# Auto-Derive Typedef-Tag Remappings from ClangSharp's AST

*Created: March 2026*
*Branch: user/jevansaks/shift-left-metadata*

---

## Problem Statement

`scraper.settings.rsp` contains ~12,700 `--remap` entries that tell ClangSharp to
rename C/C++ tag names to their typedef names in generated C# output. For example:

```
--remap
_BLUETOOTH_ADDRESS=BLUETOOTH_ADDRESS
tagDEC=DECIMAL
_RTL_BARRIER=SYNCHRONIZATION_BARRIER
__MIDL___MIDL_itf_foo_0001=RealTypeName
```

These are manually maintained. When the Windows SDK adds new types, someone must
manually add corresponding remap entries. If they don't, types appear in the winmd
with internal names like `_FOO` instead of their public typedef name `FOO`.

A previous attempt used a text-based regex scanner to parse raw SDK headers. This
fundamentally failed because it can't handle macro-expanded names (e.g.,
`VK_TO_WCHARS1` is produced by `##` token-pasting — it never appears literally in
the header source).

## Solution: ClangSharpWorker Subprocess

PInvokeGenerator discovers all typedef-tag relationships during its normal AST
traversal and stores them in a private field `_allValidNameRemappings`. A new
subprocess wrapper (`ClangSharpWorker`) runs PInvokeGenerator as a library in its
own process, extracts these remappings via reflection, and writes them to a
sidecar file — all in the same single parse pass that produces the C# output.

### Why a subprocess?

- **Single parse per partition** — PInvokeGenerator generates C# output AND
  discovers remaps in one pass. No double-parsing.
- **Process isolation** — each partition runs in its own `dotnet` process,
  eliminating shared libclang state, thread safety, and file contention concerns.
- **No public API** — `PInvokeGenerator` is `sealed` with no extensibility hooks.
  The only way to access `_allValidNameRemappings` is via reflection on a private
  field, which requires running PInvokeGenerator as a library.
- **No CLI output for discovery** — `log-potential-typedef-remappings` only logs
  validation warnings about existing `--remap` entries, not discovered remaps.

### Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│  ScrapeHeaders.ProcessPartition (per partition, parallel)       │
│                                                                 │
│  1. Build RSP files + CommandLineBuilder args                   │
│  2. dotnet "ClangSharpWorker.dll" <toolDir> <remapsFile> @rsp   │
│     └─ Own process (complete isolation)                         │
│     └─ Loads PInvokeGenerator via Assembly.LoadFrom             │
│     └─ Creates PInvokeGeneratorConfiguration (reflection)       │
│     └─ Runs GenerateBindings() (single parse)                   │
│        ├─ Generates C# output (same as stock CLI)               │
│        └─ Populates _allValidNameRemappings internally          │
│     └─ Reads _allValidNameRemappings (reflection)               │
│     └─ Writes TAG=TYPEDEF lines to .remaps sidecar file         │
│  3. Read .remaps file → merge into suggestedRemaps              │
└─────────────────────────────────────────────────────────────────┘
                              │
                              ▼
              suggestedRemaps: Dictionary<string, string>
              (merged across all 393 partitions, 16,098 entries)
                              │
                              ▼
         WriteAutoRemapsRsp() in Execute()
              → scraper.autoRemaps.generated.rsp
              (consumed on subsequent builds via @(ScraperRsp))
```

### Implementation Details

**ClangSharpWorker** (`sources/GeneratorSdk/ClangSharpWorker/Program.cs`)

A standalone console app that:
1. Receives `<toolDir> <remapsOutputPath> @rsp1 @rsp2 ...` as CLI args
2. Loads ClangSharp assemblies from `toolDir` via `Assembly.LoadFrom`
3. Pre-loads native `libclang.dll` and `libClangSharp.dll` via `NativeLibrary.Load`
4. Parses RSP files into `PInvokeGeneratorConfiguration` (same config as stock CLI)
5. Uses IL-emitted `DynamicMethod` to call `CXTranslationUnit.TryParse`
   (ReadOnlySpan params cannot be boxed for standard reflection)
6. Runs `GenerateBindings()` → writes C# output via `MemoryStream` factory
7. Reads `_allValidNameRemappings` via reflection → writes `.remaps` sidecar
8. Exits cleanly

**ScrapeHeaders** (`sources/GeneratorSdk/MetadataTasks/ScrapeHeaders.cs`)

- Spawns `dotnet ClangSharpWorker.dll` per partition (same args as stock CLI, plus
  `toolDir` and `remapsFile` prefix)
- After each successful partition, reads the `.remaps` sidecar file and merges into
  the thread-safe `suggestedRemaps` dictionary
- After all partitions, calls `WriteAutoRemapsRsp()` to write the merged remaps
- ClangSharpWorker must be present — no fallback to stock CLI

**Build integration** (`sources/GeneratorSdk/sdk/sdk.targets`)

- `ScraperAutoRemapsRsp` property points to auto-generated RSP
- Included in `@(ScraperRsp)` with `Condition="Exists(...)"` for bootstrap
- Placed BEFORE `scraper.settings.rsp` so manual overrides take priority

### Current Status (March 2026)

| Aspect | Status |
|--------|--------|
| ClangSharpWorker | ✅ Compiles and runs correctly |
| Process isolation | ✅ Each partition in own dotnet process |
| Code generation | ✅ 393/393 partitions produce correct C# output |
| Remap discovery | ✅ 16,098 unique typedef-tag remaps from full build |
| Auto-rsp writing | ✅ `scraper.autoRemaps.generated.rsp` written |
| Build integration | ✅ Auto-rsp included in `@(ScraperRsp)` |
| End-to-end build | ✅ Full build succeeds, winmd generated (23.2 MB) |
| Winmd comparison | ⚠️ Not yet compared against baseline from origin/main |
| Manual rsp cleanup | ❌ Auto-derivable entries not yet removed from `scraper.settings.rsp` |

---

## PInvokeGenerator Extensibility Research

### No public API for remap data (confirmed)

`PInvokeGenerator` is `sealed partial class : IDisposable` with no public
properties, methods, or events for accessing discovered remapping data.

Public API surface:
- `Config`, `CurrentContext`, `PreviousContext` (properties)
- `Diagnostics`, `FilePath`, `IndexHandle` (properties)
- `Close()`, `Dispose()`, `GenerateBindings(...)` (methods)

None return remapping data.

### No AST hooks or callbacks

- No `virtual` or `protected` methods to override
- No events or `Action<>`/`Func<>` fields beyond `outputStreamFactory`
- `IOutputBuilder` is internal — receives generation callbacks, not AST events
- Traversal is entirely internal: `GenerateBindings → Visit → VisitDecl`

### Useful private fields

| Field | Type | Use |
|-------|------|-----|
| `_allValidNameRemappings` | `Dict<string, HashSet<string>>` | ALL typedef-tag relationships |
| `_traversedValidNameRemappings` | `Dict<string, HashSet<string>>` | Subset from traversed files |
| `_usedRemappings` | `HashSet<string>` | Which `--remap` entries were used |
| `_visitedFiles` | `HashSet<string>` | Source files visited |
| `_diagnostics` | `List<Diagnostic>` | Generator diagnostics |

### `_usedRemappings` — future cleanup opportunity

This field tells us which manual `--remap` entries PInvokeGenerator actually
needed. Combined with `_allValidNameRemappings`, we can identify:
- **Auto-derivable**: in both `_allValidNameRemappings` and `_usedRemappings`
- **Dead entries**: in manual config but NOT in `_usedRemappings` — removable
- **Semantic overrides**: in `_usedRemappings` but NOT in
  `_allValidNameRemappings` — non-typedef remaps that must stay manual

The ClangSharpWorker could be extended to also extract `_usedRemappings` for
this analysis.

### How VisitTypedefDecl discovers remaps

The method walks the typedef's underlying type recursively:
- `FunctionProtoType` → handles function pointer typedefs
- `PointerType` / `ReferenceType` → peels pointer/ref layers
- **`TagType`** → extracts tag name and typedef name; if different, adds to
  `_allValidNameRemappings[tagName].Add(typedefName)`
- `TemplateSpecializationType` → recursively follows aliases
- Even **excluded** typedefs contribute (called with `onlyHandleRemappings: true`)

Constructor seeds defaults: `_GUID→Guid`, `intptr_t→IntPtr`, `size_t→UIntPtr`, etc.

### Upstream recommendation

The cleanest long-term fix: contribute a PR to dotnet/ClangSharp adding:
```csharp
public IReadOnlyDictionary<string, IReadOnlyCollection<string>>
    AllValidNameRemappings { get; }
```
This would eliminate the need for reflection.

---

## Next Steps

### Step 1: Validate output equivalence

Compare the winmd generated on this branch against the CLI-generated baseline
(origin/main) to confirm the ClangSharpWorker produces identical output.

### Step 2: Analyze manual vs auto-discovered remaps

The 16,098 auto-discovered remaps should subsume most of the ~12,700 entries in
`scraper.settings.rsp`. To identify which are auto-derivable:

1. Compare `scraper.autoRemaps.generated.rsp` against `scraper.settings.rsp`
2. Entries matching (same key=value) in both are auto-derivable
3. Entries only in manual file are semantic overrides or type aliases — keep these

### Step 3: Remove auto-derivable entries from scraper.settings.rsp

Once validated, remove the auto-derivable entries from `scraper.settings.rsp
--remap`. Keep only:
- Semantic renames (tag→different_public_name)
- Type alias remaps (DWORD_PTR=UIntPtr, LRESULT=IntPtr, etc.)
- Identity remaps for disambiguation

### Step 4: Extract `_usedRemappings` for dead entry detection

Extend ClangSharpWorker to also write `_usedRemappings` to a sidecar file.
This enables identifying dead `--remap` entries that are never used.

---

## Files Modified

| File | Change |
|------|--------|
| `sources/GeneratorSdk/ClangSharpWorker/Program.cs` | New: subprocess wrapper around PInvokeGenerator |
| `sources/GeneratorSdk/ClangSharpWorker/ClangSharpWorker.csproj` | New: project file |
| `sources/GeneratorSdk/MetadataTasks/ScrapeHeaders.cs` | Spawns ClangSharpWorker, reads .remaps files, writes auto-rsp |
| `sources/GeneratorSdk/sdk/sdk.targets` | Added `ScraperAutoRemapsRsp` property and `@(ScraperRsp)` inclusion |

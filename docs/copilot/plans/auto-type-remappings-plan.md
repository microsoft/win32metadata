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
| ClangSharpWorker | ✅ Subprocess wrapper, process isolated |
| Remap discovery | ✅ 16,098 typedef-tag remaps from AST |
| AutoRemaps.generated.cs | ✅ Written to GeneratedDir as C# source |
| WinmdGenerator integration | ✅ Infrastructure in place (disabled pending safe rename) |
| Heuristic filter | ✅ Filters 13,498 safe entries from 16,098 discovered |
| End-to-end build | ✅ Full build succeeds, winmd identical to baseline (0 IL diff) |
| Manual remap removal | ❌ Removing entries causes cross-namespace conflicts (VDMCONTEXT) |
| Going-forward benefit | ✅ New SDK types auto-remapped without manual entries |

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

## Verification Results

### Winmd equivalence: ✅ PASS

The ClangSharpWorker build produces an identical winmd to the origin/main baseline:
- Baseline (stock CLI): 24,328,704 bytes
- Worker build: 24,328,704 bytes
- IL comparison: 1,651,355 lines — **0 differences** (excluding image base address)

### Auto-rsp analysis

| Category | Count | Description |
|----------|------:|-------------|
| Auto-discovered | 16,098 | Total typedef-tag remaps from 393 partitions |
| Manual entries | 12,705 | Existing `--remap` entries in `scraper.settings.rsp` |
| Matching | 12,196 | Same key=value in both — safely auto-derivable |
| **Conflicts** | **32** | **Same key, different value — auto picks wrong name** |
| Only in manual | 477 | Semantic overrides not discoverable from AST |
| Only in auto | 3,869 | New discoveries (mostly ABI:: WinRT namespace remaps) |

### Conflict examples (auto-rsp picks wrong name)

| Tag | Auto discovers | Manual specifies | Why manual is correct |
|-----|---------------|-------------------|----------------------|
| `_LARGE_INTEGER` | `LARGE_INTEGER` | `long` | Semantic alias to C# primitive |
| `_ULARGE_INTEGER` | `ULARGE_INTEGER` | `ulong` | Semantic alias to C# primitive |
| `_RTL_CRITICAL_SECTION` | `RTL_CRITICAL_SECTION` | `CRITICAL_SECTION` | Public API name |
| `_RTL_SRWLOCK` | `RTL_SRWLOCK` | `SRWLOCK` | Public API name |
| `tagSTGMEDIUM` | `uSTGMEDIUM` | `STGMEDIUM` | Internal union vs public typedef |
| `_IMAGE_RUNTIME_FUNCTION_ENTRY` | `IMAGE_IA64_RUNTIME_FUNCTION_ENTRY` | `IMAGE_RUNTIME_FUNCTION_ENTRY` | Platform-specific vs generic |

### Conclusion

The auto-rsp **works correctly with manual overrides** — the current build produces
identical output because manual entries take priority over auto-discovered ones.
However, the auto-rsp **cannot fully replace** the manual file. The 32 conflicts
and 477 manual-only entries must remain as manual overrides.

The value of the auto-rsp is:
1. **Going forward**: new SDK types automatically get correct names without manual entries
2. **Cleanup**: 12,196 of 12,705 manual entries (96%) are auto-derivable and could be removed
3. **Discovery**: 3,869 new typedef-tag remaps not in the manual file

---

## Next Steps

### Step 1: Validate output equivalence

✅ **DONE.** Full IL comparison confirms identical output (1,651,355 lines).
The auto-remaps .cs pipeline produces the same winmd as baseline.

### Step 2: Remove manual --remap entries — NOT FEASIBLE

Removing `--remap` entries from `scraper.settings.rsp` changes PInvokeGenerator's
generation-time behavior beyond just naming. Some remaps affect type exclusion
and namespace scoping across partitions. Example: removing `_VDMCONTEXT=VDMCONTEXT`
causes the type to appear in multiple namespaces (SystemServices AND
VirtualDosMachines), creating Roslyn compilation ambiguity errors.

The two-phase worker correctly auto-discovers and applies these remaps in Phase 2,
but removing them from the scraper rsp means Phase 1 runs without them, producing
different partition-scoping behavior.

**Current approach:** Keep original `scraper.settings.rsp` unchanged. The two-phase
worker adds NEW auto-discoveries on top of configured remaps. Going forward, new
SDK types get correct typedef names without manual entries.

**Future improvement:** If ClangSharp adds a public API for remap discovery
(avoiding the need for the Phase 1 discovery pass), the auto-discovered remaps
could be applied in a single pass, eliminating the ~53% build time overhead.

### Step 3: Extract `_usedRemappings` for dead entry detection

Extend ClangSharpWorker to also write `_usedRemappings` to help identify
dead `--remap` entries that are never actually used.

---

## Files Modified

| File | Change |
|------|--------|
| `sources/GeneratorSdk/ClangSharpWorker/Program.cs` | New: subprocess wrapper around PInvokeGenerator |
| `sources/GeneratorSdk/ClangSharpWorker/ClangSharpWorker.csproj` | New: project file |
| `sources/GeneratorSdk/MetadataTasks/ScrapeHeaders.cs` | Spawns ClangSharpWorker, reads .remaps files, writes auto-rsp |
| `sources/GeneratorSdk/sdk/sdk.targets` | Added `ScraperAutoRemapsRsp` property and `@(ScraperRsp)` inclusion |

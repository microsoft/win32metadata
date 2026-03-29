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

## Solution: Use ClangSharp as a Library

ClangSharp already runs libclang on every SDK partition during the scraping phase.
libclang fully preprocesses macros and builds a complete AST. We now use
`ClangSharp.PInvokeGenerator` as an in-process library (instead of a CLI tool) to
access the AST data directly.

### Key Discovery

PInvokeGenerator has a private field `_allValidNameRemappings` (type:
`Dictionary<string, HashSet<string>>`) that contains **every typedef-tag
relationship** libclang discovers during parsing. By reading this field via
reflection after `GenerateBindings()` completes, we get the complete set of
auto-derivable remaps — **13,896 entries** from a full build, including
macro-expanded names.

### Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│  ScrapeHeaders.ProcessPartition (per partition, parallel)       │
│                                                                 │
│  1. Parse RSP files → PInvokeGeneratorConfiguration             │
│  2. Create PInvokeGenerator (via reflection)                    │
│  3. CXTranslationUnit.TryParse → TranslationUnit.GetOrCreate   │
│  4. generator.GenerateBindings(tu, ...)                         │
│     └─ libclang parses headers (macros expanded)                │
│     └─ Discovers typedef-tag relationships                      │
│     └─ Generates C# output (same as CLI)                        │
│  5. Read generator._allValidNameRemappings (reflection)         │
│     └─ 3000+ remaps per partition (many overlap across parts)   │
│  6. generator.Close() → MemoryStream → File.WriteAllBytes       │
│  7. generator.Dispose()                                         │
│                                                                 │
│  Falls back to CLI for x86 partitions with inline asm errors    │
└─────────────────────────────────────────────────────────────────┘
                              │
                              ▼
              suggestedRemaps: Dictionary<string, string>
              (merged across all partitions, 13,896 entries)
```

### Implementation Details

**File:** `sources/GeneratorSdk/MetadataTasks/ScrapeHeaders.cs`

**Assembly loading:** ClangSharp DLLs are loaded from the dotnet tool store
(`~/.dotnet/tools/.store/clangsharppinvokegenerator/17.0.1/.../tools/net8.0/any/`)
using `Assembly.LoadFrom`. Native libraries (`libclang.dll`, `libClangSharp.dll`)
are pre-loaded via `NativeLibrary.Load` before ClangSharp.Interop's static
constructor runs (which sets its own `DllImportResolver`).

**Reflection:** All ClangSharp types are accessed via reflection because the
assemblies are loaded dynamically — there are no compile-time references.
Key reflected types:
- `ClangSharp.PInvokeGeneratorConfiguration` — config object
- `ClangSharp.PInvokeGenerator` — the generator
- `ClangSharp.Interop.CXTranslationUnit` — libclang translation unit
- `ClangSharp.TranslationUnit` — managed wrapper

**IL emission:** `CXTranslationUnit.TryParse` takes `ReadOnlySpan<string>` and
`ReadOnlySpan<CXUnsavedFile>` parameters which cannot be called via
`MethodInfo.Invoke` (ReadOnlySpan can't be boxed). A `DynamicMethod` with IL
emission is used to build a callable delegate. See `BuildTryParseDelegate()`.

**Output handling:** A custom `Func<string, Stream>` output stream factory writes
to `MemoryStream` instances instead of files directly. After `Close()`, the
memory streams are flushed to disk. This avoids file locking issues that occur
when multiple PInvokeGenerator instances run in the same process.

**CLI fallback:** Five x86 partitions (Dfs, Dns, Hid, Js, Mf) have inline
assembly in `winnt.h` that produces clang diagnostics. PInvokeGenerator rejects
translation units with error-level diagnostics. For these partitions, the code
catches the `ArgumentException` and falls back to the CLI invocation.

**RSP parsing:** The method `ParseRspFile` reads `.rsp` files into a
`Dictionary<string, List<string>>` mapping switch names (`--remap`, `--exclude`,
`--config`, etc.) to their values. Config strings are mapped to
`PInvokeGeneratorConfigurationOptions` enum flags via `MapConfigToFieldName`.

### Current Status (March 2026)

| Aspect | Status |
|--------|--------|
| Library loading | ✅ Works — assemblies + native DLLs load correctly |
| Config parsing | ✅ All RSP settings parsed into PInvokeGeneratorConfiguration |
| Code generation | ✅ 393/393 partitions produce correct C# output |
| Remap discovery | ✅ 13,896 typedef-tag remaps auto-discovered from AST |
| CLI fallback | ✅ 5 x86 partitions fall back gracefully |
| End-to-end build | ✅ Full build succeeds, winmd generated (24.3 MB) |
| Winmd comparison | ⚠️ Not yet compared byte-for-byte against published baseline |
| Remap application | ❌ Discovered remaps not yet used to replace manual entries |

---

## Next Steps

### Step 1: Validate output equivalence

Compare the library-generated winmd against the CLI-generated baseline to confirm
byte-for-byte equivalence. Use `WinmdUtils` or a binary diff tool.

```powershell
# Generate baseline with CLI (revert to origin/main, build)
# Then generate with library (this branch, build)
# Compare the two winmd files
```

If there are differences, investigate whether they're benign (timestamps, ordering)
or indicate a generation bug.

### Step 2: Use discovered remaps to eliminate manual entries

The 13,896 discovered remaps should subsume most of the ~12,700 entries in
`scraper.settings.rsp --remap`. The plan:

1. After all partitions complete, compare `suggestedRemaps` against the existing
   `--remap` entries in `scraper.settings.rsp`
2. Entries that match (same key, same value) can be removed from the manual file
3. Entries in the manual file but NOT discovered (semantic renames like
   `_RTL_BARRIER=SYNCHRONIZATION_BARRIER`) must stay as manual overrides
4. Entries discovered but NOT in the manual file are NEW remaps — types currently
   using wrong names in the winmd

The discovered remaps should be injected into `PInvokeGeneratorConfiguration
.RemappedNames` BEFORE calling `GenerateBindings`, so ClangSharp uses the correct
names during code generation. This is more correct than applying remaps at emit
time, because:
- The Roslyn compilation needs consistent type names across partitions
- Cross-partition type references must use the same name

### Step 3: Write auto-derived remaps to generated .rsp

Write the discovered remaps (minus any manually-overridden entries) to an
auto-generated `.rsp` file:

```
$(GeneratedDir)/scraper.autoRemaps.generated.rsp
```

This file is included in the ScrapeHeaders invocation (via `@(ScraperRsp)` in
`sdk.targets`). On the first build, remaps are discovered and written. On
subsequent builds, the auto-generated file is consumed alongside the manual file.

### Step 4: Remove auto-derivable entries from scraper.settings.rsp

Once validated, remove the ~11,000 entries from `scraper.settings.rsp --remap`
that are auto-derived. Keep only:
- Semantic renames (tag→different_public_name)
- Type alias remaps (DWORD_PTR=UIntPtr, LRESULT=IntPtr, etc.)
- Identity remaps for disambiguation

### Step 5: Handle the x86 fallback partitions

The 5 x86 partitions that fall back to CLI don't get their remaps discovered.
Options:
- Accept this (they still work via CLI with manual remaps)
- Investigate why the inline assembly diagnostic causes PInvokeGenerator to reject
  the translation unit (the CLI is more tolerant)
- Filter out error-level diagnostics before calling GenerateBindings

---

## Technical Notes

### ClangSharp v17.0.1 API (via reflection)

```csharp
// Constructor
PInvokeGenerator(PInvokeGeneratorConfiguration config, Func<string, Stream>? outputStreamFactory = null)

// Main method
void GenerateBindings(TranslationUnit translationUnit, string filePath,
    string[] clangCommandLineArgs, CXTranslationUnit_Flags translationFlags)

// Lifecycle
void Close()    // Writes output
void Dispose()  // Cleans up CXIndex

// Key properties
CXIndex IndexHandle { get; }
IReadOnlyList<Diagnostic> Diagnostics { get; }

// Private fields (accessible via reflection)
Dictionary<string, HashSet<string>> _allValidNameRemappings    // ALL discovered
Dictionary<string, HashSet<string>> _traversedValidNameRemappings  // Traversed files only
HashSet<string> _usedRemappings  // Which --remap entries were actually used
```

### PInvokeGeneratorConfiguration properties

```csharp
// Set via init-only property setters
IReadOnlyCollection<string> TraversalNames { get; set; }
IReadOnlyCollection<string> ExcludedNames { get; set; }
IReadOnlyDictionary<string, string> RemappedNames { get; set; }
IReadOnlyDictionary<string, IReadOnlyList<string>> WithAttributes { get; set; }
IReadOnlyDictionary<string, string> WithTypes { get; set; }
IReadOnlyDictionary<string, string> WithLibraryPaths { get; set; }
IReadOnlyDictionary<string, string> WithCallConvs { get; set; }
IReadOnlyDictionary<string, IReadOnlyList<string>> WithUsings { get; set; }
string DefaultClass { get; set; }
```

### Files modified

| File | Change |
|------|--------|
| `sources/GeneratorSdk/MetadataTasks/ScrapeHeaders.cs` | +458 lines: library invocation, RSP parsing, IL emission, reflection helpers |

### Files NOT modified

No changes to `sdk.targets`, `EmitWinmd.cs`, `Program.cs`,
`ClangSharpSourceWinmdGenerator.cs`, or `scraper.settings.rsp`. The library
integration is fully contained in `ScrapeHeaders.cs`.

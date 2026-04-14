# Auto-Derive Typedef-Tag Remappings from ClangSharp's AST

*Created: March 2026*
*Updated: April 2026*
*Branch: user/jevansa/win32metadata-scraper*

---

## Problem Statement

`scraper.settings.rsp` contained ~12,700 `--remap` entries that tell ClangSharp to
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

Similarly, `functionPointerFixups.json` contained ~575 manual entries mapping
function pointer prototypes to their pointer typedef aliases (e.g.,
`TIMECALLBACK` → `LPTIMECALLBACK`).

A previous attempt used a text-based regex scanner to parse raw SDK headers. This
fundamentally failed because it can't handle macro-expanded names (e.g.,
`VK_TO_WCHARS1` is produced by `##` token-pasting — it never appears literally in
the header source).

## Solution: Win32MetadataScraper (Single-Pass AST Discovery)

A new standalone tool (`Win32MetadataScraper`) replaces the stock
`ClangSharpPInvokeGenerator` CLI. It hosts PInvokeGenerator as a library (via NuGet
package references), parses the translation unit, walks the ClangSharp AST to
discover typedef-tag and function pointer remappings, merges them with the
configured `--remap` entries, then runs `PInvokeGenerator.GenerateBindings` with
the full merged remap set — all in a single parse pass.

### Why a custom scraper tool?

- **Single parse per partition** — parses once, walks AST for discovery AND
  generates C# output in the same pass.
- **Process isolation** — each partition runs in its own `dotnet` process,
  eliminating shared libclang state, thread safety, and file contention concerns.
- **No public API** — `PInvokeGenerator` is `sealed` with no extensibility hooks.
  Walking the AST via ClangSharp's public types is the only supported approach.
- **No reflection** — unlike the earlier `ClangSharpWorker` prototype, this tool
  uses ClangSharp's public AST types (`TypedefDecl`, `TagType`, `PointerType`,
  etc.) directly, not reflection on PInvokeGenerator internals.

### Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│  ScrapeHeaders.ProcessPartition (per partition, parallel)       │
│                                                                 │
│  1. Build RSP files + CommandLineBuilder args                   │
│  2. dotnet "Win32MetadataScraper.dll" <remapsFile> @rsp1 @rsp2  │
│     └─ Own process (complete isolation)                         │
│     └─ Parses TU via CXTranslationUnit.TryParse                │
│     └─ RemapDiscovery.WalkTranslationUnit(AST)                  │
│        ├─ Discovers tag→typedef pairs                           │
│        ├─ Discovers fn ptr prototype→alias pairs                │
│        └─ Resolves & filters using heuristics                   │
│     └─ Merges auto-remaps + fn ptr fixups + configured remaps   │
│     └─ Runs PInvokeGenerator.GenerateBindings(same TU)          │
│     └─ Writes .remaps sidecar file                              │
│  3. ScrapeHeaders reads .remaps → merges into discovered sets   │
└─────────────────────────────────────────────────────────────────┘
                              │
                              ▼
              WriteAutoRemapsRsp() in Execute()
              → scraper.autoRemaps.generated.rsp (tag remaps)
              → emitter.autoFnPtr.generated.rsp (reducePointerLevel)
              (consumed on subsequent builds via @(ScraperRsp) / @(EmitterRsp))
```

### Key Components

**Win32MetadataScraper** (`sources/Win32MetadataScraper/Program.cs`)

A standalone console app that:
1. Receives `<remapsOutputPath> @rsp1 @rsp2 ...` as CLI args
2. Parses RSP files to extract all PInvokeGenerator settings
3. Parses the translation unit via `CXTranslationUnit.TryParse`
4. Calls `RemapDiscovery.WalkTranslationUnit` to discover typedef-tag and fn ptr relationships
5. Resolves and filters discoveries using heuristics
6. Merges auto-discovered remaps with configured ones (configured wins)
7. Creates `PInvokeGeneratorConfiguration` with merged remaps
8. Runs `GenerateBindings()` → writes C# output via `MemoryStream` factory
9. Writes auto-discovered entries to `.remaps` sidecar file

**RemapDiscovery** (`sources/Win32MetadataScraper/RemapDiscovery.cs`)

Static class with AST walking and heuristic resolution:
- `WalkTranslationUnit()` — walks all `TypedefDecl` nodes to find tag→typedef and
  function pointer prototype→alias relationships
- `ResolveTagRemaps()` — disambiguates tags with multiple typedefs using heuristics
  (strip `_` prefix, strip `tag` prefix, case-insensitive match)
- `FilterTagRemaps()` — removes built-in defaults, identity remaps, conflict with
  configured remaps, and suffix-adding remaps
- `ResolveFunctionPointerFixups()` — classifies fn ptr pairs by pointer prefix
  (`LP`, `PFN`, `P`) to determine remap direction, excludes, and reducePointerLevel

**ScrapeHeaders** (`sources/GeneratorSdk/MetadataTasks/ScrapeHeaders.cs`)

- Locates `Win32MetadataScraper.dll` from `ToolsBinDir` (built with RuntimeIdentifier)
- Spawns `dotnet Win32MetadataScraper.dll` per partition
- Reads `.remaps` sidecar files and merges into thread-safe dictionaries
- After all partitions, calls `WriteAutoRemapsRsp()` to write merged RSP files
- Runs `CheckCrossPartitionRemapConsistency()` to detect types declared with raw
  tag names (warnings only)

**Build integration** (`sources/GeneratorSdk/sdk/sdk.targets`)

- `ScraperAutoRemapsRsp` property points to auto-generated tag remap RSP
- `EmitterAutoFnPtrRsp` property points to auto-generated reducePointerLevel RSP
- Both included with `Condition="Exists(...)"` for bootstrap
- Auto-remaps placed BEFORE manual RSPs so manual overrides take priority

### Current Status (April 2026)

| Aspect | Status |
|--------|--------|
| Win32MetadataScraper | ✅ Single-pass scraper is in place and is the right long-term architecture |
| Tag remap discovery | ✅ Auto-discovers typedef→tag remaps and feeds them back into generation before emit |
| Fn ptr discovery model | ✅ Discovery now distinguishes bare-function typedefs from already-pointer typedef aliases |
| Manual remap removal | ✅ **~12,197 entries removed** from `scraper.settings.rsp` |
| Manual fn ptr removal | ⚠️ Large reduction landed, but the branch still carries temporary manual fixups for delegate correctness while discovery is tightened |
| Main-branch baseline | ✅ A detached `origin/main` worktree passes all 13 `Windows.Win32.Tests` |
| D2D emit regression | ✅ Fixed by changing `ID2D1SimplifiedGeometrySink=ID2D1SimplifiedGeometrySink` |
| Empty delegates | ✅ No longer failing in the current branch validation run |
| Duplicate fn ptr fixups | ✅ Auto-discovery now defers to configured/manual excludes, and sidecar ingestion dedupes against the manual fixup RSPs |
| End-to-end validation | ⚠️ `DoAll.ps1 -ExcludePackages -ExcludeSamples` now builds the winmd and passes all tests except `NoCyclicalNamespaces` |
| Remaining blocker | ⚠️ One 3-node namespace cycle remains: `System.Power → System.SystemServices → System.Threading → System.Power` |

### Validation Snapshot

Latest validation was run against a fresh generated tree (`generation\WinSDK\obj`
deleted, `bin\Windows.Win32.winmd` deleted first):

- `dotnet build BuildTools -c Release` — passed
- `dotnet test tests\Win32MetadataScraperTests -c Release --no-restore` — **34/34 passed**
- `.\DoAll.ps1 -ExcludePackages -ExcludeSamples` — built tools, scraped headers,
  emitted `Windows.Win32.winmd`, passed `MetadataUtils.Tests` and scraper tests,
  passed **12/13** `Windows.Win32.Tests`, failed only `NoCyclicalNamespaces`

Latest `showNamespaceCycles` output:

```text
Windows.Win32.System.Power
  Cyclical dependent namespaces: Windows.Win32.System.SystemServices
Windows.Win32.System.SystemServices
  Cyclical dependent namespaces: Windows.Win32.System.Threading
Windows.Win32.System.Threading
  Cyclical dependent namespaces: Windows.Win32.System.Power
```

---

## What Was Done

### 1. Established the correct validation path

Early validation on this branch only built the tools and ran unit tests. That was
not enough. Real validation for this work must exercise the full scrape + emit +
winmd test pipeline:

```powershell
.\DoAll.ps1 -ExcludePackages -ExcludeSamples
```

That is the command that exposed the real regressions.

### 2. Fixed the first real end-to-end regression

The initial full build failed during emit because `scraper.settings.rsp` still had:

```text
ID2D1SimplifiedGeometrySink=IDWriteGeometrySink
```

That remap caused `ID2D1GeometrySink` to inherit from the wrong interface identity
at emit time. Changing it to:

```text
ID2D1SimplifiedGeometrySink=ID2D1SimplifiedGeometrySink
```

unblocked emit and allowed the run to reach the integration tests.

### 3. Proved the branch regressions against a clean main baseline

A detached worktree at `C:\repos\win32metadata.2.main` was used to build
`origin/main` with the same real pipeline. Main passes all 13
`Windows.Win32.Tests`, so both of the branch failures below are genuine branch
regressions:

- `NoInvalidEmptyDelegates`
- `NoCyclicalNamespaces`

### 4. Tightened fn-ptr discovery semantics

The scraper no longer treats all function-pointer typedef shapes as equivalent.
Discovery now records:

- bare-function typedefs (`typedef void CALLBACK(...);`)
- already-pointer typedefs (`typedef DWORD (*PFOO)(...);`)

That distinction is important because only the first shape should automatically
generate `--remap` / `--exclude` / `--reducePointerLevel` fixups by default.

Unit tests were expanded to cover:

- non-standard pointer alias names
- already-pointer alias chains
- versioned/unversioned aliases
- configured excludes suppressing auto-generated fixups

### 5. Restored delegate correctness conservatively

The empty-delegate failure was not fully solvable by the structural split alone.
Some legacy cases are still carried by curated fixups. To keep the branch correct
while continuing to shrink the manual file, the following entries were restored to
`functionPointerFixups.json` as a temporary measure:

- `PTHREAD_START_ROUTINE -> LPTHREAD_START_ROUTINE` (`alreadyPointer: true`)
- `INTERNET_STATUS_CALLBACK -> LPINTERNET_STATUS_CALLBACK` (`alreadyPointer: true`)
- `INSTALLUI_HANDLER_RECORD -> PINSTALLUI_HANDLER_RECORD`
- `PBMCALLBACKFN -> LPBMCALLBACKFN`
- `ACMDRIVERPROC -> LPACMDRIVERPROC`
- `PTOP_LEVEL_EXCEPTION_FILTER -> LPTOP_LEVEL_EXCEPTION_FILTER`
- `LPFNADDPROPSHEETPAGE -> LPFNSVADDPROPSHEETPAGE`
- `PFIBER_START_ROUTINE -> LPFIBER_START_ROUTINE`

This is a correctness-preserving fallback, not the desired end state.

### 6. Traced and suppressed the obvious duplicate `reducePointerLevel` sources

The namespace-cycle investigation found 9 suspect `reducePointerLevel` entries that
were present on this branch but not on main:

- `LPMAPIALLOCATEBUFFER`
- `LPMAPIALLOCATEMORE`
- `LPMAPIFREEBUFFER`
- `PENCLAVE_TARGET_FUNCTION`
- `PEXCEPTION_ROUTINE`
- `PLSA_GET_EXTENDED_CALL_FLAGS`
- `WHEA_ERROR_SOURCE_CORRECT_DEVICE_DRIVER`
- `WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER`
- `WHEA_ERROR_SOURCE_UNINITIALIZE_DEVICE_DRIVER`

Those resolved to three buckets:

1. Already manually excluded in partition or global scraper settings
2. Already present in the manual function-pointer fixup RSPs
3. Newly auto-discovered entries that should defer to existing manual configuration

The current code now does two conservative things:

1. `Win32MetadataScraper` passes the configured `--exclude` set into
   `ResolveFunctionPointerFixups` and skips auto-generating a fn-ptr fixup when the
   alias is already manually excluded.
2. `ScrapeHeaders` parses the manual function-pointer fixup RSPs and drops matching
   auto-generated remap / exclude / reducePointerLevel entries while reading the
   scraper sidecar files.

After that change:

- the 9 suspect names above no longer appear in `emitter.autoFnPtr.generated.rsp`
- overlap between auto and manual `--reducePointerLevel` files is now **0**
- the branch still has the same 3-node namespace cycle, so those duplicates were
  real noise, but not the last root cause

### 7. Current interpretation

The branch is now in a cleaner debugging state:

- empty delegates are fixed
- duplicate/manual fn-ptr fixups are suppressed correctly
- the remaining failure is isolated to the namespace-cycle regression

That is a much better place for the next round of investigation than the earlier
state where delegate failures and duplicate fixups were interleaved.

---

## Remaining Work

### High Priority

- [ ] **Find the remaining cause of the `Power/SystemServices/Threading` cycle** —
  the obvious duplicate fn-ptr fixups are no longer in the auto-generated RSPs, but
  the emitted winmd still forms the same 3-namespace cycle.

- [ ] **Compare namespace dependency edges against `origin/main` again now that the
  duplicate fn-ptr entries are gone** — focus on the three namespaces still in the
  cycle instead of the broader earlier graph.

- [ ] **Decide which of the temporary 8 manual function-pointer fixups can be
  eliminated next** — they are currently justified by correctness, but the branch
  goal is still to keep shrinking `functionPointerFixups.json`, not grow it.

### Medium Priority

- [ ] **Audit the remaining cross-partition consistency warnings** — the latest full
  build still warned about raw-tag declarations such as `in_addr`, `sockaddr`,
  `timeval`, `_CERT_CONTEXT`, and `_SecPkgContext_IssuerListInfoEx`. These may be
  orthogonal, but they should be reviewed once the namespace cycle is fixed.

- [ ] **Continue whittling down `scraper.settings.rsp`** — after the namespace cycle
  is understood, resume removing still-auto-derivable tag remaps from the manual
  RSP.

- [ ] **Revisit already-pointer alias handling** — the current model is deliberately
  conservative. A future refinement may allow more of those cases to move out of
  `functionPointerFixups.json` without reintroducing empty delegates.

### Low Priority / Future

- [ ] **Extract `_usedRemappings` for dead-entry detection** — this would make the
  remaining manual remap audit much cheaper.

- [ ] **Upstream recommendation** — if ClangSharp ever exposes remap-discovery data
  directly, the repo could stop maintaining its parallel AST walk.

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

### How VisitTypedefDecl discovers remaps

The method walks the typedef's underlying type recursively:
- `FunctionProtoType` → handles function pointer typedefs
- `PointerType` / `ReferenceType` → peels pointer/ref layers
- **`TagType`** → extracts tag name and typedef name; if different, adds to
  `_allValidNameRemappings[tagName].Add(typedefName)`
- `TemplateSpecializationType` → recursively follows aliases
- Even **excluded** typedefs contribute (called with `onlyHandleRemappings: true`)

Constructor seeds defaults: `_GUID→Guid`, `intptr_t→IntPtr`, `size_t→UIntPtr`, etc.

---

## Files Modified

| File | Change |
|------|--------|
| `sources/Win32MetadataScraper/Program.cs` | New: single-pass scraper hosting PInvokeGenerator |
| `sources/Win32MetadataScraper/RemapDiscovery.cs` | New: AST walker and heuristic resolution |
| `sources/Win32MetadataScraper/Win32MetadataScraper.csproj` | New: project file with ClangSharp v17.0.1 refs |
| `sources/GeneratorSdk/MetadataTasks/ScrapeHeaders.cs` | Modified: uses Win32MetadataScraper, reads .remaps, writes auto RSPs |
| `sources/GeneratorSdk/MetadataTasks/TaskUtils.cs` | Minor cleanup |
| `sources/GeneratorSdk/sdk/sdk.targets` | Added auto-remap and auto-fn-ptr RSP properties |
| `generation/WinSDK/scraper.settings.rsp` | Removed ~12,197 auto-derivable remap entries |
| `generation/WinSDK/functionPointerFixups.json` | Removed ~160 auto-derivable fn ptr fixup entries |
| `generation/WinSDK/Partitions/*/main.cpp` | 7 files: added #include for cross-partition visibility |
| `tests/Win32MetadataScraperTests/` | New: unit tests for discovery heuristics |
| `BuildTools/BuildTools.proj` | Added Win32MetadataScraper project reference |
| `scripts/DoTests.ps1` | Added scraper discovery tests to test suite |

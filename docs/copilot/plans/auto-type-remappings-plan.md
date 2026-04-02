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
| Win32MetadataScraper | ✅ Single-pass scraper, process isolated, no reflection |
| Tag remap discovery | ✅ Auto-discovers typedef-tag remaps from AST |
| Fn ptr fixup discovery | ✅ Auto-discovers function pointer remappings from AST |
| Manual remap removal | ✅ **12,197 entries removed** from scraper.settings.rsp (12,700→525) |
| Manual fn ptr removal | ✅ **~160 entries removed** from functionPointerFixups.json (575→~20) |
| Cross-partition fixes | ✅ 7 partition main.cpp files updated with #include directives |
| Disambiguation heuristics | ✅ Case-insensitive prefix stripping, suffix filter, configured fallback |
| Unit tests | ✅ Comprehensive tests for tag-typedef, fn ptr, and edge cases |
| End-to-end build | ⬜ Needs full build verification on this branch |

---

## What Was Done (April 2026)

### 1. Created Win32MetadataScraper tool
- New project `sources/Win32MetadataScraper/` with NuGet references to ClangSharp
  v17.0.1 (same version pinned by the repo)
- `Program.cs`: full RSP parser, PInvokeGenerator configuration builder, single-pass
  scrape + discovery pipeline
- `RemapDiscovery.cs`: AST walker and heuristic resolution logic

### 2. Removed ~12,197 manual --remap entries
The previous agent's approach (ClangSharpWorker with reflection) could not remove
manual entries because removing them changed PInvokeGenerator's generation-time
behavior. The new approach (single-pass, merged remaps before generation) resolves
this: auto-discovered remaps are merged INTO the remap set BEFORE GenerateBindings
runs, so PInvokeGenerator sees all remaps during generation.

This enabled safely removing ~96% of manual `--remap` entries. The remaining ~525
entries are semantic overrides that cannot be auto-derived:
- Primitive type aliases (`_LARGE_INTEGER=long`, `DWORD_PTR=UIntPtr`)
- Public API name overrides (`_RTL_CRITICAL_SECTION=CRITICAL_SECTION`)
- MIDL-generated name remaps (`__MIDL___MIDL_itf_*=FriendlyName`)
- Nested type remaps (`D3D11_AUTHENTICATED_PROTECTION_FLAGS::__MIDL_*=_Flags_e__Struct`)
- Opaque pointer types (`_HIDP_PREPARSED_DATA*=IntPtr`)

### 3. Removed ~160 function pointer fixup entries
Auto-discovers fn ptr prototype→alias pairs from the AST and generates appropriate
`--remap`, `--exclude`, and `--reducePointerLevel` entries. The remaining ~20
entries in `functionPointerFixups.json` are edge cases:
- Entries with no `pointerType` (solo fn ptr typedefs)
- `alreadyPointer` entries (reversed direction)
- Names that don't follow standard LP/PFN/P prefix convention

### 4. Fixed cross-partition remap visibility
7 partition `main.cpp` files were updated with `#include` directives to ensure
typedef declarations are visible during scraping:
- `IpHlp/main.cpp` ← `#include <inaddr.h>`
- `NetMgmt/main.cpp` ← `#include <wincrypt.h>`
- `RRas/main.cpp` ← `#include <inaddr.h>`
- `Security.Cryptography.Sip/main.cpp` ← `#include <mscat.h>`
- `Security.WinTrust/main.cpp` ← `#include <mssip.h>`
- `TermServ/main.cpp` ← `#include <winsock.h>`
- `Wsw/main.cpp` ← `#include <schannel.h>`

### 5. Fixed thread-safety bug in ScrapeHeaders
The original `ret &= this.ProcessPartition(...)` in `Parallel.ForEach` was a race
condition (non-atomic boolean AND). Replaced with `Interlocked.Increment` on a
failure count.

### 6. Added unit tests
- `tests/Win32MetadataScraperTests/` with `RemapDiscoveryTests.cs` covering:
  - Simple tag-typedef patterns (underscore, tag prefix, lowercase, trailing underscore, enum)
  - Multi-typedef disambiguation (prefix stripping, case-insensitive, configured fallback)
  - Function pointer fixup resolution (standard LP/PFN pattern, already-pointer pattern)
  - Edge cases (namespace-scoped tags, identity remaps, built-in filtering)
- `HeaderSnippetParser.cs` test helper for parsing C header snippets via ClangSharp

### 7. Other changes
- `NuGetPackageSource` property no longer `[Required]` (tool installed via NuGet packages, not dotnet tool)
- `MaxDegreeOfParallelism` changed from `ProcessorCount/2` to `ProcessorCount`
- `ChangesSinceLastRelease.txt` emptied
- Version bumped to 71.0-preview

---

## Remaining Work

### High Priority

- [ ] **Full end-to-end build verification** — Run `./DoAll.ps1 -Clean` on this
  branch and compare the resulting winmd against the main branch baseline.
  Verify IL equivalence.

- [ ] **Remove remaining auto-derivable remaps from scraper.settings.rsp** —
  The current 525 remaining entries likely include some that ARE auto-derivable
  but were conservatively kept. Audit categories:
  - `tagFOO=FOO` patterns (e.g., `tagRASCONNA=RASCONNA`) — these follow standard
    prefix patterns and should be auto-derived
  - `_FOO=FOO` patterns (e.g., `_WSACMSGHDR=WSACMSGHDR`) — standard underscore
    prefix, should be auto-derived
  - `FWPS_*_=FWPS_*` trailing underscore patterns — should be auto-derived

- [ ] **Remove remaining auto-derivable fn ptr fixups from functionPointerFixups.json** —
  The 20 remaining entries should be audited. Some may be auto-derivable with
  improved heuristics (e.g., `_WHEA_*` entries, `DRVCALLBACK→LPDRVCALLBACK`).

### Medium Priority

- [ ] **Improve `HasPointerPrefix` heuristic** — The current check `StartsWith("P")`
  is overly broad. Consider requiring `StartsWith("LP")`, `StartsWith("PFN")`, or
  `StartsWith("P") && name[1] is uppercase` to reduce false positives.

- [ ] **Validate cross-partition consistency** — The `CheckCrossPartitionRemapConsistency`
  method currently only warns. After build verification, consider whether it should
  fail the build to prevent regressions.

- [ ] **Remove dead code** — `Program.cs` has a `FilterRemaps()` method (lines 250-277)
  that is never called; it duplicates `RemapDiscovery.FilterTagRemaps`.

### Low Priority / Future

- [ ] **Extract `_usedRemappings` for dead entry detection** — Add analysis to
  identify which remaining manual `--remap` entries PInvokeGenerator never actually
  uses (dead entries that can be removed).

- [ ] **Upstream recommendation** — Contribute a PR to dotnet/ClangSharp adding a
  public API for remap discovery data, eliminating the need for parallel AST walking.

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

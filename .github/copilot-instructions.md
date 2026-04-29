# Copilot Instructions for win32metadata

## Build Commands

```powershell
# Full build (25-30 min): build tools, scrape headers, emit winmd, package, test
./DoAll.ps1 -Clean

# Incremental build (faster, skips packages/samples)
./DoAll.ps1 -ExcludePackages -ExcludeSamples

# Build just the build tools (MetadataTasks, ConstantsScraper, ClangSharpSourceToWinmd, etc.)
dotnet build BuildTools -c Release

# Build the winmd only (requires tools built first)
dotnet build generation/WinSDK -c Release -t:EmitWinmd

# Scrape a single partition (useful for debugging)
dotnet build generation/WinSDK -c Release -p:ScanArch=crossarch -t:ScrapeHeaders -p:PartitionFilter=Foundation
```

## Test Commands

```powershell
# Run all tests
./scripts/DoTests.ps1

# Individual test suites
dotnet test tests/MetadataUtils.Tests -c Release
dotnet test tests/Windows.Win32.Tests -c Release          # winmd integrity tests
dotnet test tests/Win32MetadataScraperTests -c Release     # scraper heuristic tests
dotnet test tests/ClangSharpSourceToWinmdTests -c Release

# Single test
dotnet test tests/Win32MetadataScraperTests -c Release --filter "TransitiveInclude"
```

## Architecture

The toolchain converts Windows SDK C/C++ headers into a .NET metadata assembly (`Windows.Win32.winmd`).

**Pipeline stages** (in order, defined in `sources/GeneratorSdk/sdk/sdk.targets`):
1. **ScrapeHeaders** — `Win32MetadataScraper` hosts ClangSharp PInvokeGenerator as a library, walks the AST to auto-discover typedef-tag remappings, then generates C# bindings per partition
2. **ScrapeConstants** — `ConstantsScraper` extracts `#define` constants via regex matching on headers
3. **EmitWinmd** — `ClangSharpSourceToWinmd` compiles the generated C# into the final winmd

**Key projects:**
- `Win32MetadataScraper` — Single-pass scraper: parses the translation unit, discovers remaps from the AST, merges with manual config, calls PInvokeGenerator.GenerateBindings on the same TU
- `ClangSharpSourceToWinmd` — Reads generated C# sources, applies `MetadataSyntaxTreeCleaner` transformations (memberRemap, enum additions), emits the winmd via System.Reflection.Metadata
- `MetadataTasks` — MSBuild tasks (`ScrapeHeaders`, `EmitWinmd`, etc.) that orchestrate the pipeline
- `WinmdUtils` — CLI for winmd inspection (duplicate detection, suggested remappings, etc.)

**Partition system:** Each Win32 API area (Foundation, Kernel, DirectX, etc.) is a "partition" in `generation/WinSDK/Partitions/`. Each has a `main.cpp` (header includes) and optional `settings.rsp` (per-partition config). Partitions are scraped in parallel.

**Response files (.rsp):** Configuration is heavily RSP-based. Key files in `generation/WinSDK/`:
- `scraper.settings.rsp` — Type remaps (`--remap`), exclusions (`--exclude`), type overrides (`--with-type`)
- `emitter.settings.rsp` — Member remaps (`--memberRemap`), enum additions
- `autoTypes.json` — Handle/typedef definitions (RAII close functions, invalid values)

**Function pointer fixups** are auto-discovered by the scraper's `RemapDiscovery` module (no manual JSON needed).

**CI pipeline** (`azure-pipelines.yml` / `.github/workflows/pr-validation.yml`):
Three parallel scrape jobs (x64, x86, arm64) → artifacts merged → one build/test/package job.
Each arch job scrapes ALL partitions for that architecture.

## Key Conventions

**NuGet feed:** The repo uses a private ADO Artifact Feed (`Win32Metadata-Dependencies`) as its sole package source. New packages from nuget.org must be saved to this feed first.

**Winmd equivalence:** After any change, the winmd must be compared against the baseline. The `NoSuggestedRemappings` test in `Windows.Win32.Tests` validates that no new unhandled remappings were introduced. Changes to the winmd are tracked in `scripts/ChangesSinceLastRelease.txt`.

**Cross-partition remaps:** Remaps in `scraper.settings.rsp` are global — they apply to all partitions. Auto-discovered remaps (from `Win32MetadataScraper`) are per-partition. If a tag name is used across partitions but the typedef is only in one partition's headers, the remap must be global (in `scraper.settings.rsp`) OR the referencing partition must `#include` the header with the typedef.

**C++ namespace types:** Types inside C++ namespaces (`Gdiplus::Status`, `ABI::Windows::*`) are handled by PInvokeGenerator internally. The auto-remap discovery skips namespace-qualified tags.

**ClangSharp version pinning:** The repo pins ClangSharp v17.0.1. `Win32MetadataScraper` references ClangSharp NuGet packages directly; native libs (`libclang.dll`, `libClangSharp.dll`) are resolved at runtime via NuGet's `runtime.json` mechanism.

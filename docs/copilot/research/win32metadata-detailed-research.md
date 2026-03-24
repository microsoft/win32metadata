---
date: 2025-07-17
branch: main
commit: 674b9f0b773d
repository: microsoft/win32metadata
topic: "Repository purpose, architecture, build system, and key components"
status: complete
---

# Research: win32metadata Repository

**Date**: 2025-07-17
**Branch**: main
**Repository**: microsoft/win32metadata (C:\repos\win32metadata)

## Research Question

Understand the win32metadata repository's purpose, architecture, build system, and key components. Focus on what it produces, how it builds, and how its folders relate to each other.

## Summary

**win32metadata** is a Microsoft open-source project that generates **machine-readable metadata** for the entire Win32 API surface. It produces a `Windows.Win32.winmd` file (ECMA-335 binary format) and ships it as the [`Microsoft.Windows.SDK.Win32Metadata`](https://www.nuget.org/packages/Microsoft.Windows.SDK.Win32Metadata/) NuGet package. Language projections (C#, Rust, Python, Zig, etc.) consume this metadata to auto-generate idiomatic Win32 API bindings, replacing fragile manual P/Invoke definitions.

The repo contains:
- A **two-stage pipeline** (Scraper → Emitter) that converts Windows SDK C/C++ headers into a .winmd file
- **~240 "partitions"** that organize Win32 headers into namespaces
- **Extensive configuration** via .rsp files, JSON, and manual C# overrides
- A **companion API docs** package (`Microsoft.Windows.SDK.Win32Docs`) scraped from Microsoft documentation repositories
- The **WinmdGenerator SDK** — an MSBuild SDK that lets third parties generate their own .winmd files from C/C++ headers

---

## Detailed Findings

### 1. What This Repo Produces

| Output | NuGet Package | Description |
|--------|---------------|-------------|
| `Windows.Win32.winmd` | `Microsoft.Windows.SDK.Win32Metadata` | ECMA-335 metadata binary describing the entire Win32 API surface |
| WinmdGenerator SDK | `Microsoft.Windows.WinmdGenerator` | MSBuild project SDK for generating .winmd files from arbitrary C/C++ projects |
| API Documentation | `Microsoft.Windows.SDK.Win32Docs` | MessagePack binary (`apidocs.msgpack`) containing Win32 API documentation |

**Current version**: `70.0-preview` (managed by Nerdbank.GitVersioning via `version.json`)

**Language projections** that consume this metadata:
- **Microsoft**: [CsWin32](https://github.com/microsoft/cswin32) (C#), [windows-rs](https://github.com/microsoft/windows-rs) (Rust)
- **Community**: Dart, Python, Zig, D, Beef, .NET Standard

### 2. High-Level Architecture

The architecture has three layers documented in `docs/architecture.md`:

```
┌─────────────────────────────────────────────────────────────────┐
│                        SCRAPER LAYER                            │
│                                                                 │
│  ┌──────────────┐    ┌──────────────────┐                       │
│  │  ClangSharp   │    │ ConstantsScraper  │                      │
│  │  (C headers   │    │ (regex-based      │                      │
│  │   → C# files) │    │  constant extract) │                     │
│  └──────┬───────┘    └────────┬─────────┘                       │
│         │                     │                                  │
│    Per-arch C# files     Constants C# files                     │
│    (x64, x86, arm64)    (x86 only)                              │
└─────────┬─────────────────────┬─────────────────────────────────┘
          │                     │
          ▼                     ▼
┌─────────────────────────────────────────────────────────────────┐
│                        EMITTER LAYER                            │
│                                                                 │
│  ┌─────────────────────────────┐                                │
│  │ ClangSharpSourceCompilation  │ Orchestrates:                  │
│  │  ├─ CrossArchTreeMerger     │  - Merge arch-specific C#      │
│  │  ├─ NamesToCorrectNS Mover  │  - Fix namespaces              │
│  │  ├─ MetadataSyntaxTreeCleaner│ - Apply remaps/attributes     │
│  │  └─ ClangSharpSourceWinmd   │  - Write .winmd binary         │
│  │      Generator              │                                │
│  └─────────────┬───────────────┘                                │
│                │                                                │
│          Windows.Win32.winmd                                    │
└────────────────┬────────────────────────────────────────────────┘
                 │
                 ▼
┌─────────────────────────────────────────────────────────────────┐
│                    PACKAGING LAYER                               │
│                                                                 │
│  NuGet packages:                                                │
│  ├─ Microsoft.Windows.SDK.Win32Metadata (winmd + headers)       │
│  ├─ Microsoft.Windows.WinmdGenerator (SDK for third parties)    │
│  └─ Microsoft.Windows.SDK.Win32Docs (API docs msgpack)          │
└─────────────────────────────────────────────────────────────────┘
```

### 3. Repository Structure

```
win32metadata/
├── generation/WinSDK/           # Core: metadata generation configuration
│   ├── Windows.Win32.proj       # Main MSBuild project file
│   ├── Partitions/ (~240 dirs)  # Header→namespace mapping definitions
│   ├── manual/ (44 .cs files)   # Hand-written C# for special cases
│   ├── AdditionalHeaders/       # Custom headers not in standard SDK
│   ├── RecompiledIdlHeaders/    # Pre-compiled IDL headers (SDK copy)
│   ├── inc/                     # Internal support headers (SAL, intrinfix)
│   ├── *.rsp files              # Configuration response files
│   ├── enums.json               # Enum definitions with auto-populate rules
│   ├── autoTypes.json           # Auto-generated type definitions
│   └── functionPointerFixups.json # Function pointer type corrections
│
├── sources/                     # C# source projects (tools & libraries)
│   ├── MetadataUtils/           # Shared library (foundation for all tools)
│   ├── ClangSharpSourceToWinmd/ # Scraper→emitter: C# → .winmd converter
│   ├── ConstantsScraper/        # Constant extraction from headers
│   ├── WinmdUtils/              # .winmd inspection/comparison CLI tool
│   ├── PartitionUtils/          # Partition management CLI tool
│   ├── GeneratorSdk/            # MSBuild SDK + tasks for WinmdGenerator
│   └── nuget/                   # NuGet package definition
│
├── scripts/ (39 .ps1 files)     # PowerShell build & utility scripts
├── tests/                       # xUnit/MSTest test projects
├── apidocs/                     # API documentation scraper & NuGet package
├── ext/                         # Git submodules (6 doc repos)
├── configurations/              # DSC dev environment setup
├── buildTransitive/             # NuGet consumer MSBuild props
├── AzurePipelinesTemplates/     # CI/CD pipeline templates
├── licenses/                    # SDK license files
└── docs/                        # Project documentation
```

### 4. Build System

#### 4.1 SDK & Tooling Requirements

**`global.json`**:
- .NET SDK 8.0.417 (rollForward: feature)
- MSBuild SDKs:
  - `Microsoft.Build.NoTargets` 3.0.4
  - `Microsoft.Build.Traversal` 3.0.23
  - `Microsoft.Windows.WinmdGenerator` 0.3.11-preview

**`configurations/configuration.dsc.yaml`** (developer setup):
- Visual Studio 2022 with VC++ tools (x86, x64, ARM64)
- Windows 11 SDK (26100)
- .NET 8.0 SDK
- ILSpy (for inspecting .winmd files)

**`nuget.config`**: Single NuGet source from Azure Artifacts feed (`Win32Metadata-Dependencies`)

#### 4.2 Directory.Build.props (Root)

- Configuration defaults to `Debug`
- Output: `bin\$(Configuration)\`
- Packages: `bin\Packages\$(Configuration)\NuGet\`
- Tools target: `net8.0`
- Uses `Nerdbank.GitVersioning` 3.5.119 for version management
- `LastWin32MetadataReleaseVersion`: `69.0.7-preview`

#### 4.3 Top-Level Build Entry Point — `DoAll.ps1`

```
DoAll.ps1
├── Get-VSPath.ps1              # Validate VS is installed
├── CleanOutputs.ps1            # (optional) Clean previous outputs
├── CommonUtils.ps1             # Load shared utilities
│   └── Install-BuildTools      # dotnet restore/build BuildTools
├── BuildMetadataBin.ps1        # Scrape headers + emit .winmd
│   ├── GenerateMetadataSource  # (internal) ClangSharp scraping
│   └── dotnet build EmitWinmd  # Compile C# → .winmd
├── DoPackages.ps1              # Pack NuGet packages
├── DoSamples.ps1               # Build C++ and C# samples
└── DoTests.ps1                 # Run all tests
    ├── dotnet test MetadataUtils.Tests
    └── TestWinmdBinary.ps1
        ├── dotnet test Windows.Win32.Tests
        └── CompareBinToLastRelease.ps1
```

**Key parameters**: `-Clean`, `-ExcludePackages`, `-ExcludeTests`, `-ExcludeSamples`, `-SkipInstallTools`, `-arch` (crossarch|x64|x86|arm64)

#### 4.4 Azure Pipelines CI/CD

**Main pipeline** (`azure-pipelines.yml`): Triggers on `main` branch pushes/PRs (excludes `apidocs/` and `docs/`).

| Job | Description | Dependencies |
|-----|-------------|--------------|
| `scrape_x64` | Scrape headers for x64 arch | — |
| `scrape_x86` | Scrape headers for x86 arch (+ constants) | — |
| `scrape_arm64` | Scrape headers for arm64 arch | — |
| `build_winmd` | Merge arches → build winmd → test → sign → package | All 3 scrape jobs |

The scrape jobs run **in parallel** on `windows-2022` VMs, then `build_winmd` downloads all three artifacts and produces the cross-architecture .winmd.

**Code signing**: ESRP Authenticode signing for `Windows.Win32.winmd`, SDK DLLs, and NuGet packages (only on non-PR builds with `SignFiles=true`).

**API docs pipeline** (`azure-pipelines-apidocs.yml`): Separate pipeline triggered only by changes in `apidocs/`. Builds and packages `Microsoft.Windows.SDK.Win32Docs`.

**Release pipeline** (`release.yml`): Triggered by `auto-release` tag. Creates GitHub draft release, then pushes packages to nuget.org.

### 5. The `generation/` Folder — Core Metadata Generation

#### 5.1 Windows.Win32.proj

The main MSBuild project file that orchestrates generation. Uses the `Microsoft.Windows.WinmdGenerator` SDK, which provides MSBuild targets for scraping and emitting.

**Key MSBuild targets** (invoked by scripts):
- `ScrapeHeaders` — Runs ClangSharp on each partition's `main.cpp`
- `ScrapeConstants` — Runs ConstantsScraper on headers
- `EmitWinmd` — Compiles scraped C# files into `Windows.Win32.winmd`

**Key properties**:
- `OutputWinmd` → `..\..\bin\Windows.Win32.winmd`
- `SdkIncRoot` → `RecompiledIdlHeaders` (pre-compiled SDK headers)
- `ExcludeFromCrossarch` → 242 partitions excluded from cross-arch compilation

#### 5.2 Partitions (~240)

Each partition is a directory under `generation/WinSDK/Partitions/` containing:
- **`main.cpp`** — `#include` statements for the headers in that partition
- **`settings.rsp`** — Configuration: `--traverse` (which headers), `--namespace` (target namespace), `--exclude`, `--with-librarypath`

Examples: `ActiveDirectory`, `Audio.DirectSound`, `Base`, `Registry`, `P2P`, `Shell`, `Cryptography`, etc.

A partition maps one or more header files to a namespace like `Windows.Win32.Media.Audio.DirectSound`.

#### 5.3 Response Files (.rsp)

| File | Purpose | Example Content |
|------|---------|-----------------|
| `scraper.settings.rsp` | Shared scraper config | `--remap`, `--with-type`, `--exclude`, `--with-librarypath` |
| `emitter.settings.rsp` | Emitter config | `--typeImport`, `--enumAddition`, `--enumMakeFlags`, `--memberRemap` |
| `libMappings.rsp` | Function→DLL mappings | `CreateFileW=kernel32.dll` |
| `libMappingsManual.rsp` | Manual DLL overrides | For deprecated/special functions |
| `requiredNamespacesForNames.rsp` | Type→namespace overrides | `APPCATEGORYINFO=Windows.Win32.UI.Shell` |
| `supportedOS.rsp` | OS version attributes | `SupportedOSPlatform("windows5.1.2600")` |
| `WithSetLastError.rsp` | Functions calling SetLastError | `--with-setlasterror` list |
| `ConstantsScraper.settings.rsp` | Constants scraper config | Type attributes for constants |
| `documentationMappings.rsp` | Documentation URL links | `[Documentation("https://...")]` attributes |

#### 5.4 JSON Configuration Files

| File | Purpose |
|------|---------|
| `enums.json` | Defines enums with auto-populate rules (filter pattern + header), manual members, and usage locations |
| `autoTypes.json` | Auto-generated handle types (DECLARE_HANDLE pattern) |
| `functionPointerFixups.json` | Corrections for function pointer vs prototype distinction |

#### 5.5 Manual C# Overrides (`manual/`)

44 hand-written C# files for APIs that can't be auto-generated from headers. Covers areas like COM, Direct3D, GDI+, Shell, Security, and more.

### 6. The `sources/` Folder — C# Source Projects

All projects target **net8.0**.

| Project | Type | Purpose |
|---------|------|---------|
| **MetadataUtils** | Library | Foundation library: decompiler utils, enum handling, lib scraping, syntax utils, partition info |
| **ClangSharpSourceToWinmd** | Console Tool | Converts ClangSharp C# output → .winmd. Handles cross-arch merging, namespace fixing, syntax tree cleaning |
| **ConstantsScraper** | Console Tool | Extracts constants from C/C++ headers via regex, generates C# source |
| **WinmdUtils** | Console Tool | Inspects/compares .winmd files: `compare`, `showMissing`, `showDuplicates`, etc. |
| **PartitionUtils** | Console Tool | Manages partitions: error checking, traverse headers, enum JSON normalization |
| **GeneratorSdk/MetadataTasks** | Library | MSBuild tasks for the WinmdGenerator SDK |
| **GeneratorSdk** | SDK Package | Contains `sdk.props`, `sdk.targets`, scraper assets, and tools packaged as NuGet |

**Dependency graph**:
```
MetadataUtils (shared library)
    ↑ (referenced by all)
    ├── ClangSharpSourceToWinmd
    ├── ConstantsScraper
    ├── WinmdUtils
    ├── PartitionUtils
    └── GeneratorSdk/MetadataTasks
```

**Key external dependencies**: ClangSharp (header parsing), ICSharpCode.Decompiler (type analysis), Microsoft.CodeAnalysis/Roslyn (C# AST manipulation), System.CommandLine (CLI framework).

### 7. The `scripts/` Folder — 39 PowerShell Scripts

#### Core Build Scripts
| Script | Purpose |
|--------|---------|
| `CommonUtils.ps1` | Shared functions, directory setup, tool installation, NuGet helpers |
| `BuildMetadataBin.ps1` | Main build: scrape headers + emit .winmd (supports `-arch`, `-assetsScrapedSeparately`) |
| `GenerateMetadataSource.ps1` | Runs ClangSharp scraping for a specific architecture |
| `ScrapeHeaders.ps1` | Scrapes headers for a specific partition or all partitions |

#### Orchestration Scripts
| Script | Purpose |
|--------|---------|
| `DoPackages.ps1` | Packs NuGet packages |
| `DoSamples.ps1` | Builds C++ and C# sample projects |
| `DoTests.ps1` | Runs MetadataUtils.Tests + TestWinmdBinary.ps1 |

#### Validation & Comparison
| Script | Purpose |
|--------|---------|
| `TestWinmdBinary.ps1` | Runs Windows.Win32.Tests + compares to last release |
| `CompareBinToLastRelease.ps1` | Uses WinmdUtils `compare` to diff current vs previous .winmd |
| `TestHeaderFileCoverage.ps1` | Verifies all SDK headers are covered by partitions |

#### Configuration Generation
| Script | Purpose |
|--------|---------|
| `CreateProcLibMappingForAllLibs.ps1` | Scans .lib files to generate `libMappings.rsp` |
| `CreateWithSetLastError.ps1` | Scans docs for `GetLastError` callers → `WithSetLastError.rsp` |
| `CreateSupportedOSPlatformRsp.ps1` | Generates OS version attributes from docs |
| `CreateNameToNamespaceMappings.ps1` | Creates `requiredNamespacesForNames.rsp` from API CSV |
| `RecompileIdlFilesForScraping.ps1` | Recompiles MIDL IDL files with SAL annotations |
| `ConvertMidlAttributesToSalAnnotations.ps1` | Converts MIDL attributes to C++ SAL annotations |

#### Setup & Tooling
| Script | Purpose |
|--------|---------|
| `Install-VS.ps1` | Installs/modifies Visual Studio with required workloads |
| `Install-AllSoftware.ps1` | Installs tools via winget (ILSpy, .NET 8, VS Code) |
| `Get-VSPath.ps1` | Locates VS installation via vswhere |
| `CleanOutputs.ps1` | Cleans build outputs and obj directories |

### 8. The `tests/` Folder

| Test Project | Framework | What It Tests |
|--------------|-----------|---------------|
| **Windows.Win32.Tests** | xUnit | Main test suite: validates the generated .winmd for integrity (no duplicates, no broken arch types, no cyclical namespaces), interface layouts, RAII handle attributes |
| **MetadataUtils.Tests** | xUnit + MSTest | Tests shared utilities: .lib parsing, constant processing, winmd loading |
| **ClangSharpSourceToWinmdTests** | MSTest | Tests NativeTypedefStructsCreator: handle value generation |
| **TestCommon** | (shared lib) | Test utilities: asset loading, path resolution, process execution |

**Test data/assets**:
- `InterfacesToVerify.json` — Expected interface method signatures
- Allow-list `.rsp` files — Acceptable known violations (empty delegates, duplicate constants, etc.)
- `.lib` files (arm64, x64, x86) — For testing library import scraping

**Support tools** (in tests/ but not test projects):
- **VtablesFromPdb** — C# tool extracting vtable info from PDB symbols
- **PdbsApp** — C++ native tool for PDB processing

### 9. The `apidocs/` Folder

Produces the **`Microsoft.Windows.SDK.Win32Docs`** NuGet package.

**Components**:
- **ScrapeDocs** (net8.0 console app) — Parses markdown from 6 documentation repositories in `ext/` and serializes API documentation into `apidocs.msgpack` using MessagePack
- **Microsoft.Windows.SDK.Win32Docs** (netstandard2.0 library) — Defines the `ApiDetails` data model and packages the msgpack file

**ApiDetails** data model fields: `HelpLink`, `Description`, `Remarks`, `Parameters` (dict), `Fields` (dict), `ReturnValue`

**Documentation sources** (from `ext/` submodules):
- `ext/sdk-api` → learn.microsoft.com/windows/win32/api/
- `ext/win32` → learn.microsoft.com/windows/win32/
- `ext/Console-Docs`, `ext/sql-docs`, `ext/office-developer-client-docs`, `ext/Virtualization-Documentation`

### 10. Supporting Folders

#### `ext/` — External Git Submodules
Six documentation repositories used by `apidocs/ScrapeDocs` to extract API documentation.

#### `configurations/` — Developer Environment
`configuration.dsc.yaml` — Desired State Configuration defining required VS workloads, SDK versions, and tools. Used via `winget configure`.

#### `buildTransitive/` — NuGet Consumer Integration
MSBuild `.props` files distributed with the `Microsoft.Windows.SDK.Win32Metadata` NuGet package. Exposes `ProjectionMetadataWinmd` MSBuild item pointing to `Windows.Win32.winmd` for consumers.

#### `AzurePipelinesTemplates/` — CI/CD Templates
- `win32metadata-checkout.yml` — Git checkout with LFS and long paths
- `win32metadata-onebranch.yml` — OneBranch pipeline: scrape (3 arches) → build → test → sign → package
- `win32docs-onebranch.yml` — OneBranch pipeline for API docs

#### `licenses/`
SDK license files (`sdk_license.rtf`, `sdk_license.txt`) included in the NuGet package.

---

## End-to-End Workflow

### Full Build (local)

```
DoAll.ps1
  1. Validate VS installation (Get-VSPath.ps1)
  2. Optionally clean (CleanOutputs.ps1)
  3. Install build tools (dotnet restore/build BuildTools)
  4. BuildMetadataBin.ps1 -arch crossarch:
     a. GenerateMetadataSource for each arch (x64, x86, arm64):
        - ClangSharp scrapes partition headers → C# files per arch
        - ConstantsScraper extracts constants → C# files (x86 only)
     b. EmitWinmd target:
        - CrossArchTreeMerger merges arch-specific C# files
        - NamesToCorrectNamespacesMover applies namespace overrides
        - MetadataSyntaxTreeCleaner applies remaps, attributes, manual types
        - ClangSharpSourceWinmdGenerator writes Windows.Win32.winmd
  5. DoPackages.ps1: Pack NuGet packages
  6. DoSamples.ps1: Build sample projects
  7. DoTests.ps1:
     a. Run MetadataUtils.Tests (unit tests)
     b. Run Windows.Win32.Tests (winmd integrity tests)
     c. Compare winmd to last release (CompareBinToLastRelease.ps1)
```

### CI Build (Azure Pipelines)

```
  ┌──────────┐  ┌──────────┐  ┌────────────┐
  │scrape_x64│  │scrape_x86│  │scrape_arm64│   (parallel)
  └────┬─────┘  └────┬─────┘  └─────┬──────┘
       │              │              │
       └──────────────┼──────────────┘
                      ▼
              ┌───────────────┐
              │ build_winmd   │
              │ ├─ Merge      │
              │ ├─ Emit       │
              │ ├─ Sign       │
              │ ├─ Package    │
              │ ├─ Test       │
              │ └─ Publish    │
              └───────┬───────┘
                      │ (auto-release tag)
                      ▼
              ┌───────────────┐
              │ release.yml   │
              │ ├─ GitHub     │
              │ │   Release   │
              │ └─ nuget.org  │
              │     push      │
              └───────────────┘
```

---

## Code References

### Key Entry Points
- `DoAll.ps1` — Top-level build orchestrator
- `generation/WinSDK/Windows.Win32.proj` — Main MSBuild project
- `sources/ClangSharpSourceToWinmd/Program.cs` — Scraper → emitter tool entry point
- `sources/ConstantsScraper/Program.cs` — Constants scraper entry point
- `sources/WinmdUtils/Program.cs` — .winmd inspection CLI
- `sources/PartitionUtils/Program.cs` — Partition management CLI
- `apidocs/ScrapeDocs/Program.cs` — API docs scraper

### Key Configuration Files
- `generation/WinSDK/scraper.settings.rsp` — Shared scraper config
- `generation/WinSDK/emitter.settings.rsp` — Emitter config (type imports, enum additions, member remaps)
- `generation/WinSDK/enums.json` — Enum definitions with auto-populate rules
- `generation/WinSDK/libMappings.rsp` — Function→DLL mappings
- `generation/WinSDK/requiredNamespacesForNames.rsp` — Type→namespace overrides
- `version.json` — Version: `70.0-preview` (Nerdbank.GitVersioning)
- `global.json` — .NET SDK 8.0.417 + MSBuild SDK versions

### Key Build Scripts
- `scripts/CommonUtils.ps1` — Shared functions used by all scripts
- `scripts/BuildMetadataBin.ps1` — Builds the cross-arch winmd
- `scripts/GenerateMetadataSource.ps1` — Runs ClangSharp scraping per arch
- `scripts/TestWinmdBinary.ps1` — Validates winmd and compares to previous release

### Key Test Files
- `tests/Windows.Win32.Tests/IntegrityTests.cs` — Core winmd validation
- `tests/Windows.Win32.Tests/InterfaceTests.cs` — Interface layout verification
- `tests/MetadataUtils.Tests/` — Unit tests for shared utilities

---

## Architecture Insights

1. **Partition-based namespace assignment**: The ~240 partitions are the primary mechanism for organizing thousands of Win32 APIs into logical namespaces. Each partition maps header files to a `Windows.Win32.*` namespace.

2. **Three-architecture scraping**: Headers are scraped independently for x64, x86, and arm64 to capture architecture-specific type differences. The `CrossArchTreeMerger` then merges these into a unified representation with `[SupportedArchitecture]` attributes.

3. **Constants scraped separately on x86 only**: Constants don't vary by architecture, so they're extracted just once during the x86 scrape pass.

4. **Layered configuration**: Configuration flows from general to specific: `baseSettings.rsp` (SDK-provided) → `scraper.settings.rsp` (project-wide) → individual partition `settings.rsp`. This layered approach allows per-partition customization.

5. **Manual overrides for difficult APIs**: The `manual/` folder contains 44 hand-written C# files for APIs that ClangSharp can't handle correctly (COM interfaces, complex DirectX types, etc.).

6. **Allow-list testing pattern**: Tests use `.rsp` allow-list files to track known acceptable violations. This enables progressive quality improvement without blocking builds.

7. **Winmd diff as release gate**: Every build compares the new .winmd against the last release via `WinmdUtils compare`. The diff is tracked in `ChangesSinceLastRelease.txt` to ensure all changes are intentional.

8. **Separate pipelines for metadata vs docs**: The API documentation pipeline (`azure-pipelines-apidocs.yml`) is completely independent, triggered only by changes in `apidocs/`.

9. **WinmdGenerator as reusable SDK**: The tooling is packaged as an MSBuild project SDK (`Microsoft.Windows.WinmdGenerator`) so that other projects (like [wdkmetadata](https://github.com/microsoft/wdkmetadata)) can use the same pipeline to generate their own .winmd files from C/C++ headers.

10. **ECMA-335 with extensions**: While the .winmd uses the standard .NET binary format, it adds custom attributes (`[Documentation]`, `[RAIIFree]`, `[NativeTypedef]`, `[SupportedArchitecture]`, etc.) that encode Win32-specific semantics for language projections.

---

## Open Questions

- What is the exact role of `sources/GeneratorSdk/tools/assets/scraper/baseSettings.rsp` vs the project-specific `scraper.settings.rsp`?
- How does the `ExcludeFromCrossarch` list (242 partitions) in `Windows.Win32.proj` get maintained?
- What triggers the `auto-release` tag on the build pipeline?
- How are the `ext/` submodules updated (manually or automated)?

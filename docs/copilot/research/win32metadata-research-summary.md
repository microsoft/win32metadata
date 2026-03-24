# Win32Metadata — Research Summary

*Compiled: March 2026*
*Sources: Codebase analysis, M365 documents, Teams discussions, meeting transcripts*

---

## 1. What Is Win32Metadata?

Win32Metadata is a Microsoft open-source project that generates **machine-readable metadata** (`Windows.Win32.winmd`, ECMA-335 format) for the entire Win32 API surface. It ships as the [`Microsoft.Windows.SDK.Win32Metadata`](https://www.nuget.org/packages/Microsoft.Windows.SDK.Win32Metadata/) NuGet package. Language projections consume this metadata to auto-generate idiomatic Win32 API bindings:

- **C#** via [CsWin32](https://github.com/microsoft/cswin32)
- **Rust** via [windows-rs](https://github.com/microsoft/windows-rs)
- **Community**: Python, Zig, D, Dart, Beef, .NET Standard

### What It Produces

| Output | NuGet Package | Description |
|--------|---------------|-------------|
| `Windows.Win32.winmd` | `Microsoft.Windows.SDK.Win32Metadata` | ECMA-335 metadata for the entire Win32 API |
| WinmdGenerator SDK | `Microsoft.Windows.WinmdGenerator` | MSBuild SDK for generating .winmd from C/C++ headers |
| API Documentation | `Microsoft.Windows.SDK.Win32Docs` | MessagePack binary with Win32 API documentation |

### Why It Matters

- Safest way to generate idiomatic language projections
- Captures semantics not expressible in C headers: DLL exports, versioning, lifetime/RAII, handle specialization, synthetic enums
- Enables accurate parameter typing (e.g., pointer + length → `Span<T>`)
- Provides rich IntelliSense and API annotations
- WinmdGenerator enables Rust usage inside the OS repo and internal APIs for OSClient C#

---

## 2. Architecture

### Two-Stage Pipeline

```
┌─────────────────────────────────────────────────────────────────┐
│                        SCRAPER LAYER                            │
│  ClangSharp parses ~240 "partitions" of Win32 headers           │
│  into C# files (per-arch: x64, x86, arm64)                     │
│  ConstantsScraper extracts constants (x86 only)                 │
└─────────────┬───────────────────────────────────────────────────┘
              ▼
┌─────────────────────────────────────────────────────────────────┐
│                        EMITTER LAYER                            │
│  CrossArchTreeMerger → NamesToCorrectNSMover →                  │
│  MetadataSyntaxTreeCleaner → ClangSharpSourceWinmdGenerator      │
│  → writes Windows.Win32.winmd                                   │
└─────────────┬───────────────────────────────────────────────────┘
              ▼
┌─────────────────────────────────────────────────────────────────┐
│                    PACKAGING LAYER                               │
│  Microsoft.Windows.SDK.Win32Metadata (winmd + headers)          │
│  Microsoft.Windows.WinmdGenerator (SDK for third parties)       │
│  Microsoft.Windows.SDK.Win32Docs (API docs msgpack)             │
└─────────────────────────────────────────────────────────────────┘
```

### Repository Structure

| Folder | Purpose |
|--------|---------|
| `generation/WinSDK/` | ~240 partitions + .rsp config + enums.json + manual C# overrides |
| `sources/` | 6 C# projects: MetadataUtils, ClangSharpSourceToWinmd, ConstantsScraper, WinmdUtils, PartitionUtils, GeneratorSdk |
| `scripts/` | 39 PowerShell scripts for building, testing, validation, config generation |
| `tests/` | xUnit/MSTest suites validating winmd integrity, interfaces, RAII attributes |
| `apidocs/` | Scrapes Microsoft docs repos → `apidocs.msgpack` NuGet package |
| `ext/` | 6 git submodules of documentation repos |
| `AzurePipelinesTemplates/` | CI/CD pipeline templates |

### Build System

- **Entry point**: `DoAll.ps1` orchestrates the full build
- **SDK**: .NET 8.0.417, MSBuild with WinmdGenerator SDK 0.3.11-preview
- **CI**: Azure Pipelines — 3 parallel scrape jobs (x64/x86/arm64) → merge → emit → test → sign → package
- **Release**: `release.yml` triggered by `auto-release` tag → GitHub release + nuget.org push

---

## 3. Current Problems

### 3.1 Boundaries Have Eroded

Win32Metadata should be a clean projection of the Windows SDK, but:

- Contains non-SDK content (e.g., D3D Agility SDK)
- Mixes removed and current APIs
- Includes unknown extra headers
- Fixes are applied in win32metadata instead of the SDK
- Manual mappings and SAL fixes live in `emitter.settings.rsp`

### 3.2 Production Machinery Is Broken

- **No PR validation gates running** — pipeline YAML has `pr:` triggers but they aren't functioning (likely Azure DevOps / GitHub integration issue, or branch protection not configured)
- Release process is manual and error-prone
- SDK updates require many hand-curated steps (`autoTypes.json`, `functionPointerFixups.json`, namespace dependency management)
- Generation lags SDKs by months due to lack of ownership

### 3.3 WinmdGenerator SDK Has Fundamental MSBuild Incompatibility

The WinmdGenerator's MSBuild tasks target **net8.0**, making them incompatible with most MSBuild environments:

| Host MSBuild | Task Assembly (net8.0) | Result |
|---|---|---|
| .NET Framework 4.7.2 (VS 2022) | net8.0 | ❌ **FAILS** |
| .NET 6.0 (`dotnet build`) | net8.0 | ❌ **May fail** |
| .NET 8.0 (`dotnet build`) | net8.0 | ✅ Works |

Tasks are loaded via `UsingTask AssemblyFile` (in-process), but net8.0 assemblies can't load in .NET Framework CLR. The only functional path is `dotnet msbuild`, which nobody uses in practice.

### 3.4 Testing Gaps

**What exists:**
- Integrity tests (duplicates, cycles, broken arch types)
- Interface method signature snapshots (~100 interfaces)
- RAII attribute validation
- Deep metadata diff vs. last release (`CompareBinToLastRelease.ps1`)

**What's missing:**
- No deterministic/reproducible build verification
- No full winmd binary snapshots (only ~100 interfaces)
- No cross-build consistency tests ("build A vs build B")
- No hash-based regression detection
- `ChangesSinceLastRelease.txt` is manually maintained (400+ lines)

### 3.5 Metadata Defined After-the-Fact

- Metadata lives *after* headers → causes drift and bugs
- Bugs get papered over in win32metadata instead of fixed at source
- No "shift-left" integration with SDK production

---

## 4. Strategic Context (from Teams/Documents)

### Key Themes from Discussions

1. **Win32Metadata is critical infrastructure**, not an auxiliary project
2. **Metadata-first authoring** is the long-term direction — metadata should be the canonical source, with headers generated from it
3. **Tooling is "expert-only"** — WinMDGenerator, ClangSharp, and CsWin32 require deep tribal knowledge
4. **Clear ABI/FFI/API distinction** — Win32Metadata enables high-quality FFIs across languages
5. **WinRT as cautionary tale** — too complex, insufficient for many APIs; motivates a cleaner approach
6. **Ownership gap** — effectively unowned despite being business-critical

### Related Documents

- **"We Need to Reinvest in Win32Metadata"** (Jevan Saks) — core proposal document
- **WinPD Architecture API Notes.docx** — applies metadata-first to API authoring
- **CsWin32 & Win32Metadata.md** — ownership and tooling relationship
- **Teams chat thread: "Reinvesting in Win32Metadata"** — deep technical discussions on WinMDGenerator, libclang, SAL, autoTypes.json

---

## 5. CI/CD Pipeline Details

### Azure Pipelines Configuration

**Main pipeline** (`azure-pipelines.yml`):
- Triggers on `main` branch pushes and PRs (excludes `apidocs/`, `docs/`)
- Pool: `windows-2022`
- 4 jobs: `scrape_x64`, `scrape_x86`, `scrape_arm64` (parallel) → `build_winmd`
- `batch: true` (may delay PR runs)

**PR trigger is configured but not functioning** — possible causes:
1. Branch protection rules not requiring CI checks
2. Pipeline not connected to GitHub repo in Azure DevOps
3. `batch: true` delaying/coalescing runs
4. Service connection issues

**No GitHub Actions workflows exist** — repo relies solely on Azure Pipelines.

### WinmdGenerator SDK Packaging

Tasks shipped in `tools/net8.0/` with `.deps.json` and `.runtimeconfig.json`, loaded via `UsingTask AssemblyFile` (in-process). The `.runtimeconfig.json` suggests out-of-proc intent but actual loading is in-process — a fundamental mismatch.

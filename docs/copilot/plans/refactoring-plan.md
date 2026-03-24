# Win32Metadata Refactoring — Implementation Plan

*Created: March 2026*
*Branch: user/jevansaks/refactor*

---

## Overview

This plan addresses the reinvestment needed in win32metadata, organized into five workstreams. The first three are immediate engineering work; the latter two are strategic changes that build on the foundation.

### Workstreams

| # | Workstream | Scope |
|---|-----------|-------|
| 1 | [Fix PR Validation Gates](#workstream-1-fix-pr-validation-gates) | Get CI checks running on every PR |
| 2 | [Add Regression Testing](#workstream-2-add-regression-testing) | Ensure refactoring doesn't change winmd output |
| 3 | [Fix WinmdGenerator MSBuild Compatibility](#workstream-3-fix-winmdgenerator-msbuild-compatibility) | Make the SDK usable from normal MSBuild |
| 4 | [Version-Aligned Packaging](#workstream-4-version-aligned-packaging) | One NuGet per SDK version + meta-package |
| 5 | [Shift-Left Metadata Definition](#workstream-5-shift-left-metadata-definition) | Move metadata closer to SDK production |

---

## Workstream 1: Fix PR Validation Gates

### Problem

The `azure-pipelines.yml` has a `pr:` trigger configured for the `main` branch, but PR checks are not actually running. The pipeline is configured to run on `windows-2022` and the YAML looks correct — the issue is likely at the Azure DevOps / GitHub integration layer.

### Investigation Tasks

- [ ] **1.1 — Verify Azure DevOps pipeline connection**: Confirm the pipeline is connected to the GitHub repo and has the correct service connection. Check Azure DevOps project settings → Pipelines → ensure the pipeline is enabled and linked to the `microsoft/win32metadata` GitHub repo.
- [ ] **1.2 — Check branch protection rules**: In GitHub repo settings → Branches → `main` protection rules, verify that required status checks include the Azure Pipeline. If no status checks are required, PRs will merge without gates.
- [ ] **1.3 — Test with a dummy PR**: Create a test PR to `main` with a trivial change (not in `apidocs/` or `docs/`) and observe whether the pipeline triggers.
- [ ] **1.4 — Consider GitHub Actions alternative**: If Azure Pipelines integration is too fragile, evaluate migrating PR checks to GitHub Actions. The scraping step requires Windows and the Windows SDK, but GitHub Actions supports `windows-latest` runners.

### Implementation Tasks

- [ ] **1.5 — Fix or re-create pipeline connection**: Based on investigation, fix the Azure DevOps ↔ GitHub connection or create a new GitHub Actions workflow for PR validation.
- [ ] **1.6 — Add branch protection rule**: Configure `main` branch protection to require the CI pipeline to pass before merge.
- [ ] **1.7 — Evaluate build time optimization for PRs**: The full cross-arch scrape + emit takes significant time. Consider a lighter PR check (e.g., single-arch scrape + emit + tests) to keep PR feedback fast, with full cross-arch reserved for CI on `main`.

---

## Workstream 2: Add Regression Testing

### Problem

When refactoring win32metadata internals, we need confidence that the generated `Windows.Win32.winmd` output is identical (or intentionally changed). Current testing has gaps:

- `CompareBinToLastRelease.ps1` compares against the *last NuGet release*, not against the current `main` branch
- Interface snapshot tests cover only ~100 interfaces
- No deterministic build verification
- `ChangesSinceLastRelease.txt` is manually maintained (400+ lines)

### Implementation Tasks

- [ ] **2.1 — Extend CompareBinToLastRelease to compare against main**: In addition to comparing against the last NuGet release, compare against the winmd built from the `main` branch. This catches unintentional drift during refactoring.

- [ ] **2.2 — Expand interface snapshot coverage**: The current `InterfacesToVerify.json` covers ~100 interfaces. Extend this to cover all interfaces, or replace with a full winmd serialization diff.

- [ ] **2.3 — Automate ChangesSinceLastRelease.txt**: Generate this file from the winmd diff rather than maintaining it manually. The manual approach is error-prone and doesn't scale.

---

## Workstream 3: Fix WinmdGenerator MSBuild Compatibility

### Problem

The WinmdGenerator SDK's MSBuild tasks target `net8.0`, making them **incompatible with most MSBuild environments**:

- **Visual Studio 2022** runs MSBuild on .NET Framework 4.7.2 → ❌ Can't load net8.0 assemblies
- **`dotnet build`** works only with .NET 8.0 SDK → ✅ But requires `dotnet msbuild` invocation
- Nobody uses `dotnet msbuild` in practice — it's a non-functional SDK

The tasks are loaded via `UsingTask AssemblyFile` (in-process), but net8.0 assemblies can't load in the .NET Framework CLR. The `.runtimeconfig.json` shipped in the package suggests out-of-proc was intended but never implemented.

### Research Tasks

- [ ] **3.1 — Evaluate MSBuild TaskHost / task isolation**: MSBuild 17.x added `TaskFactory="TaskHostFactory"` and newer task isolation features. Research whether these allow running net8.0 tasks from a .NET Framework host. Key docs: [MSBuild task isolation](https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild-task-isolation).

- [ ] **3.2 — Evaluate multi-targeting to netstandard2.0**: Determine which MetadataTasks dependencies prevent targeting `netstandard2.0`. The tasks use `Microsoft.Build.Utilities.Core` (already netstandard-compatible) and `Newtonsoft.Json`. The key question is whether `ClangSharpSourceToWinmd` and other tools can run under netstandard2.0.

- [ ] **3.3 — Evaluate out-of-process tool invocation**: Several tasks (notably `EmitWinmd`) already wrap `dotnet` CLI calls via `ToolTask`. Evaluate converting all tasks to this pattern — invoke `dotnet run` on the actual tool assemblies rather than loading them in-process.

- [ ] **3.4 — Evaluate .NET tool packaging**: Package the tools as `dotnet tool` packages that can be invoked via `dotnet tool run`. This completely decouples the tool runtime from the MSBuild host.

### Implementation Options (choose after research)

**Option A: Multi-target `netstandard2.0` + `net8.0`**
```xml
<TargetFrameworks>netstandard2.0;net8.0</TargetFrameworks>
```
Ship both; sdk.targets selects the right one based on MSBuild host. Maximum compatibility, but may require API changes if net8.0-only features are used.

**Option B: Out-of-process task execution**
Convert all MSBuild tasks to `ToolTask` that invoke `dotnet` on separate assemblies. Tasks become thin wrappers; actual work runs in its own process with the correct runtime. This is what `EmitWinmd` already does — extend the pattern.

**Option C: dotnet tool packaging**
Package as `dotnet tool` and invoke via `Exec` in MSBuild targets. Cleanest separation but changes consumption model.

**Option D: MSBuild TaskHostFactory**
Use `TaskFactory="TaskHostFactory"` to run tasks in a separate process with the correct runtime. Requires MSBuild 17.x+ support validation.

### Implementation Tasks (after option selected)

- [ ] **3.5 — Implement chosen solution for MetadataTasks**
- [ ] **3.6 — Update sdk.props and sdk.targets**
- [ ] **3.7 — Update BuildSdk.nuspec packaging**
- [ ] **3.8 — Test with Visual Studio MSBuild (net472 host)**
- [ ] **3.9 — Test with `dotnet build` on .NET 6.0, 8.0, 9.0**
- [ ] **3.10 — Update documentation and samples**
- [ ] **3.11 — Bump WinmdGenerator version and publish preview**

---

## Workstream 4: Version-Aligned Packaging

### Problem

Win32Metadata currently ships a single cumulative package that mixes APIs from different SDK versions, including removed APIs and non-SDK content (D3D Agility SDK). This blurs boundaries and makes it impossible to target a specific SDK version.

### Proposal

- Ship **one `Microsoft.Windows.SDK.Win32Metadata` package per Windows SDK version** (e.g., `10.0.26100`)
- Introduce a **meta-package** (`Microsoft.Windows.Metadata`) that aggregates SDK, WDK, D3D Agility, etc.
- Keep clear boundaries: each package corresponds to exactly one SDK
- Reject the "forever cumulative" model

### Tasks

- [ ] **4.1 — Design package versioning scheme**: Define how NuGet package versions map to SDK versions. Consider: `major.minor.build.patch` matching SDK versions.
- [ ] **4.2 — Inventory non-SDK content**: Identify all APIs currently in win32metadata that don't come from the Windows SDK (D3D Agility, removed APIs, extra headers).
- [ ] **4.3 — Separate non-SDK content into distinct packages**: Move D3D Agility SDK metadata to its own package. Remove dead/removed APIs.
- [ ] **4.4 — Design meta-package structure**: Define how the meta-package references constituent packages.
- [ ] **4.5 — Update build pipeline for multi-SDK support**: Modify the pipeline to build against a specific SDK version and produce version-tagged packages.
- [ ] **4.6 — Update consumer documentation**: Document the new package model for CsWin32, windows-rs, and other consumers.

---

## Workstream 5: Shift-Left Metadata Definition

### Problem

Metadata is currently generated *after* headers are published in the SDK, causing drift, bugs, and months-long delays. Bugs get papered over in win32metadata instead of fixed at the source.

### Phased Approach (from Jon Wiswall)

**Immediate:**
- Keep tooling public and open-source
- Snapshot annotations into the OS repo
- Generate metadata as part of SDK builds
- Ship version-aligned NuGet packages

**Medium-term:**
- Define better authoring tooling
- Move annotations closer to source (enhance in-header annotations)
- Improve WinMDGenerator ergonomics and diagnostics

**Long-term:**
- Require new Win32 APIs to be authored metadata-first
- Define higher-level authoring language (IDL-like)
- Generate C headers downstream from metadata

### Tasks

- [ ] **5.1 — Document metadata-first authoring vision**: Write a design document for the metadata-first workflow.
- [ ] **5.2 — Identify pilot APIs**: Select a small set of new APIs to author metadata-first as a proof of concept.
- [ ] **5.3 — Improve WinMDGenerator diagnostics**: Add better error messages, validation, and documentation.
- [ ] **5.4 — Define annotation schema**: Formalize the annotations that encode Win32 semantics (RAII, handles, arrays, lifetime).

---

## Dependencies Between Workstreams

```
Workstream 1 (PR Gates)  ──────────────────────────────────────┐
                                                                │
Workstream 2 (Regression Tests) ──── enables safe refactoring ──┤
                                                                │
Workstream 3 (MSBuild Compat) ─── requires tests from WS2 ─────┤
                                                                │
Workstream 4 (Versioned Packages) ── requires working CI ───────┘
                                     from WS1 + WS3
Workstream 5 (Shift-Left) ────── long-term, independent ────────
```

**Recommended execution order:**
1. **WS1 + WS2 in parallel** — fix gates and add tests first (foundation)
2. **WS3** — fix MSBuild compat with confidence from WS2 tests
3. **WS4** — implement version-aligned packaging with working CI from WS1
4. **WS5** — long-term strategic work, begin design docs in parallel

---

## Architectural Principles

These principles guide all workstreams:

1. **Win32Metadata is critical platform infrastructure**, not an afterthought
2. **Metadata should be the canonical source of truth** — headers and projections are derived
3. **Clear ABI / FFI / API distinction** — Win32Metadata enables high-quality FFIs
4. **Language-neutral** — enable Rust, C#, C++ projections from same metadata
5. **Version-aligned** — metadata packages match SDK versions exactly
6. **Tested and gated** — every PR must pass validation before merge
7. **Bugs fixed at source** — stop patching SDK issues in win32metadata

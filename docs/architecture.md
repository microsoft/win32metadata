# Architecture

The toolchain converts C and C++ headers directly to Windows metadata:

```text
raw SDK headers + import libraries + annotation contracts
    -> aggregate + satellite translation units per architecture
    -> windows-clang snapshots (x64, x86, arm64 in parallel)
    -> per-architecture RDL/WinMD
    -> windows-rdl/windows-metadata architecture merge
    -> Windows.Win32.winmd
```

`tools/rust/win32metadata-tools` is the implementation. It uses the public
`windows-clang`, `windows-rdl`, and `windows-metadata` libraries from
[windows-rs](https://github.com/microsoft/windows-rs).

The `Microsoft.Windows.WinmdGenerator` NuGet package is an MSBuild SDK containing
that native executable, its pinned `libclang.dll`, matching Clang 22.1.8 resource
headers, and thin `Sdk.props` and `Sdk.targets` wrappers. Consumer generation is
offline after package restore and does not clone LLVM. The package does not contain the former C# scraper,
constants scraper, emitter, response files, or JSON fixup databases.

## Inputs

- `Partition`: focused translation units such as `main.cpp`; each file is compiled
  unchanged, with generator contracts supplied through Clang arguments.
- `WinmdIncludeDir`: directories containing the headers.
- `ImportLibs`: import-library files or directories used to map functions to DLLs.
- `TargetArchitectures`: `x64`, `x86`, and/or `arm64`.
- `WinmdScope` and `WinmdScopeHeader`: declarations to emit unconditionally.
- `WinmdRootNamespace`, `WinmdAssemblyName`, `WinmdVersion`, and `OutputWinmd`.

Metadata semantics belong in the SDK headers and libraries. The generator does not
accept API-specific RSP or JSON sidecars.

`AssociatedConstant` dependencies are resolved from declarations in the supplied
partition translation units. Only referenced loose constants are emitted into the
annotated enum's configured root namespace; missing or conflicting providers fail
instead of falling back to a name list or synthetic declaration.

## Repository build

`generation/WinSDK/Windows.Win32.proj` consumes the same SDK targets used by the
NuGet package. The production header manifest constructs one aggregate and one
satellite translation unit for each architecture. x64, x86, and arm64 extraction
runs in parallel, then the three results are merged into
`bin/Windows.Win32.winmd`.

```powershell
.\scripts\BuildMetadataBin.ps1
```

For a faster raw-tool inner loop:

```powershell
.\scripts\Generate-WindowsRsWinmd.ps1 `
    -Partition Foundation `
    -Architecture x64 `
    -Namespace Windows.Win32.Foundation
```

Focused custom translation units remain available for package fixtures and
partition-level diagnosis. Multiple generated RDL directories can also be compiled
into one metadata assembly:

```powershell
win32metadata-tools compile `
    --input obj\Foundation\rdl `
    --input obj\Power\rdl `
    --assembly-name Windows.Win32 `
    --output bin\Windows.Win32.winmd
```

This composition step consumes only source-generated RDL. It does not introduce an
API-specific semantic sidecar.

Before the production build, legacy partition inputs can be preflighted independently for all
three architectures. The bounded process isolation reports every failing
partition in one run and avoids retaining the entire SDK queue in one process:

```powershell
.\scripts\Test-WindowsRsPartitions.ps1
```

The two-input production build remains necessary after preflight to detect cross-header
name collisions, duplicate declarations, and architecture-merge differences.

## Package validation

`scripts/Test-GeneratorSdkPackage.ps1` builds the NuGet package, restores it into
an isolated consuming project, then generates without restore or network access
under a deep Windows path. It verifies unchanged translation-unit semantics
(direct declarations, include order, feature macros, and macro-expanded includes),
annotation diagnostics, assembly identity, and a checked-in API golden.

PR validation permits only an exact reviewed set of known raw-header convergence
failures when targeting `feature/shift-left-annotations`. A missing, additional,
crashing, or diagnostically changed failure fails the workflow.

# Architecture

The toolchain converts C and C++ headers directly to Windows metadata:

```text
partition translation units + header roots + import libraries
    -> windows-clang
    -> RDL
    -> windows-rdl/windows-metadata
    -> .winmd
```

`tools/rust/win32metadata-tools` is the implementation. It uses the public
`windows-clang`, `windows-rdl`, and `windows-metadata` libraries from
[windows-rs](https://github.com/microsoft/windows-rs).

The `Microsoft.Windows.WinmdGenerator` NuGet package is an MSBuild SDK containing
that native executable, its pinned `libclang.dll`, and thin `Sdk.props` and
`Sdk.targets` wrappers. The package does not contain the former C# scraper,
constants scraper, emitter, response files, or JSON fixup databases.

## Inputs

- `Partition`: translation units such as `main.cpp`.
- `WinmdIncludeDir`: directories containing the headers.
- `ImportLibs`: import-library files or directories used to map functions to DLLs.
- `TargetArchitectures`: `x64`, `x86`, and/or `arm64`.
- `WinmdScope` and `WinmdScopeHeader`: declarations to emit unconditionally.
- `WinmdRootNamespace`, `WinmdAssemblyName`, `WinmdVersion`, and `OutputWinmd`.

Metadata semantics belong in the SDK headers and libraries. The generator does not
accept API-specific RSP or JSON sidecars.

## Repository build

`generation/WinSDK/Windows.Win32.proj` consumes the same SDK targets used by the
NuGet package. Its 321 partition translation units are compiled for all three
architectures and merged into `bin/Windows.Win32.winmd`.

```powershell
.\scripts\BuildMetadataBin.ps1
```

For a faster raw-tool inner loop:

```powershell
.\scripts\Generate-WindowsRsWinmd.ps1 -Partition Foundation -Architecture x64
```

## Package validation

`scripts/Test-GeneratorSdkPackage.ps1` builds the NuGet package, restores it into
an isolated consuming project, parses a custom header, generates a WinMD, verifies
the assembly identity, dumps the API surface through `WinmdUtils`, and compares it
with a checked-in golden file.

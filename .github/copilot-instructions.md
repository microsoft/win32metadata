# Copilot instructions

## Build

```powershell
.\DoAll.ps1 -Clean
.\scripts\BuildMetadataBin.ps1
dotnet build BuildTools -c Release
```

`BuildMetadataBin.ps1` builds the packaged Rust tool when needed and generates
`bin\Windows.Win32.winmd` from all partitions for x64, x86, and arm64.

For a targeted inner loop:

```powershell
.\scripts\Generate-WindowsRsWinmd.ps1 -Partition Foundation -Architecture x64
```

## Tests

```powershell
.\scripts\DoTests.ps1
.\scripts\Test-GeneratorSdkPackage.ps1
dotnet test tests\MetadataUtils.Tests -c Release
dotnet test tests\Windows.Win32.Tests -c Release
```

The package integration test builds `Microsoft.Windows.WinmdGenerator`, restores
it into an isolated project, parses a custom header, emits a WinMD, verifies its
assembly identity, and compares an ILSpy-style API dump with a golden file.

## Architecture

`tools/rust/win32metadata-tools` converts partition translation units and header
roots to RDL with `windows-clang`, then compiles and merges architectures with
`windows-rdl` and `windows-metadata`.

`sources/GeneratorSdk/sdk/sdk.props` and `sdk.targets` are thin MSBuild wrappers.
`sources/GeneratorSdk/nuget/BuildSdk.nuspec` packages the native host executable
and pinned `libclang.dll`.

Metadata semantics belong in SDK headers and import libraries. Do not add RSP,
JSON, or manual C# metadata sidecars.

The Windows SDK queue lives in `generation/WinSDK/Partitions`. Each partition has
a `main.cpp`; the full project is `generation/WinSDK/Windows.Win32.proj`.

After metadata changes, compare `bin/Windows.Win32.winmd` with the release
baseline using `.\scripts\DiffWinmdToBaseline.ps1`.

# Copilot instructions

## Build

```powershell
.\DoAll.ps1 -Clean
.\scripts\BuildMetadataBin.ps1
dotnet build BuildTools -c Release
```

`BuildMetadataBin.ps1` builds the packaged Rust tool when needed and generates
`bin\Windows.Win32.winmd` from aggregate, satellite, two PSAPI variants and an independent
WinHTTP input for each of x64, x86, and arm64. Architecture extraction runs in parallel.
Use `-ArchitectureJobs 1` to process complete architecture workers sequentially;
all three architectures remain selected.
Normal builds copy the pristine mirror, apply sorted post-MIDL patches without
MIDL rewriting, and consume `generation\WinSDK\obj\RecompiledIdlHeaders` under
canonical partition authority. `-RawSdk` preserves the explicit raw SDK mode.

For a targeted inner loop:

```powershell
.\scripts\Generate-WindowsRsWinmd.ps1 -Partition Foundation -Architecture x64
```

## Tests

```powershell
.\scripts\DoTests.ps1
.\scripts\Test-GeneratorSdkPackage.ps1
.\scripts\Test-WindowsRsHeaders.ps1
.\scripts\Prepare-WindowsRsHeaders.ps1 -VerifyOutput .\bin\Windows.Win32.winmd
dotnet test tests\MetadataUtils.Tests -c Release
dotnet test tests\Windows.Win32.Tests -c Release
```

The package integration test builds `Microsoft.Windows.WinmdGenerator`, restores
it into an isolated project, then generates offline under a deep Windows path.
It verifies unchanged custom translation-unit semantics, annotation diagnostics,
assembly identity, and an ILSpy-style API golden.

## Architecture

`tools/rust/win32metadata-tools` converts the raw SDK aggregate/satellite inputs
or unchanged focused translation units to RDL with `windows-clang`, then compiles
and merges architectures with `windows-rdl` and `windows-metadata`.

`sources/GeneratorSdk/sdk/sdk.props` and `sdk.targets` are thin MSBuild wrappers.
`sources/GeneratorSdk/nuget/BuildSdk.nuspec` packages the native host executable
with pinned `libclang.dll` and matching Clang 22.1.8 resource headers. Consumer
generation must not require Git or network access after restore.

Metadata semantics belong in SDK headers and import libraries. Do not add RSP,
JSON, or manual C# metadata sidecars.

Legacy focused inputs live in `generation/WinSDK/Partitions`. The production
header manifest, PSAPI variants and independent WinHTTP context are built by
`generation/WinSDK/Windows.Win32.proj`.

After metadata changes, compare `bin/Windows.Win32.winmd` with the release
baseline using `.\scripts\DiffWinmdToBaseline.ps1`.

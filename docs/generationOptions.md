# WinmdGenerator options

`Microsoft.Windows.WinmdGenerator` is an MSBuild project SDK backed by
`windows-clang`, `windows-rdl`, and `windows-metadata`.

```xml
<Project Sdk="Microsoft.Windows.WinmdGenerator">
  <PropertyGroup>
    <OutputWinmd>$(MSBuildProjectDirectory)\bin\Sample.winmd</OutputWinmd>
    <WinmdRootNamespace>Sample.Api</WinmdRootNamespace>
    <WinmdAssemblyName>Sample.Metadata</WinmdAssemblyName>
    <WinmdVersion>1.2.3.4</WinmdVersion>
    <TargetArchitectures>x64</TargetArchitectures>
    <UseWinSDKAssets>false</UseWinSDKAssets>
  </PropertyGroup>

  <ItemGroup>
    <Partition Include="main.cpp"/>
    <WinmdIncludeDir Include="$(MSBuildProjectDirectory)"/>
    <WinmdScopeHeader Include="SampleApi"/>
  </ItemGroup>
</Project>
```

## Properties

| Property | Purpose | Default |
| --- | --- | --- |
| `OutputWinmd` | Output metadata path. | `bin\<project>.winmd` |
| `TargetArchitectures` | Semicolon-separated target architectures. | `x64;x86;arm64` |
| `WinmdRootNamespace` | Root namespace for emitted declarations. | `Windows.Win32` |
| `WinmdAssemblyName` | Assembly identity. | Output file stem |
| `WinmdVersion` | Four-part assembly version. | `255.255.255.255` |
| `WinmdObjDir` | RDL and per-architecture intermediate directory. | `obj\winmd` |
| `UseWinSDKAssets` | Include the packaged WinSDK annotation shim. | `true` |
| `Win32MetadataToolsExe` | Override the packaged native tool path. | Package host tool |
| `LibClangPath` | Directory containing the pinned `libclang.dll`. | Package host tool directory |

## Items

| Item | Purpose |
| --- | --- |
| `Partition` | Translation unit to parse. Repeatable. |
| `WinmdIncludeDir` | Header root. Repeatable and order-sensitive. |
| `ImportLibs` | Import-library directory or file for symbol-to-DLL mapping. |
| `WinmdScope` | Header directory segment emitted unconditionally. |
| `WinmdScopeHeader` | Header stem emitted unconditionally. |

The SDK deliberately has no response-file, manual C#, enum JSON, auto-type JSON,
or function-pointer-fixup inputs. Those metadata semantics must be expressed in
the source headers and libraries.

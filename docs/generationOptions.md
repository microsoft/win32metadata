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
| `WinmdScopeHeader` | Header name or stem emitted unconditionally. Include `.h` for names containing dots, such as `windows.graphics.interop.h`. |

The WinSDK project explicitly includes its WinRT interop and partition-local
headers as roots. Merely including these files in a partition does not make all
their declarations roots: the tool's default directory scopes are `shared` and
`um`. For example, `DocumentSource.h`, `MemoryBuffer.h`, and
`windows.graphics.interop.h` must be selected to retain their standalone interop
interfaces. Keep the explicit header-name casing aligned with the include
spellings; the current reader distinguishes casing after the first character.

The repository's WinSDK project also supplies `AdditionalHeaders` as an include
directory for `win32metadata_annotations.h`. The packaged SDK instead obtains
that shim from its WinSDK assets. Both paths must be available without relying
on a previously prepared local build.

Some SDK headers cannot share a translation unit. The VDS provider declarations
in `vdshwprv.h`, for example, use a separate `VirtualDiskService.Provider`
partition from `vds.h`. Keep annotations on their shared native declarations
consistent to avoid conflicting duplicate types in the combined metadata.
Other partition inputs include prerequisite headers before SDK constant headers;
for example, `olectl.h` must precede `msxml6did.h`.
The metadata-only `LMDFS.h` patch supplies the released `FSCTL_DFS_BASE` alias
previously defined in manual C# so the existing native `CTL_CODE` expression can
be evaluated. The native expression and non-metadata compilation are unchanged.
Place metadata-only enum declarations in the header's active C++ branch, not
its MIDL-only branch. Preserve the native macros when exposing those groupings.

The WinSDK input currently omits `x3daudio.h`. Its `X3DAUDIO_VECTOR` alias
depends on `DirectX::XMFLOAT3`, but the reader skips that native namespace and
then cannot compile the generated RDL. This also blocks 14 constant names
present in the released WinMD. Do not replace the native vector declaration
or change its namespace to hide the reader limitation.

The SDK deliberately has no response-file, manual C#, enum JSON, auto-type JSON,
or function-pointer-fixup inputs. Those metadata semantics must be expressed in
the source headers and libraries.

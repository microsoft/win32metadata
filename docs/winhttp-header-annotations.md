# WinHttp header annotations

This pilot moves the functional WinHttp sidecars into reviewed header patches while
retaining the C# scraper/emitter and the matched ClangSharp 21 stack. It is a separate
migration layer above the tooling PR, not a replacement for that tooling. No other
partition is migrated.

## Inputs and ownership

`generation\WinSDK\patches\WinHttp.json` pins SDK CPP `10.0.26100.7705`, the
post-MIDL mirror Git tree, exact header preimages, their selected-SDK inputs, and
patch order. `winhttp.h` is byte-identical to the selected package. The package
supplies `httprequest.idl`, not `httprequest.h`; the recipe separately pins the
checked-in post-MIDL header and the identical selected-SDK IDL. There are no
pre-MIDL changes or IDL recompilation in this migration.

Only WinHttp traverses these two headers. HttpServer also includes `winhttp.h`,
but traverses `http.h`, so it is an affected physical-header dependent rather than
a second owner. The mirror and partition include inventory contains no other
direct or transitive includes of these headers. WinInet is a semantic dependent:
its two existing create-URL flag uses refer to the WinHttp-owned enum, and its
existing `HTTP_VERSION_INFO` exclusion preserves that type's WinHttp ownership.

`Prepare-SdkHeaders.ps1` copies the complete mirror into a private,
content-addressed include tree and applies the ordered post-MIDL patches there.
It checks SDK/preimage identity, admitted patch targets, source/cache hashes,
ordinary paths, patch ordering, and strict patch applicability. Publication is
transactional and serialized; a modified published cache is rejected, not repaired
while a scraper might be reading it. Unmodified files retain their exact bytes.
The tracked SDK mirror is never an output.

The repository project prepares this tree before scraping and uses the same root
for constants. Changing its identity invalidates both scrape markers. Namespace,
traversal, architecture, schema, and cross-partition declaration-ownership
configuration remain build inputs, not replacements for functional annotations.

## Migration accounting

The scraper sees 61 native WinHttp functions; the final OLD winmd emits 59 API
methods. The other two native declarations lack an import binding and are not
emitted as APIs. Import-library names alone are not declarations: 20 additional
WinHttp library-map candidates are outside the emitted scope and remain unmigrated.

| Functional fact | Migrated source | Legacy input removed |
| --- | --- | --- |
| 59 DLL bindings | `_Win32_ImportLibrary_("WINHTTP.dll")` | 59 emitted-function `libMappings.rsp` rows |
| 38 OS floors: 27 XP, 11 Windows 8 | Fixed `_Windows_SupportedOS_*_` macros | All 38 WinHttp `supportedOS.rsp` rows |
| 28 thread-last-error contracts | `_Win32_SetLastError_` | All 28 WinHttp `WithSetLastError.rsp` rows |
| One same-allocation buffer | `_Win32_ContainsInteriorPointers_` on `WinHttpQueryHeadersEx::pBuffer`, with its original byte-count SAL | Interior-pointer member remap |
| Five logical enums, 21 emitted members, eight uses | Guarded native enums plus `_Win32_AssociatedEnum_` at each native use | WinHttp enum definitions and all eight enum substitutions |
| Three port constant types | Guarded `constexpr INTERNET_PORT` declarations | Three `ushort` constant overrides |
| Four scheme constant spellings | Genuine `INTERNET_SCHEME_*` members | Four constants-scraper exclusions |
| One pointer-adding callback alias | Metadata-only guard around `LPWINHTTP_STATUS_CALLBACK` | Partition callback exclusion |

All 59 bindings independently match the selected SDK's x64 `winhttp.lib`
(`SHA256 6873F0B8893E8E7BD86CB7A8310631B3FCDE99A85486196FE61CE9F1A352906A`).
`WinHttpIsHostInProxyBypassList` and `WinHttpQueryAuthParams` have native declarations
but no binding in that library or OLD metadata; neither is a final-winmd API, and
the migration does not invent a binding or synthetic declaration.
The 38 OS contracts and 28 last-error contracts were checked against
MicrosoftDocs/sdk-api revision `656e9656bfaef34dd29cd7ee9e1146aec17e924c`.
The XP annotations retain the conservative in-box floor rather than asserting
Windows 2000 redistributable availability as an unconditional OS guarantee.

There are no emitted-scope ownership/invalid-value `autoTypes.json` entries,
function-pointer fixups, or manual declarations to migrate. Native `HINTERNET`
remains `void*`; this pilot neither fabricates a handle nor claims ownership
migration coverage it does not exercise. `_WINHTTP_SECURITY_INFO` is conditional
and absent from the OLD emitted scope, so its unrelated global tag remap is not
removed.

All 108 documentation-map rows matching emitted WinHttp declarations/members,
including non-prefix targets such as `HTTP_VERSION_INFO` and `IWinHttpRequest`
members, remain documentation tooling inputs. There is no new documentation
annotation vocabulary or functional fallback in this pilot.

## Native types and source compatibility

Logical enum relationships do not replace the native ABI type in metadata:

| Declaration | Native member | Associated enum | Native type |
| --- | --- | --- | --- |
| `WinHttpOpenRequest` | `dwFlags` | `WINHTTP_OPEN_REQUEST_FLAGS` | `DWORD` |
| `WinHttpOpen` | `dwAccessType` | `WINHTTP_ACCESS_TYPE` | `DWORD` |
| `WinHttpCreateUrl` | `dwFlags` | `WIN_HTTP_CREATE_URL_FLAGS` | `DWORD` |
| `WINHTTP_PROXY_INFO` | `dwAccessType` | `WINHTTP_ACCESS_TYPE` | `DWORD` |
| `WINHTTP_CREDS` / `WINHTTP_CREDS_EX` | `dwAuthScheme` | `WINHTTP_CREDS_AUTHSCHEME` | `DWORD` |
| `URL_COMPONENTS` | `nScheme` | `WINHTTP_INTERNET_SCHEME` | `INTERNET_SCHEME` (`int`) |
| `WINHTTP_PROXY_RESULT_ENTRY` | `ProxyScheme` | `WINHTTP_INTERNET_SCHEME` | `INTERNET_SCHEME` (`int`) |

Only the open-request group is a flags enum, matching OLD. All five groups are
unscoped. Macro push/pop pairs preserve genuine macro spellings and native values.
The shared create-URL enum is owned by the header; `enums.json` retains only the two
unmigrated WinInet `addUsesTo` relationships, not another definition.

The old authentication JSON's `INHTTP_AUTH_SCHEME_DIGEST` is a nonexistent typo and
was not emitted. The new group preserves the three actually emitted members;
genuine `WINHTTP_AUTH_SCHEME_DIGEST` remains a loose constant. The scheme group uses
the actual SDK's `INTERNET_SCHEME_HTTP/HTTPS/FTP/SOCKS`, not fabricated
`WINHTTP_INTERNET_SCHEME_*` names. These four old member spellings are an explicit
consumer source-compatibility concern, not a reason to falsify native declarations.

CsWin32 generated-source compatibility is the primary acceptance gate. A metadata
declaration diff is supporting evidence, not a substitute for generating both
marshaling legs, comparing their public surfaces, and compiling the same unchanged
callers against OLD and NEW with the proposed consumer.
`AssociatedEnum` tells that consumer to use the native use site's width and
signedness for the enum and reference it directly in generated signatures and
fields, matching OLD synthetic-enum C#. It does not request an enum-valued property,
an interface-property shim, or a legacy projection mode. Each associated group in
this pilot has one consistent underlying type across all its use sites.

The genuine scheme spellings are also present in the distinct WinInet native enum,
with different values. The duplicate-constant gate admits only the exact
WinHttp/WinInet owner pair for each of these four names, not unqualified name-wide
exceptions. Its mutation controls reject a wrong owner and an additional owner;
the physical enum checks still require the exact WinHttp values.

## Reproducing the image and controls

Build the supported BuildTools first. The frozen OLD directory must contain
`Windows.Win32.winmd`, `provenance.json`, its complete `obj\generated` snapshot,
and `obj\scratch` discovery inputs
from tooling base `b5b7b26ed09d648766f07449af48c64ef0e99d13` and the selected SDK.
It contains 1,642 C# files / 1,654 generated inputs and 37,314 physical TypeDef rows,
including nested helpers. It is not a release-package baseline.

The frozen image has a confirmed pre-existing constructor-signature defect: local
attribute constructor MethodDefs omit `HASTHIS` while their MemberRefs require it.
It is retained as OLD evidence, not described as physically valid. The tooling
layer corrects this separately. A frozen-input tooling control must prove that
only those missing instance bits change and that the corrected image has exact
local constructor binding; the NEW image does not receive a waiver.
The physical control requires exactly 39 constructor rows in 39 types to gain
`HASTHIS`, with every other frozen-input type snapshot unchanged.

```powershell
dotnet build BuildTools -c Release
.\scripts\Build-WinHttpMigrationImage.ps1 -ToolingControl `
    -OutputDirectory .\artifacts\winhttp-migration\tooling-control
.\scripts\Build-WinHttpMigrationImage.ps1 `
    -BaselineDirectory .\artifacts\winhttp-migration\old `
    -OutputDirectory .\artifacts\winhttp-migration\new `
    -ToolingControlDirectory .\artifacts\winhttp-migration\tooling-control
```

The image builder verifies the frozen inputs and tools, scrapes only WinHttp and
HttpServer, overlays their four native source files onto the complete source
closure, recomputes constants with all partition inputs, preserves the other
partitions' discovered pointer fixes, and emits `Windows.Win32.winmd`. It rejects
overwriting an existing consumer-fixture or selection directory. Each image gets
a fresh selected scrape so prior aggregate discoveries cannot become configured
remap authority. Before emission it forces a second normal SDK scrape with that
selection's aggregate discovery present, requiring byte-identical selected C#
sources and pointer discoveries. The frozen discovery inputs must reproduce the
pinned complete pointer-fixup response file before the selected discoveries are overlaid.
`PartitionFilter` alone is not a complete constants/manual/emission closure.
Producer inputs must be committed before image generation and remain unchanged
through receipt publication. The receipt distinguishes the frozen baseline tooling
commit from the current producer commit and binds the actual tool, header, generated
source, discovery, and expected-difference hashes.

```powershell
. .\scripts\CommonUtils.ps1
Install-VsDevShell
$env:WINHTTP_MIGRATION_OLD = (Resolve-Path .\artifacts\winhttp-migration\old\Windows.Win32.winmd).Path
$env:WINHTTP_MIGRATION_NEW = (Resolve-Path .\artifacts\winhttp-migration\new\Windows.Win32.winmd).Path
$env:WINHTTP_MIGRATION_TOOLING_CONTROL = (Resolve-Path .\artifacts\winhttp-migration\tooling-control\Windows.Win32.winmd).Path
$env:WINHTTP_PREPARED_HEADERS = (Get-Content .\artifacts\winhttp-migration\new\selection\obj\prepared-sdk.txt -Raw).Trim()
dotnet test tests\Win32MetadataScraperTests -c Release `
    --filter "FullyQualifiedName~PreparedSdkHeadersTests|FullyQualifiedName~WinHttpMigrationTests|FullyQualifiedName~WinHttpNativeControlTests" `
    --logger "console;verbosity=normal"
```

Integration tests explicitly skip without the pinned fixture environment; skips
are not acceptance. Record nonzero executed counts and require no skipped pilot
legs. Preparation controls cover cache reuse/tampering, preimage/SDK/MIDL mismatch,
path escapes, unadmitted targets, mode/identity changes, duplicate patches, failed
transactions, and lock contention.

Native controls parse the real WinHttp and HttpServer translation units for
x86, x64, and ARM64 with metadata disabled, comparing native signatures, calling
conventions, typedef pointer depth, enum values, field offsets, record sizes, and
alignment. Their exclusive test collection prevents SDK-sized AST walks from
overlapping the generator fixtures that share the native Clang runtime.
Physical readback covers DLL/entrypoint/import flags, attribute targets,
associations, enum values/types, ports, callback identity, architecture coverage,
and local type/attribute-constructor closure, with missing-type/constructor mutation
controls. HttpServer and WinInet snapshots must remain unchanged.

The repository SDK integrity suite reads `bin\Windows.Win32.winmd` and the default
`generation\WinSDK\obj\scratch` diagnostic tree. Stage the complete frozen OLD
nonselected diagnostics plus NEW WinHttp/HttpServer diagnostics there, preserving
their architecture-relative paths, and copy the complete NEW winmd to that local
bin path before running `dotnet test tests\Windows.Win32.Tests -c Release`.
`NoSuggestedRemappings` consumes the actual `*.txt` scraper diagnostics, not just
`*.remaps` or an empty scratch directory. The pinned full closure contains 393
diagnostic files. Do not substitute the selected partition output for that closure.

The full-image decompiler comparison must consume exact symbol/value-scoped expected
differences, with no unknown or unused expectations. It complements these narrow
SRM checks; neither is presented as a comprehensive typed metadata equivalence
oracle. The ten approved Printing fixes belong to the tooling OLD baseline and
must not appear as new WinHttp migration differences.

`patches\WinHttp.expected-differences.txt` admits exactly 24 declaration differences:
native integer types and `AssociatedEnum` at eight sites (16 differences), plus
four genuine scheme member additions and four fabricated-member removals. It
does not admit callback renames, import changes, dependent changes, additional
constants, or changed values. The image builder applies this grade before publishing
its provenance receipt.

## Pinned pilot evidence

The complete migrated image was produced by commit
`9faf8a24831e1ef0a44d4ccfe4cd972f380452b3`, above tooling commit
`00ade0afc94c965522ccdbac54a06fc1bcbd01a1`. The supported pins remain
ClangSharp/Interop/PInvokeGenerator `21.1.8.4`, libclang `21.1.8`, and
libClangSharp `21.1.8.2`.

All three images are `Windows.Win32.winmd` under
`artifacts\winhttp-migration`; none is a selected-partition-only assembly.

| Image | Directory | SHA256 |
| --- | --- | --- |
| Frozen OLD | `old` | `1361407C2888102CB5161D83503235C09C36F917837C7107CA0A80E5CF4FAC43` |
| Frozen-input corrected-tooling control | `tooling-control-final` | `274A288E622B840552934AE74FE2A33FEC4E7D4E47E3D3454B92A147A13B0CDA` |
| Migrated NEW | `new-final` | `C7AEC280B0CBB19CDAD6B94FFED8473B2B22E4042BF886FCF33DCBDD92274258` |

The normal SDK first/repeated selection has ten byte-identical inputs: four native
C# files, four per-TU discovery files, and two aggregate response files. The
complete pointer-reduction set contains 155 entries. The declared OLD/NEW grade
admits all 24 expected differences, with no unknown or unused expectations.
NEW has 1,640 C# files / 1,652 generated inputs: the old synthetic
`Networking.WinHttp.enums.cs` and its processed copy are replaced by declarations
in the native header output, not by missing final metadata.
All 38 pilot cases executed without skips, including the six native ABI legs.
The full SDK integrity suite executed and passed all 14 cases using the complete
393-file diagnostic closure. Strict physical readback finds 37,314 TypeDefs and
37,248 unchanged snapshots outside WinHttp; the frozen-input control changes only
the 39 acknowledged constructor instance bits.

The companion CsWin32 gate requests these APIs/types:

```text
WinHttpOpen
WinHttpConnect
WinHttpOpenRequest
WinHttpCloseHandle
WinHttpCreateUrl
WinHttpCrackUrl
WinHttpSetStatusCallback
WinHttpQueryHeadersEx
WinHttpReadData
WinHttpGetProxyForUrl
WinHttpCreateProxyResolver
WINHTTP_CREDS
WINHTTP_CREDS_EX
WINHTTP_PROXY_RESULT_ENTRY
WINHTTP_PROXY_INFO
URL_COMPONENTS
```

The pinned compilation context is x64, `net8.0-windows`, C# 12, unsafe, public
visibility, `useSafeHandles=true`, and `emitSingleFile=true`. Run both
`allowMarshaling=true` and `false`, with the same unchanged caller source per leg.
Compare OLD + baseline consumer, OLD + proposed consumer, and NEW + proposed
consumer, pinning both consumer revisions explicitly. Public-surface comparison
and actual caller compilation are required; generated text alone is not the gate.
The four old `WINHTTP_INTERNET_SCHEME_*` member spellings remain a specific
source-break candidate until those unchanged callers are compiled. The metadata
does not add compatibility aliases or automatic `HINTERNET` ownership to hide it.

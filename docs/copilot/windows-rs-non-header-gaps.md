# Windows-rs Non-Header Fidelity and Coverage Gaps

## Purpose

This document separates problems that must be fixed in the windows-rs metadata
toolchain or scrape configuration from metadata that genuinely needs to be added to
Windows SDK declarations. None of the items in the first two sections require changing
the native SDK header declaration.

The observations compare a single-translation-unit windows-rs Win32 header scrape with
the win32metadata partition set and with the generated
`Microsoft.Windows.SDK.Win32Metadata` reference.

The SDK selected for generation defines the metadata surface. A partition or copied
header retained in this repository does not make an API part of a newer SDK. Headers
and APIs removed from the selected SDK are omitted from that metadata release;
consumers that require them use metadata generated from an older SDK.

## Toolchain fidelity problems

| Problem | Observed effect | Required tooling work | Status |
| --- | --- | --- | --- |
| SAL implied defaults | Unannotated mutable pointers can be emitted as output-only. SAL semantics instead default an unannotated pointer to `In|Out` with one element and an unannotated scalar to `In`. | Apply the defaults in the Clang-to-RDL parameter model. Do not add redundant `_In_` or `_Inout_` declarations to SDK headers. | Required in the partition pipeline. |
| SAL capture shim missing from explicit partition scraping | `WsRequestReply`, `IWbemEventProviderSecurity::AccessCheck`, and other partition output can lose direction, optionality, count/size relationships, and const-qualified pointer information already present in the headers. | Force-include the SAL capture shim for every partition translation unit. | Required; regenerate the full surface after enabling it. |
| Native constness lost during RDL-to-winmd emission | Clang and RDL retain `*const`, but the final winmd can omit `ConstAttribute`, especially in output generated before the partition SAL fix. | Preserve native `const` through RDL compilation for every partition. | Open in the final winmd path; no header annotation should compensate for it. |
| MIDL parameter comments ignored | Generated headers can contain comments such as `/* [retval][out] */` even though no SAL `_Out_retval_` macro exists. | Tokenize the generated `.h` declaration and recover `[in]`, `[out]`, `[optional]`, `[retval]`, and `[iid_is]` from its MIDL comments. | Required. The tool does not parse `.idl` files directly. |
| Existing `_NullNull_terminated_` not propagated | `GetVolumePathNamesForVolumeNameW` already has the correct SDK SAL contract, but the metadata result did not consistently contain `NullNullTerminated`. | Preserve the existing SAL annotation through Clang, RDL, and winmd emission. | Tooling work; no header change. |
| Architecture-dependent typedef roots omitted | `JET_API_PTR` was used by `JET_INSTANCE` and APIs but its architecture-dependent definition was not emitted, producing apparent width differences and unresolved type roots. | Preserve the typedef owner and merge its x86/x64 definitions into an architecture-neutral metadata representation. | Open architecture/ownership issue. |
| Alignment and packing conflated | The reference omits required `CONTEXT` alignment; x64/ARM64 require 16-byte alignment while x86 uses 4. | Read compiler alignment independently from packing and merge architecture-specific layout correctly. | Direct windows-rs behavior matches the native SDK contract and must not regress. |
| Compiler integer typing discarded | High-bit `IO_REPARSE_TAG_*` values can become signed or truncated when evaluated outside compiler rules. | Use Clang's evaluated type and C integer-conversion rules. | Direct windows-rs behavior is more accurate and must not regress. |
| COM pointer aliases collapse to `void*` | Macro-generated aliases such as `LPADRBOOK` can lose their referenced interface type, as seen in `OpenTnefStreamEx`. | Resolve macro-generated COM interface pointer typedefs and their owning declarations. | Open parser/type-ownership issue. |
| Callback typedef aliases become duplicate public types | `PTOP_LEVEL_EXCEPTION_FILTER` and `LPTOP_LEVEL_EXCEPTION_FILTER` can become a callback plus a projected wrapper even though the native typedef graph already identifies the public alias used by APIs. | Resolve the typedef-alias graph and select the API-facing public callback name. Do not add `CanonicalName` header metadata. | Open generator naming issue. |
| Callback pointer depth or direction is normalized incorrectly | Sidecar `ReducePointerLevel` entries compensate for parser/fixup behavior rather than an SDK semantic contract; `UCharIterator::move` has the correct native pointer depth in direct windows-rs output. | Correct callback typedef resolution and apply SAL implied direction. Use a guarded corrected declaration only if the SDK declaration itself is unsuitable for metadata. | Generator fix; `ReducePointerLevel` is not part of the header vocabulary. |
| Cross-partition owner suppression | `D2D1CreateDevice` and the central `ID2D1Device` hierarchy can be suppressed even though `d2d1_1.h` is traversed. | Fix owner selection, duplicate suppression, and cross-partition reference resolution. | Open generator regression; not a header-list gap. |
| Classic NDR functions filtered or skipped | Many `NdrClientCall*` and related RPC functions are absent while similar variadic declarations emit correctly. | Correct cursor collection and RPC declaration filtering rather than annotating the SDK. | Open generator issue. |
| Public alias policy differs | windows-rs may emit `EnumProcesses` with entry point `K32EnumProcesses`, while win32metadata also exposes a flat `K32EnumProcesses` method. Similar differences occur for CLFS and legacy dbghelp aliases. | Decide whether both public names are required or whether entry-point equivalence is sufficient. | Team projection-policy decision. |
| Raw return values normalized by the reference | `EnumWindows(FALSE)` can mean callback termination, and `LocalFree(NULL)` means success. | Preserve the native `BOOL`/`HLOCAL` result unless explicit metadata justifies transformation. | Direct windows-rs behavior matches the native SDK contract and must not regress. |
| Three-architecture worker pool can hang | Expanded parallel x86/x64/ARM64 generation completed workers without completing the merge or reporting a metadata diagnostic. | Fix worker coordination. Use `WIN32METADATA_SEQUENTIAL=1` as the deterministic validation workaround. | Workaround implemented; root cause remains open. |

## Single-translation-unit scrape-surface omissions

A single translation unit rooted by a `HEADERS` array does not reproduce the 321
purpose-built translation units with family-specific defines, include order, traversal
settings, and namespaces. The comparison found 4,139 reference P/Invoke names absent
from the monolithic scrape.

A literal comparison is much larger than the actionable gap:

- single-translation-unit explicit roots: 365;
- unique direct includes across win32metadata partitions: 1,403;
- direct partition includes not named as windows-rs roots: 1,060.

The 1,060 figure is **not** a list of 1,060 missing headers. Many are reached through
`windows.h` or another root. The following families were confirmed missing because no
root reached their declarations. These counts describe the comparison input, not the
target API surface; families absent from the selected SDK are excluded from generation.

### GDI+ - 620 missing P/Invokes

The `Gdiplus` partition uses:

```cpp
#include <ddraw.h>
#define GDIPVER 0x0110
#include <gdiplus.h>
```

The single-translation-unit roots did not include `gdiplus.h`, so the closure never reached
the declarations in `gdiplusflat.h`, including `GdipCreateBitmapFromFile`.

### AllJoyn - not part of current SDK metadata

The repository-carried `AllJoyn` partition defines `QCC_OS_GROUP_WINDOWS` and directly
includes:

```text
MSAJTransport.h
alljoyn_c\AjAPI.h
alljoyn_c\AboutData.h
alljoyn_c\AboutIconObj.h
alljoyn_c\AboutIconProxy.h
alljoyn_c\AboutObj.h
alljoyn_c\AboutObjectDescription.h
alljoyn_c\AboutProxy.h
alljoyn_c\ApplicationStateListener.h
alljoyn_c\AuthListener.h
alljoyn_c\AutoPinger.h
alljoyn_c\BusAttachment.h
alljoyn_c\BusListener.h
alljoyn_c\BusObject.h
alljoyn_c\DBusStdDefines.h
alljoyn_c\version.h
alljoyn_c\Init.h
alljoyn_c\InterfaceDescription.h
alljoyn_c\KeyStoreListener.h
alljoyn_c\Message.h
alljoyn_c\MsgArg.h
alljoyn_c\Observer.h
alljoyn_c\PasswordManager.h
alljoyn_c\PermissionConfigurationListener.h
alljoyn_c\PermissionConfigurator.h
alljoyn_c\ProxyBusObject.h
alljoyn_c\SecurityApplicationProxy.h
alljoyn_c\SessionListener.h
alljoyn_c\Session.h
```

These copied headers explain why the win32metadata reference contains AllJoyn APIs even
when the SDK selected for generation does not. The unified pipeline must not carry
these headers forward. Metadata generated from an SDK without AllJoyn omits this
surface; consumers that require it must use metadata generated from an older SDK.

### TAPI - 246 missing P/Invokes

The `Tapi3` partition directly includes:

```text
tapi.h
TSPI.h
tapi3err.h
tapi3.h
tapi3if.h
tapi3ds.h
rend.h
mdhcp.h
wabdefs.h
tnef.h
```

It also defines `WIN32=1`. The single-translation-unit root set did not include the TAPI
family.

### Peer-to-peer networking - 175 missing P/Invokes

The `P2p` partition directly includes:

```text
winsock2.h
p2p.h
drt.h
peerdist.h
```

The single-translation-unit root set did not include `p2p.h`, `drt.h`, or `peerdist.h`.
These headers contribute metadata only when they are present in the selected SDK.

### Families that were not confirmed root omissions

The missing-name grouping also highlighted COM, accessibility, clustering, and
WinInet. Their principal headers (`objidl.h`/`oaidl.h`, `oleacc.h`/
`uiautomationcore.h`, `clusapi.h`, and `wininet.h`) were already present in the
windows-rs root set. Their missing declarations therefore require API-specific
ownership, filtering, define, include-order, or alias analysis; they should not be
reported as simple missing-header fixes.

## Partition-based generation

Adding individual headers to the monolithic list was not sufficient because some
families require specific defines, include ordering, traversal settings, exclusions,
and namespaces. The unified pipeline consumes purpose-built partition translation units
constructed from the selected SDK.

The comparison run improved P/Invoke-name coverage from 72.56% to 98.06%. The remaining
354 missing names are primarily RPC/MIDL plumbing, canonical aliases, inline pseudo
APIs, declarations excluded by the selected SDK, and generator ownership/suppression
issues rather than another large SDK root-header omission.

## Return annotation placement

Return-oriented custom annotations do not need to follow the function declarator.
Clang accepts the annotation before the return type and attaches it to the
`FunctionDecl`; windows-rs can then emit it on the metadata return parameter:

```cpp
_Win32_RAIIFree_(CloseHandle, 0, INVALID_HANDLE_VALUE)
HANDLE WINAPI OpenThing(void);
```

This is the required style. Do not place `_Win32_..._` annotations between `WINAPI` and
the function name or after the closing parenthesis.

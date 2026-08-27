# Windows-rs Non-Header Fidelity and Coverage Gaps

## Purpose

This document separates problems that must be fixed in the windows-rs metadata
toolchain or scrape configuration from metadata that genuinely needs to be added to
Windows SDK declarations. None of the items in the first two sections require changing
the native SDK header declaration.

The observations compare the original windows-rs Win32 header scrape with the
win32metadata partition set and with the generated
`Microsoft.Windows.SDK.Win32Metadata` reference.

## Toolchain fidelity problems

| Problem | Observed effect | Required tooling work | Status |
| --- | --- | --- | --- |
| SAL implied defaults | Unannotated mutable pointers were commonly emitted as output-only. SAL semantics instead default an unannotated pointer to `In|Out` with one element and an unannotated scalar to `In`. | Apply the defaults in the Clang-to-RDL parameter model. Do not add redundant `_In_` or `_Inout_` declarations to SDK headers. | Required; covered by the partition prototype work. |
| SAL capture shim missing from explicit partition scraping | `WsRequestReply`, `IWbemEventProviderSecurity::AccessCheck`, and other partition output lost direction, optionality, count/size relationships, and const-qualified pointer information already present in the headers. | Force-include the same SAL capture shim for explicit partition translation units that the normal scrape uses. | Fixed in the prototype; full regeneration is still needed to remeasure the remaining delta. |
| Native constness lost during RDL-to-winmd emission | Clang and RDL retain `*const`, but the final winmd can omit `ConstAttribute`, especially in output generated before the partition SAL fix. | Preserve native `const` through RDL compilation for every partition. | Open in the final winmd path; no header annotation should compensate for it. |
| MIDL parameter comments ignored | Generated headers can contain comments such as `/* [retval][out] */` even though no SAL `_Out_retval_` macro exists. | Tokenize the generated `.h` declaration and recover `[in]`, `[out]`, `[optional]`, `[retval]`, and `[iid_is]` from its MIDL comments. | Implemented in the prototype. The tool does not parse `.idl` files directly. |
| Existing `_NullNull_terminated_` not propagated | `GetVolumePathNamesForVolumeNameW` already has the correct SDK SAL contract, but the metadata result did not consistently contain `NullNullTerminated`. | Preserve the existing SAL annotation through Clang, RDL, and winmd emission. | Tooling work; no header change. |
| Architecture-dependent typedef roots omitted | `JET_API_PTR` was used by `JET_INSTANCE` and APIs but its architecture-dependent definition was not emitted, producing apparent width differences and unresolved type roots. | Preserve the typedef owner and merge its x86/x64 definitions into an architecture-neutral metadata representation. | Open architecture/ownership issue. |
| Alignment and packing conflated | The reference historically mishandled `CONTEXT`; x64/ARM64 require 16-byte alignment while x86 uses 4. | Read compiler alignment independently from packing and merge architecture-specific layout correctly. | Direct windows-rs behavior is more accurate and must not regress. |
| Compiler integer typing discarded | High-bit `IO_REPARSE_TAG_*` values can become signed or truncated when evaluated outside compiler rules. | Use Clang's evaluated type and C integer-conversion rules. | Direct windows-rs behavior is more accurate and must not regress. |
| COM pointer aliases collapse to `void*` | Macro-generated aliases such as `LPADRBOOK` can lose their referenced interface type, as seen in `OpenTnefStreamEx`. | Resolve macro-generated COM interface pointer typedefs and their owning declarations. | Open parser/type-ownership issue. |
| Cross-partition owner suppression | `D2D1CreateDevice` and the central `ID2D1Device` hierarchy disappeared even though `d2d1_1.h` was traversed and an earlier run emitted them. | Fix owner selection, duplicate suppression, and cross-partition reference resolution. | Open generator regression; not a header-list gap. |
| Classic NDR functions filtered or skipped | Many `NdrClientCall*` and related RPC functions are absent while similar variadic declarations emit correctly. | Correct cursor collection and RPC declaration filtering rather than annotating the SDK. | Open generator issue. |
| Public alias policy differs | windows-rs may emit `EnumProcesses` with entry point `K32EnumProcesses`, while win32metadata also exposes a flat `K32EnumProcesses` method. Similar differences occur for CLFS and legacy dbghelp aliases. | Decide whether both public names are required or whether entry-point equivalence is sufficient. | Team projection-policy decision. |
| Raw return values were over-normalized in the reference | `EnumWindows(FALSE)` can mean callback termination, and `LocalFree(NULL)` means success. | Preserve the native `BOOL`/`HLOCAL` result unless explicit metadata justifies transformation. | Direct windows-rs behavior is more accurate and must not regress. |
| Three-architecture worker pool can hang | Expanded parallel x86/x64/ARM64 generation completed workers without completing the merge or reporting a metadata diagnostic. | Fix worker coordination. Use `WIN32METADATA_SEQUENTIAL=1` as the deterministic validation workaround. | Workaround implemented; root cause remains open. |

The previously reported `WsRequestReply` parameter-name difference was a comparison
transcription issue, not an SDK or windows-rs fidelity problem.

## Original windows-rs scrape-surface omissions

The original windows-rs generator used one translation unit rooted by a `HEADERS`
array. win32metadata used 321 purpose-built translation units with family-specific
defines, include order, traversal settings, and namespaces. The first broad comparison
found 4,139 reference P/Invoke names absent from the monolithic scrape.

A literal comparison is much larger than the actionable gap:

- original windows-rs explicit roots: 365;
- unique direct includes across win32metadata partitions: 1,403;
- direct partition includes not named as windows-rs roots: 1,060.

The 1,060 figure is **not** a list of 1,060 missing headers. Many are reached through
`windows.h` or another root. The following families were confirmed missing because no
root reached their declarations.

### GDI+ - 620 initially missing P/Invokes

The `Gdiplus` partition uses:

```cpp
#include <ddraw.h>
#define GDIPVER 0x0110
#include <gdiplus.h>
```

The original windows-rs roots did not include `gdiplus.h`, so the closure never reached
the declarations in `gdiplusflat.h`, including `GdipCreateBitmapFromFile`.

### AllJoyn - 545 initially missing P/Invokes

The `AllJoyn` partition defines `QCC_OS_GROUP_WINDOWS` and directly includes:

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

These roots and their required define were absent from the monolithic windows-rs
translation unit.

### TAPI - 246 initially missing P/Invokes

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

It also defines `WIN32=1`. The original windows-rs root set did not include the TAPI
family.

### Peer-to-peer networking - 175 initially missing P/Invokes

The `P2p` partition directly includes:

```text
winsock2.h
p2p.h
drt.h
peerdist.h
```

The original windows-rs root set did not include `p2p.h`, `drt.h`, or `peerdist.h`.

### Families that were not confirmed root omissions

The initial missing-name grouping also highlighted COM, accessibility, clustering, and
WinInet. Their principal headers (`objidl.h`/`oaidl.h`, `oleacc.h`/
`uiautomationcore.h`, `clusapi.h`, and `wininet.h`) were already present in the
windows-rs root set. Their missing declarations therefore require API-specific
ownership, filtering, define, include-order, or alias analysis; they should not be
reported as simple missing-header fixes.

## Resolution adopted by the prototype

Adding individual headers to the monolithic list was not sufficient because some
families require specific defines, include ordering, traversal settings, exclusions,
and namespaces. The prototype instead consumes the same 321 win32metadata partition
translation units.

That change improved P/Invoke-name coverage from 72.56% to 98.06%. The remaining 354
missing names are primarily RPC/MIDL plumbing, canonical aliases, inline pseudo APIs,
legacy declarations, and generator ownership/suppression issues rather than another
large SDK root-header omission.

## Return annotation placement

Return-oriented custom annotations do not need to follow the function declarator.
Clang accepts the annotation before the return type and attaches it to the
`FunctionDecl`; windows-rs can then emit it on the metadata return parameter:

```cpp
_Win32_RAII_free_(CloseHandle)
_Win32_Invalid_handle_(INVALID_HANDLE_VALUE)
HANDLE WINAPI OpenThing(void);
```

This is the required style. Do not place `_Win32_..._` annotations between `WINAPI` and
the function name or after the closing parenthesis.

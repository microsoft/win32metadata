# Shift-Left Win32 Metadata Annotation Specification

## Status

This document defines how Windows SDK C/C++ headers and original IDL represent win32metadata semantics
for the C# and windows-rs metadata toolchains.

The main sections describe the annotations SDK authors write, where to place them,
and what they mean. Compiler encoding, diagnostics, and pipeline details are collected
at the end under [Clang parsing notes](#clang-parsing-notes).

Metadata is generated from Windows SDKs that ship. The SDK selected for a metadata
release defines its API surface. Headers and APIs absent from that SDK, including
deprecated or experimental surfaces removed from the SDK, are omitted from the
generated metadata. Consumers that require those surfaces must continue using metadata
generated from an older SDK.

Header changes are staged through the SDK ingestion patch system in
`generation/WinSDK/patches`. Each patch is temporary until the corresponding change
ships in the SDK.

## Non-negotiable rules

1. Metadata must not change the native ABI: no layout, calling convention, mangling,
   parameter count, native type, vtable, or exported symbol changes.
2. Ordinary SDK compilation sees every annotation macro as empty.
3. Metadata-only declarations are guarded by `WIN32METADATA`. Metadata-enabled
   parsing is C++ only; ordinary native C compilation with metadata off must remain
   unchanged.
4. Existing genuine SDK typedefs may be annotated. New API-specific pseudo handles
   such as `PRINTER_HANDLE` must not be introduced.
5. Resource producers carry cleanup and invalid-value metadata only on their return or
   output parameter. Plain `HANDLE` and handle typedefs do not imply automatic cleanup.
6. Header import-library annotations are authoritative. Import-library scanning remains
   the default.
7. Keep one cumulative patch per original SDK artifact, keyed by its SDK-relative
   path, such as `um/winhttp.h.patch` or `um/waasapi.idl.patch`. Patch shipped IDL
   before MIDL; do not patch its generated header or stack patches for one artifact.
8. Existing C/C++, SAL, MIDL, and compiler semantics are preferred over custom
   annotations. Do not add redundant `_In_` to scalars or `_Inout_` to unannotated
   pointers: those are the SAL semantic defaults. Capture existing native SDK/SAL/MIDL
   facts even when old metadata omitted them; review exact metadata differences rather
   than suppressing those facts to retain old omissions.
9. Logical equivalence to existing metadata is the target only where that metadata is
   correct. Preserve the native declaration and documented API behavior instead of
   reproducing an incorrect projection. Direct windows-rs fixes for native alignment,
   compiler-typed constants, `EnumWindows`, and `LocalFree` must not be regressed.
10. The selected shipped SDK is authoritative for API availability. Do not carry
    forward copied headers or declarations removed from that SDK. Metadata-only
    declarations may represent macros, inline helpers, constants, or exports that are
    part of the selected SDK, but they must not resurrect APIs absent from it.

## Attribute reference

The SDK annotation header supplies the public `_Win32_` macros below. Use those macros
alongside the native declaration and existing SAL; their compiler encoding is not part
of the authoring syntax. Unknown names, invalid arguments, duplicates where not
permitted, and annotations on unsupported targets are errors.

| Intent | Header syntax | Use and valid target |
| --- | --- | --- |
| Last error | `_Win32_SetLastError_` | Function that sets thread last error. Enables the projected last-error contract; ordinary SAL does not express it. |
| Import override | `_Win32_ImportLibrary_("name.dll", ...)` | Function. The DLL is required; an optional export name or ordinal overrides its imported entry point. |
| Minimum OS | `_Win32_SupportedOS_*_` | Function, method, record, enum, constant declaration, enum member, or typedef. Choose a fixed macro from the menu below. |
| Minimum OS region | `_Win32_SupportedOS_BEGIN_(os)` / `_Win32_SupportedOS_END_()` | Reviewed, file-local defaults with explicit/innermost precedence. Requires the reader resolution and acceptance coverage under [scoped defaults](#scoped-supportedos-defaults). |
| Exact result | `_Win32_PreserveResult_` | Function or method whose result must not be transformed or discarded by a projection. |
| Producer cleanup | `_Win32_RAIIFree_(CloseX, invalid...)` | Producer return or output parameter. Names its cleanup function and optional integral invalid values. |
| HANDLE cleanup shorthand | `_Win32_RAIIFree_Handle_(CloseX)` | Producer return or output parameter whose invalid set is exactly `-1, 0`. |
| Retained pointer | `_Win32_Retained_` | Pointer parameter retained by the API after the call. Follow the API's documented lifetime. |
| Reserved parameter | `_Win32_Reserved_` | Reserved pointer or scalar parameter. Records `[Reserved]` while preserving existing native types, direction SAL, and optionality. Valueless and non-repeatable. |
| Interior pointers | `_Win32_ContainsInteriorPointers_` | Caller-owned output/inout buffer parameter. Returned absolute pointers may borrow storage inside that same allocation; keep it alive and at a stable address until all pointer use or copying ends. Valueless and non-repeatable. |
| Native typedef identity | `_Win32_NativeTypedef_` | Genuine native `typedef` of a supported scalar or data pointer. Emits a nominal native-typedef wrapper without implying cleanup, invalid values, compatibility, or an OS floor. Valueless. |
| Compatible native typedef | `_Win32_AlsoUsableFor_(TYPE)` | Genuine native typedef, not a logical enum group. |
| Enum use | `_Win32_AssociatedEnum_(TYPE)` | Return, parameter, or field associated with a native enum or metadata-only group, including a later or cross-partition definition. Keep its native declaration type. |
| Loose constant association | `_Win32_AssociatedConstant_(NAME)` | Enum. Associates an existing global constant without duplicating or renaming it. Repeatable. |
| Logical enum | `_Win32_Enum_(name, storage, constants...)` | Metadata-only unscoped group of existing constants, using the specified native integral storage type of at most 64 bits. |
| Logical flags enum | `_Win32_FlagsEnum_(name, storage, constants...)` | The same grouping contract with flags semantics. |
| Projected return parameter | `_Win32_Retval_` | Output parameter in a C/C++-authored declaration, alongside direction SAL. Use native `[retval]` in IDL instead. |
| Original-IDL metadata | `cpp_quote("/* Win32Metadata: KIND ::Native::Target => CanonicalAnnotation(...) */")` | The same fact vocabulary and validation, with explicit native identity and no synthetic declaration. |

Use existing native syntax where it already expresses the contract:

| Intent | Existing syntax |
| --- | --- |
| Input/output/optional/reserved | SAL/MIDL direction, optionality, and reserved-parameter annotations. |
| Array count/capacity/byte size | Native array declarations and SAL such as `_In_reads_`, `_Out_writes_`, `_Inout_updates_`, `_Outptr_result_buffer_`, and their byte-count variants. |
| Double-NUL string | `_NullNull_terminated_`. |
| COM output pointer | `_COM_Outptr_` and its standard SAL variants. |
| Native constness | C/C++ `const`. |
| Native scoped enum | `enum class`; do not make a logical constant group scoped. |
| Native flags enum | Existing `[[clang::flag_enum]]`. Use `_Win32_FlagsEnum_` for metadata-only groups. |

For returned buffers, `_Outptr_result_buffer_(*count)` describes the pointee's
element count, not the single outer pointer slot. The C# consumer must continue
past that slot's `elementCount(1)` constraint to the usable postcondition count
and preserve the count parameter's index in the projected method. A usable
precondition capacity still takes precedence; unsupported counts must not be
invented. This parameter handling does not enable deferred field-array inference.

The genuine `typedef int GPFIDL_FLAGS` uses a matching global
`_Win32_Enum_(GPFIDL_FLAGS, int, GPFIDL_DEFAULT, GPFIDL_ALTNAME, GPFIDL_UNCPRINTER)`
group. Omit the redundant `AssociatedEnum` on `SHGetPathFromIDListEx::uOpts`: the
existing emitter naturally uses the declared enum type without an explicit request
for primitive storage plus an association. Its logical UInt32-to-Int32 correction
is intentional, with values 0, 1 and 2 unchanged; this is not a global promotion rule.
The logical `SERVICE_NOTIFY` group becomes `SERVICE_NOTIFY_FLAGS`, retaining all
ten members, order, raw values, UInt32 storage and flags semantics without renaming
native record aliases or constants. Keep these corrections visible in raw API diffs.

## Declaration placement

### Functions and methods

Place function metadata and metadata describing the return value before the complete
declaration, rather than between `WINAPI` and the function name.

```cpp
_Win32_SetLastError_
_Win32_ImportLibrary_("correct.dll")
BOOL WINAPI Example(void);
```

Return annotations use the same prefix position, preserving the calling-convention
declarator and matching normal SAL reading order.

Before adding an import override, check the selected SDK's import libraries and the
library-processing inputs. A library missing from that processing set is a discovery
fix, not a reason to annotate every affected API. Inspect its actual exported import
names and DLL mapping rather than inferring a DLL from the `.lib` filename. Record
the search evidence when no SDK import library supplies the mapping.

```cpp
_Win32_RAIIFree_Handle_(CloseHandle)
HANDLE WINAPI OpenThing(void);
```

### Parameters and fields

Parameter and field annotations precede the declaration type, alongside SAL. Keep distinct
annotations on separate source lines when that improves readability; keep cleanup and
invalid-value metadata together in `_Win32_RAIIFree_`.

```cpp
BOOL WINAPI CreateThing(
    _Out_ _Win32_RAIIFree_Handle_(CloseThing)
    HANDLE* result);
```

Buffer counts, capacities, and byte sizes use existing SAL rather than parallel Win32
metadata annotations:

```cpp
BOOL WINAPI ReadThings(
    _Out_writes_(count)
    THING* items,
    _In_ DWORD count);
```

`_Out_writes_bytes_(cbBuf)` describes a buffer capacity of `cbBuf` bytes.
`_Out_writes_bytes_to_(cbBuf, *pcbWritten)` additionally describes the initialized
byte extent returned in `*pcbWritten`. The optional-buffer spellings are
`_Out_writes_bytes_opt_` and `_Out_writes_bytes_to_opt_`, respectively. For an
illustrative API with a byte-count output:

```cpp
BOOL WINAPI ReadBytes(
    _Out_writes_bytes_to_(cbBuf, *pcbWritten) BYTE* buffer,
    _In_ DWORD cbBuf,
    _Out_ DWORD* pcbWritten);
```

`_Win32_ContainsInteriorPointers_` is valid only on a caller-owned buffer parameter,
before its type alongside ordinary output/inout SAL, not on the containing function
or the buffer's record type:

```cpp
BOOL WINAPI EnumPrinterDriversW(
    _In_opt_ LPWSTR pName,
    _In_opt_ LPWSTR pEnvironment,
    _In_ DWORD Level,
    _Out_writes_bytes_opt_(cbBuf) _Win32_ContainsInteriorPointers_
    LPBYTE pDriverInfo,
    _In_ DWORD cbBuf,
    _Out_ LPDWORD pcbNeeded,
    _Out_ LPDWORD pcReturned);
```

The selected SDK declares `pDriverInfo` with `_Out_writes_bytes_opt_(cbBuf)`;
the example preserves that SAL spelling. `pcReturned` counts `DRIVER_INFO` records,
not bytes. For [EnumPrinterDrivers](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers),
`pcbNeeded` receives bytes copied on success or the required byte size when the
buffer is too small. Neither output is renamed or given a different unit here;
the illustrative `ReadBytes` declaration above is not a replacement printer
signature.

Do not supply arguments or repeat this annotation. The parameter must point to
caller-owned output/inout buffer storage; verify the same-allocation relationship from
the API contract rather than inferring it from pointer fields.

### Records, interfaces, and enums

Attributes appear between the declaration keyword and name.

```cpp
struct _Win32_SupportedOS_10240_ DESCRIPTION {
    DWORD cbSize;
};
```

```cpp
enum class _Win32_SupportedOS_10240_ [[clang::flag_enum]] OPTION : unsigned long {
    OPTION_NONE = 0,
};
```

### Typedefs and callback aliases

Type metadata precedes the typedef.

Use the neutral identity marker when an existing native scalar or data-pointer
alias needs its own metadata identity but has no other annotation:

```cpp
_Win32_NativeTypedef_ typedef int BOOL;
_Win32_NativeTypedef_ typedef long HRESULT;
_Win32_NativeTypedef_ typedef void* HANDLE;
```

The canonical payload is `Win32Metadata.NativeTypedef`, with no parentheses,
textual values, or compiler arguments. It uses the existing `[NativeTypedef]`
wrapper projection and produces one `Value` field and one attribute per native
identity, including repeated annotations/redeclarations. Distinct aliases remain
distinct, and references retain their written typedef identity rather than an
erasing primitive remap. Traversal and exclusion rules still decide which native
declarations are emitted; the marker does not wrap unannotated typedefs.

Supported storage preserves the target's native scalar width and signedness and
every data-pointer level. Pointer-sized integral remaps must match that ABI.
Each pointer level must have the target's ordinary pointer width. Non-default
widths such as x64 `__ptr32` or x86 `__ptr64`, including beneath ordinary outer
pointers or intervening typedefs, fail with WMA001 before output is committed.
The reader does not erase the qualifier or substitute integer storage.
Direct fixed-width integer storage is not made into a pointer because OLD used
`IntPtr`. Genuine pointers to complete or incomplete native records are allowed;
record **values**, including incomplete-record value aliases, are not. Native
enum values, logical enum groups, callbacks/function pointers, arrays, references,
C++ `using` declarations, and unsupported scalar representations fail explicitly.
Do not invent an OS floor or a self-compatibility annotation merely to force a
provider, and do not infer native pointer storage from historical metadata.

When a retained invalid-value record was authored as `DECLARE_HANDLE`, the tooling
can preserve its existing `void* Value` only with independent, identity-bound
source proofs from both producers. The retained producer records its actual
`DECLARE_HANDLE` kind; the header producer records compiler-proven macro origin,
the native alias, and the exact generated pointer storage. These attached comments
are internal source provenance, not public WinMD attributes. Missing, stale,
conflicting, or ambiguous proofs fail closed; tag spelling, matching layout, and
empty emitted records do not prove equivalence. Other pointer representations are
not admitted by this rule, and complete native records remain intact.

For an IDL-owned typedef, use the existing selector-bound comment transport in
the original IDL, for example:

```idl
cpp_quote("/* Win32Metadata: type ::BSTR => NativeTypedef */")
```

The same target and storage validation applies to that comment. Ordinary SDK
consumers see an empty identity macro and unchanged native declarations.

Callback aliases continue to use their own existing projection, not the neutral
identity marker:

```cpp
_Win32_SupportedOS_10240_
typedef BOOL(WINAPI *PUBLIC_CALLBACK)(DWORD value);
```

### IDL-owned declarations

Patch the original SDK IDL, not its generated header. Ordinary C/C++ prefix macros
do not automatically survive MIDL. Use native IDL attributes for direction, counts,
and retval. Additional metadata uses standard `cpp_quote` emitting an owned comment,
outside parameter/field lists and inside the declaration's native conditional region.

For example, a field can carry its enum association:

```idl
typedef struct DESCRIPTION {
    long kind;
} DESCRIPTION;
cpp_quote("/* Win32Metadata: field ::DESCRIPTION::kind => AssociatedEnum(DESCRIPTION_KIND) */")
```

Native callable attributes and SAL stay unchanged:

```idl
HRESULT Read(
    [in] byte* input,
    [out, retval] long* result);
cpp_quote("/* Win32Metadata: method ::IReader::Read => PreserveResult */")
cpp_quote("/* Win32Metadata: parameter ::IReader::Read::input => Retained */")
```

The shared SAL bootstrap supplies native macro definitions when required; do not add an
annotation-header include to each API header or emit one through `cpp_quote`.
An original IDL preprocessing stream that does not already include SAL must
include `<sal.h>` before using the helpers. An IDL `import` does not establish
CPP macro visibility.

Do not use `[annotation]` as a metadata channel. It overrides native SAL, rejects
interface/enumerator positions and restricts nonlocal callables. Interface facts
instead bind the original native record:

```idl
cpp_quote("/* Win32Metadata: interface ::IWaaSAssessor => SupportedOSPlatform(\"windows10.0.15063\") */")
```

Keep native interface attributes, methods, and vtables unchanged. MIDL has additional
limitations for type-level annotations and nonlocal methods; see the
[verified transport limits](#native-idl-annotation-limits) before migrating another
IDL declaration kind.

A nonlocal method uses the same comment transport:

```idl
cpp_quote("/* Win32Metadata: method ::IEnumSTATPROPSTG::Skip => PreserveResult */")
```

Reuse existing quote regions where possible and preserve raw generated-header/RPC
differences if removing a carrier changes MIDL's implicit bookkeeping.

The method must already be declared, and the annotation must be valid on that
method. This preserves the native RPC contract and SAL without adding a MIDL SAL
override. A comment can also target a local method when its metadata must not
propagate to the generated proxy function:

```idl
cpp_quote("/* Win32Metadata: method ::IEnumSTATPROPSTG::Next => PreserveResult */")
```

Comments do not create symbols for any SDK consumer. Parameter comments append
the actual native parameter name to the method/function path. A method selector
does not annotate C-interface vtable fields; the ordinary scraper uses C++ interface
definitions. Native C/CINTERFACE consumption remains unchanged.

For an existing IDL enum, emit a metadata/Clang-guarded `#pragma clang attribute`
push/pop pair through `cpp_quote` around the original definition to apply
`__attribute__((flag_enum))`. This preserves anonymous enum identity and native
member names. Existing scalar typedefs can also back `_Win32_Enum_` or
`_Win32_FlagsEnum_` groups using their original constants; do not replace the
typedef or invent a scoped native enum.

For declarations authored in an included IDL fragment, patch that physical
fragment while keeping the generated output pinned to its unchanged generation
root. Preserve every native conditional declaration variant and admit the root's
actual MIDL input closure.

An omitted outer `Pack` is not by itself an ABI difference: packed child records
can already force byte alignment. Retire such an override only after comparing
the actual physical metadata and native size, alignment, and field offsets with
the same-MIDL control. Keep the explicit metadata packing difference in the
receipt; this is not a waiver for unrelated packing facts.

For a C/C++-authored declaration, combine direction SAL with `_Win32_Retval_`:

```cpp
virtual HRESULT STDMETHODCALLTYPE GetDesc(
    _Out_ _Win32_Retval_ DXGI_ADAPTER_DESC* pDesc) = 0;
```

## Supported OS macro menu

The annotation header defines only the versions currently present in
`supportedOS.rsp`. Each per-declaration macro expands to a fixed annotation payload:

```cpp
_Win32_SupportedOS_Windows2000_
_Win32_SupportedOS_WindowsXP_
_Win32_SupportedOS_WindowsVista_
_Win32_SupportedOS_Windows7_
_Win32_SupportedOS_Windows8_
_Win32_SupportedOS_Windows81_
_Win32_SupportedOS_10240_
_Win32_SupportedOS_10586_
_Win32_SupportedOS_14393_
_Win32_SupportedOS_15063_
_Win32_SupportedOS_16299_
_Win32_SupportedOS_17134_
_Win32_SupportedOS_17763_
_Win32_SupportedOS_18362_
_Win32_SupportedOS_19041_
_Win32_SupportedOS_Server2000_
_Win32_SupportedOS_Server2003_
_Win32_SupportedOS_Server2008_
_Win32_SupportedOS_Server2012_
_Win32_SupportedOS_Server2016_
```

New versions require a reviewed entry in the canonical version table and the
corresponding fixed macro, rather than a free-form version on individual declarations
or scopes. The scope lookup must share that table, not introduce a divergent
version menu.

Existing compiler/SAL facts remain the preferred source for attributes already expressed
by native syntax, including `noreturn`, architecture guards, alignment, native typedef
identity, bitfields, UUIDs, packing, parameter direction, optionality, and array sizes.
The custom annotations are fallbacks where existing syntax is absent or wrong.

## Scoped SupportedOS defaults

`_Win32_SupportedOS_BEGIN_(WindowsVista)` pushes an authored supported-OS default;
`_Win32_SupportedOS_END_()` pops it and restores the enclosing default. Nested scopes
override, rather than combine, defaults. An explicit per-declaration
`_Win32_SupportedOS_*_` annotation wins over every scoped default. The innermost
applicable scope wins otherwise, not the greatest version.

Implementations must provide end-to-end reader resolution before enabling scope
authoring. Scopes factor reviewed availability facts already being migrated; grouping
declarations must not infer new OS floors. The emitted annotation remains the existing
`SupportedOSPlatform` payload; no new emitted metadata schema or runtime attribute is
required.

#### Macro definition

The `_Win32_SupportedOS_BEGIN_` argument is a token from the existing per-declaration
menu, without the `_Win32_SupportedOS_` prefix or trailing underscore. This definition
illustrates the Vista and Windows7 entries of the shared canonical version table,
including their per-declaration spellings. The complete table must retain
the other reviewed entries above. `_WIN32META_ANNOTATION_` is the existing transport
helper.

```cpp
#define _WIN32META_OS_STRINGIFY_RAW(...) #__VA_ARGS__
#define _WIN32META_OS_STRINGIFY(...) _WIN32META_OS_STRINGIFY_RAW(__VA_ARGS__)
#define _WIN32META_OS_PRAGMA(...) _Pragma(_WIN32META_OS_STRINGIFY(__VA_ARGS__))

#define _WIN32META_OS_VERSION_WindowsVista "SupportedOSPlatform(\"windows6.0.6000\")"
#define _WIN32META_OS_VERSION_Windows7 "SupportedOSPlatform(\"windows6.1\")"
#define _WIN32META_OS_VERSION_RAW(os) _WIN32META_OS_VERSION_##os
#define _WIN32META_OS_VERSION(os) _WIN32META_OS_VERSION_RAW(os)

#define _Win32_SupportedOS_WindowsVista_ \
    _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(WindowsVista))
#define _Win32_SupportedOS_Windows7_ \
    _WIN32META_ANNOTATION_(_WIN32META_OS_VERSION(Windows7))

#if defined(WIN32METADATA) && defined(__clang__)
#define _Win32_SupportedOS_BEGIN_(os) \
    _WIN32META_OS_PRAGMA(clang attribute win32_os.push( \
        __attribute__((annotate(_WIN32META_OS_VERSION(os)))), \
        apply_to = any(function, record, enum, type_alias)))
#define _Win32_SupportedOS_END_() \
    _WIN32META_OS_PRAGMA(clang attribute win32_os.pop)
#else
#define _Win32_SupportedOS_BEGIN_(os)
#define _Win32_SupportedOS_END_()
#endif
```

The two-stage variadic stringification expands the payload before `_Pragma`
stringification; the two-stage token lookup also permits an OS token supplied by a
macro. Push and pop use the same `win32_os` pragma namespace. Both public scope macros
are empty outside Clang metadata compilation, including ordinary MSVC builds with or
without `WIN32METADATA`; the fixed declaration macros retain their existing no-op
behavior.

ClangSharp 21.1.8.4 with native Clang 21.1.8 supports this namespaced pragma transport.
The subject filter is exactly `any(function, record, enum, type_alias)`: `typedef` is
not a valid pragma matcher; `type_alias` covers genuine typedefs and callback typedefs.
C++ `using` aliases can reach the compiler AST, but the current reader does not support
`TypeAliasDecl`; the matcher alone does not establish end-to-end alias support.

#### Nesting and applicability

These APIs are fictional; comments describe the effective metadata after reader
resolution, not a change to native declarations:

```cpp
void ExampleBeforeScope(void); // No scoped default.

_Win32_SupportedOS_BEGIN_(WindowsVista)
void ExampleVista(void); // Vista default.

_Win32_SupportedOS_BEGIN_(Windows7)
void ExampleWindows7(void); // Windows7 default.
_Win32_SupportedOS_Windows8_
void ExampleExplicitWindows8(void); // Explicit Windows8 wins.
_Win32_SupportedOS_END_()

void ExampleVistaAgain(void); // Vista default restored.
_Win32_SupportedOS_END_()

void ExampleAfterScope(void); // No scoped default.
```

A default applies to eligible declarations lexically inside the scope in the same
physical header/expansion file and include instance. Eligible COM methods and nested
types receive the default independently when their declarations are within that scope.
An annotation on a record or interface alone does not imply inheritance by its members;
parameters and fields are not scope targets.

An included header does not inherit the including header's default. It may establish
its own balanced scopes. A declaration-producing macro is evaluated at its expansion
file and include instance, not merely the file where its replacement text was spelled.
Pair every `BEGIN` and `END` within the same file and include instance, balanced in
each active preprocessing path; an included file cannot pop its caller's scope.

#### Future acceptance coverage

These are implementation acceptance cases, not completed broad validation. The small
x64 transport/final-winmd fixture does not establish cross-architecture, full-SDK, or
PCH behavior.

| Case | Required result |
| --- | --- |
| Nesting and explicit precedence | Verify Vista -> Windows7 -> Vista -> no default, plus before/after absence and an explicit later-version annotation inside a scope. Also nest an earlier version inside a later one and use an earlier explicit value: lexical/explicit precedence must win, not greatest-version selection. |
| Pairing and diagnostics | Cover active/inactive conditional paths, unknown tokens, unmatched pops, unclosed scopes, cross-file pairing, invalid targets, and conflicting explicit annotations. Errors retain source locations. |
| Includes and expansions | Cover transitive and repeated includes, independently scoped included headers, and declaration-producing macros expanded in another file. No caller-default leakage or lost genuine explicit annotations. |
| Declaration shapes | Cover C and C++ functions, records, enums, genuine typedefs/callbacks, eligible nested types, and COM methods, without inferring member inheritance from a container annotation. Do not count AST-only C++ `using` coverage as reader support. |
| Native no-op behavior | Compile ordinary C/C++ with MSVC with and without `WIN32METADATA`, and Clang without it. Preserve native types, layouts, calling conventions, symbols, and vtables. |
| Final metadata | Read back effective annotations and required absence from final x86, x64, and ARM64 winmds, including COM methods and callbacks. Validate full-SDK and PCH/include reuse separately rather than extrapolating from a small fixture. |

The current C# pragma transport does not yet implement this default-resolution
contract. Use fixed per-declaration macros for migrations until these acceptance
cases pass; see [current Clang scope transport](#current-clang-scope-transport).

## Unsupported and deferred annotations

| Semantic | Decision |
| --- | --- |
| `IgnoreIfReturn` | Not included. No supported projection behavior requires it. |
| `FreeWith` | Not included. Allocated producer outputs use `RAIIFree`; cleanup is not attached to pointer typedefs. |
| `DoNotRelease` | Not included. Plain handles are borrowed unless a producer site carries ownership metadata. |
| `Agile` | Intentionally jettisoned. Existing annotations asserted that selected non-WinRT COM interfaces were always thread-safe, but that guarantee was repeatedly violated. COM does not have WinRT's exclusive/agile interface contract, so no `_Win32_Agile_` replacement is defined. The legacy Direct2D, DirectWrite, DXGI, and `IRestrictedErrorInfo` emitter rules are removed rather than migrated. |
| custom COM out-pointer annotation | Not included. Use `_COM_Outptr_`, its standard variants, IID/PPV conventions, or explicit existing SAL. |
| `NotNullTerminated` | Not included. Declarations that use a string typedef for non-string data require an appropriately typed pointer plus ordinary SAL count/byte-count annotations. |
| `NativeArrayInfo` and `MemorySize` fallbacks | Not included. SAL expresses buffer counts, capacities, and byte sizes; the consumer must preserve that SAL instead of introducing duplicate metadata annotations. |
| `NativeArrayInfo.CountFieldName` | Deferred until field-array projection behavior is defined. |
| `NativeInheritance` | Not included for `MONITORINFOEXW`; use the native C++ base and equivalent C layout prefix. Add this vocabulary only if a separate, proven source gap requires it. |
| `ProjectAs` | Not included. Preserve native typedef identity and use `AssociatedEnum` for the proven enum-specific use-site relationship. |
| `StructSizeField` | Deferred. No equivalent SAL annotation exists; add it only with concrete projection behavior and tests. |
| `NativeEncoding` | Not included. Declare guarded constants with their real `char`/`wchar_t` type. |
| `Ansi` / `Unicode` | Not included. No projection behavior in scope requires these attributes. |
| `CanonicalName` | Not a header annotation. Resolve the public callback name from the native typedef-alias graph. |
| `ReducePointerLevel` | Not a header annotation. Correct callback/pointer parsing or use the correct typedef in a guarded metadata declaration. |
| `StaticLibrary` | Deferred until a canonical use and functional consumer behavior are defined. |

## Enum and constant migration

Group existing SDK constants into metadata-only enums. Keep the original constants
and native function/field types unchanged:

```cpp
#define MODE_A 1
#define MODE_B 2

_Win32_Enum_(MODE, DWORD, MODE_A, MODE_B);

void SetMode(_Win32_AssociatedEnum_(MODE) DWORD mode);
```

The flags form uses the same names-and-values mechanism:

```cpp
_Win32_FlagsEnum_(VERIFIER_ENUM_RESOURCE_FLAGS, ULONG,
    AVRF_ENUM_RESOURCES_FLAGS_DONT_RESOLVE_TRACES,
    AVRF_ENUM_RESOURCES_FLAGS_SUSPEND);
```

Ordinary SDK consumers see neither an enum nor a typedef/new symbol. Metadata
generation produces an unscoped enum with the listed names, compiled values, and
specified storage type. Signed/high-bit bit patterns are preserved at that storage
width. Native `enum class` declarations remain scoped.

Rare historical metadata labels may differ from native constant names. Use the same
existing native values rather than inventing SDK aliases or copying numeric values.
The current explicit-label encoding is described in
[Logical enum encoding](#logical-enum-encoding). An existing reviewed zero/none member
may supply literal `0`; that does not introduce a new native SDK constant.

An associated use can precede the native constants. Keep the original constant
block in place, and put the group declaration after it:

```cpp
void SetMode(_Win32_AssociatedEnum_(MODE) DWORD mode);

#define MODE_A 1
#define MODE_B 2
_Win32_Enum_(MODE, DWORD, MODE_A, MODE_B);
```

The use and complete group may be in different headers or partitions. An existing
traversed forward declaration still projects its compiler-bound merged group even when
the contributing header is outside the partition's traversal list. Unrelated
same-named typedefs do not establish a group; excluded or entirely untraversed
groups remain unprojected.

A group whose constants have multiple original-header owners may repeat
`_Win32_Enum_` or `_Win32_FlagsEnum_` on the same native typedef, with the same
storage and kind. Each owner lists its own existing constants after their native
definitions. The original Clang declaration graph combines contributions in one
translation unit; the emitter combines the generated `.header-types.cs` contributions
by qualified metadata identity after namespace assignment. Keep those producer
filenames when staging sources for emission.

When partitions initially emit the same group in different namespaces, use the
existing global `--requiredNamespaceForName` organization to preserve its established
physical FullName before merging. Check the combined owning-partition outputs;
individually valid fragments must not leave extra wrong-namespace copies.

The complete group is the union of those source-owned contributions, not an empty
typedef or a replacement native enum. Repeated members must have identical compiled
values after conversion to the group's storage. Conflicting values, storage, flags,
or non-repeatable annotations are errors. Ordinary native enums and legacy enum
definitions are not group contributions and are never merged this way. Do not add a
forward typedef or include an unrelated API surface merely to make an association
parse. Final composition must resolve each association to exactly one emitted enum.

Rules:

- Choose a logical group's integral storage from the native API uses it describes,
  rather than mechanically reproducing a sidecar or inferring storage from one
  constant literal. Keep native enum and use-site declarations unchanged.
- Do not `push_macro`, `undef`, copy values, or change native signatures for grouping.
- Use `AssociatedEnum` for the use-site relationship while retaining the native type.
- Preserve complete existing constant names as unscoped enum members so generated
  consuming code does not require scoped-name changes.
- Keep loose constants such as `SERVICE_NO_CHANGE` global and use repeatable
  `AssociatedConstant` annotations on each related enum. Do not duplicate the same
  unscoped enumerator name in multiple enums.
- Use `enum class` only when the SDK declaration is already scoped or a new native API
  intentionally defines scoped semantics; do not use it merely to wrap constants.
- Other metadata-only constants use guarded annotated `constexpr`/`const` declarations while
  preserving the ordinary macro.

### Enum associations and storage compatibility

An `AssociatedEnum` annotation preserves the relationship to a particular enum;
it does not require that enum's storage to equal every associated native type.
Move each existing association to the same return, parameter, or field and retain
its resolved enum identity. A lost or incorrectly retargeted association is a
migration defect, not an intentional enum-storage correction.

Choose metadata enum storage from the consuming API contracts. Correct a clearly
single-use legacy storage error when its values and native use support the change.
For shared enums, select the most appropriate representation across their uses
without changing native declarations to make every association match. Preserve
narrow structure fields and pointer element widths; an advisory association must
not silently become an ABI-changing direct enum substitution. Signedness and width
differences can be intentional, as documented in
[#2371](https://github.com/microsoft/win32metadata/issues/2371).

An enum-storage correction is a concrete metadata compatibility change to record
and cover with regression tests. It is not a reason to block an otherwise correct
header association, restore an API-specific sidecar, or retype the native enum.

## HANDLE ownership

Handle typedefs do not carry cleanup ownership or automatic-close behavior. APIs that
natively use `HANDLE` remain `HANDLE`, and ownership is attached only to a producer
return or output parameter:

```cpp
BOOL WINAPI OpenPrinterW(
    _In_ LPWSTR name,
    _Out_ _Win32_RAIIFree_Handle_(ClosePrinter)
    HANDLE* printer);
```

Do not create `PRINTER_HANDLE`, `HEAP_HANDLE`, or similar metadata-only pseudo types.
Absence of `RAIIFree` means borrowed. `GetProcessHeap`, for example, requires no custom
annotation because its returned `HANDLE` is not automatically closed.

The first argument names a cleanup function declared in the same native translation
unit. Its prototype may follow the producer; do not copy or reorder API declarations.
Optional remaining arguments are the API's invalid values:

```cpp
_Win32_RAIIFree_(SysFreeString)
_Win32_RAIIFree_Handle_(CloseHandle)
_Win32_RAIIFree_(WinHttpCloseHandle, 0)
```

The cleanup name must resolve to one actual native function declaration, not an
integer, function-pointer variable, or ambiguous overload. Unresolved cleanup names
are errors even on excluded declarations. Input handle types do not infer cleanup.
Invalid values are API-specific rather than a fixed global set. Supply compile-time
integral expressions such as `-1` and `0`, not pointer-cast `INVALID_HANDLE_VALUE`.
Nonintegral, unresolved, and nonconstant values are errors. The shorthand is only for
the exact HANDLE contract `-1, 0`; null-only handles retain `_Win32_RAIIFree_(CloseX, 0)`.

A unary cleanup may accept the address of the produced pointer.
`GdipNewPrivateFontCollection::fontCollection` can name
`GdipDeletePrivateFontCollection`; its sole `GpFontCollection**` parameter receives
the address of the produced `GpFontCollection*`. The cleanup's native signature
determines the required indirection.

Consumer/freeing APIs such as `LocalFree` retain their raw native signature. Do not use
generic invalid-handle success logic for them: `LocalFree` returns `NULL` on success and
the still-valid input handle on failure.

## Import-library precedence

1. `_Win32_ImportLibrary_` on the declaration.
2. Import-library scanning.
3. Configured default.

This permits headers to correct missing or incorrect `.lib` information without
duplicating the complete scan-derived mapping.

An optional second argument overrides only the imported entry point:

```cpp
_Win32_ImportLibrary_("example.dll", "ActualExport") int PublicName(void);
_Win32_ImportLibrary_("example.dll", 660) int OrdinalOnly(void);
```

An ordinal must be an integral constant from 1 through 65535. Omitting the second
argument preserves the normal imported entry point. The override changes the DLL or
entry point, not the native function name or signature.

## Reviewed semantic decisions

### Caller-owned buffers containing interior pointers

This use-site contract addresses
[microsoft/CsWin32#1839](https://github.com/microsoft/CsWin32/issues/1839).
It is not a blanket assertion that a structure has pointer fields. The same record
may be used by APIs with different storage and ownership rules.

The caller must keep the containing allocation alive and continuously at the address
used by native code, from the call that produces the pointers until the last
dereference or copy of their pointed-to data. Pinning only for the native call or
using `GC.KeepAlive` is insufficient for movable managed buffers. Copying a native
record copies its addresses, not its pointees; moving the bytes and re-pinning later
does not repair those addresses. Stable storage can be caller-pinned, stack, or
unmanaged storage, subject to the API's lifetime and alignment requirements.

`ContainsInteriorPointers` does not mean that native code retains the input buffer
(`Retained`), that an allocation is owned or needs cleanup (`RAIIFree`), or that data
is offset-based/self-relative. A self-relative security descriptor alone is not a
reason to annotate a buffer. A returned absolute pointer into a containing allocation
is, even when its pointee is itself self-relative.

The annotation is conservative across supported information levels/discriminators:
at least one supported result layout may contain such pointers. It neither asserts
that every result or every pointer field has that provenance nor describes record
types, counts, byte extents, success conditions, encodings, alignment, or bounds.
Keep existing SAL and consult each API's documentation for these details. In
particular, `EnumServicesStatusEx.pcbBytesNeeded` reports space needed for remaining
entries, not a universal success-time valid byte extent. Projection consumers should
preserve the native pointer parameter and suppress convenience span/ref overloads
that pin movable storage only during the call. No custom stable-span type is required.

#### Reviewed caller-owned buffer examples

`A/W` below means both declarations. Only the specified buffer parameters are
annotated; their record types, input parameters, size outputs, and return values are
not. The printer function/record documentation and `winspool.h`, the token
documentation and `securitybaseapi.h`/`winnt.h`, and the package documentation and
`appmodel.h` define the output layouts. Parameter names below use the selected SDK
header spellings, even where the documentation uses a different name.

| API | Parameter | Contract basis |
| --- | --- | --- |
| [AddJobA/W](https://learn.microsoft.com/windows/win32/printdocs/addjob) | `pData` | `ADDJOB_INFO_1` and its pointed-to path string share the supplied buffer. |
| [EnumFormsA/W](https://learn.microsoft.com/windows/win32/printdocs/enumforms), [GetFormA/W](https://learn.microsoft.com/windows/win32/printdocs/getform) | `pForm` | Returned `FORM_INFO_1/2` records include name/string pointers; the caller supplies the result storage. No separately owned string allocation is returned. |
| [EnumJobsA/W](https://learn.microsoft.com/windows/win32/printdocs/enumjobs), [GetJobA/W](https://learn.microsoft.com/windows/win32/printdocs/getjob) | `pJob` | The buffer includes `JOB_INFO` records and the strings/data their members point to. Scalar-only job information levels remain conservatively covered. |
| [EnumMonitorsA/W](https://learn.microsoft.com/windows/win32/printdocs/enummonitors) | `pMonitor` | The buffer includes `MONITOR_INFO_1/2` records and their strings. Documentation calls this parameter `pMonitors`. |
| [EnumPortsA/W](https://learn.microsoft.com/windows/win32/printdocs/enumports) | `pPort` | The buffer includes `PORT_INFO_1/2` records and their strings. Documentation calls this parameter `pPorts`. |
| [EnumPrinterDataExA/W](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdataex) | `pEnumValues` | Returned [PRINTER_ENUM_VALUES](https://learn.microsoft.com/windows/win32/printdocs/printer-enum-values) records point to retrieved names and value data in the result storage. |
| [EnumPrinterDriversA/W](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers), [GetPrinterDriverA/W](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver), [GetPrinterDriver2W](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver2) | `pDriverInfo` | The buffer includes `DRIVER_INFO` records and their strings/other pointed-to data. |
| [EnumPrintersA/W](https://learn.microsoft.com/windows/win32/printdocs/enumprinters) | `pPrinterEnum` | The buffer includes `PRINTER_INFO` records and pointed-to strings/data. |
| [GetPrinterA/W](https://learn.microsoft.com/windows/win32/printdocs/getprinter) | `pPrinter` | The buffer includes the selected `PRINTER_INFO` record and pointed-to strings/data, including absolute pointers to DEVMODE/security-descriptor storage where present. |
| [EnumPrintProcessorDatatypesA/W](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessordatatypes) | `pDatatypes` | The buffer includes `DATATYPES_INFO_1` records and their strings. |
| [EnumPrintProcessorsA/W](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessors) | `pPrintProcessorInfo` | The buffer includes `PRINTPROCESSOR_INFO_1` records and their strings. |
| [EnumServicesStatusExA/W](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-enumservicesstatusexw) | `lpServices` | The documentation explicitly includes `ENUM_SERVICE_STATUS_PROCESS` records and the strings their members point to in this buffer. |
| [GetTokenInformation](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) | `TokenInformation` | Information-class-dependent records such as `TOKEN_USER`, `TOKEN_GROUPS`, `TOKEN_OWNER`, and `TOKEN_DEFAULT_DACL` point to SID/ACL storage in the supplied result buffer. Scalar-only classes remain conservatively covered. |
| [GetCurrentPackageId](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackageid), [GetPackageId](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackageid), [PackageIdFromFullName](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-packageidfromfullname) | `buffer` | The buffer contains a `PACKAGE_ID` and its pointed-to identity strings, rather than an independent allocation. |
| [GetCurrentPackageInfo](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackageinfo), [GetCurrentPackageInfo2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getcurrentpackageinfo2), [GetPackageInfo](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackageinfo), [GetPackageInfo2](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackageinfo2) | `buffer` | The buffer contains `PACKAGE_INFO` records with path/identity strings and nested `PACKAGE_ID` string pointers. |
| [GetPackageApplicationIds](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackageapplicationids) | `buffer` | This single byte buffer contains the array of app-ID string pointers and the strings they reference; `count` counts entries in that pointer table. It has no separate pointer-array output parameter. |

#### Exclusions and relationship limitations

[GetPackagesByPackageFamily](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-getpackagesbypackagefamily)
and [FindPackagesByPackageFamily](https://learn.microsoft.com/windows/win32/api/appmodel/nf-appmodel-findpackagesbypackagefamily)
return `packageFullNames` as a separate caller-supplied pointer array whose elements
point into the companion `buffer` of UTF-16 characters. The string buffer itself does
not contain pointers, and the pointer array does not point into its own allocation.
Annotating either parameter with this single-buffer marker would be false. A future
cross-parameter provenance relationship must identify both the pointer-bearing output
and its borrowed-storage parameter so consumers can suppress unsafe projections of the
companion buffer too. These APIs remain an explicitly uncovered projection hazard,
not a declaration that their current convenience overloads are safe.

Do not annotate flat package full-name/family-name/path outputs, the independent
string outputs of `PackageNameAndPublisherIdFromFamilyName`, or package dependency
outputs allocated with `HeapAlloc` merely because the API is in `appmodel.h`.
`PackageFullNameFromId`/`PackageFamilyNameFromId` consume pointer-bearing input records
but return flat strings. Separately owned allocations and offset-only data require
their own contracts, not this marker.

`GetPackageInfo3` and numbered `FindPackagesByPackageFamily` variants are not declared
in the selected headers; do not invent annotations or declarations for them.
[GetCurrentPackageInfo3](https://learn.microsoft.com/windows/win32/appxpkg/appmodel/nf-appmodel-getcurrentpackageinfo3)
is not annotated: its currently declared discriminator is
`PackageInfo3Type_PackageInfoGeneration`, and its public documentation mixes a
generation-ID description with `PACKAGE_INFO` array wording. A clarified, supported
pointer-bearing result contract is required before adding a sidecar.

`GetPrinterDriver2A` is declared but documented to always return
`ERROR_NOT_SUPPORTED`, so only `GetPrinterDriver2W` has an annotated output contract.
Flat printer directory/name/registry-data outputs, `EnumPrinterKey` MULTI_SZ output,
separately allocated printer notification data, and pointer-bearing printer input
records are not blanket-annotated. This inventory is reviewed coverage, not exhaustive
discovery of every Win32 interior-pointer-producing API.

### COM outputs

Use standard `_COM_Outptr_` SAL variants where present. Eligible IID/PPV pairs may be
recognized by convention. Do not introduce a custom Win32 COM-out-pointer annotation.

### String termination

- `WAVEHDR::lpData` is binary data and should not use a string typedef. In the
  `WIN32METADATA` declaration, spell it as an appropriately typed character/byte
  pointer and preserve its byte-count relationship with SAL.
- `GetVolumePathNamesForVolumeNameW` already carries `_NullNull_terminated_`; preserve
  that contract without adding a custom annotation or modifying the SDK declaration.
- Classify the remaining NuGet `NotNullTerminated` occurrences as incorrect string
  typedefs, counted buffers, or double-NUL strings. Correct the declaration type or SAL
  rather than preserving `NotNullTerminated` as a custom annotation.

### Return and success behavior

- `RetVal` identifies the output parameter selected as the friendly projected return.
- `Retained` identifies a pointer that the API may use after the function returns. The
  caller follows the API documentation to determine the end of that lifetime.
- `_Win32_PreserveResult_` means that a projection must not transform or discard the
  exact result. It covers APIs represented in existing metadata by
  `CanReturnErrorsAsSuccess` or `CanReturnMultipleSuccessValues`.
  `_Success_` and `_Return_type_success_` remain useful static-analysis predicates but
  do not express this projection rule.
- `EnumWindows` must not carry `SupportsLastError`; preserve its raw `BOOL` result
  because `FALSE` can mean intentional callback termination.

### Struct size fields

No SAL annotation specifically identifies a field as the structure's initialization
size. Defer a source annotation until a projection defines concrete initializer
behavior, including versioned structures that intentionally accept an older size.

### Obsolete fields

Use standard, metadata-only guarded C++ `[[deprecated]]` syntax rather than a custom
Win32 annotation. `IMAGE_OPTIONAL_HEADER32::LoaderFlags` and the 64-bit equivalent are
the canonical examples.

### Enums and associated constants

`ENUM_SERVICE_TYPE`, `SERVICE_START_TYPE`, and `SERVICE_ERROR` are metadata-only
unscoped logical groups because the SDK exposes `DWORD` parameters and macro constants. Keep
`SERVICE_NO_CHANGE` as a global constant and apply
`_Win32_AssociatedConstant_(SERVICE_NO_CHANGE)` to each related enum. This preserves
existing projected names without introducing duplicate unscoped enumerators.

## Reviewed API-specific conclusions

| Example | Authoring guidance |
| --- | --- |
| `CoGetClassObject` | Add only the `CLSCTX` association. `CLSCTX` already exists in `shared/WTypesbase.h`; use existing COM output SAL. |
| `AddFontResourceExW` | Use a metadata-only constant group and annotate the native-typed flags use. |
| `ADsBuildVarArrayInt` | No redundant `_In_`/`_Inout_` header edits; use SAL semantic defaults. |
| `JetTerm` | Preserve `JET_API_PTR` as an architecture-neutral pointer-sized type. A typed `JET_ERR` definition is acceptable only if it remains ABI-compatible with `int`; no `ProjectAs` annotation is needed. |
| `D2D1CreateDevice` | No declaration punctuation or return-type annotation gap was established. |
| `K32EnumProcesses` | Preserve the existing team naming-policy decision rather than forcing metadata parity. |
| `NdrClientCall2` | No redundant header annotations; pointer direction follows native/SAL semantics. |
| `IDXGIFactory1::EnumAdapters1` | Add `_Win32_PreserveResult_` so `DXGI_ERROR_NOT_FOUND` remains observable during normal enumeration. |
| `DoDragDrop` | Add `_Win32_PreserveResult_` so distinct successful outcomes are not collapsed. |
| `HttpReceiveHttpRequest` | Keep `Retained`; the API uses the pointer beyond the call. |
| `RasEnumConnectionsW` | Preserve both element-count and byte-capacity relationships; they are distinct. |
| `CERT_INFO::rgExtension` | Defer `CountFieldName` until a field-array projection is defined. |
| `UCharIterator::move` | Do not change the pointer level or add direction SAL merely to compensate for a parser bug. |
| `MONITORINFOEXW` | Existing C++ inheritance/C layout prefix is sufficient; do not add `NativeInheritance`. |

## Clang parsing notes

These notes describe compiler encoding and metadata-tool implementation. They do not
add public annotation syntax or change the authoring contract above.

### Annotation encoding and diagnostic policy

The shared header, `RecompiledIdlHeaders/shared/win32metadata_annotations.h`, uses
an ordinary Clang `annotate` attribute and does not set compiler diagnostic policy:

```cpp
#if defined(WIN32METADATA) && defined(__clang__)
#ifndef _WIN32META_ANNOTATION_
#define _WIN32META_ANNOTATION_(...) \
    __attribute__((annotate("Win32Metadata." __VA_ARGS__)))
#endif
#else
#define _WIN32META_ANNOTATION_(...)
#endif
```

With `--config parse-win32-annotations`, the C# scraper predefines this private
transport macro in its Clang arguments, adding diagnostic push/error/pop around the
same attribute. These diagnostic pragmas live in the tool, not the SDK header.
Other consumers can use the plain header definition or supply their own diagnostic
policy.

The tool-owned guard makes an ignored metadata attribute an error instead of silently
losing it. For example, an attribute placed before `struct` rather than after it can
leave no annotation in the AST for the reader to validate. Existing SDK/SAL headers
also produce legitimate ignored-attribute warnings, so the tool must not globally
promote that warning to an error. Its guard limits the stricter policy to the metadata
attribute and restores the surrounding diagnostic state immediately. Clang performs
this check in the original parse, including through macro aliases; there is no
diagnostic-text filter or source-token parser. Annotation parsing rejects Clang's
global `-w` option because it suppresses even this check; use specific `-Wno-` options
for native warnings instead. This policy is not part of the public macros' spelling
or meaning. Native lexical availability scope still uses Clang's attribute push/pop,
independently of diagnostic policy.

The `Win32Metadata.` owner prefix lets the reader reject unknown owned annotations
from AST attributes without inspecting macro definitions. Prefix placement is the
recommended authoring style, but semantically equivalent placements accepted by Clang
are not rejected by a source-token parser. Function attributes describing a return
value attach to the `FunctionDecl` and are emitted on the metadata return parameter;
parameter and field annotations attach to their own declarations.

### First-parse expression arguments

Clang expands macros normally and attaches expression children to `AnnotateAttr` in
the original translation unit. Read those children rather than stringifying expressions
and reparsing an injected translation unit. Namespaces, class constants, aliases, and
declaration-time macro definitions are resolved by that first parse.

The lifecycle definitions are:

```cpp
#define _Win32_RAIIFree_(cleanup, ...) \
    _WIN32META_ANNOTATION_("RAIIFree", "Win32Metadata.FunctionDecl:" _WIN32META_EXPAND_STRINGIFY_(cleanup), ##__VA_ARGS__)
#define _Win32_RAIIFree_Handle_(cleanup) \
    _Win32_RAIIFree_(cleanup, -1, 0)
```

The internal tagged cleanup name preserves declaration-time macro expansion without
requiring the cleanup prototype before the producer or a constant imported function
address. After walking the complete original translation unit, the reader binds it
to one actual native `FunctionDecl` in the annotation's scope. Canonical redeclarations
share an identity; unknown names, non-functions, ambiguous lookups, and untagged string
arguments fail. The earlier typed `sizeof` transport remains readable. A raw
`RAIIFree(CloseX, ...)` annotation string is not a supported bypass.
Invalid values remain integral expression arguments from the first Clang parse;
pointer-cast `INVALID_HANDLE_VALUE` is not a valid annotation constant. Emit one
`RAIIFreeAttribute` and one `InvalidHandleValueAttribute` per supplied value.

`AssociatedEnum` uses an internal tagged, macro-expanded name so the use does not
require a visible enum declaration during native parsing. Complete-translation-unit
lookup preserves native enum/group identity, including aliases and remappings, and
rejects visible non-enums or ambiguous native names. An unavailable unqualified name
is retained for cross-partition or retained enum composition, where it must resolve
to exactly one emitted enum after namespace assignment, remaps and enum additions.
Missing or ambiguous final definitions fail with WMA003. The previous compiler-typed
transport remains readable; untagged strings are not an alternate transport.
`__typefix` is analyzer metadata, not a projection contract. DLL/export strings
and integral ordinals are also read from the original argument children. An import
override is written to `ImplMap.ImportName` as the export name or `#ordinal`.

### Logical enum encoding

The shared group definitions are:

```cpp
#if defined(WIN32METADATA) && defined(__clang__)
#define _Win32_Enum_(name, storage, ...) \
    typedef _WIN32META_ANNOTATION_("Enum(" #__VA_ARGS__ ")", __VA_ARGS__) storage name
#define _Win32_FlagsEnum_(name, storage, ...) \
    typedef _WIN32META_ANNOTATION_("FlagsEnum(" #__VA_ARGS__ ")", __VA_ARGS__) storage name
#else
#define _Win32_Enum_(name, storage, ...)
#define _Win32_FlagsEnum_(name, storage, ...)
#endif
```

The carrier is a `TypedefDecl`: its underlying type supplies storage, its `AnnotateAttr`
supplies member labels and the flags/non-flags marker, and expression children supply
the compiled values. Labels are explicit annotation data; consumers do not parse macro
definitions or reevaluate C/C++ expressions. Merge redeclarations by native identity so
an early unannotated storage typedef and its later group declaration emit one enum.

Rare historical metadata labels use the same encoding explicitly:

```cpp
#ifdef WIN32METADATA
typedef _WIN32META_ANNOTATION_(
    "Enum(HISTORICAL_A, HISTORICAL_B)", NATIVE_A, NATIVE_B) DWORD MODE;
#endif
```

An existing reviewed zero/none member may similarly supply literal `0`. Do not create
native SDK aliases to implement metadata labels.

### Current Clang scope transport

The existing C# implementation reads the attributes attached by Clang's
`attribute push`/`pop` transport on functions, records, enums, and type aliases.
Clang scopes accumulate attributes, include nested headers, and permit cross-include
push/pop. Identical floors are deduplicated, including on redeclarations; distinct
floors on a declaration or its redeclarations are errors. A direct annotation on a
record/interface alone does not annotate its members.

Those transport semantics do not implement the file-local, explicit/innermost
precedence required by [scoped defaults](#scoped-supportedos-defaults). Reader
resolution and its acceptance coverage remain a tooling follow-up; the existing
transport tests must not be counted as qualification of that contract.

### Original-IDL preparation

Original-IDL facts use one block comment per fact:

```text
/* Win32Metadata: KIND ::Native::Target => CanonicalAnnotation(arguments) */
```

Use standard `cpp_quote` with quotes/backslashes escaped for its ordinary string
literal. MIDL removes ordinary IDL source comments; quoted comments survive.
The reader examines actual Clang comment tokens, not marker text inside strings.
No special MIDL attribute, annotated forward typedef, copied native signature,
or compiler-expression carrier is required.

Selectors are `interface`/`record`, `method`, `function`, `return`, `parameter`,
`field`, `type`, `enum`, `enumerator`, and `constant`. Targets are absolute native
identifiers separated by `::`. Parameters append their native name to the callable.
Use actual emitted `get_`/`put_` names for properties and free-function names for
non-object RPC interfaces. Record aliases resolve their native fields, including
anonymous-member injection such as `::PROPVARIANT::vt`; a macro-erased inner tag
is not an identity. Distinct typedef aliases remain distinct.

The same canonical fact parser, validation, native cleanup resolution, projection
and final emitter serve macros and comments. `return` accepts RAIIFree and
AssociatedEnum. A `type` selector can carry valueless `NativeTypedef` for a
supported native scalar/data-pointer typedef; it does not turn a record or enum
into a typedef wrapper. References use native lookup from the bound declaration.
AssociatedEnum admits real enum declarations and already-compiled logical groups,
including exact native `__MIDL_*` tags. AlsoUsableFor and AssociatedConstant must
resolve actual native types/constants. ImportLibrary uses literal quoted strings.
Comment RAIIFree invalids are signed decimal Int64 literals, preserving their order
and sign; symbols, hexadecimal/suffixed literals, casts and expressions fail.
Existing native C/C++ macros retain compiler-evaluated arguments and Enum/FlagsEnum
groups keep their compiled-value transport.

The existing annotation option enables this path. Clang's detailed preprocessing
record supplies included files and skipped ranges. Disabled branches do not apply;
active comments in directives/macros, malformed or unknown payloads, missing names,
and ambiguous native targets/references produce WMA001. Template helper bodies
excluded from ordinary projection do not create false method overloads; two real
non-template overloads remain ambiguous. Adjacent native direction/retval comment
blocks remain readable, without treating arbitrary comments as native direction.

Metadata-only C/C++ enum grouping invocations must be excluded from `MIDL_PASS`,
including their trailing semicolon. An empty `_Win32_Enum_` expansion leaves a
naked semicolon that MIDL rejects. The canonical WinError patch guards the
complete group without changing its constants or ordinary C/C++ behavior.

Pin the helper and original import/preprocessor closure alongside the SDK source IDL,
and explicitly pass the necessary preprocessor defines/includes when MIDL `cpp_opt`
overrides normal forwarding. Preserve ordinary MIDL diagnostics and native C/C++
declarations.

Preserve native `[retval]` and read MIDL's emitted parameter comment. The selected
native SDK SAL has no `_Out_retval_`/`_COM_Outptr_retval_`; local conversion uses
standard `_Out_`/`_COM_Outptr_`. Remote interface methods retain `/sal`-generated
RPC direction/count annotations without synthetic `[annotation]` overrides.
Explicit native SAL and local-method count conversion remain intact. Native
retval, SAL and an explicit metadata RetVal converge once; duplicate authored
metadata facts still fail.

#### Native IDL annotation limits

Actual selected-SDK MIDL output distinguishes the following cases; successful
C/C++ header annotation tests alone do not establish IDL transport support.

| IDL target | Native transport and qualification limit |
| --- | --- |
| Interface | `[annotation]` is rejected with MIDL2072. A quoted owned comment binds the original native record without a typedef. |
| Field | `[annotation("_Win32_AssociatedEnum_(KIND)")]` is emitted before the field type. If the enum is declared later, `_Win32_AnnotateField_` instead targets the original field after both native definitions. |
| Method | `[annotation("...")]` emits a prefix and can also annotate the generated proxy prototype. On non-local methods it produces MIDL2495. `_Win32_AnnotateMethod_` instead targets the actual C++ method from a helper after the interface definition, without changing RPC/SAL or the proxy. |
| Parameter | `[annotation("...")]` emits the requested prefix. Non-local parameters produce MIDL2495; the method helper does not provide parameter transport. Do not change RPC locality or suppress the warning just to carry metadata. |
| Scalar typedef | `typedef [annotation("...")]` emits an annotated typedef, with MIDL2525 warning that a SAL override on a typedef is not recommended. |
| Struct or enum written as a typedef | MIDL emits the annotation on the typedef, not directly on the tag, and produces MIDL2525. The C# reader transfers primary-record typedef facts to the record; do not infer arbitrary type/tag coverage from that compatibility behavior. |

`[annotation]` is a SAL override, not an automatically composed list of independent
metadata and native SAL facts. Preserve authored native SAL; a separate
metadata-only payload can replace it. Structured comments avoid that override and
the native attribute placement restrictions.

The native-attribute table describes MIDL's restrictions, not the production
structured-comment target surface. Comment recognition does not waive original
source, native layout/RPC, physical metadata or complete-image equivalence checks.

#### Original-AST method references

MIDL accepts a `cpp_quote` inside an interface but hoists its text before the
interface identifier declaration, not into the method declaration. A standalone
quoted attribute can therefore attach to `IID_Interface`; a quoted documentation
comment is misplaced in the same way. MIDL rejects `cpp_quote` inside parameter
and field lists. Successful MIDL compilation alone does not prove attachment.
Creating a new quote region can also introduce MIDL's standard-interface
bookkeeping; reusing an existing trailing region avoids that unrelated churn.

For native-authored C/C++, `_Win32_AnnotateMethod_` emits a metadata-only carrier after the complete
interface. Its annotation arguments contain `sizeof(&Interface::Method)`, so
Clang resolves the actual method in the original translation unit. The reader
applies the ordinary attributes to that declaration and excludes the private
carrier from generated bindings. There is no copied signature, name-based method
lookup, token/comment attribution, or second parse. The carrier is a variable,
not a typedef, so Clang's lexical type-annotation scopes do not accidentally add
facts to it. Explicit attributes still undergo normal target, duplicate, and
conflicting-floor validation.

This transport is empty without `WIN32METADATA`, under a non-Clang compiler, or in
the C-interface view. Referencing an undeclared or non-method target fails rather
than producing unbound metadata.

#### Original-AST field references

`_Win32_AnnotateField_` applies an existing annotation to a compiler-resolved
instance field after its native record and referenced enum are complete:

```cpp
struct Record { unsigned flags; };
enum FLAGS { FIRST = 1, SECOND = 4 };
_Win32_AnnotateField_(Record::flags, _Win32_AssociatedEnum_(FLAGS));
```

Existing native carriers remain supported; original-IDL migration uses comments.
Place it at native global scope after both definitions, preserving their
conditional frames. It references `sizeof(&Record::flags)` and the unchanged
typed `(FLAGS)0` annotation argument. The reader resolves the canonical
`FieldDecl`, applies the annotation before projection and redeclaration merging,
and excludes the private carrier from generated bindings. Native field storage,
record layout, unrelated fields and enum members are unchanged.

This field transport remains active in metadata-enabled Clang C++ with
`CINTERFACE` defined; method carriers retain their C++ interface requirement.
It is empty in C, ordinary metadata-off builds and non-Clang builds. Undeclared
targets fail in the compiler. Non-field targets, static members, malformed or
unannotated carriers, duplicate/conflicting facts and string-substituted targets
fail in the reader. `Field` is a private target marker, not a semantic annotation
or a new lifetime contract.

#### Upstream MIDL comment recovery

The upstream `windows-clang` implementation in `microsoft/windows-rs` does read
existing MIDL comments. At revision
[`02ec1f06`](https://github.com/microsoft/windows-rs/blob/02ec1f06fcf9643f6dbcf1fe36f6668911c5c126/crates/libs/clang/src/extract/annotations/mod.rs#L20-L81),
it tokenizes the enclosing callable and manually associates fixed comment markers
with parameter positions. Its
[decoder](https://github.com/microsoft/windows-rs/blob/02ec1f06fcf9643f6dbcf1fe36f6668911c5c126/crates/libs/clang/src/extract/annotations/mod.rs#L145-L171)
recognizes `in`, `out`, `optional`, `retval`, and `iid_is`; it is not a generic
transport for new type, field, or method attributes. Property accessor markers
are a separate fixed case. This is useful legacy-marker recovery, but does not
solve arbitrary metadata transport through MIDL. The C# reader preserves native
marker recovery alongside its explicit owned-comment parser and native identity
binding.

### C# integration and compatibility bridges

The C# scraper opts in with `--config parse-win32-annotations` and uses
`WIN32METADATA` as the public header feature gate. Its private transport override
supplies diagnostic policy as described above. There is no backend-specific header
gate, private expanded-expression payload or second parse. Comment ingestion uses
the first translation unit's detailed preprocessing record. Header annotation ingestion is implemented;
remaining sidecar migrations must still be qualified against their actual headers and
output.

Source coordinates are transport, not declaration identity: macro-expanded methods
and parameters can share them. Resolve facts within the native owning record and
function, including synthesized virtual-method callbacks, before selecting a
parameter's annotations. Remaining ambiguity and annotated declarations that are
not projected remain hard errors; do not merge unrelated owners or pick the first
candidate.

Metadata emission uses the standard `Windows.Win32.Foundation.Metadata` vocabulary.
`SetLastError` sets the ECMA-335 P/Invoke `SupportsLastError` flag; COM exact-result
preservation uses `MethodImplAttributes.PreserveSig`. Native scoped enums retain
`ScopedEnum`; logical flags groups emit `Flags`.

During partial migration, a retained legacy `SupportedOSPlatform` alias can
overlap the fully qualified header attribute. The cleaner removes only a known
legacy alias with the same target and normalized literal payload, keeping the
header attribute. Different floors, different targets, unrelated qualified
attributes, and duplicate attributes from the same source remain visible.

Both legacy input attributes, `CanReturnErrorsAsSuccess` and
`CanReturnMultipleSuccessValues`, also lower to `MethodImplAttributes.PreserveSig`.
They are input-compatibility spellings, not separate emitted custom attributes.
Free functions, interface methods, and callback `Invoke` methods use the same
encoding; the callback constructor does not acquire the flag. Header
`_Win32_PreserveResult_` and unmigrated legacy inputs therefore converge without
adding another public annotation or changing native signatures.

`ContainsInteriorPointersAttribute` is declared in `generation/WinSDK/manual/Metadata.cs`
with `AttributeUsage(AttributeTargets.Parameter, AllowMultiple = false, Inherited = false)`.
Its parameterless constructor encodes a valueless attribute on the parameter. Generic
custom-attribute emission handles it; no new inference or special registry is required.
Existing sidecars use the emitter bridge until each owning header migration qualifies:

```text
--memberRemap
EnumPrinterDriversW::pDriverInfo=[ContainsInteriorPointers]
```

COM out-pointer shape inference is also compatibility-only; use existing native SAL
for new header contracts. Field-array inference remains a separate, default-off option.

Both CsWin32 and windows-rs consume `RetVal`. CsWin32 uses `Retained` to suppress
lifetime-unsafe overloads; windows-rs lifetime policy is a separate consumer decision.
Preserve `_NullNull_terminated_` through SAL/RDL/winmd rather than compensating for
transport loss with header edits.

Documentation attributes are not required for functional winmd equivalence. The
separate follow-up is to revisit windows-docs scraping and the stale
`Microsoft.Windows.SDK.Win32Docs` package process, including its manual
merge/cross-reference step.

#### Generated remap cache

The SDK already collects cross-partition discoveries in
`scraper.autoRemaps.generated.rsp`. The header-annotation integration changes how
that existing cache is consumed: it passes the cache separately through
`--auto-remaps-file`, rather than treating it as authored response-file settings.
Legacy partitions continue using its remaps and exclusions for binding generation,
with authored settings taking priority. Native remap and function-pointer discovery
use authored settings, so repeated builds retain the same discovery sidecars and
pointer-reduction inputs.

Partitions using `parse-win32-annotations` ignore this aggregate and derive remaps
from their current translation unit instead. This prevents a previous build or an
unconverted partition from renaming types hidden by annotated headers; authored
manual/global settings still apply. This is cache isolation for the complete
annotation mode, not an enum-only mode or a new source of API-specific annotations.

### Sidecar migration matrix

| Existing source | Header representation |
| --- | --- |
| `WithSetLastError.rsp` | `_Win32_SetLastError_` on each function. |
| `supportedOS.rsp` | The matching fixed `_Win32_SupportedOS_*_` macro on the owning declaration, or a reviewed [scoped default](#scoped-supportedos-defaults) in the owning header after reader support and acceptance coverage exist. |
| `libMappingsManual.rsp` | `_Win32_ImportLibrary_`; scanning remains default. |
| `libMappings.rsp` | Import-library scan, with header override only where needed. |
| `autoTypes.json` | Move cleanup and invalid-value semantics to producer returns/output parameters; no typedef ownership and no pseudo handles. |
| `enums.json` | Metadata-only `_Win32_Enum_`/`_Win32_FlagsEnum_` groups and `AssociatedEnum` use-site annotations, retaining native types; preserve loose constants and associate them with `_Win32_AssociatedConstant_`. |
| `functionPointerFixups.json` | Replace with callback typedef-alias resolution and correct pointer-depth handling in the generator; use a guarded corrected declaration only when the SDK declaration itself is unsuitable for metadata. |
| `emitter.settings.rsp --memberRemap` | Correct guarded declaration/name in the header; use an annotation only when the native spelling must remain different. |
| `emitter.settings.rsp --memberRemap` entries using `[ContainsInteriorPointers]` | Prefix the same caller-owned buffer parameter with `_Win32_ContainsInteriorPointers_`, preserving native types and SAL. Keep the bridge until the corresponding header migration and consumer behavior qualify. |
| scraper type/tag remaps | Correct typedef/tag relationship in headers; namespace-qualified C++ types remain native. |
| exclusions | Correct header guards or metadata-only exclusion annotation if the declaration truly must not be emitted. No silent consumer list. |
| array/string/size overrides | Correct the declaration type and existing SAL/MIDL contract; do not add parallel Win32 buffer annotations. |
| COM/manual metadata | Guarded declarations and method/parameter annotations in the authoritative header. |
| documentation mappings | Documentation tooling concern; not required for functional winmd equivalence. |
| APIs absent from the selected SDK | Omit them from that metadata release. Consumers that require them use metadata generated from an SDK that still contains them. |

#### Macro-only and non-owning declarations

Declaration annotations cannot attach to a preprocessor macro or to a header that merely
references a declaration owned elsewhere.

- For object-like constant macros, add a guarded annotated constant declaration when the
  value and native type are authoritative.
- For function-like macros, preserve the macro for normal compilation and represent
  functional metadata through a guarded metadata-only function/constant declaration
  present in the Clang AST. Do not introduce a text-level macro parser.
- Put supported-OS and ownership annotations on the header that owns the complete
  declaration, not on aliases or references.
- Do not synthesize declarations or values absent from the selected SDK.
- Pointer aliases such as `PSECURITY_DESCRIPTOR` do not own pointed-to memory. Use
  producer-specific return/parameter ownership.

### Native fidelity requirements

The unified pipeline must preserve native behavior represented by direct windows-rs
generation:

1. Read `__declspec(align(...))`/Clang alignment independently from packing. `CONTEXT`
   is aligned to 16 on x64/arm64 and packed/aligned to 4 on x86.
2. Evaluate constants using compiler integer literal and conversion rules.
   High-bit `IO_REPARSE_TAG_*` constants must remain `u32`.
3. Keep `EnumWindows` as raw `BOOL` without unconditional last-error transformation.
4. Keep `LocalFree` as raw `HLOCAL`; `NULL` means success.
5. Preserve C/C++ constness through RDL and winmd. The current direct RDL path retains
   `*const`, but winmd emission must also retain `ConstAttribute`.
6. Apply SAL semantic defaults: an unannotated pointer is `In|Out` with one element and
   an unannotated scalar is `In`.

`CONTEXT` is the canonical alignment example:

```cpp
#if defined(_M_AMD64) || defined(_M_ARM64)
typedef struct DECLSPEC_ALIGN(16) _CONTEXT {
    // Architecture-specific fields.
} CONTEXT;
#else
#pragma pack(push, 4)
typedef struct _CONTEXT {
    // Architecture-specific fields.
} CONTEXT;
#pragma pack(pop)
#endif
```

No custom annotation is required. The consumer preserves compiler alignment separately
from packing and emits the architecture-specific layout.

Differences from the NuGet winmd are intentional when the NuGet baseline conflicts with
the native declaration or API contract.

### Consumer requirements

Both metadata toolchains must:

- parse annotations on functions, methods, returns, parameters, records, enums, fields,
  constants, and typedefs;
- preserve repeated attributes;
- validate annotation names, values, and targets;
- preserve calling conventions, native types, and pointer depths;
- resolve canonical callback aliases consistently at declarations and references;
- use annotations only while `WIN32METADATA` is enabled;
- emit the standard `Windows.Win32.Foundation.Metadata` attribute types into the generated winmd;
- generate x86, x64, and arm64 metadata from the same annotated headers;
- preserve compiler-derived constant types, alignment, packing, and native constness;
- obtain annotation values from compiled expression children of the original AST,
  without reparsing expanded expression strings or reconstructing macro scopes;
- make group macros empty outside metadata generation, including no typedef symbols;
- implement native Clang lexical scope and reject conflicting availability facts;
- apply SAL semantic defaults without requiring redundant header edits;
- retain raw signatures where metadata does not justify an opinionated transformation.

For large validation runs, windows-rs supports `WIN32METADATA_SEQUENTIAL=1` to process
architectures serially. This does not change metadata semantics; it avoids a worker-pool
deadlock observed with the expanded header set and makes architecture failures
deterministic.

### Equivalence definition

Logical equivalence is evaluated by declaration identity and behavior rather than byte
identity or namespace partitioning. For each API/type, compare:

- native name and kind;
- calling convention and import module;
- parameter order, direction, native type, pointer depth, and array/size semantics;
- return type and ownership;
- enum underlying type, members, values, scoped/flags semantics;
- struct layout, fields, packing, alignment, inheritance, and size field;
- interfaces, methods, and UUIDs;
- last-error and success semantics;
- supported OS;
- callback canonical names;
- repeatable metadata such as invalid handle values.

Keep enum association identity, native use-site storage, and metadata enum storage
as separate checks. Existing advisory associations may legitimately join different
storage types. Expected handle/enum projection changes and justified corrections to
incorrect legacy metadata must be classified by the affected API and behavior,
not treated as unexplained migration failures.

Raw comparer output remains evidence, not a count of independent defects: one enum
storage correction can also change the reported constant types of all its members.
Metadata type-table positions and synthetic enum declaration order alone are not
functional compatibility failures. Preserve ABI-relevant structure field order and
interface/vtable method order, and keep raw reports unchanged rather than sorting
or suppressing their differences.

Any unexplained difference affecting generated bindings or safe resource use is a functional gap and
requires a source syntax, consumer behavior, patch, and regression test.

### Migration and validation plan

The existing C# tooling and pilot are qualified. The phases below describe migration
and validation requirements, not authorization to resume the paused full-SDK migration.
A Rust replacement is independent work and must meet the same source/metadata contract
before adoption; it is not a prerequisite for migrating SDK annotations.

#### Phase 1: implement the reviewed vocabulary

1. Limit the annotation header, parser, fixtures, and documentation to the vocabulary
   defined by this specification.
2. Keep `CountFieldName`, `StructSizeField`, and `NativeInheritance` out of the initial
   vocabulary unless a concrete consumer and canonical gap are demonstrated.
3. Prepare authoritative MIDL `[retval]` as native retval SAL. Use `_Win32_Retval_`
   for C/C++-authored declarations lacking that native semantic.
4. Normalize function, return, parameter, and field annotations to SAL-style prefix
   placement for readability. Validate compiler attachment rather than source tokens.
5. Keep explicit annotations only for producer ownership/invalid values, retained
   parameters, exact-result behavior, guarded enum associations, and other
   semantics that existing C/C++/SAL/MIDL cannot express.

#### Phase 2: additional windows-rs source fidelity

These requirements apply to the Rust replacement, not as gates on C# migration.

1. Preserve SAL semantic defaults and native constness through final winmd emission.
2. Preserve `_NullNull_terminated_` and native retval SAL from prepared MIDL sources.
3. Preserve compiler-derived alignment and constant types with regression coverage.
4. Add standard `[[deprecated]]` to `ObsoleteAttribute` handling.
5. Add or confirm consumer tests for `Retained`, exact-result preservation, and
   producer-site ownership.
6. Retain the direct-generation behavior for `EnumWindows` and `LocalFree`.

#### Phase 3: patch canonical SDK examples

1. `OpenPrinterW`: use raw `HANDLE*` annotated with
   `_Win32_RAIIFree_Handle_(ClosePrinter)`.
2. `CoGetClassObject`: associate `dwClsContext` with the existing `CLSCTX` declaration;
   use existing COM output SAL.
3. `AddFontResourceExW`: add the reviewed metadata-only group and associate the flags
   use.
4. `WAVEHDR::lpData`: use a non-string pointer type and existing byte-count SAL.
5. `AcceptSecurityContext`: preserve the native `SECURITY_STATUS` return and add
   `_Win32_PreserveResult_`; do not introduce `ProjectAs`.
6. `PTOP_LEVEL_EXCEPTION_FILTER`: make the generator resolve the public callback name
   from the typedef-alias graph without a header annotation.
7. Service configuration enums: add metadata-only constant groups, parameter
   associations, and `AssociatedConstant` annotations for `SERVICE_NO_CHANGE`.
8. `CM_NOTIFY_FILTER`: defer struct-size projection metadata until a consumer exists.
9. `IMAGE_OPTIONAL_HEADER32/64::LoaderFlags`: add guarded standard deprecation syntax.

#### Phase 4: migrate the remaining sidecars by family

1. Ownership and invalid values at producer sites.
2. Metadata-only logical groups, associated constants, and native-typed parameter
   associations.
3. Result behavior and retained parameters.
4. Correct native pointer types and existing SAL count/byte-size/string semantics.
5. Generator callback-alias and pointer-depth fixes.
6. Obsolete and other proven type-level semantics.
7. Import library, last error, supported OS, and documentation-source work.

For each family, require a canonical header example, first-AST/source-to-winmd coverage
through the selected production toolchain, ordinary-consumer and architecture controls,
and logical comparison to the prior metadata. Classify intentional native-SDK fidelity
differences explicitly. Add generated binding tests where projection behavior changes;
a replacement toolchain must satisfy the same contract.

#### Phase 5: equivalence and rollout

1. Select a shipped SDK and generate x86, x64, and arm64 metadata only from that SDK's
   declarations plus temporary patches for changes intended to ship in that SDK.
2. Compare by logical declaration identity and attribute behavior, not byte identity.
3. Classify every difference as:
   - required parity with win32metadata;
   - an intentional windows-rs/native-SDK fidelity improvement;
   - projection-only behavior;
   - unsupported/deferred metadata with no current consumer.
4. Run CsWin32 and windows-rs projection regressions for ownership, retval, arrays,
   struct initialization, COM output, success behavior, and architecture layout.
5. Upstream the windows-rs changes and SDK header changes in reviewable annotation
   families, then remove the corresponding sidecars.

Keep raw API differences visible. Review concrete intentional differences against the
source changes and record signoff in PR comments; do not check in an
expected-differences text file or use a blanket allowlist to turn drift into acceptance.

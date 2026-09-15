# Shift-Left Win32 Metadata Annotation Specification

## Status

This document defines how Windows SDK C/C++ headers represent win32metadata semantics
and how the windows-rs metadata toolchain consumes them.

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
3. Metadata-only declarations are guarded by `WIN32METADATA`.
4. Existing genuine SDK typedefs may be annotated. New API-specific pseudo handles
   such as `PRINTER_HANDLE` must not be introduced.
5. Resource producers carry cleanup and invalid-value metadata only on their return or
   output parameter. Plain `HANDLE` and handle typedefs do not imply automatic cleanup.
6. Header import-library annotations are authoritative. Import-library scanning remains
   the default.
7. Every SDK patch is a per-header, per-reason patch applied through the PR #2248
   ingestion mechanism, not a generated patch series under `docs`.
8. Existing C/C++, SAL, MIDL, and compiler semantics are preferred over custom
   annotations. Do not add redundant `_In_` to scalars or `_Inout_` to unannotated
   pointers: those are the SAL semantic defaults.
9. Logical equivalence to the NuGet winmd is the target only where the NuGet metadata is
   correct. Direct windows-rs fixes for native alignment, compiler-typed constants,
   `EnumWindows`, and `LocalFree` must not be regressed.
10. The selected shipped SDK is authoritative for API availability. Do not carry
    forward copied headers or declarations removed from that SDK. Metadata-only
    declarations may represent macros, inline helpers, constants, or exports that are
    part of the selected SDK, but they must not resurrect APIs absent from it.

## Transport and vocabulary

The ingested SDK defines the vocabulary in
`RecompiledIdlHeaders/shared/win32metadata_annotations.h`:

```cpp
#if defined(WIN32METADATA) && defined(__clang__)
#define _WIN32META_ANNOTATION_(text) __attribute__((annotate(text)))
#else
#define _WIN32META_ANNOTATION_(text)
#endif
```

Lifecycle metadata uses one variadic source annotation:

```cpp
#define _Win32_RAIIFree_(...) \
    _WIN32META_ANNOTATION_("RAIIFree(" #__VA_ARGS__ ")")
```

The first argument identifies the cleanup function and the optional remaining arguments
identify invalid values:

```cpp
_Win32_RAIIFree_(SysFreeString)
_Win32_RAIIFree_(CloseHandle, 0, INVALID_HANDLE_VALUE)
```

The consumer parses the comma-separated token payload. For each invalid value, it uses
the declaration's Clang preprocessor context to expand object-like macros and evaluates
the resulting constant expression. It emits one `RAIIFreeAttribute` plus one
`InvalidHandleValueAttribute` for each supplied value. An unresolved or non-constant
value is an error.

windows-rs enables `WIN32METADATA` while scraping annotated headers. Unknown,
malformed, valued-versus-valueless, and incorrectly placed annotations are errors with
source locations.

Custom names use an explicit `_Win32_` owner prefix and PascalCase semantic names. For
example, use `_Win32_SetLastError_`, `_Win32_ImportLibrary_(...)`,
`_Win32_Retval_`, and `_Win32_Retained_`.

IDL `[retval]` does not survive in MIDL-generated headers as SAL. It remains in comments
such as `/* [retval] */`, which windows-rs parses. C/C++-authored declarations without
that comment combine ordinary direction SAL with `_Win32_Retval_`:

```cpp
virtual HRESULT STDMETHODCALLTYPE GetDesc(
    _Out_ _Win32_Retval_ DXGI_ADAPTER_DESC* pDesc) = 0;
```

## Declaration placement

### Functions and methods

Function metadata and metadata describing the return value precede the complete
declaration. Clang attaches a prefix `annotate` attribute to the `FunctionDecl`; the
windows-rs consumer maps return-oriented annotations from that declaration to the
metadata return parameter. The annotation must not be inserted between `WINAPI` and
the function name.

```cpp
_Win32_SetLastError_
_Win32_ImportLibrary_("correct.dll")
BOOL WINAPI Example(void);
```

Return annotations use the same prefix position. Prefix placement is accepted by Clang
and preserves the complete calling-convention declarator while matching normal SAL
reading order.

```cpp
_Win32_RAIIFree_(CloseHandle, 0, INVALID_HANDLE_VALUE)
HANDLE WINAPI OpenThing(void);
```

### Parameters and fields

Parameter and field annotations precede the declaration type, alongside SAL. This is
supported by Clang and matches the established SDK annotation style. Keep distinct
annotations on separate source lines when that improves readability; keep cleanup and
invalid-value metadata together in `_Win32_RAIIFree_`.

```cpp
BOOL WINAPI CreateThing(
    _Out_ _Win32_RAIIFree_(CloseThing, 0, INVALID_HANDLE_VALUE)
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

Do not place custom return annotations after the closing parenthesis.

### Records, interfaces, and enums

Attributes appear between the declaration keyword and name.

```cpp
struct _Windows_SupportedOS_10240_ DESCRIPTION {
    DWORD cbSize;
};
```

```cpp
enum class _Windows_SupportedOS_10240_ [[clang::flag_enum]] OPTION : unsigned long {
    OPTION_NONE = 0,
};
```

### Typedefs and callback aliases

Type metadata precedes the typedef.

```cpp
_Windows_SupportedOS_10240_
typedef BOOL(WINAPI *PUBLIC_CALLBACK)(DWORD value);
```

## Attribute solution matrix

| winmd semantic | Header syntax | Valid target and consumer behavior |
| --- | --- | --- |
| `SetLastError` / P/Invoke `SupportsLastError` | `_Win32_SetLastError_` | Function. No existing SAL annotation means that an API sets thread last error; sets the ECMA-335 P/Invoke flag. |
| P/Invoke module override | `_Win32_ImportLibrary_("name.dll")` | Function. Overrides import-library scan results. |
| `SupportedOSPlatform("windows...")` | One fixed `_Windows_SupportedOS_*_` macro from the menu below | Function, method, record, enum, or typedef. The macro expands to the canonical version string so authors cannot mistype it. |
| preserve exact return/result | `_Win32_PreserveResult_` | Function or method. The projection must preserve the exact result; COM metadata uses standard `MethodImplAttributes.PreserveSig`. |
| `RAIIFree("CloseX")` and repeated `InvalidHandleValue(value)` | `_Win32_RAIIFree_(CloseX, invalid...)` | Producer function/method return or output parameter only. The first argument identifies the cleanup function. The remaining arguments are optional integer literals or object-like macros such as `INVALID_HANDLE_VALUE`. The consumer resolves macros in the declaration's preprocessor context, evaluates each constant expression, and emits one `RAIIFree` attribute plus one `InvalidHandleValue` attribute for each supplied invalid value. |
| `NullNullTerminated` | Existing SAL `_NullNull_terminated_` | Return, parameter, field, or typedef. No custom annotation is required. |
| `Retained` | `_Win32_Retained_` | Pointer parameter retained by the API beyond the function call. The caller must follow the API documentation to determine when the referenced storage may be released. Without this annotation, the pointer does not need to remain valid after the call returns. |
| array count/capacity/byte size | Existing SAL and native array declarations | Use `_In_reads_`, `_Out_writes_`, `_Inout_updates_`, their byte-count variants, and related standard forms. Do not define parallel Win32 annotations. |
| `AlsoUsableFor("TYPE")` | `_Win32_AlsoUsableFor_(TYPE)` | Typedef. |
| `AssociatedEnum("TYPE")` | `_Win32_AssociatedEnum_(TYPE)` | Parameter, return value, or field when direct enum typing is impossible. `__typefix` is analyzer metadata, not a projection contract. |
| `AssociatedConstant("NAME")` | `_Win32_AssociatedConstant_(NAME)` | Enum. Associates a loose SDK constant with an enum without changing the constant's existing global spelling. Repeatable. |
| input/output/optional/reserved | Existing SAL/MIDL | Use `_In_`, `_Out_`, `_Inout_`, `_Reserved_`, and their standard variants; no custom duplicates. |
| `RetVal` | MIDL `[retval]` or existing direction SAL plus `_Win32_Retval_` | Parameter. windows-rs parses `[retval]` from MIDL-generated header comments; C/C++-only declarations use the custom annotation. |
| `ComOutPtr` | `_COM_Outptr_` and standard SAL variants | Parameter. No new Win32 metadata annotation is required; shape-based inference is compatibility-only. |
| native constness | Native C/C++ `const` | Parameter or field. Const loss is a windows-rs RDL/winmd fidelity bug, not a header-annotation requirement. |
| scoped enum | Native `enum class` | Emitted as `ScopedEnum`. Existing scoped SDK enums are supported, but synthetic bags of constants use ordinary unscoped enums. |
| flags enum | `[[clang::flag_enum]]` | Enum. Emitted with flags semantics. |

### Supported OS macro menu

The annotation header defines only the versions currently present in
`supportedOS.rsp`. Each macro expands to a fixed annotation payload:

```cpp
_Windows_SupportedOS_Windows2000_
_Windows_SupportedOS_WindowsXP_
_Windows_SupportedOS_WindowsVista_
_Windows_SupportedOS_Windows7_
_Windows_SupportedOS_Windows8_
_Windows_SupportedOS_Windows81_
_Windows_SupportedOS_10240_
_Windows_SupportedOS_10586_
_Windows_SupportedOS_14393_
_Windows_SupportedOS_15063_
_Windows_SupportedOS_16299_
_Windows_SupportedOS_17134_
_Windows_SupportedOS_17763_
_Windows_SupportedOS_18362_
_Windows_SupportedOS_19041_
_Windows_SupportedOS_Server2000_
_Windows_SupportedOS_Server2003_
_Windows_SupportedOS_Server2008_
_Windows_SupportedOS_Server2012_
_Windows_SupportedOS_Server2016_
```

New versions require adding a reviewed macro definition rather than placing a free-form
version token on individual declarations.

Existing compiler/SAL facts remain the preferred source for attributes already expressed
by native syntax, including `noreturn`, architecture guards, alignment, native typedef
identity, bitfields, UUIDs, packing, parameter direction, optionality, and array sizes.
The custom annotations are fallbacks where existing syntax is absent or wrong.

### Vocabulary not included in the initial implementation

| Semantic | Decision |
| --- | --- |
| `IgnoreIfReturn` | Not included. Neither CsWin32 nor windows-rs consumes it, including the `CreatePipe` sidecars. |
| `FreeWith` | Not included. Allocated producer outputs use `RAIIFree`; cleanup is not attached to pointer typedefs. |
| `DoNotRelease` | Not included. Plain handles are borrowed unless a producer site carries ownership metadata. |
| `Agile` | Intentionally jettisoned. Existing annotations asserted that selected non-WinRT COM interfaces were always thread-safe, but that guarantee was repeatedly violated. COM does not have WinRT's exclusive/agile interface contract, so no `_Win32_Agile_` replacement is defined. |
| custom COM out-pointer annotation | Not included. Use `_COM_Outptr_`, its standard variants, IID/PPV conventions, or explicit existing SAL. |
| `NotNullTerminated` | Not included. Declarations that use a string typedef for non-string data require an appropriately typed pointer plus ordinary SAL count/byte-count annotations. |
| `NativeArrayInfo` and `MemorySize` fallbacks | Not included. SAL expresses buffer counts, capacities, and byte sizes; the consumer must preserve that SAL instead of introducing duplicate metadata annotations. |
| `NativeArrayInfo.CountFieldName` | Deferred with field-array projection. `CERT_INFO::rgExtension` is descriptive metadata, but neither CsWin32 nor windows-rs provides a field-array projection. |
| `NativeInheritance` | Not included for `MONITORINFOEXW`; the SDK expresses the C++ base and equivalent C layout prefix, and both metadata baselines preserve it. Add this vocabulary only if a separate, proven source gap requires it. |
| `ReducePointerLevel` for `UCharIterator::move` | Not included. windows-rs emits the correct callback field pointer level; only implied pointer direction requires correction. |
| `ProjectAs` | Not included. Preserve native typedef identity and use `AssociatedEnum` for the proven enum-specific use-site relationship. |
| `StructSizeField` | Deferred. No equivalent SAL annotation exists, and neither CsWin32 nor windows-rs consumes the metadata. Add it only with concrete projection behavior and tests. |
| `NativeEncoding` | Not included. Declare guarded constants with their real `char`/`wchar_t` type. |
| `Ansi` / `Unicode` | Not included. No projection behavior in scope requires these attributes. |
| `CanonicalName` | Not a header annotation. Resolve the public callback name from the native typedef-alias graph. |
| `ReducePointerLevel` | Not a header annotation. Correct callback/pointer parsing or use the correct typedef in a guarded metadata declaration. |
| `StaticLibrary` | Deferred until a canonical use and functional consumer behavior are defined. |

## Enum and constant migration

Synthetic bags of constants from `enums.json` become guarded unscoped SDK enum
declarations. Normal compilation must preserve the original integer ABI:

```cpp
#ifdef WIN32METADATA
#pragma push_macro("MODE_A")
#undef MODE_A
enum MODE : DWORD {
    MODE_A = 1,
};
#pragma pop_macro("MODE_A")
#else
typedef DWORD MODE;
#endif
```

Rules:

- Use the original underlying integer type.
- Balance every `push_macro` with `pop_macro`.
- Prefer changing metadata parameter/field types directly to the enum in the
  `WIN32METADATA` branch.
- Use `AssociatedEnum` only when direct typing is impossible.
- Preserve complete existing constant names as unscoped enum members so generated
  consuming code does not require scoped-name changes.
- Keep loose constants such as `SERVICE_NO_CHANGE` global and use repeatable
  `AssociatedConstant` annotations on each related enum. Do not duplicate the same
  unscoped enumerator name in multiple enums.
- Use `enum class` only when the SDK declaration is already scoped or a new native API
  intentionally defines scoped semantics; do not use it merely to wrap constants.
- Metadata-only constants use guarded annotated `constexpr`/`const` declarations while
  preserving the ordinary macro.

## HANDLE ownership

Handle typedefs do not carry cleanup ownership or automatic-close behavior. APIs that
natively use `HANDLE` remain `HANDLE`, and ownership is attached only to a producer
return or output parameter:

```cpp
BOOL WINAPI OpenPrinterW(
    _In_ LPWSTR name,
    _Out_ _Win32_RAIIFree_(ClosePrinter, 0, INVALID_HANDLE_VALUE)
    HANDLE* printer);
```

Do not create `PRINTER_HANDLE`, `HEAP_HANDLE`, or similar metadata-only pseudo types.
Absence of `RAIIFree` means borrowed. `GetProcessHeap`, for example, requires no custom
annotation because its returned `HANDLE` is not automatically closed.

Invalid values are API-specific rather than a fixed global set. Use the SDK spelling
that expresses the API contract, such as `0` and `INVALID_HANDLE_VALUE`. The annotation
preserves those tokens; the consumer is responsible for macro expansion and constant
evaluation.

Consumer/freeing APIs such as `LocalFree` retain their raw native signature. Do not use
generic invalid-handle success logic for them: `LocalFree` returns `NULL` on success and
the still-valid input handle on failure.

## Import-library precedence

1. `_Win32_ImportLibrary_` on the declaration.
2. Import-library scanning.
3. Configured default.

This permits headers to correct missing or incorrect `.lib` information without
duplicating the complete scan-derived mapping.

## Sidecar migration matrix

| Existing source | Header representation |
| --- | --- |
| `WithSetLastError.rsp` | `_Win32_SetLastError_` on each function. |
| `supportedOS.rsp` | The matching fixed `_Windows_SupportedOS_*_` macro on the owning declaration. |
| `libMappingsManual.rsp` | `_Win32_ImportLibrary_`; scanning remains default. |
| `libMappings.rsp` | Import-library scan, with header override only where needed. |
| `autoTypes.json` | Move cleanup and invalid-value semantics to producer returns/output parameters; no typedef ownership and no pseudo handles. |
| `enums.json` | Guarded unscoped enum declarations and direct enum typing; preserve loose constants and associate them with `_Win32_AssociatedConstant_`. |
| `functionPointerFixups.json` | Replace with callback typedef-alias resolution and correct pointer-depth handling in the generator; use a guarded corrected declaration only when the SDK declaration itself is unsuitable for metadata. |
| `emitter.settings.rsp --memberRemap` | Correct guarded declaration/name in the header; use an annotation only when the native spelling must remain different. |
| scraper type/tag remaps | Correct typedef/tag relationship in headers; namespace-qualified C++ types remain native. |
| exclusions | Correct header guards or metadata-only exclusion annotation if the declaration truly must not be emitted. No silent consumer list. |
| array/string/size overrides | Correct the declaration type and existing SAL/MIDL contract; do not add parallel Win32 buffer annotations. |
| COM/manual metadata | Guarded declarations and method/parameter annotations in the authoritative header. |
| documentation mappings | Documentation tooling concern; not required for functional winmd equivalence. |
| APIs absent from the selected SDK | Omit them from that metadata release. Consumers that require them use metadata generated from an SDK that still contains them. |

### Macro-only and non-owning declarations

Declaration annotations cannot attach to a preprocessor macro or to a header that merely
references a declaration owned elsewhere.

- For object-like constant macros, add a guarded annotated constant declaration when the
  value and native type are authoritative.
- For function-like macros, preserve the macro for normal compilation and represent
  functional metadata through a guarded metadata-only function/constant declaration or
  an explicit annotated-macro construct consumed before Clang declaration traversal.
- Put supported-OS and ownership annotations on the header that owns the complete
  declaration, not on aliases or references.
- Do not synthesize declarations or values absent from the selected SDK.
- Pointer aliases such as `PSECURITY_DESCRIPTOR` do not own pointed-to memory. Use
  producer-specific return/parameter ownership.

## Reviewed semantic decisions

### COM outputs

Use standard `_COM_Outptr_` SAL variants where present. Eligible IID/PPV pairs may be
recognized by convention. Do not introduce a custom Win32 COM-out-pointer annotation.

### String termination

- `WAVEHDR::lpData` is binary data and should not use a string typedef. In the
  `WIN32METADATA` declaration, spell it as an appropriately typed character/byte
  pointer and preserve its byte-count relationship with SAL.
- `GetVolumePathNamesForVolumeNameW` already carries `_NullNull_terminated_`. Fix the
  SAL-to-RDL-to-winmd preservation path; do not modify the SDK declaration.
- Classify the remaining NuGet `NotNullTerminated` occurrences as incorrect string
  typedefs, counted buffers, or double-NUL strings. Correct the declaration type or SAL
  rather than preserving `NotNullTerminated` as a custom annotation.

### Return and success behavior

- `RetVal` identifies the output parameter selected as the friendly projected return.
  Both CsWin32 and windows-rs consume it.
- `Retained` identifies a pointer that the API may use after the function returns. The
  caller follows the API documentation to determine the end of that lifetime. CsWin32
  uses it to suppress lifetime-unsafe overloads; windows-rs consumer policy remains
  unresolved.
- `_Win32_PreserveResult_` means that a projection must not transform or discard the
  exact result. It covers APIs represented in existing metadata by
  `CanReturnErrorsAsSuccess` or `CanReturnMultipleSuccessValues`.
  `_Success_` and `_Return_type_success_` remain useful static-analysis predicates but
  do not express this projection rule.
- `EnumWindows` must not carry `SupportsLastError`; preserve its raw `BOOL` result
  because `FALSE` can mean intentional callback termination.

### Struct size fields

No SAL annotation specifically identifies a field as the structure's initialization
size. Neither CsWin32 nor windows-rs consumes `StructSizeField`. Defer a source
annotation until a projection defines concrete initializer behavior, including
versioned structures that intentionally accept an older size.

### Obsolete fields

Prefer standard, metadata-only guarded C++ `[[deprecated]]` syntax and teach the Clang
pipeline to emit `ObsoleteAttribute`. `IMAGE_OPTIONAL_HEADER32::LoaderFlags` and the
64-bit equivalent are the canonical examples.

### Enums and associated constants

`ENUM_SERVICE_TYPE`, `SERVICE_START_TYPE`, and `SERVICE_ERROR` are guarded synthetic
unscoped enums because the SDK exposes `DWORD` parameters and macro constants. Keep
`SERVICE_NO_CHANGE` as a global constant and apply
`_Win32_AssociatedConstant_(SERVICE_NO_CHANGE)` to each related enum. This preserves
existing projected names without introducing duplicate unscoped enumerators.

### Documentation

Documentation attributes are not required for functional winmd equivalence. The
follow-up is to revisit scraping windows-docs and the stale
`Microsoft.Windows.SDK.Win32Docs` package process, which appears to have required a
manual merge/cross-reference step.

## Native fidelity requirements

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

## Reviewed API-specific conclusions

| Example | Implementation conclusion |
| --- | --- |
| `CoGetClassObject` | Add only the `CLSCTX` association. `CLSCTX` already exists in `shared/WTypesbase.h`; use existing COM output SAL. |
| `AddFontResourceExW` | Use a guarded synthetic enum because the semantic enum is not already declared in the header. |
| `ADsBuildVarArrayInt` | No redundant `_In_`/`_Inout_` header edits. Fix windows-rs handling of SAL semantic defaults. |
| `JetTerm` | Preserve `JET_API_PTR` as an architecture-neutral pointer-sized type. A typed `JET_ERR` definition is acceptable only if it remains ABI-compatible with `int`; no `ProjectAs` annotation is needed. |
| `D2D1CreateDevice` | No declaration punctuation or return-type annotation gap was established. |
| `K32EnumProcesses` | The windows-rs baseline may be more accurate, but duplicate flat names are confusing. Preserve as an explicit team naming-policy decision rather than forcing NuGet parity. |
| `NdrClientCall2` | Fix implied pointer direction; do not add redundant header annotations. |
| `IDXGIFactory1::EnumAdapters1` | Add `_Win32_PreserveResult_` so `DXGI_ERROR_NOT_FOUND` remains observable during normal enumeration. |
| `DoDragDrop` | Add `_Win32_PreserveResult_` so distinct successful outcomes are not collapsed. |
| `HttpReceiveHttpRequest` | Keep `Retained`; CsWin32 uses it, while windows-rs behavior still needs a decision. |
| `RasEnumConnectionsW` | Preserve both element-count and byte-capacity relationships; they are distinct and consumed. |
| `CERT_INFO::rgExtension` | Defer `CountFieldName` until a field-array projection is defined. |
| `UCharIterator::move` | Pointer level is already correct in windows-rs; fix only the implied `In|Out` direction. |
| `MONITORINFOEXW` | Existing C++ inheritance/C layout prefix is sufficient; do not add `NativeInheritance`. |

## Consumer requirements

The windows-rs consumer must:

- parse annotations on functions, methods, returns, parameters, records, enums, fields,
  constants, and typedefs;
- preserve repeated attributes;
- validate annotation names, values, and targets;
- preserve calling conventions and pointer depths unless an explicit metadata annotation
  changes the emitted type;
- resolve canonical callback aliases consistently at declarations and references;
- use annotations only while `WIN32METADATA` is enabled;
- emit the standard `Windows.Win32.Metadata` attribute types into the generated winmd;
- generate x86, x64, and arm64 metadata from the same annotated headers;
- preserve compiler-derived constant types, alignment, packing, and native constness;
- resolve object-like macros used as annotation values in the declaration's
  preprocessor context and evaluate the expanded constant expression;
- apply SAL semantic defaults without requiring redundant header edits;
- retain raw signatures where metadata does not justify an opinionated transformation.

For large validation runs, windows-rs supports `WIN32METADATA_SEQUENTIAL=1` to process
architectures serially. This does not change metadata semantics; it avoids a worker-pool
deadlock observed with the expanded header set and makes architecture failures
deterministic.

## Equivalence definition

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

Any difference affecting generated bindings or safe resource use is a functional gap and
requires a source syntax, consumer behavior, patch, and regression test.

## Implementation plan

### Phase 1: implement the reviewed vocabulary

1. Limit the annotation header, parser, fixtures, and documentation to the vocabulary
   defined by this specification.
2. Keep `CountFieldName`, `StructSizeField`, and `NativeInheritance` out of the initial
   vocabulary unless a concrete consumer and canonical gap are demonstrated.
3. Use MIDL `[retval]` where authoritative and `_Win32_Retval_` only for C/C++-authored
   declarations that lack the MIDL-generated comment.
4. Normalize function, return, parameter, and field annotations to SAL-style prefix
   placement. Do not use post-declarator return annotations.
5. Keep explicit annotations only for producer ownership/invalid values, retained
   parameters, exact-result behavior, guarded enum associations, and other
   semantics that existing C/C++/SAL/MIDL cannot express.

### Phase 2: complete windows-rs source fidelity

1. Preserve SAL semantic defaults and native constness through final winmd emission.
2. Preserve `_NullNull_terminated_` and MIDL-generated `[retval]` comment semantics.
3. Preserve compiler-derived alignment and constant types with regression coverage.
4. Add standard `[[deprecated]]` to `ObsoleteAttribute` handling.
5. Add or confirm consumer tests for `Retained`, exact-result preservation, and
   producer-site ownership.
6. Retain the direct-generation behavior for `EnumWindows` and `LocalFree`.

### Phase 3: patch canonical SDK examples

1. `OpenPrinterW`: use raw `HANDLE*` annotated with
   `_Win32_RAIIFree_(ClosePrinter, 0, INVALID_HANDLE_VALUE)`.
2. `CoGetClassObject`: associate `dwClsContext` with the existing `CLSCTX` declaration;
   use existing COM output SAL.
3. `AddFontResourceExW`: add the reviewed guarded unscoped enum and associate the flags
   use.
4. `WAVEHDR::lpData`: use a non-string pointer type and existing byte-count SAL.
5. `AcceptSecurityContext`: preserve the native `SECURITY_STATUS` return and add
   `_Win32_PreserveResult_`; do not introduce `ProjectAs`.
6. `PTOP_LEVEL_EXCEPTION_FILTER`: make the generator resolve the public callback name
   from the typedef-alias graph without a header annotation.
7. Service configuration enums: add guarded unscoped enum declarations, parameter
   associations, and `AssociatedConstant` annotations for `SERVICE_NO_CHANGE`.
8. `CM_NOTIFY_FILTER`: defer struct-size projection metadata until a consumer exists.
9. `IMAGE_OPTIONAL_HEADER32/64::LoaderFlags`: add guarded standard deprecation syntax.

### Phase 4: migrate the remaining sidecars by family

1. Ownership and invalid values at producer sites.
2. Guarded unscoped enum declarations, associated constants, and parameter
   associations.
3. Result behavior and retained parameters.
4. Correct native pointer types and existing SAL count/byte-size/string semantics.
5. Generator callback-alias and pointer-depth fixes.
6. Obsolete and other proven type-level semantics.
7. Import library, last error, supported OS, and documentation-source work.

For each family, require a canonical header example, source-to-RDL test, RDL-to-winmd
test, generated binding test where behavior changes, and logical comparison to both the
NuGet reference and current direct windows-rs output.

### Phase 5: equivalence and rollout

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

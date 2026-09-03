# Shift-Left Win32 Metadata Annotation Specification

## Status

This document is the canonical, reviewed implementation plan for representing
win32metadata semantics in Windows SDK C/C++ headers and consuming them with the
windows-rs metadata toolchain. It incorporates the decisions from
`docs/copilot/shift-left-gap-review.html`.

Much of the annotation transport and RDL/winmd plumbing has been prototyped on
`jevansaks/windows-rs:user/jevansa/shift-left-metadata`. Prototype support does not mean
that every provisional annotation should ship. The vocabulary must be reduced to the
semantics retained by this review before implementation is finalized.

The migration is staged through the SDK ingestion patch system in
`generation/WinSDK/patches`. The eventual source of truth is the Windows SDK headers;
the patches are temporary until the corresponding header changes ship in the SDK.

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

windows-rs enables `WIN32METADATA` while scraping annotated headers. Unknown,
malformed, valued-versus-valueless, and incorrectly placed annotations are errors with
source locations.

Custom names retain an explicit `_Win32_` owner prefix and use PascalCase semantic
names. For example, use `_Win32_SetLastError_`, `_Win32_ImportLibrary_(...)`,
`_Win32_Retval_`, and `_Win32_Retained_`. Existing SAL itself is not consistently
sentence-cased: names such as `_Return_type_success_` and
`_Outptr_result_maybenull_` use lowercase word segments. The Win32 additions
intentionally use PascalCase rather than copying that historical inconsistency.

`_Out_retval_` is not an SDK SAL macro and must not be described as one. For
IDL-authored declarations, use authoritative MIDL `[retval]`; MIDL-generated headers
retain that marker in parameter comments and windows-rs parses those comments. For
C/C++-authored declarations without such a comment, combine existing direction SAL
with `_Win32_Retval_`:

```cpp
virtual HRESULT STDMETHODCALLTYPE GetDesc(
    _Out_
    _Win32_Retval_
    DXGI_ADAPTER_DESC *pDesc) = 0;
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
_Win32_RAIIFree_(CloseHandle)
_Win32_InvalidHandle_(INVALID_HANDLE_VALUE)
_Win32_InvalidHandle_(NULL)
HANDLE WINAPI OpenThing(void);
```

### Parameters and fields

Parameter and field annotations precede the declaration type, alongside SAL. This is
supported by Clang and matches the established SDK annotation style. Put repeated
annotations on separate source lines when needed.

```cpp
BOOL WINAPI CreateThing(
    _Out_
    _Win32_RAIIFree_(CloseThing)
    _Win32_InvalidHandle_(-1)
    _Win32_InvalidHandle_(0)
    HANDLE *result);
```

Buffer counts, capacities, and byte sizes use existing SAL rather than parallel Win32
metadata annotations:

```cpp
BOOL WINAPI ReadThings(
    _Out_writes_(count)
    THING *items,
    _In_ DWORD count);
```

Do not place custom return annotations after the closing parenthesis. The earlier
prototype used trailing attributes while diagnosing a calling-convention parsing bug,
but the prefix fixture proves that trailing placement is unnecessary.

### Records, interfaces, and enums

Attributes appear between the declaration keyword and name.

```cpp
struct
    DESCRIPTION {
    DWORD cbSize;
};
```

```cpp
enum class
    _Windows_SupportedOS_10240_
    [[clang::flag_enum]]
    OPTION : unsigned long {
    OPTION_NONE = 0,
};
```

### Typedefs and callback aliases

Type metadata precedes the typedef. A canonical callback annotation preserves the
public metadata name while references continue to use the native typedef.

```cpp
typedef BOOL (WINAPI *PUBLIC_CALLBACK)(DWORD value);
```

## Attribute solution matrix

| winmd semantic | Header syntax | Valid target and consumer behavior |
| --- | --- | --- |
| `SetLastError` / P/Invoke `SupportsLastError` | `_Win32_SetLastError_` | Function. No existing SAL annotation means that an API sets thread last error; sets the ECMA-335 P/Invoke flag. |
| P/Invoke module override | `_Win32_ImportLibrary_("name.dll")` | Function. Overrides import-library scan results. |
| `SupportedOSPlatform("windows...")` | One fixed `_Windows_SupportedOS_*_` macro from the menu below | Function, method, record, enum, or typedef. The macro expands to the canonical version string so authors cannot mistype it. |
| preserve exact return/result | `_Win32_PreserveResult_` | Function or method. Replaces both `CanReturnErrorsAsSuccess` and `CanReturnMultipleSuccessValues`; COM metadata uses standard `MethodImplAttributes.PreserveSig`. |
| `Agile` | `_Win32_Agile_` | Class/struct/interface declaration. |
| `RAIIFree("CloseX")` | `_Win32_RAIIFree_(CloseX)` | Producer function/method return or output parameter only. |
| `InvalidHandleValue(value)` | `_Win32_InvalidHandle_(value)` | Producer function/method return or output parameter only. Repeatable; signed decimal and hexadecimal C literals are accepted. |
| `NullNullTerminated` | Existing SAL `_NullNull_terminated_` | Return, parameter, field, or typedef. No custom annotation is required. |
| `Retained` | `_Win32_Retained_` | Parameter. |
| array count/capacity/byte size | Existing SAL and native array declarations | Use `_In_reads_`, `_Out_writes_`, `_Inout_updates_`, their byte-count variants, and related standard forms. Do not define parallel Win32 annotations. |
| `AlsoUsableFor("TYPE")` | `_Win32_AlsoUsableFor_(TYPE)` | Typedef. |
| `AssociatedEnum("TYPE")` | `_Win32_AssociatedEnum_(TYPE)` | Parameter, return value, or field when direct enum typing is impossible. Legacy `__typefix` is obsolete analyzer metadata, has no real SDK use sites, and is not a projection contract. |
| input/output/optional/reserved | Existing SAL/MIDL | Use `_In_`, `_Out_`, `_Inout_`, `_Reserved_`, and their standard variants; no custom duplicates. |
| `RetVal` | MIDL `[retval]` or existing direction SAL plus `_Win32_Retval_` | Parameter. windows-rs parses `[retval]` from MIDL-generated header comments; C/C++-only declarations use the custom annotation. |
| `ComOutPtr` | `_COM_Outptr_` and standard SAL variants | Parameter. No new Win32 metadata annotation is required; shape-based inference is compatibility-only. |
| native constness | Native C/C++ `const` | Parameter or field. Const loss is a windows-rs RDL/winmd fidelity bug, not a header-annotation requirement. |
| scoped enum | guarded `enum class` | Emitted as `ScopedEnum`; normal branch retains the original ABI type. |
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

### Removed or deferred vocabulary

| Semantic | Decision |
| --- | --- |
| `IgnoreIfReturn` | Remove. Neither CsWin32 nor windows-rs consumes it, including the `CreatePipe` sidecars. |
| `FreeWith` | Remove. Allocated producer outputs use `RAIIFree`; cleanup is not attached to pointer typedefs. |
| `DoNotRelease` | Remove. Plain handles are borrowed unless a producer site carries ownership metadata. |
| custom COM out-pointer annotation | Remove. Use `_COM_Outptr_`, its standard variants, IID/PPV conventions, or explicit existing SAL. |
| `NotNullTerminated` | Remove. Correct declarations that use a string typedef for non-string data. Use an appropriately typed pointer plus ordinary SAL count/byte-count annotations. |
| `NativeArrayInfo` and `MemorySize` fallbacks | Remove. SAL's purpose is to express buffer counts, capacities, and byte sizes; fix SAL capture instead of defining duplicate metadata annotations. |
| `NativeArrayInfo.CountFieldName` | Defer with the rest of field-array projection. `CERT_INFO::rgExtension` is descriptive metadata today, but neither CsWin32 nor windows-rs provides a field-array projection. |
| `NativeInheritance` | Do not add for `MONITORINFOEXW`; the SDK already expresses the C++ base and equivalent C layout prefix, and both metadata baselines preserve it. Retain the vocabulary only if a separate, proven source gap is found. |
| `ReducePointerLevel` for `UCharIterator::move` | Do not use. windows-rs already emits the correct callback field pointer level; only implied pointer direction needs correction. |
| `ProjectAs` | Remove from the proposed vocabulary. No current win32metadata sidecar uses it. Preserve native typedef identity and use `AssociatedEnum` for the proven enum-specific use-site relationship. |
| `AssociatedConstant` | Remove. CsWin32 alone consumes it by copying `SERVICE_NO_CHANGE` into an enum and suppressing the global constant; windows-rs ignores it. Put the value directly in each guarded scoped metadata enum instead. |
| `StructSizeField` | Defer. No equivalent SAL annotation was found, but neither CsWin32 nor windows-rs currently consumes the metadata. Reintroduce only with a concrete projection behavior and tests. |
| `NativeEncoding` | Remove. The only windows-rs use found selects ANSI dependencies for string constants; CsWin32 does not consume it. Declare guarded constants with their real `char`/`wchar_t` type. |
| `Ansi` / `Unicode` | Remove. win32metadata infers them from A/W naming, but neither current projection consumes the attributes. |
| `CanonicalName` | Remove from the header vocabulary. It renames callback typedefs inside the scraper and is not projection metadata. Resolve the public callback name from the native typedef-alias graph. |
| `ReducePointerLevel` | Remove. It rewrites the emitted type to compensate for callback/pointer parsing. Correct the parser or use the correct typedef in a guarded metadata declaration. |
| `StaticLibrary` | Do not expand without a canonical current sidecar whose functional consumer behavior is demonstrated. |

## Enum and constant migration

Synthetic enums from `enums.json` become guarded SDK declarations. Normal compilation
must preserve the original integer ABI:

```cpp
#ifdef WIN32METADATA
#pragma push_macro("MODE_A")
#undef MODE_A
enum class MODE : DWORD {
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
- Put loose constants directly into each guarded scoped metadata enum where projections
  need them. Scoped enums permit the same spelling, such as `SERVICE_NO_CHANGE`, in
  multiple semantic enum types without a C++ name collision.
- Metadata-only constants use guarded annotated `constexpr`/`const` declarations while
  preserving the ordinary macro.

## HANDLE ownership

Handle typedefs do not carry cleanup ownership or automatic-close behavior. APIs that
natively use `HANDLE` remain `HANDLE`, and ownership is attached only to a producer
return or output parameter:

```cpp
BOOL WINAPI OpenPrinterW(
    _In_ LPWSTR name,
    _Out_
    _Win32_RAIIFree_(ClosePrinter)
    _Win32_InvalidHandle_(0)
    _Win32_InvalidHandle_(-1)
    HANDLE *printer);
```

Do not create `PRINTER_HANDLE`, `HEAP_HANDLE`, or similar metadata-only pseudo types.
Absence of `RAIIFree` means borrowed. `GetProcessHeap`, for example, requires no custom
annotation because its returned `HANDLE` is not automatically closed.

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
| `enums.json` | Guarded scoped enum declarations and direct enum typing; include required loose constants directly as guarded members. |
| `functionPointerFixups.json` | Replace with callback typedef-alias resolution and correct pointer-depth handling in the generator; use a guarded corrected declaration only when the SDK declaration itself is unsuitable for metadata. |
| `emitter.settings.rsp --memberRemap` | Correct guarded declaration/name in the header; use an annotation only when the native spelling must remain different. |
| scraper type/tag remaps | Correct typedef/tag relationship in headers; namespace-qualified C++ types remain native. |
| exclusions | Correct header guards or metadata-only exclusion annotation if the declaration truly must not be emitted. No silent consumer list. |
| array/string/size overrides | Correct the declaration type and existing SAL/MIDL contract; do not add parallel Win32 buffer annotations. |
| COM/manual metadata | Guarded declarations and method/parameter annotations in the authoritative header. |
| documentation mappings | Documentation tooling concern; not required for functional winmd equivalence. |
| removed legacy APIs | Recover the exact historical declaration from an authoritative SDK and place it in a guarded metadata-only legacy header when compatibility requires it. |

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
- Do not synthesize values absent from the current SDK. Recover them from an
  authoritative released SDK or baseline metadata and record that source.
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
- `Retained` remains metadata because CsWin32 uses it to suppress lifetime-unsafe
  overloads. windows-rs consumer policy remains unresolved.
- `CanReturnErrorsAsSuccess` and `CanReturnMultipleSuccessValues` collapse to
  `_Win32_PreserveResult_`. Their documentation rationale differs, but their functional
  projection requirement is the same: do not transform or discard the exact result.
  `_Success_` and `_Return_type_success_` remain useful static-analysis predicates but
  do not express this projection rule.
- `EnumWindows` must not carry `SupportsLastError`; preserve its raw `BOOL` result
  because `FALSE` can mean intentional callback termination.

### Agility

There is no general SAL or COM declaration syntax for runtime agility, and adding
`IAgileObject` inheritance would alter the declared contract. Keep
`_Win32_Agile_`, but require an authoritative component-owned assertion for
each interface. Do not infer agility from `ID2D*`, `ID3D*`, `IDWrite*`, or `IDXGI*`
name patterns. In particular, revisit existing D3D annotations because some device
context and allocator objects are not thread-safe.

### Struct size fields

No SAL annotation specifically identifies a field as the structure's initialization
size. The current win32metadata pipeline infers `StructSizeField` from a `cbSize` field
and carries exceptions for `BLOB` and `BSTRBLOB`, but neither CsWin32 nor windows-rs
currently consumes the resulting metadata. Defer a source annotation until a projection
defines concrete initializer behavior, including versioned structures that intentionally
accept an older size.

### Obsolete fields

Prefer standard, metadata-only guarded C++ `[[deprecated]]` syntax and teach the Clang
pipeline to emit `ObsoleteAttribute`. `IMAGE_OPTIONAL_HEADER32::LoaderFlags` and the
64-bit equivalent are the canonical examples.

### Enums and associated constants

`ENUM_SERVICE_TYPE`, `SERVICE_START_TYPE`, and `SERVICE_ERROR` are guarded synthetic
enums because the SDK exposes `DWORD` parameters and macro constants. Add
`SERVICE_NO_CHANGE` directly to each guarded scoped enum. CsWin32's current
`AssociatedConstant` behavior already copies that loose constant into the projected enum
and suppresses the global constant; windows-rs does not consume the attribute. Encoding
the desired result directly removes the custom relationship metadata.

### Documentation

Documentation attributes are not required for functional winmd equivalence. The
follow-up is to revisit scraping windows-docs and the stale
`Microsoft.Windows.SDK.Win32Docs` package process, which appears to have required a
manual merge/cross-reference step.

## Native fidelity that must supersede the NuGet baseline

The unified pipeline must preserve fixes already present in direct windows-rs
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

These are expected differences from the old NuGet winmd, not acceptable fidelity gaps.

## Reviewed API-specific conclusions

| Example | Implementation conclusion |
| --- | --- |
| `CoGetClassObject` | Add only the `CLSCTX` association. `CLSCTX` already exists in `shared/WTypesbase.h`; use existing COM output SAL. |
| `AddFontResourceExW` | Use a guarded synthetic enum because the semantic enum is not already declared in the header. |
| `ADsBuildVarArrayInt` | No redundant `_In_`/`_Inout_` header edits. Fix windows-rs handling of SAL semantic defaults. |
| `WsRequestReply` | The earlier parameter-name mismatch was a transcription/comparison issue, not a metadata annotation requirement. |
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
- interfaces, methods, UUIDs, and agility;
- last-error and success semantics;
- supported OS;
- callback canonical names;
- repeatable metadata such as invalid handle values.

Any difference affecting generated bindings or safe resource use is a functional gap and
requires a source syntax, consumer behavior, patch, and regression test.

## Implementation plan

### Phase 1: freeze the reviewed vocabulary

1. Remove `IgnoreIfReturn`, `FreeWith`, `DoNotRelease`, `NotNullTerminated`,
   `AssociatedConstant`, `NativeEncoding`, `Ansi`, `Unicode`, `CanonicalName`,
   `ReducePointerLevel`, all custom array/size annotations, and the custom COM
   out-pointer annotation from the staged header, parser, fixtures, and documentation.
2. Mark `CountFieldName`, `StructSizeField`, and `NativeInheritance` as deferred unless
   a concrete consumer and canonical gap are demonstrated.
3. Use MIDL `[retval]` where authoritative and `_Win32_Retval_` only for C/C++-authored
   declarations that lack the MIDL-generated comment.
4. Normalize function, return, parameter, and field annotations to SAL-style prefix
   placement. Do not use post-declarator return annotations.
5. Keep explicit annotations only for agility, producer ownership/invalid values,
   retained parameters, exact-result behavior, guarded enum associations, and other
   semantics that existing C/C++/SAL/MIDL cannot express.

### Phase 2: complete windows-rs source fidelity

1. Preserve SAL semantic defaults and native constness through final winmd emission.
2. Preserve `_NullNull_terminated_` and MIDL-generated `[retval]` comment semantics.
3. Preserve compiler-derived alignment and constant types with regression coverage.
4. Add standard `[[deprecated]]` to `ObsoleteAttribute` handling.
5. Add or confirm consumer tests for `Retained`, agility, exact-result preservation,
   and producer-site ownership.
6. Retain the direct-generation behavior for `EnumWindows` and `LocalFree`.

### Phase 3: patch canonical SDK examples

1. `OpenPrinterW`: remove `PRINTER_HANDLE`; annotate raw `HANDLE*` with
   `RAIIFree(ClosePrinter)` and invalid values `0` and `-1`.
2. `CoGetClassObject`: associate `dwClsContext` with the existing `CLSCTX` declaration;
   use existing COM output SAL.
3. `AddFontResourceExW`: add the reviewed guarded enum and associate the flags use.
4. `WAVEHDR::lpData`: use a non-string pointer type and existing byte-count SAL.
5. `AcceptSecurityContext`: preserve the native `SECURITY_STATUS` return and add
   `_Win32_PreserveResult_`; do not introduce `ProjectAs`.
6. `PTOP_LEVEL_EXCEPTION_FILTER`: make the generator resolve the public callback name
   from the typedef-alias graph without a header annotation.
7. Service configuration enums: add guarded enum declarations, parameter associations,
   and direct `SERVICE_NO_CHANGE` members.
8. `CM_NOTIFY_FILTER`: defer struct-size projection metadata until a consumer exists.
9. `IMAGE_OPTIONAL_HEADER32/64::LoaderFlags`: add guarded standard deprecation syntax.
10. Agile interfaces: patch only after component-owner confirmation.

### Phase 4: migrate the remaining sidecars by family

1. Ownership and invalid values at producer sites.
2. Guarded enum declarations, direct members, and parameter associations.
3. Result behavior and retained parameters.
4. Correct native pointer types and existing SAL count/byte-size/string semantics.
5. Generator callback-alias and pointer-depth fixes.
6. Obsolete, agility, and other proven type-level semantics.
7. Import library, last error, supported OS, and documentation-source work.

For each family, require a canonical header example, source-to-RDL test, RDL-to-winmd
test, generated binding test where behavior changes, and logical comparison to both the
NuGet reference and current direct windows-rs output.

### Phase 5: equivalence and rollout

1. Generate x86, x64, and arm64 metadata from a clean patched SDK.
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

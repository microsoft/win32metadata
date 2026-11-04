# Shift-Left Win32 Metadata Annotation Specification

## Status

This document defines the SDK source contract for Win32 metadata consumed by C# and
windows-rs toolchains. It specifies annotation spelling, placement, and meaning,
independently of either reader's implementation status. A declaration reaching a
compiler AST does not establish that a reader preserves its semantics in final
metadata. Unsupported contract features must be reported, not silently discarded
or redefined to match a reader's current limitations.

Metadata is generated from Windows SDKs that ship. The SDK selected for a metadata
release defines its API surface. Headers and APIs absent from that SDK, including
deprecated or experimental surfaces removed from the SDK, are omitted from the
generated metadata. Consumers that require those surfaces must continue using metadata
generated from an older SDK.

API-specific metadata belongs in the owning SDK header or authoritative IDL.
Sidecars may configure global generation policy and parser/tooling fixups; they
must not be the permanent source of an API's semantic contract.

Temporary SDK changes use the ingestion patch system in `generation/WinSDK/patches`.
Patch authoritative IDL before MIDL when it produces the consumed header; patch a
directly consumed header after MIDL. Do not patch regenerated output to bypass its
owning IDL. If that IDL is unavailable in the selected SDK, the affected fact remains
explicitly deferred rather than moving to a generated-header patch or a new semantic
sidecar. Retire each patch when the corresponding SDK change ships.

## Non-negotiable rules

1. Metadata must not change the native ABI: no layout, calling convention, mangling,
   parameter count, native type, vtable, or exported symbol changes.
2. Ordinary SDK compilation sees semantic annotations and metadata-only enum helpers
   as empty. Metadata transport must not add ordinary-consumer declarations or symbols.
3. Metadata-only declarations are guarded by `WIN32METADATA`.
4. Existing genuine SDK typedefs may be annotated. New API-specific pseudo handles
   such as `PRINTER_HANDLE` must not be introduced.
5. Resource producers carry cleanup and invalid-value metadata only on their return or
   output parameter. Plain `HANDLE` and handle typedefs do not imply automatic cleanup.
6. Header import-library annotations are authoritative. Import-library scanning remains
   the default.
7. Keep patches with the owning SDK artifact and apply them in the appropriate
   pre-MIDL or post-MIDL phase. Do not maintain a second patch series under `docs`.
8. Existing C/C++, SAL, MIDL, and compiler semantics are preferred over custom
   annotations. Do not add redundant `_In_` to scalars or `_Inout_` to unannotated
   pointers: those are the SAL semantic defaults. Capture existing native SDK/SAL/MIDL
   facts even when old metadata omitted them; review exact metadata differences rather
   than suppressing those facts to retain old omissions.
9. Logical equivalence to the NuGet winmd is the target only where the NuGet metadata is
   correct. Direct windows-rs fixes for native alignment, compiler-typed constants,
   `EnumWindows`, and `LocalFree` must not be regressed.
10. The selected shipped SDK is authoritative for API availability. Do not carry
    forward copied headers or declarations removed from that SDK. Metadata-only
    declarations may represent macros, inline helpers, constants, or exports that are
    part of the selected SDK, but they must not resurrect APIs absent from it.
11. A custom annotation must not override a conflicting native, SAL, or MIDL fact.
    Correct the authoritative declaration instead. Readers diagnose disagreements
    with source locations; legacy override syntax is not part of this contract.

## Transport and vocabulary

The ingested SDK defines the vocabulary in
`RecompiledIdlHeaders/shared/win32metadata_annotations.h`:

```cpp
#if defined(WIN32METADATA) && defined(__clang__)
#define _WIN32META_ANNOTATION_(...) \
    __attribute__((annotate("Win32Metadata." __VA_ARGS__)))
#else
#define _WIN32META_ANNOTATION_(...)
#endif
```

The `Win32Metadata.` payload prefix identifies this vocabulary without claiming
unrelated compiler annotations. Public `_Win32_*` macros are the source contract;
the shared header owns their Clang transport. Readers must preserve both the
annotation's meaning and any native declarations or expressions referenced by its
arguments, rather than treating compiler-evaluated integers as declaration identity.

Lifecycle metadata uses one variadic source annotation. In Clang metadata mode its
transport retains a reference to the cleanup function and the invalid-value
expressions:

```cpp
#define _Win32_RAIIFree_(cleanup, ...) \
    _WIN32META_ANNOTATION_("RAIIFree", sizeof(&(cleanup)), ##__VA_ARGS__)
```

The first argument identifies the cleanup function and the optional remaining arguments
identify invalid values:

```cpp
_Win32_RAIIFree_(SysFreeString)
_Win32_RAIIFree_(CloseHandle, 0, INVALID_HANDLE_VALUE)
```

The cleanup argument must resolve to the native cleanup declaration. For each
invalid value, use the declaration's preprocessor context and compiler constant
evaluation, preserving the expression's native width and signedness. Emit one
`RAIIFreeAttribute` plus one `InvalidHandleValueAttribute` per supplied value.
Unresolved cleanup names, non-constant values, and values that cannot be represented
in the metadata contract are errors. Do not infer the cleanup function from the
numeric result of `sizeof`.

Both toolchains enable `WIN32METADATA` when consuming annotated headers. Unknown
names in this vocabulary, malformed arguments, valued-versus-valueless mismatches,
incorrect targets, and conflicting facts are errors with source locations.
Unsupported contract features require explicit source-located diagnostics and
must not be reported as successfully preserved. Repeat an annotation only where
explicitly permitted.

Custom names use an explicit `_Win32_` owner prefix and PascalCase semantic names. For
example, use `_Win32_SetLastError_`, `_Win32_ImportLibrary_(...)`,
`_Win32_Retval_`, and `_Win32_Retained_`.

IDL `[retval]` remains authoritative and reaches MIDL-generated headers in comments
such as `/* [retval][out] */`; readers must preserve it. Do not add a duplicate custom
retval annotation to generated headers or convert hand-authored C++ to IDL merely
to express it. C/C++-authored declarations without an authoritative MIDL marker may
combine ordinary direction SAL with the fallback `_Win32_Retval_`:

```cpp
virtual HRESULT STDMETHODCALLTYPE GetDesc(
    _Out_ _Win32_Retval_ DXGI_ADAPTER_DESC* pDesc) = 0;
```

`_Win32_Retval_` has the payload name `RetVal`; the different capitalization of the
source macro does not define a second semantic. It selects a projected return and
does not replace direction, optionality, or COM output SAL.

## Declaration placement

### Functions and methods

Function metadata and metadata describing the return value precede the complete
declaration. Clang attaches a prefix `annotate` attribute to the `FunctionDecl`; the
reader maps return-oriented annotations from that declaration to the
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
    DWORD count);
```

`_Out_writes_bytes_(cbBuf)` describes a buffer capacity of `cbBuf` bytes.
`_Out_writes_bytes_to_(cbBuf, *pcbWritten)` additionally describes the initialized
byte extent returned in `*pcbWritten`. The optional-buffer spellings are
`_Out_writes_bytes_opt_` and `_Out_writes_bytes_to_opt_`, respectively. For an
illustrative API with a byte-count output:

```cpp
BOOL WINAPI ReadBytes(
    _Out_writes_bytes_to_(cbBuf, *pcbWritten) BYTE* buffer,
    DWORD cbBuf,
    _Out_ DWORD* pcbWritten);
```

Do not place custom return annotations after the closing parenthesis.

`_Win32_ContainsInteriorPointers_` is valid only on a caller-owned buffer parameter,
before its type alongside ordinary output/inout SAL. Clang attaches it to the
`ParmVarDecl`, not to the containing function or the buffer's record type:

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

Consumers reject values, arguments, duplicates, and placement on functions, return
values, fields, records, or typedefs with source-located diagnostics. A parameter must
be a pointer to caller-owned output/inout buffer storage; authors must verify the
same-allocation relationship from the API contract, not infer it from pointer fields.

### Records, interfaces, and enums

Attributes appear between the declaration keyword and name.

```cpp
struct _Win32_SupportedOS_10240_ DESCRIPTION {
    DWORD cbSize;
};
```

```cpp
enum _Win32_SupportedOS_10240_ [[clang::flag_enum]] OPTION : unsigned long {
    OPTION_NONE = 0,
};
```

### Typedefs and callback aliases

Type metadata precedes the typedef.

```cpp
_Win32_SupportedOS_10240_
typedef BOOL(WINAPI *PUBLIC_CALLBACK)(DWORD value);
```

### Authoritative IDL

Use native MIDL attributes such as `[in]`, `[out]`, `[optional]`, and `[retval]`
where they express the fact. Additional Win32 semantics must be authored in that
same IDL and survive regeneration without changing the native ABI or RPC contract.
For example, preserve a field's native `VARTYPE` storage while associating it with
an existing enum:

```idl
[annotation("_Win32_AssociatedEnum_(VARENUM)")] VARTYPE vt;
```

The named IDL transport helpers carry existing annotations to precise targets
in generated C++:

| Helper | Target |
| --- | --- |
| `_Win32_AnnotateMethod_(Interface::Method, annotation)` | The named method, not its interface or every method in it. |
| `_Win32_AnnotateParameter_(Interface::Method, parameter, annotation)` | The parameter with that source name on the named method, not its return value or other parameters. |
| `_Win32_AnnotateField_(Record::field, annotation)` | The named field, not its containing record or other fields. |

Interface-level annotations must reach the owning interface declaration through
authoritative IDL; no public helper spelling is prescribed for that transport here.
These helpers introduce no new semantic vocabulary, and their presence in one
header does not establish support in another header or reader. Generated transport
declarations must be metadata-only and must not become projected APIs or supply
native layout.

## Attribute solution matrix

| winmd semantic | Header syntax | Valid target and consumer behavior |
| --- | --- | --- |
| `SetLastError` / P/Invoke `SupportsLastError` | `_Win32_SetLastError_` | Function. No existing SAL annotation means that an API sets thread last error; sets the ECMA-335 P/Invoke flag. |
| P/Invoke module override | `_Win32_ImportLibrary_("name.dll")` | Function. Lower-case DLL basename including `.dll`; overrides import-library scan results only where an override is needed. |
| `SupportedOSPlatform("windows...")` | One fixed `_Win32_SupportedOS_*_` macro from the menu below, or `_Win32_SupportedOS_BEGIN_(os)` / `_Win32_SupportedOS_END_()` for a [scoped default](#scoped-supportedos-defaults) | Function, method, record/interface, enum, typedef, or constant. The fixed macro supplies the canonical version string. An explicit annotation overrides scoped defaults. Constants require explicit annotations; they are not scope targets. |
| preserve exact return/result | `_Win32_PreserveResult_` | Function, method, or callback declaration. The projection must preserve the exact result; lower to standard `MethodImplAttributes.PreserveSig`, including callback `Invoke`. |
| `RAIIFree("CloseX")` and repeated `InvalidHandleValue(value)` | `_Win32_RAIIFree_(CloseX, invalid...)` | Producer function/method return or output parameter only. Resolve the cleanup declaration and compiler-evaluate the optional invalid-value expressions, including SDK macros such as `INVALID_HANDLE_VALUE`. Emit one cleanup association and one invalid-value attribute per supplied value. |
| `NullNullTerminated` | Existing SAL `_NullNull_terminated_` | Return, parameter, field, or typedef. No custom annotation is required. |
| `Retained` | `_Win32_Retained_` | Pointer parameter retained by the API beyond the function call. The caller must follow the API documentation to determine when the referenced storage may be released. Absence does not remove the address-stability requirement for consuming `ContainsInteriorPointers` output. |
| `ContainsInteriorPointers` | `_Win32_ContainsInteriorPointers_`, using `_WIN32META_ANNOTATION_("ContainsInteriorPointers")` | Caller-owned output/inout buffer parameter only. Emits `Windows.Win32.Foundation.Metadata.ContainsInteriorPointersAttribute()` with no arguments or values. Returned data may contain absolute native pointers borrowing storage within that same allocation. The allocation must remain alive and at a stable address continuously through native production and all pointer consumption/copying. Valueless, non-repeatable, not inherited. |
| array count/capacity/byte size | Existing SAL and native array declarations | Use `_In_reads_`, `_Out_writes_`, `_Inout_updates_`, their byte-count variants, and related standard forms. Do not define parallel Win32 annotations. |
| `AlsoUsableFor("TYPE")` | `_Win32_AlsoUsableFor_(TYPE)` | Typedef. |
| `AssociatedEnum("TYPE")` | `_Win32_AssociatedEnum_(TYPE)` | Parameter, return value, or field. Resolve the existing native enum or metadata-only group; retain the declaration's native type, width, signedness, and pointer depth. Do not add an association already established by actual enum typing. `__typefix` is analyzer metadata, not a projection contract. |
| `AssociatedConstant("NAME")` | `_Win32_AssociatedConstant_(NAME)` | Enum declaration or metadata-only group carrier. Associates a loose SDK constant with an enum without changing the constant's existing global spelling. Repeatable; precedes the group helper when that helper supplies the declaration. |
| input/output/optional/reserved | Existing SAL/MIDL | Use `_In_`, `_Out_`, `_Inout_`, `_In_opt_`, `_Reserved_`, and standard variants or their authoritative MIDL equivalents. No custom duplicates. |
| `RetVal` | MIDL `[retval]` or existing direction SAL plus `_Win32_Retval_` | Output parameter. Preserve the authoritative MIDL marker; the custom fallback is limited to hand-authored C/C++ without that marker. |
| `ComOutPtr` | `_COM_Outptr_` and standard SAL variants | Parameter. No new Win32 metadata annotation is required; shape-based inference is compatibility-only. |
| native constness | Native C/C++ `const` | Parameter or field. Loss in an intermediate representation or final winmd is a reader fidelity bug, not a header-annotation requirement. |
| native typedef identity | Genuine SDK `typedef` / native alias graph | Derive the declared type and alias chain from compiler facts. An emitted `NativeTypedefAttribute` is not a request for a `_Win32_NativeTypedef_` source annotation. Identity does not imply ownership, invalid values, or availability. |
| synthetic constant group | `_Win32_Enum_(Name, Storage, members...)` | Metadata-only group declaration over existing SDK constants. Emit an unscoped enum with the stated native integer storage and original member names. |
| synthetic flags group | `_Win32_FlagsEnum_(Name, Storage, members...)` | The same declaration helper with flags semantics. This is retained; it is not a duplicate per-declaration `_Win32_Flags_` marker. |
| scoped enum | Native `enum class` | Emitted as `ScopedEnum`. Existing scoped SDK enums are supported, but synthetic bags of constants use ordinary unscoped enums. |
| native flags enum | Existing `[[clang::flag_enum]]` or `DEFINE_ENUM_FLAG_OPERATORS` contract | Enum. Preserve native flags semantics; do not add `_Win32_Flags_`. |

### Supported OS macro menu

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
Add a custom annotation only where native syntax cannot express the additional
semantic. Wrong or missing SAL/MIDL is corrected at its authoritative source,
not overridden by a parallel annotation.

### Scoped SupportedOS defaults

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
        __attribute__((annotate("Win32Metadata." _WIN32META_OS_VERSION(os)))), \
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

This illustrates transport, not completed reader support. Clang pragma attributes
accumulate; the reader must implement the lexical/explicit resolution above rather
than treating accumulated values as multiple effective OS floors.
The subject filter is exactly `any(function, record, enum, type_alias)`: `typedef` is
not a valid pragma matcher; `type_alias` covers genuine typedefs and callback typedefs.
C++ `using` aliases can reach the compiler AST; that alone does not establish
end-to-end alias support in either reader.

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

#### Required reader coverage

These are contract acceptance cases, not claims of completed implementation or
validation in either toolchain.

| Case | Required result |
| --- | --- |
| Nesting and explicit precedence | Verify Vista -> Windows7 -> Vista -> no default, plus before/after absence and an explicit later-version annotation inside a scope. Also nest an earlier version inside a later one and use an earlier explicit value: lexical/explicit precedence must win, not greatest-version selection. |
| Pairing and diagnostics | Cover active/inactive conditional paths, unknown tokens, unmatched pops, unclosed scopes, cross-file pairing, invalid targets, and conflicting explicit annotations. Errors retain source locations. |
| Includes and expansions | Cover transitive and repeated includes, independently scoped included headers, and declaration-producing macros expanded in another file. No caller-default leakage or lost genuine explicit annotations. |
| Declaration shapes | Cover C and C++ functions, records, enums, genuine typedefs/callbacks, eligible nested types, and COM methods, without inferring member inheritance from a container annotation. Do not count AST-only C++ `using` coverage as reader support. |
| Native no-op behavior | Compile ordinary C/C++ with MSVC with and without `WIN32METADATA`, and Clang without it. Preserve native types, layouts, calling conventions, symbols, and vtables. |
| Final metadata | Read back effective annotations and required absence from final x86, x64, and ARM64 winmds, including COM methods and callbacks. Validate full-SDK and PCH/include reuse separately rather than extrapolating from a small fixture. |

### Excluded and deferred vocabulary

| Semantic | Decision |
| --- | --- |
| `IgnoreIfReturn` | Not included. Neither CsWin32 nor windows-rs consumes it, including the `CreatePipe` sidecars. |
| `FreeWith` | Not included. Allocated producer outputs use `RAIIFree`; cleanup is not attached to pointer typedefs. |
| `DoNotRelease` | Not included. Do not infer automatic cleanup from plain handles or typedef identity; follow the producer's contract. |
| `_Win32_Optional_`, `_Win32_ComOutPtr_`, `_Win32_Reserved_` | Not included. Correct optionality, COM output, and reserved status using SAL/MIDL at the owning declaration. They must not override contradictory SAL. |
| `_Win32_Flags_` | Not included. Use native enum flags facts or the retained `_Win32_FlagsEnum_` group helper. |
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
| `_Win32_NativeTypedef_` | Not a header annotation. Derive genuine typedef identity from native declarations; preserve nominal projection where required without inventing API-specific aliases or annotating identity already present in the compiler. |
| `ReducePointerLevel` | Not a header annotation. Correct callback/pointer parsing or use the correct typedef in a guarded metadata declaration. |
| `StaticLibrary` | Deferred until a canonical use and functional consumer behavior are defined. |

## Enum and constant migration

Synthetic bags of constants use the retained `_Win32_Enum_` and
`_Win32_FlagsEnum_` declaration helpers:

```cpp
#define EXAMPLE_MODE_DEFAULT 0
#define EXAMPLE_MODE_FAST    1

_Win32_Enum_(EXAMPLE_MODE, DWORD,
    EXAMPLE_MODE_DEFAULT,
    EXAMPLE_MODE_FAST);

void WINAPI SetExampleMode(
    _Win32_AssociatedEnum_(EXAMPLE_MODE) DWORD mode);
```

The helpers are empty outside metadata compilation. In metadata mode they may use
an annotated storage typedef as the compiler carrier; the emitted contract is an
unscoped enum, not a new native enum ABI or a scoped consumer name. The member
arguments reference existing SDK constants and their compiler-evaluated values.
Do not undefine or replace the original macros merely to repeat their values.

Rules:

- Use the original integer storage and keep native use-site types. Use
  `AssociatedEnum` when the declaration is an integer or integer typedef rather
  than the enum itself; matching widths or similar names do not prove enum identity.
- Resolve an existing enum/group before introducing another one. A genuine enum
  use needs no additional association. An integer typedef such as `VARTYPE` may
  still need an association with `VARENUM`; its native `unsigned short` storage
  must not be widened to that enum's storage.
- Prefer a bare visible type name in `_Win32_AssociatedEnum_(eAvrfResourceTypes)`.
  Retain an elaborated `enum` type spelling only where the declaration language
  actually requires it; do not require it on C++ uses.
- Keep helper members in the order of the native constants they describe unless
  there is a specific semantic ordering requirement.
- Preserve complete existing constant names as unscoped enum members so generated
  consuming code does not require scoped-name changes.
- Keep loose constants such as `SERVICE_NO_CHANGE` global and use repeatable
  `AssociatedConstant` annotations on each related enum. Do not duplicate the same
  unscoped enumerator name in multiple enums.
- Use `enum class` only when the SDK declaration is already scoped or a new native API
  intentionally defines scoped semantics; do not use it merely to wrap constants.
- Preserve `[[clang::flag_enum]]` and `DEFINE_ENUM_FLAG_OPERATORS` for native enums.
  `_Win32_FlagsEnum_` supplies the extra group declaration for loose constants,
  not a competing flags fact on an existing native enum.
- Metadata-only constants use guarded annotated `constexpr`/`const` declarations while
  preserving the ordinary macro.
- Place a group in an existing functional SDK header where its constants are
  already visible through the existing include closure. Do not add includes,
  copy definitions, or invent an ownership annotation just to select a projected
  namespace. Contributions to one logical group must agree on storage, flags,
  member identity, and values; equal values alone do not prove native identity.

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
Absence of `RAIIFree` does not authorize automatic cleanup and does not prove that
the caller has no documented cleanup obligation. `GetProcessHeap`, for example,
requires no custom annotation because its returned `HANDLE` must not be closed.

Invalid values are API-specific rather than a fixed global set. Use the SDK spelling
that expresses the API contract, such as `0` and `INVALID_HANDLE_VALUE`. The consumer
is responsible for macro expansion and constant evaluation in the producer
declaration's context.

Consumer/freeing APIs such as `LocalFree` retain their raw native signature. Do not use
generic invalid-handle success logic for them: `LocalFree` returns `NULL` on success and
the still-valid input handle on failure.

## Import-library precedence

1. `_Win32_ImportLibrary_` on the declaration.
2. Import-library scanning.
3. Configured default.

This permits headers to correct missing or incorrect `.lib` information without
duplicating the complete scan-derived mapping. Apply the same rule to every
header: an API found correctly by scanning needs no explicit annotation. A
missing or incorrect mapping requires an annotation on that API's owning
declaration, not a header-wide assumption or an API-specific sidecar.
Spell explicit module values as lower-case DLL basenames, for example
`_Win32_ImportLibrary_("api-ms-win-wsl-api-l1-1-0.dll")`. The spelling names the
import module, not a `.lib` filename or filesystem path.

## Source ownership

The owning SDK declaration supplies API-specific last-error, availability, import
override, ownership, invalid-value, enum-association, retained-pointer, and exact-result
facts. Put an annotation on the complete declaration or its applicable return,
parameter, or field; a referencing header or alias does not become its owner.

Native typedef/tag relationships, callback aliases, pointer levels, alignment,
packing, constant types, and native enum identities come from declarations and
compiler facts. Fix general reader defects in tooling rather than authoring those
facts again in an API-specific annotation or sidecar. Namespace-qualified C++
types remain native.

Correct array, string, direction, size, optionality, reserved, and COM-output
contracts in native types and SAL/MIDL. A metadata-only declaration may represent
an SDK macro or other supported source construct, but must preserve its native
meaning. Do not invent an unspecified exclusion annotation or a silent per-API
consumer list.

Retiring an existing semantic sidecar requires the replacement source contract to
reach final metadata. Until then, report the migration as incomplete; do not
silently drop facts, claim source coverage, or make the legacy sidecar part of
this SDK contract. Global settings and genuine parser/tooling fixups remain
separate from API-specific semantic data.

### Macro-only and non-owning declarations

Declaration annotations cannot attach to a preprocessor macro or to a header that merely
references a declaration owned elsewhere.

- For object-like constant macros, add a guarded annotated constant declaration when the
  value and native type are authoritative.
- For function-like macros, preserve the macro for normal compilation. A guarded
  metadata-only declaration requires a faithful callable/constant representation;
  no general annotated-macro transport is defined here. Unsupported forms remain
  explicit gaps rather than gaining invented declarations.
- Put supported-OS and ownership annotations on the header that owns the complete
  declaration, not on aliases or references.
- Do not synthesize declarations or values absent from the selected SDK.
- Pointer aliases such as `PSECURITY_DESCRIPTOR` do not own pointed-to memory. Use
  producer-specific return/parameter ownership.

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

The emitted attribute has
`AttributeUsage(AttributeTargets.Parameter, AllowMultiple = false, Inherited = false)`,
a parameterless constructor, and no named arguments. Its presence in an existing
winmd does not establish that either header reader supports its transport.

Canonical use sites include `EnumPrinterDriversA/W::pDriverInfo`,
`EnumServicesStatusExA/W::lpServices`, `GetTokenInformation::TokenInformation`,
and pointer-bearing package-ID/info result buffers. Annotate only the caller-owned
buffer parameter after verifying its same-allocation contract from the API and
result-layout documentation. Do not infer coverage from a header name, a pointer
field, or membership in one of these API families.

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

Do not invent declarations for package API variants absent from the selected SDK.
[GetCurrentPackageInfo3](https://learn.microsoft.com/windows/win32/appxpkg/appmodel/nf-appmodel-getcurrentpackageinfo3)
requires a supported pointer-bearing result contract before annotation; a generation-ID
discriminator alone does not establish one.

`GetPrinterDriver2A` is declared but documented to always return
`ERROR_NOT_SUPPORTED`, so only `GetPrinterDriver2W` has an annotated output contract.
Flat printer directory/name/registry-data outputs, `EnumPrinterKey` MULTI_SZ output,
separately allocated printer notification data, and pointer-bearing printer input
records are not blanket-annotated. These examples do not establish exhaustive
coverage of every Win32 interior-pointer-producing API.

### COM outputs

Use standard `_COM_Outptr_` SAL variants where present. Eligible IID/PPV pairs may be
recognized by convention. Do not introduce a custom Win32 COM-out-pointer annotation.

### String termination

- `WAVEHDR::lpData` is binary data and should not use a string typedef. In the
  `WIN32METADATA` declaration, spell it as an appropriately typed character/byte
  pointer and preserve its byte-count relationship with SAL.
- `GetVolumePathNamesForVolumeNameW` already carries `_NullNull_terminated_`. Fix the
  SAL-to-RDL-to-winmd preservation path; do not modify the SDK declaration.
- Represent non-string data, counted buffers, and double-NUL strings with the
  appropriate native pointer type and SAL. Do not preserve `NotNullTerminated`
  as a custom annotation merely because it appears in an older winmd.

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

`ENUM_SERVICE_TYPE`, `SERVICE_START_TYPE`, and `SERVICE_ERROR` use the retained
group helpers to describe unscoped enums over native macro constants. Keep
`SERVICE_NO_CHANGE` as a global constant and apply
`_Win32_AssociatedConstant_(SERVICE_NO_CHANGE)` to each related enum. This preserves
existing projected names without introducing duplicate unscoped enumerators.
Keep the API parameters as native `DWORD` with the applicable enum association.

### Documentation

Documentation mappings are a documentation-tooling concern. They do not replace
functional SDK annotations and are not required for functional winmd equivalence.

## Native fidelity requirements

The unified pipeline must preserve native behavior represented by direct windows-rs
generation:

1. Read `__declspec(align(...))`/Clang alignment independently from packing. `CONTEXT`
   is aligned to 16 on x64/arm64 and packed/aligned to 4 on x86.
2. Evaluate constants using compiler integer literal and conversion rules.
   High-bit `IO_REPARSE_TAG_*` constants must remain `u32`.
3. Keep `EnumWindows` as raw `BOOL` without unconditional last-error transformation.
4. Keep `LocalFree` as raw `HLOCAL`; `NULL` means success.
5. Preserve C/C++ constness through intermediate representations and final winmd,
   including `ConstAttribute` where applicable.
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

| Example | Contract requirement |
| --- | --- |
| `CoGetClassObject` | Add only the `CLSCTX` association. `CLSCTX` already exists in `shared/WTypesbase.h`; use existing COM output SAL. |
| `AddFontResourceExW` | Use the retained synthetic enum helper because the semantic enum is not already declared in the header; keep the native integer use with its enum association. |
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
| `VerifierEnumerateResource` | Keep `ULONG` parameters; use `_Win32_FlagsEnum_` for the loose flags constants and associate the existing `eAvrfResourceTypes` enum without restating `enum` in C++. Keep members in native declaration order. |
| `PROPVARIANT::vt` / `STATPROPSTG::vt` | Preserve native `VARTYPE`. If its typedef is integer storage rather than `VARENUM`, add only the enum association in authoritative `propidlbase.idl`; do not redefine or widen the typedef. |
| WSL imports | Use lower-case DLL basenames on APIs whose import mapping needs correction. Apply that scan-first policy consistently across all headers. |

## Consumer requirements

Both C# and windows-rs consumers must:

- parse annotations on functions, methods, returns, parameters, records, enums, fields,
  constants, and typedefs;
- preserve repeated attributes;
- validate annotation names, values, and targets;
- preserve native ABI types, calling conventions, and pointer depths; an enum
  association changes projection information, not native storage;
- resolve canonical callback aliases consistently at declarations and references;
- use annotations only while `WIN32METADATA` is enabled;
- emit the applicable standard metadata attributes, including those in
  `Windows.Win32.Foundation.Metadata`, and CLR flags such as `PreserveSig`;
- generate x86, x64, and arm64 metadata from the same annotated headers;
- preserve compiler-derived constant types, alignment, packing, and native constness;
- resolve annotation arguments against actual native declarations and evaluate
  constant expressions in the declaration's preprocessor/compiler context;
- apply SAL semantic defaults without requiring redundant header edits;
- retain raw signatures where metadata does not justify an opinionated transformation.

Each implementation must distinguish supported end-to-end semantics from transport-only
or unimplemented features. A C# reader gap does not narrow the windows-rs contract,
and a windows-rs reader gap does not authorize an API-specific sidecar.

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

Classify differences as native/SDK fidelity corrections, intentional contract
retirements, selected-SDK removals, projection-only behavior, deferred semantics,
or actionable functional gaps. Agile retirement and removal of APIs absent from
the selected SDK are not requests to restore old annotations or declarations.
Unexplained changes affecting bindings or safe resource use remain gaps.

## Conformance

For each supported annotation, verify source placement and arguments, native
no-op behavior, and effective final metadata on x86, x64, and ARM64. Cover
incorrect targets, conflicting SAL/MIDL, invalid arguments, unknown vocabulary,
and unresolved native references with source-located negative cases.

IDL annotations must survive regeneration with native signatures, layout, RPC
outputs, and existing SAL intact. Group helpers must preserve constant names,
values, storage, and associated use sites without adding ordinary-consumer
symbols. Ownership, retval, buffers, COM outputs, exact-result behavior, and
layout require projection regressions where their handling changes.

Transport fixtures, AST visibility, sidecar retirement, and a successful scrape
alone do not establish source-to-final-metadata support. Deferred semantics
remain explicit until that complete path exists.

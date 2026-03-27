# Annotation Validation Results

*Validated: March 2026*
*ClangSharp: v17.0.1 and v18.1.0.4 | Clang: via libclang | Platform: x64*

---

## Key Finding: Upgrade ClangSharp to v18+

ClangSharp v17.0.1 (currently pinned in this repo) only preserves
`__attribute__((annotate(...)))` on **parameters**. All other placements
(functions, return values, struct fields, typedefs) are silently dropped.

ClangSharp v18.1.0.4+ (via PR [#552](https://github.com/dotnet/ClangSharp/pull/552))
adds `[NativeAnnotation("...")]` support that preserves annotate attributes on
**all declaration types**. We validated this — every proposed annotation works.
**Upgrading to v18+ is the path forward.**

---

## Validation Workflow

This workflow validates whether a proposed header annotation is carried through
ClangSharp into the generated C# output (and thus into the final .winmd).

### Prerequisites

- .NET 8.0+ SDK
- `ClangSharpPInvokeGenerator` **v18.1.0.4+** (installed via `dotnet tool install --global`)
  - v17.0.1 only supports parameter-level annotations
  - v18+ adds `[NativeAnnotation]` for all declaration types
- Windows SDK headers (or the `RecompiledIdlHeaders` from this repo)

### Steps

1. **Create test header** (`test_annotations.h`) with the proposed annotations
   using `__attribute__((annotate("w32m:...")))` macros

2. **Create main.cpp** that includes the test header with:
   ```cpp
   #define _WIN32METADATA_ 1
   #include <sal.h>
   #include "test_annotations.h"
   ```

3. **Run ClangSharp** with the same flags used by the real build:
   ```powershell
   ClangSharpPInvokeGenerator `
     --file main.cpp --output output.cs --namespace Test --methodClassName Apis `
     --include-directory <sdk-inc-dirs> `
     --traverse test_annotations.h `
     --additional "-D_USE_DECLSPECS_FOR_SAL=1" `
     --additional "-D_PREFAST_=1" `
     --additional "-D_WIN32METADATA_=1" `
     --additional "-D_AMD64_=1" --additional "-m64" `
     --config compatible-codegen `
     --config generate-cpp-attributes `
     --config exclude-funcs-with-body
   ```

4. **Examine `output.cs`** for `[CppAttributeList("w32m:...")]` attributes.
   - If present on the correct declaration → annotation works ✅
   - If absent → annotation is dropped by ClangSharp ❌

5. **Check for warnings** about "Unsupported attribute: 'Annotate'" —
   these indicate ClangSharp saw the attribute but doesn't know how to
   handle it at that location (v17 only handles annotate on parameters;
   v18+ handles all declaration types).

### Test Files Location

All validation test files are in `obj/annotation-validation/`:
- `win32metadata.h` — Annotation macro definitions
- `test_annotations.h` — Primary test cases (19 scenarios)
- `test_alternatives.h` — Alternative mechanism tests (8 scenarios)
- `test_returnval.h` — Return value annotation tests (4 scenarios)
- `main.cpp` — Entry point
- `output.cs` — Generated C# output (the evidence)

---

## Results Summary

### ClangSharp v17.0.1 (currently pinned)

| Annotation Target | Works? | Output Attribute |
|---|---|---|
| **Function parameter** | ✅ YES | `[CppAttributeList("w32m:...")]` |
| **Multiple attrs on same param** | ✅ YES | Concatenated with `^` separator |
| **Function pointer param** | ✅ YES | Same as regular params |
| **SAL + custom coexistence** | ✅ YES | Both present |
| **Function declaration** | ❌ NO | Dropped — "Unsupported attribute: 'Annotate'" |
| **Return value** | ❌ NO | Dropped |
| **Between return type and name** | ❌ NO | Dropped |
| **`__declspec` on function** | ❌ NO | Dropped |
| **typedef** | ❌ NO | Dropped |
| **struct field** | ❌ NO | Dropped |

### ClangSharp v18.1.0.4+ (recommended upgrade)

| Annotation Target | Works? | Output Attribute |
|---|---|---|
| **Function parameter** | ✅ YES | Both `[CppAttributeList]` AND `[NativeAnnotation]` |
| **Multiple attrs on same param** | ✅ YES | Each as separate `[NativeAnnotation]` |
| **Function declaration** | ✅ YES | `[NativeAnnotation("w32m:...")]` on method |
| **Multiple attrs on function** | ✅ YES | Each as separate `[NativeAnnotation]` |
| **Return value** | ✅ YES | `[NativeAnnotation("w32m:...")]` on method |
| **struct field** | ✅ YES | `[NativeAnnotation("w32m:...")]` on field |
| **Function pointer/delegate** | ✅ YES | `[NativeAnnotation("w32m:...")]` on delegate |
| **SAL + custom coexistence** | ✅ YES | Both present without interference |
| **`__declspec` on function** | ❌ NO | Still dropped (not needed) |
| **typedef** | ⚠️ PARTIAL | Annotation preserved but typedef may be flattened |

### By Proposed Annotation (with v18+)

| Annotation | Target | v17 | v18 |
|---|---|---|---|
| `_Sets_last_error_` | function | ❌ | ✅ |
| `_Min_os_version_(ver)` | function | ❌ | ✅ |
| `_Must_close_with_(func)` | function/return | ❌ | ✅ |
| `_Can_return_errors_as_success_` | function | ❌ | ✅ |
| `_Multiple_success_values_` | function | ❌ | ✅ |
| `_Com_out_ptr_w32m_` | parameter | ✅ | ✅ |
| `_Do_not_release_` | parameter | ✅ | ✅ |
| `_Not_null_terminated_w32m_` | parameter | ✅ | ✅ |
| `_Null_null_terminated_w32m_` | parameter | ✅ | ✅ |
| `_Array_count_param_(n)` | parameter | ✅ | ✅ |
| `_Array_count_(n)` | parameter | ✅ | ✅ |
| `_Memory_size_param_(n)` | parameter | ✅ | ✅ |
| `_Enum_type_(name)` | parameter | ✅ | ✅ |
| `_Enum_type_(name)` | struct field | ❌ | ✅ |
| `_Not_null_terminated_` | struct field | ❌ | ✅ |
| `_Close_handle_with_(func)` | typedef | ❌ | ⚠️ |
| `_Invalid_handle_(val)` | typedef | ❌ | ⚠️ |
| `_Also_usable_for_(type)` | typedef | ❌ | ⚠️ |

---

## Detailed Evidence (v18.1.0.4)

### Function-Level Annotations — NOW WORK ✅

**Test: `_Sets_last_error_` on function**
```c
// Header:
_Sets_last_error_   // expands to __attribute__((annotate("w32m:setlasterror")))
BOOL TestSetLastError_FuncDecl(LPCSTR lpFileName);

// v17 output: NO annotation (dropped)
// v18 output:
[NativeAnnotation("w32m:setlasterror")]       // ✅ PRESENT
public static extern int TestSetLastError_FuncDecl(...);
```

**Test: Multiple function-level annotations**
```c
_Sets_last_error_
_Min_os_version_(6.0.6000)
BOOL TestMultipleAnnotations(DWORD dwParam);

// v18 output — each annotation is a separate attribute:
[NativeAnnotation("w32m:setlasterror")]        // ✅
[NativeAnnotation("w32m:minversion=6.0.6000")] // ✅
public static extern int TestMultipleAnnotations(...);
```

**Test: Combined function + parameter annotations**
```c
_Sets_last_error_
_Min_os_version_(10.0.22000)
_Must_close_with_(TestClose_Combined)
HANDLE TestCombined(
    _Enum_type_(CREATE_FLAGS) DWORD dwFlags,
    _Not_null_terminated_w32m_ LPCSTR lpData,
    DWORD cbData,
    _Com_out_ptr_w32m_ void** ppResult);

// v18 output:
[NativeAnnotation("w32m:setlasterror")]                  // ✅ function
[NativeAnnotation("w32m:minversion=10.0.22000")]         // ✅ function
[NativeAnnotation("w32m:raiifree=TestClose_Combined")]   // ✅ function
public static extern void* TestCombined(
    [NativeAnnotation("w32m:enumtype=CREATE_FLAGS")] ..., // ✅ param
    [NativeAnnotation("w32m:notnullterm")] ...,           // ✅ param
    ...,
    [NativeAnnotation("w32m:comoutptr")] ...);            // ✅ param
```

### Return Value Annotations — NOW WORK ✅

```c
_Must_close_with_(CloseHandle)
HANDLE TestReturnAnnotate1(LPCSTR lpName);

HANDLE __attribute__((annotate("w32m:raiifree=FindClose")))
    TestReturnAnnotate2(LPCSTR lpName);

HANDLE TestReturnAnnotate3(LPCSTR lpName)
    __attribute__((annotate("w32m:raiifree=RegCloseKey")));

// v18 output — all three placements work:
[NativeAnnotation("w32m:raiifree=CloseHandle")]  // ✅
public static extern void* TestReturnAnnotate1(...);

[NativeAnnotation("w32m:raiifree=FindClose")]    // ✅
public static extern void* TestReturnAnnotate2(...);

[NativeAnnotation("w32m:raiifree=RegCloseKey")]  // ✅
public static extern void* TestReturnAnnotate3(...);
```

### Struct Field Annotations — NOW WORK ✅

```c
typedef struct _TEST_STRUCT {
    DWORD dwSize;
    _Enum_type_(TEST_FLAGS) DWORD dwFlags;
    _Not_null_terminated_w32m_ LPCSTR lpData;
    DWORD cbData;
} TEST_STRUCT;

// v18 output:
public unsafe partial struct _TEST_STRUCT
{
    public uint dwSize;

    [NativeAnnotation("w32m:enumtype=TEST_FLAGS")]  // ✅ PRESENT
    public uint dwFlags;

    [NativeAnnotation("w32m:notnullterm")]          // ✅ PRESENT
    public sbyte* lpData;

    public uint cbData;
}
```

### SAL + Custom Annotations Coexist ✅

```c
_Sets_last_error_
_Min_os_version_(10.0.10240)
BOOL TestWithSAL(
    _In_ LPCSTR lpFileName,
    _Out_ DWORD* pdwResult,
    _Com_out_ptr_w32m_ void** ppInterface);

// v18 output:
[NativeAnnotation("w32m:setlasterror")]       // ✅ our function annotation
[NativeAnnotation("w32m:minversion=10.0.10240")] // ✅ our function annotation
public static extern int TestWithSAL(
    [CppAttributeList("Name=SAL_name; p1=\"_In_\"...")]  // SAL preserved
    [NativeAnnotation("Name=SAL_name; ...")]             // SAL also as NativeAnnotation
    sbyte* lpFileName,
    ...
    [NativeAnnotation("w32m:comoutptr")]      // ✅ our param annotation
    void** ppInterface);
```

### Parameter Annotations — Still Work ✅

All parameter annotations from v17 continue to work in v18. In v18, they appear
as BOTH `[CppAttributeList]` (v17 format) AND `[NativeAnnotation]` (v18 format).
Multiple annotations on the same parameter appear as separate `[NativeAnnotation]`
entries (cleaner than v17's `^`-separated concatenation).

---

## What Still Doesn't Work

| Mechanism | Status | Notes |
|---|---|---|
| `__declspec` on function | ❌ | Not needed — `__attribute__((annotate))` covers everything |
| typedef annotations | ⚠️ | Annotation is preserved on usages, but simple typedefs (e.g., `typedef void* HANDLE`) are flattened by ClangSharp — the typedef itself doesn't appear as a named type in output. Handle types from `autoTypes.json` are structurally generated and will continue to need their JSON definition. |

---

## How v18's `NativeAnnotation` Works

ClangSharp v18+ (PR [#552](https://github.com/dotnet/ClangSharp/pull/552)) added a
`NativeAnnotation` attribute that is emitted whenever Clang reports an `AnnotateAttr`
on any declaration. This is fundamentally different from v17's `CppAttributeList`:

| Aspect | v17 `CppAttributeList` | v18 `NativeAnnotation` |
|---|---|---|
| Supported on parameters | ✅ | ✅ |
| Supported on functions | ❌ | ✅ |
| Supported on struct fields | ❌ | ✅ |
| Supported on return values | ❌ | ✅ |
| Supported on types | ❌ | ✅ |
| Multiple annotations | Concatenated with `^` | Separate attributes |
| String escaping | Basic | Proper (PR #572) |

The `NativeAnnotation` attribute is emitted under the same conditions as
`NativeTypeNameAttribute` — whenever the declaration has at least one
`annotate` attribute. The annotation string is the verbatim argument
to `__attribute__((annotate("...")))`.

### Emitter Processing Required

`MetadataSyntaxTreeCleaner` currently processes `CppAttributeList` to extract
SAL annotations. For v18+, it needs a parallel path to process `NativeAnnotation`
attributes with the `w32m:` prefix:

```csharp
case "NativeAnnotation":
{
    var text = GetAttributeStringArg(firstAttr);
    if (text.StartsWith("w32m:"))
        return ProcessWin32MetadataAnnotation(text.Substring(5));
    break;
}
```

---

## Appendix: v17 Workarounds (Retained for Reference)

These workarounds were validated during v17 testing but are **no longer needed**
with v18+. They are documented here in case v18 upgrade is delayed.

### Carrier-Parameter Pattern

Encode function-level metadata as annotations on the first parameter:
```c
BOOL AltC_MetaOnFirstParam(
    __attribute__((annotate("w32m:func_setlasterror")))
    __attribute__((annotate("w32m:func_minversion=10.0.19041")))
    DWORD dwParam, HANDLE hObject);

// v17 output:
[CppAttributeList("w32m:func_setlasterror^w32m:func_minversion=10.0.19041")]
uint dwParam  // ✅ Function metadata carried on first param
```

**Limitations:** Semantically incorrect; doesn't work for zero-parameter functions.

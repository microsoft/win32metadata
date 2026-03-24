# Annotation Validation Results

*Validated: March 2026*
*ClangSharp: v17.0.1 | Clang: via libclang | Platform: x64*

---

## Validation Workflow

This workflow validates whether a proposed header annotation is carried through
ClangSharp into the generated C# output (and thus into the final .winmd).

### Prerequisites

- .NET 8.0+ SDK
- `ClangSharpPInvokeGenerator` v17.0.1 (installed via `dotnet tool install --global`)
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
   handle it at that location (it only handles annotate on parameters).

### Test Files Location

All validation test files are in `obj/annotation-validation/`:
- `win32metadata.h` — Annotation macro definitions
- `test_annotations.h` — Primary test cases (19 scenarios)
- `test_alternatives.h` — Alternative mechanism tests (8 scenarios)
- `main.cpp` — Entry point
- `output.cs` — Generated C# output (the evidence)
- `test.rsp` — Response file (not used due to @-syntax parsing issue)

---

## Results Summary

### By Declaration Target

| Annotation Target | Works? | Evidence |
|---|---|---|
| **Function parameter** | ✅ YES | Appears as `[CppAttributeList("w32m:...")]` on param |
| **Multiple attrs on same param** | ✅ YES | Concatenated with `^` separator |
| **Function pointer param** | ✅ YES | Same behavior as regular params |
| **SAL + custom coexistence** | ✅ YES | Both appear as separate CppAttributeList entries |
| **Function declaration** | ❌ NO | Dropped — "Unsupported attribute: 'Annotate'" |
| **Function (after param list)** | ❌ NO | Dropped |
| **Between return type and name** | ❌ NO | Dropped |
| **`__declspec` on function** | ❌ NO | Dropped |
| **typedef** | ❌ NO | Dropped; typedefs don't appear in output |
| **struct field** | ❌ NO | Dropped |

### By Proposed Annotation

| Annotation | Target | Works Natively? | Alternative |
|---|---|---|---|
| `_Com_out_ptr_w32m_` | parameter | ✅ YES | — |
| `_Do_not_release_` | parameter | ✅ YES | — |
| `_Not_null_terminated_w32m_` | parameter | ✅ YES | — |
| `_Null_null_terminated_w32m_` | parameter | ✅ YES | — |
| `_Array_count_param_(n)` | parameter | ✅ YES | — |
| `_Array_count_(n)` | parameter | ✅ YES | — |
| `_Memory_size_param_(n)` | parameter | ✅ YES | — |
| `_Enum_type_(name)` | parameter | ✅ YES | — |
| `_Sets_last_error_` | function | ❌ NO | Carrier-param or extraction |
| `_Min_os_version_(ver)` | function | ❌ NO | Carrier-param or extraction |
| `_Must_close_with_(func)` | function | ❌ NO | Carrier-param or extraction |
| `_Can_return_errors_as_success_` | function | ❌ NO | Carrier-param or extraction |
| `_Multiple_success_values_` | function | ❌ NO | Carrier-param or extraction |
| `_Close_handle_with_(func)` | typedef | ❌ NO | Extraction only |
| `_Invalid_handle_(val)` | typedef | ❌ NO | Extraction only |
| `_Also_usable_for_(type)` | typedef | ❌ NO | Extraction only |
| `_Enum_type_(name)` on field | struct field | ❌ NO | Extraction only |

---

## Detailed Evidence

### Parameter Annotations That Work

**Test: `_Com_out_ptr_w32m_` on parameter**
```c
// Header:
HRESULT TestComOutPtr(LPCSTR lpClsid, _Com_out_ptr_w32m_ void** ppv);

// Output.cs line 72:
public static extern int TestComOutPtr(
    [NativeTypeName("LPCSTR")] sbyte* lpClsid,
    [CppAttributeList("w32m:comoutptr")] void** ppv);  // ✅ PRESENT
```

**Test: Multiple annotations on same parameter**
```c
// Header:
HRESULT AltH_MultiAnnotParam(
    __attribute__((annotate("w32m:arraycountparam=1")))
    __attribute__((annotate("w32m:notnullterm")))
    __attribute__((annotate("w32m:enumtype=BUFFER_FLAGS")))
    DWORD* pBuffer, DWORD dwCount);

// Output.cs line 140:
public static extern int AltH_MultiAnnotParam(
    [CppAttributeList("w32m:arraycountparam=1^w32m:notnullterm^w32m:enumtype=BUFFER_FLAGS")]
    uint* pBuffer, ...);  // ✅ ALL THREE PRESENT, ^-separated
```

**Test: SAL and custom annotations coexist**
```c
// Header:
BOOL TestWithSAL(_In_ LPCSTR lpFileName, _Out_ DWORD* pdwResult,
                 _Com_out_ptr_w32m_ void** ppInterface);

// Output.cs line 116:
// lpFileName has SAL CppAttributeList: "Name=SAL_name; p1=\"_In_\"..."
// ppInterface has our CppAttributeList: "w32m:comoutptr"
// ✅ BOTH COEXIST
```

### Function-Level Annotations That FAIL

**Test: `_Sets_last_error_` on function**
```c
// Header:
_Sets_last_error_   // expands to __attribute__((annotate("w32m:setlasterror")))
BOOL TestSetLastError_FuncDecl(LPCSTR lpFileName);

// Output.cs line 38-40:
public static extern int TestSetLastError_FuncDecl(
    [NativeTypeName("LPCSTR")] sbyte* lpFileName);
// ❌ NO CppAttributeList — annotation completely dropped
```

**Test: `_Min_os_version_` on function**
```c
// Header:
_Min_os_version_(10.0.19041)
HRESULT TestMinVersion_FuncDecl(UINT uParam);

// Output.cs line 46-48:
public static extern int TestMinVersion_FuncDecl(uint uParam);
// ❌ NO CppAttributeList — annotation completely dropped
```

### The "Carrier Parameter" Workaround (Alternative C)

```c
// Header — put function metadata as annotations on first parameter:
BOOL AltC_MetaOnFirstParam(
    __attribute__((annotate("w32m:func_setlasterror")))
    __attribute__((annotate("w32m:func_minversion=10.0.19041")))
    DWORD dwParam,
    HANDLE hObject);

// Output.cs line 128:
public static extern int AltC_MetaOnFirstParam(
    [CppAttributeList("w32m:func_setlasterror^w32m:func_minversion=10.0.19041")]
    uint dwParam, ...);
// ✅ BOTH function-level annotations preserved on the first param!
```

---

## Alternative Approaches for Non-Working Cases

### Option 1: Carrier-Parameter Pattern (for function-level metadata)

Encode function-level metadata as annotations on the first parameter, using
a `func_` prefix to distinguish them from parameter-specific annotations.

**Pros:**
- Works through ClangSharp today without any tool changes
- Source of truth is in the header
- Multiple annotations stack correctly (^-separated)

**Cons:**
- Semantically incorrect — function metadata shouldn't be on a parameter
- Doesn't work for zero-parameter functions (no parameter to carry)
- `MetadataSyntaxTreeCleaner` needs logic to strip `func_` annotations
  from parameters and apply them to the containing method

**Macro design:**
```c
// In win32metadata.h — carrier-param versions
#define _Func_sets_last_error_ \
    __attribute__((annotate("w32m:func_setlasterror")))
#define _Func_min_version_(ver) \
    __attribute__((annotate("w32m:func_minversion=" #ver)))
#define _Func_must_close_with_(func) \
    __attribute__((annotate("w32m:func_raiifree=" #func)))

// Usage in header:
BOOL CreateFileA(
    _Func_sets_last_error_
    _Func_min_version_(5.1.2600)
    _In_ LPCSTR lpFileName,
    ...);
```

### Option 2: Header Extraction Tool (for all non-working cases)

A preprocessing step that scans headers for annotations and generates
the corresponding .rsp/json sidecar entries automatically.

**How it works:**
1. Headers contain annotations using `__attribute__((annotate(...)))` or
   custom macros (even if ClangSharp can't read them)
2. A lightweight Clang-based tool (or regex scanner) reads the headers
3. It extracts annotations and generates:
   - `WithSetLastError.rsp` entries from `_Sets_last_error_`
   - `supportedOS.rsp` entries from `_Min_os_version_`
   - `autoTypes.json` entries from `_Close_handle_with_`
   - `emitter.settings.rsp` remaps from `_Enum_type_` on struct fields
4. ClangSharp runs with the auto-generated sidecar files

**Pros:**
- Source of truth moves to headers (the goal)
- No ClangSharp modifications needed
- Works for ALL annotation types including struct fields and typedefs
- Generated sidecar files can be committed and diffed for review

**Cons:**
- Adds a build step
- Still uses sidecar files (but they're auto-generated, not hand-maintained)
- Extraction tool needs to be built and maintained

**This is the recommended approach for non-parameter annotations.**

### Option 3: ClangSharp Patch (longer-term)

Modify ClangSharp to preserve `__attribute__((annotate(...)))` on all
declaration types, not just parameters. This would be a PR to the
ClangSharp project.

**Pros:** Cleanest solution; annotations flow naturally through the pipeline
**Cons:** Requires external project change; uncertain acceptance timeline

---

## Recommended Strategy

| Annotation Category | Approach | Rationale |
|---|---|---|
| **Parameter annotations** | Direct `__attribute__((annotate(...)))` | Works natively ✅ |
| **Function-level metadata** | Carrier-parameter pattern OR extraction tool | Carrier works for functions with params; extraction for edge cases |
| **Type/typedef metadata** | Extraction tool | No workaround exists |
| **Struct field metadata** | Extraction tool | No workaround exists |

### Hybrid Implementation

Phase 1: Use direct parameter annotations for all parameter-level metadata
(~8 annotation types). This works TODAY with no tool changes.

Phase 2: Build a lightweight extraction tool that:
- Scans headers for all `_W32M_` / `_Sets_last_error_` / etc. macros
- Uses `clang -ast-dump` or regex to find annotated declarations
- Generates the corresponding .rsp entries
- Runs as the first step in the build pipeline

Phase 3 (optional): Submit a PR to ClangSharp to preserve annotate
attributes on all declaration types. If accepted, Phase 2 becomes
unnecessary.

---

## Appendix: How ClangSharp Processes Annotate Attributes

ClangSharp v17 only emits `CppAttributeList` for `__attribute__((annotate(...)))`
when the attribute is attached to a **parameter** in the Clang AST. This is because:

1. Clang's libclang exposes annotate attributes on all declaration types
2. But ClangSharp's `generate-cpp-attributes` handler only processes
   `CXCursor_ParmDecl` (parameter declarations) when collecting annotate attributes
3. For function-level, type-level, and field-level annotate attributes, ClangSharp
   logs the "Unsupported attribute: 'Annotate'" warning and skips them

The SAL annotations work because they are applied to parameters (`_In_`, `_Out_`,
etc.), not to functions or types. SAL's function-level annotations like
`_Return_type_success_` are handled through different mechanisms (not CppAttributeList).

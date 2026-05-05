# win32metadata: How Metadata Constructs Are Derived from Headers

This document describes, at a high level, how win32metadata derives each construct
in the output winmd from the original Windows SDK C/C++ headers.

---

## Pipeline Overview

```
SDK C/C++ Headers
      │
      ├──[ClangSharp]──────────> Generated C# (functions, structs, COM interfaces)
      │                               │
      ├──[ConstantsScraper]────> Generated C# (constants, enums)
      │                               │
      └──[Manual C# overrides]────────┤
                                      │
                              [Emitter (ClangSharpSourceToWinmd)]
                                      │
                                      ▼
                              Windows.Win32.winmd
```

**ClangSharp** parses headers through Clang, producing C# declarations for functions,
structs, COM interfaces, and typedefs. It operates on the Clang AST.

**ConstantsScraper** reads headers as raw text (line-by-line regex), extracting `#define`
constants and assembling enums. It operates on preprocessor constructs that don't exist
in the AST.

**The Emitter** (`ClangSharpSourceToWinmd`) compiles all the generated C# sources,
applies transformations (remaps, attribute additions), and writes the winmd.

---

## Types (Typedefs and Structs)

### How typedefs are discovered

The SDK declares types using the C pattern of a tag name paired with a typedef:

```c
typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES;
```

ClangSharp parses the AST and discovers `TypedefDecl` nodes. For each typedef whose
underlying type is a `TagType`, it records the tag→typedef relationship (e.g.,
`_SECURITY_ATTRIBUTES` → `SECURITY_ATTRIBUTES`). These relationships drive `--remap`
entries that tell ClangSharp to emit the public typedef name rather than the internal
tag name.

**Win32MetadataScraper** automates this discovery by walking the AST in a single pass,
finding all tag→typedef pairs, and resolving ambiguities using heuristics (strip `_`
prefix, strip `tag` prefix, case-insensitive matching). See
`docs/copilot/plans/auto-type-remappings-plan.md` for the full design.

### Handle types

The SDK declares handles using `DECLARE_HANDLE(FOO)`, which expands to:

```c
typedef struct FOO##__ { int unused; } *FOO;
```

These are pointer-to-opaque-struct typedefs. ClangSharp flattens the typedef during scraping — the wrapper struct in the winmd is *not* derived from the SDK's `DECLARE_HANDLE` expansion. Instead, the metadata tooling generates a value-type wrapper struct with RAII metadata (close function, invalid handle values, alias-for relationships) on top.

#### Current approach: `autoTypes.json`

`autoTypes.json` (~280 entries) lists each handle and value typedef with its underlying value type (`DECLARE_HANDLE`, `void*`, `IntPtr`, etc.), close API, invalid sentinel values, and `AlsoUsableFor` relationships. `NativeTypedefStructsCreator` reads the JSON and generates a C# wrapper struct per entry, decorated with `[NativeTypedef]`, `[RAIIFree]`, `[InvalidHandleValue]`, and `[AlsoUsableFor]` attributes.

#### Proposed approach: conditional `DECLARE_HANDLE` redefinition

See `docs/copilot/plans/handle-annotation-proposal.md` for the full proposal.

Under `_WIN32METADATA_`, `DECLARE_HANDLE` is redefined as a single-struct form that ClangSharp emits directly. SDK headers continue to use `DECLARE_HANDLE(NAME)` for handles with no metadata; handles with RAII metadata use the new `DECLARE_HANDLE_WIN32METADATA(NAME, ...)` macro that takes attribute annotations between `struct` and the name:

```cpp
#ifdef _WIN32METADATA_
  #undef DECLARE_HANDLE
  #define DECLARE_HANDLE(name) \
      struct [[clang::annotate("w32m::handle")]] name { void* Value; }
  #define DECLARE_HANDLE_WIN32METADATA(name, ...) \
      struct [[clang::annotate("w32m::handle")]] __VA_ARGS__ name { void* Value; }

  #define _Close_handle_with_(api)  [[clang::annotate("w32m::raii_free=" #api)]]
  #define _Invalid_handle_(val)     [[clang::annotate("w32m::invalid_handle=" #val)]]
  #define _Also_usable_for_(type)   [[clang::annotate("w32m::also_usable_for=" #type)]]
#else
  #define DECLARE_HANDLE_WIN32METADATA(name, ...) DECLARE_HANDLE(name)
  #define _Close_handle_with_(api)
  #define _Invalid_handle_(val)
  #define _Also_usable_for_(type)
#endif
```

In SDK headers:

```c
DECLARE_HANDLE(HWND);                         // No metadata; unchanged

DECLARE_HANDLE_WIN32METADATA(HMODULE,         // FreeLibrary; nullable
    _Close_handle_with_(FreeLibrary)
    _Invalid_handle_(0)
    _Also_usable_for_(HINSTANCE));

DECLARE_HANDLE_WIN32METADATA(HFILE,           // CloseHandle; INVALID_HANDLE_VALUE or NULL
    _Close_handle_with_(CloseHandle)
    _Invalid_handle_(-1)
    _Invalid_handle_(0));
```

ClangSharp v18+ preserves these as `[NativeAnnotation]` attributes on the generated struct. The emitter (`MetadataSyntaxTreeCleaner`) translates them to the existing managed attributes:

| Annotation | Translated to |
|---|---|
| `w32m::handle` | `[NativeTypedef]` |
| `w32m::raii_free=X` | `[RAIIFree("X")]` |
| `w32m::invalid_handle=N` | `[InvalidHandleValue(N)]` (one per occurrence) |
| `w32m::also_usable_for=T` | `[AlsoUsableFor("T")]` |

The winmd output is byte-identical to today's output. Both downstream projections (CsWin32 and windows-rs) read these attributes by name and require no changes.

#### Typedef-style handles and value wrappers

Handles declared via direct typedef (e.g., `typedef PVOID BCRYPT_ALG_HANDLE`) and non-handle value wrappers (`BOOL`, `BOOLEAN`, `HRESULT`, `NTSTATUS`, `LPARAM`, `WPARAM`, `LRESULT`, `BSTR`, `PSID`, `VARIANT_BOOL`) use a sibling macro that takes the underlying type:

```cpp
#ifdef _WIN32METADATA_
  #define DECLARE_TYPEDEF_WIN32METADATA(name, type, ...) \
      struct [[clang::annotate("w32m::handle")]] __VA_ARGS__ name { type Value; }
#else
  #define DECLARE_TYPEDEF_WIN32METADATA(name, type, ...) typedef type name
#endif
```

Examples:

```c
// shared/bcrypt.h  ← currently: typedef PVOID BCRYPT_ALG_HANDLE;
DECLARE_TYPEDEF_WIN32METADATA(BCRYPT_ALG_HANDLE, void*,
    _Close_handle_with_(BCryptCloseAlgorithmProvider));

// shared/minwindef.h  ← currently: typedef int BOOL;
DECLARE_TYPEDEF_WIN32METADATA(BOOL, int);

// shared/wtypes.h  ← currently: typedef OLECHAR *BSTR;
DECLARE_TYPEDEF_WIN32METADATA(BSTR, OLECHAR*,
    _Close_handle_with_(SysFreeString));
```

Same annotation surface as `DECLARE_HANDLE_WIN32METADATA`; the macros differ only in their normal-compilation expansion (one preserves `DECLARE_HANDLE`, the other preserves the original typedef form). Together the two macros cover all ~280 entries in `autoTypes.json` — after migration, the JSON file is removed entirely.

### Function pointers

Function pointer typedefs follow two patterns:

```c
typedef DWORD (WINAPI *LPTHREAD_START_ROUTINE)(LPVOID);   // already-pointer
typedef void CALLBACK TIMECALLBACK(UINT, ...);             // bare-function
```

Win32MetadataScraper discovers prototype→alias pairs and generates `--remap` and
`--reducePointerLevel` entries to normalize them into delegates.

---

## Functions

ClangSharp parses function declarations from the AST and generates C# `static extern`
methods with `[DllImport]` attributes. The DLL mapping comes from `libMappings.rsp`
(auto-generated by scanning `.lib` files) and `libMappingsManual.rsp` (overrides).

Additional function metadata is applied via memberRemap entries:
- `SetLastError` — from `WithSetLastError.rsp`
- OS version support — from `supportedOS.rsp`
- Parameter type overrides — from `emitter.settings.rsp`

---

## Constants

The ConstantsScraper reads header files as raw text, matching `#define` lines with regex
patterns. It extracts:

- **Integer constants**: `#define FOO 0x1234` → `public const int FOO = 0x1234;`
- **String constants**: `#define FOO "bar"` → `public const string FOO = "bar";`
- **GUID constants**: `DEFINE_GUID(...)` → `public static readonly Guid FOO = ...;`
- **Typed constants**: `#define FOO ((HRESULT)0x80000001L)` → typed constant

Constants are placed into namespaces based on which partition's headers they appear in.

---

## Enums

### Real C/C++ enums in SDK headers

The SDK headers contain ~8,600 real `enum` declarations. These are processed natively
by ClangSharp and appear directly as C# enums in the generated output:

```c
// In d3d12.h:
enum D3D12_COMMAND_LIST_TYPE {
    D3D12_COMMAND_LIST_TYPE_DIRECT  = 0,
    D3D12_COMMAND_LIST_TYPE_BUNDLE  = 1,
    D3D12_COMMAND_LIST_TYPE_COMPUTE = 2,
    D3D12_COMMAND_LIST_TYPE_COPY    = 3,
};
```

→ ClangSharp produces:
```csharp
public enum D3D12_COMMAND_LIST_TYPE {
    D3D12_COMMAND_LIST_TYPE_DIRECT  = 0,
    D3D12_COMMAND_LIST_TYPE_BUNDLE  = 1,
    D3D12_COMMAND_LIST_TYPE_COMPUTE = 2,
    D3D12_COMMAND_LIST_TYPE_COPY    = 3,
}
```

These require no special handling. ~393 of them use `DEFINE_ENUM_FLAG_OPERATORS(FOO)`
which the ConstantsScraper detects (text regex) to add `[Flags]`.

### Lifted enums (constants grouped into logical enums)

Many Win32 API surfaces use groups of `#define` constants where a proper enum type would
be more appropriate:

```c
#define FILE_ATTRIBUTE_READONLY   0x00000001
#define FILE_ATTRIBUTE_HIDDEN     0x00000002
#define FILE_ATTRIBUTE_SYSTEM     0x00000004
```

These are not enums in C — they're preprocessor constants. The metadata needs them as
a typed enum for language projections to provide a good developer experience.

#### Current approach: `enums.json`

`enums.json` (~37K lines, ~1,072 entries) defines each logical enum with its name,
flags attribute, member names/values, and which function parameters should use the type.
The ConstantsScraper reads the JSON, matches `#define` names, generates C# enum files
and remap entries.

#### Proposed approach: conditional enum declarations

See `docs/copilot/plans/enum-remapping-proposal.md` for the full proposal.

The `#define` groups are "lifted" into real C++ enums using conditional compilation:

```cpp
#ifdef _WIN32METADATA_
enum class [[clang::flag_enum]] FILE_ATTRIBUTE_FLAGS : DWORD {
    FILE_ATTRIBUTE_READONLY = 0x00000001,
    FILE_ATTRIBUTE_HIDDEN   = 0x00000002,
    FILE_ATTRIBUTE_SYSTEM   = 0x00000004,
};
DEFINE_ENUM_FLAG_OPERATORS(FILE_ATTRIBUTE_FLAGS)
#else
#define FILE_ATTRIBUTE_FLAGS DWORD
#endif
```

When `_WIN32METADATA_` is defined (during metadata generation), ClangSharp sees a real
C++ enum and processes it natively. The `#else` branch defines the name as a DWORD macro,
allowing function signatures to use the enum name unconditionally.

---

## COM Interfaces

ClangSharp parses COM interfaces from IDL-generated headers. The IDL compiler
(`midl`/`midlrt`) produces C/C++ headers with vtable-based interface declarations.
ClangSharp recognizes the COM patterns and generates C# interfaces with
`[Guid]` attributes.

The `RecompileIdlFilesForScraping` step recompiles IDL files to produce headers
optimized for ClangSharp consumption.

---

## Annotations and Attributes

### SAL annotations

SAL (Source-code Annotation Language) annotations like `_In_`, `_Out_`, `_Ret_maybenull_`
are already in SDK headers. ClangSharp preserves them as `[CppAttributeList]` attributes
(v17) or `[NativeAnnotation]` attributes (v18+). The emitter processes these to generate
managed attributes like `[In]`, `[Out]`, etc.

### Custom metadata annotations (`w32m:` prefix)

Additional metadata that isn't in the SDK headers today can be expressed as
`__attribute__((annotate("w32m:...")))` (or the C++11 syntax
`[[clang::annotate("w32m:...")]]`). These flow through ClangSharp v18+ as
`[NativeAnnotation("w32m:...")]`. The emitter processes annotations with the `w32m:`
prefix and converts them to the appropriate winmd attributes.

Defined annotations:

| Annotation | Target | Winmd effect |
|---|---|---|
| `_Sets_last_error_` | function | `[SetLastError]` on method |
| `_Min_os_version_(ver)` | function | `[SupportedOSPlatform]` |
| `_Must_close_with_(func)` | function | `[RAIIFree]` on return |
| `_Enum_type_(name)` | parameter, field | Changes type to named enum |
| `_Enum_return_(name)` | function | Changes return type to named enum |
| `_Com_out_ptr_` | parameter | `[ComOutPtr]` |
| `_Not_null_terminated_` | parameter, field | `[NotNullTerminated]` |
| `_Close_handle_with_(api)` | handle struct | `[RAIIFree("api")]` on struct |
| `_Invalid_handle_(val)` | handle struct | `[InvalidHandleValue(val)]` on struct (multiple allowed) |
| `_Also_usable_for_(type)` | handle struct | `[AlsoUsableFor("type")]` on struct |

The handle annotations are placed between `struct` and the name via the `DECLARE_HANDLE_WIN32METADATA(name, ...)` and `DECLARE_TYPEDEF_WIN32METADATA(name, type, ...)` macros described in the [Handle types](#handle-types) section.

See `docs/copilot/plans/shift-left-metadata-plan.md` for the full annotation design and
`docs/copilot/plans/handle-annotation-proposal.md` for the handle-specific proposal.

---

## Namespace Organization

Types are placed into namespaces based on the **partition** system. Each partition
(a directory under `generation/WinSDK/Partitions/`) defines which headers it includes
(`main.cpp`) and maps to a namespace (e.g., `Partitions/Foundation/` →
`Windows.Win32.Foundation`).

`requiredNamespacesForNames.rsp` provides overrides for types that need to be in a
specific namespace regardless of which partition's headers they're declared in.

---

## Sidecar Files

Several sidecar files provide metadata that isn't (yet) expressible in headers:

| File | Purpose | Shift-left status |
|---|---|---|
| `scraper.settings.rsp` | Type remaps, exclusions | Mostly auto-derived |
| `enums.json` | Synthetic enum definitions | Proposed: conditional enums |
| `autoTypes.json` | Handle type definitions | Proposed: header annotations |
| `emitter.settings.rsp` | Member remaps, enum additions | Proposed: header annotations |
| `WithSetLastError.rsp` | SetLastError functions | Proposed: `_Sets_last_error_` |
| `supportedOS.rsp` | OS version requirements | Proposed: `_Min_os_version_()` |
| `libMappings.rsp` | Function→DLL mappings | Auto-generated from .lib files |
| `documentationMappings.rsp` | Documentation URLs | Stays (external data) |
| `functionPointerFixups.json` | Fn ptr name fixes | Mostly auto-derived |

The shift-left strategy (`docs/copilot/plans/shift-left-metadata-plan.md`) aims to move
API-semantic metadata into the headers themselves, leaving only tooling configuration in
sidecar files.

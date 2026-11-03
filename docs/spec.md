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

The default scraper also checks incomplete native records, inaccessible copy
members, Unicode companion declarations and missing native type providers.
These compatibility checks run independently of opt-in header annotations and
native constant evaluation. Companion recovery may parse additional translation
units even when there is only one primary binding-generation call.

Native inventory uses compiler cursor handles and recorded traversal parents.
The checks resolve selected declarations through those parent paths instead of
eagerly walking every managed child subtree.
Incomplete-record analysis follows the same canonical native type graph,
including pointer depth, arrays, function signatures and by-value rejection.
Companion imports still require their complete native dependency validation.
Provider recovery retains the original semantic binding and shadow checks.

Set `WIN32METADATA_TIMING_DIRECTORY` to an absolute directory to retain per-worker
phase wall time, process CPU and parse/query/binding counters. Child intervals are
included in their parent; use self times when summing nested work. Worker count,
translation-unit parse count and binding-generation count describe different work.

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

These are pointer-to-opaque-struct typedefs. The metadata tooling recognizes them and
generates value-type wrappers with RAII metadata (close function, invalid values) from
`autoTypes.json`.

An explicit header `NativeTypedef` annotation gives a scalar or data-pointer alias
its own wrapper identity. Pointer storage ending in a forward-only native record
uses `void` as its pointee without changing pointer depth. Complete definitions,
including empty definitions and definitions appearing later in the translation
unit, retain their record identity. Ordinary record-pointer API uses remain typed.

### Function pointers

Function pointer typedefs follow two patterns:

```c
typedef DWORD (WINAPI *LPTHREAD_START_ROUTINE)(LPVOID);   // already-pointer
typedef void CALLBACK TIMECALLBACK(UINT, ...);             // bare-function
```

Win32MetadataScraper discovers prototype→alias pairs and generates `--remap` and
`--reducePointerLevel` entries to normalize them into delegates.
Bare-function typedefs also generate pointer reduction when there is no named
pointer alias: the delegate represents the first native function pointer, while
additional native pointer levels remain pointers in metadata. Already-pointer
typedefs do not receive this standalone reduction.

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

The opt-in `native-constant-values` path uses Clang's target-specific integer results.
Selection protects authored declarations and source-owned groups, then applies explicit
SDK-root-relative header priority, project partition/traversal order and native source
location. Names remain case-sensitive. The MSBuild `ConstantHeaderPriority` property
and CLI `--sdkRoot` / `--headerPriority` options supply this policy.

Logical-group proofs retain the compiler's actual macro or declaration reference,
independently of the projected member label. Literal expressions have no native
symbol identity. Each target supplies its own bindings. Only an exact source-family,
group and native-definition match permits compiler-bound consumption; competing
definitions selected by policy are reported separately. The conflict JSON stores
shared proofs once and includes selected/discarded locations, targets, types, values
and reasons; `WMC001` highlights type/value conflicts. Raw native facts are unchanged.

Protection includes ordinary unscoped source enums and the final published spelling
of `__forceconst__` fields. A logical member's native binding can consume its macro
even when its projected label differs. Unrelated definitions remain policy decisions.
Pure native aliases to enum declarations carry an exact compiler reference and a
matching source-enum proof. A redundant alias is consumed only when those published
names collide; case-only publication collisions never make native identities equal.
Arithmetic expressions, explicit conversions and differently named aliases remain
separate constants. Scoped enums do not claim global constant names. Diagnostics
retain transport and published spellings, native alias targets and projected storage
type differences.

Legacy aliases use the storage of their authoritative source declarations, including
ordinary native enums and logical header groups. Removing a redundant loose constant
does not discard that dependency's type or allow regex inference to recreate it.
`SourceDependencies` records this managed-declaration policy separately from native
consumption. A logical group's exact compiler-bound member retains its native scalar
storage for aliases, independently of the projected group's underlying type. The
report preserves both storage types and identifies that distinction. Conflicting
dependency storage across targets fails rather than guessing a single alias type.
This source-ownership path requires native facts or a successful opt-in header-types
source family. Ordinary legacy scraping without either retains its existing rules.

Renamed logical members retain both the projected declaration name and the exact
consumed macro's scalar storage for dependency lookup. A legacy definition of that
raw spelling uses the retained scalar type while keeping its own expression; this
does not bind the legacy definition to the native one or equate their values.
`NativeDependencies` records the compiler-bound origin and projected owner.
`LegacyDependencyPolicies` records the actual legacy header, line, expression and
storage policy separately. Aliases resolve after legacy definitions so a later
independent definition can still supply their value. Case-only spellings and
unrelated equal literals do not acquire a dependency. Projected enum storage is
unchanged, and conversions back to primitive aliases are explicit.

The metadata-infrastructure `Architecture` enum is scoped because its members belong
to that helper type. Native unscoped SDK enums and synthetic bags remain unscoped.

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

#### Header annotations: metadata-only constant groups

Keep the existing constants and native declaration types. The shared annotation
header groups constants without `undef`, copied values, or native signature changes:

```cpp
_Win32_FlagsEnum_(FILE_ATTRIBUTE_FLAGS, DWORD,
    FILE_ATTRIBUTE_READONLY,
    FILE_ATTRIBUTE_HIDDEN,
    FILE_ATTRIBUTE_SYSTEM);
```

With `WIN32METADATA` and Clang, this is a typedef/annotation carrier. The scraper
reads its storage and compiled expression values from the original AST and emits an
unscoped logical enum. `_Win32_Enum_` is the non-flags form. Without metadata mode,
both macros expand to nothing: no enum, typedef, or new ordinary-consumer symbol.
Use `_Win32_AssociatedEnum_(FILE_ATTRIBUTE_FLAGS)` on a parameter/return/field while
preserving its native `DWORD` type.

See `docs/copilot/plans/shift-left-annotation-spec.md` for the authoring contract,
including rare explicit name/value mappings.

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

Native field element-count inference is disabled by default. The emitter's global
`--nativeFieldArrayInfo` option enables it for pointer and array fields, producing
`[NativeArrayInfo(CountFieldName = "...")]` for sibling-field counts or
`[NativeArrayInfo(CountConst = ...)]` for nonnegative constant counts. Scalar
access spans do not become array attributes. Parameter SAL processing is unchanged.

### SupportedOS declaration placement

The `_Win32_SupportedOS_*_` macros support individual enum members using postfix
placement, for example `Value _Win32_SupportedOS_Windows8_ = 1`. Const-qualified
native variables use prefix placement. A member's OS floor does not change the
enum's floor or annotate its other members.

`_Win32_SupportedOS_BEGIN_(os)`/`_Win32_SupportedOS_END_()` use native Clang
lexical scope. Includes inherit it, nested/direct attributes accumulate, identical
floors collapse, and distinct floors on one declaration/redeclaration are errors.
Close a scope before changing its floor; there is no custom override precedence.

### Custom metadata annotations

The shared `win32metadata_annotations.h` defines the `_Win32_*_` vocabulary using
Clang attributes owned by the `Win32Metadata.` payload prefix. The scraper opts in
with `--config parse-win32-annotations`, defines `WIN32METADATA`, and uses the same
translation unit for annotation extraction, remap discovery, and ClangSharp
generation. Native macro RAII invalid values, group values, and optional
import overrides are typed annotation arguments from that first AST. No
`WIN32METADATA_CSHARP` gate or second expression parse is used.
Cleanup references use a tagged expanded native name, bound to one actual function
declaration after the complete translation unit is available. The cleanup prototype
may follow the producer; unknown, non-function, and ambiguous references fail.
Macro and structured-comment enum associations share name resolution. An absent
unqualified metadata name does not require a declaration before its native use;
visible native enums/groups retain their identity and remaps, and visible scalar
aliases are rejected. Cross-partition or retained definitions are checked after
final composition. Every association must resolve to exactly one emitted enum per
applicable architecture or fail with WMA003.
Invalid-value expressions remain compiler-evaluated and input handles do not infer
cleanup. The shared helper makes ignored metadata annotations
errors locally without changing the native SDK/SAL warning policy.

Defined annotations:

| Annotation | Target | Winmd effect |
|---|---|---|
| `_Win32_SetLastError_` | function | P/Invoke last-error flag |
| `_Win32_SupportedOS_*_` | declaration | `[SupportedOSPlatform]` |
| `_Win32_RAIIFree_(cleanup, invalid...)` | producer return/output | `[RAIIFree]` and repeated `[InvalidHandleValue]` |
| `_Win32_RAIIFree_Handle_(cleanup)` | producer return/output | Cleanup plus integral invalid values `-1, 0` |
| `_Win32_AssociatedEnum_(type)` | return, parameter, field | Association while preserving native declaration types |
| `_Win32_ImportLibrary_(dll[, export or ordinal])` | function | Module and optional `ImplMap.ImportName` override |
| `_Win32_Retained_` | parameter | Retained pointer metadata |
| `_Win32_Reserved_` | parameter | Reserved metadata; preserves existing native direction and optionality |
| `_Win32_ContainsInteriorPointers_` | caller-owned output buffer | Same-allocation interior-pointer metadata |

Prefer existing SAL/MIDL for counts, directions, COM outputs and retval. Native
IDL `[retval]` survives in MIDL's parameter comments and is read alongside adjacent
direction blocks. Native SDK SAL uses `_Out_`/`_COM_Outptr_`, not generator-only
retval macros. Nonlocal methods retain `/sal`-generated RPC annotations.

Original IDL transports additional facts with standard `cpp_quote` emitting
`/* Win32Metadata: KIND ::Native::Target => CanonicalAnnotation(arguments) */`.
This uses the same opt-in, facts, target validation and emitter as native macros.
Clang's active comment tokens, included files and skipped ranges supply source
scope; strings are not comments. Explicit native identities bind interfaces,
methods, parameters, fields, types, functions/returns and enum/constants without
synthetic declarations. Cleanup/type/enum references resolve natively; comment
RAIIFree invalids support signed decimal Int64 literals. Compiled logical groups
and native C/C++ expressions retain their existing macro path.

See `docs/copilot/plans/shift-left-annotation-spec.md` for the full vocabulary and
original-SDK-artifact patching requirements.

---

## Namespace Organization

Types are placed into namespaces based on the **partition** system. Each partition
(a directory under `generation/WinSDK/Partitions/`) defines which headers it includes
(`main.cpp`) and maps to a namespace (e.g., `Partitions/Foundation/` →
`Windows.Win32.Foundation`).

`requiredNamespacesForNames.rsp` provides overrides for types that need to be in a
specific namespace regardless of which partition's headers they're declared in.

Namespace qualification replaces selected type nodes in one syntax-rewriter pass.
Composite types are qualified recursively from their original lexical context.
Lexical shadow information and member-move decisions are reused within that original
tree. Using aliases, nested types and delegates, and generic type and method parameters
retain their existing precedence. The subsequent namespace mover still removes
unmapped imports even when no declarations change namespace.

Native typedef and repeated-record composition reuse semantic models only within
their producing immutable compilation. Canonical comparisons still isolate each
provider family and rebind changed trees. Competing record providers are located by
their exact spans rather than rescanning every declaration. Native proof, selected
providers, ABI checks, and collect-and-emit diagnostics are unchanged.

---

## Sidecar Files

Several sidecar files provide metadata that isn't (yet) expressible in headers:

| File | Purpose | Shift-left status |
|---|---|---|
| `scraper.settings.rsp` | Type remaps, exclusions | Mostly auto-derived |
| `enums.json` | Synthetic enum definitions | Header constant groups and native-typed associations |
| `autoTypes.json` | Handle type definitions | Proposed: header annotations |
| `emitter.settings.rsp` | Member remaps, enum additions | Proposed: header annotations |
| `WithSetLastError.rsp` | SetLastError functions | `_Win32_SetLastError_` |
| `supportedOS.rsp` | OS version requirements | Fixed `_Win32_SupportedOS_*_` annotations/scopes |
| `libMappings.rsp` | Function→DLL mappings | Auto-generated from .lib files |
| `documentationMappings.rsp` | Documentation URLs | Stays (external data) |
| `functionPointerFixups.json` | Fn ptr name fixes | Mostly auto-derived |

The shift-left strategy (`docs/copilot/plans/shift-left-metadata-plan.md`) aims to move
API-semantic metadata into the headers themselves, leaving only tooling configuration in
sidecar files.

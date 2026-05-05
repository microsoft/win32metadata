# Handle Annotation Proposal: Replacing `autoTypes.json` Handle Metadata with Header Annotations

*Created: April 2026*
*Status: Proposal — validated end-to-end with ClangSharp v18.1.0.4*
*Test files: `obj/handle-annotation-test/`*

---

## Summary

This proposal replaces the handle metadata in `autoTypes.json` (~166 `DECLARE_HANDLE`-based entries) with C++11 attribute annotations directly in the SDK headers. The headers become the single source of truth for handle semantics: close API, invalid sentinel values, and interchangeability.

The approach has been validated end-to-end with ClangSharp v18.1.0.4: `[[clang::annotate("w32m::raii_free=...")]]` placed between `struct` and the handle name flows through to `[NativeAnnotation("w32m::raii_free=...")]` on the generated C# struct, where `MetadataSyntaxTreeCleaner` can translate it into the existing `[RAIIFree]`, `[InvalidHandleValue]`, `[AlsoUsableFor]`, and `[NativeTypedef]` attributes — preserving the current winmd output exactly.

Both downstream projections (CsWin32 and windows-rs) read these attributes by name from the winmd and emit conversion code based on them. The proposed shift-left changes preserve the same winmd output, so projections require no changes.

This proposal covers `DECLARE_HANDLE`-style handles only (~166 entries, ~70% of `autoTypes.json`). The remaining ~80 entries (typedef-style handles, non-handle typedefs, special projection types) are out of scope here and tracked separately at the end of this document, with a sketch for a sibling `DECLARE_TYPEDEF_WIN32METADATA` macro that addresses them.

---

## Background

Today, `autoTypes.json` encodes two distinct things for each handle type:

1. **Structural** — what kind of value the handle wraps (`void*`, `IntPtr`, `UIntPtr`, etc.) and that it should be emitted as a `[NativeTypedef]` wrapper struct.
2. **Semantic** — its close API, invalid sentinel values, and which other handle types it is interchangeable with.

```json
{
  "Namespace": "Windows.Win32.Foundation",
  "Name": "HMODULE",
  "ValueType": "DECLARE_HANDLE",
  "CloseApi": "FreeLibrary",
  "AlsoUsableFor": "HINSTANCE",
  "InvalidHandleValues": [ 0 ],
  "NativeTypedef": true
}
```

`NativeTypedefStructsCreator.cs` reads each entry and emits a C# struct:

```csharp
[RAIIFree("FreeLibrary")]
[AlsoUsableFor("HINSTANCE")]
[InvalidHandleValue(0)]
[NativeTypedef]
public unsafe struct HMODULE { public void* Value; }
```

The headers themselves use the standard SDK macro:

```c
DECLARE_HANDLE(HMODULE);
```

…which expands to `struct HMODULE__{int unused;}; typedef struct HMODULE__ *HMODULE`. ClangSharp flattens this typedef to `void*`, so the wrapper struct in the winmd has no relationship to the in-header declaration — it is constructed entirely from the JSON.

This proposal moves all the **semantic** information into the headers as annotations, and replaces the structural piece with a redefinition of `DECLARE_HANDLE` under `-D_WIN32METADATA_=1`.

---

## Proposed Approach: Annotated `DECLARE_HANDLE`

### Core pattern

Add a small `win32metadata.h` header that, under `_WIN32METADATA_`:

1. Redefines `DECLARE_HANDLE` so each handle becomes a fully-annotated struct in the AST
2. Defines macros that expand to `[[clang::annotate("w32m::...")]]` for the three pieces of handle metadata

```c
// win32metadata.h
#pragma once

#ifdef _WIN32METADATA_

  // Annotation primitives — expand to C++11 attributes ClangSharp v18+ preserves
  #define _Close_handle_with_(api)   [[clang::annotate("w32m::raii_free=" #api)]]
  #define _Invalid_handle_(val)      [[clang::annotate("w32m::invalid_handle=" #val)]]
  #define _Also_usable_for_(type)    [[clang::annotate("w32m::also_usable_for=" #type)]]

  // Replace DECLARE_HANDLE with a single struct declaration that ClangSharp
  // emits directly as the wrapper struct. The "w32m::handle" annotation
  // marks it for [NativeTypedef] emission by MetadataSyntaxTreeCleaner.
  #undef DECLARE_HANDLE
  #define DECLARE_HANDLE(name) \
      struct [[clang::annotate("w32m::handle")]] name { void* Value; }

  // Annotated form: takes an attribute pack between `struct` and `name`.
  // C++ requires custom attributes there; they cannot precede `struct`.
  #define DECLARE_HANDLE_WIN32METADATA(name, ...) \
      struct [[clang::annotate("w32m::handle")]] __VA_ARGS__ name { void* Value; }

#else  // Normal compilation — annotations vanish, DECLARE_HANDLE keeps SDK form

  #define _Close_handle_with_(api)
  #define _Invalid_handle_(val)
  #define _Also_usable_for_(type)
  #define DECLARE_HANDLE_WIN32METADATA(name, ...) DECLARE_HANDLE(name)

#endif
```

### How it looks in SDK headers

Unannotated handles keep the existing one-line form:

```c
DECLARE_HANDLE(HWND);   // No close API; no annotations needed
```

Annotated handles use `DECLARE_HANDLE_WIN32METADATA`:

```c
DECLARE_HANDLE_WIN32METADATA(HMODULE,
    _Close_handle_with_(FreeLibrary)
    _Invalid_handle_(0)
    _Also_usable_for_(HINSTANCE));

DECLARE_HANDLE_WIN32METADATA(HFILE,
    _Close_handle_with_(CloseHandle)
    _Invalid_handle_(-1)
    _Invalid_handle_(0));
```

### What ClangSharp v18 emits

Validated output for the above headers:

```csharp
[NativeAnnotation("w32m::handle")]
public unsafe partial struct HWND { public void* Value; }

[NativeAnnotation("w32m::handle")]
[NativeAnnotation("w32m::raii_free=FreeLibrary")]
[NativeAnnotation("w32m::invalid_handle=0")]
[NativeAnnotation("w32m::also_usable_for=HINSTANCE")]
public unsafe partial struct HMODULE { public void* Value; }

[NativeAnnotation("w32m::handle")]
[NativeAnnotation("w32m::raii_free=CloseHandle")]
[NativeAnnotation("w32m::invalid_handle=-1")]
[NativeAnnotation("w32m::invalid_handle=0")]
public unsafe partial struct HFILE { public void* Value; }
```

Functions that return these handles get the struct types directly — no typedef flattening, no `void*` leakage.

### Translation in `MetadataSyntaxTreeCleaner`

Each `w32m::` annotation maps 1:1 to an existing managed attribute:

| Annotation | Translated to |
|---|---|
| `w32m::handle` | `[NativeTypedef]` |
| `w32m::raii_free=X` | `[RAIIFree("X")]` |
| `w32m::invalid_handle=N` | `[InvalidHandleValue(N)]` (one per occurrence) |
| `w32m::also_usable_for=T` | `[AlsoUsableFor("T")]` |

The cleaner already processes `[CppAttributeList]` for SAL; this is a parallel branch that processes `[NativeAnnotation]` and recognizes the `w32m::` prefix.

---

## Projection Behavior (No Changes Needed)

Because the winmd output is byte-identical to today's output, both downstream projections continue to work unchanged. Validated by reading their source:

### CsWin32 (`Generator.TypeDef.cs`)

For a struct with `[NativeTypedef]` and `[AlsoUsableFor("HINSTANCE")]`, CsWin32 emits an implicit conversion operator on the source struct:

```csharp
public readonly partial struct HMODULE
{
    internal readonly void* Value;
    // ... constructors, equality, ToString ...
    public static implicit operator HINSTANCE(HMODULE value)
        => new HINSTANCE(value.Value);
}
```

The `[RAIIFree]`, `[InvalidHandleValue]`, and `[NativeTypedef]` attributes drive the rest of the wrapper struct shape (constructors, `IsInvalid`, `SafeHandle` integration).

### windows-rs (`crates/libs/bindgen/src/config/cpp_handle.rs`)

For the same metadata, windows-rs emits two impls plus a marker trait:

```rust
#[repr(transparent)]
pub struct HMODULE(pub *mut core::ffi::c_void);
impl HMODULE { pub fn is_invalid(&self) -> bool { self.0.is_null() } }
impl windows_core::Free for HMODULE { /* calls FreeLibrary */ }

// From [AlsoUsableFor("HINSTANCE")]:
impl windows_core::imp::CanInto<HINSTANCE> for HMODULE {}
impl From<HMODULE> for HINSTANCE {
    fn from(value: HMODULE) -> Self { Self(value.0) }
}
```

The `CanInto<HINSTANCE>` marker trait participates in windows-rs's `Param<T>` system, so any function expecting an `HINSTANCE` parameter transparently accepts an `HMODULE` at the call site — no `.into()` needed.

### Implications for the design

Both projections agree on three contracts that this proposal preserves:

1. **Source-side, asymmetric, by-name string.** Each annotation lives on the source struct and points at the target by name. Bidirectional cases (e.g., `HMODULE ↔ HINSTANCE`) require explicit annotations on both sides — same as today's JSON.
2. **Same-namespace requirement is hard-coded** in both projections. The current validation in `NativeTypedefStructsCreator` (`closeApiNamespaceMismatches`, `alsoUsableForNamespaceMismatches`) must move into the new emitter path.
3. **`AlsoUsableFor` only generates code for `[NativeTypedef]`-shaped structs** in both projections. The single non-handle entry today (`DEVPROPKEY=[AlsoUsableFor("PROPERTYKEY")]` in `emitter.settings.rsp`) is effectively a no-op in both projections — confirmed by source inspection. Out of scope for this proposal.

---

## Design Rationale

### Why `[[clang::annotate("...")]]` and not custom `[[w32m::...]]` attributes?

Validated tradeoffs:

| Form | Survives AST? | Notes |
|---|---|---|
| `[[clang::annotate("w32m::raii_free=X")]]` | ✅ | Standard Clang attribute; produces `AnnotateAttr` AST node; ClangSharp v18 emits as `[NativeAnnotation]` |
| `[[w32m::raii_free("X")]]` | ⚠️ | Unknown attribute — Clang warns and may drop it; not preserved in AST without writing a Clang plugin |
| `__attribute__((annotate("...")))` | ✅ | Equivalent to `[[clang::annotate(...)]]`; older GNU-style syntax |
| `[[clang::annotate("a","b","c")]]` (variadic) | ❌ | Validated: ClangSharp v18 only emits the first string argument; subsequent args silently dropped |

`[[clang::annotate("...")]]` is the only form that is (a) standard, (b) preserved through Clang's AST, and (c) emitted by ClangSharp without modification.

### Why the macro indirection?

Three reasons:

1. **Ergonomic SDK author experience.** `_Close_handle_with_(FreeLibrary)` reads like SAL; the underlying `[[clang::annotate("w32m::raii_free=FreeLibrary")]]` does not.
2. **Single point of change.** If we ever switch annotation prefixes (e.g., from `w32m::` to a future SDK-standard scheme), only `win32metadata.h` changes — not every handle declaration.
3. **Consistency with the SAL precedent.** SDK headers already use this macro pattern for SAL; reusing it for metadata means SDK authors learn one mechanism, not two.

### Why redefine `DECLARE_HANDLE` instead of placing annotations next to it?

Validated finding: **C++11 attributes cannot precede the `struct` keyword for a class declaration at namespace scope.**

```c
[[clang::annotate("w32m::raii_free=FreeLibrary")]]   // ❌ "misplaced attributes"
struct HMODULE { void* Value; };
```

Attributes for the type *must* go between `struct` and the name:

```c
struct [[clang::annotate("w32m::raii_free=FreeLibrary")]] HMODULE { void* Value; };  // ✅
```

Since `DECLARE_HANDLE(HMODULE);` expands to a token sequence beginning with `struct`, we cannot place attributes in front of it. Two options remain:

- Take attributes *inside* the macro via `__VA_ARGS__` — this is `DECLARE_HANDLE_WIN32METADATA`.
- Hand-write the struct without using the macro at all — verbose and inconsistent.

`DECLARE_HANDLE_WIN32METADATA` is the better choice; the `#else` branch translates it back to plain `DECLARE_HANDLE` for normal compilation, so SDK consumers see no difference.

### Why a `w32m::handle` marker on every handle?

The current `[NativeTypedef]` attribute is what tells the winmd consumer "this struct is a wrapper around a native value type, not a real struct." It must be on every handle. Two options to drive its emission:

1. **Structural detection** — any struct with a single `void* Value` field gets `[NativeTypedef]`. Fragile: misclassifies any struct that happens to have that shape.
2. **Explicit marker** (chosen) — the `w32m::handle` annotation, baked into the redefined `DECLARE_HANDLE` macro itself, makes intent explicit and impossible to confuse with an unrelated struct.

Because the marker comes from the macro definition, SDK authors never write it — they just use `DECLARE_HANDLE` (or `DECLARE_HANDLE_WIN32METADATA`) as before.

---

## What's NOT Annotated (inferred from the AST)

Following the principle "only annotate what we cannot infer":

| Property | Source |
|---|---|
| **Handle name** | The struct name in the AST |
| **Underlying value type** | The single field type (`void*`, `IntPtr`, etc.) |
| **Namespace** | The partition the header belongs to (`apiNamesToNamespaces` resolution, same as today) |
| **`unsafe` modifier** | Inferred from field type containing a pointer |
| **`[NativeTypedef]` attribute** | Driven by the `w32m::handle` marker emitted by the macro itself |

Only **CloseApi**, **InvalidHandleValues**, and **AlsoUsableFor** are explicit annotations — all three are genuinely unknowable from structure alone.

---

## Scope: What's Covered and What's Not

This proposal covers **`DECLARE_HANDLE`-style handles only** — entries in `autoTypes.json` with `"ValueType": "DECLARE_HANDLE"` (~166 entries, the largest single category).

The remaining ~80 entries fall into categories that need a sibling macro and are tracked here for follow-up proposals:

### Out of scope: Typedef-style handles and value wrappers (~83 entries)

Handles and value-wrapping types declared via direct typedef rather than `DECLARE_HANDLE`. The fix is the same shift-left mechanism with a **typed** sibling macro:

```c
// In win32metadata.h:
#ifdef _WIN32METADATA_
  // Replaces a typedef with a wrapper struct ClangSharp emits directly.
  // The 3rd+ args are attribute annotations (e.g., _Close_handle_with_).
  #define DECLARE_TYPEDEF_WIN32METADATA(name, type, ...) \
      struct [[clang::annotate("w32m::handle")]] __VA_ARGS__ name { type Value; }
#else
  // Normal compilation: leave the existing SDK typedef untouched.
  // The patch tool inserts this macro IN PLACE of the SDK typedef,
  // so the #else branch must reproduce the original typedef.
  #define DECLARE_TYPEDEF_WIN32METADATA(name, type, ...) typedef type name
#endif
```

The same `_Close_handle_with_` / `_Invalid_handle_` / `_Also_usable_for_` annotations apply.

#### Typedef-style handles (~73 entries)

| Underlying shape | Examples | Count |
|---|---|---|
| `typedef PVOID NAME` | `BCRYPT_ALG_HANDLE`, `BCRYPT_HASH_HANDLE`, `AVRT_TASK_HANDLE` | ~32 |
| `typedef IntPtr-sized NAME` | `EVT_HANDLE`, `HDEVINFO`, `HDPA`, `HCRYPTASYNC` | ~16 |
| `typedef UIntPtr-sized NAME` | `HACCESSOR`, `JET_HANDLE`, `HCRYPTPROV_LEGACY` | ~16 |
| `typedef ulong NAME` | `CONTROLTRACE_HANDLE`, `PROCESSTRACE_HANDLE` | ~4 |
| `typedef uint NAME` | `MSIHANDLE`, `OLE_HANDLE` | ~2 |
| `typedef struct _TP_X *` | `PTP_IO`, `PTP_TIMER`, `PTP_POOL` | ~7 |

Examples (illustrative — actual canonical headers and exact placement to be confirmed by the migration tool):

```c
// shared/bcrypt.h  ← currently: typedef PVOID BCRYPT_ALG_HANDLE;
DECLARE_TYPEDEF_WIN32METADATA(BCRYPT_ALG_HANDLE, void*,
    _Close_handle_with_(BCryptCloseAlgorithmProvider));

DECLARE_TYPEDEF_WIN32METADATA(BCRYPT_HASH_HANDLE, void*,
    _Close_handle_with_(BCryptDestroyHash));

// um/winevt.h  ← currently: typedef HANDLE EVT_HANDLE;
DECLARE_TYPEDEF_WIN32METADATA(EVT_HANDLE, intptr_t,
    _Close_handle_with_(EvtClose));

// um/msi.h  ← currently: typedef unsigned long MSIHANDLE;
DECLARE_TYPEDEF_WIN32METADATA(MSIHANDLE, unsigned int,
    _Close_handle_with_(MsiCloseHandle));

// um/threadpoolapiset.h  ← currently: typedef struct _TP_TIMER *PTP_TIMER;
DECLARE_TYPEDEF_WIN32METADATA(PTP_TIMER, intptr_t,
    _Close_handle_with_(CloseThreadpoolTimer));
```

#### Non-handle value wrappers (~10 entries)

These are not RAII handles — they're value typedefs that exist in `autoTypes.json` only because the pipeline needs an explicit "wrap as `[NativeTypedef]`" signal. Most have no metadata other than the type itself; `BSTR` is the one that carries a `CloseApi`.

| Type | Header | Current SDK declaration | Proposed |
|---|---|---|---|
| `BOOL` | `shared/minwindef.h:157` | `typedef int BOOL;` | `DECLARE_TYPEDEF_WIN32METADATA(BOOL, int);` |
| `BOOLEAN` | `shared/ntdef.h:1676` | `typedef UCHAR BOOLEAN;` | `DECLARE_TYPEDEF_WIN32METADATA(BOOLEAN, unsigned char);` |
| `VARIANT_BOOL` | `shared/wtypes.h:745` | `typedef short VARIANT_BOOL;` | `DECLARE_TYPEDEF_WIN32METADATA(VARIANT_BOOL, short);` |
| `HRESULT` | `shared/intsafe.h:172` (canonical; also redefined in `ntdef.h`, `strsafe.h`, `winerror.h`, `WTypesbase.h` under `#ifndef _HRESULT_DEFINED`) | `typedef _Return_type_success_(return >= 0) long HRESULT;` | `DECLARE_TYPEDEF_WIN32METADATA(HRESULT, long);` |
| `NTSTATUS` | `shared/ntdef.h:1062` | `typedef _Return_type_success_(return >= 0) LONG NTSTATUS;` | `DECLARE_TYPEDEF_WIN32METADATA(NTSTATUS, long);` |
| `LPARAM` | `shared/minwindef.h:187` | `typedef LONG_PTR LPARAM;` | `DECLARE_TYPEDEF_WIN32METADATA(LPARAM, intptr_t);` |
| `WPARAM` | `shared/minwindef.h:186` | `typedef UINT_PTR WPARAM;` | `DECLARE_TYPEDEF_WIN32METADATA(WPARAM, uintptr_t);` |
| `LRESULT` | `shared/minwindef.h:188` | `typedef LONG_PTR LRESULT;` | `DECLARE_TYPEDEF_WIN32METADATA(LRESULT, intptr_t);` |
| `BSTR` | `shared/wtypes.h:737` | `typedef OLECHAR *BSTR;` | `DECLARE_TYPEDEF_WIN32METADATA(BSTR, OLECHAR*, _Close_handle_with_(SysFreeString));` |
| `PSID` | `shared/WTypesbase.h:242` | `typedef PVOID PSID;` | `DECLARE_TYPEDEF_WIN32METADATA(PSID, void*);` |
| `PSTR`/`PWSTR`/`PCSTR`/`PCWSTR` | `shared/winnt.h` (varies) | `typedef CHAR *PSTR;` etc. | Same pattern; CsWin32 has manual templates that depend on the wrapper struct existing |

**Caveats requiring follow-up work:**

1. **Multiple declaration sites.** `HRESULT`, `LPARAM`, `WPARAM`, `LRESULT`, `BOOLEAN`, and `BSTR` are each declared in multiple headers (often in both `.h` and `.Idl` siblings) under `#ifndef`-style guards. The patch tool must annotate exactly one canonical site, or risk duplicate-struct compilation errors.
2. **SAL on the underlying type.** `HRESULT` and `NTSTATUS` carry `_Return_type_success_(return >= 0)` SAL on the typedef itself. The simple macro substitution above drops it. The follow-up proposal needs to either inline the SAL into the macro expansion or carry it as a separate annotation.
3. **String wrapper templates.** `PSTR`/`PWSTR`/`BSTR` etc. have hand-written CsWin32 templates that add `IndexOf`, `ToString`, marshalling, etc. The shift-left change preserves the wrapper struct; the projection-side templates remain unchanged.

### Out of scope: Special-form types (3 entries)

Types using non-standard `ValueType` keywords in `autoTypes.json` (`DECLARE_OPAQUE_KEY` for `CF_CONNECTION_KEY`, `AllJoynHandle` for AllJoyn types). With the typed macro from above, these become regular typedefs:

```c
DECLARE_TYPEDEF_WIN32METADATA(CF_CONNECTION_KEY, long long);
DECLARE_TYPEDEF_WIN32METADATA(alljoyn_msgarg, intptr_t);
```

### Dropped: `AlsoUsableFor` on non-handle structs (1 entry)

`emitter.settings.rsp` contains `DEVPROPKEY=[AlsoUsableFor("PROPERTYKEY")]`. Both CsWin32 and windows-rs only generate conversion code for `[NativeTypedef]`-shaped structs — for regular multi-field structs like `DEVPROPKEY`, the attribute is dormant. **Recommend dropping this entry entirely** as part of this work and observing whether anything regresses; no replacement annotation needed unless a future projection consumer is identified.

### Out of scope: Cross-cutting concerns

| Concern | Why it's deferred |
|---|---|
| **Migration tooling** | The patch system from `shift-left-metadata-plan.md` will rewrite SDK headers programmatically; that tool is shared across all annotation classes |
| **`ClangSharp v18` upgrade** | Tracked separately as a Phase 1 prerequisite for the entire shift-left effort |
| **Empty-namespace handle entries (~38 in `autoTypes.json`)** | These rely on `NativeTypedefStructsCreator` deriving the namespace from `CloseApi`. With shift-left, the namespace comes from the header's partition placement — same resolution, different mechanism |

---

## Migration from `autoTypes.json` (DECLARE_HANDLE entries only)

Every field on a `DECLARE_HANDLE` entry maps to a header construct:

| `autoTypes.json` field | Header equivalent |
|---|---|
| `Name` | Struct name in `DECLARE_HANDLE_WIN32METADATA` invocation |
| `Namespace` | Header partition (resolved via `apiNamesToNamespaces`) |
| `ValueType: "DECLARE_HANDLE"` | `DECLARE_HANDLE_WIN32METADATA(name, ...)` |
| `CloseApi` | `_Close_handle_with_(api)` |
| `InvalidHandleValues[]` | One `_Invalid_handle_(val)` per entry |
| `AlsoUsableFor` | `_Also_usable_for_(type)` |
| `NativeTypedef: true` | Implied by `w32m::handle` marker baked into the macro |

After this migration, `autoTypes.json` shrinks by ~166 entries (~70%). The remaining typedef-style and non-handle entries are addressed by follow-up proposals listed in the Scope section above.

---

## Validation Evidence

Test files in `obj/handle-annotation-test/`. ClangSharp v18.1.0.4. Eleven patterns tested:

| # | Pattern | Result |
|---|---|---|
| 1 | Annotate the SDK's opaque `name__` struct (in original DECLARE_HANDLE) | ⚠️ Annotations preserved on `name__`, but typedef flattened — function signatures use `name__*` not `name`. Wrong type carries the metadata. |
| 2 | `struct [[attr]] NAME { void* Value; };` (direct) | ✅ Clean output |
| 3 | `[[clang::annotate("a", "b", "c")]]` variadic | ❌ Only first arg preserved by ClangSharp |
| 4 | `typedef [[attr]] void* NAME;` | ❌ Annotation dropped; typedef flattened |
| 5 | Macro-wrapped equivalent of pattern 2 | ✅ Identical to 2 |
| 6 | Custom `W32M_HANDLE_BEGIN/END` macro | ✅ Works but verbose |
| 7 | `DECLARE_HANDLE_WIN32METADATA(name, [[attrs]])` | ✅ Chosen pattern |
| 8 | Same as 7, expanded form | ✅ |
| 9 | BCRYPT-style direct annotated struct | ✅ |
| 10 | `[[attr]] DECLARE_HANDLE(name);` (attrs before macro) | ❌ "misplaced attributes" parser error |
| 11 | SAL-style macros before `DECLARE_HANDLE` | ❌ Same parser error as 10 |

Final canonical form (`obj/handle-annotation-test/final.h`) produces the exact `[NativeAnnotation]` attribute set the proposal describes.

---

## Implementation Steps

1. **Add `win32metadata.h`** with the `_Close_handle_with_`, `_Invalid_handle_`, `_Also_usable_for_` macros and the `DECLARE_HANDLE` redefinition + `DECLARE_HANDLE_WIN32METADATA` macro.
2. **Add `-D_WIN32METADATA_=1`** to `baseSettings.rsp` (already validated separately by the enum proposal) and `#include "win32metadata.h"` to the scraper include chain.
3. **Extend `MetadataSyntaxTreeCleaner`** to recognize `[NativeAnnotation("w32m::handle")]`, `w32m::raii_free=...`, `w32m::invalid_handle=...`, `w32m::also_usable_for=...` and emit the corresponding managed attributes. Move the same-namespace validation logic out of `NativeTypedefStructsCreator` into this path.
4. **Build a migration tool** that reads `autoTypes.json` for `DECLARE_HANDLE` entries and rewrites the appropriate SDK headers (via the patch system from `shift-left-metadata-plan.md`) to use `DECLARE_HANDLE_WIN32METADATA`.
5. **Validate winmd equivalence** — compare winmd output handle-by-handle against the baseline.
6. **Remove the `DECLARE_HANDLE` entries from `autoTypes.json`.** Keep the file for the remaining ~80 entries until follow-up proposals address them.
7. **Eventually push these macros into the official SDK headers**, mirroring the SAL adoption path.

---

## Open Questions

1. **`InvalidHandleValue` argument types.** The current `[InvalidHandleValueAttribute]` constructor takes `long`. Some sentinels in `autoTypes.json` are `-1` and `0`, which fit; the cleaner just needs to parse the annotation string and emit the right constant.

2. **Comment-mode validation.** `NativeTypedefStructsCreator` currently throws on missing close APIs and on cross-namespace `CloseApi`/`AlsoUsableFor`. We must preserve these checks in the new emitter path; the natural home is inside `MetadataSyntaxTreeCleaner` (or a post-scan validation step).

3. **Empty-namespace handle entries.** `autoTypes.json` has ~38 `DECLARE_HANDLE` entries with no explicit `Namespace` — `NativeTypedefStructsCreator` derives it from the `CloseApi`'s namespace. With shift-left, the namespace comes from the header's partition placement. The migration tool needs to verify that placing `DECLARE_HANDLE_WIN32METADATA(NAME, ...)` in the header it currently lives in produces the same final namespace.

4. **Does the migration tool patch SDK headers in `RecompiledIdlHeaders/`, or use overlay headers?** The enum proposal uses partition-local overlay headers as Phase 1 to avoid touching SDK headers during prototyping. The same approach applies here: prototype with overlays, then move to in-place SDK header patches via the shared patch system.

---

## Other Alternatives Considered

### Annotating the original `DECLARE_HANDLE` (without redefinition)

Place annotations next to `DECLARE_HANDLE(NAME);` in the headers without changing the macro. **Rejected:** validated empirically — C++11 attributes cannot precede `struct` at namespace scope, so `[[attr]] DECLARE_HANDLE(name);` produces a parser error (test patterns 10 and 11). And annotations *inside* the SDK's `DECLARE_HANDLE` expansion attach to the `name__` opaque struct, which ClangSharp then flattens away — wrong type carries the metadata (test pattern 1).

### Custom `[[w32m::raii_free(X)]]` attributes (vendor-prefixed)

**Rejected:** vendor-prefixed attributes that Clang doesn't recognize produce "unknown attribute" warnings and are not guaranteed to land in the AST. Implementing them as recognized attributes would require a Clang plugin or upstream compiler change.

### Single multi-arg `[[clang::annotate(...)]]`

```c
struct [[clang::annotate("w32m::handle",
                         "raii=FreeLibrary",
                         "invalid=0",
                         "alsousable=HINSTANCE")]]
HMODULE { void* Value; };
```

**Rejected:** validated empirically — ClangSharp v18 only emits the first string argument as `[NativeAnnotation]`; subsequent args are silently dropped. The fix would have to live upstream in ClangSharp.

### Keeping `autoTypes.json` for structure, moving only metadata to headers

A hybrid: `autoTypes.json` shrinks to `{Name, ValueType, Namespace}`; CloseApi/Invalid/AlsoUsableFor move to headers. **Rejected:** retains the dual-source-of-truth problem the shift-left effort is trying to eliminate. The structural information (`ValueType: "DECLARE_HANDLE"`) is also derivable from the macro form used in the header — no JSON needed.

### Inferring `[NativeTypedef]` from struct shape

Auto-mark any struct with a single `void* Value` field as `[NativeTypedef]`. **Rejected:** brittle — misclassifies unrelated structs that happen to share that shape, and offers no protection against future structural drift. The explicit `w32m::handle` marker is one annotation in one place (the macro definition itself) and removes all ambiguity.

### Standalone `W32M_ALSO_USABLE_FOR(from, to)` macro for AlsoUsableFor

Express the relationship as a separate top-level declaration rather than inline on the source struct. **Rejected:** projection inspection (CsWin32 + windows-rs) confirmed the winmd model is inherently a per-struct, source-side, by-name attribute. The inline annotation maps 1:1 to that model. A separate relationship-style macro would add a layer of indirection that gets erased back to the same attribute by the time it reaches the winmd, providing no benefit.

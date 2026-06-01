# Handle Annotation Proposal: Replacing `autoTypes.json` with Header Annotations

*Created: April 2026*
*Status: Proposal — validated end-to-end with ClangSharp v18.1.0.4*
*Test files: `obj/handle-annotation-test/`*

---

## Summary

This proposal replaces `autoTypes.json` in its entirety (~280 entries across handles, value typedefs, and special-form types) with C++11 attribute annotations directly in the SDK headers. The headers become the single source of truth: underlying type, close API, invalid sentinel values, and interchangeability all live next to the type's declaration.

The approach has been validated end-to-end with ClangSharp v18.1.0.4: `[[clang::annotate("w32m::raii_free=...")]]` placed between `struct` and the type name flows through to `[NativeAnnotation("w32m::raii_free=...")]` on the generated C# struct, where `MetadataSyntaxTreeCleaner` translates it into the existing `[RAIIFree]`, `[InvalidHandleValue]`, `[AlsoUsableFor]`, and `[NativeTypedef]` attributes — preserving the current winmd output exactly.

Both downstream projections (CsWin32 and windows-rs) read these attributes by name from the winmd and emit conversion code based on them. The proposed shift-left changes preserve the same winmd output, so projections require no changes.

After migration, `autoTypes.json`, `NativeTypedefStructsCreator.cs`, `AutoType.cs`, and the JSON load path in `Windows.Win32.proj` are removed.

---

## Background

Today, `autoTypes.json` encodes two distinct things for each entry:

1. **Structural** — what kind of value the type wraps (`DECLARE_HANDLE`, `void*`, `IntPtr`, `int`, `char*`, etc.) and that it should be emitted as a `[NativeTypedef]` wrapper struct.
2. **Semantic** — its close API, invalid sentinel values, and which other types it is interchangeable with (`AlsoUsableFor`).

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

The headers themselves use the standard SDK macros:

```c
DECLARE_HANDLE(HMODULE);                 // ~166 entries — opaque pointer handles
typedef PVOID BCRYPT_ALG_HANDLE;         // ~80 entries  — typedef-style handles
typedef int   BOOL;                      //  ~10 entries — value wrappers
```

ClangSharp flattens all three forms during scraping, so the wrapper struct in the winmd has no relationship to the in-header declaration — it is constructed entirely from the JSON.

This proposal moves all of this into the headers via a small set of macros under `-D_WIN32METADATA_=1`.

---

## Proposed Approach

### `win32metadata.h`

Add a small header that, under `_WIN32METADATA_`, defines the annotation macros and two structural macros — one for opaque-pointer handles (`DECLARE_HANDLE`-style) and one for typed wrappers (everything else).

```c
// win32metadata.h
#pragma once

#ifdef _WIN32METADATA_

  // ── Annotation primitives ────────────────────────────────────────
  // C++11 attributes ClangSharp v18+ preserves as [NativeAnnotation].
  #define _Close_handle_with_(api)   [[clang::annotate("w32m::raii_free=" #api)]]
  #define _Invalid_handle_(val)      [[clang::annotate("w32m::invalid_handle=" #val)]]
  #define _Also_usable_for_(type)    [[clang::annotate("w32m::also_usable_for=" #type)]]

  // ── Structural macros ────────────────────────────────────────────
  // Both produce a [NativeTypedef]-shaped wrapper struct ClangSharp
  // emits directly. The "w32m::handle" annotation marks it for
  // [NativeTypedef] emission by MetadataSyntaxTreeCleaner.

  // Opaque-pointer handles. Replaces the SDK's DECLARE_HANDLE entirely;
  // the wrapper field is always void*.
  #undef DECLARE_HANDLE
  #define DECLARE_HANDLE(name) \
      struct [[clang::annotate("w32m::handle")]] name { void* Value; }

  // DECLARE_HANDLE plus annotations. C++ requires custom attributes
  // between `struct` and the type name; they cannot precede `struct`
  // at namespace scope, so the macro takes them via __VA_ARGS__.
  #define DECLARE_HANDLE_WIN32METADATA(name, ...) \
      struct [[clang::annotate("w32m::handle")]] __VA_ARGS__ name { void* Value; }

  // Typed wrappers — the underlying type is explicit. Replaces a
  // SDK typedef in place. Used for typedef-style handles (BCRYPT_*,
  // EVT_HANDLE, MSIHANDLE, …) and value wrappers (BOOL, BSTR,
  // HRESULT, …).
  #define DECLARE_TYPEDEF_WIN32METADATA(name, type, ...) \
      struct [[clang::annotate("w32m::handle")]] __VA_ARGS__ name { type Value; }

#else  // Normal compilation — annotations vanish; the SDK form stands

  #define _Close_handle_with_(api)
  #define _Invalid_handle_(val)
  #define _Also_usable_for_(type)
  #define DECLARE_HANDLE_WIN32METADATA(name, ...)        DECLARE_HANDLE(name)
  #define DECLARE_TYPEDEF_WIN32METADATA(name, type, ...) typedef type name

#endif
```

### How it looks in SDK headers

Three call patterns covering every entry in `autoTypes.json` today:

```c
// (1) Plain handles with no metadata — keep the existing one-line form.
//     Under _WIN32METADATA_ the redefined macro emits a [NativeTypedef] struct.
DECLARE_HANDLE(HWND);

// (2) DECLARE_HANDLE-style with metadata.
DECLARE_HANDLE_WIN32METADATA(HMODULE,
    _Close_handle_with_(FreeLibrary)
    _Invalid_handle_(0)
    _Also_usable_for_(HINSTANCE));

DECLARE_HANDLE_WIN32METADATA(HFILE,
    _Close_handle_with_(CloseHandle)
    _Invalid_handle_(-1)
    _Invalid_handle_(0));

// (3) Typedef-style handles and value wrappers — same vocabulary,
//     explicit underlying type.
DECLARE_TYPEDEF_WIN32METADATA(BCRYPT_ALG_HANDLE, void*,
    _Close_handle_with_(BCryptCloseAlgorithmProvider));

DECLARE_TYPEDEF_WIN32METADATA(MSIHANDLE, unsigned int,
    _Close_handle_with_(MsiCloseHandle));

DECLARE_TYPEDEF_WIN32METADATA(BOOL, int);

DECLARE_TYPEDEF_WIN32METADATA(BSTR, OLECHAR*,
    _Close_handle_with_(SysFreeString));
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

## Coverage: Every Entry in `autoTypes.json`

`autoTypes.json` has ~280 entries. This proposal covers all of them with the three macros above (`DECLARE_HANDLE`, `DECLARE_HANDLE_WIN32METADATA`, `DECLARE_TYPEDEF_WIN32METADATA`).

### Category 1: `DECLARE_HANDLE` opaque-pointer handles (~166 entries)

Entries with `"ValueType": "DECLARE_HANDLE"`. The largest category; all fit the void-pointer wrapper shape.

```c
// shared/windef.h  ← currently: DECLARE_HANDLE(HMODULE);
DECLARE_HANDLE_WIN32METADATA(HMODULE,
    _Close_handle_with_(FreeLibrary)
    _Invalid_handle_(0)
    _Also_usable_for_(HINSTANCE));

// um/winuser.h  ← currently: DECLARE_HANDLE(HMENU);
DECLARE_HANDLE_WIN32METADATA(HMENU,
    _Close_handle_with_(DestroyMenu)
    _Invalid_handle_(-1)
    _Invalid_handle_(0));

// shared/windef.h  ← currently: DECLARE_HANDLE(HWND);
DECLARE_HANDLE(HWND);   // No metadata — keep the existing one-line form
```

Migration mapping:

| `autoTypes.json` field | Header equivalent |
|---|---|
| `Name` | Struct name in `DECLARE_HANDLE_WIN32METADATA` invocation |
| `Namespace` | Header partition placement |
| `ValueType: "DECLARE_HANDLE"` | The macro itself |
| `CloseApi` | `_Close_handle_with_(api)` |
| `InvalidHandleValues[]` | One `_Invalid_handle_(val)` per entry |
| `AlsoUsableFor` | `_Also_usable_for_(type)` |
| `NativeTypedef: true` | Implied by `w32m::handle` marker baked into the macro |

### Category 2: Typedef-style handles (~73 entries)

Entries with `"ValueType"` of `void*`, `IntPtr`, `UIntPtr`, `ulong`, `uint`, or `typedef struct _TP_X *`.

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

Distribution across underlying shapes:

| `autoTypes.json` `ValueType` | Examples | Count |
|---|---|---|
| `void*` | `BCRYPT_ALG_HANDLE`, `BCRYPT_HASH_HANDLE`, `AVRT_TASK_HANDLE` | ~32 |
| `IntPtr` | `EVT_HANDLE`, `HDEVINFO`, `HDPA`, `HCRYPTASYNC` | ~16 |
| `UIntPtr` | `HACCESSOR`, `JET_HANDLE`, `HCRYPTPROV_LEGACY` | ~16 |
| `ulong` | `CONTROLTRACE_HANDLE`, `PROCESSTRACE_HANDLE` | ~4 |
| `uint` | `MSIHANDLE`, `OLE_HANDLE` | ~2 |
| `typedef struct _TP_*` | `PTP_IO`, `PTP_TIMER`, `PTP_POOL` | ~7 |

Migration mapping is the same as Category 1, except the `ValueType` becomes the second macro argument rather than implied.

### Category 3: Value wrappers (~10 entries)

Non-handle typedefs that exist in `autoTypes.json` only because the pipeline needs an explicit "wrap as `[NativeTypedef]`" signal. Most have no metadata; `BSTR` has a close API.

| Type | Header | Current SDK declaration | Proposed |
|---|---|---|---|
| `BOOL` | `shared/minwindef.h:157` | `typedef int BOOL;` | `DECLARE_TYPEDEF_WIN32METADATA(BOOL, int);` |
| `BOOLEAN` | `shared/ntdef.h:1676` | `typedef UCHAR BOOLEAN;` | `DECLARE_TYPEDEF_WIN32METADATA(BOOLEAN, unsigned char);` |
| `VARIANT_BOOL` | `shared/wtypes.h:745` | `typedef short VARIANT_BOOL;` | `DECLARE_TYPEDEF_WIN32METADATA(VARIANT_BOOL, short);` |
| `HRESULT` | `shared/intsafe.h:172` (canonical; redefined in 4 other headers under `#ifndef _HRESULT_DEFINED`) | `typedef _Return_type_success_(return >= 0) long HRESULT;` | `DECLARE_TYPEDEF_WIN32METADATA(HRESULT, long);` (see SAL caveat below) |
| `NTSTATUS` | `shared/ntdef.h:1062` | `typedef _Return_type_success_(return >= 0) LONG NTSTATUS;` | `DECLARE_TYPEDEF_WIN32METADATA(NTSTATUS, long);` (see SAL caveat below) |
| `LPARAM` | `shared/minwindef.h:187` (also `wtypes.h:160`) | `typedef LONG_PTR LPARAM;` | `DECLARE_TYPEDEF_WIN32METADATA(LPARAM, intptr_t);` |
| `WPARAM` | `shared/minwindef.h:186` (also `wtypes.h:151`) | `typedef UINT_PTR WPARAM;` | `DECLARE_TYPEDEF_WIN32METADATA(WPARAM, uintptr_t);` |
| `LRESULT` | `shared/minwindef.h:188` (also `wtypes.h:165`) | `typedef LONG_PTR LRESULT;` | `DECLARE_TYPEDEF_WIN32METADATA(LRESULT, intptr_t);` |
| `BSTR` | `shared/wtypes.h:737` | `typedef OLECHAR *BSTR;` | `DECLARE_TYPEDEF_WIN32METADATA(BSTR, OLECHAR*, _Close_handle_with_(SysFreeString));` |
| `PSID` | `shared/WTypesbase.h:242` | `typedef PVOID PSID;` | `DECLARE_TYPEDEF_WIN32METADATA(PSID, void*);` |
| `PSTR`/`PWSTR`/`PCSTR`/`PCWSTR` | `shared/winnt.h` (varies) | `typedef CHAR *PSTR;` etc. | Same pattern. CsWin32 has manual templates that depend on the wrapper struct existing — preserved unchanged because the wrapper struct is still emitted. |

### Category 4: Special-form types (~3 entries)

`autoTypes.json` defines two special `ValueType` keywords (`DECLARE_OPAQUE_KEY`, `AllJoynHandle`) that `NativeTypedefStructsCreator` translates internally. With the typed macro they collapse to ordinary entries:

```c
// CF_CONNECTION_KEY (currently ValueType: DECLARE_OPAQUE_KEY → long)
DECLARE_TYPEDEF_WIN32METADATA(CF_CONNECTION_KEY, long long);

// AllJoyn handles (currently ValueType: AllJoynHandle → IntPtr)
DECLARE_TYPEDEF_WIN32METADATA(alljoyn_msgarg, intptr_t);
```

Both special keywords are removed; the `NativeTypedefStructsCreator` translation logic is no longer needed.

### Category 5: Dropped — `AlsoUsableFor` on non-handle structs (1 entry)

`emitter.settings.rsp` contains `DEVPROPKEY=[AlsoUsableFor("PROPERTYKEY")]`. Both CsWin32 and windows-rs only generate conversion code for `[NativeTypedef]`-shaped structs — for regular multi-field structs like `DEVPROPKEY`, the attribute is dormant (verified by source inspection). **Recommend dropping this entry entirely** as part of this work and observing whether anything regresses.

---

## Caveats Requiring Specific Solutions

These were the open points blocking full removal of `autoTypes.json`. Each has a concrete plan, not a deferral.

### Caveat 1: Multiple declaration sites

`HRESULT` is declared in 5 headers (`intsafe.h`, `ntdef.h`, `strsafe.h`, `winerror.h`, `WTypesbase.h`), each behind `#ifndef _HRESULT_DEFINED`. `LPARAM`/`WPARAM`/`LRESULT`/`BOOLEAN`/`BSTR` have similar duplicates across `.h` and `.Idl` siblings.

**Plan:** the migration tool selects exactly one canonical declaration site per type (the earliest one in scrape order). All other sites continue to be guarded by their existing `#ifndef`s. The `_WIN32METADATA_` substitution emits the wrapper struct only at the canonical site; the other `#ifndef`-guarded redefinitions still see the original typedef during normal compilation, but during metadata generation they are skipped because the canonical declaration has already defined the struct.

### Caveat 2: SAL on the underlying type

`HRESULT` and `NTSTATUS` carry `_Return_type_success_(return >= 0)` SAL on the typedef itself.

**Resolution:** No special handling needed. The win32metadata pipeline already does not preserve typedef SAL into the winmd; success contracts are applied per-function via `emitter.settings.rsp` entries like `IUnknown::QueryInterface=[CanReturnErrorsAsSuccess]` (verified in source). The simple `DECLARE_TYPEDEF_WIN32METADATA(HRESULT, long)` form drops the typedef SAL but loses no winmd information, because today's winmd output also drops it.

### Caveat 3: String wrapper templates

CsWin32 has hand-written templates for `PSTR`/`PWSTR`/`PCSTR`/`PCWSTR`/`BSTR`/`HRESULT`/`NTSTATUS`/`BOOL`/`BOOLEAN`/`VARIANT_BOOL` that add `IndexOf`, `ToString`, marshalling, etc. to the generated wrapper struct.

**Plan:** no projection-side change is needed. The CsWin32 template extension keys off the struct *name* (e.g., the switch in `Generator.TypeDef.cs:234` matches `case "PWSTR":`). As long as the wrapper struct named `PWSTR` exists in the winmd with `[NativeTypedef]`, the template extension fires. Both behaviors are preserved by this proposal.

### Caveat 4: Empty-namespace handle entries

~38 `DECLARE_HANDLE` entries in `autoTypes.json` have no explicit `Namespace` field; `NativeTypedefStructsCreator` derives it from the `CloseApi`'s namespace.

**Plan:** with shift-left, the namespace is determined by the partition the header is included in. The migration tool verifies that placing `DECLARE_HANDLE_WIN32METADATA(NAME, ...)` in the header where the type is currently declared produces the same final namespace. For the rare case where the header is included by multiple partitions, `requiredNamespacesForNames.rsp` already provides an override mechanism — same as today.

### Caveat 5: Same-namespace validation

`NativeTypedefStructsCreator` enforces that `CloseApi` and `AlsoUsableFor` references resolve in the same namespace as the type itself.

**Plan:** move this validation into a post-scan step in the emitter (`MetadataSyntaxTreeCleaner` or a sibling pass) that runs once per scrape. For each `[RAIIFree]` and `[AlsoUsableFor]` attribute, verify the named target exists in the same namespace. Throw on mismatch with the same error message as today.

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

1. **Add `win32metadata.h`** with the `_Close_handle_with_` / `_Invalid_handle_` / `_Also_usable_for_` annotation macros and the three structural macros (`DECLARE_HANDLE` redefinition, `DECLARE_HANDLE_WIN32METADATA`, `DECLARE_TYPEDEF_WIN32METADATA`).
2. **Add `-D_WIN32METADATA_=1`** to `baseSettings.rsp` (already validated separately by the enum proposal) and `#include "win32metadata.h"` to the scraper include chain.
3. **Extend `MetadataSyntaxTreeCleaner`** to recognize `[NativeAnnotation("w32m::handle")]`, `w32m::raii_free=...`, `w32m::invalid_handle=...`, `w32m::also_usable_for=...` and emit the corresponding managed attributes. Move the same-namespace validation from `NativeTypedefStructsCreator` into a post-scan pass here (Caveat 5).
4. **Build a migration tool** that reads each `autoTypes.json` entry, locates its current SDK header declaration, and rewrites it to the appropriate macro form via the patch system from `shift-left-metadata-plan.md`. The tool handles canonical-site selection (Caveat 1) and namespace verification (Caveat 4).
5. **Validate winmd equivalence** — compare winmd output type-by-type against the baseline. Validation passes if every type that previously had `[NativeTypedef]`, `[RAIIFree]`, `[InvalidHandleValue]`, or `[AlsoUsableFor]` still carries the same set of attributes with the same values.
6. **Drop the `DEVPROPKEY=[AlsoUsableFor("PROPERTYKEY")]` line** from `emitter.settings.rsp` (Category 5).
7. **Remove `autoTypes.json`**, `NativeTypedefStructsCreator.cs`, `AutoType.cs`, `PrepSettingsForAutoTypes.cs`, and the JSON load path in `Windows.Win32.proj`.
8. **Eventually push these macros into the official SDK headers**, mirroring the SAL adoption path.

After step 7, `autoTypes.json` no longer exists. The header is the single source of truth for every handle and value typedef in the winmd.

---

## Resolved Decisions

The three questions that were open during proposal drafting have been resolved by source/data inspection:

### Decision 1: Phasing — land as a single proposal

The migration applies the same shift-left mechanism to all 280-ish entries. Splitting Category 1 (DECLARE_HANDLE) from Categories 2-4 (typedef-style + value wrappers) would require keeping `NativeTypedefStructsCreator`, `AutoType.cs`, and a partial `autoTypes.json` in production for the duration of the split — adding code-path complexity that's purely temporary. **Land as one proposal.** PR review can still proceed category-by-category if reviewers prefer.

### Decision 2: Overlay headers in Phase 1, in-place SDK patches in Phase 2

Same approach the enum proposal uses: prototype with partition-local overlay headers (`generation/WinSDK/Partitions/<P>/handles.h`) included by each partition's `main.cpp`, ahead of the SDK `#include`s. This keeps the SDK headers untouched during validation. Phase 2 moves the annotations into the SDK headers themselves via the shared patch system from `shift-left-metadata-plan.md`. The transition between phases is mechanical: the same macro invocations move from overlay files into the canonical declaration sites.

### Decision 3: Keep `DECLARE_HANDLE_WIN32METADATA` and `DECLARE_TYPEDEF_WIN32METADATA` as distinct macros

The two macros differ in their `#else` (normal-compilation) branch:

| Macro | `#else` expansion | Matches SDK form |
|---|---|---|
| `DECLARE_HANDLE_WIN32METADATA(name, ...)` | `DECLARE_HANDLE(name)` → `struct name__; typedef struct name__ *name` | Existing `DECLARE_HANDLE` users (Category 1) |
| `DECLARE_TYPEDEF_WIN32METADATA(name, type, ...)` | `typedef type name` | Existing typedef users (Categories 2-4) |

Verified by inspecting the 32 `void*`-underlying entries: every one of them is declared in the SDK as `typedef PVOID NAME;`, **not** as `DECLARE_HANDLE(NAME)`. Examples: `bcrypt.h:451-454` declares `BCRYPT_HANDLE`/`BCRYPT_ALG_HANDLE`/`BCRYPT_KEY_HANDLE`/`BCRYPT_HASH_HANDLE` all as `typedef PVOID`. Collapsing the two macros would force a different normal-compilation shape on these types — a source-compat change we shouldn't make.

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

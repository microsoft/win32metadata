# Enum Remapping Proposal: Replacing enums.json with Header Declarations

*Created: April 2026*
*Status: Proposal — validated end-to-end with ClangSharp v17*

---

## Summary

This proposal replaces the `enums.json` sidecar file (~37K lines, ~1,072 enum
definitions) with conditional C++ enum declarations in the SDK headers, eliminating
the need for JSON-driven enum synthesis entirely.

The approach has been validated end-to-end: a proof-of-concept replaced the
`SET_THEME_APP_PROPERTIES_FLAGS` entry in `enums.json` with a conditional enum in
`Uxtheme.h`, producing an identical winmd with all 13 `Windows.Win32.Tests` passing
and zero tooling code changes.

---

## Background

Windows SDK headers express many logically-related constants as groups of `#define`s:

```c
#define STAP_ALLOW_NONCLIENT    (1UL << 0)
#define STAP_ALLOW_CONTROLS     (1UL << 1)
#define STAP_ALLOW_WEBCONTENT   (1UL << 2)
```

In the metadata (winmd), these should appear as a typed flags enum:

```csharp
[Flags]
public enum SET_THEME_APP_PROPERTIES_FLAGS : uint {
    ALLOW_NONCLIENT  = 1,
    ALLOW_CONTROLS   = 2,
    ALLOW_WEBCONTENT = 4,
}
```

Today, `enums.json` encodes this mapping — the enum name, flags attribute, member
names and values, and which function parameters/struct fields should use the enum type.

The SDK already contains ~8,600 real enum declarations (e.g., `D3D12_RESOURCE_STATES`,
`DXGI_ADAPTER_FLAG3`) that ClangSharp processes natively. This proposal addresses the
~1,072 `#define`-based groups that currently require `enums.json` to be "lifted" into
enums.

---

## Proposed Approach: Conditional Enum Declarations

### Core pattern

```cpp
#ifdef _WIN32METADATA_

enum [[clang::flag_enum]] SET_THEME_APP_PROPERTIES_FLAGS : DWORD {
    ALLOW_NONCLIENT  = STAP_ALLOW_NONCLIENT,
    ALLOW_CONTROLS   = STAP_ALLOW_CONTROLS,
    ALLOW_WEBCONTENT = STAP_ALLOW_WEBCONTENT,
    VALIDBITS = STAP_ALLOW_NONCLIENT | STAP_ALLOW_CONTROLS | STAP_ALLOW_WEBCONTENT,
};
DEFINE_ENUM_FLAG_OPERATORS(SET_THEME_APP_PROPERTIES_FLAGS)

#else
#define SET_THEME_APP_PROPERTIES_FLAGS DWORD
#endif
```

The `#else` branch defines the enum name as a macro expanding to `DWORD`. This means
function signatures can use `SET_THEME_APP_PROPERTIES_FLAGS` unconditionally — no
`#ifdef` needed at each call site:

```c
THEMEAPI_(SET_THEME_APP_PROPERTIES_FLAGS)
GetThemeAppProperties(VOID);

THEMEAPI_(void)
SetThemeAppProperties(_In_ SET_THEME_APP_PROPERTIES_FLAGS dwFlags);
```

During metadata generation (`_WIN32METADATA_` defined), ClangSharp sees the real enum
type. During normal compilation, the macro expands to `DWORD` — zero behavior change.

### How it works

- **`#ifdef _WIN32METADATA_`** — Only active during metadata generation (defined in
  `baseSettings.rsp` as `-D_WIN32METADATA_=1`). Invisible to normal SDK consumers.
- **`#else #define NAME DWORD`** — The enum name becomes a DWORD macro for normal
  compilation, allowing unconditional use in function signatures with no `#ifdef`s
  at call sites.
- **Modern C++ syntax** — `enum NAME : base_type`, no `typedef` needed.
- **`[[clang::flag_enum]]`** — Clang's standard attribute for bitmask enums (see
  [Clang Attribute Reference](https://clang.llvm.org/docs/AttributeReference.html#flag-enum)).
  Signals intent; does not affect code generation.
- **`DEFINE_ENUM_FLAG_OPERATORS(NAME)`** — The existing Windows SDK convention for
  enabling bitwise operators on enums. The ConstantsScraper already detects this
  macro (text-level regex) and generates `[Flags]` — no tooling changes needed.
- **Member values reference original `#define` macros** — The preprocessor computes
  the actual values. No manual value duplication needed for renamed members.

### Validated with ClangSharp v17

All scenarios were tested (test files in `obj/enum-annotation-test/`):

| Scenario | Result |
|---|---|
| Conditional enum declarations | ✅ ClangSharp generates C# enum natively |
| C++11 enum base types (`: unsigned char`, etc.) | ✅ Maps to `byte`, `ushort`, etc. |
| Signed overflow (`(int)0xFFFFFFFF`) | ✅ Auto-generates `unchecked()` |
| Function params/return types get enum type | ✅ |
| `DEFINE_ENUM_FLAG_OPERATORS` → `[Flags]` | ✅ Existing text detection works |
| `#else #define NAME DWORD` pattern | ✅ Unconditional use in signatures |

---

### Three member patterns

**Pattern 1: Renamed members** (new name ≠ `#define` name)

No macro conflict — reference the `#define` directly:

```cpp
enum SET_THEME_APP_PROPERTIES_FLAGS : DWORD {
    ALLOW_NONCLIENT  = STAP_ALLOW_NONCLIENT,   // preprocessor resolves to 1
    ALLOW_CONTROLS   = STAP_ALLOW_CONTROLS,     // preprocessor resolves to 2
    ALLOW_WEBCONTENT = STAP_ALLOW_WEBCONTENT,    // preprocessor resolves to 4
};
```

**Pattern 2: Same-name members** (enum member name = `#define` name)

Use `push_macro`/`undef`/`pop_macro` to suppress macro expansion inside the enum:

```cpp
#pragma push_macro("FILE_ATTRIBUTE_READONLY")
#pragma push_macro("FILE_ATTRIBUTE_HIDDEN")
#undef FILE_ATTRIBUTE_READONLY
#undef FILE_ATTRIBUTE_HIDDEN

enum [[clang::flag_enum]] FILE_ATTRIBUTE_FLAGS : DWORD {
    FILE_ATTRIBUTE_READONLY = 0x00000001,
    FILE_ATTRIBUTE_HIDDEN   = 0x00000002,
};
DEFINE_ENUM_FLAG_OPERATORS(FILE_ATTRIBUTE_FLAGS)

#pragma pop_macro("FILE_ATTRIBUTE_READONLY")
#pragma pop_macro("FILE_ATTRIBUTE_HIDDEN")
```

Values are repeated from the `#define`s. This is acceptable — they're canonical values
in the same header.

**Pattern 3: Signed/unsigned overflow**

Use a C cast — ClangSharp generates `unchecked()` automatically:

```cpp
enum OBJECT_IDENTIFIER : int {
    OBJID_WINDOW  = 0,
    OBJID_SYSMENU = (int)0xFFFFFFFF,   // → unchecked((int)(0xFFFFFFFF))
};
```

### Flags enums

There is no C++ standard `[[bitmask]]` attribute (not even in C++26).

Flags enums use two complementary mechanisms:

1. **`[[clang::flag_enum]]`** — Clang's standard attribute marking the enum as a
   bitmask type. Provides compiler diagnostics for non-power-of-two values and
   documents intent.

2. **`DEFINE_ENUM_FLAG_OPERATORS(NAME)`** — The existing Windows SDK convention
   (defined in `winnt.h`) that enables bitwise operators (`|`, `&`, `^`, `~`) on
   the enum type. The ConstantsScraper already detects this macro via text-level
   regex and adds `[Flags]` to the generated C# enum — no tooling changes needed.

### Underlying types

C++11 enum base types map directly to .NET types:

| C++ base | .NET type | Example |
|---|---|---|
| `DWORD` / `: unsigned int` | `uint` | Most enums |
| `: int` (default) | `int` | Signed enums |
| `: unsigned char` | `byte` | `FONT_CHARSET` |
| `: unsigned short` | `ushort` | `CLIPBOARD_FORMAT` |
| `: unsigned long long` | `ulong` | `GPT_ATTRIBUTES` |
| `: signed char` | `sbyte` | `PFD_LAYER_TYPE` |
| `: short` | `short` | `DEVMODE_COLOR` |

---

## Constant Suppression: Avoiding Duplicates

### The problem

When a conditional enum is added, the original `#define`s still exist in the header.
The ConstantsScraper reads headers as text and would emit each `#define` as a standalone
constant — producing duplicates alongside the ClangSharp-generated enum members.

### How it works today

The ConstantsScraper has two suppression mechanisms:

1. **`enumMemberNameToEnumObj`** — loaded from `enums.json`. When a `#define` name
   matches an enum member, it's claimed by the enum and not emitted as a constant.
2. **`manualEnumMemberNames`** — loaded from `*.manual.cs` files. Constants matching
   hand-written C# enum members are suppressed.

### What changes

Since `ScrapeConstants` runs AFTER `ScrapeHeaders` (ClangSharp), the ClangSharp-generated
C# files already contain the conditional enum declarations. The ConstantsScraper can read
those files to build a suppression set — the same approach already used for manual enums:

```csharp
// Extend the existing pattern:
HashSet<string> generatedEnumMembers = LoadEnumMemberNamesFromGeneratedSources();

// In the scraping loop, suppress constants that are already enum members:
if (!manualEnumMemberNames.Contains(name) && !generatedEnumMembers.Contains(name))
{
    this.AddConstantInteger(...);
}
```

This is a small, surgical change. The `EnumObject.LoadFromFile()` method already knows
how to parse C# enum declarations. The suppression becomes data-driven from the build
pipeline rather than from a sidecar file.

Note: for renamed members (Pattern 1), the enum member names differ from the `#define`
names (e.g., `ALLOW_NONCLIENT` vs `STAP_ALLOW_NONCLIENT`), so no suppression is needed —
there's no collision.

---

## What about autoPopulate?

Today, 257 enums use `autoPopulate` — a regex filter like `FILE_ATTRIBUTE_` that
auto-discovers all matching `#define`s from a header. With explicit enum declarations,
autoPopulate is replaced by explicitly listing all members. This is better:

- **Explicit and auditable** — every member visible in the declaration
- **No silent additions** — new SDK `#define`s don't join an enum without review
- **The header IS the source of truth**
- **Simpler tooling** — no regex matching needed

---

## Where the Declarations Live

**Phase 1: Overlay headers** — Create files like
`generation/WinSDK/Partitions/Foundation/enums.h` that are `#include`d per partition.
Avoids modifying SDK headers during prototyping.

**Phase 2: SDK header patches** — Move declarations into the SDK headers themselves
(via the patch system from `shift-left-metadata-plan.md`), adjacent to the `#define`
groups they formalize.

---

## Migration from enums.json

Every field in enums.json maps to a header construct:

| enums.json field | Header equivalent |
|---|---|
| `name` | `enum NAME` |
| `flags` | `[[clang::flag_enum]]` + `DEFINE_ENUM_FLAG_OPERATORS(NAME)` |
| `type` | C++ enum base (`: DWORD`, `: unsigned char`, etc.) |
| `members[].name` | Enum member identifier |
| `members[].value` | Literal value or `#define` macro reference |
| `uses` (method/param) | Direct parameter typing via `#else #define NAME DWORD` |
| `uses` (struct/field) | Direct field typing via `#else #define NAME DWORD` |
| `uses` (return) | Direct return typing via `#else #define NAME DWORD` |
| `autoPopulate` | Explicit member list (replaces regex) |
| `namespace` | Partition placement determines namespace |

---

## Implementation Steps

1. **Build a migration tool** — converts each `enums.json` entry into a conditional
   enum declaration block
2. **Create overlay headers** with the generated declarations
3. **Add `-D_WIN32METADATA_=1` to `baseSettings.rsp`** (already validated)
4. **Extend ConstantsScraper** to suppress `#define`s that are already ClangSharp-generated
   enum members (for same-name member patterns)
5. **Validate winmd equivalence** — compare winmd output before/after
6. **Remove `enums.json`** and simplify ConstantsScraper enum pipeline
7. **Move to SDK header patches** when the patch system is ready

---

## Open Questions

1. **Expression-form values**: ClangSharp outputs `(1U << 0)` rather than `1` when
   referencing macros. Does the full pipeline handle this, or must values be
   pre-evaluated literals?

2. **Cross-partition enums**: Some enums reference `#define`s from multiple headers.
   The enum declaration must be in a partition that includes all relevant headers.

---

## Other Alternatives Considered

### `#pragma w32m` directives

```c
#pragma w32m enum_begin(THREAD_CREATION_FLAGS, flags)
#define THREAD_CREATE_RUN_IMMEDIATELY  0
#define THREAD_CREATE_SUSPENDED        4
#pragma w32m enum_end
```

**Rejected**: `#pragma` directives don't survive into the Clang AST. Custom pragmas
are silently ignored by Clang. Would require text-level parsing in the ConstantsScraper
rather than leveraging ClangSharp's native enum processing.

### Structured comments (Doxygen-style)

```c
/// @w32m:enum THREAD_CREATION_FLAGS flags
#define THREAD_CREATE_RUN_IMMEDIATELY  0
/// @w32m:enum_end
```

**Rejected**: Comments are invisible to the AST. Same text-parsing limitations as
pragmas, with the added fragility of being easily broken by reformatting tools.

### `_Enum_type_(name)` parameter annotations

```c
void SetThemeAppProperties(
    _Enum_type_(SET_THEME_APP_PROPERTIES_FLAGS) DWORD dwFlags
);
```

**Not needed for the primary approach**: When the conditional enum type exists in the
same translation unit, function signatures can use the enum type directly (via the
`#else #define NAME DWORD` pattern). The `_Enum_type_` annotation approach may still
be useful for cross-partition references where the enum type isn't visible, but it
requires emitter changes to process `w32m:enumtype=` annotations.

### AST-based `flag_enum` detection (Win32MetadataScraper)

Detecting `CX_AttrKind_FlagEnum` in the AST and injecting `[Flags]` via
PInvokeGenerator's `WithAttributes`.

**Not needed**: `DEFINE_ENUM_FLAG_OPERATORS` is already detected by the ConstantsScraper
and handles `[Flags]` without any tooling changes. The `[[clang::flag_enum]]` attribute
is still included for documentation and compiler diagnostics, but `[Flags]` generation
relies on the existing `DEFINE_ENUM_FLAG_OPERATORS` path.

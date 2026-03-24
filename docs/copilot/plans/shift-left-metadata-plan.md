# Shift-Left Metadata: Moving Sidecar Metadata Into Headers

*Created: March 2026*
*Workstream: 4 — Shift-Left Metadata Definition*
*Branch: user/jevansaks/shift-left-metadata*

---

## Executive Summary

Win32metadata currently defines critical API semantics — RAII handles, enum groupings,
SetLastError behavior, OS version support, and more — in **sidecar files** (`.rsp`, `.json`)
that live outside the Windows SDK headers. This plan details how to move each class of
metadata into the headers themselves, using a SAL-like annotation mechanism that's already
proven in the Windows SDK. We'll use a structured patch system to apply these annotations
to ingested SDK headers until the official SDK adopts them.

**Key finding (March 2026):** ClangSharp v18+ (via PR [#552](https://github.com/dotnet/ClangSharp/pull/552))
added `[NativeAnnotation("...")]` support that preserves `__attribute__((annotate(...)))`
on **all declaration types** — functions, parameters, struct fields, and return values.
This repo currently pins v17.0.1 which only supports parameter-level annotations.
**Upgrading ClangSharp to v18+ unblocks the entire shift-left strategy with no
workarounds or extraction tools needed.**

---

## Problem Statement

Today, ~170,000+ lines of metadata across 15+ sidecar files encode information that
*should* live in the C/C++ headers:

| Sidecar File | Lines | Entries | What It Encodes |
|---|---|---|---|
| `supportedOS.rsp` | 17,249 | ~8,600 | OS version each API requires |
| `documentationMappings.rsp` | 90,511 | ~45,000 | Microsoft Learn URLs |
| `enums.json` | 37,096 | ~500+ | Synthetic enum definitions |
| `libMappings.rsp` | 26,808 | ~13,400 | Function → DLL mappings |
| `scraper.settings.rsp` | 12,891 | ~1,600 | Type remaps, tag→name fixes |
| `WithSetLastError.rsp` | 3,366 | ~1,600 | SetLastError functions |
| `autoTypes.json` | 2,984 | ~280 | Handle types with close APIs |
| `emitter.settings.rsp` | 2,396 | varies | Member remaps, enum additions |
| `libMappingsManual.rsp` | 387 | ~190 | Manual DLL overrides |
| `functionPointerFixups.json` | 731 | ~200 | Function pointer name fixes |
| `manual/` (69 C# files) | varies | — | Hand-written type definitions |

This creates three problems:
1. **Drift** — sidecar data goes stale as SDK headers evolve
2. **Bugs fixed in the wrong place** — SDK errors get papered over here rather than at source
3. **Fragile maintenance** — each SDK update requires hand-curating these files

---

## The SAL Precedent: How This Already Works

The key insight is that **SAL annotations already do exactly what we need** — they embed
tool-readable metadata in C/C++ headers with zero compilation impact. The mechanism
(from `sal.h` lines 1593-1611):

```c
// When Clang is the compiler (ClangSharp uses Clang):
#if __clang__
  #define _SA_annotes0(n)   __attribute__((annotate("Name=" #n)))
  #define _SA_annotes1(n,p) __attribute__((annotate("Name=" #n "; p1=" #p)))

// When MSVC is the compiler:
#else
  #define _SA_annotes0(n)   __declspec(#n)
  #define _SA_annotes1(n,p) __declspec(#n "(" #p ")")
#endif

// When no analysis tool is running (_PREFAST_ not defined):
// All of the above expand to nothing — zero cost
```

ClangSharp already processes these annotations:
1. `baseSettings.rsp` sets `-D_PREFAST_=1` and `-D_USE_DECLSPECS_FOR_SAL=1`
2. `generate-cpp-attributes` config flag causes ClangSharp to emit them as C# attributes
3. `MetadataSyntaxTreeCleaner.cs` parses `CppAttributeList` nodes, extracts `SalAttribute`
   objects with `Name`, `p1`, `p2`, `p3` fields, and converts them to managed attributes

**Our custom annotations will follow this exact pattern.**

---

## Annotation Mechanism Design

### Header: `win32metadata.h`

A new header that defines metadata annotation macros. It follows the SAL conditional
compilation pattern:

```c
// win32metadata.h — Win32 Metadata Annotations
//
// These annotations encode metadata for the win32metadata tooling.
// When processed by ClangSharp (via Clang), they expand to
// __attribute__((annotate(...))) nodes visible in the AST.
// In normal compilation, they expand to nothing — zero cost.

#pragma once

#ifdef _WIN32METADATA_  // Defined in ClangSharp baseSettings.rsp

  #ifdef __clang__
    // Clang path — use annotate attribute (what ClangSharp actually sees)
    #define _W32M_anno0(key)         __attribute__((annotate("w32m:" key)))
    #define _W32M_anno1(key, v1)     __attribute__((annotate("w32m:" key "=" v1)))
    #define _W32M_anno2(key, v1, v2) __attribute__((annotate("w32m:" key "=" v1 ";" v2)))
  #else
    // MSVC path — use declspec (for potential future MSVC-based processing)
    #define _W32M_anno0(key)         __declspec("w32m_" key)
    #define _W32M_anno1(key, v1)     __declspec("w32m_" key "(" v1 ")")
    #define _W32M_anno2(key, v1, v2) __declspec("w32m_" key "(" v1 "," v2 ")")
  #endif

#else
  // Normal compilation — expand to nothing
  #define _W32M_anno0(key)
  #define _W32M_anno1(key, v1)
  #define _W32M_anno2(key, v1, v2)
#endif

// ── Function-Level Annotations ──────────────────────────────────────

// Function calls SetLastError on failure
#define _Sets_last_error_              _W32M_anno0("setlasterror")

// Minimum OS version required (e.g., "10.0.19041")
#define _Min_os_version_(ver)          _W32M_anno1("minversion", #ver)

// Function's return value must be freed with the named function
#define _Must_close_with_(func)        _W32M_anno1("raiifree", #func)

// Function may return error codes that look like success (HRESULT)
#define _Can_return_errors_as_success_ _W32M_anno0("errorsassuccess")

// Function may return multiple distinct success values
#define _Multiple_success_values_      _W32M_anno0("multiplesuccess")

// ── Type-Level Annotations (on DECLARE_HANDLE / typedef) ────────────

// Handle/resource cleanup function
#define _Close_handle_with_(func)      _W32M_anno1("closeapi", #func)

// Sentinel value indicating invalid handle
#define _Invalid_handle_(val)          _W32M_anno1("invalidhandle", #val)

// This handle type is interchangeable with another
#define _Also_usable_for_(type)        _W32M_anno1("alsousablefor", #type)

// ── Parameter-Level Annotations ─────────────────────────────────────

// Pointer parameter is a COM out-pointer (ppv pattern)
#define _Com_out_ptr_                  _W32M_anno0("comoutptr")

// Caller must not release this handle/pointer
#define _Do_not_release_               _W32M_anno0("donotrelease")

// Not null-terminated (overrides default assumption for string types)
#define _Not_null_terminated_          _W32M_anno0("notnullterm")

// Double-null-terminated string (e.g., environment blocks)
#define _Null_null_terminated_         _W32M_anno0("nullnullterm")

// Array whose count comes from another parameter (by zero-based index)
#define _Array_count_param_(idx)       _W32M_anno1("arraycountparam", #idx)

// Array with a fixed element count
#define _Array_count_(n)               _W32M_anno1("arraycountconst", #n)

// Memory size comes from another parameter (by zero-based index)
#define _Memory_size_param_(idx)       _W32M_anno1("memsizeparam", #idx)
```

### How It Flows Through ClangSharp

```
┌──────────────────────────────────────────────────────────────────┐
│  SDK Header (with annotations)                                   │
│                                                                  │
│  _Sets_last_error_                                               │
│  BOOL WINAPI CreateFileA(                                        │
│      _In_ LPCSTR lpFileName, ...);                               │
│                                                                  │
│  With -D_WIN32METADATA_=1, expands to:                           │
│  __attribute__((annotate("w32m:setlasterror")))                  │
│  BOOL WINAPI CreateFileA(                                        │
│      __attribute__((annotate("Name=SAL_pre;..."))) ...);         │
└────────────────────┬─────────────────────────────────────────────┘
                     │ ClangSharp parses with Clang
                     ▼
┌──────────────────────────────────────────────────────────────────┐
│  Generated C# (ClangSharp output)                                │
│                                                                  │
│  [CppAttributeList("w32m:setlasterror")]                         │
│  [DllImport("kernel32.dll", SetLastError = true)]                │
│  public static extern BOOL CreateFileA(                          │
│      [In, MarshalAs(...)] string lpFileName, ...);               │
└────────────────────┬─────────────────────────────────────────────┘
                     │ MetadataSyntaxTreeCleaner processes
                     ▼
┌──────────────────────────────────────────────────────────────────┐
│  Cleaned C# (ready for winmd emission)                           │
│                                                                  │
│  [SetLastError]                  ← converted from w32m:          │
│  [DllImport("kernel32.dll")]                                     │
│  public static extern BOOL CreateFileA(...);                     │
└────────────────────┬─────────────────────────────────────────────┘
                     │ ClangSharpSourceWinmdGenerator writes
                     ▼
┌──────────────────────────────────────────────────────────────────┐
│  Windows.Win32.winmd                                             │
│  Method: CreateFileA  [SetLastError, DllImport("kernel32.dll")]  │
└──────────────────────────────────────────────────────────────────┘
```

### Processing Changes in MetadataSyntaxTreeCleaner

The existing `CreateAttributeListForSal` method processes `CppAttributeList` nodes by
parsing SAL attributes (delimited with `^`, fields delimited with `;`). We need to add
a parallel path for `w32m:` prefixed annotations:

```csharp
// In CreateAttributeListForSal, after getting the annotate string:
if (annotateText.StartsWith("w32m:"))
{
    return ProcessWin32MetadataAnnotation(annotateText.Substring(5));
}

// New method:
private AttributeSyntax ProcessWin32MetadataAnnotation(string annotation)
{
    // Parse "key=value" or just "key"
    var eqIndex = annotation.IndexOf('=');
    var key = eqIndex >= 0 ? annotation.Substring(0, eqIndex) : annotation;
    var value = eqIndex >= 0 ? annotation.Substring(eqIndex + 1) : null;

    return key switch
    {
        "setlasterror"    => /* mark for SetLastError */,
        "raiifree"        => MakeAttribute("RAIIFree", value),
        "closeapi"        => MakeAttribute("RAIIFree", value),
        "invalidhandle"   => MakeAttribute("InvalidHandleValue", long.Parse(value)),
        "minversion"      => MakeAttribute("SupportedOSPlatform", $"windows{value}"),
        "comoutptr"       => MakeAttribute("ComOutPtr"),
        "donotrelease"    => MakeAttribute("DoNotRelease"),
        "notnullterm"     => MakeAttribute("NotNullTerminated"),
        "nullnullterm"    => MakeAttribute("NullNullTerminated"),
        "errorsassuccess" => MakeAttribute("CanReturnErrorsAsSuccess"),
        "multiplesuccess" => MakeAttribute("CanReturnMultipleSuccessValues"),
        "arraycountparam" => MakeAttribute("NativeArrayInfo",
                                namedArg: ("CountParamIndex", int.Parse(value))),
        "arraycountconst" => MakeAttribute("NativeArrayInfo",
                                namedArg: ("CountConst", int.Parse(value))),
        "memsizeparam"    => MakeAttribute("MemorySize",
                                namedArg: ("BytesParamIndex", short.Parse(value))),
        "alsousablefor"   => MakeAttribute("AlsoUsableFor", value),
        _ => null // unknown annotation — log warning
    };
}
```

---

## Taxonomy of Sidecar Metadata Classes

Each class of sidecar metadata falls into one of three categories:

### Category A: Belongs in Headers (shift-left target)

These express *semantic properties of the API* and should be in the headers.

| Class | Current Location | Header Annotation | Entries | Difficulty |
|---|---|---|---|---|
| **SetLastError** | `WithSetLastError.rsp` | `_Sets_last_error_` on function | ~1,600 | Low |
| **OS Version** | `supportedOS.rsp` | `_Min_os_version_(...)` on function | ~8,600 | Low |
| **RAII/Close API** | `autoTypes.json` | `_Close_handle_with_(...)` on typedef | ~60 | Low |
| **Invalid Handle Values** | `autoTypes.json` | `_Invalid_handle_(...)` on typedef | ~40 | Low |
| **AlsoUsableFor** | `autoTypes.json` | `_Also_usable_for_(...)` on typedef | ~10 | Low |
| **RAII on return** | `emitter.settings.rsp` memberRemap | `_Must_close_with_(...)` on function | ~50 | Medium |
| **ComOutPtr** | `emitter.settings.rsp` memberRemap | `_Com_out_ptr_` on parameter | ~30 | Medium |
| **DoNotRelease** | `emitter.settings.rsp` memberRemap | `_Do_not_release_` on parameter | ~20 | Medium |
| **Const** | `emitter.settings.rsp` memberRemap | Already in SAL (`_Const_`) | ~100 | Low |
| **NotNullTerminated** | `emitter.settings.rsp` memberRemap | `_Not_null_terminated_` on param | ~10 | Low |
| **NullNullTerminated** | `emitter.settings.rsp` memberRemap | `_Null_null_terminated_` on param | ~10 | Low |
| **Array info** | `emitter.settings.rsp` memberRemap | `_Array_count_param_(n)` on param | ~50 | Medium |
| **MemorySize** | `emitter.settings.rsp` memberRemap | `_Memory_size_param_(n)` on param | ~20 | Medium |
| **ErrorsAsSuccess** | `emitter.settings.rsp` memberRemap | `_Can_return_errors_as_success_` | ~30 | Low |
| **MultipleSuccess** | `emitter.settings.rsp` memberRemap | `_Multiple_success_values_` | ~10 | Low |
| **Manual lib mappings** | `libMappingsManual.rsp` | `#pragma comment(lib, "...")` | ~190 | Low |

### Category B: Requires Header Refactoring (longer-term)

These require structural changes to the headers, not just annotations.

| Class | Current Location | What's Needed | Entries | Difficulty |
|---|---|---|---|---|
| **Synthetic enums** | `enums.json` | Change `#define` groups → `enum` types | ~500 | **High** |
| **Enum flags** | `emitter.settings.rsp` | Add annotation to enum typedef | ~80 | Medium |
| **Enum additions** | `emitter.settings.rsp` | Add missing members to enums | ~30 | Medium |
| **Function pointer fixups** | `functionPointerFixups.json` | Fix typedef naming inconsistencies | ~200 | Medium |
| **Tag→name remaps** | `scraper.settings.rsp` | Fix `tagFOO` → `FOO` at source | ~1,000 | Medium |
| **Type corrections** | `scraper/ConstantsScraperSettings` | Use correct types in `#define` | ~600 | High |
| **Manual C# overrides** | `manual/` (69 files) | Fix the APIs in headers/IDL | varies | **Very High** |

### Category C: Stays as Tooling Configuration

These are win32metadata tooling concerns, not properties of the APIs themselves.

| Class | Current Location | Why It Stays | Entries |
|---|---|---|---|
| **Partitions** | `Partitions/` dirs | Namespace organization is our concern | ~240 |
| **Namespace resolution** | `requiredNamespacesForNames.rsp` | Disambiguation for our mapping | ~1,300 |
| **Documentation URLs** | `documentationMappings.rsp` | External data from docs repos | ~45,000 |
| **Auto lib mappings** | `libMappings.rsp` | Generated from .lib files | ~13,400 |
| **Type imports** | `emitter.settings.rsp` | WinRT interop config | ~15 |
| **Cross-arch excludes** | `Windows.Win32.proj` | Build configuration | ~250 |
| **Handle type defs** | `autoTypes.json` (ValueType) | ClangSharp handle struct generation | ~280 |

---

## Patch Management System

Since the headers come from the Windows SDK NuGet package, we need a system to apply
annotations to them during ingestion.

### Design Principles

1. **Patches are structured, not diffs** — a JSON manifest identifies *what* to annotate
   on *which* declaration in *which* header, not line-based diffs that break on any change
2. **Idempotent** — applying a patch to a header that already has the annotation is a no-op
3. **Staleness detection** — when the official SDK adopts an annotation, the patch system
   detects it and reports the patch as "already applied / no longer needed"
4. **Per-SDK versioning** — patches track which SDK version they target; when the SDK
   updates, stale patches are flagged for review

### Patch Manifest Format: `patches.json`

```json
{
  "$schema": "patches.schema.json",
  "sdkVersion": "10.0.26100",
  "patches": [
    {
      "id": "setlasterror-CreateFileA",
      "header": "um/fileapi.h",
      "target": {
        "kind": "function",
        "name": "CreateFileA"
      },
      "annotation": "_Sets_last_error_",
      "placement": "before-return-type",
      "status": "pending",
      "sourceRsp": "WithSetLastError.rsp"
    },
    {
      "id": "minversion-AmsiInitialize",
      "header": "um/amsi.h",
      "target": {
        "kind": "function",
        "name": "AmsiInitialize"
      },
      "annotation": "_Min_os_version_(10.0.10240)",
      "placement": "before-return-type",
      "status": "pending",
      "sourceRsp": "supportedOS.rsp"
    },
    {
      "id": "raii-HANDLE",
      "header": "shared/ntdef.h",
      "target": {
        "kind": "typedef",
        "name": "HANDLE"
      },
      "annotations": [
        "_Close_handle_with_(CloseHandle)",
        "_Invalid_handle_(-1)",
        "_Invalid_handle_(0)"
      ],
      "placement": "before-typedef",
      "status": "pending",
      "sourceJson": "autoTypes.json"
    }
  ]
}
```

### Patch Application Tool: `Apply-MetadataPatches.ps1`

A PowerShell script (or .NET tool) that:

1. Reads `patches.json`
2. For each patch:
   a. Locates the target declaration in the header using a lightweight C parser or regex
   b. Checks if the annotation is already present (staleness detection)
   c. If not present, inserts the annotation at the specified placement
   d. If already present, marks the patch as `"adopted"` and logs it
3. Writes a report of applied/skipped/stale patches
4. Updates patch status in the manifest

### Staleness Detection

When we ingest a new SDK version:

```
┌─ Read patches.json for previous SDK version
│
├─ For each patch:
│   ├─ Find target declaration in new SDK header
│   ├─ Is annotation already present? ──→ Mark as "adopted by SDK"
│   ├─ Has declaration moved/renamed?  ──→ Mark as "needs review"
│   └─ Declaration still exists, no annotation ──→ Re-apply patch
│
└─ Generate migration report:
    - N patches still needed
    - M patches adopted by SDK (can be removed)
    - K patches need manual review (target moved/removed)
```

### Integration with Build Pipeline

The patch application step runs **before** ClangSharp scraping:

```
DoAll.ps1
  1. Ingest SDK headers (from NuGet or local)
  2. ★ Apply-MetadataPatches.ps1          ← NEW STEP
  3. RecompileIdlFilesForScraping.ps1
  4. BuildMetadataBin.ps1 (scrape + emit)
  5. Tests, packaging, etc.
```

---

## Phased Implementation Plan

### Phase 1: Foundation — Annotation Infrastructure

**Goal:** Establish the annotation mechanism and prove it works end-to-end.

**Tasks:**
1. **Upgrade ClangSharp from v17.0.1 to v18.1.0.4+** — This is the critical
   prerequisite. v18 adds `[NativeAnnotation("...")]` support for
   `__attribute__((annotate(...)))` on all declaration types (functions,
   parameters, struct fields, return values). Without this upgrade, only
   parameter-level annotations work. Update the version pin in
   `global.json` / `ScrapeHeaders.cs` and validate existing builds still pass.
2. Create `win32metadata.h` with the annotation macros
3. Add `-D_WIN32METADATA_=1` to `baseSettings.rsp`
4. Add `#include "win32metadata.h"` to the scraper include chain
5. Modify `MetadataSyntaxTreeCleaner` to recognize `[NativeAnnotation("w32m:...")]`
   attributes (v18 emits these instead of / in addition to `CppAttributeList`)
6. Convert a small pilot set (~20 functions) of `WithSetLastError.rsp` entries into
   header annotations and verify the winmd output is identical
7. Write tests comparing winmd output before/after

**Success criteria:** A header with `_Sets_last_error_` produces the same winmd metadata
as the current `--with-setlasterror` rsp entry.

### Phase 2: Simple Function Annotations

**Goal:** Move the three largest function-level sidecar files into header annotations.

| Sub-phase | Sidecar File | Entries | What Moves |
|---|---|---|---|
| 2a | `WithSetLastError.rsp` | ~1,600 | `_Sets_last_error_` on each function |
| 2b | `supportedOS.rsp` | ~8,600 | `_Min_os_version_(...)` on each function |
| 2c | `libMappingsManual.rsp` | ~190 | `#pragma comment(lib, "...")` in headers |

**Approach:** For each sub-phase:
1. Generate `patches.json` entries from the current `.rsp` file (scripted conversion)
2. Implement the patch application tool
3. Remove the corresponding `.rsp` entries as patches take over
4. Validate winmd output is identical via `CompareBinToLastRelease.ps1`

### Phase 3: Parameter and Return Value Annotations

**Goal:** Move emitter memberRemap annotations into headers.

| Annotation | Example | Count |
|---|---|---|
| `_Must_close_with_(func)` | `FindFirstFileA` → `FindClose` | ~50 |
| `_Com_out_ptr_` | COM `ppv` parameters | ~30 |
| `_Do_not_release_` | `GetProcessHeaps::ProcessHeaps` | ~20 |
| `_Not_null_terminated_` | Binary buffer parameters | ~10 |
| `_Null_null_terminated_` | Environment block params | ~10 |
| `_Array_count_param_(n)` | Counted array parameters | ~50 |
| `_Memory_size_param_(n)` | Memory size parameters | ~20 |
| `_Can_return_errors_as_success_` | HRESULT functions | ~30 |
| `_Multiple_success_values_` | Functions with multiple S_ codes | ~10 |

**Challenges:**
- Parameter-level annotations require locating the specific parameter in the
  declaration, not just the function name
- The patch tool needs parameter-aware parsing (not just function-level regex)
- Some of these apply to COM interface methods in IDL-generated headers

### Phase 4: Handle/Type Annotations

**Goal:** Move `autoTypes.json` RAII metadata into handle typedefs.

This covers handle types like:
```c
// Before (in autoTypes.json):
// { "Name": "HMODULE", "CloseApi": "FreeLibrary", "InvalidHandleValues": [0] }

// After (in header):
_Close_handle_with_(FreeLibrary)
_Invalid_handle_(0)
DECLARE_HANDLE(HMODULE);
```

**Complexity:** The `DECLARE_HANDLE` macro is a single-line macro, so annotations
must go before it. The patch tool needs to handle this pattern.

### Phase 5: Enum Reform (Long-term)

**Goal:** Replace `#define` constant groups with proper C `enum` types.

This is the hardest phase because it requires actual structural changes to headers:

```c
// Before (current SDK):
#define FILE_ATTRIBUTE_READONLY   0x00000001
#define FILE_ATTRIBUTE_HIDDEN     0x00000002
#define FILE_ATTRIBUTE_SYSTEM     0x00000004

// After (desired):
typedef enum FILE_ATTRIBUTE_FLAGS {
    FILE_ATTRIBUTE_READONLY = 0x00000001,
    FILE_ATTRIBUTE_HIDDEN   = 0x00000002,
    FILE_ATTRIBUTE_SYSTEM   = 0x00000004,
} FILE_ATTRIBUTE_FLAGS;
// Backwards compat #defines still present:
#define FILE_ATTRIBUTE_READONLY   FILE_ATTRIBUTE_FLAGS_FILE_ATTRIBUTE_READONLY
```

**Challenges:**
- ~500 enum definitions to convert
- Backwards compatibility — existing code uses `#define` values directly
- Some constants are used as both enum values and bitfield flags
- Requires Windows SDK team buy-in for header changes
- `enums.json` auto-populate feature (regex matching `#define` patterns) has no
  header equivalent — the enum members must be explicitly listed

**Interim approach:** Keep `enums.json` but add a header annotation for enum *usage*:

```c
// Annotate parameters that should use enum types:
// (This is conceptually what enums.json "uses" already express)
BOOL SetFileAttributesA(
    _In_ LPCSTR lpFileName,
    _W32M_anno1("enumtype", "FILE_ATTRIBUTE_FLAGS") DWORD dwFileAttributes
);
```

This can be expressed with a macro:
```c
#define _Enum_type_(name) _W32M_anno1("enumtype", #name)
```

---

## Risks and Mitigations

### Risk 1: ClangSharp doesn't preserve custom `__attribute__((annotate(...)))` data

**Status: RESOLVED** — ClangSharp v17 (currently pinned) only preserves annotate
attributes on parameters. However, ClangSharp v18+ (PR [#552](https://github.com/dotnet/ClangSharp/pull/552))
added `[NativeAnnotation("...")]` support that preserves annotate attributes on
**all declaration types**: functions, parameters, struct fields, and return values.
We validated this by testing v18.1.0.4 against our full test suite — every proposed
annotation type works. **Upgrading to v18+ is a prerequisite for this workstream.**

### Risk 2: Annotation placement varies across header styles

**Likelihood:** Medium — Windows SDK headers are not uniformly formatted. Function
declarations span multiple lines, use macros like `WINAPI`, and have inconsistent
whitespace.

**Mitigation:** The patch tool should use Clang's own parser (via libclang or a C
parser library) to find declaration locations rather than regex. Alternatively, use
ClangSharp itself to identify declaration locations and generate patch coordinates.

### Risk 3: Parameter-level annotations are hard to place in macroized declarations

**Likelihood:** Medium — some SDK declarations use macros that expand to full function
signatures, making it impossible to annotate individual parameters.

**Mitigation:** For these cases, keep the sidecar remap. Not every annotation needs
to move to headers — the goal is to move *as much as practical*, not necessarily 100%.

### Risk 4: Windows SDK team may adopt different annotation syntax

**Likelihood:** Medium — when the SDK team eventually adds metadata annotations to
official headers, they may choose different macro names or syntax.

**Mitigation:** Our macro names are prefixed with `_W32M_` to avoid collisions. The
public-facing macros (`_Sets_last_error_`, etc.) can be renamed or aliased when the
SDK team standardizes. The patch system's staleness detection handles the transition.

### Risk 5: Enum reform breaks backwards compatibility

**Likelihood:** High — changing `#define` to `enum` can break C code that uses the
constants in ways incompatible with enum types (e.g., bitwise OR of different enum types).

**Mitigation:** Phase 5 is explicitly long-term and requires SDK team coordination.
The interim approach (annotating parameters with `_Enum_type_`) gets most of the
metadata value without touching the constant definitions.

---

## What Stays in Sidecar Files (permanently)

Some metadata is inherently a win32metadata tooling concern:

| File | Why It Stays |
|---|---|
| `Partitions/` | Namespace organization is our invention, not an SDK concept |
| `requiredNamespacesForNames.rsp` | Disambiguation for our namespace mapping |
| `documentationMappings.rsp` | URLs are external data, not header properties |
| `libMappings.rsp` (auto) | Generated from .lib scanning — would be redundant in headers |
| `emitter.settings.rsp` (typeImport) | WinRT interop configuration |
| `manual/` (some files) | Hand-written types for APIs that genuinely can't be scraped |
| `scraper.settings.rsp` (config) | ClangSharp behavior flags |

---

## Measuring Progress

For each sidecar file, track:

```
Total entries in sidecar file:       N
Entries moved to header annotations: M  (patches applied)
Entries adopted by official SDK:     A  (patches no longer needed)
Entries remaining in sidecar:        N - M - A
Coverage:                            (M + A) / N × 100%
```

Target: 80%+ coverage for Category A metadata within the first two phases.

---

## Validation Results (March 2026)

We rigorously tested every proposed annotation through ClangSharp v17.0.1 and v18.1.0.4.
**Full details in `annotation-validation-results.md`.** Test files in `obj/annotation-validation/`.

### ClangSharp v17.0.1 (currently pinned): Parameter-Only Support

`__attribute__((annotate("w32m:...")))` on **function parameters** is preserved as
`[CppAttributeList("w32m:...")]`. All other placements (functions, return values,
struct fields, typedefs) are silently dropped with "Unsupported attribute: 'Annotate'".

### ClangSharp v18.1.0.4+: Full Support ✅

PR [#552](https://github.com/dotnet/ClangSharp/pull/552) added `[NativeAnnotation("...")]`
attribute emission for `__attribute__((annotate(...)))` on **all declaration types**.
We validated every proposed annotation:

| Annotation | Placement | v17 | v18 |
|---|---|---|---|
| `_Sets_last_error_` | function | ❌ | ✅ `[NativeAnnotation("w32m:setlasterror")]` |
| `_Min_os_version_(ver)` | function | ❌ | ✅ `[NativeAnnotation("w32m:minversion=...")]` |
| `_Must_close_with_(func)` | function/return | ❌ | ✅ `[NativeAnnotation("w32m:raiifree=...")]` |
| `_Can_return_errors_as_success_` | function | ❌ | ✅ `[NativeAnnotation("w32m:errorsassuccess")]` |
| `_Multiple_success_values_` | function | ❌ | ✅ `[NativeAnnotation("w32m:multiplesuccess")]` |
| Multiple annotations on function | function | ❌ | ✅ Each as separate `[NativeAnnotation]` |
| Return value annotations | return | ❌ | ✅ Appears on method |
| `_Enum_type_(name)` on struct field | field | ❌ | ✅ `[NativeAnnotation("w32m:enumtype=...")]` |
| `_Not_null_terminated_` on struct field | field | ❌ | ✅ `[NativeAnnotation("w32m:notnullterm")]` |
| All parameter annotations | param | ✅ | ✅ Both `CppAttributeList` AND `NativeAnnotation` |
| SAL + custom coexistence | param | ✅ | ✅ Both present without interference |
| `__declspec` on function | function | ❌ | ❌ Still dropped (not needed) |

**Conclusion:** Upgrading ClangSharp to v18+ eliminates all workarounds. No extraction
tools, no carrier-parameter hacks — `__attribute__((annotate(...)))` flows through the
AST into `[NativeAnnotation("...")]` on the correct declaration in the generated C#.
The emitter (`MetadataSyntaxTreeCleaner`) needs to be updated to process
`NativeAnnotation` attributes in addition to `CppAttributeList`.

**Typedef annotations** are a special case: `__attribute__((annotate(...)))` on a
typedef is preserved on the function parameters that use that typedef, but the typedef
itself is typically flattened by ClangSharp. Handle types from `autoTypes.json` are
generated structurally and will continue to need their JSON definition for the
`DECLARE_HANDLE` pattern, but RAII/close metadata can move to annotations.

---

## Open Questions for Review

1. **ClangSharp upgrade**: v17→v18 is a major version bump. Are there breaking
   changes that affect our existing pipeline? Need a compatibility assessment.

2. **`NativeAnnotation` vs `CppAttributeList`**: v18 emits BOTH for parameters.
   Should `MetadataSyntaxTreeCleaner` process `NativeAnnotation` only (cleaner),
   or continue to support both for backwards compat?

3. **Enum reform strategy**: Annotate parameters with enum types (interim) vs.
   actually create enum definitions (requires SDK changes)?

4. **Macro naming convention**: SAL-style `_Sets_last_error_` vs.
   `WIN32META_SETS_LAST_ERROR`?

5. **Typedef/handle type metadata**: Keep in `autoTypes.json` (structural definition)
   but move RAII annotations to headers? Or find a way to express the full typedef
   definition as an annotation?

# Remaining `functionPointerFixups.json` Entries

## Goal

Eliminate `functionPointerFixups.json` entirely. All function pointer fixup information should come from the headers — either inferred by simple regular rules in the auto-discovery heuristic, or expressed as `__attribute__((annotate("w32m:...")))` annotations in the headers themselves. See `annotation-validation-results.md` for the annotation validation framework and ClangSharp v18+ requirements.

## Background

The `functionPointerFixups.json` file provides manual configuration for function pointer types that ClangSharp's PInvokeGenerator doesn't handle well on its own. Without these fixups, the winmd would contain duplicate delegate types and `Delegate*` (pointer-to-delegate) parameters instead of clean delegate parameters.

Each entry generates up to three directives:
- `--remap NAME=POINTER_TYPE` — unifies the two typedef names
- `--exclude POINTER_TYPE` — prevents generating a duplicate delegate
- `--reducePointerLevel POINTER_TYPE` — strips an extra `*` so the winmd parameter is the delegate type directly, not a pointer to it

The auto-discovery heuristic in `RemapDiscovery.cs` handles two common patterns:
```c
// Pattern 1: bare function + pointer alias (fully auto-discovered)
typedef void CALLBACK(int x);      // bare function type
typedef CALLBACK *LPCALLBACK;      // pointer alias (adds *)

// Pattern 2: already-pointer + pointer-adding alias (fully auto-discovered)
typedef DWORD (*PFOO)(...);        // already a pointer
typedef PFOO *LPPFOO;              // adds another *
```

As of this writing, the file has been reduced from 184 entries to 27. The remaining 27 fall into three categories described below, with a plan for each.

---

## Category 1: No pointer alias — struct field callbacks (12 entries)

These are bare function typedefs (or function declarations) used as `NAME *member` in struct fields, but there is no `typedef NAME *PNAME;` anywhere.

### LDAP referral callbacks (3 entries)
```json
{ "name": "QUERYFORCONNECTION" }
{ "name": "NOTIFYOFNEWCONNECTION" }
{ "name": "DEREFERENCECONNECTION" }
```
**Header:** `Winldap.h` lines 3163–3221:
```c
typedef ULONG (_cdecl QUERYFORCONNECTION)(PLDAP, PLDAP, PWCHAR, ...);
// used in struct:
typedef struct LdapReferralCallback {
    QUERYFORCONNECTION *QueryForConnection;  // pointer applied at usage site
} LDAP_REFERRAL_CALLBACK;
```

### ICU iterator function pointers (9 entries)
```json
{ "name": "UCharIteratorGetIndex" }
{ "name": "UCharIteratorMove" }
// ... through UCharIteratorSetState
```
**Header:** `icucommon.h` lines 6448–6743. Function declarations used as function pointer types in struct fields: `UCharIteratorGetIndex *getIndex;`.

### Plan

**Option A (heuristic):** Add a new heuristic pass in `RemapDiscovery` that scans `RecordDecl` (struct) fields for `PointerType → FunctionProtoType` or `PointerType → TypedefType` where the pointee is a known bare function typedef. Emit `--reducePointerLevel` automatically. The rule is simple and regular: "any struct field that is a pointer to a bare function type gets `reducePointerLevel`."

**Option B (annotation fallback):** If the heuristic misfires on edge cases, add a `_Reduce_pointer_level_` annotation on the struct field:
```c
typedef struct LdapReferralCallback {
    _Reduce_pointer_level_ QUERYFORCONNECTION *QueryForConnection;
} LDAP_REFERRAL_CALLBACK;
```
This annotation expands to `__attribute__((annotate("w32m:reduceptrlevel")))` and tells the emitter to strip one `*` on this field.

**Recommendation:** Try Option A first — the rule is simple. Fall back to Option B only for entries where the heuristic produces incorrect results.

---

## Category 2: Same-level function pointer aliases (10 entries)

These are already-pointer typedefs (`typedef DWORD (*PFOO)(...)`) with a same-level alias (`typedef PFOO LPFOO`). Both names refer to the identical type. The fixup unifies them under one canonical name.

### Entries with `alreadyPointer: true` (6 entries)
```json
{ "name": "PTHREAD_START_ROUTINE",    "pointerType": "LPTHREAD_START_ROUTINE",    "alreadyPointer": true }
{ "name": "INTERNET_STATUS_CALLBACK", "pointerType": "LPINTERNET_STATUS_CALLBACK", "alreadyPointer": true }
{ "name": "OLDFONTENUMPROCA",         "pointerType": "FONTENUMPROCA",              "alreadyPointer": true }
{ "name": "OLDFONTENUMPROCW",         "pointerType": "FONTENUMPROCW",              "alreadyPointer": true }
{ "name": "_EVENT_CALLBACK",          "pointerType": "RTM_EVENT_CALLBACK",         "alreadyPointer": true }
{ "name": "_ENTITY_METHOD",           "pointerType": "RTM_ENTITY_EXPORT_METHOD",   "alreadyPointer": true }
```

### Entries without `alreadyPointer` flag (4 entries)
```json
{ "name": "PBMCALLBACKFN",              "pointerType": "LPBMCALLBACKFN" }
{ "name": "PTOP_LEVEL_EXCEPTION_FILTER", "pointerType": "LPTOP_LEVEL_EXCEPTION_FILTER" }
{ "name": "LPFNADDPROPSHEETPAGE",        "pointerType": "LPFNSVADDPROPSHEETPAGE" }
{ "name": "PFIBER_START_ROUTINE",        "pointerType": "LPFIBER_START_ROUTINE" }
```

These behave identically to the `alreadyPointer` group — the alias is at the same pointer level. The missing flag is likely an oversight in the original JSON.

### Plan

**Step 1 — try a simple heuristic.** For same-level function pointer aliases, always remap base→alias (the alias name becomes canonical). The rationale: you don't create a typedef alias unless you want the alias used publicly. Generate `--remap` and `--exclude` but NOT `--reducePointerLevel`.

Implementation:
1. In `ResolveFunctionPointerFixups`, add a pass that iterates `FnPointerFunctionTypedefs`, checks `FnSameLevelAliases` for exactly 1 alias, and generates remap + exclude
2. Remove these 10 entries from `functionPointerFixups.json`
3. Rebuild and run all tests — verify identical winmd output
4. If the 4 non-`alreadyPointer` entries need `reducePointerLevel` to pass, investigate why

**Step 2 — annotation fallback.** If the "alias is canonical" rule produces wrong results for specific entries (e.g., the winmd test shows the wrong name chosen), add a `_Canonical_name_(ALIAS)` annotation on the original typedef:
```c
_Canonical_name_(LPTHREAD_START_ROUTINE)
typedef DWORD (WINAPI *PTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
```
This annotation expands to `__attribute__((annotate("w32m:canonical=LPTHREAD_START_ROUTINE")))` and tells the toolchain which name should appear in the winmd.

**Recommendation:** The heuristic should work for all 10 entries — try it first. Only add annotations for entries where the rule produces incorrect results.

---

## Category 3: Header inclusion gaps (4 entries)

These follow patterns the heuristic already handles, but the headers declaring them aren't transitively included by the partition that scrapes them.

```json
{ "name": "LSA_GET_EXTENDED_CALL_FLAGS",                   "pointerType": "PLSA_GET_EXTENDED_CALL_FLAGS" }
{ "name": "_WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER",   "pointerType": "WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER" }
{ "name": "_WHEA_ERROR_SOURCE_UNINITIALIZE_DEVICE_DRIVER", "pointerType": "WHEA_ERROR_SOURCE_UNINITIALIZE_DEVICE_DRIVER" }
{ "name": "_WHEA_ERROR_SOURCE_CORRECT_DEVICE_DRIVER",      "pointerType": "WHEA_ERROR_SOURCE_CORRECT_DEVICE_DRIVER" }
```

**Header details:**
- `LSA_GET_EXTENDED_CALL_FLAGS`: `NTSecPKG.h` (bare function + pointer alias). The ActiveDirectory partition includes `<ntsecapi.h>` but that doesn't transitively include `ntsecpkg.h`.
- `_WHEA_ERROR_SOURCE_*`: `wheadef.h` (bare function + pointer alias). Verify whether `wheadef.h` is transitively included by the Base partition.

### Plan

1. Search the scraper's `.remaps` sidecar files for these names to confirm they're not being discovered
2. Add `#include <ntsecpkg.h>` and/or `#include <wheadef.h>` to the relevant partition `main.cpp` files
3. Rebuild and verify the entries appear in `emitter.autoFnPtr.crossarch.generated.rsp`
4. Remove from `functionPointerFixups.json`
5. Run all tests

**Complexity:** Low — same approach as the 7 partition header adjustments already on this branch.

---

## Summary and Priority

| Category | Entries | Approach | Complexity |
|----------|---------|----------|------------|
| Header inclusion gaps | 4 | Add `#include` to partitions | Low — do first |
| Same-level aliases | 10 | Heuristic (alias=canonical), annotation fallback | Medium |
| Struct field callbacks | 12 | Heuristic (scan struct fields), annotation fallback | Medium-high |
| **Total** | **27** | | |

### Suggested order of work
1. **Header inclusion gaps** (4 entries) — lowest risk, immediate payoff
2. **Same-level aliases** (10 entries) — try the "alias is canonical" heuristic
3. **Struct field callbacks** (12 entries) — add struct field scanning or `_Reduce_pointer_level_` annotations

### Annotation macros to define (if needed)

Add to a shared header (e.g., `win32metadata.h`) guarded by `#ifdef _WIN32METADATA_`:

```c
#ifdef _WIN32METADATA_
  // Tells the emitter to reduce pointer level on this struct field
  #define _Reduce_pointer_level_ __attribute__((annotate("w32m:reduceptrlevel")))

  // Tells the toolchain which typedef name is canonical for this function pointer
  #define _Canonical_name_(name) __attribute__((annotate("w32m:canonical=" #name)))
#else
  #define _Reduce_pointer_level_
  #define _Canonical_name_(name)
#endif
```

These annotations require ClangSharp v18+ for full support (see `annotation-validation-results.md`).

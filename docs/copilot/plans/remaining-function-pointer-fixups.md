# Remaining `functionPointerFixups.json` Entries

## Background

The `functionPointerFixups.json` file provides manual configuration for function pointer types that ClangSharp's PInvokeGenerator doesn't handle well on its own. Without these fixups, the winmd would contain duplicate delegate types and `Delegate*` (pointer-to-delegate) parameters instead of clean delegate parameters.

Each entry generates up to three directives:
- `--remap NAME=POINTER_TYPE` — unifies the two typedef names
- `--exclude POINTER_TYPE` — prevents generating a duplicate delegate
- `--reducePointerLevel POINTER_TYPE` — strips an extra `*` so the winmd parameter is the delegate type directly, not a pointer to it

The auto-discovery heuristic in `RemapDiscovery.cs` handles the common case:
```c
typedef void CALLBACK(int x);      // bare function type → FnBareFunctionTypedefs
typedef CALLBACK *LPCALLBACK;      // pointer alias     → FnProtoToPointerTypedefs
```
And also handles already-pointer types with pointer-adding aliases:
```c
typedef DWORD (*PFOO)(...);        // already pointer   → FnPointerFunctionTypedefs
typedef PFOO *LPPFOO;              // adds another *    → FnProtoToPointerTypedefs
```

As of this writing, the file has been reduced from 184 entries to 27. The remaining 27 fall into five categories described below.

---

## Category 1: No pointer alias exists (12 entries)

These are bare function typedefs (or function declarations) used as `NAME *member` in struct fields, but there is no `typedef NAME *PNAME;` declaration anywhere. They only need `--reducePointerLevel` on the bare name.

### LDAP referral callbacks (3 entries)
```json
{ "name": "QUERYFORCONNECTION" }
{ "name": "NOTIFYOFNEWCONNECTION" }
{ "name": "DEREFERENCECONNECTION" }
```
**Header:** `Winldap.h` lines 3163–3221. These are bare function typedefs:
```c
typedef ULONG (_cdecl QUERYFORCONNECTION)(PLDAP, PLDAP, PWCHAR, ...);
```
Used in `struct LdapReferralCallback` as `QUERYFORCONNECTION *QueryForConnection;`.

### ICU iterator function pointers (9 entries)
```json
{ "name": "UCharIteratorGetIndex" }
{ "name": "UCharIteratorMove" }
// ... through UCharIteratorSetState
```
**Header:** `icucommon.h` lines 6448–6743. These are function *declarations* (not typedefs) used as function pointer types in struct fields: `UCharIteratorGetIndex *getIndex;`.

### How to auto-discover these
This requires a new heuristic pass: scan `RecordDecl` (struct/union) fields in the AST for fields typed as `PointerType → FunctionProtoType` or `PointerType → TypedefType` where the pointee is a bare function typedef. For each such field, emit `--reducePointerLevel` on the type name.

**Complexity:** Medium-high. Requires walking struct fields in addition to typedefs. The `UCharIterator*` entries are function declarations, not typedefs, so the walker would also need to handle `FunctionDecl` nodes used as field types.

**Risk:** Low — these entries only need `reducePointerLevel`, no remap or exclude.

---

## Category 2: `alreadyPointer: true` — same-level aliases (6 entries)

These are already-pointer typedefs (`typedef DWORD (*PFOO)(...)`) with a same-level alias (`typedef PFOO LPFOO`). The fixup generates `--remap` and `--exclude` but NOT `--reducePointerLevel`. The alias doesn't add a pointer level; it just renames the type.

```json
{ "name": "PTHREAD_START_ROUTINE",    "pointerType": "LPTHREAD_START_ROUTINE",    "alreadyPointer": true }
{ "name": "INTERNET_STATUS_CALLBACK", "pointerType": "LPINTERNET_STATUS_CALLBACK", "alreadyPointer": true }
{ "name": "OLDFONTENUMPROCA",         "pointerType": "FONTENUMPROCA",              "alreadyPointer": true }
{ "name": "OLDFONTENUMPROCW",         "pointerType": "FONTENUMPROCW",              "alreadyPointer": true }
{ "name": "_EVENT_CALLBACK",          "pointerType": "RTM_EVENT_CALLBACK",         "alreadyPointer": true }
{ "name": "_ENTITY_METHOD",           "pointerType": "RTM_ENTITY_EXPORT_METHOD",   "alreadyPointer": true }
```

**Header examples:**
- `minwinbase.h`: `typedef DWORD (WINAPI *PTHREAD_START_ROUTINE)(...); typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;`
- `wingdi.h`: `typedef int (CALLBACK *OLDFONTENUMPROCA)(...); typedef OLDFONTENUMPROCA FONTENUMPROCA;`
- `RtmV2.h`: `typedef ... (*_EVENT_CALLBACK)(...); typedef _EVENT_CALLBACK RTM_EVENT_CALLBACK, *PRTM_EVENT_CALLBACK;`

### Why auto-discovery can't handle these yet
The AST tells us these are same-level aliases (tracked in `FnSameLevelAliases`), but it does NOT tell us which name should be canonical. The direction of the remap varies:
- `PTHREAD_START_ROUTINE → LPTHREAD_START_ROUTINE` (P→LP)
- `OLDFONTENUMPROCA → FONTENUMPROCA` (drops OLD prefix)
- `_EVENT_CALLBACK → RTM_EVENT_CALLBACK` (different naming entirely)

There is no consistent naming rule that picks the correct direction.

### How to auto-discover these
Two possible approaches:

**Approach A: Convention-based heuristics.** For each already-pointer typedef with a same-level alias, apply rules:
- If the base starts with `_` and the alias strips it → prefer alias (canonical Win32 pattern)
- If the base starts with `OLD` and the alias doesn't → prefer alias
- If one has `LP` prefix and the other has `P` → prefer `LP` (Win32 convention)

This covers most cases but is fragile and could misfire on future SDK additions.

**Approach B: Winmd diff validation.** Auto-generate fixups for all same-level aliases in both directions, try both, and compare the winmd output against the known-good baseline. This is more of a one-time migration tool than a sustainable heuristic.

**Recommendation:** Leave manual. These 6 entries are stable (they don't change with SDK updates) and the cost of maintaining them is near zero.

---

## Category 3: Same-level aliases without `alreadyPointer` (4 entries)

These behave identically to Category 2 but are missing the `alreadyPointer` flag. The base is already a pointer typedef, and the alias is at the same level.

```json
{ "name": "PBMCALLBACKFN",              "pointerType": "LPBMCALLBACKFN" }
{ "name": "PTOP_LEVEL_EXCEPTION_FILTER", "pointerType": "LPTOP_LEVEL_EXCEPTION_FILTER" }
{ "name": "LPFNADDPROPSHEETPAGE",        "pointerType": "LPFNSVADDPROPSHEETPAGE" }
{ "name": "PFIBER_START_ROUTINE",        "pointerType": "LPFIBER_START_ROUTINE" }
```

**Header examples:**
- `Icm.h`: `typedef BOOL (WINAPI *PBMCALLBACKFN)(...); typedef PBMCALLBACKFN LPBMCALLBACKFN;`
- `errhandlingapi.h`: `typedef LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(...); typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;`
- `ShObjIdl_core.h`: `typedef LPFNADDPROPSHEETPAGE LPFNSVADDPROPSHEETPAGE;` (cross-header alias)

### Notes
These are NOT marked `alreadyPointer: true` in the JSON even though the base IS already a pointer. This means `PrepSettingsForFunctionPointerFixups` generates `--reducePointerLevel` for them even though the alias doesn't add a pointer level. This works in practice because PInvokeGenerator and the emitter handle this consistently, but it's technically incorrect — these should probably have `alreadyPointer: true`.

`LPFNADDPROPSHEETPAGE → LPFNSVADDPROPSHEETPAGE` is a special case: the alias is in a completely different header (`ShObjIdl_core.h` vs `prsht.h`). The auto-discovery would need cross-header alias tracking to find it.

**Recommendation:** Same as Category 2 — leave manual.

---

## Category 4: Header inclusion gaps (4 entries)

These follow patterns the heuristic already handles (bare function + pointer alias, or already-pointer + pointer alias), but the headers declaring them are not transitively included by the partition that scrapes them.

```json
{ "name": "LSA_GET_EXTENDED_CALL_FLAGS",                  "pointerType": "PLSA_GET_EXTENDED_CALL_FLAGS" }
{ "name": "_WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER",  "pointerType": "WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER" }
{ "name": "_WHEA_ERROR_SOURCE_UNINITIALIZE_DEVICE_DRIVER", "pointerType": "WHEA_ERROR_SOURCE_UNINITIALIZE_DEVICE_DRIVER" }
{ "name": "_WHEA_ERROR_SOURCE_CORRECT_DEVICE_DRIVER",     "pointerType": "WHEA_ERROR_SOURCE_CORRECT_DEVICE_DRIVER" }
```

**Header details:**
- `LSA_GET_EXTENDED_CALL_FLAGS`: declared in `NTSecPKG.h` (bare function + pointer alias). This header is separate from `ntsecapi.h` — it's the *package* header, not the *API* header. The ActiveDirectory partition includes `<ntsecapi.h>` but that may not transitively include `ntsecpkg.h`.
- `_WHEA_ERROR_SOURCE_*`: declared in `wheadef.h` (bare function + pointer alias). The Base partition includes `<winnt.h>` and `<winbase.h>` — verify whether `wheadef.h` is transitively included.

### How to fix
1. Check whether these headers are actually transitively included by any partition (search the scraper's `.remaps` sidecar files for these names)
2. If not, add `#include <ntsecpkg.h>` or `#include <wheadef.h>` to the relevant partition's `main.cpp`
3. Verify the entries appear in the auto-generated rsp
4. Remove from `functionPointerFixups.json`

**Complexity:** Low. Same approach as the 7 partition header adjustments already on this branch.

**Risk:** Low — adding includes is additive. But verify no new types or namespace conflicts are introduced.

---

## Summary

| Category | Entries | Auto-discoverable? | Recommendation |
|----------|---------|---------------------|----------------|
| No pointer alias (struct field callbacks) | 12 | Possible with struct field scanning | Leave manual (stable, low count) |
| `alreadyPointer` same-level aliases | 6 | Not reliably (direction ambiguous) | Leave manual |
| Same-level aliases (no `alreadyPointer`) | 4 | Not reliably (same reason) | Leave manual |
| Header inclusion gaps | 4 | Yes, after adding `#include` | Fix partition headers |
| **Total** | **27** | | |

### Suggested next step
Fix Category 4 (header inclusion gaps) — it's 4 entries, low risk, and follows the same pattern as existing partition header adjustments on this branch. The remaining 22 entries are stable and unlikely to change with SDK updates.

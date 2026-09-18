# powrprof.h: source-backed annotation proof

## Scope and outcome

This proof covers **powrprof.h itself**, not the Power partition or a full-SDK
migration. The consolidated patch preserves native declarations and ABI. Its only
SAL correction is the documented output direction of
`ReadGlobalPwrPolicy.pGlobalPowerPolicy`. The original Powerbase patch and proof
at `ffe84411791e0a8f03910fc9b60a2533dbe7fe5e` remain unchanged.

**The frozen-source final run passed all implementation gates.** It found no
missing direct symbols or unresolved metadata contracts. Passing those gates is
distinct from declaring every old/new metadata contract equivalent:
**23 method contracts compare equal, two are expected improvements only, and
48 retain explicit review-required representation differences.**

### Final verification

| Gate | Result |
| --- | --- |
| Native declarations, complete callback signatures, and dependency closure; C/C++/metadata across three architectures | **972 direct declaration checks passed** |
| Actual source annotations, callback SAL/counts, native constness; eight composed images | **2,848 passed, zero failures** |
| Direct macro value/storage/literal flags; eight images | **232 passed** |
| Original direct macro define/undef lines | **30 preserved byte-for-byte** |
| Shared enum components | **8 images passed complete root/value/storage/flags/no-helper checks** |
| Original x64/merged component identity before composition | **4 byte-identity guards passed** |
| Bounded comparer regressions, including real callback member alignment | **43 passed** |
| Generic native-improvement regressions | **126 passed** |
| Real immutable Powerbase method replay | **20 passed: 12 equal, eight expected improvements** |
| Actual enum definition/self-reference boundary cases | **7 passed** |
| Compiled negative headers | **4 rejected at the intended contract gates** |
| Final persistence | **341 artifact hashes, 46 implementation hashes, and 16 actual image hashes verified** |

The four negative headers remove a return association, change a byte-count
parameter index, change the WCHAR callback's byte count to an element count, and
widen native `ULONG` to `ULONGLONG`. All compile and produce decoded metadata
differences at their intended paths. The widening also fails the native ABI
checker. The prior Powerbase replay preserves all original type-wide
handle/ownership/sentinel differences; only the verified methods are reclassified.

The narrowed patch has two fewer enum associations than the earlier diagnostic
draft, accounting for eight fewer annotation checks across four candidate images
(2,848 here versus 2,856 in the owner's earlier replay).

### Contract comparison

These results agree across x64, x86, ARM64, and merged images.

| Method-contract result | Unannotated control | Corrected candidate |
| --- | ---: | ---: |
| Equal under the documented bounded rules | 2 | **23** |
| Differences entirely explained as expected improvements | 0 | **2** |
| Review-required residual differences | 71 | **48** |
| Methods containing any accepted improvement, including mixed outcomes | 0 | **11** |
| Unresolved candidate/reference contracts | 0 | **0** |

The two improved-only methods are `ReadGlobalPwrPolicy` and
`PowerReplaceDefaultPowerSchemes`. Nine additional methods have accepted
error-status enrichment while retaining GUID identity differences.

**The 48 review rows are not 48 annotation failures.** Forty-three contain only
`System.Guid` versus native `GUID` identity differences after accepted paths are
separated. The other five are `WritePwrScheme`, `PowerImportPowerScheme`, and
`DevicePowerSetDeviceState` (legacy `PWSTR` plus const annotation versus native
`PCWSTR` representation), and `PowerOpenUserPowerKey` /
`PowerOpenSystemPowerKey` (primitive UInt32 versus native `REGSAM` alias).
`PowerImportPowerScheme` also retains a GUID identity difference.

| All direct ledger rows | Count |
| --- | ---: |
| Equal | 117 |
| Expected improvement only | 38 |
| Review-required residual | 62 |
| Source-available addition absent from baseline | 13 |
| Missing direct symbols | **0** |

All 93 native members compare equal. The 38 improved source rows include both
tags and their typedefs for the ten availability-enriched types; they do not
represent 20 distinct runtime types. Sixteen primitive macros have fully
accepted native signedness corrections, one macro is equal, eleven retain
legacy grouping/placement differences, and `NEWSCHEME` is a source addition.
The remaining twelve source additions are ten native pointer aliases,
`PWRSCHEMESENUMPROC_V2`, and `DEVICE_NOTIFY_CALLBACK_ROUTINE`.

## Complete direct ownership

| Source-owned category | Count |
| --- | ---: |
| Functions | 73 |
| Record tags | 9 |
| Enum tags | 1 |
| Typedef declarators, including five callback aliases | 25 |
| Record fields | 64 |
| Native enum members | 29 |
| Public macros | 29 |
| **Direct declaration/member/macro ledger rows** | **230** |

Tags and their value typedefs are separate C declarations, not separate runtime
API types. All 93 record/enum members are individually compared. The complete
per-symbol ledger is `comparison\all-direct-symbols.json`; its readable table is
`comparison\REPORT.md`. Neither ledger substitutes a five-function sample for
the entire header.

The records are `GLOBAL_MACHINE_POWER_POLICY`, `GLOBAL_USER_POWER_POLICY`,
`GLOBAL_POWER_POLICY`, `MACHINE_POWER_POLICY`,
`MACHINE_PROCESSOR_POWER_POLICY`, `USER_POWER_POLICY`, `POWER_POLICY`,
`DEVICE_NOTIFY_SUBSCRIBE_PARAMETERS`, and `THERMAL_EVENT`.
The native enum is `POWER_DATA_ACCESSOR`.
The five callback aliases are `PWRSCHEMESENUMPROC`,
`PWRSCHEMESENUMPROC_V1`, `PWRSCHEMESENUMPROC_V2`,
`DEVICE_NOTIFY_CALLBACK_ROUTINE`, and `PDEVICE_NOTIFY_CALLBACK_ROUTINE`.
Callback methods are compared by unique name, including `Invoke`; an absent
delegate constructor remains a separate difference. Duplicate method names fail
explicitly rather than collapsing overloads.

`PowerGetActiveScheme` and `PowerReadACValue` belong to `powersetting.h` and are
not claimed as migrated here. Transitive types remain separate dependency rows.

## What the patch does

The single patch is
`generation\WinSDK\patches\post-midl\powrprof.h.win32metadata.patch`.
It adds the agreed annotation vocabulary, OS availability, documented
last-error behavior, error-status return associations, and the
`PowerSettingAccessCheckEx.AccessType` association on its unchanged native
`REGSAM`. It preserves original macros, parameter/return/field/typedef types,
pointer depth, native enum declarations, and layouts.

Representative **actual patch** excerpts:

```diff
+_Windows_SupportedOS_WindowsXP_
+_Win32_SetLastError_
 STDAPI_(BOOLEAN)
 ReadGlobalPwrPolicy(
-    _In_ PGLOBAL_POWER_POLICY pGlobalPowerPolicy
+    _Out_ PGLOBAL_POWER_POLICY pGlobalPowerPolicy
     );
```

```diff
+_Windows_SupportedOS_WindowsVista_
+_Win32_AssociatedEnum_(WIN32_ERROR)
 STDAPI_(DWORD)
 PowerReadFriendlyName(
```

```diff
-    _In_ REGSAM AccessType
+    _In_ _Win32_AssociatedEnum_(REG_SAM_FLAGS) REGSAM AccessType
```

The friendly-name buffer remains native `PUCHAR` with its original byte-count
SAL, not a substituted `WCHAR*`. The complete 692-line patch, not these excerpts,
is the implementation.

No `WIN32_ERROR` association is inferred for the bitmask-returning
`PowerReadSettingAttributes` or reversed-success `DevicePowerSetDeviceState`.
The latter retains its documented last-error behavior. No handles are invented
for `DevicePowerOpen`/`DevicePowerClose`, callback context pointers, or buffers.
No unconditional `LocalFree` ownership is attached to the conditionally
allocated/caller-supplied GUID storage of `PowerDuplicateScheme` or
`PowerImportPowerScheme`.

## Expected improvements versus equality

The generic classifier accepts native-backed handle identity only with retained,
hashed source/documentation evidence, native width/pointer-depth/convention
agreement, genuine handle designation, resolved definitions, and exact
producer-specific cleanup. It does not promote type-wide closers or invalid
sentinels into producer contracts. The earlier real Powerbase images are replayed
without altering their original report.

For this header the report separately recognizes:

- The documentation-backed `ReadGlobalPwrPolicy` In-to-Out correction.
- Added Windows error-status associations on unchanged native DWORD returns,
  with individually retained return-section evidence and complete real
  in-image `WIN32_ERROR` binding. `ERROR_SUCCESS` zero-success/nonzero-failure
  is recorded as a status-convention inference, not an exhaustive domain claim.
- Documented availability on the ten native record/enum definitions.
- Compiler-proven 32-bit signed macro storage where the old field was a
  primitive unsigned constant with the same nonnegative value.

All raw differences survive. Explained paths are counted separately; an
unrelated mutation remains review-required. Const encoding equivalence is
limited to a proven native single const-pointee pointer at the same level.
Dropping real const, moving it to another level, or fabricating it from SAL
does not qualify. Fixed-array normalization remains limited to the previously
approved rank-one, positive-size, omitted-versus-zero-bound case.
AttributeUsage compatibility is current-use-only, not schema-wide policy.

## Separate shared prerequisites

Foundation `WIN32_ERROR` is an explicit **source-generated pilot bridge**, not a
claim that its semantics were shifted into a shipped SDK-header patch. It has
3,378 members: 3,288 from `winerror.h` and 90 from `SetupAPI.h`, with 380
HRESULT-family exclusions determined from source/compiler evidence.

Registry `REG_SAM_FLAGS` is a second bounded dependency bridge containing the
13 selected-SDK `KEY_*` definitions from `winnt.h`. It is not a Registry API
migration. The only added Powrprof parameter use is
`PowerSettingAccessCheckEx.AccessType`.

Both bridge headers are generated in the evidence/OBJ directory from SDK
sources and compiler-evaluated values. Production generation reads neither
legacy JSON nor copied WinMD rows. Their dedicated TUs scrape into
`Windows.Win32.Foundation` and `Windows.Win32.System.Registry`; the Power TU
scrapes into `Windows.Win32.System.Power`. One compilation composes the three
generated RDL inputs and injects the metadata vocabulary once.

Each shared component exposes exactly its intended public enum, UInt32 storage,
storage-field flags 1542, literal flags 32854, and no helper API roots.
`REG_SAM_FLAGS` has `FlagsAttribute`; `WIN32_ERROR` does not.
Source macros are restored after push/pop and checked with the compiler.
Per-architecture members/values agree. Original x64 and merged component images
are byte-compared **before composition** before reusing merged RDL as x64.

## Retained limitations, not hidden failures

The report does **not** claim all 73 methods or all header metadata are identical
to the published baseline. Remaining differences include:

- Native `GUID` versus legacy `System.Guid` identity. Layout evidence is useful
  but is not a name-only equivalence rule or a third-party projection guarantee.
- String-wrapper/const representation and native `REGSAM` alias identity.
- Legacy enum grouping/placement for `DEVICE_NOTIFY_CALLBACK` and ten
  `PDCAP_*` constants, rather than their direct native macro representation.
- Delegate implementation/constructor details and callback representations.
- Source-available typedefs/callbacks and `NEWSCHEME` absent from the baseline.
- Shared/dependency type ownership, invalid-value, and representation differences.

The four `PowerGet/SetUserConfiguredAC/DCPowerMode` functions are retained from
the selected SDK. Their exact minimum client build is not invented from the
existing OS vocabulary. Conditional GUID allocation remains explicit rather
than being converted to unconditional cleanup. Official documentation marks
`PowerOpenUserPowerKey` and `PowerOpenSystemPowerKey` "Not implemented"; both
remain inventory rows, without speculative enum/ownership additions.
`DevicePowerEnumDevices` has a documented filter-on-name direction ambiguity;
its native SAL is retained.

Only the generic metadata reader/comparer is exercised. No native power API is
called and no third-party projection or whole-SDK compatibility is claimed.

## Reproducibility and immutable inputs

Final evidence directory:

```text
C:\Users\jevansa\.copilot\session-state\ac7b652c-c8c0-40c2-8251-946330986647\files\powrprof\final-f320e134-r3
```

`manifest.json` records command argument arrays, all SDK import libraries,
package archive identities, copied implementation inputs, generated input/output
hashes, component guards, macro checks, and end-of-run source consistency.
`comparison\REPORT.md` is the complete 230-row table;
`comparison\candidate-*-functions.json` and `candidate-*-types.json` retain exact
raw/effective differences and evidence-backed explained paths.
`contracts\*.json` contains actual decoded metadata, not RDL-only assertions.
The final manifest SHA-256 is
`1B151DD2D1AECE78629FAEF513EC4B4BE350CD4654F88677E20FB3850DFBA8FD`.

| Input | Immutable version / identity |
| --- | --- |
| Published reference | `Microsoft.Windows.SDK.Win32Metadata` **70.0.11-preview** |
| Reference WinMD SHA-256 | `6AEC29BE3359468D9EBA03C3AE932591B39960F1812B6D25D33C0D9F14A6D665` |
| Selected SDK CPP / CPP.x64 | **10.0.26100.7705** |
| Original SDK/repository `powrprof.h` SHA-256 | `2075A213F792A8206C510E26D94A81FF4E1A59F0168A3FD900822D14E863CEB1` |
| Native compiler | libclang **22.1.8**, LLVM `ca7933e47d3a3451d81e72ac174dcb5aa28b59d1` |
| Tooling #2303 source | `f320e1343f2458e947f699c3fe10ca28a97ca341` |
| windows-rs source | `e322c213f5a4b5fd1911a05bd9e1ee57ee32d9fc` |
| Owner-built executable SHA-256 | `0D8C17333ABCD7877CBA4A666F2331CEEE24A0D865E53FFF4EE4DAD525B816CA` |
| Patch SHA-256 | `2B96554B6556E0639896E4F0C7E27C12C324CE79ECC55E09669E08AD14B3B56F` |
| Patched header SHA-256 | `6C383A4EEF4EAB9A0597D6DE9570CCF882094017AB84450F1FE2536C2934EFF7` |
| Generated Foundation header SHA-256 | `30670E39104AF3CB9CDE6FF34931A33ECCC84E0F7EC4A652DC65FA8905DBE2A9` |
| Generated Registry header SHA-256 | `7A0BD8DFAE2A5D590C8C0F817006EED279A799E25217BEA6988ADB423624CA05` |

The owner-supplied executable is copied and hash-checked, not silently replaced
by an untracked local build. Its Cargo source/lock files are retained. Scrapes
use the complete selected SDK import-library directory, not only `PowrProf.lib`.
The selected consumer prefers dedicated DLL libraries over umbrella mappings.
The source/compilation commands are documented in `README.md` and recorded
verbatim in the manifest.

Each of the four architectures has the same image hash for this bounded input:

| Component | SHA-256 |
| --- | --- |
| Foundation-only | `011A7BD8C5C2F3D1992130C4AAA310EEB7C5C0625C570D80E9615B3F26096609` |
| Registry-only | `C35BCE4290E710D5009ECEBA254C6731CF33A6708FE0470945FDE32904F63B7A` |
| Composed control | `18055FD7B2D3E00C05E8829601014721DC92578E37EB355F3152AFA94089A7C9` |
| Composed candidate | `3C5AE8960A4BF165B8A793E59BB1ABE58739891803F54BD1ACF88F166F3AEF2E` |

The patch is **692 lines, 18,711 bytes, 140 additions and two deletions**.
Bulk generated output stays outside Git. Earlier failed/draft runs remain
separate evidence, never promoted to final success. The initial rejected final
run also exposed a PowerShell empty-array gate bug; its fix preserves the exact
zero-attributes Foundation and one-FlagsAttribute Registry requirements.

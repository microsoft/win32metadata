# powerbase.h migration proof

**All-five logical equivalence is NOT achieved.** Three method contracts match;
two retain explicit native/reference semantic disagreements. All five APIs are
generated from the candidate header. Both notification return associations now
resolve to the complete, same-image Foundation enum, not a baseline lookup.
This is the requested review endpoint, not a full-SDK or third-party projection
claim.

## Review and reproduce

Exact SDK-header patch:
`generation\WinSDK\patches\post-midl\powerbase.h.win32metadata.patch`.

```powershell
.\scripts\Test-PowerbasePilot.ps1 -EvidenceDirectory C:\evidence\powerbase
```

Use a fresh directory. The complete gate preserves evidence and returns **1**
for the remaining logical disagreements rather than disguising them as a pass.
The native and reference outputs are never rewritten to match each other.
Reader/comparer checkpoint: `4cfc5dbe78`; pilot checkpoint: `9f2e01d923`;
macro provenance: `e4e7872793`; corrected version group and representation rules:
`2bcc0353ad`. The shared prerequisite is a separate commit.

## Final execution results

The fresh guarded run completed. All generation, source-preservation and negative
controls passed; the final exit code is **1 only because logical equivalence is
false**. The manifest status is `verified evidence; unresolved logical differences`.

| Gate | Result |
| --- | --- |
| Original component x64/merged byte-identity guards | 3/3 passed before composition |
| Foundation-only images | 4/4 passed; exactly 3,378 enum members and no helper API roots |
| Composed control/candidate images | 8/8 passed; exactly five Power functions per image |
| Native declaration comparisons | 108/108 passed across C/C++/metadata, three architectures and both ownership contexts |
| Real source mutations | 4/4 rejected by the intended gates: native type, removed association, wrong byte-count index, bytes-to-elements |
| Bounded logical-comparator regressions | 29/29 passed |
| Candidate unresolved references | 0 on each architecture and merged |
| Effective differences per image | Control 40; candidate 19; all four architecture/merged results agree |

All 190 recorded verification-file hashes and all 16 verification-implementation
hashes were checked against the completed run. `logical-comparator-checks.json`
contains the separate regression results.

## Current five-function verdict

These outcomes apply to x64, x86, ARM64, and merged images. The effective
comparison has **19 structural difference records, zero unresolved references**;
these are not 19 independent API defects.

| Function | Verdict | Exact meaningful outcome |
| --- | --- | --- |
| `CallNtPowerInformation` | **Matches** | Original mutable buffers, In/Out/Optional, byte counts 2/4, named `NTSTATUS` shape, complete information-level enum, import/calling convention, OS contract |
| `GetPwrCapabilities` | **Matches** | Named `BOOLEAN` return and all affected fields, output direction, complete capability layout/arrays, import, last-error, OS contract |
| `PowerDeterminePlatformRoleEx` | **Matches** | Native `ULONG` plus actually resolved UInt32 V1/V2 enum is equivalent to old enum typing; complete return enum, In, import and OS contract |
| `PowerRegisterSuspendResumeNotification` | **Explicit disagreement** | Flags and complete return-error enum match. Candidate preserves `HPOWERNOTIFY*` output instead of old `void**` and places correct producer-specific cleanup on that output |
| `PowerUnregisterSuspendResumeNotification` | **Explicit disagreement** | Complete return-error enum matches. Native/candidate `_Inout_` is InOut; old metadata says In. Handle dependency differences remain |

Registration accounts for five structural records and unregistration one.
The other thirteen records concern shared `HANDLE`/`HPOWERNOTIFY` facts:
legacy type-wide cleanup/invalid values versus source-backed producer ownership,
and `HPOWERNOTIFY.Value` as old `IntPtr` versus native `void*`.

The native header and official registration documentation justify keeping
`PowerUnregisterSuspendResumeNotification` on the producing output, not the
legacy type-wide `UnregisterPowerSettingNotification`. `HANDLE Recipient` is
borrowed; the pilot does not invent producer semantics for it. No invalid
sentinels are copied without producer evidence. No native type or SAL direction
is changed to force equality. These remaining semantic-model differences require
explicit user review; no blanket handle normalization is applied.

## Other eleven inventory rows

The five functions above plus these eleven rows are the complete 16-row pilot
inventory, including the explicitly rejected synthetic promotion.

| Symbol | Outcome |
| --- | --- |
| `HPOWERNOTIFY` | Native alias preserved; emitted wrapper has the explicit storage/lifecycle differences above |
| `PHPOWERNOTIFY` | No standalone metadata definition in either image; native pointer alias unchanged |
| `POWER_PLATFORM_ROLE_VERSION` | Complete UInt32 V1/V2 definition, values and field flags match |
| `REGISTER_NOTIFICATION_FLAGS` | Complete four-member unsigned Flags contract matches under the recorded namespace mapping |
| `POWER_PLATFORM_ROLE_CURRENT_VERSION` | Absent in both. Newly proposed promotion removed; original SDK `POWER_PLATFORM_ROLE_VERSION` macro/value restored unchanged |
| `POWER_PLATFORM_ROLE_V1` | UInt32 value 1 and literal flags match |
| `POWER_PLATFORM_ROLE_V2` | UInt32 value 2 and literal flags match |
| `DEVICE_NOTIFY_SERVICE_HANDLE` | UInt32 value 1 and literal flags match |
| `DEVICE_NOTIFY_CALLBACK` | UInt32 value 2 and literal flags match |
| `DEVICE_NOTIFY_WINDOW_HANDLE` | UInt32 value 0 and literal flags match |
| `DEVICE_NOTIFY_ALL_INTERFACE_CLASSES` | UInt32 value 4 and literal flags match |

The ordinary `windows.h`-first TU obtains handle aliases from `winuser.h`; they
are dependencies, not newly Power-owned declarations. The alternate header-first
case is tested too. All fields/members of every dependency remain in the bulk
report. `BATTERY_REPORTING_SCALE`, `BOOLEAN`, `NTSTATUS`,
`POWER_INFORMATION_LEVEL`, `POWER_PLATFORM_ROLE`, `SYSTEM_POWER_CAPABILITIES`,
`SYSTEM_POWER_STATE`, both pilot groups, and `WIN32_ERROR` have matching
effective type contracts. `HANDLE` and `HPOWERNOTIFY` do not.

## Explicit shared prerequisite, not a second API pilot

`Generate-Win32ErrorHeader.ps1` creates an OBJ/evidence-local metadata-only C++
enum from the selected SDK. This is a **source-backed pilot prerequisite/bridge**,
not a claim that shared enum semantics have migrated into shipped SDK-header
patches. That broader authoring work remains separate.

Production generation consumes no legacy JSON or WinMD facts. Its source rule
selects `ERROR_`, `DNS_ERROR_`, `APPMODEL_ERROR_`, and `NO_ERROR` from `winerror.h`,
plus `ERROR_` constants from `setupapi.h`. Pinned Clang evaluates every name/type:
**3,378 included members = 3,288 winerror + 90 SetupAPI**. All 380 excluded raw
candidates are native `HRESULT` and use `_HRESULT_TYPEDEF_`, not missing Win32
errors. The one-time legacy inventory and published comparison independently
confirm no missing/extra members or value differences on all three architectures.

The generated header preserves every macro's native type and value through
push/undef/pop and pre/post assertions. With metadata disabled it declares
nothing. A dedicated TU includes `windows.h`, `setupapi.h`, then this header;
no SDK include guards or native declarations are edited. Foundation-scoped
scraping exposes exactly one API type, `Windows.Win32.Foundation.WIN32_ERROR`,
all 3,378 UInt32 literals, `value__` flags 1542 and literal flags 32854, and no
helper types/constants/functions.

The existing-owner `compile` command combines **generated** Foundation and Power
RDL into one image; it injects the 33 canonical vocabulary definitions once.
Every composed image has exactly the original five Power API roots, no duplicate
vocabulary, and both returns bind to the same in-image Foundation enum. The raw
Power-only images are retained. Before composition, original x64/merged component
bytes must match before merged RDL may stand in for x64 in this bounded invariant
pilot; architecture-dependent components fail rather than silently reuse it.
The shared enum is present in the composed control too, but is not reachable from
its unannotated method contracts; the control's root-reachable dependency snapshot
therefore omits it. The separate full-image snapshot retains it.

## Allowed representation mappings

Unique declaration identities may pair across namespaces only after checking
their contracts. Original namespaces remain in raw snapshots. Native integer
plus `AssociatedEnum` means a typed enum only with actual target resolution,
matching storage, and the complete names/values/flags contract.

The separate effective view excludes documentation, assembly identity, forensic
tokens/blobs, and `BeforeFieldInit`. On managed metadata attribute classes only,
`AutoClass` and positional constructor parameter labels do not change decoding.
Closed, positively sized rank-one arrays may encode an omitted or explicit zero
lower bound (ECMA-335 II.23.2.13); nonzero bounds, type, rank and size still fail
when changed. Native type flags and native parameter names are not erased.

AttributeUsage-only differences are accepted for **current uses only** after
checking both target masks, realized multiplicity, typed constructor/named
arguments, and irrelevant inheritance on sealed native structs/static PInvokes.
Four actual NativeTypedef placements and five SupportedOS placements pass.
General vocabulary target/inheritance/repetition policy is explicitly unproven
and remains recorded, not called schema-wide equivalence.

## Pins, hashes, and evidence

Published baseline: `Microsoft.Windows.SDK.Win32Metadata` `70.0.11-preview`.
SDK/import libraries: `10.0.26100.7705`, include version `10.0.26100.0`.
Compiler: libclang `22.1.8`, LLVM `ca7933e47d3a3451d81e72ac174dcb5aa28b59d1`.
Rust `1.96.0`; .NET SDK `10.0.401`.
Tooling prerequisite: `a7f78d926f5dfb8592ad32f8bc98c3cc6c1e6545`;
windows-rs: `97f7d9c7669999403a8670ad4a0388c063e815e6`.

| Artifact | SHA-256 |
| --- | --- |
| Published baseline | `6AEC29BE3359468D9EBA03C3AE932591B39960F1812B6D25D33C0D9F14A6D665` |
| Original `powerbase.h` | `66082F57FF576850899FA3DEB4779C0B762163A70946D0BE4DF78F3A2A506FB2` |
| Consolidated Power patch | `3508332F2650809797AF75F8BD72B468D78498670C33FF2D48192789575B79D6` |
| Patched Power header | `B5D60E97718C36A454DE9C1D04C2A06C5002D896CCF5366072CDEDB67DE0603D` |
| SDK `winerror.h` | `0284EA46280C14063BB714D08C9EC48DE18DE6A7F0384323B263FEC234428833` |
| SDK `setupapi.h` | `3C027FD246AA6828287B0AC2496806FEF70FB8CB05ED75FBCEB57EB0E9369EEB` |
| Exact composition tool | `7728A9FF4531D8E3151BC8E046FB0C1B9B7ED1285FAD2A8E7E85B885CA55A73A` |
| Generated shared header | `30670E39104AF3CB9CDE6FF34931A33ECCC84E0F7EC4A652DC65FA8905DBE2A9` |
| Foundation-only WinMD | `011A7BD8C5C2F3D1992130C4AAA310EEB7C5C0625C570D80E9615B3F26096609` |
| Composed control | `91C675ABFCA380544DA49DD4E45C6E63831B5A95B64C517601B983D9A3540A73` |
| Composed candidate | `64A5D1E797721771256B413364D7C9554C5DC7BAFA87D4ED6D38C8B4384A79A3` |

Artifact root:
`C:\Users\jevansa\.copilot\session-state\ac7b652c-c8c0-40c2-8251-946330986647\files\powerbase`

The final guarded run is `composed-a7f78d9-final`; the preceding completed run
is `composed-a7f78d9`. In each, `manifest.json` records exact commands, sources,
hashes, component roots, composition, and verification status.

| Path within the run | Evidence |
| --- | --- |
| `comparison\REPORT.md` and `comparison\symbols` | Complete 16-row before/control/candidate table and exact per-symbol facts |
| `comparison\DEPENDENCIES.md` | Every dependency field/enum member |
| `contracts` and `logical` | All architecture/merged raw snapshots; separate explicit effective verdict |
| `shared-prerequisite\manifest.json`, `members.json`, `excluded-hresult.json` | SDK source/evaluation origins, full included/excluded sets, compiler arguments, macro restoration |
| `shared-prerequisite\*-contract.json` | Complete Foundation-only metadata contracts and no-helper-root evidence |
| `control\*-composed-contract.json`, `candidate\*-composed-contract.json` | Full composed-image inventories, including the shared enum even when not root-reachable |
| `control\power-only`, `candidate\power-only` | Uncomposed source-generated images, never replaced by baseline facts |
| `native`, `negative-native`, `negative-metadata` | 108 native comparisons and four actual negative controls, with composed negative images |

All earlier failures are preserved separately: `25f9fe` suppressed roots;
`24d0e59` produced mismatched typedef namespaces; earlier successful Power-only
runs lacked the shared error definition. None is presented as a successful
final proof. No PR was created. Work remains on
`jevansaks-powerbase-equivalence-pilot`, not the original tooling/stack branches.

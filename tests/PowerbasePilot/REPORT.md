# powerbase.h proof status

**Logical equivalence is not established.** This report preserves the completed
single-header work and the concrete remaining blockers. No other pilot header,
full-SDK claim, or PR is included.

## Review entry points

Exact patch: `generation\WinSDK\patches\post-midl\powerbase.h.win32metadata.patch`.
One reproducible gate, using a fresh output directory:

```powershell
.\scripts\Test-PowerbasePilot.ps1 -EvidenceDirectory C:\evidence\powerbase
```

Checkpoints: `4cfc5dbe78` contains the reader/comparer and completed tests;
`9f2e01d923` contains the consolidated pilot implementation and initial report.
The command returns nonzero while substantive differences or provenance
failures remain. It does not manufacture a passing reference.

## Latest decoded comparison

The published reference is `Microsoft.Windows.SDK.Win32Metadata`
`70.0.11-preview`, not a regenerated control. The successful paired run used
tooling prerequisite `d178b4598bf7af5159488d10c197ceb5c629332e`, windows-rs
`97f7d9c7669999403a8670ad4a0388c063e815e6`, SDK `10.0.26100.7705`,
libclang `22.1.8`, Rust `1.96.0`, and .NET SDK `10.0.401`.
Both variants use canonical `Windows.Win32.System.Power`, derived from the
existing Power partition's namespace setting. The earlier flat `cb645326`
comparison is preserved separately and is not used as the reference.

| Artifact | SHA-256 |
| --- | --- |
| Published reference | `6AEC29BE3359468D9EBA03C3AE932591B39960F1812B6D25D33C0D9F14A6D665` |
| Unmodified SDK header | `66082F57FF576850899FA3DEB4779C0B762163A70946D0BE4DF78F3A2A506FB2` |
| Consolidated patch | `3508332F2650809797AF75F8BD72B468D78498670C33FF2D48192789575B79D6` |
| Patched header | `B5D60E97718C36A454DE9C1D04C2A06C5002D896CCF5366072CDEDB67DE0603D` |
| Rust control, each architecture and merged | `D4D7888996B21AB0F19E9EF0C21C921ED11EAA1054ED7E37E54F4286FACE35DF` |
| Rust candidate, each architecture and merged | `94CFD8D4B38148807CD0D43B4DA7AFCEF25B258EB2109B4A967420DBBE04261D` |
| Exact supplied consumer used for this comparison | `AEE37B35B79E92DFA97F315A7C3076D30914459CF10AFC348612131EA509AD2A` |

Control: 42 types including vocabulary, five functions, zero global constants.
Candidate: 44 types including vocabulary, five functions, zero global constants.
All eight WinMDs compile and contain the exact five required function names.
Vocabulary types are shared tooling prerequisites, not header-owned APIs.

| Function | Verified matching facts in candidate | Differences from the published reference |
| --- | --- | --- |
| `CallNtPowerInformation` | In/Out/Optional; mutable `void*`; byte-count indices 2/4; native widths; `NTSTATUS` wrapper shape; complete information-level enum contract; import/calling convention; XP OS payload | Verified `NTSTATUS` namespace mapping; shared vocabulary current-use policy assessment below |
| `GetPwrCapabilities` | `BOOLEAN` wrapper in return and all 23 affected fields; complete capability field shapes; output direction; import/calling convention; `SetLastError`; XP OS payload | Verified `BOOLEAN` namespace and fixed-array zero-bound mappings; shared vocabulary current-use policy assessment |
| `PowerDeterminePlatformRoleEx` | Complete return/version enum contracts; unchanged native `ULONG`; In; import/calling convention; Win8 OS payload; association resolves to unsigned V1/V2 group | Shared vocabulary current-use policy assessment; extra synthetic alias removed without changing the native macro |
| `PowerRegisterSuspendResumeNotification` | Native widths; In/Out; flags association resolves and complete four-member contract matches; import/calling convention; Win8 OS payload | `WIN32_ERROR` unresolved; output `HPOWERNOTIFY*` versus old `void**`; handle storage/ownership differ; vocabulary current-use policy assessment |
| `PowerUnregisterSuspendResumeNotification` | Native handle pointer ABI; import/calling convention; Win8 OS payload; return association transported | `WIN32_ERROR` unresolved; native InOut versus old In; handle storage/ownership and vocabulary schema differences |

The two return `WIN32_ERROR` associations are the only unresolved references in
the current rooted candidate. The old five unresolved vocabulary references now
resolve. A supported explicit shared-type dependency is being considered by the
tooling owner; no lookup into the comparison baseline supplies missing targets.

### Types and members: the other eleven inventory rows

| Symbol | Published reference -> candidate |
| --- | --- |
| `HPOWERNOTIFY` | Named native wrapper in both; `Value: IntPtr` -> `void*`; old type-wide closer and invalid values absent; correct producer-specific closer is on the registration output |
| `PHPOWERNOTIFY` | No standalone definition in either; original native pointer alias remains unchanged |
| `POWER_PLATFORM_ROLE_VERSION` | Unsigned `UInt32`, complete V1/V2 set, values and field flags match |
| `REGISTER_NOTIFICATION_FLAGS` | Complete four-member unsigned contract and Flags match under the explicit namespace mapping |
| `POWER_PLATFORM_ROLE_CURRENT_VERSION` | Absent in both; proposed promotion removed. Original SDK version macro and value remain unchanged |
| `POWER_PLATFORM_ROLE_V1` | `UInt32(1)` and literal field flags match |
| `POWER_PLATFORM_ROLE_V2` | `UInt32(2)` and literal field flags match |
| `DEVICE_NOTIFY_SERVICE_HANDLE` | `UInt32(1)` and literal flags match; explicit group namespace mapping |
| `DEVICE_NOTIFY_CALLBACK` | `UInt32(2)` and literal flags match; explicit group namespace mapping |
| `DEVICE_NOTIFY_WINDOW_HANDLE` | `UInt32(0)` and literal flags match; explicit group namespace mapping |
| `DEVICE_NOTIFY_ALL_INTERFACE_CLASSES` | `UInt32(4)` and literal flags match; explicit group namespace mapping |

### Exact residual schema differences

The encoder now emits the correct literal flags `32854` (including `HasDefault`)
and public `value__` flags `1542`; all constant rows remain decoded and compared.
`NativeTypedefAttribute` and `SupportedOSPlatformAttribute` still omit the
reference's `AttributeUsage`. This broadens allowed targets and remains a
general vocabulary-policy difference. Current-use equivalence requires separate
checks of actual placements, multiplicity, typed arguments, and lack of relevant
inheritance; it is not schema-wide compatibility.

The reviewed effective report has 28 difference records per architecture,
principally unresolved return enums and handle/direction/ownership differences.
Raw and earlier effective views remain preserved separately.

### Explicit representation policy

Unique declaration names may pair across namespaces only with compatible full
contracts; `BOOLEAN` and `NTSTATUS` wrapper shapes now match. A native integer
plus association may represent a legacy typed enum only when the target actually
resolves, storage matches, and the complete member/value/flags contract matches.
Both pilot-owned groups now pass those checks. Documentation,
assembly identities, forensic tokens/blobs, and `BeforeFieldInit` are excluded
from native behavior only in the separate effective view; raw evidence retains
them. No direction, count units, typedef identity, ownership, missing target,
extra member, or unapproved schema difference is erased. Only managed metadata
attribute classes disregard `AutoClass` and positional constructor parameter
labels; native types and native parameter names do not. Closed, positively sized
rank-one arrays may use omitted or explicit zero lower bounds; nonzero bounds,
element types, sizes and dimensions remain checked (ECMA-335 II.23.2.13).

## Source-correct differences are not waived

The original native types, pointer depths, calling conventions and layouts are
unchanged. `PowerUnregisterSuspendResumeNotification` has native `_Inout_` SAL,
unlike the published In-only row. The producer's documented closer is
`PowerUnregisterSuspendResumeNotification`, not the legacy type-wide
`UnregisterPowerSettingNotification`. The patch annotates only the producing
output and does not invent invalid-handle values or a replacement handle type.
These are explicit native/legacy contract disagreements, not normalization.

The complete inventory also covers both aliases, both synthetic groups, all
seven proposed members, and every dependency field/enum member. `PHPOWERNOTIFY`
has no standalone metadata definition in either output. The ordinary
`windows.h`-first TU obtains the handle aliases from `winuser.h`; they are
dependencies in that configuration. Macro origins and the alternate valid
header-first ownership configuration are documented in [README.md](README.md).

## Completed evidence

The patch passed 108 native declaration comparisons across C, C++, metadata C++,
x64/x86/ARM64, and both ownership configurations. Patch reversal restores the
exact original bytes. Four real negative controls were rejected by the intended
gates: removing the enum association, changing the input byte-count index,
replacing bytes with elements, and widening native `ULONG` to `ULONGLONG`.

The raw reader's final targeted tests passed 43/43, its full project suite passed
60/60, and its Release build had no warnings or errors. These results do not
establish the missing metadata equivalence.

## Completed run and residual blockers

The complete orchestration ran to its final verdict using the pinned consumer:
generation, all source ledgers, 108 native comparisons, and all four real
negative controls passed. Its manifest status is
`verified evidence; unresolved logical differences`. Exit 1 is the explicit
non-equivalence verdict, not a compiler or provenance failure.

The source ledger now follows actual Clang preprocessing evidence for the
`CallNtPowerInformation` return: expansion of `NTSTATUS`, definition tokens
`NTSTATUS LONG`, and the included `shared\bcrypt.h:39` typedef. Both the native
return and typedef canonicalize to four-byte `long`. This is recorded separately
from the ordinary native dependency graph, without a name allowlist or a
reference-derived replacement type.

Remaining blockers are the two unresolved shared `WIN32_ERROR` associations and
the member, handle, direction, and schema differences enumerated above. They
require individual corrections or explicit supported representation/source-error
dispositions, not blanket normalization. Only the existing tooling owner is
changing the consumer; no independent Cargo edits or SDK type substitutions
were made here.

Historical regressions remain preserved: `25f9fe` suppressed all five functions
through an exclusion reference; `24d0e59` restored RDL roots but failed all six
variant/architecture compile cases because typedef definitions and references
used different namespaces. Both are fixed in the latest paired outputs, not
silently discarded from the evidence.

The authorized next step is one complete, SDK-source-backed shared
`Foundation.WIN32_ERROR` **pilot prerequisite/bridge**, not another API pilot or
a claim that shared enum authoring has migrated into a shipped SDK patch.
Inventory/evaluation found exactly 3,378 members (3,288 `winerror.h`, 90
`setupapi.h`) matching all published names/values on three architectures.
The 380 excluded raw family candidates are compiler-typed `HRESULT` and use
`_HRESULT_TYPEDEF_`. Production bridge generation will use SDK sources and
compiler evaluation only; legacy JSON/WinMD are inventory/comparison inputs only.

## Persistent artifacts

Artifact root:
`C:\Users\jevansa\.copilot\session-state\ac7b652c-c8c0-40c2-8251-946330986647\files\powerbase`

| Relative path | Contents |
| --- | --- |
| `canonical-97f7d9c-complete\manifest.json` | Complete run status, exact commands, all pins/hashes and verification implementation hashes |
| `canonical-97f7d9c-complete\comparison\REPORT.md` | Current complete 16-row reference/control/candidate symbol table |
| `canonical-97f7d9c-complete\comparison\DEPENDENCIES.md` | Every dependency field and enum member |
| `canonical-97f7d9c-complete\contracts` | Raw reference and eight architecture/merged snapshots |
| `canonical-97f7d9c-complete\comparison\symbols` | Exact per-symbol three-way facts |
| `canonical-97f7d9c-reviewed\logical` | Explicitly reviewed representation rules; original full-run verdict remains preserved |
| `canonical-97f7d9c-complete\negative-metadata` | Three actual regenerated metadata mutations and rejection evidence |
| `canonical-97f7d9c-complete\native` and `negative-native` | Repeated native matrix and native type mutation evidence |
| `shared-win32-error-inventory` | Complete SDK source origins, raw type/value evaluations on three architectures, and one-time reference comparison |
| `pinned-cb645326-run-2` | Earlier successful flat-namespace control/candidate evidence, including all raw differences |
| `canonical-25f9fe-owner` | Rejected zero-function regression output |
| `canonical-24d0e59-root-repro` | Corrected RDL roots, exact compile failure and immutable tool provenance |
| `canonical-24d0e59-independent-roots` | Remaining five architecture/variant root inventories and identical compile failures |
| `canonical-368abc-root-repro` | Passing canonical paired WinMDs, eight exact decoded root inventories/hashes, and explicit source-ledger failure |

Work is isolated on `jevansaks-powerbase-equivalence-pilot`, with the required
original tooling base in its ancestry. Verified reader work is checkpointed in
`4cfc5dbe78`; pilot source is checkpointed separately without claiming parity.
The end-to-end gate remains red for the reasons above. No PR has been created.

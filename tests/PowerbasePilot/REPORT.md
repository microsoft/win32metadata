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
tooling prerequisite `d39bdcca908061a9c1ba1cb512a8a5ec98bc4a7b`, windows-rs
`368abc66cb7f24c58952a457d9b21e9215be846e`, SDK `10.0.26100.7705`,
libclang `22.1.8`, Rust `1.96.0`, and .NET SDK `10.0.401`.
Both variants use canonical `Windows.Win32.System.Power`, derived from the
existing Power partition's namespace setting. The earlier flat `cb645326`
comparison is preserved separately and is not used as the reference.

| Artifact | SHA-256 |
| --- | --- |
| Published reference | `6AEC29BE3359468D9EBA03C3AE932591B39960F1812B6D25D33C0D9F14A6D665` |
| Unmodified SDK header | `66082F57FF576850899FA3DEB4779C0B762163A70946D0BE4DF78F3A2A506FB2` |
| Consolidated patch | `C978A3EEC4A84E91819E5F348EE7F39CF74A166BA8A91F92198AF6D4F0FD6EAB` |
| Patched header | `6546F072285C0A32E537E8F9782510A7DAE045A807121E4D53437B450996B3B8` |
| Rust control, each architecture and merged | `004653E5982D60AED3F27F582C0FAA6A88C848F5F488EFAB695459499C05DD09` |
| Rust candidate, each architecture and merged | `D555F84CC0C9A22064317D458F3D7318C2E21C4F73FC4045AB7398E6FB851C4E` |
| Exact supplied consumer used for this comparison | `15F1C86848E971B8FCB91816252B6E0F11A0508D3BD7FB4839A2C4A50FFBB7EE` |

Control: 42 types including vocabulary, five functions, zero global constants.
Candidate: 44 types including vocabulary, five functions, zero global constants.
All eight WinMDs compile and contain the exact five required function names.
Vocabulary types are shared tooling prerequisites, not header-owned APIs.

| Function | Verified matching facts in candidate | Differences from the published reference |
| --- | --- | --- |
| `CallNtPowerInformation` | In/Out/Optional; mutable `void*`; byte-count indices 2/4; native widths; `NTSTATUS` wrapper shape; information-level members/values; import/calling convention; XP OS payload | Dependency enum field flags differ; `NTSTATUS` namespace mapping; shared vocabulary schema differences below |
| `GetPwrCapabilities` | `BOOLEAN` wrapper in return and all 23 affected fields; output direction; import/calling convention; `SetLastError`; XP OS payload | Two capability-array lower-bound encodings differ; `BOOLEAN` namespace mapping; shared vocabulary schema differences |
| `PowerDeterminePlatformRoleEx` | Return enum's ten members; unchanged native `ULONG`; In; import/calling convention; Win8 OS payload; association resolves to unsigned version enum | Version enum adds `CURRENT_VERSION`; enum field flags differ; full enum contract therefore not equal |
| `PowerRegisterSuspendResumeNotification` | Native widths; In/Out; flags association resolves, four values/unsigned storage/Flags match; import/calling convention; Win8 OS payload | `WIN32_ERROR` unresolved; output `HPOWERNOTIFY*` versus old `void**`; handle storage/ownership differ; enum field and vocabulary schema differences |
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
| `POWER_PLATFORM_ROLE_VERSION` | Unsigned `UInt32` in both; two -> three members; field-flag differences remain |
| `REGISTER_NOTIFICATION_FLAGS` | All four unsigned values and Flags match; namespace and field-flag differences remain |
| `POWER_PLATFORM_ROLE_CURRENT_VERSION` | Absent -> `UInt32(2)`; explicit extra synthetic alias, not silently accepted |
| `POWER_PLATFORM_ROLE_V1` | `UInt32(1)` -> `UInt32(1)`; literal metadata flags differ |
| `POWER_PLATFORM_ROLE_V2` | `UInt32(2)` -> `UInt32(2)`; literal metadata flags differ |
| `DEVICE_NOTIFY_SERVICE_HANDLE` | `UInt32(1)` -> `UInt32(1)`; literal flags/namespace differ |
| `DEVICE_NOTIFY_CALLBACK` | `UInt32(2)` -> `UInt32(2)`; literal flags/namespace differ |
| `DEVICE_NOTIFY_WINDOW_HANDLE` | `UInt32(0)` -> `UInt32(0)`; literal flags/namespace differ |
| `DEVICE_NOTIFY_ALL_INTERFACE_CLASSES` | `UInt32(4)` -> `UInt32(4)`; literal flags/namespace differ |

### Exact residual schema differences

Enum literals retain Constant rows and typed values, but their Field flags are
`86` instead of `32854` (missing `HasDefault`, `0x8000`); `value__` is private
instead of public (`1537` versus `1542`). Two native capability arrays encode
omitted lower bounds rather than explicit `[0]`. Vocabulary classes omit
`AutoClass`; `NativeTypedefAttribute` and `SupportedOSPlatformAttribute` omit the
reference's `AttributeUsage`; the RAIIFree constructor parameter is `name` rather
than `Name`. These exact facts are reported to the tooling owner, not collectively
classified as accepted normalization.

The effective report currently has 289 difference records per architecture.
These include repeated enum-member flag differences and are not 289 independent
bugs. Raw and effective views both remain available.

### Explicit representation policy

Unique declaration names may pair across namespaces only with compatible full
contracts; `BOOLEAN` and `NTSTATUS` wrapper shapes now match. A native integer
plus association may represent a legacy typed enum only when the target actually
resolves, storage matches, and the complete member/value/flags contract matches.
The present group/field differences still fail that gate. Documentation,
assembly identities, forensic tokens/blobs, and `BeforeFieldInit` are excluded
from native behavior only in the separate effective view; raw evidence retains
them. No direction, count units, typedef identity, ownership, missing target,
extra member, or unapproved schema difference is erased.

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

## Persistent artifacts

Artifact root:
`C:\Users\jevansa\.copilot\session-state\ac7b652c-c8c0-40c2-8251-946330986647\files\powerbase`

| Relative path | Contents |
| --- | --- |
| `canonical-368abc-complete\manifest.json` | Complete run status, exact commands, all pins/hashes and verification implementation hashes |
| `canonical-368abc-complete\comparison\REPORT.md` | Current complete 16-row reference/control/candidate symbol table |
| `canonical-368abc-complete\comparison\DEPENDENCIES.md` | Every dependency field and enum member |
| `canonical-368abc-complete\contracts` | Raw reference and eight architecture/merged snapshots |
| `canonical-368abc-complete\comparison\symbols` | Exact per-symbol three-way facts |
| `canonical-368abc-complete\logical` | Separate failed effective-contract verdict; raw facts retained |
| `canonical-368abc-complete\negative-metadata` | Three actual regenerated metadata mutations and rejection evidence |
| `canonical-368abc-complete\native` and `negative-native` | Repeated native matrix and native type mutation evidence |
| `pinned-cb645326-run-2` | Earlier successful flat-namespace control/candidate evidence, including all raw differences |
| `canonical-25f9fe-owner` | Rejected zero-function regression output |
| `canonical-24d0e59-root-repro` | Corrected RDL roots, exact compile failure and immutable tool provenance |
| `canonical-24d0e59-independent-roots` | Remaining five architecture/variant root inventories and identical compile failures |
| `canonical-368abc-root-repro` | Passing canonical paired WinMDs, eight exact decoded root inventories/hashes, and explicit source-ledger failure |

Work is isolated on `jevansaks-powerbase-equivalence-pilot`, with the required
original tooling base in its ancestry. Verified reader work is checkpointed in
`4cfc5dbe78`; pilot source is checkpointed separately without claiming parity.
The end-to-end gate remains red for the reasons above. No PR has been created.

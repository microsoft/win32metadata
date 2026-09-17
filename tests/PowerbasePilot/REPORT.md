# powerbase.h proof status

**Logical equivalence is not established.** This report preserves the completed
single-header work and the concrete remaining blockers. No other pilot header,
full-SDK claim, or PR is included.

## Last successful comparison

The published reference is `Microsoft.Windows.SDK.Win32Metadata`
`70.0.11-preview`, not a regenerated control. The successful paired run used
repository commit `f9cdbcf5cf57a622147cc73b4811db0e28a041c5`, windows-rs
`cb64532678dd48011ac4f5619fbe022e6ef3c503`, SDK `10.0.26100.7705`,
libclang `22.1.8`, Rust `1.96.0`, and .NET SDK `10.0.401`.
Its namespace was `Windows.Win32`; the subsequent canonical Power namespace
attempts below have not completed successfully.

| Artifact | SHA-256 |
| --- | --- |
| Published reference | `6AEC29BE3359468D9EBA03C3AE932591B39960F1812B6D25D33C0D9F14A6D665` |
| Unmodified SDK header | `66082F57FF576850899FA3DEB4779C0B762163A70946D0BE4DF78F3A2A506FB2` |
| Consolidated patch | `C978A3EEC4A84E91819E5F348EE7F39CF74A166BA8A91F92198AF6D4F0FD6EAB` |
| Patched header | `6546F072285C0A32E537E8F9782510A7DAE045A807121E4D53437B450996B3B8` |
| Rust control, each architecture and merged | `7AFD49C318E64739C2E9617FF1BF2D3BF457F351BC78384818BBC67402A12CB1` |
| Rust candidate, each architecture and merged | `FECED9F1B56E3C618191E3AE282A6342C54123E687F4134E3F9274531FB33D0C` |

Control: seven API types, five functions, zero global constants. Candidate:
nine API types, five functions, zero global constants. Attribute-reference
definitions are missing in these outputs and are not counted as emitted types.

| Function | Verified matching facts in candidate | Differences from the published reference |
| --- | --- | --- |
| `CallNtPowerInformation` | In/Out/Optional; byte-count indices 2/4; native parameter widths; information-level enum members; import/calling convention; XP OS attribute payload | Incorrect `IsConst` modifier on mutable input `PVOID`; `NTSTATUS` identity collapsed to `Int32` |
| `GetPwrCapabilities` | Output direction; import/calling convention; `SetLastError`; XP OS attribute payload | `BOOLEAN` identity collapsed to primitive `Boolean` in return and 23 of 33 capability fields |
| `PowerDeterminePlatformRoleEx` | Return enum's ten members; unchanged native `ULONG Version`; In; import/calling convention; Win8 OS attribute payload; association transported | Version enum incorrectly uses `Int32` instead of `UInt32`; candidate adds `CURRENT_VERSION`, absent from published metadata |
| `PowerRegisterSuspendResumeNotification` | Native `DWORD` widths; In/Out; flags group's four values, unsigned storage and flags meaning; import/calling convention; Win8 OS attribute payload; associations transported | `WIN32_ERROR` has no target definition; output is `HPOWERNOTIFY*` versus old `void**`; handle storage and ownership contracts differ |
| `PowerUnregisterSuspendResumeNotification` | Native handle pointer ABI; import/calling convention; Win8 OS attribute payload; return association transported | `WIN32_ERROR` has no target definition; native/candidate InOut versus old In; handle storage and ownership contracts differ |

Shared differences include five unresolved metadata vocabulary types and raw
namespace/documentation differences. Matching attribute payloads are transport
evidence, not proof that their definitions resolve or their schemas match.

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

## Current narrow blocker

**Update:** canonical paired generation now succeeds with repository
`d39bdcca908061a9c1ba1cb512a8a5ec98bc4a7b`, windows-rs
`368abc66cb7f24c58952a457d9b21e9215be846e`, and exact owner-supplied binary
`15F1C86848E971B8FCB91816252B6E0F11A0508D3BD7FB4839A2C4A50FFBB7EE`.
Both variants compile for all three architectures and merge. Decoding every
actual WinMD confirms exactly the five expected API functions in all eight
outputs, with zero global constants.

| Canonical output | Types including vocabulary | SHA-256 (each architecture and merged) |
| --- | --- | --- |
| Control | 42 | `004653E5982D60AED3F27F582C0FAA6A88C848F5F488EFAB695459499C05DD09` |
| Candidate | 44 | `D555F84CC0C9A22064317D458F3D7318C2E21C4F73FC4045AB7398E6FB851C4E` |

This is a compile/root-emission result, not updated legacy parity. The end-to-end
runner still returns failure at the source ledger: `bcrypt:NTSTATUS` is emitted,
but the native dependency walker follows the header's macro-expanded `LONG`
rather than its original `NTSTATUS` spelling. This requires explicit macro/type
provenance in the ledger; it is not, by itself, a metadata-consumer defect.
The bounded decoded comparison of these successful outputs is next.

The earlier failures remain preserved:

The successor `25f9fe3650c449b9dc148b6f8a1c1934a80baf6a` consumer silently
suppressed all five functions. The fixed root gate rejected its zero-function
outputs. The owner identified an exclusion-reference API incorrectly used in
place of resolution-only references.

The correction is repository commit
`27188f361a52e8c38af13da241c9bda49de8b801`, windows-rs
`24d0e59f96871ef361ea5053dc6eb981f1e44262`, binary SHA-256
`E43DACF0D99051A1D26901EEBAC8C97DA8CCC77B3087EA3A1B55F43B09B3B99A`.
It restores all five functions in canonical RDL, but x64 WinMD compilation fails:
`winnt.rdl:129:41` references `Foundation.BOOLEAN`, while `winnt.rdl:10`
defines it under `System.Power`. `NTSTATUS` has the same definition/reference
namespace mismatch. No x64 WinMD, other-architecture result, or candidate result
is claimed for that grouped run. A subsequent independent-architecture diagnostic
reached the remaining five cases: control x86/ARM64 and candidate x64/x86/ARM64.
Each has exactly the same five named function roots in RDL and fails at the same
`Foundation.BOOLEAN` reference; none emits a WinMD. Thus root restoration is
observed in all six source cases, but canonical metadata emission is still blocked.
The designated tooling owner has the exact reproducer;
no independent Cargo edits or SDK type substitutions were made here.

## Persistent artifacts

Artifact root:
`C:\Users\jevansa\.copilot\session-state\ac7b652c-c8c0-40c2-8251-946330986647\files\powerbase`

| Relative path | Contents |
| --- | --- |
| `pinned-cb645326-run-2\manifest.json` | Exact commands, pins, input/output hashes and tool identities |
| `pinned-cb645326-run-2\comparison\REPORT.md` | Complete 16-row reference/control/candidate symbol table |
| `pinned-cb645326-run-2\comparison\DEPENDENCIES.md` | Every dependency field and enum member |
| `pinned-cb645326-run-2\contracts` | Raw reference and eight architecture/merged snapshots |
| `pinned-cb645326-run-2\comparison\symbols` | Exact per-symbol three-way facts |
| `pinned-cb645326-run-2\logical` | Separate failed effective-contract verdict; raw facts retained |
| `pinned-cb645326-run-2\negative-metadata` | Three actual regenerated metadata mutations and rejection evidence |
| `native-patch-proof` and `negative-native` | Native matrix and native type mutation evidence |
| `canonical-25f9fe-owner` | Rejected zero-function regression output |
| `canonical-24d0e59-root-repro` | Corrected RDL roots, exact compile failure and immutable tool provenance |
| `canonical-24d0e59-independent-roots` | Remaining five architecture/variant root inventories and identical compile failures |
| `canonical-368abc-root-repro` | Passing canonical paired WinMDs, eight exact decoded root inventories/hashes, and explicit source-ledger failure |

Work is isolated on `jevansaks-powerbase-equivalence-pilot`, with the required
original tooling base in its ancestry. Verified reader work is checkpointed in
`4cfc5dbe78`; pilot source is checkpointed separately without claiming parity.
The end-to-end gate remains red for the reasons above. No PR has been created.

# Header-annotation migration playbook

Move authored semantic facts to reviewed header patches without changing native
contracts. Keep the C# scraper/emitter, matched ClangSharp stack and selected SDK.
The [annotation specification](copilot/plans/shift-left-annotation-spec.md) defines
the vocabulary; the [WinHttp pilot](winhttp-header-annotations.md) records one
complete example and its immutable evidence.

## 1. Bound the partition and its authorities

Inventory the actual same-SDK OLD metadata, native declarations and every applicable
sidecar, including non-prefix names, enum uses, callbacks, handles, manual code and
documentation mappings. Count emitted symbols, not just library-map rows.

| Input | Treatment |
| --- | --- |
| SDK import-library scan / generated `libMappings.rsp` | Retain as derived binding data. Do not copy correct scan results into header annotations. |
| Native declarations, SAL and MIDL | Retain as native authority; do not duplicate direction, size, string or optionality information. |
| Current-TU discovery and derived aggregate remaps | Retain discovery, with the tooling's annotated/legacy precedence. Do not turn cached discoveries into authored facts. |
| Authored OS/error, logical-enum, ownership, callback and buffer overrides | Review each contract, migrate supported facts, and remove only the matching authored fallback. |
| Manual import overrides | Use `ImportLibrary` only for demonstrated missing/incorrect scan data; retain generic override support. |
| Namespace/traversal/architecture/schema configuration and documentation tooling | Keep separate from functional semantic migration. |

Bind each physical header to one owner. Include all physical-header and semantic
dependents in the validation closure, without migrating their unrelated facts.
An API absent from the selected SDK must not be recreated as a fake declaration.

Before authoring patches, enable annotation parsing alone for the candidate with
unmodified headers and current authored inputs. Use the existing scoped scrape
to compare its declarations with the matched OLD output, separately accounting
for formatter trivia and constants-stage root imports. Parser-activation changes
such as native-comment `RetVal` additions are not annotation relocation. Reject
or defer out-of-policy changes at this cheap admission boundary, before migrating
sidecars; do not add another preparation framework or a full SDK build per
candidate.

## 2. Prepare headers once before toolchain consumption

Add reviewed deltas to the SDK-wide `generation\WinSDK\patches\SdkHeaders.json`
recipe, with explicit patch order, admitted headers, SDK package identity,
preimages and post-MIDL source identity. Keep physical-header ownership and
dependencies explicit. The tracked SDK mirror is never an output.

The single generic `PrepareSdkHeaders` stage supplies an explicit recipe to
`Prepare-SdkHeaders.ps1` before native toolchain consumption. Ordinary builds,
selected scraping and constants use the same private include root. Do not add
partition hooks or partition-default recipes to orchestration.

Preserve byte encodings and line endings, transactional publication, deterministic
caching, path/preimage checks and rejection of modified caches. A changed root
invalidates constants and every architecture's header marker; an unchanged root
retains them. Prove this with the existing preparation controls.

Respect the MIDL boundary. The current preparation script admits post-MIDL
recipes; it is not permission to rerun broad SDK/IDL update scripts or silently
introduce a pre-MIDL pipeline. Surface a bounded blocker if that is required.

## 3. Admit only the approved representation changes

| Change | Required grade |
| --- | --- |
| Existing enum use site becomes its native type plus `AssociatedEnum` | Exact owning parameter/field, native width/signedness and existing enum identity/member/value checks. |
| Justified fabricated-handle removal and producer return/output ownership relocation | Exact removed type and affected signatures, cleanup API, invalid values and attribute targets; no invented ownership for borrowed handles. |
| All other migrated facts | Same signatures, layouts, callback identity, imports, OS floors, last-error and SAL contracts. |

No new enum types, enum members, loose constants, API families, compatibility
aliases or broad difference/duplicate allowlists. Preserve existing logical
member names and values while leaving native macros intact. Document any
user-approved metadata-only naming exception at the header boundary.

Remove matching authored fallback rather than annotating on top of it.
SDK-derived bindings and discoveries are not semantic fallback. Keep import
module/entrypoint/flags checks even when no header import override is needed.

## 4. Pin OLD, tooling control and NEW separately

Freeze a complete OLD image and generated-source/discovery closure from one SDK
and an exact tooling commit. Emit a matched frozen-input tooling control when
tool binaries change. Attribute tooling-only differences to that control, not to
the partition migration; never waive a known OLD defect on NEW.

Commit producer inputs before publishing a fresh named NEW artifact. Record SDK,
producer/tooling commits, binary hashes, recipe/prepared-header identity, complete
source/reference closure and expected-difference hashes. Do not overwrite previous
images or receipts.

Use the existing selected scrape/full-source overlay loop where appropriate.
`PartitionFilter` alone does not narrow constants, manual files or emission
closure. Recompute complete constants and pointer discoveries, retaining
unselected inputs. Reject success-shaped partial images with dangling references.

## 5. Validate the actual output, not a proxy

- Compile metadata-disabled native owner/dependent translation units on x86,
  x64 and ARM64; check signatures, calling conventions, pointer levels, constants
  and record layout.
- Read the final full winmd for imports, attribute targets/constructors,
  associations, ownership, enum identities/membership, signatures, layout,
  callbacks, architecture coverage and reference closure. Preserve unrelated
  physical snapshots and existing mutation controls.
- Compare OLD/control/NEW with exact symbol-scoped expectations: zero unknown
  differences and zero unused expectations. Investigate any unapproved category
  before admitting the candidate. A declaration comparer plus scoped physical
  checks is not a comprehensive typed-equivalence oracle.
- Repeat the normal SDK build with prior discoveries present. Require identical
  selected source/discovery inputs, shared prepared roots and complete SDK
  diagnostic inputs.
- Run the smallest affected existing suites and full-SDK integrity checks.
  Verify nonzero executed counts and no skipped acceptance legs. Build tools
  before emission; never rebuild DLLs while an emitter is using them.

Physical snapshots match literal-only `Apis` fields by owning type and name,
not incidental metadata row order. Moving WinHttp's three typed port constants
from constant overrides to header declarations changes that order but not their
names, unsigned 16-bit types or values. Actual metadata mutation controls must
still reject changed names, owners, types and values. Instance-field layout,
enum-member order and method/vtable order are not canonicalized.

## 6. Report consumer compatibility independently

CsWin32 source compatibility is the primary consumer gate, not identical winmd
encoding. When an agreed immutable consumer is available, pin its version,
requests, options, target framework and unchanged caller source; compare public
surfaces and compile both OLD and NEW callers in both marshaling modes.

Separate identical output, source-compatible differences and exact source breaks.
Do not infer compatibility from a producer comparison. If the consumer cannot be
run under the agreed ownership constraints, report **unverified**. Do not search,
rebuild or modify another owner's consumer checkout to manufacture proof.

## 7. Publish a reviewable checkpoint

Keep the migration separate from the independently reviewable tooling layer.
Use the owning branch and existing draft PR, with a short WHAT/WHY description,
the current approved delta and links to durable details. Do not merge or change
native stack metadata.

Require full CI green on the final exact head of both tooling and migration PRs;
record check/run links and SHAs. Earlier successful heads and local tests do not
substitute. Do not skip checks or weaken gates to obtain green.

For a correctness/design problem, capture one bounded reproducer and correct it
within established patterns. Otherwise report the exact blocker, owner and
smallest decision, or replace the candidate through the agreed selection process.
Do not expand into parser frameworks, consumer features or prolonged speculative
investigations. Summarize each partition as relocated facts, exact representation
changes, unchanged native/dependent contracts, and an honest consumer grade.

## Selected follow-on partitions

The bounded follow-on to WinHttp uses these batches in the same migration PR.
Each batch must pass the preceding producer gates before the next is admitted.

| Batch | Owners | Physical headers |
| --- | --- | --- |
| 1 | CEIP, ApplicationVerifier | `windowsceip.h`, `avrfsdk.h` |
| 2 | MagApi, PsApi1, Time, Ual | `magnification.h`, `psapi.h`, `timezoneapi.h`, `timeprov.h`, `ual.h` |
| 3 | ToolHelp, UpdateAssessment, Wsl, Xinput | `tlhelp32.h`, `waasapi.h`, `waasapitypes.h`, `wslapi.h`, `xinput.h` |

The image helper reads the recipe's complete owner/dependent partition list and
overlays the sources actually produced for those partitions. `Base` and
`FileHistory` also include batch-1 headers; they remain unconverted dependents.
`PsApi2` shares `psapi.h` with `PsApi1` and must remain unchanged. A shared
namespace is not evidence of shared semantic ownership.

Batch 1 relocates the emitted `CeipIsOptedIn` Windows 8.1 floor, independently
confirmed by its published requirements, while retaining its SDK-derived
`KERNEL32.dll` binding. `VerifierEnumerateResource` relocates its genuine
`verifier.dll` override and existing `ResourceType` association; its existing
`VERIFIER_ENUM_RESOURCE_FLAGS` group retains both names, values, order and
unsigned 32-bit storage, with `Flags` becoming native `ULONG` plus
`AssociatedEnum`. That is two additional declaration differences, not a new enum.
A complete selected-SDK import-library scan found neither verifier entrypoint.
`VerifierIsPerUserSettingsEnabled` is absent from compiled OLD, so its unused OS
row is explicitly outside emitted-owner migration accounting and is retained.

Batch-1 checkpoint: producer `0a01605e37ace4128c8cc01cd6efadb1add02525`,
full image SHA256
`F1B647FC43E28D546B5991EFE695C6C1D678092BEEB7127747F41B7A41B8240D`,
receipt SHA256
`96FFBCA0F352BBF8E074A8A965844BF5038047D6A976D5779922C104F8999570`.
The strict declaration grade uses all 18 expectations with zero unknown/unused
differences. All 37,314 physical types and 7,791 enum identities are accounted for;
only nine exact enum-use sites differ. Eighteen owner/dependent native legs,
23 physical/no-fallback/mutation checks, 25 preparation/closure controls and
14 full-SDK integrity checks pass. Eighteen repeated source/discovery inputs are
byte-identical, and all 155 pointer reductions remain present. Artifacts are in
`artifacts\header-annotation-wave\batch1`; prior immutable candidates are retained.
Fresh consumer compatibility remains unverified.

Batch 2 moves only emitted owners: MagApi's 19 OS floors, one last-error fact
and two existing `MW_FILTERMODE` uses; PsApi1's 27 OS floors, 27 last-error facts
and `EnumProcessModulesEx` filter use; Time's 13 OS floors and 11 last-error
facts; and Ual's four OS floors. Correct SDK-scanned bindings remain untouched.
Both logical groups retain precisely OLD membership, order and unsigned 32-bit
storage; `MW_FILTERMODE` includes an annotated pointer parameter.

The existing native `PSAPI_VERSION == 1` branch owns the PsApi1 annotations and
logical group. The version-2 `K32*` declarations are not annotated or migrated;
PsApi2 remains opted out and is regenerated as an unchanged dependent. Time's
`timeprov.h` is pinned and compiled but has no emitted DLL-function facts to
relocate. Its three unused provider-export OS rows remain outside this scope.

Batch-2 checkpoint: producer `7d89f8e7f10176f3bdaa1490ae917b65be710175`,
full image SHA256
`E3177B33ED5F48879431BE7FF0446E183F873A97E1DB1EE677665D4F8FCA826F`,
receipt SHA256
`2BD8090F5CEBFF554FF9E4C85D3B24D28652D35C0EFA4A1A6EB2E83A1F252E07`.
All 24 declaration expectations are used, with zero unknown/unused differences.
All 37,314 physical types are graded: 37,305 unchanged and 12 exact enum-use
sites normalized; all 7,791 enum identities and contents remain unchanged.
Thirty-three native legs, 23 physical/no-fallback/mutation checks, 26
preparation/closure/fallback checks and 14 full-SDK checks pass without skips.
The 28 repeated source/discovery inputs are byte-identical; all 155 pointer
reductions remain. Artifacts are in `artifacts\header-annotation-wave\batch2`.
These overlapping run counts are not a unique-test total. Consumer compatibility
remains unverified.

The complete batch-2 [CI regeneration](https://github.com/microsoft/win32metadata/actions/runs/38695188241)
at `1e97e92d386492806928f84587e3073adc89033c` is also green. Its winmd SHA256 is
`D8593620542480E34B03691F53AC63314C78A4F17B4B5E17D458705C68F32946`;
all 24 exact expectations are used with zero unknown differences. This is
independent of the local selected-source overlay. In particular, `WinBase.h`
includes `timezoneapi.h`, so selected native cases alone do not cover every
transitive SDK translation unit. Final expanded-head full regeneration and
strict artifact grading remain required.

Batch 3 moves 16 ToolHelp XP floors and 15 last-error facts, retaining the
non-error-annotated `Toolhelp32ReadProcessMemory` contract. Its two existing
logical groups retain unsigned 32-bit storage and all ten members: only
`CREATE_TOOLHELP_SNAPSHOT_FLAGS` is a flags enum. The two native DWORD use sites
become associated rather than substituted enum types.

UpdateAssessment moves only `IWaaSAssessor`'s Windows 10 build 15063 floor.

These floors agree with the published requirements for
[ToolHelp](https://learn.microsoft.com/windows/win32/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)
and [IWaaSAssessor](https://learn.microsoft.com/windows/win32/api/waasapi/nn-waasapi-iwaasassessor).
UpdateAssessment separately pins its supplied IDLs and checked-in post-MIDL
headers.

Global `IUnknown`/`IDispatch`, BSTR/VARIANT helpers, and Foundation `HANDLE`
definitions remain outside these physical owners. No snapshot handle identity
or ownership assumption is invented.
The 16 emitted ToolHelp DLL bindings are independently reproduced
by the preference-free SDK scan and remain derived bindings, not header overrides.

Wsl relocates seven genuinely missing-scan API-set library overrides from its
partition settings to native declarations. The complete pinned SDK scan contains
none of those entrypoints. Their exact `Api-ms-win-wsl-api-l1-1-0.dll` binding is
retained, as specified by the native header's contract. Its real
`WSL_DISTRIBUTION_FLAGS` enum and native typed uses stay unchanged; no ownership
assumption is added for standard handles or the process output.

Xinput relocates exactly ten existing logical groups, 82 members and ten uses.
Five groups use byte storage, four use unsigned 16-bit storage, and `XINPUT_FLAG`
uses unsigned 32-bit storage. Only its four existing flags groups carry `Flags`;
in particular, `XINPUT_VIRTUAL_KEY` remains nonflags. The three threshold members
already present in `XINPUT_GAMEPAD_BUTTON_FLAGS` and the explicit
`XINPUT_FLAG_ALL = 0` member are preserved, not repaired or repopulated by prefix.
No ordinary `XINPUT_FLAG_ALL` macro is invented. Eight fields and two parameters
retain native byte/WORD/DWORD types plus associations. Its seven DLL bindings
remain SDK-derived; no binding is copied into header overrides.

Both replacement candidates passed opt-in-only admission before patches: all
2,501 Wsl and 2,115 Xinput namespace declaration tokens match frozen OLD.
Only formatter trivia and the existing constants-stage root usings differ.
`replacement-opt-in-admission.json` records that bounded grade; final winmd and
physical validation remain separate gates. Both SDK headers match their pinned
native preimages byte-for-byte, and each has only its owning direct partition.

### Deferred COM opt-in finding

The proposed SecurityCenter/WinSat conversions are not admitted. Producer
`ab29038d22518c027d2cedab33ea747353ddd2d8` emitted a rejected image with SHA256
`37CB3A49C657F9787CEC85749EBEFECCEC4C3BB9319070752FDFF7AFB3B7677C`.
Its strict comparison found 28 additional parameter-flag changes:
16 in SecurityCenter and 12 in WinSat gain `RetVal` from existing native
`[retval]` comments, for example `IWscProduct.get_ProductName.pVal` and
`IProvideWinSATAssessmentInfo.get_Score.score`.

These changes are outside the approved representation categories. The three
COM header patches and opt-ins are removed and their authored facts restored;
neither native comments nor SAL/parser policy is changed to hide the finding.
The rejected image and exact difference log remain in
`artifacts\header-annotation-wave\batch3`; the separate
`batch3-rejected-grade.json` receipt records the rejection. Successful
native/preparation controls and repeatability do not override this failed
metadata gate. Wsl and Xinput replace these candidates without widening allowed
differences; consumer compatibility remains unverified.

Sens is also deferred, not migrated. Its existing logical
`SENS_CONNECTION_TYPE` members encode `CONNECTION_LAN = 0` and
`CONNECTION_WAN = 1`, whereas native `sens.h` defines them as 1 and 2.
That needs a separate compatibility/design decision. No SDK value, metadata
value, macro or alias is changed to force this candidate through the playbook.

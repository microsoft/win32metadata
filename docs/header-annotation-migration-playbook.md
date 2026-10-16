# Header-annotation migration playbook

Move authored semantic facts to reviewed header patches without changing native
contracts. Keep the C# scraper/emitter, matched ClangSharp stack and selected SDK.
The [adopted annotation specification](https://github.com/microsoft/win32metadata/blob/733477d4ecc3ea3e6e979a9ce26930df62d065af/docs/copilot/plans/shift-left-annotation-spec.md) defines
the vocabulary; the [WinHttp pilot](winhttp-header-annotations.md) records one
complete example and its immutable evidence.

## 1. Bound the partition and its authorities

Inventory the actual same-SDK OLD metadata, native declarations and every applicable
sidecar, including non-prefix names, enum uses, callbacks, handles, manual code and
documentation mappings. Count emitted symbols, not just library-map rows.

| Input | Treatment |
| --- | --- |
| SDK import-library scan / generated `libMappings.rsp` | Retain as derived binding data. Do not copy correct scan results into header annotations. |
| Native declarations, SAL and MIDL | Capture their existing annotations faithfully, including facts OLD omitted; do not author redundant direction, size, string or optionality information. |
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
for formatter trivia and constants-stage root imports. Parser activation can
faithfully expose existing native annotations that OLD omitted, such as MIDL
`[retval]` comments. Classify these separately from annotation relocation, record
their exact source and metadata changes, and surface meaningful consumer effects
for review. Do not suppress those facts or reject/replace a candidate merely to
preserve OLD omissions. Keep this a cheap classification boundary before patch
authoring, not another preparation framework or a full SDK build per candidate.

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

## 3. Capture native facts and classify every difference

Faithfully capturing existing SDK, SAL and MIDL annotations is always acceptable,
even when it changes OLD metadata. This is a general rule, not a `RetVal` exemption.
OLD is a comparison baseline, not authority to suppress the native contract.
Classify and present exact OLD-to-NEW metadata and consumer differences to the
user for review instead of excluding a migration solely to retain OLD omissions.

A source-derived addition must be traceable to an existing fact in the pinned
native sources, with its exact declaration, owner, target, payload and architecture
coverage. Verify that interpretation rather than inventing API/type/ownership
claims or authoring arbitrary annotations to force a comparison grade. Newly
authored header patches still require independent contract review; calling a
patch a header does not make every added assertion source-derived.

| Change | Required grade |
| --- | --- |
| Existing SDK/SAL/MIDL annotation absent or differently represented in OLD | Exact source-backed expectations for each affected symbol, attribute/parameter flag, target and payload; classify metadata and consumer effects for review. |
| Existing enum use site becomes its native type plus `AssociatedEnum` | Exact owning parameter/field, native width/signedness and existing enum identity/member/value checks. |
| Justified fabricated-handle removal and producer return/output ownership relocation | Exact removed type and affected signatures, cleanup API, invalid values and attribute targets; no invented ownership for borrowed handles. |
| Other relocated facts | Preserve signatures, layouts, callback identity, imports, OS floors, last-error and SAL contracts unless an individually source-backed correction is identified and presented as above. |

This rule does not authorize manufacturing logical enum types or members, loose
constants, API families or compatibility aliases, or silently repairing logical
value conflicts. Preserve existing logical member names and values while leaving
native macros intact unless a separate review resolves a conflict. Document any
user-approved metadata-only naming exception at the header boundary.

Keep expectations exact and source-backed, with zero unknown differences and zero
unused expectations. There is no blanket native-derived difference or duplicate
allowlist, and no assumption that faithful capture implies consumer compatibility.

Remove matching authored fallback rather than annotating on top of it.
SDK-derived bindings and discoveries are not semantic fallback. Keep import
module/entrypoint/flags checks even when no header import override is needed.

### Factor SupportedOS facts without broadening coverage

Use only the canonical `_Win32_SupportedOS_*_` declaration macros and
`_Win32_SupportedOS_BEGIN_(os)` / `_Win32_SupportedOS_END_()` controls from the
[adopted contract](https://github.com/microsoft/win32metadata/blob/733477d4ecc3ea3e6e979a9ce26930df62d065af/docs/copilot/plans/shift-left-annotation-spec.md#scoped-supportedos-defaults).
There are no public `_Windows_` aliases. An explicit declaration fact wins over
all defaults; otherwise the innermost applicable scope wins, not the greatest
version. A scope applies only to eligible declarations lexically within that same
physical header and include instance. Includes do not inherit a caller's default;
a container's annotation does not imply inheritance by its methods or nested
types. Balance controls on every active preprocessing path.

Inventory existing facts before grouping them. End scopes before unannotated
declarations, records, typedefs and metadata-only enums; retain direct annotations
where grouping would add a floor. This adoption factors exactly the completed
B9 producer's 119 authored OS facts, not every declaration in an annotated header:

| Owner | Existing floors | Scopes | Direct annotations retained |
| --- | --- | --- | --- |
| WinHttp | 38 | 10 | 4 |
| CEIP | 1 | 0 | 1 |
| ApplicationVerifier | 0 | 0 | 0 |
| MagApi | 19 | 2 | 0 |
| PsApi1 | 27 | 4 | 11 |
| Time | 13 | 5 | 1 |
| Ual | 4 | 1 | 0 |
| ToolHelp | 16 | 7 | 1 |
| UpdateAssessment | 1 | 0 | 1 |
| Wsl / Xinput | 0 | 0 | 0 |

The 29 scopes cover 101 existing function declarations: 100 use their default,
and `GetWsChangesEx` retains its explicit Vista floor inside an XP scope.
PsApi1 controls remain conditional on `PSAPI_VERSION == 1`; PsApi2 stays
unconverted and unchanged. Time's scopes stop before the unannotated `Local*`
functions. ToolHelp's scopes exclude every record/typedef block. CEIP and
`IWaaSAssessor` retain direct annotations rather than assigning floors to
additional declarations or COM methods.

The required net metadata change from this factoring step is zero versus the
immutable B9 surface, in addition to the existing exact OLD-to-NEW grade.
Compare all physical type snapshots without scope-specific normalization or
allowances. Pin a fresh producer/image and matched frozen-input tooling control
after adopting the tested tooling dependency; never relabel B9 receipts or infer
semantic equivalence from line-count reduction.

Build the same-tooling canonical-direct control before factoring, then compare
the scoped candidate with both that control and B9. Keep
`--nativeFieldArrayInfo` absent/default-off in this OS-only workflow. Its separate,
SDK-wide source inventory and activation must not be hidden inside OS-scoping
expectations. The rejected `efc20826` frozen-input image and its 563 exact
field-annotation differences remain diagnostic evidence, not admitted changes;
the normal `43af342a` follow-up restores the default-off boundary and excludes
scalar access spans from array inference.

## 4. Pin OLD, tooling control and NEW separately

Freeze a complete OLD image and generated-source/discovery closure from one SDK
and an exact tooling commit. Emit a matched frozen-input tooling control when
tool binaries change. Attribute tooling-only differences to that control, not to
the partition migration; never waive a known OLD defect on NEW.

Commit producer inputs before publishing a fresh named NEW artifact. Record SDK,
producer/tooling commits, binary hashes, recipe/prepared-header identity, complete
source/reference closure and expected-difference hashes. Do not overwrite previous
images or receipts. If only documentation advances the branch, retain the actual
producer and CI-run labels on those frozen artifacts; a documentation head is not
a new emission or a fresh image grade.

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
  differences and zero unused expectations. Investigate every unclassified
  difference and record the source evidence for native-derived additions;
  surface meaningful metadata and consumer changes to the user for review.
  Do not suppress faithful native facts or use a blanket allowance to make the
  grade pass. A declaration comparer plus scoped physical checks is not a
  comprehensive typed-equivalence oracle.
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
Include the consumer effects of newly captured native annotations in that review;
their source authority is not proof of source compatibility. Do not infer
compatibility from a producer comparison. If the consumer cannot be run under the
agreed ownership constraints, report **unverified**. Do not search, rebuild or
modify another owner's consumer checkout to manufacture proof.

## 7. Publish a reviewable checkpoint

Keep the migration separate from the independently reviewable tooling layer.
Use the owning branch and existing draft PR, with a short WHAT/WHY description,
the current approved delta and links to durable details. Do not merge or change
native stack metadata.

Require full CI green on the final exact head of both tooling and migration PRs;
record check/run links and SHAs according to repository CI policy, including for
documentation-only follow-ups. Earlier successful checks do not substitute for
required current-head checks. Keep image evidence pinned to its actual producer
and run, rather than relabeling it as a grade of a later documentation head.
Do not skip checks or weaken gates to obtain green.

For a correctness/design problem, capture one bounded reproducer and correct it
within established patterns. Otherwise report the exact blocker, owner and
smallest decision, or replace the candidate through the agreed selection process.
Do not treat faithful capture of an existing native annotation as such a blocker
merely because OLD omitted it; classify and review the exact difference instead.
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
strict artifact grading are recorded for the completed B9 producer below.

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

### Completed producer checkpoint (B9, immutable)

The completed WinHttp-plus-ten producer is
`b9fae9d6cb315a93cb342beb2e79a6aa33a64f5d`, above tooling
`00ade0afc94c965522ccdbac54a06fc1bcbd01a1`. This evidence belongs to that
producer, not a later documentation-only branch head.

| Frozen evidence | Identity |
| --- | --- |
| Local full image SHA256 | `A0C321735141D55C98BCD7D048F822AAA0DA1D9434309ABA1782F79C220773BB` |
| Local provenance SHA256 | `A1379DFE6BD4AB2301356A723007FBD248D51E612D35E1441622456EE7327AF3` |
| Full-regeneration CI | [38703254017](https://github.com/microsoft/win32metadata/actions/runs/38703254017), exact B9 producer, successful |
| Downloaded CI image SHA256 | `BF78829E239721F8DCCD865CBC1F15D3A9D8CD749826A169ADF2B9FF51C24CA0` |
| Final review receipt SHA256 | `317644536D5FDB1B9129E5F1137C2636C245944733126CB7DD79F2837CC42091` |

Both images use all 48 exact declaration expectations at 24 existing enum-use
sites (10 parameters and 14 fields), with zero unknown or unused differences.
All 37,314 physical types are graded, and 7,791 enum identities and contents
are preserved. The downloaded CI image independently passes all 23
physical/no-fallback/mutation cases and has the same declared surface as the
local image without allowances. Dedicated native, preparation and SDK runs
execute 45, 26 and 14 cases respectively without skips; 36 repeated
source/discovery inputs are identical. These overlapping counts are not a unique
test total. The artifacts and original receipts under
`artifacts\header-annotation-wave\batch3-final` and
`artifacts\header-annotation-wave\ci-final-38703254017` remain immutable.
Fresh consumer compatibility remains unverified.

### Scoped SupportedOS adoption checkpoint

Tooling `43af342a3dd63803bf12a7c834cd0fd516df74ab` supplies the canonical
direct/scoped contract. The same-tooling canonical-direct producer
`a8e192627d90f71f8de080efb38a09f5bc67fb1e` was emitted and admitted before
factoring: every one of B9's 37,314 physical type snapshots is unchanged.
The scoped producer is `a18ba84473ceedf53bfe8e3a94a2bc5c6eb962cf`.

| Immutable local evidence | SHA256 |
| --- | --- |
| Canonical-direct full image | `AA7B0D71E535787D2A5B623F8B144AEDCF66A464F1E769C7ADC56CF83EA2EE43` |
| Scoped full image | `374318BB6239DA59F6B00E7C69E46C1C7D94C4FFF3F206CBE1281E38722E1B90` |
| Scoped provenance | `F8ACECD6B5E761D857388FED33060F15D8938661B98545769770204F7124886B` |
| Local scope-adoption grade | `EFC149644CD5141B0968B9B6CF2C05135FD5C260166B161CE5E862DA80943AEC` |

The scoped image is physically identical to both the canonical-direct control
and B9: all 119 OS floors, signatures, layouts, attributes and existing
7,791 enum identities/contents remain unchanged. The 29 scopes and 19 direct
annotations add no new OS coverage, API symbols, enums or members. The combined
OLD-to-NEW grade remains the original 48 exact differences at 24 enum-use sites,
with zero unknown differences or unused expectations; no scope allowance was
added.

Actual-image admission passes 26 physical/no-fallback/mutation cases, 45 native
architecture legs, 19 preparation controls, three mixed-partition closure cases
and 14 full-SDK integrity cases without skips. The complete 393-file diagnostic
closure, 36 repeated source/discovery inputs and all 155 pointer reductions are
preserved. Artifacts are under `artifacts\supported-os-scopes`; the grade is
`local-scope-grade-a18ba844.json`. These are local producer receipts, not a claim
about a later CI image. Final-head CI and downloaded-image qualification are
recorded separately in the [draft PR](https://github.com/microsoft/win32metadata/pull/2365).
Fresh CsWin32 compatibility remains unverified.

### Historical COM finding under the earlier policy

The proposed SecurityCenter/WinSat conversions were excluded under the earlier,
narrower difference policy. Producer
`ab29038d22518c027d2cedab33ea747353ddd2d8` emitted the historically rejected image
with SHA256
`37CB3A49C657F9787CEC85749EBEFECCEC4C3BB9319070752FDFF7AFB3B7677C`.
Its strict comparison found 28 additional parameter-flag changes:
16 in SecurityCenter and 12 in WinSat gain `RetVal` from existing native
`[retval]` comments, for example `IWscProduct.get_ProductName.pVal` and
`IProvideWinSATAssessmentInfo.get_Score.score`.

The behavior comes from the C# `HeaderAnnotationProcessor.HasRetvalComment`
implementation introduced in tooling commit
`b5b7b26ed09d648766f07449af48c64ef0e99d13`, not a new Clang feature. Enabling the
annotation path makes that existing C# lowering visible for these declarations.
No production suppression was added: the two whole migrations were excluded,
their three header patches and opt-ins were removed, and their authored facts
were restored. Native comments and SAL/parser behavior were not changed to hide
the finding.

The general source-derived-annotation policy above resolves that earlier policy
objection. Faithful capture is acceptable; the exact metadata and consumer
effects should be classified and surfaced for review, not rejected merely to
retain OLD omissions. The historical image and exact difference log remain in
`artifacts\header-annotation-wave\batch3`; the separate
`batch3-rejected-grade.json` receipt still records the earlier rejection, not a
new successful grade. That policy clarification did not re-enable those
migrations or change their producer inputs or expectations. Wsl and Xinput remain
the completed batch-3 owners; fresh consumer compatibility remains unverified.

Sens is also deferred, not migrated. Its existing logical
`SENS_CONNECTION_TYPE` members encode `CONNECTION_LAN = 0` and
`CONNECTION_WAN = 1`, whereas native `sens.h` defines them as 1 and 2.
That needs a separate compatibility/design decision. No SDK value, metadata
value, macro or alias is changed to force this candidate through the playbook.
Accepting existing native annotations is not approval to repair that logical
enum conflict or manufacture new enums or members.

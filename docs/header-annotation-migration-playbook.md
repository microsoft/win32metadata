# Header-annotation migration playbook

Move authored semantic facts to reviewed header patches without changing native
contracts. Keep the C# scraper/emitter, matched ClangSharp stack and selected SDK.
The [adopted annotation specification](https://github.com/microsoft/win32metadata/blob/8d6d5290e8a5421ba6e565752e79c011ea40d470/docs/copilot/plans/shift-left-annotation-spec.md) defines
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

### SDK-wide inventory and source queue

`scripts\Get-SdkAnnotationCoverage.py` inventories the selected SDK package,
partition traversals, response files, enum/handle JSON, manual sources and active
original-source patches without scraping, running MIDL or building the WinMD.
It requires Python's standard library, the cached selected SDK/D3D packages, Git
history and the frozen original-source qualification ledger supplied to the run.
Keep reports and campaign reservations in session artifacts, not the SDK mirror.

```powershell
python .\scripts\Get-SdkAnnotationCoverage.py `
    --ledger $frozenOriginalSourceLedger `
    --output "$artifacts\coverage.json" `
    --campaign "$artifacts\campaign.json" `
    --queue-output "$artifacts\queue.json" `
    --native-owner-output "$artifacts\native-owners.json" `
    --idl-owner-output "$artifacts\idl-owners.json" `
    --scoreboard-output "$artifacts\scoreboard.json" `
    --strict-apply
```

The campaign supplies the single-writer session, worker-to-role assignments,
explicit `reservedOriginals` path arrays, tool revisions and optional
`sourceReceipts` with committed revisions and exact original paths. Original
paths are exclusive locks; ordinal batch IDs are only convenient grouping.
Reassign only confirmed unstarted paths. The native owner map preserves the
existing applicator's `readyOriginalOwners` schema and exact OS/error rows;
candidate ownership still requires its three-architecture AST admission.
Original-IDL inputs are separate, with actual source hashes, generated-header
mapping candidates and explicit unsupported residuals.

Use `--refresh` with the same output/campaign/queue/owner-map/scoreboard arguments
to update operational reservations and committed-source receipts without
rescanning the SDK. It requires an unchanged production tree and a strictly
applied baseline before counting later receipts. Receipt patches come from
shared Git objects and are strictly applied to small private original copies;
no worker checkout, SDK installation or production patch is modified.

Read each denominator separately: SDK-CPP original inputs, generated header
origin slots, partitions and the historical qualification cohort are different
units. The report distinguishes direct enum substitutions from `AssociatedEnum`,
retained facts from baseline removals, and configuration/parser fixes from
authored contracts. No mapped facts does not prove no migration is needed.
Unresolved original ownership, unbound D3D overlays, auto-populated enum member
counts and manual-source semantic counts remain explicitly unknown.

The scoreboard counts unique committed, nontrivially strict-applied native
header paths, excluding the SAL bootstrap from API-header totals. Revising a
previously counted header adds no new owner; IDL paths and recipe output edges
do not count as changed generated headers. Optional campaign
`generatedOutputObservations` point to small frozen producer receipts with the
source commit, exact output paths, before/after hashes and positive authored
carrier/source-contract evidence. Only these semantically changed outputs join
the deduplicated known header-goal count; other generated outputs remain unknown.
Campaign `goalExcludedNativeHeaders` records explicit reasons for withholding
credit from nontrivial patches that do not complete any relocated fact; physical
strict-application counts remain visible separately. Likewise,
`goalExcludedGeneratedHeaders` lists observed output `header` paths and explicit
`reason` values for withdrawn or held credit. Their positive preparation evidence
remains diagnostic; they do not count toward the header goal. Reported
`reportedProductionGates` do not erase genuine source changes or imply producer
acceptance. Compilation/qualification is separate from source conversion, and
source conversion may retain explicit sidecar cleanup debt. Run the focused inventory controls with
`python -m unittest discover -s tests\SdkAnnotationCoverage.Tests`.

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

Recipe admission prepares headers; it does not activate the normal annotation
reader. Every admitted partition must also enable `--config` /
`parse-win32-annotations` in its existing `Partitions\<name>\settings.rsp`.
Keep this incremental: do not globally enable unmigrated partitions to cover a
missing owner opt-in. `AuthoredSdkPartitionsEnableNormalHeaderAnnotationProcessing`
checks the combined recipe, including admissions from other source cohorts.
Then measure the exact facts in ordinary generated sources: a native fixture
that explicitly defines `WIN32METADATA` does not prove normal scraper activation.

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

Respect the SDK artifact boundary, not just a recipe filename extension. Patch a
shipped source IDL before MIDL when its corresponding generated header owns the
fact; keep real direct-shipped header artifacts as header patches. A generated
dependency is not automatically another annotation target. Never run broad
SDK/IDL update scripts to implement a bounded migration: those scripts reset the
mirror and restore removed SDK artifacts.

The existing preparation path supports an explicit `midl` closure in the same
recipe. Pin every SDK IDL/import/ACF/preprocessor input, `midl.exe` and `midlc.exe`,
and bind each regenerated output to its admitted mirror header and exact SDK
IDL. Keep one cumulative patch per SDK artifact, named with its SDK-relative path:
`patches\um\winhttp.h.patch` or `patches\um\waasapi.idl.patch`. Each diff targets
that same artifact (`a/um/winhttp.h` to `b/um/winhttp.h`), starting from its pristine
admitted SDK bytes, not another patch's output. Reject repeated targets even
under different filenames; do not stack semantic layers on a header.

Artifact identity determines preparation, not a stage directory or recipe order.
Apply direct-header patches to private SDK header copies and IDL patches to the
pinned raw source closure before the existing MIDL-to-SAL conversion and shared
`MidlHeaderUtils.ps1` flags regenerate only the admitted outputs. There are no
post-MIDL annotation patches or patches on generated headers. Scraping
and constants still consume one private root. Reject generated-header patches,
unpinned imports, changed tools/preimages, failed generation and modified caches;
never fall back to an old generated header.
Every admitted header whose source IDL participates in the MIDL input closure
must have its own pinned output, including an unpatched IDL that includes a
patched source. A shared declaration guard can otherwise make an unchanged
including header hide all of the regenerated base header's annotations.
Unrelated pinned IDL-backed dependencies outside that closure retain their mirror
bytes; this check does not expand the bounded regeneration scope.

Run the selected C preprocessor with closed include paths and cleared ambient
compiler options; hash its executable/engine and the SAL/helper scripts into the
preparation identity. When `/cpp_opt` overrides MIDL's forwarding, explicitly pass
the same `/D` definitions and private `/I` paths, including `MIDL_PASS=1`.
The shared SDK SAL patch and metadata SAL shim provide the common annotation
bootstrap; do not repeat annotation-header includes in individual API patches.
An original IDL must obtain SAL before using annotation carriers. MIDL imports
do not establish C-preprocessor macro visibility, so the two annotated pilot
IDLs need ordinary `#include <sal.h>` directives. Their generated headers already
obtain SAL through native RPC headers. The same rule applies to annotated native
C headers imported by MIDL: `appmgmt.h` must include SAL itself, even when the
importing `shappmgr.idl` already does. Keep the shared bootstrap rather than
adding per-header no-op annotation definitions. Pin every actual SAL dependency and the
canonical repository helper's exact `sourceSha256` in the MIDL closure; do not
pretend the helper came from the selected SDK or search ambient include paths.
A header patch consumed by MIDL must bind the same pristine SDK input as its
native-header copy and apply to both private snapshots before conversion.
Verify MIDL's actual saved preprocessor input set against
the declared closure. Preserve raw inputs, converted IDLs, commands, diagnostics,
outputs and their hashes in the private cache. Keep warnings enabled and compare
the exact diagnostic/target/payload multiset against unmodified-IDL regeneration,
accounting only for source line shifts. Do not add native `[local]` attributes or
suppress diagnostics to make an annotation compile.
For source-IDL methods that cannot legally carry native MIDL annotations, use
the shared `_Win32_AnnotateMethod_(Interface::Method, annotation)` helper after
the complete interface declarations. Keep related calls in an existing trailing
quote region. Do not place a bare annotation or documentation comment in
`cpp_quote` inside an interface: MIDL hoists it outside the method. Do not
change a remotable method to `[local]`. Even legal annotations on a local method
also decorate its generated proxy, so verify the actual target in final metadata.
Group interface forward carriers in an existing opening quote region to avoid
creating new compiler-generated standard-interface regions between interfaces.
The same SDK stage copies its verified manifest and MIDL evidence to
`obj\prepared-sdk-provenance\<architecture>\<identity>` so existing generated-asset
CI artifacts preserve actual compiler identities and closed inputs, not just an
ephemeral include-root pathname.

Metadata must compose with native SAL. The converter does not skip a parameter
line merely because it also contains metadata annotations. Consolidate adjacent
SAL and metadata annotation payloads: MIDL otherwise emits only the last
`annotation(...)` attribute and silently drops the preceding SAL. Check the
actual regenerated header and final metadata, not just converted IDL text.

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

Retain genuine native macro aliases when a logical enum moves into headers.
Removing a duplicate loose enum-member constant must not leave a surviving alias
initializer unbound. The emitter qualifies a simple alias to the unique enum
member in the same namespace and applicable architecture, preserving the alias's
declared constant type. Ambiguous bindings remain errors; do not add enum members,
rewrite native values or suppress aliases merely because OLD omitted them.

Removing an authored enum use can also remove the namespace inference of a
retained, unmigrated logical enum. Preserve its existing namespace through the
existing global namespace-resolution configuration; do not retain a semantic
fallback use, duplicate the enum or allow a namespace change in the grade.
For a typed native constant that changes source-emission position, any physical
comparison adjustment must name that exact static literal, assert its complete
type/value/attribute shape, and preserve every other field's order and layout.

Keep expectations exact and source-backed, with zero unknown differences and zero
unused expectations. There is no blanket native-derived difference or duplicate
allowlist, and no assumption that faithful capture implies consumer compatibility.

Remove matching authored fallback rather than annotating on top of it.
SDK-derived bindings and discoveries are not semantic fallback. Keep import
module/entrypoint/flags checks even when no header import override is needed.

### Factor SupportedOS facts without broadening coverage

Use only the canonical `_Win32_SupportedOS_*_` declaration macros and
`_Win32_SupportedOS_BEGIN_(os)` / `_Win32_SupportedOS_END_()` controls. There are no
public `_Windows_` aliases. Scopes use Clang's lexical attribute accumulation:
included declarations inherit an active scope, and distinct conflicting floors
fail rather than selecting an explicit, innermost or greatest-version winner.
A direct container attribute alone does not annotate its methods or nested
types. Balance controls on every active preprocessing path, and move boundaries
instead of relying on a reader-defined override policy.

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
| PsApi1 | 27 | 4 | 12 |
| Time | 13 | 5 | 1 |
| Ual | 4 | 1 | 0 |
| ToolHelp | 16 | 7 | 1 |
| UpdateAssessment | 1 | 0 | 1 |
| Wsl / Xinput | 0 | 0 | 0 |

The planned placements retain 29 scopes and 20 direct annotations. In PsApi1,
`GetWsChanges` uses a direct XP floor, `GetWsChangesEx` keeps its direct Vista
floor, and the XP scope resumes at `GetMappedFileNameW`. No conflicting XP/Vista
attributes accumulate on `GetWsChangesEx`; no active pilot scope encloses an
include. These placements still require the qualified tooling and image gates
below; source inspection is not a replacement metadata grade.
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

### Express existing logical groups without native symbol additions

Use `_Win32_Enum_(name, storage, existing_constants...)` or
`_Win32_FlagsEnum_(name, storage, existing_constants...)`, retaining native ABI
types and `_Win32_AssociatedEnum_(group)` at the existing use sites. Both group
macros expand to nothing when `WIN32METADATA` is absent. Their values come from
compiled native expressions, not copied literals or a second source parse.

Eighteen pilot groups use those public macros. Two existing groups need explicit
historical labels through the same AST transport, guarded by `WIN32METADATA`:
`WINHTTP_INTERNET_SCHEME` maps its four existing `WINHTTP_INTERNET_SCHEME_*`
labels to genuine `INTERNET_SCHEME_*` expressions, and `XINPUT_FLAG` retains its
reviewed `XINPUT_FLAG_ALL` member with compiled value `0` alongside
`XINPUT_FLAG_GAMEPAD`. Use a
`typedef _WIN32META_ANNOTATION_("Enum(labels...)", expressions...) storage GROUP`
carrier (`FlagsEnum` for flags); do not create SDK `#define` aliases, ordinary
consumer symbols or metadata-only constant globals. There are no authored RAII
facts to add in this pilot.

Place each group before its first associated use, after its native constants.
Four SDK source-order exceptions instead use an early, unannotated
`typedef DWORD GROUP;` under `WIN32METADATA`, followed by the one annotated
public group typedef at the existing constants: `WINHTTP_ACCESS_TYPE`,
`WINHTTP_CREDS_AUTHSCHEME`, `CREATE_TOOLHELP_SNAPSHOT_FLAGS` and
`HEAPENTRY32_FLAGS`. Keep the same native storage and declaration scope, outside
unintended OS scopes. This is a compiler-bound redeclaration of the same
metadata-only type, not another logical group or an SDK alias. Do not move
native constant blocks to accommodate the annotation.

## 4. Pin OLD, tooling control and NEW separately

Freeze a complete OLD image and generated-source/discovery closure from one SDK
and an exact tooling commit. Emit a matched frozen-input tooling control when
tool binaries change. Attribute tooling-only differences to that control, not to
the partition migration; never waive a known OLD defect on NEW.

Commit producer inputs before publishing a fresh named NEW artifact. Record SDK,
producer/tooling commits, binary hashes, recipe/prepared-header identity, complete
source/reference closure and raw API-comparison hashes. Do not overwrite previous
images or receipts. If only documentation advances the branch, retain the actual
producer and CI-run labels on those frozen artifacts; a documentation head is not
a new emission or a fresh image grade.

Use the existing selected scrape/full-source overlay loop where appropriate.
`PartitionFilter` alone does not narrow constants, manual files or emission
closure. Recompute complete constants and pointer discoveries, retaining
unselected inputs. Include compiler-projected `partition.header-types.cs`
companions in selected overlays, repeat-input hashes and source provenance;
reject an orphan companion or a changed repeat source-file set. Reject
success-shaped partial images with dangling references.

For expanded integration, an emitted overlay image is not proof that every
physical dependent was freshly scraped. `Windows.h` unconditionally includes
`winnetwk.h`; at least 308 direct Windows-header-dependent partitions require
fresh source closure in the actual full-SDK producer run. They are physical
dependents, not additional semantic owner migrations.

RstMgr relocates eleven existing `WIN32_ERROR` return substitutions to native
`DWORD` returns with exact enum associations, and the existing
`RM_PROCESS_INFO.AppStatus` association stays on native `ULONG` storage. The
native `RM_APP_STATUS` enum, its nine members and non-Flags representation stay
unchanged. One bounded Vista scope covers exactly the eleven owned functions,
replacing eleven matching OS sidecar rows. Correct SDK library bindings remain
derived. `CCH_RM_SESSION_KEY` remains a separately held native-expression parser
gap; no native macro or manual constant shape is changed. This source integration
does not constitute actual architecture/image/full-SDK/CI acceptance.

The Proc_Snap/Monitor/IdentityProvider input preserves native handle projection,
the `PSS_CAPTURE_FLAGS=uint` storage repair, four Monitor `_BOOL` return-alias
repairs and Identity parser/name configuration. Only HPSSWALK's complete
`PssWalkMarkerFree`/`[-1,0]` contract moves to its actual creator output. HPSS's
invalid-only row stays: `PssFreeSnapshot` takes both a process and snapshot handle,
so it is not a unary cleanup contract. Native `IdentityUpdateEvent` stays
unscoped with its original eight members; its Flags designation and two
native-DWORD associations move into headers. Seven anonymous source-coordinate
shifts are transport details, not permissions to change physical field metadata.
The private input counts are source accounting, not final emitted admission.

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
- Preserve the complete unfiltered API-comparison output. Do not check in a
  difference-allowance file or give the image builder a default acceptance list.
  Record concrete source-backed differences for review in PR comments. An image
  receipt marked `reviewStatus: required` reports differences; it does not admit
  them. A failed comparison remains an error, not a review result.
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
`FileHistory` also include batch-1 headers; at that checkpoint they remained
unconverted dependents.
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

## Later qualified tooling, native DWM storage and SDK artifact form

The owning branch explicitly ordinary-merges qualified root `7ea6c85d` at
`80477883`, then serially integrates the interop and component inputs at
`b05c91ea` and `a5bb02fb`. The earlier `89a2ad02`/`9a1fd6f8` images and their
437-difference receipts remain historical controls, not new-tooling, new-input
or DWM acceptance. The eight new owners relocate 22 OS rows: 14 existing
emitted targets and eight intentionally unmapped native exports. Configuration
and recipe counts are source inventory, not accepted semantic-fact totals.

The approved DWM correction removes only `DWM_SHOWCONTACT=uint`. The native
SDK enum and `DwmShowContact(DWORD, enum DWM_SHOWCONTACT)` declaration remain
unchanged. A fresh Dwm scrape without that override produces default `int`
storage and `DWMSC_ALL = unchecked((int)(0xFFFFFFFF))`, meaning `-1` with the
same 32 bits. The exact physical gate permits this one enum's storage and
constant type codes to change from UInt32 to Int32, while preserving all seven
member names, order, values/bits, flags, attributes and the function signature.
All other enum storage remains literal. This approved change can affect managed
source that assumes an unsigned underlying type; actual consumer effects remain
unverified and no consumer work is part of this migration.

The combined native-retval expectation also includes the three existing
`IRendezvousSession` contracts documented above, separately from relocated facts.
No field inference is activated, the DHCP array sidecar stays, and the shared
LocalSize/DirectML effects remain outside these owners.

The final upstream patch payload must match the artifact shipped in the SDK.
Declarations shipped as IDL require pre-MIDL patches against that IDL and
regenerated headers; direct-header patches remain only for actual header-source
artifacts. The existing post-MIDL patches and images are retained as controls,
not described as the final upstream-ready form. The coordinated artifact-form
conversion and the resulting fresh source, matched OLD/control/NEW physical
grades, strict comparison, and actual final-head CI image qualification remain
prerequisites for final acceptance.

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
Its current patch is authored in shipped `waasapi.idl`, not the generated header;
the [pre-MIDL source adoption](#pre-midl-source-adoption) retains the same fact.

These floors agree with the published requirements for
[ToolHelp](https://learn.microsoft.com/windows/win32/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot)
and [IWaaSAssessor](https://learn.microsoft.com/windows/win32/api/waasapi/nn-waasapi-iwaasassessor).
UpdateAssessment separately pins its supplied IDLs and checked-in post-MIDL
header preimages.

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

### Pre-MIDL source adoption

The SDK CPP `10.0.26100.7705` artifact audit covers every recipe header and
actual patch target. Only the patched `waasapi.h` is generated from a shipped
IDL. `httprequest.h` is an unpatched IDL-backed dependency; `waasapitypes.h` is
an unpatched imported output regenerated with `waasapi.h`. All remaining
annotation targets, including `winhttp.h`, remain direct-header patches.
The eleven owners and fifteen owner/dependent partitions do not change.

`um\waasapi.idl.patch` applies to the actual shipped
`waasapi.idl` preimage
`A29CC19E76CFC63B284E24F2B81BFBF523436B9F29C51121882D255B82A51C38`.
It emits the annotation include and a C++-only forward declaration carrying
`_Win32_SupportedOS_15063_` specifically on `IWaaSAssessor`. MIDL rejects a
direct interface annotation, and a surrounding scope would also annotate
methods. This target-specific `cpp_quote` preserves the existing type-only
floor, UUID, method, native `[out, retval]` and library contract without a
reader change or a generated-header fallback.

The closed source set is nine IDLs (`waasapi`, `waasapitypes`, `oaidl`,
`objidl`, `objidlbase`, `unknwn`, `unknwnbase`, `wtypes`, `wtypesbase`),
`oaidl.acf`, `basetsd.h` and `guiddef.h`. MIDL's saved preprocessing proves
all twelve inputs, including the two base-IDL `#include`s and automatic ACF.
The selected SDK x64 MIDL is 8.01.0628, executable SHA256
`53CCBCBC2FF14B2D08D029AD07B3D1AA4FF3B103F712199A15248A6CCCF6D2A3`;
its engine is pinned separately. Each preparation records the actual selected
Visual C++ preprocessor/engine identities rather than assuming every machine
has the same Visual Studio installation.

Unmodified-IDL regeneration reproduces both mirror headers byte-for-byte.
The candidate leaves `waasapitypes.h` byte-identical and preserves native SAL
in `waasapi.h`. Baseline and candidate retain the same 497 native warnings for
the types compilation and 498 for the assessor compilation, with zero added
diagnostic/target/payload entries. There is no warning suppression or native
`[local]` workaround. Cold regeneration produces the same complete prepared
header bytes; cache reuse verifies rather than repairs the published tree.

The actual regenerated SDK translation unit passes metadata off/on controls on
x86, x64 and ARM64: native signatures/layout remain unchanged, with exactly
the intended type-level OS annotation enabled and no method/unrelated-type
annotation. Permanent preparation controls exercise mixed SAL/metadata through
real MIDL, import/tool/preimage rejection, wrong-stage and syntax failures,
ambient-include isolation, repeat bytes and cache tampering. These native and
preparation results are separate from final-image and exact-head CI admission;
the immutable B9 and scoped-adoption evidence above is not relabeled.

The committed local producer is
`8125cddd2ec2fbf20c6e58a58f233ac95599dd82`, normally synchronized to qualified
tooling `7ea6c85d85f6e54ba39273f9ef4897d3301d42e1`.

| Immutable local pre-MIDL evidence | SHA256 |
| --- | --- |
| Full pilot image | `9F8BA94A4376998FD177240CEA541F616672AB7C96CC9893B8C55A5E371AE35E` |
| Image provenance | `2D83ECDC7E8A94BD424E0FC7C33C7A512D92903F1E93FB527122D985E5AB553C` |
| Fresh frozen-input tooling control | `C4C5081A2CD62F9E2ED300E2841617672E866A84B8AD8142CE80FA243DEC281D` |

This actual image has zero declared and physical differences from accepted B9
and the matched canonical-direct control, and zero declared differences from
qualified c587. All 119 effective OS floors match OLD on every architecture;
the existing OLD-to-NEW grade remains exactly 48 differences at 24 existing
enum-use sites, with zero unknown or unused expectations. All 30
physical/no-fallback/OS-floor cases and 14 SDK integrity cases execute and pass.
The complete 393-file diagnostic closure, 36 repeated source/discovery inputs
and 155 pointer reductions are retained. Artifacts are under
`artifacts\pre-midl-pilot`. These local receipts retain their actual producer;
final-head CI and its downloaded-image grade are recorded separately in the
[draft PR](https://github.com/microsoft/win32metadata/pull/2365).
No full-SDK migration or consumer work is resumed by this source-format change.

### SDK-artifact patch consolidation

The six WinHttp semantic layers are folded into `um\winhttp.h.patch`, starting
from the pristine selected SDK header. The pilot now has eleven artifact-keyed
patches, including `um\waasapi.idl.patch`; there are no stage directories or
multiple patches on one canonical SDK artifact. The preparation guards reject
layered targets, bundled artifact diffs, generated-header targets and
intermediate direct-header preimages.

The layout-only control against qualified `129b900d` compares every byte of all
3,443 prepared headers and retains tree SHA256
`E8BED2C71FD18503B44A6B55B5D2DBE2B41E856888DA7AAC38A19FD97EFB6249`.
All twelve raw and SAL-converted MIDL inputs, both regenerated headers, commands,
actual import closure and baseline warnings are unchanged; cache reuse and cold
regeneration retain those header bytes. The focused 38 preparation cases and
13 directly affected native/layout cases pass without skips. No new local
all-partition scrape or emission is needed for this mechanical cleanup, and no
API-difference expectations change. Historical image qualification remains tied
to its original producer; the new head's CI state is recorded in the draft PR.

### First-parse public-macro adoption

The adoption source is tooling commit
`746d812dd15a93d77b24285708fd51727b293bba`, merged without rewriting the pilot's
history. Its canonical shared helper is pinned as a thirteenth MIDL input,
SHA256 `5C02968168112A7DA993056680041C458CEAFFEA31AFE37A8FE17444C3D1F246`.
The twelve original selected-SDK inputs remain separately hash-bound.
`_Win32_AnnotateInterface_(IWaaSAssessor, _Win32_SupportedOS_15063_)` expands
during MIDL preprocessing to the existing C++ target-specific forward carrier;
the same helper bytes are included by the regenerated header.

MIDL's explicit C-preprocessor options retain every required define, including
`MIDL_PASS=1`, and each quoted private include directory. Saved preprocessing
must read exactly the declared SDK/helper closure. There is no ambient SDK or
environment fallback, second parse, or backend-specific transport gate.
Preparation and native controls are not final-image admission: the new image,
119-floor and physical-equivalence grades and exact-head CI must be recorded
separately before publication is qualified.

Local producer `5df1154cabb7bd30990d2c9bcd96a27ebc114f30` emits the complete
pilot image, SHA256
`7D63CE48046A6E4D759D206E0CF9493BAEBB97484FD32CE1735F0019BCEA6673`.
Its two selected scrapes reproduce all 25 main/companion sources and discovery
inputs byte-for-byte. The image preserves all 119 effective floors on all three
architectures, all 7,791 enum identities and all 37,314 physical types against
both the immutable accepted B9 and canonical-direct controls, without scope
normalization. The frozen-input tooling control is declaration-zero against OLD
and physically changes only the 39 previously measured constructor instance bits.

The raw OLD comparison is still exactly 48 declaration differences at the 24
existing native-integer/`AssociatedEnum` sites. There are no new API symbols,
logical groups or members. The 140 focused preparation, comparison, native and
physical-metadata cases and 14 integrity cases pass without skips, using the
complete 393-file diagnostic closure. The local receipt is
`artifacts\public-macro-adoption\locally-qualified-5df1154c.json`; it does not
claim the separate current pilot CI/downloaded-image gate. Exact published-head
CI and source-bound artifact qualification are recorded in draft PR #2365.
The prerequisite's direct-source CI `38966888753` is independently green at
`746d812dd15a93d77b24285708fd51727b293bba`, with zero image declaration changes.

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

## Next bounded wave above PR 2365

This separate draft starts at `162f8118a7da2ecb38d410a66b729dda64ca6767`;
the reviewed tooling and WinHttp-plus-ten branches are unchanged. Its checkpoints
are SecurityCenter/WinSat, then Wcm/InputRadial/WinContacts/WinLocation, then
Rdc/Nla/Com.CallObj/Com.Events. The latter eight have real emitted authored OS facts,
not just parser opt-ins. Their unmodified-header admission compares exact C#
declaration tokens after removing only the explicitly identified native MIDL
`RetVal` additions. This admission is not a final-winmd or consumer grade.

Enstor is excluded as a **Learn-versus-legacy-sidecar discrepancy**: its existing
Vista RTM floor differs from the published Vista SP2 requirement. This is not a
conflicting native-header annotation and does not qualify acceptance of native
SDK/SAL/MIDL contracts. Its header, floor and sidecars remain unchanged; there is
no further Enstor investigation in this wave. Com.Events is the routine
replacement, admitted against unmodified headers with 15 actual emitted
Windows 2000 floors and no predicted new final retval metadata.

SecurityCenter relocates five OS floors and the existing
`IWSCProductList.Initialize.provider` association; WinSat relocates seven
interface OS floors. Three reviewed patches preserve the original native types,
macros, method order and signatures. Shared Foundation, COM, BSTR/VARIANT and RPC
facts remain under their existing owners, and FileHistory remains an opted-out
physical-header dependent.

The first pair deliberately captures 28 native-derived `RetValAttribute`
additions: 16 SecurityCenter and 12 WinSat parameters. The existing
`iwscapi.h:189` and `winsatcominterfacei.h:259` MIDL comments are representative
sources. These are not newly authored retval assertions. Exact expectations and
physical architecture cases distinguish the custom attribute from raw CLI
`ParameterAttributes.Retval`, retain `Out`, and check unchanged signatures.
The earlier rejected receipt is historical evidence and is not relabeled.

The first pair's immutable local checkpoint is producer
`e559be49e2d2dc064874a815cbf81846074c42ae`, image SHA256
`B45712BFF48B652A6A304AB043D599EBB086E5CE145A986F900E1404E8362F23`.
Strict B9-CI-to-checkpoint grading uses exactly 28 native additions; cumulative
OLD-to-checkpoint grading uses 76 differences, including the prior layer's 48
enum representation entries. Both have zero unknown and zero unused
expectations. All 37,314 physical types and 7,791 enum identities are graded;
25 preparation/retval, 51 native architecture, 26 physical/no-fallback/mutation
and 14 full-SDK cases executed with zero skipped. The owning receipt is
`artifacts\next-header-annotation-wave\checkpoint1-review-grade.json`, SHA256
`A939C4740676722D2500A10BD98290301BF27CB0D2679C49CEC41ADE8DE79E61`.

Checkpoint two relocates 19 existing OS floors through four ordinary per-header
patches: Wcm 5, InputRadial 2, WinContacts 5 and WinLocation 7. Exact native
`locationapi.h` MIDL declarations identify 39 additional retval sites, including
`ILocationReport.GetTimestamp.pCreationTime` and
`ILocation.GetReport.ppLocationReport`. WinContacts' injected source annotations
repeat final metadata already supplied by SAL; source occurrence counts are not
new final-attribute counts. The verified second checkpoint is producer
`7f7dd082e6d9ecf6b308620e5bf2b41c85541543`, image SHA256
`8EDA57048DC25ED5C97844991B17CEE94B498005E941000EB6D1A14B9EAC7A02`.
Its strict first-checkpoint delta is 39; B9-CI-to-checkpoint is 67 and cumulative
OLD-to-checkpoint is 115, each with zero unknown and zero unused expectations.
All physical types and enum identities remain unchanged. Actual execution is
26 preparation/retval/ownership, 63 native architecture, 26 physical/no-fallback/
mutation and 14 full-SDK cases, with zero skipped. Its immutable receipt is
`artifacts\next-header-annotation-wave\checkpoint2-review-grade.json`, SHA256
`06BF5961603134C7AE57FC0B145065FD50CB846AFF5E2D5D9332038186EECEAE`.

Checkpoint three relocates another 51 emitted OS floors: Rdc 17, Nla 12,
Com.CallObj 7 and Com.Events 15. Four ordinary per-header patches preserve all
existing declarations. The original `netlistmgr.h:1860` MIDL
`/* [retval][out] */ __RPC__out BOOL *pValue` contract identifies the single additional
site `INetworkConnection2.IsDomainAuthenticatedBy.pValue`. Com.Events' source
injections repeat final SAL-derived attributes rather than introducing new ones.
ComOle, WindowsConnectionManager and TransactionServer join the preparation and
native-control closure as explicitly opted-out physical-header dependents.

Com.Events also relocates the existing
`IEnumEventObject::Reset=[CanReturnMultipleSuccessValues]` authored contract to
`_Win32_PreserveResult_` on the same native method in `EventSys.h`. The explicitly
review-approved representation removes that legacy custom attribute and sets the
CLI `MethodImplAttributes.PreserveSig` bit. This is an authored-fact representation
change, not a newly discovered native annotation or a conflicting SDK contract.
The existing reader and vocabulary already support it; no tooling expansion is
needed. It has its own exact declaration expectation and physical checks on x86,
x64 and arm64. HRESULT, signature and vtable order stay unchanged; fresh consumer
compatibility remains **UNVERIFIED**.

The bounded wave therefore relocates 82 OS floors, one existing association and
one existing success-value contract through 11 patches; it does not author new
enum representations or library overrides. The exact measured native additions
are SecurityCenter 16, WinSat 12, WinLocation 39 and Nla 1. B9-to-final expectations
are 68 native additions plus the single reviewed preserved-result representation;
the cumulative OLD-to-final total is 117, including the 48 enum representation
differences from the preceding reviewed layer, not this new wave.

| Owner | OS floors relocated | Other existing facts relocated | Native RetVal additions | Patches |
| --- | ---: | --- | ---: | ---: |
| SecurityCenter | 5 | 1 provider association | 16 | 2 |
| WinSat | 7 | None | 12 | 1 |
| Wcm | 5 | None | 0 | 1 |
| InputRadial | 2 | None | 0 | 1 |
| WinContacts | 5 | None | 0 | 1 |
| WinLocation | 7 | None | 39 | 1 |
| Rdc | 17 | None | 0 | 1 |
| Nla | 12 | None | 1 | 1 |
| Com.CallObj | 7 | None | 0 | 1 |
| Com.Events | 15 | 1 preserved-result contract | 0 | 1 |

The verified final local producer is
`b61b71256b05d09c3a7f51cf7f823856ba6bbf2b`, image SHA256
`9F95FBD1913EAF47F1E0D4C495AD0247F6642F6F9F545A4F80B0F682409DF8A8`.
Strict checkpoint-two-to-final grading uses 2 differences; B9-CI-to-final uses
69 and cumulative OLD-to-final uses 117, each with zero unknown and zero unused
expectations. All 37,314 physical types and 7,791 enum identities/content are
graded, with no new types, enums, members, values or native ABI changes.
The 29 preparation/retval/preserved-result/ownership, 84 native architecture,
29 physical/no-fallback/mutation and 14 full-SDK cases actually executed with
zero skipped. The SDK integrity suite used 786 hash-recorded diagnostic inputs.
The immutable local receipt is
`artifacts\next-header-annotation-wave\checkpoint3-review-grade.json`, SHA256
`3DA0A4DA1B29FC0A5412CD0F4BD677AE410A88619169659209CE7D134A1AE825`.

The complete tracked SDK mirror remains tree
`77817f12308e29ec8bf77dc6fe56786e65ff9e08`. Derived `libMappings.rsp` is
byte-identical to the filtered starting baseline, SHA256
`BE92DDDD387279BEA0BDF8F3D838B1466A5465A694BFFB6B6FAAE94447F9EC7A`.
Final CI acceptance is a separate mandatory gate: the
[draft review report](https://github.com/microsoft/win32metadata/pull/2367)
records the exact review head, actual checkout commit/tree, green run, downloaded
artifact and independent artifact grade. A documentation-only review head is not
the local emission producer, and this local receipt is not CI provenance.

The existing image helper now relocates a copied frozen traversal map to its
owning worktree and prepared headers. It verifies one original SDK project root,
keeps the frozen OLD files/provenance unchanged, and records that original root
in the new receipt; it never reads the previous owner's checkout while emitting.
Fresh consumer compatibility remains **UNVERIFIED**; no consumer work or merging
is part of this wave.

## Ordered full-SDK integration checkpoint

The owning integration branch adopts qualified dependency
`c5879a778bfbf0463e3c96beadab4b2d56658ffe`, including tooling
`43af342a3dd63803bf12a7c834cd0fd516df74ab`, by ordinary merge. The existing native
stack and both reviewed lower branches are preserved. The SDK mirror is now
tree `d3dc662e56c715c1e0c000a0300ff3088e9a9f17`; its annotation helper changes,
not the selected SDK declaration preimages.

The ten-owner patches receive exactly 82 prefix-only changes from
`_Windows_SupportedOS_` to `_Win32_SupportedOS_`. Their named aliases, payloads,
declaration membership and authored facts are unchanged. Prior local and CI
receipts remain historical evidence; the synchronized checkpoint requires its
own actual image grade before queued owner payloads are admitted.

`--nativeFieldArrayInfo` remains absent/default-off. The rejected 563-field
diagnostic is not an accepted control, and no field sidecar is removed by this
synchronization. Native field activation, fresh physical dependency closure and
final full-SDK image/CI acceptance remain separate gates.

Selected-image assembly checks every fresh input before removing any frozen
source. It replaces the selected partitions' entire common/x86/x64/arm64 file
set, preserves unselected and non-header bytes, and records the exact removed
paths in `removedBaselineHeaderSources`. The existing preparation-test fixture
exercises architecture-shape changes, missing-input safety and overlapping-root
rejection against the actual helper function. This corrects selected-source
replacement, not stale unselected dependencies: the Network layer still needs
a fresh canonical SDK scrape for its full physical include closure.

## Parallel small API patch input

The Wcn, Cabinets, MdmReg and WebDav input relocates 28 existing emitted OS
floors through four physical header patches. The two Wcn interface floors stay
direct annotations. The four FDI functions and eleven WebDav functions use
bounded same-floor scopes; MdmReg uses three scopes plus direct annotations to
avoid assigning floors to intervening, previously unannotated functions.

Cabinets also relocates the existing unscoped, nonflags `FDICREATE_CPU_TYPE`,
preserving signed 32-bit storage and member order/values `cpuUNKNOWN = -1`,
`cpu80286 = 0`, `cpu80386 = 1`. Native macros are restored after the metadata-only
enum declaration. `FDICreate.cpuType` remains native `int` plus its existing enum
association rather than a substituted native enum. The two exact declaration
expectations describe that representation change, not a new enum identity.

The recipe pins all ten owner-cluster headers to matching selected-SDK
preimages; only four are patched. Generated DLL mappings, callback identities,
SAL, ABI and unrelated authored settings stay unchanged. The adjacent manual
`RegisterDeviceDualEnrollMmpcUsingAADDeviceCredentials` import row has no
declaration in these selected headers and remains explicitly unbound rather than
being recreated. Global native field-array inference remains absent/default-off.

The private handoff is bounded patch-production evidence, not a final full-image grade.
Artifacts under `artifacts\parallel-small-api-migration` separate unmodified
parser activation, isolated owner controls and combined-recipe preparation.
Its private combined recipe prepared and reused its immutable cache successfully.
Bounded native and scraper controls used only these four patches because its
historical inherited patches still referenced `_Windows_SupportedOS_*`.
The owning integration now inherits qualified `c5879a77`/`43af342a` and applies
the canonical spelling overlay to its inherited patches. The private handoff
does not qualify the combined owning recipe or its physical include closure.

The source controls separately check OS targets/payloads, their qualified
attribute spelling/order and removal of an unused versioning import. Four
`FDIDECRYPT` anonymous-record `NativeTypeName` coordinates move by one line
after the new include; that attribute is not emitted into the winmd. These
source details are not additional authored facts or a full-image grade.

Broad physical closure, final OLD/control/NEW images and exact-head full-SDK CI
remain integration-owner gates after ordered tooling/pilot adoption. Consumer
compatibility remains **UNVERIFIED**.

## Combined canonical image local grade

The ordered owning inputs through Proc_Snap/Monitor/IdentityProvider are emitted
from two independent, unfiltered SDK scrapes at
`92fdfdc45ba7cd35b34ecc8e55034ce3eb78575b`: 321 actual owners and 393 scan legs
each. Their 813 generated C# files and eight discovery response files match
byte-for-byte. After the generic constant-alias correction and namespace
preservation, committed tooling/configuration
`89a2ad02cda4f6eee30d639bf8707cf3902d594c` re-emits separate hash-bound copies
without a frozen OLD source overlay. This is source reuse after emitter changes,
not a claim that a new scrape ran at that tooling commit.

| Local image | SHA256 |
| --- | --- |
| Canonical full SDK | `B1F987EA8E7B78A6DA30480FD72B08B397464B1C601301B3A951EE3B7D3842CC` |
| Independent canonical repeat | `9437ADC219899CE777E6856A01F9AC685ED7DFC2DADA5FBAC9E2A2FD35DE7725` |
| Matched frozen OLD tooling control | `26B5BCBB4914575956788D47E77C2E9CF9540A231D9537673F1D4DBB5428696A` |

Both full images have 37,310 physical types, 247,659 fields, 70,740 methods and
152,513 attributes. Their physical snapshots are literally identical without
reviewed-change normalization. All 7,791 enum identities, member order, values,
underlying types and flags remain unchanged, including the retained
`System.Power.POWER_PLATFORM_ROLE_VERSION` namespace. The control differs from
OLD only in the 39 known constructor instance-bit corrections.

The exact declaration grade preserves all original 117 expectations and adds
320 measured entries, with zero unknown or unused differences:

| Classification | Exact declaration entries |
| --- | ---: |
| Previously reviewed enum uses, native MIDL retval capture and preserved result | 117 |
| 140 further native-type/AssociatedEnum sites | 280 |
| Native `DhcpEnumSubnets.EnumInfo` In/Out contract | 1 |
| Native signatures at 23 exact handle-use sites | 23 |
| Eight producer lifecycle targets, three retained-type lifecycle removals and four fabricated typedef removals | 15 |
| Genuine native `WER_SUBMIT_DISCARD_IF_QUEUED` constant | 1 |

The removed fabricated types are the two Bluetooth search handles and
`HREPORT`/`HREPORTSTORE`. Their exact signatures retain native `IntPtr`,
`Void*` and corresponding output pointer levels rather than imposing a uniform
handle representation. Every relocated producer keeps its complete authored
cleanup and invalid-value set `[-1,0]`; borrowed inputs gain no ownership.
`WEB_SOCKET_HANDLE`, `FH_SERVICE_PIPE_HANDLE` and `HPSSWALK` retain their
structural identities. `HPSS` remains invalid-only because `PssFreeSnapshot`
requires both process and snapshot handles, not a unary cleanup.

The WER addition is the existing macro alias in `WerApi.h:294` to
`WER_SUBMIT_NO_QUEUE` at line 284: UInt32, value 128, all three architectures.
Its 14-member unscoped UInt32/Flags logical enum remains unchanged.
`AF_BTH` remains UInt16/value 32 and `HIDP_STATUS_I8242_TRANS_UNKNOWN` remains
the same native NTSTATUS/Int32 bit pattern `0xC0110009`. Their field-table position
adjustments name only these two static literals; every other field's order, type,
value, attributes and layout in those two mixed-field API holders remains
strictly graded. Existing API-only literal-row-order handling is unchanged;
instance and enum field order remains strict.

Each full image passes all 76 actual physical/no-fallback/mutation cases without
skips. The primary image passes all 14 SDK integrity cases against the complete
fresh 1,179-file scratch set, including all 393 scan diagnostics. The first
combined test invocation's three wrong-namespace Restart Manager lookups and
overbroad DHCP fallback assertion are preserved as failed evidence; the tests
are corrected rather than changing metadata or removing the held DHCP row.

Native field inference remains absent/default-off; the rejected 563-field image
is not admitted. The exact `DHCP_IP_ARRAY::Elements` CountParamIndex=0 sidecar
and the held DWM storage override remain. Root `7ea6c85d` is not implicitly
inherited. These local receipts do not replace final-head CI and downloaded-image
qualification in the draft review report. Managed projection/source effects of
the native signatures, output ownership and newly captured native facts remain
**UNVERIFIED**; no consumer work is implied by producer equivalence.

### Bounded interop OS-floor input

The Eap, Media.DShow.Xml, Win32_Tile_Badge_Notif and wnv owners relocate ten
authored OS rows to five admitted post-MIDL headers:

| Owner | Native header | Exact existing OS targets |
| --- | --- | --- |
| Eap | `Raseapif.h`, `RrasCfg.h` | Five `RasEap*` provider exports and `IEAPProviderConfig`: Windows 2000 |
| Media.DShow.Xml | `amxmlgraphbuilder.h` | `IXMLGraphBuilder`: Windows 2000 |
| Win32_Tile_Badge_Notif | `NotificationActivationCallback.h` | `INotificationActivationCallback`: Windows 10 build 10240 |
| wnv | `wnvapi.h` | `WnvOpen`, `WnvRequestNotification`: Server 2012 |

Two scopes cover only the seven existing function declarations. The three COM
interfaces keep direct annotations; no method, nested type, forward declaration
or neighboring interface acquires a floor. `Media.DShow` directly includes
`amxmlgraphbuilder.h` and remains an unconverted native-control dependent.

The five Eap provider exports exist in the selected native SDK but have no
fixed DLL import: their implementations are supplied by registered third-party
Eap DLLs. Their authored floors move faithfully to those declarations without
inventing an import or adding methods to the winmd. They are not five additional
emitted APIs. Shared `NCRYPT_KEY_HANDLE` ownership/invalid-value facts, shared
`NgcTicketContext`, the `IKsPropertySet`/`_DL_EUI48` parser exclusions, SDK-scanned
Wnv imports and documentation mappings remain unchanged and separately owned.

`InteropOsHeaderMigrationTests` reuses the existing cleaner and native ABI
controls. Set `INTEROP_OS_SOURCE_CONTROLS` to the bounded artifact directory
containing `legacy`, `activation` and `prepared` three-architecture scrapes,
`INTEROP_OS_OLD_GENERATED` to the original OLD generated-source directory, and
`WINHTTP_PREPARED_HEADERS` to the private prepared include root. The source
controls check exact OS targets/payloads and declarations against original OLD,
parser-only activation and prepared headers with no authored OS fallback.
They enumerate the two Wnv anonymous `NativeTypeName` coordinate changes
(`L64` to `L65`, `L97` to `L98`, both column 5) separately; the emitter does not
serialize `NativeTypeNameAttribute`. Native controls cover each owner and the
direct dependent on x86, x64 and ARM64. The existing native control honors the
partition's explicit C++ standard: `Media.DShow` requires its configured C++20
for the SDK's signed-shift constant expressions; the default remains C++17.

These are bounded source/component/native inputs to the combined full-SDK
migration, not a new OLD/control/NEW image, broad physical-closure grade,
consumer-compatibility claim or final-head CI acceptance. Those gates remain
with the combined migration integrator. `--nativeFieldArrayInfo` stays absent.

## Bounded full-SDK input: DirectML, Dedup, RemoteAssist and Wsb

This private input batch relocates twelve owned SupportedOS facts from
`supportedOS.rsp` into five post-MIDL header patches. Eight COM interface floors
and `DMLCreateDevice` use direct annotations. A Server 2012 scope covers exactly
the three adjacent native functions in `wsbonline.h`, not its preceding records
or typedefs. `DMLCreateDevice1` remains without an OS floor. The recipe admits all
ten cluster headers and enables annotation parsing only for these four owners;
neither the installed SDK nor `RecompiledIdlHeaders` is modified.

The unmodified-header activation control exposes three existing native
`[retval][out]` contracts on `IRendezvousSession`: `get_State.pSessionState`,
`get_RemoteUser.bstrUserName` and `get_Flags.pFlags`. Bounded component emission
captures exactly three `RetValAttribute` additions, with blob `01000000`, and no
other parameter flag or attribute changes. Prepared headers and this activation
control have identical physical snapshots across all 255 selected component
types on each of x86, x64 and ARM64. These are component images using frozen OLD
only for external references, not independent full-SDK images or an OLD-to-NEW
full-SDK acceptance claim. Ordinary native ABI controls cover all four owners
on all three architectures; anonymous `NativeTypeName` coordinate changes are
inventoried separately rather than allowed by the metadata comparison.

Three relocated Wsb function floors still have no physical methods: their
existing empty DLL mappings cause the emitter to omit them. No module is
guessed and no API is recreated. Shared COM/RPC declarations and their authored
floors remain outside this batch. The existing global `LocalSize` OS row also
continues to reach the two DirectML normalization descriptor fields; this shared
name collision is a central-review residual, not permission to edit the global
row or invent a field annotation. Dedup's `_DEDUP_SET_PARAM_TYPE` remap remains
parser configuration.

The private handoff pins the parent, payload, exact source/input preimages,
per-fact dispositions and bounded command/evidence receipts under ignored
`artifacts\sdk-component-migration`. The combined migration integrator owns
original OLD/control/NEW full images, broad physical/transitive closure,
final exact-head CI and downloaded-image qualification. Consumer compatibility
remains unverified.

## Resumed original-artifact preflight and source-blocked residuals

The selected SDK's generated banners and all 930 shipped IDL files were checked
before resuming authoring. Seven previously patched headers are MIDL-generated
but their owning IDL and interface declarations are not present in that SDK:
`iwscapi.h`, `winsatcominterfacei.h`, `locationapi.h`, `WcnDevice.h`,
`IdentityProvider.h`, `IdentityStore.h` and `rendezvoussession.h`.
A shipped generated header is a consumption artifact, not an authored C/C++
source merely because its filename ends in `.h`.

These seven migrations are **source-blocked**, not accepted header-only
migrations and not removed APIs. Their historical generated-header patches and
images remain immutable controls; the seven patches are removed from the active
recipe. Their exact existing legacy contracts remain: 26 availability rows,
three associations and the IdentityUpdateEvent flags setting. No declaration,
floor, native alias or replacement authoring source is invented. Natural SDK
SAL/MIDL facts may still be read from unchanged consumption headers; that does
not authorize annotating the generated files.

### Original-source request inventory

The following exact lookup targets were checked across all 930 IDL files in
SDK package `10.0.26100.7705`, include version `10.0.26100.0`. None of the
47 interface names or seven filename probes matched. The IDL filenames below
are search terms, not reconstructed source artifacts or proof of their original
authoring filenames. Use the shipped header and its interface names when
requesting the matching original SDK source; preserve its legacy metadata until
that source is available and qualified.

| Shipped generated header | IDL filename probe | Exact interface-name probes |
| --- | --- | --- |
| `um\iwscapi.h` | `iwscapi.idl` | `IWSCDefaultProduct`, `IWscProduct`, `IWscProduct2`, `IWscProduct3`, `IWSCProductList` |
| `um\winsatcominterfacei.h` | `winsatcominterfacei.idl` | `IAccessibleWinSAT`, `IInitiateWinSATAssessment`, `IProvideWinSATAssessmentInfo`, `IProvideWinSATResultsInfo`, `IProvideWinSATVisuals`, `IQueryAllWinSATAssessments`, `IQueryOEMWinSATCustomization`, `IQueryRecentWinSATAssessment`, `IWinSATInitiateEvents` |
| `um\locationapi.h` | `locationapi.idl` | `_ICivicAddressReportFactoryEvents`, `_ILatLongReportFactoryEvents`, `ICivicAddressReport`, `ICivicAddressReportFactory`, `IDefaultLocation`, `IDispCivicAddressReport`, `IDispLatLongReport`, `ILatLongReport`, `ILatLongReportFactory`, `ILocation`, `ILocationEvents`, `ILocationPower`, `ILocationReport`, `ILocationReportFactory` |
| `um\WcnDevice.h` | `WcnDevice.idl` | `IWCNConnectNotify`, `IWCNDevice` |
| `um\IdentityProvider.h` | `IdentityProvider.idl` | `AsyncIAssociatedIdentityProvider`, `AsyncIConnectedIdentityProvider`, `AsyncIIdentityAdvise`, `AsyncIIdentityAuthentication`, `AsyncIIdentityProvider`, `IAssociatedIdentityProvider`, `IConnectedIdentityProvider`, `IIdentityAdvise`, `IIdentityAuthentication`, `IIdentityProvider` |
| `um\IdentityStore.h` | `IdentityStore.idl` | `AsyncIIdentityStore`, `AsyncIIdentityStoreEx`, `IIdentityStore`, `IIdentityStoreEx` |
| `um\rendezvoussession.h` | `rendezvoussession.idl` | `DRendezvousSessionEvents`, `IRendezvousApplication`, `IRendezvousSession` |

### Independent original-artifact batches

The first independent original-header authoring inputs are `wscapi.h` and
`wcmapi.h`, with their three and five existing availability targets. SecurityCenter
remains a mixed owner: authored Wsc functions do not imply admission of its
source-blocked IWsc interfaces. Original-IDL drafts for RadialControllerInterop,
ddpbackup, NotificationActivationCallback and wsbapp reuse grouped interface
carriers and ordinary SAL includes, without copying declarations or adding a
per-API annotation-header include.

`SourceBlockedArtifactsRetainEveryLegacyPhysicalFact` checks the retained facts
on x86, x64 and ARM64: all 26 original availability values, all three association
values and their unchanged native signatures/parameter flags, and the complete
IdentityUpdateEvent enum including its Flags payload. This also covers the mixed
SecurityCenter owner; admitting authored Wsc functions must not discard IWsc
metadata. These checks do not suppress independently captured native retval facts.

These are source classifications and bounded authoring inputs only. Updated
qualified tooling, common native/MIDL SAL bootstrap, measured input/including-IDL
closure, actual native/MIDL output checks, fresh source/image grading and final
current-head CI remain required. No historical 437-row expectation or physical
normalization is an admission waiver for the resumed work.

## Bounded original-artifact qualification after paired inheritance

Local source checkpoint `2978a7fe20df7cceb156a519c0215fae89d6ce5f` ordinary-merges
the qualified pilot `4d276d050137a8239ba24c17de797128bd887ae6`, including qualified
root `afdb1fe7d6e14d8247b9d87498887fcd7eeed92c`. The shared SAL bootstrap and helper
remain inherited, not independently rewritten. The canonical recipe contains
13 pilot patches plus 50 original-artifact drafts. This records source coverage,
**not 50 admissions**. Both distinct fresh canonical preparations prove the same
51 actual inputs, 16 regenerated outputs and 3,443 byte-identical prepared headers.
Those receipts bind the checkpoint's exact patch inputs, before the later WNet
declaration-order correction.

The first bounded qualification uses `wcmapi.h` and four original IDL streams.
The IDL controls use matched pristine and patched private recipes with exactly
37 inputs and eight outputs, including the inherited property including-IDL
closure. All 24 pinned MIDL commands execute on x86, x64 and ARM64; their 12
matched pairs preserve all 39 actually produced proxy/IID/dlldata/TLB files
byte-for-byte. A TLB is counted only where MIDL actually produces it.

| Original IDL | Actual inputs, pristine to patched, per architecture | Unchanged warning contexts per pair | Relocated interface floors |
| --- | --- | ---: | --- |
| `RadialControllerInterop.idl` | 9 to 12 | 7 | Two at `windows10.0.14393` |
| `ddpbackup.idl` | 25 to 28 | 1,150 | Two at `windowsserver2012` |
| `NotificationActivationCallback.idl` | 11 to 14 | 501 | One at `windows10.0.10240` |
| `wsbapp.idl` | 25 to 28 | 1,154 | Three at `windowsserver2008` |

Raw logs, saved preprocessor streams, actual input/tool hashes and commands are
retained. Diagnostic file/code/context multisets are compared structurally;
raw diagnostic text is not rewritten. The existing libclang AST surface controls
pass all 48 C++/CINTERFACE metadata-off/on cases and all 12 plain-C metadata-off
cases, with positive native/SAL coverage and exactly the eight interface facts.
These are real libclang ABI/SAL observations, not claims of MSVC object-code
equivalence or a fresh plain-C metadata-on qualification.

Ordinary selected scrapes and distinct fresh repeats produce four literally
identical IDL-owner sources and the identical Wcm source. Complete images use
824 unmodified actual pilot-archive C# inputs, replacing only those fresh selected
sources; they never copy an emitter-mutated generated tree or rewrite generated
C#. The emitter settings are frozen from the qualified pilot.

| Bounded local image | SHA256 |
| --- | --- |
| Wcm only | `815BD72AC97A6C6FC6B015B146451BA5C7C57B31285FA08CB362E7E062C6ED45` |
| First four original IDLs plus Wcm | `AF76A701D55E5DEA6E878E33FB7466A848FA988FCE5DDF72415B96B26884DC4A` |

Both images have zero unfiltered API differences against the actual qualified
pilot image `E284F31134B8AD8740A78386890A5AE102B2B674B7F3BC7B799EC387DC4408F5`.
The first-IDL image also has zero against the Wcm-only image. Its 13 physical
cases preserve all 37,314 type snapshots literally, all eight IDL interface
floors, five Wcm floors, 119 pilot floors and the 30 source-blocked residual
units on every architecture; all 14 standard integrity cases pass. The Wcm-only
image separately passes ten physical cases and the same 14 integrity cases.
The raw root comparison remains exactly the inherited 54 enum-use rows, with
SHA256 `64575A4777A9FF54AB10EC96545228C9356377324F83B5B42C6CCF27F7D27F2F`.
The immutable same-SDK OLD comparison remains exactly the inherited 203 rows,
with SHA256 `E6B27077C636425307FFEB779F1517A9C18A70BD770809CB7259781B14264ED6`.
There is no new native-fidelity delta, expected-difference file, physical
normalization or historical 437-row allowance.

**Native admission and current-head CI remain outstanding.** Wcm's pinned
native controls retain 15 passes and three inherited plain-C metadata-on
failures: the qualified pilot's association carrier spells the native C tag as
`VARENUM` instead of `enum VARENUM`. The minimal six-case, two-include-order
witness is retained outside the checkout and has been delivered to the pilot
owner. Its published correction is not inherited until the exact final
actual-artifact qualification arrives; neither the helper nor pilot source is
patched independently here. The first-IDL C metadata-on leg must likewise be
completed against that accepted correction before final admission.

WNet has a separate source dependency. Moving its unchanged eight-enum block
before first use fixes declaration order, but metadata-on compilation still
needs the complete existing `WIN32_ERROR` group. The actual qualified root
contains 3,378 members: 3,288 from original `WinError.h` and 90 from original
`SetupAPI.h`. The preliminary uppercase-only source count of 3,376 missed
`ERROR_ITERATED_DATA_EXCEEDS_64k` and `ERROR_AUTODATASEG_EXCEEDS_64k`.
A partial group, placeholder, forward declaration or inclusion of all SetupAPI
is not a solution. Only this admission is held for the owning global-source
resolution; independent original-source work continues. The seven unavailable
original-IDL artifacts and all their legacy facts remain source-blocked.

### Disjoint authored-header controls

The next local batch adds only the existing `MDMRegistration.h` and
`amxmlgraphbuilder.h` original-header drafts. The eleven MdmReg function floors
remain `windows8.1`; the `IXMLGraphBuilder` interface floor remains `windows5.0`.
Both real including partitions, `Media.DShow` and `Media.DShow.Xml`, are exercised
and freshly scraped. No generated header or pilot-owned source is patched.

Two distinct fresh preparations have identity
`004AABF185DD7B7BB408D983A8000B9C01DDD5569110BB3763D60A8A83BA91F9`
and 3,443 literally identical prepared files. All 37 actual MIDL input bindings,
tools and eight regenerated headers match the preceding first-IDL control
exactly. Its three-architecture native-output evidence is explicitly reused
under that unchanged-input binding, not relabeled a fresh native MIDL run.

All 18 C++ metadata-off/on libclang controls pass on x86, x64 and ARM64.
MdmReg preserves 54 native facts and 381 SAL attributes; each XML context
preserves four native facts and its genuinely empty own-header SAL set. The
control requires that set to remain empty rather than inventing SAL contracts.
Expected metadata payloads are ordered by their complete literal strings,
including the separator after prefix-related function names.

The three ordinary selected scrape outputs match their distinct fresh repeats.
The cumulative complete image has SHA256
`4F8BE2B61C27D113282791039D4119F7E2EA637BFA4F83764BFD8DAF56C02817`.
It replaces eight selected C# files in freshly materialized actual pilot sources,
without modifying their bytes. Unfiltered comparisons against both actual
`E284...` and the preceding `AF76...` control are zero. All 37,314 physical types
remain literal matches; 16 physical cases cover the twelve new targets and all
earlier bounded/pilot/source-blocked facts, and all 14 standard integrity cases
pass with no skips. The root 54-row and same-SDK OLD 203-row logs retain the exact
hashes above. These are local controls, not current-head CI or a waiver of the
inherited C metadata-on gate. No consumer compatibility claim is made.

### Corrected bootstrap and the second original-IDL control

The exact qualified C-enum correction `e263bb3bcadcb0da5915e18caf91d1b69250cd88`
is ordinary-merged in local checkpoint
`c2d142988ad6898987ea8c54b0bab501eb902449`. Both immutable qualification receipts
and actual CI image `7C1175B3...` are independently rehashed. The explicit Wcm
matrix now passes all 18 cases, including its three former C metadata-on failures.
All eight original-IDL owners pass 144 C/C++/CINTERFACE, architecture and off/on
cases. The authored Mdm/XML and property controls pass another 60 cases, including
plain-C Mdm coverage and both property include orders. All have zero skips.
These controls bind root `afdb...` and the unchanged `082E...` helper; the separate
qualified logical-group tooling release is not silently included in them.

The second original-IDL group uses the previously measured original SDK inputs,
not another transport investigation. Fresh matched controls enforce exactly
47 used inputs and 12 regenerated headers. All 24 actual three-architecture
MIDL commands preserve 48 proxy/IID/dlldata/TLB outputs byte-for-byte.

| Original IDL | Actual inputs, pristine to patched | Unchanged warning contexts per architecture | Interface floors |
| --- | --- | ---: | ---: |
| `IContact.idl` | 25 to 28 | 1,193 | 5 |
| `FhCfg.idl` | 36 to 36 | 2,652 | 4 |
| `netlistmgr.idl` | 25 to 28 | 1,204 | 12 |
| `msrdc.idl` | 25 to 28 | 1,139 | 17 |

All twelve cumulative selected sources match distinct fresh normal-scrape
repeats. The three actual `e263...` CI source archives are retained independently;
a fresh complete replay of their 824 C# inputs has image SHA256
`33042E79ECAD2130568C7FAF1176F218078B92BF29C3D64D62C899DDEB75BAB1`
and zero unfiltered differences against actual `7C1175B3...`.
The initial twelve-source image `35C49CBD...` instead reports eight untouched
raw rows, SHA256
`E6FA73C5B9D86191912540C360880A75D90BE0193979E203CBCE7D1DB035CFD3`.
Those rows have two distinct dispositions, not a difference allowance.

Seven rows lose existing `windows8.0` FhSvcCtl function floors: a whole
FileHistory partition cannot be admitted from the FhCfg IDL patch alone.
Its coupled authored `FhSvcCtl.h` draft must carry all seven floors and the
existing producer-only cleanup facts. A single native probe identified that
the cleanup annotation references `FhServiceClosePipe` before its original
declaration. The complete existing ClosePipe declaration block is moved before
OpenPipe, with deprecation, SAL, guards and the Windows8 range retained. Its
original block SHA256 is
`AE94DE35B3FB96D9F11FD51D56E54D8AE060D4CC0921C3EE2B9DA88131767994`;
all bytes outside that exact block remain unchanged from the preceding draft.
No declaration, alias, helper, carrier or include is added.

The moved-header native matrix passes nine cases but retains three actual
plain-C metadata-on failures in the inherited pilot `avrfsdk.h` carrier:
`eAvrfResourceTypes` is a native enum tag, and the association omits `enum`.
The whole actual FileHistory input includes that header. Its failed matrix and
independent source witness are retained outside the checkout and routed to the
pilot owner; that artifact is not patched independently or bypassed here.
FileHistory admission remains held, without accepting the seven floor losses.

The eighth raw row is a source-backed addition:
`INetworkConnection2.IsDomainAuthenticatedBy::pValue` gains exactly one
`RetValAttribute`. Original `netlistmgr.idl` already declares `[ out, retval ]`
on `BOOL * pValue`, and the existing generated header carries `[retval][out]`.
All three physical architecture cases preserve sequence 2, raw CLI `Out` flags,
the unset CLI `Retval` bit and the entire HRESULT/parameter signature; the new
custom-attribute payload is exactly `01000000`. Managed consumer effects remain
unmeasured. It is not suppressed to preserve the older reader's omission.

The full literal per-site image grade, source-backed cleanup relocation and
own current-head CI remain required. The seven unavailable original-IDL
artifacts and all 30 legacy residual units remain untouched.

### Disjoint original-IDL image with the qualified logical-group tooling

Exact qualified root `217cda9c335e10ce9b3c902423ff468ce901f549` is
ordinary-merged at `6df2ed791700b7dcaec1552496fb1623ed5c1f82`, retaining
the accepted `e263...` correction and the unchanged `082E...` helper.
The reconciled tools build; 306 permanent annotation/source controls and
70 emitter controls pass. The one optional component fixture remains explicitly
unprovided, not counted as coverage.

The complete frozen `e263...` replay is materialized again from its three
actual CI archives, not a post-emission directory. All 830 consumed files,
including 824 C# files, are rehashed before emission. The owning merged tooling,
including the unpublished alias prototype distinguished below, produces
`329CF9F02B6F65B45424E432738352F5C5FEEDEA8D4B126F6EB1F00201584E95`,
with unfiltered API-zero against actual `7C1175B3...`.

The independent second-batch owners are IContact, Nla and Rdc: their five,
twelve and seventeen interface floors are qualified separately from the held
whole FileHistory owner. Their current native C/C++/CINTERFACE, three-architecture
and metadata-off/on matrix passes all 54 cases without skips. Their previously
executed 18 actual MIDL commands, nine matched pairs and 36 unchanged native
outputs are retained as source-bound reuse, not relabeled current-tooling MIDL
replays. The shared 47-input/12-output preparation does not admit FileHistory.

All eleven cumulative selected sources match fresh normal-scrape repeats under
the newly inherited tooling. The complete bounded image is
`FE8B37D57A5DEFEFFF32E2779F06D64BC92F974D4D578CD0AF3A9BAEC143D913`.
Its unmodified raw comparison reports only the native Nla parameter addition,
SHA256 `4DCE34EFBCF4FF9232C977935C8790A7E58BFBFA0C4B6AE95AC465379EF1F7A1`.
All 37,314 physical type snapshots compare literally: the only changed row is
`INetworkConnection2.IsDomainAuthenticatedBy::pValue`, from
`P|2|pValue|Out||` to
`P|2|pValue|Out||Windows.Win32.Foundation.Metadata.RetValAttribute:01000000`.
The architecture-specific CLI flags and full signature checks also pass.

All 24 exact physical/source cases and 14 standard integrity cases pass without
skips, including the 119 pilot floors and all 30 source-blocked residual units.
The complete FileHistory source remains actual-parent bytes, SHA256
`EFCE728DADDED0B408187EA2D8E7ADDD71FA00AF5A98150241E3B730777BD053`;
its preserved floors are not credited as a FileHistory migration.
The earlier raw-eight result and both native failures remain retained evidence.
FileHistory's inherited Avrf C-on correction, its producer-cleanup relocation
and this owner's exact-current-head production CI admission remain separate
gates. No difference file, raw/snapshot normalization or constant-order
allowance is used.

### Complete original error owners: full constants-stage blocker

The complete `WIN32_ERROR` source candidate contributes 3,288 names from
original `shared\winerror.h` and 90 from original `um\SetupAPI.h`, including
both lowercase `64k` spellings. Both owners opt into the existing parser;
the global namespace remains `Windows.Win32.Foundation`. The legacy
definition is removed. That checkpoint retained three method `addUsesTo`
sites but incorrectly omitted the preexisting `NETINFOSTRUCT::dwStatus`
field use; the follow-up below restores it while WNet remains unadmitted.
No helper, alias, forward declaration or unrelated WNet include is introduced.

All 12 actual C/C++, three-architecture, metadata-off/on native controls
pass with unchanged native facts, SAL and diagnostics. Two transport
typedefs expose two distinct contributions; Clang also inherits the
byte-identical 3,288-name annotation onto the redeclaration. The initial
six enabled-case annotation-count assertion failures are retained, not
reported as native compiler failures. All eight opted-in Foundation/DevInst
source files match their fresh normal-scrape repeats.

The complete constants-stage replay retains all 1,577 actual CI traversal
rows, relocating only input roots. Its 1,568 existing inputs are hashed;
nine absent selected-SDK paths remain explicit and are handled by the
unchanged scraper's existing `File.Exists` behavior, not filtered from the
map or replaced with manufactured headers. With the qualified parent enum
definition, all 830 consumed files, including 824 C# files, reproduce
byte-for-byte after constants scraping. The fresh control image
`AFC3BE4A9D6C506B0AD4E8AA6129F3B10F62A8111D3F123AD97019BA3CFE8DE3`
is unfiltered API-zero against both actual `7C1175B3...` and replay
`329CF9F0...`. Its 12 physical/source harness controls pass without skips;
these are control-only results.

With both original-owner contributions and only the scoped definition/use
and namespace changes, the normal complete emission fails with 43
`CS0266` errors: 42 WNet constant declarations and one Printing declaration
use enum-valued expressions as primitive `int`/`uint` constants. Examples
are native `WN_SUCCESS = NO_ERROR`, `WN_NOT_SUPPORTED = ERROR_NOT_SUPPORTED`
and `ERROR_BIDI_NOT_SUPPORTED = ERROR_NOT_SUPPORTED`. The unmodified log
has SHA256
`2CAEB43D893FB6FE39AB887003ECA0274C1EE1961ED385B12F0FB648FB3252B6`.
The normal constants output and processed compiler inputs are retained.

This bounded repro blocks the two-original-header source admission and
WNet; it does not justify restoring the legacy definition, adding casts
to native headers, changing enum membership, suppressing native aliases,
or editing generated production output. There is no candidate winmd, so
candidate physical membership/value/flags, raw API and declaration-order
grades remain unverified. The known source-group declaration-order
difference remains a separate strict gate, with no normalization or
allowance. Other original-source batches remain independent.

The retained 43-error witness uses the owning tree's preexisting private
enum-alias prototype, not the unmodified qualified `217c...` emitter.
An independent root-tooling replay of the same 836 frozen candidate inputs
reports 49 errors: those exact 43 plus `DS_S_SUCCESS`,
`DNS_STATUS_PACKET_UNSECURE`, `SCARD_S_SUCCESS`, `RPC_X_SS_CONTEXT_MISMATCH`,
`RPC_X_INVALID_BUFFER` and `RPC_X_PIPE_APP_MEMORY`. The six-error boundary
does not change the original witness. That 58-line prototype remains
unpublished and must be superseded by the exact qualified generic root
replacement before publication; neither the pending root implementation
nor this owning candidate is admitted by focused tests alone. Shared
tooling remains owned by the root layer, and its forthcoming qualification
does not waive this layer's original-source or declaration-order gates.

### Whole FileHistory after the qualified native-C correction

Exact released pilot `3767ccd6f10c9b1a4af717bb660cb964a620519b`, including
qualified root `217c...`, is ordinary-merged at
`7dc92ae373a28be82687e5110c5bf1bebc4ab64a`. The released receipts and actual
CI image `1E1AC98A...` are independently rehashed; its unfiltered comparison
against actual `7C1175B3...` is zero. Both `enum VARENUM` carriers and helper
`082E...` remain unchanged. The sole inherited production correction is
the original `avrfsdk.h` association's native `enum eAvrfResourceTypes`
spelling, not a new alias, generated-header edit or tooling workaround.

Fresh bounded preparation identity
`D1A8EFF6AC7845E4AABCC3AAE4C6AF4103EAD010AA706C0489342D453F9B15B5`
uses 25 exact current patches, 47 actual MIDL inputs and 12 regenerated
headers. It excludes the two held global error-owner contributions.
The approved moved `FhSvcCtl.h` bytes reproduce SHA256
`8170172E4D6F515E77430E9D4ACAD3EFB41A9E40F31228EA258A7704DDD53864`.
No ClosePipe declaration is duplicated or synthesized.

The actual owning FileHistory C17/C++, three-architecture, metadata-off/on
matrix now passes all 12 cases, including the three retained inherited
C-on failures. These are libclang native ABI/SAL/diagnostic controls,
not a claim of an MSVC object-code compilation. They preserve every native
fact and the exact SAL/diagnostic multisets, expose all seven Windows8
function floors and the one OpenPipe producer annotation, and require no
unknown or unused annotation. The same run passes six owning Avrf C17
controls and 24 Mdm/XML including-context controls: 42 passes, zero skips.
The separate matched-pristine FhCfg C17/C++/CINTERFACE matrix passes all
18 cases with its four exact interface floors.

The six previously executed actual FhCfg MIDL commands remain explicitly
unchanged-source reuse, not a fresh merged-head all-architecture RPC replay.
All 36 inputs per command, tools, raw logs and preprocessed streams are
rehashed. All three matched pairs preserve four proxy/IID/dlldata/TLB
outputs each. Every one of 2,652 file/code/full warning contexts per
architecture remains literal; 2,617 retain their original source line,
while the 35 FhCfg warnings move exactly six lines after the one SAL
include, four interface-annotation lines and separating blank line.
Original line numbers and raw logs remain recorded rather than rewritten.

The fresh normal FileHistory scrape and its distinct repeat produce one
literal matching `common\FileHistory.cs`, SHA256
`F0C3EDD05D86A629E9728B94BB8223B42EE2B907E1FB5CE101EC6C41E2BBE629`.
All seven selected auxiliary remap/pointer/header inputs also match literally.
The independent complete constants control again reproduces all 830
actual parent inputs, including 824 C# files, byte-for-byte. Both complete
image materializations retain all 1,577 traversal rows and the nine
explicit absent selected-SDK paths. The candidate combines only the
eleven previously qualified disjoint sources and this whole FileHistory
source. Its private frozen-parent autoTypes selection removes only
FileHistory's type-level cleanup/invalid values, so a global cleanup fact
cannot mask a missing producer annotation. No production legacy enum is
restored, and the held global source group is not smuggled into this batch.

The fresh complete control is
`C57B89E2A93B04A06F63384F2E3465C0AD302BFE78C3943FD6C712573DF9161A`;
its untouched raw comparison against actual `1E1AC98A...` is zero.
The complete bounded candidate is
`33B82E6FF050ED9020B03DFF62285ACB0BDACEB97773990CDF314388E8019066`.
Against either that actual pilot or the fresh control it has exactly three
raw rows, SHA256
`6A72488AEB1930FC0BEB17FE3F493006628D5A51CC770BD42BF34FEE0C55247E`:
the unchanged native Nla RetVal addition, the existing cleanup/invalid
values moving onto `FhServiceOpenPipe::Pipe`, and their removal from the
global `FH_SERVICE_PIPE_HANDLE` type. Against the disjoint `FE8B37D5...`
image only the latter two rows remain, SHA256
`747B04B12CC53067650E763A4AAFC93630A38B9A5BC4F5AEEE286301688509D4`.
The unfiltered same-SDK OLD comparison retains all 206 rows; no difference
file or normalization is used.

All 37,314 physical type snapshots are compared literally: 37,311 remain
identical. The three changed physical owners are the Nla interface,
FileHistory Apis and the FileHistory handle. Exact per-architecture checks
preserve all eleven FileHistory floors, every signature/import/CLI flag,
the native handle's layout/fields/methods/nonownership attributes and the
cleanup function's matching handle argument. Exactly OpenPipe's sequence-2
Out parameter receives the existing three ownership attributes; every
nonproducer remains free of them and the global handle loses exactly those
facts. The original ClosePipe/OpenPipe source move also changes their
physical method order. That exact swap is measured and asserted, with all
other method blocks literal; the API comparer alone does not report it.
No enum or method order is sorted away. Managed projection effects of the
lifecycle relocation and method ordering remain unmeasured.

The final 32 whole-batch physical/source cases, one retained-disjoint
literal regression and 14 standard integrity cases pass without skips.
The earlier regression invocation omitted its required OLD fixture and
skipped; that invocation is retained as noncoverage, and the fully supplied
invocation actually passes. The standard bin fixture is restored to its
original hash. Together with the 60 fresh native cases above these are
bounded local controls, not a claim of current-head production CI or of
qualification for the private alias prototype. That prototype stays
unpublished pending its exact qualified generic replacement.

The earlier raw-eight and native failures remain evidence. All seven lost
floors are now physically retained, and the Nla CLI Retval bit remains
unset; neither was waived. The native Nla custom-attribute addition and
unmeasured consumer effects remain explicit and separate. Global
WinError/SetupAPI/WNet admission, its declaration-order gate and this
owner's eventual current-head production CI remain held independently.

### Existing WNet residual and original RPC alias contracts

The two-original-header batch must retain all four preexisting
`WIN32_ERROR` uses: `GetLastError::return`, `SetLastError::dwErrCode`,
`SetLastErrorEx::dwErrCode` and `NETINFOSTRUCT::dwStatus`. The production
residual and a new bounded frozen-parent configuration now retain the
fourth use. This is preservation of an existing fact until WNet qualifies,
not a new API sidecar fact, legacy group restoration or WNet admission.
The original three-use configuration and 43-error witness remain unchanged,
including original input SHA256 `78A42334...`. The follow-up input changes
only that one use and has SHA256
`E2F66BB20844A4C34E5DF2D079E255666A1CA55F0005C230DB79595FBF340829`.

The permanent physical residual check now requires the entire
`NETINFOSTRUCT` snapshot to remain literal and its `dwStatus` field to
remain `Windows.Win32.Foundation.WIN32_ERROR` in all three architectures.
Seven source, physical and literal-order harness controls actually pass on
the complete `C57B89E2...` control image. Independently applying the updated
harness to the supplied `216650FB...` candidate metadata produces exactly
six expected failures: three expose that field's loss to `UInt32`, and
three expose the changed group declaration order. Those are retained
negative results, not passes or a waiver. The pending root's code is not
inherited or executed; its image is used only as negative metadata data.

The supplied generic-root candidate and repeat emit all frozen inputs but
remain unadmitted. Their untouched 50-row report has SHA256
`9498293B4FB88B48E87B0C5EDCDD5BAB9C6596137505831A795BDBD118132932`:
46 added loose aliases, three existing RPC alias type/value changes and
the missing WNet field residual. The supplied physical grade, independently
rehashed as `FEDB8EC8...`, records equal facts for all 3,378 group members
and all 49 aliases matching their candidate-declared scalar types/targets,
with no absorption. Neither establishes baseline or native-source
equivalence. Its 3,377 changed group field positions and 37,212 of 37,314
changed type positions remain explicit, with no normalization or admission.
The follow-up configuration has not yet been emitted with qualified
replacement tooling.

The three RPC macros in original `shared\rpcnterr.h` select distinct
user and `_KRPCENV_` branches:

| Original macro | Native user branch | Native kernel branch / old Int32 value | Candidate UInt32 value |
| --- | --- | --- | --- |
| `RPC_X_SS_CONTEXT_MISMATCH` | `ERROR_INVALID_HANDLE`, `6L` | `RPC_NT_SS_CONTEXT_MISMATCH`, `-1073545211` | `6` |
| `RPC_X_INVALID_BUFFER` | `ERROR_INVALID_USER_BUFFER`, `1784L` | `STATUS_INVALID_BUFFER_SIZE`, `-1073741306` | `1784` |
| `RPC_X_PIPE_APP_MEMORY` | `ERROR_OUTOFMEMORY`, `14L` | `STATUS_NO_MEMORY`, `-1073741801` | `14` |

A permanent actual-source libclang control now asserts each macro's exact
value and signed 32-bit Windows `LONG` type in both branches, for C17/C++17,
all three architectures and metadata off/on: 24 cases pass without skips,
each compiling original and prepared SDK contexts. The narrow probe uses
the actual selected `ntdef.h`, `winerror.h`, `ntstatus.h` and `rpcnterr.h`;
it introduces no declarations, header casts, substitute headers or new
API shapes. The first broader Windows-including probe is retained
separately: its 12 user cases passed and its 12 kernel cases could not find
the unrelated WDK `ntddk.h` dependency. The narrow SDK macro-branch witness
is not a complete WDK kernel-program or MSVC object-code compilation.

The candidate values match the native user branch, while the old values
match the native kernel branch. Both native branches are signed `LONG`;
the candidate's `UInt32` representation is therefore a separate,
unresolved representation/source-selection disposition, not a consequence
of the checked alias conversion alone. These measured native facts do not
choose one global projection for both branches or approve that type change.
The 46 loose additions, three RPC changes, missing-field correction and
declaration ordering stay separate from fact relocation. Their consumer
effects remain unmeasured. The private alias prototype remains unpublished,
and, at this source checkpoint, neither pending root `d8262ba4...` nor the
complete original-source dependency is admitted by these controls.

The existing `ConstantsScraper.GetForcedTypeForName` deliberately represents
`ERROR_*` as `uint` regardless of native signedness. Its symbolic-alias path
inherits the referenced constant's represented type. That preexisting
projection policy explains the candidate's unsigned representation; the
generic checked alias lowering does not select it. This explanation does
not waive the three existing RPC API type/value changes or establish
native signedness equality.

#### WNet source-majority continuation

The original `um\winnetwk.h` and `um\Npapi.h` patches now use compact,
source-backed carriers for all twelve existing logical groups and their
55 members. Native macro values, DWORD storage and flag semantics are
retained. `RESOURCEUSAGE_NONE` remains the preexisting metadata-only zero
member, not a newly invented native macro. Exact existing flag-definition
blocks and the `WNetCloseEnum` declaration move before their typed
annotation uses; no native signature or SAL is changed.

The WNet field `NETINFOSTRUCT::dwStatus` now retains native DWORD storage
with `AssociatedEnum("WIN32_ERROR")`; its matching sidecar use is removed.
The exact remaining Foundation uses are `GetLastError::return`,
`SetLastError::dwErrCode` and `SetLastErrorEx::dwErrCode`. The earlier
four-use and literal-field snapshot gates above describe historical
evidence, not a requirement to retain direct enum storage after this
source migration. Logical member values, storage, flags and association
identity remain checked; incidental synthetic declaration order does not.

The actual selected user-mode RPC branch supplies signed LONG values
`6`, `1784` and `14` for `RPC_X_SS_CONTEXT_MISMATCH`,
`RPC_X_INVALID_BUFFER` and `RPC_X_PIPE_APP_MEMORY`. Those replace the
historical kernel-branch values separately from annotation relocation.
Three exact `=int` emitter remaps remain temporary parser/type-projection
debt: the constants scraper's symbolic-alias path otherwise inherits
unsigned `ERROR_*` storage and bypasses `--with-type`. No shared parser is
forked. The 46 previously reported source-backed loose scalar additions
remain additions, not new logical-group members or automatic blockers.

The private continuation has 41 passing focused native/source controls,
including C/C++, x86/x64/ARM64 and metadata off/on. The RPC fixture now
uses the real Windows and Winternl type context rather than mixing
`ntdef.h` with `winnt.h`. A bounded emit of the actual selected WNet and
Foundation constant sources, using the accepted frozen dependency image,
also passes six metadata controls: 65 DLL bindings, 57 floors, two
last-error imports, 75 emitted associations, twelve groups/55 exact
members and the three exact signed user-branch RPC values. These are
focused checks, not a full-SDK image, combined API grade, current-head CI
or consumer qualification; consumer compatibility remains **UNVERIFIED**.

#### Native network bulk source pass

The first two reserved bulk batches add **38 distinct original-header
patches**, not 39: `rpcproxy.h` has 36 retained, unbound facts and no
authored patch. The source-bound pass relocates exactly 2,267
SupportedOS rows and 304 SetLastError rows into 2,571 annotation
placements. Removing just those inserted annotation lines restores all
38 original native files byte-for-byte. The sidecar set difference is
exactly those 2,571 rows, with no unrelated additions or removals.

The initial draft also inserted 28 partial markers for retained facts:
18 SupportedOS and ten SetLastError markers in `clusapi.h`, `http.h`,
`mprapi.h`, `resapi.h`, `windns.h` and `winsock2.h`. Those markers are
removed using their original AST declaration offsets; their exact legacy
rows remain. Incomplete facts stay entirely legacy, matching the shared
mapper's corrected all-or-legacy behavior. This does not undo any of the
2,571 completed fact relocations or reduce the 38-header source count.

This is a source majority, not complete annotation migration for those
headers. There are 128 explicitly retained mapper facts and 41 additional
queue availability references outside the initial free-function owner
map; the latter include macros, helpers, aliases and two C++ interfaces.
Their original sidecar facts remain. The queue also retains 475
other-category row references: 12 synthetic-group definitions, 172
explicit members, 213 direct enum uses, 73 declaration overrides, two
associated-enum uses, two invalid-handle values and one cleanup API.
These are configuration references, not counts of unique APIs or new
annotation-vocabulary gaps. They are not counted as converted by the
availability/error-only mapper.

Focused ordinary native controls pass for all 17 selected partition
closures on x86/x64/ARM64, in 51 cases. The stock metadata-enabled source
scrape uses one consistent private native recipe. Complete image/API
grading, production CI and consumer qualification remain central gates;
this source commit does not claim those outcomes.

#### Reserved native continuation

The next 25 reserved originals produce **21 additional header patches**.
Exactly 285 SupportedOS rows and 80 SetLastError rows move to 365 direct
source placements. All 21 native files restore byte-for-byte after removing
only those marker lines; no signature, macro value, enum or native storage
is changed.

`d2d1helper.h`, `d2d1_1.h`, `d2d1_1helper.h` and
`traceloggingprovider.h` have no safe authored prefix and are not counted.
The pass retains 83 availability facts for ambiguous identities,
macro/non-global declarations and unbound declarations or references.
None receives a partial source annotation. The complete queue adds no
further OS/error references outside this report. Another 101 configuration
references remain unchanged: 50 direct enum uses, four synthetic groups,
30 explicit members, nine declaration overrides, one enum association,
five invalid-handle values and two cleanup APIs.

In particular, the three Foundation error-group uses remain explicit
cleanup debt even though `errhandlingapi.h` now has availability/error
prefixes. This batch does not silently change their association identity
or the temporary RPC value/type disposition above. Complete SDK/API/CI
and consumer qualification remain separate central gates.

#### Reserved following native batch

A further 25 reserved originals yield **18 actual header patches** with
57 SupportedOS and ten SetLastError relocations. The 67 placements are
direct declaration facts, not blanket header defaults. Native bytes,
signatures and all other sidecar categories are preserved.

Seven originals have no safe patch and receive no header credit:
`rometadataresolution.h`, `traceloggingactivity.h`, `atlthunk.h`,
`gdiplusimagecodec.h`, `msdrm.h`, `ntlsa.h` and `timeprov.h`.
The 28 retained floors comprise nine unsupported shared-line declarations,
twelve facts without a configured owning partition, six without a parsed
declaration and one with an additional unparsed reference. None receives
a partial source marker or a parser-only partition admission.

No additional OS/error queue references are omitted from that report.
The one cleanup API, one direct enum use and one invalid-handle-value
configuration reference remain unchanged. The broad native source total
is 77 distinct new original-header patches across these four batches;
the preexisting WNet/Npapi corrections are not counted again.

### Third original-IDL batch: actual preparation and native-output controls

The next bounded batch uses only the already-authored original
`callobj.idl`, `EventSys.idl`, `amsi.idl` and `RrasCfg.idl` patches. It must
retain 25 interface floors, seven function floors and the exact
`IEnumEventObject::Reset` result target. The matched pristine and patched
stock preparations contain 3,443 headers, 51 actual IDL inputs and 16
generated headers each. Exactly the four owning generated headers differ.
Their identities are `FB515DAF...` and `863639EE...`; this matched pair is
not a fresh repeat of the patched preparation.

All 24 actual MIDL commands for the four owners, three architectures and
two variants succeeded. The 39 actually produced RPC/IID/dlldata/TLB
outputs compare byte-for-byte across the 12 pairs. All 8,751 full warning
contexts and literal source-token lines remain equal: 8,292 retain their
line, nine move by five lines and 450 move by 17 lines. Original
coordinates, raw logs, commands, saved preprocess streams and output hashes
are retained. The first missing-header-binding recipe rejection occurred
before any MIDL execution and remains separate failed evidence.

The extended existing native C17/C++17/CINTERFACE and metadata-off/on
matrix actually ran 216 cases: 210 passed and six failed. All six failures
were the C AMSI context on the pristine header, before a before/after
comparison: the native-surface harness did not register the unnamed union
type that has a named `RequestType` field. The union is already present in
the original IDL/header. The harness now recognizes the same anonymous
type-location spelling it already compares, retaining strict declaration
identity lookup and all layout/type facts. No SDK source, native cast or
metadata expectation changes for that correction. The original six
failures remain evidence; a fresh native rerun, normal source first/repeat,
physical result-target check, complete image and owning current-head CI
remain required before admission.

### Released generic scalar-alias tooling inheritance

Ordinary inheritance now uses exact qualified root
`d8262ba4751dbf637f3a860071e1ca344fd5adc7`, tree
`311d2e49b2d4d8b59d27f4e76419ed5947ab55c7`, not a floating tooling tip.
The released receipt `A21430FC...` and all 18 bound evidence files were
independently rehashed here. The five exact-source CI jobs are successful;
the actual image artifact `12102643644` independently hashes to
`A4A49BE868156249E0A59609E8D8B64333BFD59682B0C9A80B9D5C98E1A9B133`.
The existing unfiltered comparer independently reproduces raw API-zero
against both actual `945C75BD...` and `46990689...`, and the unchanged
54-row pilot report with SHA256 `64575A47...` against actual `1E1AC98A...`.

Only the supplied private alias-prototype hunks are superseded: the
namespace/name/architecture reference reconstruction, callback plumbing and
unchecked identifier-alias block. The qualified post-compilation
`HeaderEnumGroupMerger.ConvertPrimitiveConstantAliases` implementation and
call remain intact, as do the existing owning tests, native-field-array
opt-in plumbing and other source changes. This clears the shared tooling
execution dependency, not original-source admission. Fresh source emissions
must use the corrected `E2F66BB2...` four-use configuration. The original
43/49-error, 50-row, RPC representation/branch and literal-order evidence
remains unchanged and unwaived; WNet remains independently held.

The first merged regression run retains seven private-prototype expectation
failures and one missing optional ServiceApi fixture: six native-enum
fixtures had expected implicit unchecked scalar aliases, and one had
expected a namespace-reconstruction exception. These are not header-group
fixtures. The qualified replacement intentionally leaves native enums and
unbound identifiers to the compiler. The owning tests now preserve the
exact native flag-enum member order/values/storage/attributes and signed
enum value in a successful physical image, and separately require both
original unbound scalar aliases to remain `CS0103` errors. Both
namespace/ambiguity cases likewise retain the compiler error rather than
expecting private reconstruction. The qualified logical-group positive,
checked-overflow and unrelated-error cases remain unchanged. No shared
tooling, native declaration or production scalar type changes for this
test correction; the failed run remains evidence.

The exact ordinarily merged `40b5c82a...` native replay then passes all
216 original-IDL cases without skips: 144 retained cases and 72 for the
four new owners. The successful test binary and native-test source are
preserved separately from later test-only edits. A genuinely fresh
same-patched preparation in a distinct root reproduces all 3,443 header
entries literally. The normal stock four-owner source scrape and its
independent repeat also produce four byte-identical C# files; no generated
source is repaired or rewritten.

The corrected applicable annotation suite actually passes 316 cases,
including the six native-enum physical/rejection cases, both
namespace/ambiguity negatives and 32 unchanged qualified logical-group
cases. The existing emitter and utility suites pass 70 and 40 cases,
respectively, all without skips. The optional ServiceApi image fixture
is explicitly not selected, rather than counted as native coverage. The
intermediate negative-fixture invocation omitted the same standard
metadata source copied by the existing `Emit` helper; that invocation is
retained, and the corrected fixture supplies it before compilation.
These remain bounded local controls, not complete-image or production-CI
admission for the four original IDLs or the held global source batch.

### Corrected four-use frozen execution with the qualified root

The corrected `E2F66BB2...` four-use configuration now runs through the
actual ConstantsScraper and complete emitter with the inherited qualified
tooling. This is explicitly the immutable original `750E...` header
context, not fresh owning-head header traversal or source admission.
Control has 832 frozen inputs, including 824 C# files; candidate and
independent repeat each have 836 inputs, including 828 C# files. Fresh
constants execution changes only `enumsRemap.rsp` relative to the original
candidate. All 1,577 frozen traversal rows were rechecked, including the
nine originally absent paths.

The complete images are control `D10F4503...`, candidate `3A7AF78D...`
and repeat `2B125C6E...`. Unfiltered control-to-candidate and
control-to-repeat each have exactly 49 rows, byte-identical with SHA256
`A055EBDC231FD754B14365EC343529A41FD961FC607DBF63AFA3CCFC6D1C8DC2`;
candidate-to-repeat is raw-zero. The prior 50-row report remains
unchanged. The removed row is specifically the unintended
`NETINFOSTRUCT.dwStatus` enum-use loss, not an alias or value allowance.
All 3,378 named group members, storage, values, flags and type facts,
plus all three method uses and that existing field use, pass physical
readback on all three architectures.

The 49 changed scalar declarations are physically retained without
absorption: 44 are UInt32 and five are Int32. The latter are
`DS_S_SUCCESS`, `DNS_STATUS_PACKET_UNSECURE`, `SCARD_S_SUCCESS`,
`WN_SUCCESS` and `WN_NO_ERROR`; no blanket unsigned conversion is inferred.
All scalar facts, complete physical type sequences and complete group
field sequences are literal first/repeat matches. Full unsorted raw
sequences and scalar signatures/value blobs are retained in the evidence.
These measurements do not admit the 46 added APIs or the three existing
RPC changes: `RPC_X_SS_CONTEXT_MISMATCH` changes Int32 -1073545211 to
UInt32 6, `RPC_X_INVALID_BUFFER` changes Int32 -1073741306 to UInt32 1784,
and `RPC_X_PIPE_APP_MEMORY` changes Int32 -1073741801 to UInt32 14.
Permanent architecture-specific guards print every old/new raw scalar row
and continue to fail baseline equality.

Literal order remains a separate failed gate: 3,377 of 3,379 group field
positions, including the storage slot, differ. This corrected four-use
witness also has 37,214 changed physical type positions out of 37,314.
The earlier coordinator witness's 37,212 count is retained as its own
measurement, not overwritten or reused for this different execution.
The strengthened whole-image guard compares the original type sequence
before semantic snapshots. No ordering is normalized or allowed.
WNet, native branch/representation and complete original-header source
admission remain held; native signedness and consumer effects are not
claimed.

### Third original-IDL batch: bounded complete-image results

The four normal generated C# files and all five generated RSP files are
literal first/repeat matches. Each fresh emitter rule is present in the
complete frozen response-file closure: the 22 fixup rows match exactly,
and the 11 common pointer-reduction rows are present in each architecture's
complete response file. No generated source or rule is repaired.

The next bounded complete-image experiment rematerializes all 831 entries
of the retained whole-FileHistory source archive, including 824 C# files.
Candidate and repeat replace only the four complete normal outputs for
Com.CallObj, Com.Events, Antimalware and Eap. Their bounded emitter settings
remove only the existing
`IEnumEventObject::Reset=[CanReturnMultipleSuccessValues]` directive.
The held original WinError/SetupAPI source contributions are not included;
the unchanged frozen legacy group is private comparison context, not a
restored production definition.

Control `37B8AC8A...`, candidate `1D0E2188...` and repeat `CBF56327...`
are unfiltered raw API-zero against each other. The new control is also
raw-zero against the prior whole-FileHistory `33B82E6F...` image. Both
candidate and repeat pass all 37,314 literal physical type snapshots,
the original type and field declaration sequences, and complete ordered
method rows. All 25 interface and seven function availability targets
retain their exact versions on all three architectures.

The existing reviewed Reset check uses the original same-SDK
`1361407C...` OLD image: its signature and method flags are unchanged,
the CLI PreserveSig implementation flag is set, and the former success
custom attribute is absent without a replacement custom flag. The first
invocation incorrectly used the already-canonical `37B8AC8A...` tooling
control as OLD and retained three failed old-flag preconditions. Only the
fixture binding was corrected; neither source nor assertions changed.
The qualified emitter already canonicalizes the legacy directive, so
relocating this reviewed fact into the original IDL adds no new image
delta against the matched canonical control.

Each complete candidate passes seven targeted physical cases and all 14
existing integrity/interface cases without skips. These complete-image
results accompany the retained 216 native cases, actual MIDL/native-output
and warning-source controls, and fresh preparation/source repeats; they
do not claim a new native replay after test-only edits. The prior
FileHistory placement/floor negatives and Nla custom-RetVal physical audit
remain separate evidence. This is a locally verified four-owner source
checkpoint, not production admission of all authored drafts or the held
global source batch, and not owning current-head CI qualification.

### Four authored availability headers: original-source local results

The next disjoint cohort qualifies the existing patches on original SDK
`Wscapi.h`, `DirectML.h`, `wnvapi.h` and `wsbonline.h`. Its nine relocated
availability facts are the three Wsc functions, `DMLCreateDevice` at
`windows10.0.10240`, both Wnv functions, and the three online-backup functions.
`DMLCreateDevice1` remains without an availability floor. The online-backup
functions remain absent from metadata because their existing imports are
unmapped; no DLL mapping, declaration or replacement API is invented.

All nine facts now use fixed per-declaration macros. The earlier Wnv and
online-backup scope blocks are replaced by five existing
`_Win32_SupportedOS_Server2012_` annotations. Four permanent source guards
require the exact declaration counts and prohibit BEGIN/END scope transport
in this cohort. This avoids depending on the unimplemented file-local,
explicit/innermost scoped-default resolver; the canonical helper and shared
tooling remain unchanged.

The first strict inventory check retained a literal `Wscapi.h` to `wscapi.h`
path difference, despite Windows resolving both spellings. The source binding,
patch target and patch artifact now preserve the original SDK's `Wscapi`
spelling. The stock preparer's separate patch-filename rejection is also
retained. Original mixed patch-context line endings are preserved; only the
three patch-wrapper target spellings change. Neither paths nor declaration
order are normalized to make these checks pass.

The matched recipe has 37 header bindings and 29 pristine/33 patched source
patches. Pristine `504BC1E4...` explicitly reuses the byte-identical fresh
control from the preceding spelling preflight. Distinct final patched and
repeat preparations both identify as `5D3CBC46...`. All three actual
3,443-header trees were rehashed: the pristine tree equals the preceding
original-IDL control, exactly four original headers change, and all patched
and repeat paths and bytes match literally. Removing only the nine exact
inserted declaration-annotation lines reproduces every original SDK byte. The 51 MIDL
inputs, four tools and two scripts remain literal matches to the preceding
IDL cohort; this does not claim a new all-architecture MIDL/native replay.

The final exact-source native run passes 78 cases without skips: 42 new
SecurityCenter/DirectML/Wnv/Wsb controls and 36 retained MdmReg/DirectShow/XML/
FileHistory controls. They compare native ABI, SAL, diagnostics and exact
annotation sites on x86, x64 and ARM64, metadata off/on. The new headers are
checked as C17 and C++17 where supported; DirectML is C++ only. Existing
DirectShow standard selection remains unchanged. Earlier successful native
runs, spelling/format preflights and earlier scope-source controls remain
separately identified evidence, not substitutes for this final
explicit-declaration replay. Six source guards also pass without skips.

Fresh normal first/repeat traversals produce four C# files, five generated
RSP files and one header preamble, all literal matches. Their complete
function-pointer fixup file matches the frozen full configuration; all 13
normal common pointer reductions are present in each architecture's complete
rule set. All ten outputs also byte-match their retained scope-source
predecessors. No generated source or rule is repaired.

Complete images rematerialize the exact 831-entry third-IDL source archive
(824 C# inputs), replacing only those four complete normal C# outputs.
Control `7279E5A3...` is the explicitly reused actual image, previously
unfiltered raw API-zero against the preceding `1D0E2188...` image.
Fresh candidate `BD8EA0A8...` and independent repeat `7CC277D4...` each
have exactly the same 16 untouched raw difference rows,
SHA256 `EEEEC8409DADD43282B6D4C42AE33F9EE2895EE97BC4FCD68355F0488E378112`.
Candidate to repeat is raw-zero. Earlier scope-source images `900AC677...`
and `AF8AA892...` remain retained; `900AC677...` to the new explicit-floor
candidate is also unfiltered raw-zero. All other owners and constants remain
explicit frozen context; the held WinError/SetupAPI contributions are not
included or restored to production.

These 16 additions faithfully capture existing `[retval][out]` comments in
the unchanged shipped `iwscapi.h` consumption header. They are source-backed
additions, not availability relocation or new annotation vocabulary, and
their native-source policy was already reviewed. Each image passes thirteen
physical/source cases without skips: all 37,314 physical type snapshots and
literal type/field/method sequences, exactly six emitted floors and three
unmapped omissions, and all 30 legacy facts for the seven missing-IDL
artifacts. All 16 exact parameter sites have one custom `RetValAttribute`
with blob `01000000`, unchanged method signatures/flags and parameter
sequences/Out flags, and an unset CLI `ParameterAttributes.Retval` bit on
all three architectures. The comparer spelling `[Out,RetVal]` alone is not
evidence of a CLI flag change. Consumer projection effects remain unmeasured.

Both images also pass all 14 existing integrity/interface/RAII tests without
skips. An initial 13-case class-filtered run omitted the existing RAII test;
its incomplete-selection failure is retained, and the complete suite was
rerun. The original shared binary fixture was restored byte-for-byte after
every run.

This raises bounded local resumed-original-artifact coverage to 20 of the
50 authored drafts: 12 original IDLs and eight authored headers, separately
from the 13 inherited pilot/bootstrap patch units and two held global
dependency patches. These are source-artifact/cohort counts, not complete
partition admissions or fresh replays of every earlier native witness.
Thirty authored-header drafts still await original-source qualification.
The seven missing-IDL migrations, WNet/RPC representation and literal-order
gates, excluded field-array activation and owning current-head production/CI
admission remain separate. Draft authoring and old green CI do not satisfy
those gates.

### Three authored service headers: original-source local results

The next bounded cohort qualifies original SDK `um\EvColl.h` (Wec),
`shared\tbs.h` (Tbs) and `um\davclnt.h` (WebDav). All three repository
preimages byte-match the selected shipped SDK headers; none is a generated
MIDL product. The 38 existing facts are 35 function floors, two explicit
last-error flags on `EcOpenSubscriptionEnum` and `EcOpenSubscription`, and
the `GetDeviceID` import from `tbs.dll`. These are relocations, not new
native facts, enum representations or ownership assertions.

EvColl and WebDav now use fixed per-declaration Vista macros instead of
scope blocks. Tbs's existing five Vista, three Windows 8 and one 17134
declaration floors and import annotation are unchanged. Three permanent
source guards require the exact 15/9/11 floor counts and reject scope
transport. No helper, reader, shared tooling, native declaration body or
declaration order is changed.

The initial EvColl authoring fixture lost trailing SDK whitespace and an
EOF blank line. Its exact original-byte check rejected it before any
production patch was generated. The original failed fixture and raw diff
are retained; only that formatting was restored. Removing precisely the
38 inserted CRLF annotation lines from the actual prepared headers now
reproduces every original SDK byte.

The stock bounded recipe preserves all preceding source context and adds
only these three bindings: 40 headers, 36 patches and 38 partitions.
Independent preparations both identify as `30785AE8...`. All 3,443 actual
headers in each preparation were rehashed against the manifests; literal
paths and independent repeat bytes match. The explicitly reused preceding
`5D3CBC46...` source tree differs only at these three original headers.
The 51 MIDL inputs, four tools and two scripts are unchanged; this does
not claim a fresh all-architecture native MIDL replay.

The fresh native subset passes all 36 C17/C++17, metadata-off/on,
x86/x64/ARM64 controls without skips. They preserve every measured native
ABI, SAL and diagnostic fact and require the exact 38 metadata sites when
enabled and none when disabled. The preceding 78 controls were not rerun
for this cohort. These are native compiler/AST controls, not target
runtime or consumer-projection measurements.

Fresh ordinary first/repeat owner traversals produce three complete C#
files, five generated RSP files and one preamble, all nine byte-identical.
All ten common pointer reductions are covered by each architecture's
complete frozen rules; the full function-pointer fixup file is literal.
The three raw discovery `.remaps` files are explicitly **not** byte-equal:
3,914 rows retain different absolute preparation origins, `p5a` versus
`p5b`. Every mapping identity, target, relative header spelling and raw
row position matches, and both actual origin files hash equally. The
original raw differences and every before/after row are retained. No
discovery output, source or raw report was rewritten to manufacture
literal equality.

The complete images preserve the preceding exact 831-entry input archive
(824 C# files), replacing only the three entire normal owner outputs.
All 828 other inputs and all frozen emitter configurations remain literal;
their owners and constants are not freshly traversed. Candidate
`7F0B12A1...` and independent repeat `4596A24E...` are each unfiltered
raw API-zero against preceding `BD8EA0A8...`, and against each other.
Both retain exactly the existing 16 native SecurityCenter custom-retval
rows against the older `7279E5A3...` control, byte-identical raw SHA256
`EEEEC8409DADD43282B6D4C42AE33F9EE2895EE97BC4FCD68355F0488E378112`.
The existing emitter `CSSW001` warning for WebAuthn/WinHttp.header-types
is retained, not suppressed.

Each real image passes eleven physical/source cases and all fourteen
existing integrity/interface/RAII cases without skips. These compare all
physical type snapshots and literal type/field/method sequences without
order normalization, preserve the 35 exact floors, both last-error flags,
the existing import, and all 30 legacy facts for the seven missing-IDL
artifacts. Both exact pre-emission ZIPs' membership and every entry byte
were independently rehashed after emission; processed `.modified.cs`
files are not archival inputs. The original shared binary fixture was
restored byte-for-byte after both image runs.

Source commit `19d581b7...` preserves the exact executed producer bytes;
later documentation-only qualification does not relabel these runs as
fresh. This raises local resumed-original-artifact coverage to 23 of 50:
12 original IDLs and eleven authored headers. Twenty-seven authored-header
drafts still await original-source qualification. ErrorRep remains coupled
to WerApi's normal owner traversal; no partial owner or new Wer native
failure is claimed here. The seven missing-IDL artifacts, held WNet/RPC
representation/branch and literal-order gates, excluded field-array
activation, and owning production/current-head CI admission remain
separate. The existing draft stack and published old head are unchanged.

## Sixth authored-header cohort: NetBios and NetShell

This bounded cohort qualifies original SDK `um\nb30.h` (NetBios) and
`um\NetSh.h` (NetShell), not generated MIDL consumption headers. Their
repository preimages byte-match the selected shipped SDK originals.
The nine existing facts are the Windows 2000 floor on `Netbios` and
eight Windows XP floors on `MatchEnumTag`, `MatchToken`,
`PreprocessCommand`, `PrintError`, `PrintMessageFromModule`,
`PrintMessage`, `RegisterContext` and `RegisterHelper`. NetSh now uses
fixed per-declaration macros instead of scope transport; nb30's existing
declaration macro is unchanged. These are relocations, with no new native
facts, enum representations, ownership assertions or native body changes.

The stock bounded recipe has 42 header bindings, 38 patches and 40
partitions. Independent fresh preparations both identify as
`854FD92D...`. All 3,443 actual headers in each were independently
rehashed, with identical literal paths and bytes. Compared with the
explicitly reused service preparation `30785AE8...`, only these two
original headers differ. Removing precisely their nine inserted CRLF
annotation lines reproduces every original SDK byte.

All 51 MIDL input, four tool and two script bindings remain literal,
and the actual selected tool/script bytes were rehashed. This does not
claim a fresh all-architecture native MIDL replay. A stronger attempted
whole-MIDL-evidence-directory equality assertion failed and is retained,
not waived as byte equality: the independent directories each contain
174 files, of which 158 are literal and 16 generated `.log` files differ.
Both complete inventories and all untouched raw differences are retained;
the consumed prepared headers were independently verified equal.

The fresh native subset passes exactly 24 C17/C++17, metadata-off/on,
x86/x64/ARM64 compiler/AST controls without skips. They preserve every
measured native ABI, SAL and diagnostic fact, require the exact nine
metadata sites when enabled and none when disabled, and explicitly
verify nb30's empty original SAL set. The preceding 114 native cases
were not rerun. No target-runtime or consumer-projection effect is
claimed.

An initial common-only owner assumption was rejected before image
assembly. The actual stock `crossarch` closure is three complete
architecture-specific `NetBios.cs` files and one common `NetShell.cs`;
both separate owner constants files remain frozen. Fresh ordinary
first/repeat traversals produce these four C# files, five RSP files and
one preamble, all ten byte-identical. A separate rejected pointer-proof
assumption required every name in each architecture RSP individually.
The actual emitter consumes all three complete frozen RSPs into one
unqualified reduction set. All 22 normal reduction names are covered by
that actual union; no rule or configuration was added or repaired, and
the full function-pointer fixup file is literal.

The four raw scratch `.remaps` files are explicitly **not** byte-equal:
5,233 rows retain different absolute preparation origins, `p6a` versus
`p6b`. Every mapping prefix, target, relative header spelling and row
position matches, and both actual referenced headers hash equally.
Every before/after row and untouched raw diff is retained. No discovery
output, source or report was rewritten to claim normalized equality.

Source commit `51f4c022...` preserves the exact executed producer bytes.
Native, preparation and normal-traversal commands ran before that commit
on identical source bytes, not in a newly checked-out committed tree.
Both complete images were actually emitted at the committed producer:
candidate `FC3B4A51...` and independent repeat `B4645AC4...`.
Each preserves the preceding exact 831-entry archive (824 C# files),
overlays only the four entire normal header files, and keeps all 827
other inputs and frozen configurations literal. Those other owners and
constants are not freshly traversed.

Both images are unfiltered raw API-zero against qualified service
`7F0B12A1...` and against each other; service repeat `4596A24E...` also
compares raw-zero to the candidate. Each retains exactly the existing
16 native SecurityCenter custom-retval rows against `7279E5A3...`,
with untouched raw SHA256
`EEEEC8409DADD43282B6D4C42AE33F9EE2895EE97BC4FCD68355F0488E378112`.
The existing `CSSW001` WebAuthn/WinHttp.header-types warning remains
explicit. Both exact input ZIPs preserve baseline entry membership,
case and order; all 1,662 extracted entry bytes were independently
rehashed. Processed `.modified.cs` files are not archival inputs.

Each actual image passes thirteen physical/source cases and the entire
fourteen-case integrity/interface/RAII suite without skips. These
preserve all physical type snapshots and literal type/field/method
sequences, all nine exact floors across three architectures, and all
30 legacy facts for the seven missing-IDL artifacts. The original shared
binary fixture was restored byte-for-byte.

Local resumed-original-artifact coverage is now **25 of 50**: twelve
original IDLs and thirteen authored headers, nine more headers than at
`12279c76...`. The other 25 header drafts remain outside these qualified
cohorts; draft authoring is not source admission. WebSock/Cabinets and
other deferred owner preflights are not claimed to have compiler
failures merely because they have not been qualified. The seven
missing-IDL artifacts, WNet/RPC's 49 raw rows and representation/branch
and literal-order gates, excluded field-array activation, and owning
production/current-head CI/publication remain separate. No reviewed
branch, stack membership, merge state or consumer code is changed.

## Seventh authored-header cohort: Monitor

This cohort qualifies the three original SDK headers
`um\lowlevelmonitorconfigurationapi.h`,
`um\highlevelmonitorconfigurationapi.h` and
`um\physicalmonitorenumerationapi.h`. Their repository preimages
byte-match the selected shipped SDK originals. The normal owning
partition is `Monitor`, whose complete translation unit also includes
the unchanged generated consumption header `cloneviewhelper.h`. That
header is neither an authoring source nor a partial replacement owner.

The three patches now use fixed per-declaration Vista macros, not scope
transport. They relocate exactly 32 existing floors and 26 existing
last-error facts. Six deliberate last-error omissions remain on
`SetVCPFeature`, `GetMonitorCapabilities`,
`SetMonitorRedGreenOrBlueDrive`, `SetMonitorRedGreenOrBlueGain`,
`GetNumberOfPhysicalMonitorsFromIDirect3DDevice9` and
`GetPhysicalMonitorsFromIDirect3DDevice9`. No enum, association,
ownership assertion or new native fact was added. Removing precisely
the 58 inserted CRLF annotation lines reproduces every original SDK
byte, including declaration order.

The initial authoring diff used ambient autocrlf and lost native CRLF
hunk contexts. This was caught before actual preparation. Both initial
diffs and the corrected transport are retained; the effective recipe
binding supersedes the historical preflight patch hashes. Each actual
production patch was independently applied strictly to its original
fixture and reproduced the exact authored bytes. No native source
change was needed to correct patch transport.

The ordinary bounded recipe has 45 header bindings, 41 patches and 41
partitions. Both independent fresh preparations identify as
`6F1E3968...`. All 3,443 actual headers in each were independently
rehashed with literal paths and bytes. Against the explicitly reused
network preparation `854FD92D...`, exactly these three original headers
differ. The 51 MIDL input, four tool and two script bindings are literal;
the selected tool/script bytes were rehashed. The independent MIDL
evidence directories each contain 174 files: 158 literal files and 16
different generated logs, with both full inventories and all untouched
raw differences retained. This is not whole-evidence-directory
equality or a fresh all-architecture native MIDL replay.

Exactly 36 fresh C17/C++17, metadata-off/on, x86/x64/ARM64 compiler/AST
cases pass without skips, using the complete actual Monitor translation
unit. They preserve the measured native ABI, SAL and diagnostic facts
and require the exact selected-header metadata when enabled and none
when disabled. The preceding 138 native cases were not rerun. An initial
prior-control invocation omitted the required OLD fixture and produced
one optional skip; its exact-count guard rejected that result. The
retained corrected invocation supplies every fixture and passes eight
source guards plus three actual prior-control architecture cases.

Fresh stock first/repeat traversals produce the entire common
`Monitor.cs`, five RSP files and one preamble: seven literal files.
All ten normal pointer-reduction names are covered by the actual union
of the three complete frozen architecture RSPs; the complete global
function-pointer fixups remain literal. The raw scratch remap file is
not byte-equal: 1,469 rows retain independent absolute preparation
origins. Mapping prefixes, targets, relative header spelling, positions
and actual referenced header bytes match. Every raw row and untouched
diff remains available without normalization or source repair.

Source commit `5dd0e8cf...` preserves the exact executed source bytes.
Native, preparation and normal-traversal commands ran precommit on
identical source, not in a freshly checked-out committed tree. Both
complete images were actually emitted at that committed producer:
candidate `7E8A1453...` and independent repeat `F182C554...`. Each
preserves an exact 831-entry archive containing 824 C# files, overlays
only the entire normal `common\Monitor.cs`, including unchanged
cloneviewhelper output, and keeps all 830 other inputs and full frozen
configurations literal. The separate display constants remain frozen;
other owners and constants were not freshly traversed.

Both images compare unfiltered raw API-zero to qualified network
`FC3B4A51...` and to each other; network repeat `B4645AC4...` also
compares raw-zero to the candidate. Against historical `7279E5A3...`,
each retains exactly the existing 16 native SecurityCenter custom-retval
rows, byte-identical SHA256
`EEEEC8409DADD43282B6D4C42AE33F9EE2895EE97BC4FCD68355F0488E378112`.
These are custom metadata, not a CLI Retval-bit claim. An initial
validation assertion incorrectly expected positive 1 for differences;
the existing comparer returns -1. That rejected assertion and its
already byte-correct raw report are retained; only the exit-code proxy
was corrected. No difference was suppressed or normalized.

Both images pass sixteen actual physical/source cases and the entire
fourteen-case integrity/interface/RAII suite without skips. These
preserve all physical type snapshots and literal type/field/method
sequences, all 32 exact floors, 26 last-error flags and six omissions
across three architectures, and all 30 legacy facts for the seven
missing-IDL artifacts. The original shared binary fixture was restored
byte-for-byte. All 1,662 input ZIP entries were independently rehashed
with original membership, case and order. Processed `.modified.cs`
files are not archival inputs. The existing `CSSW001`
WebAuthn/WinHttp.header-types warning remains explicit.

Local resumed-original-artifact coverage is **28 of 50**: twelve
original IDLs and sixteen authored headers, twelve more headers than at
`12279c76...`. The other 22 header drafts remain outside these
qualified cohorts. The seven missing-IDL artifacts and their 30
retained legacy facts, WNet/RPC's 49 raw rows and representation/branch
and literal-order gates, excluded field-array activation, and owning
production/current-head CI/publication are still separate. This local
cohort neither changes those dispositions nor claims consumer effects
or a PR merge.

### Next bounded native gate: Eap and DeviceQuery remain unadmitted

The next independent original-header controls select `Raseapif.h`
(Eap, alongside already-qualified original `RrasCfg.idl`) and
`devfiltertypes.h` (DeviceQuery). Raseapif now spells its five existing
Windows 2000 floors on the exact declarations rather than a scope.
These are third-party provider exports, not fixed-DLL imports; none
may be invented as new winmd methods. The existing DeviceQuery patch
is unchanged.

One fresh C17/C++17, metadata-off/on, three-architecture native run
executes 24 cases without skips. Eap passes all twelve. DeviceQuery
passes its six metadata-off controls but **fails all six metadata-on
controls**. The first exact native-fact mismatch is:

```text
original:         enum _DEVPROP_OPERATOR int
metadata enabled: enum _DEVPROP_OPERATOR unsigned int
```

The existing conditional `: unsigned int` in `devfiltertypes.h.patch`
therefore changes the measured native enum contract. The previous
qualified physical `Windows.Win32.Devices.DeviceQuery.DEVPROP_OPERATOR`
already has UInt32 storage. Three actual prior-control architecture
cases confirm that representation, the existing Eap interface floor
and the absence of invented provider imports. Preserving the old
physical representation is not proof that the unsigned native carrier
is faithful. The failing comparison stops at the first mismatch; it
does not establish equality of every other fact, a calling-ABI change,
or a consumer effect.

Strict actual production-patch round trips reproduce both authored
originals. Ordinary first/repeat preparation and whole-owner traversal
both succeed without warnings or errors at identity `80DC65DE...`.
All 3,443 actual headers in each preparation and all eight normal
generated files are literal between runs. That source success does
not override the native contradiction. Untouched scratch outputs
remain retained without a normalized-equality claim; no fresh
all-architecture native MIDL claim is made.

DeviceQuery is held for an explicit native/projection disposition after
this single bounded repro. No cast, native retyping, new annotation
vocabulary, shared-tooling change, weakened comparison or source repair
is selected. Eap has native evidence but has not completed its own
full-image qualification. Neither original increases the qualified
count above **28 of 50**, and no new complete image, current-head CI
or publication admission is claimed for this experiment.

### DeviceQuery original-native enum follow-up: measured, not admitted

The six original metadata-on failures remain sealed unchanged in the
`E731FA60...` receipt. One separately authorized bounded experiment
omits only the private `devfiltertypes.h.patch`, leaving the selected
SDK enum declaration byte-for-byte original (`2F37EFE3...`). The
production patch is not edited. The private recipe retains 47 selected
headers and 42 other patches.

The qualified root's `DEVPROP_OPERATOR=uint` setting was already absent
from the owning configuration before this experiment. Both actual
whole-owner traversals use that same configuration with zero active
overrides; no fresh one-line removal or import of different root
sidecar facts is claimed. No native casts, generated-source repair,
new vocabulary, aliases or shared-tooling changes are introduced.
The only test change adds native enum/value reporting after every
existing strict assertion.

Fresh actual DeviceQuery C17/C++17, metadata-off/on controls pass all
twelve three-architecture cases without skips. Every original and
prepared enum remains `enum _DEVPROP_OPERATOR int`. All 42 native
member values and 32-bit patterns are recorded for every before/after
case, including all repeated raw cursor occurrences. The actual
normal generated declaration is `public enum DEVPROP_OPERATOR`,
with implicit Int32 storage. It is not an assumed consequence of
removing a setting.

Both complete source traversals succeed without compiler errors.
All 3,443 prepared headers and all seven normal outputs are literal
between the independent runs at identity `3712A328...`; exactly
`um\devfiltertypes.h` differs from the held preparation, now matching
the SDK original. The untouched scratch files still differ at 1,312
source-origin lines; those raw differences are retained, not
normalized. No fresh all-architecture native MIDL claim is made.

The actual complete first/repeat images are `3E0301A2...` and
`7F060F4E...`, emitted at the reporting-only producer `136bb932...`.
Each uses 831 inputs, including 824 C# files, with only the entire
normal `common\DeviceQuery.cs` owner overlaid; 830 other inputs and all
full emitter configurations remain frozen. The frozen Eap source is
not a fresh Eap qualification. The first normal traversal predates
the reporting-only commit with identical production bytes; the repeat,
native matrix and both complete emissions actually execute at that
commit. Both pre-emission archives preserve literal membership, case
and entry order, with every entry independently rehashed.

Physical metadata measures **UInt32 to Int32**, not representation
equality. All 42 member constant type codes likewise change from
UInt32 to Int32. Forty numeric values remain equal; the two signed
values change as follows:

| Member | Prior UInt32 value | Native/candidate Int32 value | Unchanged 32-bit pattern |
| --- | ---: | ---: | --- |
| `DEVPROP_OPERATOR_MASK_NOT_LOGICAL` | 4027580415 | -267386881 | `0xF00FFFFF` |
| `DEVPROP_OPERATOR_MASK_ARRAY` | 4026531840 | -268435456 | `0xF0000000` |

Every member's four raw constant bytes and bit pattern remain equal.
All candidate physical values match the native signed values on every
case. Enum identity, all member names and positions, type/field flags
and custom-attribute blobs remain exact.

The unfiltered qualified-`7E8A1453...` comparisons each produce
**45 raw rows**, byte-identical at
`C97C86A14D02621DA989F4F23ACC5E5A4410E99E35253587C743806BECA11834`:
42 constant-type rows, one `value__` storage row and two numeric-value
rows. The historical `7279E5A3...` comparisons each retain 61 raw rows,
including the previously measured sixteen native custom-RetVal rows.
Actual candidate-to-repeat comparison is raw-zero. All 37,314 literal
type positions, 247,662 field positions, 70,740 method positions and
method signature bytes remain exact across the three images, without
sorting or normalization. The unchanged complete physical-snapshot
assertion also passes candidate-to-repeat.

Each image passes sixteen fixed-floor, prior-Monitor and missing-IDL
source/blocker controls, and all fourteen existing integrity/interface/
RAII cases, without skips. The shared `B1F987EA...` fixture is restored
byte-for-byte. The existing `CSSW001` warning remains explicit.
Conversely, all four unchanged OLD-representation assertions fail on
each image: three UInt32 shape cases and the complete OLD physical
snapshot comparison. Those eight failures remain explicit and
unwaived, with TRX error messages extracted as plain text. A separate
plain-text re-extraction also preserves the original six failures
without rewriting their sealed receipt.

This completes the bounded measurement, not DeviceQuery admission.
The native-fidelity improvement and the managed enum storage/value
changes require their separate representation disposition; actual
managed consumer effects remain unmeasured. Eap, WNet/RPC, the seven
missing-IDL blockers and other disjoint work keep their existing
grades. Qualified local coverage stays **28 of 50**; no owning
current-head CI, push, publication or PR merge is claimed.

### Independent Eap original-header qualification

The complete Eap owner now qualifies original `Raseapif.h` separately
from the held DeviceQuery experiment. Its five existing Windows 2000
floors are fixed on `RasEapGetInfo`, `RasEapFreeMemory`,
`RasEapInvokeInteractiveUI`, `RasEapInvokeConfigUI` and
`RasEapGetIdentity`. Removing exactly those five annotation lines from
the prepared header recovers every selected SDK byte and declaration
position. The original header hashes to `476F1B7A...`; the production
and private patches are literal at `B71349CE...`.

Both ordinary traversals, the fresh native controls and both complete
emissions execute at `13fe685609cfa947a274285712062968bba102c2`,
tree `455a89b0a3073c3b07fc59e8199906891c6e7ad8`. This qualification
does not propagate the private DeviceQuery original-enum candidate.
The recipe is exactly the previous eligible 47-header, 43-patch
recipe, with 42 eligible partitions, at preparation identity
`80DC65DE...`. All 3,443 actual prepared headers are independently
rehashed in each run and literal between runs.

Actual whole-owner C17/C++17, metadata-off/on controls pass all
twelve three-architecture cases without skips. Native declarations,
canonical types, layouts, calling conventions and SAL remain exact;
only the five supported-OS facts are added. Ordinary generated C#
retains all five Windows 5.0 annotations and the existing empty DLL
mappings. These are provider exports, not newly discovered fixed-DLL
imports: no library name, invented method or entrypoint is added to
the winmd. The already-qualified original `RrasCfg.idl` remains
whole-owner consumption context, not another newly counted original
or fresh all-architecture native MIDL claim.

All seven normal first/repeat outputs are literal. The complete raw
scratch differences retain 1,309 source-origin lines; no normalized
scratch equality is claimed. Both actual full images use 831 inputs,
including 824 C# files: only the entire normal `common\Eap.cs` is
overlaid, while 830 other inputs, constants and complete emitter
configurations remain frozen. Every selected pointer reduction is
present in the actual union of the three architecture response files.
Both pre-emission ZIPs retain membership, case, entry order and
independently rehashed bytes, rather than processed `.modified.cs`
files.

The actual first image is `C327A66FB43A7D72...` and the independently
emitted repeat is `DAD068A6F0ED1823...`. Each unfiltered comparison
against qualified `7E8A1453...` is raw-zero, as is first-to-repeat,
with exact report hash `9E2542A8...`. Each comparison from historical
`7279E5A3...` retains the same sixteen native custom-RetVal rows,
byte-for-byte at `EEEEC840...`; they are not suppressed or new Eap
deltas. Independent complete metadata extraction preserves all
37,314 type positions, 247,662 field positions, 70,740 method
positions and every method signature byte across all three images,
without sorting or normalization.

Each image passes twenty unchanged physical/source/blocker cases,
including every physical type snapshot and literal sequence, the
existing Eap interface floor and absence of invented imports, prior
Monitor contracts, fixed-floor source guards and all 30 legacy facts
for seven missing-IDL artifacts. Frozen DeviceQuery UInt32 shape is
preserved, not newly qualified from source. Each image also passes
the entire fourteen-case integrity/interface/RAII suite. Including
the fresh twelve-case native matrix, all **80 actual cases pass
without skips**. The shared `B1F987EA...` binary fixture is restored
byte-for-byte; the existing `CSSW001` warning remains explicit.

Local resumed-original-artifact coverage is now **29 of 50**:
twelve original IDLs and seventeen authored headers, thirteen more
original headers than at `12279c76...`. Twenty-one header drafts
remain outside the qualified cohorts. This is bounded original-source
and frozen-context full-image qualification, not owning production
integration, current-head CI, publication or measured consumer effects.
The DeviceQuery six native failures and separate Int32/45-row/eight-
failure measurement remain sealed and unadmitted. WNet/RPC's 49 raw
rows, native branch/value/type and literal-order gates, missing-IDL
originals, field-array exclusions and the other source blockers retain
their existing dispositions. No PR, branch or stack publication is
changed by this local cohort.

### DeviceQuery API-faithful Int32 target

The native Int32 representation is now the specifically authorized
DeviceQuery compatibility correction. Original `devfiltertypes.h`
declares `DEVPROP_FILTER_EXPRESSION.Operator` as `DEVPROP_OPERATOR`;
the six `DevCreateObjectQuery` variants and `DevGetObjects`/`Ex`
accept pointers to that expression. This operator is not the
separate ULONG `QueryFlags`. The documented UInt32 property operand
for bitwise operations does not redefine the operator enum's storage.
The original SDK and all three native targets establish signed
32-bit storage.

The unsigned-native-retyping patch and its recipe reference are
removed. The SDK header is unchanged, and the already-absent
`DEVPROP_OPERATOR=uint` override is not restored. No projection-only
annotation, native cast, alias, helper or shared-tooling feature is
introduced. The accepted compatibility boundary is exactly the
previously measured **45 raw rows**: 42 constant type codes and
`value__` storage change from UInt32 to Int32, while
`MASK_NOT_LOGICAL` becomes -267386881 and `MASK_ARRAY` becomes
-268435456. All 42 four-byte values, identities, order and flags
must remain unchanged.

Fresh acceptance requires that explicit Int32 target, the exact
42-member native value/bit-pattern vector, unchanged operator field
and eight filter-API signatures, and strict equality for every other
physical type and API. Whole-owner native controls now include
`devfiltertypes.h`, `devquery.h` and `devquerydef.h`, preserving the
full native/SAL contract. The original `E731FA60...` failures and
`BF8E6745...` measured negative receipt remain immutable historical
evidence; they are not rewritten as passing cases.

Corresponding committed-source preparation, complete-owner traversal
and full-image first/repeat qualification remain required before
counting DeviceQuery locally qualified. Until that evidence closes,
the ledger remains **29 of 50**. This decision does not change
WNet/RPC, other source blockers, consumer-effect grades, owning
current-head CI or publication.

### Qualified DeviceQuery original-native Int32 correction

The specifically authorized DeviceQuery correction now completes its
separate local original-source qualification. The actual source,
native matrix and both full emissions execute at
`2268ca770023aec7e87908ed8257112ba896093c`,
tree `4dd3e07ebc978e1ad43af504bf6e94f1b3f6288f`. The only
production change removes the unsigned-native-retyping patch and its
recipe reference. Original `devfiltertypes.h` remains byte-for-byte
the selected SDK at `2F37EFE3...`; no unsigned override, helper,
shared emitter change or generated-source repair is introduced.

Both independent ordinary traversals succeed without warnings or
errors, using fresh preparations at `3712A328...` with 47 selected
headers, 42 remaining patches and 42 eligible partitions. All 3,443
actual headers in each run are independently rehashed and literal
between runs. Relative to the previous Eap preparation, exactly
`um\devfiltertypes.h` changes, now matching the native SDK original.
All seven normal outputs repeat literally. The 1,321 raw differing
scratch lines remain retained without normalization. Constants and
previous all-architecture native MIDL evidence are frozen context,
not freshly rerun stages.

Fresh C17/C++17, metadata-off/on controls pass all twelve cases across
x86, x64 and arm64. Their complete selected-header surface includes
`devfiltertypes.h`, `devquery.h` and `devquerydef.h`, with unchanged
native declarations, canonical types, layouts, calling conventions,
SAL and diagnostics. Every native operator remains signed `int`.
All 42 member values and bit patterns match both before and after,
including every repeated raw cursor occurrence. Native and physical
measurements bind 1,008 distinct case/member comparisons and 3,024
raw member occurrences. The operator field and all eight filter-API
expression-pointer contracts are explicitly checked.

The actual complete images are `5032F47C...` and `AFE74DCD...`.
Each uses 831 pre-emission inputs, including 824 C# files, with only
the entire normal `common\DeviceQuery.cs` overlaid. All 830 unowned
inputs are literal to the **sealed qualified Eap `C327A66F...` source
archive**, including `common\Eap.cs` at `E31A1344...`; the older
`7E8A1453...` Eap source is not substituted. Full constants and all
emitter configurations remain frozen. All 1,662 archived entries
are independently rehashed, preserving original membership, case
and entry order rather than processed `.modified.cs` output.

The public compatibility change is confined to one existing enum:
`Windows.Win32.Devices.DeviceQuery.DEVPROP_OPERATOR` becomes Int32,
matching the native API's operator contract. All 42 literal constant
type codes become Int32. Forty numeric values are unchanged;
`MASK_NOT_LOGICAL` becomes -267386881 and `MASK_ARRAY` becomes
-268435456. Every member's four raw bytes, identity, position,
flags and custom attributes remain exact. The existing operator
field retains its enum type; neither it nor the separate QueryFlags
parameter is widened, narrowed or replaced with a different domain.
Actual downstream consumer behavior remains unmeasured.

Each unfiltered `C327A66F...` comparison reproduces the same
**45 raw rows**, byte-for-byte at `C97C86A1...`. Each historical
`7279E5A3...` comparison retains 61 rows at `E34258A1...`, including
the earlier sixteen native custom-RetVal rows. First-to-repeat and
the measured original-header variant-to-first comparisons are
raw-zero at `9E2542A8...`. No row is suppressed or normalized.
All 37,314 literal type positions, 247,662 field positions,
70,740 method positions and method signature bytes also remain
exact in this cohort.

Each image passes twenty-four explicit-target physical/API/source/
blocker cases and the entire fourteen-case integrity/interface/RAII
suite, without skips. With the twelve fresh native controls, all
**88 qualification cases pass without skips**; a separate committed
source guard also passes. Seven retained wrong-UInt32-target cases
all fail for the exact Int32/UInt32 mismatch, demonstrating that the
new target is required. The original six `E731FA60...` native
failures and eight `BF8E6745...` OLD-shape failures remain sealed,
not rewritten or reported as passing assertions. The shared
`B1F987EA...` fixture is restored literally; the existing `CSSW001`
warning remains explicit.

Local resumed-original-artifact coverage is now **30 of 50**:
twelve original IDLs and eighteen headers, fourteen more original
headers than at `12279c76...`. Twenty header drafts remain outside
these locally qualified cohorts. DeviceQuery is counted once as a
qualified original-source/native-enum correction, not as new
annotation vocabulary or another patch unit. This is not owning
full-production integration, current-head CI or publication.
No push, PR/stack mutation or merge is performed.

### Clarified enum-use and functional-equivalence boundaries

For continuing migration, choose enum storage from actual API
contracts rather than reproducing erroneous legacy storage. Preserve
each resolved `AssociatedEnum` target and placement independently of
the native parameter, return or field type. Width or signedness
disagreement is permitted by the documented advisory relationship;
it is not permission to retype native declarations, widen narrow
fields or pointers, or substitute an enum directly for an associated
primitive. The broader [#2371](https://github.com/microsoft/win32metadata/issues/2371)
cleanup is not a migration prerequisite.

The corrected four-use WIN32_ERROR witness preserves existing
enum-typed signatures: GetLastError's return, SetLastError's and
SetLastErrorEx's `dwErrCode`, and `NETINFOSTRUCT.dwStatus`. These
are not four physical AssociatedEnum blobs, and that witness does
not establish attribute parity.

Raw type-table positions and synthetic enum declaration order remain
diagnostics, not functional blockers by themselves. Keep the raw
reports and classify developer-visible changes by affected API/type
and cause. Native struct layout and field order, pointer widths and
COM/vtable method order remain strict. This clarification does not
dispose of WNet/RPC's actual branch/value/type questions or the
other independent source blockers.

### Bounded Dwm original-header continuation

The next independent cohort is the original selected SDK `dwmapi.h`.
Its source draft replaces the old scope carriers with 31 fixed
per-declaration floors: 23 Vista, three Windows 7, four Windows 8
and one build 17134. Both existing `DWMWINDOWATTRIBUTE` associations
remain on the DWORD `dwAttribute` parameters of
`DwmGetWindowAttribute` and `DwmSetWindowAttribute`. Their source
arguments use `enum DWMWINDOWATTRIBUTE`, following the existing
C/C++-compatible enum-tag qualification, not a native retyping.

The native `DWM_SHOWCONTACT` declaration and all seven members remain
original. Its API-facing use is the enum parameter of
`DwmShowContact`. Existing native-int controls and the normal scrape
will grade the representation against the clarified enum policy,
without requiring legacy UInt32 storage merely for OLD equality.
The UInt32 and Int32 paths remain explicit, exhaustive seven-member
targets rather than a blanket physical-type exclusion.

The authoritative frozen complete-image context is the sealed
DeviceQuery `380180E4...` receipt and its `5032F47C...` image/source
archive, retaining qualified DeviceQuery source `6670E513...` and
Eap source `E31A1344...`. This source draft does not itself count as
native/source/full-image/repeat qualification. Local qualified
coverage remains 30/50 until those independent gates finish; no
shared tooling, publication or PR/stack change is introduced.

### Qualified Dwm original-header cohort

The bounded Dwm continuation completes local original-source
qualification at actual producer
`3306320f718f90f833249d791869602196ec2ec1`,
tree `82d231e7f349ba9e73b1df724d0900bcdbc8e70d`. All 31 fixed
floors and both existing associations are preserved. Removing
only those 33 annotation sites recovers the selected original
SDK `CB7AA381...` literally, including native declarations,
enum members and their order. No native type, cast, alias,
handle, ownership assertion or new annotation vocabulary is authored.

Fresh preparations at `44E742DD...` contain 48 selected headers,
43 patches and 43 eligible partitions. Each actual 3,443-header
closure is independently rehashed and first/repeat literal; exactly
`um\dwmapi.h` changes relative to the qualified DeviceQuery
preparation. Both ordinary complete Dwm traversals succeed with
zero warnings/errors. All seven normal outputs repeat literally.
The 1,484 raw scratch line differences remain retained, not
normalized. Constants and prior native/MIDL preparation context
are frozen rather than freshly rerun stages.

The fresh whole-owner C17/C++17 metadata-off/on matrix passes all
twelve cases across x86, x64 and arm64 without skips. Native
declarations, calling conventions, types, layouts, SAL and
diagnostics remain exact. All 24 before/after vectors establish
signed `int` for the original `DWM_SHOWCONTACT`, and all 168
native/physical member comparisons match signed values and
four-byte patterns. The DWORD attribute parameters stay native
UInt32 despite their signed native enum association.

Actual complete images `D4FF3976...` and `F6F838BD...` each use
831 archived pre-emission inputs, including 824 C# files. Only
the entire normal `common\Dwm.cs` at `F3C81B4C...` is overlaid.
All 830 unowned inputs are literal to sealed DeviceQuery
`5032F47C...`, retaining DeviceQuery `6670E513...` and Eap
`E31A1344...`. All full emitter configurations/constants and the
actual three-architecture pointer-fixup union remain frozen;
all ten selected normal reductions are covered. Every one of
the 1,662 archived entries is independently rehashed with
membership, case and order preserved.

The one public representation correction is native/API-faithful
Int32 `DWM_SHOWCONTACT`: seven literal type codes and `value__`
become Int32; `DWMSC_ALL` becomes -1 rather than 4294967295.
All seven original four-byte values, names, member positions,
flags and attributes remain exact. `DwmShowContact` retains its
enum-typed parameter and unchanged signature/import. Both
`DWMWINDOWATTRIBUTE` association targets and parameter placements
remain exact without replacing their native DWORD types.
This is not nine separate API blockers or a new approval gate
for an erroneous legacy storage type. Actual downstream consumer
effects remain unmeasured.

Each unfiltered comparison to `5032F47C...` has the same nine raw
rows at `A552C7D7...`; the historical comparison has seventy rows
at `FD91B7DB...`, retaining the earlier sixteen custom-RetVal and
45 DeviceQuery rows. First-to-repeat is raw-zero at `9E2542A8...`.
All 37,314 literal type positions, 247,662 field positions,
70,740 method positions and every method signature byte actually
remain equal. Reports and raw physical sequences are not sorted
or normalized to obtain that result.

Each image passes 32 exact storage/API/physical/source/blocker
cases and the entire fourteen-case integrity/interface/RAII suite.
Together with the twelve native cases, all **104 qualification
cases pass with zero skips**. Fourteen separate permanent
source/storage guards pass; four retained wrong-UInt32-target
cases fail for exactly Int32 versus UInt32. All new failure
messages are plain text. The original shared `B1F987EA...`
fixture is restored; the existing `CSSW001` warning remains explicit.

Local resumed-original-artifact coverage is now **31/50**:
twelve original IDLs and nineteen headers, fifteen additional
original headers since `12279c76...`. Nineteen header drafts
remain outside the qualified cohorts. Seven missing original
IDL sources and their thirty preserved legacy facts remain
separate blockers. This does not claim whole owning production
integration, current-head CI or publication; no push, PR/stack
mutation or merge is performed.

### Bounded Wer/ErrorRep source continuation, not yet qualified

The next cohort keeps the coupled normal Wer owner intact: original
`WerApi.h` and `ErrorRep.h` are considered together. The three existing
logical flag bags use the released `_Win32_FlagsEnum_` typedef transport
instead of C++-only metadata enum declarations. Their exact 21 member
names, values, UInt32 storage, flags and existing memberships are retained;
no additional native constants are absorbed into these groups.
Thirty-five declaration-local floors replace the old scope blocks.
The five existing associations retain their native DWORD/PDWORD contracts
independently of their logical enum targets.

The exact original `WerReportCloseHandle` and `WerStoreClose` declarations
move before their producers, following the qualified FileHistory cleanup
reference pattern. There are no new prototypes or native type changes.
Stripping only the annotation sites and removing those two byte-identical
declaration blocks from each side reproduces every other selected SDK byte,
including original line endings and trailing blank lines. Both existing
cleanup annotations remain on their precise producer parameters.

Three permanent source guards and all twelve fresh whole-owner
C17/C++17, metadata-off/on, x86/x64/arm64 native cases pass without skips.
Two independent stock Wer traversals and their normal ConstantsScraper
stages succeed at producer `f55e3ccdfa0c85ece11549cd72833fc98b016349`.
Both 3,443-header prepared SDK closures are independently hashed and
literal. The three actual whole owned outputs repeat byte-for-byte;
388 of 389 complete normal-stage outputs are literal, with the two
raw preparation-root-dependent namespace maps retained unmodified.

**The coupled cohort is held on a complete-image compiler blocker.**
The normal constants output contains the source-backed scalar alias
`public const uint WER_SUBMIT_DISCARD_IF_QUEUED = WER_SUBMIT_NO_QUEUE;`.
Its target remains a member of the existing `WER_SUBMIT_FLAGS` group,
not a new loose constant. Both complete 831-input/824-C# emissions fail
with the same single `CS0103`: `WER_SUBMIT_NO_QUEUE` is unresolved in the
processed constants source. There is no candidate or repeat WinMD.
The processed constants bytes are identical, SHA256
`711C10CC74AE778F9E4B2040B12E5630970433DC795CBBA33EB77C8DAF01CE30`.
The existing cleaner removes loose copies of enum members; the released
post-compilation alias conversion requires an already bound enum
expression and does not resolve this unqualified identifier. This is
a measured integration gap, not a new native signedness or source-policy
decision.

Each complete input retains 827 literal unowned entries from sealed
Dwm `D4FF3976...`, including the qualified Eap and DeviceQuery sources.
Only the three whole real Wer outputs replace the old owned inputs;
the exact two synthetic-handle objects, twelve handle-remap rows and
five direct-enum-use rows are removed from the otherwise frozen configs.
The actual quadruple-colon `WerReportSubmit` legacy row is retained in
the removal evidence, not silently corrected.

The bounded first/repeat failures are preserved under
`files\wer-errorrep-alias-held-f55e3ccd` in the owning session.
No alias is suppressed, absorbed into a logical group, manually
qualified or replaced by a literal/cast; no generated source, native
declaration or shared tooling is repaired around the failure.
Final physical/API/order and complete-image acceptance remain unexecuted.
Coverage stays **31/50**; neither header is partially admitted. Other
disjoint original-header work and the separate WNet/RPC holds continue.

### Locally qualified WebSock original header

The disjoint `WebSock` owner traverses the original shipped `websocket.h`.
Thirteen declaration-local Windows 8 floors replace its scope block.
Both existing cleanup annotations remain on `phWebSocket` in the client
and server producer functions. The exact original `WebSocketDeleteHandle`
declaration moves before those producers; no prototype, native enum,
handle, parameter, record, field, SAL contract or helper vocabulary is
invented or retyped.

After removing only the fifteen annotations and that same byte-identical
cleanup declaration block from both sides, every other selected SDK byte
is literal. The five original native enums and their members remain
unchanged. The private 49-header/44-patch/44-partition recipe extends the
last qualified Dwm context and explicitly excludes the held Wer/ErrorRep
patches.

The first authoring at `d620a8ea...` mistakenly used the undefined
function-like token `_Win32_SupportedOS_(Windows8)`. Both stock traversals
and all twelve native cases failed while parsing that spelling; neither
the normal constants stage nor native comparison assertions completed.
This was our authoring error, not a contradictory SDK contract or a
request for new helper vocabulary. The exact failures and plain-text
language-specific diagnostics are sealed under
`files\websocket-authoring-token-negative-d620a8ea`, receipt
`B10934323E114CDFEE38F6ACE583CD81493AF2DAC5E7C89B052C0427CB811212`.

The correction uses only the existing
`_Win32_SupportedOS_Windows8_` macro. The source guard now rejects
function-like floor spellings and requires every floor to have an
existing helper definition. It rejects the original mistake; all
thirteen current fixed-floor guard cases then pass without skips,
including the WebSock case checking its thirteen exact floors.

Fresh stock header and constants traversals at `bd3b6e84...` now
complete twice. Both actual prepared closures contain 3,443 headers.
Of 388 actual normal outputs per run, 387 are literal; only
`traversedFileToNamespace.rsp` contains different preparation-root
coordinates. Both raw maps are retained without normalization. The
whole `WebSock.cs` and WebSocket constants outputs repeat byte-for-byte.
This does not claim fresh all-architecture MIDL execution.

The first corrected-token native run exposed a test-owner identity
defect: SAL owner strings still used Clang's absolute anonymous-record
coordinates. The test-only correction reuses the existing declaration
identity mapping for those owners, retaining every SAL payload and
occurrence. The original twelve failures and their successful
resolution are sealed as
`D0336E58A436C9363C4E8F5FB42610C7BEEDA06811DDFED45D7C5667A64D3ED5`.
The fresh whole-owner C17/C++17, metadata off/on, x86/x64/arm64 matrix
at `aab88d40...` passes all twelve cases. Each side retains 190 native
facts and 974 raw SAL occurrences per case. All five native enums and
their 34 members use Int32 in both old and new metadata and in the
original native controls, including the high buffer bit patterns.
There is no enum-storage compatibility change.

The two complete images, `1DF3F711...` and `D6CC3CEE...`, each consume
831 inputs, including 824 C# files. Their literal source archive is
`B204D3C8...`: only the two whole normal WebSock outputs replace the
sealed Dwm context; all 829 unowned inputs retain the qualified Eap,
DeviceQuery and Dwm sources. All ten full executed emitter configs
are retained and rehashed. Against the actual Dwm image, both
unfiltered reports have the same three lifecycle-relocation rows,
SHA `79B18381...`; candidate to repeat is raw-zero. The native handle
remains, and no API type, native signature or enum fact changes.

The exhaustive physical gates at `9e0f2f79...` preserve all 37,314
type identities and all 247,662 field positions. Only the exact
WebSocket `Apis` and native-handle snapshots change. The static
cleanup method moves before its producers; all other static methods
retain their relative order. Raw signature blobs differ in 212 type
rows because of reference-token numbering, while resolved signatures
and imports remain exact. Raw vectors and differences are retained,
not declared byte-equal or normalized. Native layouts, actual field
order, pointer widths and COM/vtable order remain strict.

An initial operational snapshot cache incorrectly collapsed the
case-distinct `AVIStreamHeader` and `AVISTREAMHEADER` identities.
Its false reports remain preserved. The authoritative ordinal
comparison proves both types unchanged; no unowned difference is
waived. The source, native and emission heads remain separately
identified: production `sources`, `generation` and `scripts` trees
are literal across the two proof-only follow-ups, not relabeled
fresh executions.

The fresh native twelve cases, two 33-case precise source/API/physical
runs and two entire fourteen-case integrity runs total **106 passed,
zero failed, zero skipped**. The shared integrity image is restored.
The local qualification is sealed under
`files\authored-websocket-14-local-9e0f2f79\qualification.json`,
SHA `5AA8E16FBFB8E0713790A2CF3DADE56E1F11FF85326A10C439943105D05A5D44`.
Its 562 indexed payloads total 422,516,702 bytes and were verified
before and after read-only sealing; all 9,324 retained source,
prepared-header and normal-output ZIP entries were independently
rehashed. All indexed payloads of the six referenced prior immutable
packets remain unchanged.

Local resumed-original-artifact coverage is now **32/50**: twelve
original IDLs and twenty headers, sixteen additional original
headers since `12279c76...`. Eighteen header drafts remain outside
qualified cohorts. Seven missing original IDLs and their thirty
legacy facts remain separate. This is not whole owning-production,
current-head CI or publication acceptance. Wer/ErrorRep still require
fresh corresponding qualification with the released generic
`5c226101...` compiler disposition and this latest frozen context;
the original `5A69415E...` hold is immutable. WNet/RPC's actual native
branch/value/type questions remain independent. No push, PR/stack
mutation or PR merge is performed.

### Locally qualified original Wer and ErrorRep headers

The coupled original `WerApi.h` and `ErrorRep.h` cohort is now locally
qualified. The historical `5A69415E...` compiler failure above remains
immutable; no generated source or native declaration was repaired around
it. Released generic compiler source `5c226101...` was ordinarily merged
at `a9f42a8d...`. Fresh stock source traversals, native controls and complete
emissions actually ran at that merge head. The permanent exact acceptance
tests ran at `7b7aa183...`; production `sources`, `generation`, `scripts`
and the native-control source are literal across that test-only commit.
These are separate execution identities, not relabeled later-head runs.

The frozen baseline is the completed WebSock qualification `5AA8E16F...`,
including its independently completed parent binding `2C82BFC5...`.
Its exact `B204D3C8...` source archive retains the qualified Eap,
DeviceQuery, Dwm and WebSock sources. Re-emitting that frozen context
with the actual new `01DCFCBF...` emitter produces `B49A29BB...`,
unfiltered API-zero against the qualified WebSock image. All 37,314
type positions, 247,662 field sequences and 70,740 method/signature
positions remain literal in that tooling control; it is not a fresh
source traversal.

The bounded recipe now has 51 selected headers, 46 literal production
patches and 45 eligible partitions. Two fresh normal Wer header/constants
traversals produce independently verified 3,443-header closures and
389 normal outputs each. Of those outputs, 388 repeat literally; only
the raw preparation-root-dependent namespace map differs. Both raw maps
are retained unnormalized. The actual whole `Wer.cs` output is
`80008CAF...`, including the existing stock ConstantsScraper headers and
usings. Its extra 2,608-byte, 36-line prefix is retained explicitly;
the entire historical `622298F4...` source is its exact literal suffix.
Historical whole-source byte equality is not claimed. No normal source
file was manually edited.

All twelve fresh whole-owner C17/C++17, metadata off/on,
x86/x64/arm64 cases pass. Each side retains 704 complete native facts,
1,526 SAL occurrences and all 21 original macro values. The three
metadata-only UInt32 typedef carriers appear only when enabled, with
47 exact metadata occurrences enabled and zero disabled. The original
native declarations, typedefs, parameter directions, layouts and SAL
contracts remain unchanged. Thirty-five fixed declaration-local floors
are retained; no new scope-based authoring or fresh all-architecture
MIDL execution is claimed.

The actual candidate `1869DB7A...` and repeat `08109440...` images each
consume 831 inputs, including 824 C# files and 827 byte-literal unowned
inputs from that latest WebSock context. Only the three whole normal
Wer outputs, the old owned logical-group file and five owned remap rows
change. All ten executed full configs per image are captured and
rehashed. Their source ZIP containers differ, but all entry names,
bytes and order repeat literally. All 821 compiler-private inputs also
repeat literally; only the compiler-private alias resolution is used.
The original native constants and normal generated sources are intact.

Both unfiltered baseline comparisons retain the same 32 report rows,
SHA `95F9FE5B...`; this is deliberately **not API-zero**. The differences
are classified by affected contract, rather than treating report lines
as separate blockers:

| Contract | Exact metadata change |
| --- | --- |
| Five flag use sites | Old direct enum uses become native UInt32/UInt32 pointers plus the same logical `AssociatedEnum` targets. All three logical groups, 21 ordered members, values, UInt32 storage and actual flags remain exact. |
| Native report/store handles | Seventeen parameters retain native pointer representations; only the two old metadata-only `HREPORT`/`HREPORTSTORE` pseudo structs disappear. The SDK declares `HREPORT` as `HANDLE` and `HREPORTSTORE` as `PVOID`, not as structs. |
| Two precise producer outputs | `WerReportCreate.phReportHandle` and `WerStoreOpen.phReportStore` gain their existing cleanup and invalid-value metadata. No other parameter gains ownership assertions. |
| Existing scalar macro alias | `WER_SUBMIT_DISCARD_IF_QUEUED` becomes a primitive UInt32 constant with value 128 and bytes `80000000`. It is not absorbed into `WER_SUBMIT_FLAGS`. |

The complete physical grade compares all 37,314 old identities.
Exactly the two pseudo types disappear; only surviving `Wer.Apis`
changes. All 37,311 other surviving snapshots are literal. All
41 Wer methods/imports and 35 floors are graded exactly, including the
two explicit original static cleanup declaration moves before their
producers. Real field order, native widths, layouts and COM/vtable
order remain strict. The 36,503 type-position changes and 6,383 type
rows with different raw method-signature sequences are retained
diagnostically, not normalized or treated as native ABI failures.
Every other resolved signature is unchanged. Candidate to repeat is
unfiltered API-zero and literal across all 37,312 type positions,
247,661 fields and 70,740 methods/raw signatures. Actual managed
consumer projection effects remain unmeasured.

The fresh native twelve cases, two 33-case precise source/API/physical
runs and two entire fourteen-case integrity runs total **106 passed,
zero failed, zero skipped**. Fourteen supplementary source guards
also pass; all 120 executed rows, including repeated case identities,
are retained with plain-text error messages. The shared integrity image
is restored byte-for-byte. The separate merged compiler regression run
has 135 passes and one unbound ServiceApi-context discovery skip;
that skip is neither hidden nor counted as source qualification.

The new immutable receipt is
`files\authored-wer-errorrep-15-local-7b7aa183\qualification.json`,
SHA `AF4C2CCB0BF39978822D379BEDF7CB96A2232187C13A0B3F78A58C328F520CB8`.
Its index `E44E9B72...` binds 244 payloads totaling 380,040,753 bytes,
all rehashed before and after read-only sealing. All 11,799 retained
SDK, normal-source, full-source and private-compilation ZIP entries
are independently rehashed. Every indexed payload in the seven
referenced prior immutable packets remains unchanged, including all
171 original held-Wer files.

Local resumed-original-artifact coverage is now **34/50**: twelve
original IDLs and twenty-two headers, eighteen additional original
headers since `12279c76...`. Sixteen header drafts remain outside
qualified cohorts. This denominator is the tracked original-artifact
cohort, not an all-SDK owner percentage or owning-production acceptance.
Seven missing original IDLs and their thirty legacy facts remain
separate. There is no owning current-head CI/publication claim and no
push, PR/stack mutation or PR merge.

WNet/RPC remains independently held on actual native branch/value/type
disposition and 46 loose additions, not the now-resolved generic
scalar-alias compiler boundary. In particular, the retained user-branch
candidate changes `RPC_X_SS_CONTEXT_MISMATCH` from -1073545211 to 6,
`RPC_X_INVALID_BUFFER` from -1073741306 to 1784, and
`RPC_X_PIPE_APP_MEMORY` from -1073741801 to 14. Its UInt32 representation
comes from the existing `ERROR_*` projection and symbolic alias path;
that explains the representation without waiving native signedness or
branch fidelity. The four corrected `WIN32_ERROR` sites remain direct
enum-typed uses, not four `AssociatedEnum` attributes. The general
association-storage clarification does not admit this separate source
cohort or make global #2371 cleanup a prerequisite.

### Locally qualified original FDI and ProcessSnapshot headers

The original `fdi.h` and `ProcessSnapshot.h` cohort is now locally
qualified. The unpatched `fci.h` and `fdi_fci_types.h` are complete
Cabinets traversal context, not two additional migrations. All four
selected SDK originals match the repository mirrors byte-for-byte.
Stock source traversals, native controls and complete emissions ran at
`0364a475...`; permanent metadata acceptance ran at `40479bbb...`.
Production `sources`, `generation`, `scripts` and the native-control
source remain literal across that acceptance-only commit. The actual
native fixture `57B6878B...` and final fixture `52530260...`, their PDBs
and source-checksum bindings are retained separately.

The baseline is the completed Wer qualification `AF4C2CCB...` and its
independently completed parent verification `F60A8A40...`. All fifteen
parent payloads were rehashed here. The exact `D3D6E336...` source archive
and `1869DB7A...` image preserve the latest qualified Eap, DeviceQuery,
Dwm, WebSock and Wer context. Reusing these unchanged inputs is not
reported as a fresh traversal. The actual emitter remains `01DCFCBF...`;
no shared tooling, helper, dependency or toolchain changes are needed.

FDI uses the existing native-neutral `_Win32_Enum_` transport for the
logical `FDICREATE_CPU_TYPE` group. Original `cpuUNKNOWN`, `cpu80286`
and `cpu80386` macros remain -1, 0 and 1; `FDICreate.cpuType` remains
native `int`. Four Windows 2000 floors and ten ProcessSnapshot
Windows 8.1 floors are fixed on individual declarations, not scopes.
The complete original `PssWalkMarkerFree` declaration moves intact
before `PssWalkMarkerCreate`. Its precise native output receives the
existing cleanup and invalid-value facts. Removing metadata and
undoing that one static declaration move recovers both original
headers byte-for-byte. No native enum, alias, cast or forward
declaration is invented.

The bounded recipe contains 55 selected headers, 48 patches and 47
eligible partitions; all 46 prior patches remain literal. Two fresh
stock whole-owner header/constants traversals each produce 3,443
prepared headers and 394 normal outputs. All 6,886 prepared payloads
are rehashed and repeat literally. Of the normal outputs, 393 repeat
literally; the only difference is the actual preparation-root
coordinate in `traversedFileToNamespace.rsp`. All raw outputs and four
raw scratch discovery differences are retained. Discovery decisions
and relative header paths remain exact, with pointer-reduction
coverage checked against the corresponding architecture, not a
cross-architecture union.

All twenty-four whole-owner C17/C++17, metadata off/on,
x86/x64/arm64 cases pass. Cabinets preserves 306 native facts and 489
SAL occurrences per case. ProcessSnapshot preserves 688 native facts
in C and 723 in C++, with 515 SAL occurrences per case. Complete
selected native, SAL and raw-SAL stdout is retained. Metadata appears
at exactly six FDI and eleven ProcessSnapshot occurrences when enabled,
and zero when disabled. The single FDI int carrier is metadata-only.
The native `HPSS` and `HPSSWALK` declarations, field layouts, pointer
widths, directions and SAL remain unchanged.

The complete candidate `EDF06984...` and repeat `263D87E3...` each
consume 833 inputs, including 826 C# files and 824 byte-literal unowned
inputs from the qualified Wer context. Eight whole normal owner C#
outputs replace their corresponding inputs; three are new
architecture-specific group companions. The entire old
`Storage.Cabinets.enums.cs` is removed. The ninth owned archive entry
is the exact enum-use configuration change. All ten actual consumed
configs are captured: only the CPU use remap and old `HPSSWALK`
lifecycle settings change; its native typedef object remains.
All 833 source entry names, order and bytes repeat literally, as do
all 821 actual compiler-private files. No partial source splice or
generated-source repair is used.

Both unfiltered Wer comparisons retain the same four report rows,
SHA `F6D870DF...`; this is **not API-zero**. The developer-visible
changes are two precise representation relocations:

| Contract | Exact metadata change |
| --- | --- |
| `FDICreate.cpuType` | Direct logical enum use becomes native `System.Int32` plus the same `AssociatedEnum(FDICREATE_CPU_TYPE)` target. `In` is unchanged. The logical enum retains its identity, Int32 storage, ordered -1/0/1 members, raw bytes and absent flags. |
| `PssWalkMarkerCreate.WalkMarkerHandle` | Existing `PssWalkMarkerFree` cleanup and invalid values -1/0 move from the `HPSSWALK` type to this precise `Out` producer. The native typedef and its physical representation remain intact. |

Every one of the 37,312 physical identities survives. Exactly the two
owners' `Apis` snapshots and `HPSSWALK` change; the other 37,309
snapshots remain literal with every correction and normalization
switch off. All twenty imports and fourteen floors are graded
exactly. Real field order, layouts and COM/vtable order remain strict;
the original static cleanup move is explicit. Raw baseline/candidate
type, field and method/signature sequences are retained diagnostically.
Candidate to repeat is unfiltered API-zero and literal across all
37,312 type positions, 247,661 fields and 70,740 methods/raw signatures.
Actual managed consumer projection effects remain unmeasured.

The twenty-four native, eight precise metadata/whole-image and
twenty-eight integrity executions total **60 passed, zero failed,
zero skipped**. Three supplementary source guards also pass. These
are 63 retained execution rows and 45 distinct case identities, not
63 distinct tests. TRX error messages are plain text. The shared
integrity image is restored byte-for-byte. Proof-only CRLF, filename,
discovery-coordinate, architecture-union, reflection-dependency and
inline-command mistakes are preserved; none is a native contradiction,
compiler repair or new source-policy gate.

The immutable receipt is
`files\authored-cabinets-processsnapshot-16-local-40479bbb\qualification.json`,
SHA `8CC52BCC20C2B33C9292F83BCAA1E169CBD3DB2AB00D4588E1FB15BB93D89936`.
Index `395FD0BF...` binds 263 payloads totaling 411,051,269 bytes,
all rehashed before and after read-only sealing. Every one of the
11,837 retained ZIP entries is independently rehashed: 11,006 fresh
SDK, normal, discovery, full-source and private-compilation entries,
plus 831 explicitly frozen qualified-Wer entries. All 2,745 indexed
payloads in the eight prior immutable packets remain read-only and
unchanged, including the original DeviceQuery and Wer negatives.

Local resumed-original-artifact coverage is now **36/50**: twelve
original IDLs and twenty-four headers, twenty additional original
headers since `12279c76...`. Fourteen header drafts remain outside
qualified cohorts. Bluetooth has only an independent original-header
preflight at this checkpoint, not source/native/image admission.
WNet/RPC branch/value/type questions, seven unavailable original IDLs
and their thirty legacy facts remain separate. This is not an all-SDK
owner percentage, whole-production/current-head CI qualification or
publication. No push, PR/stack mutation, merge or consumer work is
performed.

### Bounded original Bluetooth scalar witness, not source admission

The next Bluetooth traversal is bound to the qualified FDI/ProcessSnapshot
833-input archive `90A41D86...` and image `EDF06984...`, including completed
parent verification `CA661ADD...`. All sixteen read-only parent evidence files
were rehashed. The unadmitted Bluetooth candidate is not a new baseline.

At source/native/image producer `b8913710...`, the first stock whole-owner
header/constants traversal succeeds. Twelve complete C17/C++17, metadata
off/on, three-architecture native cases and three source guards pass. The
two API patches use forty-seven fixed declaration floors, retain twelve
SetLastError sites, and move two complete original cleanup declaration/comment
blocks before their precise producers. The original `ws2bth.h` is unchanged;
its old metadata-only C++ `constexpr USHORT` patch is removed rather than
replacing the SDK macro or narrow structure field.

One complete candidate image `83DF44BA...` is emitted using the unchanged
`01DCFCBF...` emitter, 833 normal inputs and ten captured configurations.
Both whole Bluetooth outputs are fresh; all 831 unowned inputs remain literal
to the qualified context. The unfiltered comparison `DB4E0F4B...` has twelve
rows: six find-handle uses become native IntPtr, two cleanup-return transfers
retain their existing facts, two synthetic metadata handles disappear, and
two scalar constant types change. All 37,309 other surviving physical
snapshots are literal with every correction switch disabled.

The scalar question is concrete, not an enum-storage gate. Native
`ws2bth.h:47,50` defines `AF_BTH=32` and `PF_BTH=AF_BTH`; the native matrix
establishes signed four-byte int macros. `SOCKADDR_BTH.addressFamily` remains
unsigned two-byte storage, with unchanged fields, packing and native size 30.
The original `socket.af` declaration is int; reading it is not a separately
executed socket-signature assertion. Normal ConstantsScraper literal
projection and alias inheritance produce UInt32 rather than the old UInt16
constants: signature `0607`/constant bytes `2000` become `0609`/`20000000`,
still value 32. This explains the producer result, not native signedness
equivalence or a finding that UInt16 was inappropriate for the narrow field.
The unchanged UInt16 assertion rejects candidate `AF_BTH`.

The appropriate scalar projection and any corresponding source authoring
remain outside this witness's admission. No global AF rule, new annotation,
native cast, alias or generated-source repair is introduced. The existing
macro-only constant authoring contract must not be mistaken for proof that
new shared tooling is necessarily required. There is no native compiler
contradiction, but no repeat traversal/image, full integrity acceptance,
managed consumer measurement or current-head CI/publication claim either.

The read-only receipt is
`files\original-bluetooth-scalar-boundary-b8913710\measurement.json`,
SHA `AFB2F92248D95F118CADD8AFBFF279C5D36A2B71818779A3D133AAE75E79B638`.
Index `91BA7676...` binds 179 payloads totaling 183,106,239 bytes; all 6,674
retained ZIP entries and all 263 prior FDI/ProcessSnapshot payloads were
rehashed. Complete raw reports, literal snapshots, source/config/SDK/private
inputs, native/PDB evidence and proof-only verifier mistakes are retained.
Local coverage remains **36/50**, with fourteen drafts unadmitted.
Independent Power original-header preflight uses the qualified FDI context,
not the Bluetooth candidate. WNet/RPC and missing-IDL holds remain separate.

### Source-first integration checkpoint

We now prioritize broad, buildable source conversion over per-cohort sealing and
repeat audits. Partial conversion and exact temporary sidecar debt remain explicit;
the combined full-SDK build, unfiltered API comparison, regression and CI gate comes
after integration. Historical qualification receipts remain unchanged.

The tracked 50-original-artifact cohort now has **50 source-converted artifacts**:
the previous 36 qualified artifacts, two Hid/DirectInput headers, three Bluetooth
headers, three DHCP headers, two WNet/Npapi headers, and four Power/RestartManager
headers. The additional native `um\winnt.h` PDCAP contribution is outside that
historical cohort. This is not full-SDK coverage or qualification of the combined head.
SDK-wide source/fact inventory and additional bulk migrations extend beyond this
historical cohort.

The initial SDK-wide map at `f2be80b9` retains 19,675 SupportedOS/SetLastError
rows: 12,911 new row candidates across 306 original native headers, 651
covered/assigned rows, 5,544 generated/nonfunction rows, 380 unknown rows and
189 ambiguous rows. These are reconciled inventory categories, not counts of
AST-qualified or completed migrations. The early map uses documentation and
native-declarator lexical evidence; enum, handle, parser and manual categories
are still being classified.

The expanded allocator inventory identifies 1,291 candidate source owners across
254 candidate partitions and 3,096 facts without a unique original. These remain
source candidates, not converted-header counts. Native-header and original-IDL
batch authoring now use shared, source-bound utilities; actual committed patches
and applied output, not candidate totals or recipe edges, determine progress.

Hid retains the native `NTSTATUS` alias using C17-compatible `const`, with its exact
Int32 value and bytes. Its only physical change is the existing static literal
moving within `Apis`; real field layouts, signatures and COM/vtable order remain
strict. The original-source native checks and full-image API comparisons pass.

Bluetooth uses the existing guarded `const USHORT AF_BTH = 32` encoding. The
ordinary `AF_BTH`/`PF_BTH` macros remain signed four-byte `int`, while the
metadata-only constant deliberately retains the existing UInt16 projection.
Both metadata constants retain value 32 and bytes `2000`; the native
`SOCKADDR_BTH.addressFamily` and packed structure remain unchanged. This requires
no new helper, annotation vocabulary, cast or invented alias. Its source/native
checks pass; the remaining measured API differences are the native find-handle
representation and precise cleanup transfers, not scalar widening.

| Source stream | Explicit remaining cleanup or blocker |
| --- | --- |
| WNet/Npapi and coupled RPC | Original groups and native compile fixes are integrated. Retain the three exact signed RPC alias emitter rows and Foundation direct-use rows as explicit debt. |
| Power and RestartManager | Original declarations and source-owned PDCAP contributions are integrated. Stage only the documented association-name, parser, manual-declaration and sizeof-derived constant residuals. |
| DHCP | Original declaration floors are integrated. Retain the exact `DHCP_IP_ARRAY::Elements` CountParamIndex 0 row while global field-array activation remains off. |
| SDK-wide inventory and bulk conversion | Convert the substantial tail outside the 50-artifact ledger and keep unknown or ambiguous facts visible before claiming SDK completion. |

Native compilation, ABI and signature defects remain blockers. Incidental metadata
ordering, additional provenance archives and minor annotation cleanup do not block
committing the working majority. No push, PR/stack mutation, SDK upgrade or consumer
validation is implied by this checkpoint.

### Original Power and RestartManager: source-first majority

The original `um\powerbase.h`, `um\powersetting.h`, `um\powrprof.h` and
`um\RestartManager.h` patches now compile without the held draft's synthetic
native types or macro push/undef/value copies. Direct declaration annotations
preserve 81 Power availability facts (including the callback), 16 last-error
facts, 44 native DWORD/error associations, 11 RestartManager availability/error
associations and the `RM_PROCESS_INFO::AppStatus` association. The existing
`DEVICE_POWER_CAPABILITIES` group unions nine native `um\winnt.h` macros with
the ten native `powrprof.h` macros; its 19 names/values, uint storage and flags
are preserved. Global namespace resolution keeps that union in System.Power.

The bounded original-source scrape covers x86, x64 and ARM64. Seventeen focused
checks pass without skips: C17/C++17 ordinary/metadata native ABI and SAL,
three actual component WinMDs, and exact staging-sidecar assertions. This is
not a new full-SDK image or final CI acceptance. Evidence stays in the worker's
`artifacts\parallel-system-migration\resumed-power-restart`.

| Explicit temporary legacy input | Remaining cleanup |
|---|---|
| `PowerDeterminePlatformRoleEx::Version` enum use | `POWER_PLATFORM_ROLE_VERSION` is also a native object macro; the typed association needs a non-expanding name encoding. Keep the existing V1/V2 group, not an invented CURRENT_VERSION member. |
| `PowerRegisterSuspendResumeNotification::Flags`, `PowerSettingRegisterNotification::Flags`, `PowerSettingAccessCheckEx::AccessType` enum uses | The notification and registry groups need declarations from their physical owners; retain these exact four total Power use rows in `enums.json`. |
| `CallNtPowerInformation::return=NTSTATUS` | Existing emitter substitution retained; the native header's conditional LONG macro is not permission to invent a typedef or use an enum association. |
| `CCH_RM_SESSION_KEY` in `manual\RestartManager.cs` | Existing value retained; the native definition depends on `sizeof(GUID)`, which the constants stage does not capture. No numeric header replacement. |
| `POWER_COOLING_MODE`, `PROCESSOR_POWER_INFORMATION`, `SYSTEM_POWER_INFORMATION` in `manual\Power.cs` | Native declarations are still unlocated; retain the existing declarations rather than fabricate SDK source. Shared HPOWERNOTIFY cleanup remains with its physical owner. |

`EFFECTIVE_POWER_MODE_CALLBACK` still requires the existing explicit
`--reducePointerLevel` parser fixup in addition to the derived pointer cache.

### Bulk native system sources: availability and error majority

The first system source batch adds semantic patches to 23 original native
headers and removes exactly 1,581 availability rows and 415 last-error rows.
It preserves native declarations, storage, constants, library discovery and
all unrelated sidecars. The 1,998 annotation placements include fully covered
native redeclarations. Retained facts receive no partial source annotation.

Strict preparation applies the final patches to their pinned SDK preimages.
Native controls cover all 16 owning contexts and x86/x64/ARM64: 57 initial
ordinary/metadata ABI, layout, SAL and payload checks pass, followed by six
final C17/C++17 Registry checks after the expanded owner map adds 74 existing
Registry floors. Three generated-source readbacks check 137 actual P/Invoke
facts per architecture in the completed AppxPackaging/Authorization scrapes.
The other 1,859 source facts are not an additional emission claim. The broader
selected binding-generation attempt is incomplete, not full-image acceptance.
Evidence stays under `artifacts\bulk-annotations\system-next-001-final*`.

Exactly 650 availability/error facts remain explicitly temporary: 318 lack a
parsed declaration, 248 are macro/definition/non-global placements, 64 share a
source line, 16 have additional lexical references and four have another
physical declaration owner. These are discovery or mapper/placement limits,
not demonstrated annotation-vocabulary gaps or native-contract conflicts.
`dbghelp.h` and `intsafe.h` have no semantic patch and do not count as converted;
their 180 and 107 discovery-tail facts remain intact. Other metadata categories
in these headers still require subsequent source authoring. This is a
source-first majority, not complete-header, full-SDK, CI or consumer acceptance.

The next system batch and its three-original tail add 22 further semantic
native-header patches: 89 availability and 13 last-error facts, with exactly
102 placements and matching sidecar removals. Strict pinned preparation and
54 ordinary/metadata native ABI, layout, SAL and payload checks pass across
the 17 actual owning contexts and x86/x64/ARM64. Contexts are derived from
the selected originals and the current partition traversals, not a fixed
first-batch list. Evidence stays under
`artifacts\bulk-annotations\system-next-002-and-tail*`.

The 54 retained availability facts comprise 15 macro/definition/non-global
placements, seven without a configured owning partition, 23 without a parsed
declaration and nine unparsed declarations or lexical references. The six
unpatched originals (`vsbackup.h`, `clfs.h`, `comppkgsup.h`, `lpmapi.h`,
`d2d1_3helper.h`, `gdipluspixelformats.h`) do not count. Other categories and
final emitted-image qualification remain separate work; these native controls
are not a full-image or complete-header acceptance claim.

### Original-IDL system continuation

The system IDL batch patches 24 authoritative original IDLs and removes exactly
124 equivalent interface availability rows. Actual MIDL generation and strict
canonical preparation produce 24 changed headers with all 124 exact annotated
typedef carriers before their C++ interface definitions. Existing native
admissions and the exact consumed MIDL input closure are preserved additively.

All 96 ordinary/metadata native controls pass: metadata-enabled x86, x64 and
ARM64, plus ordinary x64 for each header. The interface transport permits only
one extra identical, pre-existing same-name typedef for an expected interface;
all other declaration multiplicities, layouts, values, SAL and payloads remain
strict. The common-controls fixture includes `commctrl.h`, matching its owning
partition. Actual normal x64 binding generation and generated-source readback
also preserve every one of the 124 interface floors. These are bounded native
and generated-source checks, not a full-SDK image or CI acceptance.

`wcmconfig.idl` is not admitted or counted: its unconditional `guids.h` include
has no source-backed route in the pinned SDK. Its eight interface floors and
eight non-interface function facts elsewhere in the allocation remain exactly
in the availability sidecar. Evidence stays in the worker's
`artifacts\idl-batch\system-idl-001-*`; failed proposals are not prepared coverage.

### Native system enum source majority

The next batch patches 18 native headers with 53 existing logical enum groups
and 705 compiler-evaluated native members. Names, namespaces, backing storage,
Flags payloads and unscoped bag identities match the immutable emitted baseline.
The metadata-only group invocations, including their semicolons, are excluded
under `MIDL_PASS`. Three existing logical namespaces use the shared
`requiredNamespacesForNames.rsp` mechanism rather than physical-header defaults.

The matching sidecar cleanup retires 53 definitions and 133 explicit member rows.
Two PlaySound uses now annotate the native DWORD parameters directly; 71 unbound
uses remain exact `addUsesTo` rows. All other categories and partial/shared groups
remain unchanged. The 72 selected native controls preserve ABI, SAL, declaration
multiplicities and values across metadata x86/x64/ARM64 and ordinary x64. Actual
bounded x64 bindings and a component WinMD preserve all 53 identities and 705
values. These are source/native/component results, not full-SDK or CI acceptance.

`imepad.h` remains legacy because `IME_PAD_REQUEST_FLAGS` lists the nonexistent
`IMEPADREQ_GETCURRENTUILANG`, not the native `IMEPADREQ_GETCURRENTUILANGID`.
`mcx.h` remains outside this majority because legacy
`MODEMSETTINGS_SPEAKER_MODE` values are 1/2/4/8 while native values are 0/1/2/3.
Neither discrepancy is repaired by inventing members or copying wrong values.
The seven reserved originals outside this majority, unresolved uses and partial groups remain
explicit follow-up work. Evidence stays under the worker's
`artifacts\bulk-annotations\system-nonfloor-enums-001-*`.

The separate two-header follow-up moves four nonconflicting `mcx.h` groups
(13 existing native members) and six `tcpmib.h` field associations into source.
The TCP fields remain native DWORD/metadata UInt32, including the anonymous
`MIB_TCPROW_LH` union field; `MIB_TCP_STATE` remains its existing native enum.
Exactly four complete definitions, 13 explicit member rows and six emitter
association rows are retired. Four modem uses and the conflicting speaker-mode
definition/use remain legacy.

Eight ordinary/metadata native controls and one actual x64 component pass
without skips. The component checks all four group identities/values and all
six emitted UInt32 association payloads. Set `SYSTEM_ENUM_REFERENCE_METADATA`
to the immutable baseline for unchanged shared native dependencies such as
`LARGE_INTEGER`; it does not supply the newly authored facts. The previous
53-group component also remains passing. This is two additional semantic
headers, not complete-header or full-image acceptance. Evidence stays under
`artifacts\bulk-annotations\system-nonfloor-enums-002-*`.

### Isolated native SECPKG_ATTR correction proposal

The three native fragments in `sspi.h`, `minschannel.h` and `credssp.h` cover
21, 13 and 7 members of the same existing `SECPKG_ATTR` identity. The existing
namespace-routing mechanism moves the fragments before merging: the physical
component must contain exactly one unscoped
`Windows.Win32.Security.Authentication.Identity.SECPKG_ATTR`, with UInt32
storage and no Flags payload. Six existing uses annotate their native
`unsigned long ulAttribute` parameters directly. The Credentials partition
includes the real `sspi.h` prerequisite before `credssp.h`; no constants are
invented to satisfy that dependency.

This is an **API-value correction proposal**, not a value-equivalent migration.
Immutable OLD emits `SECPKG_ATTR_SUBJECT_SECURITY_ATTRIBUTES = 124`, while the
pinned shipped SDK defines it as 128. Source annotations use the native macro,
so the proposed component emits 128. The other 40 names and values, storage,
namespace, non-flags identity and all six use targets remain exact. That single
124-to-128 member difference requires explicit final-comparer grading and
review; these source results do not grant completed API acceptance or a blanket
normalization.

Twelve ordinary/metadata native cases and one actual x64 component pass without
skips. Native controls preserve all 75 prior SSPI annotation payloads, ABI, SAL
and declaration multiplicities. They compare the exact local and inherited
group payloads separately, including both attributes on redeclarations, rather
than deduplicating their strings or typedef surface. Only the completely
covered 41-member definition and six native use rows are retired.

The same-owner SSPI extension earns no additional unique-header credit;
`minschannel.h` and `credssp.h` are two new semantic source headers. Original
OLD124 reports remain unchanged alongside the separate native128 proposal under
`artifacts\bulk-annotations\system-nonfloor-enums-003-*` and
`system-nonfloor-enums-004-correction-*`. No frozen central SDK05 input or
full-image acceptance is changed by this source proposal.

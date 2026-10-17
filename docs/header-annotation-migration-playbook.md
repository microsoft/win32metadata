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
obtain SAL through native RPC headers. Pin every actual SAL dependency and the
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

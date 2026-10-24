# Header annotation migration: problems and decisions

Updated: 2026-10-23 (UTC).

This is the running record of migration blockers, their evidence, and the decisions
made while resolving them. The goal is to express win32metadata's intended API
metadata faithfully in the selected SDK's original headers and IDL. A zero-difference
OLD-to-NEW WinMD is not a goal. Breaking changes and unexplained differences remain
visible for review.

## Completion plan and next review

The next run follows a reviewed repair of the header-only source migration.
The decision to pursue a transitional image with API-specific sidecars still
active is withdrawn. That mixed ownership left logical enums partly in headers
and partly in sidecars; `TVITEMEXW_CHILDREN` exposed the resulting storage conflict.
Successful partition scraping did not establish a complete migration.

Header-only attempt 070 completed all 395 native profiles and constant extraction,
then failed combined emission. Its 362 association errors identify 33 missing
logical enum providers. For `RPC_C_AUTHN_LEVEL`, the use annotations reached the
generated source but the definition had remained only in the retired JSON
auto-population rule. All seven native values survived as loose constants.
The attempt is stopped and preserved. There is no complete NEW or OLD-to-NEW
comparison. Subsequent user direction authorizes careful source-first repair and
iteration, including demonstrated tooling fixes, rather than leaving work paused.

The retained-source preflight also found 81 additional OLD enum identities without
raw or processed providers, plus member gaps in 12 present groups. These require
native-source classification, not automatic restoration. `SHARE_TYPE` is a
confirmed unmigrated contract: the native `STYPE_*` constants remain in
`LMShare.h`, but its group and uses were never authored there. At that preflight,
only ten `NativeTypedef` providers appeared in the retained source; unannotated
`BOOL` produced missing-type diagnostics. The source inventory now accounts for
all 440 retired type contracts. Its latest static successor resolves the 56
previously unqualified alias shapes, without treating record values or classes
as pointer typedefs. Frozen source ports are not runtime or provider acceptance.

The initial enum repair has 250 successful, sealed MIDL producers. Its bounded
controls passed C compilation and surface checks on x86, x64 and arm64. All three
C++ surface comparisons and the TreeView carrier-pattern check failed. Those
inputs remain unchanged. The first C++ comparison fails between the OLD header's
metadata-off and metadata-on modes because of an existing metadata-only anonymous
enum; it does not reach the candidate comparison. TreeView's regex rejects a
legitimate newline. These fixture defects require a test-only successor, not a
header repair. VSTest also executed all seven cases despite the requested
stop-on-failure setting. A separate SDK-free qualification now proves six exact
singleton selections, rejection of a two-result selection, and stopping after an
intentional first failure without launching the remaining cases. It used eight
VSTest processes; both negative caller outcomes remain failures. The corrected
test-only successor is separately admitted with this unchanged caller and exact
seven-case catalog, reusing the sealed preparation.

Live-checkout ordinary tests must preserve the existing native diagnostic policy:
generator warning exits are positive successful outcomes when bindings exist,
not an instruction to suppress `FlagEnum`, `MSInheritance` or `WarnUnusedResult`.
The warning fixtures assert exact diagnostics and counts alongside the existing
native-signature and physical-metadata assertions. The declaration-only parse
still validates every diagnostic, but does not reprint a native diagnostic
already reported by the original parse; duplicates within one parse remain
visible. Unsupported native using-directive/anonymous-namespace errors remain
errors, independently of successful native annotation-name binding.

Real-MIDL test fixtures require a short workspace-local TEMP/TMP prefix. The same
unchanged preparation test fails with MIDL9008 beneath the long session-artifact
prefix and passes beneath `artifacts\t-002`; no preparation success policy or
fixture spaces/quoting is changed. Source-state tests inspect effective global
plus partition annotation settings and source-owned facts, not retired sidecar
rows. Retiring a row does not prove source coverage: missing original-IDL floors
and native associations remain explicit test failures, not accepted baselines.

The manual-type inventory exposed replacement-era exclusions that survived
deletion of their handwritten providers. The frozen source packet retires ten
partition exclusions; four common exclusions have also been removed for
`MONITORINFOEXA/W`, `SLIST_ENTRY`,
`HSTRING_HEADER`, cluster records, `PROCESS_BASIC_INFORMATION` and
`FILE_DISPOSITION_INFO`. Native fields, layout, guards and required annotations
remain owned by the SDK originals. The original-IDL and include-selection repairs
for HSTRING, EventRegistrationToken and four private VDS interfaces are frozen;
regeneration and native/metadata qualification remain outstanding. Do not supply
replacement structs from the emitter.

Four complete-record color aliases and the x86 record-alias form of `SLIST_ENTRY`
still need nominal-provider qualification. The GDI+ empty-class family now has
the bounded producer qualification described below; whole-image qualification
remains outstanding. Global empty-record filtering remains enabled. An OLD
`IntPtr` field does not establish a native pointer typedef. Two power-information
types have only qualified selected-SDK absence so far, not a proven removal
decision.

The inventory also separates 73 record-value/tag contracts from genuine pointer
typedefs. A private synthetic diagnostic confirms that ordinary generation can
emit fieldless nominal providers and preserve one- and two-pointer signatures.
The physical TypeDefs have no fields or explicit ClassLayout row; this establishes
no native object size. Empty-record exclusion removes their providers but leaves
the references, causing compilation failure. Ordinary generation also retains
unused forward declarations, so disabling the global filter is not approved.
Referenced incomplete pointees, complete definitions, by-value uses and
complete-empty classes need distinct treatment.

The native `DECLARE_HANDLE` pattern also needs selective retention. Its complete
`struct name__ { int unused; }` declaration has a real field in ordinary
ClangSharp output. For referenced pointees with that exact native shape, retain
the ordinary generated declaration, including its field and layout attributes.
Do not replace it with an empty struct. Other complete storage definitions,
by-value recovery and explicit exclusions stay outside this recovery path;
unused handle declarations remain filtered.

Complete native record aliases also need their own ordinary bindings when a
retained signature names the alias rather than the primary record. The x86
`SLIST_ENTRY` typedef aliases `_SINGLE_LIST_ENTRY`; a pointer remap alone leaves
that alias undefined. A selective ordinary ClangSharp pass emits the referenced
alias with its native fields and layout while retaining the primary provider.
Native source coordinates and canonical identity select the result. Explicit
exclusions, ambiguous aliases and already-resolved references remain protected.
By-value aliases require ordinary generated instance storage; fieldless aliases
cannot establish a new by-value contract.

The global `exclude-empty-records` option dates to commit `d1402d9f` on
2023-04-27. It was not introduced by this migration. Retiring the `autoTypes.json`
and manual API replacements exposed the missing providers. The option filters
binding generation, while the original record declarations and pointer references
remain available in the Clang AST. The selected direction is to retain necessary
source-derived nominal pointees, preserve complete-definition precedence and
native pointer depths, and leave unrelated unused declarations excluded. This
producer change is in the working tree and passes its bounded producer checks.
It emits an
ordinary empty struct for a referenced incomplete native record, without adding
a `Value` field or `NativeTypedef`, changing pointer levels, or keeping unrelated
empty records. No change to the native `UBiDi` declaration is needed.

The 28 opaque-record regression cases now pass, including C and C++ pointer
return/input/output/callback/field cases on x86, x64 and arm64, nested records in
single-file and multi-file output, and the negative filtering/layout checks.
The original selected-SDK ICU header also produces a fieldless `UBiDi` in a
bounded physical WinMD on all three architectures. Its actual `ubidi_open`,
`ubidi_close` and `ubidi_getLength` declaration nodes retain their pointer
signatures and verified `icuuc.dll` imports. The SDK headers are unchanged.

The implementation initially missed the existing decoder for ClangSharp's
incorrectly escaped Windows source-location paths; it now shares that decoder
with annotation processing. Appending a second partial enclosing struct could
also lose a nested provider during WinMD emission. The merge now inserts it into
the ordinary enclosing declaration. The missing VC include path, unrelated ICU
enum imports copied into the bounded fixture, and incorrect OS-version and
nested-name expectations were test/setup mistakes. They did not establish new
limitations on empty structs.

Private cohort `opaque-pointee-retention-001\after-007` records 31 passed opaque
and SDK cases plus four passed existing annotation cases. Six other existing
annotation cases fail on the generator's `FlagEnum` warning exit code; all six
reproduce on the unchanged pre-fix runtime with identical fixture sources.
The whole 41-case invocation therefore remains failed, not an all-green run.
All seven implementation/test files match the frozen source, and the scraper,
emitter and test portable PDBs bind to 69 verified SHA256 source documents.
No production runtime has been replaced.

The first actual-SDK consumer run failed during generation because the bounded
fixture used the test assembly identity `Test.winmd`. CsWin32's normal C# 13
friendly-overload polyfill path requires its primary `Windows.Win32` generator.
Neither consumer compilation ran. The failed image and both generation failures
remain preserved. The fixture now emits `Windows.Win32.winmd` through the
unchanged emitter and asserts its embedded assembly identity. This is a fresh
emission, not a file rename or binary rewrite.

Private cohort `after-008` passes all 35 targeted opaque, SDK and related
annotation cases, including the production-identity assertion on all three
architectures. The actual x64 SDK declaration source is byte-identical to
`after-007`, and the four producer source files are unchanged. All 69 current
source/PDB document checks pass. The six separately established baseline warning
failures were not selected again and remain unresolved. Consumer compilation
against the corrected actual SDK-derived x64 image now succeeds with marshalling
enabled and disabled. Both generation commands and both final compiler commands
exit zero, with the same consumer, options, references and tools as the failed
identity fixture. Root reverified all 41 new consumer artifacts and the actual
command receipts, plus all 121 earlier consumer artifacts and their manifests.
No native imports were executed. This completes the approved bounded `UBiDi`
fix; it does not qualify the full SDK image.

There is an existing metadata precedent. Exact OLD represents `GpCachedBitmap`
as a fieldless ordinary value type with no custom attributes or explicit
ClassLayout row. The selected SDK declares `class GpCachedBitmap;`, and its
create/draw/delete APIs use `GpCachedBitmap**` and `GpCachedBitmap*`.
The related fieldless `GpBitmap` and `GpGraphics` types originate from complete
native type-checking classes; they are not evidence of incomplete declarations.

The subsequent real-SDK GDI+ preflight confirmed that distinction matters to the
producer. The incomplete-only recovery retained `GpCachedBitmap`, but ordinary
empty-record filtering still removed the required complete definitions of
`GpGraphics`, `GpImage` and `GpBitmap`. The same generated source contained the
actual create/draw/delete declarations, so this was a missing-provider defect.

Selective recovery now also admits source-empty definitions and recursively empty
nonvirtual bases. A complete candidate cannot contain fields, methods, static
members or other declarations apart from access labels. Its definition location,
rather than an earlier forward declaration, identifies the supplemental output.
The generated provider must still be fieldless and resolve an existing missing
pointer reference. Explicit exclusions, native identity and scope checks remain
active. Unused empty records and `DECLARE_HANDLE` sentinel bodies remain excluded;
nonempty definitions are not replaced. Incomplete and complete-empty by-value
uses remain errors. None of this establishes an allocation size or object layout.

The final bounded cohort passes 46 selected cases. Eleven regression cases fail
with the exact pre-correction producer and the same final fixtures. Actual
selected-SDK GDI+ declarations now produce all four fieldless providers and the
three verified `gdiplus.dll` imports in physical WinMDs on x86, x64 and arm64,
preserving both pointer levels. SDK bytes are unchanged. The fixture initially
omitted the `Status` definition's header, then attempted to generate unrelated
C++ destructor bodies; it now traverses `gdiplustypes.h` and uses the production
`exclude-funcs-with-body` setting. Those failed setup cohorts remain preserved.

The separately combined tooling control passed all 380 required component cases
and includes fresh production tools and the integrity-review runtime. It predates
this complete-empty correction and remains a control, not the final SDK candidate.
The fresh corrected tooling now passes the exact 395-case union, with no missing,
unexpected, duplicate, failed or skipped cases. This retains 379 original case
identities, explicitly replaces the renamed discovery case, adds 12 new cases and
covers three existing associated-enum forward cases. Both test processes exited
zero on their only attempt. The six selected-SDK ICU and GDI+ physical-image cases
are included. The same frozen source graph produced all six production tools,
their dependencies and assets, and the build-only integrity-review runtime; 207
PDB/source/product bindings are verified. The earlier 380-case packets remain
unchanged. This qualifies the combined tooling, not a complete SDK image.

The combined source snapshot includes the current header and original-IDL patches.
Its 3,443-file original mirror has a separately materialized Git subtree and exact
Windows-byte inventory; the recipe binds that subtree rather than pretending the
dirty worktree is HEAD. The generated SDK build configuration is separately taken
from the qualified tooling source. Fresh SAL/MIDL preparation, ordinary full-SDK
generation, definitive NEW integrity and the raw exact-OLD comparison remain ahead.

CsWin32 consumer qualification confirms that ordinary fieldless pointees support
raw typed-pointer interop. CsWin32 commit `6f333430` generated and compiled a frozen
synthetic pointee and the existing GDI+ create/draw/delete family against its normal
`71.0.37-preview` metadata, separately, with marshalling enabled and disabled.
All four generation and four final consumer compiler invocations succeeded; no
native import was executed. The normal consumer metadata is not exact OLD.
The initial on-mode compiler harness omitted the SDK LibraryImport generator;
those failures remain preserved alongside the corrected compiler invocations.
Root reverified all 96 sealed consumer artifacts and the actual eight successful
command receipts.

This requires an ordinary struct without `NativeTypedef`, which CsWin32 expects
to contain one field. CsWin32 preserves `T*` and `T**` but does not infer ownership
or a SafeHandle from fieldlessness. It also emits some `ref T` friendly helpers:
passing a default empty value through one does not create a native opaque object.
Raw pointers are the demonstrated consumer surface; `ref T*` can represent an
output pointer slot. No native allocation size, dereference or by-value layout
is established. The separate actual-SDK consumer result is preserved in
`sdk-ubidi-consumer-002`: the raw consumer acquires `UBiDi*`, calls
`ubidi_getLength`, and explicitly calls `ubidi_close` in `finally`.

### Remaining execution order

1. Combine the separately checked tooling corrections and the authored header/IDL
   repair packets. Resolve the remaining source-ownership, namespace and native
   contract holds before treating that set as the next SDK build input.
2. Run fresh SDK generation with that exact combined set and emit the ordinary
   full WinMD. A successful small fixture is not acceptance of this step.
3. Run whole-image integrity and `NoSuggestedRemappings`, then compare exact OLD
   to NEW without suppressing differences. Classify intentional changes and fix
   unexplained losses.

The full header-only image and its final comparison have not completed, so
further whole-image defects remain possible. Report each new failure as either
a product defect or a test/setup error, state which step it blocks, and identify
whether it changes this execution order.

The three generic tooling repairs cover nominal scalar/data-pointer typedefs,
cross-architecture macro composition and retirement of owned generated sources.
Independent implementation review requested corrections to all three. The
typedef reader must reject explicit pointer widths that it cannot preserve,
including inner pointer levels. Macro composition must preserve genuine suffix
names, successful empty profiles and architecture-dependent expression bindings.
Retirement must support sparse source directories and replace same-basename manual
inputs even when their lengths and timestamps match. None of these defects explains
the missing enum definitions in attempt 070.

One earlier compiled snapshot contains the first versions of all three repairs.
Its focused qualification covers
206 executed cases: 200 passed in the first invocation; six control checks initially
failed because the runner selected a DLL/PDB archive without its runtime
configuration. Those six passed in a preserved successor using the complete
original control deployment and the unchanged compiled snapshot. No product
change or weakened assertion was needed for that successor. This evidence does
not close the subsequent implementation-review findings.

The retirement corrections reproduced seven failures, then passed all 50 related
cases. Missing profile directories are tolerated without hiding other deletion
errors. Changed or first-untracked manual input sets force copying; their identity
manifest is committed only after staging succeeds, so a failed copy cannot poison
the next attempt. The typedef-width correction has 126 passing cases after
six actual native/physical reproductions. Independent re-review accepts both
bounded corrections, while retaining the retirement packet's missing before
DLL/PDB limitation.

The macro successor passed 152 cases and closes suffix-name and successful-empty
profile defects. Independent review still requests two corrections: primitive
alias lowering must precede per-profile constant binding, and enum underlying
storage must survive composition or fail explicitly. The new counterexamples are
source-traced, not claimed as executed failures. A coherent corrected test union,
runtime admission and complete-image checks remain outstanding. The previous
component selections share 30 typedef-composition cases; two distinct marker
cases also have the same truncated display text, so display-name counts alone
cannot establish coverage.

The architecture remains the selected SDK originals plus authored patches,
targeted MIDL regeneration, the compiler-backed C# scraper, constant extraction,
and one namespace/architecture-composed WinMD. SDK sources own API-specific facts;
the reader binds them to native declarations; the emitter preserves them in the
complete image.

1. Keep authored API metadata retired from active JSON/RSP inputs and handwritten
   API sources. Attribute definitions, namespace organization, documented parser
   fixes and SDK-derived import discovery remain separately identified. Every
   normal profile reads header annotations. Do not fill missing facts from a
   legacy fragment or a baseline assembly.
2. Independently review the complete migration tooling while repairing missing
   logical groups, typedef contracts and incomplete member sets. Definitions,
   members, storage, Flags, guards and uses belong together in the original
   headers or IDL. Assign each shared original artifact to one author. A tooling
   change requires a reproduced reader or emitter defect and regression coverage;
   missing source facts do not justify weakening composition checks.
3. Check retained compilation diagnostics and actual generated providers against
   the retired definition inventory, including groups without failing references.
   Prepare the corrected originals, regenerate every affected MIDL output and
   exercise the changed source contracts before the next complete run.
4. Freeze the reviewed source and runtime candidate. Run all 321 owners and 395
   normal profiles into a fresh output directory, followed by constant extraction
   and combined WinMD emission. Do not reuse stale generated C#, constants or
   filtered response files. Stop on a compilation failure, preserve and report
   it, and diagnose the shared cause before another coherent correction or run.
   A failed run produces no NEW and cannot have an OLD-to-NEW comparison.
5. If a complete NEW is emitted, compare exact EDF069 OLD against that image.
   Preserve the full raw differences and integrity results, including
   NoSuggestedRemappings. Missing header facts and intended representation
   changes remain visible; neither is a reason to reactivate a sidecar.

| Review category | Required disposition |
| --- | --- |
| Intended representation changes | Explain the consumer impact and retain the raw difference, including primitive-plus-association signatures, storage corrections, logical names, and enum/global placement. |
| Selected-SDK changes | Prove the change against the selected native source and available OLD provenance; do not infer removal from one missing token or header. |
| Corrections to OLD | Show the native contract and why OLD was incorrect. |
| Missing header facts or providers | Identify the exact missing fact and original owner. Do not restore non-header metadata to conceal it. |
| Reader, emitter, or composition defects | Group by shared cause and propose bounded fixes. Missing APIs and wrong namespaces are not accepted as intended changes. |
| Unresolved provenance | State what remains unknown and the observation needed to decide it. |

## Historical execution record

The following records preserve earlier attempts and decisions. Transitional-image
instructions and execution authorizations in this history do not authorize the
current run; the header-only plan above supersedes them.

- The C# generator remains in use. The qualified tooling is ClangSharp 21.1.8.4
  with libclang 21.1.8. This toolchain is fixed for the complete-image milestone;
  no compiler upgrade is a prerequisite.
- The finite047 producer started at 16:52 UTC on 2026-10-21 and was stopped by
  user order to fix scraper performance, with 201 profiles launched, 169 completed
  logs and 32 incomplete logs. Its owned processes are verified stopped; partial
  outputs and stack samples are preserved. After the fixes below, the complete
  ordinary graph resumed as `full-sdk-supported-061`, with MSBuild starting at
  21:21:29 UTC on 2026-10-21. Its actual ordinary-input manifest confirms 321
  owners, 393 normal profiles, 32 workers and `StageEmit`. The frozen prepared
  source/header inputs and constants/emitter runtime remain unchanged; only the
  measured scraper and matching PDB replace the original runtime files.
  That graph terminated naturally at 21:29:37 UTC with all 393 completion logs
  and nine genuine failures across five owners. `ScrapeHeaders` took 475.307
  seconds; the ordinary driver took 487.487 seconds and its wrapper 499.650
  seconds. Constants and emission were not reached. There is no complete NEW
  WinMD; integrity and comparison remain blocked. The failed run is preserved
  unchanged.
- The prepared adapter omitted the normal `ExcludeFromCrossarch` policy,
  scheduling 963 native jobs instead of 393. Its correction preserves deliberate
  all-architecture controls and adds explicit normal-build scheduling with
  matching `common` response-file accounting.
- Three samples of one slow worker identify ClangSharp's linear diagnostic-list
  membership scan as a CPU hot path. A small reproduction with 2,000 macros now
  exposes 3,760 generator errors: preprocessing records enabled for annotation
  parsing reach the declaration visitor as unsupported cursors. The wrapper
  previously read diagnostics after `Close()` cleared them. Diagnostics are now
  captured before close in both declaration and selective-macro generation.
  The scheduling correction alone is not claimed to resolve the slowdown.
- [dotnet/ClangSharp#846](https://github.com/dotnet/ClangSharp/issues/846)
  contains a standalone reproduction requiring no SDK or win32metadata code.
  Its 2,000-macro case reports zero errors without detailed preprocessing and
  2,465 errors with it; generated bindings are byte-identical. At 32,000 macros,
  binding generation takes 4.3 seconds and reports 32,465 errors. These are
  single observations, not full SDK timings. The report now explicitly corrects
  the original classification: these are expected diagnostics for our unsupported
  caller configuration, not bogus errors.
- The detailed-record/ordinary-generation combination was introduced by this
  annotation migration in `b5b7b26e`, removed in `746d812d`, and reintroduced for
  original-IDL comment ingestion in `62f92b07`. Baseline `origin/main` does not
  request detailed preprocessing. The pinned ClangSharp CLI requests it only
  with macro-binding generation. Its macro mode processes preprocessing records
  and unconditionally reparses the source plus synthesized declarations.
  There is no existing public declaration-only entry point that accepts the
  detailed TU while avoiding macro generation and a second parse. The current
  replacement instead used that supported macro mode and accepted its second
  parse without publishing every macro. The full 061 result below exposed the
  cost of evaluating unrelated SDK macros even when their output is discarded.
- The first supported-mode candidate uses the original published ClangSharp 21.1.8.4
  generator, SHA256 `8AAD64A1AE97C2FEEA813F929F998F624A1E8FE18E82EB94F5DAE3BAD399CB44`.
  Annotation mode enables macro bindings before parsing; explicit macro mode also
  requests the detailed records even when annotation mode is off. Original-TU
  annotation facts remain the source of metadata. The adapter identifies primary
  generated macro fields/properties by their source `NativeTypeName("#define ...")`
  provenance, keeps only existing annotation-requested constant fields in
  `header-types.cs`, and leaves native declarations and the constants fallback
  intact. This avoids shared name exclusions that could delete native enum members.
  A requested provider outside the partition traversal retains the existing
  exact-name macro pass only when its field was not already emitted.
  All 54 focused tests pass on the published generator, including native-name
  collisions, remaps, provider files, explicit general macro mode, comment transport,
  physical cross-architecture fields, remap discovery and diagnostics. Warning
  exits remain positive and visible; the physical Flags controls and an excluded
  function-like macro control now assert that production success contract.
  The two authorized real partition runs completed naturally, sequentially.
  Controls/arm64 took 213.170 seconds wall and 213.047 seconds CPU, with
  1,157 generator warnings and sampled peak working set 1,919,705,088 bytes.
  Devices.Properties/arm64 took 132.190 seconds wall and 130.969 seconds CPU,
  with four generator warnings and sampled peak 1,161,105,408 bytes.
  Each also printed nine native Clang warning lines and no visible error lines.
  All three outputs per partition are byte-identical to finite047 and all input
  and runtime pins remain unchanged. Both targets are verified absent.
  finite047 is an annotated output-parity reference, not a clean `main`
  performance control. The paired main controls below establish that performance
  is still unacceptable. The full SDK remains stopped.
- The user requested an actual `main` versus updated-tool/patched-header timing
  comparison. `main` is pinned to `2f767671802301cf043c717d66bf004ed7863487`,
  matching the live remote. Its unmodified scraper builds in an isolated session
  snapshot with the same published managed/native ClangSharp versions.
  The main DLL hash is
  `82739629862D5F9EB5624597DF10E6C62D28213EC34CB5EA26D68DAC3D3204EA`.
  Exact committed main headers, settings and both partition sources are exported
  separately. Both matched single-worker controls completed naturally:
  Controls/arm64 took 8.9483924 seconds wall and 8.984375 seconds CPU, with
  sampled peak working set 462,086,144 bytes; Devices.Properties/arm64 took
  4.0022206 seconds wall and 4.125 seconds CPU, with peak 379,768,832 bytes.
  Both exited zero, with no errors, timeout or retry. Main retains its original
  diagnostic-lifetime bug, so its generator warning counts are unknown.
  All 4,282 source/configuration pins and ten runtime hashes remained unchanged.
  Main uses its committed `RecompiledIdlHeaders` tree `491aef01`; the candidate
  uses prepared patched tree `9d5a9670`. The main SDK package reference alone
  does not describe those actual header bytes.
  The updated tool and patched-header profiles are 23.8 and 33.0 times slower
  than their respective main controls. These ratios compare the intended tool,
  headers and configuration together; they do not isolate a particular cause.
  Those initial timings fail the reasonable-performance gate and required the
  actual CPU attribution and fixes recorded below.
  Once reasonable performance is established, the user has directed
  resumption of the ordinary complete SDK graph: normal scheduling, constants,
  WinMD emission, integrity checks and the unsuppressed OLD-to-NEW comparison.
  Scraper isolation is temporary diagnosis of the stage where the full run
  stopped; that run did not establish an emitter failure.
- Three managed samples of an isolated F758 Devices.Properties replay, at
  15, 40 and 75 seconds, all identify our `GetLegacyParameterComment` reader
  before binding generation. The reader resolved each parameter's filename
  back to a native file and reread its source, twice per parameter. It now uses
  the expansion's native `CXFile`, caches that file's source bytes for the
  original TU, and scans each parameter once. The first fix reduced the profile
  to 35.863 seconds with byte-identical outputs.
  The first attempted unprofiled observation was stopped at 0.17 seconds by
  the observer's empty-array handling error; it is not a scraper timing or
  correctness result. That observer error was corrected before the natural
  observations reported here.
  Subsequent samples identify `NativeNameLookup.GetWrittenFunctionName` while
  indexing global functions. The lookup now indexes original preprocessing
  expansion locations before invoking expensive native cursor lookup; ordinary
  function locations cannot be macro renamers. All existing definition, spelling,
  token and factory-rejection guards remain intact.
  The final scraper is SHA256
  `2F93F34DA1659E71F4DCB176A1D238C97B604D7E074FC1EB48686CC7DAF57FC6`,
  still using the published `8AAD` generator. All 111 focused cases pass,
  including physical MIDL directions/retval, object-macro selectors, factory
  rejection and a new 1,000-parameter, two-file UTF-8 offset regression.
  Four existing factory-control cases now assert the documented nonnegative
  success exit and visible function-like macro warning; their invalid-selector
  and generated-output checks remain intact.
  Unprofiled Controls/arm64 now completes in 27.4923358 seconds wall and
  29.5625 seconds CPU; Devices.Properties/arm64 completes in 15.6404833 seconds
  wall and 16.875 seconds CPU. Both exit naturally, retain the same warning
  counts (1,157 and four), leave original input pins unchanged and reproduce
  all six retained output files byte-for-byte. These remain 3.1 and 3.9 times
  main; historical full-pipeline performance is not established.
  Post-fix representative samples show original-TU construction, annotation AST
  traversal and the supported nested native parse instead of those reader
  bottlenecks. With the pathological costs removed and the residual overhead
  disclosed, the ordinary full graph is authorized to resume, using normal
  scheduling (393 profiles), 32 workers and the final scraper. Its actual
  end-to-end time, complete image, integrity results and raw OLD-to-NEW comparison
  remain outstanding. No additional partition qualification is a prerequisite.
  Raw Root evidence is in session files `supported-profile-diagnosis-060`.
- Full 061 failures comprised Backup on all three architectures and Kernel/common
  crashing in native `getFileContents` through `VisitVarDecl`; Rpc/common throwing
  in `VisitCXXOperatorCallExpr`; and explicit macro-definition errors for
  `__unaligned` in Shell.Common/common and `__inline` in WinProg on all three
  architectures. The fatal stacks do not identify the offending variable or
  macro. No SDK source workaround or guessed macro-name exclusion is applied.
  The two named keyword-macro failures reproduce in standalone fixtures.
  The replacement keeps the original detailed TU for all discovery, annotation
  and written-name facts, but parses a separate ordinary TU without preprocessing
  records for full native binding generation. It does not enable general macro
  generation implicitly. Requested AssociatedConstant providers retain their
  exact-name supported macro pass; explicit general macro mode is unchanged.
  This retains two ordinary native parses while avoiding unrelated macro
  evaluation. The primary-source macro-stripping adapter is no longer needed
  and is removed. Diagnostics from both parses and both binding paths remain
  visible; parse and generation errors prevent publication.
  All 113 focused tests pass, including both keyword repros, native-name
  collisions, provider fallback, macro selectors and physical annotation output.
  The new scraper SHA256 is
  `D15881F1B8516F764D46084509F631FD8913579E270EE0804650B712230EE5E8`,
  still using published `8AAD`. Sequential real-header parity controls complete
  naturally: Devices.Properties/arm64 takes 15.7461397 seconds wall and
  16.671875 seconds CPU (exit zero); Controls/arm64 takes 25.6473213 seconds wall
  and 27.078125 seconds CPU (exit one). All six outputs remain byte-identical and
  original input pins unchanged. Unrequested macro warnings disappear because
  those records are no longer evaluated, not because diagnostics are suppressed.
  All nine actual failed profiles now complete successfully on the unchanged
  replacement: natural MSBuild exit zero, 53.0971514 seconds driver time, nine
  nonempty main sources and no genuine error or fatal diagnostics. Original
  response semantics are unchanged apart from fresh output roots.
  The complete graph automatically resumed as `full-sdk-declarations-063`,
  with MSBuild starting at 21:54:20 UTC on 2026-10-21. Actual ordinary inputs
  confirm 321 owners, 393 normal profiles, 32 workers and `StageEmit`. The
  runtime and prepared source/header inputs remain pinned as above.
  All 393 header profiles and constants completed successfully. The graph then
  failed naturally during emission at 22:02:44 UTC: auto-type generation could
  not find `WHvDeletePartition` in the C# namespace index for
  `WHV_PARTITION_HANDLE`. No NEW image was emitted. Stage times were 438.126
  seconds for headers, 44.359 seconds for constants and 15.032 seconds for the
  failed emission; driver time was 503.9102399 seconds and wrapper time was
  511.631371 seconds. The selected pristine and prepared `WinHvPlatform.h`
  gate those declarations to `_AMD64_` or `_ARM64_`, but the project's
  `ExcludeFromCrossarch` list schedules Hypervisor only as x86/common.
  The ordinary task correctly follows that policy and the declarations are
  preprocessed away before binding. The emitter scans all architecture
  directories before cleaning or import filtering; its rejection is correct,
  and an explicit auto-type namespace already exists.
  Only Hypervisor was removed from `ExcludeFromCrossarch`, preserving the native
  header guard, normal adapter and qualified runtime. The corrected normal
  graph has 284 common owners and 37 architecture-specific owners, or 395
  profiles. Prior 393-profile results remain historical evidence, not a
  successful complete surface. Full `full-sdk-hypervisor-064` started at
  22:26:07 UTC on 2026-10-21 with a fresh selected-project overlay and isolated
  complete output; frozen 063 remains unchanged. Actual ordinary inputs confirm
  321 owners, 395 profiles, normal crossarch scheduling and 32 workers.
  A regression using the real selected project reproduces the skipped x64
  profile before the policy change. After the change, all 40 prepared-include
  and scheduling tests pass, including Hypervisor's combined and individual
  architecture schedules. Actual 064 generated sources now contain
  `WHvDeletePartition` in x64 and ARM64, with no x86 declaration, matching the
  native guard. All 5,473 other selected source files and the qualified runtime
  and prepared headers remain unchanged.
  Complete emission, ordinary integrity and the unsuppressed comparison
  remain outstanding; no additional approval gate is required.
  Raw Root parity evidence and frozen replacement are in session files
  `declaration-only-bindings-062`.
- Full 064 completed all 395 header profiles and constants, then failed naturally
  during emission at 22:36:48 UTC with WMA003: the retained `WSA_ERROR` group
  could not evaluate `ERROR_IO_PENDING`. Driver time was 641.3407807 seconds;
  wrapper time was 647.4454693 seconds. No NEW image was emitted.
  The legacy reader compiled an isolated enum, discarding its original imports
  and external constant declarations. Actual source has static imports of
  Foundation's `Apis`, `WAIT_EVENT` and `WIN32_ERROR`, including the required
  compiler-known values. The three relevant Root source hashes match frozen
  emitter 74CC's portable PDB and compiled-source snapshot.
  The replacement evaluates legacy groups in their original scopes with the
  selected architecture's source context. It shares the existing cleaner's
  loose-constant removal rule, composes referenced groups before dependent
  values, and retains compiler checks for storage, overflow, missing or cyclic
  dependencies and conflicting definitions. Final compilation still reports
  unrelated source errors. No header, numeric-value or namespace workaround is
  applied.
  All seven captured import/external-constant regressions fail before the repair.
  The complete emitter suite now passes 179 tests, including 32 composition cases
  covering the captured Winsock aliases, aliases across files, implicit values,
  architecture-specific providers, dependent groups and invalid dependencies.
  The next ordinary emission uses the sealed complete 395-profile C#/constants
  closure with a replacement emitter in isolated output and `SkipScraping=true`.
  The failed 064 result remains failed; native scraping need not be repeated.
  Actual NEW emission and the attached integrity and unsuppressed EDF069
  comparison remain outstanding.
- Emitter-only 065 failed naturally before source processing in 1.3071151 seconds.
  The first replacement referenced workspace `MetadataUtils` version
  `71.0.391.57282`, while the qualified runtime retains `71.0.335.41385`
  (SHA256 prefix `CAC2BB6D`). This was a replacement-build packaging error; the
  logical-enum fix was not exercised and no NEW image was emitted.
  Rebuild the unchanged `dfc225d1` source against the retained DLL with project
  dependency builds disabled. The corrected emitter SHA256 is
  `D53E2457D424A7014EE53D5341AD22868138C841AD706562C8540DFC1755A36C`.
  Its assembly reference now matches the retained dependency, and all 17
  portable-PDB source documents are individually checksum-verified and copied.
  A cold copy of the qualified 250-file runtime with only the emitter DLL/PDB
  replaced emits the captured alias fixture successfully in 1.5235003 seconds.
  All 248 other files remain hash-identical, and the emitted WinMD physically
  contains `WSA_ERROR.WSA_IO_PENDING` as Int32 value 997. This fixture image is
  binding evidence, not the complete SDK NEW.
  The frozen packet is in session files `legacy-enum-bound-runtime-066`.
  A fresh ordinary emitter-only continuation is authorized on the same complete
  395-profile producer closure, followed by the existing integrity and exact
  EDF069 comparison. Failed 064 and 065 remain sealed; no native rescrape or
  dependency substitution is required.
- Emitter-only 066 passed loading and logical-enum composition, then failed
  naturally after 275.7344505 seconds on duplicate Foundation `IntPtr` typedefs.
  The raw producer source already collapsed seven native handle names through
  generated autoTypes storage remaps. The scraper now retains the native wrapper
  identity for storage remaps without changing normal API bindings. Composition
  preserves the retained `Value` field encoding for `IntPtr`/`void*` pointer
  spellings, including architecture variants; genuine type, annotation and
  duplicate-name conflicts still fail.
  All 12 new producer/physical regressions failed before the repair. The repaired
  pipeline passes 32 targeted cases and all 186 emitter tests. Physical cases
  preserve all seven handle identities, their relationships, invalid values and
  retained pointer encodings on x86/x64/arm64.
  A read-only inventory of all 131 raw header-types inputs finds exactly one
  affected normal profile: Foundation/common, scheduled as x86. Refresh only that
  profile with the corrected scraper, then compose it with the other 394 frozen
  profile outputs and unchanged constants before ordinary emission. Preserve
  failed 064/065/066; no complete NEW image or downstream comparison exists yet.
- The authorized Foundation/common refresh completed naturally in 17.7315135
  seconds with all seven original native identities and relationships. Composed
  emission 067 used that fresh profile, the other 394 frozen profiles and unchanged
  constants. It passed the typedef repair and failed naturally after 292.4277652
  seconds at strict association validation: 30 logical names have two namespace
  candidates, while `SHUTDOWN_REASON` and `DCOMP_SURFACE_HANDLE_ACCESS` have none.
  All 357 distinct diagnostics and 713 printed lines remain preserved.
  The bounded 32-name source/input table compares the actual providers with exact
  EDF069 OLD. Thirty-one names exist in OLD; the DirectComposition group does not.
  Preserve all 31 established FullNames through literal global namespace routes.
  In particular, `ACE_FLAGS`, `RESOURCE_DISPLAY_TYPE`, `SHARE_INFO_PERMISSIONS`,
  `VIRTUAL_KEY` and `WORD_BREAK_ACTION` must not inherit either current candidate
  merely because it already exists. The retained `PROCESS_CREATION_*` wildcard
  does not route a header enum through the emitter's literal-name declaration
  mover, so `PROCESS_CREATION_FLAGS` needs its own exact entry.
  Shutdown already includes and traverses the patched `reason.h`, containing its
  complete 51-member unsigned-long group, but its normal response omitted
  `parse-win32-annotations`. Enable that existing reader configuration; do not
  recreate the group in JSON or generated C#. The qualified runtime is unchanged.
  All 31 new namespace-policy cases fail before the route changes. After repair,
  43 bounded physical/native cases and all 187 emitter tests pass. An initial
  bounded fixture passed the entire SDK namespace map without the corresponding
  SDK namespaces and failed on unrelated imports; it now selects its actual
  route from that map. Three existing association-negative native cases still
  demand zero despite a visible nonfatal `MSInheritance` warning; their failures
  remain recorded and those tests are not changed.
  The remaining DirectComposition annotation referenced a group with no selected
  header provider. All 3,443 prepared files confirm that its three legacy
  `COMPOSITIONSURFACE_*` member names are absent. The selected SDK instead defines
  `COMPOSITIONOBJECT_READ`, `COMPOSITIONOBJECT_WRITE` and
  `COMPOSITIONOBJECT_ALL_ACCESS` in authored `shared\dcomptypes.h`, under the same
  desktop/Windows 8 guards as `DCompositionCreateSurfaceHandle`. Their native
  values are `0x0001L`, `0x0002L` and the original OR expression.
  The [documented parameter contract](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositioncreatesurfacehandle)
  also names those current constants. The mirror and selected SDK original are
  byte-identical, SHA256 `447E4ADF411B9818D68BB6F5A0A9EF9F423B95CC2B10610F51936DC921135594`;
  this is an authored header, not an IDL-generated output.
  Add the missing unscoped, non-Flags `DCOMP_SURFACE_HANDLE_ACCESS` group after
  those definitions, with unsigned-long storage and the existing current names.
  Preserve the macros, guards, API declaration, native UInt32 parameter and
  existing association. Do not manufacture old-name aliases or restore missing
  SDK constants. Admit this one original-header patch through the normal recipe.
  Only DirectComp traverses this header. Its ordinary common/x86 profile must be
  refreshed; the runtime and other successful profiles remain reusable.
  All 11 focused cases pass: recipe/provider wiring, compiler-evaluated values,
  physical storage/association, C and C++ on all three architectures, native ABI
  with annotation mode off/on, and desktop/Windows 8 guard exclusions. Strict
  standard patch application also succeeds against the exact original bytes.
  Exact EDF069 OLD has no group and no attributes on `desiredAccess`; its first
  parameter is UInt32. The actual NEW must therefore expose this as a source-backed
  added enum and association, not an equivalence waiver. Leave the unused legacy
  JSON entry and all frozen constants unchanged for this first-image continuation.
  The actual Shutdown-only normal refresh 068 succeeded naturally in 14.3976817
  seconds. Its UInt32/Flags provider has all 51 names and values from exact OLD.
  DirectComp preparation exposed a separate input-mode constraint: the selected
  frozen SDK is an already-prepared snapshot with retained and refreshed MIDL
  provenance, not a published `Prepare-SdkHeaders` cache. Its archived source has
  no Git HEAD. Root's mirror still matches the pinned tree, but Root has no
  published preparation cache to reuse. Do not alter Git/recipe pins, forge a
  cache producer, or rerun unrelated MIDL to make the mirror builder accept it.
  For this transitional image, derive a fresh private prepared-input successor:
  verify and copy all 3,443 recorded inputs, apply only the newly admitted authored
  header patch with strict standard patch validation, and require exactly that
  one input to change. Preserve all retained MIDL source/SAL/generated bytes and
  original producer records. Record the complete parent and successor inventories
  as a derived prepared snapshot, without claiming canonical cache publication.
  The ordinary scrape then consumes that verified successor.
  No complete NEW or downstream comparison exists yet, and 067 remains failed.
- [dotnet/ClangSharp#847](https://github.com/dotnet/ClangSharp/pull/847) warns once
  when preprocessing records reach generation with macro bindings disabled.
  Its reviewed condition is not used by the updated consumer. Per the user's
  conditional request, that PR has not been built or tested locally.
- The local managed ClangSharp patch is committed as
  `2c21756d022d75b357ce807f1f121a5365f27352` directly above release
  `v21.1.8.4`. Its preprocessing filter adds support for our caller scenario;
  it is a policy extension rather than a proved upstream correctness fix.
  Its independent hash-based diagnostic membership change preserves ordering,
  equality and reset behavior. All 32,000 genuine declaration errors remain
  visible while their binding step drops from 4,947.1 to 425.9 milliseconds.
  Native libraries and assembly identity remain unchanged.
  All 54 focused library tests pass. An independent consumer measurement drops
  the 32,000-macro binding step from 4,333.0 to 115.0 milliseconds, with zero
  preprocessing errors under that extension and byte-identical output. This
  measures the local extension and diagnostic optimization; it does not establish
  that the original flag combination was supported or restore the full baseline.
- Five focused consumer regressions pass, covering ordinary and selective macro
  bindings, retained warnings, retained declaration errors and rejected invalid
  selective macros. A wider selection has 804 passes, 54 failures and 20 skips.
  Forty-eight failures demand a zero exit despite now-visible nonfatal warning
  counts; the others concern exception/aggregation expectations and anonymous
  namespace errors. These failures remain visible; the consumer suite is not
  claimed all-green. The isolated Controls/arm64 timing hit its 120-second limit
  before the logged GenerateBindings entry and emitted no candidate source.
  A subsequent stack observation aborted because its observer incorrectly
  compared timestamps from APIs with different precision; it yielded no stacks.
  The observer is corrected but has not been rerun. The complete SDK graph remains
  stopped and its end-to-end time is unmeasured.
- A separate quadratic scan in our remap discovery is corrected without changing
  traversal order: direct typedefs no longer repeatedly search the entire
  declaration list. At 32,000 typedefs discovery drops from 28,665.5 to 766.9
  milliseconds with identical mapping hashes. All 52 focused discovery,
  macro/diagnostic and physical WinMD integration tests pass. This synthetic
  result is not a measured attribution of the Controls timeout.
- Source cut `57be4e4239abbb1c9239dedfa0d6b7ddf117a3f2` is integrated. It contains
  the corrected `GPFIDL_FLAGS` group, the `SERVICE_NOTIFY_FLAGS` rename, the
  `ASSOCF` header migration, four credential-group retirements, the bounded
  `CERT_FIND_FLAGS` forward correction, the new `BCRYPT_OPERATION` group, and
  the shared compiler-identity and record-eligibility repairs, original-source
  OLE groups and associations, the remaining DDE associations, and the corrected
  logical name `CFU_UNDERLINE_TYPE` without the rejected CFU macro workaround,
  24 already-authored Cryptography use retirements, and 18 native Flags scopes
  from the existing original-owner source, with their 18 matching emitter
  `enumMakeFlags` rows retired. Six such rows remain. The later, independently
  qualified 26 Virtdisk return associations and reviewed metadata-only MSI zero
  member are now admitted as source. Neither source cut retires an additional row.
  Subsequent cuts add native Flags bookends to original MMstream, OPM, and
  Activprof IDL; retire the source-covered `VerSetConditionMask::TypeMask` use
  and eight RPC V2-V5 A/W field uses; and remove the conflicting metadata-only
  SetupAPI `VER_PLATFORM` forward. The RPC group provider and unmatched base
  record use remain active.
- The first-image hard-blocker source successors now include the two missing
  native WTS macro operators and withdrawal of the unsupported WDS
  `CPU_ARCHITECTURE` forward and two compiled associations. Only their exact
  original-source patch deltas are admitted; all JSON/RSP inputs and parked
  followups remain unchanged. The WDS group and both uses remain active in JSON.
  These are source corrections, with current-candidate native replay still
  pending.
- The additional Fs and WeakReference corrections are now admitted as exact
  source-only deltas. Fs retains all three field associations and its existing
  logical provider while removing three artificial scalar forwards.
  WeakReference retains the common Resolve ComOutPtr comment and removes only
  its duplicate inside the manual branch. Native declarations, SAL and guards
  remain unchanged. Affected IDL regeneration completed before the stopped run,
  with all four native MIDL invocations exiting zero. Current-candidate replay
  remains incomplete; no new CINTERFACE or physical-output result is claimed.
- Runtime `71.0.340-preview+8d0cd24516` has 135
  focused checks including six physical ANSI/Unicode architecture cases. The
  earlier ordinary SDK results used `71.0.339-preview+03958d1bb5`; Controls and
  Shell also produce real output with zero unknown/unused facts on runtime340.
  The later selective-constant successor is
  `71.0.341-preview+53f3459d5b`, with 60 executed focused checks and 18 physical
  output pairs. Its exact four-file source is integrated as
  `80deedfd20a9e709a738ea00b0e72702dd4c51c3`. Those identities remain distinct;
  runtime341 was used by the stopped ordinary SDK run, which does not establish
  complete-image success.
- The `GPFIDL_FLAGS` representation has a reduced physical WinMD proof on x86,
  x64, and arm64. Actual Controls/x64 replay clears all three previous GP/service
  binding errors. Its later IStream projection failure is fixed in runtime340;
  actual Controls now succeeds without exporting the out-of-traverse IStream type.
- All twelve planned x64 owners now succeed with real C#, header types, and remaps.
  Exact generated targets confirm all 214 active cleanup-site repairs. The three
  inactive native branches remain source-only. These are generated-output results,
  not complete-image, physical WinMD, or consumer acceptance.
- All seventeen planned ordinary owner/architecture profiles now succeed with
  strict validation. Cross-architecture coverage in this set is limited to
  ApplicationVerifier and Threading; the 214-site claim remains x64 only.
- Actual Shell output contains the exact 19-member UInt32 Flags `ASSOCF` group and
  Int32 `GPFIDL_FLAGS`. A bounded physical x64 WinMD now confirms the actual GP
  parameter and all eleven ASSOCF parameters are enum-typed, with no redundant
  associations. It preserves the 19 ASSOCF names, order, and raw values, including
  duplicate value2. This uses the frozen existing emitter and authenticated
  inherited IUnknown declaration; it is not complete-image or new Com projection
  acceptance. The WBEM selector now binds in Shell's actual TU, but Shell does not
  project IWbemServices, so its actual owning output is not claimed.
- Actual Cryptography output confirms eight `BCRYPT_OPERATION` members, all six
  OLD members unchanged, the two additional native values, and a uint parameter
  with association. `CERT_FIND_FLAGS` produces its 44-member UInt32 Flags group.
- Corrected-SDK ordinary ComOle, DataXchg, and RichEdit replays now exit zero.
  Their outputs contain the seven OLE verbs, nine cache flags, corrected 21-member
  CFU group, and DDE associations. These are generated-output checks.
- Constant-RSP removal needs further parser work. A managed probe on real SDK
  headers derives the four HRESULT attributes from winerror.h, but also exposes
  ten untyped icon constants from its numeric RC branch. The SDK also contains
  plain HRESULT fallback definitions in ddrawi.h's inactive Win16 branch.
  All fourteen attribute rows and the constant type overrides remain retained.
  Any macro-binding replacement must also prove physical fields: the text
  scraper treats readonly bindings as already written, while emission may omit
  them.
- A 24-case unchanged-runtime proof now confirms literal loose CLSCTX globals
  and a typed `D3DTS_WORLD` global with native-enum associations. These do not append
  physical enum members. Use the loose representation for genuinely loose native
  constants; preserve the resulting OLD-to-NEW differences.   Selective projection from existing annotations is now implemented and qualified
  on runtime341. It uses an exact requested-name allowlist and rejects nonconstant
  bindings before publishing output. No whole-partition macro option or new
  enum-member annotation family is approved.
- API-specific sidecars still remain active. Some already duplicate authored
  header replacements; their retirement is a separate unfinished source task.
  The app restart restored the existing coalescer, which preserved the accepted
  source and decision-log ancestry. Its next bounded source check found fourteen
  exact missing associations in Pdh and Winnt, including conditional PDH records.
  Those uses remain active and are routed to their existing original writers;
  this does not establish the status of every remaining use. No replacement
  session or source-rights transfer was made.
- The single full 963-job ordinary scrape was launched at 08:02 UTC on October 21
  against frozen dd4 headers and runtime340, with MaxProcessors32. The producer
  verified MSBuild, 32 real scraper processes, CPU progress, and actual C# outputs.
  Later MSI, 26-return, and three native-Flags IDL changes are outside this snapshot.
  Its first located failure affects Base and DevInst on all three architectures:
  SetupAPI's
  migration-added unsigned-int `VER_PLATFORM` forward conflicts with Winnt's
  unsigned-long logical group. The original writer has released a one-line
  source correction, now integrated. Affected ordinary replays are pending; the
  frozen inputs remain unchanged. Historical snapshot005 captures 172 completed logs and ten
  diagnostic cases, not a final result. Four cases in Direct2D and Direct3D11on12
  cannot resolve `DXGI_ENUM_MODES`: the base header contains only a metadata
  scalar forward, while its complete logical group is in a later DXGI header.
  The final ledger contains nine DXGI failures. One approved instrumented8d
  x86/Direct3D11on12 observation now proves that dxgi1_2.h did not participate
  in that original TU; the selected scalar had no logical-group facts.
  The artificial forward cpp_quote has now been removed from original
  dxgi.idl by its current Display writer and admitted through packet047,
  preserving the association and full provider. The one-observation receipt is
  sealed; no second diagnostic parse was run. This single observation does not
  establish inclusion behavior for every other profile or current native success.
- Post-restart reconciliation confirms that the original producer is no longer
  running. Its terminal result was never persisted, so the native/driver exit
  remains unknown. There are 956 completed-case logs and 958 settings files;
  the final ledger records 912 nonempty main outputs without an error diagnostic,
  six completed empty outputs, 38 task failures, two launched profiles without a
  completion log, and five with no observed launch. These are evidenced profile
  states, not reconstructed native exit codes. This is not a completed
  963-profile result. The complete candidate in the plan above is the next
  production milestone.
  The 38 failures group into six shared families: SetupAPI (15 profiles), DXGI
  (9), filesystem metadata (3), WeakReference (5), WDS (3), and a distinct native
  Terminal Services parse error (3). SetupAPI's source correction is already
  integrated; affected replay remains pending. These families are the current
  compilation worklist, not a functional OLD-to-NEW assessment.
  The two-token Terminal Services original-source correction is now admitted;
  it must remain visible as a native SDK syntax correction in the comparison.
- There is no complete successor WinMD yet. The complete integrity-test run,
  selected-SDK delta evaluation, and unfiltered complete OLD-to-NEW comparison
  remain outstanding.

The earlier canonical SDK preparation produced 739 headers from 468 inputs and
250 native MIDL invocations. All 250 invocations exited successfully with complete
headers. The subsequent 963-job scrape failed in 696 jobs and retained 270 partial
C# files; it did not produce an accepted complete NEW image.

## Problems and decisions

| ID | Problem and evidence | Decision | State |
| --- | --- | --- | --- |
| D01 | The migration depended on a replacement Rust generator before header annotations could be adopted. | Retain and update the existing C# pipeline. A replacement generator must independently reach functional parity. | C# annotation transport and focused physical proofs are implemented; complete-image qualification remains open. |
| D02 | Generated SDK headers cannot be the source of truth for IDL-owned declarations. | Patch original `.idl` files and regenerate their affected outputs. Patch authored `.h` files directly. A native MIDL exit of zero with complete outputs may retain the specific known MIDL2337 diagnostic; other failures remain blocking. | Original-owner patching and targeted regeneration are in use. Thirteen such diagnostics were retained in the earlier successful canonical preparation. |
| D03 | Migration-added scalar forward declarations conflicted with logical enum groups. Some similarly named aliases were genuine SDK declarations. | Remove only forwards proved to have been introduced by migration. Preserve genuine native typedefs, records, constants, guards, and ABI; do not weaken enum-kind validation. | Shared artificial forwards, including 103 additional Winuser forwards, were removed. The bounded CERT_FIND_FLAGS correction retains its 44-member group and association; MenuRc/x64 and Cryptography/x64 succeed. The full 963 run exposes another scaffold in SetupAPI: unsigned-int VER_PLATFORM conflicts with the legitimate unsigned-long group in Base and DevInst on all three architectures. The original-writer correction, integrated in afbc47, removes only that line. Strict source-patch replay and full-source inverse preserve PROCESSOR_ARCHITECTURE, the guard, both field associations, and Winnt; affected ordinary replay remains pending outside frozen dd4. |
| D04 | Some migrated `RAIIFree` facts were attached to carriers that did not match native parameter or storage ownership. | Put each fact on its correct native declaration or parameter. Preserve the native signature and evaluate the resulting metadata explicitly. | 217 carriers were corrected: 214 active sites plus three inactive forms. Actual x64 generated targets confirm all 214 active sites: 25 Winuser, 97 Gdiplus, one Hypervisor, 34 Oleauto, 44 Wingdi, nine Memory, one Power, two Controls, and one Display. Other architecture and final WinMD checks remain; the three inactive forms remain source-only. |
| D05 | Macro and comment enum-name references did not consistently resolve against the complete native translation unit and final emitted enum set. | Use compiler-expanded tagged name transport and shared complete-TU resolution. Defer only absent unqualified names. Reject visible wrong kinds, ambiguity, and absent qualified names; require exactly one final emitted enum per architecture. | Shared transport, resolver, and deterministic WMA001 aggregation are implemented. Invalid facts abort before output; native parse success alone is insufficient. |
| D06 | Twelve real inline function definitions were reported as missing annotation targets because output exclusion hid them from comment binding. | Bind and validate against real native definitions first. Keep output exclusion separately in `ShouldEmit`; do not edit declarations or comments to work around the binder. | Runtime039 contains the bounded correction. Focused controls passed, and the twelve false missing-target errors disappeared in actual Controls replay. |
| D07 | Metadata-only enum carriers raised a C versus C++ compatibility question. | Metadata-enabled parsing is C++ only. Ordinary native C SDK compilation remains protected; C metadata-on parsing is not an acceptance requirement. | Recorded in the spec and playbook. Superseded namespace experiments were not adopted as production source. |
| D08 | Native `GPFIDL_FLAGS` is `typedef int`; OLD metadata used a UInt32-backed logical enum. Its only external OLD signature use, `SHGetPathFromIDListEx::uOpts`, was already enum-typed. Values are only 0, 1, and 2. No unsigned-storage rationale was found in its original history. | Preserve the native int typedef and anonymous constants. Add a matching global `_Win32_Enum_(GPFIDL_FLAGS, int, ...)` group and omit redundant `AssociatedEnum` on `uOpts`. Accept the visible UInt32-to-Int32 enum-storage correction. | Source integrated in451. All-three-architecture reduced proofs retain native ABI and entrypoint. Ordinary Controls/Shell succeed. Actual Shell/x64 emission-only output now physically confirms the Int32 nonflags/unscoped group with0/1/2 and enum-typed uOpts without association. The existing frozen emitter and authenticated unchanged IUnknown dependency are explicit; complete-image grading remains pending. |
| D09 | OLD logical enum `SERVICE_NOTIFY` collides with a genuine SDK service-record alias of the same name. | Rename the logical group to `SERVICE_NOTIFY_FLAGS`; preserve all ten members, order, values, UInt32 storage, and Flags semantics. Update both mask associations. Preserve native records, typedefs, DWORD parameters, and buffers. Do not hide the rename behind a remap or compatibility alias. | Source integrated in451. Actual ordinary Services/x64 succeeds and emits the exact ten-member UInt32 Flags/unscoped group, both uint masks with the new association, and native SERVICE_NOTIFY_2A/W pointer buffers. Physical WinMD and complete-image grading remain pending. |
| D10 | Eleven Shell annotation references target native scalar alias `ASSOCF`. The header has its genuine DWORD typedef and 19 constants, but no logical group. The existing manual C# enum and exact OLD image independently establish the intended UInt32 Flags group, including duplicate value2. All eleven OLD parameters are actual named enum types, not primitive-plus-association parameters. | Move that exact existing group into its original header using matching unsigned-long/DWORD storage. Remove only its manual enum block and eleven migration-added redundant associations, preserving native declarations and all 19 members. | Source integrated in02fc. Actual ordinary Shell340/C9 succeeds. Bounded actual x64 physical output now confirms all six A/W functions and five IQueryAssociations parameters are ASSOCF-typed without association; its UInt32 Flags/unscoped group matches all19 OLD names/order/raw bytes, including duplicate2. Complete-image namespace composition and consumer acceptance remain separate. |
| D11 | The authored WBEM selector names `IWbemServices::GetObject::lFlags`, but an actual Shell native AST identifies `GetObjectA::lFlags`. Wingdi's active `GetObject` macro changes the native declaration name; UNICODE selects the W form. This is not a missing guard or function body. | Accept the written selector only through the first compiler TU's exact MacroExpansion-to-MacroDefinition link, direct identifier replacement, and matching replacement-token spelling file/offset. Preserve native selectors, strict scope, kind, ambiguity, canonical identity, and parameter ordinals. Do not execute comment macros or change native-reference resolution. | Successor8d is qualified, including ANSI/Unicode physical bindings on x86/x64/arm64 and negative factory/ambiguity controls. Actual Shell340 now binds the selector and succeeds with strict validation. IWbemServices is not projected by Shell; actual owning-output and complete-image claims remain separate. |
| D12 | Some partitions did not actually enable annotation parsing through their ordinary accumulated response files. Including a header also did not prove that partition owned its projection. | Inspect the real ordered and nested response inputs, enable parsing in the owning settings, and require positive output from actual projection owners. Resolve nested response paths relative to process CWD. | Gdiplus and Hypervisor opt-in were repaired and both ordinary x64 runs now succeed with positive generated facts. Ownership explicitly distinguishes MenuRc/Winuser, Shell/shlobj_core, and Services/winsvc. Wider ordinary acceptance is pending. |
| D13 | After common enum-binding errors clear, ordinary Controls reports unprojected `IStream` facts at commctrl.h814. The saved native AST proves one canonical type: an unannotated forward inside traversal, but its actual full Objidl definition outside traversal. Eligibility is being evaluated through the wrong native declaration. The validator also reports only the first unused declaration. | Use the compiler-linked actual record definition for projection eligibility when present. Keep lone incomplete/complete unused records strict, preserve all facts, and validate invalid facts even outside traversal. Reuse the expected-error collector for independent post-projection errors, aborting before output; propagate unexpected exceptions. | Successor8d passes the focused controls and actual Controls340/C8 exits zero with no unknown/unused facts, both cleanup targets positively projected, and no IStream type exported. Exact unchanged C8 native inputs isolate the reader fix; the original039 failure receipt is retained. |
| D14 | Retained API-specific sidecars still participate in generation, including duplicate header replacements. The original 441 enum items included 149 named groups and 378 actual use rows; an initial shell count also included null array entries and has been corrected. API-specific RSP inputs remain active. | Retire already-authored replacements in bounded coherent cuts using the existing fact ledger. Author missing original-source replacements rather than treating unmatched facts as permanent exemptions. Do not delete them wholesale, claim header-only coverage, or build a new inventory gate. Grade typed legacy remaps versus primitive-plus-association header output in the raw API diff. | Credential, certificate, BCrypt, OLE, DDE, Cryptography, VerSetConditionMask, and eight RPC V2-V5 A/W ImpersonationType uses have bounded matching retirements; the CFU correction is under D19. Current JSON has 407 items, 140 named groups, 267 added-use groups, 317 uses, 629 explicit members, and 39 auto-populate groups. RPC_C_IMP_LEVEL's entire named provider, auto-population, and unmatched base RPC_SECURITY_QOS use remain active. Its five UInt32 nonflags members match OLD; native unsigned-long fields plus existing associations remain a visible change from OLD's actual enum fields. The cumulative 46 exact retirements above ff924 comprise 28 JSON uses and 18 emitter Flags rows, not a global migration count. |
| D15 | OLEIVERB has no header group; UPDFCACHE_FLAGS has its UpdateCache association but no original-IDL group. Exact OLD proves seven Int32 nonflags/unscoped verbs and nine UInt32 Flags/unscoped cache members. The sidecar's trailing/double-underscore cache aliases do not exist in OLD or the selected native declarations. | Add the seven native verb constants to Ole2.h in OLD order. Add the nine cache constants to original oleidl.idl in exact OLD order, after their definitions, then regenerate its header. Do not recreate unused underscore aliases or infer a new DoVerb association: its inspected OLD iVerb is Int32 without association. Preserve native DWORD grfUpdf and its source association, while exposing its expected metadata representation change. | Source integrated in1143 with exact authored bytes, strict selected-SDK patch replay, and full native/SAL/guard/prior-metadata inverse proof. Four exact legacy objects are retired, including the five non-emitted placeholder rows without new-authorship credit. Canonical owning Oleidl033c MIDL exits zero with complete output and12 pinned actual inputs; header01BF1214 and the nine-member-only inverse are preserved. Corrected-SDK ordinary ComOle now succeeds with both groups inspected. No SDK-wide MIDL was added; physical WinMD grading remains pending. |
| D16 | BCRYPT_OPERATION has no header group or use. Exact OLD contains six UInt32 Flags members and an actual enum-typed BCryptEnumAlgorithms parameter. The native SDK explicitly defines two more operation constants with WIN8 and WIN11_GE availability guards. | Use the existing global Flags helper with mutually exclusive native 8/7/6-member branches. Preserve all six OLD names, order, and values, native ULONG, SAL, and availability guards; associate the native parameter with the logical group. Keep both newly included constants and the named-enum-to-primitive-plus-association change visible. Availability guards alone do not prove an SDK-version delta. | Source integrated in431. Actual Cryptography039/C10 succeeds and emits the eight-member UInt32 Flags group with exact OLD six names/order/values plus 64 and 128, and uint dwAlgOperations with association. It also emits CERT_FIND_FLAGS with 44 UInt32 Flags members and uint dwFindType with association. Physical WinMD grading and classification of OLD's two omitted operation constants remain open. |
| D17 | OleDuplicateData's retained sidecar associates cfFormat with CLIPBOARD_FORMAT and uiFlags with GLOBAL_ALLOC_FLAGS, but neither association is present in its original header. Exact OLD independently confirms both actual enum parameter types without associations. | Add both associations to the existing native CLIPFORMAT and UINT parameters in Ole2.h. Preserve HANDLE, all native parameters, and surrounding metadata. Grade the resulting primitive-plus-association parameters explicitly rather than inventing aliases or emitter promotion. | Source integrated in1143 with both native signatures and all earlier metadata byte-preserved. The exact two matching sidecar uses are retired; actual owning output and physical WinMD grading remain pending. |
| D18 | Six existing DDE logical groups lack eight source use-site associations: DdeEnableCallback wCmd, DdeInitialize A/W afCmd, DdeNameService afCmd, DdeClientTransaction wType, and CONVINFO wType/wStatus/wConvst. Exact OLD uses actual enum types at these sites. | Add only those associations to original ddeml.h, retaining native DWORD/UINT, SAL, existing group members/order/flags, and all other declarations. Retire only the matching legacy use rows and expose the primitive-plus-association representation changes. | Source integrated in95 and92 with strict selected-SDK replay and exact full native/SAL/guard/prior-metadata inverses. The bounded DDE owner has no matching JSON uses left. Corrected-SDK ordinary DataXchg succeeds and its associations are inspected; physical WinMD grading remains pending. |
| D19 | OLD's unrelated UInt32 Flags group named CFE_UNDERLINE contains 21 CFU constants; native CFE_UNDERLINE is value4 in CFE_EFFECTS. Source95 temporarily pushes/undefines/restores the macro to retain the old logical name, which passes byte inverse checks but violates the spec's explicit ban on macro manipulation for grouping. | Reject that workaround. Rename only the logical group to CFU_UNDERLINE_TYPE after proving the new name absent from native source. Preserve all 21 OLD member names/order/values, UInt32/Flags/unscoped semantics, genuine CFE_UNDERLINE and CFE_EFFECTS, and no new bUnderlineType association. Keep logical-name and owning-namespace differences visible; do not add a compatibility alias. | Corrective source e160 is integrated. The new name is absent from all selected native .h/.idl files; all three temporary macro-state lines are removed, selected-SDK strict replay and complete native/prior-metadata inverse pass. The95/1143/92 receipts remain immutable, with their CFU workaround rejected. Corrected-SDK ordinary RichEdit succeeds with all21 members inspected; physical WinMD grading remains pending. |
| D20 | Constant overrides cover native literal parsing, selected preprocessor context, aliases, and intended storage. The current converter treats IO_REPARSE_TAG_SYMLINK's 0xA000000CL as int unless forced unsigned. A real-header managed probe derives the four HRESULT attributes from winerror.h but emits ten icon constants without native pointer attributes after seeing the numeric RC branch first. Inactive Win16 fallbacks in ddrawi.h also define the four errors without HRESULT casts. | Do not blanket-delete constant overrides or treat a winerror-only success as whole-pipeline proof. Preserve native SDK branches. Use compiler-selected context and compiler-visible source intent to replace the overrides; distinguish generic parser corrections from API-specific storage choices. Check physical fields, not generated C# alone: readonly bindings can suppress text fallback while failing later emission eligibility. Neither the force-const name prefix nor a Constant attribute supplies missing literal storage/value semantics. | Runtime341 now projects only supported constant macros requested by existing associations; pointer/nonconstant requested bindings fail explicitly before output. Unrelated numeric/pointer text fallback is physically covered. This does not replace the fourteen attribute rows or the constant type rows. Constant keeps an otherwise eligible static field, but a default is written only for an actual compiler constant; force-const changes modifiers/name, not its type. Existing manual resource constants still use ushort plus NativeTypeName(LPCWSTR). |
| D21 | Five CryptQueryObject legacy uses duplicate existing original-header associations and groups. Exact OLD has actual enum parameters at the three input sites and actual enum pointers at the two output sites, with no associations. | Retire only the five exact duplicate uses. Keep native DWORD and DWORD pointers with their existing source associations and preserve group member names/order/Flags. Grade both value and pointer representation changes explicitly. | JSON-only source ff924 removes the five matching objects and use rows, preserving all unmatched raw bytes and prior header proof. No new annotation authorship, native compile, or final physical WinMD acceptance is claimed. |
| D22 | Nineteen more Cryptography legacy uses duplicate source-owned associations: string conversion four, certificate string type two, query encoding record fields three, context/find/control six, and certificate record fields four. Names ending in FLAGS are not sufficient reason to change nonflags groups. Two encoding uses belong to another original owner. | Retire only the exact source-covered uses after comparing OLD member order, Flags, and actual signatures. Preserve native DWORD declarations and existing associations, and retain the foreign-owner SIP uses. Keep enum-to-primitive field and parameter differences visible. | JSON-only cuts274/5ecd/82067 are integrated, preserving unmatched bytes and Root log ancestry. Header, runtime, and RSP inputs are unchanged; no new authorship or native replay is credited. |
| D23 | Two integrated originals lack 18 native Flags scopes already present in a released but unintegrated owner source. That source also contains 26 separate WIN32_ERROR return associations; a writer handoff does not admit those automatically. | Compose only the 17 Virtdisk scopes and one MINIDUMP_TYPE scope against the exact integrated originals. Preserve existing Flags, returns, all conditional native enum bodies, and separately sealed unadmitted source. Do not substitute the whole donor branch or credit existing facts as new authorship. | Source dd4 and its exact18-row RSP retirement956 are integrated. Strict selected-SDK patch replay and removing only the 18 new scopes recover integrated headers byte-exact. Six enumMakeFlags rows remain. The 26 returns were excluded from this cut and subsequently admitted independently under D27. The active dd4 scrape still excludes them. |
| D24 | Exact OLD contains both MENUPARTS::MENU_POPUPSUBMENUHCHOT and MENU_POPUPSUBMENU_HCHOT=21; selected native vsstyle has only the first spelling. Equal values do not prove name or alias equivalence. | Retain the reviewed metadata label while examining its header-driven transport under D26. The spec explicitly permits metadata labels bound to existing native values without invented ordinary SDK aliases. Native-token absence alone does not justify deleting the label. | The earlier conditional retirement instruction is withdrawn. The row remains active and native spelling/value is unchanged. Assess whether a metadata-only guarded member referencing the existing native enumerator can reuse the admitted MSI source pattern before adding a new tooling family. No such source edit, SDK-version removal, alias, or retirement is claimed. |
| D25 | A private SDK composition ran Git's patch helper inside a nested archived-source prefix. Git skipped external patch targets despite exit zero; per-target hashes rejected the output. | Run the existing strict helper from the actual repository root with empty prefix, verify original preimages and every affected target, and retain the rejected receipt. An exit code alone is insufficient SDK composition proof. | Corrected e160 manifest3A1A3061 verifies739 original preimages and all457 header patch targets changed. The subsequent frozen dd4 manifestAF533772 verifies3443 headers/250 qualified MIDL outputs and only two further Flags header deltas. Canonical MIDL preprocessing excludes those guarded pragmas, so unchanged outputs are retained. One actual963/32 scrape has started on runtime340; no repeated17-profile gate or second full producer. |
| D26 | AssociatedConstant preserves a relationship, not physical enum membership. On unchanged runtime340, 24 physical controls prove loose CLSCTX globals with native guard values 23/21 or 7/5 and typed D3DTS_WORLD=256. OLD CLSCTX has both combination members; OLD D3D and the retained-row control have no WORLD member. | Use loose globals for genuinely loose native constants, retaining native types, guards, values, and associated enum identity. Keep the CLSCTX member-to-global and guard-dependent changes visible. Do not infer D3D retirement from an unexplained inactive row. No new EnumMember helper or native-member composer is approved. Select only names requested by existing projected annotations, without enabling all macro bindings or changing unrelated APIs. | Exact source53f3459d is integrated as80deedfd; actual runtime341/53f passes 60 focused checks with 18 physical pairs. All four WORLD globals are enum-typed with values256-259; CLSCTX globals are Int32 with native guard values. IncludedNames selects one compiler-backed macro batch; ambiguous, function-like, excluded and nonconstant requests fail before output. Missing local providers remain deferred, not fabricated. Frozen340 and emitter74CC remain unchanged. Fixture storage/Flags and reduced old-guard controls do not establish ordinary SDK or header-only acceptance. All twelve addition rows remain active. |
| D27 | The 26 separately sealed Virtdisk return annotations had not been admitted by the Flags-only handoff. Exact historical rows and OLD physical WIN32_ERROR returns now independently bind each selected native DWORD return. | Admit only those exact prefixes, preserving native DWORD, SAL, guards, prior returns, and all18 Flags scopes. Keep the actual-enum-return to primitive-plus-association representation change visible. | Independent Supportfc68 proof and coalesced dff3 source are integrated. Strict selected-SDK/incremental replay and the direct26-prefix inverse recover the Flags-only source. Current matching return RSP rows are zero, so this source cut retires zero rows and adds no authorship or producer/API credit. It is outside the active dd4 snapshot. |
| D28 | The selected msiquery.h native MSITRANSFORM_ERROR has seven explicit members and no NONE member, while the existing metadata row supplies MSITRANSFORM_ERROR_NONE=0. | Use the spec's explicit reviewed-zero exception. Add only that metadata-only zero under WIN32METADATA and not MIDL_PASS; preserve the native seven members, order, values, type, and ordinary/MIDL surface. | Systemf434 source, composed as5c1, is integrated with strict selected-SDK replay and an exact guarded-addition inverse. The matching enumAddition row remains for its owning retirement task. No additional retirement, new logical group, flags, use-site change, or SDK/compiler acceptance is claimed. |
| D29 | MMSSF_GET_INFORMATION_FLAGS, OPM_HDCP_FLAGS, and PROFILER_EVENT_MASK are existing native enums whose Flags intent still lives in emitter rows. The first OPM owner packet also inherited four obsolete availability carriers that conflicted with qualified current source. | Add only guarded flag_enum bookends to original mmstream.idl, opmapi.idl, and activprof.idl. Require the same original owner to reconcile stale OPM context, preserving qualified windows6.0.6000 comments, native signatures, values, ordering, and generated-tag remaps. Regenerate the owning headers before claiming generated Flags transport. | Source 8bf41 composes MMstream048 and reconciled OPM048a; 1b8a254 adds the exact released Activprof source. Strict selected-SDK replay and bookend-only inverses recover the entire prior sources, including all three existing heap Flags scopes. Activprof preserves its five native members. The four OPM representation conflicts are resolved by its explicit owner successor; the rejected packet stays immutable. All three emitter rows remain active; owning MIDL/physical validation is pending outside frozen dd4. |
| D30 | Frozen DXGI failures reject IDXGIOutput::GetDisplayModeList::Flags. The one approved instrumented8d x86/Direct3D11on12 observation proves dxgi1_2.h is absent from the original TU inclusions. The only DXGI_ENUM_MODES declaration is the metadata-only uint TypedefDecl in dxgi.h, with no raw owned attributes, logical members or same-canonical group facts. The complete UInt32 Flags provider1/2/4/8 exists physically in dxgi1_2.h but did not participate. | Remove only the migration-added scalar-forward cpp_quote from original dxgi.idl. Preserve its guards, association, all native IDL and the entire dxgi1_2.idl group. Use existing unqualified absent-name cross-partition deferral; do not add includes, split groups, change lookup/validation or patch generated headers. | Root authenticated snapshotFA2FBF49 and sealed one-observation receipt4CB5642C. The observation preserved WMA001/no-source and MSBuild1; observer56613055 remains diagnostic-only, not production341. GetFile/empty skipped ranges do not establish file entry. Display36878909 full patchf1b97a82/66230C28 is composed as one-path1bb4d6c7 and admitted through packet047, retaining strict-IDL replay and one-line inverse evidence. Current-candidate MIDL/replay remains pending; no second diagnostic parse or broader profile-visibility claim. |
| D31 | After the app restart, the original full963 producer is absent and ordinary-result.json was never persisted. The surviving ordinary.log has no terminal result; 956 completed-case logs and 958 settings files do not prove all requested profiles ran or succeeded. | Preserve the exact partial input/output/log capture and unknown terminal exit. Use the completed profile accounting to drive the next finite candidate, without relabeling the interrupted run or making optional migration work a build prerequisite. | Receipt AB444403 seals 4,004 raw files, the exact 963-row ledger and portable archive. The ledger records 912 nonempty outputs without error diagnostics, six completed empty outputs, 38 task failures, two launched/incomplete profiles and five without an observed launch. The next production target is one coherent runtime341/74CC transitional image from accepted source, followed by the full raw OLD-to-NEW report. No complete NEW or API acceptance is claimed. |
| D32 | All three Terminal Services profiles encounter a native syntax error when the authored WTS_SECURITY_FLAGS group expands WTS_SECURITY_CURRENT_USER_ACCESS. The original macro lacks two bitwise-OR operators between continued operand lines. | Approve only those two operator insertions in the original header patch, preserving operands, macro structure, native contracts and every group fact. Record this as a native SDK syntax correction in the comparison. No numeric replacement, member removal or reader workaround. | Service handoff037 confirms the current owner. Its released 2e293c14 correction is composed as one-path 6e61eb9e, full patch3bc0997d/C7AD0ECA. Root authenticated the handoff and exact patch delta/bytes, retaining the coalescer's strict-source and two-token inverse evidence. Only this delta is admitted, without parked branch ancestry. Native replay remains pending. |
| D33 | All three WDS profiles reject the migration-only unsigned-int CPU_ARCHITECTURE forward because it has no native logical group. Root retains the synthetic JSON definition AMD64=9, IA64=6, INTEL=0 and both WdsCliInitializeLog::ulClientArchitecture and WdsCliGetImageArchitecture::pdwValue uses. | For the transitional image, remove only that forward and the two compiled AssociatedEnum prefixes from original wdsclientapi.h. Keep the JSON definition and both uses unchanged. Preserve ULONG/PDWORD, SAL, guards, the adjacent PFN_WDS_CLI_CALLBACK_MESSAGE_ID forward, and all other annotations. Do not invent native members, substitute PROCESSOR_ARCHITECTURE or relax validation. | Service c70fa045 is composed as one-path 0d1853d0, full patch39ba02bd/A1C7A895. Root authenticated the handoff and exact patch delta/bytes, retaining the coalescer's strict-source and three-edit inverse evidence. Only this hard-blocker delta is admitted over base4d. The group and two uses remain explicit sidecar dependence and unresolved source migration; no physical output equality or migration completion is claimed. |
| D34 | Fs rejects three SHARE_INFO_PERMISSIONS field associations after resolving migration-only ULONG forwards. The existing tagged-string resolver can defer an absent unqualified name. Sealed NetMgmt output on all three architectures contains the existing seven-member uint provider; provider participation in the failing Fs TU was not observed. | Remove only the three artificial scalar-forward blocks from original lmshare.h. Keep all three associations, native DWORD fields, SESSION_INFO_USER_FLAGS and unchanged lmaccess provider. Do not add includes, create a group or import older SHARE_TYPE metadata. | Network06ee7825 full patch2a2830e2/BA029044 is coalesced in 5cdecf2a. Root authenticated packet045, the exact delta and raw bytes; strict-source/inverse evidence preserves the rest of the applied header. The four-blocker SDK tree is exactly46724510. Native replay and final-provider composition remain unproved. |
| D35 | WeakReference has duplicate Resolve::objectReference ComOutPtr comments in the manual C++ path. The manual conditional closes before the second, common comment; its generated closing comment is misleading. Five profiles failed; WinRT/arm64 was incomplete, not an evidenced failure. | Delete only the first manual-branch ComOutPtr cpp_quote from original weakreference.idl. Preserve the second common marker, native manual/fallback/CINTERFACE signatures, SAL, templates and guards. Do not relax duplicate validation or edit generated headers. | Bridgeef91fae3 full patch118d0eb4/51345769 is coalesced in 5cdecf2a and admitted through authenticated packet045. The exact applied-source one-line inverse is retained. Common branch placement is static evidence, not new CINTERFACE reader or physical qualification. Primary owns affected MIDL regeneration and current-candidate replay. |

## API differences to retain

`GPFIDL_FLAGS` changes backing-field signature from UInt32 to Int32, and its
literal ConstantTypeCode changes accordingly. The three names, values, four-byte
raw payloads, nonflags/unscoped identity, and actual enum-typed parameter remain.
Explicit `AssociatedEnum` controls intentionally retain a primitive parameter;
that is existing emitter behavior, not a failure to support the logical group.

`SERVICE_NOTIFY` becomes `SERVICE_NOTIFY_FLAGS` as a logical enum. The real native
`SERVICE_NOTIFYA/W` records and selected `SERVICE_NOTIFY` alias do not change.
The logical rename must appear in the raw API diff.

`BCRYPT_OPERATION` retains the six OLD members and includes native
`BCRYPT_KEY_DERIVATION_OPERATION` (0x40) and
`BCRYPT_KEY_ENCAPSULATION_OPERATION` (0x80) only under their existing availability
conditions. They are additions to the OLD logical metadata group; whether they
reflect historical metadata omissions or an SDK-version change must be established
separately. Native `ULONG dwAlgOperations` with an explicit association now appears as uint plus
association in the actual generated C#, rather than OLD's actual enum parameter.
Final physical WinMD and managed projection effects have not been measured.

The authored `UPDFCACHE_FLAGS` source preserves all nine physical OLD members,
including their order and unsigned values. Native `DWORD grfUpdf` remains unchanged;
its source association is expected to expose the same enum-to-primitive metadata
representation difference. Its source is committed and ordinary ComOle output
contains all nine members; final physical signature grading remains pending.

Other expected differences, including selected-SDK surface changes, native enum
representation, and parameter-owned cleanup metadata, will be graded against their
specific evidence. They are not a blanket exemption for missing declarations or
incorrect annotations. Removed SDK APIs will not be recreated solely to match OLD.

## Remaining execution

1. Capture the frozen dd4/340 full-scrape result. Resolve any newly located common
   failures with affected-owner replays while preserving the original receipts.
2. Carry the bounded actual x64 GP/ASSOCF physical results into complete-image
   grading, and inspect the actual WMI owning projection rather than using Shell
   inclusion as projection proof.
3. Refresh later admitted source by header dependency and architecture. Regenerate
   the affected original-IDL outputs for the three new Flags scopes, retaining
   unrelated qualified MIDL outputs. Continue bounded API-sidecar retirements.
4. Qualify native-enum member transport and the selected-macro constant path.
   Active API-specific sidecars still prevent a header-only completion claim.
5. Emit a complete NEW WinMD, run the integrity tests including
   `NoSuggestedRemappings`, and compare exact OLD first and NEW second without
   suppressing differences. Classify
   each substantive gap as an intended representation change, corrected historical
   mistake, selected-SDK change, missing header fact, tooling bug, or unresolved
   decision. Preserve unexplained gaps rather than forcing parity.

## Evidence identities and handling

The complete OLD comparison input has SHA256
`EDF069849501B1B7B26C710686F8EDED701E71018F7F42EF35EF59489F93F5DC`.
The all-three-architecture GPFIDL proof packet has SHA256
`0BFCE2FD7A8CADF2848352F3F1D974265E6827EB52D9669DC859DBC97F50DC93`.
The coherent451 source handoff has SHA256
`781EFD545E50B04FB9FF202456C39CD29E00CB2D94B1CAF06F74BF2F932056C1`.
The actual runtime039/C8 Services and MenuRc positive-output proof has SHA256
`FC51D2ECFBB1604C3EEF8CEB5786988426DF5E760F318E5CF760389272BB6611`.
The corresponding Gdiplus and Hypervisor proof has SHA256
`CA2398AFBFE66C9A91F41F35474003AE8F7F3801E249BF06B07DD51630D9A822`;
the ComOle and Gdi proof has SHA256
`14D1EF7CEF2CD5AFF4CED7FBDAFF9A29AD4F9EF05D47E21BD32D8BD14FAB5054`.
The exact OLD OLE group/signature report has SHA256
`F5DC392AF9F74EEAEED475C00380AA629A354BD74C80745835E208EDEB3348CD`.
The actual Controls340/C8 positive-output proof has SHA256
`A9228011B89CC34C0F2DD4C8D5637575D7715AD23E9B2CA42BCDC926A80AA4B7`;
the final active cleanup-site proof has SHA256
`B0A3859E31DB7D6BD086F746FA2CA53D254C8C9EC52588DDE8B7A0A4159624EF`.
The seventeen-profile completion proof has SHA256
`E51909CB6E00C0E006045C5E1117A35FE551D278209AD3BEB4F21B4AD1146416`;
the CFU source-correction handoff has SHA256
`28D974B56C06515EC6E3E88A98BE465050F1CF474FEEE7AF6AE536E31BF3BE4A`.
The existing MetadataUtils.dll used for the constant-conversion probe has SHA256
`CAC2BB6D53C37758FBDD1D55156FAE64D41E4C8CC4934C8D0CFD27A2FD4300A9`.
The JSON-only CryptQueryObject retirement handoff has SHA256
`20290F0F3EA6CC881B3CC8F541E701161E5A3CDE72A17FA4F91D2DFDF384B606`.
The current source/config handoff has SHA256
`C1D222AFF6F3AE1027C58EA02043C215B6854090A92F958F9B16B1288F5D7663`;
the Flags-only source composition has SHA256
`CE85F217CA364140174538EA7C18CF09C20E883731D4FE7FB5F94AD1F7B5417C`.
The managed real-header constant probe has SHA256
`64FF4CBFB8845C89BAA6F6C7AEFAD80CA84912B5ABA58AE4EF4E4D1EF8A8633D`.
The exact18-row emitter RSP retirement handoff has SHA256
`12B45D2040BBBB04AACB83141ED97CF5BD4897FF9E4B67C64A737AD69B451698`;
its cumulative source/config handoff has SHA256
`9DABC1D58D2FE2B0B710937CC42AC73FBB03C8EAAA6233946E8ECA358BBB44D8`.
The corrected e160 SDK input manifest has SHA256
`3A1A3061EE4DA9C535C3B0FDADCE72F53FCC9185379286E21363B94051CB079D`.
The frozen dd4 SDK manifest has SHA256
`AF53377219DA0620E70321C90F65B3D4F670A7FB5A731D4886C71436324673E0`;
its full-scrape launch request has SHA256
`338FE4899F78DDEC2C8ECC7ABD1CF5BF7882455BFC583437FCDEBFA0F10E38BF`.
The MSI source composition handoff has SHA256
`C9FDE5AF32A0D78D2CF2D1236CF51B9BCA87665CF9527CF50A5316C7AD706041`.
The independent 26-return source handoff has SHA256
`B5BDB872F0A852C7F4AF1F2F2D2D0271413EEFE47FF1AA8BE29787491BF9F105`;
its coalesced composition handoff has SHA256
`E3A3E5085AFBFD63C593FDB101A51F89C03E8D8F5F5C02758F4A1BBFDB3E153A`.
The actual Shell/x64 GP and eleven ASSOCF physical proof has SHA256
`0F3817CA22C3D9821569BC359B8EA1F09957593B891F3D99F2D987BDB2EAAE08`;
its Test.winmd has SHA256
`0A596EE1071C1C7C3DF09581E7668722D8589628D4ED93DAC0E5EB9233820DD1`.
The reconciled two-IDL Flags composition handoff has SHA256
`CEA5058557BD8A2C926BE2EE9358E75FD18D825789CD1CE6582F6F0484DE5FEF`;
the VerSetConditionMask retirement handoff has SHA256
`CDF2E2D8E4FF5364F0C96BEC21E07BC776117D3C2F252A68D8FD33DB05252A7C`.
The cumulative source030 handoff has SHA256
`720FB9EF5C8C1EF3EDE2AD6D209443382517E5C97C5E3C377B79F792DE50D062`.
The one-line SetupAPI source correction handoff has SHA256
`1650BEB3A9095B36B0DF73422E63F5C72C5A0B19571F39D1579BB9041646D5CA`.
The cumulative source035 handoff, including Activprof source and the eight RPC
use retirements, has SHA256
`9744CABAB42E26DC5EF116F6AF9A974AAF153BFC7E9EA16A6E5CBDA200FB25C5`.
Frozen snapshot005 has SHA256
`C0FD177B3F562FF1E06E1D389E30B5E62CB1495D237D1ACA1CB49D2036B923DB`;
the located DXGI failure packet006 has SHA256
`AF6DC90186B231E6C7430F319A8709859BB411DCD38267650088B210EBDB5291`.
The completed 24-case native-enum/global-constant handoff has SHA256
`67CB3061CA6BF90C6D2E1B593571417A53FA2517F14143F571E909CB06E11CA8`;
its verified summary has SHA256
`B9A87BFBE7190D82FD086AFAA16A904B21EAC4E271B2B46851E3B8A3657F7670`.
The reviewed proposal has SHA256
`7A3695606DA1EBF8D8553038E10963F57D5BCB7A39FD0F275B382C365E638D33`;
its optional EnumMember family is not approved.
The completed read-only DXGI diagnosis has SHA256
`11D0B34EFAEEBD8E2592F1E66F4BA13A7B43CAA0062DE12B2B39094256A05B59`.
The diagnostic observation stop has SHA256
`17CC943B1C5A739A04ACD6E9484569B3A8725926285B6D3B87A7F2AC1927EE0B`.
The selective AssociatedConstant successor handoff has SHA256
`719F9C4946627EB362AC9F9492E26EC650E9AB7352D20E601B4665581E749B8B`;
its 486-file runtime manifest has SHA256
`9689B5EB1209607430D17E56C72887AAD065C9751836FC049D0FC5AFC3058C5C`.
Its executed test-results file has SHA256
`73916C36D709CDED56CDA9322AE84FEA5FE88CE02D77C562857A13327AC1460B`;
the 18-pair physical verification has SHA256
`60968DF818F97570E96E47D6C75D1D11E6438CCF7C8A2757158A641CEFC09410`.
The resumed source036 handoff has SHA256
`4498758B6C3EB3436931F0CB8448CD10E8B2BA386801FAA3069878BA88C22E5D`.
The sealed interrupted-run receipt has SHA256
`AB444403A4D3E3EF56934FA31C4FB161E325E189FFF9E392B9DA73AE14EE6D72`;
its final 963-row profile accounting has SHA256
`7209A16B01FD71FE0AE4DB25E2ACB0A7F49FE128F92C7A2FE691B89EBC5752CA`.
The finite first-image source039 handoff has SHA256
`BB0FCDE00A4C03638E5C42E6439D00404E7A9C63689F556D95F0C5CEA35B7625`.
The independently released WTS hard-blocker handoff has SHA256
`7B0DD8712F343AF58977A5F77D03A3DF705688CEAAC061CF469F418F14AC16C3`;
the WDS hard-blocker handoff has SHA256
`0C91B5BDB4F9227BF2DBD27F28E2612D0C4093F35112363F29B4CF971ED93A01`.
The finite four-blocker source packet045 has SHA256
`DC43B4516E554347F42C0DE51CE40652664121441E30F7801489D684162C19D6`;
the final Fs/WeakReference source diagnosis has SHA256
`3F1D2B468AB6475A36B4C8BC0E4EC542D3752078326AD137EBC1D8BA20BC136A`.
The single original-TU DXGI diagnostic snapshot has SHA256
`FA2FBF49AE2C42510C4E6E15A2A0AC66DE97A04A16F7F97F8C67D0773F21BFEF`.
Its sealed one-observation receipt has SHA256
`4CB5642C59D289AD7A3453A9581CD71DF7995963A09C0EA0EC4FB87D5BD09BB3`.
The finite five-source packet047 has SHA256
`F466563C6C338665A35D066FF219575E7A447EF443F98FA0961EA41B41710728`;
its SDK tree is `9d5a9670830834fe2ceb7031d77ad90d75541a7f`.

Source checks, reduced representation proofs, ordinary partition execution, and
complete-image acceptance are separate claims. No successful earlier receipt is
relabeled as execution of a later source composition or runtime.

Raw SDK patch assets and OLD-to-NEW differences are retained, including exact
patch context whitespace. Git checkout changes JSON line endings between some
worktrees; committed Git objects and normalized source content are verified
separately from physical file hashes. Original physical-byte receipts are not
rewritten to conceal that distinction.

The [migration playbook](plans/header-annotation-migration-playbook.md) and
[shift-left spec](plans/shift-left-annotation-spec.md) define the source ownership
and annotation contracts used by these decisions.

## Incremental complete-SDK compilation repairs

The complete native preparation now succeeds using the installed PowerShell:
256 actual MIDL invocations produced 256 complete outputs with 472 actual
preprocessed inputs. PowerShell installation files are not preparation inputs.

The first compilation exposed a migration-added forward declaration for
`PROCESS_AFFINITY_AUTO_UPDATE_FLAGS` using `unsigned int`, while its existing
native `DWORD` carrier uses `unsigned long`. The authored `processthreadsapi.h`
patch now uses `unsigned long` consistently. Actual ordinary Backup scraping
passes on x86, x64, and ARM64.

Com defines `NONAMELESSUNION`, which names the native VARIANT wrapper fields.
The comment selector `VARIANT::vt` therefore cannot identify its discriminator.
Original `oaidl.idl` now annotates the actual field:

```idl
[annotation("_Win32_AssociatedEnum_(VARENUM)")] VARTYPE vt;
```

Actual MIDL preserves that annotation on the generated field. All 217 outputs
whose own preprocessing reads `oaidl.idl` were regenerated; the other 39 accepted
outputs were retained unchanged. The complete actual preprocessing union remains
472 inputs. The actual ordinary Com profile now succeeds with its existing
`NONAMELESSUNION` configuration. No generated header, native layout, or field
resolver was changed to accommodate the selector.

The selected SDK defines Hypervisor emulation using x64-only native types.
The partition now includes `WinHvEmulation.h` only for AMD64; its other headers
remain included on their native architectures. Actual Hypervisor scraping
succeeds on x86, x64, and ARM64.

VirtualDiskService needs both `vds.h` and `vdshwprv.h`. The preparation recipe
omitted the latter's original MIDL producer and four shipped original-IDL inputs.
Those inputs, the output, and its admitted header are now configured. Fresh
ordinary MIDL emits the existing shared declaration guards and all four private
interfaces with their original OS floors. The complete native composition now
has 257 outputs and 476 actual preprocessed inputs.

The subsequent complete SDK run successfully scraped all 321 partitions across
395 native profiles. Ordinary no-reference emission then stopped with CSSW003:
`IOCTL_CDROM_UNLOAD_DRIVER` references `IOCTL_CDROM_BASE`, whose native definition
aliases `FILE_DEVICE_CD_ROM`. The constants scraper had discarded that alias
because it encountered the numeric provider later. It now resolves pending
aliases after visiting all headers, including transitive aliases, without
replacing already emitted definitions or inventing cyclic or absent providers.
Regression coverage compiles the resulting CTL_CODE and checks its exact type
and value in both header orders.

The regenerated constants preserve all 100,540 previous declarations, namespaces,
types, and expressions, and recover 169 native aliases. The next emission exposed
`FO_TYPE_RASTER` in Display referring to `RASTER_FONTTYPE` in Gdi. The emitter now
binds an unresolved simple constant alias only when its current profile contains
one actual matching `Apis` constant. Existing bindings and ambiguous names are
left intact; no values or providers are supplied. Physical regression cases cover
signed, unsigned, and string alias chains, native-profile values, ambiguity,
existing bindings, overflow, and common-source variation. All 253 emitter cases
pass; the five previously failing regression rows are retained separately.

A separate x86 diagnostic run retained the first 10,000 declaration errors, the
CLI's reporting limit. Shared native typedefs appeared in partition-local
namespaces and became ambiguous in combined bindings. Existing global namespace
routing now assigns `BOOL`, `BOOLEAN`, `CHAR`, `HANDLE`, `HRESULT`, `NTSTATUS`,
`PSTR`, and `PWSTR` to their established Foundation identities before composition.
Their native annotations, storage, and original header owners are unchanged.
The common scraper header also no longer imports the unproduced Hlsl namespace.
This shared-header change requires freshly generated bindings; it is not applied
by editing previously generated C#.

A fresh complete run with that shared header again successfully scraped all 321
partitions and 395 native profiles. Ordinary emission then reached
`D3DRTYPECOUNT`, whose actual native expression is `D3DRTYPE_INDEXBUFFER+1`.
The provider is a member of the original `D3DRESOURCETYPE` enum. Scalar constant
expressions now bind unique actual `Apis` constants and enum operands from their
current native profile. Enum operands use their actual underlying integral
storage, and the result retains the constant's declared storage. Ambiguous or
missing providers, overflow, and common-source value variation remain errors.
Explicit unchecked arithmetic remains unchecked.

Duplicate-constant removal also now respects namespace and containing-type
identity. An enum member must not erase a distinct constant from another native
scope before binding. The retained pre-fix control has 16 failures and four
passes across 20 new cases. The complete corrected emitter suite passes all 279
cases, including two additional nested-type and file-scoped-namespace controls.
The fresh scraper suite has 1,626 passes, two original-IDL coverage failures, and
161 skipped cases; those two source holds remain unwaived.

These native repairs and partition results do not establish complete WinMD
integrity or OLD-to-NEW equivalence. The complete SDK compilation and its raw
comparison remain the acceptance boundary.

### SDK017 composition failures

SDK017 regenerated constants successfully but stopped during cross-architecture
emission with CSSW003 on `UPNP_E_ROOT_ELEMENT_EXPECTED`. Its independent ordinary
x86 diagnostic control reported 2,152 C# compiler errors, below the 10,000-error
reporting limit. These are generated-declaration composition errors, not native
header compilation failures or OLD-to-NEW differences. Both attempts preserved
their retained native inputs and produced no accepted image.

The local emitter successor records native enum identities before and after
namespace routing, so moving a logical enum does not leave its original loose
constant copies behind. `HPROPSHEETPAGE` and `SC_HANDLE` also receive their
established global namespace routes. These routing settings are consumed by the
constants scraper and emitter, not native header scraping.

The same successor lowers integral header-native-typedef constant declarations
and casts to their actual `Value` storage for intermediate C# compilation.
`NativeTypeName` preserves the declared native typedef in physical metadata.
This addresses generated `const HRESULT` declarations without changing the SDK
typedef, adding conversion operators, or replacing native values. Conflicting
storage, unsupported conversions, missing type-preservation attributes, and
overflow remain errors. The complete local emitter suite passes 288 cases;
full-SDK qualification of these changes remains outstanding.

Historical source at `389dfa3f` establishes several exact compensations that were
not visible in the post-retirement HEAD:

- `manual\Wmp.cs` supplied WMP base expressions such as
  `DISPID_WMPCORE_BASE + DISPID_DELTA`.
- `manual\NativeWiFi.cs` supplied WLAN base, range, and connection expressions.
- `manual\Controls.cs` supplied `NM_FIRST = 0` and its unsigned derived values.
  The constants configuration excluded `NM_FIRST` to avoid that handwritten
  provider. The stale exclusion has now been removed; recovery of the unsigned
  derived expressions now has native compiler coverage described below.
- `ConstantsScraper.settings.rsp` forced `SQL_DIAG_SS_*` to `int`, compensating
  for unsigned inference on negative signed-base arithmetic.
- `autoTypes.json` supplied the integral `HRESULT` native typedef wrapper.
  Header-owned typedef projection must preserve that metadata identity while
  producing legal intermediate C#.

The selected native WMP and WLAN expressions are valid; they do not require
rewritten SDK definitions. The failed regex arithmetic reproductions motivated
the native implementation below. Their cases now run against actual compiler
output, including signed types that the old unsigned-default expectations got
wrong.

The subsequent direction authorizes implementing the generic repairs and
continuing through the full SDK, with the combined header and tooling changes
reviewed afterward. The earlier requirement to stop before implementing macro
recovery no longer applies. Authoritative SDK definitions and original IDL remain
the source of API facts.

### Clang-native integer recovery

Native Clang type and value extraction replaces regex arithmetic for the SDK's
integer macros, using the libraries
already pinned in `sources\Win32MetadataScraper\Win32MetadataScraper.csproj`:
managed ClangSharp 21.1.8.4, libclang 21.1.8, and libClangSharp 21.1.8.2.
No native-library upgrade is needed to evaluate integer expressions.

The header reader in the Rust pipeline is `windows-clang`, not
`windows-bindgen`. PR #2303's manifest pins
`jevansaks/windows-rs@3be3d29b2fc7ed974b46523acf5deda3c1ab5325`.
Its extractor selects object-like macros, checks active definitions, appends
typed declarations such as `const auto __clang_eval_NAME = (NAME);` to the
original source, and reparses with the original compiler arguments. It reads
the resulting native type and calls `clang_Cursor_Evaluate` for the value.
The pinned implementation separates [probe construction](https://github.com/jevansaks/windows-rs/blob/3be3d29b2fc7ed974b46523acf5deda3c1ab5325/crates/libs/clang/src/extract.rs#L5133-L5152)
from [typed value extraction](https://github.com/jevansaks/windows-rs/blob/3be3d29b2fc7ed974b46523acf5deda3c1ab5325/crates/libs/clang/src/extract.rs#L5155-L5253).

Macro definition cursors are preprocessing records, not typed initializer ASTs.
ClangSharp's existing macro mode synthesizes initializer declarations and
normally translates the expanded expression to C#. It does not guarantee folded
literal output. In the pinned managed source
`da7e208a2788186726f56aa1c6ef1b86de355a48`, its [macro visitor](https://github.com/dotnet/ClangSharp/blob/da7e208a2788186726f56aa1c6ef1b86de355a48/sources/ClangSharp.PInvokeGenerator/PInvokeGenerator.VisitPreprocessedEntity.cs#L11-L61)
copies historical replacement text, rather than probing the live macro name.
General recovery must not resurrect undefined macros or choose an arbitrary
definition from a redefine sequence.

The bounded direct native proof is now executed, rather than inferred from
translated C#. `artifacts\clang-native-constant-proof-030\Invoke-AstProof.ps1`
uses the existing runtime008 Interop assembly and libclang with normal installed
PowerShell. Its `native-ast-evaluated-values-003.json` records nine completed
cases and 72 checked type-width, signedness, and numeric results across x86, x64,
and ARM64:

- A reduced SDK-expression fixture in its original macro form.
- The same fixture with the explicitly permitted `WIN32METADATA`-guarded
  `constexpr int SQL_DIAG_SS_BASE = -1150;` alternative.
- The actual selected SDK `wmpids.h`, unchanged by this proof.

On every target, WMP controls is signed 32-bit `50`, the WLAN connection base is
signed 32-bit `163840`, SQL severity is signed 32-bit `-1151`, and `NM_CLICK` is
unsigned 32-bit `4294967294`. The proof also checks U/LL/ULL typing and
`18446744073709551615` through the unsigned 64-bit accessor. The two real WMP
header values are `50` and `800`, both signed 32-bit. Native compile diagnostics,
integer evaluation result kinds, and supported extraction widths are checked
before accepting values. These are bounded native extraction results, not a
complete SDK scrape, generated-C# readback, or physical WinMD qualification.
The initial response-file matrix stopped at unsupported `--target` parsing and
does not supply any native architecture evidence.

Header-native signedness is permitted to differ from the old scraper's unsigned
default. Preserve those differences in the raw comparison. An explicitly typed
metadata-only header constant is permitted where needed.
The two SQL fixture forms agree without a production header edit.

The removal of the `NM_FIRST` exclusion has its own passing source-ownership
regression in
`artifacts\native-notification-base-recovery-031\ownership.trx`. That attempt's
`utility.trx` retains the original regex overflow failures. The replacement
computes unsigned wrapping in Clang and writes the resulting literal; it does
not qualify or extend the old arithmetic path.

HRESULT constants remain supported in WinMD. The existing emitter already
combines a native-typedef field signature with an integral Constant-table
payload. The local lowering repair only restores legal intermediate C# after
header-owned typedef preservation exposed `const HRESULT` and HRESULT casts to
the C# compiler. Native recovery must retain the nominal typedef independently
of canonical scalar storage; permanently emitting an `int` field is not the
intended fix.

All supplemental API-specific C# files under `generation\WinSDK\manual` are
already retired. The remaining `Metadata.cs` defines metadata infrastructure
and is not an API provider. Definitions without an authoritative header recovery
path still require review; `FSCTL_DFS_BASE` remains unresolved.

The production scraper now probes live macro names in their actual compiler
environment. In C++, `constexpr auto` also rejects invalid constant expressions,
including signed overflow and division by zero. Each accepted value records its
native type, scalar storage, literal, header, and definition line. Other results
retain their reason and native diagnostics. Associated enum constants use the
same extraction rather than a separate C# expression translator.

The SDK task obtains integer values for x86, x64, and ARM64 even when ordinary
declarations are shared through `common`. The constants stage writes separate
source families for those targets. It runs again after separately scraped CI
assets are combined, and tracks added, changed, and removed compiler outputs.
It resolves relocated prepared-header paths when artifacts move between jobs.
The existing GUID, string, and resource handling remains in place.

`artifacts\native-constant-pipeline-046\native-pipeline.trx` records 65 passes and
two selected-SDK-input skips. Its physical WinMD cases check HRESULT signatures
with Int32 payloads, UInt64 maximum, unsigned wrapping, exact architecture masks,
repeated generation, and preservation of GUID/string/resource providers.
The utility suite passes 86 cases. The generic type-provider repairs also have
their own 36-case isolated result under `artifacts\bounded-native-type-providers`.
These are not full-SDK integrity or equivalence results.

The corrected real-SDK extraction control under
`artifacts\native-sdk-macro-control-045` recovers 10,141 integers across WMP,
Native WiFi, UPnP, Direct3D9, and Foundation. The preceding control passed CLI
options where response-file paths were required and did not exercise native
extraction; its zero counts are not a successful result. Its ten earlier binding
outputs still match their recorded hashes.

### Full SDK018 run and corrected successor

SDK018 requested all 321 partitions and 963 native integer contexts, using
Source020 and Runtime009. It produced 954 native context files. Bluetooth, Hid,
and WinHttp each failed on all three targets because Clang did not expose a
source record for an active macro restored with `push_macro` / `pop_macro`.
The failure names were `AF_BTH`, `HIDP_STATUS_I8242_TRANS_UNKNOWN`, and
`INTERNET_DEFAULT_HTTPS_PORT`. No complete NEW image was produced.

An evaluable macro without that source record is now recorded as unsupported
instead of aborting the partition. The extractor does not guess which historical
definition owns it. An existing header declaration can still supply the constant.
The new tests cover both the presence and absence of that declaration.

The old include validator also rejected the bare traversal name `excpt.h`.
It now resolves bare traversal filenames from the actual compiler output before
applying the existing include-root checks. The retained SDK018 outputs resolve
it to the selected MSVC header, and all 963 emitted response files pass those
checks. This does not change SDK018's failed generation result.

Additional controls exposed an overly broad enum-expression repair: it could
accept an unresolved ordinary enum member or an invalid enum-to-integer C#
conversion. Special scalar conversion is now limited to header-defined logical
groups. Ordinary enums must bind and convert legally. Native enum arithmetic,
including promotions and wrapping, is evaluated by Clang before C# emission.

The current native extraction tests pass 16 cases, and the complete current
emitter suite passes 290 cases in `artifacts\native-toolchain-final-055`.
BuildTools also builds with the corrected native-only success/failure handling.
The earlier complete scraper result in `artifacts\native-toolchain-suites-050`
has 13 failures; eleven have focused fixes, while the two original-IDL coverage
holds remain unwaived. That earlier full result is not green.

Source021 and Runtime010 capture the corrected tools for a fresh SDK019 run.
All 4,219 header-preparation source inputs still match the retained preparation,
so the actual MIDL outputs and prepared headers are reused without changing them.
SDK019 starts from fresh generated output and does not use OLD as a compiler
reference.

### SDK019 compiler-target correction

SDK019 completed all 395 ordinary binding outputs and all 963 requested native
JSON outputs in 1,242.694 seconds. Constants composition then rejected conflicting
`CONTEXT_ALL` values from `winnt.h`. The conflict check was correct: the ARM64
response file defined `_ARM64_` but still compiled with the host's x86-64 target.
Its ARM64 value, `4194527`, was therefore incorrectly recorded as x64 alongside
the actual x64 value, `1048607`.

The audit in `artifacts\coherent-full-sdk-019\actual-run-measurements.json`
records all 963 outputs and the 321 architecture mismatches. Those files are
completed extraction attempts, not evidence of three actual native compiler
targets. The artifact also retains each observed task interval from response-file
writing to captured tool output. These intervals include process startup and
writing; they are not CPU measurements or CI performance limits.

Each architecture response file now explicitly selects its native Windows MSVC
target. A regression uses the real shared, width-specific, and architecture
response files, then checks compiler-derived architecture and pointer width.
Its pre-fix control fails on ARM64. With the corrected settings, all 19 native
extraction tests pass in `artifacts\sdk-native-target-regression-057`.
The unsuccessful intermediate response-file syntax is retained separately.
The constants conflict check has not been relaxed.

The complete scraper result in `artifacts\native-toolchain-full-056` is 1,683
passes, two original-IDL coverage failures, and 163 skips across 1,848 cases.
It ran before the target correction and the new performance tests. The two
remaining source holds have not been removed or waived.

SDK020 uses Source022 and Runtime011 with fresh output for all 321 partitions.
Its response files select actual x86, x64, and ARM64 compiler targets.

### SDK020 constants and XML header coverage

SDK020 completed all 395 binding outputs and all 963 native integer outputs.
The constants stage completed, including the previously conflicting `CONTEXT_ALL`
values. Complete WinMD emission then failed with CSSW003 on
`DISPID_XMLELEMENTCOLLECTION_LENGTH`.

The MsXml partition listed `msxml6did.h` and `msxmldid.h` for traversal but did
not include them in its translation unit. Traversal selects declarations to
emit; it does not include headers. The actual native output contained only six
integers and named only `msxml.h` and `msxml6.h` as its macro headers. Dispatch-ID
expressions therefore still reached the old text-based constants path.
The partition now includes both dispatch-ID headers explicitly.

Source023 and Runtime012 capture this change. SDK021 recovered 551 native XML
integers on x86, including signed `int` values 65537 and 65539 for the collection
length and item IDs. Its orchestration script then constructed a remap filename
with an extra period and stopped before composition. The failed attempt and
its native output are retained.

SDK022 uses the same captured inputs with the orchestration path corrected.
Its incremental runner checks the source changes and production runtime before
reusing SDK020's other 960 native contexts. It regenerates the three MsXml
contexts and requires the ordinary declarations and discovered type remaps to
remain unchanged before retaining the complete global remap files. Constants
and complete cross-architecture emission then run again. This is a recorded
incremental continuation, not a new claim that all 963 compiler processes ran.

SDK022 completed that continuation after correcting a second orchestration
assumption: native-only profiles intentionally do not emit type-remap files.
All three XML contexts recovered 551 integers each, with unchanged declaration
and remap output. All 963 actual response files passed the include checks.
Emission then reached a new CSSW003 failure on `SPEAKER_MONO`.

The Xaudio2 partition had the same missing-include problem with `x3daudio.h`.
It now includes that header. DirectXMath's optional SIMD implementation required
Clang resource headers absent from the existing scraper setup; the partition
selects its supported `_XM_NO_INTRINSICS_` mode to parse the exported scalar
declarations instead. The first failed native control and the corrected
three-target control are retained under `artifacts\native-x3daudio-recovery-001`
and `artifacts\native-x3daudio-recovery-002`.

The corrected control recovers 162 integers per target, including signed
`SPEAKER_MONO = 4`, and generates the actual X3DAudio structures and imported
functions. Its discovered type remaps are byte-identical to the earlier complete
run, so the complete global aggregates remain reusable.

### Performance regression guards

A separate implementation agent added six always-on performance tests for
included-header annotation scanning, irrelevant macros with zero and one
selected constants, batched native integer extraction, three-architecture
composition, and a large constant file. Each checks its output, warms up, then
enforces a median budget across five measured runs. The budgets and calibration
are documented in `docs\generationOptions.md`.

The first five passed through the ordinary test runner while SDK020 was running.
`artifacts\performance-default-run-058\performance.trx` retains that result.
All six subsequently passed through the ordinary runner in
`artifacts\performance-default-run-062\performance.trx`.

The agent also measured repeated compiler diagnostic work for every constant
initializer. The emitter now collects diagnostics once per file and profile,
then checks the relevant source spans without repeating compiler work.
For 6,418 constants across three profiles, its measured median fell from
20,167.9 milliseconds to 1,370.1 and 1,568.7 milliseconds in repeated isolated
runs. The new guard enforces a 4,000-millisecond median. The ordinary runner
recorded 1,358.4 milliseconds. All 303 emitter tests pass, including thirteen
new cases preserving initializer-error and source-span behavior.

The complete SDK020 emitter also recorded 65.27 seconds moving namespaces and
63.72 seconds cleaning syntax trees. Its output was buffered by the task;
the absence of live log lines was not evidence that emission had hung.
The all-context audit in `artifacts\coherent-full-sdk-020\actual-run-measurements.json`
finds no architecture mismatches. Its observed x86/x64 task medians are
28.95/9.59 seconds, compared with 32.42/10.97 seconds in SDK019. These concurrent
task intervals are observations, not CI budgets. The earlier ARM64 timings are
not comparable because that run used the wrong compiler target.

A complete NEW image, actual integrity results, and the unsuppressed OLD-to-NEW
comparison remain outstanding.

### SDK023 string constants and 1394 namespace

SDK023 retained the complete generated graph, regenerated the three Xaudio2
contexts, and validated all 963 actual include environments. Complete emission
then stopped on `wszREGKEYNOSYSTEMCERTSVCPATH`. Its header concatenates a
`TEXT(...)` literal with another string macro. The old string writer removed
the opening wrapper and copied the remaining C++ expression into C#.

The constants scraper now translates adjacent literal and identifier terms into
C# string concatenation. It recognizes narrow and `L` literals, `TEXT`,
`__TEXT`, and `_T`, including identifier-first expressions and forward references.
Identifier terms must remain strings; they cannot acquire C#'s numeric-to-string
formatting behavior. Unsupported arithmetic is reported with the macro name and
header path. The ANSI encoding attribute also had a missing closing parenthesis;
that generic writer defect is fixed.

An audit of the 1,709 original generated sources found 1,343 syntax errors,
including 1,319 missing-parenthesis errors and invalid
`Windows.Win32.Devices.1394` namespaces. The partition default now uses
`Windows.Win32.Devices`, where the exact OLD places its two public request
structures. No generated C# or SDK declarations were edited for this correction.

The complete utility suite passes 103 cases. The added string cases compile the
generated constants and check their values and encoding, including escaped quotes,
backslashes, empty literals, forward references, and rejected numeric operands.
The failed controls and passing results are retained in
`artifacts\native-string-concatenation-regression-064`. BuildTools also builds
without warnings or errors.

### Complete-SDK semantic repairs

The subsequent constants control finishes with 1,712 original generated C# files
and no syntax errors. Combined compilation reports 202 diagnostic lines but only
101 distinct errors: 88 HRESULT enum casts, eleven missing native types and two
duplicate declarations. The raw log is unchanged; the deduplicated inventory is
retained in `artifacts\sdk-semantic-repairs-067\unique-errors-before.json`.

The emitter now lowers enum initializer casts through the integer storage of
header-defined native typedefs. Physical metadata retains the native typedef
identity. Identical ordinary partial data records from different inputs can also
compose after namespace assignment. Both syntax and semantic bindings must match,
including field types and attribute arguments. Different partial members and
conflicting definitions remain compiler errors. This handles the SDK's repeated
complete `HSTRING__` dummy record without inventing a replacement record or
editing generated MIDL headers.

Existing native globals own their generated names, preventing duplicate loose
constants. Mutable globals are not constant-alias sources. The first full-SDK
rerun exposed this distinction with `MMC_TEXTCALLBACK`: its native target is a
mutable pointer variable, not a constant. The inventory now records mutability in
the same source walk, and unsupported aliases report their macro, target and
header. Pointer, integer and string regression cases also preserve real constant
aliases. Exact OLD contains `MMC_IMAGECALLBACK`, but neither `MMC_CALLBACK` nor
`MMC_TEXTCALLBACK`.

The authored `cfapi.h` patch selects its existing C USHORT typedef representation
under `WIN32METADATA`; normal C++ retains the SDK's helper classes. Four obsolete
helper-type exclusions are removed. All six actual native controls pass: normal
C++ and metadata modes on x86, x64 and arm64. They check helper size/alignment and
both policy structs' size, alignment and member offsets. Metadata fields remain
USHORT with all four enum associations, and all six native integers are unchanged
on every target. Preparation changes only authored `um\cfapi.h` among 3,443
prepared headers; no generated MIDL header is patched. Inputs and results are in
`artifacts\cfapi-c-abi-control-068`, with the passing controls in `attempt-004`.
Earlier control setup failures remain preserved.

The complete emitter suite passes 315 cases and the utility suite passes 120.
These bounded results do not establish a complete NEW image, integrity result or
OLD-to-NEW comparison.

The separately implemented six performance guards also pass after these emitter
and scraper changes through the normal runner (`performance-default-run-069`).
The opaque-pointee repair passes eighteen focused and 140 existing cases, six
actual SDK replays, and bounded physical WinMD checks on all three targets.
It uses Clang's completeness and source-scope facts; complete backing records are
not erased. UI Animation's backing record is complete, so its obsolete exclusion
is removed and the real native integer field is generated.

The next emission-only control reused stale constants because the incremental
task did not track its own executable, helper library or generated source header.
All six changed/deleted-input regression cases fail before the correction and
pass afterward. Those producer inputs now invalidate the constants marker, so a
tooling repair cannot leave the old generated alias in place.

### Complete SDK image and validation

SDK026 produces the first complete, freshly generated NEW image from Source027
and Runtime016. The run finishes in 27 minutes 57 seconds with all 395 ordinary
binding files, all 963 native integer contexts, and all 963 include environments
validated. A separate check reads every native result's architecture mask and
confirms the requested x86/x64/ARM64 targets: 1, 2, and 4. No earlier generated C#
is reused and exact OLD is not a compiler reference.

The image is `artifacts\coherent-full-sdk-026\image\Windows.Win32.winmd`, SHA256
`33F0C23AEEE8ADC21A79BDED815438568D0CD0CEFE089DCE35DC9641B3C3BE89`.
The unsuppressed OLD-to-NEW comparison completes and retains its 29,571,494-byte
log. A completed build does not establish API equivalence.

The initial integrity deployment omitted the six existing test assets and
pointed the remapping check at the frozen source instead of the actual scrape
logs. Separate deployments preserve that original failure and validate the same
unchanged image with the original asset bytes. No allowlist entries are added.
Interface layout discovery then runs successfully; the complete suite contains
14 cases, rather than the initial 11.

The integrity tools also needed two generic corrections. Constant variants with
the same owner and exact name are valid when their architecture masks do not
overlap; the old checker reported 434 such groups as duplicates. Different owners,
case-only collisions, and overlapping masks remain errors. The architecture
checker inspected x64 record fields while checking ARM64 consumers. It now
follows each matching native type variant. Method parameter failures affect the
exit code, and method and delegate return types are checked. Five physical
regressions fail before these corrections; all nine integrity fixtures pass
afterward, including rejection cases and recursive delegate signatures. The
complete emitter suite passes 324 cases and the utility suite passes 120.

The qualified actual-image run in `artifacts\actual-sdk-integrity-074` has nine
passes and five failures, with no skips. Architecture integrity passes without
changing the image. Remaining reports include three duplicated backing-record
groups, 1,439 constant-name groups with different owners, nine suggested
remappings, two Speech pointers to delegates, and namespace cycles. These are
unresolved findings, not waived differences.

The six performance guards still have the passing combined-tool result in
`artifacts\performance-default-run-069`. Its large 6,418-constant case has a
1,333.7 ms median against the 4,000 ms failure budget. Full-SDK elapsed time is
recorded separately; it is not a replacement for those isolated regression
budgets. Original-IDL coverage holds and the two previously recorded full-scraper
failures remain open.

### Initial grading of the complete image

The raw comparison contains 170,964 differences. The inventory is complete;
source-backed review of every difference is not. Of these rows, 112,334 remain
unreviewed. The original log, OLD, NEW, and frozen producer inputs remain
unchanged. Detailed evidence and proposed repairs are recorded in
`artifacts\actual-sdk-review-073`. At that grading point, no repair in this table
had been implemented. The subsequent Unicode context decision is recorded below.

| Finding | Proposed change for discussion |
| --- | --- |
| The existing original `hstring.idl` patch is absent from the active preparation recipe. HSTRING and HSTRING_BUFFER lose their named typedef identities. | Admit that patch and regenerate its affected MIDL outputs. Do not edit generated `hstring.h` or recreate a handwritten wrapper. |
| Four HSTRING marshaler OS-version attributes survive into generated C# but disappear from the physical WinMD. | Reproduce the loss in a small composition/emission case and fix the stage dropping the existing attributes. Another header annotation would not fix this loss. |
| Nineteen buffer parameters lose ContainsInteriorPointers; their original Winsock, security, and service headers lack the annotations. | Restore the facts on the exact native buffer parameters after reviewing their storage contracts. Preserve the native types, SAL, and counts. |
| The comparer omits a separate constant-value report when the field type also changes. Physical readback identifies 4,652 additional integer identities needing value or signedness review. | Compare field signatures and constant values independently. Keep raw bytes, signedness, width, numerical values, and architecture variants visible. |
| 101 neutral Controls aliases change from their W values to their A values, matching the original NEW image's native compilation context. | The production SDK now defines UNICODE for both declarations and native constant evaluation, preserving OLD W-valued neutral aliases. The original ANSI-valued image and raw observations remain unchanged; see the bounded proof below. |
| Queue-status constants now include the native touch/pointer bits selected for modern Windows targets. | Establish the OLD producer's target context before deciding whether these are intended native-context corrections. Do not restore old numbers with overrides. |
| Retained parameters and some named handle/type namespaces change independently of the accepted enum and cleanup policies. | Review the affected lifetime contracts and intended namespaces separately. RAIIFree relocation does not approve a changed handle identity. |

Documentation-only changes and the intentional Agile retirement remain visible
in the inventory. They do not approve other changes on the same declarations.
There is no complete API-equivalence or migration-acceptance claim.

### Production SDK Unicode context

Production SDK parsing defines `UNICODE` on x86, x64 and Arm64 through the shared
`generation\WinSDK\scraper.settings.rsp`. The original header parse, any separate
declaration-only parse, ordinary native integer extraction and selected macro
recovery receive the same effective Clang arguments. Native probes add only
their existing error-limit option. No individual constant or header is rewritten.

The scraper CLI does not impose this default on custom contexts. Explicit ANSI
contexts remain supported, including a later `-UUNICODE` after the SDK settings.
This decision selects neutral numeric aliases; it does not change Unicode
custom-attribute retention, native string types, ABI or storage policy.

Fresh production Shell and Controls scrapes pass for all three architectures
with native integer evaluation enabled. They use the selected SDK28000 API
headers, the repository-standard VC include environment and the existing
compiler pins. The actual compiler-context receipts retain the response-file
order and hashes, effective Clang arguments, include environment and native
result hashes. All six contexts contain `-DUNICODE` and the expected target:
`i686-pc-windows-msvc`, `x86_64-pc-windows-msvc` or `aarch64-pc-windows-msvc`.
The real SDK parses also retain `CreateFileA`, `CreateFileW`,
`WIN32_FIND_DATAA` and `WIN32_FIND_DATAW`.

| Actual fresh native constant | x86 | x64 | Arm64 |
| --- | --- | --- | --- |
| SHCNF_PATH / SHCNF_PRINTER | 5 / 6 | 5 / 6 | 5 / 6 |
| SHCNF_PATHA / SHCNF_PRINTERA | 1 / 2 | 1 / 2 | 1 / 2 |
| SHCNF_PATHW / SHCNF_PRINTERW | 5 / 6 | 5 / 6 | 5 / 6 |
| LVM_GETITEM | 4171 | 4171 | 4171 |
| LVM_GETITEMA / LVM_GETITEMW | 4101 / 4171 | 4101 / 4171 | 4101 / 4171 |

The regression fails on all three targets before the default is defined. Its
header-parser enum values, native probe values and physical WinMD constants now
agree. Twelve fresh physical images cover SDK defaults with and without header
annotations, custom ANSI input and explicit ANSI opt-out on all three targets.
Both A/W functions and records survive every context, with narrow/wide parameter
and field types unchanged; native size, alignment and offsets are checked too.

The real-header control also exposed native evaluation passing preprocessing
cursors to ordinary binding generation when header annotations were disabled.
That case now uses the same declaration-only binding path as annotation mode,
without enabling annotations or general macro binding. Its separate failing
control is retained. The combined native/recovery/selector/performance run passes
52 tests with no skips; all six performance guards remain unchanged.

Evidence is retained in `unicode-production-partitions-final`,
`unicode-effective-native-context-receipts.json`, `unicode-context-physical-final`
and `unicode-default-regression`. These bounded results do not qualify a complete
new SDK image. The upper layer must inherit the tooling successor and freshly
scrape declarations and native results before complete emission. Preparation,
MIDL helpers, recipe and SDK pins are unchanged. Frozen OLD, SDK026 and their
original ANSI-valued outputs and comparisons remain unchanged.

### Native remapping diagnostics and legacy binding decisions

The pinned ClangSharp `Close()` clears its diagnostic collection. The historical
`c915725e` scraper read that collection after closing the generator, so its green
`NoSuggestedRemappings` result did not establish the absence of recommendations.
The integrated scraper correctly snapshots diagnostics before closing, including
selective record passes. That ordering remains required; diagnostics are not
discarded to restore a historical green result.

Actual `a73bff9f` producer logs exposed nine recommendations. The approved UNICODE
context in `93a1cc0b` exposed 49 more, chiefly W-tag/neutral aliases. These findings
are kept separate from the raw API-image differences.

The binding context now retains existing decisions that exported rename output
previously omitted: original native self typedefs, explicit
`--exclude-auto-remap` compatibility pins and the existing interface no-rename
rule. Authored remaps remain authoritative. This does not choose a different
alias when discovery is ambiguous or change an API-specific ownership rule.

The remaining legacy color warning came from explicit `___` typedef-reversion
names used by selective record generation. The scraper uses ClangSharp's
intentional-remap marker only when the unsuffixed target is proven to be a native
typedef of the exact qualified canonical source tag. The generated temporary
name is unchanged. Unknown, pointer and different-tag aliases do not qualify;
emitter storage, binding and manual-provider checks remain strict.

No remapping allowlist or integrity check is weakened, and no API-name mapping or
SDK header is added to resolve these diagnostics. Historical raw images, logs,
comparisons and failed controls remain unchanged.

The final focused run passes 77 discovery, native-provider, Unicode/ANSI, ABI,
diagnostic and performance cases, including all six unchanged performance
guards. Fresh affected SDK producer outputs cover 21 partition/architecture
combinations. Replaying the actual `93a1cc0b` three-architecture CI artifacts
with those outputs passes all 27 integrity tests, including the unchanged
producer-log remapping check. Its unsuppressed comparison against the actual
`93a1cc0b` CI image reports no declaration differences.

The separate raw c915 comparison now has 1,367 declaration rows: 606 additions,
125 removals and 636 changes, plus two Fax string-value rows. This includes the
approved UNICODE context and is not API-equivalence or migration-acceptance
proof. The original 921-row and later 885-row comparisons remain frozen.
The `93a1cc0b` normal CI run passed scraping, emission, packaging, samples and
ordinary suites, but failed integrity on the 58 remapping recommendations.
Local replay proof does not qualify a subsequently published head's normal CI.

### SDK preparation diagnostics at the MSBuild boundary

Preparation validates the native exit code, complete MIDL output, diagnostic
category and pinned hashes before publishing a private include root. Some MIDL
forward-declaration diagnostics are retained as categorized non-blocking warnings
after these checks. Their raw text contains `error MIDL2337`; passing the warning
stream through MSBuild `Exec` made MSBuild classify those already-validated lines
as fresh errors despite PowerShell returning zero.

The MSBuild invocation now records PowerShell's warning stream separately in
`obj\prepared-sdk-provenance\<architecture>\preparation.warnings.log` and emits a
build warning pointing to that evidence. Standard output still contains exactly
one include root. Raw MIDL logs, categorized results and hashes remain in the
published provenance. Native and script failures still fail `Exec`, whose normal
error recognition remains enabled. No MIDL category, recipe, output or hash
check is relaxed; preparation scripts and cache identities are unchanged.

The old wrapper fails three architecture-specific controls on thirteen retained
error-shaped diagnostic lines each. All seven new wrapper cases pass with the
repair, including real stderr errors even with a zero process exit, nonzero
failures, hash exceptions and the one-include-root contract. The existing ninety
preparation/MIDL cases also passed during the bounded validation. These wrapper
checks do not constitute a fresh complete migrated-SDK generation.

### Tooling and migration PR boundaries

The tooling layer retains the existing sidecar and manual-source inputs and
supports header annotations alongside them. Compiler, scraper, emitter,
comparison, incremental-input, and performance changes belong in that layer,
including generic fixes discovered while preparing the full SDK.

The upper layer supplies the SDK header/IDL patches and preparation recipe and
retires the API-specific non-header inputs. It does not change the tooling.
The complete pre-split source is preserved at
`42d80eeb61f39cdeea1f2f75abc0e272a271d3ca` on
`jevansaks-header-annotation-full-sdk-checkpoint`; this is a recovery branch,
not an additional proposed PR.

The independently published tooling head `c915725e` already incorporates the
newer upstream SDK 10.0.28000.2705. SDK026 and its patch recipe use the separately
selected 10.0.26100.7705 SDK and its exact older post-MIDL mirror. These histories
diverge; publishing the combined source directly onto the tooling PR would
overwrite independent upstream work. Tooling integration must preserve that
published SDK and merge the generic fixes, rather than replace its whole tree.

The frozen SDK026 qualification does not qualify the resulting two-PR stack.
Its header recipe checks the entire mirror Git identity as well as individual
preimages, so installing that recipe over the newer mirror must fail until the
SDK baseline is deliberately aligned. Do not remove the pins, silently roll the
tooling PR back to the older SDK, or discard newer sidecar facts to hide this
mismatch. Adapting the patches and regenerated IDL outputs to the newer SDK is a
separate change to review.

# SDK header-annotation migration playbook

Use this procedure to convert the SDK in substantial source batches. The
[annotation specification](shift-left-annotation-spec.md) defines the vocabulary;
this playbook defines artifact ownership, migration order, and acceptance evidence.
Keep the C# pipeline. Do not introduce a second C++ parse, API-specific sidecars,
copied native declarations, or a replacement annotation transport.

## Parallel drafting and central integration

Drafting does not wait for validation. Assign disjoint original headers and IDL
families to parallel authors; collect their patches and proposed legacy removals,
apply them to a combined candidate, then compile and iterate centrally.

| Lane | Responsibility | Completion condition |
| --- | --- | --- |
| Patch authors | Convert the remaining API-specific facts in their owned originals; deliver patches and corresponding proposed sidecar removals. | A committed draft with fact IDs, source targets, and explicit residuals. No local compilation or qualification receipt is required. |
| Source assembly | Merge draft cohorts, resolve ownership and patch conflicts, and produce named integration cuts. | An applied candidate with the draft-to-source mapping preserved. Applying a patch does not validate it. |
| Integration and tooling | Prepare the combined SDK, regenerate IDL outputs, build the tools and metadata, compare results, and repair shared failures. | A qualified combined result; failures remain explicit until fixed. |

For the local migration campaign, keep at most two agents compiling: the primary
integration worker and, when needed, one tooling worker. Other authors must not run
builds, MIDL regeneration, Clang/native
parses, partition scrapes, WinMD emissions, tests, or producer replays. Existing
text/metadata readers and patch-authoring helpers are fine. Split a helper's drafting
and validation stages if it otherwise forces a compiler run before delivering a patch.
Bound subprocess concurrency inside the compilation lanes as well.

An author takes the next leased original after handing off a draft; it does not wait
for the preceding draft's build or API review. Existing image reviews can continue
read-only, but are not gates for drafting the rest of the SDK. Do not require a
separate native-control matrix or image for every selector, original, or partition.

### Authoring procedure

1. **Claim an original or IDL family.** Use the shared remaining-fact inventory and
   one writer per original. Include all owned facts in a substantial cohort rather
   than selecting only the next fact with an already-green local probe.
2. **Read the selected SDK's native declarations.** Identify the authored `.h` or
   original `.idl`, its guards, and the declarations to annotate. The repository's
   `RecompiledIdlHeaders` tree is generated output, not an unmodified shipped-SDK
   source authority. Use the actual selected package's headers/IDL when they differ.
3. **Write cumulative source patches.** Put them under
   `generation\WinSDK\patches`, following the existing pre-MIDL/post-MIDL recipe.
   Use the specification's vocabulary and the rules below. For IDL-owned declarations,
   patch the original IDL and leave regeneration to integration. Preserve native
   declarations, SAL, values, guards, storage, and ordinary-consumer behavior.
4. **Draft the corresponding legacy removals.** Deliver the patch and removal
   edits together, mapped to the original fact IDs/selectors. Preserve foreign
   consumers and complete shared-object closure. Keep genuine global/parser controls
   and unexpressed facts as explicit residuals. A parser that does not yet consume an
   authored annotation is a tooling dependency for integration, not a reason to stop
   drafting other source facts. Never remove a fact for which no replacement was
   authored, except an explicitly classified intentional removal.
5. **Commit and hand off without a build gate.** Give the source base and commit,
   owned originals, fact-to-patch/removal mapping, and unresolved source or tooling
   questions. Do not generate per-fact proof packets or claim validated migrations.
   Continue with the allocator's next disjoint cohort while integration works.

Track drafted, applied, and validated facts separately against the same fixed
inventory. A draft is useful unfinished work; neither its existence nor deletion of
a legacy row earns validation or API-acceptance credit.

### Breadth-first conversion and shared gap families

Work across the SDK before trying to complete an individual partition. Partitions
are scrape and comparison units, not authoring-completion gates. Draft the currently
expressible facts in leased originals, record the remaining dependencies, and move
to the next source cohort. Do not wait for every fact in a partition to qualify.

Group gaps by the shared mechanism across all affected originals and partitions:
declaration selection, cleanup binding, IDL placement, enum-provider and namespace
closure, macro-only targets, type projection, or import discovery. Reuse the exact
fact IDs, native targets, and examples in existing receipts; do not require another
per-fact census or proof matrix before authors continue. Keep source ambiguity and
API-specific contract questions explicit rather than calling a whole bucket
unsupported.

Repair a shared mechanism once, then replay its affected cohorts together in a
central successor. Collect independent scrape failures across the batch where
possible instead of repeatedly completing one partition before attempting another.
Failed or unattempted jobs remain visible; collecting a partial batch does not make
its image acceptable. Review unresolved buckets separately while other source
conversion continues. Paired header/reader changes still require coherent central
qualification, not separate author qualification.

## Start from a pinned control

The integration lane records the qualified tooling and pilot commits, tree
identities, shared annotation header hash, selected SDK package version, and same-SDK
OLD image hash for each combined candidate. Authors use the allocator's named source
base; they do not need to build another control before drafting. A branch name or an
earlier green run is not a qualification pin. Keep failed candidates and their raw
output; do not overwrite them when a new candidate succeeds.

Use the existing migration session and PR. Keep the tooling, pilot, and next-wave
layers in their existing stack; synchronize exact commits in each owning worktree.
Resuming authoring does not make an unqualified tooling or pilot revision a baseline.
Do not merge PRs or start consumer changes as part of this migration.

## Choose the original artifact before editing

| Declaration owner | Authored change | Required preparation |
| --- | --- | --- |
| Shipped, C/C++-authored `.h` | One cumulative patch for that original header | Apply to an exact private SDK snapshot; scrape the patched header. |
| Header generated from shipped `.idl` | One cumulative patch for the original `.idl`, never its generated `.h` | Apply before MIDL; regenerate every admitted header produced by that source and its including IDL. |
| IDL that includes another patched IDL | Patch only the source that owns the fact; pin the including IDL as an input | Regenerate both outputs where the included source is embedded in both. Preserve include order and guards. |
| Shared bootstrap, such as `shared\sal.h` | One shared original-header patch, not one include patch per API header | Apply the same admitted patch to native and MIDL input copies that consume it; retain exact preimage checks for both. |
| Global parser/tooling setting | Keep a justified global configuration or parser fix | Demonstrate that it is not an API-specific fact being left behind. |

A file named `.h` is not evidence that it is the authored source. Check its generated
banner and the selected SDK's original IDL, including `#include` and `import` edges.
Patch identity is the SDK-relative original artifact path, not the partition name.
Multiple partitions sharing a header share one patch and one writer.

If a generated header ships without its owning IDL, block that conversion. Preserve
its unmigrated facts on the existing legacy path as explicit residuals: do not drop
the APIs, author a generated-header patch, or let partition-wide admission filter
the still-needed facts.

The property-storage pilot is the important closure example: `propidl.idl` defines
`BUILDING_PROPIDL_IDL` and includes `propidlbase.idl`. Its generated `PropIdl.h`
contains the base declarations behind `_PROPIDLBASE_`. Regenerating only
`PropIdlBase.h` loses annotations when `PropIdl.h` is included first. Regenerate
both from the one base-IDL patch, and account for other partitions that include
either output without claiming to have migrated their APIs.

## Preserve the pilot's authoring decisions

| Fact | Migration rule |
| --- | --- |
| Annotation definitions | Use the shared SAL bootstrap and the matching scraper SAL shim. Do not add `win32metadata_annotations.h` to every API header. An original IDL preprocessing stream that does not already include SAL must include `<sal.h>` before using helpers; an IDL `import` is not a CPP macro include. |
| Import DLL | First inspect the selected SDK's `.lib` imports and the actual processing set. If a library is missing from that set or the parser missed its imports, fix discovery. Only retain an authored import override when justified by actual native/library evidence. |
| Logical enums | Keep metadata-only, unscoped bags of existing constants. Preserve names, members, compiled values, and storage; associate native integer fields/parameters rather than replacing their native types. Native scoped enums remain scoped. |
| Historical labels absent from native source | Require an exact qualification pin for an original-AST label/expression carrier compatible with the selected header/reader pair. If that pin is unavailable, retain the fact in the shared carrier-gap bucket. Do not invent a native alias or expose an ordinary-consumer symbol. |
| Availability | Use the qualified Clang lexical OS scopes or explicit type carriers. Preserve actual floors and scope boundaries; do not invent floors for structs merely because a nearby interface has one. |
| Cleanup and invalid values | Put resource ownership on producers' return values or output parameters. Resolve cleanup names against actual native function declarations after the complete translation-unit walk; declaration order must not require copied or moved prototypes. Preserve complete invalid sets. Do not create pseudo-handle types or move ownership onto an existing plain handle typedef. |
| Compiler intrinsics | Preserve the generator's actual native-Builtin exclusion. Do not invent DLL APIs or require metadata projection for those excluded declarations; still parse and validate their authored annotations. |
| Direction, buffers, counts, and retval | Prefer native SAL/MIDL semantics, preserving count expressions and units. Do not replace or silently discard existing SAL, or add redundant scalar direction annotations. |
| Exact results | `_Win32_PreserveResult_`, legacy `CanReturnMultipleSuccessValues`, and legacy `CanReturnErrorsAsSuccess` converge on CLR `PreserveSig`. Do not introduce a separate multiple-success annotation or preserve the legacy custom-attribute instances. |
| Agile | Do not migrate the old Agile fact into SDK headers; its intentional removal is not a missing annotation to restore. |
| Removed SDK APIs | Do not restore headers or declarations missing from the selected shipped SDK. Compare same-SDK controls so SDK surface changes are not mistaken for annotation omissions. |

Original-IDL API facts use selector-bound comments emitted by `cpp_quote`, such as
`cpp_quote("/* Win32Metadata: parameter ::IStream::Seek::dwOrigin => AssociatedEnum(STREAM_SEEK) */")`.
Use `Convert-SdkIdlAnnotations.ps1` for authoring, or its
`-PatchedIdl`/`-PristineIdl`/`-TransportOutput` mode to convert an existing original.
Restore native SAL against that pristine declaration; never replace it with metadata
`[annotation]` payloads. Preserve native direction, counts, retval, UUID, locality,
and conditional scopes. Logical `Enum`/`FlagsEnum` groups still use their compiled
value transport. Comments use canonical native identifiers without the C `enum`
elaborated prefix; ordinary authored C/C++ annotations remain unchanged.

Retiring a legacy type-wide cleanup or invalid-value field requires evidence that
the producer annotations cover the same ownership contract and complete invalid
set. A few annotated producers, or a passing cleanup-name binding test, do not
establish that closure. Keep unresolved type-policy facts on the legacy path and
count their producer drafts as partial. This does not require recreating type-wide
cleanup annotations. Assess independent typedef aliases against their own wrapper
projection path; cleanup binding does not prove alias transport. Continue other
source drafting while central coverage and output review remain pending.

For an existing native enum with only a C tag, use its actual C type spelling in
the association carrier: `_Win32_AssociatedEnum_(enum VARENUM)`, not the nonexistent
C typedef `VARENUM`. The compiled target must still resolve to the same canonical
enum; do not add a typedef or helper workaround. `WIN32METADATA`-enabled parsing
is C++ only; ordinary native C compatibility remains required with metadata off.

For the genuine `typedef int GPFIDL_FLAGS`, use the matching global
`_Win32_Enum_(GPFIDL_FLAGS, int, ...)` group and omit the redundant `AssociatedEnum`
on `SHGetPathFromIDListEx::uOpts`. The existing emitter then uses the declared enum
type, rather than primitive storage plus an association. Grade the intentional
logical UInt32-to-Int32 correction openly. Rename the logical `SERVICE_NOTIFY`
flags group to `SERVICE_NOTIFY_FLAGS`, preserving its ten members, order, raw
values, UInt32 storage and flags semantics; do not rename native SDK record aliases.
Retain both changes in unfiltered raw diffs, not a global typedef-promotion rule.

The helper is an SDK asset. Exercise both packaged and repository-backed
GeneratorSdk samples when changing the common bootstrap: a helper available through
the main SDK's include paths can still be missing from another asset layout.

Treat a global logical group as a dependency batch before admitting its use sites.
`WIN32_ERROR`, for example, includes both WinError constants and SetupAPI-owned error
macros. Keep contributions in their original headers, using the same group name,
storage, and kind; route them to the same metadata namespace through the existing
global namespace mechanism. Preserve the complete physical member inventory across
all owners, including mixed-case native names. A prefix-only or uppercase-only
inventory is not a completeness check.

Do not accept an association with an unbound typedef, subset group, generated C#
enum, or broad include of another API's headers. Central integration must qualify
the source-owned group and its native visibility before accepting the association.
Authors can draft providers and use-site contributions in parallel, keeping missing
provider or visibility closure as a shared dependency rather than an authoring gate.
Preserve `.header-types.cs` producer filenames in frozen
source overlays so the emitter can distinguish group contributions from ordinary
native or residual legacy enum definitions. Keep unmigrated use-site facts explicit
until central qualification covers their declaration owners. After moving a complete
group definition, the existing `addUsesTo` form can retain those existing uses without
`name`, `members`, or `autoPopulate`; it emits remaps, not another enum definition.
Do not add new API-specific sidecar facts as part of that bridge.

Header typedef annotations can also coexist with a retained AutoTypes record during
incremental migration. The emitter composes generated native typedef wrappers by
their Roslyn-bound full identity and unmanaged `Value` storage, keeping one wrapper,
one `Value` field, and one copy of matching annotations. Remaining AutoTypes facts
are preserved; conflicting storage or annotation values fail rather than winning by
input order. Ordinary declarations and foreign short names are not merged. This is
an intermediate compatibility bridge, not permission to add type-wide ownership:
new cleanup annotations still belong on producing results or output parameters.

Include the complete normal constants scrape and emission in that dependency batch.
An actual header-group member can share its name with a separate retained enum type.
The constants stage recognizes producer-owned members in their resolved namespace,
preserving both enum identities and the normal scalar-alias processing; unrelated
constant/type collisions remain errors. The emitter removes the loose member copy.
Scalar macro aliases outside the group must keep their own primitive storage and
values; do not absorb them into the group or add casts to native headers. The emitter
uses Roslyn-bound header-group identities to add checked scalar conversions in its
private compiler inputs. When removal of a grouped member's loose constant leaves
a bare scalar alias unbound, the emitter resolves it only if normal C# lookup has
no symbol or candidates and exactly one producer-owned logical group supplies that
member. Parenthesized aliases follow the same rule. A bare alias that instead names
an enum type can resolve the unique header-group member in that same namespace:
the type is not a value binding. Valid value bindings, foreign types, and ambiguous
or missing names are not guessed. Original generated sources remain unchanged.
Ordinary native enums, enum-typed aliases, and unrelated compiler errors are
unchanged; out-of-range constants still fail. A small group-only image does not
qualify the full alias closure or ABI-relevant layout and declaration order.
Successful alias compilation preserves the candidate's declared scalar facts, not
OLD API equivalence. Grade newly exposed aliases, changed conditional macro
selections, and retained use-site remaps separately in the unfiltered full image.

For the selected pilot SDK `10.0.26100.7705` x64 import package, all 462 libraries were checked for
the seven WSL entrypoints and API-set DLL. None supplies them. The actual processing
set covers all 453 `um\x64` libraries and likewise finds none; the other nine
libraries are outside that set. The WSL override is therefore not evidence of a
missed library in this SDK. Repeat the check when changing SDKs; do not generalize
this result to unexamined packages or architectures.

### MIDL transport

Native MIDL `[annotation]` is a SAL override, not an unrestricted additive channel.
Type/interface and nonlocal callable targets have additional restrictions.
Use the owned structured-comment transport for original-IDL metadata:

```idl
cpp_quote("/* Win32Metadata: interface ::IExample => SupportedOSPlatform(\"windows6.1\") */")
cpp_quote("/* Win32Metadata: parameter ::IExample::Create::handle => RAIIFree(CloseHandle, -1, 0) */")
cpp_quote("/* Win32Metadata: field ::STATSTG::grfLocksSupported => AssociatedEnum(LOCKTYPE) */")
```

Place comments in the declaration's existing native conditional/include region.
They bind absolute native identities after the complete translation unit is
available, not neighboring syntax. Retain native attributes, SAL and `[retval]`.
The ordinary annotation reader validates targets/references and emits the existing
facts; a missing/ambiguous target is an error. Record aliases resolve to native
fields, including anonymous-member injection. Property selectors use actual
generated `get_`/`put_` method names. See
[the full grammar](../../generationOptions.md#original-idl-structured-comments).

For plain input pointer parameters without authored annotations, preserve MIDL's
compiler-derived RPC SAL instead of injecting `_In_`: that override can erase
native interface-pointer optionality. Nonlocal interface methods retain MIDL
`/sal`-derived RPC direction/count annotations without synthetic `[annotation]`
overrides. Explicit local methods retain standard SAL conversion. Native SDK SAL
has no `_Out_retval_`/`_COM_Outptr_retval_`; use `_Out_`/`_COM_Outptr_` and read the
preserved native `[retval]` comment. Do not suppress MIDL2495 or change locality.

Do not copy signatures or place `cpp_quote` inside field/parameter lists.
Keep compiled Enum/FlagsEnum groups and native C/C++ macro semantics; the comment
grammar does not expand macros or evaluate C++ expressions. RAIIFree comment
invalids are signed decimal Int64 literals; unsupported forms stay explicit
residuals. Compare pristine, prior macro and new output. Removing quote blocks can
change implicit RPC bookkeeping: preserve the raw delta and resolve it rather
than retaining empty scaffolding or normalizing it away.

## Integrate and qualify a combined batch

These steps belong to central integration and acceptance. They are not prerequisites
for an author to deliver a draft or start another owned original.

1. **Assemble the drafts.** Join the cohorts' fact IDs, original owners, source
   patches, proposed legacy removals, and explicit residuals. Resolve overlapping
   edits through the original's owner. Apply the source changes and matching removal
   edits to one named candidate; do not require a prevalidated result from each author.
2. **Prepare exact private inputs.** Pin original SDK/IDL/header and tool identities;
   apply one cumulative patch per original artifact. Use the pilot preparer and
   manifest, with no fuzz, installed-SDK writes, ambient include fallback, or direct
   generated-header editing. The declared input set must equal the measured
   preprocessing closure, not merely contain it.
3. **Generate the combined metadata and iterate.** Enable annotation ingestion for
   every affected consumer, not only the partition that owns a group definition.
   Scrape the affected closure and include the normal constants stage and complete
   emission, with no legacy fallback for the removed facts. Group failures by shared
   cause and repair the source or tooling once. Do not send every author back to
   reproduce the same compiler failure or require an image per patch.
4. **Prove native behavior and grade the image.** Regenerate pristine and patched
   IDL with the same MIDL/MSVC arguments. Compile actual C and C++ consumption, including C-interface
   forms where relevant, on x86/x64/ARM64 with metadata off; exercise metadata-on
   parsing as C++ only. Compare native
   signatures/layout/vtables/symbols and actual compiler SAL facts. Compare warning
   contexts as well as counts. Compare RPC proxy, IID, dlldata, and TLB outputs
   against matched pristine regeneration; explain existing mirror-only differences
   separately. Batch these checks around shared transports and affected source
   families instead of repeating the full matrix for each fact. Preserve raw logs,
   including known pristine failures; do not claim those cases passed. Run physical
   metadata checks for attributes, flags, types, signatures, constants, availability,
   and closure. Compare unfiltered OLD-to-NEW and tooling-control-to-NEW output,
   retaining every raw difference.
5. **Check repeatability and remaining legacy use.** Run fresh first/repeat scrapes
   for the changed closure and compare generated bytes, source facts, and diagnostics.
   An up-to-date MSBuild result is not a fresh scrape. Verify that every applied
   retirement has an ingested header replacement and that all retained API-specific
   facts remain on the conversion queue. Reuse frozen unaffected sources only when
   their producer and dependency identities still match.
6. **Checkpoint each batch; qualify the published wave.** Account for every changed
   site using source evidence and commit the source. Before accepting a published
   wave, run exact-current-head CI, download its actual
   image/source/log artifacts, and verify their producer identities and image hash.
   Advance acceptance only when that head is qualified. Disjoint authoring can
   continue while CI runs, but cannot inherit an unqualified result. Do not use a previous
   producer's green run, report an unpushed candidate as published, or hide a failure
   in an allowlist.

The compilation lanes use the existing build commands; authors do not run these as
handoff gates. Do not create another build wrapper:

For local repairs, reuse the prepared SDK and qualified tools. Replay the saved
response files for one affected partition and architecture. Regenerate only the
header outputs owned by a changed original IDL. Record diagnostic-only option
changes separately from ordinary acceptance.

```powershell
.\scripts\Prepare-SdkHeaders.ps1 -Recipe .\generation\WinSDK\patches\SdkHeaders.json -SdkPackageRoot '<pinned-package-root>' -MidlPreprocessorPath '<pinned-cl.exe>' -OutputRoot '<fresh-private-root>'
dotnet build BuildTools -c Release -m:1
dotnet build generation\WinSDK -c Release -m:1 -t:ScrapeHeaders -p:MaxProcessors=2 -p:ScanArch=crossarch -p:ObjDir='<fresh-obj>' -p:PartitionFilter=Foundation
dotnet build generation\WinSDK -c Release -m:1 -p:MaxProcessors=2 -t:EmitWinmd
dotnet test tests\Win32MetadataScraperTests -c Release --filter "HeaderAnnotation"
dotnet .\bin\Release\net10.0\WinmdUtils.dll compare --first <same-sdk-old.winmd> --second <candidate.winmd>
```

Replace `Foundation` with the claimed partition selection and use the pinned pilot
preparation recipe. Join multiple partition names with `%3B`. The normal scrape
target invokes the same preparation stage; its override properties are
`SdkHeaderRecipe`, `SdkHeaderSourceRoot`, `SdkHeaderOutputRoot`, and
`SdkHeaderSdkPackageRoot`. The standalone preparer returns `IncludeRoot`,
`Manifest`, `Identity`, and `Reused`; record those identities rather than guessing a
prepared path.

`MaxProcessors` bounds the scraper task's own parallel partition/architecture jobs.
MSBuild `-m` alone does not bound that internal concurrency. Set explicit bounds for
MIDL and native-control runners too; do not use a nonpositive scraper limit, which
requests unbounded task parallelism.

Enable a migrated partition with `parse-win32-annotations` under its existing
`--config`. Verify the effective ordinary response chain, including inherited
settings, before qualifying its header facts. Record annotation mode with each
partition result. There is no automatic annotation-admission command.
`Build-WinHttpMigrationImage.ps1` is the pilot's frozen complete-source
overlay/repeat/comparison harness, not a general full-SDK admission shortcut.

Annotation projection validation honors the same configured exclusions as
ClangSharp. With `exclude-funcs-with-body`, native function definitions and their
parameters still have their annotations parsed and validated, but do not require
winmd projection. Keep those native sites annotated and qualified; a C++ inline
overload is not the same declaration as a same-named C export. Without that
exclusion, unprojected annotations still fail.

Scraper-only response-file edits can miss the
incremental emitter inputs: invalidate only the relevant known scrape stamps and
stale image in the private qualification workspace, and prove the producer really
ran. Do not treat an old output's existence as a result.

## Grade differences, not expectations

Native storage plus `AssociatedEnum` and canonical result preservation are
intentional representation changes, not blanket waivers. Review the exact affected
sites and physical facts for each candidate. A known category does not authorize
an arbitrary new API, enum member, signature change, floor, or missing annotation.
Do not create checked-in expected-difference files, normalize away raw output,
invent aliases, or weaken OLD snapshots to obtain a pass.

When an integration candidate is blocked, retain its failing image, raw comparison,
native/MIDL logs, and minimal reproducer. Keep its affected acceptance facts blocked
rather than calling the whole partition migrated. Continue drafting other originals.
Fix a shared parser issue once in the tooling lane, requalify its pin, then rerun the
affected combined candidate.

## Integration acceptance handoff

For a qualified integration batch, record original artifact owners and affected
partitions; exact source/tool/SDK/helper identities; admitted input and output hashes;
migrated and residual facts;
native/SAL/MIDL/RPC evidence; first/repeat source results; complete-image hash;
physical checks; unfiltered comparisons with per-site dispositions; and the
current-head CI URL and actual producers. Distinguish local, published, and
CI-qualified evidence. Keep reports with the session/PR artifacts rather than
adding planning journals to the repository. This acceptance record is separate from
the much smaller authoring handoff above.

Work artifact by artifact within the existing migration effort. Parallel writers
may own disjoint original artifacts only; they must not each patch a shared IDL or
header. Reuse the pilot's common preparation and validation machinery, not a
separate per-partition implementation.

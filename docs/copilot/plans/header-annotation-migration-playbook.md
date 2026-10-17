# SDK header-annotation migration playbook

Use this procedure to extend the pilot in bounded batches. The
[annotation specification](shift-left-annotation-spec.md) defines the vocabulary;
this playbook defines artifact ownership, migration order, and acceptance evidence.
Keep the C# pipeline. Do not introduce a second C++ parse, API-specific sidecars,
copied native declarations, or a replacement annotation transport.

## Start from a pinned control

Record the qualified tooling and pilot commits, tree identities, shared annotation
header hash, selected SDK package version, and same-SDK OLD image hash. A branch name
or an earlier green run is not a qualification pin. Keep failed candidates and their
raw output; do not overwrite them when a new candidate succeeds.

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
| Historical labels absent from native source | Use the already-qualified original-AST carrier, with a short explanation of the label/expression pairing. Do not invent a native alias or expose an ordinary-consumer symbol. The XInput `ALL = 0` label is such an exception. |
| Availability | Use the qualified Clang lexical OS scopes or explicit type carriers. Preserve actual floors and scope boundaries; do not invent floors for structs merely because a nearby interface has one. |
| Cleanup and invalid values | Put resource ownership on producers' return values or output parameters. Do not create pseudo-handle types or move ownership onto an existing plain handle typedef. |
| Direction, buffers, counts, and retval | Prefer native SAL/MIDL semantics, preserving count expressions and units. Do not replace or silently discard existing SAL, or add redundant scalar direction annotations. |
| Exact results | `_Win32_PreserveResult_`, legacy `CanReturnMultipleSuccessValues`, and legacy `CanReturnErrorsAsSuccess` converge on CLR `PreserveSig`. Do not introduce a separate multiple-success annotation or preserve the legacy custom-attribute instances. |
| Agile | Do not migrate the old Agile fact into SDK headers; its intentional removal is not a missing annotation to restore. |
| Removed SDK APIs | Do not restore headers or declarations missing from the selected shipped SDK. Compare same-SDK controls so SDK surface changes are not mistaken for annotation omissions. |

For the selected pilot SDK `10.0.26100.7705` x64 import package, all 462 libraries were checked for
the seven WSL entrypoints and API-set DLL. None supplies them. The actual processing
set covers all 453 `um\x64` libraries and likewise finds none; the other nine
libraries are outside that set. The WSL override is therefore not evidence of a
missed library in this SDK. Repeat the check when changing SDKs; do not generalize
this result to unexamined packages or architectures.

### MIDL transport: do not substitute local experiments for qualified behavior

Native MIDL `[annotation]` is a SAL override, not an unrestricted additive channel.
It works for qualified field cases; type/interface and non-local callable targets
have additional restrictions. Existing parameter/retval marker comments are a
limited compatibility bridge, not a generic new-metadata transport.

Use `_Win32_AnnotateInterface_` for interface facts, grouped in an existing opening
quote region. Use `_Win32_AnnotateMethod_(Interface::Method, annotation)` after the
complete interface definitions, grouped with an existing trailing quote region.
The helper binds the real method through a compiler-parsed member reference. Do not
copy the signature, bind a method by string lookup, change RPC locality, or place a
`cpp_quote` inside a field/parameter list.

Use that method helper for both local and remotable methods when metadata belongs
only on the interface method. A native local-method `[annotation]` can also annotate
the generated `*_Proxy` declaration. Do not accept that spill by comparing macro
text alone. Adding quote regions between interfaces can also change MIDL's generated
bookkeeping; reuse existing regions and compare actual RPC outputs.

There is no qualified arbitrary non-local parameter carrier. If native MIDL/SAL and
the existing helpers cannot express a required fact, keep that artifact blocked and
report the exact target, diagnostic, and reproducer. Do not silently omit it, make
the method local, invent a comment payload, or add an API-specific sidecar.

## Execute one bounded batch

1. **Inventory and claim the owner.** Enumerate the selected partitions' effective
   response-file, enum, handle, import, and availability facts. Map each fact to its
   native declaration and original artifact. Expand shared-header and including-IDL
   closure before choosing writers. Keep discovery work separate from admissions.
2. **Prepare exact private inputs.** Pin original SDK/IDL/header and tool identities;
   apply one cumulative patch per original artifact. Use the pilot preparer and
   manifest, with no fuzz, installed-SDK writes, ambient include fallback, or direct
   generated-header editing. The declared input set must equal the measured
   preprocessing closure, not merely contain it.
3. **Prove native behavior first.** Regenerate pristine and patched IDL with the same
   MIDL/MSVC arguments. Compile actual C and C++ consumption, including C-interface
   forms where relevant, on x86/x64/ARM64 with metadata off and on. Compare native
   signatures/layout/vtables/symbols and actual compiler SAL facts. Compare warning
   contexts as well as counts. Compare RPC proxy, IID, dlldata, and TLB outputs
   against matched pristine regeneration; explain existing mirror-only differences
   separately. Preserve the untouched raw logs.
4. **Move the owned facts, not just their syntax.** Remove the migrated API facts
   from every relevant sidecar surface. Keep only justified global/parser controls.
   Verify first-parse annotation ingestion with no legacy fallback; then run a fresh
   first and repeat scrape of the selected partitions. Compare generated bytes,
   source facts, and diagnostics. An up-to-date MSBuild result is not a fresh scrape.
5. **Emit and grade the complete image.** Reuse frozen unaffected partition sources,
   replace the changed and affected closure sources, and emit the complete WinMD.
   Run physical metadata checks for attributes, flags, types, signatures, constants,
   availability, and metadata closure. Compare unfiltered OLD-to-NEW and
   tooling-control-to-NEW output, retaining every raw difference.
6. **Checkpoint each batch; qualify the published wave.** Account for every changed
   site using source evidence and commit the source. Before accepting a published
   wave, run exact-current-head CI, download its actual
   image/source/log artifacts, and verify their producer identities and image hash.
   Advance acceptance only when that head is qualified. Disjoint authoring can
   continue while CI runs, but cannot inherit an unqualified result. Do not use a previous
   producer's green run, report an unpushed candidate as published, or hide a failure
   in an allowlist.

Use the existing build commands; do not create another build wrapper:

```powershell
dotnet build BuildTools -c Release
dotnet build generation\WinSDK -c Release -t:ScrapeHeaders -p:ScanArch=crossarch -p:PartitionFilter=Foundation
dotnet build generation\WinSDK -c Release -t:EmitWinmd
dotnet test tests\Win32MetadataScraperTests -c Release --filter "HeaderAnnotation"
dotnet .\bin\Release\net10.0\WinmdUtils.dll compare --first <same-sdk-old.winmd> --second <candidate.winmd>
```

Replace `Foundation` with the claimed partition selection and use the pinned pilot
preparation/admission configuration. Scraper-only response-file edits can miss the
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

When a batch is blocked, retain its failing image, raw comparison, native/MIDL
logs, and minimal reproducer. Mark the affected artifact blocked rather than
calling the whole partition migrated. Fix a shared parser issue once in the tooling
layer, requalify its pin, then resume affected batches.

## Handoff required from each batch

Record original artifact owners and affected partitions; exact source/tool/SDK/
helper identities; admitted input and output hashes; migrated and residual facts;
native/SAL/MIDL/RPC evidence; first/repeat source results; complete-image hash;
physical checks; unfiltered comparisons with per-site dispositions; and the
current-head CI URL and actual producers. Distinguish local, published, and
CI-qualified evidence. Keep reports with the session/PR artifacts rather than
adding planning journals to the repository.

Work artifact by artifact within the existing migration effort. Parallel writers
may own disjoint original artifacts only; they must not each patch a shared IDL or
header. Reuse the pilot's common preparation and validation machinery, not a
separate per-partition implementation.

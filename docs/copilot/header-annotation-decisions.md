# Header annotation migration: problems and decisions

Updated: 2026-10-21 (UTC).

This is the running record of migration blockers, their evidence, and the decisions
made while resolving them. The goal is to express win32metadata's intended API
metadata faithfully in the selected SDK's original headers and IDL. A zero-difference
OLD-to-NEW WinMD is not a goal. Breaking changes and unexplained differences remain
visible for review.

## Current state

- The C# generator remains in use. The qualified tooling is ClangSharp 21.1.8.4
  with libclang 21.1.8; this is not a Clang 23 qualification.
- Source cut `76e18a0ddef80ccea546514a59f6cee41ac80eb7` is integrated. It contains
  the corrected `GPFIDL_FLAGS` group, the `SERVICE_NOTIFY_FLAGS` rename, the
  `ASSOCF` header migration, four credential-group retirements, the bounded
  `CERT_FIND_FLAGS` forward correction, the new `BCRYPT_OPERATION` group, and
  the shared compiler-identity and record-eligibility repairs.
- The qualified successor runtime is `71.0.340-preview+8d0cd24516`, with 135
  focused checks including six physical ANSI/Unicode architecture cases. The
  ordinary SDK results below used `71.0.339-preview+03958d1bb5`; actual
  Controls/Shell execution on the successor remains pending.
- The `GPFIDL_FLAGS` representation has a reduced physical WinMD proof on x86,
  x64, and arm64. Actual Controls/x64 replay clears all three previous GP/service
  binding errors, but a newly reached IStream projection failure still prevents output.
- Ordinary Services, MenuRc, Gdiplus, Hypervisor, ComOle, and Gdi x64 runs produce
  real C#, header types, and remaps on runtime039/C8 with no unknown or unused
  facts. Their exact generated targets confirm 201 of 214 active cleanup-site
  repairs. These are generated-output results, not WinMD acceptance.
- The `ASSOCF` source correction is integrated; actual Shell projection remains
  pending. The WBEM macro-expanded method identity and IStream forward/definition
  ownership repairs are qualified in the shared reader but not yet proved in
  those actual owners.
- API-specific sidecars still remain active. Some already duplicate authored
  header replacements; their retirement is a separate unfinished source task.
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
| D03 | Migration-added scalar forward declarations conflicted with logical enum groups. Some similarly named aliases were genuine SDK declarations. | Remove only forwards proved to have been introduced by migration. Preserve genuine native typedefs, records, constants, guards, and ABI; do not weaken enum-kind validation. | Shared artificial forwards, including 103 additional Winuser forwards, were removed. The bounded CERT_FIND_FLAGS correction removes only its four proven migration-added scaffold lines, retaining its 44-member group and association. Actual ordinary MenuRc/x64 succeeds; certificate-owner execution remains pending. |
| D04 | Some migrated `RAIIFree` facts were attached to carriers that did not match native parameter or storage ownership. | Put each fact on its correct native declaration or parameter. Preserve the native signature and evaluate the resulting metadata explicitly. | 217 carriers were corrected: 214 active sites plus three inactive forms. Actual x64 generated targets confirm 201 active sites: 25 Winuser, 97 Gdiplus, one Hypervisor, 34 Oleauto, and 44 Wingdi. Remaining owner/architecture checks are pending; the three inactive forms remain source-only. |
| D05 | Macro and comment enum-name references did not consistently resolve against the complete native translation unit and final emitted enum set. | Use compiler-expanded tagged name transport and shared complete-TU resolution. Defer only absent unqualified names. Reject visible wrong kinds, ambiguity, and absent qualified names; require exactly one final emitted enum per architecture. | Shared transport, resolver, and deterministic WMA001 aggregation are implemented. Invalid facts abort before output; native parse success alone is insufficient. |
| D06 | Twelve real inline function definitions were reported as missing annotation targets because output exclusion hid them from comment binding. | Bind and validate against real native definitions first. Keep output exclusion separately in `ShouldEmit`; do not edit declarations or comments to work around the binder. | Runtime039 contains the bounded correction. Focused controls passed, and the twelve false missing-target errors disappeared in actual Controls replay. |
| D07 | Metadata-only enum carriers raised a C versus C++ compatibility question. | Metadata-enabled parsing is C++ only. Ordinary native C SDK compilation remains protected; C metadata-on parsing is not an acceptance requirement. | Recorded in the spec and playbook. Superseded namespace experiments were not adopted as production source. |
| D08 | Native `GPFIDL_FLAGS` is `typedef int`; OLD metadata used a UInt32-backed logical enum. Its only external OLD signature use, `SHGetPathFromIDListEx::uOpts`, was already enum-typed. Values are only 0, 1, and 2. No unsigned-storage rationale was found in its original history. | Preserve the native int typedef and anonymous constants. Add a matching global `_Win32_Enum_(GPFIDL_FLAGS, int, ...)` group and omit redundant `AssociatedEnum` on `uOpts`. Accept the visible UInt32-to-Int32 enum-storage correction. | Source integrated in451. All-three-architecture reduced proofs produce an actual Int32-backed enum parameter with unchanged native ABI and entrypoint. The changed-source ordinary Controls run clears the previous binding error; successful output remains blocked by D13. |
| D09 | OLD logical enum `SERVICE_NOTIFY` collides with a genuine SDK service-record alias of the same name. | Rename the logical group to `SERVICE_NOTIFY_FLAGS`; preserve all ten members, order, values, UInt32 storage, and Flags semantics. Update both mask associations. Preserve native records, typedefs, DWORD parameters, and buffers. Do not hide the rename behind a remap or compatibility alias. | Source integrated in451. Actual ordinary Services/x64 succeeds and emits the exact ten-member UInt32 Flags/unscoped group, both uint masks with the new association, and native SERVICE_NOTIFY_2A/W pointer buffers. Physical WinMD and complete-image grading remain pending. |
| D10 | Eleven Shell annotation references target native scalar alias `ASSOCF`. The header has its genuine DWORD typedef and 19 constants, but no logical group. The existing manual C# enum and exact OLD image independently establish the intended UInt32 Flags group, including duplicate value2. All eleven OLD parameters are actual named enum types, not primitive-plus-association parameters. | Move that exact existing group into its original header using matching unsigned-long/DWORD storage. Remove only its manual enum block and eleven migration-added redundant associations, preserving native declarations and all 19 members. | Source integrated in02fc. Strict selected-SDK check/apply, exact native inverse, and exact manual-block inverse pass. Actual ordinary Shell output remains pending. |
| D11 | The authored WBEM selector names `IWbemServices::GetObject::lFlags`, but an actual Shell native AST identifies `GetObjectA::lFlags`. Wingdi's active `GetObject` macro changes the native declaration name; UNICODE selects the W form. This is not a missing guard or function body. | Accept the written selector only through the first compiler TU's exact MacroExpansion-to-MacroDefinition link, direct identifier replacement, and matching replacement-token spelling file/offset. Preserve native selectors, strict scope, kind, ambiguity, canonical identity, and parameter ordinals. Do not execute comment macros or change native-reference resolution. | Successor8d is qualified, including ANSI/Unicode physical bindings on x86/x64/arm64 and negative factory/ambiguity controls. Six source files are composed in76. Actual Shell execution remains pending. |
| D12 | Some partitions did not actually enable annotation parsing through their ordinary accumulated response files. Including a header also did not prove that partition owned its projection. | Inspect the real ordered and nested response inputs, enable parsing in the owning settings, and require positive output from actual projection owners. Resolve nested response paths relative to process CWD. | Gdiplus and Hypervisor opt-in were repaired and both ordinary x64 runs now succeed with positive generated facts. Ownership explicitly distinguishes MenuRc/Winuser, Shell/shlobj_core, and Services/winsvc. Wider ordinary acceptance is pending. |
| D13 | After common enum-binding errors clear, ordinary Controls reports unprojected `IStream` facts at commctrl.h814. The saved native AST proves one canonical type: an unannotated forward inside traversal, but its actual full Objidl definition outside traversal. Eligibility is being evaluated through the wrong native declaration. The validator also reports only the first unused declaration. | Use the compiler-linked actual record definition for projection eligibility when present. Keep lone incomplete/complete unused records strict, preserve all facts, and validate invalid facts even outside traversal. Reuse the expected-error collector for independent post-projection errors, aborting before output; propagate unexpected exceptions. | Successor8d passes focused definition-ownership, traverse-converse, annotation-off, incomplete-record, aggregation, and failure controls. The actual039 Controls run still records exit -1/no C#; successor owner execution remains pending. |
| D14 | Retained API-specific sidecars still participate in generation, including duplicate header replacements. The original 441 enum items included 149 named groups and 378 actual use rows; an initial shell count also included null array entries and has been corrected. API-specific RSP inputs remain active. | Retire already-authored replacements in bounded coherent cuts using the existing fact ledger. Author missing original-source replacements rather than treating unmatched facts as permanent exemptions. Do not delete them wholesale, claim header-only coverage, or build a new inventory gate. Grade typed legacy remaps versus primitive-plus-association header output in the raw API diff. | CRED_FLAGS, CRED_TYPE, CRED_PERSIST, CRED_PACK_FLAGS, CERT_FIND_FLAGS, and BCRYPT_OPERATION have bounded matching retirements. Current JSON has 435 items, 143 named groups, 292 added-use groups, 360 uses, 639 explicit members, and 42 auto-populate groups. API-specific RSP inputs and complete sidecar elimination remain open. |
| D15 | OLEIVERB has no header group; UPDFCACHE_FLAGS has its UpdateCache association but no original-IDL group. Exact OLD proves seven Int32 nonflags/unscoped verbs and nine UInt32 Flags/unscoped cache members. The sidecar's trailing/double-underscore cache aliases do not exist in OLD or the selected native declarations. | Add the seven native verb constants to Ole2.h in OLD order. Add the nine cache constants to original oleidl.idl in exact OLD order, after their definitions, then regenerate its header. Do not recreate unused underscore aliases or infer a new DoVerb association: its inspected OLD iVerb is Int32 without association. Preserve native DWORD grfUpdf and its source association, while exposing its expected metadata representation change. | Original-source additions are staged. Patch qualification, targeted owning-IDL regeneration, and ordinary output are pending. |
| D16 | BCRYPT_OPERATION has no header group or use. Exact OLD contains six UInt32 Flags members and an actual enum-typed BCryptEnumAlgorithms parameter. The native SDK explicitly defines two more operation constants with WIN8 and WIN11_GE availability guards. | Use the existing global Flags helper with mutually exclusive native 8/7/6-member branches. Preserve all six OLD names, order, and values, native ULONG, SAL, and availability guards; associate the native parameter with the logical group. Keep both newly included constants and the expected named-enum-to-primitive-plus-association change visible. Availability guards alone do not prove an SDK-version delta. | Source integrated in431 with strict patch replay and native/SAL/guard inverse proof. The cause of OLD's two omitted constants remains unclassified until actual OLD selected-header comparison. Ordinary output and physical WinMD grading remain pending. |
| D17 | OleDuplicateData's retained sidecar associates cfFormat with CLIPBOARD_FORMAT and uiFlags with GLOBAL_ALLOC_FLAGS, but neither association is present in its original header. Exact OLD independently confirms both actual enum parameter types without associations. | Add both associations to the existing native CLIPFORMAT and UINT parameters in Ole2.h. Preserve HANDLE, all native parameters, and surrounding metadata. Grade the resulting primitive-plus-association parameters explicitly rather than inventing aliases or emitter promotion. | Both original-header additions are staged with the OLE source groups; strict replay and ordinary/WinMD qualification are pending. |

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
separately. Native `ULONG dwAlgOperations` with an explicit association is expected
to project as a primitive plus association rather than OLD's actual enum parameter.

The staged `UPDFCACHE_FLAGS` source preserves all nine physical OLD members,
including their order and unsigned values. Native `DWORD grfUpdf` remains unchanged;
its source association is expected to expose the same enum-to-primitive metadata
representation difference. No generated output is claimed for this staged change.

Other expected differences, including selected-SDK surface changes, native enum
representation, and parameter-owned cleanup metadata, will be graded against their
specific evidence. They are not a blanket exemption for missing declarations or
incorrect annotations. Removed SDK APIs will not be recreated solely to match OLD.

## Remaining execution

1. Resolve the newly reached Controls projection failures, then inspect positive
   affected-owner and architecture outputs from the saved ordinary commands.
2. Complete and qualify the `ASSOCF` source migration and the WBEM macro-identity
   reader repair. Resolve later located failures using the same native-source rule.
3. Complete missing OLE source groups and the retained use-site facts, retire
   proven API-specific sidecar replacements, and publish one coherent
   corrected SDK after targeted blockers clear. Reuse the
   qualified native tooling and unaffected MIDL outputs; avoid full rebuilds for
   individual header failures.
4. Produce a complete NEW WinMD with a resource-bounded full scrape. Run the actual
   integrity tests, including `NoSuggestedRemappings`.
5. Compare exact OLD first and NEW second without suppressing differences. Classify
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

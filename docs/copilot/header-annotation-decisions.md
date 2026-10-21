# Header annotation migration: problems and decisions

Updated: 2026-10-21 (UTC).

This is the running record of migration blockers, their evidence, and the decisions
made while resolving them. The goal is to express win32metadata's intended API
metadata faithfully in the selected SDK's original headers and IDL. A zero-difference
OLD-to-NEW WinMD is not a goal. Breaking changes and unexplained differences remain
visible for review.

## Completion plan and next review

The next review milestone is one complete SDK-wide NEW WinMD, its full raw
OLD-to-NEW comparison, and a categorized assessment with an action plan.
Further annotation retirement and optional tooling research must not postpone it.

The architecture remains the selected SDK originals plus authored patches,
targeted MIDL regeneration, the compiler-backed C# scraper, constant extraction,
and one namespace/architecture-composed WinMD. SDK sources own API-specific facts;
the reader binds them to native declarations; the emitter preserves them in the
complete image.

1. Freeze a finite candidate from accepted source/config cut `4d857d46`, the
   qualified runtime341/53f scraper, and the unchanged emitter74CC. Preserve all
   manifests and the interrupted runtime340 capture. Pending source releases and
   log-only commits do not silently change the candidate. Necessary compile
   repairs produce explicitly pinned successors of that base.
2. Complete all 321 owners on x86, x64, and arm64, regenerating affected IDL
   closures and running constant extraction and full WinMD emission. Reuse a
   prior output only with matching dependency and tooling evidence. Collect hard
   failures together, repair shared compile blockers, and replay their affected
   profiles. Do not add optional per-partition qualification gates or a blind
   full-run retry loop.
3. Run complete-image integrity checks, including NoSuggestedRemappings, and
   retain every failure. Compare the pinned exact OLD first against this exact
   NEW second, including signatures, constant values, enum/global placement,
   namespaces, attributes, imports, and availability. Do not filter intended
   differences out of the raw comparison.
4. Deliver the complete image, raw comparison, and categorized issue report.
   Each category needs counts, affected APIs, consumer consequences, evidence,
   and a proposed action. Stop before broad remediation for the requested
   discussion.

| Review category | Required disposition |
| --- | --- |
| Intended representation changes | Explain the consumer impact and retain the raw difference, including primitive-plus-association signatures, storage corrections, logical names, and enum/global placement. |
| Selected-SDK changes | Prove the change against the selected native source and available OLD provenance; do not infer removal from one missing token or header. |
| Corrections to OLD | Show the native contract and why OLD was incorrect. |
| Missing header facts or providers | Identify the exact missing fact and original owner; keep unproved replacements active. |
| Reader, emitter, or composition defects | Group by shared cause and propose bounded fixes. Missing APIs and wrong namespaces are not accepted as intended changes. |
| Unresolved provenance | State what remains unknown and the observation needed to decide it. |

The first complete image is explicitly transitional: remaining API-specific
sidecars stay active where their replacements are unproved. Its functional diff
does not prove header-only coverage. The existing fact ledger records that
remaining dependency separately; no new inventory project is required.

After the full-delta review, complete the agreed original-source replacements and
retire their matching API-specific sidecars. Global organization and parser fixups
may remain. Final migration acceptance requires another complete image, integrity
results, and an explained raw OLD-to-NEW comparison from that header-driven state.

## Current state

- The C# generator remains in use. The qualified tooling is ClangSharp 21.1.8.4
  with libclang 21.1.8; this is not a Clang 23 qualification.
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
- Runtime `71.0.340-preview+8d0cd24516` has 135
  focused checks including six physical ANSI/Unicode architecture cases. The
  earlier ordinary SDK results used `71.0.339-preview+03958d1bb5`; Controls and
  Shell also produce real output with zero unknown/unused facts on runtime340.
  The later selective-constant successor is
  `71.0.341-preview+53f3459d5b`, with 60 executed focused checks and 18 physical
  output pairs. Its exact four-file source is integrated as
  `80deedfd20a9e709a738ea00b0e72702dd4c51c3`. Those identities remain distinct;
  runtime341 has not yet been adopted by an ordinary SDK run.
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
  Exact TU visibility versus source-order or reader identity remains unresolved.
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
  The Terminal Services native macro is missing two bitwise-OR operators across
  continuation lines. A two-token original-source correction is approved, subject
  to exact current-owner/native-preimage confirmation; it must remain visible as
  a native SDK syntax correction in the comparison.
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
| D30 | Frozen ordinary Direct2D x86/arm64 and Direct3D11on12 x86/x64 reject IDXGIOutput::GetDisplayModeList::Flags. Base dxgi.h has a metadata-only unsigned-int DXGI_ENUM_MODES forward and association; the complete UInt32 Flags group with values 1/2/4/8 is in dxgi1_2.h. The sealed packet lacks provider activity and canonical/group-fact observations from the failing TU. | Establish exact original-TU visibility and canonical identity before choosing a source or reader correction. Preserve all four member facts and native declarations. Do not infer an include fix, duplicate or split the group, relax validation, or patch generated headers. Original-source changes belong in shared dxgi.idl and dxgi1_2.idl. | The read-only trace confirms whole-TU collection and no source-offset cutoff. WMA001 proves a selected non-EnumDecl without matching same-canonical group facts. The existing declaration map returns before processor construction, so receipt17CC records zero diagnostic parses and no observer. A diagnostic-only8d copy with one opt-in read-only snapshot at the failing validation site is now approved, followed by the one exact x86/Direct3D11on12 parse. It must preserve WMA001/no-output behavior and record source delta, binary and original input pins. No production hook, source correction or extra profile sweep is approved. |
| D31 | After the app restart, the original full963 producer is absent and ordinary-result.json was never persisted. The surviving ordinary.log has no terminal result; 956 completed-case logs and 958 settings files do not prove all requested profiles ran or succeeded. | Preserve the exact partial input/output/log capture and unknown terminal exit. Use the completed profile accounting to drive the next finite candidate, without relabeling the interrupted run or making optional migration work a build prerequisite. | Receipt AB444403 seals 4,004 raw files, the exact 963-row ledger and portable archive. The ledger records 912 nonempty outputs without error diagnostics, six completed empty outputs, 38 task failures, two launched/incomplete profiles and five without an observed launch. The next production target is one coherent runtime341/74CC transitional image from accepted source, followed by the full raw OLD-to-NEW report. No complete NEW or API acceptance is claimed. |

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

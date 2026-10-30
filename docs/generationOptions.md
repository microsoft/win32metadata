# Inputs Used to Create Win32 Metadata

Metadata is created from headers/libs through two different stages: scraping and emitting.

This project uses [ClangSharp](https://github.com/Microsoft/ClangSharp) to scrape C headers into C# files.

Once the C# files are written by ClangSharp, the emitter turns these files into a Windows Metadata (.winmd) file.

There are different options you can pass to the scraping and emitting stages to improve the final metadata. Most options are passed to the stages via response files (.rsp files). There are also two .json files that provide additional information to the build system.

## Scraping Options

Scraping options are passed to ClangSharp via .rsp files. For the Windows Win32 metadata project, all partitions share the [generation/WinSDK/scraper.settings.rsp](/generation/WinSDK/scraper.settings.rsp) file. This allows partitions to interpret the headers in the same way.

### Automatic native typedef identity

The scraper discovers supported scalar and data-pointer `typedef` declarations
in its selected traversal. They do not require a header annotation or the
`parse-win32-annotations` option. Each alias has a separate source-bound provider
for composition and native ABI validation. Discovery alone does not request a
nominal public type. Unannotated inferred scalar and data-pointer aliases retain
their ordinary CLR use-site projections. Authored C# `NativeTypedef` providers,
explicit nominal typedef remaps (including identity remaps), retained configured
providers, and source-proven native handles retain their nominal contracts.
Primitive and pointer storage remaps alone do not request nominal wrappers.
A configured native-tag pointer projection such as `HANDLE__*=HANDLE` retains
its nominal target only for aliases of that exact qualified native record pointer.

The producer transports this distinction in source-only projection trivia.
Nominal intent survives repeated observations and retained-provider composition.
The writer projects inferred use sites only when the provider's native width and
alignment match its compiler-bound storage. Native provider `Value` chains remain
unchanged. An inferred alias of a retained nominal type uses that retained type
at public use sites; storage validation does not flatten the retained contract.
Inline/fixed buffers keep the projected element's native pointer depth
and array shape; intrinsic projection does not trigger a member-remap pointer
reduction. Existing explicit member-remap array rules remain unchanged.
After native identity, storage and binding validation, an inferred
provider is omitted from the image only when no remaining nominal storage,
signature or type-valued attribute references it. A native identity or matching
storage width never merges unrelated aliases. Older inputs without a projection
policy remain nominal unless their successful native declaration evidence proves
annotation parsing was disabled and their declaration carries no separate
nominal intent. ECMA metadata has no C typedef row; exported nominal aliases use
one-field structs with the internal `NativeTypedefAttribute`.

Inferred-only partitions request the same source-bound projection join as
annotated typedefs. Native integral constants are evaluated in the original
translation unit before their typedef storage is lowered for C# compilation.
Enum backing types and casts use the existing compiler-backed lowering.

Annotation-only `typedef NAME NAME` redeclarations retain the canonical native
declaration's backing storage. Distinct alias declarations retain their
compiler-bound nominal dependencies.

Repeated native record and inferred typedef observations retain the canonical
Clang identity, declaring-header hash and location, and per-target ABI as
source-only provenance. Explicit namespace routes take precedence; otherwise a
partition that directly traverses the declaring header owns the provider.
Dependency and supplemental observations reference that namespace, including
types used in fixed-buffer locals after a record moves. Typedef providers are
not equated by their short names or storage widths.
Legacy enum namespace discovery also prefers the directly traversed owner when
all observations prove the same native declaration. Different identities,
headers, header contents, ordinary providers or multiple direct owners remain
ambiguous; an incidental include cannot redirect a legacy enum's public owner.
An auto-type's output namespace places that retained definition; it does not
redirect an unrelated native declaration with the same short name. When an
auto-type omits its namespace and the existing writer resolves it from the
cleanup API, that resolved ownership supplies a retained-provider route.
Explicit namespace routes still take precedence. Native declaration families
and compiler-bound storage validate separately.
When no retained definition exists, a configured alias projection can select an
actual native typedef provider in the same generated input. The configured
binding must match that source observation, architecture, width and alignment,
and the input must have one native target family. An existing global native
typedef explicitly named as a configured projection target carries its own
source-bound nominal binding. A compatible configured alias can refer to that
target from another input without redeclaring it locally. Automatically
discovered tag remaps, native enum projection targets, and primitive or pointer
storage mappings do not establish this target intent. Enum targets are resolved
from the native declarations even when their headers are outside the traversal
set. A same-named scalar typedef remains inferred when its configured target is
an enum; the target name alone cannot turn it or its storage dependencies into
nominal wrappers. Native integer storage remaps use qualified `System.IntPtr`
and `System.UIntPtr` names so a native typedef cannot shadow their managed
storage types. Separate inputs can select
different native declaration families for the same explicitly routed public
projection; each family still validates independently. An ambiguous native
target, an unrelated alias, or an output namespace alone does not establish a
projection. Native handle contracts also retain their source-bound public owner.
A `DECLARE_HANDLE` observation identifies its own native family; it does not
redirect an unrelated inferred typedef with the same name. Explicit cleanup or
compatible-type annotations can select a shared owner, while native storage and
declaration-family checks still apply. A cleanup-derived namespace requires an
unambiguous actual cleanup API. Inferred-only aliases can share an intrinsic CLR
projection only after their independent source, storage, signedness and layout
checks pass. Repeated observations of one native declaration family instead use
the existing alias composition rules, preserving compatible field contracts such
as constness, documentation and string termination. They do not select an
independent intrinsic projection. These rules do not equate native identities.
Retained families include the full declaring-header identity because Clang USRs
for file-local typedefs can contain only a shared basename such as `main.cpp`.
File-local identity keys include the full physical declaring-header path.
Comparison folds physical path casing but preserves the native identifier; the
physical header, content hash, location and case-sensitive native name still
identify the declaration. Older typedef inputs with no projection policy still
require an explicit retained owner when basename-only identities collide across
physical headers. Global record USRs are also not sufficient to join
unrelated records directly owned by different headers. Each of those records
keeps its own declaring-header owner.
An arbitrary colliding generated wrapper does not establish that route.
Identical, identically bound record providers coalesce into one body, including
copies in the same generated input. Compiler-resolved type spellings are
canonicalized only for comparison, so an imported type and its fully qualified
name can share a provider without rewriting the retained body. Distinct
identities, storage bindings and genuine architecture variants are not flattened.
Record helper implementation text must also agree, but its expression bindings
are not part of metadata comparison: the existing writer emits record fields
and nested types, not helper properties or method bodies. Declaration types,
attribute arguments and field initializers still require matching bindings.
Resolvable helper-local type spellings are canonicalized for comparison too.
Unresolved helper-local type spellings remain unchanged; they do not prevent
comparison or emission of otherwise matching record declarations.
Named attribute constructor arguments match by parameter ordinal, type and
compiler-bound constructor identity.
Generated C# namespace qualification is removed from fallback `NativeTypeName`
spelling when a member remap replaces a source-bound type. An existing native
spelling remains unchanged; source provenance and compiler bindings still
determine identity.
Configured member type remaps remain authoritative at the writer boundary for
returns, parameters and fields, including regex remaps. `NativeTypeName` remains
available as native spelling but does not replace the selected remapped type
with a competing typedef. Unremapped sites retain normal native projection.
Native-name lookup prefers the member's compiler-bound namespace when distinct
providers share a short name. Existing string projection mappings still apply;
an unrelated global match does not replace a locally bound native alias.
Direct macro aliases that differ only by case from an existing unscoped enum
member in the same metadata namespace reuse that member. Other aliases can
still reference them with the canonical member's storage and architecture
availability. The constants receipt records this projection policy.
The cleaner records an applied type remap in source-only trivia that survives
processed-file reparsing and field or parameter renames. The writer uses that
applied policy rather than looking up the renamed member. Attribute-only changes
and implicit compiler-storage lowering do not establish an explicit type remap.
An excluded complete native record can still have a configured external
projection, such as `_GUID=Guid`. Inferred pointer typedefs retain that provider
instead of erasing it to `void*`; excluding the native body does not request a
different pointer contract. Unmapped excluded record pointees keep their existing
opaque treatment. Automatically discovered tag-to-typedef name remaps do not
establish external providers for excluded records.
Alternative declarations of the same native record in different headers can
share the canonical body when native size/alignment and compiler-resolved members
agree. For those alternatives, comparison can follow source-proven scalar typedef
storage. The retained body keeps its declared field types and the other nominal
typedefs remain independent providers. Different nominal bindings of the same
physical native declaration require matching source-proven native alias names,
backing declarations, observed ABI and annotations. A raw pointer parameter can
match its nominal alias only when the native spelling, pointer depth, storage
and transported const annotation agree. A raw record-pointer field also requires
the same written native record identity and a real source-proven pointee.
These comparisons keep the canonical declared types; they do not merge the
independent aliases or override an explicitly remapped member type.
Alternate native character-pointer definitions use the existing native encoding
proof, including pointer depth, to compare against retained character pointers.
The canonical pointer wrapper and its native character storage stay unchanged.
Same-header `NONAMELESSUNION` alternatives can retain the direct traversal's
named union body. Comparison maps only source-proven anonymous-union storage
names to the canonical names and verifies parent identity, header content,
parent/nested ABI, compiler-bound field types and attributes. It does not rename
the retained public members or discard an incompatible body.
Conditional records can use different native tags on disjoint targets. Ownership
and typedef composition compare declaration locations within each applicable
native target, not between mutually exclusive SDK branches. Version-two source
proofs record the actual Clang target separately from C# provider applicability:
a common C# input can cover all targets even when its native observation came
from x86. A transitive common record or typedef observation coalesces with the matching
target's canonical body before cross-architecture composition when direct
declaring-header providers cover all three targets. Native declaration, ABI and
compiler-resolved member bindings must agree on the observed target; the other
targets retain their own bodies. Typedef constraints that do not prove this
reduction remain unchanged for the normal full-family merger, including
compatible nominal backing and native spelling differences. Version-one proofs
remain readable and retain their original profile-based applicability checks.
Conflicting overlapping declarations still reject. When an SDK macro selects a
record layout, dependency partitions must use the canonical traversal's profile;
size-changing alternatives are not interchangeable.
This includes selecting `ddraw.h` before the guarded `ksmedia.h` fallback and
selecting the original `lsalookup.h` declarations before a local `_NTDEF_`
override. `ntsecapi.h` remains after that override so its fallback NT aliases do
not conflict with `winternl.h`.
The common-record comparison applies the normal validated legacy-enum
projection phase in memory for the observed target. Other native aliases retain
their normal full-family composition and validation after cross-architecture
merging. This resolves retained enum bindings before comparing fields without
rewriting the inputs or changing the final providers.
Isolated canonical binding views are reused only within one provider family and
one immutable compilation, with separate entries for each canonical declaration
and anonymous-storage, alternate-definition and coverage-normalization policy.
The normal emitter prints separate timings for common-provider coalescing,
cross-architecture constant qualification and final typedef/record composition,
including failed phases.
Validated native source proofs are cached by immutable syntax declaration and
proof family. Weak cache keys do not retain discarded trees. Rewritten or
reparsed declarations are validated independently, including cached absence;
malformed proofs still fail on every read. The cache contains no compiler
symbols, ownership decisions or cross-declaration identity comparisons.
Namespace qualification builds each enclosing type's lexical shadow-name set
once per immutable tree traversal. Nested types, delegates and generic parameters
retain their original binding precedence; these sets are not shared across trees
or used to infer native ownership.
Selected type nodes are qualified in one syntax-rewriter traversal rather than
through Roslyn's bulk replacement bookkeeping. The original qualification rules,
selected nodes and trivia are retained, including the original enclosing scope.
Legacy numeric partition suffixes retain their established parsed-prefix
namespace. The existing syntax repair records the original namespace for the
source-provenance check while ownership uses the repaired, valid C# namespace.
Other namespace drift and malformed source still reject.
References using the existing `___` projection suffix follow the configured
unsuffixed manual provider's namespace before the cleaner removes that suffix.
The manual provider remains subject to normal native-layout validation.
A source-proven common typedef provider keeps its existing all-target coverage
when sparse target observations have the same native declaration, compiler-bound
storage and compatible annotations. Those repeated observations do not require a
new three-target provider family or replace the canonical common body.
Source-bound typedef `Value` fields keep their compiler-bound ABI storage when
the writer projects API types. This prevents character projection from turning
`CHAR.Value` into a recursive `CHAR` field; ordinary fields and existing
unproven typedefs retain their established projection behavior.

Written typedef dependencies are followed transitively through selected API
returns, parameters, fields, pointer/array elements, callbacks and record fields.
Native field enumeration includes implicit anonymous struct/union fields, so
their nested scalar typedef dependencies retain the same nominal projection.
The SDK scraper profile defines the SDK's overridable `DECLSPEC_NOINITALL` macro
to empty. Its `no_init_all` attribute controls automatic initialization in
executable code, not declaration layout, calling conventions or signatures.
The native controls compare those contracts with and without the attribute on
x86, x64 and Arm64, then inspect the emitted record fields. Other unsupported
attributes retain their existing handling.
Explicit native record and field alignment is derived from the resolved Clang
declaration and written as `AlignmentAttribute(int)`. It is independent of the
maximum field packing in `StructLayoutAttribute.Pack`; ordinary field-derived
alignment does not add an attribute. This metadata preserves native alignment
requirements without claiming that the temporary C# compiler storage or the
.NET runtime can honor native over-alignment.
The producer retains PInvokeGenerator's CLR over-alignment warning in its raw
output. Only the exact native-source diagnostic whose final generated record
still has the matching source proof and alignment attribute is reported as a
supported metadata projection. Unrepresented alignment warnings and all other
unhandled diagnostics keep their existing nonzero behavior.
Native `flag_enum` diagnostics are reported as information only when the exact
source-bound enum still carries its projection proof and `System.Flags` in the
final generated sources. The original diagnostic remains in that informational
record. Disabled annotation parsing, missing projections and unrelated warnings
retain their nonzero exit status; the MSBuild task still rejects every nonzero
scraper exit.
Inferred native owners route only their source-bound providers and uses.
Untracked ordinary declarations with the same short name retain their original
namespace; only configured global routes apply to those declarations.
An inferred owner in another namespace also cannot veto an independently
compiler-bound legacy enum projection. Configured metadata routes still apply.
When the same native alias family is observed in an existing metadata typedef
or legacy enum's namespace, that retained owner takes precedence over inferred
header ownership. An unrelated alias family does not inherit that route, and
multiple observed retained owners are rejected rather than chosen arbitrarily.
An explicit nominal typedef remap also binds that source family to its unique
retained metadata target even when no native observation was emitted in the
target namespace. That binding carries the complete native source proof;
output placement alone establishes no native ownership. Missing, changed or
ambiguous binding evidence cannot substitute for source and storage validation.
Final source, storage and compiler-bound projection validation still applies.
Legacy constant aliases inherit the targets of their authoritative enum or
constant declarations, including forwarding chains. Restricted aliases use
per-target `LegacyAliases.*.constants.cs` families with empty counterparts on
unsupported targets, so normal compiler qualification and cross-architecture
composition preserve their availability. Each constant-scraping run replaces
only those generated alias families; unrelated per-target constant inputs stay
intact.
Referenced aliases in included non-traversed headers are retained too; unrelated
aliases there and explicitly excluded declarations remain outside that selection.

Integral aliases already routed to `IntPtr`/`UIntPtr` by the generator's effective
projection settings retain that intrinsic projection after native width and
signedness validation. This uses the existing remap policy; it is not a new
per-name exception. Aliases built on those intrinsic types can still retain
their own nominal identity.

An existing opaque-handle provider can retain its `IntPtr` storage when the
effective remaps also map its excluded backing-record pointer to that handle.
That ownership proof allows the provider's existing signed storage for native
unsigned pointer-sized values. Native width validation still applies. Ordinary
integer aliases continue to require matching signedness.
Native aliases that already spell their matching C# primitive retain that
primitive binding. Other keyword identifiers are escaped consistently in
generated declarations and references.

Record and enum tag aliases keep the existing record/enum projection rather than
receiving a scalar wrapper. An incomplete native record remains an empty record,
without an invented `Value` field. Function-pointer aliases use the existing
callback discovery.
Unannotated pointer aliases to native COM interfaces retain the ordinary
interface projection and pointer depth instead of creating nominal wrappers or
supplemental body-recovery roots. This follows the resolved native inheritance
chain to a UUID-bearing `QueryInterface`/`AddRef`/`Release` vtable root; a UUID,
virtual method, namespace or type name alone is insufficient. Each virtual method
in the chain must also use the target's effective COM calling convention: native
`__stdcall` on x86, or Clang's normalized Windows ABI on x64 and Arm64. An x86
`__cdecl` method retains the pointer wrapper even when the remaining root shape
matches. Existing external contract imports and API exclusions still apply.

An explicitly remapped, source-bound native enum can already provide the managed
identity of an inferred scalar alias in the same native scope. The scraper keeps
that ordinary enum, its backing type and members instead of adding a conflicting
nominal struct. The alias must be the unique unannotated owner with integral
native storage matching the enum's width and alignment. Floating, pointer,
incompatible-width and conflicting authored typedef metadata reject.
Source-location transport is selected for this path even when authored
annotation parsing is disabled and no records are present. Unrelated native
scopes remain distinct, and explicit CLR storage validation is unchanged.

Array aliases, pointers to arrays, unresolved dependent types and template-owned
typedefs remain with the ordinary generator rather than becoming nominal
wrappers. A selected non-template alias with a concrete specialization can still
retain its scalar identity. Non-default-width data-pointer aliases use fixed
`uint` or `ulong` backing at the affected pointer level, matching Clang's native
size and alignment. `NativeTypeName` on generated C# `Value` retains the written
pointer type and qualifier as source provenance; the ordinary emitter consumes
that transport. WinMD retains the nominal alias and fixed backing storage.
Alias chains and ordinary outer pointer levels are preserved.
Explicit incompatible CLR storage remaps fail validation.

Pointer remap validation follows the written native pointee aliases. A named
nominal type or existing provider owns its underlying native storage, including
any pointer layer. The validator checks that owner's effective storage mapping
and physical width and alignment. Intrinsic integer pointees retain their
pointer-sized integral storage. Unrelated pointee identities and incompatible
provider storage fail validation.
When a native pointee has no written alias, its named owner must be the unique
matching native alias with the same canonical storage. Scalar, pointer and
record siblings in the same native typedef declaration can also supply that
ownership when the spelling names their shared base instead. A different
written owner in another declaration does not authorize an unrelated alias.
Ownership checks retain the matching redeclaration before deduplicating native
identities. A secondary native alias can also own a pointer whose spelling names
an alias in that secondary alias's underlying chain.
An authored pointer view can give a native `void` pointee, or an excluded
incomplete record with existing intrinsic provider storage, a managed type
without inventing a native pointee identity. An existing conflicting native
alias still rejects. Validated explicit pointer remaps remain the wrapper's
`Value` type. Pointer layers and opaque-provider storage still require matching
physical width and alignment.
An excluded complete POD struct can retain its existing scalar provider only
when the effective excluded-record/provider mapping agrees and its sole
non-bit-field integer member has zero offset and matching signed storage,
width and alignment. This does not admit arbitrary record-to-scalar mappings,
floating storage or narrowing providers.
Retained-provider composition accepts one string `NativeTypeName`
source-transport attribute and compatible `Const`/string `Documentation`
metadata on `Value`. Duplicate, conflicting, unsupported or malformed field
attributes still reject. An existing `MetadataTypedef` provider retains its
explicit contract rather than becoming a `NativeTypedef`.
Retained-provider composition compares native nominal backing chains with the
provider's field encoding without flattening emitted alias declarations.
Constant qualification and lowering use the same validated backing-chain
analysis. Every fragment, including retained providers, must agree on fixed
integer storage and signedness before a native typedef constant can be lowered.
This analysis does not change public alias fields or direct API identities.
Successfully composed retained aliases keep their validated header provenance
for constant and cast lowering. An enum backed by a native integer alias uses
that alias's exact terminal primitive in its C# base list.
An existing legacy enum can retain its metadata contract when its unique
declaration, canonical namespace route and a bound ordinary source use
establish projection ownership. Different signed metadata storage additionally
requires an independently bound explicit member remap with unchanged integer
ABI size. Native providers are validated in their original binding view before
applying that projection; incompatible native aliases and incompatible
primitive-to-enum remaps still reject. Name, width or value coincidence alone
does not establish an enum projection.
An established enum projection can reconcile separate native declaration
families. Each family's declaration provenance remains independently validated,
and all native fragments must still pass the common storage and annotation
checks before their selected metadata enum replaces them.
Cross-architecture dependency identity partitions the complete set of provider
fragments for each architecture. Multiple partial providers are not separate
architecture variants. Distinct source fragments survive variant deduplication
until strict provider composition; a referenced type still has exactly one
dependency group per architecture. This also retains same-signature fragments
with different scoped bindings, including repeated namespace blocks in one file.
Multiple native alias owners in one input still reject unless a single retained
provider has an explicit canonical namespace route and every header fragment
passes the same storage and metadata checks.
That existing retained route can reconcile distinct native typedef declarations
and authored remaps onto its public provider. Declaration conflicts within each
native identity and incompatible compiler-bound storage or metadata still reject;
a matching short name does not authorize that projection.
Header-only integer providers can compare
their semantically resolved terminal fixed-integer backing without flattening
the retained field's nominal type. Signedness, width, pointer ownership,
annotations and other storage conflicts remain validated.
Source-bound fixed-integer constant variables use Clang's evaluated native
value, including native character-to-unsigned and signed-to-unsigned
conversions, from the original translation unit. This does not reinterpret
managed C# initializers during emission: invalid managed casts, overflow and
conflicting backing storage still reject.
An existing retained integral resource with `NativeTypedef`, `RAIIFree` and
`InvalidHandleValue` can preserve its fixed-integer signed encoding when the
native backing has the same byte width. This does not apply to
`IntPtr`/`UIntPtr`, incompatible widths, ordinary integer aliases or explicit
native storage remaps.
Retained `IntPtr`/`UIntPtr` providers can compose with fixed-integer header
variants only with complete profile coverage, matching signedness and the
profile's exact native pointer width. Compatible partial observations cannot
narrow an otherwise unchanged common retained contract or erase conditional
metadata. Plain `char` and Windows wide-character aliases can retain the
established provider's character encoding only through their source-bound
native character spelling and matching pointer depth.

Complete named and anonymous record pointees retain their generated record and
fields. The scraper joins the generated managed record through native source
identity before writing the typed alias pointer; it does not invent an anonymous
record name or replace its pointee with an opaque value.
Header-only typed/void record-pointer views require identical native pointer
spelling and one resolved record owner; unelaborated spellings must name that
record. Architecture-specific pointees must belong to the same family recorded
by the cross-architecture merger, with disjoint validated masks. Similar
managed names or matching widths do not establish that identity.

Generated `.header-types.cs` companions use the ordinary emitter namespace mover.
Configure projection placement with the existing `--requiredNamespaceForName`
mapping, just as for other generated declarations. This routing policy is
independent of native typedef semantics and header-annotation parsing.
The mover preserves each header alias's original storage dependencies before
relocation. Ordinary declarations retain source-local native alias and
enum bindings, including when a destination import exposes another type with
the same name. Uses of relocated native types are qualified even when the
consuming declaration stays in place. Namespace-level routes preserve genuine
nested type ownership and nearer nested/type-parameter bindings.
Header companions use the actual emitter dependency namespaces
and framework imports; unresolved dependencies still fail compilation.
Configured delegate pointer and function-pointer remaps add the required C#
`unsafe` modifier without changing ordinary nonpointer delegates.
Generated namespace declarations with numeric-only partition
suffixes retain their established effective prefix namespace. The emitter
repairs that parsed numeric-suffix form without changing partition settings;
other generated syntax errors still fail preflight.
Authored metadata, including active C++ method/parameter/field carriers and
logical enum groups, still requires `parse-win32-annotations`. Without it, the
scraper omits transport carriers and infers native aliases without applying or
validating their authored annotation payloads.

### Production SDK character-set context

The shared Windows SDK settings pass `-DUNICODE` through `--additional` on x86,
x64 and Arm64. Header declarations and native integer/macro probes use the same
compiler arguments, so neutral A/W constants select their W values. Explicit A
and W declarations retain their native narrow/wide types.

This is a Windows SDK project default, not an unconditional scraper CLI default.
Custom contexts can remain ANSI; an explicit `--additional` value of `-UUNICODE`
after the SDK settings overrides the definition. Unicode custom attributes and
string-storage policies are separate from this compilation context.

Native integer evaluation also works without header-annotation parsing.
ConstantsScraper reads supported simple values from the final active macro
definitions. These values generate no Clang macro-value probes or evaluation
calls. Every unresolved value candidate is sent to Clang; known structural and
declaration fragments are reported as non-values. No complex arithmetic
evaluator is used in the scanner.

The original detailed-preprocessing translation unit records active definitions
and annotations using guarded `defined(NAME)` queries. Ordinary bindings use a
clean declaration-only parse with the same compiler arguments. An additional
fresh translation unit evaluates unresolved value expressions only when needed;
it is never used for binding or annotation generation. Constants-only mode omits
the binding parse, and an all-simple input needs no value parse. General macro
binding remains opt-in.

Logical-group exports use the same traversed-or-required typedef selection as
their generated providers. Constants-only annotation export also discovers
typedef dependencies, so a group required from a nontraversed header retains
the same declaration owner as ordinary binding generation, including compatible
redeclarations. Declaration, member-expression and native binding checks remain
strict in the managed consumer.

The MSBuild task scans the original project's traversal headers once before
partition filtering and writes `ScratchDir\native-constant-names.txt`. Its
matching scraper consumes `--constant-names-file`, a unique ordinal-sorted
identifier-per-line query index that includes function-like macro dependencies.
Without that option, the CLI scans its traversal and immediately available
include-directory headers. The index supplies active-definition queries; it
does not request value evaluation for every name.

### Relocating prepared SDK native facts

Constants aggregation can relocate a prepared SDK cache only through the retained
`obj\prepared-sdk-provenance\<architecture>\<identity>\manifest.json` and the
selected prepared root's manifest. The SDK, source, recipe, preparation and full
prepared-header identities must match. Exact SDK-relative header records, native
header proofs, current header bytes and the relocated source profile hash must
also agree. Cache paths and MIDL path identities may differ when the complete
prepared header payload is unchanged.

These checks apply even when absolute paths or cache keys already match, and
support SDK caches on another drive. The producer's architecture-specific
manifest is used when present; the recorded `crossarch` batch manifest can cover
all three targets. A manifest recorded only for another architecture is not a
substitute. Source profiles retain their absolute producer identity and resolve
through the current workspace or their exact prepared SDK header record.

Missing or mismatched identities reject the native input explicitly. Header
basenames or matching constant values do not authorize a binding, and missing
traversed ownership cannot silently fall back to legacy constant parsing. A
changed prepared header payload requires fresh matching producer inputs; these
native facts do not contain a complete per-profile dependency proof that could
authorize partial reuse across different prepared payloads.

### Explicitly traversed selected-toolchain headers

A relative partition `--traverse` selector outside the SDK needs an independently
selected include root and the exact partition/profile owner. When native
constant evaluation is enabled, the shared MSBuild prerequisite uses the
repository's existing Visual C++ tools selector to select the matching compiler
include directory. This prerequisite runs for both scrape targets, including a
fresh constants consumer with `SkipScraping=true`; it does not depend on running
the native header task or retaining a producer's ownership JSON.
The Windows PowerShell selector uses its native module path rather than
inherited PowerShell Core module directories. An explicit
`NativeConstantToolchainIncludeRoots` value supplies alternative selected include
directories (semicolon-separated). Missing, relative or nonexistent selections
are errors; roots are never guessed from a native fact or macro basename.

The selected roots feed native compilation, the macro-name scan and
`ScrapeConstants`. The scraper's incremental state
includes the enabled setting and selected roots. The constants task records these
roots and each planned input's architecture, current partition source, namespace and traversal selectors
in `native-constant-header-ownership.json`. The CLI accepts this version 1 record
through `--nativeHeaderOwnership`; library callers use
`ConstantSelectionOptions.NativeHeaderOwnershipFile`.

The managed consumer joins the exact input path and target to one owner, verifies
the relocated native source path/hash against that partition source, and joins
the full header path to the explicitly selected root plus its complete traversal
selector. Every retained macro, alias and group-member header proof for that
header must match its current bytes. Matching values, a native namespace, equal
bytes in another directory or a header basename do not establish ownership.
Missing selection, source, root, traversal or hash evidence and ambiguous owners
or root candidates reject that input; no first-match root or owner is chosen.
Constants-only targets do not require a fictitious generated binding `.cs` file.

Incremental task reuse also requires the exact ownership plan independently
derived from the configured roots and partition/profile settings. The successful
input fingerprint records content hashes of the planned partition sources and
every selected-root/traversal candidate, including missing alternatives that
could introduce ambiguity. It never discovers these dependencies from native
facts. Changed or deleted physical headers invalidate reuse even when their
timestamps are unchanged; normal consumer revalidation retains typed failures
and blocks the completion marker. Missing or modified generated ownership plans
are rebuilt from the independent configuration and revalidated, not trusted as
new authority or accepted through the cached-success path.

This additional ownership record cannot replace prepared-SDK manifests or relax
their payload/source checks. Successful selection receipts include the exact
`ToolchainHeaderOwnership` resolutions; rejected receipts retain the ownership
record path and every original native-input reference. These consumer-side
checks change the shared `MetadataUtils` assembly and therefore require separate
producer/consumer binary-closure qualification before reusing a native run.

### Default generation diagnostic collection

The normal generation targets collect known, recoverable validation failures at
declaration, input-file, partition and architecture boundaries. This is the
default behavior, not a census-only option. Errors are not deduplicated and
ambiguous ownership never authorizes a fallback value or namespace.

`ScrapeHeaders` keeps its single processor-capped parallel loop: a rejected job
or failed child process does not cancel later independent jobs. Settings JSON
and import-library inputs are validated independently; IDL preparation/compiler
process failures are retained per input. Invalid prerequisites still block the
dependent native binding or constants-publication stage.

The SDK's implicit project-local `autoTypes.json` and `functionPointerFixups.json`
defaults may be absent. Explicit `AutoType` and `FunctionPointerFixup` items remain
required, even when they use those filenames. Present defaults and all configured
inputs are validated normally; malformed settings still reject generation.

I/O failures retiring generated `autotypes.cs` sources are collected as `WMG004`
at `emitter.auto-type-source-retirement`, with the path, architecture and original
exception. Independent retirement and input-preflight checks continue, while
auto-type regeneration, source transformation, compilation and publication remain
blocked.

After a native input has been read and its headers bound, a failed declaration
keeps that entire input ineligible for selection but does not stop local
validation of its later independent facts.

The targets' failure bridge uses `ContinueOnError="ErrorAndContinue"` **only**
to run independent read-only constants and emitter preflights, followed by a
task that returns failure. Thus `ScrapeConstants` depending on `ScrapeHeaders`
does not starve the managed input census. Failed managed emission instead runs
only the final reporter: it does not repeat transformations or preflight over
the failed intermediate sources. Explicit missing or invalid metadata references
are collected individually before semantic compilation; safe source-family and
syntax checks still run without inventing replacement references.

Producer receipts authorize transformation and emission only with supported
`Version: 1` and `Status: "completed"`. Blocked, rejected, unknown, malformed or
unsupported receipts diagnose independently before reference/source checks.
Optional `Errors` and `BlockedStages`, when present on a completed receipt, must
be arrays and empty. The existing successful native-selection receipt remains
valid without either array. Invalid receipt diagnostics retain the original
receipt path and cause; no invalid receipt can authorize a replacement image.

The final failure census is `GeneratedDir\generation-failures.json`. Direct
tool invocations retain their stage report even without MSBuild. Failure and
blocked receipts follow the [version 1 schema](generation-diagnostics.schema.json):

| Report | Contents |
|---|---|
| `scrape-diagnostics.json` | Native partition/profile failures, complete child output and explicit references to those jobs' declaration diagnostics. |
| `<output.cs>.generation-diagnostics.json` | Individual native annotation diagnostics before binding publication. |
| `auto-types-preparation-diagnostics.json`, `function-pointer-preparation-diagnostics.json`, `library-input-diagnostics.json` | Independent preparation input/declaration errors. |
| `ObjDir\idl-generation-diagnostics.json` | IDL source-preparation and compiler process failures. |
| `constants-task-diagnostics.json`, `native-constant-conflicts.json` | Input-plan, SDK identity, native proof, ownership, legacy constant and enum-finalization errors. The successful native selection report retains its existing shape. |
| `constants-preflight-diagnostics.json`, `emitter-preflight-diagnostics.json` | Read-only input validation after an earlier prerequisite failed; dependent selection, transformation, compilation and publication remain blocked. |
| `generation-diagnostics.json` | Managed source, reference, composition, compilation or emission rejection. |

`Errors` retain `Code`, `Stage`, `Message`, `Input`, `Symbol`, `Header`, `Line`,
`Architecture`, `Partition`, `SelectedSdkRoot`, `IdentityCategory` and the
original exception's full `Cause`. Group by stable code/stage/identity and source
context; keep every raw error. Prepared SDK binding errors use
`NATIVE_SDK_BINDING` / `constants.native-inputs` /
`prepared-sdk-header-binding`, including the raw header, input architecture and
selected SDK root. Selected-toolchain binding errors use `NATIVE_TOOLCHAIN_BINDING` /
`constants.native-inputs` / `selected-toolchain-header-binding` with the same
per-input context and original cause. `BlockedStages` records each unrun stage
and its prerequisite; `Reports` names retained stage receipts. Constants failures reference native
input paths, byte lengths and SHA-256 pins, plus source identities, rather than
copying the native-input payloads into another JSON document.

Report membership is scoped to the targets and jobs attempted by the current
failure path, not a recursive scan of unrelated old reports or a timestamp guess.
Read-only emitter preflight neither deletes nor rewrites `generated\obj` or a
previous failed managed report. A successful emission retires the old final
failure census. Failed attempts invalidate success markers and return nonzero.
Known report schema violations produce `WMG999` diagnostics at the report
boundary without stopping later independent report imports; malformed originals
remain referenced on disk. A successful up-to-date `EmitWinmd` target also
retires stale final/preflight failure receipts without rebuilding the image.
No failed/preflight path publishes an incomplete WinMD; successful serialization
uses a same-directory `.pending` file before replacing the output. An existing
valid image is not overwritten by a rejected attempt.

Collection stops at genuine dependencies: invalid native ownership sets block
legacy alias finalization; invalid transformed source/composition blocks the
dependent semantic stages. A partial metadata builder is never resumed.
Unexpected exceptions, cancellation, unavailable tools and unclassified I/O or
native-parser failures remain fatal, with explicit blocked stages; the reporter
does not claim that their remaining work ran. External SDK, MIDL and native
toolchain failures still require their corresponding qualification environment.

### Local phase timing

`Win32MetadataScraper` and `ConstantsScraper` can write local timing reports.
Set `WIN32METADATA_TIMING_DIRECTORY` to an absolute local directory outside the
generated-source tree, then run the usual commands with their unchanged inputs:

```powershell
$env:WIN32METADATA_TIMING_DIRECTORY = 'C:\temp\win32metadata-timing'
dotnet .\bin\Release\net10.0\win-x64\Win32MetadataScraper.dll <remapsOutputPath> @<settings.rsp>
dotnet .\bin\Release\net10.0\ConstantsScraper.dll @<constants.rsp>
Remove-Item Env:\WIN32METADATA_TIMING_DIRECTORY
```

An unset or empty variable disables timing. The disabled path does not create a
report, query the process CPU clock, or emit timing events. An enabled command
reserves a unique `<tool>-<pid>-<guid>.timing.json` file before generation.
Invalid, UNC, or unwritable directories fail the command explicitly; requested
timing is never silently disabled. Reports contain local source/output paths.
Nothing is uploaded, and no timing fields enter native facts or generated source.

The [version 1 schema](generation-timing.schema.json) records parent-linked spans,
monotonic wall time and process CPU deltas across all process threads. CPU time
can exceed wall time. `wallMilliseconds` and `processCpuMilliseconds` include
children; use `selfWallMilliseconds` and `selfProcessCpuMilliseconds` to attribute
cost without counting nested work twice. `childWallMilliseconds` sums direct
children only. IDs follow start order. `exitCode` is the ordinary tool result,
including positive warning counts; it is null if an exception prevented that
result from being reported. Trace serialization happens after the root span ends.

Scraper phases distinguish original/declaration-only/companion/constant-value TU
parsing, native diagnostics, remap discovery, annotation discovery/application,
native provider recovery, PInvoke bindings, constant candidate collection,
scanner routing, value extraction, and serialization/output.
`native-constants.hybrid-route` records presence-query, scanner-resolved,
unresolved-value, non-value and actual value-probe counts.
`native-constants.extract` records actual Clang value-evaluation calls,
scanner-derived integers, accepted/rejected facts and diagnostic occurrences.
Its legacy parse/retry counters are zero; optional value parsing is measured by
`translation-unit.constant-values`. There are no recursive probe batches.
Probe and evaluation counts can differ when a result is non-integral.
Missing explicitly requested definitions can contribute rejected facts without
being probe candidates. No per-constant spans are recorded.

Native facts retain `Evaluation` (`Scanner` or `Clang`) and explicit routes with
reasons, `ValueProbed` and `CompilerEvaluated`. Compiler diagnostics retain their
original text and are attributed only through actual probe locations or notes.
Unassigned native errors still fail the command.

Generated C# sources retain one immutable syntax root across callback-template
discovery, annotation rewriting, companion merging and native-provider recovery.
Unchanged sources retain their original text; rewritten roots are formatted once
when their output is requested. `projection.parse-generated-source` and
`projection.format-generated-source` record those operations separately.
`native-providers.discover` separates semantic type-use binding from native
candidate discovery. Its semantic queries, provider identity checks, by-value
storage validation and resolved-reference shadowing checks are unchanged.

The separate aggregation process records loading native facts and source owners,
ownership/type/alias resolution, native C# writing, legacy text scraping, deferred
legacy aliases, conflict-report writing, enum/remap output, and writer flushing.
Legacy text scraping still streams C# through its existing writers, so its phase
includes that generation work; the flush phase measures the remaining buffered
output. These aggregation phases do not invoke the native compiler. Compare
uninstrumented, timing-disabled and timing-enabled runs with identical inputs
before using a report to discuss architecture changes.

### Native typedef binding decisions

Exported automatic remaps contain renames. The binding context also retains
native self typedefs, explicit `--exclude-auto-remap` no-rename choices and the
existing interface no-rename rule as identities. Authored remaps still win.

Existing `___` typedef-reversion names remain authored temporary names. The
scraper marks such a binding as intentional only when the unsuffixed target is
a native typedef of the exact canonical source tag. Qualified and chained
aliases are checked; pointers, unrelated tags and unknown aliases do not satisfy
the proof. Other remapping diagnostics remain enabled.

### Header annotations

```text
--config
parse-win32-annotations
```

This enables all supported header annotations, not just enum associations. The
scraper reads the annotations from the original Clang AST and emits their metadata
semantics: supported OS, imports, ownership and invalid values, result and lifetime
behavior, logical enum groups and associations, and the rest of the supported
vocabulary. Native declarations and existing SAL remain authoritative.

`AssociatedConstant(NAME)` on a projected enum also requests an object-like macro
constant when its definition is present in the original translation unit. A
separate ClangSharp macro-binding pass includes only those requested names and
their actual provider files; it does not enable macro generation for the
ordinary partition output.
The compiler supplies each constant's type, expression value and active guards.
These remain global constants associated with the existing enum, without adding
enum members or changing native declarations.

Native constant declarations and names supplied by another partition retain
their existing representation. A missing local macro provider does not invent a
value. Multiple original-TU macro definition records, function-like providers and
bindings that cannot produce constant fields fail explicitly, as do exclusions or
remappings that prevent the requested distinct fields. Readonly/pointer
macro bindings are not published as already-written constants.

Successful annotation-enabled scrapes always publish a `.header-types.cs`
companion (or `header-types.cs` in multi-file mode), including a declaration-free
companion when that profile has no additional facts. Its first line is
`// Win32Metadata.HeaderTypes.Success.v1`. Copy these actual companions along with
the ordinary generated sources. Before an annotation-enabled parse, the scraper
invalidates its previous companion; a failed parse is not a successful empty
profile. Removing the last additional fact replaces the companion with the
successful empty form instead of leaving stale declarations.

For combined x86/x64/Arm64 emission, a marked architecture-specific source family
must contain all three successful companions. Missing or mixed-contract profiles
fail with `CSSW004`; the emitter never manufactures their contents. A deliberately
x86-only partition remains the existing all-architecture common-input convention.
Build orchestration must still propagate failed scrape jobs rather than present
their absence as common scheduling.

The emitter evaluates `Apis` constants in their original managed profile before
text deduplication or architecture composition, preserving declared storage and
constant value bits. Unresolved or invalid dependencies, unsupported constant
storage, or a common constant whose storage/value differs between profiles fail
with `CSSW003`, not an arbitrary profile's value. Architecture-varying globals
retain their native name and physical `SupportedArchitecture` masks. Temporary
field identifiers are collision-allocated and restored only from explicit
rename provenance; genuine names ending in `____1` or `____2` remain unchanged,
including their `AssociatedConstant` links.

Retained manual C# inputs keep the emitter's declaration-only diagnostic policy
for parse recovery. Qualification still requires a bound constant value and
rejects semantic initializer errors. Generated and header inputs retain
syntax-error checks, including zero-width errors at initializer boundaries.
Legacy manual `struct NAME;` forwards become partial declarations so an ordinary
generated definition can complete them without discarding native records.
Retained ConstantsScraper `.enums.cs` bags keep global macro ownership. Ordinary
native enums also own loose copies recorded in ConstantsScraper `.constants.cs`
outputs, without removing independent constants from other source scopes.
Header-composed groups use namespace-local ownership after composition.
Repeated observations of one logical header group use its validated
traversed-header namespace before alias-owner comparison, unless a unique
explicit type route exists. A scanned observer namespace is only a fallback
after those routes, regardless of observer count or namespace duplication.
Original producer namespaces remain in the
provenance checks. Conflicting bindings for the same physical native
declaration and canonical group still reject; separate physical carriers are
not collapsed by numeric equality.
Generated record projections bearing the existing `___` typedef-reversion suffix
coalesce only with an exact retained manual provider selected by the existing
namespace route. Their declaration and semantic bindings must agree; the manual
provider keeps its documentation. Conflicting storage or other attributes fail.
Ordinary complete native records remain independent providers.

Before binding constants, each original profile applies the existing checked
primitive-alias conversion against its actual logical-group providers. Retiring
a loose `Apis` constant that is now an enum member does not invalidate its
surviving primitive aliases. This lowering is profile-local and does not change
the original input bytes or bypass missing, ambiguous, or overflowing providers.

Enum-typed constants remain supported when their enum's underlying storage is
invariant. If the same enum identity has different underlying storage in the
available profiles, enum-typed constants fail with `CSSW003` before composition,
even when a particular profile does not define the constant. This avoids
silently binding a surviving field to an arbitrary profile's enum storage.
Unrelated varying enum definitions do not cause primitive constants to fail.

#### Original-IDL structured comments

The same `parse-win32-annotations` option reads owned comments emitted by MIDL.
Each block carries one existing canonical fact and an absolute native target:

```cpp
/* Win32Metadata: interface ::IExample => SupportedOSPlatform("windows6.1") */
/* Win32Metadata: return ::OpenExample => RAIIFree(CloseExample, -1, 0) */
/* Win32Metadata: parameter ::IExample::Run::flags => AssociatedEnum(EXAMPLE_FLAGS) */
/* Win32Metadata: field ::EXAMPLE_RECORD::flags => AssociatedEnum(EXAMPLE_FLAGS) */
```

Use a standard IDL quote, outside field/parameter lists:

```idl
cpp_quote("/* Win32Metadata: interface ::IExample => SupportedOSPlatform(\"windows6.1\") */")
```

Selectors are `interface`/`record`, `method`, `function`, `return`, `parameter`,
`field`, `type`, `enum`, `enumerator`, and `constant`. A parameter appends its
native name to its function/method path. Use emitted property names such as
`::IExample::get_Value::value`. Record typedefs and their tags identify the same
native fields, including compiler-owned anonymous-member injection; distinct type
aliases stay distinct. `return` accepts only RAIIFree and AssociatedEnum.

All existing simple facts are supported with their existing target validation.
Native cleanup, compatible-type, constant and enum references resolve from the
target's native scope. AssociatedEnum also accepts an already-compiled logical
group. Enum/FlagsEnum groups retain the compiled native macro transport; comments
do not evaluate their values. RAIIFree invalids are signed decimal Int64 literals,
not symbols, suffixes, casts, hexadecimal literals or C++ expressions. Existing
native C/C++ annotations retain compiler-evaluated arguments.

Payload strings use ordinary quoted canonical arguments, including escaped quotes
and backslashes. Escape the whole comment again when placing it in `cpp_quote`.
Only actual Clang comment tokens are read, never strings containing marker text.
The first native translation unit supplies included files, skipped conditional
ranges, identities and projection rules. An active comment inside a preprocessor
directive/macro, malformed payload, unknown fact, missing reference, or ambiguous
target fails with WMA001. Comments do not add declarations or change SAL.
Adjacent native MIDL direction/retval blocks remain readable.

Comment targets bind to actual native declarations independently of projection
exclusions. With `exclude-funcs-with-body`, comments on native definitions and
their parameters are still parsed and validated, but those definitions remain
excluded from generated output. A body does not make a native target missing or
resolve an ambiguous non-template overload set.

Canonical record facts use the compiler's complete definition for traversal
eligibility when one exists. A traversed forward does not require projection of
an untraversed definition. Incomplete records without a definition retain the
normal eligibility and unused-fact checks. All native facts are still validated.

Function/method targets and their return/parameter selectors can also use the
source-written name of an object-like macro whose replacement is one identifier.
The first translation unit must link both expansion and spelling locations of
the declaration name to that exact replacement token and actual native name.
Later macro changes do not affect binding. Expanded names remain valid; distinct native candidates
remain ambiguous. Function-like or declaration-producing macros do not supply
target aliases. This does not expand comment payloads or change native reference
lookup, parameter identity, declarations, or projection rules.

The scraper reports independent WMA001 failures together for one partition,
ordered by source file, line, column and native target. Invalid declaration facts
are excluded from dependent checks to avoid cascaded errors. The complete report
is written to standard error, and any error prevents generated bindings and
remap output. This includes independently unprojected facts at the final projection
check; unused facts remain fatal. Unexpected implementation exceptions remain
fatal. Fix the reported facts before checking later composition and projection
stages.

An enum association can use a metadata-only forward declaration of the original
native enum tag and typedef when its definition is in another header or partition.
The complete original definition must still participate in metadata generation.
The scraper uses native cursor identity and source locations to omit only the
forward's empty generated declaration; real empty enums, complete opaque enums,
and unrelated same-name enums remain intact. Do not substitute a primitive alias
or duplicate the members of a native enum.

The native `_Win32_AssociatedEnum_(NAME)` macro and structured-comment
`AssociatedEnum(NAME)` use the same name resolution after the complete translation
unit is parsed. Visible native enums and logical groups retain their resolved
identity and remappings. An absent unqualified metadata-only name may instead be
supplied by another partition or retained enum source. A visible scalar alias does
not become an enum, even inside a metadata-only guard; remove obsolete artificial
scalar forwards from their owning source instead. Native comment target binding
remains strict. The final emitter requires exactly one emitted enum per applicable
architecture after namespace assignment, remaps, group merging and enum additions;
missing or ambiguous associations fail with WMA003. No native typedef or include
is needed just to make an association parse. Existing typed association transports
remain readable.

The tooling can run with the existing sidecar and manual C# inputs, header
annotations, or a partially migrated combination. The tooling PR does not retire
the SDK's existing annotation inputs. The header-migration layer supplies
`generation/WinSDK/patches/SdkHeaders.json` and removes the replaced inputs.
Without that default recipe, the SDK project uses its existing headers. An
explicit `SdkHeaderRecipe` is always processed; a missing or invalid explicit
recipe fails instead of silently selecting the legacy headers. Manual C# staging
continues to track the complete input glob, so deleted inputs do not survive an
incremental switch to header-only generation.
Native constant evaluation remains opt-in on the legacy SDK path. Selecting a
header recipe enables it unless `EvaluateNativeConstants` is explicitly set;
legacy callers can select it with `-p:EvaluateNativeConstants=true`.

The repository annotation header is also a pinned MIDL input. Extending its
vocabulary requires updating both `sourceGitTree` and that input's `sourceSha256`
in `generation/WinSDK/patches/SdkHeaders.json`. Preserve the previous prepared
cache: changed MIDL input bytes need their own qualified preparation identity.

Use the [annotation specification](copilot/plans/shift-left-annotation-spec.md#attribute-reference)
for the complete vocabulary, valid targets, and examples. The options below describe
the existing response-file configuration; API-specific metadata moves into the owning
SDK header or original IDL.

### Bulk native-header annotation authoring

`--declaration-map` followed by a JSON output path exports native function and record
identities after the normal Clang parse, without generating bindings or remaps.
The schema includes the translation unit, partition, compiler arguments, source
SHA256 values, USRs, native qualified names, types, and spelling/expansion locations.
Offsets and half-open declaration extents are **bytes**, not character positions.
This is an opt-in authoring aid; ordinary scraping is unchanged.

Add `--declaration-map-symbol` followed by native names or qualified names to export
only those declarations and their members. This bounded mode also includes parameters,
fields, typedefs, enums and enum constants, with parent USRs, canonical type-declaration
USRs, and zero-based native parameter ordinals (including unnamed parameters). An
unqualified name retains matching declarations in every namespace and physical owner;
it does not establish unique ownership. The default, unfiltered map retains its
existing declaration kinds.

For explicitly allocated original-header owners, the bulk helper can export maps
for all three architectures and propose cumulative SDK patches. Map exports use
the owning partition's traversal include parents, including nested SDK directories
such as `um\cpdk`, just like the normal scraper:

```powershell
dotnet build .\sources\Win32MetadataScraper -c Release
.\scripts\Convert-SdkHeaderAnnotations.ps1 `
    -OwnerMap C:\work\owners.json `
    -Partition MenuRc,Services `
    -Original 'um\winuser.h','um\winsvc.h' `
    -OutputDirectory .\artifacts\bulk-annotations\batch-01
```

The owner inventory uses `readyOriginalOwners` records with `original`,
`partitionCandidates`, `supportedOS`, and `setLastError`; each fact supplies its
exact retained `symbol` and `value`. Its `snapshot` identifies the selected SDK
package root, package version, and include version. Inventory candidates are not
proof of declaration ownership: the helper checks the parsed identity and original
bytes before placing an annotation. It indexes only the selected fact names, but
retains every observed physical declaration owner for those names.
An exact `EXTERN_C` linkage prefix is preserved, with annotations inserted inline
after linkage and before the parsed declaration; other shared-line prefixes remain
explicit residuals.
The reviewed `WINOLEAPI`, `COMBASEAPI`, and `PSSTDAPI` return wrappers, including
their typed `_` forms, require an exact parsed source prefix. Unknown lookalike
macros remain residuals.

Declaration maps also export native struct/class identities and definition sites.
For global record SupportedOS facts, the authoring helper admits direct record
declarations and the reviewed `DECLARE_INTERFACE_`, `DECLARE_INTERFACE_IID_`,
`DECLARE_MAPI_INTERFACE_`, `interface DX_DECLARE_INTERFACE`, and
`interface DWRITE_DECLARE_INTERFACE` forms. It binds the
original name's spelling bytes, USR, full declaration extent and source hash,
retaining unknown macros, additional physical definitions and unparsed conditional
definitions. Forward declarations
are not separate definition owners. A `DECLARE_MAPI_INTERFACE_PTR` reference is
covered only by its hash-bound, same-USR parsed forward declaration. A metadata-only
typed alias carries the fixed OS macro through the existing primary-typedef-to-record
bridge; it does not place
an attribute before an expanded record keyword or change native C/C++ declarations.
Record SetLastError facts remain legacy. Existing function-only maps remain valid
for functions; record owners require fresh maps containing their definitions.

Review `report.json` and the proposed patches. Reuse exported JSON maps through
`-DeclarationMaps` instead of `-Partition` when useful. A fresh output directory is
required for every invocation. Adding `-Apply` installs patches and SDK recipe pins,
enables annotation parsing in configured owning partitions, and removes only exact
sidecar rows whose discovered declarations are all covered. Unrouted owners, generated headers,
overloads, macro-produced declarations, additional owners, unparsed conditional
occurrences, and failed configurations remain explicit residuals. Retained facts
stay entirely in sidecars, without partial annotations that would duplicate legacy
attributes. Only fully covered facts are annotated and removed.
Original IDL requires the separate original-IDL authoring path.

Run representative normal scrapes and native checks after applying a batch.
The machine-readable counts describe authored source deltas, not full-SDK or
final-winmd qualification.

### Original-IDL batch authoring

`scripts\Convert-SdkIdlAnnotations.ps1` authors cumulative SDK-relative IDL patches
from a reserved schema-1 owner map. Each `owners` entry contains `original`,
`sourceSha256`, `generatedHeaders`, `partitionCandidates`, and exact `facts`
(`category`, `symbol`, `value`, plus optional inventory provenance).

```powershell
.\scripts\Convert-SdkIdlAnnotations.ps1 -InputMap .\artifacts\idl-owners.json `
    -SdkIncludeRoot "$sdk\c\include\10.0.26100.0" `
    -OutputDirectory .\artifacts\idl-authoring
```

The tool binds interface definitions in original shipped IDL, ignoring comments
and forward declarations. Interface facts use the structured-comment transport
above, without an annotated forward typedef. Preserve original bytes, guards,
attributes, method order and the selected SAL bootstrap.
Native function-like attribute macros are kept intact when every source definition
expands to an attribute list; carriers precede the original invocation.
It also binds unique native function prototypes in consecutive `cpp_quote`
statements with an explicit `STDAPI`, `STDAPI_(type)`, `SHSTDAPI`, or HRESULT/DWORD
`STDAPICALLTYPE`, `STDMETHODCALLTYPE`, or `WINAPI` prefix and a complete parameter
list ending in a semicolon. Consecutive quoted return-type and calling-convention
lines are kept intact. The emitted comment names the bound native function,
preserving linkage, return type, calling convention, SAL and original whitespace.
If the source cannot be patched strictly, the exact fact remains legacy debt.
Calls, definitions, comments and
incomplete or ambiguous prototypes are not admitted. Rerun with the owner's full
fact map to preserve already-authored interface annotations in cumulative patches.
Ambiguous targets, unsupported OS vocabulary, existing carriers and other
unsupported facts are reported verbatim as retained legacy debt. It never removes sidecar
rows or changes the installed SDK or repository recipe. The report's
`candidateGeneratedHeaders` are ownership candidates, not measured generated
outputs. Add admitted patches, original-input closure and generated outputs to
`SdkHeaders.json`, then use the existing preparation/MIDL and native checks before
claiming applied output or removing equivalent sidecar rows. Authored source is
not compile or full-SDK acceptance.
Normal-scrape proof must exclude relocated rows from every resolved response
input: `supportedOS.rsp` is also consumed by the scraper, not just the emitter.
Preserve existing native contracts such as IDL `[retval]` and enumerate their
exact activation differences separately from relocated availability facts.
For an incremental callable batch, a parser-enabled published-before control
preserves existing interface carriers and native contracts on both sides.
With the newly relocated rows absent from both resolved normal inputs, require
the exact new function floors only in the prepared-after source and compare
the complete remaining C# syntax without suppressing unrelated attributes.
Selected callable facts can pin an `existingImportLibrary` in the qualification
report to require the same nonempty `DllImport` in actual normal output.

The same native prototype binding supplies function `SetLastError` comments.
Interface result overrides use `method ::Interface::Method => PreserveResult`;
parameter overrides use their absolute native method/parameter identity and
existing canonical fact. Keep native MIDL attributes and native inline SAL
annotations untouched. Do not insert metadata into a native `[annotation]`:
it overrides MIDL's default SAL and is restricted on nonlocal declarations.
Only one complete native method/parameter can bind each fact;
forwarded, ambiguous, unsupported and already-native `[retval]` contracts remain
explicit residuals. Existing native facts do not earn new conversion credit.

Positive/negative Optional and ComOutPtr overrides use canonical Boolean payloads
on the exact native parameter. Native declarations, order, SAL and inline
annotations are not rewritten. Short authoring selectors must still bind one
actual parameter; the emitted comment names the complete native method path.
Resolve property methods to their real generated `get_`/`put_` names.

Authoring switches still control which fact classes the authorer admits; they do
not select a different reader or a native `[annotation]` metadata transport.
`-SharedSalBootstrap` additionally supplies native `sal.h` through `cpp_quote`
when absent, using the selected preparation policy's shared vocabulary. It does
not add a per-original annotation-header include or remove existing includes.
Neither switch activates the parser or qualifies a prepared SDK. Cumulative
patches, exact input hashes and the normal `-Apply` admission checks still apply.

Existing `associated-enum-use` rows can bind one original IDL struct field or
interface method parameter. The authorer inserts
`field ::Record::field => AssociatedEnum(NativeEnum)` or the complete native
parameter selector through `cpp_quote`. It preserves native types,
storage, field order and SAL; imported, quoted, ambiguous and unsupported targets
remain exact residuals. The named enum must resolve in the actual native compiler,
and the actual normal projection must contain the exact associated-enum payload
on the field or every native/derived method and vtable delegate parameter.
This does not implement legacy direct-enum-use type substitutions.
For an anonymous original enum with a unique existing same-original MIDL-tag
remapping, the carrier references that real generated `enum` tag. The existing
global parser remap remains intact; native compilation and the exact normal
payload must prove the binding. No native enum declaration or member is added.

For native-authored C/C++ whose enum is declared later, the shared vocabulary also supports a
post-definition `_Win32_AnnotateField_(Record::field, _Win32_AssociatedEnum_(Enum))`
carrier. Place it after the complete native record and enum. The original field keeps its scalar storage and
the enum retains its native members. The reader resolves a compiler-bound instance
field and applies the existing annotation before projection. Unknown or non-field
targets, missing annotations, duplicate facts and raw-string target substitutes
fail. The carrier is active in metadata-enabled Clang C++, including `CINTERFACE`,
and disappears in ordinary builds and C. This is a target transport, not a new
semantic annotation. Original-IDL comments bind the same native field without
introducing that compiler-expression carrier.

Normal member controls follow native inheritance and each wrapper's exact
vtable-delegate reference, preserving receiver and parameter signatures.
Anonymous `NativeTypeName` coordinate changes are enumerated separately.
Each requires complete native header byte recovery after removing only the
exact new method carriers, with the line shift explained by those carriers.

Recipe `partitions` do not activate the normal scraper. After qualifying and
admitting exact original/output pairs, rerun the authorer with `-Apply` to enable
`parse-win32-annotations` in their actual configured `--traverse` owners. This
switch applies only normal parser settings: source patches, recipe admission and
sidecar cleanup remain separate. Existing settings bytes and other partitions
are preserved; unconfigured owners fail rather than inventing namespace or
traversal settings. `-SdkProjectRoot` selects an isolated SDK project for this
step. The report's `normalParserActivation.ready` is false when recipe admission
is missing, normal ownership is unresolved, or an actual owner is not enabled.

Header-generated `[NativeTypedef]` wrappers can compose with retained AutoTypes
wrappers of the same fully qualified identity and unmanaged `Value` storage.
The scraper infers supported native scalar/data-pointer aliases and their
referenced typedef dependencies as described above. No cleanup, invalid value,
compatible type, or OS version is implied. `NativeTypedef` is not accepted as a
header annotation or structured-comment fact, and the canonical helper does not
define `_Win32_NativeTypedef_`. Inferred identity preserves written alias binding,
deduplicates native redeclarations, and emits one wrapper/`Value`/attribute.
Storage preserves actual native width, signedness, and data-pointer depth;
pointer-sized integral remaps must match the target ABI. Pointer levels with the
target's ordinary width retain pointer storage. A non-default-width level, such
as x64 `__ptr32` or x86 `__ptr64`, uses matching fixed-width unsigned storage and
retains its native type provenance. Unsupported width/alignment and incompatible
explicit CLR storage mappings fail with WMA001 before output.
Complete/incomplete record **pointers** are supported, not record **values**, native enum values,
logical groups, callbacks, arrays, references, or C++ `using` aliases. Unsupported
native scalar representations fail with WMA001 rather than producing recursive
`Value` storage or guessing a pointer from an old `IntPtr` field.
When a source-proven incomplete backing record is explicitly excluded, native
typedef storage uses `void*`, preserving every outer pointer level and the
typedef's strong identity. Otherwise the existing source-backed pointee projection
is retained. Complete record pointees retain their typed pointers and original
definitions; do not exclude a complete backing record needed by a header-owned
wrapper. Ordinary bindings also use opaque pointer storage when an elaborated
native type embeds an incomplete declaration in a different lexical record scope.
Neither path erases a complete record or substitutes `void` for an unknown managed
type.
Wrapper storage honors ClangSharp's effective pointer-sized typedef remaps,
including defaults and pointer aliases; logical enums keep fixed integral storage.
The emitter keeps one wrapper and unions compatible attributes, including a
header-owned `AlsoUsableFor` and the complete retained cleanup/invalid-value set.
Conflicting storage, annotations, ordinary declarations or incomplete retained
cross-architecture coverage fail explicitly. This is wrapper metadata projection,
not a type-level native cleanup carrier or permission to retire global policies.
Producer-owned return/output annotations replace a legacy lifecycle policy only
when they represent the same ownership contract and its complete invalid set;
unresolved and invalid-only policies remain retained.
Do not remove equivalent legacy rows or claim authoring acceptance until it is
true, then verify actual normal generated declarations as well as native controls.

Preparation accepts original CRLF line endings, including first-line insertions,
while keeping strict rejection of trailing spaces/tabs and space-before-tab
indentation errors.

### Generation performance guards

`tests\Win32MetadataScraperTests\GenerationPerformanceTests.cs` runs with the
ordinary scraper suite, including `scripts\DoTests.ps1`; no environment variable,
installed Windows SDK, or opt-in benchmark runner is required. The fixtures use
the repository's copied headers and pinned native compiler packages.

Each case validates a warm-up and five measured executions, then **fails if the
median wall-clock time exceeds its fixed budget**. A single scheduling stall
does not fail the median. The xUnit collection disables parallel execution with
other collections in the same test process. Scrape timings include starting the
real scraper process, native parsing/binding, and writing outputs; warming up
does not remove per-process startup costs. Emitter timing includes actual
compilation and physical WinMD generation. Fixture setup and output assertions
are outside the timed region, but assertions run after **every** execution,
including warm-up. Scrape outputs are deleted before each execution so stale
files cannot satisfy the checks.

Initial Release calibration on 2026-10-23 used .NET 10.0.13 on Windows x64 with
32 logical processors. Budgets are rounded to approximately 2–3 times the
observed medians for CI headroom, not intended as portable benchmark scores:

| Workload and required output | Initial median | Failing median above |
| --- | ---: | ---: |
| Two UTF-8 includes, 2,000 declarations: all parameter directions and the single requested `SetLastError` | 2,982 ms | 6,000 ms |
| 8,192 unrelated macros, no associated constant: one method, no generated fields | 997 ms | 3,000 ms |
| 8,192 unrelated macros, one associated constant: one method, one enum/association, exactly one companion field with value 32 | 1,084 ms | 3,000 ms |
| 1,028 macro value candidates: exactly 1,025 typed integer values and three explicit rejections | 1,203 ms | 3,000 ms |
| Three profiles, each with 256 header groups and 768 globals: 256 physical groups and 1,024 physical globals | 1,788 ms | 5,000 ms |
| One 6,418-constant file, qualified in all three profiles: exactly 6,418 physical `uint` globals without architecture masks | 1,370 ms | 4,000 ms |

Native extraction checks every value's storage, literal and provenance,
including unsigned wraparound, signed 64-bit arithmetic and native `sizeof`.
Emission checks every group's members/association and every constant's
signature, value, alias result and architecture mask (x86 = 1, x64/Arm64 = 6).
Dropping declarations, constants, profiles or unsupported-result reporting
therefore cannot make a timing guard pass.

The large-file workload matches the declaration count in a largest SDK native
constant file and catches repeated per-initializer semantic-diagnostic work
that smaller files do not expose. Its five-sample median was **20,168 ms before
per-tree/per-profile error-span caching**, versus **1,370 ms after** (1,569 ms on
repeat). The unfixed implementation failed even the initial, looser 6,000 ms
guard; the final 4,000 ms budget retains approximately threefold headroom. The corresponding
`HeaderConstantDiagnosticTests` verify that initializer errors still produce
`CSSW003`, including zero-width boundary errors in generated sources, while
legacy manual parse recovery remains compatible. Unrelated diagnostics and
warnings do not become qualification errors.

Run just these guards from the repository root:

```powershell
dotnet test tests\Win32MetadataScraperTests -c Release --filter "Category=Performance" `
  --logger "console;verbosity=detailed" --logger "trx;LogFileName=generation-performance.trx" `
  --results-directory artifacts\generation-performance-results
```

Each test attaches its warm-up, all five samples, median and budget to the test
output/TRX, with a `PERF` summary for log searches. The default minimal console
logger hides output from passing tests; the detailed logger above displays it.
Retain the TRX as a CI artifact to compare successful measurements over time.
The failure thresholds apply regardless of logger settings. Reproduce a breach
in a quiet Release run before changing a budget; investigate sustained regressions
rather than raising thresholds to conceal unrelated build load.
These synthetic guards complement, rather than replace, full-SDK build timing.

### Architecture-specific callback references

Combined x86/x64/Arm64 emission keeps callback signature variants and propagates
their architecture masks through the generated declarations that reference them.
This includes `IntPtr` plus `NativeTypeName` fields, direct callback references,
containing records, and imported method parameters and return types. An otherwise
identical partition cannot be collapsed before these dependencies are composed.
Native type-name annotations retain their original spelling.

Native callback remapping selects the definition that covers the owning
declaration's architecture mask. Pointer reduction also recognizes the internal
variant names. Parameter types, native-width values, pointer depth, and the
existing calling-convention projection remain part of the emitted signatures.

When callbacks have multiple emitted variants, metadata population first records
the local definition handles, then populates a fresh builder with those handles
available to architecture-specific forward references. It verifies the handle
plan before writing the image. Equal public names cannot select an unrelated
variant through a shared local type reference.

### Architecture-aware WinMD integrity checks

Native constant values or storage can differ between architectures. The emitter
then writes multiple fields with the same physical name and separate
`SupportedArchitecture` masks. `WinmdUtils showDuplicateConstants` accepts these
only when the owner and exact field spelling match and the masks do not overlap.
Missing architecture attributes mean all architectures. Overlapping definitions,
case-only name collisions, and different owners still fail the check.

`WinmdUtils showBrokenArchTypes` follows the referenced type definition for each
required architecture. It does not inspect the x64 version of a record when
checking its ARM64 consumer. Invalid method parameters, method return types, and
delegate return types cause a failing exit code. Recursive delegate signatures
are checked without repeatedly walking the same definition and architecture.
Physical WinMD fixtures cover both valid alternatives and unavailable types in
`HeaderConstantIntegrityTests.cs`.

### Remapping

````
--remap
midihdr_tag=MIDIHDR
mmtime_tag=MMTIME
````

This allows types to get remapped from what clang scraped into what you would like to see in the final metadata. A common pattern in Win32 looks like this:

````
typedef struct fooTag {
    int x;
    int y;
} FOO;
````

It's not obvious to the scraper that you would rather see FOO instead of fooTag in the metadata, but adding "fooTag=FOO" under the --remap section in baseRemap.rsp will make sure it's scraped as FOO instead of fooTag.

### With type

````
--with-type
D3D12_VIDEO_PROCESS_DEINTERLACE_FLAGS=uint
````

This ensures that the enum D3D12_VIDEO_PROCESS_DEINTERLACE_FLAGS will be based on uint instead of the default int.


### With attribute

````
--with-attribute
D3D12_VIDEO_PROCESS_DEINTERLACE_FLAGS=Flags
````

This adds the Flags attribute (e.g. [Flags]) to D3D12_VIDEO_PROCESS_DEINTERLACE_FLAGS.

### Exclude

````
--exclude
LPWAVECALLBACK
````

Sometimes there are types you don't want to get scraped. It could be that that the type is redundant, or maybe you had to add a manual version of it because it doesn't scrape well.

### With library

````
--with-librarypath
VerifierEnumerateResource=verifier
````

Some functions may not appear in any .lib files. If you know the correct DLL, you can set the function to manually use the correct DLL.


## Changing a field or parameter

The emitter can modify fields and parameters by adding attributes and/or changing the type.

````
--memberRemap
JOBOBJECT_BASIC_LIMIT_INFORMATION::LimitFlags=JOB_OBJECT_LIMIT
SHGetKnownFolderPath::ppszPath=[FreeWith("CoTaskMemFree")]
````

The first statement changes the type of the field LimitFlags on the struct JOBOBJECT_BASIC_LIMIT_INFORMATION from a uint to an enum named JOB_OBJECT_LIMIT.
The second statement adds an attribute to the ppszPath parameter of the SHGetKnownFolderPath function.

## Emitting Options

Once ClangSharp has scraped the files, the emitter turns the scraped data into a .winmd. Like ClangSharp, options are passed to the emitter via .rsp files. These options allow for further fine-tuning of metadata.

````
--requiredNamespaceForName
# region appmgmt.h
APPCATEGORYINFO=Windows.Win32.UI.Shell
APPCATEGORYINFOLIST=Windows.Win32.UI.Shell
# endregion appmgmt.h
````

Sometimes a header may contain types that you want in different namespaces. ClangSharp will put all types or APIs from a given header into a single namespace, but this option lets you move them to a different namespace. In the main project, these are kept in [generation/WinSDK/requiredNamespacesForNames.rsp](../generation/WinSDK/requiredNamespacesForNames.rsp).

(The regions are for organizational purposes only. The parser ignores them.)

## Adding a member to an enum

````
--enumAddition
CLSCTX::CLSCTX_ALL=CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER|CLSCTX_LOCAL_SERVER|CLSCTX_REMOTE_SERVER
````

This tells the emitter to add a member named CLSCTX_ALL to the enum CLSCTX with the value equal to "CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER|CLSCTX_LOCAL_SERVER|CLSCTX_REMOTE_SERVER".


## Forcing an enum to be a "flags" enum

````
--enumMakeFlags
DXGI_DEBUG_RLO_FLAGS
````

This tells the emitter to add the [Flags] attribute.

## Creating enums from scraped constants

The build system can construct enums out of constants it finds in headers. Projects include an enums.json to tell the system how to construct enums. For example, look at a fragment of [generation/WinSDK/enums.json](/generation/WinSDK/enums.json):

````json
  {
    "name": "WNDCLASS_STYLES",
    "flags": true,
    "autoPopulate": {
      "filter": "CS_",
      "header": "WinUser.h"
    },
    "members": [],
    "uses": [
      {
        "struct": "WNDCLASSA",
        "field": "style"
      },
      {
        "struct": "WNDCLASSW",
        "field": "style"
      },
      {
        "struct": "WNDCLASSEXA",
        "field": "style"
      },
      {
        "struct": "WNDCLASSEXW",
        "field": "style"
      }
    ]
  }
````

This tells the constants scraper create a new enum named WNDCLASS_STYLES and make it a Flags enum. The scarper will look for constants that start with "CS_" in WinUser.h and add them to the enum. Finally, it will change the type  WNDCLASSA::style and other other listed fields to use the new enum.

## Function pointer fixups

Because ClangSharp emits both prototypes and pointers to prototypes as delegates, it can be tricky to get them to emit correctly. Projects can include a functionPointerFixups.json file to make sure things get represented correctly. Look at a fragment of [generation/WinSDK/functionPointerFixups.json](/generation/WinSDK/functionPointerFixups.json):

````json
  {
    "name": "PTHREAD_START_ROUTINE",
    "pointerType": "LPTHREAD_START_ROUTINE",
    "alreadyPointer": true
  },
````

Now let's look at the C definition:

````C
typedef DWORD (WINAPI *PTHREAD_START_ROUTINE)(
    LPVOID lpThreadParameter
    );
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
````

The json tells the build system that PTHREAD_START_ROUTINE is the prototype name and that it's already a pointer. It should get remapped to LPTHREAD_START_ROUTINE.

Here's another one:

````json
  {
    "name": "QUERYHANDLER",
    "pointerType": "PQUERYHANDLER"
  },
````

````C
DWORD __cdecl
QUERYHANDLER (LPVOID keycontext, PVALCONTEXT val_list, DWORD num_vals,
          LPVOID outputbuffer, DWORD FAR *total_outlen, DWORD input_blen);

typedef QUERYHANDLER FAR *PQUERYHANDLER;
````

The json tells the build system that QUERYHANDLER is the prototype name but it wasn't defined as a pointer ("alreadyPointer" is assumed to be false if not present). It should get remapped to PQUERYHANDLER.

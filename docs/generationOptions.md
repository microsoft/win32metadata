# Inputs Used to Create Win32 Metadata

Metadata is created from headers/libs through two different stages: scraping and emitting.

This project uses [ClangSharp](https://github.com/Microsoft/ClangSharp) to scrape C headers into C# files.

Once the C# files are written by ClangSharp, the emitter turns these files into a Windows Metadata (.winmd) file.

There are different options you can pass to the scraping and emitting stages to improve the final metadata. Most options are passed to the stages via response files (.rsp files). There are also two .json files that provide additional information to the build system.


## Scraping Options

Scraping options are passed to ClangSharp via .rsp files. For the Windows Win32 metadata project, all partitions share the [generation/WinSDK/scraper.settings.rsp](/generation/WinSDK/scraper.settings.rsp) file. This allows partitions to interpret the headers in the same way.

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
An existing native scalar/data-pointer `typedef` can request identity alone with
valueless `_Win32_NativeTypedef_` (`Win32Metadata.NativeTypedef`). Original-IDL
`cpp_quote("/* Win32Metadata: type ::Alias => NativeTypedef */")` uses the same
reader path. No cleanup, invalid value, compatible type, or OS version is implied.
The explicit marker preserves written alias binding, deduplicates native
redeclarations, and emits one wrapper/`Value`/attribute only when that native
identity is traversed and not excluded. Unannotated aliases are not promoted.
Storage preserves actual native width, signedness, and data-pointer depth;
pointer-sized integral remaps must match the target ABI. Each pointer level must
have the target's ordinary pointer width. Non-default widths (for example x64
`__ptr32` or x86 `__ptr64`), including beneath ordinary outer pointers and typedefs,
fail with WMA001 before output rather than losing the qualifier or becoming an
integer. Complete/incomplete record **pointers** are supported, not record **values**, native enum values,
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
| 1,028 native probes across batches of 512 + 512 + 4: exactly 1,025 typed integer values and three explicit rejections | 1,203 ms | 3,000 ms |
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
`CSSW003`, including zero-width boundary errors, while unrelated diagnostics
and warnings do not become qualification errors.

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

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

An enum association can use a metadata-only forward declaration of the original
native enum tag and typedef when its definition is in another header or partition.
The complete original definition must still participate in metadata generation.
The scraper uses native cursor identity and source locations to omit only the
forward's empty generated declaration; real empty enums, complete opaque enums,
and unrelated same-name enums remain intact. Do not substitute a primitive alias
or duplicate the members of a native enum.

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
and forward declarations. It inserts the reviewed
`_Win32_AnnotateInterface_` carrier before native attributes and adds the SAL
bootstrap without rewriting existing bytes, guards, attributes or method order.
Native function-like attribute macros are kept intact when every source definition
expands to an attribute list; carriers precede the original invocation.
It also binds unique native function prototypes in consecutive `cpp_quote`
statements with an explicit `STDAPI`, `STDAPI_(type)`, `SHSTDAPI`, or HRESULT/DWORD
`STDAPICALLTYPE`, `STDMETHODCALLTYPE`, or `WINAPI` prefix and a complete parameter
list ending in a semicolon. Consecutive quoted return-type and calling-convention
lines are kept intact. The public OS macro
is inserted immediately before the function name, preserving native linkage,
return types, calling conventions and SAL. If that original line has trailing
whitespace, it uses the equivalent position after the parameter list instead,
without cleaning native bytes or weakening patch checks. If neither line can be
patched strictly, the exact fact remains legacy debt. Calls, definitions, comments and
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

The same native prototype binding supports function `setLastError` facts through
`_Win32_SetLastError_`. Exact interface method
`CanReturnMultipleSuccessValues`/`CanReturnErrorsAsSuccess` overrides use the
existing `_Win32_AnnotateMethod_(Interface::Method, _Win32_PreserveResult_)`
carrier inside the original interface's guards. Native method parameter
`RetVal` overrides use `[annotation("_Win32_Retval_")]` alongside the untouched
MIDL attributes. If a parameter already has one native inline `annotation`
payload, the token is appended inside that same payload: MIDL otherwise keeps
only the last annotation and loses the metadata. Multiple existing annotation
payloads remain residuals. Only one complete native method/parameter can bind each fact;
forwarded, ambiguous, unsupported and already-native `[retval]` contracts remain
explicit residuals. Existing native facts do not earn new conversion credit.

`-AllowCompleteInterfaceParameterCarriers` opts into the existing selected
`_Win32_Optional_(true|false)` and `_Win32_ComOutPtr_(true|false)` transports for
exact positive or negative parameter overrides. Interface parameters use
`_Win32_AnnotateParameter_(Interface::Method, parameter, annotation)` after a
complete interface at matching IDL and quoted-native global scope. An existing
trailing `cpp_quote` region is preferred but is not required. Native declarations,
parameter order, SAL and inline annotations are not rewritten. A short
`Interface::parameter` selector must identify exactly one actual method parameter;
ambiguous parameters and property methods remain residuals rather than guessing
native `get_`/`put_` names. Native function parameters in one complete `cpp_quote`
prototype use the same selected override macro without changing their native SAL.

The option is additive to this authorer's existing default: without it, parameter
overrides retain the prior disposition and existing method/retval placement is
unchanged. The two new switches follow all existing positional parameters.
`-SharedSalBootstrap` additionally supplies native `sal.h` through `cpp_quote`
when absent, using the selected preparation policy's shared vocabulary. It does
not add a per-original annotation-header include or remove existing includes.
Neither switch activates the parser or qualifies a prepared SDK. Cumulative
patches, exact input hashes and the normal `-Apply` admission checks still apply.

Existing `associated-enum-use` rows can bind one original IDL struct field or
interface method parameter. The authorer inserts
`[annotation("_Win32_AssociatedEnum_(NativeEnum)")]`, or appends the token inside
the single existing native annotation payload. It preserves native types,
storage, field order and SAL; imported, quoted, ambiguous and unsupported targets
remain exact residuals. The named enum must resolve in the actual native compiler,
and the actual normal projection must contain the exact associated-enum payload
on the field or every native/derived method and vtable delegate parameter.
This does not implement legacy direct-enum-use type substitutions.
For an anonymous original enum with a unique existing same-original MIDL-tag
remapping, the carrier references that real generated `enum` tag. The existing
global parser remap remains intact; native compilation and the exact normal
payload must prove the binding. No native enum declaration or member is added.

For a field whose enum is declared later, the shared vocabulary also supports a
post-definition `_Win32_AnnotateField_(Record::field, _Win32_AssociatedEnum_(Enum))`
carrier. Place it after the complete native record and enum; original IDL emits
the carrier through `cpp_quote`. The original field keeps its scalar storage and
the enum retains its native members. The reader resolves a compiler-bound instance
field and applies the existing annotation before projection. Unknown or non-field
targets, missing annotations, duplicate facts and raw-string target substitutes
fail. The carrier is active in metadata-enabled Clang C++, including `CINTERFACE`,
and disappears in ordinary builds and C. This is a target transport, not a new
semantic annotation. The IDL authorer's default inline placement is unchanged;
it does not automatically select or place this late-field carrier.

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

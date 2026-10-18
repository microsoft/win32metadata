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

Use the [annotation specification](copilot/plans/shift-left-annotation-spec.md#attribute-reference)
for the complete vocabulary, valid targets, and examples. The options below describe
the existing response-file configuration; API-specific metadata moves into the owning
SDK header or original IDL.

### Bulk native-header annotation authoring

`--declaration-map` followed by a JSON output path exports native free-function
identities after the normal Clang parse, without generating bindings or remaps.
The schema includes the translation unit, partition, compiler arguments, source
SHA256 values, USRs, native qualified names, types, and spelling/expansion locations.
Offsets and half-open declaration extents are **bytes**, not character positions.
This is an opt-in authoring aid; ordinary scraping is unchanged.

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
bytes before placing an annotation.

Review `report.json` and the proposed patches. Reuse exported JSON maps through
`-DeclarationMaps` instead of `-Partition` when useful. A fresh output directory is
required for every invocation. Adding `-Apply` installs patches and SDK recipe pins,
enables annotation parsing in configured owning partitions, and removes only exact
sidecar rows whose discovered declarations are all covered. Generated headers,
overloads, macro-produced declarations, additional owners, unparsed conditional
occurrences, and failed configurations remain explicit residuals. A retained fact
may already have some source annotations; it is not counted as fully converted.
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

The tool binds interface definitions in original shipped IDL, ignoring comments,
quoted C++ and forward declarations. It inserts the reviewed
`_Win32_AnnotateInterface_` carrier before native attributes and adds the SAL
bootstrap without rewriting existing bytes, guards, attributes or method order.
Ambiguous targets, unsupported OS vocabulary, existing carriers and non-interface
facts are reported verbatim as retained legacy debt. It never removes sidecar
rows or changes the installed SDK or repository recipe. The report's
`candidateGeneratedHeaders` are ownership candidates, not measured generated
outputs. Add admitted patches, original-input closure and generated outputs to
`SdkHeaders.json`, then use the
existing preparation/MIDL and native checks before claiming applied output or
removing equivalent sidecar rows. Authored source is not compile or full-SDK
acceptance.

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

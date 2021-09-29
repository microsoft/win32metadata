# Inputs Used to Create Win32 Metadata

Metadata is created from headers/libs through two different stages: scraping and emitting.

This project uses [ClangSharp](https://github.com/Microsoft/ClangSharp) to scrape C headers into C# files.

Once the C# files are written by ClangSharp, the emitter turns these files into a Windows Metadata (.winmd) file.

There are different options you can pass to the scraping and emitting stages to improve the final metadata. Most options are passed to the stages via response files (.rsp files). There are also two .json files that provide additional information to the build system.


## Scraping Options

Scraping options are passed to ClangSharp via .rsp files. For the Windows Win32 metadata project, all partitions share the [generation/WinSDK/scraper.settings.rsp](/generation/WinSDK/scraper.settings.rsp) file. This allows partitions to interpret the headers in the same way.

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

This tells the emitter to add the [Flags] attribute and also to make the enum unsigned.

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

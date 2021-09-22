# Response Files

Metadata is created from headers/libs through two different stages: scraping and emitting.

This project uses [ClangSharp](https://github.com/Microsoft/ClangSharp) to scrape Windows SDK headers into C# files.

Once the C# files are written by ClangSharp, the emitter turns these files into a Windows Metadata (.winmd) file.

There are different options you can pass to the scraping and emitting stages to improve the final metadata. These options are passed to the stages via response files (.rsp files).


## Scraping Options

Scraping options are passed to ClangSharp via .rsp files. For the Win32 metada project, all partitions share the [generation/scraper/baseRemap.rsp](../generation/scraper/baseRemap.rsp) file. This allows all partitions to interpret the headers in the same way.

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


## Emitting Options

Once ClangSharp has scraped the files, the emitter turns the scraped data into a .winmd. Like ClangSharp, options are passed to the emitter via .rsp files. These options allow for further fine-tuning of metadata.

````
--requiredNamespaceForName
# region appmgmt.h
APPCATEGORYINFO=Windows.Win32.UI.Shell
APPCATEGORYINFOLIST=Windows.Win32.UI.Shell
# endregion appmgmt.h
````

Sometimes a header may contain types that you want in different namespaces. ClangSharp will put all types or APIs from a given header into a single namespace, but this option lets you move them to a different namespace. In the main project, these are kept in [generation/emitter/requiredNamespacesForNames.rsp](../generation/emitter/requiredNamespacesForNames.rsp).

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

## Reducing the pointer level for delegates

````
--reducePointerLevel
MY_PROC
````

ClangSharp will scrape both of these the same way:

````
typedef int MY_PROC();
typedef int (*MY_PROC)();
````

Scraped version:
````
public unsafe delegate int MY_PROC();
````

But a use of that type in C will look different depending on how the function pointer was defined. The first C definition is just a prototype, and the second one is actually a pointer.

Use of the first version in a header:
````
void Foo(MY_PROC* pProc)
````

Use of the second version in a header:
````
void Foo(MY_PROC pProc)
````

--reducePointerLevel tells the emitter that pointers to the delegate type need to get reduced by one, since the delegate is already a pointer.



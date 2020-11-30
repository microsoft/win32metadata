# Overview

Win32 APIs provide functionality that not all languages and frameworks support themselves. When developing for Windows, developers often call into Win32 APIs to access this functionality.

Historically, this has required manually [redefining the APIs](http://pinvoke.net/) to make them accessible, which is fragile and error-prone. Community projects like https://github.com/dotnet/pinvoke (.NET) and https://github.com/retep998/winapi-rs (Rust) have taken on the burden of providing strongly-typed and validated API signatures for their frameworks, but the projects are manually maintained, which is hard to sustain and makes it challenging to provide thorough API coverage.

This project aims to provide metadata for Win32 APIs such that idiomatic projections and projects like the ones above can be generated for all languages and frameworks in a more automated way and with more complete API coverage.

See the [roadmap](./docs/roadmap.md) and [FAQ](./docs/faq.md) for more details.

# Architecture

This project uses [ClangSharp](https://github.com/Microsoft/ClangSharp) to scrape Windows SDK headers into C# files. It uses libraries from the Windows SDK to figure out what the DLL imports are for each API function. The project is partioned by lib names, so that ClangSharp creates a .cs file for each lib that it processes.

Once the C# files are written by ClangSharp, the emitter turns these files into a Windows Metadata (.winmd) file. Although this is an ECMA-335 binary, it is not directly loadable by the CLR.

The resulting .winmd is packaged as a NuGet package which can be used to create language projections for other languages such as C#, modern C++, and Rust.

# ClangSharp Overview

ClangSharp emits C# as it encounters types found in C/C++ headers. It will only emit types for headers included in its "traverse" list. Example for dxgi.lib:

[main.cpp](generation/ImportLibs/dxgi/main.cpp):

    #include <dxgi.h>
    #include <dxgi1_5.h>
    #include <dxgicommon.h>
    #include <dxgiformat.h>
    #include <dxgitype.h>

[settings.rsp](generation/ImportLibs/dxgi/settings.rsp): (Note: The paths get updated by the build script to point at the correct WinSDK NuGet files)

    --traverse
    C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/shared/dxgiformat.h
    C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/shared/dxgi.h
    C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/shared/dxgicommon.h
    C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/shared/dxgitype.h
    C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/shared/dxgi1_5.h
    C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/shared/dxgi1_4.h
    C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/shared/dxgi1_3.h
    C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/shared/dxgi1_2.h

This means ClangSharp will emit types from the above list of headers when scraping for dxgi.lib.

## ClangSharp and Remaps

ClangSharp emits C# code as it goes. For example, when it sees this type:

    typedef struct tagRECT
    {
        LONG    left;
        LONG    top;
        LONG    right;
        LONG    bottom;
    } RECT, *PRECT, NEAR *NPRECT, FAR *LPRECT;

It starts emitting:

    public partial struct tagRect
    {
        public int left;

It has no way of knowing a typedef is coming (RECT). But, we can feed data into ClangSharp that tells it to rename tagRECT to RECT:

[baseRemap](generation/baseRemap.rsp)

    tagRECT=RECT

Now when ClangSharp encounters tagRECT it will automatically change the name it uses to RECT.

# Winmd Emitter Overview

ClangSharp was designed to create C#-compilable code from Win32 headers. Because its goal is to create C#-compilable code while also preserving pointers, it can't always express things in the way we would like for metadata that should be language-agnostic. For example, the CLR will not allow managed types such as "interface" or "delegate" to be on an unsafe struct (a struct that gets pointed to or includes pointers). This means ClangSharp emits COM objects as structs instead of interfaces, so that a COM object can exist on an unsafe struct.

The winmd emitter takes the C#-compilable source created by ClangSharp and emits it into a .winmd. A .winmd can define an interface, put it on a struct, and have a function paramter point at the struct. However, the CLR will not be able to load it because such a thing is invalid in the CLR.

The emitter also looks at SAL attributes that ClangSharp outputs for parameters and adds metadata attributes for const, in/out, COM out pointers, etc. It will also mark fields and parameters via attributes as null-terminated strings while preserving the original pointer type. It is up to consumers of the fields and parameters to interpret the metadata and turn them into language-appropriate types such as a string.

## Changing field/parameter types

The emitter allows for changing parameter or field types from what was found in the ClangSharp-created C#. For example, the Win32 API [CreateFileW](https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew) includes some variables that are of type DWORD. It would be nice if the metadata could provide a more helpful type, such as a flags enum, that would help users know what values to use. This is how we change these parameters from DWORDs to an enums:

* Add enum types to one of the manually-created C# files, or create a new C# file to be included by the emitter:

    [sources/Win32MetadataSource/onecoreuap.manual.cs](sources/Win32MetadataSource/onecoreuap.manual.cs)

        [Flags]
        public enum FILE_SHARE_FLAGS
        {
            FILE_SHARE_NONE = 0,
            FILE_SHARE_DELETE = 4,
            FILE_SHARE_READ = 1,
            FILE_SHARE_WRITE = 2,
        }


* Tell the emitter to change the type of the parameters in CreateFileW when it sees them:

    [sources/Win32MetadataSource/remap.rsp](sources/Win32MetadataSource/remap.rsp)

        CreateFileW:dwShareMode=FILE_SHARE_FLAGS
        CreateFileW:dwDesiredAccess=FILE_ACCESS_FLAGS
        CreateFileW:dwCreationDisposition=FILE_CREATE_FLAGS
        CreateFileW:dwFlagsAndAttributes=FILE_FLAGS_AND_ATTRIBUTES

# Scraping/Emitting Organization

This project drives ClangSharp by giving it response files (.rsp). The scraping is partitioned by WinSDK libs. Each lib defines what headers ClangSharp should parse, and can also add manual .cs code to be included in the final metadata.

# How to Generate the .winmd
The .winmd is generated in two steps:

1) GenerateMetadataSource.cmd: This loops over the directories under generation\ImportLibs and treats each directory as a lib name, running ClangSharp for each one. There are base settings for all libs: name remaps are found in [generation/baseRemap.rsp](generation/baseRemap.rsp) and other settings are found in [generation/baseSettings.rsp](generation/baseSettings.rsp). Each lib folder contains a main.cpp, remap.rsp, and settings.rsp. ClangSharp writes C# files to sources\Win32MetadataSource\generated (these files are not checked in).
2) BuildMetadataBin.cmd: This builds the emitter and points it at the [sources/Win32MetadataSource](sources/Win32MetadataSource) directory. Again, the "generated" subdirectory contains the files that ClangSharp created in step 1.

# How to Add a New Lib
* Create a new directory under generation\ImportLibs. Make sure the name matches a WinSDK lib.
* In that directory add a main.cpp, remap.rsp, and settings.rsp. It might be helpful to copy an existing directory and start from there.
* Edit settings.rsp to list the includes that contribute to the lib.
* Now you can try to scrape/emit it using GenerateMetadataSource.cmd and BuildMetadataBin.cmd. However, in a tighter loop you wouldn't want ClangSharp to visit every lib again. Instead, in a PowerShell window you can just call:

        .\scripts\GenerateMetadataSourceForLib.ps1 -libName <newlibname>

    You could take a look at sources\Win32MetadataSource\generated\newlibname.cs and see what was generated. Then you can call BuildMetadataBin.cmd to build metadata that uses what ClangSharp just scraped from your new lib.
* If the emitter errors out and complains it can't find a symbol, it's most likely because the header that actually defines the symbol wasn't included in your lib's new settings.rsp. Find the header that defines the type and make sure it's in generation\ImportLibs\newlibname\settings.rsp:

        --traverse
        C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/<header that defines type>.h



# Contributing

This project welcomes contributions and suggestions.  Most contributions require you to agree to a
Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us
the rights to use your contribution. For details, visit https://cla.opensource.microsoft.com.

When you submit a pull request, a CLA bot will automatically determine whether you need to provide
a CLA and decorate the PR appropriately (e.g., status check, comment). Simply follow the instructions
provided by the bot. You will only need to do this once across all repos using our CLA.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

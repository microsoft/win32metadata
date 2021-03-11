# Overview

Win32 APIs provide functionality that not all languages and frameworks support themselves. When developing for Windows, developers often call into Win32 APIs to access this functionality.

Historically, this has required manually [redefining the APIs](http://pinvoke.net/) to make them accessible, which is fragile and error-prone. Community projects like https://github.com/dotnet/pinvoke (.NET) and https://github.com/retep998/winapi-rs (Rust) have taken on the burden of providing strongly-typed and validated API signatures for their frameworks, but the projects are manually maintained, which is hard to sustain and makes it challenging to provide thorough API coverage.

This project aims to provide metadata for Win32 APIs such that idiomatic [projections](./docs/projections.md) and projects like the ones above can be generated for all languages and frameworks in a more automated way and with more complete API coverage.

To call Win32 APIs from the language of your choice based off of this metadata, use the following [language projections](./docs/projections.md):

* C# - https://github.com/microsoft/cswin32 (Microsoft)
* C++ - https://github.com/microsoft/cppwin32 (Microsoft)
* Rust - https://github.com/microsoft/windows-rs (Microsoft)
* D - https://github.com/rumbu13/windows-d (Community)

Note: Community projects are listed here to help with discovery but are not officially validated by Microsoft.

See the [roadmap](./docs/roadmap.md) and [FAQ](./docs/faq.md) for more details.

If you'd like to browse the metadata to see what we're emitting, [download the NuGet package](https://www.nuget.org/packages/Microsoft.Windows.SDK.Win32Metadata/) and load the included winmd file in [ILSpy](https://github.com/icsharpcode/ILSpy).

![ILSpy with winmd](./images/ILSpyWithWinmd.png)

# General Strategy

This project aims to expose as much of the Win32 API as possible. Some project goals include:
* Keep the names of the original APIs, but express in metadata additional information that can make them easier to use. 
* Convert non-specific types like uint that use constants into explicit enums to make calling APIs easier.
* When pulling constants into new enums, avoid changing the original constant names. This allows developers to search online using the original constant names even though they are now part of an enum.
* Express Win32 resources like HANDLEs and GDI objects as strongly-typed structs. The definition of these structs include how to dispose of the resources (like CloseHandle or DeleteObject). It is up to language projections to make use of this information in a language-specific way. For example, a C# projection could use SafeHandle objects for HANDLE and GDI objects.

# Architecture

This project uses [ClangSharp](https://github.com/Microsoft/ClangSharp) to scrape Windows SDK headers into C# files. It uses libraries from the Windows SDK to figure out what the DLL imports are for each API function. The project is split into partitions that roughly translate into namespaces. ClangSharp creates a .cs file for each partition that it processes.

Once the C# files are written by ClangSharp, the emitter turns these files into a Windows Metadata (.winmd) file. Although this is an ECMA-335 binary, it is not directly loadable by the CLR.

The resulting .winmd is packaged as a NuGet package which can be used to create language projections for other languages such as C#, modern C++, and Rust.

# ClangSharp Overview

ClangSharp emits C# as it encounters types found in C/C++ headers. It will only emit types for headers included in its "traverse" list.

Example for Direct3DDxgi:

[generation/scraper/Partitions/Direct3DDxgi/main.cpp](generation/scraper/Partitions/Direct3DDxgi/main.cpp):

    #include <winnt.h>
    #include <winerror.h>
    #include <dxgi.h>
    #include <dxgi1_2.h>
    #include <dxgi1_3.h>
    #include <dxgi1_4.h>
    #include <dxgi1_5.h>
    #include <dxgi1_6.h>
    #include <dxgidebug.h>
    #include <dxgitype.h>
    #include <dxgicommon.h>
    #include <dxgiformat.h>

[generation/scraper/Partitions/Direct3DDxgi/settings.rsp](generation/scraper/Partitions/Direct3DDxgi/settings.rsp):

    --traverse
    <IncludeRoot>/shared/dxgitype.h
    <IncludeRoot>/shared/dxgiformat.h
    <IncludeRoot>/shared/dxgicommon.h
    <IncludeRoot>/shared/dxgi.h
    <IncludeRoot>/shared/dxgi1_2.h
    <IncludeRoot>/shared/dxgi1_4.h
    <IncludeRoot>/shared/dxgi1_6.h
    <IncludeRoot>/um/dxgidebug.h
    <IncludeRoot>/shared/dxgi1_3.h
    <IncludeRoot>/shared/dxgi1_5.h
    --namespace
    Windows.Win32.Dxgi


This means ClangSharp will emit types from the above list of headers when scraping for dxgi.lib. The compiler will see lots of other headers, like what windows.h brings in, but it will only emit types seen in the list above.

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

[generation/scraper/baseRemap.rsp](generation/scraper/baseRemap.rsp)

    tagRECT=RECT

Now when ClangSharp encounters tagRECT it will automatically change the name it uses to RECT.

# Winmd Emitter Overview

ClangSharp was designed to create C#-compilable code from Win32 headers. Because its goal is to create C#-compilable code while also preserving pointers, it can't always express things in the way we would like for metadata which is meant to be language-agnostic. For example, the CLR will not allow managed types such as "interface" or "delegate" to be on an unsafe struct (a struct that gets pointed to or includes pointers). This means ClangSharp emits COM objects as structs instead of interfaces, so that a COM object can exist on an unsafe struct.

The winmd emitter takes the C#-compilable source created by ClangSharp and emits it into a .winmd. A .winmd can define an interface, have struct use it as a field type, and have a function parameter point at the struct. However, the CLR will not be able to load it because it'ss invalid to the CLR.

The emitter also looks at SAL attributes that ClangSharp outputs for parameters and adds metadata attributes for const, in/out, COM out pointers, etc. It will also mark fields and parameters via attributes as null-terminated strings while preserving the original pointer type. It is up to consumers of the fields and parameters to interpret the metadata and turn them into language-appropriate types such as a string.

## Changing field/parameter types

The emitter allows for changing parameter or field types from what was found in the ClangSharp-created C#. For example, the Win32 API [CreateFileW](https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew) includes some variables that are of type DWORD. It would be nice if the metadata could provide a more helpful type, such as a flags enum, that would help users know what values to use. This is how we change these parameters from DWORDs to an enums:

* Add enum types to one of the manually-created C# files, or create a new C# file to be included by the emitter:

    [generation/emitter/manual/FileSystem.manual.cs](generation/emitter/manual/FileSystem.manual.cs)

        [Flags]
        public enum FILE_SHARE_FLAGS
        {
            FILE_SHARE_NONE = 0,
            FILE_SHARE_DELETE = 4,
            FILE_SHARE_READ = 1,
            FILE_SHARE_WRITE = 2,
        }


* Tell the emitter to change the type of the parameters in CreateFileW when it sees them:

    [generation/emitter/remap.rsp](generation/emitter/remap.rsp)

        CreateFileW:dwShareMode=FILE_SHARE_FLAGS
        CreateFileW:dwDesiredAccess=FILE_ACCESS_FLAGS
        CreateFileW:dwCreationDisposition=FILE_CREATE_FLAGS
        CreateFileW:dwFlagsAndAttributes=FILE_FLAGS_AND_ATTRIBUTES

## Forcing APIs and types into a particular namespace
The partitions are meant to break up headers into namespaces. However, some headers like winuser.h have APIs and types that belong in multiple namespaces. The emitter takes a .rsp file that specifies namespaces for APIs and types and then puts them in the correct namespaces. These entries are only needed if a header needs to emit into multiple namespaces.

[generation/emitter/requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp)

(Both functions come from winuser.h)

    BeginPaint=Windows.Win32.Gdi
    CreateWindowExW=Windows.Win32.WindowsAndMessaging

# How to Generate the .winmd
PowerShell Core is required to run the generation scripts. Open a PowerShell Core window and:

1) [.\scripts\GenerateMetadataSource.ps1](.\scripts\GenerateMetadataSource.ps1): This loops over the directories under generation\Partitions, running ClangSharp for each one. There are base settings for all partitions: name remaps are found in [generation/scraper/baseRemap.rsp](generation/scraper/baseRemap.rsp) and other settings are found in [generation/scraper/baseSettings.rsp](generation/scraper/baseSettings.rsp). Each partitions folder contains a main.cpp, remap.rsp, and settings.rsp. ClangSharp writes C# files to generation\emitter\manual\generated (these files are not checked in).
2) [.\scripts\BuildMetadataBin.ps1](.\scripts\BuildMetadataBin.ps1): This builds the emitter and points it at the [generation/emitter](generation/emitter) directory. Again, the "generated" subdirectory contains the files that ClangSharp created in step 1.
3) Once the .winmd is built, run [.\scripts\TestMetadataBin.ps1](.\scripts\TestMetadataBin.ps1) which checks for regressions.

...or if you can do it all in one shot in a PowerShell Core window:

```winbatch
.\DoAll.ps1
```

&nbsp;
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

## How you can help
* Help fix one of the existing issues.
* Help make an API friendlier by converting a uint or other non-specific type in an API to use a more friendly flags enum. This helps make the API easier for developers to use.

    Example for what was done with CreateFileW:
    
    This function contains multiple uint paramters:
    
      uint dwShareMode
      uint dwDesiredAccess
      uint dwCreationDisposition

    But a developer would need to look up the API to figure out what values to use. To improve this, changes were added to replace the uints with enums:

    1) Find the possible constants in the [CreateFileW docs](https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea).
    2) Create enums with these values and add them to a *.manual.cs file, or create a new one at [generation/emitter/manual](generation/emitter/manual). **Please keep the original value names of the Win32 contants.** This will allow developers to search for them and find information about them online.

        Here's one for the first parameter:

            [Flags]
            public enum FILE_SHARE_FLAGS
            {
                FILE_SHARE_NONE = 0,
                FILE_SHARE_DELETE = 4,
                FILE_SHARE_READ = 1,
                FILE_SHARE_WRITE = 2,
            }

    3) Now tell the emitter to change the type of dwShareMode to be FILE_SHARE_FLAGS in [generation/emitter/remap.rsp](generation/emitter/remap.rsp):
    
    
            CreateFileW::dwShareMode=FILE_SHARE_FLAGS


# Trademarks

This project may contain trademarks or logos for projects, products, or services. Authorized use of Microsoft trademarks or logos is subject to and must follow Microsoft's Trademark & Brand Guidelines. Use of Microsoft trademarks or logos in modified versions of this project must not cause confusion or imply Microsoft sponsorship. Any use of third-party trademarks or logos are subject to those third-party's policies.

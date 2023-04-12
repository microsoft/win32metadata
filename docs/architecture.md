# Architecture

The [Scraper](#scraper) layer is responsible for traversing header files and generating C# files.

The [Emitter](#emitter) layer is responsible for traversing the generated C# files and generating Windows.Win32.winmd.

## Scraper

### ClangSharp

[ClangSharp](https://github.com/dotnet/ClangSharp) traverses header files as defined within [Partitions](../generation/WinSDK/Partitions) and generates C# files within [generated](../generation/WinSDK/obj/generated).

The base settings passed into ClangSharp are defined within [baseSettings.rsp](../sources/GeneratorSdk/tools/assets/scraper/baseSettings.rsp) along with adjacent architecture-specific response files.

Project-specific settings are included within [scraper.settings.rsp](../generation/WinSDK/scraper.settings.rsp) along with adjacent domain-specific response files like [libMappings.rsp](../generation/WinSDK/libMappings.rsp), [supportedOS.rsp](../generation/WinSDK/supportedOS.rsp), and [WithSetLastError.rsp](../generation/WinSDK/WithSetLastError.rsp).

[scraper.header.txt](../generation/WinSDK/scraper.header.txt) includes using statements that are added to the generated C# files to resolve cross-namespace dependencies.

### ConstantsScraper

[ConstantsScraper](../sources/MetadataUtils/ConstantsScraper.cs) walks the header files included within [Partitions](../generation/WinSDK/Partitions) and generates C# constants based on regular expression pattern matching.

The base settings passed into ClangSharp are defined within [baseSettings.ConstantsScraper.rsp](../sources/GeneratorSdk/tools/assets/scraper/baseSettings.ConstantsScraper.rsp).

Project-specific settings are included within [ConstantsScraper.settings.rsp](../generation/WinSDK/ConstantsScraper.settings.rsp).

[ConstantsScraper.header.txt](../generation/WinSDK/ConstantsScraper.header.txt) includes using statements that are added to the generated C# files to resolve cross-namespace dependencies.

## Emitter

### ClangSharpSourceCompilation

This class orchestrates the manipulation and compilation of the generated C# files.

Project-specific settings are included within [emitter.settings.rsp](../generation/WinSDK/emitter.settings.rsp).

ClangSharp was designed to create C#-compilable code from Win32 headers. Because its goal is to create C#-compilable code while also preserving pointers, it can't always express things in the way we would like for metadata, which is meant to be language-agnostic. For example, the CLR will not allow managed types such as "interface" or "delegate" to be on an unsafe struct (a struct that gets pointed to or includes pointers). This means ClangSharp emits COM objects as structs instead of interfaces, so that a COM object can exist on an unsafe struct. A .winmd does not have such restrictions, so ClangSharpSourceCompilation handles manipulating the generated CLR-compliant C# files into the language-agnostic metadata representation.

#### NamesToCorrectNamespacesMover

This class moves APIs to namespaces based on [requiredNamespacesForNames.rsp](../generation/WinSDK/requiredNamespacesForNames.rsp).

#### MetadataSyntaxTreeCleaner

This class visits each node in the C# abstract syntax trees (AST) and applies modifications such as remaps and custom attributes.

#### CrossArchTreeMerger

This class handles merging C# files from multiple architectures to identify architecture-specific APIs.

### ClangSharpSourceWinmdGenerator

This class walks the final C# abstract syntax trees (AST) and writes each node to Windows.Win32.winmd.
# Frequently Asked Questions

**Q. Why produce metadata for Win32 APIs?**<br />
A. Producing metadata for Win32 APIs enables programmatic generation of language projections with maximum API coverage and minimal maintenance. Language projections produced from this metadata will make Win32 APIs more accessible from more languages with improved API coverage and a better developer experience.

**Q. How do I use the metadata to call Win32 APIs from my preferred language?**<br />
A. Most developers will not consume the metadata directly and will instead use [language projections](projections.md) that themselves consume the metadata and project the APIs into the idiomatic patterns of the languages. We intend to support [C#](https://github.com/microsoft/CsWin32), [C++](https://github.com/microsoft/cppwin32), and [Rust](https://github.com/microsoft/windows-rs) projections initially with plans to coordinate with the community to support additional language projections based on demand. Language projections will be developed independently of the metadata tooling and will live in their own repos.

**Q. Can I generate metadata for my own C and C++ APIs to make them available in more languages?**<br />
A. Yes. The same tooling we use to produce metadata for Win32 APIs can be used to produce metadata for your own APIs. You can use the [Microsoft.Windows.WinmdGenerator](https://www.nuget.org/packages/Microsoft.Windows.WinmdGenerator/) NuGet package produced from this repository to produce a winmd file for your APIs which can then be used with language projections like [C#/Win32](https://github.com/microsoft/CsWin32) and [Rust](https://github.com/microsoft/windows-rs). See the [Windows SDK](../generation/WinSDK) and [WinmdGenerator samples](../sources/GeneratorSdk/samples) in this repository for example usage of the WinmdGenerator. Also see https://withinrafael.com/2023/01/18/generating-metadata-for-the-windows-crate for more details and an example of producing metadata and associated Rust bindings for the C++ DIA SDK.

**Q. Can .NET code reference the metadata binary and call its APIs directly?**<br />
A. No. While the metadata binary is compiled based on the ECMA-335 standard, it does not contain the same attributes that the .NET runtime requires to successfully P/Invoke into the functions exported by Windows. .NET code should use an appropriate language projection like [C#/Win32](https://github.com/microsoft/CsWin32).

**Q. How does this relate to existing community projects in the space like [PInvoke](https://github.com/dotnet/pinvoke) or [winapi-rs](https://github.com/retep998/winapi-rs)?**<br />
A. New and existing community projects can build on this metadata to maximize their API coverage, improve their developer experience, and reduce their maintenance overhead. We worked closely with the [PInvoke](https://github.com/dotnet/pinvoke) project during development to validate the design and ensure projects like it can build world-class experiences on par or better than what they currently provide and with less effort.

**Q. How much of the Win32 API surface is included in the metadata?**<br />
A. We aspire to include as much of the Win32 API surface as possible, though while we develop the tooling, we expect there will be gaps which will improve over time. If you discover APIs that are not supported, please [file issues](https://github.com/microsoft/win32metadata/issues) in our repo.


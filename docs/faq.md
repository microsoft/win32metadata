# Frequently Asked Questions

**Q. Why produce metadata for Win32 APIs?**<br />
A. Producing metadata for Win32 APIs enables programmatic generation of language projections with maximum API coverage and minimal maintenance. Language projections produced from this metadata will make Win32 APIs more accessible from more languages with improved API coverage and a better developer experience.

**Q. How do I use the metadata to call Win32 APIs from my preferred language?**<br />
A. Most developers will not consume the metadata directly and will instead use [language projections](projections.md) that themselves consume the metadata and project the APIs into the idiomatic patterns of the languages. We intend to support [C#](https://github.com/microsoft/CsWin32), C++, and Rust projections initially with plans to coordinate with the community to support additional language projections based on demand. Language projections will be developed independently of the metadata tooling and will live in their own repos.

**Q. Can .NET code reference the metadata binary and call its APIs directly?**<br />
A. No. While the metadata binary is compiled based on the ECMA-335 spec, it does not contain the same attributes that the .NET runtime requires to successfully P/Invoke into the functions exported by Windows. .NET code should use an appropriate language projection like [C#/Win32](https://github.com/microsoft/CsWin32).

**Q. How does this relate to existing community projects in the space like [PInvoke](https://github.com/dotnet/pinvoke) or [winapi-rs](https://github.com/retep998/winapi-rs)?**<br />
A. New and existing community projects can build on this metadata to maximize their API coverage, improve their developer experience, and reduce their maintenance overhead. We worked closely with the [PInvoke](https://github.com/dotnet/pinvoke) project during development to validate the design and ensure projects like it can build world-class experiences on par or better than what they currently provide and with less effort.


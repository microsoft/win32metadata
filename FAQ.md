# Frequently Asked Questions

**Q. Why produce metadata for Win32 APIs?**<br />
A. Producing metadata for Win32 APIs enables programmatic generation of language projections with maximum API coverage and minimal maintenance. Language projections produced from this metadata will make Win32 APIs more accessible from more languages with improved API coverage and a better developer experience.

**Q. How does this relate to existing community projects in the space like [PInvoke](https://github.com/dotnet/pinvoke) or [winapi-rs](https://github.com/retep998/winapi-rs)?**<br />
A. New and existing community projects can build on this metadata to maximize their API coverage, improve their developer experience, and reduce their maintenance overhead. We worked closely with the [PInvoke](https://github.com/dotnet/pinvoke) project during development to validate the design and ensure projects like it can build world-class experiences on par or better than what they currently provide and with less effort.

**Q. Can .NET code reference the metadata dll and call its APIs directly?**<br />
A. No. While the metadata dll is compiled based on the ECMA-335 spec, it does not contain the same attributes that the .NET runtime requires to successfully p/invoke into the  functions exported by Windows. .NET code should use a projection of this metadata intended for .NET consumption. The [PInvoke](https://github.com/dotnet/pinvoke) project is working to consume this metadata dll to create a proper .NET/C# projection of Windows APIs for use by other .NET libraries and applications.

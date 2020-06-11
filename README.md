# Overview

Win32 APIs provide functionality that not all languages and frameworks support themselves. When developing for Windows, developers often call into or P/Invoke Win32 APIs to access this functionality.

Historically, this has required manually [redefining the APIs](http://pinvoke.net/) to make them accessible, which is fragile and error-prone. Community projects like https://github.com/dotnet/pinvoke (.NET) and https://github.com/retep998/winapi-rs (Rust) have taken on the burden of providing strongly-typed and validated API signatures for their frameworks, but the projects are manually maintained, which is hard to sustain and makes it challenging to provide thorough API coverage.

This project aims to provide metadata for Win32 APIs such that idiomatic projections and projects like above can be generated for all languages and frameworks in a more automated way and with more complete API coverage.

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

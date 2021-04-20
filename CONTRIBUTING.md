# Contributing

This project welcomes contributions and suggestions. Most contributions require you to agree to a
Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us
the rights to use your contribution. For details, visit https://cla.opensource.microsoft.com.

When you submit a pull request, a CLA bot will automatically determine whether you need to provide
a CLA and decorate the PR appropriately (e.g., status check, comment). Simply follow the instructions
provided by the bot. You will only need to do this once across all repos using our CLA.

You can contribute to this project in multiple ways:

* Contribute to [issues](https://github.com/microsoft/win32metadata/issues)
* Contribute to [discussions](https://github.com/microsoft/win32metadata/discussions)
* Contribute to [namespaces](#Namespaces)
* Contribute to [projections](docs/projections.md)

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

## Namespaces

Our tooling organizes Win32 APIs into namespaces. This provides an alternative way for developers to easily include large areas of functionality and also provides an opportunity to bring more consistency across Win32 and WinRT to help with usability and discoverability.

### Assign a header file to a single namespace

The simplest way to assign an API to a namespace is to associate the API's header file with a [partition](generation/scraper/Partitions). A header file can only be associated with one partition, and by default all APIs included in the header file will be added to the partition's target namespace.

Partitions are defined as [folders](generation/scraper/Partitions) with [main.cpp](generation/scraper/Partitions/Registry/main.cpp) and [settings.rsp](generation/scraper/Partitions/Registry/settings.rsp) files.
* [main.cpp](generation/scraper/Partitions/Registry/main.cpp) contains `#include` statements like you would use to call the APIs directly. This typically includes the header files to be associated with the partition as well as any other dependent headers, included in the proper order.
* [settings.rsp](generation/scraper/Partitions/Registry/settings.rsp) associates a list of header files to a namespace. Reference existing [partitions](generation/scraper/Partitions) to understand the template for this file. The important sections are `--traverse`, which lists the header files to include, and `--namespace` which lists the namespace to associate with the content of those header files.

You can test localized changes to a partition by running `./scripts/GenerateMetadataSourceForPartition.ps1 -partitionName <PARTITION> -artifactsDir ./artifacts` from the repo root. If it compiles, the changes are likely correct. A common reason for failure is main.cpp either doesn't include all the necessary dependent headers needed to use the target headers or doesn't include them in the proper order.

### Split a header file among multiple namespaces

If a header file doesn't cleanly map to one namespace, it should be associated with a partition and namespace that makes sense for the majority of its APIs (using the steps above for a single namespace), and then the rest of the APIs should be manually remapped using [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp). This file contains one line per API and follows the format `<API>=<NAMESPACE>`. It is a single file that is shared across all partitions.

### Refactoring namespaces

Note that when refactoring namespaces, [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp) will take precedence over any namespaces declared in the partitions, so make sure it doesn't contain remappings that will conflict with the expected factoring from the partitions. For example, if you create a new Registry partition to assign everything in winreg.h to Windows.Win32.System.Registry, but [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp) was previously updated to map Reg* APIs to a different namespace, you won't achieve the desired result unless you remove the Reg* entries from [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp).

Other files that need to be kept in sync when refactoring namespaces include any manually defined APIs in [manual](generation/emitter/manual) as well as [header.txt](generation/scraper/header.txt) which adds using statements to generated .cs files during the build process.
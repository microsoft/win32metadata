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

When contributing PRs, [validate](#Validating-changes) your changes by rebuilding the winmd and then inspecting the reported winmd diff to ensure all changes were intentional:

* [Full builds](#full-builds)
* [Incremental builds](#incremental-builds)

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

## Namespaces

Our tooling organizes Win32 APIs into namespaces. This provides an alternative way for developers to easily include large areas of functionality and improves consistency and discoverability across Win32 and WinRT.

* [Assign a header file to a single namespace](#assign-a-header-file-to-a-single-namespace)
* [Split a header file among multiple namespaces](#split-a-header-file-among-multiple-namespaces)
* [Refactoring namespaces](#refactoring-namespaces)
* [Validating changes](#validating-changes)
  * [Full builds](#full-builds)
  * [Incremental builds](#incremental-builds)

### Assign a header file to a single namespace

The simplest way to assign an API to a namespace is to associate the API's header file with a [partition](generation/scraper/Partitions). A header file can only be associated with one partition, and by default all APIs included in the header file will be added to the partition's target namespace.

Partitions are defined as [folders](generation/scraper/Partitions) with [main.cpp](generation/scraper/Partitions/Registry/main.cpp) and [settings.rsp](generation/scraper/Partitions/Registry/settings.rsp) files.
* [main.cpp](generation/scraper/Partitions/Registry/main.cpp) contains `#include` statements like you would use to call the APIs directly. This typically includes the header files to be associated with the partition as well as any other dependent headers, included in the proper order.
* [settings.rsp](generation/scraper/Partitions/Registry/settings.rsp) associates a list of header files to a namespace. Reference existing [partitions](generation/scraper/Partitions) to understand the template for this file. The important sections are `--traverse`, which lists the header files to include, and `--namespace` which lists the namespace to associate with the content of those header files. Note that headers should be listed alphabetically by convention, and the casing needs to match the casing of the filenames.

You can test localized changes to a partition by running `./scripts/GenerateMetadataSourceForPartition.ps1 -partitionName <PARTITION>` from the repo root. If it compiles, the changes are likely correct. A common reason for failure is main.cpp either doesn't include all the necessary dependent headers needed to use the target headers or doesn't include them in the proper order.

### Split a header file among multiple namespaces

If a header file doesn't cleanly map to one namespace, it should be associated with a partition and namespace that makes sense for the majority of its APIs (using the steps above for a single namespace), and then the rest of the APIs should be manually remapped using [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp). This file contains one line per API and follows the format `<API>=<NAMESPACE>`. It is a single file that is shared across all partitions.

### Refactoring namespaces

Note that when refactoring namespaces, [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp) will take precedence over any namespaces declared in the partitions, so make sure it doesn't contain remappings that will conflict with the expected factoring from the partitions. For example, if you create a new Registry partition to assign everything in winreg.h to Windows.Win32.System.Registry, but [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp) was previously updated to map Reg* APIs to a different namespace, you won't achieve the desired result unless you remove the Reg* entries from [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp).

Other files that need to be kept in sync when refactoring namespaces include [manual](generation/emitter/manual) and [autotypes.rsp](generation/emitter/autoTypes.rsp), which manually define some types, as well as [header.txt](generation/scraper/header.txt), which adds using statements to generated .cs files during the build process.

## Validating changes

### Full builds

The simplest but slowest way to validate changes is to perform a full build with `./DoAll.ps1` and then inspect the reported winmd diff to ensure all changes were intentional. A full build can take 25-30 minutes. Add `-Clean` to perform a clean build.

### Incremental builds

If you have already performed a full build and are making incremental changes, you can effectively perform incremental builds by running `./scripts/GenerateMetadataSourceForPartition.ps1 -PartitionName <PARTITION>` for each impacted `<PARTITION>`, and then build and test the winmd by running `./scripts/BuildMetadataBin.ps1 && ./scripts/TestWinmdBinary.ps1`. If you are only making changes to the [emitter](./generation/emitter), then you don't need to regenerate the partitions and can just rebuild the winmd.

Note that stale artifacts on your system may sometimes result in cryptic errors when attempting incremental builds. If you do encounter cryptic errors during incremental builds that you suspect are the result of previously built changes, reset your system state by running a clean build with `./DoAll.ps1 -Clean`.
# Contributing

This project welcomes contributions and suggestions. Most contributions require you to agree to a
Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us
the rights to use your contribution. For details, visit https://cla.opensource.microsoft.com.

When you submit a pull request, a CLA bot will automatically determine whether you need to provide
a CLA and decorate the PR appropriately (e.g., status check, comment). Simply follow the instructions
provided by the bot. You will only need to do this once across all repos using our CLA.

You can contribute to this project by contributing to:

* [Issues](https://github.com/microsoft/win32metadata/issues)
* [Discussions](https://github.com/microsoft/win32metadata/discussions)
* [Namespaces](#Namespaces)
* [Enums](#Enums)
* [Constants](#Constants)
* [Projections](docs/projections.md)

If you intend to contribute code changes, learn how to [set up your development environment](#Set-up-your-development-environment).

When contributing code changes, [validate](#Validating-changes) your changes by rebuilding the winmd and then inspecting the reported winmd diff to ensure all changes were intentional:

* [Full builds](#Full-builds)
* [Incremental builds](#Incremental-builds)
* [Comparing against the baseline](#Comparing-against-the-baseline)

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

## Set up your development environment

* Install [Visual Studio Code](https://code.visualstudio.com/Download)
* Install [PowerShell](https://aka.ms/powershell-release?tag=stable)
* Install [ILSpy](https://github.com/icsharpcode/ILSpy/releases/latest)
* Clone the [repo](https://github.com/microsoft/win32metadata.git)
* Run a [full build](#Full-builds)

## Namespaces

Our tooling organizes Win32 APIs into namespaces. This provides an alternative way for developers to easily include large areas of functionality and improves consistency and discoverability across Win32 and WinRT.

* [Assign a header file to a single namespace](#assign-a-header-file-to-a-single-namespace)
* [Split a header file among multiple namespaces](#split-a-header-file-among-multiple-namespaces)
* [Refactoring namespaces](#refactoring-namespaces)

### Assign a header file to a single namespace

The simplest way to assign an API to a namespace is to associate the API's header file with a [partition](generation/scraper/Partitions). A header file can only be associated with one partition, and by default all APIs included in the header file will be added to the partition's target namespace.

Partitions are defined as [folders](generation/scraper/Partitions) with [main.cpp](generation/scraper/Partitions/Registry/main.cpp) and [settings.rsp](generation/scraper/Partitions/Registry/settings.rsp) files.
* [main.cpp](generation/scraper/Partitions/Registry/main.cpp) contains `#include` statements like you would use to call the APIs directly. This typically includes the header files to be associated with the partition as well as any other dependent headers, included in the proper order.
* [settings.rsp](generation/scraper/Partitions/Registry/settings.rsp) associates a list of header files to a namespace. Reference existing [partitions](generation/scraper/Partitions) to understand the template for this file. The important sections are `--traverse`, which lists the header files to include, and `--namespace` which lists the namespace to associate with the content of those header files. Note that headers should be listed alphabetically by convention, and the casing needs to match the casing of the filenames.

You can test localized changes to a partition by running `./scripts/GenerateMetadataSourceForPartition.ps1 <PARTITION>` from the repo root. If it compiles, the changes are likely correct. A common reason for failure is main.cpp either doesn't include all the necessary dependent headers needed to use the target headers or doesn't include them in the proper order.

### Split a header file among multiple namespaces

If a header file doesn't cleanly map to one namespace, it should be associated with a partition and namespace that makes sense for the majority of its APIs (using the steps above for a single namespace), and then the rest of the APIs should be manually remapped using [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp). This file contains one line per API and follows the format `<API>=<NAMESPACE>`. It is a single file that is shared across all partitions.

For maintainability, it is important to keep [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp) organized with APIs grouped by header files. APIs should be added within `# region <HEADER>` sections based on the header files where they are defined. APIs within a `# region` should be sorted alphabetically by selecting them and then using Visual Studio Code's `Sort Lines Ascending` command.

### Refactoring namespaces

Note that when refactoring namespaces, [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp) will take precedence over any namespaces declared in the partitions, so make sure it doesn't contain remappings that will conflict with the expected factoring from the partitions. For example, if you create a new Registry partition to assign everything in winreg.h to Windows.Win32.System.Registry, but [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp) was previously updated to map Reg* APIs to a different namespace, you won't achieve the desired result unless you remove the Reg* entries from [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp).

Other files that need to be kept in sync when refactoring namespaces include [manual](generation/emitter/manual) and [autotypes.rsp](generation/emitter/autoTypes.rsp), which manually define some types, as well as [header.txt](generation/scraper/header.txt), which adds using statements to generated .cs files to resolve cross-namespace references.

## Enums

Our tooling produces enums for loosely typed parameters and fields that expect a closed set of values. This improves discoverability and usability of the values in the projections.

Enums are defined in [enums.json](generation/scraper/enums.json). This file provides a schema for extracting constants and macros from headers and emitting them in the winmd as an enum. Each object in the JSON array is an enum with the following properties:

* `namespace` - Optional property indicating the namespace for the enum
  * Note: If omitted, the enum will inherit the namespace of the first entry in `uses`
* `type` - Optional property indicating the type for the enum
  * Note: If omitted, the default value is `uint`
* `name` -  The name of the enum
* `flags` - Whether this is a flags enum
* `autoPopulate` - For automatically defined enums, rules for how to populate them
  * `header` - The header to scan
  * `filter` - The constant or macro prefix to search for in `header`
* `members` - For manually defined enums, a list of members
  * `name` - The name of the enum member
  * `value` - The value of the enum member
* `uses` - A list of APIs where this enum is used
  * `method` - The method name
  * `parameter` - The parameter name of `method` or `"return"` for the return value
  * `struct` - The struct name
  * `field` - The field name of `struct`

In the example below, a flags enum called `WNDCLASS_STYLES` is created with all of the `CS_` constants from `winuser.h`. This enum is then used by the style fields of all the `WNDCLASS` structs. Since no `namespace` or `type` are specified, the enum will live in the same namespace as `WNDCLASSA` and will be of type `uint`.

```json
{
  "name": "WNDCLASS_STYLES",
  "flags": true,
  "autoPopulate": {
    "filter": "CS_",
    "header": "WinUser.h"
  },
  "members": [],
  "uses": [
    {
      "struct": "WNDCLASSA",
      "field": "style"
    },
    {
      "struct": "WNDCLASSW",
      "field": "style"
    },
    {
      "struct": "WNDCLASSEXA",
      "field": "style"
    },
    {
      "struct": "WNDCLASSEXW",
      "field": "style"
    }
  ]
}
```
You can add new enums, modify existing enums, or apply enums to more APIs by modifying [enums.json](generation/scraper/enums.json).

## Constants

Our tooling scans header files for constants and emits them into the namespace of the containing header file. The tool that handles this responsibility is called the [ConstantsScraper](sources/ConstantsScraper).

The behavior of the ConstantsScraper can be adjusted by modifying [ConstantsScraper.rsp](generation/scraper/ConstantsScraper.rsp):

* The `--with-attribute` section declares attributes to add to constants (e.g. `E_NOTIMPL=NativeTypeName("HRESULT")`)
* The `--with-type` section declares constant types that cannot be detected automatically (e.g. `SOCK_STREAM=ushort`)
* The `--exclude` section declares constants to exclude from the metadata

Constants can be assigned to different namespaces than their header files by adding them to [requiredNamespacesForNames.rsp](generation/emitter/requiredNamespacesForNames.rsp) as described in [Split a header file among multiple namespaces](#Split-a-header-file-among-multiple-namespaces). Wildcards can be used (e.g. `DXGI_ERROR_*=Windows.Win32.Graphics.Dxgi`).

The ConstantsScraper uses [regular expression matching](sources/MetadataUtils/ConstantsScraper.cs) on the header files to automatically extract constants. If a constant is not being detected, either a regular expression needs to be added or a regular expression would be insufficient. For cases where regular expressions would be insufficient, you can manually define constants in `.cs` files within [manual](generation/emitter/manual) (e.g. [RestartManager.manual.cs](generation/emitter/manual/RestartManager.manual.cs)).

Constants are removed from the metadata when they are detected as members of an enum.

## Validating changes

### Full builds

The simplest but slowest way to validate changes is to perform a full build with `./DoAll.ps1` and then inspect the reported winmd diff to ensure all changes were intentional. A full build can take 25-30 minutes. Add `-Clean` to perform a clean build.

### Incremental builds

If you have already performed a full build and are making incremental changes, you can effectively perform incremental builds by running `./scripts/GenerateMetadataSourceForPartition.ps1 <PARTITION>` for each impacted `<PARTITION>`, and then build and test the winmd by running `./scripts/BuildMetadataBin.ps1 && ./scripts/TestWinmdBinary.ps1`. If you are only making changes to the [emitter](./generation/emitter), then you don't need to regenerate the partitions and can just rebuild the winmd.

Note that stale artifacts on your system may sometimes result in cryptic errors when attempting incremental builds. If you do encounter cryptic errors during incremental builds that you suspect are the result of previously built changes, reset your system state by running a clean build with `./DoAll.ps1 -Clean`.

### Comparing against the baseline

A baseline winmd is checked into the repo which is used to report diffs introduced by changes. These diffs are reported by `./scripts/TestWinmdBinary.ps1` which is called during both full and incremental builds if you follow the steps above.

When validating changes, it's important to evaluate the diffs to ensure all changes are intentional. Common patterns to expect in the diffs include:

* APIs were added to the baseline
* APIs were removed from the baseline
* APIs were moved to different namespaces

Additionally, it is useful to load the winmd in [ILSpy](https://github.com/icsharpcode/ILSpy) and navigate through the APIs as another means to identify additional changes that may be required to achieve the desired end result. You may notice that two related APIs are in different namespaces or that a type that an API depends on was not moved as you would have expected. If that happens, search the repo for the API or its header file to identify where it may be being mapped to another namespace.

Once all the changes are validated, update the baseline by following the steps reported in the build output.
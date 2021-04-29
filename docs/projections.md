# Projections

Language projections built on top of Win32 metadata are what developers should use to call Win32 APIs from various languages.

## Principles

Below are some principles that all language projections should follow:

* Language projections should provide maximum API coverage
* Language projections should provide friendly adaptations of APIs and types where appropriate
* Language projections should provide Intellisense sourced from official documentation
* Language projections should support filtering available APIs based on the SDK version that a project targets
* Language projections should enable developers to target a specific set of APIs and link or include only the artifacts necessary to provide support for those APIs

## Projections
* C# - https://github.com/microsoft/cswin32 (Microsoft)
* C++ - https://github.com/microsoft/cppwin32 (Microsoft)
* Rust - https://github.com/microsoft/windows-rs (Microsoft)
* D - https://github.com/rumbu13/windows-d (Community)
* Dart - https://github.com/timsneath/win32 (Community)
* Zig - https://github.com/marlersoft/zigwin32 (Community)

Note: Community projects are listed here to help with discovery but are not officially validated by Microsoft.
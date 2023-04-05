# Projections

Language projections built on top of Win32 metadata are what developers should use to call Win32 APIs from various languages.

## Principles

Below are some principles that all language projections should follow:

* Language projections should provide maximum API coverage
* Language projections should provide friendly adaptations of APIs and types where appropriate
* Language projections should provide Intellisense sourced from official documentation
* Language projections should support filtering available APIs based on the SDK version that a project targets
* Language projections should enable developers to target a specific set of APIs and link or include only the artifacts necessary to provide support for those APIs

## Consuming language projections

To call Win32 APIs from the language of your choice based off of this metadata, use the following language projections:

* C# - https://github.com/microsoft/cswin32 (Microsoft)
* Rust - https://github.com/microsoft/windows-rs (Microsoft)
---
* Beef - https://github.com/jayrulez/Win32-Beef (Community)
* D - https://github.com/rumbu13/windows-d (Community)
* Dart - https://github.com/timsneath/win32 (Community)
* Python - https://github.com/ynkdir/py-win32more (Community)
* Zig - https://github.com/marlersoft/zigwin32 (Community)

Note: Community projects are listed here to help with discovery but are not officially validated by Microsoft.

## Implementing language projections

### Parsing the metadata

The winmd file produced by this project can be parsed with any ECMA-335 compliant parser like .NET [System.Reflection](https://docs.microsoft.com/dotnet/api/system.reflection?view=net-5.0) and [System.Reflection.Metadata](https://docs.microsoft.com/dotnet/api/system.reflection.metadata?view=net-5.0) APIs.

Alternatively, a JSON translation of the winmd file can be found at https://github.com/marlersoft/win32json.

### Scenarios

The ECMA-335 specification defines the basic format and structure of the metadata in our winmd files. We have defined additional patterns and custom attributes that allow language projections to understand Win32-specific semantics and provide an improved developer experience.

Below are scenarios that are represented in the metadata and that language projections should handle for the best possible developer experience.

DISCLAIMER: This list is a work in progress and is not yet comprehensive.

* Namespaces allow users to import only the APIs they require and/or to control any code generation that is producing language bindings
* Entry points are assumed to be the same as function names unless the [EntryPoint](https://learn.microsoft.com/dotnet/api/system.runtime.interopservices.dllimportattribute.entrypoint) property of the `DllImport` attribute is specified
* Calling convention is captured in the [CallingConvention](https://learn.microsoft.com/dotnet/api/system.runtime.interopservices.dllimportattribute.callingconvention) property of the `DllImport` attribute
* typedefs (e.g. `BCRYPT_KEY_HANDLE`) are represented as CLR structs with a single field where the `NativeTypedef` attribute is applied to the struct. The type being defined is given by the name of the struct, and the type it is being defined as is the type of the struct field. typedefs can include the attributes `AlsoUsableFor`, `RAIIFree` and `InvalidHandleValue`:
  * `AlsoUsableFor` indicates that the type is implicitly convertible to another type (e.g. `BCRYPT_HANDLE`)
  * `RAIIFree` indicates what function should be used to close the handle (e.g. `BCryptDestroyKey`)
  * `InvalidHandleValue` attributes indicate invalid handle values (e.g. `0L`)
  * NOTE: `BCRYPT_KEY_HANDLE` demonstrates all of these attributes.
* Native unions are represented as CLR structs with an explicit layout where all fields contain an offset of 0
* Array parameters are qualified with the `[NativeArrayInfo]` attribute that can contain the size of a fixed-length array (`CountConst`), the 0-based index of the parameter that defines the size of the array (`CountParamIndex`), or the struct field name (`CountFieldName`) that defines the size of the array
* String constants are considered UTF-16 unless decorated with the `[NativeEncoding("ansi")]` attribute ([#1008](https://github.com/microsoft/win32metadata/issues/1008))
* Struct initializers are defined as constants where the type of the constant is the struct and the initializer string is contained in the `[Constant]` attribute ([#1337](https://github.com/microsoft/win32metadata/issues/1337))
  * NOTE: `SECURITY_NT_AUTHORITY` and all `DEVPROPKEY` and `PROPERTYKEY` constants demonstrate struct initializers.
* Inline functions that return constants are decorated with the `[Constant]` attribute. Projections need to implement these functions themselves to return the constant value. The constant value should be cast to the appropriate type based on the return value of the function. ([#436](https://github.com/microsoft/win32metadata/issues/436))
* `[StructSizeField("<FIELDNAME>")]` on a struct indicates which field of the struct indicates the struct size so that language projections can automatically initialize the field ([#433](https://github.com/microsoft/win32metadata/issues/433))
  * NOTE: Examples of `"<FIELDNAME>"` include `"cbSize"` for a field on the struct or `"StartupInfo.cb"` for a nested field like `StartupInfo.cb` on the `STARTUPINFOEXW` struct
* `[CanReturnAlternateSuccessCodes]` and `[CanReturnErrorsAsSuccess]` attributes add semantic information about the possible return values of a function ([#1315](https://github.com/microsoft/win32metadata/issues/1315))
* `[ReturnsUnownedHandle]` on a return value or out parameter indicates the returned handle is unowned ([#792](https://github.com/microsoft/win32metadata/issues/792))

DISCLAIMER: This list is a work in progress and is not yet comprehensive.

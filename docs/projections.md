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
* The [DllImport](https://learn.microsoft.com/dotnet/api/system.runtime.interopservices.dllimportattribute) attribute is used to define several properties of a function:
  * Entry points are assumed to be the same as function names unless the [EntryPoint](https://learn.microsoft.com/dotnet/api/system.runtime.interopservices.dllimportattribute.entrypoint) property is specified
  * Calling convention is captured in the [CallingConvention](https://learn.microsoft.com/dotnet/api/system.runtime.interopservices.dllimportattribute.callingconvention) property
  * Whether a function calls `SetLastError` before returning is captured in the [SetLastError](https://learn.microsoft.com/dotnet/api/system.runtime.interopservices.dllimportattribute.setlasterror) property
* Architecture-specific types are represented as types with the same name where each type is decorated with the `[SupportedArchitecture]` attribute indicating the architecture(s) where that type is supported
* Ansi and Unicode variants of APIs (-A/-W) are decorated with `[Ansi]` and `[Unicode]` attributes, respectively. Projections can choose to expose one set or the other and remove the suffix to declutter Intellisense and emulate the [unsuffixed macros provided by the headers](https://github.com/microsoft/win32metadata/blob/3608e3fff8cfecfef728bcf1811cdea9f1e86a46/generation/WinSDK/RecompiledIdlHeaders/um/synchapi.h#L446-L451). ([#711](https://github.com/microsoft/win32metadata/issues/711))
* Documentation links are captured in the `[Documentation]` attribute. Rich documentation to power Intellisense can also be loaded from the [Microsoft.Windows.SDK.Win32Docs](https://www.nuget.org/packages/Microsoft.Windows.SDK.Win32Docs/) package which provides a [MessagePack](https://msgpack.org/) dictionary where the keys are API names and the values are [ApiDetails](../apidocs/Microsoft.Windows.SDK.Win32Docs/ApiDetails.cs) objects.
* Input and output parameters are decorated with `[In]` and `[Out]` attributes. Parameters that are both input and output will contain both attributes. COM output pointer parameters are also decorated with the `[ComOutPtr]` attribute.
* Optional parameters are decorated with the `[Optional]` attribute. Optional parameters may be `NULL`.
* Reserved parameters are decorated with the `[Reserved]` attribute. Since reserved parameters always expect a `NULL` value, projections can choose to abstract away these parameters to improve the developer experience.
* Pointer parameters that represent arrays are decorated with the `[NativeArrayInfo]` attribute that can contain the size of a fixed-length array (`CountConst`), the 0-based index of the parameter that defines the size of the array (`CountParamIndex`), or the struct field name (`CountFieldName`) that defines the size of the array
* Pointer parameters whose byte size must be specified in another parameter are decorated with the `[MemorySize]` attribute that will contain the 0-based index of the parameter that can be automatically populated with the size of the provided pointer parameter (`BytesParamIndex`) ([#284](https://github.com/microsoft/win32metadata/issues/284))
* Parameters that accept values from an enum but have conflicting types are decorated with the `[AssociatedEnum]` attribute indicating the enum that may be used with the parameter. The enum must exist in the same namespace as the API. This enables the metadata to preserve the original API definition while allowing projections to improve usability of the API with the enum if they choose. ([#1502](https://github.com/microsoft/win32metadata/issues/1502))
* Output parameters that must be closed with a specific function are decorated with the `[FreeWith]` attribute
* Handle parameters that should not be closed are decorated with the `[DoNotRelease]` attribute
* Handle parameters or return values decorated with `[ReturnsUnownedHandle]` are unowned ([#792](https://github.com/microsoft/win32metadata/issues/792))
* Handle parameters decorated with `[IgnoreIfReturn]` are undefined in failure scenarios and should be ignored if the value specified by the attribute is returned. Multiple return values are represented by multiple attributes. ([#1312](https://github.com/microsoft/win32metadata/issues/1312))
* Return value parameters marked with the `_retval_` SAL annotation are decorated with the `[RetVal]` attribute
* Functions that return multiple success values or return errors as success are decorated with `[CanReturnMultipleSuccessValues]` and `[CanReturnErrorsAsSuccess]` ([#1315](https://github.com/microsoft/win32metadata/issues/1315))
* Variadic functions contain `__arglist` as the final parameter
* Agile interfaces are decorated with the `[Agile]` attribute
* Structs decorated with `[StructSizeField("<FIELDNAME>")]` indicate that `<FIELDNAME>` should be automatically populated with the size of the struct ([#433](https://github.com/microsoft/win32metadata/issues/433))
  * NOTE: Examples of `"<FIELDNAME>"` include `"cbSize"` for a field on the struct or `"StartupInfo.cb"` for a nested field like `StartupInfo.cb` on the `STARTUPINFOEXW` struct
* Flexible array members at the end of a struct are decorated with `[FlexibleArray]` ([#912](https://github.com/microsoft/win32metadata/issues/912))
* Native unions are represented as CLR structs whose names follow the pattern `_<NAME>_e__Union` and are decorated with `[StructLayout(LayoutKind.Explicit)]` where all fields are decorated with `[FieldOffset(0)]`. Anonymous unions will use `AnonymousN` in place of `<NAME>` where `N` is an optional number added to differentiate multiple anonymous unions within the same scope. Named unions will preserve the name in place of `<NAME>`. Struct fields that refer to these unions use `<NAME>` for the field names. ([#99](https://github.com/microsoft/win32metadata/issues/99))
* Scoped enums are decorated with the `[ScopedEnum]` attribute
* typedefs (e.g. `BCRYPT_KEY_HANDLE`) are represented as CLR structs with a single field where either the `NativeTypedef` or `MetadataTypedef` attribute is applied to the struct. `NativeTypedef` represents typedefs that exist in the Win32 headers while `MetadataTypedef` represents metadata-only typedefs added to improve API usability. Projections can choose to unwrap `MetadataTypedef` structs in order to align with the original header definitions. The type being defined is given by the name of the struct, and the type it is being defined as is the type of the struct field. typedefs can include the attributes `AlsoUsableFor`, `RAIIFree` and `InvalidHandleValue`:
  * `AlsoUsableFor` indicates that the type is implicitly convertible to another type (e.g. `BCRYPT_HANDLE`)
  * `RAIIFree` indicates what function should be used to close the handle (e.g. `BCryptDestroyKey`)
  * `InvalidHandleValue` attributes indicate invalid handle values (e.g. `0L`)
  * NOTE: `BCRYPT_KEY_HANDLE` demonstrates all of these attributes.
* Constant variables marked with the `const` keyword are decorated with the `[Const]` attribute
* Struct initializers are defined as constants where the type of the constant is the struct and the initializer string is contained in the `[Constant]` attribute ([#1337](https://github.com/microsoft/win32metadata/issues/1337))
  * NOTE: `SECURITY_NT_AUTHORITY` and all `DEVPROPKEY` and `PROPERTYKEY` constants demonstrate struct initializers.
* String constants are considered UTF-16 unless decorated with the `[NativeEncoding("ansi")]` attribute ([#1008](https://github.com/microsoft/win32metadata/issues/1008))
* Inline functions that return constants are decorated with the `[Constant]` attribute. Projections need to implement these functions themselves to return the constant value. The constant value should be cast to the appropriate type based on the return value of the function. ([#436](https://github.com/microsoft/win32metadata/issues/436))

DISCLAIMER: This list is a work in progress and is not yet comprehensive.

### Examples

* [Windows.Win32.UI.WindowsAndMessaging.SetWindowLongPtrW](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowlongptrw)
  * DllImport attribute
  * SupportedArchitecture attribute
  * Documentation attribute
  * NativeTypedef parameter (HWND)
  * Enum parameter (WINDOW_LONG_PTR_INDEX)
* [Windows.Win32.Security.Cryptography.BcryptEncrypt](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptencrypt)
  * In attribute
  * Out attribute
  * Optional attribute
  * MemorySize attribute
* [Windows.Win32.Devices.DeviceAndDriverInstallation.SetupWriteTextLog](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupwritetextlog)
  * Variadic functions
* [Windows.Win32.System.Diagnostics.Debug.CONTEXT](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-context)
  * SupportedArchitecture attribute
* [Windows.Win32.Devices.Display.DISPLAYCONFIG_VIDEO_SIGNAL_INFO](https://docs.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_video_signal_info)
  * Struct and union fields
  * Bitfields
* [Windows.Win32.UI.WindowsAndMessaging.WNDCLASSEXW](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-wndclassexw)
  * StructSizeField attribute
  * Delegate fields (WNDPROC)
* [Windows.Win32.Security.Cryptography.BCRYPT_KEY_HANDLE](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptimportkey)
  * NativeTypedef
  * AlsoUsableFor attribute
  * RAIIFree attribute
  * InvalidHandleValue attribute

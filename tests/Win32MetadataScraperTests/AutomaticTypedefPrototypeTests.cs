using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text.Json;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class AutomaticTypedefPrototypeTests : HeaderAnnotationWinmdTests
    {
        private const string NativeDeclarations = @"
#define DECLARE_HANDLE(name) struct name##__ { int unused; }; typedef struct name##__ *name
typedef void VOID;
typedef HANDLE ADS_SEARCH_HANDLE;
typedef ADS_SEARCH_HANDLE *PADS_SEARCH_HANDLE;
typedef HANDLE *RAW_HANDLE_POINTER;
typedef unsigned long DWORD;
typedef DWORD SCALAR_ALIAS;
typedef short VARIANT_BOOL;
typedef int HRESULT;
typedef __INTPTR_TYPE__ INT_PTR;
typedef __UINTPTR_TYPE__ UINT_PTR;
typedef INT_PTR APP_SIGNED_POINTER_VALUE;
typedef UINT_PTR APP_UNSIGNED_POINTER_VALUE;
typedef INT_PTR (__stdcall *POINTER_SIZED_CALLBACK)();
DECLARE_HANDLE(HDC);
DECLARE_HANDLE(HDRVR);
typedef struct USet USet;
struct OPAQUE;
typedef struct OPAQUE *OPAQUE_HANDLE;
typedef struct MachineGlobalObjectTableRegistrationToken__ { int unused; }* MachineGlobalObjectTableRegistrationToken;
typedef struct { int _; } *UI_ANIMATION_KEYFRAME;
struct PUBLIC_FIELD_RECORD { EXTERNAL_FIELD_COUNT count; };
typedef struct _RECORD_VALUE { int count; } RECORD_VALUE;
typedef enum _NATIVE_ENUM { NativeFirst = 1, NativeSecond = 2 } NATIVE_ENUM;
typedef RECORD_VALUE RECORD_VALUE_ARRAY[1];
typedef RECORD_VALUE_ARRAY *PRECORD_VALUE_ARRAY;
typedef unsigned char BYTE_VALUE_ARRAY[4];
typedef BYTE_VALUE_ARRAY *PBYTE_VALUE_ARRAY;
template<unsigned Size> struct SCALAR_FOR_SIZE;
template<> struct SCALAR_FOR_SIZE<1> { typedef signed char type; };
template<> struct SCALAR_FOR_SIZE<4> { typedef int type; };
template<class T> struct SIZED_SCALAR {
    typedef typename SCALAR_FOR_SIZE<sizeof(T)>::type type;
};
template<class T> class DEPENDENT_FACTORY {
    typedef struct { T value; } DEPENDENT_RECORD;
    typedef __unaligned DEPENDENT_RECORD *DEPENDENT_POINTER;
    typedef const __unaligned DEPENDENT_RECORD *CONST_DEPENDENT_POINTER;
};
typedef SCALAR_FOR_SIZE<4>::type SELECTED_TEMPLATE_SCALAR;
struct ARRAY_ALIAS_FIELDS {
    PRECORD_VALUE_ARRAY records;
    PBYTE_VALUE_ARRAY bytes;
};
struct GateRecord { int value; };
#define GATE_VALUE 7
_Win32_Enum_(GateGroup, unsigned, GATE_VALUE);
typedef int (__stdcall *CALLBACK_ALIAS)(ADS_SEARCH_HANDLE handle);
const unsigned int E_XML_INVALID = 0xC00CE225U;
extern ""C"" {
ADS_SEARCH_HANDLE __stdcall PrototypeEchoSearchHandle(ADS_SEARCH_HANDLE value);
void __stdcall PrototypeUsePointerAlias(PADS_SEARCH_HANDLE value, RAW_HANDLE_POINTER raw);
void __stdcall PrototypeUseInlinePointers(UI_ANIMATION_KEYFRAME keyframe, MachineGlobalObjectTableRegistrationToken token);
void __stdcall PrototypeUseIntrinsicTypes(INT_PTR signedValue, UINT_PTR unsignedValue,
    APP_SIGNED_POINTER_VALUE signedAlias, APP_UNSIGNED_POINTER_VALUE unsignedAlias, POINTER_SIZED_CALLBACK callback);
EXTERNAL_API_HANDLE __stdcall PrototypeUseExternalDependencies(PUBLIC_FIELD_RECORD* record, EXTERNAL_API_HANDLE value);
void __stdcall PrototypeUseArrayAliases(PRECORD_VALUE_ARRAY records, PBYTE_VALUE_ARRAY bytes, SCALAR_ALIAS count);
SELECTED_TEMPLATE_SCALAR __stdcall PrototypeUseTemplateAlias(SELECTED_TEMPLATE_SCALAR value);
void __stdcall PrototypeUseSurface(HDC dc, HDRVR driver, VARIANT_BOOL booleanValue,
    SCALAR_ALIAS scalarValue, USet* set, OPAQUE_HANDLE opaqueValue,
    RECORD_VALUE recordValue, NATIVE_ENUM enumValue, CALLBACK_ALIAS callback);
HRESULT __stdcall PrototypeReturnResult();
}
";
        private static readonly Dictionary<string, string> Routing = new()
        {
            ["HANDLE"] = "Windows.Win32.Foundation",
            ["HRESULT"] = "Windows.Win32.Foundation",
            ["ADS_SEARCH_HANDLE"] = "Windows.Win32.Networking.ActiveDirectory",
            ["PADS_SEARCH_HANDLE"] = "Windows.Win32.Networking.ActiveDirectory",
            ["RAW_HANDLE_POINTER"] = "Windows.Win32.Networking.ActiveDirectory",
            ["HDC"] = "Windows.Win32.Graphics.Gdi",
            ["HDRVR"] = "Windows.Win32.Media.Multimedia",
            ["VARIANT_BOOL"] = "Windows.Win32.Foundation",
        };

        [Fact]
        public void UnannotatedAliasesEmitAndUseExistingNamespaceRouting()
        {
            RunCase("x64", "x86_64-pc-windows-msvc", annotationsEnabled: false);
            RunCase("x86", "i686-pc-windows-msvc", annotationsEnabled: false);
            RunCase("arm64", "aarch64-pc-windows-msvc", annotationsEnabled: false);
            RunCase("x64", "x86_64-pc-windows-msvc", annotationsEnabled: true);
            AssertInvalidIntrinsicStorage("short", "IntPtr");
            AssertInvalidIntrinsicStorage("__INTPTR_TYPE__", "UIntPtr");
            AssertInvalidPointerStorage("x64", "x86_64-pc-windows-msvc", "__ptr32", 4, 8);
            AssertInvalidPointerStorage("x86", "i686-pc-windows-msvc", "__ptr64", 8, 4);
        }

        private static void AssertInvalidPointerStorage(string architecture, string target, string qualifier, int size, int targetSize)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target,
                "typedef void * " + qualifier + " APPLICATION_POINTER;", annotationsEnabled: false);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("ordinary target-width data pointers at every pointer level", fixture.Diagnostics);
            Assert.Contains("native size " + size + " bytes instead of the target's " + targetSize + " bytes", fixture.Diagnostics);
        }

        private static void AssertInvalidIntrinsicStorage(string nativeType, string managedType)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "typedef " + nativeType + " APPLICATION_INTEGER;", annotationsEnabled: false,
                extraSettings: "--remap\nAPPLICATION_INTEGER=" + managedType + "\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("does not preserve native width, signedness, and pointer depth.", fixture.Diagnostics);
        }

        private static void RunCase(string architecture, string target, bool annotationsEnabled)
        {
            string root = Environment.GetEnvironmentVariable("WIN32_TYPEDEF_PROTOTYPE_EVIDENCE_ROOT");
            string evidence = root == null ? null : Path.Combine(root, architecture + (annotationsEnabled ? "-annotations" : "-ordinary"));
            if (evidence != null)
            {
                Assert.False(Directory.Exists(evidence), "Every prototype invocation requires a new evidence directory.");
                Directory.CreateDirectory(evidence);
            }
            string declarations = NativeDeclarations + (annotationsEnabled ? string.Empty :
                "\n_WIN32META_ANNOTATE_FIELD_(GateRecord::value, _Win32_Reserved_);\n");
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                annotationsEnabled, libraryPath: "candidate-prototype.dll", namespaceName: "Windows.Win32.Foundation",
                extraSettings: "-DWIN32METADATA\n");
            File.AppendAllText(Path.Combine(fixture.DirectoryPath, "cleanup.h"), @"
typedef void* HANDLE;
typedef unsigned long EXTERNAL_COUNT_BASE;
typedef EXTERNAL_COUNT_BASE EXTERNAL_FIELD_COUNT;
typedef void* EXTERNAL_HANDLE_BASE;
typedef EXTERNAL_HANDLE_BASE EXTERNAL_API_HANDLE;
typedef int EXTERNAL_UNUSED;
");
            try
            {
                fixture.AssertSuccess(annotationsEnabled ? Array.Empty<string>() : new[] { "MSInheritance" });
                Assert.DoesNotContain("_Win32_NativeTypedef_", File.ReadAllText(fixture.Header));
                string companion = fixture.ReadAdditionalTypes();
                Assert.DoesNotContain("_WIN32META_FIELD_", fixture.ReadSource() + companion);
                Assert.Contains("struct ADS_SEARCH_HANDLE", companion);
                Assert.Contains("ADS_SEARCH_HANDLE* Value", companion);
                Assert.Contains("HANDLE* Value", companion);
                using var image = Emit(fixture.DirectoryPath, architecture, requiredNamespaces: Routing,
                    winmdFileName: "Windows.Win32.winmd");
                var reader = image.Reader;
                var decoder = new SignatureNames(qualifiedNames: true);
                if (evidence != null)
                {
                    var observed = new
                    {
                        architecture,
                        target,
                        annotationsEnabled,
                        headerMarkers = 0,
                        image = Pin(Path.Combine(fixture.DirectoryPath, "Windows.Win32.winmd")),
                        runtime = RuntimeInformation.FrameworkDescription,
                        processorCount = Environment.ProcessorCount,
                        affinity = OperatingSystem.IsWindows() || OperatingSystem.IsLinux()
                            ? (long?)System.Diagnostics.Process.GetCurrentProcess().ProcessorAffinity.ToInt64() : null,
                        tools = new[]
                        {
                            Pin(typeof(Win32MetadataScraper.RemapDiscovery).Assembly.Location),
                            Pin(typeof(ClangSharpSourceToWinmd.ClangSharpSourceCompilation).Assembly.Location),
                            Pin(typeof(AutomaticTypedefPrototypeTests).Assembly.Location),
                        },
                        types = reader.TypeDefinitions.Select(handle =>
                        {
                            var type = reader.GetTypeDefinition(handle);
                            return new
                            {
                                token = "0x" + MetadataTokens.GetToken(handle).ToString("X8"),
                                name = reader.GetString(type.Namespace) + "." + reader.GetString(type.Name),
                                attributes = type.GetCustomAttributes().Select(value => AttributeName(reader, value)).ToArray(),
                                fields = type.GetFields().Select(fieldHandle =>
                                {
                                    var field = reader.GetFieldDefinition(fieldHandle);
                                    return new
                                    {
                                        token = "0x" + MetadataTokens.GetToken(fieldHandle).ToString("X8"),
                                        name = reader.GetString(field.Name),
                                        type = field.DecodeSignature(decoder, null),
                                        rawSignature = Convert.ToHexString(reader.GetBlobBytes(field.Signature)),
                                    };
                                }).ToArray(),
                                methods = type.GetMethods().Select(methodHandle =>
                                {
                                    var method = reader.GetMethodDefinition(methodHandle);
                                    var signature = method.DecodeSignature(decoder, null);
                                    return new
                                    {
                                        token = "0x" + MetadataTokens.GetToken(methodHandle).ToString("X8"),
                                        name = reader.GetString(method.Name),
                                        returnType = signature.ReturnType,
                                        parameters = signature.ParameterTypes.ToArray(),
                                        rawSignature = Convert.ToHexString(reader.GetBlobBytes(method.Signature)),
                                    };
                                }).ToArray(),
                            };
                        }).ToArray(),
                    };
                    File.WriteAllText(Path.Combine(evidence, "observed-metadata.json"),
                        JsonSerializer.Serialize(observed, new JsonSerializerOptions { WriteIndented = true }));
                }
                foreach (var route in Routing)
                    Assert.Equal(route.Value, reader.GetString(FindType(reader, route.Key).Namespace));

                AssertWrapper(reader, "HANDLE", "Void*");
                AssertWrapper(reader, "ADS_SEARCH_HANDLE", "Windows.Win32.Foundation.HANDLE");
                AssertWrapper(reader, "PADS_SEARCH_HANDLE", "Windows.Win32.Networking.ActiveDirectory.ADS_SEARCH_HANDLE*");
                AssertWrapper(reader, "RAW_HANDLE_POINTER", "Windows.Win32.Foundation.HANDLE*");
                AssertWrapper(reader, "DWORD", "UInt32");
                AssertWrapper(reader, "SCALAR_ALIAS", "Windows.Win32.Foundation.DWORD");
                AssertWrapper(reader, "VARIANT_BOOL", "Int16");
                AssertWrapper(reader, "APP_SIGNED_POINTER_VALUE", "IntPtr");
                AssertWrapper(reader, "APP_UNSIGNED_POINTER_VALUE", "UIntPtr");
                AssertWrapper(reader, "EXTERNAL_COUNT_BASE", "UInt32");
                AssertWrapper(reader, "EXTERNAL_FIELD_COUNT", "Windows.Win32.Foundation.EXTERNAL_COUNT_BASE");
                AssertWrapper(reader, "EXTERNAL_HANDLE_BASE", "Void*");
                AssertWrapper(reader, "EXTERNAL_API_HANDLE", "Windows.Win32.Foundation.EXTERNAL_HANDLE_BASE");
                AssertWrapper(reader, "SELECTED_TEMPLATE_SCALAR", "Int32");
                Assert.DoesNotContain(reader.TypeDefinitions, handle => reader.GetString(reader.GetTypeDefinition(handle).Name) == "EXTERNAL_UNUSED");
                foreach (string name in new[]
                {
                    "RECORD_VALUE_ARRAY", "PRECORD_VALUE_ARRAY", "BYTE_VALUE_ARRAY", "PBYTE_VALUE_ARRAY",
                    "type", "DEPENDENT_POINTER", "CONST_DEPENDENT_POINTER",
                })
                    Assert.DoesNotContain(reader.TypeDefinitions, handle => reader.GetString(reader.GetTypeDefinition(handle).Name) == name);
                var arrayFields = FindType(reader, "ARRAY_ALIAS_FIELDS").GetFields().Select(reader.GetFieldDefinition).ToArray();
                Assert.Equal(new[] { "records", "bytes" }, arrayFields.Select(field => reader.GetString(field.Name)));
                Assert.Equal(new[] { "Windows.Win32.Foundation.RECORD_VALUE*", "Byte*" },
                    arrayFields.Select(field => field.DecodeSignature(decoder, null)));
                var externalRecord = FindType(reader, "PUBLIC_FIELD_RECORD");
                var externalCount = reader.GetFieldDefinition(Assert.Single(externalRecord.GetFields()));
                Assert.Equal("count", reader.GetString(externalCount.Name));
                Assert.Equal("Windows.Win32.Foundation.EXTERNAL_FIELD_COUNT", externalCount.DecodeSignature(decoder, null));
                Assert.DoesNotContain(reader.TypeDefinitions, handle => reader.GetString(reader.GetTypeDefinition(handle).Name) == "INT_PTR");
                Assert.DoesNotContain(reader.TypeDefinitions, handle => reader.GetString(reader.GetTypeDefinition(handle).Name) == "UINT_PTR");
                AssertWrapper(reader, "HDC", "Windows.Win32.Foundation.HDC__*");
                AssertWrapper(reader, "HDRVR", "Windows.Win32.Foundation.HDRVR__*");
                var set = FindType(reader, "USet");
                Assert.Empty(set.GetFields());
                AssertDoesNotHaveAttribute(reader, set.GetCustomAttributes(), "NativeTypedefAttribute");
                var record = FindType(reader, "RECORD_VALUE");
                Assert.Equal("count", reader.GetString(reader.GetFieldDefinition(Assert.Single(record.GetFields())).Name));
                AssertDoesNotHaveAttribute(reader, record.GetCustomAttributes(), "NativeTypedefAttribute");
                AssertDoesNotHaveAttribute(reader, FindType(reader, "NATIVE_ENUM").GetCustomAttributes(), "NativeTypedefAttribute");
                var gateField = reader.GetFieldDefinition(Assert.Single(FindType(reader, "GateRecord").GetFields()));
                AssertDoesNotHaveAttribute(reader, gateField.GetCustomAttributes(), "ReservedAttribute");
                if (annotationsEnabled)
                {
                    AssertDoesNotHaveAttribute(reader, FindType(reader, "GateGroup").GetCustomAttributes(), "NativeTypedefAttribute");
                }
                else
                {
                    AssertWrapper(reader, "GateGroup", "UInt32");
                }
                AssertWrapper(reader, "OPAQUE_HANDLE", "Windows.Win32.Foundation.OPAQUE*");
                Assert.Empty(FindType(reader, "OPAQUE").GetFields());
                AssertInlineRecordPointer(reader, "UI_ANIMATION_KEYFRAME", "_");
                AssertInlineRecordPointer(reader, "MachineGlobalObjectTableRegistrationToken", "unused",
                    "Windows.Win32.Foundation.MachineGlobalObjectTableRegistrationToken__");
                var method = FindMethod(reader, "Apis", "PrototypeEchoSearchHandle").DecodeSignature(decoder, null);
                Assert.Equal("Windows.Win32.Networking.ActiveDirectory.ADS_SEARCH_HANDLE", method.ReturnType);
                Assert.Equal(method.ReturnType, Assert.Single(method.ParameterTypes));
                var pointerMethod = FindMethod(reader, "Apis", "PrototypeUsePointerAlias").DecodeSignature(decoder, null);
                Assert.Equal(new[]
                {
                    "Windows.Win32.Networking.ActiveDirectory.PADS_SEARCH_HANDLE",
                    "Windows.Win32.Networking.ActiveDirectory.RAW_HANDLE_POINTER",
                }, pointerMethod.ParameterTypes);
                var inlineMethod = FindMethod(reader, "Apis", "PrototypeUseInlinePointers").DecodeSignature(decoder, null);
                Assert.Equal(new[]
                {
                    "Windows.Win32.Foundation.UI_ANIMATION_KEYFRAME",
                    "Windows.Win32.Foundation.MachineGlobalObjectTableRegistrationToken",
                }, inlineMethod.ParameterTypes);
                var intrinsicMethod = FindMethod(reader, "Apis", "PrototypeUseIntrinsicTypes").DecodeSignature(decoder, null);
                Assert.Equal(new[]
                {
                    "IntPtr", "UIntPtr",
                    "Windows.Win32.Foundation.APP_SIGNED_POINTER_VALUE",
                    "Windows.Win32.Foundation.APP_UNSIGNED_POINTER_VALUE",
                    "Windows.Win32.Foundation.POINTER_SIZED_CALLBACK",
                }, intrinsicMethod.ParameterTypes);
                Assert.Equal("IntPtr", FindMethod(reader, "POINTER_SIZED_CALLBACK", "Invoke").DecodeSignature(decoder, null).ReturnType);
                var externalMethod = FindMethod(reader, "Apis", "PrototypeUseExternalDependencies").DecodeSignature(decoder, null);
                Assert.Equal("Windows.Win32.Foundation.EXTERNAL_API_HANDLE", externalMethod.ReturnType);
                Assert.Equal(new[]
                {
                    "Windows.Win32.Foundation.PUBLIC_FIELD_RECORD*",
                    "Windows.Win32.Foundation.EXTERNAL_API_HANDLE",
                }, externalMethod.ParameterTypes);
                var arrayMethod = FindMethod(reader, "Apis", "PrototypeUseArrayAliases").DecodeSignature(decoder, null);
                // Preserve the ordinary generator's parameter projection for pointer-to-array aliases.
                Assert.Equal(new[]
                {
                    "Windows.Win32.Foundation.RECORD_VALUE**", "Byte**", "Windows.Win32.Foundation.SCALAR_ALIAS",
                }, arrayMethod.ParameterTypes);
                var templateMethod = FindMethod(reader, "Apis", "PrototypeUseTemplateAlias").DecodeSignature(decoder, null);
                Assert.Equal("Windows.Win32.Foundation.SELECTED_TEMPLATE_SCALAR", templateMethod.ReturnType);
                Assert.Equal(templateMethod.ReturnType, Assert.Single(templateMethod.ParameterTypes));
                var callback = FindMethod(reader, "CALLBACK_ALIAS", "Invoke").DecodeSignature(decoder, null);
                Assert.Equal("Int32", callback.ReturnType);
                Assert.Equal(method.ReturnType, Assert.Single(callback.ParameterTypes));
                var surface = FindMethod(reader, "Apis", "PrototypeUseSurface").DecodeSignature(decoder, null);
                Assert.Equal(new[]
                {
                    "Windows.Win32.Graphics.Gdi.HDC",
                    "Windows.Win32.Media.Multimedia.HDRVR",
                    "Windows.Win32.Foundation.VARIANT_BOOL",
                    "Windows.Win32.Foundation.SCALAR_ALIAS",
                    "Windows.Win32.Foundation.USet*",
                    "Windows.Win32.Foundation.OPAQUE_HANDLE",
                    "Windows.Win32.Foundation.RECORD_VALUE",
                    "Windows.Win32.Foundation.NATIVE_ENUM",
                    "Windows.Win32.Foundation.CALLBACK_ALIAS",
                }, surface.ParameterTypes);
                var xml = FindType(reader, "Apis").GetFields().Select(reader.GetFieldDefinition)
                    .Single(field => reader.GetString(field.Name) == "E_XML_INVALID");
                Assert.Equal("UInt32", xml.DecodeSignature(decoder, null));
                var xmlConstant = reader.GetConstant(xml.GetDefaultValue());
                Assert.Equal(ConstantTypeCode.UInt32, xmlConstant.TypeCode);
                Assert.Equal("25E20CC0", Convert.ToHexString(reader.GetBlobBytes(xmlConstant.Value)));
                AssertMetadataClosure(reader);
            }
            finally
            {
                if (evidence != null)
                {
                    File.WriteAllText(Path.Combine(evidence, "scraper.stdout-stderr.log"), fixture.Diagnostics ?? "");
                    foreach (string file in Directory.EnumerateFiles(fixture.DirectoryPath, "*", SearchOption.AllDirectories))
                    {
                        string destination = Path.Combine(evidence, "fixture", Path.GetRelativePath(fixture.DirectoryPath, file));
                        Directory.CreateDirectory(Path.GetDirectoryName(destination));
                        File.Copy(file, destination, overwrite: false);
                    }
                }
            }
        }

        private static void AssertWrapper(MetadataReader reader, string name, string expectedStorage)
        {
            var type = FindType(reader, name);
            AssertHasAttribute(reader, type.GetCustomAttributes(), "NativeTypedefAttribute");
            var field = reader.GetFieldDefinition(Assert.Single(type.GetFields()));
            Assert.Equal("Value", reader.GetString(field.Name));
            Assert.Equal(expectedStorage, field.DecodeSignature(new SignatureNames(qualifiedNames: true), null));
        }

        private static void AssertInlineRecordPointer(MetadataReader reader, string alias, string nativeField, string expectedPointee = null)
        {
            var wrapper = FindType(reader, alias);
            AssertHasAttribute(reader, wrapper.GetCustomAttributes(), "NativeTypedefAttribute");
            var value = reader.GetFieldDefinition(Assert.Single(wrapper.GetFields()));
            string signature = value.DecodeSignature(new SignatureNames(qualifiedNames: true), null);
            Assert.EndsWith("*", signature);
            Assert.DoesNotContain("**", signature);
            string pointee = signature.Substring(0, signature.Length - 1);
            if (expectedPointee != null)
                Assert.Equal(expectedPointee, pointee);
            var record = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Namespace) + "." + reader.GetString(type.Name) == pointee);
            AssertDoesNotHaveAttribute(reader, record.GetCustomAttributes(), "NativeTypedefAttribute");
            var field = reader.GetFieldDefinition(Assert.Single(record.GetFields()));
            Assert.Equal(nativeField, reader.GetString(field.Name));
            Assert.Equal("Int32", field.DecodeSignature(new SignatureNames(), null));
        }

        private static object Pin(string path) => new
        {
            path,
            bytes = new FileInfo(path).Length,
            sha256 = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path))),
        };
    }
}

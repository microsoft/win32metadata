using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text.Json;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class AutomaticTypedefPrototypeTests : HeaderAnnotationWinmdTests
    {
        private const string NativeDeclarations = @"
#define DECLARE_HANDLE(name) struct name##__ { int unused; }; typedef struct name##__ *name
#define DECLARE_OPAQUE_KEY(name) typedef struct name##__ { long long Internal; } name, *P##name
typedef void VOID;
typedef HANDLE ADS_SEARCH_HANDLE;
typedef ADS_SEARCH_HANDLE *PADS_SEARCH_HANDLE;
typedef HANDLE *RAW_HANDLE_POINTER;
typedef unsigned long DWORD;
typedef unsigned char BYTE_CODE;
typedef unsigned char byte;
typedef unsigned int event;
typedef DWORD SCALAR_ALIAS;
typedef short VARIANT_BOOL;
typedef int HRESULT;
typedef __INTPTR_TYPE__ INT_PTR;
typedef __UINTPTR_TYPE__ UINT_PTR;
typedef UINT_PTR *APP_UNSIGNED_POINTER_ADDRESS;
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
typedef struct PROVIDED_TOKEN_t *PROVIDED_TOKEN, **PPROVIDED_TOKEN;
typedef VOID *UNTYPED_RECORD_ADDRESS;
typedef unsigned long NATIVE_COUNT_BASE;
typedef NATIVE_COUNT_BASE SIBLING_COUNT, *PSIBLING_COUNT;
typedef int NATIVE_BOOLEAN_BASE;
typedef NATIVE_BOOLEAN_BASE SIBLING_BOOLEAN, *PSIBLING_BOOLEAN;
typedef unsigned long long NATIVE_SESSION_BITS;
typedef NATIVE_SESSION_BITS SESSION_KEY, *PSESSION_KEY;
typedef HANDLE SIBLING_HANDLE, *PSIBLING_HANDLE;
typedef struct PROVIDED_CONTEXT_t *PPROVIDED_CONTEXT;
typedef struct _RECORD_VALUE RECORD_VIEW, *PRECORD_VIEW;
typedef int REDECLARED_BOOLEAN;
typedef NATIVE_BOOLEAN_BASE REDECLARED_BOOLEAN, *PREDECLARED_BOOLEAN;
DECLARE_HANDLE(PRIMARY_RESOURCE);
typedef PRIMARY_RESOURCE SECONDARY_RESOURCE;
typedef PRIMARY_RESOURCE *PSECONDARY_RESOURCE;
DECLARE_OPAQUE_KEY(OPAQUE_VALUE_KEY);
struct EXPLICIT_POINTER_FIELDS {
    PPROVIDED_TOKEN token;
    UNTYPED_RECORD_ADDRESS record;
    PSIBLING_COUNT count;
    PSIBLING_BOOLEAN boolean;
    PSESSION_KEY session;
    PSIBLING_HANDLE handle;
    PPROVIDED_CONTEXT context;
    PRECORD_VIEW view;
    PREDECLARED_BOOLEAN repeated;
    PSECONDARY_RESOURCE secondary;
    POPAQUE_VALUE_KEY key;
};
static_assert(sizeof(PROVIDED_TOKEN) == sizeof(void*), ""Provider width changed."");
static_assert(sizeof(PPROVIDED_TOKEN) == sizeof(void*), ""Provider pointer width changed."");
static_assert(sizeof(UNTYPED_RECORD_ADDRESS) == sizeof(void*), ""Untyped pointer width changed."");
static_assert(sizeof(SESSION_KEY) == 8 && alignof(SESSION_KEY) == 8, ""Session storage changed."");
static_assert(sizeof(RECORD_VIEW) == sizeof(RECORD_VALUE), ""Record view storage changed."");
static_assert(sizeof(OPAQUE_VALUE_KEY) == 8 && alignof(OPAQUE_VALUE_KEY) == 8, ""Opaque value storage changed."");
static_assert(sizeof(EXPLICIT_POINTER_FIELDS) == 11 * sizeof(void*), ""Pointer field layout changed."");
static_assert(alignof(EXPLICIT_POINTER_FIELDS) == alignof(void*), ""Pointer field alignment changed."");
typedef enum _NATIVE_ENUM { NativeFirst = 1, NativeSecond = 2 } NATIVE_ENUM;
typedef unsigned long LEGACY_MASK;
typedef enum _LEGACY_MASK { LegacyMaskFirst = 1, LegacyMaskSecond = 2 } _LEGACY_MASK;
typedef unsigned long LEGACY_HIGH_MASK;
typedef enum _LEGACY_HIGH_MASK { LegacyMaskHigh = 0x80000000U } _LEGACY_HIGH_MASK;
enum class NATIVE_SCOPED : unsigned { NativeOnly = 1 };
typedef __UINTPTR_TYPE__ LEGACY_RESOURCE;
#define DECLARE_RECORD_BUFFER(n) typedef struct _RECORD_BUFFER { RECORD_VALUE values[n]; } RECORD_BUFFER, *PRECORD_BUFFER
DECLARE_RECORD_BUFFER(2);
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
const BYTE_CODE LOWER_MARKER = (signed char)('l');
const BYTE_CODE UPPER_MARKER = (signed char)('B');
const DWORD UNSIGNED_STATUS_UNAVAILABLE = (DWORD)(-1);
static_assert(sizeof(BYTE_CODE) == 1 && sizeof(DWORD) == 4, ""Native constant storage changed."");
static_assert(LOWER_MARKER == 108 && UPPER_MARKER == 66 &&
    UNSIGNED_STATUS_UNAVAILABLE == 0xffffffffU, ""Native constant values changed."");
extern ""C"" {
ADS_SEARCH_HANDLE __stdcall PrototypeEchoSearchHandle(ADS_SEARCH_HANDLE value);
void __stdcall PrototypeUsePointerAlias(PADS_SEARCH_HANDLE value, RAW_HANDLE_POINTER raw);
void __stdcall PrototypeUseInlinePointers(UI_ANIMATION_KEYFRAME keyframe, MachineGlobalObjectTableRegistrationToken token);
void __stdcall PrototypeUseIntrinsicTypes(INT_PTR signedValue, UINT_PTR unsignedValue,
    APP_SIGNED_POINTER_VALUE signedAlias, APP_UNSIGNED_POINTER_VALUE unsignedAlias, POINTER_SIZED_CALLBACK callback);
void __stdcall PrototypeUseMappedPointerAliases(RAW_HANDLE_POINTER handle, PADS_SEARCH_HANDLE search, APP_UNSIGNED_POINTER_ADDRESS integer);
void __stdcall PrototypeUseExplicitPointerViews(PPROVIDED_TOKEN token, UNTYPED_RECORD_ADDRESS record);
void __stdcall PrototypeUseSiblingPointers(PSIBLING_COUNT count, PSIBLING_BOOLEAN boolean,
    PSESSION_KEY session, PSIBLING_HANDLE handle, PPROVIDED_CONTEXT context, PRECORD_VIEW view);
int __stdcall PrototypeCloseSession(SESSION_KEY value);
void __stdcall PrototypeUseAlternateOwners(PREDECLARED_BOOLEAN repeated, PSECONDARY_RESOURCE resource, POPAQUE_VALUE_KEY key, OPAQUE_VALUE_KEY value);
int __stdcall PrototypeCloseOpaqueValue(OPAQUE_VALUE_KEY value);
EXTERNAL_API_HANDLE __stdcall PrototypeUseExternalDependencies(PUBLIC_FIELD_RECORD* record, EXTERNAL_API_HANDLE value);
void __stdcall PrototypeUseArrayAliases(PRECORD_VALUE_ARRAY records, PBYTE_VALUE_ARRAY bytes, SCALAR_ALIAS count);
SELECTED_TEMPLATE_SCALAR __stdcall PrototypeUseTemplateAlias(SELECTED_TEMPLATE_SCALAR value);
void __stdcall PrototypeUsePrimitiveAndOwnedTypes(byte value, byte* buffer, event namedValue, LEGACY_RESOURCE resource, NATIVE_SCOPED scoped);
void __stdcall PrototypeUseRecordBuffer(PRECORD_BUFFER value);
void __stdcall PrototypeUseSurface(HDC dc, HDRVR driver, VARIANT_BOOL booleanValue,
    SCALAR_ALIAS scalarValue, USet* set, OPAQUE_HANDLE opaqueValue,
    RECORD_VALUE recordValue, NATIVE_ENUM enumValue, CALLBACK_ALIAS callback);
HRESULT __stdcall PrototypeReturnResult();
void __stdcall PrototypeUseProjectedEnums(LEGACY_MASK mask, LEGACY_HIGH_MASK high);
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
            AssertFixedWidthPointerStorage("x64", "x86_64-pc-windows-msvc", "__ptr32", 4, 8);
            AssertFixedWidthPointerStorage("x86", "i686-pc-windows-msvc", "__ptr64", 8, 4);
            AssertEnumProjectionStorage();
            AssertInvalidStorageBatches();
        }

        private static void AssertEnumProjectionStorage()
        {
            string root = Environment.GetEnvironmentVariable("WIN32_TYPEDEF_PROTOTYPE_EVIDENCE_ROOT");
            string evidence = root == null ? null : Path.Combine(root, "enum-unsigned-long");
            if (evidence != null)
            {
                Assert.False(Directory.Exists(evidence));
                Directory.CreateDirectory(evidence);
            }
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                @"typedef unsigned long PROJECTED_VALUE;
typedef enum _PROJECTED_VALUE { ProjectedFirst = 1 } _PROJECTED_VALUE;
extern ""C"" void UseProjected(PROJECTED_VALUE value);",
                annotationsEnabled: false, extraSettings: "--remap\n_PROJECTED_VALUE=PROJECTED_VALUE\n");
            try
            {
                fixture.AssertSuccess();
                Assert.Contains("enum PROJECTED_VALUE", fixture.ReadSource());
                Assert.DoesNotContain("struct PROJECTED_VALUE", fixture.ReadAdditionalTypes());
            }
            finally
            {
                RetainFixture(fixture, evidence);
            }
        }

        private static void AssertFixedWidthPointerStorage(string architecture, string target, string qualifier, int size, int targetSize)
        {
            string root = Environment.GetEnvironmentVariable("WIN32_TYPEDEF_PROTOTYPE_EVIDENCE_ROOT");
            string evidence = root == null ? null : Path.Combine(root, architecture + qualifier + "-fixed-width");
            if (evidence != null)
            {
                Assert.False(Directory.Exists(evidence));
                Directory.CreateDirectory(evidence);
            }
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target,
                "typedef void * " + qualifier + @" APPLICATION_POINTER;
typedef APPLICATION_POINTER FIXED_CHAIN;
typedef APPLICATION_POINTER* APPLICATION_POINTER_ADDRESS;
typedef void * " + qualifier + @" *RAW_APPLICATION_POINTER_ADDRESS;
struct WIDTH_RECORD { unsigned char prefix; APPLICATION_POINTER value; unsigned char tail; };
static_assert(sizeof(APPLICATION_POINTER) == " + size + @", ""Native pointer width changed."");
static_assert(sizeof(WIDTH_RECORD) > 0, ""Force native record layout."");
extern ""C"" APPLICATION_POINTER WidthEcho(APPLICATION_POINTER value);
extern ""C"" APPLICATION_POINTER __stdcall WidthStdcallEcho(APPLICATION_POINTER value);
extern ""C"" void WidthUseRecord(WIDTH_RECORD* record);",
                annotationsEnabled: false, namespaceName: "Windows.Win32.Foundation",
                extraSettings: "--additional=-Xclang\n--additional=-fdump-record-layouts\n");
            try
            {
                fixture.AssertSuccess();
                using var image = Emit(fixture.DirectoryPath, architecture);
                var reader = image.Reader;
                var decoder = new SignatureNames(qualifiedNames: true);
                string aliasType = "Windows.Win32.Foundation.APPLICATION_POINTER";
                string storage = size == 4 ? "UInt32" : "UInt64";
                AssertWrapper(reader, "APPLICATION_POINTER", storage);
                AssertWrapper(reader, "FIXED_CHAIN", aliasType);
                AssertWrapper(reader, "APPLICATION_POINTER_ADDRESS", aliasType + "*");
                AssertWrapper(reader, "RAW_APPLICATION_POINTER_ADDRESS", storage + "*");
                var alias = FindType(reader, "APPLICATION_POINTER");
                var value = reader.GetFieldDefinition(Assert.Single(alias.GetFields()));
                var aliasSource = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot().DescendantNodes()
                    .OfType<StructDeclarationSyntax>().Single(type => type.Identifier.ValueText == "APPLICATION_POINTER");
                var valueSource = (FieldDeclarationSyntax)Assert.Single(aliasSource.Members);
                Assert.Equal(size == 4 ? "uint" : "ulong", valueSource.Declaration.Type.ToString());
                string nativeType = MetadataUtils.SyntaxUtils.GetNativeTypeNameFromAttributesLists(valueSource.AttributeLists);
                Assert.Contains(qualifier, nativeType);
                Assert.Contains("void", nativeType);
                AssertDoesNotHaveAttribute(reader, value.GetCustomAttributes(), "NativeTypeNameAttribute");
                var record = FindType(reader, "WIDTH_RECORD");
                var fields = record.GetFields().Select(reader.GetFieldDefinition).ToArray();
                Assert.Equal(new[] { "prefix", "value", "tail" }, fields.Select(field => reader.GetString(field.Name)));
                Assert.Equal(new[] { "Byte", aliasType, "Byte" }, fields.Select(field => field.DecodeSignature(decoder, null)));
                Assert.Equal(TypeAttributes.SequentialLayout, record.Attributes & TypeAttributes.LayoutMask);
                Assert.Equal(TypeAttributes.SequentialLayout, alias.Attributes & TypeAttributes.LayoutMask);
                var cdeclMethod = FindMethod(reader, "Apis", "WidthEcho");
                var method = cdeclMethod.DecodeSignature(decoder, null);
                Assert.Equal(aliasType, method.ReturnType);
                Assert.Equal(aliasType, Assert.Single(method.ParameterTypes));
                Assert.Equal(MethodImportAttributes.CallingConventionCDecl,
                    cdeclMethod.GetImport().Attributes & MethodImportAttributes.CallingConventionMask);
                var stdcallMethod = FindMethod(reader, "Apis", "WidthStdcallEcho");
                var stdcallSignature = stdcallMethod.DecodeSignature(decoder, null);
                Assert.Equal(aliasType, stdcallSignature.ReturnType);
                Assert.Equal(aliasType, Assert.Single(stdcallSignature.ParameterTypes));
                Assert.Equal(MethodImportAttributes.CallingConventionWinApi,
                    stdcallMethod.GetImport().Attributes & MethodImportAttributes.CallingConventionMask);
                if (evidence != null)
                {
                    var layout = record.GetLayout();
                    File.WriteAllText(Path.Combine(evidence, "observed-metadata.json"), JsonSerializer.Serialize(new
                    {
                        architecture,
                        target,
                        qualifier,
                        nativePointerBytes = size,
                        targetPointerBytes = targetSize,
                        aliasType,
                        storage,
                        storageBytes = size,
                        nativeType,
                        nativeTypeProvenance = "generated C# Value.NativeTypeName; consumed by the ordinary emitter",
                        aliasAttributes = alias.Attributes.ToString(),
                        aliasLayoutSize = alias.GetLayout().Size,
                        aliasLayoutPackingSize = alias.GetLayout().PackingSize,
                        aliasValueRawSignature = Convert.ToHexString(reader.GetBlobBytes(value.Signature)),
                        recordAttributes = record.Attributes.ToString(),
                        layoutSize = layout.Size,
                        layoutPackingSize = layout.PackingSize,
                        fields = fields.Select(field => new
                        {
                            name = reader.GetString(field.Name),
                            type = field.DecodeSignature(decoder, null),
                            offset = field.GetOffset(),
                            rawSignature = Convert.ToHexString(reader.GetBlobBytes(field.Signature)),
                        }).ToArray(),
                        methodReturnType = method.ReturnType,
                        methodParameterTypes = method.ParameterTypes.ToArray(),
                        cdeclImportAttributes = cdeclMethod.GetImport().Attributes.ToString(),
                        stdcallReturnType = stdcallSignature.ReturnType,
                        stdcallParameterTypes = stdcallSignature.ParameterTypes.ToArray(),
                        stdcallImportAttributes = stdcallMethod.GetImport().Attributes.ToString(),
                    }, new JsonSerializerOptions { WriteIndented = true }));
                }
            }
            finally
            {
                RetainFixture(fixture, evidence);
            }
        }

        private static void AssertInvalidStorageBatches()
        {
            AssertRejectedStorageBatch("x64", "x86_64-pc-windows-msvc", "native-storage",
                @"typedef short NARROW_INTEGER;
typedef __INTPTR_TYPE__ SIGNED_INTEGER;
typedef void* __ptr32 NARROW_POINTER;
typedef void* FIRST_OWNER;
typedef void* SECOND_OWNER;
typedef FIRST_OWNER* FOREIGN_POINTER;",
                "--remap\nNARROW_INTEGER=IntPtr\nSIGNED_INTEGER=UIntPtr\nNARROW_POINTER=IntPtr\nFOREIGN_POINTER=SECOND_OWNER*\n",
                IntegerError("NARROW_INTEGER=IntPtr"), IntegerError("SIGNED_INTEGER=UIntPtr"),
                PointerError("NARROW_POINTER=IntPtr"), PointerError("FOREIGN_POINTER=SECOND_OWNER*"));
            AssertRejectedStorageBatch("x86", "i686-pc-windows-msvc", "native-storage",
                @"typedef void* __ptr64 WIDE_POINTER;
typedef unsigned long long LEGACY_RESOURCE;
typedef struct NARROW_OWNER__ { long long value; } NARROW_OWNER, *BAD_NARROW_POINTEE;
typedef struct FLOAT_OWNER__ { double value; } FLOAT_OWNER, *BAD_FLOAT_POINTEE;
struct WIDE_OWNER__;
typedef WIDE_OWNER__* __ptr64 WIDE_OWNER;
typedef WIDE_OWNER* BAD_NOMINAL_WIDTH;
struct RAW_WIDE_OWNER__;
typedef RAW_WIDE_OWNER__* __ptr64 RAW_WIDE_OWNER, * __ptr64 *BAD_RAW_WIDTH;",
                "--remap\nWIDE_POINTER=IntPtr\nLEGACY_RESOURCE=IntPtr\nLEGACY_RESOURCE__*=LEGACY_RESOURCE\n" +
                "NARROW_OWNER=int\nNARROW_OWNER__*=NARROW_OWNER\nBAD_NARROW_POINTEE=NARROW_OWNER*\n" +
                "FLOAT_OWNER=long\nFLOAT_OWNER__*=FLOAT_OWNER\nBAD_FLOAT_POINTEE=FLOAT_OWNER*\n" +
                "WIDE_OWNER=IntPtr\nWIDE_OWNER__*=WIDE_OWNER\nBAD_NOMINAL_WIDTH=WIDE_OWNER*\n" +
                "RAW_WIDE_OWNER__=IntPtr\nBAD_RAW_WIDTH=RAW_WIDE_OWNER*\n" +
                "--exclude\nLEGACY_RESOURCE__\nNARROW_OWNER__\nFLOAT_OWNER__\nWIDE_OWNER\nWIDE_OWNER__\nRAW_WIDE_OWNER\nRAW_WIDE_OWNER__\n",
                PointerError("WIDE_POINTER=IntPtr"), IntegerError("LEGACY_RESOURCE=IntPtr"),
                PointerError("BAD_NARROW_POINTEE=NARROW_OWNER*"), PointerError("BAD_FLOAT_POINTEE=FLOAT_OWNER*"),
                PointerError("BAD_NOMINAL_WIDTH=WIDE_OWNER*"), PointerError("BAD_RAW_WIDTH=RAW_WIDE_OWNER*"));

            // Enum projection happens after discovery errors have already stopped generation.
            AssertRejectedStorageBatch("x64", "x86_64-pc-windows-msvc", "enum-storage",
                @"typedef unsigned long long PROJECTED_WIDE;
typedef enum _PROJECTED_WIDE { WideFirst = 1 } _PROJECTED_WIDE;
typedef float PROJECTED_FLOAT;
typedef enum _PROJECTED_FLOAT { FloatFirst = 1 } _PROJECTED_FLOAT;
typedef void* PROJECTED_POINTER;
typedef enum _PROJECTED_POINTER { PointerFirst = 1 } _PROJECTED_POINTER;",
                "--remap\n_PROJECTED_WIDE=PROJECTED_WIDE\n_PROJECTED_FLOAT=PROJECTED_FLOAT\n_PROJECTED_POINTER=PROJECTED_POINTER\n",
                EnumError("PROJECTED_WIDE"), EnumError("PROJECTED_FLOAT"), EnumError("PROJECTED_POINTER"));

            static string IntegerError(string remap)
                => $"'NativeTypedef' storage remap '{remap}' does not preserve native width, signedness, and pointer depth.";
            static string PointerError(string remap)
                => $"'NativeTypedef' storage remap '{remap}' does not preserve native width, alignment, and pointer depth.";
            static string EnumError(string name)
                => $"Native enum projection '{name}' does not preserve native integral width and alignment.";
        }

        private static void AssertRejectedStorageBatch(string architecture, string target, string name,
            string declarations, string settings, params string[] diagnostics)
        {
            string root = Environment.GetEnvironmentVariable("WIN32_TYPEDEF_PROTOTYPE_EVIDENCE_ROOT");
            string evidence = root == null ? null : Path.Combine(root, architecture + "-" + name + "-rejections");
            if (evidence != null)
            {
                Assert.False(Directory.Exists(evidence));
                Directory.CreateDirectory(evidence);
            }
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target,
                declarations, annotationsEnabled: false, extraSettings: settings);
            try
            {
                Assert.NotEqual(0, fixture.Run());
                Assert.Equal(1, fixture.InvocationCount);
                foreach (string diagnostic in diagnostics)
                    Assert.Contains(diagnostic, fixture.Diagnostics);
            }
            finally
            {
                RetainFixture(fixture, evidence);
            }
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
                extraSettings: "-DWIN32METADATA\n--remap\n_LEGACY_MASK=LEGACY_MASK\n_LEGACY_HIGH_MASK=LEGACY_HIGH_MASK\nHANDLE=IntPtr\nRAW_HANDLE_POINTER=HANDLE*\nPADS_SEARCH_HANDLE=ADS_SEARCH_HANDLE*\nAPP_UNSIGNED_POINTER_ADDRESS=UIntPtr*\nPRECORD_BUFFER=RECORD_BUFFER*\nPROVIDED_TOKEN_t=IntPtr\nPPROVIDED_TOKEN=PROVIDED_TOKEN*\nUNTYPED_RECORD_ADDRESS=RECORD_VALUE*\nPSIBLING_COUNT=SIBLING_COUNT*\nPSIBLING_BOOLEAN=SIBLING_BOOLEAN*\nPSESSION_KEY=SESSION_KEY*\nSIBLING_HANDLE=IntPtr\nSIBLING_HANDLE__*=SIBLING_HANDLE\nPSIBLING_HANDLE=SIBLING_HANDLE*\nPROVIDED_CONTEXT_t=IntPtr\nPPROVIDED_CONTEXT=PROVIDED_CONTEXT*\nPRECORD_VIEW=RECORD_VIEW*\nPREDECLARED_BOOLEAN=REDECLARED_BOOLEAN*\nPRIMARY_RESOURCE=IntPtr\nPRIMARY_RESOURCE__*=PRIMARY_RESOURCE\nSECONDARY_RESOURCE=IntPtr\nSECONDARY_RESOURCE__*=SECONDARY_RESOURCE\nPSECONDARY_RESOURCE=SECONDARY_RESOURCE*\nOPAQUE_VALUE_KEY=long\nOPAQUE_VALUE_KEY__*=OPAQUE_VALUE_KEY\nPOPAQUE_VALUE_KEY=OPAQUE_VALUE_KEY*\nLEGACY_RESOURCE=IntPtr\nLEGACY_RESOURCE__*=LEGACY_RESOURCE\n--exclude\nPROVIDED_TOKEN_t\nPROVIDED_CONTEXT_t\nSIBLING_HANDLE__\nPRIMARY_RESOURCE__\nSECONDARY_RESOURCE__\nOPAQUE_VALUE_KEY__\nLEGACY_RESOURCE__\n");
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
                Assert.Contains("PROVIDED_TOKEN* Value", companion);
                Assert.Contains("RECORD_VALUE* Value", companion);
                var providers = new[]
                {
                    new ClangSharpSourceToWinmd.AutoType
                    {
                        Name = "PROVIDED_TOKEN",
                        Namespace = "Windows.Win32.Foundation",
                        ValueType = "typedef struct PROVIDED_TOKEN_t",
                        NativeTypedef = true,
                    },
                    new ClangSharpSourceToWinmd.AutoType
                    {
                        Name = "PROVIDED_CONTEXT",
                        Namespace = "Windows.Win32.Foundation",
                        ValueType = "typedef struct PROVIDED_CONTEXT_t",
                        NativeTypedef = true,
                    },
                    new ClangSharpSourceToWinmd.AutoType
                    {
                        Name = "SIBLING_HANDLE",
                        Namespace = "Windows.Win32.Foundation",
                        ValueType = "DECLARE_HANDLE",
                        NativeTypedef = true,
                    },
                    new ClangSharpSourceToWinmd.AutoType
                    {
                        Name = "SESSION_KEY",
                        Namespace = "Windows.Win32.Foundation",
                        ValueType = "long",
                        CloseApi = "PrototypeCloseSession",
                        InvalidHandleValues = new long[] { 0 },
                        NativeTypedef = true,
                    },
                    new ClangSharpSourceToWinmd.AutoType
                    {
                        Name = "PRIMARY_RESOURCE",
                        Namespace = "Windows.Win32.Foundation",
                        ValueType = "DECLARE_HANDLE",
                        NativeTypedef = true,
                    },
                    new ClangSharpSourceToWinmd.AutoType
                    {
                        Name = "SECONDARY_RESOURCE",
                        Namespace = "Windows.Win32.Foundation",
                        ValueType = "DECLARE_HANDLE",
                        NativeTypedef = true,
                    },
                    new ClangSharpSourceToWinmd.AutoType
                    {
                        Name = "OPAQUE_VALUE_KEY",
                        Namespace = "Windows.Win32.Foundation",
                        ValueType = "DECLARE_OPAQUE_KEY",
                        CloseApi = "PrototypeCloseOpaqueValue",
                        InvalidHandleValues = new long[] { 0 },
                        NativeTypedef = true,
                    },
                };
                var sessionProvider = providers.Single(provider => provider.Name == "SESSION_KEY");
                if (architecture == "x86" && !annotationsEnabled)
                {
                    sessionProvider.ValueType = "int";
                    AssertRejectedProvider("narrow-storage");
                    sessionProvider.ValueType = "long";
                    sessionProvider.CloseApi = null;
                    sessionProvider.InvalidHandleValues = null;
                    AssertRejectedProvider("missing-resource-contract");
                    sessionProvider.CloseApi = "PrototypeCloseSession";
                    sessionProvider.InvalidHandleValues = new long[] { 0 };
                }
                WriteProviders();
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
                AssertWrapper(reader, "BYTE_CODE", "Byte");
                AssertWrapper(reader, "SCALAR_ALIAS", "Windows.Win32.Foundation.DWORD");
                AssertWrapper(reader, "VARIANT_BOOL", "Int16");
                AssertWrapper(reader, "APP_SIGNED_POINTER_VALUE", "IntPtr");
                AssertWrapper(reader, "APP_UNSIGNED_POINTER_VALUE", "UIntPtr");
                AssertWrapper(reader, "APP_UNSIGNED_POINTER_ADDRESS", "UIntPtr*");
                AssertWrapper(reader, "EXTERNAL_COUNT_BASE", "UInt32");
                AssertWrapper(reader, "EXTERNAL_FIELD_COUNT", "Windows.Win32.Foundation.EXTERNAL_COUNT_BASE");
                AssertWrapper(reader, "EXTERNAL_HANDLE_BASE", "Void*");
                AssertWrapper(reader, "EXTERNAL_API_HANDLE", "Windows.Win32.Foundation.EXTERNAL_HANDLE_BASE");
                AssertWrapper(reader, "SELECTED_TEMPLATE_SCALAR", "Int32");
                AssertWrapper(reader, "event", "UInt32");
                AssertWrapper(reader, "PRECORD_BUFFER", "Windows.Win32.Foundation.RECORD_BUFFER*");
                AssertWrapper(reader, "PROVIDED_TOKEN", "IntPtr");
                AssertWrapper(reader, "PPROVIDED_TOKEN", "Windows.Win32.Foundation.PROVIDED_TOKEN*");
                AssertWrapper(reader, "UNTYPED_RECORD_ADDRESS", "Windows.Win32.Foundation.RECORD_VALUE*");
                AssertWrapper(reader, "SIBLING_COUNT", "Windows.Win32.Foundation.NATIVE_COUNT_BASE");
                AssertWrapper(reader, "SIBLING_BOOLEAN", "Windows.Win32.Foundation.NATIVE_BOOLEAN_BASE");
                AssertWrapper(reader, "SESSION_KEY", "Int64");
                AssertWrapper(reader, "SIBLING_HANDLE", "Void*");
                AssertWrapper(reader, "PROVIDED_CONTEXT", "IntPtr");
                AssertWrapper(reader, "REDECLARED_BOOLEAN", "Int32");
                AssertWrapper(reader, "PREDECLARED_BOOLEAN", "Windows.Win32.Foundation.REDECLARED_BOOLEAN*");
                AssertWrapper(reader, "PRIMARY_RESOURCE", "Void*");
                AssertWrapper(reader, "SECONDARY_RESOURCE", "Void*");
                AssertWrapper(reader, "OPAQUE_VALUE_KEY", "Int64");
                AssertWrapper(reader, "PSECONDARY_RESOURCE", "Windows.Win32.Foundation.SECONDARY_RESOURCE*");
                AssertWrapper(reader, "POPAQUE_VALUE_KEY", "Windows.Win32.Foundation.OPAQUE_VALUE_KEY*");
                string[] siblingPointers = { "PSIBLING_COUNT", "PSIBLING_BOOLEAN", "PSESSION_KEY",
                    "PSIBLING_HANDLE", "PPROVIDED_CONTEXT", "PRECORD_VIEW" };
                string[] siblingPointees = { "SIBLING_COUNT", "SIBLING_BOOLEAN", "SESSION_KEY",
                    "SIBLING_HANDLE", "PROVIDED_CONTEXT", "RECORD_VIEW" };
                for (int i = 0; i < siblingPointers.Length; i++)
                    AssertWrapper(reader, siblingPointers[i], "Windows.Win32.Foundation." + siblingPointees[i] + "*");
                var explicitFields = FindType(reader, "EXPLICIT_POINTER_FIELDS").GetFields().Select(reader.GetFieldDefinition).ToArray();
                Assert.Equal(new[] { "token", "record", "count", "boolean", "session", "handle", "context", "view", "repeated", "secondary", "key" },
                    explicitFields.Select(field => reader.GetString(field.Name)));
                Assert.Equal(new[] { "Windows.Win32.Foundation.PPROVIDED_TOKEN", "Windows.Win32.Foundation.UNTYPED_RECORD_ADDRESS" }
                    .Concat(siblingPointers.Select(name => "Windows.Win32.Foundation." + name))
                    .Concat(new[] { "Windows.Win32.Foundation.PREDECLARED_BOOLEAN", "Windows.Win32.Foundation.PSECONDARY_RESOURCE",
                        "Windows.Win32.Foundation.POPAQUE_VALUE_KEY" }),
                    explicitFields.Select(field => field.DecodeSignature(decoder, null)));
                foreach (string name in new[] { "byte", "LEGACY_RESOURCE" })
                    Assert.DoesNotContain(reader.TypeDefinitions, handle => reader.GetString(reader.GetTypeDefinition(handle).Name) == name);
                var primitiveMethod = FindMethod(reader, "Apis", "PrototypeUsePrimitiveAndOwnedTypes").DecodeSignature(decoder, null);
                Assert.Equal(new[] { "Byte", "Byte*", "Windows.Win32.Foundation.event", "IntPtr", "Windows.Win32.Foundation.NATIVE_SCOPED" },
                    primitiveMethod.ParameterTypes);
                var scoped = FindType(reader, "NATIVE_SCOPED");
                Assert.Equal(annotationsEnabled, scoped.GetCustomAttributes().Any(handle => AttributeName(reader, handle) == "ScopedEnumAttribute"));
                var nativeBuffer = FindType(reader, "RECORD_BUFFER");
                var bufferFields = nativeBuffer.GetFields().Select(reader.GetFieldDefinition).ToArray();
                Assert.Equal("values", reader.GetString(Assert.Single(bufferFields).Name));
                Assert.Equal("Windows.Win32.Foundation.RECORD_VALUE[]", bufferFields[0].DecodeSignature(decoder, null));
                var bufferSignature = reader.GetBlobReader(bufferFields[0].Signature);
                Assert.Equal(SignatureKind.Field, bufferSignature.ReadSignatureHeader().Kind);
                Assert.Equal(SignatureTypeCode.Array, bufferSignature.ReadSignatureTypeCode());
                Assert.Equal(SignatureTypeCode.TypeHandle, bufferSignature.ReadSignatureTypeCode());
                var element = reader.GetTypeDefinition((TypeDefinitionHandle)bufferSignature.ReadTypeHandle());
                Assert.Equal("RECORD_VALUE", reader.GetString(element.Name));
                Assert.Equal(1, bufferSignature.ReadCompressedInteger());
                Assert.Equal(1, bufferSignature.ReadCompressedInteger());
                Assert.Equal(2, bufferSignature.ReadCompressedInteger());
                Assert.Equal(1, bufferSignature.ReadCompressedInteger());
                Assert.Equal(0, bufferSignature.ReadCompressedSignedInteger());
                Assert.Equal(0, bufferSignature.RemainingBytes);
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
                foreach (string name in new[] { "LEGACY_MASK", "LEGACY_HIGH_MASK" })
                {
                    var type = FindType(reader, name);
                    AssertDoesNotHaveAttribute(reader, type.GetCustomAttributes(), "NativeTypedefAttribute");
                    Assert.Equal("Enum", reader.GetString(reader.GetTypeReference((TypeReferenceHandle)type.BaseType).Name));
                    var ordinaryEnum = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                        .OfType<EnumDeclarationSyntax>().Single(declaration => declaration.Identifier.ValueText == name);
                    string storage = ordinaryEnum.BaseList?.Types.Single().Type.ToString() == "uint" ? "UInt32" : "Int32";
                    var backing = reader.GetFieldDefinition(type.GetFields().Single(handle =>
                        reader.GetString(reader.GetFieldDefinition(handle).Name) == "value__"));
                    Assert.Equal(storage, backing.DecodeSignature(decoder, null));
                    Assert.DoesNotContain("struct " + name, companion);
                }
                var projectedEnums = FindMethod(reader, "Apis", "PrototypeUseProjectedEnums").DecodeSignature(decoder, null);
                Assert.Equal(new[] { "Windows.Win32.Foundation.LEGACY_MASK", "Windows.Win32.Foundation.LEGACY_HIGH_MASK" },
                    projectedEnums.ParameterTypes.ToArray());
                var highMember = reader.GetFieldDefinition(FindType(reader, "LEGACY_HIGH_MASK").GetFields().Single(handle =>
                    reader.GetString(reader.GetFieldDefinition(handle).Name) == "LegacyMaskHigh"));
                var highConstant = reader.GetConstant(highMember.GetDefaultValue());
                Assert.Equal(ConstantTypeCode.Int32, highConstant.TypeCode);
                Assert.Equal("00000080", Convert.ToHexString(reader.GetBlobBytes(highConstant.Value)));
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
                var mappedPointers = FindMethod(reader, "Apis", "PrototypeUseMappedPointerAliases").DecodeSignature(decoder, null);
                Assert.Equal(new[]
                {
                    "Windows.Win32.Networking.ActiveDirectory.RAW_HANDLE_POINTER",
                    "Windows.Win32.Networking.ActiveDirectory.PADS_SEARCH_HANDLE",
                    "Windows.Win32.Foundation.APP_UNSIGNED_POINTER_ADDRESS",
                }, mappedPointers.ParameterTypes);
                var explicitPointers = FindMethod(reader, "Apis", "PrototypeUseExplicitPointerViews").DecodeSignature(decoder, null);
                Assert.Equal(new[] { "Windows.Win32.Foundation.PPROVIDED_TOKEN", "Windows.Win32.Foundation.UNTYPED_RECORD_ADDRESS" },
                    explicitPointers.ParameterTypes);
                var siblingMethod = FindMethod(reader, "Apis", "PrototypeUseSiblingPointers").DecodeSignature(decoder, null);
                Assert.Equal(siblingPointers.Select(name => "Windows.Win32.Foundation." + name), siblingMethod.ParameterTypes);
                var alternateMethod = FindMethod(reader, "Apis", "PrototypeUseAlternateOwners").DecodeSignature(decoder, null);
                Assert.Equal(new[] { "Windows.Win32.Foundation.PREDECLARED_BOOLEAN", "Windows.Win32.Foundation.PSECONDARY_RESOURCE",
                    "Windows.Win32.Foundation.POPAQUE_VALUE_KEY",
                    "Windows.Win32.Foundation.OPAQUE_VALUE_KEY" }, alternateMethod.ParameterTypes);
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
                foreach (var expected in new[]
                {
                    (Name: "LOWER_MARKER", Type: "BYTE_CODE", Code: ConstantTypeCode.Byte, Bits: "6C"),
                    (Name: "UPPER_MARKER", Type: "BYTE_CODE", Code: ConstantTypeCode.Byte, Bits: "42"),
                    (Name: "UNSIGNED_STATUS_UNAVAILABLE", Type: "DWORD", Code: ConstantTypeCode.UInt32, Bits: "FFFFFFFF"),
                })
                {
                    var field = FindType(reader, "Apis").GetFields().Select(reader.GetFieldDefinition)
                        .Single(value => reader.GetString(value.Name) == expected.Name);
                    Assert.Equal("Windows.Win32.Foundation." + expected.Type, field.DecodeSignature(decoder, null));
                    var constant = reader.GetConstant(field.GetDefaultValue());
                    Assert.Equal(expected.Code, constant.TypeCode);
                    Assert.Equal(expected.Bits, Convert.ToHexString(reader.GetBlobBytes(constant.Value)));
                }
                AssertMetadataClosure(reader);

                void WriteProviders()
                {
                    using var provider = File.Create(Path.Combine(fixture.DirectoryPath, "autotypes.cs"));
                    ClangSharpSourceToWinmd.NativeTypedefStructsCreator.WriteToStream(
                        new Dictionary<string, string>
                        {
                            ["PrototypeCloseSession"] = "Windows.Win32.Foundation",
                            ["PrototypeCloseOpaqueValue"] = "Windows.Win32.Foundation",
                        },
                        providers, provider);
                }

                void AssertRejectedProvider(string label)
                {
                    WriteProviders();
                    var error = Assert.Throws<InvalidDataException>(() =>
                    {
                        using var rejected = Emit(fixture.DirectoryPath, architecture, requiredNamespaces: Routing,
                            winmdFileName: "Rejected.winmd");
                    });
                    Assert.Contains("Conflicting native typedef Value storage types.", error.Message);
                    Assert.False(File.Exists(Path.Combine(fixture.DirectoryPath, "Rejected.winmd")));
                    if (evidence != null)
                    {
                        File.Copy(Path.Combine(fixture.DirectoryPath, "autotypes.cs"),
                            Path.Combine(evidence, label + ".cs.txt"));
                        File.WriteAllText(Path.Combine(evidence, label + ".diagnostics.txt"), error.Message);
                    }
                }
            }
            finally
            {
                RetainFixture(fixture, evidence);
            }
        }

        private static void RetainFixture(HeaderAnnotationTests.NativeFixture fixture, string evidence)
        {
            if (evidence == null)
                return;
            File.WriteAllText(Path.Combine(evidence, "scraper.stdout-stderr.log"), fixture.Diagnostics ?? "");
            foreach (string file in Directory.EnumerateFiles(fixture.DirectoryPath, "*", SearchOption.AllDirectories))
            {
                string destination = Path.Combine(evidence, "fixture", Path.GetRelativePath(fixture.DirectoryPath, file));
                Directory.CreateDirectory(Path.GetDirectoryName(destination));
                File.Copy(file, destination, overwrite: false);
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

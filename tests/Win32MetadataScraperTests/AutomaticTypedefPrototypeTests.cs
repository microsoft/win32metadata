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
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Win32MetadataScraper;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    public class AutomaticTypedefPrototypeTests : HeaderAnnotationWinmdTests
    {
        private readonly ITestOutputHelper output;

        public AutomaticTypedefPrototypeTests(ITestOutputHelper output) => this.output = output;

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

        private const string InferredProjectionDeclarations = @"
#ifndef WIN32METADATA
#define WIN32METADATA
#endif
#include <win32metadata_annotations.h>
typedef unsigned long FIRST_COUNT;
typedef FIRST_COUNT SECOND_COUNT;
typedef SECOND_COUNT* PSECOND_COUNT;
typedef float SCALAR_FLOAT;
typedef unsigned long CONFIGURED_COUNT;
typedef _Win32_AlsoUsableFor_(CONFIGURED_COUNT) unsigned long AUTHORED_COUNT;
struct ROW {
    FIRST_COUNT first;
    SECOND_COUNT second;
    PSECOND_COUNT values;
    SCALAR_FLOAT factor;
    CONFIGURED_COUNT configured;
    AUTHORED_COUNT authored;
};
extern ""C"" SECOND_COUNT Echo(SECOND_COUNT value, SCALAR_FLOAT factor, PSECOND_COUNT values);
";

        private static void InferredIdentityPreservesOrdinaryClrProjectionAndExplicitNominalIntent(
            HeaderAnnotationTests.NativeFixture fixture, MetadataReader reader, bool annotationsEnabled)
        {
            var providers = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>().ToArray();
            var identities = new HashSet<string>(StringComparer.Ordinal);
            foreach (string name in new[] { "FIRST_COUNT", "SECOND_COUNT", "PSECOND_COUNT", "SCALAR_FLOAT" })
            {
                var provider = providers.Single(type => type.Identifier.ValueText == name);
                var source = NativeTypedefSourceProvenance.Read(provider);
                Assert.NotNull(source);
                Assert.True(identities.Add(source.Identity));
                Assert.True(NativeTypedefProjectionProvenance.IsInferred(provider));
            }
            Assert.False(NativeTypedefProjectionProvenance.IsInferred(providers.Single(type =>
                type.Identifier.ValueText == "CONFIGURED_COUNT")));
            Assert.Equal(!annotationsEnabled, NativeTypedefProjectionProvenance.IsInferred(providers.Single(type =>
                type.Identifier.ValueText == "AUTHORED_COUNT")));
            var secondStorage = Assert.Single(providers.Single(type =>
                type.Identifier.ValueText == "SECOND_COUNT").Members.OfType<FieldDeclarationSyntax>());
            Assert.Equal("FIRST_COUNT", secondStorage.Declaration.Type.ToString());
            var decoder = new SignatureNames(qualifiedNames: true);
            var row = FindType(reader, "ROW");
            Assert.Equal(new[] { "UInt32", "UInt32", "UInt32*", "Single", "Windows.Win32.Foundation.CONFIGURED_COUNT",
                annotationsEnabled ? "Windows.Win32.Foundation.AUTHORED_COUNT" : "UInt32" },
                row.GetFields().Select(handle => reader.GetFieldDefinition(handle).DecodeSignature(decoder, null)));
            var method = FindMethod(reader, "Apis", "Echo").DecodeSignature(decoder, null);
            Assert.Equal("UInt32", method.ReturnType);
            Assert.Equal(new[] { "UInt32", "Single", "UInt32*" }, method.ParameterTypes);
            foreach (string name in new[] { "FIRST_COUNT", "SECOND_COUNT", "PSECOND_COUNT", "SCALAR_FLOAT" })
                Assert.DoesNotContain(reader.TypeDefinitions, handle =>
                    reader.GetString(reader.GetTypeDefinition(handle).Name) == name);
            AssertWrapper(reader, "CONFIGURED_COUNT", "UInt32");
            if (annotationsEnabled)
                AssertWrapper(reader, "AUTHORED_COUNT", "UInt32");
            AssertMetadataClosure(reader);
        }

        [Fact]
        public void UnannotatedAliasesEmitAndUseExistingNamespaceRouting()
        {
            RunCase("x64", "x86_64-pc-windows-msvc", annotationsEnabled: false);
            RunCase("x86", "i686-pc-windows-msvc", annotationsEnabled: false);
            RunCase("arm64", "aarch64-pc-windows-msvc", annotationsEnabled: false);
            RunCase("x64", "x86_64-pc-windows-msvc", annotationsEnabled: true);
            RunCase("x86", "i686-pc-windows-msvc", annotationsEnabled: true);
            RunCase("arm64", "aarch64-pc-windows-msvc", annotationsEnabled: true);
            AssertFixedWidthPointerStorage("x64", "x86_64-pc-windows-msvc", "__ptr32", 4, 8);
            AssertFixedWidthPointerStorage("x86", "i686-pc-windows-msvc", "__ptr64", 8, 4);
            AssertEnumProjectionStorage();
            AssertInvalidStorageBatches();

            RunControl(nameof(NativeRecordTraversalRequiresAnExplicitMatchingFile),
                NativeRecordTraversalRequiresAnExplicitMatchingFile);
            foreach (var (architecture, target, observedArchitecture) in new[]
            {
                ("x86", "i686-pc-windows-msvc", MetadataUtils.Architecture.X86),
                ("x64", "x86_64-pc-windows-msvc", MetadataUtils.Architecture.X64),
                ("arm64", "aarch64-pc-windows-msvc", MetadataUtils.Architecture.Arm64),
            })
            {
                RunControl($"{nameof(NativeRecordOnlyTraversalRetainsItsCanonicalSourceIdentity)}:{architecture}",
                    () => NativeRecordOnlyTraversalRetainsItsCanonicalSourceIdentity(architecture, target, observedArchitecture));
                RunControl($"{nameof(AutomaticInitializationDoesNotChangeTheNativeOrMetadataContract)}:{architecture}",
                    () => AutomaticInitializationDoesNotChangeTheNativeOrMetadataContract(architecture, target));
                RunControl($"{nameof(RequiredNativeAlignmentIsSeparateFromPacking)}:{architecture}",
                    () => RequiredNativeAlignmentIsSeparateFromPacking(architecture, target));
                RunControl($"{nameof(ReferencedAnonymousRecordsDiscoverTheirNestedScalarTypedefs)}:{architecture}",
                    () => ReferencedAnonymousRecordsDiscoverTheirNestedScalarTypedefs(architecture, target));
                foreach (bool mapped in new[] { true, false })
                    RunControl($"{nameof(ExcludedRecordPointersRetainConfiguredExternalProjection)}:{architecture}:{mapped}",
                        () => ExcludedRecordPointersRetainConfiguredExternalProjection(architecture, target, mapped));
                RunControl($"{nameof(AutomaticTagNamesDoNotInventExternalProvidersForExcludedRecords)}:{architecture}",
                    () => AutomaticTagNamesDoNotInventExternalProvidersForExcludedRecords(architecture, target));
                RunControl($"{nameof(ComPointerAliasesPreserveOrdinaryExternalProjection)}:{architecture}",
                    () => ComPointerAliasesPreserveOrdinaryExternalProjection(architecture, target));
            }
            foreach (var (query, addRef, release, derived) in new[]
            {
                ("__cdecl", "__cdecl", "__cdecl", false),
                ("__cdecl", "__stdcall", "__stdcall", false),
                ("__stdcall", "__cdecl", "__stdcall", false),
                ("__stdcall", "__stdcall", "__cdecl", false),
                ("__stdcall", "__stdcall", "__stdcall", true),
            })
                RunControl($"{nameof(NonComCallingConventionsRetainNativePointerAliases)}:{query}:{addRef}:{release}:{derived}",
                    () => NonComCallingConventionsRetainNativePointerAliases(query, addRef, release, derived));
            foreach (string declaration in new[]
            {
                "struct __declspec(uuid(\"00000000-0000-0000-c000-000000000046\")) Record { int value; };",
                "struct __declspec(uuid(\"00000000-0000-0000-c000-000000000046\")) Record { virtual int Read() = 0; };",
            })
                RunControl($"{nameof(UuidAndVirtualMethodsAloneDoNotEraseNativePointerAliases)}:{declaration}",
                    () => UuidAndVirtualMethodsAloneDoNotEraseNativePointerAliases(declaration));
            foreach (bool bare in new[] { false, true })
                RunControl($"{nameof(InferredScalarContextsComposeRealPartitionObservationsThroughTheOriginalEmitter)}:{bare}",
                    () => InferredScalarContextsComposeRealPartitionObservationsThroughTheOriginalEmitter(bare));

            void RunControl(string name, Action control)
            {
                this.output.WriteLine("Native typedef control: " + name);
                control();
            }
        }

        private static void NativeRecordTraversalRequiresAnExplicitMatchingFile()
        {
            string header = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString("N"), "shared-aliases.h");
            Assert.True(HeaderAnnotationProcessor.MatchesTraversalFile(new[] { header }, header));
            Assert.True(HeaderAnnotationProcessor.MatchesTraversalFile(new[] { "SHARED-ALIASES.H" }, header));
            Assert.False(HeaderAnnotationProcessor.MatchesTraversalFile(Array.Empty<string>(), header));
            Assert.False(HeaderAnnotationProcessor.MatchesTraversalFile(new[] { "other.h" }, header));
            Assert.False(HeaderAnnotationProcessor.MatchesTraversalFile(
                new[] { Path.Combine("other", "shared-aliases.h") }, header));
        }

        private static void NativeRecordOnlyTraversalRetainsItsCanonicalSourceIdentity(string architecture, string triple,
            MetadataUtils.Architecture observedArchitecture)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, triple, @"
struct RECORD_ONLY { unsigned long Value; };
extern ""C"" void UseRecord(RECORD_ONLY* value);
", annotationsEnabled: false);
            fixture.AssertSuccess();
            Assert.DoesNotContain("NativeTypedef", fixture.ReadAdditionalTypes());
            var record = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<StructDeclarationSyntax>().Single(declaration => declaration.Identifier.ValueText == "RECORD_ONLY");
            var source = NativeRecordSourceProvenance.Read(record);
            Assert.NotNull(source);
            Assert.True(source.TraversedHeader);
            Assert.Equal(fixture.Header, source.Header);
            Assert.Equal("RECORD_ONLY", source.NativeName);
            Assert.Equal("Test", source.Namespace);
            Assert.Equal(observedArchitecture, source.SourceArchitecture);
            Assert.Equal(4L, source.Size);
            Assert.Equal(4L, source.Alignment);
        }

        private static void ReferencedAnonymousRecordsDiscoverTheirNestedScalarTypedefs(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#include ""dependency.h""
extern ""C"" void GetInfo(PINFO info);
", annotationsEnabled: false, extraSettings: "--remap\nNATIVE_FIELD_BITS=NATIVE_FIELD_BITS\n");
            string dependency = Path.Combine(fixture.DirectoryPath, "dependency.h");
            File.WriteAllText(dependency, @"
typedef unsigned long long NATIVE_FIELD_BITS;
typedef struct _INFO {
    union {
        struct { NATIVE_FIELD_BITS AllocationTag; };
    };
} INFO, *PINFO;
");
            fixture.AssertSuccess();
            var alias = Assert.Single(CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>().Where(type =>
                    type.Identifier.ValueText == "NATIVE_FIELD_BITS"));
            var proof = NativeTypedefSourceProvenance.Read(alias);
            Assert.NotNull(proof);
            Assert.Equal(dependency, proof.Header);
            Assert.Equal("NATIVE_FIELD_BITS", proof.NativeName);
            Assert.Equal(8, proof.Size);
            var field = Assert.Single(CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot()
                .DescendantNodes().OfType<FieldDeclarationSyntax>().Where(declaration =>
                    declaration.Declaration.Variables.Any(variable => variable.Identifier.ValueText == "AllocationTag")));
            Assert.Equal("NATIVE_FIELD_BITS", field.Declaration.Type.ToString());
            File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"),
                Path.Combine(fixture.DirectoryPath, "Metadata.manual.cs"));
            var compilation = ClangSharpSourceCompilation.Create(fixture.DirectoryPath, architecture,
                new(), new(), Array.Empty<string>(), new(), new(), new(), Array.Empty<string>(), new(), new());
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string imagePath = Path.Combine(fixture.DirectoryPath, "AnonymousRecordAliases.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), imagePath);
            Assert.True(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var image = new MetadataImage(imagePath);
            var reader = image.Reader;
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Namespace) == "Test" && reader.GetString(type.Name) == "NATIVE_FIELD_BITS");
            Assert.Equal("UInt64", reader.GetFieldDefinition(physical.GetFields().Single())
                .DecodeSignature(new SignatureNames(qualifiedNames: true), null));
            var nativeField = reader.TypeDefinitions.SelectMany(handle => reader.GetTypeDefinition(handle).GetFields())
                .Select(reader.GetFieldDefinition).Single(value => reader.GetString(value.Name) == "AllocationTag");
            Assert.Equal("Test.NATIVE_FIELD_BITS", nativeField.DecodeSignature(new SignatureNames(qualifiedNames: true), null));
            AssertMetadataClosure(reader);
        }

        private static void AutomaticInitializationDoesNotChangeTheNativeOrMetadataContract(string architecture, string target)
        {
            string settings = Path.Combine(AppContext.BaseDirectory, "assets", "scraper", "baseSettings.rsp");
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#ifndef DECLSPEC_NOINITALL
#define DECLSPEC_NOINITALL __declspec(no_init_all)
#endif
struct DECLSPEC_NOINITALL NOINIT_RECORD { unsigned long code; void* data; };
typedef NOINIT_RECORD* PNOINIT_RECORD;
extern ""C"" void UseNoInit(PNOINIT_RECORD value);
", annotationsEnabled: false, extraSettings: "@" + settings);
            Assert.Equal(NativeSurface(fixture, target, metadataEnabled: false),
                NativeSurface(fixture, target, metadataEnabled: false,
                    additionalArguments: new[] { "-DDECLSPEC_NOINITALL=" }));
            fixture.AssertSuccess();
            var record = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<StructDeclarationSyntax>().Single(declaration => declaration.Identifier.ValueText == "NOINIT_RECORD");
            var source = NativeRecordSourceProvenance.Read(record);
            Assert.NotNull(source);
            Assert.Equal(architecture == "x86" ? 8L : 16L, source.Size);
            Assert.Equal(architecture == "x86" ? 4L : 8L, source.Alignment);
            using var image = Emit(fixture, architecture);
            var physical = FindType(image.Reader, "NOINIT_RECORD");
            Assert.Equal(new[] { "UInt32", "Void*" }, physical.GetFields().Select(handle =>
                image.Reader.GetFieldDefinition(handle).DecodeSignature(new SignatureNames(), null)));
            AssertMetadataClosure(image.Reader);
        }

        private static void RequiredNativeAlignmentIsSeparateFromPacking(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
struct __declspec(align(16)) ALIGNED_RECORD { unsigned long long lower; long long upper; };
struct ALIGNMENT_CONTAINER { unsigned char prefix; ALIGNED_RECORD payload; unsigned char tail; };
struct ORDINARY_RECORD { unsigned long long lower; long long upper; };
struct MEMBER_ALIGNED_RECORD { unsigned char prefix; __declspec(align(16)) unsigned long long value; };
#pragma pack(push, 4)
struct PACKED_RECORD { unsigned char prefix; unsigned long long value; };
#pragma pack(pop)
extern ""C"" ALIGNED_RECORD UseAligned(ALIGNED_RECORD value, ALIGNMENT_CONTAINER* container);
", annotationsEnabled: false);
            Assert.Equal(0, fixture.Run());
            Assert.Contains("requests 16 byte alignment which .NET cannot honor", fixture.Diagnostics);
            Assert.Contains("is carried by AlignmentAttribute(16)", fixture.Diagnostics);
            var native = NativeSurface(fixture, target, metadataEnabled: false);
            Assert.Contains("record ALIGNED_RECORD 16 16", native);
            Assert.Contains("record ALIGNMENT_CONTAINER 48 16", native);
            Assert.Contains("record ORDINARY_RECORD 16 8", native);
            Assert.Contains("record MEMBER_ALIGNED_RECORD 32 16", native);
            Assert.Contains("record PACKED_RECORD 12 4", native);
            Assert.Contains("field payload ALIGNED_RECORD 128", native);
            Assert.Contains("field tail unsigned char 256", native);
            var declaration = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<StructDeclarationSyntax>().Single(type => type.Identifier.ValueText == "ALIGNED_RECORD");
            var source = NativeRecordSourceProvenance.Read(declaration);
            Assert.NotNull(source);
            Assert.True(HeaderAnnotationProcessor.HasNativeAlignmentProjection(declaration, source, 16));
            Assert.False(HeaderAnnotationProcessor.HasNativeAlignmentProjection(declaration, source, 8));
            Assert.False(HeaderAnnotationProcessor.HasNativeAlignmentProjection(declaration, source with { Identity = "other" }, 16));
            Assert.False(HeaderAnnotationProcessor.HasNativeAlignmentProjection(declaration, source with { Size = 32 }, 16));
            Assert.False(HeaderAnnotationProcessor.HasNativeAlignmentProjection(declaration.WithAttributeLists(default), source, 16));
            using var image = Emit(fixture, architecture);
            var aligned = FindType(image.Reader, "ALIGNED_RECORD");
            var attributes = aligned.GetCustomAttributes().Where(handle =>
                AttributeName(image.Reader, handle) == "AlignmentAttribute");
            var blob = image.Reader.GetBlobReader(image.Reader.GetCustomAttribute(Assert.Single(attributes)).Value);
            Assert.Equal(1, blob.ReadUInt16());
            Assert.Equal(16, blob.ReadInt32());
            Assert.Equal(0, blob.ReadUInt16());
            Assert.Equal(0, blob.RemainingBytes);
            Assert.Equal(0, aligned.GetLayout().PackingSize);
            Assert.Equal(new[] { "UInt64", "Int64" }, aligned.GetFields().Select(handle =>
                image.Reader.GetFieldDefinition(handle).DecodeSignature(new SignatureNames(), null)));
            var container = FindType(image.Reader, "ALIGNMENT_CONTAINER");
            Assert.Equal(new[] { "Byte", "Test.ALIGNED_RECORD", "Byte" }, container.GetFields().Select(handle =>
                image.Reader.GetFieldDefinition(handle).DecodeSignature(new SignatureNames(qualifiedNames: true), null)));
            AssertDoesNotHaveAttribute(image.Reader, container.GetCustomAttributes(), "AlignmentAttribute");
            AssertDoesNotHaveAttribute(image.Reader, FindType(image.Reader, "ORDINARY_RECORD").GetCustomAttributes(), "AlignmentAttribute");
            var packed = FindType(image.Reader, "PACKED_RECORD");
            Assert.Equal(4, packed.GetLayout().PackingSize);
            AssertDoesNotHaveAttribute(image.Reader, packed.GetCustomAttributes(), "AlignmentAttribute");
            var memberAligned = FindType(image.Reader, "MEMBER_ALIGNED_RECORD");
            AssertDoesNotHaveAttribute(image.Reader, memberAligned.GetCustomAttributes(), "AlignmentAttribute");
            var alignedMember = memberAligned.GetFields().Select(image.Reader.GetFieldDefinition)
                .Single(field => image.Reader.GetString(field.Name) == "value");
            var memberBlob = image.Reader.GetBlobReader(image.Reader.GetCustomAttribute(
                Assert.Single(alignedMember.GetCustomAttributes().Where(handle =>
                    AttributeName(image.Reader, handle) == "AlignmentAttribute"))).Value);
            Assert.Equal(1, memberBlob.ReadUInt16());
            Assert.Equal(16, memberBlob.ReadInt32());
            Assert.Equal(0, memberBlob.ReadUInt16());
            Assert.Equal(0, memberBlob.RemainingBytes);
            Assert.Equal("Test.ALIGNED_RECORD", FindMethod(image.Reader, "Apis", "UseAligned")
                .DecodeSignature(new SignatureNames(qualifiedNames: true), null).ReturnType);
            AssertMetadataClosure(image.Reader);
            AssertLayout("ALIGNED_RECORD", 16, 16, 0, 8);
            AssertLayout("ALIGNMENT_CONTAINER", 48, 16, 0, 16, 32);
            AssertLayout("MEMBER_ALIGNED_RECORD", 32, 16, 0, 16);
            AssertLayout("ORDINARY_RECORD", 16, 8, 0, 8);
            AssertLayout("PACKED_RECORD", 12, 4, 0, 4);
            if (architecture == "x86")
            {
                using var unsupported = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
struct __declspec(align(16)) ALIGNED_RECORD { unsigned long long lower; long long upper; };
struct __declspec(no_init_all) UNREPRESENTED_ATTRIBUTE { int value; };
", annotationsEnabled: false);
                Assert.Equal(1, unsupported.Run());
                Assert.Contains("is carried by AlignmentAttribute(16)", unsupported.Diagnostics);
                Assert.Contains("Unsupported attribute: 'NoTrivialAutoVarInit'", unsupported.Diagnostics);
            }

            void AssertLayout(string name, int size, int alignment, params int[] offsets)
            {
                var layout = ReadLayout("Test." + name);
                Assert.Equal(size, layout.Size);
                Assert.Equal(alignment, layout.Alignment);
                Assert.Equal(offsets, layout.Offsets);
            }

            (int Size, int Alignment, int Required, int[] Offsets) ReadLayout(string name)
            {
                if (name == "Byte")
                    return (1, 1, 0, Array.Empty<int>());
                if (name is "UInt64" or "Int64")
                    return (8, 8, 0, Array.Empty<int>());
                var type = image.Reader.TypeDefinitions.Select(image.Reader.GetTypeDefinition).Single(candidate =>
                    image.Reader.GetString(candidate.Namespace) + "." + image.Reader.GetString(candidate.Name) == name);
                Assert.Equal(TypeAttributes.SequentialLayout, type.Attributes & TypeAttributes.LayoutMask);
                var layout = type.GetLayout();
                int pack = layout.PackingSize == 0 ? 8 : layout.PackingSize;
                int size = 0, alignment = 1, required = ReadAlignment(type.GetCustomAttributes());
                var offsets = new List<int>();
                foreach (var handle in type.GetFields())
                {
                    var field = image.Reader.GetFieldDefinition(handle);
                    var value = ReadLayout(field.DecodeSignature(new SignatureNames(qualifiedNames: true), null));
                    int fieldRequired = Math.Max(value.Required, ReadAlignment(field.GetCustomAttributes()));
                    int fieldAlignment = Math.Max(Math.Min(pack, value.Alignment), fieldRequired);
                    int offset = Align(size, fieldAlignment);
                    offsets.Add(offset);
                    size = checked(offset + value.Size);
                    alignment = Math.Max(alignment, fieldAlignment);
                    required = Math.Max(required, fieldRequired);
                }
                alignment = Math.Max(alignment, required);
                return (Align(Math.Max(Math.Max(size, layout.Size), 1), alignment), alignment, required, offsets.ToArray());
            }

            int ReadAlignment(CustomAttributeHandleCollection attributes)
            {
                var matching = attributes.Where(handle => AttributeName(image.Reader, handle) == "AlignmentAttribute").ToArray();
                if (matching.Length == 0)
                    return 0;
                var value = image.Reader.GetBlobReader(image.Reader.GetCustomAttribute(Assert.Single(matching)).Value);
                Assert.Equal(1, value.ReadUInt16());
                int alignment = value.ReadInt32();
                Assert.True(alignment > 0 && (alignment & (alignment - 1)) == 0);
                Assert.Equal(0, value.ReadUInt16());
                Assert.Equal(0, value.RemainingBytes);
                return alignment;
            }

            static int Align(int value, int alignment) => checked((value + alignment - 1) / alignment * alignment);
        }

        private static void ExcludedRecordPointersRetainConfiguredExternalProjection(string architecture, string target, bool mapped)
        {
            string declarations = mapped ? @"
struct _GUID { unsigned long first; unsigned short second, third; unsigned char fourth[8]; };
typedef _GUID GUID;
typedef GUID IID;
typedef GUID CLSID;
typedef GUID* LPGUID;
typedef IID* LPIID;
typedef CLSID* LPCLSID;
extern ""C"" void UseIdentifiers(LPGUID guid, LPIID iid, LPCLSID clsid);
" : @"
struct UNMAPPED_RECORD { unsigned long first; unsigned short second, third; unsigned char fourth[8]; };
typedef UNMAPPED_RECORD* LPGUID;
typedef UNMAPPED_RECORD* LPIID;
typedef UNMAPPED_RECORD* LPCLSID;
extern ""C"" void UseIdentifiers(LPGUID guid, LPIID iid, LPCLSID clsid);
";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                annotationsEnabled: false, extraSettings: (mapped ? "--exclude\n_GUID\n--remap\n_GUID=Guid\n" :
                    "--exclude\nUNMAPPED_RECORD\n") +
                    "--remap\nLPGUID=LPGUID\nLPIID=LPIID\nLPCLSID=LPCLSID\n");
            fixture.AssertSuccess();
            var aliases = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>().ToArray();
            foreach (string name in new[] { "LPGUID", "LPIID", "LPCLSID" })
            {
                var alias = Assert.Single(aliases.Where(type => type.Identifier.ValueText == name));
                Assert.Equal(mapped ? "Guid*" : "void*",
                    Assert.Single(alias.Members.OfType<FieldDeclarationSyntax>()).Declaration.Type.ToString());
                var proof = NativeTypedefSourceProvenance.Read(alias);
                Assert.NotNull(proof);
                Assert.Equal(name, proof.NativeName);
                Assert.Equal(fixture.Header, proof.Header);
                Assert.Equal(architecture == "x86" ? 4L : 8L, proof.Size);
                Assert.Equal(proof.Size, proof.Alignment);
            }
            File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"),
                Path.Combine(fixture.DirectoryPath, "Metadata.manual.cs"));
            var compilation = ClangSharpSourceCompilation.Create(fixture.DirectoryPath, architecture,
                new(), new(), Array.Empty<string>(), new(), new(), new(), Array.Empty<string>(), new(), new());
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            foreach (string name in new[] { "LPGUID", "LPIID", "LPCLSID" })
            {
                var value = compilation.CSharpCompilation.GetTypeByMetadataName("Test." + name)
                    .GetMembers("Value").OfType<IFieldSymbol>().Single();
                var pointer = Assert.IsAssignableFrom<IPointerTypeSymbol>(value.Type);
                Assert.Equal(mapped ? "System.Guid" : "void", pointer.PointedAtType.ToDisplayString());
            }
            string path = Path.Combine(fixture.DirectoryPath, "ExternalRecordPointers.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), path);
            Assert.True(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var image = new MetadataImage(path);
            var reader = image.Reader;
            foreach (string name in new[] { "LPGUID", "LPIID", "LPCLSID" })
            {
                var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Single(type => reader.GetString(type.Namespace) == "Test" && reader.GetString(type.Name) == name);
                var field = reader.GetFieldDefinition(type.GetFields().Single());
                Assert.Equal(mapped ? "System.Guid*" : "Void*",
                    field.DecodeSignature(new SignatureNames(qualifiedNames: true), null));
            }
            Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                type => reader.GetString(type.Name) is "_GUID" or "GUID" or "IID" or "CLSID" or "Guid" or "UNMAPPED_RECORD");
            AssertMetadataClosure(reader);
        }

        private static void AutomaticTagNamesDoNotInventExternalProvidersForExcludedRecords(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
struct _EXCLUDED_RECORD { unsigned long value; };
typedef _EXCLUDED_RECORD EXCLUDED_RECORD;
typedef EXCLUDED_RECORD* PEXCLUDED_RECORD;
typedef struct _EXCLUDED_INLINE_RECORD { unsigned long value; } EXCLUDED_INLINE_RECORD, *PEXCLUDED_INLINE_RECORD;
extern ""C"" void UseExcluded(PEXCLUDED_RECORD first, PEXCLUDED_INLINE_RECORD second);
", annotationsEnabled: false, extraSettings: "--exclude\n_EXCLUDED_RECORD\n_EXCLUDED_INLINE_RECORD\n" +
                "--remap\nPEXCLUDED_RECORD=PEXCLUDED_RECORD\nPEXCLUDED_INLINE_RECORD=PEXCLUDED_INLINE_RECORD\n");
            fixture.AssertSuccess();
            var aliases = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>().ToArray();
            foreach (string name in new[] { "PEXCLUDED_RECORD", "PEXCLUDED_INLINE_RECORD" })
            {
                var alias = Assert.Single(aliases.Where(type => type.Identifier.ValueText == name));
                Assert.Equal("void*", Assert.Single(alias.Members.OfType<FieldDeclarationSyntax>())
                    .Declaration.Type.ToString());
                var source = NativeTypedefSourceProvenance.Read(alias);
                Assert.NotNull(source);
                Assert.Equal(name, source.NativeName);
                Assert.Equal(fixture.Header, source.Header);
                Assert.Equal(architecture == "x86" ? 4L : 8L, source.Size);
                Assert.Equal(source.Size, source.Alignment);
            }
            File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"),
                Path.Combine(fixture.DirectoryPath, "Metadata.manual.cs"));
            var compilation = ClangSharpSourceCompilation.Create(fixture.DirectoryPath, architecture,
                new(), new(), Array.Empty<string>(), new(), new(), new(), Array.Empty<string>(), new(), new());
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string path = Path.Combine(fixture.DirectoryPath, "ExcludedRecordAliases.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), path);
            Assert.True(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var image = new MetadataImage(path);
            var reader = image.Reader;
            foreach (string name in new[] { "PEXCLUDED_RECORD", "PEXCLUDED_INLINE_RECORD" })
            {
                var alias = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Single(type => reader.GetString(type.Namespace) == "Test" && reader.GetString(type.Name) == name);
                Assert.Equal("Void*", reader.GetFieldDefinition(alias.GetFields().Single())
                    .DecodeSignature(new SignatureNames(qualifiedNames: true), null));
            }
            Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                type => reader.GetString(type.Name) is "_EXCLUDED_RECORD" or "EXCLUDED_RECORD" or
                    "_EXCLUDED_INLINE_RECORD" or "EXCLUDED_INLINE_RECORD");
            AssertMetadataClosure(reader);
        }

        private static void ComPointerAliasesPreserveOrdinaryExternalProjection(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#include ""external.h""
typedef long HRESULT;
typedef External::IController* PCONTROLLER;
typedef PCONTROLLER CONTROLLER_ALIAS;
typedef CONTROLLER_ALIAS* PPCONTROLLER;
extern ""C"" HRESULT CreateController(PPCONTROLLER result);
", annotationsEnabled: false);
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "external.h"), @"
struct IID { unsigned long first; unsigned short second, third; unsigned char fourth[8]; };
struct __declspec(uuid(""00000000-0000-0000-c000-000000000046"")) Unknown
{
    virtual long __stdcall QueryInterface(const IID& iid, void** result) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
namespace External
{
    struct UnneededDependency;
    struct __declspec(uuid(""22f34e66-50db-4e36-a98d-61c01b384d20"")) IController : Unknown
    {
        virtual long __stdcall UnneededMethod(UnneededDependency** result) = 0;
    };
}
");
            fixture.AssertSuccess();
            var source = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot();
            Assert.Empty(source.DescendantNodes().OfType<StructDeclarationSyntax>());
            var method = Assert.Single(source.DescendantNodes().OfType<MethodDeclarationSyntax>());
            Assert.Equal("IController**", Assert.Single(method.ParameterList.Parameters).Type.ToString());
            var additional = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>().Select(type => type.Identifier.ValueText).ToArray();
            Assert.Equal(new[] { "HRESULT" }, additional);
            File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"),
                Path.Combine(fixture.DirectoryPath, "Metadata.manual.cs"));
            var imports = new Dictionary<string, string>
            {
                ["IController(interface)"] = "<Windows.Foundation.UniversalApiContract, Version=10.0.0.0, Culture=neutral, PublicKeyToken=null>Windows.System.DispatcherQueueController",
            };
            var compilation = ClangSharpSourceCompilation.Create(fixture.DirectoryPath, architecture,
                new(), new(), Array.Empty<string>(), imports, new(), new(), Array.Empty<string>(), new(), new());
            var compilerErrors = compilation.CSharpCompilation.GetDeclarationDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.All(compilerErrors, diagnostic => Assert.Contains(diagnostic.Id, new[] { "CS0246", "CS0208" }));
            var importedError = Assert.Single(compilerErrors.Where(diagnostic => diagnostic.Id == "CS0246"));
            Assert.Contains("'IController'", importedError.GetMessage());
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string path = Path.Combine(fixture.DirectoryPath, "ExternalController.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, imports, new(), new(), new Version(1, 0), path);
            Assert.True(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var image = new MetadataImage(path);
            var reader = image.Reader;
            var physical = FindMethod(reader, "Apis", "CreateController")
                .DecodeSignature(new SignatureNames(qualifiedNames: true), null);
            Assert.Equal(new[] { "Windows.System.DispatcherQueueController*" }, physical.ParameterTypes);
            Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                type => reader.GetString(type.Name) is "PCONTROLLER" or "CONTROLLER_ALIAS" or "PPCONTROLLER" or
                    "IController" or "Unknown" or "UnneededDependency");
            var reference = Assert.Single(reader.TypeReferences.Select(reader.GetTypeReference)
                .Where(type => reader.GetString(type.Namespace) == "Windows.System" &&
                    reader.GetString(type.Name) == "DispatcherQueueController"));
            Assert.Equal(HandleKind.AssemblyReference, reference.ResolutionScope.Kind);
            var assembly = reader.GetAssemblyReference((AssemblyReferenceHandle)reference.ResolutionScope);
            Assert.Equal("Windows.Foundation.UniversalApiContract", reader.GetString(assembly.Name));
            Assert.Equal(new Version(10, 0, 0, 0), assembly.Version);
            Assert.True(assembly.PublicKeyOrToken.IsNil);
            AssertMetadataClosure(reader);
            var withoutImport = ClangSharpSourceCompilation.Create(fixture.DirectoryPath, architecture,
                new(), new(), Array.Empty<string>(), new(), new(), new(), Array.Empty<string>(), new(), new());
            Assert.Contains(withoutImport.GetDiagnostics(), diagnostic => diagnostic.Id == "CS0246" &&
                diagnostic.GetMessage().Contains("'IController'", StringComparison.Ordinal));
        }

        private static void NonComCallingConventionsRetainNativePointerAliases(
            string queryConvention, string addRefConvention, string releaseConvention, bool derived)
        {
            string name = derived ? "Derived" : "Record";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc", $@"
struct IID {{ unsigned long first; unsigned short second, third; unsigned char fourth[8]; }};
struct __declspec(uuid(""00000000-0000-0000-c000-000000000046"")) Record
{{
    virtual long {queryConvention} QueryInterface(const IID& iid, void** result) = 0;
    virtual unsigned long {addRefConvention} AddRef() = 0;
    virtual unsigned long {releaseConvention} Release() = 0;
}};
{(derived ? "struct Derived : Record { virtual void __cdecl AdditionalMethod() = 0; };" : "")}
typedef {name}* RECORD_POINTER;
extern ""C"" void Use(RECORD_POINTER value);
", annotationsEnabled: false);
            fixture.AssertSuccess();
            var alias = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>()
                .Single(type => type.Identifier.ValueText == "RECORD_POINTER");
            Assert.Equal($"global::Test.{name}*",
                Assert.Single(alias.Members.OfType<FieldDeclarationSyntax>()).Declaration.Type.ToString());
            var proof = NativeTypedefSourceProvenance.Read(alias);
            Assert.NotNull(proof);
            Assert.Equal("RECORD_POINTER", proof.NativeName);
            Assert.Equal(fixture.Header, proof.Header);
            Assert.Equal(4L, proof.Size);
            Assert.Equal(4L, proof.Alignment);
        }

        private static void UuidAndVirtualMethodsAloneDoNotEraseNativePointerAliases(string declaration)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                declaration + "\ntypedef Record* RECORD_POINTER;\nextern \"C\" void Use(RECORD_POINTER value);",
                annotationsEnabled: false);
            fixture.AssertSuccess();
            var alias = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>()
                .Single(type => type.Identifier.ValueText == "RECORD_POINTER");
            Assert.Equal("global::Test.Record*", Assert.Single(alias.Members.OfType<FieldDeclarationSyntax>()).Declaration.Type.ToString());
            Assert.NotNull(NativeTypedefSourceProvenance.Read(alias));
        }

        private static void InferredScalarContextsComposeRealPartitionObservationsThroughTheOriginalEmitter(bool bareTraversalFileName)
        {
            string evidence = Environment.GetEnvironmentVariable("WIN32_TYPEDEF_PROTOTYPE_EVIDENCE_ROOT");
            string scenario = bareTraversalFileName ? "bare-traversal-contexts" : "scalar-contexts";
            string ownerNamespace = bareTraversalFileName ? "Observed.ZOwner" : "Observed.First";
            string observerNamespace = bareTraversalFileName ? "Observed.AObserver" : "Observed.Second";
            if (bareTraversalFileName)
                Assert.True(StringComparer.Ordinal.Compare(ownerNamespace, observerNamespace) > 0);
            string root = Path.Combine(Path.GetTempPath(), "win32-typedef-contexts-" + Guid.NewGuid().ToString("N"));
            string inputs = Path.Combine(root, "inputs");
            Directory.CreateDirectory(inputs);
            string header = Path.Combine(root, "shared-aliases.h");
            File.WriteAllText(header, @"
typedef unsigned long APP_SCALAR;
typedef __UINTPTR_TYPE__ APP_WORD;
struct APP_RECORD { APP_SCALAR first; APP_SCALAR second; };
typedef APP_RECORD* PAPP_RECORD;
static_assert(sizeof(APP_SCALAR) == 4 && alignof(APP_SCALAR) == 4, ""Scalar ABI changed."");
static_assert(sizeof(APP_WORD) == sizeof(void*) && alignof(APP_WORD) == alignof(void*), ""Word ABI changed."");
static_assert(sizeof(APP_RECORD) == 8 && alignof(APP_RECORD) == 4, ""Record ABI changed."");
");
            var routing = new Dictionary<string, string>
            {
                ["APP_SCALAR"] = "Projected.Types", ["APP_WORD"] = "Projected.Types",
                ["FirstUse"] = "Projected.Api", ["SecondUse"] = "Projected.Api",
                ["FirstRecord"] = "Projected.Api", ["SecondRecord"] = "Projected.Api",
                ["PAPP_RECORD"] = "Projected.Types",
                ["FirstEnum"] = "Projected.Enums", ["SecondEnum"] = "Projected.Enums",
            };
            var recordIdentities = new HashSet<string>(StringComparer.Ordinal);
            var aliasIdentities = new HashSet<string>(StringComparer.Ordinal);
            try
            {
                foreach (var target in new[]
                {
                    (Architecture: "x86", Triple: "i686-pc-windows-msvc"),
                    (Architecture: "x64", Triple: "x86_64-pc-windows-msvc"),
                    (Architecture: "arm64", Triple: "aarch64-pc-windows-msvc"),
                })
                {
                    string directory = Path.Combine(inputs, target.Architecture);
                    Directory.CreateDirectory(directory);
                    foreach (string prefix in new[] { "First", "Second" })
                    {
                        string sourceNamespace = prefix == "First" ? ownerNamespace : observerNamespace;
                        using var fixture = new HeaderAnnotationTests.NativeFixture(target.Architecture, target.Triple,
                            "#include \"shared-aliases.h\"\n" +
                            "const APP_SCALAR " + prefix + "Constant = (APP_SCALAR)-1;\n" +
                            "enum " + prefix + "Enum : APP_SCALAR { " + prefix + "EnumValue = (APP_SCALAR)7 };\n" +
                            "extern \"C\" APP_SCALAR __stdcall " + prefix + "Use(APP_SCALAR value, APP_WORD count);\n" +
                            "extern \"C\" void __stdcall " + prefix + "Record(PAPP_RECORD value);\n",
                            annotationsEnabled: false, namespaceName: sourceNamespace,
                            extraSettings: "--include-directory\n" + root + "\n" +
                                "--remap\nAPP_SCALAR=APP_SCALAR\nAPP_WORD=APP_WORD\nPAPP_RECORD=PAPP_RECORD\n" +
                                (prefix == "First" ? "--traverse\n" +
                                    (bareTraversalFileName ? Path.GetFileName(header) : header) + "\n" : ""),
                            directoryRoot: root);
                        try
                        {
                            Assert.False(File.Exists(Path.Combine(fixture.DirectoryPath, Path.GetFileName(header))));
                            fixture.AssertSuccess();
                            var observedRecord = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                                .OfType<StructDeclarationSyntax>().Single(record => record.Identifier.ValueText == "APP_RECORD");
                            var source = NativeRecordSourceProvenance.Read(observedRecord);
                            Assert.NotNull(source);
                            Assert.Equal(prefix == "First", source.TraversedHeader);
                            Assert.Equal(sourceNamespace, source.Namespace);
                            Assert.Equal(header, source.Header);
                            Assert.Equal(NativeConstantGroupProvenance.HashFile(header), source.HeaderHash);
                            Assert.Equal(8L, source.Size);
                            Assert.Equal(4L, source.Alignment);
                            recordIdentities.Add(source.Identity);
                            var observedAlias = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                                .DescendantNodes().OfType<StructDeclarationSyntax>()
                                .Single(alias => alias.Identifier.ValueText == "PAPP_RECORD");
                            var aliasSource = NativeTypedefSourceProvenance.Read(observedAlias);
                            Assert.NotNull(aliasSource);
                            Assert.Equal(header, aliasSource.Header);
                            Assert.Equal(source.HeaderHash, aliasSource.HeaderHash);
                            Assert.Equal(prefix == "First", aliasSource.TraversedHeader);
                            Assert.Equal(target.Architecture == "x86" ? 4L : 8L, aliasSource.Size);
                            aliasIdentities.Add(aliasSource.Identity);
                            File.Copy(fixture.Output, Path.Combine(directory, prefix + ".cs"));
                            File.Copy(Path.ChangeExtension(fixture.Output, ".header-types.cs"),
                                Path.Combine(directory, prefix + ".header-types.cs"));
                        }
                        finally
                        {
                            string retained = evidence == null ? null :
                                Path.Combine(evidence, scenario, target.Architecture, prefix);
                            if (retained != null)
                                Directory.CreateDirectory(retained);
                            RetainFixture(fixture, retained);
                        }
                    }
                    Assert.Single(recordIdentities);
                    Assert.Single(aliasIdentities);
                }
                File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"),
                    Path.Combine(inputs, "Metadata.manual.cs"));
                var compilation = ClangSharpSourceCompilation.Create(inputs, "crossarch", new(), new(),
                    Array.Empty<string>(), new(), routing, new(), Array.Empty<string>(), new(), new());
                var errors = compilation.CSharpCompilation.GetDiagnostics()
                    .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
                Assert.True(errors.Length == 0, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
                foreach (string prefix in new[] { "First", "Second" })
                {
                    var api = compilation.CSharpCompilation.GetTypeByMetadataName(
                        (prefix == "First" ? ownerNamespace : observerNamespace) + ".Apis");
                    Assert.NotNull(api);
                    var constant = Assert.Single(api.GetMembers(prefix + "Constant").OfType<IFieldSymbol>());
                    Assert.Equal(SpecialType.System_UInt32, constant.Type.SpecialType);
                    Assert.Equal(uint.MaxValue, constant.ConstantValue);
                    var enumeration = compilation.CSharpCompilation.GetTypeByMetadataName("Projected.Enums." + prefix + "Enum");
                    Assert.NotNull(enumeration);
                    Assert.Equal(SpecialType.System_UInt32, enumeration.EnumUnderlyingType.SpecialType);
                    Assert.Equal(7U, Assert.Single(enumeration.GetMembers(prefix + "EnumValue")
                        .OfType<IFieldSymbol>()).ConstantValue);
                }
                string output = Path.Combine(inputs, "ScalarContexts.winmd");
                var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                    compilation, new(), new(), new(), new Version(1, 0), output);
                Assert.True(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
                using var image = new MetadataImage(output);
                var reader = image.Reader;
                var scalar = FindType(reader, "APP_SCALAR");
                Assert.Equal("Projected.Types", reader.GetString(scalar.Namespace));
                AssertWrapper(reader, "APP_SCALAR", "UInt32");
                var record = FindType(reader, "APP_RECORD");
                Assert.Equal(ownerNamespace, reader.GetString(record.Namespace));
                Assert.Equal(new[] { "first", "second" }, record.GetFields().Select(reader.GetFieldDefinition)
                    .Select(field => reader.GetString(field.Name)).ToArray());
                Assert.All(record.GetFields().Select(reader.GetFieldDefinition), field =>
                    Assert.Equal("Projected.Types.APP_SCALAR", field.DecodeSignature(new SignatureNames(qualifiedNames: true), null)));
                Assert.Equal(record.GetCustomAttributes().Count, record.GetCustomAttributes()
                    .Select(attribute => AttributeName(reader, attribute)).Distinct().Count());
                AssertWrapper(reader, "PAPP_RECORD", ownerNamespace + ".APP_RECORD*");
                var words = reader.TypeDefinitions
                    .Where(handle => reader.GetString(reader.GetTypeDefinition(handle).Name) == "APP_WORD").ToArray();
                Assert.Equal(2, words.Length);
                var wordArchitectures = new Dictionary<EntityHandle, int>();
                var decoder = new SignatureNames(qualifiedNames: true);
                foreach (var handle in words)
                {
                    var word = reader.GetTypeDefinition(handle);
                    Assert.Equal("Projected.Types", reader.GetString(word.Namespace));
                    AssertHasAttribute(reader, word.GetCustomAttributes(), "NativeTypedefAttribute");
                    var value = reader.GetFieldDefinition(Assert.Single(word.GetFields()));
                    string storage = value.DecodeSignature(decoder, null);
                    Assert.Contains(storage, new[] { "UInt32", "UInt64" });
                    int architecture = ReadArchitecture(word.GetCustomAttributes());
                    Assert.Equal(storage == "UInt32" ? 1 : 6, architecture);
                    wordArchitectures.Add(handle, architecture);
                }
                var projectedApi = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                    reader.GetString(type.Name) == "Apis" && reader.GetString(type.Namespace) == "Projected.Api");
                var methods = projectedApi.GetMethods().Select(reader.GetMethodDefinition)
                    .Where(method => reader.GetString(method.Name) is "FirstUse" or "SecondUse").ToArray();
                Assert.Equal(4, methods.Length);
                foreach (string prefix in new[] { "First", "Second" })
                    Assert.Equal(new[] { 1, 6 }, methods.Where(method => reader.GetString(method.Name) == prefix + "Use")
                        .Select(method => ReadArchitecture(method.GetCustomAttributes())).OrderBy(mask => mask).ToArray());
                foreach (var method in methods)
                {
                    Assert.Equal("Projected.Api", reader.GetString(reader.GetTypeDefinition(method.GetDeclaringType()).Namespace));
                    var signature = method.DecodeSignature(decoder, null);
                    Assert.Equal("Projected.Types.APP_SCALAR", signature.ReturnType);
                    Assert.Equal(new[] { "Projected.Types.APP_SCALAR", "Projected.Types.APP_WORD" },
                        signature.ParameterTypes.ToArray());
                    var blob = reader.GetBlobReader(method.Signature);
                    Assert.Equal(SignatureKind.Method, blob.ReadSignatureHeader().Kind);
                    Assert.Equal(2, blob.ReadCompressedInteger());
                    int architecture = ReadArchitecture(method.GetCustomAttributes());
                    EntityHandle returned = ReadAlias(ref blob, architecture);
                    EntityHandle parameter = ReadAlias(ref blob, architecture);
                    EntityHandle word = ReadAlias(ref blob, architecture);
                    Assert.Equal(returned, parameter);
                    Assert.Equal("APP_SCALAR", reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)returned).Name));
                    Assert.Equal(architecture, wordArchitectures[word]);
                    Assert.Equal(0, blob.RemainingBytes);
                }
                foreach (string prefix in new[] { "First", "Second" })
                {
                    var fields = reader.FieldDefinitions.Select(reader.GetFieldDefinition)
                        .Where(field => reader.GetString(field.Name) == prefix + "Constant").ToArray();
                    Assert.NotEmpty(fields);
                    foreach (var field in fields)
                    {
                        var constant = reader.GetConstant(field.GetDefaultValue());
                        Assert.Equal(ConstantTypeCode.UInt32, constant.TypeCode);
                        Assert.Equal(uint.MaxValue, reader.GetBlobReader(constant.Value).ReadUInt32());
                    }
                }
                AssertMetadataClosure(reader);

                int ReadArchitecture(CustomAttributeHandleCollection attributes, bool required = true)
                {
                    var matching = attributes.Where(attribute => AttributeName(reader, attribute) == "SupportedArchitectureAttribute").ToArray();
                    if (!required && matching.Length == 0)
                        return 7;
                    var blob = reader.GetBlobReader(reader.GetCustomAttribute(Assert.Single(matching)).Value);
                    Assert.Equal(1, blob.ReadUInt16());
                    int mask = blob.ReadInt32();
                    Assert.Equal(0, blob.ReadUInt16());
                    Assert.Equal(0, blob.RemainingBytes);
                    return mask;
                }

                EntityHandle ReadAlias(ref BlobReader blob, int architecture)
                {
                    Assert.Equal(SignatureTypeCode.TypeHandle, blob.ReadSignatureTypeCode());
                    EntityHandle type = blob.ReadTypeHandle();
                    if (type.Kind == HandleKind.TypeDefinition)
                    {
                        Assert.Equal(architecture, ReadArchitecture(reader.GetTypeDefinition((TypeDefinitionHandle)type)
                            .GetCustomAttributes(), required: false) & architecture);
                        return type;
                    }
                    Assert.Equal(HandleKind.TypeReference, type.Kind);
                    var reference = reader.GetTypeReference((TypeReferenceHandle)type);
                    Assert.Equal(HandleKind.ModuleDefinition, reference.ResolutionScope.Kind);
                    return Assert.Single(reader.TypeDefinitions.Where(handle =>
                    {
                        var definition = reader.GetTypeDefinition(handle);
                        return reader.GetString(definition.Name) == reader.GetString(reference.Name) &&
                            reader.GetString(definition.Namespace) == reader.GetString(reference.Namespace) &&
                            (ReadArchitecture(definition.GetCustomAttributes(), required: false) & architecture) == architecture;
                    }));
                }
            }
            finally
            {
                if (evidence != null)
                {
                    string retained = Path.Combine(evidence, scenario, "emitter");
                    Directory.CreateDirectory(retained);
                    File.Copy(header, Path.Combine(retained, "shared-aliases.h"));
                    foreach (string file in Directory.GetFiles(inputs, "*", SearchOption.AllDirectories))
                    {
                        string destination = Path.Combine(retained, Path.GetRelativePath(inputs, file));
                        Directory.CreateDirectory(Path.GetDirectoryName(destination));
                        File.Copy(file, destination);
                    }
                }
                Directory.Delete(root, recursive: true);
            }
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
                extraSettings: "--additional=-Xclang\n--additional=-fdump-record-layouts\n" +
                    "--remap\nAPPLICATION_POINTER=APPLICATION_POINTER\nFIXED_CHAIN=FIXED_CHAIN\n" +
                    "APPLICATION_POINTER_ADDRESS=APPLICATION_POINTER_ADDRESS\nRAW_APPLICATION_POINTER_ADDRESS=RAW_APPLICATION_POINTER_ADDRESS\n");
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
            string declarations = NativeDeclarations + InferredProjectionDeclarations + (annotationsEnabled ? string.Empty :
                "\n_WIN32META_ANNOTATE_FIELD_(GateRecord::value, _Win32_Reserved_);\n");
            string nominalAliases = "--remap\n" + string.Join("", new[]
            {
                "DWORD", "BYTE_CODE", "SCALAR_ALIAS", "VARIANT_BOOL", "HRESULT", "HDC", "HDRVR", "ADS_SEARCH_HANDLE",
                "APP_SIGNED_POINTER_VALUE", "APP_UNSIGNED_POINTER_VALUE",
                "EXTERNAL_COUNT_BASE", "EXTERNAL_FIELD_COUNT", "EXTERNAL_HANDLE_BASE", "EXTERNAL_API_HANDLE",
                "SELECTED_TEMPLATE_SCALAR", "event", "SIBLING_COUNT", "SIBLING_BOOLEAN", "REDECLARED_BOOLEAN",
                "GateGroup", "OPAQUE_HANDLE", "UI_ANIMATION_KEYFRAME", "MachineGlobalObjectTableRegistrationToken",
                "CONFIGURED_COUNT",
            }.Select(name => name + "=" + name + "\n"));
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                annotationsEnabled, libraryPath: "candidate-prototype.dll", namespaceName: "Windows.Win32.Foundation",
                extraSettings: "-DWIN32METADATA\n--remap\n_LEGACY_MASK=LEGACY_MASK\n_LEGACY_HIGH_MASK=LEGACY_HIGH_MASK\nHANDLE=IntPtr\nRAW_HANDLE_POINTER=HANDLE*\nPADS_SEARCH_HANDLE=ADS_SEARCH_HANDLE*\nAPP_UNSIGNED_POINTER_ADDRESS=UIntPtr*\nPRECORD_BUFFER=RECORD_BUFFER*\nPROVIDED_TOKEN_t=IntPtr\nPPROVIDED_TOKEN=PROVIDED_TOKEN*\nUNTYPED_RECORD_ADDRESS=RECORD_VALUE*\nPSIBLING_COUNT=SIBLING_COUNT*\nPSIBLING_BOOLEAN=SIBLING_BOOLEAN*\nPSESSION_KEY=SESSION_KEY*\nSIBLING_HANDLE=IntPtr\nSIBLING_HANDLE__*=SIBLING_HANDLE\nPSIBLING_HANDLE=SIBLING_HANDLE*\nPROVIDED_CONTEXT_t=IntPtr\nPPROVIDED_CONTEXT=PROVIDED_CONTEXT*\nPRECORD_VIEW=RECORD_VIEW*\nPREDECLARED_BOOLEAN=REDECLARED_BOOLEAN*\nPRIMARY_RESOURCE=IntPtr\nPRIMARY_RESOURCE__*=PRIMARY_RESOURCE\nSECONDARY_RESOURCE=IntPtr\nSECONDARY_RESOURCE__*=SECONDARY_RESOURCE\nPSECONDARY_RESOURCE=SECONDARY_RESOURCE*\nOPAQUE_VALUE_KEY=long\nOPAQUE_VALUE_KEY__*=OPAQUE_VALUE_KEY\nPOPAQUE_VALUE_KEY=OPAQUE_VALUE_KEY*\nLEGACY_RESOURCE=IntPtr\nLEGACY_RESOURCE__*=LEGACY_RESOURCE\n--exclude\nPROVIDED_TOKEN_t\nPROVIDED_CONTEXT_t\nSIBLING_HANDLE__\nPRIMARY_RESOURCE__\nSECONDARY_RESOURCE__\nOPAQUE_VALUE_KEY__\nLEGACY_RESOURCE__\n" + nominalAliases);
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
                InferredIdentityPreservesOrdinaryClrProjectionAndExplicitNominalIntent(fixture, reader, annotationsEnabled);
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

using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Security.Cryptography;
using System.Text.Json;
using System.Text.RegularExpressions;
using ClangSharp;
using ClangSharp.Interop;
using ClangSharpSourceToWinmd;
using MetadataTasks;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class HeaderAnnotationWinmdTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void CompilerBuiltinsRemainAbsentFromPhysicalDllApiMetadata(string architecture, string target, bool annotated)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target,
                HeaderAnnotationIntrinsicTests.Declarations, annotationsEnabled: annotated);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(NativeSurface(fixture, target, false), NativeSurface(fixture, target, true));
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            Assert.DoesNotContain(reader.MethodDefinitions, handle => reader.GetString(reader.GetMethodDefinition(handle).Name)
                is "__builtin_trap" or "__builtin_memcpy" or "_mm_pause" or "__faststorefence");
            var ordinary = FindMethod(reader, "Apis", "Ordinary");
            Assert.Equal("scan.dll", reader.GetString(reader.GetModuleReference(ordinary.GetImport().Module).Name));
            Assert.Equal("Ordinary", reader.GetString(ordinary.GetImport().Name));
            var parameter = Assert.Single(ordinary.GetParameters().Select(reader.GetParameter));
            Assert.Equal(annotated, parameter.GetCustomAttributes().Any(handle => AttributeName(reader, handle) == "RetainedAttribute"));
            Assert.Equal(annotated, ordinary.GetCustomAttributes().Any(handle => AttributeName(reader, handle) == "SupportedOSPlatformAttribute"));
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void ParameterOverridesPreserveNativeContractsAndReachPhysicalMetadata(
            string architecture, string target, bool annotationsEnabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef int HRESULT;
typedef struct RECT { int left; int top; int right; int bottom; } RECT;
struct __declspec(uuid(""592ee928-49ea-414a-91b2-ae009f63f348"")) IOpaque
{
    virtual HRESULT __stdcall Ordinary() = 0;
};
extern ""C"" {
HRESULT __stdcall Scalar(_In_opt_ _Win32_Optional_(false) unsigned creationOptions);
HRESULT __stdcall Direct(_Outptr_ _Win32_ComOutPtr_(true) void** result);
HRESULT __stdcall InterfaceOutput(_Outptr_ _Win32_ComOutPtr_(true) IOpaque** result);
HRESULT __stdcall AlreadyCom(_COM_Outptr_ _Win32_ComOutPtr_(true) void** result);
HRESULT __stdcall RemoveCom(_COM_Outptr_ _Win32_ComOutPtr_(false) void** result);
HRESULT __stdcall Counted(_Out_writes_(count) _Win32_Optional_(true) unsigned* pIndex, unsigned count);
}
typedef HRESULT (__stdcall* PFN_OVERRIDES)(
    _In_opt_ _Win32_Optional_(false) void* context,
    _Outptr_ _Win32_ComOutPtr_(true) void** result);
void UseCallback(PFN_OVERRIDES callback);
struct __declspec(uuid(""2742050f-cfe2-475a-8ddb-a422215d8d09"")) IParameterOverrides
{
    virtual HRESULT __stdcall BindToObject(_Outptr_ void** result) = 0;
    virtual HRESULT __stdcall GetPageIndex(_Out_writes_(count) unsigned* pIndex, unsigned count) = 0;
    virtual HRESULT __stdcall ReadRect(_In_opt_ const RECT* prc) = 0;
};
_WIN32META_ANNOTATE_PARAMETER_(IParameterOverrides::BindToObject, result, _Win32_ComOutPtr_(true));
_WIN32META_ANNOTATE_PARAMETER_(IParameterOverrides::GetPageIndex, pIndex, _Win32_Optional_(true));
_WIN32META_ANNOTATE_PARAMETER_(IParameterOverrides::ReadRect, prc, _Win32_Optional_(true));
", annotationsEnabled: annotationsEnabled);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.DoesNotContain("_WIN32META_PARAMETER_", fixture.ReadSource());
            Assert.Equal(NativeSurface(fixture, target, false), NativeSurface(fixture, target, true));
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            Check("Apis", "Scalar", "creationOptions", "UInt32", ParameterAttributes.In |
                (annotationsEnabled ? ParameterAttributes.None : ParameterAttributes.Optional), false);
            Check("Apis", "Direct", "result", "Void**", ParameterAttributes.Out, annotationsEnabled);
            Check("Apis", "InterfaceOutput", "result", "IOpaque*", ParameterAttributes.Out, annotationsEnabled);
            Check("Apis", "AlreadyCom", "result", "Void**", ParameterAttributes.Out, true);
            Check("Apis", "RemoveCom", "result", "Void**", ParameterAttributes.Out, !annotationsEnabled);
            Check("Apis", "Counted", "pIndex", "UInt32*", ParameterAttributes.Out |
                (annotationsEnabled ? ParameterAttributes.Optional : ParameterAttributes.None), false, array: true);
            Check("IParameterOverrides", "BindToObject", "result", "Void**", ParameterAttributes.Out, annotationsEnabled);
            Check("IParameterOverrides", "GetPageIndex", "pIndex", "UInt32*", ParameterAttributes.Out |
                (annotationsEnabled ? ParameterAttributes.Optional : ParameterAttributes.None), false, array: true);
            Check("IParameterOverrides", "ReadRect", "prc", "RECT*", ParameterAttributes.In | ParameterAttributes.Optional, false);
            Check("PFN_OVERRIDES", "Invoke", "context", "Void*", ParameterAttributes.In |
                (annotationsEnabled ? ParameterAttributes.None : ParameterAttributes.Optional), false);
            Check("PFN_OVERRIDES", "Invoke", "result", "Void**", ParameterAttributes.Out, annotationsEnabled);
            var rect = FindMethod(reader, "IParameterOverrides", "ReadRect").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 1);
            AssertHasAttribute(reader, rect.GetCustomAttributes(), "ConstAttribute");
            AssertMetadataClosure(reader);

            void Check(string owner, string name, string parameterName, string expectedType,
                ParameterAttributes attributes, bool comOutPtr, bool array = false)
            {
                var method = FindMethod(reader, owner, name);
                Assert.Equal("Int32", method.DecodeSignature(new SignatureNames(), null).ReturnType);
                var parameters = method.GetParameters().Select(reader.GetParameter)
                    .Where(parameter => parameter.SequenceNumber != 0).ToArray();
                var parameter = Assert.Single(parameters, candidate => reader.GetString(candidate.Name) == parameterName);
                Assert.Equal(attributes, parameter.Attributes);
                Assert.Equal(expectedType, method.DecodeSignature(new SignatureNames(), null).ParameterTypes[parameter.SequenceNumber - 1]);
                Assert.Equal(comOutPtr ? 1 : 0, parameter.GetCustomAttributes()
                    .Count(handle => AttributeName(reader, handle) == "ComOutPtrAttribute"));
                Assert.Equal(array, parameter.GetCustomAttributes()
                    .Any(handle => AttributeName(reader, handle) == "NativeArrayInfoAttribute"));
                if (owner == "Apis")
                {
                    Assert.Equal("scan.dll", reader.GetString(reader.GetModuleReference(method.GetImport().Module).Name));
                    Assert.Equal(name, reader.GetString(method.GetImport().Name));
                    Assert.False(method.GetImport().Attributes.HasFlag(MethodImportAttributes.SetLastError));
                }
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void ParameterOverridesSupportNativeCWithoutChangingSignatures(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
int Scalar(_In_opt_ _Win32_Optional_(false) unsigned creationOptions);
int Output(_Outptr_ _Win32_ComOutPtr_(true) void** result);
", extraSettings: "--language\nc\n--std\nc11\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(NativeSurface(fixture, target, false, "c"), NativeSurface(fixture, target, true, "c"));
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var scalar = FindMethod(reader, "Apis", "Scalar").GetParameters().Select(reader.GetParameter).Single();
            Assert.Equal(ParameterAttributes.In, scalar.Attributes);
            var output = FindMethod(reader, "Apis", "Output").GetParameters().Select(reader.GetParameter).Single();
            Assert.Equal(ParameterAttributes.Out, output.Attributes);
            AssertHasAttribute(reader, output.GetCustomAttributes(), "ComOutPtrAttribute");
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void HeaderGroupMemberAndIndependentLegacyEnumKeepTheirIdentities(string architecture, string target, bool sameNamespace)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#define CFE_UNDERLINE 4UL
#define CFU_SINGLE 1
#define CFU_DOUBLE 2
#define UNDERLINE_ALIAS CFE_UNDERLINE
_Win32_Enum_(CFE_EFFECTS, unsigned, CFE_UNDERLINE);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string residual = Path.Combine(fixture.DirectoryPath, "residual.json");
            string legacyJson = @"{ ""items"": [{
                ""name"": ""CFE_UNDERLINE"", ""namespace"": ""Test"", ""type"": ""uint"", ""flags"": true,
                ""autoPopulate"": { ""filter"": ""CFU_"", ""header"": """ + Path.GetFileName(fixture.Header) + @""" }
            }] }";
            File.WriteAllText(residual, sameNamespace ? legacyJson : legacyJson.Replace(@"""namespace"": ""Test"",", ""));
            if (!sameNamespace)
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, "LegacyApis.manual.cs"),
                    "namespace Windows.Win32.System.SystemServices { public static partial class Apis { } }");
            MetadataUtils.ConstantsScraper.ScrapeConstants(new[] { residual }, "Test", fixture.DirectoryPath, "using System;\n",
                new HashSet<string>(), new() { [fixture.Header] = "Test" }, new(), new(), new(), new());
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var effects = FindType(reader, "CFE_EFFECTS");
            Assert.Equal(new[] { "value__", "CFE_UNDERLINE" }, effects.GetFields()
                .Select(handle => reader.GetString(reader.GetFieldDefinition(handle).Name)));
            Assert.Equal(4U, reader.GetBlobReader(reader.GetConstant(effects.GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == "CFE_UNDERLINE").GetDefaultValue()).Value).ReadUInt32());
            var legacy = FindType(reader, "CFE_UNDERLINE");
            Assert.Equal(sameNamespace ? "Test" : "Windows.Win32.System.SystemServices", reader.GetString(legacy.Namespace));
            AssertHasAttribute(reader, legacy.GetCustomAttributes(), "FlagsAttribute");
            Assert.Equal("UInt32", reader.GetFieldDefinition(legacy.GetFields().First()).DecodeSignature(new SignatureNames(), null));
            Assert.Equal(new[] { "value__", "CFU_SINGLE", "CFU_DOUBLE" }, legacy.GetFields()
                .Select(handle => reader.GetString(reader.GetFieldDefinition(handle).Name)));
            var fields = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "Apis" && reader.GetString(type.Namespace) == "Test")
                .GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.DoesNotContain(fields, field => reader.GetString(field.Name) == "CFE_UNDERLINE");
            var alias = Assert.Single(fields, field => reader.GetString(field.Name) == "UNDERLINE_ALIAS");
            Assert.Equal("UInt32", alias.DecodeSignature(new SignatureNames(), null));
            Assert.Equal(4U, reader.GetBlobReader(reader.GetConstant(alias.GetDefaultValue()).Value).ReadUInt32());
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("foreign-type")]
        [InlineData("ambiguous-groups")]
        [InlineData("out-of-range")]
        [InlineData("existing-value")]
        public void HeaderMemberTypeNameAliasKeepsBindingAndErrorBoundaries(string boundary)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FIRST 512U
_Win32_Enum_(SOURCE_GROUP, unsigned, FIRST);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string ns = boundary == "foreign-type" ? "Foreign" : "Test";
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "Extra.manual.cs"),
                $"namespace {ns} {{ public enum FIRST : uint {{ OTHER = 1 }} }}");
            if (boundary == "ambiguous-groups")
                File.WriteAllText(Path.Combine(Path.GetDirectoryName(fixture.Output), "Extra.header-types.cs"),
                    "namespace Test { public enum OTHER_GROUP : uint { FIRST = 512 } }");
            string storage = boundary == "out-of-range" ? "byte" : "uint";
            string existing = boundary == "existing-value" ? "private const uint FIRST = 7;" : "";
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "Aliases.constants.cs"),
                (boundary == "foreign-type" ? "using Foreign;\n" : "") +
                $"namespace Test {{ public static partial class Apis {{ {existing} public const {storage} ALIAS = FIRST; }} }}");
            if (boundary != "existing-value")
            {
                var error = Assert.Throws<Xunit.Sdk.EmptyException>(() => Emit(fixture, "x64"));
                Assert.Contains(boundary == "out-of-range" ? "CS0221" : "CS0119", error.Message);
                return;
            }
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            var alias = FindType(reader, "Apis").GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == "ALIAS");
            Assert.Equal(7U, reader.GetBlobReader(reader.GetConstant(alias.GetDefaultValue()).Value).ReadUInt32());
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("c", "c11")]
        [InlineData("c++", "c++17")]
        public void ForwardCleanupIdentityAndCompleteInvalidSetsReachPhysicalMetadata(string language, string standard)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
_Win32_RAIIFree_Handle_(CloseLater) void* __stdcall OpenLater(void);
int __stdcall CreateLater(_Out_ _Win32_RAIIFree_(CloseLater, -1, 0) void** value);
void* __stdcall BorrowLater(void* value);
__declspec(dllimport) int __stdcall CloseLater(void* value);
", extraSettings: $"--language\n{language}\n--std\n{standard}\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(NativeSurface(fixture, "x86_64-pc-windows-msvc", false, language),
                NativeSurface(fixture, "x86_64-pc-windows-msvc", true, language));
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            var open = FindMethod(reader, "Apis", "OpenLater");
            Assert.Equal("Void*", open.DecodeSignature(new SignatureNames(), null).ReturnType);
            var result = open.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 0);
            AssertStringAttribute(reader, result.GetCustomAttributes(), "RAIIFreeAttribute", "CloseLater");
            Assert.Equal(new long[] { -1, 0 }, ReadInvalidValues(reader, result.GetCustomAttributes()));
            var create = FindMethod(reader, "Apis", "CreateLater");
            Assert.Equal(new[] { "Void**" }, create.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            var output = Assert.Single(create.GetParameters().Select(reader.GetParameter));
            Assert.True(output.Attributes.HasFlag(ParameterAttributes.Out));
            AssertStringAttribute(reader, output.GetCustomAttributes(), "RAIIFreeAttribute", "CloseLater");
            Assert.Equal(new long[] { -1, 0 }, ReadInvalidValues(reader, output.GetCustomAttributes()));
            var borrowed = FindMethod(reader, "Apis", "BorrowLater");
            AssertDoesNotHaveAttribute(reader, borrowed.GetCustomAttributes(), "RAIIFreeAttribute");
            foreach (var parameter in borrowed.GetParameters().Select(reader.GetParameter))
                AssertDoesNotHaveAttribute(reader, parameter.GetCustomAttributes(), "RAIIFreeAttribute");
            AssertMetadataClosure(reader);
        }

        private const string Declarations = @"
typedef void* HANDLE;
typedef int HRESULT;
enum _Win32_SupportedOS_10240_ _Win32_AssociatedConstant_(LOOSE_A)
    _Win32_AssociatedConstant_(LOOSE_B) Options : unsigned { OptionA = 1, OptionB = 2 };
enum class [[clang::flag_enum]] ScopedOptions : unsigned { None = 0, A = 1, B = 2 };
struct _Win32_SupportedOS_10240_ DESCRIPTION {
    _Win32_AssociatedEnum_(Options) unsigned flags;
    int size;
};
_Win32_SupportedOS_Windows7_ _Win32_AlsoUsableFor_(OTHER_TOKEN)
typedef unsigned long TOKEN;
_Win32_SupportedOS_10240_
typedef int (__stdcall* PFN_BASE)(_Win32_Retained_ void* context, unsigned count);
_Win32_SupportedOS_Windows7_
typedef PFN_BASE PFN_ALIAS;
extern ""C"" {
_Win32_SetLastError_ _Win32_ImportLibrary_(""header.dll"") _Win32_SupportedOS_10240_
int __stdcall Imported(_In_ _Win32_Retained_ void* context,
    _Out_writes_bytes_opt_(capacity) _Win32_ContainsInteriorPointers_ unsigned char* buffer,
    unsigned capacity);
_Win32_RAIIFree_(CloseThing, 0, -1) HANDLE __stdcall OpenThing();
int __stdcall CreateThing(_Out_ _Win32_RAIIFree_(CloseThing, 0) HANDLE* output);
_Win32_AssociatedEnum_(Options) unsigned __stdcall AssociatedReturn();
int __stdcall ReadOption(_In_ _Win32_AssociatedEnum_(Options) unsigned option);
_Win32_PreserveResult_ HRESULT __stdcall ExactResult();
int __stdcall Retval(_Out_ _Win32_Retval_ int* result);
int __stdcall MidlRetval(/* [out] [retval] */ _Out_retval_ int* result);
TOKEN __stdcall UseToken(TOKEN value, TOKEN* output);
int __stdcall UseCallback(PFN_ALIAS callback);
}
struct __declspec(uuid(""b2051485-7dfd-41a0-af5c-1b351bfb1297"")) _Win32_SupportedOS_10240_ IHeaderSample {
    _Win32_PreserveResult_ _Win32_SupportedOS_Windows7_
    virtual HRESULT __stdcall Exact(_Out_ _Win32_Retval_ int* result) = 0;
    _Win32_RAIIFree_(CloseThing, 0, -1)
    virtual HANDLE __stdcall Produce() = 0;
    virtual HRESULT __stdcall Buffer(_Out_writes_bytes_(capacity) _Win32_ContainsInteriorPointers_ unsigned char* data, unsigned capacity) = 0;
};
";

        private const string ScopedDeclarations = @"
typedef int HRESULT;
int BeforeScope();
_Win32_SupportedOS_BEGIN_(WindowsVista)
struct SCOPED_RECORD {
    int size;
    unsigned flags;
    struct NESTED_RECORD { int value; };
    enum NESTED_ENUM { NestedValue = 1 };
};
enum SCOPED_ENUM : unsigned { ScopedValue = 1 };
typedef unsigned SCOPED_TOKEN;
typedef int (__stdcall* PFN_SCOPED)(_In_ _Win32_Retained_ void* context, _Out_ int* result);
using USING_TOKEN = unsigned;
using PFN_USING = SCOPED_TOKEN (__stdcall*)(_In_ _Win32_Retained_ void* context, _Out_ _Win32_Retval_ int* result);
using PFN_USING_ALIAS = PFN_USING;
using PFN_USING_NATIVE_ALIAS = PFN_SCOPED;
typedef PFN_USING PFN_TYPEDEF_USING_ALIAS;
SCOPED_TOKEN UseScopedToken(SCOPED_TOKEN value);
USING_TOKEN UseUsingToken(USING_TOKEN value);
void UseScopedCallbacks(PFN_SCOPED first, PFN_USING second, PFN_USING_ALIAS third, PFN_TYPEDEF_USING_ALIAS fourth);
_Win32_SupportedOS_END_()
using DIRECT_TOKEN _Win32_SupportedOS_Windows7_ = unsigned;
_Win32_SupportedOS_Windows7_ typedef struct _PRIMARY_SCOPED { unsigned value; } PRIMARY_SCOPED;
_Win32_SupportedOS_BEGIN_(Windows7)
int Seven();
_Win32_SupportedOS_Windows7_ int ExplicitEqual();
_Win32_SupportedOS_END_()
_Win32_SupportedOS_Windows8_ int ExplicitLater();
_Win32_SupportedOS_Windows2000_ int ExplicitEarlier();
_Win32_SupportedOS_BEGIN_(Windows2000)
int OlderNested();
_Win32_SupportedOS_END_()
struct __declspec(uuid(""4d0ea686-f54d-4b53-aeec-bf6154950080"")) _Win32_SupportedOS_WindowsVista_ IScoped {
    _Win32_SupportedOS_WindowsVista_ virtual HRESULT __stdcall VistaMethod(_Out_ _Win32_Retval_ int* result) = 0;
    _Win32_SupportedOS_Windows7_ virtual HRESULT __stdcall SevenMethod() = 0;
    _Win32_SupportedOS_Windows2000_ virtual HRESULT __stdcall ExplicitMethod() = 0;
    _Win32_SupportedOS_WindowsVista_ virtual HRESULT __stdcall VistaAgainMethod() = 0;
};
int AfterScope();
struct __declspec(uuid(""b3dd7ce4-3a4c-42d8-b506-b32919dc848e"")) _Win32_SupportedOS_Windows7_ IContainerOnly {
    virtual HRESULT __stdcall UnannotatedMember(_Out_ _Win32_Retval_ int* result) = 0;
};
";

        [NativeMigrationTheory("SYSTEM_AVAILABILITY_BINDINGS")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void SystemOwnedDeclarationFactsPreservePhysicalMetadata(string architecture)
        {
            string bindings = Environment.GetEnvironmentVariable("SYSTEM_AVAILABILITY_BINDINGS");
            string beforeBindings = Environment.GetEnvironmentVariable("SYSTEM_AVAILABILITY_BEFORE_BINDINGS") ?? bindings;
            string proposal = Environment.GetEnvironmentVariable("BULK_SYSTEM_MIGRATION_ROOT");
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(proposal, "report.json")));
            var facts = report.RootElement.GetProperty("facts").EnumerateArray()
                .Where(value => value.GetProperty("status").GetString() == "converted").ToArray();
            Assert.NotEmpty(facts);
            bool returnAssociations = facts.All(value => value.GetProperty("category").GetString() == "associated-enum-return");
            bool parameterContracts = facts.All(value => value.GetProperty("category").GetString()
                is "associated-enum-parameter" or "contains-interior-pointers");
            bool addedAttributes = returnAssociations || parameterContracts;
            Assert.True(addedAttributes || facts.All(value => value.GetProperty("category").GetString() == "supportedOS"));
            if (report.RootElement.TryGetProperty("physicalMetadataComponentExclusions", out var exclusions))
            {
                var excluded = exclusions.EnumerateArray().Select(value => value.GetProperty("symbol").GetString())
                    .ToHashSet(StringComparer.Ordinal);
                Assert.Subset(facts.Select(value => value.GetProperty("symbol").GetString()).ToHashSet(StringComparer.Ordinal), excluded);
                facts = facts.Where(value => !excluded.Contains(value.GetProperty("symbol").GetString())).ToArray();
                Assert.NotEmpty(facts);
            }
            var names = facts.Select(value => value.GetProperty("symbol").GetString().Split("::")[0])
                .ToHashSet(StringComparer.Ordinal);
            var factsByName = facts.ToLookup(value => value.GetProperty("symbol").GetString().Split("::")[0], StringComparer.Ordinal);
            var retired = addedAttributes
                ? report.RootElement.GetProperty("emitterRowsToRemove").EnumerateArray()
                    .Select(value => value.GetString()).ToHashSet(StringComparer.Ordinal)
                : new HashSet<string>(StringComparer.Ordinal);
            string root = WinHttpMigrationTests.RepositoryRoot;
            var namespaces = File.ReadLines(Path.Combine(root, "generation", "WinSDK", "requiredNamespacesForNames.rsp"))
                .Select(line => line.Trim().Split('=', 2)).Where(parts => parts.Length == 2)
                .ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
            var remaps = File.ReadLines(Path.Combine(root, "generation", "WinSDK", "emitter.settings.rsp"))
                .Select(line => line.Trim().Split('=', 2)).Where(parts => parts.Length == 2 &&
                    names.Contains(parts[0].Split("::")[0]) && !retired.Contains(parts[0] + "=" + parts[1]))
                .ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
            string component = Path.Combine(bindings, "availability-component-" + Guid.NewGuid().ToString("N"));
            foreach (string state in addedAttributes ? new[] { "before", "after", "expected" } : new[] { "before", "after" })
            {
                string directory = Path.Combine(component, state);
                Directory.CreateDirectory(directory);
                using var results = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                    state == "after" ? bindings : beforeBindings, state == "expected" ? "before" : state,
                    architecture, "results.json")));
                var observed = new HashSet<string>(StringComparer.Ordinal);
                foreach (var result in results.RootElement.EnumerateArray())
                {
                    Assert.True(result.GetProperty("success").GetBoolean());
                    string path = result.GetProperty("generatedSource").GetString();
                    Assert.Equal(result.GetProperty("generatedSourceSha256").GetString(),
                        Convert.ToHexString(System.Security.Cryptography.SHA256.HashData(File.ReadAllBytes(path))));
                    var source = CSharpSyntaxTree.ParseText(File.ReadAllText(path)).GetCompilationUnitRoot();
                    var methods = source.DescendantNodes().OfType<MethodDeclarationSyntax>()
                        .Where(value => names.Contains(value.Identifier.ValueText) &&
                            value.Modifiers.Any(SyntaxKind.ExternKeyword) &&
                            value.Parent is ClassDeclarationSyntax parent && parent.Identifier.ValueText == "Apis").ToArray();
                    foreach (var method in methods)
                        Assert.True(observed.Add(method.Identifier.ValueText),
                            "Duplicate actual imported method: " + method.Identifier.ValueText);
                    if (state == "expected")
                    {
                        source = source.ReplaceNodes(methods, (method, _) =>
                        {
                            if (parameterContracts)
                            {
                                var parameters = method.ParameterList.Parameters.Select(parameter =>
                                {
                                    foreach (var fact in factsByName[method.Identifier.ValueText].Where(value =>
                                        value.GetProperty("symbol").GetString().Split("::")[1] == parameter.Identifier.ValueText))
                                    {
                                        bool association = fact.GetProperty("category").GetString() == "associated-enum-parameter";
                                        var parameterAttribute = SyntaxFactory.Attribute(SyntaxFactory.IdentifierName(
                                            association ? "AssociatedEnum" : "ContainsInteriorPointers"));
                                        if (association)
                                            parameterAttribute = parameterAttribute.WithArgumentList(
                                                SyntaxFactory.AttributeArgumentList(SyntaxFactory.SingletonSeparatedList(
                                                    SyntaxFactory.AttributeArgument(SyntaxFactory.LiteralExpression(
                                                        SyntaxKind.StringLiteralExpression,
                                                        SyntaxFactory.Literal(fact.GetProperty("enumName").GetString()))))));
                                        parameter = parameter.AddAttributeLists(SyntaxFactory.AttributeList(
                                            SyntaxFactory.SingletonSeparatedList(parameterAttribute)));
                                    }
                                    return parameter;
                                });
                                return method.WithParameterList(method.ParameterList.WithParameters(
                                    SyntaxFactory.SeparatedList(parameters)));
                            }
                            var argument = SyntaxFactory.AttributeArgument(SyntaxFactory.LiteralExpression(
                                SyntaxKind.StringLiteralExpression, SyntaxFactory.Literal(Assert.Single(factsByName[method.Identifier.ValueText])
                                    .GetProperty("enumName").GetString())));
                            var attribute = SyntaxFactory.Attribute(SyntaxFactory.IdentifierName("AssociatedEnum"),
                                SyntaxFactory.AttributeArgumentList(SyntaxFactory.SingletonSeparatedList(argument)));
                            var list = SyntaxFactory.AttributeList(SyntaxFactory.SingletonSeparatedList(attribute))
                                .WithTarget(SyntaxFactory.AttributeTargetSpecifier(SyntaxFactory.Token(SyntaxKind.ReturnKeyword)));
                            return method.AddAttributeLists(list);
                        });
                        methods = source.DescendantNodes().OfType<MethodDeclarationSyntax>()
                            .Where(value => names.Contains(value.Identifier.ValueText) &&
                                value.Modifiers.Any(SyntaxKind.ExternKeyword) &&
                                value.Parent is ClassDeclarationSyntax parent && parent.Identifier.ValueText == "Apis").ToArray();
                    }
                    var availableTypes = source.DescendantNodes().OfType<BaseTypeDeclarationSyntax>()
                        .Where(value => value is StructDeclarationSyntax or EnumDeclarationSyntax &&
                            !value.Ancestors().OfType<BaseTypeDeclarationSyntax>().Any())
                        .ToLookup(value => value.Identifier.ValueText, StringComparer.Ordinal);
                    var requiredTypes = new Queue<string>(methods.SelectMany(method =>
                            new[] { method.ReturnType }.Concat(method.ParameterList.Parameters
                                .Where(parameter => parameter.Type != null).Select(parameter => parameter.Type)))
                        .SelectMany(type => type.DescendantNodesAndSelf().OfType<IdentifierNameSyntax>())
                        .Select(type => type.Identifier.ValueText).Distinct(StringComparer.Ordinal));
                    var dependencies = new List<BaseTypeDeclarationSyntax>();
                    var visited = new HashSet<string>(StringComparer.Ordinal);
                    while (requiredTypes.TryDequeue(out string name))
                    {
                        if (!visited.Add(name) || !availableTypes.Contains(name))
                            continue;
                        var declaration = Assert.Single(availableTypes[name]);
                        dependencies.Add(declaration);
                        foreach (var type in declaration.DescendantNodes().OfType<IdentifierNameSyntax>())
                            requiredTypes.Enqueue(type.Identifier.ValueText);
                    }
                    var members = methods.Cast<MemberDeclarationSyntax>().Concat(dependencies)
                        .GroupBy(value => string.Join(".", value.Ancestors()
                            .OfType<BaseNamespaceDeclarationSyntax>().Reverse().Select(parent => parent.Name.ToString())))
                        .Select(group => SyntaxFactory.NamespaceDeclaration(SyntaxFactory.ParseName(group.Key))
                            .AddMembers(group.OfType<MethodDeclarationSyntax>()
                                .GroupBy(method => method.Ancestors().OfType<ClassDeclarationSyntax>().First())
                                .Select(methodsInClass => methodsInClass.Key.WithMembers(
                                    SyntaxFactory.List<MemberDeclarationSyntax>(methodsInClass)))
                                .Concat<MemberDeclarationSyntax>(group.OfType<BaseTypeDeclarationSyntax>()).ToArray()));
                    var subset = SyntaxFactory.CompilationUnit().WithUsings(source.Usings.Add(SyntaxFactory.UsingDirective(
                            SyntaxFactory.ParseName("Windows.Win32.Foundation.Metadata"))))
                        .AddMembers(members.ToArray()).NormalizeWhitespace();
                    File.WriteAllText(Path.Combine(directory, result.GetProperty("partition").GetString() + ".cs"),
                        subset.ToFullString());
                }
                Assert.Equal(names.OrderBy(value => value, StringComparer.Ordinal),
                    observed.OrderBy(value => value, StringComparer.Ordinal));
            }
            string baseline = Environment.GetEnvironmentVariable("SYSTEM_ENUM_REFERENCE_METADATA");
            Assert.True(File.Exists(baseline), "The immutable winmd supplies existing native dependency types only.");
            using var before = Emit(Path.Combine(component, "before"), architecture,
                memberRemaps: remaps, references: new[] { baseline }, requiredNamespaces: namespaces);
            using var after = Emit(Path.Combine(component, "after"), architecture,
                memberRemaps: remaps, references: new[] { baseline }, requiredNamespaces: namespaces);
            AssertMetadataClosure(before.Reader);
            AssertMetadataClosure(after.Reader);
            if (addedAttributes)
            {
                using var expected = Emit(Path.Combine(component, "expected"), architecture,
                    memberRemaps: remaps, references: new[] { baseline }, requiredNamespaces: namespaces);
                AssertMetadataClosure(expected.Reader);
                Assert.Equal(Snapshot(expected.Reader), Snapshot(after.Reader));
            }
            else
                Assert.Equal(Snapshot(before.Reader), Snapshot(after.Reader));
            foreach (var fact in facts)
            {
                string[] targetName = fact.GetProperty("symbol").GetString().Split("::");
                string name = targetName[0];
                var method = Assert.Single(after.Reader.MethodDefinitions.Select(after.Reader.GetMethodDefinition)
                    .Where(value => after.Reader.GetString(value.Name) == name));
                if (parameterContracts)
                {
                    var parameter = Assert.Single(method.GetParameters().Select(after.Reader.GetParameter)
                        .Where(value => value.SequenceNumber > 0 && after.Reader.GetString(value.Name) == targetName[1]));
                    if (fact.GetProperty("category").GetString() == "associated-enum-parameter")
                    {
                        Assert.Equal(fact.GetProperty("nativeStorage").GetString(),
                            method.DecodeSignature(new SignatureNames(), null).ParameterTypes[parameter.SequenceNumber - 1]);
                        AssertStringAttribute(after.Reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute",
                            fact.GetProperty("enumName").GetString());
                    }
                    else
                        Assert.Single(parameter.GetCustomAttributes().Where(handle =>
                            AttributeName(after.Reader, handle) == "ContainsInteriorPointersAttribute"));
                }
                else if (returnAssociations)
                {
                    Assert.Equal(fact.GetProperty("nativeStorage").GetString(),
                        method.DecodeSignature(new SignatureNames(), null).ReturnType);
                    var target = Assert.Single(method.GetParameters().Select(after.Reader.GetParameter)
                        .Where(value => value.SequenceNumber == 0));
                    AssertStringAttribute(after.Reader, target.GetCustomAttributes(), "AssociatedEnumAttribute",
                        fact.GetProperty("enumName").GetString());
                }
                else
                {
                    string payload = fact.GetProperty("value").GetString().Split('=', 2)[1];
                    Assert.StartsWith("SupportedOSPlatform(", payload);
                    string os = JsonSerializer.Deserialize<string>(payload["SupportedOSPlatform(".Length..^1]);
                    AssertStringAttribute(after.Reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute", os);
                }
            }
            Console.WriteLine($"{architecture}: {facts.Length} exact owned declaration facts, actual imported native signatures, " +
                "calling conventions and namespaces checked without retired sidecar rows; " +
                (addedAttributes ? "only the source-qualified declaration attributes added." : "physical metadata unchanged."));

            static string[] Snapshot(MetadataReader reader) => reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Select(type => WinHttpMigrationTests.SnapshotType(reader, type))
                .OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        [MigrationTheory("SYSTEM_ENUM_BINDINGS", "SYSTEM_ENUM_MIGRATION_ROOT")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void SystemSourceLogicalGroupsPreserveExactEmittedIdentity(string architecture)
        {
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                Environment.GetEnvironmentVariable("SYSTEM_ENUM_MIGRATION_ROOT"), "report.json")));
            var owners = report.RootElement.GetProperty("owners").EnumerateArray().ToArray();
            var logicalGroups = report.RootElement.TryGetProperty("logicalGroups", out var completeGroups)
                ? completeGroups.EnumerateArray()
                : owners.SelectMany(owner => owner.GetProperty("groups").EnumerateArray());
            var expected = logicalGroups
                .ToDictionary(group => group.GetProperty("Group").GetString(), StringComparer.Ordinal);
            var fieldAssociations = owners.SelectMany(owner => owner.GetProperty("associations").EnumerateArray())
                .Where(value => value.TryGetProperty("kind", out var kind) && kind.GetString() == "field").ToArray();
            var interfaceAssociations = owners.SelectMany(owner => owner.GetProperty("associations").EnumerateArray())
                .Where(value => (!value.TryGetProperty("kind", out var kind) || kind.GetString() != "field") &&
                    value.GetProperty("symbol").GetString().Split("::").Length == 3).ToArray();
            var nativeRecords = fieldAssociations.Select(value => value.GetProperty("nativeType").GetString())
                .Concat(interfaceAssociations.Select(value => value.GetProperty("symbol").GetString().Split("::")[0]))
                .ToHashSet(StringComparer.Ordinal);
            var nativeEnums = fieldAssociations.Select(value => value.GetProperty("group").GetString())
                .ToHashSet(StringComparer.Ordinal);
            string generated = Path.Combine(Environment.GetEnvironmentVariable("SYSTEM_ENUM_BINDINGS"), architecture);
            using var results = JsonDocument.Parse(File.ReadAllText(Path.Combine(generated, "results.json")));
            string component = Path.Combine(generated, "logical-groups-component-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(component);
            var observed = new HashSet<string>(StringComparer.Ordinal);
            var sources = new Dictionary<string, CompilationUnitSyntax>(StringComparer.Ordinal);
            foreach (var result in results.RootElement.EnumerateArray())
            {
                Assert.True(result.GetProperty("success").GetBoolean(), result.GetProperty("log").GetString());
                string partition = result.GetProperty("partition").GetString();
                var source = CSharpSyntaxTree.ParseText(File.ReadAllText(
                    result.GetProperty("generatedSource").GetString())).GetCompilationUnitRoot();
                sources.Add(partition, source);
                var headerTypes = CSharpSyntaxTree.ParseText(File.ReadAllText(
                    result.GetProperty("headerTypes").GetString())).GetCompilationUnitRoot();
                var enums = headerTypes.DescendantNodes().OfType<EnumDeclarationSyntax>()
                    .Where(value => expected.ContainsKey(value.Identifier.ValueText)).ToArray();
                foreach (var declaration in enums)
                    observed.Add(declaration.Identifier.ValueText);
                var declarations = enums.Cast<MemberDeclarationSyntax>().Concat(source.DescendantNodes()
                    .OfType<BaseTypeDeclarationSyntax>().Where(declaration =>
                        !declaration.Ancestors().OfType<BaseTypeDeclarationSyntax>().Any() &&
                        ((declaration is StructDeclarationSyntax && nativeRecords.Contains(declaration.Identifier.ValueText)) ||
                         (declaration is EnumDeclarationSyntax && nativeEnums.Contains(declaration.Identifier.ValueText)))));
                var namespaces = declarations.GroupBy(declaration => string.Join(".", declaration.Ancestors()
                    .OfType<BaseNamespaceDeclarationSyntax>().Reverse().Select(value => value.Name.ToString())))
                    .Select(group => SyntaxFactory.NamespaceDeclaration(SyntaxFactory.ParseName(group.Key))
                        .AddMembers(group.ToArray())).ToArray();
                var usings = nativeRecords.Count > 0
                    ? SyntaxFactory.List(headerTypes.Usings.Concat(source.Usings).DistinctBy(value => value.ToString()))
                    : headerTypes.Usings;
                if (interfaceAssociations.Length > 0)
                    usings = SyntaxFactory.List(usings.Append(SyntaxFactory.UsingDirective(
                        SyntaxFactory.ParseName("Windows.Win32.System.Com"))).DistinctBy(value => value.ToString()));
                var subset = SyntaxFactory.CompilationUnit().WithUsings(usings)
                    .AddMembers(namespaces).NormalizeWhitespace();
                File.WriteAllText(Path.Combine(component, partition + ".header-types.cs"), subset.ToFullString());
            }
            Assert.Equal(expected.Keys.OrderBy(value => value, StringComparer.Ordinal),
                observed.OrderBy(value => value, StringComparer.Ordinal));
            var requiredNamespaces = File.ReadAllLines(Path.Combine(
                    WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "requiredNamespacesForNames.rsp"))
                .Select(line => line.Trim().Split('=', 2))
                .Where(parts => parts.Length == 2 && expected.ContainsKey(parts[0]))
                .ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
            string[] references = null;
            if (nativeRecords.Count > 0)
            {
                string baseline = Environment.GetEnvironmentVariable("SYSTEM_ENUM_REFERENCE_METADATA");
                Assert.True(File.Exists(baseline), "Set SYSTEM_ENUM_REFERENCE_METADATA to the immutable baseline for shared native dependencies.");
                references = new[] { baseline };
            }
            using var image = Emit(component, architecture, references: references, requiredNamespaces: requiredNamespaces);
            var reader = image.Reader;
            foreach (var pair in expected)
            {
                var type = FindType(reader, pair.Key);
                Assert.Equal(pair.Value.GetProperty("Namespace").GetString(), reader.GetString(type.Namespace));
                var fields = type.GetFields().Select(reader.GetFieldDefinition).ToArray();
                var storage = Assert.Single(fields.Where(field => reader.GetString(field.Name) == "value__"));
                Assert.Equal(pair.Value.GetProperty("Storage").GetString(),
                    storage.DecodeSignature(new SignatureNames(), null));
                Assert.Equal(pair.Value.GetProperty("Flags").GetBoolean(),
                    type.GetCustomAttributes().Any(handle => AttributeName(reader, handle) == "FlagsAttribute"));
                AssertDoesNotHaveAttribute(reader, type.GetCustomAttributes(), "ScopedEnumAttribute");
                var actual = fields.Where(field => !field.GetDefaultValue().IsNil)
                    .ToDictionary(field => reader.GetString(field.Name), field =>
                    {
                        var constant = reader.GetConstant(field.GetDefaultValue());
                        var blob = reader.GetBlobReader(constant.Value);
                        return constant.TypeCode switch
                        {
                            ConstantTypeCode.UInt16 => blob.ReadUInt16().ToString(),
                            ConstantTypeCode.UInt32 => blob.ReadUInt32().ToString(),
                            ConstantTypeCode.Int32 => blob.ReadInt32().ToString(),
                            _ => throw new InvalidOperationException("Unexpected native logical-group constant storage."),
                        };
                    }, StringComparer.Ordinal);
                var members = pair.Value.GetProperty("Members").EnumerateArray()
                    .ToDictionary(member => member.GetProperty("Name").GetString(),
                        member => member.GetProperty("Value").GetRawText(), StringComparer.Ordinal);
                Assert.Equal(pair.Value.GetProperty("Members").EnumerateArray()
                    .Select(member => member.GetProperty("Name").GetString()),
                    fields.Where(field => !field.GetDefaultValue().IsNil).Select(field => reader.GetString(field.Name)));
                Assert.Equal(members.OrderBy(value => value.Key, StringComparer.Ordinal),
                    actual.OrderBy(value => value.Key, StringComparer.Ordinal));
            }
            foreach (var owner in owners)
            {
                string partition = owner.GetProperty("partitionCandidates").EnumerateArray().First().GetString();
                var methods = sources[partition].DescendantNodes().OfType<MethodDeclarationSyntax>()
                    .ToLookup(method => method.Identifier.ValueText, StringComparer.Ordinal);
                foreach (var association in owner.GetProperty("associations").EnumerateArray())
                {
                    string[] symbol = association.GetProperty("symbol").GetString().Split("::");
                    if (association.TryGetProperty("kind", out var kind) && kind.GetString() == "field")
                    {
                        var record = Assert.Single(sources[partition].DescendantNodes().OfType<StructDeclarationSyntax>()
                            .Where(value => value.Identifier.ValueText == symbol[0] &&
                                !value.Ancestors().OfType<BaseTypeDeclarationSyntax>().Any()));
                        var type = FindType(reader, symbol[0]);
                        foreach (string nested in symbol.Skip(1).SkipLast(1))
                        {
                            record = Assert.Single(record.Members.OfType<StructDeclarationSyntax>()
                                .Where(value => value.Identifier.ValueText == nested));
                            type = reader.GetTypeDefinition(Assert.Single(type.GetNestedTypes()
                                .Where(handle => reader.GetString(reader.GetTypeDefinition(handle).Name) == nested)));
                        }
                        var field = Assert.Single(record.Members.OfType<FieldDeclarationSyntax>()
                            .Where(value => value.Declaration.Variables.Any(variable => variable.Identifier.ValueText == symbol.Last())));
                        Assert.Equal("uint", field.Declaration.Type.ToString());
                        var metadataField = Assert.Single(type.GetFields().Select(reader.GetFieldDefinition)
                            .Where(value => reader.GetString(value.Name) == symbol.Last()));
                        Assert.Equal("UInt32", metadataField.DecodeSignature(new SignatureNames(), null));
                        AssertStringAttribute(reader, metadataField.GetCustomAttributes(), "AssociatedEnumAttribute",
                            association.GetProperty("group").GetString());
                        continue;
                    }
                    Assert.True(symbol.Length is 2 or 3);
                    var method = Assert.Single(methods[symbol[^2]].Where(value => symbol.Length == 2 ||
                        value.Ancestors().OfType<TypeDeclarationSyntax>().Any(type => type.Identifier.ValueText == symbol[0])));
                    var parameter = Assert.Single(method.ParameterList.Parameters
                        .Where(value => value.Identifier.ValueText == symbol[^1]));
                    Assert.Equal("uint", parameter.Type.ToString());
                    var attribute = Assert.Single(parameter.AttributeLists.SelectMany(list => list.Attributes)
                        .Where(value => value.Name.ToString().Split('.').Last() is "AssociatedEnum" or "AssociatedEnumAttribute"));
                    var name = Assert.IsType<LiteralExpressionSyntax>(Assert.Single(attribute.ArgumentList.Arguments).Expression);
                    Assert.Equal(association.GetProperty("group").GetString(), name.Token.ValueText);
                    if (symbol.Length == 3)
                    {
                        var metadataMethod = FindMethod(reader, symbol[0], symbol[1]);
                        var metadataParameter = Assert.Single(metadataMethod.GetParameters().Select(reader.GetParameter)
                            .Where(value => reader.GetString(value.Name) == symbol[2]));
                        Assert.Equal("UInt32", metadataMethod.DecodeSignature(new SignatureNames(), null)
                            .ParameterTypes[metadataParameter.SequenceNumber - 1]);
                        AssertStringAttribute(reader, metadataParameter.GetCustomAttributes(), "AssociatedEnumAttribute",
                            association.GetProperty("group").GetString());
                    }
                }
            }
            if (report.RootElement.TryGetProperty("retainedUses", out var retainedUses))
            {
                var uses = retainedUses.EnumerateArray().ToArray();
                var configured = MetadataUtils.EnumObject.LoadFromFile(Path.Combine(
                        Environment.GetEnvironmentVariable("SYSTEM_ENUM_MIGRATION_ROOT"), "enums.after.json"))
                    .Where(value => value.addUsesTo != null && expected.ContainsKey(value.addUsesTo))
                    .SelectMany(value => value.uses.Select(use => value.addUsesTo + "|" + use));
                Assert.Equal(uses.Select(value => value.GetProperty("group").GetString() + "|" +
                    value.GetProperty("symbol").GetString()).OrderBy(value => value, StringComparer.Ordinal),
                    configured.OrderBy(value => value, StringComparer.Ordinal));
                foreach (var use in uses)
                {
                    string[] symbol = use.GetProperty("symbol").GetString().Split("::");
                    var method = Assert.Single(sources[use.GetProperty("partition").GetString()].DescendantNodes()
                        .OfType<MethodDeclarationSyntax>().Where(value => value.Identifier.ValueText == symbol[0]));
                    var parameter = Assert.Single(method.ParameterList.Parameters
                        .Where(value => value.Identifier.ValueText == symbol[1]));
                    Assert.Equal("uint", parameter.Type.ToString());
                }
            }
            AssertMetadataClosure(reader);
            Console.WriteLine($"{architecture}: {expected.Count} real source-projected logical identities and " +
                $"{expected.Values.Sum(group => group.GetProperty("Members").GetArrayLength())} compiled-native members; " +
                $"{fieldAssociations.Length} native DWORD field associations; " +
                $"{interfaceAssociations.Length} physical COM parameter associations.");
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17")]
        public void NativeEnumTagsResolveAssociationDeclarationsInCAndCpp(
            string architecture, string target, string language, string standard)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
enum VARENUM { VT_EMPTY = 0, VT_I4 = 3 };
typedef struct NATIVE_VARIANT
{
    _Win32_AssociatedEnum_(enum VARENUM) unsigned short vt;
} NATIVE_VARIANT;
enum eAvrfResourceTypes { AvrfResourceHeapAllocation, AvrfResourceHandleTrace, AvrfResourceMax };
_Win32_ImportLibrary_(""verifier.dll"")
unsigned long __stdcall NativeResourceType(
    _Win32_AssociatedEnum_(enum eAvrfResourceTypes) unsigned long ResourceType);
", extraSettings: $"--language\n{language}\n--std\n{standard}\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var field = FindType(reader, "NATIVE_VARIANT").GetFields().Select(reader.GetFieldDefinition).Single();
            Assert.Equal("UInt16", field.DecodeSignature(new SignatureNames(), null));
            AssertStringAttribute(reader, field.GetCustomAttributes(), "AssociatedEnumAttribute", "VARENUM");
            var values = FindType(reader, "VARENUM").GetFields().Select(reader.GetFieldDefinition)
                .Where(value => !value.GetDefaultValue().IsNil)
                .Select(value => reader.GetString(value.Name) + "=" +
                    reader.GetBlobReader(reader.GetConstant(value.GetDefaultValue()).Value).ReadInt32());
            Assert.Equal(new[] { "VT_EMPTY=0", "VT_I4=3" }, values);
            var method = FindMethod(reader, "Apis", "NativeResourceType");
            var parameter = method.GetParameters().Select(reader.GetParameter)
                .Single(value => reader.GetString(value.Name) == "ResourceType");
            Assert.Equal(new[] { "UInt32" }, method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            AssertStringAttribute(reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute", "eAvrfResourceTypes");
            Assert.Equal(new[] { "AvrfResourceHeapAllocation=0", "AvrfResourceHandleTrace=1", "AvrfResourceMax=2" },
                FindType(reader, "eAvrfResourceTypes").GetFields().Select(reader.GetFieldDefinition)
                    .Where(value => !value.GetDefaultValue().IsNil)
                    .Select(value => reader.GetString(value.Name) + "=" +
                        reader.GetBlobReader(reader.GetConstant(value.GetDefaultValue()).Value).ReadInt32()));
            AssertMetadataClosure(reader);
        }

        [NativeMigrationTheory("STATE_HELPERS_MIGRATION_ROOT")]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NormalRegistryFallbackReachesFinalWinmd(string architecture, string target)
        {
            string root = Environment.GetEnvironmentVariable("STATE_HELPERS_MIGRATION_ROOT");
            string source = Path.Combine(root, "scrape-02", "generated", architecture, "Registry.cs");
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, "");
            Directory.CreateDirectory(Path.GetDirectoryName(fixture.Output));
            WriteNormalMethod(source, "GetRegistryValueWithFallbackW", fixture.Output);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var method = FindMethod(reader, "Apis", "GetRegistryValueWithFallbackW");
            var signature = method.DecodeSignature(new SignatureNames(), null);
            Assert.Equal("Int32", signature.ReturnType);
            Assert.Equal(new[]
            {
                "IntPtr", "UInt16*", "IntPtr", "UInt16*", "UInt16*",
                "UInt32", "UInt32*", "Void*", "UInt32", "UInt32*",
            }, signature.ParameterTypes);
            var result = method.GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 0);
            AssertStringAttribute(reader, result.GetCustomAttributes(), "AssociatedEnumAttribute", "WIN32_ERROR");
            var owner = reader.GetTypeDefinition(method.GetDeclaringType());
            Assert.Equal("Windows.Win32.System.Registry", reader.GetString(owner.Namespace));
            var import = method.GetImport();
            Assert.Equal("api-ms-win-core-state-helpers-l1-1-0.dll",
                reader.GetString(reader.GetModuleReference(import.Module).Name));
            AssertMetadataClosure(reader);
        }

        [Fact]
        public void RoutedNativeGroupsHaveNoLegacyDefinitionsAndKeepTheirExactExternalUse()
        {
            string project = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK");
            var groups = new[]
            {
                (Name: "OS_PRODUCT_TYPE", Original: "shared\\ntdef.h", Macro: "_Win32_Enum_"),
                (Name: "OBJECT_ATTRIBUTE_FLAGS", Original: "shared\\ntdef.h", Macro: "_Win32_FlagsEnum_"),
                (Name: "SETUP_DI_DEVICE_CONFIGURATION_FLAGS", Original: "um\\regstr.h", Macro: "_Win32_FlagsEnum_"),
            };
            using var enums = JsonDocument.Parse(File.ReadAllText(Path.Combine(project, "enums.json")));
            var items = enums.RootElement.GetProperty("items").EnumerateArray().ToArray();
            foreach (var group in groups)
            {
                Assert.DoesNotContain(items, item => item.TryGetProperty("name", out var name) &&
                    name.GetString() == group.Name);
                var carriers = File.ReadAllLines(Path.Combine(project, "patches", group.Original + ".patch"))
                    .Where(line => line.StartsWith("+" + group.Macro + "(" + group.Name + ",", StringComparison.Ordinal));
                Assert.Single(carriers);
            }
            var retained = Assert.Single(items.Where(item => item.TryGetProperty("addUsesTo", out var name) &&
                name.GetString() == "OS_PRODUCT_TYPE"));
            Assert.False(retained.TryGetProperty("autoPopulate", out _));
            Assert.False(retained.TryGetProperty("members", out _));
            Assert.Equal("Windows.Win32.System.SystemInformation", retained.GetProperty("namespace").GetString());
            var use = Assert.Single(retained.GetProperty("uses").EnumerateArray());
            Assert.Equal("GetProductInfo", use.GetProperty("method").GetString());
            Assert.Equal("pdwReturnedProductType", use.GetProperty("parameter").GetString());
        }

        [NativeMigrationTheory("ROUTED_NATIVE_ENUM_MIGRATION_ROOT")]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NormalNativeGroupsKeepRoutedWinmdIdentities(string architecture, string target)
        {
            string root = Environment.GetEnvironmentVariable("ROUTED_NATIVE_ENUM_MIGRATION_ROOT");
            string normal = Path.Combine(root, "scrape-02", "generated", architecture);
            var groups = new[]
            {
                (Name: "OS_PRODUCT_TYPE", Namespace: "Windows.Win32.System.SystemInformation", Flags: false),
                (Name: "OBJECT_ATTRIBUTE_FLAGS", Namespace: "Windows.Win32.Foundation", Flags: true),
                (Name: "SETUP_DI_DEVICE_CONFIGURATION_FLAGS",
                    Namespace: "Windows.Win32.Devices.DeviceAndDriverInstallation", Flags: true),
            };
            var requiredNamespaces = RspReader.GetSettingsValues(Path.Combine(
                    WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "requiredNamespacesForNames.rsp"),
                    "--requiredNamespaceForName")
                .Select(line => line.Split('=', 2))
                .Where(pair => pair.Length == 2 && groups.Any(group => group.Name == pair[0]))
                .ToDictionary(pair => pair[0], pair => pair[1]);
            foreach (var group in groups)
                Assert.Equal(group.Namespace, requiredNamespaces[group.Name]);
            var remaps = RspReader.GetSettingsValues(Path.Combine(root, "constants", "enumsRemap.rsp"), "--memberRemap")
                .Select(line => line.Split('=', 2))
                .Where(pair => pair.Length == 2)
                .ToDictionary(pair => pair[0], pair => pair[1]);
            Assert.Equal(new KeyValuePair<string, string>("GetProductInfo::pdwReturnedProductType", "OS_PRODUCT_TYPE"),
                Assert.Single(remaps));
            using var expectedValues = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "normal-values.json")));
            using var sourceGroups = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "authored-03", "report.json")));
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, "");
            string directory = Path.GetDirectoryName(fixture.Output);
            Directory.CreateDirectory(directory);
            foreach (string partition in new[] { "Kernel", "Registry" })
            {
                string fileName = partition + ".header-types.cs";
                File.Copy(Path.Combine(normal, fileName), Path.Combine(directory, fileName));
            }
            WriteNormalMethod(Path.Combine(normal, "SystemInformation.cs"), "GetProductInfo", fixture.Output);
            using var image = Emit(directory, architecture, memberRemaps: remaps, requiredNamespaces: requiredNamespaces);
            var reader = image.Reader;
            using var legacyFixture = new HeaderAnnotationTests.NativeFixture(architecture, target, "");
            string legacyDirectory = Path.GetDirectoryName(legacyFixture.Output);
            Directory.CreateDirectory(legacyDirectory);
            WriteNormalMethod(Path.Combine(normal, "SystemInformation.cs"), "GetProductInfo", legacyFixture.Output);
            var legacyGroups = Directory.GetFiles(Path.Combine(root, "legacy-constants"), "*.enums.cs")
                .SelectMany(path => CSharpSyntaxTree.ParseText(File.ReadAllText(path)).GetRoot().DescendantNodes()
                    .OfType<EnumDeclarationSyntax>()).ToArray();
            foreach (var group in groups)
            {
                var declaration = legacyGroups.Single(value => value.Identifier.ValueText == group.Name);
                var ns = Assert.IsType<NamespaceDeclarationSyntax>(declaration.Parent);
                var bounded = SyntaxFactory.ParseCompilationUnit(
                    "using System; using System.Runtime.InteropServices; using Windows.Win32.Foundation.Metadata;")
                    .AddMembers(ns.WithMembers(SyntaxFactory.SingletonList<MemberDeclarationSyntax>(declaration)));
                File.WriteAllText(Path.Combine(legacyDirectory, group.Name + ".enums.cs"),
                    bounded.NormalizeWhitespace().ToFullString());
            }
            using var legacyImage = Emit(legacyDirectory, architecture,
                memberRemaps: remaps, requiredNamespaces: requiredNamespaces);
            var legacy = legacyImage.Reader;
            foreach (var group in groups)
            {
                var type = FindType(reader, group.Name);
                Assert.Equal(group.Namespace, reader.GetString(type.Namespace));
                Assert.Equal(group.Flags, type.GetCustomAttributes().Any(
                    handle => AttributeName(reader, handle) == "FlagsAttribute"));
                AssertDoesNotHaveAttribute(reader, type.GetCustomAttributes(), "ScopedEnumAttribute");
                var fields = type.GetFields().Select(reader.GetFieldDefinition).ToArray();
                var storage = fields.Single(field => reader.GetString(field.Name) == "value__");
                Assert.Equal("UInt32", storage.DecodeSignature(new SignatureNames(), null));
                var values = fields.Where(field => !field.GetDefaultValue().IsNil).ToDictionary(
                    field => reader.GetString(field.Name), field =>
                    {
                        var constant = reader.GetConstant(field.GetDefaultValue());
                        Assert.Equal(ConstantTypeCode.UInt32, constant.TypeCode);
                        return reader.GetBlobReader(constant.Value).ReadUInt32();
                    });
                var nativeMembers = sourceGroups.RootElement.GetProperty("groups").EnumerateArray()
                    .Single(item => item.GetProperty("name").GetString() == group.Name)
                    .GetProperty("members").EnumerateArray().Select(item => item.GetString())
                    .OrderBy(name => name, StringComparer.Ordinal);
                Assert.Equal(nativeMembers, values.Keys.OrderBy(name => name, StringComparer.Ordinal));
                var expected = expectedValues.RootElement.GetProperty(architecture).GetProperty(group.Name)
                    .EnumerateObject().ToDictionary(item => item.Name, item => item.Value.GetUInt32());
                Assert.Equal(expected.OrderBy(item => item.Key, StringComparer.Ordinal),
                    values.OrderBy(item => item.Key, StringComparer.Ordinal));
                var legacyType = FindType(legacy, group.Name);
                Assert.Equal(group.Namespace, legacy.GetString(legacyType.Namespace));
                Assert.Equal(AttributeValues(legacy, legacyType.GetCustomAttributes()),
                    AttributeValues(reader, type.GetCustomAttributes()));
                var legacyFields = legacyType.GetFields().Select(legacy.GetFieldDefinition).ToArray();
                Assert.Equal("UInt32", legacyFields.Single(field => legacy.GetString(field.Name) == "value__")
                    .DecodeSignature(new SignatureNames(), null));
                var legacyValues = legacyFields.Where(field => !field.GetDefaultValue().IsNil).ToDictionary(
                    field => legacy.GetString(field.Name),
                    field => legacy.GetBlobReader(legacy.GetConstant(field.GetDefaultValue()).Value).ReadUInt32());
                Assert.Equal(legacyValues.OrderBy(item => item.Key, StringComparer.Ordinal),
                    values.OrderBy(item => item.Key, StringComparer.Ordinal));
            }
            var method = FindMethod(reader, "Apis", "GetProductInfo");
            Assert.Equal("Int32", method.DecodeSignature(new SignatureNames(), null).ReturnType);
            Assert.Equal(new[] { "UInt32", "UInt32", "UInt32", "UInt32", "OS_PRODUCT_TYPE*" },
                method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.Equal("Windows.Win32.System.SystemInformation.OS_PRODUCT_TYPE*",
                method.DecodeSignature(new SignatureNames(qualifiedNames: true), null).ParameterTypes[4]);
            var legacyMethod = FindMethod(legacy, "Apis", "GetProductInfo");
            Assert.Equal(legacyMethod.DecodeSignature(new SignatureNames(qualifiedNames: true), null).ParameterTypes.ToArray(),
                method.DecodeSignature(new SignatureNames(qualifiedNames: true), null).ParameterTypes.ToArray());
            var result = method.GetParameters().Select(reader.GetParameter)
                .Single(parameter => reader.GetString(parameter.Name) == "pdwReturnedProductType");
            var legacyResult = legacyMethod.GetParameters().Select(legacy.GetParameter)
                .Single(parameter => legacy.GetString(parameter.Name) == "pdwReturnedProductType");
            Assert.Equal(legacyResult.Attributes, result.Attributes);
            Assert.Equal(AttributeValues(legacy, legacyResult.GetCustomAttributes()),
                AttributeValues(reader, result.GetCustomAttributes()));
            Assert.Equal(AttributeValues(legacy, legacyMethod.GetCustomAttributes()),
                AttributeValues(reader, method.GetCustomAttributes()));
            Assert.Equal(legacy.GetString(legacy.GetModuleReference(legacyMethod.GetImport().Module).Name),
                reader.GetString(reader.GetModuleReference(method.GetImport().Module).Name));
            Assert.Equal("Windows.Win32.System.SystemInformation",
                reader.GetString(reader.GetTypeDefinition(method.GetDeclaringType()).Namespace));
            AssertMetadataClosure(reader);
            AssertMetadataClosure(legacy);
            string physical = Path.Combine(root, "physical", architecture, Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(physical);
            foreach (var output in new[]
            {
                (Directory: directory, Name: "candidate.winmd"),
                (Directory: legacyDirectory, Name: "legacy.winmd"),
            })
                File.Copy(Path.Combine(output.Directory, "Test.winmd"), Path.Combine(physical, output.Name));
            File.WriteAllText(Path.Combine(physical, "observed.json"), JsonSerializer.Serialize(new
            {
                architecture,
                scope = "Three actual source groups plus one unchanged normal API method versus the exact three legacy descriptors.",
                groups = groups.Select(group => new
                {
                    group.Name, group.Namespace, storage = "UInt32", group.Flags,
                    memberCount = expectedValues.RootElement.GetProperty(architecture).GetProperty(group.Name)
                        .EnumerateObject().Count(),
                }),
                preservedUse = "GetProductInfo::pdwReturnedProductType=Windows.Win32.System.SystemInformation.OS_PRODUCT_TYPE*",
                candidateSha256 = Convert.ToHexString(System.Security.Cryptography.SHA256.HashData(
                    File.ReadAllBytes(Path.Combine(physical, "candidate.winmd")))),
                legacySha256 = Convert.ToHexString(System.Security.Cryptography.SHA256.HashData(
                    File.ReadAllBytes(Path.Combine(physical, "legacy.winmd")))),
            }, new JsonSerializerOptions { WriteIndented = true }));

            static string[] AttributeValues(MetadataReader metadata, CustomAttributeHandleCollection attributes)
                => attributes.Select(handle => AttributeName(metadata, handle) + "=" +
                    Convert.ToHexString(metadata.GetBlobBytes(metadata.GetCustomAttribute(handle).Value)))
                    .OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        [Fact]
        public void ExistingNativeNonfloorCategoryKeepsSourceOwnersAndExactStaging()
        {
            string project = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK");
            using var enums = JsonDocument.Parse(File.ReadAllText(Path.Combine(project, "enums.json")));
            var items = enums.RootElement.GetProperty("items").EnumerateArray().ToArray();
            foreach (var group in ExistingNativeNonfloorGroups.Where(group => group.Synthetic))
            {
                Assert.DoesNotContain(items, item => item.TryGetProperty("name", out var name) &&
                    name.GetString() == group.Name);
                Assert.Contains(items, item => item.TryGetProperty("addUsesTo", out var name) &&
                    name.GetString() == group.Name && item.GetProperty("namespace").GetString() == group.Namespace);
                string macro = group.Flags ? "_Win32_FlagsEnum_" : "_Win32_Enum_";
                Assert.Single(File.ReadAllLines(Path.Combine(project, "patches", "um", group.Header + ".patch"))
                    .Where(line => line.StartsWith("+" + macro + "(" + group.Name + ",", StringComparison.Ordinal)));
            }
            var routes = File.ReadAllLines(Path.Combine(project, "requiredNamespacesForNames.rsp"));
            Assert.Contains("DISPATCH_FLAGS=Windows.Win32.System.Com", routes);
            Assert.Contains("VAR_CHANGE_FLAGS=Windows.Win32.System.Variant", routes);
            foreach (string header in new[] { "objbase.h", "pathcch.h" })
                Assert.Contains("+__attribute__((flag_enum))",
                    File.ReadAllLines(Path.Combine(project, "patches", "um", header + ".patch")));
            string compression = File.ReadAllText(Path.Combine(project, "patches", "um", "compressapi.h.patch"));
            Assert.Contains("_Win32_RAIIFree_(CloseCompressor, -1, 0)", compression);
            Assert.Contains("_Win32_RAIIFree_(CloseDecompressor, -1, 0)", compression);
        }

        private static readonly (string Name, string Header, string Namespace, string Storage,
            bool Flags, bool Synthetic, int Members)[] ExistingNativeNonfloorGroups =
        {
            ("ACTIVEOBJECT_FLAGS", "oleauto.h", "Windows.Win32.System.Ole", "UInt32", true, true, 2),
            ("NUMPARSE_FLAGS", "oleauto.h", "Windows.Win32.System.Ole", "UInt32", true, true, 16),
            ("VARCMP", "oleauto.h", "Windows.Win32.System.Ole", "UInt32", false, true, 4),
            ("DISPATCH_FLAGS", "oleauto.h", "Windows.Win32.System.Com", "UInt16", true, true, 4),
            ("VAR_CHANGE_FLAGS", "oleauto.h", "Windows.Win32.System.Variant", "UInt16", true, true, 8),
            ("PICTYPE", "olectl.h", "Windows.Win32.System.Ole", "Int16", false, true, 6),
            ("LOAD_PICTURE_FLAGS", "olectl.h", "Windows.Win32.System.Ole", "UInt32", true, true, 4),
            ("STGM", "coml2api.h", "Windows.Win32.System.Com", "UInt32", true, true, 18),
            ("STGFMT", "coml2api.h", "Windows.Win32.System.Com.StructuredStorage", "UInt32", false, true, 6),
            ("COINIT", "objbase.h", "Windows.Win32.System.Com", "Int32", true, false, 4),
            ("PATHCCH_OPTIONS", "pathcch.h", "Windows.Win32.UI.Shell", "UInt32", true, false, 8),
        };

        [NativeMigrationTheory("EXISTING_NATIVE_NONFLOOR_ROOT")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void NormalExistingNativeGroupsKeepPhysicalNamesStorageFlagsAndValues(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("EXISTING_NATIVE_NONFLOOR_ROOT");
            string normal = Path.Combine(root, architecture == "x64" ? "scrape" : "scrape-" + architecture,
                "generated", architecture);
            string directory = Path.Combine(root, "physical", "groups", architecture, Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            var names = ExistingNativeNonfloorGroups.Select(group => group.Name).Append("COINITBASE").ToHashSet();
            var observed = new HashSet<string>();
            foreach (string path in Directory.EnumerateFiles(normal, "*.cs"))
            {
                var source = CSharpSyntaxTree.ParseText(File.ReadAllText(path)).GetCompilationUnitRoot();
                var namespaces = source.Members.OfType<NamespaceDeclarationSyntax>().Select(ns =>
                    ns.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(ns.Members
                        .OfType<EnumDeclarationSyntax>().Where(type => names.Contains(type.Identifier.ValueText)))))
                    .Where(ns => ns.Members.Count != 0).ToArray();
                foreach (var type in namespaces.SelectMany(ns => ns.Members).OfType<EnumDeclarationSyntax>())
                    Assert.True(observed.Add(type.Identifier.ValueText), "A source group must have one normal declaration.");
                if (namespaces.Length == 0)
                    continue;
                var bounded = SyntaxFactory.ParseCompilationUnit(
                    "using System; using Windows.Win32.Foundation.Metadata;")
                    .AddMembers(namespaces);
                File.WriteAllText(Path.Combine(directory, Path.GetFileName(path)),
                    bounded.NormalizeWhitespace().ToFullString());
            }
            Assert.Equal(names.OrderBy(name => name), observed.OrderBy(name => name));
            using var baselinePaths = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "frozen-baseline-types.json")));
            using var baseline = new MetadataImage(baselinePaths.RootElement.GetProperty("path").GetString());
            using var candidate = Emit(directory, architecture, requiredNamespaces:
                ExistingNativeNonfloorGroups.ToDictionary(group => group.Name, group => group.Namespace));
            var values = new Dictionary<string, string[]>();
            foreach (var group in ExistingNativeNonfloorGroups)
            {
                var current = FindType(candidate.Reader, group.Name);
                var old = FindType(baseline.Reader, group.Name);
                Assert.Equal(group.Namespace, candidate.Reader.GetString(current.Namespace));
                Assert.Equal(group.Namespace, baseline.Reader.GetString(old.Namespace));
                foreach (var pair in new[] { (candidate.Reader, current), (baseline.Reader, old) })
                {
                    var storage = pair.Item2.GetFields().Select(pair.Item1.GetFieldDefinition)
                        .Single(field => pair.Item1.GetString(field.Name) == "value__");
                    Assert.Equal(group.Storage, storage.DecodeSignature(new SignatureNames(), null));
                    Assert.Equal(group.Flags, pair.Item2.GetCustomAttributes().Any(
                        handle => AttributeName(pair.Item1, handle) == "FlagsAttribute"));
                    AssertDoesNotHaveAttribute(pair.Item1, pair.Item2.GetCustomAttributes(), "ScopedEnumAttribute");
                }
                string[] expected = Members(baseline.Reader, old);
                string[] actual = Members(candidate.Reader, current);
                Assert.Equal(group.Members, actual.Length);
                Assert.Equal(expected, actual);
                values[group.Name] = actual;
            }
            AssertMetadataClosure(candidate.Reader);
            File.WriteAllText(Path.Combine(directory, "observed.json"), JsonSerializer.Serialize(new
            {
                architecture,
                scope = "Nine actual source groups and two native flag enums versus eleven named frozen physical types.",
                nativeOriginals = 5,
                sourceGroups = 9,
                sourceGroupMembers = 68,
                types = ExistingNativeNonfloorGroups.Select(group => new
                {
                    group.Name, group.Namespace, group.Storage, group.Flags, group.Synthetic, group.Members,
                    values = values[group.Name],
                }),
                candidatePath = Path.Combine(directory, "Test.winmd"),
                baselinePath = baselinePaths.RootElement.GetProperty("path").GetString(),
            }, new JsonSerializerOptions { WriteIndented = true }));

            static string[] Members(MetadataReader reader, TypeDefinition type)
                => type.GetFields().Select(reader.GetFieldDefinition)
                    .Where(field => reader.GetString(field.Name) != "value__")
                    .Select(field =>
                    {
                        var constant = reader.GetConstant(field.GetDefaultValue());
                        return reader.GetString(field.Name) + "=" + constant.TypeCode + ":" +
                            Convert.ToHexString(reader.GetBlobBytes(constant.Value));
                    }).OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        [NativeMigrationTheory("EXISTING_NATIVE_NONFLOOR_ROOT")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void NormalExistingNativeProducersKeepExactCleanupTargetsAndNativeShapes(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("EXISTING_NATIVE_NONFLOOR_ROOT");
            string normal = Path.Combine(root, architecture == "x64" ? "scrape" : "scrape-" + architecture,
                "generated", architecture);
            string directory = Path.Combine(root, "physical", "producers", architecture, Guid.NewGuid().ToString("N"));
            string controlDirectory = Path.Combine(directory, "legacy");
            string candidateDirectory = Path.Combine(directory, "candidate");
            Directory.CreateDirectory(controlDirectory);
            Directory.CreateDirectory(candidateDirectory);
            using var baselinePaths = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "frozen-baseline-types.json")));
            string baselinePath = baselinePaths.RootElement.GetProperty("path").GetString();
            using var archive = System.IO.Compression.ZipFile.OpenRead(
                Path.Combine(Path.GetDirectoryName(baselinePath), "exact-source-inputs.zip"));
            var selections = new[]
            {
                (File: "Memory", Methods: new[] { "HeapCreate", "HeapDestroy" }),
                (File: "Perf", Methods: new[] { "PerfStartProvider", "PerfStartProviderEx", "PerfOpenQueryHandle",
                    "PerfStopProvider", "PerfCloseQueryHandle" }),
                (File: "IpHlp", Methods: new[] { "IcmpCreateFile", "Icmp6CreateFile", "IcmpSendEcho", "IcmpSendEcho2",
                    "IcmpSendEcho2Ex", "IcmpParseReplies", "IcmpCloseHandle" }),
                (File: "ActiveDirectory", Methods: new[] { "DsGetDcOpenA", "DsGetDcOpenW", "DsGetDcCloseW" }),
                (File: "CmpApi", Methods: new[] { "CreateCompressor", "CreateDecompressor",
                    "CloseCompressor", "CloseDecompressor" }),
                (File: "ComOle", Methods: Array.Empty<string>()),
            };
            foreach (var selection in selections)
            {
                var entry = archive.GetEntry(architecture + "\\" + selection.File + ".cs") ??
                    archive.GetEntry("common\\" + selection.File + ".cs");
                Assert.NotNull(entry);
                using var stream = new StreamReader(entry.Open());
                WriteSelected(stream.ReadToEnd(), selection.File, selection.Methods, controlDirectory);
                WriteSelected(File.ReadAllText(Path.Combine(normal, selection.File + ".cs")),
                    selection.File, selection.Methods, candidateDirectory);
            }
            var oldFacts = new Dictionary<string, string>
            {
                ["HeapCreate::return"] = "[RAIIFree(\"HeapDestroy\")]",
                ["PerfOpenQueryHandle::phQuery"] = "[RAIIFree(\"PerfCloseQueryHandle\")]",
                ["PerfStartProvider::phProvider"] = "[RAIIFree(\"PerfStopProvider\")]",
                ["PerfStartProviderEx::Provider"] = "[RAIIFree(\"PerfStopProvider\")]",
                ["IcmpCreateFile::return"] = "[RAIIFree(\"IcmpCloseHandle\")]",
                ["Icmp6CreateFile::return"] = "[RAIIFree(\"IcmpCloseHandle\")]",
                ["DsGetDcOpenA::RetGetDcContext"] = "[RAIIFree(\"DsGetDcCloseW\")]",
                ["DsGetDcOpenW::RetGetDcContext"] = "[RAIIFree(\"DsGetDcCloseW\")]",
                ["PICTDESC::picType"] = "[AssociatedEnum(\"PICTYPE\")]",
            };
            foreach (string method in new[] { "IcmpSendEcho", "IcmpSendEcho2", "IcmpSendEcho2Ex", "IcmpParseReplies" })
                oldFacts.Add(method + "::ReplyBuffer", "[ContainsInteriorPointers]");
            using var control = Emit(controlDirectory, architecture, memberRemaps: oldFacts, references: new[] { baselinePath });
            using var candidate = Emit(candidateDirectory, architecture, references: new[] { baselinePath });
            AssertMetadataClosure(control.Reader);
            AssertMetadataClosure(candidate.Reader);
            var before = control.Reader.TypeDefinitions.Select(control.Reader.GetTypeDefinition).Where(SelectedType)
                .ToDictionary(type => control.Reader.GetString(type.Namespace) + "." + control.Reader.GetString(type.Name));
            var after = candidate.Reader.TypeDefinitions.Select(candidate.Reader.GetTypeDefinition)
                .Where(type => candidate.Reader.GetString(type.Name) is "Apis" or "PICTDESC")
                .ToDictionary(type => candidate.Reader.GetString(type.Namespace) + "." + candidate.Reader.GetString(type.Name));
            Assert.Equal(before.Keys.OrderBy(value => value), after.Keys.OrderBy(value => value));
            foreach (string name in before.Keys)
            {
                if (name != "Windows.Win32.Storage.Compression.Apis")
                    Assert.Equal(WinHttpMigrationTests.SnapshotType(control.Reader, before[name]),
                        WinHttpMigrationTests.SnapshotType(candidate.Reader, after[name]));
            }
            foreach (var creation in new[]
            {
                (Method: "CreateCompressor", Parameter: "CompressorHandle", Cleanup: "CloseCompressor"),
                (Method: "CreateDecompressor", Parameter: "DecompressorHandle", Cleanup: "CloseDecompressor"),
            })
            {
                var old = FindApiMethod(control.Reader, creation.Method);
                var current = FindApiMethod(candidate.Reader, creation.Method);
                var oldSignature = old.DecodeSignature(new SignatureNames(qualifiedNames: true), null);
                var signature = current.DecodeSignature(new SignatureNames(qualifiedNames: true), null);
                Assert.Equal(oldSignature.ReturnType, signature.ReturnType);
                Assert.Equal(oldSignature.ParameterTypes.ToArray(), signature.ParameterTypes.ToArray());
                var parameter = current.GetParameters().Select(candidate.Reader.GetParameter)
                    .Single(value => candidate.Reader.GetString(value.Name) == creation.Parameter);
                Assert.True(parameter.Attributes.HasFlag(ParameterAttributes.Out));
                AssertStringAttribute(candidate.Reader, parameter.GetCustomAttributes(), "RAIIFreeAttribute", creation.Cleanup);
                Assert.Equal(new long[] { -1, 0 },
                    ReadInvalidValues(candidate.Reader, parameter.GetCustomAttributes()).OrderBy(value => value));
            }
            foreach (string cleanup in new[] { "CloseCompressor", "CloseDecompressor" })
            {
                var old = FindApiMethod(control.Reader, cleanup);
                var current = FindApiMethod(candidate.Reader, cleanup);
                var oldSignature = old.DecodeSignature(new SignatureNames(qualifiedNames: true), null);
                var signature = current.DecodeSignature(new SignatureNames(qualifiedNames: true), null);
                Assert.Equal(oldSignature.ReturnType, signature.ReturnType);
                Assert.Equal(oldSignature.ParameterTypes.ToArray(), signature.ParameterTypes.ToArray());
                Assert.Equal(old.Attributes, current.Attributes);
                var oldImport = old.GetImport();
                var import = current.GetImport();
                Assert.Equal(oldImport.Attributes, import.Attributes);
                Assert.Equal(control.Reader.GetString(oldImport.Name), candidate.Reader.GetString(import.Name));
                Assert.Equal(control.Reader.GetString(control.Reader.GetModuleReference(oldImport.Module).Name),
                    candidate.Reader.GetString(candidate.Reader.GetModuleReference(import.Module).Name));
            }
            File.WriteAllText(Path.Combine(directory, "observed.json"), JsonSerializer.Serialize(new
            {
                architecture,
                scope = "Actual normal producers, all seven cleanup declarations including forwards, and PICTDESC versus retained frozen normal source and thirteen exact legacy attribute rows.",
                retainedLegacyHandleObjects = new[] { "COMPRESSOR_HANDLE", "DECOMPRESSOR_HANDLE" },
                migratedLegacyAttributeRows = 13,
                newProducerCleanupAndInvalidSetContracts = 2,
                candidatePath = Path.Combine(candidateDirectory, "Test.winmd"),
                controlPath = Path.Combine(controlDirectory, "Test.winmd"),
                referencePath = baselinePath,
                noWholeSdkImageOrApiAcceptance = true,
            }, new JsonSerializerOptions { WriteIndented = true }));

            bool SelectedType(TypeDefinition type)
                => control.Reader.GetString(type.Name) is "Apis" or "PICTDESC";

            static MethodDefinition FindApiMethod(MetadataReader reader, string name)
                => reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                    .Single(method => reader.GetString(method.Name) == name);

            static void WriteSelected(string text, string file, string[] names, string output)
            {
                var source = CSharpSyntaxTree.ParseText(text).GetCompilationUnitRoot();
                var found = new HashSet<string>();
                var namespaces = source.Members.OfType<NamespaceDeclarationSyntax>().Select(ns =>
                {
                    var members = new List<MemberDeclarationSyntax>();
                    foreach (var declaration in ns.Members)
                    {
                        if (declaration is ClassDeclarationSyntax api)
                        {
                            var methods = api.Members.OfType<MethodDeclarationSyntax>()
                                .Where(method => names.Contains(method.Identifier.ValueText))
                                .GroupBy(method => method.Identifier.ValueText)
                                .SelectMany(group =>
                                {
                                    if (group.Key == "PerfStartProvider")
                                    {
                                        Assert.Equal(2, group.Count());
                                        // The exact legacy slot uses phProvider; native controls cover both HANDLE*/PHANDLE declarations.
                                        return new[] { group.Single(method => method.ParameterList.Parameters.Last()
                                            .Identifier.ValueText == "phProvider") };
                                    }
                                    if (group.Key is "HeapDestroy" or "PerfStopProvider" or "PerfCloseQueryHandle" or
                                        "IcmpCloseHandle" or "DsGetDcCloseW" or "CloseCompressor" or "CloseDecompressor")
                                        return group.ToArray();
                                    return new[] { Assert.Single(group) };
                                })
                                .OrderBy(method => method.Identifier.ValueText, StringComparer.Ordinal).ToArray();
                            foreach (string method in methods.Select(method => method.Identifier.ValueText).Distinct())
                                Assert.True(found.Add(method));
                            if (methods.Length != 0)
                                members.Add(api.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(methods)));
                        }
                        if (file == "ComOle" && declaration is StructDeclarationSyntax record &&
                            record.Identifier.ValueText == "PICTDESC")
                        {
                            Assert.True(found.Add("PICTDESC"));
                            members.Add(record);
                        }
                    }
                    return ns.WithMembers(SyntaxFactory.List(members));
                }).Where(ns => ns.Members.Count != 0).ToArray();
                Assert.Equal((file == "ComOle" ? new[] { "PICTDESC" } : names).OrderBy(name => name),
                    found.OrderBy(name => name));
                var bounded = source.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(namespaces));
                File.WriteAllText(Path.Combine(output, file + ".cs"), bounded.NormalizeWhitespace().ToFullString());
            }
        }

        [MigrationTheory("SDK_CONTRACT_FIX_NORMAL_ROOT", "WINHTTP_MIGRATION_OLD")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void NormalLogicalGroupRepairsKeepNativeStorageAndExactAssociations(string architecture)
        {
            string normal = Environment.GetEnvironmentVariable("SDK_CONTRACT_FIX_NORMAL_ROOT");
            var namespaces = RspReader.GetSettingsValues(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                    "generation", "WinSDK", "requiredNamespacesForNames.rsp"), "--requiredNamespaceForName")
                .Where(line => !line.StartsWith("#", StringComparison.Ordinal))
                .Select(line => line.Split('=', 2)).ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
            using var before = Component("before");
            using var after = Component("after");
            using var old = new MetadataImage(Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_OLD"));
            var reader = after.Reader;
            var html = FindType(reader, "HTML_HELP_COMMAND");
            var oldHtml = FindType(old.Reader, "HTML_HELP_COMMAND");
            Assert.Equal(WinHttpMigrationTests.SnapshotType(old.Reader, oldHtml),
                WinHttpMigrationTests.SnapshotType(reader, html));
            Assert.Equal(oldHtml.GetFields().Select(old.Reader.GetFieldDefinition).Select(value => old.Reader.GetString(value.Name)),
                html.GetFields().Select(reader.GetFieldDefinition).Select(value => reader.GetString(value.Name)));
            var snmp = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Namespace) == "Windows.Win32.NetworkManagement.Snmp" &&
                reader.GetString(type.Name) == "Apis");
            foreach (var (name, sequence, group) in new[]
            {
                ("SnmpMgrGetTrap", 3, "SNMP_GENERICTRAP"),
                ("SnmpMgrGetTrapEx", 4, "SNMP_GENERICTRAP"),
                ("SnmpMgrRequest", 4, "SNMP_ERROR_STATUS"),
            })
            {
                var method = snmp.GetMethods().Select(reader.GetMethodDefinition)
                    .Single(value => reader.GetString(value.Name) == name);
                var parameter = method.GetParameters().Select(reader.GetParameter)
                    .Single(value => value.SequenceNumber == sequence);
                AssertStringAttribute(reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute", group);
                Assert.Equal("Int32*", method.DecodeSignature(new SignatureNames(), null).ParameterTypes[sequence - 1]);
                Assert.Equal("mgmtapi.dll", reader.GetString(reader.GetModuleReference(method.GetImport().Module).Name));
            }
            var l2 = FindType(reader, "L2_NOTIFICATION_DATA");
            Assert.Equal("Windows.Win32.NetworkManagement.WiFi", reader.GetString(l2.Namespace));
            var field = l2.GetFields().Select(reader.GetFieldDefinition)
                .Single(value => reader.GetString(value.Name) == "NotificationSource");
            Assert.Equal("UInt32", field.DecodeSignature(new SignatureNames(), null));
            AssertStringAttribute(reader, field.GetCustomAttributes(), "AssociatedEnumAttribute", "WLAN_NOTIFICATION_SOURCES");
            var wlan = FindType(reader, "WLAN_NOTIFICATION_SOURCES");
            Assert.Equal("Windows.Win32.NetworkManagement.WiFi", reader.GetString(wlan.Namespace));
            Assert.Equal("UInt32", wlan.GetFields().Select(reader.GetFieldDefinition)
                .Single(value => reader.GetString(value.Name) == "value__").DecodeSignature(new SignatureNames(), null));

            var expected = new HashSet<(string Type, string Method, string Slot)>
            {
                ("Windows.Win32.NetworkManagement.Snmp.Apis", "SnmpMgrGetTrap", "3"),
                ("Windows.Win32.NetworkManagement.Snmp.Apis", "SnmpMgrGetTrapEx", "4"),
                ("Windows.Win32.NetworkManagement.Snmp.Apis", "SnmpMgrRequest", "4"),
                ("Windows.Win32.NetworkManagement.WiFi.L2_NOTIFICATION_DATA", "", "NotificationSource"),
            };
            var oldTypes = Snapshots(before.Reader);
            var newTypes = Snapshots(reader);
            Assert.Equal(oldTypes.Keys.OrderBy(value => value, StringComparer.Ordinal),
                newTypes.Keys.OrderBy(value => value, StringComparer.Ordinal));
            foreach (string type in oldTypes.Keys)
            {
                if (type.EndsWith(".HTML_HELP_COMMAND", StringComparison.Ordinal))
                    continue;
                string[] oldRows = oldTypes[type].Split('\n');
                string[] newRows = newTypes[type].Split('\n');
                Assert.Equal(oldRows.Length, newRows.Length);
                string method = "";
                for (int i = 0; i < oldRows.Length; i++)
                {
                    string[] parts = newRows[i].Split('|');
                    if (parts[0] == "M")
                        method = parts[1];
                    if (oldRows[i] == newRows[i])
                        continue;
                    Assert.Contains(parts[0], new[] { "F", "P" });
                    Assert.True(expected.Remove((type, parts[0] == "F" ? "" : method, parts[1])), newRows[i]);
                    int attributes = parts[0] == "F" ? 7 : 5;
                    string[] values = parts[attributes].Split(',', StringSplitOptions.RemoveEmptyEntries);
                    Assert.Single(values.Where(value => value.StartsWith(
                        "Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute:", StringComparison.Ordinal)));
                    parts[attributes] = string.Join(",", values.Where(value => !value.StartsWith(
                        "Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute:", StringComparison.Ordinal)));
                    Assert.Equal(oldRows[i], string.Join("|", parts));
                }
            }
            Assert.Empty(expected);

            MetadataImage Component(string leg)
            {
                string directory = Path.Combine(normal, "physical", architecture, leg);
                Directory.CreateDirectory(directory);
                foreach (string source in Directory.GetFiles(Path.Combine(normal, leg, architecture), "*.cs"))
                    File.Copy(source, Path.Combine(directory, Path.GetFileName(source)), overwrite: true);
                var reductions = File.ReadLines(Path.Combine(normal, leg, architecture,
                        "emitter.autoFnPtr.crossarch.generated.rsp"))
                    .Where(line => !line.StartsWith("--", StringComparison.Ordinal) && !string.IsNullOrWhiteSpace(line))
                    .ToHashSet(StringComparer.Ordinal);
                return Emit(directory, architecture, reductions,
                    references: new[] { Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_OLD") },
                    requiredNamespaces: namespaces);
            }
            static Dictionary<string, string> Snapshots(MetadataReader value) => value.TypeDefinitions
                .Select(value.GetTypeDefinition).ToDictionary(type => Key(value, type),
                    type => WinHttpMigrationTests.SnapshotType(value, type), StringComparer.Ordinal);
            static string Key(MetadataReader value, TypeDefinition type) => type.GetDeclaringType().IsNil
                ? value.GetString(type.Namespace) + "." + value.GetString(type.Name)
                : Key(value, value.GetTypeDefinition(type.GetDeclaringType())) + "+" + value.GetString(type.Name);
        }

        [MigrationTheory("SDK_CONTRACT_FIX_BEFORE_HEADERS", "SDK_CONTRACT_FIX_AFTER_HEADERS", "WINHTTP_NATIVE_TOOLSET_INCLUDE")]
        [InlineData("x86", "i686-pc-windows-msvc", "c")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++")]
        public void LogicalGroupContractRepairPatchesPreserveNativeAbiAndSal(string architecture, string target, string language)
        {
            string before = Environment.GetEnvironmentVariable("SDK_CONTRACT_FIX_BEFORE_HEADERS");
            string after = Environment.GetEnvironmentVariable("SDK_CONTRACT_FIX_AFTER_HEADERS");
            foreach (var (partition, headers) in new[]
            {
                ("HtmlHelp", new[] { "htmlhelp.h" }),
                ("Snmp", new[] { "snmp.h", "mgmtapi.h" }),
                ("NWifi", new[] { "wlanapi.h", "l2cmn.h" }),
            })
            {
                var oldSal = new List<string>();
                var newSal = new List<string>();
                string source = "#define SECURITY_WIN32\n#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n" +
                    string.Join("\n", headers.Select(header => "#include <" + header + ">")) + "\n";
                Assert.Equal(WinHttpNativeControlTests.Surface(WinHttpMigrationTests.RepositoryRoot, before,
                        partition, architecture, target, headers, "", sourceText: source, salAnnotations: oldSal, language: language),
                    WinHttpNativeControlTests.Surface(WinHttpMigrationTests.RepositoryRoot, after,
                        partition, architecture, target, headers, "", sourceText: source, salAnnotations: newSal, language: language));
                Assert.Equal(oldSal, newSal);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void MidlParameterDirectionsReachPhysicalMetadataWithoutChangingPointerDefaults(
            string architecture, string target, bool annotationsEnabled)
        {
            const string parameters = @"/* [in] */ unsigned* input,
    /* [out] */ unsigned* output,
    /* [in, out] */ unsigned* updated,
    unsigned* ordinary,
    const unsigned* constant,
    /* This prose uses [in] as an example, not a parameter contract. */ unsigned* prose";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef int HRESULT;
extern ""C"" HRESULT __stdcall NativeDirections(" + parameters + @");
typedef HRESULT (__stdcall* PFN_DIRECTIONS)(" + parameters + @");
struct __declspec(uuid(""0b38dfbb-3bb3-4ab1-b2f1-2c3e2059246a"")) IDirections {
    virtual HRESULT __stdcall Apply(" + parameters + @") = 0;
    virtual HRESULT __stdcall Sal(
        /* [in] */ _In_opt_ unsigned* input,
        /* [out] */ _Out_ unsigned* output,
        /* [in][out] */ _Inout_ unsigned* updated,
        /* [retval][out] */ _Out_retval_ unsigned* result) = 0;
    virtual HRESULT __stdcall Nullness(/* [out] */ _Notnull_ unsigned* result) = 0;
    virtual HRESULT __stdcall MidlRetval(/* [retval][out] */ unsigned* result) = 0;
};
", annotationsEnabled: annotationsEnabled);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var defaults = ParameterAttributes.In | ParameterAttributes.Out;
            var expected = new[]
            {
                annotationsEnabled ? ParameterAttributes.In : defaults,
                annotationsEnabled ? ParameterAttributes.Out : defaults,
                defaults,
                defaults,
                ParameterAttributes.In,
                defaults,
            };
            foreach (var (owner, name) in new[]
            {
                ("Apis", "NativeDirections"), ("PFN_DIRECTIONS", "Invoke"), ("IDirections", "Apply"),
            })
            {
                var method = FindMethod(reader, owner, name);
                var actual = method.GetParameters().Select(reader.GetParameter)
                    .Where(parameter => parameter.SequenceNumber != 0).ToArray();
                Assert.Equal(expected, actual.Select(parameter => parameter.Attributes));
                Assert.Equal(Enumerable.Repeat("UInt32*", expected.Length),
                    method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            }

            var sal = FindMethod(reader, "IDirections", "Sal").GetParameters().Select(reader.GetParameter)
                .Where(parameter => parameter.SequenceNumber != 0).ToArray();
            Assert.Equal(new[]
            {
                ParameterAttributes.In | ParameterAttributes.Optional,
                ParameterAttributes.Out,
                defaults,
                ParameterAttributes.Out,
            }, sal.Select(parameter => parameter.Attributes));
            Assert.Single(sal[3].GetCustomAttributes().Where(handle => AttributeName(reader, handle) == "RetValAttribute"));

            var nullness = FindMethod(reader, "IDirections", "Nullness").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 1);
            Assert.Equal(annotationsEnabled ? ParameterAttributes.Out : defaults, nullness.Attributes);

            var retval = FindMethod(reader, "IDirections", "MidlRetval").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 1);
            Assert.Equal(annotationsEnabled ? ParameterAttributes.Out : defaults, retval.Attributes);
            Assert.Equal(annotationsEnabled ? 1 : 0,
                retval.GetCustomAttributes().Count(handle => AttributeName(reader, handle) == "RetValAttribute"));
            Assert.False(retval.Attributes.HasFlag(ParameterAttributes.Retval));
            AssertMetadataClosure(reader);
        }

        [MigrationTheory("SDK_MIDL_DIRECTION_NORMAL_ROOT", "SDK_MIDL_DIRECTION_BEFORE_ROOT", "WINHTTP_MIGRATION_OLD")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void NormalDShowMidlDirectionsChangeOnlyPhysicalParameterDirections(string architecture)
        {
            string normal = Environment.GetEnvironmentVariable("SDK_MIDL_DIRECTION_NORMAL_ROOT");
            string beforeRoot = Environment.GetEnvironmentVariable("SDK_MIDL_DIRECTION_BEFORE_ROOT");
            string beforeSource = Path.Combine(beforeRoot, architecture, "Media.DShow.cs");
            string afterSource = Path.Combine(normal, "obj", "generated", architecture, "Media.DShow.cs");
            Assert.True(File.Exists(afterSource), "Each target requires its own actual normal producer output.");
            var reductions = File.ReadLines(Path.Combine(beforeRoot, "emitter.autoFnPtr.crossarch.generated.rsp"))
                .Where(line => !line.StartsWith("--", StringComparison.Ordinal) && !string.IsNullOrWhiteSpace(line))
                .ToHashSet(StringComparer.Ordinal);
            var namespaces = RspReader.GetSettingsValues(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                    "generation", "WinSDK", "requiredNamespacesForNames.rsp"), "--requiredNamespaceForName")
                .Where(line => !line.StartsWith("#", StringComparison.Ordinal))
                .Select(line => line.Split('=', 2)).ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
            using var before = Component("before", beforeSource);
            using var after = Component("after", afterSource);
            var oldTypes = Snapshots(before.Reader);
            var newTypes = Snapshots(after.Reader);
            Assert.Equal(oldTypes.Keys.OrderBy(value => value, StringComparer.Ordinal),
                newTypes.Keys.OrderBy(value => value, StringComparer.Ordinal));
            var differences = new List<object>();
            foreach (string type in oldTypes.Keys)
            {
                string[] oldRows = oldTypes[type].Split('\n');
                string[] newRows = newTypes[type].Split('\n');
                Assert.Equal(oldRows.Length, newRows.Length);
                string method = null;
                int ordinal = 0;
                var overloads = new Dictionary<string, int>(StringComparer.Ordinal);
                for (int i = 0; i < oldRows.Length; i++)
                {
                    if (oldRows[i].StartsWith("M|", StringComparison.Ordinal))
                    {
                        method = oldRows[i].Split('|')[1];
                        ordinal = overloads.GetValueOrDefault(method);
                        overloads[method] = ordinal + 1;
                    }
                    if (oldRows[i] == newRows[i])
                        continue;
                    string[] oldFields = oldRows[i].Split('|');
                    string[] newFields = newRows[i].Split('|');
                    Assert.Equal("P", oldFields[0]);
                    Assert.Equal("P", newFields[0]);
                    var oldFlags = Enum.Parse<ParameterAttributes>(oldFields[3]);
                    var newFlags = Enum.Parse<ParameterAttributes>(newFields[3]);
                    const ParameterAttributes direction = ParameterAttributes.In | ParameterAttributes.Out;
                    Assert.Equal(oldFlags & ~direction, newFlags & ~direction);
                    differences.Add(new
                    {
                        type, method, overloadOrdinal = ordinal, sequence = int.Parse(oldFields[1]),
                        parameter = oldFields[2], before = oldRows[i], after = newRows[i],
                    });
                    oldFields[3] = newFields[3];
                    Assert.Equal(oldFields, newFields);
                }
            }
            Assert.NotEmpty(differences);
            var oldParameter = FindMethod(before.Reader, "IVMRMixerControl9", "GetBackgroundClr")
                .GetParameters().Select(before.Reader.GetParameter).Single(parameter => parameter.SequenceNumber == 1);
            var newParameter = FindMethod(after.Reader, "IVMRMixerControl9", "GetBackgroundClr")
                .GetParameters().Select(after.Reader.GetParameter).Single(parameter => parameter.SequenceNumber == 1);
            Assert.Equal(ParameterAttributes.In | ParameterAttributes.Out, oldParameter.Attributes);
            Assert.Equal(ParameterAttributes.In, newParameter.Attributes);
            string report = Path.Combine(normal, "physical", architecture, "direction-deltas.json");
            File.WriteAllText(report, JsonSerializer.Serialize(new
            {
                architecture, beforeSource, afterSource, physicalTypes = newTypes.Count, differences,
                scope = "Complete actual normal source through the existing cleaner/emitter; external OLD types only. Native binding and full-image acceptance are separate gates.",
            }, new JsonSerializerOptions { WriteIndented = true }));

            MetadataImage Component(string leg, string source)
            {
                string directory = Path.Combine(normal, "physical", architecture, leg);
                Directory.CreateDirectory(directory);
                File.Copy(source, Path.Combine(directory, "Media.DShow.cs"), overwrite: true);
                return Emit(directory, architecture, reductions,
                    references: new[] { Environment.GetEnvironmentVariable("WINHTTP_MIGRATION_OLD") },
                    requiredNamespaces: namespaces);
            }
            static Dictionary<string, string> Snapshots(MetadataReader reader) => reader.TypeDefinitions
                .Select(reader.GetTypeDefinition).ToDictionary(type => Key(reader, type),
                    type => WinHttpMigrationTests.SnapshotType(reader, type), StringComparer.Ordinal);
            static string Key(MetadataReader reader, TypeDefinition type) => type.GetDeclaringType().IsNil
                ? reader.GetString(type.Namespace) + "." + reader.GetString(type.Name)
                : Key(reader, reader.GetTypeDefinition(type.GetDeclaringType())) + "+" + reader.GetString(type.Name);
        }

        [NativeMigrationTheory("EXISTING_NATIVE_AVAILABILITY_ROOT")]
        [InlineData("x64")]
        public void NormalExistingNativeAvailabilityPreservesExactFloorsAndDeclarationShapes(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("EXISTING_NATIVE_AVAILABILITY_ROOT");
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "authored", "report.json")));
            var facts = report.RootElement.GetProperty("facts").EnumerateArray().ToArray();
            Assert.Equal(53, facts.Length);
            Assert.Equal(53, facts.Select(fact => fact.GetProperty("factId").GetString()).Distinct().Count());
            Assert.Equal(25, facts.Count(fact => fact.GetProperty("kind").GetString() == "method"));
            Assert.Equal(28, facts.Count(fact => fact.GetProperty("kind").GetString() == "record"));
            string baseline = Environment.GetEnvironmentVariable("EXISTING_NATIVE_AVAILABILITY_BASELINE");
            Assert.False(string.IsNullOrEmpty(baseline));
            using var archive = System.IO.Compression.ZipFile.OpenRead(
                Path.Combine(Path.GetDirectoryName(baseline), "exact-source-inputs.zip"));
            string output = Path.Combine(root, "physical", architecture, Guid.NewGuid().ToString("N"));
            string legacyDirectory = Path.Combine(output, "legacy");
            string candidateDirectory = Path.Combine(output, "candidate");
            Directory.CreateDirectory(legacyDirectory);
            Directory.CreateDirectory(candidateDirectory);
            foreach (string partition in new[] { "Com", "DirectWrite", "Threading" })
            {
                var selected = facts.Where(fact => fact.GetProperty("partition").GetString() == partition)
                    .Select(fact => fact.GetProperty("symbol").GetString()).ToHashSet(StringComparer.Ordinal);
                var entries = new[] { "common\\" + partition + ".cs", architecture + "\\" + partition + ".cs" }
                    .Select(archive.GetEntry).Where(entry => entry != null).ToArray();
                Assert.NotEmpty(entries);
                var oldSources = entries.Select(entry =>
                {
                    using var stream = new StreamReader(entry.Open());
                    return stream.ReadToEnd();
                }).ToArray();
                WriteAvailabilityDeclarations(oldSources, partition, selected, legacyDirectory);
                WriteAvailabilityDeclarations(new[] { File.ReadAllText(Path.Combine(root, "scrape", "generated",
                    architecture, partition + ".cs")) }, partition, selected, candidateDirectory);
            }
            var priorLegacyFacts = new Dictionary<string, string>
            {
                ["CoInitialize"] = "[CanReturnMultipleSuccessValues]",
            };
            using var legacy = Emit(legacyDirectory, architecture, memberRemaps: priorLegacyFacts, references: new[] { baseline });
            using var candidate = Emit(candidateDirectory, architecture, references: new[] { baseline });
            AssertMetadataClosure(legacy.Reader);
            AssertMetadataClosure(candidate.Reader);
            foreach (var fact in facts)
            {
                string name = fact.GetProperty("symbol").GetString();
                string version = fact.GetProperty("version").GetString();
                if (fact.GetProperty("kind").GetString() == "method")
                {
                    var before = FindMethod(legacy.Reader, "Apis", name);
                    var after = FindMethod(candidate.Reader, "Apis", name);
                    AssertStringAttribute(legacy.Reader, before.GetCustomAttributes(), "SupportedOSPlatformAttribute", version);
                    AssertStringAttribute(candidate.Reader, after.GetCustomAttributes(), "SupportedOSPlatformAttribute", version);
                    Assert.Equal(MethodShape(legacy.Reader, before), MethodShape(candidate.Reader, after));
                }
                else
                {
                    var before = FindType(legacy.Reader, name);
                    var after = FindType(candidate.Reader, name);
                    Assert.Equal(legacy.Reader.GetString(before.Namespace), candidate.Reader.GetString(after.Namespace));
                    AssertStringAttribute(legacy.Reader, before.GetCustomAttributes(), "SupportedOSPlatformAttribute", version);
                    AssertStringAttribute(candidate.Reader, after.GetCustomAttributes(), "SupportedOSPlatformAttribute", version);
                    Assert.Equal(before.Attributes, after.Attributes);
                    Assert.Equal(before.GetLayout(), after.GetLayout());
                    Assert.Equal(before.GetFields().Select(legacy.Reader.GetFieldDefinition)
                        .Select(field => FieldShape(legacy.Reader, field)),
                        after.GetFields().Select(candidate.Reader.GetFieldDefinition)
                            .Select(field => FieldShape(candidate.Reader, field)));
                    Assert.Equal(before.GetMethods().Select(legacy.Reader.GetMethodDefinition)
                        .Select(method => MethodShape(legacy.Reader, method)),
                        after.GetMethods().Select(candidate.Reader.GetMethodDefinition)
                            .Select(method => MethodShape(candidate.Reader, method)));
                    Assert.Equal(before.GetNestedTypes().Select(legacy.Reader.GetTypeDefinition)
                        .Select(type => string.Join("\n", type.GetFields().Select(legacy.Reader.GetFieldDefinition)
                            .Select(field => FieldShape(legacy.Reader, field)))),
                        after.GetNestedTypes().Select(candidate.Reader.GetTypeDefinition)
                            .Select(type => string.Join("\n", type.GetFields().Select(candidate.Reader.GetFieldDefinition)
                                .Select(field => FieldShape(candidate.Reader, field)))));
                }
            }
            File.WriteAllText(Path.Combine(output, "observed.json"), JsonSerializer.Serialize(new
            {
                architecture,
                sourceFacts = facts.Select(fact => fact.GetProperty("factId").GetString()).ToArray(),
                sourceMethods = 25,
                sourceRecords = 28,
                preservedExistingControlFacts = priorLegacyFacts,
                normalPartitions = new[] { "Com", "DirectWrite", "Threading" },
                candidatePath = Path.Combine(candidateDirectory, "Test.winmd"),
                controlPath = Path.Combine(legacyDirectory, "Test.winmd"),
                scope = "Exact 53 availability attributes and unchanged native declaration signatures, field placement and COM slot order against retained normal sources. Not a whole-SDK or consumer-compatibility grade.",
            }, new JsonSerializerOptions { WriteIndented = true }));

        }

        [NativeMigrationTheory("EXISTING_NATIVE_WAVE07_ROOT")]
        [InlineData("x64")]
        public void NormalCompilerBoundNativeMajorityPreservesAvailabilityAndSessionContracts(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("EXISTING_NATIVE_WAVE07_ROOT");
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "authored", "report.json")));
            var facts = report.RootElement.GetProperty("facts").EnumerateArray().ToArray();
            Assert.Equal(20, facts.Length);
            Assert.Equal(20, facts.Select(fact => fact.GetProperty("factId").GetString()).Distinct().Count());
            var floors = facts.Where(fact => fact.GetProperty("kind").GetString() == "record").ToArray();
            Assert.Equal(16, floors.Length);
            Assert.Equal(5, report.RootElement.GetProperty("retainedReservedFacts").GetArrayLength());
            Assert.Equal(4, facts.Count(fact => fact.GetProperty("kind").GetString() == "enum"));
            string baseline = Environment.GetEnvironmentVariable("EXISTING_NATIVE_AVAILABILITY_BASELINE");
            Assert.False(string.IsNullOrEmpty(baseline));
            using var archive = System.IO.Compression.ZipFile.OpenRead(
                Path.Combine(Path.GetDirectoryName(baseline), "exact-source-inputs.zip"));
            string output = Path.Combine(root, "physical", architecture, Guid.NewGuid().ToString("N"));
            string legacyDirectory = Path.Combine(output, "legacy");
            string candidateDirectory = Path.Combine(output, "candidate");
            Directory.CreateDirectory(legacyDirectory);
            Directory.CreateDirectory(candidateDirectory);
            string[] partitions = { "Authorization.UI", "Shell", "Identity" };
            foreach (string partition in partitions)
            {
                var selected = facts.Where(fact => fact.GetProperty("partition").GetString() == partition &&
                        fact.GetProperty("kind").GetString() != "enum")
                    .Select(fact => fact.GetProperty("symbol").GetString().Split("::")[0]).ToHashSet(StringComparer.Ordinal);
                if (partition == "Identity")
                    selected.Add("SCHANNEL_SESSION_TOKEN");
                var entries = new[] { "common\\" + partition + ".cs", architecture + "\\" + partition + ".cs" }
                    .Select(archive.GetEntry).Where(entry => entry != null).ToArray();
                Assert.NotEmpty(entries);
                var oldSources = entries.Select(entry =>
                {
                    using var stream = new StreamReader(entry.Open());
                    return stream.ReadToEnd();
                }).ToArray();
                WriteAvailabilityDeclarations(oldSources, partition, selected, legacyDirectory);
                WriteAvailabilityDeclarations(new[] { File.ReadAllText(Path.Combine(root, "scrape-ready", "generated",
                    architecture, partition + ".cs")) }, partition, selected, candidateDirectory);
            }
            string rawIdentity = File.ReadAllText(Path.Combine(root, "scrape-ready", "generated", architecture, "Identity.header-types.cs"));
            var nativeGroup = CSharpSyntaxTree.ParseText(rawIdentity).GetRoot().DescendantNodes()
                .OfType<EnumDeclarationSyntax>().Single(value => value.Identifier.ValueText == "SCHANNEL_SESSION_TOKEN_FLAGS");
            var nativeNamespace = Assert.IsType<NamespaceDeclarationSyntax>(nativeGroup.Parent);
            var groupSource = SyntaxFactory.ParseCompilationUnit(
                "using System; using Windows.Win32.Foundation.Metadata;")
                .AddMembers(nativeNamespace.WithMembers(SyntaxFactory.SingletonList<MemberDeclarationSyntax>(nativeGroup)));
            File.WriteAllText(Path.Combine(candidateDirectory, "SessionEnum.cs"),
                groupSource.NormalizeWhitespace().ToFullString());
            var legacyRemaps = new Dictionary<string, string>
            {
                ["SCHANNEL_SESSION_TOKEN::dwFlags"] = "SCHANNEL_SESSION_TOKEN_FLAGS",
            };
            var requiredNamespaces = RspReader.GetSettingsValues(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                    "generation", "WinSDK", "requiredNamespacesForNames.rsp"), "--requiredNamespaceForName")
                .Select(line => line.Split('=', 2))
                .Where(pair => pair.Length == 2 && floors.Any(fact => fact.GetProperty("symbol").GetString() == pair[0]))
                .ToDictionary(pair => pair[0], pair => pair[1], StringComparer.Ordinal);
            Assert.Equal(2, requiredNamespaces.Count);
            using var legacy = Emit(legacyDirectory, architecture, memberRemaps: legacyRemaps, references: new[] { baseline },
                requiredNamespaces: requiredNamespaces);
            using var candidate = Emit(candidateDirectory, architecture, references: new[] { baseline },
                requiredNamespaces: requiredNamespaces);
            using var reference = new MetadataImage(baseline);
            AssertMetadataClosure(legacy.Reader);
            AssertMetadataClosure(candidate.Reader);
            foreach (var fact in floors)
            {
                string name = fact.GetProperty("symbol").GetString();
                string version = fact.GetProperty("version").GetString();
                var before = FindType(legacy.Reader, name);
                var after = FindType(candidate.Reader, name);
                var accepted = FindType(reference.Reader, name);
                Assert.Equal(reference.Reader.GetString(accepted.Namespace), candidate.Reader.GetString(after.Namespace));
                Assert.Equal(GuidValues(reference.Reader, accepted), GuidValues(candidate.Reader, after));
                AssertStringAttribute(legacy.Reader, before.GetCustomAttributes(), "SupportedOSPlatformAttribute", version);
                AssertStringAttribute(candidate.Reader, after.GetCustomAttributes(), "SupportedOSPlatformAttribute", version);
                AssertRecordShape(legacy.Reader, before, candidate.Reader, after);
            }
            var oldToken = FindType(legacy.Reader, "SCHANNEL_SESSION_TOKEN");
            var newToken = FindType(candidate.Reader, "SCHANNEL_SESSION_TOKEN");
            Assert.Equal(oldToken.Attributes, newToken.Attributes);
            Assert.Equal(oldToken.GetLayout(), newToken.GetLayout());
            Assert.Equal(legacy.Reader.GetString(oldToken.Namespace), candidate.Reader.GetString(newToken.Namespace));
            var oldTokenFields = oldToken.GetFields().Select(legacy.Reader.GetFieldDefinition).ToArray();
            var newTokenFields = newToken.GetFields().Select(candidate.Reader.GetFieldDefinition).ToArray();
            Assert.Equal(new[] { "dwTokenType", "dwFlags" },
                newTokenFields.Select(field => candidate.Reader.GetString(field.Name)));
            Assert.Equal(oldTokenFields.Select(field => legacy.Reader.GetString(field.Name)),
                newTokenFields.Select(field => candidate.Reader.GetString(field.Name)));
            Assert.Equal(FieldShape(legacy.Reader, oldTokenFields[0]), FieldShape(candidate.Reader, newTokenFields[0]));
            Assert.Equal(oldTokenFields[1].Attributes, newTokenFields[1].Attributes);
            Assert.Equal(oldTokenFields[1].GetOffset(), newTokenFields[1].GetOffset());
            Assert.Equal("Windows.Win32.Security.Authentication.Identity.SCHANNEL_SESSION_TOKEN_FLAGS",
                oldTokenFields[1].DecodeSignature(new SignatureNames(qualifiedNames: true), null));
            Assert.Equal("UInt32", newTokenFields[1].DecodeSignature(new SignatureNames(qualifiedNames: true), null));
            AssertStringAttribute(candidate.Reader, newTokenFields[1].GetCustomAttributes(),
                "AssociatedEnumAttribute", "SCHANNEL_SESSION_TOKEN_FLAGS");
            var oldGroup = FindType(reference.Reader, "SCHANNEL_SESSION_TOKEN_FLAGS");
            var newGroup = FindType(candidate.Reader, "SCHANNEL_SESSION_TOKEN_FLAGS");
            Assert.Equal("Windows.Win32.Security.Authentication.Identity", candidate.Reader.GetString(newGroup.Namespace));
            Assert.Equal(reference.Reader.GetString(oldGroup.Namespace), candidate.Reader.GetString(newGroup.Namespace));
            AssertDoesNotHaveAttribute(reference.Reader, oldGroup.GetCustomAttributes(), "FlagsAttribute");
            AssertDoesNotHaveAttribute(candidate.Reader, newGroup.GetCustomAttributes(), "FlagsAttribute");
            var oldFields = oldGroup.GetFields().Select(reference.Reader.GetFieldDefinition).ToArray();
            var newFields = newGroup.GetFields().Select(candidate.Reader.GetFieldDefinition).ToArray();
            Assert.Equal(3, newFields.Length);
            Assert.Equal("0609", Convert.ToHexString(candidate.Reader.GetBlobBytes(newFields[0].Signature)));
            Assert.Equal(oldFields.Select(field => FieldShape(reference.Reader, field)),
                newFields.Select(field => FieldShape(candidate.Reader, field)));
            foreach (var pair in oldFields.Skip(1).Zip(newFields.Skip(1)))
            {
                var before = reference.Reader.GetConstant(pair.First.GetDefaultValue());
                var after = candidate.Reader.GetConstant(pair.Second.GetDefaultValue());
                Assert.Equal(ConstantTypeCode.UInt32, after.TypeCode);
                Assert.Equal(before.TypeCode, after.TypeCode);
                Assert.Equal(reference.Reader.GetBlobBytes(before.Value), candidate.Reader.GetBlobBytes(after.Value));
            }
            File.WriteAllText(Path.Combine(output, "observed.json"), JsonSerializer.Serialize(new
            {
                architecture,
                sourceFacts = facts.Select(fact => fact.GetProperty("factId").GetString()).ToArray(),
                sourceRecordFloors = 16,
                retainedReservedParameters = 5,
                sourceSessionEnumFacts = 4,
                nativeGroupFullName = "Windows.Win32.Security.Authentication.Identity.SCHANNEL_SESSION_TOKEN_FLAGS",
                nativeGroupStorage = "UInt32",
                nativeGroupFlags = false,
                nativeGroupValues = new uint[] { 1, 2 },
                sessionFieldProjection = new
                {
                    nativeDeclaration = "DWORD dwFlags",
                    oldManagedType = "Windows.Win32.Security.Authentication.Identity.SCHANNEL_SESSION_TOKEN_FLAGS",
                    newManagedType = "UInt32",
                    preservedAssociatedEnum = "SCHANNEL_SESSION_TOKEN_FLAGS",
                    oldEnumAndNewNativeStorage = "UInt32",
                    nativeAllTargetSize = 8,
                    nativeAllTargetAlignment = 4,
                    nativeAllTargetOffsets = new[] { 0, 4 },
                },
                normalPartitions = partitions,
                existingNamespaceOrganization = requiredNamespaces,
                controlPath = Path.Combine(legacyDirectory, "Test.winmd"),
                candidatePath = Path.Combine(candidateDirectory, "Test.winmd"),
                scope = "Exact 20 source facts; unchanged COM declaration signatures/slots and availability; native DWORD session field with exact enum association, UInt32 storage and native-backed values. Session managed enum wrapper becomes UInt32 plus AssociatedEnum. Five Reserved facts remain unchanged. Normal physical metadata x64 only. No whole-SDK or consumer grade.",
            }, new JsonSerializerOptions { WriteIndented = true }));

            static void AssertRecordShape(MetadataReader beforeReader, TypeDefinition before,
                MetadataReader afterReader, TypeDefinition after)
            {
                Assert.Equal(beforeReader.GetString(before.Namespace), afterReader.GetString(after.Namespace));
                Assert.Equal(before.Attributes, after.Attributes);
                Assert.Equal(before.GetLayout(), after.GetLayout());
                Assert.Equal(before.GetFields().Select(beforeReader.GetFieldDefinition).Select(field => FieldShape(beforeReader, field)),
                    after.GetFields().Select(afterReader.GetFieldDefinition).Select(field => FieldShape(afterReader, field)));
                Assert.Equal(before.GetMethods().Select(beforeReader.GetMethodDefinition).Select(method => MethodShape(beforeReader, method)),
                    after.GetMethods().Select(afterReader.GetMethodDefinition).Select(method => MethodShape(afterReader, method)));
                Assert.Equal(before.GetNestedTypes().Select(beforeReader.GetTypeDefinition)
                    .Select(type => string.Join("\n", type.GetFields().Select(beforeReader.GetFieldDefinition)
                        .Select(field => FieldShape(beforeReader, field)))),
                    after.GetNestedTypes().Select(afterReader.GetTypeDefinition)
                        .Select(type => string.Join("\n", type.GetFields().Select(afterReader.GetFieldDefinition)
                            .Select(field => FieldShape(afterReader, field)))));
            }

            static string[] GuidValues(MetadataReader reader, TypeDefinition type)
                => type.GetCustomAttributes().Where(handle => AttributeName(reader, handle) == "GuidAttribute")
                    .Select(handle => Convert.ToHexString(reader.GetBlobBytes(reader.GetCustomAttribute(handle).Value)))
                    .OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        [NativeMigrationTheory("EXISTING_NATIVE_WAVE08_ROOT")]
        [InlineData("x64")]
        public void NormalOwnedScalarAssociationsAndClosedGroupsReachPhysicalWinmd(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("EXISTING_NATIVE_WAVE08_ROOT");
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "authored", "report.json")));
            var facts = report.RootElement.GetProperty("facts").EnumerateArray().ToArray();
            Assert.Equal(28, facts.Length);
            Assert.Equal(28, facts.Select(fact => fact.GetProperty("factId").GetString()).Distinct().Count());
            var uses = facts.Where(fact => fact.GetProperty("kind").GetString() == "parameter")
                .GroupBy(fact => fact.GetProperty("symbol").GetString(), StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => Assert.Single(group.Select(fact =>
                    fact.GetProperty("value").GetString()).Distinct()), StringComparer.Ordinal);
            Assert.Equal(16, uses.Count);
            string baseline = Environment.GetEnvironmentVariable("EXISTING_NATIVE_AVAILABILITY_BASELINE");
            Assert.False(string.IsNullOrEmpty(baseline));
            using var archive = System.IO.Compression.ZipFile.OpenRead(
                Path.Combine(Path.GetDirectoryName(baseline), "exact-source-inputs.zip"));
            string output = Path.Combine(root, "physical", architecture, Guid.NewGuid().ToString("N"));
            string legacyDirectory = Path.Combine(output, "native-storage-expectation");
            string candidateDirectory = Path.Combine(output, "candidate");
            Directory.CreateDirectory(legacyDirectory);
            Directory.CreateDirectory(candidateDirectory);
            string normal = Path.Combine(root, "scrape", "generated", architecture);
            var methods = new HashSet<string>(StringComparer.Ordinal);
            foreach (string partition in facts.Select(fact => fact.GetProperty("partition").GetString()).Distinct())
            {
                var selected = facts.Where(fact => fact.GetProperty("partition").GetString() == partition &&
                        fact.GetProperty("kind").GetString() != "enum")
                    .Select(fact => fact.GetProperty("symbol").GetString().Split("::")[0]).ToHashSet(StringComparer.Ordinal);
                methods.UnionWith(selected);
                if (partition == "Identity")
                    selected.Add("SCHANNEL_ALERT_TOKEN");
                var entries = archive.Entries.Where(entry =>
                    entry.FullName.Replace('\\', '/') == "common/" + partition + ".cs" ||
                    entry.FullName.Replace('\\', '/') == architecture + "/" + partition + ".cs").ToArray();
                Assert.NotEmpty(entries);
                var oldSources = entries.Select(entry =>
                {
                    using var stream = new StreamReader(entry.Open());
                    return stream.ReadToEnd();
                }).ToArray();
                WriteAvailabilityDeclarations(oldSources, partition, selected, legacyDirectory);
                WriteAvailabilityDeclarations(new[] { File.ReadAllText(Path.Combine(normal, partition + ".cs")) },
                    partition, selected, candidateDirectory);
            }
            Assert.Equal(17, methods.Count);
            foreach (var group in new[] { (Partition: "CmpApi", Name: "COMPRESS_ALGORITHM"),
                (Partition: "Identity", Name: "SCHANNEL_ALERT_TOKEN_ALERT_TYPE") })
            {
                var source = CSharpSyntaxTree.ParseText(File.ReadAllText(
                    Path.Combine(normal, group.Partition + ".header-types.cs"))).GetCompilationUnitRoot();
                var declaration = source.DescendantNodes().OfType<EnumDeclarationSyntax>()
                    .Single(value => value.Identifier.ValueText == group.Name);
                var ns = Assert.IsType<NamespaceDeclarationSyntax>(declaration.Parent);
                File.WriteAllText(Path.Combine(candidateDirectory, group.Name + ".cs"), source.WithMembers(
                    SyntaxFactory.SingletonList<MemberDeclarationSyntax>(ns.WithMembers(
                        SyntaxFactory.SingletonList<MemberDeclarationSyntax>(declaration))))
                    .NormalizeWhitespace().ToFullString());
            }
            var retained = new Dictionary<string, string>
            {
                ["SCHANNEL_ALERT_TOKEN::dwAlertType"] = "SCHANNEL_ALERT_TOKEN_ALERT_TYPE",
            };
            var nativeExpectation = new Dictionary<string, string>(retained, StringComparer.Ordinal);
            foreach (var use in uses)
                nativeExpectation.Add(use.Key, "[AssociatedEnum(\"" + use.Value + "\")] uint");
            using var legacy = Emit(legacyDirectory, architecture, memberRemaps: nativeExpectation, references: new[] { baseline });
            using var candidate = Emit(candidateDirectory, architecture, memberRemaps: retained, references: new[] { baseline });
            using var reference = new MetadataImage(baseline);
            AssertMetadataClosure(legacy.Reader);
            AssertMetadataClosure(candidate.Reader);
            foreach (string name in methods)
            {
                var before = Method(legacy.Reader, name);
                var after = Method(candidate.Reader, name);
                Assert.Equal(MethodShape(legacy.Reader, before), MethodShape(candidate.Reader, after));
                Assert.Equal(legacy.Reader.GetString(legacy.Reader.GetTypeDefinition(before.GetDeclaringType()).Namespace),
                    candidate.Reader.GetString(candidate.Reader.GetTypeDefinition(after.GetDeclaringType()).Namespace));
            }
            foreach (var use in uses)
            {
                string[] symbol = use.Key.Split("::");
                var method = Method(candidate.Reader, symbol[0]);
                var parameter = method.GetParameters().Select(candidate.Reader.GetParameter)
                    .Single(value => candidate.Reader.GetString(value.Name) == symbol[1]);
                Assert.Equal("UInt32", method.DecodeSignature(new SignatureNames(), null)
                    .ParameterTypes[parameter.SequenceNumber - 1]);
                AssertStringAttribute(candidate.Reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute", use.Value);
            }
            foreach (var floor in facts.Where(fact => fact.GetProperty("kind").GetString() == "method"))
            {
                string name = floor.GetProperty("symbol").GetString();
                string version = floor.GetProperty("version").GetString();
                AssertStringAttribute(legacy.Reader, Method(legacy.Reader, name).GetCustomAttributes(),
                    "SupportedOSPlatformAttribute", version);
                AssertStringAttribute(candidate.Reader, Method(candidate.Reader, name).GetCustomAttributes(),
                    "SupportedOSPlatformAttribute", version);
            }
            foreach (string name in new[] { "COMPRESS_ALGORITHM", "SCHANNEL_ALERT_TOKEN_ALERT_TYPE" })
            {
                var before = FindType(reference.Reader, name);
                var after = FindType(candidate.Reader, name);
                Assert.Equal(reference.Reader.GetString(before.Namespace), candidate.Reader.GetString(after.Namespace));
                AssertDoesNotHaveAttribute(candidate.Reader, after.GetCustomAttributes(), "FlagsAttribute");
                AssertDoesNotHaveAttribute(candidate.Reader, after.GetCustomAttributes(), "ScopedEnumAttribute");
                var oldFields = before.GetFields().Select(reference.Reader.GetFieldDefinition).ToArray();
                var newFields = after.GetFields().Select(candidate.Reader.GetFieldDefinition).ToArray();
                Assert.Equal(oldFields.Select(field => FieldShape(reference.Reader, field)),
                    newFields.Select(field => FieldShape(candidate.Reader, field)));
                Assert.Equal("UInt32", newFields[0].DecodeSignature(new SignatureNames(), null));
                foreach (var pair in oldFields.Skip(1).Zip(newFields.Skip(1)))
                {
                    var oldValue = reference.Reader.GetConstant(pair.First.GetDefaultValue());
                    var newValue = candidate.Reader.GetConstant(pair.Second.GetDefaultValue());
                    Assert.Equal(oldValue.TypeCode, newValue.TypeCode);
                    Assert.Equal(reference.Reader.GetBlobBytes(oldValue.Value), candidate.Reader.GetBlobBytes(newValue.Value));
                }
            }
            var oldToken = FindType(legacy.Reader, "SCHANNEL_ALERT_TOKEN");
            var newToken = FindType(candidate.Reader, "SCHANNEL_ALERT_TOKEN");
            Assert.Equal(oldToken.Attributes, newToken.Attributes);
            Assert.Equal(oldToken.GetLayout(), newToken.GetLayout());
            Assert.Equal(oldToken.GetFields().Select(legacy.Reader.GetFieldDefinition).Select(field => FieldShape(legacy.Reader, field)),
                newToken.GetFields().Select(candidate.Reader.GetFieldDefinition).Select(field => FieldShape(candidate.Reader, field)));
            File.WriteAllText(Path.Combine(output, "observed.json"), JsonSerializer.Serialize(new
            {
                architecture,
                completedUtc = DateTime.UtcNow,
                sourceFacts = facts.Select(fact => fact.GetProperty("factId").GetString()).ToArray(),
                sourceUseReferences = 17,
                uniqueNativeUInt32UseSites = uses,
                preservedMethodShapes = methods.OrderBy(value => value, StringComparer.Ordinal).ToArray(),
                sourceMethodFloors = 3,
                sourceEnumDefinitionsAndMembers = 8,
                retainedAlertFieldUse = retained,
                candidatePath = Path.Combine(candidateDirectory, "Test.winmd"),
                controlPath = Path.Combine(legacyDirectory, "Test.winmd"),
                scope = "Exact 28 source facts. Sixteen native UInt32 slots retain their exact associations; the control normalizes only those legacy enum wrappers to native storage. Seventeen method signatures, imports and SAL directions agree. Two unscoped non-Flags groups retain baseline identities, storage, order and values. The unchanged alert field overlay remains. Normal/physical x64 only; no whole-SDK or consumer grade.",
            }, new JsonSerializerOptions { WriteIndented = true }));

            static MethodDefinition Method(MetadataReader reader, string name)
                => reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                    .Single(method => reader.GetString(method.Name) == name);
        }

        [NativeMigrationTheory("TRANSFERRED_NATIVE_WAVE09_ROOT")]
        [InlineData("x64")]
        public void NormalTransferredNativeAssociationsPreserveScalarContractsAndRecordLayouts(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("TRANSFERRED_NATIVE_WAVE09_ROOT");
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "authored", "report.json")));
            var authoredFacts = report.RootElement.GetProperty("facts").EnumerateArray().ToArray();
            Assert.Equal(82, authoredFacts.Length);
            Assert.Equal(82, authoredFacts.Select(fact => fact.GetProperty("factId").GetString()).Distinct().Count());
            var facts = authoredFacts.Where(fact => fact.GetProperty("partition").GetString() != "Fs" ||
                fact.GetProperty("kind").GetString() != "parameter").ToArray();
            var blocked = authoredFacts.Except(facts).ToArray();
            Assert.Equal(54, facts.Length);
            Assert.Equal(28, blocked.Length);
            Assert.Equal(48, facts.Count(fact => fact.GetProperty("category").GetString() == "associated-enum-use"));
            Assert.Equal(6, facts.Count(fact => fact.GetProperty("category").GetString() == "direct-enum-use"));
            Assert.Equal(8, report.RootElement.GetProperty("retainedFacts").GetArrayLength());
            string baseline = Environment.GetEnvironmentVariable("EXISTING_NATIVE_AVAILABILITY_BASELINE");
            Assert.False(string.IsNullOrEmpty(baseline));
            using var archive = System.IO.Compression.ZipFile.OpenRead(
                Path.Combine(Path.GetDirectoryName(baseline), "exact-source-inputs.zip"));
            string output = Path.Combine(root, "physical", architecture, Guid.NewGuid().ToString("N"));
            string controlDirectory = Path.Combine(output, "native-storage-expectation");
            string candidateDirectory = Path.Combine(output, "candidate");
            Directory.CreateDirectory(controlDirectory);
            Directory.CreateDirectory(candidateDirectory);
            string normal = Path.Combine(root, "scrape", "generated", architecture);
            var methods = facts.Where(fact => fact.GetProperty("kind").GetString() == "parameter")
                .Select(fact => fact.GetProperty("symbol").GetString().Split("::")[0]).ToHashSet(StringComparer.Ordinal);
            var records = facts.Where(fact => fact.GetProperty("kind").GetString() == "field")
                .Select(fact => fact.GetProperty("symbol").GetString().Split("::")[0]).ToHashSet(StringComparer.Ordinal);
            Assert.Equal(20, methods.Count);
            Assert.Equal(17, records.Count);
            foreach (string partition in new[] { "Fs", "Setup" })
            {
                var selected = authoredFacts.Where(fact => fact.GetProperty("partition").GetString() == partition)
                    .Select(fact => fact.GetProperty("symbol").GetString().Split("::")[0]).ToHashSet(StringComparer.Ordinal);
                var entries = archive.Entries.Where(entry =>
                    entry.FullName.Replace('\\', '/') == "common/" + partition + ".cs" ||
                    entry.FullName.Replace('\\', '/') == architecture + "/" + partition + ".cs").ToArray();
                Assert.NotEmpty(entries);
                var oldSources = entries.Select(entry =>
                {
                    using var stream = new StreamReader(entry.Open());
                    return stream.ReadToEnd();
                }).ToArray();
                WriteAvailabilityDeclarations(oldSources, partition, selected, controlDirectory);
                WriteAvailabilityDeclarations(new[] { File.ReadAllText(Path.Combine(normal, partition + ".cs")) },
                    partition, selected, candidateDirectory);
            }
            foreach (var group in new[] { (Partition: "Fs", Name: "NTMS_OMID_TYPE"),
                (Partition: "Setup", Name: "MSIASSEMBLYINFO") })
            {
                var source = CSharpSyntaxTree.ParseText(File.ReadAllText(
                    Path.Combine(normal, group.Partition + ".header-types.cs"))).GetCompilationUnitRoot();
                var declaration = source.DescendantNodes().OfType<EnumDeclarationSyntax>()
                    .Single(value => value.Identifier.ValueText == group.Name);
                var ns = Assert.IsType<NamespaceDeclarationSyntax>(declaration.Parent);
                File.WriteAllText(Path.Combine(candidateDirectory, group.Name + ".cs"), source.WithMembers(
                    SyntaxFactory.SingletonList<MemberDeclarationSyntax>(ns.WithMembers(
                        SyntaxFactory.SingletonList<MemberDeclarationSyntax>(declaration))))
                    .NormalizeWhitespace().ToFullString());
            }
            var nativeExpectation = facts.ToDictionary(fact => fact.GetProperty("symbol").GetString(), fact =>
                "[AssociatedEnum(\"" + fact.GetProperty("group").GetString() + "\")] " +
                (fact.GetProperty("nativeStorage").GetString() == "Int32" ? "int" : "uint"), StringComparer.Ordinal);
            var selectedNames = methods.Concat(records).Concat(new[] { "NTMS_OMID_TYPE", "MSIASSEMBLYINFO" })
                .ToHashSet(StringComparer.Ordinal);
            var routes = RspReader.GetSettingsValues(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                    "generation", "WinSDK", "requiredNamespacesForNames.rsp"), "--requiredNamespaceForName")
                .Select(line => line.Split('=', 2)).Where(pair => pair.Length == 2 && selectedNames.Contains(pair[0]))
                .ToDictionary(pair => pair[0], pair => pair[1], StringComparer.Ordinal);
            using var control = Emit(controlDirectory, architecture, memberRemaps: nativeExpectation,
                references: new[] { baseline }, requiredNamespaces: routes);
            using var candidate = Emit(candidateDirectory, architecture, references: new[] { baseline }, requiredNamespaces: routes);
            using var reference = new MetadataImage(baseline);
            AssertMetadataClosure(control.Reader);
            AssertMetadataClosure(candidate.Reader);
            var blockedMethods = blocked.Select(fact => fact.GetProperty("symbol").GetString().Split("::")[0])
                .ToHashSet(StringComparer.Ordinal);
            Assert.Equal(26, blockedMethods.Count);
            Assert.DoesNotContain(control.Reader.MethodDefinitions.Select(control.Reader.GetMethodDefinition),
                method => blockedMethods.Contains(control.Reader.GetString(method.Name)));
            Assert.DoesNotContain(candidate.Reader.MethodDefinitions.Select(candidate.Reader.GetMethodDefinition),
                method => blockedMethods.Contains(candidate.Reader.GetString(method.Name)));
            var fsSource = CSharpSyntaxTree.ParseText(File.ReadAllText(Path.Combine(normal, "Fs.cs"))).GetCompilationUnitRoot();
            foreach (var fact in blocked)
            {
                string[] symbol = fact.GetProperty("symbol").GetString().Split("::");
                var method = fsSource.DescendantNodes().OfType<MethodDeclarationSyntax>()
                    .Single(value => value.Identifier.ValueText == symbol[0]);
                var parameter = method.ParameterList.Parameters.Single(value => value.Identifier.ValueText == symbol[1]);
                Assert.Equal(fact.GetProperty("nativeStorage").GetString() == "Int32" ? "int" : "uint", parameter.Type.ToString());
                var association = parameter.AttributeLists.SelectMany(value => value.Attributes)
                    .Single(value => value.Name.ToString().EndsWith(".AssociatedEnum", StringComparison.Ordinal));
                Assert.Equal(fact.GetProperty("group").GetString(),
                    Assert.IsType<LiteralExpressionSyntax>(Assert.Single(association.ArgumentList.Arguments).Expression).Token.ValueText);
            }
            foreach (string name in methods)
            {
                var before = Method(control.Reader, name);
                var after = Method(candidate.Reader, name);
                Assert.Equal(MethodShape(control.Reader, before), MethodShape(candidate.Reader, after));
                Assert.Equal(Attributes(control.Reader, before.GetCustomAttributes()),
                    Attributes(candidate.Reader, after.GetCustomAttributes()));
            }
            foreach (string name in records)
            {
                var before = FindType(control.Reader, name);
                var after = FindType(candidate.Reader, name);
                Assert.Equal(control.Reader.GetString(before.Namespace), candidate.Reader.GetString(after.Namespace));
                Assert.Equal(before.Attributes, after.Attributes);
                Assert.Equal(before.GetLayout(), after.GetLayout());
                Assert.Equal(before.GetFields().Select(control.Reader.GetFieldDefinition).Select(field => FieldShape(control.Reader, field)),
                    after.GetFields().Select(candidate.Reader.GetFieldDefinition).Select(field => FieldShape(candidate.Reader, field)));
            }
            foreach (var fact in facts)
            {
                string[] symbol = fact.GetProperty("symbol").GetString().Split("::");
                string storage = fact.GetProperty("nativeStorage").GetString();
                string group = fact.GetProperty("group").GetString();
                if (fact.GetProperty("kind").GetString() == "field")
                {
                    var field = FindType(candidate.Reader, symbol[0]).GetFields().Select(candidate.Reader.GetFieldDefinition)
                        .Single(value => candidate.Reader.GetString(value.Name) == symbol[1]);
                    Assert.Equal(storage, field.DecodeSignature(new SignatureNames(), null));
                    AssertStringAttribute(candidate.Reader, field.GetCustomAttributes(), "AssociatedEnumAttribute", group);
                }
                else
                {
                    var method = Method(candidate.Reader, symbol[0]);
                    var parameter = method.GetParameters().Select(candidate.Reader.GetParameter)
                        .Single(value => candidate.Reader.GetString(value.Name) == symbol[1]);
                    Assert.Equal(storage, method.DecodeSignature(new SignatureNames(), null).ParameterTypes[parameter.SequenceNumber - 1]);
                    AssertStringAttribute(candidate.Reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute", group);
                }
            }
            foreach (string name in new[] { "NTMS_OMID_TYPE", "MSIASSEMBLYINFO" })
            {
                var before = FindType(reference.Reader, name);
                var after = FindType(candidate.Reader, name);
                Assert.Equal(reference.Reader.GetString(before.Namespace), candidate.Reader.GetString(after.Namespace));
                Assert.Equal(before.GetFields().Select(reference.Reader.GetFieldDefinition).Select(field => FieldShape(reference.Reader, field)),
                    after.GetFields().Select(candidate.Reader.GetFieldDefinition).Select(field => FieldShape(candidate.Reader, field)));
            }
            File.WriteAllText(Path.Combine(output, "observed.json"), JsonSerializer.Serialize(new
            {
                architecture,
                completedUtc = DateTime.UtcNow,
                sourceFacts = facts.Select(fact => fact.GetProperty("factId").GetString()).ToArray(),
                sourceAssociatedEnumFacts = 48,
                sourceDirectUseFacts = 6,
                sourceAuthoredButUnqualifiedFacts = blocked.Select(fact => fact.GetProperty("factId").GetString()).ToArray(),
                preexistingEmptyImportMethods = blockedMethods.OrderBy(value => value, StringComparer.Ordinal).ToArray(),
                exactNativeScalarSites = facts.Select(fact => new
                {
                    symbol = fact.GetProperty("symbol").GetString(),
                    storage = fact.GetProperty("nativeStorage").GetString(),
                    group = fact.GetProperty("group").GetString(),
                }).ToArray(),
                unchangedMethods = methods.OrderBy(value => value, StringComparer.Ordinal).ToArray(),
                unchangedRecordLayouts = records.OrderBy(value => value, StringComparer.Ordinal).ToArray(),
                inheritedCanonicalGroupCredit = 0,
                retainedFacts = report.RootElement.GetProperty("retainedFacts"),
                candidatePath = Path.Combine(candidateDirectory, "Test.winmd"),
                scope = "Exact 54 physically qualified source facts in two explicitly transferred originals. The retained-normal control normalizes only these legacy association slots to their proven Int32/UInt32 native storage. Twenty method signatures/imports/directions/attributes and seventeen physical record layouts/field signatures agree. All 54 associations are exact. Another 28 source-authored NTMS parameter facts are checked in actual normal C# but earn no credit: both physical images omit the same 26 empty-import methods. Those old uses and eight other tails remain. Two inherited groups preserve identities/storage/field shape and earn no new credit. Normal/physical x64 only, no whole-SDK or consumer grade.",
            }, new JsonSerializerOptions { WriteIndented = true }));

            static MethodDefinition Method(MetadataReader reader, string name)
                => reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                    .Single(method => reader.GetString(method.Name) == name);

            static string[] Attributes(MetadataReader reader, CustomAttributeHandleCollection attributes)
                => attributes.Select(handle => AttributeName(reader, handle) + "=" +
                    Convert.ToHexString(reader.GetBlobBytes(reader.GetCustomAttribute(handle).Value)))
                    .OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        [NativeMigrationTheory("OWNED_SSL_AVAILABILITY_ROOT")]
        [InlineData("x64")]
        public void NormalCompilerBoundVoidWinapiPreservesSchannelAvailabilityAndImport(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("OWNED_SSL_AVAILABILITY_ROOT");
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "qualification-input.json")));
            var fact = Assert.Single(report.RootElement.GetProperty("facts").EnumerateArray());
            Assert.Equal("SslFreeCertificate", fact.GetProperty("symbol").GetString());
            string baseline = Environment.GetEnvironmentVariable("EXISTING_NATIVE_AVAILABILITY_BASELINE");
            Assert.False(string.IsNullOrEmpty(baseline));
            using var archive = System.IO.Compression.ZipFile.OpenRead(
                Path.Combine(Path.GetDirectoryName(baseline), "exact-source-inputs.zip"));
            string output = Path.Combine(root, "physical", architecture, Guid.NewGuid().ToString("N"));
            string controlDirectory = Path.Combine(output, "control");
            string candidateDirectory = Path.Combine(output, "candidate");
            Directory.CreateDirectory(controlDirectory);
            Directory.CreateDirectory(candidateDirectory);
            var selected = new HashSet<string>(StringComparer.Ordinal) { "SslFreeCertificate" };
            var entries = archive.Entries.Where(entry => entry.FullName.Replace('\\', '/') == "common/Identity.cs" ||
                entry.FullName.Replace('\\', '/') == architecture + "/Identity.cs").ToArray();
            Assert.NotEmpty(entries);
            var oldSources = entries.Select(entry =>
            {
                using var stream = new StreamReader(entry.Open());
                return stream.ReadToEnd();
            }).ToArray();
            WriteAvailabilityDeclarations(oldSources, "Identity", selected, controlDirectory);
            WriteAvailabilityDeclarations(new[] { File.ReadAllText(Path.Combine(root, "scrape", "generated",
                architecture, "Identity.cs")) }, "Identity", selected, candidateDirectory);
            using var control = Emit(controlDirectory, architecture, references: new[] { baseline });
            using var candidate = Emit(candidateDirectory, architecture, references: new[] { baseline });
            AssertMetadataClosure(control.Reader);
            AssertMetadataClosure(candidate.Reader);
            var before = FindMethod(control.Reader, "Apis", "SslFreeCertificate");
            var after = FindMethod(candidate.Reader, "Apis", "SslFreeCertificate");
            AssertStringAttribute(control.Reader, before.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows5.1.2600");
            AssertStringAttribute(candidate.Reader, after.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows5.1.2600");
            Assert.Equal(MethodShape(control.Reader, before), MethodShape(candidate.Reader, after));
            Assert.Equal("SCHANNEL.dll", candidate.Reader.GetString(candidate.Reader.GetModuleReference(after.GetImport().Module).Name));
            File.WriteAllText(Path.Combine(output, "observed.json"), JsonSerializer.Serialize(new
            {
                completedUtc = DateTime.UtcNow,
                architecture,
                sourceFacts = new[] { fact.GetProperty("factId").GetString() },
                exactFloor = "windows5.1.2600",
                unchangedVoidWinapiPointerParameterAndImport = true,
                candidatePath = Path.Combine(candidateDirectory, "Test.winmd"),
                scope = "One newly unblocked source availability fact; actual normal Identity/x64 and physical WinMD preserve the existing floor, void/pointer signature, calling convention, directions and SCHANNEL.dll import. No previous cohort or whole-SDK/consumer grade.",
            }, new JsonSerializerOptions { WriteIndented = true }));
        }

        [NativeMigrationTheory("OWNED_FORMAT_GROUPS_ROOT")]
        [InlineData("x64")]
        public void NormalUnscopedFormattingGroupsPreserveExactContractsAndNativeIntSlots(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("OWNED_FORMAT_GROUPS_ROOT");
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "authored", "report.json")));
            var facts = report.RootElement.GetProperty("facts").EnumerateArray().ToArray();
            Assert.Equal(43, facts.Length);
            Assert.Equal(43, facts.Select(fact => fact.GetProperty("factId").GetString()).Distinct().Count());
            var uses = facts.Where(fact => fact.GetProperty("kind").GetString() == "parameter").ToArray();
            Assert.Equal(11, uses.Length);
            var groups = report.RootElement.GetProperty("groupObjects").EnumerateArray().ToArray();
            Assert.Equal(6, groups.Length);
            Assert.Equal(26, groups.Sum(group => group.GetProperty("members").GetArrayLength()));
            var names = uses.Select(fact => fact.GetProperty("symbol").GetString().Split("::")[0])
                .ToHashSet(StringComparer.Ordinal);
            Assert.Equal(5, names.Count);
            string baseline = Environment.GetEnvironmentVariable("EXISTING_NATIVE_AVAILABILITY_BASELINE");
            Assert.False(string.IsNullOrEmpty(baseline));
            using var archive = System.IO.Compression.ZipFile.OpenRead(
                Path.Combine(Path.GetDirectoryName(baseline), "exact-source-inputs.zip"));
            string output = Path.Combine(root, "physical", architecture, Guid.NewGuid().ToString("N"));
            string controlDirectory = Path.Combine(output, "control");
            string candidateDirectory = Path.Combine(output, "candidate");
            Directory.CreateDirectory(controlDirectory);
            Directory.CreateDirectory(candidateDirectory);
            var entries = archive.Entries.Where(entry => entry.FullName.Replace('\\', '/') == "common/ComOle.cs" ||
                entry.FullName.Replace('\\', '/') == architecture + "/ComOle.cs").ToArray();
            Assert.NotEmpty(entries);
            var oldSources = entries.Select(entry =>
            {
                using var stream = new StreamReader(entry.Open());
                return stream.ReadToEnd();
            }).ToArray();
            string normalText = File.ReadAllText(Path.Combine(root, "scrape", "generated", architecture, "ComOle.cs"));
            WriteAvailabilityDeclarations(oldSources, "ComOle", names, controlDirectory);
            WriteAvailabilityDeclarations(new[] { normalText }, "ComOle", names, candidateDirectory);
            var normal = CSharpSyntaxTree.ParseText(normalText).GetCompilationUnitRoot();
            foreach (var group in groups)
            {
                string name = group.GetProperty("name").GetString();
                var declaration = normal.DescendantNodes().OfType<EnumDeclarationSyntax>()
                    .Single(value => value.Identifier.ValueText == name);
                var ns = Assert.IsType<NamespaceDeclarationSyntax>(declaration.Parent);
                File.WriteAllText(Path.Combine(candidateDirectory, name + ".cs"), normal.WithMembers(
                    SyntaxFactory.SingletonList<MemberDeclarationSyntax>(ns.WithMembers(
                        SyntaxFactory.SingletonList<MemberDeclarationSyntax>(declaration))))
                    .NormalizeWhitespace().ToFullString());
            }
            var expected = uses.ToDictionary(fact => fact.GetProperty("symbol").GetString(),
                fact => "[AssociatedEnum(\"" + fact.GetProperty("group").GetString() + "\")] int", StringComparer.Ordinal);
            using var control = Emit(controlDirectory, architecture, memberRemaps: expected, references: new[] { baseline });
            using var candidate = Emit(candidateDirectory, architecture, references: new[] { baseline });
            using var reference = new MetadataImage(baseline);
            AssertMetadataClosure(control.Reader);
            AssertMetadataClosure(candidate.Reader);
            foreach (string name in names)
            {
                var before = FindMethod(control.Reader, "Apis", name);
                var after = FindMethod(candidate.Reader, "Apis", name);
                Assert.Equal(MethodShape(control.Reader, before), MethodShape(candidate.Reader, after));
            }
            foreach (var fact in uses)
            {
                string[] symbol = fact.GetProperty("symbol").GetString().Split("::");
                var method = FindMethod(candidate.Reader, "Apis", symbol[0]);
                var parameter = method.GetParameters().Select(candidate.Reader.GetParameter)
                    .Single(value => candidate.Reader.GetString(value.Name) == symbol[1]);
                Assert.Equal("Int32", method.DecodeSignature(new SignatureNames(), null).ParameterTypes[parameter.SequenceNumber - 1]);
                AssertStringAttribute(candidate.Reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute",
                    fact.GetProperty("group").GetString());
            }
            foreach (var group in groups)
            {
                string name = group.GetProperty("name").GetString();
                var before = FindType(reference.Reader, name);
                var after = FindType(candidate.Reader, name);
                Assert.Equal(reference.Reader.GetString(before.Namespace), candidate.Reader.GetString(after.Namespace));
                Assert.DoesNotContain(after.GetCustomAttributes(), handle => AttributeName(candidate.Reader, handle) == "FlagsAttribute");
                Assert.Equal(before.GetFields().Select(reference.Reader.GetFieldDefinition).Select(field => FieldShape(reference.Reader, field)),
                    after.GetFields().Select(candidate.Reader.GetFieldDefinition).Select(field => FieldShape(candidate.Reader, field)));
                var actual = after.GetFields().Select(candidate.Reader.GetFieldDefinition)
                    .Where(field => !field.GetDefaultValue().IsNil).ToArray();
                foreach (var member in group.GetProperty("members").EnumerateArray())
                {
                    string memberName = member.GetProperty("name").GetString();
                    var field = Assert.Single(actual.Where(value => candidate.Reader.GetString(value.Name) == memberName));
                    var constant = candidate.Reader.GetConstant(field.GetDefaultValue());
                    Assert.Equal(ConstantTypeCode.Int32, constant.TypeCode);
                    Assert.Equal(member.GetProperty("value").GetInt32(), candidate.Reader.GetBlobReader(constant.Value).ReadInt32());
                }
            }
            File.WriteAllText(Path.Combine(output, "observed.json"), JsonSerializer.Serialize(new
            {
                completedUtc = DateTime.UtcNow, architecture,
                sourceFacts = facts.Select(fact => fact.GetProperty("factId").GetString()).ToArray(),
                sourceGroups = 6, sourceMembers = 26, sourceNativeIntAssociations = 11, preservedMethods = 5,
                candidatePath = Path.Combine(candidateDirectory, "Test.winmd"),
                scope = "Six complete source-owned unscoped non-Flags Int32 groups retain their exact existing namespaces/names/order and all 26 signed values. Eleven native Int32 slots preserve exact associations; five method signatures, imports and directions agree with the normalized retained control. Thirty-two definition/member coordinates bind through documented native contracts in the same owned original. Actual normal/physical ComOle/x64 only; no whole-SDK/consumer grade.",
            }, new JsonSerializerOptions { WriteIndented = true }));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void AssociatedEnumNativeForwardsResolveAnotherPartitionWithoutEmptyDefinitions(string architecture, string target)
        {
            using var use = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef enum tagCOINIT COINIT;
void Initialize(_Win32_AssociatedEnum_(COINIT) unsigned long flags);
", extraSettings: "--language\nc++\n--std\nc++17\n--additional=-fms-extensions\n");
            using var definition = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef enum tagCOINIT
{
    COINIT_APARTMENTTHREADED = 2,
    COINIT_MULTITHREADED = 0,
    COINIT_DISABLE_OLE1DDE = 4,
    COINIT_SPEED_OVER_MEMORY = 8
} COINIT;
");
            Assert.True(use.Run() == 0, use.Diagnostics);
            Assert.True(definition.Run() == 0, definition.Diagnostics);
            File.Copy(definition.Output, Path.Combine(Path.GetDirectoryName(use.Output), "NativeEnumDefinition.cs"));
            using var image = Emit(use, architecture);
            var reader = image.Reader;
            var nativeEnum = Assert.Single(reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "COINIT"));
            Assert.Equal("Test", reader.GetString(nativeEnum.Namespace));
            var fields = nativeEnum.GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal("Int32", fields.Single(field => reader.GetString(field.Name) == "value__")
                .DecodeSignature(new SignatureNames(), null));
            var members = fields.Where(field => reader.GetString(field.Name) != "value__").ToArray();
            Assert.Equal(new[] { "COINIT_APARTMENTTHREADED", "COINIT_MULTITHREADED", "COINIT_DISABLE_OLE1DDE", "COINIT_SPEED_OVER_MEMORY" },
                members.Select(field => reader.GetString(field.Name)));
            Assert.Equal(new[] { 2, 0, 4, 8 }, members.Select(field =>
                reader.GetBlobReader(reader.GetConstant(field.GetDefaultValue()).Value).ReadInt32()));
            var initialize = FindMethod(reader, "Apis", "Initialize");
            Assert.Equal(new[] { "UInt32" }, initialize.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            var flags = initialize.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 1);
            AssertStringAttribute(reader, flags.GetCustomAttributes(), "AssociatedEnumAttribute", "COINIT");
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void ExplicitReservedMetadataPreservesDirectionAndOptionality(string architecture, string target)
        {
            const string annotation = "_Win32_Reserved_ ";
            const string declarations = @"
int __stdcall PreserveReserved(
    _In_ _Win32_Reserved_ void* input,
    _Win32_Reserved_ unsigned scalar,
    _Win32_Reserved_ void* untyped,
    _In_opt_ _Win32_Reserved_ void* optional);
";
            using var candidateSource = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations);
            Assert.True(candidateSource.Run() == 0, candidateSource.Diagnostics);
            using var legacySource = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations.Replace(annotation, ""));
            Assert.True(legacySource.Run() == 0, legacySource.Diagnostics);
            Assert.Equal(NativeSurface(candidateSource, target, metadataEnabled: false),
                NativeSurface(candidateSource, target, metadataEnabled: true));
            using var candidate = Emit(candidateSource, architecture);
            using var legacy = Emit(legacySource.DirectoryPath, architecture, memberRemaps: new Dictionary<string, string>
            {
                ["PreserveReserved::input"] = "[Reserved]",
                ["PreserveReserved::scalar"] = "[Reserved]",
                ["PreserveReserved::untyped"] = "[Reserved]",
                ["PreserveReserved::optional"] = "[Reserved]",
            });
            var before = FindMethod(legacy.Reader, "Apis", "PreserveReserved");
            var after = FindMethod(candidate.Reader, "Apis", "PreserveReserved");
            Assert.Equal(MethodShape(legacy.Reader, before), MethodShape(candidate.Reader, after));
            var parameters = after.GetParameters().Select(candidate.Reader.GetParameter).ToArray();
            Assert.Equal(4, parameters.Length);
            Assert.Equal(new[] { ParameterAttributes.In, ParameterAttributes.In, ParameterAttributes.In | ParameterAttributes.Out,
                ParameterAttributes.In | ParameterAttributes.Optional },
                parameters.Select(parameter => parameter.Attributes).ToArray());
            foreach (var parameter in parameters)
                AssertHasAttribute(candidate.Reader, parameter.GetCustomAttributes(), "ReservedAttribute");
            AssertMetadataClosure(candidate.Reader);
        }

        private static string FieldShape(MetadataReader reader, FieldDefinition field)
            => reader.GetString(field.Name) + "|" + field.Attributes + "|" + field.GetOffset() + "|" +
                field.DecodeSignature(new SignatureNames(qualifiedNames: true), null);

        private static string MethodShape(MetadataReader reader, MethodDefinition method)
        {
            var signature = method.DecodeSignature(new SignatureNames(qualifiedNames: true), null);
            var import = method.GetImport();
            string module = import.Module.IsNil ? "" :
                reader.GetString(reader.GetModuleReference(import.Module).Name);
            return reader.GetString(method.Name) + "|" + method.Attributes + "|" + method.ImplAttributes + "|" +
                signature.Header.RawValue + "|" + signature.ReturnType + "|" +
                string.Join(",", signature.ParameterTypes) + "|" + import.Attributes + "|" + module + "|" +
                (import.Name.IsNil ? "" : reader.GetString(import.Name)) + "|" +
                string.Join(",", method.GetParameters().Select(reader.GetParameter)
                    .Select(parameter => reader.GetString(parameter.Name) + ":" + parameter.SequenceNumber + ":" + parameter.Attributes));
        }

        private static void WriteAvailabilityDeclarations(IEnumerable<string> texts, string partition, HashSet<string> names, string directory)
        {
            var sources = texts.Select(text => CSharpSyntaxTree.ParseText(text).GetCompilationUnitRoot()).ToArray();
            var source = sources[0].WithUsings(SyntaxFactory.List(sources.SelectMany(unit => unit.Usings)
                .GroupBy(value => value.ToString(), StringComparer.Ordinal).Select(group => group.First())));
            var found = new HashSet<string>(StringComparer.Ordinal);
            var namespaces = sources.SelectMany(unit => unit.Members).OfType<NamespaceDeclarationSyntax>().Select(ns =>
            {
                var members = new List<MemberDeclarationSyntax>();
                foreach (var declaration in ns.Members)
                {
                    if (declaration is StructDeclarationSyntax record && names.Contains(record.Identifier.ValueText))
                    {
                        Assert.True(found.Add(record.Identifier.ValueText));
                        members.Add(record);
                    }
                    if (declaration is ClassDeclarationSyntax api)
                    {
                        var methods = api.Members.OfType<MethodDeclarationSyntax>()
                            .Where(method => names.Contains(method.Identifier.ValueText)).ToArray();
                        foreach (var method in methods)
                            Assert.True(found.Add(method.Identifier.ValueText));
                        if (methods.Length != 0)
                            members.Add(api.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(methods)));
                    }
                }
                return ns.WithMembers(SyntaxFactory.List(members));
            }).Where(ns => ns.Members.Count != 0).ToArray();
            Assert.True(names.SetEquals(found), directory + "/" + partition + ": " + string.Join(",", names.Except(found)));
            File.WriteAllText(Path.Combine(directory, partition + ".cs"),
                source.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(namespaces)).NormalizeWhitespace().ToFullString());
        }

        private static readonly (string Name, string Header, bool Flags, int Members)[] NextNativeCategoryGroups =
        {
            ("CERT_SELECT_STRUCT_FLAGS", "cryptdlg.h", true, 6),
            ("CERT_VIEWPROPERTIES_STRUCT_FLAGS", "cryptdlg.h", true, 10),
            ("CTL_MODIFY_REQUEST_OPERATION", "cryptdlg.h", false, 3),
            ("SECURITY_INFO_PAGE_FLAGS", "aclui.h", true, 3),
            ("SET_SERVICE_OPERATION", "nspapi.h", false, 5),
            ("PERF_COUNTER_AGGREGATE_FUNC", "perflib.h", false, 5),
            ("CACHE_CONFIG", "winineti.h", false, 10),
            ("PFN_WDS_CLI_CALLBACK_MESSAGE_ID", "wdsclientapi.h", false, 4),
        };

        [Fact]
        public void NextNativeCategoryKeepsSourceGroupsAndExactUnsupportedTails()
        {
            string project = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK");
            using var enums = JsonDocument.Parse(File.ReadAllText(Path.Combine(project, "enums.json")));
            var items = enums.RootElement.GetProperty("items").EnumerateArray().ToArray();
            foreach (var group in NextNativeCategoryGroups)
            {
                Assert.DoesNotContain(items, item => item.TryGetProperty("name", out var name) &&
                    name.GetString() == group.Name);
                string macro = group.Flags ? "_Win32_FlagsEnum_" : "_Win32_Enum_";
                Assert.Single(File.ReadAllLines(Path.Combine(project, "patches", "um", group.Header + ".patch"))
                    .Where(line => line.StartsWith("+" + macro + "(" + group.Name + ",", StringComparison.Ordinal)));
            }
            var wds = Assert.Single(items.Where(item => item.TryGetProperty("addUsesTo", out var name) &&
                name.GetString() == "PFN_WDS_CLI_CALLBACK_MESSAGE_ID"));
            Assert.Equal("Windows.Win32.System.DeploymentServices", wds.GetProperty("namespace").GetString());
            var callback = Assert.Single(wds.GetProperty("uses").EnumerateArray());
            Assert.Equal("PFN_WdsCliCallback", callback.GetProperty("method").GetString());
            Assert.Equal("dwMessageId", callback.GetProperty("parameter").GetString());
            Assert.Contains(items, item => item.TryGetProperty("name", out var name) &&
                name.GetString() == "SI_OBJECT_INFO_FLAGS");
            var rows = File.ReadAllLines(Path.Combine(project, "emitter.settings.rsp"));
            foreach (string row in new[]
            {
                "GetProcessHeap::return=[DoNotRelease]",
                "GetProcessHeaps::ProcessHeaps=[DoNotRelease]",
                "OleCreatePropertyFrame::dwReserved=[Reserved]",
                "OleCreatePropertyFrame::pvReserved=[Reserved]",
                "OleLoadPicturePath::dwReserved=[Reserved]",
            })
                Assert.Contains(row, rows);
            foreach (string row in new[]
            {
                "SysAllocStringByteLen::psz=[NativeArrayInfo(CountParamIndex = 1)]",
                "CoInitialize=[CanReturnMultipleSuccessValues]",
                "CreateDataCache::ppv=[ComOutPtr]",
                "PXE_DHCP_OPTION=[StructLayout(LayoutKind.Sequential, Pack = 1)]",
                "PXE_DHCPV6_MESSAGE_HEADER=[StructLayout(LayoutKind.Sequential, Pack = 1)]",
                "PXE_DHCPV6_MESSAGE=[StructLayout(LayoutKind.Sequential, Pack = 1)]",
                "PXE_DHCPV6_RELAY_MESSAGE=[StructLayout(LayoutKind.Sequential, Pack = 1)]",
            })
                Assert.DoesNotContain(row, rows);
        }

        [NativeMigrationTheory("EXISTING_NATIVE_CATEGORY_NEXT_ROOT")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void NormalNextNativeCategoryKeepsPhysicalGroupsAndContracts(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("EXISTING_NATIVE_CATEGORY_NEXT_ROOT");
            using var expectations = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "expectations.json")));
            var plan = expectations.RootElement;
            using var baselinePaths = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "frozen-baseline-types.json")));
            string baselinePath = baselinePaths.RootElement.GetProperty("path").GetString();
            using var baseline = new MetadataImage(baselinePath);
            using var archive = System.IO.Compression.ZipFile.OpenRead(
                Path.Combine(Path.GetDirectoryName(baselinePath), "exact-source-inputs.zip"));
            string normal = Path.Combine(root, "scrape-" + architecture, "generated", architecture);
            string directory = Path.Combine(root, "physical", architecture, Guid.NewGuid().ToString("N"));
            string controlDirectory = Path.Combine(directory, "native-storage-expectation");
            string candidateDirectory = Path.Combine(directory, "candidate");
            Directory.CreateDirectory(controlDirectory);
            Directory.CreateDirectory(candidateDirectory);
            var methods = plan.GetProperty("methods").EnumerateArray().Select(value => value.GetString()).ToHashSet();
            var records = plan.GetProperty("records").EnumerateArray().Select(value => value.GetString()).ToHashSet();
            var groups = NextNativeCategoryGroups.Select(group => group.Name).ToHashSet();
            var expectedMethods = new HashSet<string>();
            var expectedRecords = new HashSet<string>();
            var actualMethods = new HashSet<string>();
            var actualRecords = new HashSet<string>();
            var actualGroups = new HashSet<string>();
            foreach (string file in new[] { "Authorization.UI", "Security.Cryptography.UI", "WinSock", "Perf",
                "WinInet", "Wds", "Shell", "Fs", "Com", "ComOle" })
            {
                var entry = archive.GetEntry(architecture + "\\" + file + ".cs") ??
                    archive.GetEntry("common\\" + file + ".cs");
                Assert.NotNull(entry);
                using var stream = new StreamReader(entry.Open());
                WriteSelected(stream.ReadToEnd(), file, controlDirectory, false, expectedMethods, expectedRecords);
                WriteSelected(File.ReadAllText(Path.Combine(normal, file + ".cs")), file,
                    candidateDirectory, true, actualMethods, actualRecords);
            }
            foreach (string path in Directory.EnumerateFiles(normal, "*.header-types.cs"))
                WriteSelected(File.ReadAllText(path), Path.GetFileNameWithoutExtension(path), candidateDirectory,
                    true, actualMethods, actualRecords);
            Assert.Equal(methods.OrderBy(value => value), expectedMethods.OrderBy(value => value));
            Assert.Equal(records.OrderBy(value => value), expectedRecords.OrderBy(value => value));
            Assert.Equal(methods.OrderBy(value => value), actualMethods.OrderBy(value => value));
            Assert.Equal(records.OrderBy(value => value), actualRecords.OrderBy(value => value));
            Assert.Equal(groups.OrderBy(value => value), actualGroups.OrderBy(value => value));

            // Preserve every legacy attribute; normalize only the eleven reviewed enum-typed UInt32 slots.
            using var control = Emit(controlDirectory, architecture,
                memberRemaps: Dictionary(plan.GetProperty("nativeStorageExpectationRemaps")),
                references: new[] { baselinePath });
            using var candidate = Emit(candidateDirectory, architecture,
                memberRemaps: Dictionary(plan.GetProperty("candidateRemaps")),
                references: new[] { baselinePath });
            AssertMetadataClosure(control.Reader);
            AssertMetadataClosure(candidate.Reader);
            var before = Types(control.Reader);
            var after = Types(candidate.Reader);
            Assert.Equal(before.Keys.OrderBy(value => value), after.Keys.OrderBy(value => value));
            foreach (string name in before.Keys)
                Assert.Equal(WinHttpMigrationTests.SnapshotType(control.Reader, before[name]),
                    WinHttpMigrationTests.SnapshotType(candidate.Reader, after[name]));

            var groupValues = new Dictionary<string, string[]>();
            foreach (var group in NextNativeCategoryGroups)
            {
                var current = FindType(candidate.Reader, group.Name);
                var old = FindType(baseline.Reader, group.Name);
                string ns = plan.GetProperty("namespaces").GetProperty(group.Name).GetString();
                Assert.Equal(ns, candidate.Reader.GetString(current.Namespace));
                Assert.Equal(ns, baseline.Reader.GetString(old.Namespace));
                foreach (var pair in new[] { (candidate.Reader, current), (baseline.Reader, old) })
                {
                    var storage = pair.Item2.GetFields().Select(pair.Item1.GetFieldDefinition)
                        .Single(field => pair.Item1.GetString(field.Name) == "value__");
                    Assert.Equal("UInt32", storage.DecodeSignature(new SignatureNames(), null));
                    Assert.Equal(group.Flags, pair.Item2.GetCustomAttributes().Any(
                        handle => AttributeName(pair.Item1, handle) == "FlagsAttribute"));
                    AssertDoesNotHaveAttribute(pair.Item1, pair.Item2.GetCustomAttributes(), "ScopedEnumAttribute");
                }
                string[] values = Values(candidate.Reader, current);
                Assert.Equal(group.Members, values.Length);
                Assert.Equal(Values(baseline.Reader, old), values);
                groupValues[group.Name] = values;
            }
            foreach (var association in plan.GetProperty("associations").EnumerateArray())
            {
                string group = association.GetProperty("group").GetString();
                string fullEnum = plan.GetProperty("namespaces").GetProperty(group).GetString() + "." + group;
                var use = association.GetProperty("legacyUse");
                if (use.TryGetProperty("struct", out var owner))
                {
                    string fieldName = use.GetProperty("field").GetString();
                    var old = FindType(baseline.Reader, owner.GetString()).GetFields().Select(baseline.Reader.GetFieldDefinition)
                        .Single(field => baseline.Reader.GetString(field.Name) == fieldName);
                    var current = FindType(candidate.Reader, owner.GetString()).GetFields().Select(candidate.Reader.GetFieldDefinition)
                        .Single(field => candidate.Reader.GetString(field.Name) == fieldName);
                    Assert.Equal(fullEnum, old.DecodeSignature(new SignatureNames(qualifiedNames: true), null));
                    Assert.Equal("UInt32", current.DecodeSignature(new SignatureNames(), null));
                    AssertStringAttribute(candidate.Reader, current.GetCustomAttributes(), "AssociatedEnumAttribute", group);
                }
                else
                {
                    string methodName = use.GetProperty("method").GetString();
                    string recordName = use.TryGetProperty("interface", out owner) ? owner.GetString() : "Apis";
                    var old = Method(baseline.Reader, recordName, methodName);
                    var current = Method(candidate.Reader, recordName, methodName);
                    string parameterName = use.GetProperty("parameter").GetString();
                    var oldParameter = old.GetParameters().Select(baseline.Reader.GetParameter)
                        .Single(parameter => baseline.Reader.GetString(parameter.Name) == parameterName);
                    var parameter = current.GetParameters().Select(candidate.Reader.GetParameter)
                        .Single(value => candidate.Reader.GetString(value.Name) == parameterName);
                    Assert.Equal(oldParameter.SequenceNumber, parameter.SequenceNumber);
                    Assert.Equal(oldParameter.Attributes, parameter.Attributes);
                    Assert.Equal(fullEnum, old.DecodeSignature(new SignatureNames(qualifiedNames: true), null)
                        .ParameterTypes[oldParameter.SequenceNumber - 1]);
                    Assert.Equal("UInt32", current.DecodeSignature(new SignatureNames(), null)
                        .ParameterTypes[parameter.SequenceNumber - 1]);
                    AssertStringAttribute(candidate.Reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute", group);
                }
            }
            foreach (var contract in plan.GetProperty("preserveResult").EnumerateArray())
                Assert.True(Method(candidate.Reader, "Apis", contract.GetProperty("method").GetString())
                    .ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            foreach (var name in plan.GetProperty("packing").GetProperty("types").EnumerateArray())
                Assert.Equal(1, FindType(candidate.Reader, name.GetString()).GetLayout().PackingSize);
            var allocation = Method(candidate.Reader, "Apis", "SysAllocStringByteLen");
            var input = allocation.GetParameters().Select(candidate.Reader.GetParameter)
                .Single(parameter => candidate.Reader.GetString(parameter.Name) == "psz");
            Assert.Equal(ParameterAttributes.In | ParameterAttributes.Optional, input.Attributes);
            AssertHasAttribute(candidate.Reader, input.GetCustomAttributes(), "NativeArrayInfoAttribute");
            File.WriteAllText(Path.Combine(directory, "observed.json"), JsonSerializer.Serialize(new
            {
                architecture,
                scope = plan.GetProperty("scope").GetString(),
                groups = groupValues,
                nativeStorageAssociations = plan.GetProperty("associations"),
                exactLegacyAttributeRows = plan.GetProperty("retiredAttributeRows"),
                retainedSelectedAttributeRows = plan.GetProperty("retainedSelectedAttributeRows"),
                candidatePath = Path.Combine(candidateDirectory, "Test.winmd"),
                expectationPath = Path.Combine(controlDirectory, "Test.winmd"),
                referencePath = baselinePath,
                selectedMethods = actualMethods.OrderBy(value => value),
                selectedRecords = actualRecords.OrderBy(value => value),
                nativeFieldArrayInferenceEnabled = false,
                noWholeSdkImageOrApiAcceptance = true,
            }, new JsonSerializerOptions { WriteIndented = true }));

            Dictionary<string, TypeDefinition> Types(MetadataReader reader)
                => reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => reader.GetString(type.Name) == "Apis" || records.Contains(reader.GetString(type.Name)))
                    .ToDictionary(type => reader.GetString(type.Namespace) + "." + reader.GetString(type.Name));

            static Dictionary<string, string> Dictionary(JsonElement element)
                => element.EnumerateObject().ToDictionary(property => property.Name, property => property.Value.GetString());

            static string[] Values(MetadataReader reader, TypeDefinition type)
                => type.GetFields().Select(reader.GetFieldDefinition)
                    .Where(field => reader.GetString(field.Name) != "value__")
                    .Select(field =>
                    {
                        var value = reader.GetConstant(field.GetDefaultValue());
                        return reader.GetString(field.Name) + "=" + value.TypeCode + ":" +
                            Convert.ToHexString(reader.GetBlobBytes(value.Value));
                    }).OrderBy(value => value, StringComparer.Ordinal).ToArray();

            static MethodDefinition Method(MetadataReader reader, string owner, string name)
                => reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => reader.GetString(type.Name) == owner)
                    .SelectMany(type => type.GetMethods()).Select(reader.GetMethodDefinition)
                    .Single(method => reader.GetString(method.Name) == name);

            void WriteSelected(string text, string file, string output, bool includeGroups,
                HashSet<string> foundMethods, HashSet<string> foundRecords)
            {
                var source = CSharpSyntaxTree.ParseText(text).GetCompilationUnitRoot();
                var namespaces = source.Members.OfType<NamespaceDeclarationSyntax>().Select(ns =>
                {
                    var members = new List<MemberDeclarationSyntax>();
                    foreach (var declaration in ns.Members)
                    {
                        if (declaration is BaseTypeDeclarationSyntax type && records.Contains(type.Identifier.ValueText))
                        {
                            Assert.True(foundRecords.Add(type.Identifier.ValueText));
                            members.Add(type);
                        }
                        else if (includeGroups && declaration is EnumDeclarationSyntax group &&
                            groups.Contains(group.Identifier.ValueText))
                        {
                            Assert.True(actualGroups.Add(group.Identifier.ValueText));
                            members.Add(group);
                        }
                        else if (declaration is ClassDeclarationSyntax api && api.Identifier.ValueText == "Apis")
                        {
                            var selected = api.Members.OfType<MethodDeclarationSyntax>()
                                .Where(method => methods.Contains(method.Identifier.ValueText))
                                .OrderBy(method => method.Identifier.ValueText, StringComparer.Ordinal).ToArray();
                            foreach (var method in selected)
                                Assert.True(foundMethods.Add(method.Identifier.ValueText), "An API must have one actual normal declaration.");
                            if (selected.Length != 0)
                                members.Add(api.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(selected)));
                        }
                    }
                    return ns.WithMembers(SyntaxFactory.List(members));
                }).Where(ns => ns.Members.Count != 0).ToArray();
                if (namespaces.Length != 0)
                    File.WriteAllText(Path.Combine(output, file + ".cs"),
                        source.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(namespaces)).NormalizeWhitespace().ToFullString());
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void SignedRegistryStatusKeepsUnsignedErrorAssociation(
            string architecture, string target, bool annotationsEnabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#define ERROR_SUCCESS 0L
#if defined(WIN32METADATA) && defined(__clang__) && defined(__cplusplus) && !defined(MIDL_PASS)
_Win32_Enum_(WIN32_ERROR, unsigned long, ERROR_SUCCESS);
#endif
typedef long LSTATUS;
#if defined(WIN32METADATA) && defined(__clang__) && defined(__cplusplus) && !defined(MIDL_PASS)
_Win32_AssociatedEnum_(WIN32_ERROR)
#endif
LSTATUS __stdcall RegistryStatus(unsigned long flags);
", annotationsEnabled: annotationsEnabled);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var method = FindMethod(reader, "Apis", "RegistryStatus");
            var signature = method.DecodeSignature(new SignatureNames(), null);
            Assert.Equal("Int32", signature.ReturnType);
            Assert.Equal(new[] { "UInt32" }, signature.ParameterTypes);
            var result = method.GetParameters().Select(reader.GetParameter)
                .SingleOrDefault(parameter => parameter.SequenceNumber == 0);
            if (annotationsEnabled)
            {
                AssertStringAttribute(reader, result.GetCustomAttributes(), "AssociatedEnumAttribute", "WIN32_ERROR");
                var storage = FindType(reader, "WIN32_ERROR").GetFields().Select(reader.GetFieldDefinition)
                    .Single(field => reader.GetString(field.Name) == "value__");
                Assert.Equal("UInt32", storage.DecodeSignature(new SignatureNames(), null));
            }
            else
            {
                Assert.DoesNotContain(reader.CustomAttributes,
                    handle => AttributeName(reader, handle) == "AssociatedEnumAttribute");
                Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                    type => reader.GetString(type.Name) == "WIN32_ERROR");
            }
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void ReturnedBufferSalCountReachesPhysicalWinmd(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef int HRESULT;
struct __declspec(uuid(""f40fb47a-61fc-49ec-811a-60be160a87cc"")) IReturnedBuffer
{
    virtual HRESULT __stdcall List(
        _Inout_ unsigned* count,
        _Outptr_result_buffer_(*count) unsigned** values) = 0;
};
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var method = FindMethod(reader, "IReturnedBuffer", "List");
            Assert.Equal(new[] { "UInt32*", "UInt32**" },
                method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            var parameters = method.GetParameters().Select(reader.GetParameter).ToArray();
            var count = parameters.Single(parameter => reader.GetString(parameter.Name) == "count");
            var values = parameters.Single(parameter => reader.GetString(parameter.Name) == "values");
            Assert.True(count.Attributes.HasFlag(ParameterAttributes.In | ParameterAttributes.Out));
            Assert.True(values.Attributes.HasFlag(ParameterAttributes.Out));
            Assert.False(values.Attributes.HasFlag(ParameterAttributes.In));
            var arrayInfo = reader.GetCustomAttribute(Assert.Single(values.GetCustomAttributes()
                .Where(handle => AttributeName(reader, handle) == "NativeArrayInfoAttribute")));
            var blob = reader.GetBlobReader(arrayInfo.Value);
            Assert.Equal(1, blob.ReadUInt16());
            Assert.Equal(1, blob.ReadUInt16());
            Assert.Equal(0x53, blob.ReadByte());
            Assert.Equal((byte)SignatureTypeCode.Int16, blob.ReadByte());
            Assert.Equal("CountParamIndex", blob.ReadSerializedString());
            Assert.Equal(0, blob.ReadInt16());
            Assert.Equal(0, blob.RemainingBytes);
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void MidlGeneratedAnnotationsReachTypesAndMembersWithoutChangingNativeSignatures(
            string architecture, string target, bool annotationsEnabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef int HRESULT;
typedef enum MIDL_FIELD_KIND { MidlFirst = 0, MidlSecond = 1 } MIDL_FIELD_KIND;
typedef /* [annotation] */ _Win32_SupportedOS_Windows7_ struct MIDL_RECORD
{
    _Win32_AssociatedEnum_(MIDL_FIELD_KIND) int value;
} MIDL_RECORD;
struct _Win32_SupportedOS_Windows7_ IMidlAnnotations;
struct __declspec(uuid(""e4994cce-f062-4613-9dc4-70e3e60cf711"")) IMidlAnnotations
{
    virtual /* [annotation] */ _Win32_SupportedOS_Windows8_
    HRESULT __stdcall Read(
        /* [in][annotation] */ _In_ _Win32_Retained_ void* input,
        /* [out][retval][annotation] */ _Out_retval_ int* result) = 0;
};
", annotationsEnabled: annotationsEnabled);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var record = FindType(reader, "MIDL_RECORD");
            var contract = FindType(reader, "IMidlAnnotations");
            var method = FindMethod(reader, "IMidlAnnotations", "Read");
            var field = record.GetFields().Select(reader.GetFieldDefinition).Single();
            var parameters = method.GetParameters().Select(reader.GetParameter).ToArray();
            var input = parameters.Single(parameter => reader.GetString(parameter.Name) == "input");
            var result = parameters.Single(parameter => reader.GetString(parameter.Name) == "result");
            Assert.Equal("Int32", field.DecodeSignature(new SignatureNames(), null));
            Assert.Equal(new[] { "Void*", "Int32*" }, method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.True(input.Attributes.HasFlag(ParameterAttributes.In));
            Assert.True(result.Attributes.HasFlag(ParameterAttributes.Out));
            Assert.Equal(1, result.GetCustomAttributes().Count(handle => AttributeName(reader, handle) == "RetValAttribute"));
            if (annotationsEnabled)
            {
                AssertStringAttribute(reader, record.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
                AssertStringAttribute(reader, contract.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
                AssertStringAttribute(reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows8.0");
                AssertStringAttribute(reader, field.GetCustomAttributes(), "AssociatedEnumAttribute", "MIDL_FIELD_KIND");
                AssertHasAttribute(reader, input.GetCustomAttributes(), "RetainedAttribute");
            }
            else
            {
                AssertDoesNotHaveAttribute(reader, record.GetCustomAttributes(), "SupportedOSPlatformAttribute");
                AssertDoesNotHaveAttribute(reader, contract.GetCustomAttributes(), "SupportedOSPlatformAttribute");
                AssertDoesNotHaveAttribute(reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute");
                AssertDoesNotHaveAttribute(reader, field.GetCustomAttributes(), "AssociatedEnumAttribute");
                AssertDoesNotHaveAttribute(reader, input.GetCustomAttributes(), "RetainedAttribute");
            }
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void MethodReferencesReachFinalWinmdWithoutChangingNativeSignatures(
            string architecture, string target, bool annotationsEnabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef int HRESULT;
struct __declspec(uuid(""6292cdba-4274-446e-99da-7fe23885266c"")) IMethodReferences
{
    virtual HRESULT __stdcall Next(_Out_writes_(count) int* values, unsigned count) = 0;
    virtual HRESULT __stdcall Skip(unsigned count) = 0;
    virtual HRESULT __stdcall Reset() = 0;
};
typedef IMethodReferences IMethodAlias;
_WIN32META_ANNOTATE_METHOD_(IMethodAlias::Next, _Win32_PreserveResult_);
_Win32_SupportedOS_BEGIN_(Windows7)
int ScopedSentinel();
_WIN32META_ANNOTATE_METHOD_(IMethodReferences::Skip, _Win32_PreserveResult_);
_Win32_SupportedOS_END_()
_WIN32META_ANNOTATE_METHOD_(IMethodReferences::Skip, _Win32_SupportedOS_Windows8_);
", annotationsEnabled: annotationsEnabled, extraSettings: "--exclude\nIMethodAlias\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.DoesNotContain("_WIN32META_METHOD_", fixture.ReadSource());
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var contract = FindType(reader, "IMethodReferences");
            Assert.Equal(new[] { "Next", "Skip", "Reset" },
                contract.GetMethods().Select(reader.GetMethodDefinition).Select(method => reader.GetString(method.Name)));
            var next = FindMethod(reader, "IMethodReferences", "Next");
            var skip = FindMethod(reader, "IMethodReferences", "Skip");
            var reset = FindMethod(reader, "IMethodReferences", "Reset");
            Assert.Equal("Int32", skip.DecodeSignature(new SignatureNames(), null).ReturnType);
            Assert.Equal(new[] { "UInt32" }, skip.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.Equal(new[] { "Int32*", "UInt32" }, next.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.True(next.GetParameters().Select(reader.GetParameter)
                .Single(parameter => reader.GetString(parameter.Name) == "values").Attributes.HasFlag(ParameterAttributes.Out));
            Assert.Equal(annotationsEnabled, next.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            Assert.Equal(annotationsEnabled, skip.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            Assert.False(reset.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            AssertDoesNotHaveAttribute(reader, next.GetCustomAttributes(), "SupportedOSPlatformAttribute");
            if (annotationsEnabled)
                AssertStringAttribute(reader, skip.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows8.0");
            else
                AssertDoesNotHaveAttribute(reader, skip.GetCustomAttributes(), "SupportedOSPlatformAttribute");
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void LegacyAndHeaderResultsUseOnlyPreserveSig(
            string architecture, string target, bool annotationsEnabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef int HRESULT;
_Win32_PreserveResult_ HRESULT __stdcall HeaderResult(unsigned value);
HRESULT __stdcall LegacyMultiple(unsigned value);
HRESULT __stdcall LegacyErrors(unsigned value);
HRESULT __stdcall LegacyMixed(unsigned value);
HRESULT __stdcall OrdinaryResult(unsigned value);
typedef HRESULT (__stdcall* ORDINARY_RESULT_CALLBACK)(unsigned value);
void UseResultCallback(ORDINARY_RESULT_CALLBACK callback);
struct __declspec(uuid(""898ef5f4-bbf4-42f8-9707-a7b6b6214f9e"")) ILegacyResults
{
    virtual HRESULT __stdcall Next(unsigned count) = 0;
    virtual HRESULT __stdcall Skip(unsigned count) = 0;
    virtual HRESULT __stdcall Reset() = 0;
};
", annotationsEnabled: annotationsEnabled);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "LegacyCallbacks.manual.cs"), @"
namespace Test
{
    [Windows.Win32.Foundation.Metadata.CanReturnMultipleSuccessValues]
    public delegate int LegacyMultipleCallback(uint value);
    [Windows.Win32.Foundation.Metadata.CanReturnErrorsAsSuccess]
    public delegate int LegacyErrorsCallback(uint value);
}");
            using var image = Emit(fixture.DirectoryPath, architecture, memberRemaps: new Dictionary<string, string>
            {
                ["LegacyMultiple"] = "[CanReturnMultipleSuccessValues]",
                ["LegacyErrors"] = "[CanReturnErrorsAsSuccess]",
                ["LegacyMixed"] = "[CanReturnErrorsAsSuccess] [CanReturnMultipleSuccessValues] [PreserveSig]",
                ["ILegacyResults::Next"] = "[CanReturnMultipleSuccessValues]",
                ["ILegacyResults::Skip"] = "[CanReturnErrorsAsSuccess]",
            });
            var reader = image.Reader;
            Assert.Equal(annotationsEnabled, FindMethod(reader, "Apis", "HeaderResult")
                .ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            foreach (string name in new[] { "LegacyMultiple", "LegacyErrors", "LegacyMixed" })
            {
                var method = FindMethod(reader, "Apis", name);
                Assert.True(method.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
                Assert.Equal("Int32", method.DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "UInt32" }, method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            }
            foreach (string name in new[] { "Next", "Skip" })
                Assert.True(FindMethod(reader, "ILegacyResults", name).ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            Assert.False(FindMethod(reader, "ILegacyResults", "Reset").ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            Assert.False(FindMethod(reader, "Apis", "OrdinaryResult").ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            foreach (string name in new[] { "LegacyMultipleCallback", "LegacyErrorsCallback" })
            {
                var invoke = FindMethod(reader, name, "Invoke");
                Assert.True(invoke.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
                Assert.True(invoke.ImplAttributes.HasFlag(MethodImplAttributes.Runtime));
                Assert.Equal("Int32", invoke.DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "UInt32" }, invoke.DecodeSignature(new SignatureNames(), null).ParameterTypes);
                Assert.False(FindMethod(reader, name, ".ctor").ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            }
            Assert.False(FindMethod(reader, "ORDINARY_RESULT_CALLBACK", "Invoke").ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            Assert.DoesNotContain(reader.CustomAttributes, handle => AttributeName(reader, handle) is
                "CanReturnErrorsAsSuccessAttribute" or "CanReturnMultipleSuccessValuesAttribute" or "PreserveSigAttribute");
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void LogicalEnumGroupsReachFinalWinmdWithoutChangingNativeTypes(string architecture, string target, bool enabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#define FIRST 2U
#define SECOND 1U
#define ALIAS FIRST
#define ALL 0xffffffffU
#define HIGH (1ULL << 63)
#define WIDE_ALL (~0ULL)
_Win32_FlagsEnum_(OPTIONS, unsigned, FIRST, SECOND, ALIAS, ALL);
_Win32_Enum_(SIGNED, int, ALL);
_Win32_Enum_(WIDE, unsigned long long, HIGH, WIDE_ALL);
#ifdef WIN32METADATA
typedef _WIN32META_ANNOTATION_(""Enum(HISTORICAL_FIRST, HISTORICAL_SECOND)"", FIRST, SECOND) unsigned NAMED;
typedef _WIN32META_ANNOTATION_(""FlagsEnum(FLAG_ALL, FLAG_FIRST)"", 0, FIRST) unsigned NAMED_FLAGS;
#endif
_Win32_AssociatedEnum_(OPTIONS) unsigned GetOptions();
void SetOptions(_Win32_AssociatedEnum_(OPTIONS) unsigned options,
    _Win32_AssociatedEnum_(OPTIONS) unsigned* output);
struct HOLDER { _Win32_AssociatedEnum_(OPTIONS) unsigned options; unsigned after; };
", annotationsEnabled: enabled);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var get = FindMethod(reader, "Apis", "GetOptions");
            Assert.Equal("UInt32", get.DecodeSignature(new SignatureNames(), null).ReturnType);
            var set = FindMethod(reader, "Apis", "SetOptions");
            Assert.Equal(new[] { "UInt32", "UInt32*" }, set.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            var field = FindType(reader, "HOLDER").GetFields().Select(reader.GetFieldDefinition).First();
            Assert.Equal("UInt32", field.DecodeSignature(new SignatureNames(), null));
            if (enabled)
            {
                var options = FindType(reader, "OPTIONS");
                AssertHasAttribute(reader, options.GetCustomAttributes(), "FlagsAttribute");
                AssertDoesNotHaveAttribute(reader, options.GetCustomAttributes(), "ScopedEnumAttribute");
                CheckEnum("OPTIONS", "UInt32", ConstantTypeCode.UInt32, new[] { "FIRST", "SECOND", "ALIAS", "ALL" },
                    new ulong[] { 2, 1, 2, uint.MaxValue });
                CheckEnum("SIGNED", "Int32", ConstantTypeCode.Int32, new[] { "ALL" }, new[] { (ulong)uint.MaxValue });
                CheckEnum("WIDE", "UInt64", ConstantTypeCode.UInt64, new[] { "HIGH", "WIDE_ALL" },
                    new[] { 1UL << 63, ulong.MaxValue });
                CheckEnum("NAMED", "UInt32", ConstantTypeCode.UInt32, new[] { "HISTORICAL_FIRST", "HISTORICAL_SECOND" },
                    new ulong[] { 2, 1 });
                CheckEnum("NAMED_FLAGS", "UInt32", ConstantTypeCode.UInt32, new[] { "FLAG_ALL", "FLAG_FIRST" },
                    new ulong[] { 0, 2 });
                AssertDoesNotHaveAttribute(reader, FindType(reader, "NAMED").GetCustomAttributes(), "FlagsAttribute");
                AssertHasAttribute(reader, FindType(reader, "NAMED_FLAGS").GetCustomAttributes(), "FlagsAttribute");
                var result = get.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 0);
                AssertStringAttribute(reader, result.GetCustomAttributes(), "AssociatedEnumAttribute", "OPTIONS");
                foreach (var parameter in set.GetParameters().Select(reader.GetParameter))
                    AssertStringAttribute(reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute", "OPTIONS");
                AssertStringAttribute(reader, field.GetCustomAttributes(), "AssociatedEnumAttribute", "OPTIONS");
            }
            else
            {
                Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                    type => new[] { "OPTIONS", "SIGNED", "WIDE", "NAMED", "NAMED_FLAGS" }.Contains(reader.GetString(type.Name)));
                AssertDoesNotHaveAttribute(reader, field.GetCustomAttributes(), "AssociatedEnumAttribute");
            }
            AssertMetadataClosure(reader);

            void CheckEnum(string name, string storageName, ConstantTypeCode typeCode, string[] names, ulong[] values)
            {
                var fields = FindType(reader, name).GetFields().Select(reader.GetFieldDefinition).ToArray();
                Assert.Equal(storageName, fields.Single(item => reader.GetString(item.Name) == "value__")
                    .DecodeSignature(new SignatureNames(), null));
                var members = fields.Where(item => reader.GetString(item.Name) != "value__").ToArray();
                Assert.Equal(names, members.Select(item => reader.GetString(item.Name)));
                Assert.Equal(values, members.Select(item =>
                {
                    var constant = reader.GetConstant(item.GetDefaultValue());
                    Assert.Equal(typeCode, constant.TypeCode);
                    var blob = reader.GetBlobReader(constant.Value);
                    return typeCode == ConstantTypeCode.UInt64 ? blob.ReadUInt64() : blob.ReadUInt32();
                }));
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void ForwardLogicalEnumsReachFinalWinmdFromTraversedConsumers(
            string architecture, string target, bool enabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#ifdef WIN32METADATA
typedef unsigned OPTIONS;
typedef unsigned FLAGS;
#endif
_Win32_AssociatedEnum_(OPTIONS) unsigned GetOptions();
void SetFlags(_Win32_AssociatedEnum_(FLAGS) unsigned flags);
#include ""group-values.h""
#include ""group-more.h""
", annotationsEnabled: enabled);
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "group-values.h"), @"
#define FIRST 1U
#define HIGH 0x80000000U
_Win32_Enum_(OPTIONS, unsigned, FIRST);
_Win32_FlagsEnum_(FLAGS, unsigned, FIRST, HIGH);
");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "group-more.h"), @"
#define EXTRA (HIGH | FIRST)
_Win32_Enum_(OPTIONS, unsigned, FIRST, EXTRA);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var get = FindMethod(reader, "Apis", "GetOptions");
            var set = FindMethod(reader, "Apis", "SetFlags");
            Assert.Equal("UInt32", get.DecodeSignature(new SignatureNames(), null).ReturnType);
            Assert.Equal(new[] { "UInt32" }, set.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            if (enabled)
            {
                foreach (string name in new[] { "OPTIONS", "FLAGS" })
                {
                    var group = FindType(reader, name);
                    Assert.Equal("Test", reader.GetString(group.Namespace));
                    var fields = group.GetFields().Select(reader.GetFieldDefinition).ToArray();
                    Assert.Equal("UInt32", fields.Single(field => reader.GetString(field.Name) == "value__")
                        .DecodeSignature(new SignatureNames(), null));
                    var members = fields.Where(field => reader.GetString(field.Name) != "value__").ToArray();
                    Assert.Equal(name == "OPTIONS" ? new[] { "FIRST", "EXTRA" } : new[] { "FIRST", "HIGH" },
                        members.Select(field => reader.GetString(field.Name)));
                    Assert.Equal(new uint[] { 1, name == "OPTIONS" ? 0x80000001U : 0x80000000U },
                        members.Select(field => reader.GetBlobReader(reader.GetConstant(field.GetDefaultValue()).Value).ReadUInt32()));
                    AssertDoesNotHaveAttribute(reader, group.GetCustomAttributes(), "ScopedEnumAttribute");
                }
                AssertDoesNotHaveAttribute(reader, FindType(reader, "OPTIONS").GetCustomAttributes(), "FlagsAttribute");
                AssertHasAttribute(reader, FindType(reader, "FLAGS").GetCustomAttributes(), "FlagsAttribute");
                var result = get.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 0);
                AssertStringAttribute(reader, result.GetCustomAttributes(), "AssociatedEnumAttribute", "OPTIONS");
                var flagsParameter = set.GetParameters().Select(reader.GetParameter).Single(item => item.SequenceNumber == 1);
                AssertStringAttribute(reader, flagsParameter.GetCustomAttributes(), "AssociatedEnumAttribute", "FLAGS");
            }
            else
            {
                Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                    type => new[] { "OPTIONS", "FLAGS" }.Contains(reader.GetString(type.Name)));
                foreach (var handle in get.GetParameters().Concat(set.GetParameters()))
                    AssertDoesNotHaveAttribute(reader, reader.GetParameter(handle).GetCustomAttributes(), "AssociatedEnumAttribute");
            }
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void SharedAssociatedEnumsPreserveTargetsAndConflictingNativeStorage(
            string architecture, string target, bool enabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#define FIRST_CHOICE 1
_Win32_Enum_(SHARED_KIND, unsigned char, FIRST_CHOICE);
enum NATIVE_KIND { NativeChoice = 1 };
struct SHARED_HOLDER {
    _Win32_AssociatedEnum_(SHARED_KIND) unsigned char narrow;
    _Win32_AssociatedEnum_(SHARED_KIND) unsigned wide;
    _Win32_AssociatedEnum_(NATIVE_KIND) unsigned nativeUnsigned;
};
_Win32_AssociatedEnum_(SHARED_KIND) unsigned GetKind();
void UseKinds(_Win32_AssociatedEnum_(SHARED_KIND) unsigned kind,
    _Win32_AssociatedEnum_(SHARED_KIND) unsigned short* output,
    _Win32_AssociatedEnum_(NATIVE_KIND) unsigned nativeKind);
", annotationsEnabled: enabled);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(NativeSurface(fixture, target, metadataEnabled: false),
                NativeSurface(fixture, target, metadataEnabled: true));
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var nativeStorage = FindType(reader, "NATIVE_KIND").GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == "value__");
            Assert.Equal("Int32", nativeStorage.DecodeSignature(new SignatureNames(), null));
            var fields = FindType(reader, "SHARED_HOLDER").GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal(new[] { "Byte", "UInt32", "UInt32" },
                fields.Select(field => field.DecodeSignature(new SignatureNames(), null)));
            var get = FindMethod(reader, "Apis", "GetKind");
            Assert.Equal("UInt32", get.DecodeSignature(new SignatureNames(), null).ReturnType);
            var use = FindMethod(reader, "Apis", "UseKinds");
            Assert.Equal(new[] { "UInt32", "UInt16*", "UInt32" },
                use.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            var parameters = use.GetParameters().Select(reader.GetParameter)
                .Where(parameter => parameter.SequenceNumber != 0).ToArray();
            CheckAssociation(fields[0].GetCustomAttributes(), "SHARED_KIND");
            CheckAssociation(fields[1].GetCustomAttributes(), "SHARED_KIND");
            CheckAssociation(fields[2].GetCustomAttributes(), "NATIVE_KIND");
            CheckAssociation(get.GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 0).GetCustomAttributes(), "SHARED_KIND");
            CheckAssociation(parameters[0].GetCustomAttributes(), "SHARED_KIND");
            CheckAssociation(parameters[1].GetCustomAttributes(), "SHARED_KIND");
            CheckAssociation(parameters[2].GetCustomAttributes(), "NATIVE_KIND");
            if (enabled)
            {
                var groupStorage = FindType(reader, "SHARED_KIND").GetFields().Select(reader.GetFieldDefinition)
                    .Single(field => reader.GetString(field.Name) == "value__");
                Assert.Equal("Byte", groupStorage.DecodeSignature(new SignatureNames(), null));
            }
            else
            {
                Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                    type => reader.GetString(type.Name) == "SHARED_KIND");
            }
            AssertMetadataClosure(reader);

            void CheckAssociation(CustomAttributeHandleCollection attributes, string expected)
            {
                if (enabled)
                    AssertStringAttribute(reader, attributes, "AssociatedEnumAttribute", expected);
                else
                    AssertDoesNotHaveAttribute(reader, attributes, "AssociatedEnumAttribute");
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void TypedImportOverridesReachActualImplMap(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
extern ""C"" {
_Win32_ImportLibrary_(""actual.dll"") int Ordinary();
_Win32_ImportLibrary_(""actual.dll"", ""ActualExport"") int PublicName();
_Win32_ImportLibrary_(""actual.dll"", 660) int OrdinalOnly();
_Win32_ImportLibrary_(""actual.dll"", 65535) int HighestOrdinal();
_Win32_ImportLibrary_(""actual.dll"", ""#660"") int ExplicitOrdinal();
}
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            foreach (var item in new[] { ("Ordinary", "Ordinary"), ("PublicName", "ActualExport"),
                ("OrdinalOnly", "#660"), ("HighestOrdinal", "#65535"), ("ExplicitOrdinal", "#660") })
            {
                var import = FindMethod(image.Reader, "Apis", item.Item1).GetImport();
                Assert.Equal("actual.dll", image.Reader.GetString(image.Reader.GetModuleReference(import.Module).Name));
                Assert.Equal(item.Item2, image.Reader.GetString(import.Name));
            }
            AssertMetadataClosure(image.Reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void SupportedOSOnConstantsPreservesIndividualTargets(string architecture, string target, bool annotationsEnabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
enum _Win32_SupportedOS_Windows7_ REG_NOTIFY_FILTER {
    REG_NOTIFY_DEFAULT = 0,
    REG_NOTIFY_THREAD_AGNOSTIC _Win32_SupportedOS_Windows8_ = 0x10000000,
    REG_NOTIFY_AFTER = 1
};
_Win32_SupportedOS_Windows8_ const unsigned CONSTANT_VALUE = 42;
const unsigned CONSTANT_AFTER = 43;
", annotationsEnabled: annotationsEnabled);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var type = FindType(reader, "REG_NOTIFY_FILTER");
            var storage = type.GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == "value__");
            Assert.Equal("Int32", storage.DecodeSignature(new SignatureNames(), null));
            var fields = type.GetFields().Select(reader.GetFieldDefinition)
                .Where(field => reader.GetString(field.Name) != "value__").ToArray();
            Assert.All(fields, field => Assert.Equal(ConstantTypeCode.Int32, reader.GetConstant(field.GetDefaultValue()).TypeCode));
            Assert.Equal(new[] { "REG_NOTIFY_DEFAULT", "REG_NOTIFY_THREAD_AGNOSTIC", "REG_NOTIFY_AFTER" },
                fields.Select(field => reader.GetString(field.Name)));
            Assert.Equal(new[] { 0, 0x10000000, 1 }, fields.Select(field =>
                reader.GetBlobReader(reader.GetConstant(field.GetDefaultValue()).Value).ReadInt32()));
            var constants = FindType(reader, "Apis").GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal(new[] { "CONSTANT_VALUE", "CONSTANT_AFTER" },
                constants.Select(field => reader.GetString(field.Name)));
            Assert.All(constants, field => Assert.Equal("UInt32", field.DecodeSignature(new SignatureNames(), null)));
            Assert.Equal(new uint[] { 42, 43 }, constants.Select(field =>
                reader.GetBlobReader(reader.GetConstant(field.GetDefaultValue()).Value).ReadUInt32()));
            if (annotationsEnabled)
            {
                AssertStringAttribute(reader, type.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
                AssertStringAttribute(reader, fields[1].GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows8.0");
                AssertStringAttribute(reader, constants[0].GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows8.0");
            }
            else
            {
                AssertDoesNotHaveAttribute(reader, type.GetCustomAttributes(), "SupportedOSPlatformAttribute");
                AssertDoesNotHaveAttribute(reader, fields[1].GetCustomAttributes(), "SupportedOSPlatformAttribute");
                AssertDoesNotHaveAttribute(reader, constants[0].GetCustomAttributes(), "SupportedOSPlatformAttribute");
            }
            AssertDoesNotHaveAttribute(reader, fields[0].GetCustomAttributes(), "SupportedOSPlatformAttribute");
            AssertDoesNotHaveAttribute(reader, fields[2].GetCustomAttributes(), "SupportedOSPlatformAttribute");
            AssertDoesNotHaveAttribute(reader, constants[1].GetCustomAttributes(), "SupportedOSPlatformAttribute");
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void ScopedSupportedOSReachFinalWinmd(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, ScopedDeclarations);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            foreach (string name in new[] { "BeforeScope", "AfterScope" })
                AssertDoesNotHaveAttribute(reader, FindMethod(reader, "Apis", name).GetCustomAttributes(), "SupportedOSPlatformAttribute");
            foreach (var item in new[]
            {
                ("Seven", "windows6.1"), ("ExplicitLater", "windows8.0"), ("ExplicitEqual", "windows6.1"),
                ("ExplicitEarlier", "windows5.0"), ("OlderNested", "windows5.0"),
            })
                AssertStringAttribute(reader, FindMethod(reader, "Apis", item.Item1).GetCustomAttributes(), "SupportedOSPlatformAttribute", item.Item2);
            foreach (string name in new[] { "SCOPED_RECORD", "NESTED_RECORD", "NESTED_ENUM", "SCOPED_ENUM",
                "SCOPED_TOKEN", "USING_TOKEN", "PFN_SCOPED", "PFN_USING", "PFN_USING_ALIAS", "PFN_TYPEDEF_USING_ALIAS", "IScoped" })
                AssertStringAttribute(reader, FindType(reader, name).GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.0.6000");
            AssertStringAttribute(reader, FindType(reader, "PRIMARY_SCOPED").GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
            AssertStringAttribute(reader, FindType(reader, "DIRECT_TOKEN").GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
            Assert.Equal(new[] { "Int32", "UInt32" }, FindType(reader, "SCOPED_RECORD").GetFields().Select(reader.GetFieldDefinition)
                .Select(field => field.DecodeSignature(new SignatureNames(), null)));
            foreach (string name in new[] { "SCOPED_TOKEN", "USING_TOKEN" })
                Assert.Equal("UInt32", reader.GetFieldDefinition(FindType(reader, name).GetFields().Single()).DecodeSignature(new SignatureNames(), null));
            Assert.Equal("SCOPED_TOKEN", FindMethod(reader, "Apis", "UseScopedToken").DecodeSignature(new SignatureNames(), null).ReturnType);
            Assert.Equal("USING_TOKEN", FindMethod(reader, "Apis", "UseUsingToken").DecodeSignature(new SignatureNames(), null).ReturnType);
            foreach (string name in new[] { "PFN_SCOPED", "PFN_USING", "PFN_USING_ALIAS", "PFN_TYPEDEF_USING_ALIAS", "PFN_USING_NATIVE_ALIAS" })
            {
                var invoke = FindMethod(reader, name, "Invoke");
                Assert.Equal(ReadCallingConvention("PFN_SCOPED"), ReadCallingConvention(name));
                var signature = invoke.DecodeSignature(new SignatureNames(), null);
                bool nativeOrigin = name is "PFN_SCOPED" or "PFN_USING_NATIVE_ALIAS";
                Assert.Equal(nativeOrigin ? "Int32" : "SCOPED_TOKEN", signature.ReturnType);
                Assert.Equal(new[] { "Void*", "Int32*" }, signature.ParameterTypes);
                var parameters = invoke.GetParameters().Select(reader.GetParameter).Where(parameter => parameter.SequenceNumber != 0).ToArray();
                Assert.Equal(new[] { "context", "result" }, parameters.Select(parameter => reader.GetString(parameter.Name)));
                Assert.True(parameters[0].Attributes.HasFlag(ParameterAttributes.In));
                AssertHasAttribute(reader, parameters[0].GetCustomAttributes(), "RetainedAttribute");
                Assert.True(parameters[1].Attributes.HasFlag(ParameterAttributes.Out));
                if (!nativeOrigin)
                    AssertHasAttribute(reader, parameters[1].GetCustomAttributes(), "RetValAttribute");
            }
            var com = FindType(reader, "IScoped");
            Assert.True(com.Attributes.HasFlag(TypeAttributes.Interface));
            Assert.Equal(new[] { "VistaMethod", "SevenMethod", "ExplicitMethod", "VistaAgainMethod" },
                com.GetMethods().Select(reader.GetMethodDefinition).Select(method => reader.GetString(method.Name)));
            foreach (var item in new[] { ("VistaMethod", "windows6.0.6000"), ("SevenMethod", "windows6.1"),
                ("ExplicitMethod", "windows5.0"), ("VistaAgainMethod", "windows6.0.6000") })
                AssertStringAttribute(reader, FindMethod(reader, "IScoped", item.Item1).GetCustomAttributes(), "SupportedOSPlatformAttribute", item.Item2);
            AssertStringAttribute(reader, FindType(reader, "IContainerOnly").GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
            var member = FindMethod(reader, "IContainerOnly", "UnannotatedMember");
            AssertDoesNotHaveAttribute(reader, member.GetCustomAttributes(), "SupportedOSPlatformAttribute");
            AssertHasAttribute(reader, member.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 1)
                .GetCustomAttributes(), "RetValAttribute");
            foreach (var attributes in reader.FieldDefinitions.Select(reader.GetFieldDefinition).Select(field => field.GetCustomAttributes())
                .Concat(reader.MethodDefinitions.Select(reader.GetMethodDefinition).SelectMany(method => method.GetParameters())
                    .Select(reader.GetParameter).Select(parameter => parameter.GetCustomAttributes())))
                AssertDoesNotHaveAttribute(reader, attributes, "SupportedOSPlatformAttribute");
            AssertMetadataClosure(reader);

            byte[] ReadCallingConvention(string name) => reader.GetBlobBytes(reader.GetCustomAttribute(
                FindType(reader, name).GetCustomAttributes().Single(handle => AttributeName(reader, handle) == "UnmanagedFunctionPointerAttribute")).Value);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void CSupportedOSScopesReachFinalWinmd(string architecture, string target)
        {
            const string declarations = @"
int Before(void);
_Win32_SupportedOS_BEGIN_(WindowsVista)
struct C_RECORD { int value; void* context; };
enum C_ENUM { C_VALUE = 1 };
typedef unsigned C_TOKEN;
typedef int (__stdcall* C_CALLBACK)(_In_ _Win32_Retained_ void* context);
_Win32_ImportLibrary_(""native.dll"") _Win32_SetLastError_ int Within(void);
_Win32_SupportedOS_END_()
_Win32_SupportedOS_BEGIN_(Windows7)
int Nested(void);
_Win32_SupportedOS_END_()
_Win32_SupportedOS_Windows2000_ int Explicit(void);
_Win32_SupportedOS_BEGIN_(WindowsVista)
int Restored(void);
_Win32_SupportedOS_END_()
int After(void);
";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                extraSettings: "--language\nc\n--std\nc11\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(NativeSurface(fixture, target, metadataEnabled: false, language: "c"),
                NativeSurface(fixture, target, metadataEnabled: true, language: "c"));
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            foreach (string name in new[] { "C_RECORD", "C_ENUM", "C_TOKEN", "C_CALLBACK" })
                AssertStringAttribute(reader, FindType(reader, name).GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.0.6000");
            foreach (var item in new[] { ("Within", "windows6.0.6000"), ("Nested", "windows6.1"),
                ("Explicit", "windows5.0"), ("Restored", "windows6.0.6000") })
                AssertStringAttribute(reader, FindMethod(reader, "Apis", item.Item1).GetCustomAttributes(), "SupportedOSPlatformAttribute", item.Item2);
            foreach (string name in new[] { "Before", "After" })
                AssertDoesNotHaveAttribute(reader, FindMethod(reader, "Apis", name).GetCustomAttributes(), "SupportedOSPlatformAttribute");
            var import = FindMethod(reader, "Apis", "Within").GetImport();
            Assert.Equal("native.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));
            Assert.True(import.Attributes.HasFlag(MethodImportAttributes.SetLastError));
            AssertHasAttribute(reader, FindMethod(reader, "C_CALLBACK", "Invoke").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 1).GetCustomAttributes(), "RetainedAttribute");
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void SupportedOSScopesPreserveNativeAbiAndTheOptInGate(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, ScopedDeclarations);
            Assert.Equal(NativeSurface(fixture, target, metadataEnabled: false), NativeSurface(fixture, target, metadataEnabled: true));
            using var disabled = new HeaderAnnotationTests.NativeFixture(architecture, target, ScopedDeclarations, annotationsEnabled: false);
            Assert.True(disabled.Run() == 0, disabled.Diagnostics);
            Assert.DoesNotContain("SupportedOSPlatform", disabled.ReadSource());
            Assert.DoesNotContain("NativeAnnotation(\"SupportedOSPlatform", disabled.ReadSource());
            Assert.Contains("NativeAnnotation(\"Name=SAL_name", disabled.ReadSource());
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void NativeFieldCountSalReachesFinalWinmd(string architecture, string target, bool nativeFieldArrayInfo)
        {
            const string declarations = @"
typedef unsigned long DHCP_IP_ADDRESS;
typedef DHCP_IP_ADDRESS* LPDHCP_IP_ADDRESS;
struct DHCP_IP_ARRAY {
    unsigned long NumElements;
    _Field_size_(NumElements) LPDHCP_IP_ADDRESS Elements;
};
";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture.DirectoryPath, architecture, nativeFieldArrayInfo: nativeFieldArrayInfo);
            var reader = image.Reader;
            var fields = FindType(reader, "DHCP_IP_ARRAY").GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal(new[] { "NumElements", "Elements" }, fields.Select(field => reader.GetString(field.Name)));
            Assert.Equal(new[] { "UInt32", "UInt32*" },
                fields.Select(field => field.DecodeSignature(new SignatureNames(), null)));
            AssertDoesNotHaveAttribute(reader, fields[0].GetCustomAttributes(), "NativeArrayInfoAttribute");
            if (!nativeFieldArrayInfo)
            {
                AssertDoesNotHaveAttribute(reader, fields[1].GetCustomAttributes(), "NativeArrayInfoAttribute");
                AssertMetadataClosure(reader);
                return;
            }

            var attribute = reader.GetCustomAttribute(Assert.Single(fields[1].GetCustomAttributes()
                .Where(handle => AttributeName(reader, handle) == "NativeArrayInfoAttribute")));
            var blob = reader.GetBlobReader(attribute.Value);
            Assert.Equal(1, blob.ReadUInt16());
            Assert.Equal(1, blob.ReadUInt16());
            Assert.Equal(0x53, blob.ReadByte());
            Assert.Equal(0x0e, blob.ReadByte());
            Assert.Equal("CountFieldName", blob.ReadSerializedString());
            Assert.Equal("NumElements", blob.ReadSerializedString());
            Assert.Equal(0, blob.RemainingBytes);
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeHeadersReachFinalWinmd(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, Declarations);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var nativeCom = CSharpSyntaxTree.ParseText(File.ReadAllText(fixture.Output)).GetRoot().DescendantNodes()
                .OfType<StructDeclarationSyntax>().Single(node => node.Identifier.ValueText == "IHeaderSample");
            var nativeBuffer = nativeCom.Members.OfType<MethodDeclarationSyntax>().Single(node => node.Identifier.ValueText == "Buffer");
            Assert.True(nativeBuffer.ParameterList.Parameters[0].AttributeLists.ToString().Contains("ContainsInteriorPointers"),
                nativeCom.ToFullString());
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var imported = FindMethod(reader, "Apis", "Imported");
            var import = imported.GetImport();
            Assert.Equal("header.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));
            Assert.True(import.Attributes.HasFlag(MethodImportAttributes.SetLastError));
            Assert.True(imported.Attributes.HasFlag(MethodAttributes.Static));
            Assert.False(imported.DecodeSignature(new SignatureNames(), null).Header.IsInstance);
            AssertStringAttribute(reader, imported.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows10.0.10240");
            var parameters = imported.GetParameters().Select(reader.GetParameter).ToArray();
            Assert.True(parameters[0].Attributes.HasFlag(ParameterAttributes.In));
            AssertHasAttribute(reader, parameters[0].GetCustomAttributes(), "RetainedAttribute");
            Assert.True(parameters[1].Attributes.HasFlag(ParameterAttributes.Out));
            Assert.True(parameters[1].Attributes.HasFlag(ParameterAttributes.Optional));
            AssertHasAttribute(reader, parameters[1].GetCustomAttributes(), "ContainsInteriorPointersAttribute");
            AssertHasAttribute(reader, parameters[1].GetCustomAttributes(), "MemorySizeAttribute");

            var open = FindMethod(reader, "Apis", "OpenThing");
            var result = open.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 0);
            AssertStringAttribute(reader, result.GetCustomAttributes(), "RAIIFreeAttribute", "CloseThing");
            Assert.Equal(new long[] { 0, -1 }, ReadInvalidValues(reader, result.GetCustomAttributes()));
            AssertDoesNotHaveAttribute(reader, open.GetCustomAttributes(), "RAIIFreeAttribute");

            var create = FindMethod(reader, "Apis", "CreateThing");
            var output = create.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 1);
            Assert.True(output.Attributes.HasFlag(ParameterAttributes.Out));
            AssertStringAttribute(reader, output.GetCustomAttributes(), "RAIIFreeAttribute", "CloseThing");
            Assert.Equal(new long[] { 0 }, ReadInvalidValues(reader, output.GetCustomAttributes()));
            Assert.True(FindMethod(reader, "Apis", "ExactResult").ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            var retval = FindMethod(reader, "Apis", "Retval").GetParameters().Select(reader.GetParameter).Single();
            AssertHasAttribute(reader, retval.GetCustomAttributes(), "RetValAttribute");
            Assert.True(retval.Attributes.HasFlag(ParameterAttributes.Out));
            var midlRetval = FindMethod(reader, "Apis", "MidlRetval").GetParameters().Select(reader.GetParameter).Single();
            AssertHasAttribute(reader, midlRetval.GetCustomAttributes(), "RetValAttribute");
            Assert.True(midlRetval.Attributes.HasFlag(ParameterAttributes.Out));

            var associated = FindMethod(reader, "Apis", "AssociatedReturn").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 0);
            AssertStringAttribute(reader, associated.GetCustomAttributes(), "AssociatedEnumAttribute", "Options");
            var optionParameter = FindMethod(reader, "Apis", "ReadOption").GetParameters().Select(reader.GetParameter).Single();
            AssertStringAttribute(reader, optionParameter.GetCustomAttributes(), "AssociatedEnumAttribute", "Options");

            var record = FindType(reader, "DESCRIPTION");
            AssertStringAttribute(reader, record.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows10.0.10240");
            var flags = record.GetFields().Select(reader.GetFieldDefinition).Single(field => reader.GetString(field.Name) == "flags");
            AssertStringAttribute(reader, flags.GetCustomAttributes(), "AssociatedEnumAttribute", "Options");
            var options = FindType(reader, "Options");
            AssertStringAttribute(reader, options.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows10.0.10240");
            Assert.Equal(2, options.GetCustomAttributes().Count(handle => AttributeName(reader, handle) == "AssociatedConstantAttribute"));
            var scoped = FindType(reader, "ScopedOptions");
            AssertHasAttribute(reader, scoped.GetCustomAttributes(), "ScopedEnumAttribute");
            AssertHasAttribute(reader, scoped.GetCustomAttributes(), "FlagsAttribute");

            var token = FindType(reader, "TOKEN");
            AssertHasAttribute(reader, token.GetCustomAttributes(), "NativeTypedefAttribute");
            AssertStringAttribute(reader, token.GetCustomAttributes(), "AlsoUsableForAttribute", "OTHER_TOKEN");
            AssertStringAttribute(reader, token.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
            var tokenSignature = FindMethod(reader, "Apis", "UseToken").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("TOKEN", tokenSignature.ReturnType);
            Assert.Equal(new[] { "TOKEN", "TOKEN*" }, tokenSignature.ParameterTypes);
            var callback = FindType(reader, "PFN_ALIAS");
            AssertStringAttribute(reader, callback.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
            var invoke = FindMethod(reader, "PFN_ALIAS", "Invoke");
            Assert.Equal(new[] { "context", "count" }, invoke.GetParameters().Select(reader.GetParameter).Select(parameter => reader.GetString(parameter.Name)));
            Assert.Equal(new[] { "Void*", "UInt32" }, invoke.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            AssertHasAttribute(reader, invoke.GetParameters().Select(reader.GetParameter).First().GetCustomAttributes(), "RetainedAttribute");

            var com = FindType(reader, "IHeaderSample");
            Assert.True(com.Attributes.HasFlag(TypeAttributes.Interface));
            Assert.Equal(new[] { "Exact", "Produce", "Buffer" }, com.GetMethods().Select(reader.GetMethodDefinition).Select(method => reader.GetString(method.Name)));
            var exact = FindMethod(reader, "IHeaderSample", "Exact");
            Assert.True(exact.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
            AssertStringAttribute(reader, exact.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
            var produced = FindMethod(reader, "IHeaderSample", "Produce").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 0);
            AssertStringAttribute(reader, produced.GetCustomAttributes(), "RAIIFreeAttribute", "CloseThing");
            Assert.Equal(new long[] { 0, -1 }, ReadInvalidValues(reader, produced.GetCustomAttributes()));
            var buffer = FindMethod(reader, "IHeaderSample", "Buffer").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 1);
            AssertHasAttribute(reader, buffer.GetCustomAttributes(), "ContainsInteriorPointersAttribute");
            Assert.True(buffer.Attributes.HasFlag(ParameterAttributes.Out));
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void AssociatedEnumPreservesNativeTypesDespiteForeignShortNames(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef int INTERNET_SCHEME;
enum WINHTTP_INTERNET_SCHEME : unsigned { WinHttpHttp = 1, WinHttpHttps = 2 };
struct COMPONENTS {
    _Win32_AssociatedEnum_(WINHTTP_INTERNET_SCHEME) INTERNET_SCHEME Scheme;
    _Win32_AssociatedEnum_(WINHTTP_INTERNET_SCHEME) INTERNET_SCHEME* Schemes;
    _Win32_AssociatedEnum_(WINHTTP_INTERNET_SCHEME) INTERNET_SCHEME FixedSchemes[2];
    INTERNET_SCHEME LegacyScheme;
};
_Win32_AssociatedEnum_(WINHTTP_INTERNET_SCHEME) INTERNET_SCHEME AssociatedReturn();
_Win32_AssociatedEnum_(WINHTTP_INTERNET_SCHEME) INTERNET_SCHEME* AssociatedPointerReturn();
void UseSchemes(_Win32_AssociatedEnum_(WINHTTP_INTERNET_SCHEME) INTERNET_SCHEME Scheme,
    _Win32_AssociatedEnum_(WINHTTP_INTERNET_SCHEME) INTERNET_SCHEME* Schemes);
INTERNET_SCHEME LegacyReturn(INTERNET_SCHEME Scheme, INTERNET_SCHEME* Schemes);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "Foreign.manual.cs"), @"
namespace Foreign {
    public enum INTERNET_SCHEME : int { ForeignHttp = 3, ForeignHttps = 4 }
}");
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var provider = new SignatureNames(qualifiedNames: true);
            var fields = FindType(reader, "COMPONENTS").GetFields().Select(reader.GetFieldDefinition)
                .ToDictionary(field => reader.GetString(field.Name));
            foreach (var pair in new[] { ("Scheme", "Int32"), ("Schemes", "Int32*"), ("FixedSchemes", "Int32[]") })
            {
                var field = fields[pair.Item1];
                Assert.Equal(pair.Item2, field.DecodeSignature(provider, null));
                AssertStringAttribute(reader, field.GetCustomAttributes(), "AssociatedEnumAttribute", "WINHTTP_INTERNET_SCHEME");
            }
            Assert.Equal("Foreign.INTERNET_SCHEME", fields["LegacyScheme"].DecodeSignature(provider, null));

            foreach (var pair in new[] { ("AssociatedReturn", "Int32"), ("AssociatedPointerReturn", "Int32*") })
            {
                var method = FindMethod(reader, "Apis", pair.Item1);
                Assert.Equal(pair.Item2, method.DecodeSignature(provider, null).ReturnType);
                var result = method.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 0);
                AssertStringAttribute(reader, result.GetCustomAttributes(), "AssociatedEnumAttribute", "WINHTTP_INTERNET_SCHEME");
            }
            var use = FindMethod(reader, "Apis", "UseSchemes");
            Assert.Equal(new[] { "Int32", "Int32*" }, use.DecodeSignature(provider, null).ParameterTypes);
            foreach (var parameter in use.GetParameters().Select(reader.GetParameter))
                AssertStringAttribute(reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute", "WINHTTP_INTERNET_SCHEME");
            var legacy = FindMethod(reader, "Apis", "LegacyReturn").DecodeSignature(provider, null);
            Assert.Equal("Foreign.INTERNET_SCHEME", legacy.ReturnType);
            Assert.Equal(new[] { "Foreign.INTERNET_SCHEME", "Foreign.INTERNET_SCHEME*" }, legacy.ParameterTypes);
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void MidlAndSalRetvalReachFinalWinmdOnce(string architecture, string target, bool annotationsEnabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef int HRESULT;
typedef wchar_t* BSTR;
extern ""C"" HRESULT __stdcall NativeRetval(/* [retval][out] */ _Out_retval_ BSTR* Value);
typedef HRESULT (__stdcall* PFN_RETVAL)(/* [retval][out] */ _Out_retval_ BSTR* Value);
struct __declspec(uuid(""5a076bce-18f2-49bb-861f-48850743e9d3"")) IRetvalSample {
    virtual HRESULT __stdcall Combined(/* [retval][out] */ _Out_retval_ BSTR* Value) = 0;
    virtual HRESULT __stdcall SalOnly(_Out_retval_ BSTR* Value) = 0;
    virtual HRESULT __stdcall HeaderAndSal(_Out_retval_ _Win32_Retval_ BSTR* Value) = 0;
    virtual HRESULT __stdcall MidlOnly(/* [retval][out] */ _Out_ BSTR* Value) = 0;
    virtual HRESULT __stdcall RepeatedSal(/* [retval][out] */ _Out_retval_ _Out_retval_ BSTR* Value) = 0;
    virtual HRESULT __stdcall Ordinary(_Out_ BSTR* Value) = 0;
};
", annotationsEnabled: annotationsEnabled);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadSource();
            Assert.Contains("Name=SAL_retval", source);
            if (annotationsEnabled)
                Assert.Contains("global::Windows.Win32.Foundation.Metadata.RetVal", source);

            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            foreach (string methodName in new[] { "Combined", "SalOnly", "HeaderAndSal", "MidlOnly", "RepeatedSal", "Ordinary" })
            {
                var method = FindMethod(reader, "IRetvalSample", methodName);
                var parameter = method.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 1);
                int expected = methodName == "Ordinary" || (methodName == "MidlOnly" && !annotationsEnabled) ? 0 : 1;
                Assert.Equal(expected, parameter.GetCustomAttributes().Count(handle => AttributeName(reader, handle) == "RetValAttribute"));
                Assert.True(parameter.Attributes.HasFlag(ParameterAttributes.Out));
                Assert.False(parameter.Attributes.HasFlag(ParameterAttributes.In));
                Assert.Equal(new[] { "UInt16**" }, method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            }
            foreach (var method in new[] { FindMethod(reader, "Apis", "NativeRetval"), FindMethod(reader, "PFN_RETVAL", "Invoke") })
            {
                var parameter = method.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 1);
                Assert.Equal(1, parameter.GetCustomAttributes().Count(handle => AttributeName(reader, handle) == "RetValAttribute"));
                Assert.True(parameter.Attributes.HasFlag(ParameterAttributes.Out));
                Assert.Equal(new[] { "UInt16**" }, method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            }
            foreach (var parameter in reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                .SelectMany(method => method.GetParameters()).Select(reader.GetParameter))
            {
                Assert.InRange(parameter.GetCustomAttributes().Count(handle => AttributeName(reader, handle) == "RetValAttribute"), 0, 1);
            }
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void MetadataMacrosDoNotChangeNativeAbi(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, Declarations);
            var ordinarySurface = NativeSurface(fixture, target, metadataEnabled: false);
            Assert.Equal(13, ordinarySurface.Count(value => value.StartsWith("function ", StringComparison.Ordinal)));
            Assert.Contains(ordinarySurface, value => value.StartsWith("record DESCRIPTION ", StringComparison.Ordinal));
            Assert.Contains(ordinarySurface, value => value.StartsWith("record IHeaderSample ", StringComparison.Ordinal));
            Assert.Equal(ordinarySurface, NativeSurface(fixture, target, metadataEnabled: true));
            using var ordinary = new HeaderAnnotationTests.NativeFixture(architecture, target, Declarations, annotationsEnabled: false);
            Assert.True(ordinary.Run() == 0, ordinary.Diagnostics);
            Assert.DoesNotContain("RAIIFree", File.ReadAllText(ordinary.Output));
            Assert.DoesNotContain("ContainsInteriorPointers", File.ReadAllText(ordinary.Output));
        }

        [Fact]
        public void AllReviewedOsMacrosReachWinmd()
        {
            var versions = new Dictionary<string, string>
            {
                ["Windows2000"] = "windows5.0", ["WindowsXP"] = "windows5.1.2600",
                ["WindowsVista"] = "windows6.0.6000", ["Windows7"] = "windows6.1",
                ["Windows8"] = "windows8.0", ["Windows81"] = "windows8.1",
                ["10240"] = "windows10.0.10240", ["10586"] = "windows10.0.10586",
                ["14393"] = "windows10.0.14393", ["15063"] = "windows10.0.15063",
                ["16299"] = "windows10.0.16299", ["17134"] = "windows10.0.17134",
                ["17763"] = "windows10.0.17763", ["18362"] = "windows10.0.18362",
                ["19041"] = "windows10.0.19041", ["Server2000"] = "windowsserver2000",
                ["Server2003"] = "windowsserver2003", ["Server2008"] = "windowsserver2008",
                ["Server2012"] = "windowsserver2012", ["Server2016"] = "windowsserver2016",
            };
            string declarations = string.Join("\n", versions.Keys.Select(version =>
                $"_Win32_SupportedOS_{version}_ int OS_{version}();\n" +
                $"_Win32_SupportedOS_BEGIN_({version})\nint SCOPED_OS_{version}();\n_Win32_SupportedOS_END_()"));
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", declarations);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "x64");
            foreach (var version in versions)
            {
                AssertStringAttribute(image.Reader, FindMethod(image.Reader, "Apis", "OS_" + version.Key).GetCustomAttributes(),
                    "SupportedOSPlatformAttribute", version.Value);
                AssertStringAttribute(image.Reader, FindMethod(image.Reader, "Apis", "SCOPED_OS_" + version.Key).GetCustomAttributes(),
                    "SupportedOSPlatformAttribute", version.Value);
            }
        }

        [Fact]
        public void CrossArchitectureEmissionRetainsDifferentAnnotationFacts()
        {
            const string declarations = @"
enum First { FirstA = 1 };
enum Second { SecondA = 1 };
#ifdef _M_IX86
_Win32_AssociatedEnum_(First) unsigned F();
struct S { _Win32_AssociatedEnum_(First) unsigned value; };
enum _Win32_AssociatedConstant_(FirstA) E { A = 1 };
#else
_Win32_AssociatedEnum_(Second) unsigned F();
struct S { _Win32_AssociatedEnum_(Second) unsigned value; };
enum _Win32_AssociatedConstant_(SecondA) E { A = 1 };
#endif
";
            using var x86 = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc", declarations);
            using var x64 = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", declarations);
            using var arm64 = new HeaderAnnotationTests.NativeFixture("arm64", "aarch64-pc-windows-msvc", declarations);
            foreach (var fixture in new[] { x86, x64, arm64 })
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                if (fixture != x86)
                {
                    string architecture = Path.GetFileName(Path.GetDirectoryName(fixture.Output));
                    string directory = Path.Combine(x86.DirectoryPath, architecture);
                    Directory.CreateDirectory(directory);
                    File.Copy(fixture.Output, Path.Combine(directory, "Bindings.cs"));
                }
            }
            using var image = Emit(x86, "crossarch");
            var reader = image.Reader;
            var methods = FindType(reader, "Apis").GetMethods().Select(reader.GetMethodDefinition)
                .Where(method => reader.GetString(method.Name) == "F").ToArray();
            Assert.Equal(2, methods.Length);
            var values = methods.Select(method =>
            {
                AssertHasAttribute(reader, method.GetCustomAttributes(), "SupportedArchitectureAttribute");
                var result = method.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 0);
                return ReadStringAttribute(reader, result.GetCustomAttributes(), "AssociatedEnumAttribute");
            }).OrderBy(value => value).ToArray();
            Assert.Equal(new[] { "First", "Second" }, values);
            var records = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Where(type => reader.GetString(type.Name) == "S").ToArray();
            Assert.Equal(2, records.Length);
            Assert.Equal(new[] { "First", "Second" }, records.Select(record =>
            {
                AssertHasAttribute(reader, record.GetCustomAttributes(), "SupportedArchitectureAttribute");
                return ReadStringAttribute(reader, reader.GetFieldDefinition(record.GetFields().Single()).GetCustomAttributes(), "AssociatedEnumAttribute");
            }).OrderBy(value => value));
            var enums = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Where(type => reader.GetString(type.Name) == "E").ToArray();
            Assert.Equal(2, enums.Length);
            Assert.Equal(new[] { "FirstA", "SecondA" }, enums.Select(type =>
            {
                AssertHasAttribute(reader, type.GetCustomAttributes(), "SupportedArchitectureAttribute");
                return ReadStringAttribute(reader, type.GetCustomAttributes(), "AssociatedConstantAttribute");
            }).OrderBy(value => value));
            AssertMetadataClosure(reader);
        }

        [Fact]
        public void CrossArchitectureEmissionRetainsLogicalGroupValues()
        {
            const string declarations = @"
#ifdef _M_IX86
#define FIRST 1U
#else
#define FIRST 2U
#endif
#define SECOND 4U
_Win32_FlagsEnum_(OPTIONS, unsigned, FIRST, SECOND);
void F(_Win32_AssociatedEnum_(OPTIONS) unsigned options);
";
            using var x86 = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc", declarations);
            using var x64 = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", declarations);
            using var arm64 = new HeaderAnnotationTests.NativeFixture("arm64", "aarch64-pc-windows-msvc", declarations);
            foreach (var fixture in new[] { x86, x64, arm64 })
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                if (fixture == x86)
                    continue;
                string architecture = Path.GetFileName(Path.GetDirectoryName(fixture.Output));
                string directory = Path.Combine(x86.DirectoryPath, architecture);
                Directory.CreateDirectory(directory);
                foreach (string path in new[] { fixture.Output, Path.ChangeExtension(fixture.Output, ".header-types.cs") })
                    File.Copy(path, Path.Combine(directory, Path.GetFileName(path)));
            }
            using var image = Emit(x86, "crossarch");
            var reader = image.Reader;
            var groups = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "OPTIONS").ToArray();
            Assert.Equal(2, groups.Length);
            Assert.Equal(new uint[] { 1, 2 }, groups.Select(group =>
            {
                AssertHasAttribute(reader, group.GetCustomAttributes(), "FlagsAttribute");
                AssertHasAttribute(reader, group.GetCustomAttributes(), "SupportedArchitectureAttribute");
                AssertDoesNotHaveAttribute(reader, group.GetCustomAttributes(), "ScopedEnumAttribute");
                var first = group.GetFields().Select(reader.GetFieldDefinition)
                    .Single(field => reader.GetString(field.Name) == "FIRST");
                return reader.GetBlobReader(reader.GetConstant(first.GetDefaultValue()).Value).ReadUInt32();
            }).OrderBy(value => value));
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void LogicalGroupsAcrossGeneratedFilesReachFinalWinmd(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#define FIRST 1U
#define SECOND 2U
_Win32_Enum_(OPTIONS, unsigned, FIRST, SECOND);
void F(_Win32_AssociatedEnum_(OPTIONS) unsigned options);
", multipleFiles: true);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            Assert.Equal("OPTIONS", reader.GetString(FindType(reader, "OPTIONS").Name));
            var method = FindMethod(reader, "Apis", "F");
            Assert.Equal(new[] { "UInt32" }, method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            var parameter = reader.GetParameter(method.GetParameters().Single());
            AssertStringAttribute(reader, parameter.GetCustomAttributes(), "AssociatedEnumAttribute", "OPTIONS");
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void LogicalGroupContributionsFromIndependentPartitionsReachFinalWinmd(string architecture, string target, bool flags)
        {
            string firstDeclarations = @"
#define FIRST 1U
#define SHARED (-1)
const unsigned LOOSE_A = 8U;
_Win32_AssociatedConstant_(LOOSE_A) _Win32_Enum_(ERROR_GROUP, unsigned, FIRST, SHARED);
void First(_Win32_AssociatedEnum_(ERROR_GROUP) unsigned error);
";
            string extraDeclarations = @"
#define SHARED 0xFFFFFFFFU
#define EXTRA 4U
const unsigned LOOSE_B = 16U;
_Win32_AssociatedConstant_(LOOSE_B) _Win32_Enum_(ERROR_GROUP, unsigned, SHARED, EXTRA);
void Extra(_Win32_AssociatedEnum_(ERROR_GROUP) unsigned error);
";
            using var first = new HeaderAnnotationTests.NativeFixture(architecture, target,
                flags ? firstDeclarations.Replace("_Win32_Enum_", "_Win32_FlagsEnum_", StringComparison.Ordinal) : firstDeclarations);
            using var extra = new HeaderAnnotationTests.NativeFixture(architecture, target,
                flags ? extraDeclarations.Replace("_Win32_Enum_", "_Win32_FlagsEnum_", StringComparison.Ordinal) : extraDeclarations);
            Assert.True(first.Run() == 0, first.Diagnostics);
            Assert.True(extra.Run() == 0, extra.Diagnostics);
            string directory = Path.GetDirectoryName(first.Output);
            File.Copy(extra.Output, Path.Combine(directory, "Extra.cs"));
            File.Copy(Path.ChangeExtension(extra.Output, ".header-types.cs"), Path.Combine(directory, "Extra.header-types.cs"));
            using var image = Emit(first, architecture);
            var reader = image.Reader;
            var group = FindType(reader, "ERROR_GROUP");
            var fields = group.GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal(new[] { "value__", "FIRST", "SHARED", "EXTRA" }, fields.Select(field => reader.GetString(field.Name)));
            Assert.Equal("UInt32", fields[0].DecodeSignature(new SignatureNames(), null));
            Assert.Equal(new uint[] { 1, uint.MaxValue, 4 }, fields.Skip(1).Select(field =>
                reader.GetBlobReader(reader.GetConstant(field.GetDefaultValue()).Value).ReadUInt32()));
            Assert.Equal(flags ? 1 : 0, group.GetCustomAttributes().Count(handle => AttributeName(reader, handle) == "FlagsAttribute"));
            Assert.Equal(2, group.GetCustomAttributes().Count(handle => AttributeName(reader, handle) == "AssociatedConstantAttribute"));
            Assert.Contains(FindType(reader, "Apis").GetFields(), handle => reader.GetString(reader.GetFieldDefinition(handle).Name) == "LOOSE_A");
            Assert.Contains(FindType(reader, "Apis").GetFields(), handle => reader.GetString(reader.GetFieldDefinition(handle).Name) == "LOOSE_B");
            foreach (string methodName in new[] { "First", "Extra" })
            {
                var method = FindMethod(reader, "Apis", methodName);
                Assert.Equal(new[] { "UInt32" }, method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
                AssertStringAttribute(reader, reader.GetParameter(method.GetParameters().Single()).GetCustomAttributes(),
                    "AssociatedEnumAttribute", "ERROR_GROUP");
            }
            AssertMetadataClosure(reader);
        }

        [Fact]
        public void CrossArchitectureLogicalGroupContributionsIncludeCommonMembers()
        {
            using var common = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc", @"
#define COMMON 1U
_Win32_Enum_(ERROR_GROUP, unsigned, COMMON);
void Common(_Win32_AssociatedEnum_(ERROR_GROUP) unsigned error);
");
            const string declarations = @"
#ifdef _M_IX86
#define EXTRA 2U
#else
#define EXTRA 4U
#endif
_Win32_Enum_(ERROR_GROUP, unsigned, EXTRA);
void Extra(_Win32_AssociatedEnum_(ERROR_GROUP) unsigned error);
";
            using var x86 = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc", declarations);
            using var x64 = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", declarations);
            using var arm64 = new HeaderAnnotationTests.NativeFixture("arm64", "aarch64-pc-windows-msvc", declarations);
            Assert.True(common.Run() == 0, common.Diagnostics);
            foreach (var fixture in new[] { x86, x64, arm64 })
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                string architecture = Path.GetFileName(Path.GetDirectoryName(fixture.Output));
                string directory = Path.Combine(common.DirectoryPath, architecture);
                Directory.CreateDirectory(directory);
                File.Copy(fixture.Output, Path.Combine(directory, "Extra.cs"));
                File.Copy(Path.ChangeExtension(fixture.Output, ".header-types.cs"), Path.Combine(directory, "Extra.header-types.cs"));
            }
            using var image = Emit(common, "crossarch");
            var reader = image.Reader;
            var groups = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "ERROR_GROUP").ToArray();
            Assert.Equal(2, groups.Length);
            Assert.Equal(new uint[] { 2, 4 }, groups.Select(group =>
            {
                AssertHasAttribute(reader, group.GetCustomAttributes(), "SupportedArchitectureAttribute");
                var fields = group.GetFields().Select(reader.GetFieldDefinition).ToArray();
                Assert.Equal(new[] { "value__", "COMMON", "EXTRA" }, fields.Select(field => reader.GetString(field.Name)));
                Assert.Equal(1U, reader.GetBlobReader(reader.GetConstant(fields[1].GetDefaultValue()).Value).ReadUInt32());
                return reader.GetBlobReader(reader.GetConstant(fields[2].GetDefaultValue()).Value).ReadUInt32();
            }).OrderBy(value => value));
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("uint", "2", "", "Conflicting logical group values")]
        [InlineData("int", "1", "", "Conflicting logical group storage")]
        [InlineData("uint", "1", "[global::System.Flags]", "Conflicting logical group flags")]
        public void ConflictingLogicalGroupContributionsCannotBeUnioned(
            string storage, string value, string attributes, string diagnostic)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FIRST 1U
_Win32_Enum_(ERROR_GROUP, unsigned, FIRST);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            File.WriteAllText(Path.Combine(Path.GetDirectoryName(fixture.Output), "Extra.header-types.cs"),
                $"namespace Test {{ {attributes} public enum ERROR_GROUP : {storage} {{ FIRST = unchecked(({storage}){value}UL) }} }}");
            var exception = Assert.Throws<InvalidOperationException>(() => Emit(fixture, "x64"));
            Assert.Contains("WMA003", exception.Message);
            Assert.Contains(diagnostic, exception.Message);
        }

        [Fact]
        public void LogicalGroupUnionDoesNotAbsorbLegacyOrNativeEnumDefinitions()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FIRST 1U
_Win32_Enum_(ERROR_GROUP, unsigned, FIRST);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            File.WriteAllText(Path.Combine(Path.GetDirectoryName(fixture.Output), "Extra.header-types.cs"),
                "namespace Test { public enum ERROR_GROUP : uint { EXTRA = unchecked((uint)2UL) } }");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "Residual.enums.cs"),
                "namespace Test { public enum ERROR_GROUP : uint { EXTRA = 2 } }");
            var exception = Assert.Throws<Xunit.Sdk.EmptyException>(() => Emit(fixture, "x64"));
            Assert.Contains("CS0101", exception.Message);
        }

        [Fact]
        public void LogicalGroupUnionPreservesExistingResidualEnumUsesWithoutALegacyDefinition()
        {
            using var first = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FIRST 1U
_Win32_Enum_(ERROR_GROUP, unsigned, FIRST);
struct LEGACY_RECORD { unsigned status; };
unsigned Legacy(unsigned error);
_Win32_AssociatedEnum_(ERROR_GROUP) unsigned Migrated();
");
            using var extra = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define EXTRA 4U
_Win32_Enum_(ERROR_GROUP, unsigned, EXTRA);
void Extra(_Win32_AssociatedEnum_(ERROR_GROUP) unsigned error);
");
            Assert.True(first.Run() == 0, first.Diagnostics);
            Assert.True(extra.Run() == 0, extra.Diagnostics);
            string directory = Path.GetDirectoryName(first.Output);
            File.Copy(extra.Output, Path.Combine(directory, "Extra.cs"));
            File.Copy(Path.ChangeExtension(extra.Output, ".header-types.cs"), Path.Combine(directory, "Extra.header-types.cs"));
            string residual = Path.Combine(first.DirectoryPath, "residual-uses.json");
            File.WriteAllText(residual, @"
{ ""items"": [{
    ""addUsesTo"": ""ERROR_GROUP"",
    ""uses"": [
        { ""method"": ""Legacy"", ""parameter"": ""return"" },
        { ""method"": ""Legacy"", ""parameter"": ""error"" },
        { ""struct"": ""LEGACY_RECORD"", ""field"": ""status"" }
    ]
}] }");
            var remaps = new Dictionary<string, string>();
            MetadataUtils.ConstantsScraper.ScrapeConstants(new[] { residual }, "Test", first.DirectoryPath, "",
                new HashSet<string>(), new Dictionary<string, string>(), new Dictionary<string, string>(), remaps,
                new Dictionary<string, string>(), new Dictionary<string, string>());
            Assert.Equal(3, remaps.Count);
            foreach (string use in new[] { "Legacy::return", "Legacy::error", "LEGACY_RECORD::status" })
                Assert.Equal("ERROR_GROUP", remaps[use]);
            foreach (string source in Directory.GetFiles(first.DirectoryPath, "*.enums.cs"))
                Assert.Empty(CSharpSyntaxTree.ParseText(File.ReadAllText(source)).GetRoot()
                    .DescendantNodes().OfType<EnumDeclarationSyntax>());
            using var image = Emit(first.DirectoryPath, "x64", memberRemaps: remaps);
            var reader = image.Reader;
            Assert.Equal("Test", reader.GetString(FindType(reader, "ERROR_GROUP").Namespace));
            Assert.Equal(new[] { "value__", "FIRST", "EXTRA" }, FindType(reader, "ERROR_GROUP").GetFields()
                .Select(handle => reader.GetString(reader.GetFieldDefinition(handle).Name)));
            var legacy = FindMethod(reader, "Apis", "Legacy").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("ERROR_GROUP", legacy.ReturnType);
            Assert.Equal(new[] { "ERROR_GROUP" }, legacy.ParameterTypes);
            Assert.Equal("ERROR_GROUP", FindType(reader, "LEGACY_RECORD").GetFields()
                .Select(reader.GetFieldDefinition).Single().DecodeSignature(new SignatureNames(), null));
            var migrated = FindMethod(reader, "Apis", "Migrated");
            Assert.Equal("UInt32", migrated.DecodeSignature(new SignatureNames(), null).ReturnType);
            AssertStringAttribute(reader, migrated.GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 0).GetCustomAttributes(), "AssociatedEnumAttribute", "ERROR_GROUP");
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void LogicalGroupUnionPreservesPrimitiveAliasesFromConstantsScraper(
            string architecture, string target, bool includeGroupImport)
        {
            using var first = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#define SUCCESS 0L
#define NOT_SUPPORTED 50UL
#define LOCAL_ZERO_1 SUCCESS
#define LOCAL_ZERO_2 SUCCESS
#define LOCAL_ZERO_3 SUCCESS
#define LOCAL_ALIAS_1 NOT_SUPPORTED
#define LOCAL_ALIAS_2 NOT_SUPPORTED
#define LOCAL_ALIAS_3 NOT_SUPPORTED
_Win32_Enum_(ERROR_GROUP, unsigned, SUCCESS, NOT_SUPPORTED);
");
            using var extra = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#define EXTRA 100U
_Win32_Enum_(ERROR_GROUP, unsigned, EXTRA);
");
            Assert.True(first.Run() == 0, first.Diagnostics);
            Assert.True(extra.Run() == 0, extra.Diagnostics);
            File.Copy(Path.ChangeExtension(extra.Output, ".header-types.cs"),
                Path.Combine(Path.GetDirectoryName(first.Output), "Extra.header-types.cs"));
            string networkHeader = Path.Combine(first.DirectoryPath, "network.h");
            string printingHeader = Path.Combine(first.DirectoryPath, "printing.h");
            File.WriteAllText(networkHeader, "#define NETWORK_SUCCESS SUCCESS\n#define NETWORK_NO_ERROR SUCCESS\n" +
                string.Join("\n", Enumerable.Range(1, 40).Select(index => $"#define NETWORK_ALIAS_{index} NOT_SUPPORTED")));
            File.WriteAllText(printingHeader, "#define PRINTING_ALIAS NOT_SUPPORTED\n");
            MetadataUtils.ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", first.DirectoryPath,
                includeGroupImport ? "using static Test.ERROR_GROUP;\n" : "", new HashSet<string>(), new Dictionary<string, string>
                {
                    [first.Header] = "Test",
                    [networkHeader] = "Network",
                    [printingHeader] = "Printing",
                }, new Dictionary<string, string>(), new Dictionary<string, string>(),
                new Dictionary<string, string>(), new Dictionary<string, string>());
            Assert.Contains("public const int NETWORK_SUCCESS = SUCCESS;",
                File.ReadAllText(Path.Combine(first.DirectoryPath, "Network.constants.cs")));
            Assert.Contains("public const uint PRINTING_ALIAS = NOT_SUPPORTED;",
                File.ReadAllText(Path.Combine(first.DirectoryPath, "Printing.constants.cs")));
            var originals = Directory.GetFiles(first.DirectoryPath, "*.cs", SearchOption.AllDirectories)
                .ToDictionary(path => path, File.ReadAllBytes);
            using var image = Emit(first, architecture);
            foreach (var original in originals)
                Assert.Equal(original.Value, File.ReadAllBytes(original.Key));
            var reader = image.Reader;
            Assert.Equal(new[] { "value__", "SUCCESS", "NOT_SUPPORTED", "EXTRA" },
                FindType(reader, "ERROR_GROUP").GetFields().Select(handle =>
                    reader.GetString(reader.GetFieldDefinition(handle).Name)));
            var aliases = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "Apis" &&
                    reader.GetString(type.Namespace) is "Test" or "Network" or "Printing")
                .SelectMany(type => type.GetFields()).Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal(49, aliases.Length);
            foreach (var alias in aliases)
            {
                var constant = reader.GetConstant(alias.GetDefaultValue());
                var blob = reader.GetBlobReader(constant.Value);
                string name = reader.GetString(alias.Name);
                if (name is "NETWORK_SUCCESS" or "NETWORK_NO_ERROR" || name.StartsWith("LOCAL_ZERO_", StringComparison.Ordinal))
                {
                    Assert.Equal("Int32", alias.DecodeSignature(new SignatureNames(), null));
                    Assert.Equal(ConstantTypeCode.Int32, constant.TypeCode);
                    Assert.Equal(0, blob.ReadInt32());
                }
                else
                {
                    Assert.Equal("UInt32", alias.DecodeSignature(new SignatureNames(), null));
                    Assert.Equal(ConstantTypeCode.UInt32, constant.TypeCode);
                    Assert.Equal(50U, blob.ReadUInt32());
                }
                Assert.True(alias.Attributes.HasFlag(FieldAttributes.Literal));
            }
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void LogicalGroupsDoNotImplicitlyConvertOrdinaryNativeEnumConstants(bool unqualified)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
enum class NATIVE_GROUP : unsigned { FIRST = 2 };
#define FIRST 1U
_Win32_Enum_(ERROR_GROUP, unsigned, FIRST);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "NativeAlias.constants.cs"),
                (unqualified ? "using static Test.NATIVE_GROUP;\n" : "") +
                "namespace Test { public static partial class Apis { public const uint NativeAlias = " +
                (unqualified ? "FIRST" : "NATIVE_GROUP.FIRST") + "; } }");
            var exception = Assert.Throws<Xunit.Sdk.EmptyException>(() => Emit(fixture, "x64"));
            Assert.Contains("CS0266", exception.Message);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void LogicalGroupScalarAliasesPreserveIntegralStorageAndExpressions(
            string architecture, string target, bool includeGroupImport)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#define ONE 1ULL
#define BYTE_MAX 255ULL
#define SHORT_MAX 32767ULL
#define USHORT_MAX 65535ULL
#define INT_MAX 2147483647ULL
#define UINT_MAX 4294967295ULL
#define LONG_MAX 9223372036854775807ULL
#define ULONG_MAX 18446744073709551615ULL
#define NEGATIVE -1LL
_Win32_Enum_(WIDE_GROUP, unsigned long long, ONE, BYTE_MAX, SHORT_MAX, USHORT_MAX, INT_MAX, UINT_MAX, LONG_MAX, ULONG_MAX);
_Win32_Enum_(SIGNED_GROUP, long long, NEGATIVE);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string aliasesSource = @"
using Scalar = System.UInt32;
using static Test.WIDE_GROUP;
namespace Consumers {
public static partial class Apis {
    public const sbyte SmallSigned = global::Test.WIDE_GROUP.ONE + 126;
    public const byte SmallUnsigned = (BYTE_MAX);
    public const short Short = SHORT_MAX;
    public const ushort UShort = USHORT_MAX;
    public const char Character = USHORT_MAX;
    public const int Int = INT_MAX;
    public const Scalar UInt = UINT_MAX;
    public const long Long = LONG_MAX;
    public const ulong ULong = ULONG_MAX;
    public const int Negative = Test.SIGNED_GROUP.NEGATIVE;
    public const uint AlreadyCast = (uint)global::Test.WIDE_GROUP.UINT_MAX;
    public const uint AliasChain = UInt;
}}
";
            if (!includeGroupImport)
                aliasesSource = aliasesSource.Replace("using static Test.WIDE_GROUP;", "", StringComparison.Ordinal);
            string aliasesPath = Path.Combine(fixture.DirectoryPath, "Aliases.manual.cs");
            File.WriteAllText(aliasesPath, aliasesSource);
            byte[] originalAliases = File.ReadAllBytes(aliasesPath);
            using var image = Emit(fixture, architecture);
            Assert.Equal(originalAliases, File.ReadAllBytes(aliasesPath));
            var reader = image.Reader;
            var expected = new Dictionary<string, (ConstantTypeCode Code, string Signature, object Value)>
            {
                ["SmallSigned"] = (ConstantTypeCode.SByte, "SByte", sbyte.MaxValue),
                ["SmallUnsigned"] = (ConstantTypeCode.Byte, "Byte", byte.MaxValue),
                ["Short"] = (ConstantTypeCode.Int16, "Int16", short.MaxValue),
                ["UShort"] = (ConstantTypeCode.UInt16, "UInt16", ushort.MaxValue),
                ["Character"] = (ConstantTypeCode.Char, "Char", char.MaxValue),
                ["Int"] = (ConstantTypeCode.Int32, "Int32", int.MaxValue),
                ["UInt"] = (ConstantTypeCode.UInt32, "UInt32", uint.MaxValue),
                ["Long"] = (ConstantTypeCode.Int64, "Int64", long.MaxValue),
                ["ULong"] = (ConstantTypeCode.UInt64, "UInt64", ulong.MaxValue),
                ["Negative"] = (ConstantTypeCode.Int32, "Int32", -1),
                ["AlreadyCast"] = (ConstantTypeCode.UInt32, "UInt32", uint.MaxValue),
                ["AliasChain"] = (ConstantTypeCode.UInt32, "UInt32", uint.MaxValue),
            };
            var aliases = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Namespace) == "Consumers")
                .SelectMany(type => type.GetFields()).Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal(expected.Count, aliases.Length);
            foreach (var alias in aliases)
            {
                var actual = expected[reader.GetString(alias.Name)];
                var constant = reader.GetConstant(alias.GetDefaultValue());
                Assert.Equal(actual.Signature, alias.DecodeSignature(new SignatureNames(), null));
                Assert.Equal(actual.Code, constant.TypeCode);
                Assert.Equal(actual.Value, reader.GetBlobReader(constant.Value).ReadConstant(constant.TypeCode));
            }
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("byte", "ERROR_GROUP.TOO_LARGE", "CS0221")]
        [InlineData("bool", "ERROR_GROUP.FIRST", "CS0029")]
        [InlineData("OTHER_GROUP", "ERROR_GROUP.FIRST", "CS0266")]
        [InlineData("uint", "ERROR_GROUP.UNDECLARED", "CS0117")]
        [InlineData("byte", "TOO_LARGE", "CS0221")]
        [InlineData("byte", "(TOO_LARGE)", "CS0221")]
        [InlineData("uint", "UNDECLARED", "CS0103")]
        [InlineData("uint", "FIRST", "CS0103")]
        [InlineData("uint", "Other", "CS0103")]
        [InlineData("bool", "TOO_LARGE", "CS0103")]
        [InlineData("OTHER_GROUP", "TOO_LARGE", "CS0103")]
        public void LogicalGroupScalarAliasConversionPreservesErrors(string type, string value, string diagnostic)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FIRST 1U
#define TOO_LARGE 256U
_Win32_Enum_(ERROR_GROUP, unsigned, FIRST, TOO_LARGE);
_Win32_Enum_(SECOND_GROUP, unsigned, FIRST);
enum class OTHER_GROUP : unsigned { Other = 2 };
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "Rejected.constants.cs"),
                $"namespace Test {{ public static partial class Apis {{ public const {type} Rejected = {value}; }} }}");
            var exception = Assert.Throws<Xunit.Sdk.EmptyException>(() => Emit(fixture, "x64"));
            Assert.Contains(diagnostic, exception.Message);
        }

        [Fact]
        public void LogicalGroupContributionsAreUnionedAfterNamespaceAssignment()
        {
            using var first = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FIRST 1U
_Win32_Enum_(ERROR_GROUP, unsigned, FIRST);
void First(_Win32_AssociatedEnum_(ERROR_GROUP) unsigned error);
");
            using var extra = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define EXTRA 4U
_Win32_Enum_(ERROR_GROUP, unsigned, EXTRA);
");
            Assert.True(first.Run() == 0, first.Diagnostics);
            Assert.True(extra.Run() == 0, extra.Diagnostics);
            File.WriteAllText(Path.Combine(Path.GetDirectoryName(first.Output), "Extra.header-types.cs"),
                File.ReadAllText(Path.ChangeExtension(extra.Output, ".header-types.cs"))
                    .Replace("namespace Test", "namespace AnotherPartition", StringComparison.Ordinal));
            using var image = Emit(first.DirectoryPath, "x64", requiredNamespaces: new Dictionary<string, string>
            {
                ["ERROR_GROUP"] = "Windows.Win32.Foundation",
            });
            var reader = image.Reader;
            var group = FindType(reader, "ERROR_GROUP");
            Assert.Equal("Windows.Win32.Foundation", reader.GetString(group.Namespace));
            Assert.Equal(new[] { "value__", "FIRST", "EXTRA" }, group.GetFields()
                .Select(handle => reader.GetString(reader.GetFieldDefinition(handle).Name)));
            AssertMetadataClosure(reader);
        }

        [Fact]
        public void LogicalGroupUnionRejectsConflictingTypeAnnotations()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FIRST 1U
_Win32_SupportedOS_Windows7_ _Win32_Enum_(ERROR_GROUP, unsigned, FIRST);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            File.WriteAllText(Path.Combine(Path.GetDirectoryName(fixture.Output), "Extra.header-types.cs"), @"
namespace Test {
    [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(""windows6.2"")]
    public enum ERROR_GROUP : uint { FIRST = unchecked((uint)1UL) }
}");
            var exception = Assert.Throws<InvalidOperationException>(() => Emit(fixture, "x64"));
            Assert.Contains("WMA003", exception.Message);
            Assert.Contains("Conflicting", exception.Message);
            Assert.Contains("SupportedOSPlatform", exception.Message);
        }

        [Fact]
        public void DistinctNativeLogicalGroupsInOneTranslationUnitCannotBeUnioned()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FIRST 1U
#define SECOND 2U
namespace First { _Win32_Enum_(ERROR_GROUP, unsigned, FIRST); }
namespace Second { _Win32_Enum_(ERROR_GROUP, unsigned, SECOND); }
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var exception = Assert.Throws<InvalidOperationException>(() => Emit(fixture, "x64"));
            Assert.Contains("WMA003", exception.Message);
            Assert.Contains("Distinct native declarations", exception.Message);
        }

        [Fact]
        public void HeaderImportRescuesUnmappedMethod()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "_Win32_ImportLibrary_(\"header.dll\") _Win32_SetLastError_ int Imported();", libraryPath: "");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "x64");
            var import = FindMethod(image.Reader, "Apis", "Imported").GetImport();
            Assert.Equal("header.dll", image.Reader.GetString(image.Reader.GetModuleReference(import.Module).Name));
            Assert.True(import.Attributes.HasFlag(MethodImportAttributes.SetLastError));
        }

        [Fact]
        public void RedeclaredFactsReachFinalWinmd()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
int Imported();
_Win32_SetLastError_ int Imported();
int Retain(_Win32_Retained_ void* context);
int Retain(void* context);
enum _Win32_SupportedOS_10240_ E : unsigned;
enum E : unsigned { A = 1 };
struct _Win32_SupportedOS_Windows7_ RECORD;
struct RECORD { unsigned value; };
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            Assert.True(FindMethod(reader, "Apis", "Imported").GetImport().Attributes.HasFlag(MethodImportAttributes.SetLastError));
            AssertHasAttribute(reader, FindMethod(reader, "Apis", "Retain").GetParameters().Select(reader.GetParameter).Single()
                .GetCustomAttributes(), "RetainedAttribute");
            AssertStringAttribute(reader, FindType(reader, "E").GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows10.0.10240");
            AssertStringAttribute(reader, FindType(reader, "RECORD").GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows6.1");
            AssertMetadataClosure(reader);
        }

        [Fact]
        public void CallbackAliasAcrossGeneratedFilesKeepsCanonicalSignature()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
_Win32_SupportedOS_10240_ typedef unsigned long TOKEN;
typedef TOKEN (__stdcall* PFN_BASE)(_Win32_Retained_ void* context, unsigned count);
_Win32_SupportedOS_Windows7_ typedef PFN_BASE PFN_ALIAS;
int UseCallback(PFN_ALIAS callback);
", multipleFiles: true);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            var invoke = FindMethod(reader, "PFN_ALIAS", "Invoke");
            Assert.Equal("TOKEN", invoke.DecodeSignature(new SignatureNames(), null).ReturnType);
            Assert.Equal(new[] { "Void*", "UInt32" }, invoke.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.Equal(new[] { "context", "count" }, invoke.GetParameters().Select(reader.GetParameter)
                .Where(parameter => parameter.SequenceNumber != 0).Select(parameter => reader.GetString(parameter.Name)));
            AssertHasAttribute(reader, invoke.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 1)
                .GetCustomAttributes(), "RetainedAttribute");
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void InvalidValuesAreEvaluatedInTheirNativeScope(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef void* HANDLE;
__declspec(dllimport) int __stdcall ImportedCleanup(void*);
_Win32_RAIIFree_Handle_(ImportedCleanup) HANDLE ImportedProducer();
namespace N {
enum Value { Invalid = 7 };
_Win32_RAIIFree_(CloseThing, Invalid, (1 ^ 2), ~0ULL, -1) HANDLE Produce();
}
struct __declspec(uuid(""1d04d0ec-13d6-4fa8-9b02-9a4cc7b8bb7f"")) Producer {
    static const int Invalid = 19;
    _Win32_RAIIFree_(CloseThing, Invalid) virtual HANDLE __stdcall ProduceMember() = 0;
};
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var result = FindMethod(reader, "Apis", "Produce").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 0);
            Assert.Equal(new long[] { 7, 3, -1, -1 }, ReadInvalidValues(reader, result.GetCustomAttributes()));
            var memberResult = FindMethod(reader, "Producer", "ProduceMember").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 0);
            Assert.Equal(new long[] { 19 }, ReadInvalidValues(reader, memberResult.GetCustomAttributes()));
            var importedResult = FindMethod(reader, "Apis", "ImportedProducer").GetParameters().Select(reader.GetParameter)
                .Single(parameter => parameter.SequenceNumber == 0);
            AssertStringAttribute(reader, importedResult.GetCustomAttributes(), "RAIIFreeAttribute", "ImportedCleanup");
            Assert.Equal(new long[] { -1, 0 }, ReadInvalidValues(reader, importedResult.GetCustomAttributes()));
            AssertMetadataClosure(reader);
        }

        private static string[] NativeSurface(HeaderAnnotationTests.NativeFixture fixture, string target, bool metadataEnabled, string language = "c++")
        {
            string source = Path.Combine(fixture.DirectoryPath, "test.cpp");
            var arguments = new List<string>
            {
                "--language=" + language, "--std=" + (language == "c" ? "c11" : "c++17"), "--target=" + target,
                "--include-directory=" + Path.Combine(AppContext.BaseDirectory, "assets"),
                "-D_USE_DECLSPECS_FOR_SAL=1", "-D_PREFAST_=1", "-Wno-ignored-attributes",
            };
            if (metadataEnabled)
                arguments.Add("-DWIN32METADATA");
            using var index = CXIndex.Create(false, false);
            Assert.Equal(CXErrorCode.CXError_Success, CXTranslationUnit.TryParse(index, source, arguments.ToArray(),
                ReadOnlySpan<CXUnsavedFile>.Empty, CXTranslationUnit_Flags.CXTranslationUnit_IncludeAttributedTypes, out var handle));
            using var unit = TranslationUnit.GetOrCreate(handle);
            for (uint i = 0; i < handle.NumDiagnostics; i++)
            {
                using var diagnostic = handle.GetDiagnostic(i);
                Assert.True(diagnostic.Severity < CXDiagnosticSeverity.CXDiagnostic_Error, diagnostic.Format(CXDiagnostic.DefaultDisplayOptions).ToString());
            }
            var surface = new List<string>();
            Walk(unit.TranslationUnitDecl);
            return surface.ToArray();

            void Walk(Cursor cursor)
            {
                cursor.Location.GetExpansionLocation(out var file, out _, out _, out _);
                if (Path.GetFileName(file.ToString()) == "test.h")
                {
                    if (cursor is FunctionDecl function)
                        surface.Add("function " + function.Name + " " + function.Type.CanonicalType.AsString);
                    else if (cursor is FieldDecl field)
                        surface.Add("field " + field.Name + " " + field.Type.CanonicalType.AsString + " " + field.Handle.OffsetOfField);
                    else if (cursor is RecordDecl record && record.IsCompleteDefinition)
                        surface.Add("record " + record.Name + " " + record.Handle.Type.SizeOf + " " + record.Handle.Type.AlignOf);
                    else if (cursor is EnumDecl enumeration)
                        surface.Add("enum " + enumeration.Name + " " + enumeration.IntegerType.AsString);
                }
                foreach (var child in cursor.CursorChildren)
                    if (child.Handle.IsDeclaration || child.Handle.IsTranslationUnit)
                        Walk(child);
            }
        }

        private static MetadataImage Emit(HeaderAnnotationTests.NativeFixture fixture, string architecture)
            => Emit(fixture.DirectoryPath, architecture);

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void NativeEnumsRetainPhysicalFactsWithoutImplicitScalarAliasLowering(string architecture, string target, bool common)
        {
            string[] names =
            {
                "WER_SUBMIT_ADD_REGISTERED_DATA", "WER_SUBMIT_HONOR_RECOVERY", "WER_SUBMIT_HONOR_RESTART",
                "WER_SUBMIT_NO_ARCHIVE", "WER_SUBMIT_NO_CLOSE_UI", "WER_SUBMIT_NO_QUEUE",
                "WER_SUBMIT_OUTOFPROCESS", "WER_SUBMIT_OUTOFPROCESS_ASYNC", "WER_SUBMIT_QUEUE",
                "WER_SUBMIT_SHOW_DEBUG", "WER_SUBMIT_START_MINIMIZED", "WER_SUBMIT_BYPASS_DATA_THROTTLING",
                "WER_SUBMIT_ARCHIVE_PARAMETERS_ONLY", "WER_SUBMIT_REPORT_MACHINE_ID",
            };
            uint[] values = { 16, 1, 2, 256, 64, 128, 32, 1024, 4, 8, 512, 2048, 4096, 8192 };
            string declarations = "enum [[clang::flag_enum]] WER_SUBMIT_FLAGS : unsigned { "
                + string.Join(", ", names.Zip(values, (name, value) => $"{name} = {value}")) + " };"
                + " enum SIGNED_FLAGS : int { SIGNED_ALL = -1 };";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            if (common)
            {
                string commonDirectory = Path.Combine(fixture.DirectoryPath, "common");
                Directory.CreateDirectory(commonDirectory);
                File.Move(fixture.Output, Path.Combine(commonDirectory, "Bindings.cs"));
            }
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "Aliases.constants.cs"), @"
namespace Other { public enum OtherFlags : uint { WER_SUBMIT_NO_QUEUE = 7 } }
namespace Test { public static class Apis {
    public const uint UNRELATED = 9;
    public const uint UNRELATED_ALIAS = UNRELATED;
}}");
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var flags = FindType(reader, "WER_SUBMIT_FLAGS");
            AssertHasAttribute(reader, flags.GetCustomAttributes(), "FlagsAttribute");
            AssertDoesNotHaveAttribute(reader, flags.GetCustomAttributes(), "ScopedEnumAttribute");
            var fields = flags.GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal("UInt32", fields[0].DecodeSignature(new SignatureNames(), null));
            Assert.Equal(names, fields.Skip(1).Select(field => reader.GetString(field.Name)));
            Assert.Equal(values, fields.Skip(1).Select(ReadUInt32));
            var constants = FindType(reader, "Apis").GetFields().Select(reader.GetFieldDefinition)
                .ToDictionary(field => reader.GetString(field.Name));
            Assert.All(constants.Values, field =>
                Assert.Equal("UInt32", field.DecodeSignature(new SignatureNames(), null)));
            Assert.DoesNotContain("WER_SUBMIT_NO_QUEUE", constants.Keys);
            Assert.DoesNotContain("SIGNED_ALL", constants.Keys);
            Assert.Equal(9u, ReadUInt32(constants["UNRELATED_ALIAS"]));
            Assert.Equal(7u, ReadUInt32(FindType(reader, "OtherFlags").GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == "WER_SUBMIT_NO_QUEUE")));
            var signed = FindType(reader, "SIGNED_FLAGS").GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal("Int32", signed[0].DecodeSignature(new SignatureNames(), null));
            var signedValue = reader.GetConstant(signed.Single(field => reader.GetString(field.Name) == "SIGNED_ALL").GetDefaultValue());
            Assert.Equal(ConstantTypeCode.Int32, signedValue.TypeCode);
            Assert.Equal(-1, reader.GetBlobReader(signedValue.Value).ReadInt32());
            AssertMetadataClosure(reader);

            using var aliases = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations);
            Assert.True(aliases.Run() == 0, aliases.Diagnostics);
            if (common)
            {
                string commonDirectory = Path.Combine(aliases.DirectoryPath, "common");
                Directory.CreateDirectory(commonDirectory);
                File.Move(aliases.Output, Path.Combine(commonDirectory, "Bindings.cs"));
            }
            File.WriteAllText(Path.Combine(aliases.DirectoryPath, "Aliases.constants.cs"), @"
namespace Other { public enum OtherFlags : uint { WER_SUBMIT_NO_QUEUE = 7 } }
namespace Test { public static class Apis {
    public const uint WER_SUBMIT_NO_QUEUE = 128;
    public const uint WER_SUBMIT_DISCARD_IF_QUEUED = WER_SUBMIT_NO_QUEUE;
    public const uint ALIAS_CHAIN = WER_SUBMIT_DISCARD_IF_QUEUED;
    public const uint SIGNED_ALL = 0xffffffff;
    public const uint UNSIGNED_ALIAS = SIGNED_ALL;
    public const uint UNRELATED = 9;
    public const uint UNRELATED_ALIAS = UNRELATED;
}}");
            File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"),
                Path.Combine(aliases.DirectoryPath, "Metadata.manual.cs"));
            var compilation = ClangSharpSourceCompilation.Create(aliases.DirectoryPath, architecture,
                new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(), Array.Empty<string>(),
                new Dictionary<string, string>(), new Dictionary<string, string>(), new HashSet<string>(),
                Array.Empty<string>(), new Dictionary<string, string>(), new Dictionary<string, string>());
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.Equal(2, errors.Length);
            Assert.All(errors, diagnostic => Assert.Equal("CS0103", diagnostic.Id));
            Assert.Contains(errors, diagnostic => diagnostic.GetMessage().Contains("'WER_SUBMIT_NO_QUEUE'", StringComparison.Ordinal));
            Assert.Contains(errors, diagnostic => diagnostic.GetMessage().Contains("'SIGNED_ALL'", StringComparison.Ordinal));

            uint ReadUInt32(FieldDefinition field)
            {
                var value = reader.GetConstant(field.GetDefaultValue());
                Assert.Equal(ConstantTypeCode.UInt32, value.TypeCode);
                return reader.GetBlobReader(value.Value).ReadUInt32();
            }
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void EnumConstantAliasesDoNotGuessAnotherNamespaceOrAmbiguousEnum(bool ambiguous)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", "");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "Bindings.cs"), ambiguous ? @"
namespace Test {
public enum First { SHARED = 1 }
public enum Second { SHARED = 2 }
public static class Apis { public const int ALIAS = SHARED; }
}" : @"
namespace Other { public enum First { SHARED = 1 } }
namespace Test { public static class Apis { public const int ALIAS = SHARED; } }");
            Assert.Contains(Create().GetDiagnostics(), diagnostic => diagnostic.Id == "CS0103");

            ClangSharpSourceCompilation Create() => ClangSharpSourceCompilation.Create(fixture.DirectoryPath, "x64",
                new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(), Array.Empty<string>(),
                new Dictionary<string, string>(), new Dictionary<string, string>(), new HashSet<string>(),
                Array.Empty<string>(), new Dictionary<string, string>(), new Dictionary<string, string>());
        }

        [ServiceApiMigrationTheory]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void ServiceApiHeaderMigrationMatchesBoundedComponent(string architecture)
        {
            string artifacts = Environment.GetEnvironmentVariable("SERVICE_API_MIGRATION_ARTIFACTS");
            string[] owners = { "Tbs", "FileHistory", "Antimalware", "WebSock" };
            foreach (string owner in owners)
                Assert.Contains("parse-win32-annotations", File.ReadAllText(Path.Combine(
                    WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "Partitions", owner, "settings.rsp")));
            string constants = Path.Combine(artifacts, "constants");
            var remaps = File.ReadLines(Path.Combine(constants, "enumsRemap.rsp"))
                .Where(line => line.Contains('=')).Select(line => line.Split('=', 2))
                .ToDictionary(pair => pair[0], pair => pair[1]);
            var namespaces = new HashSet<string>(new[]
            {
                "Windows.Win32.Foundation", "Windows.Win32.Foundation.Metadata",
                "Windows.Win32.System.Com",
                "Windows.Win32.System.TpmBaseServices", "Windows.Win32.Storage.FileHistory",
                "Windows.Win32.System.Antimalware", "Windows.Win32.Networking.WebSocket",
            });
            var dependencies = new Dictionary<string, CompilationUnitSyntax>();
            foreach (var item in new[] { (File: "Foundation", Type: "FILETIME"), (File: "Com", Type: "IUnknown") })
            {
                var dependency = CSharpSyntaxTree.ParseText(File.ReadAllText(
                    Path.Combine(artifacts, "dependencies", item.File + ".cs"))).GetCompilationUnitRoot();
                var type = dependency.DescendantNodes().OfType<StructDeclarationSyntax>()
                    .Single(value => value.Identifier.ValueText == item.Type);
                var ns = type.Ancestors().OfType<NamespaceDeclarationSyntax>().Single()
                    .WithMembers(SyntaxFactory.SingletonList<MemberDeclarationSyntax>(type));
                dependencies.Add(item.File, dependency.WithMembers(SyntaxFactory.SingletonList<MemberDeclarationSyntax>(ns)));
            }
            var movements = new[]
            {
                (Type: "FH_SERVICE_PIPE_HANDLE", Owner: "FileHistory", Method: "FhServiceOpenPipe", Parameter: "Pipe"),
                (Type: "WEB_SOCKET_HANDLE", Owner: "WebSock", Method: "WebSocketCreateClientHandle", Parameter: "phWebSocket"),
                (Type: "WEB_SOCKET_HANDLE", Owner: "WebSock", Method: "WebSocketCreateServerHandle", Parameter: "phWebSocket"),
            };
            string directory = Path.Combine(artifacts, "components", architecture);
            foreach (string state in new[] { "original", "parser-control", "migrated", "expected" })
            {
                string output = Path.Combine(directory, state);
                string sources = Path.Combine(output, architecture);
                Directory.CreateDirectory(sources);
                File.Delete(Path.Combine(output, "Metadata.manual.cs"));
                string aliases = Path.Combine(sources, "autotypes.cs");
                File.Delete(aliases);
                foreach (string owner in owners)
                {
                    var source = CSharpSyntaxTree.ParseText(File.ReadAllText(Path.Combine(artifacts,
                        state == "expected" ? "parser-control" : state, architecture, owner + ".cs"))).GetCompilationUnitRoot();
                    source = source.WithUsings(SyntaxFactory.List(source.Usings.Where(value =>
                        !value.Name.ToString().StartsWith("Windows.Win32.", StringComparison.Ordinal)
                        || namespaces.Contains(value.Name.ToString()))));
                    File.WriteAllText(Path.Combine(sources, owner + ".cs"), source.ToFullString());
                }
                foreach (var dependency in dependencies)
                    File.WriteAllText(Path.Combine(output, dependency.Key + ".dependency.cs"), dependency.Value.ToFullString());
                foreach (string path in Directory.GetFiles(constants, "*.cs"))
                    File.Copy(path, Path.Combine(output, Path.GetFileName(path)), overwrite: true);
                var autoTypes = AutoTypeHelpers.GetAutoTypesFromFiles(new[]
                {
                    Path.Combine(artifacts, state == "migrated" ? "current-owned-autoTypes.json" : "original-owned-autoTypes.json"),
                }).ToArray();
                var names = MetadataUtils.ScraperUtils.GetNameToNamespaceMap(output,
                    MetadataUtils.ScraperUtils.NameOptions.Methods | MetadataUtils.ScraperUtils.NameOptions.Structs);
                using (var stream = File.Create(aliases))
                    NativeTypedefStructsCreator.WriteToStream(names, autoTypes, stream);
                if (state != "expected")
                    continue;

                var aliasesSource = CSharpSyntaxTree.ParseText(File.ReadAllText(aliases)).GetCompilationUnitRoot();
                var lifecycle = new Dictionary<string, SyntaxList<AttributeListSyntax>>();
                var types = aliasesSource.DescendantNodes().OfType<StructDeclarationSyntax>()
                    .Where(type => movements.Any(value => value.Type == type.Identifier.ValueText)).ToArray();
                aliasesSource = aliasesSource.ReplaceNodes(types, (original, rewritten) =>
                {
                    bool IsLifecycle(AttributeListSyntax list) => list.Attributes.All(attribute =>
                        attribute.Name.ToString() is "RAIIFree" or "InvalidHandleValue");
                    lifecycle.Add(original.Identifier.ValueText,
                        SyntaxFactory.List(original.AttributeLists.Where(IsLifecycle)));
                    return rewritten.WithAttributeLists(
                        SyntaxFactory.List(rewritten.AttributeLists.Where(list => !IsLifecycle(list))));
                });
                File.WriteAllText(aliases, aliasesSource.ToFullString());
                foreach (var movement in movements)
                {
                    string path = Path.Combine(sources, movement.Owner + ".cs");
                    var source = CSharpSyntaxTree.ParseText(File.ReadAllText(path)).GetCompilationUnitRoot();
                    var method = source.DescendantNodes().OfType<MethodDeclarationSyntax>()
                        .Single(value => value.Identifier.ValueText == movement.Method);
                    var parameter = method.ParameterList.Parameters.Single(value => value.Identifier.ValueText == movement.Parameter);
                    Assert.DoesNotContain(parameter.AttributeLists.SelectMany(list => list.Attributes),
                        attribute => attribute.Name.ToString() is "RAIIFree" or "InvalidHandleValue");
                    source = source.ReplaceNode(parameter, parameter.AddAttributeLists(lifecycle[movement.Type].ToArray()));
                    File.WriteAllText(path, source.ToFullString());
                }
            }

            using var original = Emit(Path.Combine(directory, "original"), architecture, memberRemaps: remaps);
            using var control = Emit(Path.Combine(directory, "parser-control"), architecture, memberRemaps: remaps);
            using var current = Emit(Path.Combine(directory, "migrated"), architecture, memberRemaps: remaps);
            using var expected = Emit(Path.Combine(directory, "expected"), architecture, memberRemaps: remaps);
            foreach (var image in new[] { original, control, current, expected })
                AssertMetadataClosure(image.Reader);
            Assert.Equal(Snapshot(original.Reader), Snapshot(control.Reader));
            Assert.Equal(Snapshot(expected.Reader), Snapshot(current.Reader));
            foreach (var movement in movements)
            {
                var oldType = FindType(control.Reader, movement.Type);
                Assert.Equal(new long[] { -1, 0 }, ReadInvalidValues(control.Reader, oldType.GetCustomAttributes()).OrderBy(value => value));
                string cleanup = ReadStringAttribute(control.Reader, oldType.GetCustomAttributes(), "RAIIFreeAttribute");
                var newType = FindType(current.Reader, movement.Type);
                AssertDoesNotHaveAttribute(current.Reader, newType.GetCustomAttributes(), "RAIIFreeAttribute");
                AssertDoesNotHaveAttribute(current.Reader, newType.GetCustomAttributes(), "InvalidHandleValueAttribute");
                var method = current.Reader.MethodDefinitions.Select(current.Reader.GetMethodDefinition)
                    .Single(value => current.Reader.GetString(value.Name) == movement.Method);
                var parameter = method.GetParameters().Select(current.Reader.GetParameter)
                    .Single(value => current.Reader.GetString(value.Name) == movement.Parameter);
                Assert.True(parameter.Attributes.HasFlag(ParameterAttributes.Out));
                AssertStringAttribute(current.Reader, parameter.GetCustomAttributes(), "RAIIFreeAttribute", cleanup);
                Assert.Equal(new long[] { -1, 0 }, ReadInvalidValues(current.Reader, parameter.GetCustomAttributes()).OrderBy(value => value));
            }
            foreach (string name in new[] { "HAMSICONTEXT", "HAMSISESSION" })
                Assert.Equal(new long[] { -1, 0 }, ReadInvalidValues(current.Reader, FindType(current.Reader, name).GetCustomAttributes()).OrderBy(value => value));
            var getDeviceId = current.Reader.MethodDefinitions.Select(current.Reader.GetMethodDefinition)
                .Single(method => current.Reader.GetString(method.Name) == "GetDeviceID").GetImport();
            Assert.Equal("tbs.dll", current.Reader.GetString(current.Reader.GetModuleReference(getDeviceId.Module).Name));
            Assert.DoesNotContain(current.Reader.MethodDefinitions.Select(current.Reader.GetMethodDefinition),
                method => current.Reader.GetString(method.Name) == "AmsiResultIsMalware");
            string[] sharedRpc = { "BSTR_UserSize64", "BSTR_UserMarshal64", "BSTR_UserUnmarshal64", "BSTR_UserFree64" };
            foreach (string name in sharedRpc)
            {
                var method = current.Reader.MethodDefinitions.Select(current.Reader.GetMethodDefinition)
                    .Single(value => current.Reader.GetString(value.Name) == name);
                AssertStringAttribute(current.Reader, method.GetCustomAttributes(),
                    "SupportedOSPlatformAttribute", "windows5.1.2600");
            }
            Assert.Equal(43 + sharedRpc.Length, current.Reader.CustomAttributes.Count(handle =>
                AttributeName(current.Reader, handle) == "SupportedOSPlatformAttribute"));
            foreach (var item in new[]
            {
                (Name: "TBS_COMMAND_PRIORITY", Members: new[] { "LOW", "NORMAL", "SYSTEM", "HIGH", "MAX" },
                    Values: new uint[] { 100, 200, 400, 300, 0x80000000 }),
                (Name: "TBS_COMMAND_LOCALITY", Members: new[] { "ZERO", "ONE", "TWO", "THREE", "FOUR" },
                    Values: new uint[] { 0, 1, 2, 3, 4 }),
            })
            {
                var type = FindType(current.Reader, item.Name);
                AssertDoesNotHaveAttribute(current.Reader, type.GetCustomAttributes(), "FlagsAttribute");
                AssertDoesNotHaveAttribute(current.Reader, type.GetCustomAttributes(), "ScopedEnumAttribute");
                var fields = type.GetFields().Select(current.Reader.GetFieldDefinition).ToArray();
                Assert.Equal("value__", current.Reader.GetString(fields[0].Name));
                Assert.Equal("UInt32", fields[0].DecodeSignature(new SignatureNames(), null));
                Assert.Equal(item.Members.Select(name => item.Name + "_" + name),
                    fields.Skip(1).Select(field => current.Reader.GetString(field.Name)));
                Assert.Equal(item.Values, fields.Skip(1).Select(field =>
                {
                    var constant = current.Reader.GetConstant(field.GetDefaultValue());
                    Assert.Equal(ConstantTypeCode.UInt32, constant.TypeCode);
                    return current.Reader.GetBlobReader(constant.Value).ReadUInt32();
                }));
            }

            static string[] Snapshot(MetadataReader reader) => reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Select(type => WinHttpMigrationTests.SnapshotType(reader, type)).OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        [MigrationTheory("WINHTTP_DEVICE_PRODUCER_ROOT", "WINHTTP_DEVICE_PRODUCER_BASELINE")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void DeviceProducerSourceProjectionPreservesFamiliesAndMovesOnlyFourOutputContracts(string architecture)
        {
            AssertDeviceProducerSourceProjection(Environment.GetEnvironmentVariable("WINHTTP_DEVICE_PRODUCER_ROOT"),
                Environment.GetEnvironmentVariable("WINHTTP_DEVICE_PRODUCER_BASELINE"), architecture,
                WinHttpMigrationTests.DeviceProducerTransfers);
        }

        [MigrationTheory("WINHTTP_DEVICE_UI_PRODUCER_ROOT", "WINHTTP_DEVICE_UI_PRODUCER_BASELINE")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void DeviceUiProducerSourceProjectionPreservesFamiliesAndMovesOnlyFiveProducerContracts(string architecture)
        {
            AssertDeviceProducerSourceProjection(Environment.GetEnvironmentVariable("WINHTTP_DEVICE_UI_PRODUCER_ROOT"),
                Environment.GetEnvironmentVariable("WINHTTP_DEVICE_UI_PRODUCER_BASELINE"), architecture,
                WinHttpMigrationTests.DeviceUiProducerTransfers);
        }

        private static void AssertDeviceProducerSourceProjection(string root, string baselinePath, string architecture,
            (string Header, string Partition, string Namespace, string TypeName,
                string Method, string Parameter, string Cleanup, long[] InvalidValues)[] transfers)
        {
            var families = transfers.DistinctBy(value => value.TypeName).ToArray();
            using var baseline = new MetadataImage(baselinePath);
            using var before = Component("before", "original-autoTypes.json");
            using var after = Component("after", "candidate-owned-autoTypes.json");
            AssertMetadataClosure(before.Reader);
            AssertMetadataClosure(after.Reader);
            Assert.Equal(families.Length, before.Reader.CustomAttributes.Count(handle => AttributeName(before.Reader, handle) == "RAIIFreeAttribute"));
            Assert.Equal(families.Sum(value => value.InvalidValues.Length),
                before.Reader.CustomAttributes.Count(handle => AttributeName(before.Reader, handle) == "InvalidHandleValueAttribute"));
            Assert.Equal(transfers.Length, after.Reader.CustomAttributes.Count(handle => AttributeName(after.Reader, handle) == "RAIIFreeAttribute"));
            Assert.Equal(transfers.Sum(value => value.InvalidValues.Length),
                after.Reader.CustomAttributes.Count(handle => AttributeName(after.Reader, handle) == "InvalidHandleValueAttribute"));
            var originalTypes = TypeSnapshots(before.Reader);
            var currentTypes = TypeSnapshots(after.Reader);
            Assert.Equal(originalTypes.Keys, currentTypes.Keys);
            var changed = families.Select(value => value.Namespace + "." + value.TypeName)
                .Concat(families.Select(value => value.Namespace + ".Apis")).ToHashSet(StringComparer.Ordinal);
            foreach (var entry in originalTypes.Where(value => !changed.Contains(value.Key)))
                Assert.Equal(entry.Value, currentTypes[entry.Key]);

            var signatures = new SignatureNames(qualifiedNames: true);
            foreach (var family in families)
            {
                var original = FindType(before.Reader, family.TypeName);
                var current = FindType(after.Reader, family.TypeName);
                Assert.Equal(WinHttpMigrationTests.SnapshotType(baseline.Reader, FindType(baseline.Reader, family.TypeName)),
                    WinHttpMigrationTests.SnapshotType(before.Reader, original));
                Assert.Equal(family.Cleanup, ReadStringAttribute(before.Reader, original.GetCustomAttributes(), "RAIIFreeAttribute"));
                Assert.Equal(family.InvalidValues, ReadInvalidValues(before.Reader, original.GetCustomAttributes()));
                AssertDoesNotHaveAttribute(after.Reader, current.GetCustomAttributes(), "RAIIFreeAttribute");
                AssertDoesNotHaveAttribute(after.Reader, current.GetCustomAttributes(), "InvalidHandleValueAttribute");
                Assert.Equal(original.Attributes, current.Attributes);
                Assert.Equal(original.GetLayout().PackingSize, current.GetLayout().PackingSize);
                Assert.Equal(original.GetLayout().Size, current.GetLayout().Size);
                Assert.Equal(HandleKind.TypeReference, original.BaseType.Kind);
                Assert.Equal(HandleKind.TypeReference, current.BaseType.Kind);
                Assert.Equal(signatures.GetTypeFromReference(before.Reader, (TypeReferenceHandle)original.BaseType, 0),
                    signatures.GetTypeFromReference(after.Reader, (TypeReferenceHandle)current.BaseType, 0));
                Assert.Equal(Facts(before.Reader, original.GetCustomAttributes(), true),
                    Facts(after.Reader, current.GetCustomAttributes(), true));
                Assert.Equal(WinHttpMigrationTests.SnapshotType(before.Reader, original).Split('\n').First(),
                    WinHttpMigrationTests.SnapshotType(after.Reader, current).Split('\n').First());
                Assert.Equal(WinHttpMigrationTests.SnapshotType(before.Reader, original).Split('\n').Skip(2),
                    WinHttpMigrationTests.SnapshotType(after.Reader, current).Split('\n').Skip(2));
            }

            var usedTransfers = new HashSet<string>(StringComparer.Ordinal);
            foreach (var family in families)
            {
                var originalApis = Api(before.Reader, family.Namespace);
                var currentApis = Api(after.Reader, family.Namespace);
                Assert.Equal(originalApis.Attributes, currentApis.Attributes);
                Assert.Equal(Facts(before.Reader, originalApis.GetCustomAttributes()),
                    Facts(after.Reader, currentApis.GetCustomAttributes()));
                var originalMethods = originalApis.GetMethods().Select(before.Reader.GetMethodDefinition).ToArray();
                var currentMethods = currentApis.GetMethods().Select(after.Reader.GetMethodDefinition).ToArray();
                var expectedOrder = originalMethods.Select(method => before.Reader.GetString(method.Name)).ToList();
                Assert.True(expectedOrder.IndexOf(family.Cleanup) > expectedOrder.IndexOf(family.Method));
                Assert.True(expectedOrder.Remove(family.Cleanup));
                expectedOrder.Insert(expectedOrder.IndexOf(family.Method), family.Cleanup);
                Assert.Equal(expectedOrder, currentMethods.Select(method => after.Reader.GetString(method.Name)));
                foreach (var original in originalMethods)
                {
                    string name = before.Reader.GetString(original.Name);
                    var current = Assert.Single(currentMethods.Where(method => after.Reader.GetString(method.Name) == name));
                    Assert.Equal(original.Attributes, current.Attributes);
                    Assert.Equal(original.ImplAttributes, current.ImplAttributes);
                    var oldSignature = original.DecodeSignature(signatures, null);
                    var signature = current.DecodeSignature(signatures, null);
                    Assert.Equal(oldSignature.Header, signature.Header);
                    Assert.Equal(oldSignature.ReturnType, signature.ReturnType);
                    Assert.Equal(oldSignature.ParameterTypes.ToArray(), signature.ParameterTypes.ToArray());
                    Assert.Equal(Facts(before.Reader, original.GetCustomAttributes()), Facts(after.Reader, current.GetCustomAttributes()));
                    var oldImport = original.GetImport();
                    var import = current.GetImport();
                    Assert.Equal(oldImport.Attributes, import.Attributes);
                    Assert.Equal(before.Reader.GetString(oldImport.Name), after.Reader.GetString(import.Name));
                    Assert.Equal(before.Reader.GetString(before.Reader.GetModuleReference(oldImport.Module).Name),
                        after.Reader.GetString(after.Reader.GetModuleReference(import.Module).Name));
                    var originalParameters = original.GetParameters().Select(before.Reader.GetParameter)
                        .ToDictionary(parameter => parameter.SequenceNumber);
                    var parameters = current.GetParameters().Select(after.Reader.GetParameter).ToArray();
                    Assert.Equal(originalParameters.Keys.OrderBy(value => value),
                        parameters.Select(parameter => parameter.SequenceNumber).OrderBy(value => value));
                    foreach (var parameter in parameters)
                    {
                        var originalParameter = originalParameters[parameter.SequenceNumber];
                        string parameterName = after.Reader.GetString(parameter.Name);
                        string target = parameter.SequenceNumber == 0 ? "return" : parameterName;
                        var transfer = transfers.SingleOrDefault(value => value.Method == name && value.Parameter == target);
                        Assert.Equal(before.Reader.GetString(originalParameter.Name), parameterName);
                        Assert.Equal(originalParameter.Attributes, parameter.Attributes);
                        Assert.Equal(Facts(before.Reader, originalParameter.GetCustomAttributes()),
                            Facts(after.Reader, parameter.GetCustomAttributes(), true));
                        if (transfer.Method == null)
                        {
                            AssertDoesNotHaveAttribute(after.Reader, parameter.GetCustomAttributes(), "RAIIFreeAttribute");
                            AssertDoesNotHaveAttribute(after.Reader, parameter.GetCustomAttributes(), "InvalidHandleValueAttribute");
                            continue;
                        }
                        Assert.True(usedTransfers.Add(name + "::" + target));
                        AssertStringAttribute(after.Reader, parameter.GetCustomAttributes(), "RAIIFreeAttribute", transfer.Cleanup);
                        Assert.Equal(transfer.InvalidValues, ReadInvalidValues(after.Reader, parameter.GetCustomAttributes()));
                        if (target == "return")
                        {
                            Assert.False(parameter.Attributes.HasFlag(ParameterAttributes.Out));
                            Assert.Equal(transfer.Namespace + "." + transfer.TypeName, signature.ReturnType);
                        }
                        else
                        {
                            Assert.True(parameter.Attributes.HasFlag(ParameterAttributes.Out));
                            Assert.Equal(transfer.Namespace + "." + transfer.TypeName + "*",
                                signature.ParameterTypes[parameter.SequenceNumber - 1]);
                        }
                    }
                }
            }
            Assert.Equal(transfers.Select(value => value.Method + "::" + value.Parameter).OrderBy(value => value, StringComparer.Ordinal),
                usedTransfers.OrderBy(value => value, StringComparer.Ordinal));

            MetadataImage Component(string state, string autoTypesFile)
            {
                string directory = Path.Combine(root, "components", architecture, state);
                Directory.CreateDirectory(directory);
                var names = new Dictionary<string, string>(StringComparer.Ordinal);
                foreach (var group in transfers.GroupBy(value => value.Partition, StringComparer.Ordinal))
                {
                    string generated = Path.Combine(root, state, "obj", "generated");
                    string path = new[] { architecture, "common" }.Select(folder =>
                        Path.Combine(generated, folder, group.Key + ".cs")).Single(File.Exists);
                    var source = CSharpSyntaxTree.ParseText(File.ReadAllText(path)).GetCompilationUnitRoot();
                    var apis = Assert.Single(source.DescendantNodes().OfType<ClassDeclarationSyntax>()
                        .Where(value => value.Identifier.ValueText == "Apis"));
                    var ns = Assert.Single(apis.Ancestors().OfType<NamespaceDeclarationSyntax>());
                    Assert.All(group, value => Assert.Equal(value.Namespace, ns.Name.ToString()));
                    var methods = group.Select(value => value.Method).Concat(group.Select(value => value.Cleanup))
                        .ToHashSet(StringComparer.Ordinal);
                    string familyPattern = @"\b(?:" + string.Join("|", group.Select(value => Regex.Escape(value.TypeName))
                        .Distinct(StringComparer.Ordinal)) + @")\b";
                    var selected = apis.Members.OfType<MethodDeclarationSyntax>()
                        .Where(value => Regex.IsMatch(value.ToString(), familyPattern)).ToArray();
                    Assert.All(methods, method => Assert.Single(selected.Where(value => value.Identifier.ValueText == method)));
                    source = source.WithMembers(SyntaxFactory.SingletonList<MemberDeclarationSyntax>(
                        ns.WithMembers(SyntaxFactory.SingletonList<MemberDeclarationSyntax>(
                            apis.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(selected))))));
                    File.WriteAllText(Path.Combine(directory, group.Key + ".cs"), source.ToFullString());
                    foreach (string cleanup in group.Select(value => value.Cleanup))
                        names[cleanup] = ns.Name.ToString();
                }
                var types = AutoTypeHelpers.GetAutoTypesFromFiles(new[] { Path.Combine(root, autoTypesFile) })
                    .Where(value => families.Any(family => family.TypeName == value.Name)).ToArray();
                Assert.Equal(families.Length, types.Length);
                using (var stream = File.Create(Path.Combine(directory, "NativeTypedefs.cs")))
                    NativeTypedefStructsCreator.WriteToStream(names, types, stream);
                return Emit(directory, architecture, references: new[] { baselinePath });
            }

            static TypeDefinition Api(MetadataReader reader, string ns) => reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(value => reader.GetString(value.Namespace) == ns && reader.GetString(value.Name) == "Apis");
            static Dictionary<string, string> TypeSnapshots(MetadataReader reader) => reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .OrderBy(value => reader.GetString(value.Namespace) + "." + reader.GetString(value.Name), StringComparer.Ordinal)
                .ToDictionary(value => reader.GetString(value.Namespace) + "." + reader.GetString(value.Name),
                    value => WinHttpMigrationTests.SnapshotType(reader, value), StringComparer.Ordinal);
            static string[] Facts(MetadataReader reader, CustomAttributeHandleCollection attributes, bool withoutOwnership = false)
                => attributes.Where(handle => !withoutOwnership ||
                    AttributeName(reader, handle) is not ("RAIIFreeAttribute" or "InvalidHandleValueAttribute"))
                    .Select(handle => AttributeName(reader, handle) + ":" +
                        Convert.ToHexString(reader.GetBlobBytes(reader.GetCustomAttribute(handle).Value)))
                    .OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        [NativeMigrationTheory("NETWORK_WINSPOOL_CONST_NORMAL_SOURCES")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void WinspoolNativePointeeConstNormalSourcesReachPhysicalMetadata(string architecture)
        {
            string source = Path.Combine(Environment.GetEnvironmentVariable("NETWORK_WINSPOOL_CONST_NORMAL_SOURCES"),
                architecture, "Printing.cs");
            string baseline = Environment.GetEnvironmentVariable("NETWORK_WINSPOOL_CONST_BASELINE_WINMD");
            string output = Environment.GetEnvironmentVariable("NETWORK_WINSPOOL_CONST_PHYSICAL_ROOT");
            Assert.True(File.Exists(source), "The actual ordinary Printing source is required: " + source);
            Assert.True(File.Exists(baseline), "The frozen physical baseline is required: " + baseline);
            Assert.False(string.IsNullOrEmpty(output));
            string directory = Path.Combine(output, architecture);
            Assert.False(Directory.Exists(directory), "Preserve prior physical attempts and select a fresh output directory.");
            Directory.CreateDirectory(directory);
            string sourceDirectory = Path.Combine(directory, architecture);
            Directory.CreateDirectory(sourceDirectory);

            var targets = WinHttpNativeControlTests.WinspoolConstParameters.ToHashSet(StringComparer.Ordinal);
            Assert.Equal(92, targets.Count);
            var methods = targets.Select(value => value.Substring(0, value.IndexOf("::", StringComparison.Ordinal)))
                .ToHashSet(StringComparer.Ordinal);
            var syntax = CSharpSyntaxTree.ParseText(File.ReadAllText(source)).GetCompilationUnitRoot();
            var ns = Assert.Single(syntax.Members.OfType<NamespaceDeclarationSyntax>());
            Assert.Equal("Windows.Win32.Graphics.Printing", ns.Name.ToString());
            var apis = Assert.Single(ns.Members.OfType<ClassDeclarationSyntax>()
                .Where(value => value.Identifier.ValueText == "Apis"));
            var selected = apis.Members.OfType<MethodDeclarationSyntax>()
                .Where(value => methods.Contains(value.Identifier.ValueText)).ToArray();
            Assert.Equal(54, selected.Length);
            Assert.Equal(methods.OrderBy(value => value, StringComparer.Ordinal),
                selected.Select(value => value.Identifier.ValueText).OrderBy(value => value, StringComparer.Ordinal));
            var subset = syntax.WithMembers(SyntaxFactory.SingletonList<MemberDeclarationSyntax>(
                ns.WithMembers(SyntaxFactory.SingletonList<MemberDeclarationSyntax>(
                    apis.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(selected))))));
            File.WriteAllText(Path.Combine(sourceDirectory, "Printing.cs"), subset.ToFullString());

            // Keep actual NORMAL declarations intact; the reference supplies unrelated native dependency types.
            using var original = new MetadataImage(baseline);
            using var current = Emit(directory, architecture, references: new[] { baseline });
            var oldApis = Assert.Single(original.Reader.TypeDefinitions.Select(original.Reader.GetTypeDefinition)
                .Where(value => original.Reader.GetString(value.Namespace) == "Windows.Win32.Graphics.Printing" &&
                    original.Reader.GetString(value.Name) == "Apis"));
            var newApis = FindType(current.Reader, "Apis");
            var observations = new List<object>();
            var signatureNames = new SignatureNames(qualifiedNames: true);
            foreach (string target in targets.OrderBy(value => value, StringComparer.Ordinal))
            {
                string[] names = target.Split(new[] { "::" }, StringSplitOptions.None);
                var nativeMethod = Assert.Single(selected.Where(value => value.Identifier.ValueText == names[0]));
                var nativeParameter = Assert.Single(nativeMethod.ParameterList.Parameters
                    .Where(value => value.Identifier.ValueText == names[1]));
                int index = nativeMethod.ParameterList.Parameters.IndexOf(nativeParameter);
                string alias = names[0].EndsWith("A", StringComparison.Ordinal) ? "LPCSTR" : "LPCWSTR";
                var nativeType = Assert.Single(nativeParameter.AttributeLists.SelectMany(value => value.Attributes)
                    .Where(value => value.Name.ToString() == "NativeTypeName"));
                Assert.Equal(alias, nativeType.ArgumentList.Arguments[0].Expression.ToString().Trim('"'));

                var oldMethod = Assert.Single(oldApis.GetMethods().Select(original.Reader.GetMethodDefinition)
                    .Where(value => original.Reader.GetString(value.Name) == names[0]));
                var newMethod = Assert.Single(newApis.GetMethods().Select(current.Reader.GetMethodDefinition)
                    .Where(value => current.Reader.GetString(value.Name) == names[0]));
                var oldParameter = Assert.Single(oldMethod.GetParameters().Select(original.Reader.GetParameter)
                    .Where(value => original.Reader.GetString(value.Name) == names[1]));
                var newParameter = Assert.Single(newMethod.GetParameters().Select(current.Reader.GetParameter)
                    .Where(value => current.Reader.GetString(value.Name) == names[1]));
                Assert.Equal(index + 1, oldParameter.SequenceNumber);
                Assert.Equal(oldParameter.SequenceNumber, newParameter.SequenceNumber);
                Assert.Equal(oldParameter.Attributes, newParameter.Attributes);
                Assert.Single(oldParameter.GetCustomAttributes()
                    .Where(value => AttributeName(original.Reader, value) == "ConstAttribute"));
                Assert.Single(newParameter.GetCustomAttributes()
                    .Where(value => AttributeName(current.Reader, value) == "ConstAttribute"));
                string oldType = oldMethod.DecodeSignature(signatureNames, null).ParameterTypes[index];
                string newType = newMethod.DecodeSignature(signatureNames, null).ParameterTypes[index];
                Assert.Equal(oldType, newType);
                Assert.Equal("Windows.Win32.Foundation." + (alias == "LPCSTR" ? "PSTR" : "PWSTR"), newType);
                observations.Add(new
                {
                    symbol = target, parameterIndex = index,
                    beforeNativeTypeName = alias == "LPCSTR" ? "LPSTR" : "LPWSTR",
                    afterNativeTypeName = alias, pointerIndirection = 1, nativePointeeConstChangeAuthorized = true,
                    oldPhysicalType = oldType, newPhysicalType = newType, oldConstCount = 1, newConstCount = 1,
                    parameterFlags = newParameter.Attributes.ToString(), legacyMemberRemapsUsed = 0,
                });
            }
            Assert.Equal(92, observations.Count);
            AssertMetadataClosure(current.Reader);
            string image = Path.Combine(directory, "Test.winmd");
            File.WriteAllText(Path.Combine(directory, "normal-physical-observations.json"), JsonSerializer.Serialize(new
            {
                architecture, actualNormalSource = source,
                normalSourceSha256 = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(source))),
                baselineWinmd = baseline,
                baselineSha256 = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(baseline))),
                physicalImage = image, physicalImageSha256 = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(image))),
                actualNormalMethodsUnmodified = 54, exactParameters = observations, legacyMemberRemapsUsed = 0,
                fullSdkImageOrConsumerClaimed = false,
            }, new JsonSerializerOptions { WriteIndented = true }));
        }

        internal static MetadataImage Emit(string directory, string architecture, HashSet<string> reducePointerLevels = null,
            bool nativeFieldArrayInfo = false, Dictionary<string, string> memberRemaps = null,
            IEnumerable<string> references = null, Dictionary<string, string> requiredNamespaces = null)
        {
            File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"),
                Path.Combine(directory, "Metadata.manual.cs"), overwrite: true);
            var compilation = ClangSharpSourceCompilation.Create(directory, architecture,
                memberRemaps ?? new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(), Array.Empty<string>(),
                new Dictionary<string, string>(), requiredNamespaces ?? new Dictionary<string, string>(), new HashSet<string>(),
                references ?? Array.Empty<string>(), new Dictionary<string, string>(), new Dictionary<string, string>(), nativeFieldArrayInfo);
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string path = Path.Combine(directory, "Test.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation,
                new Dictionary<string, string>(), reducePointerLevels ?? new HashSet<string>(), new HashSet<string>(), new Version(1, 0), path);
            Assert.True(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            return new MetadataImage(path);
        }

        private static void WriteNormalMethod(string source, string name, string destination)
        {
            var method = CSharpSyntaxTree.ParseText(File.ReadAllText(source)).GetRoot().DescendantNodes()
                .OfType<MethodDeclarationSyntax>().Single(value => value.Identifier.ValueText == name);
            var api = Assert.IsType<ClassDeclarationSyntax>(method.Parent);
            var ns = Assert.IsType<NamespaceDeclarationSyntax>(api.Parent);
            var boundedApi = api.WithMembers(SyntaxFactory.SingletonList<MemberDeclarationSyntax>(method));
            var boundedSource = SyntaxFactory.ParseCompilationUnit(
                "using System; using System.Runtime.InteropServices; using Windows.Win32.Foundation.Metadata;")
                .AddMembers(ns.WithMembers(SyntaxFactory.SingletonList<MemberDeclarationSyntax>(boundedApi)));
            File.WriteAllText(destination, boundedSource.NormalizeWhitespace().ToFullString());
        }

        private static TypeDefinition FindType(MetadataReader reader, string name)
            => reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type => reader.GetString(type.Name) == name);

        private static MethodDefinition FindMethod(MetadataReader reader, string type, string name)
            => FindType(reader, type).GetMethods().Select(reader.GetMethodDefinition).Single(method => reader.GetString(method.Name) == name);

        internal static string AttributeName(MetadataReader reader, CustomAttributeHandle handle)
        {
            var constructor = reader.GetCustomAttribute(handle).Constructor;
            var type = constructor.Kind == HandleKind.MethodDefinition
                ? reader.GetMethodDefinition((MethodDefinitionHandle)constructor).GetDeclaringType()
                : reader.GetMemberReference((MemberReferenceHandle)constructor).Parent;
            return type.Kind == HandleKind.TypeDefinition
                ? reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)type).Name)
                : reader.GetString(reader.GetTypeReference((TypeReferenceHandle)type).Name);
        }

        private static void AssertHasAttribute(MetadataReader reader, CustomAttributeHandleCollection attributes, string name)
            => Assert.Contains(attributes, handle => AttributeName(reader, handle) == name);

        private static void AssertDoesNotHaveAttribute(MetadataReader reader, CustomAttributeHandleCollection attributes, string name)
            => Assert.DoesNotContain(attributes, handle => AttributeName(reader, handle) == name);

        private static void AssertStringAttribute(MetadataReader reader, CustomAttributeHandleCollection attributes, string name, string value)
            => Assert.Equal(value, ReadStringAttribute(reader, attributes, name));

        private static string ReadStringAttribute(MetadataReader reader, CustomAttributeHandleCollection attributes, string name)
        {
            var attribute = reader.GetCustomAttribute(attributes.Single(handle => AttributeName(reader, handle) == name));
            var blob = reader.GetBlobReader(attribute.Value);
            Assert.Equal(1, blob.ReadUInt16());
            string value = blob.ReadSerializedString();
            Assert.Equal(0, blob.ReadUInt16());
            Assert.Equal(0, blob.RemainingBytes);
            return value;
        }

        private static long[] ReadInvalidValues(MetadataReader reader, CustomAttributeHandleCollection attributes)
            => attributes.Where(handle => AttributeName(reader, handle) == "InvalidHandleValueAttribute").Select(handle =>
            {
                var blob = reader.GetBlobReader(reader.GetCustomAttribute(handle).Value);
                Assert.Equal(1, blob.ReadUInt16());
                long value = blob.ReadInt64();
                Assert.Equal(0, blob.ReadUInt16());
                Assert.Equal(0, blob.RemainingBytes);
                return value;
            }).ToArray();

        private static void AssertMetadataClosure(MetadataReader reader)
        {
            var localTypes = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Select(type => reader.GetString(type.Namespace) + "." + reader.GetString(type.Name)).ToHashSet();
            foreach (var handle in reader.TypeReferences)
            {
                var type = reader.GetTypeReference(handle);
                Assert.False(type.ResolutionScope.IsNil);
                if (type.ResolutionScope.Kind == HandleKind.ModuleDefinition)
                    Assert.Contains(reader.GetString(type.Namespace) + "." + reader.GetString(type.Name), localTypes);
            }
            foreach (var handle in reader.CustomAttributes)
            {
                string name = AttributeName(reader, handle);
                Assert.DoesNotContain(name, new[] { "NativeAnnotationAttribute", "SourceLocationAttribute", "CppAttributeList" });
                var constructor = reader.GetCustomAttribute(handle).Constructor;
                if (constructor.Kind != HandleKind.MemberReference)
                    continue;
                var reference = reader.GetMemberReference((MemberReferenceHandle)constructor);
                if (reference.Parent.Kind != HandleKind.TypeReference)
                    continue;
                var type = reader.GetTypeReference((TypeReferenceHandle)reference.Parent);
                if (type.ResolutionScope.Kind != HandleKind.ModuleDefinition)
                    continue;

                string fullName = reader.GetString(type.Namespace) + "." + reader.GetString(type.Name);
                var definition = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(candidate =>
                    reader.GetString(candidate.Namespace) + "." + reader.GetString(candidate.Name) == fullName);
                var provider = new SignatureNames(qualifiedNames: true);
                var expected = reference.DecodeMethodSignature(provider, null);
                Assert.True(expected.Header.IsInstance);
                var actual = Assert.Single(definition.GetMethods().Select(reader.GetMethodDefinition)
                    .Where(method => reader.GetString(method.Name) == ".ctor")
                    .Select(method => (Method: method, Signature: method.DecodeSignature(provider, null)))
                    .Where(candidate => candidate.Signature.Header.RawValue == expected.Header.RawValue
                        && candidate.Signature.GenericParameterCount == expected.GenericParameterCount
                        && candidate.Signature.RequiredParameterCount == expected.RequiredParameterCount
                        && candidate.Signature.ReturnType == expected.ReturnType
                        && candidate.Signature.ParameterTypes.SequenceEqual(expected.ParameterTypes)));
                Assert.False(actual.Method.Attributes.HasFlag(MethodAttributes.Static));
                Assert.True(actual.Method.Attributes.HasFlag(MethodAttributes.SpecialName | MethodAttributes.RTSpecialName));
            }
        }

        internal sealed class MetadataImage : IDisposable
        {
            private readonly FileStream stream;
            private readonly PEReader image;
            internal MetadataImage(string path)
            {
                stream = File.OpenRead(path);
                image = new PEReader(stream);
                Reader = image.GetMetadataReader(MetadataReaderOptions.None);
            }
            internal MetadataReader Reader { get; }
            public void Dispose() { image.Dispose(); stream.Dispose(); }
        }

        internal sealed class SignatureNames : ISignatureTypeProvider<string, object>
        {
            private readonly bool qualifiedNames;
            internal SignatureNames(bool qualifiedNames = false) => this.qualifiedNames = qualifiedNames;

            public string GetArrayType(string elementType, ArrayShape shape) => elementType + "[]";
            public string GetByReferenceType(string elementType) => elementType + "&";
            public string GetFunctionPointerType(MethodSignature<string> signature) => "fnptr";
            public string GetGenericInstantiation(string genericType, ImmutableArray<string> typeArguments) => genericType;
            public string GetGenericMethodParameter(object context, int index) => "!!" + index;
            public string GetGenericTypeParameter(object context, int index) => "!" + index;
            public string GetModifiedType(string modifier, string type, bool required) => type;
            public string GetPinnedType(string elementType) => elementType;
            public string GetPointerType(string elementType) => elementType + "*";
            public string GetPrimitiveType(PrimitiveTypeCode type) => type.ToString();
            public string GetSZArrayType(string elementType) => elementType + "[]";
            public string GetTypeFromDefinition(MetadataReader reader, TypeDefinitionHandle handle, byte kind)
            {
                var type = reader.GetTypeDefinition(handle);
                return this.GetTypeName(reader, type.Namespace, type.Name);
            }
            public string GetTypeFromReference(MetadataReader reader, TypeReferenceHandle handle, byte kind)
            {
                var type = reader.GetTypeReference(handle);
                return this.GetTypeName(reader, type.Namespace, type.Name);
            }
            public string GetTypeFromSpecification(MetadataReader reader, object context, TypeSpecificationHandle handle, byte kind)
                => reader.GetTypeSpecification(handle).DecodeSignature(this, context);
            private string GetTypeName(MetadataReader reader, StringHandle @namespace, StringHandle name)
                => this.qualifiedNames ? reader.GetString(@namespace) + "." + reader.GetString(name) : reader.GetString(name);
        }
    }

    public sealed class ServiceApiMigrationTheoryAttribute : TheoryAttribute
    {
        public ServiceApiMigrationTheoryAttribute()
        {
            if (Environment.GetEnvironmentVariable("SERVICE_API_MIGRATION_ARTIFACTS") == null)
                Skip = "Set SERVICE_API_MIGRATION_ARTIFACTS to the bounded actual-header migration sources.";
        }
    }
}

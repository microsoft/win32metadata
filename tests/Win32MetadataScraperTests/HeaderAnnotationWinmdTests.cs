using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using ClangSharp;
using ClangSharp.Interop;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class HeaderAnnotationWinmdTests
    {
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
_Win32_RAIIFree_(CloseThing, 0, ((HANDLE)-1)) HANDLE __stdcall OpenThing();
int __stdcall CreateThing(_Out_ _Win32_RAIIFree_(CloseThing, 0) HANDLE* output);
_Win32_AssociatedEnum_(Options) unsigned __stdcall AssociatedReturn();
int __stdcall ReadOption(_In_ _Win32_AssociatedEnum_(Options) unsigned option);
_Win32_PreserveResult_ HRESULT __stdcall ExactResult();
int __stdcall Retval(_Out_ _Win32_Retval_ int* result);
int __stdcall MidlRetval(/* [out] [retval] */ _Out_ int* result);
TOKEN __stdcall UseToken(TOKEN value, TOKEN* output);
int __stdcall UseCallback(PFN_ALIAS callback);
}
struct __declspec(uuid(""b2051485-7dfd-41a0-af5c-1b351bfb1297"")) _Win32_SupportedOS_10240_ IHeaderSample {
    _Win32_PreserveResult_ _Win32_SupportedOS_Windows7_
    virtual HRESULT __stdcall Exact(_Out_ _Win32_Retval_ int* result) = 0;
    _Win32_RAIIFree_(CloseThing, 0, ((HANDLE)-1))
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
using DIRECT_TOKEN _Win32_SupportedOS_Windows7_ = unsigned;
using PFN_USING = SCOPED_TOKEN (__stdcall*)(_In_ _Win32_Retained_ void* context, _Out_ _Win32_Retval_ int* result);
using PFN_USING_ALIAS = PFN_USING;
using PFN_USING_NATIVE_ALIAS = PFN_SCOPED;
typedef PFN_USING PFN_TYPEDEF_USING_ALIAS;
_Win32_SupportedOS_Windows7_ typedef struct _PRIMARY_SCOPED { unsigned value; } PRIMARY_SCOPED;
SCOPED_TOKEN UseScopedToken(SCOPED_TOKEN value);
USING_TOKEN UseUsingToken(USING_TOKEN value);
void UseScopedCallbacks(PFN_SCOPED first, PFN_USING second, PFN_USING_ALIAS third, PFN_TYPEDEF_USING_ALIAS fourth);
_Win32_SupportedOS_BEGIN_(Windows7)
int Seven();
_Win32_SupportedOS_Windows8_ int ExplicitLater();
_Win32_SupportedOS_Windows7_ int ExplicitEqual();
_Win32_SupportedOS_Windows2000_ int ExplicitEarlier();
_Win32_SupportedOS_BEGIN_(Windows2000)
int OlderNested();
_Win32_SupportedOS_END_()
_Win32_SupportedOS_END_()
struct __declspec(uuid(""4d0ea686-f54d-4b53-aeec-bf6154950080"")) IScoped {
    virtual HRESULT __stdcall VistaMethod(_Out_ _Win32_Retval_ int* result) = 0;
    _Win32_SupportedOS_Windows7_ virtual HRESULT __stdcall SevenMethod() = 0;
    _Win32_SupportedOS_Windows2000_ virtual HRESULT __stdcall ExplicitMethod() = 0;
    virtual HRESULT __stdcall VistaAgainMethod() = 0;
};
_Win32_SupportedOS_END_()
int AfterScope();
struct __declspec(uuid(""b3dd7ce4-3a4c-42d8-b506-b32919dc848e"")) _Win32_SupportedOS_Windows7_ IContainerOnly {
    virtual HRESULT __stdcall UnannotatedMember(_Out_ _Win32_Retval_ int* result) = 0;
};
";

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
_Win32_SupportedOS_BEGIN_(Windows7)
int Nested(void);
_Win32_SupportedOS_Windows2000_ int Explicit(void);
_Win32_SupportedOS_END_()
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
namespace N {
enum Value { Invalid = 7 };
_Win32_RAIIFree_(CloseThing, Invalid, (1 ^ 2), ~0ULL, (HANDLE)-1) HANDLE Produce();
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
                arguments.AddRange(new[] { "-DWIN32METADATA", "-DWIN32METADATA_CSHARP" });
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
        public void NativeEnumConstantAliasesReachFinalWinmd(string architecture, string target, bool common)
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
    public const uint WER_SUBMIT_NO_QUEUE = 128;
    public const uint WER_SUBMIT_DISCARD_IF_QUEUED = WER_SUBMIT_NO_QUEUE;
    public const uint ALIAS_CHAIN = WER_SUBMIT_DISCARD_IF_QUEUED;
    public const uint SIGNED_ALL = 0xffffffff;
    public const uint UNSIGNED_ALIAS = SIGNED_ALL;
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
            Assert.Equal(128u, ReadUInt32(constants["WER_SUBMIT_DISCARD_IF_QUEUED"]));
            Assert.Equal(128u, ReadUInt32(constants["ALIAS_CHAIN"]));
            Assert.Equal(uint.MaxValue, ReadUInt32(constants["UNSIGNED_ALIAS"]));
            Assert.Equal(9u, ReadUInt32(constants["UNRELATED_ALIAS"]));
            Assert.Equal(7u, ReadUInt32(FindType(reader, "OtherFlags").GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == "WER_SUBMIT_NO_QUEUE")));
            AssertMetadataClosure(reader);

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
            if (ambiguous)
            {
                var exception = Assert.Throws<AggregateException>(Create);
                Assert.Contains(exception.Flatten().InnerExceptions, error =>
                    error is InvalidOperationException && error.Message.Contains("Ambiguous enum constant alias 'Test.SHARED'"));
            }
            else
            {
                Assert.Contains(Create().GetDiagnostics(), diagnostic => diagnostic.Id == "CS0103");
            }

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

        internal static MetadataImage Emit(string directory, string architecture, HashSet<string> reducePointerLevels = null,
            bool nativeFieldArrayInfo = false, Dictionary<string, string> memberRemaps = null)
        {
            File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"),
                Path.Combine(directory, "Metadata.manual.cs"));
            var compilation = ClangSharpSourceCompilation.Create(directory, architecture,
                memberRemaps ?? new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(), Array.Empty<string>(),
                new Dictionary<string, string>(), new Dictionary<string, string>(), new HashSet<string>(),
                Array.Empty<string>(), new Dictionary<string, string>(), new Dictionary<string, string>(), nativeFieldArrayInfo);
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string path = Path.Combine(directory, "Test.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation,
                new Dictionary<string, string>(), reducePointerLevels ?? new HashSet<string>(), new HashSet<string>(), new Version(1, 0), path);
            Assert.True(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            return new MetadataImage(path);
        }

        private static TypeDefinition FindType(MetadataReader reader, string name)
            => reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type => reader.GetString(type.Name) == name);

        private static MethodDefinition FindMethod(MetadataReader reader, string type, string name)
            => FindType(reader, type).GetMethods().Select(reader.GetMethodDefinition).Single(method => reader.GetString(method.Name) == name);

        private static string AttributeName(MetadataReader reader, CustomAttributeHandle handle)
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

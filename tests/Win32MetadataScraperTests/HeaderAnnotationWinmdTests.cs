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
    public abstract partial class HeaderAnnotationWinmdTests
    {
        internal const string AssociatedConstantNativeDeclarations = @"
typedef enum _Win32_AssociatedConstant_(CLSCTX_ALL) _Win32_AssociatedConstant_(CLSCTX_SERVER)
__attribute__((flag_enum)) tagCLSCTX {
    CLSCTX_INPROC_SERVER = 1,
    CLSCTX_INPROC_HANDLER = 2,
    CLSCTX_LOCAL_SERVER = 4,
    CLSCTX_REMOTE_SERVER = 16
} CLSCTX;
#if (_WIN32_WINNT >= 0x0400) || defined(_WIN32_DCOM)
#define CLSCTX_ALL (CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER | CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER)
#define CLSCTX_SERVER (CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER)
#else
#define CLSCTX_ALL (CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER | CLSCTX_LOCAL_SERVER)
#define CLSCTX_SERVER (CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER)
#endif
typedef enum _Win32_AssociatedConstant_(D3DTS_WORLD) _Win32_AssociatedConstant_(D3DTS_WORLD1)
_Win32_AssociatedConstant_(D3DTS_WORLD2) _Win32_AssociatedConstant_(D3DTS_WORLD3)
_D3DTRANSFORMSTATETYPE : int { D3DTS_VIEW = 2, D3DTS_PROJECTION = 3 } D3DTRANSFORMSTATETYPE;
#define D3DTS_WORLDMATRIX(index) (D3DTRANSFORMSTATETYPE)(index + 256)
#define D3DTS_WORLD D3DTS_WORLDMATRIX(0)
#define D3DTS_WORLD1 D3DTS_WORLDMATRIX(1)
#define D3DTS_WORLD2 D3DTS_WORLDMATRIX(2)
#define D3DTS_WORLD3 D3DTS_WORLDMATRIX(3)
#define UNRELATED_NUMBER 19U
#define UNRELATED_POINTER ((void*)-1)
void KeepNative(unsigned value);
";
        internal const string Declarations = @"
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
        internal const string ScopedDeclarations = @"
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
        internal static string[] NativeSurface(HeaderAnnotationTests.NativeFixture fixture, string target, bool metadataEnabled, string language = "c++")
        {
            string source = Path.Combine(fixture.DirectoryPath, "test.cpp");
            var arguments = new List<string> { "--language=" + language, "--std=" + (language == "c" ? "c11" : "c++17"), "--target=" + target, "--include-directory=" + Path.Combine(AppContext.BaseDirectory, "assets"), "-D_USE_DECLSPECS_FOR_SAL=1", "-D_PREFAST_=1", };
            if (metadataEnabled)
                arguments.Add("-DWIN32METADATA");
            using var index = CXIndex.Create(false, false);
            Console.WriteLine($"TEST-TOOLCHAIN direct-ABI-parse target={target}; metadata={metadataEnabled}");
            Assert.Equal(CXErrorCode.CXError_Success, CXTranslationUnit.TryParse(index, source, arguments.ToArray(), ReadOnlySpan<CXUnsavedFile>.Empty, CXTranslationUnit_Flags.CXTranslationUnit_IncludeAttributedTypes, out var handle));
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

        internal static MetadataImage Emit(HeaderAnnotationTests.NativeFixture fixture, string architecture) => Emit(fixture.DirectoryPath, architecture);
        internal static MetadataImage Emit(string directory, string architecture, HashSet<string> reducePointerLevels = null, bool nativeFieldArrayInfo = false, Dictionary<string, string> memberRemaps = null, IEnumerable<string> references = null, Dictionary<string, string> requiredNamespaces = null, Dictionary<string, Dictionary<string, string>> enumAdditions = null, string winmdFileName = "Test.winmd", Dictionary<string, string> apiNamesToNamespaces = null, string metadataSource = null)
        {
            if (metadataSource == null)
                File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"), Path.Combine(directory, "Metadata.manual.cs"), overwrite: true);
            else
                File.WriteAllText(Path.Combine(directory, "Metadata.manual.cs"), metadataSource);
            var compilation = ClangSharpSourceCompilation.Create(directory, architecture, memberRemaps ?? new Dictionary<string, string>(), enumAdditions ?? new Dictionary<string, Dictionary<string, string>>(), Array.Empty<string>(), new Dictionary<string, string>(), requiredNamespaces ?? new Dictionary<string, string>(), new HashSet<string>(), references ?? Array.Empty<string>(), new Dictionary<string, string>(), apiNamesToNamespaces ?? new Dictionary<string, string>(), nativeFieldArrayInfo);
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string path = Path.Combine(directory, winmdFileName);
            Console.WriteLine($"TEST-TOOLCHAIN physical-WinMD-emission architecture={architecture}");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation, new Dictionary<string, string>(), reducePointerLevels ?? new HashSet<string>(), new HashSet<string>(), new Version(1, 0), path);
            Assert.True(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            return new MetadataImage(path);
        }

        internal static TypeDefinition FindType(MetadataReader reader, string name) => reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type => reader.GetString(type.Name) == name);
        internal static MethodDefinition FindMethod(MetadataReader reader, string type, string name) => FindType(reader, type).GetMethods().Select(reader.GetMethodDefinition).Single(method => reader.GetString(method.Name) == name);
        internal static string AttributeName(MetadataReader reader, CustomAttributeHandle handle)
        {
            var constructor = reader.GetCustomAttribute(handle).Constructor;
            var type = constructor.Kind == HandleKind.MethodDefinition ? reader.GetMethodDefinition((MethodDefinitionHandle)constructor).GetDeclaringType() : reader.GetMemberReference((MemberReferenceHandle)constructor).Parent;
            return type.Kind == HandleKind.TypeDefinition ? reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)type).Name) : reader.GetString(reader.GetTypeReference((TypeReferenceHandle)type).Name);
        }

        internal static void AssertHasAttribute(MetadataReader reader, CustomAttributeHandleCollection attributes, string name) => Assert.Contains(attributes, handle => AttributeName(reader, handle) == name);
        internal static void AssertDoesNotHaveAttribute(MetadataReader reader, CustomAttributeHandleCollection attributes, string name) => Assert.DoesNotContain(attributes, handle => AttributeName(reader, handle) == name);
        internal static void AssertStringAttribute(MetadataReader reader, CustomAttributeHandleCollection attributes, string name, string value) => Assert.Equal(value, ReadStringAttribute(reader, attributes, name));
        internal static string ReadStringAttribute(MetadataReader reader, CustomAttributeHandleCollection attributes, string name)
        {
            var attribute = reader.GetCustomAttribute(attributes.Single(handle => AttributeName(reader, handle) == name));
            var blob = reader.GetBlobReader(attribute.Value);
            Assert.Equal(1, blob.ReadUInt16());
            string value = blob.ReadSerializedString();
            Assert.Equal(0, blob.ReadUInt16());
            Assert.Equal(0, blob.RemainingBytes);
            return value;
        }

        internal static long[] ReadInvalidValues(MetadataReader reader, CustomAttributeHandleCollection attributes) => attributes.Where(handle => AttributeName(reader, handle) == "InvalidHandleValueAttribute").Select(handle =>
        {
            var blob = reader.GetBlobReader(reader.GetCustomAttribute(handle).Value);
            Assert.Equal(1, blob.ReadUInt16());
            long value = blob.ReadInt64();
            Assert.Equal(0, blob.ReadUInt16());
            Assert.Equal(0, blob.RemainingBytes);
            return value;
        }).ToArray();
        internal static void AssertMetadataClosure(MetadataReader reader)
        {
            var localTypes = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Select(type => reader.GetString(type.Namespace) + "." + reader.GetString(type.Name)).ToHashSet();
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
                var definition = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(candidate => reader.GetString(candidate.Namespace) + "." + reader.GetString(candidate.Name) == fullName);
                var provider = new SignatureNames(qualifiedNames: true);
                var expected = reference.DecodeMethodSignature(provider, null);
                Assert.True(expected.Header.IsInstance);
                var actual = Assert.Single(definition.GetMethods().Select(reader.GetMethodDefinition).Where(method => reader.GetString(method.Name) == ".ctor").Select(method => (Method: method, Signature: method.DecodeSignature(provider, null))).Where(candidate => candidate.Signature.Header.RawValue == expected.Header.RawValue && candidate.Signature.GenericParameterCount == expected.GenericParameterCount && candidate.Signature.RequiredParameterCount == expected.RequiredParameterCount && candidate.Signature.ReturnType == expected.ReturnType && candidate.Signature.ParameterTypes.SequenceEqual(expected.ParameterTypes)));
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

            public void Dispose()
            {
                image.Dispose();
                stream.Dispose();
            }
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

            public string GetTypeFromSpecification(MetadataReader reader, object context, TypeSpecificationHandle handle, byte kind) => reader.GetTypeSpecification(handle).DecodeSignature(this, context);
            private string GetTypeName(MetadataReader reader, StringHandle @namespace, StringHandle name) => this.qualifiedNames ? reader.GetString(@namespace) + "." + reader.GetString(name) : reader.GetString(name);
        }
    }

    public partial class NativeContractBatchTests : HeaderAnnotationWinmdTests
    {
        private static void AssertNativeHeaders(HeaderAnnotationTests.NativeFixture fixture, MetadataReader reader)
        {
            var nativeCom = CSharpSyntaxTree.ParseText(File.ReadAllText(fixture.Output)).GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>().Single(node => node.Identifier.ValueText == "IHeaderSample");
            var nativeBuffer = nativeCom.Members.OfType<MethodDeclarationSyntax>().Single(node => node.Identifier.ValueText == "Buffer");
            Assert.True(nativeBuffer.ParameterList.Parameters[0].AttributeLists.ToString().Contains("ContainsInteriorPointers"), nativeCom.ToFullString());
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
            var associated = FindMethod(reader, "Apis", "AssociatedReturn").GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 0);
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
            var produced = FindMethod(reader, "IHeaderSample", "Produce").GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 0);
            AssertStringAttribute(reader, produced.GetCustomAttributes(), "RAIIFreeAttribute", "CloseThing");
            Assert.Equal(new long[] { 0, -1 }, ReadInvalidValues(reader, produced.GetCustomAttributes()));
            var buffer = FindMethod(reader, "IHeaderSample", "Buffer").GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 1);
            AssertHasAttribute(reader, buffer.GetCustomAttributes(), "ContainsInteriorPointersAttribute");
            Assert.True(buffer.Attributes.HasFlag(ParameterAttributes.Out));
            AssertMetadataClosure(reader);
        }
    }
}

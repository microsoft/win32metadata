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
        internal const string AssociatedConstantNativeDeclarations = Win32MetadataTestCases.HeaderAnnotationCases.AssociatedConstantNativeDeclarations;
        internal const string Declarations = Win32MetadataTestCases.HeaderAnnotationCases.NativeContractDeclarations;
        internal const string ScopedDeclarations = Win32MetadataTestCases.HeaderAnnotationCases.ScopedDeclarations;
        internal static string[] NativeSurface(HeaderAnnotationTests.NativeFixture fixture, string target, bool metadataEnabled,
            string language = "c++", IEnumerable<string> additionalArguments = null)
        {
            string source = Path.Combine(fixture.DirectoryPath, "test.cpp");
            var arguments = new List<string> { "--language=" + language, "--std=" + (language == "c" ? "c11" : "c++17"), "--target=" + target, "--include-directory=" + Path.Combine(AppContext.BaseDirectory, "assets"), "-D_USE_DECLSPECS_FOR_SAL=1", "-D_PREFAST_=1", };
            if (metadataEnabled)
                arguments.Add("-DWIN32METADATA");
            if (additionalArguments != null)
                arguments.AddRange(additionalArguments);
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
            Win32MetadataTestCases.NativeContractPhysicalAssertions.AssertNativeHeaders(reader);
        }
    }
}

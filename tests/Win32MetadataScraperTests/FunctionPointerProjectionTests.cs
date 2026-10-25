using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class FunctionPointerProjectionTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void BareFunctionAndPointerTypedefsKeepTheirDistinctPhysicalPointerDepths(
            string architecture, string target, bool annotationsEnabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef void __stdcall NATIVE_CALLBACK(unsigned long value);
typedef void (__stdcall *POINTER_CALLBACK)(unsigned long value);
void RegisterCallbacks(NATIVE_CALLBACK* direct, NATIVE_CALLBACK** indirect,
    NATIVE_CALLBACK*** deep, POINTER_CALLBACK pointer,
    POINTER_CALLBACK* pointerIndirect, POINTER_CALLBACK** pointerDeep);
NATIVE_CALLBACK* GetNativeCallback(void);
POINTER_CALLBACK GetPointerCallback(void);
struct CALLBACK_FIELDS { NATIVE_CALLBACK* Native; POINTER_CALLBACK Pointer; };
", annotationsEnabled: annotationsEnabled);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("public delegate void NATIVE_CALLBACK(", fixture.ReadSource());
            Assert.Contains("public delegate void POINTER_CALLBACK(", fixture.ReadSource());
            string output = Emit(fixture, architecture);
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var methods = reader.MethodDefinitions.Select(reader.GetMethodDefinition).ToArray();
            var register = methods.Single(method => reader.GetString(method.Name) == "RegisterCallbacks");
            var signature = reader.GetBlobReader(register.Signature);
            Assert.False(signature.ReadSignatureHeader().IsGeneric);
            Assert.Equal(6, signature.ReadCompressedInteger());
            Assert.Equal(SignatureTypeCode.Void, signature.ReadSignatureTypeCode());
            AssertCallbackType(reader, ref signature, "NATIVE_CALLBACK", 0);
            AssertCallbackType(reader, ref signature, "NATIVE_CALLBACK", 1);
            AssertCallbackType(reader, ref signature, "NATIVE_CALLBACK", 2);
            AssertCallbackType(reader, ref signature, "POINTER_CALLBACK", 0);
            AssertCallbackType(reader, ref signature, "POINTER_CALLBACK", 1);
            AssertCallbackType(reader, ref signature, "POINTER_CALLBACK", 2);
            Assert.Equal(0, signature.RemainingBytes);

            foreach (var item in new[] { ("GetNativeCallback", "NATIVE_CALLBACK"), ("GetPointerCallback", "POINTER_CALLBACK") })
            {
                var method = methods.Single(method => reader.GetString(method.Name) == item.Item1);
                var returned = reader.GetBlobReader(method.Signature);
                returned.ReadSignatureHeader();
                Assert.Equal(0, returned.ReadCompressedInteger());
                AssertCallbackType(reader, ref returned, item.Item2, 0);
                Assert.Equal(0, returned.RemainingBytes);
            }

            var fields = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "CALLBACK_FIELDS")
                .GetFields().Select(reader.GetFieldDefinition).ToArray();
            foreach (var item in new[] { ("Native", "NATIVE_CALLBACK"), ("Pointer", "POINTER_CALLBACK") })
            {
                var field = fields.Single(field => reader.GetString(field.Name) == item.Item1);
                var fieldSignature = reader.GetBlobReader(field.Signature);
                Assert.Equal(SignatureKind.Field, fieldSignature.ReadSignatureHeader().Kind);
                AssertCallbackType(reader, ref fieldSignature, item.Item2, 0);
                Assert.Equal(0, fieldSignature.RemainingBytes);
            }
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void StandaloneFunctionReductionRespectsExplicitPreservation(bool preserve)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef void __stdcall NATIVE_CALLBACK(unsigned long value);
void RegisterCallback(NATIVE_CALLBACK* callback);
", annotationsEnabled: false, extraSettings:
                (preserve ? "--preserve-auto-fnptr-level\nNATIVE_CALLBACK\n" : ""));
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string output = Emit(fixture, "x64");
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var method = reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                .Single(method => reader.GetString(method.Name) == "RegisterCallback");
            var signature = reader.GetBlobReader(method.Signature);
            signature.ReadSignatureHeader();
            Assert.Equal(1, signature.ReadCompressedInteger());
            Assert.Equal(SignatureTypeCode.Void, signature.ReadSignatureTypeCode());
            AssertCallbackType(reader, ref signature, "NATIVE_CALLBACK", preserve ? 1 : 0);
            Assert.Equal(0, signature.RemainingBytes);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void AuthoredRenameDoesNotReinterpretUnresolvedNativeCallbackSpelling(bool preserve)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef void __stdcall NATIVE_CALLBACK(unsigned long value);
void RegisterCallback(NATIVE_CALLBACK* callback);
", annotationsEnabled: false, extraSettings: "--remap\nNATIVE_CALLBACK=RENAMED_CALLBACK\n" +
                (preserve ? "--preserve-auto-fnptr-level\nNATIVE_CALLBACK\n" : ""));
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("public delegate void RENAMED_CALLBACK(", fixture.ReadSource());
            Assert.Contains("NativeTypeName(\"NATIVE_CALLBACK *\")", fixture.ReadSource());
            string output = Emit(fixture, "x64");
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var method = reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                .Single(method => reader.GetString(method.Name) == "RegisterCallback");
            var signature = reader.GetBlobReader(method.Signature);
            signature.ReadSignatureHeader();
            Assert.Equal(1, signature.ReadCompressedInteger());
            Assert.Equal(SignatureTypeCode.Void, signature.ReadSignatureTypeCode());
            Assert.Equal(SignatureTypeCode.IntPtr, signature.ReadSignatureTypeCode());
            Assert.Equal(0, signature.RemainingBytes);
        }

        private static string Emit(HeaderAnnotationTests.NativeFixture fixture, string architecture)
        {
            File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"),
                Path.Combine(fixture.DirectoryPath, "Metadata.manual.cs"));
            string remaps = Path.Combine(fixture.DirectoryPath, "remaps.txt");
            var reductions = File.Exists(remaps)
                ? File.ReadLines(remaps).Where(line => line.StartsWith("REDUCE_PTR_LEVEL:", StringComparison.Ordinal))
                    .Select(line => line.Substring("REDUCE_PTR_LEVEL:".Length)).ToHashSet(StringComparer.Ordinal)
                : new HashSet<string>(StringComparer.Ordinal);
            var compilation = ClangSharpSourceCompilation.Create(
                fixture.DirectoryPath, architecture, new Dictionary<string, string>(),
                new Dictionary<string, Dictionary<string, string>>(), Array.Empty<string>(),
                new Dictionary<string, string>(), new Dictionary<string, string>(),
                new HashSet<string>(), Array.Empty<string>(),
                new Dictionary<string, string>(), new Dictionary<string, string>());
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string output = Path.Combine(fixture.DirectoryPath, "Callbacks.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new Dictionary<string, string>(), reductions, new HashSet<string>(),
                new Version(1, 0, 0, 0), output);
            Assert.True(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            return output;
        }

        private static void AssertCallbackType(MetadataReader reader, ref BlobReader signature, string name, int pointers)
        {
            for (int index = 0; index < pointers; index++)
                Assert.Equal(SignatureTypeCode.Pointer, signature.ReadSignatureTypeCode());
            Assert.Equal(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            EntityHandle handle = signature.ReadTypeHandle();
            Assert.Equal(HandleKind.TypeDefinition, handle.Kind);
            var type = reader.GetTypeDefinition((TypeDefinitionHandle)handle);
            Assert.Equal("Test", reader.GetString(type.Namespace));
            Assert.Equal(name, reader.GetString(type.Name));
            var parent = reader.GetTypeReference((TypeReferenceHandle)type.BaseType);
            Assert.Equal("System", reader.GetString(parent.Namespace));
            Assert.Equal("MulticastDelegate", reader.GetString(parent.Name));
        }
    }
}

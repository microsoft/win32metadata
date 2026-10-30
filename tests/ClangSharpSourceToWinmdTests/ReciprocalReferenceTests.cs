using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class ReciprocalReferenceTests
    {
        [TestMethod]
        public void EmitWinmd_ExternalInterfaceInheritsFromCurrentAssembly_PreservesSignaturesAndSlots()
        {
            using var fixture = new Fixture();
            string originalWindows = fixture.EmitReference("Windows.Win32.winmd", @"
namespace Windows.Win32.System.Com
{
    public interface IUnknown { void QueryInterface(); void AddRef(); void Release(); }
}
namespace Windows.Win32.Graphics.Dxgi.Common
{
    public enum DXGI_FORMAT : uint { Unknown = 0 }
}");
            string sdk = fixture.EmitReference("Sdk.winmd", @"
namespace Windows.Win32.Graphics.Direct3D12
{
    public interface ID3D12Object : Windows.Win32.System.Com.IUnknown { void GetName(); }
    public interface ID3D12Device : ID3D12Object { void Create(); }
    public struct DescriptorHandle { public ulong Value; }
    public struct ResourceDescription { public Windows.Win32.Graphics.Dxgi.Common.DXGI_FORMAT Format; }
    public enum ResourceState : uint { Common = 0 }
}", originalWindows);
            string output = fixture.EmitWindows(sdk);

            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            MetadataReader reader = pe.GetMetadataReader(MetadataReaderOptions.None);
            TypeDefinition derived = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "IDerived");
            CollectionAssert.AreEqual(
                new[] { "OwnMethod" },
                derived.GetMethods().Select(reader.GetMethodDefinition).Select(method => reader.GetString(method.Name)).ToArray());
            TypeReference inherited = reader.GetTypeReference((TypeReferenceHandle)reader.GetInterfaceImplementation(
                derived.GetInterfaceImplementations().Single()).Interface);
            Assert.AreEqual("ID3D12Device", reader.GetString(inherited.Name));
            AssertSdkScope(reader, inherited);

            TypeDefinition probe = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "InteropProbe");
            foreach (FieldDefinition field in probe.GetFields().Select(reader.GetFieldDefinition))
            {
                BlobReader signature = reader.GetBlobReader(field.Signature);
                Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
                string name = reader.GetString(field.Name);
                if (name == "Description")
                {
                    Assert.AreEqual(SignatureTypeCode.Pointer, signature.ReadSignatureTypeCode());
                }
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                TypeReference type = reader.GetTypeReference((TypeReferenceHandle)signature.ReadTypeHandle());
                AssertSdkScope(reader, type);
                BlobReader raw = reader.GetBlobReader(field.Signature);
                raw.ReadByte();
                if (name == "Description")
                {
                    Assert.AreEqual((byte)0x0f, raw.ReadByte());
                }
                Assert.AreEqual(name == "Device" ? (byte)0x12 : (byte)0x11, raw.ReadByte());
            }

            Assert.IsFalse(reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Any(type => reader.GetString(type.Namespace) == "Windows.Win32.Graphics.Direct3D12"));
            Assert.IsFalse(reader.AssemblyReferences.Select(reader.GetAssemblyReference)
                .Any(reference => reader.GetString(reference.Name) == "Windows.Win32.winmd"));
        }

        [TestMethod]
        public void EmitWinmd_MissingInterfaceInAnotherAssembly_DoesNotUseSameNamedLocalType()
        {
            using var fixture = new Fixture();
            string other = fixture.EmitReference("Other.winmd", @"
namespace Windows.Win32.System.Com
{
    public interface IUnknown { void QueryInterface(); void AddRef(); void Release(); }
}
namespace Windows.Win32.Graphics.Dxgi.Common
{
    public enum DXGI_FORMAT : uint { Unknown = 0 }
}");
            string sdk = fixture.EmitReference("Sdk.winmd", @"
namespace Windows.Win32.Graphics.Direct3D12
{
    public interface ID3D12Object : Windows.Win32.System.Com.IUnknown { void GetName(); }
    public interface ID3D12Device : ID3D12Object { void Create(); }
    public struct DescriptorHandle { public ulong Value; }
    public struct ResourceDescription { public uint Format; }
    public enum ResourceState : uint { Common = 0 }
}", other);

            var error = Assert.ThrowsException<InvalidOperationException>(() => fixture.EmitWindows(sdk));
            StringAssert.Contains(error.Message, "Windows.Win32.System.Com.IUnknown");
            StringAssert.Contains(error.Message, "Other.winmd");
        }

        [TestMethod]
        public void EmitWinmd_ReferenceAlsoDefinesSourceInterfaces_DoesNotOverwriteSourceSlotCounts()
        {
            using var fixture = new Fixture();
            string[] unknown = { "QueryInterface", "AddRef", "Release" };
            string[] objectMethods = unknown.Concat(new[] { "GetPrivateData", "SetPrivateData", "SetPrivateDataInterface", "SetName" }).ToArray();
            string[] childMethods = objectMethods.Concat(new[] { "GetDevice" }).ToArray();
            string declarations = Interface("ID3D12Object", "IUnknown", objectMethods) +
                Interface("ID3D12DeviceChild", "ID3D12Object", childMethods) +
                Interface("ID3D12Pageable", "ID3D12DeviceChild", childMethods);
            string original = fixture.EmitSource("Windows.Win32.winmd",
                GetSource(Interface("IUnknown", null, unknown) + declarations));
            string sdk = fixture.EmitSource("Sdk.winmd", GetSource(declarations), original);

            using var stream = File.OpenRead(sdk);
            using var pe = new PEReader(stream);
            MetadataReader reader = pe.GetMetadataReader(MetadataReaderOptions.None);
            TypeDefinition pageable = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "ID3D12Pageable");
            Assert.AreEqual(0, pageable.GetMethods().Count);
            TypeDefinition child = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "ID3D12DeviceChild");
            CollectionAssert.AreEqual(new[] { "GetDevice" }, child.GetMethods().Select(reader.GetMethodDefinition)
                .Select(method => reader.GetString(method.Name)).ToArray());

            static string Interface(string name, string? inherited, string[] methods)
            {
                string inheritance = inherited == null ? string.Empty : $"[NativeInheritance(\"{inherited}\")]";
                return inheritance + $" public unsafe struct {name} {{ public void** lpVtbl; public delegate void _Call();" +
                    string.Join(Environment.NewLine, methods.Select((method, slot) =>
                        $"public void {method}() {{ Marshal.GetDelegateForFunctionPointer<_Call>((IntPtr)(lpVtbl[{slot}]))(); }}")) + "}";
            }

            static string GetSource(string interfaces)
            {
                return @"using System; using System.Runtime.InteropServices; using Windows.Win32.Foundation.Metadata;
namespace Windows.Win32.Foundation.Metadata
{
    public class NativeInheritanceAttribute : Attribute { public NativeInheritanceAttribute(string name) { } }
}
namespace Test { " + interfaces + " }";
            }
        }

        private static void AssertSdkScope(MetadataReader reader, TypeReference type)
        {
            Assert.AreEqual(HandleKind.AssemblyReference, type.ResolutionScope.Kind);
            Assert.AreEqual("Sdk.winmd", reader.GetString(reader.GetAssemblyReference((AssemblyReferenceHandle)type.ResolutionScope).Name));
        }

        private sealed class Fixture : IDisposable
        {
            private readonly string directory = Path.Combine(Path.GetTempPath(), "Win32MetadataReciprocal-" + Guid.NewGuid().ToString("N"));

            public string EmitReference(string name, string source, params string[] references)
            {
                var compilation = this.Create(name, source, references);
                string output = Path.Combine(this.directory, name);
                using var stream = File.Create(output);
                var result = compilation.CSharpCompilation.WithAssemblyName(name)
                    .WithOptions(compilation.CSharpCompilation.Options.WithOutputKind(OutputKind.DynamicallyLinkedLibrary)).Emit(stream);
                Assert.IsTrue(result.Success, string.Join(Environment.NewLine, result.Diagnostics));
                return output;
            }

            public string EmitWindows(string sdk)
            {
                var compilation = this.Create("current", @"
using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;
using Windows.Win32.Graphics.Direct3D12;
namespace Windows.Win32.Foundation.Metadata
{
    public class NativeInheritanceAttribute : Attribute { public NativeInheritanceAttribute(string name) { } }
}
namespace Windows.Win32.System.Com
{
    public unsafe struct IUnknown
    {
        public void** lpVtbl;
        public delegate void _QueryInterface();
        public void QueryInterface() { Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[0]))(); }
        public void AddRef() { Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[1]))(); }
        public void Release() { Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[2]))(); }
    }
}
namespace Windows.Win32.Graphics.Dxgi.Common
{
    public enum DXGI_FORMAT : uint { Unknown = 0 }
}
namespace Windows.Win32.Graphics.Interop
{
    public unsafe struct InteropProbe
    {
        public DescriptorHandle Handle;
        public ResourceState State;
        public ID3D12Device* Device;
        public ResourceDescription* Description;
    }
    [NativeInheritance(""ID3D12Device"")]
    public unsafe struct IDerived
    {
        public void** lpVtbl;
        public delegate void _QueryInterface();
        public void QueryInterface() { Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[0]))(); }
        public void AddRef() { Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[1]))(); }
        public void Release() { Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[2]))(); }
        public void GetName() { Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[3]))(); }
        public void Create() { Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[4]))(); }
        public void OwnMethod() { Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[5]))(); }
    }
}", new[] { sdk });
                return this.Emit(compilation, "Windows.Win32.winmd");
            }

            public string EmitSource(string name, string source, params string[] references)
            {
                return this.Emit(this.Create(name, source, references), name);
            }

            private string Emit(ClangSharpSourceCompilation compilation, string name)
            {
                string output = Path.Combine(this.directory, name);
                var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                    compilation, new Dictionary<string, string>(), new HashSet<string>(), new HashSet<string>(),
                    new Version(1, 0, 0, 0), output);
                Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
                return output;
            }

            private ClangSharpSourceCompilation Create(string name, string source, string[] references)
            {
                string sourceDirectory = Path.Combine(this.directory, name + "-source");
                Directory.CreateDirectory(sourceDirectory);
                File.WriteAllText(Path.Combine(sourceDirectory, "Test.manual.cs"), source);
                var compilation = ClangSharpSourceCompilation.Create(
                    sourceDirectory, "x64", new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(),
                    Array.Empty<string>(), new Dictionary<string, string>(), new Dictionary<string, string>(), new HashSet<string>(),
                    references, new Dictionary<string, string>(), new Dictionary<string, string>(),
                    name == "current" ? "Windows.Win32.winmd" : name);
                Diagnostic[] errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
                Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
                return compilation;
            }

            public void Dispose()
            {
                Directory.Delete(this.directory, true);
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class CrossArchMetadataTests
    {
        [TestMethod]
        public void EmitEnums_ArchitectureVariants_KeepNativeNamesValuesAndFlags()
        {
            using var fixture = new MetadataFixture();
            string winmd = fixture.Generate(
                string.Empty,
                "public enum Register { X64Register = 1 }",
                "public enum Register { Arm64Register = 2 }",
                new[] { "Register" });
            using var stream = File.OpenRead(winmd);
            using var pe = new PEReader(stream);
            MetadataReader reader = pe.GetMetadataReader(MetadataReaderOptions.None);
            TypeDefinition[] definitions = reader.TypeDefinitions
                .Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Namespace) == "Test")
                .ToArray();
            Assert.AreEqual(2, definitions.Length);

            var architectures = new HashSet<Architecture>();
            foreach (TypeDefinition type in definitions)
            {
                Assert.AreEqual("Register", reader.GetString(type.Name));
                CustomAttribute[] attributes = type.GetCustomAttributes().Select(reader.GetCustomAttribute).ToArray();
                Assert.IsTrue(attributes.Any(attribute => GetAttributeName(reader, attribute) == "FlagsAttribute"));
                CustomAttribute architectureAttribute = attributes.Single(attribute => GetAttributeName(reader, attribute) == "SupportedArchitectureAttribute");
                BlobReader value = reader.GetBlobReader(architectureAttribute.Value);
                Assert.AreEqual(1, value.ReadUInt16());
                Architecture architecture = (Architecture)value.ReadInt32();
                architectures.Add(architecture);

                FieldDefinition member = type.GetFields().Select(reader.GetFieldDefinition)
                    .Single(field => reader.GetString(field.Name) != "value__");
                string expectedName = architecture == Architecture.X64 ? "X64Register" : "Arm64Register";
                int expectedValue = architecture == Architecture.X64 ? 1 : 2;
                Assert.AreEqual(expectedName, reader.GetString(member.Name));
                Constant constant = reader.GetConstant(member.GetDefaultValue());
                Assert.AreEqual(expectedValue, reader.GetBlobReader(constant.Value).ReadInt32());
            }

            CollectionAssert.AreEquivalent(new[] { Architecture.X64, Architecture.Arm64 }, architectures.ToArray());
        }

        [DataTestMethod]
        [DataRow(Architecture.X64, Architecture.Arm64, false)]
        [DataRow(Architecture.X64, Architecture.X64, true)]
        [DataRow(Architecture.All, Architecture.Arm64, true)]
        [DataRow(Architecture.X64 | Architecture.Arm64, Architecture.Arm64, true)]
        public void DuplicateConstants_RequireOverlappingArchitectures(Architecture first, Architecture second, bool expectDuplicate)
        {
            using var fixture = new MetadataFixture();
            string winmd = fixture.Generate(
                GetSource(Architecture.X86),
                GetSource(Architecture.X64),
                GetSource(Architecture.Arm64));

            AssertToolExitCode("showDuplicateConstants", winmd, expectDuplicate ? -1 : 0);

            string GetSource(Architecture architecture)
            {
                return (first.HasFlag(architecture) ? "public enum First { Shared = 1 }" : string.Empty) +
                    (second.HasFlag(architecture) ? "public enum Second { Shared = 2 }" : string.Empty);
            }
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void BrokenArchTypes_InspectMatchingVariantWithoutHidingInvalidReferences(bool invalidReference)
        {
            using var fixture = new MetadataFixture();
            string x64FieldType = invalidReference ? "Arm64Only" : "RegisterValue";
            string winmd = fixture.Generate(
                string.Empty,
                "public struct X64Only { public int Value; }" +
                "public struct RegisterValue { public X64Only Value; }" +
                $"public struct X64Owner {{ public {x64FieldType} Value; }}",
                "public struct Arm64Only { public int Value; }" +
                "public struct RegisterValue { public Arm64Only Value; }" +
                "public struct Arm64Owner { public RegisterValue Value; }");

            AssertToolExitCode("showBrokenArchTypes", winmd, invalidReference ? -1 : 0);
        }

        [DataTestMethod]
        [DataRow(false, 1, 0)]
        [DataRow(true, 1, 0)]
        [DataRow(false, 2, 0)]
        [DataRow(true, 2, 0)]
        [DataRow(false, 1, 1)]
        [DataRow(true, 1, 1)]
        [DataRow(false, 2, 1)]
        [DataRow(true, 2, 1)]
        [DataRow(false, 1, 2)]
        [DataRow(true, 1, 2)]
        [DataRow(false, 1, 3)]
        [DataRow(false, 2, 3)]
        [DataRow(false, 1, 4)]
        [DataRow(true, 1, 4)]
        [DataRow(false, 2, 4)]
        [DataRow(true, 2, 4)]
        public void CallbackReferences_KeepArchitectureSpecificEncodedTargets(bool reverseOrder, int nativePointerDepth, int sourceKind)
        {
            using var fixture = new MetadataFixture();
            string winmd = fixture.Generate(
                Source(false), Source(true), Source(false),
                callbackOrder: sourceKind == 3 ? null : reverseOrder,
                reducePointerLevels: new HashSet<string> { "Callback" },
                commonSource: sourceKind == 3 ? OwnerSource() : null);
            using var stream = File.OpenRead(winmd);
            using var pe = new PEReader(stream);
            MetadataReader reader = pe.GetMetadataReader(MetadataReaderOptions.None);
            TypeDefinitionHandle[] pages = Types("Page");
            TypeDefinitionHandle[] containers = Types("Container");
            Assert.AreEqual(2, pages.Length, "The callback-dependent owner must split into architecture 2 and 5.");
            Assert.AreEqual(2, containers.Length, "Architecture-specific identity must propagate through containing fields.");
            CollectionAssert.AreEquivalent(
                new[] { Architecture.X64, Architecture.X86 | Architecture.Arm64 },
                pages.Select(ArchitectureOf).ToArray());
            var callbackTargets = new Dictionary<Architecture, TypeDefinitionHandle>();

            foreach (TypeDefinitionHandle pageHandle in pages)
            {
                Architecture architecture = ArchitectureOf(pageHandle);
                TypeDefinition page = reader.GetTypeDefinition(pageHandle);
                var fields = page.GetFields().Select(reader.GetFieldDefinition)
                    .ToDictionary(field => reader.GetString(field.Name));
                TypeDefinitionHandle captured = fields.ContainsKey("Captured")
                    ? FieldTarget(fields["Captured"], nativePointerDepth - 1) : FieldTarget(fields["Direct"], 0);
                if (fields.ContainsKey("Direct"))
                {
                    Assert.AreEqual(captured, FieldTarget(fields["Direct"], 0));
                    Assert.AreEqual(captured, FieldTarget(fields["Indirect"], 0));
                    Assert.AreEqual(captured, FieldTarget(fields["Aliased"], 0));
                }
                Assert.AreEqual(architecture, ArchitectureOf(captured));
                Assert.AreEqual("Callback", reader.GetString(reader.GetTypeDefinition(captured).Name));
                AssertInvoke(captured, architecture);
                callbackTargets.Add(architecture, captured);

                TypeDefinitionHandle container = containers.Single(handle => ArchitectureOf(handle) == architecture);
                FieldDefinition value = reader.GetTypeDefinition(container).GetFields()
                    .Select(reader.GetFieldDefinition).Single();
                Assert.AreEqual(pageHandle, FieldTarget(value, 0));
                Assert.AreNotEqual(Architecture.All, architecture);
            }

            MethodDefinition[] methods = reader.GetTypeDefinition(Types("Apis").Single()).GetMethods()
                .Select(reader.GetMethodDefinition).Where(method =>
                    reader.GetString(method.Name) is "NativeBridge" or "DirectBridge").ToArray();
            Assert.AreEqual(sourceKind is 1 or 2 ? 2 : 4, methods.Length);
            foreach (MethodDefinition method in methods)
            {
                Architecture architecture = AttributeArchitecture(method.GetCustomAttributes());
                BlobReader signature = reader.GetBlobReader(method.Signature);
                Assert.IsFalse(signature.ReadSignatureHeader().IsInstance);
                Assert.AreEqual(1, signature.ReadCompressedInteger());
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                Assert.AreEqual(callbackTargets[architecture], LocalType(ref signature));
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                Assert.AreEqual(callbackTargets[architecture], LocalType(ref signature));
                Assert.AreEqual(0, signature.RemainingBytes);
                Assert.AreEqual(System.Reflection.MethodImportAttributes.CallingConventionWinApi,
                    method.GetImport().Attributes & System.Reflection.MethodImportAttributes.CallingConventionMask);
            }

            string Source(bool x64)
            {
                string record = x64 ? "Record64*" : "void*";
                return "using CallbackAlias = global::Test.Callback; " +
                    (x64 ? "public struct Record64 { public ulong Value; }" : string.Empty) + @"
[System.Runtime.InteropServices.UnmanagedFunctionPointer(System.Runtime.InteropServices.CallingConvention.Winapi)]
public unsafe delegate int Callback(" + record + @" record, UIntPtr width, Callback* next);" +
                    (sourceKind == 3 ? string.Empty : OwnerSource()) +
                    (sourceKind == 4 ? "public struct Other { public int Marker; public delegate long Callback(long value); }" : string.Empty);
            }

            string OwnerSource() => "public unsafe struct Page { " +
                (sourceKind == 2 ? string.Empty :
                    @"[NativeTypeName(""Callback " + new string('*', nativePointerDepth) + @""")] public IntPtr Captured; ") +
                (sourceKind == 1 ? string.Empty :
                    "public global::Test.Callback Direct; public global::Test.Callback* Indirect; public CallbackAlias Aliased; ") +
                "} public struct Container { public Page Value; } " +
                "public static unsafe partial class Apis { " +
                (sourceKind == 2 ? string.Empty : @"
[DllImport(""fixture"", EntryPoint = ""NativeBridge"",
    CallingConvention = System.Runtime.InteropServices.CallingConvention.StdCall)]
[return: NativeTypeName(""Callback *"")]
public static extern IntPtr NativeBridge([NativeTypeName(""Callback *"")] IntPtr value);") +
                (sourceKind == 1 ? string.Empty : @"
[DllImport(""fixture"", EntryPoint = ""DirectBridge"",
    CallingConvention = System.Runtime.InteropServices.CallingConvention.StdCall)]
public static extern CallbackAlias DirectBridge(CallbackAlias value);") + " }";

            TypeDefinitionHandle[] Types(string name) => reader.TypeDefinitions
                .Where(handle => reader.GetString(reader.GetTypeDefinition(handle).Namespace) == "Test" &&
                    reader.GetString(reader.GetTypeDefinition(handle).Name) == name).ToArray();

            Architecture ArchitectureOf(TypeDefinitionHandle handle)
                => AttributeArchitecture(reader.GetTypeDefinition(handle).GetCustomAttributes());

            Architecture AttributeArchitecture(CustomAttributeHandleCollection handles)
            {
                CustomAttribute[] attributes = handles
                    .Select(reader.GetCustomAttribute)
                    .Where(attribute => GetAttributeName(reader, attribute) == "SupportedArchitectureAttribute").ToArray();
                if (attributes.Length == 0)
                    return Architecture.All;
                Assert.AreEqual(1, attributes.Length);
                BlobReader value = reader.GetBlobReader(attributes[0].Value);
                Assert.AreEqual(1, value.ReadUInt16());
                return (Architecture)value.ReadInt32();
            }

            TypeDefinitionHandle FieldTarget(FieldDefinition field, int pointerDepth)
            {
                BlobReader signature = reader.GetBlobReader(field.Signature);
                Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
                for (int i = 0; i < pointerDepth; i++)
                    Assert.AreEqual(SignatureTypeCode.Pointer, signature.ReadSignatureTypeCode());
                SignatureTypeCode kind = signature.ReadSignatureTypeCode();
                Assert.AreEqual(SignatureTypeCode.TypeHandle, kind);
                TypeDefinitionHandle target = LocalType(ref signature);
                Assert.AreEqual(0, signature.RemainingBytes);
                return target;
            }

            TypeDefinitionHandle LocalType(ref BlobReader signature)
            {
                EntityHandle handle = signature.ReadTypeHandle();
                Assert.AreEqual(HandleKind.TypeDefinition, handle.Kind, "The field must bind a specific local definition.");
                Assert.IsTrue(MetadataTokens.GetRowNumber(handle) > 0);
                return (TypeDefinitionHandle)handle;
            }

            void AssertInvoke(TypeDefinitionHandle callback, Architecture architecture)
            {
                TypeDefinition type = reader.GetTypeDefinition(callback);
                MethodDefinition invoke = type.GetMethods().Select(reader.GetMethodDefinition)
                    .Single(method => reader.GetString(method.Name) == "Invoke");
                BlobReader signature = reader.GetBlobReader(invoke.Signature);
                Assert.IsTrue(signature.ReadSignatureHeader().IsInstance);
                Assert.AreEqual(3, signature.ReadCompressedInteger());
                Assert.AreEqual(SignatureTypeCode.Int32, signature.ReadSignatureTypeCode());
                Assert.AreEqual(SignatureTypeCode.Pointer, signature.ReadSignatureTypeCode());
                if (architecture == Architecture.X64)
                {
                    Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                    Assert.AreEqual("Record64", reader.GetString(reader.GetTypeDefinition(LocalType(ref signature)).Name));
                }
                else
                {
                    Assert.AreEqual(SignatureTypeCode.Void, signature.ReadSignatureTypeCode());
                }
                Assert.AreEqual(SignatureTypeCode.UIntPtr, signature.ReadSignatureTypeCode());
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                Assert.AreEqual(callback, LocalType(ref signature));
                Assert.AreEqual(0, signature.RemainingBytes);
                CustomAttribute convention = type.GetCustomAttributes().Select(reader.GetCustomAttribute)
                    .Single(attribute => GetAttributeName(reader, attribute) == "UnmanagedFunctionPointerAttribute");
                BlobReader value = reader.GetBlobReader(convention.Value);
                Assert.AreEqual(1, value.ReadUInt16());
                Assert.AreEqual((int)System.Runtime.InteropServices.CallingConvention.Winapi, value.ReadInt32());
            }
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void NativeCallbackLookup_KeepsTheFullDeclaringScopeWithoutVariants(bool nestedFirst)
        {
            using var fixture = new MetadataFixture();
            string unrelated = "public struct Other { public int Marker; public delegate long Callback(long value); }";
            string source = (nestedFirst ? unrelated : string.Empty) +
                "public delegate int Callback(int value);" +
                (nestedFirst ? string.Empty : unrelated) +
                @"public struct Holder { [NativeTypeName(""Callback *"")] public IntPtr Value; }";
            string winmd = fixture.Generate(source, source, source, reducePointerLevels: new HashSet<string> { "Callback" });
            using var stream = File.OpenRead(winmd);
            using var pe = new PEReader(stream);
            MetadataReader reader = pe.GetMetadataReader(MetadataReaderOptions.None);
            TypeDefinition holder = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Namespace) == "Test" && reader.GetString(type.Name) == "Holder");
            FieldDefinition field = holder.GetFields().Select(reader.GetFieldDefinition).Single();
            BlobReader signature = reader.GetBlobReader(field.Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            EntityHandle target = signature.ReadTypeHandle();
            Assert.AreEqual(HandleKind.TypeDefinition, target.Kind);
            Assert.AreEqual(0, signature.RemainingBytes);
            TypeDefinition callback = reader.GetTypeDefinition((TypeDefinitionHandle)target);
            Assert.IsTrue(callback.GetDeclaringType().IsNil, "The selected callback must have the top-level declaring scope.");
            Assert.AreEqual("Test", reader.GetString(callback.Namespace));
            Assert.AreEqual("Callback", reader.GetString(callback.Name));
            MethodDefinition invoke = callback.GetMethods().Select(reader.GetMethodDefinition)
                .Single(method => reader.GetString(method.Name) == "Invoke");
            BlobReader invokeSignature = reader.GetBlobReader(invoke.Signature);
            Assert.IsTrue(invokeSignature.ReadSignatureHeader().IsInstance);
            Assert.AreEqual(1, invokeSignature.ReadCompressedInteger());
            Assert.AreEqual(SignatureTypeCode.Int32, invokeSignature.ReadSignatureTypeCode());
            Assert.AreEqual(SignatureTypeCode.Int32, invokeSignature.ReadSignatureTypeCode());
            Assert.AreEqual(0, invokeSignature.RemainingBytes);
        }

        private static string GetAttributeName(MetadataReader reader, CustomAttribute attribute)
        {
            EntityHandle parent = attribute.Constructor.Kind == HandleKind.MemberReference
                ? reader.GetMemberReference((MemberReferenceHandle)attribute.Constructor).Parent
                : reader.GetMethodDefinition((MethodDefinitionHandle)attribute.Constructor).GetDeclaringType();
            return parent.Kind == HandleKind.TypeDefinition
                ? reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)parent).Name)
                : reader.GetString(reader.GetTypeReference((TypeReferenceHandle)parent).Name);
        }

        private static string AssertToolExitCode(string command, string winmd, int expected)
        {
            using var process = new Process();
            process.StartInfo = new ProcessStartInfo("dotnet")
            {
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
            };
            process.StartInfo.ArgumentList.Add(Path.Combine(AppContext.BaseDirectory, "WinmdUtils.dll"));
            process.StartInfo.ArgumentList.Add(command);
            process.StartInfo.ArgumentList.Add("--winmd");
            process.StartInfo.ArgumentList.Add(winmd);
            process.Start();
            string output = process.StandardOutput.ReadToEnd();
            string error = process.StandardError.ReadToEnd();
            process.WaitForExit();

            Assert.AreEqual(expected, process.ExitCode, output + error);
            return output;
        }

        private sealed class MetadataFixture : IDisposable
        {
            private readonly string directory = Path.Combine(Path.GetTempPath(), "Win32MetadataTests-" + Guid.NewGuid().ToString("N"));

            public MetadataFixture()
            {
                Directory.CreateDirectory(this.directory);
                File.WriteAllText(Path.Combine(this.directory, "Attributes.manual.cs"), @"
using System;
namespace Windows.Win32.Foundation.Metadata
{
    [Flags]
    public enum Architecture { None = 0, X86 = 1, X64 = 2, Arm64 = 4, All = 7 }
    public class SupportedArchitectureAttribute : Attribute
    {
        public SupportedArchitectureAttribute(Architecture architecture) { }
    }
    public class NativeTypeNameAttribute : Attribute
    {
        public NativeTypeNameAttribute(string name) { }
    }
}");
            }

            public string Generate(string x86, string x64, string arm64, IEnumerable<string>? flags = null,
                bool? callbackOrder = null, HashSet<string>? reducePointerLevels = null, string? commonSource = null)
            {
                foreach (var source in new[] { ("x86", x86), ("x64", x64), ("arm64", arm64) })
                {
                    string architectureDirectory = Path.Combine(this.directory, source.Item1);
                    Directory.CreateDirectory(architectureDirectory);
                    File.WriteAllText(
                        Path.Combine(architectureDirectory, "Test.cs"),
                        "using System; using System.Runtime.InteropServices; using Windows.Win32.Foundation.Metadata; namespace Test { " + source.Item2 + " }");
                    if (commonSource != null)
                        File.WriteAllText(Path.Combine(architectureDirectory, "Owner.cs"),
                            "using System; using System.Runtime.InteropServices; using Windows.Win32.Foundation.Metadata; namespace Test { " +
                            "using CallbackAlias = global::Test.Callback; " + commonSource + " }");
                }

                string inputDirectory = this.directory;
                if (callbackOrder.HasValue)
                {
                    string[] order = callbackOrder.Value ? new[] { "x86", "arm64", "x64" } : new[] { "x64", "arm64", "x86" };
                    SyntaxTree[] trees = order.Select(architecture =>
                    {
                        string path = Path.Combine(this.directory, architecture, "Test.cs");
                        return CSharpSyntaxTree.ParseText(File.ReadAllText(path), path: path);
                    }).Append(CSharpSyntaxTree.ParseText(
                        File.ReadAllText(Path.Combine(this.directory, "Attributes.manual.cs")),
                        path: Path.Combine(this.directory, "Attributes.manual.cs"))).ToArray();
                    var map = new CrossArchSyntaxMap();
                    foreach (SyntaxTree tree in trees)
                        map.AddTree(tree);
                    var merger = new CrossArchTreeMerger(map, trees);
                    inputDirectory = Path.Combine(this.directory, "composed");
                    Directory.CreateDirectory(inputDirectory);
                    for (int i = 0; i < trees.Length; i++)
                        File.WriteAllText(Path.Combine(inputDirectory, $"Composed{i}.manual.cs"),
                            merger.ProcessTree(trees[i], out _).ToString());
                }

                var compilation = ClangSharpSourceCompilation.Create(
                    inputDirectory,
                    "crossarch",
                    new Dictionary<string, string>(),
                    new Dictionary<string, Dictionary<string, string>>(),
                    flags ?? Array.Empty<string>(),
                    new Dictionary<string, string>(),
                    new Dictionary<string, string>(),
                    new HashSet<string>(),
                    Array.Empty<string>(),
                    new Dictionary<string, string>(),
                    new Dictionary<string, string>());
                Diagnostic[] errors = compilation.GetDiagnostics()
                    .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
                Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));

                string output = Path.Combine(this.directory, "Test.winmd");
                ClangSharpSourceWinmdGenerator generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                    compilation,
                    new Dictionary<string, string>(),
                    reducePointerLevels ?? new HashSet<string>(),
                    new HashSet<string>(),
                    new Version(1, 0, 0, 0),
                    output);
                Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
                return output;
            }

            public void Dispose()
            {
                Directory.Delete(this.directory, true);
            }
        }
    }
}

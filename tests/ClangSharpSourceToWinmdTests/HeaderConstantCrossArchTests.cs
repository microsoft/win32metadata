using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Text.Json;
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public partial class HeaderConstantCrossArchTests
    {
        private static readonly string[] Architectures = { "x86", "x64", "arm64" };
        private const string MetadataSource = @"
namespace Windows.Win32.Foundation.Metadata
{
    [System.Flags] public enum Architecture { X86=1, X64=2, Arm64=4, All=7 }
    public class SupportedArchitectureAttribute:System.Attribute
    {
        public SupportedArchitectureAttribute(Architecture architecture) { }
    }
    public class NativeTypeNameAttribute:System.Attribute
    {
        public NativeTypeNameAttribute(string name) { }
    }
    public class NativeTypedefAttribute:System.Attribute { }
    public class ConstantAttribute:System.Attribute
    {
        public ConstantAttribute(string value) { }
    }
}";

        [DataTestMethod]
        [DataRow("sbyte", "18446744073709551615", ConstantTypeCode.SByte, "0604", "FF")]
        [DataRow("byte", "255", ConstantTypeCode.Byte, "0605", "FF")]
        [DataRow("short", "18446744073709551615", ConstantTypeCode.Int16, "0606", "FFFF")]
        [DataRow("ushort", "65535", ConstantTypeCode.UInt16, "0607", "FFFF")]
        [DataRow("int", "18446744073709551615", ConstantTypeCode.Int32, "0608", "FFFFFFFF")]
        [DataRow("uint", "4294967295", ConstantTypeCode.UInt32, "0609", "FFFFFFFF")]
        [DataRow("long", "9223372036854775808", ConstantTypeCode.Int64, "060A", "0000000000000080")]
        [DataRow("ulong", "18446744073709551615", ConstantTypeCode.UInt64, "060B", "FFFFFFFFFFFFFFFF")]
        public void PhysicalConstantVariantsPreserveStorageSignednessAndValueBits(
            string storage, string bits, ConstantTypeCode code, string signature, string valueBits)
        {
            Emit(Architectures.ToDictionary(architecture => architecture, architecture => Source(
                $"public const uint ALWAYS = 0U; public const {storage} EXTRA = unchecked(({storage})" +
                (architecture == "x86" ? bits : "0") + "UL);")), fields =>
            {
                AssertInvariant(fields);
                var extras = fields.Where(field => field.Name == "EXTRA").OrderBy(field => field.Architectures).ToArray();
                Assert.AreEqual(2, extras.Length);
                CollectionAssert.AreEqual(new int?[] { 1, 6 }, extras.Select(field => field.Architectures).ToArray());
                CollectionAssert.AreEqual(new[] { valueBits, new string('0', valueBits.Length) },
                    extras.Select(field => field.ValueBits).ToArray());
                foreach (var field in extras)
                {
                    Assert.AreEqual(signature, field.Signature);
                    Assert.AreEqual(code, field.ConstantType);
                    Assert.IsTrue(field.Attributes.HasFlag(
                        FieldAttributes.Public | FieldAttributes.Static | FieldAttributes.Literal | FieldAttributes.HasDefault));
                    Assert.AreEqual("Test", field.Namespace);
                }
            });
        }

        [DataTestMethod]
        [DataRow(1)]
        [DataRow(2)]
        [DataRow(3)]
        [DataRow(4)]
        [DataRow(5)]
        [DataRow(6)]
        public void PhysicalConstantAvailabilityIsTheUnionOfItsNativeProfiles(int mask)
        {
            Emit(Architectures.Select((architecture, index) => (architecture, index))
                .ToDictionary(item => item.architecture, item => Source("public const uint ALWAYS = 0U;" +
                    (((1 << item.index) & mask) != 0 ? "public const uint EXTRA = 2U;" : ""))), fields =>
            {
                AssertInvariant(fields);
                var extra = fields.Single(field => field.Name == "EXTRA");
                Assert.AreEqual(2, fields.Length);
                Assert.AreEqual(mask, extra.Architectures);
                Assert.AreEqual("0609", extra.Signature);
                Assert.AreEqual("02000000", extra.ValueBits);
            });
        }

        [TestMethod]
        public void IdenticalNativeTypeNamesDoNotHideDifferentManagedStorage()
        {
            Emit(Architectures.ToDictionary(architecture => architecture, architecture => Source(
                @"[NativeTypeName(""NATIVE_WORD"")] public const " +
                (architecture == "x86" ? "int EXTRA = -1;" : "uint EXTRA = 0xFFFFFFFFU;"))), fields =>
            {
                var extras = fields.OrderBy(field => field.Architectures).ToArray();
                Assert.AreEqual(2, extras.Length);
                CollectionAssert.AreEqual(new int?[] { 1, 6 }, extras.Select(field => field.Architectures).ToArray());
                CollectionAssert.AreEqual(new[] { "0608", "0609" }, extras.Select(field => field.Signature).ToArray());
                CollectionAssert.AreEqual(new ConstantTypeCode?[] { ConstantTypeCode.Int32, ConstantTypeCode.UInt32 },
                    extras.Select(field => field.ConstantType).ToArray());
                Assert.IsTrue(extras.All(field => field.Name == "EXTRA" && field.ValueBits == "FFFFFFFF"));
            });
        }

        [TestMethod]
        public void NamespaceQualifiedFieldIdentityDoesNotMergeUnrelatedGlobals()
        {
            Emit(Architectures.ToDictionary(architecture => architecture, architecture =>
                Source("public const uint EXTRA = " + (architecture == "x86" ? "1" : "2") + "U;", "First") +
                Source("public const uint EXTRA = 7U;", "Second") +
                Source("public const uint EXTRA = 8U;", "Outer.Nested")), fields =>
            {
                Assert.AreEqual(4, fields.Length);
                Assert.IsTrue(fields.All(field => field.Name == "EXTRA"));
                var first = fields.Where(field => field.Namespace == "First").OrderBy(field => field.Architectures).ToArray();
                CollectionAssert.AreEqual(new int?[] { 1, 6 }, first.Select(field => field.Architectures).ToArray());
                CollectionAssert.AreEqual(new[] { "01000000", "02000000" }, first.Select(field => field.ValueBits).ToArray());
                foreach (var (ns, bits) in new[] { ("Second", "07000000"), ("Outer.Nested", "08000000") })
                {
                    var field = fields.Single(field => field.Namespace == ns);
                    Assert.IsNull(field.Architectures);
                    Assert.AreEqual(bits, field.ValueBits);
                }
            });
        }

        [TestMethod]
        public void PhysicalStaticConstantAttributesRemainArchitectureSpecific()
        {
            Emit(Architectures.ToDictionary(architecture => architecture, architecture => Source(
                "[Constant(\"" + (architecture == "x86" ? "1" : "2") + "\")] public static uint EXTRA;")), fields =>
            {
                Assert.AreEqual(2, fields.Length);
                var extras = fields.OrderBy(field => field.Architectures).ToArray();
                CollectionAssert.AreEqual(new int?[] { 1, 6 }, extras.Select(field => field.Architectures).ToArray());
                CollectionAssert.AreEqual(new[] { "1", "2" }, extras.Select(field => field.ConstantExpression).ToArray());
                foreach (var field in extras)
                {
                    Assert.AreEqual("EXTRA", field.Name);
                    Assert.AreEqual("0609", field.Signature);
                    Assert.AreEqual(FieldAttributes.Public | FieldAttributes.Static, field.Attributes);
                    Assert.IsNull(field.ConstantType);
                    Assert.IsNull(field.ValueBits);
                }
            });
        }

        [TestMethod]
        public void FieldSignaturesIgnoreTransportAndTriviaButNotPhysicalFacts()
        {
            var map = new CrossArchSyntaxMap();
            var trees = Architectures.Select(architecture => CSharpSyntaxTree.ParseText(Source(
                architecture == "x86"
                    ? "[NativeTypeName(\"#define EXTRA 1U\")] public const uint EXTRA = 1U;"
                    : "[NativeTypeName(\"#define EXTRA (1U)\")]\npublic  const  uint EXTRA=1U;"),
                path: Path.Combine("fixtures", architecture, "Bindings.header-types.cs"))).ToArray();
            foreach (var tree in trees)
                map.AddTree(tree);
            var node = trees[0].GetRoot().DescendantNodes().OfType<FieldDeclarationSyntax>().Single();
            CollectionAssert.AreEqual(new[] { Architecture.All }, map.GetSignatureArchGroupings(node).ToArray());
            var merger = new CrossArchTreeMerger(map);
            var merged = trees.Select(tree => merger.ProcessTree(tree, out _)).ToArray();
            Assert.AreEqual(1, merged.SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<FieldDeclarationSyntax>()).Count());
        }

        [TestMethod]
        public void ThreeDistinctValuesKeepOnePhysicalNameWithThreeMasks()
        {
            Emit(Architectures.Select((architecture, index) => (architecture, index))
                .ToDictionary(item => item.architecture, item => Source($"public const uint EXTRA = {item.index + 1}U;")), fields =>
            {
                Assert.AreEqual(3, fields.Length);
                Assert.IsTrue(fields.All(field => field.Name == "EXTRA"));
                var extras = fields.OrderBy(field => field.Architectures).ToArray();
                CollectionAssert.AreEqual(new int?[] { 1, 2, 4 }, extras.Select(field => field.Architectures).ToArray());
                CollectionAssert.AreEqual(new[] { "01000000", "02000000", "03000000" },
                    extras.Select(field => field.ValueBits).ToArray());
            });
        }

        [TestMethod]
        public void PhysicalFieldArchitectureAttributesAreNotShadowedByLocalWindowsTypes()
        {
            Emit(Architectures.ToDictionary(architecture => architecture, architecture =>
                Source("public const uint EXTRA = " + (architecture == "x86" ? "1" : "2") + "U;") +
                (architecture == "x86" ? "namespace Test { public class Windows { } }" : "")), fields =>
            {
                Assert.AreEqual(2, fields.Length);
                Assert.IsTrue(fields.All(field => field.Name == "EXTRA"));
                CollectionAssert.AreEquivalent(new int?[] { 1, 6 }, fields.Select(field => field.Architectures).ToArray());
            });
        }

        private static string Source(string declarations, string ns = "Test")
            => $"namespace {ns} {{ public static partial class Apis {{ {declarations} }} }}";

        private static void AssertInvariant(ObservedField[] fields)
        {
            var always = fields.Single(field => field.Name == "ALWAYS");
            Assert.IsNull(always.Architectures);
            Assert.AreEqual("00000000", always.ValueBits);
            Assert.AreEqual("0609", always.Signature);
        }

        private static void Emit(Dictionary<string, string> inputs, Action<ObservedField[]> assert,
            Dictionary<string, string>? requiredNamespaces = null, Action<FileInfo>? inspectImage = null)
        {
            string? artifacts = Environment.GetEnvironmentVariable("WIN32_HEADER_CONSTANT_CROSSARCH_TEST_ARTIFACTS");
            string directory = Path.Combine(artifacts ?? Path.Combine(AppContext.BaseDirectory, "header-constant-crossarch-tests"),
                Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                File.WriteAllText(Path.Combine(directory, "Metadata.manual.cs"), MetadataSource);
                foreach (var input in inputs)
                {
                    string path = input.Key.EndsWith(".cs", StringComparison.Ordinal)
                        ? Path.Combine(directory, input.Key)
                        : Path.Combine(directory, input.Key, "Bindings.header-types.cs");
                    Directory.CreateDirectory(Path.GetDirectoryName(path)!);
                    File.WriteAllText(path, "using Windows.Win32.Foundation.Metadata;\n" + input.Value);
                }
                var compilation = ClangSharpSourceCompilation.Create(directory, "crossarch",
                    new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(),
                    Array.Empty<string>(), new Dictionary<string, string>(), requiredNamespaces ?? new Dictionary<string, string>(),
                    new HashSet<string>(), Array.Empty<string>(), new Dictionary<string, string>(), new Dictionary<string, string>());
                var errors = compilation.CSharpCompilation.GetDiagnostics()
                    .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
                Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
                string image = Path.Combine(directory, "Test.winmd");
                var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation,
                    new Dictionary<string, string>(), new HashSet<string>(), new HashSet<string>(), new Version(1, 0), image);
                Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
                inspectImage?.Invoke(new FileInfo(image));
                using var stream = File.OpenRead(image);
                using var pe = new PEReader(stream);
                var reader = pe.GetMetadataReader(MetadataReaderOptions.None);
                var fields = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => reader.GetString(type.Name) == "Apis")
                    .SelectMany(type => type.GetFields().Select(reader.GetFieldDefinition).Select(field => ReadField(reader, type, field))).ToArray();
                if (artifacts != null)
                    File.WriteAllText(Path.Combine(directory, "physical.json"),
                        JsonSerializer.Serialize(fields, new JsonSerializerOptions { WriteIndented = true }));
                assert(fields);
            }
            catch (Exception error)
            {
                if (artifacts != null)
                    File.WriteAllText(Path.Combine(directory, "failure.txt"), error.ToString());
                throw;
            }
            finally
            {
                if (artifacts == null)
                    Directory.Delete(directory, true);
            }
        }

        private static ObservedField ReadField(MetadataReader reader, TypeDefinition type, FieldDefinition field)
        {
            int? architectures = null;
            string? expression = null;
            foreach (var handle in field.GetCustomAttributes())
            {
                var attribute = reader.GetCustomAttribute(handle);
                var constructor = attribute.Constructor;
                var attributeType = constructor.Kind == HandleKind.MethodDefinition
                    ? reader.GetMethodDefinition((MethodDefinitionHandle)constructor).GetDeclaringType()
                    : reader.GetMemberReference((MemberReferenceHandle)constructor).Parent;
                string name = attributeType.Kind == HandleKind.TypeDefinition
                    ? reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)attributeType).Name)
                    : reader.GetString(reader.GetTypeReference((TypeReferenceHandle)attributeType).Name);
                var blob = reader.GetBlobReader(attribute.Value);
                Assert.AreEqual(1, (int)blob.ReadUInt16());
                if (name == "SupportedArchitectureAttribute")
                {
                    Assert.IsNull(architectures);
                    architectures = blob.ReadInt32();
                }
                else if (name == "ConstantAttribute")
                    expression = blob.ReadSerializedString();
            }
            var constant = field.GetDefaultValue();
            return new ObservedField
            {
                Namespace = reader.GetString(type.Namespace),
                Name = reader.GetString(field.Name),
                Signature = Convert.ToHexString(reader.GetBlobBytes(field.Signature)),
                Attributes = field.Attributes,
                ConstantType = constant.IsNil ? null : reader.GetConstant(constant).TypeCode,
                ValueBits = constant.IsNil ? null : Convert.ToHexString(reader.GetBlobBytes(reader.GetConstant(constant).Value)),
                Architectures = architectures,
                ConstantExpression = expression,
            };
        }

        private sealed class ObservedField
        {
            public string Namespace { get; init; } = "";
            public string Name { get; init; } = "";
            public string Signature { get; init; } = "";
            public FieldAttributes Attributes { get; init; }
            public ConstantTypeCode? ConstantType { get; init; }
            public string? ValueBits { get; init; }
            public int? Architectures { get; init; }
            public string? ConstantExpression { get; init; }
        }
    }
}

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class HeaderEnumCompositionTests
    {
        [DataTestMethod]
        [DataRow("Windows.Win32.Graphics.Gdi", "RGN_COMBINE_MODE", "int",
            "RGN_AND=1,RGN_OR=2,RGN_XOR=3,RGN_DIFF=4,RGN_COPY=5,RGN_MIN=1,RGN_MAX=5",
            "RGN_AND=1,RGN_OR=2,RGN_XOR=3,RGN_DIFF=4,RGN_COPY=5,RGN_MIN=RGN_AND,RGN_MAX=RGN_COPY", 7)]
        [DataRow("Windows.Win32.Security.Cryptography.UI", "CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT", "uint",
            "CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_BLOB=2,CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_FILE=1,CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_NONE=0",
            "CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_NONE=0", 3)]
        [DataRow("Windows.Win32.Security.Cryptography.UI", "CRYPTUI_WIZ_DIGITAL_SIGN", "uint",
            "CRYPTUI_WIZ_DIGITAL_SIGN_CERT=1,CRYPTUI_WIZ_DIGITAL_SIGN_STORE=2,CRYPTUI_WIZ_DIGITAL_SIGN_PVK=3,CRYPTUI_WIZ_DIGITAL_SIGN_NONE=0",
            "CRYPTUI_WIZ_DIGITAL_SIGN_NONE=0", 4)]
        [DataRow("Windows.Win32.Security.Cryptography.UI", "CRYPTUI_WIZ_DIGITAL_ADDITIONAL_CERT_CHOICE", "uint",
            "CRYPTUI_WIZ_DIGITAL_SIGN_ADD_CHAIN=1,CRYPTUI_WIZ_DIGITAL_SIGN_ADD_CHAIN_NO_ROOT=2,CRYPTUI_WIZ_DIGITAL_SIGN_ADD_NONE=0",
            "CRYPTUI_WIZ_DIGITAL_SIGN_ADD_NONE=0", 3)]
        public void CapturedDefinitionsComposeWithoutLosingLegacyConsumers(
            string ns, string name, string storage, string nativeMembers, string legacyMembers, int count)
        {
            foreach (string arch in new[] { "x86", "x64", "arm64", "crossarch" })
            {
                var expected = nativeMembers.Split(',').Select(member => member.Split('=')).ToArray();
                string headerMembers = string.Join(",", expected.Select(member =>
                    $"{member[0]}=unchecked(({storage}){member[1]}UL)"));
                string legacyStorage = storage == "int" ? string.Empty : $": {storage}";
                Compile(new Dictionary<string, string>
                {
                    ["provider.header-types.cs"] = $"namespace {ns} {{ public enum {name}: {storage} {{ {headerMembers} }} }}",
                    ["legacy.manual.cs"] = $"namespace {ns} {{ public enum {name}{legacyStorage} {{ {legacyMembers} }} }}",
                    ["consumer.cs"] = $"namespace {ns} {{ public struct Consumer {{ public {name} value; }} }}",
                }, compilation =>
                {
                    AssertCompiles(compilation);
                    var type = compilation.GetTypeByMetadataName($"{ns}.{name}");
                    Assert.IsNotNull(type);
                    var members = type!.GetMembers().OfType<IFieldSymbol>().Where(field => field.HasConstantValue).ToArray();
                    Assert.AreEqual(count, members.Length);
                    CollectionAssert.AreEqual(expected.Select(member => member[0]).ToArray(),
                        members.Select(member => member.Name).ToArray());
                    CollectionAssert.AreEqual(expected.Select(member => long.Parse(member[1])).ToArray(),
                        members.Select(member => Convert.ToInt64(member.ConstantValue)).ToArray());
                    Assert.AreEqual(storage == "int" ? SpecialType.System_Int32 : SpecialType.System_UInt32,
                        type.EnumUnderlyingType!.SpecialType);
                    var consumer = compilation.GetTypeByMetadataName($"{ns}.Consumer")!;
                    Assert.IsTrue(SymbolEqualityComparer.Default.Equals(type,
                        consumer.GetMembers("value").OfType<IFieldSymbol>().Single().Type));
                }, arch);
            }
        }

        [TestMethod]
        public void NativeFragmentsAndRetainedLegacyMembersKeepFlagsValuesAndBindings()
        {
            Compile(new Dictionary<string, string>
            {
                ["first.header-types.cs"] = "namespace Test { [global::System.Flags] public enum G:uint { A=unchecked((uint)1UL) } }",
                ["second.header-types.cs"] = "namespace Test { [global::System.Flags] public enum G:uint { B=unchecked((uint)2UL) } }",
                ["legacy.enums.cs"] = "using System; namespace Test { [Flags] public enum G:uint { A=1, Retained=4 } }",
                ["consumer.cs"] = "namespace Test { public struct Consumer { public G value; } public static class Apis { public const uint Alias=(uint)G.Retained; } }",
            }, compilation =>
            {
                AssertCompiles(compilation);
                var type = compilation.GetTypeByMetadataName("Test.G")!;
                CollectionAssert.AreEqual(new[] { "A", "B", "Retained" },
                    type.GetMembers().OfType<IFieldSymbol>().Where(field => field.HasConstantValue).Select(field => field.Name).ToArray());
                Assert.AreEqual(1, type.GetAttributes().Count(attribute =>
                    attribute.AttributeClass?.ToDisplayString() == "System.FlagsAttribute"));
                Assert.AreEqual(4U, compilation.GetTypeByMetadataName("Test.Apis")!
                    .GetMembers("Alias").OfType<IFieldSymbol>().Single().ConstantValue);
            });
        }

        [DataTestMethod]
        [DataRow("int", "", "A=1", "storage")]
        [DataRow("uint", "[System.Flags]", "A=1", "flags")]
        [DataRow("uint", "", "A=2", "values")]
        [DataRow("uint", "", "A=Missing", "could not be evaluated")]
        [DataRow("uint", "", "A=4294967296UL", "could not be evaluated")]
        public void ConflictingLegacyDefinitionsAreRejected(
            string storage, string attributes, string members, string expected)
        {
            var exception = Assert.ThrowsException<InvalidOperationException>(() => Compile(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = "namespace Test { public enum G:uint { A=unchecked((uint)1UL) } }",
                ["legacy.enums.cs"] = $"namespace Test {{ {attributes} public enum G:{storage} {{ {members} }} }}",
            }, _ => Assert.Fail("Conflicting definitions must not reach compilation.")));
            StringAssert.Contains(exception.Message, "WMA003");
            StringAssert.Contains(exception.Message, expected);
        }

        [DataTestMethod]
        [DataRow("sbyte", "18446744073709551615", "-1")]
        [DataRow("long", "18446744073709551615", "-1")]
        [DataRow("uint", "4294967295", "4294967295U")]
        [DataRow("ulong", "18446744073709551615", "18446744073709551615UL")]
        public void SignedLargeAndQualifiedLegacyAliasesRetainTheirCompiledValues(string storage, string bits, string value)
        {
            Compile(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = $"namespace Test {{ public enum G:{storage} {{ A=unchecked(({storage}){bits}UL), Alias=unchecked(({storage}){bits}UL) }} }}",
                ["legacy.enums.cs"] = $"namespace Test {{ public enum G:{storage} {{ A={value}, Alias=global::Test.G.A }} }}",
            }, compilation =>
            {
                AssertCompiles(compilation);
                var members = compilation.GetTypeByMetadataName("Test.G")!.GetMembers().OfType<IFieldSymbol>()
                    .Where(field => field.HasConstantValue).ToArray();
                Assert.AreEqual(2, members.Length);
                Assert.AreEqual(members[0].ConstantValue, members[1].ConstantValue);
                Assert.AreEqual(value.TrimEnd('U', 'L'), Convert.ToString(members[0].ConstantValue));
            });
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void ConflictingDeclarationAndMemberAnnotationsAreRejected(bool onMember)
        {
            string header = "[System.Obsolete(\"native\")]";
            string legacy = "[System.Obsolete(\"legacy\")]";
            var exception = Assert.ThrowsException<InvalidOperationException>(() => Compile(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = $"namespace Test {{ {(onMember ? "" : header)} public enum G:uint {{ {(onMember ? header : "")} A=unchecked((uint)1UL) }} }}",
                ["legacy.enums.cs"] = $"namespace Test {{ {(onMember ? "" : legacy)} public enum G:uint {{ {(onMember ? legacy : "")} A=1 }} }}",
            }, _ => Assert.Fail("Conflicting annotations must not be dropped during composition.")));
            StringAssert.Contains(exception.Message, "WMA003");
            StringAssert.Contains(exception.Message, onMember ? "Conflicting logical group values" : "Conflicting 'System.Obsolete' annotations");
        }

        [TestMethod]
        public void AShadowedFlagsAttributeIsNotReplacedWithSystemFlags()
        {
            var exception = Assert.ThrowsException<InvalidOperationException>(() => Compile(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = "namespace Test { [global::System.Flags] public enum G:uint { A=unchecked((uint)1UL) } }",
                ["legacy.enums.cs"] = "namespace Test { public class FlagsAttribute:System.Attribute { } [Flags] public enum G:uint { A=1 } }",
            }, _ => Assert.Fail("An unrelated Flags attribute must not be normalized into System.FlagsAttribute.")));
            StringAssert.Contains(exception.Message, "must resolve to System.FlagsAttribute");
        }

        [TestMethod]
        public void NamespaceIdentityAndNonHeaderDuplicatesAreNotNormalizedAway()
        {
            Compile(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = "namespace Native { public enum G:uint { A=unchecked((uint)1UL) } }",
                ["legacy.enums.cs"] = "namespace Legacy { public enum G:uint { A=2 } }",
                ["consumer.cs"] = "namespace Test { public struct Consumer { public Legacy.G value; } }",
            }, compilation =>
            {
                AssertCompiles(compilation);
                Assert.IsNotNull(compilation.GetTypeByMetadataName("Native.G"));
                var legacy = compilation.GetTypeByMetadataName("Legacy.G")!;
                Assert.AreEqual(2U, legacy.GetMembers("A").OfType<IFieldSymbol>().Single().ConstantValue);
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(legacy, compilation.GetTypeByMetadataName("Test.Consumer")!
                    .GetMembers("value").OfType<IFieldSymbol>().Single().Type));
            });
            Compile(new Dictionary<string, string>
            {
                ["first.enums.cs"] = "namespace Test { public enum G:uint { A=1 } }",
                ["second.enums.cs"] = "namespace Test { public enum G:uint { A=1 } }",
            }, compilation => Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0101")));
        }

        [TestMethod]
        public void DistinctNativeDeclarationsInOneTranslationUnitRemainAnError()
        {
            var exception = Assert.ThrowsException<InvalidOperationException>(() => Compile(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = "namespace Test { public enum G:uint { A=unchecked((uint)1UL) } public enum G:uint { A=unchecked((uint)1UL) } }",
            }, _ => Assert.Fail("Distinct native declarations must not be silently coalesced.")));
            StringAssert.Contains(exception.Message, "one translation unit");
        }

        private static void AssertCompiles(CSharpCompilation compilation)
        {
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
        }

        private static void Compile(Dictionary<string, string> inputs, Action<CSharpCompilation> assert, string arch = "crossarch")
        {
            string directory = Path.Combine(Path.GetTempPath(), "header-enum-composition-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                File.WriteAllText(Path.Combine(directory, "metadata.cs"), "namespace Windows.Win32.Foundation.Metadata { public class Fixture { } }");
                foreach (var input in inputs)
                    File.WriteAllText(Path.Combine(directory, input.Key), input.Value);
                var compilation = ClangSharpSourceCompilation.Create(directory, arch,
                    new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(),
                    Array.Empty<string>(), new Dictionary<string, string>(), new Dictionary<string, string>(),
                    new HashSet<string>(), Array.Empty<string>(), new Dictionary<string, string>(), new Dictionary<string, string>());
                assert(compilation.CSharpCompilation);
                foreach (var input in inputs)
                    Assert.AreEqual(input.Value, File.ReadAllText(Path.Combine(directory, input.Key)));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }
    }
}

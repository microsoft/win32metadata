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
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        [DataRow("crossarch")]
        public void CapturedWinsockAliasesKeepTheirUsingStaticConstantContext(string architecture)
        {
            string[] names =
            {
                "WSA_IO_PENDING", "WSA_IO_INCOMPLETE", "WSA_INVALID_HANDLE", "WSA_INVALID_PARAMETER",
                "WSA_NOT_ENOUGH_MEMORY", "WSA_OPERATION_ABORTED", "WSA_WAIT_EVENT_0", "WSA_WAIT_IO_COMPLETION",
            };
            int[] values = { 997, 996, 6, 87, 8, 995, 0, 192 };
            Compile(new Dictionary<string, string>
            {
                ["Foundation.header-types.cs"] = @"
namespace Windows.Win32.Foundation
{
    public enum WIN32_ERROR:uint
    {
        ERROR_IO_PENDING=unchecked((uint)997UL), ERROR_IO_INCOMPLETE=unchecked((uint)996UL),
        ERROR_INVALID_HANDLE=unchecked((uint)6UL), ERROR_INVALID_PARAMETER=unchecked((uint)87UL),
        ERROR_NOT_ENOUGH_MEMORY=unchecked((uint)8UL), ERROR_OPERATION_ABORTED=unchecked((uint)995UL)
    }
    public enum WAIT_EVENT:uint
    {
        WAIT_OBJECT_0=unchecked((uint)0UL), WAIT_IO_COMPLETION=unchecked((uint)192UL)
    }
    public enum WSA_ERROR:int
    {
        WSA_IO_PENDING=unchecked((int)997UL), WSA_IO_INCOMPLETE=unchecked((int)996UL),
        WSA_INVALID_HANDLE=unchecked((int)6UL), WSA_INVALID_PARAMETER=unchecked((int)87UL),
        WSA_NOT_ENOUGH_MEMORY=unchecked((int)8UL), WSA_OPERATION_ABORTED=unchecked((int)995UL),
        WSA_WAIT_EVENT_0=unchecked((int)0UL), WSA_WAIT_IO_COMPLETION=unchecked((int)192UL)
    }
}",
                ["System.SystemServices.enums.cs"] = @"
using static Windows.Win32.Foundation.Apis;
using static Windows.Win32.Foundation.WAIT_EVENT;
using static Windows.Win32.Foundation.WIN32_ERROR;
namespace Windows.Win32.Foundation
{
    public enum WSA_ERROR
    {
        WSA_IO_PENDING=(int)ERROR_IO_PENDING, WSA_IO_INCOMPLETE=(int)ERROR_IO_INCOMPLETE,
        WSA_INVALID_HANDLE=(int)ERROR_INVALID_HANDLE, WSA_INVALID_PARAMETER=(int)ERROR_INVALID_PARAMETER,
        WSA_NOT_ENOUGH_MEMORY=(int)ERROR_NOT_ENOUGH_MEMORY, WSA_OPERATION_ABORTED=(int)ERROR_OPERATION_ABORTED,
        WSA_WAIT_EVENT_0=(int)WAIT_OBJECT_0, WSA_WAIT_IO_COMPLETION=(int)WAIT_IO_COMPLETION
    }
}",
                ["Foundation.constants.cs"] = @"
namespace Windows.Win32.Foundation
{
    public static partial class Apis
    {
        public const uint ERROR_IO_PENDING=997, ERROR_IO_INCOMPLETE=996, ERROR_INVALID_HANDLE=6,
            ERROR_INVALID_PARAMETER=87, ERROR_NOT_ENOUGH_MEMORY=8, ERROR_OPERATION_ABORTED=995;
        public const uint WAIT_OBJECT_0=0, WAIT_IO_COMPLETION=192;
    }
}",
            }, compilation =>
            {
                AssertCompiles(compilation);
                var type = compilation.GetTypeByMetadataName("Windows.Win32.Foundation.WSA_ERROR")!;
                Assert.AreEqual(SpecialType.System_Int32, type.EnumUnderlyingType!.SpecialType);
                var members = type.GetMembers().OfType<IFieldSymbol>().Where(field => field.HasConstantValue).ToArray();
                CollectionAssert.AreEqual(names, members.Select(member => member.Name).ToArray());
                CollectionAssert.AreEqual(values, members.Select(member => (int)member.ConstantValue!).ToArray());
            }, architecture);
        }

        [DataTestMethod]
        [DataRow("using static Support.Apis;", "VALUE")]
        [DataRow("using Alias = Support.Apis;", "Alias.VALUE")]
        [DataRow("", "global::Support.Apis.VALUE")]
        public void LegacyValuesRetainExternalConstantsAliasChainsAndImplicitIncrements(string imports, string expression)
        {
            Compile(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = "namespace Test { public enum G:uint { A=unchecked((uint)7UL) } }",
                ["legacy.enums.cs"] = $"{imports} namespace Test {{ public enum G:uint {{ A={expression}, Retained=({expression})+1, Next }} }}",
                ["constants.cs"] = "namespace Support { public static partial class Apis { public const uint VALUE=BASE+3; public const uint BASE=4; } }",
            }, compilation =>
            {
                AssertCompiles(compilation);
                var members = compilation.GetTypeByMetadataName("Test.G")!.GetMembers().OfType<IFieldSymbol>()
                    .Where(field => field.HasConstantValue).ToArray();
                CollectionAssert.AreEqual(new[] { 7U, 8U, 9U }, members.Select(member => (uint)member.ConstantValue!).ToArray());
            });
        }

        [TestMethod]
        public void LegacyValuesUseOnlyTheCurrentArchitecturesConstantProviders()
        {
            var inputs = new Dictionary<string, string>
            {
                ["legacy.enums.cs"] = "using static Test.Apis; namespace Test { public enum G:uint { A=VALUE } }",
            };
            string[] architectures = { "x86", "x64", "arm64" };
            for (int i = 0; i < architectures.Length; i++)
            {
                inputs[Path.Combine(architectures[i], "provider.header-types.cs")] =
                    $"namespace Test {{ public enum G:uint {{ A=unchecked((uint){i + 1}UL) }} }}";
                inputs[Path.Combine(architectures[i], "constants.cs")] =
                    $"namespace Test {{ public static partial class Apis {{ public const uint VALUE={i + 1}; }} }}";
            }
            Compile(inputs, compilation =>
            {
                AssertCompiles(compilation);
                var groups = compilation.GlobalNamespace.GetNamespaceMembers().Single(ns => ns.Name == "Test")
                    .GetTypeMembers().Where(type => type.TypeKind == TypeKind.Enum).ToArray();
                Assert.AreEqual(3, groups.Length);
                foreach (var group in groups)
                {
                    uint value = (uint)group.GetMembers("A").OfType<IFieldSymbol>().Single().ConstantValue!;
                    var attribute = group.GetAttributes().Single(attribute =>
                        attribute.AttributeClass?.Name == "SupportedArchitectureAttribute");
                    Assert.AreEqual(1 << ((int)value - 1), attribute.ConstructorArguments.Single().Value);
                }
            });
        }

        [TestMethod]
        public void LegacyValuesCanReferenceAnotherComposedLogicalGroup()
        {
            Compile(new Dictionary<string, string>
            {
                ["first.header-types.cs"] = "namespace Test { public enum G:uint { A=unchecked((uint)7UL), Extra=unchecked((uint)8UL) } }",
                ["second.header-types.cs"] = "namespace Test { public enum H:uint { B=unchecked((uint)7UL) } }",
                ["first.enums.cs"] = "namespace Test { public enum G:uint { A=(uint)H.B, Extra=(uint)H.Retained } }",
                ["second.enums.cs"] = "namespace Test { public enum H:uint { B=7, Retained=8 } }",
            }, compilation =>
            {
                AssertCompiles(compilation);
                var members = compilation.GetTypeByMetadataName("Test.G")!.GetMembers().OfType<IFieldSymbol>()
                    .Where(field => field.HasConstantValue).ToArray();
                CollectionAssert.AreEqual(new[] { 7U, 8U }, members.Select(member => (uint)member.ConstantValue!).ToArray());
            });
        }

        [DataTestMethod]
        [DataRow("Missing")]
        [DataRow("4294967296UL")]
        [DataRow("VALUE")]
        public void InvalidExternalConstantDependenciesCannotProduceMergedValues(string expression)
        {
            var exception = Assert.ThrowsException<InvalidOperationException>(() => Compile(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = "namespace Test { public enum G:uint { A=unchecked((uint)1UL) } }",
                ["legacy.enums.cs"] = "using static Support.Apis; namespace Test { public enum G:uint { A=VALUE } }",
                ["constants.cs"] = $"namespace Support {{ public static partial class Apis {{ public const uint VALUE={expression}; }} }}",
            }, _ => Assert.Fail("Invalid dependencies must not produce a successful composition.")));
            StringAssert.Contains(exception.Message, "WMA003");
        }

        [TestMethod]
        public void UnrelatedSourceErrorsRemainVisibleAfterEvaluatingValidLegacyValues()
        {
            Compile(new Dictionary<string, string>
            {
                ["provider.header-types.cs"] = "namespace Test { public enum G:uint { A=unchecked((uint)7UL) } }",
                ["legacy.enums.cs"] = "using static Support.Apis; namespace Test { public enum G:uint { A=VALUE } }",
                ["constants.cs"] = "namespace Support { public static partial class Apis { public const uint VALUE=7; public static Missing Broken; } }",
            }, compilation => Assert.IsTrue(compilation.GetDiagnostics()
                .Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error && diagnostic.Id == "CS0246")));
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
                File.WriteAllText(Path.Combine(directory, "metadata.cs"), @"
namespace Windows.Win32.Foundation.Metadata
{
    public class Fixture { }
    [System.Flags] public enum Architecture { X86=1, X64=2, Arm64=4 }
    [System.AttributeUsage(System.AttributeTargets.All)]
    public class SupportedArchitectureAttribute:System.Attribute
    {
        public SupportedArchitectureAttribute(Architecture architecture) { }
    }
}");
                foreach (var input in inputs)
                {
                    Directory.CreateDirectory(Path.GetDirectoryName(Path.Combine(directory, input.Key))!);
                    File.WriteAllText(Path.Combine(directory, input.Key), input.Value);
                }
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

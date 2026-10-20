using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class HeaderAnnotationPipelineTests
    {
        [DataTestMethod]
        [DataRow("Optional", true, false)]
        [DataRow("Optional", true, true)]
        [DataRow("Optional", false, false)]
        [DataRow("Optional", false, true)]
        [DataRow("ComOutPtr", true, false)]
        [DataRow("ComOutPtr", true, true)]
        [DataRow("ComOutPtr", false, false)]
        [DataRow("ComOutPtr", false, true)]
        public void ParameterOverridesApplyAfterNativeAttributesWithoutChangingOtherFacts(
            string name, bool enabled, bool alreadyPresent)
        {
            string existing = alreadyPresent ? $"[{name}]" : "";
            var tree = Clean($@"
namespace Test {{ public unsafe delegate int F(
    [NativeAnnotation(""Win32Metadata.{name}({enabled.ToString().ToLowerInvariant()})"")]
    {existing}
    [In, Out, NativeArrayInfo(CountParamIndex = 1), Other.Optional, Other.ComOutPtr]
    void** value, uint count); }}");
            var parameter = tree.GetRoot().DescendantNodes().OfType<ParameterSyntax>().First();
            var actual = parameter.AttributeLists.SelectMany(list => list.Attributes).ToArray();
            Assert.AreEqual(enabled ? 1 : 0, actual.Count(attribute =>
                attribute.Name.ToString() == name || attribute.Name.ToString().EndsWith("." + name) &&
                !attribute.Name.ToString().StartsWith("Other.", StringComparison.Ordinal)));
            foreach (string retained in new[] { "In", "Out", "NativeArrayInfo", "Other.Optional", "Other.ComOutPtr" })
                Assert.IsTrue(actual.Any(attribute => attribute.Name.ToString() == retained));
            Assert.AreEqual("void**", parameter.Type?.ToString());
            Assert.IsFalse(actual.Any(attribute => attribute.Name.ToString() == "NativeAnnotation"));
            Assert.AreEqual(tree.GetRoot().ToFullString(), Clean(tree.GetRoot().ToFullString()).GetRoot().ToFullString());
        }

        [TestMethod]
        public void ParameterOverridesComposeWithDerivedSalInsteadOfReplacingIt()
        {
            var tree = Clean(@"
namespace Test { public unsafe delegate int F(
    [CppAttributeList(""Name=SAL_name;p1=\""_In_opt_\""^Name=SAL_pre^Name=SAL_valid"")]
    [NativeAnnotation(""Win32Metadata.Optional(false)"")] uint scalar,
    [CppAttributeList(""Name=SAL_name;p1=\""_Outptr_\""^Name=SAL_post^Name=SAL_valid"")]
    [NativeAnnotation(""Win32Metadata.ComOutPtr(true)"")] void** result); }");
            var parameters = tree.GetRoot().DescendantNodes().OfType<ParameterSyntax>().ToArray();
            CollectionAssert.AreEqual(new[] { "In" }, parameters[0].AttributeLists.SelectMany(list => list.Attributes)
                .Select(attribute => attribute.Name.ToString()).ToArray());
            CollectionAssert.AreEquivalent(new[] { "Out", "global::Windows.Win32.Foundation.Metadata.ComOutPtr" },
                parameters[1].AttributeLists.SelectMany(list => list.Attributes).Select(attribute => attribute.Name.ToString()).ToArray());
        }

        [TestMethod]
        public void RemovingComOutPtrPreservesItsImplicitPhysicalOutFlag()
        {
            var tree = Clean(@"
namespace Test { public unsafe delegate int F(
    [ComOutPtr, NativeAnnotation(""Win32Metadata.ComOutPtr(false)"")] void** value); }");
            var attributes = tree.GetRoot().DescendantNodes().OfType<ParameterSyntax>().Single()
                .AttributeLists.SelectMany(list => list.Attributes).ToArray();
            Assert.AreEqual(1, attributes.Length);
            Assert.AreEqual("global::System.Runtime.InteropServices.Out", attributes[0].Name.ToString());
        }

        [DataTestMethod]
        [DataRow("NativeAnnotation")]
        [DataRow("NativeAnnotationAttribute")]
        [DataRow("global::NativeAnnotation")]
        [DataRow("global::NativeAnnotationAttribute")]
        public void RecognizedParameterOverrideTransportCannotLeakIntoFinalSource(string attributeName)
        {
            var tree = Clean($@"namespace Test {{ public delegate void F(
                [{attributeName}(""Win32Metadata.Optional(false)"")] [Optional, In] int value); }}");
            var attributes = tree.GetRoot().DescendantNodes().OfType<ParameterSyntax>().Single()
                .AttributeLists.SelectMany(list => list.Attributes).ToArray();
            Assert.AreEqual(1, attributes.Length);
            Assert.AreEqual("In", attributes[0].Name.ToString());
        }

        [DataTestMethod]
        [DataRow("Optional", false, "[-Optional]", false)]
        [DataRow("Optional", true, "[Optional]", false)]
        [DataRow("ComOutPtr", true, "[ComOutPtr]", false)]
        [DataRow("Optional", false, "[Optional]", true)]
        [DataRow("Optional", true, "[-Optional]", true)]
        [DataRow("ComOutPtr", true, "[-ComOutPtr]", true)]
        public void ParameterOverridesDoNotPermitContradictoryLegacyRemaps(
            string name, bool enabled, string remap, bool conflict)
        {
            string source = $@"
namespace Test {{ public unsafe delegate int F(
    [NativeAnnotation(""Win32Metadata.{name}({enabled.ToString().ToLowerInvariant()})"")]
    [In, Out] void** value); }}";
            var remaps = new Dictionary<string, string> { ["F::value"] = remap };
            if (conflict)
            {
                var error = Assert.ThrowsException<InvalidOperationException>(() => Clean(source, remaps));
                StringAssert.Contains(error.Message, "WMA002");
            }
            else
            {
                var tree = Clean(source, remaps);
                var attributes = tree.GetRoot().DescendantNodes().OfType<ParameterSyntax>().Single()
                    .AttributeLists.SelectMany(list => list.Attributes).ToArray();
                Assert.AreEqual(enabled ? 3 : 2, attributes.Length);
            }
        }

        [DataTestMethod]
        [DataRow("Optional")]
        [DataRow("Optional(1)")]
        [DataRow("ComOutPtr(TRUE)")]
        [DataRow("ComOutPtr(false, true)")]
        public void MalformedParameterOverridesCannotBeSilentlyDropped(string payload)
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() =>
                Clean($@"namespace Test {{ public delegate void F([NativeAnnotation(""Win32Metadata.{payload}"")] int value); }}"));
            StringAssert.Contains(error.Message, "WMA001");
        }

        [DataTestMethod]
        [DataRow("[NativeAnnotation(\"Win32Metadata.Optional(true)\")] public int value;")]
        [DataRow("[return: NativeAnnotation(\"Win32Metadata.ComOutPtr(false)\")] public int F() => 0;")]
        [DataRow("public extern void F([NativeAnnotation(\"Win32Metadata.Optional(true)\"), NativeAnnotation(\"Win32Metadata.Optional(false)\")] int value);")]
        public void ParameterOverridesRejectWrongTargetsAndDuplicates(string declaration)
        {
            var error = Assert.ThrowsException<InvalidOperationException>(() =>
                Clean("namespace Test { public class S { " + declaration + " } }"));
            StringAssert.Contains(error.Message, "WMA001");
        }

        [TestMethod]
        public void CleanerHandlesMixedAttributeListsAndReturnTargets()
        {
            var tree = Clean(@"
namespace Test {
public static unsafe class Apis {
    [return: NativeAnnotation(""unowned""), NativeTypeName(""const wchar_t *""), global::Windows.Win32.Foundation.Metadata.RAIIFree(""Free"")]
    public static extern void* F([NativeAnnotation(""unowned""), global::Windows.Win32.Foundation.Metadata.Retained] void* value);
}}
");
            var method = tree.GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>().Single();
            Assert.IsFalse(method.AttributeLists.ToString().Contains("NativeAnnotation"));
            Assert.IsTrue(method.AttributeLists.ToString().Contains("Const"));
            Assert.IsTrue(method.AttributeLists.All(list => list.Target?.Identifier.ValueText == "return"));
            Assert.IsTrue(method.ParameterList.Parameters[0].AttributeLists.ToString().Contains("Retained"));
        }

        [DataTestMethod]
        [DataRow("[NativeTypeName(\"LPCWSTR\"), Const, In]")]
        [DataRow("[NativeTypeName(\"LPCWSTR\")] [Const] [In]")]
        [DataRow("[Const, NativeTypeName(\"LPCWSTR\"), In]")]
        [DataRow("[NativeTypeName(\"LPCWSTR\"), global::Windows.Win32.Foundation.Metadata.ConstAttribute, In]")]
        public void NativeConstInferencePreservesExplicitConst(string attributes)
        {
            var tree = Clean($"namespace Test {{ public unsafe delegate int D({attributes} ushort* value); }}");
            var parameter = tree.GetRoot().DescendantNodes().OfType<ParameterSyntax>().Single();
            var actual = parameter.AttributeLists.SelectMany(list => list.Attributes).ToArray();
            Assert.AreEqual(1, actual.Count(attribute => attribute.Name.ToString().Contains("Const")));
            Assert.IsTrue(actual.Any(attribute => attribute.Name.ToString() == "NativeTypeName"));
            Assert.IsTrue(actual.Any(attribute => attribute.Name.ToString() == "In"));
        }

        [TestMethod]
        public void MethodConstDoesNotSuppressReturnConst()
        {
            var tree = Clean(@"
namespace Test { public static unsafe class Apis {
    [Const] [return: NativeTypeName(""LPCWSTR"")]
    public static extern ushort* F();
}}");
            var method = tree.GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>().Single();
            Assert.AreEqual(1, method.AttributeLists.Where(list => list.Target?.Identifier.ValueText == "return")
                .SelectMany(list => list.Attributes).Count(attribute => attribute.Name.ToString() == "Const"));
            Assert.AreEqual(1, method.AttributeLists.Where(list => list.Target == null)
                .SelectMany(list => list.Attributes).Count(attribute => attribute.Name.ToString() == "Const"));
        }

        [DataTestMethod]
        [DataRow("[RetVal]")]
        [DataRow("[RetValAttribute]")]
        [DataRow("[Windows.Win32.Foundation.Metadata.RetVal]")]
        [DataRow("[Windows.Win32.Foundation.Metadata.RetValAttribute]")]
        [DataRow("[global::Windows.Win32.Foundation.Metadata.RetVal]")]
        [DataRow("[global::Windows.Win32.Foundation.Metadata.RetValAttribute]")]
        [DataRow("[Optional, global::Windows.Win32.Foundation.Metadata.RetValAttribute]")]
        [DataRow("[param: global::Windows.Win32.Foundation.Metadata.RetValAttribute]")]
        public void SalRetvalDoesNotDuplicateExistingRetval(string attributes)
        {
            var tree = Clean($@"
namespace Test {{ public unsafe delegate int D(
    [CppAttributeList(""Name=SAL_post^Name=SAL_valid^Name=SAL_retval"")]
    {attributes} int* value); }}");
            var actual = tree.GetRoot().DescendantNodes().OfType<ParameterSyntax>().Single()
                .AttributeLists.SelectMany(list => list.Attributes).ToArray();
            Assert.AreEqual(1, actual.Count(attribute => attribute.Name.ToString().Contains("RetVal")));
            Assert.IsTrue(actual.Any(attribute => attribute.Name.ToString() == "Out"));
            Assert.IsFalse(actual.Any(attribute => attribute.Name.ToString() == "CppAttributeList"));
            if (attributes.Contains("Optional"))
                Assert.IsTrue(actual.Any(attribute => attribute.Name.ToString() == "Optional"));
        }

        [TestMethod]
        public void SalRetvalStillAddsMissingRetval()
        {
            var tree = Clean(@"
namespace Test { public unsafe delegate int D(
    [CppAttributeList(""Name=SAL_post^Name=SAL_valid^Name=SAL_retval^Name=SAL_retval"")] int* value); }");
            var actual = tree.GetRoot().DescendantNodes().OfType<ParameterSyntax>().Single()
                .AttributeLists.SelectMany(list => list.Attributes).ToArray();
            CollectionAssert.AreEquivalent(new[] { "Out", "RetVal" },
                actual.Select(attribute => attribute.Name.ToString()).ToArray());
        }

        [TestMethod]
        public void SalRetvalDoesNotEraseAuthoredDuplicates()
        {
            var tree = Clean(@"
namespace Test { public unsafe delegate int D(
    [RetVal, global::Windows.Win32.Foundation.Metadata.RetValAttribute]
    [CppAttributeList(""Name=SAL_post^Name=SAL_valid^Name=SAL_retval"")] int* value); }");
            var actual = tree.GetRoot().DescendantNodes().OfType<ParameterSyntax>().Single()
                .AttributeLists.SelectMany(list => list.Attributes).ToArray();
            Assert.AreEqual(2, actual.Count(attribute => attribute.Name.ToString().Contains("RetVal")));
            Assert.IsTrue(actual.Any(attribute => attribute.Name.ToString() == "Out"));
        }

        [TestMethod]
        public void HeaderAndIdenticalLegacyFactsAreDeduplicated()
        {
            var tree = Clean(HeaderReturn, new Dictionary<string, string>
            {
                ["F::return"] = "[RAIIFreeAttribute(\"Free\")] [InvalidHandleValue(0)]",
            });
            var method = tree.GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>().Single();
            Assert.AreEqual(1, method.AttributeLists.SelectMany(list => list.Attributes).Count(attribute => attribute.Name.ToString().Contains("RAIIFree")));
            Assert.AreEqual(2, method.AttributeLists.SelectMany(list => list.Attributes).Count(attribute => attribute.Name.ToString().Contains("InvalidHandleValue")));
        }

        [DataTestMethod]
        [DataRow("[SupportedOSPlatform(\"windows5.0\")] [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\")]")]
        [DataRow("[global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\"), SupportedOSPlatform(\"windows5.0\")]")]
        [DataRow("[SupportedOSPlatformAttribute(\"windows5.0\"), global::Windows.Win32.Foundation.Metadata.SupportedOSPlatformAttribute(\"windows5.0\")]")]
        [DataRow("[Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\")] [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\")]")]
        [DataRow("[Windows.Win32.Foundation.Metadata.SupportedOSPlatformAttribute(\"windows5.0\")] [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatformAttribute(\"windows5.0\")]")]
        [DataRow("[SupportedOSPlatform(@\"windows5.0\")] [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\")]")]
        [DataRow("[SupportedOSPlatform(\"\\u0077indows5.0\")] [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\")]")]
        public void IdenticalProducerAndLegacyAvailabilityAliasesAreDeduplicated(string attributes)
        {
            var tree = Clean($@"
namespace Test {{ public abstract class Apis {{
    {attributes} [Obsolete(""keep"")]
    public abstract int F();
}} }}");
            var method = tree.GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>().Single();
            var actual = method.AttributeLists.SelectMany(list => list.Attributes).ToArray();
            Assert.AreEqual(1, actual.Count(attribute => attribute.Name.ToString().Contains("SupportedOSPlatform")));
            Assert.IsTrue(actual.Any(attribute => attribute.Name.ToString().StartsWith("global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform", StringComparison.Ordinal)));
            Assert.IsTrue(actual.Any(attribute => attribute.Name.ToString() == "Obsolete"));
            Assert.AreEqual(tree.GetRoot().ToFullString(), Clean(tree.GetRoot().ToFullString()).GetRoot().ToFullString());
        }

        [DataTestMethod]
        [DataRow("[SupportedOSPlatform(\"windows6.0\")] [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\")]")]
        [DataRow("[SupportedOSPlatform(\"windows5.00\")] [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\")]")]
        [DataRow("[Other.SupportedOSPlatform(\"windows5.0\")] [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\")]")]
        [DataRow("[SupportedOSPlatform(\"windows5.0\")] [global::Windows.Win32.Foundation.Metadata.Other.SupportedOSPlatform(\"windows5.0\")]")]
        [DataRow("[SupportedOSPlatform(\"windows5.0\"), SupportedOSPlatform(\"windows5.0\")]")]
        [DataRow("[global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\"), global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\")]")]
        [DataRow("[return: SupportedOSPlatform(\"windows5.0\")] [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"windows5.0\")]")]
        public void AvailabilityDeduplicationPreservesConflictsOtherNamesAndTargets(string attributes)
        {
            var tree = Clean($@"
namespace Test {{ public abstract class Apis {{
    {attributes}
    public abstract int F();
}} }}");
            var method = tree.GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>().Single();
            Assert.AreEqual(2, method.AttributeLists.SelectMany(list => list.Attributes)
                .Count(attribute => attribute.Name.ToString().Contains("SupportedOSPlatform")));
            if (attributes.Contains("return:"))
                Assert.IsTrue(method.AttributeLists.Any(list => list.Target?.Identifier.ValueText == "return"));
        }

        [DataTestMethod]
        [DataRow("windows5.0", true)]
        [DataRow("windows6.0", false)]
        public void AvailabilityAliasDeduplicationAllowsOnlyIdenticalPayloadsToCompile(string legacyPlatform, bool success)
        {
            var tree = Clean($@"
using Windows.Win32.Foundation.Metadata;
namespace Windows.Win32.Foundation.Metadata {{
    public sealed class SupportedOSPlatformAttribute : System.Attribute {{
        public SupportedOSPlatformAttribute(string platform) {{ }}
    }}
}}
namespace Test {{ public abstract class Apis {{
    [SupportedOSPlatform(""{legacyPlatform}"")]
    [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(""windows5.0"")]
    public abstract int F();
}} }}");
            var compilation = CSharpCompilation.Create("AvailabilityAliases", new[] { tree },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));
            using var output = new MemoryStream();
            var result = compilation.Emit(output);
            Assert.AreEqual(success, result.Success, string.Join(Environment.NewLine, result.Diagnostics));
            if (!success)
                Assert.IsTrue(result.Diagnostics.Any(diagnostic => diagnostic.Id == "CS0579"));
        }

        [DataTestMethod]
        [DataRow("[RAIIFree(\"Other\")]")]
        [DataRow("[InvalidHandleValue(7L)]")]
        public void ConflictingLegacyFactsCannotOverwriteHeaders(string remap)
        {
            var exception = Assert.ThrowsException<InvalidOperationException>(() =>
                Clean(HeaderReturn, new Dictionary<string, string> { ["F::return"] = remap }));
            StringAssert.Contains(exception.Message, "WMA002");
        }

        [TestMethod]
        public void LegacyRemovalCannotEraseHeaderFact()
        {
            string remap = $"[RAIIFree{EncodeHelpers.AttributeToRemoveSuffix}]";
            var exception = Assert.ThrowsException<InvalidOperationException>(() =>
                Clean(HeaderReturn, new Dictionary<string, string> { ["F::return"] = remap }));
            StringAssert.Contains(exception.Message, "WMA002");
        }

        [TestMethod]
        public void LegacyRemapsPreserveOtherTargetsAndMixedListAttributes()
        {
            var tree = Clean(@"
namespace Test { public class Apis {
    [return: global::Windows.Win32.Foundation.Metadata.AssociatedEnum(""E"")]
    public static extern int F([In, Out, Optional] int* output);
}}", new Dictionary<string, string>
            {
                ["F"] = "[AssociatedEnum(\"Other\")]",
                ["F::output"] = "[Out]",
            });
            var method = tree.GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>().Single();
            Assert.IsTrue(method.AttributeLists.Any(list => list.Target?.Identifier.ValueText == "return" &&
                list.Attributes.Any(attribute => attribute.ToString().Contains("\"E\""))));
            CollectionAssert.AreEquivalent(new[] { "In", "Out", "Optional" }, method.ParameterList.Parameters[0]
                .AttributeLists.SelectMany(list => list.Attributes).Select(attribute => attribute.Name.ToString()).ToArray());
        }

        [TestMethod]
        public void NativeFlagsAreNotDuplicatedByEnumSidecars()
        {
            var tree = Clean("namespace Test { [global::System.Flags] public enum E { A = 1 } }", flags: new HashSet<string> { "E" });
            Assert.AreEqual(1, tree.GetRoot().DescendantNodes().OfType<AttributeSyntax>().Count(attribute => attribute.Name.ToString().Contains("Flags")));
        }

        [TestMethod]
        public void SourceOwnedGroupKeepsItsNamespaceWithoutAnAuthoredUse()
        {
            var tree = CSharpSyntaxTree.ParseText(@"
namespace Windows.Win32.System.SystemServices {
[global::System.Flags] public enum ROT_FLAGS : uint {
    ROTFLAGS_REGISTRATIONKEEPSALIVE = 1,
    ROTFLAGS_ALLOWANYCLIENT = 2
}}", path: "winnt.header-types.cs");
            var moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree, new Dictionary<string, string>
            {
                ["ROT_FLAGS"] = "Windows.Win32.System.Com",
            });
            var group = moved.GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>().Single();
            Assert.AreEqual("Windows.Win32.System.Com",
                group.Ancestors().OfType<NamespaceDeclarationSyntax>().Single().Name.ToString());
            Assert.AreEqual("uint", group.BaseList!.Types.Single().Type.ToString());
            Assert.AreEqual("global::System.Flags", group.AttributeLists.Single().Attributes.Single().Name.ToString());
            CollectionAssert.AreEqual(new[] { "ROTFLAGS_REGISTRATIONKEEPSALIVE=1", "ROTFLAGS_ALLOWANYCLIENT=2" },
                group.Members.Select(member => member.Identifier.ValueText + "=" + member.EqualsValue!.Value).ToArray());
        }

        [DataTestMethod]
        [DataRow("static string Text = \"x\";")]
        [DataRow("static readonly global::System.Guid Id = new global::System.Guid(\"00000000-0000-0000-0000-000000000000\");")]
        [DataRow("static readonly int __forceconst__Value = 1;")]
        public void SpecialFieldsStillCleanTransport(string declaration)
        {
            var tree = Clean($"namespace Test {{ public class C {{ [NativeAnnotation(\"unowned\")] public {declaration} }} }}");
            Assert.IsFalse(tree.GetRoot().ToString().Contains("NativeAnnotation"));
        }

        [TestMethod]
        public void GuidConstantsDoNotAcquirePointerConstnessOrAdditionalLegacyRemaps()
        {
            var tree = Clean(@"
namespace Test { public class Apis {
    [NativeAnnotation(""unowned""), NativeTypeName(""const GUID"")]
    public static readonly Guid Id = new Guid(""00000000-0000-0000-0000-000000000001"");
}}", new Dictionary<string, string> { ["Id"] = "[Documentation(\"https://example.invalid/\")]" });
            var field = tree.GetRoot().DescendantNodes().OfType<FieldDeclarationSyntax>().Single();
            Assert.IsTrue(field.AttributeLists.ToString().Contains("Guid"));
            Assert.IsFalse(field.AttributeLists.ToString().Contains("Const"));
            Assert.IsFalse(field.AttributeLists.ToString().Contains("Documentation"));
            Assert.IsFalse(field.AttributeLists.ToString().Contains("NativeAnnotation"));
        }

        [DataTestMethod]
        [DataRow("return")]
        [DataRow("parameter")]
        [DataRow("field")]
        [DataRow("delegate")]
        [DataRow("interface")]
        [DataRow("enum")]
        [DataRow("import")]
        [DataRow("nested-struct")]
        [DataRow("nested-enum")]
        public void CrossArchitectureMergingIncludesSemanticFacts(string target)
        {
            var map = new CrossArchSyntaxMap();
            var trees = new[] { "x86", "x64", "arm64" }.Select(architecture =>
                CSharpSyntaxTree.ParseText(Source(target, architecture == "x86" ? "First" : "Second"),
                    path: $@"C:\fixture\{architecture}\Partition.cs")).ToArray();
            foreach (var tree in trees)
                map.AddTree(tree);
            var groups = map.GetSignatureArchGroupings(trees[0].GetRoot().DescendantNodes()
                .First(node => node is EnumDeclarationSyntax or StructDeclarationSyntax or DelegateDeclarationSyntax or MethodDeclarationSyntax)).ToArray();
            CollectionAssert.AreEquivalent(new[] { Architecture.X86, Architecture.X64 | Architecture.Arm64 }, groups);
            var merger = new CrossArchTreeMerger(map);
            string merged = string.Join("\n", trees.Select(tree => merger.ProcessTree(tree, out _).ToString()));
            StringAssert.Contains(merged, "First");
            StringAssert.Contains(merged, "Second");
            StringAssert.Contains(merged, "SupportedArchitecture");
        }

        [TestMethod]
        public void CallingConventionOnlyDoesNotSplitArchitectures()
        {
            var map = new CrossArchSyntaxMap();
            var trees = new[] { "x86", "x64", "arm64" }.Select(architecture =>
                CSharpSyntaxTree.ParseText(
                    $"namespace Test {{ public class Apis {{ [DllImport(\"x.dll\", CallingConvention = CallingConvention.{(architecture == "x86" ? "StdCall" : "Cdecl")})] public static extern int F(int x); }} }}",
                    path: $@"C:\fixture\{architecture}\Partition.cs")).ToArray();
            foreach (var tree in trees)
                map.AddTree(tree);
            var method = trees[0].GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>().Single();
            CollectionAssert.AreEqual(new[] { Architecture.All }, map.GetSignatureArchGroupings(method).ToArray());
        }

        [TestMethod]
        public void X86PackingFallbackDoesNotBorrowSemanticAttributes()
        {
            var map = new CrossArchSyntaxMap();
            var x64 = CSharpSyntaxTree.ParseText(@"
namespace Test {
    [StructLayout(LayoutKind.Sequential, Pack = 8), SupportedOSPlatform(""windows10.0.10240"")]
    public struct S { public uint value; }
}", path: @"C:\fixture\x64\Partition.cs");
            var x86 = CSharpSyntaxTree.ParseText("namespace Test { public struct S { public uint value; } }",
                path: @"C:\fixture\x86\Partition.cs");
            map.AddTree(x64);
            map.AddTree(x86);
            var record = x86.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            CollectionAssert.AreEquivalent(new[] { Architecture.X86, Architecture.X64 }, map.GetSignatureArchGroupings(record).ToArray());
            Assert.IsFalse(map.FixX86Struct(record).AttributeLists.ToString().Contains("SupportedOSPlatform"));
        }

        [TestMethod]
        public void X86PackingFallbackCanBorrowLayoutAlone()
        {
            var map = new CrossArchSyntaxMap();
            var x64 = CSharpSyntaxTree.ParseText(@"
namespace Test {
    [StructLayout(LayoutKind.Sequential, Pack = 8)]
    public struct S { public uint value; }
}", path: @"C:\fixture\x64\Partition.cs");
            var x86 = CSharpSyntaxTree.ParseText("namespace Test { public struct S { public uint value; } }",
                path: @"C:\fixture\x86\Partition.cs");
            map.AddTree(x64);
            map.AddTree(x86);
            var record = x86.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            CollectionAssert.AreEqual(new[] { Architecture.X86 | Architecture.X64 }, map.GetSignatureArchGroupings(record).ToArray());
            var attributes = map.FixX86Struct(record).AttributeLists.SelectMany(list => list.Attributes).ToArray();
            Assert.AreEqual(1, attributes.Count(attribute => attribute.Name.ToString() == "StructLayout"));
            Assert.AreEqual(0, attributes.Count(attribute => attribute.Name.ToString() == "SupportedOSPlatform"));
        }

        private const string HeaderReturn = @"
namespace Test { public static class Apis {
    [return: global::Windows.Win32.Foundation.Metadata.RAIIFree(""Free"")]
    [return: global::Windows.Win32.Foundation.Metadata.InvalidHandleValue(0L)]
    [return: global::Windows.Win32.Foundation.Metadata.InvalidHandleValue(-1L)]
    public static extern int F();
}}
";

        private static SyntaxTree Clean(string source, Dictionary<string, string>? remaps = null, HashSet<string>? flags = null)
            => MetadataSyntaxTreeCleaner.CleanSyntaxTree(CSharpSyntaxTree.ParseText(source),
                remaps ?? new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(),
                flags ?? new HashSet<string>(), new Dictionary<string, string>(), new Dictionary<string, string>(),
                new Dictionary<string, string>(), new HashSet<string>(), new HashSet<string>(), "test.cs");

        private static string Source(string target, string value)
        {
            string attribute = $"[AssociatedEnum(\"{value}\")]";
            switch (target)
            {
                case "field": return $"namespace Test {{ public struct S {{ {attribute} public uint value; }} }}";
                case "enum": return $"namespace Test {{ [AssociatedConstant(\"{value}\")] public enum E {{ A = 1 }} }}";
                case "delegate": return $"namespace Test {{ public delegate int D({attribute} uint value); }}";
                case "interface": return $"namespace Test {{ public struct I {{ public void* lpVtbl; public int F({attribute} uint value) {{ }} }} }}";
                case "parameter": return $"namespace Test {{ public class Apis {{ [DllImport(\"x.dll\")] public static extern int F({attribute} uint value); }} }}";
                case "import": return $"namespace Test {{ public class Apis {{ [DllImport(\"{value}.dll\")] public static extern int F(uint value); }} }}";
                case "nested-struct": return $"namespace Test {{ public struct S {{ [global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform(\"{value}\")] public struct Nested {{ public uint value; }} }} }}";
                case "nested-enum": return $"namespace Test {{ public struct S {{ [global::Windows.Win32.Foundation.Metadata.AssociatedConstant(\"{value}\")] public enum Nested {{ A = 1 }} }} }}";
                default: return $"namespace Test {{ public class Apis {{ [DllImport(\"x.dll\")] [return: AssociatedEnum(\"{value}\")] public static extern int F(uint value); }} }}";
            }
        }
    }
}

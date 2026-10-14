using System;
using System.Collections.Generic;
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

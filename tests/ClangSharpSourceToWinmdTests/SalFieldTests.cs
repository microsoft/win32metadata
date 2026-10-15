using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    [DoNotParallelize]
    public class SalFieldTests
    {
        private const string DhcpFieldSal =
            "Name=SAL_name; p1=\"_Field_size_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^" +
            "Name=SAL_name; p1=\"_Notnull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^" +
            "Name=SAL_null; p1=__no^Name=SAL_end^" +
            "Name=SAL_name; p1=\"_Writable_elements_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^" +
            "Name=SAL_writableTo; p1=elementCount(NumElements)^Name=SAL_end^Name=SAL_end";

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void NativeDhcpFieldSalUsesFieldNameRatherThanParameterIndex(bool countAfterArray)
        {
            var tree = Clean(Source(DhcpFieldSal, countAfterArray: countAfterArray));
            var field = GetElements(tree);
            var attributes = field.AttributeLists.SelectMany(list => list.Attributes).ToArray();
            CollectionAssert.AreEquivalent(new[] { "NativeTypeName", "NativeArrayInfo" },
                attributes.Select(attribute => attribute.Name.ToString()).ToArray());
            var argument = attributes.Single(attribute => attribute.Name.ToString() == "NativeArrayInfo")
                .ArgumentList!.Arguments.Single();
            Assert.AreEqual("CountFieldName", argument.NameEquals!.Name.Identifier.ValueText);
            Assert.AreEqual("NumElements", ((LiteralExpressionSyntax)argument.Expression).Token.ValueText);
            Assert.AreEqual("uint*", field.Declaration.Type.ToString());
        }

        [TestMethod]
        public void DuplicateReadableAndWritableConstraintsProduceOneAttribute()
        {
            var tree = Clean(Source("Name=SAL_readableTo; p1=elementCount(NumElements)^" +
                "Name=SAL_writableTo; p1=elementCount(NumElements)",
                fieldAttributes: CppAttribute("Name=SAL_readableTo; p1=elementCount(NumElements)")));
            Assert.AreEqual(1, GetElements(tree).AttributeLists.SelectMany(list => list.Attributes)
                .Count(attribute => attribute.Name.ToString() == "NativeArrayInfo"));
        }

        [DataTestMethod]
        [DataRow(0)]
        [DataRow(1)]
        [DataRow(4)]
        public void ConstantElementCountsArePreserved(int count)
        {
            var tree = Clean(Source($"Name=SAL_readableTo; p1=elementCount({count})"));
            var argument = GetArrayArgument(tree);
            Assert.AreEqual("CountConst", argument.NameEquals!.Name.Identifier.ValueText);
            Assert.AreEqual(count, ((LiteralExpressionSyntax)argument.Expression).Token.Value);
        }

        [TestMethod]
        public void EscapedCounterIdentifierUsesItsMetadataName()
        {
            var tree = Clean(Source("Name=SAL_readableTo; p1=elementCount(params)",
                countDeclaration: "public uint @params;"));
            Assert.AreEqual("params", ((LiteralExpressionSyntax)GetArrayArgument(tree).Expression).Token.ValueText);
        }

        [TestMethod]
        public void CounterMemberRemapUpdatesCountFieldName()
        {
            var tree = Clean(Source(DhcpFieldSal), new Dictionary<string, string>
            {
                [@"^S::NumElements$"] = "uint Count",
            });
            Assert.AreEqual("Count", ((LiteralExpressionSyntax)GetArrayArgument(tree).Expression).Token.ValueText);
            Assert.IsTrue(tree.GetRoot().DescendantNodes().OfType<VariableDeclaratorSyntax>()
                .Any(variable => variable.Identifier.ValueText == "Count"));
        }

        [TestMethod]
        public void IdenticalExplicitArrayInfoIsNotDuplicated()
        {
            var tree = Clean(Source(DhcpFieldSal,
                fieldAttributes: "[global::Windows.Win32.Foundation.Metadata.NativeArrayInfoAttribute(CountFieldName = \"NumElements\")]"));
            Assert.AreEqual(1, GetElements(tree).AttributeLists.SelectMany(list => list.Attributes)
                .Count(attribute => attribute.Name.ToString().Contains("NativeArrayInfo")));
        }

        [TestMethod]
        public void ConflictingExplicitArrayInfoIsNotSilentlyReplaced()
        {
            var exception = Assert.ThrowsException<InvalidOperationException>(() => Clean(Source(DhcpFieldSal,
                fieldAttributes: "[NativeArrayInfo(CountConst = 4)]")));
            StringAssert.Contains(exception.Message, "WMA002");
            StringAssert.Contains(exception.Message, "S::Elements");
        }

        [TestMethod]
        public void ExistingLegacyRemapStillAppliesUntilItsRowIsRemoved()
        {
            var tree = Clean(Source(DhcpFieldSal), new Dictionary<string, string>
            {
                ["S::Elements"] = "[NativeArrayInfo(CountParamIndex = 0)]",
            });
            Assert.AreEqual("CountParamIndex", GetArrayArgument(tree).NameEquals!.Name.Identifier.ValueText);
        }

        [DataTestMethod]
        [DataRow("Missing")]
        [DataRow("NumElements + 1")]
        [DataRow("*NumElements")]
        [DataRow("_Old_(NumElements)")]
        [DataRow("-1")]
        [DataRow("NumElements == 0 ? 1 : NumElements")]
        public void UnsupportedElementCountsAreReportedNotFabricated(string count)
        {
            var tree = CleanWithDiagnostics(Source($"Name=SAL_readableTo; p1=elementCount({count})"),
                out string diagnostics);
            Assert.IsFalse(GetElements(tree).AttributeLists.ToString().Contains("NativeArrayInfo"));
            StringAssert.Contains(diagnostics, "warning CSSW002");
            StringAssert.Contains(diagnostics, "S::Elements");
            StringAssert.Contains(diagnostics, count);
        }

        [TestMethod]
        public void ConflictingNativeCountsAreReportedNotChosenArbitrarily()
        {
            var tree = CleanWithDiagnostics(Source("Name=SAL_readableTo; p1=elementCount(NumElements)^" +
                "Name=SAL_writableTo; p1=elementCount(Other)",
                countDeclaration: "public uint NumElements; public uint Other;"), out string diagnostics);
            Assert.IsFalse(GetElements(tree).AttributeLists.ToString().Contains("NativeArrayInfo"));
            StringAssert.Contains(diagnostics, "multiple distinct element counts");
        }

        [TestMethod]
        public void ByteCountsAreNotMisrepresentedAsElementCounts()
        {
            var tree = Clean(Source("Name=SAL_readableTo; p1=byteCount(NumElements)"));
            Assert.IsFalse(GetElements(tree).AttributeLists.ToString().Contains("NativeArrayInfo"));
        }

        [DataTestMethod]
        [DataRow("elementCount", "NativeArrayInfo", "CountParamIndex")]
        [DataRow("byteCount", "MemorySize", "BytesParamIndex")]
        public void ParameterCountLoweringRetainsParameterIndices(string countKind, string attributeName, string argumentName)
        {
            string sal = $"Name=SAL_pre^Name=SAL_readableTo; p1={countKind}(count)";
            var tree = Clean("namespace Test { public unsafe delegate void D(" + CppAttribute(sal) +
                " uint* values, uint count); }");
            var argument = tree.GetRoot().DescendantNodes().OfType<ParameterSyntax>().First()
                .AttributeLists.SelectMany(list => list.Attributes)
                .Single(attribute => attribute.Name.ToString() == attributeName).ArgumentList!.Arguments.Single();
            Assert.AreEqual(argumentName, argument.NameEquals!.Name.Identifier.ValueText);
            Assert.AreEqual(1, ((LiteralExpressionSyntax)argument.Expression).Token.Value);
        }

        private static string Source(string sal, bool countAfterArray = false,
            string countDeclaration = "public uint NumElements;", string fieldAttributes = "")
        {
            string elements = "[NativeTypeName(\"LPDHCP_IP_ADDRESS\")] " + fieldAttributes + CppAttribute(sal) +
                " public uint* Elements;";
            return "namespace Test { public unsafe struct S { public uint Reserved; " +
                (countAfterArray ? elements + countDeclaration : countDeclaration + elements) + " } }";
        }

        private static string CppAttribute(string sal) => $"[CppAttributeList({SyntaxFactory.Literal(sal).Text})]";

        private static FieldDeclarationSyntax GetElements(SyntaxTree tree) =>
            tree.GetRoot().DescendantNodes().OfType<FieldDeclarationSyntax>()
                .Single(field => field.Declaration.Variables[0].Identifier.ValueText == "Elements");

        private static AttributeArgumentSyntax GetArrayArgument(SyntaxTree tree) =>
            GetElements(tree).AttributeLists.SelectMany(list => list.Attributes)
                .Single(attribute => attribute.Name.ToString() == "NativeArrayInfo").ArgumentList!.Arguments.Single();

        private static SyntaxTree Clean(string source, Dictionary<string, string>? remaps = null) =>
            MetadataSyntaxTreeCleaner.CleanSyntaxTree(CSharpSyntaxTree.ParseText(source),
                remaps ?? new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(),
                new HashSet<string>(), new Dictionary<string, string>(), new Dictionary<string, string>(),
                new Dictionary<string, string>(), new HashSet<string>(), new HashSet<string>(), "native-field.cs");

        private static SyntaxTree CleanWithDiagnostics(string source, out string diagnostics)
        {
            using var writer = new StringWriter();
            var previous = Console.Out;
            try
            {
                Console.SetOut(writer);
                return Clean(source);
            }
            finally
            {
                Console.SetOut(previous);
                diagnostics = writer.ToString();
            }
        }
    }
}

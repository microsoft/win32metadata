using System.Collections.Generic;
using System.Linq;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class NamespaceQualificationTests
    {
        [DataTestMethod]
        [DataRow("<TARGET>", "public TARGET Value;", "TARGET")]
        [DataRow("", "public struct TARGET {} public TARGET Value;", "TARGET")]
        [DataRow("", "public enum TARGET { Zero } public TARGET Value;", "TARGET")]
        [DataRow("", "public delegate void TARGET(); public TARGET Value;", "TARGET")]
        [DataRow("", "public struct TARGET { public TARGET Value; }", "TARGET")]
        [DataRow("<TARGET>", "public struct Inner { public TARGET Value; }", "TARGET")]
        [DataRow("", "public class Inner { public delegate void TARGET(); public TARGET Value; }", "TARGET")]
        [DataRow("", "public TARGET Echo<TARGET>(TARGET Value) => Value;", "TARGET")]
        [DataRow("", "public TARGET Value;", "global::Test.TARGET")]
        [DataRow("", "public OTHER Value;", "OTHER")]
        public void QualificationPreservesLexicalTypeShadowing(string parameters, string members, string expected)
        {
            var tree = CSharpSyntaxTree.ParseText(
                $"namespace Test {{ public struct Container{parameters} {{ {members} }} }}", path: "Bindings.cs");
            var moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree,
                new Dictionary<string, string> { ["Container"] = "Moved" },
                new HashSet<(string, string)> { ("Test", "TARGET") });
            var root = moved.GetRoot();
            var types = root.DescendantNodes().OfType<FieldDeclarationSyntax>().Select(field => field.Declaration.Type)
                .Concat(root.DescendantNodes().OfType<MethodDeclarationSyntax>().Select(method => method.ReturnType))
                .Concat(root.DescendantNodes().OfType<ParameterSyntax>().Where(parameter =>
                    parameter.Identifier.ValueText == "Value").Select(parameter => parameter.Type)).ToArray();
            Assert.IsTrue(types.Length > 0);
            Assert.IsTrue(types.All(type => type?.ToString() == expected), moved.GetText().ToString());
        }

        [TestMethod]
        public void ShadowedNamesStayWithinTheirEnclosingDeclaration()
        {
            var tree = CSharpSyntaxTree.ParseText(@"
namespace Test {
public struct First { public struct TARGET {} public TARGET Shadowed; }
public struct Second { public TARGET Qualified; }
}", path: "Bindings.cs");
            var moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree,
                new Dictionary<string, string> { ["First"] = "Moved", ["Second"] = "Moved" },
                new HashSet<(string, string)> { ("Test", "TARGET") });
            var fields = moved.GetRoot().DescendantNodes().OfType<FieldDeclarationSyntax>().ToDictionary(
                field => field.Declaration.Variables.Single().Identifier.ValueText,
                field => field.Declaration.Type.ToString());
            Assert.AreEqual("TARGET", fields["Shadowed"]);
            Assert.AreEqual("global::Test.TARGET", fields["Qualified"]);
        }

        [TestMethod]
        public void LargeQualificationRetainsTheOriginalReplacementTypesAndTrivia()
        {
            string members = string.Join("\r\n", Enumerable.Range(0, 512).Select(index =>
                $"public /* before {index} */ TARGET /* after {index} */ Value{index};"));
            var tree = CSharpSyntaxTree.ParseText(
                $"namespace Test {{ public struct Container {{ {members} }} }}", path: "Bindings.cs");
            var original = tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            var expected = original.ReplaceNodes(
                original.DescendantNodes().OfType<FieldDeclarationSyntax>().Select(field => field.Declaration.Type),
                (type, _) => SyntaxFactory.ParseTypeName("global::Test.TARGET").WithTriviaFrom(type));
            var moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree,
                new Dictionary<string, string> { ["Container"] = "Moved" },
                new HashSet<(string, string)> { ("Test", "TARGET") });
            var actual = moved.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            Assert.AreEqual(512, actual.Members.OfType<FieldDeclarationSyntax>().Count());
            Assert.AreEqual(expected.NormalizeWhitespace().ToFullString(), actual.NormalizeWhitespace().ToFullString());
        }
    }
}

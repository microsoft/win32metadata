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
    public class CrossArchEnumTests
    {
        [TestMethod]
        public void MergeEnums_IdenticalAcrossAllArchitectures_ProducesSingleCommonEnum()
        {
            SyntaxTree[] trees =
            {
                CreateTree("x64", "public enum Register { Value = 0 }"),
                CreateTree("arm64", "public enum Register { Value = 0 }"),
                CreateTree("x86", "public enum Register { Value = 0 }"),
            };

            EnumDeclarationSyntax declaration = MergeEnums(trees).Single();

            Assert.AreEqual("Register", declaration.Identifier.ValueText);
            Assert.IsNull(SyntaxUtils.GetAttribute(declaration.AttributeLists, "SupportedArchitecture"));
        }

        [TestMethod]
        public void MergeEnums_AbsentOnX86_RetainsShared64BitEnum()
        {
            SyntaxTree[] trees =
            {
                CreateTree("x64", "public enum Register { Value = 0 }"),
                CreateTree("arm64", "public enum Register { Value = 0 }"),
                CreateTree("x86", string.Empty),
            };

            EnumDeclarationSyntax declaration = MergeEnums(trees).Single();

            Assert.AreEqual("Register", declaration.Identifier.ValueText);
            Assert.AreEqual(
                "Windows.Win32.Foundation.Metadata.Architecture.X64 | Windows.Win32.Foundation.Metadata.Architecture.Arm64",
                GetArchitectures(declaration));
        }

        [TestMethod]
        public void MergeEnums_DifferentOnX64AndArm64_RetainsBothDefinitions()
        {
            SyntaxTree[] trees =
            {
                CreateTree("x64", "public enum Register { X64Register = 1 }"),
                CreateTree("arm64", "public enum Register { Arm64Register = 2 }"),
                CreateTree("x86", string.Empty),
            };

            EnumDeclarationSyntax[] declarations = MergeEnums(trees);

            Assert.AreEqual(2, declarations.Length);
            Assert.AreEqual("Register", declarations[0].Identifier.ValueText);
            Assert.AreEqual("Register____1", declarations[1].Identifier.ValueText);
            Assert.AreEqual("X64Register", declarations[0].Members.Single().Identifier.ValueText);
            Assert.AreEqual("Arm64Register", declarations[1].Members.Single().Identifier.ValueText);
            Assert.AreEqual("1", declarations[0].Members.Single().EqualsValue?.Value.ToString());
            Assert.AreEqual("2", declarations[1].Members.Single().EqualsValue?.Value.ToString());
            Assert.AreEqual("Windows.Win32.Foundation.Metadata.Architecture.X64", GetArchitectures(declarations[0]));
            Assert.AreEqual("Windows.Win32.Foundation.Metadata.Architecture.Arm64", GetArchitectures(declarations[1]));
        }

        [DataTestMethod]
        [DataRow("x86", "X86")]
        [DataRow("x64", "X64")]
        [DataRow("arm64", "Arm64")]
        public void MergeEnums_DeclaredOnSingleArchitecture_RetainsArchitecture(string directory, string architecture)
        {
            EnumDeclarationSyntax declaration = MergeEnums(
                new[] { CreateTree(directory, "public enum Register { Value = 0 }") }).Single();

            Assert.AreEqual("Windows.Win32.Foundation.Metadata.Architecture." + architecture, GetArchitectures(declaration));
        }

        private static SyntaxTree CreateTree(string architecture, string declaration)
        {
            return CSharpSyntaxTree.ParseText(
                "namespace Test { " + declaration + " }",
                path: Path.Combine("generated", architecture, "Test.cs"));
        }

        private static EnumDeclarationSyntax[] MergeEnums(SyntaxTree[] trees)
        {
            var map = new CrossArchSyntaxMap();
            foreach (SyntaxTree tree in trees)
            {
                map.AddTree(tree);
            }

            var merger = new CrossArchTreeMerger(map);
            return trees.Select(tree => merger.ProcessTree(tree, out _))
                .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>())
                .ToArray();
        }

        private static string GetArchitectures(EnumDeclarationSyntax declaration)
        {
            AttributeArgumentListSyntax arguments = SyntaxUtils.GetAttribute(declaration.AttributeLists, "SupportedArchitecture")?.ArgumentList
                ?? throw new AssertFailedException("Expected a SupportedArchitecture attribute.");
            return arguments.Arguments.Single().Expression.ToString();
        }
    }
}

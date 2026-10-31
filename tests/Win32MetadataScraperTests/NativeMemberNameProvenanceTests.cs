using System;
using System.Linq;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class NativeMemberNameProvenanceTests
    {
        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ProvenMemberNamePreservesFieldDeclaratorsAndAuthoredNames(bool authoredName)
        {
            var field = SyntaxFactory.ParseCompilationUnit("unsafe struct Values { public fixed ushort NameW[8]; }")
                .DescendantNodes().OfType<FieldDeclarationSyntax>().Single();
            field = NativeMemberNameProvenance.Attach(field, "native.h:20 (FieldDecl)", "native.h:10 (StructDecl)", "NameW", "NameA");
            if (authoredName)
                field = field.WithDeclaration(field.Declaration.WithVariables(SyntaxFactory.SingletonSeparatedList(
                    field.Declaration.Variables[0].WithIdentifier(SyntaxFactory.Identifier("Chosen")))));
            var projected = (FieldDeclarationSyntax)NativeMemberNameProvenance.Project(field);
            Assert.Equal(authoredName ? "Chosen" : "NameA", projected.Declaration.Variables[0].Identifier.ValueText);
            Assert.Equal("[8]", projected.Declaration.Variables[0].ArgumentList.ToString());
            Assert.Equal("ushort", projected.Declaration.Type.ToString());
            Assert.DoesNotContain("Win32Metadata.NativeMemberName", projected.ToFullString());
        }

        [Fact]
        public void ProvenMemberNameLeavesAuthoredMethodSpellingAndEncodingMetadataUnchanged()
        {
            var method = SyntaxFactory.ParseCompilationUnit(
                "unsafe struct Owner { [Unicode] public int NameW(char* value) => 0; }")
                .DescendantNodes().OfType<MethodDeclarationSyntax>().Single();
            method = NativeMemberNameProvenance.Attach(method, "native.h:20 (CXXMethod)", "native.h:10 (StructDecl)", "NameW", "NameA")
                .WithIdentifier(SyntaxFactory.Identifier("Chosen"));
            var projected = (MethodDeclarationSyntax)NativeMemberNameProvenance.Project(method);
            Assert.Equal("Chosen", projected.Identifier.ValueText);
            Assert.Equal("Unicode", Assert.Single(projected.AttributeLists).Attributes.Single().Name.ToString());
            Assert.Equal("char*", projected.ParameterList.Parameters[0].Type.ToString());
            Assert.DoesNotContain("Win32Metadata.NativeMemberName", projected.ToFullString());
        }

        [Fact]
        public void ProvenMethodNameSurvivesRemovalAndAdditionOfTransportAttributes()
        {
            var method = SyntaxFactory.ParseCompilationUnit(
                "unsafe struct Owner { [SourceLocation(\"native.h\", 2, 3)] public int NameW(char* value) => 0; }")
                .DescendantNodes().OfType<MethodDeclarationSyntax>().Single();
            method = NativeMemberNameProvenance.Attach(method, "native.h:20 (CXXMethod)", "native.h:10 (StructDecl)", "NameW", "NameA");
            method = SyntaxFactory.ParseCompilationUnit("unsafe struct Owner { " + method.NormalizeWhitespace().ToFullString() + "\n}")
                .DescendantNodes().OfType<MethodDeclarationSyntax>().Single();
            method = method.WithAttributeLists(default).AddAttributeLists(
                SyntaxFactory.AttributeList(SyntaxFactory.SingletonSeparatedList(
                    SyntaxFactory.Attribute(SyntaxFactory.IdentifierName("Unicode")))));
            var projected = (MethodDeclarationSyntax)NativeMemberNameProvenance.Project(method);
            Assert.Equal("NameA", projected.Identifier.ValueText);
            Assert.Equal("Unicode", Assert.Single(projected.AttributeLists).Attributes.Single().Name.ToString());
            Assert.Equal("char*", projected.ParameterList.Parameters[0].Type.ToString());
            Assert.DoesNotContain("Win32Metadata.NativeMemberName", projected.ToFullString());
        }

        [Theory]
        [InlineData("v2 {}")]
        [InlineData("v1 {}")]
        [InlineData("v1 {\"kind\":\"method\",\"source\":\"native.h:1\",\"parent\":\"native.h:2\",\"primaryName\":\"NameW\",\"legacyName\":\"NameA\",\"extra\":\"unproved\"}")]
        [InlineData("v1 {\"kind\":\"field\",\"source\":\"native.h:1\",\"parent\":\"native.h:2\",\"primaryName\":\"NameW\",\"legacyName\":\"NameA\"}")]
        public void MalformedMemberNameProofFailsInsteadOfSilentlyLeavingANewPublicName(string payload)
        {
            var root = SyntaxFactory.ParseCompilationUnit(
                "struct Owner {\n/* Win32Metadata.NativeMemberName." + payload + " */\npublic int NameW() => 0;\n}");
            Assert.Throws<InvalidOperationException>(() => NativeMemberNameProvenance.Project(root));
        }

        [Fact]
        public void NativeMemberNameProofCannotRenameAnExplicitDllExport()
        {
            var method = SyntaxFactory.ParseCompilationUnit(
                "class Apis { [DllImport(\"native.dll\")] public static extern int NameW(); }")
                .DescendantNodes().OfType<MethodDeclarationSyntax>().Single();
            method = NativeMemberNameProvenance.Attach(method, "native.h:20 (CXXMethod)", "native.h:10 (StructDecl)", "NameW", "NameA");
            Assert.Throws<InvalidOperationException>(() => NativeMemberNameProvenance.Project(method));
        }
    }
}

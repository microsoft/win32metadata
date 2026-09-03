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
    public class GuidAttributeTests
    {
        [TestMethod]
        public void ConvertGuidToAttributeList_TypeNamedWindows_DoesNotShadowGuidAttributeNamespace()
        {
            AttributeListSyntax attributeList = EncodeHelpers.ConvertGuidToAttributeList(Guid.Empty);
            string source = @"
namespace Windows.Win32.Foundation.Metadata
{
    public sealed class GuidAttribute : global::System.Attribute
    {
        public GuidAttribute(uint a, ushort b, ushort c, byte d, byte e, byte f, byte g, byte h, byte i, byte j, byte k)
        {
        }
    }
}

namespace Test
{
    public sealed class Windows
    {
    }

    public static class Constants
    {
        " + attributeList + @"
        public const string Id = """";
    }
}";

            CSharpCompilation compilation = CSharpCompilation.Create(
                "GuidAttributeTest",
                new[] { CSharpSyntaxTree.ParseText(source) },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));

            Diagnostic[] errors = compilation.GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error)
                .ToArray();

            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
        }

        [TestMethod]
        public void CleanSyntaxTree_GuidConstantUsesGloballyQualifiedAttribute()
        {
            SyntaxTree syntaxTree = CSharpSyntaxTree.ParseText(@"
using System;

namespace Test
{
    public static class Constants
    {
        public static readonly Guid Id = new Guid(""00000000-0000-0000-0000-000000000000"");
    }
}");

            SyntaxTree cleanedTree = MetadataSyntaxTreeCleaner.CleanSyntaxTree(
                syntaxTree,
                new Dictionary<string, string>(),
                new Dictionary<string, Dictionary<string, string>>(),
                new HashSet<string>(),
                new Dictionary<string, string>(),
                new Dictionary<string, string>(),
                new Dictionary<string, string>(),
                new HashSet<string>(),
                new HashSet<string>(),
                "test.cs");

            AttributeSyntax guidAttribute = cleanedTree.GetRoot()
                .DescendantNodes()
                .OfType<AttributeSyntax>()
                .Single();

            Assert.AreEqual(EncodeHelpers.GuidAttributeName, guidAttribute.Name.ToString());
        }
    }
}

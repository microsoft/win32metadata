using System.Collections.Generic;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class MetadataSyntaxTreeCleanerTests
    {
        [TestMethod]
        public void CleanSyntaxTree_RemovesNativeAnnotation()
        {
            SyntaxTree syntaxTree = CSharpSyntaxTree.ParseText(@"
[NativeAnnotation(""Name=SAL_name"")]
[NativeTypeName(""int"")]
public partial struct TEST_TYPE
{
}
");

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

            string cleanedSource = cleanedTree.GetRoot().ToFullString();
            Assert.IsFalse(cleanedSource.Contains("NativeAnnotation"));
            Assert.IsTrue(cleanedSource.Contains("NativeTypeName"));
        }
    }
}

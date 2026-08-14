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

        [TestMethod]
        public void CleanSyntaxTree_RemovesFieldSalAnnotations()
        {
            SyntaxTree syntaxTree = CSharpSyntaxTree.ParseText(@"
public partial struct TEST_TYPE
{
    [CppAttributeList(""Name=SAL_name; p1=\""Field_size_(1)\"""")]
    public int Value;
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
            Assert.IsFalse(cleanedSource.Contains("CppAttributeList"));
            Assert.IsTrue(cleanedSource.Contains("public int Value"));
        }

        [TestMethod]
        public void CleanSyntaxTree_NormalizesInvalidAnonymousRecordIndex()
        {
            SyntaxTree syntaxTree = CSharpSyntaxTree.ParseText(@"
public partial struct TEST_TYPE
{
    public _Anonymous-1_e__Struct* Value;

    public partial struct _Anonymous-1_e__Struct
    {
        public int NestedValue;
    }
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
            Assert.IsFalse(cleanedSource.Contains("_Anonymous-1_e__Struct"));
            Assert.IsTrue(cleanedSource.Contains("_Anonymous_e__Struct"));
        }

        [TestMethod]
        public void CleanSyntaxTree_RemovesRedundantIUnknownInheritance()
        {
            SyntaxTree syntaxTree = CSharpSyntaxTree.ParseText(@"
[NativeTypeName(""struct IDerived : IBase, IUnknown"")]
[NativeInheritance(""IUnknown"")]
public unsafe partial struct IDerived
{
    public void** lpVtbl;
    public IUnknown Base2;
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
            Assert.IsTrue(cleanedSource.Contains("NativeInheritance(\"IBase\")"));
            Assert.IsFalse(cleanedSource.Contains("Base2"));
            Assert.IsTrue(cleanedSource.Contains("lpVtbl"));
        }
    }
}

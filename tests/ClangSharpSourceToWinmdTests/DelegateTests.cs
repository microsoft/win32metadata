using System.Collections.Generic;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class DelegateTests
    {
        [TestMethod]
        public void VisitDelegateDeclaration_RelatedDelegates_DelegateParametersMerged()
        {
            // Arrange
            string code = 
                "[UnmanagedFunctionPointer(CallingConvention.StdCall)]\r\n" +
                "public unsafe delegate void TP_SIMPLE_CALLBACK(IntPtr* Instance, void* Context);\r\n" +
                "\r\n" +
                "[UnmanagedFunctionPointer(CallingConvention.StdCall)]\r\n" +
                "public unsafe delegate void PTP_SIMPLE_CALLBACK();\r\n";

            var syntaxTree = CSharpSyntaxTree.ParseText(code);
            var remaps = new Dictionary<string, string>();
            var enumAdditions = new Dictionary<string, Dictionary<string, string>>();
            var enumsMakeFlags = new HashSet<string>();
            var requiredNamespaces = new Dictionary<string, string>();
            var staticLibs = new Dictionary<string, string>();
            var apiNamesToNamespaces = new Dictionary<string, string>();
            var nonEmptyStructs = new HashSet<string>();
            var enumMemberNames = new HashSet<string>();

            // Act
            var result = MetadataSyntaxTreeCleaner.CleanSyntaxTree(
                syntaxTree,
                remaps,
                enumAdditions,
                enumsMakeFlags,
                requiredNamespaces,
                staticLibs,
                apiNamesToNamespaces,
                nonEmptyStructs,
                enumMemberNames,
                "DelegateTests.cs");

            // Assert
            string resultText = result.ToString();
            Assert.IsTrue(resultText.Contains("TP_SIMPLE_CALLBACK(IntPtr* Instance, void* Context)"), "TP_SIMPLE_CALLBACK should be present and have two parameters");
            Assert.IsTrue(resultText.Contains("PTP_SIMPLE_CALLBACK(IntPtr* Instance, void* Context)"), "PTP_SIMPLE_CALLBACK should be present and have two parameters");
        }
    }
}

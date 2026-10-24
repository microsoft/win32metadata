using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.ExceptionServices;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.CodeAnalysis.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class HeaderConstantDiagnosticTests
    {
        // Exercise qualification alone; public emission also rejects unrelated compilation errors.
        private static readonly Type Qualifier = typeof(ClangSharpSourceCompilation).Assembly
            .GetType("ClangSharpSourceToWinmd.CrossArchConstantQualifier", throwOnError: true)!;

        [DataTestMethod]
        [DataRow(false, false, false)]
        [DataRow(true, false, false)]
        [DataRow(false, true, false)]
        [DataRow(true, true, false)]
        [DataRow(false, false, true)]
        [DataRow(true, false, true)]
        [DataRow(false, true, true)]
        [DataRow(true, true, true)]
        public void InitializerErrorsRejectOtherwiseFoldableConstants(bool multipleDeclarators, bool mappedLines, bool legacyManual)
        {
            string declarations = "[System.Obsolete(\"legacy\", true)] public const int LEGACY = 1;\n" +
                (mappedLines ? "#line 200 \"mapped-constants.h\"\n" : "") +
                "public const int " + (multipleDeclarators ? "FIRST = 0, " : "") + "VALUE = LEGACY;";
            var tree = Parse(declarations, legacyManual ? "Constants.manual.modified.cs" : "Constants.cs");
            var model = Compile(tree).GetSemanticModel(tree);
            var variable = Variable(tree, "VALUE");
            AssertFoldedValue(model, variable, 1);
            var errors = model.GetDiagnostics(variable.Initializer!.Span)
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.IsTrue(errors.Any(diagnostic => diagnostic.Id == "CS0619"));
            if (mappedLines)
                Assert.AreEqual("mapped-constants.h", errors[0].Location.GetMappedLineSpan().Path);

            var error = Assert.ThrowsException<InvalidOperationException>(() => Qualify(tree));
            Assert.AreEqual($"CSSW003: Cannot qualify 'VALUE' in '{tree.FilePath}' for X86. " +
                "The constant or its dependencies could not be evaluated in this profile.", error.Message);
        }

        [DataTestMethod]
        [DataRow("public const int VALUE = 1; public static MissingType Other;")]
        [DataRow("[Missing] public const int VALUE = 1;")]
        [DataRow("public const int VALUE = 1; public static void Broken() { Missing(); }")]
        [DataRow("#error unrelated\npublic const int VALUE = 1;")]
        public void ErrorsOutsideInitializerRemainForOrdinaryCompilation(string declarations)
        {
            var tree = Parse(declarations);
            var model = Compile(tree).GetSemanticModel(tree);
            var variable = Variable(tree, "VALUE");
            AssertFoldedValue(model, variable, 1);
            Assert.IsTrue(model.GetDiagnostics().Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.IsFalse(model.GetDiagnostics(variable.Initializer!.Span)
                .Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));

            var qualified = Qualify(tree).Single();
            AssertFoldedValue(Compile(qualified).GetSemanticModel(qualified), Variable(qualified, "VALUE"), 1);
            Assert.IsTrue(Compile(qualified).GetDiagnostics().Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
        }

        [TestMethod]
        public void InitializerWarningsDoNotBecomeQualificationErrors()
        {
            var tree = Parse("[System.Obsolete(\"legacy\")] public const int LEGACY = 1;\n" +
                "public const int VALUE = LEGACY + 1;");
            var model = Compile(tree).GetSemanticModel(tree);
            var variable = Variable(tree, "VALUE");
            AssertFoldedValue(model, variable, 2);
            var diagnostics = model.GetDiagnostics(variable.Initializer!.Span);
            Assert.IsTrue(diagnostics.Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Warning));
            Assert.IsFalse(diagnostics.Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));

            var qualified = Qualify(tree).Single();
            AssertFoldedValue(Compile(qualified).GetSemanticModel(qualified), Variable(qualified, "VALUE"), 2);
        }

        [TestMethod]
        public void ZeroWidthErrorsAtInitializerEndAreNotLost()
        {
            var tree = Parse("public const int VALUE = 1");
            var model = Compile(tree).GetSemanticModel(tree);
            var variable = Variable(tree, "VALUE");
            AssertFoldedValue(model, variable, 1);
            Assert.IsTrue(model.GetDiagnostics(variable.Initializer!.Span).Any(diagnostic =>
                diagnostic.Severity == DiagnosticSeverity.Error && diagnostic.Location.SourceSpan.IsEmpty &&
                diagnostic.Location.SourceSpan.Start == variable.Initializer.Span.End));

            var error = Assert.ThrowsException<InvalidOperationException>(() => Qualify(tree));
            StringAssert.Contains(error.Message, "CSSW003: Cannot qualify 'VALUE'");
        }

        [DataTestMethod]
        [DataRow("Constants.manual.cs")]
        [DataRow("Constants.manual.modified.cs")]
        public void LegacyManualParseRecoveryPreservesItsBoundConstant(string fileName)
        {
            var tree = Parse("public const int BASE = 7;\npublic const int VALUE = (BASE + 1)\n" +
                "public const int NEXT = 9;", fileName);
            var model = Compile(tree).GetSemanticModel(tree);
            AssertFoldedValue(model, Variable(tree, "VALUE"), 8);
            Assert.IsTrue(tree.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS1002"));
            Assert.IsFalse(Compile(tree).GetDeclarationDiagnostics()
                .Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));

            var qualified = Qualify(tree).Single();
            AssertFoldedValue(Compile(qualified).GetSemanticModel(qualified), Variable(qualified, "VALUE"), 8);
            Assert.IsTrue(qualified.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS1002"));
        }

        [TestMethod]
        public void ASharedTreeGetsFreshDiagnosticsForEachProfile()
        {
            var shared = Parse("public const int VALUE = Provider.RAW;");
            var providers = new[] { "x86", "x64", "arm64" }.Select(architecture => CSharpSyntaxTree.ParseText(
                "namespace Test { public static class Provider { " +
                (architecture == "x64" ? "[System.Obsolete(\"legacy\", true)] " : "") +
                "public const int RAW = 7; } }", path: Path.Combine("fixtures", architecture, "Provider.cs"))).ToArray();
            var variable = Variable(shared, "VALUE");
            var x86 = Compile(shared, providers[0]).GetSemanticModel(shared);
            var x64 = Compile(shared, providers[1]).GetSemanticModel(shared);
            AssertFoldedValue(x86, variable, 7);
            AssertFoldedValue(x64, variable, 7);
            Assert.IsFalse(x86.GetDiagnostics(variable.Initializer!.Span)
                .Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.IsTrue(x64.GetDiagnostics(variable.Initializer.Span)
                .Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));

            var error = Assert.ThrowsException<InvalidOperationException>(() => Qualify(new[] { shared }.Concat(providers).ToArray()));
            StringAssert.Contains(error.Message, "CSSW003: Cannot qualify 'VALUE'");
            StringAssert.Contains(error.Message, "for X64");
        }

        [TestMethod]
        public void SameSpanErrorsInAnotherTreeDoNotRejectAConstant()
        {
            var tree = Parse("public const int VALUE = 1;");
            var variable = Variable(tree, "VALUE");
            const string prefix = "class Broken : ";
            var other = CSharpSyntaxTree.ParseText(new string(' ', variable.Initializer!.Span.Start - prefix.Length) +
                prefix + "MissingType { }", path: Path.Combine("fixtures", "common", "Unrelated.cs"));
            var compilation = Compile(tree, other);
            Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error &&
                diagnostic.Location.SourceTree == other && diagnostic.Location.SourceSpan.IntersectsWith(variable.Initializer.Span)));
            Assert.IsFalse(compilation.GetSemanticModel(tree).GetDiagnostics(variable.Initializer.Span)
                .Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));

            var qualified = Qualify(tree, other);
            var current = qualified.Single(source => source.FilePath == tree.FilePath);
            AssertFoldedValue(Compile(qualified).GetSemanticModel(current), Variable(current, "VALUE"), 1);
        }

        [TestMethod]
        public void CachedQueriesMatchRoslynAtDiagnosticBoundaries()
        {
            var tree = Parse("[System.Obsolete(\"old\", true)] public const int OLD = -1;\n" +
                "public const int FIRST = OLD, SECOND = OLD + 1;\n" +
                "public const uint BAD = (uint)(OLD + 0);\n" +
                "public static int Broken() => Missing;\npublic const int LAST = 3");
            var model = Compile(tree).GetSemanticModel(tree);
            var getErrorSpans = (Func<SemanticModel, TextSpan[]>)Qualifier.GetMethod("GetErrorSpans",
                BindingFlags.Static | BindingFlags.NonPublic)!.CreateDelegate(typeof(Func<SemanticModel, TextSpan[]>));
            var hasError = (Func<TextSpan, TextSpan[], bool>)Qualifier.GetMethod("HasError",
                BindingFlags.Static | BindingFlags.NonPublic)!.CreateDelegate(typeof(Func<TextSpan, TextSpan[], bool>));
            var errors = model.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error &&
                diagnostic.Location.SourceTree == tree).ToArray();
            Assert.IsTrue(errors.Length >= 4);
            Assert.IsTrue(errors.Any(outer => errors.Any(inner =>
                outer.Location.SourceSpan.Start < inner.Location.SourceSpan.Start &&
                outer.Location.SourceSpan.End > inner.Location.SourceSpan.End)),
                "The fixture must exercise an enclosing diagnostic as well as the inner error.");
            var positions = errors.SelectMany(diagnostic => new[]
                {
                    diagnostic.Location.SourceSpan.Start - 1, diagnostic.Location.SourceSpan.Start,
                    diagnostic.Location.SourceSpan.End, diagnostic.Location.SourceSpan.End + 1,
                }).Concat(new[] { 0, tree.Length }).Where(position => position >= 0 && position <= tree.Length)
                .Distinct().OrderBy(position => position).ToArray();
            var spans = getErrorSpans(model);
            foreach (int start in positions)
                foreach (int end in positions.Where(position => position >= start))
                {
                    var span = TextSpan.FromBounds(start, end);
                    bool expected = model.GetDiagnostics(span).Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error);
                    Assert.AreEqual(expected, hasError(span, spans), $"Diagnostic filtering changed for {span}.");
                }
        }

        private static SyntaxTree Parse(string declarations, string fileName = "Constants.cs") => CSharpSyntaxTree.ParseText(
            "namespace Test { public static class Apis {\n" + declarations + "\n} }",
            path: Path.Combine("fixtures", "common", fileName));

        private static CSharpCompilation Compile(params SyntaxTree[] trees) => CSharpCompilation.Create("DiagnosticOracle", trees,
            new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
            new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));

        private static VariableDeclaratorSyntax Variable(SyntaxTree tree, string name) => tree.GetRoot().DescendantNodes()
            .OfType<VariableDeclaratorSyntax>().Single(variable => variable.Identifier.ValueText == name);

        private static void AssertFoldedValue(SemanticModel model, VariableDeclaratorSyntax variable, int expected)
        {
            var symbol = model.GetDeclaredSymbol(variable) as IFieldSymbol;
            Assert.IsNotNull(symbol);
            Assert.IsTrue(symbol!.HasConstantValue);
            Assert.AreEqual(SpecialType.System_Int32, symbol.Type.SpecialType);
            Assert.AreEqual(expected, symbol.ConstantValue);
        }

        private static SyntaxTree[] Qualify(params SyntaxTree[] trees)
        {
            try
            {
                return ((IEnumerable<SyntaxTree>)Qualifier.GetMethod("Qualify", BindingFlags.Static | BindingFlags.NonPublic)!
                    .Invoke(null, new object[] { trees, Array.Empty<MetadataReference>() })!).ToArray();
            }
            catch (TargetInvocationException error) when (error.InnerException != null)
            {
                ExceptionDispatchInfo.Capture(error.InnerException).Throw();
                throw;
            }
        }
    }
}

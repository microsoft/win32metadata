using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class ImportEntryPointTests
    {
        private const string FixtureSource = @"
using System.Runtime.InteropServices;

namespace Windows.Win32.Fixture
{
    public static unsafe partial class Apis
    {
        [DllImport(""OrdinalFixture"", ExactSpelling = true)]
        public static extern int FixtureByName(int value);

        [DllImport(""OrdinalFixture"", ExactSpelling = true)]
        public static extern int FixtureByOrdinal(int value);
    }
}";

        [TestMethod]
        public void CleanSyntaxTree_AddsEntryPointOnlyToMappedImport()
        {
            SyntaxTree cleaned = Clean(FixtureSource, new Dictionary<string, string> { ["FixtureByOrdinal"] = "#7" });

            Dictionary<string, MethodDeclarationSyntax> methods = cleaned.GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>().ToDictionary(m => m.Identifier.Text);

            Assert.AreEqual("#7", GetEntryPoint(methods["FixtureByOrdinal"]));
            Assert.IsNull(GetEntryPoint(methods["FixtureByName"]));
        }

        [TestMethod]
        public void CleanSyntaxTree_ReplacesExistingEntryPoint()
        {
            const string source = @"
using System.Runtime.InteropServices;

namespace Windows.Win32.Fixture
{
    public static unsafe partial class Apis
    {
        [DllImport(""OrdinalFixture"", EntryPoint = ""Other"", ExactSpelling = true)]
        public static extern int FixtureByOrdinal(int value);
    }
}";

            SyntaxTree cleaned = Clean(source, new Dictionary<string, string> { ["FixtureByOrdinal"] = "#7" });

            MethodDeclarationSyntax method = cleaned.GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>().Single(m => m.Identifier.Text == "FixtureByOrdinal");
            AttributeSyntax dllImport = method.AttributeLists.SelectMany(l => l.Attributes).Single(a => a.Name.ToString().EndsWith("DllImport"));
            Assert.AreEqual(1, dllImport.ArgumentList!.Arguments.Count(a => a.NameEquals?.Name.Identifier.Text == "EntryPoint"));
            Assert.AreEqual("#7", GetEntryPoint(method));
        }

        [TestMethod]
        public void EmittedWinmd_ImportsOrdinalOnlyExportByOrdinalAndKeepsManagedName()
        {
            string root = Path.Combine(Path.GetTempPath(), "importentrypoint-" + Guid.NewGuid().ToString("N"));
            string sourceDir = Path.Combine(root, "src");
            string winmdPath = Path.Combine(root, "fixture.winmd");
            string rspPath = Path.Combine(root, "entrypoints.rsp");
            Directory.CreateDirectory(Path.Combine(sourceDir, "x64"));

            try
            {
                File.WriteAllText(Path.Combine(sourceDir, "x64", "fixture.cs"), FixtureSource);
                File.WriteAllText(rspPath, "--importEntryPoint" + Environment.NewLine + "FixtureByOrdinal=#7" + Environment.NewLine);

                int exitCode = Program.Main(new[] { "--sourceDir", sourceDir, "--arch", "x64", "--outputFileName", winmdPath, "@" + rspPath });
                Assert.AreEqual(0, exitCode);

                Dictionary<string, string> imports = ReadImports(winmdPath);
                Assert.AreEqual("#7", imports["FixtureByOrdinal"]);
                Assert.AreEqual("FixtureByName", imports["FixtureByName"]);
            }
            finally
            {
                Directory.Delete(root, true);
            }
        }

        private static SyntaxTree Clean(string source, Dictionary<string, string> importEntryPoints)
        {
            return MetadataSyntaxTreeCleaner.CleanSyntaxTree(
                CSharpSyntaxTree.ParseText(source),
                new Dictionary<string, string>(),
                new Dictionary<string, Dictionary<string, string>>(),
                new HashSet<string>(),
                new Dictionary<string, string>(),
                new Dictionary<string, string>(),
                new Dictionary<string, string>(),
                new HashSet<string>(),
                new HashSet<string>(),
                "test.cs",
                importEntryPoints);
        }

        private static string? GetEntryPoint(MethodDeclarationSyntax method)
        {
            AttributeSyntax dllImport = method.AttributeLists.SelectMany(l => l.Attributes).Single(a => a.Name.ToString().EndsWith("DllImport"));
            AttributeArgumentSyntax? argument = dllImport.ArgumentList!.Arguments.SingleOrDefault(a => a.NameEquals?.Name.Identifier.Text == "EntryPoint");
            return argument == null ? null : ((LiteralExpressionSyntax)argument.Expression).Token.ValueText;
        }

        // Maps each P/Invoke method's name to the name recorded in its ImplMap row.
        private static Dictionary<string, string> ReadImports(string winmdPath)
        {
            using var stream = File.OpenRead(winmdPath);
            using var pe = new PEReader(stream);
            MetadataReader reader = pe.GetMetadataReader();

            var imports = new Dictionary<string, string>();
            foreach (MethodDefinitionHandle handle in reader.MethodDefinitions)
            {
                MethodDefinition method = reader.GetMethodDefinition(handle);
                MethodImport import = method.GetImport();
                if (!import.Module.IsNil)
                {
                    imports[reader.GetString(method.Name)] = reader.GetString(import.Name);
                }
            }

            return imports;
        }
    }
}



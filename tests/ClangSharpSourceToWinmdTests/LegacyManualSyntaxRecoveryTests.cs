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
    public class LegacyManualSyntaxRecoveryTests
    {
        [DataTestMethod]
        [DataRow("(-2147483648U) >> 32", -1L)]
        [DataRow("(-0x80000000) >> 32", -2147483648L)]
        [DataRow("(-0x80000000U) >> 32", -1L)]
        [DataRow("-0x8000000000000000", long.MinValue)]
        [DataRow("-0x8000000000000000L", long.MinValue)]
        [DataRow("(-(0x80000000)) >> 32", -1L)]
        [DataRow("(-0b10000000000000000000000000000000) >> 32", -2147483648L)]
        public void MinimumLiteralRadixSuffixAndParenthesisFollowTheActualCSharpCompiler(string expression, long expected)
        {
            var tree = CSharpSyntaxTree.ParseText("public static class A { public const long V = " + expression + "; }");
            var compilation = CSharpCompilation.Create("MinimumLiteralControl", new[] { tree },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var field = compilation.GetTypeByMetadataName("A")?.GetMembers("V").OfType<IFieldSymbol>().Single();
            Assert.IsNotNull(field);
            Assert.AreEqual(expected, field.ConstantValue);
        }

        [TestMethod]
        public void EnumInitializerReferencesUseUnderlyingValuesInTheActualCSharpCompiler()
        {
            var tree = CSharpSyntaxTree.ParseText(@"
public enum Dependency : uint
{
    High = 0x80000000, Alias = High,
    Combined = High | 0x1FF, Added = Alias + 1U, Qualified = Dependency.High | 1U
}");
            var compilation = CSharpCompilation.Create("EnumInitializerControl", new[] { tree },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var model = compilation.GetSemanticModel(tree);
            var values = tree.GetRoot().DescendantNodes().OfType<EnumMemberDeclarationSyntax>()
                .ToDictionary(member => member.Identifier.ValueText,
                    member => model.GetDeclaredSymbol(member) is IFieldSymbol { HasConstantValue: true } field
                        ? field.ConstantValue : throw new InvalidOperationException("The compiler produced no enum constant."));
            Assert.AreEqual(0x800001FFU, values["Combined"]);
            Assert.AreEqual(0x80000001U, values["Added"]);
            Assert.AreEqual(0x80000001U, values["Qualified"]);
        }

        [TestMethod]
        public void RetainedShellRecoveryPreservesFollowingEnumAndAllMembersInPhysicalLegacyOutput()
        {
            string retained = File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "assets", "Shell.manual.cs"));
            var root = CSharpSyntaxTree.ParseText(retained).GetRoot();
            var method = root.DescendantNodes().OfType<MethodDeclarationSyntax>()
                .Single(declaration => declaration.Identifier.ValueText == "FileIconInit");
            Assert.IsTrue(method.SemicolonToken.IsMissing);
            string[] names = { "SHGFI_FLAGS", "SHOP_TYPE", "SHFMT_OPT" };
            var enums = root.DescendantNodes().OfType<EnumDeclarationSyntax>()
                .Where(declaration => names.Contains(declaration.Identifier.ValueText)).ToArray();
            Assert.AreEqual(3, enums.Length);
            var shop = enums.Single(declaration => declaration.Identifier.ValueText == "SHOP_TYPE");
            Assert.AreEqual(3, shop.Members.Count);
            Assert.AreEqual(2, shop.Members.GetSeparators().Count(separator => separator.IsMissing));
            Assert.AreEqual(1, enums.Single(declaration => declaration.Identifier.ValueText == "SHFMT_OPT")
                .Members.GetSeparators().Count(separator => separator.IsMissing));
            string source = @"using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation;
namespace Windows.Win32.Foundation { public struct BOOL { public int Value; } }
namespace Windows.Win32.UI.Shell
{
    public static unsafe partial class Apis
    {
" + method.ToFullString() + "\n}\n" + string.Join("\n", enums.Select(declaration => declaration.ToFullString())) + "\n}";
            var parseErrors = CSharpSyntaxTree.ParseText(source).GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(4, parseErrors.Length, string.Join(Environment.NewLine, parseErrors.Select(error => error.ToString())));
            string directory = Path.Combine(AppContext.BaseDirectory, "legacy-manual-recovery", Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string path = Path.Combine(directory, "Shell.manual.cs");
                File.WriteAllText(path, source);
                var compilation = ClangSharpSourceCompilation.Create(directory, "crossarch",
                    new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(),
                    Array.Empty<string>(), new Dictionary<string, string>(), new Dictionary<string, string>(),
                    new HashSet<string>(), Array.Empty<string>(), new Dictionary<string, string>(), new Dictionary<string, string>());
                var declarationErrors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
                Assert.AreEqual(0, declarationErrors.Length,
                    string.Join(Environment.NewLine, declarationErrors.Select(error => error.ToString())));
                var remainingParseErrors = compilation.CSharpCompilation.GetParseDiagnostics()
                    .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
                Assert.AreEqual(4, remainingParseErrors.Length);
                string output = Path.Combine(directory, "Test.winmd");
                var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation,
                    new Dictionary<string, string>(), new HashSet<string>(), new HashSet<string>(), new Version(1, 0), output);
                Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
                using var stream = File.OpenRead(output);
                using var pe = new PEReader(stream);
                var reader = pe.GetMetadataReader(MetadataReaderOptions.None);
                var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .ToDictionary(type => reader.GetString(type.Name), StringComparer.Ordinal);
                var actual = reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                    .Single(value => reader.GetString(value.Name) == "FileIconInit");
                Assert.IsTrue(actual.Attributes.HasFlag(System.Reflection.MethodAttributes.PinvokeImpl));
                Assert.AreEqual("#660", reader.GetString(actual.GetImport().Name));
                Assert.AreEqual("SHELL32.dll", reader.GetString(reader.GetModuleReference(actual.GetImport().Module).Name));
                Assert.AreEqual(18, types["SHGFI_FLAGS"].GetFields().Count(handle =>
                    !reader.GetFieldDefinition(handle).GetDefaultValue().IsNil));
                AssertValues("SHOP_TYPE", new Dictionary<string, int>
                {
                    ["SHOP_PRINTERNAME"] = 1, ["SHOP_FILEPATH"] = 2, ["SHOP_VOLUMEGUID"] = 4,
                });
                AssertValues("SHFMT_OPT", new Dictionary<string, int>
                {
                    ["SHFMT_OPT_NONE"] = 0, ["SHFMT_OPT_FULL"] = 1, ["SHFMT_OPT_SYSONLY"] = 2,
                });

                void AssertValues(string typeName, Dictionary<string, int> expected)
                {
                    var fields = types[typeName].GetFields().Select(reader.GetFieldDefinition)
                        .Where(field => !field.GetDefaultValue().IsNil).ToArray();
                    Assert.AreEqual(expected.Count, fields.Length);
                    foreach (var field in fields)
                    {
                        var constant = reader.GetConstant(field.GetDefaultValue());
                        Assert.AreEqual(ConstantTypeCode.Int32, constant.TypeCode);
                        Assert.AreEqual(expected[reader.GetString(field.Name)], reader.GetBlobReader(constant.Value).ReadInt32());
                    }
                }
            }
            finally
            {
                Directory.Delete(directory, recursive: true);
            }
        }
    }
}

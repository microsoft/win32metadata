using System;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    [CollectionDefinition(nameof(GenerationPerformanceCollection), DisableParallelization = true)]
    public sealed class GenerationPerformanceCollection
    {
    }

    [Collection(nameof(GenerationPerformanceCollection))]
    [Trait("Category", "Performance")]
    public sealed class GenerationPerformanceTests : IDisposable
    {
        private const int SampleCount = 5;
        private readonly ITestOutputHelper output;
        private readonly string directory;

        public GenerationPerformanceTests(ITestOutputHelper output)
        {
            this.output = output;
            directory = Path.GetFullPath(Path.Combine("artifacts", "generation-performance-" + Guid.NewGuid().ToString("N")));
            Directory.CreateDirectory(directory);
        }

        [Fact]
        public void IncludedHeaderParameterCommentsStayWithinBudget()
        {
            const int declarationsPerHeader = 1000;
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#include \"input.h\"\n#include \"output.h\"\n",
                extraSettings: "--traverse\ninput.h\noutput.h\n", directoryRoot: directory);
            foreach (bool input in new[] { true, false })
            {
                string declarations = string.Join("\n", Enumerable.Range(0, declarationsPerHeader).Select(index =>
                    $"// \u00e9 {index}\nint {(input ? "Read" : "Save")}{index:D4}(/* [{(input ? "in " : "out")}] */ unsigned* value);"));
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, input ? "input.h" : "output.h"), declarations);
            }
            File.AppendAllText(fixture.Header, "/* Win32Metadata: function ::Read0999 => SetLastError */\n");
            int exitCode = -1;
            Measure("2 included UTF-8 headers / 2,000 parameter annotations", 6000,
                () => exitCode = fixture.Run(), () =>
                {
                    fixture.AssertGeneratorWarnings(exitCode);
                    var methods = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                        .OfType<MethodDeclarationSyntax>().ToArray();
                    Assert.Equal(2 * declarationsPerHeader, methods.Length);
                    Assert.Equal(new[] { "Read", "Save" }.SelectMany(prefix =>
                        Enumerable.Range(0, declarationsPerHeader).Select(index => $"{prefix}{index:D4}")),
                        methods.Select(method => method.Identifier.ValueText).OrderBy(name => name, StringComparer.Ordinal));
                    foreach (var method in methods)
                    {
                        bool input = method.Identifier.ValueText.StartsWith("Read", StringComparison.Ordinal);
                        var parameter = Assert.Single(method.ParameterList.Parameters);
                        Assert.Equal("value", parameter.Identifier.ValueText);
                        string attributes = parameter.AttributeLists.ToString();
                        Assert.Contains(input ? "InteropServices.In" : "InteropServices.Out", attributes);
                        Assert.DoesNotContain(input ? "InteropServices.Out" : "InteropServices.In", attributes);
                    }
                    var lastError = Assert.Single(methods.Where(method => method.AttributeLists.ToString()
                        .Contains("SetLastError = true", StringComparison.Ordinal)));
                    Assert.Equal("Read0999", lastError.Identifier.ValueText);
                }, () => RemoveNativeOutputs(fixture));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void SelectiveMacroBindingStaysWithinBudget(bool associatedMacro)
        {
            const int irrelevantMacros = 8192;
            string declarations = string.Join("\n", Enumerable.Range(0, irrelevantMacros)
                .Select(index => $"#define PERF_UNUSED_{index:D4} ({index}U + 1U)"));
            if (associatedMacro)
                declarations += @"
#define PERF_REQUESTED (1U << 5)
enum _Win32_AssociatedConstant_(PERF_REQUESTED) PERF_FLAGS { PERF_FIRST = 1 };
";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                declarations + "\n_Win32_SetLastError_ int MacroProbe();\n", directoryRoot: directory);
            int exitCode = -1;
            Measure($"8,192 irrelevant macros / {(associatedMacro ? 1 : 0)} requested constants", 3000,
                () => exitCode = fixture.Run(), () =>
                {
                    fixture.AssertGeneratorWarnings(exitCode);
                    var root = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot();
                    var method = Assert.Single(root.DescendantNodes().OfType<MethodDeclarationSyntax>());
                    Assert.Equal("MacroProbe", method.Identifier.ValueText);
                    Assert.Contains("SetLastError = true", method.AttributeLists.ToString());
                    Assert.Empty(root.DescendantNodes().OfType<FieldDeclarationSyntax>());
                    var groups = root.DescendantNodes().OfType<EnumDeclarationSyntax>().ToArray();
                    Assert.Equal(associatedMacro ? 1 : 0, groups.Length);
                    if (associatedMacro)
                    {
                        var group = Assert.Single(groups);
                        Assert.Equal("PERF_FLAGS", group.Identifier.ValueText);
                        Assert.Contains("AssociatedConstant(\"PERF_REQUESTED\")", group.AttributeLists.ToString());
                        Assert.Equal("PERF_FIRST", Assert.Single(group.Members).Identifier.ValueText);
                    }
                    var fields = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot().DescendantNodes()
                        .OfType<FieldDeclarationSyntax>().ToArray();
                    Assert.Equal(associatedMacro ? 1 : 0, fields.Length);
                    if (associatedMacro)
                        AssertUInt32Field(Assert.Single(fields), "PERF_REQUESTED", 32U);
                }, () => RemoveNativeOutputs(fixture));
        }

        [Fact]
        public void NativeIntegerExtractionAcrossProbeBatchesStaysWithinBudget()
        {
            const int constantCount = 8193;
            string declarations = "constexpr unsigned PERF_DECLARED = 23U;\n" +
                string.Join("\n", Enumerable.Range(0, constantCount).Select(index =>
                    $"#define PERF_INTEGER_{index:D4} " + ((index % 3) switch
                    {
                        0 => $"(0xffffffffU + {index + 1}U)",
                        1 => $"((long long)PERF_DECLARED - {index + 1}LL)",
                        _ => $"((1ULL << 63) | ({index}ULL * sizeof(void*)))",
                    }))) + @"
#define PERF_TEXT ""not an integer""
#define PERF_POINTER ((void*)-1)
#define PERF_MISSING (UNDEFINED_PERF_VALUE + 1)
#define PERF_FUNCTION(value) ((value) + 1U)
int NativeConstantProbe();
";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                declarations, extraSettings: "--config\nnative-constant-values\n", directoryRoot: directory);
            int exitCode = -1;
            Measure("8,196 native probes (4096 + 4096 + 4) -> 8,193 integers / 3 rejected macros", 3000,
                () => exitCode = fixture.Run(), () =>
                {
                    fixture.AssertGeneratorWarnings(exitCode);
                    var source = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot();
                    Assert.Equal("NativeConstantProbe", Assert.Single(source.DescendantNodes()
                        .OfType<MethodDeclarationSyntax>()).Identifier.ValueText);
                    AssertUInt32Field(Assert.Single(source.DescendantNodes().OfType<FieldDeclarationSyntax>()),
                        "PERF_DECLARED", 23U);
                    var values = NativeConstantExtractionTests.Read(fixture);
                    Assert.Equal(Architecture.X64, values.Architecture);
                    Assert.Equal("Test", values.Namespace);
                    Assert.Equal(fixture.Output, values.BindingSource);
                    Assert.Equal(fixture.Header, Assert.Single(values.Headers));
                    Assert.Equal(constantCount, values.Constants.Count);
                    var constants = values.Constants.ToDictionary(value => value.NativeName, StringComparer.Ordinal);
                    for (int index = 0; index < constantCount; index++)
                    {
                        string name = $"PERF_INTEGER_{index:D4}";
                        var value = constants[name];
                        Assert.Equal(name, value.Name);
                        Assert.Equal(fixture.Header, value.Header);
                        Assert.True(value.Line > 0);
                        Assert.False(string.IsNullOrEmpty(value.NativeType));
                        string storage = (index % 3) switch { 0 => "uint", 1 => "long", _ => "ulong" };
                        string literal = (index % 3) switch
                        {
                            0 => index.ToString(CultureInfo.InvariantCulture) + "U",
                            1 => (22L - index).ToString(CultureInfo.InvariantCulture) + "L",
                            _ => ((1UL << 63) | ((ulong)index * 8)).ToString(CultureInfo.InvariantCulture) + "UL",
                        };
                        Assert.Equal(storage, value.StorageType);
                        Assert.Equal(literal, value.Value);
                    }
                    Assert.Equal(3, values.Issues.Count);
                    Assert.Contains(values.Issues, issue => issue.Name == "PERF_TEXT" && issue.Reason == "pointer constant");
                    Assert.Contains(values.Issues, issue => issue.Name == "PERF_POINTER" && issue.Reason == "pointer constant");
                    Assert.Contains(values.Issues, issue => issue.Name == "PERF_MISSING" &&
                        issue.Reason == "native diagnostic" && issue.Diagnostics.Length > 0);
                }, () => RemoveNativeOutputs(fixture));
        }

        [Fact]
        public void CrossArchitectureHeaderConstantEmissionStaysWithinBudget()
        {
            const int groupCount = 256;
            foreach (string architecture in new[] { "x86", "x64", "arm64" })
            {
                string profile = Path.Combine(directory, architecture);
                Directory.CreateDirectory(profile);
                string constants = string.Join("\n", Enumerable.Range(0, groupCount).Select(index =>
                    $"public const uint PERF_ALIAS_{index:D4} = PERF_COMMON_{index:D4} + 1U;\n" +
                    $"public const uint PERF_COMMON_{index:D4} = {index}U;\n" +
                    $"public const uint PERF_VARIANT_{index:D4} = {index + (architecture == "x86" ? 4 : 8)}U;"));
                File.WriteAllText(Path.Combine(profile, "Bindings.cs"),
                    "namespace Test { public static partial class Apis {\n" + constants + "\n} }");
                string groups = string.Join("\n", Enumerable.Range(0, groupCount).Select(index =>
                    $"[AssociatedConstant(\"PERF_COMMON_{index:D4}\")] public enum PERF_GROUP_{index:D4} : uint {{ First = 1, Second = 2 }}"));
                File.WriteAllText(Path.Combine(profile, "Bindings.header-types.cs"),
                    HeaderTypesSourceFamily.SuccessMarker + "\nusing Windows.Win32.Foundation.Metadata;\nnamespace Test {\n" + groups + "\n}");
            }
            HeaderAnnotationWinmdTests.MetadataImage image = null;
            Measure("3 profiles x (256 header groups + 768 globals) -> 256 groups + 1,024 globals", 5000,
                () => image = HeaderAnnotationWinmdTests.Emit(directory, "crossarch"), () =>
                {
                    using var current = image;
                    var reader = current.Reader;
                    var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                        .Where(type => reader.GetString(type.Namespace) == "Test")
                        .ToDictionary(type => reader.GetString(type.Name), StringComparer.Ordinal);
                    Assert.Equal(groupCount + 1, types.Count);
                    var fields = types["Apis"].GetFields().Select(reader.GetFieldDefinition)
                        .GroupBy(field => reader.GetString(field.Name)).ToDictionary(group => group.Key, group => group.ToArray());
                    Assert.Equal(groupCount * 3, fields.Count);
                    Assert.Equal(groupCount * 4, fields.Values.Sum(group => group.Length));
                    for (int index = 0; index < groupCount; index++)
                    {
                        var common = Assert.Single(fields[$"PERF_COMMON_{index:D4}"]);
                        Assert.Equal((uint)index, ReadUInt32(reader, common));
                        Assert.Null(ReadArchitectures(reader, common));
                        var alias = Assert.Single(fields[$"PERF_ALIAS_{index:D4}"]);
                        Assert.Equal((uint)index + 1, ReadUInt32(reader, alias));
                        Assert.Null(ReadArchitectures(reader, alias));
                        var variants = fields[$"PERF_VARIANT_{index:D4}"].OrderBy(field => ReadUInt32(reader, field)).ToArray();
                        Assert.Equal(2, variants.Length);
                        Assert.Equal((uint)index + 4, ReadUInt32(reader, variants[0]));
                        Assert.Equal((uint)index + 8, ReadUInt32(reader, variants[1]));
                        Assert.Equal(1, ReadArchitectures(reader, variants[0]));
                        Assert.Equal(6, ReadArchitectures(reader, variants[1]));
                        var group = types[$"PERF_GROUP_{index:D4}"];
                        var members = group.GetFields().Select(reader.GetFieldDefinition).ToArray();
                        Assert.Equal(new[] { "First", "Second", "value__" },
                            members.Select(field => reader.GetString(field.Name)).OrderBy(name => name, StringComparer.Ordinal));
                        Assert.Equal(1U, ReadUInt32(reader, members.Single(field => reader.GetString(field.Name) == "First"), $"PERF_GROUP_{index:D4}"));
                        Assert.Equal(2U, ReadUInt32(reader, members.Single(field => reader.GetString(field.Name) == "Second"), $"PERF_GROUP_{index:D4}"));
                        var attribute = reader.GetCustomAttribute(Assert.Single(group.GetCustomAttributes().Where(handle =>
                            HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "AssociatedConstantAttribute")));
                        var blob = reader.GetBlobReader(attribute.Value);
                        Assert.Equal(1, blob.ReadUInt16());
                        Assert.Equal($"PERF_COMMON_{index:D4}", blob.ReadSerializedString());
                        Assert.Equal(0, blob.ReadUInt16());
                        Assert.Equal(0, blob.RemainingBytes);
                    }
                });
        }

        [Fact]
        public void LargeConstantFileEmissionStaysWithinBudget()
        {
            const int constantCount = 6418;
            string common = Path.Combine(directory, "common");
            Directory.CreateDirectory(common);
            string constants = string.Join("\n", Enumerable.Range(0, constantCount).Select(index =>
                $"public const uint PERF_LARGE_{index:D5} = {index}U;"));
            File.WriteAllText(Path.Combine(common, "NativeConstants.Test.header-types.cs"),
                "namespace Test { public static partial class Apis {\n" + constants + "\n} }");
            HeaderAnnotationWinmdTests.MetadataImage image = null;
            Measure("6,418 constants in one file / 3 profiles -> 6,418 physical globals", 4000,
                () => image = HeaderAnnotationWinmdTests.Emit(directory, "crossarch"), () =>
                {
                    using var current = image;
                    var reader = current.Reader;
                    var api = Assert.Single(reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                        .Where(type => reader.GetString(type.Namespace) == "Test"));
                    Assert.Equal("Apis", reader.GetString(api.Name));
                    var fields = api.GetFields().Select(reader.GetFieldDefinition)
                        .OrderBy(field => reader.GetString(field.Name), StringComparer.Ordinal).ToArray();
                    Assert.Equal(constantCount, fields.Length);
                    for (int index = 0; index < constantCount; index++)
                    {
                        Assert.Equal($"PERF_LARGE_{index:D5}", reader.GetString(fields[index].Name));
                        Assert.Equal((uint)index, ReadUInt32(reader, fields[index]));
                        Assert.Null(ReadArchitectures(reader, fields[index]));
                    }
                });
        }

        private void Measure(string workload, int budgetMilliseconds, Action run, Action validate, Action prepare = null)
        {
            output.WriteLine($"{workload}; median budget {budgetMilliseconds} ms; .NET {Environment.Version}; {Environment.ProcessorCount} logical processors.");
            var samples = new double[SampleCount];
            for (int index = -1; index < SampleCount; index++)
            {
                prepare?.Invoke();
                var stopwatch = Stopwatch.StartNew();
                run();
                stopwatch.Stop();
                output.WriteLine($"{(index < 0 ? "Warm-up" : $"Sample {index + 1}")}: {stopwatch.Elapsed.TotalMilliseconds:F1} ms");
                validate();
                if (index >= 0)
                    samples[index] = stopwatch.Elapsed.TotalMilliseconds;
            }
            double median = samples.OrderBy(value => value).ElementAt(SampleCount / 2);
            string result = $"{workload}: median {median:F1} ms; budget {budgetMilliseconds} ms " +
                $"(samples: {string.Join(", ", samples.Select(value => value.ToString("F1", CultureInfo.InvariantCulture)))} ms).";
            output.WriteLine("PERF " + result);
            Assert.True(median <= budgetMilliseconds, result);
        }

        private static void RemoveNativeOutputs(HeaderAnnotationTests.NativeFixture fixture)
        {
            string outputDirectory = Path.GetDirectoryName(fixture.Output);
            if (Directory.Exists(outputDirectory))
                Directory.Delete(outputDirectory, recursive: true);
        }

        private static void AssertUInt32Field(FieldDeclarationSyntax field, string name, uint expected)
        {
            Assert.Equal("uint", field.Declaration.Type.ToString());
            Assert.True(field.Modifiers.Any(SyntaxKind.ConstKeyword));
            var variable = Assert.Single(field.Declaration.Variables);
            Assert.Equal(name, variable.Identifier.ValueText);
            var value = Assert.IsType<LiteralExpressionSyntax>(variable.Initializer.Value);
            Assert.Equal(expected, Convert.ToUInt32(value.Token.Value, CultureInfo.InvariantCulture));
        }

        private static uint ReadUInt32(MetadataReader reader, FieldDefinition field, string expectedType = "UInt32")
        {
            Assert.True(field.Attributes.HasFlag(FieldAttributes.Public | FieldAttributes.Static | FieldAttributes.Literal | FieldAttributes.HasDefault));
            Assert.Equal(expectedType, field.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null));
            var value = reader.GetConstant(field.GetDefaultValue());
            Assert.Equal(ConstantTypeCode.UInt32, value.TypeCode);
            var blob = reader.GetBlobReader(value.Value);
            uint result = blob.ReadUInt32();
            Assert.Equal(0, blob.RemainingBytes);
            return result;
        }

        private static int? ReadArchitectures(MetadataReader reader, FieldDefinition field)
        {
            var attributes = field.GetCustomAttributes().Where(handle =>
                HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "SupportedArchitectureAttribute").ToArray();
            if (attributes.Length == 0)
                return null;
            var attribute = reader.GetCustomAttribute(Assert.Single(attributes));
            var blob = reader.GetBlobReader(attribute.Value);
            Assert.Equal(1, blob.ReadUInt16());
            int result = blob.ReadInt32();
            Assert.Equal(0, blob.ReadUInt16());
            Assert.Equal(0, blob.RemainingBytes);
            return result;
        }

        public void Dispose() => Directory.Delete(directory, recursive: true);
    }
}

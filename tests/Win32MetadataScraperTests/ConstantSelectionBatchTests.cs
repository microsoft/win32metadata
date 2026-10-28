using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.Json;
using MetadataTasks;
using MetadataUtils;
using Microsoft.Build.Framework;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    public class ConstantSelectionBatchTests : HeaderAnnotationWinmdTests
    {
        private readonly ITestOutputHelper output;

        public ConstantSelectionBatchTests(ITestOutputHelper output) => this.output = output;

        [Fact]
        public void GuidInitializerTuplesPreserveGuidDefinitionsAndNestedCommaScalars()
        {
            const string high = "0x54F39980L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8";
            const string low = "0xE09C77E0L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#define DDVPTYPE_E_HREFH_VREFH " + high + "\n" +
                "#define DDVPTYPE_E_HREFL_VREFL " + low + "\n" +
                "#define BARE_GUID_ALIAS DDVPTYPE_E_HREFH_VREFH\n" +
                "#define PAREN_GUID_ALIAS (DDVPTYPE_E_HREFH_VREFH)\n" +
                "#define NESTED_COMMA (1, (2, 3))\n" +
                "#define ELEVEN_COMMA (1,2,3,4,5,6,7,8,9,10,11)\n" +
                "#define NESTED_ELEVEN_COMMA ((1,2,3,4,5,6,7,8,9,10,11))\n" +
                "#define NESTED_CALL __builtin_choose_expr(1, (4, 5), 0)\nint F();",
                extraSettings: "--config\nnative-constant-values\n", namespaceName: "KernelStreaming");
            fixture.AssertSuccess();
            string input = Path.ChangeExtension(fixture.Output, ".native-constants.json");
            var values = JsonSerializer.Deserialize<NativeConstantValues>(File.ReadAllText(input));
            var scalars = new[]
            {
                (Name: "ELEVEN_COMMA", Value: 11),
                (Name: "NESTED_ELEVEN_COMMA", Value: 11),
                (Name: "PAREN_GUID_ALIAS", Value: 184),
            };
            foreach (string name in new[] { "DDVPTYPE_E_HREFH_VREFH", "DDVPTYPE_E_HREFL_VREFL" })
            {
                Assert.DoesNotContain(values.Constants, value => value.Name == name);
                var route = Assert.Single(values.Routes.Where(value => value.Name == name));
                Assert.Equal("ScannerResolved", route.Route);
                Assert.Equal("Guid", route.Reason);
                Assert.False(route.ValueProbed);
                Assert.False(route.CompilerEvaluated);
            }
            Assert.Equal("3", Assert.Single(values.Constants.Where(value => value.Name == "NESTED_COMMA")).Value);
            Assert.Equal("5", Assert.Single(values.Constants.Where(value => value.Name == "NESTED_CALL")).Value);
            Assert.DoesNotContain(values.Constants, value => value.Name == "BARE_GUID_ALIAS");
            var bareAlias = Assert.Single(values.Routes.Where(value => value.Name == "BARE_GUID_ALIAS"));
            Assert.Equal("ScannerResolved", bareAlias.Route);
            Assert.Equal("simple macro alias", bareAlias.Reason);
            Assert.False(bareAlias.ValueProbed);
            Assert.False(bareAlias.CompilerEvaluated);
            foreach (var scalar in scalars)
            {
                Assert.Equal(scalar.Value.ToString(System.Globalization.CultureInfo.InvariantCulture),
                    Assert.Single(values.Constants.Where(value => value.Name == scalar.Name)).Value);
                var route = Assert.Single(values.Routes.Where(value => value.Name == scalar.Name));
                Assert.Equal("UnresolvedValue", route.Route);
                Assert.NotEqual("Guid", route.Reason);
                Assert.True(route.ValueProbed);
                Assert.True(route.CompilerEvaluated);
            }

            string guidHeader = Path.Combine(fixture.DirectoryPath, "dvp.h");
            File.WriteAllText(guidHeader, "DEFINE_GUID(DDVPTYPE_E_HREFH_VREFH," + high + ");\n" +
                "DEFINE_GUID(DDVPTYPE_E_HREFL_VREFL," + low + ");\n");
            ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", fixture.DirectoryPath,
                "using System; using Windows.Win32.Foundation.Metadata;", new(),
                new() { [fixture.Header] = "KernelStreaming", [guidHeader] = "DirectDraw" },
                new(), new(), new(), new(), new ConstantSelectionOptions { NativeInputs = new[] { input } });
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            foreach (var expected in new[]
            {
                (Name: "DDVPTYPE_E_HREFH_VREFH", Guid: "54F39980-DA60-11CF-9B06-00A0C903A3B8"),
                (Name: "DDVPTYPE_E_HREFL_VREFL", Guid: "E09C77E0-DA60-11CF-9B06-00A0C903A3B8"),
            })
            {
                var owner = Assert.Single(reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => type.GetFields().Select(reader.GetFieldDefinition)
                        .Any(field => reader.GetString(field.Name) == expected.Name)));
                Assert.Equal("DirectDraw", reader.GetString(owner.Namespace));
                var field = Assert.Single(owner.GetFields().Select(reader.GetFieldDefinition)
                    .Where(value => reader.GetString(value.Name) == expected.Name));
                Assert.Equal((FieldAttributes)0, field.Attributes & FieldAttributes.Literal);
                Assert.True(field.GetDefaultValue().IsNil);
                var attribute = reader.GetCustomAttribute(Assert.Single(field.GetCustomAttributes()
                    .Where(handle => AttributeName(reader, handle) == "GuidAttribute")));
                Assert.Equal("0100" + Convert.ToHexString(new Guid(expected.Guid).ToByteArray()) + "0000",
                    Convert.ToHexString(reader.GetBlobBytes(attribute.Value)));
            }
            foreach (var scalar in scalars)
            {
                var owner = Assert.Single(reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => type.GetFields().Select(reader.GetFieldDefinition)
                        .Any(field => reader.GetString(field.Name) == scalar.Name)));
                Assert.Equal("KernelStreaming", reader.GetString(owner.Namespace));
                var field = Assert.Single(owner.GetFields().Select(reader.GetFieldDefinition)
                    .Where(value => reader.GetString(value.Name) == scalar.Name));
                Assert.NotEqual((FieldAttributes)0, field.Attributes & FieldAttributes.Literal);
                var constant = reader.GetConstant(field.GetDefaultValue());
                Assert.Equal(System.Reflection.Metadata.ConstantTypeCode.Int32, constant.TypeCode);
                Assert.Equal(scalar.Value, reader.GetBlobReader(constant.Value).ReadInt32());
                Assert.DoesNotContain(field.GetCustomAttributes(), handle => AttributeName(reader, handle) == "GuidAttribute");
            }
            AssertMetadataClosure(reader);
            this.output.WriteLine($"GUID tuple regression: scraper={fixture.InvocationCount}; physical WinMD emissions=1");
        }

        [Fact]
        public void TwoNativeInputsServeAllSelectionPoliciesAndLogicalOwnershipAssertions()
        {
            using var first = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#include \"sdk/um/infotech.h\"\n#define MEMBER (1U << 2)\n" +
                "_Win32_Enum_(SOURCE_GROUP, unsigned, MEMBER);\nint F();",
                extraSettings: "--config\nnative-constant-values\n");
            string sdk = Path.Combine(first.DirectoryPath, "sdk");
            string original = Path.Combine(sdk, "um", "infotech.h");
            string preferred = Path.Combine(sdk, "um", "devicetopology.h");
            Directory.CreateDirectory(Path.GetDirectoryName(original));
            File.WriteAllText(original, "typedef long HRESULT;\n#define _HRESULT_TYPEDEF_(value) ((HRESULT)(value))\n" +
                "#define E_NOTFOUND _HRESULT_TYPEDEF_(0x8000100DL)\n");
            File.WriteAllText(preferred, "typedef long HRESULT;\n#define ERROR_NOT_FOUND 1168L\n" +
                "#define HRESULT_FROM_WIN32(value) ((HRESULT)((value) <= 0 ? (value) : (((value) & 0xffff) | 0x80070000)))\n" +
                "#define E_NOTFOUND HRESULT_FROM_WIN32(ERROR_NOT_FOUND)\n");
            using var second = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#include \"" + preferred.Replace('\\', '/') + "\"\nint G();",
                extraSettings: "--config\nnative-constant-values\n");
            File.AppendAllText(Path.Combine(first.DirectoryPath, "test.rsp"), "--traverse\n" + original + "\n");
            File.AppendAllText(Path.Combine(second.DirectoryPath, "test.rsp"), "--traverse\n" + preferred + "\n");
            first.AssertSuccess();
            second.AssertSuccess();
            var group = Assert.Single(CSharpSyntaxTree.ParseText(first.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<EnumDeclarationSyntax>());
            Assert.Equal("SOURCE_GROUP", group.Identifier.ValueText);
            var binding = Assert.Single(Assert.Single(NativeConstantGroupProvenance.Read(group).Group.Members).Bindings);
            Assert.Equal("Macro", binding.Kind);
            Assert.Equal("MEMBER", binding.NativeName);
            string extraInput = Path.Combine(Path.GetDirectoryName(first.Output), "Other.native-constants.json");
            File.Copy(Path.ChangeExtension(second.Output, ".native-constants.json"), extraInput);
            var namespaces = new Dictionary<string, string> { ["SOURCE_GROUP"] = "Canonical" };
            foreach (bool explicitPriority in new[] { false, true })
                foreach (bool preferredFirst in new[] { false, true })
                {
                    this.output.WriteLine($"Constant selection policy: explicitPriority={explicitPriority}; preferredFirst={preferredFirst}");
                    var headers = preferredFirst
                        ? new Dictionary<string, string> { [preferred] = "Audio", [original] = "HtmlHelp", [first.Header] = "Origin" }
                        : new Dictionary<string, string> { [original] = "HtmlHelp", [preferred] = "Audio", [first.Header] = "Origin" };
                    var options = new ConstantSelectionOptions
                    {
                        SdkRoot = sdk,
                        HeaderPriority = explicitPriority ? new[] { @"um\devicetopology.h" } : Array.Empty<string>(),
                        NativeInputs = new[] { extraInput, Path.ChangeExtension(first.Output, ".native-constants.json") },
                    };
                    var result = Select();
                    Assert.Contains(result.Output, message => message.StartsWith("warning WMC001:", StringComparison.Ordinal) &&
                        message.Contains("E_NOTFOUND") && message.Contains("TYPE/VALUE CONFLICT"));
                    string reportPath = Path.Combine(first.DirectoryPath, "native-constant-conflicts.json");
                    string reportBytes = File.ReadAllText(reportPath);
                    using var report = JsonDocument.Parse(reportBytes);
                    var decision = report.RootElement.GetProperty("Decisions").EnumerateArray()
                        .Single(value => value.GetProperty("Name").GetString() == "E_NOTFOUND");
                    bool canonical = explicitPriority || preferredFirst;
                    Assert.True(decision.GetProperty("TypeValueConflict").GetBoolean());
                    Assert.True(decision.GetProperty("DistinctNativeDefinitions").GetBoolean());
                    Assert.Equal(canonical ? preferred : original,
                        Path.GetFullPath(decision.GetProperty("Selected").GetProperty("RawHeader").GetString()));
                    var candidates = decision.GetProperty("Candidates").EnumerateArray().ToArray();
                    Assert.Equal(2, candidates.Length);
                    Assert.Single(candidates.Where(value => value.GetProperty("Disposition").GetString() == "selected"));
                    Assert.Single(candidates.Where(value => value.GetProperty("Disposition").GetString() == "discarded-by-policy"));
                    Assert.All(candidates, value =>
                    {
                        Assert.Equal("HRESULT", value.GetProperty("NativeType").GetString());
                        Assert.True(value.GetProperty("Line").GetUInt32() > 0);
                        Assert.True(value.GetProperty("Column").GetUInt32() > 0);
                        Assert.False(string.IsNullOrEmpty(value.GetProperty("Reason").GetString()));
                    });
                    Select();
                    Assert.Equal(reportBytes, File.ReadAllText(reportPath));
                    if (!explicitPriority)
                    {
                        using var image = Emit(first.DirectoryPath, "x64", requiredNamespaces: namespaces);
                        var reader = image.Reader;
                        Assert.Equal("Canonical", reader.GetString(FindType(reader, "SOURCE_GROUP").Namespace));
                        var owners = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                            .Where(type => type.GetFields().Select(reader.GetFieldDefinition)
                                .Any(field => reader.GetString(field.Name) == "MEMBER")).ToArray();
                        Assert.Equal("SOURCE_GROUP", reader.GetString(Assert.Single(owners).Name));
                        var owner = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                            type.GetFields().Select(reader.GetFieldDefinition).Any(field => reader.GetString(field.Name) == "E_NOTFOUND"));
                        Assert.Equal(canonical ? "Audio" : "HtmlHelp", reader.GetString(owner.Namespace));
                        var field = owner.GetFields().Select(reader.GetFieldDefinition)
                            .Single(value => reader.GetString(value.Name) == "E_NOTFOUND");
                        var value = reader.GetConstant(field.GetDefaultValue());
                        Assert.Equal(System.Reflection.Metadata.ConstantTypeCode.Int32, value.TypeCode);
                        Assert.Equal(unchecked((int)(canonical ? 0x80070490 : 0x8000100D)),
                            reader.GetBlobReader(value.Value).ReadInt32());
                        AssertMetadataClosure(reader);
                    }
                    ScraperResults Select() => ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", first.DirectoryPath,
                        "using System; using Windows.Win32.Foundation.Metadata;", new(), headers, namespaces, new(), new(), new(), options);
                }
            this.output.WriteLine($"TOOLCHAIN constant selection: scraper={first.InvocationCount + second.InvocationCount}; physical WinMD emissions=2; managed policy selections=8");
        }

        [Fact]
        public void ChangedOrMissingConstantProducerInputsInvalidateTheCache()
        {
            foreach (string inputName in new[] { "ConstantsScraper.dll", "MetadataUtils.dll", "constants.header.txt" })
                foreach (bool remove in new[] { false, true })
                {
                    string directory = Path.Combine(Path.GetTempPath(), "constant-inputs-" + Guid.NewGuid().ToString("N"));
                    Directory.CreateDirectory(directory);
                    try
                    {
                        string tools = Path.Combine(directory, "tools");
                        Directory.CreateDirectory(tools);
                        string header = Path.Combine(directory, "constants.header.txt");
                        string marker = Path.Combine(directory, "constants.scraped.txt");
                        foreach (string input in new[] { Path.Combine(tools, "ConstantsScraper.dll"), Path.Combine(tools, "MetadataUtils.dll"), header })
                        {
                            File.WriteAllText(input, "");
                            File.SetLastWriteTimeUtc(input, DateTime.UtcNow.AddMinutes(-1));
                        }
                        File.WriteAllText(marker, "");
                        var task = new ScrapeConstants
                        {
                            ToolsBinDir = tools,
                            HeaderTextFile = header,
                            MarkerFileName = marker,
                            ScraperOutputDir = directory,
                            MSBuildProjectDirectory = directory,
                            SdkIncRoot = directory,
                            ResponseFiles = Array.Empty<ITaskItem>(),
                            ManualCs = Array.Empty<ITaskItem>(),
                        };
                        var check = typeof(ScrapeConstants).GetMethod("AreNonPartitionFilesUpToDate", BindingFlags.Instance | BindingFlags.NonPublic);
                        typeof(ScrapeConstants).GetField("loadedPartitions", BindingFlags.Instance | BindingFlags.NonPublic)
                            .SetValue(task, Array.Empty<Partition>());
                        File.WriteAllLines(Path.Combine(directory, "constant-selection-inputs.txt"),
                            new[] { "sdkRoot=" + Path.GetFullPath(directory) });
                        Assert.True(Assert.IsType<bool>(check.Invoke(task, null)));
                        string changed = inputName.EndsWith(".dll", StringComparison.Ordinal) ? Path.Combine(tools, inputName) : header;
                        if (remove)
                            File.Delete(changed);
                        else
                            File.SetLastWriteTimeUtc(changed, File.GetLastWriteTimeUtc(marker).AddSeconds(1));
                        Assert.False(Assert.IsType<bool>(check.Invoke(task, null)));
                    }
                    finally
                    {
                        Directory.Delete(directory, recursive: true);
                    }
                }
        }
    }
}

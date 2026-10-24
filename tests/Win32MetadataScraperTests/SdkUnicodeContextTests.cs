using System;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Text.Json;
using MetadataTasks;
using MetadataUtils;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void SdkUnicodeDefaultsAgreeAcrossHeaderParsingNativeProbesAndWinmd(string architecture, string target)
        {
            const string declarations = @"
#define SHCNF_PATHA 0x0001
#define SHCNF_PRINTERA 0x0002
#define SHCNF_PATHW 0x0005
#define SHCNF_PRINTERW 0x0006
#define LVM_FIRST 0x1000
#define LVM_GETITEMA (LVM_FIRST + 5)
#define LVM_GETITEMW (LVM_FIRST + 75)
#ifdef UNICODE
#define SHCNF_PATH SHCNF_PATHW
#define SHCNF_PRINTER SHCNF_PRINTERW
#define LVM_GETITEM LVM_GETITEMW
#else
#define SHCNF_PATH SHCNF_PATHA
#define SHCNF_PRINTER SHCNF_PRINTERA
#define LVM_GETITEM LVM_GETITEMA
#endif
typedef unsigned short WCHAR;
struct OPTIONS_A { const char* name; unsigned flags; };
struct OPTIONS_W { const WCHAR* name; unsigned flags; };
int __stdcall OpenValueA(const char* name, OPTIONS_A* options);
int __stdcall OpenValueW(const WCHAR* name, OPTIONS_W* options);
#ifdef UNICODE
#define OpenValue OpenValueW
#else
#define OpenValue OpenValueA
#endif
static_assert(sizeof(OPTIONS_A) == 2 * sizeof(void*));
static_assert(sizeof(OPTIONS_W) == sizeof(OPTIONS_A));
static_assert(alignof(OPTIONS_A) == alignof(void*));
static_assert(alignof(OPTIONS_W) == alignof(OPTIONS_A));
static_assert(__builtin_offsetof(OPTIONS_A, flags) == sizeof(void*));
static_assert(__builtin_offsetof(OPTIONS_W, flags) == sizeof(void*));
enum ParsedSelection
{
    ParsedPath = SHCNF_PATH,
    ParsedPrinter = SHCNF_PRINTER,
    ParsedItem = LVM_GETITEM
};
";
            foreach (var context in new[]
            {
                (Name: "sdk-default", SdkDefaults: true, ExplicitAnsi: false, Unicode: true, Annotations: true),
                (Name: "sdk-legacy-default", SdkDefaults: true, ExplicitAnsi: false, Unicode: true, Annotations: false),
                (Name: "custom-ansi", SdkDefaults: false, ExplicitAnsi: false, Unicode: false, Annotations: true),
                (Name: "explicit-ansi", SdkDefaults: true, ExplicitAnsi: true, Unicode: false, Annotations: true),
            })
            {
                using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                    annotationsEnabled: context.Annotations, extraSettings: "--config\nnative-constant-values\n");
                string response = Path.Combine(fixture.DirectoryPath, "test.rsp");
                if (context.SdkDefaults)
                {
                    string compilerSettings = Path.Combine(fixture.DirectoryPath, "sdk.compiler.rsp");
                    var filter = new FilterResponseFiles
                    {
                        ResponseFiles = new[]
                        {
                            new Microsoft.Build.Utilities.TaskItem(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                                "generation", "WinSDK", "scraper.settings.rsp")),
                        },
                        OutputFileName = compilerSettings,
                        ValidSwitches = "--additional",
                        MSBuildProjectDirectory = WinHttpMigrationTests.RepositoryRoot,
                    };
                    Assert.True(filter.Execute());
                    File.AppendAllText(response, "\n@" + compilerSettings + "\n");
                }
                if (context.ExplicitAnsi)
                    File.AppendAllText(response, "--additional\n-UUNICODE\n");
                fixture.AssertSuccess();

                var native = NativeConstantExtractionTests.Read(fixture);
                int path = context.Unicode ? 5 : 1;
                int printer = context.Unicode ? 6 : 2;
                int item = context.Unicode ? 4171 : 4101;
                Assert.Equal(path.ToString(), Assert.Single(native.Constants.Where(value => value.Name == "SHCNF_PATH")).Value);
                Assert.Equal(printer.ToString(), Assert.Single(native.Constants.Where(value => value.Name == "SHCNF_PRINTER")).Value);
                Assert.Equal(item.ToString(), Assert.Single(native.Constants.Where(value => value.Name == "LVM_GETITEM")).Value);
                ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", fixture.DirectoryPath,
                    "using System; using Windows.Win32.Foundation.Metadata;", new(), new() { [fixture.Header] = "Test" },
                    new(), new(), new(), new());
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                AssertValue("ParsedSelection", "ParsedPath", path);
                AssertValue("ParsedSelection", "ParsedPrinter", printer);
                AssertValue("ParsedSelection", "ParsedItem", item);
                foreach (var expected in new[]
                {
                    ("SHCNF_PATH", path), ("SHCNF_PRINTER", printer), ("LVM_GETITEM", item),
                    ("SHCNF_PATHA", 1), ("SHCNF_PRINTERA", 2), ("SHCNF_PATHW", 5), ("SHCNF_PRINTERW", 6),
                    ("LVM_GETITEMA", 4101), ("LVM_GETITEMW", 4171),
                })
                    AssertValue("Apis", expected.Item1, expected.Item2);
                foreach (var variant in new[] { (Suffix: "A", Storage: "SByte*"), (Suffix: "W", Storage: "UInt16*") })
                {
                    string options = "OPTIONS_" + variant.Suffix;
                    var fields = FindType(reader, options).GetFields().Select(reader.GetFieldDefinition)
                        .ToDictionary(field => reader.GetString(field.Name));
                    Assert.Equal(2, fields.Count);
                    Assert.Equal(variant.Storage, fields["name"].DecodeSignature(new SignatureNames(), null));
                    Assert.Equal("UInt32", fields["flags"].DecodeSignature(new SignatureNames(), null));
                    var method = FindType(reader, "Apis").GetMethods().Select(reader.GetMethodDefinition)
                        .Single(value => reader.GetString(value.Name) == "OpenValue" + variant.Suffix);
                    var signature = method.DecodeSignature(new SignatureNames(), null);
                    Assert.Equal("Int32", signature.ReturnType);
                    Assert.Equal(new[] { variant.Storage, options + "*" }, signature.ParameterTypes);
                }
                AssertMetadataClosure(reader);

                string map = Path.Combine(fixture.DirectoryPath, "compiler-context.json");
                File.AppendAllText(response, "--declaration-map\n" + map +
                    "\n--declaration-map-symbol\nParsedSelection\n");
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                using var contextMap = JsonDocument.Parse(File.ReadAllText(map));
                string[] arguments = contextMap.RootElement.GetProperty("arguments").EnumerateArray()
                    .Select(argument => argument.GetString()).ToArray();
                Assert.Equal(context.SdkDefaults, arguments.Contains("-DUNICODE"));
                Assert.Equal(context.ExplicitAnsi, arguments.Contains("-UUNICODE"));
                if (context.ExplicitAnsi)
                    Assert.True(Array.IndexOf(arguments, "-DUNICODE") < Array.IndexOf(arguments, "-UUNICODE"));
                string artifacts = Environment.GetEnvironmentVariable("WIN32_UNICODE_CONTEXT_ARTIFACTS");
                if (artifacts != null)
                    ArchiveCombinedHeaderConstants(artifacts, architecture + "-" + context.Name,
                        fixture.DirectoryPath, reader, architecture);

                void AssertValue(string typeName, string name, int expected)
                {
                    var field = FindType(reader, typeName).GetFields().Select(reader.GetFieldDefinition)
                        .Single(value => reader.GetString(value.Name) == name);
                    var value = reader.GetConstant(field.GetDefaultValue());
                    Assert.Equal(ConstantTypeCode.Int32, value.TypeCode);
                    Assert.Equal(expected, reader.GetBlobReader(value.Value).ReadInt32());
                }
            }
        }
    }
}

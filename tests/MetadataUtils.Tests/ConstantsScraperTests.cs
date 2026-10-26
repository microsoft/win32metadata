using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Abstractions.TestingHelpers;
using System.Linq;
using System.Reflection;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Moq;
using Xunit;

namespace MetadataUtils.Tests
{
    public class ConstantsScraperTests
    {
        [Fact]
        public void ObjectLikeNameScanReusesDefineAndContinuationRulesWithoutEvaluatingValues()
        {
            string source = @"
                #define A 1
                # define EMPTY
                #define EXPRESSION (unknown_template<int>{} + invalid_value)
                #define FUNCTION(x) (x)
                #define OBJECT (x)
                #de\
fine CONTINUED \
                    (1 + 2)
                #if 0
                #define INACTIVE arbitrary tokens
                #endif
                /*
                #define COMMENTED_OUT 1
                */ #/**/define/**/AFTER_COMMENT/**/4
                #define TEXT ""/* not a comment */""
                #define LAST 'x' // trailing comment
                ";
            Assert.Equal(new[] { "A", "EMPTY", "EXPRESSION", "OBJECT", "CONTINUED", "INACTIVE",
                "AFTER_COMMENT", "TEXT", "LAST" },
                ConstantsScraper.ReadObjectLikeMacroNames(source.Split('\n').Select(line => line.TrimEnd('\r'))));
        }

        [Theory]
        [InlineData("ansi", true)]
        [InlineData("unicode", false)]
        [InlineData("", false)]
        public void StringConstantEncodingAttributesHaveValidSyntax(string context, bool hasEncodingAttribute)
        {
            using var stream = new MemoryStream();
            using (var writer = new ConstantWriter(stream, "Test", "", new()))
                writer.AddValue("string", "LIBRARY_NAME", "\"sample.dll\"", context);
            string output = System.Text.Encoding.UTF8.GetString(stream.ToArray());
            Assert.Empty(CSharpSyntaxTree.ParseText(output).GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.Equal(hasEncodingAttribute, output.Contains("[NativeEncoding(\"ansi\")]"));
            Assert.Contains("public const string LIBRARY_NAME = \"sample.dll\";", output);
        }

        [Theory]
        [InlineData("\"one\" \"two\"", "onetwo", true)]
        [InlineData("L\"one\" L\"two\"", "onetwo", false)]
        [InlineData("TEXT(\"one\") TEXT(\"two\")", "onetwo", false)]
        [InlineData("__TEXT(\"one\") NAME \"\\\\end\"", "oneUnit\\end", false)]
        [InlineData("_T(\"one\") NAME", "oneUnit", false)]
        [InlineData("NAME L\"\\\\sub\"", "Unit\\sub", false)]
        [InlineData("\"prefix\\\\\" NAME \"\\\\%s\"", "prefix\\Unit\\%s", true)]
        [InlineData("TEXT(\"prefix\\\\\") NAME", "prefix\\Unit", false)]
        [InlineData("(TEXT(\"one\") NAME)", "oneUnit", false)]
        [InlineData("TEXT(\"a\\\"b\") NAME", "a\"bUnit", false)]
        [InlineData("TEXT(\"\") NAME", "Unit", false)]
        [InlineData("\"{not a block}\"", "{not a block}", true)]
        [InlineData("TEXT(NAME)", "Unit", false)]
        [InlineData("TEXT ( NAME )", "Unit", false)]
        [InlineData("_T(NAME)", "Unit", false)]
        [InlineData("NAME TEXT(\"\\\\\") TEXT(NAME)", "Unit\\Unit", false)]
        public void AdjacentNativeStringTermsPreserveValueAndEncoding(string expression, string expected, bool ansi)
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\strings.h"] = new MockFileData(
                    $"#define VALUE {expression}\n#define NAME \"Unit\"\n"),
            });
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(new() { [@"C:\strings.h"] = "Test.Namespace.Win32" });
            string output = files.GetFile("output.txt").TextContents;
            var compilation = CSharpCompilation.Create("AdjacentStrings", new[]
            {
                CSharpSyntaxTree.ParseText(output),
                CSharpSyntaxTree.ParseText(
                    "namespace Test.Namespace.Win32 { class NativeEncodingAttribute : System.Attribute { " +
                    "public NativeEncodingAttribute(string value) {} } }"),
            }, new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var field = Assert.IsAssignableFrom<IFieldSymbol>(
                Assert.Single(compilation.GetTypeByMetadataName("Test.Namespace.Win32.Apis").GetMembers("VALUE")));
            Assert.Equal(expected, field.ConstantValue);
            Assert.Equal(ansi, field.GetAttributes().Any(attribute => attribute.AttributeClass.Name == "NativeEncodingAttribute"));
        }

        [Fact]
        public void AdjacentStringTermsCannotFormatANumericOperandAsText()
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\strings.h"] = new MockFileData(
                    "#define VALUE L\"prefix\" NUMBER\n#define NUMBER 7\n"),
            });
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(new() { [@"C:\strings.h"] = "Test.Namespace.Win32" });
            var compilation = CSharpCompilation.Create("InvalidAdjacentStrings",
                new[] { CSharpSyntaxTree.ParseText(files.GetFile("output.txt").TextContents) },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));
            Assert.Contains(compilation.GetDiagnostics(),
                diagnostic => diagnostic.Severity == DiagnosticSeverity.Error && diagnostic.Id == "CS0030");
        }

        [Theory]
        [InlineData("\"one\" + 1")]
        [InlineData("TEXT(\"one\")[0]")]
        public void StringArithmeticIsNotReinterpretedAsCSharpConcatenation(string expression)
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\strings.h"] = new MockFileData($"#define VALUE {expression}\n"),
            });
            using var scraper = new TestableConstantsScraper(files);
            var error = Assert.Throws<TargetInvocationException>(() =>
                scraper.ScrapeConstantsFromTraversedFiles(new() { [@"C:\strings.h"] = "Test.Namespace.Win32" }));
            var cause = Assert.IsType<InvalidOperationException>(error.InnerException);
            Assert.Contains("'VALUE'", cause.Message);
            Assert.Contains(@"C:\strings.h", cause.Message);
            Assert.Contains(expression, cause.Message);
        }

        [Theory]
        [InlineData("extern \"C\" {")]
        [InlineData("extern \"C\"")]
        [InlineData("return \"value\"")]
        [InlineData("operator \"\" _suffix")]
        [InlineData("__declspec(uuid(\"example\"))")]
        [InlineData("__TEXT(NAME)")]
        public void QuotedTextInDeclarationAndStatementMacrosIsNotAStringConstant(string expression)
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\strings.h"] = new MockFileData($"#define DECLARATION {expression}\n"),
            });
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(new() { [@"C:\strings.h"] = "Test.Namespace.Win32" });
            Assert.DoesNotContain("DECLARATION =", files.GetFile("output.txt").TextContents);
        }

        [Theory]
        [InlineData("const")]
        [InlineData("static readonly")]
        [InlineData("static")]
        public void ExistingGlobalFieldBindingsOwnTheirConstantNames(string modifiers)
        {
            string directory = Path.Combine(Path.GetTempPath(), "existing-global-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                File.WriteAllText(Path.Combine(directory, "bindings.cs"),
                    "namespace Test { public static partial class Apis { public " + modifiers +
                    " string EXISTING=\"value\"; } }");
                var constants = ScraperUtils.GetConstants(directory, out var mutableGlobals);
                Assert.Equal("string", constants["EXISTING"]);
                Assert.Equal(modifiers == "static", mutableGlobals.Contains("EXISTING"));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [Theory]
        [InlineData("ushort*", "(ushort*)-1")]
        [InlineData("string", "\"value\"")]
        [InlineData("int", "7")]
        public void MacroAliasesToMutableGlobalsAreNotInventedAsConstants(string type, string value)
        {
            string directory = Path.Combine(Path.GetTempPath(), "mutable-global-alias-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string bindings = Path.Combine(directory, "bindings.cs");
                File.WriteAllText(bindings, "namespace Test { public static unsafe partial class Apis { " +
                    $"public static {type} GLOBAL = {value}; public const int CONSTANT = 7; " + "} }");
                string header = Path.Combine(directory, "input.h");
                File.WriteAllText(header, "#define GLOBAL_ALIAS GLOBAL\n#define CONSTANT_ALIAS CONSTANT\n");
                var result = ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", directory, "",
                    new(), new() { [header] = "Test" }, new(), new(), new(), new());
                string output = File.ReadAllText(Path.Combine(directory, "Test.constants.cs"));
                Assert.DoesNotContain("GLOBAL_ALIAS =", output);
                Assert.Contains("public const int CONSTANT_ALIAS = CONSTANT;", output);
                Assert.Contains(result.Output, message => message.Contains("GLOBAL_ALIAS") &&
                    message.Contains("GLOBAL") && message.Contains("mutable") && message.Contains(header));
                var compilation = CSharpCompilation.Create("MutableAliases",
                    new[] { CSharpSyntaxTree.ParseText(File.ReadAllText(bindings)), CSharpSyntaxTree.ParseText(output) },
                    new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                    new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));
                Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [Theory]
        [InlineData(true)]
        [InlineData(false)]
        public void ForwardMacroAliasesKeepCtlCodeValuesIndependentOfHeaderOrder(bool aliasesFirst)
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\aliases.h"] = new MockFileData(
                    "#define DEVICE_BASE DEVICE_TYPE\n" +
                    "#define DEVICE_BASE_ALIAS DEVICE_BASE\n" +
                    "#define IOCTL_SAMPLE CTL_CODE(DEVICE_BASE_ALIAS, 3, METHOD_BUFFERED, FILE_READ_ACCESS)\n"),
                [@"C:\values.h"] = new MockFileData(
                    "#define DEVICE_TYPE 0x00000002\n#define METHOD_BUFFERED 0\n#define FILE_READ_ACCESS 0x0001\n"),
            });
            var headers = new Dictionary<string, string>();
            foreach (string name in aliasesFirst ? new[] { "aliases", "values" } : new[] { "values", "aliases" })
                headers.Add($@"C:\{name}.h", "Test.Namespace.Win32");
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(headers);

            var compilation = CSharpCompilation.Create("ForwardMacroAliases",
                new[] { CSharpSyntaxTree.ParseText(files.GetFile("output.txt").TextContents) },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var type = compilation.GetTypeByMetadataName("Test.Namespace.Win32.Apis");
            foreach (string name in new[] { "DEVICE_BASE", "DEVICE_BASE_ALIAS" })
            {
                var field = Assert.IsAssignableFrom<IFieldSymbol>(Assert.Single(type.GetMembers(name)));
                Assert.Equal(SpecialType.System_UInt32, field.Type.SpecialType);
                Assert.Equal(2u, field.ConstantValue);
            }
            var ioctl = Assert.IsAssignableFrom<IFieldSymbol>(Assert.Single(type.GetMembers("IOCTL_SAMPLE")));
            Assert.Equal(SpecialType.System_UInt32, ioctl.Type.SpecialType);
            Assert.Equal(0x2400Cu, ioctl.ConstantValue);
        }

        [Theory]
        [InlineData(true)]
        [InlineData(false)]
        public void DeferredAliasesDoNotInventCyclicOrMissingProvidersOrReplaceExistingValues(bool providerFirst)
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\aliases.h"] = new MockFileData(
                    "#define FIRST SECOND\n#define SECOND FIRST\n#define MISSING NOT_DEFINED\n" +
                    "#define PRESENT LATER\n" + (providerFirst
                        ? "#define LATER 0x00000002\n#define PRESENT 7\n"
                        : "#define PRESENT 7\n#define LATER 0x00000002\n")),
            });
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(new() { [@"C:\aliases.h"] = "Test.Namespace.Win32" });

            string output = files.GetFile("output.txt").TextContents;
            Assert.Contains("PRESENT = 7;", output);
            Assert.DoesNotContain("FIRST =", output);
            Assert.DoesNotContain("SECOND =", output);
            Assert.DoesNotContain("MISSING =", output);
        }

        [Fact]
        public void DeferredAliasesDoNotStealResolvableDeclarationsFromAnotherHeader()
        {
            string directory = Path.Combine(Path.GetTempPath(), "header-aliases-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string early = Path.Combine(directory, "early.h");
                string later = Path.Combine(directory, "later.h");
                File.WriteAllText(early, "#define ALIAS PROVIDER\n");
                File.WriteAllText(later, "#define PROVIDER 0x00010000\n#define ALIAS PROVIDER\n");
                ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", directory, "",
                    new(), new() { [early] = "Early", [later] = "Later" }, new(), new(), new(), new());
                Assert.False(File.Exists(Path.Combine(directory, "Early.constants.cs")));
                Assert.Contains("public const uint ALIAS = PROVIDER;",
                    File.ReadAllText(Path.Combine(directory, "Later.constants.cs")));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [Theory]
        [InlineData(@"x86\Group.header-types.cs", "Test", false, true, false)]
        [InlineData(@"x64\Group.header-types.cs", "Test", false, true, false)]
        [InlineData(@"arm64\Group.header-types.cs", "Test", false, true, false)]
        [InlineData(@"common\header-types.cs", "Test", false, true, false)]
        [InlineData(@"x64\Group.cs", "Test", false, false, false)]
        [InlineData(@"x64\Group.header-types.modified.cs", "Test", false, false, false)]
        [InlineData(@"x64\Group.header-types.cs", "Foreign", false, false, false)]
        [InlineData(@"x64\Group.header-types.cs", "Foreign", true, true, false)]
        [InlineData(@"x64\Group.header-types.cs", "Test", false, true, true)]
        public void HeaderGroupMemberDoesNotCollideWithIndependentEnum(
            string sourceName, string sourceNamespace, bool routeNamespace, bool succeeds, bool omitLegacyNamespace)
        {
            string directory = Path.Combine(Path.GetTempPath(), "header-constants-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string source = Path.Combine(directory, sourceName);
                Directory.CreateDirectory(Path.GetDirectoryName(source));
                File.WriteAllText(source, $"namespace {sourceNamespace} {{ public enum SOURCE_GROUP : uint {{ MEMBER = 4 }} }}");
                string header = Path.Combine(directory, "test.h");
                File.WriteAllText(header, "#define MEMBER 4\n#define LEGACY_SINGLE 1\n#define LEGACY_DOUBLE 2\n");
                string enums = Path.Combine(directory, "enums.json");
                string legacy = @"{ ""items"": [{
                    ""name"": ""MEMBER"", ""namespace"": ""Test"", ""type"": ""uint"", ""flags"": true,
                    ""autoPopulate"": { ""filter"": ""LEGACY_"", ""header"": ""test.h"" }
                }] }";
                File.WriteAllText(enums, omitLegacyNamespace ? legacy.Replace(@"""namespace"": ""Test"",", "") : legacy);
                var namespaces = new Dictionary<string, string>();
                if (routeNamespace)
                    namespaces.Add("SOURCE_GROUP", "Test");
                Action scrape = () => ConstantsScraper.ScrapeConstants(new[] { enums }, "Test", directory, "",
                    new(), new() { [header] = "Test" }, namespaces, new(), new(), new());
                if (!succeeds)
                {
                    var error = Assert.Throws<InvalidOperationException>(scrape);
                    Assert.Contains("constant with the same name already exists", error.Message);
                    return;
                }
                scrape();
                string output = File.ReadAllText(Path.Combine(directory,
                    omitLegacyNamespace ? "System.SystemServices.enums.cs" : "Test.enums.cs"));
                Assert.Contains("enum MEMBER", output);
                Assert.Contains("LEGACY_SINGLE", output);
                Assert.Contains("LEGACY_DOUBLE", output);
                Assert.DoesNotContain("enum SOURCE_GROUP", output);
                Assert.Contains("MEMBER = 4", File.ReadAllText(Path.Combine(directory, "Test.constants.cs")));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [Theory]

        // No multicharacter literals = no change
        [InlineData(
            "0x3231564E, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x3231564E, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        [InlineData(
            "842094158, 0, 16, 128, 0, 0, 170, 0, 56, 155, 113",
            "842094158, 0, 16, 128, 0, 0, 170, 0, 56, 155, 113"
        )]
        [InlineData(
            "0x3231564E, 0, 16, 128, 0, 0, 0xaa, 0, 56, 155, 113",
            "0x3231564E, 0, 16, 128, 0, 0, 0xaa, 0, 56, 155, 113"
        )]

        // Multicharacter literals with varying amounts of leading/trailing space are
        // transformed into hexadecimal constants
        [InlineData(
            "'802P', 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x38303250, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        [InlineData(
            "'802P' , 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x38303250, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        [InlineData(
            "     '802P', 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x38303250, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        public void GetCanonicalGuidConstantIntegerArgs_VariousGuidConstantForms_CanonicalFormReturned(string actual, string expected)
        {
            // Arrange
            var implType = typeof(ConstantsScraper).GetNestedType("ConstantsScraperImpl", BindingFlags.NonPublic);
            var implInstance = Activator.CreateInstance(implType, true);
            var method = implType.GetMethod("GetCanonicalGuidConstantIntegerArgs", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.InvokeMethod);

            // Act
            actual = method.Invoke(implInstance, new object[] { actual }) as string;

            // Assert
            Assert.Equal(expected, actual);
        }

        [Theory]
        [InlineData("MAKEINTRESOURCE(19)", "[NativeTypeName(\"LPCWSTR\")]", "public const ushort TEST_RESOURCE = 19;")]
        [InlineData("MAKEINTRESOURCE(0)", "[NativeTypeName(\"LPCWSTR\")]", "public const ushort TEST_RESOURCE = 0;")]
        [InlineData("MAKEINTRESOURCE(-42)", "[NativeTypeName(\"LPCWSTR\")]", "public const ushort TEST_RESOURCE = unchecked((ushort) -42);")]
        [InlineData("MAKEINTRESOURCEA(1)", "[NativeTypeName(\"LPCSTR\")]", "public const ushort TEST_RESOURCE = 1;")]
        public void ScrapeConstantsFromTraversedFiles_MakeIntResourceConstantsPresent_UnsignedShortIntegersWritten(string actual, string expectedAttribute, string expectedConst)
        {
            // Arrange
            var mockFileSystem = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                {
                    @"C:\test.h",
                    new MockFileData(
                        @$"
                        /* test.h */
                        #define TEST_RESOURCE {actual}
                        @"
                    )
                }
            });
            var fileMap = new Dictionary<string, string>(new[] {
                new KeyValuePair<string, string>("test.h", "Test.Namespace.Win32")
            });

            // Act
            {
                using var scraper = new TestableConstantsScraper(mockFileSystem);
                scraper.ScrapeConstantsFromTraversedFiles(fileMap);
            }

            // Assert
            Assert.Collection(mockFileSystem.GetFile("output.txt").TextContents.Split("\n"),
                e => { },
                e => { /* namespace */ },
                e => { /* { */ },
                e => { /*   class */ },
                e => { /*   { */ },
                e => Assert.Equal(expectedAttribute, e.Trim()),
                e => Assert.Equal(expectedConst, e.Trim()),
                e => { },
                e => { /*   } */ },
                e => { /* } */ },
                e => { }
            );
        }

        private class TestableConstantsScraper : IDisposable
        {
            private readonly object _instance;
            private readonly System.Reflection.MethodInfo _scrapeConstantsFromTraversedFiles;
            private bool _disposed;

            public TestableConstantsScraper(MockFileSystem mockFileSystem)
            {
                var scraperImplType = typeof(ConstantsScraper).GetNestedType("ConstantsScraperImpl", BindingFlags.NonPublic);
                this._scrapeConstantsFromTraversedFiles = scraperImplType.GetMethod("ScrapeConstantsFromTraversedFiles", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.InvokeMethod);
                this._instance = Activator.CreateInstance(scraperImplType, true);

                var fileSystemProperty = scraperImplType.GetProperty("_fileSystem", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetProperty);
                fileSystemProperty.SetValue(this._instance, mockFileSystem);

                var scraperOutputDirField = scraperImplType.GetField("scraperOutputDir", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                scraperOutputDirField.SetValue(this._instance, @"C:\");

                var regexHelperField = scraperImplType.GetField("regexConstHelper", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                regexHelperField.SetValue(this._instance, Mock.Of<IRegexConstHelper>());

                var writtenConstants = new Dictionary<string, string>();
                var writtenConstantsField = scraperImplType.GetField("writtenConstants", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                writtenConstantsField.SetValue(this._instance, writtenConstants);

                var withTypesField = scraperImplType.GetField("withTypes", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                withTypesField.SetValue(this._instance, new Dictionary<string, string>());

                var requiredNamespaces = new WildcardDictionary(new());
                var requiredNamespacesField = scraperImplType.GetField("requiredNamespaces", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                requiredNamespacesField.SetValue(this._instance, requiredNamespaces);

                var scannedNamesToNamespaces = new Dictionary<string, string>();
                var scannedNamesToNamespacesField = scraperImplType.GetField("scannedNamesToNamespaces", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                scannedNamesToNamespacesField.SetValue(this._instance, scannedNamesToNamespaces);

                var enumMemberNameToEnumObj = new Dictionary<string, List<EnumObject>>();
                var enumMemberNameToEnumObjField = scraperImplType.GetField("enumMemberNameToEnumObj", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                enumMemberNameToEnumObjField.SetValue(this._instance, enumMemberNameToEnumObj);

                var outputStream = mockFileSystem.File.OpenWrite("output.txt");
                var constantWriter = new ConstantWriter(outputStream, "Test.Namespace.Win32", "", new());
                var namespacesToConstantWriters = new Dictionary<string, IConstantWriter>()
                {
                    { "Test.Namespace.Win32", constantWriter }
                };
                var namespacesToConstantWritersField = scraperImplType.GetField("namespacesToConstantWriters", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                namespacesToConstantWritersField.SetValue(this._instance, namespacesToConstantWriters);
            }

            public void ScrapeConstantsFromTraversedFiles(Dictionary<string, string> fileMap)
            {
                this._scrapeConstantsFromTraversedFiles.Invoke(this._instance, new[] { fileMap });
            }

            protected virtual void Dispose(bool disposing)
            {
                if (!this._disposed)
                {
                    if (disposing)
                    {
                        ((IDisposable)this._instance).Dispose();
                    }

                    this._disposed = true;
                }
            }

            public void Dispose()
            {
                this.Dispose(disposing: true);
                GC.SuppressFinalize(this);
            }
        }
    }
}

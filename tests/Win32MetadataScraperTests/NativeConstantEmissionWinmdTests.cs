using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        [Fact]
        public void RelocatedCompilerOutputsResolveTheirCurrentPreparedHeaders()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#define VALUE (40U + 2U)\nint F();", extraSettings: "--config\nnative-constant-values\n");
            fixture.AssertSuccess();
            string relocated = Path.Combine(fixture.DirectoryPath, "relocated");
            string generated = Path.Combine(relocated, "x64");
            Directory.CreateDirectory(generated);
            string header = Path.Combine(relocated, Path.GetFileName(fixture.Header));
            File.Copy(fixture.Header, header);
            foreach (string source in Directory.GetFiles(Path.GetDirectoryName(fixture.Output)))
                if (source.EndsWith(".cs", StringComparison.Ordinal) || source.EndsWith(".native-constants.json", StringComparison.Ordinal))
                    File.Copy(source, Path.Combine(generated, Path.GetFileName(source)));
            ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", relocated,
                "using Windows.Win32.Foundation.Metadata;", new(), new() { [header] = "Test" },
                new(), new(), new(), new());
            Assert.Contains("public const uint VALUE = 42U;",
                File.ReadAllText(Path.Combine(generated, "NativeConstants.Test.header-types.cs")));
            Assert.False(File.Exists(Path.Combine(relocated, "Test.constants.cs")));
        }

        [Fact]
        public void NativeIntegerRecoveryKeepsGuidStringAndResourceProviders()
        {
            const string declarations = @"
typedef const wchar_t* LPCWSTR;
#define MAKEINTRESOURCEW(value) ((LPCWSTR)((unsigned short)(value)))
#define RESOURCE MAKEINTRESOURCEW(19)
#define WIDE_TEXT L""hello""
#define NUMBER (40U + 2U)
#define DEFINE_GUID(name, ...)
DEFINE_GUID(SAMPLE_GUID, 0x12345678, 0x1234, 0x5678, 0x90, 0xab, 0xcd, 0xef, 0x12, 0x34, 0x56, 0x78);
int F();
";
            using var original = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", declarations);
            using var native = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", declarations,
                extraSettings: "--config\nnative-constant-values\n");
            foreach (var fixture in new[] { original, native })
            {
                fixture.AssertSuccess();
                ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", fixture.DirectoryPath,
                    "using System; using Windows.Win32.Foundation.Metadata;", new(), new() { [fixture.Header] = "Test" },
                    new(), new(), new(), new());
            }
            var before = ReadFields(original);
            var after = ReadFields(native);
            foreach (string name in new[] { "RESOURCE", "WIDE_TEXT", "SAMPLE_GUID__scanned__" })
                Assert.Equal(before[name], after[name]);
            using var image = Emit(native, "x64");
            AssertMetadataClosure(image.Reader);
            var number = FindType(image.Reader, "Apis").GetFields().Select(image.Reader.GetFieldDefinition)
                .Single(field => image.Reader.GetString(field.Name) == "NUMBER");
            Assert.Equal(42u, image.Reader.GetBlobReader(image.Reader.GetConstant(number.GetDefaultValue()).Value).ReadUInt32());

            static Dictionary<string, string> ReadFields(HeaderAnnotationTests.NativeFixture fixture) =>
                SyntaxFactory.ParseCompilationUnit(File.ReadAllText(Path.Combine(fixture.DirectoryPath, "Test.constants.cs")))
                    .DescendantNodes().OfType<FieldDeclarationSyntax>()
                    .ToDictionary(field => field.Declaration.Variables.Single().Identifier.ValueText, field => field.ToString());
        }

        [Fact]
        public void CompilerRecoveredMacrosReachPhysicalWinmdWithoutExpressionFixups()
        {
            const string declarations = @"
_Win32_NativeTypedef_ typedef long HRESULT;
constexpr int DECLARED_VALUE = 23;
int F();
#define RESULT ((HRESULT)0x80004005L)
#define WRAP32 (0xffffffffU + 1U)
#define NM_CLICK (NM_FIRST - 2)
#define NM_FIRST (0U - 0U)
#define BIGGEST 0xffffffffffffffffULL
#define POINTER_SIZE sizeof(void*)
#define DECLARED_ALIAS DECLARED_VALUE
#if defined(_WIN64)
#define ONLY_64 64U
#else
#define ONLY_32 32U
#endif
";
            using var first = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc", declarations,
                extraSettings: "--config\nnative-constant-values\n");
            using var second = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", declarations,
                extraSettings: "--config\nnative-constant-values\n");
            using var third = new HeaderAnnotationTests.NativeFixture("arm64", "aarch64-pc-windows-msvc", declarations,
                extraSettings: "--config\nnative-constant-values\n");
            var fixtures = new[] { first, second, third };
            foreach (var fixture in fixtures)
            {
                fixture.AssertSuccess();
                if (fixture == first)
                    continue;
                string directory = Path.Combine(first.DirectoryPath,
                    NativeConstantExtractionTests.Read(fixture).Architecture.ToString().ToLowerInvariant());
                Directory.CreateDirectory(directory);
                foreach (string file in Directory.GetFiles(Path.GetDirectoryName(fixture.Output)))
                    if (file.EndsWith(".cs", StringComparison.Ordinal) || file.EndsWith(".native-constants.json", StringComparison.Ordinal))
                        File.Copy(file, Path.Combine(directory, Path.GetFileName(file)));
            }
            var headers = fixtures.ToDictionary(fixture => fixture.Header, _ => "Test");
            string preamble = "using System; using Windows.Win32.Foundation.Metadata;";
            ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", first.DirectoryPath, preamble,
                new(), headers, new(), new(), new(), new());
            string nativeSource = File.ReadAllText(Path.Combine(first.DirectoryPath, "x86", "NativeConstants.Test.header-types.cs"));
            Assert.Contains("public const uint NM_CLICK = 4294967294U;", nativeSource);
            Assert.DoesNotContain("NM_FIRST -", nativeSource);
            ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", first.DirectoryPath, preamble,
                new(), headers, new(), new(), new(), new());
            Assert.Equal(nativeSource, File.ReadAllText(Path.Combine(first.DirectoryPath, "x86", "NativeConstants.Test.header-types.cs")));

            using var image = Emit(first, "crossarch");
            var reader = image.Reader;
            string artifacts = Environment.GetEnvironmentVariable("WIN32_NATIVE_CONSTANT_ARTIFACTS");
            if (artifacts != null)
                ArchiveCombinedHeaderConstants(artifacts, "compiler-native", first.DirectoryPath, reader);
            var fields = FindType(reader, "Apis").GetFields().Select(reader.GetFieldDefinition)
                .GroupBy(field => reader.GetString(field.Name)).ToDictionary(group => group.Key, group => group.ToArray());
            Assert.Equal(23, ReadInt32(Assert.Single(fields["DECLARED_ALIAS"])));
            Assert.Equal(23, ReadInt32(Assert.Single(fields["DECLARED_VALUE"])));
            Assert.Equal(0u, ReadUInt32(Assert.Single(fields["WRAP32"])));
            Assert.Equal(uint.MaxValue - 1, ReadUInt32(Assert.Single(fields["NM_CLICK"])));
            var result = Assert.Single(fields["RESULT"]);
            Assert.Equal("Test.HRESULT", result.DecodeSignature(new SignatureNames(qualifiedNames: true), null));
            Assert.Equal(-2147467259, ReadInt32(result));
            var biggest = reader.GetConstant(Assert.Single(fields["BIGGEST"]).GetDefaultValue());
            Assert.Equal(ConstantTypeCode.UInt64, biggest.TypeCode);
            Assert.Equal(ulong.MaxValue, reader.GetBlobReader(biggest.Value).ReadUInt64());
            Assert.Equal(2, fields["POINTER_SIZE"].Length);
            Assert.Equal(new[] { "UInt32", "UInt64" }, fields["POINTER_SIZE"].Select(field =>
                field.DecodeSignature(new SignatureNames(), null)).OrderBy(value => value));
            Assert.Equal((int)Architecture.X86, ReadArchitecture(Assert.Single(fields["ONLY_32"])));
            Assert.Equal((int)(Architecture.X64 | Architecture.Arm64), ReadArchitecture(Assert.Single(fields["ONLY_64"])));
            foreach (var field in fields["POINTER_SIZE"])
            {
                bool is32 = field.DecodeSignature(new SignatureNames(), null) == "UInt32";
                Assert.Equal((int)(is32 ? Architecture.X86 : Architecture.X64 | Architecture.Arm64), ReadArchitecture(field));
                var value = reader.GetConstant(field.GetDefaultValue());
                var blob = reader.GetBlobReader(value.Value);
                Assert.Equal(is32 ? 4UL : 8UL, is32 ? blob.ReadUInt32() : blob.ReadUInt64());
            }
            AssertMetadataClosure(reader);

            int ReadInt32(FieldDefinition field)
            {
                var value = reader.GetConstant(field.GetDefaultValue());
                Assert.Equal(ConstantTypeCode.Int32, value.TypeCode);
                return reader.GetBlobReader(value.Value).ReadInt32();
            }
            uint ReadUInt32(FieldDefinition field)
            {
                var value = reader.GetConstant(field.GetDefaultValue());
                Assert.Equal(ConstantTypeCode.UInt32, value.TypeCode);
                return reader.GetBlobReader(value.Value).ReadUInt32();
            }
            int ReadArchitecture(FieldDefinition field)
            {
                var attribute = reader.GetCustomAttribute(Assert.Single(field.GetCustomAttributes().Where(handle =>
                    AttributeName(reader, handle) == "SupportedArchitectureAttribute")));
                var blob = reader.GetBlobReader(attribute.Value);
                Assert.Equal(1, blob.ReadUInt16());
                int architecture = blob.ReadInt32();
                Assert.Equal(0, blob.ReadUInt16());
                Assert.Equal(0, blob.RemainingBytes);
                return architecture;
            }
        }
    }
}

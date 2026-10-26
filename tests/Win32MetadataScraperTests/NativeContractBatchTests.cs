using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using MetadataUtils;
using Win32MetadataScraper;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    public partial class NativeContractBatchTests
    {
        private readonly ITestOutputHelper output;

        public NativeContractBatchTests(ITestOutputHelper output) => this.output = output;

        private const string AdditionalDeclarations = @"
#define BATCH_FIRST 1U
#define BATCH_SECOND (1U << 3)
_Win32_FlagsEnum_(BATCH_OPTIONS, unsigned, BATCH_FIRST, BATCH_SECOND);
enum BATCH_NATIVE_FLAGS : unsigned { BatchRead = 1, BatchWrite = 4 };
/* Win32Metadata: enum ::BATCH_NATIVE_FLAGS => Flags */
struct BATCH_FIELDS { unsigned value; };
_Win32_AnnotateField_(BATCH_FIELDS::value, _Win32_AssociatedEnum_(BATCH_NATIVE_FLAGS));
#pragma pack(push, 1)
struct BATCH_PACKED { unsigned char kind; void* context; };
#pragma pack(pop)
_Win32_ImportLibrary_(""ordinal.dll"", ""#42"") int __stdcall ByOrdinal();
struct __declspec(uuid(""eb0c0ca2-cfc2-4538-a693-314db6fc20f2"")) IOverride {
    virtual int __stdcall Read(_Out_opt_ void** value) = 0;
};
_WIN32META_ANNOTATE_PARAMETER_(IOverride::Read, value, _Win32_Optional_(false) _Win32_ComOutPtr_(true));
_Win32_NativeTypedef_ typedef int BATCH_BOOL;
_Win32_NativeTypedef_ typedef void* BATCH_HANDLE;
_Win32_NativeTypedef_ typedef BATCH_HANDLE* BATCH_PHANDLE;
struct BATCH_OPAQUE;
_Win32_NativeTypedef_ typedef struct BATCH_OPAQUE* BATCH_HOPAQUE;
BATCH_BOOL RoundTripBatch(BATCH_BOOL value, BATCH_HANDLE handle, BATCH_PHANDLE output, BATCH_HOPAQUE opaque);
#define BATCH_WRAP32 (0xffffffffU + 1U)
#define BATCH_POINTER_SIZE sizeof(void*)
#if defined(_WIN64)
#define BATCH_ONLY_64 64U
#else
#define BATCH_ONLY_32 32U
#endif
";

        [Fact]
        public void OneHeaderPerArchitectureExercisesNativeContractsAndPhysicalMetadata()
        {
            var fixtures = new List<(string Architecture, HeaderAnnotationTests.NativeFixture Fixture)>();
            try
            {
                foreach (var (architecture, target) in new[]
                {
                ("x86", "i686-pc-windows-msvc"),
                ("x64", "x86_64-pc-windows-msvc"),
                ("arm64", "aarch64-pc-windows-msvc"),
                })
                {
                    this.output.WriteLine($"Native contract batch: architecture={architecture}; target={target}");
                    string declarations = "#define _WIN32_WINNT 0x0600\n" + Declarations +
                        ScopedDeclarations + AssociatedConstantNativeDeclarations + AdditionalDeclarations;
                    var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                        extraSettings: "--config\nnative-constant-values\n");
                    fixtures.Add((architecture, fixture));
                    fixture.AssertSuccess("FlagEnum", "FlagEnum", "MSInheritance", "MSInheritance");
                    Assert.Equal(NativeSurface(fixture, target, metadataEnabled: false),
                        NativeSurface(fixture, target, metadataEnabled: true));
                    using var image = Emit(fixture, architecture);
                    var reader = image.Reader;
                    AssertNativeHeaders(fixture, reader);

                    foreach (string name in new[] { "SCOPED_RECORD", "SCOPED_ENUM", "SCOPED_TOKEN", "PFN_SCOPED" })
                        AssertStringAttribute(reader, FindType(reader, name).GetCustomAttributes(),
                            "SupportedOSPlatformAttribute", "windows6.0.6000");
                    AssertStringAttribute(reader, FindMethod(reader, "Apis", "Seven").GetCustomAttributes(),
                        "SupportedOSPlatformAttribute", "windows6.1");
                    AssertDoesNotHaveAttribute(reader, FindMethod(reader, "Apis", "AfterScope").GetCustomAttributes(),
                        "SupportedOSPlatformAttribute");

                    foreach (string name in new[] { "BATCH_OPTIONS", "BATCH_NATIVE_FLAGS", "CLSCTX" })
                    {
                        var type = FindType(reader, name);
                        AssertHasAttribute(reader, type.GetCustomAttributes(), "FlagsAttribute");
                        AssertDoesNotHaveAttribute(reader, type.GetCustomAttributes(), "ScopedEnumAttribute");
                    }
                    AssertConstant(reader, "BATCH_OPTIONS", "BATCH_FIRST", 1);
                    AssertConstant(reader, "BATCH_OPTIONS", "BATCH_SECOND", 8);
                    AssertConstant(reader, "Apis", "CLSCTX_ALL", 23);
                    AssertConstant(reader, "Apis", "CLSCTX_SERVER", 21);
                    foreach (int index in Enumerable.Range(0, 4))
                        AssertConstant(reader, "Apis", index == 0 ? "D3DTS_WORLD" : "D3DTS_WORLD" + index, 256 + index);
                    Assert.DoesNotContain(reader.FieldDefinitions.Select(reader.GetFieldDefinition),
                        field => reader.GetString(field.Name).StartsWith("UNRELATED_", StringComparison.Ordinal));

                    var field = Assert.Single(FindType(reader, "BATCH_FIELDS").GetFields());
                    AssertStringAttribute(reader, reader.GetFieldDefinition(field).GetCustomAttributes(),
                        "AssociatedEnumAttribute", "BATCH_NATIVE_FLAGS");
                    Assert.Equal("UInt32", reader.GetFieldDefinition(field).DecodeSignature(new SignatureNames(), null));
                    var packed = FindType(reader, "BATCH_PACKED");
                    Assert.Equal(1, packed.GetLayout().PackingSize);
                    Assert.Equal(new[] { "Byte", "Void*" }, packed.GetFields().Select(handle =>
                        reader.GetFieldDefinition(handle).DecodeSignature(new SignatureNames(), null)));
                    var import = FindMethod(reader, "Apis", "ByOrdinal").GetImport();
                    Assert.Equal("ordinal.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));
                    Assert.Equal("#42", reader.GetString(import.Name));
                    var parameter = FindMethod(reader, "IOverride", "Read").GetParameters().Select(reader.GetParameter).Single();
                    Assert.True(parameter.Attributes.HasFlag(ParameterAttributes.Out));
                    Assert.False(parameter.Attributes.HasFlag(ParameterAttributes.Optional));
                    AssertHasAttribute(reader, parameter.GetCustomAttributes(), "ComOutPtrAttribute");
                    foreach (var (name, storage) in new[]
                    {
                    ("BATCH_BOOL", "Int32"), ("BATCH_HANDLE", "Void*"),
                    ("BATCH_PHANDLE", "Void**"), ("BATCH_HOPAQUE", "Void*"),
                })
                    {
                        var type = FindType(reader, name);
                        AssertHasAttribute(reader, type.GetCustomAttributes(), "NativeTypedefAttribute");
                        Assert.Equal(storage, reader.GetFieldDefinition(Assert.Single(type.GetFields()))
                            .DecodeSignature(new SignatureNames(), null));
                    }
                    var signature = FindMethod(reader, "Apis", "RoundTripBatch").DecodeSignature(new SignatureNames(), null);
                    Assert.Equal("BATCH_BOOL", signature.ReturnType);
                    Assert.Equal(new[] { "BATCH_BOOL", "BATCH_HANDLE", "BATCH_PHANDLE", "BATCH_HOPAQUE" }, signature.ParameterTypes);
                    AssertMetadataClosure(reader);
                    this.output.WriteLine($"TOOLCHAIN {architecture}: scraper={fixture.InvocationCount}; native ABI parses=2; physical WinMD emissions=1");
                }
                var first = fixtures[0].Fixture;
                foreach (var (architecture, fixture) in fixtures.Skip(1))
                {
                    string destination = Path.Combine(first.DirectoryPath, architecture);
                    Directory.CreateDirectory(destination);
                    foreach (string file in Directory.GetFiles(Path.GetDirectoryName(fixture.Output)))
                        if (file.EndsWith(".cs", StringComparison.Ordinal) || file.EndsWith(".native-constants.json", StringComparison.Ordinal))
                            File.Copy(file, Path.Combine(destination, Path.GetFileName(file)));
                }
                ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", first.DirectoryPath,
                    "using System; using Windows.Win32.Foundation.Metadata;", new(),
                    fixtures.ToDictionary(value => value.Fixture.Header, _ => "Test"), new(), new(), new(), new());
                using var combined = Emit(first, "crossarch");
                AssertNativeHeaders(first, combined.Reader);
                AssertConstant(combined.Reader, "Apis", "BATCH_WRAP32", 0);
                var fields = FindType(combined.Reader, "Apis").GetFields().Select(combined.Reader.GetFieldDefinition)
                    .GroupBy(field => combined.Reader.GetString(field.Name)).ToDictionary(group => group.Key, group => group.ToArray());
                Assert.Equal(2, fields["BATCH_POINTER_SIZE"].Length);
                foreach (var field in fields["BATCH_POINTER_SIZE"])
                {
                    bool is32 = field.DecodeSignature(new SignatureNames(), null) == "UInt32";
                    Assert.Equal(is32 ? 1 : 6, ReadArchitecture(combined.Reader, field));
                    var value = combined.Reader.GetConstant(field.GetDefaultValue());
                    var blob = combined.Reader.GetBlobReader(value.Value);
                    Assert.Equal(is32 ? 4UL : 8UL, is32 ? blob.ReadUInt32() : blob.ReadUInt64());
                }
                Assert.Equal(1, ReadArchitecture(combined.Reader, Assert.Single(fields["BATCH_ONLY_32"])));
                Assert.Equal(6, ReadArchitecture(combined.Reader, Assert.Single(fields["BATCH_ONLY_64"])));
                AssertMetadataClosure(combined.Reader);
                this.output.WriteLine("TOOLCHAIN crossarch: reused all 3 native inputs; physical WinMD emissions=1; managed constant selection=1");
            }
            finally
            {
                foreach (var (_, fixture) in fixtures)
                    fixture.Dispose();
            }
        }

        [Fact]
        public void InvalidNativeFactsFailClosedWithoutPublishingBindings()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
_WIN32META_ANNOTATION_(""FutureFact"") int Unknown();
_Win32_SetLastError_ typedef int Misplaced;
_Win32_SetLastError_ _Win32_SetLastError_ int Duplicate();
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains("FutureFact", fixture.Diagnostics);
            Assert.Contains("not valid on", fixture.Diagnostics);
            Assert.Contains("Duplicate", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
            this.output.WriteLine($"TOOLCHAIN fail-closed: scraper={fixture.InvocationCount}");
        }

        [Fact]
        public void DisabledCAnnotationsDoNotRequireMetadataNamesOrEmitTransport()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
_Win32_AnnotateField_(Missing::value, _Win32_AssociatedEnum_(MissingEnum));
_WIN32META_ANNOTATE_METHOD_(Missing::Run, _Win32_PreserveResult_);
int Ordinary(void);
", annotationsEnabled: false, extraSettings: "--language\nc\n--std\nc11\n");
            fixture.AssertSuccess();
            Assert.DoesNotContain("NativeAnnotation", fixture.ReadSource());
            Assert.DoesNotContain("_WIN32META_", fixture.ReadSource());
            this.output.WriteLine($"TOOLCHAIN disabled-C: scraper={fixture.InvocationCount}");
        }

        [Fact]
        public void PayloadValidationRunsInMemoryInsteadOfLaunchingTheCompilerPerString()
        {
            foreach (string payload in new[]
            {
                "SetLastError()", "Flags()", "Flags(true)", "Flags(unsigned)", "Retained(1)",
                "Reserved()", "ContainsInteriorPointers=value", "RAIIFree()", "RAIIFree(Close, )",
                "RAIIFree(Close, (0)", "RAIIFree(Close, [))", "AssociatedEnum", "Field",
                "ImportLibrary(\"\")", "ImportLibrary(\"x.dll\", \"#0\")",
                "ImportLibrary(\"x.dll\", \"#65536\")", "ImportLibrary(\"x.dll\", \"#not-an-ordinal\")",
                "SupportedOSPlatform(\"windows10.0.99999\")", "Optional", "Optional()", "Optional(1)",
                "Optional(TRUE)", "Optional(\"false\")", "ComOutPtr(false, true)",
                "ComOutPtr(true || false)", "Unsupported",
            })
            {
                var error = Record.Exception(() => HeaderAnnotation.Parse(payload));
                Assert.True(error?.GetType() == typeof(FormatException), $"Expected FormatException for payload '{payload}'; actual: {error}");
            }
            foreach (string payload in new[] { "Flags", "Win32Metadata.Flags" })
            {
                this.output.WriteLine("Valid payload: " + payload);
                var annotation = HeaderAnnotation.Parse(payload);
                Assert.Equal("Flags", annotation.Name);
                Assert.Empty(annotation.Arguments);
            }
            foreach (var (payload, name, argument) in new[]
            {
                ("Optional(true)", "Optional", "true"), ("Optional(false)", "Optional", "false"),
                ("Win32Metadata.ComOutPtr(true)", "ComOutPtr", "true"), ("ComOutPtr(false)", "ComOutPtr", "false"),
            })
            {
                this.output.WriteLine("Valid payload: " + payload);
                var annotation = HeaderAnnotation.Parse(payload);
                Assert.Equal(name, annotation.Name);
                Assert.Equal(argument, Assert.Single(annotation.Arguments));
            }
        }

        [Fact]
        public void NativeIntegrationUsesBatchesInsteadOfInheritedScenarioTheories()
        {
            var nativeClasses = typeof(HeaderAnnotationWinmdTests).Assembly.GetTypes()
                .Where(type => !type.IsAbstract && typeof(HeaderAnnotationWinmdTests).IsAssignableFrom(type)).ToArray();
            var nativeTests = nativeClasses.SelectMany(type => type.GetMethods(BindingFlags.Public | BindingFlags.Instance))
                .Where(method => method.IsDefined(typeof(FactAttribute), inherit: true)).ToArray();
            Assert.InRange(nativeTests.Length, 1, 10);
            Assert.DoesNotContain(nativeTests, method => method.IsDefined(typeof(TheoryAttribute), inherit: true));
            Assert.Empty(typeof(HeaderAnnotationWinmdTests).GetMethods(BindingFlags.Public | BindingFlags.NonPublic |
                BindingFlags.Instance | BindingFlags.Static).Where(method => method.IsDefined(typeof(FactAttribute), inherit: true)));
        }

        private static void AssertConstant(MetadataReader reader, string type, string name, long expected)
        {
            var field = FindType(reader, type).GetFields().Select(reader.GetFieldDefinition)
                .Single(value => reader.GetString(value.Name) == name);
            Assert.True(field.Attributes.HasFlag(FieldAttributes.Literal | FieldAttributes.HasDefault | FieldAttributes.Static));
            var constant = reader.GetConstant(field.GetDefaultValue());
            var blob = reader.GetBlobReader(constant.Value);
            long actual = constant.TypeCode switch
            {
                ConstantTypeCode.Int32 => blob.ReadInt32(),
                ConstantTypeCode.UInt32 => blob.ReadUInt32(),
                _ => throw new InvalidOperationException("Unexpected constant storage: " + constant.TypeCode),
            };
            Assert.Equal(expected, actual);
        }

        private static int ReadArchitecture(MetadataReader reader, FieldDefinition field)
        {
            var attribute = reader.GetCustomAttribute(Assert.Single(field.GetCustomAttributes()
                .Where(handle => AttributeName(reader, handle) == "SupportedArchitectureAttribute")));
            var blob = reader.GetBlobReader(attribute.Value);
            Assert.Equal(1, blob.ReadUInt16());
            int value = blob.ReadInt32();
            Assert.Equal(0, blob.ReadUInt16());
            Assert.Equal(0, blob.RemainingBytes);
            return value;
        }
    }
}

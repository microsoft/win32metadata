using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Security.Cryptography;
using System.Text.Json;
using ClangSharpSourceToWinmd;
using Xunit;

namespace Win32MetadataScraperTests
{
    public abstract partial class HeaderAnnotationWinmdTests
    {

        internal static uint ReadCombinedHeaderConstant(MetadataReader reader, FieldDefinition field)
        {
            Assert.True(field.Attributes.HasFlag(FieldAttributes.Public | FieldAttributes.Static | FieldAttributes.Literal | FieldAttributes.HasDefault));
            Assert.Equal("UInt32", field.DecodeSignature(new SignatureNames(), null));
            var value = reader.GetConstant(field.GetDefaultValue());
            Assert.Equal(ConstantTypeCode.UInt32, value.TypeCode);
            return reader.GetBlobReader(value.Value).ReadUInt32();
        }

        internal static int? ReadCombinedHeaderConstantArchitectures(MetadataReader reader, CustomAttributeHandleCollection attributes)
        {
            var handles = attributes.Where(handle => AttributeName(reader, handle) == "SupportedArchitectureAttribute").ToArray();
            if (handles.Length == 0)
                return null;
            var attribute = reader.GetCustomAttribute(Assert.Single(handles));
            var blob = reader.GetBlobReader(attribute.Value);
            Assert.Equal(1, blob.ReadUInt16());
            int value = blob.ReadInt32();
            Assert.Equal(0, blob.ReadUInt16());
            Assert.Equal(0, blob.RemainingBytes);
            return value;
        }

        internal static void ArchiveCombinedHeaderConstants(string artifacts, string name, string directory, MetadataReader reader,
            string architecture = "crossarch")
        {
            string destination = Path.Combine(artifacts, name);
            Assert.False(Directory.Exists(destination), "Preserve previous physical attempts.");
            Directory.CreateDirectory(destination);
            foreach (string file in Directory.EnumerateFiles(directory, "*", SearchOption.AllDirectories))
            {
                string target = Path.Combine(destination, Path.GetRelativePath(directory, file));
                Directory.CreateDirectory(Path.GetDirectoryName(target));
                File.Copy(file, target);
            }
            File.WriteAllText(Path.Combine(destination, "physical.json"), JsonSerializer.Serialize(new
            {
                architecture,
                image = "Test.winmd",
                imageSha256 = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(Path.Combine(directory, "Test.winmd")))),
                fields = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => reader.GetString(type.Name) == "Apis")
                    .SelectMany(type => type.GetFields().Select(reader.GetFieldDefinition).Select(field => new
                    {
                        @namespace = reader.GetString(type.Namespace),
                        name = reader.GetString(field.Name),
                        storage = field.DecodeSignature(new SignatureNames(), null),
                        attributes = field.Attributes.ToString(),
                        constantType = reader.GetConstant(field.GetDefaultValue()).TypeCode.ToString(),
                        valueBits = Convert.ToHexString(reader.GetBlobBytes(reader.GetConstant(field.GetDefaultValue()).Value)),
                        supportedArchitecture = ReadCombinedHeaderConstantArchitectures(reader, field.GetCustomAttributes()),
                    })),
                runtime = new[] { typeof(HeaderAnnotationTests).Assembly, typeof(ClangSharpSourceWinmdGenerator).Assembly,
                    typeof(global::Win32MetadataScraper.HeaderAnnotationProcessor).Assembly }.Select(assembly => new
                    {
                        path = assembly.Location,
                        sha256 = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(assembly.Location))),
                    }),
            }, new JsonSerializerOptions { WriteIndented = true }));
        }
    }
    public class HeaderConstantCrossArchWinmdTests : HeaderAnnotationWinmdTests
    {
        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void AssociatedConstantMacrosComposePhysicalArchitectureValues(bool limitedTo64Bit)
        {
            string declarations = @"
#define ALWAYS 0U
enum _Win32_AssociatedConstant_(ALWAYS) BASE_E { BASE_ZERO = 0 };
#ifdef _WIN64
#define EXTRA 2U
" + (limitedTo64Bit ? @"
enum _Win32_AssociatedConstant_(EXTRA) E { E_ZERO = 0 };
#endif
" : @"
#else
#define EXTRA 1U
#endif
enum _Win32_AssociatedConstant_(EXTRA) E { E_ZERO = 0 };
");
            string artifacts = Environment.GetEnvironmentVariable("WIN32_HEADER_CONSTANT_CROSSARCH_ARTIFACTS");
            string fixtures = Path.Combine(artifacts ?? AppContext.BaseDirectory, "header-constant-crossarch-fixtures");
            using var x86 = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc",
                declarations, directoryRoot: fixtures);
            using var x64 = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                declarations, directoryRoot: fixtures);
            using var arm64 = new HeaderAnnotationTests.NativeFixture("arm64", "aarch64-pc-windows-msvc",
                declarations, directoryRoot: fixtures);
            foreach (var fixture in new[] { x86, x64, arm64 })
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                Assert.True(File.Exists(Path.ChangeExtension(fixture.Output, ".header-types.cs")));
                if (artifacts != null)
                {
                    string profile = Path.GetFileName(Path.GetDirectoryName(fixture.Output));
                    string native = Path.Combine(x86.DirectoryPath, "native-inputs", profile);
                    Directory.CreateDirectory(native);
                    foreach (string path in Directory.GetFiles(fixture.DirectoryPath))
                        File.Copy(path, Path.Combine(native, Path.GetFileName(path)));
                    File.WriteAllText(Path.Combine(native, "diagnostics.txt"), fixture.Diagnostics);
                }
                if (fixture == x86)
                    continue;
                string architecture = Path.GetFileName(Path.GetDirectoryName(fixture.Output));
                string directory = Path.Combine(x86.DirectoryPath, architecture);
                Directory.CreateDirectory(directory);
                foreach (string path in new[] { fixture.Output, Path.ChangeExtension(fixture.Output, ".header-types.cs") })
                    File.Copy(path, Path.Combine(directory, Path.GetFileName(path)));
            }
            using var image = Emit(x86, "crossarch");
            var reader = image.Reader;
            if (artifacts != null)
                ArchiveCombinedHeaderConstants(artifacts, limitedTo64Bit ? "limited" : "varying", x86.DirectoryPath, reader);
            var api = FindType(reader, "Apis");
            Assert.Equal("Test", reader.GetString(api.Namespace));
            var fields = api.GetFields().Select(reader.GetFieldDefinition).ToArray();
            var always = Assert.Single(fields.Where(field => reader.GetString(field.Name) == "ALWAYS"));
            Assert.Equal(0U, ReadCombinedHeaderConstant(reader, always));
            AssertDoesNotHaveAttribute(reader, always.GetCustomAttributes(), "SupportedArchitectureAttribute");
            var extras = fields.Where(field => reader.GetString(field.Name) == "EXTRA")
                .OrderBy(field => ReadCombinedHeaderConstant(reader, field)).ToArray();
            Assert.Equal(limitedTo64Bit ? 1 : 2, extras.Length);
            Assert.Equal(limitedTo64Bit ? new uint[] { 2 } : new uint[] { 1, 2 },
                extras.Select(field => ReadCombinedHeaderConstant(reader, field)));
            Assert.Equal(limitedTo64Bit ? new int?[] { 6 } : new int?[] { 1, 6 },
                extras.Select(field => ReadCombinedHeaderConstantArchitectures(reader, field.GetCustomAttributes())));
            Assert.Equal(fields.Length, 1 + extras.Length);
            var enumeration = FindType(reader, "E");
            AssertStringAttribute(reader, enumeration.GetCustomAttributes(), "AssociatedConstantAttribute", "EXTRA");
            Assert.Equal(limitedTo64Bit ? 6 : (int?)null,
                ReadCombinedHeaderConstantArchitectures(reader, enumeration.GetCustomAttributes()));
            AssertMetadataClosure(reader);
        }
    }
}

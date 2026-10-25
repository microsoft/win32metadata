using System;
using System.Linq;
using System.Reflection.Metadata;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++")]
        public void NativeTypedefIncompleteRecordStorageDoesNotCreateBackingRecords(
            string architecture, string target, string language)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
struct INCOMPLETE;
typedef struct INCOMPLETE* COOKIE;
_Win32_NativeTypedef_ typedef COOKIE COOKIE;
typedef const struct INCOMPLETE* READ_ONLY_COOKIE;
/* Win32Metadata: type ::READ_ONLY_COOKIE => NativeTypedef */
_Win32_NativeTypedef_ typedef volatile struct INCOMPLETE* VOLATILE_COOKIE;
_Win32_NativeTypedef_ typedef struct INCOMPLETE* const CONST_COOKIE;
_Win32_NativeTypedef_ typedef COOKIE* DOUBLE_COOKIE;
_Win32_NativeTypedef_ typedef DOUBLE_COOKIE* TRIPLE_COOKIE;
union INCOMPLETE_UNION;
_Win32_NativeTypedef_ typedef union INCOMPLETE_UNION* UNION_COOKIE;
typedef char COOKIE_WIDTH[(sizeof(COOKIE) == sizeof(void*)) ? 1 : -1];
typedef char DOUBLE_COOKIE_WIDTH[(sizeof(DOUBLE_COOKIE) == sizeof(void*)) ? 1 : -1];
typedef char TRIPLE_COOKIE_WIDTH[(sizeof(TRIPLE_COOKIE) == sizeof(void*)) ? 1 : -1];
struct HOLDER { COOKIE value; DOUBLE_COOKIE output; TRIPLE_COOKIE indirect; };
COOKIE OpenCookie(void);
void UseCookie(COOKIE value, COOKIE* output, DOUBLE_COOKIE indirect, TRIPLE_COOKIE deepest,
    READ_ONLY_COOKIE readOnly, VOLATILE_COOKIE changing, UNION_COOKIE alternate);
", extraSettings: "--config\nexclude-empty-records\n--language\n" + language +
                "\n--std\n" + (language == "c" ? "c11" : "c++17") + "\n");
            try
            {
                Assert.Equal(NativeSurface(fixture, target, false, language), NativeSurface(fixture, target, true, language));
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                var wrappers = ReadOpaqueRecordSources(fixture).SelectMany(root =>
                    root.DescendantNodes().OfType<StructDeclarationSyntax>()).ToArray();
                Assert.DoesNotContain(wrappers, type => type.Identifier.ValueText is "INCOMPLETE" or "INCOMPLETE_UNION");
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                foreach (var (name, depth) in new[]
                {
                    ("COOKIE", 1), ("READ_ONLY_COOKIE", 1), ("VOLATILE_COOKIE", 1), ("CONST_COOKIE", 1),
                    ("DOUBLE_COOKIE", 2), ("TRIPLE_COOKIE", 3), ("UNION_COOKIE", 1),
                })
                {
                    AssertNativeTypedefStorage(reader, name, "Void" + new string('*', depth));
                    var field = reader.GetFieldDefinition(Assert.Single(FindType(reader, name).GetFields()));
                    Assert.Equal(new byte[] { 0x06 }.Concat(Enumerable.Repeat((byte)0x0f, depth)).Append((byte)0x01),
                        reader.GetBlobBytes(field.Signature));
                }
                Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                    type => reader.GetString(type.Name) is "INCOMPLETE" or "INCOMPLETE_UNION");
                Assert.DoesNotContain(reader.TypeReferences.Select(reader.GetTypeReference),
                    type => reader.GetString(type.Name) is "INCOMPLETE" or "INCOMPLETE_UNION");
                Assert.Equal("COOKIE", FindMethod(reader, "Apis", "OpenCookie")
                    .DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "COOKIE", "COOKIE*", "DOUBLE_COOKIE", "TRIPLE_COOKIE",
                    "READ_ONLY_COOKIE", "VOLATILE_COOKIE", "UNION_COOKIE" },
                    FindMethod(reader, "Apis", "UseCookie").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                Assert.Equal(new[] { "COOKIE", "DOUBLE_COOKIE", "TRIPLE_COOKIE" }, FindType(reader, "HOLDER").GetFields()
                    .Select(reader.GetFieldDefinition).Select(field => field.DecodeSignature(new SignatureNames(), null)));
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "incomplete-typedef-" + architecture + "-" + language);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void IncompleteNativeTypedefStorageDoesNotEraseOrdinaryRecordPointers(
            string architecture, string target, bool annotations)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
struct EXPOSED;
_Win32_NativeTypedef_ typedef struct EXPOSED* COOKIE;
struct HOLDER { struct EXPOSED* raw; COOKIE cookie; };
struct EXPOSED* OpenRaw(void);
void UseRaw(struct EXPOSED* value, struct EXPOSED** output);
COOKIE OpenCookie(void);
", annotationsEnabled: annotations, extraSettings: "--config\nexclude-empty-records\n");
            try
            {
                Assert.Equal(NativeSurface(fixture, target, false), NativeSurface(fixture, target, true));
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                AssertOpaqueRecordProvider(reader, "EXPOSED");
                Assert.Equal("EXPOSED*", FindMethod(reader, "Apis", "OpenRaw")
                    .DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "EXPOSED*", "EXPOSED**" },
                    FindMethod(reader, "Apis", "UseRaw").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                Assert.Equal(new[] { "EXPOSED*", annotations ? "COOKIE" : "EXPOSED*" },
                    FindType(reader, "HOLDER").GetFields().Select(reader.GetFieldDefinition)
                        .Select(field => field.DecodeSignature(new SignatureNames(), null)));
                Assert.Equal(annotations ? "COOKIE" : "EXPOSED*", FindMethod(reader, "Apis", "OpenCookie")
                    .DecodeSignature(new SignatureNames(), null).ReturnType);
                if (annotations)
                    AssertNativeTypedefStorage(reader, "COOKIE", "Void*");
                else
                    Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                        type => reader.GetString(type.Name) == "COOKIE");
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "ordinary-incomplete-pointers-" + architecture + "-" + annotations);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeTypedefCompleteRecordPointeesRetainTheirPhysicalIdentity(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
struct LATER;
_Win32_NativeTypedef_ typedef struct LATER* LATER_COOKIE;
struct COMPLETE { int value; };
_Win32_NativeTypedef_ typedef struct COMPLETE** COMPLETE_COOKIE;
struct EMPTY {};
_Win32_NativeTypedef_ typedef struct EMPTY* EMPTY_COOKIE;
union COMPLETE_UNION { int value; };
_Win32_NativeTypedef_ typedef union COMPLETE_UNION* UNION_COOKIE;
struct LATER { long long value; };
void UseCookies(LATER_COOKIE later, COMPLETE_COOKIE complete, EMPTY_COOKIE empty, UNION_COOKIE alternate);
", extraSettings: "--config\nexclude-empty-records\n");
            try
            {
                Assert.Equal(NativeSurface(fixture, target, false), NativeSurface(fixture, target, true));
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                foreach (var (name, storage) in new[]
                {
                    ("LATER_COOKIE", "LATER*"), ("COMPLETE_COOKIE", "COMPLETE**"),
                    ("EMPTY_COOKIE", "EMPTY*"), ("UNION_COOKIE", "COMPLETE_UNION*"),
                })
                    AssertNativeTypedefStorage(reader, name, storage);
                AssertOpaqueRecordProvider(reader, "EMPTY");
                foreach (var (name, storage) in new[] { ("LATER", "Int64"), ("COMPLETE", "Int32"), ("COMPLETE_UNION", "Int32") })
                    Assert.Equal(storage, reader.GetFieldDefinition(Assert.Single(FindType(reader, name).GetFields()))
                        .DecodeSignature(new SignatureNames(), null));
                Assert.Equal(new[] { "LATER_COOKIE", "COMPLETE_COOKIE", "EMPTY_COOKIE", "UNION_COOKIE" },
                    FindMethod(reader, "Apis", "UseCookies").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "complete-typedef-pointees-" + architecture);
            }
        }
    }
}

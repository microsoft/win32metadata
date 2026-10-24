using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        internal const string ExistingEnumFlagDeclarations = @"
typedef enum ENUM_FLAGS tagSTGC {
    STGC_DEFAULT = 0,
    STGC_OVERWRITE = 1,
    STGC_ONLYIFCURRENT = 2,
    STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE = 4,
    STGC_CONSOLIDATE = 8
} STGC;
enum ENUM_FLAGS VARENUM {
    VT_EMPTY = 0x0000, VT_NULL = 0x0001, VT_I2 = 0x0002, VT_I4 = 0x0003,
    VT_R4 = 0x0004, VT_R8 = 0x0005, VT_CY = 0x0006, VT_DATE = 0x0007,
    VT_BSTR = 0x0008, VT_DISPATCH = 0x0009, VT_ERROR = 0x000a, VT_BOOL = 0x000b,
    VT_VARIANT = 0x000c, VT_UNKNOWN = 0x000d, VT_DECIMAL = 0x000e,
    VT_I1 = 0x0010, VT_UI1 = 0x0011, VT_UI2 = 0x0012, VT_UI4 = 0x0013,
    VT_I8 = 0x0014, VT_UI8 = 0x0015, VT_INT = 0x0016, VT_UINT = 0x0017,
    VT_VOID = 0x0018, VT_HRESULT = 0x0019, VT_PTR = 0x001a, VT_SAFEARRAY = 0x001b,
    VT_CARRAY = 0x001c, VT_USERDEFINED = 0x001d, VT_LPSTR = 0x001e, VT_LPWSTR = 0x001f,
    VT_RECORD = 0x0024, VT_INT_PTR = 0x0025, VT_UINT_PTR = 0x0026,
    VT_FILETIME = 0x0040, VT_BLOB = 0x0041, VT_STREAM = 0x0042, VT_STORAGE = 0x0043,
    VT_STREAMED_OBJECT = 0x0044, VT_STORED_OBJECT = 0x0045, VT_BLOB_OBJECT = 0x0046,
    VT_CF = 0x0047, VT_CLSID = 0x0048, VT_VERSIONED_STREAM = 0x0049,
    VT_BSTR_BLOB = 0x0fff, VT_VECTOR = 0x1000, VT_ARRAY = 0x2000,
    VT_BYREF = 0x4000, VT_RESERVED = 0x8000, VT_ILLEGAL = 0xffff,
    VT_ILLEGALMASKED = 0x0fff, VT_TYPEMASK = 0x0fff
};
struct ENUM_STORAGE { STGC flags; unsigned short tag; unsigned after; };
";

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "macro")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "macro")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "macro")]
        [InlineData("x86", "i686-pc-windows-msvc", "tag")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "tag")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "tag")]
        [InlineData("x86", "i686-pc-windows-msvc", "alias")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "alias")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "alias")]
        public void ExistingEnumFlagsPreserveNativeAndPhysicalModels(string architecture, string target, string transport)
        {
            const string settings = "--with-type\nVARENUM=ushort\n--additional=-Wflag-enum\n";
            string original = ExistingEnumFlagDeclarations.Replace("ENUM_FLAGS", "");
            string annotated = ExistingEnumFlagDeclarations.Replace("ENUM_FLAGS", transport == "macro" ? "_Win32_Flags_" : "");
            if (transport != "macro")
                annotated += "/* Win32Metadata: enum ::" + (transport == "tag" ? "tagSTGC" : "STGC") + " => Flags */\n" +
                    "/* Win32Metadata: " + (transport == "tag" ? "enum" : "type") + " ::VARENUM => Flags */\n";
            var namespaces = new Dictionary<string, string>
            {
                ["STGC"] = "Windows.Win32.System.Com",
                ["VARENUM"] = "Windows.Win32.System.Variant",
            };
            foreach (string name in new[] { "STGC", "VARENUM" })
            {
                using var before = new HeaderAnnotationTests.NativeFixture(architecture, target, original,
                    extraSettings: settings, namespaceName: namespaces[name]);
                using var after = new HeaderAnnotationTests.NativeFixture(architecture, target, annotated,
                    extraSettings: settings, namespaceName: namespaces[name]);
                before.AssertSuccess();
                after.AssertSuccess();
                Assert.DoesNotContain("-Wflag-enum", before.Diagnostics);
                Assert.DoesNotContain("-Wflag-enum", after.Diagnostics);
                foreach (string language in new[] { "c", "c++" })
                {
                    var native = NativeSurface(before, target, false, language);
                    Assert.Equal(native, NativeSurface(before, target, true, language));
                    Assert.Equal(native, NativeSurface(after, target, false, language));
                    Assert.Equal(native, NativeSurface(after, target, true, language));
                }
                using var oldImage = Emit(before, architecture);
                using var newImage = Emit(after, architecture);
                var oldType = FindType(oldImage.Reader, name);
                var newType = FindType(newImage.Reader, name);
                Assert.Equal(namespaces[name], newImage.Reader.GetString(newType.Namespace));
                Assert.Equal(oldImage.Reader.GetString(oldType.Namespace), newImage.Reader.GetString(newType.Namespace));
                var flags = Assert.Single(newType.GetCustomAttributes(), handle => AttributeName(newImage.Reader, handle) == "FlagsAttribute");
                Assert.Equal("01000000", Convert.ToHexString(newImage.Reader.GetBlobBytes(newImage.Reader.GetCustomAttribute(flags).Value)));
                AssertDoesNotHaveAttribute(oldImage.Reader, oldType.GetCustomAttributes(), "FlagsAttribute");
                Assert.Equal(EnumFieldSnapshot(oldImage.Reader, oldType), EnumFieldSnapshot(newImage.Reader, newType));
                var fields = newType.GetFields().Select(newImage.Reader.GetFieldDefinition).ToArray();
                Assert.Equal(name == "STGC" ? "0608" : "0607", Convert.ToHexString(newImage.Reader.GetBlobBytes(fields[0].Signature)));
                Assert.Equal(name == "STGC" ? 5 : 52, fields.Length - 1);
                Assert.All(fields.Skip(1), field => Assert.Equal(name == "STGC" ? ConstantTypeCode.Int32 : ConstantTypeCode.UInt16,
                    newImage.Reader.GetConstant(field.GetDefaultValue()).TypeCode));
                AssertMetadataClosure(newImage.Reader);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void ExistingEnumFlagsDoNotSelectPromoteOrTruncateStorage(string architecture, string target, bool enabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
enum _Win32_Flags_ Small : unsigned short { SMALL_ZERO = 0, SMALL_HIGH = 0x8000, SMALL_ALL = 0xffff };
enum _Win32_Flags_ Signed : int { SIGNED_MINUS = -1, SIGNED_HIGH = 0x7fffffff };
enum _Win32_Flags_ Wide : unsigned long long { WIDE_HIGH = 0x100000000ULL, WIDE_ALL = 0xffffffffffffffffULL };
", annotationsEnabled: enabled, extraSettings: "--additional=-Wflag-enum\n");
            fixture.AssertSuccess();
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            foreach (var model in new[]
            {
                (Name: "Small", Storage: "UInt16", Value: "FFFF"),
                (Name: "Signed", Storage: "Int32", Value: "FFFFFF7F"),
                (Name: "Wide", Storage: "UInt64", Value: "FFFFFFFFFFFFFFFF"),
            })
            {
                var type = FindType(reader, model.Name);
                Assert.Equal(enabled ? 1 : 0, type.GetCustomAttributes().Count(handle => AttributeName(reader, handle) == "FlagsAttribute"));
                var fields = type.GetFields().Select(reader.GetFieldDefinition).ToArray();
                Assert.Equal(model.Storage, fields[0].DecodeSignature(new SignatureNames(), null));
                Assert.Equal(model.Value, Convert.ToHexString(reader.GetBlobBytes(reader.GetConstant(fields.Last().GetDefaultValue()).Value)));
            }
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("_Win32_Flags_ typedef unsigned BAD;")]
        [InlineData("typedef enum E ALIAS _Win32_Flags_;")]
        [InlineData("struct _Win32_Flags_ Bad { int value; };")]
        [InlineData("_Win32_Flags_ int F();")]
        [InlineData("void F(_Win32_Flags_ unsigned value);")]
        [InlineData("struct Bad { _Win32_Flags_ unsigned value; };")]
        [InlineData("enum Bad { VALUE _Win32_Flags_ = 1 };")]
        [InlineData("enum _Win32_Flags_ _Win32_Flags_ Bad { VALUE = 1 };")]
        public void ExistingEnumFlagsRejectNonEnumDeclarationsAndDuplicates(string declaration)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "enum E { FIRST = 1 };\n" + declaration);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void MetadataFlagsAvoidTheNativeFlagEnumDiagnosticPolicy()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                ExistingEnumFlagDeclarations.Replace("ENUM_FLAGS", "__attribute__((flag_enum))"),
                extraSettings: "--additional=-Wflag-enum\n");
            fixture.Run();
            Assert.Contains("-Wflag-enum", fixture.Diagnostics);
        }

        [Fact]
        public void ExistingNativeAndMetadataFlagsEmitOnePhysicalAttribute()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "enum __attribute__((flag_enum)) _Win32_Flags_ NATIVE { NONE = 0, ONE = 1, TWO = 2 };");
            fixture.AssertSuccess("FlagEnum");
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            Assert.Single(FindType(reader, "NATIVE").GetCustomAttributes(), handle => AttributeName(reader, handle) == "FlagsAttribute");
        }

        private static string[] EnumFieldSnapshot(MetadataReader reader, TypeDefinition type)
            => type.GetFields().Select(reader.GetFieldDefinition).Select(field =>
            {
                string value = field.GetDefaultValue().IsNil ? "" :
                    reader.GetConstant(field.GetDefaultValue()).TypeCode + ":" +
                    Convert.ToHexString(reader.GetBlobBytes(reader.GetConstant(field.GetDefaultValue()).Value));
                return reader.GetString(field.Name) + ":" + field.DecodeSignature(new SignatureNames(), null) + ":" + value;
            }).ToArray();
    }
}

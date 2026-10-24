using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        private const string MacroSelectedMembers = @"
#ifdef UNICODE
#define CreateProcess CreateProcessW
#define WideMember WideMemberW
#define SelectedText SelectedTextW
#define DeviceCapabilities DeviceCapabilitiesW
typedef unsigned short SELECTED_CHAR;
enum Selection { PrimarySelection = 5 };
#else
#define CreateProcess CreateProcessA
#define WideMember WideMemberA
#define SelectedText SelectedTextA
#define DeviceCapabilities DeviceCapabilitiesA
typedef char SELECTED_CHAR;
enum Selection { PrimarySelection = 1 };
#endif
#define STDMETHOD(name) virtual int __stdcall name
struct Owner {
    STDMETHOD(CreateProcess)(char* text) = 0;
    virtual int WideMember(const unsigned short* text) = 0;
    virtual int SelectedText(SELECTED_CHAR* text) = 0;
};
struct Values { unsigned short* DeviceCapabilities; char* narrow; };
extern ""C"" int CreateProcessA(char* text);
extern ""C"" int CreateProcessW(unsigned short* text);
extern ""C"" int WideMemberA(char* text);
extern ""C"" int WideMemberW(unsigned short* text);
";

        private static Dictionary<string, string> MacroMemberApis() => new()
        {
            ["CreateProcessA"] = "Test", ["CreateProcessW"] = "Test",
            ["WideMemberA"] = "Test", ["WideMemberW"] = "Test",
        };

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, false)]
        [InlineData("x86", "i686-pc-windows-msvc", true, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, true)]
        public void LegacyMemberNamesKeepPrimaryTypesAndDoNotInferAnsiFromRestoredSpelling(
            string architecture, string target, bool annotations, bool multipleFiles)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, MacroSelectedMembers,
                annotationsEnabled: annotations, multipleFiles: multipleFiles, extraSettings: "--additional\n-DUNICODE\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = multipleFiles ? string.Join("\n",
                Directory.EnumerateFiles(fixture.Output, "*.cs", SearchOption.AllDirectories).Select(File.ReadAllText))
                : fixture.ReadSource();
            Assert.Contains("CreateProcessW(", source);
            Assert.Contains("WideMemberW(", source);
            Assert.DoesNotContain("[SourceLocation(", source);
            var generatedMembers = CSharpSyntaxTree.ParseText(source).GetRoot().DescendantNodes();
            Assert.Equal(3, generatedMembers.OfType<MethodDeclarationSyntax>().Count(method =>
                method.GetTrailingTrivia().Any(trivia => trivia.ToString().StartsWith("/* Win32Metadata.NativeMemberName."))));
            Assert.Single(generatedMembers.OfType<FieldDeclarationSyntax>().Where(field =>
                field.GetTrailingTrivia().Any(trivia => trivia.ToString().StartsWith("/* Win32Metadata.NativeMemberName."))));
            using var image = Emit(fixture.DirectoryPath, architecture, apiNamesToNamespaces: MacroMemberApis());
            var reader = image.Reader;
            var narrowMethod = FindMethod(reader, "Owner", "CreateProcessA");
            Assert.Equal(new[] { "SByte*" }, narrowMethod.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            AssertHasAttribute(reader, narrowMethod.GetCustomAttributes(), "UnicodeAttribute");
            AssertDoesNotHaveAttribute(reader, narrowMethod.GetCustomAttributes(), "AnsiAttribute");
            var wideMethod = FindMethod(reader, "Owner", "WideMemberA");
            Assert.Equal(new[] { "UInt16*" }, wideMethod.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            AssertHasAttribute(reader, wideMethod.GetCustomAttributes(), "UnicodeAttribute");
            AssertDoesNotHaveAttribute(reader, wideMethod.GetCustomAttributes(), "AnsiAttribute");
            Assert.Equal(new[] { "UInt16*" }, FindMethod(reader, "Owner", "SelectedTextA")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            var fields = FindType(reader, "Values").GetFields().Select(reader.GetFieldDefinition)
                .ToDictionary(field => reader.GetString(field.Name));
            Assert.Equal(new[] { "DeviceCapabilitiesA", "narrow" }, fields.Keys.OrderBy(name => name));
            Assert.Equal("UInt16*", fields["DeviceCapabilitiesA"].DecodeSignature(new SignatureNames(), null));
            Assert.Equal("SByte*", fields["narrow"].DecodeSignature(new SignatureNames(), null));
            Assert.Equal(new[] { "SByte*" }, FindMethod(reader, "Apis", "CreateProcessA")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.Equal(new[] { "UInt16*" }, FindMethod(reader, "Apis", "CreateProcessW")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.Equal("CreateProcessA", reader.GetString(FindMethod(reader, "Apis", "CreateProcessA").GetImport().Name));
            Assert.Equal("CreateProcessW", reader.GetString(FindMethod(reader, "Apis", "CreateProcessW").GetImport().Name));
            var selection = FindType(reader, "Selection").GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == "PrimarySelection");
            Assert.Equal(5, reader.GetBlobReader(reader.GetConstant(selection.GetDefaultValue()).Value).ReadInt32());
            AssertMetadataClosure(reader);
            string evidencePath = multipleFiles ? Path.Combine(fixture.Output, "Bindings.native-declarations.json")
                : Path.ChangeExtension(fixture.Output, ".native-declarations.json");
            using var evidence = JsonDocument.Parse(File.ReadAllText(evidencePath));
            Assert.Equal(4, evidence.RootElement.GetProperty("evidence").EnumerateArray()
                .Count(value => value.GetProperty("kind").GetString() == "legacy-member-name"));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void LegacyMemberNamesDoNotRenameExplicitNativeOverloads(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#ifdef UNICODE
#define Selected SelectedW
#else
#define Selected SelectedA
#endif
struct Owner {
    virtual int Selected(char* text) = 0;
    virtual int SelectedW(unsigned value) = 0;
};
", extraSettings: "--additional\n-DUNICODE\n");
            fixture.AssertSuccess();
            using var image = Emit(fixture, architecture);
            Assert.Equal(new[] { "SByte*" }, FindMethod(image.Reader, "Owner", "SelectedA")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.Equal(new[] { "UInt32" }, FindMethod(image.Reader, "Owner", "SelectedW")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            AssertMetadataClosure(image.Reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void LegacyMemberNamesPreserveScalarFieldsWithoutOtherTransportAttributes(
            string architecture, string target, bool annotations)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#ifdef UNICODE
#define Selected SelectedW
#else
#define Selected SelectedA
#endif
struct Values { int Selected; };
", annotationsEnabled: annotations, extraSettings: "--additional\n-DUNICODE\n");
            fixture.AssertSuccess();
            Assert.DoesNotContain("[SourceLocation(", fixture.ReadSource());
            using var image = Emit(fixture, architecture);
            var field = image.Reader.GetFieldDefinition(Assert.Single(FindType(image.Reader, "Values").GetFields()));
            Assert.Equal("SelectedA", image.Reader.GetString(field.Name));
            Assert.Equal("Int32", field.DecodeSignature(new SignatureNames(), null));
            AssertMetadataClosure(image.Reader);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void LegacyMemberNamesYieldToAuthoredPrimaryBindingAndEmitterNames(bool bindingRemap)
        {
            string settings = "--additional\n-DUNICODE\n";
            if (bindingRemap)
                settings += "--remap\nOwner::CreateProcessW=ChosenMethod\nValues::DeviceCapabilitiesW=ChosenField\n";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                MacroSelectedMembers, extraSettings: settings);
            fixture.AssertSuccess();
            using var image = Emit(fixture.DirectoryPath, "x64", memberRemaps: bindingRemap ? null : new()
            {
                ["Values::DeviceCapabilitiesW"] = "ushort* ChosenField",
            }, apiNamesToNamespaces: MacroMemberApis());
            var reader = image.Reader;
            Assert.Equal(new[] { "SByte*" }, FindMethod(reader, "Owner", bindingRemap ? "ChosenMethod" : "CreateProcessA")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            var field = FindType(reader, "Values").GetFields().Select(reader.GetFieldDefinition)
                .Single(value => reader.GetString(value.Name) == "ChosenField");
            Assert.Equal("UInt16*", field.DecodeSignature(new SignatureNames(), null));
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void LegacyMemberNamesPreserveInheritedSourceDeclarationsWithoutTraversingTheirHeader(bool annotations)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#include ""base.h""
struct Owned : Parent {};
", annotationsEnabled: annotations, extraSettings: "--additional\n-DUNICODE\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "base.h"), @"
#ifdef UNICODE
#define Selected SelectedW
#else
#define Selected SelectedA
#endif
struct Parent { virtual int Selected(char* text) = 0; };
");
            fixture.AssertSuccess();
            using var image = Emit(fixture, "x64");
            Assert.Equal(new[] { "SByte*" }, FindMethod(image.Reader, "Owned", "SelectedA")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            AssertMetadataClosure(image.Reader);
        }

        [Fact]
        public void LegacyMemberNamesRejectIdenticalIncludedCoordinatesWithDifferentNativeParents()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#ifdef UNICODE
#define Selected SelectedW
struct Primary {
#include ""members.h""
};
#else
#define Selected SelectedA
struct Alternate {
#include ""members.h""
};
#endif
", extraSettings: "--additional\n-DUNICODE\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "members.h"),
                "virtual int Selected(char* text) = 0;\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("different native parents", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void LegacyMemberNamesRejectMatchingRecordCoordinatesUnderDifferentNativeNamespaces()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#ifdef UNICODE
#define Selected SelectedW
namespace Primary {
#include ""base.h""
}
using Base = Primary::Parent;
#else
#define Selected SelectedA
namespace Alternate {
#include ""base.h""
}
using Base = Alternate::Parent;
#endif
struct Owned : Base {};
", extraSettings: "--additional\n-DUNICODE\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "base.h"),
                "struct Parent { virtual int Selected(char* text) = 0; };\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("different native parents", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void LegacyMemberNamesKeepNativeArrayCountReferencesBoundToTheFinalField(
            string architecture, string target, bool authoredName)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#ifdef UNICODE
#define Count CountW
#else
#define Count CountA
#endif
struct Values {
    unsigned Count;
    _Field_size_(Count) unsigned* elements;
};
", extraSettings: "--additional\n-DUNICODE\n");
            fixture.AssertSuccess();
            using var image = Emit(fixture.DirectoryPath, architecture, nativeFieldArrayInfo: true,
                memberRemaps: authoredName ? new() { ["Values::CountW"] = "uint ChosenCount" } : null);
            string expected = authoredName ? "ChosenCount" : "CountA";
            var reader = image.Reader;
            var fields = FindType(reader, "Values").GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal(new[] { expected, "elements" }, fields.Select(field => reader.GetString(field.Name)));
            var attribute = reader.GetCustomAttribute(Assert.Single(fields[1].GetCustomAttributes()
                .Where(handle => AttributeName(reader, handle) == "NativeArrayInfoAttribute")));
            var blob = reader.GetBlobReader(attribute.Value);
            Assert.Equal(1, blob.ReadUInt16());
            Assert.Equal(1, blob.ReadUInt16());
            Assert.Equal(0x53, blob.ReadByte());
            Assert.Equal(0x0e, blob.ReadByte());
            Assert.Equal("CountFieldName", blob.ReadSerializedString());
            Assert.Equal(expected, blob.ReadSerializedString());
            Assert.Equal(0, blob.RemainingBytes);
            AssertMetadataClosure(reader);
        }
    }
}

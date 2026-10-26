using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Text.Json;
using Xunit;

namespace Win32MetadataScraperTests
{
    public abstract partial class HeaderAnnotationWinmdTests
    {

        internal static string StructuredCommentDeclarations(bool comments)
        {
            string Fact(string kind, string target, string payload, string macro)
                => comments ? "/* Win32Metadata: " + kind + " ::" + target + " => " + payload + " */" : macro;
            string field = comments
                ? "/* Win32Metadata: field ::RECORD::flags => AssociatedEnum(FLAGS) */"
                : "_Win32_AssociatedEnum_(FLAGS)";
            string parameter = comments
                ? "/* Win32Metadata: parameter ::IComment::Run::flags => AssociatedEnum(FLAGS) */"
                : "_Win32_AssociatedEnum_(FLAGS)";
            string raii = comments
                ? "/* Win32Metadata: return ::OpenOwned => RAIIFree(CloseOwned, 0, -1) */"
                : "_Win32_RAIIFree_(CloseOwned, 0, -1)";
            string output = comments
                ? "/* Win32Metadata: parameter ::CreateOwned::output => RAIIFree(CloseOwned, 0, -1) */"
                : "_Win32_RAIIFree_(CloseOwned, 0, -1)";
            string os = comments
                ? "/* Win32Metadata: interface ::IComment => SupportedOSPlatform(\"windows6.1\") */"
                : "#if defined(WIN32METADATA) && defined(__clang__)\ntypedef _Win32_SupportedOS_Windows7_ struct IComment IComment;\n#endif";
            string simple = @"
const unsigned EXTRA = 8;
enum " + Fact("enum", "MORE_FLAGS", "AssociatedConstant(EXTRA)", "_Win32_AssociatedConstant_(EXTRA)") + @" MORE_FLAGS {
    THIRD " + Fact("enumerator", "MORE_FLAGS::THIRD", "SupportedOSPlatform(\"windows6.1\")", "_Win32_SupportedOS_Windows7_") + @" = 8
};
typedef unsigned OTHER_TOKEN;
" + Fact("type", "TOKEN", "SupportedOSPlatform(\"windows6.1\")", "_Win32_SupportedOS_Windows7_") + @"
" + Fact("type", "TOKEN", "AlsoUsableFor(OTHER_TOKEN)", "_Win32_AlsoUsableFor_(OTHER_TOKEN)") + @"
typedef unsigned TOKEN;
" + Fact("type", "SIMPLE_CALLBACK", "SupportedOSPlatform(\"windows6.1\")", "_Win32_SupportedOS_Windows7_") + @"
typedef int (__stdcall *SIMPLE_CALLBACK)(unsigned count);
#define MODE_FIRST 1U
#define MODE_SECOND 4U
_Win32_FlagsEnum_(MODES, unsigned, MODE_FIRST, MODE_SECOND);
struct GROUPED { " + Fact("field", "GROUPED::flags", "AssociatedEnum(MODES)", "_Win32_AssociatedEnum_(MODES)") + @" unsigned flags; };
extern ""C"" {
" + Fact("function", "Imported", "ImportLibrary(\"source.dll\", \"Exported\")", "_Win32_ImportLibrary_(\"source.dll\", \"Exported\")") + @"
" + Fact("function", "Imported", "SetLastError", "_Win32_SetLastError_") + @"
" + Fact("function", "Imported", "PreserveResult", "_Win32_PreserveResult_") + @"
int __stdcall Imported();
" + Fact("return", "Associated", "AssociatedEnum(MORE_FLAGS)", "_Win32_AssociatedEnum_(MORE_FLAGS)") + @"
unsigned __stdcall Associated();
int __stdcall Behaviors(
    _In_ " + Fact("parameter", "Behaviors::context", "Retained", "_Win32_Retained_") + @" void* context,
    _Out_writes_(count) " + Fact("parameter", "Behaviors::buffer", "ContainsInteriorPointers", "_Win32_ContainsInteriorPointers_") + @" char* buffer,
    unsigned count,
    " + Fact("parameter", "Behaviors::reserved", "Reserved", "_Win32_Reserved_") + @" unsigned reserved,
    _In_opt_ " + Fact("parameter", "Behaviors::optional", "Optional(false)", "_Win32_Optional_(false)") + @" void* optional,
    _Outptr_ " + Fact("parameter", "Behaviors::result", "ComOutPtr(true)", "_Win32_ComOutPtr_(true)") + @" void** result,
    _COM_Outptr_ " + Fact("parameter", "Behaviors::ordinary", "ComOutPtr(false)", "_Win32_ComOutPtr_(false)") + @" void** ordinary,
    _Out_ " + Fact("parameter", "Behaviors::retval", "RetVal", "_Win32_Retval_") + @" unsigned* retval);
}
";
            return @"
typedef int HRESULT;
enum FLAGS { FIRST = 1, SECOND = 4 };
struct RECORD { unsigned before; " + field + @" unsigned flags; unsigned after; };
struct __declspec(uuid(""5bdf1d05-dbaa-4e03-b2b4-574ca7cd7de7"")) IComment
{
    virtual HRESULT __stdcall Run(/* [in] */ " + parameter + @" unsigned flags, /* [out][retval] */ void** result) = 0;
};
" + os + @"
extern ""C"" {
" + raii + @" void* __stdcall OpenOwned();
int __stdcall CreateOwned(/* [out] */ " + output + @" void** output);
int __stdcall CloseOwned(void* value);
}" + simple;
        }

        internal static string[] StructuredCommentSnapshot(MetadataReader reader)
        {
            var facts = new List<string>();
            var names = new SignatureNames(qualifiedNames: true);
            foreach (var handle in reader.TypeDefinitions)
            {
                var type = reader.GetTypeDefinition(handle);
                if (reader.GetString(type.Name) == "<Module>")
                    continue;
                string owner = names.GetTypeFromDefinition(reader, handle, 0);
                var layout = type.GetLayout();
                facts.Add("type " + owner + " " + type.Attributes + " pack=" + layout.PackingSize + " size=" + layout.Size +
                    Attributes(type.GetCustomAttributes()));
                int ordinal = 0;
                foreach (var field in type.GetFields().Select(reader.GetFieldDefinition))
                    facts.Add("field " + owner + "." + ordinal++ + ":" + reader.GetString(field.Name) + " " + field.Attributes +
                        " offset=" + field.GetOffset() + " " + field.DecodeSignature(names, null) +
                        Constant(field.GetDefaultValue()) + Attributes(field.GetCustomAttributes()));
                foreach (var method in type.GetMethods().Select(reader.GetMethodDefinition))
                {
                    var signature = method.DecodeSignature(names, null);
                    string identity = owner + "." + reader.GetString(method.Name) + "(" +
                        string.Join(",", signature.ParameterTypes) + ")";
                    var import = method.GetImport();
                    string imported = import.Module.IsNil ? "" : " import=" +
                        reader.GetString(reader.GetModuleReference(import.Module).Name) + ":" + reader.GetString(import.Name) + ":" + import.Attributes;
                    facts.Add("method " + identity + " " + method.Attributes + " " + method.ImplAttributes + " " +
                        signature.ReturnType + " header=" + signature.Header.RawValue + imported + Attributes(method.GetCustomAttributes()));
                    foreach (var parameter in method.GetParameters().Select(reader.GetParameter))
                        facts.Add("parameter " + identity + "::" + parameter.SequenceNumber + ":" + reader.GetString(parameter.Name) +
                            " " + parameter.Attributes + Constant(parameter.GetDefaultValue()) + Attributes(parameter.GetCustomAttributes()));
                }
            }
            return facts.OrderBy(value => value, StringComparer.Ordinal).ToArray();

            string Constant(ConstantHandle handle) => handle.IsNil ? "" : " constant=" +
                reader.GetConstant(handle).TypeCode + ":" + Convert.ToHexString(reader.GetBlobBytes(reader.GetConstant(handle).Value));

            string Attributes(CustomAttributeHandleCollection attributes) => " [" + string.Join(";",
                attributes.Select(handle => AttributeName(reader, handle) + ":" +
                    Convert.ToHexString(reader.GetBlobBytes(reader.GetCustomAttribute(handle).Value)))
                    .OrderBy(value => value, StringComparer.Ordinal)) + "]";
        }
    }
    public class HeaderAnnotationCommentWinmdTests : HeaderAnnotationWinmdTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void StructuredCommentsMatchMacroNativeAndPhysicalMetadata(string architecture, string target, bool enabled)
        {
            using var old = new HeaderAnnotationTests.NativeFixture(architecture, target, StructuredCommentDeclarations(false),
                annotationsEnabled: enabled);
            using var current = new HeaderAnnotationTests.NativeFixture(architecture, target, StructuredCommentDeclarations(true),
                annotationsEnabled: enabled);
            Assert.True(old.Run() == 0, old.Diagnostics);
            Assert.True(current.Run() == 0, current.Diagnostics);
            var native = NativeSurface(old, target, false);
            Assert.Equal(native, NativeSurface(old, target, true));
            Assert.Equal(native, NativeSurface(current, target, false));
            Assert.Equal(native, NativeSurface(current, target, true));
            using var before = Emit(old, architecture);
            using var after = Emit(current, architecture);
            var oldSnapshot = StructuredCommentSnapshot(before.Reader);
            var newSnapshot = StructuredCommentSnapshot(after.Reader);
            Assert.Equal(oldSnapshot, newSnapshot);
            var reader = after.Reader;
            var api = FindMethod(reader, "Apis", "OpenOwned");
            var result = api.GetParameters().Select(reader.GetParameter).SingleOrDefault(parameter => parameter.SequenceNumber == 0);
            if (enabled)
            {
                AssertStringAttribute(reader, FindType(reader, "IComment").GetCustomAttributes(),
                    "SupportedOSPlatformAttribute", "windows6.1");
                AssertStringAttribute(reader, result.GetCustomAttributes(), "RAIIFreeAttribute", "CloseOwned");
                Assert.Equal(new long[] { 0, -1 }, ReadInvalidValues(reader, result.GetCustomAttributes()));
            }
            var run = FindMethod(reader, "IComment", "Run");
            var input = run.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 1);
            var output = run.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 2);
            if (enabled)
            {
                Assert.Equal(System.Reflection.ParameterAttributes.In, input.Attributes);
                Assert.Equal(System.Reflection.ParameterAttributes.Out, output.Attributes);
                AssertStringAttribute(reader, input.GetCustomAttributes(), "AssociatedEnumAttribute", "FLAGS");
                AssertHasAttribute(reader, output.GetCustomAttributes(), "RetValAttribute");
                var field = FindType(reader, "RECORD").GetFields().Select(reader.GetFieldDefinition)
                    .Single(value => reader.GetString(value.Name) == "flags");
                AssertStringAttribute(reader, field.GetCustomAttributes(), "AssociatedEnumAttribute", "FLAGS");
                var create = FindMethod(reader, "Apis", "CreateOwned").GetParameters().Select(reader.GetParameter)
                    .Single(parameter => parameter.SequenceNumber == 1);
                AssertStringAttribute(reader, create.GetCustomAttributes(), "RAIIFreeAttribute", "CloseOwned");
                Assert.Equal(new long[] { 0, -1 }, ReadInvalidValues(reader, create.GetCustomAttributes()));
            }
            AssertMetadataClosure(reader);
            string artifacts = Environment.GetEnvironmentVariable("WIN32_COMMENT_ARTIFACTS");
            if (artifacts != null)
            {
                string root = Path.Combine(artifacts, architecture + (enabled ? "-on" : "-off"));
                foreach (var pair in new[] { (Name: "macro", Fixture: old), (Name: "comment", Fixture: current) })
                {
                    string destination = Path.Combine(root, pair.Name);
                    foreach (string path in Directory.GetFiles(pair.Fixture.DirectoryPath, "*", SearchOption.AllDirectories))
                    {
                        string copy = Path.Combine(destination, Path.GetRelativePath(pair.Fixture.DirectoryPath, path));
                        Directory.CreateDirectory(Path.GetDirectoryName(copy));
                        File.Copy(path, copy);
                    }
                    File.WriteAllText(Path.Combine(destination, "reader.log"), pair.Fixture.Diagnostics);
                }
                File.WriteAllText(Path.Combine(root, "comparison.json"), JsonSerializer.Serialize(new
                {
                    architecture, enabled, nativeSignatures = native, oldPhysicalFacts = oldSnapshot,
                    newPhysicalFacts = newSnapshot, nativeEqual = true, physicalEqual = true,
                }, new JsonSerializerOptions { WriteIndented = true }));
            }
        }
    }
}

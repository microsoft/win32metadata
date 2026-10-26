using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Security.Cryptography;
using System.Text.Json;
using Xunit;

namespace Win32MetadataScraperTests
{
    public abstract partial class HeaderAnnotationWinmdTests
    {

        internal static void AssertNativeTypedefStorage(MetadataReader reader, string name, string storage)
        {
            var type = FindType(reader, name);
            var field = reader.GetFieldDefinition(Assert.Single(type.GetFields()));
            Assert.Equal("Value", reader.GetString(field.Name));
            Assert.Equal(storage, field.DecodeSignature(new SignatureNames(), null));
            Assert.Single(type.GetCustomAttributes().Where(handle => AttributeName(reader, handle) == "NativeTypedefAttribute"));
        }

        internal static string RunNativeTypedefControl(HeaderAnnotationTests.NativeFixture fixture, string scraper)
        {
            var start = new ProcessStartInfo("dotnet")
            {
                WorkingDirectory = fixture.DirectoryPath,
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
            };
            start.ArgumentList.Add(scraper);
            start.ArgumentList.Add(Path.Combine(fixture.DirectoryPath, "control-remaps.txt"));
            start.ArgumentList.Add("@" + Path.Combine(fixture.DirectoryPath, "test.rsp"));
            using var process = Process.Start(start);
            var output = process.StandardOutput.ReadToEndAsync();
            var error = process.StandardError.ReadToEndAsync();
            process.WaitForExit();
            string diagnostics = output.GetAwaiter().GetResult() + error.GetAwaiter().GetResult();
            Assert.True(process.ExitCode == 0, diagnostics);
            return diagnostics;
        }

        internal static string FileSha256(string path) => Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path)));

        internal static void SaveNativeTypedefArtifacts(HeaderAnnotationTests.NativeFixture fixture, string name,
            MetadataReader reader = null, object native = null)
        {
            string artifacts = Environment.GetEnvironmentVariable("WIN32_NATIVE_TYPEDEF_ARTIFACTS");
            if (artifacts == null)
                return;
            string destination = Path.Combine(artifacts, name.Replace("c++", "cpp"));
            Assert.False(Directory.Exists(destination), "Retain each isolated test attempt separately.");
            foreach (string path in Directory.GetFiles(fixture.DirectoryPath, "*", SearchOption.AllDirectories))
            {
                string copy = Path.Combine(destination, Path.GetRelativePath(fixture.DirectoryPath, path));
                Directory.CreateDirectory(Path.GetDirectoryName(copy));
                File.Copy(path, copy);
            }
            File.WriteAllText(Path.Combine(destination, "reader.log"), fixture.Diagnostics ?? "");
            string scraper = typeof(global::Win32MetadataScraper.HeaderAnnotationProcessor).Assembly.Location;
            string emitter = typeof(ClangSharpSourceToWinmd.ClangSharpSourceWinmdGenerator).Assembly.Location;
            File.WriteAllText(Path.Combine(destination, "physical.json"), JsonSerializer.Serialize(new
            {
                native,
                physicalSnapshot = reader == null ? null : StructuredCommentSnapshot(reader),
                scraper, scraperSha256 = FileSha256(scraper),
                emitter, emitterSha256 = FileSha256(emitter),
                helperSha256 = FileSha256(Path.Combine(AppContext.BaseDirectory, "assets", "win32metadata_annotations.h")),
            }, new JsonSerializerOptions { WriteIndented = true }));
        }
    }
    public class HeaderNativeTypedefTests : HeaderAnnotationWinmdTests
    {
        [Fact]
        public void NativeTypedefNeutralPayloadReachesPhysicalWinmd()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef int BOOL __attribute__((annotate(""Win32Metadata.NativeTypedef"")));
BOOL RoundTrip(BOOL value);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            var type = FindType(reader, "BOOL");
            var field = reader.GetFieldDefinition(Assert.Single(type.GetFields()));
            Assert.Equal("Value", reader.GetString(field.Name));
            Assert.Equal("Int32", field.DecodeSignature(new SignatureNames(), null));
            Assert.Single(type.GetCustomAttributes().Where(handle => AttributeName(reader, handle) == "NativeTypedefAttribute"));
            var signature = FindMethod(reader, "Apis", "RoundTrip").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("BOOL", signature.ReturnType);
            Assert.Equal(new[] { "BOOL" }, signature.ParameterTypes);
            AssertMetadataClosure(reader);
            SaveNativeTypedefArtifacts(fixture, "neutral-payload", reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++")]
        public void NativeTypedefMarkerPreservesNativeScalarAndPointerAbi(string architecture, string target, string language)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
_Win32_NativeTypedef_ typedef int BOOL;
typedef long LONG;
_Win32_NativeTypedef_ typedef LONG HRESULT;
_Win32_NativeTypedef_ typedef void* HANDLE;
_Win32_NativeTypedef_ typedef HANDLE* PHANDLE;
_Win32_NativeTypedef_ typedef PHANDLE* PPHANDLE;
_Win32_NativeTypedef_ typedef BOOL BOOL_ALIAS;
_Win32_NativeTypedef_ typedef signed char SIGNED_BYTE;
_Win32_NativeTypedef_ typedef unsigned char UNSIGNED_BYTE;
_Win32_NativeTypedef_ typedef short SIGNED_SHORT;
_Win32_NativeTypedef_ typedef unsigned short UNSIGNED_SHORT;
_Win32_NativeTypedef_ typedef unsigned long UNSIGNED_LONG;
_Win32_NativeTypedef_ typedef long long SIGNED_64;
_Win32_NativeTypedef_ typedef unsigned long long UNSIGNED_64;
_Win32_NativeTypedef_ typedef float NATIVE_FLOAT;
_Win32_NativeTypedef_ typedef double NATIVE_DOUBLE;
#if defined(__cplusplus)
_Win32_NativeTypedef_ typedef bool NATIVE_BOOL;
#else
_Win32_NativeTypedef_ typedef _Bool NATIVE_BOOL;
#endif
typedef void* BASE_POINTER;
_Win32_NativeTypedef_ typedef BASE_POINTER NATIVE_POINTER;
_Win32_NativeTypedef_ typedef const unsigned char* PCBYTE;
_Win32_NativeTypedef_ typedef PCBYTE* PPCBYTE;
struct OPAQUE;
_Win32_NativeTypedef_ typedef struct OPAQUE* HOPAQUE;
struct COMPLETE { int value; };
_Win32_NativeTypedef_ typedef struct COMPLETE** PPCOMPLETE;
typedef int UNMARKED;
struct NATIVE_ABI {
    BOOL boolean;
    HRESULT result;
    HANDLE handle;
    PPHANDLE indirect;
    BOOL_ALIAS alias;
    SIGNED_BYTE small;
    SIGNED_64 wide;
};
typedef char BOOL_SIZE[(sizeof(BOOL) == 4) ? 1 : -1];
typedef char HRESULT_SIZE[(sizeof(HRESULT) == 4) ? 1 : -1];
#if defined(_WIN64)
typedef char HANDLE_SIZE[(sizeof(HANDLE) == 8) ? 1 : -1];
#else
typedef char HANDLE_SIZE[(sizeof(HANDLE) == 4) ? 1 : -1];
#endif
BOOL UseBool(BOOL value, BOOL_ALIAS alias);
HRESULT UseResult(HRESULT value);
HANDLE UseHandle(HANDLE value, PHANDLE output, PPHANDLE indirect);
void UseOpaque(HOPAQUE first, PPCOMPLETE second, PPCBYTE third);
void WriteHandle(HANDLE* output, HANDLE** indirect);
UNMARKED UseUnmarked(UNMARKED value);
#if defined(__cplusplus)
struct __declspec(uuid(""59487912-a894-42c4-8500-bf628adee483"")) IHeaderIdentity {
    virtual HRESULT __stdcall Transform(BOOL value, HANDLE handle, HANDLE* output) = 0;
};
#endif
", extraSettings: "--language\n" + language + "\n--std\n" + (language == "c" ? "c11" : "c++17") +
                "\n--remap\nBASE_POINTER=IntPtr\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var native = NativeSurface(fixture, target, false, language);
            Assert.Equal(native, NativeSurface(fixture, target, true, language));
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            foreach (var (name, storage) in new[]
            {
                ("BOOL", "Int32"), ("HRESULT", "Int32"), ("HANDLE", "Void*"),
                ("PHANDLE", "Void**"), ("PPHANDLE", "Void***"), ("BOOL_ALIAS", "Int32"),
                ("SIGNED_BYTE", "SByte"), ("UNSIGNED_BYTE", "Byte"),
                ("SIGNED_SHORT", "Int16"), ("UNSIGNED_SHORT", "UInt16"), ("UNSIGNED_LONG", "UInt32"),
                ("SIGNED_64", "Int64"), ("UNSIGNED_64", "UInt64"),
                ("NATIVE_FLOAT", "Single"), ("NATIVE_DOUBLE", "Double"), ("NATIVE_BOOL", "Byte"), ("NATIVE_POINTER", "Void*"),
                ("PCBYTE", "Byte*"), ("PPCBYTE", "Byte**"), ("HOPAQUE", "Void*"), ("PPCOMPLETE", "COMPLETE**"),
            })
                AssertNativeTypedefStorage(reader, name, storage);
            Assert.Equal(new byte[] { 0x06, 0x08 },
                reader.GetBlobBytes(reader.GetFieldDefinition(Assert.Single(FindType(reader, "BOOL").GetFields())).Signature));
            Assert.Equal(new byte[] { 0x06, 0x0f, 0x01 },
                reader.GetBlobBytes(reader.GetFieldDefinition(Assert.Single(FindType(reader, "HANDLE").GetFields())).Signature));
            var boolean = FindMethod(reader, "Apis", "UseBool").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("BOOL", boolean.ReturnType);
            Assert.Equal(new[] { "BOOL", "BOOL_ALIAS" }, boolean.ParameterTypes);
            var result = FindMethod(reader, "Apis", "UseResult").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("HRESULT", result.ReturnType);
            Assert.Equal(new[] { "HRESULT" }, result.ParameterTypes);
            var handles = FindMethod(reader, "Apis", "UseHandle").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("HANDLE", handles.ReturnType);
            Assert.Equal(new[] { "HANDLE", "PHANDLE", "PPHANDLE" }, handles.ParameterTypes);
            Assert.Equal(new[] { "HOPAQUE", "PPCOMPLETE", "PPCBYTE" },
                FindMethod(reader, "Apis", "UseOpaque").DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.Equal(new[] { "HANDLE*", "HANDLE**" },
                FindMethod(reader, "Apis", "WriteHandle").DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.Equal(new[] { "BOOL", "HRESULT", "HANDLE", "PPHANDLE", "BOOL_ALIAS", "SIGNED_BYTE", "SIGNED_64" },
                FindType(reader, "NATIVE_ABI").GetFields().Select(reader.GetFieldDefinition)
                    .Select(field => field.DecodeSignature(new SignatureNames(), null)));
            if (language == "c++")
            {
                var method = FindMethod(reader, "IHeaderIdentity", "Transform").DecodeSignature(new SignatureNames(), null);
                Assert.Equal("HRESULT", method.ReturnType);
                Assert.Equal(new[] { "BOOL", "HANDLE", "HANDLE*" }, method.ParameterTypes);
            }
            Assert.Equal("Int32", FindMethod(reader, "Apis", "UseUnmarked").DecodeSignature(new SignatureNames(), null).ReturnType);
            Assert.DoesNotContain(reader.TypeDefinitions, handle => reader.GetString(reader.GetTypeDefinition(handle).Name) is "UNMARKED" or "LONG");
            AssertMetadataClosure(reader);
            SaveNativeTypedefArtifacts(fixture, architecture + "-" + language, reader, native);
        }

        public static IEnumerable<object[]> NativeTypedefNonDefaultPointerWidths()
        {
            foreach (var (architecture, target, qualifier, width) in new[]
            {
                ("x86", "i686-pc-windows-msvc", "__ptr64", 8),
                ("x64", "x86_64-pc-windows-msvc", "__ptr32", 4),
                ("arm64", "aarch64-pc-windows-msvc", "__ptr32", 4),
            })
                foreach (string language in new[] { "c", "c++" })
                    foreach (int outerLevels in new[] { 0, 1, 2 })
                        foreach (bool comment in new[] { false, true })
                            yield return new object[] { architecture, target, qualifier, width, language, outerLevels, comment };
        }

        [Theory]
        [MemberData(nameof(NativeTypedefNonDefaultPointerWidths))]
        public void NativeTypedefMarkerRejectsNonDefaultPointerWidthAtEveryLevel(string architecture, string target,
            string qualifier, int explicitWidth, string language, int outerLevels, bool comment)
        {
            int ordinaryWidth = architecture == "x86" ? 4 : 8;
            string assertion = language == "c" ? "_Static_assert" : "static_assert";
            string selected = new[] { "EXPLICIT_POINTER", "OUTER_POINTER", "OUTER_POINTER_TWICE" }[outerLevels];
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, $@"
typedef int* {qualifier} EXPLICIT_POINTER;
typedef EXPLICIT_POINTER* OUTER_POINTER;
typedef OUTER_POINTER* OUTER_POINTER_TWICE;
{(comment ? "" : "_Win32_NativeTypedef_ ")}typedef {selected} NOMINAL;
{(comment ? "/* Win32Metadata: type ::NOMINAL => NativeTypedef */" : "")}
{assertion}(sizeof(void*) == {ordinaryWidth}, ""ordinary native pointer width"");
{assertion}(sizeof(EXPLICIT_POINTER) == {explicitWidth}, ""explicit native pointer width"");
{assertion}(sizeof(OUTER_POINTER) == {ordinaryWidth}, ""ordinary outer native pointer width"");
{assertion}(sizeof(OUTER_POINTER_TWICE) == {ordinaryWidth}, ""ordinary outermost native pointer width"");
{assertion}(sizeof(NOMINAL) == {(outerLevels == 0 ? explicitWidth : ordinaryWidth)}, ""selected alias width"");
struct STORAGE {{ NOMINAL value; int tail; }};
NOMINAL RoundTrip(NOMINAL value);
void Write(NOMINAL* output);
", extraSettings: "--language\n" + language + "\n--std\n" + (language == "c" ? "c11" : "c++17") + "\n");
            var native = NativeSurface(fixture, target, false, language);
            Assert.Equal(native, NativeSurface(fixture, target, true, language));
            Assert.Contains("field tail int " + (outerLevels == 0 ? explicitWidth : ordinaryWidth) * 8, native);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("error WMA001:", fixture.Diagnostics);
            Assert.Contains("requires ordinary target-width data pointers at every pointer level", fixture.Diagnostics);
            Assert.Contains($"has native size {explicitWidth} bytes instead of the target's {ordinaryWidth} bytes", fixture.Diagnostics);
            Assert.Empty(Directory.GetFiles(fixture.DirectoryPath, "*.cs", SearchOption.AllDirectories));
            Assert.False(File.Exists(Path.Combine(fixture.DirectoryPath, "remaps.txt")));
            SaveNativeTypedefArtifacts(fixture,
                architecture + "-rejected-pointer-" + language + "-" + outerLevels + "-" + comment, native: new
                {
                    target,
                    qualifier,
                    nativeSurface = native,
                    nativePointerWidths = Enumerable.Repeat(ordinaryWidth, outerLevels).Append(explicitWidth).ToArray(),
                    rejectedBeforeBindings = true,
                });
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "__ptr32", "c")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "__ptr64", "c")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "__ptr64", "c")]
        [InlineData("x86", "i686-pc-windows-msvc", "__ptr32", "c++")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "__ptr64", "c++")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "__ptr64", "c++")]
        public void NativeTypedefMarkerPreservesOrdinaryWidthQualifiedPointers(string architecture, string target,
            string qualifier, string language)
        {
            int ordinaryWidth = architecture == "x86" ? 4 : 8;
            string assertion = language == "c" ? "_Static_assert" : "static_assert";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, $@"
_Win32_NativeTypedef_ typedef int* {qualifier} INTEGER_POINTER;
_Win32_NativeTypedef_ typedef void* {qualifier} VOID_POINTER;
struct COMPLETE {{ int value; }};
_Win32_NativeTypedef_ typedef struct COMPLETE* {qualifier} RECORD_POINTER;
struct OPAQUE;
_Win32_NativeTypedef_ typedef struct OPAQUE* {qualifier} OPAQUE_POINTER;
_Win32_NativeTypedef_ typedef INTEGER_POINTER* {qualifier} NESTED_POINTER;
_Win32_NativeTypedef_ typedef NESTED_POINTER* OUTER_POINTER;
{assertion}(sizeof(void*) == {ordinaryWidth}, ""ordinary native pointer width"");
{assertion}(sizeof(INTEGER_POINTER) == sizeof(void*), ""integer pointer width"");
{assertion}(sizeof(VOID_POINTER) == sizeof(void*), ""void pointer width"");
{assertion}(sizeof(RECORD_POINTER) == sizeof(void*), ""record pointer width"");
{assertion}(sizeof(OPAQUE_POINTER) == sizeof(void*), ""incomplete record pointer width"");
{assertion}(sizeof(NESTED_POINTER) == sizeof(void*), ""qualified outer pointer width"");
{assertion}(sizeof(OUTER_POINTER) == sizeof(void*), ""ordinary outer pointer width"");
struct STORAGE {{ INTEGER_POINTER value; VOID_POINTER opaque; OUTER_POINTER indirect; }};
INTEGER_POINTER RoundTrip(INTEGER_POINTER value, VOID_POINTER opaque, RECORD_POINTER record,
    OPAQUE_POINTER incomplete, NESTED_POINTER nested, OUTER_POINTER outer);
", extraSettings: "--language\n" + language + "\n--std\n" + (language == "c" ? "c11" : "c++17") + "\n");
            var native = NativeSurface(fixture, target, false, language);
            Assert.Equal(native, NativeSurface(fixture, target, true, language));
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            foreach (var (name, storage) in new[]
            {
                ("INTEGER_POINTER", "Int32*"), ("VOID_POINTER", "Void*"), ("RECORD_POINTER", "COMPLETE*"),
                ("OPAQUE_POINTER", "Void*"), ("NESTED_POINTER", "Int32**"), ("OUTER_POINTER", "Int32***"),
            })
                AssertNativeTypedefStorage(reader, name, storage);
            var signature = FindMethod(reader, "Apis", "RoundTrip").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("INTEGER_POINTER", signature.ReturnType);
            Assert.Equal(new[] { "INTEGER_POINTER", "VOID_POINTER", "RECORD_POINTER", "OPAQUE_POINTER", "NESTED_POINTER", "OUTER_POINTER" },
                signature.ParameterTypes);
            Assert.Equal(new[] { "INTEGER_POINTER", "VOID_POINTER", "OUTER_POINTER" },
                FindType(reader, "STORAGE").GetFields().Select(reader.GetFieldDefinition)
                    .Select(field => field.DecodeSignature(new SignatureNames(), null)));
            AssertMetadataClosure(reader);
            SaveNativeTypedefArtifacts(fixture, architecture + "-ordinary-pointer-" + language, reader, native);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void NativeTypedefMarkerPreservesNativeSizedIntegerStorage(string architecture, string target, bool explicitMappings)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#if defined(_WIN64)
typedef unsigned long long UINT_PTR;
typedef long long LONG_PTR;
_Win32_NativeTypedef_ typedef long long SHANDLE_PTR;
_Win32_NativeTypedef_ typedef unsigned long long HANDLE_PTR;
#else
typedef unsigned int UINT_PTR;
typedef long LONG_PTR;
_Win32_NativeTypedef_ typedef long SHANDLE_PTR;
_Win32_NativeTypedef_ typedef unsigned long HANDLE_PTR;
#endif
_Win32_NativeTypedef_ typedef UINT_PTR WPARAM;
_Win32_NativeTypedef_ typedef LONG_PTR LPARAM;
_Win32_NativeTypedef_ typedef LONG_PTR LRESULT;
_Win32_NativeTypedef_ typedef WPARAM* PWPARAM;
_Win32_NativeTypedef_ typedef LPARAM** PPLPARAM;
LRESULT Message(WPARAM first, LPARAM second, PWPARAM third, PPLPARAM fourth, SHANDLE_PTR fifth, HANDLE_PTR sixth);
", extraSettings: explicitMappings ? "--remap\nUINT_PTR=System.UIntPtr\nLONG_PTR=nint\nSHANDLE_PTR=nint\nHANDLE_PTR=nuint\n" : "");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(NativeSurface(fixture, target, false), NativeSurface(fixture, target, true));
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            AssertNativeTypedefStorage(reader, "WPARAM", "UIntPtr");
            AssertNativeTypedefStorage(reader, "LPARAM", "IntPtr");
            AssertNativeTypedefStorage(reader, "LRESULT", "IntPtr");
            AssertNativeTypedefStorage(reader, "PWPARAM", "UIntPtr*");
            AssertNativeTypedefStorage(reader, "PPLPARAM", "IntPtr**");
            AssertNativeTypedefStorage(reader, "SHANDLE_PTR", architecture == "x86" ? "Int32" : "Int64");
            AssertNativeTypedefStorage(reader, "HANDLE_PTR", architecture == "x86" ? "UInt32" : "UInt64");
            var signature = FindMethod(reader, "Apis", "Message").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("LRESULT", signature.ReturnType);
            Assert.Equal(new[] { "WPARAM", "LPARAM", "PWPARAM", "PPLPARAM", "SHANDLE_PTR", "HANDLE_PTR" }, signature.ParameterTypes);
            AssertMetadataClosure(reader);
            SaveNativeTypedefArtifacts(fixture, architecture + "-sized-" + explicitMappings, reader);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void NativeTypedefMarkerDeduplicatesRedeclarationsAndRetainsTraversedOwners(bool multipleFiles)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef int FORWARDED;
#include ""annotation-owner.h""
typedef FORWARDED FORWARDED;
_Win32_NativeTypedef_ typedef int BOOL;
_Win32_NativeTypedef_ typedef BOOL BOOL;
_Win32_NativeTypedef_ _Win32_NativeTypedef_ typedef BOOL BOOL_ALIAS;
_Win32_NativeTypedef_ typedef void* HANDLE;
_Win32_NativeTypedef_ typedef HANDLE HANDLE;
_Win32_NativeTypedef_ typedef int EXCLUDED;
FORWARDED Forward(FORWARDED value);
BOOL Alias(BOOL_ALIAS value);
HANDLE Pointer(HANDLE value);
", multipleFiles: multipleFiles, extraSettings: "--remap\nBOOL=int\nHANDLE=IntPtr\n--exclude\nEXCLUDED\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "annotation-owner.h"), @"
_Win32_NativeTypedef_ typedef int FORWARDED;
_Win32_NativeTypedef_ typedef int UNTRAVERSED;
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            foreach (string name in new[] { "FORWARDED", "BOOL", "BOOL_ALIAS" })
                AssertNativeTypedefStorage(reader, name, "Int32");
            AssertNativeTypedefStorage(reader, "HANDLE", "Void*");
            Assert.DoesNotContain(reader.TypeDefinitions, handle => reader.GetString(reader.GetTypeDefinition(handle).Name) is "UNTRAVERSED" or "EXCLUDED");
            var alias = FindMethod(reader, "Apis", "Alias").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("BOOL", alias.ReturnType);
            Assert.Equal(new[] { "BOOL_ALIAS" }, alias.ParameterTypes);
            Assert.Equal("FORWARDED", FindMethod(reader, "Apis", "Forward").DecodeSignature(new SignatureNames(), null).ReturnType);
            Assert.Equal("HANDLE", FindMethod(reader, "Apis", "Pointer").DecodeSignature(new SignatureNames(), null).ReturnType);
            AssertMetadataClosure(reader);
            SaveNativeTypedefArtifacts(fixture, "redeclarations-" + multipleFiles, reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeTypedefExistingOriginalIdlCommentTransportReachesPhysicalWinmd(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef wchar_t* BSTR;
typedef short VARIANT_BOOL;
typedef long LONG;
typedef _Return_type_success_(return >= 0) LONG HRESULT;
typedef int BOOL;
typedef unsigned char boolean;
typedef boolean BOOLEAN;
/* Win32Metadata: type ::BSTR => NativeTypedef */
/* Win32Metadata: type ::VARIANT_BOOL => NativeTypedef */
/* Win32Metadata: type ::HRESULT => Win32Metadata.NativeTypedef */
/* Win32Metadata: type ::BOOL => NativeTypedef */
/* Win32Metadata: type ::BOOLEAN => NativeTypedef */
struct IDL_RECORD { HRESULT result; BOOL booleanValue; BOOLEAN byteBoolean; };
HRESULT OriginalIdlMethod(BSTR text, VARIANT_BOOL value, BOOL flag, BOOLEAN byteFlag);
BOOL OriginalIdlBool(BOOL value);
struct __declspec(uuid(""f63722ce-16a2-432a-bd90-e900b8e72226"")) IOriginalIdlIdentity {
    virtual HRESULT __stdcall Read(BOOL value) = 0;
};
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(NativeSurface(fixture, target, false), NativeSurface(fixture, target, true));
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            AssertNativeTypedefStorage(reader, "BSTR", "UInt16*");
            AssertNativeTypedefStorage(reader, "VARIANT_BOOL", "Int16");
            AssertNativeTypedefStorage(reader, "HRESULT", "Int32");
            AssertNativeTypedefStorage(reader, "BOOL", "Int32");
            AssertNativeTypedefStorage(reader, "BOOLEAN", "Byte");
            var signature = FindMethod(reader, "Apis", "OriginalIdlMethod").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("HRESULT", signature.ReturnType);
            Assert.Equal(new[] { "BSTR", "VARIANT_BOOL", "BOOL", "BOOLEAN" }, signature.ParameterTypes);
            var boolean = FindMethod(reader, "Apis", "OriginalIdlBool").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("BOOL", boolean.ReturnType);
            Assert.Equal(new[] { "BOOL" }, boolean.ParameterTypes);
            Assert.Equal(new[] { "HRESULT", "BOOL", "BOOLEAN" }, FindType(reader, "IDL_RECORD").GetFields()
                .Select(reader.GetFieldDefinition).Select(field => field.DecodeSignature(new SignatureNames(), null)));
            var method = FindMethod(reader, "IOriginalIdlIdentity", "Read").DecodeSignature(new SignatureNames(), null);
            Assert.Equal("HRESULT", method.ReturnType);
            Assert.Equal(new[] { "BOOL" }, method.ParameterTypes);
            AssertMetadataClosure(reader);
            SaveNativeTypedefArtifacts(fixture, architecture + "-idl-comments", reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void NativeTypedefExistingTenProvidersKeepTheirPhysicalFacts(string architecture, string target, bool addIdentityMarkers)
        {
            string original = HeaderAnnotationTests.OpaqueHandleDeclarations + @"
typedef void* BCRYPT_HANDLE;
_Win32_AlsoUsableFor_(BCRYPT_HANDLE) typedef void* BCRYPT_KEY_HANDLE;
#if defined(_WIN64)
typedef unsigned long long ULONG_PTR;
#else
typedef unsigned long ULONG_PTR;
#endif
typedef ULONG_PTR NCRYPT_HANDLE;
_Win32_AlsoUsableFor_(NCRYPT_HANDLE) typedef ULONG_PTR NCRYPT_PROV_HANDLE;
_Win32_AlsoUsableFor_(NCRYPT_HANDLE) typedef ULONG_PTR NCRYPT_KEY_HANDLE;
BCRYPT_KEY_HANDLE UseKey(BCRYPT_KEY_HANDLE value);
NCRYPT_PROV_HANDLE UseProvider(NCRYPT_KEY_HANDLE value);
";
            string[] names = HeaderAnnotationTests.OpaqueHandleAliases.Select(alias => alias.Name)
                .Concat(new[] { "BCRYPT_KEY_HANDLE", "NCRYPT_PROV_HANDLE", "NCRYPT_KEY_HANDLE" }).ToArray();
            string marked = original + (addIdentityMarkers ? string.Concat(names.Select(name =>
                "\n_Win32_NativeTypedef_ typedef " + name + " " + name + ";\n")) : "");
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, marked);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            foreach (var alias in HeaderAnnotationTests.OpaqueHandleAliases)
            {
                AssertNativeTypedefStorage(reader, alias.Name, alias.Name + "__*");
                AssertStringAttribute(reader, FindType(reader, alias.Name).GetCustomAttributes(), "AlsoUsableForAttribute", alias.Target);
            }
            AssertNativeTypedefStorage(reader, "BCRYPT_KEY_HANDLE", "Void*");
            AssertNativeTypedefStorage(reader, "NCRYPT_PROV_HANDLE", "UIntPtr");
            AssertNativeTypedefStorage(reader, "NCRYPT_KEY_HANDLE", "UIntPtr");
            Assert.Equal(10, reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Count(type => type.GetCustomAttributes().Any(handle => AttributeName(reader, handle) == "NativeTypedefAttribute")));
            AssertMetadataClosure(reader);
            SaveNativeTypedefArtifacts(fixture, architecture + "-ten-providers-" + addIdentityMarkers, reader);

            string controlScraper = Environment.GetEnvironmentVariable("WIN32_NATIVE_TYPEDEF_CONTROL_SCRAPER");
            if (controlScraper != null)
            {
                using var control = new HeaderAnnotationTests.NativeFixture(architecture, target, original);
                string diagnostics = RunNativeTypedefControl(control, controlScraper);
                using var before = Emit(control, architecture);
                Assert.Equal(StructuredCommentSnapshot(before.Reader), StructuredCommentSnapshot(reader));
                SaveNativeTypedefArtifacts(control, architecture + "-ten-control-" + addIdentityMarkers, before.Reader,
                    new { diagnostics, scraper = controlScraper, scraperSha256 = FileSha256(controlScraper) });
            }
        }

        [Theory]
        [InlineData("_Win32_NativeTypedef_ int Function(void);", "not valid on")]
        [InlineData("struct _Win32_NativeTypedef_ Record { int field; };", "not valid on")]
        [InlineData("enum _Win32_NativeTypedef_ Mode { First };", "not valid on")]
        [InlineData("void Function(_Win32_NativeTypedef_ int value);", "not valid on")]
        [InlineData("_Win32_NativeTypedef_ const int Constant = 1;", "not valid on")]
        [InlineData("using Alias _Win32_NativeTypedef_ = int;", "not valid on")]
        [InlineData("_Win32_NativeTypedef_ typedef int (*Callback)(int);", "supported native scalar or data-pointer alias")]
        [InlineData("_Win32_NativeTypedef_ typedef int Callback(int);", "supported native scalar or data-pointer alias")]
        [InlineData("_Win32_NativeTypedef_ typedef int (**Callback)(int);", "supported native scalar or data-pointer alias")]
        [InlineData("_Win32_NativeTypedef_ typedef int Array[3];", "supported native scalar or data-pointer alias")]
        [InlineData("_Win32_NativeTypedef_ typedef int (*ArrayPointer)[3];", "supported native scalar or data-pointer alias")]
        [InlineData("_Win32_NativeTypedef_ typedef int& Reference;", "supported native scalar or data-pointer alias")]
        [InlineData("_Win32_NativeTypedef_ typedef void Empty;", "supported native scalar or data-pointer alias")]
        [InlineData("_Win32_NativeTypedef_ typedef enum Mode { First } Mode;", "supported native scalar or data-pointer alias")]
        [InlineData("_Win32_NativeTypedef_ typedef struct Opaque Opaque;", "supported native scalar or data-pointer alias")]
        [InlineData("typedef struct _WS_HEAP WS_HEAP;\n_Win32_NativeTypedef_ typedef WS_HEAP WS_HEAP;", "supported native scalar or data-pointer alias")]
        [InlineData("_Win32_NativeTypedef_ typedef struct Complete { int field; } Complete;", "supported native scalar or data-pointer alias")]
        [InlineData("typedef int Value __attribute__((annotate(\"Win32Metadata.NativeTypedef(1)\")));", "expects no value or parentheses")]
        [InlineData("typedef int Value __attribute__((annotate(\"Win32Metadata.NativeTypedef()\")));", "expects no value or parentheses")]
        [InlineData("_WIN32META_ANNOTATION_(\"NativeTypedef\", 1) typedef int Value;", "expects no value or compiler arguments")]
        [InlineData("#define FIRST 1\n_Win32_NativeTypedef_ _Win32_Enum_(Group, unsigned, FIRST);", "not valid on")]
        [InlineData("_Win32_NativeTypedef_ typedef unsigned Group;\n#define FIRST 1\n_Win32_Enum_(Group, unsigned, FIRST);", "not valid on")]
        [InlineData("int Function(void);\n/* Win32Metadata: function ::Function => NativeTypedef */", "not valid on")]
        [InlineData("typedef int Value;\n/* Win32Metadata: type ::Value => NativeTypedef(1) */", "expects no value or parentheses")]
        public void NativeTypedefMarkerRejectsUnsupportedTargetsAndValueShapes(string native, string expected)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", native);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("error WMA001:", fixture.Diagnostics);
            Assert.Contains(expected, fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
            Assert.False(File.Exists(Path.ChangeExtension(fixture.Output, ".header-types.cs")));
            SaveNativeTypedefArtifacts(fixture, "rejected-" + Convert.ToHexString(SHA256.HashData(System.Text.Encoding.UTF8.GetBytes(native)))[..12]);
        }

        [Theory]
        [InlineData("int", "IntPtr")]
        [InlineData("unsigned long long", "IntPtr")]
        [InlineData("long long", "UIntPtr")]
        [InlineData("long long", "IntPtr*")]
        public void NativeTypedefMarkerRejectsAbiChangingStorageRemaps(string native, string mapped)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "typedef " + native + " BASE;\n_Win32_NativeTypedef_ typedef BASE NOMINAL;\n",
                extraSettings: "--remap\nBASE=" + mapped + "\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("error WMA001:", fixture.Diagnostics);
            Assert.Contains("does not preserve native width, signedness, and pointer depth", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
            SaveNativeTypedefArtifacts(fixture, "rejected-remap-" + native.Replace(' ', '-') + "-" + mapped.Replace("*", "pointer"));
        }

        [Fact]
        public void NativeTypedefMarkerDoesNotPromoteAliasesWithoutReaderOptIn()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "_Win32_NativeTypedef_ typedef int BOOL;\nBOOL RoundTrip(BOOL value);\n", annotationsEnabled: false);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.False(File.Exists(Path.ChangeExtension(fixture.Output, ".header-types.cs")));
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            Assert.DoesNotContain(reader.TypeDefinitions, handle => reader.GetString(reader.GetTypeDefinition(handle).Name) == "BOOL");
            Assert.Equal("Int32", FindMethod(reader, "Apis", "RoundTrip").DecodeSignature(new SignatureNames(), null).ReturnType);
            SaveNativeTypedefArtifacts(fixture, "reader-disabled", reader);
        }
    }
}

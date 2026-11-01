using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text.Json;
using System.Text.RegularExpressions;
using Xunit;
using static Win32MetadataScraperTests.HeaderAnnotationWinmdTests;

namespace Win32MetadataScraperTests
{
    public class HeaderCompatibilityPatchTests
    {
        [Fact]
        public void ActiveWaitDeclarationsPreserveNativeStatusResults()
        {
            string root = RepositoryRoot();
            string patch = File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "patches", "um", "synchapi.h.patch"));
            foreach (string name in new[] { "WaitForSingleObject", "WaitForSingleObjectEx", "WaitForMultipleObjects", "WaitForMultipleObjectsEx" })
                Assert.Contains("+_Win32_PreserveResult_ _Win32_AssociatedEnum_(WAIT_EVENT) WINBASEAPI\n DWORD\n WINAPI\n " + name + "(",
                    patch.Replace("\r\n", "\n"));
            Assert.Contains("<IncludeRoot>/um/synchapi.h", File.ReadAllText(
                Path.Combine(root, "generation", "WinSDK", "Partitions", "Threading", "settings.rsp")));
        }

        [Fact]
        public void SharedDxgiUsageGroupHasOneProjectionNamespace()
        {
            string root = RepositoryRoot();
            var routes = File.ReadAllLines(Path.Combine(root, "generation", "WinSDK", "requiredNamespacesForNames.rsp"))
                .Where(line => line.StartsWith("DXGI_USAGE=", StringComparison.Ordinal));
            Assert.Equal("DXGI_USAGE=Windows.Win32.Graphics.Dxgi", Assert.Single(routes));
            string patch = File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "patches", "shared", "dxgi.idl.patch"));
            Assert.Contains("_Win32_FlagsEnum_(DXGI_USAGE, unsigned int, DXGI_USAGE_SHADER_INPUT, " +
                "DXGI_USAGE_RENDER_TARGET_OUTPUT, DXGI_USAGE_BACK_BUFFER, DXGI_USAGE_SHARED, DXGI_USAGE_READ_ONLY, " +
                "DXGI_USAGE_DISCARD_ON_PRESENT, DXGI_USAGE_UNORDERED_ACCESS);", patch);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", 4, 4)]
        [InlineData("x64", "x86_64-pc-windows-msvc", 16, 16)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", 16, 16)]
        public void BackupSListAliasesRetainNativeRecordProviders(
            string architecture, string target, int size, int alignment)
        {
            using var headers = new PatchedHeaders(@"um\winnt.h");
            string original = headers.ReadOriginal(@"um\winnt.h").Replace("\r\n", "\n");
            string patched = headers.Read(@"um\winnt.h").Replace("\r\n", "\n");
            const string singleStart = "typedef struct _SINGLE_LIST_ENTRY {";
            const string singleEnd = "\n// end_ntoshvp";
            const string slistStart = "#if defined(_WIN64)\n\n//\n// The type SINGLE_LIST_ENTRY";
            const string slistEnd = "\n#if defined(_AMD64_)";
            string single = Between(original, singleStart, singleEnd);
            string slist = Between(original, slistStart, slistEnd);
            Assert.Equal(single, Between(patched, singleStart, singleEnd));
            Assert.Equal(slist, Between(patched, slistStart, slistEnd));
            Assert.Contains("typedef struct _SINGLE_LIST_ENTRY SLIST_ENTRY, *PSLIST_ENTRY;", slist);

            string sdk = Path.Combine(RepositoryRoot(), "generation", "WinSDK");
            string settings = File.ReadAllText(Path.Combine(sdk, "Partitions", "Backup", "settings.rsp"))
                .Replace("\r\n", "\n");
            string exclusions = Between(settings, "--exclude\n", "--traverse\n");
            string[] excludedNames = exclusions.Split('\n', StringSplitOptions.RemoveEmptyEntries);
            Assert.DoesNotContain("_SINGLE_LIST_ENTRY", excludedNames);
            Assert.Contains("_LIST_ENTRY", excludedNames);
            string pointerMapping = Assert.Single(File.ReadAllLines(Path.Combine(sdk, "scraper.settings.rsp")),
                line => line.StartsWith("PSLIST_ENTRY=", StringComparison.Ordinal));
            Assert.Equal("PSLIST_ENTRY=SLIST_ENTRY*", pointerMapping);
            var requiredNamespaces = File.ReadAllLines(Path.Combine(sdk, "requiredNamespacesForNames.rsp"))
                .Where(line => line.StartsWith("SLIST_ENTRY=", StringComparison.Ordinal) ||
                    line.StartsWith("SINGLE_LIST_ENTRY=", StringComparison.Ordinal))
                .Select(line => line.Split('=', 2)).ToDictionary(parts => parts[0], parts => parts[1]);
            const string canonicalNamespace = "Windows.Win32.System.Kernel";
            Assert.Equal(canonicalNamespace, requiredNamespaces["SLIST_ENTRY"]);
            Assert.Equal(canonicalNamespace, requiredNamespaces["SINGLE_LIST_ENTRY"]);

            const string declarations = @"
#ifdef __cplusplus
#ifdef _WIN64
static_assert(!__is_same(SLIST_ENTRY, SINGLE_LIST_ENTRY), ""64-bit SLIST entries are a distinct native record."");
#else
static_assert(__is_same(SLIST_ENTRY, SINGLE_LIST_ENTRY), ""x86 SLIST entries retain their native alias identity."");
#endif
extern ""C"" {
#endif
PSLIST_ENTRY __stdcall ReadSListAlias(PSLIST_ENTRY entry);
SLIST_ENTRY* __stdcall ReadSListRecord(SLIST_ENTRY* entry);
#ifdef __cplusplus
}
#endif
";
            const string projectionNamespace = "Windows.Win32.System.SystemServices";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target,
                "#define DECLSPEC_ALIGN(n) __declspec(align(n))\n" + single + "\n" + slist + declarations,
                extraSettings: "--config\nexclude-empty-records\n" + exclusions + "--remap\n" + pointerMapping + "\n",
                namespaceName: projectionNamespace);
            string evidenceRoot = Environment.GetEnvironmentVariable("WIN32_TYPEDEF_PROTOTYPE_EVIDENCE_ROOT");
            string evidence = evidenceRoot == null ? null : Path.Combine(evidenceRoot, architecture + "-sdk-slist");
            if (evidence != null)
            {
                Assert.False(Directory.Exists(evidence), "Every SDK SLIST invocation requires a new evidence directory.");
                Directory.CreateDirectory(evidence);
            }
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                string[] expectedWarnings = architecture == "x86" ? Array.Empty<string>() : new[]
                {
                    "Struct 'SLIST_ENTRY' requests 16 byte alignment which .NET cannot honor; " +
                    "over-alignment can only lower, never raise, alignment, so the runtime will align it to 8 bytes.",
                };
                Assert.Equal(expectedWarnings, Regex.Matches(fixture.Diagnostics,
                    @"(?m)^\s*Warning \([^\r\n]+\): ([^\r\n]+)").Select(match => match.Groups[1].Value.TrimEnd()));
                Assert.DoesNotContain("Error (", fixture.Diagnostics);
                Assert.DoesNotContain("error:", fixture.Diagnostics);
                Assert.True(File.Exists(fixture.Output), fixture.Diagnostics);
                string nativeRecord = architecture == "x86" ? "_SINGLE_LIST_ENTRY" : "_SLIST_ENTRY";
                foreach (string language in new[] { "c", "c++" })
                {
                    string[] surface = NativeSurface(fixture, target, metadataEnabled: false, language);
                    if (evidence != null)
                        File.WriteAllLines(Path.Combine(fixture.DirectoryPath, language + ".native-surface.txt"), surface);
                    Assert.Contains($"record {nativeRecord} {size} {alignment}", surface);
                }

                using var image = Emit(fixture.DirectoryPath, architecture, requiredNamespaces: requiredNamespaces);
                var reader = image.Reader;
                var decoder = new SignatureNames(qualifiedNames: true);
                string projectedPointer = canonicalNamespace + ".SLIST_ENTRY*";
                var record = FindType(reader, "SLIST_ENTRY");
                Assert.Equal(canonicalNamespace, reader.GetString(record.Namespace));
                var next = reader.GetFieldDefinition(Assert.Single(record.GetFields()));
                Assert.Equal("Next", reader.GetString(next.Name));
                Assert.Equal(projectedPointer, next.DecodeSignature(decoder, null));
                Assert.Contains(next.GetOffset(), new[] { -1, 0 });
                Assert.Equal(size, Math.Max(architecture == "x86" ? 4 : 8, record.GetLayout().Size));
                if (architecture != "x86")
                {
                    var attribute = reader.GetCustomAttribute(Assert.Single(record.GetCustomAttributes(),
                        handle => AttributeName(reader, handle) == "AlignmentAttribute"));
                    var value = reader.GetBlobReader(attribute.Value);
                    Assert.Equal(1, value.ReadUInt16());
                    Assert.Equal(alignment, value.ReadInt32());
                    Assert.Equal(0, value.ReadUInt16());
                    Assert.Equal(0, value.RemainingBytes);
                }
                else
                {
                    var canonicalRecord = FindType(reader, "SINGLE_LIST_ENTRY");
                    Assert.Equal(canonicalNamespace, reader.GetString(canonicalRecord.Namespace));
                    var canonicalNext = reader.GetFieldDefinition(Assert.Single(canonicalRecord.GetFields()));
                    Assert.Equal("Next", reader.GetString(canonicalNext.Name));
                    Assert.Equal(canonicalNamespace + ".SINGLE_LIST_ENTRY*", canonicalNext.DecodeSignature(decoder, null));
                    Assert.Equal(size, Math.Max(4, canonicalRecord.GetLayout().Size));
                }
                foreach (string name in new[] { "ReadSListAlias", "ReadSListRecord" })
                {
                    // The pointer remap names SLIST_ENTRY; a direct x86 record alias resolves to SINGLE_LIST_ENTRY.
                    string expectedPointer = architecture == "x86" && name == "ReadSListRecord"
                        ? canonicalNamespace + ".SINGLE_LIST_ENTRY*" : projectedPointer;
                    var signature = FindMethod(reader, "Apis", name).DecodeSignature(decoder, null);
                    Assert.Equal(expectedPointer, signature.ReturnType);
                    Assert.Equal(expectedPointer, Assert.Single(signature.ParameterTypes));
                }
                AssertMetadataClosure(reader);
            }
            finally
            {
                fixture.Retain(evidence);
            }
        }

        [Fact]
        public void ActiveFileAndSocketDeclarationsPreserveNativeResults()
        {
            string root = RepositoryRoot();
            foreach (var (header, name, prefix, os, linkage, convention) in new[]
            {
                ("fileapi.h", "GetFileAttributesA", "", "WindowsXP", "WINBASEAPI", "WINAPI"),
                ("fileapi.h", "GetFileAttributesW", "", "WindowsXP", "WINBASEAPI", "WINAPI"),
                ("fileapi.h", "QueryDosDeviceW", "", "WindowsXP", "WINBASEAPI", "WINAPI"),
                ("winsock2.h", "WSAWaitForMultipleEvents", "_Win32_AssociatedEnum_(WAIT_EVENT) ",
                    "Windows81", "WINSOCK_API_LINKAGE", "WSAAPI"),
            })
            {
                string patch = File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "patches", "um", header + ".patch"))
                    .Replace("\r\n", "\n");
                Assert.Contains("+_Win32_PreserveResult_ " + prefix + "_Win32_SetLastError_\n" +
                    "+_Win32_SupportedOS_" + os + "_\n " + linkage + "\n DWORD\n " + convention + "\n " + name + "(", patch);
            }
            foreach (var (partition, header) in new[] { ("Fs", "fileapi.h"), ("WinSock", "WinSock2.h") })
            {
                string directory = Path.Combine(root, "generation", "WinSDK", "Partitions", partition);
                Assert.Contains("<IncludeRoot>/um/" + header, File.ReadAllText(Path.Combine(directory, "settings.rsp")));
                Assert.Contains("#include <" + header.ToLowerInvariant() + ">", File.ReadAllText(Path.Combine(directory, "main.cpp")));
            }
        }

        [Fact]
        public void CompatibilityPatchesPreserveResultsWidthsAndInputHandleDirections()
        {
            using var headers = new PatchedHeaders();
            string callbacks = CallbackDeclarations(headers.Read(@"shared\minwindef.h"));
            string originalCallbacks = CallbackDeclarations(headers.ReadOriginal(@"shared\minwindef.h"));
            string iads = headers.Read(@"um\Iads.h");
            string searchMethods = Between(iads, "        _Win32_PreserveResult_\r\n",
                "        virtual HRESULT STDMETHODCALLTYPE GetColumn(");
            string listener = headers.Read(@"um\alljoyn_c\AboutDataListener.h");
            string about = Callback(listener, "alljoyn_aboutdatalistener_getaboutdata_ptr");
            string announced = Callback(listener, "alljoyn_aboutdatalistener_getannouncedaboutdata_ptr");
            string dbghelp = headers.Read(@"um\dbghelp.h");
            var guards = Regex.Matches(dbghelp,
                @"#if defined\(WIN32METADATA\)\r?\n#pragma push_macro\(""SearchPath""\)[\s\S]*?#pragma pop_macro\(""SearchPath""\)\r?\n#endif")
                .Select(match => match.Value).ToArray();
            string[] names = { "SymFindFileInPath", "SymFindFileInPathW", "SymGetSearchPath",
                "SymGetSearchPathW", "SymSetSearchPath", "SymSetSearchPathW", "FindFileInPath", "FindFileInSearchPath" };
            Assert.Equal(names.Length, guards.Length);
            foreach (string name in names)
                Assert.Single(guards, guard => Regex.IsMatch(guard, @"\b" + name + @"\("));
            string search = Assert.Single(guards, guard => guard.Contains("SymSetSearchPathW("));
            Assert.Contains("typedef ADS_SEARCH_HANDLE *PADS_SEARCH_HANDLE;", iads);
            Assert.DoesNotContain("_Win32_NativeTypedef_", iads);
            const string types = @"
#define FAR
#define NEAR
#define WINAPI __stdcall
#define CALLBACK __stdcall
#define IMAGEAPI __stdcall
#define STDMETHODCALLTYPE __stdcall
#define __RPC__in _In_
#define __RPC__deref_out_opt _Out_
typedef __INTPTR_TYPE__ INT_PTR;
typedef void* HANDLE;
typedef HANDLE ADS_SEARCH_HANDLE;
typedef ADS_SEARCH_HANDLE* PADS_SEARCH_HANDLE;
typedef long HRESULT;
typedef int BOOL;
typedef int QStatus;
typedef wchar_t* LPWSTR;
typedef const wchar_t* PCWSTR;
typedef struct _alljoyn_msgarg_handle* alljoyn_msgarg;
static_assert(sizeof(PADS_SEARCH_HANDLE) == sizeof(void*), ""Native pointer width must not change."");
static_assert(__is_same(PADS_SEARCH_HANDLE, HANDLE*), ""The ADS alias refactor must preserve native type identity."");
";
            string other = "\nstruct CallbackShape { PROC value; };\n" +
                "struct __declspec(uuid(\"109ba8ec-92f0-11d0-a790-00c04fd8d5a8\")) IDirectorySearch {\n" +
                searchMethods + "\n};\n" + about + "\n" + announced + @"
extern ""C"" {
int __stdcall CreateOutput(_Out_ alljoyn_msgarg* output);
#define SearchPath SearchPathW
" + search + @"
void __stdcall AfterSearch(PCWSTR SearchPath);
}
";
            foreach (var (architecture, target) in new[]
            {
                ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
            })
            {
                using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target,
                    types + callbacks + other,
                    extraSettings: "-DWIN32METADATA\n-DUNICODE\n--remap\nHRESULT=HRESULT\n");
                fixture.AssertSuccess();
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                foreach (string name in new[] { "FARPROC", "NEARPROC", "PROC" })
                {
                    var invoke = FindMethod(reader, name, "Invoke");
                    Assert.Equal("IntPtr", invoke.DecodeSignature(new SignatureNames(), null).ReturnType);
                    var convention = reader.GetCustomAttribute(FindType(reader, name).GetCustomAttributes()
                        .Single(handle => AttributeName(reader, handle) == "UnmanagedFunctionPointerAttribute"));
                    var blob = reader.GetBlobReader(convention.Value);
                    Assert.Equal(1, blob.ReadUInt16());
                    Assert.Equal((int)System.Runtime.InteropServices.CallingConvention.Winapi, blob.ReadInt32());
                    Assert.Equal(0, blob.ReadUInt16());
                    Assert.Equal(0, blob.RemainingBytes);
                }
                var hresult = FindType(reader, "HRESULT");
                AssertHasAttribute(reader, hresult.GetCustomAttributes(), "NativeTypedefAttribute");
                var hresultValue = reader.GetFieldDefinition(Assert.Single(hresult.GetFields()));
                Assert.Equal("Value", reader.GetString(hresultValue.Name));
                Assert.Equal("Int32", hresultValue.DecodeSignature(new SignatureNames(), null));
                string resultType = reader.GetString(hresult.Namespace) + "." + reader.GetString(hresult.Name);
                foreach (string name in new[] { "GetFirstRow", "GetNextRow", "GetPreviousRow", "GetNextColumnName" })
                {
                    var method = FindMethod(reader, "IDirectorySearch", name);
                    Assert.True(method.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig), name);
                    Assert.Equal(resultType, method.DecodeSignature(new SignatureNames(qualifiedNames: true), null).ReturnType);
                }
                foreach (string name in new[] { "alljoyn_aboutdatalistener_getaboutdata_ptr",
                    "alljoyn_aboutdatalistener_getannouncedaboutdata_ptr" })
                {
                    var parameter = FindMethod(reader, name, "Invoke").GetParameters().Select(reader.GetParameter)
                        .Single(value => reader.GetString(value.Name) == "msgArg");
                    Assert.Equal(ParameterAttributes.In, parameter.Attributes);
                }
                var output = FindMethod(reader, "Apis", "CreateOutput").GetParameters()
                    .Select(reader.GetParameter).Single(value => value.SequenceNumber == 1);
                Assert.Equal(ParameterAttributes.Out, output.Attributes);
                var guarded = FindMethod(reader, "Apis", "SymSetSearchPathW").GetParameters()
                    .Select(reader.GetParameter).Single(value => value.SequenceNumber == 2);
                Assert.Equal("SearchPath", reader.GetString(guarded.Name));
                var after = FindMethod(reader, "Apis", "AfterSearch").GetParameters()
                    .Select(reader.GetParameter).Single(value => value.SequenceNumber == 1);
                Assert.Equal("SearchPathW", reader.GetString(after.Name));
                using var ordinary = new HeaderAnnotationTests.NativeFixture(architecture, target,
                    types + originalCallbacks + other, annotationsEnabled: false);
                Assert.Equal(NativeSurface(ordinary, target, metadataEnabled: false),
                    NativeSurface(fixture, target, metadataEnabled: false));
                AssertMetadataClosure(reader);
            }
        }

        [Fact]
        public void DirectMlPartitionSelectsLatestForDeclarationsAndNativeConstants()
        {
            string root = RepositoryRoot();
            string partition = File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "Partitions", "DirectML", "main.cpp"));
            int define = partition.IndexOf("#define DML_TARGET_VERSION_USE_LATEST", StringComparison.Ordinal);
            Assert.InRange(define, 0, partition.IndexOf("#include", StringComparison.Ordinal) - 1);
            string header = File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders", "um", "DirectML.h"));
            string version = Between(header, "#ifndef DML_TARGET_VERSION",
                "// ===================================================================================================================");
            string declarations = "#define DML_TARGET_VERSION_USE_LATEST\n#define NTDDI_VERSION 0x0A000012\n" +
                "#define NTDDI_WIN11_ZN 0x0A00000E\n#define NTDDI_WIN10_NI 0x0A00000C\n" + version +
                "\nenum DML_VERSION_CHECK { DmlVersionCheck = DML_TARGET_VERSION };\n";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                declarations, extraSettings: "--config\nnative-constant-values\n");
            string names = Path.Combine(fixture.DirectoryPath, "names.txt");
            File.WriteAllLines(names, new[] { "DML_TARGET_VERSION", "DML_TARGET_VERSION_USE_LATEST",
                "NTDDI_VERSION", "NTDDI_WIN11_ZN", "NTDDI_WIN10_NI" }.OrderBy(name => name, StringComparer.Ordinal));
            File.AppendAllText(Path.Combine(fixture.DirectoryPath, "test.rsp"), "--constant-names-file\n" + names + "\n");
            fixture.AssertSuccess();
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            var field = FindType(reader, "DML_VERSION_CHECK").GetFields().Select(reader.GetFieldDefinition)
                .Single(value => reader.GetString(value.Name) == "DmlVersionCheck");
            var value = reader.GetBlobReader(reader.GetConstant(field.GetDefaultValue()).Value);
            Assert.Equal(0x6400, value.ReadInt32());
            var constants = JsonSerializer.Deserialize<MetadataUtils.NativeConstantValues>(File.ReadAllText(
                Path.ChangeExtension(fixture.Output, ".native-constants.json")));
            var targetVersion = Assert.Single(constants.Constants, item => item.NativeName == "DML_TARGET_VERSION");
            Assert.Equal("25600", targetVersion.Value);
            Assert.Equal("int", targetVersion.NativeType);
            Assert.Contains(targetVersion.Evaluation, new[] { "Clang", "Scanner" });
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", 24, 4)]
        [InlineData("x64", "x86_64-pc-windows-msvc", 48, 8)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", 48, 8)]
        public void ProcessBasicInformationUsesDocumentedFieldsWithoutChangingNativeLayout(
            string architecture, string target, int size, int alignment)
        {
            using var headers = new PatchedHeaders();
            string original = headers.ReadOriginal(@"um\winternl.h").Replace("\r\n", "\n");
            string patched = headers.Read(@"um\winternl.h").Replace("\r\n", "\n");
            string declaration = Between(patched, "typedef struct _PROCESS_BASIC_INFORMATION {",
                "\ntypedef PROCESS_BASIC_INFORMATION *PPROCESS_BASIC_INFORMATION;");
            string sdkDeclaration = Between(original, "typedef struct _PROCESS_BASIC_INFORMATION {",
                "\ntypedef PROCESS_BASIC_INFORMATION *PPROCESS_BASIC_INFORMATION;");
            string sdkRecord = sdkDeclaration.Replace("_PROCESS_BASIC_INFORMATION", "_SDK_PROCESS_BASIC_INFORMATION",
                StringComparison.Ordinal).Replace("} PROCESS_BASIC_INFORMATION;", "} SDK_PROCESS_BASIC_INFORMATION;",
                StringComparison.Ordinal);
            Assert.Contains("#else\n" + Between(sdkDeclaration, "    PVOID Reserved1;", "\n} PROCESS_BASIC_INFORMATION;")
                + "\n#endif", declaration);
            string root = Path.Combine(RepositoryRoot(), "generation", "WinSDK", "RecompiledIdlHeaders");
            string winnt = File.ReadAllText(Path.Combine(root, "um", "winnt.h"));
            string basetsd = File.ReadAllText(Path.Combine(root, "shared", "basetsd.h")).Replace("\r\n", "\n");
            Assert.Contains("typedef long LONG;", winnt);
            Assert.Contains("typedef void *PVOID;", winnt);
            Assert.Contains("} PEB, *PPEB;", original);
            string types = "typedef long LONG;\ntypedef void *PVOID;\ntypedef struct _PEB *PPEB;\n"
                + Between(original, "typedef _Return_type_success_(return >= 0) LONG NTSTATUS;", "\n")
                + "\n" + Between(original, "typedef LONG KPRIORITY;", "\n") + "\n"
                + Between(basetsd, "#if !defined(_W64)", "\n//\n// HANDLE64 uses 64 bits") + "\n";
            const string assertions = @"
#ifdef __cplusplus
#define ABI_CHECK static_assert
#define ABI_ALIGNOF alignof
#else
#define ABI_CHECK _Static_assert
#define ABI_ALIGNOF _Alignof
#endif
ABI_CHECK(sizeof(NTSTATUS) == 4 && sizeof(KPRIORITY) == 4, ""Native signed scalar widths."");
ABI_CHECK(sizeof(ULONG_PTR) == sizeof(PVOID), ""Native pointer-sized unsigned storage."");
ABI_CHECK(sizeof(PROCESS_BASIC_INFORMATION) == sizeof(SDK_PROCESS_BASIC_INFORMATION), ""PBI size."");
ABI_CHECK(ABI_ALIGNOF(PROCESS_BASIC_INFORMATION) == ABI_ALIGNOF(SDK_PROCESS_BASIC_INFORMATION), ""PBI alignment."");
ABI_CHECK(__builtin_offsetof(PROCESS_BASIC_INFORMATION, PebBaseAddress) ==
          __builtin_offsetof(SDK_PROCESS_BASIC_INFORMATION, PebBaseAddress), ""PEB pointer offset."");
ABI_CHECK(__builtin_offsetof(PROCESS_BASIC_INFORMATION, UniqueProcessId) ==
          __builtin_offsetof(SDK_PROCESS_BASIC_INFORMATION, UniqueProcessId), ""Process ID offset."");
#if defined(WIN32METADATA)
ABI_CHECK(__builtin_offsetof(PROCESS_BASIC_INFORMATION, ExitStatus) ==
          __builtin_offsetof(SDK_PROCESS_BASIC_INFORMATION, Reserved1), ""Exit status offset."");
ABI_CHECK(__builtin_offsetof(PROCESS_BASIC_INFORMATION, AffinityMask) ==
          __builtin_offsetof(SDK_PROCESS_BASIC_INFORMATION, Reserved2[0]), ""Affinity offset."");
ABI_CHECK(__builtin_offsetof(PROCESS_BASIC_INFORMATION, BasePriority) ==
          __builtin_offsetof(SDK_PROCESS_BASIC_INFORMATION, Reserved2[1]), ""Priority offset."");
ABI_CHECK(__builtin_offsetof(PROCESS_BASIC_INFORMATION, InheritedFromUniqueProcessId) ==
          __builtin_offsetof(SDK_PROCESS_BASIC_INFORMATION, Reserved3), ""Parent process ID offset."");
#ifdef __cplusplus
ABI_CHECK(__is_same(decltype(PROCESS_BASIC_INFORMATION::ExitStatus), NTSTATUS), ""Exit status type."");
ABI_CHECK(__is_same(decltype(PROCESS_BASIC_INFORMATION::PebBaseAddress), PPEB), ""PEB pointer type."");
ABI_CHECK(__is_same(decltype(PROCESS_BASIC_INFORMATION::AffinityMask), ULONG_PTR), ""Affinity type."");
ABI_CHECK(__is_same(decltype(PROCESS_BASIC_INFORMATION::BasePriority), KPRIORITY), ""Priority type."");
ABI_CHECK(__is_same(decltype(PROCESS_BASIC_INFORMATION::UniqueProcessId), ULONG_PTR), ""Process ID type."");
ABI_CHECK(__is_same(decltype(PROCESS_BASIC_INFORMATION::InheritedFromUniqueProcessId), ULONG_PTR), ""Parent process ID type."");
#endif
#endif
";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target,
                types + declaration + "\n" + sdkRecord + assertions,
                extraSettings: "-DWIN32METADATA\n--remap\nLONG=LONG\nNTSTATUS=NTSTATUS\n" +
                    "KPRIORITY=KPRIORITY\nPPEB=PPEB\n");
            fixture.AssertSuccess();
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var decoder = new SignatureNames(qualifiedNames: true);
            var fields = FindType(reader, "PROCESS_BASIC_INFORMATION").GetFields()
                .Select(reader.GetFieldDefinition).Select(field =>
                    (reader.GetString(field.Name), field.DecodeSignature(decoder, null))).ToArray();
            Assert.Equal(new[]
            {
                ("ExitStatus", "Test.NTSTATUS"), ("PebBaseAddress", "Test.PPEB"),
                ("AffinityMask", "UIntPtr"), ("BasePriority", "Test.KPRIORITY"),
                ("UniqueProcessId", "UIntPtr"), ("InheritedFromUniqueProcessId", "UIntPtr"),
            }, fields);
            foreach (var (name, storage) in new[]
            {
                ("NTSTATUS", "Test.LONG"), ("KPRIORITY", "Test.LONG"),
                ("LONG", "Int32"), ("PPEB", "Test._PEB*"),
            })
            {
                var alias = FindType(reader, name);
                Assert.Equal("Test", reader.GetString(alias.Namespace));
                AssertHasAttribute(reader, alias.GetCustomAttributes(), "NativeTypedefAttribute");
                var value = reader.GetFieldDefinition(Assert.Single(alias.GetFields()));
                Assert.Equal("Value", reader.GetString(value.Name));
                Assert.Equal(storage, value.DecodeSignature(decoder, null));
            }
            var peb = FindType(reader, "_PEB");
            Assert.Equal("Test", reader.GetString(peb.Namespace));
            Assert.Empty(peb.GetFields());
            AssertDoesNotHaveAttribute(reader, peb.GetCustomAttributes(), "NativeTypedefAttribute");
            Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                type => reader.GetString(type.Name) == "ULONG_PTR");
            AssertMetadataClosure(reader);
            var metadataSurface = NativeSurface(fixture, target, metadataEnabled: true);
            Assert.Contains($"record _PROCESS_BASIC_INFORMATION {size} {alignment}", metadataSurface);
            using var ordinary = new HeaderAnnotationTests.NativeFixture(architecture, target,
                types + sdkDeclaration + "\n" + sdkRecord + assertions, annotationsEnabled: false);
            foreach (string language in new[] { "c", "c++" })
                Assert.Equal(NativeSurface(ordinary, target, metadataEnabled: false, language),
                    NativeSurface(fixture, target, metadataEnabled: false, language));
        }

        private static string CallbackDeclarations(string header)
            => Between(header, "#ifndef _MANAGED", "\ntypedef WORD");

        private static string Callback(string header, string name)
            => Assert.Single(Regex.Matches(header, @"typedef QStatus \(AJ_CALL \* " + name + @"\)[\s\S]*?;")
                .Select(match => match.Value)).Replace("AJ_CALL", "__stdcall", StringComparison.Ordinal);

        private static string Between(string text, string start, string end)
        {
            int first = text.IndexOf(start, StringComparison.Ordinal);
            Assert.True(first >= 0, start);
            int last = text.IndexOf(end, first + start.Length, StringComparison.Ordinal);
            Assert.True(last > first, end);
            return text.Substring(first, last - first);
        }

        private static string RepositoryRoot([CallerFilePath] string source = null)
            => Path.GetFullPath(Path.Combine(Path.GetDirectoryName(source), "..", ".."));

        private sealed class PatchedHeaders : IDisposable
        {
            private readonly string root = Path.Combine(Path.GetTempPath(), "header-compatibility-" + Guid.NewGuid().ToString("N"));
            private readonly string sdk = Path.Combine(RepositoryRoot(), "generation", "WinSDK");

            internal PatchedHeaders(params string[] headers)
            {
                using var recipe = JsonDocument.Parse(File.ReadAllText(Path.Combine(this.sdk, "patches", "SdkHeaders.json")));
                foreach (string header in headers.Length != 0 ? headers : new[] { @"shared\minwindef.h", @"um\winternl.h",
                    @"um\Iads.h", @"um\alljoyn_c\AboutDataListener.h", @"um\dbghelp.h" })
                {
                    string source = Path.Combine(this.sdk, "RecompiledIdlHeaders", header);
                    var entry = Assert.Single(recipe.RootElement.GetProperty("headers").EnumerateArray(),
                        item => item.GetProperty("path").GetString() == header);
                    Assert.Equal(entry.GetProperty("sourceSha256").GetString(),
                        Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(source))));
                    string destination = Path.Combine(this.root, header);
                    Directory.CreateDirectory(Path.GetDirectoryName(destination));
                    File.Copy(source, destination);
                    RunGit(header, check: true);
                    RunGit(header, check: false);
                }
            }

            internal string Read(string header) => File.ReadAllText(Path.Combine(this.root, header));
            internal string ReadOriginal(string header) => File.ReadAllText(Path.Combine(this.sdk, "RecompiledIdlHeaders", header));

            private void RunGit(string header, bool check)
            {
                var start = new ProcessStartInfo("git")
                { WorkingDirectory = RepositoryRoot(), UseShellExecute = false, RedirectStandardOutput = true, RedirectStandardError = true };
                foreach (string argument in new[] { "-c", "core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol",
                    "apply", "--unsafe-paths", "-p1", "--directory=" + this.root, "--whitespace=error-all" })
                    start.ArgumentList.Add(argument);
                if (check)
                    start.ArgumentList.Add("--check");
                start.ArgumentList.Add(Path.Combine(this.sdk, "patches", header + ".patch"));
                using var process = Process.Start(start);
                var output = process.StandardOutput.ReadToEndAsync();
                var error = process.StandardError.ReadToEndAsync();
                process.WaitForExit();
                Assert.True(process.ExitCode == 0, output.GetAwaiter().GetResult() + error.GetAwaiter().GetResult());
            }

            public void Dispose() => Directory.Delete(this.root, recursive: true);
        }
    }
}

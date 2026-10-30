using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Runtime.CompilerServices;
using System.Text.RegularExpressions;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Win32MetadataScraper;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    public partial class NativeContractBatchTests
    {
        private readonly ITestOutputHelper output;

        public NativeContractBatchTests(ITestOutputHelper output) => this.output = output;

        private const string AdditionalDeclarations =
            Win32MetadataTestCases.HeaderAnnotationCases.NativeContractAdditionalDeclarations + @"
typedef unsigned long DWORD;
typedef int BOOL;
enum WAIT_EVENT : unsigned long { WAIT_OBJECT_0 = 0, WAIT_ABANDONED = 128, WAIT_IO_COMPLETION = 192, WAIT_TIMEOUT = 258, WAIT_FAILED = 0xffffffffUL };
extern ""C"" {
_Win32_SetLastError_ _Win32_SupportedOS_WindowsXP_ _Win32_AssociatedEnum_(WAIT_EVENT)
DWORD __stdcall _Win32_PreserveResult_ WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
_Win32_SetLastError_ _Win32_SupportedOS_WindowsXP_ _Win32_AssociatedEnum_(WAIT_EVENT)
DWORD __stdcall _Win32_PreserveResult_ WaitForSingleObjectEx(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable);
_Win32_SetLastError_ _Win32_SupportedOS_WindowsXP_ _Win32_AssociatedEnum_(WAIT_EVENT)
DWORD __stdcall _Win32_PreserveResult_ WaitForMultipleObjects(DWORD nCount, const HANDLE* lpHandles, BOOL bWaitAll, DWORD dwMilliseconds);
_Win32_SetLastError_ _Win32_SupportedOS_WindowsXP_ _Win32_AssociatedEnum_(WAIT_EVENT)
DWORD __stdcall _Win32_PreserveResult_ WaitForMultipleObjectsEx(DWORD nCount, const HANDLE* lpHandles, BOOL bWaitAll, DWORD dwMilliseconds, BOOL bAlertable);
DWORD __stdcall WaitResultWithoutPreserveResult(DWORD dwMilliseconds);
}
";

        private const string ImageHlpLastErrorDeclarations = @"
extern ""C"" {
void* __stdcall _Win32_SetLastError_ ImageRvaToSection(void* headers, void* image, unsigned long rva);
void* __stdcall _Win32_SetLastError_ ImageRvaToVa(void* headers, void* image, unsigned long rva, void** section);
HANDLE __stdcall _Win32_SetLastError_ FindDebugInfoFile(const char* fileName, const char* searchPath, char* result);
void* __stdcall ImageHlpWithoutLastError(void* image);
}
";

        private const string FileAndSocketResultDeclarations = @"
typedef unsigned long DWORD;
typedef int BOOL;
typedef const char* LPCSTR;
typedef const wchar_t* LPCWSTR;
typedef wchar_t* LPWSTR;
typedef void* WSAEVENT;
enum BATCH_SOCKET_WAIT_EVENT : unsigned long { BatchEvent = 0, BatchCompletion = 192, BatchTimeout = 258, BatchFailed = 0xffffffffUL };
extern ""C"" {
_Win32_PreserveResult_ _Win32_SetLastError_ _Win32_SupportedOS_WindowsXP_
DWORD __stdcall GetFileAttributesA(_In_ LPCSTR lpFileName);
_Win32_PreserveResult_ _Win32_SetLastError_ _Win32_SupportedOS_WindowsXP_
DWORD __stdcall GetFileAttributesW(_In_ LPCWSTR lpFileName);
_Win32_PreserveResult_ _Win32_SetLastError_ _Win32_SupportedOS_WindowsXP_
DWORD __stdcall QueryDosDeviceW(_In_opt_ LPCWSTR lpDeviceName,
    _Out_writes_to_opt_(ucchMax,return) LPWSTR lpTargetPath, _In_ DWORD ucchMax);
_Win32_PreserveResult_ _Win32_AssociatedEnum_(BATCH_SOCKET_WAIT_EVENT) _Win32_SetLastError_ _Win32_SupportedOS_Windows81_
DWORD __stdcall WSAWaitForMultipleEvents(_In_ DWORD cEvents,
    _In_reads_(cEvents) const WSAEVENT* lphEvents, _In_ BOOL fWaitAll, _In_ DWORD dwTimeout, _In_ BOOL fAlertable);
DWORD __stdcall FileAndSocketResultWithoutPreserveResult(DWORD value);
}
";

        private const string FileAndSocketResultLibraries = @"--with-librarypath
GetFileAttributesA=kernel32.dll
GetFileAttributesW=kernel32.dll
QueryDosDeviceW=kernel32.dll
WSAWaitForMultipleEvents=ws2_32.dll
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
                        ScopedDeclarations + AssociatedConstantNativeDeclarations + AdditionalDeclarations +
                        ImageHlpLastErrorDeclarations + FileAndSocketResultDeclarations;
                    var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                        extraSettings: "--config\nnative-constant-values\n" +
                            "--remap\nBATCH_BOOL=BATCH_BOOL\nBATCH_HANDLE=BATCH_HANDLE\n" +
                            "BATCH_PHANDLE=BATCH_PHANDLE\nBATCH_HOPAQUE=BATCH_HOPAQUE\nDWORD=DWORD\n" +
                            FileAndSocketResultLibraries);
                    fixtures.Add((architecture, fixture));
                    fixture.AssertSuccess("MSInheritance", "MSInheritance");
                    Assert.Contains("is represented by System.Flags", fixture.Diagnostics);
                    Assert.Equal(NativeSurface(fixture, target, metadataEnabled: false),
                        NativeSurface(fixture, target, metadataEnabled: true));
                    using var image = Emit(fixture, architecture);
                    var reader = image.Reader;
                    AssertNativeHeaders(fixture, reader);
                    AssertImageHlpLastError(reader);
                    AssertWaitResults(reader);
                    AssertFileAndSocketResults(reader);

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
                    ("BATCH_PHANDLE", "BATCH_HANDLE*"), ("BATCH_HOPAQUE", "BATCH_OPAQUE*"),
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
                AssertImageHlpLastError(combined.Reader);
                AssertWaitResults(combined.Reader);
                AssertFileAndSocketResults(combined.Reader);
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
        public void SelectedImageHlpLastErrorContractsAreAnnotatedOnTheTraversedHeader()
        {
            string sdk = Path.Combine(RepositoryRoot(), "generation", "WinSDK");
            Assert.Contains("#include <ImageHlp.h>", File.ReadAllText(Path.Combine(sdk, "Partitions", "Debug", "main.cpp")));
            Assert.Contains("<IncludeRoot>/um/ImageHlp.h",
                File.ReadAllText(Path.Combine(sdk, "Partitions", "Debug", "settings.rsp")));
            string patch = File.ReadAllText(Path.Combine(sdk, "patches", "um", "imagehlp.h.patch"));
            foreach (string name in new[] { "ImageRvaToSection", "ImageRvaToVa", "FindDebugInfoFile" })
                Assert.Matches(@"(?m)^\+_Win32_SetLastError_\s+" + Regex.Escape(name) + @"\s*\(", patch);
        }

        private static string RepositoryRoot([CallerFilePath] string source = null)
            => Path.GetFullPath(Path.Combine(Path.GetDirectoryName(source), "..", ".."));

        private static void AssertImageHlpLastError(MetadataReader reader)
        {
            foreach (string name in new[] { "ImageRvaToSection", "ImageRvaToVa", "FindDebugInfoFile" })
            {
                var import = FindMethod(reader, "Apis", name).GetImport();
                Assert.True(import.Attributes.HasFlag(MethodImportAttributes.SetLastError));
                Assert.Equal("scan.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));
                Assert.Equal(name, reader.GetString(import.Name));
            }
            Assert.False(FindMethod(reader, "Apis", "ImageHlpWithoutLastError").GetImport()
                .Attributes.HasFlag(MethodImportAttributes.SetLastError));
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
enum __attribute__((flag_enum)) DISABLED_FLAGS { DisabledRead = 1, DisabledWrite = 2 };
int Ordinary(void);
", annotationsEnabled: false, extraSettings: "--language\nc\n--std\nc11\n");
            fixture.AssertSuccess("FlagEnum");
            Assert.DoesNotContain("is represented by System.Flags", fixture.Diagnostics);
            Assert.DoesNotContain("System.Flags", fixture.ReadSource());
            Assert.DoesNotContain("NativeAnnotation", fixture.ReadSource());
            Assert.DoesNotContain("_WIN32META_", fixture.ReadSource());
            this.output.WriteLine($"TOOLCHAIN disabled-C: scraper={fixture.InvocationCount}");
        }

        private static void AssertWaitResults(MetadataReader reader)
        {
            foreach (var (name, parameterCount) in new[]
            {
                ("WaitForSingleObject", 2), ("WaitForSingleObjectEx", 3),
                ("WaitForMultipleObjects", 4), ("WaitForMultipleObjectsEx", 5),
            })
            {
                var method = FindMethod(reader, "Apis", name);
                Assert.True(method.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig), name);
                Assert.True(method.GetImport().Attributes.HasFlag(MethodImportAttributes.SetLastError), name);
                Assert.Equal(name, reader.GetString(method.GetImport().Name));
                AssertDwordReturn(reader, method, parameterCount);
                var result = method.GetParameters().Select(reader.GetParameter).Single(parameter => parameter.SequenceNumber == 0);
                AssertStringAttribute(reader, result.GetCustomAttributes(), "AssociatedEnumAttribute", "WAIT_EVENT");
                AssertStringAttribute(reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute", "windows5.1.2600");
            }
            Assert.False(FindMethod(reader, "Apis", "WaitResultWithoutPreserveResult")
                .ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
        }

        private static void AssertDwordReturn(MetadataReader reader, MethodDefinition method, int parameterCount)
        {
            var signature = method.DecodeSignature(new SignatureNames(qualifiedNames: true), null);
            Assert.Equal("Test.DWORD", signature.ReturnType);
            Assert.Equal(parameterCount, signature.ParameterTypes.Length);
            var handle = reader.TypeDefinitions.Single(value =>
                reader.GetString(reader.GetTypeDefinition(value).Name) == "DWORD");
            var type = reader.GetTypeDefinition(handle);
            AssertHasAttribute(reader, type.GetCustomAttributes(), "NativeTypedefAttribute");
            var storage = reader.GetFieldDefinition(Assert.Single(type.GetFields()));
            Assert.Equal("Value", reader.GetString(storage.Name));
            Assert.Equal("UInt32", storage.DecodeSignature(new SignatureNames(), null));

            var blob = reader.GetBlobReader(method.Signature);
            Assert.False(blob.ReadSignatureHeader().IsGeneric);
            Assert.Equal(parameterCount, blob.ReadCompressedInteger());
            Assert.Equal((byte)SignatureTypeKind.ValueType, blob.ReadByte());
            var result = blob.ReadTypeHandle();
            if (result.Kind == HandleKind.TypeReference)
            {
                var reference = reader.GetTypeReference((TypeReferenceHandle)result);
                Assert.Equal(HandleKind.ModuleDefinition, reference.ResolutionScope.Kind);
                Assert.Equal(reader.GetString(type.Namespace), reader.GetString(reference.Namespace));
                Assert.Equal(reader.GetString(type.Name), reader.GetString(reference.Name));
            }
            else
                Assert.Equal((EntityHandle)handle, result);
        }

        private static void AssertFileAndSocketResults(MetadataReader reader, string waitEnum = "BATCH_SOCKET_WAIT_EVENT")
        {
            foreach (var (name, count) in new[]
            {
                ("GetFileAttributesA", 1), ("GetFileAttributesW", 1),
                ("QueryDosDeviceW", 3), ("WSAWaitForMultipleEvents", 5),
            })
            {
                bool socket = name == "WSAWaitForMultipleEvents";
                var method = FindMethod(reader, "Apis", name);
                Assert.True(method.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig), name);
                var import = method.GetImport();
                Assert.Equal(MethodImportAttributes.ExactSpelling | MethodImportAttributes.CallingConventionWinApi |
                    MethodImportAttributes.SetLastError, import.Attributes);
                Assert.Equal(socket ? "ws2_32.dll" : "kernel32.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));
                Assert.Equal(name, reader.GetString(import.Name));
                AssertDwordReturn(reader, method, count);
                var results = method.GetParameters().Select(reader.GetParameter).Where(parameter => parameter.SequenceNumber == 0).ToArray();
                if (socket)
                    AssertStringAttribute(reader, Assert.Single(results).GetCustomAttributes(), "AssociatedEnumAttribute", waitEnum);
                else
                    foreach (var result in results)
                        AssertDoesNotHaveAttribute(reader, result.GetCustomAttributes(), "AssociatedEnumAttribute");
                AssertStringAttribute(reader, method.GetCustomAttributes(), "SupportedOSPlatformAttribute",
                    socket ? "windows8.1" : "windows5.1.2600");
            }
            Assert.False(FindMethod(reader, "Apis", "FileAndSocketResultWithoutPreserveResult")
                .ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig));
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

    public class NativeContractBatchTestsManaged
    {
        private readonly ITestOutputHelper output;

        public NativeContractBatchTestsManaged(ITestOutputHelper output) => this.output = output;

        [Fact]
        public void PayloadValidationRunsInMemoryInsteadOfLaunchingTheCompilerPerString()
        {
            foreach (string payload in Win32MetadataTestCases.HeaderAnnotationCases.InvalidPayloads)
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
            AssertNativeFlagsProjectionProof();
        }

        private static void AssertNativeFlagsProjectionProof()
        {
            var source = new NativeRecordSource("c:@E@FLAG_OPTIONS", "FLAG_OPTIONS",
                @"C:\sdk\flags.h", new string('A', 64), 7, 6, "FLAG_OPTIONS", "Test", true, 4, 4);
            var root = SyntaxFactory.ParseCompilationUnit(
                "namespace Test { [global::System.Flags] public enum FLAG_OPTIONS : uint { Read = 1, Write = 2 } }");
            var original = root.DescendantNodes().OfType<EnumDeclarationSyntax>().Single();
            var projection = HeaderAnnotationProcessor.CreateNativeFlagsProjection(source);
            root = root.ReplaceNode(original, original.WithAdditionalAnnotations(projection));
            var generated = GeneratedSource.FromRoot(root);
            Assert.DoesNotContain("Win32Metadata.NativeFlagsProjection", generated.Text);
            var declaration = generated.Root.DescendantNodes().OfType<EnumDeclarationSyntax>().Single();
            Assert.True(HeaderAnnotationProcessor.HasNativeFlagsProjection(declaration, source, projection));
            Assert.False(HeaderAnnotationProcessor.HasNativeFlagsProjection(
                declaration.WithoutAnnotations(projection), source, projection));
            Assert.False(HeaderAnnotationProcessor.HasNativeFlagsProjection(
                declaration.WithAttributeLists(default), source, projection));
            foreach (var other in new[]
            {
                source with { Identity = "c:@E@OTHER_FLAGS" },
                source with { HeaderHash = new string('B', 64) },
                source with { Line = 8 },
                source with { Namespace = "Other" },
                source with { Name = "OTHER_FLAGS" },
            })
                Assert.False(HeaderAnnotationProcessor.HasNativeFlagsProjection(declaration, other, projection));
            Assert.False(HeaderAnnotationProcessor.HasNativeFlagsProjection(declaration, source,
                HeaderAnnotationProcessor.CreateNativeFlagsProjection(source)));
        }

        [Fact]
        public void NativeIntegrationUsesBatchesInsteadOfInheritedScenarioTheories()
        {
            var nativeClasses = typeof(HeaderAnnotationWinmdTests).Assembly.GetTypes()
                .Where(type => !type.IsAbstract && typeof(HeaderAnnotationWinmdTests).IsAssignableFrom(type)).ToArray();
            var nativeTests = nativeClasses.SelectMany(type => type.GetMethods(BindingFlags.Public | BindingFlags.Instance))
                .Where(method => method.IsDefined(typeof(FactAttribute), inherit: true)).ToArray();
            this.output.WriteLine($"Native batch budget: {nativeTests.Length} Fact methods across {nativeClasses.Length} concrete classes.");
            foreach (var method in nativeTests.OrderBy(method => method.DeclaringType.FullName, StringComparer.Ordinal)
                .ThenBy(method => method.Name, StringComparer.Ordinal))
                this.output.WriteLine(method.DeclaringType.FullName + "." + method.Name);
            Assert.InRange(nativeTests.Length, 1, 10);
            Assert.DoesNotContain(nativeTests, method => method.IsDefined(typeof(TheoryAttribute), inherit: true));
            Assert.Empty(typeof(HeaderAnnotationWinmdTests).GetMethods(BindingFlags.Public | BindingFlags.NonPublic |
                BindingFlags.Instance | BindingFlags.Static).Where(method => method.IsDefined(typeof(FactAttribute), inherit: true)));
        }
    }
}

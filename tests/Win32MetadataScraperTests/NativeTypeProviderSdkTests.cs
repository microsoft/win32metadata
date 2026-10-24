using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using ClangSharp;
using ClangSharp.Interop;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        [SelectedOpaqueSdkTheory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeTypeProviderSdkGdiPlusUsesActualRecordStorage(string architecture, string target)
        {
            using var fixture = TypeProviderFixture(architecture, target, @"
#include <windows.h>
#define GDIPVER 0x0110
#include <gdiplus.h>
");
            using var index = CXIndex.Create(false, false);
            using var native = ParseTypeProviderFixture(index, fixture, target, TypeProviderSdkIncludes());
            var excludes = RemapDiscovery.FindInaccessibleCopyMembers(native.TranslationUnitDecl, true);
            var remaps = new Dictionary<string, string>();
            string root = Environment.GetEnvironmentVariable("WIN32_OPAQUE_SDK_INCLUDE_ROOT");
            string[] traversal = { "gdiplusgpstubs.h", "gdiplusflat.h", "gdiplustypes.h", "gdiplusenums.h", "gdiplusmatrix.h" };
            var files = traversal.Select(name => Path.Combine(root, "um", name)).ToArray();
            string[] names =
            {
                "Gdiplus::Status", "Gdiplus::PointF",
                "Gdiplus::DllExports::GdipCreateMatrix", "Gdiplus::DllExports::GdipGetPathData",
                "Gdiplus::Matrix", "Gdiplus::PathData",
            };
            var flags = PInvokeGeneratorConfigurationOptions.GenerateCompatibleCode |
                PInvokeGeneratorConfigurationOptions.GenerateCppAttributes |
                PInvokeGeneratorConfigurationOptions.ExcludeFunctionsWithBody |
                PInvokeGeneratorConfigurationOptions.ExcludeEmptyRecords;
            var sources = GenerateTypeProviderSdkBindings(native, fixture, flags, names, files, remaps, excludes);
            var projection = new OpaqueRecordProjection(native, sources.Values, remaps, excludes);
            var recovered = new List<string>();
            var supplementalFlags = flags & ~PInvokeGeneratorConfigurationOptions.ExcludeEmptyRecords |
                PInvokeGeneratorConfigurationOptions.GenerateSourceLocationAttribute;
            recovered.AddRange(projection.SelectRequiredBindings(GenerateTypeProviderSdkBindings(native, fixture,
                supplementalFlags, projection.IncludedNames, files.Concat(projection.TraversalFiles), remaps, excludes)).Values);
            foreach (var alias in projection.RecordAliases)
            {
                var recordProjection = projection.ForAlias(alias);
                var recordRemaps = new Dictionary<string, string>(remaps)
                {
                    [alias.RecordName] = alias.ManagedName,
                    [alias.Name] = alias.ManagedName,
                };
                recovered.AddRange(recordProjection.SelectRequiredBindings(GenerateTypeProviderSdkBindings(native, fixture,
                    supplementalFlags, recordProjection.IncludedNames, files.Concat(recordProjection.TraversalFiles), recordRemaps, excludes)).Values);
            }
            var control = GenerateTypeProviderSdkBindings(native, fixture,
                flags & ~PInvokeGeneratorConfigurationOptions.ExcludeEmptyRecords, names, files, remaps, excludes);
            try
            {
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, "ordinary-native-bindings.txt"), string.Join(Environment.NewLine, control.Values));
                WriteTypeProviderSdkBindings(fixture, sources.Values.Concat(recovered));
                var actualTypes = ReadOpaqueRecordSources(fixture).SelectMany(source => source.DescendantNodes()
                    .OfType<StructDeclarationSyntax>()).ToArray();
                foreach (string name in new[] { "Matrix", "PathData" })
                {
                    var expected = Assert.Single(control.Values.SelectMany(source => SyntaxFactory.ParseCompilationUnit(source)
                        .DescendantNodes().OfType<StructDeclarationSyntax>()).Where(type => type.Identifier.ValueText == name));
                    var actual = Assert.Single(actualTypes.Where(type => type.Identifier.ValueText == name));
                    Assert.Equal(expected.Members.OfType<FieldDeclarationSyntax>().Select(field => field.NormalizeWhitespace().ToFullString()),
                        actual.Members.OfType<FieldDeclarationSyntax>().Select(field => field.NormalizeWhitespace().ToFullString()));
                }
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                Assert.Equal(new[] { "Matrix*", "Status" }, FindType(reader, "Matrix").GetFields().Select(handle =>
                    reader.GetFieldDefinition(handle).DecodeSignature(new SignatureNames(), null)));
                Assert.Equal(new[] { "Int32", "PointF*", "Byte*" }, FindType(reader, "PathData").GetFields().Select(handle =>
                    reader.GetFieldDefinition(handle).DecodeSignature(new SignatureNames(), null)));
                Assert.Equal(new[] { "Matrix**" }, FindMethod(reader, "Apis", "GdipCreateMatrix")
                    .DecodeSignature(new SignatureNames(), null).ParameterTypes);
                Assert.Equal(new[] { "GpPath*", "PathData*" }, FindMethod(reader, "Apis", "GdipGetPathData")
                    .DecodeSignature(new SignatureNames(), null).ParameterTypes);
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "native-type-provider-sdk-gdiplus-" + architecture);
            }
        }

        [SelectedOpaqueSdkTheory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeTypeProviderSdkEnumsUseTheirActualNativeDeclarations(string architecture, string target)
        {
            using var fixture = TypeProviderFixture(architecture, target, @"
#include <windows.h>
#include <dwrite_3.h>
#include <jsrt.h>
");
            using var index = CXIndex.Create(false, false);
            using var native = ParseTypeProviderFixture(index, fixture, target, TypeProviderSdkIncludes());
            string root = Environment.GetEnvironmentVariable("WIN32_OPAQUE_SDK_INCLUDE_ROOT");
            var names = new[] { "DWRITE_FONT_AXIS_TAG", "JsRuntimeVersion", "_EXCEPTION_DISPOSITION" };
            var files = new[]
            {
                Path.Combine(root, "um", "dwrite_3.h"), Path.Combine(root, "um", "jsrt9.h"),
                "excpt.h",
            };
            var discovery = RemapDiscovery.WalkTranslationUnit(native.TranslationUnitDecl);
            var remaps = RemapDiscovery.FilterTagRemaps(
                RemapDiscovery.ResolveTagRemaps(discovery.TagToTypedefs, new Dictionary<string, string>()),
                new Dictionary<string, string>(), discovery.EnumTags);
            var sources = GenerateTypeProviderSdkBindings(native, fixture,
                PInvokeGeneratorConfigurationOptions.GenerateCompatibleCode, names, files, remaps, Array.Empty<string>());
            try
            {
                WriteTypeProviderSdkBindings(fixture, sources.Values);
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                var axes = FindType(reader, "DWRITE_FONT_AXIS_TAG").GetFields().Select(reader.GetFieldDefinition).ToArray();
                Assert.Equal("UInt32", axes[0].DecodeSignature(new SignatureNames(), null));
                Assert.Equal(new[] { "DWRITE_FONT_AXIS_TAG_WEIGHT", "DWRITE_FONT_AXIS_TAG_WIDTH", "DWRITE_FONT_AXIS_TAG_SLANT",
                    "DWRITE_FONT_AXIS_TAG_OPTICAL_SIZE", "DWRITE_FONT_AXIS_TAG_ITALIC" },
                    axes.Skip(1).Select(field => reader.GetString(field.Name)));
                Assert.Equal(new[] { 0x74686777u, 0x68746477u, 0x746E6C73u, 0x7A73706Fu, 0x6C617469u },
                    axes.Skip(1).Select(field => reader.GetBlobReader(reader.GetConstant(field.GetDefaultValue()).Value).ReadUInt32()));
                Assert.Equal(new[] { "JsRuntimeVersion10", "JsRuntimeVersion11" }, FindType(reader, "JsRuntimeVersion")
                    .GetFields().Select(reader.GetFieldDefinition).Skip(1).Select(field => reader.GetString(field.Name)));
                Assert.Equal(new[] { "ExceptionContinueExecution", "ExceptionContinueSearch", "ExceptionNestedException", "ExceptionCollidedUnwind" },
                    FindType(reader, "EXCEPTION_DISPOSITION").GetFields().Select(reader.GetFieldDefinition).Skip(1)
                        .Select(field => reader.GetString(field.Name)));
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "native-type-provider-sdk-enums-" + architecture);
            }
        }

        private static string[] TypeProviderSdkIncludes()
        {
            string root = Environment.GetEnvironmentVariable("WIN32_OPAQUE_SDK_INCLUDE_ROOT");
            return new[] { "um", "shared", "ucrt", "winrt" }.Select(directory => Path.Combine(root, directory))
                .Append(Environment.GetEnvironmentVariable("WIN32_OPAQUE_SDK_CPP_INCLUDE"))
                .Append(Environment.GetEnvironmentVariable("WIN32_NATIVE_TYPE_PROVIDER_UCRT_INCLUDE"))
                .Where(path => !string.IsNullOrEmpty(path)).Select(path => "--include-directory=" + path).ToArray();
        }

        private static Dictionary<string, string> GenerateTypeProviderSdkBindings(TranslationUnit native,
            HeaderAnnotationTests.NativeFixture fixture, PInvokeGeneratorConfigurationOptions flags, IEnumerable<string> names,
            IEnumerable<string> files, IReadOnlyDictionary<string, string> remaps, IReadOnlyCollection<string> excludes)
        {
            var streams = new Dictionary<string, MemoryStream>();
            var configuration = new PInvokeGeneratorConfiguration("c++", "c++17", "Test", fixture.Output,
                Path.Combine(AppContext.BaseDirectory, "assets", "scraper.header.txt"), PInvokeGeneratorOutputMode.CSharp, flags)
            {
                IncludedNames = names.ToArray(),
                TraversalNames = RemapDiscovery.ResolveTraversalFiles(native.TranslationUnitDecl, files),
                RemappedNames = remaps,
                ExcludedNames = excludes,
                DefaultClass = "Apis",
                LibraryPath = "gdiplus.dll",
            };
            using var generator = new PInvokeGenerator(configuration, path =>
            {
                var stream = new MemoryStream();
                streams[path] = stream;
                return stream;
            });
            generator.GenerateBindings(native, Path.Combine(fixture.DirectoryPath, "test.cpp"),
                Array.Empty<string>(), CXTranslationUnit_Flags.CXTranslationUnit_None);
            Assert.DoesNotContain(generator.Diagnostics, diagnostic => diagnostic.Level == DiagnosticLevel.Error);
            generator.Close();
            return streams.ToDictionary(pair => pair.Key, pair => Encoding.UTF8.GetString(pair.Value.ToArray()));
        }

        private static void WriteTypeProviderSdkBindings(HeaderAnnotationTests.NativeFixture fixture, IEnumerable<string> sources)
        {
            Directory.CreateDirectory(Path.GetDirectoryName(fixture.Output));
            int index = 0;
            foreach (string source in sources)
            {
                var root = new TypeProviderSourceLocationRemover().Visit(SyntaxFactory.ParseCompilationUnit(source));
                File.WriteAllText(Path.Combine(Path.GetDirectoryName(fixture.Output), "NativeBindings" + index++ + ".cs"),
                    root.NormalizeWhitespace().ToFullString());
            }
        }

        private sealed class TypeProviderSourceLocationRemover : CSharpSyntaxRewriter
        {
            public override SyntaxNode VisitAttributeList(AttributeListSyntax node)
            {
                var attributes = SyntaxFactory.SeparatedList(node.Attributes.Where(attribute =>
                    attribute.Name.ToString() is not "SourceLocation" and not "SourceLocationAttribute"));
                return attributes.Count == 0 ? null : base.VisitAttributeList(node.WithAttributes(attributes));
            }
        }
    }
}

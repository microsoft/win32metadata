using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text.Json;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class HeaderOpaqueSdkTests : HeaderAnnotationWinmdTests
    {
        [SelectedOpaqueSdkTheory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void SelectedSdkGdiPlusStubsReachPhysicalWinmd(string architecture, string target)
        {
            string includeRoot = Environment.GetEnvironmentVariable("WIN32_OPAQUE_SDK_INCLUDE_ROOT");
            string cppInclude = Environment.GetEnvironmentVariable("WIN32_OPAQUE_SDK_CPP_INCLUDE");
            var headers = new[] { "gdiplus.h", "gdiplusgpstubs.h", "gdiplusflat.h", "gdiplusenums.h", "gdiplustypes.h", "windows.h" }
                .Select(name => Path.Combine(includeRoot, "um", name)).ToArray();
            var hashes = headers.ToDictionary(path => path,
                path => Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path))));
            string[] functions = { "GdipCreateCachedBitmap", "GdipDrawCachedBitmap", "GdipDeleteCachedBitmap" };
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#include <windows.h>
#define GDIPVER 0x0110
#include <gdiplus.h>
", libraryPath: string.Empty, extraSettings:
                "--namespace\nWindows.Win32.Graphics.GdiPlus\n--traverse\n" +
                string.Join("\n", headers.Skip(1).Take(4)) +
                "\n--include-directory\n" + Path.Combine(includeRoot, "um") + "\n" +
                Path.Combine(includeRoot, "shared") + "\n" + Path.Combine(includeRoot, "ucrt") + "\n" + cppInclude +
                "\n--with-librarypath\n" + string.Join("\n", functions.Select(name => name + "=gdiplus.dll")) +
                "\n--config\nexclude-empty-records\nexclude-funcs-with-body\n");
            try
            {
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, "sdk-inputs.json"), JsonSerializer.Serialize(new
                {
                    headers = hashes, architecture, target,
                    scope = "Original GDI+ stubs and cached-bitmap APIs; physical image restricted to actual generated declaration nodes.",
                }, new JsonSerializerOptions { WriteIndented = true }));
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                var roots = ReadOpaqueRecordSources(fixture);
                string[] names = { "GpGraphics", "GpImage", "GpBitmap", "GpCachedBitmap" };
                var providers = names.Select(name => Assert.Single(
                    roots.SelectMany(root => root.DescendantNodes().OfType<StructDeclarationSyntax>())
                        .Where(type => type.Identifier.ValueText == name))).ToArray();
                foreach (var provider in providers)
                    Assert.Empty(provider.Members);
                var status = Assert.Single(roots.SelectMany(root => root.DescendantNodes().OfType<EnumDeclarationSyntax>())
                    .Where(type => type.Identifier.ValueText == "Status"));
                var methods = roots.SelectMany(root => root.DescendantNodes().OfType<MethodDeclarationSyntax>())
                    .Where(method => functions.Contains(method.Identifier.ValueText)).ToArray();
                Assert.Equal(functions.OrderBy(name => name), methods.Select(method => method.Identifier.ValueText).OrderBy(name => name));
                var api = Assert.IsType<ClassDeclarationSyntax>(methods[0].Parent)
                    .WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(methods));
                var bounded = SyntaxFactory.ParseCompilationUnit(
                    "using System; using System.Runtime.InteropServices; using Windows.Win32.Foundation.Metadata;")
                    .AddMembers(SyntaxFactory.NamespaceDeclaration(SyntaxFactory.ParseName("Windows.Win32.Graphics.GdiPlus"))
                        .AddMembers(providers).AddMembers(status, api));
                string directory = Path.Combine(fixture.DirectoryPath, "bounded-image");
                Directory.CreateDirectory(directory);
                File.WriteAllText(Path.Combine(directory, "ActualSdkBindings.cs"), bounded.NormalizeWhitespace().ToFullString());
                using var image = Emit(directory, architecture, winmdFileName: "Windows.Win32.winmd");
                var reader = image.Reader;
                Assert.Equal("Windows.Win32.winmd", reader.GetString(reader.GetAssemblyDefinition().Name));
                foreach (string name in names)
                    AssertOpaqueRecordProvider(reader, name);
                Assert.Equal(new[] { "GpBitmap*", "GpGraphics*", "GpCachedBitmap**" },
                    FindMethod(reader, "Apis", "GdipCreateCachedBitmap").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                Assert.Equal(new[] { "GpGraphics*", "GpCachedBitmap*", "Int32", "Int32" },
                    FindMethod(reader, "Apis", "GdipDrawCachedBitmap").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                Assert.Equal(new[] { "GpCachedBitmap*" },
                    FindMethod(reader, "Apis", "GdipDeleteCachedBitmap").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                foreach (string name in functions)
                {
                    var method = FindMethod(reader, "Apis", name);
                    Assert.Equal("Status", method.DecodeSignature(new SignatureNames(), null).ReturnType);
                    var import = method.GetImport();
                    Assert.Equal(name, reader.GetString(import.Name));
                    Assert.Equal("gdiplus.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));
                }
                AssertMetadataClosure(reader);
                foreach (var header in hashes)
                    Assert.Equal(header.Value, Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(header.Key))));
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "actual-sdk-gdiplus-" + architecture);
            }
        }

        [SelectedOpaqueSdkTheory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void SelectedSdkUbidiPointeeReachesPhysicalWinmd(string architecture, string target)
        {
            string includeRoot = Environment.GetEnvironmentVariable("WIN32_OPAQUE_SDK_INCLUDE_ROOT");
            string cppInclude = Environment.GetEnvironmentVariable("WIN32_OPAQUE_SDK_CPP_INCLUDE");
            string header = Path.Combine(includeRoot, "um", "icucommon.h");
            string versionHeader = Path.Combine(includeRoot, "shared", "sdkddkver.h");
            string runtimeHeader = Path.Combine(cppInclude, "vcruntime.h");
            string originalHash = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(header)));
            string originalVersionHash = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(versionHeader)));
            string originalRuntimeHash = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(runtimeHeader)));
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#define SUPPRESS_LEGACY_ICU_HEADER_WARNINGS
#include <sdkddkver.h>
#include <icucommon.h>
", libraryPath: string.Empty,
                extraSettings: "--namespace\nWindows.Win32.Globalization\n--traverse\n" + header +
                "\n--include-directory\n" + Path.Combine(includeRoot, "um") + "\n" +
                Path.Combine(includeRoot, "shared") + "\n" + Path.Combine(includeRoot, "ucrt") +
                "\n" + cppInclude +
                "\n--with-librarypath\nubidi_open=icuuc.dll\nubidi_close=icuuc.dll\nubidi_getLength=icuuc.dll\n" +
                "--config\nexclude-empty-records\n");
            try
            {
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, "sdk-inputs.json"), JsonSerializer.Serialize(new
                {
                    header, headerSha256 = originalHash,
                    versionHeader, versionHeaderSha256 = originalVersionHash,
                    runtimeHeader, runtimeHeaderSha256 = originalRuntimeHash,
                    architecture, target,
                    scope = "Original ICU header bindings; physical image restricted to actual UBiDi/open/close/getLength nodes.",
                }, new JsonSerializerOptions { WriteIndented = true }));
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                var roots = ReadOpaqueRecordSources(fixture);
                var provider = Assert.Single(roots.SelectMany(root => root.DescendantNodes().OfType<StructDeclarationSyntax>())
                    .Where(type => type.Identifier.ValueText == "UBiDi"));
                Assert.Empty(provider.Members);
                var names = new HashSet<string>(StringComparer.Ordinal) { "ubidi_open", "ubidi_close", "ubidi_getLength" };
                var methods = roots.SelectMany(root => root.DescendantNodes().OfType<MethodDeclarationSyntax>())
                    .Where(method => names.Contains(method.Identifier.ValueText)).ToArray();
                Assert.Equal(names.OrderBy(name => name), methods.Select(method => method.Identifier.ValueText).OrderBy(name => name));
                var api = Assert.IsType<ClassDeclarationSyntax>(methods[0].Parent).WithMembers(
                    SyntaxFactory.List<MemberDeclarationSyntax>(methods));
                var bounded = SyntaxFactory.ParseCompilationUnit(
                    "using System; using System.Runtime.InteropServices; using Windows.Win32.Foundation.Metadata;")
                    .AddMembers(SyntaxFactory.NamespaceDeclaration(SyntaxFactory.ParseName("Windows.Win32.Globalization"))
                        .AddMembers(provider, api));
                string directory = Path.Combine(fixture.DirectoryPath, "bounded-image");
                Directory.CreateDirectory(directory);
                File.WriteAllText(Path.Combine(directory, "ActualSdkBindings.cs"), bounded.NormalizeWhitespace().ToFullString());
                using var image = Emit(directory, architecture, winmdFileName: "Windows.Win32.winmd");
                var reader = image.Reader;
                Assert.Equal("Windows.Win32.winmd", reader.GetString(reader.GetAssemblyDefinition().Name));
                AssertOpaqueRecordProvider(reader, "UBiDi");
                Assert.Equal("UBiDi*", FindMethod(reader, "Apis", "ubidi_open").DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "UBiDi*" }, FindMethod(reader, "Apis", "ubidi_close").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                Assert.Equal(new[] { "UBiDi*" }, FindMethod(reader, "Apis", "ubidi_getLength").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                foreach (string name in names)
                {
                    var import = FindMethod(reader, "Apis", name).GetImport();
                    Assert.Equal(name, reader.GetString(import.Name));
                    Assert.Equal("icuuc.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));
                }
                AssertMetadataClosure(reader);
                Assert.Equal(originalHash, Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(header))));
                Assert.Equal(originalVersionHash, Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(versionHeader))));
                Assert.Equal(originalRuntimeHash, Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(runtimeHeader))));
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "actual-sdk-ubidi-" + architecture);
            }
        }
    }

    public sealed class SelectedOpaqueSdkTheoryAttribute : TheoryAttribute
    {
        public SelectedOpaqueSdkTheoryAttribute()
        {
            if (string.IsNullOrEmpty(Environment.GetEnvironmentVariable("WIN32_OPAQUE_SDK_INCLUDE_ROOT")) ||
                string.IsNullOrEmpty(Environment.GetEnvironmentVariable("WIN32_OPAQUE_SDK_CPP_INCLUDE")))
                Skip = "Set WIN32_OPAQUE_SDK_INCLUDE_ROOT and WIN32_OPAQUE_SDK_CPP_INCLUDE for original-header qualification.";
        }
    }
}

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
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
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeTypedefOfExcludedIncompleteRecordUsesOpaquePointerStorage(string architecture, string target)
        {
            using var fixture = PointeeStorageFixture(architecture, target, @"
struct Hidden;
_Win32_NativeTypedef_ typedef struct Hidden* HIDDEN;
_Win32_NativeTypedef_ typedef HIDDEN* PHIDDEN;
_Win32_NativeTypedef_ typedef PHIDDEN* PPHIDDEN;
struct Complete { int value; };
_Win32_NativeTypedef_ typedef struct Complete** PPCOMPLETE;
HIDDEN OpenHidden(void);
void UseHidden(HIDDEN value, PHIDDEN output, PPHIDDEN indirect, PPCOMPLETE complete);
", "--exclude\nHidden\n--remap\nHidden*=HIDDEN\n");
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                foreach (var (name, storage) in new[]
                {
                    ("HIDDEN", "Void*"), ("PHIDDEN", "Void**"), ("PPHIDDEN", "Void***"),
                    ("PPCOMPLETE", "Complete**"),
                })
                    AssertNativeTypedefStorage(reader, name, storage);
                Assert.DoesNotContain(ReadOpaqueRecordSources(fixture).SelectMany(root =>
                    root.DescendantNodes().OfType<StructDeclarationSyntax>()),
                    declaration => declaration.Identifier.ValueText == "Hidden");
                Assert.Equal("HIDDEN", FindMethod(reader, "Apis", "OpenHidden")
                    .DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "HIDDEN", "PHIDDEN", "PPHIDDEN", "PPCOMPLETE" },
                    FindMethod(reader, "Apis", "UseHidden").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "excluded-incomplete-pointee-" + architecture);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void EmbeddedIncompleteRecordPointeeUsesOpaquePointerStorage(string architecture, string target)
        {
            using var fixture = PointeeStorageFixture(architecture, target, @"
struct Holder { struct Undeclared* Process; struct Undeclared** Output; };
");
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                Assert.Equal(new[] { "Void*", "Void**" }, FindType(reader, "Holder").GetFields()
                    .Select(reader.GetFieldDefinition).Select(field => field.DecodeSignature(new SignatureNames(), null)));
                Assert.DoesNotContain(ReadOpaqueRecordSources(fixture).SelectMany(root =>
                    root.DescendantNodes().OfType<StructDeclarationSyntax>()),
                    declaration => declaration.Identifier.ValueText == "Undeclared");
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "implicit-incomplete-pointee-" + architecture);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void CompleteRecordPointeeKeepsItsStorageWhenPointerAliasIsRemapped(string architecture, string target)
        {
            using var fixture = PointeeStorageFixture(architecture, target, @"
struct Backing;
typedef struct Backing* KEY;
/* Win32Metadata: type ::KEY => NativeTypedef */
KEY Open(void);
void Use(KEY value, KEY* output);
struct Backing { int _; };
", "--remap\nBacking*=KEY\n");
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                AssertNativeTypedefStorage(reader, "KEY", "Backing*");
                Assert.Equal("Int32", reader.GetFieldDefinition(Assert.Single(FindType(reader, "Backing").GetFields()))
                    .DecodeSignature(new SignatureNames(), null));
                Assert.Equal("KEY", FindMethod(reader, "Apis", "Open").DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "KEY", "KEY*" },
                    FindMethod(reader, "Apis", "Use").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "complete-pointee-alias-" + architecture);
            }
        }

        [Fact]
        public void CompleteExcludedPointeeIsNotErasedToRepairAMissingManagedType()
        {
            using var fixture = PointeeStorageFixture("x64", "x86_64-pc-windows-msvc", @"
struct Backing { int value; };
_Win32_NativeTypedef_ typedef struct Backing* KEY;
KEY Open(void);
", "--exclude\nBacking\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("public Backing* Value;", fixture.ReadAdditionalTypes());
            Assert.DoesNotContain(ReadOpaqueRecordSources(fixture).SelectMany(root =>
                root.DescendantNodes().OfType<StructDeclarationSyntax>()),
                declaration => declaration.Identifier.ValueText == "Backing");
        }

        [Fact]
        public void EmbeddedPointeeDiscoveryDoesNotEraseStandaloneLinkageOrLaterDefinitions()
        {
            using var fixture = PointeeStorageFixture("x64", "x86_64-pc-windows-msvc", @"
struct Standalone;
extern ""C++"" { struct Linkage; }
struct Holder {
    struct Embedded* first;
    struct Standalone* second;
    struct Linkage* third;
    struct Later* fourth;
    struct Nested;
    struct Nested* fifth;
};
struct Later { int value; };
");
            using var index = CXIndex.Create(false, false);
            using var native = ParseTypeProviderFixture(index, fixture, "x86_64-pc-windows-msvc");
            var remap = Assert.Single(RemapDiscovery.FindEmbeddedIncompleteRecordPointerRemaps(native.TranslationUnitDecl));
            Assert.Equal("Embedded", remap.Key);
            Assert.Equal("void", remap.Value);
        }

        [Fact]
        public void EmbeddedIncompletePointeeDoesNotAuthorizeByValueErasure()
        {
            using var fixture = PointeeStorageFixture("x64", "x86_64-pc-windows-msvc", @"
struct Holder { struct Embedded* value; };
struct Embedded RoundTrip(struct Embedded value);
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("Incomplete native record 'Embedded' is used by value", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
            Assert.False(File.Exists(Path.Combine(fixture.DirectoryPath, "remaps.txt")));
        }

        [SelectedOpaqueSdkTheory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void SelectedSdkPointeeStorageUsesActualClangCompleteness(string architecture, string target)
        {
            using var fixture = PointeeStorageFixture(architecture, target, @"
#include <windows.h>
#include <commctrl.h>
#include <UIAnimation.h>
#include <dxmini.h>
");
            using var index = CXIndex.Create(false, false);
            using var native = ParseTypeProviderFixture(index, fixture, target, TypeProviderSdkIncludes());
            var declarations = new List<Decl>();
            var visited = new HashSet<Cursor>();
            Walk(native.TranslationUnitDecl);
            string[] names = { "HIMAGELIST", "HTREEITEM", "HDSA", "HDPA", "LPPROC_THREAD_ATTRIBUTE_LIST", "UI_ANIMATION_KEYFRAME" };
            var aliases = declarations.OfType<TypedefNameDecl>().Where(alias => names.Contains(alias.Name))
                .GroupBy(alias => alias.Name).Select(group => group.First()).OrderBy(alias => alias.Name).ToArray();
            Assert.Equal(names.OrderBy(name => name), aliases.Select(alias => alias.Name));
            var facts = aliases.Select(alias =>
            {
                var pointer = Assert.IsType<PointerType>(alias.UnderlyingType.CanonicalType);
                var record = Assert.IsType<RecordType>(pointer.PointeeType.CanonicalType);
                var definition = record.Decl.Definition ?? record.Decl;
                bool complete = alias.Name == "UI_ANIMATION_KEYFRAME";
                Assert.Equal(complete, definition.IsCompleteDefinition);
                Assert.Equal(architecture == "x86" ? 4 : 8, pointer.Handle.SizeOf);
                if (complete)
                {
                    var field = Assert.Single(definition.CursorChildren.OfType<FieldDecl>());
                    Assert.Equal("_", field.Name);
                    Assert.Equal(CXTypeKind.CXType_Int, field.Type.CanonicalType.Kind);
                    Assert.Equal(4, record.Handle.SizeOf);
                }
                definition.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
                return new
                {
                    alias = alias.Name, pointee = record.Decl.Name, complete = definition.IsCompleteDefinition,
                    pointerSize = pointer.Handle.SizeOf, recordSize = record.Handle.SizeOf,
                    file = file.ToString(), line, column,
                };
            }).ToArray();
            var processField = Assert.Single(declarations.OfType<FieldDecl>().Where(field =>
                field.Name == "Process" && field.Type.CanonicalType is PointerType pointer &&
                pointer.PointeeType.CanonicalType is RecordType record && record.Decl.Name == "_EPROCESS"));
            var process = (RecordType)((PointerType)processField.Type.CanonicalType).PointeeType.CanonicalType;
            Assert.False((process.Decl.Definition ?? process.Decl).IsCompleteDefinition);
            Assert.NotEqual(process.Decl.LexicalParentCursor, process.Decl.SemanticParentCursor);
            var remaps = RemapDiscovery.FindEmbeddedIncompleteRecordPointerRemaps(native.TranslationUnitDecl);
            string artifacts = Environment.GetEnvironmentVariable("WIN32_OPAQUE_PROVIDER_ARTIFACTS");
            if (!string.IsNullOrEmpty(artifacts))
            {
                Directory.CreateDirectory(artifacts);
                File.WriteAllText(Path.Combine(artifacts, "sdk-pointee-facts-" + architecture + ".json"),
                    JsonSerializer.Serialize(new
                    {
                        architecture, target, facts, process = process.AsString,
                        processName = DeclarationSourceMap.QualifiedName(process.Decl.Handle),
                        processParent = process.Decl.SemanticParentCursor.ToString(),
                        processLexicalParent = process.Decl.LexicalParentCursor.ToString(),
                        processImplicit = process.Decl.Handle.IsImplicit,
                        processContext = process.Decl.DeclContext.GetType().Name,
                        remaps,
                    },
                        new JsonSerializerOptions { WriteIndented = true }));
            }
            Assert.Equal("void", remaps[DeclarationSourceMap.QualifiedName(process.Decl.Handle)]);

            void Walk(Decl declaration)
            {
                if (!visited.Add(declaration))
                    return;
                declarations.Add(declaration);
                foreach (var child in declaration.CursorChildren.OfType<Decl>())
                    Walk(child);
            }
        }

        [ReplayedPointeeSdkTheory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void ReplayedSdkPointeesReachPhysicalWinmd(string architecture, string target)
        {
            using var fixture = PointeeStorageFixture(architecture, target, "");
            string root = Environment.GetEnvironmentVariable("WIN32_OPAQUE_REPLAY_ROOT");
            const string keyframeRecord = "__MIDL___MIDL_itf_uianimation_0000_0002_0003";
            var inputs = new[]
            {
                (Path.Combine(root, architecture, "Controls", "Controls.header-types.cs"),
                    new[] { "HIMAGELIST", "HTREEITEM", "HDSA", "HDPA" }),
                (Path.Combine(root, "x86", "Threading", "Threading.header-types.cs"),
                    new[] { "LPPROC_THREAD_ATTRIBUTE_LIST" }),
                (Path.Combine(root, "x86", "UiAnimation", "UiAnimation.header-types.cs"),
                    new[] { "UI_ANIMATION_KEYFRAME" }),
                (Path.Combine(root, "x86", "UiAnimation", "UiAnimation.cs"),
                    new[] { keyframeRecord }),
                (Path.Combine(root, "x86", "DirectDraw", "DirectDraw.cs"),
                    new[] { "DDMDL" }),
            };
            var declarations = new List<MemberDeclarationSyntax>();
            foreach (var (path, names) in inputs)
            {
                var source = SyntaxFactory.ParseCompilationUnit(File.ReadAllText(path));
                int count = 0;
                foreach (var ns in source.DescendantNodes().OfType<NamespaceDeclarationSyntax>())
                {
                    var selected = ns.Members.OfType<StructDeclarationSyntax>()
                        .Where(type => names.Contains(type.Identifier.ValueText)).ToArray();
                    count += selected.Length;
                    if (selected.Length != 0)
                        declarations.Add(ns.WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(selected)));
                }
                Assert.Equal(names.Length, count);
            }
            var bounded = SyntaxFactory.ParseCompilationUnit(
                "using System; using System.Runtime.InteropServices; using Windows.Win32.Foundation.Metadata;")
                .AddMembers(declarations.ToArray());
            Directory.CreateDirectory(Path.GetDirectoryName(fixture.Output));
            File.WriteAllText(fixture.Output, bounded.NormalizeWhitespace().ToFullString());
            try
            {
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                foreach (string name in new[] { "HIMAGELIST", "HTREEITEM", "HDSA", "HDPA", "LPPROC_THREAD_ATTRIBUTE_LIST" })
                    AssertNativeTypedefStorage(reader, name, "Void*");
                AssertNativeTypedefStorage(reader, "UI_ANIMATION_KEYFRAME", keyframeRecord + "*");
                var keyframe = reader.GetFieldDefinition(Assert.Single(FindType(reader, keyframeRecord).GetFields()));
                Assert.Equal("_", reader.GetString(keyframe.Name));
                Assert.Equal("Int32", keyframe.DecodeSignature(new SignatureNames(), null));
                var process = FindType(reader, "DDMDL").GetFields().Select(reader.GetFieldDefinition)
                    .Single(field => reader.GetString(field.Name) == "Process");
                Assert.Equal("Void*", process.DecodeSignature(new SignatureNames(), null));
                Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                    type => new[] { "_IMAGELIST", "_TREEITEM", "_DSA", "_DPA", "_PROC_THREAD_ATTRIBUTE_LIST", "_EPROCESS" }
                        .Contains(reader.GetString(type.Name)));
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "replayed-sdk-pointees-" + architecture);
            }
        }

        private static HeaderAnnotationTests.NativeFixture PointeeStorageFixture(string architecture, string target,
            string declarations, string settings = "")
            => new(architecture, target, declarations, extraSettings: "--config\nexclude-empty-records\n" + settings,
                directoryRoot: Path.Combine(Directory.GetCurrentDirectory(), "artifacts", "opaque-pointee-validation", "fixtures"));
    }

    public sealed class ReplayedPointeeSdkTheoryAttribute : TheoryAttribute
    {
        public ReplayedPointeeSdkTheoryAttribute()
        {
            if (string.IsNullOrEmpty(Environment.GetEnvironmentVariable("WIN32_OPAQUE_REPLAY_ROOT")))
                Skip = "Requires regenerated ordinary SDK profiles in WIN32_OPAQUE_REPLAY_ROOT.";
        }
    }
}

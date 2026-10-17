using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Xml.Linq;
using MetadataTasks;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class ScrapeHeadersIntegrationTests
    {
        [Theory]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void RepeatedMixedPartitionBuildsKeepAnnotatedCallbackIdentity(string architecture)
        {
            using var fixture = new SdkFixture(architecture);
            fixture.Build("Frozen");
            var frozenReductions = fixture.ReadEmitterPointerReductions();
            Assert.Equal(fixture.ReadPointerReductions("Frozen").OrderBy(name => name), frozenReductions.OrderBy(name => name));
            Assert.Equal(new[] { "LPFROZEN_CALLBACK" }, frozenReductions.OrderBy(name => name));
            fixture.Build();
            string annotated = fixture.ReadSource("Annotated");
            string legacy = fixture.ReadSource("Legacy");
            string annotatedDiscovery = fixture.ReadDiscovery("Annotated");
            string legacyDiscovery = fixture.ReadDiscovery("Legacy");
            var completeReductions = new HashSet<string>(frozenReductions, StringComparer.Ordinal);
            completeReductions.UnionWith(fixture.ReadEmitterPointerReductions());
            Assert.Equal(new[] { "LPFROZEN_CALLBACK", "LPSTATUS_CALLBACK" }, completeReductions.OrderBy(name => name));
            Assert.Contains("STATUS_CALLBACK=LPSTATUS_CALLBACK", legacyDiscovery);
            Assert.Contains("FNPTR_EXCLUDE:LPSTATUS_CALLBACK", legacyDiscovery);
            Assert.Contains("REDUCE_PTR_LEVEL:LPSTATUS_CALLBACK", legacyDiscovery);
            AssertSurface(annotated, "STATUS_CALLBACK");
            AssertSurface(legacy, "LPSTATUS_CALLBACK");
            Assert.Contains("STATUS_CALLBACK=LPSTATUS_CALLBACK", File.ReadAllText(fixture.AutoRemaps));

            for (int repeat = 0; repeat < 2; repeat++)
            {
                fixture.Build();
                AssertSurface(fixture.ReadSource("Annotated"), "STATUS_CALLBACK");
                AssertSurface(fixture.ReadSource("Legacy"), "LPSTATUS_CALLBACK");
                Assert.Equal(annotated, fixture.ReadSource("Annotated"));
                Assert.Equal(legacy, fixture.ReadSource("Legacy"));
                Assert.Equal(annotatedDiscovery, fixture.ReadDiscovery("Annotated"));
                Assert.Equal(legacyDiscovery, fixture.ReadDiscovery("Legacy"));
                Assert.Equal(completeReductions.OrderBy(name => name),
                    frozenReductions.Concat(fixture.ReadPointerReductions("Annotated", "Legacy")).Distinct().OrderBy(name => name));
                Assert.Equal(completeReductions.OrderBy(name => name),
                    frozenReductions.Concat(fixture.ReadEmitterPointerReductions()).Distinct().OrderBy(name => name));
            }

            fixture.SetAnnotations(enabled: false);
            File.Delete(fixture.AutoRemaps);
            fixture.Build();
            AssertSurface(fixture.ReadSource("Annotated"), "LPSTATUS_CALLBACK");
            Assert.Contains("STATUS_CALLBACK=LPSTATUS_CALLBACK", File.ReadAllText(fixture.AnnotatedRemaps));
            fixture.SetAnnotations(enabled: true);
            fixture.Build();
            AssertSurface(fixture.ReadSource("Annotated"), "STATUS_CALLBACK");
            Assert.Equal(annotated, fixture.ReadSource("Annotated"));
            Assert.DoesNotContain("STATUS_CALLBACK=LPSTATUS_CALLBACK",
                File.Exists(fixture.AnnotatedRemaps) ? File.ReadAllText(fixture.AnnotatedRemaps) : "");

            Assert.Equal(legacyDiscovery, fixture.ReadDiscovery("Legacy"));
            var finalReductions = new HashSet<string>(frozenReductions, StringComparer.Ordinal);
            finalReductions.UnionWith(fixture.ReadEmitterPointerReductions());
            Assert.Equal(completeReductions.OrderBy(name => name), finalReductions.OrderBy(name => name));
            Assert.Equal(finalReductions.OrderBy(name => name),
                frozenReductions.Concat(fixture.ReadPointerReductions("Annotated", "Legacy")).Distinct().OrderBy(name => name));
            using var image = HeaderAnnotationWinmdTests.Emit(fixture.GeneratedDirectory, architecture, finalReductions);
            AssertSignature(image.Reader, "Test.Annotated", "STATUS_CALLBACK");
            AssertSignature(image.Reader, "Test.Legacy", "LPSTATUS_CALLBACK");
            AssertSignature(image.Reader, "Test.Frozen", "LPFROZEN_CALLBACK", "UseFrozen");
        }

        private static void AssertSurface(string source, string callback)
        {
            var root = CSharpSyntaxTree.ParseText(source).GetRoot();
            Assert.Equal(callback, Assert.Single(root.DescendantNodes().OfType<DelegateDeclarationSyntax>()).Identifier.ValueText);
            var structures = root.DescendantNodes().OfType<StructDeclarationSyntax>()
                .Select(type => type.Identifier.ValueText).ToArray();
            Assert.Contains("AUTHORED_RECORD", structures);
            Assert.DoesNotContain("_PRIVATE_RECORD", structures);
            Assert.DoesNotContain("EXCLUDED_RECORD", structures);
        }

        private static void AssertSignature(MetadataReader reader, string @namespace, string callback, string methodName = "SetCallback")
        {
            var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(definition =>
                reader.GetString(definition.Namespace) == @namespace && reader.GetString(definition.Name) == "Apis");
            var method = type.GetMethods().Select(reader.GetMethodDefinition)
                .Single(definition => reader.GetString(definition.Name) == methodName);
            var signature = method.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(qualifiedNames: true), null);
            Assert.Equal("Int32", signature.ReturnType);
            Assert.Equal(new[] { @namespace + "." + callback }, signature.ParameterTypes);
        }

        private sealed class SdkFixture : IDisposable
        {
            private readonly string root;
            private readonly string architecture;
            private readonly string project;

            internal SdkFixture(string architecture)
            {
                this.architecture = architecture;
                root = Path.Combine(Path.GetTempPath(), "win32-sdk-annotations-" + Guid.NewGuid().ToString("N"));
                Directory.CreateDirectory(root);
                string assets = Path.Combine(AppContext.BaseDirectory, "assets");
                string sharedSettings = Path.Combine(root, "shared.rsp");
                File.WriteAllText(sharedSettings, @"--libraryPath
fixture.dll
--remap
_PRIVATE_RECORD=AUTHORED_RECORD
--exclude
EXCLUDED_RECORD
");
                string emptyJson = Path.Combine(root, "empty.json");
                File.WriteAllText(emptyJson, "[]");
                var partitions = new XElement("ItemGroup");
                foreach (string name in new[] { "Annotated", "Legacy", "Frozen" })
                {
                    string directory = Path.Combine(root, name);
                    Directory.CreateDirectory(directory);
                    string header = Path.Combine(directory, "test.h");
                    File.WriteAllText(header, "#include \"" + Path.Combine(assets, "win32metadata_annotations.h").Replace('\\', '/') + "\"\n" + (name == "Frozen" ? @"
typedef int (__stdcall FROZEN_CALLBACK)(int value);
typedef FROZEN_CALLBACK* LPFROZEN_CALLBACK;
int __stdcall UseFrozen(LPFROZEN_CALLBACK callback);
" : @"
typedef int (__stdcall* STATUS_CALLBACK)(int value);
#ifndef WIN32METADATA
typedef STATUS_CALLBACK* LPSTATUS_CALLBACK;
#endif
struct _PRIVATE_RECORD { int value; };
struct EXCLUDED_RECORD { int value; };
int __stdcall SetCallback(STATUS_CALLBACK callback);
int __stdcall UseRecord(_PRIVATE_RECORD* record);
"));
                    string main = Path.Combine(directory, "main.cpp");
                    File.WriteAllText(main, "#include \"test.h\"\n");
                    if (name == "Annotated")
                        SetAnnotations(enabled: true);
                    partitions.Add(new XElement("Partition", new XAttribute("Include", main),
                        new XElement("Name", name), new XElement("Namespace", "Test." + name),
                        new XElement("TraverseFiles", header)));
                }
                project = Path.Combine(root, "fixture.proj");
                new XDocument(new XElement("Project",
                    new XElement("PropertyGroup",
                        new XElement("ObjDir", Path.Combine(root, "obj")),
                        new XElement("TaskBinDir", Path.GetDirectoryName(typeof(ScrapeHeaders).Assembly.Location)),
                        new XElement("ToolsBinDir", Path.GetDirectoryName(typeof(RemapDiscovery).Assembly.Location)),
                        new XElement("Win32MetadataAssetsDir", assets),
                        new XElement("SdkIncRoot", root),
                        new XElement("TargetPlatformSdkRootOverride", root),
                        new XElement("ScriptsDir", root),
                        new XElement("ScanArch", architecture),
                        new XElement("MaxProcessors", "1"),
                        new XElement("PartitionFilter", "Annotated,Legacy")),
                    partitions,
                    new XElement("ItemGroup",
                        new XElement("ScraperRsp", new XAttribute("Include", sharedSettings)),
                        new XElement("ResponseFile", new XAttribute("Include", sharedSettings)),
                        new XElement("FunctionPointerFixup", new XAttribute("Include", emptyJson)),
                        new XElement("AutoTypesForSettingsOnly", new XAttribute("Include", emptyJson))),
                    new XElement("Import", new XAttribute("Project", Path.Combine(assets, "scraper.sdk.targets"))),
                    new XElement("Target", new XAttribute("Name", "CompileIdls")),
                    new XElement("Target", new XAttribute("Name", "PrepareWithLibsRsp")))).Save(project);
            }

            internal string GeneratedDirectory => Path.Combine(root, "obj", "generated");
            internal string AutoRemaps => Path.Combine(GeneratedDirectory, "scraper.autoRemaps.generated.rsp");
            internal string AnnotatedRemaps => Path.Combine(root, "obj", "scratch", architecture, "Annotated.remaps");
            internal string ReadSource(string partition) => File.ReadAllText(Path.Combine(GeneratedDirectory, architecture, partition + ".cs"));
            internal string ReadDiscovery(string partition) => File.ReadAllText(Path.Combine(root, "obj", "scratch", architecture, partition + ".remaps"));
            internal HashSet<string> ReadPointerReductions(params string[] partitions)
                => partitions.SelectMany(partition => ReadDiscovery(partition).Split(new[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries))
                    .Where(line => line.StartsWith("REDUCE_PTR_LEVEL:", StringComparison.Ordinal))
                    .Select(line => line.Substring("REDUCE_PTR_LEVEL:".Length)).ToHashSet(StringComparer.Ordinal);
            internal HashSet<string> ReadEmitterPointerReductions()
                => RspReader.GetSettingsValues(Path.Combine(GeneratedDirectory, "emitter.autoFnPtr." + architecture + ".generated.rsp"),
                    "--reducePointerLevel").ToHashSet(StringComparer.Ordinal);

            internal void SetAnnotations(bool enabled)
                => File.WriteAllText(Path.Combine(root, "Annotated", "settings.rsp"), enabled ? "--config\nparse-win32-annotations\n" : "");

            internal void Build(string partitionFilter = null)
            {
                var start = new ProcessStartInfo("dotnet")
                {
                    WorkingDirectory = root,
                    UseShellExecute = false,
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                };
                foreach (string argument in new[] { "msbuild", project, "-t:ScrapeHeaders", "-nologo", "-v:minimal" })
                    start.ArgumentList.Add(argument);
                if (partitionFilter != null)
                    start.ArgumentList.Add("-p:PartitionFilter=" + partitionFilter);
                using var process = Process.Start(start);
                var output = process.StandardOutput.ReadToEndAsync();
                var error = process.StandardError.ReadToEndAsync();
                process.WaitForExit();
                string diagnostics = output.GetAwaiter().GetResult() + error.GetAwaiter().GetResult();
                if (Directory.Exists(Path.Combine(root, "obj", "scratch")))
                {
                    foreach (string log in Directory.GetFiles(Path.Combine(root, "obj", "scratch"), "*.generation.output.txt", SearchOption.AllDirectories))
                        diagnostics += Environment.NewLine + File.ReadAllText(log);
                }
                Assert.True(process.ExitCode == 0, diagnostics);
            }

            public void Dispose() => Directory.Delete(root, recursive: true);
        }
    }
}

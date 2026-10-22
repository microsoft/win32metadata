using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Runtime.CompilerServices;
using System.Xml.Linq;
using ClangSharpSourceToWinmd;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class GeneratedSourceRetirementTests
    {
        [DataTestMethod]
        [DataRow("crossarch", "crossarch", false)]
        [DataRow("crossarch", "crossarch", true)]
        [DataRow("x64", "crossarch", true)]
        [DataRow("crossarch", "x64", false)]
        public void RetiredAutoTypesDoNotSurviveIncrementalEmission(string firstArchitecture, string nextArchitecture, bool emptyFile)
        {
            using var incremental = new Fixture();
            string definitions = Path.Combine(incremental.DirectoryPath, "autoTypes.json");
            File.WriteAllText(definitions,
                "[{\"Name\":\"RETIRED_HANDLE\",\"ValueType\":\"int\",\"Namespace\":\"Windows.Win32.RetirementTests\",\"NativeTypedef\":true}]");
            CollectionAssert.Contains(incremental.Emit(firstArchitecture, definitions), "Windows.Win32.RetirementTests.RETIRED_HANDLE");
            File.WriteAllText(definitions, "[]");

            string[] actual = incremental.Emit(nextArchitecture, emptyFile ? definitions : null);
            CollectionAssert.DoesNotContain(actual, "Windows.Win32.RetirementTests.RETIRED_HANDLE");
            Assert.IsFalse(Directory.GetFiles(incremental.GeneratedDirectory, "autotypes.cs", SearchOption.AllDirectories)
                .Any(path => !path.Contains(Path.DirectorySeparatorChar + "obj" + Path.DirectorySeparatorChar, StringComparison.Ordinal)));
            Assert.IsTrue(File.Exists(Path.Combine(incremental.GeneratedDirectory, "common", "Bindings.cs")));

            using var fresh = new Fixture();
            CollectionAssert.AreEqual(fresh.Emit(nextArchitecture), actual);
        }

        [DataTestMethod]
        [DataRow("common", "crossarch")]
        [DataRow("x86", "x86")]
        [DataRow("x64", "x64")]
        [DataRow("arm64", "arm64")]
        public void SparseProfileRootsDoNotRequireUnusedDirectories(string profile, string architecture)
        {
            using var fixture = new Fixture(profile);
            string[] actual = fixture.Emit(architecture);
            CollectionAssert.Contains(actual, "Windows.Win32.RetirementTests.Unrelated");
            foreach (string unused in new[] { "common", "x86", "x64", "arm64" }.Where(value => value != profile))
            {
                Assert.IsFalse(Directory.Exists(Path.Combine(fixture.GeneratedDirectory, unused)));
            }
        }

        [TestMethod]
        public void AutoTypeDeletionErrorsAreNotIgnored()
        {
            using var fixture = new Fixture();
            string stale = Path.Combine(fixture.GeneratedDirectory, "common", "autotypes.cs");
            File.WriteAllText(stale, "namespace Windows.Win32.RetirementTests { public struct Stale { } }");
            using var locked = File.Open(stale, FileMode.Open, FileAccess.Read, FileShare.Read);
            string output = Path.Combine(fixture.DirectoryPath, "Windows.Win32.winmd");

            Assert.AreEqual(-1, Program.Main(new[] {
                "--sourceDir", fixture.GeneratedDirectory, "--arch", "crossarch", "--outputFileName", output }));
            Assert.IsFalse(File.Exists(output));
        }

        [TestMethod]
        public void ManualStagingPrunesRetiredOutputsWithUnchangedOrEmptyInputs()
        {
            using var incremental = new Fixture();
            string kept = Path.Combine(incremental.DirectoryPath, "Kept.cs");
            string retired = Path.Combine(incremental.DirectoryPath, "Retired.cs");
            File.WriteAllText(kept, "namespace Windows.Win32.RetirementTests { public struct Kept { public int Value; } }");
            File.WriteAllText(retired, "namespace Windows.Win32.RetirementTests { public struct Retired { public int Value; } }");
            string vocabulary = Path.Combine(RepositoryRoot(), "generation", "WinSDK", "manual", "Metadata.cs");
            incremental.StageManual(vocabulary, kept, retired);
            CollectionAssert.Contains(incremental.Emit("crossarch"), "Windows.Win32.RetirementTests.Retired");

            incremental.StageManual(vocabulary, kept);
            Assert.IsFalse(File.Exists(Path.Combine(incremental.GeneratedDirectory, "Retired.manual.cs")));
            Assert.IsTrue(File.Exists(Path.Combine(incremental.GeneratedDirectory, "Kept.manual.cs")));
            Assert.IsTrue(File.Exists(Path.Combine(incremental.GeneratedDirectory, "common", "Bindings.cs")));
            Assert.IsFalse(File.Exists(Path.Combine(incremental.DirectoryPath, "Windows.Win32.winmd")));
            string[] actual = incremental.Emit("crossarch");
            CollectionAssert.DoesNotContain(actual, "Windows.Win32.RetirementTests.Retired");
            CollectionAssert.Contains(actual, "Windows.Win32.RetirementTests.Kept");

            using var fresh = new Fixture();
            fresh.StageManual(vocabulary, kept);
            CollectionAssert.AreEqual(fresh.Emit("crossarch"), actual);

            incremental.StageManual();
            Assert.AreEqual(0, Directory.GetFiles(incremental.GeneratedDirectory, "*.manual.cs").Length);
            Assert.IsTrue(File.Exists(Path.Combine(incremental.GeneratedDirectory, "common", "Bindings.cs")));
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void ManualIdentityReplacementCopiesEqualMetadataSources(bool removeManifest)
        {
            using var incremental = new Fixture();
            string original = CreateManualSource(incremental, "A", "OldRoot");
            string replacement = CreateManualSource(incremental, "B", "NewRoot");
            string vocabulary = Path.Combine(RepositoryRoot(), "generation", "WinSDK", "manual", "Metadata.cs");
            incremental.StageManual(vocabulary, original);
            CollectionAssert.Contains(incremental.Emit("crossarch"), "Windows.Win32.RetirementTests.OldRoot");
            if (removeManifest)
            {
                File.Delete(Path.Combine(incremental.GeneratedDirectory, "source-inputs.generated.txt"));
            }

            incremental.StageManual(vocabulary, replacement);
            string[] actual = incremental.Emit("crossarch");
            CollectionAssert.Contains(actual, "Windows.Win32.RetirementTests.NewRoot");
            CollectionAssert.DoesNotContain(actual, "Windows.Win32.RetirementTests.OldRoot");

            using var fresh = new Fixture();
            fresh.StageManual(vocabulary, replacement);
            CollectionAssert.AreEqual(fresh.Emit("crossarch"), actual);

            using var locked = File.Open(Path.Combine(incremental.GeneratedDirectory, "Kept.manual.cs"),
                FileMode.Open, FileAccess.Read, FileShare.Read);
            incremental.StageManual(vocabulary, replacement);
        }

        [TestMethod]
        public void FailedManualIdentityReplacementDoesNotCommitStagingState()
        {
            using var fixture = new Fixture();
            string original = CreateManualSource(fixture, "A", "OldRoot");
            string replacement = Path.Combine(fixture.DirectoryPath, "B", "Kept.cs");
            string vocabulary = Path.Combine(RepositoryRoot(), "generation", "WinSDK", "manual", "Metadata.cs");
            fixture.StageManual(vocabulary, original);
            CollectionAssert.Contains(fixture.Emit("crossarch"), "Windows.Win32.RetirementTests.OldRoot");

            fixture.StageInputs("CopyManualFilesToScraped", new[] { vocabulary, replacement },
                Array.Empty<string>(), expectSuccess: false);
            Assert.AreEqual(replacement, CreateManualSource(fixture, "B", "NewRoot"));
            fixture.StageManual(vocabulary, replacement);
            string[] actual = fixture.Emit("crossarch");
            CollectionAssert.Contains(actual, "Windows.Win32.RetirementTests.NewRoot");
            CollectionAssert.DoesNotContain(actual, "Windows.Win32.RetirementTests.OldRoot");
        }

        [TestMethod]
        public void RetiringAutoTypeInputsInvalidatesConsumersWithoutInvalidatingUnchangedSets()
        {
            using var fixture = new Fixture();
            string definitions = Path.Combine(fixture.DirectoryPath, "autoTypes.json");
            File.WriteAllText(definitions, "[]");
            fixture.StageInputs("TrackGeneratedSourceInputs", Array.Empty<string>(), new[] { definitions });
            string settings = Path.Combine(fixture.GeneratedDirectory, "scraper.autoTypes.generated.rsp");
            File.WriteAllText(settings, "--remap\nOLD_HANDLE=IntPtr\n");
            var products = new[] { "scannedheaders.crossarch.txt", "scannedheaders.x86.txt", "scannedheaders.x64.txt",
                "scannedheaders.arm64.txt", "constants.scraped.txt" }.Select(file => Path.Combine(fixture.GeneratedDirectory, file))
                .Append(Path.Combine(fixture.DirectoryPath, "Windows.Win32.winmd")).ToArray();
            foreach (string product in products)
            {
                File.WriteAllText(product, "previous output");
            }

            fixture.StageInputs("TrackGeneratedSourceInputs", Array.Empty<string>(), new[] { definitions });
            Assert.IsTrue(products.All(File.Exists));
            StringAssert.Contains(File.ReadAllText(settings), "OLD_HANDLE");
            fixture.StageInputs("TrackGeneratedSourceInputs", Array.Empty<string>(), Array.Empty<string>());
            Assert.IsFalse(products.Any(File.Exists));
            Assert.AreEqual(0L, new FileInfo(settings).Length);
            Assert.IsTrue(File.Exists(Path.Combine(fixture.GeneratedDirectory, "common", "Bindings.cs")));
        }

        private static string CreateManualSource(Fixture fixture, string directory, string typeName)
        {
            string path = Path.Combine(fixture.DirectoryPath, directory, "Kept.cs");
            Directory.CreateDirectory(Path.GetDirectoryName(path)!);
            File.WriteAllText(path,
                $"namespace Windows.Win32.RetirementTests {{ public struct {typeName} {{ public int Value; }} }}");
            File.SetLastWriteTimeUtc(path, new DateTime(2020, 1, 1, 0, 0, 0, DateTimeKind.Utc));
            return path;
        }

        private static string RepositoryRoot([CallerFilePath] string sourceFile = "") =>
            Path.GetFullPath(Path.Combine(Path.GetDirectoryName(sourceFile)!, "..", ".."));

        private sealed class Fixture : IDisposable
        {
            public Fixture(string? onlyProfile = null)
            {
                DirectoryPath = Path.Combine(Path.GetTempPath(), "win32metadata-retirement-" + Guid.NewGuid().ToString("N"));
                GeneratedDirectory = Path.Combine(DirectoryPath, "generated");
                foreach (string architecture in onlyProfile == null ? new[] { "common", "x86", "x64", "arm64" } : new[] { onlyProfile })
                {
                    Directory.CreateDirectory(Path.Combine(GeneratedDirectory, architecture));
                }

                File.Copy(Path.Combine(RepositoryRoot(), "generation", "WinSDK", "manual", "Metadata.cs"),
                    Path.Combine(GeneratedDirectory, "Metadata.manual.cs"));
                File.WriteAllText(Path.Combine(GeneratedDirectory, onlyProfile ?? "common", "Bindings.cs"),
                    "namespace Windows.Win32.RetirementTests { public struct Unrelated { public int Value; } }");
            }

            public string DirectoryPath { get; }

            public string GeneratedDirectory { get; }

            public string[] Emit(string architecture, string? autoTypes = null)
            {
                string output = Path.Combine(DirectoryPath, "Windows.Win32.winmd");
                var arguments = new[] { "--sourceDir", GeneratedDirectory, "--arch", architecture, "--outputFileName", output };
                if (autoTypes != null)
                {
                    arguments = arguments.Concat(new[] { "--autoTypes", autoTypes }).ToArray();
                }

                Assert.AreEqual(0, Program.Main(arguments));
                using var stream = File.OpenRead(output);
                using var pe = new PEReader(stream);
                var reader = pe.GetMetadataReader();
                return reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Select(type => reader.GetString(type.Namespace) + "." + reader.GetString(type.Name))
                    .OrderBy(name => name, StringComparer.Ordinal).ToArray();
            }

            public void StageManual(params string[] sources)
            {
                this.StageInputs("CopyManualFilesToScraped", sources, Array.Empty<string>());
            }

            public void StageInputs(string target, string[] manualSources, string[] autoTypes, bool expectSuccess = true)
            {
                var sdk = XDocument.Load(Path.Combine(RepositoryRoot(), "sources", "GeneratorSdk", "sdk", "sdk.targets")).Root!;
                string project = Path.Combine(DirectoryPath, "Staging.proj");
                new XDocument(new XElement("Project",
                    new XElement("PropertyGroup",
                        new XElement("GeneratedDir", GeneratedDirectory),
                        new XElement("OutputWinmd", Path.Combine(DirectoryPath, "Windows.Win32.winmd")),
                        sdk.Elements("PropertyGroup").Elements().Where(element => new[] {
                            "GeneratedSourceInputsFile", "ScraperAutoTypesRsp", "ScrapedConstantsMarker" }.Contains(element.Name.LocalName))
                            .Select(element => new XElement(element))),
                    new XElement("ItemGroup",
                        manualSources.Select(source => new XElement("ManualCs", new XAttribute("Include", source))),
                        autoTypes.Select(source => new XElement("AutoType", new XAttribute("Include", source)))),
                    sdk.Elements("Target").Where(element => new[] { "TrackGeneratedSourceInputs", "CopyManualFilesToScraped" }
                        .Contains((string?)element.Attribute("Name"))).Select(element => new XElement(element)))).Save(project);

                var start = new ProcessStartInfo(Environment.GetEnvironmentVariable("DOTNET_HOST_PATH") ?? "dotnet")
                {
                    UseShellExecute = false,
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                };
                foreach (string argument in new[] { "msbuild", project, "-target:" + target, "-nologo", "-verbosity:quiet" })
                {
                    start.ArgumentList.Add(argument);
                }

                using var process = Process.Start(start)!;
                var stdout = process.StandardOutput.ReadToEndAsync();
                var stderr = process.StandardError.ReadToEndAsync();
                if (!process.WaitForExit(60000))
                {
                    process.Kill(entireProcessTree: true);
                    Assert.Fail("Manual source staging timed out.");
                }

                string diagnostics = stdout.GetAwaiter().GetResult() + stderr.GetAwaiter().GetResult();
                if (expectSuccess)
                {
                    Assert.AreEqual(0, process.ExitCode, diagnostics);
                }
                else
                {
                    Assert.AreNotEqual(0, process.ExitCode, diagnostics);
                }
            }

            public void Dispose()
            {
                Directory.Delete(DirectoryPath, recursive: true);
            }
        }
    }
}

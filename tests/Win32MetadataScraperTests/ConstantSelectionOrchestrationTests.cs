using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Xml.Linq;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        [Fact]
        public void NormalConstantsTaskPassesExactPriorityInputOrderAndIncrementalPolicy()
        {
            using var first = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc",
                "#include \"sdk inputs\\um\\unlisted.h\"\nint F();");
            string sdk = Path.Combine(first.DirectoryPath, "sdk inputs");
            string original = Path.Combine(sdk, "um", "unlisted.h");
            string preferred = Path.Combine(sdk, "um", "devicetopology.h");
            Directory.CreateDirectory(Path.GetDirectoryName(original));
            File.WriteAllText(original, "#define CHOICE 13U\n");
            File.WriteAllText(preferred, "#define CHOICE 29U\n");
            using var second = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc",
                "#include \"" + preferred + "\"\nint G();");
            AppendNativeTraversal(first, original);
            AppendNativeTraversal(second, preferred);
            try
            {
                first.AssertSuccess();
                second.AssertSuccess();
                string generated = Path.Combine(first.DirectoryPath, "generated with spaces");
                string target = Path.Combine(generated, "x86");
                Directory.CreateDirectory(target);
                File.Copy(Path.ChangeExtension(second.Output, ".native-constants.json"), Path.Combine(target, "Alpha.native-constants.json"));
                File.Copy(Path.ChangeExtension(first.Output, ".native-constants.json"), Path.Combine(target, "Zeta.native-constants.json"));
                File.Copy(first.Output, Path.Combine(target, "Zeta.cs"));
                string helper = Path.Combine(generated, "Metadata.manual.cs");
                File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"), helper);
                string header = Path.Combine(first.DirectoryPath, "constants header.txt");
                File.WriteAllText(header, "using System; using Windows.Win32.Foundation.Metadata;");
                string marker = Path.Combine(generated, "constants.scraped.txt");
                string project = Path.Combine(first.DirectoryPath, "constants.proj");
                new XDocument(new XElement("Project",
                    new XAttribute("DefaultTargets", "Run"),
                    new XElement("UsingTask",
                        new XAttribute("TaskName", "MetadataTasks.ScrapeConstants"),
                        new XAttribute("AssemblyFile", Path.Combine(AppContext.BaseDirectory, "MetadataTasks.dll"))),
                    new XElement("ItemGroup",
                        Partition(first, "Zeta", "First", original),
                        Partition(second, "Alpha", "Second", preferred),
                        new XElement("Manual", new XAttribute("Include", helper))),
                    new XElement("Target", new XAttribute("Name", "Run"),
                        new XElement("ScrapeConstants",
                            new XAttribute("DefaultNamespace", "Test"),
                            new XAttribute("ScraperOutputDir", generated),
                            new XAttribute("HeaderTextFile", header),
                            new XAttribute("Partitions", "@(Partition)"),
                            new XAttribute("ManualCs", "@(Manual)"),
                            new XAttribute("ToolsBinDir", AppContext.BaseDirectory),
                            new XAttribute("MSBuildProjectDirectory", first.DirectoryPath),
                            new XAttribute("SdkIncRoot", sdk),
                            new XAttribute("HeaderPriority", "$(Priority)"),
                            new XAttribute("MarkerFileName", marker))))).Save(project);

                RunConstantsProject(project, "", expected: 0);
                using (var report = ReadReport())
                {
                    var inputs = report.RootElement.GetProperty("NativeInputs").EnumerateArray().ToArray();
                    Assert.Equal(new[] { "Zeta.native-constants.json", "Alpha.native-constants.json" },
                        inputs.Select(value => Path.GetFileName(value.GetProperty("Path").GetString())));
                    Assert.Equal("13U", Choice(report).GetProperty("Selected").GetProperty("Value").GetString());
                }
                DateTime previous = File.GetLastWriteTimeUtc(marker);
                RunConstantsProject(project, @"um\devicetopology.h", expected: 0);
                using (var report = ReadReport())
                {
                    Assert.Equal(sdk, report.RootElement.GetProperty("SdkRoot").GetString());
                    Assert.Equal("29U", Choice(report).GetProperty("Selected").GetProperty("Value").GetString());
                    Assert.True(Assert.Single(report.RootElement.GetProperty("HeaderPriority").EnumerateArray())
                        .GetProperty("Applicable").GetBoolean());
                }
                Assert.True(File.GetLastWriteTimeUtc(marker) > previous);
                DateTime unchanged = File.GetLastWriteTimeUtc(marker);
                string output = RunConstantsProject(project, @"um\devicetopology.h", expected: 0);
                Assert.DoesNotContain("Scraping constants and enums...", output);
                Assert.Equal(unchanged, File.GetLastWriteTimeUtc(marker));
                string error = RunConstantsProject(project, @"C:\not-a-relative-header.h", expected: 1);
                Assert.Contains("Invalid or repeated SDK-root-relative priority header", error);
                Assert.Equal(unchanged, File.GetLastWriteTimeUtc(marker));
                using var image = Emit(generated, "x86");
                Assert.Equal(29U, ReadUInt32Field(image.Reader, "Apis", "CHOICE"));

                JsonDocument ReadReport() => JsonDocument.Parse(File.ReadAllText(Path.Combine(generated, "native-constant-conflicts.json")));
                static JsonElement Choice(JsonDocument report) => report.RootElement.GetProperty("Decisions").EnumerateArray()
                    .Single(value => value.GetProperty("Name").GetString() == "CHOICE");
            }
            finally
            {
                SaveOpaqueRecordArtifacts(first, "matched-constants-task-orchestration");
                SaveOpaqueRecordArtifacts(second, "matched-constants-task-other-native-source");
            }

            static XElement Partition(HeaderAnnotationTests.NativeFixture fixture, string name, string ns, string traversed) =>
                new("Partition", new XAttribute("Include", Path.Combine(fixture.DirectoryPath, "test.cpp")),
                    new XElement("Name", name), new XElement("Namespace", ns), new XElement("TraverseFiles", traversed));
        }

        private static string RunConstantsProject(string project, string priority, int expected)
        {
            using var process = new Process();
            process.StartInfo = new ProcessStartInfo("dotnet")
            {
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
            };
            foreach (string argument in new[] { "msbuild", project, "-nologo", "-v:normal", "-p:Priority=" + priority })
                process.StartInfo.ArgumentList.Add(argument);
            process.Start();
            var stdout = process.StandardOutput.ReadToEndAsync();
            var stderr = process.StandardError.ReadToEndAsync();
            bool completed = process.WaitForExit(60000);
            if (!completed)
                process.Kill(entireProcessTree: true);
            Assert.True(completed, "The normal constants task did not finish.");
            string output = stdout.GetAwaiter().GetResult() + stderr.GetAwaiter().GetResult();
            File.AppendAllText(Path.ChangeExtension(project, ".log"), $"Priority={priority}; exit={process.ExitCode}\n{output}\n");
            Assert.True(expected == process.ExitCode, output);
            return output;
        }
    }
}

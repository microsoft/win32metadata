using System;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Reflection;
using System.Security.Cryptography;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Xml.Linq;
using Xunit;

namespace WinmdGenerator.IntegrationTests
{
    public sealed class PackageFixture : IDisposable
    {
        private const string PackageId = "Microsoft.Windows.WinmdGenerator";
        private readonly string root;
        private readonly byte[] packageHash;
        private readonly string logDirectory;

        public PackageFixture()
        {
            string packagePath = Environment.GetEnvironmentVariable("WINMD_GENERATOR_PACKAGE_PATH");
            Assert.True(File.Exists(packagePath),
                "Set WINMD_GENERATOR_PACKAGE_PATH to the just-built nupkg, or run scripts\\TestWinmdGeneratorPackage.ps1.");

            using var archive = ZipFile.OpenRead(packagePath);
            using var nuspecStream = archive.Entries.Single(e => e.FullName.EndsWith(".nuspec", StringComparison.OrdinalIgnoreCase)).Open();
            var metadata = XDocument.Load(nuspecStream).Root.Elements().Single(e => e.Name.LocalName == "metadata");
            Assert.Equal(PackageId, metadata.Elements().Single(e => e.Name.LocalName == "id").Value);
            string version = metadata.Elements().Single(e => e.Name.LocalName == "version").Value;

            string repositoryRoot = typeof(PackageFixture).Assembly.GetCustomAttributes<AssemblyMetadataAttribute>()
                .Single(a => a.Key == "RepositoryRoot").Value;
            string runId = Guid.NewGuid().ToString("N");
            root = Path.Combine(Path.GetTempPath(), "WinmdGeneratorIntegration-" + runId);
            logDirectory = Path.Combine(repositoryRoot, "bin", "logs", "WinmdGeneratorIntegration", runId);
            Directory.CreateDirectory(root);
            Directory.CreateDirectory(logDirectory);

            string feed = Directory.CreateDirectory(Path.Combine(root, "feed")).FullName;
            File.Copy(packagePath, Path.Combine(feed, Path.GetFileName(packagePath)));
            using (var packageStream = File.OpenRead(packagePath))
            {
                packageHash = SHA256.HashData(packageStream);
            }
            PackageDirectory = Path.Combine(root, "packages", PackageId.ToLowerInvariant(), version.ToLowerInvariant());

            var globalJson = JsonNode.Parse(File.ReadAllText(Path.Combine(repositoryRoot, "global.json")));
            globalJson["msbuild-sdks"][PackageId] = version;
            File.WriteAllText(Path.Combine(root, "global.json"), globalJson.ToJsonString(new JsonSerializerOptions { WriteIndented = true }));

            var sources = XElement.Load(Path.Combine(repositoryRoot, "nuget.config")).Element("packageSources")
                .Elements("add").Select(source => new XElement(source)).ToArray();
            var mapping = new XElement("packageSourceMapping",
                new XElement("packageSource", new XAttribute("key", "package-under-test"),
                    new XElement("package", new XAttribute("pattern", PackageId))));
            foreach (var source in sources)
            {
                mapping.Add(new XElement("packageSource", new XAttribute("key", source.Attribute("key").Value),
                    new XElement("package", new XAttribute("pattern", "*"))));
            }

            new XDocument(new XElement("configuration",
                new XElement("packageSources", new XElement("clear"),
                    new XElement("add", new XAttribute("key", "package-under-test"), new XAttribute("value", feed)), sources),
                new XElement("disabledPackageSources", new XElement("clear")), mapping))
                .Save(Path.Combine(root, "nuget.config"));

            foreach (string name in new[] { "Directory.Build.props", "Directory.Build.targets", "Directory.Packages.props" })
            {
                File.WriteAllText(Path.Combine(root, name), "<Project />");
            }
        }

        public string PackageDirectory { get; }

        public string Build(string scenario, string arch)
        {
            string name = scenario + "-" + arch;
            string projectDirectory = Directory.CreateDirectory(Path.Combine(root, name)).FullName;
            string outputDirectory = Directory.CreateDirectory(Path.Combine(logDirectory, name)).FullName;
            CopyFixture("Common", projectDirectory);
            if (scenario != "Basic")
            {
                CopyFixture(scenario, projectDirectory);
            }

            RunDotnet(projectDirectory, Path.Combine(outputDirectory, "restore.log"),
                "restore", "Consumer.proj", "--configfile", Path.Combine(root, "nuget.config"), "--verbosity", "minimal");
            RunDotnet(projectDirectory, Path.Combine(outputDirectory, "build.log"),
                "build", "Consumer.proj", "--no-restore", "--configuration", "Release", "--nologo", "--verbosity", "minimal",
                "-p:ScanArch=" + arch, "-bl:" + Path.Combine(outputDirectory, "build.binlog"));
            string buildLog = File.ReadAllText(Path.Combine(outputDirectory, "build.log"));
            Assert.Contains("Scraping headers for " + arch + "...", buildLog);
            Assert.Contains("Using Win32MetadataScraper from "
                + Path.Combine(PackageDirectory, "tools", "net10.0", "win-x64", "Win32MetadataScraper.dll"), buildLog);

            string restoredPackage = Directory.GetFiles(PackageDirectory, "*.nupkg").Single();
            using (var packageStream = File.OpenRead(restoredPackage))
            {
                Assert.Equal(packageHash, SHA256.HashData(packageStream));
            }

            string[] expectedPaths =
            {
                PackageDirectory,
                Path.Combine(PackageDirectory, "tools", "net10.0"),
                Path.Combine(PackageDirectory, "tools", "net10.0"),
                Path.Combine(PackageDirectory, "scripts"),
                Path.Combine(PackageDirectory, "tools", "assets"),
            };
            string[] actualPaths = File.ReadAllLines(Path.Combine(projectDirectory, "bin", "package-paths.txt"));
            Assert.Equal(expectedPaths.Length, actualPaths.Length);
            for (int i = 0; i < expectedPaths.Length; i++)
            {
                Assert.Equal(Path.GetFullPath(expectedPaths[i]), Path.GetFullPath(actualPaths[i]), ignoreCase: true);
            }

            string winmd = Path.Combine(projectDirectory, "bin", "PackageIntegration.winmd");
            Assert.True(File.Exists(winmd), "The SDK build did not produce " + winmd);
            string savedWinmd = Path.Combine(outputDirectory, "PackageIntegration.winmd");
            File.Copy(winmd, savedWinmd);
            return savedWinmd;
        }

        public void Dispose()
        {
            Directory.Delete(root, recursive: true);
        }

        private static void CopyFixture(string name, string destination)
        {
            string source = Path.Combine(AppContext.BaseDirectory, "Fixtures", name);
            foreach (string file in Directory.GetFiles(source, "*", SearchOption.AllDirectories))
            {
                string target = Path.Combine(destination, Path.GetRelativePath(source, file));
                Directory.CreateDirectory(Path.GetDirectoryName(target));
                File.Copy(file, target, overwrite: true);
            }
        }

        private void RunDotnet(string workingDirectory, string logPath, params string[] arguments)
        {
            var startInfo = new ProcessStartInfo("dotnet")
            {
                WorkingDirectory = workingDirectory,
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                CreateNoWindow = true,
            };
            foreach (string argument in arguments)
            {
                startInfo.ArgumentList.Add(argument);
            }

            startInfo.Environment["NUGET_PACKAGES"] = Path.Combine(root, "packages");
            startInfo.Environment["NUGET_HTTP_CACHE_PATH"] = Path.Combine(root, "http-cache");
            startInfo.Environment["NUGET_FALLBACK_PACKAGES"] = string.Empty;
            using var process = Process.Start(startInfo);
            var output = process.StandardOutput.ReadToEndAsync();
            var error = process.StandardError.ReadToEndAsync();
            bool exited = process.WaitForExit(300000);
            if (!exited)
            {
                process.Kill(entireProcessTree: true);
                process.WaitForExit();
            }

            string transcript = "dotnet " + string.Join(" ", arguments) + Environment.NewLine
                + output.GetAwaiter().GetResult() + error.GetAwaiter().GetResult();
            File.WriteAllText(logPath, transcript);
            Assert.True(exited, "SDK consumption timed out. See " + logPath + Environment.NewLine + transcript);
            Assert.True(process.ExitCode == 0, "SDK consumption failed. See " + logPath + Environment.NewLine + transcript);
        }
    }
}

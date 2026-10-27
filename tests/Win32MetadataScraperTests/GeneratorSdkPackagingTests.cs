using System;
using System.IO;
using System.IO.Enumeration;
using System.Linq;
using System.Text.Json;
using System.Xml.Linq;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class GeneratorSdkPackagingTests
    {
        [Fact]
        public void PackagedScraperIncludesEveryManagedRuntimeDependency()
        {
            var directory = new DirectoryInfo(AppContext.BaseDirectory);
            while (directory != null && !File.Exists(Path.Combine(directory.FullName, "sources", "GeneratorSdk", "nuget", "BuildSdk.nuspec")))
                directory = directory.Parent;
            string repositoryRoot = directory?.FullName ?? throw new InvalidOperationException("Repository manifest was not found.");
            string manifestPath = Path.Combine(repositoryRoot, "sources", "GeneratorSdk", "nuget", "BuildSdk.nuspec");
            var manifest = XDocument.Load(manifestPath);
            var scraperFiles = manifest.Root.Element("files").Elements("file")
                .Where(file => string.Equals(file.Attribute("target").Value.TrimEnd('\\'),
                    @"tools\net10.0\win-x64", StringComparison.OrdinalIgnoreCase))
                .Select(file => file.Attribute("src").Value)
                .ToArray();
            Assert.NotEmpty(scraperFiles);

            string dependenciesPath = Path.Combine(AppContext.BaseDirectory, "Win32MetadataScraper.deps.json");
            using var dependencies = JsonDocument.Parse(File.ReadAllText(dependenciesPath));
            string runtimeTarget = dependencies.RootElement.GetProperty("runtimeTarget").GetProperty("name").GetString();
            var runtimeAssets = dependencies.RootElement.GetProperty("targets").GetProperty(runtimeTarget)
                .EnumerateObject()
                .Where(library => library.Value.TryGetProperty("runtime", out _))
                .SelectMany(library => library.Value.GetProperty("runtime").EnumerateObject())
                .Select(asset => Path.GetFileName(asset.Name))
                .Distinct(StringComparer.OrdinalIgnoreCase);

            foreach (string asset in runtimeAssets)
            {
                Assert.True(scraperFiles.Any(source =>
                    FileSystemName.MatchesSimpleExpression(Path.GetFileName(source), asset, ignoreCase: true) &&
                    File.Exists(Path.Combine(repositoryRoot, Path.GetDirectoryName(source), asset))),
                    $"The generator SDK must include {asset} beside Win32MetadataScraper.dll.");
            }
        }
    }
}

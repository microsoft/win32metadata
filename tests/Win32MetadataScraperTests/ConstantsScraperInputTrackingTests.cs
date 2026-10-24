using System;
using System.IO;
using System.Reflection;
using MetadataTasks;
using Microsoft.Build.Framework;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class ConstantsScraperInputTrackingTests
    {
        [Theory]
        [InlineData("ConstantsScraper.dll", false)]
        [InlineData("MetadataUtils.dll", false)]
        [InlineData("constants.header.txt", false)]
        [InlineData("ConstantsScraper.dll", true)]
        [InlineData("MetadataUtils.dll", true)]
        [InlineData("constants.header.txt", true)]
        public void ChangedOrMissingProducerInputsRequireRescraping(string inputName, bool remove)
        {
            string directory = Path.Combine(Path.GetTempPath(), "constant-inputs-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string tools = Path.Combine(directory, "tools");
                Directory.CreateDirectory(tools);
                string header = Path.Combine(directory, "constants.header.txt");
                string marker = Path.Combine(directory, "constants.scraped.txt");
                var inputs = new[]
                {
                    Path.Combine(tools, "ConstantsScraper.dll"),
                    Path.Combine(tools, "MetadataUtils.dll"),
                    header,
                };
                DateTime before = DateTime.UtcNow.AddMinutes(-1);
                foreach (string input in inputs)
                {
                    File.WriteAllText(input, "");
                    File.SetLastWriteTimeUtc(input, before);
                }
                File.WriteAllText(marker, "");
                var task = new ScrapeConstants
                {
                    ToolsBinDir = tools,
                    HeaderTextFile = header,
                    MarkerFileName = marker,
                    ScraperOutputDir = directory,
                    MSBuildProjectDirectory = directory,
                    ResponseFiles = Array.Empty<ITaskItem>(),
                    ManualCs = Array.Empty<ITaskItem>(),
                };
                MethodInfo check = typeof(ScrapeConstants).GetMethod("AreNonPartitionFilesUpToDate",
                    BindingFlags.Instance | BindingFlags.NonPublic)!;
                Assert.True(Assert.IsType<bool>(check.Invoke(task, null)));

                string changed = inputName.EndsWith(".dll", StringComparison.Ordinal)
                    ? Path.Combine(tools, inputName) : header;
                if (remove)
                    File.Delete(changed);
                else
                    File.SetLastWriteTimeUtc(changed, File.GetLastWriteTimeUtc(marker).AddSeconds(1));

                Assert.False(Assert.IsType<bool>(check.Invoke(task, null)));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }
    }
}

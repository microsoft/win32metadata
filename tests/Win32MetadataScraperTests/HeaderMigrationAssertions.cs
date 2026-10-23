using System;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text.Json;
using System.Text.RegularExpressions;
using MetadataTasks;
using Xunit;

namespace Win32MetadataScraperTests
{
    internal static class HeaderMigrationAssertions
    {
        internal static string SdkRoot => Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK");

        internal static string AddedSource(string artifact)
            => string.Join("\n", File.ReadAllLines(Path.Combine(SdkRoot, "patches", artifact + ".patch"))
                .Where(line => line.StartsWith("+", StringComparison.Ordinal) &&
                    !line.StartsWith("+++", StringComparison.Ordinal)).Select(line => line.Substring(1)));

        internal static string PatchedSource(string artifact)
        {
            string original = Path.Combine(SdkRoot, "RecompiledIdlHeaders", artifact);
            using var recipe = JsonDocument.Parse(File.ReadAllText(Path.Combine(SdkRoot, "patches", "SdkHeaders.json")));
            var descriptor = Assert.Single(recipe.RootElement.GetProperty("headers").EnumerateArray()
                .Where(header => string.Equals(header.GetProperty("path").GetString(), artifact, StringComparison.OrdinalIgnoreCase)));
            Assert.Equal(descriptor.GetProperty("sourceSha256").GetString(),
                Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(original))));
            string[] lines = File.ReadAllLines(original);
            var result = new System.Collections.Generic.List<string>();
            int cursor = 0;
            bool inHunk = false;
            foreach (string line in File.ReadAllLines(Path.Combine(SdkRoot, "patches", artifact + ".patch")))
            {
                var hunk = Regex.Match(line, @"^@@ -(\d+)(?:,\d+)? \+\d+(?:,\d+)? @@");
                if (hunk.Success)
                {
                    int start = Math.Max(0, int.Parse(hunk.Groups[1].Value) - 1);
                    Assert.InRange(start, cursor, lines.Length);
                    result.AddRange(lines.Skip(cursor).Take(start - cursor));
                    cursor = start;
                    inHunk = true;
                }
                else if (inHunk && line.Length != 0 && line[0] != '\\')
                {
                    if (line[0] == '+')
                        result.Add(line.Substring(1));
                    else
                    {
                        Assert.Contains(line[0], new[] { ' ', '-' });
                        Assert.True(cursor < lines.Length, "Patch context extends beyond the pinned original.");
                        Assert.Equal(line.Substring(1), lines[cursor]);
                        if (line[0] == ' ')
                            result.Add(lines[cursor]);
                        cursor++;
                    }
                }
            }
            result.AddRange(lines.Skip(cursor));
            return string.Join("\n", result);
        }

        internal static void AssertAnnotationReaderEnabled(string partition)
        {
            string filtered = Path.GetTempFileName();
            try
            {
                var filter = new FilterResponseFiles
                {
                    ResponseFiles = new[]
                    {
                        new Microsoft.Build.Utilities.TaskItem(Path.Combine(SdkRoot, "scraper.settings.rsp")),
                        new Microsoft.Build.Utilities.TaskItem(Path.Combine(SdkRoot, "Partitions", partition, "settings.rsp")),
                    },
                    OutputFileName = filtered,
                    ValidSwitches = "--config",
                    MSBuildProjectDirectory = SdkRoot,
                };
                Assert.True(filter.Execute());
                Assert.Single(File.ReadAllLines(filtered).Distinct(StringComparer.Ordinal)
                    .Where(line => line == "parse-win32-annotations"));
            }
            finally
            {
                File.Delete(filtered);
            }
        }

        internal static void AssertNativeTypedef(string artifact, string name)
            => Assert.Matches(@"_Win32_NativeTypedef_\s+typedef\s+" + Regex.Escape(name) +
                @"\s+" + Regex.Escape(name) + @";", AddedSource(artifact));

        internal static void AssertCommentFact(string artifact, string kind, string target, string payload)
            => Assert.Contains($"/* Win32Metadata: {kind} ::{target} => {payload} */",
                AddedSource(artifact).Replace("\\\"", "\"", StringComparison.Ordinal));

        internal static void AssertAssociationCounts(string source, params string[] expected)
            => Assert.Equal(expected.OrderBy(value => value, StringComparer.Ordinal),
                Regex.Matches(source, @"_Win32_AssociatedEnum_\(([^)]+)\)")
                    .Select(match => match.Groups[1].Value).GroupBy(value => value, StringComparer.Ordinal)
                    .Select(group => group.Key + "=" + group.Count()).OrderBy(value => value, StringComparer.Ordinal));

        internal static void AssertContributions(System.Collections.Generic.IEnumerable<Match> groups, params string[] expected)
            => Assert.Equal(expected.OrderBy(value => value, StringComparer.Ordinal),
                groups.Select(group => group.Groups["name"].Value + "|" + group.Groups["kind"].Value + "|" +
                    group.Groups["storage"].Value.Trim() + "|" +
                    string.Join(",", group.Groups["members"].Value.Split(',').Select(value => value.Trim())))
                    .OrderBy(value => value, StringComparer.Ordinal));
    }
}

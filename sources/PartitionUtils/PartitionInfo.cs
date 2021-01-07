using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace PartitionUtils
{
    public class PartitionInfo
    {
        private RepoInfo repoInfo;
        private string partitionName;
        private List<string> visitedHeaders;
        private List<string> traverseHeaders;

        public PartitionInfo(RepoInfo repoInfo, string partitionName)
        {
            this.repoInfo = repoInfo;
            this.partitionName = partitionName;
        }

        public void EnsureSettingsUsingNamspace()
        {
            if (this.Namespace == null)
            {
                File.AppendAllText(this.SettingsFile, $"--namespace\r\n{this.DefaultNamespaceName}\r\n");
            }
        }

        public IEnumerable<string> GetSettingsValues(string settingsName)
        {
            bool inSettingsName = false;
            foreach (string line in File.ReadAllLines(this.SettingsFile))
            {
                if (line.StartsWith("--"))
                {
                    inSettingsName = line == settingsName;
                    continue;
                }

                if (inSettingsName)
                {
                    yield return line;
                }
            }
        }

        public string Namespace
        {
            get
            {
                var values = this.GetSettingsValues("--namespace");
                return values.FirstOrDefault();
            }
        }

        public void AddTraverseHeader(string header)
        {
            var oldLines = File.ReadAllLines(this.SettingsFile);
            bool foundTraverseBlock = false;
            using (StreamWriter writer = new StreamWriter(this.SettingsFile))
            {
                foreach (string line in oldLines)
                {
                    writer.WriteLine(line);
                    if (!foundTraverseBlock && line == "--traverse")
                    {
                        foundTraverseBlock = true;
                        writer.WriteLine($"<IncludeRoot>{header.Replace('\\', '/')}");
                    }
                }
            }
        }

        private static readonly Regex VisitingHeaderRegex = new Regex(@"Info: Visiting .+(\/(?:um|shared|winrt)\/[^\r\n]+)");
        private static readonly Regex FilesInSettingsRspRegex = new Regex(@".+(\/(?:um|shared|winrt)\/.+)");

        public string Name => this.partitionName;

        public string DefaultNamespaceName => this.partitionName.Replace("_", string.Empty);

        public string SettingsFile => Path.Combine(this.repoInfo.ParitionDir, $"{this.partitionName}\\settings.rsp");

        public string GenerationOutputFile => Path.Combine(this.repoInfo.ArtifactsOutputDir, $"{this.partitionName}.generation.output.txt");

        public ReadOnlyCollection<string> VisitedHeaders
        {
            get
            {
                if (this.visitedHeaders == null)
                {
                    this.visitedHeaders = new List<string>();

                    string text = File.ReadAllText(this.GenerationOutputFile);
                    foreach (Match match in VisitingHeaderRegex.Matches(text))
                    {
                        this.visitedHeaders.Add(match.Groups[1].Value);
                    }
                }

                return this.visitedHeaders.AsReadOnly();
            }
        }

        public ReadOnlyCollection<string> TraverseHeaders
        {
            get
            {
                if (this.traverseHeaders == null)
                {
                    this.traverseHeaders = new List<string>();
                    bool inTraverse = false;
                    foreach (string line in File.ReadAllLines(this.SettingsFile))
                    {
                        if (line.StartsWith("--"))
                        {
                            inTraverse = line == "--traverse";
                            continue;
                        }

                        if (inTraverse)
                        {
                            var match = FilesInSettingsRspRegex.Match(line);
                            if (match.Success)
                            {
                                this.traverseHeaders.Add(match.Groups[1].Value);
                            }
                        }
                    }
                }

                return this.traverseHeaders.AsReadOnly();
            }
        }

        public override string ToString()
        {
            return this.partitionName;
        }

        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }

    }
}

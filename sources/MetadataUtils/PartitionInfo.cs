using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

namespace MetadataUtils
{
    public class PartitionInfo
    {
        private RepoInfo repoInfo;
        private string partitionName;
        private Dictionary<string, List<string>> visitedHeaders = new Dictionary<string, List<string>>();
        private List<string> traverseHeaders;
        private string incRoot;

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

        private static readonly Regex VisitingHeaderRegex = new Regex(@"Info: Visiting (.+)(\/(?:um|shared|winrt)\/[^\r\n]+)");
        private static readonly Regex FilesInSettingsRspRegex = new Regex(@".+(\/(?:um|shared|winrt)\/.+)");

        public string Name => this.partitionName;

        public string DefaultNamespaceName => this.partitionName.Replace("_", string.Empty);

        public string SettingsFile => Path.Combine(this.repoInfo.ParitionDir, $"{this.partitionName}\\settings.rsp");

        public string GetGenerationOutputFile(string arch)
        {
            return Path.Combine(this.repoInfo.GetScraperOutputDir(arch), $"{this.partitionName}.generation.output.txt");
        }

        public ReadOnlyCollection<string> GetVisitedHeaders(string arch)
        {
            this.LoadVisitedHeaders(arch);

            return this.visitedHeaders[arch].AsReadOnly();
        }

        public ReadOnlyCollection<string> GetTraverseHeaders(bool fullPath, string arch)
        {
            if (this.traverseHeaders == null)
            {
                this.LoadVisitedHeaders(arch);
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
                        if (Path.IsPathRooted(line))
                        {
                            this.traverseHeaders.Add(line);
                        }
                        else
                        {
                            var match = FilesInSettingsRspRegex.Match(line);
                            if (match.Success)
                            {
                                this.traverseHeaders.Add(match.Groups[1].Value);
                            }
                        }
                    }
                }
            }

            if (!fullPath)
            {
                return this.traverseHeaders.AsReadOnly();
            }

            List<string> longPaths = new List<string>();
            foreach (var shortPath in this.traverseHeaders)
            {
                if (Path.IsPathFullyQualified(shortPath))
                {
                    longPaths.Add(shortPath);
                }
                else
                {
                    string longPath = this.incRoot + shortPath;
                    longPath = longPath.Replace('/', '\\');
                    longPaths.Add(longPath);
                }
            }

            return longPaths.AsReadOnly();
        }

        private void LoadVisitedHeaders(string arch)
        {
            if (!this.visitedHeaders.ContainsKey(arch))
            {
                List<string> headers = new List<string>();

                string text = File.ReadAllText(this.GetGenerationOutputFile(arch));
                foreach (Match match in VisitingHeaderRegex.Matches(text))
                {
                    string rootDir = match.Groups[1].Value;
                    if (this.incRoot == null)
                    {
                        this.incRoot = rootDir;
                    }

                    string shortName = match.Groups[2].Value;
                    string fullPath = rootDir + shortName;
                    headers.Add(fullPath);
                }

                this.visitedHeaders[arch] = headers;
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

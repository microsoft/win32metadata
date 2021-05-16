using System.Collections.Generic;
using System.IO;

namespace MetadataUtils
{
    public class RepoInfo
    {
        private string repoRoot;

        public RepoInfo(string repoRoot)
        {
            this.repoRoot = Path.GetFullPath(repoRoot);
        }

        public string ParitionDir => Path.Combine(this.repoRoot, "generation\\scraper\\partitions");

        public string GetScraperOutputDir(string arch) 
        { 
            return Path.Combine(this.repoRoot, $"generation\\scraper\\obj\\{arch}"); 
        }

        public IEnumerable<PartitionInfo> GetPartitionInfos()
        {
            foreach (var partionDir in Directory.GetDirectories(this.ParitionDir))
            {
                var partitionName = Path.GetFileName(partionDir);
                yield return new PartitionInfo(this, partitionName);
            }
        }

        public void UpdateGeneratedSourceHeader()
        {
            string headerPath = Path.Combine(this.repoRoot, "generation\\header.txt");
            using (StreamWriter streamWriter = new StreamWriter(headerPath))
            {
                streamWriter.WriteLine("// Copyright © Microsoft");
                streamWriter.WriteLine("using Windows.Win32.Interop");
                streamWriter.WriteLine();

                foreach (var partInfo in this.GetPartitionInfos())
                {
                    var ns = partInfo.Namespace;
                    streamWriter.WriteLine($"using {ns}");
                }
            }
        }

        public void AddTraverseHeader(string header, string partName)
        {
            var partInfo = new PartitionInfo(this, partName);
            partInfo.AddTraverseHeader(header);
        }
    }
}

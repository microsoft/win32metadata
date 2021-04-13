using System.Collections.Generic;
using System.IO;

namespace PartitionUtilsLib
{
    public class RepoInfo
    {
        private string generationDir;

        public RepoInfo(string generationDir)
        {
            this.generationDir = Path.GetFullPath(generationDir);
        }

        public string ParitionDir => Path.Combine(this.generationDir, "scraper\\Partitions");

        public string ScraperOutputDir => Path.Combine(this.generationDir, "scraper\\obj");

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
            string headerPath = Path.Combine(this.generationDir, "scraper\\header.txt");
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

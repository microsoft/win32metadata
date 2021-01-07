using System.Collections.Generic;
using System.IO;

namespace PartitionUtils
{
    public class RepoInfo
    {
        private string repoRoot;
        private string artifactsDir;

        public RepoInfo(string repoRoot, string artifactsDir)
        {
            this.repoRoot = Path.GetFullPath(repoRoot);
            this.artifactsDir = artifactsDir;

            if (this.artifactsDir == null)
            {
                this.artifactsDir = Path.Combine(this.repoRoot, "artifacts");
            }
        }

        public string ParitionDir => Path.Combine(this.repoRoot, "generation\\partitions");

        public string ArtifactsOutputDir => Path.Combine(this.artifactsDir, "output");

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

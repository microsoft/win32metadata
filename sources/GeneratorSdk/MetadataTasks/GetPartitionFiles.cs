using System.Collections.Generic;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class GetPartitionFiles : Task
    {
        [Required]
        public ITaskItem[] Partitions { get; set; }

        [Output]
        public ITaskItem[] AllFiles { get; set; }

        [Required]
        public string MSBuildProjectDirectory { get; set; }

        [Required]
        public string SdkIncRoot { get; set; }

        public override bool Execute()
        {
            List<ITaskItem> ret = new List<ITaskItem>();

            foreach (ITaskItem partItem in this.Partitions)
            {
                var partition = Partition.FromTaskItem(partItem, this.MSBuildProjectDirectory, this.SdkIncRoot);
                ret.Add(new TaskItem(partition.FullPath));

                foreach (var file in partition.TraverseFiles)
                {
                    ret.Add(new TaskItem(file));
                }
            }

            this.AllFiles = ret.ToArray();

            return true;
        }
    }
}

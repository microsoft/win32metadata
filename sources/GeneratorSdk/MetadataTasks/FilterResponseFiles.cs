using System.Collections.Generic;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class FilterResponseFiles : Task
    {
        [Required]
        public ITaskItem[] ResponseFiles { get; set; }

        [Required]
        public string OutputFileName { get; set; }

        [Required]
        public string ValidSwitches { get; set; }

        [Required]
        public string MSBuildProjectDirectory { get; set; }

        public override bool Execute()
        {
            IEnumerable<string> rspPaths = TaskUtils.GetFullPaths(this.ResponseFiles, this.MSBuildProjectDirectory);
            TaskUtils.FilterRspFiles(rspPaths, this.OutputFileName, this.ValidSwitches.Split(';'));

            return true;
        }
    }
}

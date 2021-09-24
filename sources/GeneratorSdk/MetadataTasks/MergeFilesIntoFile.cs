using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class MergeFilesIntoFile : Task
    {
        [Required]
        public ITaskItem[] InputFiles { get; set; }

        [Required]
        public string OutputFile { get; set; }

        public override bool Execute()
        {
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_MERGE_FILES_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif
            Directory.CreateDirectory(Path.GetDirectoryName(this.OutputFile));

            using var streamWriter = new StreamWriter(this.OutputFile);
            foreach (var item in this.InputFiles)
            {
                string fileName = item.ItemSpec;
                if (File.Exists(fileName))
                {
                    streamWriter.WriteLine($"// From {fileName}");
                    streamWriter.Write(File.ReadAllText(fileName));
                }
            }

            return true;
        }
    }
}

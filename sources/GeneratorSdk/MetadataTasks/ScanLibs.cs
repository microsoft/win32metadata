using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class ScanLibs : Task
    {
        public ITaskItem[] Libs { get; set; }

        [Required]
        public string LibToolsBinDir { get; set; }

        [Required]
        public string WithLibsRsp { get; set; }

        [Required]
        public string MSBuildProjectDirectory { get; set; }

        public override bool Execute()
        {
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_TASKS") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            string[] libFiles = this.GetLibs();
            string dumpBinPath = Path.Combine(this.LibToolsBinDir, "dumpbin.exe");
            var libLines = new StringBuilder();
            var libRegex = new Regex(@"DLL name     : (\S+)\s+Symbol name  : (\S+)");
            var functionNames = new HashSet<string>(System.StringComparer.OrdinalIgnoreCase);
            foreach (var lib in libFiles)
            {
                string dbinArgs = $"/headers \"{lib}\"";
                TaskUtils.ExecuteCmd(dumpBinPath, dbinArgs, out var dbinOutput, this.Log);
                foreach (Match match in libRegex.Matches(dbinOutput))
                {
                    var dllName = Path.GetFileNameWithoutExtension(match.Groups[1].Value);
                    var functionName = match.Groups[2].Value;

                    if (!functionNames.Contains(functionName))
                    {
                        if (libLines.Length == 0)
                        {
                            libLines.AppendLine("--with-librarypath");
                        }

                        libLines.AppendLine($"{functionName}={dllName}");
                        functionNames.Add(functionName);
                    }
                }
            }

            if (libLines.Length != 0)
            {
                var dir = Path.GetDirectoryName(this.WithLibsRsp);
                Directory.CreateDirectory(dir);

                File.WriteAllText(this.WithLibsRsp, libLines.ToString());
            }
            else
            {
                if (File.Exists(this.WithLibsRsp))
                {
                    File.Delete(this.WithLibsRsp);
                }
            }

            return true;
        }

        private string[] GetLibs()
        {
            var ret = new List<string>();
            if (this.Libs != null)
            {
                foreach (ITaskItem libItem in this.Libs)
                {
                    var libPath = libItem.ItemSpec;
                    if (!Path.IsPathRooted(libPath))
                    {
                        libPath = Path.Combine(this.MSBuildProjectDirectory, libPath);
                    }

                    ret.Add(libPath);
                }
            }

            return ret.ToArray();
        }
    }
}

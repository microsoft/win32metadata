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
        public ITaskItem[] Libs
        {
            get;
            set;
        }

        [Required]
        public string LibToolsBinDir
        {
            get; set;
        }

        [Output]
        public ITaskItem OutputLibRsp
        {
            get;set;
        }

        [Required]
        public string MSBuildProjectDirectory
        {
            get; set;
        }

        public override bool Execute()
        {
#if DEBUG
            System.Diagnostics.Debugger.Launch();
#endif

            Log.LogMessage($"Scanning libs...");

            string[] libFiles = GetLibs();
            string dumpBinPath = Path.Combine(this.LibToolsBinDir, "dumpbin.exe");
            StringBuilder libLines = new StringBuilder();
            Regex libRegex = new Regex(@"DLL name     : (\S+)\s+Symbol name  : (\S+)");
            HashSet<string> functionNames = new HashSet<string>(System.StringComparer.OrdinalIgnoreCase);
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
                var objDir = Path.Combine(this.MSBuildProjectDirectory, "obj");
                Directory.CreateDirectory(objDir);

                string rspFile = Path.Combine(objDir, $"withLibs.generated.rsp");
                File.WriteAllText(rspFile, libLines.ToString());

                this.OutputLibRsp = new TaskItem(rspFile);
            }

            return true;
        }

        private string[] GetLibs()
        {
            List<string> ret = new List<string>();
            if (this.Libs != null)
            {
                foreach (var libItem in this.Libs)
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

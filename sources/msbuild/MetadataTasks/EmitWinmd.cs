using System.IO;
using System.Linq;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class EmitWinmd : Task
    {
        [Required]
        public string ToolsBinDir
        {
            get; set;
        }

        [Required]
        public string EmitterSourceDir
        {
            get; set;
        }

        [Required]
        public string WinmdVersion
        {
            get; set;
        }

        [Required]
        public string OutputWinmd
        {
            get; set;
        }

        [Required]
        public string Win32WinmdBinDir
        {
            get; set;
        }

        [Required]
        public string MSBuildProjectDirectory
        {
            get; set;
        }

        [Required]
        public ITaskItem[] Libs
        {
            get; set;
        }

        [Output]
        public ITaskItem[] FileWrites
        {
            get; set;
        }

        public override bool Execute()
        {
            Log.LogMessage($"Emitting winmd...");

            string dllPath = Path.Combine(this.ToolsBinDir, "ClangSharpSourceToWinmd.dll");
            string interopPath = Path.Combine(this.Win32WinmdBinDir, "Windows.Win32.Interop.dll");
            string win32WinmdPath = Path.Combine(this.Win32WinmdBinDir, "Windows.Win32.winmd");

            string outputWinmd = this.OutputWinmd;
            if (!Path.IsPathRooted(outputWinmd))
            {
                outputWinmd = Path.Combine(this.MSBuildProjectDirectory, outputWinmd);
            }

            var args = new StringBuilder($"{dllPath} --sourceDir \"{this.EmitterSourceDir}\" --arch x64 --interopFileName \"{interopPath}\" --ref \"{win32WinmdPath}\" --version {this.WinmdVersion} --outputFileName \"{outputWinmd}\"");

            var staticLibs = GetStaticLibs();

            if (staticLibs.Length > 0)
            {
                string rspFile = Path.Combine(this.EmitterSourceDir, @"staticLibs.generated.rsp");
                var rspArgs = new StringBuilder();

                rspArgs.AppendLine(@"--staticLibs");
                foreach (string staticLib in staticLibs)
                {
                    rspArgs.AppendLine(staticLib);
                }

                File.WriteAllText(rspFile, rspArgs.ToString());
                args.AppendFormat($" @{rspFile}");
            }

            int exitCode = TaskUtils.ExecuteCmd("dotnet", args.ToString(), out var output, this.Log);
            if (exitCode < 0)
            {
                Log.LogError($"ClangSharpSourceToWinmd.dll failed: {output}");
                return false;
            }

            Log.LogMessage(MessageImportance.High, $"Winmd emitted at: {outputWinmd}");
            this.FileWrites = new ITaskItem[] { new TaskItem(outputWinmd) };

            return true;
        }

        private string[] GetStaticLibs()
        {
            return this.Libs
                .Select(importLib => importLib.GetMetadata("StaticLibs"))
                .Where(staticLibs => !string.IsNullOrWhiteSpace(staticLibs))
                .SelectMany(staticLibs => staticLibs.Split(';'))
                .Distinct()
                .ToArray();
        }
    }
}

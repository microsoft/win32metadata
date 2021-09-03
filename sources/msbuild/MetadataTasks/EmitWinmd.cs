using System.IO;
using System.Linq;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class EmitWinmd : ToolTask
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

        private string outputWinmdFullPath;

        protected override string ToolName => "dotnet";

        protected override string GenerateFullPathToTool() => this.ToolExe;

        protected override string GenerateCommandLineCommands()
        {
            var builder = new CommandLineBuilder();
            builder.AppendFileNameIfNotNull(Path.Combine(this.ToolsBinDir, "ClangSharpSourceToWinmd.dll"));

            string interopPath = Path.Combine(this.Win32WinmdBinDir, "Windows.Win32.Interop.dll");
            string win32WinmdPath = Path.Combine(this.Win32WinmdBinDir, "Windows.Win32.winmd");

            this.outputWinmdFullPath = this.OutputWinmd;
            if (!Path.IsPathRooted(this.outputWinmdFullPath))
            {
                this.outputWinmdFullPath = Path.Combine(this.MSBuildProjectDirectory, this.outputWinmdFullPath);
            }

            builder.AppendSwitchIfNotNull("--sourceDir ", this.EmitterSourceDir);
            builder.AppendSwitchIfNotNull("--arch ", "x64");
            builder.AppendSwitchIfNotNull("--interopFileName ", interopPath);
            builder.AppendSwitchIfNotNull("--ref ", win32WinmdPath);
            builder.AppendSwitchIfNotNull("--version ", this.WinmdVersion);
            builder.AppendSwitchIfNotNull("--outputFileName ", this.outputWinmdFullPath);

            return builder.ToString();
        }

        protected override string GenerateResponseFileCommands()
        {
            var builder = new CommandLineBuilder();
            var staticLibs = this.GetStaticLibs();
            if (staticLibs.Length > 0)
            {
                builder.AppendSwitchIfNotNull("--staticLibs ", staticLibs," ");
            }

            return builder.ToString();
        }

        protected override int ExecuteTool(string pathToTool, string responseFileCommands, string commandLineCommands)
        {
            this.Log.LogMessage($"Emitting winmd...");
            int exitCode = base.ExecuteTool(pathToTool, responseFileCommands, commandLineCommands);
            if (exitCode != 0)
            {
                this.Log.LogError($"ClangSharpSourceToWinmd.dll failed.");
                return exitCode;
            }

            this.Log.LogMessage(MessageImportance.High, $"Winmd emitted at: {this.outputWinmdFullPath}");
            this.FileWrites = new ITaskItem[] { new TaskItem(this.outputWinmdFullPath) };
            return exitCode;
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

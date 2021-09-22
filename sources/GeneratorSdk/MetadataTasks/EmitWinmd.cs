using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;
using System;

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

        public string ShowOutputDetails
        {
            get;set;
        }

        private bool ShouldShowOutputDetails => this.ShowOutputDetails != null && this.ShowOutputDetails == "true";

        public ITaskItem[] ResponseFiles { get; set; }

        public string AutoTypesJson { get; set; }

        private string outputWinmdFullPath;

        protected override string ToolName => "dotnet";

        protected override string GenerateFullPathToTool() => this.ToolExe;

        protected override MessageImportance StandardOutputLoggingImportance => this.ShouldShowOutputDetails ? MessageImportance.High : MessageImportance.Normal;

        protected override string GenerateCommandLineCommands()
        {
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_EMITTER_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            var builder = new CommandLineBuilder();
            builder.AppendFileNameIfNotNull(Path.Combine(this.ToolsBinDir, "ClangSharpSourceToWinmd.dll"));

            string interopPath = Path.Combine(this.Win32WinmdBinDir, "Windows.Win32.Interop.dll");
            string win32WinmdPath = Path.Combine(this.Win32WinmdBinDir, "Windows.Win32.winmd");

            this.outputWinmdFullPath = this.OutputWinmd;
            if (!Path.IsPathRooted(this.outputWinmdFullPath))
            {
                this.outputWinmdFullPath = Path.GetFullPath(Path.Combine(this.MSBuildProjectDirectory, this.outputWinmdFullPath));
            }

            builder.AppendSwitchIfNotNull("--sourceDir ", this.EmitterSourceDir);
            builder.AppendSwitchIfNotNull("--arch ", "crossarch");
            builder.AppendSwitchIfNotNull("--interopFileName ", interopPath);

            if (!StringComparer.OrdinalIgnoreCase.Equals(
                Path.GetFileName(this.outputWinmdFullPath),
                Path.GetFileName(win32WinmdPath)))
            {
                builder.AppendSwitchIfNotNull("--ref ", win32WinmdPath);
            }

            builder.AppendSwitchIfNotNull("--version ", this.WinmdVersion);
            builder.AppendSwitchIfNotNull("--outputFileName ", this.outputWinmdFullPath);

            if (File.Exists(this.AutoTypesJson))
            {
                builder.AppendSwitchIfNotNull("--autoTypes ", this.AutoTypesJson);
            }

            IEnumerable<string> rspFiles = TaskUtils.GetFullPaths(this.ResponseFiles, this.MSBuildProjectDirectory);
            foreach (var rspFile in rspFiles)
            {
                if (File.Exists(rspFile))
                {
                    builder.AppendRspFile(rspFile);
                }
            }

            return builder.ToString();
        }

        protected override string GenerateResponseFileCommands()
        {
            var ret = new StringBuilder();
            var staticLibs = this.GetStaticLibs();
            if (staticLibs.Length > 0)
            {
                ret.AppendLine("--staticLibs");
                foreach (var lib in staticLibs)
                {
                    ret.AppendLine(lib);
                }
            }

            return ret.ToString();
        }

        protected override int ExecuteTool(string pathToTool, string responseFileCommands, string commandLineCommands)
        {
            this.Log.LogMessage($"Emitting winmd...");

            this.EchoOff = false;

            int exitCode = base.ExecuteTool(pathToTool, responseFileCommands, commandLineCommands);
            if (exitCode != 0)
            {
                this.Log.LogError($"ClangSharpSourceToWinmd.dll failed.");
                return exitCode;
            }

            this.Log.LogMessage(MessageImportance.High, $"Winmd emitted at: {this.outputWinmdFullPath}");
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

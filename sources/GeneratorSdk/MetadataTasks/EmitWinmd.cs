using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class EmitWinmd : ToolTask
    {
        private string outputWinmdFullPath;
        private string partitionsWithoutCrossarchDifferences;
        private StringBuilder fullOutput = new StringBuilder();

        [Required]
        public string ToolsBinDir { get; set; }

        [Required]
        public string EmitterSourceDir { get; set; }

        [Required]
        public string WinmdVersion { get; set; }

        [Required]
        public string OutputWinmd { get; set; }

        [Required]
        public string Win32WinmdBinDir { get; set; }

        [Required]
        public string MSBuildProjectDirectory { get; set; }

        [Required]
        public ITaskItem[] Libs { get; set; }

        public string ShowOutputDetails { get; set; }

        public ITaskItem[] ResponseFiles { get; set; }

        public ITaskItem[] AutoTypes { get; set; }

        protected override string ToolName => "dotnet";

        protected override string GenerateFullPathToTool() => this.ToolExe;

        protected override MessageImportance StandardOutputLoggingImportance => this.ShouldShowOutputDetails ? MessageImportance.High : MessageImportance.Normal;

        private bool ShouldShowOutputDetails => this.ShowOutputDetails != null && this.ShowOutputDetails == "true";

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

            foreach (var autoTypeJson in TaskUtils.GetFullPaths(this.AutoTypes, this.MSBuildProjectDirectory))
            {
                if (File.Exists(autoTypeJson))
                {
                    builder.AppendSwitchIfNotNull("--autoTypes ", autoTypeJson);
                }
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
                this.Log.LogError($"ClangSharpSourceToWinmd failed. Full output:\r\n{this.fullOutput}");
                return exitCode;
            }

            if (!string.IsNullOrEmpty(this.partitionsWithoutCrossarchDifferences))
            {
                string sortedDifferences = string.Join(';', this.partitionsWithoutCrossarchDifferences.Split(';').OrderBy(s => s).ToArray());
                this.Log.LogMessage(
                    MessageImportance.High,
                    "There are partitions that have no cross-arch differences. You can exclude them from cross-arch processing and speed up builds by adding this property to the project file:");
                this.Log.LogMessage(
                    MessageImportance.High,
                    $"<ExcludeFromCrossarch>{sortedDifferences}</ExcludeFromCrossarch>");
                this.Log.LogMessage(
                    MessageImportance.High,
                    $"Or, add this property to any partitions you want to exclude: <ExcludeFromCrossarch>true</ExcludeFromCrossarch>");
            }

            this.Log.LogMessage(MessageImportance.High, $"Winmd emitted at: {this.outputWinmdFullPath}");
            return exitCode;
        }

        protected override void LogEventsFromTextOutput(string singleLine, MessageImportance messageImportance)
        {
            // See if the line contains the warning about partitions that don't need crossarch
            if (singleLine.Contains("CSSW001"))
            {
                int lastColon = singleLine.LastIndexOf(':');
                if (lastColon != -1)
                {
                    this.partitionsWithoutCrossarchDifferences =
                        singleLine.Substring(lastColon + 1).Trim().Replace(',', ';');
                }
            }

            this.fullOutput.AppendLine(singleLine);

            base.LogEventsFromTextOutput(singleLine, messageImportance);
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

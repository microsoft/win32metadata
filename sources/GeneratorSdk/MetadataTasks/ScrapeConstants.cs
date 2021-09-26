using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class ScrapeConstants : ToolTask
    {
        private Partition[] loadedPartitions;

        [Required]
        public string DefaultNamespace { get; set; }

        [Required]
        public string ScraperOutputDir { get; set; }

        public string HeaderTextFile { get; set; }

        public ITaskItem[] ResponseFiles { get; set; }

        [Required]
        public ITaskItem[] Partitions { get; set; }

        public string EnumsJson { get; set; }

        [Required]
        public string ToolsBinDir { get; set; }

        [Required]
        public string MSBuildProjectDirectory { get; set; }

        [Required]
        public string SdkIncRoot { get; set; }

        [Required]
        public string MarkerFileName { get; set; }

        protected override string ToolName => "dotnet";

        protected override string GenerateFullPathToTool() => this.ToolExe;

        public override bool Execute()
        {
            this.EchoOff = false;

#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_CONSTANTS_SCRAPER_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            bool needsBuild = !File.Exists(this.MarkerFileName);
            this.loadedPartitions = Partition.FromTaskItems(this.Partitions, this.MSBuildProjectDirectory, this.SdkIncRoot).ToArray();
            needsBuild |= this.loadedPartitions.Any(p => !p.IsUpToDate(this.MarkerFileName));
            needsBuild |= !this.AreNonPartitionFilesUpToDate();

            if (!needsBuild)
            {
                return true;
            }

            this.Log.LogMessage(MessageImportance.High, $"Scraping constants and enums...");

            bool ret = base.Execute();

            if (ret)
            {
                File.WriteAllText(this.MarkerFileName, string.Empty);
            }

            return ret;
        }

        protected override string GenerateCommandLineCommands()
        {
            var builder = new CommandLineBuilder();
            builder.AppendFileNameIfNotNull(Path.Combine(this.ToolsBinDir, "ConstantsScraper.dll"));

            builder.AppendSwitchIfNotNull("--headerTextFile ", this.HeaderTextFile);
            builder.AppendSwitchIfNotNull("--scraperOutputDir ", this.ScraperOutputDir);

            IEnumerable<string> reponseFiles = TaskUtils.GetFullPaths(this.ResponseFiles, this.MSBuildProjectDirectory);
            foreach (var file in reponseFiles)
            {
                builder.AppendRspFileIfNotNull(file);
            }

            return builder.ToString();
        }

        protected override string GenerateResponseFileCommands()
        {
            StringBuilder ret = new();

            this.AppendTraversedFilesAndNamespaces(ret);

            if (!string.IsNullOrEmpty(this.EnumsJson))
            {
                string enumsJson = TaskUtils.GetFullPath(this.EnumsJson, this.MSBuildProjectDirectory);
                if (File.Exists(enumsJson))
                {
                    ret.AppendLine($"--enumsJson\n{enumsJson}");
                }
            }

            return ret.ToString();
        }

        private bool AreNonPartitionFilesUpToDate()
        {
            IEnumerable<string> files = TaskUtils.GetFullPaths(this.ResponseFiles, this.MSBuildProjectDirectory);

            if (this.EnumsJson != null)
            {
                files = files.Concat(new string[] { TaskUtils.GetFullPath(this.EnumsJson, this.MSBuildProjectDirectory) });
            }

            return TaskUtils.IsUpToDate(files, this.MarkerFileName);
        }

        private void AppendTraversedFilesAndNamespaces(StringBuilder rsp)
        {
            foreach (Partition partition in this.loadedPartitions)
            {
                var ns = partition.Namespace;
                foreach (var file in partition.TraverseFiles)
                {
                    rsp.AppendLine($"{file}={ns}");
                }
            }

            if (rsp.Length != 0)
            {
                rsp.Insert(0, "--traversedFileToNamespace\n");
            }
        }
    }
}

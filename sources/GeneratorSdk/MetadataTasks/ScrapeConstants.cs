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

        [Required]
        public ITaskItem[] ManualCs {get; set;}

        public string EnumsJson { get; set; }

        [Required]
        public string ToolsBinDir { get; set; }

        [Required]
        public string MSBuildProjectDirectory { get; set; }

        [Required]
        public string SdkIncRoot { get; set; }

        public string[] HeaderPriority { get; set; }

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
                string nativeInputs = Path.Combine(this.ScraperOutputDir, "native-constant-inputs.txt");
                string[] paths = this.GetNativeConstantInputs();
                if (paths.Length != 0 || File.Exists(nativeInputs))
                    File.WriteAllLines(nativeInputs, paths);
                File.WriteAllLines(Path.Combine(this.ScraperOutputDir, "constant-selection-inputs.txt"), this.GetSelectionInputs());
            }

            return ret;
        }

        protected override string GenerateCommandLineCommands()
        {
            var builder = new CommandLineBuilder();
            builder.AppendFileNameIfNotNull(Path.Combine(this.ToolsBinDir, "ConstantsScraper.dll"));

            builder.AppendSwitchIfNotNull("--headerTextFile ", this.HeaderTextFile);
            builder.AppendSwitchIfNotNull("--scraperOutputDir ", this.ScraperOutputDir);
            builder.AppendSwitchIfNotNull("--sdkRoot ", this.SdkIncRoot);

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
            if (this.HeaderPriority?.Length > 0)
            {
                ret.AppendLine("--headerPriority");
                foreach (string header in this.HeaderPriority)
                    ret.AppendLine(header);
            }
            string[] nativeInputs = this.GetOrderedNativeConstantInputs();
            if (nativeInputs.Length != 0)
            {
                ret.AppendLine("--nativeInput");
                foreach (string path in nativeInputs)
                    ret.AppendLine(path);
            }

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

            files = files.Concat(TaskUtils.GetFullPaths(this.ManualCs, this.MSBuildProjectDirectory));

            if (this.EnumsJson != null)
            {
                files = files.Concat(new string[] { TaskUtils.GetFullPath(this.EnumsJson, this.MSBuildProjectDirectory) });
            }

            var producerInputs = new List<string>
            {
                Path.Combine(this.ToolsBinDir, "ConstantsScraper.dll"),
                Path.Combine(this.ToolsBinDir, "MetadataUtils.dll"),
                typeof(ScrapeConstants).Assembly.Location,
            };
            if (!string.IsNullOrEmpty(this.HeaderTextFile))
                producerInputs.Add(TaskUtils.GetFullPath(this.HeaderTextFile, this.MSBuildProjectDirectory));
            if (producerInputs.Any(file => !File.Exists(file)))
                return false;
            files = files.Concat(producerInputs);
            string policy = Path.Combine(this.ScraperOutputDir, "constant-selection-inputs.txt");
            if (!File.Exists(policy) || !File.ReadAllLines(policy).SequenceEqual(this.GetSelectionInputs(), System.StringComparer.Ordinal))
                return false;
            if (Directory.Exists(this.ScraperOutputDir))
                files = files.Concat(Directory.GetFiles(this.ScraperOutputDir, "*header-types.cs", SearchOption.AllDirectories)
                    .Where(path => !MetadataUtils.NativeConstantValues.IsGeneratedSource(path)));

            string[] nativePaths = this.GetNativeConstantInputs();
            string nativeInputs = Path.Combine(this.ScraperOutputDir, "native-constant-inputs.txt");
            if (nativePaths.Length != 0 || File.Exists(nativeInputs))
                if (!File.Exists(nativeInputs) || !File.ReadAllLines(nativeInputs).SequenceEqual(nativePaths, System.StringComparer.OrdinalIgnoreCase))
                    return false;
            return TaskUtils.IsUpToDate(files.Concat(nativePaths), this.MarkerFileName);
        }

        private string[] GetNativeConstantInputs() => Directory.Exists(this.ScraperOutputDir)
            ? Directory.GetFiles(this.ScraperOutputDir, "*.native-constants.json", SearchOption.AllDirectories)
                .OrderBy(path => path, System.StringComparer.OrdinalIgnoreCase).ToArray()
            : System.Array.Empty<string>();

        private string[] GetSelectionInputs() => new[] { "sdkRoot=" + Path.GetFullPath(this.SdkIncRoot) }
            .Concat((this.HeaderPriority ?? System.Array.Empty<string>()).Select(header => "headerPriority=" + header))
            .Concat(this.GetOrderedNativeConstantInputs().Select(path => "nativeInput=" + path)).ToArray();

        private string[] GetOrderedNativeConstantInputs()
        {
            var remaining = this.GetNativeConstantInputs().ToHashSet(System.StringComparer.OrdinalIgnoreCase);
            var ordered = new List<string>();
            foreach (var partition in this.loadedPartitions)
                foreach (string target in new[] { "common", "x86", "x64", "arm64" })
                {
                    string path = Path.GetFullPath(Path.Combine(this.ScraperOutputDir, target, partition.Name + ".native-constants.json"));
                    if (remaining.Remove(path))
                        ordered.Add(path);
                }
            if (remaining.Count != 0)
                throw new InvalidDataException("Native constant inputs have no project partition-order owner: " +
                    string.Join(", ", remaining));
            return ordered.ToArray();
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

            File.WriteAllText(Path.Combine(this.ScraperOutputDir, "traversedFileToNamespace.rsp"), rsp.ToString());
        }

    }
}

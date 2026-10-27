using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class ScrapeConstants : ToolTask
    {
        private Partition[] loadedPartitions;
        private string[] orderedNativeInputs;
        private readonly MetadataUtils.GenerationValidation validation = new();

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

        public string[] ToolchainIncludeRoots { get; set; }

        public bool PreflightOnly { get; set; }

        public string BlockedBy { get; set; }

        [Required]
        public string MarkerFileName { get; set; }

        protected override string ToolName => "dotnet";

        protected override string GenerateFullPathToTool() => this.ToolExe;

        public override bool Execute()
        {
            this.EchoOff = false;
            bool actualScrape = !this.PreflightOnly;
            Directory.CreateDirectory(this.ScraperOutputDir);
            File.Delete(Path.Combine(this.ScraperOutputDir, "constants-task-diagnostics.json"));
            File.Delete(Path.Combine(this.ScraperOutputDir, "constants-preflight-diagnostics.json"));

#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_CONSTANTS_SCRAPER_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            bool needsBuild = !File.Exists(this.MarkerFileName);
            var partitions = new List<Partition>();
            foreach (var item in this.Partitions)
            {
                var partition = Partition.FromTaskItem(item, this.MSBuildProjectDirectory, this.SdkIncRoot);
                try
                {
                    _ = partition.Namespace;
                    partitions.Add(partition);
                }
                catch (InvalidDataException error)
                {
                    this.validation.Add(error, "WMG004", "constants.partition-plan", partition.FullPath,
                        partition: item.GetMetadata("Name"), selectedSdkRoot: this.SdkIncRoot);
                }
            }
            this.loadedPartitions = partitions.ToArray();
            _ = this.GetOrderedNativeConstantInputs();
            needsBuild |= this.loadedPartitions.Any(p => !p.IsUpToDate(this.MarkerFileName));
            needsBuild |= !this.AreNonPartitionFilesUpToDate();
            needsBuild |= this.PreflightOnly || this.validation.HasErrors;

            if (!needsBuild)
            {
                return true;
            }
            if (actualScrape)
                File.Delete(Path.Combine(this.ScraperOutputDir, "native-constant-conflicts.json"));

            if (this.validation.HasErrors)
            {
                this.PreflightOnly = true;
                this.BlockedBy ??= "valid constants input/partition plan";
                this.validation.Block("ScrapeConstants;EmitWinmd;default tests", this.BlockedBy);
                Directory.CreateDirectory(this.ScraperOutputDir);
                this.validation.WriteReport(Path.Combine(this.ScraperOutputDir, "constants-task-diagnostics.json"));
                this.Log.LogError(this.validation.Format());
            }
            this.Log.LogMessage(MessageImportance.High, this.PreflightOnly
                ? "Validating independent constants inputs..." : "Scraping constants and enums...");

            File.Delete(this.MarkerFileName);
            string[] selectionInputs = this.PreflightOnly ? null : this.GetSelectionInputs();
            bool ret = base.Execute();

            if (ret && !this.PreflightOnly && !this.validation.HasErrors)
            {
                File.WriteAllText(this.MarkerFileName, string.Empty);
                string nativeInputs = Path.Combine(this.ScraperOutputDir, "native-constant-inputs.txt");
                string[] paths = this.GetNativeConstantInputs();
                if (paths.Length != 0 || File.Exists(nativeInputs))
                    File.WriteAllLines(nativeInputs, paths);
                File.WriteAllLines(Path.Combine(this.ScraperOutputDir, "constant-selection-inputs.txt"), selectionInputs);
            }
            else
            {
                this.Log.LogError(this.PreflightOnly
                    ? $"Blocked constants finalization, EmitWinmd and default tests: requires valid {this.BlockedBy}. See constants-preflight-diagnostics.json."
                    : "Blocked EmitWinmd and default tests: constants finalization failed. " +
                        "See native-constant-conflicts.json and the complete constants scraper output.");
            }

            return ret && !this.PreflightOnly && !this.validation.HasErrors;
        }

        protected override string GenerateCommandLineCommands()
        {
            var builder = new CommandLineBuilder();
            builder.AppendFileNameIfNotNull(Path.Combine(this.ToolsBinDir, "ConstantsScraper.dll"));

            if (!this.PreflightOnly)
                builder.AppendSwitchIfNotNull("--headerTextFile ", this.HeaderTextFile);
            builder.AppendSwitchIfNotNull("--scraperOutputDir ", this.ScraperOutputDir);
            builder.AppendSwitchIfNotNull("--sdkRoot ", this.SdkIncRoot);
            if (this.PreflightOnly)
            {
                builder.AppendSwitch("--preflightOnly");
                builder.AppendSwitchIfNotNull("--blockedBy ", this.BlockedBy);
            }

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
            if (this.ToolchainIncludeRoots?.Length > 0)
            {
                string ownership = Path.Combine(this.ScraperOutputDir, "native-constant-header-ownership.json");
                File.WriteAllText(ownership, SerializeHeaderSelection(this.GetNativeHeaderSelection()));
                ret.AppendLine("--nativeHeaderOwnership");
                ret.AppendLine(ownership);
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
            if (this.ToolchainIncludeRoots?.Length > 0 &&
                ((this.ToolchainIncludeRoots.Any(root => !Path.IsPathFullyQualified(root))) ||
                 FileIdentity(Path.Combine(this.ScraperOutputDir, "native-constant-header-ownership.json")) !=
                    TextIdentity(SerializeHeaderSelection(this.GetNativeHeaderSelection()))))
                return false;
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

        private string[] GetSelectionInputs()
        {
            var inputs = new List<string> { "sdkRoot=" + Path.GetFullPath(this.SdkIncRoot) };
            inputs.AddRange((this.HeaderPriority ?? System.Array.Empty<string>()).Select(header => "headerPriority=" + header));
            inputs.AddRange((this.ToolchainIncludeRoots ?? System.Array.Empty<string>()).Select(root => "toolchainIncludeRoot=" + root));
            inputs.AddRange(this.GetOrderedNativeConstantInputs().Select(path => "nativeInput=" + path));
            if (this.ToolchainIncludeRoots?.Length > 0)
            {
                var selection = this.GetNativeHeaderSelection();
                inputs.Add("nativeHeaderOwnership=" + TextIdentity(SerializeHeaderSelection(selection)));
                inputs.AddRange(selection.Inputs.Select(owner => owner.SourceFile).Distinct(System.StringComparer.OrdinalIgnoreCase)
                    .Select(source => "toolchainSource=" + source + "=" + FileIdentity(source)));
                inputs.AddRange(this.GetSelectedToolchainHeaders(selection).Distinct(System.StringComparer.OrdinalIgnoreCase)
                    .Select(header => "toolchainHeader=" + header + "=" + FileIdentity(header)));
            }
            return inputs.ToArray();
        }

        private MetadataUtils.NativeConstantHeaderSelection GetNativeHeaderSelection()
        {
            var inputs = this.GetOrderedNativeConstantInputs().ToHashSet(System.StringComparer.OrdinalIgnoreCase);
            var owners = new List<MetadataUtils.NativeConstantInputOwner>();
            foreach (var partition in this.loadedPartitions)
                foreach (string profile in new[] { "common", "x86", "x64", "arm64" })
                {
                    string input = Path.GetFullPath(Path.Combine(this.ScraperOutputDir, profile, partition.Name + ".native-constants.json"));
                    if (inputs.Contains(input))
                        owners.Add(new MetadataUtils.NativeConstantInputOwner(input,
                            profile switch
                            {
                                "common" or "x86" => MetadataUtils.Architecture.X86,
                                "x64" => MetadataUtils.Architecture.X64,
                                _ => MetadataUtils.Architecture.Arm64,
                            }, partition.FullPath, partition.Namespace, partition.TraverseFiles.ToArray()));
                }
            return new MetadataUtils.NativeConstantHeaderSelection(1, this.ToolchainIncludeRoots, owners.ToArray());
        }

        private IEnumerable<string> GetSelectedToolchainHeaders(MetadataUtils.NativeConstantHeaderSelection selection)
        {
            foreach (string root in selection.IncludeRoots.Where(Path.IsPathFullyQualified))
                foreach (string selector in selection.Inputs.SelectMany(owner => owner.TraversedHeaders))
                {
                    string header;
                    string relative;
                    try
                    {
                        header = Path.GetFullPath(Path.Combine(root, selector));
                        relative = Path.GetRelativePath(root, header);
                    }
                    catch (System.ArgumentException)
                    {
                        continue; // The consumer retains the contextual invalid-selection diagnostic.
                    }
                    if (!Path.IsPathRooted(relative) && relative != ".." &&
                        !relative.StartsWith(".." + Path.DirectorySeparatorChar, System.StringComparison.Ordinal))
                        yield return header;
                }
        }

        private static string SerializeHeaderSelection(MetadataUtils.NativeConstantHeaderSelection selection) =>
            System.Text.Json.JsonSerializer.Serialize(selection, new System.Text.Json.JsonSerializerOptions { WriteIndented = true });

        private static string TextIdentity(string text) => System.Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(text)));

        private static string FileIdentity(string path)
        {
            if (!File.Exists(path))
                return "missing";
            using var stream = File.OpenRead(path);
            return System.Convert.ToHexString(SHA256.HashData(stream));
        }

        private string[] GetOrderedNativeConstantInputs()
        {
            if (this.orderedNativeInputs != null)
                return this.orderedNativeInputs;
            var remaining = this.GetNativeConstantInputs().ToHashSet(System.StringComparer.OrdinalIgnoreCase);
            var ordered = new List<string>();
            foreach (var partition in this.loadedPartitions)
                foreach (string target in new[] { "common", "x86", "x64", "arm64" })
                {
                    string path = Path.GetFullPath(Path.Combine(this.ScraperOutputDir, target, partition.Name + ".native-constants.json"));
                    if (remaining.Remove(path))
                        ordered.Add(path);
                }
            foreach (string path in remaining.OrderBy(path => path, System.StringComparer.OrdinalIgnoreCase))
            {
                this.validation.Add(new InvalidDataException("Native constant input has no project partition-order owner."),
                    "WMC002", "constants.native-input-plan", path, selectedSdkRoot: this.SdkIncRoot,
                    identityCategory: "partition-order-owner");
                ordered.Add(path);
            }
            return this.orderedNativeInputs = ordered.ToArray();
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

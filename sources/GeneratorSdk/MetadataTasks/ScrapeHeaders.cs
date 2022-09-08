//#define MakeSingleThreaded

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class ScrapeHeaders : Task, ICancelableTask
    {
        public const string ClangSharpVersion = "14.0.0-rc1";

        private static readonly string[] allArches = new string[] { "x86", "x64", "arm64" };

        private bool canceled;
        private string[] defaultIncDirs;
        private HashSet<string> partitionSettingsValidSwitches = new HashSet<string>(System.StringComparer.OrdinalIgnoreCase);
        private HashSet<string> partitionsToExcludeFromCrossarch = new HashSet<string>(System.StringComparer.OrdinalIgnoreCase);
        private Dictionary<string, string> suggestedRemaps = new();


        [Required]
        public ITaskItem[] Partitions { get; set; }

        [Required]
        public string HeaderTextFile { get; set; }

        public ITaskItem[] ResponseFiles { get; set; }

        [Required]
        public string WinSdkRoot { get; set; }

        [Required]
        public string ToolsBinDir { get; set; }

        [Required]
        public string MSBuildProjectDirectory { get; set; }

        [Required]
        public string Win32MetadataScraperAssetsDir
        {
            get; set;
        }

        [Required]
        public string ScanArch { get; set; }

        [Required]
        public string GeneratedDir { get; set; }

        [Required]
        public string ScratchDir { get; set; }

        [Required]
        public string SdkIncRoot { get; set; }

        public string AdditionalIncludes { get; set; }

        [Required]
        public string MarkerFileName { get; set; }

        public string MaxProcessors { get; set; }

        public string ExcludeFromCrossarch { get; set; }

        public string PartitionFilter { get; set; }

        [Required]
        public string ScriptsDir { get; set; }

        public override bool Execute()
        {
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_SCRAPER_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            bool needsBuild = !File.Exists(this.MarkerFileName);
            string[] arches = this.ScanArch == "crossarch" ? allArches : new string[] { this.ScanArch };
            var items = this.GetPartitions().Where(p => !p.IsUpToDate(this.MarkerFileName)).SelectMany(p => arches, (p, a) => new { Partition = p, Arch = a });
            needsBuild |= items.Any();
            needsBuild |= !this.AreNonPartitionFilesUpToDate();

            if (!needsBuild)
            {
                return true;
            }

            if (!string.IsNullOrEmpty(this.ExcludeFromCrossarch))
            {
                foreach (var part in this.ExcludeFromCrossarch.Split(';', System.StringSplitOptions.RemoveEmptyEntries))
                {
                    this.partitionsToExcludeFromCrossarch.Add(part);
                }
            }

            this.Log.LogMessage(MessageImportance.High, $"Scraping headers for {this.ScanArch}...");

            if (!this.EnsureClangSharpInstalled())
            {
                return false;
            }

            System.Threading.Tasks.ParallelOptions opt = new System.Threading.Tasks.ParallelOptions();

#if MakeSingleThreaded
            opt.MaxDegreeOfParallelism = 1;
#else
            int throttleCount;
            if (this.MaxProcessors != null && int.TryParse(this.MaxProcessors, out throttleCount))
            {
                if (throttleCount > System.Environment.ProcessorCount)
                {
                    throttleCount = System.Environment.ProcessorCount;
                }
                else if (throttleCount <= 0)
                {
                    throttleCount = -1;
                }
            }
            else
            {
                throttleCount = System.Environment.ProcessorCount / 2;

                if (throttleCount < 2)
                {
                    throttleCount = 2;
                }
            }

            opt.MaxDegreeOfParallelism = throttleCount;
#endif

            this.defaultIncDirs = new string[]
            {
                Path.Combine(this.SdkIncRoot, "shared"),
                Path.Combine(this.SdkIncRoot, "um"),
                Path.Combine(this.SdkIncRoot, "ucrt"),
                Path.Combine(this.SdkIncRoot, "winrt"),
            };

            this.partitionSettingsValidSwitches = new HashSet<string>(new string[] { "--exclude", "--remap", "--with-librarypath", "--with-type", "--with-attribute" });

            bool ret = true;

            System.Threading.Tasks.Parallel.ForEach(items, opt, (item) =>
            {
                if (!this.canceled)
                {
                    ret &= this.ProcessPartition(item.Partition, item.Arch);
                }
            });

            if (this.suggestedRemaps.Count != 0)
            {
                this.Log.LogMessage(MessageImportance.High, "One or more potential remaps were detected. To use them, add these lines to an .rsp with the '--remap' option.");

                foreach (var item in this.suggestedRemaps)
                {
                    this.Log.LogMessage(MessageImportance.High, $"{item.Key}={item.Value}");
                }
            }

            if (ret && string.IsNullOrEmpty(this.PartitionFilter))
            {
                File.WriteAllText(this.MarkerFileName, string.Empty);
            }

            return ret;
        }

        public void Cancel()
        {
            this.canceled = true;
        }

        private bool EnsureClangSharpInstalled()
        {
            string scriptPath = Path.Combine(this.ScriptsDir, "Install-DotNetTool.ps1");
            string scriptArgs = $"-Name ClangSharpPInvokeGenerator -Version {ClangSharpVersion}";
            return TaskUtils.CallPowershellScript(scriptPath, scriptArgs, this.Log, out _);
        }

        private bool AreNonPartitionFilesUpToDate()
        {
            IEnumerable<string> files = TaskUtils.GetFullPaths(this.ResponseFiles, this.MSBuildProjectDirectory);

            return TaskUtils.IsUpToDate(files, this.MarkerFileName);
        }

        private Partition[] GetPartitions()
        {
            List<Partition> ret = new List<Partition>();
            HashSet<string> partitionFilter = null;
            if (!string.IsNullOrEmpty(this.PartitionFilter))
            {
                partitionFilter = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
                foreach (var partName in this.PartitionFilter.Split(new char[] { ',', ';' }, System.StringSplitOptions.RemoveEmptyEntries))
                {
                    partitionFilter.Add(partName);
                }
            }

            foreach (ITaskItem item in this.Partitions)
            {
                Partition partition = Partition.FromTaskItem(item, this.MSBuildProjectDirectory, this.SdkIncRoot);

                if (partitionFilter != null)
                {
                    if (!partitionFilter.Contains(partition.Name))
                    {
                        continue;
                    }

                    // If we were given a filter, force all partitions in the filter to build
                    partition.ForceOutOfDate = true;
                }

                ret.Add(partition);
            }

            return ret.ToArray();
        }

        private bool ProcessPartition(Partition partition, string arch)
        {
            if (partition.IsUpToDate(this.MarkerFileName))
            {
                return true;
            }

            string partitionName = partition.Name;
            string archDirName = arch;

            bool excludeFromCrossarch = this.partitionsToExcludeFromCrossarch.Contains(partitionName) || partition.ExcludeFromCrossarch;
            if (excludeFromCrossarch)
            {
                if (arch == "x64" || arch == "arm64")
                {
                    return true;
                }

                archDirName = "common";
            }

            string infoPrefix = $"{partitionName}:{archDirName}";

            string ns = partition.Namespace;
            string archDir = Path.Combine(this.GeneratedDir, archDirName);
            string outputFileName = Path.Combine(archDir, $"{partitionName}.cs");
            string scratchDir = Path.Combine(this.ScratchDir, archDirName);

            Directory.CreateDirectory(archDir);
            Directory.CreateDirectory(scratchDir);

            if (string.IsNullOrEmpty(ns))
            {
                System.Diagnostics.Debugger.Launch();
            }

            this.Log.LogMessage(MessageImportance.High, $"{infoPrefix} - Scanning to {outputFileName}...");

            string settingsRsp = Path.Combine(scratchDir, $"{partitionName}.settings.rsp");

            if (File.Exists(outputFileName))
            {
                File.Delete(outputFileName);
            }

            var includeDirHash = new HashSet<string>();
            var includeDirs = new List<string>();

            if (this.AdditionalIncludes != null)
            {
                string[] dirs = this.AdditionalIncludes.Split(';', System.StringSplitOptions.RemoveEmptyEntries);
                foreach (var dir in dirs)
                {
                    if (!includeDirHash.Contains(dir))
                    {
                        includeDirHash.Add(dir);
                        includeDirs.Add(dir);
                    }
                }
            }

            var traverseFiles = partition.TraverseFiles;
            foreach (var traverseFile in partition.TraverseFiles)
            {
                string dir = Path.GetDirectoryName(traverseFile);
                if (!includeDirHash.Contains(dir) && !this.defaultIncDirs.Contains(dir))
                {
                    includeDirHash.Add(dir);
                    includeDirs.Add(dir);
                }
            }

            foreach (var dir in this.defaultIncDirs)
            {
                includeDirs.Add(dir);
            }

            string sourceFile = partition.FullPath;

            using (var rspWriter = new StreamWriter(settingsRsp))
            {
                rspWriter.WriteLine(
$@"--file
{sourceFile}
--output
{outputFileName}
--namespace
{ns}
--headerFile
{this.HeaderTextFile}
--include-directory");

                foreach (var include in includeDirs)
                {
                    rspWriter.WriteLine(include);
                }

                rspWriter.WriteLine("--traverse");

                foreach (var traverseFile in traverseFiles)
                {
                    rspWriter.WriteLine(traverseFile);
                }

                var settingsFile = partition.SettingsFile;

                if (settingsFile != null)
                {
                    TaskUtils.FilterRspFile(settingsFile, rspWriter, this.partitionSettingsValidSwitches);
                }

                var exclusions = this.GetExclusions(partition.TaskItem);
                if (exclusions.Any())
                {
                    rspWriter.WriteLine("--exclude");
                    foreach (var exclude in exclusions)
                    {
                        rspWriter.WriteLine(exclude);
                    }
                }

                var remaps = this.GetRemaps(partition.TaskItem);
                if (remaps.Any())
                {
                    rspWriter.WriteLine("--remap");
                    foreach (var remap in remaps)
                    {
                        rspWriter.WriteLine(remap);
                    }
                }
            }

            string currentScraperOutputDir = scratchDir;
            Directory.CreateDirectory(currentScraperOutputDir);

            string scrapeToolOutput = Path.Combine(currentScraperOutputDir, $"{partitionName}.generation.output.txt");
            var args = new CommandLineBuilder();
            args.AppendRspFile(settingsRsp);
            foreach (var rspFileName in TaskUtils.GetFullPaths(this.ResponseFiles, this.MSBuildProjectDirectory))
            {
                if (rspFileName.EndsWith("ConstantsScraper.rsp"))
                {
                    continue;
                }

                if (arch == "x86" && (rspFileName.EndsWith(".64.rsp") || rspFileName.EndsWith(".x64.rsp") || rspFileName.EndsWith(".arm64.rsp")))
                {
                    continue;
                }

                if (arch == "x64" && (rspFileName.EndsWith(".32.rsp") || rspFileName.EndsWith(".x86.rsp") || rspFileName.EndsWith(".arm64.rsp")))
                {
                    continue;
                }

                if (arch == "arm64" && (rspFileName.EndsWith(".32.rsp") || rspFileName.EndsWith(".x86.rsp") || rspFileName.EndsWith(".x64.rsp")))
                {
                    continue;
                }

                if (File.Exists(rspFileName))
                {
                    System.Diagnostics.Debug.WriteLine($"Adding {rspFileName}...");

                    args.AppendRspFile(rspFileName);
                }
                else
                {
                    System.Diagnostics.Debug.WriteLine($"Skipped {rspFileName}, didn't exist...");
                }
            }

            int exitCode = TaskUtils.ExecuteCmd("ClangSharpPInvokeGenerator", args.ToString(), out var output, this.Log);
            if (output == null)
            {
                output = string.Empty;
            }

            File.WriteAllText(scrapeToolOutput, output);

            Regex duplicateKeyRegex = new Regex(@"A key with the given name already exists: (\S+)\.");
            Regex errorRegex = new Regex(@"(?:\s*Error: (.*)|(?:\s*(.+ error: .+|Error \(.+\).*)))");
            Regex potentialRemapRegex = new Regex(@"\s*Info: Potential remap: (.+)");

            char[] lineChars = new char[] { '\r', '\n' };

            if (exitCode < 0 || !File.Exists(outputFileName))
            {
                this.Log.LogError($"{infoPrefix} - ClangSharpPInvokeGenerator failed. Full output at {scrapeToolOutput}.");

                foreach (var line in output.Split(lineChars, System.StringSplitOptions.RemoveEmptyEntries))
                {
                    var errorMatch = errorRegex.Match(line);
                    if (errorMatch.Success)
                    {
                        if (errorMatch.Groups[1].Success)
                        {
                            var errorDetails = errorMatch.Groups[1].Value;
                            var duplicateMatch = duplicateKeyRegex.Match(errorDetails);
                            if (duplicateMatch.Success)
                            {
                                var dupeName = duplicateMatch.Groups[1].Value;
                                errorDetails = $"A duplicate rsp entry was found using the name '{dupeName}'. Make sure there is only one entry per name.";
                            }

                            this.Log.LogError($"{infoPrefix} - {errorDetails}");
                        }
                        else
                        {
                            this.Log.LogError($"{infoPrefix} - {errorMatch.Groups[2].Value}");
                        }
                    }
                }

                return false;
            }
            else
            {
                foreach (var line in output.Split(lineChars, System.StringSplitOptions.RemoveEmptyEntries))
                {
                    var remapMatch = potentialRemapRegex.Match(line);
                    if (remapMatch.Success)
                    {
                        string[] parts = remapMatch.Groups[1].Value.Split('=');
                        lock (this.suggestedRemaps)
                        {
                            this.suggestedRemaps[parts[0]] = parts[1];
                        }
                    }
                }
            }

            return true;
        }

        private string[] GetExclusions(ITaskItem item)
        {
            return item.GetMetadata("Exclude").Split(';', System.StringSplitOptions.RemoveEmptyEntries);
        }

        private string[] GetRemaps(ITaskItem item)
        {
            return item.GetMetadata("Remap").Split(';', System.StringSplitOptions.RemoveEmptyEntries);
        }

        private string[] GetFilesFromMetadata(ITaskItem item, string name)
        {
            string[] items = item.GetMetadata(name).Split(';', System.StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < items.Length; i++)
            {
                if (!Path.IsPathRooted(items[i]))
                {
                    items[i] = Path.Combine(this.MSBuildProjectDirectory, items[i]);
                }
            }

            return items;
        }
    }
}

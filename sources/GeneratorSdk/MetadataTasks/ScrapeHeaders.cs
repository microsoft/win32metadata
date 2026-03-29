//#define MakeSingleThreaded

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class ScrapeHeaders : Task, ICancelableTask
    {
        public const string ClangSharpVersion = "17.0.1";

        private static readonly string[] allArches = new string[] { "x86", "x64", "arm64" };

        private bool canceled;
        private string clangSharpToolPath;
        private string clangSharpToolDir;
        private string clangSharpWorkerPath;
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

        public string NuGetPackageSource { get; set; }

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
                throttleCount = System.Environment.ProcessorCount;
            }

            opt.MaxDegreeOfParallelism = throttleCount;
#endif

            this.Log.LogMessage(MessageImportance.High, $"Scraping with MaxDegreeOfParallelism = {opt.MaxDegreeOfParallelism} (ProcessorCount = {System.Environment.ProcessorCount})");

            this.defaultIncDirs = new string[]
            {
                Path.Combine(this.SdkIncRoot, "shared"),
                Path.Combine(this.SdkIncRoot, "um"),
                Path.Combine(this.SdkIncRoot, "ucrt"),
                Path.Combine(this.SdkIncRoot, "winrt"),
            };

            this.partitionSettingsValidSwitches = new HashSet<string>(new string[] { "--exclude", "--remap", "--with-librarypath", "--with-type", "--with-attribute", "--config" });

            int failureCount = 0;

            System.Threading.Tasks.Parallel.ForEach(items, opt, (item) =>
            {
                if (!this.canceled)
                {
                    if (!this.ProcessPartition(item.Partition, item.Arch))
                    {
                        System.Threading.Interlocked.Increment(ref failureCount);
                    }
                }
            });

            bool ret = failureCount == 0;

            if (this.suggestedRemaps.Count != 0)
            {
                if (string.IsNullOrEmpty(this.PartitionFilter))
                {
                    this.WriteAutoRemapsCsFile();
                }
                else
                {
                    this.Log.LogMessage(MessageImportance.High,
                        $"{this.suggestedRemaps.Count} potential remaps discovered (not written — partition filter active)");
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
            // Restore ClangSharp as a local tool with the pinned version, so we are
            // not affected by whatever version is installed globally on the machine.
            // A tool manifest is generated in the scratch directory so this works both
            // in-repo and when the GeneratorSdk is consumed as a NuGet MSBuild SDK.
            string toolManifestDir = Path.Combine(this.ScratchDir, ".config");
            string toolManifest = Path.Combine(toolManifestDir, "dotnet-tools.json");

            Directory.CreateDirectory(toolManifestDir);
            File.WriteAllText(toolManifest,
$@"{{
  ""version"": 1,
  ""isRoot"": true,
  ""tools"": {{
    ""clangsharppinvokegenerator"": {{
      ""version"": ""{ClangSharpVersion}"",
      ""commands"": [""ClangSharpPInvokeGenerator""]
    }}
  }}
}}");

            int exitCode = TaskUtils.ExecuteCmd("dotnet", $"tool restore --tool-manifest \"{toolManifest}\"", out var output, this.Log);
            if (exitCode != 0)
            {
                this.Log.LogError($"Failed to restore ClangSharpPInvokeGenerator {ClangSharpVersion}. Exit code: {exitCode}. Output: {output}");
                return false;
            }

            // Resolve the tool DLL path so we can invoke it directly via 'dotnet <dll>'
            // instead of 'dotnet tool run' which has per-invocation overhead.
            string userProfile = Environment.GetFolderPath(Environment.SpecialFolder.UserProfile);
            string storeRoot = Path.Combine(userProfile, ".dotnet", "tools", ".store", "clangsharppinvokegenerator");
            if (Directory.Exists(storeRoot))
            {
                var found = Directory.GetFiles(storeRoot, "ClangSharpPInvokeGenerator.dll", SearchOption.AllDirectories);
                if (found.Length > 0)
                {
                    this.clangSharpToolPath = found[0];
                }
            }

            if (this.clangSharpToolPath != null)
            {
                this.clangSharpToolDir = Path.GetDirectoryName(this.clangSharpToolPath);
                this.Log.LogMessage(MessageImportance.High, $"Using ClangSharp {ClangSharpVersion} from {this.clangSharpToolPath}");
            }
            else
            {
                this.Log.LogError($"Could not resolve ClangSharpPInvokeGenerator.dll in tool store under {storeRoot}");
                return false;
            }

            // Resolve ClangSharpWorker — a process-isolated wrapper that runs
            // PInvokeGenerator as a library and extracts typedef-tag remaps
            this.clangSharpWorkerPath = Path.Combine(this.ToolsBinDir, "ClangSharpWorker.dll");
            if (!File.Exists(this.clangSharpWorkerPath))
            {
                this.Log.LogError($"ClangSharpWorker.dll not found at {this.clangSharpWorkerPath}. Build the ClangSharpWorker project first.");
                return false;
            }

            this.Log.LogMessage(MessageImportance.High, $"Using ClangSharpWorker from {this.clangSharpWorkerPath}");

            return true;
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

            string output;
            int exitCode;
            string remapsFile = Path.Combine(scratchDir, $"{partitionName}.remaps");

            // Use ClangSharpWorker: runs PInvokeGenerator as a library in its own
            // process and writes a .remaps sidecar with discovered typedef-tag remaps
            exitCode = TaskUtils.ExecuteCmd("dotnet",
                $"\"{this.clangSharpWorkerPath}\" \"{this.clangSharpToolDir}\" \"{remapsFile}\" {args}",
                out output, this.Log);
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
                        string remapValue = remapMatch.Groups[1].Value;
                        int eq = remapValue.IndexOf('=');
                        if (eq > 0)
                        {
                            lock (this.suggestedRemaps)
                            {
                                this.suggestedRemaps[remapValue.Substring(0, eq)] = remapValue.Substring(eq + 1);
                            }
                        }
                    }
                }

                // Read typedef-tag remaps from the worker's .remaps sidecar file
                if (File.Exists(remapsFile))
                {
                    lock (this.suggestedRemaps)
                    {
                        foreach (var line in File.ReadLines(remapsFile))
                        {
                            int eq = line.IndexOf('=');
                            if (eq > 0)
                            {
                                string key = line.Substring(0, eq);
                                if (!this.suggestedRemaps.ContainsKey(key))
                                    this.suggestedRemaps[key] = line.Substring(eq + 1);
                            }
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

        #region Auto Remap Discovery

        /// <summary>
        /// Writes auto-discovered typedef-tag remaps to a generated C# file.
        /// The ClangSharpWorker subprocess extracts these from PInvokeGenerator's
        /// _allValidNameRemappings field after GenerateBindings completes.
        /// ClangSharpSourceToWinmd reads this file and applies the renames during
        /// syntax tree cleaning, so the final winmd has correct type names.
        /// </summary>
        private void WriteAutoRemapsCsFile()
        {
            string autoRemapsCsPath = Path.Combine(this.GeneratedDir, "AutoRemaps.generated.cs");

            Directory.CreateDirectory(Path.GetDirectoryName(autoRemapsCsPath));
            using (var writer = new StreamWriter(autoRemapsCsPath))
            {
                writer.WriteLine("// <auto-generated/>");
                writer.WriteLine("// Typedef-tag remappings discovered by ClangSharpWorker from the libclang AST.");
                writer.WriteLine("// Each entry maps a C/C++ tag name to its public typedef name.");
                writer.WriteLine("// ClangSharpSourceToWinmd reads this data and renames types during syntax tree cleaning.");
                writer.WriteLine();
                writer.WriteLine("namespace AutoRemaps");
                writer.WriteLine("{");
                writer.WriteLine("    internal static class DiscoveredRemaps");
                writer.WriteLine("    {");
                writer.WriteLine("        internal static readonly string[] Entries = new[]");
                writer.WriteLine("        {");

                foreach (var kv in this.suggestedRemaps.OrderBy(kv => kv.Key, StringComparer.OrdinalIgnoreCase))
                {
                    // Escape any quotes in names (shouldn't happen but be safe)
                    string key = kv.Key.Replace("\"", "\\\"");
                    string val = kv.Value.Replace("\"", "\\\"");
                    writer.WriteLine($"            \"{key}={val}\",");
                }

                writer.WriteLine("        };");
                writer.WriteLine("    }");
                writer.WriteLine("}");
            }

            this.Log.LogMessage(MessageImportance.High,
                $"Auto-remaps: wrote {this.suggestedRemaps.Count} entries to {Path.GetFileName(autoRemapsCsPath)}");
        }

        #endregion

    }
}

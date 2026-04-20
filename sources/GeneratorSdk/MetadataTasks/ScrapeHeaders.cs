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
        public const string ClangSharpVersion = "17.0.1";

        private static readonly string[] allArches = new string[] { "x86", "x64", "arm64" };

        private bool canceled;
        private string win32MetadataScraperPath;
        private string[] defaultIncDirs;
        private HashSet<string> partitionSettingsValidSwitches = new HashSet<string>(System.StringComparer.OrdinalIgnoreCase);
        private HashSet<string> partitionsToExcludeFromCrossarch = new HashSet<string>(System.StringComparer.OrdinalIgnoreCase);
        private Dictionary<string, string> suggestedRemaps = new();
        private Dictionary<string, string> discoveredRemaps = new();
        private Dictionary<string, string> discoveredRemapHeaders = new(); // tag → header file path
        private HashSet<string> discoveredFnPtrExcludes = new();
        private HashSet<string> discoveredReducePointerLevel = new();
        // Per-partition: which tag remaps each partition discovered from its own AST
        private Dictionary<string, Dictionary<string, string>> perPartitionRemaps = new();


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

            this.partitionSettingsValidSwitches = new HashSet<string>(new string[] { "--exclude", "--exclude-auto-remap", "--remap", "--with-librarypath", "--with-type", "--with-attribute", "--config" });

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
                this.Log.LogMessage(MessageImportance.High, "One or more potential remaps were detected. To use them, add these lines to an .rsp with the '--remap' option.");

                foreach (var item in this.suggestedRemaps)
                {
                    this.Log.LogMessage(MessageImportance.High, $"{item.Key}={item.Value}");
                }
            }

            // Write auto-discovered remaps to generated RSP
            if (ret)
            {
                this.WriteAutoRemapsRsp();
                this.CheckCrossPartitionRemapConsistency();
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
            string rid = System.Runtime.InteropServices.RuntimeInformation.RuntimeIdentifier;
            string[] candidatePaths =
            {
                Path.Combine(this.ToolsBinDir, rid, "Win32MetadataScraper.dll"),
                Path.Combine(this.ToolsBinDir, "Win32MetadataScraper.dll"),
            };

            this.win32MetadataScraperPath = candidatePaths.FirstOrDefault(File.Exists);
            if (this.win32MetadataScraperPath is null)
            {
                this.Log.LogError($"Win32MetadataScraper not found. Checked: {string.Join(", ", candidatePaths)}");
                return false;
            }

            this.Log.LogMessage(MessageImportance.High, $"Using Win32MetadataScraper from {this.win32MetadataScraperPath}");
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
            string remapsFile = Path.Combine(currentScraperOutputDir, $"{partitionName}.remaps");

            // Use Win32MetadataScraper — hosts PInvokeGenerator as a library,
            // walks the AST to discover remaps, and generates output in a single pass
            string scraperArgs = $"\"{this.win32MetadataScraperPath}\" \"{remapsFile}\" {args}";
            exitCode = TaskUtils.ExecuteCmd("dotnet", scraperArgs, out output, this.Log);
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

                // Read discovered remaps from sidecar file (written by Win32MetadataScraper)
                if (File.Exists(remapsFile))
                {
                    foreach (var line in File.ReadLines(remapsFile))
                    {
                        string trimmed = line.Trim();
                        if (string.IsNullOrEmpty(trimmed)) continue;

                        if (trimmed.StartsWith("FNPTR_EXCLUDE:"))
                        {
                            string exclude = trimmed.Substring("FNPTR_EXCLUDE:".Length);

                            lock (this.discoveredFnPtrExcludes)
                            {
                                this.discoveredFnPtrExcludes.Add(exclude);
                            }
                        }
                        else if (trimmed.StartsWith("REDUCE_PTR_LEVEL:"))
                        {
                            string reducePointerLevel = trimmed.Substring("REDUCE_PTR_LEVEL:".Length);

                            lock (this.discoveredReducePointerLevel)
                            {
                                this.discoveredReducePointerLevel.Add(reducePointerLevel);
                            }
                        }
                        else
                        {
                            int eq = trimmed.IndexOf('=');
                            if (eq > 0)
                            {
                                string key = trimmed.Substring(0, eq);
                                string rest = trimmed.Substring(eq + 1);

                                // Parse optional header info: value|HEADER:path
                                string value = rest;
                                string headerFile = null;
                                int headerMarker = rest.IndexOf("|HEADER:");
                                if (headerMarker >= 0)
                                {
                                    value = rest.Substring(0, headerMarker);
                                    headerFile = rest.Substring(headerMarker + "|HEADER:".Length);
                                }

                                lock (this.discoveredRemaps)
                                {
                                    if (!this.discoveredRemaps.ContainsKey(key))
                                    {
                                        this.discoveredRemaps[key] = value;
                                        if (headerFile != null)
                                            this.discoveredRemapHeaders[key] = headerFile;
                                    }
                                }

                                // Track per-partition for consistency checking
                                lock (this.perPartitionRemaps)
                                {
                                    if (!this.perPartitionRemaps.TryGetValue(partitionName, out var partRemaps))
                                    {
                                        this.perPartitionRemaps[partitionName] = partRemaps = new Dictionary<string, string>();
                                    }
                                    partRemaps[key] = value;
                                }
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

        /// <summary>
        /// Writes the auto-discovered remaps and function pointer fixups to generated RSP files.
        /// </summary>
        private void WriteAutoRemapsRsp()
        {
            Directory.CreateDirectory(this.GeneratedDir);

            if (this.discoveredRemaps.Count > 0 || this.discoveredFnPtrExcludes.Count > 0)
            {
                string autoRemapsRsp = Path.Combine(this.GeneratedDir, "scraper.autoRemaps.generated.rsp");

                using (var writer = new StreamWriter(autoRemapsRsp))
                {
                    if (this.discoveredFnPtrExcludes.Count > 0)
                    {
                        writer.WriteLine("--exclude");
                        foreach (var excl in this.discoveredFnPtrExcludes.OrderBy(x => x, StringComparer.OrdinalIgnoreCase))
                        {
                            writer.WriteLine(excl);
                        }
                    }

                    if (this.discoveredRemaps.Count > 0)
                    {
                        writer.WriteLine("--remap");
                        foreach (var kv in this.discoveredRemaps.OrderBy(kv => kv.Key, StringComparer.OrdinalIgnoreCase))
                        {
                            writer.WriteLine($"{kv.Key}={kv.Value}");
                        }
                    }
                }

                this.Log.LogMessage(MessageImportance.High, $"Wrote {this.discoveredRemaps.Count} auto-remaps and {this.discoveredFnPtrExcludes.Count} fn-ptr excludes to {autoRemapsRsp}");
            }

            if (this.discoveredReducePointerLevel.Count > 0)
            {
                string autoEmitterRsp = Path.Combine(this.GeneratedDir, $"emitter.autoFnPtr.{this.ScanArch}.generated.rsp");

                using (var writer = new StreamWriter(autoEmitterRsp))
                {
                    writer.WriteLine("--reducePointerLevel");
                    foreach (var rpl in this.discoveredReducePointerLevel.OrderBy(x => x, StringComparer.OrdinalIgnoreCase))
                    {
                        writer.WriteLine(rpl);
                    }
                }

                this.Log.LogMessage(MessageImportance.High, $"Wrote {this.discoveredReducePointerLevel.Count} reduce-pointer-level entries to {autoEmitterRsp}");
            }
        }

        /// <summary>
        /// Checks for cross-partition remap inconsistencies. After all partitions are
        /// scraped, collects the set of type names declared in the generated C# files.
        /// If any declared type name matches a tag that was remapped in another partition,
        /// it means this partition didn't discover the remap and used the raw tag name.
        /// </summary>
        private void CheckCrossPartitionRemapConsistency()
        {
            if (this.discoveredRemaps.Count == 0)
            {
                return;
            }

            // Collect all declared type names from all generated .cs files.
            // Pattern: "partial struct FOO" / "enum FOO" / "delegate ... FOO("
            var declaredTypeNames = new HashSet<string>(StringComparer.Ordinal);
            string[] archDirs = new string[] { "common", "x86", "x64", "arm64" };
            var typeNameToFile = new Dictionary<string, string>();

            foreach (string archDir in archDirs)
            {
                string dir = Path.Combine(this.GeneratedDir, archDir);
                if (!Directory.Exists(dir)) continue;

                foreach (string csFile in Directory.GetFiles(dir, "*.cs"))
                {
                    foreach (var line in File.ReadLines(csFile))
                    {
                        // Match: public partial struct FOO / public enum FOO / public delegate ... FOO(
                        string trimmed = line.TrimStart();
                        if (trimmed.StartsWith("public "))
                        {
                            // Extract the type name after struct/enum/delegate keywords
                            string typeName = null;
                            int idx;
                            if ((idx = trimmed.IndexOf(" struct ")) >= 0)
                                typeName = ExtractIdentifier(trimmed, idx + 8);
                            else if ((idx = trimmed.IndexOf(" enum ")) >= 0)
                                typeName = ExtractIdentifier(trimmed, idx + 6);
                            else if ((idx = trimmed.IndexOf(" interface ")) >= 0)
                                typeName = ExtractIdentifier(trimmed, idx + 11);

                            if (typeName != null)
                            {
                                declaredTypeNames.Add(typeName);
                                if (!typeNameToFile.ContainsKey(typeName))
                                {
                                    string partName = Path.GetFileNameWithoutExtension(csFile);
                                    typeNameToFile[typeName] = $"{partName} ({archDir})";
                                }
                            }
                        }
                    }
                }
            }

            // Check: does any declared type name match a remap TAG?
            // If so, that type was declared with its raw tag name instead of the typedef.
            bool consistent = true;
            foreach (var kv in this.discoveredRemaps)
            {
                string tagName = kv.Key;
                string typedefName = kv.Value;

                if (declaredTypeNames.Contains(tagName))
                {
                    // Find which partition discovered this remap
                    string definingPartition = null;
                    foreach (var pp in this.perPartitionRemaps)
                    {
                        if (pp.Value.ContainsKey(tagName))
                        {
                            definingPartition = pp.Key;
                            break;
                        }
                    }

                    typeNameToFile.TryGetValue(tagName, out string location);
                    this.discoveredRemapHeaders.TryGetValue(tagName, out string headerFile);
                    string headerHint = headerFile != null
                        ? $" Add '#include \"{Path.GetFileName(headerFile)}\"' to that partition's main.cpp."
                        : "";

                    this.Log.LogWarning(
                        $"Inconsistent remap: type '{tagName}' is declared in {location} but should be " +
                        $"'{typedefName}' (remap discovered in partition '{definingPartition}').{headerHint}");
                    consistent = false;
                }
            }

            if (!consistent)
            {
                this.Log.LogWarning(
                    "Cross-partition remap inconsistencies detected. See warnings above. " +
                    "Fix by adding the missing #include directives to the affected partition's main.cpp " +
                    "so the typedef is visible during scraping.");
            }
        }

        /// <summary>
        /// Extracts a C# identifier starting at the given position in a line.
        /// </summary>
        private static string ExtractIdentifier(string line, int startIndex)
        {
            if (startIndex >= line.Length) return null;
            int end = startIndex;
            while (end < line.Length && (char.IsLetterOrDigit(line[end]) || line[end] == '_'))
                end++;
            return end > startIndex ? line.Substring(startIndex, end - startIndex) : null;
        }

    }
}

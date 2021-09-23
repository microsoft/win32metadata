//#define MakeSingleThreaded

using System.Collections.Generic;
using System.IO;
using System.Linq;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class ScrapeHeaders : Task, ICancelableTask
    {
        private bool canceled;
        private string[] defaultIncDirs;
        private HashSet<string> partitionSettingsValidSwitches = new HashSet<string>(System.StringComparer.OrdinalIgnoreCase);

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

        public override bool Execute()
        {
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_SCRAPER_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            bool needsBuild = !File.Exists(this.MarkerFileName);
            string[] arches = this.ScanArch == "crossarch" ? new string[] { "x64", "x86", "arm64" } : new string[] { this.ScanArch };
            var items = this.GetPartitionItems().Where(p => !p.IsUpToDate(this.MarkerFileName)).SelectMany(p => arches, (p, a) => new { Partition = p, Arch = a });
            needsBuild |= items.Any();
            needsBuild |= !this.AreNonPartitionFilesUpToDate();

            if (!needsBuild)
            {
                return true;
            }

            if (File.Exists(this.MarkerFileName))
            {
                File.Delete(this.MarkerFileName);
            }

            this.Log.LogMessage(MessageImportance.High, $"Scraping headers for {this.ScanArch}...");


            System.Threading.Tasks.ParallelOptions opt = new System.Threading.Tasks.ParallelOptions();

#if MakeSingleThreaded
            opt.MaxDegreeOfParallelism = 1;
#else
            int throttleCount;
            if (this.MaxProcessors != null)
            {
                int.TryParse(this.MaxProcessors, out throttleCount);
                if (throttleCount > System.Environment.ProcessorCount)
                {
                    throttleCount = System.Environment.ProcessorCount;
                }
                else if (throttleCount < 0)
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

            if (ret)
            {
                File.WriteAllText(this.MarkerFileName, string.Empty);
            }

            return ret;
        }

        public void Cancel()
        {
            this.canceled = true;
        }

        private bool AreNonPartitionFilesUpToDate()
        {
            IEnumerable<string> files = TaskUtils.GetFullPaths(this.ResponseFiles, this.MSBuildProjectDirectory);

            return TaskUtils.IsUpToDate(files, this.MarkerFileName);
        }

        private Partition[] GetPartitionItems()
        {
            List<Partition> ret = new List<Partition>();
            foreach (ITaskItem item in this.Partitions)
            {
                ret.Add(Partition.FromTaskItem(item, this.MSBuildProjectDirectory, this.SdkIncRoot));
            }

            return ret.ToArray();
        }

        private bool ProcessPartition(Partition partition, string arch)
        {
            if (partition.IsUpToDate(this.MarkerFileName))
            {
                return true;
            }

            string ns = partition.Namespace;
            string partitionName = partition.Name;
            string archDir = Path.Combine(this.GeneratedDir, arch);
            string outputFileName = Path.Combine(archDir, $"{partitionName}.cs");
            string scratchDir = Path.Combine(this.ScratchDir, arch);
            Directory.CreateDirectory(scratchDir);

            if (string.IsNullOrEmpty(ns))
            {
                System.Diagnostics.Debugger.Launch();
            }

            this.Log.LogMessage(MessageImportance.High, $"Scanning to {outputFileName}...");

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
                    //System.Diagnostics.Debug.WriteLine(File.ReadAllText(rspFileName));

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

            if (exitCode < 0 || !File.Exists(outputFileName))
            {
                this.Log.LogError($"ClangSharpPInvokeGenerator.exe failed for {outputFileName} - {arch}, full output at {scrapeToolOutput}.");
                return false;
                // TODO: Output errors
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

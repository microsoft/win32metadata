using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class ScrapeHeaders : Task
    {
        private string winSdkIncludeRoot;
        private string objDir;
        private string generatedDir;
        private string generationDir;
        private string scraperDir;
        private string emitterDir;
        private string partitionsDir;

        [Required]
        public ITaskItem[] Partitions
        {
            get;
            set;
        }

        public ITaskItem[] Rsps
        {
            get;
            set;
        }

        [Required]
        public string WinSdkRoot
        {
            get;set;
        }

        [Required]
        public string ToolsBinDir
        {
            get; set;
        }

        [Required]
        public string MSBuildProjectDirectory
        {
            get; set;
        }

        [Required]
        public string Win32MetadataScraperAssetsDir
        {
            get; set;
        }

        [Required]
        public string Win32MetadataScraperGeneratedAssetsDir
        {
            get; set;
        }

        [Output]
        public string GeneratedSourceDir { get; set; }

        public override bool Execute()
        {
            this.InitDirs();

            bool ret = true;
            foreach (var partitionItem in this.Partitions)
            {
                ret &= this.ProcessPartitionItem(partitionItem);
            }

            if (ret)
            {
                ret = ScrapeConstants();
            }

            return ret;
        }

        private void InitDirs()
        {
            this.objDir = Path.Combine(this.MSBuildProjectDirectory, "obj");
            Directory.CreateDirectory(this.objDir);

            this.generationDir = Path.Combine(this.objDir, "generation");
            this.scraperDir = Path.Combine(this.generationDir, "scraper");
            this.partitionsDir = Path.Combine(this.scraperDir, "Partitions");

            this.emitterDir = Path.Combine(this.generationDir, "emitter");
            
            // Output parameter for the emitter
            this.GeneratedSourceDir = this.emitterDir;

            this.generatedDir = Path.Combine(this.emitterDir, "generated");

            if (!Directory.Exists(this.partitionsDir))
            {
                Directory.CreateDirectory(this.partitionsDir);
            }

            if (!Directory.Exists(this.generatedDir))
            {
                Directory.CreateDirectory(this.generatedDir);
            }
        }

        private string WinSDKIncludeRoot
        {
            get
            {
                if (this.winSdkIncludeRoot == null)
                {
                    string baseDir = Path.Combine(this.WinSdkRoot, "include");
                    this.winSdkIncludeRoot = Directory.GetDirectories(baseDir)[0];
                }

                return this.winSdkIncludeRoot;
            }
        }

        private void AddWin32GeneratedRsp(StringBuilder args, string name)
        {
            if (args.Length != 0)
            {
                args.Append(' ');
            }

            string path = Path.Combine(this.Win32MetadataScraperGeneratedAssetsDir, name);
            args.Append($"\"@{path}\"");
        }

        private void AddWin32Rsp(StringBuilder args, string name)
        {
            if (args.Length != 0)
            {
                args.Append(' ');
            }

            string path = Path.Combine(this.Win32MetadataScraperAssetsDir, name);
            args.Append($"\"@{path}\"");
        }

        private bool ScrapeConstants()
        {
            Log.LogMessage($"Scraping constants...");

            string constantsScraperDll = Path.Combine(this.ToolsBinDir, "ConstantsScraper.dll");
            string constantsHeaderTxt = Path.Combine(this.Win32MetadataScraperAssetsDir, "ConstantsHeader.txt");
            var args = new StringBuilder($"{constantsScraperDll} --repoRoot {this.objDir} --arch x64 --headerTextFile {constantsHeaderTxt}");
            int exitCode = TaskUtils.ExecuteCmd("dotnet", args.ToString(), out var output, this.Log);
            if (exitCode < 0)
            {
                Log.LogError($"ConstantsScraper.dll failed: {output}");
                return false;
            }

            return true;
        }

        private bool ProcessPartitionItem(ITaskItem partitionItem)
        {
            // TODO: Do we want to do this for all architectures?
            string arch = "x64";

            string[] traverseFiles = GetTraverseFiles(partitionItem);

            string ns = partitionItem.GetMetadata("Namespace");
            string name = partitionItem.GetMetadata("Name");

            if (string.IsNullOrEmpty(name))
            {
                name = ns.Split('.').Last();
            }

            Log.LogMessage($"Scanning partition {name}...");

            string partitionDir = Path.Combine(this.partitionsDir, name);
            if (!Directory.Exists(partitionDir))
            {
                Directory.CreateDirectory(partitionDir);
            }

            string file = partitionItem.ItemSpec;
            string settingsRsp = Path.Combine(partitionDir, "settings.rsp");

            string currentGeneratedDir = Path.Combine(this.generatedDir, arch);
            if (!Directory.Exists(currentGeneratedDir))
            {
                Directory.CreateDirectory(currentGeneratedDir);
            }

            string outputFile = Path.Combine(currentGeneratedDir, $"{name}.cs");
            if (File.Exists(outputFile))
            {
                File.Delete(outputFile);
            }

            HashSet<string> includeDirHash = new HashSet<string>();
            List<string> includeDirs = new List<string>();
            
            // For sal.h, etc.
            includeDirs.Add(this.Win32MetadataScraperAssetsDir);

            foreach (var traverseFile in traverseFiles)
            {
                string dir = Path.GetDirectoryName(traverseFile);
                if (!includeDirHash.Contains(dir))
                {
                    includeDirHash.Add(dir);
                    includeDirs.Add(dir);
                }
            }

            includeDirs.Add($"{this.WinSDKIncludeRoot}/shared");
            includeDirs.Add($"{this.WinSDKIncludeRoot}/um");
            includeDirs.Add($"{this.WinSDKIncludeRoot}/winrt");

            string headerTextFile = Path.Combine(this.Win32MetadataScraperAssetsDir, "header.txt");

            using (StreamWriter rspWriter = new StreamWriter(settingsRsp))
            {
                rspWriter.WriteLine(
$@"--file
{file}
--output
{outputFile}
--namespace
{ns}
--headerFile
{headerTextFile}
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

                var exclusions = this.GetExclusions(partitionItem);
                if (exclusions.Any())
                {
                    rspWriter.WriteLine("--exclude");
                    foreach (var exclude in exclusions)
                    {
                        rspWriter.WriteLine(exclude);
                    }
                }
            }

            string currentScraperOutputDir = Path.Combine(this.scraperDir, $"obj\\{arch}");
            if (!Directory.Exists(currentScraperOutputDir))
            {
                Directory.CreateDirectory(currentScraperOutputDir);
            }

            string scrapeToolOutput = Path.Combine(currentScraperOutputDir, $"{name}.generation.output.txt");
            StringBuilder args = new StringBuilder($"\"@{settingsRsp}\"");
            AddWin32Rsp(args, "baseRemap.rsp");
            AddWin32Rsp(args, "baseSettings.64.rsp");
            AddWin32Rsp(args, "baseSettings.rsp");
            AddWin32GeneratedRsp(args, "autoTypes.generated.rsp");
            AddWin32GeneratedRsp(args, "functionPointerFixups.generated.rsp");

            foreach (var rspItem in this.Rsps)
            {
                var rspPath = rspItem.ItemSpec;
                if (!Path.IsPathRooted(rspPath))
                {
                    rspPath = Path.Combine(this.MSBuildProjectDirectory, rspPath);
                }

                args.Append($" \"@{rspPath}\"");
            }

            int exitCode = TaskUtils.ExecuteCmd("ClangSharpPInvokeGenerator", args.ToString(), out var output, this.Log);
            if (output == null)
            {
                output = string.Empty;
            }

            File.WriteAllText(scrapeToolOutput, output);

            if (exitCode < 0 || !File.Exists(outputFile))
            {
                Log.LogError($"ClangSharpPInvokeGenerator.exe failed, full output at {scrapeToolOutput}.");
                return false;
                // TODO: Output errors
            }

            return true;
        }

        private string[] GetExclusions(ITaskItem item)
        {
            return item.GetMetadata("Exclude").Split(';');
        }

        private string[] GetTraverseFiles(ITaskItem item)
        {
            string[] traverseItems = item.GetMetadata("TraverseFiles").Split(';');
            for (int i = 0; i < traverseItems.Length; i++)
            {
                if (!Path.IsPathRooted(traverseItems[i]))
                {
                    traverseItems[i] = Path.Combine(this.MSBuildProjectDirectory, traverseItems[i]);
                }
            }

            return traverseItems;
        }
    }
}

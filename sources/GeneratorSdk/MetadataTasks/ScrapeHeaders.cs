//#define MakeSingleThreaded

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Runtime.InteropServices;
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
        private Assembly clangSharpInteropAsm;
        private Assembly clangSharpAsm;
        private Assembly clangSharpPInvokeGenAsm;
        private Func<object, string, string[], int, object[]> tryParseDelegate;
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

                // Load ClangSharp assemblies for library usage — lets us access the AST
                // to auto-derive typedef-tag remaps during generation
                try
                {
                    this.clangSharpInteropAsm = Assembly.LoadFrom(Path.Combine(this.clangSharpToolDir, "ClangSharp.Interop.dll"));
                    this.clangSharpAsm = Assembly.LoadFrom(Path.Combine(this.clangSharpToolDir, "ClangSharp.dll"));
                    this.clangSharpPInvokeGenAsm = Assembly.LoadFrom(Path.Combine(this.clangSharpToolDir, "ClangSharp.PInvokeGenerator.dll"));

                    // Pre-load native libraries before ClangSharp.Interop's static
                    // constructor runs — it sets its own DllImportResolver, but that
                    // resolver can't find the DLLs when loaded via Assembly.LoadFrom.
                    // Pre-loading puts them in the process so P/Invoke finds them.
                    NativeLibrary.Load(Path.Combine(this.clangSharpToolDir, "libclang.dll"));
                    NativeLibrary.Load(Path.Combine(this.clangSharpToolDir, "libClangSharp.dll"));

                    this.tryParseDelegate = this.BuildTryParseDelegate();
                    this.Log.LogMessage(MessageImportance.High, "Loaded ClangSharp as library for AST-based remap discovery");
                }
                catch (Exception ex)
                {
                    this.Log.LogWarning($"Could not load ClangSharp as library; falling back to CLI: {ex.Message}");
                    this.clangSharpPInvokeGenAsm = null;
                }
            }
            else
            {
                this.Log.LogWarning($"Could not resolve ClangSharpPInvokeGenerator.dll path; falling back to 'dotnet tool run'");
            }

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
            var rspFiles = new List<string> { settingsRsp };
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
                    rspFiles.Add(rspFileName);
                }
                else
                {
                    System.Diagnostics.Debug.WriteLine($"Skipped {rspFileName}, didn't exist...");
                }
            }

            string output;
            int exitCode;
            if (this.clangSharpPInvokeGenAsm != null)
            {
                (exitCode, output) = this.InvokeClangSharpAsLibrary(rspFiles.ToArray());

                // Fall back to CLI for partitions the library can't handle
                // (e.g., x86 inline assembly diagnostics)
                if (exitCode != 0 && this.clangSharpToolPath != null)
                {
                    this.Log.LogMessage(MessageImportance.Normal,
                        $"{infoPrefix} - Library path failed, falling back to CLI");
                    exitCode = TaskUtils.ExecuteCmd("dotnet", $"\"{this.clangSharpToolPath}\" {args}", out output, this.Log);
                }
            }
            else if (this.clangSharpToolPath != null)
            {
                exitCode = TaskUtils.ExecuteCmd("dotnet", $"\"{this.clangSharpToolPath}\" {args}", out output, this.Log);
            }
            else
            {
                exitCode = TaskUtils.ExecuteCmd("dotnet", $"tool run ClangSharpPInvokeGenerator -- {args}", out output, this.Log, workingDirectory: this.ScratchDir);
            }
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

        #region ClangSharp Library Invocation

        /// <summary>
        /// Invokes PInvokeGenerator as a library instead of a CLI process.
        /// This lets us read _allValidNameRemappings from the AST after generation,
        /// which contains typedef-tag relationships discovered by libclang.
        /// </summary>
        private (int exitCode, string output) InvokeClangSharpAsLibrary(string[] rspFiles)
        {
            var outputSb = new StringBuilder();

            try
            {
                // Parse all RSP files into a unified settings dictionary
                var settings = new Dictionary<string, List<string>>(StringComparer.OrdinalIgnoreCase);
                foreach (var rsp in rspFiles)
                    ParseRspFile(rsp, settings);

                // Extract settings
                string sourceFile = settings.GetValueOrDefault("--file")?.LastOrDefault();
                string outputFile = settings.GetValueOrDefault("--output")?.LastOrDefault();
                string ns = settings.GetValueOrDefault("--namespace")?.LastOrDefault();
                string headerFile = settings.GetValueOrDefault("--headerFile")?.LastOrDefault();

                if (sourceFile == null || outputFile == null || ns == null)
                    return (-1, "Error: Missing required --file, --output, or --namespace in RSP files");

                // Build clang command-line args (include dirs + additional flags like -D, -W)
                var clangArgs = new List<string> { "--language=c++", "--std=c++17" };
                if (settings.TryGetValue("--include-directory", out var incDirs))
                    foreach (var dir in incDirs)
                        clangArgs.Add($"--include-directory={dir}");
                if (settings.TryGetValue("--additional", out var additionals))
                    clangArgs.AddRange(additionals);

                // Map --config strings to PInvokeGeneratorConfigurationOptions flags
                var optionsType = this.clangSharpPInvokeGenAsm.GetType("ClangSharp.PInvokeGeneratorConfigurationOptions");
                long optionsValue = 0;
                if (settings.TryGetValue("--config", out var configs))
                {
                    foreach (var cfg in configs)
                    {
                        string fieldName = MapConfigToFieldName(cfg);
                        if (fieldName != null)
                        {
                            var field = optionsType.GetField(fieldName);
                            if (field != null)
                                optionsValue |= Convert.ToInt64(field.GetValue(null));
                        }
                    }
                }

                // Create PInvokeGeneratorConfiguration via reflection
                var outputModeType = this.clangSharpPInvokeGenAsm.GetType("ClangSharp.PInvokeGeneratorOutputMode");
                var configType = this.clangSharpPInvokeGenAsm.GetType("ClangSharp.PInvokeGeneratorConfiguration");
                var config = Activator.CreateInstance(configType, new object[] {
                    "c++", "c++17", ns, outputFile, headerFile ?? string.Empty,
                    Enum.Parse(outputModeType, "CSharp"),
                    Enum.ToObject(optionsType, optionsValue)
                });

                // Set config properties
                SetConfigProperty(configType, config, "TraversalNames",
                    (IReadOnlyCollection<string>)(settings.GetValueOrDefault("--traverse")?.ToArray() ?? Array.Empty<string>()));
                SetConfigProperty(configType, config, "ExcludedNames",
                    (IReadOnlyCollection<string>)(settings.GetValueOrDefault("--exclude")?.ToArray() ?? Array.Empty<string>()));
                SetConfigProperty(configType, config, "RemappedNames",
                    ParseKeyValuePairs(settings.GetValueOrDefault("--remap")));
                SetConfigProperty(configType, config, "WithAttributes",
                    ParseKeyValueMultiPairs(settings.GetValueOrDefault("--with-attribute")));
                SetConfigProperty(configType, config, "WithTypes",
                    ParseKeyValuePairs(settings.GetValueOrDefault("--with-type")));
                SetConfigProperty(configType, config, "WithLibraryPaths",
                    ParseKeyValuePairs(settings.GetValueOrDefault("--with-librarypath")));
                SetConfigProperty(configType, config, "WithCallConvs",
                    ParseKeyValuePairs(settings.GetValueOrDefault("--with-callconv")));
                SetConfigProperty(configType, config, "WithUsings",
                    ParseKeyValueMultiPairs(settings.GetValueOrDefault("--with-using")));

                if (settings.TryGetValue("--methodClassName", out var classNames) && classNames.Count > 0)
                    configType.GetProperty("DefaultClass").SetValue(config, classNames.Last());

                // Create PInvokeGenerator with custom stream factory to avoid file locking
                var genType = this.clangSharpPInvokeGenAsm.GetType("ClangSharp.PInvokeGenerator");
                var capturedStreams = new Dictionary<string, MemoryStream>();
                Func<string, Stream> streamFactory = (path) =>
                {
                    var ms = new MemoryStream();
                    lock (capturedStreams) { capturedStreams[path] = ms; }
                    return ms;
                };
                var generator = Activator.CreateInstance(genType, new object[] { config, streamFactory });

                try
                {
                    // Parse translation unit
                    var indexHandle = genType.GetProperty("IndexHandle").GetValue(generator);

                    var flagsType = this.clangSharpInteropAsm.GetType("ClangSharp.Interop.CXTranslationUnit_Flags");
                    long flagsValue = Convert.ToInt64(Enum.Parse(flagsType, "CXTranslationUnit_IncludeAttributedTypes"))
                                    | Convert.ToInt64(Enum.Parse(flagsType, "CXTranslationUnit_VisitImplicitAttributes"));
                    var flags = Enum.ToObject(flagsType, flagsValue);

                    var cxTUType = this.clangSharpInteropAsm.GetType("ClangSharp.Interop.CXTranslationUnit");

                    // Use IL-emitted delegate to call TryParse (ReadOnlySpan params
                    // cannot be boxed, so standard reflection Invoke doesn't work)
                    var tryParseResult = this.tryParseDelegate(
                        indexHandle, sourceFile, clangArgs.ToArray(), (int)flagsValue);
                    var parseResult = tryParseResult[0];
                    var cxTU = tryParseResult[1];

                    if (parseResult.ToString() != "CXError_Success")
                    {
                        outputSb.AppendLine($"Error: Failed to parse {sourceFile}: {parseResult}");
                        return (-1, outputSb.ToString());
                    }

                    // Wrap in managed TranslationUnit
                    var tuType = this.clangSharpAsm.GetType("ClangSharp.TranslationUnit");
                    var getOrCreate = tuType.GetMethod("GetOrCreate", BindingFlags.Public | BindingFlags.Static);
                    var translationUnit = getOrCreate.Invoke(null, new[] { cxTU });

                    // Generate bindings (same pass that creates C# output)
                    try
                    {
                        genType.GetMethod("GenerateBindings").Invoke(generator, new[] {
                            translationUnit, sourceFile, clangArgs.ToArray(), flags
                        });
                    }
                    catch (TargetInvocationException tie) when (tie.InnerException is ArgumentException ae
                        && ae.Message.Contains("diagnostics which prevent"))
                    {
                        // Some partitions (x86) have non-fatal clang diagnostics that
                        // PInvokeGenerator rejects. Fall through to return failure so the
                        // caller can retry via CLI.
                        outputSb.AppendLine($"Error: {ae.Message}");
                        return (-1, outputSb.ToString());
                    }

                    // Flush output to memory streams
                    genType.GetMethod("Close").Invoke(generator, null);

                    // Write captured output streams to disk
                    foreach (var kvp in capturedStreams)
                    {
                        var dir = Path.GetDirectoryName(kvp.Key);
                        if (!string.IsNullOrEmpty(dir))
                            Directory.CreateDirectory(dir);
                        File.WriteAllBytes(kvp.Key, kvp.Value.ToArray());
                    }

                    // Collect diagnostics
                    var diagnostics = (IEnumerable)genType.GetProperty("Diagnostics").GetValue(generator);
                    foreach (var diag in diagnostics)
                        outputSb.AppendLine($"    {diag}");

                    // Read _allValidNameRemappings — the typedef-tag relationships libclang discovered
                    var remappingsField = genType.GetField("_allValidNameRemappings",
                        BindingFlags.NonPublic | BindingFlags.Instance);
                    if (remappingsField != null)
                    {
                        var allRemappings = remappingsField.GetValue(generator) as IDictionary;
                        if (allRemappings != null)
                        {
                            foreach (DictionaryEntry entry in allRemappings)
                            {
                                string tagName = (string)entry.Key;
                                // Value is HashSet<string> of possible typedef names
                                var typedefNames = entry.Value as IEnumerable<string>;
                                string preferredName = typedefNames?.FirstOrDefault();
                                if (preferredName != null && tagName != preferredName)
                                {
                                    lock (this.suggestedRemaps)
                                    {
                                        if (!this.suggestedRemaps.ContainsKey(tagName))
                                            this.suggestedRemaps[tagName] = preferredName;
                                    }
                                }
                            }
                        }
                    }

                    return (0, outputSb.ToString());
                }
                finally
                {
                    if (generator is IDisposable disposable)
                        disposable.Dispose();
                }
            }
            catch (Exception ex)
            {
                var inner = ex is TargetInvocationException tie ? tie.InnerException : ex;
                outputSb.AppendLine($"Error: Library invocation failed: {inner?.Message ?? ex.Message}");
                return (-1, outputSb.ToString());
            }
        }

        private static void SetConfigProperty(Type configType, object config, string name, object value)
        {
            var prop = configType.GetProperty(name);
            if (prop != null && prop.CanWrite)
                prop.SetValue(config, value);
        }

        private static void ParseRspFile(string path, Dictionary<string, List<string>> settings)
        {
            if (!File.Exists(path)) return;

            string currentSwitch = null;
            foreach (var rawLine in File.ReadLines(path))
            {
                string line = rawLine.Trim();
                if (string.IsNullOrEmpty(line)) continue;

                if (line.StartsWith("--"))
                {
                    currentSwitch = line;
                    if (!settings.ContainsKey(currentSwitch))
                        settings[currentSwitch] = new List<string>();
                }
                else if (currentSwitch != null)
                {
                    settings[currentSwitch].Add(line);
                }
            }
        }

        private static Dictionary<string, string> ParseKeyValuePairs(List<string> items)
        {
            var dict = new Dictionary<string, string>();
            if (items == null) return dict;
            foreach (var item in items)
            {
                int eq = item.IndexOf('=');
                if (eq > 0)
                {
                    string key = item.Substring(0, eq);
                    string val = item.Substring(eq + 1);
                    dict[key] = val;
                }
            }
            return dict;
        }

        private static Dictionary<string, IReadOnlyList<string>> ParseKeyValueMultiPairs(List<string> items)
        {
            var dict = new Dictionary<string, IReadOnlyList<string>>();
            if (items == null) return dict;
            var temp = new Dictionary<string, List<string>>();
            foreach (var item in items)
            {
                int eq = item.IndexOf('=');
                if (eq > 0)
                {
                    string key = item.Substring(0, eq);
                    string val = item.Substring(eq + 1);
                    if (!temp.TryGetValue(key, out var list))
                    {
                        list = new List<string>();
                        temp[key] = list;
                    }
                    list.Add(val);
                }
            }
            foreach (var kv in temp)
                dict[kv.Key] = kv.Value;
            return dict;
        }

        private static string MapConfigToFieldName(string configName)
        {
            return configName switch
            {
                "compatible-codegen" => "GenerateCompatibleCode",
                "log-visited-files" => "LogVisitedFiles",
                "log-exclusions" => "LogExclusions",
                "log-potential-typedef-remappings" => "LogPotentialTypedefRemappings",
                "exclude-funcs-with-body" => "ExcludeFunctionsWithBody",
                "generate-cpp-attributes" => "GenerateCppAttributes",
                "generate-native-bitfield-attribute" => "GenerateNativeBitfieldAttribute",
                "generate-native-inheritance-attribute" => "GenerateNativeInheritanceAttribute",
                "dont-use-using-statics-for-enums" => "DontUseUsingStaticsForEnums",
                "exclude-anonymous-field-helpers" => "ExcludeAnonymousFieldHelpers",
                "exclude-empty-records" => "ExcludeEmptyRecords",
                "exclude-enum-operators" => "ExcludeEnumOperators",
                "exclude-com-proxies" => "ExcludeComProxies",
                "generate-marker-interfaces" => "GenerateMarkerInterfaces",
                "generate-explicit-vtbls" => "GenerateExplicitVtbls",
                "generate-trimmable-vtbls" => "GenerateTrimmableVtbls",
                "generate-aggressive-inlining" => "GenerateAggressiveInlining",
                "multi-file" => "GenerateMultipleFiles",
                "generate-macro-bindings" => "GenerateMacroBindings",
                "generate-file-scoped-namespaces" => "GenerateFileScopedNamespaces",
                "generate-disable-runtime-marshalling" => "GenerateDisableRuntimeMarshalling",
                "generate-guid-member" => "GenerateGuidMember",
                "generate-helper-types" => "GenerateHelperTypes",
                "generate-vtbl-index-attribute" => "GenerateVtblIndexAttribute",
                "generate-setslasterror-attribute" => "GenerateSetsLastSystemErrorAttribute",
                "generate-unmanaged-constants" => "GenerateUnmanagedConstants",
                "generate-latest-code" => "GenerateLatestCode",
                "generate-template-bindings" => "GenerateTemplateBindings",
                "generate-source-location-attribute" => "GenerateSourceLocationAttribute",
                "generate-callconv-member-function" => "GenerateCallConvMemberFunction",
                "generate-doc-includes" => "GenerateDocIncludes",
                "preview-codegen" => "GeneratePreviewCode",
                "unix-types" => "GenerateUnixTypes",
                _ => null
            };
        }

        /// <summary>
        /// Builds a delegate that calls CXTranslationUnit.TryParse via IL emit.
        /// Standard reflection cannot invoke methods with ReadOnlySpan parameters
        /// because ref structs cannot be boxed into the object[] args array.
        /// This DynamicMethod emits IL that passes ReadOnlySpan on the evaluation
        /// stack directly, bypassing the boxing requirement.
        /// </summary>
        /// <returns>
        /// A delegate: (object cxIndex, string sourceFile, string[] clangArgs, int flags)
        ///          -> object[] { CXErrorCode, CXTranslationUnit }
        /// </returns>
        private Func<object, string, string[], int, object[]> BuildTryParseDelegate()
        {
            var cxIndexType = this.clangSharpInteropAsm.GetType("ClangSharp.Interop.CXIndex");
            var cxTUType = this.clangSharpInteropAsm.GetType("ClangSharp.Interop.CXTranslationUnit");
            var errorCodeType = this.clangSharpInteropAsm.GetType("ClangSharp.Interop.CXErrorCode");
            var unsavedFileType = this.clangSharpInteropAsm.GetType("ClangSharp.Interop.CXUnsavedFile");

            var spanStringType = typeof(ReadOnlySpan<>).MakeGenericType(typeof(string));
            var spanUnsavedType = typeof(ReadOnlySpan<>).MakeGenericType(unsavedFileType);

            var tryParseMethod = cxTUType.GetMethod("TryParse", BindingFlags.Public | BindingFlags.Static);

            // Conversion operators for creating spans from arrays / empty
            var opImplicitString = spanStringType.GetMethod("op_Implicit",
                BindingFlags.Public | BindingFlags.Static, null, new[] { typeof(string[]) }, null);
            var emptyUnsavedGetter = spanUnsavedType.GetProperty("Empty",
                BindingFlags.Public | BindingFlags.Static).GetGetMethod();

            var dm = new DynamicMethod(
                "CallTryParse", typeof(object[]),
                new[] { typeof(object), typeof(string), typeof(string[]), typeof(int) },
                typeof(ScrapeHeaders).Module, true);

            var il = dm.GetILGenerator();

            var cxTULocal = il.DeclareLocal(cxTUType);
            var errorLocal = il.DeclareLocal(errorCodeType);
            var resultLocal = il.DeclareLocal(typeof(object[]));

            // arg0: CXIndex (unbox from object)
            il.Emit(OpCodes.Ldarg_0);
            il.Emit(OpCodes.Unbox_Any, cxIndexType);

            // arg1: string sourceFileName
            il.Emit(OpCodes.Ldarg_1);

            // arg2: ReadOnlySpan<string> via implicit conversion from string[]
            il.Emit(OpCodes.Ldarg_2);
            il.EmitCall(OpCodes.Call, opImplicitString, null);

            // arg3: empty ReadOnlySpan<CXUnsavedFile>
            il.EmitCall(OpCodes.Call, emptyUnsavedGetter, null);

            // arg4: CXTranslationUnit_Flags (int → enum, same underlying type)
            il.Emit(OpCodes.Ldarg_3);

            // arg5: out CXTranslationUnit
            il.Emit(OpCodes.Ldloca_S, cxTULocal);

            // call CXTranslationUnit.TryParse(...)
            il.EmitCall(OpCodes.Call, tryParseMethod, null);

            // store error code
            il.Emit(OpCodes.Stloc, errorLocal);

            // build result array: new object[2]
            il.Emit(OpCodes.Ldc_I4_2);
            il.Emit(OpCodes.Newarr, typeof(object));
            il.Emit(OpCodes.Stloc, resultLocal);

            // result[0] = (object)errorCode
            il.Emit(OpCodes.Ldloc, resultLocal);
            il.Emit(OpCodes.Ldc_I4_0);
            il.Emit(OpCodes.Ldloc, errorLocal);
            il.Emit(OpCodes.Box, errorCodeType);
            il.Emit(OpCodes.Stelem_Ref);

            // result[1] = (object)cxTranslationUnit
            il.Emit(OpCodes.Ldloc, resultLocal);
            il.Emit(OpCodes.Ldc_I4_1);
            il.Emit(OpCodes.Ldloc, cxTULocal);
            il.Emit(OpCodes.Box, cxTUType);
            il.Emit(OpCodes.Stelem_Ref);

            // return result
            il.Emit(OpCodes.Ldloc, resultLocal);
            il.Emit(OpCodes.Ret);

            return (Func<object, string, string[], int, object[]>)dm.CreateDelegate(
                typeof(Func<object, string, string[], int, object[]>));
        }

        #endregion

    }
}

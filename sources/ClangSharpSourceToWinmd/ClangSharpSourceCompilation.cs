//#define MakeSingleThreaded
//#define ShowMemoryInfo

using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text.Json;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using MetadataUtils;

namespace ClangSharpSourceToWinmd
{
    public class ClangSharpSourceCompilation
    {
        private const string NumericNamespaceSource = "Win32Metadata.NumericNamespaceSource";
        private CSharpCompilation compilation;
        private Dictionary<string, string> typeImports;
        internal IReadOnlyDictionary<string, string> FieldRenames { get; }
        private ClangSharpSourceCompilation(CSharpCompilation compilation, Dictionary<string, string> typeImports,
            IReadOnlyDictionary<string, string> fieldRenames)
        {
            this.compilation = compilation;
            this.typeImports = typeImports;
            this.FieldRenames = fieldRenames;
        }

        public CSharpCompilation CSharpCompilation => this.compilation;

        internal static void ShowMemory()
        {
#if ShowMemoryInfo
            MEMORYSTATUSEX mem = new MEMORYSTATUSEX();
            if (GlobalMemoryStatusEx(mem))
            {
                double max = ConvertToGB(mem.ullTotalPhys);
                double avail = ConvertToGB(mem.ullAvailPhys);
                Console.WriteLine($"RAM avail = {avail}, load = {mem.dwMemoryLoad}");
            }

            static double ConvertToGB(ulong val)
            {
                return (double)val / (1024 * 1024 * 1024);
            }
#endif
        }

        private static void WriteTree(SyntaxTree tree, string fileName)
        {
            var dir = Path.GetDirectoryName(fileName);
            if (!Directory.Exists(dir))
            {
                Directory.CreateDirectory(dir);
            }

            using (StreamWriter writer = File.CreateText(fileName))
            {
                tree.GetText().Write(writer);
            }
        }

        private static SyntaxTree ReadTree(string fileName)
        {
            var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(fileName), null, fileName);
            if (MetadataSyntaxTreeCleaner.IsLegacyManualSource(fileName) ||
                !tree.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS1514"))
                return tree;
            var replacements = new Dictionary<NamespaceDeclarationSyntax, NamespaceDeclarationSyntax>();
            foreach (var ns in tree.GetRoot().DescendantNodes().OfType<NamespaceDeclarationSyntax>())
            {
                if (!ns.OpenBraceToken.IsMissing || ns.CloseBraceToken.IsMissing || ns.Name.ContainsDiagnostics)
                    continue;
                int bodyStart = ns.Members.Count == 0 ? ns.CloseBraceToken.SpanStart : ns.Members[0].SpanStart;
                var skipped = ns.DescendantTrivia().Where(trivia => trivia.IsKind(SyntaxKind.SkippedTokensTrivia) &&
                    trivia.SpanStart >= ns.Name.Span.End && trivia.Span.End <= bodyStart).ToArray();
                var tokens = skipped.SelectMany(trivia => ((SkippedTokensTriviaSyntax)trivia.GetStructure()).Tokens).ToArray();
                if (tokens.Length != 2 || !tokens[0].IsKind(SyntaxKind.NumericLiteralToken) ||
                    tokens[0].Text.Length < 2 || tokens[0].Text[0] != '.' ||
                    !tokens[0].Text.Skip(1).All(char.IsDigit) || !tokens[1].IsKind(SyntaxKind.OpenBraceToken))
                    continue;
                // Numeric partition suffixes historically bind to the parsed prefix namespace.
                // Preserve that metadata owner while emitting a well-formed namespace declaration.
                replacements.Add(ns, ns.ReplaceTrivia(skipped, (_, _) => SyntaxFactory.Whitespace(""))
                    .WithOpenBraceToken(SyntaxFactory.Token(SyntaxKind.OpenBraceToken))
                    .WithAdditionalAnnotations(new SyntaxAnnotation(NumericNamespaceSource,
                        string.Concat((ns.Name.ToString() + tokens[0].Text).Where(character => !char.IsWhiteSpace(character))))));
            }
            return replacements.Count == 0 ? tree : tree.WithRootAndOptions(
                tree.GetRoot().ReplaceNodes(replacements.Keys, (original, _) => replacements[original]), tree.Options);
        }

        private static IEnumerable<SyntaxTree> FilesToTrees(IEnumerable<string> files)
        {
            foreach (string file in files)
            {
                yield return ReadTree(file);
            }
        }

        internal static Architecture GetArchitectureForFileName(string fileName)
        {
            string potentialArch = Path.GetFileName(Path.GetDirectoryName(fileName));

            switch (potentialArch)
            {
                case "x64":
                    return Architecture.X64;

                case "x86":
                    return Architecture.X86;

                case "arm64":
                    return Architecture.Arm64;

                default:
                    return Architecture.None;
            }
        }

        private static CrossArchSyntaxMap LoadCrossArchMapFromFiles(IEnumerable<string> files, System.Threading.Tasks.ParallelOptions parallelOptions)
        {
            CrossArchSyntaxMap crossArchSyntaxMap = new CrossArchSyntaxMap();

            var nonx86Files = files.Where(f => GetArchitectureForFileName(f) == Architecture.X64 || GetArchitectureForFileName(f) == Architecture.Arm64);
            var x86Files = files.Where(f => GetArchitectureForFileName(f) == Architecture.X86);

            // Add non-x86 first so that x86 has a chance to see if it can merge structs not marked
            // with 4-byte packing with 64-bit versions that are marked. The default packing is 4
            // for x86 so we can merge these types of structs
            System.Threading.Tasks.Parallel.ForEach(FilesToTrees(nonx86Files), parallelOptions, (tree) =>
            {
                crossArchSyntaxMap.AddTree(tree);
            });

            System.Threading.Tasks.Parallel.ForEach(FilesToTrees(x86Files), parallelOptions, (tree) =>
            {
                crossArchSyntaxMap.AddTree(tree);
            });

            return crossArchSyntaxMap;
        }

        private static string GetPartitionNameFromFileName(string fileName)
        {
            return Path.GetFileName(fileName).Replace(".modified.cs", string.Empty);
        }

        private static void ValidateHeaderTypesFamilies(IEnumerable<string> files, GenerationValidation validation)
        {
            var paths = new HashSet<string>(files, StringComparer.OrdinalIgnoreCase);
            foreach (string file in paths.Where(file => HeaderEnumGroupMerger.IsHeaderTypesFile(file) ||
                Path.GetFileName(file) == "header-types.cs" || file.EndsWith(".header-types.cs", StringComparison.Ordinal)))
            {
                if (GetArchitectureForFileName(file) == Architecture.None ||
                    !File.ReadAllText(file).StartsWith(HeaderTypesSourceFamily.SuccessMarker, StringComparison.Ordinal))
                    continue;
                string parent = Path.GetDirectoryName(Path.GetDirectoryName(file));
                string[] siblings = new[] { "x86", "x64", "arm64" }
                    .Select(architecture => Path.Combine(parent, architecture, Path.GetFileName(file))).ToArray();
                var present = siblings.Where(paths.Contains).ToArray();
                if (present.Length == 3 && present.All(path =>
                    File.ReadAllText(path).StartsWith(HeaderTypesSourceFamily.SuccessMarker, StringComparison.Ordinal)))
                    continue;
                bool common = present.Length == 1 && GetArchitectureForFileName(file) == Architecture.X86 &&
                    !siblings.Skip(1).Any(sibling => Path.GetFileName(file) is "header-types.modified.cs" or "header-types.cs"
                        ? paths.Any(path => string.Equals(Path.GetDirectoryName(path), Path.GetDirectoryName(sibling),
                            StringComparison.OrdinalIgnoreCase))
                        : paths.Contains(sibling.Replace(".header-types.modified.cs", ".modified.cs", StringComparison.Ordinal)
                            .Replace(".header-types.cs", ".cs", StringComparison.Ordinal)));
                if (!common)
                    validation.Add(new InvalidOperationException($"CSSW004: Incomplete successful header-types source family '{file}'. " +
                        "Supply all three successfully generated companions, including successful empty outputs; missing or failed profiles are not empty outputs."),
                        "CSSW004", "emitter.source-family-preflight", file,
                        architecture: GetArchitectureForFileName(file).ToString(),
                        partition: Path.GetFileName(file));
            }
        }

        private static string ReadProducerStatus(JsonElement root)
        {
            if (root.ValueKind != JsonValueKind.Object)
                throw new JsonException("Producer receipt must be an object.");
            if (!root.TryGetProperty("Version", out var version) || version.ValueKind != JsonValueKind.Number ||
                !version.TryGetInt32(out int number) || number != 1)
                throw new JsonException("Producer receipt requires supported Version 1.");
            RequireString(root, "Status");
            string status = root.GetProperty("Status").GetString();
            if (status is not ("completed" or "rejected" or "blocked"))
                throw new JsonException($"Unknown producer receipt Status '{status}'.");
            foreach (string field in new[] { "Errors", "BlockedStages", "Reports" })
            {
                if (!root.TryGetProperty(field, out var values))
                    continue;
                if (values.ValueKind != JsonValueKind.Array)
                    throw new JsonException($"Producer receipt '{field}' must be an array when present.");
                foreach (var value in values.EnumerateArray())
                {
                    if (field == "Reports")
                    {
                        if (value.ValueKind != JsonValueKind.String || string.IsNullOrEmpty(value.GetString()))
                            throw new JsonException("Producer receipt Reports entries must be nonempty paths.");
                    }
                    else
                    {
                        if (value.ValueKind != JsonValueKind.Object)
                            throw new JsonException($"Producer receipt '{field}' entries must be objects.");
                        foreach (string name in field == "Errors"
                            ? new[] { "Code", "Stage", "Message", "Cause" } : new[] { "Stage", "Dependency" })
                            RequireString(value, name);
                    }
                }
                if (status == "completed" && field != "Reports" && values.GetArrayLength() != 0)
                    throw new JsonException($"Completed producer receipt cannot contain nonempty '{field}'.");
            }
            return status;

            static void RequireString(JsonElement value, string name)
            {
                if (!value.TryGetProperty(name, out var property) || property.ValueKind != JsonValueKind.String)
                    throw new JsonException($"Producer receipt '{name}' must be a string.");
            }
        }

        public static ClangSharpSourceCompilation Create(
            string sourceDirectory,
            string arch,
            Dictionary<string, string> remaps,
            Dictionary<string, Dictionary<string, string>> enumAdditions,
            IEnumerable<string> enumsMakeFlags,
            Dictionary<string, string> typeImports,
            Dictionary<string, string> requiredNamespaces,
            HashSet<string> reducePointerLevels,
            IEnumerable<string> addedRefs,
            Dictionary<string, string> staticLibs,
            Dictionary<string, string> apiNamesToNamespaces,
            bool nativeFieldArrayInfo = false,
            GenerationValidation validation = null,
            bool preflightOnly = false,
            string blockedBy = null)
        {
            sourceDirectory = Path.GetFullPath(sourceDirectory);
            validation ??= new GenerationValidation();
            string validationReport = Path.Combine(sourceDirectory,
                preflightOnly ? "emitter-preflight-diagnostics.json" : "generation-diagnostics.json");
            File.Delete(validationReport);
            var producerReports = new List<string>();
            foreach (string receipt in new[] { "scrape-diagnostics.json", "native-constant-conflicts.json" })
            {
                if (preflightOnly && (receipt == "scrape-diagnostics.json" && blockedBy != "ScrapeHeaders" ||
                    receipt == "native-constant-conflicts.json" && blockedBy != "ScrapeConstants"))
                    continue;
                string path = Path.Combine(sourceDirectory, receipt);
                if (!File.Exists(path))
                    continue;
                try
                {
                    using var report = JsonDocument.Parse(File.ReadAllText(path));
                    string status = ReadProducerStatus(report.RootElement);
                    if (status != "completed")
                    {
                        producerReports.Add(path);
                        validation.Add(new InvalidDataException($"A required producer has status '{status}'. Rerun it successfully before emission."),
                            "WMG002", "emitter.producer-preflight", path, identityCategory: "producer-authorization");
                    }
                }
                catch (JsonException error)
                {
                    producerReports.Add(path);
                    validation.Add(error, "CSSW004", "emitter.producer-preflight", path, identityCategory: "producer-authorization");
                }
            }

            var refs = new List<MetadataReference>();
            foreach (string referencePath in addedRefs ?? Enumerable.Empty<string>())
            {
                try
                {
                    if (string.IsNullOrWhiteSpace(referencePath))
                        throw new FileNotFoundException("An explicit reference must name an existing metadata assembly.", referencePath);
                    var reference = MetadataReference.CreateFromFile(referencePath);
                    var metadata = reference.GetMetadata();
                    if (metadata is AssemblyMetadata assembly)
                        foreach (var module in assembly.GetModules())
                            _ = module.GetMetadataReader();
                    else if (metadata is ModuleMetadata moduleMetadata)
                        _ = moduleMetadata.GetMetadataReader();
                    refs.Add(reference);
                }
                catch (FileNotFoundException error)
                {
                    validation.Add(error, "CSSW007", "emitter.reference-preflight", referencePath);
                }
                catch (DirectoryNotFoundException error)
                {
                    validation.Add(error, "CSSW007", "emitter.reference-preflight", referencePath);
                }
                catch (BadImageFormatException error)
                {
                    validation.Add(error, "CSSW007", "emitter.reference-preflight", referencePath);
                }
            }

            string topObjDir = Path.Combine(sourceDirectory, "obj");
            var sourceFiles = Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories)
                .Where(file => !file.StartsWith(topObjDir + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase) &&
                    IsValidCsSourceFile(file, arch)).ToArray();
            if (arch == "crossarch")
                ValidateHeaderTypesFamilies(sourceFiles, validation);
            if (preflightOnly || validation.HasErrors)
            {
                CollectSyntaxErrors(FilesToTrees(sourceFiles));
                validation.Block("emitter.source-transformation;emitter.compilation;EmitWinmd;default tests",
                    blockedBy ?? "valid source families, producer receipts, auto-type inputs and explicit references");
                validation.WriteReport(validationReport, producerReports);
                validation.ThrowIfAny(validationReport);
                return null;
            }

            if (Directory.Exists(topObjDir))
            {
                Directory.Delete(topObjDir, true);
            }

            string objDir = Path.Combine(topObjDir, arch);
            Directory.CreateDirectory(objDir);

            IReadOnlyDictionary<string, string> fieldRenames = new Dictionary<string, string>();
            IReadOnlyDictionary<string, string> recordFamilies = new Dictionary<string, string>();

            TreeInfoFinder infoFinder = new TreeInfoFinder();

            List<string> modifiedFiles = new List<string>();
            System.Threading.Tasks.ParallelOptions opt = new System.Threading.Tasks.ParallelOptions();

#if MakeSingleThreaded
            opt.MaxDegreeOfParallelism = 1;
#endif

            foreach (string file in sourceFiles)
            {
                // Turn c:\dir\generated\foo.cs into c:\dir\generated\obj\foo.modified.cs

                string modifiedFile = Path.ChangeExtension(file, ".modified.cs");
                string fileWithSubDir = modifiedFile.Substring(sourceDirectory.Length);
                if (fileWithSubDir.StartsWith('\\'))
                {
                    fileWithSubDir = fileWithSubDir.Substring(1);
                }

                modifiedFile = Path.Combine(objDir, fileWithSubDir);

                var dir = Path.GetDirectoryName(modifiedFile);
                if (!Directory.Exists(dir))
                {
                    Directory.CreateDirectory(dir);
                }

                File.Copy(file, modifiedFile, true);
                modifiedFiles.Add(modifiedFile);
            }

            System.Diagnostics.Stopwatch watch = System.Diagnostics.Stopwatch.StartNew();

            var namespaceTrees = PrepareNativeTypedefProjectionPolicies(
                FilesToTrees(modifiedFiles).ToArray(), sourceDirectory, objDir, validation, requiredNamespaces);
            StopIfInvalid("emitter.native-typedef-policy", "source-bound native projection policies");
            var recordNamespaces = ResolveNativeNamespaces(namespaceTrees, requiredNamespaces, apiNamesToNamespaces, validation);
            StopIfInvalid("emitter.namespace-routing", "native provider ownership");
            var configuredRequiredNamespaces = requiredNamespaces;
            requiredNamespaces = new Dictionary<string, string>(requiredNamespaces);
            apiNamesToNamespaces = new Dictionary<string, string>(apiNamesToNamespaces);
            foreach (var group in recordNamespaces.GroupBy(route => route.Key.Name, StringComparer.Ordinal))
            {
                var owners = group.Select(route => route.Value).Distinct(StringComparer.Ordinal).ToArray();
                apiNamesToNamespaces[group.Key] = string.Join(";", owners);
                if (owners.Length == 1)
                    requiredNamespaces[group.Key] = owners[0];
            }
            var sourceTypes = namespaceTrees
                .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<BaseTypeDeclarationSyntax>()
                    .Where(declaration => declaration is EnumDeclarationSyntax ||
                        declaration is StructDeclarationSyntax record &&
                            (HeaderEnumGroupMerger.IsHeaderTypesFile(tree.FilePath) ||
                                NativeRecordSourceProvenance.Read(record) != null)))
                .Where(declaration => declaration.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax)
                .Select(declaration => (Namespace: SyntaxUtils.GetEnclosingNamespace(declaration), Name: declaration.Identifier.ValueText))
                .ToHashSet();
            var dependencyNamespaces = apiNamesToNamespaces.Values.SelectMany(namespaces => namespaces.Split(';'))
                .Append("System").Where(ns => ns.Length != 0).Distinct(StringComparer.Ordinal).OrderBy(ns => ns, StringComparer.Ordinal)
                .ToArray();

            Console.WriteLine($"  Moving names to correct namespaces...");
            System.Threading.Tasks.Parallel.ForEach(namespaceTrees, opt, (tree) =>
            {
                string treeFile = tree.FilePath;
                if (!treeFile.EndsWith(".manual.cs"))
                {
                    if (HeaderEnumGroupMerger.IsHeaderTypesFile(treeFile))
                    {
                        var root = tree.GetCompilationUnitRoot();
                        var imports = root.Usings.Where(directive => directive.Alias == null &&
                            !directive.StaticKeyword.IsKind(SyntaxKind.StaticKeyword))
                            .Select(directive => directive.Name.ToString()).ToHashSet(StringComparer.Ordinal);
                        tree = tree.WithRootAndOptions(root.AddUsings(dependencyNamespaces.Where(ns => !imports.Contains(ns))
                            .Select(ns => SyntaxFactory.UsingDirective(SyntaxFactory.ParseName(ns)).NormalizeWhitespace()
                                .WithTrailingTrivia(SyntaxFactory.CarriageReturnLineFeed)).ToArray()), tree.Options);
                    }
                    // Loose constants retain their source namespace when their owning enum is routed elsewhere.
                    infoFinder.AnalyzeTree(tree);
                    tree = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree, configuredRequiredNamespaces, sourceTypes, recordNamespaces);

                    infoFinder.AnalyzeTree(tree);

                    WriteTree(tree, treeFile);
                }
            });

            var elapsed = watch.Elapsed;
            Console.WriteLine($"  {OutputUtils.FormatTimespan(elapsed)}");

            ShowMemory();

            HeaderEnumGroupMerger.MergeWithDiagnostics(modifiedFiles, objDir, arch, infoFinder.EnumMemberNames, validation);
            StopIfInvalid("emitter.source-cleaning", "logical enum composition");

            // Retained enum bags own macros globally; native enums also own ConstantsScraper copies.
            var scrapedEnumMemberNames = new HashSet<string>(infoFinder.EnumMemberNames);
            foreach (var tree in FilesToTrees(modifiedFiles.Where(file =>
                !HeaderEnumGroupMerger.IsHeaderEnumSourceFile(file))))
            {
                bool legacyBag = tree.FilePath.EndsWith(".enums.modified.cs", StringComparison.OrdinalIgnoreCase);
                foreach (var member in tree.GetRoot().DescendantNodes().OfType<EnumMemberDeclarationSyntax>()
                    .Where(member => member.Parent?.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax))
                {
                    scrapedEnumMemberNames.Add(member.Identifier.ValueText);
                    if (legacyBag)
                        infoFinder.EnumMemberNames.Add(member.Identifier.ValueText);
                }
            }
            scrapedEnumMemberNames.UnionWith(infoFinder.EnumMemberNames);

            Console.WriteLine($"  Cleaning syntax trees...");

            watch.Restart();

            HashSet<string> enumsMakeFlagsHashSet = enumsMakeFlags != null ? new HashSet<string>(enumsMakeFlags) : new HashSet<string>();
            System.Threading.Tasks.Parallel.ForEach(FilesToTrees(modifiedFiles), opt, (tree) =>
            {
                var enumMemberNames = tree.FilePath.EndsWith(".constants.modified.cs", StringComparison.OrdinalIgnoreCase)
                    ? scrapedEnumMemberNames : infoFinder.EnumMemberNames;
                var cleanedTree = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, remaps, enumAdditions, enumsMakeFlagsHashSet, requiredNamespaces, staticLibs, apiNamesToNamespaces, infoFinder.EmptyStructs, enumMemberNames, tree.FilePath, nativeFieldArrayInfo, validation);
                WriteTree(cleanedTree, cleanedTree.FilePath);
            });
            StopIfInvalid("emitter.crossarch-composition", "source declaration validation");

            Console.WriteLine($"  {OutputUtils.FormatTimespan(watch.Elapsed)}");
            ShowMemory();

            if (arch == "crossarch")
            {
                Console.WriteLine("  Coalescing common native providers...");
                watch.Restart();
                SyntaxTree[] canonicalProviders;
                try
                {
                    canonicalProviders = CoalesceCommonNativeProviders(FilesToTrees(modifiedFiles).ToArray(), refs, validation,
                        configuredRequiredNamespaces, remaps);
                    StopIfInvalid("emitter.crossarch-composition", "canonical native providers");
                    foreach (var tree in canonicalProviders)
                        WriteTree(tree, tree.FilePath);
                }
                finally
                {
                    Console.WriteLine($"  Common native provider coalescing: {OutputUtils.FormatTimespan(watch.Elapsed)}");
                }
                Console.WriteLine("  Qualifying cross-architecture constants...");
                watch.Restart();
                try
                {
                    var qualified = CrossArchConstantQualifier.QualifyWithDiagnostics(canonicalProviders, refs, validation);
                    StopIfInvalid("emitter.crossarch-composition", "constant qualification for every architecture");
                    foreach (var tree in qualified)
                        WriteTree(tree, tree.FilePath);
                }
                finally
                {
                    Console.WriteLine($"  Cross-architecture constant qualification: {OutputUtils.FormatTimespan(watch.Elapsed)}");
                }
                List<string> partitionsNotNeedingCrossarch = new List<string>();

                Console.WriteLine($"  Merging cross-arch items...");
                watch.Restart();

                CrossArchSyntaxMap crossArchSyntaxMap = LoadCrossArchMapFromFiles(modifiedFiles.Where(File.Exists), opt);
                CrossArchTreeMerger crossArchTreeMerger = new CrossArchTreeMerger(crossArchSyntaxMap,
                    FilesToTrees(modifiedFiles.Where(File.Exists)), refs);
                List<string> filesToMerge = new List<string>();
                foreach (string x86FileName in modifiedFiles.Where(f => GetArchitectureForFileName(f) == Architecture.X86))
                {
                    string x64FileName = x86FileName.Replace(@"\x86\", @"\x64\", StringComparison.OrdinalIgnoreCase);
                    string arm64FileName = x86FileName.Replace(@"\x86\", @"\arm64\", StringComparison.OrdinalIgnoreCase);

                    if (File.Exists(x64FileName) && File.Exists(arm64FileName))
                    {
                        string x86Content = File.ReadAllText(x86FileName);
                        if (x86Content == File.ReadAllText(x64FileName) && x86Content == File.ReadAllText(arm64FileName) &&
                            !crossArchSyntaxMap.HasCallbackDependencies(x86FileName) &&
                            !crossArchSyntaxMap.HasCallbackDependencies(x64FileName) &&
                            !crossArchSyntaxMap.HasCallbackDependencies(arm64FileName))
                        {
                            var parititionName = GetPartitionNameFromFileName(x86FileName);

                            File.Delete(x64FileName);
                            File.Delete(arm64FileName);

                            partitionsNotNeedingCrossarch.Add(GetPartitionNameFromFileName(x86FileName));
                        }
                        else
                        {
                            filesToMerge.Add(x64FileName);
                            filesToMerge.Add(x86FileName);
                            filesToMerge.Add(arm64FileName);
                        }
                    }
                }

                HashSet<string> nonX86TreesUsedForX86 = crossArchSyntaxMap.Get64BitTreesUsedForX86();
                System.Threading.Tasks.Parallel.ForEach(FilesToTrees(filesToMerge.Where(f => GetArchitectureForFileName(f) == Architecture.X86)), opt, (x86Tree) =>
                {
                    string x64FileName = x86Tree.FilePath.Replace(@"\x86\", @"\x64\", StringComparison.OrdinalIgnoreCase);
                    string arm64FileName = x86Tree.FilePath.Replace(@"\x86\", @"\arm64\", StringComparison.OrdinalIgnoreCase);

                    var parititionName = GetPartitionNameFromFileName(x86Tree.FilePath);

                    var fixed86Tree = crossArchTreeMerger.ProcessTree(x86Tree, out _);
                    var fixed64Tree = crossArchTreeMerger.ProcessTree(ReadTree(x64FileName), out bool x64Contributed);
                    var fixedArm64Tree = crossArchTreeMerger.ProcessTree(ReadTree(arm64FileName), out bool arm64Contributed);

                    x64Contributed |= nonX86TreesUsedForX86.Contains(x64FileName);
                    arm64Contributed |= nonX86TreesUsedForX86.Contains(arm64FileName);

                    if (!x64Contributed && SyntaxUtils.IsTreeEmpty(fixed64Tree) &&
                         !arm64Contributed && SyntaxUtils.IsTreeEmpty(fixedArm64Tree))
                    {
                        File.Delete(x64FileName);
                        File.Delete(arm64FileName);

                        partitionsNotNeedingCrossarch.Add(GetPartitionNameFromFileName(parititionName));
                    }
                    else
                    {
                        WriteTree(fixed64Tree, fixed64Tree.FilePath);
                        WriteTree(fixedArm64Tree, fixedArm64Tree.FilePath);
                    }

                    WriteTree(fixed86Tree, fixed86Tree.FilePath);
                });
                fieldRenames = new ReadOnlyDictionary<string, string>(
                    crossArchTreeMerger.FieldRenames.ToDictionary(pair => pair.Key, pair => pair.Value, StringComparer.Ordinal));
                recordFamilies = new ReadOnlyDictionary<string, string>(
                    crossArchTreeMerger.RecordFamilies.ToDictionary(pair => pair.Key, pair => pair.Value, StringComparer.Ordinal));

                if (partitionsNotNeedingCrossarch.Count != 0)
                {
                    string partInfo = string.Join(';', partitionsNotNeedingCrossarch.ToArray().OrderBy(s => s));

                    Console.WriteLine($"ClangSharpSourceToWinmd : warning CSSW001: Partitions detected with no cross-arch differences: {partInfo}");
                }

                Console.WriteLine($"  {OutputUtils.FormatTimespan(watch.Elapsed)}");
                ShowMemory();
            }

            Console.WriteLine($"  Creating C# compilation on processed syntax trees...");
            watch.Restart();

            CSharpCompilationOptions compilationOptions = new CSharpCompilationOptions(OutputKind.WindowsRuntimeMetadata, allowUnsafe: true);
            var comp =
                CSharpCompilation.Create(
                    null,
                    FilesToTrees(modifiedFiles.Where(f => File.Exists(f))),
                    refs,
                    compilationOptions);

            comp = AddNetstandardReference(comp);

            Console.WriteLine($"  C# compilation creation: {OutputUtils.FormatTimespan(watch.Elapsed)}");
            Console.WriteLine("  Composing native typedef and record providers...");
            watch.Restart();
            try
            {
                comp = MergeLegacyTypedefProjections(comp, requiredNamespaces, validation);
                comp = HeaderTypedefMerger.MergeWithDiagnostics(comp, validation, configuredRequiredNamespaces, recordFamilies, remaps);
                if (!validation.HasErrors)
                    comp = MergeRepeatedStructs(comp, validation);
            }
            finally
            {
                Console.WriteLine($"  Native typedef and record composition: {OutputUtils.FormatTimespan(watch.Elapsed)}");
            }
            Console.WriteLine("  Lowering constants and validating associations...");
            watch.Restart();
            if (!validation.HasErrors)
            {
                comp = HeaderTypedefMerger.LowerConstantsWithDiagnostics(comp, true, validation);
                if (!validation.HasErrors)
                    comp = HeaderEnumGroupMerger.ConvertPrimitiveConstantAliases(comp);
            }
            else
                validation.Block("emitter.typedef-constant-lowering", "native typedef composition");
            HeaderEnumGroupMerger.ValidateAssociationsWithDiagnostics(comp, arch, validation);
            StopIfInvalid("emitter.compilation", "typedef and association validation", comp.SyntaxTrees);

            Console.WriteLine($"  {OutputUtils.FormatTimespan(watch.Elapsed)}");
            ShowMemory();

            return new ClangSharpSourceCompilation(comp, typeImports, fieldRenames);

            void StopIfInvalid(string stage, string dependency, IEnumerable<SyntaxTree> syntaxTrees = null)
            {
                if (syntaxTrees != null)
                    CollectSyntaxErrors(syntaxTrees);
                if (!validation.HasErrors)
                    return;
                if (syntaxTrees == null)
                    CollectSyntaxErrors(FilesToTrees(modifiedFiles.Where(File.Exists)));
                validation.Block(stage, dependency);
                validation.Block("EmitWinmd;default tests", stage);
                validation.WriteReport(validationReport, producerReports);
                validation.ThrowIfAny(validationReport);
            }

            void CollectSyntaxErrors(IEnumerable<SyntaxTree> trees)
            {
                foreach (var tree in trees
                    .Where(tree => !MetadataSyntaxTreeCleaner.IsLegacyManualSource(tree.FilePath)))
                    foreach (var diagnostic in tree.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error))
                        validation.Add(new InvalidOperationException(diagnostic.ToString()), diagnostic.Id,
                            "emitter.source-syntax-preflight", tree.FilePath,
                            line: diagnostic.Location.GetLineSpan().StartLinePosition.Line + 1,
                            architecture: GetArchitectureForFileName(tree.FilePath).ToString());
            }
        }

        private static SyntaxTree[] PrepareNativeTypedefProjectionPolicies(SyntaxTree[] trees,
            string sourceDirectory, string objDir, GenerationValidation validation,
            IReadOnlyDictionary<string, string> requiredNamespaces)
        {
            var policies = new List<(SyntaxTree Tree, StructDeclarationSyntax Declaration,
                NativeRecordSource Source, bool? Inferred)>();
            foreach (var tree in trees.Where(tree => HeaderEnumGroupMerger.IsHeaderTypesFile(tree.FilePath)))
            {
                bool? legacyInferred = null;
                bool readLegacyPolicy = false;
                foreach (var declaration in tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                {
                    try
                    {
                        bool? inferred = NativeTypedefProjectionProvenance.IsInferred(declaration);
                        _ = NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(declaration);
                        var source = NativeTypedefSourceProvenance.Read(declaration);
                        if (source == null)
                            continue;
                        if (!inferred.HasValue)
                        {
                            if (!readLegacyPolicy)
                            {
                                readLegacyPolicy = true;
                                string relative = Path.GetRelativePath(objDir, tree.FilePath)
                                    .Replace(".header-types.modified.cs", ".native-declarations.json", StringComparison.Ordinal);
                                string modelPath = Path.Combine(sourceDirectory, relative);
                                if (File.Exists(modelPath))
                                {
                                    using var model = JsonDocument.Parse(File.ReadAllText(modelPath));
                                    var root = model.RootElement;
                                    if (root.ValueKind != JsonValueKind.Object ||
                                        !root.TryGetProperty("schemaVersion", out var version) ||
                                        version.ValueKind != JsonValueKind.Number ||
                                        !version.TryGetInt32(out int schemaVersion) || schemaVersion != 1 ||
                                        !root.TryGetProperty("projectionCompleted", out var completed) ||
                                        completed.ValueKind != JsonValueKind.True ||
                                        !root.TryGetProperty("primaryFlags", out var flags) ||
                                        flags.ValueKind != JsonValueKind.String ||
                                        !ulong.TryParse(flags.GetString(), System.Globalization.NumberStyles.None,
                                            System.Globalization.CultureInfo.InvariantCulture, out ulong nativeFlags))
                                        throw new InvalidDataException("Invalid retained native declaration projection evidence.");
                                    // Annotation parsing requires DetailedPreprocessingRecord (bit 0).
                                    legacyInferred = (nativeFlags & 1) == 0 ? true : null;
                                }
                            }
                            if (legacyInferred == true)
                                inferred = source.NativeName == source.Name &&
                                    !NativeHandleSourceProvenance.TryRead(declaration, out _) &&
                                    declaration.AttributeLists.SelectMany(list => list.Attributes).All(attribute =>
                                        attribute.Name.ToString().Split('.').Last() is
                                            "NativeTypedef" or "NativeTypedefAttribute" or
                                            "SupportedArchitecture" or "SupportedArchitectureAttribute");
                        }
                        policies.Add((tree, declaration, source, inferred));
                    }
                    catch (Exception error) when (error is InvalidDataException or JsonException)
                    {
                        validation.Add(error, "CSSW005", "emitter.native-typedef-policy", tree.FilePath,
                            declaration.Identifier.ValueText);
                    }
                }
            }
            var replacements = new Dictionary<StructDeclarationSyntax, StructDeclarationSyntax>();
            var nativeOwners = HeaderTypedefMerger.FindNativeProjectionOwners(trees,
                policies.Select(policy => policy.Declaration), requiredNamespaces, validation);
            foreach (var family in policies.GroupBy(policy =>
                (Identity: NativeRecordSourceProvenance.GetIdentityKey(policy.Source),
                    Header: policy.Source.Header.ToUpperInvariant())))
            {
                bool inferred = family.All(policy => policy.Inferred == true) && !family.Any(policy =>
                    nativeOwners.TryGetValue(policy.Source.Name, out var owner) && owner.IsTarget(policy.Declaration));
                foreach (var policy in family)
                    if (policy.Inferred.HasValue)
                        replacements.Add(policy.Declaration,
                            NativeTypedefProjectionProvenance.WithPolicy(policy.Declaration, inferred));
            }
            return trees.Select(tree =>
            {
                var declarations = replacements.Keys.Where(declaration => declaration.SyntaxTree == tree).ToArray();
                if (declarations.Length == 0)
                    return tree;
                var replacement = tree.WithRootAndOptions(tree.GetRoot().ReplaceNodes(declarations,
                    (original, _) => replacements[original]), tree.Options);
                WriteTree(replacement, replacement.FilePath);
                return replacement;
            }).ToArray();
        }

        internal static bool HasConflictingNativeDeclarations(
            IEnumerable<(NativeRecordSource Source, Architecture Architectures)> sources)
        {
            var versions = sources.Where(source => source.Source != null)
                .Select(source => (source.Source,
                    Architectures: source.Source.SourceArchitecture ?? source.Architectures)).ToArray();
            if (versions.Skip(1).Any(source => NativeRecordSourceProvenance.GetIdentityKey(source.Source) !=
                NativeRecordSourceProvenance.GetIdentityKey(versions[0].Source)))
                return true;
            return new[] { Architecture.X86, Architecture.X64, Architecture.Arm64 }.Any(architecture =>
            {
                var applicable = versions.Where(source => source.Architectures == Architecture.None ||
                    (source.Architectures & architecture) != 0).ToArray();
                return applicable.Skip(1).Any(source =>
                    !NativeRecordSourceProvenance.SameDeclaration(applicable[0].Source, source.Source));
            });
        }

        private static Dictionary<(string Namespace, string Name), string> ResolveNativeNamespaces(IEnumerable<SyntaxTree> trees,
            IReadOnlyDictionary<string, string> requiredNamespaces, IReadOnlyDictionary<string, string> scannedNamespaces,
            GenerationValidation validation)
        {
            var retained = trees.Where(tree => tree.FilePath.EndsWith("autotypes.modified.cs", StringComparison.OrdinalIgnoreCase))
                .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                .Where(declaration => declaration.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax)
                .GroupBy(declaration => (Namespace: SyntaxUtils.GetEnclosingNamespace(declaration),
                    Name: declaration.Identifier.ValueText))
                .Where(group => group.Count() == 1).Select(group => group.Key).ToHashSet();
            var retainedOwners = retained.Concat(trees.Where(tree =>
                    MetadataSyntaxTreeCleaner.IsLegacyManualSource(tree.FilePath) ||
                    tree.FilePath.EndsWith(".enums.modified.cs", StringComparison.OrdinalIgnoreCase))
                .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>())
                .Where(declaration => declaration.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax)
                .Select(declaration => (Namespace: SyntaxUtils.GetEnclosingNamespace(declaration),
                    Name: declaration.Identifier.ValueText)))
                .Distinct().GroupBy(owner => owner.Name, StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => group.Select(owner => owner.Namespace).ToArray(),
                    StringComparer.Ordinal);
            var records = new List<(StructDeclarationSyntax Declaration, NativeRecordSource Source, string Namespace,
                Architecture Architectures, bool ConfiguredNominal)>();
            foreach (var tree in trees.Where(tree => !tree.FilePath.EndsWith("manual.cs", StringComparison.OrdinalIgnoreCase)))
            {
                foreach (var declaration in tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>()
                    .Where(declaration => declaration.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax))
                {
                    try
                    {
                        var record = NativeRecordSourceProvenance.Read(declaration);
                        var alias = NativeTypedefSourceProvenance.Read(declaration);
                        if (record != null && alias != null)
                            throw new InvalidDataException("A native provider cannot have both record and typedef source identities.");
                        var source = record ?? alias;
                        if (source == null)
                            continue;
                        string ns = SyntaxUtils.GetEnclosingNamespace(declaration);
                        if (source.Namespace != ns && !declaration.Ancestors().OfType<NamespaceDeclarationSyntax>()
                            .Any(owner => owner.GetAnnotations(NumericNamespaceSource).Any(annotation =>
                                annotation.Data == string.Concat(source.Namespace.Where(character => !char.IsWhiteSpace(character))))))
                            throw new InvalidDataException("Native record source namespace drift.");
                        var architecture = GetArchitectureForFileName(tree.FilePath);
                        records.Add((declaration, source, ns, architecture,
                            NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(declaration)));
                    }
                    catch (InvalidDataException error)
                    {
                        validation.Add(error, "CSSW005", "emitter.record-ownership", tree.FilePath,
                            declaration.Identifier.ValueText);
                    }
                }
            }
            var routes = new Dictionary<(string Namespace, string Name), string>();
            var identities = new Dictionary<(string Namespace, string Name, Architecture Architecture), string>();
            var nativeOwners = HeaderTypedefMerger.FindNativeProjectionOwners(trees,
                records.Select(record => record.Declaration), requiredNamespaces, validation);
            foreach (var legacy in records.Where(record =>
                NativeTypedefSourceProvenance.Read(record.Declaration) != null &&
                NativeRecordSourceProvenance.GetIdentityKey(record.Source) != record.Source.Identity)
                .GroupBy(record => (record.Source.Identity, record.Source.Name)))
            {
                if (legacy.Select(record => record.Source.Header).Distinct(StringComparer.OrdinalIgnoreCase).Skip(1).Any() &&
                    legacy.Any(record => !NativeTypedefProjectionProvenance.IsInferred(record.Declaration).HasValue) &&
                    !retainedOwners.ContainsKey(legacy.Key.Name) &&
                    !(nativeOwners.TryGetValue(legacy.Key.Name, out var owner) &&
                        legacy.All(record => owner.Authorizes(record.Declaration))))
                    validation.Add(new InvalidDataException($"Conflicting native record identities for '{legacy.Key.Name}': " +
                        "independent file-local aliases require source-bound projection policies."),
                        "CSSW005", "emitter.record-ownership", legacy.First().Declaration.SyntaxTree.FilePath, legacy.Key.Name);
            }
            var intrinsicNames = records.GroupBy(record => record.Source.Name, StringComparer.Ordinal)
                .Where(group => !retainedOwners.ContainsKey(group.Key) && group.All(record =>
                    NativeTypedefSourceProvenance.Read(record.Declaration) != null &&
                    NativeTypedefProjectionProvenance.IsInferred(record.Declaration) == true))
                .Select(group => group.Key).ToHashSet(StringComparer.Ordinal);
            var independentlyOwnedRecords = records.GroupBy(record =>
                (Identity: NativeRecordSourceProvenance.GetIdentityKey(record.Source), record.Source.Name))
                .Where(group => group.All(record => NativeRecordSourceProvenance.Read(record.Declaration) != null) &&
                    group.Where(record => record.Source.TraversedHeader).Select(record => record.Source.Header)
                        .Distinct(StringComparer.OrdinalIgnoreCase).Skip(1).Any())
                .Select(group => group.Key).ToHashSet();
            foreach (var group in records.GroupBy(record =>
                (Identity: NativeRecordSourceProvenance.GetIdentityKey(record.Source), record.Source.Name,
                    Header: independentlyOwnedRecords.Contains((NativeRecordSourceProvenance.GetIdentityKey(record.Source),
                        record.Source.Name)) ? record.Source.Header.ToUpperInvariant() : null)))
            {
                var first = group.First();
                bool nativeRecord = group.All(record => NativeRecordSourceProvenance.Read(record.Declaration) != null);
                bool nativeAlias = group.All(record => NativeTypedefSourceProvenance.Read(record.Declaration) != null);
                string owner = requiredNamespaces.TryGetValue(group.Key.Name, out string required) ? required : null;
                var nativeOwner = nativeAlias && nativeOwners.TryGetValue(group.Key.Name, out var projectedOwner) &&
                    group.All(record => projectedOwner.Authorizes(record.Declaration)) ? projectedOwner : null;
                owner ??= nativeOwner?.Namespace;
                if (owner == null && nativeAlias && group.Any(record => record.ConfiguredNominal) &&
                    retainedOwners.TryGetValue(group.Key.Name, out var configuredOwners))
                {
                    if (configuredOwners.Length != 1)
                    {
                        validation.Add(new InvalidDataException(
                            $"Configured native typedef '{group.Key.Name}' has multiple retained metadata targets."),
                            "CSSW005", "emitter.record-ownership", first.Declaration.SyntaxTree.FilePath, group.Key.Name);
                        continue;
                    }
                    owner = configuredOwners[0];
                }
                bool retainedProjection = owner != null && nativeAlias &&
                    (retained.Contains((owner, group.Key.Name)) || nativeOwner?.Namespace == owner);
                bool conflictingDeclarations = nativeRecord
                    ? group.GroupBy(record => record.Source.Header, StringComparer.OrdinalIgnoreCase).Any(header =>
                        new[] { Architecture.X86, Architecture.X64, Architecture.Arm64 }.Any(architecture =>
                        {
                            var applicable = header.Where(record =>
                            {
                                var targets = record.Source.SourceArchitecture ?? record.Architectures;
                                return targets == Architecture.None || (targets & architecture) != 0;
                            }).OrderBy(record => record.Source.TraversedHeader ? 0 : 1).ToArray();
                            return applicable.Skip(1).Any(record =>
                                !NativeRecordSourceProvenance.SameDeclaration(applicable[0].Source, record.Source) &&
                                !HasAnonymousStorageVariants(applicable[0].Declaration, record.Declaration));
                        }))
                    : retainedProjection
                    ? group.GroupBy(record => record.Source.Header, StringComparer.OrdinalIgnoreCase)
                        .Any(header => HasConflictingNativeDeclarations(header.Select(record => (record.Source, record.Architectures))))
                    : HasConflictingNativeDeclarations(group.Select(record => (record.Source, record.Architectures)));
                if (conflictingDeclarations || group.Any(record => record.Source.NativeName != first.Source.NativeName))
                {
                    validation.Add(new InvalidDataException($"Conflicting native record identities for '{group.Key.Name}'."),
                        "CSSW005", "emitter.record-ownership", first.Declaration.SyntaxTree.FilePath, group.Key.Name);
                    continue;
                }
                if (owner == null && nativeAlias && retainedOwners.TryGetValue(group.Key.Name, out var metadataOwners))
                {
                    var observedOwners = metadataOwners.Where(metadataOwner =>
                        group.Any(record => record.Namespace == metadataOwner)).ToArray();
                    if (observedOwners.Length > 1)
                    {
                        validation.Add(new InvalidDataException(
                            $"Native typedef '{group.Key.Name}' has multiple observed retained metadata owners."),
                            "CSSW005", "emitter.record-ownership", first.Declaration.SyntaxTree.FilePath, group.Key.Name);
                        continue;
                    }
                    owner = observedOwners.SingleOrDefault();
                }
                var direct = group.Where(record => record.Source.TraversedHeader).Select(record => record.Namespace)
                    .Distinct(StringComparer.Ordinal).OrderBy(ns => ns, StringComparer.Ordinal).ToArray();
                string[] scanned = scannedNamespaces.TryGetValue(group.Key.Name, out string namespaces)
                    ? namespaces.Split(';').Where(ns => ns.Length != 0).Distinct(StringComparer.Ordinal).ToArray()
                    : Array.Empty<string>();
                owner ??= direct.Length == 0 ? scanned.Length == 1 ? scanned[0] : null :
                    scanned.Length == 1 && direct.Contains(scanned[0], StringComparer.Ordinal) ? scanned[0] : direct[0];
                owner ??= group.Select(record => record.Namespace).OrderBy(ns => ns, StringComparer.Ordinal).First();
                foreach (string originalNamespace in group.Select(record => record.Namespace).Distinct(StringComparer.Ordinal))
                {
                    var key = (originalNamespace, group.Key.Name);
                    bool conflict = false;
                    foreach (var architecture in new[] { Architecture.X86, Architecture.X64, Architecture.Arm64 })
                    {
                        var applicable = group.Where(record => record.Namespace == originalNamespace &&
                            (record.Architectures == Architecture.None || (record.Architectures & architecture) != 0)).ToArray();
                        if (applicable.Length == 0)
                            continue;
                        var identityKey = (originalNamespace, group.Key.Name, architecture);
                        if (identities.TryGetValue(identityKey, out string identity) && identity != group.Key.Identity &&
                            !retainedProjection && !intrinsicNames.Contains(group.Key.Name))
                        {
                            validation.Add(new InvalidDataException($"Distinct native records project to '{originalNamespace}.{group.Key.Name}'."),
                                "CSSW005", "emitter.record-ownership", applicable[0].Declaration.SyntaxTree.FilePath,
                                group.Key.Name, architecture: architecture.ToString());
                            conflict = true;
                            continue;
                        }
                        identities[identityKey] = group.Key.Identity;
                    }
                    if (conflict)
                        continue;
                    if (routes.TryGetValue(key, out string previousOwner) && previousOwner != owner)
                    {
                        validation.Add(new InvalidDataException($"Conditional native providers for '{originalNamespace}.{group.Key.Name}' " +
                            $"have conflicting public owners '{previousOwner}' and '{owner}'."),
                            "CSSW005", "emitter.record-ownership", first.Declaration.SyntaxTree.FilePath, group.Key.Name);
                        continue;
                    }
                    routes[key] = owner;
                }
            }
            return routes;
        }

        private static SyntaxTree[] CoalesceCommonNativeProviders(SyntaxTree[] trees,
            IEnumerable<MetadataReference> references, GenerationValidation validation,
            IReadOnlyDictionary<string, string> requiredNamespaces, IReadOnlyDictionary<string, string> remaps)
        {
            var groups = trees.Where(tree => !MetadataSyntaxTreeCleaner.IsLegacyManualSource(tree.FilePath))
                .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                .Where(declaration => declaration.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax &&
                    declaration.Modifiers.Any(SyntaxKind.PartialKeyword) && declaration.TypeParameterList == null &&
                    declaration.BaseList == null)
                .Select(declaration => (Declaration: declaration,
                    Source: HeaderEnumGroupMerger.IsHeaderTypesFile(declaration.SyntaxTree.FilePath)
                        ? NativeTypedefSourceProvenance.Read(declaration) : NativeRecordSourceProvenance.Read(declaration),
                    Architecture: GetArchitectureForFileName(declaration.SyntaxTree.FilePath),
                    IsTypedef: HeaderEnumGroupMerger.IsHeaderTypesFile(declaration.SyntaxTree.FilePath)))
                .Where(item => item.Source != null)
                .GroupBy(item => (Name: $"{SyntaxUtils.GetEnclosingNamespace(item.Declaration)}.{item.Declaration.Identifier.ValueText}",
                    item.IsTypedef)).ToArray();
            var trackedTrees = groups.SelectMany(group => group).GroupBy(item => item.Declaration.SyntaxTree)
                .ToDictionary(group => group.Key, group => group.Key.WithRootAndOptions(
                    group.Key.GetRoot().TrackNodes(group.Select(item => item.Declaration)), group.Key.Options));
            var compilations = new Dictionary<Architecture, CSharpCompilation>();
            var comparisonTrees = new Dictionary<Architecture, Dictionary<string, SyntaxTree>>();
            var removals = new HashSet<StructDeclarationSyntax>();
            foreach (var group in groups)
            {
                var familyCopies = new Dictionary<Architecture, Dictionary<StructDeclarationSyntax, StructDeclarationSyntax>>();
                var familyBindings = new Dictionary<Architecture, NativeBindingComparison>();
                var direct = group.Where(item => item.Architecture != Architecture.None &&
                    item.Source.TraversedHeader &&
                    (item.Source.SourceArchitecture ?? item.Architecture) == item.Architecture).ToArray();
                foreach (var common in group.Where(item => item.Architecture == Architecture.None &&
                    !item.Source.TraversedHeader && item.Source.SourceArchitecture.HasValue))
                {
                    var providers = direct.Where(item => NativeRecordSourceProvenance.GetIdentityKey(item.Source) ==
                        NativeRecordSourceProvenance.GetIdentityKey(common.Source) &&
                        item.Source.NativeName == common.Source.NativeName && item.Source.Name == common.Source.Name &&
                        string.Equals(item.Source.Header, common.Source.Header, StringComparison.OrdinalIgnoreCase) &&
                        item.Source.HeaderHash == common.Source.HeaderHash).ToArray();
                    if (providers.Aggregate(Architecture.None, (coverage, item) => coverage | item.Architecture) != Architecture.All)
                        continue;
                    Architecture architecture = common.Source.SourceArchitecture.Value;
                    var matching = providers.Where(item => item.Architecture == architecture &&
                            NativeRecordSourceProvenance.SameDeclaration(common.Source, item.Source) &&
                            common.Source.Size == item.Source.Size && common.Source.Alignment == item.Source.Alignment)
                        .OrderBy(item => item.Declaration.SyntaxTree.FilePath, StringComparer.Ordinal).ToArray();
                    if (!compilations.TryGetValue(architecture, out var compilation))
                    {
                        compilation = AddNetstandardReference(CSharpCompilation.Create("CommonNativeProviders",
                            trees.Where(tree => GetArchitectureForFileName(tree.FilePath) is Architecture.None ||
                                GetArchitectureForFileName(tree.FilePath) == architecture)
                                .Select(tree => trackedTrees.TryGetValue(tree, out var tracked) ? tracked : tree), references,
                            new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true)));
                        compilation = HeaderTypedefMerger.BindLegacyEnumProjectionsForComparison(compilation, validation,
                            requiredNamespaces, remaps);
                        if (validation.HasErrors)
                            return trees;
                        compilations.Add(architecture, compilation);
                        comparisonTrees.Add(architecture, compilation.SyntaxTrees.ToDictionary(tree => tree.FilePath,
                            StringComparer.OrdinalIgnoreCase));
                    }
                    if (!familyCopies.TryGetValue(architecture, out var comparisonCopies))
                    {
                        comparisonCopies = group.Where(item => item.Architecture is Architecture.None || item.Architecture == architecture)
                            .Select(item => item.Declaration).ToDictionary(declaration => declaration, declaration =>
                                comparisonTrees[architecture][declaration.SyntaxTree.FilePath].GetRoot().GetCurrentNode(declaration));
                        familyCopies.Add(architecture, comparisonCopies);
                    }
                    // Validated enum projection removes the whole native alias family from this comparison.
                    if (group.Key.IsTypedef && comparisonCopies.Values.All(declaration => declaration == null))
                        continue;
                    bool matches = matching.Length != 0 && comparisonCopies.Values.All(declaration => declaration != null);
                    if (matches)
                    {
                        var canonical = comparisonCopies[matching[0].Declaration];
                        var observed = comparisonCopies[common.Declaration];
                        matches = group.Key.IsTypedef && SyntaxFactory.AreEquivalent(canonical, observed) &&
                            BindingsMatch(canonical, compilation.GetSemanticModel(canonical.SyntaxTree),
                                observed, compilation.GetSemanticModel(observed.SyntaxTree));
                        if (!matches)
                        {
                            if (!familyBindings.TryGetValue(architecture, out var comparison))
                            {
                                comparison = new NativeBindingComparison(compilation, comparisonCopies.Values.ToArray());
                                familyBindings.Add(architecture, comparison);
                            }
                            matches = NativeBindingsMatch(comparison, canonical, observed);
                        }
                    }
                    if (!matches)
                    {
                        // Other typedef constraints still require the normal full-family merger.
                        if (group.Key.IsTypedef)
                            continue;
                        validation.Add(new InvalidDataException(
                            $"Common native {(group.Key.IsTypedef ? "typedef" : "record")} '{group.Key.Name}' " +
                            $"conflicts with its canonical {architecture} provider " +
                            $"for '{common.Source.Header}:{common.Source.Line}:{common.Source.Column}'."),
                            "CSSW005", "emitter.record-composition", common.Declaration.SyntaxTree.FilePath, group.Key.Name);
                        continue;
                    }
                    // This is one target's dependency observation, not an architecture-neutral native body.
                    removals.Add(common.Declaration);
                }
            }
            return trees.Select(tree =>
            {
                var removed = removals.Where(declaration => declaration.SyntaxTree == tree).ToArray();
                return removed.Length == 0 ? tree : tree.WithRootAndOptions(
                    tree.GetRoot().RemoveNodes(removed, SyntaxRemoveOptions.KeepNoTrivia), tree.Options);
            }).ToArray();
        }

        private static CSharpCompilation MergeRepeatedStructs(CSharpCompilation compilation, GenerationValidation validation)
        {
            var removals = new HashSet<StructDeclarationSyntax>();
            var groups = compilation.SyntaxTrees.Where(tree =>
                !tree.FilePath.EndsWith("manual.cs", StringComparison.OrdinalIgnoreCase) &&
                !HeaderEnumGroupMerger.IsHeaderTypesFile(tree.FilePath))
                .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                .Where(declaration => declaration.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax &&
                    declaration.Modifiers.Any(SyntaxKind.PartialKeyword) &&
                    declaration.TypeParameterList == null && declaration.BaseList == null &&
                    (NativeRecordSourceProvenance.Read(declaration) != null ||
                    declaration.Members.All(member => member is FieldDeclarationSyntax field &&
                        !field.Modifiers.Any(SyntaxKind.ConstKeyword) && !field.Modifiers.Any(SyntaxKind.StaticKeyword) &&
                        field.Declaration.Variables.All(variable => variable.Initializer == null))))
                .GroupBy(declaration => $"{SyntaxUtils.GetEnclosingNamespace(declaration)}.{declaration.Identifier.ValueText}",
                    StringComparer.Ordinal).Where(group => group.Count() > 1);
            foreach (var group in groups)
            {
                var copies = group.OrderBy(declaration => NativeRecordSourceProvenance.Read(declaration)?.TraversedHeader == true ? 0 : 1)
                    .ThenBy(declaration => declaration.SyntaxTree.FilePath, StringComparer.Ordinal).ToArray();
                var sources = copies.Select(NativeRecordSourceProvenance.Read).ToArray();
                bool native = sources.All(source => source != null);
                if (native && sources.Skip(1).Select((source, index) => (Source: source, Declaration: copies[index + 1])).Any(item =>
                {
                    var source = item.Source;
                    return
                    NativeRecordSourceProvenance.GetIdentityKey(source) != NativeRecordSourceProvenance.GetIdentityKey(sources[0]) ||
                    source.NativeName != sources[0].NativeName ||
                    source.Name != sources[0].Name ||
                    string.Equals(source.Header, sources[0].Header, StringComparison.OrdinalIgnoreCase) &&
                        !NativeRecordSourceProvenance.SameDeclaration(sources[0], source) &&
                        !HasAnonymousStorageVariants(copies[0], item.Declaration) ||
                    source.Size != sources[0].Size || source.Alignment != sources[0].Alignment;
                }))
                {
                    validation.Add(new InvalidDataException($"Conflicting native record providers for '{group.Key}'."),
                        "CSSW005", "emitter.record-composition", copies[0].SyntaxTree.FilePath, group.Key);
                    continue;
                }
                if (!native && (copies.Select(declaration => declaration.SyntaxTree).Distinct().Count() != copies.Length ||
                    copies.Skip(1).Any(declaration => !SyntaxFactory.AreEquivalent(copies[0], declaration))))
                    continue;
                var firstModel = compilation.GetSemanticModel(copies[0].SyntaxTree);
                var firstSymbol = firstModel.GetDeclaredSymbol(copies[0]);
                if (firstSymbol == null)
                    continue;
                var nativeBindings = native ? new NativeBindingComparison(compilation, copies) : null;
                // Identical text can refer to different field types or annotation arguments through using aliases.
                if (copies.Skip(1).Any(declaration =>
                {
                    var model = compilation.GetSemanticModel(declaration.SyntaxTree);
                    return !SymbolEqualityComparer.Default.Equals(firstSymbol, model.GetDeclaredSymbol(declaration)) ||
                        !(native ? NativeBindingsMatch(nativeBindings, copies[0], declaration) :
                            BindingsMatch(copies[0], firstModel, declaration, model));
                }))
                    continue;
                removals.UnionWith(copies.Skip(1));
            }
            return RemoveStructs(compilation, removals);
        }

        private static (StructDeclarationSyntax Declaration, NativeRecordSource Source, int Index)[] AnonymousUnionProviders(
            StructDeclarationSyntax declaration)
        {
            var parent = NativeRecordSourceProvenance.Read(declaration);
            return declaration.Members.Select((member, index) => (Declaration: member as StructDeclarationSyntax, Index: index))
                .Where(item => item.Declaration != null)
                .Select(item => (item.Declaration, Source: NativeRecordSourceProvenance.Read(item.Declaration), item.Index))
                .Where(item => parent != null && item.Source != null &&
                    item.Source.Identity.StartsWith(parent.Identity + "@U", StringComparison.Ordinal) &&
                    (item.Source.NativeName.StartsWith(parent.NativeName + "::(anonymous union at ", StringComparison.Ordinal) ||
                        item.Source.NativeName.StartsWith(parent.NativeName + "::(unnamed union at ", StringComparison.Ordinal)) &&
                    string.Equals(item.Source.Header, parent.Header, StringComparison.OrdinalIgnoreCase) &&
                    item.Source.HeaderHash == parent.HeaderHash && item.Source.SourceArchitecture == parent.SourceArchitecture)
                .ToArray();
        }

        private static bool HasAnonymousStorageVariants(StructDeclarationSyntax first, StructDeclarationSyntax second)
        {
            var left = NativeRecordSourceProvenance.Read(first);
            var right = NativeRecordSourceProvenance.Read(second);
            if (left == null || right == null || !(left.TraversedHeader || right.TraversedHeader) ||
                NativeRecordSourceProvenance.GetIdentityKey(left) != NativeRecordSourceProvenance.GetIdentityKey(right) ||
                left.NativeName != right.NativeName || left.Name != right.Name ||
                !string.Equals(left.Header, right.Header, StringComparison.OrdinalIgnoreCase) ||
                left.HeaderHash != right.HeaderHash || left.Size != right.Size || left.Alignment != right.Alignment)
                return false;
            var leftUnions = AnonymousUnionProviders(first);
            var rightUnions = AnonymousUnionProviders(second);
            return leftUnions.Length != 0 && leftUnions.Length == rightUnions.Length &&
                leftUnions.Zip(rightUnions).All(pair => pair.First.Index == pair.Second.Index &&
                    pair.First.Source.Size == pair.Second.Source.Size &&
                    pair.First.Source.Alignment == pair.Second.Source.Alignment);
        }

        private sealed class NativeBindingComparison
        {
            public NativeBindingComparison(CSharpCompilation compilation, IReadOnlyList<StructDeclarationSyntax> copies)
            {
                Compilation = compilation;
                Copies = copies.ToArray();
            }

            public CSharpCompilation Compilation { get; }
            public IReadOnlyList<StructDeclarationSyntax> Copies { get; }
            public Dictionary<(StructDeclarationSyntax Canonical, bool Alternate, bool Anonymous, bool Broader),
                (StructDeclarationSyntax Declaration, SemanticModel Model, StructDeclarationSyntax Normalized)> CanonicalViews { get; } = new();
        }

        private static bool NativeBindingsMatch(NativeBindingComparison comparison, StructDeclarationSyntax first,
            StructDeclarationSyntax second)
        {
            var compilation = comparison.Compilation;
            // Bind each complete provider without its duplicate fields, indexers and locals.
            bool alternateDefinitions = !string.Equals(NativeRecordSourceProvenance.Read(first)?.Header,
                NativeRecordSourceProvenance.Read(second)?.Header, StringComparison.OrdinalIgnoreCase);
            bool anonymousStorageVariants = HasAnonymousStorageVariants(first, second);
            int firstMask = SupportedMask(first);
            int secondMask = SupportedMask(second);
            bool retainBroaderCoverage = alternateDefinitions && firstMask != 0 && secondMask != 0 &&
                (secondMask & ~firstMask) == 0;
            var key = (first, alternateDefinitions, anonymousStorageVariants, retainBroaderCoverage);
            if (!comparison.CanonicalViews.TryGetValue(key, out var left))
            {
                left = Isolate(first);
                comparison.CanonicalViews.Add(key, left);
            }
            var right = Isolate(second);
            return left.Declaration != null && right.Declaration != null &&
                SyntaxFactory.AreEquivalent(left.Normalized, right.Normalized) &&
                BindingsMatch(left.Declaration, left.Model, right.Declaration, right.Model, isolated: true);

            (StructDeclarationSyntax Declaration, SemanticModel Model, StructDeclarationSyntax Normalized)
                Isolate(StructDeclarationSyntax retained)
            {
                var marker = new SyntaxAnnotation();
                var result = compilation;
                SyntaxTree retainedTree = null;
                foreach (var group in comparison.Copies.GroupBy(declaration => declaration.SyntaxTree))
                {
                    var tree = group.Key;
                    var root = tree.GetRoot();
                    if (tree == retained.SyntaxTree)
                        root = root.ReplaceNode(retained, retained.WithAdditionalAnnotations(marker));
                    var spans = group.Where(declaration => declaration != retained)
                        .Select(declaration => declaration.Span).ToHashSet();
                    root = root.RemoveNodes(root.DescendantNodes().OfType<StructDeclarationSyntax>()
                        .Where(declaration => spans.Contains(declaration.Span)), SyntaxRemoveOptions.KeepNoTrivia);
                    var replacement = tree.WithRootAndOptions(root, tree.Options);
                    result = result.ReplaceSyntaxTree(tree, replacement);
                    if (tree == retained.SyntaxTree)
                        retainedTree = replacement;
                }
                var declaration = (StructDeclarationSyntax)retainedTree.GetRoot().GetAnnotatedNodes(marker).Single();
                var model = result.GetSemanticModel(retainedTree);
                if (retained != first && left.Declaration != null && NativeRecordSourceProvenance.SameDeclaration(
                    NativeRecordSourceProvenance.Read(first), NativeRecordSourceProvenance.Read(retained)))
                {
                    var fields = left.Declaration.DescendantNodes().OfType<FieldDeclarationSyntax>()
                        .GroupBy(MemberKey).Where(group => group.Count() == 1)
                        .ToDictionary(group => group.Key, group => group.Single(), StringComparer.Ordinal);
                    var parameters = left.Declaration.DescendantNodes().OfType<ParameterSyntax>()
                        .Where(parameter => parameter.Parent is BaseParameterListSyntax { Parent: MemberDeclarationSyntax })
                        .GroupBy(ParameterKey).Where(group => group.Count() == 1)
                        .ToDictionary(group => group.Key, group => group.Single(), StringComparer.Ordinal);
                    var references = new Dictionary<SyntaxNode, SyntaxNode>();
                    foreach (var field in declaration.DescendantNodes().OfType<FieldDeclarationSyntax>())
                    {
                        if (!fields.TryGetValue(MemberKey(field), out var canonicalField) ||
                            MetadataSyntaxTreeCleaner.HasAppliedTypeRemap(field) ||
                            MetadataSyntaxTreeCleaner.HasAppliedTypeRemap(canonicalField))
                            continue;
                        var incoming = model.GetTypeInfo(field.Declaration.Type).Type;
                        var expected = left.Model.GetTypeInfo(canonicalField.Declaration.Type).Type;
                        if (incoming?.ToDisplayString() != expected?.ToDisplayString() &&
                            (HaveEquivalentNativeAliases(incoming, expected) ||
                                HaveEquivalentNativeRecordPointers(incoming, expected, field, model, canonicalField, left.Model)))
                            references.Add(field.Declaration.Type, SyntaxFactory.ParseTypeName(
                                expected.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat)));
                    }
                    foreach (var parameter in declaration.DescendantNodes().OfType<ParameterSyntax>()
                        .Where(parameter => parameter.Parent is BaseParameterListSyntax { Parent: MemberDeclarationSyntax }))
                    {
                        if (!parameters.TryGetValue(ParameterKey(parameter), out var canonicalParameter) ||
                            MetadataSyntaxTreeCleaner.HasAppliedTypeRemap(parameter) ||
                            MetadataSyntaxTreeCleaner.HasAppliedTypeRemap(canonicalParameter))
                            continue;
                        var incoming = model.GetTypeInfo(parameter.Type).Type;
                        var expected = left.Model.GetTypeInfo(canonicalParameter.Type).Type;
                        var alias = expected;
                        int pointerDepth = 0;
                        while (alias is IPointerTypeSymbol pointer)
                        {
                            pointerDepth++;
                            alias = pointer.PointedAtType;
                        }
                        if (incoming?.ToDisplayString() == expected?.ToDisplayString() ||
                            !TryGetNativeAlias(alias, out var source, out var storage, out _, out bool isConst))
                            continue;
                        for (int i = 0; i < pointerDepth; i++)
                            storage = result.CreatePointerTypeSymbol(storage);
                        if (!SymbolEqualityComparer.Default.Equals(incoming, storage))
                            continue;
                        string nativeName = source.NativeName + string.Concat(Enumerable.Repeat(" *", pointerDepth));
                        bool transportedConst = isConst && pointerDepth == 0;
                        var attributes = parameter.AttributeLists.SelectMany(list => list.Attributes).ToArray();
                        var nativeTypes = attributes.Where(attribute => AttributeName(attribute, model) ==
                            "Windows.Win32.Foundation.Metadata.NativeTypeNameAttribute").ToArray();
                        var constants = attributes.Where(attribute => AttributeName(attribute, model) ==
                            "Windows.Win32.Foundation.Metadata.ConstAttribute").ToArray();
                        if (nativeTypes.Length != 1 || nativeTypes[0].ArgumentList?.Arguments.Count != 1 ||
                            model.GetConstantValue(nativeTypes[0].ArgumentList.Arguments[0].Expression).Value is not string declared ||
                            declared != nativeName || constants.Length != (transportedConst ? 1 : 0) ||
                            constants.Any(attribute => attribute.ArgumentList?.Arguments.Count > 0) ||
                            canonicalParameter.AttributeLists.SelectMany(list => list.Attributes).Any(attribute =>
                                AttributeName(attribute, left.Model) is "Windows.Win32.Foundation.Metadata.NativeTypeNameAttribute" or
                                    "Windows.Win32.Foundation.Metadata.ConstAttribute"))
                            continue;
                        var transported = nativeTypes.Concat(constants).ToHashSet();
                        var lists = parameter.AttributeLists.Select(list => list.WithAttributes(
                            SyntaxFactory.SeparatedList(list.Attributes.Where(attribute => !transported.Contains(attribute)))))
                            .Where(list => list.Attributes.Count != 0);
                        references.Add(parameter, parameter.WithType(SyntaxFactory.ParseTypeName(
                            expected.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat)).WithTriviaFrom(parameter.Type))
                            .WithAttributeLists(SyntaxFactory.List(lists)));
                    }
                    if (references.Count != 0)
                    {
                        var root = retainedTree.GetRoot().ReplaceNodes(references.Keys,
                            (original, rewritten) => references[original].WithTriviaFrom(rewritten));
                        var replacement = retainedTree.WithRootAndOptions(root, retainedTree.Options);
                        result = result.ReplaceSyntaxTree(retainedTree, replacement);
                        retainedTree = replacement;
                        declaration = (StructDeclarationSyntax)retainedTree.GetRoot().GetAnnotatedNodes(marker).Single();
                        model = result.GetSemanticModel(retainedTree);
                    }
                }
                var renamedSymbols = new Dictionary<ISymbol, string>(SymbolEqualityComparer.Default);
                var renamedTokens = new Dictionary<SyntaxToken, string>();
                var replacements = new Dictionary<SyntaxNode, SyntaxNode>();
                if (anonymousStorageVariants)
                {
                    foreach (var union in AnonymousUnionProviders(declaration))
                    {
                        var canonicalUnion = (StructDeclarationSyntax)first.Members[union.Index];
                        var canonicalSource = NativeRecordSourceProvenance.Read(canonicalUnion);
                        var symbol = model.GetDeclaredSymbol(union.Declaration);
                        if (symbol == null)
                            return (null, null, null);
                        renamedSymbols.Add(symbol, canonicalUnion.Identifier.ValueText);
                        renamedTokens.Add(union.Declaration.Identifier, canonicalUnion.Identifier.ValueText);
                        var fields = declaration.Members.OfType<FieldDeclarationSyntax>().Where(field =>
                            SymbolEqualityComparer.Default.Equals(model.GetTypeInfo(field.Declaration.Type).Type, symbol)).ToArray();
                        if (fields.Length == 0)
                            return (null, null, null);
                        foreach (var field in fields)
                        {
                            if (first.Members[declaration.Members.IndexOf(field)] is not FieldDeclarationSyntax canonicalField ||
                                field.Declaration.Variables.Count != canonicalField.Declaration.Variables.Count)
                                return (null, null, null);
                            var attributes = field.AttributeLists.SelectMany(list => list.Attributes).Where(attribute =>
                                model.GetSymbolInfo(attribute).Symbol is IMethodSymbol constructor &&
                                constructor.ContainingType.ToDisplayString() == "Windows.Win32.Foundation.Metadata.NativeTypeNameAttribute")
                                .ToArray();
                            if (attributes.Length != 1 || attributes[0].ArgumentList?.Arguments.Count != 1)
                                return (null, null, null);
                            var expression = attributes[0].ArgumentList.Arguments[0].Expression;
                            if (model.GetConstantValue(expression).Value is not string nativeName ||
                                nativeName != AnonymousRecordName(union.Source))
                                return (null, null, null);
                            replacements.Add(expression, SyntaxFactory.LiteralExpression(SyntaxKind.StringLiteralExpression,
                                SyntaxFactory.Literal(AnonymousRecordName(canonicalSource))));
                            for (int i = 0; i < field.Declaration.Variables.Count; i++)
                            {
                                var variable = field.Declaration.Variables[i];
                                var fieldSymbol = model.GetDeclaredSymbol(variable);
                                if (fieldSymbol == null)
                                    return (null, null, null);
                                string name = canonicalField.Declaration.Variables[i].Identifier.ValueText;
                                renamedSymbols.Add(fieldSymbol, name);
                                renamedTokens.Add(variable.Identifier, name);
                            }
                        }
                    }
                    foreach (var identifier in declaration.DescendantNodes().OfType<IdentifierNameSyntax>())
                        if (model.GetSymbolInfo(identifier).Symbol is { } symbol && renamedSymbols.TryGetValue(symbol, out string name))
                            renamedTokens.TryAdd(identifier.Identifier, name);
                }
                var types = declaration.DescendantNodes().Select(node => node switch
                {
                    VariableDeclarationSyntax variable => variable.Type,
                    ParameterSyntax parameter => parameter.Type,
                    PropertyDeclarationSyntax property => property.Type,
                    IndexerDeclarationSyntax indexer => indexer.Type,
                    MethodDeclarationSyntax method => method.ReturnType,
                    CastExpressionSyntax cast => cast.Type,
                    TypeOfExpressionSyntax typeOf => typeOf.Type,
                    SizeOfExpressionSyntax sizeOf => sizeOf.Type,
                    BaseTypeSyntax baseType => baseType.Type,
                    _ => null,
                }).Where(type => type != null).Distinct().ToArray();
                foreach (var type in types)
                {
                    var symbol = model.GetTypeInfo(type is RefTypeSyntax reference ? reference.Type : type).Type;
                    if (symbol == null || symbol.TypeKind == TypeKind.Error)
                    {
                        if (IsMemberImplementation(type))
                            continue;
                        return (null, null, null);
                    }
                    if (alternateDefinitions)
                        symbol = HeaderTypedefMerger.GetNativeRecordScalarStorage(result, symbol);
                    var qualified = SyntaxFactory.ParseTypeName(string.Concat(symbol.ToDisplayParts(SymbolDisplayFormat.FullyQualifiedFormat)
                        .Select(part => part.Symbol != null && renamedSymbols.TryGetValue(part.Symbol, out string name) ? name : part.ToString())));
                    replacements.Add(type, type is RefTypeSyntax refType ? refType.WithType(qualified) : qualified);
                }
                // NONAMELESSUNION changes generated storage names, not the canonical native record's field bindings.
                var canonical = declaration.ReplaceSyntax(replacements.Keys,
                    (original, rewritten) => replacements[original].WithTriviaFrom(rewritten),
                    renamedTokens.Keys, (original, rewritten) =>
                        SyntaxFactory.Identifier(renamedTokens[original]).WithTriviaFrom(rewritten),
                    Array.Empty<SyntaxTrivia>(), (_, rewritten) => rewritten);
                if (retainBroaderCoverage)
                    canonical = canonical.WithAttributeLists(SyntaxFactory.List(declaration.AttributeLists.Select(list =>
                        list.WithAttributes(SyntaxFactory.SeparatedList(list.Attributes.Where(attribute =>
                            !IsArchitectureAttribute(attribute, model))))).Where(list => list.Attributes.Count != 0)));
                if (SyntaxFactory.AreEquivalent(declaration, canonical))
                    return (declaration, model, canonical.NormalizeWhitespace());
                var canonicalRoot = retainedTree.GetRoot().ReplaceNode(declaration, canonical);
                var canonicalTree = retainedTree.WithRootAndOptions(canonicalRoot, retainedTree.Options);
                result = result.ReplaceSyntaxTree(retainedTree, canonicalTree);
                var isolated = (StructDeclarationSyntax)canonicalTree.GetRoot().GetAnnotatedNodes(marker).Single();
                return (isolated, result.GetSemanticModel(canonicalTree), isolated.NormalizeWhitespace());
            }

            int SupportedMask(StructDeclarationSyntax declaration)
            {
                var model = compilation.GetSemanticModel(declaration.SyntaxTree);
                var attributes = declaration.AttributeLists.SelectMany(list => list.Attributes)
                    .Where(attribute => IsArchitectureAttribute(attribute, model)).ToArray();
                if (attributes.Length == 0)
                    return (int)Architecture.All;
                var masks = attributes.Select(attribute => attribute.ArgumentList?.Arguments.Count == 1
                    ? model.GetConstantValue(attribute.ArgumentList.Arguments[0].Expression).Value : null).ToArray();
                return masks.All(mask => mask is int value && value > 0 && (value & ~(int)Architecture.All) == 0) &&
                    masks.Distinct().Count() == 1 ? (int)masks[0] : 0;
            }

            static bool IsArchitectureAttribute(AttributeSyntax attribute, SemanticModel model) =>
                model.GetSymbolInfo(attribute).Symbol is IMethodSymbol constructor &&
                constructor.ContainingType.ToDisplayString() == "Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute";

            static string AnonymousRecordName(NativeRecordSource source) =>
                $"__AnonymousRecord_{Path.GetFileNameWithoutExtension(source.Header)}_L{source.Line}_C{source.Column}";
        }

        private static string MemberKey(MemberDeclarationSyntax member) => string.Join("/", member.AncestorsAndSelf()
            .OfType<MemberDeclarationSyntax>().Reverse().Select(declaration => declaration switch
            {
                TypeDeclarationSyntax type => "type:" + type.Identifier.ValueText,
                FieldDeclarationSyntax field => "field:" + string.Join(",", field.Declaration.Variables
                    .Select(variable => variable.Identifier.ValueText)),
                MethodDeclarationSyntax method => "method:" + method.Identifier.ValueText + ":" + method.ParameterList.Parameters.Count,
                DelegateDeclarationSyntax callback => "delegate:" + callback.Identifier.ValueText + ":" + callback.ParameterList.Parameters.Count,
                _ => declaration.Kind().ToString(),
            }));

        private static string ParameterKey(ParameterSyntax parameter) =>
            MemberKey((MemberDeclarationSyntax)parameter.Parent.Parent) + ":" +
                ((BaseParameterListSyntax)parameter.Parent).Parameters.IndexOf(parameter);

        private static string AttributeName(AttributeSyntax attribute, SemanticModel model) =>
            (model.GetSymbolInfo(attribute).Symbol as IMethodSymbol)?.ContainingType.ToDisplayString();

        private static bool HaveEquivalentNativeAliases(ITypeSymbol left, ITypeSymbol right) =>
            TryGetNativeAlias(left, out var leftSource, out var leftStorage, out string leftNativeType, out bool leftConst) &&
            TryGetNativeAlias(right, out var rightSource, out var rightStorage, out string rightNativeType, out bool rightConst) &&
            leftSource.NativeName == rightSource.NativeName && leftSource.Size == rightSource.Size &&
            leftSource.Alignment == rightSource.Alignment && leftSource.SourceArchitecture == rightSource.SourceArchitecture &&
            leftNativeType == rightNativeType && leftConst == rightConst &&
            SymbolEqualityComparer.Default.Equals(leftStorage, rightStorage);

        private static bool HaveEquivalentNativeRecordPointers(ITypeSymbol incoming, ITypeSymbol expected,
            FieldDeclarationSyntax field, SemanticModel model, FieldDeclarationSyntax canonical, SemanticModel canonicalModel)
        {
            int depth = 0;
            while (incoming is IPointerTypeSymbol incomingPointer && expected is IPointerTypeSymbol expectedPointer)
            {
                depth++;
                incoming = incomingPointer.PointedAtType;
                expected = expectedPointer.PointedAtType;
            }
            if (depth == 0 || incoming?.SpecialType != SpecialType.System_Void ||
                expected is not INamedTypeSymbol { TypeKind: TypeKind.Struct } record)
                return false;
            var sources = record.DeclaringSyntaxReferences.Select(reference => reference.GetSyntax())
                .OfType<StructDeclarationSyntax>().Select(NativeRecordSourceProvenance.Read).ToArray();
            if (sources.Length == 0 || sources.Any(source => !NativeRecordSourceProvenance.SameDeclaration(sources[0], source)))
                return false;
            string nativeType = NativeType(field, model);
            if (nativeType == null || nativeType != NativeType(canonical, canonicalModel))
                return false;
            string name = sources[0].NativeName + string.Concat(Enumerable.Repeat(" *", depth));
            return nativeType == name || nativeType == "struct " + name || nativeType == "union " + name;

            static string NativeType(FieldDeclarationSyntax declaration, SemanticModel semanticModel)
            {
                var attributes = declaration.AttributeLists.SelectMany(list => list.Attributes).Where(attribute =>
                    AttributeName(attribute, semanticModel) == "Windows.Win32.Foundation.Metadata.NativeTypeNameAttribute").ToArray();
                return attributes.Length == 1 && attributes[0].ArgumentList?.Arguments.Count == 1
                    ? semanticModel.GetConstantValue(attributes[0].ArgumentList.Arguments[0].Expression).Value as string : null;
            }
        }

        private static bool TryGetNativeAlias(ITypeSymbol type, out NativeRecordSource source, out ITypeSymbol storage,
            out string nativeType, out bool isConst)
        {
            source = null;
            nativeType = null;
            storage = null;
            isConst = false;
            if (type is not INamedTypeSymbol { TypeKind: TypeKind.Struct, ContainingType: null } named ||
                !named.GetAttributes().Any(attribute => attribute.AttributeClass?.ToDisplayString() ==
                    "Windows.Win32.Foundation.Metadata.NativeTypedefAttribute") ||
                named.GetAttributes().Any(attribute => attribute.AttributeClass?.ToDisplayString() is not
                    ("Windows.Win32.Foundation.Metadata.NativeTypedefAttribute" or
                    "Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute" or
                    "Windows.Win32.Foundation.Metadata.DocumentationAttribute")))
                return false;
            var sources = named.DeclaringSyntaxReferences.Select(reference => reference.GetSyntax())
                .OfType<StructDeclarationSyntax>().Select(NativeTypedefSourceProvenance.Read).ToArray();
            if (sources.Length == 0 || sources.Any(observation => observation == null) ||
                sources.Select(observation => (observation.NativeName, observation.Size, observation.Alignment,
                    observation.SourceArchitecture)).Distinct().Count() != 1)
                return false;
            var fields = named.GetMembers().OfType<IFieldSymbol>().Where(field => !field.IsStatic && !field.IsImplicitlyDeclared).ToArray();
            if (fields.Length != 1 || fields[0].Name != "Value" || fields[0].Type.TypeKind == TypeKind.Error)
                return false;
            var attributes = fields[0].GetAttributes();
            if (attributes.Any(attribute => attribute.AttributeClass?.ToDisplayString() is not
                ("Windows.Win32.Foundation.Metadata.NativeTypeNameAttribute" or "Windows.Win32.Foundation.Metadata.ConstAttribute")) ||
                attributes.GroupBy(attribute => attribute.AttributeClass, SymbolEqualityComparer.Default).Any(group => group.Count() != 1))
                return false;
            var native = attributes.SingleOrDefault(attribute => attribute.AttributeClass?.ToDisplayString() ==
                "Windows.Win32.Foundation.Metadata.NativeTypeNameAttribute");
            if (native?.ConstructorArguments.Length != 1 || native.ConstructorArguments[0].Value is not string spelling)
                return false;
            source = sources[0];
            nativeType = spelling;
            storage = fields[0].Type;
            isConst = attributes.Any(attribute => attribute.AttributeClass?.ToDisplayString() ==
                "Windows.Win32.Foundation.Metadata.ConstAttribute");
            return true;
        }

        private static CSharpCompilation MergeLegacyTypedefProjections(CSharpCompilation compilation,
            IReadOnlyDictionary<string, string> requiredNamespaces, GenerationValidation validation)
        {
            var removals = new HashSet<StructDeclarationSyntax>();
            foreach (var tree in compilation.SyntaxTrees.Where(tree =>
                !MetadataSyntaxTreeCleaner.IsLegacyManualSource(tree.FilePath) &&
                !HeaderEnumGroupMerger.IsHeaderTypesFile(tree.FilePath)))
            {
                foreach (var declaration in tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>()
                    .Where(declaration => declaration.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax &&
                        declaration.Identifier.ValueText.EndsWith(MetadataSyntaxTreeCleaner.RevertToTypeSuffix, StringComparison.Ordinal)))
                {
                    string name = declaration.Identifier.ValueText[..^MetadataSyntaxTreeCleaner.RevertToTypeSuffix.Length];
                    string ns = requiredNamespaces.TryGetValue(name, out var owner) ? owner :
                        SyntaxUtils.GetEnclosingNamespace(declaration);
                    string identity = string.IsNullOrEmpty(ns) ? name : ns + "." + name;
                    var provider = compilation.GetTypeByMetadataName(identity);
                    if (provider?.DeclaringSyntaxReferences.Length != 1)
                        continue;
                    var reference = provider.DeclaringSyntaxReferences.Single();
                    if (!MetadataSyntaxTreeCleaner.IsLegacyManualSource(reference.SyntaxTree.FilePath) ||
                        reference.GetSyntax() is not StructDeclarationSyntax manual ||
                        manual.OpenBraceToken.IsMissing || !manual.OpenBraceToken.IsKind(SyntaxKind.OpenBraceToken))
                        continue;

                    // The suffix requests the established manual typedef, not another native provider.
                    var generatedModel = compilation.GetSemanticModel(tree);
                    var manualModel = compilation.GetSemanticModel(reference.SyntaxTree);
                    if (!SyntaxFactory.AreEquivalent(
                            WithoutDocumentation(declaration, generatedModel).WithIdentifier(manual.Identifier),
                            WithoutDocumentation(manual, manualModel)) ||
                        !BindingsMatch(declaration, generatedModel, manual, manualModel, ignoreDocumentation: true))
                    {
                        validation.Add(new InvalidOperationException($"Legacy typedef projection '{declaration.Identifier.ValueText}' " +
                            $"conflicts with the established manual provider '{identity}'."),
                            "CSSW005", "emitter.legacy-typedef-composition", tree.FilePath, declaration.Identifier.ValueText,
                            architecture: GetArchitectureForFileName(tree.FilePath).ToString());
                        continue;
                    }
                    removals.Add(declaration);
                }
            }
            return RemoveStructs(compilation, removals);
        }

        private static StructDeclarationSyntax WithoutDocumentation(StructDeclarationSyntax declaration, SemanticModel model)
        {
            var result = declaration.ReplaceNodes(declaration.DescendantNodes().OfType<AttributeListSyntax>(),
                (list, _) => list.WithAttributes(SyntaxFactory.SeparatedList(list.Attributes
                    .Where(attribute => !IsDocumentationAttribute(attribute, model)))));
            return result.RemoveNodes(result.DescendantNodes().OfType<AttributeListSyntax>()
                .Where(list => list.Attributes.Count == 0), SyntaxRemoveOptions.KeepNoTrivia);
        }

        private static bool IsDocumentationAttribute(AttributeSyntax attribute, SemanticModel model)
            => model.GetSymbolInfo(attribute).Symbol is IMethodSymbol constructor &&
                constructor.ContainingType.ToDisplayString() == "Windows.Win32.Foundation.Metadata.DocumentationAttribute";

        private static CSharpCompilation RemoveStructs(CSharpCompilation compilation,
            IEnumerable<StructDeclarationSyntax> removals)
        {
            foreach (var group in removals.GroupBy(declaration => declaration.SyntaxTree))
            {
                var tree = group.Key;
                var replacement = tree.WithRootAndOptions(
                    tree.GetRoot().RemoveNodes(group, SyntaxRemoveOptions.KeepNoTrivia), tree.Options);
                File.WriteAllText(tree.FilePath, replacement.GetText().ToString());
                compilation = compilation.ReplaceSyntaxTree(tree, replacement);
            }
            return compilation;
        }

        private static bool BindingsMatch(StructDeclarationSyntax first, SemanticModel firstModel,
            StructDeclarationSyntax second, SemanticModel secondModel, bool ignoreDocumentation = false,
            bool isolated = false)
        {
            var comparison = new DeclarationBindingComparison(first, firstModel, second, secondModel, isolated);
            var firstNodes = first.DescendantNodes().Where(node => node is ExpressionSyntax or AttributeSyntax)
                .Where(node => !isolated || !IsMemberImplementation(node))
                .Where(node => !ignoreDocumentation || !node.AncestorsAndSelf().OfType<AttributeSyntax>()
                    .Any(attribute => IsDocumentationAttribute(attribute, firstModel))).ToArray();
            var secondNodes = second.DescendantNodes().Where(node => node is ExpressionSyntax or AttributeSyntax)
                .Where(node => !isolated || !IsMemberImplementation(node))
                .Where(node => !ignoreDocumentation || !node.AncestorsAndSelf().OfType<AttributeSyntax>()
                    .Any(attribute => IsDocumentationAttribute(attribute, secondModel))).ToArray();
            if (firstNodes.Length != secondNodes.Length)
                return false;
            for (int i = 0; i < firstNodes.Length; i++)
            {
                var left = firstModel.GetSymbolInfo(firstNodes[i]);
                var right = secondModel.GetSymbolInfo(secondNodes[i]);
                if (left.CandidateReason != CandidateReason.None || right.CandidateReason != CandidateReason.None ||
                    !comparison.SymbolsMatch(left.Symbol, right.Symbol))
                    return false;
                if (firstNodes[i] is ExpressionSyntax leftExpression && secondNodes[i] is ExpressionSyntax rightExpression)
                {
                    var leftType = firstModel.GetTypeInfo(leftExpression);
                    var rightType = secondModel.GetTypeInfo(rightExpression);
                    if (leftType.Type?.TypeKind == TypeKind.Error || rightType.Type?.TypeKind == TypeKind.Error ||
                        !comparison.TypesMatch(leftType.Type, rightType.Type) ||
                        !comparison.TypesMatch(leftType.ConvertedType, rightType.ConvertedType))
                        return false;
                }
            }
            return true;
        }

        private sealed class DeclarationBindingComparison
        {
            private readonly bool isolated;
            private readonly Dictionary<ISymbol, int> firstDeclarations;
            private readonly Dictionary<ISymbol, int> secondDeclarations;

            public DeclarationBindingComparison(StructDeclarationSyntax first, SemanticModel firstModel,
                StructDeclarationSyntax second, SemanticModel secondModel, bool isolated)
            {
                this.isolated = isolated;
                firstDeclarations = isolated ? DeclaredSymbols(first, firstModel) : null;
                secondDeclarations = isolated ? DeclaredSymbols(second, secondModel) : null;
            }

            public bool SymbolsMatch(ISymbol left, ISymbol right)
            {
                if (SymbolEqualityComparer.Default.Equals(left, right))
                    return true;
                if (!isolated || left == null || right == null || left.Kind != right.Kind)
                    return false;
                bool leftOwned = firstDeclarations.TryGetValue(left, out int leftIndex);
                bool rightOwned = secondDeclarations.TryGetValue(right, out int rightIndex);
                if (leftOwned || rightOwned)
                    return leftOwned && rightOwned && leftIndex == rightIndex;
                if (left is ITypeSymbol leftType && right is ITypeSymbol rightType &&
                    (left is not INamedTypeSymbol || right is not INamedTypeSymbol))
                    return TypesMatch(leftType, rightType);
                if (left is IParameterSymbol lp && right is IParameterSymbol rp)
                    return lp.Ordinal == rp.Ordinal && lp.Name == rp.Name && lp.RefKind == rp.RefKind &&
                        SymbolsMatch(lp.ContainingSymbol, rp.ContainingSymbol) && TypesMatch(lp.Type, rp.Type);
                if (left.Kind is not (SymbolKind.Namespace or SymbolKind.NamedType or SymbolKind.Field or
                    SymbolKind.Method or SymbolKind.Property or SymbolKind.Event))
                    return false;
                string identity = DocumentationCommentId.CreateDeclarationId(left);
                return HasDeclarationIdentity(right, identity) &&
                    Equals(left.ContainingAssembly?.Identity, right.ContainingAssembly?.Identity);
            }

            private static bool HasDeclarationIdentity(ISymbol symbol, string identity) =>
                identity != null && identity == DocumentationCommentId.CreateDeclarationId(symbol);

            public bool TypesMatch(ITypeSymbol left, ITypeSymbol right)
            {
                if (SymbolEqualityComparer.IncludeNullability.Equals(left, right))
                    return true;
                if (!isolated || left == null || right == null ||
                    left.TypeKind != right.TypeKind || left.NullableAnnotation != right.NullableAnnotation ||
                    left.TypeKind == TypeKind.Error)
                    return false;
                if (left is IPointerTypeSymbol lp && right is IPointerTypeSymbol rp)
                    return TypesMatch(lp.PointedAtType, rp.PointedAtType);
                if (left is IArrayTypeSymbol la && right is IArrayTypeSymbol ra)
                    return la.Rank == ra.Rank && la.IsSZArray == ra.IsSZArray && TypesMatch(la.ElementType, ra.ElementType);
                if (left is INamedTypeSymbol ln && right is INamedTypeSymbol rn)
                    return SymbolsMatch(ln.OriginalDefinition, rn.OriginalDefinition) &&
                        ln.TypeArguments.Length == rn.TypeArguments.Length &&
                        ln.TypeArguments.Zip(rn.TypeArguments).All(pair => TypesMatch(pair.First, pair.Second));
                return false;
            }

            private static Dictionary<ISymbol, int> DeclaredSymbols(StructDeclarationSyntax declaration, SemanticModel model)
            {
                var result = new Dictionary<ISymbol, int>(SymbolEqualityComparer.Default);
                int index = 0;
                foreach (var node in declaration.DescendantNodesAndSelf())
                {
                    var symbol = model.GetDeclaredSymbol(node);
                    if (symbol != null)
                        result.TryAdd(symbol, index);
                    index++;
                }
                foreach (var property in result.Keys.OfType<IPropertySymbol>().ToArray())
                {
                    foreach (var accessor in new[] { property.GetMethod, property.SetMethod }.Where(accessor => accessor != null))
                    {
                        for (int parameter = 0; parameter < property.Parameters.Length; parameter++)
                            if (result.TryGetValue(property.Parameters[parameter], out int declarationIndex))
                                result.TryAdd(accessor.Parameters[parameter], declarationIndex);
                    }
                }
                return result;
            }
        }

        // Record helper implementations are compared as syntax but are not emitted by the metadata writer.
        private static bool IsMemberImplementation(SyntaxNode node) => node.Ancestors().Any(ancestor =>
            ancestor is BlockSyntax { Parent: BaseMethodDeclarationSyntax or AccessorDeclarationSyntax } or
                ArrowExpressionClauseSyntax);

        internal static CSharpCompilation AddNetstandardReference(CSharpCompilation comp)
        {
            if (!comp.ReferencedAssemblyNames.Any(ran => ran.Name == "netstandard" && ran.Version.Major == 2 && ran.Version.Minor == 1))
            {
                var netstandardPath = FindNetstandardDllPath();
                if (!File.Exists(netstandardPath))
                {
                    throw new FileNotFoundException("Failed to find the netstandard DLL.");
                }

                comp = comp.AddReferences(MetadataReference.CreateFromFile(netstandardPath));
            }
            return comp;
        }

        public ReadOnlyCollection<Diagnostic> GetDiagnostics()
        {
            List<Diagnostic> diags = new List<Diagnostic>();
            var culture = new System.Globalization.CultureInfo("en-US");

            foreach (var diag in this.compilation.GetDeclarationDiagnostics())
            {
                if (diag.Severity == DiagnosticSeverity.Warning)
                {
                    continue;
                }

                // CS0208: Cannot take the address of, get the size of, or declare a pointer to a managed type
                // We can do this in metadata, so it's OK
                // CS0558: Operator, which we don't emit
                // CS0562: Operator, which we don't emit
                // CS0590: Operator, which we don't emit
                // CS0568: Ctor on structs, which we don't emit
                // CS0592: FieldOffset on a property which we don't emit
                // CS1745: Cannot specify default parameter value in conjunction with DefaultParameterAttribute or OptionalAttribute
                // CS0111: Operator
                if (diag.Id == "CS0208" || diag.Id == "CS0558" || diag.Id == "CS0562" || diag.Id == "CS0590" || diag.Id == "CS0568" || diag.Id == "CS0592" || diag.Id == "CS1745" ||
                    diag.Id == "CS0111")
                {
                    continue;
                }

                // CS0029: Cannot implicitly convert type 'string' to 'string[]'
                // Problem with ClangSharp that emits WCHAR Bar[] = "foo" into string[] Bar = "foo"
                // We work around this in the emitter
                if (diag.Id == "CS0029" && diag.ToString().Contains("'string' to 'string[]'"))
                {
                    continue;
                }

                // Symbol not found. See if it's in the type import list
                if (diag.Id == "CS0246")
                {
                    var symbolNameRegx = new System.Text.RegularExpressions.Regex(@"The type or namespace name '(\w+)'");
                    var match = symbolNameRegx.Match(diag.GetMessage(culture));
                    if (match.Success)
                    {
                        var symbolName = match.Groups[1].Value;
                        if (this.typeImports.ContainsKey(symbolName) || this.typeImports.ContainsKey($"{symbolName}(interface)"))
                        {
                            continue;
                        }
                    }
                }

                diags.Add(diag);
            }

            return diags.AsReadOnly();
        }

        private static bool IsValidCsSourceFile(string fileName, string arch)
        {
            if (fileName.EndsWith(".modified.cs"))
            {
                return false;
            }

            string potentialArch = Path.GetFileName(Path.GetDirectoryName(fileName));
            if (potentialArch == "x86" || potentialArch == "x64" || potentialArch == "arm64")
            {
                if (arch == "crossarch")
                {
                    return true;
                }
                else
                {
                    return arch == potentialArch;
                }
            }

            return true;
        }

        private static string FindNetstandardDllPath()
        {
            // Is there a better way to find this?
            string progFiles = Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles);
            return Path.Combine(progFiles, @"dotnet\packs\NETStandard.Library.Ref\2.1.0\ref\netstandard2.1\netstandard.dll");
        }

#if ShowMemoryInfo
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
        private class MEMORYSTATUSEX
        {
            public uint dwLength;
            public uint dwMemoryLoad;
            public ulong ullTotalPhys;
            public ulong ullAvailPhys;
            public ulong ullTotalPageFile;
            public ulong ullAvailPageFile;
            public ulong ullTotalVirtual;
            public ulong ullAvailVirtual;
            public ulong ullAvailExtendedVirtual;
            public MEMORYSTATUSEX()
            {
                this.dwLength = (uint)Marshal.SizeOf(typeof(MEMORYSTATUSEX));
            }
        }

        [return: MarshalAs(UnmanagedType.Bool)]
        [DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        static extern bool GlobalMemoryStatusEx([In, Out] MEMORYSTATUSEX lpBuffer);
#endif

        private class TreeInfoFinder : CSharpSyntaxWalker
        {
            public TreeInfoFinder()
            {
            }

            public HashSet<string> EmptyStructs { get; } = new HashSet<string>();

            public HashSet<string> EnumMemberNames { get; } = new HashSet<string>();


            public void AnalyzeTree(SyntaxTree tree)
            {
                this.Visit(tree.GetRoot());
            }

            public override void VisitEnumMemberDeclaration(EnumMemberDeclarationSyntax node)
            {
                lock (this.EnumMemberNames)
                {
                    this.EnumMemberNames.Add(MetadataSyntaxTreeCleaner.GetEnumMemberIdentity(node, node.Identifier.ValueText));
                }

                base.VisitEnumMemberDeclaration(node);
            }

            public override void VisitStructDeclaration(StructDeclarationSyntax node)
            {
                if (!SyntaxUtils.IsEmptyStruct(node))
                {
                    lock (this.EmptyStructs)
                    {
                        this.EmptyStructs.Add(node.Identifier.ValueText);
                    }
                }
            }
        }
    }
}

//#define MakeSingleThreaded
//#define ShowMemoryInfo

using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using MetadataUtils;

namespace ClangSharpSourceToWinmd
{
    public class ClangSharpSourceCompilation
    {
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
            return CSharpSyntaxTree.ParseText(File.ReadAllText(fileName), null, fileName);
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

        private static void ValidateHeaderTypesFamilies(IEnumerable<string> files)
        {
            var paths = new HashSet<string>(files, StringComparer.OrdinalIgnoreCase);
            foreach (string file in paths.Where(HeaderEnumGroupMerger.IsHeaderTypesFile))
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
                    !siblings.Skip(1).Any(sibling => Path.GetFileName(file) == "header-types.modified.cs"
                        ? paths.Any(path => string.Equals(Path.GetDirectoryName(path), Path.GetDirectoryName(sibling),
                            StringComparison.OrdinalIgnoreCase))
                        : paths.Contains(sibling.Replace(".header-types.modified.cs", ".modified.cs", StringComparison.Ordinal)));
                if (!common)
                    throw new InvalidOperationException($"CSSW004: Incomplete successful header-types source family '{file}'. " +
                        "Supply all three successfully generated companions, including successful empty outputs; missing or failed profiles are not empty outputs.");
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
            bool nativeFieldArrayInfo = false)
        {
            sourceDirectory = Path.GetFullPath(sourceDirectory);

            string topObjDir = Path.Combine(sourceDirectory, $"obj");
            if (Directory.Exists(topObjDir))
            {
                Directory.Delete(topObjDir, true);
            }

            string objDir = Path.Combine(topObjDir, arch);
            Directory.CreateDirectory(objDir);

            var refs = (addedRefs ?? Enumerable.Empty<string>()).Select(r => MetadataReference.CreateFromFile(r)).ToArray();
            IReadOnlyDictionary<string, string> fieldRenames = new Dictionary<string, string>();

            TreeInfoFinder infoFinder = new TreeInfoFinder();

            List<string> modifiedFiles = new List<string>();
            var sourceFiles = Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories).Where(f => IsValidCsSourceFile(f, arch));
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

            if (arch == "crossarch")
                ValidateHeaderTypesFamilies(modifiedFiles);

            System.Diagnostics.Stopwatch watch = System.Diagnostics.Stopwatch.StartNew();

            Console.WriteLine($"  Moving names to correct namespaces...");
            System.Threading.Tasks.Parallel.ForEach(modifiedFiles, opt, (treeFile) =>
            {
                if (!treeFile.EndsWith(".manual.cs"))
                {
                    var tree = ReadTree(treeFile);
                    // Loose constants retain their source namespace when their owning enum is routed elsewhere.
                    infoFinder.AnalyzeTree(tree);
                    tree = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree, requiredNamespaces);

                    infoFinder.AnalyzeTree(tree);

                    WriteTree(tree, treeFile);
                }
            });

            var elapsed = watch.Elapsed;
            Console.WriteLine($"  {OutputUtils.FormatTimespan(elapsed)}");

            ShowMemory();

            HeaderEnumGroupMerger.Merge(modifiedFiles, objDir, arch, infoFinder.EnumMemberNames);

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
                var cleanedTree = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, remaps, enumAdditions, enumsMakeFlagsHashSet, requiredNamespaces, staticLibs, apiNamesToNamespaces, infoFinder.EmptyStructs, enumMemberNames, tree.FilePath, nativeFieldArrayInfo);
                WriteTree(cleanedTree, cleanedTree.FilePath);
            });

            Console.WriteLine($"  {OutputUtils.FormatTimespan(watch.Elapsed)}");
            ShowMemory();

            if (arch == "crossarch")
            {
                foreach (var tree in CrossArchConstantQualifier.Qualify(FilesToTrees(modifiedFiles).ToArray(), refs))
                    WriteTree(tree, tree.FilePath);
                List<string> partitionsNotNeedingCrossarch = new List<string>();

                Console.WriteLine($"  Merging cross-arch items...");
                watch.Restart();

                List<string> filesToMerge = new List<string>();
                foreach (string x86FileName in modifiedFiles.Where(f => GetArchitectureForFileName(f) == Architecture.X86))
                {
                    string x64FileName = x86FileName.Replace(@"\x86\", @"\x64\", StringComparison.OrdinalIgnoreCase);
                    string arm64FileName = x86FileName.Replace(@"\x86\", @"\arm64\", StringComparison.OrdinalIgnoreCase);

                    if (File.Exists(x64FileName) && File.Exists(arm64FileName))
                    {
                        string x86Content = File.ReadAllText(x86FileName);
                        if (x86Content == File.ReadAllText(x64FileName) && x86Content == File.ReadAllText(arm64FileName))
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

                CrossArchSyntaxMap crossArchSyntaxMap = LoadCrossArchMapFromFiles(filesToMerge, opt);
                HashSet<string> nonX86TreesUsedForX86 = crossArchSyntaxMap.Get64BitTreesUsedForX86();

                CrossArchTreeMerger crossArchTreeMerger = new CrossArchTreeMerger(crossArchSyntaxMap,
                    FilesToTrees(modifiedFiles.Where(File.Exists)));
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

            comp = MergeRepeatedStructs(comp);
            comp = MergeLegacyTypedefProjections(comp, requiredNamespaces);
            comp = HeaderTypedefMerger.Merge(comp);
            comp = HeaderTypedefMerger.LowerConstants(comp);
            comp = HeaderEnumGroupMerger.ConvertPrimitiveConstantAliases(comp);
            HeaderEnumGroupMerger.ValidateAssociations(comp, arch);

            Console.WriteLine($"  {OutputUtils.FormatTimespan(watch.Elapsed)}");
            ShowMemory();

            return new ClangSharpSourceCompilation(comp, typeImports, fieldRenames);
        }

        private static CSharpCompilation MergeRepeatedStructs(CSharpCompilation compilation)
        {
            var removals = new HashSet<StructDeclarationSyntax>();
            var groups = compilation.SyntaxTrees.Where(tree =>
                !tree.FilePath.EndsWith("manual.cs", StringComparison.OrdinalIgnoreCase) &&
                !HeaderEnumGroupMerger.IsHeaderTypesFile(tree.FilePath))
                .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                .Where(declaration => declaration.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax &&
                    declaration.Modifiers.Any(SyntaxKind.PartialKeyword) &&
                    declaration.TypeParameterList == null && declaration.BaseList == null &&
                    declaration.Members.All(member => member is FieldDeclarationSyntax field &&
                        !field.Modifiers.Any(SyntaxKind.ConstKeyword) && !field.Modifiers.Any(SyntaxKind.StaticKeyword) &&
                        field.Declaration.Variables.All(variable => variable.Initializer == null)))
                .GroupBy(declaration => $"{SyntaxUtils.GetEnclosingNamespace(declaration)}.{declaration.Identifier.ValueText}",
                    StringComparer.Ordinal).Where(group => group.Count() > 1);
            foreach (var group in groups)
            {
                var copies = group.OrderBy(declaration => declaration.SyntaxTree.FilePath, StringComparer.Ordinal).ToArray();
                if (copies.Select(declaration => declaration.SyntaxTree).Distinct().Count() != copies.Length ||
                    copies.Skip(1).Any(declaration => !SyntaxFactory.AreEquivalent(copies[0], declaration)))
                    continue;
                var firstModel = compilation.GetSemanticModel(copies[0].SyntaxTree);
                var firstSymbol = firstModel.GetDeclaredSymbol(copies[0]);
                if (firstSymbol == null)
                    continue;
                // Identical text can refer to different field types or annotation arguments through using aliases.
                if (copies.Skip(1).Any(declaration =>
                {
                    var model = compilation.GetSemanticModel(declaration.SyntaxTree);
                    return !SymbolEqualityComparer.Default.Equals(firstSymbol, model.GetDeclaredSymbol(declaration)) ||
                        !BindingsMatch(copies[0], firstModel, declaration, model);
                }))
                    continue;
                removals.UnionWith(copies.Skip(1));
            }
            return RemoveStructs(compilation, removals);
        }

        private static CSharpCompilation MergeLegacyTypedefProjections(CSharpCompilation compilation,
            IReadOnlyDictionary<string, string> requiredNamespaces)
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
                        throw new InvalidOperationException($"Legacy typedef projection '{declaration.Identifier.ValueText}' " +
                            $"conflicts with the established manual provider '{identity}'.");
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
            StructDeclarationSyntax second, SemanticModel secondModel, bool ignoreDocumentation = false)
        {
            var firstNodes = first.DescendantNodes().Where(node => node is ExpressionSyntax or AttributeSyntax)
                .Where(node => !ignoreDocumentation || !node.AncestorsAndSelf().OfType<AttributeSyntax>()
                    .Any(attribute => IsDocumentationAttribute(attribute, firstModel))).ToArray();
            var secondNodes = second.DescendantNodes().Where(node => node is ExpressionSyntax or AttributeSyntax)
                .Where(node => !ignoreDocumentation || !node.AncestorsAndSelf().OfType<AttributeSyntax>()
                    .Any(attribute => IsDocumentationAttribute(attribute, secondModel))).ToArray();
            if (firstNodes.Length != secondNodes.Length)
                return false;
            for (int i = 0; i < firstNodes.Length; i++)
            {
                var left = firstModel.GetSymbolInfo(firstNodes[i]);
                var right = secondModel.GetSymbolInfo(secondNodes[i]);
                if (left.CandidateReason != CandidateReason.None || right.CandidateReason != CandidateReason.None ||
                    !SymbolEqualityComparer.Default.Equals(left.Symbol, right.Symbol))
                    return false;
                if (firstNodes[i] is ExpressionSyntax leftExpression && secondNodes[i] is ExpressionSyntax rightExpression)
                {
                    var leftType = firstModel.GetTypeInfo(leftExpression);
                    var rightType = secondModel.GetTypeInfo(rightExpression);
                    if (leftType.Type?.TypeKind == TypeKind.Error || rightType.Type?.TypeKind == TypeKind.Error ||
                        !SymbolEqualityComparer.IncludeNullability.Equals(leftType.Type, rightType.Type) ||
                        !SymbolEqualityComparer.IncludeNullability.Equals(leftType.ConvertedType, rightType.ConvertedType))
                        return false;
                }
            }
            return true;
        }

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

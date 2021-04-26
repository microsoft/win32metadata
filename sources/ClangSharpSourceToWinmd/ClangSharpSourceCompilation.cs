//#define MakeSingleThreaded

using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using PartitionUtilsLib;

namespace ClangSharpSourceToWinmd
{
    public class ClangSharpSourceCompilation
    {
        private CSharpCompilation compilation;
        private Dictionary<string, string> typeImports;

        private ClangSharpSourceCompilation(CSharpCompilation compilation, Dictionary<string, string> typeImports)
        {
            this.compilation = compilation;
            this.typeImports = typeImports;
        }

        public CSharpCompilation CSharpCompilation => this.compilation;

        public static ClangSharpSourceCompilation Create(
            string sourceDirectory,
            string arch,
            string interopFileName,
            string baseMetadataFileName,
            string outputNamespace,
            Dictionary<string, string> remaps,
            Dictionary<string, Dictionary<string, string>> enumAdditions,
            IEnumerable<string> enumsMakeFlags,
            Dictionary<string, string> typeImports,
            Dictionary<string, string> requiredNamespaces,
            HashSet<string> reducePointerLevels)
        {
            sourceDirectory = Path.GetFullPath(sourceDirectory);

            var netstandardPath = FindNetstandardDllPath();
            if (!File.Exists(netstandardPath))
            {
                throw new FileNotFoundException("Failed to find the netstandard DLL.");
            }

            List<MetadataReference> refs = new List<MetadataReference>();
            refs.Add(MetadataReference.CreateFromFile(interopFileName));
            refs.Add(MetadataReference.CreateFromFile(netstandardPath));

            if (!string.IsNullOrEmpty(baseMetadataFileName))
            {
                refs.Add(MetadataReference.CreateFromFile(baseMetadataFileName));
            }

            List<SyntaxTree> syntaxTrees = new List<SyntaxTree>();
            var sourceFiles = Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories).Where(f => IsValidCsSourceFile(f, arch));
            if (!string.IsNullOrEmpty(outputNamespace))
            {
                var matchingFilenames = new[] {
                    $@"\{outputNamespace}.",
                    @"\autotypes.",
                };

                sourceFiles = sourceFiles.Where(f => matchingFilenames.Any(m => f.Contains(m, StringComparison.OrdinalIgnoreCase)));
            }
            System.Threading.Tasks.ParallelOptions opt = new System.Threading.Tasks.ParallelOptions() { MaxDegreeOfParallelism = Environment.ProcessorCount * 2 };
            System.Threading.Tasks.Parallel.ForEach(sourceFiles, opt, (sourceFile) =>
            {
                string fileToRead = Path.GetFullPath(sourceFile);
                var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(fileToRead), null, fileToRead);

                lock (syntaxTrees)
                {
                    syntaxTrees.Add(tree);
                }
            });

            syntaxTrees = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(syntaxTrees, requiredNamespaces);

            if (arch == "crossarch")
            {
                CrossArchSyntaxMap crossArchSyntaxMap = CrossArchSyntaxMap.LoadFromTrees(syntaxTrees);
                syntaxTrees = CrossArchTreeMerger.MergeTrees(crossArchSyntaxMap, syntaxTrees);
            }

            HashSet<string> foundNonEmptyStructs = GetNonEmptyStructs(syntaxTrees);

#if MakeSingleThreaded
            opt.MaxDegreeOfParallelism = 1;
#endif

            string objDir = Path.Combine(sourceDirectory, $"obj\\{arch}");
            Directory.CreateDirectory(objDir);

            HashSet<string> enumsMakeFlagsHashSet = enumsMakeFlags != null ? new HashSet<string>(enumsMakeFlags) : new HashSet<string>();
            List<SyntaxTree> cleanedTrees = new List<SyntaxTree>();
            System.Threading.Tasks.Parallel.ForEach(syntaxTrees, opt, (tree) =>
            {
                // Turn c:\dir\generated\foo.cs into c:\dir\generated\obj\foo.modified.cs

                string modifiedFile = Path.ChangeExtension(tree.FilePath, ".modified.cs");
                string fileWithSubDir = modifiedFile.Substring(sourceDirectory.Length);
                if (fileWithSubDir.StartsWith('\\'))
                {
                    fileWithSubDir = fileWithSubDir.Substring(1);
                }

                modifiedFile = Path.Combine(objDir, fileWithSubDir);

                // e.g. c:\dir\generated\obj
                string newSubDir = Path.GetDirectoryName(modifiedFile);
                if (!Directory.Exists(newSubDir))
                {
                    Directory.CreateDirectory(newSubDir);
                }

                var cleanedTree = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, remaps, enumAdditions, enumsMakeFlagsHashSet, requiredNamespaces, foundNonEmptyStructs, modifiedFile);
                File.WriteAllText(modifiedFile, cleanedTree.GetText().ToString());

                lock (cleanedTrees)
                {
                    cleanedTrees.Add(cleanedTree);
                }
            });

            CSharpCompilationOptions compilationOptions = new CSharpCompilationOptions(OutputKind.WindowsRuntimeMetadata, allowUnsafe: true);
            var comp =
                CSharpCompilation.Create(
                    null,
                    cleanedTrees,
                    refs,
                    compilationOptions);

            return new ClangSharpSourceCompilation(comp, typeImports);
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
                        if (this.typeImports.ContainsKey(symbolName) || typeImports.ContainsKey($"{symbolName}(interface)"))
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
            if (fileName.EndsWith("modified.cs"))
            {
                return false;
            }

            string potentialArch = Path.GetFileName(Path.GetDirectoryName(fileName));
            if (potentialArch == "x86" || potentialArch == "x64" || potentialArch == "arm64")
            {
                if (arch == "crossarch")
                {
                    if (potentialArch != "x64" && (fileName.EndsWith("autotypes.cs") || fileName.EndsWith(".enums.cs") || fileName.EndsWith(".constants.cs")))
                    {
                        return false;
                    }

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

        private static HashSet<string> GetNonEmptyStructs(List<SyntaxTree> trees)
        {
            HashSet<string> foundStructs = new HashSet<string>();
            foreach (var tree in trees)
            {
                NonEmptyStructFinder finder = new NonEmptyStructFinder(foundStructs, tree);
            }

            return foundStructs;
        }

        private class NonEmptyStructFinder : CSharpSyntaxWalker
        {
            private HashSet<string> foundStructs;

            public NonEmptyStructFinder(HashSet<string> foundStructs, SyntaxTree tree)
            {
                this.foundStructs = foundStructs;
                this.Visit(tree.GetRoot());
            }

            public override void VisitStructDeclaration(StructDeclarationSyntax node)
            {
                if (!SyntaxUtils.IsEmptyStruct(node))
                {
                    this.foundStructs.Add(node.Identifier.ValueText);
                }
            }
        }
    }
}

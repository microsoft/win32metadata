//#define MakeSingleThreaded

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

        private ClangSharpSourceCompilation(CSharpCompilation compilation, Dictionary<string, string> typeImports)
        {
            this.compilation = compilation;
            this.typeImports = typeImports;
        }

        internal static void ShowMemory()
        {
            double mem = (double)GC.GetTotalMemory(true) / (1024 * 1024 * 1024);
            Console.WriteLine($"Current memory: {mem}");
        }

        public CSharpCompilation CSharpCompilation => this.compilation;

        public static ClangSharpSourceCompilation Create(
            string sourceDirectory,
            string arch,
            string interopFileName,
            Dictionary<string, string> remaps,
            Dictionary<string, Dictionary<string, string>> enumAdditions,
            IEnumerable<string> enumsMakeFlags,
            Dictionary<string, string> typeImports,
            Dictionary<string, string> requiredNamespaces,
            HashSet<string> reducePointerLevels,
            IEnumerable<string> addedRefs,
            Dictionary<string, string> staticLibs)
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

            if (addedRefs != null)
            {
                foreach (var r in addedRefs)
                {
                    refs.Add(MetadataReference.CreateFromFile(r));
                }
            }

            List<SyntaxTree> syntaxTrees = new List<SyntaxTree>();
            var sourceFiles = Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories).Where(f => IsValidCsSourceFile(f, arch));
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

            Console.WriteLine($"Moving names to correct namespaces...");
            ShowMemory();

            syntaxTrees = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(syntaxTrees, requiredNamespaces);

            GetTreeInfo(syntaxTrees, out var emptyStucts, out var enumMemberNames);

#if MakeSingleThreaded
            opt.MaxDegreeOfParallelism = 1;
#endif

            string objDir = Path.Combine(sourceDirectory, $"obj\\{arch}");
            Directory.CreateDirectory(objDir);

            Console.WriteLine($"Cleaning trees with {opt.MaxDegreeOfParallelism} threads...");
            ShowMemory();

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

                var cleanedTree = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, remaps, enumAdditions, enumsMakeFlagsHashSet, requiredNamespaces, staticLibs, emptyStucts, enumMemberNames, modifiedFile);

                lock (cleanedTrees)
                {
                    cleanedTrees.Add(cleanedTree);
                }
            });

            Console.WriteLine($"Merging trees...");
            ShowMemory();

            if (arch == "crossarch")
            {
                CrossArchSyntaxMap crossArchSyntaxMap = CrossArchSyntaxMap.LoadFromTrees(cleanedTrees);
                cleanedTrees = CrossArchTreeMerger.MergeTrees(crossArchSyntaxMap, cleanedTrees);
            }

            foreach (var cleanedTree in cleanedTrees)
            {
                File.WriteAllText(cleanedTree.FilePath, cleanedTree.GetText().ToString());
            }

            Console.WriteLine($"Calling C# compiler on processed trees...");
            ShowMemory();

            CSharpCompilationOptions compilationOptions = new CSharpCompilationOptions(OutputKind.WindowsRuntimeMetadata, allowUnsafe: true);
            var comp =
                CSharpCompilation.Create(
                    null,
                    cleanedTrees,
                    refs,
                    compilationOptions);

            Console.WriteLine($"C# compiler done");
            ShowMemory();

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

        private static void GetTreeInfo(List<SyntaxTree> trees, out HashSet<string> emptyStructs, out HashSet<string> enumMemberNames)
        {
            emptyStructs = new HashSet<string>();
            enumMemberNames = new HashSet<string>();
            foreach (var tree in trees)
            {
                TreeInfoFinder finder = new TreeInfoFinder(emptyStructs, enumMemberNames, tree);
            }
        }

        private class TreeInfoFinder : CSharpSyntaxWalker
        {
            private HashSet<string> emptyStructs;
            private HashSet<string> enumMemberNames;

            public TreeInfoFinder(HashSet<string> emptyStructs, HashSet<string> enumMemberNames, SyntaxTree tree)
            {
                this.emptyStructs = emptyStructs;
                this.enumMemberNames = enumMemberNames;
                this.Visit(tree.GetRoot());
            }

            public override void VisitEnumMemberDeclaration(EnumMemberDeclarationSyntax node)
            {
                this.enumMemberNames.Add(node.Identifier.ValueText);
                base.VisitEnumMemberDeclaration(node);
            }

            public override void VisitStructDeclaration(StructDeclarationSyntax node)
            {
                if (!SyntaxUtils.IsEmptyStruct(node))
                {
                    this.emptyStructs.Add(node.Identifier.ValueText);
                }
            }
        }
    }
}

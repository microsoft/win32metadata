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
            double beforeMem = (double)GC.GetTotalMemory(false) / (1024 * 1024 * 1024);
            double afterMem = (double)GC.GetTotalMemory(true) / (1024 * 1024 * 1024);
            Console.WriteLine($"Current memory: before GC {beforeMem}, after GC {afterMem}");
        }

        public CSharpCompilation CSharpCompilation => this.compilation;

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

            string objDir = Path.Combine(sourceDirectory, $"obj\\{arch}");
            Directory.CreateDirectory(objDir);

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

            TreeInfoFinder infoFinder = new TreeInfoFinder();

            //List<SyntaxTree> syntaxTrees = new List<SyntaxTree>();
            List<string> treeFiles = new List<string>();
            var sourceFiles = Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories).Where(f => IsValidCsSourceFile(f, arch));
            System.Threading.Tasks.ParallelOptions opt = new System.Threading.Tasks.ParallelOptions(); // { MaxDegreeOfParallelism = Environment.ProcessorCount * 2 };

#if MakeSingleThreaded
            opt.MaxDegreeOfParallelism = 1;
#endif

            System.Threading.Tasks.Parallel.ForEach(sourceFiles, opt, (sourceFile) =>
            {
                string treeFile = Path.GetFullPath(sourceFile);

                string modifiedFile = Path.ChangeExtension(treeFile, ".modified.cs");
                string fileWithSubDir = modifiedFile.Substring(sourceDirectory.Length);
                if (fileWithSubDir.StartsWith('\\'))
                {
                    fileWithSubDir = fileWithSubDir.Substring(1);
                }

                modifiedFile = Path.Combine(objDir, fileWithSubDir);

                if (!treeFile.EndsWith("manual.cs"))
                {
                    var tree = ReadTree(treeFile);
                    tree = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree, requiredNamespaces);

                    infoFinder.AnalyzeTree(tree);
                    // Turn c:\dir\generated\foo.cs into c:\dir\generated\obj\foo.modified.cs

                    WriteTree(tree, modifiedFile);
                }
                else
                {
                    var dir = Path.GetDirectoryName(modifiedFile);
                    if (!Directory.Exists(dir))
                    {
                        Directory.CreateDirectory(dir);
                    }

                    File.Copy(treeFile, modifiedFile, true);
                }

                lock (treeFiles)
                {
                    treeFiles.Add(modifiedFile);
                }
            });

            ShowMemory();
            //Console.WriteLine($"Moving names to correct namespaces...");

            //syntaxTrees = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(syntaxTrees, requiredNamespaces);

            //GetTreeInfo(syntaxTrees, out var emptyStucts, out var enumMemberNames);

            //Console.WriteLine($"Done moving names to correct namespaces.");
            //ShowMemory();

            Console.WriteLine($"Cleaning trees with {opt.MaxDegreeOfParallelism} threads...");

            HashSet<string> enumsMakeFlagsHashSet = enumsMakeFlags != null ? new HashSet<string>(enumsMakeFlags) : new HashSet<string>();
            //List<SyntaxTree> cleanedTrees = new List<SyntaxTree>();
            System.Threading.Tasks.Parallel.ForEach(FilesToTrees(treeFiles), opt, (tree) =>
            {
                // Turn c:\dir\generated\foo.cs into c:\dir\generated\obj\foo.modified.cs

                //string modifiedFile = Path.ChangeExtension(tree.FilePath, ".modified.cs");
                //string fileWithSubDir = modifiedFile.Substring(sourceDirectory.Length);
                //if (fileWithSubDir.StartsWith('\\'))
                //{
                //    fileWithSubDir = fileWithSubDir.Substring(1);
                //}

                //modifiedFile = Path.Combine(objDir, fileWithSubDir);

                //// e.g. c:\dir\generated\obj
                //string newSubDir = Path.GetDirectoryName(modifiedFile);
                //if (!Directory.Exists(newSubDir))
                //{
                //    Directory.CreateDirectory(newSubDir);
                //}

                var cleanedTree = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, remaps, enumAdditions, enumsMakeFlagsHashSet, requiredNamespaces, staticLibs, infoFinder.EmptyStructs, infoFinder.EnumMemberNames, tree.FilePath);
                WriteTree(cleanedTree, cleanedTree.FilePath);

                //lock (cleanedTrees)
                //{
                //    cleanedTrees.Add(cleanedTree);
                //}
            });

            Console.WriteLine($"Done cleaning trees.");
            ShowMemory();

            Console.WriteLine($"Merging trees...");

            if (arch == "crossarch")
            {
                CrossArchSyntaxMap crossArchSyntaxMap = CrossArchSyntaxMap.LoadFromTrees(FilesToTrees(treeFiles));
                CrossArchTreeMerger.CrossArchTreeRewriter crossArchTreeRewriter = new CrossArchTreeMerger.CrossArchTreeRewriter(crossArchSyntaxMap);
                foreach (var tree in FilesToTrees(treeFiles))
                {
                    var fixedTree = crossArchTreeRewriter.ProcessTree(tree);
                    WriteTree(fixedTree, fixedTree.FilePath);
                }
            }
             
            //foreach (var cleanedTree in cleanedTrees)
            //{
            //    File.WriteAllText(cleanedTree.FilePath, cleanedTree.GetText().ToString());
            //}

            Console.WriteLine($"Done merging trees.");
            ShowMemory();

            Console.WriteLine($"Calling C# compiler on processed trees...");

            CSharpCompilationOptions compilationOptions = new CSharpCompilationOptions(OutputKind.WindowsRuntimeMetadata, allowUnsafe: true);
            var comp =
                CSharpCompilation.Create(
                    null,
                    FilesToTrees(treeFiles),
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

        //private static void GetTreeInfo(List<SyntaxTree> trees, out HashSet<string> emptyStructs, out HashSet<string> enumMemberNames)
        //{
        //    emptyStructs = new HashSet<string>();
        //    enumMemberNames = new HashSet<string>();
        //    foreach (var tree in trees)
        //    {
        //        _ = new TreeInfoFinder(emptyStructs, enumMemberNames, tree);
        //    }
        //}

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
                    this.EnumMemberNames.Add(node.Identifier.ValueText);
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

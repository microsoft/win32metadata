using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Text;

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
            string interopFileName,
            Dictionary<string, string> remaps,
            Dictionary<string, string> typeImports,
            Dictionary<string, string> requiredNamespaces)
        {
            var netstandardPath = FindNetstandardDllPath();
            if (!File.Exists(netstandardPath))
            {
                throw new FileNotFoundException("Failed to find the netstandard DLL.");
            }

            List<MetadataReference> refs = new List<MetadataReference>();
            refs.Add(MetadataReference.CreateFromFile(interopFileName));
            refs.Add(MetadataReference.CreateFromFile(netstandardPath));

            List<SyntaxTree> syntaxTrees = new List<SyntaxTree>();
            var sourceFiles = Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories);
            System.Threading.Tasks.ParallelOptions opt = new System.Threading.Tasks.ParallelOptions() { MaxDegreeOfParallelism = Environment.ProcessorCount * 2 };
            System.Threading.Tasks.Parallel.ForEach(sourceFiles, opt, (sourceFile) =>
            {
                if (sourceFile.EndsWith("modified.cs"))
                {
                    return;
                }

                string fileToRead = Path.GetFullPath(sourceFile);
                var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(fileToRead), null, fileToRead);

                lock (syntaxTrees)
                {
                    syntaxTrees.Add(tree);
                }
            });

            HashSet<string> foundNonEmptyStructs = GetNonEmptyStructs(syntaxTrees);

            List<SyntaxTree> cleanedTrees = new List<SyntaxTree>();
            System.Threading.Tasks.Parallel.ForEach(syntaxTrees, opt, (tree) =>
            {
                string modifiedFile = Path.ChangeExtension(tree.FilePath, ".modified.cs");
                var cleanedTree = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, remaps, requiredNamespaces, foundNonEmptyStructs, modifiedFile);
                File.WriteAllText(modifiedFile, tree.GetText().ToString());

                lock (cleanedTrees)
                {
                    cleanedTrees.Add(cleanedTree);
                }
            });

            CSharpCompilationOptions compilationOptions = new CSharpCompilationOptions(OutputKind.WindowsRuntimeMetadata, allowUnsafe: true);
            var comp =
                CSharpCompilation.Create(
                    //Path.GetFileName(outputFileName),
                    null,
                    cleanedTrees,
                    refs,
                    compilationOptions);

            return new ClangSharpSourceCompilation(comp, typeImports);
        }

        public ReadOnlyCollection<Diagnostic> GetDiagnostics()
        {
            List<Diagnostic> diags = new List<Diagnostic>();

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
                    var match = symbolNameRegx.Match(diag.GetMessage());
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
                if (node.Members.Count != 0 || node.AttributeLists.Count != 0)
                {
                    this.foundStructs.Add(node.Identifier.ValueText);
                }
            }
        }
    }
}

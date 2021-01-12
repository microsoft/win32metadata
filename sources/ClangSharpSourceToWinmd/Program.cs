using System;
using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;

namespace ClangSharpSourceToWinmd
{
    public static class Program
    {
        public static int Main(string[] args)
        {
            var rootCommand = new RootCommand("Convert ClangSharp-generated code into metadata")
            {
                new Option<string>(new[] { "--sourceDir", "-s" }, "The location of the source files.") { IsRequired = true },
                new Option<string>(new[] { "--interopFileName", "-i" }, "The path to Windows.Win32.Interop.dll") { IsRequired = true },
                new Option<string>(new[] { "--outputFileName", "-o" }, "The path to the .winmd to create") { IsRequired = true },
                new Option<string>(new[] { "--version", "-v"}, description: "The version to use on the .winmd", getDefaultValue: () => "1.0.0.0"),
                new Option(new string[] { "--remap", "-r" }, "A declaration name to be remapped to another name during binding generation.")
                {
                    Argument = new Argument("<name>=<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
                new Option(new string[] { "--typeImport", "-t" }, "A type to be imported from another assembly.")
                {
                    Argument = new Argument("<name>=<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                }
            };

            rootCommand.Handler = CommandHandler.Create(typeof(Program).GetMethod(nameof(Run)));

            return rootCommand.Invoke(args);
        }

        public static int Run(InvocationContext context)
        {
            string sourceDirectory = context.ParseResult.ValueForOption<string>("sourceDir");
            string interopFileName = context.ParseResult.ValueForOption<string>("interopFileName");
            string outputFileName = context.ParseResult.ValueForOption<string>("outputFileName");
            string version = context.ParseResult.ValueForOption<string>("version");
            var remappedNameValuePairs = context.ParseResult.ValueForOption<string[]>("remap");
            var typeImportValuePairs = context.ParseResult.ValueForOption<string[]>("typeImport");

            var remaps = ConvertValuePairsToDictionary(remappedNameValuePairs);
            var typeImports = ConvertValuePairsToDictionary(typeImportValuePairs);

            string rawVersion = version.Split('-')[0];
            Version assemblyVersion = Version.Parse(rawVersion);

            var netstandardPath = FindNetstandardDllPath();
            if (!File.Exists(netstandardPath))
            {
                Console.WriteLine($"Error: Failed to find {netstandardPath}.");
                return 1;
            }

            List<MetadataReference> refs = new List<MetadataReference>();
            refs.Add(MetadataReference.CreateFromFile(interopFileName));
            refs.Add(MetadataReference.CreateFromFile(netstandardPath));

            Console.Write($"Compiling source files...");
            System.Diagnostics.Stopwatch watch = System.Diagnostics.Stopwatch.StartNew();

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
                    string modifiedFile = Path.ChangeExtension(fileToRead, ".modified.cs");
                    var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(fileToRead), null, modifiedFile);
                    tree = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, remaps);
                    File.WriteAllText(modifiedFile, tree.GetText().ToString());

                    lock (syntaxTrees)
                    {
                        syntaxTrees.Add(tree);
                    }
                });

            CSharpCompilationOptions compilationOptions = new CSharpCompilationOptions(OutputKind.WindowsRuntimeMetadata, allowUnsafe: true);
            var comp =
                CSharpCompilation.Create(
                    Path.GetFileName(outputFileName),
                    syntaxTrees,
                    refs,
                    compilationOptions);

            Console.Write("looking for errors...");
            var diags = comp.GetDeclarationDiagnostics();

            watch.Stop();

            int errors = 0;
            const int MaxErrorsToShow = 10000;
            foreach (var diag in diags)
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
                        if (typeImports.ContainsKey(symbolName) || typeImports.ContainsKey($"{symbolName}(interface)"))
                        {
                            continue;
                        }
                    }
                }

                if (errors == 0)
                {
                    Console.WriteLine("errors were found.");
                }

                errors++;
                Console.WriteLine(diag.ToString());
                if (errors >= MaxErrorsToShow)
                {
                    Console.WriteLine($"Only showing the first {MaxErrorsToShow} errors.");
                    break;
                }
            }

            if (errors > 0)
            {
                return -1;
            }

            string timeTaken = watch.Elapsed.ToString("c");

            Console.WriteLine($"took {timeTaken}");

            Console.WriteLine($"Emitting {outputFileName}...");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(comp, typeImports, assemblyVersion, outputFileName);

            foreach (var diag in generator.GetDiagnostics())
            {
                Console.WriteLine($"{diag.Severity}: {diag.Message}");
            }

            return generator.WroteWinmd ? 0 : -1;
        }

        private static string FindNetstandardDllPath()
        {
            // Is there a better way to find this?
            string progFiles = Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles);
            return Path.Combine(progFiles, @"dotnet\packs\NETStandard.Library.Ref\2.1.0\ref\netstandard2.1\netstandard.dll");
        }

        private static Command WithHandler(this RootCommand command, string name)
        {
            var flags = BindingFlags.NonPublic | BindingFlags.Static;
            var method = typeof(Program).GetMethod(name, flags);

            var handler = CommandHandler.Create(method!);
            command.Handler = handler;
            return command;
        }

        private static Dictionary<string, string> ConvertValuePairsToDictionary(string[] items)
        {
            Dictionary<string, string> ret = new Dictionary<string, string>();
            foreach (var item in items)
            {
                if (string.IsNullOrEmpty(item))
                {
                    continue;
                }

                int firstEqual = item.IndexOf('=');
                if (firstEqual != -1)
                {
                    string name = item.Substring(0, firstEqual);
                    string value = item.Substring(firstEqual + 1);
                    ret[name] = value;
                }
            }

            return ret;
        }
    }
}

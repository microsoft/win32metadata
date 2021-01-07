using System;
using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using System.Linq;
using System.Reflection;
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
                    string fileToRead = Path.GetFullPath(sourceFile);
                    var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(fileToRead), null, fileToRead);
                    tree = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, remaps);

                    lock (syntaxTrees)
                    {
                        syntaxTrees.Add(tree);
                    }
                });

            watch.Stop();

            string timeTaken = watch.Elapsed.ToString("c");
            Console.WriteLine($"took {timeTaken}");

            var comp =
                CSharpCompilation.Create(
                    Path.GetFileName(outputFileName),
                    syntaxTrees,
                    refs);

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

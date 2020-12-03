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
                new Option<string>(new[] { "--sourceDir", "-s" }, "The location of the source files."),
                new Option<string>(new[] { "--interopFileName", "-i" }, "The path to Microsoft.Windows.Sdk.Win32.Interop.dll"),
                new Option<string>(new[] { "--outputFileName", "-o" }, "The path to the .winmd to create"),
                new Option<string>(new[] { "--version", "-v"}, description: "The version to use on the .winmd", getDefaultValue: () => "1.0.0.0"),
                new Option(new string[] { "--remap", "-r" }, "A declaration name to be remapped to another name during binding generation.")
                {
                    Argument = new Argument("<name>=<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                }
            };

            foreach (var opt in rootCommand.Options.Where(o => o.Name != "version" && o.Name != "remap"))
            {
                opt.IsRequired = true;
            }

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

            var remaps = ConvertValuePairsToDictionary(remappedNameValuePairs);

            Version assemblyVersion = new Version(1, 0, 0, 0);
            string rawVersion = version.Split('-')[0];
            assemblyVersion = Version.Parse(rawVersion);

            var netstandardPath = FindNetstandardDllPath();
            if (!File.Exists(netstandardPath))
            {
                Console.WriteLine($"Error: Failed to find {netstandardPath}.");
                return 1;
            }

            List<MetadataReference> refs = new List<MetadataReference>();
            refs.Add(MetadataReference.CreateFromFile(interopFileName));
            refs.Add(MetadataReference.CreateFromFile(netstandardPath));

            List<SyntaxTree> syntaxTrees = new List<SyntaxTree>();
            foreach (var sourceFile in Directory.GetFiles(sourceDirectory, "*.cs", SearchOption.AllDirectories))
            {
                if (sourceFile.Contains("\\obj\\") || sourceFile.Contains("\\bin\\"))
                {
                    continue;
                }

                Console.WriteLine($"Compiling {sourceFile}...");
                var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(sourceFile));
                tree = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, remaps);
                syntaxTrees.Add(tree);
            }

            var comp =
                CSharpCompilation.Create(
                    Path.GetFileName(outputFileName),
                    syntaxTrees,
                    refs);

            Console.WriteLine($"Emitting {outputFileName}...");
            ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(comp, assemblyVersion, outputFileName);

            return 0;
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

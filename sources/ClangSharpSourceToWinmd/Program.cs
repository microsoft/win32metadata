using System;
using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using System.Text.RegularExpressions;

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
                new Option<string>(new[] { "--baseMetadataFileName", "-b" }, "The path to Windows.Win32.winmd") { IsRequired = false },
                new Option<string>(new[] { "--outputNamespace" }, "The namespace for an external .winmd") { IsRequired = false },
                new Option<string>(new[] { "--outputFileName", "-o" }, "The path to the .winmd to create") { IsRequired = true },
                new Option<string>(new[] { "--version", "-v"}, description: "The version to use on the .winmd", getDefaultValue: () => "1.0.0.0"),
                new Option(new string[] { "--remap", "-r" }, "A declaration name to be remapped to another name during binding generation.")
                {
                    Argument = new Argument("<name>=<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.ZeroOrMore,
                    }
                },
                new Option(new string[] { "--enum-Addition" }, "Add a member to an enum.")
                {
                    Argument = new Argument("<name>=<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
                new Option(new string[] { "--enum-Make-Flags" }, "Make an enum a Flags enum.")
                {
                    Argument = new Argument("<name>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.ZeroOrMore,
                    }
                },
                new Option(new string[] { "--reducePointerLevel", "-p" }, "Reduce pointer level by one.")
                {
                    Argument = new Argument("<name>")
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
                },
                new Option(new string[] { "--requiredNamespaceForName", "-n" }, "The required namespace for a named item.")
                {
                    Argument = new Argument("<name>=<value>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
                new Option(new string[] { "--autoTypes", "-a" }, "An auto-type to add to the metadata.")
                {
                    Argument = new Argument("<value>")
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
            string baseMetadataFileName = context.ParseResult.ValueForOption<string>("baseMetadataFileName");
            string outputNamespace = context.ParseResult.ValueForOption<string>("outputNamespace");
            string outputFileName = context.ParseResult.ValueForOption<string>("outputFileName");
            string version = context.ParseResult.ValueForOption<string>("version");
            var remappedNameValuePairs = context.ParseResult.ValueForOption<string[]>("remap");
            var enumAdditionsNameValuePairs = context.ParseResult.ValueForOption<string[]>("enum-Addition");
            var enumMakeFlags = context.ParseResult.ValueForOption<string[]>("enum-Make-Flags");
            var reducePointerLevelPairs = context.ParseResult.ValueForOption<string[]>("reducePointerLevel");
            var typeImportValuePairs = context.ParseResult.ValueForOption<string[]>("typeImport");
            var requiredNamespaceValuePairs = context.ParseResult.ValueForOption<string[]>("requiredNamespaceForName");
            var autoTypes = context.ParseResult.ValueForOption<string[]>("autoTypes");

            var remaps = ConvertValuePairsToDictionary(remappedNameValuePairs);
            var enumAdditions = ConvertValuePairsToEnumAdditions(enumAdditionsNameValuePairs);
            var reducePointerLevels = reducePointerLevelPairs != null ? new HashSet<string>(reducePointerLevelPairs) : new HashSet<string>();
            var typeImports = ConvertValuePairsToDictionary(typeImportValuePairs);
            var requiredNamespaces = ConvertValuePairsToDictionary(requiredNamespaceValuePairs);

            string rawVersion = version.Split('-')[0];
            Version assemblyVersion = Version.Parse(rawVersion);

            NativeTypedefStructsCreator.CreateNativeTypedefsSourceFile(autoTypes, Path.Combine(sourceDirectory, "generated\\autotypes.cs"));

            Console.Write($"Compiling source files...");
            System.Diagnostics.Stopwatch watch = System.Diagnostics.Stopwatch.StartNew();

            ClangSharpSourceCompilation clangSharpCompliation =
                ClangSharpSourceCompilation.Create(
                    sourceDirectory,
                    interopFileName,
                    baseMetadataFileName,
                    outputNamespace,
                    remaps,
                    enumAdditions,
                    enumMakeFlags,
                    typeImports,
                    requiredNamespaces,
                    reducePointerLevels);

            Console.Write("looking for errors...");
            var diags = clangSharpCompliation.GetDiagnostics();

            watch.Stop();

            int errors = 0;
            const int MaxErrorsToShow = 10000;
            foreach (var diag in diags)
            {
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
            var generator =
                ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                    clangSharpCompliation,
                    typeImports,
                    reducePointerLevels,
                    assemblyVersion,
                    outputFileName);

            foreach (var diag in generator.GetDiagnostics())
            {
                Console.WriteLine($"{diag.Severity}: {diag.Message}");
            }

            return generator.WroteWinmd ? 0 : -1;
        }

        private static readonly Regex EnumAddtionRegex = new Regex(@"([^\:]+)::([^\:]+)=(.+)");

        private static Dictionary<string, Dictionary<string, string>> ConvertValuePairsToEnumAdditions(string[] items)
        {
            Dictionary<string, Dictionary<string, string>> ret = new Dictionary<string, Dictionary<string, string>>();

            if (items != null)
            {
                foreach (var item in items)
                {
                    if (string.IsNullOrEmpty(item))
                    {
                        continue;
                    }

                    var match = EnumAddtionRegex.Match(item);
                    if (match.Success)
                    {
                        var enumName = match.Groups[1].Value;
                        var memberName = match.Groups[2].Value;
                        var value = match.Groups[3].Value;

                        if (!ret.TryGetValue(enumName, out var enumList))
                        {
                            enumList = new Dictionary<string, string>();
                            ret[enumName] = enumList;
                        }

                        enumList[memberName] = value;
                    }
                }
            }

            return ret;
        }

        private static Dictionary<string, string> ConvertValuePairsToDictionary(string[] items)
        {
            Dictionary<string, string> ret = new Dictionary<string, string>();

            if (items != null)
            {
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
            }

            return ret;
        }
    }
}

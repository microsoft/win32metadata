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
                new Option<string>("--sourceDir", "The location of the source files.") { IsRequired = true },
                new Option<string>("--arch", () => "x64", "The CPU architecture."),
                new Option<string>("--interopFileName", "The path to Windows.Win32.Interop.dll") { IsRequired = true },
                new Option<string>("--outputFileName", "The path to the .winmd to create") { IsRequired = true },
                new Option<string>("--version", description: "The version to use on the .winmd", getDefaultValue: () => "1.0.0.0"),
                new Option<string>("--remap", "A declaration name to be remapped to another name during binding generation.", ArgumentArity.OneOrMore),

                new Option<string>("--enum-Addition", "Add a member to an enum.", ArgumentArity.OneOrMore),
                new Option<string>("--ref", "The path to a referenced binary.", ArgumentArity.OneOrMore),
                new Option<string>("--enum-Make-Flags", "Make an enum a Flags enum.", ArgumentArity.OneOrMore),
                new Option<string>("--reducePointerLevel", "Reduce pointer level by one.", ArgumentArity.OneOrMore),
                new Option<string>("--typeImport", "A type to be imported from another assembly.", ArgumentArity.OneOrMore),
                new Option<string>("--requiredNamespaceForName", "The required namespace for a named item.", ArgumentArity.OneOrMore),
                new Option<string>("--autoTypes", "An auto-type to add to the metadata.", ArgumentArity.OneOrMore)
            };

            rootCommand.Handler = CommandHandler.Create(typeof(Program).GetMethod(nameof(Run)));

            return rootCommand.Invoke(args);
        }

        public static int Run(InvocationContext context)
        {
            string sourceDirectory = context.ParseResult.ValueForOption<string>("--sourceDir");
            string arch = context.ParseResult.ValueForOption<string>("--arch");
            string interopFileName = context.ParseResult.ValueForOption<string>("--interopFileName");
            string outputFileName = context.ParseResult.ValueForOption<string>("--outputFileName");
            string version = context.ParseResult.ValueForOption<string>("--version");
            var remappedNameValuePairs = context.ParseResult.ValueForOption<string[]>("--remap");
            var enumAdditionsNameValuePairs = context.ParseResult.ValueForOption<string[]>("--enum-Addition");
            var enumMakeFlags = context.ParseResult.ValueForOption<string[]>("--enum-Make-Flags");
            var reducePointerLevelPairs = context.ParseResult.ValueForOption<string[]>("--reducePointerLevel");
            var typeImportValuePairs = context.ParseResult.ValueForOption<string[]>("--typeImport");
            var requiredNamespaceValuePairs = context.ParseResult.ValueForOption<string[]>("--requiredNamespaceForName");
            var autoTypes = context.ParseResult.ValueForOption<string[]>("--autoTypes");
            var refs = context.ParseResult.ValueForOption<string[]>("--ref");

            var remaps = ConvertValuePairsToDictionary(remappedNameValuePairs);
            var enumAdditions = ConvertValuePairsToEnumAdditions(enumAdditionsNameValuePairs);
            var reducePointerLevels = new HashSet<string>(reducePointerLevelPairs ?? (new string[0]));
            var typeImports = ConvertValuePairsToDictionary(typeImportValuePairs);
            var requiredNamespaces = ConvertValuePairsToDictionary(requiredNamespaceValuePairs);

            string rawVersion = version.Split('-')[0];
            Version assemblyVersion = Version.Parse(rawVersion);

            string archForAutoTypes = arch == "crossarch" ? "x64" : arch;
            NativeTypedefStructsCreator.CreateNativeTypedefsSourceFile(autoTypes, Path.Combine(sourceDirectory, $"generated\\{archForAutoTypes}\\autotypes.cs"));

            Console.WriteLine($"Compiling source files...");
            System.Diagnostics.Stopwatch watch = System.Diagnostics.Stopwatch.StartNew();

            ClangSharpSourceCompilation clangSharpCompliation =
                ClangSharpSourceCompilation.Create(
                    sourceDirectory, arch, interopFileName, remaps, enumAdditions, enumMakeFlags, typeImports, requiredNamespaces, reducePointerLevels, refs);

            Console.WriteLine("Looking for compilation errors...");
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

            watch.Reset();
            watch.Start();

            Console.WriteLine($"Compilation stage took {timeTaken}");

            Console.WriteLine($"\r\nEmitting {outputFileName}...");
            var generator = 
                ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                    clangSharpCompliation, 
                    typeImports,
                    reducePointerLevels,
                    assemblyVersion, 
                    outputFileName);

            watch.Stop();

            foreach (var diag in generator.GetDiagnostics())
            {
                Console.WriteLine($"{diag.Severity}: {diag.Message}");
            }

            timeTaken = watch.Elapsed.ToString("c");
            Console.WriteLine($"Emit stage took {timeTaken}");

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

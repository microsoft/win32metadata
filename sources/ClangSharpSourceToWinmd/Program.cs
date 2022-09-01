using System;
using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

namespace ClangSharpSourceToWinmd
{
    public static class Program
    {
        public static int Main(string[] args)
        {
#if DEBUG
            if (System.Environment.GetEnvironmentVariable("DEBUG_EMITTER") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            var rootCommand = new RootCommand("Convert ClangSharp-generated code into metadata")
            {
                new Option<string>("--sourceDir", "The location of the source files.") { IsRequired = true },
                new Option<string>("--arch", () => "x64", "The CPU architecture."),
                new Option<string>("--interopFileName", "The path to Windows.Win32.Interop.dll") { IsRequired = true },
                new Option<string>("--outputFileName", "The path to the .winmd to create") { IsRequired = true },
                new Option<string>("--version", description: "The version to use on the .winmd", getDefaultValue: () => "1.0.0.0"),
                new Option<string>("--memberRemap", "Remaps fields and parameters by adding attributes or changing the type.", ArgumentArity.OneOrMore),

                new Option<string>("--enumAddition", "Add a member to an enum.", ArgumentArity.OneOrMore),
                new Option<string>("--ref", "The path to a referenced binary.", ArgumentArity.OneOrMore),
                new Option<string>("--enumMakeFlags", "Make an enum a Flags enum.", ArgumentArity.OneOrMore),
                new Option<string>("--reducePointerLevel", "Reduce pointer level by one.", ArgumentArity.OneOrMore),
                new Option<string>("--typeImport", "A type to be imported from another assembly.", ArgumentArity.OneOrMore),
                new Option<string>("--requiredNamespaceForName", "The required namespace for a named item.", ArgumentArity.OneOrMore),
                new Option<string>("--autoTypes", "A path to a .json file of auto-types to add to the metadata.", ArgumentArity.OneOrMore),
                new Option<string>("--staticLibs", "Mapping from DLL names to alternative static libraries.", ArgumentArity.OneOrMore),
                new Option<string>("--forceGuidConst", "Forces a guid-only struct to be a guid const.", ArgumentArity.OneOrMore)
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
            var remappedNameValuePairs = context.ParseResult.ValueForOption<string[]>("--memberRemap");
            var enumAdditionsNameValuePairs = context.ParseResult.ValueForOption<string[]>("--enumAddition");
            var enumMakeFlags = context.ParseResult.ValueForOption<string[]>("--enumMakeFlags");
            var reducePointerLevelPairs = context.ParseResult.ValueForOption<string[]>("--reducePointerLevel");
            var typeImportValuePairs = context.ParseResult.ValueForOption<string[]>("--typeImport");
            var requiredNamespaceValuePairs = context.ParseResult.ValueForOption<string[]>("--requiredNamespaceForName");
            var autoTypeFiles = context.ParseResult.ValueForOption<string[]>("--autoTypes");
            var refs = context.ParseResult.ValueForOption<string[]>("--ref");
            var staticLibValuePairs = context.ParseResult.ValueForOption<string[]>("--staticLibs");
            var forceGuidConstsVals = context.ParseResult.ValueForOption<string[]>("--forceGuidConst");

            Dictionary<string, string> remaps = ConvertValuePairsToDictionary(remappedNameValuePairs);
            Dictionary<string, Dictionary<string, string>> enumAdditions = ConvertValuePairsToEnumAdditions(enumAdditionsNameValuePairs);
            var reducePointerLevels = new HashSet<string>(reducePointerLevelPairs ?? (Array.Empty<string>()));
            Dictionary<string, string> typeImports = ConvertValuePairsToDictionary(typeImportValuePairs);
            Dictionary<string, string> requiredNamespaces = ConvertValuePairsToDictionary(requiredNamespaceValuePairs);
            Dictionary<string, string> staticLibs = ConvertValuePairsToDictionary(staticLibValuePairs);
            var forceGuidConsts = new HashSet<string>(forceGuidConstsVals ?? (Array.Empty<string>()));

            string rawVersion = version.Split('-')[0];
            Version assemblyVersion = Version.Parse(rawVersion);

            string archForAutoTypes = arch == "crossarch" ? "common" : arch;
            string archSourceDir = Path.Combine(sourceDirectory, archForAutoTypes);

            Dictionary<string, string> methodNamesToNamespaces = MetadataUtils.ScraperUtils.GetNameToNamespaceMap(sourceDirectory, MetadataUtils.ScraperUtils.NameOptions.Methods);

            if (requiredNamespaceValuePairs != null)
            {
                // Merge the requiredNamespaceForName entries into what we found the scraped source files
                foreach (KeyValuePair<string, string> requiredItem in requiredNamespaces)
                {
                    if (methodNamesToNamespaces.ContainsKey(requiredItem.Key))
                    {
                        methodNamesToNamespaces[requiredItem.Key] = requiredItem.Value;
                    }
                }
            }

            try
            {
                var autoTypes = AutoTypeHelpers.GetAutoTypesFromFiles(autoTypeFiles);
                if (autoTypes != null && autoTypes.Any())
                {
                    var outputFilePath = Path.Combine(archSourceDir, "autotypes.cs");
                    if (!Directory.Exists(Path.GetDirectoryName(outputFilePath)))
                    {
                        Directory.CreateDirectory(Path.GetDirectoryName(outputFilePath));
                    }

                    using var fileStream = new FileStream(outputFilePath, FileMode.Create, FileAccess.Write, FileShare.Read);
                    NativeTypedefStructsCreator.WriteToStream(methodNamesToNamespaces, autoTypes, fileStream);
                }
            }
            catch (Exception e)
            {
                var error = new GeneratorDiagnostic($"Failed to create source for auto types: {e.Message}", Microsoft.CodeAnalysis.DiagnosticSeverity.Error);
                Console.WriteLine(error.ToString());

                return -1;
            }

            Console.WriteLine($"Preparing and compiling source files...");
            System.Diagnostics.Stopwatch mainWatch = System.Diagnostics.Stopwatch.StartNew();

            ClangSharpSourceCompilation clangSharpCompliation =
                ClangSharpSourceCompilation.Create(
                    sourceDirectory, arch, interopFileName, remaps, enumAdditions, enumMakeFlags, typeImports, requiredNamespaces, reducePointerLevels, refs, staticLibs);

            System.Diagnostics.Stopwatch errorsWatch = System.Diagnostics.Stopwatch.StartNew();
            Console.WriteLine("  Looking for compilation errors...");
            System.Collections.ObjectModel.ReadOnlyCollection<Microsoft.CodeAnalysis.Diagnostic> diags = clangSharpCompliation.GetDiagnostics();

            int errors = 0;
            const int MaxErrorsToShow = 10000;
            foreach (Microsoft.CodeAnalysis.Diagnostic diag in diags)
            {
                if (errors == 0)
                {
                    Console.WriteLine("  errors were found.");
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

            Console.WriteLine($"  {OutputUtils.FormatTimespan(errorsWatch.Elapsed)}");

            Console.WriteLine($"{OutputUtils.FormatTimespan(mainWatch.Elapsed)}");
            ClangSharpSourceCompilation.ShowMemory();

            mainWatch.Restart();

            Console.WriteLine($"\r\nEmitting {outputFileName}...");
            var generator = 
                ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                    clangSharpCompliation, 
                    typeImports,
                    reducePointerLevels,
                    forceGuidConsts,
                    assemblyVersion, 
                    outputFileName);

            mainWatch.Stop();

            foreach (GeneratorDiagnostic diag in generator.GetDiagnostics())
            {
                Console.WriteLine(diag.ToString());
            }

            Console.WriteLine($"{OutputUtils.FormatTimespan(mainWatch.Elapsed)}");
            ClangSharpSourceCompilation.ShowMemory();

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

                    Match match = EnumAddtionRegex.Match(item);
                    if (match.Success)
                    {
                        var enumName = match.Groups[1].Value;
                        var memberName = match.Groups[2].Value;
                        var value = match.Groups[3].Value;

                        if (!ret.TryGetValue(enumName, out Dictionary<string, string> enumList))
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

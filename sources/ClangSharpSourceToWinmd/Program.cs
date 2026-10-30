using System;
using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using MetadataUtils;

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
                new Option<string>("--outputFileName", "The path to the .winmd to create") { IsRequired = true },
                new Option<string>("--version", description: "The version to use on the .winmd", getDefaultValue: () => "1.0.0.0"),
                new Option<string>("--memberRemap", "Remaps fields and parameters by adding attributes or changing the type.", ArgumentArity.OneOrMore),
                new Option<bool>("--nativeFieldArrayInfo", "Opt in to NativeArrayInfo inference for native SAL pointer/array fields."),
                new Option<bool>("--preflightOnly", "Validate independent inputs without transforming sources or emitting metadata."),
                new Option<string>("--blockedBy", "Failed producer prerequisite for the read-only preflight."),

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

            try
            {
                return rootCommand.Invoke(args);
            }
            catch (Exception error)
            {
                Console.Error.WriteLine($"fatal WMG999: Unexpected emitter failure: {error}");
                Console.Error.WriteLine("error WMG002: Blocked WinMD publication and default tests.");
                return -1;
            }
        }

        public static int Run(InvocationContext context)
        {
            string sourceDirectory = context.ParseResult.ValueForOption<string>("--sourceDir");
            string arch = context.ParseResult.ValueForOption<string>("--arch");
            string outputFileName = context.ParseResult.ValueForOption<string>("--outputFileName");
            string version = context.ParseResult.ValueForOption<string>("--version");
            var remappedNameValuePairs = context.ParseResult.ValueForOption<string[]>("--memberRemap");
            bool nativeFieldArrayInfo = context.ParseResult.ValueForOption<bool>("--nativeFieldArrayInfo");
            bool preflightOnly = context.ParseResult.ValueForOption<bool>("--preflightOnly");
            string blockedBy = context.ParseResult.ValueForOption<string>("--blockedBy");
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
            var validation = new GenerationValidation();
            var autoTypes = AutoTypeHelpers.GetAutoTypesWithDiagnostics(autoTypeFiles, validation);

            if (!preflightOnly)
            {
                foreach (string generatedArchitecture in new[] { "common", "x86", "x64", "arm64" })
                {
                    string generatedSource = Path.Combine(sourceDirectory, generatedArchitecture, "autotypes.cs");
                    try
                    {
                        File.Delete(generatedSource);
                    }
                    catch (DirectoryNotFoundException)
                    {
                        // Sparse source layouts need not contain every architecture.
                    }
                    catch (Exception error) when (error is IOException or UnauthorizedAccessException)
                    {
                        validation.Add(error, "WMG004", "emitter.auto-type-source-retirement", generatedSource,
                            architecture: generatedArchitecture);
                    }
                }

            }

            var apiNamesToNamespaces = ScraperUtils.GetNameToNamespaceMap(sourceDirectory,
                ScraperUtils.NameOptions.Methods | ScraperUtils.NameOptions.Structs | ScraperUtils.NameOptions.Delegates);
            if (requiredNamespaceValuePairs != null)
            {
                foreach (KeyValuePair<string, string> requiredItem in requiredNamespaces)
                {
                    if (apiNamesToNamespaces.ContainsKey(requiredItem.Key))
                    {
                        apiNamesToNamespaces[requiredItem.Key] = requiredItem.Value;
                    }
                }
            }

            NativeTypedefStructsCreator.Validate(apiNamesToNamespaces, autoTypes, validation);
            if (!preflightOnly && autoTypes != null && autoTypes.Length != 0 && !validation.HasErrors)
            {
                var outputFilePath = Path.Combine(archSourceDir, "autotypes.cs");
                Directory.CreateDirectory(Path.GetDirectoryName(outputFilePath));
                using var fileStream = new FileStream(outputFilePath, FileMode.Create, FileAccess.Write, FileShare.Read);
                var cleanupOwnedTypes = autoTypes.Where(type =>
                    string.IsNullOrEmpty(type.Namespace) && !string.IsNullOrEmpty(type.CloseApi)).ToArray();
                NativeTypedefStructsCreator.WriteToStream(apiNamesToNamespaces, autoTypes, fileStream);
                foreach (var autoType in cleanupOwnedTypes)
                    requiredNamespaces.TryAdd(autoType.Name, autoType.Namespace);
            }
            else if (validation.HasErrors || preflightOnly)
                validation.Block("emitter.auto-type-source", blockedBy ?? "valid auto-type declarations and inputs");

            Console.WriteLine(preflightOnly ? "Validating independent emitter inputs..." : "Preparing and compiling source files...");
            System.Diagnostics.Stopwatch mainWatch = System.Diagnostics.Stopwatch.StartNew();

            ClangSharpSourceCompilation clangSharpCompliation;
            try
            {
                clangSharpCompliation = ClangSharpSourceCompilation.Create(
                    sourceDirectory, arch, remaps, enumAdditions, enumMakeFlags, typeImports, requiredNamespaces,
                    reducePointerLevels, refs, staticLibs, apiNamesToNamespaces, nativeFieldArrayInfo, validation,
                    preflightOnly, blockedBy);
            }
            catch (InvalidDataException error) when (GenerationValidation.IsValidationFailure(error))
            {
                Console.Error.WriteLine(error.Message);
                return -1;
            }
            catch (InvalidOperationException error) when (GenerationValidation.IsValidationFailure(error))
            {
                Console.Error.WriteLine(error.Message);
                return -1;
            }
            if (preflightOnly)
            {
                Console.Error.WriteLine(validation.Format());
                Console.Error.WriteLine("Full diagnostics: " + Path.Combine(sourceDirectory, "emitter-preflight-diagnostics.json"));
                return -1;
            }

            System.Diagnostics.Stopwatch errorsWatch = System.Diagnostics.Stopwatch.StartNew();
            Console.WriteLine("  Looking for compilation errors...");
            System.Collections.ObjectModel.ReadOnlyCollection<Microsoft.CodeAnalysis.Diagnostic> diags = clangSharpCompliation.GetDiagnostics();

            int errors = 0;
            foreach (Microsoft.CodeAnalysis.Diagnostic diag in diags)
            {
                if (errors == 0)
                {
                    Console.WriteLine("  errors were found.");
                }

                errors++;
                Console.WriteLine(diag.ToString());
                validation.Add(new InvalidOperationException(diag.ToString()), diag.Id, "emitter.compilation",
                    diag.Location.SourceTree?.FilePath, line: diag.Location.GetLineSpan().StartLinePosition.Line + 1);
            }

            if (errors > 0)
            {
                validation.Block("EmitWinmd;default tests", "successful C# compilation");
                validation.WriteReport(Path.Combine(sourceDirectory, "generation-diagnostics.json"));
                return -1;
            }

            Console.WriteLine($"  {OutputUtils.FormatTimespan(errorsWatch.Elapsed)}");

            Console.WriteLine($"{OutputUtils.FormatTimespan(mainWatch.Elapsed)}");
            ClangSharpSourceCompilation.ShowMemory();

            mainWatch.Restart();

            Console.WriteLine($"Emitting {outputFileName}...");
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
                if (diag.Severity == Microsoft.CodeAnalysis.DiagnosticSeverity.Error)
                    validation.Add(new InvalidOperationException(diag.Message), "WMG001", "emitter.metadata-emission");
            }
            if (validation.HasErrors)
            {
                validation.Block("WinMD publication;default tests", "successful metadata emission");
                validation.WriteReport(Path.Combine(sourceDirectory, "generation-diagnostics.json"));
            }

            Console.WriteLine($"{OutputUtils.FormatTimespan(mainWatch.Elapsed)}");
            ClangSharpSourceCompilation.ShowMemory();

            if (generator.WroteWinmd)
            {
                File.Delete(Path.Combine(sourceDirectory, "generation-failures.json"));
                File.Delete(Path.Combine(sourceDirectory, "emitter-preflight-diagnostics.json"));
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

                        if (ret.ContainsKey(name))
                        {
                            ret[name] += value;
                        }
                        else
                        {
                            ret[name] = value;
                        }
                    }
                }
            }

            return ret;
        }
    }
}

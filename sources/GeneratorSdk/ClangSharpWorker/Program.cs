// ClangSharpWorker: Process-isolated wrapper around PInvokeGenerator.
//
// Runs PInvokeGenerator as a library in its own process, then extracts
// _allValidNameRemappings (typedef-tag relationships discovered by libclang)
// and writes them to a .remaps sidecar file.
//
// Usage: dotnet ClangSharpWorker.dll <toolDir> <remapsOutputPath> @rsp1 @rsp2 ...
//
// Arguments:
//   toolDir          - Path to ClangSharp tool directory containing DLLs
//   remapsOutputPath - Path to write discovered remaps (one TAG=TYPEDEF per line)
//   @rsp...          - Response files (same format as ClangSharpPInvokeGenerator)

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Runtime.InteropServices;

class Program
{
    static int Main(string[] args)
    {
        if (args.Length < 3)
        {
            Console.Error.WriteLine("Usage: dotnet ClangSharpWorker.dll <toolDir> <remapsOutputPath> @rsp1 @rsp2 ...");
            return 1;
        }

        string toolDir = args[0];
        string remapsOutputPath = args[1];
        string[] rspArgs = args.Skip(2).ToArray();

        try
        {
            // Load ClangSharp assemblies from the tool directory
            var interopAsm = Assembly.LoadFrom(Path.Combine(toolDir, "ClangSharp.Interop.dll"));
            var clangSharpAsm = Assembly.LoadFrom(Path.Combine(toolDir, "ClangSharp.dll"));
            var pinvokeGenAsm = Assembly.LoadFrom(Path.Combine(toolDir, "ClangSharp.PInvokeGenerator.dll"));

            // Pre-load native libraries before ClangSharp.Interop's static
            // constructor runs — its DllImportResolver can't find them when
            // loaded via Assembly.LoadFrom from a non-standard path.
            NativeLibrary.Load(Path.Combine(toolDir, "libclang.dll"));
            NativeLibrary.Load(Path.Combine(toolDir, "libClangSharp.dll"));

            // Parse RSP files
            var settings = new Dictionary<string, List<string>>(StringComparer.OrdinalIgnoreCase);
            foreach (var arg in rspArgs)
            {
                string rspPath = arg.StartsWith("@") ? arg.Substring(1).Trim('"') : arg;
                ParseRspFile(rspPath, settings);
            }

            string sourceFile = settings.GetValueOrDefault("--file")?.LastOrDefault();
            string outputFile = settings.GetValueOrDefault("--output")?.LastOrDefault();
            string ns = settings.GetValueOrDefault("--namespace")?.LastOrDefault();
            string headerFile = settings.GetValueOrDefault("--headerFile")?.LastOrDefault();

            if (sourceFile == null || outputFile == null || ns == null)
            {
                Console.Error.WriteLine("Error: Missing required --file, --output, or --namespace in RSP files");
                return 1;
            }

            // Build clang command-line args
            var clangArgs = new List<string> { "--language=c++", "--std=c++17" };
            if (settings.TryGetValue("--include-directory", out var incDirs))
                foreach (var dir in incDirs)
                    clangArgs.Add($"--include-directory={dir}");
            if (settings.TryGetValue("--additional", out var additionals))
                clangArgs.AddRange(additionals);

            // Map --config strings to PInvokeGeneratorConfigurationOptions flags
            var optionsType = pinvokeGenAsm.GetType("ClangSharp.PInvokeGeneratorConfigurationOptions");
            long optionsValue = 0;
            if (settings.TryGetValue("--config", out var configs))
            {
                foreach (var cfg in configs)
                {
                    string fieldName = MapConfigToFieldName(cfg);
                    if (fieldName != null)
                    {
                        var field = optionsType.GetField(fieldName);
                        if (field != null)
                            optionsValue |= Convert.ToInt64(field.GetValue(null));
                    }
                }
            }

            // Create PInvokeGeneratorConfiguration
            var outputModeType = pinvokeGenAsm.GetType("ClangSharp.PInvokeGeneratorOutputMode");
            var configType = pinvokeGenAsm.GetType("ClangSharp.PInvokeGeneratorConfiguration");
            var config = Activator.CreateInstance(configType, new object[] {
                "c++", "c++17", ns, outputFile, headerFile ?? string.Empty,
                Enum.Parse(outputModeType, "CSharp"),
                Enum.ToObject(optionsType, optionsValue)
            });

            // Set config properties
            SetProperty(configType, config, "TraversalNames",
                (IReadOnlyCollection<string>)(settings.GetValueOrDefault("--traverse")?.ToArray() ?? Array.Empty<string>()));
            SetProperty(configType, config, "ExcludedNames",
                (IReadOnlyCollection<string>)(settings.GetValueOrDefault("--exclude")?.ToArray() ?? Array.Empty<string>()));
            SetProperty(configType, config, "RemappedNames",
                ParseKeyValuePairs(settings.GetValueOrDefault("--remap")));
            SetProperty(configType, config, "WithAttributes",
                ParseKeyValueMultiPairs(settings.GetValueOrDefault("--with-attribute")));
            SetProperty(configType, config, "WithTypes",
                ParseKeyValuePairs(settings.GetValueOrDefault("--with-type")));
            SetProperty(configType, config, "WithLibraryPaths",
                ParseKeyValuePairs(settings.GetValueOrDefault("--with-librarypath")));
            SetProperty(configType, config, "WithCallConvs",
                ParseKeyValuePairs(settings.GetValueOrDefault("--with-callconv")));
            SetProperty(configType, config, "WithUsings",
                ParseKeyValueMultiPairs(settings.GetValueOrDefault("--with-using")));

            if (settings.TryGetValue("--methodClassName", out var classNames) && classNames.Count > 0)
                configType.GetProperty("DefaultClass").SetValue(config, classNames.Last());

            // Create PInvokeGenerator with MemoryStream output factory
            var genType = pinvokeGenAsm.GetType("ClangSharp.PInvokeGenerator");
            var capturedStreams = new Dictionary<string, MemoryStream>();
            Func<string, Stream> streamFactory = (path) =>
            {
                var ms = new MemoryStream();
                capturedStreams[path] = ms;
                return ms;
            };
            var generator = Activator.CreateInstance(genType, new object[] { config, streamFactory });

            try
            {
                // Build TryParse delegate via IL emit (ReadOnlySpan params can't be boxed)
                var tryParseDelegate = BuildTryParseDelegate(interopAsm);

                // Parse translation unit
                var indexHandle = genType.GetProperty("IndexHandle").GetValue(generator);

                var flagsType = interopAsm.GetType("ClangSharp.Interop.CXTranslationUnit_Flags");
                long flagsValue = Convert.ToInt64(Enum.Parse(flagsType, "CXTranslationUnit_IncludeAttributedTypes"))
                                | Convert.ToInt64(Enum.Parse(flagsType, "CXTranslationUnit_VisitImplicitAttributes"));
                var flags = Enum.ToObject(flagsType, flagsValue);

                var tryParseResult = tryParseDelegate(
                    indexHandle, sourceFile, clangArgs.ToArray(), (int)flagsValue);
                var parseResult = tryParseResult[0];
                var cxTU = tryParseResult[1];

                if (parseResult.ToString() != "CXError_Success")
                {
                    Console.Error.WriteLine($"Error: Failed to parse {sourceFile}: {parseResult}");
                    return 1;
                }

                // Wrap in managed TranslationUnit
                var tuType = clangSharpAsm.GetType("ClangSharp.TranslationUnit");
                var getOrCreate = tuType.GetMethod("GetOrCreate", BindingFlags.Public | BindingFlags.Static);
                var translationUnit = getOrCreate.Invoke(null, new[] { cxTU });

                // Generate bindings (produces C# output, discovers remaps)
                try
                {
                    genType.GetMethod("GenerateBindings").Invoke(generator, new[] {
                        translationUnit, sourceFile, clangArgs.ToArray(), flags
                    });
                }
                catch (TargetInvocationException tie) when (tie.InnerException is ArgumentException ae
                    && ae.Message.Contains("diagnostics which prevent"))
                {
                    Console.Error.WriteLine($"Error: {ae.Message}");
                    return 1;
                }

                // Flush output
                genType.GetMethod("Close").Invoke(generator, null);

                // Write captured streams to disk
                foreach (var kvp in capturedStreams)
                {
                    var dir = Path.GetDirectoryName(kvp.Key);
                    if (!string.IsNullOrEmpty(dir))
                        Directory.CreateDirectory(dir);
                    File.WriteAllBytes(kvp.Key, kvp.Value.ToArray());
                }

                // Write diagnostics to stdout (same as CLI)
                var diagnostics = (IEnumerable)genType.GetProperty("Diagnostics").GetValue(generator);
                foreach (var diag in diagnostics)
                    Console.WriteLine($"    {diag}");

                // Extract _allValidNameRemappings and write .remaps sidecar
                var remappingsField = genType.GetField("_allValidNameRemappings",
                    BindingFlags.NonPublic | BindingFlags.Instance);
                if (remappingsField != null)
                {
                    var allRemappings = remappingsField.GetValue(generator) as IDictionary;
                    if (allRemappings != null && allRemappings.Count > 0)
                    {
                        var remapDir = Path.GetDirectoryName(remapsOutputPath);
                        if (!string.IsNullOrEmpty(remapDir))
                            Directory.CreateDirectory(remapDir);

                        using var writer = new StreamWriter(remapsOutputPath);
                        foreach (DictionaryEntry entry in allRemappings)
                        {
                            string tagName = (string)entry.Key;
                            var typedefNames = entry.Value as IEnumerable<string>;
                            string preferredName = typedefNames?.FirstOrDefault();
                            if (preferredName != null && tagName != preferredName)
                                writer.WriteLine($"{tagName}={preferredName}");
                        }
                    }
                }

                return 0;
            }
            finally
            {
                if (generator is IDisposable disposable)
                    disposable.Dispose();
            }
        }
        catch (Exception ex)
        {
            var inner = ex is TargetInvocationException tie ? tie.InnerException : ex;
            Console.Error.WriteLine($"Error: {inner?.Message ?? ex.Message}");
            return 1;
        }
    }

    static void ParseRspFile(string path, Dictionary<string, List<string>> settings)
    {
        if (!File.Exists(path)) return;

        string currentSwitch = null;
        foreach (var rawLine in File.ReadLines(path))
        {
            string line = rawLine.Trim();
            if (string.IsNullOrEmpty(line)) continue;

            if (line.StartsWith("--"))
            {
                currentSwitch = line;
                if (!settings.ContainsKey(currentSwitch))
                    settings[currentSwitch] = new List<string>();
            }
            else if (currentSwitch != null)
            {
                settings[currentSwitch].Add(line);
            }
        }
    }

    static void SetProperty(Type type, object obj, string name, object value)
    {
        var prop = type.GetProperty(name);
        if (prop != null && prop.CanWrite)
            prop.SetValue(obj, value);
    }

    static Dictionary<string, string> ParseKeyValuePairs(List<string> items)
    {
        var dict = new Dictionary<string, string>();
        if (items == null) return dict;
        foreach (var item in items)
        {
            int eq = item.IndexOf('=');
            if (eq > 0)
                dict[item.Substring(0, eq)] = item.Substring(eq + 1);
        }
        return dict;
    }

    static Dictionary<string, IReadOnlyList<string>> ParseKeyValueMultiPairs(List<string> items)
    {
        var dict = new Dictionary<string, IReadOnlyList<string>>();
        if (items == null) return dict;
        var temp = new Dictionary<string, List<string>>();
        foreach (var item in items)
        {
            int eq = item.IndexOf('=');
            if (eq > 0)
            {
                string key = item.Substring(0, eq);
                string val = item.Substring(eq + 1);
                if (!temp.TryGetValue(key, out var list))
                {
                    list = new List<string>();
                    temp[key] = list;
                }
                list.Add(val);
            }
        }
        foreach (var kv in temp)
            dict[kv.Key] = kv.Value;
        return dict;
    }

    static string MapConfigToFieldName(string configName)
    {
        return configName switch
        {
            "compatible-codegen" => "GenerateCompatibleCode",
            "log-visited-files" => "LogVisitedFiles",
            "log-exclusions" => "LogExclusions",
            "log-potential-typedef-remappings" => "LogPotentialTypedefRemappings",
            "exclude-funcs-with-body" => "ExcludeFunctionsWithBody",
            "generate-cpp-attributes" => "GenerateCppAttributes",
            "generate-native-bitfield-attribute" => "GenerateNativeBitfieldAttribute",
            "generate-native-inheritance-attribute" => "GenerateNativeInheritanceAttribute",
            "dont-use-using-statics-for-enums" => "DontUseUsingStaticsForEnums",
            "exclude-anonymous-field-helpers" => "ExcludeAnonymousFieldHelpers",
            "exclude-empty-records" => "ExcludeEmptyRecords",
            "exclude-enum-operators" => "ExcludeEnumOperators",
            "exclude-com-proxies" => "ExcludeComProxies",
            "generate-marker-interfaces" => "GenerateMarkerInterfaces",
            "generate-explicit-vtbls" => "GenerateExplicitVtbls",
            "generate-trimmable-vtbls" => "GenerateTrimmableVtbls",
            "generate-aggressive-inlining" => "GenerateAggressiveInlining",
            "multi-file" => "GenerateMultipleFiles",
            "generate-macro-bindings" => "GenerateMacroBindings",
            "generate-file-scoped-namespaces" => "GenerateFileScopedNamespaces",
            "generate-disable-runtime-marshalling" => "GenerateDisableRuntimeMarshalling",
            "generate-guid-member" => "GenerateGuidMember",
            "generate-helper-types" => "GenerateHelperTypes",
            "generate-vtbl-index-attribute" => "GenerateVtblIndexAttribute",
            "generate-setslasterror-attribute" => "GenerateSetsLastSystemErrorAttribute",
            "generate-unmanaged-constants" => "GenerateUnmanagedConstants",
            "generate-latest-code" => "GenerateLatestCode",
            "generate-template-bindings" => "GenerateTemplateBindings",
            "generate-source-location-attribute" => "GenerateSourceLocationAttribute",
            "generate-callconv-member-function" => "GenerateCallConvMemberFunction",
            "generate-doc-includes" => "GenerateDocIncludes",
            "preview-codegen" => "GeneratePreviewCode",
            "unix-types" => "GenerateUnixTypes",
            _ => null
        };
    }

    /// <summary>
    /// Builds a delegate for CXTranslationUnit.TryParse via IL emit.
    /// ReadOnlySpan params cannot be boxed, so standard reflection Invoke doesn't work.
    /// </summary>
    static Func<object, string, string[], int, object[]> BuildTryParseDelegate(Assembly interopAsm)
    {
        var cxIndexType = interopAsm.GetType("ClangSharp.Interop.CXIndex");
        var cxTUType = interopAsm.GetType("ClangSharp.Interop.CXTranslationUnit");
        var errorCodeType = interopAsm.GetType("ClangSharp.Interop.CXErrorCode");
        var unsavedFileType = interopAsm.GetType("ClangSharp.Interop.CXUnsavedFile");

        var spanStringType = typeof(ReadOnlySpan<>).MakeGenericType(typeof(string));
        var spanUnsavedType = typeof(ReadOnlySpan<>).MakeGenericType(unsavedFileType);

        var tryParseMethod = cxTUType.GetMethod("TryParse", BindingFlags.Public | BindingFlags.Static);

        var opImplicitString = spanStringType.GetMethod("op_Implicit",
            BindingFlags.Public | BindingFlags.Static, null, new[] { typeof(string[]) }, null);
        var emptyUnsavedGetter = spanUnsavedType.GetProperty("Empty",
            BindingFlags.Public | BindingFlags.Static).GetGetMethod();

        var dm = new DynamicMethod(
            "CallTryParse", typeof(object[]),
            new[] { typeof(object), typeof(string), typeof(string[]), typeof(int) },
            typeof(Program).Module, true);

        var il = dm.GetILGenerator();

        var cxTULocal = il.DeclareLocal(cxTUType);
        var errorLocal = il.DeclareLocal(errorCodeType);
        var resultLocal = il.DeclareLocal(typeof(object[]));

        il.Emit(OpCodes.Ldarg_0);
        il.Emit(OpCodes.Unbox_Any, cxIndexType);
        il.Emit(OpCodes.Ldarg_1);
        il.Emit(OpCodes.Ldarg_2);
        il.EmitCall(OpCodes.Call, opImplicitString, null);
        il.EmitCall(OpCodes.Call, emptyUnsavedGetter, null);
        il.Emit(OpCodes.Ldarg_3);
        il.Emit(OpCodes.Ldloca_S, cxTULocal);
        il.EmitCall(OpCodes.Call, tryParseMethod, null);
        il.Emit(OpCodes.Stloc, errorLocal);

        il.Emit(OpCodes.Ldc_I4_2);
        il.Emit(OpCodes.Newarr, typeof(object));
        il.Emit(OpCodes.Stloc, resultLocal);

        il.Emit(OpCodes.Ldloc, resultLocal);
        il.Emit(OpCodes.Ldc_I4_0);
        il.Emit(OpCodes.Ldloc, errorLocal);
        il.Emit(OpCodes.Box, errorCodeType);
        il.Emit(OpCodes.Stelem_Ref);

        il.Emit(OpCodes.Ldloc, resultLocal);
        il.Emit(OpCodes.Ldc_I4_1);
        il.Emit(OpCodes.Ldloc, cxTULocal);
        il.Emit(OpCodes.Box, cxTUType);
        il.Emit(OpCodes.Stelem_Ref);

        il.Emit(OpCodes.Ldloc, resultLocal);
        il.Emit(OpCodes.Ret);

        return (Func<object, string, string[], int, object[]>)dm.CreateDelegate(
            typeof(Func<object, string, string[], int, object[]>));
    }
}

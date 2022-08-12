﻿using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Text;
using System.Text.RegularExpressions;
using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.Metadata;
using ICSharpCode.Decompiler.TypeSystem;
using Windows.Win32.Interop;
using MetadataUtils;

namespace WinmdUtilsProgram
{
    class Program
    {
        static int Main(string[] args)
        {
            var showMissingImportsCommand = new Command("showMissingImports", "Show missing imports between two winmd files.")
            {
                new Option<FileInfo>("--first", "The first winmd.") { IsRequired = true }.ExistingOnly(),
                new Option<FileInfo>("--second", "The second winmd.") { IsRequired = true }.ExistingOnly(),
                new Option<string>("--exclusions", "Exclusions files."),
            };

            showMissingImportsCommand.Handler = CommandHandler.Create<FileInfo, FileInfo, string, IConsole>(ShowMissingImports);

            var compareCommand = new Command("compare", "Compare two winmd files.")
            {
                new Option<FileInfo>("--first", "The first winmd.") { IsRequired = true }.ExistingOnly(),
                new Option<FileInfo>("--second", "The second winmd.") { IsRequired = true }.ExistingOnly(),
            };

            compareCommand.Handler = CommandHandler.Create<FileInfo, FileInfo, string, IConsole>(CompareWinmds);

            var showDuplicateImports = new Command("showDuplicateImports", "Show duplicate imports in a single winmd files.")
            {
                new Option<FileInfo>("--winmd", "The winmd to inspect.") { IsRequired = true }.ExistingOnly(),
            };

            showDuplicateImports.Handler = CommandHandler.Create<FileInfo, IConsole>(ShowDuplicateImports);

            var showDuplicateTypes = new Command("showDuplicateTypes", "Show duplicate types in a single winmd files.")
            {
                new Option<FileInfo>("--winmd", "The winmd to inspect.") { IsRequired = true }.ExistingOnly(),
            };

            showDuplicateTypes.Handler = CommandHandler.Create<FileInfo, IConsole>(ShowDuplicateTypes);

            var showDuplicateConstants = new Command("showDuplicateConstants", "Show duplicate constants in a single winmd files.")
            {
                new Option<FileInfo>("--winmd", "The winmd to inspect.") { IsRequired = true }.ExistingOnly(),
            };

            showDuplicateConstants.Handler = CommandHandler.Create<FileInfo, IConsole>(ShowDuplicateConstants);

            var showEmptyDelegates = new Command("showEmptyDelegates", "Show delegates that have no parameters.")
            {
                new Option<FileInfo>("--winmd", "The winmd to inspect.") { IsRequired = true }.ExistingOnly(),
                new Option<string>("--allowItem", "Item to allow and not flag as an error.", ArgumentArity.OneOrMore)
            };

            showEmptyDelegates.Handler = CommandHandler.Create<FileInfo, string[], IConsole>(ShowEmptyDelegates);

            var showPointersToDelegates = new Command("showPointersToDelegates", "Show pointers to delegates.")
            {
                new Option<FileInfo>("--winmd", "The winmd to inspect.") { IsRequired = true }.ExistingOnly(),
                new Option<string>("--allowItem", "Item to allow and not flag as an error.", ArgumentArity.OneOrMore)
            };

            showPointersToDelegates.Handler = CommandHandler.Create<FileInfo, string[], IConsole>(ShowPointersToDelegates);

            var showLibImports = new Command("dumpImports", "Show lib imports.")
            {
                new Option<FileInfo>("--lib", "The lib path.") { IsRequired = true }.ExistingOnly(),
            };

            showLibImports.Handler = CommandHandler.Create<FileInfo, IConsole>(ShowLibImports);

            var createLibRsp = new Command("createLibRsp", "Create lib rsp.")
            {
                new Option<string>("--lib", "A lib path.", ArgumentArity.ZeroOrMore),
                new Option<string>("--libDir", "A directory containing libs.", ArgumentArity.ZeroOrMore),
                new Option<string>("--exclude", "A function to exclude.", ArgumentArity.ZeroOrMore),
                new Option<FileInfo>("--outputRsp", "Output rsp file."),
                new Option<FileInfo>("--inputRsp", "Input rsp file use to resolve duplicate libs for the same function."),
            };

            createLibRsp.Handler = CommandHandler.Create<string[], string[], string[], FileInfo, FileInfo, IConsole>(CreateLibRsp);

            var showNamespaceDependencies = new Command("showNamespaceDependencies", "Show namespace dependencies.")
            {
                new Option<FileInfo>("--winmd", "The winmd to inspect.") { IsRequired = true }.ExistingOnly(),
                new Option<string>("--ignoreDependNamespace", "Ignore dependencies to this namespace.", ArgumentArity.OneOrMore),
                new Option<string>("--namespaceFilter", "Namespace filter", ArgumentArity.OneOrMore),
                new Option<int>("--maxBroughtInBy", getDefaultValue: () => int.MaxValue,  description: "The max number of items to display of a type that brought in a namespace"),
                new Option<int>("--maxDependTypes", getDefaultValue: () => int.MaxValue,  description: "The max number of types to display that brought in a namespace"),
            };

            showNamespaceDependencies.Handler = CommandHandler.Create<FileInfo, string[], string[], int, int, IConsole>(ShowNamespaceDependencies);

            var showNamespaceCycles = new Command("showNamespaceCycles", "Show namespace cyclical dependencies.")
            {
                new Option<FileInfo>("--winmd", "The winmd to inspect.") { IsRequired = true }.ExistingOnly(),
            };

            showNamespaceCycles.Handler = CommandHandler.Create<FileInfo, IConsole>(ShowNamespaceCycles);

            var showBrokenArchTypes = new Command("showBrokenArchTypes", "Show broken architecture types.")
            {
                new Option<FileInfo>("--winmd", "The winmd to inspect.") { IsRequired = true }.ExistingOnly(),
            };

            showBrokenArchTypes.Handler = CommandHandler.Create<FileInfo, IConsole>(ShowBrokenArchTypes);

            var rootCommand = new RootCommand("Win32metadata winmd utils")
            {
                showMissingImportsCommand,
                showDuplicateImports,
                showDuplicateTypes,
                showDuplicateConstants,
                showEmptyDelegates,
                showPointersToDelegates,
                compareCommand,
                showLibImports,
                createLibRsp,
                showNamespaceDependencies,
                showNamespaceCycles,
                showBrokenArchTypes
            };

            return rootCommand.Invoke(args);
        }

        private static bool TypeIsPointerToOneOfNames(HashSet<string> names, string type)
        {
            int starIndex = type.IndexOf('*');
            if (starIndex == -1)
            {
                return false;
            }

            string typeOnly = type.Substring(0, starIndex);
            return names.Contains(typeOnly);
        }

        private class PointerInfo
        {
            public PointerInfo(string name, string type)
            {
                this.Name = name;
                this.Type = type;
            }

            public string Name { get; }
            public string Type { get; }
        }

        private static string GetPointerTypeToOneOfNamesInUseByParameter(HashSet<string> typeNames, MethodSignature<string> methodSignature, IEnumerable<MetadataUtils.ParameterInfo> parameterInfos)
        {
            var parameters = parameterInfos.ToArray();
            for (int i = 0; i < methodSignature.ParameterTypes.Length; i++)
            {
                var paramType = methodSignature.ParameterTypes[i];
                var paramtTypeToTest = paramType;
                var param = parameters[i];

                if (param.Attributes.HasFlag(ParameterAttributes.Out) && paramtTypeToTest.EndsWith('*'))
                {
                    paramtTypeToTest = paramtTypeToTest.Substring(0, paramType.Length - 1);
                }

                if (TypeIsPointerToOneOfNames(typeNames, paramtTypeToTest))
                {
                    return paramType;
                }
            }

            return null;
        }

        private static IEnumerable<PointerInfo> PointerToOneOfNamesInUse(HashSet<string> typeNames, MetadataUtils.TypeInfo typeInfo)
        {
            if (typeInfo is StructInfo structInfo)
            {
                foreach (var fieldInfo in structInfo.Fields)
                {
                    if (TypeIsPointerToOneOfNames(typeNames, fieldInfo.Type))
                    {
                        yield return new PointerInfo($"{typeInfo.Namespace}.{typeInfo.Name}.{fieldInfo.Name}", fieldInfo.Type);
                    }
                }
            }
            else if (typeInfo is InterfaceInfo interfaceInfo)
            {
                foreach (var methodInfo in interfaceInfo.Methods)
                {
                    var paramType = GetPointerTypeToOneOfNamesInUseByParameter(typeNames, methodInfo.MethodSignature, methodInfo.Parameters);
                    if (paramType != null)
                    {
                        yield return new PointerInfo($"{interfaceInfo.Namespace}.{interfaceInfo.Name}.{methodInfo.Name}", paramType);
                    }
                }
            }
            else if (typeInfo is DelegateTypeInfo delegateInfo)
            {
                for (int i = 0; i < delegateInfo.MethodSignature.ParameterTypes.Length; i++)
                {
                    var paramType = GetPointerTypeToOneOfNamesInUseByParameter(typeNames, delegateInfo.MethodSignature, delegateInfo.Parameters);
                    if (paramType != null)
                    {
                        yield return new PointerInfo($"{delegateInfo.Namespace}.{delegateInfo.Name}", paramType);
                    }
                }
            }
            else if (typeInfo is ClassInfo classInfo)
            {
                foreach (var methodInfo in classInfo.Methods)
                {
                    var paramType = GetPointerTypeToOneOfNamesInUseByParameter(typeNames, methodInfo.MethodSignature, methodInfo.Parameters);
                    if (paramType != null)
                    {
                        yield return new PointerInfo($"{classInfo.Namespace}.{classInfo.Name}.{methodInfo.Name}", paramType);
                    }
                }
            }
        }

        public static int CreateLibRsp(string[] lib, string[] libDir, string[] exclude, FileInfo outputRsp, FileInfo inputRsp, IConsole console)
        {
            List<string> libPaths = new List<string>();
            HashSet<string> visitedPaths = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            HashSet<string> excludes = new HashSet<string>();

            if (exclude != null)
            {
                foreach (var item in exclude)
                {
                    excludes.Add(item);
                }
            }

            if (lib != null)
            {
                foreach (var libPath in lib)
                {
                    if (!File.Exists(libPath))
                    {
                        console.Out.Write($"Error: {libPath} not found.");
                        return -1;
                    }

                    libPaths.Add(libPath);
                    visitedPaths.Add(libPath);
                }
            }

            if (libDir != null)
            {
                foreach (var dir in libDir)
                {
                    foreach (var libPath in Directory.GetFiles(dir, "*.lib"))
                    {
                        if (!visitedPaths.Contains(libPath))
                        {
                            libPaths.Add(libPath);
                            visitedPaths.Add(libPath);
                        }
                    }
                }
            }

            OrderedDictionary procNameToDll = new OrderedDictionary();
            Dictionary<string, string> inputEntries = new Dictionary<string, string>();

            if (inputRsp != null)
            {
                foreach (var line in File.ReadAllLines(inputRsp.FullName))
                {
                    int equal = line.IndexOf('=');
                    if (equal != -1)
                    {
                        var procName = line.Substring(0, equal);
                        var dllName = line.Substring(equal + 1);
                        inputEntries[procName] = dllName;
                    }
                }
            }

            foreach (var libFile in libPaths)
            {
                foreach (var importInfo in LibScraper.GetImportInfos(libFile))
                {
                    List<string> dlls;
                    string fixedDll = Path.GetFileNameWithoutExtension(importInfo.Dll);

                    // Skip mangled names
                    if (importInfo.ProcName.StartsWith('?'))
                    {
                        continue;
                    }

                    // Skip ones we are told to exclude
                    if (excludes.Contains(importInfo.ProcName))
                    {
                        continue;
                    }

                    if (!procNameToDll.Contains(importInfo.ProcName))
                    {
                        dlls = new List<string>();
                        procNameToDll[importInfo.ProcName] = dlls;
                        dlls.Add(fixedDll);
                    }
                    else
                    {
                        dlls = (List<string>)procNameToDll[importInfo.ProcName];

                        // Don't overwrite an existing value with an API set
                        if (fixedDll.StartsWith("api-ms") || fixedDll.StartsWith("ext-ms"))
                        {
                            continue;
                        }

                        if (dlls.Contains(fixedDll))
                        {
                            continue;
                        }

                        // Only concat the new value to the old one if the old one is
                        // not an api set. If the old one is an api set, override it.
                        string oldValue = dlls[0];
                        if (!oldValue.StartsWith("api-ms") && !oldValue.StartsWith("ext-ms"))
                        {
                            dlls.Add(fixedDll);
                        }
                        else
                        {
                            dlls[0] = fixedDll;
                        }
                    }
                }
            }

            using StreamWriter streamWriter = new StreamWriter(outputRsp.FullName);

            streamWriter.WriteLine("--with-librarypath");

            List<string> linesToFix = new List<string>();
            foreach (string procName in procNameToDll.Keys)
            {
                var dlls = (List<string>)procNameToDll[procName];
                bool lineNeedsFixing = false;
                if (!inputEntries.TryGetValue(procName, out string value))
                {
                    value = string.Join(',', dlls.ToArray());
                    if (dlls.Count > 1)
                    {
                        lineNeedsFixing = true;
                    }
                }

                string line = $"{procName}={value}";
                streamWriter.WriteLine(line);

                if (lineNeedsFixing)
                {
                    linesToFix.Add(line);
                }
            }

            if (linesToFix.Count != 0)
            {
                console.Out.Write("One or more procedures map to multiple DLLs:\n");
                foreach (var line in linesToFix)
                {
                    console.Out.Write(line + "\n");
                }

                return -1;
            }

            return 0;
        }

        public static int ShowLibImports(FileInfo lib, IConsole console)
        {
            foreach (var libInfo in LibScraper.GetImportInfos(lib.FullName))
            {
                console.Out.Write($"{libInfo.ProcName}={libInfo.Dll}\n");
            }

            return 0;
        }

        public static int ShowPointersToDelegates(FileInfo winmd, string[] allowItem, IConsole console)
        {
            HashSet<string> allowTable = new HashSet<string>(allowItem);
            using WinmdUtils w1 = WinmdUtils.LoadFromFile(winmd.FullName);
            bool pointersFound = false;

            HashSet<string> delegateNames = new HashSet<string>(w1.GetTypes().Where(t => t is DelegateTypeInfo).Select(d => $"{d.Namespace}.{d.Name}"));

            foreach (var type in w1.GetTypes())
            {
                foreach (var pointerInUse in PointerToOneOfNamesInUse(delegateNames, type))
                {
                    if (allowTable.Contains(pointerInUse.Name))
                    {
                        continue;
                    }

                    if (!pointersFound)
                    {
                        console.Out.Write("Pointers to delegates detected:\r\n");
                        pointersFound = true;
                    }

                    console?.Out.Write($"{pointerInUse.Type},{pointerInUse.Name}\r\n");
                }
            }

            if (!pointersFound)
            {
                console.Out.Write("No pointers to delegates found.\r\n");
            }

            return pointersFound ? -1 : 0;
        }

        public static int ShowDuplicateConstants(FileInfo winmd, IConsole console)
        {
            DecompilerTypeSystem winmd1 = DecompilerTypeSystemUtils.CreateTypeSystemFromFile(winmd.FullName);
            Dictionary<string, List<string>> nameToOwner = new Dictionary<string, List<string>>();

            foreach (var type in winmd1.GetTopLevelTypeDefinitions())
            {
                if (type.FullName == "<Module>")
                {
                    continue;
                }

                if (type.ParentModule != winmd1.MainModule)
                {
                    continue;
                }

                // Skip enums marked as a scoped enum (like a C++ class enum).
                // We don't count these in the duplicated constants
                if (type.Kind == TypeKind.Enum)
                {
                    if (type.GetAttributes().Any(a => a.AttributeType.Name == "ScopedEnumAttribute"))
                    {
                        continue;
                    }
                }

                if (type.Kind == TypeKind.Enum || (type.Kind == TypeKind.Class && type.Name == "Apis"))
                {
                    foreach (var field in type.GetFields(options: GetMemberOptions.IgnoreInheritedMembers))
                    {
                        if (field.Name == "value__")
                        {
                            continue;
                        }

                        if (!nameToOwner.TryGetValue(field.Name, out var owners))
                        {
                            owners = new List<string>();
                            nameToOwner[field.Name] = owners;
                        }

                        owners.Add(type.FullName);
                    }
                }
            }

            bool dupsFound = false;
            foreach (var pair in nameToOwner)
            {
                if (pair.Value.Count > 1)
                {
                    if (dupsFound == false)
                    {
                        dupsFound = true;
                        console.Out.Write("Duplicate constants/enum names detected:\r\n");
                    }

                    pair.Value.Sort();

                    console?.Out.Write($"{pair.Key}\r\n");
                    foreach (var owner in pair.Value)
                    {
                        console?.Out.Write($"  {owner}\r\n");
                    }
                }
            }

            if (!dupsFound)
            {
                console.Out.Write("No duplicate constants/enum names found.\r\n");
            }

            return dupsFound ? -1 : 0;
        }

        public static int ShowDuplicateTypes(FileInfo winmd, IConsole console)
        {
            DecompilerTypeSystem winmd1 = DecompilerTypeSystemUtils.CreateTypeSystemFromFile(winmd.FullName);

            Dictionary<string, List<string>> nameToNamespaces = new Dictionary<string, List<string>>();

            foreach (var type1 in winmd1.GetTopLevelTypeDefinitions())
            {
                if (type1.FullName == "<Module>")
                {
                    continue;
                }

                if (type1.ParentModule != winmd1.MainModule)
                {
                    continue;
                }

                var typeName = type1.Name;
                if (type1.Kind == TypeKind.Class && typeName == "Apis")
                {
                    continue;
                }

                StringBuilder members = new StringBuilder();
                foreach (var m in type1.Members)
                {
                    if (type1.Kind == TypeKind.Enum && m.Name == "value__")
                    {
                        continue;
                    }

                    if (m.Name == ".ctor")
                    {
                        continue;
                    }

                    if (members.Length != 0)
                    {
                        members.Append(',');
                    }

                    members.Append(m.Name);
                }

                if (members.Length != 0)
                {
                    typeName += $"({members})";
                }

                string archInfo = GetArchInfo(type1.GetAttributes());
                if (!string.IsNullOrEmpty(archInfo))
                {
                    typeName += $"({archInfo})";
                }

                if (!nameToNamespaces.TryGetValue(typeName, out var namespaces))
                {
                    namespaces = new List<string>();
                    nameToNamespaces[typeName] = namespaces;
                }

                namespaces.Add(type1.Namespace);
            }

            bool dupsFound = false;
            foreach (var pair in nameToNamespaces)
            {
                if (pair.Value.Count > 1)
                {
                    if (dupsFound == false)
                    {
                        dupsFound = true;
                        console.Out.Write("Duplicate types detected:\r\n");
                    }

                    pair.Value.Sort();

                    console?.Out.Write($"{pair.Key}\r\n");
                    foreach (var ns in pair.Value)
                    {
                        console?.Out.Write($"  {ns}\r\n");
                    }
                }
            }

            if (!dupsFound)
            {
                console.Out.Write("No duplicate types found.\r\n");
            }

            return dupsFound ? -1 : 0;
        }

        public static int ShowEmptyDelegates(FileInfo winmd, string[] allowItem, IConsole console)
        {
            HashSet<string> allowTable = new HashSet<string>(allowItem);
            using WinmdUtils w1 = WinmdUtils.LoadFromFile(winmd.FullName);
            bool emptyFound = false;
            foreach (DelegateTypeInfo type in w1.GetTypes().Where(t => t is DelegateTypeInfo))
            {
                if (!type.Parameters.Any())
                {
                    if (allowTable.Contains(type.Name))
                    {
                        continue;
                    }

                    if (!emptyFound)
                    {
                        emptyFound = true;
                        console.Out.Write("Empty delegates detected:\r\n");
                    }

                    console?.Out.Write($"{type.Name}\r\n");
                }
            }


            if (!emptyFound)
            {
                console.Out.Write("No empty delegates found.\r\n");
            }

            return emptyFound ? -1 : 0;
        }

        private static string GetArchInfo(IEnumerable<IAttribute> attributes)
        {
            var archAttr = attributes.FirstOrDefault(a => a.AttributeType.FullName == "Windows.Win32.Interop.SupportedArchitectureAttribute");
            if (archAttr != null)
            {
                Architecture arch = (Architecture)archAttr.FixedArguments[0].Value;
                return arch.ToString();
            }

            return string.Empty;
        }

        private static bool VerifyTypeHasRightArch(
            Dictionary<string, List<ITypeDefinition>> namesToArchDefs,
            IEntity owner,
            IType type,
            Architecture requiredArch,
            IConsole console)
        {
            bool success = true;

            if (owner != type)
            {
                var currentType = type;
                while (currentType.Kind == TypeKind.Array)
                {
                    ArrayType arrayType = (ArrayType)currentType;
                    currentType = arrayType.ElementType;
                }

                while (currentType.Kind == TypeKind.Pointer)
                {
                    PointerType pointerType = (PointerType)currentType;
                    currentType = pointerType.ElementType;
                }

                // If the type isn't in the map, it's not arch-specific, so return success
                if (!namesToArchDefs.TryGetValue(currentType.FullName, out var foundArchTypes))
                {
                    return true;
                }

                bool found = false;
                Architecture typeArches = Architecture.None;
                foreach (var archType in foundArchTypes)
                {
                    var typeArchAttr =
                        archType.GetAttributes().Single(a => a.AttributeType.FullName == "Windows.Win32.Interop.SupportedArchitectureAttribute");

                    var typeArch = (Architecture)typeArchAttr.FixedArguments[0].Value;
                    typeArches |= typeArch;
                    if ((typeArches & requiredArch) == requiredArch)
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    console.Out.Write($"{owner.FullName} supports '{requiredArch}' but referenced type {type.FullName} only supports '{typeArches}'");
                    success = false;
                }
            }

            if (type.Kind == TypeKind.Struct)
            {
                foreach (var field in type.GetFields())
                {
                    if (!VerifyTypeHasRightArch(namesToArchDefs, owner, field.Type, requiredArch, console))
                    {
                        success = false;
                    }
                }
            }
            else if (type.Kind == TypeKind.Delegate)
            {
                var invoke = type.GetMethods(m => m.Name == "Invoke").Single();
                foreach (var param in invoke.Parameters)
                {
                    if (!VerifyTypeHasRightArch(namesToArchDefs, owner, param.Type, requiredArch, console))
                    {
                        success = false;
                    }
                }
            }

            return success;
        }

        public static int ShowBrokenArchTypes(FileInfo winmd, IConsole console)
        {
            DecompilerTypeSystem winmd1 = DecompilerTypeSystemUtils.CreateTypeSystemFromFile(winmd.FullName);

            int badTopLevelTypes = 0;
            Dictionary<string, List<ITypeDefinition>> namesToArchDefs = new Dictionary<string, List<ITypeDefinition>>();

            foreach (var type in winmd1.GetTopLevelTypeDefinitions()
                .Where(t => t.GetAttributes()
                    .Any(a => a.AttributeType.FullName == "Windows.Win32.Interop.SupportedArchitectureAttribute")))
            {
                if (!namesToArchDefs.TryGetValue(type.FullName, out var list))
                {
                    list = new();
                    namesToArchDefs[type.FullName] = list;
                }

                list.Add(type);
            }

            foreach (var type in namesToArchDefs.SelectMany(map => map.Value))
            {
                var archAttr = type.GetAttributes().Single(a => a.AttributeType.FullName == "Windows.Win32.Interop.SupportedArchitectureAttribute");
                Architecture arch = (Architecture)archAttr.FixedArguments[0].Value;

                if (!VerifyTypeHasRightArch(namesToArchDefs, type, type, arch, console))
                {
                    badTopLevelTypes++;
                }
            }

            foreach (var apisClass in winmd1.GetTopLevelTypeDefinitions().Where(t => t.Kind == TypeKind.Class && t.Name == "Apis"))
            {
                foreach (var method in apisClass.Methods.Where(
                    m => m.IsStatic && m.DeclaringType == apisClass && m.GetAttributes()
                        .Any(a => a.AttributeType.FullName == "Windows.Win32.Interop.SupportedArchitectureAttribute")))
                {
                    var archAttr = method.GetAttributes().Single(a => a.AttributeType.FullName == "Windows.Win32.Interop.SupportedArchitectureAttribute");
                    Architecture arch = (Architecture)archAttr.FixedArguments[0].Value;

                    foreach (var param in method.Parameters)
                    {
                        VerifyTypeHasRightArch(namesToArchDefs, method, param.Type, arch, console);
                    }
                }
            }

            if (badTopLevelTypes == 0)
            {
                console.Out.Write("No broken arch-specific types or methods found.\r\n");
            }

            return badTopLevelTypes == 0 ? 0 : -1;
        }

        public static int ShowNamespaceCycles(FileInfo winmd, IConsole console)
        {
            bool cyclesFound = false;

            foreach (var item in NamespaceDependencyUtil.GetNamespaceDependencies(winmd.FullName))
            {
                if (item.CyclicalDependencyNamespaces.Any())
                {
                    console.Out.Write($"{item.Namespace}\r\n");

                    console.Out.Write($"  Cyclical dependent namespaces: {string.Join(", ", item.CyclicalDependencyNamespaces.ToArray())}\r\n");

                    cyclesFound = true;
                }
            }

            if (!cyclesFound)
            {
                console.Out.Write("No cycles found between any namespaces.\r\n");
            }

            return cyclesFound ? 1 : 0;
        }

        public static int ShowNamespaceDependencies(FileInfo winmd, string[] ignoreDependNamespace, string[] namespaceFilter, int maxBroughtInBy, int maxDependTypes, IConsole console)
        {
            List<Regex> namespaceFilterRegex = new List<Regex>();
            if (namespaceFilter != null)
            {
                foreach (var filterSpec in namespaceFilter)
                {
                    string fixedPattern = filterSpec.Replace(".", @"\.");
                    fixedPattern = fixedPattern.Replace("*", ".*");

                    if (!fixedPattern.StartsWith('^'))
                    {
                        fixedPattern = $"^{fixedPattern}";
                    }

                    if (!fixedPattern.EndsWith('$'))
                    {
                        fixedPattern = $"{fixedPattern}$";
                    }

                    namespaceFilterRegex.Add(new Regex(fixedPattern, RegexOptions.IgnoreCase));
                }
            }

            HashSet<string> ignoreNamespaces = new();
            foreach (var ns in ignoreDependNamespace)
            {
                ignoreNamespaces.Add(ns);
            }

            Dictionary<string, DependenciesInNamespace> namespaceToItem = new Dictionary<string, DependenciesInNamespace>();
            foreach (var item in NamespaceDependencyUtil.GetNamespaceDependencies(winmd.FullName))
            {
                namespaceToItem[item.Namespace] = item;
            }

            foreach (var pair in namespaceToItem.OrderBy(x => x.Key))
            {
                var item = pair.Value;
                bool isMatch = namespaceFilterRegex.Count == 0 || namespaceFilterRegex.Any(r => r.IsMatch(item.Namespace));
                if (!isMatch)
                {
                    continue;
                }

                console.Out.Write($"{item.Namespace}\r\n");

                string[] allDependNamespaces = item.AllDependencyNamespaces.Where(ns => !ignoreNamespaces.Contains(ns)).ToArray();
                if (allDependNamespaces.Length != 0)
                {
                    console.Out.Write($"  All dependent namespaces: {string.Join(", ", allDependNamespaces)}\r\n");
                }

                if (item.CyclicalDependencyNamespaces.Any())
                {
                    console.Out.Write($"  Cyclical dependent namespaces: {string.Join(", ", item.CyclicalDependencyNamespaces.ToArray())}\r\n");
                }

                var allDependsByNamespace = item.GetDependenciesByNamespace().Where(d => !ignoreNamespaces.Contains(d.Key)).ToArray();
                foreach (var dependsByNamespace in allDependsByNamespace)
                {
                    var currentNamespace = dependsByNamespace.Key;

                    console.Out.Write($"  {dependsByNamespace.Key}\r\n");

                    var allDependTypes = dependsByNamespace.Value.ToArray();
                    var dependCount = 0;
                    foreach (var depend in allDependTypes)
                    {
                        if (dependCount >= maxDependTypes)
                        {
                            int remainingCount = allDependTypes.Length - dependCount;
                            console.Out.Write($"    ({remainingCount} more...)\r\n");
                            break;
                        }

                        console.Out.Write($"    {depend.Type.Name}: ");

                        dependCount++;

                        bool first = true;
                        string[] broughtInByItems = depend.BroughtInBy.ToArray();
                        int broughtInCount = 0;
                        foreach (var broughtInBy in broughtInByItems)
                        {
                            if (broughtInCount == maxBroughtInBy)
                            {
                                int itemsRemaining = broughtInByItems.Length - broughtInCount;
                                console.Out.Write($" ({itemsRemaining} more...)");
                                break;
                            }

                            if (first)
                            {
                                first = false;
                            }
                            else
                            {
                                console.Out.Write(", ");
                            }

                            console.Out.Write(broughtInBy);
                            broughtInCount++;
                        }

                        console.Out.Write("\r\n");
                    }

                    console.Out.Write("\r\n");
                }

                if (allDependsByNamespace.Length != 0)
                {
                    console.Out.Write("\r\n\r\n");
                }
            }

            return 0;
        }

        public static int ShowDuplicateImports(FileInfo winmd, IConsole console)
        {
            DecompilerSettings settings = new DecompilerSettings() { ThrowOnAssemblyResolveErrors = false };
            DecompilerTypeSystem winmd1 = DecompilerTypeSystemUtils.CreateTypeSystemFromFile(winmd.FullName);

            Dictionary<string, List<string>> dllImportsToClassNames = new Dictionary<string, List<string>>();

            foreach (var type1 in winmd1.GetTopLevelTypeDefinitions())
            {
                if (type1.FullName == "<Module>")
                {
                    continue;
                }

                if (type1.ParentModule != winmd1.MainModule)
                {
                    continue;
                }

                if (type1.Kind != TypeKind.Class)
                {
                    continue;
                }

                foreach (var method in type1.GetMethods())
                {
                    if (!method.IsStatic)
                    {
                        continue;
                    }

                    var dllImportAttr = method.GetAttribute(KnownAttribute.DllImport);
                    if (dllImportAttr != null)
                    {
                        string entryPoint = method.Name;
                        var dllName = (string)(dllImportAttr.FixedArguments[0].Value);
                        var entryPointVar = dllImportAttr.NamedArguments.FirstOrDefault(a => a.Name == "EntryPoint");
                        if (entryPointVar.Name != null)
                        {
                            entryPoint = (string)entryPointVar.Value;
                        }

                        string fullImport = $"{dllName}:{entryPoint}";
                        string archInfo = GetArchInfo(method.GetAttributes());
                        if (!string.IsNullOrEmpty(archInfo))
                        {
                            fullImport += $"({archInfo})";
                        }

                        if (!dllImportsToClassNames.TryGetValue(fullImport, out var classNames))
                        {
                            classNames = new List<string>();
                            dllImportsToClassNames[fullImport] = classNames;
                        }

                        classNames.Add(type1.FullName);
                    }
                }
            }

            bool dupsFound = false;
            foreach (var pair in dllImportsToClassNames)
            {
                if (pair.Value.Count > 1)
                {
                    if (dupsFound == false)
                    {
                        dupsFound = true;
                        console.Out.Write("Duplicated imports detected:\r\n");
                    }

                    pair.Value.Sort();

                    console?.Out.Write($"{pair.Key}\r\n");
                    foreach (var imp in pair.Value)
                    {
                        console?.Out.Write($"  {imp}\r\n");
                    }
                }
            }

            if (!dupsFound)
            {
                console.Out.Write("No duplicate imports found.\r\n");
            }

            return dupsFound ? -1 : 0;
        }

        public static bool CompareFields(IField field1, IField field2, IConsole console)
        {
            bool ret = CompareAttributes(field1.Name, field1.GetAttributes(), field2.GetAttributes(), console);

            // Using the ReflectionName gets us the name of the type in
            // metadata. The FullName might not be fully resolvable by the
            // library because it doesn't know how to resolve arch-specific types
            if (field1.Type.ReflectionName != field2.Type.ReflectionName)
            {
                console?.Out.Write($"{field1.DeclaringType.FullName}.{field1.Name}...{field1.Type.ReflectionName} => {field2.Type.ReflectionName}\r\n");
                ret = false;
            }
            else
            {
                if (field1.IsConst)
                {
                    if (!field2.IsConst)
                    {
                        console?.Out.Write($"winmd1: {field1.Name} const, winmd2: not\r\n");
                        ret = false;
                    }
                    else
                    {
                        var fieldVal1 = field1.GetConstantValue();
                        var fieldVal2 = field2.GetConstantValue();

                        if (fieldVal1 == null)
                        {
                            console?.Out.Write($"winmd1: {field1.Name} is a constant with a null value\r\n");
                        }

                        if (fieldVal2 == null)
                        {
                            console?.Out.Write($"winmd2: {field2.Name} is a constant with a null value\r\n");
                        }

                        string val1 = fieldVal1?.ToString();
                        string val2 = fieldVal2?.ToString();

                        if (val1 != val2)
                        {
                            console?.Out.Write($"winmd1: {field1.Name} = {val1}, winmd2 = {val2}\r\n");
                            ret = false;
                        }
                    }
                }
                else if (field2.IsConst)
                {
                    if (!field2.IsConst)
                    {
                        console?.Out.Write($"winmd1: {field1.Name} not const, winmd2: const\r\n");
                        ret = false;
                    }
                }
            }

            return ret;
        }

        public static bool CompareFieldsOnTypes(ITypeDefinition type1, ITypeDefinition type2, IConsole console)
        {
            bool ret = true;

            Dictionary<string, IField> type2Fields = new Dictionary<string, IField>();
            foreach (var field2 in type2.Fields)
            {
                type2Fields[field2.Name] = field2;
            }

            foreach (var field1 in type1.Fields)
            {
                if (!type2Fields.TryGetValue(field1.Name, out var field2))
                {
                    ret = false;
                    console?.Out.Write($"{field1.FullName} not found in 2nd winmd\r\n");
                    continue;
                }

                type2Fields.Remove(field2.Name);

                ret &= CompareFields(field1, field2, console);
            }

            foreach (var field2 in type2Fields.Values)
            {
                console?.Out.Write($"{field2.FullName} not found in 1st winmd\r\n");
                ret = false;
            }

            return ret;
        }

        private static string GetMethodNameWithParams(IMethod method)
        {
            string name = method.Name;
            if (method.DeclaringType.Kind == TypeKind.Delegate && name.EndsWith(".Invoke"))
            {
                name = name.Substring(0, name.Length - ".Invoke".Length);
            }

            StringBuilder methodName = new StringBuilder(name);
            methodName.Append('(');
            bool first = true;
            foreach (var p in method.Parameters)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    methodName.Append(',');
                }

                methodName.Append(p.Name);
            }

            methodName.Append(')');

            string archInfo = GetArchInfo(method.GetAttributes());
            if (!string.IsNullOrEmpty(archInfo))
            {
                methodName.Append($"({archInfo})");
            }

            return methodName.ToString();
        }

        private static Dictionary<string, IMethod> GetMethodMap(ITypeDefinition type)
        {
            var typeMethods = new Dictionary<string, IMethod>();
            foreach (var method in type.Methods)
            {
                if (method.Name == ".ctor")
                {
                    continue;
                }

                string name = GetMethodNameWithParams(method);
                if (typeMethods.ContainsKey(name))
                {
                    for (int i = 2; ; i++)
                    {
                        string newName = $"{name}_{i}";
                        if (typeMethods.ContainsKey(newName))
                        {
                            continue;
                        }

                        name = newName;
                        break;
                    }
                }

                typeMethods[name] = method;
            }

            return typeMethods;
        }

        private static string ConvertAttributeToText(IAttribute attr)
        {
            string name = attr.AttributeType.Name;
            if (name.EndsWith("Attribute"))
            {
                name = name.Substring(0, name.Length - "Attribute".Length);
            }

            StringBuilder ret = new StringBuilder(name);
            bool first = true;
            foreach (var fixedArg in attr.FixedArguments)
            {
                if (!first)
                {
                    ret.Append(',');
                }
                else
                {
                    ret.Append('(');
                    first = false;
                }

                ret.Append(fixedArg.Value.ToString());
            }

            foreach (var namedArg in attr.NamedArguments)
            {
                if (!first)
                {
                    ret.Append(',');
                }
                else
                {
                    ret.Append('(');
                    first = false;
                }

                ret.Append($"{namedArg.Name}={namedArg.Value}");
            }

            if (!first)
            {
                ret.Append(')');
            }

            return ret.ToString();
        }

        private static string ConvertAttributesToText(IEnumerable<IAttribute> attrs)
        {
            StringBuilder stringBuilder = new StringBuilder();
            foreach (var attr in attrs.OrderBy(a => a.AttributeType.Name))
            {
                if (stringBuilder.Length != 0)
                {
                    stringBuilder.Append(',');
                }

                stringBuilder.Append(ConvertAttributeToText(attr));
            }

            if (stringBuilder.Length == 0)
            {
                return string.Empty;
            }

            stringBuilder.Insert(0, '[');
            stringBuilder.Append(']');
            return stringBuilder.ToString();
        }

        public static bool CompareAttributes(string fullName, IEnumerable<IAttribute> attrs1, IEnumerable<IAttribute> attrs2, IConsole console)
        {
            bool ret = true;

            string attrText1 = ConvertAttributesToText(attrs1);
            string attrText2 = ConvertAttributesToText(attrs2);

            if (attrText1 != attrText2)
            {
                console?.Out.Write($"{fullName} : {attrText1} => {attrText2}\r\n");
                ret = false;
            }

            return ret;
        }

        public static bool CompareMethods(IMethod method1, IMethod method2, IConsole console)
        {
            bool ret = true;

            string methodFullName = GetFullMemberName(method1);

            ret &= CompareAttributes(methodFullName, method1.GetAttributes(), method2.GetAttributes(), console);

            // Return param
            string returnFullName = $"{methodFullName} : return";
            ret &= CompareAttributes(returnFullName, method1.GetReturnTypeAttributes(), method2.GetReturnTypeAttributes(), console);
            if (method1.ReturnType.Name != method2.ReturnType.Name)
            {
                console?.Out.Write($"{returnFullName}...{method1.ReturnType.Name} => {method2.ReturnType.Name}\r\n");
                ret = false;
            }

            // Params
            foreach (var param1 in method1.Parameters)
            {
                var param2 = method2.Parameters.FirstOrDefault(p => p.Name == param1.Name);
                if (param2 == null)
                {
                    console?.Out.Write($"{methodFullName}, param {param1.Name} not found in 2nd winmd\r\n");
                    ret = false;
                    continue;
                }

                string paramFullName = $"{methodFullName} : {param1.Name}";
                if (param1.Type.Name != param2.Type.Name)
                {
                    console?.Out.Write($"{paramFullName}...{param1.Type.Name} => {param2.Type.Name}\r\n");
                    ret = false;
                }

                ret &= CompareAttributes(paramFullName, param1.GetAttributes(), param2.GetAttributes(), console);
            }

            return ret;
        }

        public static bool CompareMethodsOnType(ITypeDefinition type1, ITypeDefinition type2, IConsole console)
        {
            bool ret = true;

            var type1Methods = GetMethodMap(type1);
            var type2Methods = GetMethodMap(type2);

            foreach (var methodPair in type1Methods)
            {
                if (methodPair.Key == ".ctor")
                {
                    continue;
                }

                string methodFullName = methodPair.Key;
                if (!type2Methods.TryGetValue(methodFullName, out var method2))
                {
                    console?.Out.Write($"{methodFullName} not found in 2nd winmd\r\n");
                    ret = false;
                    continue;
                }

                var method1 = methodPair.Value;
                type2Methods.Remove(methodFullName);

                ret &= CompareMethods(method1, method2, console);
            }

            foreach (var method2 in type2Methods.Values)
            {
                console?.Out.Write($"{method2.FullName} not found in 1st winmd\r\n");
                ret = false;
            }

            return ret;
        }

        public static bool CompareTypes(ITypeDefinition type1, ITypeDefinition type2, IConsole console)
        {
            bool ret = true;

            ret &= CompareFieldsOnTypes(type1, type2, console);
            ret &= CompareMethodsOnType(type1, type2, console);
            ret &= CompareAttributes(type1.FullName, type1.GetAttributes(), type2.GetAttributes(), console);
            ret &= CompareTypes(type1.NestedTypes, type2.NestedTypes, console);

            return ret;
        }

        private static string GetFullTypeName(ITypeDefinition typeDefinition)
        {
            string name = typeDefinition.FullName;
            string archInfo = GetArchInfo(typeDefinition.GetAttributes());
            if (!string.IsNullOrEmpty(archInfo))
            {
                name += $"({archInfo})";
            }

            return name;
        }

        private static string GetFullMemberName(IMember member)
        {
            string name = member.FullName;
            string archInfo = GetArchInfo(member.GetAttributes());
            if (!string.IsNullOrEmpty(archInfo))
            {
                name += $"({archInfo})";
            }

            return name;
        }

        private static Dictionary<string, List<IMember>> GetApiMemberNamesToMemberDefinitions(DecompilerTypeSystem winmd)
        {
            Dictionary<string, List<IMember>> ret = new Dictionary<string, List<IMember>>();
            foreach (var type1 in winmd.GetTopLevelTypeDefinitions())
            {
                if (type1.FullName == "<Module>")
                {
                    continue;
                }

                if (type1.ParentModule != winmd.MainModule)
                {
                    continue;
                }

                if (type1.Kind != TypeKind.Class || type1.Name != "Apis")
                {
                    continue;
                }

                foreach (var m in type1.Members)
                {
                    string name = m.Name;
                    string archInfo = GetArchInfo(m.GetAttributes());
                    if (!string.IsNullOrEmpty(archInfo))
                    {
                        name += $"({archInfo})";
                    }

                    if (!ret.TryGetValue(name, out var list))
                    {
                        list = new List<IMember>();
                        ret[name] = list;
                    }

                    list.Add(m);
                }
            }

            return ret;
        }

        private static Dictionary<string, List<ITypeDefinition>> GetShortNamesToTypeDefinitions(IEnumerable<ITypeDefinition> types)
        {
            Dictionary<string, List<ITypeDefinition>> ret = new Dictionary<string, List<ITypeDefinition>>();
            foreach (var type1 in types)
            {
                string name = type1.Name;
                if (!ret.TryGetValue(name, out var list))
                {
                    list = new List<ITypeDefinition>();
                    ret[name] = list;
                }

                list.Add(type1);
            }

            return ret;
        }

        private static Dictionary<string, ITypeDefinition> GetNamesToTypeDefinitions(IEnumerable<ITypeDefinition> types)
        {
            Dictionary<string, ITypeDefinition> ret = new Dictionary<string, ITypeDefinition>();
            foreach (var type1 in types)
            {
                string name = GetFullTypeName(type1);
                ret[name] = type1;
            }

            return ret;
        }

        private static IEnumerable<ITypeDefinition> GetSelfDefinedWinmdToplevelTypes(DecompilerTypeSystem winmd)
        {
            return winmd.GetTopLevelTypeDefinitions().Where(
                type => type.ParentModule == winmd.MainModule && type.FullName != "<Module>");
        }

        private static bool CompareTypes(IEnumerable<ITypeDefinition> types1, IEnumerable<ITypeDefinition> types2, IConsole console)
        {
            Dictionary<string, ITypeDefinition> winmd2NamesToTypes = GetNamesToTypeDefinitions(types2);
            Dictionary<string, List<ITypeDefinition>> winmd2ShortNamesToTypes = GetShortNamesToTypeDefinitions(types2);
            bool same = true;

            HashSet<string> visitedNames = new HashSet<string>();
            foreach (var type1 in types1)
            {
                // We'll compare the members of Apis in their own way
                if (type1.Name == "Apis")
                {
                    continue;
                }

                var type1Name = GetFullTypeName(type1);
                visitedNames.Add(type1Name);

                winmd2NamesToTypes.TryGetValue(type1Name, out var type2);
                if (type2 == null)
                {
                    if (winmd2ShortNamesToTypes.TryGetValue(type1.Name, out var list))
                    {
                        foreach (var t2 in list)
                        {
                            if (CompareTypes(type1, t2, null))
                            {
                                var type2Name = GetFullTypeName(t2);
                                console?.Out.Write($"{type1Name} => {type2Name}\r\n");
                                visitedNames.Add(type2Name);
                                same = false;
                                type2 = t2;
                                break;
                            }
                        }
                    }

                    if (type2 == null)
                    {
                        console?.Out.Write($"{type1Name} not found in 2nd winmd\r\n");
                        same = false;
                    }

                    continue;
                }

                same &= CompareTypes(type1, type2, console);
            }

            Dictionary<string, ITypeDefinition> winmd1NamesToTypes = GetNamesToTypeDefinitions(types1);
            foreach (var type2 in types2)
            {
                // We'll compare the members of Apis in their own way
                if (type2.Name == "Apis")
                {
                    continue;
                }

                var type2FullName = GetFullTypeName(type2);
                if (visitedNames.Contains(type2FullName))
                {
                    continue;
                }

                winmd1NamesToTypes.TryGetValue(type2FullName, out var type1);
                if (type1 == null)
                {
                    console?.Out.Write($"{type2FullName} not found in 1st winmd\r\n");
                    same = false;
                }
            }

            return same;
        }

        public static int CompareWinmds(FileInfo first, FileInfo second, string exclusions, IConsole console)
        {
            bool same = true;

            DecompilerTypeSystem winmd1 = DecompilerTypeSystemUtils.CreateTypeSystemFromFile(first.FullName);
            DecompilerTypeSystem winmd2 = DecompilerTypeSystemUtils.CreateTypeSystemFromFile(second.FullName);

            CompareAttributes("Assembly (informational only)", winmd1.MainModule.GetAssemblyAttributes(), winmd2.MainModule.GetAssemblyAttributes(), console);

            var winmd1Types = GetSelfDefinedWinmdToplevelTypes(winmd1);
            var winmd2Types = GetSelfDefinedWinmdToplevelTypes(winmd2);

            same &= CompareTypes(winmd1Types, winmd2Types, console);

            var apiNameToMembers1 = GetApiMemberNamesToMemberDefinitions(winmd1);
            var apiNameToMembers2 = GetApiMemberNamesToMemberDefinitions(winmd2);

            HashSet<string> visitedM2Names = new HashSet<string>();
            foreach (var api1MemberInfo in apiNameToMembers1)
            {
                if (apiNameToMembers2.TryGetValue(api1MemberInfo.Key, out var api2Members))
                {
                    foreach (var m1 in api1MemberInfo.Value)
                    {
                        string m1FullName = GetFullMemberName(m1);
                        bool found = false;

                        foreach (var m2 in api2Members)
                        {
                            if (m1.GetType() == m2.GetType())
                            {
                                string m2FullName = GetFullMemberName(m2);

                                bool membersSame;
                                if (m1 is IField)
                                {
                                    membersSame = CompareFields((IField)m1, (IField)m2, console);
                                }
                                else
                                {
                                    membersSame = CompareMethods((IMethod)m1, (IMethod)m2, null);

                                    // If the members aren't the same on the methods and the namespaces also aren't
                                    // the same, then assume these aren't the same methods and keep going
                                    if (!membersSame && (m1.Namespace != m2.Namespace))
                                    {
                                        continue;
                                    }

                                    if (!membersSame && console != null)
                                    {
                                        CompareMethods((IMethod)m1, (IMethod)m2, console);
                                    }
                                }

                                if (membersSame)
                                {
                                    if (m1.Namespace != m2.Namespace)
                                    {
                                        console?.Out.Write($"{m1FullName} => {m2FullName}\r\n");
                                        membersSame = false;
                                    }
                                }

                                same &= membersSame;

                                visitedM2Names.Add(m2FullName);
                                found = true;
                                break;
                            }
                        }

                        if (!found)
                        {
                            console?.Out.Write($"{m1FullName} not found in 2nd winmd\r\n");
                        }
                    }
                }
                else
                {
                    foreach (var m1 in api1MemberInfo.Value)
                    {
                        string m1FullName = GetFullMemberName(m1);
                        console?.Out.Write($"{m1FullName} not found in 2nd winmd\r\n");
                        same = false;
                    }
                }
            }

            foreach (var api2MemberInfo in apiNameToMembers2)
            {
                foreach (var api2Member in api2MemberInfo.Value)
                {
                    string m2FullName = GetFullMemberName(api2Member);
                    if (!visitedM2Names.Contains(m2FullName))
                    {
                        console?.Out.Write($"{m2FullName} not found in 1st winmd\r\n");
                        same = false;
                    }
                }
            }

            if (same)
            {
                console.Out.Write($"No differences in winmd contents.\r\n");
            }

            return same ? 0 : -1;
        }

        public static int ShowMissingImports(FileInfo first, FileInfo second, string exclusions, IConsole console)
        {
            int ret = 0;

            using WinmdUtils w1 = WinmdUtils.LoadFromFile(first.FullName);
            HashSet<string> remainingImports = new HashSet<string>();
            foreach (var imp in w1.GetDllImports())
            {
                remainingImports.Add(imp.Name.ToString());
            }

            using WinmdUtils w2 = WinmdUtils.LoadFromFile(second.FullName);
            foreach (var imp in w2.GetDllImports())
            {
                var text = imp.Name.ToString();
                if (remainingImports.Contains(text))                                
                {
                    remainingImports.Remove(text);
                }
            }

            foreach (var imp in remainingImports)
            {
                if (ret == 0)
                {
                    console.Out.Write("Missing imports detected:\r\n");
                    ret = -1;
                }

                console?.Out.Write($"{imp}\r\n");
            }
            
            if (ret == 0)
            {
                console.Out.Write("No missing imports found.\r\n");
            }

            return ret;
        }
    }
}

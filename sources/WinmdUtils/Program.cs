using System;
using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;

namespace WinmdUtils
{
    class Program
    {
        static int Main(string[] args)
        {
            var showMissingImportsCommand = new Command("showMissingImports", "Show missing imports between two winmd files.")
            {
                new Option(new[] { "--first" }, "The first winmd.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
                new Option(new[] { "--second" }, "The second winmd.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
                new Option(new[] { "--exclusions" }, "Exclusions files.") { Argument = new Argument<string>(), IsRequired = false },
            };

            showMissingImportsCommand.Handler = CommandHandler.Create<FileInfo, FileInfo, string, IConsole>(ShowMissingImports);

            var showDuplicateImports = new Command("showDuplicateImports", "Show duplicate imports in a single winmd files.")
            {
                new Option(new[] { "--winmd" }, "The winmd to inspect.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
            };

            showDuplicateImports.Handler = CommandHandler.Create<FileInfo, IConsole>(ShowDuplicateImports);

            var showDuplicateTypes = new Command("showDuplicateTypes", "Show duplicate types in a single winmd files.")
            {
                new Option(new[] { "--winmd" }, "The winmd to inspect.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
            };

            showDuplicateTypes.Handler = CommandHandler.Create<FileInfo, IConsole>(ShowDuplicateTypes);

            var showDuplicateConstants = new Command("showDuplicateConstants", "Show duplicate constants in a single winmd files.")
            {
                new Option(new[] { "--winmd" }, "The winmd to inspect.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
            };

            showDuplicateConstants.Handler = CommandHandler.Create<FileInfo, IConsole>(ShowDuplicateConstants);

            var showEmptyDelegates = new Command("showEmptyDelegates", "Show delegates that have no parameters.")
            {
                new Option(new[] { "--winmd" }, "The winmd to inspect.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
                new Option(new string[] { "--allowItem", "-i" }, "Item to allow and not flag as an error.")
                {
                    Argument = new Argument("<name>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
            };

            showEmptyDelegates.Handler = CommandHandler.Create<FileInfo, string[], IConsole>(ShowEmptyDelegates);

            var showPointersToDelegates = new Command("showPointersToDelegates", "Show pointers to delegates.")
            {
                new Option(new[] { "--winmd" }, "The winmd to inspect.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
                new Option(new string[] { "--allowItem", "-i" }, "Item to allow and not flag as an error.")
                {
                    Argument = new Argument("<name>")
                    {
                        ArgumentType = typeof(string),
                        Arity = ArgumentArity.OneOrMore,
                    }
                },
            };

            showPointersToDelegates.Handler = CommandHandler.Create<FileInfo, string[], IConsole>(ShowPointersToDelegates);

            var rootCommand = new RootCommand("Win32metadata winmd utils")
            {
                showMissingImportsCommand,
                showDuplicateImports,
                showDuplicateTypes,
                showDuplicateConstants,
                showEmptyDelegates,
                showPointersToDelegates
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

        private static string GetPointerTypeToOneOfNamesInUseByParameter(HashSet<string> typeNames, MethodSignature<string> methodSignature, IEnumerable<ParameterInfo> parameterInfos)
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

        private static IEnumerable<PointerInfo> PointerToOneOfNamesInUse(HashSet<string> typeNames, TypeInfo typeInfo)
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

                    console.Out.Write($"{pointerInUse.Type},{pointerInUse.Name}\r\n");
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
            using WinmdUtils w1 = WinmdUtils.LoadFromFile(winmd.FullName);
            Dictionary<string, List<string>> nameToNamespace = new Dictionary<string, List<string>>();
            foreach (var constant in w1.GetConstants())
            {
                if (!nameToNamespace.TryGetValue(constant.Name, out var namespaces))
                {
                    namespaces = new List<string>();
                    nameToNamespace[constant.Name] = namespaces;
                }

                namespaces.Add(constant.Namespace);
            }

            bool dupsFound = false;
            foreach (var pair in nameToNamespace)
            {
                if (pair.Value.Count > 1)
                {
                    if (dupsFound == false)
                    {
                        dupsFound = true;
                        console.Out.Write("Duplicate constants detected:\r\n");
                    }

                    pair.Value.Sort();

                    console.Out.Write($"{pair.Key}\r\n");
                    foreach (var @namespace in pair.Value)
                    {
                        console.Out.Write($"  {@namespace}\r\n");
                    }
                }
            }

            if (!dupsFound)
            {
                console.Out.Write("No duplicate constants found.\r\n");
            }

            return dupsFound ? -1 : 0;
        }

        public static int ShowDuplicateTypes(FileInfo winmd, IConsole console)
        {
            using WinmdUtils w1 = WinmdUtils.LoadFromFile(winmd.FullName);
            Dictionary<string, List<string>> nameToTypes = new Dictionary<string, List<string>>();
            foreach (var type in w1.GetTypes())
            {
                if (type is ClassInfo && type.Name == "Apis")
                {
                    continue;
                }

                var toString = type.ToString();
                if (!nameToTypes.TryGetValue(toString, out var structs))
                {
                    structs = new List<string>();
                    nameToTypes[toString] = structs;
                }

                structs.Add(type.Namespace);
            }

            bool dupsFound = false;
            foreach (var pair in nameToTypes)
            {
                if (pair.Value.Count > 1)
                {
                    if (dupsFound == false)
                    {
                        dupsFound = true;
                        console.Out.Write("Duplicate types detected:\r\n");
                    }

                    pair.Value.Sort();

                    console.Out.Write($"{pair.Key}\r\n");
                    foreach (var type in pair.Value)
                    {
                        console.Out.Write($"  {type}\r\n");
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

                    console.Out.Write($"{type.Name}\r\n");
                }
            }


            if (!emptyFound)
            {
                console.Out.Write("No empty delegates found.\r\n");
            }

            return emptyFound ? -1 : 0;
        }

        public static int ShowDuplicateImports(FileInfo winmd, IConsole console)
        {
            using WinmdUtils w1 = WinmdUtils.LoadFromFile(winmd.FullName);
            Dictionary<string, List<string>> nameToImports = new Dictionary<string, List<string>>();
            foreach (var imp in w1.GetDllImports())
            {
                if (!nameToImports.TryGetValue(imp.Name, out var imports))
                {
                    imports = new List<string>();
                    nameToImports[imp.Name] = imports;
                }

                imports.Add(imp.DeclaringType);
            }

            bool dupsFound = false;
            foreach (var pair in nameToImports)
            {
                if (pair.Value.Count > 1)
                {
                    if (dupsFound == false)
                    {
                        dupsFound = true;
                        console.Out.Write("Duplicated imports detected:\r\n");
                    }

                    pair.Value.Sort();

                    console.Out.Write($"{pair.Key}\r\n");
                    foreach (var imp in pair.Value)
                    {
                        console.Out.Write($"  {imp}\r\n");
                    }
                }
            }

            if (!dupsFound)
            {
                console.Out.Write("No duplicate imports found.\r\n");
            }

            return dupsFound ? -1 : 0;
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

                console.Out.Write($"{imp}\r\n");
            }
            
            if (ret == 0)
            {
                console.Out.Write("No missing imports found.\r\n");
            }

            return ret;
        }
    }
}

using System;
using System.Collections.Generic;
using System.CommandLine;
using System.CommandLine.Invocation;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Text;
using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.Metadata;
using ICSharpCode.Decompiler.TypeSystem;
using Windows.Win32.Interop;

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

            var compareCommand = new Command("compare", "Compare two winmd files.")
            {
                new Option(new[] { "--first" }, "The first winmd.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
                new Option(new[] { "--second" }, "The second winmd.") { Argument = new Argument<FileInfo>().ExistingOnly(), IsRequired = true },
            };

            compareCommand.Handler = CommandHandler.Create<FileInfo, FileInfo, string, IConsole>(CompareWinmds);

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
                showPointersToDelegates,
                compareCommand
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
            HashSet<string> allowTable = allowItem != null ? new HashSet<string>(allowItem) : new HashSet<string>();
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
            DecompilerSettings settings = new DecompilerSettings() { ThrowOnAssemblyResolveErrors = false };
            DecompilerTypeSystem winmd1 = CreateTypeSystemFromFile(winmd.FullName, settings);
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
                    foreach (var field in type.GetFields())
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
            DecompilerSettings settings = new DecompilerSettings() { ThrowOnAssemblyResolveErrors = false };
            DecompilerTypeSystem winmd1 = CreateTypeSystemFromFile(winmd.FullName, settings);

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
            HashSet<string> allowTable = allowItem != null ? new HashSet<string>(allowItem) : new HashSet<string>();
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

        public static int ShowDuplicateImports(FileInfo winmd, IConsole console)
        {
            DecompilerSettings settings = new DecompilerSettings() { ThrowOnAssemblyResolveErrors = false };
            DecompilerTypeSystem winmd1 = CreateTypeSystemFromFile(winmd.FullName, settings);

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

        static PEFile LoadPEFile(string fileName, DecompilerSettings settings)
        {
            settings.LoadInMemory = true;
            return new PEFile(
                fileName,
                new FileStream(fileName, FileMode.Open, FileAccess.Read),
                streamOptions: PEStreamOptions.PrefetchEntireImage,
                metadataOptions: settings.ApplyWindowsRuntimeProjections ? MetadataReaderOptions.ApplyWindowsRuntimeProjections : MetadataReaderOptions.None
            );
        }

        static DecompilerTypeSystem CreateTypeSystemFromFile(string fileName, DecompilerSettings settings)
        {
            settings.LoadInMemory = true;
            var file = LoadPEFile(fileName, settings);
            var resolver = new UniversalAssemblyResolver(fileName, settings.ThrowOnAssemblyResolveErrors, file.DetectTargetFrameworkId());
            return new DecompilerTypeSystem(file, resolver);
        }

        public static bool CompareFields(ITypeDefinition type1, ITypeDefinition type2, IConsole console)
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
                    console?.Out.Write($"{field1.Name} not found in 2nd winmd\r\n");
                    continue;
                }

                type2Fields.Remove(field2.Name);

                if (field1.Type.Name != field2.Type.Name)
                {
                    console?.Out.Write($"{type1.FullTypeName}.{field1.Name}...{field1.Type.Name} => {field2.Type.Name}\r\n");
                    ret = false;
                    continue;
                }

                ret &= CompareAttributes(field1.Name, field1.GetAttributes(), field2.GetAttributes(), console);

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

                        if (fieldVal1.ToString() != fieldVal2.ToString())
                        {
                            console?.Out.Write($"winmd1: {field1.Name} = {fieldVal1}, winmd2 = {fieldVal2}\r\n");
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

            foreach (var field2 in type2Fields.Values)
            {
                console?.Out.Write($"{field2.Name} not found in 1st winmd\r\n");
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
            foreach (var attr in attrs)
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

        public static bool CompareMethods(ITypeDefinition type1, ITypeDefinition type2, IConsole console)
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

            ret &= CompareFields(type1, type2, console);
            ret &= CompareMethods(type1, type2, console);
            ret &= CompareAttributes(type1.FullName, type1.GetAttributes(), type2.GetAttributes(), console);

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

        private static Dictionary<string, List<ITypeDefinition>> GetShortNamesToTypeDefinitions(DecompilerTypeSystem winmd)
        {
            Dictionary<string, List<ITypeDefinition>> ret = new Dictionary<string, List<ITypeDefinition>>();
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

        private static Dictionary<string, ITypeDefinition> GetNamesToTypeDefinitions(DecompilerTypeSystem winmd)
        {
            Dictionary<string, ITypeDefinition> ret = new Dictionary<string, ITypeDefinition>();
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

                string name = GetFullTypeName(type1);
                ret[name] = type1;
            }

            return ret;
        }

        public static int CompareWinmds(FileInfo first, FileInfo second, string exclusions, IConsole console)
        {
            bool same = true;

            DecompilerSettings settings = new DecompilerSettings() { ThrowOnAssemblyResolveErrors = false };
            DecompilerTypeSystem winmd1 = CreateTypeSystemFromFile(first.FullName, settings);
            DecompilerTypeSystem winmd2 = CreateTypeSystemFromFile(second.FullName, settings);
            Dictionary<string, ITypeDefinition> winmd2NamesToTypes = GetNamesToTypeDefinitions(winmd2);
            Dictionary<string, List<ITypeDefinition>> winmd2ShortNamesToTypes = GetShortNamesToTypeDefinitions(winmd2);

            HashSet<string> visitedNames = new HashSet<string>();
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

            Dictionary<string, ITypeDefinition> winmd1NamesToTypes = GetNamesToTypeDefinitions(winmd1);
            foreach (var type2 in winmd2.GetTopLevelTypeDefinitions())
            {
                if (type2.FullName == "<Module>")
                {
                    continue;
                }

                var type2FullName = GetFullTypeName(type2);
                if (type2.ParentModule != winmd2.MainModule)
                {
                    continue;
                }

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

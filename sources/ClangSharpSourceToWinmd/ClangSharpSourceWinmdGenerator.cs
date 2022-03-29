// This adds the enclosing symbol name to the neseted type name.
// Can help disambiguate where a name came from when looking at a winmd
//#define MakeShortNameIncludeEnclosingName

using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using MetadataUtils;

namespace ClangSharpSourceToWinmd
{
    public class ClangSharpSourceWinmdGenerator
    {
        public const string Win32WideStringType = "Windows.Win32.Foundation.PWSTR";
        public const string Win32StringType = "Windows.Win32.Foundation.PSTR";

        private const string InteropNamespace = "Windows.Win32.Interop";
        private const string ScannedSuffix = "__scanned__";
        private const string RemovePrefix = "__remove__";

        private const string SystemAssemblyName = "netstandard";
        private const string Win32InteropAssemblyName = "Windows.Win32.Interop";
        private const string Win32MetadataAssemblyName = "Windows.Win32.winmd";

        private static readonly Regex TypeImportRegex = new Regex(@"<(([^,]+),\s*Version=(\d+\.\d+\.\d+\.\d+),\s*Culture=([^,]+),\s*PublicKeyToken=([^>]+))>(\S+)");
        private static readonly Regex IsSpecialNameRegex = new Regex(@"^(?:get_|put_|add_|remove_|invoke_)");
        private static readonly Regex IsWcharRegex = new Regex(@"^(?:WCHAR|OLECHAR|wchar_t)");
        private static readonly Regex IsCharRegex = new Regex(@"^(?:CHAR|char)");
        private static readonly Regex ArrayMatcher = new Regex(@"\[\d*\]");

        private MetadataBuilder metadataBuilder = new MetadataBuilder();
        private CSharpCompilation compilation;
        private ModuleDefinitionHandle moduleRef;
        private Dictionary<string, TypeReferenceHandle> namesToTypeRefHandles = new Dictionary<string, TypeReferenceHandle>();
        private Dictionary<string, TypeDefinitionHandle> namesToTypeDefHandles = new Dictionary<string, TypeDefinitionHandle>();
        private Dictionary<string, MethodDefinitionHandle> namesToMethodDefHandles = new Dictionary<string, MethodDefinitionHandle>();
        private HashSet<TypeDeclarationSyntax> visitedPartialDefs = new HashSet<TypeDeclarationSyntax>();
        private HashSet<ISymbol> interfaceSymbols = new HashSet<ISymbol>();
        private Dictionary<string, List<ISymbol>> namesToInterfaceSymbols = new Dictionary<string, List<ISymbol>>();
        private Dictionary<ITypeSymbol, FixedBufferInfo> fixedBufferTypeToInfo = new Dictionary<ITypeSymbol, FixedBufferInfo>();
        private Dictionary<SyntaxTree, SemanticModel> treeToModels = new Dictionary<SyntaxTree, SemanticModel>();
        private HashSet<StructDeclarationSyntax> interfaceStructs = new HashSet<StructDeclarationSyntax>();
        private Dictionary<ISymbol, int> interfaceMethodCount = new Dictionary<ISymbol, int>();
        private Dictionary<string, EntityHandle> ctorNamesToRefs = new Dictionary<string, EntityHandle>();
        private Dictionary<string, ModuleReferenceHandle> moduleRefHandles = new Dictionary<string, ModuleReferenceHandle>();
        private List<GeneratorDiagnostic> diagnostics = new List<GeneratorDiagnostic>();
        private HashSet<string> typeImportInterfaces = new HashSet<string>();
        private Dictionary<string, string> typeImports = new Dictionary<string, string>();
        private HashSet<string> reducePointerLevels;
        private Dictionary<string, AssemblyReferenceHandle> assemblyNamesToRefHandles = new Dictionary<string, AssemblyReferenceHandle>();
        private Dictionary<string, ITypeSymbol> nameToSymbols = new Dictionary<string, ITypeSymbol>();
        private Dictionary<StructDeclarationSyntax, ISymbol> structNodesToInheritedSymbols = new Dictionary<StructDeclarationSyntax, ISymbol>();
        private Dictionary<string, FieldDeclarationSyntax> nameToGuidConstFields = new Dictionary<string, FieldDeclarationSyntax>();
        private HashSet<string> structNameWithGuids = new HashSet<string>();
        private Dictionary<string, AssemblyReferenceHandle> assemblyNamesToRefs = new Dictionary<string, AssemblyReferenceHandle>();

        private ClangSharpSourceWinmdGenerator(
            CSharpCompilation compilation, 
            Dictionary<string, string> typeImports,
            HashSet<string> reducePointerLevels, 
            Version assemblyVersion, 
            string assemblyName)
        {
            this.compilation = compilation;
            this.reducePointerLevels = reducePointerLevels;

            foreach (var pair in typeImports)
            {
                string name = pair.Key;
                if (name.EndsWith("(interface)"))
                {
                    name = pair.Key.Substring(0, pair.Key.Length - "(interface)".Length);
                    this.typeImportInterfaces.Add(name);
                }

                this.typeImports[name] = pair.Value;
            }

            VerifySymbolsLoadedByCompiler();
            InitReferences();
            InitAssembly(assemblyVersion, assemblyName);
            InitModule(assemblyName);

            void VerifySymbolsLoadedByCompiler()
            {
                string[] standardSymbolNames = new string[] { "System.Object", "System.Attribute", $"{InteropNamespace}.ConstAttribute" };

                foreach (var name in standardSymbolNames)
                {
                    var type = this.compilation.GetTypeByMetadataName(name);
                    if (type == null)
                    {
                        throw new InvalidOperationException($"The compiler failed to find the '{name}' type. Make sure the references are correct.");
                    }
                }
            }

            void InitAssembly(Version version, string assemblyName)
            {
                this.metadataBuilder.AddAssembly(
                    this.metadataBuilder.GetOrAddString(assemblyName),
                    version,
                    default,
                    default,
                    default,
                    hashAlgorithm: AssemblyHashAlgorithm.None);
            }

            void InitModule(string assemblyName)
            {
                this.moduleRef =
                    this.metadataBuilder.AddModule(
                        0,
                        this.metadataBuilder.GetOrAddString(assemblyName),
                        this.metadataBuilder.GetOrAddGuid(Guid.NewGuid()),
                        default,
                        default);

                this.metadataBuilder.AddTypeDefinition(
                    default,
                    default,
                    this.metadataBuilder.GetOrAddString("<Module>"),
                    baseType: default(EntityHandle),
                    fieldList: MetadataTokens.FieldDefinitionHandle(1),
                    methodList: MetadataTokens.MethodDefinitionHandle(1));

            }

            void InitReferences()
            {
                Version systemVersion = new Version(2, 1, 0, 0);
                var netstandardAssembly = this.compilation.ReferencedAssemblyNames.ToList().Find(a => a.Name == SystemAssemblyName);
                var systemAssemblyRef =
                    this.metadataBuilder.AddAssemblyReference(
                        this.metadataBuilder.GetOrAddString(netstandardAssembly.Name),
                        netstandardAssembly.Version,
                        default,
                        this.metadataBuilder.GetOrAddBlob(netstandardAssembly.PublicKeyToken),
                        default,
                        default);
                this.assemblyNamesToRefHandles[SystemAssemblyName] = systemAssemblyRef;

                var interopAssembly = this.compilation.ReferencedAssemblyNames.ToList().Find(a => a.Name == Win32InteropAssemblyName);
                var interopAssemblyRef =
                    this.metadataBuilder.AddAssemblyReference(
                        this.metadataBuilder.GetOrAddString(InteropNamespace),
                        interopAssembly.Version,
                        default,
                        this.metadataBuilder.GetOrAddBlob(interopAssembly.PublicKeyToken),
                        default,
                        default);
                this.assemblyNamesToRefHandles[Win32InteropAssemblyName] = interopAssemblyRef;

                var win32Assembly = this.compilation.ReferencedAssemblyNames.ToList().Find(a => a.Name == Win32MetadataAssemblyName);
                if (win32Assembly != null)
                {
                    var win32MetadataAssemblyRef =
                        this.metadataBuilder.AddAssemblyReference(
                            this.metadataBuilder.GetOrAddString(win32Assembly.Name),
                            win32Assembly.Version,
                            default,
                            this.metadataBuilder.GetOrAddBlob(win32Assembly.PublicKeyToken),
                            default,
                            default);

                    this.assemblyNamesToRefHandles[Win32MetadataAssemblyName] = win32MetadataAssemblyRef;
                }
            }
        }

        public bool WroteWinmd { get; private set; }

        public static ClangSharpSourceWinmdGenerator GenerateWindmdForCompilation(
            ClangSharpSourceCompilation compilation, 
            Dictionary<string, string> typeImports,
            HashSet<string> reducePointerLevels,
            Version version, 
            string outputFileName)
        {
            ClangSharpSourceWinmdGenerator generator = 
                new ClangSharpSourceWinmdGenerator(
                    compilation.CSharpCompilation, 
                    typeImports, 
                    reducePointerLevels, 
                    version, 
                    Path.GetFileName(outputFileName));

            generator.PopulateMetadataBuilder();

            if (!generator.diagnostics.Any(d => d.Severity == DiagnosticSeverity.Error))
            {
                generator.WriteWinmd(outputFileName);
            }

            return generator;
        }

        public ReadOnlyCollection<GeneratorDiagnostic> GetDiagnostics()
        {
            return this.diagnostics.AsReadOnly();
        }

        private static string FixFinalName(string name)
        {
            if (name.StartsWith(RemovePrefix))
            {
                name = name.Substring(RemovePrefix.Length);
            }

            if (name.EndsWith(ScannedSuffix))
            {
                name = name.Substring(0, name.Length - ScannedSuffix.Length);
            }

            return name;
        }

        private static byte[] ConvertKeyToByteArray(string key)
        {
            byte[] ret = new byte[key.Length / 2];
            for (int i = 0; i < ret.Length; i++)
            {
                string item = key.Substring(i * 2, 2);
                ret[i] = byte.Parse(item, System.Globalization.NumberStyles.HexNumber);
            }

            return ret;
        }

        private static string GetQualifiedName(string @namespace, string name)
        {
            return $"{@namespace}.{name}";
        }

        private static bool HasGuidAttribute(SyntaxList<AttributeListSyntax> attributeLists)
        {
            bool ret = attributeLists.Any(list => list.Attributes.Any(attr => attr.Name.ToString() == "Windows.Win32.Interop.Guid"));
            return ret;
        }

        private static bool HasPropertyKeyAttribute(SyntaxList<AttributeListSyntax> attributeLists)
        {
            bool ret = attributeLists.Any(list => list.Attributes.Any(attr => attr.Name.ToString() == "PropertyKey"));
            return ret;
        }

        private static string FixArchSpecificName(string name)
        {
            if (name.EndsWith("____1") || name.EndsWith("____2"))
            {
                name = name.Substring(0, name.Length - "____1".Length);
            }

            return name;
        }

        private static void EnsureEnumSizeMatchesOriginalSize(string parent, string name, ITypeSymbol type, string nativeType)
        {
            if (type is INamedTypeSymbol namedType)
            {
                var underlyingType = namedType.EnumUnderlyingType;
                if (underlyingType != null)
                {
                    if (nativeType != null)
                    {
                        int nativeSize = 0;

                        switch (nativeType)
                        {
                            case "SHORT":
                            case "USHORT":
                            case "WORD":
                                nativeSize = 2;
                                break;

                            case "LONG":
                            case "ULONG":
                            case "DWORD":
                            case "UINT":
                            case "UINT32":
                            case "BOOL":
                                nativeSize = 4;
                                break;

                            default:
                                System.Diagnostics.Debug.WriteLine($"{parent}.{name} is using an enum {underlyingType} but its native type {nativeType} not handled.");
                                return;
                        }

                        int enumSize = 0;

                        switch (underlyingType.SpecialType)
                        {
                            case SpecialType.System_UInt32:
                            case SpecialType.System_Int32:
                                enumSize = 4;
                                break;

                            case SpecialType.System_UInt16:
                            case SpecialType.System_Int16:
                                enumSize = 2;
                                break;

                            default:
                                throw new InvalidOperationException($"Enum type {underlyingType} not handled.");
                        }

                        if (enumSize != nativeSize)
                        {
                            throw new InvalidOperationException(
                                $"{parent}.{name} was remapped to enum {namedType} (type {underlyingType}, size {enumSize}) but the original field was of type {nativeType} (size {nativeSize}). Either don't use an enum or make sure the enum is of the same size.");
                        }
                    }
                }
            }
        }
        private void CacheGuidConst(FieldDeclarationSyntax guidFieldNode)
        {
            this.nameToGuidConstFields[guidFieldNode.Declaration.Variables.First().Identifier.ValueText] = guidFieldNode;
        }

        private void CacheInterfaceInfo(InterfaceInfo interfaceInfo)
        {
            string fullName = $"{interfaceInfo.Namespace}.{interfaceInfo.Name}";
            var symbol = this.compilation.GetTypeByMetadataName(fullName);
            if (symbol != null)
            {
                this.interfaceSymbols.Add(symbol);
                this.interfaceMethodCount[symbol] = interfaceInfo.Methods.Count();
                if (!this.namesToInterfaceSymbols.TryGetValue(symbol.Name, out var symbols))
                {
                    symbols = new List<ISymbol>();
                    this.namesToInterfaceSymbols[symbol.Name] = symbols;
                }

                symbols.Add(symbol);
            }
        }

        private void CacheInterfaceType(StructDeclarationSyntax interfaceNode)
        {
            this.interfaceStructs.Add(interfaceNode);

            var model = this.GetModel(interfaceNode);
            var symbol = model.GetDeclaredSymbol(interfaceNode);
            this.interfaceSymbols.Add(symbol);
            this.interfaceMethodCount[symbol] = interfaceNode.Members.Count(m => m is MethodDeclarationSyntax);

            if (!this.namesToInterfaceSymbols.TryGetValue(symbol.Name, out var symbols))
            {
                symbols = new List<ISymbol>();
                this.namesToInterfaceSymbols[symbol.Name] = symbols;
            }

            symbols.Add(symbol);
        }

        private void WriteWinmd(string outputFileName)
        {
            var peBuilder = new ManagedPEBuilder(
                PEHeaderBuilder.CreateLibraryHeader(),
                new MetadataRootBuilder(this.metadataBuilder),
                ilStream: new BlobBuilder());

            var peBlob = new BlobBuilder();
            peBuilder.Serialize(peBlob);

            string dir = Path.GetDirectoryName(outputFileName);
            if (!Directory.Exists(dir))
            {
                Directory.CreateDirectory(dir);
            }

            using (FileStream fileStream = new FileStream(outputFileName, FileMode.Create, FileAccess.ReadWrite))
            {
                peBlob.WriteContentTo(fileStream);
            }

            this.WroteWinmd = true;
        }

        private void PopulateMetadataBuilder()
        {
            GatherInterfaceTypes();

            VisitAllTypes();

            void VisitAllTypes()
            {
                SyntaxWalker walker = new SyntaxWalker(this);
                foreach (var tree in this.compilation.SyntaxTrees)
                {
                    walker.Visit(tree.GetRoot());
                }
            }

            void GatherInterfaceTypes()
            {
                InterfaceWalker interfaceWalker = new InterfaceWalker(this);
                foreach (var tree in this.compilation.SyntaxTrees)
                {
                    interfaceWalker.Visit(tree.GetRoot());
                }

                foreach (var r in this.compilation.References)
                {
                    if (r.Display.EndsWith("netstandard.dll"))
                    {
                        continue;
                    }

                    using (var winmd = MetadataUtils.WinmdUtils.LoadFromFile(r.Display))
                    {
                        foreach (var typeInfo in winmd.GetTypes())
                        {
                            if (typeInfo is MetadataUtils.InterfaceInfo interfaceInfo)
                            {
                                this.CacheInterfaceInfo(interfaceInfo);
                            }
                            else if (typeInfo is MetadataUtils.StructInfo)
                            {
                                var fullName = $"{typeInfo.Namespace}.{typeInfo.Name}";
                                var typeSymbol = this.compilation.GetTypeByMetadataName(fullName);

                                if (typeSymbol != null)
                                {
                                    this.nameToSymbols[typeInfo.Name] = typeSymbol;
                                }
                            }
                        }
                    }
                }
            }
        }

        private EntityHandle GetTypeReference(ISymbol symbol)
        {
            EntityHandle scopeRef;

            if (symbol.ContainingAssembly.Name == "?")
            {
                scopeRef = this.moduleRef;
            }
            else
            {
                this.assemblyNamesToRefHandles.TryGetValue(symbol.ContainingAssembly.Name, out var assemblyRef);

                scopeRef = assemblyRef;
            }

            // Change from namepace.parent.self => parent/self
            string name = symbol.ToString().Substring(symbol.ContainingNamespace.ToString().Length + 1).Replace('.', '/');

            return this.GetTypeReference(symbol.ContainingNamespace.ToString(), name, scopeRef);
        }

        private EntityHandle GetTypeReference(string @namespace, string name)
        {
            return this.GetTypeReference(@namespace, name, default);
        }

        private EntityHandle GetTypeReference(string @namespace, string name, EntityHandle scopeRef)
        {
            name = FixArchSpecificName(name);

            string fullname = GetQualifiedName(@namespace, name);
            if (!this.namesToTypeRefHandles.TryGetValue(fullname, out var typeRef))
            {
                if (scopeRef == default)
                {
                    if (@namespace.StartsWith("System"))
                    {
                        scopeRef = this.assemblyNamesToRefHandles[SystemAssemblyName];
                    }
                    else if (@namespace.StartsWith(InteropNamespace))
                    {
                        scopeRef = this.assemblyNamesToRefHandles[Win32InteropAssemblyName];
                    }
                    else
                    {
                        scopeRef = this.moduleRef;
                    }
                }

                int lastPlus = name.LastIndexOf('/');
                if (lastPlus != -1)
                {
                    string parent = name.Substring(0, lastPlus);
                    name = name.Substring(lastPlus + 1);
                    scopeRef = this.GetTypeReference(@namespace, parent);

                    // No longer using the namespace name when a dervied ref
                    @namespace = null;
                }

                var nsHandle = @namespace != null ? this.metadataBuilder.GetOrAddString(@namespace) : default;
                typeRef = this.metadataBuilder.AddTypeReference(
                    scopeRef,
                    nsHandle,
                    this.metadataBuilder.GetOrAddString(name));
                this.namesToTypeRefHandles[fullname] = typeRef;
            }

            return typeRef;
        }

        private SemanticModel GetModel(SyntaxNode node)
        {
            if (!this.treeToModels.TryGetValue(node.SyntaxTree, out SemanticModel model))
            {
                model = this.compilation.GetSemanticModel(node.SyntaxTree, true);
                this.treeToModels[node.SyntaxTree] = model;
            }

            return model;
        }

        private void WriteEnumDef(EnumDeclarationSyntax node)
        {
            this.WriteEnumDef(node, default);
        }

        private void WriteEnumDef(EnumDeclarationSyntax node, TypeDefinitionHandle enclosingType)
        {
            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);
            string fullName = this.GetFullNameForSymbol(symbol);

            if (this.namesToTypeDefHandles.ContainsKey(fullName))
            {
                return;
            }

            // Add special value__ field for enums
            FieldAttributes valueFieldAttrs = FieldAttributes.Public | FieldAttributes.SpecialName | FieldAttributes.RTSpecialName;
            var fieldSignature = new BlobBuilder();
            var encoder = new BlobEncoder(fieldSignature);
            encoder.FieldSignature().EncodeSpecialType(symbol.EnumUnderlyingType.SpecialType);

            var valueFieldDef =
                this.metadataBuilder.AddFieldDefinition(
                    valueFieldAttrs,
                    this.metadataBuilder.GetOrAddString("value__"),
                    this.metadataBuilder.GetOrAddBlob(fieldSignature));

            this.WriteEnumMembers(node);

            // Write type def
            TypeAttributes typeAttributes = TypeAttributes.Public | TypeAttributes.AnsiClass | TypeAttributes.Sealed | TypeAttributes.AutoLayout;
            var destTypeDefHandle =
                this.metadataBuilder.AddTypeDefinition(
                    typeAttributes,
                    this.metadataBuilder.GetOrAddString(symbol.ContainingNamespace.ToString()),
                    this.metadataBuilder.GetOrAddString(node.Identifier.ValueText),
                    this.GetTypeReference("System", "Enum"),
                    fieldList: valueFieldDef,
                    methodList: MetadataTokens.MethodDefinitionHandle(this.metadataBuilder.GetRowCount(TableIndex.MethodDef) + 1));

            this.AddCustomAttributes(node, destTypeDefHandle);

            if (enclosingType != default)
            {
                this.metadataBuilder.AddNestedType(destTypeDefHandle, enclosingType);
            }

            this.namesToTypeDefHandles[fullName] = destTypeDefHandle;
        }

        private bool IsInterfaceDef(StructDeclarationSyntax node)
        {
            if (this.interfaceStructs.Contains(node))
            {
                return true;
            }
            
            bool hasVtbl = node.Members.Any(m => m.Kind() == SyntaxKind.FieldDeclaration && ((FieldDeclarationSyntax)m).Declaration.Variables.First().Identifier.Text == "lpVtbl");
            bool hasDelegate = node.Members.Any(m => m.Kind() == SyntaxKind.DelegateDeclaration);
            return hasVtbl && hasDelegate;
        }

        private void WriteInterfaceDef(StructDeclarationSyntax node)
        {
            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);
            var nsHandle = this.metadataBuilder.GetOrAddString(symbol.ContainingNamespace.ToString());
            var name = node.Identifier.ValueText;
            string fullName = symbol.ConstructedFrom.ToString();

            MethodDefinitionHandle firstMethod = this.WriteInterfaceMethods(node);
            if (firstMethod.IsNil)
            {
                firstMethod = MetadataTokens.MethodDefinitionHandle(this.metadataBuilder.GetRowCount(TableIndex.MethodDef) + 1);
            }

            TypeAttributes typeAttributes = TypeAttributes.Interface | TypeAttributes.Public | TypeAttributes.AnsiClass | TypeAttributes.Abstract;
            var destTypeDefHandle =
                this.metadataBuilder.AddTypeDefinition(
                    typeAttributes,
                    nsHandle,
                    this.metadataBuilder.GetOrAddString(name),
                    default,
                    fieldList: MetadataTokens.FieldDefinitionHandle(this.metadataBuilder.GetRowCount(TableIndex.Field) + 1),
                    methodList: firstMethod);

            this.namesToTypeDefHandles[fullName] = destTypeDefHandle;

            var inheritsFromSymbol = this.GetInheritedInterfaceSymbol(node);

            // Can be null if it's a non-IUnknown interface
            if (inheritsFromSymbol != null)
            {
                var inheritsFromTypeDef = this.GetTypeReference(inheritsFromSymbol);
                this.metadataBuilder.AddInterfaceImplementation(destTypeDefHandle, inheritsFromTypeDef);
            }

            // If this interface node doesn't have a Guid attribute, see if we can 
            // match it to a Guid constant
            if (!HasGuidAttribute(node.AttributeLists))
            {
                string iidGuidConstName = $"IID_{name}";
                if (!this.nameToGuidConstFields.TryGetValue(iidGuidConstName, out var fieldDeclNode))
                {
                    iidGuidConstName += ScannedSuffix;
                    this.nameToGuidConstFields.TryGetValue(iidGuidConstName, out fieldDeclNode);
                }

                if (fieldDeclNode != null)
                {
                    ISymbol fieldSymbol = this.compilation.GetSymbolsWithName(iidGuidConstName).FirstOrDefault();

                    if (fieldSymbol != null)
                    {
                        this.AddCustomAttributes(fieldSymbol, destTypeDefHandle);
                    }
                }
            }

            this.AddCustomAttributes(node, destTypeDefHandle);
        }

        private void WriteStructDef(StructDeclarationSyntax node)
        {
            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);
            string fullName = this.GetFullNameForSymbol(symbol);

            if (this.namesToTypeDefHandles.ContainsKey(fullName))
            {
                return;
            }

            if (this.IsInterfaceDef(node))
            {
                this.WriteInterfaceDef(node);
                return;
            }

            this.WriteStructDef(node, default);
        }

        private void AddFixedBufferTypeInfoForStructNode(StructDeclarationSyntax node)
        {
            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);
            var fields = node.Members.Where(m => m is FieldDeclarationSyntax);
            var firstFieldNode = (FieldDeclarationSyntax)fields.First();
            var variable = firstFieldNode.Declaration.Variables.First();
            var type = model.GetTypeInfo(firstFieldNode.Declaration.Type).Type;
            this.fixedBufferTypeToInfo[symbol] = new FixedBufferInfo(type, fields.Count());
        }

        private void WriteStructDef(StructDeclarationSyntax node, TypeDefinitionHandle enclosingType)
        {
            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);
            string fullName = this.GetFullNameForSymbol(symbol);

            // Don't emit structs that end in _e__FixedBuffer. These are emitted by ClangSharp instead of arrays of structs
            // because C# can't do fixed length arrays of structs. Cache the type so when we emit the field it has the
            // type handy
            if (fullName.EndsWith("_e__FixedBuffer"))
            {
                this.AddFixedBufferTypeInfoForStructNode(node);
                return;
            }

            TypeAttributes typeAttributes = TypeAttributes.AnsiClass | TypeAttributes.Sealed | TypeAttributes.BeforeFieldInit;
            if (!enclosingType.IsNil)
            {
                typeAttributes |= TypeAttributes.NestedPublic;
            }
            else
            {
                typeAttributes |= TypeAttributes.Public;
            }

            int? packSize = null;
            var structLayoutAttr = symbol.GetAttributes().FirstOrDefault(a => a.AttributeClass.Name == "StructLayoutAttribute");
            if (structLayoutAttr != null)
            {
                var arg = (System.Runtime.InteropServices.LayoutKind)structLayoutAttr.ConstructorArguments[0].Value;
                typeAttributes |= arg == System.Runtime.InteropServices.LayoutKind.Explicit ? TypeAttributes.ExplicitLayout : TypeAttributes.SequentialLayout;

                foreach (var nameVal in structLayoutAttr.NamedArguments.Where(n => n.Key == "Pack"))
                {
                    packSize = (int)nameVal.Value.Value;
                    break;
                }
            }
            else
            {
                typeAttributes |= TypeAttributes.SequentialLayout;
            }

            var firstField = this.WriteStructFields(node);
            if (firstField.IsNil)
            {
                firstField = MetadataTokens.FieldDefinitionHandle(this.metadataBuilder.GetRowCount(TableIndex.Field) + 1);
            }

            var nsHandle = enclosingType == default ? this.metadataBuilder.GetOrAddString(symbol.ContainingNamespace.ToString()) : default;
            var name = this.GetShortNameForSymbol(symbol);

            name = FixArchSpecificName(name);

            var destTypeDefHandle =
                this.metadataBuilder.AddTypeDefinition(
                    typeAttributes,
                    nsHandle,
                    this.metadataBuilder.GetOrAddString(name),
                    this.GetTypeReference("System", "ValueType"),
                    fieldList: firstField,
                    methodList: MetadataTokens.MethodDefinitionHandle(this.metadataBuilder.GetRowCount(TableIndex.MethodDef) + 1));

            this.namesToTypeDefHandles[fullName] = destTypeDefHandle;

            this.WriteStructEnums(node, destTypeDefHandle);

            if (packSize.HasValue)
            {
                this.metadataBuilder.AddTypeLayout(destTypeDefHandle, (ushort)packSize.Value, 0);
            }

            this.AddCustomAttributes(node, destTypeDefHandle);

            if (enclosingType != default)
            {
                this.metadataBuilder.AddNestedType(destTypeDefHandle, enclosingType);
            }

            foreach (StructDeclarationSyntax nested in node.Members.Where(m => m is StructDeclarationSyntax))
            {
                this.WriteStructDef(nested, destTypeDefHandle);
            }
        }

        private void EncodeReturnType(ITypeSymbol returnType, ReturnTypeEncoder returnTypeEncoder)
        {
            if (returnType == null || returnType.SpecialType == SpecialType.System_Void)
            {
                returnTypeEncoder.Void();
                return;
            }

            this.EncodeTypeSymbol(returnType, returnTypeEncoder.Type());
        }

        private void EncodeParameters(IEnumerable<Parameter> parameters, ParametersEncoder parametersEncoder)
        {
            foreach (var parameter in parameters)
            {
                var parameterTypeEncoder = parametersEncoder.AddParameter();
                this.EncodeTypeSymbol(parameter.Type, parameterTypeEncoder.Type());
            }
        }

        private ITypeSymbol GetTypeFromShortName(string name)
        {
            var origName = name;

            // If it's an array, treat it like a pointer
            var arrayMatch = ArrayMatcher.Match(name);
            if (arrayMatch.Success)
            {
                name = name.Substring(0, arrayMatch.Captures[0].Index) + "*";
            }

            if (!this.nameToSymbols.TryGetValue(name, out var ret))
            {
                string fixedName = origName;

                switch (name)
                {
                    case "PCHAR":
                    case "LPCH":
                    case "PCH":
                    case "LPCCH":
                    case "PCCH":
                    case "NPSTR":
                    case "LPSTR":
                    case "PSTR":
                    case "LPCSTR":
                    case "PCSTR":
                    case "PZZSTR":
                    case "CPZZSTR":
                    case "CHAR *":
                    case "char *":
                    case "const CHAR *":
                    case "const char *":
                        fixedName = Win32StringType;
                        break;

                    case "PWCHAR":
                    case "LPWCH":
                    case "PWCH":
                    case "NWPSTR":
                    case "LPWSTR":
                    case "PWSTR":
                    case "LPOLESTR":
                    case "WCHAR *":
                    case "wchar_t *":
                    case "LPCWSTR":
                    case "PCWSTR":
                    case "LPCWCH":
                    case "LPCOLESTR":
                    case "OLECHAR *":
                    case "const WCHAR *":
                    case "const wchar_t *":
                    case "PZZWSTR":
                    case "PCZZWSTR":
                    case "PNZWCH":
                    case "PCNZWCH":
                        fixedName = Win32WideStringType;
                        break;

                    default:
                        break;
                }

                if (!fixedName.Contains("."))
                {
                    foreach (string @namespace in new string[] { InteropNamespace, "System" })
                    {
                        var fullNameToCheck = GetQualifiedName(@namespace, fixedName);
                        ret = this.compilation.GetTypeByMetadataName(fullNameToCheck);
                        if (ret != null)
                        {
                            break;
                        }
                    }

                    if (ret == null)
                    {
                        ret = this.compilation.GetSymbolsWithName(fixedName, SymbolFilter.Type).FirstOrDefault() as ITypeSymbol;
                    }
                }
                else
                {
                    ret = this.compilation.GetTypeByMetadataName(fixedName);
                }

                // Use the original name and not the fixed name to cache it
                this.nameToSymbols[name] = ret;
            }

            return ret;
        }

        private void RemapToMoreSpecificTypeIfPossible(
            string owner,
            string name,
            ImmutableArray<AttributeData> ownerAttributes,
            ref ITypeSymbol typeSymbol)
        {
            // Can't do anything without a NativeTypeNameAttribute 
            var nativeTypeNameAttr = ownerAttributes.FirstOrDefault(a => a.AttributeClass.Name == "NativeTypeNameAttribute");
            if (nativeTypeNameAttr == null)
            {
                return;
            }

            var nativeType = nativeTypeNameAttr.ConstructorArguments[0].Value.ToString();
            EnsureEnumSizeMatchesOriginalSize(owner, name, typeSymbol, nativeType);

            if (typeSymbol.SpecialType == SpecialType.System_SByte && IsCharRegex.IsMatch(nativeType))
            {
                typeSymbol = this.GetTypeFromShortName("CHAR");
                return;
            }

            if (typeSymbol.SpecialType == SpecialType.System_UInt16 && IsWcharRegex.IsMatch(nativeType))
            {
                typeSymbol = this.GetTypeFromShortName("System.Char");
                return;
            }

            if (typeSymbol.SpecialType == SpecialType.System_IntPtr && nativeType.Contains("(*)"))
            {
                string fullName = $"{owner}.{name}";
                this.diagnostics.Add(new GeneratorDiagnostic($"{fullName} is a pointer to a function: {nativeType}. To express this properly in metadata, define a delegate and map {fullName} to use it.", DiagnosticSeverity.Warning));
                return;
            }

            var typeName = typeSymbol.ToString();

            // See if we can map from some generic types to a more specific type
            if (typeSymbol.SpecialType == SpecialType.System_IntPtr ||
                typeSymbol.SpecialType == SpecialType.System_UIntPtr ||
                typeSymbol.SpecialType == SpecialType.System_Int32 ||
                typeSymbol.SpecialType == SpecialType.System_UInt32 ||
                typeSymbol.SpecialType == SpecialType.System_Int64 ||
                typeSymbol.SpecialType == SpecialType.System_UInt64 ||
                typeSymbol.SpecialType == SpecialType.System_Byte ||
                typeName.StartsWith("System.IntPtr*") ||
                typeName.StartsWith("System.UIntPtr*") ||
                typeName.StartsWith("ushort*") ||
                typeName.StartsWith("sbyte*") ||
                typeName.StartsWith("int*") ||
                typeName.StartsWith("uint*") ||
                typeName.StartsWith("long*") ||
                typeName.StartsWith("ulong*") ||
                typeName.StartsWith("void*"))
            {
                if (nativeType.StartsWith("const "))
                {
                    nativeType = nativeType.Substring("const ".Length);
                }

                var newTypeSymbol = this.GetTypeFromShortName(nativeType);
                if (newTypeSymbol != null)
                {
                    typeSymbol = newTypeSymbol;
                    return;
                }

                var parts = nativeType.Split(' ');
                var nameOnly = parts[0];
                var star = parts.Length > 1 ? parts[1] : null;

                if (star != null)
                {
                    // If this is an array...
                    if (star[0] == '[')
                    {
                        // Treat it like a pointer if the array doesn't have a size
                        if (star == "[]")
                        {
                            star = "*";
                        }
                        // Otherwise don't treat it like an array. The encoder will encode
                        // the array size
                        else
                        {
                            star = null;
                        }
                    }
                    // Make sure it's actually a pointer. If it's not, we can't do anything more
                    else if (star[0] != '*')
                    {
                        return;
                    }
                }

                newTypeSymbol = this.GetTypeFromShortName(nameOnly);

                if (newTypeSymbol != null)
                {
                    if (!string.IsNullOrEmpty(star))
                    {
                        var currentName = nameOnly;
                        for (int i = 0; i < star.Length; i++)
                        {
                            currentName += "*";
                            var pointerSymbol = this.GetTypeFromShortName(currentName);
                            if (pointerSymbol == null)
                            {
                                pointerSymbol = this.compilation.CreatePointerTypeSymbol(newTypeSymbol);
                                this.nameToSymbols[currentName] = pointerSymbol;
                            }

                            newTypeSymbol = pointerSymbol;
                        }
                    }

                    typeSymbol = newTypeSymbol;
                }
            }
        }

        private MethodDefinitionHandle AddMethodViaParams(
            IMethodSymbol methodSymbol,
            string methodName,
            ITypeSymbol returnType,
            IEnumerable<Parameter> parameters,
            MethodAttributes methodAttrs,
            MethodImplAttributes methodImplAttributes,
            bool instanceMethod)
        {
            methodName = FixArchSpecificName(methodName);

            var methodSignature = new BlobBuilder();
            new BlobEncoder(methodSignature)
                .MethodSignature(
                    SignatureCallingConvention.Default,
                    0,
                    instanceMethod)
                .Parameters(
                    parameters.Count(),
                    returnTypeEncoder => this.EncodeReturnType(returnType, returnTypeEncoder),
                    parametersEncoder => this.EncodeParameters(parameters, parametersEncoder)
                );
            var newMethod =
                this.metadataBuilder.AddMethodDefinition(
                    methodAttrs,
                    methodImplAttributes,
                    this.metadataBuilder.GetOrAddString(methodName),
                    this.metadataBuilder.GetOrAddBlob(methodSignature),
                    -1,
                    MetadataTokens.ParameterHandle(this.metadataBuilder.GetRowCount(TableIndex.Param) + 1));

            if (methodSymbol != null)
            {
                var returnAttrs = methodSymbol.GetReturnTypeAttributes();
                if (returnAttrs.Length != 0)
                {
                    var returnParamHandle = this.metadataBuilder.AddParameter(ParameterAttributes.None, default, 0);
                    this.AddCustomAttributes(returnAttrs, returnParamHandle);
                }
            }

            int index = 1;
            foreach (var p in parameters)
            {
                var paramHandle = this.metadataBuilder.AddParameter(p.Attrs, this.metadataBuilder.GetOrAddString(p.Name), index++);
                if (p.Symbol != null)
                {
                    this.AddCustomAttributes(p.Symbol.GetAttributes(), paramHandle);
                }
            }

            return newMethod;
        }

        private MethodDefinitionHandle AddMethodViaSymbol(
            IMethodSymbol methodSymbol,
            MethodAttributes methodAttrs,
            MethodImplAttributes methodImplAttrs,
            bool instanceMethod)
        {
            var returnType = methodSymbol.ReturnType;
            this.RemapToMoreSpecificTypeIfPossible(methodSymbol.Name, "return", methodSymbol.GetReturnTypeAttributes(), ref returnType);

            List<Parameter> parameters = new List<Parameter>();
            foreach (var p in methodSymbol.Parameters)
            {
                parameters.Add(new Parameter(this, methodSymbol, p));
            }

            return this.AddMethodViaParams(methodSymbol, methodSymbol.Name, returnType, parameters, methodAttrs, methodImplAttrs, instanceMethod);
        }

        private INamedTypeSymbol GetTypeByMetadataName(string typeName)
        {
            return this.compilation.GetTypeByMetadataName(typeName);
        }

        private ModuleReferenceHandle GetModuleRef(string name)
        {
            if (!this.moduleRefHandles.TryGetValue(name, out ModuleReferenceHandle handle))
            {
                handle = this.metadataBuilder.AddModuleReference(this.metadataBuilder.GetOrAddString(name));
                this.moduleRefHandles[name] = handle;
            }

            return handle;
        }

        private FieldDefinitionHandle WriteClassFields(ClassDeclarationSyntax node)
        {
            var className = node.Identifier.ValueText;
            var model = this.GetModel(node);
            var classSymbol = model.GetDeclaredSymbol(node);
            FieldDefinitionHandle firstField = default;
            foreach (FieldDeclarationSyntax field in node.Members.Where(m => m is FieldDeclarationSyntax))
            {
                var fieldVariable = field.Declaration.Variables.First();
                IFieldSymbol fieldSymbol = (IFieldSymbol)model.GetDeclaredSymbol(fieldVariable);
                string name = fieldSymbol.Name;

                FieldAttributes fieldAttributes;

                if (!fieldSymbol.IsConst)
                {
                    fieldAttributes = FieldAttributes.Public | FieldAttributes.Static;

                    if (!HasGuidAttribute(field.AttributeLists) && !HasPropertyKeyAttribute(field.AttributeLists))
                    {
                        continue;
                    }

                    if (fieldSymbol.Name.StartsWith("IID_"))
                    {
                        continue;
                    }

                    name = FixFinalName(name);

                    if (name.StartsWith("CLSID_"))
                    {
                        string testClassName = name.Substring("CLSID_".Length);
                        if (this.structNameWithGuids.Contains(testClassName))
                        {
                            continue;
                        }
                    }
                }
                else
                {
                    fieldAttributes = FieldAttributes.Public | FieldAttributes.Static | FieldAttributes.Literal | FieldAttributes.HasDefault;
                }

                var fieldSignature = this.EncodeFieldSignature(className, model, field, out _);

                var fieldDefinitionHandle =
                    this.metadataBuilder.AddFieldDefinition(
                        fieldAttributes,
                        this.metadataBuilder.GetOrAddString(name),
                        this.metadataBuilder.GetOrAddBlob(fieldSignature));
                if (fieldSymbol.HasConstantValue)
                {
                    this.metadataBuilder.AddConstant(fieldDefinitionHandle, fieldSymbol.ConstantValue);
                }

                if (firstField.IsNil)
                {
                    firstField = fieldDefinitionHandle;
                }

                this.AddCustomAttributes(fieldVariable, fieldDefinitionHandle);
            }

            return firstField;
        }

        private MethodDefinitionHandle WriteClassMethods(ClassDeclarationSyntax node)
        {
            var className = node.Identifier.ValueText;
            var model = this.GetModel(node);
            var classSymbol = model.GetDeclaredSymbol(node);
            MethodDefinitionHandle firstMethod = default;
            string classFullName = this.GetFullNameForSymbol(classSymbol);

            foreach (MethodDeclarationSyntax method in node.Members.Where(m => m is MethodDeclarationSyntax))
            {
                var symbol = model.GetDeclaredSymbol(method);
                var methodName = method.Identifier.ValueText;
                string fullName = $"{classFullName}+{methodName}";

                if (this.namesToMethodDefHandles.ContainsKey(fullName))
                {
                    continue;
                }

                if (!symbol.IsExtern)
                {
                    continue;
                }

                methodName = FixArchSpecificName(methodName);

                MethodImplAttributes methodImplAttributes = MethodImplAttributes.Managed;
                if (symbol.GetAttributes().Any(a => a.AttributeClass.Name == "PreserveSigAttribute"))
                {
                    methodImplAttributes |= MethodImplAttributes.PreserveSig;
                }

                var methodDef =
                    this.AddMethodViaSymbol(
                        symbol,
                        MethodAttributes.Public | MethodAttributes.Static | MethodAttributes.HideBySig | MethodAttributes.PinvokeImpl,
                        methodImplAttributes,
                        false);
                if (firstMethod.IsNil)
                {
                    firstMethod = methodDef;
                }

                this.namesToMethodDefHandles[fullName] = methodDef;

                MethodImportAttributes methodImportAttributes = MethodImportAttributes.CallingConventionWinApi;
                var dllImportAttr = symbol.GetAttributes().First(a => a.AttributeClass.Name == "DllImportAttribute");
                string moduleName = (string)dllImportAttr.ConstructorArguments[0].Value;
                StringHandle importedMethodName = this.metadataBuilder.GetOrAddString(methodName);
                foreach (var arg in dllImportAttr.NamedArguments)
                {
                    if (arg.Key == "ExactSpelling" && (bool)arg.Value.Value)
                    {
                        methodImportAttributes |= MethodImportAttributes.ExactSpelling;
                    }
                    else if (arg.Key == "SetLastError" && (bool)arg.Value.Value)
                    {
                        methodImportAttributes |= MethodImportAttributes.SetLastError;
                    }
                    else if (arg.Key == "EntryPoint")
                    {
                        importedMethodName = this.metadataBuilder.GetOrAddString((string)arg.Value.Value);
                    }
                }

                this.AddCustomAttributes(method, methodDef);

                this.metadataBuilder.AddMethodImport(
                    methodDef,
                    methodImportAttributes,
                    importedMethodName,
                    this.GetModuleRef(moduleName));
            }

            return firstMethod;
        }

        private void WriteClassDef(ClassDeclarationSyntax node)
        {
            var partialDefs = this.GetUnvistedPartialDefs(node);
            if (partialDefs.Count == 0)
            {
                return;
            }

            MethodDefinitionHandle methodDefinition = default;
            FieldDefinitionHandle fieldDefinition = default;
            foreach (var partialDef in partialDefs)
            {
                var firstMethod =
                    this.WriteClassMethods(partialDef);

                if (methodDefinition.IsNil)
                {
                    methodDefinition = firstMethod;
                }

                var firstField = this.WriteClassFields(partialDef);
                if (fieldDefinition.IsNil)
                {
                    fieldDefinition = firstField;
                }
            }

            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);
            var nsHandle = this.metadataBuilder.GetOrAddString(symbol.ContainingNamespace.ToString());
            var name = node.Identifier.ValueText;
            string fullName = symbol.ConstructedFrom.ToString();

            TypeAttributes typeAttributes = TypeAttributes.Public | TypeAttributes.AutoClass | TypeAttributes.Abstract | TypeAttributes.Sealed | TypeAttributes.BeforeFieldInit;

            if (methodDefinition.IsNil)
            {
                methodDefinition = MetadataTokens.MethodDefinitionHandle(this.metadataBuilder.GetRowCount(TableIndex.MethodDef) + 1);
            }

            if (fieldDefinition.IsNil)
            {
                fieldDefinition = MetadataTokens.FieldDefinitionHandle(this.metadataBuilder.GetRowCount(TableIndex.Field) + 1);
            }

            var destTypeDefHandle =
                this.metadataBuilder.AddTypeDefinition(
                    typeAttributes,
                    nsHandle,
                    this.metadataBuilder.GetOrAddString(name),
                    this.GetTypeReference("System", "Object"),
                    fieldList: fieldDefinition,
                    methodList: methodDefinition);

            this.namesToTypeDefHandles[fullName] = destTypeDefHandle;
            System.Diagnostics.Debug.WriteLine($"Class: {symbol}");
        }

        private MethodDefinitionHandle WriteDelegateMethods(DelegateDeclarationSyntax node)
        {
            MethodDefinitionHandle firstMethod = default;

            if (node.Parent is StructDeclarationSyntax)
            {
                return firstMethod;
            }

            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);

            var ctorMethodDef =
                this.AddMethodViaParams(
                    null,
                    ".ctor",
                    returnType: null,
                    new Parameter[]
                    {
                        new Parameter("object", this.GetTypeByMetadataName("System.Object"), ParameterAttributes.None),
                        new Parameter("method", this.GetTypeByMetadataName("System.IntPtr"), ParameterAttributes.None)
                    },
                    MethodAttributes.Public | MethodAttributes.HideBySig | MethodAttributes.SpecialName | MethodAttributes.RTSpecialName,
                    MethodImplAttributes.Managed | MethodImplAttributes.Runtime,
                    true);
            firstMethod = ctorMethodDef;

            var invokeMethodSymbol = symbol.GetMembers().First(m => m.Name == "Invoke");

            this.AddMethodViaSymbol(
                (IMethodSymbol)invokeMethodSymbol,
                MethodAttributes.Public | MethodAttributes.NewSlot | MethodAttributes.HideBySig | MethodAttributes.Virtual,
                MethodImplAttributes.Managed | MethodImplAttributes.Runtime,
                true);

            return firstMethod;
        }

        private void WriteDelegateDef(DelegateDeclarationSyntax node)
        {
            // We only want top-level delegates
            if (node.Parent is StructDeclarationSyntax)
            {
                return;
            }

            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);
            string fullName = symbol.ConstructedFrom.ToString();
            if (this.namesToTypeDefHandles.ContainsKey(fullName))
            {
                return;
            }

            var nsHandle = this.metadataBuilder.GetOrAddString(symbol.ContainingNamespace.ToString());
            var name = node.Identifier.ValueText;

            name = FixArchSpecificName(name);

            TypeAttributes delegateTypeAttributes = TypeAttributes.Public | TypeAttributes.AutoClass | TypeAttributes.Sealed | TypeAttributes.BeforeFieldInit;

            MethodDefinitionHandle firstMethod = this.WriteDelegateMethods(node);
            if (firstMethod.IsNil)
            {
                firstMethod = MetadataTokens.MethodDefinitionHandle(this.metadataBuilder.GetRowCount(TableIndex.MethodDef) + 1);
            }

            var delegateDefHandle =
                this.metadataBuilder.AddTypeDefinition(
                    delegateTypeAttributes,
                    nsHandle,
                    this.metadataBuilder.GetOrAddString(name),
                    this.GetTypeReference("System", "MulticastDelegate"),
                    fieldList: MetadataTokens.FieldDefinitionHandle(this.metadataBuilder.GetRowCount(TableIndex.Field) + 1),
                    methodList: firstMethod);
            this.AddCustomAttributes(node, delegateDefHandle);

            this.namesToTypeDefHandles[fullName] = delegateDefHandle;
        }

        private string GetShortNameForSymbol(ITypeSymbol typeSymbol)
        {
#if MakeShortNameIncludeEnclosingName
            if (typeSymbol.ContainingType == null)
            {
                return typeSymbol.Name;
            }

            return $"{this.GetShortNameForSymbol(typeSymbol.ContainingType)}_{typeSymbol.Name}";
#else
            string ret = typeSymbol.Name;
            if (typeSymbol.ContainingSymbol is ITypeSymbol containingType && this.GetShortNameForSymbol(containingType) == ret)
            {
                ret += "_1";
            }

            return ret;
#endif
        }

        private string GetFullNameForSymbol(ITypeSymbol typeSymbol)
        {
            if (typeSymbol.ContainingType == null)
            {
                return typeSymbol.ToString();
            }

            return this.GetFullNameForSymbol(typeSymbol.ContainingType) + "/" + this.GetShortNameForSymbol(typeSymbol);
        }

        private EntityHandle GetTypeRefOrDef(ITypeSymbol typeSymbol)
        {
            string fullName = this.GetFullNameForSymbol(typeSymbol);
            if (this.namesToTypeRefHandles.TryGetValue(fullName, out TypeReferenceHandle typeRef))
            {
                return typeRef;
            }

            if (this.namesToTypeDefHandles.TryGetValue(fullName, out TypeDefinitionHandle typeDef))
            {
                return typeDef;
            }

            string @namespace = typeSymbol.ContainingNamespace.ToString();
            if (@namespace == "<global namespace>")
            {
                if (this.ConvertTypeToImportedType(fullName, out typeRef))
                {
                    return typeRef;
                }
                
                throw new InvalidOperationException(
                    $"\"{fullName}\" could not be resolved. Make sure this symbol is defined in the metadata source files or in a referenced assembly.");
            }

            return this.GetTypeReference(typeSymbol);
        }

        /// <summary>
        /// Tries to map a type name to an imported type. The format comes from remap entries:
        /// IPropertyValue(interface)=&lt;Windows.Foundation.FoundationContract, Version=4.0.0.0, Culture=neutral, PublicKeyToken=null&gt;Windows.Foundation.IPropertyValue
        /// </summary>
        /// <param name="fullName">Symbol name</param>
        /// <param name="typeRef">Type ref to symbol</param>
        /// <returns></returns>
        private bool ConvertTypeToImportedType(string fullName, out TypeReferenceHandle typeRef)
        {
            typeRef = default;

            if (this.typeImports.TryGetValue(fullName, out var importInfoText))
            {
                var match = TypeImportRegex.Match(importInfoText);
                if (!match.Success)
                {
                    this.diagnostics.Add(new GeneratorDiagnostic($"Failed to convert imported type info for {fullName}: {importInfoText}", DiagnosticSeverity.Error));
                    return false;
                }

                var strongName = match.Groups[1].Value;
                if (!this.assemblyNamesToRefHandles.TryGetValue(strongName, out var assemblyRef))
                {
                    string assemblyName = match.Groups[2].Value;
                    Version assemblyVersion = Version.Parse(match.Groups[3].Value);
                    string publicKeyToken = match.Groups[5].Value;
                    BlobHandle publicKeyTokenBlobHandle = publicKeyToken == "null" ? default : this.metadataBuilder.GetOrAddBlob(ConvertKeyToByteArray(publicKeyToken));

                    assemblyRef =
                        this.metadataBuilder.AddAssemblyReference(
                            this.metadataBuilder.GetOrAddString(assemblyName),
                            assemblyVersion,
                            default,
                            publicKeyTokenBlobHandle,
                            default,
                            default);

                    this.assemblyNamesToRefHandles[strongName] = assemblyRef;
                }

                string newFullName = match.Groups[6].Value;
                int lastDot = newFullName.LastIndexOf('.');
                string newNamespace = newFullName.Substring(0, lastDot);
                string newName = newFullName.Substring(lastDot + 1);

                var nsHandle = this.metadataBuilder.GetOrAddString(newNamespace);
                typeRef = this.metadataBuilder.AddTypeReference(
                    assemblyRef,
                    nsHandle,
                    this.metadataBuilder.GetOrAddString(newName));
                this.namesToTypeRefHandles[fullName] = typeRef;

                return true;
            }

            return false;
        }

        private bool IsSymbolInterface(ISymbol symbol)
        {
            return this.interfaceSymbols.Contains(symbol) || this.typeImportInterfaces.Contains(symbol.Name);
        }

        private bool NeedsPointerReduction(ISymbol symbol)
        {
            if (this.IsSymbolInterface(symbol))
            {
                return true;
            }

            return this.reducePointerLevels.Contains(symbol.Name);
        }

        private void EncodeTypeSymbol(ITypeSymbol typeSymbol, SignatureTypeEncoder typeEncoder)
        {
            if (typeSymbol.SpecialType != SpecialType.None)
            {
                typeEncoder.EncodeSpecialType(typeSymbol.SpecialType);
            }
            else
            {
                if (typeSymbol.ToString() == "void*")
                {
                    typeEncoder.VoidPointer();
                    return;
                }

                // ClangSharp mistakenly emits WCHAR foo[] as string[] instead of string
                if (typeSymbol.ToString() == "string[]")
                {
                    typeEncoder.EncodeSpecialType(SpecialType.System_String);
                    return;
                }

                if (typeSymbol is IPointerTypeSymbol pointer)
                {
                    if (this.NeedsPointerReduction(pointer.PointedAtType))
                    {
                        this.EncodeTypeSymbol(pointer.PointedAtType, typeEncoder);
                    }
                    else
                    {
                        typeEncoder.Pointer();
                        this.EncodeTypeSymbol(pointer.PointedAtType, typeEncoder);
                    }

                    return;
                }

                bool isTypeInterface = this.IsSymbolInterface(typeSymbol);
                EntityHandle refHandle = this.GetTypeRefOrDef(typeSymbol);

                if (refHandle != default)
                {
                    typeEncoder.Type(
                        refHandle,
                        !isTypeInterface && (typeSymbol.TypeKind == TypeKind.Enum || typeSymbol.TypeKind == TypeKind.Struct));
                }
            }
        }

        private void WriteEnumMembers(EnumDeclarationSyntax node)
        {
            foreach (EnumMemberDeclarationSyntax member in node.Members)
            {
                var enumFieldAttributes =
                    FieldAttributes.Public |
                    FieldAttributes.Static |
                    FieldAttributes.Literal |
                    FieldAttributes.HasDefault;

                var model = this.GetModel(member);
                var symbol = model.GetDeclaredSymbol(member);
                var type = symbol.ContainingType;
                var fieldSignature = new BlobBuilder();
                var encoder = new BlobEncoder(fieldSignature);
                var signatureEncoder = encoder.FieldSignature();

                this.EncodeTypeSymbol(type, signatureEncoder);

                var memberName = FixFinalName(member.Identifier.Text);
                if (string.IsNullOrEmpty(memberName))
                {
                    throw new InvalidOperationException($"Enum {node.Identifier.Text} has a member with no name.");
                }

                var fieldDefinitionHandle = this.metadataBuilder.AddFieldDefinition(
                    enumFieldAttributes,
                    this.metadataBuilder.GetOrAddString(memberName),
                    this.metadataBuilder.GetOrAddBlob(fieldSignature));

                if (symbol.HasConstantValue)
                {
                    this.metadataBuilder.AddConstant(fieldDefinitionHandle, symbol.ConstantValue);
                }
            }
        }

        private EntityHandle GetCtorRef(string typeName, string[] argTypes)
        {
            string ctorKey = typeName + "::" + string.Join(',', argTypes);
            if (!this.ctorNamesToRefs.TryGetValue(ctorKey, out var ctorRef))
            {
                var interfaceTypeAttr = this.GetTypeByMetadataName(typeName);
                List<ITypeSymbol> typeSymbols = new List<ITypeSymbol>();
                List<Parameter> parameters = new List<Parameter>();
                foreach (var a in argTypes)
                {
                    var argType = this.GetTypeByMetadataName(a);
                    typeSymbols.Add(argType);
                    Parameter p = new Parameter(string.Empty, argType, ParameterAttributes.None);
                    parameters.Add(p);
                }

                var ctorFound = 
                    interfaceTypeAttr
                        .Constructors
                        .First(c => c.Parameters.Length == argTypes.Length && c.Parameters.Select(param => param.Type)
                        .SequenceEqual(typeSymbols));

                var @namespace = interfaceTypeAttr.ContainingNamespace.ToString();
                var name = interfaceTypeAttr.Name;

                var typeRef = this.GetTypeReference(@namespace, name);

                ctorRef = this.CreateAndCacheCtorRefForTypeRef(typeRef, parameters, ctorKey);
            }

            return ctorRef;
        }

        private EntityHandle CreateAndCacheCtorRefForTypeRef(EntityHandle typeRef, List<Parameter> parameters, string ctorKey)
        {
            var methodSignature = new BlobBuilder();
            new BlobEncoder(methodSignature)
                .MethodSignature(
                    SignatureCallingConvention.Default,
                    0,
                    true)
                .Parameters(
                    parameters.Count(),
                    returnTypeEncoder => this.EncodeReturnType(null, returnTypeEncoder),
                    parametersEncoder => this.EncodeParameters(parameters, parametersEncoder)
                );
            var ctorRef =
                this.metadataBuilder.AddMemberReference(
                    typeRef,
                    this.metadataBuilder.GetOrAddString(".ctor"),
                    this.metadataBuilder.GetOrAddBlob(methodSignature));
            this.ctorNamesToRefs[ctorKey] = ctorRef;
            return ctorRef;
        }

        private EntityHandle GetAttributeCtorRef(AttributeData attributeData)
        {
            if (attributeData.AttributeConstructor == null)
            {
                throw new InvalidOperationException($"Failed to find attribute ctor for {attributeData}. Make sure the using statement for the attribute's assembly is in the source file.");
            }

            string ctorKey = attributeData.AttributeConstructor.ToDisplayString();
            if (!this.ctorNamesToRefs.TryGetValue(ctorKey, out var ctorRef))
            {
                var @namespace = attributeData.AttributeClass.ContainingNamespace.ToString();
                var name = attributeData.AttributeClass.Name;

                var typeRef = this.GetTypeReference(@namespace, name);

                List<Parameter> parameters = new List<Parameter>();
                foreach (var arg in attributeData.ConstructorArguments)
                {
                    Parameter p = new Parameter(string.Empty, arg.Type, ParameterAttributes.None);
                    parameters.Add(p);
                }

                ctorRef = this.CreateAndCacheCtorRefForTypeRef(typeRef, parameters, ctorKey);
            }

            return ctorRef;
        }

        private void AddCustomAttribute(string typeName, string[] ctorArgTypes, object[] ctorConstArgValues, EntityHandle entityHandle)
        {
            var ctorRef = this.GetCtorRef(typeName, ctorArgTypes);
            var attributeSignature = new BlobBuilder();
            new BlobEncoder(attributeSignature)
                .CustomAttributeSignature(
                    fixedArguments => fixedArguments.ConstArguments(ctorConstArgValues),
                    namedArguments => namedArguments.Count(0)
                );

            this.metadataBuilder.AddCustomAttribute(
                entityHandle,
                ctorRef,
                this.metadataBuilder.GetOrAddBlob(attributeSignature));
        }

        private void AddCustomAttribute(AttributeData attributeData, EntityHandle entityHandle)
        {
            var ctorRef = this.GetAttributeCtorRef(attributeData);

            var attributeSignature = new BlobBuilder();
            new BlobEncoder(attributeSignature)
                .CustomAttributeSignature(
                    fixedArguments => fixedArguments.FixedArguments(attributeData.ConstructorArguments),
                    namedArguments => namedArguments.NamedArguments(attributeData.AttributeClass, attributeData.NamedArguments)
                );

            this.metadataBuilder.AddCustomAttribute(
                entityHandle,
                ctorRef,
                this.metadataBuilder.GetOrAddBlob(attributeSignature));
        }

        private void AddCustomAttributes(IEnumerable<AttributeData> attrs, EntityHandle entityHandle)
        {
            foreach (var attributeData in attrs)
            {
                switch (attributeData.AttributeClass.Name)
                {
                    case "NativeTypeNameAttribute": // We may want to preserve this for some cases, like to disambiguate handle types

                    // These are all attributes that get converted into flags or settings for different nodes.
                    // If we keep these then when it gets decompiled it looks like there are two of everything
                    case "StructLayoutAttribute":
                    case "FieldOffsetAttribute":
                    case "InAttribute":
                    case "OutAttribute":
                    case "OptionalAttribute":
                    case "DllImportAttribute":
                    case "NativeInheritanceAttribute":
                    case "PreserveSigAttribute":
                        continue;
                }

                this.AddCustomAttribute(attributeData, entityHandle);
            }
        }

        private void AddCustomAttributes(ISymbol symbol, EntityHandle entityHandle)
        {
            this.AddCustomAttributes(symbol.GetAttributes(), entityHandle);
        }

        private void AddCustomAttributes(SyntaxNode node, EntityHandle entityHandle)
        {
            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);

            this.AddCustomAttributes(symbol, entityHandle);
        }

        private ISymbol GetInheritedInterfaceSymbol(StructDeclarationSyntax node)
        {
            if (this.structNodesToInheritedSymbols.TryGetValue(node, out var retSymbol))
            {
                return retSymbol;
            }

            foreach (var attrList in node.AttributeLists)
            {
                foreach (var attr in attrList.Attributes)
                {
                    if (attr.Name.ToString() == "NativeInheritance")
                    {
                        var name = EncodeHelpers.RemoveQuotes(attr.ArgumentList.Arguments[0].ToString());
                        if (this.namesToInterfaceSymbols.TryGetValue(name, out var symbols))
                        {
                            // Could short circuit if there's only one, but this ensures the methods
                            // truly match up

                            // Get a map of all methods on this interface
                            var model = this.GetModel(node);
                            HashSet<string> methodNames = new HashSet<string>();
                            foreach (var method in node.Members.Where(m => m is MethodDeclarationSyntax))
                            {
                                var methodSymbol = model.GetDeclaredSymbol(method);
                                var methodName = methodSymbol.Name;

                                methodNames.Add(methodName);
                            }

                            // See if all the methods of the candidate symbol are also
                            // in the node's methods
                            foreach (INamedTypeSymbol symbol in symbols)
                            {
                                bool allFound = true;
                                foreach (var member in symbol.GetMembers().Where(m => m is IMethodSymbol && m.Name != ".ctor"))
                                {
                                    if (!methodNames.Contains(member.Name))
                                    {
                                        allFound = false;
                                        break;
                                    }
                                }

                                if (allFound)
                                {
                                    this.structNodesToInheritedSymbols[node] = symbol;
                                    return symbol;
                                }
                            }

                            throw new InvalidOperationException($"Failed to find suitable inhertited interface {name} for interace {node.Identifier.ValueText}");
                        }
                        else
                        {
                            throw new InvalidOperationException($"Failed to find inhertited interface {name} for interace {node.Identifier.ValueText}");
                        }
                    }
                }
            }

            return null;
        }

        private int GetInheritedMethodCount(StructDeclarationSyntax node)
        {
            var inheritedFrom = this.GetInheritedInterfaceSymbol(node);
            if (inheritedFrom == null)
            {
                return 0;
            }

            return this.interfaceMethodCount[inheritedFrom];
        }

        private MethodDefinitionHandle WriteInterfaceMethods(StructDeclarationSyntax node)
        {
            MethodDefinitionHandle firstMethod = default;

            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);

            var inheritedMethodCount = this.GetInheritedMethodCount(node);

            foreach (MethodDeclarationSyntax method in node.Members.Where(m => m is MethodDeclarationSyntax)
                .OrderBy(m => SyntaxUtils.GetVtableSlotFromMethodBody((MethodDeclarationSyntax)m))
                .Skip(inheritedMethodCount))
            {
                var methodSymbol = model.GetDeclaredSymbol(method);
                var methodName = methodSymbol.Name;
                MethodAttributes methodAttributes = MethodAttributes.Public | MethodAttributes.HideBySig | MethodAttributes.NewSlot | MethodAttributes.Abstract | MethodAttributes.Virtual;

                if (IsSpecialNameRegex.IsMatch(methodName))
                {
                    methodAttributes |= MethodAttributes.SpecialName;
                }

                MethodImplAttributes methodImplAttributes = MethodImplAttributes.Managed;

                if (methodSymbol.GetAttributes().Any(a => a.AttributeClass.Name == "PreserveSigAttribute"))
                {
                    methodImplAttributes |= MethodImplAttributes.PreserveSig;
                }

                var methodDef =
                    this.AddMethodViaSymbol(
                        methodSymbol,
                        methodAttributes,
                        methodImplAttributes,
                        true);

                if (firstMethod.IsNil)
                {
                    firstMethod = methodDef;
                }

                this.AddCustomAttributes(method, methodDef);
            }

            return firstMethod;
        }

        private BlobBuilder EncodeFieldSignature(string structName, SemanticModel model, FieldDeclarationSyntax field, out string name)
        {
            var fieldVariable = field.Declaration.Variables.First();
            IFieldSymbol fieldSymbol = (IFieldSymbol)model.GetDeclaredSymbol(fieldVariable);
            var type = model.GetTypeInfo(field.Declaration.Type).Type;
            var fieldSignature = new BlobBuilder();
            var encoder = new BlobEncoder(fieldSignature);
            var signatureEncoder = encoder.FieldSignature();

            name = fieldSymbol.Name;

            this.RemapToMoreSpecificTypeIfPossible(structName, name, fieldSymbol.GetAttributes(), ref type);

            if (type.Name.EndsWith("_e__FixedBuffer"))
            {
                // Convert fixed buffer type into an array
                if (!this.fixedBufferTypeToInfo.TryGetValue(type, out FixedBufferInfo fixedBufferInfo))
                {
                    // If we haven't visited the node that defines the fixed buffer type, do it now
                    StructDeclarationSyntax structNode = (StructDeclarationSyntax)type.DeclaringSyntaxReferences[0].GetSyntax();
                    this.AddFixedBufferTypeInfoForStructNode(structNode);
                    fixedBufferInfo = this.fixedBufferTypeToInfo[type];
                }

                var fieldType = fixedBufferInfo.Type;
                this.RemapToMoreSpecificTypeIfPossible(structName, name, fieldSymbol.GetAttributes(), ref fieldType);

                bool symbolsChanged = !SymbolEqualityComparer.Default.Equals(fieldType, fixedBufferInfo.Type);
                if (symbolsChanged && fieldType is IPointerTypeSymbol pointer)
                {
                    fieldType = pointer.PointedAtType;
                }

                signatureEncoder.Array(
                    s => this.EncodeTypeSymbol(fieldType, signatureEncoder),
                    h => h.Shape(1, new int[1] { fixedBufferInfo.Count }.ToImmutableArray(), new int[1] { 0 }.ToImmutableArray()));
            }
            // Arrays
            else if (fieldVariable.ArgumentList is BracketedArgumentListSyntax bracketedArgList)
            {
                if (bracketedArgList.Arguments[0].Expression is LiteralExpressionSyntax literalExp)
                {
                    int size = int.Parse(literalExp.Token.Text);
                    signatureEncoder.Array(s => this.EncodeTypeSymbol(type, signatureEncoder), h => h.Shape(1, new int[1] { size }.ToImmutableArray(), new int[1] { 0 }.ToImmutableArray()));
                }
                else if (bracketedArgList.Arguments[0].Expression is BinaryExpressionSyntax binaryExp)
                {
                    var litLeft = (LiteralExpressionSyntax)binaryExp.Left;
                    var litRight = (LiteralExpressionSyntax)binaryExp.Right;
                    int size = int.Parse(litLeft.Token.Text) * int.Parse(litRight.Token.Text);
                    signatureEncoder.Array(s => this.EncodeTypeSymbol(type, signatureEncoder), h => h.Shape(1, new int[1] { size }.ToImmutableArray(), new int[1] { 0 }.ToImmutableArray()));
                }
            }
            else
            {
                var nativeType =
                    SyntaxUtils.GetNativeTypeNameFromAttributesLists(field.AttributeLists);

                // See if this is a type that ends with an array that needs to be emitted as a 1-length array
                // which means a variable-length array
                if (nativeType != null && nativeType.EndsWith("[]") && !(type is IPointerTypeSymbol))
                {
                    signatureEncoder.Array(s => this.EncodeTypeSymbol(type, signatureEncoder), h => h.Shape(1, new int[1] { 1 }.ToImmutableArray(), new int[1] { 0 }.ToImmutableArray()));
                }
                else
                {
                    this.EncodeTypeSymbol(type, signatureEncoder);
                }
            }

            return fieldSignature;
        }

        private void WriteStructEnums(StructDeclarationSyntax node, TypeDefinitionHandle structTypeDefHandle)
        {
            foreach (EnumDeclarationSyntax enumNode in node.Members.Where(m => m is EnumDeclarationSyntax))
            {
                this.WriteEnumDef(enumNode, structTypeDefHandle);
            }
        }

        private FieldDefinitionHandle WriteStructFields(StructDeclarationSyntax node)
        {
            FieldDefinitionHandle firstField = default;

            if (this.IsInterfaceDef(node))
            {
                throw new InvalidOperationException();
            }

            var structName = node.Identifier.ValueText;
            if (structName.EndsWith("_e__FixedBuffer"))
            {
                return firstField;
            }

            var model = this.GetModel(node);
            var structSymbol = model.GetDeclaredSymbol(node);

            // Write fields
            foreach (FieldDeclarationSyntax field in node.Members.Where(m => m is FieldDeclarationSyntax))
            {
                var fieldSignature = this.EncodeFieldSignature(structName, model, field, out string name);
                var fieldVariable = field.Declaration.Variables.First();
                var fieldAttributes = FieldAttributes.Public;
                IFieldSymbol fieldSymbol = (IFieldSymbol)model.GetDeclaredSymbol(fieldVariable);
                bool isConst = fieldSymbol.IsStatic && fieldSymbol.HasConstantValue;

                if (isConst)
                {
                    fieldAttributes |= FieldAttributes.Static | FieldAttributes.Literal | FieldAttributes.HasDefault;
                }

                var fieldDefinitionHandle =
                    this.metadataBuilder.AddFieldDefinition(
                        fieldAttributes,
                        this.metadataBuilder.GetOrAddString(name),
                        this.metadataBuilder.GetOrAddBlob(fieldSignature));
                if (firstField.IsNil)
                {
                    firstField = fieldDefinitionHandle;
                }

                if (isConst)
                {
                    this.metadataBuilder.AddConstant(fieldDefinitionHandle, fieldSymbol.ConstantValue);
                }

                var fieldOffsetAttr = fieldSymbol.GetAttributes().FirstOrDefault(a => a.AttributeClass.Name == "FieldOffsetAttribute");
                if (fieldOffsetAttr != null)
                {
                    int offset = (int)fieldOffsetAttr.ConstructorArguments[0].Value;
                    this.metadataBuilder.AddFieldLayout(fieldDefinitionHandle, offset);
                }

                this.AddCustomAttributes(fieldVariable, fieldDefinitionHandle);
            }

            return firstField;
        }

        private List<T> GetUnvistedPartialDefs<T>(T node) where T : TypeDeclarationSyntax
        {
            List<T> nodes = new List<T>();

            if (this.visitedPartialDefs.Contains(node))
            {
                return nodes;
            }

            bool isPartial = node.Modifiers.Any(m => m.ValueText == "partial");
            nodes.Add(node);
            this.visitedPartialDefs.Add(node);

            if (isPartial)
            {
                var model = this.GetModel(node);
                var symbol = model.GetDeclaredSymbol(node);
                string fullName = symbol.ConstructedFrom.ToString();
                var symbolsWithSameName = this.compilation.GetSymbolsWithName(symbol.Name, SymbolFilter.Type);
                foreach (INamedTypeSymbol foundSymbol in symbolsWithSameName)
                {
                    if (foundSymbol.ConstructedFrom.ToString() != fullName)
                    {
                        continue;
                    }

                    foreach (var declaringSyntaxNode in foundSymbol.DeclaringSyntaxReferences)
                    {
                        var foundNode = declaringSyntaxNode.GetSyntax() as T;
                        if (foundNode == null || foundNode == node || this.visitedPartialDefs.Contains(foundNode))
                        {
                            continue;
                        }

                        nodes.Add(foundNode);
                        this.visitedPartialDefs.Add(foundNode);
                    }
                }
            }

            return nodes;
        }

        private class SyntaxWalker : CSharpSyntaxWalker
        {
            private ClangSharpSourceWinmdGenerator parent;

            public SyntaxWalker(ClangSharpSourceWinmdGenerator parent)
            {
                this.parent = parent;
            }

            public override void VisitEnumDeclaration(EnumDeclarationSyntax node)
            {
                try
                {
                    this.parent.WriteEnumDef(node);
                }
                catch (Exception e)
                {
                    string message = $"Failed to emit {node.Identifier.ValueText} in {node.SyntaxTree.FilePath}: {e.Message}";
                    this.parent.diagnostics.Add(new GeneratorDiagnostic(message, DiagnosticSeverity.Error));
                }
            }

            public override void VisitStructDeclaration(StructDeclarationSyntax node)
            {
                try
                {
                    this.parent.WriteStructDef(node);
                }
                catch (Exception e)
                {
                    string message = $"Failed to emit {node.Identifier.ValueText} in {node.SyntaxTree.FilePath}: {e.Message}";
                    this.parent.diagnostics.Add(new GeneratorDiagnostic(message, DiagnosticSeverity.Error));
                }
            }

            public override void VisitDelegateDeclaration(DelegateDeclarationSyntax node)
            {
                try
                {
                    this.parent.WriteDelegateDef(node);
                }
                catch (Exception e)
                {
                    string message = $"Failed to emit {node.Identifier.ValueText} in {node.SyntaxTree.FilePath}: {e.Message}";
                    this.parent.diagnostics.Add(new GeneratorDiagnostic(message, DiagnosticSeverity.Error));
                }
            }

            public override void VisitClassDeclaration(ClassDeclarationSyntax node)
            {
                try
                {
                    this.parent.WriteClassDef(node);
                }
                catch (Exception e)
                {
                    string message = $"Failed to emit {node.Identifier.ValueText} in {node.SyntaxTree.FilePath}: {e.Message}";
                    this.parent.diagnostics.Add(new GeneratorDiagnostic(message, DiagnosticSeverity.Error));
                }
            }
        }

        private class InterfaceWalker : CSharpSyntaxWalker
        {
            private ClangSharpSourceWinmdGenerator parent;

            public InterfaceWalker(ClangSharpSourceWinmdGenerator parent)
            {
                this.parent = parent;
            }

            public override void VisitStructDeclaration(StructDeclarationSyntax node)
            {
                base.VisitStructDeclaration(node);

                if (this.parent.IsInterfaceDef(node))
                {
                    this.parent.CacheInterfaceType(node);
                }
                
                if (HasGuidAttribute(node.AttributeLists))
                {
                    this.parent.structNameWithGuids.Add(node.Identifier.ValueText);
                }
            }

            public override void VisitFieldDeclaration(FieldDeclarationSyntax node)
            {
                if (node.Modifiers.ToString() == "public static readonly" && node.Declaration.Type.ToString() == "Guid")
                {
                    this.parent.CacheGuidConst(node);
                }
            }
        }

        private class FixedBufferInfo
        {
            public FixedBufferInfo(ITypeSymbol type, int count)
            {
                this.Type = type;
                this.Count = count;
            }

            public ITypeSymbol Type { get; }
            public int Count { get; }
        }

        private class Parameter
        {
            public Parameter(string name, ITypeSymbol type, ParameterAttributes attrs)
            {
                this.Name = name;
                this.Type = type;
                this.Attrs = attrs;
            }

            public Parameter(ClangSharpSourceWinmdGenerator generator, IMethodSymbol methodSymbol, IParameterSymbol parameterSymbol)
            {
                this.Symbol = parameterSymbol;

                var paramType = parameterSymbol.Type;
                var paramName = parameterSymbol.Name;

                string methodName;
                if (methodSymbol.ContainingType != null && methodSymbol.ContainingType.Name != "Apis")
                {
                    methodName = $"{methodSymbol.ContainingType.Name}.{methodSymbol.Name}";
                }
                else
                {
                    methodName = methodSymbol.Name;
                }

                generator.RemapToMoreSpecificTypeIfPossible(methodName, paramName, parameterSymbol.GetAttributes(), ref paramType);
                ParameterAttributes parameterAttributes = ParameterAttributes.None;
                var symbolAttrs = parameterSymbol.GetAttributes();
                if (symbolAttrs.Any(a => a.AttributeClass.Name == "InAttribute"))
                {
                    parameterAttributes |= ParameterAttributes.In;
                }

                // Figure out if the final type is a pointer or not.
                IPointerTypeSymbol pointerTypeSymbol = paramType as IPointerTypeSymbol;
                bool isInterface = pointerTypeSymbol != null && generator.IsSymbolInterface(pointerTypeSymbol.PointedAtType);
                bool isPointer = pointerTypeSymbol != null && !isInterface;

                // If it's not a pointer, see if it's a native typedef that has a pointer type as its value (like for PWSTR)
                if (!isPointer)
                {
                    if (paramType is INamedTypeSymbol namedType)
                    {
                        if (namedType.GetAttributes().Any(a => a.AttributeClass.Name == "NativeTypedefAttribute") &&
                            (paramType.GetMembers("Value").First() as IFieldSymbol).Type is IPointerTypeSymbol)
                        {
                            isPointer = true;
                        }
                    }
                }

                // Make sure we have a pointer before we add the Out attribute
                if (isPointer && symbolAttrs.Any(a => a.AttributeClass.Name == "OutAttribute" || a.AttributeClass.Name == "ComOutPtrAttribute"))
                {
                    parameterAttributes |= ParameterAttributes.Out;
                }

                if (symbolAttrs.Any(a => a.AttributeClass.Name == "OptionalAttribute"))
                {
                    parameterAttributes |= ParameterAttributes.Optional;
                }

                // If we don't have any in/out attributes, figure out some sensible values
                if (parameterAttributes == ParameterAttributes.None)
                {
                    // https://github.com/microsoft/win32metadata/issues/63
                    // * If it's a primitive or a COM pointer, it's In.
                    // * If it's a pointer it's In, Out, unless it's marked Const, then only In.
                    // * If it's a COM double pointer (e.g. IUnknown**), it's Out.
                    parameterAttributes |= ParameterAttributes.In;
                    if (pointerTypeSymbol != null)
                    {
                        // If we're not pointing at an interface...
                        if (!isInterface)
                        {
                            bool isConst = symbolAttrs.Any(a => a.AttributeClass.Name == "ConstAttribute");

                            // Only add Out if it's not const
                            if (!isConst)
                            {
                                parameterAttributes |= ParameterAttributes.Out;
                            }
                        }

                        // If it's a double pointer...
                        if (pointerTypeSymbol.PointedAtType is IPointerTypeSymbol doublePointedAtType)
                        {
                            // Only use "Out" if it's a double COM pointer
                            if (generator.IsSymbolInterface(doublePointedAtType.PointedAtType))
                            {
                                parameterAttributes = ParameterAttributes.Out;
                            }
                        }
                    }
                }

                this.Name = paramName;
                this.Attrs = parameterAttributes;
                this.Type = paramType;
            }

            public string Name { get; }
            public ITypeSymbol Type { get; }
            public ParameterAttributes Attrs { get; }
            public IParameterSymbol Symbol { get; }
        }
    }
}

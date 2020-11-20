// This adds the enclosing symbol name to the neseted type name.
// Can help disambiguate where a name came from when looking at a winmd
//#define MakeShortNameIncludeEnclosingName

using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace ClangSharpSourceToWinmd
{
    public class ClangSharpSourceWinmdGenerator
    {
        private MetadataBuilder metadataBuilder = new MetadataBuilder();
        private CSharpCompilation compilation;
        private AssemblyReferenceHandle systemAssemblyRef;
        private AssemblyReferenceHandle interopAssemblyRef;
        private string interopNamespace;
        private ModuleDefinitionHandle moduleRef;
        private Dictionary<string, TypeReferenceHandle> namesToTypeRefHandles = new Dictionary<string, TypeReferenceHandle>();
        private Dictionary<string, TypeDefinitionHandle> namesToTypeDefHandles = new Dictionary<string, TypeDefinitionHandle>();
        private HashSet<TypeDeclarationSyntax> visitedPartialDefs = new HashSet<TypeDeclarationSyntax>();
        private HashSet<ISymbol> interfaceSymbols = new HashSet<ISymbol>();
        private Dictionary<ITypeSymbol, FixedBufferInfo> fixedBufferTypeToInfo = new Dictionary<ITypeSymbol, FixedBufferInfo>();
        private Dictionary<SyntaxTree, SemanticModel> treeToModels = new Dictionary<SyntaxTree, SemanticModel>();
        private HashSet<StructDeclarationSyntax> interfaceStructs = new HashSet<StructDeclarationSyntax>();
        private Dictionary<string, EntityHandle> ctorNamesToRefs = new Dictionary<string, EntityHandle>();
        private Dictionary<string, ModuleReferenceHandle> moduleRefHandles = new Dictionary<string, ModuleReferenceHandle>();

        private ClangSharpSourceWinmdGenerator(CSharpCompilation compilation, Version assemblyVersion)
        {
            this.compilation = compilation;

            VerifySymbolsLoadedByCompiler();
            InitAssembly(assemblyVersion);
            InitModule();
            InitReferences();

            void VerifySymbolsLoadedByCompiler()
            {
                string[] standardSymbolNames = new string[] { "System.Object", "System.Attribute", "Microsoft.Windows.Sdk.Win32Metadata.Interop.NativeTypeInfoAttribute" };

                foreach (var name in standardSymbolNames)
                {
                    var type = this.compilation.GetTypeByMetadataName(name);
                    if (type == null)
                    {
                        throw new InvalidOperationException($"The compiler failed to find {type}. Make sure the references are correct.");
                    }
                }
            }

            void InitAssembly(Version version)
            {
                this.metadataBuilder.AddAssembly(
                    metadataBuilder.GetOrAddString(this.compilation.AssemblyName),
                    version,
                    default,
                    default,
                    default,
                    hashAlgorithm: AssemblyHashAlgorithm.None);
            }

            void InitModule()
            {
                this.moduleRef =
                    this.metadataBuilder.AddModule(
                        0,
                        metadataBuilder.GetOrAddString(this.compilation.AssemblyName),
                        metadataBuilder.GetOrAddGuid(Guid.NewGuid()),
                        default,
                        default);

                this.metadataBuilder.AddTypeDefinition(
                    default,
                    default,
                    metadataBuilder.GetOrAddString("<Module>"),
                    baseType: default(EntityHandle),
                    fieldList: MetadataTokens.FieldDefinitionHandle(1),
                    methodList: MetadataTokens.MethodDefinitionHandle(1));

            }

            void InitReferences()
            {
                const string SystemAssemblyName = "netstandard";
                //byte[] systemAssemblyStrongName = { 0xcc, 0x7b, 0x13, 0xff, 0xcd, 0x2d, 0xdd, 0x51 };
                Version systemVersion = new Version(2, 1, 0, 0);
                var netstandardAssembly = this.compilation.ReferencedAssemblyNames.ToList().Find(a => a.Name == SystemAssemblyName);
                this.systemAssemblyRef =
                    metadataBuilder.AddAssemblyReference(
                        this.metadataBuilder.GetOrAddString(netstandardAssembly.Name),
                        netstandardAssembly.Version,
                        default,
                        this.metadataBuilder.GetOrAddBlob(netstandardAssembly.PublicKeyToken),
                        default,
                        default);

                var interopAssembly = this.compilation.ReferencedAssemblyNames.ToList().Find(a => a.Name.Contains("Interop"));
                this.interopNamespace = interopAssembly.Name;
                this.interopAssemblyRef =
                    metadataBuilder.AddAssemblyReference(
                        this.metadataBuilder.GetOrAddString(this.interopNamespace),
                        interopAssembly.Version,
                        default,
                        this.metadataBuilder.GetOrAddBlob(interopAssembly.PublicKeyToken),
                        default,
                        default);
            }
        }

        public static void GenerateWindmdForCompilation(CSharpCompilation compilation, Version version, string outputFileName)
        {
            ClangSharpSourceWinmdGenerator generator = new ClangSharpSourceWinmdGenerator(compilation, version);

            generator.PopulateMetadataBuilder();
            generator.WriteWinmd(outputFileName);
        }

        private static string GetQualifiedName(string @namespace, string name)
        {
            return $"{@namespace}.{name}";
        }

        private void CacheInterfaceType(StructDeclarationSyntax interfaceNode)
        {
            var model = this.GetModel(interfaceNode);
            var symbol = model.GetDeclaredSymbol(interfaceNode);
            this.interfaceSymbols.Add(symbol);
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
            }
        }

        private EntityHandle GetTypeReference(string @namespace, string name)
        {
            string fullname = GetQualifiedName(@namespace, name);
            if (!this.namesToTypeRefHandles.TryGetValue(fullname, out var typeRef))
            {
                EntityHandle scopeRef;
                if (@namespace.StartsWith("System"))
                {
                    scopeRef = this.systemAssemblyRef;
                }
                else if (@namespace.StartsWith(this.interopNamespace))
                {
                    scopeRef = this.interopAssemblyRef;
                }
                else
                {
                    scopeRef = this.moduleRef;
                }

                int lastPlus = name.LastIndexOf('/');
                if (lastPlus != -1)
                {
                    string parent = name.Substring(0, lastPlus);
                    name = name.Substring(lastPlus + 1);
                    scopeRef = GetTypeReference(@namespace, parent);

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
                treeToModels[node.SyntaxTree] = model;
            }

            return model;
        }

        private void WriteEnumDef(EnumDeclarationSyntax node)
        {
            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);

            // Add special value__ field for enums
            FieldAttributes valueFieldAttrs = FieldAttributes.Public | FieldAttributes.SpecialName | FieldAttributes.RTSpecialName;
            var fieldSignature = new BlobBuilder();
            var encoder = new BlobEncoder(fieldSignature);
            encoder.FieldSignature().EncodeSpecialType(symbol.EnumUnderlyingType.SpecialType);

            var valueFieldDef =
                metadataBuilder.AddFieldDefinition(
                    valueFieldAttrs,
                    this.metadataBuilder.GetOrAddString("value__"),
                    this.metadataBuilder.GetOrAddBlob(fieldSignature));

            this.WriteEnumMembers(node);

            // Write type def
            TypeAttributes typeAttributes = TypeAttributes.Public | TypeAttributes.AnsiClass | TypeAttributes.Sealed | TypeAttributes.AutoLayout;
            var destTypeDefHandle =
                metadataBuilder.AddTypeDefinition(
                    typeAttributes,
                    metadataBuilder.GetOrAddString(symbol.ContainingNamespace.ToString()),
                    metadataBuilder.GetOrAddString(node.Identifier.ValueText),
                    this.GetTypeReference("System", "Enum"),
                    fieldList: valueFieldDef,
                    methodList: MetadataTokens.MethodDefinitionHandle(metadataBuilder.GetRowCount(TableIndex.MethodDef) + 1));

            string fullName = symbol.ConstructedFrom.ToString();
            this.namesToTypeDefHandles[fullName] = destTypeDefHandle;
        }

        private bool IsInterfaceDef(StructDeclarationSyntax node)
        {
            if (this.interfaceStructs.Contains(node))
            {
                return true;
            }
            
            bool ret = node.Members.Any(m => m.Kind() == SyntaxKind.FieldDeclaration && ((FieldDeclarationSyntax)m).Declaration.Variables.First().Identifier.Text == "lpVtbl");
            if (ret)
            {
                this.interfaceStructs.Add(node);
            }

            return ret;
        }

        private void WriteInterfaceDef(StructDeclarationSyntax node)
        {
            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);
            var nsHandle = metadataBuilder.GetOrAddString(symbol.ContainingNamespace.ToString());
            var name = node.Identifier.ValueText;
            string fullName = symbol.ConstructedFrom.ToString();

            MethodDefinitionHandle firstMethod = this.WriteInterfaceMethods(node);
            if (firstMethod.IsNil)
            {
                firstMethod = MetadataTokens.MethodDefinitionHandle(metadataBuilder.GetRowCount(TableIndex.MethodDef) + 1);
            }

            TypeAttributes typeAttributes = TypeAttributes.Interface | TypeAttributes.Public | TypeAttributes.AnsiClass | TypeAttributes.Abstract;
            var destTypeDefHandle =
                metadataBuilder.AddTypeDefinition(
                    typeAttributes,
                    nsHandle,
                    metadataBuilder.GetOrAddString(name),
                    default,
                    fieldList: MetadataTokens.FieldDefinitionHandle(metadataBuilder.GetRowCount(TableIndex.Field) + 1),
                    methodList: firstMethod);

            this.namesToTypeDefHandles[fullName] = destTypeDefHandle;

            this.AddCustomAttribute(
                "System.Runtime.InteropServices.InterfaceTypeAttribute",
                new string[] { "System.Runtime.InteropServices.ComInterfaceType" },
                new object[] { System.Runtime.InteropServices.ComInterfaceType.InterfaceIsIUnknown },
                destTypeDefHandle);
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
                firstField = MetadataTokens.FieldDefinitionHandle(metadataBuilder.GetRowCount(TableIndex.Field) + 1);
            }

            var nsHandle = enclosingType == default ? metadataBuilder.GetOrAddString(symbol.ContainingNamespace.ToString()) : default;
            var name = this.GetShortNameForSymbol(symbol);

            var destTypeDefHandle =
                metadataBuilder.AddTypeDefinition(
                    typeAttributes,
                    nsHandle,
                    metadataBuilder.GetOrAddString(name),
                    this.GetTypeReference("System", "ValueType"),
                    fieldList: firstField,
                    methodList: MetadataTokens.MethodDefinitionHandle(metadataBuilder.GetRowCount(TableIndex.MethodDef) + 1));

            this.namesToTypeDefHandles[fullName] = destTypeDefHandle;

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

            EncodeTypeSymbol(returnType, returnTypeEncoder.Type());
        }

        private void EncodeParameters(IEnumerable<Parameter> parameters, ParametersEncoder parametersEncoder)
        {
            foreach (var parameter in parameters)
            {
                var parameterTypeEncoder = parametersEncoder.AddParameter();
                EncodeTypeSymbol(parameter.Type, parameterTypeEncoder.Type());
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
            var methodSignature = new BlobBuilder();
            new BlobEncoder(methodSignature)
                .MethodSignature(
                    SignatureCallingConvention.Default,
                    0,
                    instanceMethod)
                .Parameters(
                    parameters.Count(),
                    returnTypeEncoder => EncodeReturnType(returnType, returnTypeEncoder),
                    parametersEncoder => EncodeParameters(parameters, parametersEncoder)
                );
            var newMethod =
                this.metadataBuilder.AddMethodDefinition(
                    methodAttrs,
                    methodImplAttributes,
                    metadataBuilder.GetOrAddString(methodName),
                    metadataBuilder.GetOrAddBlob(methodSignature),
                    -1,
                    MetadataTokens.ParameterHandle(metadataBuilder.GetRowCount(TableIndex.Param) + 1));

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
            List<Parameter> parameters = new List<Parameter>();
            foreach (var p in methodSymbol.Parameters)
            {
                parameters.Add(new Parameter(p));
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

                if (!fieldSymbol.IsConst)
                {
                    continue;
                }

                var fieldSignature = this.EncodeFieldSignature(model, field);

                var fieldDefinitionHandle =
                    metadataBuilder.AddFieldDefinition(
                        FieldAttributes.Public | FieldAttributes.Static | FieldAttributes.Literal | FieldAttributes.HasDefault,
                        metadataBuilder.GetOrAddString(fieldVariable.Identifier.Text),
                        metadataBuilder.GetOrAddBlob(fieldSignature));
                if (fieldSymbol.HasConstantValue)
                {
                    metadataBuilder.AddConstant(fieldDefinitionHandle, fieldSymbol.ConstantValue);
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

            foreach (MethodDeclarationSyntax method in node.Members.Where(m => m is MethodDeclarationSyntax))
            {
                var symbol = model.GetDeclaredSymbol(method);
                var methodName = method.Identifier.ValueText;

                if (!symbol.IsExtern)
                {
                    continue;
                }

                var methodDef =
                    this.AddMethodViaSymbol(
                        symbol,
                        MethodAttributes.Public | MethodAttributes.Static | MethodAttributes.HideBySig | MethodAttributes.PinvokeImpl,
                        MethodImplAttributes.Managed | MethodImplAttributes.PreserveSig,
                        false);
                if (firstMethod.IsNil)
                {
                    firstMethod = methodDef;
                }

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
            var nsHandle = metadataBuilder.GetOrAddString(symbol.ContainingNamespace.ToString());
            var name = node.Identifier.ValueText;
            string fullName = symbol.ConstructedFrom.ToString();

            TypeAttributes typeAttributes = TypeAttributes.Public | TypeAttributes.AutoClass | TypeAttributes.Abstract | TypeAttributes.Sealed | TypeAttributes.BeforeFieldInit;

            if (methodDefinition.IsNil)
            {
                methodDefinition = MetadataTokens.MethodDefinitionHandle(metadataBuilder.GetRowCount(TableIndex.MethodDef) + 1);
            }

            if (fieldDefinition.IsNil)
            {
                fieldDefinition = MetadataTokens.FieldDefinitionHandle(metadataBuilder.GetRowCount(TableIndex.Field) + 1);
            }

            var destTypeDefHandle =
                metadataBuilder.AddTypeDefinition(
                    typeAttributes,
                    nsHandle,
                    metadataBuilder.GetOrAddString(name),
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
            var nsHandle = metadataBuilder.GetOrAddString(symbol.ContainingNamespace.ToString());
            var name = node.Identifier.ValueText;
            string fullName = symbol.ConstructedFrom.ToString();

            TypeAttributes delegateTypeAttributes = TypeAttributes.Public | TypeAttributes.AutoClass | TypeAttributes.Sealed | TypeAttributes.BeforeFieldInit;

            MethodDefinitionHandle firstMethod = this.WriteDelegateMethods(node);
            if (firstMethod.IsNil)
            {
                firstMethod = MetadataTokens.MethodDefinitionHandle(metadataBuilder.GetRowCount(TableIndex.MethodDef) + 1);
            }

            var delegateDefHandle =
                metadataBuilder.AddTypeDefinition(
                    delegateTypeAttributes,
                    nsHandle,
                    metadataBuilder.GetOrAddString(name),
                    this.GetTypeReference("System", "MulticastDelegate"),
                    fieldList: MetadataTokens.FieldDefinitionHandle(metadataBuilder.GetRowCount(TableIndex.Field) + 1),
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
            return typeSymbol.Name;
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
            string nameWithoutNamespace = fullName.Substring(@namespace.Length + 1);
            return this.GetTypeReference(@namespace, nameWithoutNamespace);
        }

        private bool IsSymbolInterface(ISymbol symbol)
        {
            return this.interfaceSymbols.Contains(symbol);
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

                if (typeSymbol is IPointerTypeSymbol pointer)
                {
                    if (this.IsSymbolInterface(pointer.PointedAtType))
                    {
                        EncodeTypeSymbol(pointer.PointedAtType, typeEncoder);
                    }
                    else
                    {
                        typeEncoder.Pointer();
                        EncodeTypeSymbol(pointer.PointedAtType, typeEncoder);
                    }

                    return;
                }

                bool isTypeInterface = this.IsSymbolInterface(typeSymbol);
                typeEncoder.Type(
                    GetTypeRefOrDef(typeSymbol), 
                    !isTypeInterface && (typeSymbol.TypeKind == TypeKind.Enum || typeSymbol.TypeKind == TypeKind.Struct));
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

                EncodeTypeSymbol(type, signatureEncoder);

                var fieldDefinitionHandle = metadataBuilder.AddFieldDefinition(
                    enumFieldAttributes,
                    metadataBuilder.GetOrAddString(member.Identifier.Text),
                    metadataBuilder.GetOrAddBlob(fieldSignature));

                if (symbol.HasConstantValue)
                {
                    metadataBuilder.AddConstant(fieldDefinitionHandle, symbol.ConstantValue);
                }
            }
        }

        private EntityHandle GetCtorRef(string typeName, string[] argTypes)
        {
            string ctorKey = typeName + "::" + string.Join(',', argTypes);
            if (!ctorNamesToRefs.TryGetValue(ctorKey, out var ctorRef))
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

                ctorRef = CreateAndCacheCtorRefForTypeRef(typeRef, parameters, ctorKey);
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
                    returnTypeEncoder => EncodeReturnType(null, returnTypeEncoder),
                    parametersEncoder => EncodeParameters(parameters, parametersEncoder)
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

                ctorRef = CreateAndCacheCtorRefForTypeRef(typeRef, parameters, ctorKey);
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

            metadataBuilder.AddCustomAttribute(
                entityHandle,
                ctorRef,
                metadataBuilder.GetOrAddBlob(attributeSignature));
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

            metadataBuilder.AddCustomAttribute(
                entityHandle,
                ctorRef,
                metadataBuilder.GetOrAddBlob(attributeSignature));
        }

        private void AddCustomAttributes(IEnumerable<AttributeData> attrs, EntityHandle entityHandle)
        {
            foreach (var attributeData in attrs)
            {
                switch (attributeData.AttributeClass.Name)
                {
                    case "NativeTypeNameAttribute": // We may want to preserve this for some cases, like to disambiguate handle type

                    // These are all attributes that get converted into flags or settings for different nodes.
                    // If we keep these then when it gets decompiled it looks like there are two of everything
                    case "StructLayoutAttribute":
                    case "FieldOffsetAttribute":
                    case "InAttribute":
                    case "OutAttribute":
                    case "OptionalAttribute":
                    case "DllImportAttribute":
                        continue;
                }

                this.AddCustomAttribute(attributeData, entityHandle);
            }
        }

        private void AddCustomAttributes(SyntaxNode node, EntityHandle entityHandle)
        {
            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);

            this.AddCustomAttributes(symbol.GetAttributes(), entityHandle);
        }

        private MethodDefinitionHandle WriteInterfaceMethods(StructDeclarationSyntax node)
        {
            MethodDefinitionHandle firstMethod = default;

            int before = metadataBuilder.GetRowCount(TableIndex.MethodDef) + 1;
            var model = this.GetModel(node);
            var symbol = model.GetDeclaredSymbol(node);
            foreach (MethodDeclarationSyntax method in node.Members.Where(m => m is MethodDeclarationSyntax))
            {
                var methodSymbol = model.GetDeclaredSymbol(method);
                var methodName = methodSymbol.Name;

                if (symbol.Name != "IUnknown" && (methodName == "QueryInterface" || methodName == "AddRef" || methodName == "Release"))
                {
                    continue;
                }

                var methodDef =
                    this.AddMethodViaSymbol(
                        methodSymbol,
                        MethodAttributes.Public | MethodAttributes.HideBySig | MethodAttributes.NewSlot | MethodAttributes.Abstract | MethodAttributes.Virtual,
                        MethodImplAttributes.Managed,
                        true);

                if (firstMethod.IsNil)
                {
                    firstMethod = methodDef;
                }

                this.AddCustomAttributes(method, methodDef);
            }

            return firstMethod;
        }

        private BlobBuilder EncodeFieldSignature(SemanticModel model, FieldDeclarationSyntax field)
        {
            var fieldVariable = field.Declaration.Variables.First();
            IFieldSymbol fieldSymbol = (IFieldSymbol)model.GetDeclaredSymbol(fieldVariable);
            var type = model.GetTypeInfo(field.Declaration.Type).Type;
            var fieldSignature = new BlobBuilder();
            var encoder = new BlobEncoder(fieldSignature);
            var signatureEncoder = encoder.FieldSignature();

            if (type.Name.EndsWith("_e__FixedBuffer"))
            {
                // Convert fixed buffer type into an array
                if (!fixedBufferTypeToInfo.TryGetValue(type, out FixedBufferInfo fixedBufferInfo))
                {
                    // If we haven't visited the node that defixes the fixed buffer type, do it now
                    StructDeclarationSyntax structNode = (StructDeclarationSyntax)type.DeclaringSyntaxReferences[0].GetSyntax();
                    this.AddFixedBufferTypeInfoForStructNode(structNode);
                    fixedBufferInfo = fixedBufferTypeToInfo[type];
                }

                signatureEncoder.Array(
                    s => EncodeTypeSymbol(fixedBufferInfo.Type, signatureEncoder),
                    h => h.Shape(1, new int[1] { fixedBufferInfo.Count }.ToImmutableArray(), new int[1] { 0 }.ToImmutableArray()));
            }
            // Arrays
            else if (fieldVariable.ArgumentList is BracketedArgumentListSyntax bracketedArgList)
            {
                if (bracketedArgList.Arguments[0].Expression is LiteralExpressionSyntax literalExp)
                {
                    int size = int.Parse(literalExp.Token.Text);
                    signatureEncoder.Array(s => EncodeTypeSymbol(type, signatureEncoder), h => h.Shape(1, new int[1] { size }.ToImmutableArray(), new int[1] { 0 }.ToImmutableArray()));
                }
                else if (bracketedArgList.Arguments[0].Expression is BinaryExpressionSyntax binaryExp)
                {
                    var litLeft = (LiteralExpressionSyntax)binaryExp.Left;
                    var litRight = (LiteralExpressionSyntax)binaryExp.Right;
                    int size = int.Parse(litLeft.Token.Text) * int.Parse(litRight.Token.Text);
                    signatureEncoder.Array(s => EncodeTypeSymbol(type, signatureEncoder), h => h.Shape(1, new int[1] { size }.ToImmutableArray(), new int[1] { 0 }.ToImmutableArray()));
                }
            }
            else
            {
                EncodeTypeSymbol(type, signatureEncoder);
            }

            return fieldSignature;
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
                var fieldSignature = this.EncodeFieldSignature(model, field);
                var fieldVariable = field.Declaration.Variables.First();

                var fieldDefinitionHandle = 
                    metadataBuilder.AddFieldDefinition(
                        FieldAttributes.Public,
                        metadataBuilder.GetOrAddString(fieldVariable.Identifier.Text),
                        metadataBuilder.GetOrAddBlob(fieldSignature));
                if (firstField.IsNil)
                {
                    firstField = fieldDefinitionHandle;
                }

                var fieldSymbol = model.GetDeclaredSymbol(fieldVariable);
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
                this.parent.WriteEnumDef(node);
            }

            public override void VisitStructDeclaration(StructDeclarationSyntax node)
            {
                this.parent.WriteStructDef(node);
            }

            public override void VisitDelegateDeclaration(DelegateDeclarationSyntax node)
            {
                this.parent.WriteDelegateDef(node);
            }

            public override void VisitClassDeclaration(ClassDeclarationSyntax node)
            {
                this.parent.WriteClassDef(node);
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
                if (this.parent.IsInterfaceDef(node))
                {
                    this.parent.CacheInterfaceType(node);
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

            public Parameter(IParameterSymbol parameterSymbol)
            {
                this.Symbol = parameterSymbol;
                ParameterAttributes parameterAttributes = ParameterAttributes.None;
                var symbolAttrs = parameterSymbol.GetAttributes();
                if (symbolAttrs.Any(a => a.AttributeClass.Name == "InAttribute"))
                {
                    parameterAttributes |= ParameterAttributes.In;
                }

                if (symbolAttrs.Any(a => a.AttributeClass.Name == "OutAttribute"))
                {
                    parameterAttributes |= ParameterAttributes.Out;
                }

                if (symbolAttrs.Any(a => a.AttributeClass.Name == "OptionalAttribute"))
                {
                    parameterAttributes |= ParameterAttributes.Optional;
                }

                this.Name = parameterSymbol.Name;
                this.Attrs = parameterAttributes;
                this.Type = parameterSymbol.Type;
            }

            public string Name { get; }
            public ITypeSymbol Type { get; }
            public ParameterAttributes Attrs { get; }
            public IParameterSymbol Symbol { get; }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.IO;
using System.Linq;
using System.Text;
using System.Reflection;

namespace MetadataUtils
{
    public class WinmdUtils : IDisposable
    {
        private FileStream stream;
        private PEReader peReader;
        private MetadataReader metadataReader;
        private GenericSignatureTypeProvider provider = new GenericSignatureTypeProvider();

        private WinmdUtils(string fileName)
        {
            this.stream = new System.IO.FileStream(fileName, System.IO.FileMode.Open, System.IO.FileAccess.Read);
            this.peReader = new PEReader(this.stream);
            this.metadataReader = this.peReader.GetMetadataReader();
        }

        public static WinmdUtils LoadFromFile(string fileName)
        {
            return new WinmdUtils(fileName);
        }

        public void Dispose()
        {
            this.stream?.Dispose();
            this.peReader?.Dispose();
        }

        public IEnumerable<DllImport> GetDllImports()
        {
            foreach (var methodDefHandle in this.metadataReader.MethodDefinitions)
            {
                var method = this.metadataReader.GetMethodDefinition(methodDefHandle);
                if (method.Attributes.HasFlag(System.Reflection.MethodAttributes.PinvokeImpl))
                {
                    var name = this.metadataReader.GetString(method.Name);
                    var import = method.GetImport();
                    var moduleRef = this.metadataReader.GetModuleReference(import.Module);
                    var dllName = this.metadataReader.GetString(moduleRef.Name);
                    var declaringType = this.metadataReader.GetTypeDefinition(method.GetDeclaringType());
                    var declaringTypeName = this.metadataReader.GetString(declaringType.Name);
                    var declaringTypeNamespace = this.metadataReader.GetString(declaringType.Namespace);
                    var methodSignature = method.DecodeSignature<string, GenericContext>(this.provider, null);

                    yield return new DllImport(name, dllName, $"{declaringTypeNamespace}.{declaringTypeName}", methodSignature);
                }
            }
        }

        public IEnumerable<ConstInfo> GetConstants()
        {
            foreach (var typeDefHandle in this.metadataReader.TypeDefinitions)
            {
                var typeDef = this.metadataReader.GetTypeDefinition(typeDefHandle);

                if (typeDef.IsNested)
                {
                    continue;
                }

                var name = this.metadataReader.GetString(typeDef.Name);

                if (name != "Apis")
                {
                    continue;
                }

                var ns = this.metadataReader.GetString(typeDef.Namespace);
                var fields = typeDef.GetFields();
                foreach (var handle in fields)
                {
                    var fieldDef = this.metadataReader.GetFieldDefinition(handle);
                    if (fieldDef.Attributes.HasFlag(System.Reflection.FieldAttributes.Static | System.Reflection.FieldAttributes.Literal))
                    {
                        var constantHandle = fieldDef.GetDefaultValue();
                        var constant = this.metadataReader.GetConstant(constantHandle);
                        string fieldName = this.metadataReader.GetString(fieldDef.Name);
                        yield return new ConstInfo(ns, fieldName, constant.TypeCode);
                    }
                }
            }
        }

        private IEnumerable<FieldInfo> GetFieldInfos(FieldDefinitionHandleCollection fieldDefinitionHandles)
        {
            foreach (var fieldHandle in fieldDefinitionHandles)
            {
                var fieldDef = this.metadataReader.GetFieldDefinition(fieldHandle);
                var fieldName = this.metadataReader.GetString(fieldDef.Name);
                var fieldType = fieldDef.DecodeSignature<string, GenericContext>(this.provider, null);

                yield return new FieldInfo(fieldType, fieldName);
            }
        }

        private IEnumerable<ParameterInfo> GetParams(ParameterHandleCollection parameterHandles)
        {
            foreach (var pH in parameterHandles)
            {
                var p = this.metadataReader.GetParameter(pH);
                string pName = this.metadataReader.GetString(p.Name);
                if (!string.IsNullOrEmpty(pName))
                {
                    yield return new ParameterInfo(pName, p.Attributes);
                }
            }
        }

        private MethodInfo GetMethod(MethodDefinitionHandle methodDefinitionHandle)
        {
            var methodDef = this.metadataReader.GetMethodDefinition(methodDefinitionHandle);
            var methodSignature = methodDef.DecodeSignature<string, GenericContext>(this.provider, null);
            var paramHandles = methodDef.GetParameters();

            return new MethodInfo(this.metadataReader.GetString(methodDef.Name), methodSignature, this.GetParams(paramHandles));
        }

        private IEnumerable<MethodInfo> GetMethodInfos(MethodDefinitionHandleCollection methodDefinitionHandles)
        {
            foreach (var methodHandle in methodDefinitionHandles)
            {
                yield return this.GetMethod(methodHandle);
            }
        }

        public IEnumerable<TypeInfo> GetTypes()
        {
            foreach (var typeDefHandle in this.metadataReader.TypeDefinitions)
            {
                var typeDef = this.metadataReader.GetTypeDefinition(typeDefHandle);
                var name = this.metadataReader.GetString(typeDef.Name);
                var ns = this.metadataReader.GetString(typeDef.Namespace);

                if (typeDef.IsNested)
                {
                    continue;
                }

                if (name == "<Module>")
                {
                    continue;
                }

                var baseTypeDefHandle = typeDef.BaseType;
                string baseTypeName = null;
                if (baseTypeDefHandle.Kind == HandleKind.TypeReference)
                {
                    var declaringTypeRef = this.metadataReader.GetTypeReference((TypeReferenceHandle)baseTypeDefHandle);
                    baseTypeName = this.metadataReader.GetString(declaringTypeRef.Name);
                }

                if (baseTypeName == "MulticastDelegate")
                {
                    var methodHandles = typeDef.GetMethods();
                    foreach (var handle in methodHandles)
                    {
                        var methodDef = this.metadataReader.GetMethodDefinition(handle);
                        var methodName = this.metadataReader.GetString(methodDef.Name);
                        if (methodName == "Invoke")
                        {
                            var invokeMethodInfo = this.GetMethod(handle);

                            yield return new DelegateTypeInfo(ns, name, invokeMethodInfo.MethodSignature, invokeMethodInfo.Parameters);
                        }
                    }
                }
                else if (baseTypeName == "Enum")
                {
                    var fieldInfos = this.GetFieldInfos(typeDef.GetFields()).ToList();
                    var valueFieldInfo = fieldInfos.FirstOrDefault(f => f.Name == "value__");
                    if (valueFieldInfo != null)
                    {
                        string type = valueFieldInfo.Type;
                        var finalFields = fieldInfos.Where(f => f != valueFieldInfo);
                        yield return new EnumInfo(ns, name, type, finalFields);
                    }
                }
                else if (typeDef.Attributes.HasFlag(TypeAttributes.Interface))
                {
                    var implementedMethodCount = this.InternalGetImplementedMethodCount(typeDef);
                    var methodInfos = this.GetMethodInfos(typeDef.GetMethods());
                    yield return new InterfaceInfo(ns, name, methodInfos, implementedMethodCount);
                }
                else if (baseTypeName == "ValueType")
                {
                    var fieldInfos = this.GetFieldInfos(typeDef.GetFields());
                    yield return new StructInfo(ns, name, fieldInfos);
                }
                else if (baseTypeName == "Object")
                {
                    var fieldInfos = this.GetFieldInfos(typeDef.GetFields());
                    var methodInfos = this.GetMethodInfos(typeDef.GetMethods());
                    yield return new ClassInfo(ns, name, methodInfos, fieldInfos);
                }
                else
                {
                    // Skipping all others
                }
            }
        }

        private int InternalGetImplementedMethodCount(TypeDefinition typeDef)
        {
            int methodCount = typeDef.GetMethods().Count;
            var interfaceImplHandles = typeDef.GetInterfaceImplementations();
            foreach (var interfaceImplHandle in interfaceImplHandles)
            {
                var interfaceImpl = this.metadataReader.GetInterfaceImplementation(interfaceImplHandle);

                TypeDefinition interfaceTypeDef;
                switch (interfaceImpl.Interface.Kind)
                {
                    case HandleKind.TypeReference:
                        {
                            var interfaceTypeRefHandle = this.metadataReader.GetTypeReference((TypeReferenceHandle)interfaceImpl.Interface);
                            interfaceTypeDef = this.metadataReader.TypeDefinitions
                                .Select(h => this.metadataReader.GetTypeDefinition(h))
                                .First(iterType =>
                                    this.metadataReader.GetString(iterType.Name) == this.metadataReader.GetString(interfaceTypeRefHandle.Name) &&
                                    this.metadataReader.GetString(iterType.Namespace) == this.metadataReader.GetString(interfaceTypeRefHandle.Namespace));
                            break;
                        }

                    case HandleKind.TypeDefinition:
                        {
                            interfaceTypeDef = this.metadataReader.GetTypeDefinition((TypeDefinitionHandle)interfaceImpl.Interface);
                            break;
                        }
                    default:
                        throw new NotImplementedException();
                }

                methodCount += interfaceTypeDef.GetMethods().Count;
            }

            return methodCount;
        }
    }

    public class TypeInfo
    {
        public TypeInfo(string @namespace, string name)
        {
            this.Namespace = @namespace;
            this.Name = name;
        }

        public string Namespace { get; private set; }

        public string Name { get; private set; }
    }

    public class EnumInfo : TypeInfo
    {
        public EnumInfo(string @namespace, string name, string type, IEnumerable<FieldInfo> fieldInfos) :
            base(@namespace, name)
        {
            this.Type = type;
            this.Fields = fieldInfos;
        }

        public string Type { get; }

        public IEnumerable<FieldInfo> Fields { get; }

        public override string ToString()
        {
            StringBuilder ret = new StringBuilder($"{this.Name}(");
            var paramNames = string.Join(",", this.Fields.Select(f => f.Name).OrderBy(s => s));
            ret.Append(paramNames);
            ret.Append(")");
            return ret.ToString();
        }
    }

    public class ClassInfo : TypeInfo
    {
        public ClassInfo(string @namespace, string name, IEnumerable<MethodInfo> methodInfos, IEnumerable<FieldInfo> fieldInfos) :
            base(@namespace, name)
        {
            this.Methods = methodInfos;
            this.Fields = fieldInfos;
        }

        public IEnumerable<MethodInfo> Methods { get; }
        public IEnumerable<FieldInfo> Fields { get; }
        public override string ToString()
        {
            return $"{this.Namespace}.{this.Name}";
        }
    }

    public class InterfaceInfo : TypeInfo
    {
        public InterfaceInfo(string @namespace, string name, IEnumerable<MethodInfo> methodInfos, int implementedMethodCount) :
            base(@namespace, name)
        {
            this.Methods = methodInfos;
            this.ImplementedMethodCount = implementedMethodCount;
        }

        public IEnumerable<MethodInfo> Methods { get; }
        public int ImplementedMethodCount { get; }

        public override string ToString()
        {
            StringBuilder ret = new StringBuilder($"{this.Name}(");
            var methodNames = string.Join(",", this.Methods.Select(m => m.Name).OrderBy(s => s));
            ret.Append(methodNames);
            ret.Append(")");
            return ret.ToString();
        }
    }

    public class StructInfo : TypeInfo
    {
        public StructInfo(string @namespace, string name, IEnumerable<FieldInfo> fieldInfos) :
            base(@namespace, name)
        {
            this.Fields = fieldInfos;
        }

        public IEnumerable<FieldInfo> Fields { get; }

        public override string ToString()
        {
            StringBuilder ret = new StringBuilder($"{this.Name}(");
            var fieldNames = string.Join(",", this.Fields.Select(f => f.Name).OrderBy(s => s));
            ret.Append(fieldNames);
            ret.Append(")");
            return ret.ToString();
        }

        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }
    }

    public class FieldInfo
    {
        public FieldInfo(string type, string name)
        {
            this.Type = type;
            this.Name = name;
        }

        public string Type { get; }
        public string Name { get; }
    }

    public class DelegateTypeInfo : TypeInfo
    {
        public DelegateTypeInfo(string @namespace, string name, MethodSignature<string> methodSignature, IEnumerable<ParameterInfo> parameters) : base(@namespace, name)
        {
            this.Parameters = parameters;
            this.MethodSignature = methodSignature;
        }

        public MethodSignature<string> MethodSignature { get; }
        public IEnumerable<ParameterInfo> Parameters { get; private set; }

        public override string ToString()
        {
            StringBuilder ret = new StringBuilder($"{this.Name}(");
            var paramNames = string.Join(",", this.Parameters.Select(p => p.Name).OrderBy(s => s));
            ret.Append(paramNames);
            ret.Append(")");
            return ret.ToString();
        }

        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }
    }

    public class ConstInfo
    {
        public ConstInfo(string @namespace, string name, ConstantTypeCode typeCode)
        {
            this.Namespace = @namespace;
            this.Name = name;
            this.ConstantTypeCode = typeCode;
        }

        public string Namespace { get; private set; }

        public string Name { get; private set; }

        public ConstantTypeCode ConstantTypeCode { get; private set; }
    }

    public class ParameterInfo
    {
        public ParameterInfo(string name, ParameterAttributes parameterAttributes)
        {
            this.Name = name;
            this.Attributes = parameterAttributes;
        }

        public string Name
        {
            get;
        }

        public ParameterAttributes Attributes
        {
            get;
        }
    }

    public class MethodInfo
    {
        public MethodInfo(string name, MethodSignature<string> methodSignature, IEnumerable<ParameterInfo> parameters)
        {
            this.Name = name;
            this.MethodSignature = methodSignature;
            this.Parameters = parameters;
        }

        public string Name { get; }
        public MethodSignature<string> MethodSignature { get; }
        public IEnumerable<ParameterInfo> Parameters { get; }

        public override string ToString()
        {
            StringBuilder ret = new StringBuilder($"{this.Name}(");
            var paramNames = string.Join(",", this.Parameters.Select(p => p.Name).OrderBy(s => s));
            ret.Append(paramNames);
            ret.Append(")");
            return ret.ToString();
        }

        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }
    }

    public class DllImport
    {
        public DllImport(string name, string dll, string declaringType, MethodSignature<string> methodSignature)
        {
            this.Name = name;
            this.Dll = dll;
            this.DeclaringType = declaringType;
            this.MethodSignature = methodSignature;
        }

        public string DeclaringType { get; private set; }

        public string Name { get; private set; }

        public string Dll { get; private set; }

        public MethodSignature<string> MethodSignature { get; }

        public override string ToString()
        {
            return $"{this.Name}({this.Dll})";
        }

        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }
    }
}

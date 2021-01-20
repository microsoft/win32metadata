using System;
using System.Collections.Generic;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.IO;
using System.Linq;

namespace WinmdUtils
{
    public class WinmdUtils : IDisposable
    {
        private FileStream stream;
        private PEReader peReader;
        private MetadataReader metadataReader;

        private WinmdUtils(string fileName)
        {
            this.stream = new System.IO.FileStream(fileName, System.IO.FileMode.Open, System.IO.FileAccess.Read);
            this.peReader = new PEReader(stream);
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

                    yield return new DllImport(name, dllName, $"{declaringTypeNamespace}.{declaringTypeName}");
                }
            }
        }

        public IEnumerable<TypeInfo> GetTypes()
        {
            foreach (var typeDefHandle in this.metadataReader.TypeDefinitions)
            {
                var typeDef = this.metadataReader.GetTypeDefinition(typeDefHandle);
                var name = this.metadataReader.GetString(typeDef.Name);
                var ns = this.metadataReader.GetString(typeDef.Namespace);

                if (name == "Apis")
                {
                    continue;
                }

                // Some interfaces have the same name so use method names to determine uniqueness
                if (typeDef.Attributes.HasFlag(System.Reflection.TypeAttributes.Interface))
                {
                    name += "(";
                    var handles = typeDef.GetMethods();
                    bool first = true;
                    foreach (var handle in handles)
                    {
                        if (!first)
                        {
                            name += ",";
                        }
                        else
                        {
                            first = false;
                        }

                        var methodDef = this.metadataReader.GetMethodDefinition(handle);
                        name += metadataReader.GetString(methodDef.Name);
                    }
                    name += ")";
                }
                else
                {
                    var fields = typeDef.GetFields();
                    bool first = true;
                    foreach (var handle in fields.Take(10))
                    {
                        name += "(";
                        name += ")";

                        if (!first)
                        {
                            name += ",";
                        }
                        else
                        {
                            first = false;
                        }

                        var fieldDef = this.metadataReader.GetFieldDefinition(handle);
                        name += metadataReader.GetString(fieldDef.Name);
                    }
                }

                if (typeDef.IsNested)
                {
                    continue;
                }

                yield return new TypeInfo(ns, name);
            }
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

    public class DllImport
    {
        public DllImport(string name, string dll, string declaringType)
        {
            this.Name = name;
            this.Dll = dll;
            this.DeclaringType = declaringType;
        }

        public string DeclaringType { get; private set; }

        public string Name { get; private set; }

        public string Dll { get; private set; }

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

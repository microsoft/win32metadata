using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using MetadataUtils;

namespace WinmdUtilsProgram
{
    internal sealed class WinmdReviewMetadata : IDisposable
    {
        private readonly PEReader pe;
        private readonly MetadataReader reader;
        private readonly GenericSignatureTypeProvider provider = new();
        private readonly Dictionary<string, List<TypeDefinitionHandle>> types = new(StringComparer.Ordinal);
        private readonly Dictionary<string, object> entries = new(StringComparer.Ordinal);
        private readonly HashSet<string> gaps = new(StringComparer.Ordinal);

        internal WinmdReviewMetadata(string path)
        {
            this.pe = new PEReader(File.OpenRead(path));
            this.reader = this.pe.GetMetadataReader();
            foreach (var handle in this.reader.TypeDefinitions)
            {
                string name = this.TypeName(handle);
                if (!this.types.TryGetValue(name, out var variants))
                    this.types.Add(name, variants = new List<TypeDefinitionHandle>());
                variants.Add(handle);
            }
        }

        internal IEnumerable<object> Entries => this.entries.Values;
        internal IEnumerable<string> Gaps => this.gaps.OrderBy(s => s, StringComparer.Ordinal);

        internal static string LookupName(string symbol)
        {
            int context = symbol.IndexOf(" : ", StringComparison.Ordinal);
            if (context >= 0)
                symbol = symbol.Substring(0, context);
            int parameters = symbol.IndexOf('(');
            if (parameters >= 0)
                symbol = symbol.Substring(0, parameters);
            int removedParameter = symbol.IndexOf(", parameter ", StringComparison.Ordinal);
            return removedParameter < 0 ? symbol : symbol.Substring(0, removedParameter);
        }

        internal string[] Resolve(string symbol)
        {
            string lookup = LookupName(symbol);
            string owner = lookup;
            while (!this.types.ContainsKey(owner))
            {
                int separator = owner.LastIndexOf('.');
                if (separator < 0)
                {
                    this.gaps.Add(symbol);
                    return Array.Empty<string>();
                }
                owner = owner.Substring(0, separator);
            }
            string member = lookup == owner ? null : lookup.Substring(owner.Length + 1);
            var keys = new List<string>();
            foreach (var handle in this.types[owner])
            {
                var type = this.reader.GetTypeDefinition(handle);
                var fields = type.GetFields().Where(h => member == null || this.reader.GetString(this.reader.GetFieldDefinition(h).Name) == member).ToArray();
                var methods = type.GetMethods().Where(h => member == null || this.reader.GetString(this.reader.GetMethodDefinition(h).Name) == member).ToArray();
                if (member != null && fields.Length == 0 && methods.Length == 0)
                    continue;
                string key = owner + ":" + MetadataTokens.GetToken(handle).ToString("X8") + ":" + member;
                keys.Add(key);
                if (this.entries.ContainsKey(key))
                    continue;
                var layout = type.GetLayout();
                this.entries.Add(key, new
                {
                    key, identity = lookup,
                    type = new
                    {
                        name = owner,
                        token = MetadataTokens.GetToken(handle),
                        attributes = (int)type.Attributes,
                        baseType = this.Entity(type.BaseType),
                        packingSize = layout.PackingSize,
                        size = layout.Size,
                        customAttributes = this.Attributes(type.GetCustomAttributes()),
                        interfaces = type.GetInterfaceImplementations().Select(h => this.Entity(this.reader.GetInterfaceImplementation(h).Interface)).ToArray(),
                    },
                    selection = member == null ? "complete type and ordered fields/methods" : "complete selected member variants; parent type header retained",
                    fields = fields.Select(this.Field).ToArray(),
                    methods = methods.Select(this.Method).ToArray(),
                });
            }
            if (keys.Count == 0)
                this.gaps.Add(symbol);
            return keys.ToArray();
        }

        private object Field(FieldDefinitionHandle handle)
        {
            var field = this.reader.GetFieldDefinition(handle);
            return new
            {
                name = this.reader.GetString(field.Name),
                token = MetadataTokens.GetToken(handle),
                attributes = (int)field.Attributes,
                signature = this.Blob(field.Signature),
                decodedType = field.DecodeSignature(this.provider, null),
                offset = field.GetOffset(),
                defaultValue = this.Constant(field.GetDefaultValue()),
                marshalling = this.Blob(field.GetMarshallingDescriptor()),
                customAttributes = this.Attributes(field.GetCustomAttributes()),
            };
        }

        private object Method(MethodDefinitionHandle handle)
        {
            var method = this.reader.GetMethodDefinition(handle);
            var signature = method.DecodeSignature(this.provider, null);
            var import = method.GetImport();
            return new
            {
                name = this.reader.GetString(method.Name),
                token = MetadataTokens.GetToken(handle),
                attributes = (int)method.Attributes,
                implAttributes = (int)method.ImplAttributes,
                signature = this.Blob(method.Signature),
                callingConvention = signature.Header.CallingConvention.ToString(),
                returnType = signature.ReturnType,
                parameterTypes = signature.ParameterTypes.ToArray(),
                requiredParameters = signature.RequiredParameterCount,
                customAttributes = this.Attributes(method.GetCustomAttributes()),
                returnCustomAttributesAreInSequenceZeroParameter = true,
                parameters = method.GetParameters().Select(h =>
                {
                    var parameter = this.reader.GetParameter(h);
                    return new
                    {
                        name = this.reader.GetString(parameter.Name),
                        sequence = parameter.SequenceNumber,
                        attributes = (int)parameter.Attributes,
                        defaultValue = this.Constant(parameter.GetDefaultValue()),
                        marshalling = this.Blob(parameter.GetMarshallingDescriptor()),
                        customAttributes = this.Attributes(parameter.GetCustomAttributes()),
                    };
                }).ToArray(),
                import = import.Module.IsNil ? null : new
                {
                    module = this.reader.GetString(this.reader.GetModuleReference(import.Module).Name),
                    name = this.reader.GetString(import.Name),
                    attributes = (int)import.Attributes,
                },
            };
        }

        private object Constant(ConstantHandle handle)
        {
            if (handle.IsNil)
                return null;
            var value = this.reader.GetConstant(handle);
            return new { type = value.TypeCode.ToString(), bytes = this.Blob(value.Value) };
        }

        private object[] Attributes(CustomAttributeHandleCollection handles) => handles.Select(h =>
        {
            var attribute = this.reader.GetCustomAttribute(h);
            return (object)new { constructor = this.Entity(attribute.Constructor), value = this.Blob(attribute.Value) };
        }).ToArray();

        private string Blob(BlobHandle handle) => handle.IsNil ? null : Convert.ToHexString(this.reader.GetBlobBytes(handle));

        private string Entity(EntityHandle handle)
        {
            if (handle.IsNil)
                return null;
            if (handle.Kind == HandleKind.TypeDefinition)
                return this.TypeName((TypeDefinitionHandle)handle);
            if (handle.Kind == HandleKind.TypeReference)
            {
                var reference = this.reader.GetTypeReference((TypeReferenceHandle)handle);
                return this.reader.GetString(reference.Namespace) + "." + this.reader.GetString(reference.Name);
            }
            if (handle.Kind == HandleKind.MethodDefinition)
            {
                var method = this.reader.GetMethodDefinition((MethodDefinitionHandle)handle);
                return this.TypeName(method.GetDeclaringType()) + "." + this.reader.GetString(method.Name) + ":" + this.Blob(method.Signature);
            }
            if (handle.Kind == HandleKind.MemberReference)
            {
                var member = this.reader.GetMemberReference((MemberReferenceHandle)handle);
                return this.Entity(member.Parent) + "." + this.reader.GetString(member.Name) + ":" + this.Blob(member.Signature);
            }
            return handle.Kind + ":" + MetadataTokens.GetToken(handle).ToString("X8");
        }

        private string TypeName(TypeDefinitionHandle handle)
        {
            var type = this.reader.GetTypeDefinition(handle);
            string name = this.reader.GetString(type.Name);
            return type.IsNested ? this.TypeName(type.GetDeclaringType()) + "." + name :
                this.reader.GetString(type.Namespace) + "." + name;
        }

        public void Dispose() => this.pe.Dispose();
    }
}

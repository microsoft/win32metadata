using System;
using System.Collections.Immutable;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Security.Cryptography;
using Newtonsoft.Json.Linq;

namespace MetadataUtils
{
    // Unlike the display-oriented GenericSignatureTypeProvider, this provider never
    // aliases primitive types or drops calling conventions, modifiers, or array bounds.
    internal sealed class ContractTypeProvider : ISignatureTypeProvider<JObject, object>, ICustomAttributeTypeProvider<JObject>
    {
        private readonly MetadataReader reader;
        private readonly Dictionary<string, TypeDefinitionHandle[]> definitionsByName;
        private readonly Dictionary<string, PrimitiveTypeCode> enumTypes = new Dictionary<string, PrimitiveTypeCode>(StringComparer.Ordinal);

        internal ContractTypeProvider(MetadataReader reader)
        {
            this.reader = reader;
            definitionsByName = reader.TypeDefinitions.GroupBy(h => FullName(reader, h), StringComparer.Ordinal)
                .ToDictionary(g => g.Key, g => g.ToArray(), StringComparer.Ordinal);
        }

        internal static JObject Object(params object[] pairs)
        {
            var result = new JObject();
            for (int i = 0; i < pairs.Length; i += 2)
            {
                result.Add((string)pairs[i], pairs[i + 1] == null ? JValue.CreateNull() :
                    pairs[i + 1] is JToken token ? token : JToken.FromObject(pairs[i + 1]));
            }

            return result;
        }

        internal static JObject Signature(MethodSignature<JObject> signature)
        {
            return Object(
                "header", signature.Header.RawValue,
                "callingConvention", signature.Header.CallingConvention.ToString(),
                "hasThis", signature.Header.IsInstance,
                "explicitThis", signature.Header.HasExplicitThis,
                "genericParameterCount", signature.GenericParameterCount,
                "requiredParameterCount", signature.RequiredParameterCount,
                "returnType", signature.ReturnType,
                "parameterTypes", new JArray(signature.ParameterTypes));
        }

        public JObject GetPrimitiveType(PrimitiveTypeCode typeCode)
        {
            if (!Enum.IsDefined(typeof(PrimitiveTypeCode), typeCode))
            {
                throw new BadImageFormatException($"Unknown primitive type {typeCode}.");
            }

            return Object("kind", "primitive", "name", typeCode.ToString());
        }

        public JObject GetTypeFromDefinition(MetadataReader metadata, TypeDefinitionHandle handle, byte rawTypeKind)
        {
            var type = metadata.GetTypeDefinition(handle);
            string ns = metadata.GetString(type.Namespace);
            string name = metadata.GetString(type.Name);
            string fullName = type.IsNested
                ? FullName(metadata, type.GetDeclaringType()) + "+" + name
                : Qualify(ns, name);
            return Object("kind", "type", "namespace", ns, "name", name, "fullName", fullName,
                "scope", null, "signatureTypeKind", rawTypeKind,
                "evidence", Object("token", MetadataTokens.GetToken(handle)));
        }

        public JObject GetTypeFromReference(MetadataReader metadata, TypeReferenceHandle handle, byte rawTypeKind)
        {
            var type = metadata.GetTypeReference(handle);
            string ns = metadata.GetString(type.Namespace);
            string name = metadata.GetString(type.Name);
            JObject scope;
            JObject originalScope;
            string fullName;
            if (type.ResolutionScope.Kind == HandleKind.TypeReference)
            {
                var parent = GetTypeFromReference(metadata, (TypeReferenceHandle)type.ResolutionScope, 0);
                fullName = (string)parent["fullName"] + "+" + name;
                scope = parent["scope"] as JObject;
                originalScope = Object("kind", "typeReference", "parent", parent);
            }
            else
            {
                fullName = Qualify(ns, name);
                scope = Scope(metadata, type.ResolutionScope);
                originalScope = scope;
                if (type.ResolutionScope.Kind == HandleKind.AssemblyReference &&
                    IsCurrentAssembly(metadata, (AssemblyReferenceHandle)type.ResolutionScope))
                {
                    scope = null;
                }
            }

            return Object("kind", "type", "namespace", ns, "name", name, "fullName", fullName,
                "scope", scope, "signatureTypeKind", rawTypeKind,
                "evidence", Object("token", MetadataTokens.GetToken(handle), "resolutionScope", originalScope));
        }

        private static bool IsCurrentAssembly(MetadataReader metadata, AssemblyReferenceHandle handle)
        {
            if (!metadata.IsAssembly)
            {
                return false;
            }

            var reference = metadata.GetAssemblyReference(handle);
            var definition = metadata.GetAssemblyDefinition();
            if (metadata.GetString(reference.Name) != metadata.GetString(definition.Name) ||
                reference.Version != definition.Version ||
                metadata.GetString(reference.Culture) != metadata.GetString(definition.Culture) ||
                (reference.Flags & ~AssemblyFlags.PublicKey) != (definition.Flags & ~AssemblyFlags.PublicKey))
            {
                return false;
            }

            byte[] key = metadata.GetBlobBytes(definition.PublicKey);
            if ((reference.Flags & AssemblyFlags.PublicKey) == 0 && key.Length != 0)
            {
                // A reference normally carries the reversed final eight SHA-1 bytes
                // of the defining assembly's full public key.
                key = SHA1.HashData(key).TakeLast(8).Reverse().ToArray();
            }

            return key.SequenceEqual(metadata.GetBlobBytes(reference.PublicKeyOrToken));
        }

        internal JObject Type(EntityHandle handle)
        {
            if (handle.IsNil)
            {
                return null;
            }

            return handle.Kind switch
            {
                HandleKind.TypeDefinition => GetTypeFromDefinition(reader, (TypeDefinitionHandle)handle, 0),
                HandleKind.TypeReference => GetTypeFromReference(reader, (TypeReferenceHandle)handle, 0),
                HandleKind.TypeSpecification => GetTypeFromSpecification(reader, null, (TypeSpecificationHandle)handle, 0),
                _ => throw new BadImageFormatException($"Expected a type, got {handle.Kind}."),
            };
        }

        internal static string FullName(MetadataReader metadata, TypeDefinitionHandle handle)
        {
            var type = metadata.GetTypeDefinition(handle);
            string name = metadata.GetString(type.Name);
            return type.IsNested ? FullName(metadata, type.GetDeclaringType()) + "+" + name : Qualify(metadata.GetString(type.Namespace), name);
        }

        internal static string Qualify(string ns, string name) => ns.Length == 0 ? name : ns + "." + name;

        internal static JObject AssemblyReference(MetadataReader metadata, AssemblyReferenceHandle handle)
        {
            var reference = metadata.GetAssemblyReference(handle);
            return Object("name", metadata.GetString(reference.Name), "version", reference.Version.ToString(),
                "culture", metadata.GetString(reference.Culture), "flags", (int)reference.Flags,
                "publicKeyOrToken", Convert.ToHexString(metadata.GetBlobBytes(reference.PublicKeyOrToken)),
                "hashValue", Convert.ToHexString(metadata.GetBlobBytes(reference.HashValue)));
        }

        private static JObject Scope(MetadataReader metadata, EntityHandle handle)
        {
            if (handle.IsNil || handle.Kind == HandleKind.ModuleDefinition)
            {
                return null;
            }

            return handle.Kind switch
            {
                HandleKind.AssemblyReference => Object("kind", "assembly", "identity", AssemblyReference(metadata, (AssemblyReferenceHandle)handle)),
                HandleKind.ModuleReference => Object("kind", "module", "name", metadata.GetString(metadata.GetModuleReference((ModuleReferenceHandle)handle).Name)),
                _ => throw new BadImageFormatException($"Unsupported type reference scope: {handle.Kind}."),
            };
        }

        public JObject GetTypeFromSpecification(MetadataReader metadata, object context, TypeSpecificationHandle handle, byte rawTypeKind)
        {
            var blob = metadata.GetBlobReader(metadata.GetTypeSpecification(handle).Signature);
            var type = new SignatureDecoder<JObject, object>(this, metadata, context).DecodeType(ref blob);
            End(blob, "type specification");
            return type;
        }

        internal JObject MethodSignature(BlobHandle handle, bool property = false)
        {
            var blob = reader.GetBlobReader(handle);
            var signature = new SignatureDecoder<JObject, object>(this, reader, null).DecodeMethodSignature(ref blob);
            if (signature.Header.Kind != (property ? SignatureKind.Property : SignatureKind.Method))
            {
                throw new BadImageFormatException("Incorrect signature kind.");
            }

            End(blob, "method/property signature");
            return Signature(signature);
        }

        internal JObject FieldSignature(BlobHandle handle)
        {
            var blob = reader.GetBlobReader(handle);
            var type = new SignatureDecoder<JObject, object>(this, reader, null).DecodeFieldSignature(ref blob);
            End(blob, "field signature");
            return type;
        }

        internal static void End(BlobReader blob, string description)
        {
            if (blob.RemainingBytes != 0)
            {
                throw new BadImageFormatException($"Trailing bytes in {description}.");
            }
        }

        public JObject GetSZArrayType(JObject elementType) => Object("kind", "szArray", "elementType", elementType);

        public JObject GetArrayType(JObject elementType, ArrayShape shape) => Object("kind", "array", "elementType", elementType,
            "rank", shape.Rank, "sizes", new JArray(shape.Sizes), "lowerBounds", new JArray(shape.LowerBounds));

        public JObject GetPointerType(JObject elementType) => Object("kind", "pointer", "elementType", elementType);

        public JObject GetByReferenceType(JObject elementType) => Object("kind", "byReference", "elementType", elementType);

        public JObject GetPinnedType(JObject elementType) => Object("kind", "pinned", "elementType", elementType);

        public JObject GetGenericMethodParameter(object context, int index) => Object("kind", "genericMethodParameter", "index", index);

        public JObject GetGenericTypeParameter(object context, int index) => Object("kind", "genericTypeParameter", "index", index);

        public JObject GetGenericInstantiation(JObject genericType, ImmutableArray<JObject> typeArguments)
            => Object("kind", "genericInstantiation", "genericType", genericType, "arguments", new JArray(typeArguments));

        public JObject GetModifiedType(JObject modifier, JObject unmodifiedType, bool isRequired)
            => Object("kind", "modified", "required", isRequired, "modifier", modifier, "elementType", unmodifiedType);

        public JObject GetFunctionPointerType(MethodSignature<JObject> signature)
        {
            if (signature.Header.Kind != SignatureKind.Method)
            {
                throw new BadImageFormatException("Invalid function pointer signature kind.");
            }

            return Object("kind", "functionPointer", "signature", Signature(signature));
        }

        public JObject GetSystemType() => Object("kind", "systemType", "fullName", "System.Type");

        public bool IsSystemType(JObject type) => (string)type["fullName"] == "System.Type";

        public JObject GetTypeFromSerializedName(string name)
        {
            ParseTypeName(name);
            return Object("kind", "serializedType", "name", name);
        }

        internal IEnumerable<string> LocalSerializedTypes(string name) => LocalSerializedTypes(ParseTypeName(name));

        private IEnumerable<string> LocalSerializedTypes(TypeName type)
        {
            if (type.IsArray || type.IsPointer || type.IsByRef)
            {
                foreach (string name in LocalSerializedTypes(type.GetElementType()))
                {
                    yield return name;
                }
            }
            else if (type.IsConstructedGenericType)
            {
                foreach (var part in type.GetGenericArguments().Prepend(type.GetGenericTypeDefinition()))
                {
                    foreach (string name in LocalSerializedTypes(part))
                    {
                        yield return name;
                    }
                }
            }
            else if (type.AssemblyName == null || (reader.IsAssembly && type.AssemblyName.Name == reader.GetString(reader.GetAssemblyDefinition().Name)))
            {
                yield return type.FullName;
            }
        }

        private static TypeName ParseTypeName(string name)
        {
            if (name == null || !TypeName.TryParse(name.AsSpan(), out var type))
            {
                throw new BadImageFormatException($"Invalid serialized type name: {name}.");
            }

            return type;
        }

        public PrimitiveTypeCode GetUnderlyingEnumType(JObject type)
        {
            string name = (string)type["fullName"] ?? (string)type["name"];
            string localName = (string)type["fullName"] ?? ParseTypeName(name).FullName;
            string key = type.ToString(Newtonsoft.Json.Formatting.None);
            if (enumTypes.TryGetValue(key, out var cached))
            {
                return cached;
            }

            var definitions = Array.Empty<TypeDefinitionHandle>();
            if ((int?)type["evidence"]?["token"] is int token && MetadataTokens.Handle(token).Kind == HandleKind.TypeDefinition)
            {
                definitions = new[] { (TypeDefinitionHandle)MetadataTokens.Handle(token) };
            }
            else if (((string)type["kind"] == "serializedType" && LocalSerializedTypes(name).Contains(localName, StringComparer.Ordinal)) ||
                type["scope"]?.Type == JTokenType.Null)
            {
                definitions = definitionsByName.TryGetValue(localName, out var found) ? found : definitions;
            }
            PrimitiveTypeCode? underlying = null;
            foreach (var handle in definitions)
            {
                var definition = reader.GetTypeDefinition(handle);
                if ((string)Type(definition.BaseType)?["fullName"] != "System.Enum")
                {
                    throw new BadImageFormatException($"Custom attribute type {name} is not an enum.");
                }

                var fields = definition.GetFields().Where(h => reader.GetString(reader.GetFieldDefinition(h).Name) == "value__").ToArray();
                if (fields.Length != 1)
                {
                    throw new BadImageFormatException($"Enum {name} must have exactly one value__ field.");
                }

                var fieldType = FieldSignature(reader.GetFieldDefinition(fields[0]).Signature);
                if ((string)fieldType["kind"] != "primitive" ||
                    !Enum.TryParse((string)fieldType["name"], out PrimitiveTypeCode code) ||
                    !IsEnumInteger(code) || (underlying.HasValue && underlying != code))
                {
                    throw new BadImageFormatException($"Unsupported or ambiguous underlying type of enum {name}.");
                }

                underlying = code;
            }

            if (underlying.HasValue)
            {
                enumTypes.Add(key, underlying.Value);
                return underlying.Value;
            }

            // These framework enum definitions are fixed. Never guess Int32 for an
            // unresolved user enum: doing so can silently misdecode the rest of a blob.
            var frameworkEnums = new[]
            {
                typeof(AttributeTargets), typeof(System.Runtime.InteropServices.LayoutKind),
                typeof(System.Runtime.InteropServices.UnmanagedType), typeof(System.Runtime.InteropServices.CharSet),
                typeof(System.Runtime.InteropServices.CallingConvention), typeof(System.Runtime.InteropServices.VarEnum),
                typeof(System.Runtime.CompilerServices.MethodImplOptions),
                typeof(System.Runtime.CompilerServices.MethodCodeType), typeof(AssemblyNameFlags),
                typeof(System.Diagnostics.DebuggableAttribute.DebuggingModes),
            };
            if (frameworkEnums.Any(t => t.FullName == localName))
            {
                enumTypes.Add(key, PrimitiveTypeCode.Int32);
                return PrimitiveTypeCode.Int32;
            }

            throw new NotSupportedException($"Cannot decode external enum {name}; its underlying type is not available in this metadata.");
        }

        private static bool IsEnumInteger(PrimitiveTypeCode code) => code == PrimitiveTypeCode.SByte || code == PrimitiveTypeCode.Byte ||
            code == PrimitiveTypeCode.Int16 || code == PrimitiveTypeCode.UInt16 || code == PrimitiveTypeCode.Int32 ||
            code == PrimitiveTypeCode.UInt32 || code == PrimitiveTypeCode.Int64 || code == PrimitiveTypeCode.UInt64;

        internal static JToken Value(object value)
        {
            if (value == null)
            {
                return JValue.CreateNull();
            }

            if (value is ImmutableArray<CustomAttributeTypedArgument<JObject>> array)
            {
                return array.IsDefault ? JValue.CreateNull() : new JArray(array.Select(Argument));
            }

            if (value is CustomAttributeTypedArgument<JObject> argument)
            {
                return Argument(argument);
            }

            if (value is float single)
            {
                return Object("text", single.ToString("R", CultureInfo.InvariantCulture),
                    "bits", BitConverter.SingleToInt32Bits(single).ToString("X8", CultureInfo.InvariantCulture));
            }

            if (value is double number)
            {
                return Object("text", number.ToString("R", CultureInfo.InvariantCulture),
                    "bits", BitConverter.DoubleToInt64Bits(number).ToString("X16", CultureInfo.InvariantCulture));
            }

            return value is char character ? new JValue((int)character) : JToken.FromObject(value);
        }

        internal static JObject Argument(CustomAttributeTypedArgument<JObject> argument)
            => Object("type", argument.Type, "value", Value(argument.Value));
    }
}

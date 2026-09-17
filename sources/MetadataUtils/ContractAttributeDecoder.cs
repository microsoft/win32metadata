using System;
using System.Reflection.Metadata;
using Newtonsoft.Json.Linq;
using static MetadataUtils.ContractTypeProvider;

namespace MetadataUtils
{
    internal static class ContractAttributeDecoder
    {
        // Read the complete blob, including its boundary. The runtime's convenience
        // DecodeValue API does not expose the final cursor for trailing-byte checks.
        internal static JObject Read(MetadataReader metadata, ContractTypeProvider provider, BlobHandle value, JObject constructor)
        {
            var blob = metadata.GetBlobReader(value);
            if (blob.ReadUInt16() != 1)
            {
                throw new BadImageFormatException("Invalid custom attribute prolog.");
            }

            var fixedArguments = new JArray();
            foreach (JObject type in constructor["signature"]["parameterTypes"])
            {
                fixedArguments.Add(Argument(ref blob, provider, type));
            }

            var namedArguments = new JArray();
            int namedCount = blob.ReadUInt16();
            for (int i = 0; i < namedCount; i++)
            {
                namedArguments.Add(NamedArgument(ref blob, provider));
            }

            End(blob, "custom attribute");
            return Object("constructor", constructor, "fixedArguments", fixedArguments,
                "namedArguments", namedArguments);
        }

        internal static JArray ReadPermissionSet(MetadataReader metadata, ContractTypeProvider provider, BlobHandle handle)
        {
            var blob = metadata.GetBlobReader(handle);
            if (blob.ReadByte() != '.')
            {
                throw new NotSupportedException("Only binary declarative security permission sets are supported.");
            }

            int count = blob.ReadCompressedInteger();
            var permissions = new JArray();
            for (int i = 0; i < count; i++)
            {
                string type = blob.ReadSerializedString() ?? throw new BadImageFormatException("Null security attribute type.");
                int size = blob.ReadCompressedInteger();
                if (size < 0 || size > blob.RemainingBytes)
                {
                    throw new BadImageFormatException("Invalid permission attribute size.");
                }

                int endOffset = blob.Offset + size;
                int namedCount = blob.ReadCompressedInteger();
                var arguments = new JArray();
                for (int j = 0; j < namedCount; j++)
                {
                    arguments.Add(NamedArgument(ref blob, provider));
                }

                if (blob.Offset != endOffset)
                {
                    throw new BadImageFormatException("Incorrect permission attribute boundary.");
                }

                permissions.Add(Object("type", provider.GetTypeFromSerializedName(type), "namedArguments", arguments));
            }

            End(blob, "permission set");
            return WinmdContractSnapshot.Sort(permissions);
        }

        private static JObject NamedArgument(ref BlobReader blob, ContractTypeProvider provider)
        {
            byte kind = blob.ReadByte();
            if (kind != 0x53 && kind != 0x54)
            {
                throw new BadImageFormatException($"Invalid custom attribute named argument kind: 0x{kind:X2}.");
            }

            JObject type = EncodedType(ref blob, provider);
            string name = blob.ReadSerializedString() ?? throw new BadImageFormatException("Null named argument name.");
            JObject argument = Argument(ref blob, provider, type);
            argument.AddFirst(new JProperty("name", name));
            argument.AddFirst(new JProperty("kind", kind == 0x53 ? "field" : "property"));
            return argument;
        }

        private static JObject EncodedType(ref BlobReader blob, ContractTypeProvider provider)
        {
            byte code = blob.ReadByte();
            if (code == 0x50)
            {
                return provider.GetSystemType();
            }

            if (code == 0x51)
            {
                return provider.GetPrimitiveType(PrimitiveTypeCode.Object);
            }

            if (code == 0x55)
            {
                string name = blob.ReadSerializedString() ?? throw new BadImageFormatException("Null custom attribute enum type.");
                return provider.GetTypeFromSerializedName(name);
            }

            if (code == 0x1d)
            {
                return provider.GetSZArrayType(EncodedType(ref blob, provider));
            }

            if (code < 0x02 || code > 0x0e)
            {
                throw new BadImageFormatException($"Invalid custom attribute element type: 0x{code:X2}.");
            }

            return provider.GetPrimitiveType((PrimitiveTypeCode)code);
        }

        private static JObject Argument(ref BlobReader blob, ContractTypeProvider provider, JObject type)
        {
            string kind = (string)type["kind"];
            JToken value;
            if (kind == "szArray")
            {
                int count = blob.ReadInt32();
                if (count == -1)
                {
                    value = JValue.CreateNull();
                }
                else
                {
                    if (count < 0 || count > blob.RemainingBytes)
                    {
                        throw new BadImageFormatException("Invalid custom attribute array length.");
                    }

                    var array = new JArray();
                    for (int i = 0; i < count; i++)
                    {
                        array.Add(Argument(ref blob, provider, (JObject)type["elementType"]));
                    }

                    value = array;
                }
            }
            else if (provider.IsSystemType(type))
            {
                string name = blob.ReadSerializedString();
                value = name == null ? JValue.CreateNull() : provider.GetTypeFromSerializedName(name);
            }
            else if (kind == "type" || kind == "serializedType")
            {
                value = Scalar(ref blob, provider.GetUnderlyingEnumType(type));
            }
            else if (kind == "primitive" && Enum.TryParse((string)type["name"], out PrimitiveTypeCode code))
            {
                value = code == PrimitiveTypeCode.Object
                    ? Argument(ref blob, provider, EncodedType(ref blob, provider))
                    : Scalar(ref blob, code);
            }
            else
            {
                throw new BadImageFormatException($"Invalid custom attribute argument type: {type}.");
            }

            return Object("type", type, "value", value);
        }

        private static JToken Scalar(ref BlobReader blob, PrimitiveTypeCode code)
        {
            switch (code)
            {
                case PrimitiveTypeCode.Boolean:
                    byte boolean = blob.ReadByte();
                    if (boolean > 1)
                    {
                        throw new BadImageFormatException("Invalid custom attribute Boolean.");
                    }

                    return new JValue(boolean == 1);
                case PrimitiveTypeCode.Char: return new JValue((int)blob.ReadUInt16());
                case PrimitiveTypeCode.SByte: return new JValue(blob.ReadSByte());
                case PrimitiveTypeCode.Byte: return new JValue(blob.ReadByte());
                case PrimitiveTypeCode.Int16: return new JValue(blob.ReadInt16());
                case PrimitiveTypeCode.UInt16: return new JValue(blob.ReadUInt16());
                case PrimitiveTypeCode.Int32: return new JValue(blob.ReadInt32());
                case PrimitiveTypeCode.UInt32: return new JValue(blob.ReadUInt32());
                case PrimitiveTypeCode.Int64: return new JValue(blob.ReadInt64());
                case PrimitiveTypeCode.UInt64: return new JValue(blob.ReadUInt64());
                case PrimitiveTypeCode.Single: return Value(blob.ReadSingle());
                case PrimitiveTypeCode.Double: return Value(blob.ReadDouble());
                case PrimitiveTypeCode.String: return Value(blob.ReadSerializedString());
                default: throw new BadImageFormatException($"Invalid custom attribute scalar type: {code}.");
            }
        }
    }
}

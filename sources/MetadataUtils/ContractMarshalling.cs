using System;
using System.Reflection.Metadata;
using Newtonsoft.Json.Linq;
using static MetadataUtils.ContractTypeProvider;

namespace MetadataUtils
{
    internal static class ContractMarshalling
    {
        internal static JObject Read(MetadataReader metadata, BlobHandle handle)
        {
            if (handle.IsNil)
            {
                return null;
            }

            var blob = metadata.GetBlobReader(handle);
            byte code = blob.ReadByte();
            var result = Object("nativeType", code);
            switch (code)
            {
                case 0x17: // FIXEDSYSSTRING
                    result.Add("size", Compressed(ref blob));
                    break;
                case 0x1d: // SAFEARRAY
                    if (blob.RemainingBytes > 0)
                    {
                        result.Add("variantType", Compressed(ref blob));
                    }

                    if (blob.RemainingBytes > 0)
                    {
                        result.Add("userDefinedSubType", blob.ReadSerializedString());
                    }

                    break;
                case 0x1e: // FIXEDARRAY
                    result.Add("size", Compressed(ref blob));
                    if (blob.RemainingBytes > 0)
                    {
                        result.Add("elementType", NativeType(ref blob));
                    }

                    break;
                case 0x19: // IUNKNOWN
                case 0x1a: // IDISPATCH
                case 0x1c: // INTF
                    if (blob.RemainingBytes > 0)
                    {
                        result.Add("iidParameterIndex", Compressed(ref blob));
                    }

                    break;
                case 0x2a: // ARRAY; omitted suffixes are different from explicit zeroes.
                    if (blob.RemainingBytes > 0)
                    {
                        result.Add("elementType", NativeType(ref blob));
                    }

                    if (blob.RemainingBytes > 0)
                    {
                        result.Add("sizeParameterIndex", Compressed(ref blob));
                    }

                    if (blob.RemainingBytes > 0)
                    {
                        result.Add("size", Compressed(ref blob));
                    }

                    if (blob.RemainingBytes > 0)
                    {
                        result.Add("flags", Compressed(ref blob));
                    }

                    break;
                case 0x2c: // CUSTOMMARSHALER
                    result.Add("guid", blob.ReadSerializedString());
                    result.Add("nativeTypeName", blob.ReadSerializedString());
                    result.Add("managedTypeName", blob.ReadSerializedString());
                    result.Add("cookie", blob.ReadSerializedString());
                    break;
                default:
                    ValidateSimple(code);
                    break;
            }

            if (blob.RemainingBytes != 0)
            {
                throw new BadImageFormatException($"Trailing bytes in native marshaling descriptor (0x{code:X2}).");
            }

            // FieldMarshal blobs contain no metadata indices. Keep their exact bytes
            // as semantic facts as well as the decoded, conveniently queryable form.
            result.Add("descriptor", Convert.ToHexString(metadata.GetBlobBytes(handle)));
            return result;
        }

        private static int NativeType(ref BlobReader blob)
        {
            byte code = blob.ReadByte();
            if (code != 0x50)
            {
                ValidateSimple(code);
            }

            return code;
        }

        private static void ValidateSimple(byte code)
        {
            switch (code)
            {
                case 0x02: case 0x03: case 0x04: case 0x05: case 0x06:
                case 0x07: case 0x08: case 0x09: case 0x0a: case 0x0b:
                case 0x0c: case 0x0f: case 0x13: case 0x14: case 0x15:
                case 0x16: case 0x18: case 0x19: case 0x1a: case 0x1b:
                case 0x1c: case 0x1f: case 0x20: case 0x22: case 0x23:
                case 0x24: case 0x25: case 0x26: case 0x28: case 0x2b:
                case 0x2d: case 0x2e: case 0x2f: case 0x30:
                    return;
                default:
                    throw new NotSupportedException($"Unsupported native marshaling type 0x{code:X2}.");
            }
        }

        private static int Compressed(ref BlobReader blob)
        {
            int result = blob.ReadCompressedInteger();
            if (result < 0)
            {
                throw new BadImageFormatException("Invalid compressed integer in marshaling descriptor.");
            }

            return result;
        }
    }
}

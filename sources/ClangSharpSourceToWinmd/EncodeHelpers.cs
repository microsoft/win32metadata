using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using Microsoft.CodeAnalysis;

namespace ClangSharpSourceToWinmd
{
    public static class EncodeHelpers
    {
        public static void EncodeConstant(this LiteralEncoder encoder, object constant)
        {
            encoder.Scalar().Constant(constant);
        }

        public static void TypedConstant(this LiteralEncoder encoder, TypedConstant constant)
        {
            switch (constant.Kind)
            {
                case TypedConstantKind.Primitive:
                    encoder.Scalar().Constant(constant.Value);
                    break;
                case TypedConstantKind.Enum:
                    encoder.Scalar().Constant(constant.Value);
                    break;

                // This looks more correct, but the code above matches what the C# compiler produces
                //  encoder.TaggedScalar(
                //      type => type.Enum(constant.Type.ToString()),
                //      scalar => scalar.Constant(constant.Value)
                //);

                case TypedConstantKind.Type:
                    encoder.Scalar().SystemType(constant.Type.ToString());
                    break;
                case TypedConstantKind.Array:
                    {
                        LiteralsEncoder arrayEncoder = encoder.Vector().Count(constant.Values.Length);
                        foreach (var arrayConstant in constant.Values)
                        {
                            arrayEncoder.AddLiteral().TypedConstant(arrayConstant);
                        }
                        break;
                    }
            }

        }

        public static void EncodeSpecialType(this SignatureTypeEncoder typeEncoder, SpecialType specialType)
        {
            switch (specialType)
            {
                case SpecialType.System_Boolean:
                    typeEncoder.Boolean();
                    break;
                case SpecialType.System_SByte:
                    typeEncoder.SByte();
                    break;
                case SpecialType.System_Byte:
                    typeEncoder.Byte();
                    break;
                case SpecialType.System_Int16:
                    typeEncoder.Int16();
                    break;
                case SpecialType.System_Int32:
                    typeEncoder.Int32();
                    break;
                case SpecialType.System_Int64:
                    typeEncoder.Int64();
                    break;
                case SpecialType.System_UInt16:
                    typeEncoder.UInt16();
                    break;
                case SpecialType.System_UInt32:
                    typeEncoder.UInt32();
                    break;
                case SpecialType.System_UInt64:
                    typeEncoder.UInt64();
                    break;
                case SpecialType.System_Single:
                    typeEncoder.Single();
                    break;
                case SpecialType.System_Double:
                    typeEncoder.Double();
                    break;
                case SpecialType.System_Char:
                    typeEncoder.Char();
                    break;
                case SpecialType.System_String:
                    typeEncoder.String();
                    break;
                case SpecialType.System_Object:
                    typeEncoder.Object();
                    break;
                case SpecialType.System_IntPtr:
                    typeEncoder.IntPtr();
                    break;
                case SpecialType.System_UIntPtr:
                    typeEncoder.UIntPtr();
                    break;
                default:
                    throw new NotImplementedException();
            }

            // TODO: handle C# interface mappings for special types
        }

        public static void NamedArgumentType(this NamedArgumentTypeEncoder encoder, INamedTypeSymbol attributeType, string field)
        {
            var fieldMembers = attributeType.GetMembers(field);
            var fieldSymbol = fieldMembers.First() as IFieldSymbol;

            if (fieldSymbol.Type.SpecialType == SpecialType.System_Object)
            {
                encoder.Object();
            }
            else if (fieldSymbol.Type.SpecialType == SpecialType.System_Array)
            {
                // TODO array type encoder
                encoder.SZArray();
            }
            else
            {
                encoder.ScalarType().CustomElementType(fieldSymbol);
            }
        }

        public static void CustomElementType(this CustomAttributeElementTypeEncoder typeEncoder, IFieldSymbol field)
        {
            switch (field.Type.SpecialType)
            {
                case SpecialType.System_Boolean:
                    typeEncoder.Boolean();
                    break;
                case SpecialType.System_Byte:
                    typeEncoder.Byte();
                    break;
                case SpecialType.System_Int16:
                    typeEncoder.Int16();
                    break;
                case SpecialType.System_Int32:
                    typeEncoder.Int32();
                    break;
                case SpecialType.System_Int64:
                    typeEncoder.Int64();
                    break;
                case SpecialType.System_UInt16:
                    typeEncoder.UInt16();
                    break;
                case SpecialType.System_UInt32:
                    typeEncoder.UInt32();
                    break;
                case SpecialType.System_UInt64:
                    typeEncoder.UInt64();
                    break;
                case SpecialType.System_Single:
                    typeEncoder.Single();
                    break;
                case SpecialType.System_Double:
                    typeEncoder.Double();
                    break;
                case SpecialType.System_Char:
                    typeEncoder.Char();
                    break;
                case SpecialType.System_String:
                    typeEncoder.String();
                    break;
                case SpecialType.System_Enum:
                    typeEncoder.Enum(field.Type.ToString());
                    break;
                case SpecialType.System_SByte:
                    typeEncoder.SByte();
                    break;
                default:
                    throw new NotImplementedException();
            }
        }

        public static void NamedArguments(
            this CustomAttributeNamedArgumentsEncoder argumentsEncoder,
            INamedTypeSymbol attributeType,
            IList<KeyValuePair<string, TypedConstant>> namedArguments)
        {
            var encoder = argumentsEncoder.Count(namedArguments.Count);
            foreach (var argument in namedArguments)
            {
                encoder.AddArgument(
                    true,
                    type => type.NamedArgumentType(attributeType, argument.Key),
                    name => name.Name(argument.Key),
                    literal => literal.TypedConstant(argument.Value)
                );
            }
        }

        public static void ConstArguments(this FixedArgumentsEncoder argumentsEncoder, IList<object> arguments)
        {
            foreach (var argument in arguments)
            {
                argumentsEncoder.AddArgument().Scalar().Constant(argument);
            }
        }

        public static void FixedArguments(this FixedArgumentsEncoder argumentsEncoder, IList<TypedConstant> arguments)
        {
            foreach (var argument in arguments)
            {
                argumentsEncoder.AddArgument().TypedConstant(argument);
            }
        }
    }
}

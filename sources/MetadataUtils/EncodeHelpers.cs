using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace MetadataUtils
{
    public static class EncodeHelpers
    {
        public const string AttributeToRemoveSuffix = "__remove";

        private static readonly System.Text.RegularExpressions.Regex RemappedParmRegex = new System.Text.RegularExpressions.Regex(@"(?:\[([^\]]*)\])?(?:\s*(\w+\**)(?:\s+(\w+))?)?");
        private static readonly System.Text.RegularExpressions.Regex AttributeRegex = new System.Text.RegularExpressions.Regex(@"(-?\w+)(\(.+\)$)?");

        public static bool DecodeRemap(string remappedTo, out List<AttributeSyntax> listAttributes, out string newType, out string newName)
        {
            listAttributes = null;
            newType = newName = null;

            foreach (System.Text.RegularExpressions.Match match in RemappedParmRegex.Matches(remappedTo))
            {
                if (match.Groups[1].Success)
                {
                    var attributeText = match.Groups[1].Value;
                    var parseAttrMatch = AttributeRegex.Match(attributeText);
                    if (parseAttrMatch.Success)
                    {
                        var attrName = parseAttrMatch.Groups[1].Value;

                        // If it starts with '-' this means the .rsp is saying to remove it.
                        // Change it to a name we will know to remove later
                        if (attrName.StartsWith('-'))
                        {
                            attrName = attrName.Substring(1) + AttributeToRemoveSuffix;
                        }

                        var attrArgs = parseAttrMatch.Groups[2].Value;

                        var attrNameNode = SyntaxFactory.ParseName(attrName);
                        var argsNode = !string.IsNullOrEmpty(attrArgs) ? SyntaxFactory.ParseAttributeArgumentList(attrArgs) : null;
                        var finalAttrNode = SyntaxFactory.Attribute(attrNameNode, argsNode);

                        if (listAttributes == null)
                        {
                            listAttributes = new List<AttributeSyntax>();
                        }

                        listAttributes.Add(finalAttrNode);
                    }
                }

                if (match.Groups[2].Success)
                {
                    newType = match.Groups[2].Value;
                }

                if (match.Groups[3].Success)
                {
                    newName = match.Groups[3].Value;
                }
            }

            return listAttributes != null || newType != null || newName != null;
        }

        public static void EncodeConstant(this LiteralEncoder encoder, object constant)
        {
            encoder.Scalar().Constant(constant);
        }

        public static void SplitType(string fullType, out string typeOnly, out string pointers)
        {
            int starIndex = fullType.IndexOf('*');
            if (starIndex != -1)
            {
                typeOnly = fullType.Substring(0, starIndex);
                pointers = fullType.Substring(starIndex);
            }
            else
            {
                typeOnly = fullType;
                pointers = string.Empty;
            }
        }

        public static string RemoveQuotes(string text)
        {
            if (text.Length >= 2 && text[0] == '\"' && text[text.Length - 1] == '\"')
            {
                return text.Substring(1, text.Length - 2);
            }

            return text;
        }

        public static uint ParseHex(string text)
        {
            if (text.StartsWith("0x", StringComparison.OrdinalIgnoreCase))
            {
                text = text.Substring(2);
            }

            if (char.ToUpperInvariant(text[text.Length - 1]) == 'L')
            {
                text = text.Substring(0, text.Length - 1);
            }

            return uint.Parse(text, System.Globalization.NumberStyles.HexNumber);
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
            var propertySymbol = fieldMembers.First() as IPropertySymbol;

            if (fieldSymbol != null)
            {
                if (fieldSymbol.Type.SpecialType == SpecialType.System_Object)
                {
                    encoder.Object();
                }
                else if (fieldSymbol.Type.SpecialType == SpecialType.System_Array)
                {
                    // TODO array type encoder
                    encoder.SZArray();
                }
                else if (fieldSymbol.Type.TypeKind == TypeKind.Enum)
                {
                    encoder.ScalarType().Enum(fieldSymbol.Type.ToString());
                }
                else
                {
                    encoder.ScalarType().CustomElementType(fieldSymbol);
                }
            }
            else if (propertySymbol != null)
            {
                if (propertySymbol.Type.SpecialType == SpecialType.System_Object)
                {
                    encoder.Object();
                }
                else if (propertySymbol.Type.SpecialType == SpecialType.System_Array)
                {
                    // TODO array type encoder
                    encoder.SZArray();
                }
                else if (propertySymbol.Type.TypeKind == TypeKind.Enum)
                {
                    encoder.ScalarType().Enum(propertySymbol.Type.ToString());
                }
                else
                {
                    encoder.ScalarType().CustomElementType(propertySymbol);
                }
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

        public static void CustomElementType(this CustomAttributeElementTypeEncoder typeEncoder, IPropertySymbol property)
        {
            switch (property.Type.SpecialType)
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
                    typeEncoder.Enum(property.Type.ToString());
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

        public static AttributeListSyntax ConvertGuidToAttributeList(Guid guid)
        {
            // Outputs in format: {0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}
            string formattedGuid = guid.ToString("x");

            // Get rid of leading { and trailing }}
            formattedGuid = formattedGuid.Substring(1, formattedGuid.Length - 3);
            // There's one more { we need to get rid of
            formattedGuid = formattedGuid.Replace("{", string.Empty);
            string args = $"({formattedGuid})";
            return
                SyntaxFactory.AttributeList(
                    SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                        SyntaxFactory.Attribute(
                            SyntaxFactory.ParseName("Windows.Win32.Foundation.Metadata.Guid"),
                            SyntaxFactory.ParseAttributeArgumentList(args))));
        }
    }
}

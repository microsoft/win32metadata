using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace PartitionUtilsLib
{
    public static class SyntaxUtils
    {
        public static bool IsEmptyStruct(StructDeclarationSyntax node)
        {
            bool hasNoImportantAttributes =
                node.AttributeLists.Count == 0 ||
                (node.AttributeLists.Count == 1 && node.AttributeLists[0].Attributes[0].Name.ToString() == "SupportedOSPlatform");

            return node.Members.Count == 0 && hasNoImportantAttributes;
        }

        public static string GetNativeTypeNameFromAttributesLists(SyntaxList<AttributeListSyntax> attributeLists)
        {
            foreach (var attrList in attributeLists)
            {
                foreach (var attr in attrList.Attributes)
                {
                    if (attr.Name.ToString() == "NativeTypeName")
                    {
                        string nativeType = attr.ArgumentList.Arguments[0].ToString();
                        return EncodeHelpers.RemoveQuotes(nativeType);
                    }
                }
            }

            return null;
        }

        public static string GetFullName(SyntaxNode node)
        {
            string parentName = null;
            string ret = null;
            if (node is DelegateDeclarationSyntax delNode)
            {
                parentName = GetFullName(delNode.Parent);
                ret = delNode.Identifier.Text;
            }
            else if (node is ClassDeclarationSyntax)
            {
                return string.Empty;
            }
            else if (node is StructDeclarationSyntax structNode)
            {
                parentName = GetFullName(structNode.Parent);
                ret = structNode.Identifier.Text;
            }
            else if (node is MethodDeclarationSyntax methodNode)
            {
                parentName = GetFullName(methodNode.Parent);
                ret = methodNode.Identifier.Text;
            }
            else if (node is ParameterSyntax paramNode)
            {
                parentName = GetFullName(paramNode.Parent.Parent);
                ret = paramNode.Identifier.Text;
            }
            else if (node is VariableDeclaratorSyntax varNode)
            {
                parentName = GetFullName(varNode.Parent.Parent.Parent);
                ret = varNode.Identifier.Text;
            }
            else if (node is FieldDeclarationSyntax fieldNode)
            {
                ret = GetFullName(fieldNode.Declaration.Variables.First());
            }
            else
            {
                // Do nothing for everything else
            }

            if (!string.IsNullOrEmpty(parentName) && !string.IsNullOrEmpty(ret))
            {
                ret = $"{parentName}::{ret}";
            }

            return ret;
        }
    }
}

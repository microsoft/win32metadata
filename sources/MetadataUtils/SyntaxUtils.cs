using System;
using System.Linq;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace MetadataUtils
{
    public static class SyntaxUtils
    {
        private static readonly Regex vtableSlotRegex = new Regex(@"\(IntPtr\)\(lpVtbl\[(\d+)\]\)");

        public static bool IsTreeEmpty(SyntaxTree tree)
        {
            foreach (var node in tree.GetRoot().DescendantNodes())
            {
                if (node is StructDeclarationSyntax structNode && !IsEmptyStruct(structNode))
                {
                    return false;
                }

                if (node is ClassDeclarationSyntax classNode && !IsEmptyClass(classNode))
                {
                    return false;
                }

                if (node is DelegateDeclarationSyntax || node is EnumDeclarationSyntax)
                {
                    return false;
                }
            }

            return true;
        }

        public static bool IsEmptyClass(ClassDeclarationSyntax node)
        {
            return node.Members.Count == 0;
        }

        public static bool IsEmptyStruct(StructDeclarationSyntax node)
        {
            bool hasNoImportantAttributes =
                node.AttributeLists.Count == 0 ||
                (node.AttributeLists.Count == 1 && node.AttributeLists[0].Attributes[0].Name.ToString() == "SupportedOSPlatform");

            return node.Members.Count == 0 && hasNoImportantAttributes;
        }

        public static SyntaxList<AttributeListSyntax> RemoveAttribute(SyntaxList<AttributeListSyntax> attributeLists, string name)
        {
            foreach (var attrList in attributeLists.ToArray())
            {
                foreach (var attr in attrList.Attributes)
                {
                    if (attr.Name.ToString() == name)
                    {
                        attributeLists = attributeLists.Remove(attrList);

                        var newAttrList = attrList.RemoveNode(attr, SyntaxRemoveOptions.KeepNoTrivia);
                        if (newAttrList.Attributes.Count != 0)
                        {
                            attributeLists = attributeLists.Add(newAttrList);
                        }
                    }
                }
            }

            return attributeLists;
        }

        public static AttributeSyntax GetAttribute(SyntaxList<AttributeListSyntax> attributeLists, string name)
        {
            foreach (var attrList in attributeLists)
            {
                foreach (var attr in attrList.Attributes)
                {
                    if (attr.Name.ToString() == name)
                    {
                        return attr;
                    }
                }
            }

            return null;
        }

        public static string GetNativeTypeNameFromAttributesLists(SyntaxList<AttributeListSyntax> attributeLists)
        {
            var attr = GetAttribute(attributeLists, "NativeTypeName");
            if (attr != null)
            {
                string nativeType = attr.ArgumentList.Arguments[0].ToString();
                string ret = EncodeHelpers.RemoveQuotes(nativeType);
                if (ret == "INT_PTR")
                {
                    ret = "IntPtr";
                }

                return ret;
            }

            return null;
        }

        public static string GetFullSignature(SyntaxNode node)
        {
            return node.ToString();
        }

        public static string GetEnclosingNamespace(SyntaxNode node)
        {
            for (SyntaxNode currentNode = node; currentNode != null; currentNode = currentNode.Parent)
            {
                if (currentNode is NamespaceDeclarationSyntax nsNode)
                {
                    return nsNode.Name.ToString();
                }
            }

            return null;
        }

        public static string GetFullName(SyntaxNode node, bool includeNamespace)
        {
            string parentName = null;
            string ret = null;
            if (node is DelegateDeclarationSyntax delNode)
            {
                parentName = GetFullName(delNode.Parent, includeNamespace);
                ret = delNode.Identifier.Text;
            }
            else if (node is ClassDeclarationSyntax)
            {
                return string.Empty;
            }
            else if (node is StructDeclarationSyntax structNode)
            {
                parentName = GetFullName(structNode.Parent, includeNamespace);
                ret = structNode.Identifier.Text;
            }
            else if (node is EnumDeclarationSyntax enumNode)
            {
                parentName = GetFullName(enumNode.Parent, includeNamespace);
                ret = enumNode.Identifier.Text;
            }
            else if (node is MethodDeclarationSyntax methodNode)
            {
                if (methodNode.Parent.Parent is NamespaceDeclarationSyntax && includeNamespace)
                {
                    parentName = GetFullName(methodNode.Parent.Parent, includeNamespace);
                }
                else
                {
                    parentName = GetFullName(methodNode.Parent, includeNamespace);
                }

                ret = methodNode.Identifier.Text;
            }
            else if (node is ParameterSyntax paramNode)
            {
                parentName = GetFullName(paramNode.Parent.Parent, includeNamespace);
                ret = paramNode.Identifier.Text;
            }
            else if (node is VariableDeclaratorSyntax varNode)
            {
                parentName = GetFullName(varNode.Parent.Parent.Parent, includeNamespace);
                ret = varNode.Identifier.Text;
            }
            else if (node is FieldDeclarationSyntax fieldNode)
            {
                ret = GetFullName(fieldNode.Declaration.Variables.First(), includeNamespace);
            }
            else if (node is NamespaceDeclarationSyntax namespaceNode && includeNamespace)
            {
                ret = namespaceNode.Name.ToString();
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

        public static string GetFullName(SyntaxNode node)
        {
            return GetFullName(node, false);
        }

        public static int GetVtableSlotFromMethodBody(MethodDeclarationSyntax method)
        {
            var match = vtableSlotRegex.Match(method.Body.ToString());
            if (match.Success)
            {
                return int.Parse(match.Groups[1].Value);
            }

            throw new InvalidOperationException($"Could not find vtable entry for {method.Parent}.{method.Identifier.ValueText}");
        }
    }
}

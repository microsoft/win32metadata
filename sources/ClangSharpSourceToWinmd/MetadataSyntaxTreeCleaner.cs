using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace ClangSharpSourceToWinmd
{
    public static class MetadataSyntaxTreeCleaner
    {
        public static SyntaxTree CleanSyntaxTree(SyntaxTree tree)
        {
            TreeRewriter treeRewriter = new TreeRewriter();
            var newRoot = (CSharpSyntaxNode)treeRewriter.Visit(tree.GetRoot());
            return CSharpSyntaxTree.Create(newRoot);
        }

        private class TreeRewriter : CSharpSyntaxRewriter
        {
            private static readonly System.Text.RegularExpressions.Regex elementCountRegex = new System.Text.RegularExpressions.Regex(@"(?:elementCount|byteCount)\(([^\)]+)\)");

            private HashSet<SyntaxNode> nodesWithMarshalAs = new HashSet<SyntaxNode>();

            public override SyntaxNode VisitAttributeList(AttributeListSyntax node)
            {
                var firstAttr = node.Attributes[0];
                var attrName = firstAttr.Name.ToString();

                switch (attrName)
                {
                    case "NativeTypeName":
                    {
                        var ret = this.ProcessNativeTypeNameAttr(firstAttr, out bool marshalAs);
                        if (marshalAs)
                        {
                            this.nodesWithMarshalAs.Add(node.Parent);
                        }

                        return ret == null ? node : ret;
                    }

                    case "CppAttributeList":
                    {
                        return this.CreateAttributeListForSal(node);
                    }
                }

                return base.VisitAttributeList(node);
            }

            private string ConvertTypeToMarshalAsType(string nativeTypeName, out bool isConst, out bool isNullTerminated, out bool isNullNullTerminated)
            {
                string marshalAsType = null;
                isConst = false;
                isNullTerminated = false;
                isNullNullTerminated = false;

                switch (nativeTypeName)
                {
                    case "BOOL":
                        marshalAsType = "Bool";
                        break;

                    case "PCHAR":
                    case "LPCH":
                    case "PCH":
                        marshalAsType = "LPStr";
                        break;

                    case "LPCCH":
                    case "PCCH":
                        marshalAsType = "LPStr";
                        isConst = true;
                        break;

                    case "NPSTR":
                    case "LPSTR":
                    case "PSTR":
                        marshalAsType = "LPStr";
                        isNullTerminated = true;
                        break;

                    case "LPCSTR":
                    case "PCSTR":
                        marshalAsType = "LPStr";
                        isConst = true;
                        isNullTerminated = true;
                        break;

                    case "PZZSTR":
                        marshalAsType = "LPStr";
                        isNullNullTerminated = true;
                        break;

                    case "CPZZSTR":
                        marshalAsType = "LPStr";
                        isConst = true;
                        isNullNullTerminated = true;
                        break;

                    case "PWCHAR":
                    case "LPWCH":
                    case "PWCH":
                        marshalAsType = "LPWStr";
                        break;

                    case "NWPSTR":
                    case "LPWSTR":
                    case "PWSTR":
                        marshalAsType = "LPWStr";
                        isNullTerminated = true;
                        break;

                    case "LPCWSTR":
                    case "PCWSTR":
                    case "LPCWCH":
                    case "const WCHAR *":
                        marshalAsType = "LPWStr";
                        isNullTerminated = true;
                        isConst = true;
                        break;

                    case "PZZWSTR":
                        marshalAsType = "LPWStr";
                        isNullNullTerminated = true;
                        break;

                    case "PCZZWSTR":
                        marshalAsType = "LPWStr";
                        isConst = true;
                        isNullNullTerminated = true;
                        break;

                    default:
                        if (nativeTypeName.StartsWith("const "))
                        {
                            isConst = true;
                        }

                        break;
                }

                return marshalAsType;
            }

            private bool AddNativeTypeInfoAttribute(string nativeTypeName, List<AttributeSyntax> attrsList)
            {
                if (string.IsNullOrWhiteSpace(nativeTypeName))
                {
                    return false;
                }

                var marshalAsType = ConvertTypeToMarshalAsType(nativeTypeName, out bool isConst, out bool isNullTerminated, out bool isNullNullTerminated);

                if (isConst)
                {
                    attrsList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("Const")));
                }

                if (marshalAsType != null)
                {
                    StringBuilder attrArgs = new StringBuilder($"(UnmanagedType.{marshalAsType}");

                    if (isNullTerminated)
                    {
                        attrArgs.Append(", IsNullTerminated = true");
                    }

                    if (isNullNullTerminated)
                    {
                        attrArgs.Append(", IsNullNullTerminated = true");
                    }

                    attrArgs.Append(")");

                    var attrName = SyntaxFactory.ParseName("NativeTypeInfo");
                    var args = SyntaxFactory.ParseAttributeArgumentList(attrArgs.ToString());
                    var finalAttr = SyntaxFactory.Attribute(attrName, args);
                    attrsList.Add(finalAttr);

                    return true;
                }

                return false;
            }

            private SyntaxNode ProcessNativeTypeNameAttr(AttributeSyntax nativeTypeNameAttr, out bool marshalAs)
            {
                string nativeType = nativeTypeNameAttr.ArgumentList.Arguments[0].ToString();
                nativeType = nativeType.Substring(1, nativeType.Length - 2);
                List<AttributeSyntax> attributeNodes = new List<AttributeSyntax>();
                marshalAs = this.AddNativeTypeInfoAttribute(nativeType, attributeNodes);
                if (attributeNodes.Count == 0)
                {
                    return null;
                }

                var ret = SyntaxFactory.AttributeList(SyntaxFactory.SeparatedList(attributeNodes));
                return ret;
            }


            private SyntaxNode CreateAttributeListForSal(AttributeListSyntax cppAttrList)
            {
                ParameterSyntax paramNode = (ParameterSyntax)cppAttrList.Parent;
                bool marshalAsAdded = this.nodesWithMarshalAs.Contains(paramNode);

                AttributeSyntax cppAttr = cppAttrList.Attributes[0];
                List<AttributeSyntax> attributesList = new List<AttributeSyntax>();

                string salText = cppAttr.ArgumentList.Arguments[0].ToString();
                salText = salText.Substring(1, salText.Length - 2);

                string marshalAsParams = null;
                bool isIn = false;
                bool isOut = false;
                bool isOpt = false;
                bool isComOutPtr = false;
                bool isNullNullTerminated;
                bool? pre = null;
                bool? post = null;

                var salAttrs = GetSalAttributes(salText);
                isNullNullTerminated = salAttrs.Any(a => a.Name == "SAL_name" && a.P1 == "_NullNull_terminated_");

                foreach (var salAttr in salAttrs)
                {
                    if (salAttr.Name == "SAL_name" && salAttr.P1.StartsWith("_COM_Outptr"))
                    {
                        isComOutPtr = true;
                        continue;
                    }

                    if (salAttr.Name == "SAL_null" && salAttr.P1 == "__maybe")
                    {
                        isOpt = true;
                        continue;
                    }

                    if (salAttr.Name == "SAL_pre")
                    {
                        pre = true;
                        continue;
                    }

                    if (salAttr.Name == "SAL_post")
                    {
                        pre = false;
                        post = true;
                        continue;
                    }

                    if (salAttr.Name == "SAL_end")
                    {
                        pre = post = false;
                    }

                    if (salAttr.Name == "SAL_valid")
                    {
                        if (pre.HasValue && pre.Value)
                        {
                            isIn = true;
                        }
                        else if (post.HasValue && post.Value)
                        {
                            isOut = true;
                        }
                        else
                        {
                            isIn = isOut = true;
                        }

                        continue;
                    }

                    if (salAttr.Name == "SAL_name" && salAttr.P1 == "_Post_valid_")
                    {
                        isOut = true;
                        continue;
                    }

                    if (!marshalAsAdded && (salAttr.Name == "SAL_writableTo" || salAttr.Name == "SAL_readableTo") && pre.HasValue && pre.Value)
                    {
                        marshalAsParams = GetArrayMarshalAsFromP1(paramNode, salAttr.P1, isNullNullTerminated);
                        if (!string.IsNullOrEmpty(marshalAsParams))
                        {
                            marshalAsAdded = true;
                        }

                        continue;
                    }
                }

                // If we didn't add marshal as yet, try again without using pre
                if (!marshalAsAdded)
                {
                    var salAttr = salAttrs.FirstOrDefault(attr => attr.Name == "SAL_readableTo" || attr.Name == "SAL_writeableTo");
                    if (salAttr != null)
                    {
                        marshalAsParams = GetArrayMarshalAsFromP1(paramNode, salAttr.P1, isNullNullTerminated);
                        if (!string.IsNullOrEmpty(marshalAsParams))
                        {
                            marshalAsAdded = true;
                        }
                    }
                }

                if (!string.IsNullOrEmpty(marshalAsParams))
                {
                    var attrName = SyntaxFactory.ParseName("NativeTypeInfo");
                    var args = SyntaxFactory.ParseAttributeArgumentList(marshalAsParams.ToString());
                    var finalAttr = SyntaxFactory.Attribute(attrName, args);
                    attributesList.Add(finalAttr);
                }

                if (isIn)
                {
                    attributesList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("In")));
                }

                if (isComOutPtr)
                {
                    attributesList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("ComOutPtr")));
                }
                else if (isOut)
                {
                    attributesList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("Out")));
                }

                if (isOpt)
                {
                    attributesList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("Optional")));
                }

                if (attributesList.Count == 0)
                {
                    return null;
                }

                return SyntaxFactory.AttributeList(SyntaxFactory.SeparatedList(attributesList));

                string GetArrayMarshalAsFromP1(ParameterSyntax paramNode, string p1Text, bool isNullNullTerminated)
                {
                    ParameterListSyntax parameterListNode = (ParameterListSyntax)paramNode.Parent;
                    var match = elementCountRegex.Match(p1Text);
                    string nullnullTerminated = isNullNullTerminated ? ", IsNullNullTerminated = true" : string.Empty;
                    if (match.Success)
                    {
                        string sizeOrParamName = match.Groups[1].Value;
                        if (int.TryParse(sizeOrParamName, out int size))
                        {
                            // Don't bother marking this as an array if it only has 1
                            if (size == 1)
                            {
                                return string.Empty;
                            }

                            return $"(UnmanagedType.LPArray, SizeConst = {size})";
                        }
                        else
                        {
                            sizeOrParamName = sizeOrParamName.Replace("*", string.Empty);
                            for (int i = 0; i < parameterListNode.Parameters.Count; i++)
                            {
                                if (parameterListNode.Parameters[i].Identifier.ValueText == sizeOrParamName)
                                {
                                    return $"(UnmanagedType.LPArray, SizeParamIndex = {i}{nullnullTerminated})";
                                }
                            }
                        }
                    }
                    else
                    {
                        if (p1Text.StartsWith("inexpressibleCount"))
                        {
                            return $"(UnmanagedType.LPArray{nullnullTerminated})";
                        }
                    }

                    return string.Empty;
                }

                IEnumerable<SalAttribute> GetSalAttributes(string salArgsText)
                {
                    foreach (var attr in salArgsText.Split('^'))
                    {
                        var salAttr = SalAttribute.CreateFromCppAttribute(attr);
                        if (salAttr != null)
                        {
                            yield return salAttr;
                        }
                    }
                }
            }

            public override SyntaxNode VisitMethodDeclaration(MethodDeclarationSyntax node)
            {
                if (node.AttributeLists.ToString().Contains("[DllImport(\"\""))
                {
                    return null;
                }

                return base.VisitMethodDeclaration(node);
            }
        }

        private class SalAttribute
        {
            private static readonly System.Text.RegularExpressions.Regex _salRegex = new System.Text.RegularExpressions.Regex("Name=([^\\s;]+)(?:; p1=\\\"?([^\\\";]*)\\\"?)?(?:; p2=\\\"?([^\\\";]*)\\\"?)?(?:; p3=\\\"?([^\\\";]*)\\\"?)?");

            public static SalAttribute CreateFromCppAttribute(string attr)
            {
                SalAttribute ret = new SalAttribute();
                var parts = attr.Split(';');
                foreach (var part in parts)
                {
                    var nameAndValue = part.Split('=');
                    var name = nameAndValue[0].Trim();
                    var value = nameAndValue[1].Replace("\\\"", string.Empty);
                    switch (name)
                    {
                        case "Name":
                            ret.Name = value;
                            break;

                        case "p1":
                            ret.P1 = value;
                            break;

                        case "p2":
                            ret.P2 = value;
                            break;

                        case "p3":
                            ret.P3 = value;
                            break;
                    }
                }

                return ret;
            }

            public string Name { get; private set; }
            public string P1 { get; private set; }
            public string P2 { get; private set; }
            public string P3 { get; private set; }
        }

    }
}

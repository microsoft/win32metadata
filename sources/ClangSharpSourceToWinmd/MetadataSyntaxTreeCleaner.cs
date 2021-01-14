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
        public static SyntaxTree CleanSyntaxTree(SyntaxTree tree, Dictionary<string, string> remaps, Dictionary<string, string> requiredNamespaces, HashSet<string> nonEmptyStructs, string filePath)
        {
            TreeRewriter treeRewriter = new TreeRewriter(remaps, requiredNamespaces, nonEmptyStructs);
            var newRoot = (CSharpSyntaxNode)treeRewriter.Visit(tree.GetRoot());
            return CSharpSyntaxTree.Create(newRoot, null, filePath);
        }

        private class TreeRewriter : CSharpSyntaxRewriter
        {
            private static readonly System.Text.RegularExpressions.Regex elementCountRegex = new System.Text.RegularExpressions.Regex(@"(?:elementCount|byteCount)\(([^\)]+)\)");

            private HashSet<SyntaxNode> nodesWithMarshalAs = new HashSet<SyntaxNode>();
            private Dictionary<string, string> remaps;
            private Dictionary<string, string> requiredNamespaces;
            private HashSet<string> visitedDelegateNames = new HashSet<string>();
            private HashSet<string> visitedMethodNames = new HashSet<string>();
            private HashSet<string> nonEmptyStructs;

            public TreeRewriter(Dictionary<string, string> remaps, Dictionary<string, string> requiredNamespaces, HashSet<string> nonEmptyStructs)
            {
                this.remaps = remaps;
                this.requiredNamespaces = requiredNamespaces;
                this.nonEmptyStructs = nonEmptyStructs;
            }

            public override SyntaxNode VisitParameter(ParameterSyntax node)
            {
                string fullName = GetFullName(node);

                if (this.GetRemapInfo(fullName, out List<AttributeSyntax> listAttributes, out string newType, out string newName))
                {
                    node = (ParameterSyntax)base.VisitParameter(node);
                    if (listAttributes != null)
                    {
                        foreach (var attrNode in listAttributes)
                        {
                            var attrListNode =
                                SyntaxFactory.AttributeList(
                                    SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(attrNode));
                            node = node.WithAttributeLists(node.AttributeLists.Add(attrListNode));
                        }
                    }
                        
                    if (newName != null)
                    {
                        node = node.WithIdentifier(SyntaxFactory.Identifier(newName));
                    }

                    if (newType != null)
                    {
                        node = node.WithType(SyntaxFactory.ParseTypeName(newType));
                    }

                    return node;
                }

                var ret = (ParameterSyntax)base.VisitParameter(node);

                // Get rid of default parameter values
                if (ret.Default != null)
                {
                    ret = ret.WithDefault(null);
                }

                return ret;
            }

            public override SyntaxNode VisitStructDeclaration(StructDeclarationSyntax node)
            {
                // If the struct is empty and we found a non-empty struct in all the source files, delete it
                if (node.Members.Count == 0 && node.AttributeLists.Count == 0 && this.nonEmptyStructs.Contains(node.Identifier.ValueText))
                {
                    return null;
                }

                return base.VisitStructDeclaration(node);
            }

            public override SyntaxNode VisitFieldDeclaration(FieldDeclarationSyntax node)
            {
                string fullName = GetFullName(node);

                this.GetRemapInfo(fullName, out var listAttributes, out string newType, out string newName);

                // ClangSharp mistakenly emits string[] for WCHAR[] Foo = "Bar".
                // Change it to string
                if (newType == null && node.Declaration.Type.ToString() == "string[]")
                {
                    newType = "string";
                }

                node = (FieldDeclarationSyntax)base.VisitFieldDeclaration(node);
                if (listAttributes != null)
                {
                    foreach (var attrNode in listAttributes)
                    {
                        var attrListNode =
                            SyntaxFactory.AttributeList(
                                SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(attrNode));
                        node = node.WithAttributeLists(node.AttributeLists.Add(attrListNode));
                    }
                }

                var firstVar = node.Declaration.Variables.First();

                if (newName != null)
                {
                    var newVar = SyntaxFactory.VariableDeclarator(SyntaxFactory.Identifier(newName));
                    node = node.ReplaceNode(firstVar, newVar);
                }

                if (newType != null)
                {
                    var newDeclaration = node.Declaration.WithType(SyntaxFactory.ParseTypeName(newType));
                    node = node.ReplaceNode(node.Declaration, newDeclaration);
                }

                return node;
            }

            public override SyntaxNode VisitAttributeList(AttributeListSyntax node)
            {
                var firstAttr = node.Attributes[0];
                var attrName = firstAttr.Name.ToString();

                switch (attrName)
                {
                    case "UnmanagedFunctionPointer":
                    {
                        // ClangSharp is emitting this attribute with no arguments.
                        // The typedef we're using of this attribute has no such ctor,
                        // so emit one that does, using WinApi as the default calling convention
                        if (firstAttr.ArgumentList == null)
                        {
                            return
                                SyntaxFactory.AttributeList(
                                    SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                        SyntaxFactory.Attribute(
                                            SyntaxFactory.ParseName("UnmanagedFunctionPointer"),
                                            SyntaxFactory.ParseAttributeArgumentList("(CallingConvention.Winapi)"))));
                        }

                        break;
                    }

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

            public override SyntaxNode VisitDelegateDeclaration(DelegateDeclarationSyntax node)
            {
                string fullName = GetFullName(node);

                // Remove duplicate delegates in this tree
                if (this.visitedDelegateNames.Contains(fullName))
                {
                    return null;
                }

                this.visitedDelegateNames.Add(fullName);

                string returnFullName = $"{fullName}::return";

                if (this.GetRemapInfo(returnFullName, out List<AttributeSyntax> listAttributes, out _, out _))
                {
                    node = (DelegateDeclarationSyntax)base.VisitDelegateDeclaration(node);
                    if (listAttributes != null)
                    {
                        foreach (var attrNode in listAttributes)
                        {
                            var attrListNode =
                                SyntaxFactory.AttributeList(
                                    SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(attrNode))
                                    .WithTarget(
                                        SyntaxFactory.AttributeTargetSpecifier(
                                            SyntaxFactory.Token(SyntaxKind.ReturnKeyword)));

                            node = node.WithAttributeLists(node.AttributeLists.Add(attrListNode));
                        }
                    }

                    return node;
                }

                return base.VisitDelegateDeclaration(node);
            }

            public override SyntaxNode VisitMethodDeclaration(MethodDeclarationSyntax node)
            {
                // Skip methods where we weren't given a import lib name. Should we warn the caller?
                if (node.AttributeLists.ToString().Contains("[DllImport(\"\""))
                {
                    return null;
                }

                string fullName = GetFullName(node);
                if (this.requiredNamespaces.TryGetValue(fullName, out var requiredNamespace))
                {
                    var ns = GetEnclosingNamespace(node);
                    if (ns != requiredNamespace)
                    {
                        return null;
                    }
                }

                // Remove duplicate methods in this tree
                if (this.visitedMethodNames.Contains(fullName))
                {
                    return null;
                }

                this.visitedMethodNames.Add(fullName);

                string returnFullName = $"{fullName}::return";

                // Find remap info for the return parameter for this method and apply any that we find
                if (this.GetRemapInfo(returnFullName, out List<AttributeSyntax> listAttributes, out _, out _))
                {
                    node = (MethodDeclarationSyntax)base.VisitMethodDeclaration(node);
                    if (listAttributes != null)
                    {
                        foreach (var attrNode in listAttributes)
                        {
                            var attrListNode =
                                SyntaxFactory.AttributeList(
                                    SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(attrNode))
                                    .WithTarget(
                                        SyntaxFactory.AttributeTargetSpecifier(
                                            SyntaxFactory.Token(SyntaxKind.ReturnKeyword)));

                            node = node.WithAttributeLists(node.AttributeLists.Add(attrListNode));
                        }
                    }

                    return node;
                }

                return base.VisitMethodDeclaration(node);
            }

            private static string GetEnclosingNamespace(SyntaxNode node)
            {
                for (SyntaxNode currentNode = node; node != null; node = node.Parent)
                {
                    if (node is NamespaceDeclarationSyntax nsNode)
                    {
                        return nsNode.Name.ToString();
                    }
                }

                return null;
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

            private string GetFullName(SyntaxNode node)
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

            private SyntaxNode ProcessNativeTypeNameAttr(AttributeSyntax nativeTypeNameAttr, out bool marshalAs)
            {
                string nativeType = nativeTypeNameAttr.ArgumentList.Arguments[0].ToString();
                nativeType = EncodeHelpers.RemoveQuotes(nativeType);

                List<AttributeSyntax> attributeNodes = new List<AttributeSyntax>();

                marshalAs = this.AddNativeTypeInfoAttribute(nativeType, attributeNodes);
                if (attributeNodes.Count == 0)
                {
                    return null;
                }

                var ret = SyntaxFactory.AttributeList(SyntaxFactory.SeparatedList(attributeNodes));
                if (((AttributeListSyntax)nativeTypeNameAttr.Parent).Target is AttributeTargetSpecifierSyntax target
                    && target.Identifier.ValueText == "return")
                {
                    ret =
                        ret.WithTarget(
                            SyntaxFactory.AttributeTargetSpecifier(
                                SyntaxFactory.Token(SyntaxKind.ReturnKeyword)));
                }

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
                    string arraySubType = GetParameterArraySubtype(paramNode);
                    StringBuilder ret = new StringBuilder("(UnmanagedType.LPArray");

                    if (arraySubType != null)
                    {
                        ret.Append($", ArraySubType = UnmanagedType.{arraySubType}");
                    }

                    if (isNullNullTerminated)
                    {
                        ret.Append(", IsNullNullTerminated = true");
                    }

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

                            ret.Append($", SizeConst = {size}");
                        }
                        else
                        {
                            sizeOrParamName = sizeOrParamName.Replace("*", string.Empty);
                            for (int i = 0; i < parameterListNode.Parameters.Count; i++)
                            {
                                if (parameterListNode.Parameters[i].Identifier.ValueText == sizeOrParamName)
                                {
                                    ret.Append($", SizeParamIndex = {i}");
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        // If it didn't match the regex and we don't see inexpressibleCount, we can't do 
                        // anything but return an empty string, because we don't know how to interpret it
                        if (!p1Text.StartsWith("inexpressibleCount"))
                        {
                            ret = new StringBuilder();
                        }
                    }

                    if (ret.Length != 0)
                    {
                        ret.Append(')');
                    }

                    return ret.ToString();

                    string GetParameterArraySubtype(ParameterSyntax paramNode)
                    {
                        foreach (var attrList in paramNode.AttributeLists)
                        {
                            foreach (var attr in attrList.Attributes)
                            {
                                if (attr.Name.ToString() == "NativeTypeName")
                                {
                                    string nativeType = attr.ArgumentList.Arguments[0].ToString();
                                    nativeType = EncodeHelpers.RemoveQuotes(nativeType);
                                    if (nativeType.StartsWith("const "))
                                    {
                                        nativeType = nativeType.Substring("const ".Length);
                                    }

                                    if (nativeType.EndsWith(" *"))
                                    {
                                        nativeType = nativeType.Substring(0, nativeType.Length - 2);
                                    }

                                    string arraySubType = ConvertTypeToMarshalAsType(nativeType, out _, out _, out _);
                                    return arraySubType;
                                }
                            }
                        }

                        return null;
                    }
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

            private bool GetRemapInfo(string fullName, out List<AttributeSyntax> listAttributes, out string newType, out string newName)
            {
                if (!string.IsNullOrEmpty(fullName) && this.remaps.TryGetValue(fullName, out string remapData))
                {
                    return EncodeHelpers.DecodeRemap(remapData, out listAttributes, out newType, out newName);
                }

                listAttributes = null;
                newType = null;
                newName = null;

                return false;
            }
        }

        private class SalAttribute
        {
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

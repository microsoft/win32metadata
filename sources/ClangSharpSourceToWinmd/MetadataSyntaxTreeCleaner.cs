using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using PartitionUtilsLib;

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
            private HashSet<string> visitedStaticMethodNames = new HashSet<string>();
            private HashSet<string> nonEmptyStructs;

            public TreeRewriter(Dictionary<string, string> remaps, Dictionary<string, string> requiredNamespaces, HashSet<string> nonEmptyStructs)
            {
                this.remaps = remaps;
                this.requiredNamespaces = requiredNamespaces;
                this.nonEmptyStructs = nonEmptyStructs;
            }

            public override SyntaxNode VisitParameter(ParameterSyntax node)
            {
                string fullName = SyntaxUtils.GetFullName(node);

                if (this.GetRemapInfo(fullName, out List<AttributeSyntax> listAttributes, node.Type.ToString(), out string newType, out string newName))
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
                        node = node.WithType(SyntaxFactory.ParseTypeName(newType).WithTrailingTrivia(SyntaxFactory.Space));
                    }
                }
                else
                {
                    node = (ParameterSyntax)base.VisitParameter(node);
                }

                // Get rid of default parameter values
                if (node.Default != null)
                {
                    node = node.WithDefault(null);
                }

                return node;
            }

            public override SyntaxNode VisitStructDeclaration(StructDeclarationSyntax node)
            {
                // If the struct is empty and we found a non-empty struct in all the source files, delete it
                if (SyntaxUtils.IsEmptyStruct(node) && this.nonEmptyStructs.Contains(node.Identifier.ValueText))
                {
                    return null;
                }

                return base.VisitStructDeclaration(node);
            }

            public override SyntaxNode VisitFieldDeclaration(FieldDeclarationSyntax node)
            {
                string fullName = SyntaxUtils.GetFullName(node);

                this.GetRemapInfo(fullName, out var listAttributes, node.Declaration.Type.ToString(), out string newType, out string newName);

                // ClangSharp mistakenly emits string[] for WCHAR[] Foo = "Bar".
                // Change it to string
                if (newType == null && node.Declaration.Type.ToString() == "string[]")
                {
                    newType = "string";
                }

                // Turn public static readonly Guids into string constants with an attribute
                // to signal language projections to turn them into Guid constants. Guid constants 
                // aren't allowed in metadata, requiring us to surface them this way
                if (node.Modifiers.ToString() == "public static readonly" && node.Declaration.Type.ToString() == "Guid")
                {
                    Guid guidVal = Guid.Empty;
                    var varInitializer = node.Declaration.Variables.First().Initializer;
                    if (varInitializer.Value is ObjectCreationExpressionSyntax objCreationSyntax)
                    {
                        var args = objCreationSyntax.ArgumentList.Arguments;
                        if (args.Count == 11)
                        {
                            uint p0 = EncodeHelpers.ParseHex(args[0].ToString());
                            ushort p1 = (ushort)EncodeHelpers.ParseHex(args[1].ToString());
                            ushort p2 = (ushort)EncodeHelpers.ParseHex(args[2].ToString());
                            byte p3 = (byte)EncodeHelpers.ParseHex(args[3].ToString());
                            byte p4 = (byte)EncodeHelpers.ParseHex(args[4].ToString());
                            byte p5 = (byte)EncodeHelpers.ParseHex(args[5].ToString());
                            byte p6 = (byte)EncodeHelpers.ParseHex(args[6].ToString());
                            byte p7 = (byte)EncodeHelpers.ParseHex(args[7].ToString());
                            byte p8 = (byte)EncodeHelpers.ParseHex(args[8].ToString());
                            byte p9 = (byte)EncodeHelpers.ParseHex(args[9].ToString());
                            byte p10 = (byte)EncodeHelpers.ParseHex(args[10].ToString());

                            guidVal = new Guid(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
                        }
                        else if (objCreationSyntax.ArgumentList.Arguments.Count == 1)
                        {
                            // If this is an invalid format, remove the node
                            if (!Guid.TryParse(objCreationSyntax.ArgumentList.Arguments[0].ToString(), out guidVal))
                            {
                                return null;
                            }
                        }
                    }

                    if (guidVal == Guid.Empty)
                    {
                        return node;
                    }

                    node = node.RemoveNode(varInitializer, SyntaxRemoveOptions.KeepExteriorTrivia | SyntaxRemoveOptions.KeepEndOfLine);
                    node = node.AddAttributeLists(EncodeHelpers.ConvertGuidToAttributeList(guidVal).WithLeadingTrivia(node.GetLeadingTrivia()));

                    return node;
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
                    node = node.WithDeclaration(node.Declaration.WithType(SyntaxFactory.ParseTypeName(newType).WithTrailingTrivia(SyntaxFactory.Space)));
                }

                return node;
            }

            public override SyntaxNode VisitAttributeList(AttributeListSyntax node)
            {
                var firstAttr = node.Attributes[0];
                var attrName = firstAttr.Name.ToString();

                switch (attrName)
                {
                    // We don't want more than one of these on an interface. Get rid of it if the 
                    // struct doesn't have a NativeTypeName, which means it's a forward declaration.
                    // The real declaration will have the SupportedOSPlatform that we'll keep 
                    case "SupportedOSPlatform":
                    {
                        if (node.Parent is StructDeclarationSyntax structDeclaration)
                        {
                            if (!structDeclaration.AttributeLists.Any(list => list.Attributes.Any(attr => attr.Name.ToString() == "NativeTypeName")))
                            {
                                return null;
                            }
                        }

                        break;
                    }

                    case "Guid":
                    {
                        return this.ProcessGuidAttr(firstAttr);
                    }

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
                        var ret = this.ProcessNativeTypeNameAttr(firstAttr);

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
                string fullName = SyntaxUtils.GetFullName(node);

                // Remove duplicate delegates in this tree
                if (this.visitedDelegateNames.Contains(fullName))
                {
                    return null;
                }

                this.visitedDelegateNames.Add(fullName);

                string returnFullName = $"{fullName}::return";

                if (this.GetRemapInfo(returnFullName, out List<AttributeSyntax> listAttributes, node.ReturnType.ToString(), out var newType, out _))
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

                    if (newType != null)
                    {
                        node = node.WithReturnType(SyntaxFactory.ParseTypeName(newType).WithTrailingTrivia(SyntaxFactory.Space));
                    }

                    return node;
                }

                return base.VisitDelegateDeclaration(node);
            }

            public override SyntaxNode VisitMethodDeclaration(MethodDeclarationSyntax node)
            {
                // Skip methods where we weren't given an import lib name. Should we warn the caller?
                if (node.AttributeLists.ToString().Contains("[DllImport(\"\""))
                {
                    return null;
                }

                string fullName = SyntaxUtils.GetFullName(node);

                // Remove duplicate static methods
                if (node.Body == null)
                {
                    // If this function is supposed to be in a certain namespace, remove it if it's not.
                    // We only respect this for static methods
                    if (this.requiredNamespaces.TryGetValue(fullName, out var requiredNamespace))
                    {
                        var ns = GetEnclosingNamespace(node);
                        if (ns != requiredNamespace)
                        {
                            return null;
                        }
                    }

                    // Remove duplicate methods in this tree
                    if (this.visitedStaticMethodNames.Contains(fullName))
                    {
                        return null;
                    }

                    this.visitedStaticMethodNames.Add(fullName);
                }
                // Any method with a body has to be part of a call to a vtable for an interface.
                // If it's not, get rid of it
                else if (!node.Body.ToString().Contains("GetDelegateForFunctionPointer"))
                {
                    return null;
                }

                string returnFullName = $"{fullName}::return";

                // Find remap info for the return parameter for this method and apply any that we find
                if (this.GetRemapInfo(returnFullName, out List<AttributeSyntax> listAttributes, node.ReturnType.ToString(), out var newType, out _))
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

                    if (newType != null)
                    {
                        node = node.WithReturnType(SyntaxFactory.ParseTypeName(newType).WithTrailingTrivia(SyntaxFactory.Space));
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

            private string GetInfoForNativeType(string nativeTypeName, out bool isConst, out bool isNullTerminated, out bool isNullNullTerminated)
            {
                string metadataType = null;
                isConst = false;
                isNullTerminated = false;
                isNullNullTerminated = false;

                switch (nativeTypeName)
                {
                    case "LPCVOID":
                        isConst = true;
                        break;

                    case "PCHAR":
                    case "LPCH":
                    case "PCH":
                        metadataType = ClangSharpSourceWinmdGenerator.Win32StringType;
                        break;

                    case "LPCCH":
                    case "PCCH":
                        metadataType = ClangSharpSourceWinmdGenerator.Win32StringType;
                        isConst = true;
                        break;

                    case "NPSTR":
                    case "LPSTR":
                    case "PSTR":
                        metadataType = ClangSharpSourceWinmdGenerator.Win32StringType;
                        isNullTerminated = true;
                        break;

                    case "LPCSTR":
                    case "PCSTR":
                        metadataType = ClangSharpSourceWinmdGenerator.Win32StringType;
                        isConst = true;
                        isNullTerminated = true;
                        break;

                    case "PZZSTR":
                        metadataType = ClangSharpSourceWinmdGenerator.Win32StringType;
                        isNullNullTerminated = true;
                        break;

                    case "CPZZSTR":
                        metadataType = ClangSharpSourceWinmdGenerator.Win32StringType;
                        isConst = true;
                        isNullNullTerminated = true;
                        break;

                    case "PWCHAR":
                    case "LPWCH":
                    case "PWCH":
                        metadataType = ClangSharpSourceWinmdGenerator.Win32StringType;
                        break;

                    case "NWPSTR":
                    case "LPWSTR":
                    case "PWSTR":
                    case "LPOLESTR":
                    case "PNZWCH":
                    case "WCHAR *":
                    case "OLECHAR *":
                    case "wchar_t *":
                        metadataType = ClangSharpSourceWinmdGenerator.Win32WideStringType;
                        isNullTerminated = true;
                        break;

                    case "LPCWSTR":
                    case "PCWSTR":
                    case "LPCWCH":
                    case "PCNZWCH":
                    case "LPCOLESTR":
                    case "const OLECHAR *":
                    case "const WCHAR *":
                    case "const wchar_t *":
                        metadataType = ClangSharpSourceWinmdGenerator.Win32WideStringType;
                        isNullTerminated = true;
                        isConst = true;
                        break;

                    case "PZZWSTR":
                        metadataType = ClangSharpSourceWinmdGenerator.Win32WideStringType;
                        isNullNullTerminated = true;
                        break;

                    case "PCZZWSTR":
                        metadataType = ClangSharpSourceWinmdGenerator.Win32WideStringType;
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

                return metadataType;
            }

            private void AddNativeArrayInfoAttribute(string nativeTypeName, List<AttributeSyntax> attrsList)
            {
                if (string.IsNullOrWhiteSpace(nativeTypeName))
                {
                    return;
                }

                var metadataType = GetInfoForNativeType(nativeTypeName, out bool isConst, out bool isNullTerminated, out bool isNullNullTerminated);

                if (isConst)
                {
                    attrsList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("Const")));
                }

                if (metadataType == ClangSharpSourceWinmdGenerator.Win32StringType || metadataType == ClangSharpSourceWinmdGenerator.Win32WideStringType)
                {
                    if (!isNullTerminated)
                    {
                        attrsList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("NotNullTerminated")));
                    }

                    if (isNullNullTerminated)
                    {
                        attrsList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("NullNullTerminated")));
                    }
                }
            }

            private SyntaxNode ProcessGuidAttr(AttributeSyntax guidAttr)
            {
                string guidStr = guidAttr.ArgumentList.Arguments[0].ToString();
                guidStr = EncodeHelpers.RemoveQuotes(guidStr);

                Guid guid = Guid.Parse(guidStr);

                return EncodeHelpers.ConvertGuidToAttributeList(guid);
            }

            private SyntaxNode ProcessNativeTypeNameAttr(AttributeSyntax nativeTypeNameAttr)
            {
                string nativeType = nativeTypeNameAttr.ArgumentList.Arguments[0].ToString();
                nativeType = EncodeHelpers.RemoveQuotes(nativeType);
                if (nativeType == "PCNZWCH")
                {

                }

                List<AttributeSyntax> attributeNodes = new List<AttributeSyntax>();

                this.AddNativeArrayInfoAttribute(nativeType, attributeNodes);
                attributeNodes.Insert(0, nativeTypeNameAttr);

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

                string nativeArrayInfoParams = null;
                bool isIn = false;
                bool isOut = false;
                bool isOpt = false;
                bool isComOutPtr = false;
                bool isRetVal = false;
                bool isNullNullTerminated;
                bool? pre = null;
                bool? post = null;

                var salAttrs = GetSalAttributes(salText);
                isNullNullTerminated = salAttrs.Any(a => a.Name == "SAL_name" && a.P1 == "_NullNull_terminated_");

                foreach (var salAttr in salAttrs)
                {
                    if (salAttr.Name == "SAL_name")
                    {
                        if (salAttr.P1.StartsWith("_COM_Outptr"))
                        {
                            isComOutPtr = true;
                            continue;
                        }
                        else if (salAttr.P1.StartsWith("_Outptr_") && !isComOutPtr)
                        {
                            isOut = true;
                            continue;
                        }
                        else if (salAttr.P1.StartsWith("__RPC__"))
                        {
                            // TODO: Handle ecount, xcount and others that deal with counts

                            string[] parts = salAttr.P1.Split('_');
                            foreach (var part in parts)
                            {
                                switch (part)
                                {
                                    case "in":
                                        isIn = true;
                                        break;

                                    case "out":
                                        isOut = true;
                                        break;

                                    case "inout":
                                        isIn = isOut = true;
                                        break;

                                    case "opt":
                                        isOpt = true;
                                        break;
                                }
                            }

                            break;
                        }
                    }

                    if (salAttr.Name == "SAL_null" && salAttr.P1 == "__maybe")
                    {
                        isOpt = true;
                        continue;
                    }

                    if (salAttr.Name == "SAL_retval")
                    {
                        isRetVal = true;
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
                        nativeArrayInfoParams = GetArrayMarshalAsFromP1(paramNode, salAttr.P1);
                        if (!string.IsNullOrEmpty(nativeArrayInfoParams))
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
                        nativeArrayInfoParams = GetArrayMarshalAsFromP1(paramNode, salAttr.P1);
                        if (!string.IsNullOrEmpty(nativeArrayInfoParams))
                        {
                            marshalAsAdded = true;
                        }
                    }
                }

                if (!string.IsNullOrEmpty(nativeArrayInfoParams))
                {
                    var attrName = SyntaxFactory.ParseName(nativeArrayInfoParams.Contains("BytesParamIndex") ? "MemorySize" : "NativeArrayInfo");
                    var args = SyntaxFactory.ParseAttributeArgumentList(nativeArrayInfoParams.ToString());
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

                if (isNullNullTerminated)
                {
                    attributesList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("NullNullTerminated")));
                }

                if (isRetVal)
                {
                    attributesList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("RetVal")));
                }

                if (attributesList.Count == 0)
                {
                    return null;
                }

                return SyntaxFactory.AttributeList(SyntaxFactory.SeparatedList(attributesList));

                string GetArrayMarshalAsFromP1(ParameterSyntax paramNode, string p1Text)
                {
                    ParameterListSyntax parameterListNode = (ParameterListSyntax)paramNode.Parent;
                    var match = elementCountRegex.Match(p1Text);
                    StringBuilder ret = new StringBuilder("(");

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

                            if (ret.Length != 1)
                            {
                                ret.Append(", ");
                            }

                            ret.Append($"SizeConst = {size}");
                        }
                        else
                        {
                            sizeOrParamName = sizeOrParamName.Replace("*", string.Empty);
                            for (int i = 0; i < parameterListNode.Parameters.Count; i++)
                            {
                                if (parameterListNode.Parameters[i].Identifier.ValueText == sizeOrParamName)
                                {
                                    if (ret.Length != 1)
                                    {
                                        ret.Append(", ");
                                    }

                                    string propName = p1Text.StartsWith("elementCount") ? "SizeParamIndex" : "BytesParamIndex";
                                    ret.Append($"{propName} = {i}");
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

                    if (ret.Length > 1)
                    {
                        ret.Append(')');
                        return ret.ToString();
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

            private bool GetRemapInfo(string fullName, out List<AttributeSyntax> listAttributes, string currentType, out string newType, out string newName)
            {
                listAttributes = null;
                newName = null;

                if (!string.IsNullOrEmpty(fullName) && this.remaps.TryGetValue(fullName, out string remapData))
                {
                    var ret = EncodeHelpers.DecodeRemap(remapData, out listAttributes, out newType, out newName);
                    if (newType != null)
                    {
                        // Try to keep the pointers at the same level if we're replacing
                        // a uint or int. The mismatch can happen in the auto-generated
                        // enum remaps which don't know if the params/fields getting replaced
                        // are pointers or not
                        if (currentType.StartsWith("uint") || currentType.StartsWith("int") || currentType.StartsWith("short") || currentType.StartsWith("ushort"))
                        {
                            int starIndex = currentType.IndexOf('*');
                            if (starIndex != -1 && newType.IndexOf('*') == -1)
                            {
                                newType += currentType.Substring(starIndex);
                            }
                        }
                    }

                    return ret;
                }
                else
                {
                    // See if the type ends in the magic suffix. We use a remap fed to clangsharp 
                    // to keep some typedefs from following down to their original type
                    const string RevertToTypeSuffix = "___";

                    EncodeHelpers.SplitType(currentType, out var typeOnly, out var pointers);
                    if (typeOnly.EndsWith(RevertToTypeSuffix))
                    {
                        newType = typeOnly.Substring(0, typeOnly.Length - RevertToTypeSuffix.Length) + pointers;
                        return true;
                    }
                }

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

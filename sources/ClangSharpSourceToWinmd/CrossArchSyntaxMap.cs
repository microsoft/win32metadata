using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using MetadataUtils;

namespace ClangSharpSourceToWinmd
{
    public class CrossArchSyntaxMap
    {
        private readonly Dictionary<string, List<CrossArchInfo>> namesToInfos = new();
        private readonly Dictionary<string, StructDeclarationSyntax> namesTo64BitStructs = new();
        private readonly HashSet<string> x86StructsNeed64BitAttrs = new();
        private readonly object syncObj = new();

        public CrossArchSyntaxMap()
        {
        }

        public static Architecture GetArchForTree(SyntaxTree tree)
        {
            string potentialArch = Path.GetFileName(Path.GetDirectoryName(tree.FilePath));

            switch (potentialArch)
            {
                case "x64":
                    return Architecture.X64;

                case "x86":
                    return Architecture.X86;

                case "arm64":
                    return Architecture.Arm64;

                default:
                    return Architecture.None;
            }
        }

        public static bool IsCrossArchTree(SyntaxTree tree)
        {
            string treeFileName = Path.GetFileName(tree.FilePath).ToLowerInvariant();
            if (treeFileName.StartsWith("autotypes.") ||
                treeFileName.EndsWith(".enums.cs") ||
                treeFileName.EndsWith(".constants.cs") ||
                treeFileName.EndsWith(".manual.cs"))
            {
                return false;
            }

            return true;
        }

        public static bool IsPotentialCrossArch(StructDeclarationSyntax node)
        {
            return node.Parent is NamespaceDeclarationSyntax && !SyntaxUtils.IsEmptyStruct(node);
        }

        public static bool IsPotentialCrossArch(DelegateDeclarationSyntax node)
        {
            return node.Parent is NamespaceDeclarationSyntax;
        }

        public static bool IsPotentialCrossArch(EnumDeclarationSyntax node)
        {
            return node.Parent is NamespaceDeclarationSyntax;
        }

        public static bool IsPotentialCrossArch(MethodDeclarationSyntax node)
        {
            var dllImportAttr = SyntaxUtils.GetAttribute(node.AttributeLists, "DllImport");
            if (dllImportAttr != null)
            {
                return true;
            }

            return false;
        }

        public StructDeclarationSyntax FixX86Struct(StructDeclarationSyntax x86Node)
        {
            string name = SyntaxUtils.GetFullName(x86Node, true);

            lock (this.syncObj)
            {
                if (this.x86StructsNeed64BitAttrs.Contains(name))
                {
                    return x86Node.AddAttributeLists(GetLayoutAttributes(this.namesTo64BitStructs[name].AttributeLists).ToArray());
                }
            }

            return x86Node;
        }

        public HashSet<string> Get64BitTreesUsedForX86()
        {
            HashSet<string> ret = new();

            lock (this.syncObj)
            {
                foreach (var name in this.x86StructsNeed64BitAttrs)
                {
                    var nonX86Struct = this.namesTo64BitStructs[name];
                    if (!ret.Contains(nonX86Struct.SyntaxTree.FilePath))
                    {
                        ret.Add(nonX86Struct.SyntaxTree.FilePath);
                    }
                }
            }

            return ret;
        }

        private static SyntaxList<AttributeListSyntax> GetLayoutAttributes(SyntaxList<AttributeListSyntax> lists)
            => SyntaxFactory.List(lists.Select(list => list.WithAttributes(SyntaxFactory.SeparatedList(
                list.Attributes.Where(attribute => attribute.Name.ToString().Split('.').Last()
                    is "StructLayout" or "StructLayoutAttribute")))).Where(list => list.Attributes.Count != 0));

        public void AddTree(SyntaxTree tree)
        {
            CrossArchSyntaxWalker walker = new CrossArchSyntaxWalker(this);
            walker.WalkTree(tree);
        }

        public IEnumerable<Architecture> GetSignatureArchGroupings(string name)
        {
            CrossArchInfo[] foundCrossArchInfos = new CrossArchInfo[0];

            lock (this.syncObj)
            {
                if (this.namesToInfos.TryGetValue(name, out var crossArchInfos))
                {
                    foundCrossArchInfos = crossArchInfos.ToArray();
                }
            }

            foreach (var info in foundCrossArchInfos)
            {
                yield return info.Arch;
            }
        }

        public IEnumerable<Architecture> GetSignatureArchGroupings(SyntaxNode node)
        {
            string name = SyntaxUtils.GetFullName(node, true);
            return this.GetSignatureArchGroupings(name);
        }

        private static string GetNativeTypeForSignature(SyntaxList<AttributeListSyntax> attributeLists)
        {
            var nativeType = SyntaxUtils.GetNativeTypeNameFromAttributesLists(attributeLists);

            // Get rid of ones that won't compare well:
            // If the native type has a '/' it contains a path
            // If it contains (*), it's a function pointer prototype
            if (nativeType != null && (nativeType.Contains('/') || nativeType.Contains("(*)")))
            {
                nativeType = null;
            }

            return nativeType;
        }

        private static string GetMethodSignature(
            string name, SyntaxList<AttributeListSyntax> attributeLists, TypeSyntax returnType, ParameterListSyntax parameterList)
        {
            StringBuilder ret = new StringBuilder();
            AppendAttributes(ret, attributeLists);

            var returnAttributes = SyntaxFactory.List(attributeLists.Where(list => list.Target?.Identifier.ValueText == "return"));
            var retType = GetTypeName(returnType.ToString(), returnAttributes);
            if (retType == null)
            {
                retType = returnType.ToString();
            }

            ret.Append(retType);
            ret.Append(' ');
            ret.Append(name);
            ret.Append('(');

            bool firstParam = true;
            foreach (var param in parameterList.Parameters)
            {
                if (firstParam)
                {
                    firstParam = false;
                }
                else
                {
                    ret.Append(',');
                }

                AppendAttributes(ret, param.AttributeLists);
                ret.Append(param.Modifiers.ToString());
                if (param.Type != null)
                {
                    var typeName = GetTypeName(param.Type.ToString(), param.AttributeLists);
                    ret.Append(typeName);
                    ret.Append(' ');
                }

                ret.Append(param.Identifier.ValueText);
            }

            ret.Append(')');

            return ret.ToString();
        }

        private static void AppendAttributes(StringBuilder signature, SyntaxList<AttributeListSyntax> lists)
        {
            var attributes = new List<string>();
            foreach (var list in lists)
            {
                foreach (var attribute in list.Attributes)
                {
                    string name = attribute.Name.ToString().Split('.').Last().Replace("global::", string.Empty);
                    if (name is "NativeTypeName" or "UnmanagedFunctionPointer")
                        continue;
                    var value = attribute;
                    if (name == "DllImport" && value.ArgumentList != null)
                    {
                        // Windows calling conventions are only meaningful on x86.
                        value = value.WithArgumentList(value.ArgumentList.WithArguments(
                            SyntaxFactory.SeparatedList(value.ArgumentList.Arguments.Where(argument =>
                                argument.NameEquals?.Name.Identifier.ValueText != "CallingConvention"))));
                    }
                    attributes.Add($"[{list.Target}{value.NormalizeWhitespace()}]");
                }
            }
            foreach (string attribute in attributes.OrderBy(value => value, StringComparer.Ordinal))
                signature.Append(attribute);
        }

        private static string GetTypeName(string type, SyntaxList<AttributeListSyntax> attributeList)
        {
            var ret = type;
            if (type.StartsWith("IntPtr") ||
                type.StartsWith("UIntPtr") ||
                type.StartsWith("int") ||
                type.StartsWith("uint") ||
                type.StartsWith("long") ||
                type.StartsWith("ulong"))
            {
                var nativeType = GetNativeTypeForSignature(attributeList);
                if (nativeType != null)
                {
                    ret = nativeType;
                }
            }

            return ret;
        }

        private static string GetFullSignature(SyntaxNode node)
        {
            if (node is StructDeclarationSyntax s)
            {
                StringBuilder ret = new StringBuilder();
                AppendAttributes(ret, s.AttributeLists);
                ret.Append(s.Identifier.ValueText);
                ret.Append(s.BaseList?.ToString());
                ret.Append(':');

                bool firstField = true;
                foreach (var member in s.Members)
                {
                    if (member is FieldDeclarationSyntax field)
                    {
                        if (field.Modifiers.ToString().Contains("const"))
                        {
                            continue;
                        }

                        if (firstField)
                        {
                            firstField = false;
                        }
                        else
                        {
                            ret.Append(',');
                        }   

                        var firstVar = field.Declaration.Variables.First();
                        var typeName = GetTypeName(field.Declaration.Type.ToString(), field.AttributeLists);
                        AppendAttributes(ret, field.AttributeLists);
                        ret.Append(field.Modifiers.ToString());
                        ret.Append(typeName);
                        ret.Append(' ');
                        ret.Append(firstVar.ToString());
                    }
                    else if (member is MethodDeclarationSyntax method)
                    {
                        ret.Append(GetMethodSignature(method.Identifier.ValueText, method.AttributeLists, method.ReturnType, method.ParameterList));
                    }
                    else if (member is DelegateDeclarationSyntax callback)
                    {
                        ret.Append(GetMethodSignature(callback.Identifier.ValueText, callback.AttributeLists, callback.ReturnType, callback.ParameterList));
                    }
                    else if ((member is StructDeclarationSyntax or EnumDeclarationSyntax) &&
                        member.DescendantNodesAndSelf().OfType<AttributeSyntax>().Any(attribute =>
                            attribute.Name.ToString().StartsWith("global::Windows.Win32.Foundation.Metadata.", StringComparison.Ordinal) ||
                            attribute.Name.ToString() is "global::System.Flags" or "global::System.Runtime.InteropServices.PreserveSig"))
                    {
                        ret.Append('{').Append(GetFullSignature(member)).Append('}');
                    }
                }

                return ret.ToString();
            }
            else if (node is MethodDeclarationSyntax m)
            {
                return GetMethodSignature(m.Identifier.ValueText, m.AttributeLists, m.ReturnType, m.ParameterList);
            }
            else if (node is DelegateDeclarationSyntax d)
            {
                return GetMethodSignature(d.Identifier.ValueText, d.AttributeLists, d.ReturnType, d.ParameterList);
            }

            return node.ToString();
        }

        private void AddNode(Architecture arch, SyntaxNode node)
        {
            string name = SyntaxUtils.GetFullName(node, true);
            string fullSignature = GetFullSignature(node);
            string altSignatureForX86 = string.Empty;

            lock (this.syncObj)
            {
                if (node is StructDeclarationSyntax structNode)
                {
                    // Cache non-x86 layout in case Clang omits x86 packing information.
                    // Clang doesn't seem to always know the packing for -m32 but does better with -m64
                    if (arch != Architecture.X86 && GetLayoutAttributes(structNode.AttributeLists).Count != 0 && !this.namesTo64BitStructs.ContainsKey(name))
                    {
                        this.namesTo64BitStructs[name] = structNode;
                    }

                    if (arch == Architecture.X86)
                    {
                        if (structNode.AttributeLists.Count == 0 && this.namesTo64BitStructs.TryGetValue(name, out var nonX86Node))
                        {
                            var tempNode = structNode.AddAttributeLists(GetLayoutAttributes(nonX86Node.AttributeLists).ToArray());

                            // Save these off to see if we match with previous items
                            altSignatureForX86 = GetFullSignature(tempNode);
                        }
                    }
                }

                if (!this.namesToInfos.TryGetValue(name, out var crossArchInfos))
                {
                    crossArchInfos = new List<CrossArchInfo>();
                    this.namesToInfos[name] = crossArchInfos;
                }

                foreach (var info in crossArchInfos)
                {
                    if (info.FullSignature == altSignatureForX86)
                    {
                        this.x86StructsNeed64BitAttrs.Add(name);
                        info.Arch |= arch;
                        return;
                    }

                    if (info.FullSignature == fullSignature)
                    {
                        info.Arch |= arch;
                        return;
                    }
                }

                var newInfo = new CrossArchInfo() { Arch = arch, FullSignature = fullSignature };
                crossArchInfos.Add(newInfo);
            }
        }

        private class CrossArchSyntaxWalker : CSharpSyntaxWalker
        {
            private CrossArchSyntaxMap map;
            private Architecture currentArch;

            public CrossArchSyntaxWalker(CrossArchSyntaxMap map)
            {
                this.map = map;
            }

            public void WalkTree(SyntaxTree tree)
            {
                if (!IsCrossArchTree(tree))
                {
                    return;
                }

                this.currentArch = GetArchForTree(tree);

                if (this.currentArch != Architecture.None)
                {
                    this.Visit(tree.GetRoot());
                }
            }

            public override void VisitStructDeclaration(StructDeclarationSyntax node)
            {
                if (IsPotentialCrossArch(node))
                {
                    this.map.AddNode(this.currentArch, node);
                }

                base.VisitStructDeclaration(node);
            }

            public override void VisitMethodDeclaration(MethodDeclarationSyntax node)
            {
                if (IsPotentialCrossArch(node))
                {
                    this.map.AddNode(this.currentArch, node);
                }

                base.VisitMethodDeclaration(node);
            }

            public override void VisitDelegateDeclaration(DelegateDeclarationSyntax node)
            {
                if (IsPotentialCrossArch(node))
                {
                    this.map.AddNode(this.currentArch, node);
                }

                base.VisitDelegateDeclaration(node);
            }

            public override void VisitEnumDeclaration(EnumDeclarationSyntax node)
            {
                if (IsPotentialCrossArch(node))
                {
                    this.map.AddNode(this.currentArch, node);
                }

                base.VisitEnumDeclaration(node);
            }
        }
    }

    public class CrossArchInfo
    {
        public Architecture Arch { get; set; }

        public string FullSignature { get; set; }
    }
}

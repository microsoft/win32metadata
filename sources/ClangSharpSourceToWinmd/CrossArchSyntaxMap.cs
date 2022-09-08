using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Windows.Win32.Interop;
using MetadataUtils;

namespace ClangSharpSourceToWinmd
{
    public class CrossArchSyntaxMap
    {
        private Dictionary<string, List<CrossArchInfo>> namesToInfos = new Dictionary<string, List<CrossArchInfo>>();
        private Dictionary<string, StructDeclarationSyntax> namesTo64BitStructs = new Dictionary<string, StructDeclarationSyntax>();
        private HashSet<string> x86StructsNeed64BitAttrs = new HashSet<string>();

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
            if (this.x86StructsNeed64BitAttrs.Contains(name))
            {
                return x86Node.AddAttributeLists(this.namesTo64BitStructs[name].AttributeLists.ToArray());
            }

            return x86Node;
        }

        public HashSet<string> Get64BitTreesUsedForX86()
        {
            HashSet<string> ret = new HashSet<string>();

            foreach (var name in this.x86StructsNeed64BitAttrs)
            {
                var nonX86Struct = this.namesTo64BitStructs[name];
                if (!ret.Contains(nonX86Struct.SyntaxTree.FilePath))
                {
                    ret.Add(nonX86Struct.SyntaxTree.FilePath);
                }
            }

            return ret;
        }

        public void AddTree(SyntaxTree tree)
        {
            CrossArchSyntaxWalker walker = new CrossArchSyntaxWalker(this);
            walker.WalkTree(tree);
        }

        public IEnumerable<Architecture> GetSignatureArchGroupings(string name)
        {
            if (this.namesToInfos.TryGetValue(name, out var crossArchInfos))
            {
                foreach (var info in crossArchInfos)
                {
                    yield return info.Arch;
                }
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
            foreach (var list in attributeLists)
            {
                if (list.Target != null && list.Target.Identifier.Text == "return")
                {
                    continue;
                }

                foreach (var attr in list.Attributes)
                {
                    var attrText = attr.ToString();

                    // Skip return attributes
                    if (attrText.StartsWith("return:"))
                    {
                        continue;
                    }

                    // Skip UnmanagedFunctionPointer attributes because they can have calling
                    // conventions that will only be accurate on x86
                    if (attrText.StartsWith("UnmanagedFunctionPointer"))
                    {
                        continue;
                    }

                    // Skip DllImport attributes because they can have calling
                    // conventions that will only be accurate on x86
                    if (attrText.StartsWith("DllImport"))
                    {
                        continue;
                    }

                    ret.Append($"[{attrText}]");
                }
            }

            var retType = GetTypeName(returnType.ToString(), attributeLists);
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
                ret.Append(s.AttributeLists.ToString());
                ret.Append(s.Identifier.ValueText);
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
                        ret.Append(typeName);
                        ret.Append(' ');
                        ret.Append(firstVar.ToString());
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

            if (node is StructDeclarationSyntax structNode)
            {
                // Cache the non-x86 struct attributes in case the x86 doesn't have any.
                // Clang doesn't seem to always know the packing for -m32 but does better with -m64
                if (arch != Architecture.X86 && structNode.AttributeLists.Count != 0 && !this.namesTo64BitStructs.ContainsKey(name))
                {
                    this.namesTo64BitStructs[name] = structNode;
                }

                if (arch == Architecture.X86)
                {
                    // If the x86 node doesn't have any attributes, try using the ones cached from the non-x86 version
                    if (structNode.AttributeLists.Count == 0 && this.namesTo64BitStructs.TryGetValue(name, out var nonX86Node))
                    {
                        var tempNode = structNode.WithAttributeLists(nonX86Node.AttributeLists);

                        // Save these off to see if we match with previous items
                        altSignatureForX86 = GetFullSignature(tempNode);
                    }
                }
            }

            lock (this.namesToInfos)
            {
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
        }
    }

    public class CrossArchInfo
    {
        public Architecture Arch { get; set; }

        public string FullSignature { get; set; }
    }
}

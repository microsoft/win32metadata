using System.Collections.Generic;
using System.IO;
using System.Text;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Windows.Win32.Interop;
using PartitionUtilsLib;

namespace ClangSharpSourceToWinmd
{
    public class CrossArchSyntaxMap
    {
        private Dictionary<string, List<CrossArchInfo>> namesToInfos = new Dictionary<string, List<CrossArchInfo>>();

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
            string treeFileName = tree.FilePath;
            if (treeFileName.EndsWith("autotypes.cs") || 
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

        public static CrossArchSyntaxMap LoadFromTrees(List<SyntaxTree> trees)
        {
            CrossArchSyntaxMap map = new CrossArchSyntaxMap();
            CrossArchSyntaxWalker walker = new CrossArchSyntaxWalker(map);
            foreach (var tree in trees)
            {
                walker.WalkTree(tree);
            }

            return map;
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

            // If the native type has a '/' it means it contains a path, which won't compare well
            // in a cloud build when different architectures are built on different agents. Just
            // return null in that case
            if (nativeType != null && nativeType.Contains('/'))
            {
                nativeType = null;
            }

            return nativeType;
        }

        private static string GetFullSignature(SyntaxNode node)
        {
            if (node is StructDeclarationSyntax s)
            {
                StringBuilder ret = new StringBuilder();
                if (s.AttributeLists != null)
                {
                    ret.Append(s.AttributeLists.ToString());
                }

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
                        var nativeType = GetNativeTypeForSignature(field.AttributeLists);
                        ret.Append(nativeType ?? field.Declaration.Type.ToString());
                        ret.Append(' ');
                        ret.Append(firstVar.ToString());
                    }
                }

                return ret.ToString();
            }
            else if (node is MethodDeclarationSyntax m)
            {
                StringBuilder ret = new StringBuilder();
                if (m.AttributeLists != null)
                {
                    ret.Append(m.AttributeLists.ToString());
                }

                ret.Append(m.ReturnType.ToString());
                ret.Append(' ');
                ret.Append(m.Identifier.ValueText);
                ret.Append('(');

                bool firstParam = true;
                foreach (var param in m.ParameterList.Parameters)
                {
                    if (firstParam)
                    {
                        firstParam = false;
                    }
                    else
                    {
                        ret.Append(',');
                    }

                    var nativeType = GetNativeTypeForSignature(param.AttributeLists);
                    ret.Append(nativeType ?? param.Type.ToString());
                    ret.Append(' ');
                    ret.Append(param.Identifier.ValueText);
                }

                ret.Append(')');

                return ret.ToString();
            }

            return node.ToString();
        }

        private void AddNode(Architecture arch, SyntaxNode node)
        {
            string name = SyntaxUtils.GetFullName(node, true);
            string fullSignature = GetFullSignature(node);
            if (!this.namesToInfos.TryGetValue(name, out var crossArchInfos))
            {
                crossArchInfos = new List<CrossArchInfo>();
                this.namesToInfos[name] = crossArchInfos;
            }

            foreach (var info in crossArchInfos)
            {
                if (info.FullSignature == fullSignature)
                {
                    info.Arch |= arch;
                    return;
                }
            }

            var newInfo = new CrossArchInfo() { Arch = arch, FullSignature = fullSignature };
            crossArchInfos.Add(newInfo);
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

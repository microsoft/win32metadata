using System;
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
    public class CrossArchTreeMerger
    {
        public static List<SyntaxTree> MergeTrees(CrossArchSyntaxMap map, List<SyntaxTree> trees)
        {
            List<SyntaxTree> ret = new List<SyntaxTree>();
            CrossArchTreeRewriter archTreeRewriter = new CrossArchTreeRewriter(map);
            foreach (var tree in trees)
            {
                var fixedTree = archTreeRewriter.ProcessTree(tree);

                if (fixedTree != null)
                {
                    ret.Add(fixedTree);
                }
            }

            return ret;
        }

        private class CrossArchTreeRewriter : CSharpSyntaxRewriter
        {
            private CrossArchSyntaxMap map;
            private Architecture currentArch;
            private HashSet<string> crossArchVisitedNames = new HashSet<string>();

            public CrossArchTreeRewriter(CrossArchSyntaxMap map)
            {
                this.map = map;
            }

            public SyntaxTree ProcessTree(SyntaxTree tree)
            {
                this.currentArch = CrossArchSyntaxMap.GetArchForTree(tree);

                if (Path.GetFileName(tree.FilePath) == "autotypes.cs" && this.currentArch != Architecture.X64)
                {
                    return null;
                }

                if (!CrossArchSyntaxMap.IsCrossArchTree(tree))
                {
                    return tree;
                }

                if (this.currentArch == Architecture.None)
                {
                    return tree;
                }

                var newRoot = (CSharpSyntaxNode)this.Visit(tree.GetRoot());

                return CSharpSyntaxTree.Create(newRoot, null, tree.FilePath);
            }

            public override SyntaxNode VisitEnumDeclaration(EnumDeclarationSyntax node)
            {
                if (this.currentArch != Architecture.X64)
                {
                    return null;
                }

                return base.VisitEnumDeclaration(node);
            }

            public override SyntaxNode VisitClassDeclaration(ClassDeclarationSyntax node)
            {
                node = (ClassDeclarationSyntax)base.VisitClassDeclaration(node);

                if (node.Identifier.ValueText == "Apis")
                {
                    if (!node.ChildNodes().Any())
                    {
                        return null;
                    }
                }

                return node;
            }

            public override SyntaxNode VisitFieldDeclaration(FieldDeclarationSyntax node)
            {
                var modifiers = node.Modifiers.ToString();

                // Get rid of constants on Apis classes when arch isn't x64
                if (this.currentArch != Architecture.X64 && 
                    (node.Parent is ClassDeclarationSyntax cDef && cDef.Identifier.ValueText == "Apis") &&
                    (modifiers.Contains("const") || modifiers.Contains("static")))
                {
                    return null;
                }

                return base.VisitFieldDeclaration(node);
            }

            public override SyntaxNode VisitStructDeclaration(StructDeclarationSyntax node)
            {
                node = (StructDeclarationSyntax)base.VisitStructDeclaration(node);

                if (CrossArchSyntaxMap.IsPotentialCrossArch(node))
                {
                    var originalName = node.Identifier.ValueText;
                    var name = originalName;

                    HandleArchSpecific(node, out var removeNode, out var attributeList, ref name);
                    
                    if (removeNode)
                    {
                        return null;
                    }

                    if (name != originalName)
                    {
                        node =
                            node.WithIdentifier(SyntaxFactory.ParseToken(name));
                    }

                    if (attributeList != null)
                    {
                        node = node.AddAttributeLists(attributeList);
                    }
                }

                return node;
            }

            public override SyntaxNode VisitDelegateDeclaration(DelegateDeclarationSyntax node)
            {
                node = (DelegateDeclarationSyntax)base.VisitDelegateDeclaration(node);

                if (CrossArchSyntaxMap.IsPotentialCrossArch(node))
                {
                    var originalName = node.Identifier.ValueText;
                    var name = originalName;
                    HandleArchSpecific(node, out var removeNode, out var attributeList, ref name);
                    if (removeNode)
                    {
                        return null;
                    }

                    if (name != originalName)
                    {
                        node =
                            node.WithIdentifier(SyntaxFactory.ParseToken(name));
                    }

                    if (attributeList != null)
                    {
                        node = node.AddAttributeLists(attributeList);
                    }
                }

                return node;
            }

            public override SyntaxNode VisitMethodDeclaration(MethodDeclarationSyntax node)
            {
                node = (MethodDeclarationSyntax)base.VisitMethodDeclaration(node);

                if (CrossArchSyntaxMap.IsPotentialCrossArch(node))
                {
                    var originalName = node.Identifier.ValueText;
                    var name = originalName;
                    HandleArchSpecific(node, out var removeNode, out var attributeList, ref name);
                    if (removeNode)
                    {
                        return null;
                    }

                    if (name != originalName)
                    {
                        node =
                            node.WithIdentifier(SyntaxFactory.ParseToken(name));
                    }

                    if (attributeList != null)
                    {
                        node = node.AddAttributeLists(attributeList);
                    }
                }

                return node;
            }

            private static string GetUniqueNameWithArches(string name, Architecture arch)
            {
                if (arch.HasFlag(Architecture.X64))
                {
                    name += "__x64__";
                }

                if (arch.HasFlag(Architecture.X86))
                {
                    name += "__x86__";
                }

                if (arch.HasFlag(Architecture.Arm64))
                {
                    name += "__ARM64__";
                }

                return name;
            }

            private static string FormatArch(Architecture arch)
            {
                StringBuilder ret = new StringBuilder();
                foreach (Architecture val in Enum.GetValues(typeof(Architecture)))
                {
                    if (val == Architecture.None || val == Architecture.All)
                    {
                        continue;
                    }

                    if (arch.HasFlag(val))
                    {
                        if (ret.Length != 0)
                        {
                            ret.Append(" | ");
                        }

                        ret.Append($"Windows.Win32.Interop.Architecture.{val}");
                    }
                }

                return ret.ToString();
            }

            private void HandleArchSpecific(SyntaxNode node, out bool removeNode, out AttributeListSyntax attributeList, ref string name)
            {
                var archGroupings = this.map.GetSignatureArchGroupings(node).ToArray();

                attributeList = null;
                removeNode = false;

                bool appliesToAll = archGroupings.Any(a => a == Architecture.All);

                if (appliesToAll)
                {
                    // Get rid of items that are common to all architectures if we're not on x64
                    removeNode = this.currentArch != Architecture.X64;
                    return;
                }

                for (int i = 0; i < archGroupings.Length; i++)
                {
                    var archGroup = archGroupings[i];

                    if (archGroup.HasFlag(this.currentArch))
                    {
                        var fullNameWithArch = GetFullNameWithArch(node, archGroup);

                        // If we've already visited it via another arch, get rid of this one
                        if (this.crossArchVisitedNames.Contains(fullNameWithArch))
                        {
                            removeNode = true;
                            return;
                        }

                        if (i != 0)
                        {
                            name = $"{name}____{i}";
                        }

                        string archValues = FormatArch(archGroup);
                        string attributeArgs = $"({archValues})";
                        attributeList =
                            SyntaxFactory.AttributeList(
                                SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                    SyntaxFactory.Attribute(
                                        SyntaxFactory.ParseName("SupportedArchitecture"),
                                        SyntaxFactory.ParseAttributeArgumentList(attributeArgs))));

                        this.crossArchVisitedNames.Add(fullNameWithArch);

                        return;
                    }
                }
            }

            private string GetFullNameWithArch(SyntaxNode node, Architecture arch)
            {
                return GetUniqueNameWithArches(SyntaxUtils.GetFullName(node, true), arch);
            }
        }
    }
}

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
    public class CrossArchTreeMerger
    {
        private readonly CrossArchSyntaxMap map;
        private readonly HashSet<string> crossArchVisitedNames = new HashSet<string>();
        private readonly HashSet<string> reservedIdentifiers;
        private readonly Dictionary<string, string> fieldRenames = new(StringComparer.Ordinal);
        private readonly Dictionary<string, string> recordFamilies = new(StringComparer.Ordinal);

        public CrossArchTreeMerger(CrossArchSyntaxMap map, IEnumerable<SyntaxTree> sourceTrees = null,
            IEnumerable<MetadataReference> references = null)
        {
            this.map = map;
            var trees = sourceTrees?.ToArray();
            map.BindCallbackReferences(trees, references);
            this.reservedIdentifiers = new HashSet<string>(map.GetSourceIdentifiers(), StringComparer.Ordinal);
            foreach (var tree in trees ?? Array.Empty<SyntaxTree>())
            {
                foreach (var token in tree.GetRoot().DescendantTokens().Where(token => token.IsKind(SyntaxKind.IdentifierToken)))
                    this.reservedIdentifiers.Add(token.ValueText);
                foreach (var declaration in tree.GetRoot().DescendantNodes().OfType<MemberDeclarationSyntax>())
                {
                    string name = declaration switch
                    {
                        BaseTypeDeclarationSyntax type => type.Identifier.ValueText,
                        DelegateDeclarationSyntax callback => callback.Identifier.ValueText,
                        MethodDeclarationSyntax method => method.Identifier.ValueText,
                        _ => null,
                    };
                    if (name != null)
                        for (int i = 1; i <= 2; i++)
                            this.reservedIdentifiers.Add($"{name}____{i}");
                }
            }
        }

        internal IReadOnlyDictionary<string, string> FieldRenames => this.fieldRenames;
        internal IReadOnlyDictionary<string, string> RecordFamilies => this.recordFamilies;

        private string RenameField(FieldDeclarationSyntax field, string originalName, int ordinal)
        {
            lock (this)
            {
                string candidate = $"{originalName}____{ordinal}";
                int collision = 0;
                while (!this.reservedIdentifiers.Add(candidate))
                    candidate = $"{originalName}____{ordinal}_{++collision}";
                string identity = CrossArchSyntaxMap.GetFullName(field);
                string renamedIdentity = identity.Substring(0, identity.LastIndexOf("::", StringComparison.Ordinal) + 2) + candidate;
                this.fieldRenames.Add(renamedIdentity, originalName);
                return candidate;
            }
        }

        public SyntaxTree ProcessTree(SyntaxTree tree, out bool contributedToNonCommonTree)
        {
            return CrossArchTreeRewriter.ProcessTree(this, tree, out contributedToNonCommonTree);
        }

        private class CrossArchTreeRewriter : CSharpSyntaxRewriter
        {
            private Architecture currentArch;
            private CrossArchTreeMerger owner;
            private bool contributedToNonCommonTree;

            private CrossArchTreeRewriter(CrossArchTreeMerger owner)
            {
                this.owner = owner;
            }

            public static SyntaxTree ProcessTree(CrossArchTreeMerger owner, SyntaxTree tree, out bool contributedToNonCommonTree)
            {
                CrossArchTreeRewriter treeWriter = new CrossArchTreeRewriter(owner);
                tree = treeWriter.ProcessTree(tree);
                contributedToNonCommonTree = treeWriter.contributedToNonCommonTree;
                return tree;
            }

            private SyntaxTree ProcessTree(SyntaxTree tree)
            {
                this.currentArch = CrossArchSyntaxMap.GetArchForTree(tree);

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

            public override SyntaxNode VisitIdentifierName(IdentifierNameSyntax node)
            {
                string name = this.owner.map.GetCallbackReference(node.SyntaxTree, this.currentArch, node.SpanStart);
                return name == null ? base.VisitIdentifierName(node) : SyntaxFactory.ParseName(name).WithTriviaFrom(node);
            }

            public override SyntaxNode VisitEnumDeclaration(EnumDeclarationSyntax node)
            {
                if (CrossArchSyntaxMap.IsPotentialCrossArch(node))
                {
                    string name = node.Identifier.ValueText;
                    this.HandleArchSpecific(node, out bool removeNode, out var attributes, ref name);
                    if (removeNode)
                        return null;
                    node = node.WithIdentifier(SyntaxFactory.Identifier(name));
                    if (attributes != null)
                        node = node.AddAttributeLists(attributes);
                }
                return base.VisitEnumDeclaration(node);
            }

            public override SyntaxNode VisitClassDeclaration(ClassDeclarationSyntax node)
            {
                bool hasVariantReferences = this.owner.map.HasCallbackDependencies(node.SyntaxTree.FilePath);
                node = (ClassDeclarationSyntax)base.VisitClassDeclaration(node);

                if (hasVariantReferences && node.Members.OfType<MethodDeclarationSyntax>().Any(CrossArchSyntaxMap.IsPotentialCrossArch) &&
                    !node.Modifiers.Any(SyntaxKind.PartialKeyword))
                {
                    node = node.AddModifiers(SyntaxFactory.Token(SyntaxKind.PartialKeyword).WithTrailingTrivia(SyntaxFactory.Space));
                }

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
                var original = node;
                node = (FieldDeclarationSyntax)base.VisitFieldDeclaration(node);
                if (CrossArchSyntaxMap.IsPotentialCrossArch(original))
                {
                    var variable = node.Declaration.Variables.First();
                    string name = variable.Identifier.ValueText;
                    this.HandleArchSpecific(original, out bool removeNode, out var attributes, ref name);
                    if (removeNode)
                        return null;
                    if (name != variable.Identifier.ValueText)
                        node = node.ReplaceNode(variable, variable.WithIdentifier(SyntaxFactory.Identifier(name)));
                    if (attributes != null)
                        node = node.AddAttributeLists(attributes);
                }

                return node;
            }

            public override SyntaxNode VisitStructDeclaration(StructDeclarationSyntax node)
            {
                var original = node;
                node = (StructDeclarationSyntax)base.VisitStructDeclaration(node);

                if (this.currentArch == Architecture.X86)
                {
                    node = this.owner.map.FixX86Struct(node, CrossArchSyntaxMap.GetFullName(original));
                }

                if (CrossArchSyntaxMap.IsPotentialCrossArch(original))
                {
                    var originalName = node.Identifier.ValueText;
                    var name = originalName;

                    this.HandleArchSpecific(original, out var removeNode, out var attributeList, ref name);
                    
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
                var original = node;
                node = (DelegateDeclarationSyntax)base.VisitDelegateDeclaration(node);

                if (CrossArchSyntaxMap.IsPotentialCrossArch(original))
                {
                    var originalName = node.Identifier.ValueText;
                    var name = originalName;
                    this.HandleArchSpecific(original, out var removeNode, out var attributeList, ref name);
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
                var original = node;
                node = (MethodDeclarationSyntax)base.VisitMethodDeclaration(node);

                if (CrossArchSyntaxMap.IsPotentialCrossArch(original))
                {
                    var originalName = node.Identifier.ValueText;
                    var name = originalName;
                    this.HandleArchSpecific(original, out var removeNode, out var attributeList, ref name);
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

                        ret.Append($"global::Windows.Win32.Foundation.Metadata.Architecture.{val}");
                    }
                }

                return ret.ToString();
            }

            private void HandleArchSpecific(SyntaxNode node, out bool removeNode, out AttributeListSyntax attributeList, ref string name)
            {
                var archGroupings = this.owner.map.GetSignatureArchGroupings(node).ToArray();

                attributeList = null;
                removeNode = false;

                bool appliesToAll = archGroupings.Any(a => a == Architecture.All);

                if (appliesToAll)
                {
                    // Get rid of items that are common to all architectures if we're not on x86
                    removeNode = this.currentArch != Architecture.X86;
                    return;
                }

                for (int i = 0; i < archGroupings.Length; i++)
                {
                    var archGroup = archGroupings[i];

                    if (archGroup.HasFlag(this.currentArch))
                    {
                        this.contributedToNonCommonTree = true;

                        var fullNameWithArch = this.GetFullNameWithArch(node, archGroup);
                        string provider = this.owner.map.GetCallbackProviderKey(node);
                        string visitKey = provider.Length == 0 ? fullNameWithArch : fullNameWithArch + "\0" + provider;

                        lock (this.owner)
                        {
                            // If we've already visited it via another arch, get rid of this one
                            if (this.owner.crossArchVisitedNames.Contains(visitKey))
                            {
                                removeNode = true;
                                return;
                            }

                            this.owner.crossArchVisitedNames.Add(visitKey);
                        }

                        if (i != 0)
                        {
                            name = node is FieldDeclarationSyntax field
                                ? this.owner.RenameField(field, name, i)
                                : $"{name}____{i}";
                        }

                        if (node is StructDeclarationSyntax && node.Parent is BaseNamespaceDeclarationSyntax)
                        {
                            string ns = SyntaxUtils.GetEnclosingNamespace(node);
                            string identity = "global::" + (ns.Length == 0 ? name : ns + "." + name);
                            string family = CrossArchSyntaxMap.GetFullName(node);
                            lock (this.owner)
                            {
                                if (this.owner.recordFamilies.TryGetValue(identity, out string previous) && previous != family)
                                    throw new System.IO.InvalidDataException($"Conflicting generated record families for '{identity}'.");
                                this.owner.recordFamilies[identity] = family;
                            }
                        }

                        string archValues = FormatArch(archGroup);
                        string attributeArgs = $"({archValues})";
                        attributeList =
                            SyntaxFactory.AttributeList(
                                SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                    SyntaxFactory.Attribute(
                                        SyntaxFactory.ParseName("global::Windows.Win32.Foundation.Metadata.SupportedArchitecture"),
                                        SyntaxFactory.ParseAttributeArgumentList(attributeArgs))));

                        return;
                    }
                }
            }

            private string GetFullNameWithArch(SyntaxNode node, Architecture arch)
            {
                return GetUniqueNameWithArches(CrossArchSyntaxMap.GetFullName(node), arch);
            }
        }
    }
}

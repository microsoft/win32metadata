using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using MetadataUtils;
using System.Xml.Linq;

namespace ClangSharpSourceToWinmd
{
    public static class MetadataSyntaxTreeCleaner
    {
        public const string ArgListVarName = "__arglist__";
        internal const string RevertToTypeSuffix = "___";

        internal static bool IsEnumMemberConstant(FieldDeclarationSyntax node, ISet<string> enumMemberNames)
            => node.Modifiers.ToString() == "public const" &&
                (enumMemberNames.Contains(node.Declaration.Variables.First().Identifier.ValueText) ||
                enumMemberNames.Contains(GetEnumMemberIdentity(node, node.Declaration.Variables.First().Identifier.ValueText)));

        internal static bool IsLegacyManualSource(string path)
            => path.EndsWith(".manual.cs", StringComparison.OrdinalIgnoreCase) ||
                path.EndsWith(".manual.modified.cs", StringComparison.OrdinalIgnoreCase);

        internal static string GetEnumMemberIdentity(SyntaxNode node, string name)
        {
            string ns = string.Join(".", node.Ancestors().OfType<BaseNamespaceDeclarationSyntax>()
                .Reverse().Select(declaration => declaration.Name.ToString()));
            var owners = node.Ancestors().OfType<TypeDeclarationSyntax>()
                .Where(owner => owner is not ClassDeclarationSyntax type || type.Identifier.ValueText != "Apis")
                .Reverse().Select(owner => owner.Identifier.ValueText).Append(name);
            return (ns.Length == 0 ? "" : ns + "::") + string.Join("::", owners);
        }

        public static SyntaxTree CleanSyntaxTree(SyntaxTree tree, Dictionary<string, string> remaps, Dictionary<string, Dictionary<string, string>> enumAdditions, HashSet<string> enumsMakeFlags, Dictionary<string, string> requiredNamespaces, Dictionary<string, string> staticLibs, Dictionary<string, string> apiNamesToNamespaces, HashSet<string> nonEmptyStructs, HashSet<string> enumMemberNames, string filePath, bool nativeFieldArrayInfo = false, GenerationValidation validation = null)
        {
            bool ownsValidation = validation == null;
            validation ??= new GenerationValidation();
            TreeRewriter treeRewriter = new TreeRewriter(remaps, enumAdditions, enumsMakeFlags, requiredNamespaces, staticLibs, apiNamesToNamespaces, nonEmptyStructs, enumMemberNames, nativeFieldArrayInfo, validation, filePath);
            var newRoot = (CSharpSyntaxNode)treeRewriter.Visit(tree.GetRoot());
            newRoot = NativeMemberNameProvenance.Project(newRoot);
            var ret = CSharpSyntaxTree.Create(newRoot, null, filePath);
            if (ownsValidation)
                validation.ThrowIfAny();
            return ret;
        }

        private sealed class SourceValidationException : InvalidOperationException
        {
            internal SourceValidationException(string message) : base(message) { }
        }

        private class TreeRewriter : CSharpSyntaxRewriter
        {
            private static readonly Regex NativeTypeNameArrayRegex = new Regex(@"\[\s*(\d+)\s*\]$");
            private static readonly Regex ElementCountRegex = new Regex(@"(?:elementCount|byteCount)\((?:_Old_\()?([^\)]+)\)+");
            private static readonly Regex IsRegex = new Regex(@"[^\w::]");
            private static readonly Regex ParameterOverrideRegex = new Regex(@"^Win32Metadata\.(Optional|ComOutPtr)\((true|false)\)$");

            private HashSet<SyntaxNode> nodesWithMarshalAs = new HashSet<SyntaxNode>();
            private Dictionary<string, string> remaps;
            private Dictionary<Regex, string> regexRemaps = new Dictionary<Regex, string>();
            private Dictionary<string, Dictionary<string, string>> enumAdditions;
            private Dictionary<string, string> requiredNamespaces;
            private Dictionary<string, string> staticLibs;
            private Dictionary<string, string> apiNamesToNamespaces;
            private HashSet<string> visitedDelegateNames = new HashSet<string>();
            private HashSet<string> visitedStaticMethodNames = new HashSet<string>();
            private HashSet<string> nonEmptyStructs;
            private HashSet<string> enumMemberNames;
            private HashSet<string> enumsToMakeFlags;
            private HashSet<string> usingNamespaces = new HashSet<string>();
            private readonly bool nativeFieldArrayInfo;
            private readonly GenerationValidation validation;
            private readonly string filePath;

            public TreeRewriter(Dictionary<string, string> remaps, Dictionary<string, Dictionary<string, string>> enumAdditions, HashSet<string> enumsToMakeFlags, Dictionary<string, string> requiredNamespaces, Dictionary<string, string> staticLibs, Dictionary<string, string> apiNamesToNamespaces, HashSet<string> nonEmptyStructs, HashSet<string> enumMemberNames, bool nativeFieldArrayInfo, GenerationValidation validation, string filePath)
            {
                this.validation = validation;
                this.filePath = filePath;
                this.remaps = remaps;
                this.InitRegexRemaps();

                this.enumAdditions = enumAdditions;
                this.requiredNamespaces = requiredNamespaces;
                this.staticLibs = staticLibs;
                this.apiNamesToNamespaces = apiNamesToNamespaces;
                this.nonEmptyStructs = nonEmptyStructs;
                this.enumMemberNames = enumMemberNames;
                this.enumsToMakeFlags = enumsToMakeFlags;
                this.nativeFieldArrayInfo = nativeFieldArrayInfo;
            }

            public override SyntaxNode Visit(SyntaxNode node)
            {
                try
                {
                    return base.Visit(node);
                }
                catch (SourceValidationException error) when (node is MemberDeclarationSyntax or ParameterSyntax)
                {
                    string symbol = node switch
                    {
                        MethodDeclarationSyntax method => method.Identifier.ValueText,
                        ParameterSyntax parameter => parameter.Identifier.ValueText,
                        FieldDeclarationSyntax field => string.Join(", ", field.Declaration.Variables
                            .Select(variable => variable.Identifier.ValueText)),
                        _ => node.Kind().ToString(),
                    };
                    this.validation.Add(error, "WMA002", "emitter.source-cleaning", this.filePath, symbol,
                        line: node.GetLocation().GetLineSpan().StartLinePosition.Line + 1,
                        architecture: ClangSharpSourceCompilation.GetArchitectureForFileName(this.filePath).ToString());
                    return node;
                }
            }

            private void InitRegexRemaps()
            {
                foreach (var pair in this.remaps)
                {
                    if (IsRegex.IsMatch(pair.Key))
                    {
                        this.regexRemaps[new Regex(pair.Key)] = pair.Value;
                    }
                }
            }

            public override SyntaxNode VisitCompilationUnit(CompilationUnitSyntax node)
            {
                var ret = (CompilationUnitSyntax)base.VisitCompilationUnit(node);

                // Add any namespaces we might need due to remappings
                var newUsings = new List<UsingDirectiveSyntax>();
                foreach (var remapNamespace in this.requiredNamespaces.Values.Distinct())
                {
                    if (!this.usingNamespaces.Contains(remapNamespace))
                    {
                        newUsings.Add(SyntaxFactory.UsingDirective(SyntaxFactory.ParseName(remapNamespace)).NormalizeWhitespace().WithTrailingTrivia(SyntaxFactory.CarriageReturnLineFeed));
                    }
                }

                if (newUsings.Count != 0)
                {
                    ret = ret.AddUsings(newUsings.ToArray());
                }

                return ret;
            }

            public override SyntaxNode VisitUsingDirective(UsingDirectiveSyntax node)
            {
                this.usingNamespaces.Add(node.Name.ToString());
                return base.VisitUsingDirective(node);
            }

            private static SyntaxList<AttributeListSyntax> FixRemappedAttributes(
                SyntaxList<AttributeListSyntax> existingAttrList,
                List<AttributeSyntax> remappedListAttributes)
            {
                return FixRemappedAttributes(existingAttrList, remappedListAttributes, null);
            }

            private static SyntaxList<AttributeListSyntax> FixRemappedAttributes(
                SyntaxList<AttributeListSyntax> existingAttrList,
                List<AttributeSyntax> remappedListAttributes,
                AttributeTargetSpecifierSyntax target)
            {
                if (remappedListAttributes == null)
                {
                    return existingAttrList;
                }

                foreach (var attrNode in remappedListAttributes)
                {
                    var attrName = attrNode.Name.ToString();
                    bool remove = attrName.EndsWith(EncodeHelpers.AttributeToRemoveSuffix);
                    string semanticName = GetAttributeName(attrNode);
                    if (remove)
                    {
                        semanticName = semanticName[..^EncodeHelpers.AttributeToRemoveSuffix.Length];
                        if (semanticName.EndsWith("Attribute", StringComparison.Ordinal))
                            semanticName = semanticName[..^"Attribute".Length];
                    }
                    var headerAttributes = existingAttrList
                        .Where(list => list.Target?.Identifier.ValueText == target?.Identifier.ValueText)
                        .SelectMany(list => list.Attributes)
                        .Where(attribute => IsHeaderAttribute(attribute) && GetAttributeName(attribute) == semanticName)
                        .ToArray();
                    if (headerAttributes.Length != 0)
                    {
                        if (remove || !headerAttributes.Any(attribute =>
                            NormalizeAttributeArguments(attribute) == NormalizeAttributeArguments(attrNode)))
                            throw new SourceValidationException($"WMA002: Legacy remapping '{attrNode}' conflicts with header annotation '{headerAttributes[0]}'.");
                        continue;
                    }
                    if (attrName.EndsWith(EncodeHelpers.AttributeToRemoveSuffix))
                    {
                        existingAttrList = RemoveTargetAttributes(existingAttrList, semanticName, target);
                    }
                    else
                    {
                        // Remove any existing attribute with the same name
                        existingAttrList = RemoveTargetAttributes(existingAttrList, GetAttributeName(attrNode), target);

                        var attrListNode =
                            SyntaxFactory.AttributeList(
                                SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(attrNode));
                        if (target != null)
                        {
                            attrListNode = attrListNode.WithTarget(target);
                        }

                        existingAttrList = existingAttrList.Add(attrListNode);
                    }
                }

                return existingAttrList;
            }

            private static string GetAttributeName(AttributeSyntax attribute)
            {
                string name = attribute.Name.ToString().Split('.').Last().Replace("global::", string.Empty);
                return name.EndsWith("Attribute", StringComparison.Ordinal) ? name[..^"Attribute".Length] : name;
            }

            private static bool IsHeaderAttribute(AttributeSyntax attribute)
                => attribute.Name.ToString().StartsWith("global::Windows.Win32.Foundation.Metadata.", StringComparison.Ordinal) ||
                    attribute.Name.ToString() is "global::System.Runtime.InteropServices.PreserveSig" or "global::System.Flags";

            private static string NormalizeAttributeArguments(AttributeSyntax attribute)
                => new AttributeLiteralNormalizer().Visit(attribute.ArgumentList)?.NormalizeWhitespace().ToString();

            private static SyntaxList<AttributeListSyntax> RemoveTargetAttributes(
                SyntaxList<AttributeListSyntax> lists, string name, AttributeTargetSpecifierSyntax target)
                => SyntaxFactory.List(lists.Select(list =>
                    list.Target?.Identifier.ValueText == target?.Identifier.ValueText
                        ? list.WithAttributes(SyntaxFactory.SeparatedList(list.Attributes.Where(attribute => GetAttributeName(attribute) != name)))
                        : list).Where(list => list.Attributes.Count != 0));

            private sealed class AttributeLiteralNormalizer : CSharpSyntaxRewriter
            {
                public override SyntaxNode VisitLiteralExpression(LiteralExpressionSyntax node)
                {
                    if (node.IsKind(SyntaxKind.StringLiteralExpression))
                        return node.WithToken(SyntaxFactory.Literal(node.Token.ValueText));
                    if (node.IsKind(SyntaxKind.NumericLiteralExpression) &&
                        node.Token.Value is byte or sbyte or short or ushort or int or uint or long or ulong)
                        return SyntaxFactory.ParseExpression(Convert.ToDecimal(node.Token.Value, System.Globalization.CultureInfo.InvariantCulture)
                            .ToString(System.Globalization.CultureInfo.InvariantCulture));
                    return base.VisitLiteralExpression(node);
                }
            }

            public override SyntaxNode VisitParameter(ParameterSyntax node)
            {
                if (node.Identifier.Text == "__arglist")
                {
                    // Special case __arglist to give it the type of "object" and a name we'll recognize in the emitter.
                    // Otherwise the compilation will fail if __arglist is found in any delegates
                    return node
                        .WithIdentifier(SyntaxFactory.Identifier(ArgListVarName))
                        .WithTrailingTrivia(SyntaxFactory.Space)
                        .WithType(SyntaxFactory.ParseTypeName("object")
                        .WithTrailingTrivia(SyntaxFactory.Space));
                }

                string fullName = GetFullNameWithoutArchSuffix(node);
                var overrides = new Dictionary<string, bool>(StringComparer.Ordinal);
                foreach (var attribute in node.AttributeLists.SelectMany(list => list.Attributes))
                {
                    if (TryReadParameterOverride(attribute, out string name, out bool enabled) && !overrides.TryAdd(name, enabled))
                        throw new SourceValidationException($"WMA001: Duplicate '{name}' parameter override on '{fullName}'.");
                }
                this.GetRemapInfo(fullName, node.AttributeLists, out var listAttributes, node.Type.ToString(), out string newType, out string newName);
                node = (ParameterSyntax)base.VisitParameter(node);
                foreach (var pair in overrides)
                {
                    if (listAttributes != null)
                    {
                        listAttributes = listAttributes.Where(attribute =>
                        {
                            string name = attribute.Name.ToString();
                            bool remove = name.EndsWith(EncodeHelpers.AttributeToRemoveSuffix, StringComparison.Ordinal);
                            if (remove)
                                name = name[..^EncodeHelpers.AttributeToRemoveSuffix.Length];
                            if (!IsParameterMetadataAttribute(name, pair.Key))
                                return true;
                            if (pair.Value == remove)
                                throw new SourceValidationException($"WMA002: Legacy remapping '{attribute}' conflicts with header parameter override '{pair.Key}({pair.Value.ToString().ToLowerInvariant()})' on '{fullName}'.");
                            return false;
                        }).ToList();
                    }
                    if (pair.Key == "ComOutPtr" && !pair.Value &&
                        node.AttributeLists.SelectMany(list => list.Attributes)
                            .Any(attribute => IsParameterMetadataAttribute(attribute.Name.ToString(), "ComOutPtr")) &&
                        !node.AttributeLists.SelectMany(list => list.Attributes)
                            .Any(attribute => IsParameterMetadataAttribute(attribute.Name.ToString(), "Out")))
                    {
                        // Keep the Out flag the emitter otherwise derives from ComOutPtr.
                        node = node.AddAttributeLists(SyntaxFactory.AttributeList(SyntaxFactory.SingletonSeparatedList(
                            SyntaxFactory.Attribute(SyntaxFactory.ParseName("global::System.Runtime.InteropServices.Out")))));
                    }
                    node = node.WithAttributeLists(SyntaxFactory.List(node.AttributeLists.Select(list =>
                        list.WithAttributes(SyntaxFactory.SeparatedList(list.Attributes.Where(attribute =>
                            pair.Value || !IsParameterMetadataAttribute(attribute.Name.ToString(), pair.Key)))))
                        .Where(list => list.Attributes.Count != 0)));
                    if (pair.Value && !node.AttributeLists.SelectMany(list => list.Attributes)
                        .Any(attribute => IsParameterMetadataAttribute(attribute.Name.ToString(), pair.Key)))
                    {
                        string name = pair.Key == "Optional" ? "global::System.Runtime.InteropServices.Optional" :
                            "global::Windows.Win32.Foundation.Metadata.ComOutPtr";
                        node = node.AddAttributeLists(SyntaxFactory.AttributeList(SyntaxFactory.SingletonSeparatedList(
                            SyntaxFactory.Attribute(SyntaxFactory.ParseName(name)))));
                    }
                }
                node = node.WithAttributeLists(FixRemappedAttributes(node.AttributeLists, listAttributes));
                if (newName != null)
                    node = node.WithIdentifier(SyntaxFactory.Identifier(newName));
                if (newType != null)
                    node = node.WithType(SyntaxFactory.ParseTypeName(newType).WithTrailingTrivia(SyntaxFactory.Space));

                // Get rid of default parameter values
                if (node.Default != null)
                {
                    node = node.WithDefault(null);
                }

                return node;
            }

            private static bool TryReadParameterOverride(AttributeSyntax attribute, out string name, out bool enabled)
            {
                name = null;
                enabled = false;
                if (GetAttributeName(attribute) != "NativeAnnotation" ||
                    attribute.ArgumentList?.Arguments.FirstOrDefault()?.Expression is not LiteralExpressionSyntax literal ||
                    !literal.IsKind(SyntaxKind.StringLiteralExpression))
                    return false;
                string payload = literal.Token.ValueText;
                if (!payload.StartsWith("Win32Metadata.Optional", StringComparison.Ordinal) &&
                    !payload.StartsWith("Win32Metadata.ComOutPtr", StringComparison.Ordinal))
                    return false;
                var match = ParameterOverrideRegex.Match(payload);
                if (attribute.ArgumentList.Arguments.Count != 1 || !match.Success)
                    throw new SourceValidationException($"WMA001: Malformed parameter override '{payload}'; expected Optional(true|false) or ComOutPtr(true|false).");
                name = match.Groups[1].Value;
                enabled = match.Groups[2].Value == "true";
                return true;
            }

            private static bool IsParameterMetadataAttribute(string name, string semanticName)
            {
                name = name.Replace("global::", string.Empty, StringComparison.Ordinal);
                if (name.EndsWith("Attribute", StringComparison.Ordinal))
                    name = name[..^"Attribute".Length];
                string qualified = semanticName is "Optional" or "Out" ? "System.Runtime.InteropServices." + semanticName :
                    "Windows.Win32.Foundation.Metadata.ComOutPtr";
                return name == semanticName || name == qualified;
            }

            public override SyntaxNode VisitStructDeclaration(StructDeclarationSyntax node)
            {
                // If the struct is empty and we found a non-empty struct in all the source files, delete it
                if (SyntaxUtils.IsEmptyStruct(node) && this.nonEmptyStructs.Contains(node.Identifier.ValueText))
                {
                    return null;
                }

                // Authored forward declarations can acquire an ordinary generated definition.
                if (IsLegacyManualSource(node.SyntaxTree.FilePath) &&
                    node.SemicolonToken.IsKind(SyntaxKind.SemicolonToken) &&
                    !node.Modifiers.Any(SyntaxKind.PartialKeyword))
                {
                    node = node.AddModifiers(SyntaxFactory.Token(SyntaxKind.PartialKeyword)
                        .WithTrailingTrivia(SyntaxFactory.Space));
                }

                string name = node.Identifier.Text;
                string fullName = GetFullNameWithoutArchSuffix(node);

                // Add Ansi or Unicode attributes to -A/-W APIs.
                if ((name.EndsWith("A") && this.apiNamesToNamespaces.ContainsKey($"{name[0..^1]}W")) ||
                   (!name.EndsWith("W") && this.apiNamesToNamespaces.ContainsKey($"{name}W")))
                {
                    var attributeList = SyntaxFactory.AttributeList(
                            SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                SyntaxFactory.Attribute(
                                    SyntaxFactory.ParseName("Ansi"))));

                    node = node.AddAttributeLists(attributeList);
                }
                else if (name.EndsWith("W") && (this.apiNamesToNamespaces.ContainsKey($"{name[0..^1]}A") || this.apiNamesToNamespaces.ContainsKey($"{name[0..^1]}")))
                {
                    var attributeList = SyntaxFactory.AttributeList(
                            SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                SyntaxFactory.Attribute(
                                    SyntaxFactory.ParseName("Unicode"))));

                    node = node.AddAttributeLists(attributeList);
                }

                foreach (var member in node.Members)
                {
                    if (!(member is FieldDeclarationSyntax))
                    {
                        continue;
                    }

                    var fieldName = ((FieldDeclarationSyntax)member).Declaration.Variables[0].Identifier.Value.ToString();
                    if (fieldName == "cbSize")
                    {
                        var attributeList = SyntaxFactory.AttributeList(
                                SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                    SyntaxFactory.Attribute(
                                        SyntaxFactory.ParseName("StructSizeField"),
                                        SyntaxFactory.ParseAttributeArgumentList($"(\"{fieldName}\")"))));

                        node = node.AddAttributeLists(attributeList);
                    }
                }

                if (this.GetRemapInfo(fullName, node.AttributeLists, out var listAttributes, null, out _, out string newName))
                {
                    node = (StructDeclarationSyntax)base.VisitStructDeclaration(node);
                    node = node.WithAttributeLists(FixRemappedAttributes(node.AttributeLists, listAttributes));

                    if (newName != null)
                    {
                        node = node.WithIdentifier(SyntaxFactory.Identifier(newName));
                    }
                }
                else
                {
                    node = (StructDeclarationSyntax)base.VisitStructDeclaration(node);
                }

                return node;
            }

            public override SyntaxNode VisitFieldDeclaration(FieldDeclarationSyntax node)
            {
                const string ForceConstPrefix = "__forceconst__";

                string localName = node.Declaration.Variables.First().Identifier.ValueText;

                // If it's a constant, ignore it if it's already part of an enum
                if (IsEnumMemberConstant(node, this.enumMemberNames))
                {
                    return null;
                }

                string fullName = GetFullNameWithoutArchSuffix(node);

                this.GetRemapInfo(fullName, node.AttributeLists, out var listAttributes, node.Declaration.Type.ToString(), out string newType, out string newName);

                // ClangSharp mistakenly emits string[] for WCHAR[] Foo = "Bar".
                // Change it to string
                if (newType == null && node.Declaration.Type.ToString() == "string[]")
                {
                    newType = "string";
                }

                // We will turn static strings into constants
                if (node.Modifiers.ToString() == "public static" && node.Declaration.Type.ToString() == "string")
                {
                    var newModifiers =
                        SyntaxFactory.TokenList(
                            SyntaxFactory.Token(SyntaxKind.PublicKeyword).WithTrailingTrivia(SyntaxFactory.Space),
                            SyntaxFactory.Token(SyntaxKind.ConstKeyword).WithTrailingTrivia(SyntaxFactory.Space));

                    node = node.WithModifiers(newModifiers).WithLeadingTrivia(node.GetLeadingTrivia());

                    return base.VisitFieldDeclaration(node);
                }

                if (node.Modifiers.ToString() == "public static readonly")
                {
                    // Turn public static readonly Guids into string constants with an attribute
                    // to signal language projections to turn them into Guid constants. Guid constants 
                    // aren't allowed in metadata, requiring us to surface them this way
                    if (node.Declaration.Type.ToString() == "Guid")
                    {
                        var varInitializer = node.Declaration.Variables.First().Initializer;
                        if (varInitializer.Value is ObjectCreationExpressionSyntax objCreationSyntax)
                        {
                            node = node.RemoveNode(varInitializer, SyntaxRemoveOptions.KeepExteriorTrivia | SyntaxRemoveOptions.KeepEndOfLine);

                            var args = objCreationSyntax.ArgumentList.Arguments;
                            if (args.Count == 11)
                            {
                                var allArgs = $"(uint){args}";

                                string argsFormatted = $"({allArgs})";
                                var attrsList =
                                    SyntaxFactory.AttributeList(
                                        SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                            SyntaxFactory.Attribute(
                                                SyntaxFactory.ParseName(EncodeHelpers.GuidAttributeName),
                                                SyntaxFactory.ParseAttributeArgumentList(argsFormatted))));

                                node = node.AddAttributeLists(attrsList).WithLeadingTrivia(node.GetLeadingTrivia());
                            }
                            else if (objCreationSyntax.ArgumentList.Arguments.Count == 1)
                            {
                                var textValue = EncodeHelpers.RemoveQuotes(objCreationSyntax.ArgumentList.Arguments[0].ToString());

                                // If this is an invalid format, remove the node
                                if (!Guid.TryParse(textValue, out var guidVal))
                                {
                                    return null;
                                }

                                node = node.AddAttributeLists(EncodeHelpers.ConvertGuidToAttributeList(guidVal).WithLeadingTrivia(node.GetLeadingTrivia()));
                            }
                        }

                        return base.VisitFieldDeclaration(node);
                    }
                    // Some constants get scraped as public static readonly.
                    // If we see the prefix, force it to be a const
                    else if (localName.StartsWith(ForceConstPrefix))
                    {
                        var newModifiers =
                            SyntaxFactory.TokenList(
                                SyntaxFactory.Token(SyntaxKind.PublicKeyword).WithTrailingTrivia(SyntaxFactory.Space),
                                SyntaxFactory.Token(SyntaxKind.ConstKeyword).WithTrailingTrivia(SyntaxFactory.Space));

                        node = node.WithModifiers(newModifiers).WithLeadingTrivia(node.GetLeadingTrivia());

                        var variable = node.Declaration.Variables.First();
                        variable = variable.WithIdentifier(SyntaxFactory.ParseToken(localName.Substring(ForceConstPrefix.Length)));
                        node = node.WithDeclaration(node.Declaration.WithVariables(SyntaxFactory.SingletonSeparatedList(variable)));

                        return base.VisitFieldDeclaration(node);
                    }
                }

                // Assume [0] or [1] (ANYSIZE_ARRAY) at the end of a struct indicates flexible arrays and add the FlexibleArray attribute.
                // Parse NativeTypeName instead of the field declaration to support scenarios like arrays of structs which aren't scraped as arrays.
                var nativeTypeName = SyntaxUtils.GetNativeTypeNameFromAttributesLists(node.AttributeLists);
                if (nativeTypeName != null)
                {
                    var match = NativeTypeNameArrayRegex.Match(nativeTypeName);
                    if (match.Success && match.Groups[1].Value == "0" || match.Groups[1].Value == "1")
                    {
                        if (node.ToString() == (node.Parent as StructDeclarationSyntax).Members.Where(m => m is FieldDeclarationSyntax).Last().ToString())
                        {
                            var attributeList = SyntaxFactory.AttributeList(
                                    SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                        SyntaxFactory.Attribute(
                                            SyntaxFactory.ParseName("FlexibleArray"))));

                            node = node.AddAttributeLists(attributeList);
                        }
                    }
                }

                node = (FieldDeclarationSyntax)base.VisitFieldDeclaration(node);
                node = node.WithAttributeLists(FixRemappedAttributes(node.AttributeLists, listAttributes));

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
                var attributes = new List<AttributeSyntax>();
                foreach (var attribute in node.Attributes)
                {
                    var result = this.ProcessAttribute(node, attribute) as AttributeListSyntax;
                    if (result != null)
                        attributes.AddRange(result.Attributes);
                }
                return attributes.Count == 0 ? null : node.WithAttributes(SyntaxFactory.SeparatedList(attributes));
            }

            private SyntaxNode ProcessAttribute(AttributeListSyntax node, AttributeSyntax firstAttr)
            {
                var attrName = firstAttr.Name.ToString();

                if (TryReadParameterOverride(firstAttr, out _, out _))
                {
                    if (node.Parent is not ParameterSyntax || node.Target?.Identifier.ValueText is not (null or "param"))
                        throw new SourceValidationException("WMA001: Optional/ComOutPtr overrides are valid only on parameters.");
                    return null;
                }

                if ((attrName is "SupportedOSPlatform" or "SupportedOSPlatformAttribute" or
                    "Windows.Win32.Foundation.Metadata.SupportedOSPlatform" or
                    "Windows.Win32.Foundation.Metadata.SupportedOSPlatformAttribute") &&
                    node.Parent.ChildNodes().OfType<AttributeListSyntax>()
                        .Where(list => list.Target?.Identifier.ValueText == node.Target?.Identifier.ValueText)
                        .SelectMany(list => list.Attributes)
                        .Any(attribute => (attribute.Name.ToString() is
                            "global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform" or
                            "global::Windows.Win32.Foundation.Metadata.SupportedOSPlatformAttribute") &&
                            NormalizeAttributeArguments(attribute) == NormalizeAttributeArguments(firstAttr)))
                    return null;

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

                        // We don't want these for parameters or fields
                        if (node.Parent is ParameterSyntax || node.Parent is FieldDeclarationSyntax)
                        {
                            return null;
                        }

                        // We don't want these for interface methods
                        if (node.Parent is MethodDeclarationSyntax && node.Parent.Parent is StructDeclarationSyntax)
                        {
                            return null;
                        }

                        break;
                    }

                    case "Guid":
                    {
                        return this.ProcessGuidAttr(firstAttr);
                    }

                    case "UnmanagedFunctionPointer":
                    {
                        // ClangSharp can emit this attribute with no arguments.
                        // The typedef we're using of this attribute has no such ctor,
                        // so emit one that does, using WinApi as the default calling convention.
                        // Also, convert StdCall to Winapi
                        if (firstAttr.ArgumentList == null || firstAttr.ArgumentList.ToString() == "(CallingConvention.StdCall)")
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
                        bool alreadyConst =
                            (node.Parent is FieldDeclarationSyntax parentField &&
                             (parentField.Modifiers.Any(m => m.ToString() == "const") ||
                              parentField.AttributeLists.SelectMany(list => list.Attributes)
                                  .Any(attribute => GetAttributeName(attribute) == "Guid"))) ||
                            node.Parent.ChildNodes().OfType<AttributeListSyntax>()
                                .Where(list => list.Target?.Identifier.ValueText == node.Target?.Identifier.ValueText)
                                .SelectMany(list => list.Attributes)
                                .Any(attribute => GetAttributeName(attribute) == "Const");

                        var ret = this.ProcessNativeTypeNameAttr(alreadyConst, firstAttr);

                        return ret ?? SyntaxFactory.AttributeList(SyntaxFactory.SingletonSeparatedList(firstAttr));
                    }

                    case "NativeAnnotation":
                    {
                        return null;
                    }

                    case "CppAttributeList":
                    {
                        return this.CreateAttributeListForSal(node, firstAttr);
                    }
                }

                return SyntaxFactory.AttributeList(SyntaxFactory.SingletonSeparatedList(firstAttr));
            }

            public override SyntaxNode VisitEnumDeclaration(EnumDeclarationSyntax node)
            {
                node = (EnumDeclarationSyntax)base.VisitEnumDeclaration(node);

                var enumName = node.Identifier.ValueText;
                if (this.GetRemapInfo(enumName, node.AttributeLists, out var listAttributes, null, out _, out _))
                {
                    node = node.WithAttributeLists(FixRemappedAttributes(node.AttributeLists, listAttributes));
                }

                if (this.enumAdditions.TryGetValue(enumName, out var additionsList))
                {
                    List<EnumMemberDeclarationSyntax> newMembers = new List<EnumMemberDeclarationSyntax>();
                    foreach (var additionPair in additionsList)
                    {
                        var member =
                            SyntaxFactory.EnumMemberDeclaration(additionPair.Key)
                                .WithEqualsValue(
                                    SyntaxFactory.EqualsValueClause(
                                        SyntaxFactory.ParseExpression(additionPair.Value)));
                        newMembers.Add(member);
                    }

                    node = node.AddMembers(newMembers.ToArray());
                }

                if (this.enumsToMakeFlags.Contains(enumName))
                {
                    bool hasFlags = node.AttributeLists.SelectMany(list => list.Attributes).Any(attribute => GetAttributeName(attribute) == "Flags");
                    if (!hasFlags)
                    {
                        node =
                            node.AddAttributeLists(
                                SyntaxFactory.AttributeList(
                                    SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                        SyntaxFactory.Attribute(SyntaxFactory.ParseName("global::System.Flags")))).WithLeadingTrivia(node.GetLeadingTrivia()));
                    }
                }

                return node;
            }

            public override SyntaxNode VisitEnumMemberDeclaration(EnumMemberDeclarationSyntax node)
            {
                string fullName = GetFullNameWithoutArchSuffix(node);

                this.GetRemapInfo(fullName, node.AttributeLists, out var listAttributes, string.Empty, out string newType, out string newName);

                node = (EnumMemberDeclarationSyntax)base.VisitEnumMemberDeclaration(node);
                node = node.WithAttributeLists(FixRemappedAttributes(node.AttributeLists, listAttributes));

                return node;
            }

            public override SyntaxNode VisitDelegateDeclaration(DelegateDeclarationSyntax node)
            {
                string name = node.Identifier.Text;
                string fullName = SyntaxUtils.GetFullName(node);
                string fixedName = GetFullNameWithoutArchSuffix(node);

                // Remove duplicate delegates in this tree
                if (this.visitedDelegateNames.Contains(fullName))
                {
                    return null;
                }

                this.visitedDelegateNames.Add(fullName);

                // Add Ansi or Unicode attributes to -A/-W APIs.
                if ((name.EndsWith("A") && this.apiNamesToNamespaces.ContainsKey($"{name[0..^1]}W")) ||
                   (!name.EndsWith("W") && this.apiNamesToNamespaces.ContainsKey($"{name}W")))
                {
                    var attributeList = SyntaxFactory.AttributeList(
                            SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                SyntaxFactory.Attribute(
                                    SyntaxFactory.ParseName("Ansi"))));

                    node = node.AddAttributeLists(attributeList);
                }
                else if (name.EndsWith("W") && (this.apiNamesToNamespaces.ContainsKey($"{name[0..^1]}A") || this.apiNamesToNamespaces.ContainsKey($"{name[0..^1]}")))
                {
                    var attributeList = SyntaxFactory.AttributeList(
                            SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                SyntaxFactory.Attribute(
                                    SyntaxFactory.ParseName("Unicode"))));

                    node = node.AddAttributeLists(attributeList);
                }

                string returnFullName = $"{fixedName}::return";

                if (this.GetRemapInfo(returnFullName, node.AttributeLists, out var listAttributes, node.ReturnType.ToString(), out var newType, out _))
                {
                    node = (DelegateDeclarationSyntax)base.VisitDelegateDeclaration(node);

                    var target = SyntaxFactory.AttributeTargetSpecifier(SyntaxFactory.Token(SyntaxKind.ReturnKeyword));
                    node = node.WithAttributeLists(FixRemappedAttributes(node.AttributeLists, listAttributes, target));

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
                var dllImportAttr = SyntaxUtils.GetAttribute(node.AttributeLists, "DllImport");
                string dllName = dllImportAttr?.ArgumentList.Arguments[0].ToString();

                // Trim the leading and trailing quotes.
                dllName = dllName?.Substring(1, dllName.Length - 2);

                // Skip methods where we weren't given an import lib name. Should we warn the caller?
                if (dllImportAttr != null && string.IsNullOrEmpty(dllName))
                {
                    return null;
                }

                string name = node.Identifier.Text;
                string fullName = SyntaxUtils.GetFullName(node);
                string fixedFullName = GetFullNameWithoutArchSuffix(node);

                // Remove duplicate static methods
                if (node.Body == null)
                {
                    // If this function is supposed to be in a certain namespace, remove it if it's not.
                    // We only respect this for static methods
                    if (this.requiredNamespaces.TryGetValue(fixedFullName, out var requiredNamespace))
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

                var isInterface = node.Parent is StructDeclarationSyntax;

                node = (MethodDeclarationSyntax)base.VisitMethodDeclaration(node);

                // Add Ansi or Unicode attributes to -A/-W APIs.
                if ((name.EndsWith("A") && this.apiNamesToNamespaces.ContainsKey($"{name[0..^1]}W")) ||
                   (!name.EndsWith("W") && this.apiNamesToNamespaces.ContainsKey($"{name}W") && !isInterface))
                {
                    var attributeList = SyntaxFactory.AttributeList(
                            SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                SyntaxFactory.Attribute(
                                    SyntaxFactory.ParseName("Ansi"))));

                    node = node.AddAttributeLists(attributeList);
                }
                else if (name.EndsWith("W") && (this.apiNamesToNamespaces.ContainsKey($"{name[0..^1]}A") || this.apiNamesToNamespaces.ContainsKey($"{name[0..^1]}")))
                {
                    var attributeList = SyntaxFactory.AttributeList(
                            SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                                SyntaxFactory.Attribute(
                                    SyntaxFactory.ParseName("Unicode"))));

                    node = node.AddAttributeLists(attributeList);
                }

                // Add the StaticLibrary attribute if one was specified for this DLL.
                if (!string.IsNullOrEmpty(dllName) && this.staticLibs.TryGetValue(dllName, out string staticLib))
                {
                    var attrListNode = SyntaxFactory.AttributeList(
                        SyntaxFactory.SingletonSeparatedList<AttributeSyntax>(
                            SyntaxFactory.Attribute(SyntaxFactory.ParseName("StaticLibrary"),
                            SyntaxFactory.ParseAttributeArgumentList($"(\"{staticLib}\")"))));

                    node = node.WithAttributeLists(node.AttributeLists.Add(attrListNode));
                }

                // See if there are any attributes directly on the method
                if (this.GetRemapInfo(fullName, node.AttributeLists, out var methodAttributes, null, out _, out _))
                {
                    node = node.WithAttributeLists(FixRemappedAttributes(node.AttributeLists, methodAttributes));
                }

                string returnFullName = $"{fixedFullName}::return";
                string nodeReturnType = node.ReturnType.ToString();

                // Find remap info for the return parameter for this method and apply any that we find
                if (this.GetRemapInfo(returnFullName, node.AttributeLists, out var listAttributes, nodeReturnType, out var newType, out _))
                {
                    var target = SyntaxFactory.AttributeTargetSpecifier(SyntaxFactory.Token(SyntaxKind.ReturnKeyword));
                    node = node.WithAttributeLists(FixRemappedAttributes(node.AttributeLists, listAttributes, target));

                    if (newType != null)
                    {
                        node = node.WithReturnType(SyntaxFactory.ParseTypeName(newType).WithTrailingTrivia(SyntaxFactory.Space));
                    }
                }

                return node;
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

            private static string GetFullNameWithoutArchSuffix(SyntaxNode node)
            {
                string ret = SyntaxUtils.GetFullName(node);

                ret = ret.Replace("____1", string.Empty);
                ret = ret.Replace("____2", string.Empty);

                return ret;
            }

            private string GetInfoForNativeType(string nativeTypeName, out bool isConst, out bool isNullTerminated, out bool isNullNullTerminated)
            {
                string metadataType = null;
                isConst = false;
                isNullTerminated = false;
                isNullNullTerminated = false;

                if (this.remaps.TryGetValue(nativeTypeName, out var attrs))
                {
                    if (attrs.Contains("[Const]"))
                    {
                        isConst = true;
                    }
                }

                switch (nativeTypeName)
                {
                    case "LPCGUID":
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
                        if (nativeTypeName.StartsWith("const ") || Regex.IsMatch(nativeTypeName, "^L?PCW?STR"))
                        {
                            isConst = true;
                        }

                        break;
                }

                return metadataType;
            }

            private void AddNativeArrayInfoAttribute(bool alreadyConst, string nativeTypeName, List<AttributeSyntax> attrsList)
            {
                if (string.IsNullOrWhiteSpace(nativeTypeName))
                {
                    return;
                }

                var metadataType = this.GetInfoForNativeType(nativeTypeName, out bool isConst, out bool isNullTerminated, out bool isNullNullTerminated);

                if (isConst && !alreadyConst)
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

            private SyntaxNode ProcessNativeTypeNameAttr(bool alreadyConst, AttributeSyntax nativeTypeNameAttr)
            {
                string nativeType = nativeTypeNameAttr.ArgumentList.Arguments[0].ToString();
                nativeType = EncodeHelpers.RemoveQuotes(nativeType);

                List<AttributeSyntax> attributeNodes = new List<AttributeSyntax>();

                this.AddNativeArrayInfoAttribute(alreadyConst, nativeType, attributeNodes);
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

            private SyntaxNode CreateAttributeListForSal(AttributeListSyntax cppAttrList, AttributeSyntax cppAttr)
            {
                if (this.nativeFieldArrayInfo && cppAttrList.Parent is FieldDeclarationSyntax fieldNode)
                {
                    return this.CreateAttributeListForFieldSal(fieldNode, cppAttr);
                }

                if (cppAttrList.Parent is not ParameterSyntax paramNode)
                {
                    return null;
                }

                bool marshalAsAdded = this.nodesWithMarshalAs.Contains(paramNode);

                List<AttributeSyntax> attributesList = new List<AttributeSyntax>();

                string nativeArrayInfoParams = null;
                bool isIn = false;
                bool isOut = false;
                bool isOpt = false;
                bool isReserved = false;
                bool isComOutPtr = false;
                bool isRetVal = false;
                bool isNullNullTerminated;
                bool isByteBuffer = false;
                bool? pre = null;
                bool? post = null;

                var salAttrs = GetSalAttributes(cppAttr);
                isNullNullTerminated = salAttrs.Any(a => a.Name == "SAL_name" && a.P1 == "_NullNull_terminated_");

                foreach (var salAttr in salAttrs)
                {
                    if (salAttr.Name == "SAL_name")
                    {
                        if (salAttr.P1.StartsWith("__RPC__"))
                        {
                            // TODO: Handle ecount, xcount and others that deal with counts
                            bool deref = false;

                            string[] parts = salAttr.P1.Split('_');
                            foreach (var part in parts)
                            {
                                switch (part)
                                {
                                    case "deref":
                                        deref = true;
                                        break;

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
                                        // As per rpcsal.h, deref_opt means input optional but deref_***_opt doesn't
                                        if (deref && (isIn || isOut))
                                        {
                                            continue;
                                        }

                                        isOpt = true;
                                        break;
                                }
                            }

                            break;
                        }
                        else if (salAttr.P1 == "_Maybenull_" || salAttr.P1 == "_Pre_maybenull_" || salAttr.P1 == "_Pre_null_")
                        {
                            isIn = true;
                            isOpt = true;

                            continue;
                        }

                        if (salAttr.P1.Contains("_opt"))
                        {
                            isOpt = true;
                        }

                        if (salAttr.P1.StartsWith("_COM_Outptr"))
                        {
                            isComOutPtr = true;
                            continue;
                        }
                        else if (salAttr.P1.StartsWith("_Outptr_") && !isComOutPtr)
                        {
                            isOut = true;
                            isByteBuffer = salAttr.P1.Contains("bytebuffer");
                            continue;
                        }
                        else if (salAttr.P1 == "_Reserved_")
                        {
                            isReserved = true;
                            continue;
                        }
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
                if (!marshalAsAdded && !isByteBuffer)
                {
                    foreach (var salAttr in salAttrs.Where(attr => attr.Name == "SAL_writableTo" || attr.Name == "SAL_readableTo"))
                    {
                        nativeArrayInfoParams = GetArrayMarshalAsFromP1(paramNode, salAttr.P1);
                        if (!string.IsNullOrEmpty(nativeArrayInfoParams))
                        {
                            marshalAsAdded = true;
                            break;
                        }
                    }
                }

                var nativeTypeName = SyntaxUtils.GetNativeTypeNameFromAttributesLists((cppAttrList.Parent as ParameterSyntax).AttributeLists);
                if (!string.IsNullOrEmpty(nativeArrayInfoParams))
                {
                    var attrName = SyntaxFactory.ParseName(nativeArrayInfoParams.Contains("BytesParamIndex") ? "MemorySize" : "NativeArrayInfo");
                    var args = SyntaxFactory.ParseAttributeArgumentList(nativeArrayInfoParams.ToString());
                    var finalAttr = SyntaxFactory.Attribute(attrName, args);
                    attributesList.Add(finalAttr);
                }
                else if (nativeTypeName != null)
                {
                    var match = NativeTypeNameArrayRegex.Match(nativeTypeName);
                    if (match.Success)
                    {
                        var size = Convert.ToUInt32(match.Groups[1].Value);

                        // Don't bother marking this as an array if it has 1 or less
                        if (size > 1)
                        {
                            var attrName = SyntaxFactory.ParseName("NativeArrayInfo");
                            var args = SyntaxFactory.ParseAttributeArgumentList($"(CountConst = {size})");
                            attributesList.Add(SyntaxFactory.Attribute(attrName, args));
                        }
                    }
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

                if (isReserved)
                {
                    attributesList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("Reserved")));
                }

                if (isOpt || isReserved)
                {
                    attributesList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("Optional")));
                }

                if (isNullNullTerminated)
                {
                    attributesList.Add(SyntaxFactory.Attribute(SyntaxFactory.ParseName("NullNullTerminated")));
                }

                if (isRetVal && !paramNode.AttributeLists.SelectMany(list => list.Attributes)
                    .Any(attribute => GetAttributeName(attribute) == "RetVal"))
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
                    var match = ElementCountRegex.Match(p1Text);
                    StringBuilder ret = new StringBuilder("(");

                    if (match.Success)
                    {
                        string sizeOrParamName = match.Groups[1].Value;
                        if (int.TryParse(sizeOrParamName, out int size))
                        {
                            // Don't bother marking this as an array if it has 1 or less
                            if (size <= 1)
                            {
                                return string.Empty;
                            }

                            if (ret.Length != 1)
                            {
                                ret.Append(", ");
                            }

                            ret.Append($"CountConst = {size}");
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

                                    string propName = p1Text.StartsWith("elementCount") ? "CountParamIndex" : "BytesParamIndex";
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

            }

            private SyntaxNode CreateAttributeListForFieldSal(FieldDeclarationSyntax fieldNode, AttributeSyntax cppAttr)
            {
                if (fieldNode.Parent is not TypeDeclarationSyntax containingType)
                {
                    return null;
                }

                string nativeTypeName = SyntaxUtils.GetNativeTypeNameFromAttributesLists(fieldNode.AttributeLists);
                if (fieldNode.Declaration.Type is not PointerTypeSyntax and not ArrayTypeSyntax
                    && (nativeTypeName == null || !NativeTypeNameArrayRegex.IsMatch(nativeTypeName)))
                {
                    return null;
                }

                var cppAttributes = fieldNode.AttributeLists.SelectMany(list => list.Attributes)
                    .Where(attribute => GetAttributeName(attribute) == "CppAttributeList").ToArray();
                if (cppAttributes[0] != cppAttr)
                {
                    return null;
                }

                AttributeSyntax arrayInfo = null;
                foreach (var salAttr in cppAttributes.SelectMany(GetSalAttributes))
                {
                    if (salAttr.Name != "SAL_readableTo" && salAttr.Name != "SAL_writableTo")
                    {
                        continue;
                    }

                    string countExpression = salAttr.P1;
                    if (countExpression == null || !countExpression.StartsWith("elementCount(", StringComparison.Ordinal))
                    {
                        continue;
                    }

                    var match = ElementCountRegex.Match(countExpression);
                    string count = match.Success && match.Length == countExpression.Length
                        && !countExpression.StartsWith("elementCount(_Old_(", StringComparison.Ordinal)
                        ? match.Groups[1].Value.Trim()
                        : null;
                    AttributeArgumentSyntax argument = null;
                    if (int.TryParse(count, out int size) && size >= 0)
                    {
                        argument = SyntaxFactory.AttributeArgument(
                            SyntaxFactory.LiteralExpression(SyntaxKind.NumericLiteralExpression, SyntaxFactory.Literal(size)))
                            .WithNameEquals(SyntaxFactory.NameEquals("CountConst"));
                    }
                    else
                    {
                        var countField = containingType.Members.OfType<FieldDeclarationSyntax>()
                            .FirstOrDefault(field => !field.Modifiers.Any(SyntaxKind.StaticKeyword)
                                && !field.Modifiers.Any(SyntaxKind.ConstKeyword)
                                && field.Declaration.Variables.Count == 1
                                && field.Declaration.Variables[0].Identifier.ValueText == count);
                        if (countField != null)
                        {
                            this.GetRemapInfo(GetFullNameWithoutArchSuffix(countField), countField.AttributeLists,
                                out _, countField.Declaration.Type.ToString(), out _, out string newName);
                            string countFieldName = newName ?? NativeMemberNameProvenance.GetProjectedFieldName(countField, count);
                            argument = SyntaxFactory.AttributeArgument(
                                SyntaxFactory.LiteralExpression(SyntaxKind.StringLiteralExpression, SyntaxFactory.Literal(countFieldName)))
                                .WithNameEquals(SyntaxFactory.NameEquals("CountFieldName"));
                        }
                    }

                    if (argument == null)
                    {
                        ReportUnsupportedCount(countExpression);
                        return null;
                    }

                    var attribute = SyntaxFactory.Attribute(SyntaxFactory.ParseName("NativeArrayInfo"),
                        SyntaxFactory.AttributeArgumentList(SyntaxFactory.SingletonSeparatedList(argument)));
                    if (arrayInfo != null && NormalizeAttributeArguments(arrayInfo) != NormalizeAttributeArguments(attribute))
                    {
                        ReportUnsupportedCount("multiple distinct element counts");
                        return null;
                    }

                    arrayInfo = attribute;
                }

                if (arrayInfo == null)
                {
                    return null;
                }

                var existing = fieldNode.AttributeLists.SelectMany(list => list.Attributes)
                    .Where(attribute => GetAttributeName(attribute) == "NativeArrayInfo").ToArray();
                if (existing.Length != 0)
                {
                    if (existing.All(attribute => NormalizeAttributeArguments(attribute) == NormalizeAttributeArguments(arrayInfo)))
                    {
                        return null;
                    }

                    throw new SourceValidationException($"WMA002: Native SAL array count on '{GetFullNameWithoutArchSuffix(fieldNode)}' conflicts with '{existing[0]}'.");
                }

                return SyntaxFactory.AttributeList(SyntaxFactory.SingletonSeparatedList(arrayInfo));

                void ReportUnsupportedCount(string expression)
                {
                    Console.WriteLine($"ClangSharpSourceToWinmd : warning CSSW002: Cannot represent native SAL element count '{expression}' on field '{GetFullNameWithoutArchSuffix(fieldNode)}'.");
                }
            }

            private static IEnumerable<SalAttribute> GetSalAttributes(AttributeSyntax cppAttr)
            {
                string salText = cppAttr.ArgumentList.Arguments[0].ToString();
                salText = salText.Substring(1, salText.Length - 2);

                foreach (var attr in salText.Split('^'))
                {
                    yield return SalAttribute.CreateFromCppAttribute(attr);
                }
            }

            private string GetRemapData(string fullName)
            {
                if (string.IsNullOrEmpty(fullName))
                {
                    return null;
                }

                string remapData = null;

                if (this.remaps.TryGetValue(fullName, out var remap))
                {
                    remapData += remap;
                }

                foreach (var pair in this.regexRemaps)
                {
                    if (pair.Key.IsMatch(fullName))
                    {
                        remapData += pair.Value;
                    }
                }

                return remapData;
            }

            private bool GetRemapInfo(string fullName, SyntaxList<AttributeListSyntax> existingAttrList, out List<AttributeSyntax> listAttributes, string currentType, out string newType, out string newName)
            {
                listAttributes = null;
                newType = null;
                newName = null;

                bool ret = false;
                string remapData = this.GetRemapData(fullName);
                if (!string.IsNullOrEmpty(remapData))
                {
                    ret = EncodeHelpers.DecodeRemap(remapData, out listAttributes, out newType, out newName);
                    if (newType != null)
                    {
                        // Try to keep the pointers at the same level if we're replacing
                        // a uint or int. The mismatch can happen in the auto-generated
                        // enum remaps which don't know if the params/fields getting replaced
                        // are pointers or not
                        if (currentType != null && (currentType.StartsWith("uint") || currentType.StartsWith("int") || currentType.StartsWith("short") || currentType.StartsWith("ushort")))
                        {
                            int starIndex = currentType.IndexOf('*');
                            if (starIndex != -1 && newType.IndexOf('*') == -1)
                            {
                                newType += currentType.Substring(starIndex);
                            }
                        }

                        // Add NativeTypeName attribute if it is missing 
                        bool hasNativeTypeName = false;

                        foreach (var attrList in existingAttrList.ToArray())
                        {
                            foreach (var attr in attrList.Attributes)
                            {
                                var attrName = attr.Name.ToString();
                                if (attrName == "NativeTypeName")
                                {
                                    hasNativeTypeName = true;
                                }
                            }
                        }

                        if (!hasNativeTypeName && !(currentType.Contains("IUnknown**")) && !(currentType.Contains("IInspectable**")))
                        {
                            var newCurrentType = "(\"" + currentType + "\")";
                            newCurrentType = newCurrentType.ToUpper();

                            var attrNameNode = SyntaxFactory.ParseName("NativeTypeName");
                            var argsNode = !string.IsNullOrEmpty(currentType) ? SyntaxFactory.ParseAttributeArgumentList(newCurrentType) : null;
                            var newNode = SyntaxFactory.Attribute(attrNameNode, argsNode);

                            if (listAttributes == null)
                            {
                                listAttributes = new List<AttributeSyntax>();
                            }

                            listAttributes.Add(newNode);
                        }
                    }
                }

                if (newType == null && currentType != null)
                {
                    // See if the type ends in the magic suffix. We use a remap fed to clangsharp 
                    // to keep some typedefs from following down to their original type
                    EncodeHelpers.SplitType(currentType, out var typeOnly, out var pointers);
                    if (typeOnly.EndsWith(RevertToTypeSuffix))
                    {
                        newType = typeOnly.Substring(0, typeOnly.Length - RevertToTypeSuffix.Length) + pointers;
                        ret = true;
                    }
                }

                return ret;
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
                    var nameAndValue = part.Split('=', 2);
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

using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Text.RegularExpressions;
using ClangSharp;
using ClangSharp.Interop;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace Win32MetadataScraper
{
    internal sealed class HeaderAnnotationProcessor
    {
        private const string MetadataNamespace = "global::Windows.Win32.Foundation.Metadata.";
        private const string CleanupReferencePrefix = HeaderAnnotation.OwnerPrefix + "FunctionDecl:";
        private readonly Dictionary<NamedDecl, DeclarationFacts> declarations = new();
        private readonly Dictionary<(string File, uint Line, uint Column), List<DeclarationFacts>> projectionLocations = new();
        private readonly Dictionary<string, string> remaps;
        private IReadOnlyDictionary<string, string> storageTypeRemaps;
        private readonly List<DeclarationFacts> annotatedTypedefs = new();
        private readonly HashSet<NamedDecl> projectedDeclarations = new();
        private readonly string generatedNamespace;
        private readonly IReadOnlyList<string> traversalNames;
        private readonly ISet<string> excludedNames;
        private readonly bool excludeFunctionsWithBody;
        private readonly Dictionary<TypedefNameDecl, TypedefNameDecl> callbackOrigins = new();
        private readonly Dictionary<TypedefNameDecl, DelegateDeclarationSyntax> callbackTemplates = new();
        private readonly List<(CXCursor Declaration, NativeLocation Location)> enumAssociations = new();
        private readonly HashSet<CXCursor> enumReferenceCarriers = new();
        private readonly List<(VarDecl Declaration, Attr Target)> methodCarriers = new();
        private readonly List<(VarDecl Declaration, Attr Target)> parameterCarriers = new();
        private readonly List<(VarDecl Declaration, Attr Target)> fieldCarriers = new();
        private readonly HashSet<Cursor> visited = new();
        private readonly List<(NamedDecl Owner, string Name, string[] Arguments, NativeLocation Location)> cleanupReferences = new();

        internal IEnumerable<string> AnnotationCarrierNames => methodCarriers.Concat(parameterCarriers).Concat(fieldCarriers)
            .Select(carrier => carrier.Declaration.Name);

        internal HeaderAnnotationProcessor(TranslationUnit translationUnit, Dictionary<string, string> remaps, string generatedNamespace,
            IReadOnlyList<string> traversalNames, ISet<string> excludedNames, bool excludeFunctionsWithBody)
        {
            this.remaps = remaps;
            storageTypeRemaps = remaps;
            this.generatedNamespace = generatedNamespace;
            this.traversalNames = traversalNames;
            this.excludedNames = excludedNames;
            this.excludeFunctionsWithBody = excludeFunctionsWithBody;
            Walk(translationUnit.TranslationUnitDecl);
            ApplyMethodAnnotations();
            ApplyParameterAnnotations();
            ApplyFieldAnnotations();
            ResolveCleanupReferences();
            MergeRedeclarationFacts();
            foreach (var association in enumAssociations)
                if (association.Declaration.Kind != CXCursorKind.CXCursor_EnumDecl &&
                    !declarations.Values.Any(facts => facts.LogicalEnumMembers != null &&
                        facts.Declaration.Handle.CanonicalCursor == association.Declaration.CanonicalCursor))
                    throw Error(association.Location, "AssociatedEnum requires a native enum or a _Win32_Enum_/_Win32_FlagsEnum_ group.");
            TransferRecordTypedefFacts();
            foreach (var facts in declarations.Values)
            {
                // Match ClangSharp's GetFileLocation transport, including macro arguments.
                facts.Declaration.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
                var location = (file.ToString(), line, column);
                if (!projectionLocations.TryGetValue(location, out var candidates))
                    projectionLocations[location] = candidates = new();
                candidates.Add(facts);
            }
        }

        internal void PrepareTypedefs()
        {
            foreach (var facts in annotatedTypedefs)
            {
                var alias = (TypedefNameDecl)facts.Declaration;
                if (facts.LogicalEnumMembers != null)
                    continue;
                bool primaryRecord = alias.UnderlyingType.CanonicalType is RecordType record && Remap(record.Decl.Name) == Remap(alias.Name);
                if ((GetFunctionType(alias.UnderlyingType) == null || alias is TypeAliasDecl) && !primaryRecord)
                    remaps.TryAdd(alias.Name, alias.Name);
            }
        }

        private static unsafe bool IsForwardEnumReference(EnumDecl declaration)
        {
            declaration = declaration.Definition ?? declaration;
            if (declaration.Enumerators.Count != 0)
                return false;
            var cursor = declaration.Handle;
            var translationUnit = cursor.TranslationUnit;
            var tokens = translationUnit.Tokenize(cursor.Extent);
            try
            {
                // MSVC enum forwards have an assumed integer type, even without a definition.
                if (tokens.Length != 2)
                    return false;
                using var keyword = clang.getTokenSpelling(translationUnit, tokens[0]);
                using var name = clang.getTokenSpelling(translationUnit, tokens[1]);
                return keyword.ToString() == "enum" && name.ToString() == declaration.Name;
            }
            finally
            {
                translationUnit.DisposeTokens(tokens);
            }
        }

        private HeaderAnnotation ReadAnnotation(Attr attribute, DeclarationFacts facts, NamedDecl owner, NativeLocation location)
        {
            string payload = HeaderAnnotation.RemoveOwnerPrefix(attribute.Spelling);
            var arguments = attribute.CursorChildren.ToArray();
            if (payload == "RAIIFree")
            {
                if (arguments.Length == 0)
                    throw Error(location, "RAIIFree requires a cleanup function and optional integral constant arguments.");
                bool deferred = UnwrapArgument(arguments[0]) is StringLiteral;
                string cleanup;
                if (deferred)
                {
                    string reference = ReadStringArgument(arguments[0], location);
                    if (!reference.StartsWith(CleanupReferencePrefix, StringComparison.Ordinal))
                        throw Error(location, "RAIIFree requires a native cleanup function reference, not an untagged string.");
                    cleanup = reference[CleanupReferencePrefix.Length..].Trim();
                    while (cleanup.StartsWith("(", StringComparison.Ordinal) && cleanup.EndsWith(")", StringComparison.Ordinal))
                        cleanup = cleanup[1..^1].Trim();
                    cleanup = Regex.Replace(cleanup, @"\s*::\s*", "::");
                    if (!Regex.IsMatch(cleanup, @"^(?:::)?[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*$"))
                        throw Error(location, "RAIIFree requires a native cleanup function name.");
                }
                else
                    cleanup = ReadCleanupReference(arguments[0], location).Spelling.ToString();
                var values = arguments.Skip(1).Select(argument => ReadInteger(argument, location)).ToArray();
                facts.InvalidValues.AddRange(values.Select(value => unchecked((long)value)));
                var annotationArguments = new[] { cleanup }
                    .Concat(facts.InvalidValues.Select(value => value.ToString(CultureInfo.InvariantCulture))).ToArray();
                if (deferred)
                    cleanupReferences.Add((owner, cleanup, annotationArguments, location));
                return new HeaderAnnotation("RAIIFree", annotationArguments);
            }
            if (payload == "ImportLibrary")
            {
                if (arguments.Length is < 1 or > 2)
                    throw Error(location, "ImportLibrary requires a module string and optional export-name string or ordinal.");
                var values = new List<string> { HeaderAnnotation.Quote(ReadStringArgument(arguments[0], location)) };
                if (arguments.Length == 2)
                {
                    string entryPoint;
                    if (UnwrapArgument(arguments[1]) is StringLiteral)
                        entryPoint = ReadStringArgument(arguments[1], location);
                    else
                    {
                        ulong ordinal = ReadInteger(arguments[1], location);
                        if (ordinal is < 1 or > ushort.MaxValue)
                            throw Error(location, "An import ordinal must be between 1 and 65535.");
                        entryPoint = "#" + ordinal.ToString(CultureInfo.InvariantCulture);
                    }
                    values.Add(HeaderAnnotation.Quote(entryPoint));
                }
                return HeaderAnnotation.Parse("ImportLibrary(" + string.Join(",", values) + ")");
            }
            if (payload == "AssociatedEnum")
            {
                if (arguments.Length != 1)
                    throw Error(location, "AssociatedEnum requires one enum or metadata group type.");
                var declaration = clang.getTypeDeclaration(arguments[0].Handle.Type);
                if (declaration.IsNull)
                    throw Error(location, "AssociatedEnum requires a named native enum or metadata group type.");
                if (arguments[0] is Expr expression && expression.Type.CanonicalType is EnumType nativeEnum)
                {
                    declaration = nativeEnum.Decl.Handle;
                    if (IsForwardEnumReference(nativeEnum.Decl))
                        enumReferenceCarriers.Add(declaration.CanonicalCursor);
                }
                enumAssociations.Add((declaration, location));
                return new HeaderAnnotation("AssociatedEnum", new[] { Remap(declaration.Spelling.ToString()) });
            }
            var annotation = HeaderAnnotation.Parse(payload);
            if (annotation.Name is "Enum" or "FlagsEnum")
            {
                if (facts.Declaration is not TypedefNameDecl alias || !IsEnumStorage(alias.UnderlyingType.CanonicalType.Kind))
                    throw Error(location, "Enum groups require an integral typedef storage type of at most 64 bits.");
                if (arguments.Length != annotation.Arguments.Count)
                    throw Error(location, "An enum group requires exactly one compiled value for each member name.");
                if (facts.LogicalEnumMembers != null && facts.IsFlagsEnum != (annotation.Name == "FlagsEnum"))
                    throw Error(location, $"Conflicting enum group kinds on '{facts.Declaration.Name}'.");
                string storage = GetManagedType(alias.UnderlyingType, location);
                ulong mask = ulong.MaxValue >> checked((8 - (int)alias.UnderlyingType.CanonicalType.Handle.SizeOf) * 8);
                var members = annotation.Arguments.Zip(arguments, (name, argument) =>
                {
                    ulong value = ReadInteger(argument, location);
                    return new LogicalEnumMember(name, $"unchecked(({storage}){value.ToString(CultureInfo.InvariantCulture)}UL)", value & mask);
                }).ToArray();
                facts.LogicalEnumMembers = MergeEnumMembers(facts.LogicalEnumMembers, members, location);
                facts.IsFlagsEnum = annotation.Name == "FlagsEnum";
            }
            else if (arguments.Length != 0 || annotation.Name is "RAIIFree" or "ImportLibrary" or "AssociatedEnum")
                throw Error(location, $"'{annotation.Name}' requires compiler-parsed annotation arguments; include win32metadata_annotations.h.");
            return annotation;
        }

        private static Cursor UnwrapArgument(Cursor argument)
        {
            while (argument.CursorKind is CXCursorKind.CXCursor_UnexposedExpr or CXCursorKind.CXCursor_ParenExpr)
            {
                var children = argument.CursorChildren.ToArray();
                if (children.Length != 1)
                    break;
                argument = children[0];
            }
            return argument;
        }

        private static CXCursor ReadCleanupReference(Cursor argument, NativeLocation location)
            => ReadDeclarationReference(argument, CXCursorKind.CXCursor_FunctionDecl, location,
                "RAIIFree requires a reference to a declared native cleanup function.");

        private void ResolveCleanupReferences()
        {
            if (cleanupReferences.Count == 0)
                return;
            var named = visited.OfType<NamedDecl>().Where(declaration => declaration.SemanticParentCursor != null &&
                (declaration is ParmVarDecl || declaration.SemanticParentCursor is not FunctionDecl)).ToArray();
            var declarationsByScope = named.Where(declaration => declaration.Name.Length != 0)
                .ToLookup(declaration =>
                {
                    Cursor scope = declaration.SemanticParentCursor;
                    if (declaration is EnumConstantDecl && scope is EnumDecl enumeration && !enumeration.IsScoped)
                        scope = enumeration.SemanticParentCursor;
                    return (scope.Handle.CanonicalCursor, declaration.Name);
                });
            var records = new Dictionary<CXCursor, CXXRecordDecl>();
            foreach (var record in named.OfType<CXXRecordDecl>())
                records.TryAdd(record.Handle.CanonicalCursor, record);
            var namespaceImports = named.OfType<UsingDirectiveDecl>()
                .ToLookup(declaration => declaration.SemanticParentCursor.Handle.CanonicalCursor);
            var implicitNamespaces = named.OfType<NamespaceDecl>()
                .Where(declaration => declaration.IsInline || declaration.IsAnonymousNamespace)
                .ToLookup(declaration => declaration.SemanticParentCursor.Handle.CanonicalCursor);
            foreach (var reference in cleanupReferences)
            {
                bool absolute = reference.Name.StartsWith("::", StringComparison.Ordinal);
                string[] parts = (absolute ? reference.Name[2..] : reference.Name)
                    .Split(new[] { "::" }, StringSplitOptions.None);
                Cursor scope = absolute ? reference.Owner.TranslationUnitDecl : reference.Owner.SemanticParentCursor;
                NamedDecl[] candidates = Array.Empty<NamedDecl>();
                while (scope != null)
                {
                    candidates = Lookup(scope.Handle.CanonicalCursor, parts[0]);
                    if (candidates.Length != 0 || absolute)
                        break;
                    scope = scope.SemanticParentCursor;
                }
                foreach (string part in parts.Skip(1))
                {
                    candidates = candidates.Where(declaration => declaration is NamespaceDecl or RecordDecl)
                        .SelectMany(declaration => Lookup(declaration.Handle.CanonicalCursor, part))
                        .ToArray();
                }
                candidates = candidates.GroupBy(declaration => declaration.Handle.CanonicalCursor)
                    .Select(group => group.First()).ToArray();
                if (candidates.Length != 1 || candidates[0].Handle.Kind != CXCursorKind.CXCursor_FunctionDecl)
                    throw Error(reference.Location, $"RAIIFree cleanup '{reference.Name}' must identify one declared native cleanup function; found {candidates.Length} candidates.");
                reference.Arguments[0] = candidates[0].Name;
            }

            NamedDecl[] Lookup(CXCursor scope, string name)
            {
                var candidates = new List<NamedDecl>();
                var searched = new HashSet<CXCursor>();
                var scopes = new Stack<CXCursor>();
                scopes.Push(scope);
                while (scopes.TryPop(out scope))
                {
                    if (!searched.Add(scope))
                        continue;
                    var direct = declarationsByScope[(scope, name)].ToArray();
                    candidates.AddRange(direct.Select(declaration => declaration.UnderlyingDecl));
                    if (direct.Length == 0 && records.TryGetValue(scope, out var record))
                        foreach (var parent in (record.Definition ?? record).Bases)
                        {
                            if (parent.Type.CanonicalType is not RecordType type)
                                throw Error(GetLocation(record.Location), "RAIIFree cleanup lookup requires a resolved native base declaration.");
                            scopes.Push(type.Decl.Handle.CanonicalCursor);
                        }
                    foreach (var declaration in implicitNamespaces[scope])
                        scopes.Push(declaration.Handle.CanonicalCursor);
                    foreach (var directive in namespaceImports[scope])
                    {
                        var target = directive.CursorChildren.LastOrDefault(child => child.Handle.Kind == CXCursorKind.CXCursor_NamespaceRef);
                        if (target == null)
                            throw Error(GetLocation(directive.Location), "A cleanup namespace import requires a native namespace reference.");
                        var handle = target.Handle.Referenced;
                        if (handle.Kind == CXCursorKind.CXCursor_NamespaceAlias)
                            handle = handle.Referenced;
                        if (handle.Kind != CXCursorKind.CXCursor_Namespace)
                            throw Error(GetLocation(directive.Location), "A cleanup namespace import must resolve to a native namespace.");
                        scopes.Push(handle.CanonicalCursor);
                    }
                }
                return candidates.ToArray();
            }
        }

        private static CXCursor ReadDeclarationReference(Cursor argument, CXCursorKind kind, NativeLocation location, string message)
        {
            var references = new HashSet<CXCursor>();
            var pending = new Stack<Cursor>();
            pending.Push(argument);
            while (pending.TryPop(out var cursor))
            {
                if (cursor is DeclRefExpr)
                    references.Add(cursor.Handle.Referenced.CanonicalCursor);
                foreach (var child in cursor.CursorChildren)
                    pending.Push(child);
            }
            if (references.Count != 1 || references.Single().Kind != kind)
                throw Error(location, message);
            return references.Single();
        }

        private static string ReadStringArgument(Cursor argument, NativeLocation location)
        {
            if (UnwrapArgument(argument) is not StringLiteral literal || literal.Kind != CX_StringKind.CX_SLK_Ordinary)
                throw Error(location, "Metadata references require ordinary narrow string literals.");
            return literal.String;
        }

        private static ulong ReadInteger(Cursor argument, NativeLocation location)
        {
            var type = argument is Expr expression ? expression.Type.CanonicalType : null;
            if (type is EnumType enumeration)
                type = enumeration.Decl.IntegerType.CanonicalType;
            if (type == null || !IsEnumStorage(type.Kind))
                throw Error(location, "Annotation values must be integral constant expressions of at most 64 bits; use -1, not a pointer-cast INVALID_HANDLE_VALUE.");
            using var result = argument.Handle.Evaluate;
            if (result.Handle == IntPtr.Zero || result.Kind != CXEvalResultKind.CXEval_Int)
                throw Error(location, "Annotation value is not an integral constant expression.");
            return result.IsUnsignedInt ? result.AsUnsigned : unchecked((ulong)result.AsLongLong);
        }

        private static bool IsEnumStorage(CXTypeKind kind) => kind is
            CXTypeKind.CXType_Char_S or CXTypeKind.CXType_SChar or CXTypeKind.CXType_Char_U or CXTypeKind.CXType_UChar or
            CXTypeKind.CXType_Short or CXTypeKind.CXType_UShort or CXTypeKind.CXType_WChar or
            CXTypeKind.CXType_Int or CXTypeKind.CXType_UInt or CXTypeKind.CXType_Long or CXTypeKind.CXType_ULong or
            CXTypeKind.CXType_LongLong or CXTypeKind.CXType_ULongLong;

        internal void PrepareProjections(IEnumerable<string> sources, IReadOnlyDictionary<string, string> typeRemaps)
        {
            storageTypeRemaps = typeRemaps;
            var rewriter = new ProjectionRewriter(this);
            foreach (var source in sources)
                foreach (var node in CSharpSyntaxTree.ParseText(source).GetRoot().DescendantNodes().OfType<DelegateDeclarationSyntax>())
                    rewriter.AddCallbackTemplate(node);
        }

        internal string Rewrite(string source)
        {
            var root = CSharpSyntaxTree.ParseText(source).GetRoot();
            return new ProjectionRewriter(this).Visit(root).NormalizeWhitespace().ToFullString() + Environment.NewLine;
        }

        internal string GetAdditionalTypes()
        {
            var members = new List<MemberDeclarationSyntax>();
            foreach (var facts in annotatedTypedefs)
            {
                var alias = (TypedefNameDecl)facts.Declaration;
                string name = Remap(alias.Name);
                if (projectedDeclarations.Contains(facts.AnnotationOwner.Declaration))
                    continue;
                if (!ShouldEmit(alias, facts.Location))
                    continue;
                if (facts.LogicalEnumMembers != null)
                {
                    var logicalEnum = SyntaxFactory.EnumDeclaration(name)
                        .AddModifiers(SyntaxFactory.Token(SyntaxKind.PublicKeyword))
                        .AddBaseListTypes(SyntaxFactory.SimpleBaseType(SyntaxFactory.ParseTypeName(
                            GetManagedType(alias.UnderlyingType, facts.Location))))
                        .AddAttributeLists(GetAttributes(facts).ToArray())
                        .AddMembers(facts.LogicalEnumMembers.Select(member =>
                            SyntaxFactory.EnumMemberDeclaration(Remap(member.Name))
                                .WithEqualsValue(SyntaxFactory.EqualsValueClause(SyntaxFactory.ParseExpression(member.Value)))).ToArray());
                    members.Add(logicalEnum);
                    projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                    continue;
                }
                var functionType = GetFunctionType(alias.UnderlyingType);
                if (functionType != null)
                {
                    var template = (DelegateDeclarationSyntax)new ProjectionRewriter(this).Visit(GetCallbackTemplate(alias, facts.Location));
                    var callback = template.WithIdentifier(SyntaxFactory.Identifier(name))
                        .WithAttributeLists(SyntaxFactory.List(template.AttributeLists.Where(list => list.Target?.Identifier.ValueText == "return" ||
                            list.Attributes.Any(attribute => attribute.Name.ToString().EndsWith("UnmanagedFunctionPointer", StringComparison.Ordinal)))))
                        .AddAttributeLists(GetAttributes(facts).ToArray());
                    members.Add(callback);
                    projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                    continue;
                }
                string valueType = GetSignatureType(alias.UnderlyingType, facts.Location, underlyingStorage: true);
                var declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                    $"[{MetadataNamespace}NativeTypedef] public unsafe partial struct {name} {{ public {valueType} Value; }}");
                declaration = declaration.AddAttributeLists(GetAttributes(facts).ToArray());
                members.Add(declaration);
                projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
            }
            if (members.Count == 0)
                return string.Empty;
            return SyntaxFactory.CompilationUnit().AddUsings(
                SyntaxFactory.UsingDirective(SyntaxFactory.ParseName("System.Runtime.InteropServices")),
                SyntaxFactory.UsingDirective(SyntaxFactory.ParseName("Windows.Win32.Foundation.Metadata"))).AddMembers(
                SyntaxFactory.NamespaceDeclaration(SyntaxFactory.ParseName(generatedNamespace)).AddMembers(members.ToArray()))
                .NormalizeWhitespace().ToFullString() + Environment.NewLine;
        }

        internal void ValidateProjection()
        {
            foreach (var facts in declarations.Values)
                if ((facts.Annotations.Count != 0 || facts.MidlDirection != ParameterAttributes.None || facts.IsScopedEnum || facts.IsFlagsEnum) &&
                    ShouldEmit(facts.Declaration, facts.Location) && !projectedDeclarations.Contains(facts.AnnotationOwner.Declaration))
                    throw Error(facts.Location, $"Annotation facts for '{facts.Declaration.Name}' were not projected by ClangSharp.");
        }

        private void Walk(Cursor cursor)
        {
            if (!visited.Add(cursor))
                return;
            if (cursor is NamedDecl declaration)
            {
                var location = GetLocation(declaration.Location);
                var targets = declaration.Attrs.Where(attribute =>
                    attribute.Kind == CX_AttrKind.CX_AttrKind_Annotate &&
                    attribute.Spelling is HeaderAnnotation.OwnerPrefix + "Method" or HeaderAnnotation.OwnerPrefix + "Parameter" or
                        HeaderAnnotation.OwnerPrefix + "Field").ToArray();
                if (targets.Length != 0)
                {
                    string kind = HeaderAnnotation.RemoveOwnerPrefix(targets[0].Spelling);
                    if (targets.Length != 1 || declaration is not VarDecl variable ||
                        variable.Handle.StorageClass != CX_StorageClass.CX_SC_Static ||
                        variable.Type.CanonicalType.Kind != CXTypeKind.CXType_UChar ||
                        !variable.Type.Handle.IsConstQualified ||
                        !variable.Name.StartsWith("_WIN32META_" + kind.ToUpperInvariant() + "_", StringComparison.Ordinal))
                        throw Error(location, $"{kind} annotations require the metadata-only _Win32_Annotate{kind}_ carrier.");
                    var carriers = kind switch
                    {
                        "Parameter" => parameterCarriers,
                        "Field" => fieldCarriers,
                        _ => methodCarriers,
                    };
                    carriers.Add((variable, targets[0]));
                    return;
                }
                var facts = new DeclarationFacts(declaration, location);
                if (declaration is ParmVarDecl)
                {
                    string comment = GetLegacyParameterComment(declaration);
                    if (!HasSalParameterDirection(declaration))
                        facts.MidlDirection = GetMidlDirection(comment);
                }
                ReadAnnotations(declaration, facts);
                if (declaration is ParmVarDecl)
                {
                    string comment = GetLegacyParameterComment(declaration);
                    if (comment.Contains("[retval]", StringComparison.OrdinalIgnoreCase))
                    {
                        var retval = new HeaderAnnotation("RetVal", Array.Empty<string>());
                        ValidateTarget(facts, retval, location);
                        if (!facts.Annotations.Any(annotation => annotation.Name == retval.Name))
                            facts.Annotations.Add(retval);
                    }
                }
                if (declaration is EnumDecl enumDeclaration)
                {
                    facts.IsScopedEnum = enumDeclaration.IsScoped;
                    facts.IsFlagsEnum = declaration.Attrs.Any(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_FlagEnum);
                }
                if (declaration is FunctionDecl or ParmVarDecl or FieldDecl or RecordDecl or EnumDecl or EnumConstantDecl or TypedefNameDecl ||
                    IsConstantVariable(declaration))
                {
                    declarations[declaration] = facts;
                    if (declaration is TypedefNameDecl alias)
                    {
                        if (facts.Annotations.Count != 0)
                            annotatedTypedefs.Add(facts);
                        if (GetCallbackOrigin(alias) is TypedefNameDecl origin)
                            callbackOrigins[alias] = origin;
                    }
                }
            }
            foreach (var child in cursor.CursorChildren)
            {
                if (!child.Handle.IsAttribute && !child.Handle.IsReference && !child.Handle.IsExpression)
                    Walk(child);
            }
        }

        private void ApplyMethodAnnotations()
        {
            foreach (var carrier in methodCarriers)
            {
                var location = GetLocation(carrier.Target.Location);
                var arguments = carrier.Target.CursorChildren.ToArray();
                if (arguments.Length != 1)
                    throw Error(location, "A method carrier requires one compiler-parsed native method reference.");
                var target = ReadDeclarationReference(arguments[0], CXCursorKind.CXCursor_CXXMethod, location,
                    "A method carrier requires a reference to a declared native interface method.");
                var facts = declarations.Values.FirstOrDefault(item => item.Declaration.Handle.CanonicalCursor == target);
                if (facts == null)
                    throw Error(location, "The referenced method was not found in the original Clang AST.");
                if (!carrier.Declaration.Attrs.Any(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Annotate &&
                    attribute.Spelling != HeaderAnnotation.OwnerPrefix + "Method" && HeaderAnnotation.IsKnownPayload(attribute.Spelling)))
                    throw Error(location, "A method carrier requires at least one metadata annotation.");
                ReadAnnotations(carrier.Declaration, facts);
            }
        }

        private void ApplyParameterAnnotations()
        {
            foreach (var carrier in parameterCarriers)
            {
                var location = GetLocation(carrier.Target.Location);
                var arguments = carrier.Target.CursorChildren.ToArray();
                if (arguments.Length != 2)
                    throw Error(location, "A parameter carrier requires a compiler-parsed method reference and native parameter name.");
                var target = ReadDeclarationReference(arguments[0], CXCursorKind.CXCursor_CXXMethod, location,
                    "A parameter carrier requires a reference to a declared native interface method.");
                string name = ReadStringArgument(arguments[1], location);
                if (!Regex.IsMatch(name, @"^[A-Za-z_]\w*$"))
                    throw Error(location, "A parameter carrier requires one native parameter identifier.");
                var method = declarations.Keys.OfType<CXXMethodDecl>()
                    .FirstOrDefault(declaration => declaration.Handle.CanonicalCursor == target);
                var parameters = method?.Parameters.Where(parameter => parameter.Name == name).ToArray();
                if (parameters?.Length != 1 || !declarations.TryGetValue(parameters[0], out var facts))
                    throw Error(location, $"The native parameter '{name}' does not uniquely identify a parameter of the referenced method.");
                if (!carrier.Declaration.Attrs.Any(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Annotate &&
                    attribute.Spelling != HeaderAnnotation.OwnerPrefix + "Parameter" && HeaderAnnotation.IsKnownPayload(attribute.Spelling)))
                    throw Error(location, "A parameter carrier requires at least one metadata annotation.");
                ReadAnnotations(carrier.Declaration, facts);
            }
        }

        private void ApplyFieldAnnotations()
        {
            foreach (var carrier in fieldCarriers)
            {
                var location = GetLocation(carrier.Target.Location);
                var arguments = carrier.Target.CursorChildren.ToArray();
                if (arguments.Length != 1)
                    throw Error(location, "A field carrier requires one compiler-parsed native field reference.");
                var target = ReadDeclarationReference(arguments[0], CXCursorKind.CXCursor_FieldDecl, location,
                    "A field carrier requires a reference to a declared native instance field.");
                var facts = declarations.Values.FirstOrDefault(item => item.Declaration is FieldDecl &&
                    item.Declaration.Handle.CanonicalCursor == target);
                if (facts == null)
                    throw Error(location, "The referenced field was not found in the original Clang AST.");
                if (!carrier.Declaration.Attrs.Any(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Annotate &&
                    attribute.Spelling != HeaderAnnotation.OwnerPrefix + "Field" && HeaderAnnotation.IsKnownPayload(attribute.Spelling)))
                    throw Error(location, "A field carrier requires at least one metadata annotation.");
                ReadAnnotations(carrier.Declaration, facts);
            }
        }

        private void ReadAnnotations(NamedDecl declaration, DeclarationFacts facts)
        {
            var occurrences = new HashSet<CXCursor>();
            // Group carriers must be known before validating annotations on the emitted enum.
            var attributes = declaration.Attrs.Where(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Annotate)
                .OrderBy(attribute =>
                {
                    string payload = HeaderAnnotation.RemoveOwnerPrefix(attribute.Spelling);
                    return payload.StartsWith("Enum(", StringComparison.Ordinal) ||
                        payload.StartsWith("FlagsEnum(", StringComparison.Ordinal) ? 0 : 1;
                });
            foreach (var attribute in attributes)
            {
                var attributeLocation = GetLocation(attribute.Location);
                string payload = attribute.Spelling;
                if (payload is HeaderAnnotation.OwnerPrefix + "Method" or HeaderAnnotation.OwnerPrefix + "Parameter" or
                    HeaderAnnotation.OwnerPrefix + "Field")
                    continue;
                if (!HeaderAnnotation.IsKnownPayload(payload))
                    continue;
                if (!occurrences.Add(attribute.Handle))
                    continue;
                HeaderAnnotation annotation;
                try
                {
                    annotation = ReadAnnotation(attribute, facts, declaration, attributeLocation);
                }
                catch (FormatException exception)
                {
                    throw Error(attributeLocation, exception.Message);
                }
                ValidateTarget(facts, annotation, attributeLocation);
                if (annotation.Name != "AssociatedConstant")
                {
                    var existing = facts.Annotations.FirstOrDefault(item => item.Name == annotation.Name);
                    if (existing != null)
                    {
                        if (annotation.Name is "Enum" or "FlagsEnum")
                            continue;
                        if (annotation.Name != "SupportedOSPlatform")
                            throw Error(attributeLocation, $"Duplicate '{annotation.Name}' annotation.");
                        if (!existing.Arguments.SequenceEqual(annotation.Arguments))
                            throw Error(attributeLocation, $"Conflicting 'SupportedOSPlatform' annotations on '{facts.Declaration.Name}'. Clang scopes accumulate; close the prior scope before changing floors.");
                        continue;
                    }
                }
                facts.Annotations.Add(annotation);
            }
        }

        private void MergeRedeclarationFacts()
        {
            foreach (var group in declarations.Values.GroupBy(facts => GetNativeIdentity(facts.Declaration)))
            {
                var osValues = group.SelectMany(facts => facts.Annotations)
                    .Where(annotation => annotation.Name == "SupportedOSPlatform").ToArray();
                var supportedOS = osValues.FirstOrDefault();
                if (osValues.Any(annotation => !annotation.Arguments.SequenceEqual(supportedOS.Arguments)))
                    throw Error(group.First().Location, $"Conflicting 'SupportedOSPlatform' annotations on redeclarations of '{group.First().Declaration.Name}'.");
                var directions = group.Select(facts => facts.MidlDirection)
                    .Where(direction => direction != ParameterAttributes.None).Distinct().ToArray();
                if (directions.Length > 1)
                    throw Error(group.First().Location, $"Conflicting MIDL parameter directions on redeclarations of '{group.First().Declaration.Name}'.");
                foreach (var facts in group)
                    facts.Annotations.RemoveAll(annotation => annotation.Name == "SupportedOSPlatform");
                var owner = group.FirstOrDefault(facts => facts.Annotations.Count != 0) ?? group.First();
                foreach (var facts in group.Where(facts => facts != owner))
                {
                    if (owner.LogicalEnumMembers != null && facts.LogicalEnumMembers != null &&
                        owner.IsFlagsEnum != facts.IsFlagsEnum)
                        throw Error(facts.Location, $"Conflicting enum group kinds on '{facts.Declaration.Name}'.");
                    foreach (var annotation in facts.Annotations)
                    {
                        if (annotation.Name is "Enum" or "FlagsEnum" && owner.LogicalEnumMembers != null)
                            continue;
                        var matching = owner.Annotations.Where(existing => existing.Name == annotation.Name).ToArray();
                        bool equal = matching.Any(existing => existing.Arguments.SequenceEqual(annotation.Arguments));
                        if (matching.Length != 0 && !equal && annotation.Name != "AssociatedConstant")
                            throw Error(facts.Location, $"Conflicting '{annotation.Name}' annotations on redeclarations of '{facts.Declaration.Name}'.");
                        int count = facts.Annotations.Count(existing => existing.Name == annotation.Name &&
                            existing.Arguments.SequenceEqual(annotation.Arguments));
                        while (owner.Annotations.Count(existing => existing.Name == annotation.Name &&
                            existing.Arguments.SequenceEqual(annotation.Arguments)) < count)
                            owner.Annotations.Add(annotation);
                    }
                    owner.IsScopedEnum |= facts.IsScopedEnum;
                    owner.IsFlagsEnum |= facts.IsFlagsEnum;
                    if (facts.InvalidValues.Count != 0)
                    {
                        if (owner.InvalidValues.Count != 0 && !owner.InvalidValues.SequenceEqual(facts.InvalidValues))
                            throw Error(facts.Location, $"Conflicting RAIIFree invalid values on redeclarations of '{facts.Declaration.Name}'.");
                        if (owner.InvalidValues.Count == 0)
                            owner.InvalidValues.AddRange(facts.InvalidValues);
                    }
                    if (facts.LogicalEnumMembers != null)
                        owner.LogicalEnumMembers = MergeEnumMembers(owner.LogicalEnumMembers, facts.LogicalEnumMembers, facts.Location);
                }
                if (supportedOS != null)
                    owner.Annotations.Add(supportedOS);
                foreach (var facts in group)
                {
                    facts.AnnotationOwner = owner;
                    facts.Annotations = owner.Annotations;
                    facts.InvalidValues = owner.InvalidValues;
                    facts.IsScopedEnum = owner.IsScopedEnum;
                    facts.IsFlagsEnum = owner.IsFlagsEnum;
                    facts.LogicalEnumMembers = owner.LogicalEnumMembers;
                    facts.MidlDirection = directions.SingleOrDefault();
                    // A traversed forward typedef can inherit group facts from an untraversed redeclaration.
                    if (facts.Declaration is TypedefNameDecl && facts.LogicalEnumMembers != null && !annotatedTypedefs.Contains(facts))
                        annotatedTypedefs.Add(facts);
                }
            }
        }

        private static LogicalEnumMember[] MergeEnumMembers(
            LogicalEnumMember[] existing, LogicalEnumMember[] incoming, NativeLocation location)
        {
            var members = (existing ?? Array.Empty<LogicalEnumMember>()).ToList();
            var values = members.ToDictionary(member => member.Name, member => member.StorageBits, StringComparer.Ordinal);
            foreach (var member in incoming)
            {
                if (values.TryGetValue(member.Name, out ulong value))
                {
                    if (value != member.StorageBits)
                        throw Error(location, $"Conflicting enum group values for '{member.Name}'.");
                    continue;
                }
                values.Add(member.Name, member.StorageBits);
                members.Add(member);
            }
            return members.ToArray();
        }

        private static (CXCursor Declaration, int Parameter) GetNativeIdentity(NamedDecl declaration)
        {
            if (declaration is ParmVarDecl parameter && parameter.SemanticParentCursor is FunctionDecl function)
                for (int i = 0; i < function.Parameters.Count; i++)
                    if (function.Parameters[i] == parameter)
                        return (function.Handle.CanonicalCursor, i);
            return (declaration.Handle.CanonicalCursor, -1);
        }

        private static void ValidateTarget(DeclarationFacts facts, HeaderAnnotation annotation, NativeLocation location)
        {
            var declaration = facts.Declaration;
            bool function = declaration is FunctionDecl;
            bool parameter = declaration is ParmVarDecl;
            bool record = declaration is RecordDecl;
            bool typedef = declaration is TypedefNameDecl;
            bool field = declaration is FieldDecl;
            bool valid = annotation.Name switch
            {
                "SetLastError" or "ImportLibrary" => function && declaration is not CXXMethodDecl,
                "PreserveResult" => function,
                "SupportedOSPlatform" => function || record || typedef || declaration is EnumDecl or EnumConstantDecl || IsConstantVariable(declaration),
                "AssociatedEnum" => function || parameter || field,
                "AssociatedConstant" => declaration is EnumDecl || facts.LogicalEnumMembers != null,
                "Enum" or "FlagsEnum" => typedef,
                "AlsoUsableFor" => typedef && facts.LogicalEnumMembers == null,
                "RAIIFree" => function || parameter,
                "Retained" or "ContainsInteriorPointers" or "RetVal" or "Reserved" or "Optional" or "ComOutPtr" => parameter,
                _ => false,
            };
            if (!valid)
                throw Error(location, $"'{annotation.Name}' is not valid on {declaration.Handle.DeclKind} '{declaration.Name}'.");
            if (annotation.Name == "ComOutPtr")
            {
                var type = ((ParmVarDecl)declaration).Type.CanonicalType;
                var pointee = type switch
                {
                    PointerType pointer => pointer.PointeeType,
                    ReferenceType reference => reference.PointeeType,
                    _ => null,
                };
                if (pointee == null || pointee.Handle.IsConstQualified || pointee.CanonicalType is not PointerType)
                    throw Error(location, "ComOutPtr requires writable output pointer storage.");
                bool inputOnly = facts.MidlDirection == ParameterAttributes.In || declaration.Attrs.Any(attribute =>
                {
                    string name = Regex.Match(attribute.Spelling, @"\bName\s*=\s*SAL_name\s*;\s*p1\s*=\s*""([^""]+)""").Groups[1].Value;
                    return name.StartsWith("_In_", StringComparison.Ordinal) ||
                        name == "__RPC__in" || name.StartsWith("__RPC__in_", StringComparison.Ordinal);
                });
                if (inputOnly)
                    throw Error(location, "ComOutPtr requires output/inout storage, not an input-only parameter.");
            }
            if (parameter && annotation.Name is "Retained" or "ContainsInteriorPointers" or "RAIIFree" or "RetVal")
            {
                var type = ((ParmVarDecl)declaration).Type.CanonicalType;
                if (type is not PointerType && type is not ReferenceType)
                    throw Error(location, $"'{annotation.Name}' requires a pointer or reference parameter.");
                var salNames = declaration.Attrs.Select(attribute =>
                    Regex.Match(attribute.Spelling, @"\bName\s*=\s*SAL_name\s*;\s*p1\s*=\s*""([^""]+)""").Groups[1].Value).ToArray();
                bool inputOnly = salNames.Any(name => name.StartsWith("_In_", StringComparison.Ordinal) ||
                    name.StartsWith("__RPC__in_", StringComparison.Ordinal));
                if (inputOnly && annotation.Name is "ContainsInteriorPointers" or "RAIIFree" or "RetVal")
                    throw Error(location, $"'{annotation.Name}' requires output/inout storage, not an input-only parameter.");
                if (annotation.Name is "ContainsInteriorPointers" or "RAIIFree" or "RetVal")
                {
                    var pointee = type is PointerType pointer ? pointer.PointeeType : ((ReferenceType)type).PointeeType;
                    if (pointee.Handle.IsConstQualified)
                        throw Error(location, $"'{annotation.Name}' requires writable output/inout storage.");
                    if (annotation.Name == "ContainsInteriorPointers")
                    {
                        bool allocatedOutput = salNames.Any(name => name.StartsWith("_Outptr_", StringComparison.Ordinal) ||
                            name.StartsWith("_Outref_", StringComparison.Ordinal) || name.StartsWith("_COM_Outptr_", StringComparison.Ordinal));
                        bool buffer = salNames.Any(name => name.StartsWith("_Out_writes_", StringComparison.Ordinal) ||
                            name.StartsWith("_Inout_updates_", StringComparison.Ordinal));
                        if (allocatedOutput || (!buffer && pointee.CanonicalType is PointerType or ReferenceType))
                            throw Error(location, "ContainsInteriorPointers describes caller-owned buffer storage, not a callee-allocated pointer output.");
                    }
                }
            }
            if (function && annotation.Name is "RAIIFree" or "AssociatedEnum")
            {
                if (((FunctionDecl)declaration).ReturnType.CanonicalType.Kind == CXTypeKind.CXType_Void)
                    throw Error(location, $"'{annotation.Name}' cannot describe a void return.");
            }
        }

        private static bool IsConstantVariable(NamedDecl declaration)
            => declaration is VarDecl variable and not ParmVarDecl &&
                variable.Type.Handle.IsConstQualified && variable.SemanticParentCursor is not FunctionDecl;

        private void TransferRecordTypedefFacts()
        {
            foreach (var facts in annotatedTypedefs)
            {
                var alias = (TypedefNameDecl)facts.Declaration;
                if (alias.UnderlyingType.CanonicalType is not RecordType record)
                    continue;
                var recordLocation = GetLocation(record.Decl.Location);
                if (!declarations.TryGetValue(record.Decl, out var recordFacts))
                {
                    recordFacts = new DeclarationFacts(record.Decl, recordLocation);
                    declarations[record.Decl] = recordFacts;
                }
                if (Remap(record.Decl.Name) != Remap(alias.Name))
                    continue;
                foreach (var annotation in facts.Annotations)
                {
                    var existing = recordFacts.Annotations.SingleOrDefault(item => item.Name == annotation.Name);
                    if (existing != null && !existing.Arguments.SequenceEqual(annotation.Arguments))
                        throw Error(facts.Location, $"Conflicting '{annotation.Name}' annotations on a record and its typedef.");
                    if (existing == null)
                        recordFacts.Annotations.Add(annotation);
                }
                projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
            }
        }

        private IEnumerable<AttributeListSyntax> GetAttributes(DeclarationFacts facts)
        {
            if (facts.MidlDirection != ParameterAttributes.None && !HasSalParameterDirection(facts.Declaration))
            {
                if (facts.MidlDirection.HasFlag(ParameterAttributes.In))
                    yield return MakeAttribute("global::System.Runtime.InteropServices.In");
                if (facts.MidlDirection.HasFlag(ParameterAttributes.Out))
                    yield return MakeAttribute("global::System.Runtime.InteropServices.Out");
            }
            foreach (var annotation in facts.Annotations)
            {
                bool returnTarget = facts.Declaration is FunctionDecl && annotation.Name is "RAIIFree" or "AssociatedEnum";
                string name = annotation.Name switch
                {
                    "PreserveResult" => "global::System.Runtime.InteropServices.PreserveSig",
                    "SupportedOSPlatform" => MetadataNamespace + "SupportedOSPlatform",
                    _ => MetadataNamespace + annotation.Name,
                };
                switch (annotation.Name)
                {
                    case "Optional":
                    case "ComOutPtr":
                        yield return MakeAttribute("NativeAnnotation(" +
                            HeaderAnnotation.Quote(HeaderAnnotation.OwnerPrefix + annotation.Name + "(" + annotation.Arguments[0] + ")") + ")");
                        continue;
                    case "SetLastError":
                    case "ImportLibrary":
                    case "Enum":
                    case "FlagsEnum":
                        continue;
                    case "SupportedOSPlatform":
                        name += "(" + HeaderAnnotation.Quote(HeaderAnnotation.ReadString(annotation.Arguments[0])) + ")";
                        break;
                    case "AlsoUsableFor":
                    case "AssociatedEnum":
                    case "AssociatedConstant":
                    case "RAIIFree":
                        name += "(" + HeaderAnnotation.Quote(annotation.Arguments[0]) + ")";
                        break;
                }
                yield return MakeAttribute(name, returnTarget);
            }
            bool raiiReturn = facts.Declaration is FunctionDecl;
            foreach (long value in facts.InvalidValues)
                yield return MakeAttribute(MetadataNamespace + $"InvalidHandleValue({value.ToString(CultureInfo.InvariantCulture)}L)", raiiReturn);
            if (facts.IsScopedEnum)
                yield return MakeAttribute(MetadataNamespace + "ScopedEnum");
            if (facts.IsFlagsEnum)
                yield return MakeAttribute("global::System.Flags");
        }

        private static AttributeListSyntax MakeAttribute(string text, bool returnTarget = false)
        {
            var declaration = SyntaxFactory.ParseCompilationUnit($"[{(returnTarget ? "return: " : "")}{text}] public class C {{ }}")
                .Members.OfType<ClassDeclarationSyntax>().Single();
            return declaration.AttributeLists.Single();
        }

        private bool ShouldEmit(NamedDecl declaration, NativeLocation location)
        {
            for (Cursor cursor = declaration; cursor is NamedDecl named; cursor = cursor.SemanticParentCursor)
                if (excludedNames.Contains(named.Name) ||
                    named is FunctionDecl function &&
                    (function.Attrs.Any(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Builtin) ||
                        excludeFunctionsWithBody && function.HasBody))
                    return false;
            if (location.File.Length == 0)
                return false;
            return traversalNames.Count == 0 || traversalNames.Any(name =>
                string.Equals(Path.GetFullPath(name), Path.GetFullPath(location.File), StringComparison.OrdinalIgnoreCase) ||
                (Path.GetFileName(name) == name && string.Equals(name, Path.GetFileName(location.File), StringComparison.OrdinalIgnoreCase)));
        }

        private string Remap(string name) => remaps.GetValueOrDefault(name) ?? name;

        private static FunctionProtoType GetFunctionType(ClangSharp.Type type)
        {
            type = UnwrapSignatureType(type);
            if (type is PointerType pointer)
                type = UnwrapSignatureType(pointer.PointeeType);
            return type as FunctionProtoType;
        }

        private static ClangSharp.Type UnwrapSignatureType(ClangSharp.Type type)
        {
            while (true)
            {
                type = type switch
                {
                    ElaboratedType elaborated => elaborated.NamedType,
                    AttributedType attributed => attributed.EquivalentType,
                    ParenType parentheses => parentheses.InnerType,
                    TypedefType typedef => ((TypedefNameDecl)typedef.Decl).UnderlyingType,
                    _ => null,
                } ?? type;
                if (type is not ElaboratedType and not AttributedType and not ParenType and not TypedefType)
                    return type;
            }
        }

        private static TypedefNameDecl GetCallbackOrigin(TypedefNameDecl alias)
        {
            var type = RemapDiscovery.UnwrapType(alias.UnderlyingType);
            if (type is TypedefType typedef)
                return GetCallbackOrigin((TypedefNameDecl)typedef.Decl);
            if (type is PointerType pointer)
            {
                type = RemapDiscovery.UnwrapType(pointer.PointeeType);
                if (type is TypedefType typedefPointer)
                    return GetCallbackOrigin((TypedefNameDecl)typedefPointer.Decl);
            }
            return type is FunctionProtoType ? alias : null;
        }

        private string GetManagedType(ClangSharp.Type type, NativeLocation location)
        {
            type = type.CanonicalType;
            if (type is PointerType pointer)
                return GetManagedType(pointer.PointeeType, location) + "*";
            if (type is TagType tag)
                return Remap(tag.Decl.Name);
            return type.Kind switch
            {
                CXTypeKind.CXType_Void => "void",
                CXTypeKind.CXType_Bool => "byte",
                CXTypeKind.CXType_Char_S or CXTypeKind.CXType_SChar => "sbyte",
                CXTypeKind.CXType_Char_U or CXTypeKind.CXType_UChar => "byte",
                CXTypeKind.CXType_Short => "short",
                CXTypeKind.CXType_WChar or CXTypeKind.CXType_UShort => "ushort",
                CXTypeKind.CXType_Int or CXTypeKind.CXType_Long => "int",
                CXTypeKind.CXType_UInt or CXTypeKind.CXType_ULong => "uint",
                CXTypeKind.CXType_LongLong => "long",
                CXTypeKind.CXType_ULongLong => "ulong",
                CXTypeKind.CXType_Float => "float",
                CXTypeKind.CXType_Double => "double",
                _ => throw Error(location, $"Unsupported annotated typedef underlying type '{type.AsString}'."),
            };
        }

        private DelegateDeclarationSyntax CreateCallbackTemplate(TypedefNameDecl alias, FunctionProtoType signature, NativeLocation location)
        {
            var parameters = alias.CursorChildren.OfType<ParmVarDecl>().ToArray();
            if (parameters.Length != signature.ParamTypes.Count || signature.Handle.IsFunctionTypeVariadic)
                throw Error(location, $"Unsupported callback alias signature '{alias.Name}'.");
            string convention = GetCallbackConvention(alias.UnderlyingType, location);
            var callback = (DelegateDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                $"public unsafe delegate {GetSignatureType(signature.ReturnType, location)} {Remap(alias.Name)}();");
            callback = callback.AddAttributeLists(MakeAttribute(
                $"UnmanagedFunctionPointer(CallingConvention.{convention})"),
                MakeAttribute($"NativeTypeName({HeaderAnnotation.Quote(signature.ReturnType.AsString)})", returnTarget: true));
            for (int i = 0; i < parameters.Length; i++)
            {
                var native = parameters[i];
                string name = string.IsNullOrEmpty(native.Name) ? $"param{i}" : Remap(native.Name);
                if (SyntaxFacts.GetKeywordKind(name) != SyntaxKind.None)
                    name = "@" + name;
                var parameter = SyntaxFactory.Parameter(SyntaxFactory.Identifier(name))
                    .WithType(SyntaxFactory.ParseTypeName(GetSignatureType(native.Type, location)))
                    .AddAttributeLists(MakeAttribute($"NativeTypeName({HeaderAnnotation.Quote(native.Type.AsString)})"));
                string attributes = string.Join("^", native.Attrs.Select(attribute => attribute.Spelling)
                    .Where(payload => !HeaderAnnotation.IsKnownPayload(payload)));
                if (attributes.Length != 0)
                    parameter = parameter.AddAttributeLists(MakeAttribute($"CppAttributeList({HeaderAnnotation.Quote(attributes)})"));
                if (declarations.TryGetValue(native, out var facts))
                {
                    parameter = parameter.AddAttributeLists(GetAttributes(facts).ToArray());
                    projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                }
                callback = callback.AddParameterListParameters(parameter);
            }
            return callback;
        }

        private static string GetCallbackConvention(ClangSharp.Type type, NativeLocation location) => type switch
        {
            AttributedType attributed => attributed.AttrKind switch
            {
                CX_AttrKind.CX_AttrKind_CDecl => "Cdecl",
                CX_AttrKind.CX_AttrKind_StdCall => "StdCall",
                CX_AttrKind.CX_AttrKind_FastCall => "FastCall",
                CX_AttrKind.CX_AttrKind_ThisCall => "ThisCall",
                _ => GetCallbackConvention(attributed.ModifiedType, location),
            },
            ElaboratedType elaborated => GetCallbackConvention(elaborated.NamedType, location),
            ParenType parentheses => GetCallbackConvention(parentheses.InnerType, location),
            TypedefType typedef => GetCallbackConvention(((TypedefNameDecl)typedef.Decl).UnderlyingType, location),
            PointerType pointer => GetCallbackConvention(pointer.PointeeType, location),
            FunctionProtoType signature => signature.CallConv switch
            {
                CXCallingConv.CXCallingConv_C => "Cdecl",
                CXCallingConv.CXCallingConv_X86StdCall => "StdCall",
                CXCallingConv.CXCallingConv_X86FastCall => "FastCall",
                CXCallingConv.CXCallingConv_X86ThisCall => "ThisCall",
                CXCallingConv.CXCallingConv_Default or CXCallingConv.CXCallingConv_Win64 or
                    CXCallingConv.CXCallingConv_AAPCS or CXCallingConv.CXCallingConv_AAPCS_VFP => "Winapi",
                _ => throw Error(location, $"Unsupported callback alias calling convention '{signature.CallConv}'."),
            },
            _ => throw Error(location, $"Unsupported callback alias type '{type.AsString}'."),
        };

        private DelegateDeclarationSyntax GetCallbackTemplate(TypedefNameDecl alias, NativeLocation location)
        {
            var origin = callbackOrigins.GetValueOrDefault(alias) ?? alias;
            if (!callbackTemplates.TryGetValue(origin, out var template))
            {
                if (origin is not TypeAliasDecl)
                    throw Error(location, $"Canonical signature for callback alias '{alias.Name}' was not generated.");
                callbackTemplates[origin] = template = CreateCallbackTemplate(origin, GetFunctionType(origin.UnderlyingType), location);
            }
            return template;
        }

        private string GetSignatureType(ClangSharp.Type type, NativeLocation location, bool underlyingStorage = false)
        {
            type = RemapDiscovery.UnwrapType(type);
            if (type is TypedefType typedef)
            {
                var alias = (TypedefNameDecl)typedef.Decl;
                var mappings = underlyingStorage ? storageTypeRemaps : remaps;
                if (mappings.TryGetValue(alias.Name, out string mapped) && (!underlyingStorage || mapped != alias.Name))
                {
                    if (!underlyingStorage)
                        return mapped;
                    // Nominal remaps name wrappers, not their underlying storage.
                    string storage = GetNativeIntegerStorage(mapped);
                    if (storage != null)
                        return storage;
                }
                return GetSignatureType(alias.UnderlyingType, location, underlyingStorage);
            }
            if (type is PointerType pointer)
                return GetSignatureType(pointer.PointeeType, location, underlyingStorage) + "*";
            return GetManagedType(type, location);
        }

        private static string GetNativeIntegerStorage(string mapped)
        {
            mapped = mapped.Trim();
            if (mapped.EndsWith("*", StringComparison.Ordinal))
            {
                string pointee = GetNativeIntegerStorage(mapped.Substring(0, mapped.Length - 1));
                return pointee == null ? null : pointee + "*";
            }
            return mapped switch
            {
                "IntPtr" or "System.IntPtr" or "global::System.IntPtr" or "nint" => "global::System.IntPtr",
                "UIntPtr" or "System.UIntPtr" or "global::System.UIntPtr" or "nuint" => "global::System.UIntPtr",
                _ => null,
            };
        }

        private static bool HasSalParameterDirection(NamedDecl declaration)
        {
            foreach (var attribute in declaration.Attrs)
            {
                string payload = attribute.Spelling;
                if (Regex.IsMatch(payload, @"\bName\s*=\s*SAL_valid\b"))
                    return true;
                string name = Regex.Match(payload, @"\bName\s*=\s*SAL_name\s*;\s*p1\s*=\s*""([^""]+)""").Groups[1].Value;
                if ((name.StartsWith("__RPC__", StringComparison.Ordinal) && Regex.IsMatch(name, @"_(in|out|inout)(_|$)")) ||
                    name.StartsWith("_COM_Outptr", StringComparison.Ordinal) || name.StartsWith("_Outptr_", StringComparison.Ordinal) ||
                    name is "_Maybenull_" or "_Pre_maybenull_" or "_Pre_null_")
                    return true;
            }
            return false;
        }

        private static ParameterAttributes GetMidlDirection(string comment)
        {
            if (!Regex.IsMatch(comment, @"^/\*\s*(\[[^\[\]]*\]\s*)+\*/$"))
                return ParameterAttributes.None;
            var direction = ParameterAttributes.None;
            foreach (Match attributeList in Regex.Matches(comment, @"\[([^\[\]]*)\]"))
                foreach (string attribute in attributeList.Groups[1].Value.Split(','))
                {
                    if (attribute.Trim().Equals("in", StringComparison.OrdinalIgnoreCase))
                        direction |= ParameterAttributes.In;
                    else if (attribute.Trim().Equals("out", StringComparison.OrdinalIgnoreCase))
                        direction |= ParameterAttributes.Out;
                }
            return direction;
        }

        // MIDL does not emit SAL for every explicit direction or retval contract.
        private string GetLegacyParameterComment(NamedDecl declaration)
        {
            var start = GetLocation(declaration.Extent.Start);
            if (start.File.Length == 0)
                return string.Empty;
            var file = declaration.TranslationUnit.Handle.GetFile(start.File);
            var contents = declaration.TranslationUnit.Handle.GetFileContents(file, out _);
            int position = checked((int)start.Offset);
            while (position > 0 && char.IsWhiteSpace((char)contents[position - 1]))
                position--;
            if (position < 2 || contents[position - 2] != '*' || contents[position - 1] != '/')
                return string.Empty;
            int end = position;
            position -= 2;
            while (position >= 2 && !(contents[position - 2] == '/' && contents[position - 1] == '*'))
                position--;
            if (position < 2)
                return string.Empty;
            return Encoding.UTF8.GetString(contents.Slice(position - 2, end - position + 2));
        }

        private static NativeLocation GetLocation(CXSourceLocation location)
        {
            location.GetExpansionLocation(out var file, out uint line, out uint column, out uint offset);
            string path = file.ToString();
            return new NativeLocation(path, line, column, offset);
        }

        private static HeaderAnnotationException Error(NativeLocation location, string message)
            => new($"{location.File}({location.Line},{location.Column})", message);

        private sealed record NativeLocation(string File, uint Line, uint Column, uint Offset);
        private sealed record LogicalEnumMember(string Name, string Value, ulong StorageBits);

        private sealed class DeclarationFacts
        {
            internal DeclarationFacts(NamedDecl declaration, NativeLocation location)
            {
                Declaration = declaration;
                Location = location;
                AnnotationOwner = this;
            }
            internal NamedDecl Declaration { get; }
            internal NativeLocation Location { get; }
            internal DeclarationFacts AnnotationOwner { get; set; }
            internal List<HeaderAnnotation> Annotations { get; set; } = new();
            internal List<long> InvalidValues { get; set; } = new();
            internal bool IsScopedEnum { get; set; }
            internal bool IsFlagsEnum { get; set; }
            internal ParameterAttributes MidlDirection { get; set; }
            internal LogicalEnumMember[] LogicalEnumMembers { get; set; }
        }

        private sealed class ProjectionRewriter : CSharpSyntaxRewriter
        {
            private readonly HeaderAnnotationProcessor owner;
            internal ProjectionRewriter(HeaderAnnotationProcessor owner)
            {
                this.owner = owner;
            }

            internal void AddCallbackTemplate(DelegateDeclarationSyntax node)
            {
                var declaration = FindFacts(node.AttributeLists, node)?.Declaration;
                if (declaration is TypedefNameDecl alias &&
                    owner.callbackOrigins.TryGetValue(alias, out var origin) && origin == alias)
                    owner.callbackTemplates[origin] = node;
            }

            private DeclarationFacts FindFacts(SyntaxList<AttributeListSyntax> attributes, SyntaxNode node)
            {
                var location = attributes.SelectMany(list => list.Attributes).FirstOrDefault(attribute => attribute.Name.ToString() == "SourceLocation");
                if (location?.ArgumentList?.Arguments.Count != 3)
                {
                    if (attributes.SelectMany(list => list.Attributes).Any(attribute =>
                        attribute.Name.ToString() == "NativeAnnotation" &&
                        attribute.ArgumentList?.Arguments.FirstOrDefault()?.Expression is LiteralExpressionSyntax literal &&
                        HeaderAnnotation.IsKnownPayload(literal.Token.ValueText)))
                        throw new InvalidOperationException("ClangSharp did not produce source-location transport for an annotated declaration.");
                    return null;
                }
                var args = location.ArgumentList.Arguments;
                var fileToken = ((LiteralExpressionSyntax)args[0].Expression).Token;
                // ClangSharp 21 inconsistently escapes the final Windows path separator.
                string file = OperatingSystem.IsWindows()
                    ? fileToken.Text[1..^1].Replace(@"\\", @"\", StringComparison.Ordinal)
                    : fileToken.ValueText;
                uint line = uint.Parse(args[1].Expression.ToString(), CultureInfo.InvariantCulture);
                uint column = uint.Parse(args[2].Expression.ToString(), CultureInfo.InvariantCulture);
                owner.projectionLocations.TryGetValue((file, line, column), out var candidates);
                var compatible = candidates?.Where(facts => MatchesKind(facts.Declaration, node)).ToArray()
                    ?? Array.Empty<DeclarationFacts>();
                compatible = compatible.GroupBy(facts => facts.AnnotationOwner).Select(group => group.First()).ToArray();
                if (compatible.Length > 1 && node is ParameterSyntax parameterNode)
                {
                    var parent = parameterNode.Parent?.Parent;
                    var declaration = parent switch
                    {
                        MethodDeclarationSyntax method => FindFacts(method.AttributeLists, method)?.Declaration,
                        DelegateDeclarationSyntax callback => FindFacts(callback.AttributeLists, callback)?.Declaration,
                        _ => null,
                    };
                    if (declaration is FunctionDecl function)
                        compatible = compatible.Where(facts =>
                            GetNativeIdentity(facts.Declaration).Declaration == function.Handle.CanonicalCursor).ToArray();
                    else if (declaration is TypedefNameDecl alias)
                    {
                        var origin = owner.callbackOrigins.GetValueOrDefault(alias) ?? alias;
                        var parameters = origin.CursorChildren.OfType<ParmVarDecl>().Select(GetNativeIdentity).ToHashSet();
                        compatible = compatible.Where(facts => parameters.Contains(GetNativeIdentity(facts.Declaration))).ToArray();
                    }
                }
                if (compatible.Length > 1)
                {
                    string name = node switch
                    {
                        MethodDeclarationSyntax method => method.Identifier.ValueText,
                        ParameterSyntax parameter => parameter.Identifier.ValueText,
                        FieldDeclarationSyntax field => field.Declaration.Variables.Single().Identifier.ValueText,
                        EnumMemberDeclarationSyntax member => member.Identifier.ValueText,
                        BaseTypeDeclarationSyntax type => type.Identifier.ValueText,
                        DelegateDeclarationSyntax callback => callback.Identifier.ValueText,
                        _ => string.Empty,
                    };
                    // ClangSharp prefixes synthesized virtual-method delegate names with "_".
                    compatible = compatible.Where(facts => owner.Remap(facts.Declaration.Name) == name ||
                        node is DelegateDeclarationSyntax && facts.Declaration is CXXMethodDecl &&
                        "_" + owner.Remap(facts.Declaration.Name) == name).ToArray();
                }
                if (compatible.Length > 1 && node is MethodDeclarationSyntax or DelegateDeclarationSyntax)
                {
                    var record = node.Ancestors().OfType<StructDeclarationSyntax>()
                        .Select(parent => FindFacts(parent.AttributeLists, parent)?.Declaration)
                        .OfType<RecordDecl>().FirstOrDefault();
                    if (record != null)
                        compatible = compatible.Where(facts =>
                            facts.Declaration.SemanticParentCursor.Handle.CanonicalCursor == record.Handle.CanonicalCursor).ToArray();
                }
                if (compatible.Length > 1)
                    throw Error(compatible[0].Location, "Source-location transport is ambiguous between native declarations; refusing to assign annotation facts.");
                var found = compatible.SingleOrDefault();
                if (found == null && attributes.SelectMany(list => list.Attributes).Any(attribute =>
                    attribute.Name.ToString() == "NativeAnnotation" &&
                    attribute.ArgumentList?.Arguments.FirstOrDefault()?.Expression is LiteralExpressionSyntax literal &&
                    HeaderAnnotation.IsKnownPayload(literal.Token.ValueText)))
                    throw Error(new NativeLocation(file, line, column, 0), "Cannot map annotated declaration to its native source.");
                return found;
            }

            private static bool MatchesKind(NamedDecl declaration, SyntaxNode node) => node switch
            {
                MethodDeclarationSyntax => declaration is FunctionDecl,
                ParameterSyntax => declaration is ParmVarDecl,
                FieldDeclarationSyntax => declaration is FieldDecl || IsConstantVariable(declaration),
                EnumMemberDeclarationSyntax => declaration is EnumConstantDecl,
                StructDeclarationSyntax => declaration is RecordDecl,
                EnumDeclarationSyntax => declaration is EnumDecl,
                DelegateDeclarationSyntax => declaration is TypedefNameDecl or FunctionDecl,
                _ => false,
            };

            public override SyntaxNode VisitAttributeList(AttributeListSyntax node)
            {
                var attributes = new List<AttributeSyntax>();
                foreach (var attribute in node.Attributes)
                {
                    string name = attribute.Name.ToString();
                    if (name == "SourceLocation")
                        continue;
                    if (attribute.ArgumentList?.Arguments.FirstOrDefault()?.Expression is LiteralExpressionSyntax literal)
                    {
                        if (name == "NativeAnnotation" && HeaderAnnotation.IsKnownPayload(literal.Token.ValueText))
                            continue;
                        if (name == "CppAttributeList")
                        {
                            var payloads = HeaderAnnotation.SplitAttributeTransport(literal.Token.ValueText);
                            string[] retained = payloads.Where(payload => !HeaderAnnotation.IsKnownPayload(payload)).ToArray();
                            if (retained.Length == 0)
                                continue;
                            if (retained.Length != payloads.Count)
                            {
                                attributes.Add(attribute.ReplaceNode(literal, SyntaxFactory.LiteralExpression(
                                    SyntaxKind.StringLiteralExpression, SyntaxFactory.Literal(string.Join("^", retained)))));
                                continue;
                            }
                        }
                    }
                    attributes.Add(attribute);
                }
                return attributes.Count == 0 ? null : node.WithAttributes(SyntaxFactory.SeparatedList(attributes));
            }

            public override SyntaxNode VisitMethodDeclaration(MethodDeclarationSyntax node)
            {
                var facts = FindFacts(node.AttributeLists, node);
                node = (MethodDeclarationSyntax)base.VisitMethodDeclaration(node);
                if (facts == null)
                    return node;
                owner.projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                node = node.AddAttributeLists(owner.GetAttributes(facts).ToArray());
                var import = node.AttributeLists.SelectMany(list => list.Attributes).SingleOrDefault(attribute => attribute.Name.ToString() == "DllImport");
                if (import == null && facts.Annotations.Any(annotation => annotation.Name is "ImportLibrary" or "SetLastError"))
                    throw Error(facts.Location, $"Import metadata for '{facts.Declaration.Name}' requires a DllImport declaration.");
                if (import != null)
                {
                    var arguments = import.ArgumentList.Arguments;
                    var module = facts.Annotations.SingleOrDefault(annotation => annotation.Name == "ImportLibrary");
                    if (module != null)
                    {
                        arguments = arguments.Replace(arguments[0], SyntaxFactory.AttributeArgument(
                            SyntaxFactory.LiteralExpression(SyntaxKind.StringLiteralExpression, SyntaxFactory.Literal(HeaderAnnotation.ReadString(module.Arguments[0])))));
                        if (module.Arguments.Count == 2)
                        {
                            arguments = SyntaxFactory.SeparatedList(arguments.Where(argument => argument.NameEquals?.Name.Identifier.ValueText != "EntryPoint"));
                            arguments = arguments.Add(SyntaxFactory.AttributeArgument(SyntaxFactory.LiteralExpression(
                                SyntaxKind.StringLiteralExpression, SyntaxFactory.Literal(HeaderAnnotation.ReadString(module.Arguments[1]))))
                                .WithNameEquals(SyntaxFactory.NameEquals("EntryPoint")));
                        }
                    }
                    if (facts.Annotations.Any(annotation => annotation.Name == "SetLastError"))
                    {
                        arguments = SyntaxFactory.SeparatedList(arguments.Where(argument => argument.NameEquals?.Name.Identifier.ValueText != "SetLastError"));
                        arguments = arguments.Add(SyntaxFactory.AttributeArgument(SyntaxFactory.LiteralExpression(SyntaxKind.TrueLiteralExpression))
                            .WithNameEquals(SyntaxFactory.NameEquals("SetLastError")));
                    }
                    node = node.ReplaceNode(import, import.WithArgumentList(import.ArgumentList.WithArguments(arguments)));
                }
                return node;
            }

            public override SyntaxNode VisitParameter(ParameterSyntax node)
            {
                var facts = FindFacts(node.AttributeLists, node);
                node = (ParameterSyntax)base.VisitParameter(node);
                if (facts != null)
                {
                    owner.projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                    node = node.AddAttributeLists(owner.GetAttributes(facts).ToArray());
                }
                return node;
            }

            public override SyntaxNode VisitFieldDeclaration(FieldDeclarationSyntax node)
            {
                var facts = FindFacts(node.AttributeLists, node);
                node = (FieldDeclarationSyntax)base.VisitFieldDeclaration(node);
                if (facts != null)
                {
                    owner.projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                    node = node.AddAttributeLists(owner.GetAttributes(facts).ToArray());
                }
                return node;
            }

            public override SyntaxNode VisitStructDeclaration(StructDeclarationSyntax node)
            {
                var facts = FindFacts(node.AttributeLists, node);
                node = (StructDeclarationSyntax)base.VisitStructDeclaration(node);
                if (facts != null)
                {
                    owner.projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                    node = node.AddAttributeLists(owner.GetAttributes(facts).ToArray());
                }
                return node;
            }

            public override SyntaxNode VisitEnumDeclaration(EnumDeclarationSyntax node)
            {
                var facts = FindFacts(node.AttributeLists, node);
                if (facts?.Declaration is EnumDecl nativeEnum &&
                    owner.enumReferenceCarriers.Contains(nativeEnum.Handle.CanonicalCursor))
                {
                    if (node.Members.Count != 0)
                        throw Error(facts.Location, "A native enum forward reference unexpectedly projected members.");
                    return null;
                }
                node = (EnumDeclarationSyntax)base.VisitEnumDeclaration(node);
                if (facts != null)
                {
                    owner.projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                    node = node.AddAttributeLists(owner.GetAttributes(facts).ToArray());
                }
                return node;
            }

            public override SyntaxNode VisitEnumMemberDeclaration(EnumMemberDeclarationSyntax node)
            {
                var facts = FindFacts(node.AttributeLists, node);
                node = (EnumMemberDeclarationSyntax)base.VisitEnumMemberDeclaration(node);
                if (facts != null)
                {
                    owner.projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                    node = node.AddAttributeLists(owner.GetAttributes(facts).ToArray());
                }
                return node;
            }

            public override SyntaxNode VisitDelegateDeclaration(DelegateDeclarationSyntax node)
            {
                var facts = FindFacts(node.AttributeLists, node);
                if (facts?.Declaration is TypedefNameDecl alias && owner.callbackOrigins.TryGetValue(alias, out var origin) && alias != origin)
                {
                    var template = owner.GetCallbackTemplate(alias, facts.Location);
                    node = node.WithParameterList(template.ParameterList).WithReturnType(template.ReturnType)
                        .WithAttributeLists(SyntaxFactory.List(node.AttributeLists.Where(list => list.Target?.Identifier.ValueText != "return")))
                        .AddAttributeLists(template.AttributeLists.Where(list => list.Target?.Identifier.ValueText == "return").ToArray());
                    if (template.Modifiers.Any(SyntaxKind.UnsafeKeyword) && !node.Modifiers.Any(SyntaxKind.UnsafeKeyword))
                        node = node.WithModifiers(node.Modifiers.Add(SyntaxFactory.Token(SyntaxKind.UnsafeKeyword)));
                    var callConvention = template.AttributeLists.Where(list => list.Attributes.Any(attribute => attribute.Name.ToString() == "UnmanagedFunctionPointer"));
                    node = node.WithAttributeLists(SyntaxFactory.List(node.AttributeLists.Where(list =>
                        !list.Attributes.Any(attribute => attribute.Name.ToString() == "UnmanagedFunctionPointer"))))
                        .AddAttributeLists(callConvention.ToArray());
                }
                node = (DelegateDeclarationSyntax)base.VisitDelegateDeclaration(node);
                if (facts != null)
                {
                    owner.projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                    node = node.AddAttributeLists(owner.GetAttributes(facts).ToArray());
                }
                return node;
            }
        }
    }
}

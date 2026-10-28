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
using MetadataUtils;

namespace Win32MetadataScraper
{
    internal sealed partial class HeaderAnnotationProcessor
    {
        private const string MetadataNamespace = "global::Windows.Win32.Foundation.Metadata.";
        private const string CleanupReferencePrefix = HeaderAnnotation.OwnerPrefix + "FunctionDecl:";
        private const string EnumReferencePrefix = HeaderAnnotation.OwnerPrefix + "EnumName:";
        private readonly Dictionary<NamedDecl, DeclarationFacts> declarations = new();
        private readonly Dictionary<(string File, uint Line, uint Column), List<DeclarationFacts>> projectionLocations = new();
        private readonly Dictionary<string, string> remaps;
        private IReadOnlyDictionary<string, string> storageTypeRemaps;
        private readonly IReadOnlyDictionary<string, string> projectionTypeRemaps;
        private readonly Dictionary<CXCursor, string> nativeTypedefStorageRemaps = new();
        private readonly List<DeclarationFacts> annotatedTypedefs = new();
        private readonly HashSet<NamedDecl> projectedDeclarations = new();
        private readonly string generatedNamespace;
        private readonly IReadOnlyList<string> traversalNames;
        private readonly ISet<string> excludedNames;
        private readonly bool excludeFunctionsWithBody;
        private readonly bool parseHeaderAnnotations;
        private readonly IReadOnlySet<CXCursor> includedDeclarations;
        private readonly int nativePointerSize;
        private readonly HashSet<CXCursor> recordPointees = new();
        private readonly Dictionary<CXCursor, string> projectedRecordNames = new();
        private readonly HashSet<CXCursor> requiredTypedefs = new();
        private readonly Dictionary<TypedefNameDecl, TypedefNameDecl> callbackOrigins = new();
        private readonly Dictionary<TypedefNameDecl, DelegateDeclarationSyntax> callbackTemplates = new();
        private readonly List<(CXCursor Declaration, NamedDecl Target, NativeLocation Location)> enumAssociations = new();
        private readonly HashSet<CXCursor> enumReferenceCarriers = new();
        private readonly List<(VarDecl Declaration, Attr Target)> methodCarriers = new();
        private readonly List<(VarDecl Declaration, Attr Target)> parameterCarriers = new();
        private readonly List<(VarDecl Declaration, Attr Target)> fieldCarriers = new();
        private readonly HashSet<Cursor> visited = new();
        private readonly List<(NamedDecl Owner, NamedDecl Target, string Name, string[] Arguments, NativeLocation Location)> cleanupReferences = new();
        private readonly List<(NamedDecl Owner, NamedDecl Target, string Name, string[] Arguments, NativeLocation Location)> enumNameReferences = new();
        private readonly HashSet<(CXCursor Declaration, int Parameter)> invalidDeclarations = new();
        private readonly List<(HeaderAnnotationException Error, string Target)> annotationErrors = new();
        private readonly Dictionary<CXFile, byte[]> parameterCommentSources = new();
        private NativeNameLookup nativeNames;

        internal IEnumerable<string> AnnotationCarrierNames => methodCarriers.Concat(parameterCarriers).Concat(fieldCarriers)
            .Select(carrier => carrier.Declaration.Name);

        internal IEnumerable<string> GetAssociatedConstantCandidateNames() => declarations.Values
            .Where(facts => facts.AnnotationOwner == facts)
            .SelectMany(facts => facts.Annotations.Where(annotation => annotation.Name == "AssociatedConstant"))
            .Select(annotation => annotation.Arguments[0]).Distinct(StringComparer.Ordinal);

        internal IReadOnlyList<MacroDefinitionRecord> GetAssociatedConstantMacros()
        {
            using var timing = GenerationTiming.BeginSpan("annotations.select-associated-constants");
            var macrosByName = visited.OfType<MacroDefinitionRecord>().ToLookup(macro => macro.Name, StringComparer.Ordinal);
            var selected = new Dictionary<string, MacroDefinitionRecord>(StringComparer.Ordinal);
            foreach (var facts in declarations.Values.Where(facts => facts.AnnotationOwner == facts &&
                projectedDeclarations.Contains(facts.Declaration)))
                foreach (var annotation in facts.Annotations.Where(annotation => annotation.Name == "AssociatedConstant"))
                    CollectAnnotationErrors(facts.Declaration, () =>
                    {
                        string name = annotation.Arguments[0];
                        var macros = macrosByName[name].ToArray();
                        // A native constant or another partition can supply the associated name.
                        if (macros.Length == 0)
                            return;
                        var macro = macros.FirstOrDefault(value => !value.IsFunctionLike);
                        if (macro == null)
                            throw Error(facts.Location, $"AssociatedConstant macro '{name}' must be an object-like constant.");
                        selected.TryAdd(name, macro);
                    });
            return selected.Values.OrderBy(macro => macro.Name, StringComparer.Ordinal).ToArray();
        }

        internal void RejectAssociatedConstant(MacroDefinitionRecord macro, IEnumerable<NativeConstantIssue> issues)
        {
            var location = GetLocation(macro.Location);
            annotationErrors.Add((Error(location, $"Associated constant '{macro.Name}' has no valid native integer value: " +
                string.Join("; ", issues.Select(issue => issue.Reason + " " + string.Join(" ", issue.Diagnostics)))), macro.Name));
        }

        internal HeaderAnnotationProcessor(TranslationUnit translationUnit, Dictionary<string, string> remaps, string generatedNamespace,
            IReadOnlyList<string> traversalNames, ISet<string> excludedNames, bool excludeFunctionsWithBody,
            IReadOnlySet<CXCursor> includedDeclarations = null, bool inferNativeTypedefs = false, bool parseHeaderAnnotations = true,
            IReadOnlyDictionary<string, string> projectionTypeRemaps = null)
        {
            using var timing = GenerationTiming.BeginSpan("annotations.discovery");
            this.remaps = remaps;
            storageTypeRemaps = remaps;
            this.projectionTypeRemaps = projectionTypeRemaps ?? remaps;
            this.generatedNamespace = generatedNamespace;
            this.traversalNames = traversalNames;
            this.excludedNames = excludedNames;
            this.excludeFunctionsWithBody = excludeFunctionsWithBody;
            this.parseHeaderAnnotations = parseHeaderAnnotations;
            this.includedDeclarations = includedDeclarations;
            using (var target = translationUnit.Handle.TargetInfo)
                nativePointerSize = target.PointerWidth / 8;
            using (GenerationTiming.BeginSpan("annotations.discover-constant-groups"))
                InitializeConstantGroups(translationUnit);
            using (var walkTiming = GenerationTiming.BeginSpan("annotations.walk-native-ast"))
            {
                Walk(translationUnit.TranslationUnitDecl);
                walkTiming?.SetCounter("cursorCount", visited.Count);
            }
            using var resolutionTiming = GenerationTiming.BeginSpan("annotations.resolve-native-facts");
            if (parseHeaderAnnotations)
            {
                ApplyMethodAnnotations();
                ApplyParameterAnnotations();
                ApplyFieldAnnotations();
                ApplyCommentAnnotations(translationUnit);
            }
            ResolveEnumNameReferences();
            foreach (var facts in declarations.Values.Where(value => value.HasMidlRetval))
                CollectAnnotationErrors(facts.Declaration, () =>
                {
                    if (!facts.Annotations.Any(annotation => annotation.Name == "RetVal"))
                        AddAnnotation(facts, new HeaderAnnotation("RetVal", Array.Empty<string>()), facts.Location);
                });
            ResolveCleanupReferences();
            foreach (var association in enumAssociations)
                CollectAnnotationErrors(association.Target, () =>
                {
                    if (!invalidDeclarations.Contains((association.Declaration.CanonicalCursor, -1)) &&
                        association.Declaration.Kind != CXCursorKind.CXCursor_EnumDecl &&
                        !declarations.Values.Any(facts => facts.LogicalEnumMembers != null &&
                            facts.Declaration.Handle.CanonicalCursor == association.Declaration.CanonicalCursor))
                        throw Error(association.Location, "AssociatedEnum requires a native enum or a _Win32_Enum_/_Win32_FlagsEnum_ group.");
                });
            MergeRedeclarationFacts();
            if (inferNativeTypedefs)
                DiscoverNativeTypedefs();
            ThrowAnnotationErrors();
            TransferRecordTypedefFacts();
            resolutionTiming?.Dispose();
            using var indexTiming = GenerationTiming.BeginSpan("annotations.index-projections");
            foreach (var facts in declarations.Values)
            {
                // Match ClangSharp's GetFileLocation transport, including macro arguments.
                facts.Declaration.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
                var location = (file.ToString(), line, column);
                if (!projectionLocations.TryGetValue(location, out var candidates))
                    projectionLocations[location] = candidates = new();
                candidates.Add(facts);
            }
            timing?.SetCounter("declarationCount", declarations.Count);
            timing?.SetCounter("annotatedTypedefCount", annotatedTypedefs.Count);
            timing?.SetCounter("carrierCount", methodCarriers.Count + parameterCarriers.Count + fieldCarriers.Count);
        }

        internal void PrepareTypedefs()
        {
            using var timing = GenerationTiming.BeginSpan("annotations.prepare-typedefs");
            foreach (var facts in annotatedTypedefs)
            {
                var alias = (TypedefNameDecl)facts.Declaration;
                if (facts.LogicalEnumMembers != null)
                    continue;
                bool primaryRecord = alias.UnderlyingType.CanonicalType is RecordType record && Remap(record.Decl.Name) == Remap(alias.Name);
                if ((GetFunctionType(alias.UnderlyingType) == null || alias is TypeAliasDecl) && !primaryRecord)
                {
                    if (facts.HasNativeTypedefIdentity &&
                        remaps.TryGetValue(alias.Name, out string mapped) && IsStorageTypeName(mapped))
                    {
                        nativeTypedefStorageRemaps[alias.Handle.CanonicalCursor] = mapped;
                        remaps[alias.Name] = alias.Name;
                    }

                    else
                        remaps.TryAdd(alias.Name, alias.Name);
                }
            }
        }

        internal Dictionary<string, string> CreateBindingRemaps(DiscoveryResult discovery,
            IReadOnlyDictionary<string, string> names, ISet<string> autoRemapExcludes)
        {
            var bindings = RemapDiscovery.CreateBindingRemaps(discovery, names, autoRemapExcludes);
            foreach (var facts in annotatedTypedefs)
            {
                string nativeName = facts.Declaration.Name;
                string name = names.GetValueOrDefault(nativeName) ?? nativeName;
                if (IsStorageTypeName(name))
                    name = nativeName;
                if (SyntaxFacts.GetKeywordKind(name) != SyntaxKind.None)
                    // ClangSharp consumes the first @ as a force-remap marker.
                    bindings[nativeName] = "@" + EscapeIdentifier(name);
            }
            return bindings;
        }

        internal bool RequiresRecordProjectionIdentity => recordPointees.Count != 0;

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
                    cleanupReferences.Add((owner, facts.Declaration, cleanup, annotationArguments, location));
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
                if (UnwrapArgument(arguments[0]) is StringLiteral)
                {
                    string reference = ReadStringArgument(arguments[0], location);
                    if (!reference.StartsWith(EnumReferencePrefix, StringComparison.Ordinal))
                        throw Error(location, "AssociatedEnum requires a tagged enum name, not an untagged string.");
                    return ReadEnumNameReference(owner, facts, reference[EnumReferencePrefix.Length..], location);
                }
                var declaration = clang.getTypeDeclaration(arguments[0].Handle.Type);
                if (declaration.IsNull)
                    throw Error(location, "AssociatedEnum requires a named native enum or metadata group type.");
                if (arguments[0] is Expr expression && expression.Type.CanonicalType is EnumType nativeEnum)
                {
                    declaration = nativeEnum.Decl.Handle;
                    if (IsForwardEnumReference(nativeEnum.Decl))
                        enumReferenceCarriers.Add(declaration.CanonicalCursor);
                }
                enumAssociations.Add((declaration, facts.Declaration, location));
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
                    return new LogicalEnumMember(name, $"unchecked(({storage}){value.ToString(CultureInfo.InvariantCulture)}UL)",
                        value & mask, new[] { ReadConstantBinding(attribute, name, argument, location) });
                }).ToArray();
                facts.LogicalEnumMembers = MergeEnumMembers(facts.LogicalEnumMembers, members, location);
                facts.IsFlagsEnum = annotation.Name == "FlagsEnum";
            }
            else if (annotation.Name == "NativeTypedef" && arguments.Length != 0)
                throw Error(location, "Annotation 'NativeTypedef' expects no value or compiler arguments.");
            else if (arguments.Length != 0 || annotation.Name is "RAIIFree" or "ImportLibrary" or "AssociatedEnum")
                throw Error(location, $"'{annotation.Name}' requires compiler-parsed annotation arguments; include win32metadata_annotations.h.");
            return annotation;
        }

        private HeaderAnnotation ReadEnumNameReference(NamedDecl owner, DeclarationFacts facts, string name, NativeLocation location)
        {
            name = Regex.Replace(name.Trim(), @"\s*::\s*", "::");
            name = Regex.Replace(name, @"^enum\s+", "");
            if (!Regex.IsMatch(name, @"^(?:::)?[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*$") ||
                name is "void" or "bool" or "char" or "short" or "int" or "long" or "signed" or "unsigned" or
                    "float" or "double" or "wchar_t" or "char8_t" or "char16_t" or "char32_t")
                throw Error(location, "AssociatedEnum requires a native enum or metadata group name.");
            var arguments = new[] { name };
            enumNameReferences.Add((owner, facts.Declaration, name, arguments, location));
            return new HeaderAnnotation("AssociatedEnum", arguments);
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
            nativeNames ??= new NativeNameLookup(visited);
            foreach (var reference in cleanupReferences)
                CollectAnnotationErrors(reference.Target, () =>
                {
                    var candidates = nativeNames.Resolve(reference.Owner, reference.Name, reference.Location);
                    if (candidates.Length != 1 || candidates[0].Handle.Kind != CXCursorKind.CXCursor_FunctionDecl)
                        throw Error(reference.Location, $"RAIIFree cleanup '{reference.Name}' must identify one declared native cleanup function; found {candidates.Length} candidates.");
                    reference.Arguments[0] = candidates[0].Name;
                });
        }

        private void ResolveEnumNameReferences()
        {
            if (enumNameReferences.Count == 0)
                return;
            nativeNames ??= new NativeNameLookup(visited);
            foreach (var reference in enumNameReferences)
                CollectAnnotationErrors(reference.Target, () =>
                {
                    var candidates = nativeNames.Resolve(reference.Owner, reference.Name, reference.Location)
                        .Select(UnwrapTypeDeclaration).GroupBy(value => value.Handle.CanonicalCursor)
                        .Select(group => group.First()).ToArray();
                    if (candidates.Length == 0 && !reference.Name.Contains("::", StringComparison.Ordinal))
                    {
                        // Another partition or retained enum source supplies the final definition.
                        reference.Arguments[0] = Remap(reference.Name);
                        return;
                    }
                    if (candidates.Length != 1)
                        throw Error(reference.Location, $"AssociatedEnum reference '{reference.Name}' must identify one native enum or metadata group; found {candidates.Length} candidates.");
                    var declaration = candidates[0];
                    enumAssociations.Add((declaration.Handle, reference.Target, reference.Location));
                    if (declaration is EnumDecl nativeEnum && IsForwardEnumReference(nativeEnum))
                        enumReferenceCarriers.Add(declaration.Handle.CanonicalCursor);
                    reference.Arguments[0] = Remap(declaration.Name);
                });
        }

        private static CXCursor ReadDeclarationReference(Cursor argument, CXCursorKind kind, NativeLocation location, string message)
        {
            var references = GetDeclarationReferences(argument);
            if (references.Count != 1 || references.Single().Kind != kind)
                throw Error(location, message);
            return references.Single();
        }

        private static HashSet<CXCursor> GetDeclarationReferences(Cursor argument)
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
            return references;
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
            => PrepareProjections(sources.Select(source => GeneratedSource.FromText(source).Root), typeRemaps);

        internal void PrepareProjections(IEnumerable<CompilationUnitSyntax> sources, IReadOnlyDictionary<string, string> typeRemaps)
        {
            using var timing = GenerationTiming.BeginSpan("annotations.prepare-projections");
            storageTypeRemaps = typeRemaps;
            var rewriter = new ProjectionRewriter(this);
            foreach (var source in sources)
                foreach (var node in source.DescendantNodes(descendIntoChildren: node =>
                    node is CompilationUnitSyntax or BaseNamespaceDeclarationSyntax or TypeDeclarationSyntax))
                {
                    if (node is DelegateDeclarationSyntax callback)
                        rewriter.AddCallbackTemplate(callback);
                    else if (node is StructDeclarationSyntax record)
                        rewriter.AddRecordProjection(record);
                }
        }

        internal string Rewrite(string source)
            => GeneratedSource.FromRoot(Rewrite(GeneratedSource.FromText(source).Root)).Text;

        internal CompilationUnitSyntax Rewrite(CompilationUnitSyntax root)
        {
            using var timing = GenerationTiming.BeginSpan("annotations.apply-to-source");
            timing?.SetCounter("sourceCharacters", root.FullSpan.Length);
            return (CompilationUnitSyntax)new ProjectionRewriter(this).Visit(root);
        }

        internal string GetAdditionalTypes()
        {
            using var timing = GenerationTiming.BeginSpan("annotations.native-type-providers");
            timing?.SetCounter("annotatedTypedefCount", annotatedTypedefs.Count);
            var members = new List<MemberDeclarationSyntax>();
            foreach (var facts in annotatedTypedefs)
            {
                var alias = (TypedefNameDecl)facts.Declaration;
                try
                {
                string name = Remap(alias.Name);
                if (projectedDeclarations.Contains(facts.AnnotationOwner.Declaration))
                    continue;
                if (!ShouldProjectTypedef(alias, facts.Location))
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
                    logicalEnum = NativeConstantGroupProvenance.Attach(logicalEnum, GetConstantGroupSource(facts));
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
                // ABI storage remaps do not rename annotated native wrappers.
                if (IsStorageTypeName(name))
                    name = alias.Name;
                name = EscapeIdentifier(name);
                string valueType = nativeTypedefStorageRemaps.TryGetValue(alias.Handle.CanonicalCursor, out string pointerStorage) &&
                    SyntaxFactory.ParseTypeName(pointerStorage) is PointerTypeSyntax
                    ? GetNativeIntegerStorage(pointerStorage) ?? pointerStorage
                    : GetSignatureType(alias.UnderlyingType, facts.Location, underlyingStorage: true,
                        preserveNativeShape: facts.HasNativeTypedefIdentity);
                var declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                    $"[{MetadataNamespace}NativeTypedef] public unsafe partial struct {name} {{ public {valueType} Value; }}");
                if (declaration == null || declaration.ContainsDiagnostics || declaration.Members.Count != 1 ||
                    declaration.Members[0] is not FieldDeclarationSyntax)
                    throw Error(facts.Location, $"Cannot project native typedef '{alias.Name}' as managed '{name}' with storage '{valueType}'.");
                if (facts.IsInferredTypedef)
                    declaration = declaration.ReplaceNode(declaration.Members.Single(),
                        ((FieldDeclarationSyntax)declaration.Members.Single()).AddAttributeLists(
                            MakeAttribute($"NativeTypeName({HeaderAnnotation.Quote(alias.UnderlyingType.AsString)})")));
                declaration = declaration.AddAttributeLists(GetAttributes(facts).ToArray());
                if (SyntaxFactory.ParseTypeName(valueType) is PointerTypeSyntax { ElementType: NameSyntax } &&
                    NativeHandleOrigins.IsDeclareHandle(alias, visited))
                    declaration = MetadataUtils.NativeHandleSourceProvenance.AttachHeaderDeclareHandle(
                        declaration, DeclarationSourceMap.QualifiedName(alias.Handle), valueType);
                else if (SyntaxFactory.ParseTypeName(valueType) is PointerTypeSyntax { ElementType: NameSyntax } &&
                    TryGetOpaqueStructPointer(facts, alias, out var nativeRecord))
                    declaration = MetadataUtils.NativeHandleSourceProvenance.AttachHeaderOpaqueStructPointer(
                        declaration, DeclarationSourceMap.QualifiedName(alias.Handle),
                        DeclarationSourceMap.QualifiedName(nativeRecord.Decl.Handle), valueType, explicitWrapperIntent: true);
                members.Add(declaration);
                projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                }
                catch (HeaderAnnotationException error)
                {
                    invalidDeclarations.Add(GetNativeIdentity(alias));
                    annotationErrors.Add((error, GetNativeTarget(alias.Handle)));
                }
            }
            timing?.SetCounter("memberCount", members.Count);
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
            using var timing = GenerationTiming.BeginSpan("annotations.validate-projection");
            foreach (var facts in declarations.Values)
                CollectAnnotationErrors(facts.Declaration, () =>
                {
                    if ((facts.HasNativeTypedefIdentity || facts.Annotations.Count != 0 || facts.MidlDirection != ParameterAttributes.None || facts.IsScopedEnum || facts.IsFlagsEnum) &&
                        (ShouldEmit(facts.Declaration, facts.Location) ||
                            facts.IsInferredTypedef && ShouldProjectTypedef((TypedefNameDecl)facts.Declaration, facts.Location)) &&
                        !projectedDeclarations.Contains(facts.AnnotationOwner.Declaration))
                        throw Error(facts.Location, $"Annotation facts for '{facts.Declaration.Name}' were not projected by ClangSharp.");
                });
            ThrowAnnotationErrors();
        }

        private void Walk(Cursor cursor)
        {
            if (!visited.Add(cursor))
                return;
            if (cursor is NamedDecl declaration)
                CollectAnnotationErrors(declaration, () => ReadDeclaration(declaration));
            foreach (var child in cursor.CursorChildren)
            {
                if (!child.Handle.IsAttribute && !child.Handle.IsReference && !child.Handle.IsExpression)
                    Walk(child);
            }
        }

        private void ReadDeclaration(NamedDecl declaration)
        {
            var location = GetLocation(declaration.Location);
            var targets = declaration.Attrs.Where(attribute =>
                attribute.Kind == CX_AttrKind.CX_AttrKind_Annotate &&
                attribute.Spelling is HeaderAnnotation.OwnerPrefix + "Method" or HeaderAnnotation.OwnerPrefix + "Parameter" or
                    HeaderAnnotation.OwnerPrefix + "Field").ToArray();
            if (targets.Length != 0)
            {
                string kind = HeaderAnnotation.RemoveOwnerPrefix(targets[0].Spelling);
                var carriers = kind switch
                {
                    "Parameter" => parameterCarriers,
                    "Field" => fieldCarriers,
                    _ => methodCarriers,
                };
                string prefix = "_WIN32META_" + kind.ToUpperInvariant() + "_";
                if (!parseHeaderAnnotations)
                {
                    if (declaration is VarDecl ignored && ignored.Name.StartsWith(prefix, StringComparison.Ordinal))
                    {
                        carriers.Add((ignored, targets[0]));
                        return;
                    }
                }
                else
                {
                    if (targets.Length != 1 || declaration is not VarDecl variable ||
                        variable.Handle.StorageClass != CX_StorageClass.CX_SC_Static ||
                        variable.Type.CanonicalType.Kind != CXTypeKind.CXType_UChar ||
                        !variable.Type.Handle.IsConstQualified ||
                        !variable.Name.StartsWith(prefix, StringComparison.Ordinal))
                        throw Error(location, $"{kind} annotations require the metadata-only _Win32_Annotate{kind}_ carrier.");
                    carriers.Add((variable, targets[0]));
                    return;
                }
            }
            var facts = new DeclarationFacts(declaration, location);
            string parameterComment = parseHeaderAnnotations && declaration is ParmVarDecl ? GetLegacyParameterComment(declaration) : null;
            if (parseHeaderAnnotations && declaration is ParmVarDecl)
            {
                if (!HasSalParameterDirection(declaration))
                    facts.MidlDirection = GetMidlDirection(parameterComment);
            }
            if (parseHeaderAnnotations)
                ReadAnnotations(declaration, facts);
            if (invalidDeclarations.Contains(GetNativeIdentity(declaration)))
                return;
            if (parseHeaderAnnotations && declaration is ParmVarDecl)
            {
                if (parameterComment.Contains("[retval]", StringComparison.OrdinalIgnoreCase))
                {
                    var retval = new HeaderAnnotation("RetVal", Array.Empty<string>());
                    ValidateTarget(facts, retval, location);
                    facts.HasMidlRetval = true;
                }
            }
            if (parseHeaderAnnotations && declaration is EnumDecl enumDeclaration)
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

        private void ApplyMethodAnnotations()
        {
            foreach (var carrier in methodCarriers)
                CollectAnnotationErrors(carrier.Declaration, () =>
                {
                    var location = GetLocation(carrier.Target.Location);
                    var arguments = carrier.Target.CursorChildren.ToArray();
                    if (arguments.Length != 1)
                        throw Error(location, "A method carrier requires one compiler-parsed native method reference.");
                    var target = ReadDeclarationReference(arguments[0], CXCursorKind.CXCursor_CXXMethod, location,
                        "A method carrier requires a reference to a declared native interface method.");
                    if (invalidDeclarations.Contains((target, -1)))
                        return;
                    var facts = declarations.Values.FirstOrDefault(item => item.Declaration.Handle.CanonicalCursor == target);
                    if (facts == null)
                        throw Error(location, "The referenced method was not found in the original Clang AST.");
                    if (!carrier.Declaration.Attrs.Any(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Annotate &&
                        attribute.Spelling != HeaderAnnotation.OwnerPrefix + "Method" && HeaderAnnotation.IsKnownPayload(attribute.Spelling)))
                        throw Error(location, "A method carrier requires at least one metadata annotation.");
                    ReadAnnotations(carrier.Declaration, facts);
                }, () => GetCarrierTarget(carrier.Target));
        }

        private void ApplyParameterAnnotations()
        {
            foreach (var carrier in parameterCarriers)
                CollectAnnotationErrors(carrier.Declaration, () =>
                {
                    var location = GetLocation(carrier.Target.Location);
                    var arguments = carrier.Target.CursorChildren.ToArray();
                    if (arguments.Length != 2)
                        throw Error(location, "A parameter carrier requires a compiler-parsed method reference and native parameter name.");
                    var target = ReadDeclarationReference(arguments[0], CXCursorKind.CXCursor_CXXMethod, location,
                        "A parameter carrier requires a reference to a declared native interface method.");
                    if (invalidDeclarations.Contains((target, -1)))
                        return;
                    string name = ReadStringArgument(arguments[1], location);
                    if (!Regex.IsMatch(name, @"^[A-Za-z_]\w*$"))
                        throw Error(location, "A parameter carrier requires one native parameter identifier.");
                    var method = declarations.Keys.OfType<CXXMethodDecl>()
                        .FirstOrDefault(declaration => declaration.Handle.CanonicalCursor == target);
                    var parameters = method?.Parameters.Where(parameter => parameter.Name == name).ToArray();
                    if (parameters?.Length == 1 && invalidDeclarations.Contains(GetNativeIdentity(parameters[0])))
                        return;
                    if (parameters?.Length != 1 || !declarations.TryGetValue(parameters[0], out var facts))
                        throw Error(location, $"The native parameter '{name}' does not uniquely identify a parameter of the referenced method.");
                    if (!carrier.Declaration.Attrs.Any(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Annotate &&
                        attribute.Spelling != HeaderAnnotation.OwnerPrefix + "Parameter" && HeaderAnnotation.IsKnownPayload(attribute.Spelling)))
                        throw Error(location, "A parameter carrier requires at least one metadata annotation.");
                    ReadAnnotations(carrier.Declaration, facts);
                }, () => GetCarrierTarget(carrier.Target));
        }

        private void ApplyFieldAnnotations()
        {
            foreach (var carrier in fieldCarriers)
                CollectAnnotationErrors(carrier.Declaration, () =>
                {
                    var location = GetLocation(carrier.Target.Location);
                    var arguments = carrier.Target.CursorChildren.ToArray();
                    if (arguments.Length != 1)
                        throw Error(location, "A field carrier requires one compiler-parsed native field reference.");
                    var target = ReadDeclarationReference(arguments[0], CXCursorKind.CXCursor_FieldDecl, location,
                        "A field carrier requires a reference to a declared native instance field.");
                    if (invalidDeclarations.Contains((target, -1)))
                        return;
                    var facts = declarations.Values.FirstOrDefault(item => item.Declaration is FieldDecl &&
                        item.Declaration.Handle.CanonicalCursor == target);
                    if (facts == null)
                        throw Error(location, "The referenced field was not found in the original Clang AST.");
                    if (!carrier.Declaration.Attrs.Any(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Annotate &&
                        attribute.Spelling != HeaderAnnotation.OwnerPrefix + "Field" && HeaderAnnotation.IsKnownPayload(attribute.Spelling)))
                        throw Error(location, "A field carrier requires at least one metadata annotation.");
                    ReadAnnotations(carrier.Declaration, facts);
                }, () => GetCarrierTarget(carrier.Target));
        }

        private void ReadAnnotations(NamedDecl declaration, DeclarationFacts facts)
            => CollectAnnotationErrors(declaration, () => ReadAnnotationFacts(declaration, facts),
                () => GetNativeTarget(facts.Declaration.Handle), facts.Declaration);

        private void ReadAnnotationFacts(NamedDecl declaration, DeclarationFacts facts)
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
                AddAnnotation(facts, annotation, attributeLocation);
            }
        }

        private void AddAnnotation(DeclarationFacts facts, HeaderAnnotation annotation, NativeLocation location)
        {
            ValidateTarget(facts, annotation, location);
            if (annotation.Name != "AssociatedConstant")
            {
                var existing = facts.Annotations.FirstOrDefault(item => item.Name == annotation.Name);
                if (existing != null)
                {
                    if (annotation.Name is "Enum" or "FlagsEnum" or "NativeTypedef")
                        return;
                    if (annotation.Name != "SupportedOSPlatform")
                        throw Error(location, $"Duplicate '{annotation.Name}' annotation.");
                    if (!existing.Arguments.SequenceEqual(annotation.Arguments))
                        throw Error(location, $"Conflicting 'SupportedOSPlatform' annotations on '{facts.Declaration.Name}'. Clang scopes accumulate; close the prior scope before changing floors.");
                    return;
                }
            }
            facts.Annotations.Add(annotation);
        }

        private void MergeRedeclarationFacts()
        {
            foreach (var group in declarations.Values.GroupBy(facts => GetNativeIdentity(facts.Declaration)))
                CollectAnnotationErrors(group.First().Declaration, () => MergeRedeclarationGroup(group.ToArray()));
        }

        private void MergeRedeclarationGroup(DeclarationFacts[] group)
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
            if (owner.LogicalEnumMembers != null && owner.Annotations.Any(annotation => annotation.Name == "NativeTypedef"))
                throw Error(owner.Location, "'NativeTypedef' is not valid on a logical enum group.");
            foreach (var facts in group)
            {
                facts.AnnotationOwner = owner;
                facts.Annotations = owner.Annotations;
                facts.InvalidValues = owner.InvalidValues;
                facts.IsScopedEnum = owner.IsScopedEnum;
                facts.IsFlagsEnum = owner.IsFlagsEnum;
                facts.LogicalEnumMembers = owner.LogicalEnumMembers;
                facts.MidlDirection = directions.SingleOrDefault();
                // Traversed typedefs can inherit group or explicit identity facts from another redeclaration.
                if (facts.Declaration is TypedefNameDecl &&
                    (facts.LogicalEnumMembers != null || facts.Annotations.Any(annotation => annotation.Name == "NativeTypedef")) &&
                    !annotatedTypedefs.Contains(facts))
                    annotatedTypedefs.Add(facts);
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
                    int index = members.FindIndex(existingMember => existingMember.Name == member.Name);
                    members[index] = members[index] with
                    {
                        Bindings = members[index].Bindings.Concat(member.Bindings).Distinct().ToArray(),
                    };
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

        private void ValidateTarget(DeclarationFacts facts, HeaderAnnotation annotation, NativeLocation location)
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
                "Flags" => declaration is EnumDecl,
                "NativeTypedef" => declaration is TypedefDecl && facts.LogicalEnumMembers == null,
                "AlsoUsableFor" => typedef && facts.LogicalEnumMembers == null,
                "RAIIFree" => function || parameter,
                "Retained" or "ContainsInteriorPointers" or "RetVal" or "Reserved" or "Optional" or "ComOutPtr" => parameter,
                _ => false,
            };
            if (!valid)
                throw Error(location, $"'{annotation.Name}' is not valid on {declaration.Handle.DeclKind} '{declaration.Name}'.");
            if (annotation.Name == "NativeTypedef")
                ValidateNativeTypedefType(((TypedefDecl)declaration).UnderlyingType, location);
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
                bool inputOnly = facts.MidlDirection == ParameterAttributes.In ||
                    salNames.Any(name => name.StartsWith("_In_", StringComparison.Ordinal) ||
                    name == "__RPC__in" || name.StartsWith("__RPC__in_", StringComparison.Ordinal));
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

        private void DiscoverNativeTypedefs()
        {
            var dependencies = new HashSet<ClangSharp.Type>();
            foreach (var facts in declarations.Values.Where(facts =>
                ShouldEmit(facts.Declaration, facts.Location) && !HasTemplateContext(facts.Declaration)).ToArray())
            {
                switch (facts.Declaration)
                {
                    case FunctionDecl function:
                        RequireTypedefDependencies(function.ReturnType, dependencies);
                        foreach (var parameter in function.Parameters)
                            RequireTypedefDependencies(parameter.Type, dependencies);
                        break;
                    case FieldDecl field:
                        RequireTypedefDependencies(field.Type, dependencies);
                        break;
                    case TypedefNameDecl alias:
                        RequireTypedefDependencies(alias.UnderlyingType, dependencies);
                        break;
                }
            }
            foreach (var facts in declarations.Values)
            {
                if (facts.Declaration is not TypedefDecl alias || facts.LogicalEnumMembers != null ||
                    !ShouldProjectTypedef(alias, facts.Location) || HasTemplateContext(alias))
                    continue;
                var type = alias.UnderlyingType.CanonicalType;
                if (type.Kind == CXTypeKind.CXType_Void || type is RecordType or EnumType or ArrayType or ReferenceType or FunctionType)
                    continue;
                if (facts.Annotations.Count == 0 && GetNativeTypedefScalarSize(type.Kind) != 0 &&
                    SyntaxFactory.ParseTypeName(alias.Name) is PredefinedTypeSyntax &&
                    GetManagedType(type, facts.Location) == alias.Name &&
                    (!projectionTypeRemaps.TryGetValue(alias.Name, out string primitiveRemap) || primitiveRemap == alias.Name))
                    continue;
                if (type is not PointerType && facts.Annotations.Count == 0 &&
                    projectionTypeRemaps.TryGetValue(alias.Name, out string mapped) && GetNativeIntegerStorage(mapped) != null)
                {
                    CollectAnnotationErrors(alias, () =>
                    {
                        ValidateNativeIntegerStorage(alias, mapped, facts.Location);
                        remaps[alias.Name] = mapped;
                    });
                    continue;
                }
                if (!IsNativeTypedefCandidate(type))
                    continue;
                var terminal = type;
                while (terminal is PointerType pointer)
                    terminal = pointer.PointeeType.CanonicalType;
                CollectAnnotationErrors(alias, () =>
                {
                    if (type is PointerType && projectionTypeRemaps.TryGetValue(alias.Name, out string pointerMapping) &&
                        IsStorageTypeName(pointerMapping))
                        ValidateNativePointerStorage(alias, pointerMapping, facts.Location);
                    ValidateNativeTypedefType(alias.UnderlyingType, facts.Location);
                    if (type is PointerType nativePointer && nativePointer.Handle.SizeOf != nativePointerSize &&
                        (alias.Handle.Type.SizeOf != nativePointer.Handle.SizeOf ||
                            alias.Handle.Type.AlignOf != nativePointer.Handle.AlignOf))
                        throw Error(facts.Location, $"Native pointer alias '{alias.Name}' has an unsupported size or alignment.");
                    facts.IsInferredTypedef = true;
                    if (type is PointerType && terminal is RecordType record)
                        recordPointees.Add(record.Decl.Handle.CanonicalCursor);
                    if (!annotatedTypedefs.Contains(facts))
                        annotatedTypedefs.Add(facts);
                });
            }
        }

        private static bool IsNativeTypedefCandidate(ClangSharp.Type type)
        {
            type = type.CanonicalType;
            bool pointee = false;
            while (type is PointerType pointer)
            {
                if (pointer.Handle.SizeOf < 0)
                    return false;
                pointee = true;
                type = pointer.PointeeType.CanonicalType;
            }
            if (pointee && (type.Kind == CXTypeKind.CXType_Void || type is RecordType or EnumType))
                return true;
            return GetNativeTypedefScalarSize(type.Kind) != 0 && type.Handle.SizeOf >= 0;
        }

        private void RequireTypedefDependencies(ClangSharp.Type type, HashSet<ClangSharp.Type> visitedTypes)
        {
            type = RemapDiscovery.UnwrapType(type);
            if (!visitedTypes.Add(type))
                return;
            switch (type)
            {
                case TypedefType typedef:
                    var alias = (TypedefNameDecl)typedef.Decl;
                    if (IsExcludedDeclaration(alias))
                        return;
                    requiredTypedefs.Add(alias.Handle.CanonicalCursor);
                    RequireTypedefDependencies(alias.UnderlyingType, visitedTypes);
                    break;
                case PointerType pointer:
                    RequireTypedefDependencies(pointer.PointeeType, visitedTypes);
                    break;
                case ReferenceType reference:
                    RequireTypedefDependencies(reference.PointeeType, visitedTypes);
                    break;
                case ArrayType array:
                    RequireTypedefDependencies(array.ElementType, visitedTypes);
                    break;
                case FunctionProtoType function:
                    RequireTypedefDependencies(function.ReturnType, visitedTypes);
                    foreach (var parameter in function.ParamTypes)
                        RequireTypedefDependencies(parameter, visitedTypes);
                    break;
                case RecordType record:
                    if (IsExcludedDeclaration(record.Decl))
                        return;
                    foreach (var field in (record.Decl.Definition ?? record.Decl).CursorChildren.OfType<FieldDecl>())
                        RequireTypedefDependencies(field.Type, visitedTypes);
                    break;
            }
        }

        private void ValidateNativeTypedefType(ClangSharp.Type type, NativeLocation location, bool pointee = false)
        {
            type = type.CanonicalType;
            if (type is PointerType pointer)
            {
                GetFixedPointerStorage(pointer, location);
                ValidateNativeTypedefType(pointer.PointeeType, location, pointee: true);
                return;
            }
            if (pointee && (type.Kind == CXTypeKind.CXType_Void || type is RecordType or EnumType))
                return;
            int size = GetNativeTypedefScalarSize(type.Kind);
            if (size == 0 || type.Handle.SizeOf != size)
                throw Error(location, $"'NativeTypedef' requires a supported native scalar or data-pointer alias; " +
                    $"unsupported underlying type '{type.AsString}'. Record values (including incomplete records), enums, callbacks, arrays, and references are not supported.");
        }

        private static int GetNativeTypedefScalarSize(CXTypeKind kind)
            => kind switch
            {
                CXTypeKind.CXType_Bool or CXTypeKind.CXType_Char_S or CXTypeKind.CXType_SChar or
                    CXTypeKind.CXType_Char_U or CXTypeKind.CXType_UChar => 1,
                CXTypeKind.CXType_Short or CXTypeKind.CXType_UShort or CXTypeKind.CXType_WChar => 2,
                CXTypeKind.CXType_Int or CXTypeKind.CXType_UInt or CXTypeKind.CXType_Long or
                    CXTypeKind.CXType_ULong or CXTypeKind.CXType_Float => 4,
                CXTypeKind.CXType_LongLong or CXTypeKind.CXType_ULongLong or CXTypeKind.CXType_Double => 8,
                _ => 0,
            };

        private string GetFixedPointerStorage(PointerType pointer, NativeLocation location)
        {
            long size = pointer.Handle.SizeOf;
            if (size == nativePointerSize)
                return null;
            if (pointer.Handle.AlignOf == size)
            {
                if (size == 4)
                    return "uint";
                if (size == 8)
                    return "ulong";
            }
            throw Error(location, $"Native pointer '{pointer.AsString}' has unsupported size {size} or alignment {pointer.Handle.AlignOf}.");
        }

        private void ValidateNativePointerStorage(TypedefNameDecl alias, string mapped, NativeLocation location)
        {
            var resolving = new HashSet<CXCursor>();
            if (!MatchesStorage(alias.UnderlyingType, SyntaxFactory.ParseTypeName(mapped)))
                throw Error(location, $"'NativeTypedef' storage remap '{alias.Name}={mapped}' does not preserve native width, alignment, and pointer depth.");

            bool MatchesStorage(ClangSharp.Type native, TypeSyntax managed)
            {
                var canonical = native.CanonicalType;
                // Retain written aliases so nominal pointees can own their desugared storage.
                var written = RemapDiscovery.UnwrapType(native);
                if (managed is PointerTypeSyntax pointer)
                {
                    while (written is TypedefType typedef)
                        written = RemapDiscovery.UnwrapType(typedef.Decl.UnderlyingType);
                    return canonical is PointerType && canonical.Handle.SizeOf == nativePointerSize &&
                        canonical.Handle.AlignOf == nativePointerSize && written is PointerType nativePointer &&
                        MatchesStorage(nativePointer.PointeeType, pointer.ElementType);
                }

                // An explicit pointer remap may give an untyped native pointee a managed view.
                if (canonical.Kind == CXTypeKind.CXType_Void)
                    return managed is PredefinedTypeSyntax or NameSyntax;
                string name = managed.ToString();
                string integerStorage = GetNativeIntegerStorage(name);
                int scalarSize = integerStorage != null ? nativePointerSize : managed is PredefinedTypeSyntax primitive
                    ? primitive.Keyword.Kind() switch
                    {
                        SyntaxKind.BoolKeyword or SyntaxKind.ByteKeyword or SyntaxKind.SByteKeyword => 1,
                        SyntaxKind.ShortKeyword or SyntaxKind.UShortKeyword or SyntaxKind.CharKeyword => 2,
                        SyntaxKind.IntKeyword or SyntaxKind.UIntKeyword or SyntaxKind.FloatKeyword => 4,
                        SyntaxKind.LongKeyword or SyntaxKind.ULongKeyword or SyntaxKind.DoubleKeyword => 8,
                        _ => 0,
                    } : 0;
                if (scalarSize != 0)
                {
                    if (canonical.Handle.SizeOf != scalarSize || canonical.Handle.AlignOf != scalarSize)
                        return false;
                    if (canonical is PointerType nativePointer)
                        return nativePointer.PointeeType.CanonicalType is not PointerType &&
                            (integerStorage != null || managed is PredefinedTypeSyntax scalar &&
                                scalar.Keyword.Kind() is not (SyntaxKind.FloatKeyword or SyntaxKind.DoubleKeyword));
                    if (integerStorage != null)
                    {
                        if (written is TypedefType typedef)
                            ValidateNativeIntegerStorage((TypedefNameDecl)typedef.Decl, name, location);
                        else if (!IsEnumStorage(canonical.Kind) ||
                            integerStorage != (IsUnsignedNativeInteger(canonical.Kind) ? "global::System.UIntPtr" : "global::System.IntPtr"))
                            return false;
                    }
                    return GetNativeTypedefScalarSize(canonical.Kind) != 0 || canonical is EnumType;
                }
                if (managed is PredefinedTypeSyntax voidType && voidType.Keyword.IsKind(SyntaxKind.VoidKeyword))
                    return canonical is not PointerType;

                // Sibling declarators share native storage without a written reference to the sibling alias.
                var namedOwners = visited.OfType<TypedefNameDecl>().Where(owner => MatchesOwnerName(owner, name))
                    .GroupBy(owner => owner.Handle.CanonicalCursor).Select(group => group.First()).ToArray();
                var owners = namedOwners.Where(owner => owner.UnderlyingType.CanonicalType.Handle.Equals(canonical.Handle) &&
                    (written is not TypedefType || owner.Handle.Extent.Start.Equals(alias.Handle.Extent.Start))).ToArray();
                if (owners.Length != 0)
                    return owners.Length == 1 && MatchesOwner(owners[0], canonical);
                while (written is TypedefType typedef)
                {
                    var owner = (TypedefNameDecl)typedef.Decl;
                    if (MatchesOwnerName(owner, name))
                        return MatchesOwner(owner, canonical);
                    written = RemapDiscovery.UnwrapType(owner.UnderlyingType);
                }
                return written is RecordType record && (name == GetRecordPointeeName(record) ||
                    namedOwners.Length == 0 && IsExcludedRecord(record.Decl) &&
                    !(record.Decl.Definition ?? record.Decl).IsCompleteDefinition &&
                    projectionTypeRemaps.TryGetValue(record.Decl.Name, out string providerStorage) &&
                    GetNativeIntegerStorage(providerStorage) is "global::System.IntPtr" or "global::System.UIntPtr") ||
                    written is EnumType nativeEnum && name == EscapeIdentifier(Remap(nativeEnum.Decl.Name));
            }

            bool MatchesOwnerName(TypedefNameDecl owner, string name)
            {
                projectionTypeRemaps.TryGetValue(owner.Name, out string ownerMapping);
                return name == EscapeIdentifier(owner.Name) ||
                    ownerMapping != null && !IsStorageTypeName(ownerMapping) && name == EscapeIdentifier(ownerMapping);
            }

            bool MatchesOwner(TypedefNameDecl owner, ClangSharp.Type canonical)
            {
                if (owner.Handle.Type.SizeOf != canonical.Handle.SizeOf || owner.Handle.Type.AlignOf != canonical.Handle.AlignOf)
                    return false;
                if (projectionTypeRemaps.TryGetValue(owner.Name, out string ownerMapping) && IsStorageTypeName(ownerMapping))
                {
                    if (!resolving.Add(owner.Handle.CanonicalCursor))
                        return false;
                    bool matches = MatchesStorage(owner.UnderlyingType, SyntaxFactory.ParseTypeName(ownerMapping));
                    resolving.Remove(owner.Handle.CanonicalCursor);
                    return matches;
                }
                if (canonical is RecordType or EnumType)
                    return true;
                if (canonical is PointerType pointer && pointer.PointeeType.CanonicalType is RecordType record &&
                    IsExcludedRecord(record.Decl) && projectionTypeRemaps.TryGetValue(record.Decl.Name, out string providerStorage) &&
                    GetNativeIntegerStorage(providerStorage) is "global::System.IntPtr" or "global::System.UIntPtr" &&
                    (canonical.Handle.SizeOf != nativePointerSize || canonical.Handle.AlignOf != nativePointerSize))
                    return false;
                ValidateNativeTypedefType(owner.UnderlyingType, location);
                return canonical is not PointerType || canonical.Handle.AlignOf == canonical.Handle.SizeOf;
            }
        }

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
                    case "NativeTypedef":
                    case "Enum":
                    case "FlagsEnum":
                    case "Flags":
                        continue;
                    case "SupportedOSPlatform":
                        name += "(" + HeaderAnnotation.Quote(HeaderAnnotation.ReadString(annotation.Arguments[0])) + ")";
                        break;
                    case "AlsoUsableFor":
                    case "AssociatedEnum":
                    case "RAIIFree":
                        name += "(" + HeaderAnnotation.Quote(annotation.Arguments[0]) + ")";
                        break;
                    case "AssociatedConstant":
                        name += "(" + HeaderAnnotation.Quote(Remap(annotation.Arguments[0])) + ")";
                        break;
                }
                yield return MakeAttribute(name, returnTarget);
            }
            bool raiiReturn = facts.Declaration is FunctionDecl;
            foreach (long value in facts.InvalidValues)
                yield return MakeAttribute(MetadataNamespace + $"InvalidHandleValue({value.ToString(CultureInfo.InvariantCulture)}L)", raiiReturn);
            if (facts.IsScopedEnum)
                yield return MakeAttribute(MetadataNamespace + "ScopedEnum");
            if (facts.IsFlagsEnum || facts.Annotations.Any(annotation => annotation.Name == "Flags"))
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
            if (includedDeclarations != null &&
                !includedDeclarations.Contains((declaration is ParmVarDecl ? declaration.SemanticParentCursor : declaration).Handle.CanonicalCursor))
                return false;
            if (declaration is RecordDecl record && record.Definition is RecordDecl definition)
            {
                declaration = definition;
                location = GetLocation(definition.Location);
            }
            if (IsExcludedDeclaration(declaration) || location.File.Length == 0)
                return false;
            return traversalNames.Count == 0 || traversalNames.Any(name =>
                string.Equals(Path.GetFullPath(name), Path.GetFullPath(location.File), StringComparison.OrdinalIgnoreCase) ||
                (Path.GetFileName(name) == name && string.Equals(name, Path.GetFileName(location.File), StringComparison.OrdinalIgnoreCase)));
        }

        private bool ShouldProjectTypedef(TypedefNameDecl alias, NativeLocation location)
            => ShouldEmit(alias, location) || requiredTypedefs.Contains(alias.Handle.CanonicalCursor) &&
                location.File.Length != 0 && !IsExcludedDeclaration(alias);

        private bool IsExcludedDeclaration(NamedDecl declaration)
        {
            for (Cursor cursor = declaration; cursor is NamedDecl named; cursor = cursor.SemanticParentCursor)
                if (excludedNames.Contains(named.Name) || excludedNames.Contains(DeclarationSourceMap.QualifiedName(named.Handle)) ||
                    named is FunctionDecl function &&
                    (function.Attrs.Any(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Builtin) ||
                        excludeFunctionsWithBody && function.HasBody))
                    return true;
            return false;
        }

        private string Remap(string name) => remaps.GetValueOrDefault(name) ?? name;

        private static string EscapeIdentifier(string name)
            => SyntaxFacts.GetKeywordKind(name) == SyntaxKind.None ? name : "@" + name;

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

        private bool TryGetOpaqueStructPointer(DeclarationFacts facts, TypedefNameDecl alias, out RecordType record)
        {
            record = null;
            if (!facts.HasNativeTypedefIdentity ||
                !nativeTypedefStorageRemaps.TryGetValue(alias.Handle.CanonicalCursor, out string mapped) ||
                GetNativeIntegerStorage(mapped) != "global::System.IntPtr")
                return false;
            var native = alias.UnderlyingType.CanonicalType;
            if (HasOpaquePointerQualifiers(alias.UnderlyingType) ||
                native is not PointerType pointer || pointer.Handle.SizeOf != nativePointerSize ||
                pointer.Handle.AlignOf != nativePointerSize || alias.Handle.Type.SizeOf != nativePointerSize ||
                alias.Handle.Type.AlignOf != nativePointerSize)
                return false;
            var pointee = pointer.PointeeType.CanonicalType;
            if (pointee is not RecordType candidate ||
                candidate.Decl.Handle.Kind != CXCursorKind.CXCursor_StructDecl || string.IsNullOrEmpty(candidate.Decl.Name) ||
                HasTemplateContext(alias) || HasTemplateContext(candidate.Decl))
                return false;
            record = candidate;
            return true;
        }

        private static bool HasTemplateContext(NamedDecl declaration)
        {
            for (Cursor cursor = declaration; cursor is NamedDecl; cursor = cursor.SemanticParentCursor)
                if (cursor is ClassTemplateSpecializationDecl || cursor.Handle.Kind == CXCursorKind.CXCursor_ClassTemplate)
                    return true;
            return false;
        }

        private static bool HasOpaquePointerQualifiers(ClangSharp.Type type)
        {
            if (type.Handle.IsConstQualified || type.Handle.IsVolatileQualified || type.Handle.IsRestrictQualified ||
                type.Handle.AddressSpace != 0 || type.Handle.Nullability != CXTypeNullabilityKind.CXTypeNullability_Invalid)
                return true;
            return type switch
            {
                TypedefType typedef => HasOpaquePointerQualifiers(typedef.Decl.UnderlyingType),
                ElaboratedType elaborated => HasOpaquePointerQualifiers(elaborated.NamedType),
                ParenType parentheses => HasOpaquePointerQualifiers(parentheses.InnerType),
                AttributedType => true,
                PointerType pointer => HasOpaquePointerQualifiers(pointer.PointeeType),
                _ => false,
            };
        }

        private string GetRecordPointeeName(RecordType record)
        {
            if (projectedRecordNames.TryGetValue(record.Decl.Handle.CanonicalCursor, out string projectedName))
                return projectedName;
            if (string.IsNullOrEmpty(record.Decl.Name))
                throw Error(GetLocation(record.Decl.Location),
                    "A native anonymous record pointee requires one source-bound generated managed record identity.");
            string name = Remap(record.Decl.Name);
            // A whole-alias storage mapping is not a name for its native record pointee.
            return EscapeIdentifier(IsStorageTypeName(name) || visited.OfType<TypedefNameDecl>().Any(alias =>
                alias.UnderlyingType.CanonicalType is PointerType && Remap(alias.Name) == name)
                ? record.Decl.Name : name);
        }

        private string GetSignatureType(ClangSharp.Type type, NativeLocation location, bool underlyingStorage = false,
            bool preserveNativeShape = false, bool recordPointee = false)
        {
            var nativeType = type.CanonicalType;
            type = RemapDiscovery.UnwrapType(type);
            if (underlyingStorage && preserveNativeShape && recordPointee && type.CanonicalType is RecordType nativeRecord)
                return IsExcludedRecord(nativeRecord.Decl) ? "void" : GetRecordPointeeName(nativeRecord);
            if (type is TypedefType typedef)
            {
                var alias = (TypedefNameDecl)typedef.Decl;
                if ((!underlyingStorage || preserveNativeShape) &&
                    declarations.TryGetValue(alias, out var facts) && facts.HasNativeTypedefIdentity)
                    return EscapeIdentifier(Remap(alias.Name));
                var mappings = underlyingStorage ? storageTypeRemaps : remaps;
                if (mappings.TryGetValue(alias.Name, out string mapped) && (!underlyingStorage || mapped != alias.Name))
                {
                    if (!underlyingStorage)
                        return mapped;
                    // Nominal remaps name wrappers, not their underlying storage.
                    string storage = GetNativeIntegerStorage(mapped);
                    if (storage != null)
                    {
                        var native = alias.UnderlyingType.CanonicalType;
                        if (!preserveNativeShape || native is not PointerType)
                        {
                            if (preserveNativeShape)
                                ValidateNativeIntegerStorage(alias, mapped, location);
                            return storage;
                        }
                    }
                }
                return GetSignatureType(alias.UnderlyingType, location, underlyingStorage, preserveNativeShape, recordPointee);
            }
            if (type is PointerType pointer)
            {
                if (nativeType is not PointerType nativePointer)
                    throw Error(location, $"Unsupported native pointer representation '{nativeType.AsString}'.");
                string fixedStorage = GetFixedPointerStorage(nativePointer, location);
                if (fixedStorage != null)
                    return fixedStorage;
                if (underlyingStorage && pointer.PointeeType.CanonicalType is RecordType record &&
                    !(record.Decl.Definition ?? record.Decl).IsCompleteDefinition && IsExcludedRecord(record.Decl))
                    return "void*";
                return GetSignatureType(pointer.PointeeType, location, underlyingStorage, preserveNativeShape,
                    recordPointee: true) + "*";
            }
            return GetManagedType(type, location);
        }

        private bool IsExcludedRecord(RecordDecl record)
        {
            for (Cursor cursor = record; cursor is NamedDecl declaration; cursor = cursor.SemanticParentCursor)
                if (excludedNames.Contains(declaration.Name) ||
                    excludedNames.Contains(DeclarationSourceMap.QualifiedName(declaration.Handle)))
                    return true;
            return false;
        }

        private void ValidateNativeIntegerStorage(TypedefNameDecl alias, string mapped, NativeLocation location)
        {
            var native = alias.UnderlyingType.CanonicalType;
            bool unsigned = IsUnsignedNativeInteger(native.Kind);
            bool opaqueProvider = GetNativeIntegerStorage(mapped) == "global::System.IntPtr" &&
                projectionTypeRemaps.Any(pair => pair.Value == alias.Name && pair.Key.EndsWith("*", StringComparison.Ordinal) &&
                    excludedNames.Contains(pair.Key.Substring(0, pair.Key.Length - 1).TrimEnd()));
            if (!IsEnumStorage(native.Kind) || native.Handle.SizeOf != nativePointerSize ||
                !opaqueProvider && GetNativeIntegerStorage(mapped) != (unsigned ? "global::System.UIntPtr" : "global::System.IntPtr"))
                throw Error(location, $"'NativeTypedef' storage remap '{alias.Name}={mapped}' does not preserve native width, signedness, and pointer depth.");
        }

        private static bool IsUnsignedNativeInteger(CXTypeKind kind)
            => kind is CXTypeKind.CXType_Char_U or CXTypeKind.CXType_UChar or
                CXTypeKind.CXType_UShort or CXTypeKind.CXType_WChar or CXTypeKind.CXType_UInt or
                CXTypeKind.CXType_ULong or CXTypeKind.CXType_ULongLong;

        private static bool IsStorageTypeName(string name)
            => GetNativeIntegerStorage(name) != null ||
                SyntaxFactory.ParseTypeName(name) is PredefinedTypeSyntax or PointerTypeSyntax;

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
            var direction = ParameterAttributes.None;
            foreach (Match block in Regex.Matches(comment, @"/\*\s*(\[[^\[\]]*\]\s*)+\*/"))
                foreach (Match attributeList in Regex.Matches(block.Value, @"\[([^\[\]]*)\]"))
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
            declaration.Extent.Start.GetExpansionLocation(out var file, out _, out _, out uint offset);
            if (file.Equals(default(CXFile)))
                return string.Empty;
            if (!parameterCommentSources.TryGetValue(file, out var source))
                parameterCommentSources[file] = source = declaration.TranslationUnit.Handle.GetFileContents(file, out _).ToArray();
            ReadOnlySpan<byte> contents = source;
            int position = checked((int)offset);
            var comments = new List<string>();
            while (position > 0)
            {
                while (position > 0 && char.IsWhiteSpace((char)contents[position - 1]))
                    position--;
                if (position < 2 || contents[position - 2] != '*' || contents[position - 1] != '/')
                    break;
                int end = position;
                position -= 2;
                while (position >= 2 && !(contents[position - 2] == '/' && contents[position - 1] == '*'))
                    position--;
                if (position < 2)
                    break;
                position -= 2;
                comments.Add(Encoding.UTF8.GetString(contents.Slice(position, end - position)));
            }
            comments.Reverse();
            return string.Join(" ", comments);
        }

        private static NativeLocation GetLocation(CXSourceLocation location)
        {
            location.GetExpansionLocation(out var file, out uint line, out uint column, out uint offset);
            string path = file.ToString();
            return new NativeLocation(path, line, column, offset);
        }

        private static HeaderAnnotationException Error(NativeLocation location, string message)
            => new(location.File, location.Line, location.Column, message);

        private void CollectAnnotationErrors(NamedDecl declaration, Action validate, Func<string> nativeTarget = null,
            NamedDecl factsOwner = null)
        {
            if (declaration != null && invalidDeclarations.Contains(GetNativeIdentity(declaration)) ||
                factsOwner != null && invalidDeclarations.Contains(GetNativeIdentity(factsOwner)))
                return;
            try
            {
                validate();
            }
            catch (HeaderAnnotationException exception)
            {
                if (declaration != null)
                    invalidDeclarations.Add(GetNativeIdentity(declaration));
                if (factsOwner != null)
                    invalidDeclarations.Add(GetNativeIdentity(factsOwner));
                string target = nativeTarget?.Invoke();
                if (string.IsNullOrEmpty(target))
                    target = declaration == null ? "metadata comment" : GetNativeTarget(declaration.Handle);
                annotationErrors.Add((exception, target));
            }
        }

        private void ThrowAnnotationErrors()
        {
            if (annotationErrors.Count != 0)
                throw new HeaderAnnotationDiagnosticsException(annotationErrors
                    .OrderBy(diagnostic => diagnostic.Error.File, StringComparer.OrdinalIgnoreCase)
                    .ThenBy(diagnostic => diagnostic.Error.Line)
                    .ThenBy(diagnostic => diagnostic.Error.Column)
                    .ThenBy(diagnostic => diagnostic.Target, StringComparer.Ordinal)
                    .ThenBy(diagnostic => diagnostic.Error.Message, StringComparer.Ordinal)
                    .Select(diagnostic => $"{diagnostic.Error.Message} [native target: {diagnostic.Target}]"));
        }

        internal static string GetNativeTarget(CXCursor declaration)
        {
            var names = new Stack<string>();
            for (var cursor = declaration; !cursor.IsNull && cursor.Kind != CXCursorKind.CXCursor_TranslationUnit;
                cursor = clang.getCursorSemanticParent(cursor))
            {
                string name = cursor.Spelling.ToString();
                if (name.Length != 0)
                    names.Push(name);
            }
            return names.Count == 0 ? declaration.Kind.ToString() : "::" + string.Join("::", names);
        }

        private static string GetCarrierTarget(Attr target)
        {
            string names = string.Join(", ", target.CursorChildren.SelectMany(GetDeclarationReferences)
                .Select(GetNativeTarget).Distinct(StringComparer.Ordinal).OrderBy(name => name, StringComparer.Ordinal));
            return names.Length == 0 ? target.Spelling : names;
        }

        private sealed record NativeLocation(string File, uint Line, uint Column, uint Offset);
        private sealed record LogicalEnumMember(string Name, string Value, ulong StorageBits, NativeConstantBinding[] Bindings);

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
            internal bool HasMidlRetval { get; set; }
            internal bool IsScopedEnum { get; set; }
            internal bool IsFlagsEnum { get; set; }
            internal bool IsInferredTypedef { get; set; }
            internal bool HasNativeTypedefIdentity => IsInferredTypedef ||
                Annotations.Any(annotation => annotation.Name == "NativeTypedef");
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

            public override SyntaxNode Visit(SyntaxNode node)
            {
                try
                {
                    return base.Visit(node);
                }
                catch (HeaderAnnotationException error) when (node is MemberDeclarationSyntax or ParameterSyntax)
                {
                    owner.annotationErrors.Add((error, "projection " + node.Kind() + ": " +
                        string.Join(", ", node.ChildTokens().Where(token => token.IsKind(SyntaxKind.IdentifierToken))
                            .Select(token => token.ValueText))));
                    return node;
                }
            }

            internal void AddCallbackTemplate(DelegateDeclarationSyntax node)
            {
                var declaration = FindFacts(node.AttributeLists, node)?.Declaration;
                if (declaration is TypedefNameDecl alias &&
                    owner.callbackOrigins.TryGetValue(alias, out var origin) && origin == alias)
                    owner.callbackTemplates[origin] = node;
            }

            internal void AddRecordProjection(StructDeclarationSyntax node)
            {
                if (FindFacts(node.AttributeLists, node)?.Declaration is not RecordDecl record ||
                    !owner.recordPointees.Contains(record.Handle.CanonicalCursor))
                    return;
                var owners = node.AncestorsAndSelf().OfType<StructDeclarationSyntax>().Reverse().ToArray();
                if (owners.Any(type => type.TypeParameterList?.Parameters.Count > 0))
                    throw Error(GetLocation(record.Location), "A native data-pointer typedef cannot use an open generic record projection.");
                string name = string.Join(".", owners.Select(type => type.Identifier.Text));
                string ns = MetadataUtils.SyntaxUtils.GetEnclosingNamespace(node);
                if (!string.IsNullOrEmpty(ns))
                    name = ns + "." + name;
                name = "global::" + name;
                var identity = record.Handle.CanonicalCursor;
                if (owner.projectedRecordNames.TryGetValue(identity, out string previous) && previous != name)
                    throw Error(GetLocation(record.Location), "A native record pointee has multiple generated managed identities.");
                owner.projectedRecordNames[identity] = name;
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
                string file = DeclarationSourceMap.ReadFilePath(fileToken);
                uint line = uint.Parse(args[1].Expression.ToString(), CultureInfo.InvariantCulture);
                uint column = uint.Parse(args[2].Expression.ToString(), CultureInfo.InvariantCulture);
                owner.projectionLocations.TryGetValue((file, line, column), out var candidates);
                var compatible = candidates?.Where(facts => MatchesKind(facts.Declaration, node)).ToArray()
                    ?? Array.Empty<DeclarationFacts>();
                compatible = compatible.GroupBy(facts => facts.AnnotationOwner).Select(group => group.First()).ToArray();
                if (node is StructDeclarationSyntax && compatible.Length != 0)
                {
                    var enclosingRecords = node.Ancestors().OfType<StructDeclarationSyntax>()
                        .Select(parent => FindFacts(parent.AttributeLists, parent)?.Declaration)
                        .OfType<RecordDecl>().Select(record => record.Handle.CanonicalCursor).ToHashSet();
                    // A synthesized nested buffer cannot be its enclosing native record.
                    compatible = compatible.Where(facts => !enclosingRecords.Contains(facts.Declaration.Handle.CanonicalCursor)).ToArray();
                    if (compatible.Length == 0)
                        return null;
                }
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
                bool nativeAliases = facts?.Declaration is EnumDecl declaration && owner.HasNativeConstantAliases(declaration);
                string ns = string.Join(".", node.Ancestors().OfType<BaseNamespaceDeclarationSyntax>()
                    .Reverse().Select(parent => parent.Name.ToString()));
                var bindings = nativeAliases ? node.Members.Select(member =>
                    owner.ReadNativeEnumBinding(FindFacts(member.AttributeLists, member))).ToArray() : null;
                node = (EnumDeclarationSyntax)base.VisitEnumDeclaration(node);
                if (facts != null)
                {
                    owner.projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
                    node = node.AddAttributeLists(owner.GetAttributes(facts).ToArray());
                    if (nativeAliases)
                        node = NativeConstantGroupProvenance.Attach(node, owner.GetNativeEnumSource(facts, node, ns, bindings));
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

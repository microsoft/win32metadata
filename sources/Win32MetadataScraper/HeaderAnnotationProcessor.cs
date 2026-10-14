using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
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
        private readonly Dictionary<NamedDecl, DeclarationFacts> declarations = new();
        private readonly Dictionary<(string File, uint Line, uint Column), List<DeclarationFacts>> projectionLocations = new();
        private readonly Dictionary<string, string> remaps;
        private readonly List<DeclarationFacts> annotatedTypedefs = new();
        private readonly HashSet<NativeLocation> annotationLocations = new();
        private readonly HashSet<NativeLocation> ownedMacroLocations = new();
        private readonly HashSet<NamedDecl> projectedDeclarations = new();
        private readonly string generatedNamespace;
        private readonly TranslationUnit translationUnit;
        private readonly IReadOnlyList<string> traversalNames;
        private readonly ISet<string> excludedNames;
        private readonly Dictionary<NativeLocation, CXSourceRange> macroExpansions = new();
        private readonly Dictionary<TypedefDecl, TypedefDecl> callbackOrigins = new();
        private readonly Dictionary<TypedefDecl, DelegateDeclarationSyntax> callbackTemplates = new();
        private readonly Dictionary<string, CXCursor> macroDefinitions = new(StringComparer.Ordinal);
        private readonly Dictionary<CXCursor, string[]> macroIdentifiers = new();
        private readonly Dictionary<CXCursor, bool> macroOwnership = new();
        private readonly HashSet<Cursor> visited = new();

        internal HeaderAnnotationProcessor(TranslationUnit translationUnit, Dictionary<string, string> remaps, string generatedNamespace,
            IReadOnlyList<string> traversalNames, ISet<string> excludedNames)
        {
            this.translationUnit = translationUnit;
            this.remaps = remaps;
            this.generatedNamespace = generatedNamespace;
            this.traversalNames = traversalNames;
            this.excludedNames = excludedNames;
            foreach (var cursor in translationUnit.TranslationUnitDecl.CursorChildren)
            {
                if (cursor.CursorKind == CXCursorKind.CXCursor_MacroDefinition)
                {
                    macroDefinitions[cursor.Spelling] = cursor.Handle;
                    macroOwnership.Clear();
                }
                if (cursor.CursorKind == CXCursorKind.CXCursor_MacroExpansion)
                {
                    var location = GetLocation(cursor.Location);
                    macroExpansions[location] = cursor.Extent;
                    if (IsOwnedMacro(cursor.Spelling) || ReferencesOwnedMacro(cursor.Handle.Referenced, new HashSet<CXCursor>()))
                        ownedMacroLocations.Add(location);
                }
            }
            Walk(translationUnit.TranslationUnitDecl);
            MergeRedeclarationFacts();
            foreach (var location in ownedMacroLocations)
            {
                if (!annotationLocations.Contains(location))
                {
                    throw Error(location, "Win32 metadata annotation was ignored by Clang or is not attached to a supported declaration.");
                }
            }
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

        private static bool IsOwnedMacro(string name)
            => name == "_WIN32META_ANNOTATION_" || name.StartsWith("_Win32_", StringComparison.Ordinal) ||
                name.StartsWith("_Windows_SupportedOS_", StringComparison.Ordinal);

        internal void PrepareTypedefs()
        {
            foreach (var facts in annotatedTypedefs)
            {
                var alias = (TypedefDecl)facts.Declaration;
                bool primaryRecord = alias.UnderlyingType.CanonicalType is RecordType record && Remap(record.Decl.Name) == Remap(alias.Name);
                if (GetFunctionType(alias.UnderlyingType) == null && !primaryRecord)
                    remaps.TryAdd(alias.Name, alias.Name);
            }
        }

        internal void EvaluateInvalidValues(TranslationUnit translationUnit, string sourceFile, string[] clangArguments)
        {
            var evaluations = declarations.Values.Select(facts => facts.AnnotationOwner).Distinct().SelectMany(facts =>
                facts.Annotations.Where(annotation => annotation.Name == "RAIIFree")
                    .SelectMany(annotation => annotation.Arguments.Skip(1)
                        .Select((argument, index) => new InvalidValue(facts, argument, index)))).ToArray();
            if (evaluations.Length == 0)
                return;

            var insertions = new Dictionary<string, List<(uint Offset, string Text)>>(StringComparer.Ordinal);
            var queryLocations = new Dictionary<NamedDecl, NativeLocation>();
            for (int i = 0; i < evaluations.Length; i++)
            {
                var evaluation = evaluations[i];
                var expanded = evaluation.Facts.Annotations.SingleOrDefault(annotation => annotation.Name == HeaderAnnotation.ExpandedRaiiName);
                if (expanded == null)
                    throw Error(evaluation.Facts.Location, "RAIIFree invalid values require declaration-time expansion transport; include win32metadata_annotations.h.");
                string expression = expanded.Arguments[evaluation.Index + 1];
                var declaration = evaluation.Facts.Declaration;
                if (declaration is ParmVarDecl)
                    declaration = (NamedDecl)declaration.SemanticParentCursor;
                if (!queryLocations.TryGetValue(declaration, out var start))
                    queryLocations[declaration] = start = GetCompleteDeclarationStart(declaration);
                bool classMember = declaration.SemanticParentCursor is RecordDecl;
                string storage = classMember ? "inline static const" : "static const";
                string query = $"\nstatic_assert(__is_integral(decltype({expression})) || __is_enum(decltype({expression})) || __is_pointer(decltype({expression})), \"Invalid handle values must be integral, enum, or pointer constants\");\n" +
                    $"{storage} long long __win32metadata_invalid_{i} = __is_pointer(decltype({expression})) ? (long long)(__INTPTR_TYPE__)({expression}) : (long long)({expression});\n";
                if (!insertions.TryGetValue(start.File, out var items))
                    insertions[start.File] = items = new();
                items.Add((start.Offset, query));
            }

            unsafe
            {
                var unsavedFiles = new List<CXUnsavedFile>();
                try
                {
                    foreach (var insertion in insertions)
                    {
                        var file = translationUnit.Handle.GetFile(insertion.Key);
                        var bytes = translationUnit.Handle.GetFileContents(file, out _);
                        using var contents = new MemoryStream();
                        int offset = 0;
                        foreach (var item in insertion.Value.OrderBy(item => item.Offset))
                        {
                            int position = checked((int)item.Offset);
                            contents.Write(bytes.Slice(offset, position - offset));
                            contents.Write(Encoding.UTF8.GetBytes(item.Text));
                            offset = position;
                        }
                        contents.Write(bytes[offset..]);
                        unsavedFiles.Add(CreateUnsavedFile(insertion.Key, contents.ToArray()));
                    }
                    using var index = CXIndex.Create(false, false);
                    var error = CXTranslationUnit.TryParse(index, sourceFile, clangArguments,
                        unsavedFiles.ToArray(), CXTranslationUnit_Flags.CXTranslationUnit_None, out var handle);
                    if (error != CXErrorCode.CXError_Success)
                        throw Error(evaluations[0].Facts.Location, $"Failed to evaluate invalid values: {error}.");
                    using var queryUnit = TranslationUnit.GetOrCreate(handle);
                    for (uint i = 0; i < handle.NumDiagnostics; i++)
                    {
                        using var diagnostic = handle.GetDiagnostic(i);
                        if (diagnostic.Severity is CXDiagnosticSeverity.CXDiagnostic_Error or CXDiagnosticSeverity.CXDiagnostic_Fatal)
                            throw Error(evaluations[0].Facts.Location, $"Invalid handle expression: {diagnostic.Format(CXDiagnostic.DefaultDisplayOptions)}");
                    }
                    var variables = FindQueryVariables(queryUnit.TranslationUnitDecl).ToDictionary(variable => variable.Name);
                    for (int i = 0; i < evaluations.Length; i++)
                    {
                        if (!variables.TryGetValue($"__win32metadata_invalid_{i}", out var variable))
                            throw Error(evaluations[i].Facts.Location, "Invalid value evaluation declaration was not produced.");
                        using var result = variable.Handle.Evaluate;
                        if (result.Handle == IntPtr.Zero || result.Kind != CXEvalResultKind.CXEval_Int)
                            throw Error(evaluations[i].Facts.Location, $"Invalid value '{evaluations[i].Expression}' is not an integer constant expression.");
                        evaluations[i].Facts.InvalidValues.Add(result.AsLongLong);
                    }
                }
                finally
                {
                    foreach (var unsaved in unsavedFiles)
                        unsaved.Dispose();
                }
            }
        }

        private NativeLocation GetCompleteDeclarationStart(NamedDecl declaration)
        {
            var start = GetLocation(declaration.Extent.Start);
            var attributes = declaration.Attrs.Where(attribute => !attribute.IsImplicit)
                .Select(attribute => GetLocation(attribute.Extent.Start))
                .Where(location => location.File == start.File && location.Offset < start.Offset).ToArray();
            if (attributes.Length == 0)
                return start;

            var file = translationUnit.Handle.GetFile(start.File);
            var range = CXSourceRange.Create(translationUnit.Handle.GetLocationForOffset(file, 0),
                translationUnit.Handle.GetLocationForOffset(file, start.Offset));
            var tokens = translationUnit.Handle.Tokenize(range);
            try
            {
                var prefix = new List<(NativeLocation Location, string Text)>();
                foreach (var token in tokens)
                {
                    if (token.Kind == CXTokenKind.CXToken_Comment)
                        continue;
                    using var text = token.GetSpelling(translationUnit.Handle);
                    prefix.Add((GetLocation(token.GetLocation(translationUnit.Handle)), text.ToString()));
                }
                uint boundary = prefix.Where(token => token.Text is ";" or "{" or "}")
                    .Select(token => token.Location.Offset).DefaultIfEmpty(0u).Max();
                var first = attributes.Where(location => location.Offset > boundary).OrderBy(location => location.Offset).FirstOrDefault();
                if (first == null)
                    return start;

                int squareDepth = 0;
                NativeLocation open = null;
                for (int i = 0; i < prefix.Count; i++)
                {
                    string text = prefix[i].Text;
                    if (squareDepth == 0 && text == "[" && i + 1 < prefix.Count && prefix[i + 1].Text == "[")
                        open = prefix[i].Location;
                    if (open == null)
                        continue;
                    if (text == "[")
                        squareDepth++;
                    else if (text == "]")
                        squareDepth--;
                    if (squareDepth == 0)
                    {
                        if (open.Offset <= first.Offset && first.Offset <= prefix[i].Location.Offset)
                            return open;
                        open = null;
                    }
                }
                return first;
            }
            finally
            {
                translationUnit.Handle.DisposeTokens(tokens);
            }
        }

        private static unsafe CXUnsavedFile CreateUnsavedFile(string filename, ReadOnlySpan<byte> contents)
        {
            var file = CXUnsavedFile.Create(filename, string.Empty);
            try
            {
                file.Contents = (sbyte*)NativeMemory.Alloc(checked((nuint)contents.Length + 1));
                contents.CopyTo(new Span<byte>(file.Contents, contents.Length));
                file.Contents[contents.Length] = 0;
                file.Length = (nuint)contents.Length;
                return file;
            }
            catch
            {
                file.Dispose();
                throw;
            }
        }

        internal void PrepareProjections(IEnumerable<string> sources)
        {
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
                var alias = (TypedefDecl)facts.Declaration;
                string name = Remap(alias.Name);
                if (projectedDeclarations.Contains(facts.AnnotationOwner.Declaration))
                    continue;
                if (!ShouldEmit(alias, facts.Location))
                    continue;
                var functionType = GetFunctionType(alias.UnderlyingType);
                if (functionType != null)
                    throw Error(facts.Location, $"Annotated callback typedef '{alias.Name}' was not projected by ClangSharp.");
                string valueType = GetManagedType(alias.UnderlyingType.CanonicalType, facts.Location);
                var declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                    $"[{MetadataNamespace}NativeTypedef] public unsafe partial struct {name} {{ public {valueType} Value; }}");
                declaration = declaration.AddAttributeLists(GetAttributes(facts).ToArray());
                members.Add(declaration);
                projectedDeclarations.Add(facts.AnnotationOwner.Declaration);
            }
            if (members.Count == 0)
                return string.Empty;
            return SyntaxFactory.CompilationUnit().AddMembers(
                SyntaxFactory.NamespaceDeclaration(SyntaxFactory.ParseName(generatedNamespace)).AddMembers(members.ToArray()))
                .NormalizeWhitespace().ToFullString() + Environment.NewLine;
        }

        internal void ValidateProjection()
        {
            foreach (var facts in declarations.Values)
                if ((facts.Annotations.Count != 0 || facts.IsScopedEnum || facts.IsFlagsEnum) &&
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
                var facts = new DeclarationFacts(declaration, location);
                var occurrences = new HashSet<CXCursor>();
                foreach (var attribute in declaration.Attrs.Where(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Annotate))
                {
                    var attributeLocation = GetLocation(attribute.Location);
                    string payload = attribute.Spelling;
                    bool owned = ownedMacroLocations.Contains(attributeLocation);
                    if (!HeaderAnnotation.IsKnownPayload(payload) && !owned)
                        continue;
                    annotationLocations.Add(attributeLocation);
                    if (!occurrences.Add(attribute.Handle))
                        continue;
                    HeaderAnnotation annotation;
                    try
                    {
                        annotation = HeaderAnnotation.Parse(payload);
                    }
                    catch (FormatException exception)
                    {
                        throw Error(attributeLocation, exception.Message);
                    }
                    if (attributeLocation.File == location.File && attributeLocation.Offset > location.Offset)
                        throw Error(attributeLocation, "Win32 metadata annotations must use prefix placement, not a post-declarator attribute.");
                    ValidatePlacement(declaration, attributeLocation);
                    ValidateTarget(facts, annotation, attributeLocation);
                    if (annotation.Name != "AssociatedConstant" && facts.Annotations.Any(existing => existing.Name == annotation.Name))
                        throw Error(attributeLocation, $"Duplicate '{annotation.Name}' annotation.");
                    facts.Annotations.Add(annotation);
                }
                if (declaration is ParmVarDecl && HasRetvalComment(declaration))
                {
                    var retval = new HeaderAnnotation("RetVal", Array.Empty<string>());
                    ValidateTarget(facts, retval, location);
                    if (!facts.Annotations.Any(annotation => annotation.Name == retval.Name))
                        facts.Annotations.Add(retval);
                }
                if (declaration is EnumDecl enumDeclaration)
                {
                    facts.IsScopedEnum = enumDeclaration.IsScoped;
                    facts.IsFlagsEnum = declaration.Attrs.Any(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_FlagEnum);
                }
                if (declaration is FunctionDecl or ParmVarDecl or FieldDecl or RecordDecl or EnumDecl or TypedefDecl)
                {
                    var raii = facts.Annotations.SingleOrDefault(annotation => annotation.Name == "RAIIFree");
                    var expanded = facts.Annotations.SingleOrDefault(annotation => annotation.Name == HeaderAnnotation.ExpandedRaiiName);
                    if (expanded != null && (raii == null || raii.Arguments.Count != expanded.Arguments.Count))
                        throw Error(location, "Expanded RAIIFree transport does not match the authored annotation.");
                    declarations[declaration] = facts;
                    if (declaration is TypedefDecl alias)
                    {
                        if (facts.Annotations.Count != 0)
                            annotatedTypedefs.Add(facts);
                        if (GetCallbackOrigin(alias) is TypedefDecl origin)
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

        private void MergeRedeclarationFacts()
        {
            foreach (var group in declarations.Values.GroupBy(facts => GetNativeIdentity(facts.Declaration)))
            {
                var owner = group.FirstOrDefault(facts => facts.Annotations.Count != 0) ?? group.First();
                foreach (var facts in group.Where(facts => facts != owner))
                {
                    foreach (var annotation in facts.Annotations)
                    {
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
                }
                foreach (var facts in group)
                {
                    facts.AnnotationOwner = owner;
                    facts.Annotations = owner.Annotations;
                    facts.InvalidValues = owner.InvalidValues;
                    facts.IsScopedEnum = owner.IsScopedEnum;
                    facts.IsFlagsEnum = owner.IsFlagsEnum;
                }
            }
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
            bool typedef = declaration is TypedefDecl;
            bool field = declaration is FieldDecl;
            bool valid = annotation.Name switch
            {
                "SetLastError" or "ImportLibrary" => function && declaration is not CXXMethodDecl,
                "PreserveResult" => function,
                "SupportedOSPlatform" => function || record || typedef || declaration is EnumDecl,
                "AssociatedEnum" => function || parameter || field,
                "AssociatedConstant" => declaration is EnumDecl,
                "AlsoUsableFor" => typedef,
                "RAIIFree" or HeaderAnnotation.ExpandedRaiiName => function || parameter,
                "Retained" or "ContainsInteriorPointers" or "RetVal" => parameter,
                _ => false,
            };
            if (!valid)
                throw Error(location, $"'{annotation.Name}' is not valid on {declaration.Handle.DeclKind} '{declaration.Name}'.");
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

        private void TransferRecordTypedefFacts()
        {
            foreach (var facts in annotatedTypedefs)
            {
                var alias = (TypedefDecl)facts.Declaration;
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
                    case "SetLastError":
                    case "ImportLibrary":
                    case HeaderAnnotation.ExpandedRaiiName:
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

        private static IEnumerable<VarDecl> FindQueryVariables(Cursor cursor)
        {
            if (cursor is VarDecl variable && variable.Name.StartsWith("__win32metadata_invalid_", StringComparison.Ordinal))
                yield return variable;
            foreach (var child in cursor.CursorChildren)
            {
                if (child.Handle.IsDeclaration || child.Handle.IsTranslationUnit)
                    foreach (var nested in FindQueryVariables(child))
                        yield return nested;
            }
        }

        private bool ShouldEmit(NamedDecl declaration, NativeLocation location)
        {
            for (Cursor cursor = declaration; cursor is NamedDecl named; cursor = cursor.SemanticParentCursor)
                if (excludedNames.Contains(named.Name))
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
            type = type.CanonicalType;
            if (type is PointerType pointer)
                type = pointer.PointeeType.CanonicalType;
            return type as FunctionProtoType;
        }

        private static TypedefDecl GetCallbackOrigin(TypedefDecl alias)
        {
            var type = RemapDiscovery.UnwrapType(alias.UnderlyingType);
            if (type is TypedefType typedef)
                return GetCallbackOrigin((TypedefDecl)typedef.Decl);
            if (type is PointerType pointer)
            {
                type = RemapDiscovery.UnwrapType(pointer.PointeeType);
                if (type is TypedefType typedefPointer)
                    return GetCallbackOrigin((TypedefDecl)typedefPointer.Decl);
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

        private bool ReferencesOwnedMacro(CXCursor definition, HashSet<CXCursor> visiting)
        {
            if (definition.IsNull)
                return false;
            if (macroOwnership.TryGetValue(definition, out bool owned))
                return owned;
            if (!visiting.Add(definition))
                return false;
            try
            {
                if (!macroIdentifiers.TryGetValue(definition, out var identifiers))
                {
                    var tokens = translationUnit.Handle.Tokenize(definition.Extent);
                    try
                    {
                        var names = new List<string>();
                        foreach (var token in tokens)
                            if (token.Kind == CXTokenKind.CXToken_Identifier)
                            {
                                using var spelling = token.GetSpelling(translationUnit.Handle);
                                names.Add(spelling.ToString());
                            }
                        identifiers = names.Skip(1).ToArray();
                        macroIdentifiers[definition] = identifiers;
                    }
                    finally
                    {
                        translationUnit.Handle.DisposeTokens(tokens);
                    }
                }
                owned = identifiers.Any(name => IsOwnedMacro(name) ||
                    (macroDefinitions.TryGetValue(name, out var nested) && ReferencesOwnedMacro(nested, visiting)));
                if (owned || visiting.Count == 1)
                    macroOwnership[definition] = owned;
                return owned;
            }
            finally
            {
                visiting.Remove(definition);
            }
        }

        private void ValidatePlacement(NamedDecl declaration, NativeLocation annotation)
        {
            if (declaration is RecordDecl or EnumDecl)
                return;
            var start = GetLocation(declaration.Extent.Start);
            if (start.File != annotation.File || annotation.Offset <= start.Offset)
                return;
            var attributeLocations = declaration.Attrs.Select(attribute => GetLocation(attribute.Location)).ToHashSet();
            var prefixMacros = macroExpansions.Where(item => attributeLocations.Contains(item.Key))
                .Select(item => (Start: item.Key, End: GetLocation(item.Value.End))).ToArray();
            var range = CXSourceRange.Create(declaration.Extent.Start, declaration.Location);
            var tokens = translationUnit.Handle.Tokenize(range);
            try
            {
                int attributeDepth = 0;
                int squareDepth = 0;
                bool rawAttribute = false;
                foreach (var token in tokens)
                {
                    var location = GetLocation(token.GetLocation(translationUnit.Handle));
                    if (token.Kind == CXTokenKind.CXToken_Comment || prefixMacros.Any(macro =>
                        macro.Start.File == location.File && location.Offset >= macro.Start.Offset && location.Offset < macro.End.Offset))
                        continue;
                    using var text = token.GetSpelling(translationUnit.Handle);
                    string spelling = text.ToString();
                    if (squareDepth != 0)
                    {
                        if (spelling == "[")
                            squareDepth++;
                        else if (spelling == "]")
                            squareDepth--;
                        continue;
                    }
                    if (!rawAttribute && spelling == "[")
                    {
                        squareDepth = 1;
                        continue;
                    }
                    if (spelling is "__declspec" or "__attribute__")
                    {
                        rawAttribute = true;
                        continue;
                    }
                    if (rawAttribute)
                    {
                        if (spelling == "(")
                            attributeDepth++;
                        else if (spelling == ")" && --attributeDepth == 0)
                            rawAttribute = false;
                        continue;
                    }
                    if (annotation.Offset > location.Offset)
                        throw Error(annotation, "Win32 metadata annotations must precede the complete declaration type or typedef, not occur inside its declarator.");
                    break;
                }
            }
            finally
            {
                translationUnit.Handle.DisposeTokens(tokens);
            }
        }

        private bool HasRetvalComment(NamedDecl declaration)
        {
            var start = GetLocation(declaration.Extent.Start);
            if (start.File.Length == 0)
                return false;
            var file = translationUnit.Handle.GetFile(start.File);
            var contents = translationUnit.Handle.GetFileContents(file, out _);
            int position = checked((int)start.Offset);
            while (position > 0 && char.IsWhiteSpace((char)contents[position - 1]))
                position--;
            if (position < 2 || contents[position - 2] != '*' || contents[position - 1] != '/')
                return false;
            int end = position;
            position -= 2;
            while (position >= 2 && !(contents[position - 2] == '/' && contents[position - 1] == '*'))
                position--;
            if (position < 2)
                return false;
            string comment = Encoding.UTF8.GetString(contents.Slice(position - 2, end - position + 2));
            return comment.Contains("[retval]", StringComparison.OrdinalIgnoreCase);
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
        private sealed record InvalidValue(DeclarationFacts Facts, string Expression, int Index);

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
                if (declaration is TypedefDecl alias &&
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
                if (compatible.Length > 1)
                {
                    string name = node switch
                    {
                        MethodDeclarationSyntax method => method.Identifier.ValueText,
                        ParameterSyntax parameter => parameter.Identifier.ValueText,
                        FieldDeclarationSyntax field => field.Declaration.Variables.Single().Identifier.ValueText,
                        BaseTypeDeclarationSyntax type => type.Identifier.ValueText,
                        DelegateDeclarationSyntax callback => callback.Identifier.ValueText,
                        _ => string.Empty,
                    };
                    compatible = compatible.Where(facts => owner.Remap(facts.Declaration.Name) == name).ToArray();
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
                FieldDeclarationSyntax => declaration is FieldDecl,
                StructDeclarationSyntax => declaration is RecordDecl,
                EnumDeclarationSyntax => declaration is EnumDecl,
                DelegateDeclarationSyntax => declaration is TypedefDecl or FunctionDecl,
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
                        arguments = arguments.Replace(arguments[0], SyntaxFactory.AttributeArgument(
                            SyntaxFactory.LiteralExpression(SyntaxKind.StringLiteralExpression, SyntaxFactory.Literal(HeaderAnnotation.ReadString(module.Arguments[0])))));
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
                node = (EnumDeclarationSyntax)base.VisitEnumDeclaration(node);
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
                if (facts?.Declaration is TypedefDecl alias && owner.callbackOrigins.TryGetValue(alias, out var origin) && alias != origin)
                {
                    if (!owner.callbackTemplates.TryGetValue(origin, out var template))
                        throw Error(facts.Location, $"Canonical signature for callback alias '{alias.Name}' was not generated.");
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

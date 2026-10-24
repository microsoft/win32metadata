using System;
using System.Collections.Generic;
using ClangSharp.Interop;

namespace Win32MetadataScraperTests
{
    internal sealed record NativeMetadataSelfTypedefProof(
        string Alias, string Scope, string CanonicalDeclaration, string CanonicalType,
        int PointerDepth, string OriginalSource, string MetadataSource)
    {
        public string NativeFact { get; init; }
        public string AnnotationOwner { get; init; }
    }

    internal static class NativeMetadataSelfTypedef
    {
        internal static unsafe bool TryProve(CXCursor declaration, out NativeMetadataSelfTypedefProof proof)
        {
            proof = null;
            if (declaration.Kind != CXCursorKind.CXCursor_TypedefDecl)
                return false;
            var referencedType = declaration.TypedefDeclUnderlyingType;
            while (referencedType.kind == CXTypeKind.CXType_Elaborated)
                referencedType = referencedType.NamedType;
            if (referencedType.kind != CXTypeKind.CXType_Typedef)
                return false;

            var annotations = new List<CXCursor>();
            var references = new List<CXCursor>();
            declaration.VisitChildren((child, _, _) =>
            {
                if (child.Kind == CXCursorKind.CXCursor_AnnotateAttr &&
                    Text(child.Spelling) == "Win32Metadata.NativeTypedef")
                    annotations.Add(child);
                else if (child.Kind == CXCursorKind.CXCursor_TypeRef)
                    references.Add(child.Referenced);
                return CXChildVisitResult.CXChildVisit_Continue;
            }, default);
            if (annotations.Count != 1 || references.Count != 1)
                return false;

            var original = references[0];
            string name = Text(declaration.Spelling);
            if (original.Kind != CXCursorKind.CXCursor_TypedefDecl || original == declaration ||
                Text(original.Spelling) != name ||
                original.SemanticParent.CanonicalCursor != declaration.SemanticParent.CanonicalCursor ||
                original.CanonicalCursor != declaration.CanonicalCursor ||
                original.TypedefDeclUnderlyingType.CanonicalType != declaration.TypedefDeclUnderlyingType.CanonicalType)
                return false;

            original.Location.GetExpansionLocation(out var originalFile, out var originalLine, out var originalColumn, out var originalOffset);
            declaration.Location.GetExpansionLocation(out var metadataFile, out var metadataLine, out var metadataColumn, out var metadataOffset);
            annotations[0].Location.GetExpansionLocation(out var annotationFile, out _, out _, out _);
            string provider = originalFile.ToString();
            if (string.IsNullOrEmpty(provider) ||
                !string.Equals(provider, metadataFile.ToString(), StringComparison.OrdinalIgnoreCase) ||
                !string.Equals(provider, annotationFile.ToString(), StringComparison.OrdinalIgnoreCase) ||
                originalOffset >= metadataOffset)
                return false;

            var canonical = declaration.TypedefDeclUnderlyingType.CanonicalType;
            int depth = 0;
            for (var type = canonical; type.kind == CXTypeKind.CXType_Pointer; type = type.PointeeType.CanonicalType)
                depth++;
            proof = new NativeMetadataSelfTypedefProof(name, Scope(declaration.SemanticParent),
                Text(original.CanonicalCursor.Usr), Text(canonical.Spelling), depth,
                provider + ":" + originalLine + ":" + originalColumn,
                metadataFile + ":" + metadataLine + ":" + metadataColumn);
            return !string.IsNullOrEmpty(proof.CanonicalDeclaration);
        }

        private static string Scope(CXCursor parent)
        {
            var names = new Stack<string>();
            while (parent.Kind != CXCursorKind.CXCursor_TranslationUnit)
            {
                names.Push(Text(parent.Spelling));
                parent = parent.SemanticParent;
            }
            return "::" + string.Join("::", names);
        }

        private static string Text(CXString value)
        {
            using (value) return value.ToString();
        }
    }
}

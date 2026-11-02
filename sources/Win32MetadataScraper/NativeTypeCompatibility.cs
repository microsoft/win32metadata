using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;

namespace Win32MetadataScraper
{
    internal sealed class NativeTypeCompatibility
    {
        private readonly ILookup<NativeSourceIdentity, NamedDecl> primary;
        private readonly HashSet<(CXType Primary, CXType Companion)> compared = new();
        private readonly List<string> witnesses = new();

        internal NativeTypeCompatibility(IEnumerable<Decl> declarations)
            => primary = declarations.OfType<NamedDecl>()
                .Select(declaration => declaration is RecordDecl record ? record.Definition ?? record : declaration)
                .DistinctBy(declaration => declaration.Handle.CanonicalCursor)
                .ToLookup(NativeSourceIdentity.Of);

        internal IReadOnlyList<string> Witnesses => witnesses;

        internal void Validate(FunctionDecl function)
        {
            RequireProvider(function.ReturnType, function.Name + ".return");
            for (int index = 0; index < function.Parameters.Count; index++)
                RequireProvider(function.Parameters[index].Type, function.Name + $".parameter[{index}]");
        }

        private void RequireProvider(ClangSharp.Type type, string path, bool indirect = false)
        {
            type = ResolveType(type);
            if (!indirect && type.CanonicalType is RecordType valueRecord &&
                !(valueRecord.Decl.Definition ?? valueRecord.Decl).IsCompleteDefinition)
                throw Incompatible(path, $"incomplete by-value native dependency '{type.AsString}'");
            if (type is TypedefType alias)
            {
                var provider = Provider<TypedefNameDecl>(alias.Decl, path);
                Compare(provider.UnderlyingType, alias.Decl.UnderlyingType, path + $".typedef({alias.Decl.Name})");
            }
            else if (type is PointerType pointer)
                RequireProvider(pointer.PointeeType, path + ".pointee", indirect: true);
            else if (type is TagType tag)
            {
                var declaration = tag.Decl is RecordDecl record ? record.Definition ?? record : tag.Decl;
                var provider = Provider<TagDecl>(declaration, path);
                Compare(provider.TypeForDecl, declaration.TypeForDecl, path);
            }
            else if (type is FunctionProtoType signature)
            {
                RequireProvider(signature.ReturnType, path + ".return");
                for (int index = 0; index < signature.ParamTypes.Count; index++)
                    RequireProvider(signature.ParamTypes[index], path + $".parameter[{index}]");
            }
            else if (type is ArrayType array)
                RequireProvider(array.ElementType, path + ".element");
            else if (type is not BuiltinType)
                throw Incompatible(path, $"unsupported native dependency '{type.AsString}'");
        }

        private T Provider<T>(NamedDecl declaration, string path) where T : NamedDecl
        {
            var candidates = primary[NativeSourceIdentity.Of(declaration)].OfType<T>().ToArray();
            if (candidates.Length != 1 ||
                DeclarationSourceMap.QualifiedName(candidates[0].Handle) != DeclarationSourceMap.QualifiedName(declaration.Handle))
                throw Incompatible(path, $"no unique primary provider for '{declaration.Name}' at {NativeSourceIdentity.Of(declaration)}");
            witnesses.Add(path + ": " + NativeSourceIdentity.Of(declaration));
            CompareAnnotations(candidates[0], declaration, path);
            return candidates[0];
        }

        private void Compare(ClangSharp.Type expected, ClangSharp.Type actual, string path)
        {
            if (expected.CanonicalType.Handle.IsConstQualified != actual.CanonicalType.Handle.IsConstQualified ||
                expected.CanonicalType.Handle.IsVolatileQualified != actual.CanonicalType.Handle.IsVolatileQualified ||
                expected.CanonicalType.Handle.IsRestrictQualified != actual.CanonicalType.Handle.IsRestrictQualified ||
                expected.Handle.AddressSpace != actual.Handle.AddressSpace ||
                expected.Handle.Nullability != actual.Handle.Nullability ||
                !TypeAttributes(expected, path).SequenceEqual(TypeAttributes(actual, path)))
                throw Difference(expected, actual, path);
            expected = ResolveType(expected);
            actual = ResolveType(actual);
            if (!compared.Add((expected.Handle, actual.Handle)))
                return;
            witnesses.Add($"{path}: primary '{expected.AsString}' ({expected.Kind}); ANSI '{actual.AsString}' ({actual.Kind})");
            if (expected.Handle.IsConstQualified != actual.Handle.IsConstQualified ||
                expected.Handle.IsVolatileQualified != actual.Handle.IsVolatileQualified ||
                expected.Handle.IsRestrictQualified != actual.Handle.IsRestrictQualified ||
                expected.Kind != actual.Kind)
                throw Difference(expected, actual, path);
            if (expected is TypedefType expectedAlias && actual is TypedefType actualAlias)
            {
                SameDeclaration(expectedAlias.Decl, actualAlias.Decl, path);
                Compare(expectedAlias.Decl.UnderlyingType, actualAlias.Decl.UnderlyingType,
                    path + $".typedef({actualAlias.Decl.Name})");
            }
            else if (expected is PointerType expectedPointer && actual is PointerType actualPointer)
            {
                if (expected.Handle.SizeOf != actual.Handle.SizeOf || expected.Handle.AlignOf != actual.Handle.AlignOf)
                    throw Difference(expected, actual, path);
                Compare(expectedPointer.PointeeType, actualPointer.PointeeType, path + ".pointee");
            }
            else if (expected is RecordType expectedRecord && actual is RecordType actualRecord)
                CompareRecords(expectedRecord.Decl.Definition ?? expectedRecord.Decl,
                    actualRecord.Decl.Definition ?? actualRecord.Decl, path);
            else if (expected is EnumType expectedEnum && actual is EnumType actualEnum)
            {
                SameDeclaration(expectedEnum.Decl, actualEnum.Decl, path);
                Compare(expectedEnum.Decl.IntegerType, actualEnum.Decl.IntegerType, path + ".enum-storage");
                var expectedValues = expectedEnum.Decl.CursorChildren.OfType<EnumConstantDecl>().ToArray();
                var actualValues = actualEnum.Decl.CursorChildren.OfType<EnumConstantDecl>().ToArray();
                if (expectedValues.Length != actualValues.Length)
                    throw Incompatible(path, $"native enum value count differs for '{actualEnum.Decl.Name}'");
                for (int index = 0; index < expectedValues.Length; index++)
                {
                    SameDeclaration(expectedValues[index], actualValues[index], path + $".enum-value[{index}]");
                    if (expectedValues[index].Handle.EnumConstantDeclUnsignedValue !=
                        actualValues[index].Handle.EnumConstantDeclUnsignedValue)
                        throw Incompatible(path, $"native enum value differs for '{actualValues[index].Name}'");
                }
            }
            else if (expected is FunctionProtoType expectedFunction && actual is FunctionProtoType actualFunction)
            {
                if (expectedFunction.CallConv != actualFunction.CallConv ||
                    expectedFunction.Handle.IsFunctionTypeVariadic != actualFunction.Handle.IsFunctionTypeVariadic ||
                    expectedFunction.Handle.CXXRefQualifier != actualFunction.Handle.CXXRefQualifier ||
                    expectedFunction.ParamTypes.Count != actualFunction.ParamTypes.Count)
                    throw Difference(expected, actual, path);
                Compare(expectedFunction.ReturnType, actualFunction.ReturnType, path + ".return");
                for (int index = 0; index < expectedFunction.ParamTypes.Count; index++)
                    Compare(expectedFunction.ParamTypes[index], actualFunction.ParamTypes[index], path + $".parameter[{index}]");
            }
            else if (expected is ArrayType expectedArray && actual is ArrayType actualArray)
            {
                if (expected.Handle.ArraySize != actual.Handle.ArraySize)
                    throw Difference(expected, actual, path);
                Compare(expectedArray.ElementType, actualArray.ElementType, path + ".element");
            }
            else if (expected is BuiltinType && actual is BuiltinType)
            {
                if (expected.Kind != actual.Kind || expected.Handle.SizeOf != actual.Handle.SizeOf ||
                    expected.Handle.AlignOf != actual.Handle.AlignOf)
                    throw Difference(expected, actual, path);
            }
            else
                throw Incompatible(path, $"unsupported native type comparison '{expected.AsString}' / '{actual.AsString}'");
        }

        private static ClangSharp.Type ResolveType(ClangSharp.Type type)
        {
            while (true)
                switch (type)
                {
                    case ElaboratedType elaborated:
                        type = elaborated.NamedType;
                        break;
                    case AttributedType attributed:
                        type = attributed.EquivalentType;
                        break;
                    case ParenType parenthesized:
                        type = parenthesized.InnerType;
                        break;
                    default:
                        return type;
                }
        }

        private static IEnumerable<CX_AttrKind> TypeAttributes(ClangSharp.Type type, string path)
        {
            while (true)
                switch (type)
                {
                    case ElaboratedType elaborated:
                        type = elaborated.NamedType;
                        break;
                    case AttributedType attributed:
                        if (attributed.AttrKind is CX_AttrKind.CX_AttrKind_AnnotateType or CX_AttrKind.CX_AttrKind_BTFTypeTag)
                            throw Incompatible(path, $"native type attribute '{attributed.AttrKind}' has no comparable compiled arguments");
                        yield return attributed.AttrKind;
                        type = attributed.EquivalentType;
                        break;
                    case ParenType parenthesized:
                        type = parenthesized.InnerType;
                        break;
                    default:
                        yield break;
                }
        }

        private void CompareRecords(RecordDecl expected, RecordDecl actual, string path)
        {
            SameDeclaration(expected, actual, path);
            if (expected.IsCompleteDefinition != actual.IsCompleteDefinition)
                throw Incompatible(path, $"native completeness differs for '{actual.Name}'");
            if (!actual.IsCompleteDefinition)
                return;
            if (expected.TypeForDecl.Handle.SizeOf != actual.TypeForDecl.Handle.SizeOf ||
                expected.TypeForDecl.Handle.AlignOf != actual.TypeForDecl.Handle.AlignOf)
                throw Incompatible(path, $"native record layout differs for '{actual.Name}'");
            var expectedFields = expected.CursorChildren.OfType<FieldDecl>().ToArray();
            var actualFields = actual.CursorChildren.OfType<FieldDecl>().ToArray();
            if (expectedFields.Length != actualFields.Length)
                throw Incompatible(path, $"native field count differs for '{actual.Name}'");
            for (int index = 0; index < expectedFields.Length; index++)
            {
                var first = expectedFields[index];
                var second = actualFields[index];
                SameDeclaration(first, second, path + $".field[{index}]");
                if (first.IsBitField != second.IsBitField || first.Handle.OffsetOfField != second.Handle.OffsetOfField ||
                    first.IsBitField && first.Handle.FieldDeclBitWidth != second.Handle.FieldDeclBitWidth)
                    throw Incompatible(path, $"native field layout differs for '{second.Name}'");
                Compare(first.Type, second.Type, path + $".field({second.Name})");
            }
            var expectedBases = (expected as CXXRecordDecl)?.Bases.ToArray() ?? Array.Empty<CXXBaseSpecifier>();
            var actualBases = (actual as CXXRecordDecl)?.Bases.ToArray() ?? Array.Empty<CXXBaseSpecifier>();
            var expectedMethods = expected.CursorChildren.OfType<CXXMethodDecl>().ToArray();
            var actualMethods = actual.CursorChildren.OfType<CXXMethodDecl>().ToArray();
            if (expectedMethods.Length != 0 || actualMethods.Length != 0 ||
                expectedBases.Length != 0 || actualBases.Length != 0)
                throw Incompatible(path, $"native C++ method/base dependencies for '{actual.Name}' require an independently proved primary contract");
        }

        private static void SameDeclaration(NamedDecl expected, NamedDecl actual, string path)
        {
            if (NativeSourceIdentity.Of(expected) != NativeSourceIdentity.Of(actual) ||
                (NativeMacroNames.GetWrittenName(expected) ?? expected.Name) !=
                (NativeMacroNames.GetWrittenName(actual) ?? actual.Name))
                throw Incompatible(path, $"native declaration identity differs: {NativeSourceIdentity.Of(expected)} / {NativeSourceIdentity.Of(actual)}");
            CompareAnnotations(expected, actual, path);
        }

        private static void CompareAnnotations(NamedDecl expected, NamedDecl actual, string path)
        {
            IEnumerable<string> Facts(NamedDecl declaration) => declaration.Attrs
                .Where(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Annotate)
                .Select(attribute => attribute.Spelling + "(" +
                    string.Join(",", attribute.CursorChildren.Select(argument => AnnotationArgument(argument, path))) + ")")
                .OrderBy(value => value, StringComparer.Ordinal);
            if (!Facts(expected).SequenceEqual(Facts(actual), StringComparer.Ordinal))
                throw Incompatible(path, $"native annotation contract differs for '{actual.Name}'");
        }

        private static string AnnotationArgument(Cursor argument, string path)
        {
            if (argument is not Expr expression)
                throw Incompatible(path, "native annotation argument is not a comparable expression");
            while (expression is ParenExpr or ImplicitCastExpr or ConstantExpr)
                expression = expression.CursorChildren.OfType<Expr>().Single();
            if (expression is StringLiteral literal)
                return literal.Kind + ":" + literal.String;
            using var value = expression.Handle.Evaluate;
            if (value.Handle == IntPtr.Zero || value.Kind != CXEvalResultKind.CXEval_Int)
                throw Incompatible(path, "native annotation argument has no comparable compiled value");
            var references = new List<string>();
            var pending = new Stack<Cursor>();
            pending.Push(expression);
            while (pending.TryPop(out var cursor))
            {
                if (cursor is DeclRefExpr || cursor.Handle.IsReference)
                {
                    var declaration = cursor.Handle.Referenced;
                    references.Add(DeclarationSourceMap.QualifiedName(declaration) + "@" + NativeSourceIdentity.Of(declaration));
                }
                foreach (var child in cursor.CursorChildren)
                    pending.Push(child);
            }
            return expression.Type.CanonicalType.Kind + ":" + value.IsUnsignedInt + ":" +
                (value.IsUnsignedInt ? value.AsUnsigned : unchecked((ulong)value.AsLongLong)) + ":" +
                string.Join("|", references.OrderBy(reference => reference, StringComparer.Ordinal));
        }

        private static InvalidOperationException Difference(ClangSharp.Type expected, ClangSharp.Type actual, string path)
            => Incompatible(path, $"primary '{expected.AsString}' differs from ANSI '{actual.AsString}'");

        private static InvalidOperationException Incompatible(string path, string reason)
            => new($"ANSI companion provider is incompatible at {path}: {reason}. Primary Unicode declarations remain authoritative.");
    }

    internal sealed record NativeSourceIdentity(string File, uint Offset, CXCursorKind Kind)
    {
        internal static NativeSourceIdentity Of(Cursor declaration)
            => Of(declaration.Handle);

        internal static NativeSourceIdentity Of(CXCursor declaration)
        {
            declaration.Location.GetExpansionLocation(out var file, out _, out _, out uint offset);
            string path = file.ToString();
            string fullPath = path.Length == 0 ? path : Path.GetFullPath(path);
            return new NativeSourceIdentity(OperatingSystem.IsWindows() ? fullPath.ToUpperInvariant() : fullPath,
                offset, declaration.Kind);
        }

        public override string ToString() => $"{File}:{Offset} ({Kind})";
    }
}

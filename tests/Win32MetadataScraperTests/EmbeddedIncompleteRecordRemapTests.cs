using System;
using System.Collections.Generic;
using System.Linq;
using ClangSharp;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class EmbeddedIncompleteRecordRemapTests
    {
        [Theory]
        [InlineData("struct Holder { struct Hidden* Value; };")]
        [InlineData("struct Hidden; struct Holder { Hidden* Value; };")]
        [InlineData("struct Holder { struct Hidden* Value; }; struct Hidden { int Value; };")]
        [InlineData("struct Holder { struct Hidden* Values[3]; };")]
        [InlineData("struct Holder { struct Hidden* Values[]; };")]
        [InlineData("struct Holder { void (__stdcall *Call)(struct Hidden*, struct Other**); };")]
        [InlineData("struct Holder { struct Hidden*& Value; };")]
        [InlineData("struct Holder { struct Hidden*&& Value; };")]
        [InlineData("struct Holder { struct Hidden* Value; }; using Alias = Hidden*; typedef Alias Second; Second Read(Second*);")]
        [InlineData("template<unsigned N> struct Holder { struct Hidden* Values[N]; };")]
        [InlineData("struct Holder { struct Hidden* Value; }; const Hidden* Read(Hidden*);")]
        [InlineData("namespace Test { struct Holder { struct Hidden* Value; }; }")]
        [InlineData("template<class T> struct Holder { struct Hidden* Value; }; template<> struct Holder<int> { struct Other* Value; };")]
        [InlineData("template<class T> struct Holder {}; template<class T> struct Holder<T*> { struct Hidden* Value; };")]
        public void NativeHandleTraversalPreservesTheOriginalTypeGraphContract(string source)
        {
            using var native = new OpaqueRecordProjectionTests.NativeRecords(source);
            var expected = OriginalRemaps(native.Unit.TranslationUnitDecl);
            var actual = RemapDiscovery.FindEmbeddedIncompleteRecordPointerRemaps(native.Unit.TranslationUnitDecl);
            Assert.Equal(expected.OrderBy(pair => pair.Key), actual.OrderBy(pair => pair.Key));
        }

        [Fact]
        public void EmbeddedIncompletePointeesStillRequireOpaqueStorage()
        {
            using var native = new OpaqueRecordProjectionTests.NativeRecords(
                "struct Holder { struct Hidden* Value; };");
            Assert.Equal("void",
                RemapDiscovery.FindEmbeddedIncompleteRecordPointerRemaps(native.Unit.TranslationUnitDecl)["Hidden"]);
        }

        [Theory]
        [InlineData("struct Holder { struct Hidden* Value; }; Hidden Read(void);")]
        [InlineData("struct Holder { struct Hidden* Value; }; void Use(Hidden);")]
        [InlineData("struct Holder { struct Hidden* Value; }; void Use(Hidden&);")]
        public void ByValueAndReferenceConflictsStillRejectUnprovedStorage(string source)
        {
            using var native = new OpaqueRecordProjectionTests.NativeRecords(source);
            var expected = Assert.Throws<InvalidOperationException>(() =>
                OriginalRemaps(native.Unit.TranslationUnitDecl));
            var actual = Assert.Throws<InvalidOperationException>(() =>
                RemapDiscovery.FindEmbeddedIncompleteRecordPointerRemaps(native.Unit.TranslationUnitDecl));
            Assert.Equal(expected.Message, actual.Message);
        }

        private static Dictionary<string, string> OriginalRemaps(Decl root)
        {
            var declarations = NativeConditionalCompanion.Declarations(root).ToArray();
            var declared = declarations.OfType<RecordDecl>()
                .Where(record => record.LexicalParentCursor is not RecordDecl ||
                    record.LexicalParentCursor == record.SemanticParentCursor)
                .Select(record => record.Handle.CanonicalCursor).ToHashSet();
            var pending = new Stack<(ClangSharp.Type Type, bool ValueUse, bool BehindPointer)>();
            var visited = new HashSet<(ClangSharp.Type Type, bool ValueUse, bool BehindPointer)>();
            var byValue = new HashSet<string>(StringComparer.Ordinal);
            var result = new Dictionary<string, string>(StringComparer.Ordinal);
            foreach (var declaration in declarations)
            {
                if (declaration is ValueDecl value)
                    pending.Push((value.Type, true, false));
                else if (declaration is TypedefNameDecl alias)
                    pending.Push((alias.UnderlyingType, false, false));
            }
            while (pending.TryPop(out var entry))
            {
                var (type, valueUse, behindPointer) = entry;
                type = type.CanonicalType;
                if (!visited.Add((type, valueUse, behindPointer)))
                    continue;
                if (type is PointerType pointer)
                    pending.Push((pointer.PointeeType, valueUse, true));
                else if (type is RecordType record && !(record.Decl.Definition ?? record.Decl).IsCompleteDefinition &&
                    !declared.Contains(record.Decl.Handle.CanonicalCursor))
                {
                    string name = DeclarationSourceMap.QualifiedName(record.Decl.Handle);
                    if (name.Length != 0)
                    {
                        if (behindPointer)
                            result.TryAdd(name, "void");
                        else if (valueUse)
                            byValue.Add(name);
                    }
                }
                else if (type is FunctionType function)
                {
                    pending.Push((function.ReturnType, true, false));
                    if (function is FunctionProtoType prototype)
                        foreach (var parameter in prototype.ParamTypes)
                            pending.Push((parameter, true, false));
                }
                else if (type is ArrayType array)
                    pending.Push((array.ElementType, valueUse, behindPointer));
                else if (type is ReferenceType reference)
                    pending.Push((reference.PointeeType, valueUse, false));
            }
            foreach (string name in byValue)
                if (result.ContainsKey(name))
                    throw new InvalidOperationException($"Incomplete native record '{name}' is used by value; opaque pointer storage cannot establish its layout.");
            return result;
        }
    }
}

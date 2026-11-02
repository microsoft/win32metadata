using System.Collections.Generic;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class NativeCursorIndexTests
    {
        [Theory]
        [InlineData("namespace Test { struct Record { int Field; int Method(int Value); }; int Function(int); }")]
        [InlineData("template<class T> struct Record { T Field; }; template<> struct Record<int> { int Other; };")]
        [InlineData("struct Outer { struct Inner { int Field; }; }; typedef Outer::Inner Alias;")]
        public void DeclarationHandlesPreserveTheOriginalOrderAndExactManagedOwners(string source)
        {
            using var native = new OpaqueRecordProjectionTests.NativeRecords(source);
            var root = native.Unit.TranslationUnitDecl;
            var index = new NativeCursorIndex(root);
            var expected = NativeConditionalCompanion.Declarations(root).ToArray();
            Assert.Equal(expected.Select(declaration => declaration.Handle), index.Cursors);
            foreach (var declaration in expected)
                Assert.Same(declaration, index.GetCursor(declaration.Handle));
        }

        [Fact]
        public void ForwardProviderTraversalRetainsStatementOwnedRecords()
        {
            using var native = new OpaqueRecordProjectionTests.NativeRecords(
                "void Method(void) { struct Local { int Value; }; Local value; }");
            var root = native.Unit.TranslationUnitDecl;
            var index = new NativeCursorIndex(root, Include, reverseTraversal: false);
            var expected = new List<Cursor>();
            var visited = new HashSet<Cursor>();
            Walk(root);
            Assert.Equal(expected.Select(cursor => cursor.Handle), index.Cursors);
            foreach (var cursor in expected)
                Assert.Same(cursor, index.GetCursor(cursor.Handle));
            Assert.Contains(expected, cursor => cursor is RecordDecl { Name: "Local" });

            void Walk(Cursor cursor)
            {
                if (!visited.Add(cursor))
                    return;
                expected.Add(cursor);
                foreach (var child in cursor.CursorChildren.Where(child => Include(child.Handle)))
                    Walk(child);
            }
        }

        [Theory]
        [InlineData("class Record { Record(const Record&); };", false)]
        [InlineData("class Record { protected: Record(const Record&); };", false)]
        [InlineData("class Record { Record(const Record&); public: Record(); };", false)]
        [InlineData("class Record { Record(const Record&); public: Record() {} };", true)]
        [InlineData("class Record { Record(const Record&); public: Record() {} };", false)]
        [InlineData("class Record { Record& operator=(const Record&); };", false)]
        [InlineData("class Record { virtual Record& operator=(const Record&); };", false)]
        [InlineData("class Record { Record(const Record&); template<class T> Record(T); };", false)]
        public void CopyExclusionsRetainAllOriginalOverloadAndVirtualChecks(string source, bool excludeBodies)
        {
            using var native = new OpaqueRecordProjectionTests.NativeRecords(source);
            var root = native.Unit.TranslationUnitDecl;
            var actual = RemapDiscovery.FindInaccessibleCopyMembers(new NativeCursorIndex(root), excludeBodies);
            var expected = new HashSet<string>();
            foreach (var record in NativeConditionalCompanion.Declarations(root)
                .OfType<CXXRecordDecl>().Where(record => record.IsCompleteDefinition))
            {
                foreach (var group in record.Methods.GroupBy(method => method.Name))
                    if (!record.CursorChildren.OfType<FunctionTemplateDecl>().Any(template => template.Name == group.Key) &&
                        group.Any(IsInaccessibleCopyMember) && group.All(method =>
                            !method.IsVirtual && (IsInaccessibleCopyMember(method) || excludeBodies && method.HasBody)))
                        expected.Add(DeclarationSourceMap.QualifiedName(group.First().Handle));
            }
            Assert.Equal(expected.OrderBy(name => name), actual.OrderBy(name => name));

            static bool IsInaccessibleCopyMember(CXXMethodDecl method)
                => method.Access is CX_CXXAccessSpecifier.CX_CXXPrivate or CX_CXXAccessSpecifier.CX_CXXProtected &&
                    (method is CXXConstructorDecl constructor && constructor.IsCopyOrMoveConstructor ||
                        method.IsCopyAssignmentOperator || method.IsMoveAssignmentOperator);
        }

        private static bool Include(CXCursor cursor)
            => !cursor.IsAttribute && !cursor.IsReference && !cursor.IsExpression;
    }
}

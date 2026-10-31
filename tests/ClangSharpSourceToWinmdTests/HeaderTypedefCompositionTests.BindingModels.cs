using System;
using System.Collections;
using System.IO;
using System.Linq;
using System.Reflection;
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    public partial class HeaderTypedefCompositionTests
    {
        [TestMethod]
        public void TypedefFragmentsRetainOnlyTheirProducingCompilationsSemanticModels()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test {
[NativeTypedef] public partial struct FIRST { [NativeTypeName(""int"")] public int Value; }
[NativeTypedef] public partial struct SECOND { [NativeTypeName(""unsigned int"")] public uint Value; }
}");
            var compilation = fixture.Compile().CSharpCompilation;
            var merger = typeof(ClangSharpSourceCompilation).Assembly.GetType("ClangSharpSourceToWinmd.HeaderTypedefMerger")!;
            var read = merger.GetMethod("ReadFragments", BindingFlags.NonPublic | BindingFlags.Static)!;
            object[] Read(CSharpCompilation source) => ((IEnumerable)read.Invoke(null,
                new object[] { source, new GenerationValidation() })!).Cast<object>().ToArray();
            SemanticModel Model(object fragment) => (SemanticModel)fragment.GetType().GetProperty("Model")!.GetValue(fragment)!;
            var fragments = Read(compilation);
            Assert.AreEqual(2, fragments.Length);
            Assert.AreSame(compilation, Model(fragments[0]).Compilation);
            Assert.AreSame(Model(fragments[0]), Model(fragments[1]));
            var metadata = compilation.SyntaxTrees.Single(tree => tree.GetRoot().DescendantNodes()
                .OfType<ClassDeclarationSyntax>().Any(type => type.Identifier.ValueText == "NativeTypeNameAttribute"));
            var root = metadata.GetRoot();
            var attribute = root.DescendantNodes().OfType<ClassDeclarationSyntax>()
                .Single(type => type.Identifier.ValueText == "NativeTypeNameAttribute");
            var changed = SyntaxFactory.ParseMemberDeclaration(@"
public class NativeTypeNameAttribute : global::System.Attribute {
    public NativeTypeNameAttribute(int value) { }
}")!;
            var replacement = metadata.WithRootAndOptions(root.ReplaceNode(attribute, changed), metadata.Options);
            var other = compilation.ReplaceSyntaxTree(metadata, replacement);
            var incoming = Read(other);
            Assert.AreEqual(2, incoming.Length);
            Assert.AreSame(other, Model(incoming[0]).Compilation);
            Assert.AreSame(Model(incoming[0]), Model(incoming[1]));
            Assert.AreNotSame(Model(fragments[0]), Model(incoming[0]));
            Assert.AreSame(Model(fragments[0]).SyntaxTree, Model(incoming[0]).SyntaxTree);
            var value = merger.GetMethod("GetValueType", BindingFlags.NonPublic | BindingFlags.Static)!;
            Assert.IsNotNull(value.Invoke(null, new object[] { fragments[0], Model(fragments[0]) }));
            var failure = Assert.ThrowsException<TargetInvocationException>(() =>
                value.Invoke(null, new object[] { incoming[0], Model(incoming[0]) }));
            Assert.IsInstanceOfType(failure.InnerException, typeof(InvalidDataException));
            StringAssert.Contains(failure.InnerException!.Message, "Native typedef Value fields only support");
        }

        [TestMethod]
        public void RecordBindingModelsDoNotCrossCompilationVersions()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            var compilation = fixture.Compile().CSharpCompilation;
            var cache = typeof(ClangSharpSourceCompilation).GetNestedType("BindingModels", BindingFlags.NonPublic)!;
            var constructor = cache.GetConstructor(new[] { typeof(CSharpCompilation) })!;
            var get = cache.GetMethod("Get")!;
            var tree = compilation.SyntaxTrees.First();
            object original = constructor.Invoke(new object[] { compilation });
            var model = (SemanticModel)get.Invoke(original, new object[] { tree })!;
            Assert.AreSame(model, get.Invoke(original, new object[] { tree }));
            var added = CSharpSyntaxTree.ParseText("namespace Later { public struct Added { public int Value; } }",
                path: "Added.cs");
            var other = compilation.AddSyntaxTrees(added);
            object changed = constructor.Invoke(new object[] { other });
            var incoming = (SemanticModel)get.Invoke(changed, new object[] { tree })!;
            Assert.AreSame(compilation, model.Compilation);
            Assert.AreSame(other, incoming.Compilation);
            Assert.AreNotSame(model, incoming);
            Assert.AreSame(incoming, get.Invoke(changed, new object[] { tree }));
            Assert.ThrowsException<TargetInvocationException>(() => get.Invoke(original, new object[] { added }));
        }

        [TestMethod]
        public void LargeNativeRecordFamiliesKeepEveryCanonicalBinding()
        {
            const int count = 128;
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            var compilation = fixture.Compile().CSharpCompilation;
            var trees = new[] { false, true }.Select(traversed => CSharpSyntaxTree.ParseText(
                string.Join("\n", Enumerable.Range(0, count).Select(index =>
                    RecordProvider(fixture, "Test", "record-family-" + index, traversed)
                        .Replace("NATIVE_RECORD", "RECORD_" + index))),
                path: Path.Combine(fixture.DirectoryPath, traversed ? "Direct.cs" : "Transitive.cs"))).ToArray();
            compilation = compilation.AddSyntaxTrees(trees);
            var validation = new GenerationValidation();
            var merge = typeof(ClangSharpSourceCompilation).GetMethod("MergeRepeatedStructs",
                BindingFlags.NonPublic | BindingFlags.Static)!;
            var result = (CSharpCompilation)merge.Invoke(null, new object[] { compilation, validation })!;
            Assert.AreEqual(0, validation.Errors.Count);
            var errors = result.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join("\n", errors.Select(error => error.ToString())));
            for (int index = 0; index < count; index++)
            {
                var type = result.GetTypeByMetadataName("Test.RECORD_" + index)!;
                Assert.AreEqual(1, type.DeclaringSyntaxReferences.Length, type.Name);
                Assert.AreEqual(SpecialType.System_Int32, type.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.SpecialType);
                Assert.IsTrue(NativeRecordSourceProvenance.Read(
                    (StructDeclarationSyntax)type.DeclaringSyntaxReferences.Single().GetSyntax())!.TraversedHeader);
            }
        }
    }
}

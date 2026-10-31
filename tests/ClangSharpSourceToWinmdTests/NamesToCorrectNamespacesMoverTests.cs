using System.Collections.Generic;
using System.Linq;
using System.Text;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class NamesToCorrectNamespacesMoverTests
    {
        [TestMethod]
        public void MovedMembersKeepAliasesAndNestedAndGenericTypePrecedence()
        {
            var tree = CSharpSyntaxTree.ParseText(@"
using System.Collections.Generic;
using Alias = Foreign.Payload;
namespace Original {
public struct Payload { public int Value; }
public unsafe partial struct Consumer<T> {
    public Payload Value;
    public Payload[] Array;
    public Payload? Nullable;
    public Payload* Pointer;
    public List<Payload> List;
    public delegate* unmanaged<Payload*, Payload> Function;
    public Alias Imported;
    public T Generic;
    public U Echo<U>(U value) => value;
}
public unsafe partial struct Nested {
    public struct Payload { public short Value; }
    public delegate Payload Callback(Payload value);
    public Payload Value;
    public Callback Function;
    public struct Inner {
        public Inner* Self;
        public Payload Value;
    }
}
}", path: "Bindings.cs");
            var names = new Dictionary<string, string>
            {
                ["Payload"] = "Support", ["Consumer"] = "Destination", ["Nested"] = "Destination",
                ["T"] = "Support", ["U"] = "Support", ["Callback"] = "Support", ["Inner"] = "Support",
            };
            var sourceTypes = names.Keys.Append("Alias").Select(name => ("Original", name)).ToHashSet();
            var moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree, names, sourceTypes);
            var compilation = Compile(moved);
            var consumer = compilation.GetTypeByMetadataName("Destination.Consumer`1")!;
            Assert.AreEqual("Support.Payload", Field(consumer, "Value").Type.ToDisplayString());
            Assert.AreEqual("Support.Payload", ((IArrayTypeSymbol)Field(consumer, "Array").Type).ElementType.ToDisplayString());
            Assert.AreEqual("Support.Payload", ((INamedTypeSymbol)Field(consumer, "Nullable").Type).TypeArguments.Single().ToDisplayString());
            Assert.AreEqual("Support.Payload", ((IPointerTypeSymbol)Field(consumer, "Pointer").Type).PointedAtType.ToDisplayString());
            Assert.AreEqual("Support.Payload", ((INamedTypeSymbol)Field(consumer, "List").Type).TypeArguments.Single().ToDisplayString());
            var function = (IFunctionPointerTypeSymbol)Field(consumer, "Function").Type;
            Assert.AreEqual("Support.Payload", function.Signature.ReturnType.ToDisplayString());
            Assert.AreEqual("Support.Payload", ((IPointerTypeSymbol)function.Signature.Parameters.Single().Type).PointedAtType.ToDisplayString());
            Assert.AreEqual("Foreign.Payload", Field(consumer, "Imported").Type.ToDisplayString());
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(consumer.TypeParameters.Single(), Field(consumer, "Generic").Type));
            var echo = consumer.GetMembers("Echo").OfType<IMethodSymbol>().Single();
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(echo.TypeParameters.Single(), echo.ReturnType));
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(echo.TypeParameters.Single(), echo.Parameters.Single().Type));
            var nested = compilation.GetTypeByMetadataName("Destination.Nested")!;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(nested.GetTypeMembers("Payload").Single(), Field(nested, "Value").Type));
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(nested.GetTypeMembers("Callback").Single(), Field(nested, "Function").Type));
            var inner = nested.GetTypeMembers("Inner").Single();
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(inner, ((IPointerTypeSymbol)Field(inner, "Self").Type).PointedAtType));
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(nested.GetTypeMembers("Payload").Single(), Field(inner, "Value").Type));
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void RelocatedDependenciesDoNotReuseOtherTreesLexicalScopes(bool nativeRoute)
        {
            var names = nativeRoute ? new Dictionary<string, string>() :
                new Dictionary<string, string> { ["Payload"] = "Support", ["Consumer"] = "Destination" };
            var routes = nativeRoute ? new Dictionary<(string Namespace, string Name), string>
                { [("Original", "Payload")] = "Support" } : null;
            var sourceTypes = new HashSet<(string Namespace, string Name)> { ("Original", "Payload") };
            var shadowed = CSharpSyntaxTree.ParseText(@"
namespace Original {
public struct Payload { public int Value; }
public struct Consumer {
    public struct Payload { public short Value; }
    public Payload Value;
} }", path: "Shadowed.cs");
            var moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(shadowed, names, sourceTypes, routes);
            string owner = nativeRoute ? "Original.Consumer" : "Destination.Consumer";
            var first = Compile(moved).GetTypeByMetadataName(owner)!;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(first.GetTypeMembers("Payload").Single(), Field(first, "Value").Type));
            var unshadowed = CSharpSyntaxTree.ParseText(@"
namespace Original {
public struct Payload { public int Value; }
public struct Consumer { public Payload Value; }
}", path: "Unshadowed.cs");
            moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(unshadowed, names, sourceTypes, routes);
            var second = Compile(moved).GetTypeByMetadataName(owner)!;
            Assert.AreEqual("Support.Payload", Field(second, "Value").Type.ToDisplayString());
            var manual = shadowed.WithFilePath("Bindings.manual.cs");
            Assert.AreSame(manual, NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(manual, names, sourceTypes, routes));
        }

        [TestMethod]
        public void LargeSiblingScopesPreserveEveryNestedTypeBinding()
        {
            const int count = 1024;
            var source = new StringBuilder("namespace Original { public partial struct Consumer {");
            var sourceTypes = new HashSet<(string Namespace, string Name)>();
            for (int index = 0; index < count; index++)
            {
                source.Append($"public struct Nested{index} {{ public int Value; }} public Nested{index} Value{index};");
                sourceTypes.Add(("Original", $"Nested{index}"));
            }
            source.Append("} }");
            var tree = CSharpSyntaxTree.ParseText(source.ToString(), path: "Large.cs");
            var moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree,
                new Dictionary<string, string> { ["Consumer"] = "Destination" }, sourceTypes);
            var consumer = Compile(moved).GetTypeByMetadataName("Destination.Consumer")!;
            Assert.AreEqual(count, consumer.GetTypeMembers().Length);
            for (int index = 0; index < count; index++)
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(consumer.GetTypeMembers($"Nested{index}").Single(),
                    Field(consumer, $"Value{index}").Type), $"Nested{index}");
        }

        [TestMethod]
        public void CompositeTypesAndNestedBodyTypesKeepTheirOriginalBindings()
        {
            var tree = CSharpSyntaxTree.ParseText(@"
namespace Original {
public struct Payload { public int Value; }
public unsafe partial struct Consumer {
    public delegate* unmanaged<Payload*, Payload> Function;
    public Payload Convert(Payload* value) => *(Payload*)value;
    public System.Type Type => typeof(Payload);
} }", path: "Composite.cs");
            var moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree,
                new Dictionary<string, string> { ["Payload"] = "Support", ["Consumer"] = "Destination" },
                new HashSet<(string Namespace, string Name)> { ("Original", "Payload") });
            var compilation = Compile(moved);
            var payload = compilation.GetTypeByMetadataName("Support.Payload")!;
            var consumer = compilation.GetTypeByMetadataName("Destination.Consumer")!;
            var function = (IFunctionPointerTypeSymbol)Field(consumer, "Function").Type;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(payload, function.Signature.ReturnType));
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(payload,
                ((IPointerTypeSymbol)function.Signature.Parameters.Single().Type).PointedAtType));
            var method = consumer.GetMembers("Convert").OfType<IMethodSymbol>().Single();
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(payload, method.ReturnType));
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(payload,
                ((IPointerTypeSymbol)method.Parameters.Single().Type).PointedAtType));
            var model = compilation.GetSemanticModel(moved);
            foreach (var expression in moved.GetRoot().DescendantNodes().Where(node =>
                node is Microsoft.CodeAnalysis.CSharp.Syntax.CastExpressionSyntax or
                    Microsoft.CodeAnalysis.CSharp.Syntax.TypeOfExpressionSyntax))
            {
                var type = expression is Microsoft.CodeAnalysis.CSharp.Syntax.CastExpressionSyntax cast
                    ? ((Microsoft.CodeAnalysis.CSharp.Syntax.PointerTypeSyntax)cast.Type).ElementType
                    : ((Microsoft.CodeAnalysis.CSharp.Syntax.TypeOfExpressionSyntax)expression).Type;
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(payload, model.GetTypeInfo(type).Type));
            }
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void EmptyImportsAreStillRemovedWithoutNamespaceMoves(bool inspectSourceTypes)
        {
            var tree = CSharpSyntaxTree.ParseText(@"
using System.Runtime.InteropServices;
namespace Original { public static class Apis {
    [DllImport("""")] public static extern int Missing();
    [DllImport(""kernel32.dll"")] public static extern int Retained();
} }", path: "NoMoves.cs");
            var moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree,
                new Dictionary<string, string>(), inspectSourceTypes
                    ? new HashSet<(string Namespace, string Name)> { ("Original", "Payload") } : null);
            var apis = Compile(moved).GetTypeByMetadataName("Original.Apis")!;
            Assert.AreEqual(0, apis.GetMembers("Missing").Length);
            Assert.AreEqual(1, apis.GetMembers("Retained").Length);
        }

        private static IFieldSymbol Field(INamedTypeSymbol type, string name) => type.GetMembers(name).OfType<IFieldSymbol>().Single();

        private static CSharpCompilation Compile(SyntaxTree tree)
        {
            var foreign = CSharpSyntaxTree.ParseText("namespace Foreign { public struct Payload { public short Value; } }",
                path: "Foreign.manual.cs");
            var compilation = CSharpCompilation.Create("NamespaceScopes", new[] { tree, foreign },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join("\n", errors.Select(error => error.ToString())));
            return compilation;
        }
    }
}

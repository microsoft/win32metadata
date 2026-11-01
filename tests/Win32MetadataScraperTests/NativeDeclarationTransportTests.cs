using System;
using System.IO;
using System.Linq;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class NativeDeclarationTransportTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", Architecture.X86)]
        [InlineData("x64", "x86_64-pc-windows-msvc", Architecture.X64)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", Architecture.Arm64)]
        public void LogicalGroupProducerTransportsTheActualNativeDeclaration(
            string architecture, string target, Architecture expectedArchitecture)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(
                architecture, target, @"
#define WIN32METADATA
#include <win32metadata_annotations.h>
#define GROUP_FIRST 1
#define GROUP_SECOND 2
_Win32_Enum_(GROUP, unsigned int, GROUP_FIRST, GROUP_SECOND);
typedef unsigned int ORDINARY_COUNT;
GROUP ReadGroup(GROUP value);
ORDINARY_COUNT ReadCount(ORDINARY_COUNT value);
", namespaceName: "NativeOwner");

            fixture.AssertSuccess();
            var root = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot();
            var declaration = root.DescendantNodes().OfType<EnumDeclarationSyntax>()
                .Single(value => value.Identifier.ValueText == "GROUP");
            var source = NativeDeclarationSourceProvenance.Read(declaration);
            Assert.NotNull(source);
            Assert.Equal(NativeDeclarationKind.LogicalEnum, source.Kind);
            Assert.EndsWith("@T@GROUP", source.Identity, StringComparison.Ordinal);
            Assert.Equal("GROUP", source.NativeName);
            Assert.Equal(Path.GetFullPath(fixture.Header), source.Header);
            Assert.Equal(NativeConstantGroupProvenance.HashFile(fixture.Header), source.HeaderHash);
            Assert.Equal("GROUP", source.Name);
            Assert.Equal("NativeOwner", source.Namespace);
            Assert.True(source.TraversedHeader);
            Assert.Equal(expectedArchitecture, source.SourceArchitecture);
            string[] lines = File.ReadAllLines(fixture.Header);
            Assert.Equal((uint)(Array.FindIndex(lines, line =>
                line.Contains("_Win32_Enum_(GROUP,", StringComparison.Ordinal)) + 1), source.Line);
            Assert.InRange(source.Column, 1U, (uint)lines[checked((int)source.Line - 1)].Length);

            var constants = NativeConstantGroupProvenance.Read(declaration);
            Assert.NotNull(constants);
            Assert.Equal(expectedArchitecture, constants.Architecture);
            Assert.Equal(source.Header, constants.Group.Header);
            Assert.Equal("::GROUP", constants.Group.NativeName);
            Assert.Equal(source.Name, constants.Group.Name);
            Assert.Equal(source.Namespace, constants.Group.Namespace);
            Assert.Equal("uint", constants.Group.StorageType);
            Assert.Equal("LogicalGroup", constants.Group.Kind);
            Assert.Equal(new[] { "GROUP_FIRST", "GROUP_SECOND" },
                declaration.Members.Select(member => member.Identifier.ValueText)
                    .OrderBy(value => value, StringComparer.Ordinal));
            var sourceTree = CSharpSyntaxTree.ParseText(fixture.ReadSource());
            var compilation = CSharpCompilation.Create("NativeLogicalGroupValues",
                new[] { declaration.SyntaxTree, sourceTree },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) });
            var model = compilation.GetSemanticModel(declaration.SyntaxTree);
            var members = declaration.Members.ToDictionary(member => member.Identifier.ValueText,
                member => Assert.IsAssignableFrom<IFieldSymbol>(model.GetDeclaredSymbol(member)));
            Assert.True(members["GROUP_FIRST"].HasConstantValue);
            Assert.True(members["GROUP_SECOND"].HasConstantValue);
            Assert.Equal(1U, Assert.IsType<uint>(members["GROUP_FIRST"].ConstantValue));
            Assert.Equal(2U, Assert.IsType<uint>(members["GROUP_SECOND"].ConstantValue));
            Assert.DoesNotContain("\"Size\"", declaration.GetTrailingTrivia().ToFullString());
            Assert.DoesNotContain("\"Alignment\"", declaration.GetTrailingTrivia().ToFullString());

            var methods = sourceTree.GetRoot()
                .DescendantNodes().OfType<MethodDeclarationSyntax>().ToArray();
            var groupMethod = methods.Single(method => method.Identifier.ValueText == "ReadGroup");
            Assert.Equal("GROUP", SyntaxUtils.GetNativeTypeNameFromAttributesLists(
                SyntaxFactory.List(groupMethod.AttributeLists.Where(list => list.Target?.Identifier.ValueText == "return"))));
            Assert.Equal("GROUP", SyntaxUtils.GetNativeTypeNameFromAttributesLists(
                groupMethod.ParameterList.Parameters.Single().AttributeLists));
            var ordinary = methods
                .Single(method => method.Identifier.ValueText == "ReadCount");
            Assert.Equal("ORDINARY_COUNT", ordinary.ReturnType.ToString());
            Assert.Equal("ORDINARY_COUNT", ordinary.ParameterList.Parameters.Single().Type.ToString());
            var ordinaryProvider = root.DescendantNodes().OfType<StructDeclarationSyntax>()
                .Single(value => value.Identifier.ValueText == "ORDINARY_COUNT");
            var ordinarySource = NativeTypedefSourceProvenance.Read(ordinaryProvider);
            Assert.NotNull(ordinarySource);
            Assert.EndsWith("@T@ORDINARY_COUNT", ordinarySource.Identity, StringComparison.Ordinal);
            Assert.Equal("ORDINARY_COUNT", ordinarySource.NativeName);
            Assert.Equal("NativeOwner", ordinarySource.Namespace);
            Assert.Equal(source.Header, ordinarySource.Header);
            Assert.Equal(source.HeaderHash, ordinarySource.HeaderHash);
            Assert.Equal(expectedArchitecture, ordinarySource.SourceArchitecture);
            Assert.Equal(4, ordinarySource.Size);
            Assert.Equal(4, ordinarySource.Alignment);
            Assert.True(NativeTypedefProjectionProvenance.IsInferred(ordinaryProvider));
            Assert.False(NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(ordinaryProvider));
            var ordinaryField = ordinaryProvider.Members.OfType<FieldDeclarationSyntax>().Single();
            Assert.Equal("Value", ordinaryField.Declaration.Variables.Single().Identifier.ValueText);
            Assert.Equal("uint", ordinaryField.Declaration.Type.ToString());
            var providerSymbol = Assert.IsAssignableFrom<INamedTypeSymbol>(model.GetDeclaredSymbol(ordinaryProvider));
            var ordinarySymbol = Assert.IsAssignableFrom<IMethodSymbol>(
                compilation.GetSemanticModel(sourceTree).GetDeclaredSymbol(ordinary));
            Assert.True(SymbolEqualityComparer.Default.Equals(providerSymbol, ordinarySymbol.ReturnType));
            Assert.True(SymbolEqualityComparer.Default.Equals(providerSymbol, ordinarySymbol.Parameters.Single().Type));
            var storageSymbol = Assert.IsAssignableFrom<IFieldSymbol>(
                model.GetDeclaredSymbol(ordinaryField.Declaration.Variables.Single()));
            Assert.Equal(SpecialType.System_UInt32, storageSymbol.Type.SpecialType);

            var reparsed = CSharpSyntaxTree.ParseText(declaration.ToFullString()).GetRoot()
                .DescendantNodes().OfType<EnumDeclarationSyntax>().Single();
            Assert.Equal(source, NativeDeclarationSourceProvenance.Read(reparsed));
            var transportedConstants = NativeConstantGroupProvenance.Read(reparsed);
            Assert.NotNull(transportedConstants);
            Assert.Equal(constants.SourceFile, transportedConstants.SourceFile);
            Assert.Equal(constants.SourceHash, transportedConstants.SourceHash);
            Assert.Equal(constants.Architecture, transportedConstants.Architecture);
            Assert.Equal(constants.Group.NativeName, transportedConstants.Group.NativeName);
            Assert.Equal(constants.Group.Name, transportedConstants.Group.Name);
            Assert.Equal(constants.Group.Namespace, transportedConstants.Group.Namespace);
            Assert.Equal(constants.Group.StorageType, transportedConstants.Group.StorageType);
            Assert.Equal(constants.Group.Header, transportedConstants.Group.Header);
            Assert.Equal(constants.Group.Line, transportedConstants.Group.Line);
            Assert.Equal(constants.Group.Kind, transportedConstants.Group.Kind);
            Assert.Equal(constants.Group.Members.Length, transportedConstants.Group.Members.Length);
            foreach (var pair in constants.Group.Members.Zip(transportedConstants.Group.Members))
            {
                Assert.Equal(pair.First.Name, pair.Second.Name);
                Assert.Equal(pair.First.Expression, pair.Second.Expression);
                Assert.Equal<NativeConstantBinding>(pair.First.Bindings, pair.Second.Bindings);
            }
            Assert.Equal(declaration.GetLeadingTrivia().ToFullString(), reparsed.GetLeadingTrivia().ToFullString());
        }

        [Fact]
        public void IncompleteRecordProducerTransportsDeclarationIdentityWithoutLayout()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(
                "x86", "i686-pc-windows-msvc", @"
struct FORWARD;
struct COMPLETE { int Value; };
FORWARD* ReadForward(FORWARD* value);
COMPLETE* ReadComplete(COMPLETE* value);
", namespaceName: "NativeOwner");

            fixture.AssertSuccess();
            var root = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>()
                .Single(value => value.Identifier.ValueText == "FORWARD");
            var source = NativeDeclarationSourceProvenance.Read(declaration);
            Assert.NotNull(source);
            Assert.Equal(NativeDeclarationKind.IncompleteRecord, source.Kind);
            Assert.Equal("c:@S@FORWARD", source.Identity);
            Assert.Equal("FORWARD", source.NativeName);
            Assert.Equal(Path.GetFullPath(fixture.Header), source.Header);
            Assert.Equal(NativeConstantGroupProvenance.HashFile(fixture.Header), source.HeaderHash);
            Assert.Equal("FORWARD", source.Name);
            Assert.Equal("NativeOwner", source.Namespace);
            Assert.True(source.TraversedHeader);
            Assert.Equal(Architecture.X86, source.SourceArchitecture);
            string[] lines = File.ReadAllLines(fixture.Header);
            Assert.Equal((uint)(Array.FindIndex(lines, line => line == "struct FORWARD;") + 1), source.Line);
            Assert.Equal(8U, source.Column);
            Assert.Empty(declaration.Members);
            Assert.Null(NativeRecordSourceProvenance.Read(declaration));
            Assert.Null(NativeTypedefSourceProvenance.Read(declaration));
            Assert.DoesNotContain("\"Size\"", declaration.GetTrailingTrivia().ToFullString());
            Assert.DoesNotContain("\"Alignment\"", declaration.GetTrailingTrivia().ToFullString());

            var method = root.DescendantNodes().OfType<MethodDeclarationSyntax>()
                .Single(value => value.Identifier.ValueText == "ReadForward");
            var result = Assert.IsType<PointerTypeSyntax>(method.ReturnType);
            var parameter = Assert.IsType<PointerTypeSyntax>(method.ParameterList.Parameters.Single().Type);
            Assert.Equal("FORWARD", Assert.IsType<IdentifierNameSyntax>(result.ElementType).Identifier.ValueText);
            Assert.Equal("FORWARD", Assert.IsType<IdentifierNameSyntax>(parameter.ElementType).Identifier.ValueText);

            var complete = root.DescendantNodes().OfType<StructDeclarationSyntax>()
                .Single(value => value.Identifier.ValueText == "COMPLETE");
            Assert.NotNull(NativeRecordSourceProvenance.Read(complete));
            Assert.Null(NativeDeclarationSourceProvenance.Read(complete));
            var reparsed = CSharpSyntaxTree.ParseText(declaration.ToFullString()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            Assert.Equal(source, NativeDeclarationSourceProvenance.Read(reparsed));
        }
    }
}

using System;
using System.Collections.Immutable;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using Xunit;

namespace MetadataUtils.Tests
{
    public class DelegateValidatorTests
    {
        [Theory]
        [InlineData(7)]
        [InlineData(8)]
        public void DelegateParametersAreReportedOnceWithDistinctCleanupCallback(int arity)
        {
            var parameterTypes = Enumerable.Repeat("int", arity).ToArray();
            parameterTypes[arity - 4] = "Test.Callback**";
            parameterTypes[arity - 3] = "Test.CleanupCallback**";
            var parameters = Enumerable.Range(0, arity)
                .Select(i => new ParameterInfo($"arg{i}", ParameterAttributes.Out)).ToArray();
            parameters[arity - 4] = new ParameterInfo("Callback", ParameterAttributes.Out);
            parameters[arity - 3] = new ParameterInfo("CleanupCallback", ParameterAttributes.Out);
            var owner = new DelegateTypeInfo("Test", "Owner", Signature(parameterTypes), parameters);

            var findings = DelegateValidator.FindPointersToDelegates(
                new[] { Callback("Callback"), Callback("CleanupCallback"), owner }, Array.Empty<string>()).ToArray();

            Assert.Equal(2, findings.Length);
            Assert.All(findings, finding => Assert.Equal("Test.Owner", finding.Name));
            Assert.Equal(new[] { "Callback", "CleanupCallback" }, findings.Select(finding => finding.ParameterName));
            Assert.Equal(new[] { arity - 3, arity - 2 }, findings.Select(finding => finding.ParameterSequence.Value));
            Assert.Equal(new[] { "Test.Callback**", "Test.CleanupCallback**" }, findings.Select(finding => finding.Type));
        }

        [Theory]
        [InlineData("Test.Callback", ParameterAttributes.None, false)]
        [InlineData("Test.Callback*", ParameterAttributes.In, true)]
        [InlineData("Test.Callback*", ParameterAttributes.None, true)]
        [InlineData("Test.Callback*", ParameterAttributes.Out, false)]
        [InlineData("Test.Callback*", ParameterAttributes.In | ParameterAttributes.Out, false)]
        [InlineData("Test.Callback**", ParameterAttributes.Out, true)]
        [InlineData("Test.Callback**", ParameterAttributes.In | ParameterAttributes.Out, true)]
        [InlineData("Test.Callback***", ParameterAttributes.Out, true)]
        [InlineData("Other.Callback*", ParameterAttributes.In, false)]
        [InlineData("test.Callback*", ParameterAttributes.In, false)]
        public void OnlyOneOutPointerLayerIsNormalized(string type, ParameterAttributes attributes, bool reported)
        {
            var owner = new DelegateTypeInfo("Test", "Owner", Signature(type),
                new[] { new ParameterInfo("Value", attributes) });
            var findings = DelegateValidator.FindPointersToDelegates(
                new[] { Callback("Callback"), owner }, Array.Empty<string>()).ToArray();

            Assert.Equal(reported ? 1 : 0, findings.Length);
            if (reported)
            {
                Assert.Equal(type, findings[0].Type);
                Assert.Equal("Value", findings[0].ParameterName);
                Assert.Equal(1, findings[0].ParameterSequence);
            }
        }

        [Fact]
        public void RepeatedTypesAtDifferentParameterSitesAreNotDeduplicated()
        {
            var owner = new DelegateTypeInfo("Test", "Owner", Signature("Test.Callback*", "Test.Callback*"),
                new[] { new ParameterInfo("First", ParameterAttributes.In), new ParameterInfo("Second", ParameterAttributes.In) });
            var findings = DelegateValidator.FindPointersToDelegates(
                new[] { Callback("Callback"), owner }, Array.Empty<string>()).ToArray();

            Assert.Equal(new[] { "First", "Second" }, findings.Select(finding => finding.ParameterName));
            Assert.Equal(new[] { 1, 2 }, findings.Select(finding => finding.ParameterSequence.Value));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ClassAndInterfaceMethodsReportEveryOffendingParameter(bool isInterface)
        {
            var method = new MethodInfo("Method", Signature("Test.Callback*", "Test.Callback**", "Test.Callback*"),
                new[]
                {
                    new ParameterInfo("Input", ParameterAttributes.In),
                    new ParameterInfo("BadOutput", ParameterAttributes.Out),
                    new ParameterInfo("GoodOutput", ParameterAttributes.Out),
                });
            TypeInfo owner = isInterface
                ? new InterfaceInfo("Test", "Owner", new[] { method }, 1)
                : new ClassInfo("Test", "Owner", new[] { method }, Array.Empty<FieldInfo>());
            var types = new[] { Callback("Callback"), owner };

            var findings = DelegateValidator.FindPointersToDelegates(types, Array.Empty<string>()).ToArray();
            Assert.Equal(new[] { "Input", "BadOutput" }, findings.Select(finding => finding.ParameterName));
            Assert.All(findings, finding => Assert.Equal("Test.Owner.Method", finding.Name));
            Assert.Empty(DelegateValidator.FindPointersToDelegates(types, new[] { "Test.Owner.Method" }));
            Assert.Equal(2, DelegateValidator.FindPointersToDelegates(types, new[] { "Method", "Owner.Method" }).Count());
        }

        [Theory]
        [InlineData("Test.Owner.Value", 1)]
        [InlineData("Value", 2)]
        [InlineData("Owner.Value", 2)]
        [InlineData("Test.Owner", 2)]
        [InlineData("test.Owner.Value", 2)]
        [InlineData("Test.Callback", 2)]
        public void PointerAllowancesMatchOnlyTheFullSite(string allowed, int count)
        {
            var fields = new[] { new FieldInfo("Test.Callback*", "Value"), new FieldInfo("Test.Callback", "Direct") };
            TypeInfo[] types =
            {
                Callback("Callback"),
                new StructInfo("Test", "Owner", fields),
                new StructInfo("Other", "Owner", fields),
            };

            var findings = DelegateValidator.FindPointersToDelegates(types, new[] { allowed }).ToArray();
            Assert.Equal(count, findings.Length);
            Assert.All(findings, finding =>
            {
                Assert.Equal("Test.Callback*", finding.Type);
                Assert.Null(finding.ParameterName);
                Assert.Null(finding.ParameterSequence);
            });
            Assert.Contains(findings, finding => finding.Name == "Other.Owner.Value");
        }

        [Fact]
        public void DelegateAllowancesRetainWholeSignatureSiteSemantics()
        {
            var owner = new DelegateTypeInfo("Test", "Owner", Signature("Test.Callback*"),
                new[] { new ParameterInfo("Value", ParameterAttributes.In) });
            var types = new[] { Callback("Callback"), owner };

            Assert.Empty(DelegateValidator.FindPointersToDelegates(types, new[] { "Test.Owner" }));
            Assert.Single(DelegateValidator.FindPointersToDelegates(types, new[] { "Owner", "Test.Owner.Value" }));
        }

        [Fact]
        public void FullyQualifiedEmptyAllowanceDoesNotPermitHomonyms()
        {
            var allowed = Callback("Callback");
            var homonym = new DelegateTypeInfo("Other", "Callback", Signature(), Array.Empty<ParameterInfo>());
            var unmatched = Callback("Unmatched");

            var findings = DelegateValidator.FindEmptyDelegates(
                new[] { allowed, homonym, unmatched }, new[] { "Test.Callback" }).ToArray();

            Assert.Equal(new[] { homonym, unmatched }, findings);
        }

        [Fact]
        public void LegacyShortEmptyAllowancesRemainSupported()
        {
            var homonym = new DelegateTypeInfo("Other", "Callback", Signature(), Array.Empty<ParameterInfo>());
            var unmatched = Callback("Unmatched");

            Assert.Equal(new[] { unmatched }, DelegateValidator.FindEmptyDelegates(
                new[] { Callback("Callback"), homonym, unmatched }, new[] { "Callback" }));
        }

        [Theory]
        [InlineData("callback")]
        [InlineData("test.Callback")]
        [InlineData("Test.callback")]
        public void EmptyAllowancesAreCaseSensitive(string allowed)
        {
            Assert.Single(DelegateValidator.FindEmptyDelegates(new[] { Callback("Callback") }, new[] { allowed }));
        }

        [Fact]
        public void EmptyMeansZeroSignatureArityNotMissingParameterRows()
        {
            var nonempty = new DelegateTypeInfo("Test", "Nonempty", Signature("int"), Array.Empty<ParameterInfo>());
            Assert.Empty(DelegateValidator.FindEmptyDelegates(new[] { nonempty }, Array.Empty<string>()));
            Assert.Single(DelegateValidator.FindEmptyDelegates(new[] { Callback("Unmatched") }, Array.Empty<string>()));
        }

        [Fact]
        public void InconsistentParameterInformationIsAnErrorNotAQuietSuccess()
        {
            var owner = new DelegateTypeInfo("Test", "Owner", Signature("Test.Callback*"), Array.Empty<ParameterInfo>());
            var error = Assert.Throws<InvalidOperationException>(() =>
                DelegateValidator.FindPointersToDelegates(
                    new[] { Callback("Callback"), owner }, Array.Empty<string>()).ToArray());

            Assert.Contains("Test.Owner", error.Message);
        }

        private static DelegateTypeInfo Callback(string name) =>
            new DelegateTypeInfo("Test", name, Signature(), Array.Empty<ParameterInfo>());

        private static MethodSignature<string> Signature(params string[] parameters) =>
            new MethodSignature<string>(new SignatureHeader(0), "void", parameters.Length, 0, parameters.ToImmutableArray());
    }
}

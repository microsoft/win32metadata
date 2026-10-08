using System.Collections.Generic;
using System.Collections.Immutable;
using System.Linq;
using System.Reflection.Metadata;
using ICSharpCode.Decompiler.TypeSystem;
using Moq;
using Xunit;

namespace MetadataUtils.Tests
{
    public class ConstantValidatorTests
    {
        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void DisjointFieldVariantsAreNotDuplicates(bool reverse)
        {
            var apis = Type("Test.Apis");
            Fields(apis, Field(apis, "SIZE", Architecture.X86), Field(apis, "SIZE", Architecture.X64 | Architecture.Arm64));
            if (reverse)
            {
                Fields(apis, apis.Object.Fields.Reverse().ToArray());
            }

            Assert.Empty(ConstantValidator.FindDuplicates(new[] { apis.Object }));
        }

        [Theory]
        [InlineData(Architecture.X86, Architecture.X86)]
        [InlineData(Architecture.X86 | Architecture.X64, Architecture.X64 | Architecture.Arm64)]
        [InlineData(null, Architecture.X86)]
        public void SameOwnerOverlappingFieldsRemainDuplicates(Architecture? first, Architecture? second)
        {
            var apis = Type("Test.Apis");
            Fields(apis, Field(apis, "VALUE", first), Field(apis, "VALUE", second));

            var diagnostic = Assert.Single(ConstantValidator.FindDuplicates(new[] { apis.Object }));
            Assert.Equal("VALUE", diagnostic.Name);
            Assert.Equal(new[] { "Test.Apis", "Test.Apis" }, diagnostic.Owners);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ContainingTypeVariantsRestrictFieldAvailability(bool nested)
        {
            var x86 = Type("Test.Apis", Architecture.X86);
            var other = Type("Test.Apis", Architecture.X64 | Architecture.Arm64);
            if (nested)
            {
                var x86Parent = x86;
                var otherParent = other;
                x86 = Type("Test.Container.Apis");
                other = Type("Test.Container.Apis");
                x86.SetupGet(t => t.DeclaringTypeDefinition).Returns(x86Parent.Object);
                other.SetupGet(t => t.DeclaringTypeDefinition).Returns(otherParent.Object);
            }

            Fields(x86, Field(x86, "VALUE"));
            Fields(other, Field(other, "VALUE"));

            Assert.Empty(ConstantValidator.FindDuplicates(new[] { x86.Object, other.Object }));
        }

        [Theory]
        [InlineData(Architecture.X86, false)]
        [InlineData(Architecture.X64, true)]
        public void FieldMaskIntersectsContainingTypeMask(Architecture secondMask, bool overlaps)
        {
            var first = Type("Test.Apis", Architecture.X86 | Architecture.X64);
            var second = Type("Test.Apis", secondMask);
            Fields(first, Field(first, "VALUE", Architecture.X64 | Architecture.Arm64));
            Fields(second, Field(second, "VALUE"));

            Assert.Equal(overlaps ? 1 : 0, ConstantValidator.FindDuplicates(new[] { first.Object, second.Object }).Count);
        }

        [Fact]
        public void ImpossibleFieldAvailabilityDoesNotConflict()
        {
            var first = Type("Test.Apis", Architecture.X86);
            var second = Type("Other.Apis");
            Fields(first, Field(first, "VALUE", Architecture.X64));
            Fields(second, Field(second, "VALUE"));

            Assert.Empty(ConstantValidator.FindDuplicates(new[] { first.Object, second.Object }));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void GuidOnlyStructsUseTheirArchitectureMasks(bool overlaps)
        {
            var first = Type("First.VALUE", Architecture.X86, TypeKind.Struct, "GuidAttribute");
            var second = Type("Second.VALUE", overlaps ? Architecture.X86 : Architecture.X64, TypeKind.Struct, "GuidAttribute");

            Assert.Equal(overlaps ? 1 : 0, ConstantValidator.FindDuplicates(new[] { first.Object, second.Object }).Count);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void UnscopedEnumAndApisOverlapIsNotWaived(bool scoped)
        {
            var apis = Type("Test.Apis");
            var enumeration = Type("Test.Options", null, TypeKind.Enum, scoped ? "ScopedEnumAttribute" : null);
            Fields(apis, Field(apis, "VALUE"));
            Fields(enumeration, Field(enumeration, "VALUE"), Field(enumeration, "value__"));

            Assert.Equal(scoped ? 0 : 1, ConstantValidator.FindDuplicates(new[] { apis.Object, enumeration.Object }).Count);
        }

        [Fact]
        public void NonOverlappingThirdOwnerIsNotReported()
        {
            var first = Type("First.Apis", Architecture.X86);
            var second = Type("Second.Apis", Architecture.X86);
            var third = Type("Third.Apis", Architecture.X64);
            foreach (var type in new[] { first, second, third })
            {
                Fields(type, Field(type, "VALUE"));
            }

            var diagnostic = Assert.Single(ConstantValidator.FindDuplicates(new[] { first.Object, second.Object, third.Object }));
            Assert.Equal(new[] { "First.Apis", "Second.Apis" }, diagnostic.Owners);
        }

        [Fact]
        public void ExistingCaseInsensitiveNameCheckIsPreserved()
        {
            var apis = Type("Test.Apis");
            Fields(apis, Field(apis, "value"), Field(apis, "VALUE"));

            Assert.Single(ConstantValidator.FindDuplicates(new[] { apis.Object }));
        }

        [Fact]
        public void EnumBackingFieldsAndOrdinaryClassFieldsRemainExcluded()
        {
            var first = Type("Test.First", null, TypeKind.Enum);
            var second = Type("Test.Second", null, TypeKind.Enum);
            Fields(first, Field(first, "value__"));
            Fields(second, Field(second, "value__"));
            var ordinary = Type("Test.Ordinary");
            Fields(ordinary, Field(ordinary, "VALUE"), Field(ordinary, "VALUE"));

            Assert.Empty(ConstantValidator.FindDuplicates(new[] { first.Object, second.Object, ordinary.Object }));
        }

        private static Mock<ITypeDefinition> Type(
            string fullName, Architecture? architecture = null, TypeKind kind = TypeKind.Class, string attribute = null)
        {
            var type = new Mock<ITypeDefinition>();
            type.SetupGet(t => t.Name).Returns(fullName.Split('.').Last());
            type.SetupGet(t => t.FullName).Returns(fullName);
            type.SetupGet(t => t.Kind).Returns(kind);
            type.Setup(t => t.GetAttributes()).Returns(Attributes(architecture, attribute));
            Fields(type);
            return type;
        }

        private static void Fields(Mock<ITypeDefinition> type, params IField[] fields)
        {
            type.SetupGet(t => t.Fields).Returns(fields);
        }

        private static IField Field(Mock<ITypeDefinition> owner, string name, Architecture? architecture = null)
        {
            var field = new Mock<IField>();
            field.SetupGet(f => f.Name).Returns(name);
            field.SetupGet(f => f.DeclaringTypeDefinition).Returns(owner.Object);
            field.Setup(f => f.GetAttributes()).Returns(Attributes(architecture));
            return field.Object;
        }

        private static IEnumerable<IAttribute> Attributes(Architecture? architecture, string extra = null)
        {
            if (architecture is Architecture value)
            {
                var type = new Mock<IType>();
                type.SetupGet(t => t.FullName).Returns("Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute");
                var attribute = new Mock<IAttribute>();
                attribute.SetupGet(a => a.AttributeType).Returns(type.Object);
                attribute.SetupGet(a => a.FixedArguments).Returns(ImmutableArray.Create(
                    new CustomAttributeTypedArgument<IType>(SpecialType.UnknownType, (int)value)));
                yield return attribute.Object;
            }

            if (extra != null)
            {
                var type = new Mock<IType>();
                type.SetupGet(t => t.Name).Returns(extra);
                var attribute = new Mock<IAttribute>();
                attribute.SetupGet(a => a.AttributeType).Returns(type.Object);
                yield return attribute.Object;
            }
        }
    }
}

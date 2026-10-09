using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.Linq;
using System.Reflection.Metadata;
using ICSharpCode.Decompiler.TypeSystem;
using Moq;
using Xunit;

namespace MetadataUtils.Tests
{
    public class ArchitectureValidatorTests
    {
        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void SameNameVariantsUseOnlyTheirIntersectingLayouts(bool reverse)
        {
            var x86Leaf = Type("X86Leaf", Architecture.X86);
            var armLeaf = Type("ArmLeaf", Architecture.Arm64);
            var x86 = Type("Variant", Architecture.X86, x86Leaf.Object);
            var arm = Type("Variant", Architecture.Arm64, armLeaf.Object);
            var owner = Type("Owner", Architecture.X86 | Architecture.Arm64, arm.Object);
            var types = new[] { owner.Object, x86.Object, arm.Object, x86Leaf.Object, armLeaf.Object };

            Assert.Empty(ArchitectureValidator.FindMismatches(reverse ? types.Reverse() : types));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void MissingArchitectureIsStillRejected(bool pointer)
        {
            var x86 = Type("Target", Architecture.X86);
            IType reference = pointer ? new PointerType(x86.Object) : x86.Object;
            var owner = Type("Owner", Architecture.X64, reference);

            var diagnostic = Assert.Single(ArchitectureValidator.FindMismatches(new[] { owner.Object, x86.Object }));
            Assert.Equal("Test.Owner", diagnostic.Owner);
            Assert.Equal(Architecture.X64, diagnostic.Required);
            Assert.Equal(Architecture.X86, diagnostic.Supported);
        }

        [Fact]
        public void MixedPointerArrayWrappersStillCheckElementAvailability()
        {
            var target = Type("Target", Architecture.X86);
            var compilation = new Mock<ICompilation>().Object;
            target.SetupGet(t => t.Compilation).Returns(compilation);
            var array = new ArrayType(compilation, target.Object, 1, Nullability.Oblivious);
            var owner = Type("Owner", Architecture.X64, new PointerType(array));

            Assert.Single(ArchitectureValidator.FindMismatches(new[] { owner.Object, target.Object }));
        }

        [Fact]
        public void UnannotatedVariantStillSuppliesAllArchitectures()
        {
            var x86 = Type("Target", Architecture.X86);
            var all = Type("Target", null);
            var owner = Type("Owner", Architecture.Arm64, x86.Object);

            Assert.Empty(ArchitectureValidator.FindMismatches(new[] { owner.Object, x86.Object, all.Object }));
        }

        [Fact]
        public void UnionOfVariantsMustCoverEveryRequiredArchitecture()
        {
            var x86 = Type("Target", Architecture.X86);
            var x64 = Type("Target", Architecture.X64);
            var owner = Type("Owner", Architecture.All, x64.Object);

            var diagnostic = Assert.Single(ArchitectureValidator.FindMismatches(new[] { owner.Object, x86.Object, x64.Object }));
            Assert.Equal(Architecture.All, diagnostic.Required);
            Assert.Equal(Architecture.X86 | Architecture.X64, diagnostic.Supported);
        }

        [Fact]
        public void NestedVariantsInheritTheirContainingArchitecture()
        {
            var x86Leaf = Type("X86Leaf", Architecture.X86);
            var armLeaf = Type("ArmLeaf", Architecture.Arm64);
            var x86Nested = Type("Container.Nested", null, x86Leaf.Object);
            var armNested = Type("Container.Nested", null, armLeaf.Object);
            var x86 = Type("Container", Architecture.X86);
            var arm = Type("Container", Architecture.Arm64);
            x86.SetupGet(t => t.NestedTypes).Returns(new[] { x86Nested.Object });
            arm.SetupGet(t => t.NestedTypes).Returns(new[] { armNested.Object });
            var owner = Type("Owner", Architecture.X86 | Architecture.Arm64, armNested.Object);

            Assert.Empty(ArchitectureValidator.FindMismatches(new[] { owner.Object, x86.Object, arm.Object, x86Leaf.Object, armLeaf.Object }));
        }

        [Fact]
        public void PointerCyclesTerminateWithoutHidingMissingAvailability()
        {
            var leaf = Type("Leaf", Architecture.X86);
            var owner = Type("Owner", Architecture.X64);
            owner.SetupGet(t => t.Fields).Returns(new[] { Field(new PointerType(owner.Object)), Field(leaf.Object) });

            Assert.Single(ArchitectureValidator.FindMismatches(new[] { owner.Object, leaf.Object }));
        }

        [Fact]
        public void SharedDependencyIsCheckedForEachOwnersArchitecture()
        {
            var leaf = Type("Leaf", Architecture.X86);
            var shared = Type("Shared", null, leaf.Object);
            var x86 = Type("X86Owner", Architecture.X86, shared.Object);
            var x64 = Type("X64Owner", Architecture.X64, shared.Object);

            var diagnostic = Assert.Single(ArchitectureValidator.FindMismatches(new[] { x86.Object, x64.Object, shared.Object, leaf.Object }));
            Assert.Equal("Test.X64Owner", diagnostic.Owner);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void MethodParameterAndReturnFailuresAreNotDiscarded(bool returnValue)
        {
            var target = Type("Target", Architecture.X86);
            var apis = Type("Apis", null);
            apis.SetupGet(t => t.Kind).Returns(TypeKind.Class);
            var method = new Mock<IMethod>();
            method.SetupGet(m => m.Name).Returns("Method");
            method.SetupGet(m => m.FullName).Returns("Test.Apis.Method");
            method.SetupGet(m => m.IsStatic).Returns(true);
            method.Setup(m => m.GetAttributes()).Returns(Attributes(Architecture.X64));
            method.SetupGet(m => m.ReturnType).Returns(returnValue ? target.Object : SpecialType.UnknownType);
            var parameter = new Mock<IParameter>();
            parameter.SetupGet(p => p.Type).Returns(target.Object);
            method.SetupGet(m => m.Parameters).Returns(returnValue ? Array.Empty<IParameter>() : new[] { parameter.Object });
            apis.SetupGet(t => t.Methods).Returns(new[] { method.Object });

            var diagnostic = Assert.Single(ArchitectureValidator.FindMismatches(new[] { apis.Object, target.Object }));
            Assert.Equal("Test.Apis.Method", diagnostic.Owner);
        }

        [Fact]
        public void MemberArchitectureRestrictsItsRequiredClosure()
        {
            var target = Type("Target", Architecture.X86);
            var owner = Type("Owner", Architecture.All);
            owner.SetupGet(t => t.Fields).Returns(new[] { Field(target.Object, Architecture.X86) });

            Assert.Empty(ArchitectureValidator.FindMismatches(new[] { owner.Object, target.Object }));
        }

        [Fact]
        public void DelegateReturnAvailabilityIsChecked()
        {
            var target = Type("Target", Architecture.X86);
            var callback = Type("Callback", Architecture.X64);
            callback.SetupGet(t => t.Kind).Returns(TypeKind.Delegate);
            var invoke = new Mock<IMethod>();
            invoke.SetupGet(m => m.Name).Returns("Invoke");
            invoke.SetupGet(m => m.ReturnType).Returns(target.Object);
            invoke.SetupGet(m => m.Parameters).Returns(Array.Empty<IParameter>());
            callback.SetupGet(t => t.Methods).Returns(new[] { invoke.Object });

            var diagnostic = Assert.Single(ArchitectureValidator.FindMismatches(new[] { callback.Object, target.Object }));
            Assert.Equal("Test.Callback", diagnostic.Owner);
        }

        private static Mock<ITypeDefinition> Type(string name, Architecture? architecture, params IType[] fields)
        {
            var type = new Mock<ITypeDefinition>();
            type.SetupGet(t => t.Name).Returns(name);
            type.SetupGet(t => t.FullName).Returns("Test." + name);
            type.SetupGet(t => t.ReflectionName).Returns("Test." + name);
            type.SetupGet(t => t.Kind).Returns(TypeKind.Struct);
            type.Setup(t => t.GetDefinition()).Returns(type.Object);
            type.Setup(t => t.GetAttributes()).Returns(Attributes(architecture));
            type.SetupGet(t => t.Fields).Returns(fields.Select(f => Field(f)).ToArray());
            type.SetupGet(t => t.NestedTypes).Returns(Array.Empty<ITypeDefinition>());
            type.SetupGet(t => t.Methods).Returns(Array.Empty<IMethod>());
            return type;
        }

        private static IField Field(IType type, Architecture? architecture = null)
        {
            var field = new Mock<IField>();
            field.SetupGet(f => f.Type).Returns(type);
            field.Setup(f => f.GetAttributes()).Returns(Attributes(architecture));
            return field.Object;
        }

        private static IEnumerable<IAttribute> Attributes(Architecture? architecture)
        {
            if (architecture is not Architecture value)
            {
                return Array.Empty<IAttribute>();
            }

            var type = new Mock<IType>();
            type.SetupGet(t => t.FullName).Returns("Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute");
            var attribute = new Mock<IAttribute>();
            attribute.SetupGet(a => a.AttributeType).Returns(type.Object);
            attribute.SetupGet(a => a.FixedArguments).Returns(ImmutableArray.Create(
                new CustomAttributeTypedArgument<IType>(SpecialType.UnknownType, (int)value)));
            return new[] { attribute.Object };
        }
    }
}

using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
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
        public void CaseOnlySpellingsAreDistinctNativeNames()
        {
            var apis = Type("Test.Apis");
            Fields(apis, Field(apis, "value"), Field(apis, "VALUE"));

            Assert.Empty(ConstantValidator.FindDuplicates(new[] { apis.Object }));
        }

        [Fact]
        public void CaseSensitiveMediaSubtypeGuidsWithDifferentData1RemainSeparate()
        {
            Assert.Empty(Raw(f =>
            {
                f.Guid("Test", "MEDIASUBTYPE_M4S2", 0x3253344D);
                f.Guid("Test", "MEDIASUBTYPE_m4s2", 0x3273346D);
            }));
        }

        [Fact]
        public void TransparentEnumNamesWithDifferentDomainsAndValuesRemainSeparate()
        {
            Assert.Empty(Raw(f =>
            {
                f.Enum("Windows.Win32.Graphics.Gdi", "BackgroundMode", "TRANSPARENT", 1);
                f.Enum("Windows.Win32.Graphics.GdiPlus", "Color", "Transparent", 0x00FFFFFF);
            }));
        }

        [Fact]
        public void CompatibilityCaseAliasesRemainSeparateEvenWithEqualPayloads()
        {
            Assert.Empty(Raw(f =>
            {
                f.Apis("Test", "WHvRunVpCancelReasonUser", 0);
                f.Apis("Other", "WhvRunVpCancelReasonUser", 0);
            }));
        }

        [Theory]
        [InlineData(7u)]
        [InlineData(9u)]
        public void ExactGuidHolderAndFieldNamesStillCollideRegardlessOfPayload(uint fieldValue)
        {
            var duplicate = Assert.Single(Raw(f =>
            {
                f.Guid("First", "NativeGuid", 7);
                f.Apis("Second", "NativeGuid", fieldValue);
            }));
            Assert.Equal("NativeGuid", duplicate.Name);
            Assert.Equal(new[] { "First.NativeGuid", "Second.Apis" }, duplicate.Owners);
        }

        [Theory]
        [InlineData(7u)]
        [InlineData(9u)]
        public void ExactGuidNamesStillCollideRegardlessOfPayload(uint secondData1)
        {
            var duplicate = Assert.Single(Raw(f =>
            {
                f.Guid("First", "NativeGuid", 7);
                f.Guid("Second", "NativeGuid", secondData1);
            }));
            Assert.Equal("NativeGuid", duplicate.Name);
            Assert.Equal(new[] { "First.NativeGuid", "Second.NativeGuid" }, duplicate.Owners);
        }

        [Theory]
        [InlineData(false, 7u)]
        [InlineData(false, 9u)]
        [InlineData(true, 7u)]
        [InlineData(true, 9u)]
        public void ExactFieldNamesStillCollideAcrossEnumAndApisRegardlessOfPayload(bool enumeration, uint secondValue)
        {
            var duplicate = Assert.Single(Raw(f =>
            {
                if (enumeration)
                {
                    f.Enum("First", "Options", "NativeConstant", 7);
                }
                else
                {
                    f.Apis("First", "NativeConstant", 7);
                }

                f.Apis("Second", "NativeConstant", secondValue);
            }));
            Assert.Equal("NativeConstant", duplicate.Name);
            Assert.Equal(new[] { enumeration ? "First.Options" : "First.Apis", "Second.Apis" }, duplicate.Owners);
        }

        [Theory]
        [InlineData("en-US")]
        [InlineData("tr-TR")]
        public void IdentityAndDiagnosticSpellingAreOrdinalAndCultureIndependent(string culture)
        {
            var previous = CultureInfo.CurrentCulture;
            try
            {
                CultureInfo.CurrentCulture = CultureInfo.GetCultureInfo(culture);
                var apis = Type("Test.Apis");
                Fields(apis, Field(apis, "item"), Field(apis, "ITEM"), Field(apis, "item"));
                var duplicate = Assert.Single(ConstantValidator.FindDuplicates(new[] { apis.Object }));
                Assert.Equal("item", duplicate.Name);
                Assert.Equal(2, duplicate.Owners.Count);
            }
            finally
            {
                CultureInfo.CurrentCulture = previous;
            }
        }

        [Theory]
        [InlineData("NATIVE_CONSTANT", "NATIVE_CONSTANT", true)]
        [InlineData("NATIVE_CONSTANT", "native_constant", false)]
        [InlineData("NativeConstant", "NativeConstant", false)]
        [InlineData("NativeConstant", "NATIVECONSTANT", true)]
        [InlineData("NativeConstant", "nativeconstant", false)]
        public void AllowItemContractRetainsLegacyUppercaseKeysAndOrdinalTokens(string name, string allowItem, bool allowed)
        {
            var duplicate = Assert.Single(Raw(f =>
            {
                f.Apis("First", name, 7);
                f.Apis("Second", name, 9);
            }));
            Assert.Equal(name, duplicate.Name);
            InCulture("en-US", () => Assert.Equal(allowed ? 0 : 1,
                ApplyLegacyAllowances(new[] { duplicate }, allowItem).Count));
        }

        [Theory]
        [InlineData(null)]
        [InlineData("NATIVECONSTANT")]
        [InlineData("NativeConstant")]
        public void CaseDistinctSingletonsNeverBecomeDuplicatesWithOrWithoutAllowances(string allowItem)
        {
            var duplicates = Raw(f =>
            {
                f.Apis("First", "NativeConstant", 7);
                f.Apis("Second", "NATIVECONSTANT", 9);
            });
            Assert.Empty(duplicates);
            Assert.Empty(ApplyLegacyAllowances(duplicates, allowItem));
        }

        [Theory]
        [InlineData(null, 1)]
        [InlineData("NATIVECONSTANT", 0)]
        [InlineData("NativeConstant", 1)]
        public void MixedExactDuplicatesDoNotAbsorbTheCaseDistinctSingleton(string allowItem, int remaining)
        {
            var duplicates = Raw(f =>
            {
                f.Apis("First", "NativeConstant", 7);
                f.Apis("Second", "NativeConstant", 9);
                f.Apis("Singleton", "NATIVECONSTANT", 7);
            });
            var duplicate = Assert.Single(duplicates);
            Assert.Equal("NativeConstant", duplicate.Name);
            Assert.Equal(new[] { "First.Apis", "Second.Apis" }, duplicate.Owners);
            InCulture("en-US", () => Assert.Equal(remaining, ApplyLegacyAllowances(duplicates, allowItem).Count));
        }

        [Theory]
        [InlineData(null, 2)]
        [InlineData("NATIVECONSTANT", 0)]
        [InlineData("NativeConstant", 2)]
        public void CaseDistinctDuplicateGroupsRemainSeparateBeforeLegacyAllowanceLookup(string allowItem, int remaining)
        {
            var duplicates = Raw(f =>
            {
                f.Apis("First", "NativeConstant", 7);
                f.Apis("Second", "NativeConstant", 9);
                f.Apis("Third", "NATIVECONSTANT", 7);
                f.Apis("Fourth", "NATIVECONSTANT", 9);
            });
            Assert.Equal(new[] { "NativeConstant", "NATIVECONSTANT" }, duplicates.Select(d => d.Name));
            Assert.All(duplicates, duplicate => Assert.Equal(2, duplicate.Owners.Count));
            InCulture("en-US", () => Assert.Equal(remaining, ApplyLegacyAllowances(duplicates, allowItem).Count));
        }

        [Theory]
        [InlineData("en-US", "ITEM", true)]
        [InlineData("en-US", "\u0130TEM", false)]
        [InlineData("en-US", "item", false)]
        [InlineData("tr-TR", "ITEM", false)]
        [InlineData("tr-TR", "\u0130TEM", true)]
        [InlineData("tr-TR", "item", false)]
        public void LegacyAllowanceNormalizationUsesCurrentCultureWithoutChangingOrdinalIdentity(string culture, string allowItem, bool allowed)
        {
            var previous = CultureInfo.CurrentCulture;
            try
            {
                CultureInfo.CurrentCulture = CultureInfo.GetCultureInfo(culture);
                var duplicates = Raw(f =>
                {
                    f.Apis("First", "item", 7);
                    f.Apis("Second", "item", 9);
                    f.Apis("Singleton", "ITEM", 11);
                });
                var duplicate = Assert.Single(duplicates);
                Assert.Equal("item", duplicate.Name);
                Assert.Equal(new[] { "First.Apis", "Second.Apis" }, duplicate.Owners);
                Assert.Equal(allowed ? 0 : 1, ApplyLegacyAllowances(duplicates, allowItem).Count);
            }
            finally
            {
                CultureInfo.CurrentCulture = previous;
            }
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

        private static IReadOnlyList<DuplicateConstantDiagnostic> ApplyLegacyAllowances(
            IReadOnlyList<DuplicateConstantDiagnostic> duplicates, string allowItem)
        {
            // This is ShowDuplicateConstants' compatibility lookup, independent of identity.
            var allowTable = new HashSet<string>(allowItem == null ? Array.Empty<string>() : new[] { allowItem });
            return duplicates.Where(duplicate => !allowTable.Contains(duplicate.Name.ToUpper())).ToArray();
        }

        private static void InCulture(string culture, Action assert)
        {
            var previous = CultureInfo.CurrentCulture;
            try
            {
                CultureInfo.CurrentCulture = CultureInfo.GetCultureInfo(culture);
                assert();
            }
            finally
            {
                CultureInfo.CurrentCulture = previous;
            }
        }

        private static IReadOnlyList<DuplicateConstantDiagnostic> Raw(Action<ConstantImage> configure)
        {
            var fixture = new ConstantImage();
            configure(fixture);
            var image = new BlobBuilder();
            new ManagedPEBuilder(
                new PEHeaderBuilder(imageCharacteristics: Characteristics.ExecutableImage | Characteristics.Dll),
                new MetadataRootBuilder(fixture.Metadata), new BlobBuilder(), flags: CorFlags.ILOnly).Serialize(image);
            string path = Path.GetFullPath($"constant-identity-{Guid.NewGuid():N}.winmd");
            try
            {
                File.WriteAllBytes(path, image.ToArray());
                var system = DecompilerTypeSystemUtils.CreateTypeSystemFromFile(path);
                using (system.MainModule.PEFile)
                {
                    return ConstantValidator.FindDuplicates(system.MainModule.TopLevelTypeDefinitions);
                }
            }
            finally
            {
                File.Delete(path);
            }
        }

        private sealed class ConstantImage
        {
            private readonly AssemblyReferenceHandle system;
            internal MetadataBuilder Metadata { get; } = new();

            internal ConstantImage()
            {
                Metadata.AddModule(0, Metadata.GetOrAddString("Fixture"), Metadata.GetOrAddGuid(System.Guid.NewGuid()), default, default);
                Metadata.AddAssembly(Metadata.GetOrAddString("Fixture"), new Version(1, 0), default, default, 0, AssemblyHashAlgorithm.None);
                system = Metadata.AddAssemblyReference(Metadata.GetOrAddString("System.Runtime"), new Version(10, 0), default, default, 0, default);
                Metadata.AddTypeDefinition(TypeAttributes.NotPublic, default, Metadata.GetOrAddString("<Module>"), default,
                    MetadataTokens.FieldDefinitionHandle(1), MetadataTokens.MethodDefinitionHandle(1));
            }

            internal void Apis(string ns, string name, uint value)
            {
                Type(ns, "Apis", "Object");
                Field(name, value);
            }

            internal void Enum(string ns, string name, string field, uint value)
            {
                var type = Type(ns, name, "Enum");
                Metadata.AddFieldDefinition(FieldAttributes.Public | FieldAttributes.SpecialName | FieldAttributes.RTSpecialName,
                    Metadata.GetOrAddString("value__"), Metadata.GetOrAddBlob(new byte[] { 6, 9 }));
                Field(field, value, type);
            }

            internal void Guid(string ns, string name, uint data1)
            {
                var type = Type(ns, name, "ValueType");
                var attribute = Metadata.AddTypeReference(system, Metadata.GetOrAddString("System.Runtime.InteropServices"),
                    Metadata.GetOrAddString("GuidAttribute"));
                var constructor = Metadata.AddMemberReference(attribute, Metadata.GetOrAddString(".ctor"),
                    Metadata.GetOrAddBlob(new byte[] { 0x20, 1, 1, 14 }));
                var value = new BlobBuilder();
                value.WriteUInt16(1);
                // Only Data1 is relevant to this fixture; the remaining GUID bytes are synthetic.
                value.WriteSerializedString($"{data1:x8}-0000-0000-0000-000000000000");
                value.WriteUInt16(0);
                Metadata.AddCustomAttribute(type, constructor, Metadata.GetOrAddBlob(value));
            }

            private TypeDefinitionHandle Type(string ns, string name, string baseName)
            {
                var baseType = Metadata.AddTypeReference(system, Metadata.GetOrAddString("System"), Metadata.GetOrAddString(baseName));
                return Metadata.AddTypeDefinition(TypeAttributes.Public | TypeAttributes.Sealed,
                    Metadata.GetOrAddString(ns), Metadata.GetOrAddString(name), baseType,
                    MetadataTokens.FieldDefinitionHandle(Metadata.GetRowCount(TableIndex.Field) + 1),
                    MetadataTokens.MethodDefinitionHandle(1));
            }

            private void Field(string name, uint value, TypeDefinitionHandle enumeration = default)
            {
                var signature = new BlobBuilder();
                var type = new BlobEncoder(signature).FieldSignature();
                if (enumeration.IsNil)
                {
                    type.UInt32();
                }
                else
                {
                    type.Type(enumeration, isValueType: true);
                }

                var field = Metadata.AddFieldDefinition(FieldAttributes.Public | FieldAttributes.Static | FieldAttributes.Literal | FieldAttributes.HasDefault,
                    Metadata.GetOrAddString(name), Metadata.GetOrAddBlob(signature));
                Metadata.AddConstant(field, value);
            }
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

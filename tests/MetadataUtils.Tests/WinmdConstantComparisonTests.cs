using System;
using System.Collections.Generic;
using System.Globalization;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using WinmdUtilsProgram;
using Xunit;

namespace MetadataUtils.Tests
{
    public class WinmdConstantComparisonTests
    {
        [Fact]
        public void SimultaneousTypeAndValueChangesReportEveryComponent()
        {
            using var first = new FieldImage(PrimitiveTypeCode.UInt32, 1u);
            using var second = new FieldImage(PrimitiveTypeCode.Int32, 2);
            var differences = Compare(first, second);

            Assert.Equal(4, differences.Count);
            Assert.Contains("VALUE...System.UInt32 => System.Int32", differences);
            Assert.Contains("VALUE : ConstantTypeCode...UInt32 => Int32", differences);
            Assert.Contains("VALUE : constant bytes...01000000 => 02000000", differences);
            Assert.Contains("winmd1: VALUE = 1, winmd2 = 2", differences);
        }

        [Fact]
        public void EqualRawBitsDoNotHideSignedInterpretationChanges()
        {
            using var first = new FieldImage(PrimitiveTypeCode.UInt32, uint.MaxValue);
            using var second = new FieldImage(PrimitiveTypeCode.Int32, -1);
            var differences = Compare(first, second);

            Assert.Equal(3, differences.Count);
            Assert.Contains("VALUE : ConstantTypeCode...UInt32 => Int32", differences);
            Assert.Contains("winmd1: VALUE = 4294967295, winmd2 = -1", differences);
            Assert.DoesNotContain(differences, item => item.Contains("constant bytes"));
        }

        [Fact]
        public void DeclaredTypeOnlyDoesNotManufactureStorageOrValueChanges()
        {
            using var first = new FieldImage(PrimitiveTypeCode.UInt32, 1);
            using var second = new FieldImage(PrimitiveTypeCode.Int32, 1);
            Assert.Equal(new[] { "VALUE...System.UInt32 => System.Int32" }, Compare(first, second));
        }

        [Fact]
        public void ValueOnlyKeepsTheUnchangedDeclaredType()
        {
            using var first = new FieldImage(PrimitiveTypeCode.Int32, 3);
            using var second = new FieldImage(PrimitiveTypeCode.Int32, 9);
            Assert.Equal(new[]
            {
                "VALUE : constant bytes...03000000 => 09000000",
                "winmd1: VALUE = 3, winmd2 = 9",
            }, Compare(first, second));
        }

        [Fact]
        public void StorageOnlyIsNotAValueDifference()
        {
            using var first = new FieldImage(PrimitiveTypeCode.Int32, 1);
            using var second = new FieldImage(PrimitiveTypeCode.Int32, 1u);
            Assert.Equal(new[] { "VALUE : ConstantTypeCode...Int32 => UInt32" }, Compare(first, second));
        }

        [Fact]
        public void IdenticalConstantsCoverEveryConstantTypeCodeIncludingNull()
        {
            object[] values =
            {
                true, 'A', (sbyte)-1, (byte)1, (short)-2, (ushort)2,
                -3, 3u, -4L, 4UL, 1.5f, 2.5d, "text", null,
            };
            foreach (object value in values)
            {
                using var first = new FieldImage(PrimitiveTypeCode.Object, value);
                using var second = new FieldImage(PrimitiveTypeCode.Object, value);
                Assert.Empty(Compare(first, second));
            }
        }

        [Fact]
        public void NullConstantIsNotTheStringNull()
        {
            using var first = new FieldImage(PrimitiveTypeCode.String, null);
            using var second = new FieldImage(PrimitiveTypeCode.String, "null");
            var differences = Compare(first, second);
            Assert.Contains("VALUE : ConstantTypeCode...NullReference => String", differences);
            Assert.Contains("winmd1: VALUE = null, winmd2 = \"null\"", differences);
        }

        [Fact]
        public void LiteralAndConstantPresenceAreSymmetric()
        {
            using var literal = new FieldImage(PrimitiveTypeCode.Int32, 1);
            using var ordinary = new FieldImage(PrimitiveTypeCode.Int32, null, literal: false, hasConstant: false);
            var forward = Compare(literal, ordinary);
            var reverse = Compare(ordinary, literal);
            Assert.Contains("VALUE : literal...True => False", forward);
            Assert.Contains("VALUE : Constant row...present => missing", forward);
            Assert.Contains("VALUE : literal...False => True", reverse);
            Assert.Contains("VALUE : Constant row...missing => present", reverse);
        }

        [Fact]
        public void MissingConstantRowsRemainExplicit()
        {
            using var first = new FieldImage(PrimitiveTypeCode.Int32, null, hasConstant: false);
            using var second = new FieldImage(PrimitiveTypeCode.Int32, null, hasConstant: false);
            Assert.Equal(new[]
            {
                "winmd1: VALUE is literal without a Constant row",
                "winmd2: VALUE is literal without a Constant row",
            }, Compare(first, second));
        }

        [Fact]
        public void NonliteralFieldDefaultsAreNotSkipped()
        {
            using var first = new FieldImage(PrimitiveTypeCode.Int32, 3, literal: false);
            using var second = new FieldImage(PrimitiveTypeCode.Int32, 9, literal: false);
            Assert.Contains("winmd1: VALUE = 3, winmd2 = 9", Compare(first, second));
        }

        [Fact]
        public void DecodedNumbersAreCultureInvariant()
        {
            var original = CultureInfo.CurrentCulture;
            try
            {
                CultureInfo.CurrentCulture = CultureInfo.GetCultureInfo("fr-FR");
                using var first = new FieldImage(PrimitiveTypeCode.Double, 1.5);
                using var second = new FieldImage(PrimitiveTypeCode.Double, 2.5);
                Assert.Contains("winmd1: VALUE = 1.5, winmd2 = 2.5", Compare(first, second));
            }
            finally
            {
                CultureInfo.CurrentCulture = original;
            }
        }

        private static List<string> Compare(FieldImage first, FieldImage second)
        {
            var differences = new List<string>();
            WinmdConstantComparison.Compare(
                "VALUE", first.DeclaredType, first.Reader, first.Field,
                second.DeclaredType, second.Reader, second.Field, differences.Add);
            return differences;
        }

        private sealed class FieldImage : IDisposable
        {
            private readonly MetadataReaderProvider provider;

            internal FieldImage(PrimitiveTypeCode declaredType, object value, bool literal = true, bool hasConstant = true)
            {
                var metadata = new MetadataBuilder();
                metadata.AddModule(0, metadata.GetOrAddString("Fixture"), default, default, default);
                var signature = new BlobBuilder();
                new BlobEncoder(signature).FieldSignature().PrimitiveType(declaredType);
                Field = metadata.AddFieldDefinition(
                    FieldAttributes.Public | FieldAttributes.Static | (literal ? FieldAttributes.Literal : 0) |
                    (hasConstant ? FieldAttributes.HasDefault : 0),
                    metadata.GetOrAddString("VALUE"), metadata.GetOrAddBlob(signature));
                if (hasConstant)
                    metadata.AddConstant(Field, value);
                var image = new BlobBuilder();
                new MetadataRootBuilder(metadata).Serialize(image, 0, 0);
                provider = MetadataReaderProvider.FromMetadataImage(image.ToImmutableArray());
                Reader = provider.GetMetadataReader(MetadataReaderOptions.None);
                DeclaredType = "System." + declaredType;
            }

            internal MetadataReader Reader { get; }
            internal FieldDefinitionHandle Field { get; }
            internal string DeclaredType { get; }
            public void Dispose() => provider.Dispose();
        }
    }
}

using System;
using System.Reflection;
using Xunit;

namespace MetadataUtils.Tests
{
    public class ConstantsScraperTests
    {
        [Theory]

        // No multicharacter literals = no change
        [InlineData(
            "0x3231564E, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x3231564E, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        [InlineData(
            "842094158, 0, 16, 128, 0, 0, 170, 0, 56, 155, 113",
            "842094158, 0, 16, 128, 0, 0, 170, 0, 56, 155, 113"
        )]
        [InlineData(
            "0x3231564E, 0, 16, 128, 0, 0, 0xaa, 0, 56, 155, 113",
            "0x3231564E, 0, 16, 128, 0, 0, 0xaa, 0, 56, 155, 113"
        )]

        // Multicharacter literals with varying amounts of leading/trailing space are
        // transformed into hexadecimal constants
        [InlineData(
            "'802P', 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x38303250, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        [InlineData(
            "'802P' , 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x38303250, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        [InlineData(
            "     '802P', 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x38303250, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        public void MyTestMethod(string actual, string expected)
        {
            // Arrange
            var implType = typeof(ConstantsScraper).GetNestedType("ConstantsScraperImpl", BindingFlags.NonPublic);
            var implInstance = Activator.CreateInstance(implType, true);
            var method = implType.GetMethod("GetCanonicalGuidConstantIntegerArgs", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.InvokeMethod);

            // Act
            actual = method.Invoke(implInstance, new object[] { actual }) as string;

            // Assert
            Assert.Equal(expected, actual);
        }
    }
}

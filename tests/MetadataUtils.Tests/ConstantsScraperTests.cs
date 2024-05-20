using System;
using System.Collections.Generic;
using System.IO.Abstractions.TestingHelpers;
using System.Reflection;
using Moq;
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
        public void GetCanonicalGuidConstantIntegerArgs_VariousGuidConstantForms_CanonicalFormReturned(string actual, string expected)
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

        [Theory]
        [InlineData("MAKEINTRESOURCE(19)", "[NativeTypeName(\"LPCWSTR\")]", "public const ushort TEST_RESOURCE = 19;")]
        [InlineData("MAKEINTRESOURCE(0)", "[NativeTypeName(\"LPCWSTR\")]", "public const ushort TEST_RESOURCE = 0;")]
        [InlineData("MAKEINTRESOURCE(-42)", "[NativeTypeName(\"LPCWSTR\")]", "public const ushort TEST_RESOURCE = unchecked((ushort) -42);")]
        [InlineData("MAKEINTRESOURCEA(1)", "[NativeTypeName(\"LPCSTR\")]", "public const ushort TEST_RESOURCE = 1;")]
        public void ScrapeConstantsFromTraversedFiles_MakeIntResourceConstantsPresent_UnsignedShortIntegersWritten(string actual, string expectedAttribute, string expectedConst)
        {
            // Arrange
            var mockFileSystem = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                {
                    @"C:\test.h",
                    new MockFileData(
                        @$"
                        /* test.h */
                        #define TEST_RESOURCE {actual}
                        @"
                    )
                }
            });
            var fileMap = new Dictionary<string, string>(new[] {
                new KeyValuePair<string, string>("test.h", "Test.Namespace.Win32")
            });

            // Act
            {
                using var scraper = new TestableConstantsScraper(mockFileSystem);
                scraper.ScrapeConstantsFromTraversedFiles(fileMap);
            }

            // Assert
            Assert.Collection(mockFileSystem.GetFile("output.txt").TextContents.Split("\n"),
                e => { },
                e => { /* namespace */ },
                e => { /* { */ },
                e => { /*   class */ },
                e => { /*   { */ },
                e => Assert.Equal(expectedAttribute, e.Trim()),
                e => Assert.Equal(expectedConst, e.Trim()),
                e => { },
                e => { /*   } */ },
                e => { /* } */ },
                e => { }
            );
        }

        private class TestableConstantsScraper : IDisposable
        {
            private readonly object _instance;
            private readonly System.Reflection.MethodInfo _scrapeConstantsFromTraversedFiles;
            private bool _disposed;

            public TestableConstantsScraper(MockFileSystem mockFileSystem)
            {
                var scraperImplType = typeof(ConstantsScraper).GetNestedType("ConstantsScraperImpl", BindingFlags.NonPublic);
                this._scrapeConstantsFromTraversedFiles = scraperImplType.GetMethod("ScrapeConstantsFromTraversedFiles", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.InvokeMethod);
                this._instance = Activator.CreateInstance(scraperImplType, true);

                var fileSystemProperty = scraperImplType.GetProperty("_fileSystem", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetProperty);
                fileSystemProperty.SetValue(this._instance, mockFileSystem);

                var scraperOutputDirField = scraperImplType.GetField("scraperOutputDir", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                scraperOutputDirField.SetValue(this._instance, @"C:\");

                var regexHelperField = scraperImplType.GetField("regexConstHelper", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                regexHelperField.SetValue(this._instance, Mock.Of<IRegexConstHelper>());

                var writtenConstants = new Dictionary<string, string>();
                var writtenConstantsField = scraperImplType.GetField("writtenConstants", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                writtenConstantsField.SetValue(this._instance, writtenConstants);

                var requiredNamespaces = new WildcardDictionary(new());
                var requiredNamespacesField = scraperImplType.GetField("requiredNamespaces", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                requiredNamespacesField.SetValue(this._instance, requiredNamespaces);

                var scannedNamesToNamespaces = new Dictionary<string, string>();
                var scannedNamesToNamespacesField = scraperImplType.GetField("scannedNamesToNamespaces", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                scannedNamesToNamespacesField.SetValue(this._instance, scannedNamesToNamespaces);

                var enumMemberNameToEnumObj = new Dictionary<string, List<EnumObject>>();
                var enumMemberNameToEnumObjField = scraperImplType.GetField("enumMemberNameToEnumObj", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                enumMemberNameToEnumObjField.SetValue(this._instance, enumMemberNameToEnumObj);

                var outputStream = mockFileSystem.File.OpenWrite("output.txt");
                var constantWriter = new ConstantWriter(outputStream, "Test.Namespace.Win32", "", new());
                var namespacesToConstantWriters = new Dictionary<string, IConstantWriter>()
                {
                    { "Test.Namespace.Win32", constantWriter }
                };
                var namespacesToConstantWritersField = scraperImplType.GetField("namespacesToConstantWriters", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                namespacesToConstantWritersField.SetValue(this._instance, namespacesToConstantWriters);
            }

            public void ScrapeConstantsFromTraversedFiles(Dictionary<string, string> fileMap)
            {
                this._scrapeConstantsFromTraversedFiles.Invoke(this._instance, new[] { fileMap });
            }

            protected virtual void Dispose(bool disposing)
            {
                if (!this._disposed)
                {
                    if (disposing)
                    {
                        ((IDisposable)this._instance).Dispose();
                    }

                    this._disposed = true;
                }
            }

            public void Dispose()
            {
                this.Dispose(disposing: true);
                GC.SuppressFinalize(this);
            }
        }
    }
}

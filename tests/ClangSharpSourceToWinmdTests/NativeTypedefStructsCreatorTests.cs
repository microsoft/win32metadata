using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class NativeTypedefStructsCreatorTests
    {
        [TestMethod]
        public void NativeTypedefStructsGenerator_DeclareHandle_PreservesVoidPointerAndInvalidValues()
        {
            var autoTypes = new[]
            {
                new AutoType
                {
                    Name = "TEST_HANDLE",
                    Namespace = "Test",
                    ValueType = "DECLARE_HANDLE",
                    InvalidHandleValues = new long[] { -1, 0 },
                },
            };
            using var stream = new MemoryStream();
            NativeTypedefStructsCreator.WriteToStream(new(), autoTypes, stream);
            AssertGeneratedStructStreamContainsAttributes(stream, new[]
            {
                "[NativeTypedef]",
                "public unsafe struct TEST_HANDLE",
                "public void* Value;",
                "[InvalidHandleValue(-1)]",
                "[InvalidHandleValue(0)]",
            });
        }

        [DataTestMethod]
        [DataRow("DECLARE_HANDLE", true)]
        [DataRow("void*", false)]
        [DataRow("IntPtr", false)]
        [DataRow("AllJoynHandle", false)]
        [DataRow("typedef struct NativeTag*", false)]
        public void NativeTypedefStructsGenerator_OnlyDeclareHandleInputsCarrySourceProof(string valueType, bool expected)
        {
            using var stream = new MemoryStream();
            NativeTypedefStructsCreator.WriteToStream(new(), new[]
            {
                new AutoType
                {
                    Name = "TEST_HANDLE",
                    Namespace = "Test",
                    ValueType = valueType,
                    NativeTypedef = true,
                    InvalidHandleValues = new long[] { 0 },
                },
            }, stream);
            var declaration = CSharpSyntaxTree.ParseText(Encoding.UTF8.GetString(stream.ToArray()))
                .GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            Assert.AreEqual(expected, NativeHandleSourceProvenance.TryRead(declaration, out var proof));
            if (expected)
            {
                Assert.AreEqual(NativeHandleSourceProvider.Retained, proof.Provider);
                Assert.AreEqual("DECLARE_HANDLE", proof.Kind);
                Assert.AreEqual("::TEST_HANDLE", proof.NativeAlias);
                Assert.AreEqual("TEST_HANDLE", proof.GeneratedAlias);
                Assert.AreEqual("void*", proof.StorageType);
            }
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void NativeTypedefStructsGenerator_AttachesProofToEachExactRetainedAlias(bool separateNamespaces)
        {
            using var stream = new MemoryStream();
            NativeTypedefStructsCreator.WriteToStream(new(), new[]
            {
                new AutoType
                {
                    Name = "FIRST_TOKEN",
                    Namespace = "First",
                    ValueType = "DECLARE_HANDLE",
                    InvalidHandleValues = new long[] { 0 },
                },
                new AutoType
                {
                    Name = "SECOND_TOKEN",
                    Namespace = separateNamespaces ? "Second" : "First",
                    ValueType = "DECLARE_HANDLE",
                    InvalidHandleValues = new long[] { 0 },
                },
            }, stream);
            var declarations = CSharpSyntaxTree.ParseText(Encoding.UTF8.GetString(stream.ToArray()))
                .GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>().ToArray();
            Assert.AreEqual(2, declarations.Length);
            foreach (var declaration in declarations)
            {
                Assert.IsTrue(NativeHandleSourceProvenance.TryRead(declaration, out var proof));
                Assert.AreEqual("::" + declaration.Identifier.ValueText, proof.NativeAlias);
                Assert.AreEqual(declaration.Identifier.ValueText, proof.GeneratedAlias);
            }
        }

        [TestMethod]
        public void NativeTypedefStructsGenerator_NegativeSingularInvalidHandleValue_ValidAttributeGenerated()
        {
            // Arrange
            var methodNameToNamespacesMap = new Dictionary<string, string>
            {
                { "FindVolumeClose", "Windows.Win32.Storage.FileSystem" },
            };

            var autoTypes = new AutoType[]
            {
                new AutoType { Name = "FindVolumeHandle", ValueType = "IntPtr", CloseApi = "FindVolumeClose", InvalidHandleValues = new long[] { -1 } }
            };

            using var stream = new MemoryStream();
            var expectedAttribute = "[InvalidHandleValue(-1)]";

            // Act
            NativeTypedefStructsCreator.WriteToStream(methodNameToNamespacesMap, autoTypes, stream);

            // Assert
            AssertGeneratedStructStreamContainsAttribute(stream, expectedAttribute);
        }

        [TestMethod]
        public void NativeTypedefStructsGenerator_ZeroSingularInvalidHandleValue_ValidAttributeGenerated()
        {
            // Arrange
            var methodNameToNamespacesMap = new Dictionary<string, string>
            {
                { "JET_INSTANCE", "Windows.Win32.Storage.StructuredStorage" },
            };

            var autoTypes = new AutoType[]
            {
                new AutoType { Name = "JET_INSTANCE", ValueType = "UIntPtr", Namespace = "Windows.Win32.Storage.StructuredStorage", InvalidHandleValues = new long[] { 0 } }
            };

            using var stream = new MemoryStream();
            var expectedAttribute = "[InvalidHandleValue(0)]";

            // Act
            NativeTypedefStructsCreator.WriteToStream(methodNameToNamespacesMap, autoTypes, stream);

            // Assert
            AssertGeneratedStructStreamContainsAttribute(stream, expectedAttribute);
        }

        [TestMethod]
        public void NativeTypedefStructsGenerator_PositiveSingularInvalidHandleValue_ValidAttributeGenerated()
        {
            // Arrange
            var methodNameToNamespacesMap = new Dictionary<string, string>
            {
                { "JET_INSTANCE", "Windows.Win32.Storage.StructuredStorage" },
            };

            var autoTypes = new AutoType[]
            {
                new AutoType { Name = "FAUX_HANDLE", ValueType = "IntPtr", Namespace = "Windows.Win32.Nonexistent", InvalidHandleValues = new long[] { 1 } }
            };

            using var stream = new MemoryStream();
            var expectedAttribute = "[InvalidHandleValue(1)]";

            // Act
            NativeTypedefStructsCreator.WriteToStream(methodNameToNamespacesMap, autoTypes, stream);

            // Assert
            AssertGeneratedStructStreamContainsAttribute(stream, expectedAttribute);
        }

        [TestMethod]
        public void NativeTypedefStructsGenerator_NegativeMultipleInvalidHandleValues_ValidAttributesGenerated()
        {
            // Arrange
            var methodNameToNamespacesMap = new Dictionary<string, string>
            {
                { "FindVolumeClose", "Windows.Win32.Storage.FileSystem" },
            };

            var autoTypes = new AutoType[]
            {
                new AutoType
                {
                    Name = "FindVolumeHandle",
                    ValueType = "IntPtr",
                    CloseApi = "FindVolumeClose",
                    InvalidHandleValues = new long[] { long.MinValue, -1 }
                }
            };

            using var stream = new MemoryStream();
            var expectedAttributes = new[] {
                "[InvalidHandleValue(-9223372036854775808)]",
                "[InvalidHandleValue(-1)]",
            };

            // Act
            NativeTypedefStructsCreator.WriteToStream(methodNameToNamespacesMap, autoTypes, stream);

            // Assert
            AssertGeneratedStructStreamContainsAttributes(stream, expectedAttributes);
        }

        [TestMethod]
        public void NativeTypedefStructsGenerator_ZeroMultipleInvalidHandleValues_ValidAttributesGenerated()
        {
            // Arrange
            var methodNameToNamespacesMap = new Dictionary<string, string>
            {
                { "JET_INSTANCE", "Windows.Win32.Storage.StructuredStorage" },
            };

            var autoTypes = new AutoType[]
            {
                new AutoType
                {
                    Name = "JET_INSTANCE",
                    ValueType = "UIntPtr",
                    Namespace = "Windows.Win32.Storage.StructuredStorage",
                    InvalidHandleValues = new long[] { 0, long.MaxValue }
                }
            };

            using var stream = new MemoryStream();
            var expectedAttributes = new[] {
                "[InvalidHandleValue(0)]",
                "[InvalidHandleValue(9223372036854775807)]",
            };

            // Act
            NativeTypedefStructsCreator.WriteToStream(methodNameToNamespacesMap, autoTypes, stream);

            // Assert
            AssertGeneratedStructStreamContainsAttributes(stream, expectedAttributes);
        }

        [TestMethod]
        public void NativeTypedefStructsGenerator_PositiveMultipleInvalidHandleValues_ValidAttributesGenerated()
        {
            // Arrange
            var methodNameToNamespacesMap = new Dictionary<string, string>
            {
                { "JET_INSTANCE", "Windows.Win32.Storage.StructuredStorage" },
            };

            var autoTypes = new AutoType[]
            {
                new AutoType
                {
                    Name = "FAUX_HANDLE",
                    ValueType = "IntPtr",
                    Namespace = "Windows.Win32.Nonexistent",
                    InvalidHandleValues = new long[] { long.MinValue, 0, long.MaxValue }
                }
            };

            using var stream = new MemoryStream();
            var expectedAttributes = new[] {
                "[InvalidHandleValue(-9223372036854775808)]",
                "[InvalidHandleValue(0)]",
                "[InvalidHandleValue(9223372036854775807)]",
            };

            // Act
            NativeTypedefStructsCreator.WriteToStream(methodNameToNamespacesMap, autoTypes, stream);

            // Assert
            AssertGeneratedStructStreamContainsAttributes(stream, expectedAttributes);
        }

        private static void AssertGeneratedStructStreamContainsAttributes(MemoryStream stream, IEnumerable<string> attributes)
        {
            foreach (var attribute in attributes)
            {
                AssertGeneratedStructStreamContainsAttribute(stream, attribute);
            }
        }

        private static void AssertGeneratedStructStreamContainsAttribute(MemoryStream stream, string attribute)
        {
            stream.Seek(0, SeekOrigin.Begin);
            var generatedStruct = Encoding.UTF8.GetString(stream.GetBuffer());
            Assert.IsTrue(generatedStruct.Contains(attribute));
        }
    }
}

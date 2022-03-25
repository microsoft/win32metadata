using System.Collections.Generic;
using System.IO;
using System.Text;
using ClangSharpSourceToWinmd;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class NativeTypedefStructsCreatorTests
    {
        [TestMethod]
        public void NativeTypedefStructsGenerator_PositiveInvalidHandleValue_ValidUnsignedLongGenerated()
        {
            // Arrange
            var methodNameToNamespacesMap = new Dictionary<string, string>
            {
                { "FindVolumeClose", "Windows.Win32.Storage.FileSystem" },
            };

            var autoTypes = new AutoType[]
            {
                new AutoType { Name = "FindVolumeHandle", ValueType = "IntPtr", CloseApi = "FindVolumeClose", InvalidHandleValue = 18446744073709551615 }
            };

            using var stream = new MemoryStream();
            var expectedAttribute = "[InvalidHandleValue(18446744073709551615)]";

            // Act
            NativeTypedefStructsCreator.WriteToStream(methodNameToNamespacesMap, autoTypes, stream);

            // Assert
            AssertGeneratedStructStreamContainsAttribute(stream, expectedAttribute);
        }

        [TestMethod]
        public void NativeTypedefStructsGenerator_ZeroInvalidHandleValue_ValidUnsignedLongGenerated()
        {
            // Arrange
            var methodNameToNamespacesMap = new Dictionary<string, string>
            {
                { "JET_INSTANCE", "Windows.Win32.Storage.StructuredStorage" },
            };

            var autoTypes = new AutoType[]
            {
                new AutoType { Name = "JET_INSTANCE", ValueType = "UIntPtr", Namespace = "Windows.Win32.Storage.StructuredStorage", InvalidHandleValue = 0 }
            };

            using var stream = new MemoryStream();
            var expectedAttribute = "[InvalidHandleValue(0)]";

            // Act
            NativeTypedefStructsCreator.WriteToStream(methodNameToNamespacesMap, autoTypes, stream);

            // Assert
            AssertGeneratedStructStreamContainsAttribute(stream, expectedAttribute);
        }

        private static void AssertGeneratedStructStreamContainsAttribute(MemoryStream stream, string attribute)
        {
            stream.Seek(0, SeekOrigin.Begin);
            var generatedStruct = Encoding.UTF8.GetString(stream.GetBuffer());
            Assert.IsTrue(generatedStruct.Contains(attribute));
        }
    }
}

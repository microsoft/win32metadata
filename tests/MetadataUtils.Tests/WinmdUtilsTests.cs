using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using Xunit;

namespace MetadataUtils.Tests
{
    public interface IBase { void A(); };
    public interface IFoo { void B(); }
    public interface IBar : IBase { void C(); }
    public interface IQux : IFoo, IBar { void D(); }
    public interface IInheritsFromOther : IRegexConstHelper { }

    public class WinmdUtilsTests
    {
        [Fact]
        public void GetTypes_MultipleInterfacesPresent_CorrectNumberOfMethodsReturned()
        {
            // Arrange

            // Act
            using var metadata = WinmdUtils.LoadFromFile(Assembly.GetExecutingAssembly().Location);
            var typeInfo = metadata.GetTypes(new List<WinmdUtils> { metadata }).First(t => t.Name == "IQux") as InterfaceInfo;

            // Assert
            Assert.Equal(4, typeInfo.ImplementedMethodCount);
        }

        [Fact]
        public void GetTypes_InterfaceHeirarchyNotPresent_CorrectNumberOfMethodsReturned()
        {
            // Arrange

            // Act
            using var metadata = WinmdUtils.LoadFromFile(Assembly.GetExecutingAssembly().Location);
            var typeInfo = metadata.GetTypes(new List<WinmdUtils> { metadata }).First(t => t.Name == "IFoo") as InterfaceInfo;

            // Assert
            Assert.Equal(1, typeInfo.ImplementedMethodCount);
        }

        [Fact]
        public void GetTypes_InterfaceHeirarchyPresent_CorrectNumberOfMethodsReturned()
        {
            // Arrange

            // Act
            using var metadata = WinmdUtils.LoadFromFile(Assembly.GetExecutingAssembly().Location);
            var typeInfo = metadata.GetTypes(new List<WinmdUtils> { metadata }).First(t => t.Name == "IBar") as InterfaceInfo;

            // Assert
            Assert.Equal(2, typeInfo.ImplementedMethodCount);
        }

        [Fact]
        public void GetTypes_InterfaceHeirarchyPresent_InheritFromOtherAssembly()
        {
            // Arrange

            // Act
            using var otherMetadata = WinmdUtils.LoadFromFile(typeof(IRegexConstHelper).Assembly.Location);
            using var metadata = WinmdUtils.LoadFromFile(Assembly.GetExecutingAssembly().Location);
            var typeInfo = metadata.GetTypes(new List<WinmdUtils> { metadata, otherMetadata }).First(t => t.Name == "IInheritsFromOther") as InterfaceInfo;

            // Assert
            Assert.Equal(typeof(IRegexConstHelper).GetMethods().Length, typeInfo.ImplementedMethodCount);
        }
    }
}

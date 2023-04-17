using System.Linq;
using System.Reflection;
using Xunit;

namespace MetadataUtils.Tests
{
    public interface IBase { void A(); };
    public interface IFoo { void B(); }
    public interface IBar : IBase { void C(); }
    public interface IQux : IFoo, IBar { void D(); }

    public class WinmdUtilsTests
    {
        [Fact]
        public void GetTypes_MultipleInterfacesPresent_CorrectNumberOfMethodsReturned()
        {
            // Arrange

            // Act
            using var metadata = WinmdUtils.LoadFromFile(Assembly.GetExecutingAssembly().Location);
            var typeInfo = metadata.GetTypes().First(t => t.Name == "IQux") as InterfaceInfo;

            // Assert
            Assert.Equal(4, typeInfo.ImplementedMethodCount);
        }

        [Fact]
        public void GetTypes_InterfaceHeirarchyNotPresent_CorrectNumberOfMethodsReturned()
        {
            // Arrange

            // Act
            using var metadata = WinmdUtils.LoadFromFile(Assembly.GetExecutingAssembly().Location);
            var typeInfo = metadata.GetTypes().First(t => t.Name == "IFoo") as InterfaceInfo;

            // Assert
            Assert.Equal(1, typeInfo.ImplementedMethodCount);
        }

        [Fact]
        public void GetTypes_InterfaceHeirarchyPresent_CorrectNumberOfMethodsReturned()
        {
            // Arrange

            // Act
            using var metadata = WinmdUtils.LoadFromFile(Assembly.GetExecutingAssembly().Location);
            var typeInfo = metadata.GetTypes().First(t => t.Name == "IBar") as InterfaceInfo;

            // Assert
            Assert.Equal(2, typeInfo.ImplementedMethodCount);
        }
    }
}

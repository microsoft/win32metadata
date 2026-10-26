using System.Linq;
using System.Reflection;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class HeaderAnnotationWinmdFixtureTests
    {
        [Fact]
        public void SharedHelperBaseDoesNotDeclareTests()
        {
            var helpers = typeof(HeaderAnnotationWinmdTests);
            Assert.True(helpers.IsAbstract);
            Assert.Empty(helpers.GetMethods(BindingFlags.Public | BindingFlags.NonPublic |
                BindingFlags.Instance | BindingFlags.Static | BindingFlags.DeclaredOnly)
                .Where(method => method.IsDefined(typeof(FactAttribute), inherit: true)));
        }
    }
}

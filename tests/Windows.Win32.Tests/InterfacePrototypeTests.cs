using Xunit;

namespace Windows.Win32.Tests
{
    public class InterfacePrototypeTests
    {
        [Theory]
        [InlineData("Windows.Foundation.HResult", "HResult", "HRESULT")]
        [InlineData("Windows.Win32.Foundation.HRESULT", "HRESULT", "HRESULT")]
        [InlineData("System.Exception", "Exception", "Exception")]
        [InlineData("Other.HResult", "HResult", "HResult")]
        [InlineData("Windows.Foundation.hresult", "hresult", "hresult")]
        [InlineData("Windows.Win32.System.SystemServices.PCWSTR", "PCWSTR", "PCWSTR")]
        [InlineData("Windows.Win32.System.SystemServices.PWSTR", "PWSTR", "PWSTR")]
        public void HresultDisplayUsesOnlyTheExactNativeIdentity(string fullName, string name, string expected)
        {
            Assert.Equal(expected, WinmdTestUtils.GetNativeTypeName(fullName, name));
        }
    }
}

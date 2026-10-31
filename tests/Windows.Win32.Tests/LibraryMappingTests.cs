using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using MetadataUtils;
using Xunit;

namespace Windows.Win32.Tests
{
    public class LibraryMappingTests
    {
        [Fact]
        public void WinHttpStatusCallbackKeepsItsNativeTypedef()
        {
            var typeSystem = DecompilerUtils.LoadDecompilerTypeSystem(TestCommon.TestUtils.Win32WinmdPath);
            var apis = DecompilerUtils.GetSelfDefinedWinmdToplevelTypes(typeSystem)
                .Single(type => type.FullName == "Windows.Win32.Networking.WinHttp.Apis");
            var method = apis.Methods.Single(method => method.Name == "WinHttpSetStatusCallback");

            Assert.Equal("WINHTTP_STATUS_CALLBACK", method.ReturnType.Name);
            Assert.Equal("WINHTTP_STATUS_CALLBACK", method.Parameters[1].Type.Name);
        }

        [Theory]
        [InlineData("Windows.Win32.Security.Authentication.WebAuthn", "WebAuthNPluginAddAuthenticator2", "webauthn.dll")]
        [InlineData("Windows.Win32.Security.Authentication.WebAuthn", "WebAuthNPluginUpdateAuthenticatorDetails2", "webauthn.dll")]
        [InlineData("Windows.Win32.Security.Authentication.WebAuthn", "WebAuthNPluginPerformUserVerification2", "webauthn.dll")]
        [InlineData("Windows.Win32.Devices.AllJoyn", "AllJoynCloseBusHandle", "MSAJApi.dll")]
        [InlineData("Windows.Win32.Devices.AllJoyn", "alljoyn_init", "MSAJApi.dll")]
        [InlineData("Windows.Win32.NetworkManagement.P2P", "PeerDistStartup", "PeerDist.dll")]
        [InlineData("Windows.Win32.Media.MediaFoundation", "OPMXboxEnableHDCP", "OPMXbox.dll")]
        [InlineData("Windows.Win32.Media.MediaFoundation", "OPMXboxGetHDCPStatus", "OPMXbox.dll")]
        [InlineData("Windows.Win32.Media.MediaFoundation", "OPMXboxGetHDCPStatusAndType", "OPMXbox.dll")]
        public void SdkApisHaveDllImports(string expectedNamespace, string methodName, string expectedDll)
        {
            using var stream = File.OpenRead(TestCommon.TestUtils.Win32WinmdPath);
            using var peReader = new PEReader(stream);
            var reader = peReader.GetMetadataReader();
            var method = reader.MethodDefinitions
                .Select(reader.GetMethodDefinition)
                .Single(method => reader.StringComparer.Equals(method.Name, methodName));
            var declaringType = reader.GetTypeDefinition(method.GetDeclaringType());
            Assert.Equal(expectedNamespace, reader.GetString(declaringType.Namespace));

            var import = method.GetImport();
            Assert.False(import.Module.IsNil);
            Assert.Equal(methodName, reader.GetString(import.Name));
            Assert.Equal(expectedDll, reader.GetString(reader.GetModuleReference(import.Module).Name));
        }

        [Fact]
        public void RemovedPeerGroupSdkApiIsNotRestored()
        {
            using var stream = File.OpenRead(TestCommon.TestUtils.Win32WinmdPath);
            using var peReader = new PEReader(stream);
            var reader = peReader.GetMetadataReader();

            Assert.DoesNotContain(reader.MethodDefinitions.Select(reader.GetMethodDefinition),
                method => reader.StringComparer.Equals(method.Name, "PeerGroupStartup"));
        }
    }
}

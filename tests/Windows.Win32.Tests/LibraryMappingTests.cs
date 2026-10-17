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
        [InlineData("WebAuthNPluginAddAuthenticator2")]
        [InlineData("WebAuthNPluginUpdateAuthenticatorDetails2")]
        [InlineData("WebAuthNPluginPerformUserVerification2")]
        public void WebAuthnPluginVersion2ApisHaveDllImports(string methodName)
        {
            using var stream = File.OpenRead(TestCommon.TestUtils.Win32WinmdPath);
            using var peReader = new PEReader(stream);
            var reader = peReader.GetMetadataReader();
            var method = reader.MethodDefinitions
                .Select(reader.GetMethodDefinition)
                .Single(method => reader.StringComparer.Equals(method.Name, methodName));
            var declaringType = reader.GetTypeDefinition(method.GetDeclaringType());
            Assert.Equal("Windows.Win32.Security.Authentication.WebAuthn", reader.GetString(declaringType.Namespace));

            var import = method.GetImport();
            Assert.False(import.Module.IsNil);
            Assert.Equal(methodName, reader.GetString(import.Name));
            Assert.Equal("webauthn.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));
        }
    }
}

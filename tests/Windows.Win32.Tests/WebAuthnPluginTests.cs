using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using Xunit;

namespace Windows.Win32.Tests
{
    public class WebAuthnPluginTests
    {
        [Theory]
        [InlineData(
            "WebAuthNPluginUpdateAuthenticatorDetails2",
            "WEBAUTHN_PLUGIN_UPDATE_AUTHENTICATOR_DETAILS_2",
            "pwszAuthenticatorName,pClsid,pClsidNew,pwszLightThemeLogoSvg,pwszDarkThemeLogoSvg,cbAuthenticatorInfo,pbAuthenticatorInfo,cSupportedRpIds,ppwszSupportedRpIds,pwszUserVerificationKeyName")]
        [InlineData(
            "WebAuthNPluginPerformUserVerification2",
            "WEBAUTHN_PLUGIN_USER_VERIFICATION_REQUEST_2",
            "hwnd,pGuidTransactionId,pwszUsername,pwszDisplayHint,cbBufferToSign,pbBufferToSign")]
        [InlineData(
            "WebAuthNPluginAddAuthenticator2",
            "WEBAUTHN_PLUGIN_ADD_AUTHENTICATOR_OPTIONS_2",
            "pwszAuthenticatorName,pClsid,pwszPluginRpId,pwszLightThemeLogoSvg,pwszDarkThemeLogoSvg,cbAuthenticatorInfo,pbAuthenticatorInfo,cSupportedRpIds,ppwszSupportedRpIds,pwszUserVerificationKeyName")]
        public void StablePluginApisHaveExpectedMetadata(string apiName, string optionsName, string expectedFields)
        {
            using var stream = File.OpenRead(TestCommon.TestUtils.Win32WinmdPath);
            using var peReader = new PEReader(stream);
            var metadata = peReader.GetMetadataReader();
            const string webAuthnNamespace = "Windows.Win32.Security.Authentication.WebAuthn";

            var webAuthnTypes = metadata.TypeDefinitions
                .Select(metadata.GetTypeDefinition)
                .Where(type => metadata.GetString(type.Namespace) == webAuthnNamespace)
                .ToArray();

            var options = Assert.Single(webAuthnTypes, type => metadata.GetString(type.Name) == optionsName);
            Assert.Equal(
                expectedFields.Split(','),
                options.GetFields().Select(field => metadata.GetString(metadata.GetFieldDefinition(field).Name)));

            var apis = Assert.Single(webAuthnTypes, type => metadata.GetString(type.Name) == "Apis");
            var method = Assert.Single(
                apis.GetMethods().Select(metadata.GetMethodDefinition),
                method => metadata.GetString(method.Name) == apiName);
            var import = method.GetImport();
            Assert.Equal(apiName, metadata.GetString(import.Name));
            Assert.Equal("webauthn.dll", metadata.GetString(metadata.GetModuleReference(import.Module).Name));
        }
    }
}

using System;
using Windows.Win32.Foundation;
using Windows.Win32.Interop;
using Windows.Win32.System.PropertiesSystem; // For PROPERTYKEY
using Windows.Win32.System.SystemServices;
using static Windows.Win32.Foundation.Apis; // Various constants
using static Windows.Win32.System.Diagnostics.Debug.WIN32_ERROR;
using static Windows.Win32.System.SystemServices.Apis; // Various constants
using static Windows.Win32.Media.Multimedia.Apis; // Various constants
using static Windows.Win32.Media.Audio.CoreAudio.Apis; // Various constants
using static Windows.Win32.Graphics.DirectShow.Apis; // Various constants
using static Windows.Win32.UI.WindowsAndMessaging.Apis; // For WM_USER
using static Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS; // For FILE_* constants
using static Windows.Win32.System.Diagnostics.Debug.FACILITY_CODE; // For MAKE_HRESULT constants


namespace Windows.Win32.Networking.WindowsWebServices
{
    public static partial class Apis
    {
        public const uint WEBAUTHN_API_VERSION_1 = 1;

        public const uint WEBAUTHN_API_VERSION_2 = 2;

        public const uint WEBAUTHN_RP_ENTITY_INFORMATION_CURRENT_VERSION = 1;

        public const uint WEBAUTHN_MAX_USER_ID_LENGTH = 64;

        public const uint WEBAUTHN_USER_ENTITY_INFORMATION_CURRENT_VERSION = 1;

        public const uint WEBAUTHN_CLIENT_DATA_CURRENT_VERSION = 1;

        public const int WEBAUTHN_COSE_ALGORITHM_ECDSA_P256_WITH_SHA256 = -7;

        public const int WEBAUTHN_COSE_ALGORITHM_ECDSA_P384_WITH_SHA384 = -35;

        public const int WEBAUTHN_COSE_ALGORITHM_ECDSA_P521_WITH_SHA512 = -36;

        public const int WEBAUTHN_COSE_ALGORITHM_RSASSA_PKCS1_V1_5_WITH_SHA256 = -257;

        public const int WEBAUTHN_COSE_ALGORITHM_RSASSA_PKCS1_V1_5_WITH_SHA384 = -258;

        public const int WEBAUTHN_COSE_ALGORITHM_RSASSA_PKCS1_V1_5_WITH_SHA512 = -259;

        public const int WEBAUTHN_COSE_ALGORITHM_RSA_PSS_WITH_SHA256 = -37;

        public const int WEBAUTHN_COSE_ALGORITHM_RSA_PSS_WITH_SHA384 = -38;

        public const int WEBAUTHN_COSE_ALGORITHM_RSA_PSS_WITH_SHA512 = -39;

        public const uint WEBAUTHN_COSE_CREDENTIAL_PARAMETER_CURRENT_VERSION = 1;

        public const uint WEBAUTHN_CREDENTIAL_CURRENT_VERSION = 1;

        public const uint WEBAUTHN_CTAP_TRANSPORT_USB = 0x00000001;

        public const uint WEBAUTHN_CTAP_TRANSPORT_NFC = 0x00000002;

        public const uint WEBAUTHN_CTAP_TRANSPORT_BLE = 0x00000004;

        public const uint WEBAUTHN_CTAP_TRANSPORT_TEST = 0x00000008;

        public const uint WEBAUTHN_CTAP_TRANSPORT_INTERNAL = 0x00000010;

        public const uint WEBAUTHN_CTAP_TRANSPORT_FLAGS_MASK = 0x0000001F;

        public const uint WEBAUTHN_CREDENTIAL_EX_CURRENT_VERSION = 1;

        public const uint WEBAUTHN_USER_VERIFICATION_ANY = 0;

        public const uint WEBAUTHN_USER_VERIFICATION_OPTIONAL = 1;

        public const uint WEBAUTHN_USER_VERIFICATION_OPTIONAL_WITH_CREDENTIAL_ID_LIST = 2;

        public const uint WEBAUTHN_USER_VERIFICATION_REQUIRED = 3;

        public const uint WEBAUTHN_AUTHENTICATOR_ATTACHMENT_ANY = 0;

        public const uint WEBAUTHN_AUTHENTICATOR_ATTACHMENT_PLATFORM = 1;

        public const uint WEBAUTHN_AUTHENTICATOR_ATTACHMENT_CROSS_PLATFORM = 2;

        public const uint WEBAUTHN_AUTHENTICATOR_ATTACHMENT_CROSS_PLATFORM_U2F_V2 = 3;

        public const uint WEBAUTHN_USER_VERIFICATION_REQUIREMENT_ANY = 0;

        public const uint WEBAUTHN_USER_VERIFICATION_REQUIREMENT_REQUIRED = 1;

        public const uint WEBAUTHN_USER_VERIFICATION_REQUIREMENT_PREFERRED = 2;

        public const uint WEBAUTHN_USER_VERIFICATION_REQUIREMENT_DISCOURAGED = 3;

        public const uint WEBAUTHN_ATTESTATION_CONVEYANCE_PREFERENCE_ANY = 0;

        public const uint WEBAUTHN_ATTESTATION_CONVEYANCE_PREFERENCE_NONE = 1;

        public const uint WEBAUTHN_ATTESTATION_CONVEYANCE_PREFERENCE_INDIRECT = 2;

        public const uint WEBAUTHN_ATTESTATION_CONVEYANCE_PREFERENCE_DIRECT = 3;

        public const uint WEBAUTHN_AUTHENTICATOR_MAKE_CREDENTIAL_OPTIONS_VERSION_1 = 1;

        public const uint WEBAUTHN_AUTHENTICATOR_MAKE_CREDENTIAL_OPTIONS_VERSION_2 = 2;

        public const uint WEBAUTHN_AUTHENTICATOR_MAKE_CREDENTIAL_OPTIONS_VERSION_3 = 3;

        public const uint WEBAUTHN_AUTHENTICATOR_GET_ASSERTION_OPTIONS_VERSION_1 = 1;

        public const uint WEBAUTHN_AUTHENTICATOR_GET_ASSERTION_OPTIONS_VERSION_2 = 2;

        public const uint WEBAUTHN_AUTHENTICATOR_GET_ASSERTION_OPTIONS_VERSION_3 = 3;

        public const uint WEBAUTHN_AUTHENTICATOR_GET_ASSERTION_OPTIONS_VERSION_4 = 4;

        public const uint WEBAUTHN_ATTESTATION_DECODE_NONE = 0;

        public const uint WEBAUTHN_ATTESTATION_DECODE_COMMON = 1;

        public const uint WEBAUTHN_COMMON_ATTESTATION_CURRENT_VERSION = 1;

        public const uint WEBAUTHN_CREDENTIAL_ATTESTATION_VERSION_1 = 1;

        public const uint WEBAUTHN_CREDENTIAL_ATTESTATION_VERSION_2 = 2;

        public const uint WEBAUTHN_CREDENTIAL_ATTESTATION_VERSION_3 = 3;

        public const uint WEBAUTHN_ASSERTION_CURRENT_VERSION = 1;

    }
}

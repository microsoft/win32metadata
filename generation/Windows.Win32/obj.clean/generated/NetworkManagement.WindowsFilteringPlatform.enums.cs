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


using static Windows.Win32.NetworkManagement.WindowsFilteringPlatform.Apis;

namespace Windows.Win32.NetworkManagement.WindowsFilteringPlatform
{
    [Flags]
    public enum IPSEC_SA_BUNDLE_FLAGS : uint
    {
        IPSEC_SA_BUNDLE_FLAG_ND_SECURE = 0x00000001,
        IPSEC_SA_BUNDLE_FLAG_ND_BOUNDARY = 0x00000002,
        IPSEC_SA_BUNDLE_FLAG_ND_PEER_NAT_BOUNDARY = 0x00000004,
        IPSEC_SA_BUNDLE_FLAG_GUARANTEE_ENCRYPTION = 0x00000008,
        IPSEC_SA_BUNDLE_FLAG_ALLOW_NULL_TARGET_NAME_MATCH = 0x00000200,
        IPSEC_SA_BUNDLE_FLAG_CLEAR_DF_ON_TUNNEL = 0x00000400,
        IPSEC_SA_BUNDLE_FLAG_ASSUME_UDP_CONTEXT_OUTBOUND = 0x00000800,
        IPSEC_SA_BUNDLE_FLAG_ND_PEER_BOUNDARY = 0x00001000,
        IPSEC_SA_BUNDLE_FLAG_SUPPRESS_DUPLICATE_DELETION = 0x00002000,
        IPSEC_SA_BUNDLE_FLAG_PEER_SUPPORTS_GUARANTEE_ENCRYPTION = 0x00004000,
    }

    [Flags]
    public enum IPSEC_POLICY_FLAG : uint
    {
        IPSEC_POLICY_FLAG_ND_SECURE = 0x00000002,
        IPSEC_POLICY_FLAG_ND_BOUNDARY = 0x00000004,
        IPSEC_POLICY_FLAG_NAT_ENCAP_ALLOW_PEER_BEHIND_NAT = 0x00000010,
        IPSEC_POLICY_FLAG_NAT_ENCAP_ALLOW_GENERAL_NAT_TRAVERSAL = 0x00000020,
        IPSEC_POLICY_FLAG_DONT_NEGOTIATE_SECOND_LIFETIME = 0x00000040,
        IPSEC_POLICY_FLAG_DONT_NEGOTIATE_BYTE_LIFETIME = 0x00000080,
        IPSEC_POLICY_FLAG_CLEAR_DF_ON_TUNNEL = 0x00000008,
        IPSEC_POLICY_FLAG_ENABLE_V6_IN_V4_TUNNELING = 0x00000100,
        IPSEC_POLICY_FLAG_ENABLE_SERVER_ADDR_ASSIGNMENT = 0x00000200,
        IPSEC_POLICY_FLAG_TUNNEL_ALLOW_OUTBOUND_CLEAR_CONNECTION = 0x00000400,
        IPSEC_POLICY_FLAG_TUNNEL_BYPASS_ALREADY_SECURE_CONNECTION = 0x00000800,
        IPSEC_POLICY_FLAG_TUNNEL_BYPASS_ICMPV6 = 0x00001000,
        IPSEC_POLICY_FLAG_KEY_MANAGER_ALLOW_DICTATE_KEY = 0x00002000,
    }

    [Flags]
    public enum IKEEXT_CERT_AUTH : uint
    {
        IKEEXT_CERT_AUTH_FLAG_SSL_ONE_WAY = 0x00000001,
        IKEEXT_CERT_AUTH_ENABLE_CRL_CHECK_STRONG = 0x00000004,
        IKEEXT_CERT_AUTH_DISABLE_SSL_CERT_VALIDATION = 0x00000008,
        IKEEXT_CERT_AUTH_ALLOW_HTTP_CERT_LOOKUP = 0x00000010,
        IKEEXT_CERT_AUTH_URL_CONTAINS_BUNDLE = 0x00000020,
    }

    [Flags]
    public enum IKEEXT_PRESHARED_KEY_AUTHENTICATION_FLAGS : uint
    {
        IKEEXT_PSK_FLAG_LOCAL_AUTH_ONLY = 0x00000001,
        IKEEXT_PSK_FLAG_REMOTE_AUTH_ONLY = 0x00000002,
    }

    [Flags]
    public enum IKEEXT_POLICY_FLAG : uint
    {
        IKEEXT_POLICY_FLAG_DISABLE_DIAGNOSTICS = 0x00000001,
        IKEEXT_POLICY_FLAG_NO_MACHINE_LUID_VERIFY = 0x00000002,
        IKEEXT_POLICY_FLAG_NO_IMPERSONATION_LUID_VERIFY = 0x00000004,
        IKEEXT_POLICY_FLAG_ENABLE_OPTIONAL_DH = 0x00000008,
    }

    public enum FWPM_SUBSCRIPTION_FLAGS : uint
    {
        FWPM_SUBSCRIPTION_FLAG_NOTIFY_ON_ADD = 0x00000001,
        FWPM_SUBSCRIPTION_FLAG_NOTIFY_ON_DELETE = 0x00000002,
    }

    [Flags]
    public enum IKEEXT_CERT_FLAGS : uint
    {
        IKEEXT_CERT_FLAG_ENABLE_ACCOUNT_MAPPING = 0x00000001,
        IKEEXT_CERT_FLAG_DISABLE_REQUEST_PAYLOAD = 0x00000002,
        IKEEXT_CERT_FLAG_USE_NAP_CERTIFICATE = 0x00000004,
        IKEEXT_CERT_FLAG_INTERMEDIATE_CA = 0x00000008,
        IKEEXT_CERT_FLAG_IGNORE_INIT_CERT_MAP_FAILURE = 0x00000010,
        IKEEXT_CERT_FLAG_PREFER_NAP_CERTIFICATE_OUTBOUND = 0x00000020,
        IKEEXT_CERT_FLAG_SELECT_NAP_CERTIFICATE = 0x00000040,
        IKEEXT_CERT_FLAG_VERIFY_NAP_CERTIFICATE = 0x00000080,
        IKEEXT_CERT_FLAG_FOLLOW_RENEWAL_CERTIFICATE = 0x00000100,
    }

    [Flags]
    public enum IPSEC_DOSP_FLAGS : uint
    {
        IPSEC_DOSP_FLAG_ENABLE_IKEV1 = 0x00000001,
        IPSEC_DOSP_FLAG_ENABLE_IKEV2 = 0x00000002,
        IPSEC_DOSP_FLAG_DISABLE_AUTHIP = 0x00000004,
        IPSEC_DOSP_FLAG_DISABLE_DEFAULT_BLOCK = 0x00000008,
        IPSEC_DOSP_FLAG_FILTER_BLOCK = 0x00000010,
        IPSEC_DOSP_FLAG_FILTER_EXEMPT = 0x00000020,
    }

    [Flags]
    public enum IKEEXT_KERBEROS_AUTHENTICATION_FLAGS : uint
    {
        IKEEXT_KERB_AUTH_DISABLE_INITIATOR_TOKEN_GENERATION = 0x00000001,
        IKEEXT_KERB_AUTH_DONT_ACCEPT_EXPLICIT_CREDENTIALS = 0x00000002,
    }

    [Flags]
    public enum IKEEXT_RESERVED_AUTHENTICATION_FLAGS : uint
    {
        IKEEXT_RESERVED_AUTH_DISABLE_INITIATOR_TOKEN_GENERATION = 0x00000001,
    }

    [Flags]
    public enum IKEEXT_EAP_AUTHENTICATION_FLAGS : uint
    {
        IKEEXT_EAP_FLAG_LOCAL_AUTH_ONLY = 0x00000001,
        IKEEXT_EAP_FLAG_REMOTE_AUTH_ONLY = 0x00000002,
    }

    [Flags]
    public enum FWPM_FILTER_FLAGS : uint
    {
        FWPM_FILTER_FLAG_NONE = 0x00000000,
        FWPM_FILTER_FLAG_PERSISTENT = 0x00000001,
        FWPM_FILTER_FLAG_BOOTTIME = 0x00000002,
        FWPM_FILTER_FLAG_HAS_PROVIDER_CONTEXT = 0x00000004,
        FWPM_FILTER_FLAG_CLEAR_ACTION_RIGHT = 0x00000008,
        FWPM_FILTER_FLAG_PERMIT_IF_CALLOUT_UNREGISTERED = 0x00000010,
        FWPM_FILTER_FLAG_DISABLED = 0x00000020,
        FWPM_FILTER_FLAG_INDEXED = 0x00000040,
    }

}
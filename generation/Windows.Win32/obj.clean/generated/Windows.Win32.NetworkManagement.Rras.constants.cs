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


namespace Windows.Win32.NetworkManagement.Rras
{
    public static partial class Apis
    {
        public const uint RASNAP_ProbationTime = 0x00000001;

        public const uint RASTUNNELENDPOINT_UNKNOWN = 0;

        public const uint RASTUNNELENDPOINT_IPv4 = 1;

        public const uint RASTUNNELENDPOINT_IPv6 = 2;

        public const uint RAS_MaxDeviceType = 16;

        public const uint RAS_MaxPhoneNumber = 128;

        public const uint RAS_MaxIpAddress = 15;

        public const uint RAS_MaxIpxAddress = 21;

        public const uint RAS_MaxEntryName = 256;

        public const uint RAS_MaxDeviceName = 128;

        public const uint RAS_MaxCallbackNumber = 48;

        public const uint RAS_MaxAreaCode = 10;

        public const uint RAS_MaxPadType = 32;

        public const uint RAS_MaxX25Address = 200;

        public const uint RAS_MaxFacilities = 200;

        public const uint RAS_MaxUserData = 200;

        public const uint RAS_MaxReplyMessage = 1024;

        public const uint RAS_MaxDnsSuffix = 256;

        public const uint RASCF_AllUsers = 0x00000001;

        public const uint RASCF_GlobalCreds = 0x00000002;

        public const uint RASCF_OwnerKnown = 0x00000004;

        public const uint RASCF_OwnerMatch = 0x00000008;

        public const uint RAS_MaxIDSize = 256;

        public const uint RASCS_PAUSED = 0x1000;

        public const uint RASCS_DONE = 0x2000;

        public const uint RASCSS_DONE = 0x2000;

        public const uint RDEOPT_UsePrefixSuffix = 0x00000001;

        public const uint RDEOPT_PausedStates = 0x00000002;

        public const uint RDEOPT_IgnoreModemSpeaker = 0x00000004;

        public const uint RDEOPT_SetModemSpeaker = 0x00000008;

        public const uint RDEOPT_IgnoreSoftwareCompression = 0x00000010;

        public const uint RDEOPT_SetSoftwareCompression = 0x00000020;

        public const uint RDEOPT_DisableConnectedUI = 0x00000040;

        public const uint RDEOPT_DisableReconnectUI = 0x00000080;

        public const uint RDEOPT_DisableReconnect = 0x00000100;

        public const uint RDEOPT_NoUser = 0x00000200;

        public const uint RDEOPT_PauseOnScript = 0x00000400;

        public const uint RDEOPT_Router = 0x00000800;

        public const uint RDEOPT_CustomDial = 0x00001000;

        public const uint RDEOPT_UseCustomScripting = 0x00002000;

        public const uint RDEOPT_InvokeAutoTriggerCredentialUI = 0x00004000;

        public const uint RDEOPT_EapInfoCryptInCapable = 0x00008000;

        public const uint REN_User = 0x00000000;

        public const uint REN_AllUsers = 0x00000001;

        public const uint RASIPO_VJ = 0x00000001;

        public const uint RASLCPO_PFC = 0x00000001;

        public const uint RASLCPO_ACFC = 0x00000002;

        public const uint RASLCPO_SSHF = 0x00000004;

        public const uint RASLCPO_DES_56 = 0x00000008;

        public const uint RASLCPO_3_DES = 0x00000010;

        public const uint RASLCPO_AES_128 = 0x00000020;

        public const uint RASLCPO_AES_256 = 0x00000040;

        public const uint RASLCPO_AES_192 = 0x00000080;

        public const uint RASLCPO_GCM_AES_128 = 0x00000100;

        public const uint RASLCPO_GCM_AES_192 = 0x00000200;

        public const uint RASLCPO_GCM_AES_256 = 0x00000400;

        public const uint RASCCPCA_MPPC = 0x00000006;

        public const uint RASCCPCA_STAC = 0x00000005;

        public const uint RASCCPO_Compression = 0x00000001;

        public const uint RASCCPO_HistoryLess = 0x00000002;

        public const uint RASCCPO_Encryption56bit = 0x00000010;

        public const uint RASCCPO_Encryption40bit = 0x00000020;

        public const uint RASCCPO_Encryption128bit = 0x00000040;

        public const uint RASIKEv2_AUTH_MACHINECERTIFICATES = 1;

        public const uint RASIKEv2_AUTH_EAP = 2;

        public const uint RASIKEv2_AUTH_PSK = 3;

        public const uint WM_RASDIALEVENT = 0xCCCD;

        public const uint ET_None = 0;

        public const uint ET_Require = 1;

        public const uint ET_RequireMax = 2;

        public const uint ET_Optional = 3;

        public const uint VS_Default = 0;

        public const uint VS_PptpOnly = 1;

        public const uint VS_PptpFirst = 2;

        public const uint VS_L2tpOnly = 3;

        public const uint VS_L2tpFirst = 4;

        public const uint VS_SstpOnly = 5;

        public const uint VS_SstpFirst = 6;

        public const uint VS_Ikev2Only = 7;

        public const uint VS_Ikev2First = 8;

        public const uint VS_GREOnly = 9;

        public const uint VS_PptpSstp = 12;

        public const uint VS_L2tpSstp = 13;

        public const uint VS_Ikev2Sstp = 14;

        public const uint RASEO_UseCountryAndAreaCodes = 0x00000001;

        public const uint RASEO_SpecificIpAddr = 0x00000002;

        public const uint RASEO_SpecificNameServers = 0x00000004;

        public const uint RASEO_IpHeaderCompression = 0x00000008;

        public const uint RASEO_RemoteDefaultGateway = 0x00000010;

        public const uint RASEO_DisableLcpExtensions = 0x00000020;

        public const uint RASEO_TerminalBeforeDial = 0x00000040;

        public const uint RASEO_TerminalAfterDial = 0x00000080;

        public const uint RASEO_ModemLights = 0x00000100;

        public const uint RASEO_SwCompression = 0x00000200;

        public const uint RASEO_RequireEncryptedPw = 0x00000400;

        public const uint RASEO_RequireMsEncryptedPw = 0x00000800;

        public const uint RASEO_RequireDataEncryption = 0x00001000;

        public const uint RASEO_NetworkLogon = 0x00002000;

        public const uint RASEO_UseLogonCredentials = 0x00004000;

        public const uint RASEO_PromoteAlternates = 0x00008000;

        public const uint RASEO_SecureLocalFiles = 0x00010000;

        public const uint RASEO_RequireEAP = 0x00020000;

        public const uint RASEO_RequirePAP = 0x00040000;

        public const uint RASEO_RequireSPAP = 0x00080000;

        public const uint RASEO_Custom = 0x00100000;

        public const uint RASEO_PreviewPhoneNumber = 0x00200000;

        public const uint RASEO_SharedPhoneNumbers = 0x00800000;

        public const uint RASEO_PreviewUserPw = 0x01000000;

        public const uint RASEO_PreviewDomain = 0x02000000;

        public const uint RASEO_ShowDialingProgress = 0x04000000;

        public const uint RASEO_RequireCHAP = 0x08000000;

        public const uint RASEO_RequireMsCHAP = 0x10000000;

        public const uint RASEO_RequireMsCHAP2 = 0x20000000;

        public const uint RASEO_RequireW95MSCHAP = 0x40000000;

        public const uint RASEO_CustomScript = 0x80000000;

        public const uint RASEO2_SecureFileAndPrint = 0x00000001;

        public const uint RASEO2_SecureClientForMSNet = 0x00000002;

        public const uint RASEO2_DontNegotiateMultilink = 0x00000004;

        public const uint RASEO2_DontUseRasCredentials = 0x00000008;

        public const uint RASEO2_UsePreSharedKey = 0x00000010;

        public const uint RASEO2_Internet = 0x00000020;

        public const uint RASEO2_DisableNbtOverIP = 0x00000040;

        public const uint RASEO2_UseGlobalDeviceSettings = 0x00000080;

        public const uint RASEO2_ReconnectIfDropped = 0x00000100;

        public const uint RASEO2_SharePhoneNumbers = 0x00000200;

        public const uint RASEO2_SecureRoutingCompartment = 0x00000400;

        public const uint RASEO2_UseTypicalSettings = 0x00000800;

        public const uint RASEO2_IPv6SpecificNameServers = 0x00001000;

        public const uint RASEO2_IPv6RemoteDefaultGateway = 0x00002000;

        public const uint RASEO2_RegisterIpWithDNS = 0x00004000;

        public const uint RASEO2_UseDNSSuffixForRegistration = 0x00008000;

        public const uint RASEO2_IPv4ExplicitMetric = 0x00010000;

        public const uint RASEO2_IPv6ExplicitMetric = 0x00020000;

        public const uint RASEO2_DisableIKENameEkuCheck = 0x00040000;

        public const uint RASEO2_DisableClassBasedStaticRoute = 0x00080000;

        public const uint RASEO2_SpecificIPv6Addr = 0x00100000;

        public const uint RASEO2_DisableMobility = 0x00200000;

        public const uint RASEO2_RequireMachineCertificates = 0x00400000;

        public const uint RASEO2_UsePreSharedKeyForIkev2Initiator = 0x00800000;

        public const uint RASEO2_UsePreSharedKeyForIkev2Responder = 0x01000000;

        public const uint RASEO2_CacheCredentials = 0x02000000;

        public const uint RASEO2_AutoTriggerCapable = 0x04000000;

        public const uint RASEO2_IsThirdPartyProfile = 0x08000000;

        public const uint RASEO2_AuthTypeIsOtp = 0x10000000;

        public const uint RASEO2_IsAlwaysOn = 0x20000000;

        public const uint RASEO2_IsPrivateNetwork = 0x40000000;

        public const uint RASEO2_PlumbIKEv2TSAsRoutes = 0x80000000;

        public const uint RASNP_NetBEUI = 0x00000001;

        public const uint RASNP_Ipx = 0x00000002;

        public const uint RASNP_Ip = 0x00000004;

        public const uint RASNP_Ipv6 = 0x00000008;

        public const uint RASFP_Ppp = 0x00000001;

        public const uint RASFP_Slip = 0x00000002;

        public const uint RASFP_Ras = 0x00000004;

        public const uint RASET_Phone = 1;

        public const uint RASET_Vpn = 2;

        public const uint RASET_Direct = 3;

        public const uint RASET_Internet = 4;

        public const uint RASET_Broadband = 5;

        public const uint RASCN_Connection = 0x00000001;

        public const uint RASCN_Disconnection = 0x00000002;

        public const uint RASCN_BandwidthAdded = 0x00000004;

        public const uint RASCN_BandwidthRemoved = 0x00000008;

        public const uint RASCN_Dormant = 0x00000010;

        public const uint RASCN_ReConnection = 0x00000020;

        public const uint RASCN_EPDGPacketArrival = 0x00000040;

        public const uint RASIDS_Disabled = 0xffffffff;

        public const uint RASIDS_UseGlobalValue = 0;

        public const uint RASADFLG_PositionDlg = 0x00000001;

        public const uint RASCM_UserName = 0x00000001;

        public const uint RASCM_Password = 0x00000002;

        public const uint RASCM_Domain = 0x00000004;

        public const uint RASCM_DefaultCreds = 0x00000008;

        public const uint RASCM_PreSharedKey = 0x00000010;

        public const uint RASCM_ServerPreSharedKey = 0x00000020;

        public const uint RASCM_DDMPreSharedKey = 0x00000040;

        public const uint RASADP_DisableConnectionQuery = 0;

        public const uint RASADP_LoginSessionDisable = 1;

        public const uint RASADP_SavedAddressesLimit = 2;

        public const uint RASADP_FailedConnectionTimeout = 3;

        public const uint RASADP_ConnectionQueryTimeout = 4;

        public const uint RASEAPF_NonInteractive = 0x00000002;

        public const uint RASEAPF_Logon = 0x00000004;

        public const uint RASEAPF_Preview = 0x00000008;

        public const uint RCD_SingleUser = 0;

        public const uint RCD_AllUsers = 0x00000001;

        public const uint RCD_Eap = 0x00000002;

        public const uint RCD_Logon = 0x00000004;

        public const uint RASPBDEVENT_AddEntry = 1;

        public const uint RASPBDEVENT_EditEntry = 2;

        public const uint RASPBDEVENT_RemoveEntry = 3;

        public const uint RASPBDEVENT_DialEntry = 4;

        public const uint RASPBDEVENT_EditGlobals = 5;

        public const uint RASPBDEVENT_NoUser = 6;

        public const uint RASPBDEVENT_NoUserEdit = 7;

        public const uint RASNOUSER_SmartCard = 0x00000001;

        public const uint RASPBDFLAG_PositionDlg = 0x00000001;

        public const uint RASPBDFLAG_ForceCloseOnDial = 0x00000002;

        public const uint RASPBDFLAG_NoUser = 0x00000010;

        public const uint RASPBDFLAG_UpdateDefaults = 0x80000000;

        public const uint RASEDFLAG_PositionDlg = 0x00000001;

        public const uint RASEDFLAG_NewEntry = 0x00000002;

        public const uint RASEDFLAG_CloneEntry = 0x00000004;

        public const uint RASEDFLAG_NoRename = 0x00000008;

        public const uint RASEDFLAG_ShellOwned = 0x40000000;

        public const uint RASEDFLAG_NewPhoneEntry = 0x00000010;

        public const uint RASEDFLAG_NewTunnelEntry = 0x00000020;

        public const uint RASEDFLAG_NewDirectEntry = 0x00000040;

        public const uint RASEDFLAG_NewBroadbandEntry = 0x00000080;

        public const uint RASEDFLAG_InternetEntry = 0x00000100;

        public const uint RASEDFLAG_NAT = 0x00000200;

        public const uint RASEDFLAG_IncomingConnection = 0x00000400;

        public const uint RASDDFLAG_PositionDlg = 0x00000001;

        public const uint RASDDFLAG_NoPrompt = 0x00000002;

        public const uint RASDDFLAG_AoacRedial = 0x00000004;

        public const uint RASDDFLAG_LinkFailure = 0x80000000;

        public const uint PID_IPX = 0x0000002B;

        public const uint PID_IP = 0x00000021;

        public const uint PID_IPV6 = 0x00000057;

        public const uint PID_NBF = 0x0000003F;

        public const uint PID_ATALK = 0x00000029;

        public const uint MPR_INTERFACE_OUT_OF_RESOURCES = 0x00000001;

        public const uint MPR_INTERFACE_ADMIN_DISABLED = 0x00000002;

        public const uint MPR_INTERFACE_CONNECTION_FAILURE = 0x00000004;

        public const uint MPR_INTERFACE_SERVICE_PAUSED = 0x00000008;

        public const uint MPR_INTERFACE_DIALOUT_HOURS_RESTRICTION = 0x00000010;

        public const uint MPR_INTERFACE_NO_MEDIA_SENSE = 0x00000020;

        public const uint MPR_INTERFACE_NO_DEVICE = 0x00000040;

        public const uint MPRIO_IpSecPreSharedKey = 0x80000000;

        public const uint MPRIO_RequireMachineCertificates = 0x01000000;

        public const uint MPRIO_UsePreSharedKeyForIkev2Initiator = 0x02000000;

        public const uint MPRIO_UsePreSharedKeyForIkev2Responder = 0x04000000;

        public const uint MPR_ENABLE_RAS_ON_DEVICE = 0x00000001;

        public const uint MPR_ENABLE_ROUTING_ON_DEVICE = 0x00000002;

        public const uint IPADDRESSLEN = 15;

        public const uint IPXADDRESSLEN = 22;

        public const uint ATADDRESSLEN = 32;

        public const uint MAXIPADRESSLEN = 64;

        public const uint PPP_IPCP_VJ = 0x00000001;

        public const uint PPP_CCP_COMPRESSION = 0x00000001;

        public const uint PPP_CCP_ENCRYPTION40BITOLD = 0x00000010;

        public const uint PPP_CCP_ENCRYPTION40BIT = 0x00000020;

        public const uint PPP_CCP_ENCRYPTION128BIT = 0x00000040;

        public const uint PPP_CCP_ENCRYPTION56BIT = 0x00000080;

        public const uint PPP_CCP_HISTORYLESS = 0x01000000;

        public const uint PPP_LCP_MULTILINK_FRAMING = 0x00000001;

        public const uint PPP_LCP_PFC = 0x00000002;

        public const uint PPP_LCP_ACFC = 0x00000004;

        public const uint PPP_LCP_SSHF = 0x00000008;

        public const uint PPP_LCP_DES_56 = 0x00000010;

        public const uint PPP_LCP_3_DES = 0x00000020;

        public const uint PPP_LCP_AES_128 = 0x00000040;

        public const uint PPP_LCP_AES_256 = 0x00000080;

        public const uint PPP_LCP_AES_192 = 0x00000100;

        public const uint PPP_LCP_GCM_AES_128 = 0x00000200;

        public const uint PPP_LCP_GCM_AES_192 = 0x00000400;

        public const uint PPP_LCP_GCM_AES_256 = 0x00000800;

        public const uint RAS_FLAGS_RAS_CONNECTION = 0x00000004;

        public const uint RASPRIV_NoCallback = 0x01;

        public const uint RASPRIV_AdminSetCallback = 0x02;

        public const uint RASPRIV_CallerSetCallback = 0x04;

        public const uint RASPRIV_DialinPrivilege = 0x08;

        public const uint RASPRIV2_DialinPolicy = 0x1;

        public const uint MPRAPI_IKEV2_AUTH_USING_CERT = 1;

        public const uint MPRAPI_IKEV2_AUTH_USING_EAP = 2;

        public const uint MPRAPI_PPP_PROJECTION_INFO_TYPE = 1;

        public const uint MPRAPI_IKEV2_PROJECTION_INFO_TYPE = 2;

        public const uint MPRAPI_RAS_CONNECTION_OBJECT_REVISION_1 = 0x1;

        public const uint MPRAPI_MPR_IF_CUSTOM_CONFIG_OBJECT_REVISION_1 = 0x1;

        public const uint MPRAPI_IF_CUSTOM_CONFIG_FOR_IKEV2 = 0x1;

        public const uint MPRAPI_MPR_IF_CUSTOM_CONFIG_OBJECT_REVISION_3 = 0x3;

        public const uint MPRAPI_MPR_IF_CUSTOM_CONFIG_OBJECT_REVISION_2 = 0x2;

        public const uint MPRAPI_IKEV2_SET_TUNNEL_CONFIG_PARAMS = 0x1;

        public const uint MPRAPI_L2TP_SET_TUNNEL_CONFIG_PARAMS = 0x1;

        public const uint MAX_SSTP_HASH_SIZE = 32;

        public const uint MPRAPI_MPR_SERVER_OBJECT_REVISION_1 = 0x1;

        public const uint MPRAPI_MPR_SERVER_OBJECT_REVISION_2 = 0x2;

        public const uint MPRAPI_MPR_SERVER_OBJECT_REVISION_3 = 0x3;

        public const uint MPRAPI_MPR_SERVER_OBJECT_REVISION_4 = 0x4;

        public const uint MPRAPI_MPR_SERVER_OBJECT_REVISION_5 = 0x5;

        public const uint MPRAPI_MPR_SERVER_SET_CONFIG_OBJECT_REVISION_1 = 0x1;

        public const uint MPRAPI_MPR_SERVER_SET_CONFIG_OBJECT_REVISION_2 = 0x2;

        public const uint MPRAPI_MPR_SERVER_SET_CONFIG_OBJECT_REVISION_3 = 0x3;

        public const uint MPRAPI_MPR_SERVER_SET_CONFIG_OBJECT_REVISION_4 = 0x4;

        public const uint MPRAPI_MPR_SERVER_SET_CONFIG_OBJECT_REVISION_5 = 0x5;

        public const uint MPRAPI_SET_CONFIG_PROTOCOL_FOR_PPTP = 0x1;

        public const uint MPRAPI_SET_CONFIG_PROTOCOL_FOR_L2TP = 0x2;

        public const uint MPRAPI_SET_CONFIG_PROTOCOL_FOR_SSTP = 0x4;

        public const uint MPRAPI_SET_CONFIG_PROTOCOL_FOR_IKEV2 = 0x8;

        public const uint MPRAPI_SET_CONFIG_PROTOCOL_FOR_GRE = 0x10;

        public const uint ALLOW_NO_AUTH = 1;

        public const uint DO_NOT_ALLOW_NO_AUTH = 0;

        public const uint MPRAPI_RAS_UPDATE_CONNECTION_OBJECT_REVISION_1 = 0x1;

        public const uint MPRAPI_ADMIN_DLL_VERSION_1 = 0x1;

        public const uint MPRAPI_ADMIN_DLL_VERSION_2 = 0x2;

        public const uint MGM_JOIN_STATE_FLAG = 0x00000001;

        public const uint MGM_FORWARD_STATE_FLAG = 0x00000002;

        public const uint MGM_MFE_STATS_0 = 0x00000001;

        public const uint MGM_MFE_STATS_1 = 0x00000002;

        public const uint RTM_MAX_ADDRESS_SIZE = 16;

        public const uint RTM_MAX_VIEWS = 32;

        public const uint RTM_VIEW_ID_UCAST = 0;

        public const uint RTM_VIEW_ID_MCAST = 1;

        public const uint RTM_VIEW_MASK_SIZE = 0x20;

        public const uint RTM_VIEW_MASK_NONE = 0x00000000;

        public const uint RTM_VIEW_MASK_ANY = 0x00000000;

        public const uint RTM_VIEW_MASK_UCAST = 0x00000001;

        public const uint RTM_VIEW_MASK_MCAST = 0x00000002;

        public const uint RTM_VIEW_MASK_ALL = 0xFFFFFFFF;

        public const uint IPV6_ADDRESS_LEN_IN_BYTES = 16;

        public const uint RTM_DEST_FLAG_NATURAL_NET = 0x01;

        public const uint RTM_DEST_FLAG_FWD_ENGIN_ADD = 0x02;

        public const uint RTM_DEST_FLAG_DONT_FORWARD = 0x04;

        public const uint RTM_ROUTE_STATE_CREATED = 0;

        public const uint RTM_ROUTE_STATE_DELETING = 1;

        public const uint RTM_ROUTE_STATE_DELETED = 2;

        public const uint RTM_ROUTE_FLAGS_MARTIAN = 0x0001;

        public const uint RTM_ROUTE_FLAGS_BLACKHOLE = 0x0002;

        public const uint RTM_ROUTE_FLAGS_DISCARD = 0x0004;

        public const uint RTM_ROUTE_FLAGS_INACTIVE = 0x0008;

        public const uint RTM_ROUTE_FLAGS_LOCAL = 0x0010;

        public const uint RTM_ROUTE_FLAGS_REMOTE = 0x0020;

        public const uint RTM_ROUTE_FLAGS_MYSELF = 0x0040;

        public const uint RTM_ROUTE_FLAGS_LOOPBACK = 0x0080;

        public const uint RTM_ROUTE_FLAGS_MCAST = 0x0100;

        public const uint RTM_ROUTE_FLAGS_LOCAL_MCAST = 0x0200;

        public const uint RTM_ROUTE_FLAGS_LIMITED_BC = 0x0400;

        public const uint RTM_ROUTE_FLAGS_ZEROS_NETBC = 0x1000;

        public const uint RTM_ROUTE_FLAGS_ZEROS_SUBNETBC = 0x2000;

        public const uint RTM_ROUTE_FLAGS_ONES_NETBC = 0x4000;

        public const uint RTM_ROUTE_FLAGS_ONES_SUBNETBC = 0x8000;

        public const uint RTM_NEXTHOP_STATE_CREATED = 0;

        public const uint RTM_NEXTHOP_STATE_DELETED = 1;

        public const uint RTM_NEXTHOP_FLAGS_REMOTE = 0x0001;

        public const uint RTM_NEXTHOP_FLAGS_DOWN = 0x0002;

        public const uint METHOD_TYPE_ALL_METHODS = 0xFFFFFFFF;

        public const uint METHOD_RIP2_NEIGHBOUR_ADDR = 0x00000001;

        public const uint METHOD_RIP2_OUTBOUND_INTF = 0x00000002;

        public const uint METHOD_RIP2_ROUTE_TAG = 0x00000004;

        public const uint METHOD_RIP2_ROUTE_TIMESTAMP = 0x00000008;

        public const uint METHOD_BGP4_AS_PATH = 0x00000001;

        public const uint METHOD_BGP4_PEER_ID = 0x00000002;

        public const uint METHOD_BGP4_PA_ORIGIN = 0x00000004;

        public const uint METHOD_BGP4_NEXTHOP_ATTR = 0x00000008;

        public const uint RTM_RESUME_METHODS = 0;

        public const uint RTM_BLOCK_METHODS = 1;

        public const uint RTM_ROUTE_CHANGE_FIRST = 0x01;

        public const uint RTM_ROUTE_CHANGE_NEW = 0x02;

        public const uint RTM_ROUTE_CHANGE_BEST = 0x00010000;

        public const uint RTM_NEXTHOP_CHANGE_NEW = 0x01;

        public const uint RTM_MATCH_NONE = 0x00000000;

        public const uint RTM_MATCH_OWNER = 0x00000001;

        public const uint RTM_MATCH_NEIGHBOUR = 0x00000002;

        public const uint RTM_MATCH_PREF = 0x00000004;

        public const uint RTM_MATCH_NEXTHOP = 0x00000008;

        public const uint RTM_MATCH_INTERFACE = 0x00000010;

        public const uint RTM_MATCH_FULL = 0x0000FFFF;

        public const uint RTM_ENUM_START = 0x00000000;

        public const uint RTM_ENUM_NEXT = 0x00000001;

        public const uint RTM_ENUM_RANGE = 0x00000002;

        public const uint RTM_ENUM_ALL_DESTS = 0x00000000;

        public const uint RTM_ENUM_OWN_DESTS = 0x01000000;

        public const uint RTM_ENUM_ALL_ROUTES = 0x00000000;

        public const uint RTM_ENUM_OWN_ROUTES = 0x00010000;

        public const uint RTM_NUM_CHANGE_TYPES = 3;

        public const uint RTM_CHANGE_TYPE_ALL = 0x0001;

        public const uint RTM_CHANGE_TYPE_BEST = 0x0002;

        public const uint RTM_CHANGE_TYPE_FORWARDING = 0x0004;

        public const uint RTM_NOTIFY_ONLY_MARKED_DESTS = 0x00010000;

    }
}

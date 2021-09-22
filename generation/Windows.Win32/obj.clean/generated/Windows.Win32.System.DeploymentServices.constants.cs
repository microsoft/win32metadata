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


namespace Windows.Win32.System.DeploymentServices
{
    public static partial class Apis
    {
        public const uint WDS_CLI_TRANSFER_ASYNCHRONOUS = 0x00000001;

        public const uint WDS_CLI_NO_SPARSE_FILE = 0x00000002;

        public const uint PXE_DHCP_SERVER_PORT = 67;

        public const uint PXE_DHCP_CLIENT_PORT = 68;

        public const uint PXE_SERVER_PORT = 4011;

        public const uint PXE_DHCPV6_SERVER_PORT = 547;

        public const uint PXE_DHCPV6_CLIENT_PORT = 546;

        public const uint PXE_DHCP_FILE_SIZE = 128;

        public const uint PXE_DHCP_SERVER_SIZE = 64;

        public const uint PXE_DHCP_HWAADR_SIZE = 16;

        public const uint PXE_DHCP_MAGIC_COOKIE_SIZE = 4;

        public const uint PXE_REG_INDEX_TOP = 0;

        public const uint PXE_REG_INDEX_BOTTOM = 0xFFFFFFFF;

        public const uint PXE_CALLBACK_RECV_REQUEST = 0;

        public const uint PXE_CALLBACK_SHUTDOWN = 1;

        public const uint PXE_CALLBACK_SERVICE_CONTROL = 2;

        public const uint PXE_CALLBACK_MAX = 3;

        public const uint PXE_GSI_TRACE_ENABLED = 1;

        public const uint PXE_GSI_SERVER_DUID = 2;

        public const uint PXE_MAX_ADDRESS = 16;

        public const uint PXE_ADDR_BROADCAST = 0x0001;

        public const uint PXE_ADDR_USE_PORT = 0x0002;

        public const uint PXE_ADDR_USE_ADDR = 0x0004;

        public const uint PXE_ADDR_USE_DHCP_RULES = 0x0008;

        public const uint PXE_DHCPV6_RELAY_HOP_COUNT_LIMIT = 32;

        public const uint PXE_BA_NBP = 1;

        public const uint PXE_BA_CUSTOM = 2;

        public const uint PXE_BA_IGNORE = 3;

        public const uint PXE_BA_REJECTED = 4;

        public const uint PXE_TRACE_VERBOSE = 0x00010000;

        public const uint PXE_TRACE_INFO = 0x00020000;

        public const uint PXE_TRACE_WARNING = 0x00040000;

        public const uint PXE_TRACE_ERROR = 0x00080000;

        public const uint PXE_TRACE_FATAL = 0x00100000;

        public const uint PXE_PROV_ATTR_FILTER = 0;

        public const uint PXE_PROV_ATTR_FILTER_IPV6 = 1;

        public const uint PXE_PROV_ATTR_IPV6_CAPABLE = 2;

        public const uint PXE_PROV_FILTER_ALL = 0x0000;

        public const uint PXE_PROV_FILTER_DHCP_ONLY = 0x0001;

        public const uint PXE_PROV_FILTER_PXE_ONLY = 0x0002;

        public const uint MC_SERVER_CURRENT_VERSION = 1;

        public const uint TRANSPORTPROVIDER_CURRENT_VERSION = 1;

        public const uint WDS_MC_TRACE_VERBOSE = 0x00010000;

        public const uint WDS_MC_TRACE_INFO = 0x00020000;

        public const uint WDS_MC_TRACE_WARNING = 0x00040000;

        public const uint WDS_MC_TRACE_ERROR = 0x00080000;

        public const uint WDS_MC_TRACE_FATAL = 0x00100000;

        public const uint WDS_TRANSPORTCLIENT_CURRENT_API_VERSION = 1;

        public const uint WDS_TRANSPORTCLIENT_PROTOCOL_MULTICAST = 0x00000001;

        public const uint WDS_TRANSPORTCLIENT_NO_CACHE = 0;

        public const uint WDS_TRANSPORTCLIENT_STATUS_IN_PROGRESS = 0x0001;

        public const uint WDS_TRANSPORTCLIENT_STATUS_SUCCESS = 0x0002;

        public const uint WDS_TRANSPORTCLIENT_STATUS_FAILURE = 0x0003;

        public const uint WDSTRANSPORT_RESOURCE_UTILIZATION_UNKNOWN = 0xFF;

        public const uint WDSBP_PK_TYPE_DHCP = 1;

        public const uint WDSBP_PK_TYPE_WDSNBP = 2;

        public const uint WDSBP_PK_TYPE_BCD = 4;

        public const uint WDSBP_PK_TYPE_DHCPV6 = 8;

        public const uint WDSBP_OPT_TYPE_NONE = 0;

        public const uint WDSBP_OPT_TYPE_BYTE = 1;

        public const uint WDSBP_OPT_TYPE_USHORT = 2;

        public const uint WDSBP_OPT_TYPE_ULONG = 3;

        public const uint WDSBP_OPT_TYPE_WSTR = 4;

        public const uint WDSBP_OPT_TYPE_STR = 5;

        public const uint WDSBP_OPT_TYPE_IP4 = 6;

        public const uint WDSBP_OPT_TYPE_IP6 = 7;

        public const uint WDSBP_OPTVAL_ACTION_APPROVAL = 1;

        public const uint WDSBP_OPTVAL_ACTION_REFERRAL = 3;

        public const uint WDSBP_OPTVAL_ACTION_ABORT = 5;

        public const uint WDSBP_OPTVAL_PXE_PROMPT_OPTIN = 1;

        public const uint WDSBP_OPTVAL_PXE_PROMPT_NOPROMPT = 2;

        public const uint WDSBP_OPTVAL_PXE_PROMPT_OPTOUT = 3;

        public const uint WDSBP_OPTVAL_NBP_VER_7 = 0x0700;

        public const uint WDSBP_OPTVAL_NBP_VER_8 = 0x0800;

    }
}

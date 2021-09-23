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


using static Windows.Win32.NetworkManagement.Rras.Apis;

namespace Windows.Win32.NetworkManagement.Rras
{
    public enum MPR_INTERFACE_DIAL_MODE : uint
    {
        MPRDM_DialFirst = 0,
        MPRDM_DialAll = RASENTRY_DIAL_MODE.RASEDM_DialAll,
        MPRDM_DialAsNeeded = RASENTRY_DIAL_MODE.RASEDM_DialAsNeeded,
    }

    public enum RASENTRY_DIAL_MODE : uint
    {
        RASEDM_DialAll = 1,
        RASEDM_DialAsNeeded = 2,
    }

    public enum RAS_FLAGS : uint
    {
        RAS_FLAGS_PPP_CONNECTION = 1,
        RAS_FLAGS_MESSENGER_PRESENT = 2,
        RAS_FLAGS_QUARANTINE_PRESENT = 8,
        RAS_FLAGS_ARAP_CONNECTION = 16,
        RAS_FLAGS_IKEV2_CONNECTION = 16,
        RAS_FLAGS_DORMANT = 32,
    }

    public enum MPR_ET : uint
    {
        MPR_ET_None = ET_None,
        MPR_ET_Require = ET_Require,
        MPR_ET_RequireMax = ET_RequireMax,
        MPR_ET_Optional = ET_Optional,
    }

    public enum RASPPP_PROJECTION_INFO_SERVER_AUTH_DATA : uint
    {
        RASLCPAD_CHAP_MD5 = 0x05,
        RASLCPAD_CHAP_MS = 0x80,
        RASLCPAD_CHAP_MSV2 = 0x81,
    }

    public enum PPP_LCP : uint
    {
        PPP_LCP_PAP = 0xC023,
        PPP_LCP_CHAP = 0xC223,
        PPP_LCP_EAP = 0xC227,
        PPP_LCP_SPAP = 0xC027,
    }

    public enum RASPPP_PROJECTION_INFO_SERVER_AUTH_PROTOCOL : uint
    {
        RASLCPAP_PAP = 0xC023,
        RASLCPAP_SPAP = 0xC027,
        RASLCPAP_CHAP = 0xC223,
        RASLCPAP_EAP = 0xC227,
    }

    public enum PPP_LCP_INFO_AUTH_DATA : uint
    {
        PPP_LCP_CHAP_MD5 = 0x05,
        PPP_LCP_CHAP_MS = 0x80,
        PPP_LCP_CHAP_MSV2 = 0x81,
    }

    [Flags]
    public enum RASIKEV_PROJECTION_INFO_FLAGS : uint
    {
        RASIKEv2_FLAGS_MOBIKESUPPORTED = 0x00000001,
        RASIKEv2_FLAGS_BEHIND_NAT = 0x00000002,
        RASIKEv2_FLAGS_SERVERBEHIND_NAT = 0x00000004,
    }

    public enum MPR_VS : uint
    {
        MPR_VS_Default = VS_Default,
        MPR_VS_PptpOnly = VS_PptpOnly,
        MPR_VS_PptpFirst = VS_PptpFirst,
        MPR_VS_L2tpOnly = VS_L2tpOnly,
        MPR_VS_L2tpFirst = VS_L2tpFirst,
    }

    public enum SECURITY_MESSAGE_MSG_ID : uint
    {
        SECURITYMSG_SUCCESS = 1,
        SECURITYMSG_FAILURE = 2,
        SECURITYMSG_ERROR = 3,
    }

}

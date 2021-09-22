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


using static Windows.Win32.NetworkManagement.IpHelper.Apis;

namespace Windows.Win32.NetworkManagement.IpHelper
{
    public enum ADDRESS_FAMILY : uint
    {
        AF_INET = 2,
        AF_INET6 = 23,
        AF_UNSPEC = 0,
    }

    [Flags]
    public enum GET_ADAPTERS_ADDRESSES_FLAGS : uint
    {
        GAA_FLAG_SKIP_UNICAST = 1,
        GAA_FLAG_SKIP_ANYCAST = 2,
        GAA_FLAG_SKIP_MULTICAST = 4,
        GAA_FLAG_SKIP_DNS_SERVER = 8,
        GAA_FLAG_INCLUDE_PREFIX = 16,
        GAA_FLAG_SKIP_FRIENDLY_NAME = 32,
        GAA_FLAG_INCLUDE_WINS_INFO = 64,
        GAA_FLAG_INCLUDE_GATEWAYS = 128,
        GAA_FLAG_INCLUDE_ALL_INTERFACES = 256,
        GAA_FLAG_INCLUDE_ALL_COMPARTMENTS = 512,
        GAA_FLAG_INCLUDE_TUNNEL_BINDINGORDER = 1024,
    }

}

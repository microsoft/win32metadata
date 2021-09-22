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


using static Windows.Win32.NetworkManagement.WiFi.Apis;

namespace Windows.Win32.NetworkManagement.WiFi
{
    public enum WLAN_SET_EAPHOST_FLAGS : uint
    {
        WLAN_SET_EAPHOST_DATA_ALL_USERS = 1,
    }

    public enum WLAN_CONNECTION_NOTIFICATION_FLAGS : uint
    {
        WLAN_CONNECTION_NOTIFICATION_ADHOC_NETWORK_FORMED = 0x00000001,
        WLAN_CONNECTION_NOTIFICATION_CONSOLE_USER_PROFILE = 0x00000004,
    }

}

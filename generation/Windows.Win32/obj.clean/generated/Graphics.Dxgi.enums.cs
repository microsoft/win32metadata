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


using static Windows.Win32.Graphics.Dxgi.Apis;

namespace Windows.Win32.Graphics.Dxgi
{
    public enum DXGI_RESOURCE_PRIORITY : uint
    {
        DXGI_RESOURCE_PRIORITY_MINIMUM = 0x28000000,
        DXGI_RESOURCE_PRIORITY_LOW = 0x50000000,
        DXGI_RESOURCE_PRIORITY_NORMAL = 0x78000000,
        DXGI_RESOURCE_PRIORITY_HIGH = 0xa0000000,
        DXGI_RESOURCE_PRIORITY_MAXIMUM = 0xc8000000,
    }

}

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


using static Windows.Win32.Devices.BiometricFramework.Apis;

namespace Windows.Win32.Devices.BiometricFramework
{
    public enum WINBIO_SETTING_SOURCE : uint
    {
        WINBIO_SETTING_SOURCE_INVALID = 0,
        WINBIO_SETTING_SOURCE_DEFAULT = 1,
        WINBIO_SETTING_SOURCE_LOCAL = 3,
        WINBIO_SETTING_SOURCE_POLICY = 2,
    }

    public enum WINBIO_COMPONENT : uint
    {
        WINBIO_COMPONENT_SENSOR = 1,
        WINBIO_COMPONENT_ENGINE = 2,
        WINBIO_COMPONENT_STORAGE = 3,
    }

    public enum WINBIO_POOL : uint
    {
        WINBIO_POOL_SYSTEM = 1,
        WINBIO_POOL_PRIVATE = 2,
    }

}

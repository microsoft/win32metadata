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


using static Windows.Win32.System.WindowsProgramming.Apis;

namespace Windows.Win32.System.WindowsProgramming
{
    public enum NT_CREATE_FILE_DISPOSITION : uint
    {
        FILE_SUPERSEDE = 0x00000000,
        FILE_CREATE = 0x00000002,
        FILE_OPEN = 0x00000001,
        FILE_OPEN_IF = 0x00000003,
        FILE_OVERWRITE = 0x00000004,
        FILE_OVERWRITE_IF = 0x00000005,
    }

    public enum TDIENTITY_ENTITY_TYPE : uint
    {
        GENERIC_ENTITY = 0,
        AT_ENTITY = 0x280,
        CL_NL_ENTITY = 0x301,
        CO_NL_ENTITY = 0x300,
        CL_TL_ENTITY = 0x401,
        CO_TL_ENTITY = 0x400,
        ER_ENTITY = 0x380,
        IF_ENTITY = 0x200,
    }

}

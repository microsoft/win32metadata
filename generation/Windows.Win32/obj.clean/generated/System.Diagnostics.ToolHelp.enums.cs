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


using static Windows.Win32.System.Diagnostics.ToolHelp.Apis;

namespace Windows.Win32.System.Diagnostics.ToolHelp
{
    [Flags]
    public enum CREATE_TOOLHELP_SNAPSHOT_FLAGS : uint
    {
        TH32CS_INHERIT = 2147483648,
        TH32CS_SNAPALL = (TH32CS_SNAPHEAPLIST | TH32CS_SNAPPROCESS | TH32CS_SNAPTHREAD | TH32CS_SNAPMODULE),
        TH32CS_SNAPHEAPLIST = 1,
        TH32CS_SNAPMODULE = 8,
        TH32CS_SNAPMODULE32 = 16,
        TH32CS_SNAPPROCESS = 2,
        TH32CS_SNAPTHREAD = 4,
    }

    public enum HEAPENTRY32_FLAGS : uint
    {
        LF32_FIXED = 0x00000001,
        LF32_FREE = 0x00000002,
        LF32_MOVEABLE = 0x00000004,
    }

}

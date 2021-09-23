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


using static Windows.Win32.UI.TextServices.Apis;

namespace Windows.Win32.UI.TextServices
{
    public enum LANG_BAR_ITEM_ICON_MODE_FLAGS : uint
    {
        TF_DTLBI_NONE = 0,
        TF_DTLBI_USEPROFILEICON = 0x00000001,
    }

    [Flags]
    public enum TEXT_STORE_TEXT_CHANGE_FLAGS : uint
    {
        TS_ST_NONE = 0,
        TS_ST_CORRECTION = 0x1,
    }

    [Flags]
    public enum TEXT_STORE_CHANGE_FLAGS : uint
    {
        TS_TC_NONE = 0,
        TS_TC_CORRECTION = 0x1,
    }

    public enum INSERT_TEXT_AT_SELECTION_FLAGS : uint
    {
        TF_IAS_NOQUERY = 0x1,
        TF_IAS_QUERYONLY = 0x2,
        TF_IAS_NO_DEFAULT_COMPOSITION = 0x80000000,
    }

    [Flags]
    public enum ANCHOR_CHANGE_HISTORY_FLAGS : uint
    {
        TS_CH_PRECEDING_DEL = 1,
        TS_CH_FOLLOWING_DEL = 2,
    }

    public enum TEXT_STORE_LOCK_FLAGS : uint
    {
        TS_LF_READ = 0x2,
        TS_LF_READWRITE = 0x6,
    }

    [Flags]
    public enum GET_TEXT_AND_PROPERTY_UPDATES_FLAGS : uint
    {
        TF_GTP_NONE = 0,
        TF_GTP_INCL_TEXT = 0x1,
    }

    [Flags]
    public enum TF_CONTEXT_EDIT_CONTEXT_FLAGS : uint
    {
        TF_ES_ASYNCDONTCARE = 0,
        TF_ES_SYNC = 0x1,
        TF_ES_READ = 0x2,
        TF_ES_READWRITE = 0x6,
        TF_ES_ASYNC = 0x8,
    }

}

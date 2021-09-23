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


using static Windows.Win32.NetworkManagement.WNet.Apis;

namespace Windows.Win32.NetworkManagement.WNet
{
    public enum UNC_INFO_LEVEL : uint
    {
        UNIVERSAL_NAME_INFO_LEVEL = 0x00000001,
        REMOTE_NAME_INFO_LEVEL = 0x00000002,
    }

    public enum WNPERM_DLG : uint
    {
        WNPERM_DLG_PERM = 0,
        WNPERM_DLG_AUDIT = 1,
        WNPERM_DLG_OWNER = 2,
    }

    [Flags]
    public enum WNET_OPEN_ENUM_USAGE : uint
    {
        RESOURCEUSAGE_NONE = 0,
        RESOURCEUSAGE_CONNECTABLE = 0x00000001,
        RESOURCEUSAGE_CONTAINER = 0x00000002,
        RESOURCEUSAGE_ATTACHED = 0x00000010,
        RESOURCEUSAGE_ALL = (RESOURCEUSAGE_CONNECTABLE | RESOURCEUSAGE_CONTAINER | RESOURCEUSAGE_ATTACHED),
    }

    [Flags]
    public enum NET_USE_CONNECT_FLAGS : uint
    {
        CONNECT_INTERACTIVE = 0x00000008,
        CONNECT_PROMPT = 0x00000010,
        CONNECT_REDIRECT = 0x00000080,
        CONNECT_UPDATE_PROFILE = 0x00000001,
        CONNECT_COMMANDLINE = 0x00000800,
        CONNECT_CMD_SAVECRED = 0x00001000,
        CONNECT_TEMPORARY = 0x00000004,
        CONNECT_DEFERRED = 0x00000400,
        CONNECT_UPDATE_RECENT = 0x00000002,
    }

    public enum NP_PROPERTY_DIALOG_SELECTION : uint
    {
        WNPS_FILE = 0,
        WNPS_DIR = 1,
        WNPS_MULT = 2,
    }

    public enum NPDIRECTORY_NOTIFY_OPERATION : uint
    {
        WNDN_MKDIR = 1,
        WNDN_RMDIR = 2,
        WNDN_MVDIR = 3,
    }

    [Flags]
    public enum NET_RESOURCE_TYPE : uint
    {
        RESOURCETYPE_ANY = 0x00000000,
        RESOURCETYPE_DISK = 0x00000001,
        RESOURCETYPE_PRINT = 0x00000002,
    }

    public enum NETWORK_NAME_FORMAT_FLAGS : uint
    {
        WNFMT_MULTILINE = 0x01,
        WNFMT_ABBREVIATED = 0x02,
    }

    public enum NET_RESOURCE_SCOPE : uint
    {
        RESOURCE_CONNECTED = 0x00000001,
        RESOURCE_CONTEXT = 0x00000005,
        RESOURCE_GLOBALNET = 0x00000002,
        RESOURCE_REMEMBERED = 0x00000003,
    }

    [Flags]
    public enum NETINFOSTRUCT_CHARACTERISTICS : uint
    {
        NETINFO_DLL16 = 0x00000001,
        NETINFO_DISKRED = 0x00000004,
        NETINFO_PRINTERRED = 0x00000008,
    }

    [Flags]
    public enum CONNECTDLGSTRUCT_FLAGS : uint
    {
        CONNDLG_RO_PATH = 0x00000001,
        CONNDLG_CONN_POINT = 0x00000002,
        CONNDLG_USE_MRU = 0x00000004,
        CONNDLG_HIDE_BOX = 0x00000008,
        CONNDLG_PERSIST = 0x00000010,
        CONNDLG_NOT_PERSIST = 0x00000020,
    }

    [Flags]
    public enum DISCDLGSTRUCT_FLAGS : uint
    {
        DISC_UPDATE_PROFILE = 0x00000001,
        DISC_NO_FORCE = 0x00000040,
    }

}

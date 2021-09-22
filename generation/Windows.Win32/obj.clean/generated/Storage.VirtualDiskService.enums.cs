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


using static Windows.Win32.Storage.VirtualDiskService.Apis;

namespace Windows.Win32.Storage.VirtualDiskService
{
    public enum VDS_NF_PACK : uint
    {
        VDS_NF_PACK_ARRIVE = 1,
        VDS_NF_PACK_DEPART = 2,
        VDS_NF_PACK_MODIFY = 3,
    }

    public enum VDS_NF_FILE_SYSTEM : uint
    {
        VDS_NF_FILE_SYSTEM_MODIFY = 203,
        VDS_NF_FILE_SYSTEM_FORMAT_PROGRESS = 204,
    }

    public enum VDS_NF_CONTROLLER : uint
    {
        VDS_NF_CONTROLLER_ARRIVE = 103,
        VDS_NF_CONTROLLER_DEPART = 104,
        VDS_NF_CONTROLLER_MODIFY = 350,
        VDS_NF_CONTROLLER_REMOVED = 351,
    }

    public enum VDS_NF_DRIVE : uint
    {
        VDS_NF_DRIVE_ARRIVE = 105,
        VDS_NF_DRIVE_DEPART = 106,
        VDS_NF_DRIVE_MODIFY = 107,
        VDS_NF_DRIVE_REMOVED = 354,
    }

    public enum VDS_NF_PORT : uint
    {
        VDS_NF_PORT_ARRIVE = 121,
        VDS_NF_PORT_DEPART = 122,
        VDS_NF_PORT_MODIFY = 352,
        VDS_NF_PORT_REMOVED = 353,
    }

    public enum VDS_NF_LUN : uint
    {
        VDS_NF_LUN_ARRIVE = 108,
        VDS_NF_LUN_DEPART = 109,
        VDS_NF_LUN_MODIFY = 110,
    }

    public enum VDS_NF_DISK : uint
    {
        VDS_NF_DISK_ARRIVE = 8,
        VDS_NF_DISK_DEPART = 9,
        VDS_NF_DISK_MODIFY = 10,
    }

}

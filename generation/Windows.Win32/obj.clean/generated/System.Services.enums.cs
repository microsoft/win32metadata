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


using static Windows.Win32.System.Services.Apis;

namespace Windows.Win32.System.Services
{
    public enum ENUM_SERVICE_STATE : uint
    {
        SERVICE_ACTIVE = 1,
        SERVICE_INACTIVE = 2,
        SERVICE_STATE_ALL = 3,
    }

    public enum SERVICE_ERROR : uint
    {
        SERVICE_ERROR_CRITICAL = 3,
        SERVICE_ERROR_IGNORE = 0,
        SERVICE_ERROR_NORMAL = 1,
        SERVICE_ERROR_SEVERE = 2,
    }

    public enum SERVICE_CONFIG : uint
    {
        SERVICE_CONFIG_DELAYED_AUTO_START_INFO = 3,
        SERVICE_CONFIG_DESCRIPTION = 1,
        SERVICE_CONFIG_FAILURE_ACTIONS = 2,
        SERVICE_CONFIG_FAILURE_ACTIONS_FLAG = 4,
        SERVICE_CONFIG_PREFERRED_NODE = 9,
        SERVICE_CONFIG_PRESHUTDOWN_INFO = 7,
        SERVICE_CONFIG_REQUIRED_PRIVILEGES_INFO = 6,
        SERVICE_CONFIG_SERVICE_SID_INFO = 5,
        SERVICE_CONFIG_TRIGGER_INFO = 8,
        SERVICE_CONFIG_LAUNCH_PROTECTED = 12,
    }

    [Flags]
    public enum ENUM_SERVICE_TYPE : uint
    {
        SERVICE_DRIVER = 11,
        SERVICE_FILE_SYSTEM_DRIVER_ = 2,
        SERVICE_KERNEL_DRIVER = 1,
        SERVICE_WIN32 = 48,
        SERVICE_WIN32_OWN_PROCESS_ = 16,
        SERVICE_WIN32_SHARE_PROCESS = 32,
        SERVICE_ADAPTER = 4,
        SERVICE_FILE_SYSTEM_DRIVER = 2,
        SERVICE_RECOGNIZER_DRIVER = 8,
        SERVICE_WIN32_OWN_PROCESS = 16,
        SERVICE_USER_OWN_PROCESS = 80,
        SERVICE_USER_SHARE_PROCESS = 96,
    }

    public enum SERVICE_START_TYPE : uint
    {
        SERVICE_AUTO_START = 2,
        SERVICE_BOOT_START = 0,
        SERVICE_DEMAND_START = 3,
        SERVICE_DISABLED = 4,
        SERVICE_SYSTEM_START = 1,
    }

    [Flags]
    public enum SERVICE_NOTIFY : uint
    {
        SERVICE_NOTIFY_CREATED = 128,
        SERVICE_NOTIFY_CONTINUE_PENDING = 16,
        SERVICE_NOTIFY_DELETE_PENDING = 512,
        SERVICE_NOTIFY_DELETED = 256,
        SERVICE_NOTIFY_PAUSE_PENDING = 32,
        SERVICE_NOTIFY_PAUSED = 64,
        SERVICE_NOTIFY_RUNNING = 8,
        SERVICE_NOTIFY_START_PENDING = 2,
        SERVICE_NOTIFY_STOP_PENDING = 4,
        SERVICE_NOTIFY_STOPPED = 1,
    }

    public enum SERVICE_RUNS_IN_PROCESS : uint
    {
        SERVICE_RUNS_IN_NON_SYSTEM_OR_NOT_RUNNING = 0,
        SERVICE_RUNS_IN_SYSTEM_PROCESS = 1,
    }

    public enum SERVICE_TRIGGER_ACTION : uint
    {
        SERVICE_TRIGGER_ACTION_SERVICE_START = 1,
        SERVICE_TRIGGER_ACTION_SERVICE_STOP = 2,
    }

    public enum SERVICE_TRIGGER_TYPE : uint
    {
        SERVICE_TRIGGER_TYPE_CUSTOM = 20,
        SERVICE_TRIGGER_TYPE_DEVICE_INTERFACE_ARRIVAL = 1,
        SERVICE_TRIGGER_TYPE_DOMAIN_JOIN = 3,
        SERVICE_TRIGGER_TYPE_FIREWALL_PORT_EVENT = 4,
        SERVICE_TRIGGER_TYPE_GROUP_POLICY = 5,
        SERVICE_TRIGGER_TYPE_IP_ADDRESS_AVAILABILITY = 2,
        SERVICE_TRIGGER_TYPE_NETWORK_ENDPOINT = 6,
    }

    public enum SERVICE_TRIGGER_SPECIFIC_DATA_ITEM_DATA_TYPE : uint
    {
        SERVICE_TRIGGER_DATA_TYPE_BINARY = 1,
        SERVICE_TRIGGER_DATA_TYPE_STRING = 2,
        SERVICE_TRIGGER_DATA_TYPE_LEVEL = 3,
        SERVICE_TRIGGER_DATA_TYPE_KEYWORD_ANY = 4,
        SERVICE_TRIGGER_DATA_TYPE_KEYWORD_ALL = 5,
    }

    public enum SERVICE_STATUS_CURRENT_STATE : uint
    {
        SERVICE_CONTINUE_PENDING = 5,
        SERVICE_PAUSE_PENDING = 6,
        SERVICE_PAUSED = 7,
        SERVICE_RUNNING = 4,
        SERVICE_START_PENDING = 2,
        SERVICE_STOP_PENDING = 3,
        SERVICE_STOPPED = 1,
    }

}

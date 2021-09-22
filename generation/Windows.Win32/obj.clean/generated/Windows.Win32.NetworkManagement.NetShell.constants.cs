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


namespace Windows.Win32.NetworkManagement.NetShell
{
    public static partial class Apis
    {
        public const uint NETSH_ERROR_BASE = 15000;

        public const uint ERROR_NO_ENTRIES = NETSH_ERROR_BASE + 0;

        public const uint ERROR_INVALID_SYNTAX = NETSH_ERROR_BASE + 1;

        public const uint ERROR_PROTOCOL_NOT_IN_TRANSPORT = NETSH_ERROR_BASE + 2;

        public const uint ERROR_NO_CHANGE = NETSH_ERROR_BASE + 3;

        public const uint ERROR_CMD_NOT_FOUND = NETSH_ERROR_BASE + 4;

        public const uint ERROR_ENTRY_PT_NOT_FOUND = NETSH_ERROR_BASE + 5;

        public const uint ERROR_DLL_LOAD_FAILED = NETSH_ERROR_BASE + 6;

        public const uint ERROR_INIT_DISPLAY = NETSH_ERROR_BASE + 7;

        public const uint ERROR_TAG_ALREADY_PRESENT = NETSH_ERROR_BASE + 8;

        public const uint ERROR_INVALID_OPTION_TAG = NETSH_ERROR_BASE + 9;

        public const uint ERROR_NO_TAG = NETSH_ERROR_BASE + 10;

        public const uint ERROR_MISSING_OPTION = NETSH_ERROR_BASE + 11;

        public const uint ERROR_TRANSPORT_NOT_PRESENT = NETSH_ERROR_BASE + 12;

        public const uint ERROR_SHOW_USAGE = NETSH_ERROR_BASE + 13;

        public const uint ERROR_INVALID_OPTION_VALUE = NETSH_ERROR_BASE + 14;

        public const uint ERROR_OKAY = NETSH_ERROR_BASE + 15;

        public const uint ERROR_CONTINUE_IN_PARENT_CONTEXT = NETSH_ERROR_BASE + 16;

        public const uint ERROR_SUPPRESS_OUTPUT = NETSH_ERROR_BASE + 17;

        public const uint ERROR_HELPER_ALREADY_REGISTERED = NETSH_ERROR_BASE + 18;

        public const uint ERROR_CONTEXT_ALREADY_REGISTERED = NETSH_ERROR_BASE + 19;

        public const uint ERROR_PARSING_FAILURE = NETSH_ERROR_BASE + 20;

        public const uint MAX_NAME_LEN = 48;

        public const uint NETSH_VERSION_50 = 0x0005000;

        public const uint NETSH_MAX_TOKEN_LENGTH = 64;

        public const uint NETSH_MAX_CMD_TOKEN_LENGTH = 128;

        public const uint DEFAULT_CONTEXT_PRIORITY = 100;

    }
}

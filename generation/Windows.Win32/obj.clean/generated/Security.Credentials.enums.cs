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


using static Windows.Win32.Security.Credentials.Apis;

namespace Windows.Win32.Security.Credentials
{
    [Flags]
    public enum CRED_FLAGS : uint
    {
        CRED_FLAGS_PASSWORD_FOR_CERT = 0x0001,
        CRED_FLAGS_PROMPT_NOW = 0x0002,
        CRED_FLAGS_USERNAME_TARGET = 0x0004,
        CRED_FLAGS_OWF_CRED_BLOB = 0x0008,
        CRED_FLAGS_REQUIRE_CONFIRMATION = 0x0010,
        CRED_FLAGS_WILDCARD_MATCH = 0x0020,
        CRED_FLAGS_VSM_PROTECTED = 0x0040,
        CRED_FLAGS_NGC_CERT = 0x0080,
        CRED_FLAGS_VALID_FLAGS = 0xF0FF,
        CRED_FLAGS_VALID_INPUT_FLAGS = 0xF09F,
    }

    public enum CRED_TYPE : uint
    {
        CRED_TYPE_GENERIC = 1,
        CRED_TYPE_DOMAIN_PASSWORD = 2,
        CRED_TYPE_DOMAIN_CERTIFICATE = 3,
        CRED_TYPE_DOMAIN_VISIBLE_PASSWORD = 4,
        CRED_TYPE_GENERIC_CERTIFICATE = 5,
        CRED_TYPE_DOMAIN_EXTENDED = 6,
        CRED_TYPE_MAXIMUM = 7,
        CRED_TYPE_MAXIMUM_EX = CRED_TYPE_MAXIMUM+1000,
    }

    public enum CRED_PERSIST : uint
    {
        CRED_PERSIST_NONE = 0,
        CRED_PERSIST_SESSION = 1,
        CRED_PERSIST_LOCAL_MACHINE = 2,
        CRED_PERSIST_ENTERPRISE = 3,
    }

    [Flags]
    public enum CREDUI_FLAGS : uint
    {
        CREDUI_FLAGS_ALWAYS_SHOW_UI = 128,
        CREDUI_FLAGS_COMPLETE_USERNAME = 2048,
        CREDUI_FLAGS_DO_NOT_PERSIST = 2,
        CREDUI_FLAGS_EXCLUDE_CERTIFICATES = 8,
        CREDUI_FLAGS_EXPECT_CONFIRMATION = 131072,
        CREDUI_FLAGS_GENERIC_CREDENTIALS = 262144,
        CREDUI_FLAGS_INCORRECT_PASSWORD = 1,
        CREDUI_FLAGS_KEEP_USERNAME = 1048576,
        CREDUI_FLAGS_PASSWORD_ONLY_OK = 512,
        CREDUI_FLAGS_PERSIST = 4096,
        CREDUI_FLAGS_REQUEST_ADMINISTRATOR = 4,
        CREDUI_FLAGS_REQUIRE_CERTIFICATE = 16,
        CREDUI_FLAGS_REQUIRE_SMARTCARD = 256,
        CREDUI_FLAGS_SERVER_CREDENTIAL = 0x04000,
        CREDUI_FLAGS_SHOW_SAVE_CHECK_BOX = 64,
        CREDUI_FLAGS_USERNAME_TARGET_CREDENTIALS = 524288,
        CREDUI_FLAGS_VALIDATE_USERNAME = 1024,
    }

    public enum SCARD_SCOPE : uint
    {
        SCARD_SCOPE_USER = 0,
        SCARD_SCOPE_SYSTEM = 2,
    }

    [Flags]
    public enum CRED_ENUMERATE_FLAGS : uint
    {
        CRED_ENUMERATE_ALL_CREDENTIALS = 1,
    }

    [Flags]
    public enum CREDUIWIN_FLAGS : uint
    {
        CREDUIWIN_GENERIC = 1,
        CREDUIWIN_CHECKBOX = 2,
        CREDUIWIN_AUTHPACKAGE_ONLY = 16,
        CREDUIWIN_IN_CRED_ONLY = 32,
        CREDUIWIN_ENUMERATE_ADMINS = 256,
        CREDUIWIN_ENUMERATE_CURRENT_USER = 512,
        CREDUIWIN_SECURE_PROMPT = 4096,
        CREDUIWIN_PREPROMPTING = 8192,
        CREDUIWIN_PACK_32_WOW = 268435456,
    }

    public enum SCARD_STATE : uint
    {
        SCARD_STATE_UNAWARE = 0x00000000,
        SCARD_STATE_IGNORE = 0x00000001,
        SCARD_STATE_UNAVAILABLE = 0x00000008,
        SCARD_STATE_EMPTY = 0x00000010,
        SCARD_STATE_PRESENT = 0x00000020,
        SCARD_STATE_ATRMATCH = 0x00000040,
        SCARD_STATE_EXCLUSIVE = 0x00000080,
        SCARD_STATE_INUSE = 0x00000100,
        SCARD_STATE_MUTE = 0x00000200,
        SCARD_STATE_CHANGED = 0x00000002,
        SCARD_STATE_UNKNOWN = 0x00000004,
    }

    [Flags]
    public enum CRED_PACK_FLAGS : uint
    {
        CRED_PACK_PROTECTED_CREDENTIALS = 0x1,
        CRED_PACK_WOW_BUFFER = 0x2,
        CRED_PACK_GENERIC_CREDENTIALS = 0x4,
        CRED_PACK_ID_PROVIDER_CREDENTIALS = 0x8,
    }

}

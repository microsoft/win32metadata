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


using static Windows.Win32.System.DataExchange.Apis;

namespace Windows.Win32.System.DataExchange
{
    public enum DDE_ENABLE_CALLBACK_CMD : uint
    {
        EC_ENABLEALL = 0,
        EC_ENABLEONE = 128,
        EC_DISABLE = 8,
        EC_QUERYWAITING = 2,
    }

    [Flags]
    public enum DDE_INITIALIZE_COMMAND : uint
    {
        APPCLASS_MONITOR = 0x00000001,
        APPCLASS_STANDARD = 0x00000000,
        APPCMD_CLIENTONLY = 0x00000010,
        APPCMD_FILTERINITS = 0x00000020,
        CBF_FAIL_ALLSVRXACTIONS = 258048,
        CBF_FAIL_ADVISES = 16384,
        CBF_FAIL_CONNECTIONS = 8192,
        CBF_FAIL_EXECUTES = 32768,
        CBF_FAIL_POKES = 65536,
        CBF_FAIL_REQUESTS = 131072,
        CBF_FAIL_SELFCONNECTIONS = 4096,
        CBF_SKIP_ALLNOTIFICATIONS = 3932160,
        CBF_SKIP_CONNECT_CONFIRMS = 262144,
        CBF_SKIP_DISCONNECTS = 2097152,
        CBF_SKIP_REGISTRATIONS = 524288,
        CBF_SKIP_UNREGISTRATIONS = 1048576,
        MF_CALLBACKS = 134217728,
        MF_CONV = 1073741824,
        MF_ERRORS = 268435456,
        MF_HSZ_INFO = 16777216,
        MF_LINKS = 536870912,
        MF_POSTMSGS = 67108864,
        MF_SENDMSGS = 33554432,
    }

    public enum DDE_NAME_SERVICE_CMD : uint
    {
        DNS_REGISTER = 1,
        DNS_UNREGISTER = 2,
        DNS_FILTERON = 4,
        DNS_FILTEROFF = 8,
    }

    public enum DDE_CLIENT_TRANSACTION_TYPE : uint
    {
        XTYP_ADVSTART = 4144,
        XTYP_ADVSTOP = 32832,
        XTYP_EXECUTE = 16464,
        XTYP_POKE = 16528,
        XTYP_REQUEST = 8368,
        XTYP_ADVDATA = 16400,
        XTYP_ADVREQ = 8226,
        XTYP_CONNECT = 4194,
        XTYP_CONNECT_CONFIRM = 32882,
        XTYP_DISCONNECT = 32962,
        XTYP_MONITOR = 33010,
        XTYP_REGISTER = 32930,
        XTYP_UNREGISTER = 32978,
        XTYP_WILDCONNECT = 8418,
        XTYP_XACT_COMPLETE = 32896,
    }

    public enum CONVINFO_CONVERSATION_STATE : uint
    {
        XST_ADVACKRCVD = 13,
        XST_ADVDATAACKRCVD = 16,
        XST_ADVDATASENT = 15,
        XST_ADVSENT = 11,
        XST_CONNECTED = 2,
        XST_DATARCVD = 6,
        XST_EXECACKRCVD = 10,
        XST_EXECSENT = 9,
        XST_INCOMPLETE = 1,
        XST_INIT1 = 3,
        XST_INIT2 = 4,
        XST_NULL = 0,
        XST_POKEACKRCVD = 8,
        XST_POKESENT = 7,
        XST_REQSENT = 5,
        XST_UNADVACKRCVD = 14,
        XST_UNADVSENT = 12,
    }

    [Flags]
    public enum CONVINFO_STATUS : uint
    {
        ST_ADVISE = 2,
        ST_BLOCKED = 8,
        ST_BLOCKNEXT = 128,
        ST_CLIENT = 16,
        ST_CONNECTED = 1,
        ST_INLIST = 64,
        ST_ISLOCAL = 4,
        ST_ISSELF = 256,
        ST_TERMINATED = 32,
    }

}

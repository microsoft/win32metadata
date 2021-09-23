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


namespace Windows.Win32.System.Mapi
{
    public static partial class Apis
    {
        public const uint MAPI_OLE = 0x00000001;

        public const uint MAPI_OLE_STATIC = 0x00000002;

        public const uint MAPI_ORIG = 0;

        public const uint MAPI_TO = 1;

        public const uint MAPI_CC = 2;

        public const uint MAPI_BCC = 3;

        public const uint MAPI_UNREAD = 0x00000001;

        public const uint MAPI_RECEIPT_REQUESTED = 0x00000002;

        public const uint MAPI_SENT = 0x00000004;

        public const uint MAPI_LOGON_UI = 0x00000001;

        public const uint MAPI_PASSWORD_UI = 0x00020000;

        public const uint MAPI_NEW_SESSION = 0x00000002;

        public const uint MAPI_FORCE_DOWNLOAD = 0x00001000;

        public const uint MAPI_EXTENDED = 0x00000020;

        public const uint MAPI_DIALOG = 0x00000008;

        public const uint MAPI_FORCE_UNICODE = 0x00040000;

        public const uint MAPI_UNREAD_ONLY = 0x00000020;

        public const uint MAPI_GUARANTEE_FIFO = 0x00000100;

        public const uint MAPI_LONG_MSGID = 0x00004000;

        public const uint MAPI_PEEK = 0x00000080;

        public const uint MAPI_SUPPRESS_ATTACH = 0x00000800;

        public const uint MAPI_ENVELOPE_ONLY = 0x00000040;

        public const uint MAPI_BODY_AS_FILE = 0x00000200;

        public const uint MAPI_AB_NOMODIFY = 0x00000400;

        public const uint SUCCESS_SUCCESS = 0;

        public const uint MAPI_USER_ABORT = 1;

        public const uint MAPI_E_FAILURE = 2;

        public const uint MAPI_E_LOGON_FAILURE = 3;

        public const uint MAPI_E_DISK_FULL = 4;

        public const uint MAPI_E_INSUFFICIENT_MEMORY = 5;

        public const uint MAPI_E_ACCESS_DENIED = 6;

        public const uint MAPI_E_TOO_MANY_SESSIONS = 8;

        public const uint MAPI_E_TOO_MANY_FILES = 9;

        public const uint MAPI_E_TOO_MANY_RECIPIENTS = 10;

        public const uint MAPI_E_ATTACHMENT_NOT_FOUND = 11;

        public const uint MAPI_E_ATTACHMENT_OPEN_FAILURE = 12;

        public const uint MAPI_E_ATTACHMENT_WRITE_FAILURE = 13;

        public const uint MAPI_E_UNKNOWN_RECIPIENT = 14;

        public const uint MAPI_E_BAD_RECIPTYPE = 15;

        public const uint MAPI_E_NO_MESSAGES = 16;

        public const uint MAPI_E_INVALID_MESSAGE = 17;

        public const uint MAPI_E_TEXT_TOO_LARGE = 18;

        public const uint MAPI_E_INVALID_SESSION = 19;

        public const uint MAPI_E_TYPE_NOT_SUPPORTED = 20;

        public const uint MAPI_E_AMBIGUOUS_RECIPIENT = 21;

        public const uint MAPI_E_MESSAGE_IN_USE = 22;

        public const uint MAPI_E_NETWORK_FAILURE = 23;

        public const uint MAPI_E_INVALID_EDITFIELDS = 24;

        public const uint MAPI_E_INVALID_RECIPS = 25;

        public const uint MAPI_E_NOT_SUPPORTED = 26;

        public const uint MAPI_E_UNICODE_NOT_SUPPORTED = 27;

        public const uint MAPI_E_ATTACHMENT_TOO_LARGE = 28;

    }
}

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


namespace Windows.Win32.Media.DeviceManager
{
    public static partial class Apis
    {
        public const uint IOCTL_MTP_CUSTOM_COMMAND = 0x3150544d;

        public const uint MTP_NEXTPHASE_READ_DATA = 1;

        public const uint MTP_NEXTPHASE_WRITE_DATA = 2;

        public const uint MTP_NEXTPHASE_NO_DATA = 3;

        public const uint RSA_KEY_LEN = 64;

        public const uint SAC_SESSION_KEYLEN = 8;

        public const uint SAC_PROTOCOL_WMDM = 1;

        public const uint SAC_PROTOCOL_V1 = 2;

        public const uint SAC_CERT_X509 = 1;

        public const uint SAC_CERT_V1 = 2;

        public static readonly Guid WMDM_DEVICE_PROTOCOL_MTP__scanned__ = new Guid(0x979e54e5, 0xafc, 0x4604, 0x8d, 0x93, 0xdc, 0x79, 0x8a, 0x4b, 0xcf, 0x45);

        public static readonly Guid WMDM_DEVICE_PROTOCOL_RAPI__scanned__ = new Guid(0x2a11ed91, 0x8c8f, 0x41e4, 0x82, 0xd1, 0x83, 0x86, 0xe0, 0x3, 0x56, 0x1c);

        public static readonly Guid WMDM_DEVICE_PROTOCOL_MSC__scanned__ = new Guid(0xa4d2c26c, 0xa881, 0x44bb, 0xbd, 0x5d, 0x1f, 0x70, 0x3c, 0x71, 0xf7, 0xa9);

        public static readonly Guid WMDM_SERVICE_PROVIDER_VENDOR_MICROSOFT__scanned__ = new Guid(0x7de8686d, 0x78ee, 0x43ea, 0xa4, 0x96, 0xc6, 0x25, 0xac, 0x91, 0xcc, 0x5d);

        public const uint WMDMID_LENGTH = 128;

        public const uint WMDM_MAC_LENGTH = 8;

        public const int WMDM_S_NOT_ALL_PROPERTIES_APPLIED = 0x00045001;

        public const int WMDM_S_NOT_ALL_PROPERTIES_RETRIEVED = 0x00045002;

        public const int WMDM_E_BUSY = unchecked((int)0x80045000);

        public const int WMDM_E_INTERFACEDEAD = unchecked((int)0x80045001);

        public const int WMDM_E_INVALIDTYPE = unchecked((int)0x80045002);

        public const int WMDM_E_PROCESSFAILED = unchecked((int)0x80045003);

        public const int WMDM_E_NOTSUPPORTED = unchecked((int)0x80045004);

        public const int WMDM_E_NOTCERTIFIED = unchecked((int)0x80045005);

        public const int WMDM_E_NORIGHTS = unchecked((int)0x80045006);

        public const int WMDM_E_CALL_OUT_OF_SEQUENCE = unchecked((int)0x80045007);

        public const int WMDM_E_BUFFERTOOSMALL = unchecked((int)0x80045008);

        public const int WMDM_E_MOREDATA = unchecked((int)0x80045009);

        public const int WMDM_E_MAC_CHECK_FAILED = unchecked((int)0x8004500A);

        public const int WMDM_E_USER_CANCELLED = unchecked((int)0x8004500B);

        public const int WMDM_E_SDMI_TRIGGER = unchecked((int)0x8004500C);

        public const int WMDM_E_SDMI_NOMORECOPIES = unchecked((int)0x8004500D);

        public const int WMDM_E_REVOKED = unchecked((int)0x8004500E);

        public const int WMDM_E_LICENSE_NOTEXIST = unchecked((int)0x8004500F);

        public const int WMDM_E_INCORRECT_APPSEC = unchecked((int)0x80045010);

        public const int WMDM_E_INCORRECT_RIGHTS = unchecked((int)0x80045011);

        public const int WMDM_E_LICENSE_EXPIRED = unchecked((int)0x80045012);

        public const int WMDM_E_CANTOPEN_PMSN_SERVICE_PIPE = unchecked((int)0x80045013);

        public const int WMDM_E_TOO_MANY_SESSIONS = unchecked((int)0x80045013);

        public const uint WMDM_WMDM_REVOKED = 0x00000001;

        public const uint WMDM_APP_REVOKED = 0x00000002;

        public const uint WMDM_SP_REVOKED = 0x00000004;

        public const uint WMDM_SCP_REVOKED = 0x00000008;

        public const uint WMDM_GET_FORMAT_SUPPORT_AUDIO = 0x00000001;

        public const uint WMDM_GET_FORMAT_SUPPORT_VIDEO = 0x00000002;

        public const uint WMDM_GET_FORMAT_SUPPORT_FILE = 0x00000004;

        public const uint WMDM_RIGHTS_PLAYBACKCOUNT = 0x00000001;

        public const uint WMDM_RIGHTS_EXPIRATIONDATE = 0x00000002;

        public const uint WMDM_RIGHTS_GROUPID = 0x00000004;

        public const uint WMDM_RIGHTS_FREESERIALIDS = 0x00000008;

        public const uint WMDM_RIGHTS_NAMEDSERIALIDS = 0x00000010;

        public const uint WMDM_DEVICE_TYPE_PLAYBACK = 0x00000001;

        public const uint WMDM_DEVICE_TYPE_RECORD = 0x00000002;

        public const uint WMDM_DEVICE_TYPE_DECODE = 0x00000004;

        public const uint WMDM_DEVICE_TYPE_ENCODE = 0x00000008;

        public const uint WMDM_DEVICE_TYPE_STORAGE = 0x00000010;

        public const uint WMDM_DEVICE_TYPE_VIRTUAL = 0x00000020;

        public const uint WMDM_DEVICE_TYPE_SDMI = 0x00000040;

        public const uint WMDM_DEVICE_TYPE_NONSDMI = 0x00000080;

        public const uint WMDM_DEVICE_TYPE_NONREENTRANT = 0x00000100;

        public const uint WMDM_DEVICE_TYPE_FILELISTRESYNC = 0x00000200;

        public const uint WMDM_DEVICE_TYPE_VIEW_PREF_METADATAVIEW = 0x00000400;

        public const uint WMDM_POWER_CAP_BATTERY = 0x00000001;

        public const uint WMDM_POWER_CAP_EXTERNAL = 0x00000002;

        public const uint WMDM_POWER_IS_BATTERY = 0x00000004;

        public const uint WMDM_POWER_IS_EXTERNAL = 0x00000008;

        public const uint WMDM_POWER_PERCENT_AVAILABLE = 0x00000010;

        public const uint WMDM_STATUS_READY = 0x00000001;

        public const uint WMDM_STATUS_BUSY = 0x00000002;

        public const uint WMDM_STATUS_DEVICE_NOTPRESENT = 0x00000004;

        public const uint WMDM_STATUS_DEVICECONTROL_PLAYING = 0x00000008;

        public const uint WMDM_STATUS_DEVICECONTROL_RECORDING = 0x00000010;

        public const uint WMDM_STATUS_DEVICECONTROL_PAUSED = 0x00000020;

        public const uint WMDM_STATUS_DEVICECONTROL_REMOTE = 0x00000040;

        public const uint WMDM_STATUS_DEVICECONTROL_STREAM = 0x00000080;

        public const uint WMDM_STATUS_STORAGE_NOTPRESENT = 0x00000100;

        public const uint WMDM_STATUS_STORAGE_INITIALIZING = 0x00000200;

        public const uint WMDM_STATUS_STORAGE_BROKEN = 0x00000400;

        public const uint WMDM_STATUS_STORAGE_NOTSUPPORTED = 0x00000800;

        public const uint WMDM_STATUS_STORAGE_UNFORMATTED = 0x00001000;

        public const uint WMDM_STATUS_STORAGECONTROL_INSERTING = 0x00002000;

        public const uint WMDM_STATUS_STORAGECONTROL_DELETING = 0x00004000;

        public const uint WMDM_STATUS_STORAGECONTROL_APPENDING = 0x00008000;

        public const uint WMDM_STATUS_STORAGECONTROL_MOVING = 0x00010000;

        public const uint WMDM_STATUS_STORAGECONTROL_READING = 0x00020000;

        public const uint WMDM_DEVICECAP_CANPLAY = 0x00000001;

        public const uint WMDM_DEVICECAP_CANSTREAMPLAY = 0x00000002;

        public const uint WMDM_DEVICECAP_CANRECORD = 0x00000004;

        public const uint WMDM_DEVICECAP_CANSTREAMRECORD = 0x00000008;

        public const uint WMDM_DEVICECAP_CANPAUSE = 0x00000010;

        public const uint WMDM_DEVICECAP_CANRESUME = 0x00000020;

        public const uint WMDM_DEVICECAP_CANSTOP = 0x00000040;

        public const uint WMDM_DEVICECAP_CANSEEK = 0x00000080;

        public const uint WMDM_DEVICECAP_HASSECURECLOCK = 0x00000100;

        public const uint WMDM_SEEK_REMOTECONTROL = 0x00000001;

        public const uint WMDM_SEEK_STREAMINGAUDIO = 0x00000002;

        public const uint WMDM_STORAGE_ATTR_FILESYSTEM = 0x00000001;

        public const uint WMDM_STORAGE_ATTR_REMOVABLE = 0x00000002;

        public const uint WMDM_STORAGE_ATTR_NONREMOVABLE = 0x00000004;

        public const uint WMDM_FILE_ATTR_FOLDER = 0x00000008;

        public const uint WMDM_FILE_ATTR_LINK = 0x00000010;

        public const uint WMDM_FILE_ATTR_FILE = 0x00000020;

        public const uint WMDM_FILE_ATTR_VIDEO = 0x00000040;

        public const uint WMDM_STORAGE_ATTR_CANEDITMETADATA = 0x00000080;

        public const uint WMDM_STORAGE_ATTR_FOLDERS = 0x00000100;

        public const uint WMDM_FILE_ATTR_AUDIO = 0x00001000;

        public const uint WMDM_FILE_ATTR_DATA = 0x00002000;

        public const uint WMDM_FILE_ATTR_CANPLAY = 0x00004000;

        public const uint WMDM_FILE_ATTR_CANDELETE = 0x00008000;

        public const uint WMDM_FILE_ATTR_CANMOVE = 0x00010000;

        public const uint WMDM_FILE_ATTR_CANRENAME = 0x00020000;

        public const uint WMDM_FILE_ATTR_CANREAD = 0x00040000;

        public const uint WMDM_FILE_ATTR_MUSIC = 0x00080000;

        public const uint WMDM_FILE_CREATE_OVERWRITE = 0x00100000;

        public const uint WMDM_FILE_ATTR_AUDIOBOOK = 0x00200000;

        public const uint WMDM_FILE_ATTR_HIDDEN = 0x00400000;

        public const uint WMDM_FILE_ATTR_SYSTEM = 0x00800000;

        public const uint WMDM_FILE_ATTR_READONLY = 0x01000000;

        public const uint WMDM_STORAGE_ATTR_HAS_FOLDERS = 0x02000000;

        public const uint WMDM_STORAGE_ATTR_HAS_FILES = 0x04000000;

        public const uint WMDM_STORAGE_IS_DEFAULT = 0x08000000;

        public const uint WMDM_STORAGE_CONTAINS_DEFAULT = 0x10000000;

        public const uint WMDM_STORAGE_ATTR_VIRTUAL = 0x20000000;

        public const uint WMDM_STORAGECAP_FOLDERSINROOT = 0x00000001;

        public const uint WMDM_STORAGECAP_FILESINROOT = 0x00000002;

        public const uint WMDM_STORAGECAP_FOLDERSINFOLDERS = 0x00000004;

        public const uint WMDM_STORAGECAP_FILESINFOLDERS = 0x00000008;

        public const uint WMDM_STORAGECAP_FOLDERLIMITEXISTS = 0x00000010;

        public const uint WMDM_STORAGECAP_FILELIMITEXISTS = 0x00000020;

        public const uint WMDM_STORAGECAP_NOT_INITIALIZABLE = 0x00000040;

        public const uint WMDM_MODE_BLOCK = 0x00000001;

        public const uint WMDM_MODE_THREAD = 0x00000002;

        public const uint WMDM_CONTENT_FILE = 0x00000004;

        public const uint WMDM_CONTENT_FOLDER = 0x00000008;

        public const uint WMDM_CONTENT_OPERATIONINTERFACE = 0x00000010;

        public const uint WMDM_MODE_QUERY = 0x00000020;

        public const uint WMDM_MODE_PROGRESS = 0x00000040;

        public const uint WMDM_MODE_TRANSFER_PROTECTED = 0x00000080;

        public const uint WMDM_MODE_TRANSFER_UNPROTECTED = 0x00000100;

        public const uint WMDM_STORAGECONTROL_INSERTBEFORE = 0x00000200;

        public const uint WMDM_STORAGECONTROL_INSERTAFTER = 0x00000400;

        public const uint WMDM_STORAGECONTROL_INSERTINTO = 0x00000800;

        public const uint WMDM_MODE_RECURSIVE = 0x00001000;

        public const uint WMDM_RIGHTS_PLAY_ON_PC = 0x00000001;

        public const uint WMDM_RIGHTS_COPY_TO_NON_SDMI_DEVICE = 0x00000002;

        public const uint WMDM_RIGHTS_COPY_TO_CD = 0x00000008;

        public const uint WMDM_RIGHTS_COPY_TO_SDMI_DEVICE = 0x00000010;

        public const uint WMDM_SEEK_BEGIN = 0x00000001;

        public const uint WMDM_SEEK_CURRENT = 0x00000002;

        public const uint WMDM_SEEK_END = 0x00000008;

        public const uint DO_NOT_VIRTUALIZE_STORAGES_AS_DEVICES = 0x00000001;

        public const uint ALLOW_OUTOFBAND_NOTIFICATION = 0x00000002;

        public const uint MDSP_READ = 0x00000001;

        public const uint MDSP_WRITE = 0x00000002;

        public const uint MDSP_SEEK_BOF = 0x00000001;

        public const uint MDSP_SEEK_CUR = 0x00000002;

        public const uint MDSP_SEEK_EOF = 0x00000004;

        public const int WMDM_SCP_EXAMINE_EXTENSION = 0x00000001;

        public const int WMDM_SCP_EXAMINE_DATA = 0x00000002;

        public const int WMDM_SCP_DECIDE_DATA = 0x00000008;

        public const int WMDM_SCP_PROTECTED_OUTPUT = 0x00000010;

        public const int WMDM_SCP_UNPROTECTED_OUTPUT = 0x00000020;

        public const int WMDM_SCP_RIGHTS_DATA = 0x00000040;

        public const int WMDM_SCP_TRANSFER_OBJECTDATA = 0x00000020;

        public const int WMDM_SCP_NO_MORE_CHANGES = 0x00000040;

        public const int WMDM_SCP_DRMINFO_NOT_DRMPROTECTED = 0x00000000;

        public const int WMDM_SCP_DRMINFO_V1HEADER = 0x00000001;

        public const int WMDM_SCP_DRMINFO_V2HEADER = 0x00000002;

        public static readonly Guid SCP_EVENTID_ACQSECURECLOCK__scanned__ = new Guid(0x86248cc9, 0x4a59, 0x43e2, 0x91, 0x46, 0x48, 0xa7, 0xf3, 0xf4, 0x14, 0xc);

        public static readonly Guid SCP_EVENTID_NEEDTOINDIV__scanned__ = new Guid(0x87a507c7, 0xb469, 0x4386, 0xb9, 0x76, 0xd5, 0xd1, 0xce, 0x53, 0x8a, 0x6f);

        public static readonly Guid SCP_EVENTID_DRMINFO__scanned__ = new Guid(0x213dd287, 0x41d2, 0x432b, 0x9e, 0x3f, 0x3b, 0x4f, 0x7b, 0x35, 0x81, 0xdd);

        public static readonly Guid SCP_PARAMID_DRMVERSION__scanned__ = new Guid(0x41d0155d, 0x7cc7, 0x4217, 0xad, 0xa9, 0x00, 0x50, 0x74, 0x62, 0x4d, 0xa4);

        public const uint SAC_MAC_LEN = 8;

        public const uint WMDM_LOG_SEV_INFO = 0x00000001;

        public const uint WMDM_LOG_SEV_WARN = 0x00000002;

        public const uint WMDM_LOG_SEV_ERROR = 0x00000004;

        public const uint WMDM_LOG_NOTIMESTAMP = 0x00000010;

    }
}

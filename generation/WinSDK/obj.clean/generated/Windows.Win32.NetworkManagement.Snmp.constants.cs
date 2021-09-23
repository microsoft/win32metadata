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


namespace Windows.Win32.NetworkManagement.Snmp
{
    public static partial class Apis
    {
        public const uint ASN_UNIVERSAL = 0x00;

        public const uint ASN_APPLICATION = 0x40;

        public const uint ASN_CONTEXT = 0x80;

        public const uint ASN_PRIVATE = 0xC0;

        public const uint ASN_PRIMITIVE = 0x00;

        public const uint ASN_CONSTRUCTOR = 0x20;

        public const uint SNMP_ACCESS_NONE = 0;

        public const uint SNMP_ACCESS_NOTIFY = 1;

        public const uint SNMP_ACCESS_READ_ONLY = 2;

        public const uint SNMP_ACCESS_READ_WRITE = 3;

        public const uint SNMP_ACCESS_READ_CREATE = 4;

        public const uint SNMPAPI_NOERROR = 1;

        public const uint SNMPAPI_ERROR = 0;

        public const uint SNMP_OUTPUT_TO_EVENTLOG = 0x4;

        public const uint DEFAULT_SNMP_PORT_UDP = 161;

        public const uint DEFAULT_SNMP_PORT_IPX = 36879;

        public const uint DEFAULT_SNMPTRAP_PORT_UDP = 162;

        public const uint DEFAULT_SNMPTRAP_PORT_IPX = 36880;

        public const uint SNMP_MAX_OID_LEN = 128;

        public const uint SNMP_MEM_ALLOC_ERROR = 1;

        public const uint SNMP_BERAPI_INVALID_LENGTH = 10;

        public const uint SNMP_BERAPI_INVALID_TAG = 11;

        public const uint SNMP_BERAPI_OVERFLOW = 12;

        public const uint SNMP_BERAPI_SHORT_BUFFER = 13;

        public const uint SNMP_BERAPI_INVALID_OBJELEM = 14;

        public const uint SNMP_PDUAPI_UNRECOGNIZED_PDU = 20;

        public const uint SNMP_PDUAPI_INVALID_ES = 21;

        public const uint SNMP_PDUAPI_INVALID_GT = 22;

        public const uint SNMP_AUTHAPI_INVALID_VERSION = 30;

        public const uint SNMP_AUTHAPI_INVALID_MSG_TYPE = 31;

        public const uint SNMP_AUTHAPI_TRIV_AUTH_FAILED = 32;

        public const uint SNMP_MGMTAPI_TIMEOUT = 40;

        public const uint SNMP_MGMTAPI_SELECT_FDERRORS = 41;

        public const uint SNMP_MGMTAPI_TRAP_ERRORS = 42;

        public const uint SNMP_MGMTAPI_TRAP_DUPINIT = 43;

        public const uint SNMP_MGMTAPI_NOTRAPS = 44;

        public const uint SNMP_MGMTAPI_AGAIN = 45;

        public const uint SNMP_MGMTAPI_INVALID_CTL = 46;

        public const uint SNMP_MGMTAPI_INVALID_SESSION = 47;

        public const uint SNMP_MGMTAPI_INVALID_BUFFER = 48;

        public const uint MGMCTL_SETAGENTPORT = 0x01;

        public const uint MAXOBJIDSIZE = 128;

        public const uint MAXOBJIDSTRSIZE = 1408;

        public const uint SNMPLISTEN_USEENTITY_ADDR = 0;

        public const uint SNMPLISTEN_ALL_ADDR = 1;

        public const uint SNMP_TRAP_COLDSTART = 0;

        public const uint SNMP_TRAP_WARMSTART = 1;

        public const uint SNMP_TRAP_LINKDOWN = 2;

        public const uint SNMP_TRAP_LINKUP = 3;

        public const uint SNMP_TRAP_AUTHFAIL = 4;

        public const uint SNMP_TRAP_EGPNEIGHBORLOSS = 5;

        public const uint SNMP_TRAP_ENTERPRISESPECIFIC = 6;

        public const uint SNMPAPI_NO_SUPPORT = 0;

        public const uint SNMPAPI_V1_SUPPORT = 1;

        public const uint SNMPAPI_V2_SUPPORT = 2;

        public const uint SNMPAPI_M2M_SUPPORT = 3;

        public const uint SNMPAPI_FAILURE = 0;

        public const uint SNMPAPI_SUCCESS = 1;

        public const uint SNMPAPI_ALLOC_ERROR = 2;

        public const uint SNMPAPI_CONTEXT_INVALID = 3;

        public const uint SNMPAPI_CONTEXT_UNKNOWN = 4;

        public const uint SNMPAPI_ENTITY_INVALID = 5;

        public const uint SNMPAPI_ENTITY_UNKNOWN = 6;

        public const uint SNMPAPI_INDEX_INVALID = 7;

        public const uint SNMPAPI_NOOP = 8;

        public const uint SNMPAPI_OID_INVALID = 9;

        public const uint SNMPAPI_OPERATION_INVALID = 10;

        public const uint SNMPAPI_OUTPUT_TRUNCATED = 11;

        public const uint SNMPAPI_PDU_INVALID = 12;

        public const uint SNMPAPI_SESSION_INVALID = 13;

        public const uint SNMPAPI_SYNTAX_INVALID = 14;

        public const uint SNMPAPI_VBL_INVALID = 15;

        public const uint SNMPAPI_MODE_INVALID = 16;

        public const uint SNMPAPI_SIZE_INVALID = 17;

        public const uint SNMPAPI_NOT_INITIALIZED = 18;

        public const uint SNMPAPI_MESSAGE_INVALID = 19;

        public const uint SNMPAPI_HWND_INVALID = 20;

        public const uint SNMPAPI_OTHER_ERROR = 99;

        public const uint SNMPAPI_TL_NOT_INITIALIZED = 100;

        public const uint SNMPAPI_TL_NOT_SUPPORTED = 101;

        public const uint SNMPAPI_TL_NOT_AVAILABLE = 102;

        public const uint SNMPAPI_TL_RESOURCE_ERROR = 103;

        public const uint SNMPAPI_TL_UNDELIVERABLE = 104;

        public const uint SNMPAPI_TL_SRC_INVALID = 105;

        public const uint SNMPAPI_TL_INVALID_PARAM = 106;

        public const uint SNMPAPI_TL_IN_USE = 107;

        public const uint SNMPAPI_TL_TIMEOUT = 108;

        public const uint SNMPAPI_TL_PDU_TOO_BIG = 109;

        public const uint SNMPAPI_TL_OTHER = 199;

        public const uint MAXVENDORINFO = 32;

    }
}

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


using static Windows.Win32.NetworkManagement.Snmp.Apis;

namespace Windows.Win32.NetworkManagement.Snmp
{
    public enum SNMP_PDU_TYPE : uint
    {
        SNMP_PDU_GET = (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x0),
        SNMP_PDU_GETNEXT = (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x1),
        SNMP_PDU_RESPONSE = (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x2),
        SNMP_PDU_SET = (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x3),
        SNMP_PDU_GETBULK = (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x5),
        SNMP_PDU_TRAP = (ASN_CONTEXT | ASN_CONSTRUCTOR | 0x7),
    }

    public enum SNMP_EXTENSION_REQUEST_TYPE : uint
    {
        SNMP_EXTENSION_GET = SNMP_PDU_TYPE.SNMP_PDU_GET,
        SNMP_EXTENSION_GET_NEXT = SNMP_PDU_TYPE.SNMP_PDU_GETNEXT,
        SNMP_EXTENSION_SET_TEST = (ASN_PRIVATE | ASN_CONSTRUCTOR | 0x0),
        SNMP_EXTENSION_SET_COMMIT = SNMP_PDU_TYPE.SNMP_PDU_SET,
        SNMP_EXTENSION_SET_UNDO = (ASN_PRIVATE | ASN_CONSTRUCTOR | 0x1),
        SNMP_EXTENSION_SET_CLEANUP = (ASN_PRIVATE | ASN_CONSTRUCTOR | 0x2),
    }

    public enum SNMP_API_TRANSLATE_MODE : uint
    {
        SNMPAPI_TRANSLATED = 0,
        SNMPAPI_UNTRANSLATED_V1 = 1,
        SNMPAPI_UNTRANSLATED_V2 = 2,
    }

    public enum SNMP_GENERICTRAP : uint
    {
        SNMP_GENERICTRAP_COLDSTART = 0,
        SNMP_GENERICTRAP_WARMSTART = 1,
        SNMP_GENERICTRAP_LINKDOWN = 2,
        SNMP_GENERICTRAP_LINKUP = 3,
        SNMP_GENERICTRAP_AUTHFAILURE = 4,
        SNMP_GENERICTRAP_EGPNEIGHLOSS = 5,
        SNMP_GENERICTRAP_ENTERSPECIFIC = 6,
    }

    public enum SNMP_ERROR_STATUS : uint
    {
        SNMP_ERRORSTATUS_NOERROR = 0,
        SNMP_ERRORSTATUS_TOOBIG = 1,
        SNMP_ERRORSTATUS_NOSUCHNAME = 2,
        SNMP_ERRORSTATUS_BADVALUE = 3,
        SNMP_ERRORSTATUS_READONLY = 4,
        SNMP_ERRORSTATUS_GENERR = 5,
        SNMP_ERRORSTATUS_NOACCESS = 6,
        SNMP_ERRORSTATUS_WRONGTYPE = 7,
        SNMP_ERRORSTATUS_WRONGLENGTH = 8,
        SNMP_ERRORSTATUS_WRONGENCODING = 9,
        SNMP_ERRORSTATUS_WRONGVALUE = 10,
        SNMP_ERRORSTATUS_NOCREATION = 11,
        SNMP_ERRORSTATUS_INCONSISTENTVALUE = 12,
        SNMP_ERRORSTATUS_RESOURCEUNAVAILABLE = 13,
        SNMP_ERRORSTATUS_COMMITFAILED = 14,
        SNMP_ERRORSTATUS_UNDOFAILED = 15,
        SNMP_ERRORSTATUS_AUTHORIZATIONERROR = 16,
        SNMP_ERRORSTATUS_NOTWRITABLE = 17,
        SNMP_ERRORSTATUS_INCONSISTENTNAME = 18,
    }

    public enum SNMP_STATUS : uint
    {
        SNMPAPI_ON = 1,
        SNMPAPI_OFF = 0,
    }

    public enum SNMP_OUTPUT_LOG_TYPE : uint
    {
        SNMP_OUTPUT_TO_CONSOLE = 0x1,
        SNMP_OUTPUT_TO_LOGFILE = 0x2,
        SNMP_OUTPUT_TO_DEBUGGER = 0x8,
    }

    public enum SNMP_LOG : uint
    {
        SNMP_LOG_SILENT = 0x0,
        SNMP_LOG_FATAL = 0x1,
        SNMP_LOG_ERROR = 0x2,
        SNMP_LOG_WARNING = 0x3,
        SNMP_LOG_TRACE = 0x4,
        SNMP_LOG_VERBOSE = 0x5,
    }

    public enum SNMP_ERROR : uint
    {
        SNMP_ERROR_NOERROR = 0,
        SNMP_ERROR_TOOBIG = 1,
        SNMP_ERROR_NOSUCHNAME = 2,
        SNMP_ERROR_BADVALUE = 3,
        SNMP_ERROR_READONLY = 4,
        SNMP_ERROR_GENERR = 5,
        SNMP_ERROR_NOACCESS = 6,
        SNMP_ERROR_WRONGTYPE = 7,
        SNMP_ERROR_WRONGLENGTH = 8,
        SNMP_ERROR_WRONGENCODING = 9,
        SNMP_ERROR_WRONGVALUE = 10,
        SNMP_ERROR_NOCREATION = 11,
        SNMP_ERROR_INCONSISTENTVALUE = 12,
        SNMP_ERROR_RESOURCEUNAVAILABLE = 13,
        SNMP_ERROR_COMMITFAILED = 14,
        SNMP_ERROR_UNDOFAILED = 15,
        SNMP_ERROR_AUTHORIZATIONERROR = 16,
        SNMP_ERROR_NOTWRITABLE = 17,
        SNMP_ERROR_INCONSISTENTNAME = 18,
    }

}

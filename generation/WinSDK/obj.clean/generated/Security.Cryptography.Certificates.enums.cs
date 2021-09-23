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


using static Windows.Win32.Security.Cryptography.Certificates.Apis;

namespace Windows.Win32.Security.Cryptography.Certificates
{
    public enum CERT_RDN_ATTR_VALUE_TYPE : uint
    {
        CERT_RDN_ANY_TYPE = 0,
        CERT_RDN_NUMERIC_STRING = 3,
        CERT_RDN_PRINTABLE_STRING = 4,
        CERT_RDN_T61_STRING = 5,
        CERT_RDN_VIDEOTEX_STRING = 6,
        CERT_RDN_IA5_STRING = 7,
        CERT_RDN_GRAPHIC_STRING = 8,
        CERT_RDN_ISO646_STRING = 9,
        CERT_RDN_GENERAL_STRING = 10,
        CERT_RDN_INT4_STRING = 11,
        CERT_RDN_UNICODE_STRING = 12,
        CERT_RDN_BMP_STRING = 12,
        CERT_RDN_ENCODED_BLOB = 1,
        CERT_RDN_OCTET_STRING = 2,
        CERT_RDN_TELETEX_STRING = 5,
        CERT_RDN_UNIVERSAL_STRING = 11,
        CERT_RDN_UTF8_STRING = 13,
        CERT_RDN_VISIBLE_STRING = 9,
    }

    public enum CERT_VIEW_COLUMN_INDEX
    {
        CV_COLUMN_LOG_DEFAULT = -2,
        CV_COLUMN_LOG_FAILED_DEFAULT = -3,
        CV_COLUMN_QUEUE_DEFAULT = -1,
    }

    public enum CERT_DELETE_ROW_FLAGS : uint
    {
        CDR_EXPIRED = 1,
        CDR_REQUEST_LAST_CHANGED = 2,
    }

    public enum FULL_RESPONSE_PROPERTY_ID : uint
    {
        FR_PROP_NONE = 0,
        FR_PROP_FULLRESPONSE = 1,
        FR_PROP_STATUSINFOCOUNT = 2,
        FR_PROP_BODYPARTSTRING = 3,
        FR_PROP_STATUS = 4,
        FR_PROP_STATUSSTRING = 5,
        FR_PROP_OTHERINFOCHOICE = 6,
        FR_PROP_FAILINFO = 7,
        FR_PROP_PENDINFOTOKEN = 8,
        FR_PROP_PENDINFOTIME = 9,
        FR_PROP_ISSUEDCERTIFICATEHASH = 10,
        FR_PROP_ISSUEDCERTIFICATE = 11,
        FR_PROP_ISSUEDCERTIFICATECHAIN = 12,
        FR_PROP_ISSUEDCERTIFICATECRLCHAIN = 13,
        FR_PROP_ENCRYPTEDKEYHASH = 14,
        FR_PROP_FULLRESPONSENOPKCS7 = 15,
        FR_PROP_CAEXCHANGECERTIFICATEHASH = 16,
        FR_PROP_CAEXCHANGECERTIFICATE = 17,
        FR_PROP_CAEXCHANGECERTIFICATECHAIN = 18,
        FR_PROP_CAEXCHANGECERTIFICATECRLCHAIN = 19,
        FR_PROP_ATTESTATIONCHALLENGE = 20,
        FR_PROP_ATTESTATIONPROVIDERNAME = 21,
    }

    public enum CVRC_COLUMN : uint
    {
        CVRC_COLUMN_SCHEMA = 0,
        CVRC_COLUMN_RESULT = 0x1,
        CVRC_COLUMN_VALUE = 0x2,
        CVRC_COLUMN_MASK = 0xfff,
    }

    public enum CERT_IMPORT_FLAGS : uint
    {
        CR_IN_BASE64HEADER = 0,
        CR_IN_BASE64 = 0x1,
        CR_IN_BINARY = 0x2,
    }

    public enum CERT_GET_CONFIG_FLAGS : uint
    {
        CC_DEFAULTCONFIG = 0,
        CC_FIRSTCONFIG = 2,
        CC_LOCALACTIVECONFIG = 4,
        CC_LOCALCONFIG = 3,
        CC_UIPICKCONFIG = 1,
        CC_UIPICKCONFIGSKIPLOCALCA_ = 5,
    }

    public enum ENUM_CERT_COLUMN_VALUE_FLAGS : uint
    {
        CV_OUT_BASE64 = 0x1,
        CV_OUT_BASE64HEADER = 0,
        CV_OUT_BASE64REQUESTHEADER = 0x3,
        CV_OUT_BASE64X509CRLHEADER = 0x9,
        CV_OUT_BINARY = 0x2,
        CV_OUT_HEX = 0x4,
        CV_OUT_HEXADDR = 0xa,
        CV_OUT_HEXASCII = 0x5,
        CV_OUT_HEXASCIIADDR = 0xb,
    }

    public enum PENDING_REQUEST_DESIRED_PROPERTY : uint
    {
        XEPR_CADNS = 0x01,
        XEPR_CAFRIENDLYNAME = 0x03,
        XEPR_CANAME = 0x02,
        XEPR_HASH = 0x08,
        XEPR_REQUESTID = 0x04,
    }

    [Flags]
    public enum CERTADMIN_GET_ROLES_FLAGS : uint
    {
        CA_ACCESS_ADMIN = 1,
        CA_ACCESS_AUDITOR = 4,
        CA_ACCESS_ENROLL = 512,
        CA_ACCESS_OFFICER = 2,
        CA_ACCESS_OPERATOR = 8,
        CA_ACCESS_READ = 256,
    }

    public enum CR_DISP : uint
    {
        CR_DISP_DENIED = 0x2,
        CR_DISP_ERROR = 0x1,
        CR_DISP_INCOMPLETE = 0,
        CR_DISP_ISSUED = 0x3,
        CR_DISP_ISSUED_OUT_OF_BAND = 0x4,
        CR_DISP_UNDER_SUBMISSION = 0x5,
    }

    public enum XEKL_KEYSIZE : uint
    {
        XEKL_KEYSIZE_MIN = 0x1,
        XEKL_KEYSIZE_MAX = 0x2,
        XEKL_KEYSIZE_INC = 0x3,
    }

    public enum CERT_CREATE_REQUEST_FLAGS : uint
    {
        XECR_CMC = 0x3,
        XECR_PKCS10_V1_5 = 0x4,
        XECR_PKCS10_V2_0 = 0x1,
        XECR_PKCS7 = 0x2,
    }

    [Flags]
    public enum CERT_EXIT_EVENT_MASK : uint
    {
        EXITEVENT_CERTDENIED = 0x4,
        EXITEVENT_CERTISSUED = 0x1,
        EXITEVENT_CERTPENDING = 0x2,
        EXITEVENT_CERTRETRIEVEPENDING = 0x10,
        EXITEVENT_CERTREVOKED = 0x8,
        EXITEVENT_CRLISSUED = 0x20,
        EXITEVENT_SHUTDOWN = 0x40,
    }

    public enum ADDED_CERT_TYPE : uint
    {
        XECT_EXTENSION_V1 = 0x1,
        XECT_EXTENSION_V2 = 0x2,
    }

    public enum CVRC_TABLE : uint
    {
        CVRC_TABLE_ATTRIBUTES = 0x4000,
        CVRC_TABLE_CRL = 0x5000,
        CVRC_TABLE_EXTENSIONS = 0x3000,
        CVRC_TABLE_REQCERT = 0,
    }

    public enum CERT_PROPERTY_TYPE : uint
    {
        PROPTYPE_BINARY = 3,
        PROPTYPE_DATE = 2,
        PROPTYPE_LONG = 1,
        PROPTYPE_STRING = 4,
    }

    public enum CERT_ALT_NAME : uint
    {
        CERT_ALT_NAME_RFC822_NAME = 2,
        CERT_ALT_NAME_DNS_NAME = 3,
        CERT_ALT_NAME_URL = 7,
        CERT_ALT_NAME_REGISTERED_ID = 9,
        CERT_ALT_NAME_DIRECTORY_NAME = 5,
        CERT_ALT_NAME_IP_ADDRESS = 8,
        CERT_ALT_NAME_OTHER_NAME = 1,
    }

    public enum CSBACKUP_TYPE : uint
    {
        CSBACKUP_TYPE_FULL = 0x00000001,
        CSBACKUP_TYPE_LOGS_ONLY = 0x00000002,
    }

    public enum XEKL_KEYSPEC : uint
    {
        XEKL_KEYSPEC_KEYX = 0x1,
        XEKL_KEYSPEC_SIG = 0x2,
    }

    public enum CERT_REQUEST_OUT_TYPE : uint
    {
        CR_OUT_BASE64HEADER = 0,
        CR_OUT_BASE64 = 1,
        CR_OUT_BINARY = 2,
    }

    public enum CERT_VIEW_SEEK_OPERATOR_FLAGS : uint
    {
        CVR_SEEK_EQ = 0x1,
        CVR_SEEK_LE = 0x4,
        CVR_SEEK_LT = 0x2,
        CVR_SEEK_GE = 0x8,
        CVR_SEEK_GT = 0x10,
    }

}

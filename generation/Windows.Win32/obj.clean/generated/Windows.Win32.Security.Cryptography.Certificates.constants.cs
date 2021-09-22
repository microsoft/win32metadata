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


namespace Windows.Win32.Security.Cryptography.Certificates
{
    public static partial class Apis
    {
        public const uint CA_DISP_INCOMPLETE = 0;

        public const uint CA_DISP_ERROR = 0x1;

        public const uint CA_DISP_REVOKED = 0x2;

        public const uint CA_DISP_VALID = 0x3;

        public const uint CA_DISP_INVALID = 0x4;

        public const uint CA_DISP_UNDER_SUBMISSION = 0x5;

        public const uint KRA_DISP_EXPIRED = 0;

        public const uint KRA_DISP_NOTFOUND = 0x1;

        public const uint KRA_DISP_REVOKED = 0x2;

        public const uint KRA_DISP_VALID = 0x3;

        public const uint KRA_DISP_INVALID = 0x4;

        public const uint KRA_DISP_UNTRUSTED = 0x5;

        public const uint KRA_DISP_NOTLOADED = 0x6;

        public const uint CA_ACCESS_MASKROLES = 0xff;

        public const uint CA_CRL_BASE = 0x1;

        public const uint CA_CRL_DELTA = 0x2;

        public const uint CA_CRL_REPUBLISH = 0x10;

        public const uint ICF_ALLOWFOREIGN = 0x10000;

        public const uint ICF_EXISTINGROW = 0x20000;

        public const uint IKF_OVERWRITE = 0x10000;

        public const uint CSBACKUP_TYPE_MASK = 0x00000003;

        public const uint CSRESTORE_TYPE_FULL = 0x00000001;

        public const uint CSRESTORE_TYPE_ONLINE = 0x00000002;

        public const uint CSRESTORE_TYPE_CATCHUP = 0x00000004;

        public const uint CSRESTORE_TYPE_MASK = 0x00000005;

        public const uint CSBACKUP_DISABLE_INCREMENTAL = 0xffffffff;

        public const uint CSBFT_DIRECTORY = 0x80;

        public const uint CSBFT_DATABASE_DIRECTORY = 0x40;

        public const uint CSBFT_LOG_DIRECTORY = 0x20;

        public const ulong CSCONTROL_SHUTDOWN = 0x000000001;

        public const ulong CSCONTROL_SUSPEND = 0x000000002;

        public const ulong CSCONTROL_RESTART = 0x000000003;

        public const uint CAIF_DSENTRY = 0x1;

        public const uint CAIF_SHAREDFOLDERENTRY = 0x2;

        public const uint CAIF_REGISTRY = 0x4;

        public const uint CAIF_LOCAL = 0x8;

        public const uint CAIF_REGISTRYPARENT = 0x10;

        public const uint CR_IN_ENCODEANY = 0xff;

        public const uint CR_IN_ENCODEMASK = 0xff;

        public const uint CR_IN_FORMATANY = 0;

        public const uint CR_IN_PKCS10 = 0x100;

        public const uint CR_IN_KEYGEN = 0x200;

        public const uint CR_IN_PKCS7 = 0x300;

        public const uint CR_IN_CMC = 0x400;

        public const uint CR_IN_CHALLENGERESPONSE = 0x500;

        public const uint CR_IN_SIGNEDCERTIFICATETIMESTAMPLIST = 0x600;

        public const uint CR_IN_FORMATMASK = 0xff00;

        public const uint CR_IN_SCEP = 0x10000;

        public const uint CR_IN_RPC = 0x20000;

        public const uint CR_IN_HTTP = 0x30000;

        public const uint CR_IN_FULLRESPONSE = 0x40000;

        public const uint CR_IN_CRLS = 0x80000;

        public const uint CR_IN_MACHINE = 0x100000;

        public const uint CR_IN_ROBO = 0x200000;

        public const uint CR_IN_CLIENTIDNONE = 0x400000;

        public const uint CR_IN_CONNECTONLY = 0x800000;

        public const uint CR_IN_RETURNCHALLENGE = 0x1000000;

        public const uint CR_IN_SCEPPOST = 0x2000000;

        public const uint CR_IN_CERTIFICATETRANSPARENCY = 0x4000000;

        public const uint CC_UIPICKCONFIGSKIPLOCALCA = 0x5;

        public const uint CR_DISP_REVOKED = 0x6;

        public const uint CR_OUT_BASE64REQUESTHEADER = 0x3;

        public const uint CR_OUT_HEX = 0x4;

        public const uint CR_OUT_HEXASCII = 0x5;

        public const uint CR_OUT_BASE64X509CRLHEADER = 0x9;

        public const uint CR_OUT_HEXADDR = 0xa;

        public const uint CR_OUT_HEXASCIIADDR = 0xb;

        public const uint CR_OUT_HEXRAW = 0xc;

        public const uint CR_OUT_ENCODEMASK = 0xff;

        public const uint CR_OUT_CHAIN = 0x100;

        public const uint CR_OUT_CRLS = 0x200;

        public const uint CR_OUT_NOCRLF = 0x40000000;

        public const uint CR_OUT_NOCR = 0x80000000;

        public const uint CR_GEMT_DEFAULT = 0;

        public const uint CR_GEMT_HRESULT_STRING = 0x1;

        public const uint CR_GEMT_HTTP_ERROR = 0x2;

        public const uint CR_PROP_NONE = 0;

        public const uint CR_PROP_FILEVERSION = 1;

        public const uint CR_PROP_PRODUCTVERSION = 2;

        public const uint CR_PROP_EXITCOUNT = 3;

        public const uint CR_PROP_EXITDESCRIPTION = 4;

        public const uint CR_PROP_POLICYDESCRIPTION = 5;

        public const uint CR_PROP_CANAME = 6;

        public const uint CR_PROP_SANITIZEDCANAME = 7;

        public const uint CR_PROP_SHAREDFOLDER = 8;

        public const uint CR_PROP_PARENTCA = 9;

        public const uint CR_PROP_CATYPE = 10;

        public const uint CR_PROP_CASIGCERTCOUNT = 11;

        public const uint CR_PROP_CASIGCERT = 12;

        public const uint CR_PROP_CASIGCERTCHAIN = 13;

        public const uint CR_PROP_CAXCHGCERTCOUNT = 14;

        public const uint CR_PROP_CAXCHGCERT = 15;

        public const uint CR_PROP_CAXCHGCERTCHAIN = 16;

        public const uint CR_PROP_BASECRL = 17;

        public const uint CR_PROP_DELTACRL = 18;

        public const uint CR_PROP_CACERTSTATE = 19;

        public const uint CR_PROP_CRLSTATE = 20;

        public const uint CR_PROP_CAPROPIDMAX = 21;

        public const uint CR_PROP_DNSNAME = 22;

        public const uint CR_PROP_ROLESEPARATIONENABLED = 23;

        public const uint CR_PROP_KRACERTUSEDCOUNT = 24;

        public const uint CR_PROP_KRACERTCOUNT = 25;

        public const uint CR_PROP_KRACERT = 26;

        public const uint CR_PROP_KRACERTSTATE = 27;

        public const uint CR_PROP_ADVANCEDSERVER = 28;

        public const uint CR_PROP_TEMPLATES = 29;

        public const uint CR_PROP_BASECRLPUBLISHSTATUS = 30;

        public const uint CR_PROP_DELTACRLPUBLISHSTATUS = 31;

        public const uint CR_PROP_CASIGCERTCRLCHAIN = 32;

        public const uint CR_PROP_CAXCHGCERTCRLCHAIN = 33;

        public const uint CR_PROP_CACERTSTATUSCODE = 34;

        public const uint CR_PROP_CAFORWARDCROSSCERT = 35;

        public const uint CR_PROP_CABACKWARDCROSSCERT = 36;

        public const uint CR_PROP_CAFORWARDCROSSCERTSTATE = 37;

        public const uint CR_PROP_CABACKWARDCROSSCERTSTATE = 38;

        public const uint CR_PROP_CACERTVERSION = 39;

        public const uint CR_PROP_SANITIZEDCASHORTNAME = 40;

        public const uint CR_PROP_CERTCDPURLS = 41;

        public const uint CR_PROP_CERTAIAURLS = 42;

        public const uint CR_PROP_CERTAIAOCSPURLS = 43;

        public const uint CR_PROP_LOCALENAME = 44;

        public const uint CR_PROP_SUBJECTTEMPLATE_OIDS = 45;

        public const uint CR_PROP_SCEPSERVERCERTS = 1000;

        public const uint CR_PROP_SCEPSERVERCAPABILITIES = 1001;

        public const uint CR_PROP_SCEPSERVERCERTSCHAIN = 1002;

        public const uint FR_PROP_CLAIMCHALLENGE = 22;

        public const uint EAN_NAMEOBJECTID = 0x80000000;

        public const uint EANR_SUPPRESS_IA5CONVERSION = 0x80000000;

        public const uint CERTENROLL_INDEX_BASE = 0;

        public const uint EXITEVENT_INVALID = 0x0;

        public const uint EXITEVENT_STARTUP = 0x80;

        public const uint EXITEVENT_CERTIMPORTED = 0x200;

        public const uint ENUMEXT_OBJECTID = 0x1;

        public const uint CMM_REFRESHONLY = 0x1;

        public const uint CMM_READONLY = 0x2;

        public const uint DBSESSIONCOUNTDEFAULT = 100;

        public const uint DBFLAGS_READONLY = 0x00000001;

        public const uint DBFLAGS_CREATEIFNEEDED = 0x00000002;

        public const uint DBFLAGS_CIRCULARLOGGING = 0x00000004;

        public const uint DBFLAGS_LAZYFLUSH = 0x00000008;

        public const uint DBFLAGS_MAXCACHESIZEX100 = 0x00000010;

        public const uint DBFLAGS_CHECKPOINTDEPTH60MB = 0x00000020;

        public const uint DBFLAGS_LOGBUFFERSLARGE = 0x00000040;

        public const uint DBFLAGS_LOGBUFFERSHUGE = 0x00000080;

        public const uint DBFLAGS_LOGFILESIZE16MB = 0x00000100;

        public const uint DBFLAGS_MULTITHREADTRANSACTIONS = 0x00000200;

        public const uint DBFLAGS_DISABLESNAPSHOTBACKUP = 0x00000400;

        public const uint DBFLAGS_ENABLEVOLATILEREQUESTS = 0X00000800;

        public const uint LDAPF_SSLENABLE = 0x00000001;

        public const uint LDAPF_SIGNDISABLE = 0x00000002;

        public const uint CSVER_MAJOR_WIN2K = 1;

        public const uint CSVER_MINOR_WIN2K = 1;

        public const uint CSVER_MAJOR_WHISTLER = 2;

        public const uint CSVER_MINOR_WHISTLER_BETA2 = 1;

        public const uint CSVER_MINOR_WHISTLER_BETA3 = 2;

        public const uint CSVER_MAJOR_LONGHORN = 3;

        public const uint CSVER_MINOR_LONGHORN_BETA1 = 1;

        public const uint CSVER_MAJOR_WIN7 = 4;

        public const uint CSVER_MINOR_WIN7 = 1;

        public const uint CSVER_MAJOR_WIN8 = 5;

        public const uint CSVER_MINOR_WIN8 = 1;

        public const uint CSVER_MAJOR_WINBLUE = 6;

        public const uint CSVER_MINOR_WINBLUE = 1;

        public const uint CSVER_MAJOR_THRESHOLD = 7;

        public const uint CSVER_MINOR_THRESHOLD = 1;

        public const uint CCLOCKSKEWMINUTESDEFAULT = 10;

        public const uint CVIEWAGEMINUTESDEFAULT = 16;

        public const uint SETUP_SERVER_FLAG = 0x00000001;

        public const uint SETUP_CLIENT_FLAG = 0x00000002;

        public const uint SETUP_SUSPEND_FLAG = 0x00000004;

        public const uint SETUP_REQUEST_FLAG = 0x00000008;

        public const uint SETUP_ONLINE_FLAG = 0x00000010;

        public const uint SETUP_DENIED_FLAG = 0x00000020;

        public const uint SETUP_CREATEDB_FLAG = 0x00000040;

        public const uint SETUP_ATTEMPT_VROOT_CREATE = 0x00000080;

        public const uint SETUP_FORCECRL_FLAG = 0x00000100;

        public const uint SETUP_UPDATE_CAOBJECT_SVRTYPE = 0x00000200;

        public const uint SETUP_SERVER_UPGRADED_FLAG = 0x00000400;

        public const uint SETUP_W2K_SECURITY_NOT_UPGRADED_FLAG = 0x00000800;

        public const uint SETUP_SECURITY_CHANGED = 0x00001000;

        public const uint SETUP_DCOM_SECURITY_UPDATED_FLAG = 0x00002000;

        public const uint SETUP_SERVER_IS_UP_TO_DATE_FLAG = 0x00004000;

        public const uint CRLF_DELTA_USE_OLDEST_UNEXPIRED_BASE = 0x00000001;

        public const uint CRLF_DELETE_EXPIRED_CRLS = 0x00000002;

        public const uint CRLF_CRLNUMBER_CRITICAL = 0x00000004;

        public const uint CRLF_REVCHECK_IGNORE_OFFLINE = 0x00000008;

        public const uint CRLF_IGNORE_INVALID_POLICIES = 0x00000010;

        public const uint CRLF_REBUILD_MODIFIED_SUBJECT_ONLY = 0x00000020;

        public const uint CRLF_SAVE_FAILED_CERTS = 0x00000040;

        public const uint CRLF_IGNORE_UNKNOWN_CMC_ATTRIBUTES = 0x00000080;

        public const uint CRLF_IGNORE_CROSS_CERT_TRUST_ERROR = 0x00000100;

        public const uint CRLF_PUBLISH_EXPIRED_CERT_CRLS = 0x00000200;

        public const uint CRLF_ENFORCE_ENROLLMENT_AGENT = 0x00000400;

        public const uint CRLF_DISABLE_RDN_REORDER = 0x00000800;

        public const uint CRLF_DISABLE_ROOT_CROSS_CERTS = 0x00001000;

        public const uint CRLF_LOG_FULL_RESPONSE = 0x00002000;

        public const uint CRLF_USE_XCHG_CERT_TEMPLATE = 0x00004000;

        public const uint CRLF_USE_CROSS_CERT_TEMPLATE = 0x00008000;

        public const uint CRLF_ALLOW_REQUEST_ATTRIBUTE_SUBJECT = 0x00010000;

        public const uint CRLF_REVCHECK_IGNORE_NOREVCHECK = 0x00020000;

        public const uint CRLF_PRESERVE_EXPIRED_CA_CERTS = 0x00040000;

        public const uint CRLF_PRESERVE_REVOKED_CA_CERTS = 0x00080000;

        public const uint CRLF_DISABLE_CHAIN_VERIFICATION = 0x00100000;

        public const uint CRLF_BUILD_ROOTCA_CRLENTRIES_BASEDONKEY = 0x00200000;

        public const uint KRAF_ENABLEFOREIGN = 0x00000001;

        public const uint KRAF_SAVEBADREQUESTKEY = 0x00000002;

        public const uint KRAF_ENABLEARCHIVEALL = 0x00000004;

        public const uint KRAF_DISABLEUSEDEFAULTPROVIDER = 0x00000008;

        public const uint IF_LOCKICERTREQUEST = 0x00000001;

        public const uint IF_NOREMOTEICERTREQUEST = 0x00000002;

        public const uint IF_NOLOCALICERTREQUEST = 0x00000004;

        public const uint IF_NORPCICERTREQUEST = 0x00000008;

        public const uint IF_NOREMOTEICERTADMIN = 0x00000010;

        public const uint IF_NOLOCALICERTADMIN = 0x00000020;

        public const uint IF_NOREMOTEICERTADMINBACKUP = 0x00000040;

        public const uint IF_NOLOCALICERTADMINBACKUP = 0x00000080;

        public const uint IF_NOSNAPSHOTBACKUP = 0x00000100;

        public const uint IF_ENFORCEENCRYPTICERTREQUEST = 0x00000200;

        public const uint IF_ENFORCEENCRYPTICERTADMIN = 0x00000400;

        public const uint IF_ENABLEEXITKEYRETRIEVAL = 0x00000800;

        public const uint IF_ENABLEADMINASAUDITOR = 0x00001000;

        public const uint PROCFLG_NONE = 0x00;

        public const uint PROCFLG_ENFORCEGOODKEYS = 0x01;

        public const uint CSURL_SERVERPUBLISH = 0x00000001;

        public const uint CSURL_ADDTOCERTCDP = 0x00000002;

        public const uint CSURL_ADDTOFRESHESTCRL = 0x00000004;

        public const uint CSURL_ADDTOCRLCDP = 0x00000008;

        public const uint CSURL_PUBLISHRETRY = 0x00000010;

        public const uint CSURL_ADDTOCERTOCSP = 0x00000020;

        public const uint CSURL_SERVERPUBLISHDELTA = 0x00000040;

        public const uint CSURL_ADDTOIDP = 0x00000080;

        public const uint CAPATHLENGTH_INFINITE = 0xffffffff;

        public const uint REQDISP_PENDING = 0x00000000;

        public const uint REQDISP_ISSUE = 0x00000001;

        public const uint REQDISP_DENY = 0x00000002;

        public const uint REQDISP_USEREQUESTATTRIBUTE = 0x00000003;

        public const uint REQDISP_MASK = 0x000000ff;

        public const uint REQDISP_PENDINGFIRST = 0x00000100;

        public const uint REVEXT_CDPLDAPURL_OLD = 0x00000001;

        public const uint REVEXT_CDPHTTPURL_OLD = 0x00000002;

        public const uint REVEXT_CDPFTPURL_OLD = 0x00000004;

        public const uint REVEXT_CDPFILEURL_OLD = 0x00000008;

        public const uint REVEXT_CDPURLMASK_OLD = 0x000000ff;

        public const uint REVEXT_CDPENABLE = 0x00000100;

        public const uint REVEXT_ASPENABLE = 0x00000200;

        public const uint ISSCERT_LDAPURL_OLD = 0x00000001;

        public const uint ISSCERT_HTTPURL_OLD = 0x00000002;

        public const uint ISSCERT_FTPURL_OLD = 0x00000004;

        public const uint ISSCERT_FILEURL_OLD = 0x00000008;

        public const uint ISSCERT_URLMASK_OLD = 0x000000ff;

        public const uint ISSCERT_ENABLE = 0x00000100;

        public const uint EDITF_ENABLEREQUESTEXTENSIONS = 0x00000001;

        public const uint EDITF_REQUESTEXTENSIONLIST = 0x00000002;

        public const uint EDITF_DISABLEEXTENSIONLIST = 0x00000004;

        public const uint EDITF_ADDOLDKEYUSAGE = 0x00000008;

        public const uint EDITF_ADDOLDCERTTYPE = 0x00000010;

        public const uint EDITF_ATTRIBUTEENDDATE = 0x00000020;

        public const uint EDITF_BASICCONSTRAINTSCRITICAL = 0x00000040;

        public const uint EDITF_BASICCONSTRAINTSCA = 0x00000080;

        public const uint EDITF_ENABLEAKIKEYID = 0x00000100;

        public const uint EDITF_ATTRIBUTECA = 0x00000200;

        public const uint EDITF_IGNOREREQUESTERGROUP = 0x00000400;

        public const uint EDITF_ENABLEAKIISSUERNAME = 0x00000800;

        public const uint EDITF_ENABLEAKIISSUERSERIAL = 0x00001000;

        public const uint EDITF_ENABLEAKICRITICAL = 0x00002000;

        public const uint EDITF_SERVERUPGRADED = 0x00004000;

        public const uint EDITF_ATTRIBUTEEKU = 0x00008000;

        public const uint EDITF_ENABLEDEFAULTSMIME = 0x00010000;

        public const uint EDITF_EMAILOPTIONAL = 0x00020000;

        public const uint EDITF_ATTRIBUTESUBJECTALTNAME2 = 0x00040000;

        public const uint EDITF_ENABLELDAPREFERRALS = 0x00080000;

        public const uint EDITF_ENABLECHASECLIENTDC = 0x00100000;

        public const uint EDITF_AUDITCERTTEMPLATELOAD = 0x00200000;

        public const uint EDITF_DISABLEOLDOSCNUPN = 0x00400000;

        public const uint EDITF_DISABLELDAPPACKAGELIST = 0x00800000;

        public const uint EDITF_ENABLEUPNMAP = 0x01000000;

        public const uint EDITF_ENABLEOCSPREVNOCHECK = 0x02000000;

        public const uint EDITF_ENABLERENEWONBEHALFOF = 0x04000000;

        public const uint EDITF_ENABLEKEYENCIPHERMENTCACERT = 0x08000000;

        public const uint EXITPUB_FILE = 0x00000001;

        public const uint EXITPUB_ACTIVEDIRECTORY = 0x00000002;

        public const uint EXITPUB_REMOVEOLDCERTS = 0x00000010;

        public const uint TP_MACHINEPOLICY = 0x00000001;

        public const uint KR_ENABLE_MACHINE = 0x00000001;

        public const uint KR_ENABLE_USER = 0x00000002;

        public const uint EXTENSION_CRITICAL_FLAG = 0x00000001;

        public const uint EXTENSION_DISABLE_FLAG = 0x00000002;

        public const uint EXTENSION_DELETE_FLAG = 0x00000004;

        public const uint EXTENSION_POLICY_MASK = 0x0000ffff;

        public const uint EXTENSION_ORIGIN_REQUEST = 0x00010000;

        public const uint EXTENSION_ORIGIN_POLICY = 0x00020000;

        public const uint EXTENSION_ORIGIN_ADMIN = 0x00030000;

        public const uint EXTENSION_ORIGIN_SERVER = 0x00040000;

        public const uint EXTENSION_ORIGIN_RENEWALCERT = 0x00050000;

        public const uint EXTENSION_ORIGIN_IMPORTEDCERT = 0x00060000;

        public const uint EXTENSION_ORIGIN_PKCS7 = 0x00070000;

        public const uint EXTENSION_ORIGIN_CMC = 0x00080000;

        public const uint EXTENSION_ORIGIN_CACERT = 0x00090000;

        public const uint EXTENSION_ORIGIN_MASK = 0x000f0000;

        public const uint CPF_BASE = 0x00000001;

        public const uint CPF_DELTA = 0x00000002;

        public const uint CPF_COMPLETE = 0x00000004;

        public const uint CPF_SHADOW = 0x00000008;

        public const uint CPF_CASTORE_ERROR = 0x00000010;

        public const uint CPF_BADURL_ERROR = 0x00000020;

        public const uint CPF_MANUAL = 0x00000040;

        public const uint CPF_SIGNATURE_ERROR = 0x00000080;

        public const uint CPF_LDAP_ERROR = 0x00000100;

        public const uint CPF_FILE_ERROR = 0x00000200;

        public const uint CPF_FTP_ERROR = 0x00000400;

        public const uint CPF_HTTP_ERROR = 0x00000800;

        public const uint CPF_POSTPONED_BASE_LDAP_ERROR = 0x00001000;

        public const uint CPF_POSTPONED_BASE_FILE_ERROR = 0x00002000;

        public const uint PROPTYPE_MASK = 0x000000ff;

        public const uint PROPCALLER_SERVER = 0x00000100;

        public const uint PROPCALLER_POLICY = 0x00000200;

        public const uint PROPCALLER_EXIT = 0x00000300;

        public const uint PROPCALLER_ADMIN = 0x00000400;

        public const uint PROPCALLER_REQUEST = 0x00000500;

        public const uint PROPCALLER_MASK = 0x00000f00;

        public const uint PROPFLAGS_INDEXED = 0x00010000;

        public const uint CR_FLG_FORCETELETEX = 0x00000001;

        public const uint CR_FLG_RENEWAL = 0x00000002;

        public const uint CR_FLG_FORCEUTF8 = 0x00000004;

        public const uint CR_FLG_CAXCHGCERT = 0x00000008;

        public const uint CR_FLG_ENROLLONBEHALFOF = 0x00000010;

        public const uint CR_FLG_SUBJECTUNMODIFIED = 0x00000020;

        public const uint CR_FLG_VALIDENCRYPTEDKEYHASH = 0x00000040;

        public const uint CR_FLG_CACROSSCERT = 0x00000080;

        public const uint CR_FLG_ENFORCEUTF8 = 0x00000100;

        public const uint CR_FLG_DEFINEDCACERT = 0x00000200;

        public const uint CR_FLG_CHALLENGEPENDING = 0x00000400;

        public const uint CR_FLG_CHALLENGESATISFIED = 0x00000800;

        public const uint CR_FLG_TRUSTONUSE = 0x00001000;

        public const uint CR_FLG_TRUSTEKCERT = 0x00002000;

        public const uint CR_FLG_TRUSTEKKEY = 0x00004000;

        public const uint CR_FLG_PUBLISHERROR = 0x80000000;

        public const uint DB_DISP_ACTIVE = 8;

        public const uint DB_DISP_PENDING = 9;

        public const uint DB_DISP_QUEUE_MAX = 9;

        public const uint DB_DISP_FOREIGN = 12;

        public const uint DB_DISP_CA_CERT = 15;

        public const uint DB_DISP_CA_CERT_CHAIN = 16;

        public const uint DB_DISP_KRA_CERT = 17;

        public const uint DB_DISP_LOG_MIN = 20;

        public const uint DB_DISP_ISSUED = 20;

        public const uint DB_DISP_REVOKED = 21;

        public const uint DB_DISP_LOG_FAILED_MIN = 30;

        public const uint DB_DISP_ERROR = 30;

        public const uint DB_DISP_DENIED = 31;

        public const uint VR_PENDING = 0;

        public const uint VR_INSTANT_OK = 1;

        public const uint VR_INSTANT_BAD = 2;

        public const uint CV_OUT_HEXRAW = 0xc;

        public const uint CV_OUT_ENCODEMASK = 0xff;

        public const uint CV_OUT_NOCRLF = 0x40000000;

        public const uint CV_OUT_NOCR = 0x80000000;

        public const uint CVR_SEEK_NONE = 0;

        public const uint CVR_SEEK_MASK = 0xff;

        public const uint CVR_SEEK_NODELTA = 0x1000;

        public const uint CVR_SORT_NONE = 0;

        public const uint CVR_SORT_ASCEND = 0x1;

        public const uint CVR_SORT_DESCEND = 0x2;

        public const int CV_COLUMN_EXTENSION_DEFAULT = -4;

        public const int CV_COLUMN_ATTRIBUTE_DEFAULT = -5;

        public const int CV_COLUMN_CRL_DEFAULT = -6;

        public const int CV_COLUMN_LOG_REVOKED_DEFAULT = -7;

        public const uint CVRC_TABLE_MASK = 0xf000;

        public const uint CVRC_TABLE_SHIFT = 12;

        public const uint CRYPT_ENUM_ALL_PROVIDERS = 0x1;

        public const int XEPR_ENUM_FIRST = -1;

        public const uint XEPR_DATE = 0x05;

        public const uint XEPR_TEMPLATENAME = 0x06;

        public const uint XEPR_VERSION = 0x07;

        public const uint XEPR_V1TEMPLATENAME = 0x09;

        public const uint XEPR_V2TEMPLATEOID = 0x10;

        public const uint XEKL_KEYSIZE_DEFAULT = 0x4;

        public const uint XECP_STRING_PROPERTY = 0x1;

        public const uint XECI_DISABLE = 0x0;

        public const uint XECI_XENROLL = 0x1;

        public const uint XECI_AUTOENROLL = 0x2;

        public const uint XECI_REQWIZARD = 0x3;

        public const uint XECI_CERTREQ = 0x4;

    }
}

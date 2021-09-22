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


namespace Windows.Win32.Networking.ActiveDirectory
{
    public static partial class Apis
    {
        public const uint WM_ADSPROP_NOTIFY_PAGEINIT = WM_USER + 1101;

        public const uint WM_ADSPROP_NOTIFY_PAGEHWND = WM_USER + 1102;

        public const uint WM_ADSPROP_NOTIFY_CHANGE = WM_USER + 1103;

        public const uint WM_ADSPROP_NOTIFY_APPLY = WM_USER + 1104;

        public const uint WM_ADSPROP_NOTIFY_SETFOCUS = WM_USER + 1105;

        public const uint WM_ADSPROP_NOTIFY_FOREGROUND = WM_USER + 1106;

        public const uint WM_ADSPROP_NOTIFY_EXIT = WM_USER + 1107;

        public const uint WM_ADSPROP_NOTIFY_ERROR = WM_USER + 1110;

        public static readonly Guid CLSID_CommonQuery__scanned__ = new Guid(0x83bc5ec0, 0x6f2a, 0x11d0, 0xa1, 0xc4, 0x0, 0xaa, 0x00, 0xc1, 0x6e, 0x65);

        public const ulong QUERYFORM_CHANGESFORMLIST = 0x000000001;

        public const ulong QUERYFORM_CHANGESOPTFORMLIST = 0x000000002;

        public const uint CQFF_NOGLOBALPAGES = 0x0000001;

        public const uint CQFF_ISOPTIONAL = 0x0000002;

        public const uint CQPM_INITIALIZE = 0x00000001;

        public const uint CQPM_RELEASE = 0x00000002;

        public const uint CQPM_ENABLE = 0x00000003;

        public const uint CQPM_GETPARAMETERS = 0x00000005;

        public const uint CQPM_CLEARFORM = 0x00000006;

        public const uint CQPM_PERSIST = 0x00000007;

        public const uint CQPM_HELP = 0x00000008;

        public const uint CQPM_SETDEFAULTPARAMETERS = 0x00000009;

        public const uint CQPM_HANDLERSPECIFIC = 0x10000000;

        public const uint OQWF_OKCANCEL = 0x00000001;

        public const uint OQWF_DEFAULTFORM = 0x00000002;

        public const uint OQWF_SINGLESELECT = 0x00000004;

        public const uint OQWF_LOADQUERY = 0x00000008;

        public const uint OQWF_REMOVESCOPES = 0x00000010;

        public const uint OQWF_REMOVEFORMS = 0x00000020;

        public const uint OQWF_ISSUEONOPEN = 0x00000040;

        public const uint OQWF_SHOWOPTIONAL = 0x00000080;

        public const uint OQWF_SAVEQUERYONOK = 0x00000200;

        public const uint OQWF_HIDEMENUS = 0x00000400;

        public const uint OQWF_HIDESEARCHUI = 0x00000800;

        public const uint OQWF_PARAMISPROPERTYBAG = 0x80000000;

        public static readonly Guid CLSID_DsAdminCreateObj__scanned__ = new Guid(0xe301a009, 0xf901, 0x11d2, 0x82, 0xb9, 0x0, 0xc0, 0x4f, 0x68, 0x92, 0x8b);

        public static readonly Guid IID_IDsAdminCreateObj__scanned__ = new Guid(0x53554a38, 0xf902, 0x11d2, 0x82, 0xb9, 0x0, 0xc0, 0x4f, 0x68, 0x92, 0x8b);

        public static readonly Guid IID_IDsAdminNewObj__scanned__ = new Guid(0xf2573587, 0xe6fc, 0x11d2, 0x82, 0xaf, 0x0, 0xc0, 0x4f, 0x68, 0x92, 0x8b);

        public static readonly Guid IID_IDsAdminNewObjPrimarySite__scanned__ = new Guid(0xbe2b487e, 0xf904, 0x11d2, 0x82, 0xb9, 0x0, 0xc0, 0x4f, 0x68, 0x92, 0x8b);

        public static readonly Guid IID_IDsAdminNewObjExt__scanned__ = new Guid(0x6088eae2, 0xe7bf, 0x11d2, 0x82, 0xaf, 0x0, 0xc0, 0x4f, 0x68, 0x92, 0x8b);

        public static readonly Guid IID_IDsAdminNotifyHandler__scanned__ = new Guid(0xe4a2b8b3, 0x5a18, 0x11d2, 0x97, 0xc1, 0x0, 0xa0, 0xc9, 0xa0, 0x6d, 0x2d);

        public const uint DSA_NEWOBJ_CTX_PRECOMMIT = 0x00000001;

        public const uint DSA_NEWOBJ_CTX_COMMIT = 0x00000002;

        public const uint DSA_NEWOBJ_CTX_POSTCOMMIT = 0x00000003;

        public const uint DSA_NEWOBJ_CTX_CLEANUP = 0x00000004;

        public const uint DSA_NOTIFY_DEL = 0x00000001;

        public const uint DSA_NOTIFY_REN = 0x00000002;

        public const uint DSA_NOTIFY_MOV = 0x00000004;

        public const uint DSA_NOTIFY_PROP = 0x00000008;

        public const uint DSA_NOTIFY_FLAG_ADDITIONAL_DATA = 0x00000002;

        public const uint DSA_NOTIFY_FLAG_FORCE_ADDITIONAL_DATA = 0x00000001;

        public static readonly Guid CLSID_MicrosoftDS__scanned__ = new Guid(0xfe1290f0, 0xcfbd, 0x11cf, 0xa3, 0x30, 0x0, 0xaa, 0x0, 0xc1, 0x6e, 0x65);

        public static readonly Guid CLSID_DsPropertyPages__scanned__ = new Guid(0xd45d530,  0x764b, 0x11d0, 0xa1, 0xca, 0x0, 0xaa, 0x0, 0xc1, 0x6e, 0x65);

        public static readonly Guid CLSID_DsDomainTreeBrowser__scanned__ = new Guid(0x1698790a, 0xe2b4, 0x11d0, 0xb0, 0xb1, 0x00, 0xc0, 0x4f, 0xd8, 0xdc, 0xa6);

        public static readonly Guid CLSID_DsDisplaySpecifier__scanned__ = new Guid(0x1ab4a8c0, 0x6a0b, 0x11d2, 0xad, 0x49, 0x0, 0xc0, 0x4f, 0xa3, 0x1a, 0x86);

        public static readonly Guid CLSID_DsFolderProperties__scanned__ = new Guid(0x9e51e0d0, 0x6e0f, 0x11d2, 0x96, 0x1, 0x0, 0xc0, 0x4f, 0xa3, 0x1a, 0x86);

        public const uint DSOBJECT_ISCONTAINER = 0x00000001;

        public const uint DSOBJECT_READONLYPAGES = 0x80000000;

        public const uint DSPROVIDER_UNUSED_0 = 0x00000001;

        public const uint DSPROVIDER_UNUSED_1 = 0x00000002;

        public const uint DSPROVIDER_UNUSED_2 = 0x00000004;

        public const uint DSPROVIDER_UNUSED_3 = 0x00000008;

        public const uint DSPROVIDER_ADVANCED = 0x00000010;

        public const uint DSPROVIDER_AD_LDS = 0x00000020;

        public const uint DSDSOF_HASUSERANDSERVERINFO = 0x00000001;

        public const uint DSDSOF_SIMPLEAUTHENTICATE = 0x00000002;

        public const uint DSDSOF_DONTSIGNSEAL = 0x00000004;

        public const uint DSDSOF_DSAVAILABLE = 0x40000000;

        public const uint DBDTF_RETURNFQDN = 0x00000001;

        public const uint DBDTF_RETURNMIXEDDOMAINS = 0x00000002;

        public const uint DBDTF_RETURNEXTERNAL = 0x00000004;

        public const uint DBDTF_RETURNINBOUND = 0x00000008;

        public const uint DBDTF_RETURNINOUTBOUND = 0x00000010;

        public const uint DSSSF_SIMPLEAUTHENTICATE = 0x00000001;

        public const uint DSSSF_DONTSIGNSEAL = 0x00000002;

        public const uint DSSSF_DSAVAILABLE = 0x80000000;

        public const uint DSGIF_ISNORMAL = 0x0000000;

        public const uint DSGIF_ISOPEN = 0x0000001;

        public const uint DSGIF_ISDISABLED = 0x0000002;

        public const uint DSGIF_ISMASK = 0x000000f;

        public const uint DSGIF_GETDEFAULTICON = 0x0000010;

        public const uint DSGIF_DEFAULTISCONTAINER = 0x0000020;

        public const uint DSICCF_IGNORETREATASLEAF = 0x00000001;

        public const uint DSECAF_NOTLISTED = 0x00000001;

        public const uint DSCCIF_HASWIZARDDIALOG = 0x00000001;

        public const uint DSCCIF_HASWIZARDPRIMARYPAGE = 0x00000002;

        public const uint DSBI_NOBUTTONS = 0x00000001;

        public const uint DSBI_NOLINES = 0x00000002;

        public const uint DSBI_NOLINESATROOT = 0x00000004;

        public const uint DSBI_CHECKBOXES = 0x00000100;

        public const uint DSBI_NOROOT = 0x00010000;

        public const uint DSBI_INCLUDEHIDDEN = 0x00020000;

        public const uint DSBI_EXPANDONOPEN = 0x00040000;

        public const uint DSBI_ENTIREDIRECTORY = 0x00090000;

        public const uint DSBI_RETURN_FORMAT = 0x00100000;

        public const uint DSBI_HASCREDENTIALS = 0x00200000;

        public const uint DSBI_IGNORETREATASLEAF = 0x00400000;

        public const uint DSBI_SIMPLEAUTHENTICATE = 0x00800000;

        public const uint DSBI_RETURNOBJECTCLASS = 0x01000000;

        public const uint DSBI_DONTSIGNSEAL = 0x02000000;

        public const uint DSB_MAX_DISPLAYNAME_CHARS = 64;

        public const uint DSBF_STATE = 0x00000001;

        public const uint DSBF_ICONLOCATION = 0x00000002;

        public const uint DSBF_DISPLAYNAME = 0x00000004;

        public const uint DSBS_CHECKED = 0x00000001;

        public const uint DSBS_HIDDEN = 0x00000002;

        public const uint DSBS_ROOT = 0x00000004;

        public const uint DSBM_QUERYINSERTW = 100;

        public const uint DSBM_QUERYINSERTA = 101;

        public const uint DSBM_CHANGEIMAGESTATE = 102;

        public const uint DSBM_HELP = 103;

        public const uint DSBM_CONTEXTMENU = 104;

        public const uint DSBID_BANNER = 256;

        public const uint DSBID_CONTAINERLIST = 257;

        public const uint DS_FORCE_REDISCOVERY = 0x00000001;

        public const uint DS_DIRECTORY_SERVICE_REQUIRED = 0x00000010;

        public const uint DS_DIRECTORY_SERVICE_PREFERRED = 0x00000020;

        public const uint DS_GC_SERVER_REQUIRED = 0x00000040;

        public const uint DS_PDC_REQUIRED = 0x00000080;

        public const uint DS_BACKGROUND_ONLY = 0x00000100;

        public const uint DS_IP_REQUIRED = 0x00000200;

        public const uint DS_KDC_REQUIRED = 0x00000400;

        public const uint DS_TIMESERV_REQUIRED = 0x00000800;

        public const uint DS_WRITABLE_REQUIRED = 0x00001000;

        public const uint DS_GOOD_TIMESERV_PREFERRED = 0x00002000;

        public const uint DS_AVOID_SELF = 0x00004000;

        public const uint DS_ONLY_LDAP_NEEDED = 0x00008000;

        public const uint DS_IS_FLAT_NAME = 0x00010000;

        public const uint DS_IS_DNS_NAME = 0x00020000;

        public const uint DS_TRY_NEXTCLOSEST_SITE = 0x00040000;

        public const uint DS_DIRECTORY_SERVICE_6_REQUIRED = 0x00080000;

        public const uint DS_WEB_SERVICE_REQUIRED = 0x00100000;

        public const uint DS_DIRECTORY_SERVICE_8_REQUIRED = 0x00200000;

        public const uint DS_DIRECTORY_SERVICE_9_REQUIRED = 0x00400000;

        public const uint DS_DIRECTORY_SERVICE_10_REQUIRED = 0x00800000;

        public const uint DS_KEY_LIST_SUPPORT_REQUIRED = 0x01000000;

        public const uint DS_RETURN_DNS_NAME = 0x40000000;

        public const uint DS_RETURN_FLAT_NAME = 0x80000000;

        public const uint DS_PDC_FLAG = 0x00000001;

        public const uint DS_GC_FLAG = 0x00000004;

        public const uint DS_LDAP_FLAG = 0x00000008;

        public const uint DS_DS_FLAG = 0x00000010;

        public const uint DS_KDC_FLAG = 0x00000020;

        public const uint DS_TIMESERV_FLAG = 0x00000040;

        public const uint DS_CLOSEST_FLAG = 0x00000080;

        public const uint DS_WRITABLE_FLAG = 0x00000100;

        public const uint DS_GOOD_TIMESERV_FLAG = 0x00000200;

        public const uint DS_NDNC_FLAG = 0x00000400;

        public const uint DS_SELECT_SECRET_DOMAIN_6_FLAG = 0x00000800;

        public const uint DS_FULL_SECRET_DOMAIN_6_FLAG = 0x00001000;

        public const uint DS_WS_FLAG = 0x00002000;

        public const uint DS_DS_8_FLAG = 0x00004000;

        public const uint DS_DS_9_FLAG = 0x00008000;

        public const uint DS_DS_10_FLAG = 0x00010000;

        public const uint DS_KEY_LIST_FLAG = 0x00020000;

        public const uint DS_PING_FLAGS = 0x000FFFFF;

        public const uint DS_DNS_CONTROLLER_FLAG = 0x20000000;

        public const uint DS_DNS_DOMAIN_FLAG = 0x40000000;

        public const uint DS_DNS_FOREST_FLAG = 0x80000000;

        public const uint DS_DOMAIN_IN_FOREST = 0x0001;

        public const uint DS_DOMAIN_DIRECT_OUTBOUND = 0x0002;

        public const uint DS_DOMAIN_TREE_ROOT = 0x0004;

        public const uint DS_DOMAIN_PRIMARY = 0x0008;

        public const uint DS_DOMAIN_NATIVE_MODE = 0x0010;

        public const uint DS_DOMAIN_DIRECT_INBOUND = 0x0020;

        public const uint DS_GFTI_UPDATE_TDO = 0x1;

        public const uint DS_GFTI_VALID_FLAGS = 0x1;

        public const uint DS_ONLY_DO_SITE_NAME = 0x01;

        public const uint DS_NOTIFY_AFTER_SITE_RECORDS = 0x02;

        public static readonly Guid CLSID_DsQuery__scanned__ = new Guid(0x8a23e65e, 0x31c2, 0x11d0, 0x89, 0x1c, 0x0, 0xa0, 0x24, 0xab, 0x2d, 0xbb);

        public static readonly Guid CLSID_DsFindObjects__scanned__ = new Guid(0x83ee3fe1, 0x57d9, 0x11d0, 0xb9, 0x32, 0x0, 0xa0, 0x24, 0xab, 0x2d, 0xbb);

        public static readonly Guid CLSID_DsFindPeople__scanned__ = new Guid(0x83ee3fe2, 0x57d9, 0x11d0, 0xb9, 0x32, 0x0, 0xa0, 0x24, 0xab, 0x2d, 0xbb);

        public static readonly Guid CLSID_DsFindPrinter__scanned__ = new Guid(0xb577f070, 0x7ee2, 0x11d0, 0x91, 0x3f, 0x0, 0xaa, 0x0, 0xc1, 0x6e, 0x65);

        public static readonly Guid CLSID_DsFindComputer__scanned__ = new Guid(0x16006700, 0x87ad, 0x11d0, 0x91, 0x40, 0x0, 0xaa, 0x0, 0xc1, 0x6e, 0x65);

        public static readonly Guid CLSID_DsFindVolume__scanned__ = new Guid(0xc1b3cbf1, 0x886a, 0x11d0, 0x91, 0x40, 0x0, 0xaa, 0x0, 0xc1, 0x6e, 0x65);

        public static readonly Guid CLSID_DsFindContainer__scanned__ = new Guid(0xc1b3cbf2, 0x886a, 0x11d0, 0x91, 0x40, 0x0, 0xaa, 0x0, 0xc1, 0x6e, 0x65);

        public static readonly Guid CLSID_DsFindAdvanced__scanned__ = new Guid(0x83ee3fe3, 0x57d9, 0x11d0, 0xb9, 0x32, 0x0, 0xa0, 0x24, 0xab, 0x2d, 0xbb);

        public static readonly Guid CLSID_DsFindDomainController__scanned__ = new Guid(0x538c7b7e, 0xd25e, 0x11d0, 0x97, 0x42, 0x0, 0xa0, 0xc9, 0x6, 0xaf, 0x45);

        public static readonly Guid CLSID_DsFindWriteableDomainController__scanned__ = new Guid(0x7cbef079, 0xaa84, 0x444b, 0xbc, 0x70, 0x68, 0xe4, 0x12, 0x83, 0xea, 0xbc);

        public static readonly Guid CLSID_DsFindFrsMembers__scanned__ = new Guid(0x94ce4b18, 0xb3d3, 0x11d1, 0xb9, 0xb4, 0x0, 0xc0, 0x4f, 0xd8, 0xd5, 0xb0);

        public const uint DSQPF_NOSAVE = 0x00000001;

        public const uint DSQPF_SAVELOCATION = 0x00000002;

        public const uint DSQPF_SHOWHIDDENOBJECTS = 0x00000004;

        public const uint DSQPF_ENABLEADMINFEATURES = 0x00000008;

        public const uint DSQPF_ENABLEADVANCEDFEATURES = 0x00000010;

        public const uint DSQPF_HASCREDENTIALS = 0x00000020;

        public const uint DSQPF_NOCHOOSECOLUMNS = 0x00000040;

        public const uint DSQPM_GETCLASSLIST = CQPM_HANDLERSPECIFIC+0;

        public const uint DSQPM_HELPTOPICS = CQPM_HANDLERSPECIFIC+1;

        public const uint DSROLE_PRIMARY_DS_RUNNING = 0x00000001;

        public const uint DSROLE_PRIMARY_DS_MIXED_MODE = 0x00000002;

        public const uint DSROLE_UPGRADE_IN_PROGRESS = 0x00000004;

        public const uint DSROLE_PRIMARY_DS_READONLY = 0x00000008;

        public const uint DSROLE_PRIMARY_DOMAIN_GUID_PRESENT = 0x01000000;

        public const uint ADS_ATTR_CLEAR = 1;

        public const uint ADS_ATTR_UPDATE = 2;

        public const uint ADS_ATTR_APPEND = 3;

        public const uint ADS_ATTR_DELETE = 4;

        public const uint ADS_EXT_MINEXTDISPID = 1;

        public const uint ADS_EXT_MAXEXTDISPID = 16777215;

        public const uint ADS_EXT_INITCREDENTIALS = 1;

        public const uint ADS_EXT_INITIALIZE_COMPLETE = 2;

        public const uint DS_BEHAVIOR_WIN2000 = 0;

        public const uint DS_BEHAVIOR_WIN2003_WITH_MIXED_DOMAINS = 1;

        public const uint DS_BEHAVIOR_WIN2003 = 2;

        public const uint DS_BEHAVIOR_WIN2008 = 3;

        public const uint DS_BEHAVIOR_WIN2008R2 = 4;

        public const uint DS_BEHAVIOR_WIN2012 = 5;

        public const uint DS_BEHAVIOR_WIN2012R2 = 6;

        public const uint DS_BEHAVIOR_WIN2016 = 7;

        public const uint ACTRL_DS_OPEN = 0x00000000;

        public const uint ACTRL_DS_CREATE_CHILD = 0x00000001;

        public const uint ACTRL_DS_DELETE_CHILD = 0x00000002;

        public const uint ACTRL_DS_LIST = 0x00000004;

        public const uint ACTRL_DS_SELF = 0x00000008;

        public const uint ACTRL_DS_READ_PROP = 0x00000010;

        public const uint ACTRL_DS_WRITE_PROP = 0x00000020;

        public const uint ACTRL_DS_DELETE_TREE = 0x00000040;

        public const uint ACTRL_DS_LIST_OBJECT = 0x00000080;

        public const uint ACTRL_DS_CONTROL_ACCESS = 0x00000100;

        public const uint NTDSAPI_BIND_ALLOW_DELEGATION = 0x00000001;

        public const uint NTDSAPI_BIND_FIND_BINDING = 0x00000002;

        public const uint NTDSAPI_BIND_FORCE_KERBEROS = 0x00000004;

        public const uint DS_REPSYNC_ASYNCHRONOUS_OPERATION = 0x00000001;

        public const uint DS_REPSYNC_WRITEABLE = 0x00000002;

        public const uint DS_REPSYNC_PERIODIC = 0x00000004;

        public const uint DS_REPSYNC_INTERSITE_MESSAGING = 0x00000008;

        public const uint DS_REPSYNC_FULL = 0x00000020;

        public const uint DS_REPSYNC_URGENT = 0x00000040;

        public const uint DS_REPSYNC_NO_DISCARD = 0x00000080;

        public const uint DS_REPSYNC_FORCE = 0x00000100;

        public const uint DS_REPSYNC_ADD_REFERENCE = 0x00000200;

        public const uint DS_REPSYNC_NEVER_COMPLETED = 0x00000400;

        public const uint DS_REPSYNC_TWO_WAY = 0x00000800;

        public const uint DS_REPSYNC_NEVER_NOTIFY = 0x00001000;

        public const uint DS_REPSYNC_INITIAL = 0x00002000;

        public const uint DS_REPSYNC_USE_COMPRESSION = 0x00004000;

        public const uint DS_REPSYNC_ABANDONED = 0x00008000;

        public const uint DS_REPSYNC_SELECT_SECRETS = 0x00008000;

        public const uint DS_REPSYNC_INITIAL_IN_PROGRESS = 0x00010000;

        public const uint DS_REPSYNC_PARTIAL_ATTRIBUTE_SET = 0x00020000;

        public const uint DS_REPSYNC_REQUEUE = 0x00040000;

        public const uint DS_REPSYNC_NOTIFICATION = 0x00080000;

        public const uint DS_REPSYNC_ASYNCHRONOUS_REPLICA = 0x00100000;

        public const uint DS_REPSYNC_CRITICAL = 0x00200000;

        public const uint DS_REPSYNC_FULL_IN_PROGRESS = 0x00400000;

        public const uint DS_REPSYNC_PREEMPTED = 0x00800000;

        public const uint DS_REPSYNC_NONGC_RO_REPLICA = 0x01000000;

        public const uint DS_REPADD_ASYNCHRONOUS_OPERATION = 0x00000001;

        public const uint DS_REPADD_WRITEABLE = 0x00000002;

        public const uint DS_REPADD_INITIAL = 0x00000004;

        public const uint DS_REPADD_PERIODIC = 0x00000008;

        public const uint DS_REPADD_INTERSITE_MESSAGING = 0x00000010;

        public const uint DS_REPADD_ASYNCHRONOUS_REPLICA = 0x00000020;

        public const uint DS_REPADD_DISABLE_NOTIFICATION = 0x00000040;

        public const uint DS_REPADD_DISABLE_PERIODIC = 0x00000080;

        public const uint DS_REPADD_USE_COMPRESSION = 0x00000100;

        public const uint DS_REPADD_NEVER_NOTIFY = 0x00000200;

        public const uint DS_REPADD_TWO_WAY = 0x00000400;

        public const uint DS_REPADD_CRITICAL = 0x00000800;

        public const uint DS_REPADD_SELECT_SECRETS = 0x00001000;

        public const uint DS_REPADD_NONGC_RO_REPLICA = 0x01000000;

        public const uint DS_REPDEL_ASYNCHRONOUS_OPERATION = 0x00000001;

        public const uint DS_REPDEL_WRITEABLE = 0x00000002;

        public const uint DS_REPDEL_INTERSITE_MESSAGING = 0x00000004;

        public const uint DS_REPDEL_IGNORE_ERRORS = 0x00000008;

        public const uint DS_REPDEL_LOCAL_ONLY = 0x00000010;

        public const uint DS_REPDEL_NO_SOURCE = 0x00000020;

        public const uint DS_REPDEL_REF_OK = 0x00000040;

        public const uint DS_REPMOD_ASYNCHRONOUS_OPERATION = 0x00000001;

        public const uint DS_REPMOD_WRITEABLE = 0x00000002;

        public const uint DS_REPMOD_UPDATE_FLAGS = 0x00000001;

        public const uint DS_REPMOD_UPDATE_INSTANCE = 0x00000002;

        public const uint DS_REPMOD_UPDATE_SCHEDULE = 0x00000004;

        public const uint DS_REPMOD_UPDATE_RESULT = 0x00000008;

        public const uint DS_REPMOD_UPDATE_TRANSPORT = 0x00000010;

        public const uint DS_REPUPD_ASYNCHRONOUS_OPERATION = 0x00000001;

        public const uint DS_REPUPD_WRITEABLE = 0x00000002;

        public const uint DS_REPUPD_ADD_REFERENCE = 0x00000004;

        public const uint DS_REPUPD_DELETE_REFERENCE = 0x00000008;

        public const uint DS_REPUPD_REFERENCE_GCSPN = 0x00000010;

        public const uint DS_INSTANCETYPE_IS_NC_HEAD = 0x00000001;

        public const uint DS_INSTANCETYPE_NC_IS_WRITEABLE = 0x00000004;

        public const uint DS_INSTANCETYPE_NC_COMING = 0x00000010;

        public const uint DS_INSTANCETYPE_NC_GOING = 0x00000020;

        public const uint NTDSDSA_OPT_IS_GC = 1u<< 0;

        public const uint NTDSDSA_OPT_DISABLE_INBOUND_REPL = 1u<< 1;

        public const uint NTDSDSA_OPT_DISABLE_OUTBOUND_REPL = 1u<< 2;

        public const uint NTDSDSA_OPT_DISABLE_NTDSCONN_XLATE = 1u<< 3;

        public const uint NTDSDSA_OPT_DISABLE_SPN_REGISTRATION = 1u<< 4;

        public const uint NTDSDSA_OPT_GENERATE_OWN_TOPO = 1u<< 5;

        public const uint NTDSDSA_OPT_BLOCK_RPC = 1u<< 6;

        public const uint NTDSCONN_OPT_IS_GENERATED = 1u<< 0;

        public const uint NTDSCONN_OPT_TWOWAY_SYNC = 1u<< 1;

        public const uint NTDSCONN_OPT_OVERRIDE_NOTIFY_DEFAULT = 1u<< 2;

        public const uint NTDSCONN_OPT_USE_NOTIFY = 1u<< 3;

        public const uint NTDSCONN_OPT_DISABLE_INTERSITE_COMPRESSION = 1u<< 4;

        public const uint NTDSCONN_OPT_USER_OWNED_SCHEDULE = 1u<< 5;

        public const uint NTDSCONN_OPT_RODC_TOPOLOGY = 1u<< 6;

        public const uint NTDSCONN_KCC_NO_REASON = 0;

        public const uint NTDSCONN_KCC_GC_TOPOLOGY = 1u<< 0;

        public const uint NTDSCONN_KCC_RING_TOPOLOGY = 1u<< 1;

        public const uint NTDSCONN_KCC_MINIMIZE_HOPS_TOPOLOGY = 1u<< 2;

        public const uint NTDSCONN_KCC_STALE_SERVERS_TOPOLOGY = 1u<< 3;

        public const uint NTDSCONN_KCC_OSCILLATING_CONNECTION_TOPOLOGY = 1u<< 4;

        public const uint NTDSCONN_KCC_INTERSITE_GC_TOPOLOGY = 1u<< 5;

        public const uint NTDSCONN_KCC_INTERSITE_TOPOLOGY = 1u<< 6;

        public const uint NTDSCONN_KCC_SERVER_FAILOVER_TOPOLOGY = 1u<< 7;

        public const uint NTDSCONN_KCC_SITE_FAILOVER_TOPOLOGY = 1u<< 8;

        public const uint NTDSCONN_KCC_REDUNDANT_SERVER_TOPOLOGY = 1u<< 9;

        public const uint FRSCONN_PRIORITY_MASK = 0x70000000;

        public const uint FRSCONN_MAX_PRIORITY = 0x8;

        public const uint NTDSCONN_OPT_IGNORE_SCHEDULE_MASK = 0x80000000;

        public const uint NTDSSETTINGS_OPT_IS_AUTO_TOPOLOGY_DISABLED = 1u<< 0;

        public const uint NTDSSETTINGS_OPT_IS_TOPL_CLEANUP_DISABLED = 1u<< 1;

        public const uint NTDSSETTINGS_OPT_IS_TOPL_MIN_HOPS_DISABLED = 1u<< 2;

        public const uint NTDSSETTINGS_OPT_IS_TOPL_DETECT_STALE_DISABLED = 1u<< 3;

        public const uint NTDSSETTINGS_OPT_IS_INTER_SITE_AUTO_TOPOLOGY_DISABLED = 1u<< 4;

        public const uint NTDSSETTINGS_OPT_IS_GROUP_CACHING_ENABLED = 1u<< 5;

        public const uint NTDSSETTINGS_OPT_FORCE_KCC_WHISTLER_BEHAVIOR = 1u<< 6;

        public const uint NTDSSETTINGS_OPT_FORCE_KCC_W2K_ELECTION = 1u<< 7;

        public const uint NTDSSETTINGS_OPT_IS_RAND_BH_SELECTION_DISABLED = 1u<< 8;

        public const uint NTDSSETTINGS_OPT_IS_SCHEDULE_HASHING_ENABLED = 1u<< 9;

        public const uint NTDSSETTINGS_OPT_IS_REDUNDANT_SERVER_TOPOLOGY_ENABLED = 1u<< 10;

        public const uint NTDSSETTINGS_OPT_W2K3_IGNORE_SCHEDULES = 1u<< 11;

        public const uint NTDSSETTINGS_OPT_W2K3_BRIDGES_REQUIRED = 1u<< 12;

        public const uint NTDSSETTINGS_DEFAULT_SERVER_REDUNDANCY = 2;

        public const uint NTDSTRANSPORT_OPT_IGNORE_SCHEDULES = 1u<< 0;

        public const uint NTDSTRANSPORT_OPT_BRIDGES_REQUIRED = 1u<< 1;

        public const uint NTDSSITECONN_OPT_USE_NOTIFY = 1u<< 0;

        public const uint NTDSSITECONN_OPT_TWOWAY_SYNC = 1u<< 1;

        public const uint NTDSSITECONN_OPT_DISABLE_COMPRESSION = 1u<< 2;

        public const uint NTDSSITELINK_OPT_USE_NOTIFY = 1u<< 0;

        public const uint NTDSSITELINK_OPT_TWOWAY_SYNC = 1u<< 1;

        public const uint NTDSSITELINK_OPT_DISABLE_COMPRESSION = 1u<< 2;

        public const uint DS_REPSYNCALL_NO_OPTIONS = 0x00000000;

        public const uint DS_REPSYNCALL_ABORT_IF_SERVER_UNAVAILABLE = 0x00000001;

        public const uint DS_REPSYNCALL_SYNC_ADJACENT_SERVERS_ONLY = 0x00000002;

        public const uint DS_REPSYNCALL_ID_SERVERS_BY_DN = 0x00000004;

        public const uint DS_REPSYNCALL_DO_NOT_SYNC = 0x00000008;

        public const uint DS_REPSYNCALL_SKIP_INITIAL_CHECK = 0x00000010;

        public const uint DS_REPSYNCALL_PUSH_CHANGES_OUTWARD = 0x00000020;

        public const uint DS_REPSYNCALL_CROSS_SITE_BOUNDARIES = 0x00000040;

        public const uint DS_LIST_DSA_OBJECT_FOR_SERVER = 0;

        public const uint DS_LIST_DNS_HOST_NAME_FOR_SERVER = 1;

        public const uint DS_LIST_ACCOUNT_OBJECT_FOR_SERVER = 2;

        public const uint DS_ROLE_SCHEMA_OWNER = 0;

        public const uint DS_ROLE_DOMAIN_OWNER = 1;

        public const uint DS_ROLE_PDC_OWNER = 2;

        public const uint DS_ROLE_RID_OWNER = 3;

        public const uint DS_ROLE_INFRASTRUCTURE_OWNER = 4;

        public const uint DS_SCHEMA_GUID_NOT_FOUND = 0;

        public const uint DS_SCHEMA_GUID_ATTR = 1;

        public const uint DS_SCHEMA_GUID_ATTR_SET = 2;

        public const uint DS_SCHEMA_GUID_CLASS = 3;

        public const uint DS_SCHEMA_GUID_CONTROL_RIGHT = 4;

        public const uint DS_KCC_FLAG_ASYNC_OP = 1u<< 0;

        public const uint DS_KCC_FLAG_DAMPED = 1u<< 1;

        public const uint DS_EXIST_ADVISORY_MODE = 0x1;

        public const uint DS_REPL_INFO_FLAG_IMPROVE_LINKED_ATTRS = 0x00000001;

        public const uint DS_REPL_NBR_WRITEABLE = 0x00000010;

        public const uint DS_REPL_NBR_SYNC_ON_STARTUP = 0x00000020;

        public const uint DS_REPL_NBR_DO_SCHEDULED_SYNCS = 0x00000040;

        public const uint DS_REPL_NBR_USE_ASYNC_INTERSITE_TRANSPORT = 0x00000080;

        public const uint DS_REPL_NBR_TWO_WAY_SYNC = 0x00000200;

        public const uint DS_REPL_NBR_NONGC_RO_REPLICA = 0x00000400;

        public const uint DS_REPL_NBR_RETURN_OBJECT_PARENTS = 0x00000800;

        public const uint DS_REPL_NBR_SELECT_SECRETS = 0x00001000;

        public const uint DS_REPL_NBR_FULL_SYNC_IN_PROGRESS = 0x00010000;

        public const uint DS_REPL_NBR_FULL_SYNC_NEXT_PACKET = 0x00020000;

        public const uint DS_REPL_NBR_GCSPN = 0x00100000;

        public const uint DS_REPL_NBR_NEVER_SYNCED = 0x00200000;

        public const uint DS_REPL_NBR_PREEMPTED = 0x01000000;

        public const uint DS_REPL_NBR_IGNORE_CHANGE_NOTIFICATIONS = 0x04000000;

        public const uint DS_REPL_NBR_DISABLE_SCHEDULED_SYNC = 0x08000000;

        public const uint DS_REPL_NBR_COMPRESS_CHANGES = 0x10000000;

        public const uint DS_REPL_NBR_NO_CHANGE_NOTIFICATIONS = 0x20000000;

        public const uint DS_REPL_NBR_PARTIAL_ATTRIBUTE_SET = 0x40000000;

        public const uint ADAM_REPL_AUTHENTICATION_MODE_NEGOTIATE_PASS_THROUGH = 0;

        public const uint ADAM_REPL_AUTHENTICATION_MODE_NEGOTIATE = 1;

        public const uint ADAM_REPL_AUTHENTICATION_MODE_MUTUAL_AUTH_REQUIRED = 2;

        public const uint FLAG_FOREST_OPTIONAL_FEATURE = 0x00000001;

        public const uint FLAG_DOMAIN_OPTIONAL_FEATURE = 0x00000002;

        public const uint FLAG_DISABLABLE_OPTIONAL_FEATURE = 0x00000004;

        public const uint FLAG_SERVER_OPTIONAL_FEATURE = 0x00000008;

        public const uint DSOP_SCOPE_TYPE_TARGET_COMPUTER = 0x00000001;

        public const uint DSOP_SCOPE_TYPE_UPLEVEL_JOINED_DOMAIN = 0x00000002;

        public const uint DSOP_SCOPE_TYPE_DOWNLEVEL_JOINED_DOMAIN = 0x00000004;

        public const uint DSOP_SCOPE_TYPE_ENTERPRISE_DOMAIN = 0x00000008;

        public const uint DSOP_SCOPE_TYPE_GLOBAL_CATALOG = 0x00000010;

        public const uint DSOP_SCOPE_TYPE_EXTERNAL_UPLEVEL_DOMAIN = 0x00000020;

        public const uint DSOP_SCOPE_TYPE_EXTERNAL_DOWNLEVEL_DOMAIN = 0x00000040;

        public const uint DSOP_SCOPE_TYPE_WORKGROUP = 0x00000080;

        public const uint DSOP_SCOPE_TYPE_USER_ENTERED_UPLEVEL_SCOPE = 0x00000100;

        public const uint DSOP_SCOPE_TYPE_USER_ENTERED_DOWNLEVEL_SCOPE = 0x00000200;

        public const uint DSOP_SCOPE_FLAG_STARTING_SCOPE = 0x00000001;

        public const uint DSOP_SCOPE_FLAG_WANT_PROVIDER_WINNT = 0x00000002;

        public const uint DSOP_SCOPE_FLAG_WANT_PROVIDER_LDAP = 0x00000004;

        public const uint DSOP_SCOPE_FLAG_WANT_PROVIDER_GC = 0x00000008;

        public const uint DSOP_SCOPE_FLAG_WANT_SID_PATH = 0x00000010;

        public const uint DSOP_SCOPE_FLAG_WANT_DOWNLEVEL_BUILTIN_PATH = 0x00000020;

        public const uint DSOP_SCOPE_FLAG_DEFAULT_FILTER_USERS = 0x00000040;

        public const uint DSOP_SCOPE_FLAG_DEFAULT_FILTER_GROUPS = 0x00000080;

        public const uint DSOP_SCOPE_FLAG_DEFAULT_FILTER_COMPUTERS = 0x00000100;

        public const uint DSOP_SCOPE_FLAG_DEFAULT_FILTER_CONTACTS = 0x00000200;

        public const uint DSOP_SCOPE_FLAG_DEFAULT_FILTER_SERVICE_ACCOUNTS = 0x00000400;

        public const uint DSOP_SCOPE_FLAG_DEFAULT_FILTER_PASSWORDSETTINGS_OBJECTS = 0x00000800;

        public const uint DSOP_FILTER_INCLUDE_ADVANCED_VIEW = 0x00000001;

        public const uint DSOP_FILTER_USERS = 0x00000002;

        public const uint DSOP_FILTER_BUILTIN_GROUPS = 0x00000004;

        public const uint DSOP_FILTER_WELL_KNOWN_PRINCIPALS = 0x00000008;

        public const uint DSOP_FILTER_UNIVERSAL_GROUPS_DL = 0x00000010;

        public const uint DSOP_FILTER_UNIVERSAL_GROUPS_SE = 0x00000020;

        public const uint DSOP_FILTER_GLOBAL_GROUPS_DL = 0x00000040;

        public const uint DSOP_FILTER_GLOBAL_GROUPS_SE = 0x00000080;

        public const uint DSOP_FILTER_DOMAIN_LOCAL_GROUPS_DL = 0x00000100;

        public const uint DSOP_FILTER_DOMAIN_LOCAL_GROUPS_SE = 0x00000200;

        public const uint DSOP_FILTER_CONTACTS = 0x00000400;

        public const uint DSOP_FILTER_COMPUTERS = 0x00000800;

        public const uint DSOP_FILTER_SERVICE_ACCOUNTS = 0x00001000;

        public const uint DSOP_FILTER_PASSWORDSETTINGS_OBJECTS = 0x00002000;

        public const uint DSOP_DOWNLEVEL_FILTER_USERS = 0x80000001;

        public const uint DSOP_DOWNLEVEL_FILTER_LOCAL_GROUPS = 0x80000002;

        public const uint DSOP_DOWNLEVEL_FILTER_GLOBAL_GROUPS = 0x80000004;

        public const uint DSOP_DOWNLEVEL_FILTER_COMPUTERS = 0x80000008;

        public const uint DSOP_DOWNLEVEL_FILTER_WORLD = 0x80000010;

        public const uint DSOP_DOWNLEVEL_FILTER_AUTHENTICATED_USER = 0x80000020;

        public const uint DSOP_DOWNLEVEL_FILTER_ANONYMOUS = 0x80000040;

        public const uint DSOP_DOWNLEVEL_FILTER_BATCH = 0x80000080;

        public const uint DSOP_DOWNLEVEL_FILTER_CREATOR_OWNER = 0x80000100;

        public const uint DSOP_DOWNLEVEL_FILTER_CREATOR_GROUP = 0x80000200;

        public const uint DSOP_DOWNLEVEL_FILTER_DIALUP = 0x80000400;

        public const uint DSOP_DOWNLEVEL_FILTER_INTERACTIVE = 0x80000800;

        public const uint DSOP_DOWNLEVEL_FILTER_NETWORK = 0x80001000;

        public const uint DSOP_DOWNLEVEL_FILTER_SERVICE = 0x80002000;

        public const uint DSOP_DOWNLEVEL_FILTER_SYSTEM = 0x80004000;

        public const uint DSOP_DOWNLEVEL_FILTER_EXCLUDE_BUILTIN_GROUPS = 0x80008000;

        public const uint DSOP_DOWNLEVEL_FILTER_TERMINAL_SERVER = 0x80010000;

        public const uint DSOP_DOWNLEVEL_FILTER_ALL_WELLKNOWN_SIDS = 0x80020000;

        public const uint DSOP_DOWNLEVEL_FILTER_LOCAL_SERVICE = 0x80040000;

        public const uint DSOP_DOWNLEVEL_FILTER_NETWORK_SERVICE = 0x80080000;

        public const uint DSOP_DOWNLEVEL_FILTER_REMOTE_LOGON = 0x80100000;

        public const uint DSOP_DOWNLEVEL_FILTER_INTERNET_USER = 0x80200000;

        public const uint DSOP_DOWNLEVEL_FILTER_OWNER_RIGHTS = 0x80400000;

        public const uint DSOP_DOWNLEVEL_FILTER_SERVICES = 0x80800000;

        public const uint DSOP_DOWNLEVEL_FILTER_LOCAL_LOGON = 0x81000000;

        public const uint DSOP_DOWNLEVEL_FILTER_THIS_ORG_CERT = 0x82000000;

        public const uint DSOP_DOWNLEVEL_FILTER_IIS_APP_POOL = 0x84000000;

        public const uint DSOP_DOWNLEVEL_FILTER_ALL_APP_PACKAGES = 0x88000000;

        public const uint DSOP_DOWNLEVEL_FILTER_LOCAL_ACCOUNTS = 0x90000000;

        public const uint DSOP_FLAG_MULTISELECT = 0x00000001;

        public const uint DSOP_FLAG_SKIP_TARGET_COMPUTER_DC_CHECK = 0x00000002;

        public const uint SCHEDULE_INTERVAL = 0;

        public const uint SCHEDULE_BANDWIDTH = 1;

        public const uint SCHEDULE_PRIORITY = 2;

    }
}

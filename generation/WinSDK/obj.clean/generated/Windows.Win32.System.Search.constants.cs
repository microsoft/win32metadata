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


namespace Windows.Win32.System.Search
{
    public static partial class Apis
    {
        public const uint SI_TEMPORARY = 0x80000000;

        public const uint SUBSINFO_ALLFLAGS = 0x0000EF7F;

        public const uint RS_READY = 0x00000001;

        public const uint RS_SUSPENDED = 0x00000002;

        public const uint RS_UPDATING = 0x00000004;

        public const uint RS_SUSPENDONIDLE = 0x00010000;

        public const uint RS_MAYBOTHERUSER = 0x00020000;

        public const uint RS_COMPLETED = 0x80000000;

        public const uint SUBSMGRUPDATE_MINIMIZE = 0x00000001;

        public const uint SUBSMGRUPDATE_MASK = 0x00000001;

        public const uint SUBSMGRENUM_TEMP = 0x00000001;

        public const uint SUBSMGRENUM_MASK = 0x00000001;

        [NativeTypeName("HRESULT")]
        public const int INET_E_AGENT_MAX_SIZE_EXCEEDED = unchecked((int)0x800C0F80);

        [NativeTypeName("HRESULT")]
        public const int INET_S_AGENT_PART_FAIL = 0x000C0F81;

        [NativeTypeName("HRESULT")]
        public const int INET_E_AGENT_CACHE_SIZE_EXCEEDED = unchecked((int)0x800C0F82);

        [NativeTypeName("HRESULT")]
        public const int INET_E_AGENT_CONNECTION_FAILED = unchecked((int)0x800C0F83);

        [NativeTypeName("HRESULT")]
        public const int INET_E_SCHEDULED_UPDATES_DISABLED = unchecked((int)0x800C0F84);

        [NativeTypeName("HRESULT")]
        public const int INET_E_SCHEDULED_UPDATES_RESTRICTED = unchecked((int)0x800C0F85);

        [NativeTypeName("HRESULT")]
        public const int INET_E_SCHEDULED_UPDATE_INTERVAL = unchecked((int)0x800C0F86);

        [NativeTypeName("HRESULT")]
        public const int INET_E_SCHEDULED_EXCLUDE_RANGE = unchecked((int)0x800C0F87);

        [NativeTypeName("HRESULT")]
        public const int INET_E_AGENT_EXCEEDING_CACHE_SIZE = unchecked((int)0x800C0F90);

        [NativeTypeName("HRESULT")]
        public const int INET_S_AGENT_INCREASED_CACHE_SIZE = 0x000C0F90;

        public const uint OLEDBVER = 0x0270;

        public const uint DB_NULL_HACCESSOR = 0x00;

        public const uint DB_INVALID_HACCESSOR = 0x00;

        public const uint DB_NULL_HROW = 0x00;

        public const uint DB_NULL_HCHAPTER = 0x00;

        public const uint DB_INVALID_HCHAPTER = 0x00;

        public const uint STD_BOOKMARKLENGTH = 1;

        public const int DBPROPVAL_BMK_NUMERIC = 0x00000001;

        public const int DBPROPVAL_BMK_KEY = 0x00000002;

        public const int DBPROPVAL_CL_START = 0x00000001;

        public const int DBPROPVAL_CL_END = 0x00000002;

        public const int DBPROPVAL_CU_DML_STATEMENTS = 0x00000001;

        public const int DBPROPVAL_CU_TABLE_DEFINITION = 0x00000002;

        public const int DBPROPVAL_CU_INDEX_DEFINITION = 0x00000004;

        public const int DBPROPVAL_CU_PRIVILEGE_DEFINITION = 0x00000008;

        public const int DBPROPVAL_CD_NOTNULL = 0x00000001;

        public const int DBPROPVAL_CB_NULL = 0x00000001;

        public const int DBPROPVAL_CB_NON_NULL = 0x00000002;

        public const int DBPROPVAL_FU_NOT_SUPPORTED = 0x00000001;

        public const int DBPROPVAL_FU_COLUMN = 0x00000002;

        public const int DBPROPVAL_FU_TABLE = 0x00000004;

        public const int DBPROPVAL_FU_CATALOG = 0x00000008;

        public const int DBPROPVAL_GB_NOT_SUPPORTED = 0x00000001;

        public const int DBPROPVAL_GB_EQUALS_SELECT = 0x00000002;

        public const int DBPROPVAL_GB_CONTAINS_SELECT = 0x00000004;

        public const int DBPROPVAL_GB_NO_RELATION = 0x00000008;

        public const int DBPROPVAL_HT_DIFFERENT_CATALOGS = 0x00000001;

        public const int DBPROPVAL_HT_DIFFERENT_PROVIDERS = 0x00000002;

        public const int DBPROPVAL_IC_UPPER = 0x00000001;

        public const int DBPROPVAL_IC_LOWER = 0x00000002;

        public const int DBPROPVAL_IC_SENSITIVE = 0x00000004;

        public const int DBPROPVAL_IC_MIXED = 0x00000008;

        public const int DBPROPVAL_LM_NONE = 0x00000001;

        public const int DBPROPVAL_LM_READ = 0x00000002;

        public const int DBPROPVAL_LM_INTENT = 0x00000004;

        public const int DBPROPVAL_LM_RITE = 0x00000008;

        public const int DBPROPVAL_NP_OKTODO = 0x00000001;

        public const int DBPROPVAL_NP_ABOUTTODO = 0x00000002;

        public const int DBPROPVAL_NP_SYNCHAFTER = 0x00000004;

        public const int DBPROPVAL_NP_FAILEDTODO = 0x00000008;

        public const int DBPROPVAL_NP_DIDEVENT = 0x00000010;

        public const int DBPROPVAL_NC_END = 0x00000001;

        public const int DBPROPVAL_NC_HIGH = 0x00000002;

        public const int DBPROPVAL_NC_LOW = 0x00000004;

        public const int DBPROPVAL_NC_START = 0x00000008;

        public const int DBPROPVAL_OO_BLOB = 0x00000001;

        public const int DBPROPVAL_OO_IPERSIST = 0x00000002;

        public const int DBPROPVAL_CB_DELETE = 0x00000001;

        public const int DBPROPVAL_CB_PRESERVE = 0x00000002;

        public const int DBPROPVAL_SU_DML_STATEMENTS = 0x00000001;

        public const int DBPROPVAL_SU_TABLE_DEFINITION = 0x00000002;

        public const int DBPROPVAL_SU_INDEX_DEFINITION = 0x00000004;

        public const int DBPROPVAL_SU_PRIVILEGE_DEFINITION = 0x00000008;

        public const int DBPROPVAL_SQ_CORRELATEDSUBQUERIES = 0x00000001;

        public const int DBPROPVAL_SQ_COMPARISON = 0x00000002;

        public const int DBPROPVAL_SQ_EXISTS = 0x00000004;

        public const int DBPROPVAL_SQ_IN = 0x00000008;

        public const int DBPROPVAL_SQ_QUANTIFIED = 0x00000010;

        public const int DBPROPVAL_SQ_TABLE = 0x00000020;

        public const int DBPROPVAL_SS_ISEQUENTIALSTREAM = 0x00000001;

        public const int DBPROPVAL_SS_ISTREAM = 0x00000002;

        public const int DBPROPVAL_SS_ISTORAGE = 0x00000004;

        public const int DBPROPVAL_SS_ILOCKBYTES = 0x00000008;

        public const int DBPROPVAL_TI_CHAOS = 0x00000010;

        public const int DBPROPVAL_TI_READUNCOMMITTED = 0x00000100;

        public const int DBPROPVAL_TI_BROWSE = 0x00000100;

        public const int DBPROPVAL_TI_CURSORSTABILITY = 0x00001000;

        public const int DBPROPVAL_TI_READCOMMITTED = 0x00001000;

        public const int DBPROPVAL_TI_REPEATABLEREAD = 0x00010000;

        public const int DBPROPVAL_TI_SERIALIZABLE = 0x00100000;

        public const int DBPROPVAL_TI_ISOLATED = 0x00100000;

        public const int DBPROPVAL_TR_COMMIT_DC = 0x00000001;

        public const int DBPROPVAL_TR_COMMIT = 0x00000002;

        public const int DBPROPVAL_TR_COMMIT_NO = 0x00000004;

        public const int DBPROPVAL_TR_ABORT_DC = 0x00000008;

        public const int DBPROPVAL_TR_ABORT = 0x00000010;

        public const int DBPROPVAL_TR_ABORT_NO = 0x00000020;

        public const int DBPROPVAL_TR_DONTCARE = 0x00000040;

        public const int DBPROPVAL_TR_BOTH = 0x00000080;

        public const int DBPROPVAL_TR_NONE = 0x00000100;

        public const int DBPROPVAL_TR_OPTIMISTIC = 0x00000200;

        public const int DBPROPVAL_RT_FREETHREAD = 0x00000001;

        public const int DBPROPVAL_RT_APTMTTHREAD = 0x00000002;

        public const int DBPROPVAL_RT_SINGLETHREAD = 0x00000004;

        public const int DBPROPVAL_UP_CHANGE = 0x00000001;

        public const int DBPROPVAL_UP_DELETE = 0x00000002;

        public const int DBPROPVAL_UP_INSERT = 0x00000004;

        public const int DBPROPVAL_SQL_NONE = 0x00000000;

        public const int DBPROPVAL_SQL_ODBC_MINIMUM = 0x00000001;

        public const int DBPROPVAL_SQL_ODBC_CORE = 0x00000002;

        public const int DBPROPVAL_SQL_ODBC_EXTENDED = 0x00000004;

        public const int DBPROPVAL_SQL_ANSI89_IEF = 0x00000008;

        public const int DBPROPVAL_SQL_ANSI92_ENTRY = 0x00000010;

        public const int DBPROPVAL_SQL_FIPS_TRANSITIONAL = 0x00000020;

        public const int DBPROPVAL_SQL_ANSI92_INTERMEDIATE = 0x00000040;

        public const int DBPROPVAL_SQL_ANSI92_FULL = 0x00000080;

        public const int DBPROPVAL_SQL_ESCAPECLAUSES = 0x00000100;

        public const int DBPROPVAL_IT_BTREE = 0x00000001;

        public const int DBPROPVAL_IT_HASH = 0x00000002;

        public const int DBPROPVAL_IT_CONTENT = 0x00000003;

        public const int DBPROPVAL_IT_OTHER = 0x00000004;

        public const int DBPROPVAL_IN_DISALLOWNULL = 0x00000001;

        public const int DBPROPVAL_IN_IGNORENULL = 0x00000002;

        public const int DBPROPVAL_IN_IGNOREANYNULL = 0x00000004;

        public const int DBPROPVAL_TC_NONE = 0x00000000;

        public const int DBPROPVAL_TC_DML = 0x00000001;

        public const int DBPROPVAL_TC_DDL_COMMIT = 0x00000002;

        public const int DBPROPVAL_TC_DDL_IGNORE = 0x00000004;

        public const int DBPROPVAL_TC_ALL = 0x00000008;

        public const int DBPROPVAL_OA_NOTSUPPORTED = 0x00000001;

        public const int DBPROPVAL_OA_ATEXECUTE = 0x00000002;

        public const int DBPROPVAL_OA_ATROWRELEASE = 0x00000004;

        public const int DBPROPVAL_MR_NOTSUPPORTED = 0x00000000;

        public const int DBPROPVAL_MR_SUPPORTED = 0x00000001;

        public const int DBPROPVAL_MR_CONCURRENT = 0x00000002;

        public const int DBPROPVAL_PT_GUID_NAME = 0x00000001;

        public const int DBPROPVAL_PT_GUID_PROPID = 0x00000002;

        public const int DBPROPVAL_PT_NAME = 0x00000004;

        public const int DBPROPVAL_PT_GUID = 0x00000008;

        public const int DBPROPVAL_PT_PROPID = 0x00000010;

        public const int DBPROPVAL_PT_PGUID_NAME = 0x00000020;

        public const int DBPROPVAL_PT_PGUID_PROPID = 0x00000040;

        public const int DBPROPVAL_NT_SINGLEROW = 0x00000001;

        public const int DBPROPVAL_NT_MULTIPLEROWS = 0x00000002;

        public const int DBPROPVAL_ASYNCH_INITIALIZE = 0x00000001;

        public const int DBPROPVAL_ASYNCH_SEQUENTIALPOPULATION = 0x00000002;

        public const int DBPROPVAL_ASYNCH_RANDOMPOPULATION = 0x00000004;

        public const int DBPROPVAL_OP_EQUAL = 0x00000001;

        public const int DBPROPVAL_OP_RELATIVE = 0x00000002;

        public const int DBPROPVAL_OP_STRING = 0x00000004;

        public const int DBPROPVAL_CO_EQUALITY = 0x00000001;

        public const int DBPROPVAL_CO_STRING = 0x00000002;

        public const int DBPROPVAL_CO_CASESENSITIVE = 0x00000004;

        public const int DBPROPVAL_CO_CASEINSENSITIVE = 0x00000008;

        public const int DBPROPVAL_CO_CONTAINS = 0x00000010;

        public const int DBPROPVAL_CO_BEGINSWITH = 0x00000020;

        public const int DBPROPVAL_ASYNCH_BACKGROUNDPOPULATION = 0x00000008;

        public const int DBPROPVAL_ASYNCH_PREPOPULATE = 0x00000010;

        public const int DBPROPVAL_ASYNCH_POPULATEONDEMAND = 0x00000020;

        public const int DBPROPVAL_LM_SINGLEROW = 0x00000002;

        public const int DBPROPVAL_SQL_SUBMINIMUM = 0x00000200;

        public const int DBPROPVAL_DST_TDP = 0x00000001;

        public const int DBPROPVAL_DST_MDP = 0x00000002;

        public const int DBPROPVAL_DST_TDPANDMDP = 0x00000003;

        public const int MDPROPVAL_AU_UNSUPPORTED = 0x00000000;

        public const int MDPROPVAL_AU_UNCHANGED = 0x00000001;

        public const int MDPROPVAL_AU_UNKNOWN = 0x00000002;

        public const int MDPROPVAL_MF_WITH_CALCMEMBERS = 0x00000001;

        public const int MDPROPVAL_MF_WITH_NAMEDSETS = 0x00000002;

        public const int MDPROPVAL_MF_CREATE_CALCMEMBERS = 0x00000004;

        public const int MDPROPVAL_MF_CREATE_NAMEDSETS = 0x00000008;

        public const int MDPROPVAL_MF_SCOPE_SESSION = 0x00000010;

        public const int MDPROPVAL_MF_SCOPE_GLOBAL = 0x00000020;

        public const int MDPROPVAL_MMF_COUSIN = 0x00000001;

        public const int MDPROPVAL_MMF_PARALLELPERIOD = 0x00000002;

        public const int MDPROPVAL_MMF_OPENINGPERIOD = 0x00000004;

        public const int MDPROPVAL_MMF_CLOSINGPERIOD = 0x00000008;

        public const int MDPROPVAL_MNF_MEDIAN = 0x00000001;

        public const int MDPROPVAL_MNF_VAR = 0x00000002;

        public const int MDPROPVAL_MNF_STDDEV = 0x00000004;

        public const int MDPROPVAL_MNF_RANK = 0x00000008;

        public const int MDPROPVAL_MNF_AGGREGATE = 0x00000010;

        public const int MDPROPVAL_MNF_COVARIANCE = 0x00000020;

        public const int MDPROPVAL_MNF_CORRELATION = 0x00000040;

        public const int MDPROPVAL_MNF_LINREGSLOPE = 0x00000080;

        public const int MDPROPVAL_MNF_LINREGVARIANCE = 0x00000100;

        public const int MDPROPVAL_MNF_LINREG2 = 0x00000200;

        public const int MDPROPVAL_MNF_LINREGPOINT = 0x00000400;

        public const int MDPROPVAL_MNF_DRILLDOWNLEVEL = 0x00000800;

        public const int MDPROPVAL_MNF_DRILLDOWNMEMBERTOP = 0x00001000;

        public const int MDPROPVAL_MNF_DRILLDOWNMEMBERBOTTOM = 0x00002000;

        public const int MDPROPVAL_MNF_DRILLDOWNLEVELTOP = 0x00004000;

        public const int MDPROPVAL_MNF_DRILLDOWNLEVELBOTTOM = 0x00008000;

        public const int MDPROPVAL_MNF_DRILLUPMEMBER = 0x00010000;

        public const int MDPROPVAL_MNF_DRILLUPLEVEL = 0x00020000;

        public const int MDPROPVAL_MSF_TOPPERCENT = 0x00000001;

        public const int MDPROPVAL_MSF_BOTTOMPERCENT = 0x00000002;

        public const int MDPROPVAL_MSF_TOPSUM = 0x00000004;

        public const int MDPROPVAL_MSF_BOTTOMSUM = 0x00000008;

        public const int MDPROPVAL_MSF_PERIODSTODATE = 0x00000010;

        public const int MDPROPVAL_MSF_LASTPERIODS = 0x00000020;

        public const int MDPROPVAL_MSF_YTD = 0x00000040;

        public const int MDPROPVAL_MSF_QTD = 0x00000080;

        public const int MDPROPVAL_MSF_MTD = 0x00000100;

        public const int MDPROPVAL_MSF_WTD = 0x00000200;

        public const int MDPROPVAL_MSF_DRILLDOWNMEMBBER = 0x00000400;

        public const int MDPROPVAL_MSF_DRILLDOWNLEVEL = 0x00000800;

        public const int MDPROPVAL_MSF_DRILLDOWNMEMBERTOP = 0x00001000;

        public const int MDPROPVAL_MSF_DRILLDOWNMEMBERBOTTOM = 0x00002000;

        public const int MDPROPVAL_MSF_DRILLDOWNLEVELTOP = 0x00004000;

        public const int MDPROPVAL_MSF_DRILLDOWNLEVELBOTTOM = 0x00008000;

        public const int MDPROPVAL_MSF_DRILLUPMEMBER = 0x00010000;

        public const int MDPROPVAL_MSF_DRILLUPLEVEL = 0x00020000;

        public const int MDPROPVAL_MSF_TOGGLEDRILLSTATE = 0x00040000;

        public const int MDPROPVAL_MD_SELF = 0x00000001;

        public const int MDPROPVAL_MD_BEFORE = 0x00000002;

        public const int MDPROPVAL_MD_AFTER = 0x00000004;

        public const int MDPROPVAL_MSC_LESSTHAN = 0x00000001;

        public const int MDPROPVAL_MSC_GREATERTHAN = 0x00000002;

        public const int MDPROPVAL_MSC_LESSTHANEQUAL = 0x00000004;

        public const int MDPROPVAL_MSC_GREATERTHANEQUAL = 0x00000008;

        public const int MDPROPVAL_MC_SINGLECASE = 0x00000001;

        public const int MDPROPVAL_MC_SEARCHEDCASE = 0x00000002;

        public const int MDPROPVAL_MOQ_OUTERREFERENCE = 0x00000001;

        public const int MDPROPVAL_MOQ_DATASOURCE_CUBE = 0x00000001;

        public const int MDPROPVAL_MOQ_CATALOG_CUBE = 0x00000002;

        public const int MDPROPVAL_MOQ_SCHEMA_CUBE = 0x00000004;

        public const int MDPROPVAL_MOQ_CUBE_DIM = 0x00000008;

        public const int MDPROPVAL_MOQ_DIM_HIER = 0x00000010;

        public const int MDPROPVAL_MOQ_DIMHIER_LEVEL = 0x00000020;

        public const int MDPROPVAL_MOQ_LEVEL_MEMBER = 0x00000040;

        public const int MDPROPVAL_MOQ_MEMBER_MEMBER = 0x00000080;

        public const int MDPROPVAL_MOQ_DIMHIER_MEMBER = 0x00000100;

        public const int MDPROPVAL_FS_FULL_SUPPORT = 0x00000001;

        public const int MDPROPVAL_FS_GENERATED_COLUMN = 0x00000002;

        public const int MDPROPVAL_FS_GENERATED_DIMENSION = 0x00000003;

        public const int MDPROPVAL_FS_NO_SUPPORT = 0x00000004;

        public const int MDPROPVAL_NL_NAMEDLEVELS = 0x00000001;

        public const int MDPROPVAL_NL_NUMBEREDLEVELS = 0x00000002;

        public const int MDPROPVAL_MJC_SINGLECUBE = 0x00000001;

        public const int MDPROPVAL_MJC_MULTICUBES = 0x00000002;

        public const int MDPROPVAL_MJC_IMPLICITCUBE = 0x00000004;

        public const int MDPROPVAL_RR_NORANGEROWSET = 0x00000001;

        public const int MDPROPVAL_RR_READONLY = 0x00000002;

        public const int MDPROPVAL_RR_UPDATE = 0x00000004;

        public const int MDPROPVAL_MS_MULTIPLETUPLES = 0x00000001;

        public const int MDPROPVAL_MS_SINGLETUPLE = 0x00000002;

        public const int MDPROPVAL_NME_ALLDIMENSIONS = 0x00000000;

        public const int MDPROPVAL_NME_MEASURESONLY = 0x00000001;

        public const int DBPROPVAL_AO_SEQUENTIAL = 0x00000000;

        public const int DBPROPVAL_AO_SEQUENTIALSTORAGEOBJECTS = 0x00000001;

        public const int DBPROPVAL_AO_RANDOM = 0x00000002;

        public const int DBPROPVAL_BD_ROWSET = 0x00000000;

        public const int DBPROPVAL_BD_INTRANSACTION = 0x00000001;

        public const int DBPROPVAL_BD_XTRANSACTION = 0x00000002;

        public const int DBPROPVAL_BD_REORGANIZATION = 0x00000003;

        public const int DBPROPVAL_BO_NOLOG = 0x00000000;

        public const int DBPROPVAL_BO_NOINDEXUPDATE = 0x00000001;

        public const int DBPROPVAL_BO_REFINTEGRITY = 0x00000002;

        public const uint DBPROPVAL_STGM_DIRECT = 0x00010000;

        public const uint DBPROPVAL_STGM_TRANSACTED = 0x00020000;

        public const uint DBPROPVAL_STGM_CONVERT = 0x00040000;

        public const uint DBPROPVAL_STGM_FAILIFTHERE = 0x00080000;

        public const uint DBPROPVAL_STGM_PRIORITY = 0x00100000;

        public const uint DBPROPVAL_STGM_DELETEONRELEASE = 0x00200000;

        public const int DBPROPVAL_GB_COLLATE = 0x00000010;

        public const int DBPROPVAL_CS_UNINITIALIZED = 0x00000000;

        public const int DBPROPVAL_CS_INITIALIZED = 0x00000001;

        public const int DBPROPVAL_CS_COMMUNICATIONFAILURE = 0x00000002;

        public const int DBPROPVAL_RD_RESETALL = unchecked((int)0xffffffff);

        public const int DBPROPVAL_OS_RESOURCEPOOLING = 0x00000001;

        public const int DBPROPVAL_OS_TXNENLISTMENT = 0x00000002;

        public const int DBPROPVAL_OS_CLIENTCURSOR = 0x00000004;

        public const int DBPROPVAL_OS_ENABLEALL = unchecked((int)0xffffffff);

        public const int DBPROPVAL_BI_CROSSROWSET = 0x00000001;

        public const int MDPROPVAL_NL_SCHEMAONLY = 0x00000004;

        public const int DBPROPVAL_OS_DISABLEALL = 0x00000000;

        public const int DBPROPVAL_OO_ROWOBJECT = 0x00000004;

        public const int DBPROPVAL_OO_SCOPED = 0x00000008;

        public const int DBPROPVAL_OO_DIRECTBIND = 0x00000010;

        public const int DBPROPVAL_DST_DOCSOURCE = 0x00000004;

        public const int DBPROPVAL_GU_NOTSUPPORTED = 0x00000001;

        public const int DBPROPVAL_GU_SUFFIX = 0x00000002;

        public const int DB_BINDFLAGS_DELAYFETCHCOLUMNS = 0x00000001;

        public const int DB_BINDFLAGS_DELAYFETCHSTREAM = 0x00000002;

        public const int DB_BINDFLAGS_RECURSIVE = 0x00000004;

        public const int DB_BINDFLAGS_OUTPUT = 0x00000008;

        public const int DB_BINDFLAGS_COLLECTION = 0x00000010;

        public const int DB_BINDFLAGS_OPENIFEXISTS = 0x00000020;

        public const int DB_BINDFLAGS_OVERWRITE = 0x00000040;

        public const int DB_BINDFLAGS_ISSTRUCTUREDDOCUMENT = 0x00000080;

        public const int DBPROPVAL_ORS_TABLE = 0x00000000;

        public const int DBPROPVAL_ORS_INDEX = 0x00000001;

        public const int DBPROPVAL_ORS_INTEGRATEDINDEX = 0x00000002;

        public const int DBPROPVAL_TC_DDL_LOCK = 0x00000010;

        public const int DBPROPVAL_ORS_STOREDPROC = 0x00000004;

        public const int DBPROPVAL_IN_ALLOWNULL = 0x00000000;

        public const int DBPROPVAL_OO_SINGLETON = 0x00000020;

        public const int DBPROPVAL_OS_AGR_AFTERSESSION = 0x00000008;

        public const int DBPROPVAL_CM_TRANSACTIONS = 0x00000001;

        public const int DBPROPVAL_TS_CARDINALITY = 0x00000001;

        public const int DBPROPVAL_TS_HISTOGRAM = 0x00000002;

        public const int DBPROPVAL_ORS_HISTOGRAM = 0x00000008;

        public const int MDPROPVAL_VISUAL_MODE_DEFAULT = 0x00000000;

        public const int MDPROPVAL_VISUAL_MODE_VISUAL = 0x00000001;

        public const int MDPROPVAL_VISUAL_MODE_VISUAL_OFF = 0x00000002;

        public const uint DB_IMP_LEVEL_ANONYMOUS = 0x00;

        public const uint DB_IMP_LEVEL_IDENTIFY = 0x01;

        public const uint DB_IMP_LEVEL_IMPERSONATE = 0x02;

        public const uint DB_IMP_LEVEL_DELEGATE = 0x03;

        public const uint DBPROMPT_PROMPT = 0x01;

        public const uint DBPROMPT_COMPLETE = 0x02;

        public const uint DBPROMPT_COMPLETEREQUIRED = 0x03;

        public const uint DBPROMPT_NOPROMPT = 0x04;

        public const uint DB_PROT_LEVEL_NONE = 0x00;

        public const uint DB_PROT_LEVEL_CONNECT = 0x01;

        public const uint DB_PROT_LEVEL_CALL = 0x02;

        public const uint DB_PROT_LEVEL_PKT = 0x03;

        public const uint DB_PROT_LEVEL_PKT_INTEGRITY = 0x04;

        public const uint DB_PROT_LEVEL_PKT_PRIVACY = 0x05;

        public const uint DB_MODE_READ = 0x01;

        public const uint DB_MODE_WRITE = 0x02;

        public const uint DB_MODE_READWRITE = 0x03;

        public const uint DB_MODE_SHARE_DENY_READ = 0x04;

        public const uint DB_MODE_SHARE_DENY_WRITE = 0x08;

        public const uint DB_MODE_SHARE_EXCLUSIVE = 0x0c;

        public const uint DB_MODE_SHARE_DENY_NONE = 0x10;

        public const uint DBCOMPUTEMODE_COMPUTED = 0x01;

        public const uint DBCOMPUTEMODE_DYNAMIC = 0x02;

        public const uint DBCOMPUTEMODE_NOTCOMPUTED = 0x03;

        public const uint DBPROPVAL_DF_INITIALLY_DEFERRED = 0x01;

        public const uint DBPROPVAL_DF_INITIALLY_IMMEDIATE = 0x02;

        public const uint DBPROPVAL_DF_NOT_DEFERRABLE = 0x03;

        public const uint DBPARAMTYPE_INPUT = 0x01;

        public const uint DBPARAMTYPE_INPUTOUTPUT = 0x02;

        public const uint DBPARAMTYPE_OUTPUT = 0x03;

        public const uint DBPARAMTYPE_RETURNVALUE = 0x04;

        public const uint DB_PT_UNKNOWN = 0x01;

        public const uint DB_PT_PROCEDURE = 0x02;

        public const uint DB_PT_FUNCTION = 0x03;

        public const uint DB_REMOTE = 0x01;

        public const uint DB_LOCAL_SHARED = 0x02;

        public const uint DB_LOCAL_EXCLUSIVE = 0x03;

        public const uint DB_COLLATION_ASC = 0x01;

        public const uint DB_COLLATION_DESC = 0x02;

        public const uint DB_UNSEARCHABLE = 0x01;

        public const uint DB_LIKE_ONLY = 0x02;

        public const uint DB_ALL_EXCEPT_LIKE = 0x03;

        public const uint DB_SEARCHABLE = 0x04;

        public const uint MDTREEOP_CHILDREN = 0x01;

        public const uint MDTREEOP_SIBLINGS = 0x02;

        public const uint MDTREEOP_PARENT = 0x04;

        public const uint MDTREEOP_SELF = 0x08;

        public const uint MDTREEOP_DESCENDANTS = 0x10;

        public const uint MDTREEOP_ANCESTORS = 0x20;

        public const uint MD_DIMTYPE_UNKNOWN = 0x00;

        public const uint MD_DIMTYPE_TIME = 0x01;

        public const uint MD_DIMTYPE_MEASURE = 0x02;

        public const uint MD_DIMTYPE_OTHER = 0x03;

        public const uint MDLEVEL_TYPE_UNKNOWN = 0x0000;

        public const uint MDLEVEL_TYPE_REGULAR = 0x0000;

        public const uint MDLEVEL_TYPE_ALL = 0x0001;

        public const uint MDLEVEL_TYPE_CALCULATED = 0x0002;

        public const uint MDLEVEL_TYPE_TIME = 0x0004;

        public const uint MDLEVEL_TYPE_RESERVED1 = 0x0008;

        public const uint MDLEVEL_TYPE_TIME_YEARS = 0x0014;

        public const uint MDLEVEL_TYPE_TIME_HALF_YEAR = 0x0024;

        public const uint MDLEVEL_TYPE_TIME_QUARTERS = 0x0044;

        public const uint MDLEVEL_TYPE_TIME_MONTHS = 0x0084;

        public const uint MDLEVEL_TYPE_TIME_WEEKS = 0x0104;

        public const uint MDLEVEL_TYPE_TIME_DAYS = 0x0204;

        public const uint MDLEVEL_TYPE_TIME_HOURS = 0x0304;

        public const uint MDLEVEL_TYPE_TIME_MINUTES = 0x0404;

        public const uint MDLEVEL_TYPE_TIME_SECONDS = 0x0804;

        public const uint MDLEVEL_TYPE_TIME_UNDEFINED = 0x1004;

        public const uint MDMEASURE_AGGR_UNKNOWN = 0x00;

        public const uint MDMEASURE_AGGR_SUM = 0x01;

        public const uint MDMEASURE_AGGR_COUNT = 0x02;

        public const uint MDMEASURE_AGGR_MIN = 0x03;

        public const uint MDMEASURE_AGGR_MAX = 0x04;

        public const uint MDMEASURE_AGGR_AVG = 0x05;

        public const uint MDMEASURE_AGGR_VAR = 0x06;

        public const uint MDMEASURE_AGGR_STD = 0x07;

        public const uint MDMEASURE_AGGR_CALCULATED = 0x7f;

        public const uint MDPROP_MEMBER = 0x01;

        public const uint MDPROP_CELL = 0x02;

        public const uint MDMEMBER_TYPE_UNKNOWN = 0x00;

        public const uint MDMEMBER_TYPE_REGULAR = 0x01;

        public const uint MDMEMBER_TYPE_ALL = 0x02;

        public const uint MDMEMBER_TYPE_MEASURE = 0x03;

        public const uint MDMEMBER_TYPE_FORMULA = 0x04;

        public const uint MDMEMBER_TYPE_RESERVE1 = 0x05;

        public const uint MDMEMBER_TYPE_RESERVE2 = 0x06;

        public const uint MDMEMBER_TYPE_RESERVE3 = 0x07;

        public const uint MDMEMBER_TYPE_RESERVE4 = 0x08;

        public const uint MDDISPINFO_DRILLED_DOWN = 0x00010000;

        public const uint MDDISPINFO_PARENT_SAME_AS_PREV = 0x00020000;

        public const int DB_COUNTUNAVAILABLE = -1;

        public const uint MDFF_BOLD = 0x01;

        public const uint MDFF_ITALIC = 0x02;

        public const uint MDFF_UNDERLINE = 0x04;

        public const uint MDFF_STRIKEOUT = 0x08;

        public const uint MDAXIS_COLUMNS = 0x00000000;

        public const uint MDAXIS_ROWS = 0x00000001;

        public const uint MDAXIS_PAGES = 0x00000002;

        public const uint MDAXIS_SECTIONS = 0x00000003;

        public const uint MDAXIS_CHAPTERS = 0x00000004;

        public const uint MDAXIS_SLICERS = 0xffffffff;

        public const uint CRESTRICTIONS_DBSCHEMA_ASSERTIONS = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_CATALOGS = 1;

        public const uint CRESTRICTIONS_DBSCHEMA_CHARACTER_SETS = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_COLLATIONS = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_COLUMNS = 4;

        public const uint CRESTRICTIONS_DBSCHEMA_CHECK_CONSTRAINTS = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_CONSTRAINT_COLUMN_USAGE = 4;

        public const uint CRESTRICTIONS_DBSCHEMA_CONSTRAINT_TABLE_USAGE = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_KEY_COLUMN_USAGE = 7;

        public const uint CRESTRICTIONS_DBSCHEMA_REFERENTIAL_CONSTRAINTS = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_TABLE_CONSTRAINTS = 7;

        public const uint CRESTRICTIONS_DBSCHEMA_COLUMN_DOMAIN_USAGE = 4;

        public const uint CRESTRICTIONS_DBSCHEMA_INDEXES = 5;

        public const uint CRESTRICTIONS_DBSCHEMA_OBJECT_ACTIONS = 1;

        public const uint CRESTRICTIONS_DBSCHEMA_OBJECTS = 1;

        public const uint CRESTRICTIONS_DBSCHEMA_COLUMN_PRIVILEGES = 6;

        public const uint CRESTRICTIONS_DBSCHEMA_TABLE_PRIVILEGES = 5;

        public const uint CRESTRICTIONS_DBSCHEMA_USAGE_PRIVILEGES = 6;

        public const uint CRESTRICTIONS_DBSCHEMA_PROCEDURES = 4;

        public const uint CRESTRICTIONS_DBSCHEMA_SCHEMATA = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_SQL_LANGUAGES = 0;

        public const uint CRESTRICTIONS_DBSCHEMA_STATISTICS = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_TABLES = 4;

        public const uint CRESTRICTIONS_DBSCHEMA_TRANSLATIONS = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_PROVIDER_TYPES = 2;

        public const uint CRESTRICTIONS_DBSCHEMA_VIEWS = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_VIEW_COLUMN_USAGE = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_VIEW_TABLE_USAGE = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_PROCEDURE_PARAMETERS = 4;

        public const uint CRESTRICTIONS_DBSCHEMA_FOREIGN_KEYS = 6;

        public const uint CRESTRICTIONS_DBSCHEMA_PRIMARY_KEYS = 3;

        public const uint CRESTRICTIONS_DBSCHEMA_PROCEDURE_COLUMNS = 4;

        public const uint CRESTRICTIONS_DBSCHEMA_TABLES_INFO = 4;

        public const uint CRESTRICTIONS_MDSCHEMA_CUBES = 3;

        public const uint CRESTRICTIONS_MDSCHEMA_DIMENSIONS = 5;

        public const uint CRESTRICTIONS_MDSCHEMA_HIERARCHIES = 6;

        public const uint CRESTRICTIONS_MDSCHEMA_LEVELS = 7;

        public const uint CRESTRICTIONS_MDSCHEMA_MEASURES = 5;

        public const uint CRESTRICTIONS_MDSCHEMA_PROPERTIES = 9;

        public const uint CRESTRICTIONS_MDSCHEMA_MEMBERS = 12;

        public const uint CRESTRICTIONS_DBSCHEMA_TRUSTEE = 4;

        public const uint CRESTRICTIONS_DBSCHEMA_TABLE_STATISTICS = 7;

        public const uint CRESTRICTIONS_DBSCHEMA_CHECK_CONSTRAINTS_BY_TABLE = 6;

        public const uint CRESTRICTIONS_MDSCHEMA_FUNCTIONS = 4;

        public const uint CRESTRICTIONS_MDSCHEMA_ACTIONS = 8;

        public const uint CRESTRICTIONS_MDSCHEMA_COMMANDS = 5;

        public const uint CRESTRICTIONS_MDSCHEMA_SETS = 5;

        public const uint IDENTIFIER_SDK_MASK = 0xF0000000;

        public const uint IDENTIFIER_SDK_ERROR = 0x10000000;

    }
}

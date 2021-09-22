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


namespace Windows.Win32.Storage.IndexServer
{
    public static partial class Apis
    {
        public const uint CI_VERSION_WDS30 = 0x102;

        public const uint CI_VERSION_WDS40 = 0x109;

        public const uint CI_VERSION_WIN70 = 0x700;

        public const uint LIFF_LOAD_DEFINED_FILTER = 1;

        public const uint LIFF_IMPLEMENT_TEXT_FILTER_FALLBACK_POLICY = 2;

        public const uint LIFF_FORCE_TEXT_FILTER_FALLBACK = 3;

        public const uint PID_FILENAME = 100;

        public const uint DBPROP_CI_CATALOG_NAME = 2;

        public const uint DBPROP_CI_INCLUDE_SCOPES = 3;

        public const uint DBPROP_CI_DEPTHS = 4;

        public const uint DBPROP_CI_SCOPE_FLAGS = 4;

        public const uint DBPROP_CI_EXCLUDE_SCOPES = 5;

        public const uint DBPROP_CI_SECURITY_ID = 6;

        public const uint DBPROP_CI_QUERY_TYPE = 7;

        public const uint DBPROP_CI_PROVIDER = 8;

        public const uint CI_PROVIDER_MSSEARCH = 1;

        public const uint CI_PROVIDER_INDEXING_SERVICE = 2;

        public const uint CI_PROVIDER_ALL = 0xffffffff;

        public const uint DBPROP_DEFAULT_EQUALS_BEHAVIOR = 2;

        public const uint DBPROP_USECONTENTINDEX = 2;

        public const uint DBPROP_DEFERNONINDEXEDTRIMMING = 3;

        public const uint DBPROP_USEEXTENDEDDBTYPES = 4;

        public const uint DBPROP_IGNORENOISEONLYCLAUSES = 5;

        public const uint DBPROP_GENERICOPTIONS_STRING = 6;

        public const uint DBPROP_FIRSTROWS = 7;

        public const uint DBPROP_DEFERCATALOGVERIFICATION = 8;

        public const uint DBPROP_CATALOGLISTID = 9;

        public const uint DBPROP_GENERATEPARSETREE = 10;

        public const uint DBPROP_APPLICATION_NAME = 11;

        public const uint DBPROP_FREETEXTANYTERM = 12;

        public const uint DBPROP_FREETEXTUSESTEMMING = 13;

        public const uint DBPROP_IGNORESBRI = 14;

        public const uint DBPROP_DONOTCOMPUTEEXPENSIVEPROPS = 15;

        public const uint DBPROP_ENABLEROWSETEVENTS = 16;

        public const uint DBPROP_MACHINE = 2;

        public const uint DBPROP_CLIENT_CLSID = 3;

        public const uint MSIDXSPROP_ROWSETQUERYSTATUS = 2;

        public const uint MSIDXSPROP_COMMAND_LOCALE_STRING = 3;

        public const uint MSIDXSPROP_QUERY_RESTRICTION = 4;

        public const uint MSIDXSPROP_PARSE_TREE = 5;

        public const uint MSIDXSPROP_MAX_RANK = 6;

        public const uint MSIDXSPROP_RESULTS_FOUND = 7;

        public const uint MSIDXSPROP_WHEREID = 8;

        public const uint MSIDXSPROP_SERVER_VERSION = 9;

        public const uint MSIDXSPROP_SERVER_WINVER_MAJOR = 10;

        public const uint MSIDXSPROP_SERVER_WINVER_MINOR = 11;

        public const uint MSIDXSPROP_SERVER_NLSVERSION = 12;

        public const uint MSIDXSPROP_SERVER_NLSVER_DEFINED = 13;

        public const uint MSIDXSPROP_SAME_SORTORDER_USED = 14;

        public const uint STAT_BUSY = 0;

        public const uint STAT_ERROR = 0x1;

        public const uint STAT_DONE = 0x2;

        public const uint STAT_REFRESH = 0x3;

        public const uint STAT_PARTIAL_SCOPE = 0x8;

        public const uint STAT_NOISE_WORDS = 0x10;

        public const uint STAT_CONTENT_OUT_OF_DATE = 0x20;

        public const uint STAT_REFRESH_INCOMPLETE = 0x40;

        public const uint STAT_CONTENT_QUERY_INCOMPLETE = 0x80;

        public const uint STAT_TIME_LIMIT_EXCEEDED = 0x100;

        public const uint STAT_SHARING_VIOLATION = 0x200;

        public const uint STAT_MISSING_RELDOC = 0x400;

        public const uint STAT_MISSING_PROP_IN_RELDOC = 0x800;

        public const uint STAT_RELDOC_ACCESS_DENIED = 0x1000;

        public const uint STAT_COALESCE_COMP_ALL_NOISE = 0x2000;

        public const uint QUERY_SHALLOW = 0;

        public const uint QUERY_DEEP = 1;

        public const uint QUERY_PHYSICAL_PATH = 0;

        public const uint QUERY_VIRTUAL_PATH = 2;

        public const uint PROPID_QUERY_WORKID = 5;

        public const uint PROPID_QUERY_UNFILTERED = 7;

        public const uint PROPID_QUERY_VIRTUALPATH = 9;

        public const uint PROPID_QUERY_LASTSEENTIME = 10;

        public const uint CICAT_STOPPED = 0x1;

        public const uint CICAT_READONLY = 0x2;

        public const uint CICAT_WRITABLE = 0x4;

        public const uint CICAT_NO_QUERY = 0x8;

        public const uint CICAT_GET_STATE = 0x10;

        public const uint CICAT_ALL_OPENED = 0x20;

        public const uint CI_STATE_SHADOW_MERGE = 0x0001;

        public const uint CI_STATE_MASTER_MERGE = 0x0002;

        public const uint CI_STATE_CONTENT_SCAN_REQUIRED = 0x0004;

        public const uint CI_STATE_ANNEALING_MERGE = 0x0008;

        public const uint CI_STATE_SCANNING = 0x0010;

        public const uint CI_STATE_RECOVERING = 0x0020;

        public const uint CI_STATE_INDEX_MIGRATION_MERGE = 0x0040;

        public const uint CI_STATE_LOW_MEMORY = 0x0080;

        public const uint CI_STATE_HIGH_IO = 0x0100;

        public const uint CI_STATE_MASTER_MERGE_PAUSED = 0x0200;

        public const uint CI_STATE_READ_ONLY = 0x0400;

        public const uint CI_STATE_BATTERY_POWER = 0x0800;

        public const uint CI_STATE_USER_ACTIVE = 0x1000;

        public const uint CI_STATE_STARTING = 0x2000;

        public const uint CI_STATE_READING_USNS = 0x4000;

        public const uint CI_STATE_DELETION_MERGE = 0x8000;

        public const uint CI_STATE_LOW_DISK = 0x10000;

        public const uint CI_STATE_HIGH_CPU = 0x20000;

        public const uint CI_STATE_BATTERY_POLICY = 0x40000;

        public const uint GENERATE_METHOD_EXACT = 0;

        public const uint GENERATE_METHOD_PREFIX = 1;

        public const uint GENERATE_METHOD_INFLECT = 2;

        public const uint SCOPE_FLAG_MASK = 0x000000ff;

        public const uint SCOPE_FLAG_INCLUDE = 0x00000001;

        public const uint SCOPE_FLAG_DEEP = 0x00000002;

        public const uint SCOPE_TYPE_MASK = 0xffffff00;

        public const uint SCOPE_TYPE_WINPATH = 0x00000100;

        public const uint SCOPE_TYPE_VPATH = 0x00000200;

        public const uint PROPID_QUERY_RANKVECTOR = 0x2;

        public const uint PROPID_QUERY_RANK = 0x3;

        public const uint PROPID_QUERY_HITCOUNT = 0x4;

        public const uint PROPID_QUERY_ALL = 0x6;

        public const uint PROPID_STG_CONTENTS = 0x13;

        public const uint VECTOR_RANK_MIN = 0;

        public const uint VECTOR_RANK_MAX = 1;

        public const uint VECTOR_RANK_INNER = 2;

        public const uint VECTOR_RANK_DICE = 3;

        public const uint VECTOR_RANK_JACCARD = 4;

        public const uint DBSETFUNC_NONE = 0x0;

        public const uint DBSETFUNC_ALL = 0x1;

        public const uint DBSETFUNC_DISTINCT = 0x2;

        public const uint PROXIMITY_UNIT_WORD = 0;

        public const uint PROXIMITY_UNIT_SENTENCE = 1;

        public const uint PROXIMITY_UNIT_PARAGRAPH = 2;

        public const uint PROXIMITY_UNIT_CHAPTER = 3;

    }
}

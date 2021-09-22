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


namespace Windows.Win32.Storage.StructuredStorage
{
    public static partial class Apis
    {
        public const uint MARSHALINTERFACE_MIN = 500;

        public const int ASYNC_MODE_COMPATIBILITY = 0x00000001;

        public const int ASYNC_MODE_DEFAULT = 0x00000000;

        public const int STGTY_REPEAT = 0x00000100;

        public const int STG_TOEND = unchecked((int)0xFFFFFFFF);

        public const int STG_LAYOUT_SEQUENTIAL = 0x00000000;

        public const int STG_LAYOUT_INTERLEAVED = 0x00000001;

        public const uint PROPSETFLAG_DEFAULT = 0;

        public const uint PROPSETFLAG_NONSIMPLE = 1;

        public const uint PROPSETFLAG_ANSI = 2;

        public const uint PROPSETFLAG_UNBUFFERED = 4;

        public const uint PROPSETFLAG_CASE_SENSITIVE = 8;

        public const uint PROPSET_BEHAVIOR_CASE_SENSITIVE = 1;

        public const uint PID_DICTIONARY = 0;

        public const uint PID_CODEPAGE = 0x1;

        public const uint PID_FIRST_NAME_DEFAULT = 0xfff;

        public const uint PID_LOCALE = 0x80000000;

        public const uint PID_MODIFY_TIME = 0x80000001;

        public const uint PID_SECURITY = 0x80000002;

        public const uint PID_BEHAVIOR = 0x80000003;

        public const uint PID_ILLEGAL = 0xffffffff;

        public const uint PID_MIN_READONLY = 0x80000000;

        public const uint PID_MAX_READONLY = 0xbfffffff;

        public const uint PRSPEC_INVALID = 0xffffffff;

        public const uint PROPSETHDR_OSVERSION_UNKNOWN = 0xFFFFFFFF;

        public const int PIDDI_THUMBNAIL = 0x00000002;

        public const int PIDSI_TITLE = 0x00000002;

        public const int PIDSI_SUBJECT = 0x00000003;

        public const int PIDSI_AUTHOR = 0x00000004;

        public const int PIDSI_KEYWORDS = 0x00000005;

        public const int PIDSI_COMMENTS = 0x00000006;

        public const int PIDSI_TEMPLATE = 0x00000007;

        public const int PIDSI_LASTAUTHOR = 0x00000008;

        public const int PIDSI_REVNUMBER = 0x00000009;

        public const int PIDSI_EDITTIME = 0x0000000a;

        public const int PIDSI_LASTPRINTED = 0x0000000b;

        public const int PIDSI_CREATE_DTM = 0x0000000c;

        public const int PIDSI_LASTSAVE_DTM = 0x0000000d;

        public const int PIDSI_PAGECOUNT = 0x0000000e;

        public const int PIDSI_WORDCOUNT = 0x0000000f;

        public const int PIDSI_CHARCOUNT = 0x00000010;

        public const int PIDSI_THUMBNAIL = 0x00000011;

        public const int PIDSI_APPNAME = 0x00000012;

        public const int PIDSI_DOC_SECURITY = 0x00000013;

        public const uint PIDDSI_CATEGORY = 0x00000002;

        public const uint PIDDSI_PRESFORMAT = 0x00000003;

        public const uint PIDDSI_BYTECOUNT = 0x00000004;

        public const uint PIDDSI_LINECOUNT = 0x00000005;

        public const uint PIDDSI_PARCOUNT = 0x00000006;

        public const uint PIDDSI_SLIDECOUNT = 0x00000007;

        public const uint PIDDSI_NOTECOUNT = 0x00000008;

        public const uint PIDDSI_HIDDENCOUNT = 0x00000009;

        public const uint PIDDSI_MMCLIPCOUNT = 0x0000000A;

        public const uint PIDDSI_SCALE = 0x0000000B;

        public const uint PIDDSI_HEADINGPAIR = 0x0000000C;

        public const uint PIDDSI_DOCPARTS = 0x0000000D;

        public const uint PIDDSI_MANAGER = 0x0000000E;

        public const uint PIDDSI_COMPANY = 0x0000000F;

        public const uint PIDDSI_LINKSDIRTY = 0x00000010;

        public const int PIDMSI_EDITOR = 0x00000002;

        public const int PIDMSI_SUPPLIER = 0x00000003;

        public const int PIDMSI_SOURCE = 0x00000004;

        public const int PIDMSI_SEQUENCE_NO = 0x00000005;

        public const int PIDMSI_PROJECT = 0x00000006;

        public const int PIDMSI_STATUS = 0x00000007;

        public const int PIDMSI_OWNER = 0x00000008;

        public const int PIDMSI_RATING = 0x00000009;

        public const int PIDMSI_PRODUCTION = 0x0000000A;

        public const int PIDMSI_COPYRIGHT = 0x0000000B;

        public const uint CWCSTORAGENAME = 32;

        public const int STGM_DIRECT = 0x00000000;

        public const int STGM_TRANSACTED = 0x00010000;

        public const int STGM_SIMPLE = 0x08000000;

        public const int STGM_READ = 0x00000000;

        public const int STGM_WRITE = 0x00000001;

        public const int STGM_READWRITE = 0x00000002;

        public const int STGM_SHARE_DENY_NONE = 0x00000040;

        public const int STGM_SHARE_DENY_READ = 0x00000030;

        public const int STGM_SHARE_DENY_WRITE = 0x00000020;

        public const int STGM_SHARE_EXCLUSIVE = 0x00000010;

        public const int STGM_PRIORITY = 0x00040000;

        public const int STGM_DELETEONRELEASE = 0x04000000;

        public const int STGM_NOSCRATCH = 0x00100000;

        public const int STGM_CREATE = 0x00001000;

        public const int STGM_CONVERT = 0x00020000;

        public const int STGM_FAILIFTHERE = 0x00000000;

        public const int STGM_NOSNAPSHOT = 0x00200000;

        public const int STGM_DIRECT_SWMR = 0x00400000;

        public const uint STGFMT_STORAGE = 0;

        public const uint STGFMT_NATIVE = 1;

        public const uint STGFMT_FILE = 3;

        public const uint STGFMT_ANY = 4;

        public const uint STGFMT_DOCFILE = 5;

        public const uint STGFMT_DOCUMENT = 0;

        public const uint STGOPTIONS_VERSION = 1;

        public const uint CCH_MAX_PROPSTG_NAME = 31;

        public const uint JET_bitConfigStoreReadControlInhibitRead = 0x1;

        public const uint JET_bitConfigStoreReadControlDisableAll = 0x2;

        public const uint JET_bitConfigStoreReadControlDefault = 0x0;

        public const uint JET_bitDefragmentBatchStart = 0x00000001;

        public const uint JET_bitDefragmentBatchStop = 0x00000002;

        public const uint JET_bitDefragmentAvailSpaceTreesOnly = 0x00000040;

        public const uint JET_bitDefragmentNoPartialMerges = 0x00000080;

        public const uint JET_bitDefragmentBTree = 0x00000100;

        public const uint JET_cbtypNull = 0x00000000;

        public const uint JET_cbtypFinalize = 0x00000001;

        public const uint JET_cbtypBeforeInsert = 0x00000002;

        public const uint JET_cbtypAfterInsert = 0x00000004;

        public const uint JET_cbtypBeforeReplace = 0x00000008;

        public const uint JET_cbtypAfterReplace = 0x00000010;

        public const uint JET_cbtypBeforeDelete = 0x00000020;

        public const uint JET_cbtypAfterDelete = 0x00000040;

        public const uint JET_cbtypUserDefinedDefaultValue = 0x00000080;

        public const uint JET_cbtypOnlineDefragCompleted = 0x00000100;

        public const uint JET_cbtypFreeCursorLS = 0x00000200;

        public const uint JET_cbtypFreeTableLS = 0x00000400;

        public const uint JET_bitTableInfoUpdatable = 0x00000001;

        public const uint JET_bitTableInfoBookmark = 0x00000002;

        public const uint JET_bitTableInfoRollback = 0x00000004;

        public const uint JET_bitObjectSystem = 0x80000000;

        public const uint JET_bitObjectTableFixedDDL = 0x40000000;

        public const uint JET_bitObjectTableTemplate = 0x20000000;

        public const uint JET_bitObjectTableDerived = 0x10000000;

        public const uint JET_bitObjectTableNoFixedVarColumnsInDerivedTables = 0x04000000;

        public const uint JET_MAX_COMPUTERNAME_LENGTH = 15;

        public const uint JET_bitDurableCommitCallbackLogUnavailable = 0x00000001;

        public const uint JET_cbBookmarkMost = 256;

        public const uint JET_cbNameMost = 64;

        public const uint JET_cbFullNameMost = 255;

        public const uint JET_cbColumnLVPageOverhead = 82;

        public const uint JET_cbLVDefaultValueMost = 255;

        public const uint JET_cbColumnMost = 255;

        public const uint JET_cbLVColumnMost = 0x7FFFFFFF;

        public const uint JET_cbKeyMost8KBytePage = 2000;

        public const uint JET_cbKeyMost4KBytePage = 1000;

        public const uint JET_cbKeyMost2KBytePage = 500;

        public const uint JET_cbKeyMostMin = 255;

        public const uint JET_cbKeyMost = 255;

        public const uint JET_cbLimitKeyMost = 256;

        public const uint JET_cbPrimaryKeyMost = 255;

        public const uint JET_cbSecondaryKeyMost = 255;

        public const uint JET_ccolKeyMost = 16;

        public const uint JET_ccolMost = 0x0000fee0;

        public const uint JET_ccolFixedMost = 0x0000007f;

        public const uint JET_ccolVarMost = 0x00000080;

        public const uint JET_EventLoggingDisable = 0;

        public const uint JET_EventLoggingLevelMin = 1;

        public const uint JET_EventLoggingLevelLow = 25;

        public const uint JET_EventLoggingLevelMedium = 50;

        public const uint JET_EventLoggingLevelHigh = 75;

        public const uint JET_EventLoggingLevelMax = 100;

        public const uint JET_IOPriorityNormal = 0x0;

        public const uint JET_IOPriorityLow = 0x1;

        public const uint JET_configDefault = 0x0001;

        public const uint JET_configRemoveQuotas = 0x0002;

        public const uint JET_configLowDiskFootprint = 0x0004;

        public const uint JET_configMediumDiskFootprint = 0x0008;

        public const uint JET_configLowMemory = 0x0010;

        public const uint JET_configDynamicMediumMemory = 0x0020;

        public const uint JET_configLowPower = 0x0040;

        public const uint JET_configSSDProfileIO = 0x0080;

        public const uint JET_configRunSilent = 0x0100;

        public const uint JET_configUnthrottledMemory = 0x0200;

        public const uint JET_configHighConcurrencyScaling = 0x0400;

        public const uint JET_paramSystemPath = 0;

        public const uint JET_paramTempPath = 1;

        public const uint JET_paramLogFilePath = 2;

        public const uint JET_paramBaseName = 3;

        public const uint JET_paramEventSource = 4;

        public const uint JET_paramMaxSessions = 5;

        public const uint JET_paramMaxOpenTables = 6;

        public const uint JET_paramPreferredMaxOpenTables = 7;

        public const uint JET_paramCachedClosedTables = 125;

        public const uint JET_paramMaxCursors = 8;

        public const uint JET_paramMaxVerPages = 9;

        public const uint JET_paramPreferredVerPages = 63;

        public const uint JET_paramGlobalMinVerPages = 81;

        public const uint JET_paramVersionStoreTaskQueueMax = 105;

        public const uint JET_paramMaxTemporaryTables = 10;

        public const uint JET_paramLogFileSize = 11;

        public const uint JET_paramLogBuffers = 12;

        public const uint JET_paramWaitLogFlush = 13;

        public const uint JET_paramLogCheckpointPeriod = 14;

        public const uint JET_paramLogWaitingUserMax = 15;

        public const uint JET_paramCommitDefault = 16;

        public const uint JET_paramCircularLog = 17;

        public const uint JET_paramDbExtensionSize = 18;

        public const uint JET_paramPageTempDBMin = 19;

        public const uint JET_paramPageFragment = 20;

        public const uint JET_paramEnableFileCache = 126;

        public const uint JET_paramVerPageSize = 128;

        public const uint JET_paramConfiguration = 129;

        public const uint JET_paramEnableAdvanced = 130;

        public const uint JET_paramMaxColtyp = 131;

        public const uint JET_paramBatchIOBufferMax = 22;

        public const uint JET_paramCacheSize = 41;

        public const uint JET_paramCacheSizeMin = 60;

        public const uint JET_paramCacheSizeMax = 23;

        public const uint JET_paramCheckpointDepthMax = 24;

        public const uint JET_paramLRUKCorrInterval = 25;

        public const uint JET_paramLRUKHistoryMax = 26;

        public const uint JET_paramLRUKPolicy = 27;

        public const uint JET_paramLRUKTimeout = 28;

        public const uint JET_paramLRUKTrxCorrInterval = 29;

        public const uint JET_paramOutstandingIOMax = 30;

        public const uint JET_paramStartFlushThreshold = 31;

        public const uint JET_paramStopFlushThreshold = 32;

        public const uint JET_paramEnableViewCache = 127;

        public const uint JET_paramCheckpointIOMax = 135;

        public const uint JET_paramTableClass1Name = 137;

        public const uint JET_paramTableClass2Name = 138;

        public const uint JET_paramTableClass3Name = 139;

        public const uint JET_paramTableClass4Name = 140;

        public const uint JET_paramTableClass5Name = 141;

        public const uint JET_paramTableClass6Name = 142;

        public const uint JET_paramTableClass7Name = 143;

        public const uint JET_paramTableClass8Name = 144;

        public const uint JET_paramTableClass9Name = 145;

        public const uint JET_paramTableClass10Name = 146;

        public const uint JET_paramTableClass11Name = 147;

        public const uint JET_paramTableClass12Name = 148;

        public const uint JET_paramTableClass13Name = 149;

        public const uint JET_paramTableClass14Name = 150;

        public const uint JET_paramTableClass15Name = 151;

        public const uint JET_paramIOPriority = 152;

        public const uint JET_paramRecovery = 34;

        public const uint JET_paramEnableOnlineDefrag = 35;

        public const uint JET_paramCheckFormatWhenOpenFail = 44;

        public const uint JET_paramEnableTempTableVersioning = 46;

        public const uint JET_paramIgnoreLogVersion = 47;

        public const uint JET_paramDeleteOldLogs = 48;

        public const uint JET_paramEventSourceKey = 49;

        public const uint JET_paramNoInformationEvent = 50;

        public const uint JET_paramEventLoggingLevel = 51;

        public const uint JET_paramDeleteOutOfRangeLogs = 52;

        public const uint JET_paramAccessDeniedRetryPeriod = 53;

        public const uint JET_paramEnableIndexChecking = 45;

        public const uint JET_paramEnableIndexCleanup = 54;

        public const uint JET_paramDatabasePageSize = 64;

        public const uint JET_paramDisableCallbacks = 65;

        public const uint JET_paramLogFileCreateAsynch = 69;

        public const uint JET_paramErrorToString = 70;

        public const uint JET_paramZeroDatabaseDuringBackup = 71;

        public const uint JET_paramUnicodeIndexDefault = 72;

        public const uint JET_paramRuntimeCallback = 73;

        public const uint JET_paramCleanupMismatchedLogFiles = 77;

        public const uint JET_paramRecordUpgradeDirtyLevel = 78;

        public const uint JET_paramOSSnapshotTimeout = 82;

        public const uint JET_paramExceptionAction = 98;

        public const uint JET_paramEventLogCache = 99;

        public const uint JET_paramCreatePathIfNotExist = 100;

        public const uint JET_paramPageHintCacheSize = 101;

        public const uint JET_paramOneDatabasePerSession = 102;

        public const uint JET_paramMaxInstances = 104;

        public const uint JET_paramDisablePerfmon = 107;

        public const uint JET_paramIndexTuplesLengthMin = 110;

        public const uint JET_paramIndexTuplesLengthMax = 111;

        public const uint JET_paramIndexTuplesToIndexMax = 112;

        public const uint JET_paramAlternateDatabaseRecoveryPath = 113;

        public const uint JET_paramIndexTupleIncrement = 132;

        public const uint JET_paramIndexTupleStart = 133;

        public const uint JET_paramKeyMost = 134;

        public const uint JET_paramLegacyFileNames = 136;

        public const uint JET_paramEnablePersistedCallbacks = 156;

        public const uint JET_paramWaypointLatency = 153;

        public const uint JET_paramDefragmentSequentialBTrees = 160;

        public const uint JET_paramDefragmentSequentialBTreesDensityCheckFrequency = 161;

        public const uint JET_paramIOThrottlingTimeQuanta = 162;

        public const uint JET_paramLVChunkSizeMost = 163;

        public const uint JET_paramMaxCoalesceReadSize = 164;

        public const uint JET_paramMaxCoalesceWriteSize = 165;

        public const uint JET_paramMaxCoalesceReadGapSize = 166;

        public const uint JET_paramMaxCoalesceWriteGapSize = 167;

        public const uint JET_paramEnableDBScanInRecovery = 169;

        public const uint JET_paramDbScanThrottle = 170;

        public const uint JET_paramDbScanIntervalMinSec = 171;

        public const uint JET_paramDbScanIntervalMaxSec = 172;

        public const uint JET_paramCachePriority = 177;

        public const uint JET_paramMaxTransactionSize = 178;

        public const uint JET_paramPrereadIOMax = 179;

        public const uint JET_paramEnableDBScanSerialization = 180;

        public const uint JET_paramHungIOThreshold = 181;

        public const uint JET_paramHungIOActions = 182;

        public const uint JET_paramMinDataForXpress = 183;

        public const uint JET_paramEnableShrinkDatabase = 184;

        public const uint JET_paramProcessFriendlyName = 186;

        public const uint JET_paramDurableCommitCallback = 187;

        public const uint JET_paramEnableSqm = 188;

        public const uint JET_paramConfigStoreSpec = 189;

        public const uint JET_paramMaxValueInvalid = 212;

        public const uint JET_sesparamCommitDefault = 4097;

        public const uint JET_sesparamTransactionLevel = 4099;

        public const uint JET_sesparamOperationContext = 4100;

        public const uint JET_sesparamCorrelationID = 4101;

        public const uint JET_sesparamMaxValueInvalid = 4109;

        public const uint JET_bitESE98FileNames = 0x00000001;

        public const uint JET_bitEightDotThreeSoftCompat = 0x00000002;

        public const uint JET_bitHungIOEvent = 0x00000001;

        public const uint JET_bitShrinkDatabaseOff = 0x0;

        public const uint JET_bitShrinkDatabaseOn = 0x1;

        public const uint JET_bitShrinkDatabaseRealtime = 0x2;

        public const uint JET_bitShrinkDatabaseTrim = 0x1;

        public const uint JET_bitReplayIgnoreMissingDB = 0x00000004;

        public const uint JET_bitRecoveryWithoutUndo = 0x00000008;

        public const uint JET_bitTruncateLogsAfterRecovery = 0x00000010;

        public const uint JET_bitReplayMissingMapEntryDB = 0x00000020;

        public const uint JET_bitLogStreamMustExist = 0x00000040;

        public const uint JET_bitReplayIgnoreLostLogs = 0x00000080;

        public const uint JET_bitKeepDbAttachedAtEndOfRecovery = 0x00001000;

        public const uint JET_bitTermComplete = 0x00000001;

        public const uint JET_bitTermAbrupt = 0x00000002;

        public const uint JET_bitTermStopBackup = 0x00000004;

        public const uint JET_bitTermDirty = 0x00000008;

        public const uint JET_bitIdleFlushBuffers = 0x00000001;

        public const uint JET_bitIdleCompact = 0x00000002;

        public const uint JET_bitIdleStatus = 0x00000004;

        public const uint JET_bitDbReadOnly = 0x00000001;

        public const uint JET_bitDbExclusive = 0x00000002;

        public const uint JET_bitDbDeleteCorruptIndexes = 0x00000010;

        public const uint JET_bitDbDeleteUnicodeIndexes = 0x00000400;

        public const uint JET_bitDbUpgrade = 0x00000200;

        public const uint JET_bitDbEnableBackgroundMaintenance = 0x00000800;

        public const uint JET_bitDbPurgeCacheOnAttach = 0x00001000;

        public const uint JET_bitForceDetach = 0x00000001;

        public const uint JET_bitDbRecoveryOff = 0x00000008;

        public const uint JET_bitDbShadowingOff = 0x00000080;

        public const uint JET_bitDbOverwriteExisting = 0x00000200;

        public const uint JET_bitBackupIncremental = 0x00000001;

        public const uint JET_bitBackupAtomic = 0x00000004;

        public const uint JET_bitBackupSnapshot = 0x00000010;

        public const uint JET_bitBackupEndNormal = 0x0001;

        public const uint JET_bitBackupEndAbort = 0x0002;

        public const uint JET_bitBackupTruncateDone = 0x0100;

        public const uint JET_bitTableCreateFixedDDL = 0x00000001;

        public const uint JET_bitTableCreateTemplateTable = 0x00000002;

        public const uint JET_bitTableCreateNoFixedVarColumnsInDerivedTables = 0x00000004;

        public const uint JET_bitTableCreateImmutableStructure = 0x00000008;

        public const uint JET_bitColumnFixed = 0x00000001;

        public const uint JET_bitColumnTagged = 0x00000002;

        public const uint JET_bitColumnNotNULL = 0x00000004;

        public const uint JET_bitColumnVersion = 0x00000008;

        public const uint JET_bitColumnAutoincrement = 0x00000010;

        public const uint JET_bitColumnUpdatable = 0x00000020;

        public const uint JET_bitColumnTTKey = 0x00000040;

        public const uint JET_bitColumnTTDescending = 0x00000080;

        public const uint JET_bitColumnMultiValued = 0x00000400;

        public const uint JET_bitColumnEscrowUpdate = 0x00000800;

        public const uint JET_bitColumnUnversioned = 0x00001000;

        public const uint JET_bitColumnMaybeNull = 0x00002000;

        public const uint JET_bitColumnFinalize = 0x00004000;

        public const uint JET_bitColumnUserDefinedDefault = 0x00008000;

        public const uint JET_bitColumnDeleteOnZero = 0x00020000;

        public const uint JET_bitColumnCompressed = 0x00080000;

        public const uint JET_bitDeleteColumnIgnoreTemplateColumns = 0x00000001;

        public const uint JET_bitMoveFirst = 0x00000000;

        public const uint JET_bitNoMove = 0x00000002;

        public const uint JET_bitNewKey = 0x00000001;

        public const uint JET_bitStrLimit = 0x00000002;

        public const uint JET_bitSubStrLimit = 0x00000004;

        public const uint JET_bitNormalizedKey = 0x00000008;

        public const uint JET_bitKeyDataZeroLength = 0x00000010;

        public const uint JET_bitFullColumnStartLimit = 0x00000100;

        public const uint JET_bitFullColumnEndLimit = 0x00000200;

        public const uint JET_bitPartialColumnStartLimit = 0x00000400;

        public const uint JET_bitPartialColumnEndLimit = 0x00000800;

        public const uint JET_bitRangeInclusive = 0x00000001;

        public const uint JET_bitRangeUpperLimit = 0x00000002;

        public const uint JET_bitRangeInstantDuration = 0x00000004;

        public const uint JET_bitRangeRemove = 0x00000008;

        public const uint JET_bitReadLock = 0x00000001;

        public const uint JET_bitWriteLock = 0x00000002;

        public const uint JET_MoveFirst = 0x80000000;

        public const int JET_MovePrevious = -1;

        public const uint JET_MoveLast = 0x7fffffff;

        public const uint JET_bitMoveKeyNE = 0x00000001;

        public const uint JET_bitSeekEQ = 0x00000001;

        public const uint JET_bitSeekLT = 0x00000002;

        public const uint JET_bitSeekLE = 0x00000004;

        public const uint JET_bitSeekGE = 0x00000008;

        public const uint JET_bitSeekGT = 0x00000010;

        public const uint JET_bitSetIndexRange = 0x00000020;

        public const uint JET_bitCheckUniqueness = 0x00000040;

        public const uint JET_bitBookmarkPermitVirtualCurrency = 0x00000001;

        public const uint JET_bitIndexColumnMustBeNull = 0x00000001;

        public const uint JET_bitIndexColumnMustBeNonNull = 0x00000002;

        public const uint JET_bitRecordInIndex = 0x00000001;

        public const uint JET_bitRecordNotInIndex = 0x00000002;

        public const uint JET_bitIndexUnique = 0x00000001;

        public const uint JET_bitIndexPrimary = 0x00000002;

        public const uint JET_bitIndexDisallowNull = 0x00000004;

        public const uint JET_bitIndexIgnoreNull = 0x00000008;

        public const uint JET_bitIndexIgnoreAnyNull = 0x00000020;

        public const uint JET_bitIndexIgnoreFirstNull = 0x00000040;

        public const uint JET_bitIndexLazyFlush = 0x00000080;

        public const uint JET_bitIndexEmpty = 0x00000100;

        public const uint JET_bitIndexUnversioned = 0x00000200;

        public const uint JET_bitIndexSortNullsHigh = 0x00000400;

        public const uint JET_bitIndexUnicode = 0x00000800;

        public const uint JET_bitIndexTuples = 0x00001000;

        public const uint JET_bitIndexTupleLimits = 0x00002000;

        public const uint JET_bitIndexCrossProduct = 0x00004000;

        public const uint JET_bitIndexKeyMost = 0x00008000;

        public const uint JET_bitIndexDisallowTruncation = 0x00010000;

        public const uint JET_bitIndexNestedTable = 0x00020000;

        public const uint JET_bitIndexDotNetGuid = 0x00040000;

        public const uint JET_bitIndexImmutableStructure = 0x00080000;

        public const uint JET_bitKeyAscending = 0x00000000;

        public const uint JET_bitKeyDescending = 0x00000001;

        public const uint JET_bitTableDenyWrite = 0x00000001;

        public const uint JET_bitTableDenyRead = 0x00000002;

        public const uint JET_bitTableReadOnly = 0x00000004;

        public const uint JET_bitTableUpdatable = 0x00000008;

        public const uint JET_bitTablePermitDDL = 0x00000010;

        public const uint JET_bitTableNoCache = 0x00000020;

        public const uint JET_bitTablePreread = 0x00000040;

        public const uint JET_bitTableOpportuneRead = 0x00000080;

        public const uint JET_bitTableSequential = 0x00008000;

        public const uint JET_bitTableClassMask = 0x001F0000;

        public const uint JET_bitTableClassNone = 0x00000000;

        public const uint JET_bitTableClass1 = 0x00010000;

        public const uint JET_bitTableClass2 = 0x00020000;

        public const uint JET_bitTableClass3 = 0x00030000;

        public const uint JET_bitTableClass4 = 0x00040000;

        public const uint JET_bitTableClass5 = 0x00050000;

        public const uint JET_bitTableClass6 = 0x00060000;

        public const uint JET_bitTableClass7 = 0x00070000;

        public const uint JET_bitTableClass8 = 0x00080000;

        public const uint JET_bitTableClass9 = 0x00090000;

        public const uint JET_bitTableClass10 = 0x000A0000;

        public const uint JET_bitTableClass11 = 0x000B0000;

        public const uint JET_bitTableClass12 = 0x000C0000;

        public const uint JET_bitTableClass13 = 0x000D0000;

        public const uint JET_bitTableClass14 = 0x000E0000;

        public const uint JET_bitTableClass15 = 0x000F0000;

        public const uint JET_bitLSReset = 0x00000001;

        public const uint JET_bitLSCursor = 0x00000002;

        public const uint JET_bitLSTable = 0x00000004;

        public const uint JET_bitPrereadForward = 0x00000001;

        public const uint JET_bitPrereadBackward = 0x00000002;

        public const uint JET_bitPrereadFirstPage = 0x00000004;

        public const uint JET_bitPrereadNormalizedKey = 0x00000008;

        public const uint JET_bitTTIndexed = 0x00000001;

        public const uint JET_bitTTUnique = 0x00000002;

        public const uint JET_bitTTUpdatable = 0x00000004;

        public const uint JET_bitTTScrollable = 0x00000008;

        public const uint JET_bitTTSortNullsHigh = 0x00000010;

        public const uint JET_bitTTForceMaterialization = 0x00000020;

        public const uint JET_bitTTForwardOnly = 0x00000040;

        public const uint JET_bitTTIntrinsicLVsOnly = 0x00000080;

        public const uint JET_bitTTDotNetGuid = 0x00000100;

        public const uint JET_bitSetAppendLV = 0x00000001;

        public const uint JET_bitSetOverwriteLV = 0x00000004;

        public const uint JET_bitSetSizeLV = 0x00000008;

        public const uint JET_bitSetZeroLength = 0x00000020;

        public const uint JET_bitSetSeparateLV = 0x00000040;

        public const uint JET_bitSetUniqueMultiValues = 0x00000080;

        public const uint JET_bitSetUniqueNormalizedMultiValues = 0x00000100;

        public const uint JET_bitSetRevertToDefaultValue = 0x00000200;

        public const uint JET_bitSetIntrinsicLV = 0x00000400;

        public const uint JET_bitSetUncompressed = 0x00010000;

        public const uint JET_bitSetCompressed = 0x00020000;

        public const uint JET_bitSetContiguousLV = 0x00040000;

        public const uint JET_bitSpaceHintsUtilizeParentSpace = 0x00000001;

        public const uint JET_bitCreateHintAppendSequential = 0x00000002;

        public const uint JET_bitCreateHintHotpointSequential = 0x00000004;

        public const uint JET_bitRetrieveHintReserve1 = 0x00000008;

        public const uint JET_bitRetrieveHintTableScanForward = 0x00000010;

        public const uint JET_bitRetrieveHintTableScanBackward = 0x00000020;

        public const uint JET_bitRetrieveHintReserve2 = 0x00000040;

        public const uint JET_bitRetrieveHintReserve3 = 0x00000080;

        public const uint JET_bitDeleteHintTableSequential = 0x00000100;

        public const uint JET_prepInsert = 0;

        public const uint JET_prepReplace = 2;

        public const uint JET_prepCancel = 3;

        public const uint JET_prepReplaceNoLock = 4;

        public const uint JET_prepInsertCopy = 5;

        public const uint JET_prepInsertCopyDeleteOriginal = 7;

        public const uint JET_prepInsertCopyReplaceOriginal = 9;

        public const uint JET_sqmDisable = 0;

        public const uint JET_sqmEnable = 1;

        public const uint JET_sqmFromCEIP = 2;

        public const uint JET_bitUpdateCheckESE97Compatibility = 0x00000001;

        public const uint JET_bitEscrowNoRollback = 0x0001;

        public const uint JET_bitRetrieveCopy = 0x00000001;

        public const uint JET_bitRetrieveFromIndex = 0x00000002;

        public const uint JET_bitRetrieveFromPrimaryBookmark = 0x00000004;

        public const uint JET_bitRetrieveTag = 0x00000008;

        public const uint JET_bitRetrieveNull = 0x00000010;

        public const uint JET_bitRetrieveIgnoreDefault = 0x00000020;

        public const uint JET_bitRetrieveTuple = 0x00000800;

        public const uint JET_bitZeroLength = 0x00000001;

        public const uint JET_bitEnumeratePresenceOnly = 0x00020000;

        public const uint JET_bitEnumerateTaggedOnly = 0x00040000;

        public const uint JET_bitEnumerateCompressOutput = 0x00080000;

        public const uint JET_bitEnumerateIgnoreUserDefinedDefault = 0x00100000;

        public const uint JET_bitEnumerateInRecordOnly = 0x00200000;

        public const uint JET_bitRecordSizeInCopyBuffer = 0x00000001;

        public const uint JET_bitRecordSizeRunningTotal = 0x00000002;

        public const uint JET_bitRecordSizeLocal = 0x00000004;

        public const uint JET_bitTransactionReadOnly = 0x00000001;

        public const uint JET_bitCommitLazyFlush = 0x00000001;

        public const uint JET_bitWaitLastLevel0Commit = 0x00000002;

        public const uint JET_bitWaitAllLevel0Commit = 0x00000008;

        public const uint JET_bitForceNewLog = 0x00000010;

        public const uint JET_bitRollbackAll = 0x00000001;

        public const uint JET_bitIncrementalSnapshot = 0x00000001;

        public const uint JET_bitCopySnapshot = 0x00000002;

        public const uint JET_bitContinueAfterThaw = 0x00000004;

        public const uint JET_bitExplicitPrepare = 0x00000008;

        public const uint JET_bitAllDatabasesSnapshot = 0x00000001;

        public const uint JET_bitAbortSnapshot = 0x00000001;

        public const uint JET_DbInfoFilename = 0;

        public const uint JET_DbInfoConnect = 1;

        public const uint JET_DbInfoCountry = 2;

        public const uint JET_DbInfoLCID = 3;

        public const uint JET_DbInfoLangid = 3;

        public const uint JET_DbInfoCp = 4;

        public const uint JET_DbInfoCollate = 5;

        public const uint JET_DbInfoOptions = 6;

        public const uint JET_DbInfoTransactions = 7;

        public const uint JET_DbInfoVersion = 8;

        public const uint JET_DbInfoIsam = 9;

        public const uint JET_DbInfoFilesize = 10;

        public const uint JET_DbInfoSpaceOwned = 11;

        public const uint JET_DbInfoSpaceAvailable = 12;

        public const uint JET_DbInfoUpgrade = 13;

        public const uint JET_DbInfoMisc = 14;

        public const uint JET_DbInfoDBInUse = 15;

        public const uint JET_DbInfoPageSize = 17;

        public const uint JET_DbInfoFileType = 19;

        public const uint JET_DbInfoFilesizeOnDisk = 21;

        public const uint JET_dbstateJustCreated = 1;

        public const uint JET_dbstateDirtyShutdown = 2;

        public const uint JET_dbstateCleanShutdown = 3;

        public const uint JET_dbstateBeingConverted = 4;

        public const uint JET_dbstateForceDetach = 5;

        public const uint JET_filetypeUnknown = 0;

        public const uint JET_filetypeDatabase = 1;

        public const uint JET_filetypeLog = 3;

        public const uint JET_filetypeCheckpoint = 4;

        public const uint JET_filetypeTempDatabase = 5;

        public const uint JET_filetypeFlushMap = 7;

        public const uint JET_coltypNil = 0;

        public const uint JET_coltypBit = 1;

        public const uint JET_coltypUnsignedByte = 2;

        public const uint JET_coltypShort = 3;

        public const uint JET_coltypLong = 4;

        public const uint JET_coltypCurrency = 5;

        public const uint JET_coltypIEEESingle = 6;

        public const uint JET_coltypIEEEDouble = 7;

        public const uint JET_coltypDateTime = 8;

        public const uint JET_coltypBinary = 9;

        public const uint JET_coltypText = 10;

        public const uint JET_coltypLongBinary = 11;

        public const uint JET_coltypLongText = 12;

        public const uint JET_coltypMax = 13;

        public const uint JET_coltypSLV = 13;

        public const uint JET_coltypUnsignedLong = 14;

        public const uint JET_coltypLongLong = 15;

        public const uint JET_coltypGUID = 16;

        public const uint JET_coltypUnsignedShort = 17;

        public const uint JET_coltypUnsignedLongLong = 18;

        public const uint JET_ColInfoGrbitNonDerivedColumnsOnly = 0x80000000;

        public const uint JET_ColInfoGrbitMinimalInfo = 0x40000000;

        public const uint JET_ColInfoGrbitSortByColumnid = 0x20000000;

        public const uint JET_objtypNil = 0;

        public const uint JET_objtypTable = 1;

        public const uint JET_bitCompactStats = 0x00000020;

        public const uint JET_bitCompactRepair = 0x00000040;

        public const uint JET_snpRepair = 2;

        public const uint JET_snpCompact = 4;

        public const uint JET_snpRestore = 8;

        public const uint JET_snpBackup = 9;

        public const uint JET_snpUpgrade = 10;

        public const uint JET_snpScrub = 11;

        public const uint JET_snpUpgradeRecordFormat = 12;

        public const uint JET_sntBegin = 5;

        public const uint JET_sntRequirements = 7;

        public const uint JET_sntProgress = 0;

        public const uint JET_sntComplete = 6;

        public const uint JET_sntFail = 3;

        public const uint JET_ExceptionMsgBox = 0x0001;

        public const uint JET_ExceptionNone = 0x0002;

        public const uint JET_ExceptionFailFast = 0x0004;

        public const uint JET_OnlineDefragDisable = 0x0000;

        public const uint JET_OnlineDefragAllOBSOLETE = 0x0001;

        public const uint JET_OnlineDefragDatabases = 0x0002;

        public const uint JET_OnlineDefragSpaceTrees = 0x0004;

        public const uint JET_OnlineDefragAll = 0xffff;

        public const uint JET_bitResizeDatabaseOnlyGrow = 0x00000001;

        public const uint JET_bitResizeDatabaseOnlyShrink = 0x00000002;

        public const uint JET_bitStopServiceAll = 0x00000000;

        public const uint JET_bitStopServiceBackgroundUserTasks = 0x00000002;

        public const uint JET_bitStopServiceQuiesceCaches = 0x00000004;

        public const uint JET_bitStopServiceResume = 0x80000000;

        public const uint JET_errSuccess = 0;

        public const int JET_wrnNyi = -1;

        public const int JET_errRfsFailure = -100;

        public const int JET_errRfsNotArmed = -101;

        public const int JET_errFileClose = -102;

        public const int JET_errOutOfThreads = -103;

        public const int JET_errTooManyIO = -105;

        public const int JET_errTaskDropped = -106;

        public const int JET_errInternalError = -107;

        public const int JET_errDisabledFunctionality = -112;

        public const int JET_errUnloadableOSFunctionality = -113;

        public const int JET_errDatabaseBufferDependenciesCorrupted = -255;

        public const uint JET_wrnRemainingVersions = 321;

        public const int JET_errPreviousVersion = -322;

        public const int JET_errPageBoundary = -323;

        public const int JET_errKeyBoundary = -324;

        public const int JET_errBadPageLink = -327;

        public const int JET_errBadBookmark = -328;

        public const int JET_errNTSystemCallFailed = -334;

        public const int JET_errBadParentPageLink = -338;

        public const int JET_errSPAvailExtCacheOutOfSync = -340;

        public const int JET_errSPAvailExtCorrupted = -341;

        public const int JET_errSPAvailExtCacheOutOfMemory = -342;

        public const int JET_errSPOwnExtCorrupted = -343;

        public const int JET_errDbTimeCorrupted = -344;

        public const uint JET_wrnUniqueKey = 345;

        public const int JET_errKeyTruncated = -346;

        public const int JET_errDatabaseLeakInSpace = -348;

        public const int JET_errBadEmptyPage = -351;

        public const int JET_errBadLineCount = -354;

        public const uint JET_wrnSeparateLongValue = 406;

        public const int JET_errKeyTooBig = -408;

        public const int JET_errCannotSeparateIntrinsicLV = -416;

        public const int JET_errSeparatedLongValue = -421;

        public const int JET_errMustBeSeparateLongValue = -423;

        public const int JET_errInvalidPreread = -424;

        public const int JET_errInvalidLoggedOperation = -500;

        public const int JET_errLogFileCorrupt = -501;

        public const int JET_errNoBackupDirectory = -503;

        public const int JET_errBackupDirectoryNotEmpty = -504;

        public const int JET_errBackupInProgress = -505;

        public const int JET_errRestoreInProgress = -506;

        public const int JET_errMissingPreviousLogFile = -509;

        public const int JET_errLogWriteFail = -510;

        public const int JET_errLogDisabledDueToRecoveryFailure = -511;

        public const int JET_errCannotLogDuringRecoveryRedo = -512;

        public const int JET_errLogGenerationMismatch = -513;

        public const int JET_errBadLogVersion = -514;

        public const int JET_errInvalidLogSequence = -515;

        public const int JET_errLoggingDisabled = -516;

        public const int JET_errLogBufferTooSmall = -517;

        public const int JET_errLogSequenceEnd = -519;

        public const int JET_errNoBackup = -520;

        public const int JET_errInvalidBackupSequence = -521;

        public const int JET_errBackupNotAllowedYet = -523;

        public const int JET_errDeleteBackupFileFail = -524;

        public const int JET_errMakeBackupDirectoryFail = -525;

        public const int JET_errInvalidBackup = -526;

        public const int JET_errRecoveredWithErrors = -527;

        public const int JET_errMissingLogFile = -528;

        public const int JET_errLogDiskFull = -529;

        public const int JET_errBadLogSignature = -530;

        public const int JET_errBadDbSignature = -531;

        public const int JET_errBadCheckpointSignature = -532;

        public const int JET_errCheckpointCorrupt = -533;

        public const int JET_errMissingPatchPage = -534;

        public const int JET_errBadPatchPage = -535;

        public const int JET_errRedoAbruptEnded = -536;

        public const int JET_errPatchFileMissing = -538;

        public const int JET_errDatabaseLogSetMismatch = -539;

        public const int JET_errDatabaseStreamingFileMismatch = -540;

        public const int JET_errLogFileSizeMismatch = -541;

        public const int JET_errCheckpointFileNotFound = -542;

        public const int JET_errRequiredLogFilesMissing = -543;

        public const int JET_errSoftRecoveryOnBackupDatabase = -544;

        public const int JET_errLogFileSizeMismatchDatabasesConsistent = -545;

        public const int JET_errLogSectorSizeMismatch = -546;

        public const int JET_errLogSectorSizeMismatchDatabasesConsistent = -547;

        public const int JET_errLogSequenceEndDatabasesConsistent = -548;

        public const int JET_errStreamingDataNotLogged = -549;

        public const int JET_errDatabaseDirtyShutdown = -550;

        public const int JET_errConsistentTimeMismatch = -551;

        public const int JET_errDatabasePatchFileMismatch = -552;

        public const int JET_errEndingRestoreLogTooLow = -553;

        public const int JET_errStartingRestoreLogTooHigh = -554;

        public const int JET_errGivenLogFileHasBadSignature = -555;

        public const int JET_errGivenLogFileIsNotContiguous = -556;

        public const int JET_errMissingRestoreLogFiles = -557;

        public const uint JET_wrnExistingLogFileHasBadSignature = 558;

        public const uint JET_wrnExistingLogFileIsNotContiguous = 559;

        public const int JET_errMissingFullBackup = -560;

        public const int JET_errBadBackupDatabaseSize = -561;

        public const int JET_errDatabaseAlreadyUpgraded = -562;

        public const int JET_errDatabaseIncompleteUpgrade = -563;

        public const uint JET_wrnSkipThisRecord = 564;

        public const int JET_errMissingCurrentLogFiles = -565;

        public const int JET_errDbTimeTooOld = -566;

        public const int JET_errDbTimeTooNew = -567;

        public const int JET_errMissingFileToBackup = -569;

        public const int JET_errLogTornWriteDuringHardRestore = -570;

        public const int JET_errLogTornWriteDuringHardRecovery = -571;

        public const int JET_errLogCorruptDuringHardRestore = -573;

        public const int JET_errLogCorruptDuringHardRecovery = -574;

        public const int JET_errMustDisableLoggingForDbUpgrade = -575;

        public const int JET_errBadRestoreTargetInstance = -577;

        public const uint JET_wrnTargetInstanceRunning = 578;

        public const int JET_errRecoveredWithoutUndo = -579;

        public const int JET_errDatabasesNotFromSameSnapshot = -580;

        public const int JET_errSoftRecoveryOnSnapshot = -581;

        public const int JET_errCommittedLogFilesMissing = -582;

        public const int JET_errSectorSizeNotSupported = -583;

        public const int JET_errRecoveredWithoutUndoDatabasesConsistent = -584;

        public const uint JET_wrnCommittedLogFilesLost = 585;

        public const int JET_errCommittedLogFileCorrupt = -586;

        public const uint JET_wrnCommittedLogFilesRemoved = 587;

        public const uint JET_wrnFinishWithUndo = 588;

        public const int JET_errLogSequenceChecksumMismatch = -590;

        public const uint JET_wrnDatabaseRepaired = 595;

        public const int JET_errPageInitializedMismatch = -596;

        public const int JET_errUnicodeTranslationBufferTooSmall = -601;

        public const int JET_errUnicodeTranslationFail = -602;

        public const int JET_errUnicodeNormalizationNotSupported = -603;

        public const int JET_errUnicodeLanguageValidationFailure = -604;

        public const int JET_errExistingLogFileHasBadSignature = -610;

        public const int JET_errExistingLogFileIsNotContiguous = -611;

        public const int JET_errLogReadVerifyFailure = -612;

        public const int JET_errCheckpointDepthTooDeep = -614;

        public const int JET_errRestoreOfNonBackupDatabase = -615;

        public const int JET_errLogFileNotCopied = -616;

        public const int JET_errTransactionTooLong = -618;

        public const int JET_errEngineFormatVersionNoLongerSupportedTooLow = -619;

        public const int JET_errEngineFormatVersionNotYetImplementedTooHigh = -620;

        public const int JET_errEngineFormatVersionParamTooLowForRequestedFeature = -621;

        public const int JET_errEngineFormatVersionSpecifiedTooLowForLogVersion = -622;

        public const int JET_errEngineFormatVersionSpecifiedTooLowForDatabaseVersion = -623;

        public const int JET_errBackupAbortByServer = -801;

        public const int JET_errInvalidGrbit = -900;

        public const int JET_errTermInProgress = -1000;

        public const int JET_errFeatureNotAvailable = -1001;

        public const int JET_errInvalidName = -1002;

        public const int JET_errInvalidParameter = -1003;

        public const uint JET_wrnColumnNull = 1004;

        public const uint JET_wrnBufferTruncated = 1006;

        public const uint JET_wrnDatabaseAttached = 1007;

        public const int JET_errDatabaseFileReadOnly = -1008;

        public const uint JET_wrnSortOverflow = 1009;

        public const int JET_errInvalidDatabaseId = -1010;

        public const int JET_errOutOfMemory = -1011;

        public const int JET_errOutOfDatabaseSpace = -1012;

        public const int JET_errOutOfCursors = -1013;

        public const int JET_errOutOfBuffers = -1014;

        public const int JET_errTooManyIndexes = -1015;

        public const int JET_errTooManyKeys = -1016;

        public const int JET_errRecordDeleted = -1017;

        public const int JET_errReadVerifyFailure = -1018;

        public const int JET_errPageNotInitialized = -1019;

        public const int JET_errOutOfFileHandles = -1020;

        public const int JET_errDiskReadVerificationFailure = -1021;

        public const int JET_errDiskIO = -1022;

        public const int JET_errInvalidPath = -1023;

        public const int JET_errInvalidSystemPath = -1024;

        public const int JET_errInvalidLogDirectory = -1025;

        public const int JET_errRecordTooBig = -1026;

        public const int JET_errTooManyOpenDatabases = -1027;

        public const int JET_errInvalidDatabase = -1028;

        public const int JET_errNotInitialized = -1029;

        public const int JET_errAlreadyInitialized = -1030;

        public const int JET_errInitInProgress = -1031;

        public const int JET_errFileAccessDenied = -1032;

        public const int JET_errBufferTooSmall = -1038;

        public const uint JET_wrnSeekNotEqual = 1039;

        public const int JET_errTooManyColumns = -1040;

        public const int JET_errContainerNotEmpty = -1043;

        public const int JET_errInvalidFilename = -1044;

        public const int JET_errInvalidBookmark = -1045;

        public const int JET_errColumnInUse = -1046;

        public const int JET_errInvalidBufferSize = -1047;

        public const int JET_errColumnNotUpdatable = -1048;

        public const int JET_errIndexInUse = -1051;

        public const int JET_errLinkNotSupported = -1052;

        public const int JET_errNullKeyDisallowed = -1053;

        public const int JET_errNotInTransaction = -1054;

        public const uint JET_wrnNoErrorInfo = 1055;

        public const int JET_errMustRollback = -1057;

        public const uint JET_wrnNoIdleActivity = 1058;

        public const int JET_errTooManyActiveUsers = -1059;

        public const int JET_errInvalidCountry = -1061;

        public const int JET_errInvalidLanguageId = -1062;

        public const int JET_errInvalidCodePage = -1063;

        public const int JET_errInvalidLCMapStringFlags = -1064;

        public const int JET_errVersionStoreEntryTooBig = -1065;

        public const int JET_errVersionStoreOutOfMemoryAndCleanupTimedOut = -1066;

        public const uint JET_wrnNoWriteLock = 1067;

        public const uint JET_wrnColumnSetNull = 1068;

        public const int JET_errVersionStoreOutOfMemory = -1069;

        public const int JET_errCannotIndex = -1071;

        public const int JET_errRecordNotDeleted = -1072;

        public const int JET_errTooManyMempoolEntries = -1073;

        public const int JET_errOutOfObjectIDs = -1074;

        public const int JET_errOutOfLongValueIDs = -1075;

        public const int JET_errOutOfAutoincrementValues = -1076;

        public const int JET_errOutOfDbtimeValues = -1077;

        public const int JET_errOutOfSequentialIndexValues = -1078;

        public const int JET_errRunningInOneInstanceMode = -1080;

        public const int JET_errRunningInMultiInstanceMode = -1081;

        public const int JET_errSystemParamsAlreadySet = -1082;

        public const int JET_errSystemPathInUse = -1083;

        public const int JET_errLogFilePathInUse = -1084;

        public const int JET_errTempPathInUse = -1085;

        public const int JET_errInstanceNameInUse = -1086;

        public const int JET_errSystemParameterConflict = -1087;

        public const int JET_errInstanceUnavailable = -1090;

        public const int JET_errDatabaseUnavailable = -1091;

        public const int JET_errInstanceUnavailableDueToFatalLogDiskFull = -1092;

        public const int JET_errInvalidSesparamId = -1093;

        public const int JET_errTooManyRecords = -1094;

        public const int JET_errInvalidDbparamId = -1095;

        public const int JET_errOutOfSessions = -1101;

        public const int JET_errWriteConflict = -1102;

        public const int JET_errTransTooDeep = -1103;

        public const int JET_errInvalidSesid = -1104;

        public const int JET_errWriteConflictPrimaryIndex = -1105;

        public const int JET_errInTransaction = -1108;

        public const int JET_errRollbackRequired = -1109;

        public const int JET_errTransReadOnly = -1110;

        public const int JET_errSessionWriteConflict = -1111;

        public const int JET_errRecordTooBigForBackwardCompatibility = -1112;

        public const int JET_errCannotMaterializeForwardOnlySort = -1113;

        public const int JET_errSesidTableIdMismatch = -1114;

        public const int JET_errInvalidInstance = -1115;

        public const int JET_errDirtyShutdown = -1116;

        public const int JET_errReadPgnoVerifyFailure = -1118;

        public const int JET_errReadLostFlushVerifyFailure = -1119;

        public const int JET_errFileSystemCorruption = -1121;

        public const uint JET_wrnShrinkNotPossible = 1122;

        public const int JET_errRecoveryVerifyFailure = -1123;

        public const int JET_errFilteredMoveNotSupported = -1124;

        public const int JET_errDatabaseDuplicate = -1201;

        public const int JET_errDatabaseInUse = -1202;

        public const int JET_errDatabaseNotFound = -1203;

        public const int JET_errDatabaseInvalidName = -1204;

        public const int JET_errDatabaseInvalidPages = -1205;

        public const int JET_errDatabaseCorrupted = -1206;

        public const int JET_errDatabaseLocked = -1207;

        public const int JET_errCannotDisableVersioning = -1208;

        public const int JET_errInvalidDatabaseVersion = -1209;

        public const int JET_errDatabase200Format = -1210;

        public const int JET_errDatabase400Format = -1211;

        public const int JET_errDatabase500Format = -1212;

        public const int JET_errPageSizeMismatch = -1213;

        public const int JET_errTooManyInstances = -1214;

        public const int JET_errDatabaseSharingViolation = -1215;

        public const int JET_errAttachedDatabaseMismatch = -1216;

        public const int JET_errDatabaseInvalidPath = -1217;

        public const int JET_errDatabaseIdInUse = -1218;

        public const int JET_errForceDetachNotAllowed = -1219;

        public const int JET_errCatalogCorrupted = -1220;

        public const int JET_errPartiallyAttachedDB = -1221;

        public const int JET_errDatabaseSignInUse = -1222;

        public const int JET_errDatabaseCorruptedNoRepair = -1224;

        public const int JET_errInvalidCreateDbVersion = -1225;

        public const int JET_errDatabaseNotReady = -1230;

        public const int JET_errDatabaseAttachedForRecovery = -1231;

        public const int JET_errTransactionsNotReadyDuringRecovery = -1232;

        public const uint JET_wrnTableEmpty = 1301;

        public const int JET_errTableLocked = -1302;

        public const int JET_errTableDuplicate = -1303;

        public const int JET_errTableInUse = -1304;

        public const int JET_errObjectNotFound = -1305;

        public const int JET_errDensityInvalid = -1307;

        public const int JET_errTableNotEmpty = -1308;

        public const int JET_errInvalidTableId = -1310;

        public const int JET_errTooManyOpenTables = -1311;

        public const int JET_errIllegalOperation = -1312;

        public const int JET_errTooManyOpenTablesAndCleanupTimedOut = -1313;

        public const int JET_errObjectDuplicate = -1314;

        public const int JET_errInvalidObject = -1316;

        public const int JET_errCannotDeleteTempTable = -1317;

        public const int JET_errCannotDeleteSystemTable = -1318;

        public const int JET_errCannotDeleteTemplateTable = -1319;

        public const int JET_errExclusiveTableLockRequired = -1322;

        public const int JET_errFixedDDL = -1323;

        public const int JET_errFixedInheritedDDL = -1324;

        public const int JET_errCannotNestDDL = -1325;

        public const int JET_errDDLNotInheritable = -1326;

        public const uint JET_wrnTableInUseBySystem = 1327;

        public const int JET_errInvalidSettings = -1328;

        public const int JET_errClientRequestToStopJetService = -1329;

        public const int JET_errCannotAddFixedVarColumnToDerivedTable = -1330;

        public const int JET_errIndexCantBuild = -1401;

        public const int JET_errIndexHasPrimary = -1402;

        public const int JET_errIndexDuplicate = -1403;

        public const int JET_errIndexNotFound = -1404;

        public const int JET_errIndexMustStay = -1405;

        public const int JET_errIndexInvalidDef = -1406;

        public const int JET_errInvalidCreateIndex = -1409;

        public const int JET_errTooManyOpenIndexes = -1410;

        public const int JET_errMultiValuedIndexViolation = -1411;

        public const int JET_errIndexBuildCorrupted = -1412;

        public const int JET_errPrimaryIndexCorrupted = -1413;

        public const int JET_errSecondaryIndexCorrupted = -1414;

        public const uint JET_wrnCorruptIndexDeleted = 1415;

        public const int JET_errInvalidIndexId = -1416;

        public const uint JET_wrnPrimaryIndexOutOfDate = 1417;

        public const uint JET_wrnSecondaryIndexOutOfDate = 1418;

        public const int JET_errIndexTuplesSecondaryIndexOnly = -1430;

        public const int JET_errIndexTuplesTooManyColumns = -1431;

        public const int JET_errIndexTuplesNonUniqueOnly = -1432;

        public const int JET_errIndexTuplesTextBinaryColumnsOnly = -1433;

        public const int JET_errIndexTuplesVarSegMacNotAllowed = -1434;

        public const int JET_errIndexTuplesInvalidLimits = -1435;

        public const int JET_errIndexTuplesCannotRetrieveFromIndex = -1436;

        public const int JET_errIndexTuplesKeyTooSmall = -1437;

        public const int JET_errInvalidLVChunkSize = -1438;

        public const int JET_errColumnCannotBeEncrypted = -1439;

        public const int JET_errCannotIndexOnEncryptedColumn = -1440;

        public const int JET_errColumnLong = -1501;

        public const int JET_errColumnNoChunk = -1502;

        public const int JET_errColumnDoesNotFit = -1503;

        public const int JET_errNullInvalid = -1504;

        public const int JET_errColumnIndexed = -1505;

        public const int JET_errColumnTooBig = -1506;

        public const int JET_errColumnNotFound = -1507;

        public const int JET_errColumnDuplicate = -1508;

        public const int JET_errMultiValuedColumnMustBeTagged = -1509;

        public const int JET_errColumnRedundant = -1510;

        public const int JET_errInvalidColumnType = -1511;

        public const uint JET_wrnColumnMaxTruncated = 1512;

        public const int JET_errTaggedNotNULL = -1514;

        public const int JET_errNoCurrentIndex = -1515;

        public const int JET_errKeyIsMade = -1516;

        public const int JET_errBadColumnId = -1517;

        public const int JET_errBadItagSequence = -1518;

        public const int JET_errColumnInRelationship = -1519;

        public const uint JET_wrnCopyLongValue = 1520;

        public const int JET_errCannotBeTagged = -1521;

        public const int JET_errDefaultValueTooBig = -1524;

        public const int JET_errMultiValuedDuplicate = -1525;

        public const int JET_errLVCorrupted = -1526;

        public const int JET_errMultiValuedDuplicateAfterTruncation = -1528;

        public const int JET_errDerivedColumnCorruption = -1529;

        public const int JET_errInvalidPlaceholderColumn = -1530;

        public const uint JET_wrnColumnSkipped = 1531;

        public const uint JET_wrnColumnNotLocal = 1532;

        public const uint JET_wrnColumnMoreTags = 1533;

        public const uint JET_wrnColumnTruncated = 1534;

        public const uint JET_wrnColumnPresent = 1535;

        public const uint JET_wrnColumnSingleValue = 1536;

        public const uint JET_wrnColumnDefault = 1537;

        public const int JET_errColumnCannotBeCompressed = -1538;

        public const uint JET_wrnColumnNotInRecord = 1539;

        public const int JET_errColumnNoEncryptionKey = -1540;

        public const uint JET_wrnColumnReference = 1541;

        public const int JET_errRecordNotFound = -1601;

        public const int JET_errRecordNoCopy = -1602;

        public const int JET_errNoCurrentRecord = -1603;

        public const int JET_errRecordPrimaryChanged = -1604;

        public const int JET_errKeyDuplicate = -1605;

        public const int JET_errAlreadyPrepared = -1607;

        public const int JET_errKeyNotMade = -1608;

        public const int JET_errUpdateNotPrepared = -1609;

        public const uint JET_wrnDataHasChanged = 1610;

        public const int JET_errDataHasChanged = -1611;

        public const uint JET_wrnKeyChanged = 1618;

        public const int JET_errLanguageNotSupported = -1619;

        public const int JET_errDecompressionFailed = -1620;

        public const int JET_errUpdateMustVersion = -1621;

        public const int JET_errDecryptionFailed = -1622;

        public const int JET_errEncryptionBadItag = -1623;

        public const int JET_errTooManySorts = -1701;

        public const int JET_errInvalidOnSort = -1702;

        public const int JET_errTempFileOpenError = -1803;

        public const int JET_errTooManyAttachedDatabases = -1805;

        public const int JET_errDiskFull = -1808;

        public const int JET_errPermissionDenied = -1809;

        public const int JET_errFileNotFound = -1811;

        public const int JET_errFileInvalidType = -1812;

        public const uint JET_wrnFileOpenReadOnly = 1813;

        public const int JET_errFileAlreadyExists = -1814;

        public const int JET_errAfterInitialization = -1850;

        public const int JET_errLogCorrupted = -1852;

        public const int JET_errInvalidOperation = -1906;

        public const int JET_errAccessDenied = -1907;

        public const uint JET_wrnIdleFull = 1908;

        public const int JET_errTooManySplits = -1909;

        public const int JET_errSessionSharingViolation = -1910;

        public const int JET_errEntryPointNotFound = -1911;

        public const int JET_errSessionContextAlreadySet = -1912;

        public const int JET_errSessionContextNotSetByThisThread = -1913;

        public const int JET_errSessionInUse = -1914;

        public const int JET_errRecordFormatConversionFailed = -1915;

        public const int JET_errOneDatabasePerSession = -1916;

        public const int JET_errRollbackError = -1917;

        public const int JET_errFlushMapVersionUnsupported = -1918;

        public const int JET_errFlushMapDatabaseMismatch = -1919;

        public const int JET_errFlushMapUnrecoverable = -1920;

        public const uint JET_wrnDefragAlreadyRunning = 2000;

        public const uint JET_wrnDefragNotRunning = 2001;

        public const int JET_errDatabaseAlreadyRunningMaintenance = -2004;

        public const uint JET_wrnCallbackNotRegistered = 2100;

        public const int JET_errCallbackFailed = -2101;

        public const int JET_errCallbackNotResolved = -2102;

        public const int JET_errSpaceHintsInvalid = -2103;

        public const int JET_errOSSnapshotInvalidSequence = -2401;

        public const int JET_errOSSnapshotTimeOut = -2402;

        public const int JET_errOSSnapshotNotAllowed = -2403;

        public const int JET_errOSSnapshotInvalidSnapId = -2404;

        public const int JET_errLSCallbackNotSpecified = -3000;

        public const int JET_errLSAlreadySet = -3001;

        public const int JET_errLSNotSet = -3002;

        public const int JET_errFileIOSparse = -4000;

        public const int JET_errFileIOBeyondEOF = -4001;

        public const int JET_errFileIOAbort = -4002;

        public const int JET_errFileIORetry = -4003;

        public const int JET_errFileIOFail = -4004;

        public const int JET_errFileCompressed = -4005;

        public const uint JET_BASE_NAME_LENGTH = 3;

        public const uint JET_bitDumpMinimum = 0x00000001;

        public const uint JET_bitDumpMaximum = 0x00000002;

        public const uint JET_bitDumpCacheMinimum = 0x00000004;

        public const uint JET_bitDumpCacheMaximum = 0x00000008;

        public const uint JET_bitDumpCacheIncludeDirtyPages = 0x00000010;

        public const uint JET_bitDumpCacheIncludeCachedPages = 0x00000020;

        public const uint JET_bitDumpCacheIncludeCorruptedPages = 0x00000040;

        public const uint JET_bitDumpCacheNoDecommit = 0x00000080;

    }
}

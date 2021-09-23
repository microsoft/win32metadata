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


namespace Windows.Win32.NetworkManagement.NetManagement
{
    public static partial class Apis
    {
        public const uint NERR_BASE = 2100;

        public const uint NERR_PasswordExpired = NERR_BASE+142;

        public const uint CNLEN = 15;

        public const uint LM20_CNLEN = 15;

        public const uint UNCLEN = CNLEN+2;

        public const uint LM20_UNCLEN = LM20_CNLEN+2;

        public const uint LM20_NNLEN = 12;

        public const uint SNLEN = 80;

        public const uint LM20_SNLEN = 15;

        public const uint STXTLEN = 256;

        public const uint LM20_STXTLEN = 63;

        public const uint PATHLEN = 256;

        public const uint LM20_PATHLEN = 256;

        public const uint DEVLEN = 80;

        public const uint LM20_DEVLEN = 8;

        public const uint EVLEN = 16;

        public const uint UNLEN = 256;

        public const uint LM20_UNLEN = 20;

        public const uint PWLEN = 256;

        public const uint LM20_PWLEN = 14;

        public const uint SHPWLEN = 8;

        public const uint CLTYPE_LEN = 12;

        public const uint MAXCOMMENTSZ = 256;

        public const uint LM20_MAXCOMMENTSZ = 48;

        public const uint ALERTSZ = 128;

        public const uint NETBIOS_NAME_LEN = 16;

        public const uint MAX_PREFERRED_LENGTH = 0xFFFFFFFF;

        public const uint CRYPT_KEY_LEN = 7;

        public const uint CRYPT_TXT_LEN = 8;

        public const uint ENCRYPTED_PWLEN = 16;

        public const uint SESSION_PWLEN = 24;

        public const uint SESSION_CRYPT_KLEN = 21;

        public const uint PARMNUM_ALL = 0;

        public const uint PARM_ERROR_UNKNOWN = 0xFFFFFFFF;

        public const uint PARM_ERROR_NONE = 0;

        public const uint PARMNUM_BASE_INFOLEVEL = 1000;

        public const uint PLATFORM_ID_DOS = 300;

        public const uint PLATFORM_ID_OS2 = 400;

        public const uint PLATFORM_ID_NT = 500;

        public const uint PLATFORM_ID_OSF = 600;

        public const uint PLATFORM_ID_VMS = 700;

        public const uint MAX_LANMAN_MESSAGE_ID = 5899;

        public const uint NERR_Success = 0;

        public const uint NERR_NetNotStarted = NERR_BASE+2;

        public const uint NERR_UnknownServer = NERR_BASE+3;

        public const uint NERR_ShareMem = NERR_BASE+4;

        public const uint NERR_NoNetworkResource = NERR_BASE+5;

        public const uint NERR_RemoteOnly = NERR_BASE+6;

        public const uint NERR_DevNotRedirected = NERR_BASE+7;

        public const uint NERR_ServerNotStarted = NERR_BASE+14;

        public const uint NERR_ItemNotFound = NERR_BASE+15;

        public const uint NERR_UnknownDevDir = NERR_BASE+16;

        public const uint NERR_RedirectedPath = NERR_BASE+17;

        public const uint NERR_DuplicateShare = NERR_BASE+18;

        public const uint NERR_NoRoom = NERR_BASE+19;

        public const uint NERR_TooManyItems = NERR_BASE+21;

        public const uint NERR_InvalidMaxUsers = NERR_BASE+22;

        public const uint NERR_BufTooSmall = NERR_BASE+23;

        public const uint NERR_RemoteErr = NERR_BASE+27;

        public const uint NERR_LanmanIniError = NERR_BASE+31;

        public const uint NERR_NetworkError = NERR_BASE+36;

        public const uint NERR_WkstaInconsistentState = NERR_BASE+37;

        public const uint NERR_WkstaNotStarted = NERR_BASE+38;

        public const uint NERR_BrowserNotStarted = NERR_BASE+39;

        public const uint NERR_InternalError = NERR_BASE+40;

        public const uint NERR_BadTransactConfig = NERR_BASE+41;

        public const uint NERR_InvalidAPI = NERR_BASE+42;

        public const uint NERR_BadEventName = NERR_BASE+43;

        public const uint NERR_DupNameReboot = NERR_BASE+44;

        public const uint NERR_CfgCompNotFound = NERR_BASE+46;

        public const uint NERR_CfgParamNotFound = NERR_BASE+47;

        public const uint NERR_LineTooLong = NERR_BASE+49;

        public const uint NERR_QNotFound = NERR_BASE+50;

        public const uint NERR_JobNotFound = NERR_BASE+51;

        public const uint NERR_DestNotFound = NERR_BASE+52;

        public const uint NERR_DestExists = NERR_BASE+53;

        public const uint NERR_QExists = NERR_BASE+54;

        public const uint NERR_QNoRoom = NERR_BASE+55;

        public const uint NERR_JobNoRoom = NERR_BASE+56;

        public const uint NERR_DestNoRoom = NERR_BASE+57;

        public const uint NERR_DestIdle = NERR_BASE+58;

        public const uint NERR_DestInvalidOp = NERR_BASE+59;

        public const uint NERR_ProcNoRespond = NERR_BASE+60;

        public const uint NERR_SpoolerNotLoaded = NERR_BASE+61;

        public const uint NERR_DestInvalidState = NERR_BASE+62;

        public const uint NERR_QInvalidState = NERR_BASE+63;

        public const uint NERR_JobInvalidState = NERR_BASE+64;

        public const uint NERR_SpoolNoMemory = NERR_BASE+65;

        public const uint NERR_DriverNotFound = NERR_BASE+66;

        public const uint NERR_DataTypeInvalid = NERR_BASE+67;

        public const uint NERR_ProcNotFound = NERR_BASE+68;

        public const uint NERR_ServiceTableLocked = NERR_BASE+80;

        public const uint NERR_ServiceTableFull = NERR_BASE+81;

        public const uint NERR_ServiceInstalled = NERR_BASE+82;

        public const uint NERR_ServiceEntryLocked = NERR_BASE+83;

        public const uint NERR_ServiceNotInstalled = NERR_BASE+84;

        public const uint NERR_BadServiceName = NERR_BASE+85;

        public const uint NERR_ServiceCtlTimeout = NERR_BASE+86;

        public const uint NERR_ServiceCtlBusy = NERR_BASE+87;

        public const uint NERR_BadServiceProgName = NERR_BASE+88;

        public const uint NERR_ServiceNotCtrl = NERR_BASE+89;

        public const uint NERR_ServiceKillProc = NERR_BASE+90;

        public const uint NERR_ServiceCtlNotValid = NERR_BASE+91;

        public const uint NERR_NotInDispatchTbl = NERR_BASE+92;

        public const uint NERR_BadControlRecv = NERR_BASE+93;

        public const uint NERR_ServiceNotStarting = NERR_BASE+94;

        public const uint NERR_AlreadyLoggedOn = NERR_BASE+100;

        public const uint NERR_NotLoggedOn = NERR_BASE+101;

        public const uint NERR_BadUsername = NERR_BASE+102;

        public const uint NERR_BadPassword = NERR_BASE+103;

        public const uint NERR_UnableToAddName_W = NERR_BASE+104;

        public const uint NERR_UnableToAddName_F = NERR_BASE+105;

        public const uint NERR_UnableToDelName_W = NERR_BASE+106;

        public const uint NERR_UnableToDelName_F = NERR_BASE+107;

        public const uint NERR_LogonsPaused = NERR_BASE+109;

        public const uint NERR_LogonServerConflict = NERR_BASE+110;

        public const uint NERR_LogonNoUserPath = NERR_BASE+111;

        public const uint NERR_LogonScriptError = NERR_BASE+112;

        public const uint NERR_StandaloneLogon = NERR_BASE+114;

        public const uint NERR_LogonServerNotFound = NERR_BASE+115;

        public const uint NERR_LogonDomainExists = NERR_BASE+116;

        public const uint NERR_NonValidatedLogon = NERR_BASE+117;

        public const uint NERR_ACFNotFound = NERR_BASE+119;

        public const uint NERR_GroupNotFound = NERR_BASE+120;

        public const uint NERR_UserNotFound = NERR_BASE+121;

        public const uint NERR_ResourceNotFound = NERR_BASE+122;

        public const uint NERR_GroupExists = NERR_BASE+123;

        public const uint NERR_UserExists = NERR_BASE+124;

        public const uint NERR_ResourceExists = NERR_BASE+125;

        public const uint NERR_NotPrimary = NERR_BASE+126;

        public const uint NERR_ACFNotLoaded = NERR_BASE+127;

        public const uint NERR_ACFNoRoom = NERR_BASE+128;

        public const uint NERR_ACFFileIOFail = NERR_BASE+129;

        public const uint NERR_ACFTooManyLists = NERR_BASE+130;

        public const uint NERR_UserLogon = NERR_BASE+131;

        public const uint NERR_ACFNoParent = NERR_BASE+132;

        public const uint NERR_CanNotGrowSegment = NERR_BASE+133;

        public const uint NERR_SpeGroupOp = NERR_BASE+134;

        public const uint NERR_NotInCache = NERR_BASE+135;

        public const uint NERR_UserInGroup = NERR_BASE+136;

        public const uint NERR_UserNotInGroup = NERR_BASE+137;

        public const uint NERR_AccountUndefined = NERR_BASE+138;

        public const uint NERR_AccountExpired = NERR_BASE+139;

        public const uint NERR_InvalidWorkstation = NERR_BASE+140;

        public const uint NERR_InvalidLogonHours = NERR_BASE+141;

        public const uint NERR_PasswordCantChange = NERR_BASE+143;

        public const uint NERR_PasswordHistConflict = NERR_BASE+144;

        public const uint NERR_PasswordTooShort = NERR_BASE+145;

        public const uint NERR_PasswordTooRecent = NERR_BASE+146;

        public const uint NERR_InvalidDatabase = NERR_BASE+147;

        public const uint NERR_DatabaseUpToDate = NERR_BASE+148;

        public const uint NERR_SyncRequired = NERR_BASE+149;

        public const uint NERR_UseNotFound = NERR_BASE+150;

        public const uint NERR_BadAsgType = NERR_BASE+151;

        public const uint NERR_DeviceIsShared = NERR_BASE+152;

        public const uint NERR_SameAsComputerName = NERR_BASE+153;

        public const uint NERR_NoComputerName = NERR_BASE+170;

        public const uint NERR_MsgAlreadyStarted = NERR_BASE+171;

        public const uint NERR_MsgInitFailed = NERR_BASE+172;

        public const uint NERR_NameNotFound = NERR_BASE+173;

        public const uint NERR_AlreadyForwarded = NERR_BASE+174;

        public const uint NERR_AddForwarded = NERR_BASE+175;

        public const uint NERR_AlreadyExists = NERR_BASE+176;

        public const uint NERR_TooManyNames = NERR_BASE+177;

        public const uint NERR_DelComputerName = NERR_BASE+178;

        public const uint NERR_LocalForward = NERR_BASE+179;

        public const uint NERR_GrpMsgProcessor = NERR_BASE+180;

        public const uint NERR_PausedRemote = NERR_BASE+181;

        public const uint NERR_BadReceive = NERR_BASE+182;

        public const uint NERR_NameInUse = NERR_BASE+183;

        public const uint NERR_MsgNotStarted = NERR_BASE+184;

        public const uint NERR_NotLocalName = NERR_BASE+185;

        public const uint NERR_NoForwardName = NERR_BASE+186;

        public const uint NERR_RemoteFull = NERR_BASE+187;

        public const uint NERR_NameNotForwarded = NERR_BASE+188;

        public const uint NERR_TruncatedBroadcast = NERR_BASE+189;

        public const uint NERR_InvalidDevice = NERR_BASE+194;

        public const uint NERR_WriteFault = NERR_BASE+195;

        public const uint NERR_DuplicateName = NERR_BASE+197;

        public const uint NERR_DeleteLater = NERR_BASE+198;

        public const uint NERR_IncompleteDel = NERR_BASE+199;

        public const uint NERR_MultipleNets = NERR_BASE+200;

        public const uint NERR_NetNameNotFound = NERR_BASE+210;

        public const uint NERR_DeviceNotShared = NERR_BASE+211;

        public const uint NERR_ClientNameNotFound = NERR_BASE+212;

        public const uint NERR_FileIdNotFound = NERR_BASE+214;

        public const uint NERR_ExecFailure = NERR_BASE+215;

        public const uint NERR_TmpFile = NERR_BASE+216;

        public const uint NERR_TooMuchData = NERR_BASE+217;

        public const uint NERR_DeviceShareConflict = NERR_BASE+218;

        public const uint NERR_BrowserTableIncomplete = NERR_BASE+219;

        public const uint NERR_NotLocalDomain = NERR_BASE+220;

        public const uint NERR_IsDfsShare = NERR_BASE+221;

        public const uint NERR_DevInvalidOpCode = NERR_BASE+231;

        public const uint NERR_DevNotFound = NERR_BASE+232;

        public const uint NERR_DevNotOpen = NERR_BASE+233;

        public const uint NERR_BadQueueDevString = NERR_BASE+234;

        public const uint NERR_BadQueuePriority = NERR_BASE+235;

        public const uint NERR_NoCommDevs = NERR_BASE+237;

        public const uint NERR_QueueNotFound = NERR_BASE+238;

        public const uint NERR_BadDevString = NERR_BASE+240;

        public const uint NERR_BadDev = NERR_BASE+241;

        public const uint NERR_InUseBySpooler = NERR_BASE+242;

        public const uint NERR_CommDevInUse = NERR_BASE+243;

        public const uint NERR_InvalidComputer = NERR_BASE+251;

        public const uint NERR_MaxLenExceeded = NERR_BASE+254;

        public const uint NERR_BadComponent = NERR_BASE+256;

        public const uint NERR_CantType = NERR_BASE+257;

        public const uint NERR_TooManyEntries = NERR_BASE+262;

        public const uint NERR_ProfileFileTooBig = NERR_BASE+270;

        public const uint NERR_ProfileOffset = NERR_BASE+271;

        public const uint NERR_ProfileCleanup = NERR_BASE+272;

        public const uint NERR_ProfileUnknownCmd = NERR_BASE+273;

        public const uint NERR_ProfileLoadErr = NERR_BASE+274;

        public const uint NERR_ProfileSaveErr = NERR_BASE+275;

        public const uint NERR_LogOverflow = NERR_BASE+277;

        public const uint NERR_LogFileChanged = NERR_BASE+278;

        public const uint NERR_LogFileCorrupt = NERR_BASE+279;

        public const uint NERR_SourceIsDir = NERR_BASE+280;

        public const uint NERR_BadSource = NERR_BASE+281;

        public const uint NERR_BadDest = NERR_BASE+282;

        public const uint NERR_DifferentServers = NERR_BASE+283;

        public const uint NERR_RunSrvPaused = NERR_BASE+285;

        public const uint NERR_ErrCommRunSrv = NERR_BASE+289;

        public const uint NERR_ErrorExecingGhost = NERR_BASE+291;

        public const uint NERR_ShareNotFound = NERR_BASE+292;

        public const uint NERR_InvalidLana = NERR_BASE+300;

        public const uint NERR_OpenFiles = NERR_BASE+301;

        public const uint NERR_ActiveConns = NERR_BASE+302;

        public const uint NERR_BadPasswordCore = NERR_BASE+303;

        public const uint NERR_DevInUse = NERR_BASE+304;

        public const uint NERR_LocalDrive = NERR_BASE+305;

        public const uint NERR_AlertExists = NERR_BASE+330;

        public const uint NERR_TooManyAlerts = NERR_BASE+331;

        public const uint NERR_NoSuchAlert = NERR_BASE+332;

        public const uint NERR_BadRecipient = NERR_BASE+333;

        public const uint NERR_AcctLimitExceeded = NERR_BASE+334;

        public const uint NERR_InvalidLogSeek = NERR_BASE+340;

        public const uint NERR_BadUasConfig = NERR_BASE+350;

        public const uint NERR_InvalidUASOp = NERR_BASE+351;

        public const uint NERR_LastAdmin = NERR_BASE+352;

        public const uint NERR_DCNotFound = NERR_BASE+353;

        public const uint NERR_LogonTrackingError = NERR_BASE+354;

        public const uint NERR_NetlogonNotStarted = NERR_BASE+355;

        public const uint NERR_CanNotGrowUASFile = NERR_BASE+356;

        public const uint NERR_TimeDiffAtDC = NERR_BASE+357;

        public const uint NERR_PasswordMismatch = NERR_BASE+358;

        public const uint NERR_NoSuchServer = NERR_BASE+360;

        public const uint NERR_NoSuchSession = NERR_BASE+361;

        public const uint NERR_NoSuchConnection = NERR_BASE+362;

        public const uint NERR_TooManyServers = NERR_BASE+363;

        public const uint NERR_TooManySessions = NERR_BASE+364;

        public const uint NERR_TooManyConnections = NERR_BASE+365;

        public const uint NERR_TooManyFiles = NERR_BASE+366;

        public const uint NERR_NoAlternateServers = NERR_BASE+367;

        public const uint NERR_TryDownLevel = NERR_BASE+370;

        public const uint NERR_UPSDriverNotStarted = NERR_BASE+380;

        public const uint NERR_UPSInvalidConfig = NERR_BASE+381;

        public const uint NERR_UPSInvalidCommPort = NERR_BASE+382;

        public const uint NERR_UPSSignalAsserted = NERR_BASE+383;

        public const uint NERR_UPSShutdownFailed = NERR_BASE+384;

        public const uint NERR_BadDosRetCode = NERR_BASE+400;

        public const uint NERR_ProgNeedsExtraMem = NERR_BASE+401;

        public const uint NERR_BadDosFunction = NERR_BASE+402;

        public const uint NERR_RemoteBootFailed = NERR_BASE+403;

        public const uint NERR_BadFileCheckSum = NERR_BASE+404;

        public const uint NERR_NoRplBootSystem = NERR_BASE+405;

        public const uint NERR_RplLoadrNetBiosErr = NERR_BASE+406;

        public const uint NERR_RplLoadrDiskErr = NERR_BASE+407;

        public const uint NERR_ImageParamErr = NERR_BASE+408;

        public const uint NERR_TooManyImageParams = NERR_BASE+409;

        public const uint NERR_NonDosFloppyUsed = NERR_BASE+410;

        public const uint NERR_RplBootRestart = NERR_BASE+411;

        public const uint NERR_RplSrvrCallFailed = NERR_BASE+412;

        public const uint NERR_CantConnectRplSrvr = NERR_BASE+413;

        public const uint NERR_CantOpenImageFile = NERR_BASE+414;

        public const uint NERR_CallingRplSrvr = NERR_BASE+415;

        public const uint NERR_StartingRplBoot = NERR_BASE+416;

        public const uint NERR_RplBootServiceTerm = NERR_BASE+417;

        public const uint NERR_RplBootStartFailed = NERR_BASE+418;

        public const uint NERR_RPL_CONNECTED = NERR_BASE+419;

        public const uint NERR_BrowserConfiguredToNotRun = NERR_BASE+450;

        public const uint NERR_RplNoAdaptersStarted = NERR_BASE+510;

        public const uint NERR_RplBadRegistry = NERR_BASE+511;

        public const uint NERR_RplBadDatabase = NERR_BASE+512;

        public const uint NERR_RplRplfilesShare = NERR_BASE+513;

        public const uint NERR_RplNotRplServer = NERR_BASE+514;

        public const uint NERR_RplCannotEnum = NERR_BASE+515;

        public const uint NERR_RplWkstaInfoCorrupted = NERR_BASE+516;

        public const uint NERR_RplWkstaNotFound = NERR_BASE+517;

        public const uint NERR_RplWkstaNameUnavailable = NERR_BASE+518;

        public const uint NERR_RplProfileInfoCorrupted = NERR_BASE+519;

        public const uint NERR_RplProfileNotFound = NERR_BASE+520;

        public const uint NERR_RplProfileNameUnavailable = NERR_BASE+521;

        public const uint NERR_RplProfileNotEmpty = NERR_BASE+522;

        public const uint NERR_RplConfigInfoCorrupted = NERR_BASE+523;

        public const uint NERR_RplConfigNotFound = NERR_BASE+524;

        public const uint NERR_RplAdapterInfoCorrupted = NERR_BASE+525;

        public const uint NERR_RplInternal = NERR_BASE+526;

        public const uint NERR_RplVendorInfoCorrupted = NERR_BASE+527;

        public const uint NERR_RplBootInfoCorrupted = NERR_BASE+528;

        public const uint NERR_RplWkstaNeedsUserAcct = NERR_BASE+529;

        public const uint NERR_RplNeedsRPLUSERAcct = NERR_BASE+530;

        public const uint NERR_RplBootNotFound = NERR_BASE+531;

        public const uint NERR_RplIncompatibleProfile = NERR_BASE+532;

        public const uint NERR_RplAdapterNameUnavailable = NERR_BASE+533;

        public const uint NERR_RplConfigNotEmpty = NERR_BASE+534;

        public const uint NERR_RplBootInUse = NERR_BASE+535;

        public const uint NERR_RplBackupDatabase = NERR_BASE+536;

        public const uint NERR_RplAdapterNotFound = NERR_BASE+537;

        public const uint NERR_RplVendorNotFound = NERR_BASE+538;

        public const uint NERR_RplVendorNameUnavailable = NERR_BASE+539;

        public const uint NERR_RplBootNameUnavailable = NERR_BASE+540;

        public const uint NERR_RplConfigNameUnavailable = NERR_BASE+541;

        public const uint NERR_DfsInternalCorruption = NERR_BASE+560;

        public const uint NERR_DfsVolumeDataCorrupt = NERR_BASE+561;

        public const uint NERR_DfsNoSuchVolume = NERR_BASE+562;

        public const uint NERR_DfsVolumeAlreadyExists = NERR_BASE+563;

        public const uint NERR_DfsAlreadyShared = NERR_BASE+564;

        public const uint NERR_DfsNoSuchShare = NERR_BASE+565;

        public const uint NERR_DfsNotALeafVolume = NERR_BASE+566;

        public const uint NERR_DfsLeafVolume = NERR_BASE+567;

        public const uint NERR_DfsVolumeHasMultipleServers = NERR_BASE+568;

        public const uint NERR_DfsCantCreateJunctionPoint = NERR_BASE+569;

        public const uint NERR_DfsServerNotDfsAware = NERR_BASE+570;

        public const uint NERR_DfsBadRenamePath = NERR_BASE+571;

        public const uint NERR_DfsVolumeIsOffline = NERR_BASE+572;

        public const uint NERR_DfsNoSuchServer = NERR_BASE+573;

        public const uint NERR_DfsCyclicalName = NERR_BASE+574;

        public const uint NERR_DfsNotSupportedInServerDfs = NERR_BASE+575;

        public const uint NERR_DfsDuplicateService = NERR_BASE+576;

        public const uint NERR_DfsCantRemoveLastServerShare = NERR_BASE+577;

        public const uint NERR_DfsVolumeIsInterDfs = NERR_BASE+578;

        public const uint NERR_DfsInconsistent = NERR_BASE+579;

        public const uint NERR_DfsServerUpgraded = NERR_BASE+580;

        public const uint NERR_DfsDataIsIdentical = NERR_BASE+581;

        public const uint NERR_DfsCantRemoveDfsRoot = NERR_BASE+582;

        public const uint NERR_DfsChildOrParentInDfs = NERR_BASE+583;

        public const uint NERR_DfsInternalError = NERR_BASE+590;

        public const uint NERR_SetupAlreadyJoined = NERR_BASE+591;

        public const uint NERR_SetupNotJoined = NERR_BASE+592;

        public const uint NERR_SetupDomainController = NERR_BASE+593;

        public const uint NERR_DefaultJoinRequired = NERR_BASE+594;

        public const uint NERR_InvalidWorkgroupName = NERR_BASE+595;

        public const uint NERR_NameUsesIncompatibleCodePage = NERR_BASE+596;

        public const uint NERR_ComputerAccountNotFound = NERR_BASE+597;

        public const uint NERR_PersonalSku = NERR_BASE+598;

        public const uint NERR_SetupCheckDNSConfig = NERR_BASE+599;

        public const uint NERR_AlreadyCloudDomainJoined = NERR_BASE+600;

        public const uint NERR_PasswordMustChange = NERR_BASE + 601;

        public const uint NERR_AccountLockedOut = NERR_BASE + 602;

        public const uint NERR_PasswordTooLong = NERR_BASE + 603;

        public const uint NERR_PasswordNotComplexEnough = NERR_BASE + 604;

        public const uint NERR_PasswordFilterError = NERR_BASE + 605;

        public const uint NERR_NoOfflineJoinInfo = NERR_BASE + 609;

        public const uint NERR_BadOfflineJoinInfo = NERR_BASE + 610;

        public const uint NERR_CantCreateJoinInfo = NERR_BASE + 611;

        public const uint NERR_BadDomainJoinInfo = NERR_BASE + 612;

        public const uint NERR_JoinPerformedMustRestart = NERR_BASE + 613;

        public const uint NERR_NoJoinPending = NERR_BASE + 614;

        public const uint NERR_ValuesNotSet = NERR_BASE + 615;

        public const uint NERR_CantVerifyHostname = NERR_BASE + 616;

        public const uint NERR_CantLoadOfflineHive = NERR_BASE + 617;

        public const uint NERR_ConnectionInsecure = NERR_BASE + 618;

        public const uint NERR_ProvisioningBlobUnsupported = NERR_BASE + 619;

        public const uint NERR_DS8DCRequired = NERR_BASE + 620;

        public const uint NERR_LDAPCapableDCRequired = NERR_BASE + 621;

        public const uint NERR_DS8DCNotFound = NERR_BASE + 622;

        public const uint NERR_TargetVersionUnsupported = NERR_BASE + 623;

        public const uint NERR_InvalidMachineNameForJoin = NERR_BASE + 624;

        public const uint NERR_DS9DCNotFound = NERR_BASE + 625;

        public const uint NERR_PlainTextSecretsRequired = NERR_BASE + 626;

        public const uint NERR_CannotUnjoinAadDomain = NERR_BASE + 627;

        public const uint MAX_NERR = NERR_BASE+899;

        public const uint UF_TEMP_DUPLICATE_ACCOUNT = 0x0100;

        public const uint UF_NORMAL_ACCOUNT = 0x0200;

        public const uint UF_INTERDOMAIN_TRUST_ACCOUNT = 0x0800;

        public const uint UF_WORKSTATION_TRUST_ACCOUNT = 0x1000;

        public const uint UF_SERVER_TRUST_ACCOUNT = 0x2000;

        public const uint UF_MNS_LOGON_ACCOUNT = 0x20000;

        public const uint UF_NO_AUTH_DATA_REQUIRED = 0x2000000;

        public const uint UF_PARTIAL_SECRETS_ACCOUNT = 0x4000000;

        public const uint UF_USE_AES_KEYS = 0x8000000;

        public const uint LG_INCLUDE_INDIRECT = 0x0001;

        public const uint USER_NAME_PARMNUM = 1;

        public const uint USER_PASSWORD_PARMNUM = 3;

        public const uint USER_PASSWORD_AGE_PARMNUM = 4;

        public const uint USER_PRIV_PARMNUM = 5;

        public const uint USER_HOME_DIR_PARMNUM = 6;

        public const uint USER_COMMENT_PARMNUM = 7;

        public const uint USER_FLAGS_PARMNUM = 8;

        public const uint USER_SCRIPT_PATH_PARMNUM = 9;

        public const uint USER_AUTH_FLAGS_PARMNUM = 10;

        public const uint USER_FULL_NAME_PARMNUM = 11;

        public const uint USER_USR_COMMENT_PARMNUM = 12;

        public const uint USER_PARMS_PARMNUM = 13;

        public const uint USER_WORKSTATIONS_PARMNUM = 14;

        public const uint USER_LAST_LOGON_PARMNUM = 15;

        public const uint USER_LAST_LOGOFF_PARMNUM = 16;

        public const uint USER_ACCT_EXPIRES_PARMNUM = 17;

        public const uint USER_MAX_STORAGE_PARMNUM = 18;

        public const uint USER_UNITS_PER_WEEK_PARMNUM = 19;

        public const uint USER_LOGON_HOURS_PARMNUM = 20;

        public const uint USER_PAD_PW_COUNT_PARMNUM = 21;

        public const uint USER_NUM_LOGONS_PARMNUM = 22;

        public const uint USER_LOGON_SERVER_PARMNUM = 23;

        public const uint USER_COUNTRY_CODE_PARMNUM = 24;

        public const uint USER_CODE_PAGE_PARMNUM = 25;

        public const uint USER_PRIMARY_GROUP_PARMNUM = 51;

        public const uint USER_PROFILE = 52;

        public const uint USER_PROFILE_PARMNUM = 52;

        public const uint USER_HOME_DIR_DRIVE_PARMNUM = 53;

        public const uint UNITS_PER_DAY = 24;

        public const uint USER_PRIV_MASK = 0x3;

        public const uint DEF_MIN_PWLEN = 6;

        public const uint DEF_PWUNIQUENESS = 5;

        public const uint DEF_MAX_PWHIST = 8;

        public const uint DEF_MAX_BADPW = 0;

        public const uint VALIDATED_LOGON = 0;

        public const uint PASSWORD_EXPIRED = 2;

        public const uint NON_VALIDATED_LOGON = 3;

        public const uint VALID_LOGOFF = 1;

        public const uint MODALS_MIN_PASSWD_LEN_PARMNUM = 1;

        public const uint MODALS_MAX_PASSWD_AGE_PARMNUM = 2;

        public const uint MODALS_MIN_PASSWD_AGE_PARMNUM = 3;

        public const uint MODALS_FORCE_LOGOFF_PARMNUM = 4;

        public const uint MODALS_PASSWD_HIST_LEN_PARMNUM = 5;

        public const uint MODALS_ROLE_PARMNUM = 6;

        public const uint MODALS_PRIMARY_PARMNUM = 7;

        public const uint MODALS_DOMAIN_NAME_PARMNUM = 8;

        public const uint MODALS_DOMAIN_ID_PARMNUM = 9;

        public const uint MODALS_LOCKOUT_DURATION_PARMNUM = 10;

        public const uint MODALS_LOCKOUT_OBSERVATION_WINDOW_PARMNUM = 11;

        public const uint MODALS_LOCKOUT_THRESHOLD_PARMNUM = 12;

        public const uint GROUPIDMASK = 0x8000;

        public const uint GROUP_ALL_PARMNUM = 0;

        public const uint GROUP_NAME_PARMNUM = 1;

        public const uint GROUP_COMMENT_PARMNUM = 2;

        public const uint GROUP_ATTRIBUTES_PARMNUM = 3;

        public const uint LOCALGROUP_NAME_PARMNUM = 1;

        public const uint LOCALGROUP_COMMENT_PARMNUM = 2;

        public const uint MAXPERMENTRIES = 64;

        public const uint ACCESS_NONE = 0;

        public const uint ACCESS_GROUP = 0x8000;

        public const uint ACCESS_AUDIT = 0x1;

        public const uint ACCESS_SUCCESS_OPEN = 0x10;

        public const uint ACCESS_SUCCESS_WRITE = 0x20;

        public const uint ACCESS_SUCCESS_DELETE = 0x40;

        public const uint ACCESS_SUCCESS_ACL = 0x80;

        public const uint ACCESS_SUCCESS_MASK = 0xF0;

        public const uint ACCESS_FAIL_OPEN = 0x100;

        public const uint ACCESS_FAIL_WRITE = 0x200;

        public const uint ACCESS_FAIL_DELETE = 0x400;

        public const uint ACCESS_FAIL_ACL = 0x800;

        public const uint ACCESS_FAIL_MASK = 0xF00;

        public const uint ACCESS_FAIL_SHIFT = 4;

        public const uint ACCESS_RESOURCE_NAME_PARMNUM = 1;

        public const uint ACCESS_ATTR_PARMNUM = 2;

        public const uint ACCESS_COUNT_PARMNUM = 3;

        public const uint ACCESS_ACCESS_LIST_PARMNUM = 4;

        public const uint NET_VALIDATE_PASSWORD_LAST_SET = 0x00000001;

        public const uint NET_VALIDATE_BAD_PASSWORD_TIME = 0x00000002;

        public const uint NET_VALIDATE_LOCKOUT_TIME = 0x00000004;

        public const uint NET_VALIDATE_BAD_PASSWORD_COUNT = 0x00000008;

        public const uint NET_VALIDATE_PASSWORD_HISTORY_LENGTH = 0x00000010;

        public const uint NET_VALIDATE_PASSWORD_HISTORY = 0x00000020;

        public const uint NETLOGON_CONTROL_QUERY = 1;

        public const uint NETLOGON_CONTROL_REPLICATE = 2;

        public const uint NETLOGON_CONTROL_SYNCHRONIZE = 3;

        public const uint NETLOGON_CONTROL_PDC_REPLICATE = 4;

        public const uint NETLOGON_CONTROL_REDISCOVER = 5;

        public const uint NETLOGON_CONTROL_TC_QUERY = 6;

        public const uint NETLOGON_CONTROL_TRANSPORT_NOTIFY = 7;

        public const uint NETLOGON_CONTROL_FIND_USER = 8;

        public const uint NETLOGON_CONTROL_CHANGE_PASSWORD = 9;

        public const uint NETLOGON_CONTROL_TC_VERIFY = 10;

        public const uint NETLOGON_CONTROL_FORCE_DNS_REG = 11;

        public const uint NETLOGON_CONTROL_QUERY_DNS_REG = 12;

        public const uint NETLOGON_CONTROL_QUERY_ENC_TYPES = 13;

        public const uint NETLOGON_CONTROL_UNLOAD_NETLOGON_DLL = 0xFFFB;

        public const uint NETLOGON_CONTROL_BACKUP_CHANGE_LOG = 0xFFFC;

        public const uint NETLOGON_CONTROL_TRUNCATE_LOG = 0xFFFD;

        public const uint NETLOGON_CONTROL_SET_DBFLAG = 0xFFFE;

        public const uint NETLOGON_CONTROL_BREAKPOINT = 0xFFFF;

        public const uint NETLOGON_REPLICATION_NEEDED = 0x01;

        public const uint NETLOGON_REPLICATION_IN_PROGRESS = 0x02;

        public const uint NETLOGON_FULL_SYNC_REPLICATION = 0x04;

        public const uint NETLOGON_REDO_NEEDED = 0x08;

        public const uint NETLOGON_HAS_IP = 0x10;

        public const uint NETLOGON_HAS_TIMESERV = 0x20;

        public const uint NETLOGON_DNS_UPDATE_FAILURE = 0x40;

        public const uint NETLOGON_VERIFY_STATUS_RETURNED = 0x80;

        public static readonly Guid ServiceAccountPasswordGUID__scanned__ = new Guid(0x262E99C9,    0x6160,    0x4871,    0xAC, 0xEC, 0x4E, 0x61, 0x73, 0x6B, 0x6F, 0x21 );

        public const int SERVICE_ACCOUNT_FLAG_LINK_TO_HOST_ONLY = 0x00000001;

        public const int SERVICE_ACCOUNT_FLAG_ADD_AGAINST_RODC = 0x00000002;

        public const int SERVICE_ACCOUNT_FLAG_UNLINK_FROM_HOST_ONLY = 0x00000001;

        public const int SERVICE_ACCOUNT_FLAG_REMOVE_OFFLINE = 0x00000002;

        public const uint PRJOB_QSTATUS = 0x3;

        public const uint PRJOB_DEVSTATUS = 0x1fc;

        public const uint PRJOB_COMPLETE = 0x4;

        public const uint PRJOB_INTERV = 0x8;

        public const uint PRJOB_ERROR = 0x10;

        public const uint PRJOB_DESTOFFLINE = 0x20;

        public const uint PRJOB_DESTPAUSED = 0x40;

        public const uint PRJOB_NOTIFY = 0x80;

        public const uint PRJOB_DESTNOPAPER = 0x100;

        public const uint PRJOB_DELETED = 0x8000;

        public const uint PRJOB_QS_QUEUED = 0;

        public const uint PRJOB_QS_PAUSED = 1;

        public const uint PRJOB_QS_SPOOLING = 2;

        public const uint PRJOB_QS_PRINTING = 3;

        public const uint JOB_RUN_PERIODICALLY = 0x01;

        public const uint JOB_EXEC_ERROR = 0x02;

        public const uint JOB_RUNS_TODAY = 0x04;

        public const uint JOB_ADD_CURRENT_DATE = 0x08;

        public const uint JOB_NONINTERACTIVE = 0x10;

        public const uint LOGFLAGS_FORWARD = 0;

        public const uint LOGFLAGS_BACKWARD = 0x1;

        public const uint LOGFLAGS_SEEK = 0x2;

        public const uint ACTION_LOCKOUT = 00;

        public const uint ACTION_ADMINUNLOCK = 01;

        public const uint AE_SRVSTATUS = 0;

        public const uint AE_SESSLOGON = 1;

        public const uint AE_SESSLOGOFF = 2;

        public const uint AE_SESSPWERR = 3;

        public const uint AE_CONNSTART = 4;

        public const uint AE_CONNSTOP = 5;

        public const uint AE_CONNREJ = 6;

        public const uint AE_RESACCESS = 7;

        public const uint AE_RESACCESSREJ = 8;

        public const uint AE_CLOSEFILE = 9;

        public const uint AE_SERVICESTAT = 11;

        public const uint AE_ACLMOD = 12;

        public const uint AE_UASMOD = 13;

        public const uint AE_NETLOGON = 14;

        public const uint AE_NETLOGOFF = 15;

        public const uint AE_NETLOGDENIED = 16;

        public const uint AE_ACCLIMITEXCD = 17;

        public const uint AE_RESACCESS2 = 18;

        public const uint AE_ACLMODFAIL = 19;

        public const uint AE_LOCKOUT = 20;

        public const uint AE_GENERIC_TYPE = 21;

        public const uint AE_SRVSTART = 0;

        public const uint AE_SRVPAUSED = 1;

        public const uint AE_SRVCONT = 2;

        public const uint AE_SRVSTOP = 3;

        public const uint AE_GUEST = 0;

        public const uint AE_USER = 1;

        public const uint AE_ADMIN = 2;

        public const uint AE_NORMAL = 0;

        public const uint AE_USERLIMIT = 0;

        public const uint AE_GENERAL = 0;

        public const uint AE_ERROR = 1;

        public const uint AE_SESSDIS = 1;

        public const uint AE_BADPW = 1;

        public const uint AE_AUTODIS = 2;

        public const uint AE_UNSHARE = 2;

        public const uint AE_ADMINPRIVREQD = 2;

        public const uint AE_ADMINDIS = 3;

        public const uint AE_NOACCESSPERM = 3;

        public const uint AE_ACCRESTRICT = 4;

        public const uint AE_NORMAL_CLOSE = 0;

        public const uint AE_SES_CLOSE = 1;

        public const uint AE_ADMIN_CLOSE = 2;

        public const uint AE_LIM_UNKNOWN = 0;

        public const uint AE_LIM_LOGONHOURS = 1;

        public const uint AE_LIM_EXPIRED = 2;

        public const uint AE_LIM_INVAL_WKSTA = 3;

        public const uint AE_LIM_DISABLED = 4;

        public const uint AE_LIM_DELETED = 5;

        public const uint AE_MOD = 0;

        public const uint AE_DELETE = 1;

        public const uint AE_ADD = 2;

        public const uint AE_UAS_USER = 0;

        public const uint AE_UAS_GROUP = 1;

        public const uint AE_UAS_MODALS = 2;

        public const uint SVAUD_SERVICE = 0x1;

        public const uint SVAUD_GOODSESSLOGON = 0x6;

        public const uint SVAUD_BADSESSLOGON = 0x18;

        public const uint SVAUD_GOODNETLOGON = 0x60;

        public const uint SVAUD_BADNETLOGON = 0x180;

        public const uint SVAUD_GOODUSE = 0x600;

        public const uint SVAUD_BADUSE = 0x1800;

        public const uint SVAUD_USERLIST = 0x2000;

        public const uint SVAUD_PERMISSIONS = 0x4000;

        public const uint SVAUD_RESOURCE = 0x8000;

        public const uint SVAUD_LOGONLIM = 0x00010000;

        public const uint AA_AUDIT_ALL = 0x0001;

        public const uint AA_A_OWNER = 0x0004;

        public const uint AA_CLOSE = 0x0008;

        public const uint AA_S_OPEN = 0x0010;

        public const uint AA_S_WRITE = 0x0020;

        public const uint AA_S_CREATE = 0x0020;

        public const uint AA_S_DELETE = 0x0040;

        public const uint AA_S_ACL = 0x0080;

        public const uint AA_F_OPEN = 0x0100;

        public const uint AA_F_WRITE = 0x0200;

        public const uint AA_F_CREATE = 0x0200;

        public const uint AA_F_DELETE = 0x0400;

        public const uint AA_F_ACL = 0x0800;

        public const uint AA_A_OPEN = 0x1000;

        public const uint AA_A_WRITE = 0x2000;

        public const uint AA_A_CREATE = 0x2000;

        public const uint AA_A_DELETE = 0x4000;

        public const uint AA_A_ACL = 0x8000;

        public const uint ERRLOG_BASE = 3100;

        public const uint NELOG_Internal_Error = ERRLOG_BASE + 0;

        public const uint NELOG_Resource_Shortage = ERRLOG_BASE + 1;

        public const uint NELOG_Unable_To_Lock_Segment = ERRLOG_BASE + 2;

        public const uint NELOG_Unable_To_Unlock_Segment = ERRLOG_BASE + 3;

        public const uint NELOG_Uninstall_Service = ERRLOG_BASE + 4;

        public const uint NELOG_Init_Exec_Fail = ERRLOG_BASE + 5;

        public const uint NELOG_Ncb_Error = ERRLOG_BASE + 6;

        public const uint NELOG_Net_Not_Started = ERRLOG_BASE + 7;

        public const uint NELOG_Ioctl_Error = ERRLOG_BASE + 8;

        public const uint NELOG_System_Semaphore = ERRLOG_BASE + 9;

        public const uint NELOG_Init_OpenCreate_Err = ERRLOG_BASE + 10;

        public const uint NELOG_NetBios = ERRLOG_BASE + 11;

        public const uint NELOG_SMB_Illegal = ERRLOG_BASE + 12;

        public const uint NELOG_Service_Fail = ERRLOG_BASE + 13;

        public const uint NELOG_Entries_Lost = ERRLOG_BASE + 14;

        public const uint NELOG_Init_Seg_Overflow = ERRLOG_BASE + 20;

        public const uint NELOG_Srv_No_Mem_Grow = ERRLOG_BASE + 21;

        public const uint NELOG_Access_File_Bad = ERRLOG_BASE + 22;

        public const uint NELOG_Srvnet_Not_Started = ERRLOG_BASE + 23;

        public const uint NELOG_Init_Chardev_Err = ERRLOG_BASE + 24;

        public const uint NELOG_Remote_API = ERRLOG_BASE + 25;

        public const uint NELOG_Ncb_TooManyErr = ERRLOG_BASE + 26;

        public const uint NELOG_Mailslot_err = ERRLOG_BASE + 27;

        public const uint NELOG_ReleaseMem_Alert = ERRLOG_BASE + 28;

        public const uint NELOG_AT_cannot_write = ERRLOG_BASE + 29;

        public const uint NELOG_Cant_Make_Msg_File = ERRLOG_BASE + 30;

        public const uint NELOG_Exec_Netservr_NoMem = ERRLOG_BASE + 31;

        public const uint NELOG_Server_Lock_Failure = ERRLOG_BASE + 32;

        public const uint NELOG_Msg_Shutdown = ERRLOG_BASE + 40;

        public const uint NELOG_Msg_Sem_Shutdown = ERRLOG_BASE + 41;

        public const uint NELOG_Msg_Log_Err = ERRLOG_BASE + 50;

        public const uint NELOG_VIO_POPUP_ERR = ERRLOG_BASE + 51;

        public const uint NELOG_Msg_Unexpected_SMB_Type = ERRLOG_BASE + 52;

        public const uint NELOG_Wksta_Infoseg = ERRLOG_BASE + 60;

        public const uint NELOG_Wksta_Compname = ERRLOG_BASE + 61;

        public const uint NELOG_Wksta_BiosThreadFailure = ERRLOG_BASE + 62;

        public const uint NELOG_Wksta_IniSeg = ERRLOG_BASE + 63;

        public const uint NELOG_Wksta_HostTab_Full = ERRLOG_BASE + 64;

        public const uint NELOG_Wksta_Bad_Mailslot_SMB = ERRLOG_BASE + 65;

        public const uint NELOG_Wksta_UASInit = ERRLOG_BASE + 66;

        public const uint NELOG_Wksta_SSIRelogon = ERRLOG_BASE + 67;

        public const uint NELOG_Build_Name = ERRLOG_BASE + 70;

        public const uint NELOG_Name_Expansion = ERRLOG_BASE + 71;

        public const uint NELOG_Message_Send = ERRLOG_BASE + 72;

        public const uint NELOG_Mail_Slt_Err = ERRLOG_BASE + 73;

        public const uint NELOG_AT_cannot_read = ERRLOG_BASE + 74;

        public const uint NELOG_AT_sched_err = ERRLOG_BASE + 75;

        public const uint NELOG_AT_schedule_file_created = ERRLOG_BASE + 76;

        public const uint NELOG_Srvnet_NB_Open = ERRLOG_BASE + 77;

        public const uint NELOG_AT_Exec_Err = ERRLOG_BASE + 78;

        public const uint NELOG_Lazy_Write_Err = ERRLOG_BASE + 80;

        public const uint NELOG_HotFix = ERRLOG_BASE + 81;

        public const uint NELOG_HardErr_From_Server = ERRLOG_BASE + 82;

        public const uint NELOG_LocalSecFail1 = ERRLOG_BASE + 83;

        public const uint NELOG_LocalSecFail2 = ERRLOG_BASE + 84;

        public const uint NELOG_LocalSecFail3 = ERRLOG_BASE + 85;

        public const uint NELOG_LocalSecGeneralFail = ERRLOG_BASE + 86;

        public const uint NELOG_NetWkSta_Internal_Error = ERRLOG_BASE + 90;

        public const uint NELOG_NetWkSta_No_Resource = ERRLOG_BASE + 91;

        public const uint NELOG_NetWkSta_SMB_Err = ERRLOG_BASE + 92;

        public const uint NELOG_NetWkSta_VC_Err = ERRLOG_BASE + 93;

        public const uint NELOG_NetWkSta_Stuck_VC_Err = ERRLOG_BASE + 94;

        public const uint NELOG_NetWkSta_NCB_Err = ERRLOG_BASE + 95;

        public const uint NELOG_NetWkSta_Write_Behind_Err = ERRLOG_BASE + 96;

        public const uint NELOG_NetWkSta_Reset_Err = ERRLOG_BASE + 97;

        public const uint NELOG_NetWkSta_Too_Many = ERRLOG_BASE + 98;

        public const uint NELOG_Srv_Thread_Failure = ERRLOG_BASE + 104;

        public const uint NELOG_Srv_Close_Failure = ERRLOG_BASE + 105;

        public const uint NELOG_ReplUserCurDir = ERRLOG_BASE + 106;

        public const uint NELOG_ReplCannotMasterDir = ERRLOG_BASE + 107;

        public const uint NELOG_ReplUpdateError = ERRLOG_BASE + 108;

        public const uint NELOG_ReplLostMaster = ERRLOG_BASE + 109;

        public const uint NELOG_NetlogonAuthDCFail = ERRLOG_BASE + 110;

        public const uint NELOG_ReplLogonFailed = ERRLOG_BASE + 111;

        public const uint NELOG_ReplNetErr = ERRLOG_BASE + 112;

        public const uint NELOG_ReplMaxFiles = ERRLOG_BASE + 113;

        public const uint NELOG_ReplMaxTreeDepth = ERRLOG_BASE + 114;

        public const uint NELOG_ReplBadMsg = ERRLOG_BASE + 115;

        public const uint NELOG_ReplSysErr = ERRLOG_BASE + 116;

        public const uint NELOG_ReplUserLoged = ERRLOG_BASE + 117;

        public const uint NELOG_ReplBadImport = ERRLOG_BASE + 118;

        public const uint NELOG_ReplBadExport = ERRLOG_BASE + 119;

        public const uint NELOG_ReplSignalFileErr = ERRLOG_BASE + 120;

        public const uint NELOG_DiskFT = ERRLOG_BASE+121;

        public const uint NELOG_ReplAccessDenied = ERRLOG_BASE + 122;

        public const uint NELOG_NetlogonFailedPrimary = ERRLOG_BASE + 123;

        public const uint NELOG_NetlogonPasswdSetFailed = ERRLOG_BASE + 124;

        public const uint NELOG_NetlogonTrackingError = ERRLOG_BASE + 125;

        public const uint NELOG_NetlogonSyncError = ERRLOG_BASE + 126;

        public const uint NELOG_NetlogonRequireSignOrSealError = ERRLOG_BASE + 127;

        public const uint NELOG_UPS_PowerOut = ERRLOG_BASE + 130;

        public const uint NELOG_UPS_Shutdown = ERRLOG_BASE + 131;

        public const uint NELOG_UPS_CmdFileError = ERRLOG_BASE + 132;

        public const uint NELOG_UPS_CannotOpenDriver = ERRLOG_BASE+133;

        public const uint NELOG_UPS_PowerBack = ERRLOG_BASE + 134;

        public const uint NELOG_UPS_CmdFileConfig = ERRLOG_BASE + 135;

        public const uint NELOG_UPS_CmdFileExec = ERRLOG_BASE + 136;

        public const uint NELOG_Missing_Parameter = ERRLOG_BASE + 150;

        public const uint NELOG_Invalid_Config_Line = ERRLOG_BASE + 151;

        public const uint NELOG_Invalid_Config_File = ERRLOG_BASE + 152;

        public const uint NELOG_File_Changed = ERRLOG_BASE + 153;

        public const uint NELOG_Files_Dont_Fit = ERRLOG_BASE + 154;

        public const uint NELOG_Wrong_DLL_Version = ERRLOG_BASE + 155;

        public const uint NELOG_Error_in_DLL = ERRLOG_BASE + 156;

        public const uint NELOG_System_Error = ERRLOG_BASE + 157;

        public const uint NELOG_FT_ErrLog_Too_Large = ERRLOG_BASE + 158;

        public const uint NELOG_FT_Update_In_Progress = ERRLOG_BASE + 159;

        public const uint NELOG_Joined_Domain = ERRLOG_BASE + 160;

        public const uint NELOG_Joined_Workgroup = ERRLOG_BASE + 161;

        public const uint NELOG_OEM_Code = ERRLOG_BASE + 199;

        public const uint ERRLOG2_BASE = 5700;

        public const uint NELOG_NetlogonSSIInitError = ERRLOG2_BASE + 0;

        public const uint NELOG_NetlogonFailedToUpdateTrustList = ERRLOG2_BASE + 1;

        public const uint NELOG_NetlogonFailedToAddRpcInterface = ERRLOG2_BASE + 2;

        public const uint NELOG_NetlogonFailedToReadMailslot = ERRLOG2_BASE + 3;

        public const uint NELOG_NetlogonFailedToRegisterSC = ERRLOG2_BASE + 4;

        public const uint NELOG_NetlogonChangeLogCorrupt = ERRLOG2_BASE + 5;

        public const uint NELOG_NetlogonFailedToCreateShare = ERRLOG2_BASE + 6;

        public const uint NELOG_NetlogonDownLevelLogonFailed = ERRLOG2_BASE + 7;

        public const uint NELOG_NetlogonDownLevelLogoffFailed = ERRLOG2_BASE + 8;

        public const uint NELOG_NetlogonNTLogonFailed = ERRLOG2_BASE + 9;

        public const uint NELOG_NetlogonNTLogoffFailed = ERRLOG2_BASE + 10;

        public const uint NELOG_NetlogonPartialSyncCallSuccess = ERRLOG2_BASE + 11;

        public const uint NELOG_NetlogonPartialSyncCallFailed = ERRLOG2_BASE + 12;

        public const uint NELOG_NetlogonFullSyncCallSuccess = ERRLOG2_BASE + 13;

        public const uint NELOG_NetlogonFullSyncCallFailed = ERRLOG2_BASE + 14;

        public const uint NELOG_NetlogonPartialSyncSuccess = ERRLOG2_BASE + 15;

        public const uint NELOG_NetlogonPartialSyncFailed = ERRLOG2_BASE + 16;

        public const uint NELOG_NetlogonFullSyncSuccess = ERRLOG2_BASE + 17;

        public const uint NELOG_NetlogonFullSyncFailed = ERRLOG2_BASE + 18;

        public const uint NELOG_NetlogonAuthNoDomainController = ERRLOG2_BASE + 19;

        public const uint NELOG_NetlogonAuthNoTrustLsaSecret = ERRLOG2_BASE + 20;

        public const uint NELOG_NetlogonAuthNoTrustSamAccount = ERRLOG2_BASE + 21;

        public const uint NELOG_NetlogonServerAuthFailed = ERRLOG2_BASE + 22;

        public const uint NELOG_NetlogonServerAuthNoTrustSamAccount = ERRLOG2_BASE + 23;

        public const uint NELOG_FailedToRegisterSC = ERRLOG2_BASE + 24;

        public const uint NELOG_FailedToSetServiceStatus = ERRLOG2_BASE + 25;

        public const uint NELOG_FailedToGetComputerName = ERRLOG2_BASE + 26;

        public const uint NELOG_DriverNotLoaded = ERRLOG2_BASE + 27;

        public const uint NELOG_NoTranportLoaded = ERRLOG2_BASE + 28;

        public const uint NELOG_NetlogonFailedDomainDelta = ERRLOG2_BASE + 29;

        public const uint NELOG_NetlogonFailedGlobalGroupDelta = ERRLOG2_BASE + 30;

        public const uint NELOG_NetlogonFailedLocalGroupDelta = ERRLOG2_BASE + 31;

        public const uint NELOG_NetlogonFailedUserDelta = ERRLOG2_BASE + 32;

        public const uint NELOG_NetlogonFailedPolicyDelta = ERRLOG2_BASE + 33;

        public const uint NELOG_NetlogonFailedTrustedDomainDelta = ERRLOG2_BASE + 34;

        public const uint NELOG_NetlogonFailedAccountDelta = ERRLOG2_BASE + 35;

        public const uint NELOG_NetlogonFailedSecretDelta = ERRLOG2_BASE + 36;

        public const uint NELOG_NetlogonSystemError = ERRLOG2_BASE + 37;

        public const uint NELOG_NetlogonDuplicateMachineAccounts = ERRLOG2_BASE + 38;

        public const uint NELOG_NetlogonTooManyGlobalGroups = ERRLOG2_BASE + 39;

        public const uint NELOG_NetlogonBrowserDriver = ERRLOG2_BASE + 40;

        public const uint NELOG_NetlogonAddNameFailure = ERRLOG2_BASE + 41;

        public const uint NELOG_RplMessages = ERRLOG2_BASE + 42;

        public const uint NELOG_RplXnsBoot = ERRLOG2_BASE + 43;

        public const uint NELOG_RplSystem = ERRLOG2_BASE + 44;

        public const uint NELOG_RplWkstaTimeout = ERRLOG2_BASE + 45;

        public const uint NELOG_RplWkstaFileOpen = ERRLOG2_BASE + 46;

        public const uint NELOG_RplWkstaFileRead = ERRLOG2_BASE + 47;

        public const uint NELOG_RplWkstaMemory = ERRLOG2_BASE + 48;

        public const uint NELOG_RplWkstaFileChecksum = ERRLOG2_BASE + 49;

        public const uint NELOG_RplWkstaFileLineCount = ERRLOG2_BASE + 50;

        public const uint NELOG_RplWkstaBbcFile = ERRLOG2_BASE + 51;

        public const uint NELOG_RplWkstaFileSize = ERRLOG2_BASE + 52;

        public const uint NELOG_RplWkstaInternal = ERRLOG2_BASE + 53;

        public const uint NELOG_RplWkstaWrongVersion = ERRLOG2_BASE + 54;

        public const uint NELOG_RplWkstaNetwork = ERRLOG2_BASE + 55;

        public const uint NELOG_RplAdapterResource = ERRLOG2_BASE + 56;

        public const uint NELOG_RplFileCopy = ERRLOG2_BASE + 57;

        public const uint NELOG_RplFileDelete = ERRLOG2_BASE + 58;

        public const uint NELOG_RplFilePerms = ERRLOG2_BASE + 59;

        public const uint NELOG_RplCheckConfigs = ERRLOG2_BASE + 60;

        public const uint NELOG_RplCreateProfiles = ERRLOG2_BASE + 61;

        public const uint NELOG_RplRegistry = ERRLOG2_BASE + 62;

        public const uint NELOG_RplReplaceRPLDISK = ERRLOG2_BASE + 63;

        public const uint NELOG_RplCheckSecurity = ERRLOG2_BASE + 64;

        public const uint NELOG_RplBackupDatabase = ERRLOG2_BASE + 65;

        public const uint NELOG_RplInitDatabase = ERRLOG2_BASE + 66;

        public const uint NELOG_RplRestoreDatabaseFailure = ERRLOG2_BASE + 67;

        public const uint NELOG_RplRestoreDatabaseSuccess = ERRLOG2_BASE + 68;

        public const uint NELOG_RplInitRestoredDatabase = ERRLOG2_BASE + 69;

        public const uint NELOG_NetlogonSessionTypeWrong = ERRLOG2_BASE + 70;

        public const uint NELOG_RplUpgradeDBTo40 = ERRLOG2_BASE + 71;

        public const uint NELOG_NetlogonLanmanBdcsNotAllowed = ERRLOG2_BASE + 72;

        public const uint NELOG_NetlogonNoDynamicDns = ERRLOG2_BASE + 73;

        public const uint NELOG_NetlogonDynamicDnsRegisterFailure = ERRLOG2_BASE + 74;

        public const uint NELOG_NetlogonDynamicDnsDeregisterFailure = ERRLOG2_BASE + 75;

        public const uint NELOG_NetlogonFailedFileCreate = ERRLOG2_BASE + 76;

        public const uint NELOG_NetlogonGetSubnetToSite = ERRLOG2_BASE + 77;

        public const uint NELOG_NetlogonNoSiteForClient = ERRLOG2_BASE + 78;

        public const uint NELOG_NetlogonBadSiteName = ERRLOG2_BASE + 79;

        public const uint NELOG_NetlogonBadSubnetName = ERRLOG2_BASE + 80;

        public const uint NELOG_NetlogonDynamicDnsServerFailure = ERRLOG2_BASE + 81;

        public const uint NELOG_NetlogonDynamicDnsFailure = ERRLOG2_BASE + 82;

        public const uint NELOG_NetlogonRpcCallCancelled = ERRLOG2_BASE + 83;

        public const uint NELOG_NetlogonDcSiteCovered = ERRLOG2_BASE + 84;

        public const uint NELOG_NetlogonDcSiteNotCovered = ERRLOG2_BASE + 85;

        public const uint NELOG_NetlogonGcSiteCovered = ERRLOG2_BASE + 86;

        public const uint NELOG_NetlogonGcSiteNotCovered = ERRLOG2_BASE + 87;

        public const uint NELOG_NetlogonFailedSpnUpdate = ERRLOG2_BASE + 88;

        public const uint NELOG_NetlogonFailedDnsHostNameUpdate = ERRLOG2_BASE + 89;

        public const uint NELOG_NetlogonAuthNoUplevelDomainController = ERRLOG2_BASE + 90;

        public const uint NELOG_NetlogonAuthDomainDowngraded = ERRLOG2_BASE + 91;

        public const uint NELOG_NetlogonNdncSiteCovered = ERRLOG2_BASE + 92;

        public const uint NELOG_NetlogonNdncSiteNotCovered = ERRLOG2_BASE + 93;

        public const uint NELOG_NetlogonDcOldSiteCovered = ERRLOG2_BASE + 94;

        public const uint NELOG_NetlogonDcSiteNotCoveredAuto = ERRLOG2_BASE + 95;

        public const uint NELOG_NetlogonGcOldSiteCovered = ERRLOG2_BASE + 96;

        public const uint NELOG_NetlogonGcSiteNotCoveredAuto = ERRLOG2_BASE + 97;

        public const uint NELOG_NetlogonNdncOldSiteCovered = ERRLOG2_BASE + 98;

        public const uint NELOG_NetlogonNdncSiteNotCoveredAuto = ERRLOG2_BASE + 99;

        public const uint NELOG_NetlogonSpnMultipleSamAccountNames = ERRLOG2_BASE + 100;

        public const uint NELOG_NetlogonSpnCrackNamesFailure = ERRLOG2_BASE + 101;

        public const uint NELOG_NetlogonNoAddressToSiteMapping = ERRLOG2_BASE + 102;

        public const uint NELOG_NetlogonInvalidGenericParameterValue = ERRLOG2_BASE + 103;

        public const uint NELOG_NetlogonInvalidDwordParameterValue = ERRLOG2_BASE + 104;

        public const uint NELOG_NetlogonServerAuthFailedNoAccount = ERRLOG2_BASE + 105;

        public const uint NELOG_NetlogonNoDynamicDnsManual = ERRLOG2_BASE + 106;

        public const uint NELOG_NetlogonNoSiteForClients = ERRLOG2_BASE + 107;

        public const uint NELOG_NetlogonDnsDeregAborted = ERRLOG2_BASE + 108;

        public const uint NELOG_NetlogonRpcPortRequestFailure = ERRLOG2_BASE + 109;

        public const uint NELOG_NetlogonPartialSiteMappingForClients = ERRLOG2_BASE + 110;

        public const uint NELOG_NetlogonRemoteDynamicDnsRegisterFailure = ERRLOG2_BASE + 111;

        public const uint NELOG_NetlogonRemoteDynamicDnsDeregisterFailure = ERRLOG2_BASE + 112;

        public const uint NELOG_NetlogonRejectedRemoteDynamicDnsRegister = ERRLOG2_BASE + 113;

        public const uint NELOG_NetlogonRejectedRemoteDynamicDnsDeregister = ERRLOG2_BASE + 114;

        public const uint NELOG_NetlogonRemoteDynamicDnsUpdateRequestFailure = ERRLOG2_BASE + 115;

        public const uint NELOG_NetlogonUserValidationReqInitialTimeOut = ERRLOG2_BASE + 116;

        public const uint NELOG_NetlogonUserValidationReqRecurringTimeOut = ERRLOG2_BASE + 117;

        public const uint NELOG_NetlogonUserValidationReqWaitInitialWarning = ERRLOG2_BASE + 118;

        public const uint NELOG_NetlogonUserValidationReqWaitRecurringWarning = ERRLOG2_BASE + 119;

        public const uint NELOG_NetlogonFailedToAddAuthzRpcInterface = ERRLOG2_BASE + 120;

        public const uint NELOG_NetLogonFailedToInitializeAuthzRm = ERRLOG2_BASE + 121;

        public const uint NELOG_NetLogonFailedToInitializeRPCSD = ERRLOG2_BASE + 122;

        public const uint NELOG_NetlogonMachinePasswdSetSucceeded = ERRLOG2_BASE + 123;

        public const uint NELOG_NetlogonMsaPasswdSetSucceeded = ERRLOG2_BASE + 124;

        public const uint NETSETUP_ACCT_DELETE = 0x00000004;

        public const uint NETSETUP_DNS_NAME_CHANGES_ONLY = 0x00001000;

        public const uint NETSETUP_INSTALL_INVOCATION = 0x00040000;

        public const uint NETSETUP_ALT_SAMACCOUNTNAME = 0x00020000;

        public const uint NET_IGNORE_UNSUPPORTED_FLAGS = 0x01;

        public const uint NETSETUP_PROVISION_PERSISTENTSITE = 0x00000020;

        public const uint NETSETUP_PROVISION_CHECK_PWD_ONLY = 0x80000000;

        public const uint NETSETUP_PROVISIONING_PARAMS_WIN8_VERSION = 0x00000001;

        public const uint NETSETUP_PROVISIONING_PARAMS_CURRENT_VERSION = 0x00000002;

        public const uint MSGNAME_NOT_FORWARDED = 0;

        public const uint MSGNAME_FORWARDED_TO = 0x04;

        public const uint MSGNAME_FORWARDED_FROM = 0x10;

        public const int SUPPORTS_ANY = unchecked((int)0xFFFFFFFF);

        public const uint NO_PERMISSION_REQUIRED = 0x00000001;

        public const uint ALLOCATE_RESPONSE = 0x00000002;

        public const uint USE_SPECIFIC_TRANSPORT = 0x80000000;

        public const uint SV_PLATFORM_ID_OS2 = 400;

        public const uint SV_PLATFORM_ID_NT = 500;

        public const uint MAJOR_VERSION_MASK = 0x0F;

        public const int SV_NODISC = -1;

        public const uint SV_PLATFORM_ID_PARMNUM = 101;

        public const uint SV_NAME_PARMNUM = 102;

        public const uint SV_VERSION_MAJOR_PARMNUM = 103;

        public const uint SV_VERSION_MINOR_PARMNUM = 104;

        public const uint SV_TYPE_PARMNUM = 105;

        public const uint SV_COMMENT_PARMNUM = 5;

        public const uint SV_USERS_PARMNUM = 107;

        public const uint SV_DISC_PARMNUM = 10;

        public const uint SV_HIDDEN_PARMNUM = 16;

        public const uint SV_ANNOUNCE_PARMNUM = 17;

        public const uint SV_ANNDELTA_PARMNUM = 18;

        public const uint SV_USERPATH_PARMNUM = 112;

        public const uint SV_ULIST_MTIME_PARMNUM = 401;

        public const uint SV_GLIST_MTIME_PARMNUM = 402;

        public const uint SV_ALIST_MTIME_PARMNUM = 403;

        public const uint SV_ALERTS_PARMNUM = 11;

        public const uint SV_SECURITY_PARMNUM = 405;

        public const uint SV_NUMADMIN_PARMNUM = 406;

        public const uint SV_LANMASK_PARMNUM = 407;

        public const uint SV_GUESTACC_PARMNUM = 408;

        public const uint SV_CHDEVQ_PARMNUM = 410;

        public const uint SV_CHDEVJOBS_PARMNUM = 411;

        public const uint SV_CONNECTIONS_PARMNUM = 412;

        public const uint SV_SHARES_PARMNUM = 413;

        public const uint SV_OPENFILES_PARMNUM = 414;

        public const uint SV_SESSREQS_PARMNUM = 417;

        public const uint SV_ACTIVELOCKS_PARMNUM = 419;

        public const uint SV_NUMREQBUF_PARMNUM = 420;

        public const uint SV_NUMBIGBUF_PARMNUM = 422;

        public const uint SV_NUMFILETASKS_PARMNUM = 423;

        public const uint SV_ALERTSCHED_PARMNUM = 37;

        public const uint SV_ERRORALERT_PARMNUM = 38;

        public const uint SV_LOGONALERT_PARMNUM = 39;

        public const uint SV_ACCESSALERT_PARMNUM = 40;

        public const uint SV_DISKALERT_PARMNUM = 41;

        public const uint SV_NETIOALERT_PARMNUM = 42;

        public const uint SV_MAXAUDITSZ_PARMNUM = 43;

        public const uint SV_SRVHEURISTICS_PARMNUM = 431;

        public const uint SV_SESSOPENS_PARMNUM = 501;

        public const uint SV_SESSVCS_PARMNUM = 502;

        public const uint SV_OPENSEARCH_PARMNUM = 503;

        public const uint SV_SIZREQBUF_PARMNUM = 504;

        public const uint SV_INITWORKITEMS_PARMNUM = 505;

        public const uint SV_MAXWORKITEMS_PARMNUM = 506;

        public const uint SV_RAWWORKITEMS_PARMNUM = 507;

        public const uint SV_IRPSTACKSIZE_PARMNUM = 508;

        public const uint SV_MAXRAWBUFLEN_PARMNUM = 509;

        public const uint SV_SESSUSERS_PARMNUM = 510;

        public const uint SV_SESSCONNS_PARMNUM = 511;

        public const uint SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM = 512;

        public const uint SV_MAXPAGEDMEMORYUSAGE_PARMNUM = 513;

        public const uint SV_ENABLESOFTCOMPAT_PARMNUM = 514;

        public const uint SV_ENABLEFORCEDLOGOFF_PARMNUM = 515;

        public const uint SV_TIMESOURCE_PARMNUM = 516;

        public const uint SV_ACCEPTDOWNLEVELAPIS_PARMNUM = 517;

        public const uint SV_LMANNOUNCE_PARMNUM = 518;

        public const uint SV_DOMAIN_PARMNUM = 519;

        public const uint SV_MAXCOPYREADLEN_PARMNUM = 520;

        public const uint SV_MAXCOPYWRITELEN_PARMNUM = 521;

        public const uint SV_MINKEEPSEARCH_PARMNUM = 522;

        public const uint SV_MAXKEEPSEARCH_PARMNUM = 523;

        public const uint SV_MINKEEPCOMPLSEARCH_PARMNUM = 524;

        public const uint SV_MAXKEEPCOMPLSEARCH_PARMNUM = 525;

        public const uint SV_THREADCOUNTADD_PARMNUM = 526;

        public const uint SV_NUMBLOCKTHREADS_PARMNUM = 527;

        public const uint SV_SCAVTIMEOUT_PARMNUM = 528;

        public const uint SV_MINRCVQUEUE_PARMNUM = 529;

        public const uint SV_MINFREEWORKITEMS_PARMNUM = 530;

        public const uint SV_XACTMEMSIZE_PARMNUM = 531;

        public const uint SV_THREADPRIORITY_PARMNUM = 532;

        public const uint SV_MAXMPXCT_PARMNUM = 533;

        public const uint SV_OPLOCKBREAKWAIT_PARMNUM = 534;

        public const uint SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM = 535;

        public const uint SV_ENABLEOPLOCKS_PARMNUM = 536;

        public const uint SV_ENABLEOPLOCKFORCECLOSE_PARMNUM = 537;

        public const uint SV_ENABLEFCBOPENS_PARMNUM = 538;

        public const uint SV_ENABLERAW_PARMNUM = 539;

        public const uint SV_ENABLESHAREDNETDRIVES_PARMNUM = 540;

        public const uint SV_MINFREECONNECTIONS_PARMNUM = 541;

        public const uint SV_MAXFREECONNECTIONS_PARMNUM = 542;

        public const uint SV_INITSESSTABLE_PARMNUM = 543;

        public const uint SV_INITCONNTABLE_PARMNUM = 544;

        public const uint SV_INITFILETABLE_PARMNUM = 545;

        public const uint SV_INITSEARCHTABLE_PARMNUM = 546;

        public const uint SV_ALERTSCHEDULE_PARMNUM = 547;

        public const uint SV_ERRORTHRESHOLD_PARMNUM = 548;

        public const uint SV_NETWORKERRORTHRESHOLD_PARMNUM = 549;

        public const uint SV_DISKSPACETHRESHOLD_PARMNUM = 550;

        public const uint SV_MAXLINKDELAY_PARMNUM = 552;

        public const uint SV_MINLINKTHROUGHPUT_PARMNUM = 553;

        public const uint SV_LINKINFOVALIDTIME_PARMNUM = 554;

        public const uint SV_SCAVQOSINFOUPDATETIME_PARMNUM = 555;

        public const uint SV_MAXWORKITEMIDLETIME_PARMNUM = 556;

        public const uint SV_MAXRAWWORKITEMS_PARMNUM = 557;

        public const uint SV_PRODUCTTYPE_PARMNUM = 560;

        public const uint SV_SERVERSIZE_PARMNUM = 561;

        public const uint SV_CONNECTIONLESSAUTODISC_PARMNUM = 562;

        public const uint SV_SHARINGVIOLATIONRETRIES_PARMNUM = 563;

        public const uint SV_SHARINGVIOLATIONDELAY_PARMNUM = 564;

        public const uint SV_MAXGLOBALOPENSEARCH_PARMNUM = 565;

        public const uint SV_REMOVEDUPLICATESEARCHES_PARMNUM = 566;

        public const uint SV_LOCKVIOLATIONRETRIES_PARMNUM = 567;

        public const uint SV_LOCKVIOLATIONOFFSET_PARMNUM = 568;

        public const uint SV_LOCKVIOLATIONDELAY_PARMNUM = 569;

        public const uint SV_MDLREADSWITCHOVER_PARMNUM = 570;

        public const uint SV_CACHEDOPENLIMIT_PARMNUM = 571;

        public const uint SV_CRITICALTHREADS_PARMNUM = 572;

        public const uint SV_RESTRICTNULLSESSACCESS_PARMNUM = 573;

        public const uint SV_ENABLEWFW311DIRECTIPX_PARMNUM = 574;

        public const uint SV_OTHERQUEUEAFFINITY_PARMNUM = 575;

        public const uint SV_QUEUESAMPLESECS_PARMNUM = 576;

        public const uint SV_BALANCECOUNT_PARMNUM = 577;

        public const uint SV_PREFERREDAFFINITY_PARMNUM = 578;

        public const uint SV_MAXFREERFCBS_PARMNUM = 579;

        public const uint SV_MAXFREEMFCBS_PARMNUM = 580;

        public const uint SV_MAXFREELFCBS_PARMNUM = 581;

        public const uint SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM = 582;

        public const uint SV_MINPAGEDPOOLCHUNKSIZE_PARMNUM = 583;

        public const uint SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM = 584;

        public const uint SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM = 585;

        public const uint SV_MAXTHREADSPERQUEUE_PARMNUM = 586;

        public const uint SV_CACHEDDIRECTORYLIMIT_PARMNUM = 587;

        public const uint SV_MAXCOPYLENGTH_PARMNUM = 588;

        public const uint SV_ENABLECOMPRESSION_PARMNUM = 590;

        public const uint SV_AUTOSHAREWKS_PARMNUM = 591;

        public const uint SV_AUTOSHARESERVER_PARMNUM = 592;

        public const uint SV_ENABLESECURITYSIGNATURE_PARMNUM = 593;

        public const uint SV_REQUIRESECURITYSIGNATURE_PARMNUM = 594;

        public const uint SV_MINCLIENTBUFFERSIZE_PARMNUM = 595;

        public const uint SV_CONNECTIONNOSESSIONSTIMEOUT_PARMNUM = 596;

        public const uint SV_IDLETHREADTIMEOUT_PARMNUM = 597;

        public const uint SV_ENABLEW9XSECURITYSIGNATURE_PARMNUM = 598;

        public const uint SV_ENFORCEKERBEROSREAUTHENTICATION_PARMNUM = 599;

        public const uint SV_DISABLEDOS_PARMNUM = 600;

        public const uint SV_LOWDISKSPACEMINIMUM_PARMNUM = 601;

        public const uint SV_DISABLESTRICTNAMECHECKING_PARMNUM = 602;

        public const uint SV_ENABLEAUTHENTICATEUSERSHARING_PARMNUM = 603;

        public const uint SVI1_NUM_ELEMENTS = 5;

        public const uint SVI2_NUM_ELEMENTS = 40;

        public const uint SVI3_NUM_ELEMENTS = 44;

        public const uint SW_AUTOPROF_LOAD_MASK = 0x1;

        public const uint SW_AUTOPROF_SAVE_MASK = 0x2;

        public const uint SV_MAX_SRV_HEUR_LEN = 32;

        public const uint SV_USERS_PER_LICENSE = 5;

        public const uint SVTI2_REMAP_PIPE_NAMES = 0x02;

        public const uint SVTI2_SCOPED_NAME = 0x04;

        public const uint SVTI2_CLUSTER_NAME = 0x08;

        public const uint SVTI2_CLUSTER_DNN_NAME = 0x10;

        public const uint SVTI2_UNICODE_TRANSPORT_ADDRESS = 0x20;

        public const uint SVTI2_RESERVED1 = 0x1000;

        public const uint SVTI2_RESERVED2 = 0x2000;

        public const uint SVTI2_RESERVED3 = 0x4000;

        public const uint SRV_SUPPORT_HASH_GENERATION = 0x0001;

        public const uint SRV_HASH_GENERATION_ACTIVE = 0x0002;

        public const uint SERVICE_INSTALL_STATE = 0x03;

        public const uint SERVICE_UNINSTALLED = 0x00;

        public const uint SERVICE_INSTALL_PENDING = 0x01;

        public const uint SERVICE_UNINSTALL_PENDING = 0x02;

        public const uint SERVICE_INSTALLED = 0x03;

        public const uint SERVICE_PAUSE_STATE = 0x0C;

        public const uint LM20_SERVICE_ACTIVE = 0x00;

        public const uint LM20_SERVICE_CONTINUE_PENDING = 0x04;

        public const uint LM20_SERVICE_PAUSE_PENDING = 0x08;

        public const uint LM20_SERVICE_PAUSED = 0x0C;

        public const uint SERVICE_NOT_UNINSTALLABLE = 0x00;

        public const uint SERVICE_UNINSTALLABLE = 0x10;

        public const uint SERVICE_NOT_PAUSABLE = 0x00;

        public const uint SERVICE_PAUSABLE = 0x20;

        public const uint SERVICE_REDIR_PAUSED = 0x700;

        public const uint SERVICE_REDIR_DISK_PAUSED = 0x100;

        public const uint SERVICE_REDIR_PRINT_PAUSED = 0x200;

        public const uint SERVICE_REDIR_COMM_PAUSED = 0x400;

        public const uint SERVICE_CTRL_INTERROGATE = 0;

        public const uint SERVICE_CTRL_PAUSE = 1;

        public const uint SERVICE_CTRL_CONTINUE = 2;

        public const uint SERVICE_CTRL_UNINSTALL = 3;

        public const uint SERVICE_CTRL_REDIR_DISK = 0x1;

        public const uint SERVICE_CTRL_REDIR_PRINT = 0x2;

        public const uint SERVICE_CTRL_REDIR_COMM = 0x4;

        public const uint SERVICE_IP_NO_HINT = 0x0;

        public const uint SERVICE_CCP_NO_HINT = 0x0;

        public const uint SERVICE_IP_QUERY_HINT = 0x10000;

        public const uint SERVICE_CCP_QUERY_HINT = 0x10000;

        public const uint SERVICE_IP_CHKPT_NUM = 0x0FF;

        public const uint SERVICE_CCP_CHKPT_NUM = 0x0FF;

        public const uint SERVICE_IP_WAIT_TIME = 0x0FF00;

        public const uint SERVICE_CCP_WAIT_TIME = 0x0FF00;

        public const uint SERVICE_IP_WAITTIME_SHIFT = 8;

        public const uint SERVICE_NTIP_WAITTIME_SHIFT = 12;

        public const uint UPPER_HINT_MASK = 0x0000FF00;

        public const uint LOWER_HINT_MASK = 0x000000FF;

        public const uint UPPER_GET_HINT_MASK = 0x0FF00000;

        public const uint LOWER_GET_HINT_MASK = 0x0000FF00;

        public const uint SERVICE_NT_MAXTIME = 0x0000FFFF;

        public const uint SERVICE_RESRV_MASK = 0x0001FFFF;

        public const uint SERVICE_MAXTIME = 0x000000FF;

        public const uint SERVICE_BASE = 3050;

        public const uint SERVICE_UIC_NORMAL = 0;

        public const uint SERVICE_UIC_BADPARMVAL = SERVICE_BASE + 1;

        public const uint SERVICE_UIC_MISSPARM = SERVICE_BASE + 2;

        public const uint SERVICE_UIC_UNKPARM = SERVICE_BASE + 3;

        public const uint SERVICE_UIC_RESOURCE = SERVICE_BASE + 4;

        public const uint SERVICE_UIC_CONFIG = SERVICE_BASE + 5;

        public const uint SERVICE_UIC_SYSTEM = SERVICE_BASE + 6;

        public const uint SERVICE_UIC_INTERNAL = SERVICE_BASE + 7;

        public const uint SERVICE_UIC_AMBIGPARM = SERVICE_BASE + 8;

        public const uint SERVICE_UIC_DUPPARM = SERVICE_BASE + 9;

        public const uint SERVICE_UIC_KILL = SERVICE_BASE + 10;

        public const uint SERVICE_UIC_EXEC = SERVICE_BASE + 11;

        public const uint SERVICE_UIC_SUBSERV = SERVICE_BASE + 12;

        public const uint SERVICE_UIC_CONFLPARM = SERVICE_BASE + 13;

        public const uint SERVICE_UIC_FILE = SERVICE_BASE + 14;

        public const uint SERVICE_UIC_M_NULL = 0;

        public const uint SERVICE_UIC_M_MEMORY = SERVICE_BASE + 20;

        public const uint SERVICE_UIC_M_DISK = SERVICE_BASE + 21;

        public const uint SERVICE_UIC_M_THREADS = SERVICE_BASE + 22;

        public const uint SERVICE_UIC_M_PROCESSES = SERVICE_BASE + 23;

        public const uint SERVICE_UIC_M_SECURITY = SERVICE_BASE + 24;

        public const uint SERVICE_UIC_M_LANROOT = SERVICE_BASE + 25;

        public const uint SERVICE_UIC_M_REDIR = SERVICE_BASE + 26;

        public const uint SERVICE_UIC_M_SERVER = SERVICE_BASE + 27;

        public const uint SERVICE_UIC_M_SEC_FILE_ERR = SERVICE_BASE + 28;

        public const uint SERVICE_UIC_M_FILES = SERVICE_BASE + 29;

        public const uint SERVICE_UIC_M_LOGS = SERVICE_BASE + 30;

        public const uint SERVICE_UIC_M_LANGROUP = SERVICE_BASE + 31;

        public const uint SERVICE_UIC_M_MSGNAME = SERVICE_BASE + 32;

        public const uint SERVICE_UIC_M_ANNOUNCE = SERVICE_BASE + 33;

        public const uint SERVICE_UIC_M_UAS = SERVICE_BASE + 34;

        public const uint SERVICE_UIC_M_SERVER_SEC_ERR = SERVICE_BASE + 35;

        public const uint SERVICE_UIC_M_WKSTA = SERVICE_BASE + 37;

        public const uint SERVICE_UIC_M_ERRLOG = SERVICE_BASE + 38;

        public const uint SERVICE_UIC_M_FILE_UW = SERVICE_BASE + 39;

        public const uint SERVICE_UIC_M_ADDPAK = SERVICE_BASE + 40;

        public const uint SERVICE_UIC_M_LAZY = SERVICE_BASE + 41;

        public const uint SERVICE_UIC_M_UAS_MACHINE_ACCT = SERVICE_BASE + 42;

        public const uint SERVICE_UIC_M_UAS_SERVERS_NMEMB = SERVICE_BASE + 43;

        public const uint SERVICE_UIC_M_UAS_SERVERS_NOGRP = SERVICE_BASE + 44;

        public const uint SERVICE_UIC_M_UAS_INVALID_ROLE = SERVICE_BASE + 45;

        public const uint SERVICE_UIC_M_NETLOGON_NO_DC = SERVICE_BASE + 46;

        public const uint SERVICE_UIC_M_NETLOGON_DC_CFLCT = SERVICE_BASE + 47;

        public const uint SERVICE_UIC_M_NETLOGON_AUTH = SERVICE_BASE + 48;

        public const uint SERVICE_UIC_M_UAS_PROLOG = SERVICE_BASE + 49;

        public const uint SERVICE2_BASE = 5600;

        public const uint SERVICE_UIC_M_NETLOGON_MPATH = SERVICE2_BASE + 0;

        public const uint SERVICE_UIC_M_LSA_MACHINE_ACCT = SERVICE2_BASE + 1;

        public const uint SERVICE_UIC_M_DATABASE_ERROR = SERVICE2_BASE + 2;

        public const uint USE_FLAG_GLOBAL_MAPPING = 0x10000;

        public const uint USE_LOCAL_PARMNUM = 1;

        public const uint USE_REMOTE_PARMNUM = 2;

        public const uint USE_PASSWORD_PARMNUM = 3;

        public const uint USE_ASGTYPE_PARMNUM = 4;

        public const uint USE_USERNAME_PARMNUM = 5;

        public const uint USE_DOMAINNAME_PARMNUM = 6;

        public const uint USE_FLAGS_PARMNUM = 7;

        public const uint USE_AUTHIDENTITY_PARMNUM = 8;

        public const uint USE_SD_PARMNUM = 9;

        public const uint USE_OPTIONS_PARMNUM = 10;

        public const uint USE_OK = 0;

        public const uint USE_PAUSED = 1;

        public const uint USE_SESSLOST = 2;

        public const uint USE_DISCONN = 2;

        public const uint USE_NETERR = 3;

        public const uint USE_CONN = 4;

        public const uint USE_RECONN = 5;

        public const uint USE_CHARDEV = 2;

        public const uint CREATE_NO_CONNECT = 0x1;

        public const uint CREATE_BYPASS_CSC = 0x2;

        public const uint CREATE_CRED_RESET = 0x4;

        public const uint USE_DEFAULT_CREDENTIALS = 0x4;

        public const uint CREATE_REQUIRE_CONNECTION_INTEGRITY = 0x8;

        public const uint CREATE_REQUIRE_CONNECTION_PRIVACY = 0x10;

        public const uint CREATE_PERSIST_MAPPING = 0x20;

        public const uint CREATE_WRITE_THROUGH_SEMANTICS = 0x40;

        public const uint CREATE_COMPRESS_NETWORK_TRAFFIC = 0x80;

        public const uint WKSTA_PLATFORM_ID_PARMNUM = 100;

        public const uint WKSTA_COMPUTERNAME_PARMNUM = 1;

        public const uint WKSTA_LANGROUP_PARMNUM = 2;

        public const uint WKSTA_VER_MAJOR_PARMNUM = 4;

        public const uint WKSTA_VER_MINOR_PARMNUM = 5;

        public const uint WKSTA_LOGGED_ON_USERS_PARMNUM = 6;

        public const uint WKSTA_LANROOT_PARMNUM = 7;

        public const uint WKSTA_LOGON_DOMAIN_PARMNUM = 8;

        public const uint WKSTA_LOGON_SERVER_PARMNUM = 9;

        public const uint WKSTA_CHARWAIT_PARMNUM = 10;

        public const uint WKSTA_CHARTIME_PARMNUM = 11;

        public const uint WKSTA_CHARCOUNT_PARMNUM = 12;

        public const uint WKSTA_KEEPCONN_PARMNUM = 13;

        public const uint WKSTA_KEEPSEARCH_PARMNUM = 14;

        public const uint WKSTA_MAXCMDS_PARMNUM = 15;

        public const uint WKSTA_NUMWORKBUF_PARMNUM = 16;

        public const uint WKSTA_MAXWRKCACHE_PARMNUM = 17;

        public const uint WKSTA_SESSTIMEOUT_PARMNUM = 18;

        public const uint WKSTA_SIZERROR_PARMNUM = 19;

        public const uint WKSTA_NUMALERTS_PARMNUM = 20;

        public const uint WKSTA_NUMSERVICES_PARMNUM = 21;

        public const uint WKSTA_NUMCHARBUF_PARMNUM = 22;

        public const uint WKSTA_SIZCHARBUF_PARMNUM = 23;

        public const uint WKSTA_ERRLOGSZ_PARMNUM = 27;

        public const uint WKSTA_PRINTBUFTIME_PARMNUM = 28;

        public const uint WKSTA_SIZWORKBUF_PARMNUM = 29;

        public const uint WKSTA_MAILSLOTS_PARMNUM = 30;

        public const uint WKSTA_NUMDGRAMBUF_PARMNUM = 31;

        public const uint WKSTA_WRKHEURISTICS_PARMNUM = 32;

        public const uint WKSTA_MAXTHREADS_PARMNUM = 33;

        public const uint WKSTA_LOCKQUOTA_PARMNUM = 41;

        public const uint WKSTA_LOCKINCREMENT_PARMNUM = 42;

        public const uint WKSTA_LOCKMAXIMUM_PARMNUM = 43;

        public const uint WKSTA_PIPEINCREMENT_PARMNUM = 44;

        public const uint WKSTA_PIPEMAXIMUM_PARMNUM = 45;

        public const uint WKSTA_DORMANTFILELIMIT_PARMNUM = 46;

        public const uint WKSTA_CACHEFILETIMEOUT_PARMNUM = 47;

        public const uint WKSTA_USEOPPORTUNISTICLOCKING_PARMNUM = 48;

        public const uint WKSTA_USEUNLOCKBEHIND_PARMNUM = 49;

        public const uint WKSTA_USECLOSEBEHIND_PARMNUM = 50;

        public const uint WKSTA_BUFFERNAMEDPIPES_PARMNUM = 51;

        public const uint WKSTA_USELOCKANDREADANDUNLOCK_PARMNUM = 52;

        public const uint WKSTA_UTILIZENTCACHING_PARMNUM = 53;

        public const uint WKSTA_USERAWREAD_PARMNUM = 54;

        public const uint WKSTA_USERAWWRITE_PARMNUM = 55;

        public const uint WKSTA_USEWRITERAWWITHDATA_PARMNUM = 56;

        public const uint WKSTA_USEENCRYPTION_PARMNUM = 57;

        public const uint WKSTA_BUFFILESWITHDENYWRITE_PARMNUM = 58;

        public const uint WKSTA_BUFFERREADONLYFILES_PARMNUM = 59;

        public const uint WKSTA_FORCECORECREATEMODE_PARMNUM = 60;

        public const uint WKSTA_USE512BYTESMAXTRANSFER_PARMNUM = 61;

        public const uint WKSTA_READAHEADTHRUPUT_PARMNUM = 62;

        public const uint WKSTA_OTH_DOMAINS_PARMNUM = 101;

        public const uint TRANSPORT_QUALITYOFSERVICE_PARMNUM = 201;

        public const uint TRANSPORT_NAME_PARMNUM = 202;

    }
}

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


namespace Windows.Win32.Devices.Tapi
{
    public static partial class Apis
    {
        public const uint TAPI_CURRENT_VERSION = 0x00020002;

        public const int LINE_ADDRESSSTATE = 0;

        public const int LINE_CALLINFO = 1;

        public const int LINE_CALLSTATE = 2;

        public const int LINE_CLOSE = 3;

        public const int LINE_DEVSPECIFIC = 4;

        public const int LINE_DEVSPECIFICFEATURE = 5;

        public const int LINE_GATHERDIGITS = 6;

        public const int LINE_GENERATE = 7;

        public const int LINE_LINEDEVSTATE = 8;

        public const int LINE_MONITORDIGITS = 9;

        public const int LINE_MONITORMEDIA = 10;

        public const int LINE_MONITORTONE = 11;

        public const int LINE_REPLY = 12;

        public const int LINE_REQUEST = 13;

        public const int PHONE_BUTTON = 14;

        public const int PHONE_CLOSE = 15;

        public const int PHONE_DEVSPECIFIC = 16;

        public const int PHONE_REPLY = 17;

        public const int PHONE_STATE = 18;

        public const int LINE_CREATE = 19;

        public const int PHONE_CREATE = 20;

        public const int LINE_AGENTSPECIFIC = 21;

        public const int LINE_AGENTSTATUS = 22;

        public const int LINE_APPNEWCALL = 23;

        public const int LINE_PROXYREQUEST = 24;

        public const int LINE_REMOVE = 25;

        public const int PHONE_REMOVE = 26;

        public const int LINE_AGENTSESSIONSTATUS = 27;

        public const int LINE_QUEUESTATUS = 28;

        public const int LINE_AGENTSTATUSEX = 29;

        public const int LINE_GROUPSTATUS = 30;

        public const int LINE_PROXYSTATUS = 31;

        public const int LINE_APPNEWCALLHUB = 32;

        public const int LINE_CALLHUBCLOSE = 33;

        public const int LINE_DEVSPECIFICEX = 34;

        public const uint INITIALIZE_NEGOTIATION = 0xFFFFFFFF;

        public const uint LINEADDRCAPFLAGS_FWDNUMRINGS = 0x00000001;

        public const uint LINEADDRCAPFLAGS_PICKUPGROUPID = 0x00000002;

        public const uint LINEADDRCAPFLAGS_SECURE = 0x00000004;

        public const uint LINEADDRCAPFLAGS_BLOCKIDDEFAULT = 0x00000008;

        public const uint LINEADDRCAPFLAGS_BLOCKIDOVERRIDE = 0x00000010;

        public const uint LINEADDRCAPFLAGS_DIALED = 0x00000020;

        public const uint LINEADDRCAPFLAGS_ORIGOFFHOOK = 0x00000040;

        public const uint LINEADDRCAPFLAGS_DESTOFFHOOK = 0x00000080;

        public const uint LINEADDRCAPFLAGS_FWDCONSULT = 0x00000100;

        public const uint LINEADDRCAPFLAGS_SETUPCONFNULL = 0x00000200;

        public const uint LINEADDRCAPFLAGS_AUTORECONNECT = 0x00000400;

        public const uint LINEADDRCAPFLAGS_COMPLETIONID = 0x00000800;

        public const uint LINEADDRCAPFLAGS_TRANSFERHELD = 0x00001000;

        public const uint LINEADDRCAPFLAGS_TRANSFERMAKE = 0x00002000;

        public const uint LINEADDRCAPFLAGS_CONFERENCEHELD = 0x00004000;

        public const uint LINEADDRCAPFLAGS_CONFERENCEMAKE = 0x00008000;

        public const uint LINEADDRCAPFLAGS_PARTIALDIAL = 0x00010000;

        public const uint LINEADDRCAPFLAGS_FWDSTATUSVALID = 0x00020000;

        public const uint LINEADDRCAPFLAGS_FWDINTEXTADDR = 0x00040000;

        public const uint LINEADDRCAPFLAGS_FWDBUSYNAADDR = 0x00080000;

        public const uint LINEADDRCAPFLAGS_ACCEPTTOALERT = 0x00100000;

        public const uint LINEADDRCAPFLAGS_CONFDROP = 0x00200000;

        public const uint LINEADDRCAPFLAGS_PICKUPCALLWAIT = 0x00400000;

        public const uint LINEADDRCAPFLAGS_PREDICTIVEDIALER = 0x00800000;

        public const uint LINEADDRCAPFLAGS_QUEUE = 0x01000000;

        public const uint LINEADDRCAPFLAGS_ROUTEPOINT = 0x02000000;

        public const uint LINEADDRCAPFLAGS_HOLDMAKESNEW = 0x04000000;

        public const uint LINEADDRCAPFLAGS_NOINTERNALCALLS = 0x08000000;

        public const uint LINEADDRCAPFLAGS_NOEXTERNALCALLS = 0x10000000;

        public const uint LINEADDRCAPFLAGS_SETCALLINGID = 0x20000000;

        public const uint LINEADDRCAPFLAGS_ACDGROUP = 0x40000000;

        public const uint LINEADDRCAPFLAGS_NOPSTNADDRESSTRANSLATION = 0x80000000;

        public const uint LINEADDRESSMODE_ADDRESSID = 0x00000001;

        public const uint LINEADDRESSMODE_DIALABLEADDR = 0x00000002;

        public const uint LINEADDRESSSHARING_PRIVATE = 0x00000001;

        public const uint LINEADDRESSSHARING_BRIDGEDEXCL = 0x00000002;

        public const uint LINEADDRESSSHARING_BRIDGEDNEW = 0x00000004;

        public const uint LINEADDRESSSHARING_BRIDGEDSHARED = 0x00000008;

        public const uint LINEADDRESSSHARING_MONITORED = 0x00000010;

        public const uint LINEADDRESSSTATE_OTHER = 0x00000001;

        public const uint LINEADDRESSSTATE_DEVSPECIFIC = 0x00000002;

        public const uint LINEADDRESSSTATE_INUSEZERO = 0x00000004;

        public const uint LINEADDRESSSTATE_INUSEONE = 0x00000008;

        public const uint LINEADDRESSSTATE_INUSEMANY = 0x00000010;

        public const uint LINEADDRESSSTATE_NUMCALLS = 0x00000020;

        public const uint LINEADDRESSSTATE_FORWARD = 0x00000040;

        public const uint LINEADDRESSSTATE_TERMINALS = 0x00000080;

        public const uint LINEADDRESSSTATE_CAPSCHANGE = 0x00000100;

        public const uint LINEADDRESSTYPE_PHONENUMBER = 0x00000001;

        public const uint LINEADDRESSTYPE_SDP = 0x00000002;

        public const uint LINEADDRESSTYPE_EMAILNAME = 0x00000004;

        public const uint LINEADDRESSTYPE_DOMAINNAME = 0x00000008;

        public const uint LINEADDRESSTYPE_IPADDRESS = 0x00000010;

        public const uint LINEADDRFEATURE_FORWARD = 0x00000001;

        public const uint LINEADDRFEATURE_MAKECALL = 0x00000002;

        public const uint LINEADDRFEATURE_PICKUP = 0x00000004;

        public const uint LINEADDRFEATURE_SETMEDIACONTROL = 0x00000008;

        public const uint LINEADDRFEATURE_SETTERMINAL = 0x00000010;

        public const uint LINEADDRFEATURE_SETUPCONF = 0x00000020;

        public const uint LINEADDRFEATURE_UNCOMPLETECALL = 0x00000040;

        public const uint LINEADDRFEATURE_UNPARK = 0x00000080;

        public const uint LINEADDRFEATURE_PICKUPHELD = 0x00000100;

        public const uint LINEADDRFEATURE_PICKUPGROUP = 0x00000200;

        public const uint LINEADDRFEATURE_PICKUPDIRECT = 0x00000400;

        public const uint LINEADDRFEATURE_PICKUPWAITING = 0x00000800;

        public const uint LINEADDRFEATURE_FORWARDFWD = 0x00001000;

        public const uint LINEADDRFEATURE_FORWARDDND = 0x00002000;

        public const uint LINEAGENTFEATURE_SETAGENTGROUP = 0x00000001;

        public const uint LINEAGENTFEATURE_SETAGENTSTATE = 0x00000002;

        public const uint LINEAGENTFEATURE_SETAGENTACTIVITY = 0x00000004;

        public const uint LINEAGENTFEATURE_AGENTSPECIFIC = 0x00000008;

        public const uint LINEAGENTFEATURE_GETAGENTACTIVITYLIST = 0x00000010;

        public const uint LINEAGENTFEATURE_GETAGENTGROUP = 0x00000020;

        public const uint LINEAGENTSTATE_LOGGEDOFF = 0x00000001;

        public const uint LINEAGENTSTATE_NOTREADY = 0x00000002;

        public const uint LINEAGENTSTATE_READY = 0x00000004;

        public const uint LINEAGENTSTATE_BUSYACD = 0x00000008;

        public const uint LINEAGENTSTATE_BUSYINCOMING = 0x00000010;

        public const uint LINEAGENTSTATE_BUSYOUTBOUND = 0x00000020;

        public const uint LINEAGENTSTATE_BUSYOTHER = 0x00000040;

        public const uint LINEAGENTSTATE_WORKINGAFTERCALL = 0x00000080;

        public const uint LINEAGENTSTATE_UNKNOWN = 0x00000100;

        public const uint LINEAGENTSTATE_UNAVAIL = 0x00000200;

        public const uint LINEAGENTSTATUS_GROUP = 0x00000001;

        public const uint LINEAGENTSTATUS_STATE = 0x00000002;

        public const uint LINEAGENTSTATUS_NEXTSTATE = 0x00000004;

        public const uint LINEAGENTSTATUS_ACTIVITY = 0x00000008;

        public const uint LINEAGENTSTATUS_ACTIVITYLIST = 0x00000010;

        public const uint LINEAGENTSTATUS_GROUPLIST = 0x00000020;

        public const uint LINEAGENTSTATUS_CAPSCHANGE = 0x00000040;

        public const uint LINEAGENTSTATUS_VALIDSTATES = 0x00000080;

        public const uint LINEAGENTSTATUS_VALIDNEXTSTATES = 0x00000100;

        public const uint LINEAGENTSTATEEX_NOTREADY = 0x00000001;

        public const uint LINEAGENTSTATEEX_READY = 0x00000002;

        public const uint LINEAGENTSTATEEX_BUSYACD = 0x00000004;

        public const uint LINEAGENTSTATEEX_BUSYINCOMING = 0x00000008;

        public const uint LINEAGENTSTATEEX_BUSYOUTGOING = 0x00000010;

        public const uint LINEAGENTSTATEEX_UNKNOWN = 0x00000020;

        public const uint LINEAGENTSTATEEX_RELEASED = 0x00000040;

        public const uint LINEAGENTSTATUSEX_NEWAGENT = 0x00000001;

        public const uint LINEAGENTSTATUSEX_STATE = 0x00000002;

        public const uint LINEAGENTSTATUSEX_UPDATEINFO = 0x00000004;

        public const uint LINEAGENTSESSIONSTATE_NOTREADY = 0x00000001;

        public const uint LINEAGENTSESSIONSTATE_READY = 0x00000002;

        public const uint LINEAGENTSESSIONSTATE_BUSYONCALL = 0x00000004;

        public const uint LINEAGENTSESSIONSTATE_BUSYWRAPUP = 0x00000008;

        public const uint LINEAGENTSESSIONSTATE_ENDED = 0x00000010;

        public const uint LINEAGENTSESSIONSTATE_RELEASED = 0x00000020;

        public const uint LINEAGENTSESSIONSTATUS_NEWSESSION = 0x00000001;

        public const uint LINEAGENTSESSIONSTATUS_STATE = 0x00000002;

        public const uint LINEAGENTSESSIONSTATUS_UPDATEINFO = 0x00000004;

        public const uint LINEQUEUESTATUS_UPDATEINFO = 0x00000001;

        public const uint LINEQUEUESTATUS_NEWQUEUE = 0x00000002;

        public const uint LINEQUEUESTATUS_QUEUEREMOVED = 0x00000004;

        public const uint LINEGROUPSTATUS_NEWGROUP = 0x00000001;

        public const uint LINEGROUPSTATUS_GROUPREMOVED = 0x00000002;

        public const uint LINEPROXYSTATUS_OPEN = 0x00000001;

        public const uint LINEPROXYSTATUS_CLOSE = 0x00000002;

        public const uint LINEPROXYSTATUS_ALLOPENFORACD = 0x00000004;

        public const uint LINEANSWERMODE_NONE = 0x00000001;

        public const uint LINEANSWERMODE_DROP = 0x00000002;

        public const uint LINEANSWERMODE_HOLD = 0x00000004;

        public const uint LINEBEARERMODE_VOICE = 0x00000001;

        public const uint LINEBEARERMODE_SPEECH = 0x00000002;

        public const uint LINEBEARERMODE_MULTIUSE = 0x00000004;

        public const uint LINEBEARERMODE_DATA = 0x00000008;

        public const uint LINEBEARERMODE_ALTSPEECHDATA = 0x00000010;

        public const uint LINEBEARERMODE_NONCALLSIGNALING = 0x00000020;

        public const uint LINEBEARERMODE_PASSTHROUGH = 0x00000040;

        public const uint LINEBEARERMODE_RESTRICTEDDATA = 0x00000080;

        public const uint LINEBUSYMODE_STATION = 0x00000001;

        public const uint LINEBUSYMODE_TRUNK = 0x00000002;

        public const uint LINEBUSYMODE_UNKNOWN = 0x00000004;

        public const uint LINEBUSYMODE_UNAVAIL = 0x00000008;

        public const uint LINECALLCOMPLCOND_BUSY = 0x00000001;

        public const uint LINECALLCOMPLCOND_NOANSWER = 0x00000002;

        public const uint LINECALLCOMPLMODE_CAMPON = 0x00000001;

        public const uint LINECALLCOMPLMODE_CALLBACK = 0x00000002;

        public const uint LINECALLCOMPLMODE_INTRUDE = 0x00000004;

        public const uint LINECALLCOMPLMODE_MESSAGE = 0x00000008;

        public const uint LINECALLFEATURE_ACCEPT = 0x00000001;

        public const uint LINECALLFEATURE_ADDTOCONF = 0x00000002;

        public const uint LINECALLFEATURE_ANSWER = 0x00000004;

        public const uint LINECALLFEATURE_BLINDTRANSFER = 0x00000008;

        public const uint LINECALLFEATURE_COMPLETECALL = 0x00000010;

        public const uint LINECALLFEATURE_COMPLETETRANSF = 0x00000020;

        public const uint LINECALLFEATURE_DIAL = 0x00000040;

        public const uint LINECALLFEATURE_DROP = 0x00000080;

        public const uint LINECALLFEATURE_GATHERDIGITS = 0x00000100;

        public const uint LINECALLFEATURE_GENERATEDIGITS = 0x00000200;

        public const uint LINECALLFEATURE_GENERATETONE = 0x00000400;

        public const uint LINECALLFEATURE_HOLD = 0x00000800;

        public const uint LINECALLFEATURE_MONITORDIGITS = 0x00001000;

        public const uint LINECALLFEATURE_MONITORMEDIA = 0x00002000;

        public const uint LINECALLFEATURE_MONITORTONES = 0x00004000;

        public const uint LINECALLFEATURE_PARK = 0x00008000;

        public const uint LINECALLFEATURE_PREPAREADDCONF = 0x00010000;

        public const uint LINECALLFEATURE_REDIRECT = 0x00020000;

        public const uint LINECALLFEATURE_REMOVEFROMCONF = 0x00040000;

        public const uint LINECALLFEATURE_SECURECALL = 0x00080000;

        public const uint LINECALLFEATURE_SENDUSERUSER = 0x00100000;

        public const uint LINECALLFEATURE_SETCALLPARAMS = 0x00200000;

        public const uint LINECALLFEATURE_SETMEDIACONTROL = 0x00400000;

        public const uint LINECALLFEATURE_SETTERMINAL = 0x00800000;

        public const uint LINECALLFEATURE_SETUPCONF = 0x01000000;

        public const uint LINECALLFEATURE_SETUPTRANSFER = 0x02000000;

        public const uint LINECALLFEATURE_SWAPHOLD = 0x04000000;

        public const uint LINECALLFEATURE_UNHOLD = 0x08000000;

        public const uint LINECALLFEATURE_RELEASEUSERUSERINFO = 0x10000000;

        public const uint LINECALLFEATURE_SETTREATMENT = 0x20000000;

        public const uint LINECALLFEATURE_SETQOS = 0x40000000;

        public const uint LINECALLFEATURE_SETCALLDATA = 0x80000000;

        public const uint LINECALLFEATURE2_NOHOLDCONFERENCE = 0x00000001;

        public const uint LINECALLFEATURE2_ONESTEPTRANSFER = 0x00000002;

        public const uint LINECALLFEATURE2_COMPLCAMPON = 0x00000004;

        public const uint LINECALLFEATURE2_COMPLCALLBACK = 0x00000008;

        public const uint LINECALLFEATURE2_COMPLINTRUDE = 0x00000010;

        public const uint LINECALLFEATURE2_COMPLMESSAGE = 0x00000020;

        public const uint LINECALLFEATURE2_TRANSFERNORM = 0x00000040;

        public const uint LINECALLFEATURE2_TRANSFERCONF = 0x00000080;

        public const uint LINECALLFEATURE2_PARKDIRECT = 0x00000100;

        public const uint LINECALLFEATURE2_PARKNONDIRECT = 0x00000200;

        public const uint LINECALLHUBTRACKING_NONE = 0x00000000;

        public const uint LINECALLHUBTRACKING_PROVIDERLEVEL = 0x00000001;

        public const uint LINECALLHUBTRACKING_ALLCALLS = 0x00000002;

        public const uint LINECALLINFOSTATE_OTHER = 0x00000001;

        public const uint LINECALLINFOSTATE_DEVSPECIFIC = 0x00000002;

        public const uint LINECALLINFOSTATE_BEARERMODE = 0x00000004;

        public const uint LINECALLINFOSTATE_RATE = 0x00000008;

        public const uint LINECALLINFOSTATE_MEDIAMODE = 0x00000010;

        public const uint LINECALLINFOSTATE_APPSPECIFIC = 0x00000020;

        public const uint LINECALLINFOSTATE_CALLID = 0x00000040;

        public const uint LINECALLINFOSTATE_RELATEDCALLID = 0x00000080;

        public const uint LINECALLINFOSTATE_ORIGIN = 0x00000100;

        public const uint LINECALLINFOSTATE_REASON = 0x00000200;

        public const uint LINECALLINFOSTATE_COMPLETIONID = 0x00000400;

        public const uint LINECALLINFOSTATE_NUMOWNERINCR = 0x00000800;

        public const uint LINECALLINFOSTATE_NUMOWNERDECR = 0x00001000;

        public const uint LINECALLINFOSTATE_NUMMONITORS = 0x00002000;

        public const uint LINECALLINFOSTATE_TRUNK = 0x00004000;

        public const uint LINECALLINFOSTATE_CALLERID = 0x00008000;

        public const uint LINECALLINFOSTATE_CALLEDID = 0x00010000;

        public const uint LINECALLINFOSTATE_CONNECTEDID = 0x00020000;

        public const uint LINECALLINFOSTATE_REDIRECTIONID = 0x00040000;

        public const uint LINECALLINFOSTATE_REDIRECTINGID = 0x00080000;

        public const uint LINECALLINFOSTATE_DISPLAY = 0x00100000;

        public const uint LINECALLINFOSTATE_USERUSERINFO = 0x00200000;

        public const uint LINECALLINFOSTATE_HIGHLEVELCOMP = 0x00400000;

        public const uint LINECALLINFOSTATE_LOWLEVELCOMP = 0x00800000;

        public const uint LINECALLINFOSTATE_CHARGINGINFO = 0x01000000;

        public const uint LINECALLINFOSTATE_TERMINAL = 0x02000000;

        public const uint LINECALLINFOSTATE_DIALPARAMS = 0x04000000;

        public const uint LINECALLINFOSTATE_MONITORMODES = 0x08000000;

        public const uint LINECALLINFOSTATE_TREATMENT = 0x10000000;

        public const uint LINECALLINFOSTATE_QOS = 0x20000000;

        public const uint LINECALLINFOSTATE_CALLDATA = 0x40000000;

        public const uint LINECALLORIGIN_OUTBOUND = 0x00000001;

        public const uint LINECALLORIGIN_INTERNAL = 0x00000002;

        public const uint LINECALLORIGIN_EXTERNAL = 0x00000004;

        public const uint LINECALLORIGIN_UNKNOWN = 0x00000010;

        public const uint LINECALLORIGIN_UNAVAIL = 0x00000020;

        public const uint LINECALLORIGIN_CONFERENCE = 0x00000040;

        public const uint LINECALLORIGIN_INBOUND = 0x00000080;

        public const uint LINECALLPARAMFLAGS_SECURE = 0x00000001;

        public const uint LINECALLPARAMFLAGS_IDLE = 0x00000002;

        public const uint LINECALLPARAMFLAGS_BLOCKID = 0x00000004;

        public const uint LINECALLPARAMFLAGS_ORIGOFFHOOK = 0x00000008;

        public const uint LINECALLPARAMFLAGS_DESTOFFHOOK = 0x00000010;

        public const uint LINECALLPARAMFLAGS_NOHOLDCONFERENCE = 0x00000020;

        public const uint LINECALLPARAMFLAGS_PREDICTIVEDIAL = 0x00000040;

        public const uint LINECALLPARAMFLAGS_ONESTEPTRANSFER = 0x00000080;

        public const uint LINECALLPARTYID_BLOCKED = 0x00000001;

        public const uint LINECALLPARTYID_OUTOFAREA = 0x00000002;

        public const uint LINECALLPARTYID_NAME = 0x00000004;

        public const uint LINECALLPARTYID_ADDRESS = 0x00000008;

        public const uint LINECALLPARTYID_PARTIAL = 0x00000010;

        public const uint LINECALLPARTYID_UNKNOWN = 0x00000020;

        public const uint LINECALLPARTYID_UNAVAIL = 0x00000040;

        public const uint LINECALLPRIVILEGE_NONE = 0x00000001;

        public const uint LINECALLPRIVILEGE_MONITOR = 0x00000002;

        public const uint LINECALLPRIVILEGE_OWNER = 0x00000004;

        public const uint LINECALLREASON_DIRECT = 0x00000001;

        public const uint LINECALLREASON_FWDBUSY = 0x00000002;

        public const uint LINECALLREASON_FWDNOANSWER = 0x00000004;

        public const uint LINECALLREASON_FWDUNCOND = 0x00000008;

        public const uint LINECALLREASON_PICKUP = 0x00000010;

        public const uint LINECALLREASON_UNPARK = 0x00000020;

        public const uint LINECALLREASON_REDIRECT = 0x00000040;

        public const uint LINECALLREASON_CALLCOMPLETION = 0x00000080;

        public const uint LINECALLREASON_TRANSFER = 0x00000100;

        public const uint LINECALLREASON_REMINDER = 0x00000200;

        public const uint LINECALLREASON_UNKNOWN = 0x00000400;

        public const uint LINECALLREASON_UNAVAIL = 0x00000800;

        public const uint LINECALLREASON_INTRUDE = 0x00001000;

        public const uint LINECALLREASON_PARKED = 0x00002000;

        public const uint LINECALLREASON_CAMPEDON = 0x00004000;

        public const uint LINECALLREASON_ROUTEREQUEST = 0x00008000;

        public const uint LINECALLSELECT_LINE = 0x00000001;

        public const uint LINECALLSELECT_ADDRESS = 0x00000002;

        public const uint LINECALLSELECT_CALL = 0x00000004;

        public const uint LINECALLSELECT_DEVICEID = 0x00000008;

        public const uint LINECALLSELECT_CALLID = 0x00000010;

        public const uint LINECALLSTATE_IDLE = 0x00000001;

        public const uint LINECALLSTATE_OFFERING = 0x00000002;

        public const uint LINECALLSTATE_ACCEPTED = 0x00000004;

        public const uint LINECALLSTATE_DIALTONE = 0x00000008;

        public const uint LINECALLSTATE_DIALING = 0x00000010;

        public const uint LINECALLSTATE_RINGBACK = 0x00000020;

        public const uint LINECALLSTATE_BUSY = 0x00000040;

        public const uint LINECALLSTATE_SPECIALINFO = 0x00000080;

        public const uint LINECALLSTATE_CONNECTED = 0x00000100;

        public const uint LINECALLSTATE_PROCEEDING = 0x00000200;

        public const uint LINECALLSTATE_ONHOLD = 0x00000400;

        public const uint LINECALLSTATE_CONFERENCED = 0x00000800;

        public const uint LINECALLSTATE_ONHOLDPENDCONF = 0x00001000;

        public const uint LINECALLSTATE_ONHOLDPENDTRANSFER = 0x00002000;

        public const uint LINECALLSTATE_DISCONNECTED = 0x00004000;

        public const uint LINECALLSTATE_UNKNOWN = 0x00008000;

        public const uint LINECALLTREATMENT_SILENCE = 0x00000001;

        public const uint LINECALLTREATMENT_RINGBACK = 0x00000002;

        public const uint LINECALLTREATMENT_BUSY = 0x00000003;

        public const uint LINECALLTREATMENT_MUSIC = 0x00000004;

        public const uint LINECARDOPTION_PREDEFINED = 0x00000001;

        public const uint LINECARDOPTION_HIDDEN = 0x00000002;

        public const uint LINECONNECTEDMODE_ACTIVE = 0x00000001;

        public const uint LINECONNECTEDMODE_INACTIVE = 0x00000002;

        public const uint LINECONNECTEDMODE_ACTIVEHELD = 0x00000004;

        public const uint LINECONNECTEDMODE_INACTIVEHELD = 0x00000008;

        public const uint LINECONNECTEDMODE_CONFIRMED = 0x00000010;

        public const uint LINEDEVCAPFLAGS_CROSSADDRCONF = 0x00000001;

        public const uint LINEDEVCAPFLAGS_HIGHLEVCOMP = 0x00000002;

        public const uint LINEDEVCAPFLAGS_LOWLEVCOMP = 0x00000004;

        public const uint LINEDEVCAPFLAGS_MEDIACONTROL = 0x00000008;

        public const uint LINEDEVCAPFLAGS_MULTIPLEADDR = 0x00000010;

        public const uint LINEDEVCAPFLAGS_CLOSEDROP = 0x00000020;

        public const uint LINEDEVCAPFLAGS_DIALBILLING = 0x00000040;

        public const uint LINEDEVCAPFLAGS_DIALQUIET = 0x00000080;

        public const uint LINEDEVCAPFLAGS_DIALDIALTONE = 0x00000100;

        public const uint LINEDEVCAPFLAGS_MSP = 0x00000200;

        public const uint LINEDEVCAPFLAGS_CALLHUB = 0x00000400;

        public const uint LINEDEVCAPFLAGS_CALLHUBTRACKING = 0x00000800;

        public const uint LINEDEVCAPFLAGS_PRIVATEOBJECTS = 0x00001000;

        public const uint LINEDEVCAPFLAGS_LOCAL = 0x00002000;

        public const uint LINEDEVSTATE_OTHER = 0x00000001;

        public const uint LINEDEVSTATE_RINGING = 0x00000002;

        public const uint LINEDEVSTATE_CONNECTED = 0x00000004;

        public const uint LINEDEVSTATE_DISCONNECTED = 0x00000008;

        public const uint LINEDEVSTATE_MSGWAITON = 0x00000010;

        public const uint LINEDEVSTATE_MSGWAITOFF = 0x00000020;

        public const uint LINEDEVSTATE_INSERVICE = 0x00000040;

        public const uint LINEDEVSTATE_OUTOFSERVICE = 0x00000080;

        public const uint LINEDEVSTATE_MAINTENANCE = 0x00000100;

        public const uint LINEDEVSTATE_OPEN = 0x00000200;

        public const uint LINEDEVSTATE_CLOSE = 0x00000400;

        public const uint LINEDEVSTATE_NUMCALLS = 0x00000800;

        public const uint LINEDEVSTATE_NUMCOMPLETIONS = 0x00001000;

        public const uint LINEDEVSTATE_TERMINALS = 0x00002000;

        public const uint LINEDEVSTATE_ROAMMODE = 0x00004000;

        public const uint LINEDEVSTATE_BATTERY = 0x00008000;

        public const uint LINEDEVSTATE_SIGNAL = 0x00010000;

        public const uint LINEDEVSTATE_DEVSPECIFIC = 0x00020000;

        public const uint LINEDEVSTATE_REINIT = 0x00040000;

        public const uint LINEDEVSTATE_LOCK = 0x00080000;

        public const uint LINEDEVSTATE_CAPSCHANGE = 0x00100000;

        public const uint LINEDEVSTATE_CONFIGCHANGE = 0x00200000;

        public const uint LINEDEVSTATE_TRANSLATECHANGE = 0x00400000;

        public const uint LINEDEVSTATE_COMPLCANCEL = 0x00800000;

        public const uint LINEDEVSTATE_REMOVED = 0x01000000;

        public const uint LINEDEVSTATUSFLAGS_CONNECTED = 0x00000001;

        public const uint LINEDEVSTATUSFLAGS_MSGWAIT = 0x00000002;

        public const uint LINEDEVSTATUSFLAGS_INSERVICE = 0x00000004;

        public const uint LINEDEVSTATUSFLAGS_LOCKED = 0x00000008;

        public const uint LINEDIALTONEMODE_NORMAL = 0x00000001;

        public const uint LINEDIALTONEMODE_SPECIAL = 0x00000002;

        public const uint LINEDIALTONEMODE_INTERNAL = 0x00000004;

        public const uint LINEDIALTONEMODE_EXTERNAL = 0x00000008;

        public const uint LINEDIALTONEMODE_UNKNOWN = 0x00000010;

        public const uint LINEDIALTONEMODE_UNAVAIL = 0x00000020;

        public const uint LINEDIGITMODE_PULSE = 0x00000001;

        public const uint LINEDIGITMODE_DTMF = 0x00000002;

        public const uint LINEDIGITMODE_DTMFEND = 0x00000004;

        public const uint LINEDISCONNECTMODE_NORMAL = 0x00000001;

        public const uint LINEDISCONNECTMODE_UNKNOWN = 0x00000002;

        public const uint LINEDISCONNECTMODE_REJECT = 0x00000004;

        public const uint LINEDISCONNECTMODE_PICKUP = 0x00000008;

        public const uint LINEDISCONNECTMODE_FORWARDED = 0x00000010;

        public const uint LINEDISCONNECTMODE_BUSY = 0x00000020;

        public const uint LINEDISCONNECTMODE_NOANSWER = 0x00000040;

        public const uint LINEDISCONNECTMODE_BADADDRESS = 0x00000080;

        public const uint LINEDISCONNECTMODE_UNREACHABLE = 0x00000100;

        public const uint LINEDISCONNECTMODE_CONGESTION = 0x00000200;

        public const uint LINEDISCONNECTMODE_INCOMPATIBLE = 0x00000400;

        public const uint LINEDISCONNECTMODE_UNAVAIL = 0x00000800;

        public const uint LINEDISCONNECTMODE_NODIALTONE = 0x00001000;

        public const uint LINEDISCONNECTMODE_NUMBERCHANGED = 0x00002000;

        public const uint LINEDISCONNECTMODE_OUTOFORDER = 0x00004000;

        public const uint LINEDISCONNECTMODE_TEMPFAILURE = 0x00008000;

        public const uint LINEDISCONNECTMODE_QOSUNAVAIL = 0x00010000;

        public const uint LINEDISCONNECTMODE_BLOCKED = 0x00020000;

        public const uint LINEDISCONNECTMODE_DONOTDISTURB = 0x00040000;

        public const uint LINEDISCONNECTMODE_CANCELLED = 0x00080000;

        public const uint LINEDISCONNECTMODE_DESTINATIONBARRED = 0x00100000;

        public const uint LINEDISCONNECTMODE_FDNRESTRICT = 0x00200000;

        public const uint LINEERR_ALLOCATED = 0x80000001;

        public const uint LINEERR_BADDEVICEID = 0x80000002;

        public const uint LINEERR_BEARERMODEUNAVAIL = 0x80000003;

        public const uint LINEERR_CALLUNAVAIL = 0x80000005;

        public const uint LINEERR_COMPLETIONOVERRUN = 0x80000006;

        public const uint LINEERR_CONFERENCEFULL = 0x80000007;

        public const uint LINEERR_DIALBILLING = 0x80000008;

        public const uint LINEERR_DIALDIALTONE = 0x80000009;

        public const uint LINEERR_DIALPROMPT = 0x8000000A;

        public const uint LINEERR_DIALQUIET = 0x8000000B;

        public const uint LINEERR_INCOMPATIBLEAPIVERSION = 0x8000000C;

        public const uint LINEERR_INCOMPATIBLEEXTVERSION = 0x8000000D;

        public const uint LINEERR_INIFILECORRUPT = 0x8000000E;

        public const uint LINEERR_INUSE = 0x8000000F;

        public const uint LINEERR_INVALADDRESS = 0x80000010;

        public const uint LINEERR_INVALADDRESSID = 0x80000011;

        public const uint LINEERR_INVALADDRESSMODE = 0x80000012;

        public const uint LINEERR_INVALADDRESSSTATE = 0x80000013;

        public const uint LINEERR_INVALAPPHANDLE = 0x80000014;

        public const uint LINEERR_INVALAPPNAME = 0x80000015;

        public const uint LINEERR_INVALBEARERMODE = 0x80000016;

        public const uint LINEERR_INVALCALLCOMPLMODE = 0x80000017;

        public const uint LINEERR_INVALCALLHANDLE = 0x80000018;

        public const uint LINEERR_INVALCALLPARAMS = 0x80000019;

        public const uint LINEERR_INVALCALLPRIVILEGE = 0x8000001A;

        public const uint LINEERR_INVALCALLSELECT = 0x8000001B;

        public const uint LINEERR_INVALCALLSTATE = 0x8000001C;

        public const uint LINEERR_INVALCALLSTATELIST = 0x8000001D;

        public const uint LINEERR_INVALCARD = 0x8000001E;

        public const uint LINEERR_INVALCOMPLETIONID = 0x8000001F;

        public const uint LINEERR_INVALCONFCALLHANDLE = 0x80000020;

        public const uint LINEERR_INVALCONSULTCALLHANDLE = 0x80000021;

        public const uint LINEERR_INVALCOUNTRYCODE = 0x80000022;

        public const uint LINEERR_INVALDEVICECLASS = 0x80000023;

        public const uint LINEERR_INVALDEVICEHANDLE = 0x80000024;

        public const uint LINEERR_INVALDIALPARAMS = 0x80000025;

        public const uint LINEERR_INVALDIGITLIST = 0x80000026;

        public const uint LINEERR_INVALDIGITMODE = 0x80000027;

        public const uint LINEERR_INVALDIGITS = 0x80000028;

        public const uint LINEERR_INVALEXTVERSION = 0x80000029;

        public const uint LINEERR_INVALGROUPID = 0x8000002A;

        public const uint LINEERR_INVALLINEHANDLE = 0x8000002B;

        public const uint LINEERR_INVALLINESTATE = 0x8000002C;

        public const uint LINEERR_INVALLOCATION = 0x8000002D;

        public const uint LINEERR_INVALMEDIALIST = 0x8000002E;

        public const uint LINEERR_INVALMEDIAMODE = 0x8000002F;

        public const uint LINEERR_INVALMESSAGEID = 0x80000030;

        public const uint LINEERR_INVALPARAM = 0x80000032;

        public const uint LINEERR_INVALPARKID = 0x80000033;

        public const uint LINEERR_INVALPARKMODE = 0x80000034;

        public const uint LINEERR_INVALPOINTER = 0x80000035;

        public const uint LINEERR_INVALPRIVSELECT = 0x80000036;

        public const uint LINEERR_INVALRATE = 0x80000037;

        public const uint LINEERR_INVALREQUESTMODE = 0x80000038;

        public const uint LINEERR_INVALTERMINALID = 0x80000039;

        public const uint LINEERR_INVALTERMINALMODE = 0x8000003A;

        public const uint LINEERR_INVALTIMEOUT = 0x8000003B;

        public const uint LINEERR_INVALTONE = 0x8000003C;

        public const uint LINEERR_INVALTONELIST = 0x8000003D;

        public const uint LINEERR_INVALTONEMODE = 0x8000003E;

        public const uint LINEERR_INVALTRANSFERMODE = 0x8000003F;

        public const uint LINEERR_LINEMAPPERFAILED = 0x80000040;

        public const uint LINEERR_NOCONFERENCE = 0x80000041;

        public const uint LINEERR_NODEVICE = 0x80000042;

        public const uint LINEERR_NODRIVER = 0x80000043;

        public const uint LINEERR_NOMEM = 0x80000044;

        public const uint LINEERR_NOREQUEST = 0x80000045;

        public const uint LINEERR_NOTOWNER = 0x80000046;

        public const uint LINEERR_NOTREGISTERED = 0x80000047;

        public const uint LINEERR_OPERATIONFAILED = 0x80000048;

        public const uint LINEERR_OPERATIONUNAVAIL = 0x80000049;

        public const uint LINEERR_RATEUNAVAIL = 0x8000004A;

        public const uint LINEERR_RESOURCEUNAVAIL = 0x8000004B;

        public const uint LINEERR_REQUESTOVERRUN = 0x8000004C;

        public const uint LINEERR_STRUCTURETOOSMALL = 0x8000004D;

        public const uint LINEERR_TARGETNOTFOUND = 0x8000004E;

        public const uint LINEERR_TARGETSELF = 0x8000004F;

        public const uint LINEERR_UNINITIALIZED = 0x80000050;

        public const uint LINEERR_USERUSERINFOTOOBIG = 0x80000051;

        public const uint LINEERR_REINIT = 0x80000052;

        public const uint LINEERR_ADDRESSBLOCKED = 0x80000053;

        public const uint LINEERR_BILLINGREJECTED = 0x80000054;

        public const uint LINEERR_INVALFEATURE = 0x80000055;

        public const uint LINEERR_NOMULTIPLEINSTANCE = 0x80000056;

        public const uint LINEERR_INVALAGENTID = 0x80000057;

        public const uint LINEERR_INVALAGENTGROUP = 0x80000058;

        public const uint LINEERR_INVALPASSWORD = 0x80000059;

        public const uint LINEERR_INVALAGENTSTATE = 0x8000005A;

        public const uint LINEERR_INVALAGENTACTIVITY = 0x8000005B;

        public const uint LINEERR_DIALVOICEDETECT = 0x8000005C;

        public const uint LINEERR_USERCANCELLED = 0x8000005D;

        public const uint LINEERR_INVALADDRESSTYPE = 0x8000005E;

        public const uint LINEERR_INVALAGENTSESSIONSTATE = 0x8000005F;

        public const uint LINEERR_DISCONNECTED = 0X80000060;

        public const uint LINEERR_SERVICE_NOT_RUNNING = 0x80000061;

        public const uint LINEFEATURE_DEVSPECIFIC = 0x00000001;

        public const uint LINEFEATURE_DEVSPECIFICFEAT = 0x00000002;

        public const uint LINEFEATURE_FORWARD = 0x00000004;

        public const uint LINEFEATURE_MAKECALL = 0x00000008;

        public const uint LINEFEATURE_SETMEDIACONTROL = 0x00000010;

        public const uint LINEFEATURE_SETTERMINAL = 0x00000020;

        public const uint LINEFEATURE_SETDEVSTATUS = 0x00000040;

        public const uint LINEFEATURE_FORWARDFWD = 0x00000080;

        public const uint LINEFEATURE_FORWARDDND = 0x00000100;

        public const uint LINEFORWARDMODE_UNCOND = 0x00000001;

        public const uint LINEFORWARDMODE_UNCONDINTERNAL = 0x00000002;

        public const uint LINEFORWARDMODE_UNCONDEXTERNAL = 0x00000004;

        public const uint LINEFORWARDMODE_UNCONDSPECIFIC = 0x00000008;

        public const uint LINEFORWARDMODE_BUSY = 0x00000010;

        public const uint LINEFORWARDMODE_BUSYINTERNAL = 0x00000020;

        public const uint LINEFORWARDMODE_BUSYEXTERNAL = 0x00000040;

        public const uint LINEFORWARDMODE_BUSYSPECIFIC = 0x00000080;

        public const uint LINEFORWARDMODE_NOANSW = 0x00000100;

        public const uint LINEFORWARDMODE_NOANSWINTERNAL = 0x00000200;

        public const uint LINEFORWARDMODE_NOANSWEXTERNAL = 0x00000400;

        public const uint LINEFORWARDMODE_NOANSWSPECIFIC = 0x00000800;

        public const uint LINEFORWARDMODE_BUSYNA = 0x00001000;

        public const uint LINEFORWARDMODE_BUSYNAINTERNAL = 0x00002000;

        public const uint LINEFORWARDMODE_BUSYNAEXTERNAL = 0x00004000;

        public const uint LINEFORWARDMODE_BUSYNASPECIFIC = 0x00008000;

        public const uint LINEFORWARDMODE_UNKNOWN = 0x00010000;

        public const uint LINEFORWARDMODE_UNAVAIL = 0x00020000;

        public const uint LINEGATHERTERM_BUFFERFULL = 0x00000001;

        public const uint LINEGATHERTERM_TERMDIGIT = 0x00000002;

        public const uint LINEGATHERTERM_FIRSTTIMEOUT = 0x00000004;

        public const uint LINEGATHERTERM_INTERTIMEOUT = 0x00000008;

        public const uint LINEGATHERTERM_CANCEL = 0x00000010;

        public const uint LINEGENERATETERM_DONE = 0x00000001;

        public const uint LINEGENERATETERM_CANCEL = 0x00000002;

        public const uint LINEINITIALIZEEXOPTION_USEHIDDENWINDOW = 0x00000001;

        public const uint LINEINITIALIZEEXOPTION_USEEVENT = 0x00000002;

        public const uint LINEINITIALIZEEXOPTION_USECOMPLETIONPORT = 0x00000003;

        public const uint LINEINITIALIZEEXOPTION_CALLHUBTRACKING = 0x80000000;

        public const uint LINELOCATIONOPTION_PULSEDIAL = 0x00000001;

        public const uint LINEMAPPER = 0xFFFFFFFF;

        public const uint LINEMEDIACONTROL_NONE = 0x00000001;

        public const uint LINEMEDIACONTROL_START = 0x00000002;

        public const uint LINEMEDIACONTROL_RESET = 0x00000004;

        public const uint LINEMEDIACONTROL_PAUSE = 0x00000008;

        public const uint LINEMEDIACONTROL_RESUME = 0x00000010;

        public const uint LINEMEDIACONTROL_RATEUP = 0x00000020;

        public const uint LINEMEDIACONTROL_RATEDOWN = 0x00000040;

        public const uint LINEMEDIACONTROL_RATENORMAL = 0x00000080;

        public const uint LINEMEDIACONTROL_VOLUMEUP = 0x00000100;

        public const uint LINEMEDIACONTROL_VOLUMEDOWN = 0x00000200;

        public const uint LINEMEDIACONTROL_VOLUMENORMAL = 0x00000400;

        public const uint LINEMEDIAMODE_UNKNOWN = 0x00000002;

        public const uint LINEMEDIAMODE_INTERACTIVEVOICE = 0x00000004;

        public const uint LINEMEDIAMODE_AUTOMATEDVOICE = 0x00000008;

        public const uint LINEMEDIAMODE_DATAMODEM = 0x00000010;

        public const uint LINEMEDIAMODE_G3FAX = 0x00000020;

        public const uint LINEMEDIAMODE_TDD = 0x00000040;

        public const uint LINEMEDIAMODE_G4FAX = 0x00000080;

        public const uint LINEMEDIAMODE_DIGITALDATA = 0x00000100;

        public const uint LINEMEDIAMODE_TELETEX = 0x00000200;

        public const uint LINEMEDIAMODE_VIDEOTEX = 0x00000400;

        public const uint LINEMEDIAMODE_TELEX = 0x00000800;

        public const uint LINEMEDIAMODE_MIXED = 0x00001000;

        public const uint LINEMEDIAMODE_ADSI = 0x00002000;

        public const uint LINEMEDIAMODE_VOICEVIEW = 0x00004000;

        public const uint LINEMEDIAMODE_VIDEO = 0x00008000;

        public const uint LAST_LINEMEDIAMODE = 0x00008000;

        public const uint LINEOFFERINGMODE_ACTIVE = 0x00000001;

        public const uint LINEOFFERINGMODE_INACTIVE = 0x00000002;

        public const uint LINEOPENOPTION_SINGLEADDRESS = 0x80000000;

        public const uint LINEOPENOPTION_PROXY = 0x40000000;

        public const uint LINEPARKMODE_DIRECTED = 0x00000001;

        public const uint LINEPARKMODE_NONDIRECTED = 0x00000002;

        public const uint LINEPROXYREQUEST_SETAGENTGROUP = 0x00000001;

        public const uint LINEPROXYREQUEST_SETAGENTSTATE = 0x00000002;

        public const uint LINEPROXYREQUEST_SETAGENTACTIVITY = 0x00000003;

        public const uint LINEPROXYREQUEST_GETAGENTCAPS = 0x00000004;

        public const uint LINEPROXYREQUEST_GETAGENTSTATUS = 0x00000005;

        public const uint LINEPROXYREQUEST_AGENTSPECIFIC = 0x00000006;

        public const uint LINEPROXYREQUEST_GETAGENTACTIVITYLIST = 0x00000007;

        public const uint LINEPROXYREQUEST_GETAGENTGROUPLIST = 0x00000008;

        public const uint LINEPROXYREQUEST_CREATEAGENT = 0x00000009;

        public const uint LINEPROXYREQUEST_SETAGENTMEASUREMENTPERIOD = 0x0000000A;

        public const uint LINEPROXYREQUEST_GETAGENTINFO = 0x0000000B;

        public const uint LINEPROXYREQUEST_CREATEAGENTSESSION = 0x0000000C;

        public const uint LINEPROXYREQUEST_GETAGENTSESSIONLIST = 0x0000000D;

        public const uint LINEPROXYREQUEST_SETAGENTSESSIONSTATE = 0x0000000E;

        public const uint LINEPROXYREQUEST_GETAGENTSESSIONINFO = 0x0000000F;

        public const uint LINEPROXYREQUEST_GETQUEUELIST = 0x00000010;

        public const uint LINEPROXYREQUEST_SETQUEUEMEASUREMENTPERIOD = 0x00000011;

        public const uint LINEPROXYREQUEST_GETQUEUEINFO = 0x00000012;

        public const uint LINEPROXYREQUEST_GETGROUPLIST = 0x00000013;

        public const uint LINEPROXYREQUEST_SETAGENTSTATEEX = 0x00000014;

        public const uint LINEREMOVEFROMCONF_NONE = 0x00000001;

        public const uint LINEREMOVEFROMCONF_LAST = 0x00000002;

        public const uint LINEREMOVEFROMCONF_ANY = 0x00000003;

        public const uint LINEREQUESTMODE_MAKECALL = 0x00000001;

        public const uint LINEREQUESTMODE_MEDIACALL = 0x00000002;

        public const uint LINEREQUESTMODE_DROP = 0x00000004;

        public const uint LINEROAMMODE_UNKNOWN = 0x00000001;

        public const uint LINEROAMMODE_UNAVAIL = 0x00000002;

        public const uint LINEROAMMODE_HOME = 0x00000004;

        public const uint LINEROAMMODE_ROAMA = 0x00000008;

        public const uint LINEROAMMODE_ROAMB = 0x00000010;

        public const uint LINESPECIALINFO_NOCIRCUIT = 0x00000001;

        public const uint LINESPECIALINFO_CUSTIRREG = 0x00000002;

        public const uint LINESPECIALINFO_REORDER = 0x00000004;

        public const uint LINESPECIALINFO_UNKNOWN = 0x00000008;

        public const uint LINESPECIALINFO_UNAVAIL = 0x00000010;

        public const uint LINETERMDEV_PHONE = 0x00000001;

        public const uint LINETERMDEV_HEADSET = 0x00000002;

        public const uint LINETERMDEV_SPEAKER = 0x00000004;

        public const uint LINETERMMODE_BUTTONS = 0x00000001;

        public const uint LINETERMMODE_LAMPS = 0x00000002;

        public const uint LINETERMMODE_DISPLAY = 0x00000004;

        public const uint LINETERMMODE_RINGER = 0x00000008;

        public const uint LINETERMMODE_HOOKSWITCH = 0x00000010;

        public const uint LINETERMMODE_MEDIATOLINE = 0x00000020;

        public const uint LINETERMMODE_MEDIAFROMLINE = 0x00000040;

        public const uint LINETERMMODE_MEDIABIDIRECT = 0x00000080;

        public const uint LINETERMSHARING_PRIVATE = 0x00000001;

        public const uint LINETERMSHARING_SHAREDEXCL = 0x00000002;

        public const uint LINETERMSHARING_SHAREDCONF = 0x00000004;

        public const uint LINETOLLLISTOPTION_ADD = 0x00000001;

        public const uint LINETOLLLISTOPTION_REMOVE = 0x00000002;

        public const uint LINETONEMODE_CUSTOM = 0x00000001;

        public const uint LINETONEMODE_RINGBACK = 0x00000002;

        public const uint LINETONEMODE_BUSY = 0x00000004;

        public const uint LINETONEMODE_BEEP = 0x00000008;

        public const uint LINETONEMODE_BILLING = 0x00000010;

        public const uint LINETRANSFERMODE_TRANSFER = 0x00000001;

        public const uint LINETRANSFERMODE_CONFERENCE = 0x00000002;

        public const uint LINETRANSLATEOPTION_CARDOVERRIDE = 0x00000001;

        public const uint LINETRANSLATEOPTION_CANCELCALLWAITING = 0x00000002;

        public const uint LINETRANSLATEOPTION_FORCELOCAL = 0x00000004;

        public const uint LINETRANSLATEOPTION_FORCELD = 0x00000008;

        public const uint LINETRANSLATERESULT_CANONICAL = 0x00000001;

        public const uint LINETRANSLATERESULT_INTERNATIONAL = 0x00000002;

        public const uint LINETRANSLATERESULT_LONGDISTANCE = 0x00000004;

        public const uint LINETRANSLATERESULT_LOCAL = 0x00000008;

        public const uint LINETRANSLATERESULT_INTOLLLIST = 0x00000010;

        public const uint LINETRANSLATERESULT_NOTINTOLLLIST = 0x00000020;

        public const uint LINETRANSLATERESULT_DIALBILLING = 0x00000040;

        public const uint LINETRANSLATERESULT_DIALQUIET = 0x00000080;

        public const uint LINETRANSLATERESULT_DIALDIALTONE = 0x00000100;

        public const uint LINETRANSLATERESULT_DIALPROMPT = 0x00000200;

        public const uint LINETRANSLATERESULT_VOICEDETECT = 0x00000400;

        public const uint LINETRANSLATERESULT_NOTRANSLATION = 0x00000800;

        public const uint PHONEBUTTONFUNCTION_UNKNOWN = 0x00000000;

        public const uint PHONEBUTTONFUNCTION_CONFERENCE = 0x00000001;

        public const uint PHONEBUTTONFUNCTION_TRANSFER = 0x00000002;

        public const uint PHONEBUTTONFUNCTION_DROP = 0x00000003;

        public const uint PHONEBUTTONFUNCTION_HOLD = 0x00000004;

        public const uint PHONEBUTTONFUNCTION_RECALL = 0x00000005;

        public const uint PHONEBUTTONFUNCTION_DISCONNECT = 0x00000006;

        public const uint PHONEBUTTONFUNCTION_CONNECT = 0x00000007;

        public const uint PHONEBUTTONFUNCTION_MSGWAITON = 0x00000008;

        public const uint PHONEBUTTONFUNCTION_MSGWAITOFF = 0x00000009;

        public const uint PHONEBUTTONFUNCTION_SELECTRING = 0x0000000A;

        public const uint PHONEBUTTONFUNCTION_ABBREVDIAL = 0x0000000B;

        public const uint PHONEBUTTONFUNCTION_FORWARD = 0x0000000C;

        public const uint PHONEBUTTONFUNCTION_PICKUP = 0x0000000D;

        public const uint PHONEBUTTONFUNCTION_RINGAGAIN = 0x0000000E;

        public const uint PHONEBUTTONFUNCTION_PARK = 0x0000000F;

        public const uint PHONEBUTTONFUNCTION_REJECT = 0x00000010;

        public const uint PHONEBUTTONFUNCTION_REDIRECT = 0x00000011;

        public const uint PHONEBUTTONFUNCTION_MUTE = 0x00000012;

        public const uint PHONEBUTTONFUNCTION_VOLUMEUP = 0x00000013;

        public const uint PHONEBUTTONFUNCTION_VOLUMEDOWN = 0x00000014;

        public const uint PHONEBUTTONFUNCTION_SPEAKERON = 0x00000015;

        public const uint PHONEBUTTONFUNCTION_SPEAKEROFF = 0x00000016;

        public const uint PHONEBUTTONFUNCTION_FLASH = 0x00000017;

        public const uint PHONEBUTTONFUNCTION_DATAON = 0x00000018;

        public const uint PHONEBUTTONFUNCTION_DATAOFF = 0x00000019;

        public const uint PHONEBUTTONFUNCTION_DONOTDISTURB = 0x0000001A;

        public const uint PHONEBUTTONFUNCTION_INTERCOM = 0x0000001B;

        public const uint PHONEBUTTONFUNCTION_BRIDGEDAPP = 0x0000001C;

        public const uint PHONEBUTTONFUNCTION_BUSY = 0x0000001D;

        public const uint PHONEBUTTONFUNCTION_CALLAPP = 0x0000001E;

        public const uint PHONEBUTTONFUNCTION_DATETIME = 0x0000001F;

        public const uint PHONEBUTTONFUNCTION_DIRECTORY = 0x00000020;

        public const uint PHONEBUTTONFUNCTION_COVER = 0x00000021;

        public const uint PHONEBUTTONFUNCTION_CALLID = 0x00000022;

        public const uint PHONEBUTTONFUNCTION_LASTNUM = 0x00000023;

        public const uint PHONEBUTTONFUNCTION_NIGHTSRV = 0x00000024;

        public const uint PHONEBUTTONFUNCTION_SENDCALLS = 0x00000025;

        public const uint PHONEBUTTONFUNCTION_MSGINDICATOR = 0x00000026;

        public const uint PHONEBUTTONFUNCTION_REPDIAL = 0x00000027;

        public const uint PHONEBUTTONFUNCTION_SETREPDIAL = 0x00000028;

        public const uint PHONEBUTTONFUNCTION_SYSTEMSPEED = 0x00000029;

        public const uint PHONEBUTTONFUNCTION_STATIONSPEED = 0x0000002A;

        public const uint PHONEBUTTONFUNCTION_CAMPON = 0x0000002B;

        public const uint PHONEBUTTONFUNCTION_SAVEREPEAT = 0x0000002C;

        public const uint PHONEBUTTONFUNCTION_QUEUECALL = 0x0000002D;

        public const uint PHONEBUTTONFUNCTION_NONE = 0x0000002E;

        public const uint PHONEBUTTONFUNCTION_SEND = 0x0000002F;

        public const uint PHONEBUTTONMODE_DUMMY = 0x00000001;

        public const uint PHONEBUTTONMODE_CALL = 0x00000002;

        public const uint PHONEBUTTONMODE_FEATURE = 0x00000004;

        public const uint PHONEBUTTONMODE_KEYPAD = 0x00000008;

        public const uint PHONEBUTTONMODE_LOCAL = 0x00000010;

        public const uint PHONEBUTTONMODE_DISPLAY = 0x00000020;

        public const uint PHONEBUTTONSTATE_UP = 0x00000001;

        public const uint PHONEBUTTONSTATE_DOWN = 0x00000002;

        public const uint PHONEBUTTONSTATE_UNKNOWN = 0x00000004;

        public const uint PHONEBUTTONSTATE_UNAVAIL = 0x00000008;

        public const uint PHONEERR_ALLOCATED = 0x90000001;

        public const uint PHONEERR_BADDEVICEID = 0x90000002;

        public const uint PHONEERR_INCOMPATIBLEAPIVERSION = 0x90000003;

        public const uint PHONEERR_INCOMPATIBLEEXTVERSION = 0x90000004;

        public const uint PHONEERR_INIFILECORRUPT = 0x90000005;

        public const uint PHONEERR_INUSE = 0x90000006;

        public const uint PHONEERR_INVALAPPHANDLE = 0x90000007;

        public const uint PHONEERR_INVALAPPNAME = 0x90000008;

        public const uint PHONEERR_INVALBUTTONLAMPID = 0x90000009;

        public const uint PHONEERR_INVALBUTTONMODE = 0x9000000A;

        public const uint PHONEERR_INVALBUTTONSTATE = 0x9000000B;

        public const uint PHONEERR_INVALDATAID = 0x9000000C;

        public const uint PHONEERR_INVALDEVICECLASS = 0x9000000D;

        public const uint PHONEERR_INVALEXTVERSION = 0x9000000E;

        public const uint PHONEERR_INVALHOOKSWITCHDEV = 0x9000000F;

        public const uint PHONEERR_INVALHOOKSWITCHMODE = 0x90000010;

        public const uint PHONEERR_INVALLAMPMODE = 0x90000011;

        public const uint PHONEERR_INVALPARAM = 0x90000012;

        public const uint PHONEERR_INVALPHONEHANDLE = 0x90000013;

        public const uint PHONEERR_INVALPHONESTATE = 0x90000014;

        public const uint PHONEERR_INVALPOINTER = 0x90000015;

        public const uint PHONEERR_INVALPRIVILEGE = 0x90000016;

        public const uint PHONEERR_INVALRINGMODE = 0x90000017;

        public const uint PHONEERR_NODEVICE = 0x90000018;

        public const uint PHONEERR_NODRIVER = 0x90000019;

        public const uint PHONEERR_NOMEM = 0x9000001A;

        public const uint PHONEERR_NOTOWNER = 0x9000001B;

        public const uint PHONEERR_OPERATIONFAILED = 0x9000001C;

        public const uint PHONEERR_OPERATIONUNAVAIL = 0x9000001D;

        public const uint PHONEERR_RESOURCEUNAVAIL = 0x9000001F;

        public const uint PHONEERR_REQUESTOVERRUN = 0x90000020;

        public const uint PHONEERR_STRUCTURETOOSMALL = 0x90000021;

        public const uint PHONEERR_UNINITIALIZED = 0x90000022;

        public const uint PHONEERR_REINIT = 0x90000023;

        public const uint PHONEERR_DISCONNECTED = 0x90000024;

        public const uint PHONEERR_SERVICE_NOT_RUNNING = 0x90000025;

        public const uint PHONEFEATURE_GETBUTTONINFO = 0x00000001;

        public const uint PHONEFEATURE_GETDATA = 0x00000002;

        public const uint PHONEFEATURE_GETDISPLAY = 0x00000004;

        public const uint PHONEFEATURE_GETGAINHANDSET = 0x00000008;

        public const uint PHONEFEATURE_GETGAINSPEAKER = 0x00000010;

        public const uint PHONEFEATURE_GETGAINHEADSET = 0x00000020;

        public const uint PHONEFEATURE_GETHOOKSWITCHHANDSET = 0x00000040;

        public const uint PHONEFEATURE_GETHOOKSWITCHSPEAKER = 0x00000080;

        public const uint PHONEFEATURE_GETHOOKSWITCHHEADSET = 0x00000100;

        public const uint PHONEFEATURE_GETLAMP = 0x00000200;

        public const uint PHONEFEATURE_GETRING = 0x00000400;

        public const uint PHONEFEATURE_GETVOLUMEHANDSET = 0x00000800;

        public const uint PHONEFEATURE_GETVOLUMESPEAKER = 0x00001000;

        public const uint PHONEFEATURE_GETVOLUMEHEADSET = 0x00002000;

        public const uint PHONEFEATURE_SETBUTTONINFO = 0x00004000;

        public const uint PHONEFEATURE_SETDATA = 0x00008000;

        public const uint PHONEFEATURE_SETDISPLAY = 0x00010000;

        public const uint PHONEFEATURE_SETGAINHANDSET = 0x00020000;

        public const uint PHONEFEATURE_SETGAINSPEAKER = 0x00040000;

        public const uint PHONEFEATURE_SETGAINHEADSET = 0x00080000;

        public const uint PHONEFEATURE_SETHOOKSWITCHHANDSET = 0x00100000;

        public const uint PHONEFEATURE_SETHOOKSWITCHSPEAKER = 0x00200000;

        public const uint PHONEFEATURE_SETHOOKSWITCHHEADSET = 0x00400000;

        public const uint PHONEFEATURE_SETLAMP = 0x00800000;

        public const uint PHONEFEATURE_SETRING = 0x01000000;

        public const uint PHONEFEATURE_SETVOLUMEHANDSET = 0x02000000;

        public const uint PHONEFEATURE_SETVOLUMESPEAKER = 0x04000000;

        public const uint PHONEFEATURE_SETVOLUMEHEADSET = 0x08000000;

        public const uint PHONEFEATURE_GENERICPHONE = 0x10000000;

        public const uint PHONEHOOKSWITCHDEV_HANDSET = 0x00000001;

        public const uint PHONEHOOKSWITCHDEV_SPEAKER = 0x00000002;

        public const uint PHONEHOOKSWITCHDEV_HEADSET = 0x00000004;

        public const uint PHONEHOOKSWITCHMODE_ONHOOK = 0x00000001;

        public const uint PHONEHOOKSWITCHMODE_MIC = 0x00000002;

        public const uint PHONEHOOKSWITCHMODE_SPEAKER = 0x00000004;

        public const uint PHONEHOOKSWITCHMODE_MICSPEAKER = 0x00000008;

        public const uint PHONEHOOKSWITCHMODE_UNKNOWN = 0x00000010;

        public const uint PHONEINITIALIZEEXOPTION_USEHIDDENWINDOW = 0x00000001;

        public const uint PHONEINITIALIZEEXOPTION_USEEVENT = 0x00000002;

        public const uint PHONEINITIALIZEEXOPTION_USECOMPLETIONPORT = 0x00000003;

        public const uint PHONELAMPMODE_DUMMY = 0x00000001;

        public const uint PHONELAMPMODE_OFF = 0x00000002;

        public const uint PHONELAMPMODE_STEADY = 0x00000004;

        public const uint PHONELAMPMODE_WINK = 0x00000008;

        public const uint PHONELAMPMODE_FLASH = 0x00000010;

        public const uint PHONELAMPMODE_FLUTTER = 0x00000020;

        public const uint PHONELAMPMODE_BROKENFLUTTER = 0x00000040;

        public const uint PHONELAMPMODE_UNKNOWN = 0x00000080;

        public const uint PHONEPRIVILEGE_MONITOR = 0x00000001;

        public const uint PHONEPRIVILEGE_OWNER = 0x00000002;

        public const uint PHONESTATE_OTHER = 0x00000001;

        public const uint PHONESTATE_CONNECTED = 0x00000002;

        public const uint PHONESTATE_DISCONNECTED = 0x00000004;

        public const uint PHONESTATE_OWNER = 0x00000008;

        public const uint PHONESTATE_MONITORS = 0x00000010;

        public const uint PHONESTATE_DISPLAY = 0x00000020;

        public const uint PHONESTATE_LAMP = 0x00000040;

        public const uint PHONESTATE_RINGMODE = 0x00000080;

        public const uint PHONESTATE_RINGVOLUME = 0x00000100;

        public const uint PHONESTATE_HANDSETHOOKSWITCH = 0x00000200;

        public const uint PHONESTATE_HANDSETVOLUME = 0x00000400;

        public const uint PHONESTATE_HANDSETGAIN = 0x00000800;

        public const uint PHONESTATE_SPEAKERHOOKSWITCH = 0x00001000;

        public const uint PHONESTATE_SPEAKERVOLUME = 0x00002000;

        public const uint PHONESTATE_SPEAKERGAIN = 0x00004000;

        public const uint PHONESTATE_HEADSETHOOKSWITCH = 0x00008000;

        public const uint PHONESTATE_HEADSETVOLUME = 0x00010000;

        public const uint PHONESTATE_HEADSETGAIN = 0x00020000;

        public const uint PHONESTATE_SUSPEND = 0x00040000;

        public const uint PHONESTATE_RESUME = 0x00080000;

        public const uint PHONESTATE_DEVSPECIFIC = 0x00100000;

        public const uint PHONESTATE_REINIT = 0x00200000;

        public const uint PHONESTATE_CAPSCHANGE = 0x00400000;

        public const uint PHONESTATE_REMOVED = 0x00800000;

        public const uint PHONESTATUSFLAGS_CONNECTED = 0x00000001;

        public const uint PHONESTATUSFLAGS_SUSPENDED = 0x00000002;

        public const uint STRINGFORMAT_ASCII = 0x00000001;

        public const uint STRINGFORMAT_DBCS = 0x00000002;

        public const uint STRINGFORMAT_UNICODE = 0x00000003;

        public const uint STRINGFORMAT_BINARY = 0x00000004;

        public const uint TAPI_REPLY = WM_USER + 99;

        public const int TAPIERR_CONNECTED = 0;

        public const int TAPIERR_DROPPED = -1;

        public const int TAPIERR_NOREQUESTRECIPIENT = -2;

        public const int TAPIERR_REQUESTQUEUEFULL = -3;

        public const int TAPIERR_INVALDESTADDRESS = -4;

        public const int TAPIERR_INVALWINDOWHANDLE = -5;

        public const int TAPIERR_INVALDEVICECLASS = -6;

        public const int TAPIERR_INVALDEVICEID = -7;

        public const int TAPIERR_DEVICECLASSUNAVAIL = -8;

        public const int TAPIERR_DEVICEIDUNAVAIL = -9;

        public const int TAPIERR_DEVICEINUSE = -10;

        public const int TAPIERR_DESTBUSY = -11;

        public const int TAPIERR_DESTNOANSWER = -12;

        public const int TAPIERR_DESTUNAVAIL = -13;

        public const int TAPIERR_UNKNOWNWINHANDLE = -14;

        public const int TAPIERR_UNKNOWNREQUESTID = -15;

        public const int TAPIERR_REQUESTFAILED = -16;

        public const int TAPIERR_REQUESTCANCELLED = -17;

        public const int TAPIERR_INVALPOINTER = -18;

        public const int TAPIERR_NOTADMIN = -19;

        public const int TAPIERR_MMCWRITELOCKED = -20;

        public const int TAPIERR_PROVIDERALREADYINSTALLED = -21;

        public const int TAPIERR_SCP_ALREADY_EXISTS = -22;

        public const int TAPIERR_SCP_DOES_NOT_EXIST = -23;

        public const int TAPIMAXDESTADDRESSSIZE = 80;

        public const int TAPIMAXAPPNAMESIZE = 40;

        public const int TAPIMAXCALLEDPARTYSIZE = 40;

        public const int TAPIMAXCOMMENTSIZE = 80;

        public const int TAPIMAXDEVICECLASSSIZE = 40;

        public const int TAPIMAXDEVICEIDSIZE = 40;

        public const uint INTERFACEMASK = 0xff0000;

        public const uint DISPIDMASK = 0xffff;

        public const uint IDISPTAPI = 0x10000;

        public const uint IDISPTAPICALLCENTER = 0x20000;

        public const uint IDISPCALLINFO = 0x10000;

        public const uint IDISPBASICCALLCONTROL = 0x20000;

        public const uint IDISPLEGACYCALLMEDIACONTROL = 0x30000;

        public const uint IDISPAGGREGATEDMSPCALLOBJ = 0x40000;

        public const uint IDISPADDRESS = 0x10000;

        public const uint IDISPADDRESSCAPABILITIES = 0x20000;

        public const uint IDISPMEDIASUPPORT = 0x30000;

        public const uint IDISPADDRESSTRANSLATION = 0x40000;

        public const uint IDISPLEGACYADDRESSMEDIACONTROL = 0x50000;

        public const uint IDISPAGGREGATEDMSPADDRESSOBJ = 0x60000;

        public const uint IDISPPHONE = 0x10000;

        public const uint IDISPAPC = 0x20000;

        public const uint IDISPMULTITRACK = 0x10000;

        public const uint IDISPMEDIACONTROL = 0x20000;

        public const uint IDISPMEDIARECORD = 0x30000;

        public const uint IDISPMEDIAPLAYBACK = 0x40000;

        public const uint IDISPFILETRACK = 0x10000;

        public const uint TAPIMEDIATYPE_AUDIO = 0x8;

        public const uint TAPIMEDIATYPE_VIDEO = 0x8000;

        public const uint TAPIMEDIATYPE_DATAMODEM = 0x10;

        public const uint TAPIMEDIATYPE_G3FAX = 0x20;

        public const uint TAPIMEDIATYPE_MULTITRACK = 0x10000;

        public const uint TSPI_MESSAGE_BASE = 500;

        public const uint LINETSPIOPTION_NONREENTRANT = 0x00000001;

        public const int TUISPIDLL_OBJECT_LINEID = 1;

        public const int TUISPIDLL_OBJECT_PHONEID = 2;

        public const int TUISPIDLL_OBJECT_PROVIDERID = 3;

        public const int TUISPIDLL_OBJECT_DIALOGINSTANCE = 4;

        public const uint PRIVATEOBJECT_NONE = 0x00000001;

        public const uint PRIVATEOBJECT_CALLID = 0x00000002;

        public const uint PRIVATEOBJECT_LINE = 0x00000003;

        public const uint PRIVATEOBJECT_CALL = 0x00000004;

        public const uint PRIVATEOBJECT_PHONE = 0x00000005;

        public const uint PRIVATEOBJECT_ADDRESS = 0x00000006;

        public const uint LINEQOSREQUESTTYPE_SERVICELEVEL = 0x00000001;

        public const uint LINEQOSSERVICELEVEL_NEEDED = 0x00000001;

        public const uint LINEQOSSERVICELEVEL_IFAVAILABLE = 0x00000002;

        public const uint LINEQOSSERVICELEVEL_BESTEFFORT = 0x00000003;

        public const uint LINEEQOSINFO_NOQOS = 0x00000001;

        public const uint LINEEQOSINFO_ADMISSIONFAILURE = 0x00000002;

        public const uint LINEEQOSINFO_POLICYFAILURE = 0x00000003;

        public const uint LINEEQOSINFO_GENERICERROR = 0x00000004;

        public const uint TSPI_PROC_BASE = 500;

        public const uint TSPI_LINEACCEPT = TSPI_PROC_BASE + 0;

        public const uint TSPI_LINEADDTOCONFERENCE = TSPI_PROC_BASE + 1;

        public const uint TSPI_LINEANSWER = TSPI_PROC_BASE + 2;

        public const uint TSPI_LINEBLINDTRANSFER = TSPI_PROC_BASE + 3;

        public const uint TSPI_LINECLOSE = TSPI_PROC_BASE + 4;

        public const uint TSPI_LINECLOSECALL = TSPI_PROC_BASE + 5;

        public const uint TSPI_LINECOMPLETECALL = TSPI_PROC_BASE + 6;

        public const uint TSPI_LINECOMPLETETRANSFER = TSPI_PROC_BASE + 7;

        public const uint TSPI_LINECONDITIONALMEDIADETECTION = TSPI_PROC_BASE + 8;

        public const uint TSPI_LINECONFIGDIALOG = TSPI_PROC_BASE + 9;

        public const uint TSPI_LINEDEVSPECIFIC = TSPI_PROC_BASE + 10;

        public const uint TSPI_LINEDEVSPECIFICFEATURE = TSPI_PROC_BASE + 11;

        public const uint TSPI_LINEDIAL = TSPI_PROC_BASE + 12;

        public const uint TSPI_LINEDROP = TSPI_PROC_BASE + 13;

        public const uint TSPI_LINEFORWARD = TSPI_PROC_BASE + 14;

        public const uint TSPI_LINEGATHERDIGITS = TSPI_PROC_BASE + 15;

        public const uint TSPI_LINEGENERATEDIGITS = TSPI_PROC_BASE + 16;

        public const uint TSPI_LINEGENERATETONE = TSPI_PROC_BASE + 17;

        public const uint TSPI_LINEGETADDRESSCAPS = TSPI_PROC_BASE + 18;

        public const uint TSPI_LINEGETADDRESSID = TSPI_PROC_BASE + 19;

        public const uint TSPI_LINEGETADDRESSSTATUS = TSPI_PROC_BASE + 20;

        public const uint TSPI_LINEGETCALLADDRESSID = TSPI_PROC_BASE + 21;

        public const uint TSPI_LINEGETCALLINFO = TSPI_PROC_BASE + 22;

        public const uint TSPI_LINEGETCALLSTATUS = TSPI_PROC_BASE + 23;

        public const uint TSPI_LINEGETDEVCAPS = TSPI_PROC_BASE + 24;

        public const uint TSPI_LINEGETDEVCONFIG = TSPI_PROC_BASE + 25;

        public const uint TSPI_LINEGETEXTENSIONID = TSPI_PROC_BASE + 26;

        public const uint TSPI_LINEGETICON = TSPI_PROC_BASE + 27;

        public const uint TSPI_LINEGETID = TSPI_PROC_BASE + 28;

        public const uint TSPI_LINEGETLINEDEVSTATUS = TSPI_PROC_BASE + 29;

        public const uint TSPI_LINEGETNUMADDRESSIDS = TSPI_PROC_BASE + 30;

        public const uint TSPI_LINEHOLD = TSPI_PROC_BASE + 31;

        public const uint TSPI_LINEMAKECALL = TSPI_PROC_BASE + 32;

        public const uint TSPI_LINEMONITORDIGITS = TSPI_PROC_BASE + 33;

        public const uint TSPI_LINEMONITORMEDIA = TSPI_PROC_BASE + 34;

        public const uint TSPI_LINEMONITORTONES = TSPI_PROC_BASE + 35;

        public const uint TSPI_LINENEGOTIATEEXTVERSION = TSPI_PROC_BASE + 36;

        public const uint TSPI_LINENEGOTIATETSPIVERSION = TSPI_PROC_BASE + 37;

        public const uint TSPI_LINEOPEN = TSPI_PROC_BASE + 38;

        public const uint TSPI_LINEPARK = TSPI_PROC_BASE + 39;

        public const uint TSPI_LINEPICKUP = TSPI_PROC_BASE + 40;

        public const uint TSPI_LINEPREPAREADDTOCONFERENCE = TSPI_PROC_BASE + 41;

        public const uint TSPI_LINEREDIRECT = TSPI_PROC_BASE + 42;

        public const uint TSPI_LINEREMOVEFROMCONFERENCE = TSPI_PROC_BASE + 43;

        public const uint TSPI_LINESECURECALL = TSPI_PROC_BASE + 44;

        public const uint TSPI_LINESELECTEXTVERSION = TSPI_PROC_BASE + 45;

        public const uint TSPI_LINESENDUSERUSERINFO = TSPI_PROC_BASE + 46;

        public const uint TSPI_LINESETAPPSPECIFIC = TSPI_PROC_BASE + 47;

        public const uint TSPI_LINESETCALLPARAMS = TSPI_PROC_BASE + 48;

        public const uint TSPI_LINESETDEFAULTMEDIADETECTION = TSPI_PROC_BASE + 49;

        public const uint TSPI_LINESETDEVCONFIG = TSPI_PROC_BASE + 50;

        public const uint TSPI_LINESETMEDIACONTROL = TSPI_PROC_BASE + 51;

        public const uint TSPI_LINESETMEDIAMODE = TSPI_PROC_BASE + 52;

        public const uint TSPI_LINESETSTATUSMESSAGES = TSPI_PROC_BASE + 53;

        public const uint TSPI_LINESETTERMINAL = TSPI_PROC_BASE + 54;

        public const uint TSPI_LINESETUPCONFERENCE = TSPI_PROC_BASE + 55;

        public const uint TSPI_LINESETUPTRANSFER = TSPI_PROC_BASE + 56;

        public const uint TSPI_LINESWAPHOLD = TSPI_PROC_BASE + 57;

        public const uint TSPI_LINEUNCOMPLETECALL = TSPI_PROC_BASE + 58;

        public const uint TSPI_LINEUNHOLD = TSPI_PROC_BASE + 59;

        public const uint TSPI_LINEUNPARK = TSPI_PROC_BASE + 60;

        public const uint TSPI_PHONECLOSE = TSPI_PROC_BASE + 61;

        public const uint TSPI_PHONECONFIGDIALOG = TSPI_PROC_BASE + 62;

        public const uint TSPI_PHONEDEVSPECIFIC = TSPI_PROC_BASE + 63;

        public const uint TSPI_PHONEGETBUTTONINFO = TSPI_PROC_BASE + 64;

        public const uint TSPI_PHONEGETDATA = TSPI_PROC_BASE + 65;

        public const uint TSPI_PHONEGETDEVCAPS = TSPI_PROC_BASE + 66;

        public const uint TSPI_PHONEGETDISPLAY = TSPI_PROC_BASE + 67;

        public const uint TSPI_PHONEGETEXTENSIONID = TSPI_PROC_BASE + 68;

        public const uint TSPI_PHONEGETGAIN = TSPI_PROC_BASE + 69;

        public const uint TSPI_PHONEGETHOOKSWITCH = TSPI_PROC_BASE + 70;

        public const uint TSPI_PHONEGETICON = TSPI_PROC_BASE + 71;

        public const uint TSPI_PHONEGETID = TSPI_PROC_BASE + 72;

        public const uint TSPI_PHONEGETLAMP = TSPI_PROC_BASE + 73;

        public const uint TSPI_PHONEGETRING = TSPI_PROC_BASE + 74;

        public const uint TSPI_PHONEGETSTATUS = TSPI_PROC_BASE + 75;

        public const uint TSPI_PHONEGETVOLUME = TSPI_PROC_BASE + 76;

        public const uint TSPI_PHONENEGOTIATEEXTVERSION = TSPI_PROC_BASE + 77;

        public const uint TSPI_PHONENEGOTIATETSPIVERSION = TSPI_PROC_BASE + 78;

        public const uint TSPI_PHONEOPEN = TSPI_PROC_BASE + 79;

        public const uint TSPI_PHONESELECTEXTVERSION = TSPI_PROC_BASE + 80;

        public const uint TSPI_PHONESETBUTTONINFO = TSPI_PROC_BASE + 81;

        public const uint TSPI_PHONESETDATA = TSPI_PROC_BASE + 82;

        public const uint TSPI_PHONESETDISPLAY = TSPI_PROC_BASE + 83;

        public const uint TSPI_PHONESETGAIN = TSPI_PROC_BASE + 84;

        public const uint TSPI_PHONESETHOOKSWITCH = TSPI_PROC_BASE + 85;

        public const uint TSPI_PHONESETLAMP = TSPI_PROC_BASE + 86;

        public const uint TSPI_PHONESETRING = TSPI_PROC_BASE + 87;

        public const uint TSPI_PHONESETSTATUSMESSAGES = TSPI_PROC_BASE + 88;

        public const uint TSPI_PHONESETVOLUME = TSPI_PROC_BASE + 89;

        public const uint TSPI_PROVIDERCONFIG = TSPI_PROC_BASE + 90;

        public const uint TSPI_PROVIDERINIT = TSPI_PROC_BASE + 91;

        public const uint TSPI_PROVIDERINSTALL = TSPI_PROC_BASE + 92;

        public const uint TSPI_PROVIDERREMOVE = TSPI_PROC_BASE + 93;

        public const uint TSPI_PROVIDERSHUTDOWN = TSPI_PROC_BASE + 94;

        public const uint TSPI_PROVIDERENUMDEVICES = TSPI_PROC_BASE + 95;

        public const uint TSPI_LINEDROPONCLOSE = TSPI_PROC_BASE + 96;

        public const uint TSPI_LINEDROPNOOWNER = TSPI_PROC_BASE + 97;

        public const uint TSPI_PROVIDERCREATELINEDEVICE = TSPI_PROC_BASE + 98;

        public const uint TSPI_PROVIDERCREATEPHONEDEVICE = TSPI_PROC_BASE + 99;

        public const uint TSPI_LINESETCURRENTLOCATION = TSPI_PROC_BASE + 100;

        public const uint TSPI_LINECONFIGDIALOGEDIT = TSPI_PROC_BASE + 101;

        public const uint TSPI_LINERELEASEUSERUSERINFO = TSPI_PROC_BASE + 102;

        public const uint TSPI_LINEGETCALLID = TSPI_PROC_BASE + 103;

        public const uint TSPI_LINEGETCALLHUBTRACKING = TSPI_PROC_BASE + 104;

        public const uint TSPI_LINESETCALLHUBTRACKING = TSPI_PROC_BASE + 105;

        public const uint TSPI_LINERECEIVEMSPDATA = TSPI_PROC_BASE + 106;

        public const uint TSPI_LINEMSPIDENTIFY = TSPI_PROC_BASE + 107;

        public const uint TSPI_LINECREATEMSPINSTANCE = TSPI_PROC_BASE + 108;

        public const uint TSPI_LINECLOSEMSPINSTANCE = TSPI_PROC_BASE + 109;

        public const uint IDISPDIROBJECT = 0x10000;

        public const uint IDISPDIROBJCONFERENCE = 0x20000;

        public const uint IDISPDIROBJUSER = 0x30000;

        public const uint IDISPDIRECTORY = 0x10000;

        public const uint IDISPILSCONFIG = 0x20000;

        public const uint RENDBIND_AUTHENTICATE = 0x00000001;

        public const uint RENDBIND_DEFAULTDOMAINNAME = 0x00000002;

        public const uint RENDBIND_DEFAULTUSERNAME = 0x00000004;

        public const uint RENDBIND_DEFAULTPASSWORD = 0x00000008;

        public const uint RENDBIND_DEFAULTCREDENTIALS = 0x0000000e;

        public const uint STRM_INITIAL = 0x00000000;

        public const uint STRM_TERMINALSELECTED = 0x00000001;

        public const uint STRM_CONFIGURED = 0x00000002;

        public const uint STRM_RUNNING = 0x00000004;

        public const uint STRM_PAUSED = 0x00000008;

        public const uint STRM_STOPPED = 0x00000010;

    }
}

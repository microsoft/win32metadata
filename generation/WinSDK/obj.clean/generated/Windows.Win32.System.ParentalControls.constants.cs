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


namespace Windows.Win32.System.ParentalControls
{
    public static partial class Apis
    {
        public const uint ARRAY_SEP_CHAR = 0x9;

        public const uint WPCCHANNEL = 0x10;

        public const uint WPC_SETTINGS_LOCATE = 0x14;

        public const uint WPC_SETTINGS_MODIFY = 0x15;

        public const uint WPC_APP_LAUNCH = 0x16;

        public const uint WPC_SYSTEM = 0x17;

        public const uint WPC_WEB = 0x18;

        public const uint WPCPROV_TASK_SettingChange = 0x1;

        public const uint WPCPROV_TASK_GameStart = 0x2;

        public const uint WPCPROV_TASK_UrlVisit = 0x3;

        public const uint WPCPROV_TASK_EmailReceived = 0x4;

        public const uint WPCPROV_TASK_EmailSent = 0x5;

        public const uint WPCPROV_TASK_MediaPlayback = 0x6;

        public const uint WPCPROV_TASK_IMInvitation = 0x7;

        public const uint WPCPROV_TASK_IMJoin = 0x8;

        public const uint WPCPROV_TASK_IMLeave = 0x9;

        public const uint WPCPROV_TASK_FileDownload = 0xa;

        public const uint WPCPROV_TASK_IMFeature = 0xb;

        public const uint WPCPROV_TASK_Custom = 0xd;

        public const uint WPCPROV_TASK_EmailContact = 0xe;

        public const uint WPCPROV_TASK_IMContact = 0xf;

        public const uint WPCPROV_TASK_AppBlocked = 0x10;

        public const uint WPCPROV_TASK_AppOverride = 0x11;

        public const uint WPCPROV_TASK_WebOverride = 0x12;

        public const uint WPCPROV_TASK_WebsiteVisit = 0x13;

        public const uint WPCPROV_TASK_Application = 0x14;

        public const uint WPCPROV_TASK_ComputerUsage = 0x15;

        public const uint WPCPROV_TASK_ContentUsage = 0x16;

        public const uint WPCPROV_KEYWORD_WPC = 0x10;

        public const uint WPCPROV_KEYWORD_ThirdParty = 0x20;

        public const uint WPCEVENT_SYS_SETTINGCHANGE_value = 0x1;

        public const uint WPCEVENT_GAME_START_value = 0x2;

        public const uint WPCEVENT_WEB_URLVISIT_value = 0x3;

        public const uint WPCEVENT_EMAIL_RECEIVED_value = 0x4;

        public const uint WPCEVENT_EMAIL_SENT_value = 0x5;

        public const uint WPCEVENT_MEDIA_PLAYBACK_value = 0x6;

        public const uint WPCEVENT_IM_INVITATION_value = 0x7;

        public const uint WPCEVENT_IM_JOIN_value = 0x8;

        public const uint WPCEVENT_IM_LEAVE_value = 0x9;

        public const uint WPCEVENT_WEB_FILEDOWNLOAD_value = 0xa;

        public const uint WPCEVENT_IM_FEATURE_value = 0xb;

        public const uint WPCEVENT_CUSTOM_value = 0xd;

        public const uint WPCEVENT_EMAIL_CONTACT_value = 0xe;

        public const uint WPCEVENT_IM_CONTACT_value = 0xf;

        public const uint WPCEVENT_SYSTEM_APPBLOCKED_value = 0x10;

        public const uint WPCEVENT_APPOVERRIDE_value = 0x11;

        public const uint WPCEVENT_WEBOVERRIDE_value = 0x12;

        public const uint WPCEVENT_WEB_WEBSITEVISIT_value = 0x13;

        public const uint WPCEVENT_APPLICATION_value = 0x14;

        public const uint WPCEVENT_COMPUTERUSAGE_value = 0x15;

        public const uint WPCEVENT_CONTENTUSAGE_value = 0x16;

        public const int MSG_Keyword_WPC = 0x10000005;

        public const int MSG_Keyword_ThirdParty = 0x10000006;

        public const int MSG_Opcode_Locate = 0x30000014;

        public const int MSG_Opcode_Modify = 0x30000015;

        public const int MSG_Opcode_Launch = 0x30000016;

        public const int MSG_Opcode_System = 0x30000017;

        public const int MSG_Opcode_Web = 0x30000018;

        public const int MSG_Task_SettingChange = 0x70000001;

        public const int MSG_Task_GameStart = 0x70000002;

        public const int MSG_Task_UrlVisit = 0x70000003;

        public const int MSG_Task_EmailReceived = 0x70000004;

        public const int MSG_Task_EmailSent = 0x70000005;

        public const int MSG_Task_MediaPlayback = 0x70000006;

        public const int MSG_Task_IMInvitation = 0x70000007;

        public const int MSG_Task_IMJoin = 0x70000008;

        public const int MSG_Task_IMLeave = 0x70000009;

        public const int MSG_Task_FileDownload = 0x7000000A;

        public const int MSG_Task_IMFeature = 0x7000000B;

        public const int MSG_Task_Custom = 0x7000000D;

        public const int MSG_Task_EmailContact = 0x7000000E;

        public const int MSG_Task_IMContact = 0x7000000F;

        public const int MSG_Task_AppBlocked = 0x70000010;

        public const int MSG_Task_AppOverride = 0x70000011;

        public const int MSG_Task_WebOverride = 0x70000012;

        public const int MSG_Task_WebsiteVisit = 0x70000013;

        public const int MSG_Task_Application = 0x70000014;

        public const int MSG_Task_ComputerUsage = 0x70000015;

        public const int MSG_Task_ContentUsage = 0x70000016;

        public const int MSG_Publisher_Name = unchecked((int)0x90000001);

        public const int MSG_Event_SettingChange = unchecked((int)0xB0000001);

        public const int MSG_Event_GameStart = unchecked((int)0xB0000002);

        public const int MSG_Event_UrlVisit = unchecked((int)0xB0000003);

        public const int MSG_Event_EmailReceived = unchecked((int)0xB0000004);

        public const int MSG_Event_EmailSent = unchecked((int)0xB0000005);

        public const int MSG_Event_MediaPlayback = unchecked((int)0xB0000006);

        public const int MSG_Event_IMInvitation = unchecked((int)0xB0000007);

        public const int MSG_Event_IMJoin = unchecked((int)0xB0000008);

        public const int MSG_Event_IMLeave = unchecked((int)0xB0000009);

        public const int MSG_Event_FileDownload = unchecked((int)0xB000000A);

        public const int MSG_Event_IMFeature = unchecked((int)0xB000000B);

        public const int MSG_Event_Custom = unchecked((int)0xB000000D);

        public const int MSG_Event_EmailContact = unchecked((int)0xB000000E);

        public const int MSG_Event_IMContact = unchecked((int)0xB000000F);

        public const int MSG_Event_AppBlocked = unchecked((int)0xB0000010);

        public const int MSG_Event_AppOverride = unchecked((int)0xB0000011);

        public const int MSG_Event_WebOverride = unchecked((int)0xB0000012);

        public const int MSG_Event_WebsiteVisit = unchecked((int)0xB0000013);

        public const int MSG_Event_Application = unchecked((int)0xB0000014);

        public const int MSG_Event_ComputerUsage = unchecked((int)0xB0000015);

        public const int MSG_Event_ContentUsage = unchecked((int)0xB0000016);

    }
}

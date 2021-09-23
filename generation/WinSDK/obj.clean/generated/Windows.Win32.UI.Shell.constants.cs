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


namespace Windows.Win32.UI.Shell
{
    public static partial class Apis
    {
        public const uint WM_CPL_LAUNCH = WM_USER+1000;

        public const uint WM_CPL_LAUNCHED = WM_USER+1001;

        public const uint CPL_DYNAMIC_RES = 0;

        public const uint CPL_INIT = 1;

        public const uint CPL_GETCOUNT = 2;

        public const uint CPL_INQUIRE = 3;

        public const uint CPL_SELECT = 4;

        public const uint CPL_DBLCLK = 5;

        public const uint CPL_STOP = 6;

        public const uint CPL_EXIT = 7;

        public const uint CPL_NEWINQUIRE = 8;

        public const uint CPL_STARTWPARMSA = 9;

        public const uint CPL_STARTWPARMSW = 10;

        public const uint CPL_SETUP = 200;

        public const uint PERCEIVEDFLAG_UNDEFINED = 0x0000;

        public const uint PERCEIVEDFLAG_SOFTCODED = 0x0001;

        public const uint PERCEIVEDFLAG_HARDCODED = 0x0002;

        public const uint PERCEIVEDFLAG_NATIVESUPPORT = 0x0004;

        public const uint PERCEIVEDFLAG_GDIPLUS = 0x0010;

        public const uint PERCEIVEDFLAG_WMSDK = 0x0020;

        public const uint PERCEIVEDFLAG_ZIPFOLDER = 0x0040;

        public static readonly Guid FOLDERID_NetworkFolder__scanned__ = new Guid(0xD20BEEC4, 0x5CA8, 0x4905, 0xAE, 0x3B, 0xBF, 0x25, 0x1E, 0xA0, 0x9B, 0x53);

        public static readonly Guid FOLDERID_ComputerFolder__scanned__ = new Guid(0x0AC0837C, 0xBBF8, 0x452A, 0x85, 0x0D, 0x79, 0xD0, 0x8E, 0x66, 0x7C, 0xA7);

        public static readonly Guid FOLDERID_InternetFolder__scanned__ = new Guid(0x4D9F7874, 0x4E0C, 0x4904, 0x96, 0x7B, 0x40, 0xB0, 0xD2, 0x0C, 0x3E, 0x4B);

        public static readonly Guid FOLDERID_ControlPanelFolder__scanned__ = new Guid(0x82A74AEB, 0xAEB4, 0x465C, 0xA0, 0x14, 0xD0, 0x97, 0xEE, 0x34, 0x6D, 0x63);

        public static readonly Guid FOLDERID_PrintersFolder__scanned__ = new Guid(0x76FC4E2D, 0xD6AD, 0x4519, 0xA6, 0x63, 0x37, 0xBD, 0x56, 0x06, 0x81, 0x85);

        public static readonly Guid FOLDERID_SyncManagerFolder__scanned__ = new Guid(0x43668BF8, 0xC14E, 0x49B2, 0x97, 0xC9, 0x74, 0x77, 0x84, 0xD7, 0x84, 0xB7);

        public static readonly Guid FOLDERID_SyncSetupFolder__scanned__ = new Guid(0xf214138, 0xb1d3, 0x4a90, 0xbb, 0xa9, 0x27, 0xcb, 0xc0, 0xc5, 0x38, 0x9a);

        public static readonly Guid FOLDERID_ConflictFolder__scanned__ = new Guid(0x4bfefb45, 0x347d, 0x4006, 0xa5, 0xbe, 0xac, 0x0c, 0xb0, 0x56, 0x71, 0x92);

        public static readonly Guid FOLDERID_SyncResultsFolder__scanned__ = new Guid(0x289a9a43, 0xbe44, 0x4057, 0xa4, 0x1b, 0x58, 0x7a, 0x76, 0xd7, 0xe7, 0xf9);

        public static readonly Guid FOLDERID_RecycleBinFolder__scanned__ = new Guid(0xB7534046, 0x3ECB, 0x4C18, 0xBE, 0x4E, 0x64, 0xCD, 0x4C, 0xB7, 0xD6, 0xAC);

        public static readonly Guid FOLDERID_ConnectionsFolder__scanned__ = new Guid(0x6F0CD92B, 0x2E97, 0x45D1, 0x88, 0xFF, 0xB0, 0xD1, 0x86, 0xB8, 0xDE, 0xDD);

        public static readonly Guid FOLDERID_Fonts__scanned__ = new Guid(0xFD228CB7, 0xAE11, 0x4AE3, 0x86, 0x4C, 0x16, 0xF3, 0x91, 0x0A, 0xB8, 0xFE);

        public static readonly Guid FOLDERID_Desktop__scanned__ = new Guid(0xB4BFCC3A, 0xDB2C, 0x424C, 0xB0, 0x29, 0x7F, 0xE9, 0x9A, 0x87, 0xC6, 0x41);

        public static readonly Guid FOLDERID_Startup__scanned__ = new Guid(0xB97D20BB, 0xF46A, 0x4C97, 0xBA, 0x10, 0x5E, 0x36, 0x08, 0x43, 0x08, 0x54);

        public static readonly Guid FOLDERID_Programs__scanned__ = new Guid(0xA77F5D77, 0x2E2B, 0x44C3, 0xA6, 0xA2, 0xAB, 0xA6, 0x01, 0x05, 0x4A, 0x51);

        public static readonly Guid FOLDERID_StartMenu__scanned__ = new Guid(0x625B53C3, 0xAB48, 0x4EC1, 0xBA, 0x1F, 0xA1, 0xEF, 0x41, 0x46, 0xFC, 0x19);

        public static readonly Guid FOLDERID_Recent__scanned__ = new Guid(0xAE50C081, 0xEBD2, 0x438A, 0x86, 0x55, 0x8A, 0x09, 0x2E, 0x34, 0x98, 0x7A);

        public static readonly Guid FOLDERID_SendTo__scanned__ = new Guid(0x8983036C, 0x27C0, 0x404B, 0x8F, 0x08, 0x10, 0x2D, 0x10, 0xDC, 0xFD, 0x74);

        public static readonly Guid FOLDERID_Documents__scanned__ = new Guid(0xFDD39AD0, 0x238F, 0x46AF, 0xAD, 0xB4, 0x6C, 0x85, 0x48, 0x03, 0x69, 0xC7);

        public static readonly Guid FOLDERID_Favorites__scanned__ = new Guid(0x1777F761, 0x68AD, 0x4D8A, 0x87, 0xBD, 0x30, 0xB7, 0x59, 0xFA, 0x33, 0xDD);

        public static readonly Guid FOLDERID_NetHood__scanned__ = new Guid(0xC5ABBF53, 0xE17F, 0x4121, 0x89, 0x00, 0x86, 0x62, 0x6F, 0xC2, 0xC9, 0x73);

        public static readonly Guid FOLDERID_PrintHood__scanned__ = new Guid(0x9274BD8D, 0xCFD1, 0x41C3, 0xB3, 0x5E, 0xB1, 0x3F, 0x55, 0xA7, 0x58, 0xF4);

        public static readonly Guid FOLDERID_Templates__scanned__ = new Guid(0xA63293E8, 0x664E, 0x48DB, 0xA0, 0x79, 0xDF, 0x75, 0x9E, 0x05, 0x09, 0xF7);

        public static readonly Guid FOLDERID_CommonStartup__scanned__ = new Guid(0x82A5EA35, 0xD9CD, 0x47C5, 0x96, 0x29, 0xE1, 0x5D, 0x2F, 0x71, 0x4E, 0x6E);

        public static readonly Guid FOLDERID_CommonPrograms__scanned__ = new Guid(0x0139D44E, 0x6AFE, 0x49F2, 0x86, 0x90, 0x3D, 0xAF, 0xCA, 0xE6, 0xFF, 0xB8);

        public static readonly Guid FOLDERID_CommonStartMenu__scanned__ = new Guid(0xA4115719, 0xD62E, 0x491D, 0xAA, 0x7C, 0xE7, 0x4B, 0x8B, 0xE3, 0xB0, 0x67);

        public static readonly Guid FOLDERID_PublicDesktop__scanned__ = new Guid(0xC4AA340D, 0xF20F, 0x4863, 0xAF, 0xEF, 0xF8, 0x7E, 0xF2, 0xE6, 0xBA, 0x25);

        public static readonly Guid FOLDERID_ProgramData__scanned__ = new Guid(0x62AB5D82, 0xFDC1, 0x4DC3, 0xA9, 0xDD, 0x07, 0x0D, 0x1D, 0x49, 0x5D, 0x97);

        public static readonly Guid FOLDERID_CommonTemplates__scanned__ = new Guid(0xB94237E7, 0x57AC, 0x4347, 0x91, 0x51, 0xB0, 0x8C, 0x6C, 0x32, 0xD1, 0xF7);

        public static readonly Guid FOLDERID_PublicDocuments__scanned__ = new Guid(0xED4824AF, 0xDCE4, 0x45A8, 0x81, 0xE2, 0xFC, 0x79, 0x65, 0x08, 0x36, 0x34);

        public static readonly Guid FOLDERID_RoamingAppData__scanned__ = new Guid(0x3EB685DB, 0x65F9, 0x4CF6, 0xA0, 0x3A, 0xE3, 0xEF, 0x65, 0x72, 0x9F, 0x3D);

        public static readonly Guid FOLDERID_LocalAppData__scanned__ = new Guid(0xF1B32785, 0x6FBA, 0x4FCF, 0x9D, 0x55, 0x7B, 0x8E, 0x7F, 0x15, 0x70, 0x91);

        public static readonly Guid FOLDERID_LocalAppDataLow__scanned__ = new Guid(0xA520A1A4, 0x1780, 0x4FF6, 0xBD, 0x18, 0x16, 0x73, 0x43, 0xC5, 0xAF, 0x16);

        public static readonly Guid FOLDERID_InternetCache__scanned__ = new Guid(0x352481E8, 0x33BE, 0x4251, 0xBA, 0x85, 0x60, 0x07, 0xCA, 0xED, 0xCF, 0x9D);

        public static readonly Guid FOLDERID_Cookies__scanned__ = new Guid(0x2B0F765D, 0xC0E9, 0x4171, 0x90, 0x8E, 0x08, 0xA6, 0x11, 0xB8, 0x4F, 0xF6);

        public static readonly Guid FOLDERID_History__scanned__ = new Guid(0xD9DC8A3B, 0xB784, 0x432E, 0xA7, 0x81, 0x5A, 0x11, 0x30, 0xA7, 0x59, 0x63);

        public static readonly Guid FOLDERID_System__scanned__ = new Guid(0x1AC14E77, 0x02E7, 0x4E5D, 0xB7, 0x44, 0x2E, 0xB1, 0xAE, 0x51, 0x98, 0xB7);

        public static readonly Guid FOLDERID_SystemX86__scanned__ = new Guid(0xD65231B0, 0xB2F1, 0x4857, 0xA4, 0xCE, 0xA8, 0xE7, 0xC6, 0xEA, 0x7D, 0x27);

        public static readonly Guid FOLDERID_Windows__scanned__ = new Guid(0xF38BF404, 0x1D43, 0x42F2, 0x93, 0x05, 0x67, 0xDE, 0x0B, 0x28, 0xFC, 0x23);

        public static readonly Guid FOLDERID_Profile__scanned__ = new Guid(0x5E6C858F, 0x0E22, 0x4760, 0x9A, 0xFE, 0xEA, 0x33, 0x17, 0xB6, 0x71, 0x73);

        public static readonly Guid FOLDERID_Pictures__scanned__ = new Guid(0x33E28130, 0x4E1E, 0x4676, 0x83, 0x5A, 0x98, 0x39, 0x5C, 0x3B, 0xC3, 0xBB);

        public static readonly Guid FOLDERID_ProgramFilesX86__scanned__ = new Guid(0x7C5A40EF, 0xA0FB, 0x4BFC, 0x87, 0x4A, 0xC0, 0xF2, 0xE0, 0xB9, 0xFA, 0x8E);

        public static readonly Guid FOLDERID_ProgramFilesCommonX86__scanned__ = new Guid(0xDE974D24, 0xD9C6, 0x4D3E, 0xBF, 0x91, 0xF4, 0x45, 0x51, 0x20, 0xB9, 0x17);

        public static readonly Guid FOLDERID_ProgramFilesX64__scanned__ = new Guid(0x6d809377, 0x6af0, 0x444b, 0x89, 0x57, 0xa3, 0x77, 0x3f, 0x02, 0x20, 0x0e );

        public static readonly Guid FOLDERID_ProgramFilesCommonX64__scanned__ = new Guid(0x6365d5a7, 0xf0d, 0x45e5, 0x87, 0xf6, 0xd, 0xa5, 0x6b, 0x6a, 0x4f, 0x7d );

        public static readonly Guid FOLDERID_ProgramFiles__scanned__ = new Guid(0x905e63b6, 0xc1bf, 0x494e, 0xb2, 0x9c, 0x65, 0xb7, 0x32, 0xd3, 0xd2, 0x1a);

        public static readonly Guid FOLDERID_ProgramFilesCommon__scanned__ = new Guid(0xF7F1ED05, 0x9F6D, 0x47A2, 0xAA, 0xAE, 0x29, 0xD3, 0x17, 0xC6, 0xF0, 0x66);

        public static readonly Guid FOLDERID_UserProgramFiles__scanned__ = new Guid(0x5cd7aee2, 0x2219, 0x4a67, 0xb8, 0x5d, 0x6c, 0x9c, 0xe1, 0x56, 0x60, 0xcb);

        public static readonly Guid FOLDERID_UserProgramFilesCommon__scanned__ = new Guid(0xbcbd3057, 0xca5c, 0x4622, 0xb4, 0x2d, 0xbc, 0x56, 0xdb, 0x0a, 0xe5, 0x16);

        public static readonly Guid FOLDERID_AdminTools__scanned__ = new Guid(0x724EF170, 0xA42D, 0x4FEF, 0x9F, 0x26, 0xB6, 0x0E, 0x84, 0x6F, 0xBA, 0x4F);

        public static readonly Guid FOLDERID_CommonAdminTools__scanned__ = new Guid(0xD0384E7D, 0xBAC3, 0x4797, 0x8F, 0x14, 0xCB, 0xA2, 0x29, 0xB3, 0x92, 0xB5);

        public static readonly Guid FOLDERID_Music__scanned__ = new Guid(0x4BD8D571, 0x6D19, 0x48D3, 0xBE, 0x97, 0x42, 0x22, 0x20, 0x08, 0x0E, 0x43);

        public static readonly Guid FOLDERID_Videos__scanned__ = new Guid(0x18989B1D, 0x99B5, 0x455B, 0x84, 0x1C, 0xAB, 0x7C, 0x74, 0xE4, 0xDD, 0xFC);

        public static readonly Guid FOLDERID_Ringtones__scanned__ = new Guid(0xC870044B, 0xF49E, 0x4126, 0xA9, 0xC3, 0xB5, 0x2A, 0x1F, 0xF4, 0x11, 0xE8);

        public static readonly Guid FOLDERID_PublicPictures__scanned__ = new Guid(0xB6EBFB86, 0x6907, 0x413C, 0x9A, 0xF7, 0x4F, 0xC2, 0xAB, 0xF0, 0x7C, 0xC5);

        public static readonly Guid FOLDERID_PublicMusic__scanned__ = new Guid(0x3214FAB5, 0x9757, 0x4298, 0xBB, 0x61, 0x92, 0xA9, 0xDE, 0xAA, 0x44, 0xFF);

        public static readonly Guid FOLDERID_PublicVideos__scanned__ = new Guid(0x2400183A, 0x6185, 0x49FB, 0xA2, 0xD8, 0x4A, 0x39, 0x2A, 0x60, 0x2B, 0xA3);

        public static readonly Guid FOLDERID_PublicRingtones__scanned__ = new Guid(0xE555AB60, 0x153B, 0x4D17, 0x9F, 0x04, 0xA5, 0xFE, 0x99, 0xFC, 0x15, 0xEC);

        public static readonly Guid FOLDERID_ResourceDir__scanned__ = new Guid(0x8AD10C31, 0x2ADB, 0x4296, 0xA8, 0xF7, 0xE4, 0x70, 0x12, 0x32, 0xC9, 0x72);

        public static readonly Guid FOLDERID_LocalizedResourcesDir__scanned__ = new Guid(0x2A00375E, 0x224C, 0x49DE, 0xB8, 0xD1, 0x44, 0x0D, 0xF7, 0xEF, 0x3D, 0xDC);

        public static readonly Guid FOLDERID_CommonOEMLinks__scanned__ = new Guid(0xC1BAE2D0, 0x10DF, 0x4334, 0xBE, 0xDD, 0x7A, 0xA2, 0x0B, 0x22, 0x7A, 0x9D);

        public static readonly Guid FOLDERID_CDBurning__scanned__ = new Guid(0x9E52AB10, 0xF80D, 0x49DF, 0xAC, 0xB8, 0x43, 0x30, 0xF5, 0x68, 0x78, 0x55);

        public static readonly Guid FOLDERID_UserProfiles__scanned__ = new Guid(0x0762D272, 0xC50A, 0x4BB0, 0xA3, 0x82, 0x69, 0x7D, 0xCD, 0x72, 0x9B, 0x80);

        public static readonly Guid FOLDERID_Playlists__scanned__ = new Guid(0xDE92C1C7, 0x837F, 0x4F69, 0xA3, 0xBB, 0x86, 0xE6, 0x31, 0x20, 0x4A, 0x23);

        public static readonly Guid FOLDERID_SamplePlaylists__scanned__ = new Guid(0x15CA69B3, 0x30EE, 0x49C1, 0xAC, 0xE1, 0x6B, 0x5E, 0xC3, 0x72, 0xAF, 0xB5);

        public static readonly Guid FOLDERID_SampleMusic__scanned__ = new Guid(0xB250C668, 0xF57D, 0x4EE1, 0xA6, 0x3C, 0x29, 0x0E, 0xE7, 0xD1, 0xAA, 0x1F);

        public static readonly Guid FOLDERID_SamplePictures__scanned__ = new Guid(0xC4900540, 0x2379, 0x4C75, 0x84, 0x4B, 0x64, 0xE6, 0xFA, 0xF8, 0x71, 0x6B);

        public static readonly Guid FOLDERID_SampleVideos__scanned__ = new Guid(0x859EAD94, 0x2E85, 0x48AD, 0xA7, 0x1A, 0x09, 0x69, 0xCB, 0x56, 0xA6, 0xCD);

        public static readonly Guid FOLDERID_PhotoAlbums__scanned__ = new Guid(0x69D2CF90, 0xFC33, 0x4FB7, 0x9A, 0x0C, 0xEB, 0xB0, 0xF0, 0xFC, 0xB4, 0x3C);

        public static readonly Guid FOLDERID_Public__scanned__ = new Guid(0xDFDF76A2, 0xC82A, 0x4D63, 0x90, 0x6A, 0x56, 0x44, 0xAC, 0x45, 0x73, 0x85);

        public static readonly Guid FOLDERID_ChangeRemovePrograms__scanned__ = new Guid(0xdf7266ac, 0x9274, 0x4867, 0x8d, 0x55, 0x3b, 0xd6, 0x61, 0xde, 0x87, 0x2d);

        public static readonly Guid FOLDERID_AppUpdates__scanned__ = new Guid(0xa305ce99, 0xf527, 0x492b, 0x8b, 0x1a, 0x7e, 0x76, 0xfa, 0x98, 0xd6, 0xe4);

        public static readonly Guid FOLDERID_AddNewPrograms__scanned__ = new Guid(0xde61d971, 0x5ebc, 0x4f02, 0xa3, 0xa9, 0x6c, 0x82, 0x89, 0x5e, 0x5c, 0x04);

        public static readonly Guid FOLDERID_Downloads__scanned__ = new Guid(0x374de290, 0x123f, 0x4565, 0x91, 0x64, 0x39, 0xc4, 0x92, 0x5e, 0x46, 0x7b);

        public static readonly Guid FOLDERID_PublicDownloads__scanned__ = new Guid(0x3d644c9b, 0x1fb8, 0x4f30, 0x9b, 0x45, 0xf6, 0x70, 0x23, 0x5f, 0x79, 0xc0);

        public static readonly Guid FOLDERID_SavedSearches__scanned__ = new Guid(0x7d1d3a04, 0xdebb, 0x4115, 0x95, 0xcf, 0x2f, 0x29, 0xda, 0x29, 0x20, 0xda);

        public static readonly Guid FOLDERID_QuickLaunch__scanned__ = new Guid(0x52a4f021, 0x7b75, 0x48a9, 0x9f, 0x6b, 0x4b, 0x87, 0xa2, 0x10, 0xbc, 0x8f);

        public static readonly Guid FOLDERID_Contacts__scanned__ = new Guid(0x56784854, 0xc6cb, 0x462b, 0x81, 0x69, 0x88, 0xe3, 0x50, 0xac, 0xb8, 0x82);

        public static readonly Guid FOLDERID_SidebarParts__scanned__ = new Guid(0xa75d362e, 0x50fc, 0x4fb7, 0xac, 0x2c, 0xa8, 0xbe, 0xaa, 0x31, 0x44, 0x93);

        public static readonly Guid FOLDERID_SidebarDefaultParts__scanned__ = new Guid(0x7b396e54, 0x9ec5, 0x4300, 0xbe, 0xa, 0x24, 0x82, 0xeb, 0xae, 0x1a, 0x26);

        public static readonly Guid FOLDERID_PublicGameTasks__scanned__ = new Guid(0xdebf2536, 0xe1a8, 0x4c59, 0xb6, 0xa2, 0x41, 0x45, 0x86, 0x47, 0x6a, 0xea);

        public static readonly Guid FOLDERID_GameTasks__scanned__ = new Guid(0x54fae61, 0x4dd8, 0x4787, 0x80, 0xb6, 0x9, 0x2, 0x20, 0xc4, 0xb7, 0x0);

        public static readonly Guid FOLDERID_SavedGames__scanned__ = new Guid(0x4c5c32ff, 0xbb9d, 0x43b0, 0xb5, 0xb4, 0x2d, 0x72, 0xe5, 0x4e, 0xaa, 0xa4);

        public static readonly Guid FOLDERID_Games__scanned__ = new Guid(0xcac52c1a, 0xb53d, 0x4edc, 0x92, 0xd7, 0x6b, 0x2e, 0x8a, 0xc1, 0x94, 0x34);

        public static readonly Guid FOLDERID_SEARCH_MAPI__scanned__ = new Guid(0x98ec0e18, 0x2098, 0x4d44, 0x86, 0x44, 0x66, 0x97, 0x93, 0x15, 0xa2, 0x81);

        public static readonly Guid FOLDERID_SEARCH_CSC__scanned__ = new Guid(0xee32e446, 0x31ca, 0x4aba, 0x81, 0x4f, 0xa5, 0xeb, 0xd2, 0xfd, 0x6d, 0x5e);

        public static readonly Guid FOLDERID_Links__scanned__ = new Guid(0xbfb9d5e0, 0xc6a9, 0x404c, 0xb2, 0xb2, 0xae, 0x6d, 0xb6, 0xaf, 0x49, 0x68);

        public static readonly Guid FOLDERID_UsersFiles__scanned__ = new Guid(0xf3ce0f7c, 0x4901, 0x4acc, 0x86, 0x48, 0xd5, 0xd4, 0x4b, 0x04, 0xef, 0x8f);

        public static readonly Guid FOLDERID_UsersLibraries__scanned__ = new Guid(0xa302545d, 0xdeff, 0x464b, 0xab, 0xe8, 0x61, 0xc8, 0x64, 0x8d, 0x93, 0x9b);

        public static readonly Guid FOLDERID_SearchHome__scanned__ = new Guid(0x190337d1, 0xb8ca, 0x4121, 0xa6, 0x39, 0x6d, 0x47, 0x2d, 0x16, 0x97, 0x2a);

        public static readonly Guid FOLDERID_OriginalImages__scanned__ = new Guid(0x2C36C0AA, 0x5812, 0x4b87, 0xbf, 0xd0, 0x4c, 0xd0, 0xdf, 0xb1, 0x9b, 0x39);

        public static readonly Guid FOLDERID_DocumentsLibrary__scanned__ = new Guid(0x7b0db17d, 0x9cd2, 0x4a93, 0x97, 0x33, 0x46, 0xcc, 0x89, 0x02, 0x2e, 0x7c);

        public static readonly Guid FOLDERID_MusicLibrary__scanned__ = new Guid(0x2112ab0a, 0xc86a, 0x4ffe, 0xa3, 0x68, 0xd, 0xe9, 0x6e, 0x47, 0x1, 0x2e);

        public static readonly Guid FOLDERID_PicturesLibrary__scanned__ = new Guid(0xa990ae9f, 0xa03b, 0x4e80, 0x94, 0xbc, 0x99, 0x12, 0xd7, 0x50, 0x41, 0x4);

        public static readonly Guid FOLDERID_VideosLibrary__scanned__ = new Guid(0x491e922f, 0x5643, 0x4af4, 0xa7, 0xeb, 0x4e, 0x7a, 0x13, 0x8d, 0x81, 0x74);

        public static readonly Guid FOLDERID_RecordedTVLibrary__scanned__ = new Guid(0x1a6fdba2, 0xf42d, 0x4358, 0xa7, 0x98, 0xb7, 0x4d, 0x74, 0x59, 0x26, 0xc5);

        public static readonly Guid FOLDERID_HomeGroup__scanned__ = new Guid(0x52528a6b, 0xb9e3, 0x4add, 0xb6, 0xd, 0x58, 0x8c, 0x2d, 0xba, 0x84, 0x2d);

        public static readonly Guid FOLDERID_HomeGroupCurrentUser__scanned__ = new Guid(0x9b74b6a3, 0xdfd, 0x4f11, 0x9e, 0x78, 0x5f, 0x78, 0x0, 0xf2, 0xe7, 0x72);

        public static readonly Guid FOLDERID_DeviceMetadataStore__scanned__ = new Guid(0x5ce4a5e9, 0xe4eb, 0x479d, 0xb8, 0x9f, 0x13, 0x0c, 0x02, 0x88, 0x61, 0x55);

        public static readonly Guid FOLDERID_Libraries__scanned__ = new Guid(0x1b3ea5dc, 0xb587, 0x4786, 0xb4, 0xef, 0xbd, 0x1d, 0xc3, 0x32, 0xae, 0xae);

        public static readonly Guid FOLDERID_PublicLibraries__scanned__ = new Guid(0x48daf80b, 0xe6cf, 0x4f4e, 0xb8, 0x00, 0x0e, 0x69, 0xd8, 0x4e, 0xe3, 0x84);

        public static readonly Guid FOLDERID_UserPinned__scanned__ = new Guid(0x9e3995ab, 0x1f9c, 0x4f13, 0xb8, 0x27, 0x48, 0xb2, 0x4b, 0x6c, 0x71, 0x74);

        public static readonly Guid FOLDERID_ImplicitAppShortcuts__scanned__ = new Guid(0xbcb5256f, 0x79f6, 0x4cee, 0xb7, 0x25, 0xdc, 0x34, 0xe4, 0x2, 0xfd, 0x46);

        public static readonly Guid FOLDERID_AccountPictures__scanned__ = new Guid(0x008ca0b1, 0x55b4, 0x4c56, 0xb8, 0xa8, 0x4d, 0xe4, 0xb2, 0x99, 0xd3, 0xbe);

        public static readonly Guid FOLDERID_PublicUserTiles__scanned__ = new Guid(0x0482af6c, 0x08f1, 0x4c34, 0x8c, 0x90, 0xe1, 0x7e, 0xc9, 0x8b, 0x1e, 0x17);

        public static readonly Guid FOLDERID_AppsFolder__scanned__ = new Guid(0x1e87508d, 0x89c2, 0x42f0, 0x8a, 0x7e, 0x64, 0x5a, 0x0f, 0x50, 0xca, 0x58);

        public static readonly Guid FOLDERID_StartMenuAllPrograms__scanned__ = new Guid(0xf26305ef, 0x6948, 0x40b9, 0xb2, 0x55, 0x81, 0x45, 0x3d, 0x9, 0xc7, 0x85);

        public static readonly Guid FOLDERID_CommonStartMenuPlaces__scanned__ = new Guid(0xa440879f, 0x87a0, 0x4f7d, 0xb7, 0x0, 0x2, 0x7, 0xb9, 0x66, 0x19, 0x4a);

        public static readonly Guid FOLDERID_ApplicationShortcuts__scanned__ = new Guid(0xa3918781, 0xe5f2, 0x4890, 0xb3, 0xd9, 0xa7, 0xe5, 0x43, 0x32, 0x32, 0x8c);

        public static readonly Guid FOLDERID_RoamingTiles__scanned__ = new Guid(0xbcfc5a, 0xed94, 0x4e48, 0x96, 0xa1, 0x3f, 0x62, 0x17, 0xf2, 0x19, 0x90);

        public static readonly Guid FOLDERID_RoamedTileImages__scanned__ = new Guid(0xaaa8d5a5, 0xf1d6, 0x4259, 0xba, 0xa8, 0x78, 0xe7, 0xef, 0x60, 0x83, 0x5e);

        public static readonly Guid FOLDERID_Screenshots__scanned__ = new Guid(0xb7bede81, 0xdf94, 0x4682, 0xa7, 0xd8, 0x57, 0xa5, 0x26, 0x20, 0xb8, 0x6f);

        public static readonly Guid FOLDERID_CameraRoll__scanned__ = new Guid(0xab5fb87b, 0x7ce2, 0x4f83, 0x91, 0x5d, 0x55, 0x8, 0x46, 0xc9, 0x53, 0x7b);

        public static readonly Guid FOLDERID_SkyDrive__scanned__ = new Guid(0xa52bba46, 0xe9e1, 0x435f, 0xb3, 0xd9, 0x28, 0xda, 0xa6, 0x48, 0xc0, 0xf6);

        public static readonly Guid FOLDERID_OneDrive__scanned__ = new Guid(0xa52bba46, 0xe9e1, 0x435f, 0xb3, 0xd9, 0x28, 0xda, 0xa6, 0x48, 0xc0, 0xf6);

        public static readonly Guid FOLDERID_SkyDriveDocuments__scanned__ = new Guid(0x24d89e24, 0x2f19, 0x4534, 0x9d, 0xde, 0x6a, 0x66, 0x71, 0xfb, 0xb8, 0xfe);

        public static readonly Guid FOLDERID_SkyDrivePictures__scanned__ = new Guid(0x339719b5, 0x8c47, 0x4894, 0x94, 0xc2, 0xd8, 0xf7, 0x7a, 0xdd, 0x44, 0xa6);

        public static readonly Guid FOLDERID_SkyDriveMusic__scanned__ = new Guid(0xc3f2459e, 0x80d6, 0x45dc, 0xbf, 0xef, 0x1f, 0x76, 0x9f, 0x2b, 0xe7, 0x30);

        public static readonly Guid FOLDERID_SkyDriveCameraRoll__scanned__ = new Guid(0x767e6811, 0x49cb, 0x4273, 0x87, 0xc2, 0x20, 0xf3, 0x55, 0xe1, 0x08, 0x5b);

        public static readonly Guid FOLDERID_SearchHistory__scanned__ = new Guid(0x0d4c3db6, 0x03a3, 0x462f, 0xa0, 0xe6, 0x08, 0x92, 0x4c, 0x41, 0xb5, 0xd4);

        public static readonly Guid FOLDERID_SearchTemplates__scanned__ = new Guid(0x7e636bfe, 0xdfa9, 0x4d5e, 0xb4, 0x56, 0xd7, 0xb3, 0x98, 0x51, 0xd8, 0xa9);

        public static readonly Guid FOLDERID_CameraRollLibrary__scanned__ = new Guid(0x2b20df75, 0x1eda, 0x4039, 0x80, 0x97, 0x38, 0x79, 0x82, 0x27, 0xd5, 0xb7);

        public static readonly Guid FOLDERID_SavedPictures__scanned__ = new Guid(0x3b193882, 0xd3ad, 0x4eab, 0x96, 0x5a, 0x69, 0x82, 0x9d, 0x1f, 0xb5, 0x9f);

        public static readonly Guid FOLDERID_SavedPicturesLibrary__scanned__ = new Guid(0xe25b5812, 0xbe88, 0x4bd9, 0x94, 0xb0, 0x29, 0x23, 0x34, 0x77, 0xb6, 0xc3);

        public static readonly Guid FOLDERID_RetailDemo__scanned__ = new Guid(0x12d4c69e, 0x24ad, 0x4923, 0xbe, 0x19, 0x31, 0x32, 0x1c, 0x43, 0xa7, 0x67);

        public static readonly Guid FOLDERID_Device__scanned__ = new Guid(0x1C2AC1DC, 0x4358, 0x4B6C, 0x97, 0x33, 0xAF, 0x21, 0x15, 0x65, 0x76, 0xF0);

        public static readonly Guid FOLDERID_DevelopmentFiles__scanned__ = new Guid(0xdbe8e08e, 0x3053, 0x4bbc, 0xb1, 0x83, 0x2a, 0x7b, 0x2b, 0x19, 0x1e, 0x59);

        public static readonly Guid FOLDERID_Objects3D__scanned__ = new Guid(0x31c0dd25, 0x9439, 0x4f12, 0xbf, 0x41, 0x7f, 0xf4, 0xed, 0xa3, 0x87, 0x22);

        public static readonly Guid FOLDERID_AppCaptures__scanned__ = new Guid(0xedc0fe71, 0x98d8, 0x4f4a, 0xb9, 0x20, 0xc8, 0xdc, 0x13, 0x3c, 0xb1, 0x65);

        public static readonly Guid FOLDERID_LocalDocuments__scanned__ = new Guid(0xf42ee2d3, 0x909f, 0x4907, 0x88, 0x71, 0x4c, 0x22, 0xfc, 0x0b, 0xf7, 0x56);

        public static readonly Guid FOLDERID_LocalPictures__scanned__ = new Guid(0x0ddd015d, 0xb06c, 0x45d5, 0x8c, 0x4c, 0xf5, 0x97, 0x13, 0x85, 0x46, 0x39);

        public static readonly Guid FOLDERID_LocalVideos__scanned__ = new Guid(0x35286a68, 0x3c57, 0x41a1, 0xbb, 0xb1, 0x0e, 0xae, 0x73, 0xd7, 0x6c, 0x95);

        public static readonly Guid FOLDERID_LocalMusic__scanned__ = new Guid(0xa0c69a99,  0x21c8, 0x4671, 0x87, 0x03, 0x79, 0x34, 0x16, 0x2f, 0xcf, 0x1d);

        public static readonly Guid FOLDERID_LocalDownloads__scanned__ = new Guid(0x7d83ee9b,  0x2244, 0x4e70, 0xb1, 0xf5, 0x53, 0x93, 0x04, 0x2a, 0xf1, 0xe4);

        public static readonly Guid FOLDERID_RecordedCalls__scanned__ = new Guid(0x2f8b40c2, 0x83ed, 0x48ee, 0xb3, 0x83, 0xa1, 0xf1, 0x57, 0xec, 0x6f, 0x9a);

        public static readonly Guid FOLDERID_AllAppMods__scanned__ = new Guid(0x7ad67899, 0x66af, 0x43ba, 0x91, 0x56, 0x6a, 0xad, 0x42, 0xe6, 0xc5, 0x96);

        public static readonly Guid FOLDERID_CurrentAppMods__scanned__ = new Guid(0x3db40b20, 0x2a30, 0x4dbe, 0x91, 0x7e, 0x77, 0x1d, 0xd2, 0x1d, 0xd0, 0x99);

        public static readonly Guid FOLDERID_AppDataDesktop__scanned__ = new Guid(0xb2c5e279, 0x7add, 0x439f, 0xb2, 0x8c, 0xc4, 0x1f, 0xe1, 0xbb, 0xf6, 0x72);

        public static readonly Guid FOLDERID_AppDataDocuments__scanned__ = new Guid(0x7be16610, 0x1f7f, 0x44ac, 0xbf, 0xf0, 0x83, 0xe1, 0x5f, 0x2f, 0xfc, 0xa1);

        public static readonly Guid FOLDERID_AppDataFavorites__scanned__ = new Guid(0x7cfbefbc, 0xde1f, 0x45aa, 0xb8, 0x43, 0xa5, 0x42, 0xac, 0x53, 0x6c, 0xc9);

        public static readonly Guid FOLDERID_AppDataProgramData__scanned__ = new Guid(0x559d40a3, 0xa036, 0x40fa, 0xaf, 0x61, 0x84, 0xcb, 0x43, 0xa, 0x4d, 0x34);

        public static readonly Guid CLSID_InternetShortcut__scanned__ = new Guid(0xFBF23B40L, 0xE3F0, 0x101B, 0x84, 0x88, 0x00, 0xAA, 0x00, 0x3E, 0x56, 0xF8);

        public static readonly Guid CLSID_NetworkDomain__scanned__ = new Guid(0x46e06680, 0x4bf0, 0x11d1, 0x83,0xee,0x00,0xa0,0xc9,0x0d,0xc8,0x49);

        public static readonly Guid CLSID_NetworkServer__scanned__ = new Guid(0xc0542a90, 0x4bf0, 0x11d1, 0x83,0xee,0x00,0xa0,0xc9,0x0d,0xc8,0x49);

        public static readonly Guid CLSID_NetworkShare__scanned__ = new Guid(0x54a754c0, 0x4bf0, 0x11d1, 0x83,0xee,0x00,0xa0,0xc9,0x0d,0xc8,0x49);

        public static readonly Guid CLSID_MyComputer__scanned__ = new Guid(0x20D04FE0, 0x3AEA, 0x1069, 0xA2,0xD8,0x08,0x00,0x2B,0x30,0x30,0x9D);

        public static readonly Guid CLSID_Internet__scanned__ = new Guid(0x871C5380, 0x42A0, 0x1069, 0xA2,0xEA,0x08,0x00,0x2B,0x30,0x30,0x9D);

        public static readonly Guid CLSID_RecycleBin__scanned__ = new Guid(0x645FF040, 0x5081, 0x101B, 0x9F,0x08,0x00,0xAA,0x00,0x2F,0x95,0x4E);

        public static readonly Guid CLSID_ControlPanel__scanned__ = new Guid(0x21EC2020, 0x3AEA, 0x1069, 0xA2,0xDD,0x08,0x00,0x2B,0x30,0x30,0x9D);

        public static readonly Guid CLSID_Printers__scanned__ = new Guid(0x2227A280, 0x3AEA, 0x1069, 0xA2,0xDE,0x08,0x00,0x2B,0x30,0x30,0x9D);

        public static readonly Guid CLSID_MyDocuments__scanned__ = new Guid(0x450d8fba, 0xad25, 0x11d0, 0x98,0xa8,0x08,0x00,0x36,0x1b,0x11,0x03);

        public static readonly Guid CATID_BrowsableShellExt__scanned__ = new Guid(0x00021490L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid CATID_BrowseInPlace__scanned__ = new Guid(0x00021491L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid CATID_DeskBand__scanned__ = new Guid(0x00021492L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid CATID_InfoBand__scanned__ = new Guid(0x00021493L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid CATID_CommBand__scanned__ = new Guid(0x00021494L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid FMTID_Intshcut__scanned__ = new Guid(0x000214A0L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid FMTID_InternetSite__scanned__ = new Guid(0x000214A1L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid CGID_Explorer__scanned__ = new Guid(0x000214D0L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid CGID_ShellDocView__scanned__ = new Guid(0x000214D1L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid CGID_ShellServiceObject__scanned__ = new Guid(0x000214D2L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid CGID_ExplorerBarDoc__scanned__ = new Guid(0x000214D3L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IFileViewerA__scanned__ = new Guid(0x000214F0L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IFileViewerSite__scanned__ = new Guid(0x000214F3L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IShellExecuteHookA__scanned__ = new Guid(0x000214F5L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IPropSheetPage__scanned__ = new Guid(0x000214F6L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IFileViewerW__scanned__ = new Guid(0x000214F8L, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IShellExecuteHookW__scanned__ = new Guid(0x000214FBL, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IBriefcaseStg__scanned__ = new Guid(0x8BCE1FA1L, 0x0921, 0x101B, 0xB1, 0xFF, 0x00, 0xDD, 0x01, 0x0C, 0xCC, 0x48);

        public static readonly Guid IID_IDefViewID__scanned__ = new Guid(0x985F64F0L, 0xD410, 0x4E02, 0xBE, 0x22, 0xDA, 0x07, 0xF2, 0xB5, 0xC5, 0xE1);

        public static readonly Guid CLSID_FolderShortcut__scanned__ = new Guid(0x0AFACED1L, 0xE828, 0x11D1, 0x91, 0x87, 0xB5, 0x32, 0xF1, 0xE9, 0x57, 0x5D);

        public static readonly Guid CLSID_CFSIconOverlayManager__scanned__ = new Guid(0x63B51F81L, 0xC868, 0x11D0, 0x99, 0x9C, 0x00, 0xC0, 0x4F, 0xD6, 0x55, 0xE1);

        public static readonly Guid IID_IShellImageStore__scanned__ = new Guid(0x48c8118c, 0xb924, 0x11d1, 0x98, 0xd5, 0x0, 0xc0, 0x4f, 0xb6, 0x87, 0xda);

        public static readonly Guid CLSID_ShellThumbnailDiskCache__scanned__ = new Guid(0x1ebdcf80, 0xa200, 0x11d0, 0xa3, 0xa4, 0x0, 0xc0, 0x4f, 0xd7, 0x6, 0xec);

        public static readonly Guid SID_DefView__scanned__ = new Guid(0x6D12FE80, 0x7911, 0x11CF, 0x95, 0x34, 0x00, 0x00, 0xC0, 0x5B, 0xAE, 0x0B);

        public static readonly Guid CGID_DefView__scanned__ = new Guid(0x4af07f10, 0xd231, 0x11d0, 0xb9, 0x42, 0x0, 0xa0, 0xc9, 0x3, 0x12, 0xe1);

        public static readonly Guid CLSID_MenuBand__scanned__ = new Guid(0x5b4dae26, 0xb807, 0x11d0, 0x98, 0x15, 0x0, 0xc0, 0x4f, 0xd9, 0x19, 0x72);

        public static readonly Guid IID_IDefViewFrame__scanned__ = new Guid(0x710EB7A0L, 0x45ED, 0x11D0, 0x92, 0x4A, 0x00, 0x20, 0xAF, 0xC7, 0xAC, 0x4D);

        public static readonly Guid VID_LargeIcons__scanned__ = new Guid(0x0057D0E0L, 0x3573, 0x11CF, 0xAE, 0x69, 0x08, 0x00, 0x2B, 0x2E, 0x12, 0x62);

        public static readonly Guid VID_SmallIcons__scanned__ = new Guid(0x089000C0L, 0x3573, 0x11CF, 0xAE, 0x69, 0x08, 0x00, 0x2B, 0x2E, 0x12, 0x62);

        public static readonly Guid VID_List__scanned__ = new Guid(0x0E1FA5E0L, 0x3573, 0x11CF, 0xAE, 0x69, 0x08, 0x00, 0x2B, 0x2E, 0x12, 0x62);

        public static readonly Guid VID_Details__scanned__ = new Guid(0x137E7700L, 0x3573, 0x11CF, 0xAE, 0x69, 0x08, 0x00, 0x2B, 0x2E, 0x12, 0x62);

        public static readonly Guid VID_Tile__scanned__ = new Guid(0x65f125e5L, 0x7be1, 0x4810, 0xba, 0x9d, 0xd2, 0x71, 0xc8, 0x43, 0x2c, 0xe3);

        public static readonly Guid VID_Content__scanned__ = new Guid(0x30c2c434L, 0x0889, 0x4c8d, 0x98, 0x5d, 0xa9, 0xf7, 0x18, 0x30, 0xb0, 0xa9);

        public static readonly Guid VID_Thumbnails__scanned__ = new Guid(0x8bebb290, 0x52d0, 0x11d0, 0xb7, 0xf4, 0x0, 0xc0, 0x4f, 0xd7, 0x6, 0xec);

        public static readonly Guid VID_ThumbStrip__scanned__ = new Guid(0x8EEFA624, 0xD1E9, 0x445B, 0x94, 0xB7, 0x74, 0xFB, 0xCE, 0x2E, 0xA1, 0x1A);

        public static readonly Guid SID_SInPlaceBrowser__scanned__ = new Guid(0x1D2AE02B, 0x3655, 0x46CC, 0xB6, 0x3A, 0x28, 0x59, 0x88, 0x15, 0x3B, 0xCA);

        public static readonly Guid SID_SSearchBoxInfo__scanned__ = new Guid(0x142daa61, 0x516b, 0x4713, 0xb4, 0x9c, 0xfb, 0x98, 0x5e, 0xf8, 0x29, 0x98);

        public static readonly Guid SID_CommandsPropertyBag__scanned__ = new Guid(0x6e043250, 0x4416, 0x485c, 0xb1, 0x43, 0xe6, 0x2a, 0x76, 0x0d, 0x9f, 0xe5);

        public static readonly Guid IID_IDiscardableBrowserProperty__scanned__ = new Guid(0x49c3de7c, 0xd329, 0x11d0, 0xab, 0x73, 0x00, 0xc0, 0x4f, 0xc3, 0x3e, 0x80);

        public static readonly Guid CLSID_CUrlHistory__scanned__ = new Guid(0x3C374A40L, 0xBAE4, 0x11CF, 0xBF, 0x7D, 0x00, 0xAA, 0x00, 0x69, 0x46, 0xEE);

        public static readonly Guid CLSID_CURLSearchHook__scanned__ = new Guid(0xCFBFAE00L, 0x17A6, 0x11D0, 0x99, 0xCB, 0x00, 0xC0, 0x4F, 0xD6, 0x44, 0x97);

        public static readonly Guid CLSID_AutoComplete__scanned__ = new Guid(0x00BB2763L, 0x6A77, 0x11D0, 0xA5, 0x35, 0x00, 0xC0, 0x4F, 0xD7, 0xD0, 0x62);

        public static readonly Guid CLSID_ACLHistory__scanned__ = new Guid(0x00BB2764L, 0x6A77, 0x11D0, 0xA5, 0x35, 0x00, 0xC0, 0x4F, 0xD7, 0xD0, 0x62);

        public static readonly Guid CLSID_ACListISF__scanned__ = new Guid(0x03C036F1L, 0xA186, 0x11D0, 0x82, 0x4A, 0x00, 0xAA, 0x00, 0x5B, 0x43, 0x83);

        public static readonly Guid CLSID_ACLMRU__scanned__ = new Guid(0x6756a641L, 0xde71, 0x11d0, 0x83, 0x1b, 0x0, 0xaa, 0x0, 0x5b, 0x43, 0x83);

        public static readonly Guid CLSID_ACLMulti__scanned__ = new Guid(0x00BB2765L, 0x6A77, 0x11D0, 0xA5, 0x35, 0x00, 0xC0, 0x4F, 0xD7, 0xD0, 0x62);

        public static readonly Guid CLSID_ACLCustomMRU__scanned__ = new Guid(0x6935db93, 0x21e8, 0x4ccc, 0xbe, 0xb9, 0x9f, 0xe3, 0xc7, 0x7a, 0x29, 0x7a);

        public static readonly Guid CLSID_ProgressDialog__scanned__ = new Guid(0xf8383852, 0xfcd3, 0x11d1, 0xa6, 0xb9, 0x0, 0x60, 0x97, 0xdf, 0x5b, 0xd4);

        public static readonly Guid SID_STopLevelBrowser__scanned__ = new Guid(0x4C96BE40L, 0x915C, 0x11CF, 0x99, 0xD3, 0x00, 0xAA, 0x00, 0x4A, 0xE8, 0x37);

        public static readonly Guid CLSID_FileTypes__scanned__ = new Guid(0xB091E540, 0x83E3, 0x11CF, 0xA7,0x13,0x00,0x20,0xAF,0xD7,0x97,0x62);

        public static readonly Guid CLSID_ActiveDesktop__scanned__ = new Guid(0x75048700L, 0xEF1F, 0x11D0, 0x98, 0x88, 0x00, 0x60, 0x97, 0xDE, 0xAC, 0xF9);

        public static readonly Guid IID_IActiveDesktop__scanned__ = new Guid(0xF490EB00L, 0x1240, 0x11D1, 0x98, 0x88, 0x00, 0x60, 0x97, 0xDE, 0xAC, 0xF9);

        public static readonly Guid IID_ISynchronizedCallBack__scanned__ = new Guid(0x74c26041, 0x70d1, 0x11d1, 0xb7, 0x5a, 0x0, 0xa0, 0xc9, 0x5, 0x64, 0xfe);

        public static readonly Guid CLSID_QueryAssociations__scanned__ = new Guid(0xa07034fd, 0x6caa, 0x4954, 0xac, 0x3f, 0x97, 0xa2, 0x72, 0x16, 0xf9, 0x8a);

        public static readonly Guid CLSID_LinkColumnProvider__scanned__ = new Guid(0x24f14f02, 0x7b1c, 0x11d1, 0x83, 0x8f, 0x0, 0x0, 0xf8, 0x4, 0x61, 0xcf);

        public static readonly Guid CGID_ShortCut__scanned__ = new Guid(0x93a68750, 0x951a, 0x11d1, 0x94, 0x6f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0);

        public static readonly Guid CLSID_InternetButtons__scanned__ = new Guid(0x1E796980L, 0x9CC5, 0x11D1, 0xA8, 0x3F, 0x00, 0xC0, 0x4F, 0xC9, 0x9D, 0x61);

        public static readonly Guid CLSID_MSOButtons__scanned__ = new Guid(0x178f34b8, 0xa282, 0x11d2, 0x86, 0xc5, 0x0, 0xc0, 0x4f, 0x8e, 0xea, 0x99);

        public static readonly Guid CLSID_ToolbarExtButtons__scanned__ = new Guid(0x2ce4b5d8, 0xa28f, 0x11d2, 0x86, 0xc5, 0x0, 0xc0, 0x4f, 0x8e, 0xea, 0x99);

        public static readonly Guid CLSID_DarwinAppPublisher__scanned__ = new Guid(0xCFCCC7A0L, 0xA282, 0x11D1, 0x90, 0x82, 0x00, 0x60, 0x08, 0x05, 0x93, 0x82);

        public static readonly Guid CLSID_DocHostUIHandler__scanned__ = new Guid(0x7057e952, 0xbd1b, 0x11d1, 0x89, 0x19, 0x0, 0xc0, 0x4f, 0xc2, 0xc8, 0x36);

        public static readonly Guid FMTID_ShellDetails__scanned__ = new Guid(0x28636aa6, 0x953d, 0x11d2, 0xb5, 0xd6, 0x0, 0xc0, 0x4f, 0xd9, 0x18, 0xd0);

        public const uint PID_FINDDATA = 0;

        public const uint PID_NETRESOURCE = 1;

        public const uint PID_DESCRIPTIONID = 2;

        public const uint PID_WHICHFOLDER = 3;

        public const uint PID_NETWORKLOCATION = 4;

        public const uint PID_COMPUTERNAME = 5;

        public static readonly Guid FMTID_Storage__scanned__ = new Guid(0xb725f130, 0x47ef, 0x101a, 0xa5, 0xf1, 0x02, 0x60, 0x8c, 0x9e, 0xeb, 0xac);

        public static readonly Guid FMTID_ImageProperties__scanned__ = new Guid(0x14b81da1, 0x0135, 0x4d31, 0x96, 0xd9, 0x6c, 0xbf, 0xc9, 0x67, 0x1a, 0x99);

        public static readonly Guid FMTID_CustomImageProperties__scanned__ = new Guid(0x7ecd8b0e, 0xc136, 0x4a9b, 0x94, 0x11, 0x4e, 0xbd, 0x66, 0x73, 0xcc, 0xc3);

        public static readonly Guid FMTID_LibraryProperties__scanned__ = new Guid(0x5d76b67f, 0x9b3d, 0x44bb, 0xb6, 0xae, 0x25, 0xda, 0x4f, 0x63, 0x8a, 0x67);

        public static readonly Guid FMTID_Displaced__scanned__ = new Guid(0x9b174b33, 0x40ff, 0x11d2, 0xa2, 0x7e, 0x0, 0xc0, 0x4f, 0xc3, 0x8, 0x71);

        public const uint PID_DISPLACED_FROM = 2;

        public const uint PID_DISPLACED_DATE = 3;

        public static readonly Guid FMTID_Briefcase__scanned__ = new Guid(0x328d8b21, 0x7729, 0x4bfc, 0x95, 0x4c, 0x90, 0x2b, 0x32, 0x9d, 0x56, 0xb0);

        public const uint PID_SYNC_COPY_IN = 2;

        public static readonly Guid FMTID_Misc__scanned__ = new Guid(0x9b174b34, 0x40ff, 0x11d2, 0xa2, 0x7e, 0x0, 0xc0, 0x4f, 0xc3, 0x8, 0x71);

        public const uint PID_MISC_STATUS = 2;

        public const uint PID_MISC_ACCESSCOUNT = 3;

        public const uint PID_MISC_OWNER = 4;

        public const uint PID_HTMLINFOTIPFILE = 5;

        public const uint PID_MISC_PICS = 6;

        public static readonly Guid FMTID_WebView__scanned__ = new Guid(0xf2275480, 0xf782, 0x4291, 0xbd, 0x94, 0xf1, 0x36, 0x93, 0x51, 0x3a, 0xec);

        public const uint PID_DISPLAY_PROPERTIES = 0;

        public const uint PID_INTROTEXT = 1;

        public static readonly Guid FMTID_MUSIC__scanned__ = new Guid(0x56a3372e, 0xce9c, 0x11d2, 0x9f, 0xe, 0x0, 0x60, 0x97, 0xc6, 0x86, 0xf6);

        public const uint PIDSI_ARTIST = 2;

        public const uint PIDSI_SONGTITLE = 3;

        public const uint PIDSI_ALBUM = 4;

        public const uint PIDSI_YEAR = 5;

        public const uint PIDSI_COMMENT = 6;

        public const uint PIDSI_TRACK = 7;

        public const uint PIDSI_GENRE = 11;

        public const uint PIDSI_LYRICS = 12;

        public static readonly Guid FMTID_DRM__scanned__ = new Guid(0xaeac19e4, 0x89ae, 0x4508, 0xb9, 0xb7, 0xbb, 0x86, 0x7a, 0xbe, 0xe2, 0xed);

        public const uint PIDDRSI_PROTECTED = 2;

        public const uint PIDDRSI_DESCRIPTION = 3;

        public const uint PIDDRSI_PLAYCOUNT = 4;

        public const uint PIDDRSI_PLAYSTARTS = 5;

        public const uint PIDDRSI_PLAYEXPIRES = 6;

        public const uint PIDVSI_STREAM_NAME = 0x00000002;

        public const uint PIDVSI_FRAME_WIDTH = 0x00000003;

        public const uint PIDVSI_FRAME_HEIGHT = 0x00000004;

        public const uint PIDVSI_TIMELENGTH = 0x00000007;

        public const uint PIDVSI_FRAME_COUNT = 0x00000005;

        public const uint PIDVSI_FRAME_RATE = 0x00000006;

        public const uint PIDVSI_DATA_RATE = 0x00000008;

        public const uint PIDVSI_SAMPLE_SIZE = 0x00000009;

        public const uint PIDVSI_COMPRESSION = 0x0000000A;

        public const uint PIDVSI_STREAM_NUMBER = 0x0000000B;

        public const uint PIDASI_FORMAT = 0x00000002;

        public const uint PIDASI_TIMELENGTH = 0x00000003;

        public const uint PIDASI_AVG_DATA_RATE = 0x00000004;

        public const uint PIDASI_SAMPLE_RATE = 0x00000005;

        public const uint PIDASI_SAMPLE_SIZE = 0x00000006;

        public const uint PIDASI_CHANNEL_COUNT = 0x00000007;

        public const uint PIDASI_STREAM_NUMBER = 0x00000008;

        public const uint PIDASI_STREAM_NAME = 0x00000009;

        public const uint PIDASI_COMPRESSION = 0x0000000A;

        public const uint PID_CONTROLPANEL_CATEGORY = 2;

        public static readonly Guid FMTID_Volume__scanned__ = new Guid(0x9b174b35, 0x40ff, 0x11d2, 0xa2, 0x7e, 0x0, 0xc0, 0x4f, 0xc3, 0x8, 0x71);

        public const uint PID_VOLUME_FREE = 2;

        public const uint PID_VOLUME_CAPACITY = 3;

        public const uint PID_VOLUME_FILESYSTEM = 4;

        public const uint PID_SHARE_CSC_STATUS = 2;

        public const uint PID_LINK_TARGET = 2;

        public const uint PID_LINK_TARGET_TYPE = 3;

        public static readonly Guid FMTID_Query__scanned__ = new Guid(0x49691c90,0x7e17,0x101a, 0xa9,0x1c,0x08,0x00,0x2b,0x2e,0xcd,0xa9);

        public const uint PID_QUERY_RANK = 2;

        public static readonly Guid CLSID_HWShellExecute__scanned__ = new Guid(0xffb8655f, 0x81b9, 0x4fce, 0xb8, 0x9c, 0x9a, 0x6b, 0xa7, 0x6d, 0x13, 0xe7);

        public static readonly Guid CLSID_DragDropHelper__scanned__ = new Guid(0x4657278a, 0x411b, 0x11d2, 0x83, 0x9a, 0x0, 0xc0, 0x4f, 0xd9, 0x18, 0xd0);

        public static readonly Guid CLSID_CAnchorBrowsePropertyPage__scanned__ = new Guid(0x3050f3BB, 0x98b5, 0x11cf, 0xbb, 0x82, 0x00, 0xaa, 0x00, 0xbd, 0xce, 0x0b);

        public static readonly Guid CLSID_CImageBrowsePropertyPage__scanned__ = new Guid(0x3050f3B3, 0x98b5, 0x11cf, 0xbb, 0x82, 0x00, 0xaa, 0x00, 0xbd, 0xce, 0x0b);

        public static readonly Guid CLSID_CDocBrowsePropertyPage__scanned__ = new Guid(0x3050f3B4, 0x98b5, 0x11cf, 0xbb, 0x82, 0x00, 0xaa, 0x00, 0xbd, 0xce, 0x0b);

        public static readonly Guid SID_STopWindow__scanned__ = new Guid(0x49e1b500, 0x4636, 0x11d3, 0x97, 0xf7, 0x0, 0xc0, 0x4f, 0x45, 0xd0, 0xb3);

        public static readonly Guid SID_SGetViewFromViewDual__scanned__ = new Guid(0x889A935D, 0x971E, 0x4B12, 0xB9, 0x0C, 0x24, 0xDF, 0xC9, 0xE1, 0xE5, 0xE8);

        public static readonly Guid CLSID_FolderItem__scanned__ = new Guid(0xfef10fa2, 0x355e, 0x4e06, 0x93, 0x81, 0x9b, 0x24, 0xd7, 0xf7, 0xcc, 0x88);

        public static readonly Guid CLSID_FolderItemsMultiLevel__scanned__ = new Guid(0x53c74826, 0xab99, 0x4d33, 0xac, 0xa4, 0x31, 0x17, 0xf5, 0x1d, 0x37, 0x88);

        public static readonly Guid CLSID_NewMenu__scanned__ = new Guid(0xd969a300, 0xe7ff, 0x11d0, 0xa9, 0x3b, 0x0, 0xa0, 0xc9, 0xf, 0x27, 0x19);

        public static readonly Guid BHID_SFObject__scanned__ = new Guid(0x3981e224, 0xf559, 0x11d3, 0x8e, 0x3a, 0x00, 0xc0, 0x4f, 0x68, 0x37, 0xd5);

        public static readonly Guid BHID_SFUIObject__scanned__ = new Guid(0x3981e225, 0xf559, 0x11d3, 0x8e, 0x3a, 0x00, 0xc0, 0x4f, 0x68, 0x37, 0xd5);

        public static readonly Guid BHID_SFViewObject__scanned__ = new Guid(0x3981e226, 0xf559, 0x11d3, 0x8e, 0x3a, 0x00, 0xc0, 0x4f, 0x68, 0x37, 0xd5);

        public static readonly Guid BHID_Storage__scanned__ = new Guid(0x3981e227, 0xf559, 0x11d3, 0x8e, 0x3a, 0x00, 0xc0, 0x4f, 0x68, 0x37, 0xd5);

        public static readonly Guid BHID_Stream__scanned__ = new Guid(0x1cebb3ab, 0x7c10, 0x499a, 0xa4, 0x17, 0x92, 0xca, 0x16, 0xc4, 0xcb, 0x83);

        public static readonly Guid BHID_RandomAccessStream__scanned__ = new Guid(0xf16fc93b, 0x77ae, 0x4cfe, 0xbd, 0xa7, 0xa8, 0x66, 0xee, 0xa6, 0x87, 0x8d);

        public static readonly Guid BHID_LinkTargetItem__scanned__ = new Guid(0x3981e228, 0xf559, 0x11d3, 0x8e, 0x3a, 0x00, 0xc0, 0x4f, 0x68, 0x37, 0xd5);

        public static readonly Guid BHID_StorageEnum__scanned__ = new Guid(0x4621a4e3, 0xf0d6, 0x4773, 0x8a, 0x9c, 0x46, 0xe7, 0x7b, 0x17, 0x48, 0x40);

        public static readonly Guid BHID_Transfer__scanned__ = new Guid(0xd5e346a1, 0xf753, 0x4932, 0xb4, 0x3, 0x45, 0x74, 0x80, 0xe, 0x24, 0x98);

        public static readonly Guid BHID_PropertyStore__scanned__ = new Guid(0x0384e1a4, 0x1523, 0x439c, 0xa4, 0xc8, 0xab, 0x91, 0x10, 0x52, 0xf5, 0x86);

        public static readonly Guid BHID_ThumbnailHandler__scanned__ = new Guid(0x7b2e650a, 0x8e20, 0x4f4a, 0xb0, 0x9e, 0x65, 0x97, 0xaf, 0xc7, 0x2f, 0xb0);

        public static readonly Guid BHID_EnumItems__scanned__ = new Guid(0x94f60519, 0x2850, 0x4924, 0xaa, 0x5a, 0xd1, 0x5e, 0x84, 0x86, 0x80, 0x39);

        public static readonly Guid BHID_DataObject__scanned__ = new Guid(0xb8c0bd9f, 0xed24, 0x455c, 0x83, 0xe6, 0xd5, 0x39, 0xc, 0x4f, 0xe8, 0xc4);

        public static readonly Guid BHID_AssociationArray__scanned__ = new Guid(0xbea9ef17, 0x82f1, 0x4f60, 0x92, 0x84, 0x4f, 0x8d, 0xb7, 0x5c, 0x3b, 0xe9);

        public static readonly Guid BHID_Filter__scanned__ = new Guid(0x38d08778, 0xf557, 0x4690, 0x9e, 0xbf, 0xba, 0x54, 0x70, 0x6a, 0xd8, 0xf7);

        public static readonly Guid BHID_EnumAssocHandlers__scanned__ = new Guid(0xb8ab0b9c, 0xc2ec, 0x4f7a, 0x91, 0x8d, 0x31, 0x49, 0x00, 0xe6, 0x28, 0x0a);

        public static readonly Guid BHID_StorageItem__scanned__ = new Guid(0x404e2109, 0x77d2, 0x4699, 0xa5, 0xa0, 0x4f, 0xdf, 0x10, 0xdb, 0x98, 0x37);

        public static readonly Guid BHID_FilePlaceholder__scanned__ = new Guid(0x8677dceb, 0xaae0, 0x4005, 0x8d, 0x3d, 0x54, 0x7f, 0xa8, 0x52, 0xf8, 0x25);

        public static readonly Guid CATID_FilePlaceholderMergeHandler__scanned__ = new Guid(0x3e9c9a51, 0xd4aa, 0x4870, 0xb4, 0x7c, 0x74, 0x24, 0xb4, 0x91, 0xf1, 0xcc);

        public static readonly Guid SID_CtxQueryAssociations__scanned__ = new Guid(0xfaadfc40, 0xb777, 0x4b69, 0xaa, 0x81, 0x77, 0x03, 0x5e, 0xf0, 0xe6, 0xe8);

        public static readonly Guid CLSID_QuickLinks__scanned__ = new Guid(0xe5cbf21, 0xd15f, 0x11d0, 0x83, 0x1, 0x0, 0xaa, 0x0, 0x5b, 0x43, 0x83);

        public static readonly Guid CLSID_ISFBand__scanned__ = new Guid(0xD82BE2B0L, 0x5764, 0x11D0, 0xA9, 0x6E, 0x00, 0xC0, 0x4F, 0xD7, 0x05, 0xA2);

        public static readonly Guid IID_CDefView__scanned__ = new Guid(0x4434FF80, 0xEF4C, 0x11CE, 0xAE, 0x65, 0x08, 0x00, 0x2B, 0x2E, 0x12, 0x62 );

        public static readonly Guid CLSID_ShellFldSetExt__scanned__ = new Guid(0x6D5313C0, 0x8C62, 0x11D1, 0xB2,0xCD,0x00,0x60,0x97,0xDF,0x8C,0x11);

        public static readonly Guid SID_SMenuBandChild__scanned__ = new Guid(0xed9cc020, 0x8b9, 0x11d1, 0x98, 0x23, 0x0, 0xc0, 0x4f, 0xd9, 0x19, 0x72);

        public static readonly Guid SID_SMenuBandParent__scanned__ = new Guid(0x8c278eec, 0x3eab, 0x11d1, 0x8c, 0xb0, 0x0, 0xc0, 0x4f, 0xd9, 0x18, 0xd0);

        public static readonly Guid SID_SMenuPopup__scanned__ = new Guid(0xD1E7AFEB, 0x6A2E, 0x11d0, 0x8C, 0x78, 0x0, 0xC0, 0x4F, 0xD9, 0x18, 0xB4);

        public static readonly Guid SID_SMenuBandBottomSelected__scanned__ = new Guid(0x165ebaf4, 0x6d51, 0x11d2, 0x83, 0xad, 0x0, 0xc0, 0x4f, 0xd9, 0x18, 0xd0);

        public static readonly Guid SID_SMenuBandBottom__scanned__ = new Guid(0x743ca664, 0xdeb, 0x11d1, 0x98, 0x25, 0x0, 0xc0, 0x4f, 0xd9, 0x19, 0x72);

        public static readonly Guid SID_MenuShellFolder__scanned__ = new Guid(0xa6c17eb4, 0x2d65, 0x11d2, 0x83, 0x8f, 0x0, 0xc0, 0x4f, 0xd9, 0x18, 0xd0);

        public static readonly Guid SID_SMenuBandContextMenuModifier__scanned__ = new Guid(0x39545874, 0x7162, 0x465e, 0xb7, 0x83, 0x2a, 0xa1, 0x87, 0x4f, 0xef, 0x81);

        public static readonly Guid SID_SMenuBandBKContextMenu__scanned__ = new Guid(0x164bbd86, 0x1d0d, 0x4de0, 0x9a, 0x3b, 0xd9, 0x72, 0x96, 0x47, 0xc2, 0xb8);

        public static readonly Guid CGID_MENUDESKBAR__scanned__ = new Guid(0x5c9f0a12, 0x959e, 0x11d0, 0xa3, 0xa4, 0x0, 0xa0, 0xc9, 0x8, 0x26, 0x36);

        public static readonly Guid SID_SMenuBandTop__scanned__ = new Guid(0x9493a810, 0xec38, 0x11d0, 0xbc, 0x46, 0x0, 0xaa, 0x0, 0x6c, 0xe2, 0xf5);

        public static readonly Guid CLSID_MenuToolbarBase__scanned__ = new Guid(0x40b96610, 0xb522, 0x11d1, 0xb3, 0xb4, 0x0, 0xaa, 0x0, 0x6e, 0xfd, 0xe7);

        public static readonly Guid CLSID_MenuBandSite__scanned__ = new Guid(0xe13ef4e4, 0xd2f2, 0x11d0, 0x98, 0x16, 0x0, 0xc0, 0x4f, 0xd9, 0x19, 0x72);

        public static readonly Guid SID_SCommDlgBrowser__scanned__ = new Guid(0x80f30233, 0xb7df, 0x11d2, 0xa3, 0x3b, 0x0, 0x60, 0x97, 0xdf, 0x5b, 0xd4);

        public static readonly Guid CPFG_LOGON_USERNAME__scanned__ = new Guid(0xda15bbe8, 0x954d, 0x4fd3, 0xb0, 0xf4, 0x1f, 0xb5, 0xb9, 0x0b, 0x17, 0x4b);

        public static readonly Guid CPFG_LOGON_PASSWORD__scanned__ = new Guid(0x60624cfa, 0xa477, 0x47b1, 0x8a, 0x8e, 0x3a, 0x4a, 0x19, 0x98, 0x18, 0x27);

        public static readonly Guid CPFG_SMARTCARD_USERNAME__scanned__ = new Guid(0x3e1ecf69, 0x568c, 0x4d96, 0x9d, 0x59, 0x46, 0x44, 0x41, 0x74, 0xe2, 0xd6);

        public static readonly Guid CPFG_SMARTCARD_PIN__scanned__ = new Guid(0x4fe5263b, 0x9181, 0x46c1, 0xb0, 0xa4, 0x9d, 0xed, 0xd4, 0xdb, 0x7d, 0xea);

        public static readonly Guid CPFG_CREDENTIAL_PROVIDER_LOGO__scanned__ = new Guid(0x2d837775, 0xf6cd, 0x464e, 0xa7, 0x45, 0x48, 0x2f, 0xd0, 0xb4, 0x74, 0x93);

        public static readonly Guid CPFG_CREDENTIAL_PROVIDER_LABEL__scanned__ = new Guid(0x286bbff3, 0xbad4, 0x438f, 0xb0, 0x7, 0x79, 0xb7, 0x26, 0x7c, 0x3d, 0x48);

        public static readonly Guid CPFG_STANDALONE_SUBMIT_BUTTON__scanned__ = new Guid(0x0b7b0ad8, 0xcc36, 0x4d59, 0x80, 0x2b, 0x82, 0xf7, 0x14, 0xfa, 0x70, 0x22);

        public static readonly Guid CPFG_STYLE_LINK_AS_BUTTON__scanned__ = new Guid(0x088fa508, 0x94a6, 0x4430, 0xa4, 0xcb, 0x6f, 0xc6, 0xe3, 0xc0, 0xb9, 0xe2);

        public static readonly Guid FOLDERTYPEID_Invalid__scanned__ = new Guid(0x57807898, 0x8c4f, 0x4462, 0xbb, 0x63, 0x71, 0x04, 0x23, 0x80, 0xb1, 0x09);

        public static readonly Guid FOLDERTYPEID_Generic__scanned__ = new Guid(0x5c4f28b5, 0xf869, 0x4e84, 0x8e, 0x60, 0xf1, 0x1d, 0xb9, 0x7c, 0x5c, 0xc7);

        public static readonly Guid FOLDERTYPEID_GenericSearchResults__scanned__ = new Guid(0x7fde1a1e, 0x8b31, 0x49a5, 0x93, 0xb8, 0x6b, 0xe1, 0x4c, 0xfa, 0x49, 0x43);

        public static readonly Guid FOLDERTYPEID_GenericLibrary__scanned__ = new Guid(0x5f4eab9a, 0x6833, 0x4f61, 0x89, 0x9d, 0x31, 0xcf, 0x46, 0x97, 0x9d, 0x49);

        public static readonly Guid FOLDERTYPEID_Documents__scanned__ = new Guid(0x7d49d726, 0x3c21, 0x4f05, 0x99, 0xaa, 0xfd, 0xc2, 0xc9, 0x47, 0x46, 0x56);

        public static readonly Guid FOLDERTYPEID_Pictures__scanned__ = new Guid(0xb3690e58, 0xe961, 0x423b, 0xb6, 0x87, 0x38, 0x6e, 0xbf, 0xd8, 0x32, 0x39);

        public static readonly Guid FOLDERTYPEID_Music__scanned__ = new Guid(0x94d6ddcc, 0x4a68, 0x4175, 0xa3, 0x74, 0xbd, 0x58, 0x4a, 0x51, 0x0b, 0x78);

        public static readonly Guid FOLDERTYPEID_Videos__scanned__ = new Guid(0x5fa96407, 0x7e77, 0x483c, 0xac, 0x93, 0x69, 0x1d, 0x05, 0x85, 0x0d, 0xe8);

        public static readonly Guid FOLDERTYPEID_Downloads__scanned__ = new Guid(0x885a186e, 0xa440, 0x4ada, 0x81, 0x2b, 0xdb, 0x87, 0x1b, 0x94, 0x22, 0x59);

        public static readonly Guid FOLDERTYPEID_UserFiles__scanned__ = new Guid(0xcd0fc69b, 0x71e2, 0x46e5, 0x96, 0x90, 0x5b, 0xcd, 0x9f, 0x57, 0xaa, 0xb3);

        public static readonly Guid FOLDERTYPEID_UsersLibraries__scanned__ = new Guid(0xc4d98f09, 0x6124, 0x4fe0, 0x99, 0x42, 0x82, 0x64, 0x16, 0x8, 0x2d, 0xa9);

        public static readonly Guid FOLDERTYPEID_OtherUsers__scanned__ = new Guid(0xb337fd00, 0x9dd5, 0x4635, 0xa6, 0xd4, 0xda, 0x33, 0xfd, 0x10, 0x2b, 0x7a);

        public static readonly Guid FOLDERTYPEID_PublishedItems__scanned__ = new Guid(0x7f2f5b96, 0xff74, 0x41da, 0xaf, 0xd8, 0x1c, 0x78, 0xa5, 0xf3, 0xae, 0xa2);

        public static readonly Guid FOLDERTYPEID_Communications__scanned__ = new Guid(0x91475fe5, 0x586b, 0x4eba, 0x8d, 0x75, 0xd1, 0x74, 0x34, 0xb8, 0xcd, 0xf6);

        public static readonly Guid FOLDERTYPEID_Contacts__scanned__ = new Guid(0xde2b70ec, 0x9bf7, 0x4a93, 0xbd, 0x3d, 0x24, 0x3f, 0x78, 0x81, 0xd4, 0x92);

        public static readonly Guid FOLDERTYPEID_StartMenu__scanned__ = new Guid(0xef87b4cb, 0xf2ce, 0x4785, 0x86, 0x58, 0x4c, 0xa6, 0xc6, 0x3e, 0x38, 0xc6);

        public static readonly Guid FOLDERTYPEID_RecordedTV__scanned__ = new Guid(0x5557a28f, 0x5da6, 0x4f83, 0x88, 0x09, 0xc2, 0xc9, 0x8a, 0x11, 0xa6, 0xfa);

        public static readonly Guid FOLDERTYPEID_SavedGames__scanned__ = new Guid(0xd0363307, 0x28cb, 0x4106, 0x9f, 0x23, 0x29, 0x56, 0xe3, 0xe5, 0xe0, 0xe7);

        public static readonly Guid FOLDERTYPEID_OpenSearch__scanned__ = new Guid(0x8faf9629, 0x1980, 0x46ff, 0x80, 0x23, 0x9d, 0xce, 0xab, 0x9c, 0x3e, 0xe3);

        public static readonly Guid FOLDERTYPEID_SearchConnector__scanned__ = new Guid(0x982725ee, 0x6f47, 0x479e, 0xb4, 0x47, 0x81, 0x2b, 0xfa, 0x7d, 0x2e, 0x8f);

        public static readonly Guid FOLDERTYPEID_AccountPictures__scanned__ = new Guid(0xdb2a5d8f, 0x06e6, 0x4007, 0xab, 0xa6, 0xaf, 0x87, 0x7d, 0x52, 0x6e, 0xa6);

        public static readonly Guid FOLDERTYPEID_Games__scanned__ = new Guid(0xb689b0d0, 0x76d3, 0x4cbb, 0x87, 0xf7, 0x58, 0x5d, 0x0e, 0x0c, 0xe0, 0x70);

        public static readonly Guid FOLDERTYPEID_ControlPanelCategory__scanned__ = new Guid(0xde4f0660, 0xfa10, 0x4b8f, 0xa4, 0x94, 0x06, 0x8b, 0x20, 0xb2, 0x23, 0x07);

        public static readonly Guid FOLDERTYPEID_ControlPanelClassic__scanned__ = new Guid(0x0c3794f3, 0xb545, 0x43aa, 0xa3, 0x29, 0xc3, 0x74, 0x30, 0xc5, 0x8d, 0x2a);

        public static readonly Guid FOLDERTYPEID_Printers__scanned__ = new Guid(0x2c7bbec6, 0xc844, 0x4a0a, 0x91, 0xfa, 0xce, 0xf6, 0xf5, 0x9c, 0xfd, 0xa1);

        public static readonly Guid FOLDERTYPEID_RecycleBin__scanned__ = new Guid(0xd6d9e004, 0xcd87, 0x442b, 0x9d, 0x57, 0x5e, 0x0a, 0xeb, 0x4f, 0x6f, 0x72);

        public static readonly Guid FOLDERTYPEID_SoftwareExplorer__scanned__ = new Guid(0xd674391b, 0x52d9, 0x4e07, 0x83, 0x4e, 0x67, 0xc9, 0x86, 0x10, 0xf3, 0x9d);

        public static readonly Guid FOLDERTYPEID_CompressedFolder__scanned__ = new Guid(0x80213e82, 0xbcfd, 0x4c4f, 0x88, 0x17, 0xbb, 0x27, 0x60, 0x12, 0x67, 0xa9);

        public static readonly Guid FOLDERTYPEID_NetworkExplorer__scanned__ = new Guid(0x25cc242b, 0x9a7c, 0x4f51, 0x80, 0xe0, 0x7a, 0x29, 0x28, 0xfe, 0xbe, 0x42);

        public static readonly Guid FOLDERTYPEID_Searches__scanned__ = new Guid(0x0b0ba2e3, 0x405f, 0x415e, 0xa6, 0xee, 0xca, 0xd6, 0x25, 0x20, 0x78, 0x53);

        public static readonly Guid FOLDERTYPEID_SearchHome__scanned__ = new Guid(0x834d8a44, 0x0974, 0x4ed6, 0x86, 0x6e, 0xf2, 0x03, 0xd8, 0x0b, 0x38, 0x10);

        public static readonly Guid FOLDERTYPEID_StorageProviderGeneric__scanned__ = new Guid(0x4F01EBC5, 0x2385, 0x41f2, 0xA2, 0x8E, 0x2C, 0x5C, 0x91, 0xFB, 0x56, 0xE0);

        public static readonly Guid FOLDERTYPEID_StorageProviderDocuments__scanned__ = new Guid(0xDD61BD66, 0x70E8, 0x48dd, 0x96, 0x55, 0x65, 0xC5, 0xE1, 0xAA, 0xC2, 0xD1);

        public static readonly Guid FOLDERTYPEID_StorageProviderPictures__scanned__ = new Guid(0x71d642a9, 0xf2b1, 0x42cd, 0xad, 0x92, 0xeb, 0x93, 0x0, 0xc7, 0xcc, 0xa);

        public static readonly Guid FOLDERTYPEID_StorageProviderMusic__scanned__ = new Guid(0x672ECD7E, 0xAF04, 0x4399, 0x87, 0x5C, 0x02, 0x90, 0x84, 0x5B, 0x62, 0x47);

        public static readonly Guid FOLDERTYPEID_StorageProviderVideos__scanned__ = new Guid(0x51294DA1, 0xD7B1, 0x485b, 0x9E, 0x9A, 0x17, 0xCF, 0xFE, 0x33, 0xE1, 0x87);

        public static readonly Guid SYNCMGR_OBJECTID_Icon__scanned__ = new Guid(0x6dbc85c3, 0x5d07, 0x4c72, 0xa7, 0x77, 0x7f, 0xec, 0x78, 0x7, 0x2c, 0x6);

        public static readonly Guid SYNCMGR_OBJECTID_EventStore__scanned__ = new Guid(0x4bef34b9, 0xa786, 0x4075, 0xba, 0x88, 0xc, 0x2b, 0x9d, 0x89, 0xa9, 0x8f);

        public static readonly Guid SYNCMGR_OBJECTID_ConflictStore__scanned__ = new Guid(0xd78181f4, 0x2389, 0x47e4, 0xa9, 0x60, 0x60, 0xbc, 0xc2, 0xed, 0x93, 0xb);

        public static readonly Guid SYNCMGR_OBJECTID_BrowseContent__scanned__ = new Guid(0x57cbb584, 0xe9b4, 0x47ae, 0xa1, 0x20, 0xc4, 0xdf, 0x33, 0x35, 0xde, 0xe2);

        public static readonly Guid SYNCMGR_OBJECTID_ShowSchedule__scanned__ = new Guid(0xedc6f3e3, 0x8441, 0x4109, 0xad, 0xf3, 0x6c, 0x1c, 0xa0, 0xb7, 0xde, 0x47);

        public static readonly Guid SYNCMGR_OBJECTID_QueryBeforeActivate__scanned__ = new Guid(0xd882d80b, 0xe7aa, 0x49ed, 0x86, 0xb7, 0xe6, 0xe1, 0xf7, 0x14, 0xcd, 0xfe);

        public static readonly Guid SYNCMGR_OBJECTID_QueryBeforeDeactivate__scanned__ = new Guid(0xa0efc282, 0x60e0, 0x460e, 0x93, 0x74, 0xea, 0x88, 0x51, 0x3c, 0xfc, 0x80);

        public static readonly Guid SYNCMGR_OBJECTID_QueryBeforeEnable__scanned__ = new Guid(0x4cbf7f0, 0x5beb, 0x4de1, 0xbc, 0x90, 0x90, 0x83, 0x45, 0xc4, 0x80, 0xf6);

        public static readonly Guid SYNCMGR_OBJECTID_QueryBeforeDisable__scanned__ = new Guid(0xbb5f64aa, 0xf004, 0x4eb5, 0x8e, 0x4d, 0x26, 0x75, 0x19, 0x66, 0x34, 0x4c);

        public static readonly Guid SYNCMGR_OBJECTID_QueryBeforeDelete__scanned__ = new Guid(0xf76c3397, 0xafb3, 0x45d7, 0xa5, 0x9f, 0x5a, 0x49, 0xe9, 0x5, 0x43, 0x7e);

        public static readonly Guid SYNCMGR_OBJECTID_EventLinkClick__scanned__ = new Guid(0x2203bdc1, 0x1af1, 0x4082, 0x8c, 0x30, 0x28, 0x39, 0x9f, 0x41, 0x38, 0x4c);

        public static readonly Guid EP_NavPane__scanned__ = new Guid(0xcb316b22, 0x25f7, 0x42b8, 0x8a, 0x09, 0x54, 0x0d, 0x23, 0xa4, 0x3c, 0x2f);

        public static readonly Guid EP_Commands__scanned__ = new Guid(0xd9745868, 0xca5f, 0x4a76, 0x91, 0xcd, 0xf5, 0xa1, 0x29, 0xfb, 0xb0, 0x76);

        public static readonly Guid EP_Commands_Organize__scanned__ = new Guid(0x72e81700, 0xe3ec, 0x4660, 0xbf, 0x24, 0x3c, 0x3b, 0x7b, 0x64, 0x88, 0x06);

        public static readonly Guid EP_Commands_View__scanned__ = new Guid(0x21f7c32d, 0xeeaa, 0x439b, 0xbb, 0x51, 0x37, 0xb9, 0x6f, 0xd6, 0xa9, 0x43);

        public static readonly Guid EP_DetailsPane__scanned__ = new Guid(0x43abf98b, 0x89b8, 0x472d, 0xb9, 0xce, 0xe6, 0x9b, 0x82, 0x29, 0xf0, 0x19);

        public static readonly Guid EP_PreviewPane__scanned__ = new Guid(0x893c63d1, 0x45c8, 0x4d17, 0xbe, 0x19, 0x22, 0x3b, 0xe7, 0x1b, 0xe3, 0x65);

        public static readonly Guid EP_QueryPane__scanned__ = new Guid(0x65bcde4f, 0x4f07, 0x4f27, 0x83, 0xa7, 0x1a, 0xfc, 0xa4, 0xdf, 0x7d, 0xdd);

        public static readonly Guid EP_AdvQueryPane__scanned__ = new Guid(0xb4e9db8b, 0x34ba, 0x4c39, 0xb5, 0xcc, 0x16, 0xa1, 0xbd, 0x2c, 0x41, 0x1c);

        public static readonly Guid EP_StatusBar__scanned__ = new Guid(0x65fe56ce, 0x5cfe, 0x4bc4, 0xad, 0x8a, 0x7a, 0xe3, 0xfe, 0x7e, 0x8f, 0x7c);

        public static readonly Guid EP_Ribbon__scanned__ = new Guid(0xd27524a8, 0xc9f2, 0x4834, 0xa1, 0x6, 0xdf, 0x88, 0x89, 0xfd, 0x4f, 0x37);

        public static readonly Guid CATID_LocationFactory__scanned__ = new Guid(0x965c4d51, 0x8b76, 0x4e57, 0x80, 0xb7, 0x56, 0x4d, 0x2e, 0xa4, 0xb5, 0x5e);

        public static readonly Guid CATID_LocationProvider__scanned__ = new Guid(0x1b3ca474, 0x2614, 0x414b, 0xb8, 0x13, 0x1a, 0xce, 0xca, 0x3e, 0x3d, 0xd8);

        public static readonly Guid ItemCount_Property_GUID__scanned__ = new Guid(0xabbf5c45, 0x5ccc, 0x47b7, 0xbb, 0x4e, 0x87, 0xcb, 0x87, 0xbb, 0xd1, 0x62);

        public static readonly Guid SelectedItemCount_Property_GUID__scanned__ = new Guid(0x8fe316d2, 0xe52, 0x460a, 0x9c, 0x1e, 0x48, 0xf2, 0x73, 0xd4, 0x70, 0xa3);

        public static readonly Guid ItemIndex_Property_GUID__scanned__ = new Guid(0x92a053da, 0x2969, 0x4021, 0xbf, 0x27, 0x51, 0x4c, 0xfc, 0x2e, 0x4a, 0x69);

        public static readonly Guid CATID_SearchableApplication__scanned__ = new Guid(0x366c292a, 0xd9b3, 0x4dbf, 0xbb, 0x70, 0xe6, 0x2e, 0xc3, 0xd0, 0xbb, 0xbf);

        public const uint IDD_WIZEXTN_FIRST = 0x5000;

        public const uint IDD_WIZEXTN_LAST = 0x5100;

        public const uint SHPWHF_NORECOMPRESS = 0x00000001;

        public const uint SHPWHF_NONETPLACECREATE = 0x00000002;

        public const uint SHPWHF_NOFILESELECTOR = 0x00000004;

        public const uint SHPWHF_USEMRU = 0x00000008;

        public const uint SHPWHF_ANYLOCATION = 0x00000100;

        public const uint SHPWHF_VALIDATEVIAWEBFOLDERS = 0x00010000;

        public const uint ACDD_VISIBLE = 0x0001;

        public static readonly Guid SID_SCommandBarState__scanned__ = new Guid(0xB99EAA5C, 0x3850, 0x4400, 0xBC, 0x33, 0x2C, 0xE5, 0x34, 0x04, 0x8B, 0xF8);

        public const int NSTCDHPOS_ONTOP = -1;

        public const uint FVSIF_RECT = 0x00000001;

        public const uint FVSIF_PINNED = 0x00000002;

        public const uint FVSIF_NEWFAILED = 0x08000000;

        public const uint FVSIF_NEWFILE = 0x80000000;

        public const uint FVSIF_CANVIEWIT = 0x40000000;

        public const uint FCIDM_TOOLBAR = FCIDM_BROWSERFIRST + 0;

        public const uint FCIDM_STATUS = FCIDM_BROWSERFIRST + 1;

        public const uint IDC_OFFLINE_HAND = 103;

        public const uint IDC_PANTOOL_HAND_OPEN = 104;

        public const uint IDC_PANTOOL_HAND_CLOSED = 105;

        public const uint PANE_NONE = 0xFFFFFFFF;

        public const uint PANE_ZONE = 1;

        public const uint PANE_OFFLINE = 2;

        public const uint PANE_PRINTER = 3;

        public const uint PANE_SSL = 4;

        public const uint PANE_NAVIGATION = 5;

        public const uint PANE_PROGRESS = 6;

        public const uint PANE_PRIVACY = 7;

        public const uint DWFRF_NORMAL = 0x0000;

        public const uint DWFRF_DELETECONFIGDATA = 0x0001;

        public const uint DWFAF_HIDDEN = 0x0001;

        public const uint DWFAF_GROUP1 = 0x0002;

        public const uint DWFAF_GROUP2 = 0x0004;

        public const uint DWFAF_AUTOHIDE = 0x0010;

        public const uint SHIMSTCAPFLAG_LOCKABLE = 0x0001;

        public const uint SHIMSTCAPFLAG_PURGEABLE = 0x0002;

        public const uint ISFB_MASK_STATE = 0x00000001;

        public const uint ISFB_MASK_BKCOLOR = 0x00000002;

        public const uint ISFB_MASK_VIEWMODE = 0x00000004;

        public const uint ISFB_MASK_SHELLFOLDER = 0x00000008;

        public const uint ISFB_MASK_IDLIST = 0x00000010;

        public const uint ISFB_MASK_COLORS = 0x00000020;

        public const uint ISFB_STATE_DEFAULT = 0x00000000;

        public const uint ISFB_STATE_DEBOSSED = 0x00000001;

        public const uint ISFB_STATE_ALLOWRENAME = 0x00000002;

        public const uint ISFB_STATE_NOSHOWTEXT = 0x00000004;

        public const uint ISFB_STATE_CHANNELBAR = 0x00000010;

        public const uint ISFB_STATE_QLINKSMODE = 0x00000020;

        public const uint ISFB_STATE_FULLOPEN = 0x00000040;

        public const uint ISFB_STATE_NONAMESORT = 0x00000080;

        public const uint ISFB_STATE_BTNMINSIZE = 0x00000100;

        public const uint ISFBVIEWMODE_SMALLICONS = 0x0001;

        public const uint ISFBVIEWMODE_LARGEICONS = 0x0002;

        public const uint ISFBVIEWMODE_LOGOS = 0x0003;

        public const uint DBC_GS_IDEAL = 0;

        public const uint DBC_GS_SIZEDOWN = 1;

        public const uint DBC_HIDE = 0;

        public const uint DBC_SHOW = 1;

        public const uint DBC_SHOWOBSCURE = 2;

        public const uint SSM_CLEAR = 0x0000;

        public const uint SSM_SET = 0x0001;

        public const uint SSM_REFRESH = 0x0002;

        public const uint SSM_UPDATE = 0x0004;

        public const uint SCHEME_DISPLAY = 0x0001;

        public const uint SCHEME_EDIT = 0x0002;

        public const uint SCHEME_LOCAL = 0x0004;

        public const uint SCHEME_GLOBAL = 0x0008;

        public const uint SCHEME_REFRESH = 0x0010;

        public const uint SCHEME_UPDATE = 0x0020;

        public const uint SCHEME_DONOTUSE = 0x0040;

        public const uint SCHEME_CREATE = 0x0080;

        public const uint GADOF_DIRTY = 0x00000001;

        public const uint SHCDF_UPDATEITEM = 0x00000001;

        public const uint PPCF_ADDQUOTES = 0x00000001;

        public const uint PPCF_ADDARGUMENTS = 0x00000003;

        public const uint PPCF_NODIRECTORIES = 0x00000010;

        public const uint PPCF_FORCEQUALIFY = 0x00000040;

        public const uint PPCF_LONGESTPOSSIBLE = 0x00000080;

        public const uint OPENPROPS_NONE = 0x0000;

        public const uint OPENPROPS_INHIBITPIF = 0x8000;

        public const uint GETPROPS_NONE = 0x0000;

        public const uint SETPROPS_NONE = 0x0000;

        public const uint CLOSEPROPS_NONE = 0x0000;

        public const uint CLOSEPROPS_DISCARD = 0x0001;

        public const uint TBIF_APPEND = 0;

        public const uint TBIF_PREPEND = 1;

        public const uint TBIF_REPLACE = 2;

        public const uint TBIF_DEFAULT = 0x00000000;

        public const uint TBIF_INTERNETBAR = 0x00010000;

        public const uint TBIF_STANDARDTOOLBAR = 0x00020000;

        public const uint TBIF_NOTOOLBAR = 0x00030000;

        public const uint SFVM_REARRANGE = 0x00000001;

        public const uint SFVM_ADDOBJECT = 0x00000003;

        public const uint SFVM_REMOVEOBJECT = 0x00000006;

        public const uint SFVM_UPDATEOBJECT = 0x00000007;

        public const uint SFVM_GETSELECTEDOBJECTS = 0x00000009;

        public const uint SFVM_SETITEMPOS = 0x0000000e;

        public const uint SFVM_SETCLIPBOARD = 0x00000010;

        public const uint SFVM_SETPOINTS = 0x00000017;

        public const uint GIL_OPENICON = 0x0001;

        public const uint GIL_FORSHELL = 0x0002;

        public const uint GIL_ASYNC = 0x0020;

        public const uint GIL_DEFAULTICON = 0x0040;

        public const uint GIL_FORSHORTCUT = 0x0080;

        public const uint GIL_CHECKSHIELD = 0x0200;

        public const uint GIL_SIMULATEDOC = 0x0001;

        public const uint GIL_PERINSTANCE = 0x0002;

        public const uint GIL_PERCLASS = 0x0004;

        public const uint GIL_NOTFILENAME = 0x0008;

        public const uint GIL_DONTCACHE = 0x0010;

        public const uint GIL_SHIELD = 0x0200;

        public const uint GIL_FORCENOSHIELD = 0x0400;

        public const uint SIOM_OVERLAYINDEX = 0x1;

        public const uint SIOM_ICONINDEX = 0x2;

        public const uint SIOM_RESERVED_SHARED = 0;

        public const uint SIOM_RESERVED_LINK = 1;

        public const uint SIOM_RESERVED_SLOWFILE = 2;

        public const uint SIOM_RESERVED_DEFAULT = 3;

        public const uint OI_DEFAULT = 0x00000000;

        public const uint OI_ASYNC = 0xFFFFEEEE;

        public const uint IDO_SHGIOI_SHARE = 0x0FFFFFFF;

        public const uint IDO_SHGIOI_LINK = 0x0FFFFFFE;

        public const ulong IDO_SHGIOI_SLOWFILE = 0x0FFFFFFFD;

        public const ulong IDO_SHGIOI_DEFAULT = 0x0FFFFFFFC;

        public const uint NT_CONSOLE_PROPS_SIG = 0xA0000002;

        public const uint NT_FE_CONSOLE_PROPS_SIG = 0xA0000004;

        public const uint EXP_DARWIN_ID_SIG = 0xA0000006;

        public const uint EXP_SPECIAL_FOLDER_SIG = 0xA0000005;

        public const uint EXP_SZ_LINK_SIG = 0xA0000001;

        public const uint EXP_SZ_ICON_SIG = 0xA0000007;

        public const uint EXP_PROPERTYSTORAGE_SIG = 0xA0000009;

        public const uint FCIDM_SHVIEWFIRST = 0x0000;

        public const uint FCIDM_SHVIEWLAST = 0x7fff;

        public const uint FCIDM_BROWSERFIRST = 0xa000;

        public const uint FCIDM_BROWSERLAST = 0xbf00;

        public const uint FCIDM_GLOBALFIRST = 0x8000;

        public const uint FCIDM_GLOBALLAST = 0x9fff;

        public const uint FCIDM_MENU_FILE = FCIDM_GLOBALFIRST+0x0000;

        public const uint FCIDM_MENU_EDIT = FCIDM_GLOBALFIRST+0x0040;

        public const uint FCIDM_MENU_VIEW = FCIDM_GLOBALFIRST+0x0080;

        public const uint FCIDM_MENU_VIEW_SEP_OPTIONS = FCIDM_GLOBALFIRST+0x0081;

        public const uint FCIDM_MENU_TOOLS = FCIDM_GLOBALFIRST+0x00c0;

        public const uint FCIDM_MENU_TOOLS_SEP_GOTO = FCIDM_GLOBALFIRST+0x00c1;

        public const uint FCIDM_MENU_HELP = FCIDM_GLOBALFIRST+0x0100;

        public const uint FCIDM_MENU_FIND = FCIDM_GLOBALFIRST+0x0140;

        public const uint FCIDM_MENU_EXPLORE = FCIDM_GLOBALFIRST+0x0150;

        public const uint FCIDM_MENU_FAVORITES = FCIDM_GLOBALFIRST+0x0170;

        public const uint OFASI_EDIT = 0x0001;

        public const uint OFASI_OPENDESKTOP = 0x0002;

        public const uint CSIDL_DESKTOP = 0x0000;

        public const uint CSIDL_INTERNET = 0x0001;

        public const uint CSIDL_PROGRAMS = 0x0002;

        public const uint CSIDL_CONTROLS = 0x0003;

        public const uint CSIDL_PRINTERS = 0x0004;

        public const uint CSIDL_PERSONAL = 0x0005;

        public const uint CSIDL_FAVORITES = 0x0006;

        public const uint CSIDL_STARTUP = 0x0007;

        public const uint CSIDL_RECENT = 0x0008;

        public const uint CSIDL_SENDTO = 0x0009;

        public const uint CSIDL_BITBUCKET = 0x000a;

        public const uint CSIDL_STARTMENU = 0x000b;

        public const uint CSIDL_MYMUSIC = 0x000d;

        public const uint CSIDL_MYVIDEO = 0x000e;

        public const uint CSIDL_DESKTOPDIRECTORY = 0x0010;

        public const uint CSIDL_DRIVES = 0x0011;

        public const uint CSIDL_NETWORK = 0x0012;

        public const uint CSIDL_NETHOOD = 0x0013;

        public const uint CSIDL_FONTS = 0x0014;

        public const uint CSIDL_TEMPLATES = 0x0015;

        public const uint CSIDL_COMMON_STARTMENU = 0x0016;

        public const uint CSIDL_COMMON_PROGRAMS = 0X0017;

        public const uint CSIDL_COMMON_STARTUP = 0x0018;

        public const uint CSIDL_COMMON_DESKTOPDIRECTORY = 0x0019;

        public const uint CSIDL_APPDATA = 0x001a;

        public const uint CSIDL_PRINTHOOD = 0x001b;

        public const uint CSIDL_LOCAL_APPDATA = 0x001c;

        public const uint CSIDL_ALTSTARTUP = 0x001d;

        public const uint CSIDL_COMMON_ALTSTARTUP = 0x001e;

        public const uint CSIDL_COMMON_FAVORITES = 0x001f;

        public const uint CSIDL_INTERNET_CACHE = 0x0020;

        public const uint CSIDL_COOKIES = 0x0021;

        public const uint CSIDL_HISTORY = 0x0022;

        public const uint CSIDL_COMMON_APPDATA = 0x0023;

        public const uint CSIDL_WINDOWS = 0x0024;

        public const uint CSIDL_SYSTEM = 0x0025;

        public const uint CSIDL_PROGRAM_FILES = 0x0026;

        public const uint CSIDL_MYPICTURES = 0x0027;

        public const uint CSIDL_PROFILE = 0x0028;

        public const uint CSIDL_SYSTEMX86 = 0x0029;

        public const uint CSIDL_PROGRAM_FILESX86 = 0x002a;

        public const uint CSIDL_PROGRAM_FILES_COMMON = 0x002b;

        public const uint CSIDL_PROGRAM_FILES_COMMONX86 = 0x002c;

        public const uint CSIDL_COMMON_TEMPLATES = 0x002d;

        public const uint CSIDL_COMMON_DOCUMENTS = 0x002e;

        public const uint CSIDL_COMMON_ADMINTOOLS = 0x002f;

        public const uint CSIDL_ADMINTOOLS = 0x0030;

        public const uint CSIDL_CONNECTIONS = 0x0031;

        public const uint CSIDL_COMMON_MUSIC = 0x0035;

        public const uint CSIDL_COMMON_PICTURES = 0x0036;

        public const uint CSIDL_COMMON_VIDEO = 0x0037;

        public const uint CSIDL_RESOURCES = 0x0038;

        public const uint CSIDL_RESOURCES_LOCALIZED = 0x0039;

        public const uint CSIDL_COMMON_OEM_LINKS = 0x003a;

        public const uint CSIDL_CDBURN_AREA = 0x003b;

        public const uint CSIDL_COMPUTERSNEARME = 0x003d;

        public const uint CSIDL_FLAG_CREATE = 0x8000;

        public const uint CSIDL_FLAG_DONT_VERIFY = 0x4000;

        public const uint CSIDL_FLAG_DONT_UNEXPAND = 0x2000;

        public const uint CSIDL_FLAG_NO_ALIAS = 0x1000;

        public const uint CSIDL_FLAG_PER_USER_INIT = 0x0800;

        public const uint CSIDL_FLAG_MASK = 0xFF00;

        public const uint FCS_READ = 0x00000001;

        public const uint FCS_FORCEWRITE = 0x00000002;

        public const uint FCS_FLAG_DRAGDROP = 2;

        public const uint FCSM_VIEWID = 0x00000001;

        public const uint FCSM_WEBVIEWTEMPLATE = 0x00000002;

        public const uint FCSM_INFOTIP = 0x00000004;

        public const uint FCSM_CLSID = 0x00000008;

        public const uint FCSM_ICONFILE = 0x00000010;

        public const uint FCSM_LOGO = 0x00000020;

        public const uint FCSM_FLAGS = 0x00000040;

        public const uint BIF_RETURNONLYFSDIRS = 0x00000001;

        public const uint BIF_DONTGOBELOWDOMAIN = 0x00000002;

        public const uint BIF_STATUSTEXT = 0x00000004;

        public const uint BIF_RETURNFSANCESTORS = 0x00000008;

        public const uint BIF_EDITBOX = 0x00000010;

        public const uint BIF_VALIDATE = 0x00000020;

        public const uint BIF_NEWDIALOGSTYLE = 0x00000040;

        public const uint BIF_BROWSEINCLUDEURLS = 0x00000080;

        public const uint BIF_UAHINT = 0x00000100;

        public const uint BIF_NONEWFOLDERBUTTON = 0x00000200;

        public const uint BIF_NOTRANSLATETARGETS = 0x00000400;

        public const uint BIF_BROWSEFORCOMPUTER = 0x00001000;

        public const uint BIF_BROWSEFORPRINTER = 0x00002000;

        public const uint BIF_BROWSEINCLUDEFILES = 0x00004000;

        public const uint BIF_SHAREABLE = 0x00008000;

        public const uint BIF_BROWSEFILEJUNCTIONS = 0x00010000;

        public const uint BFFM_INITIALIZED = 1;

        public const uint BFFM_SELCHANGED = 2;

        public const uint BFFM_VALIDATEFAILEDA = 3;

        public const uint BFFM_VALIDATEFAILEDW = 4;

        public const uint BFFM_IUNKNOWN = 5;

        public const uint BFFM_SETSTATUSTEXTA = WM_USER + 100;

        public const uint BFFM_ENABLEOK = WM_USER + 101;

        public const uint BFFM_SETSELECTIONA = WM_USER + 102;

        public const uint BFFM_SETSELECTIONW = WM_USER + 103;

        public const uint BFFM_SETSTATUSTEXTW = WM_USER + 104;

        public const uint BFFM_SETOKTEXT = WM_USER + 105;

        public const uint BFFM_SETEXPANDED = WM_USER + 106;

        public const uint PROGDLG_NORMAL = 0x00000000;

        public const uint PROGDLG_MODAL = 0x00000001;

        public const uint PROGDLG_AUTOTIME = 0x00000002;

        public const uint PROGDLG_NOTIME = 0x00000004;

        public const uint PROGDLG_NOMINIMIZE = 0x00000008;

        public const uint PROGDLG_NOPROGRESSBAR = 0x00000010;

        public const uint PROGDLG_MARQUEEPROGRESS = 0x00000020;

        public const uint PROGDLG_NOCANCEL = 0x00000040;

        public const uint PDTIMER_RESET = 0x00000001;

        public const uint PDTIMER_PAUSE = 0x00000002;

        public const uint PDTIMER_RESUME = 0x00000003;

        public const uint COMPONENT_TOP = 0x3fffffff;

        public const uint COMP_TYPE_HTMLDOC = 0;

        public const uint COMP_TYPE_PICTURE = 1;

        public const uint COMP_TYPE_WEBSITE = 2;

        public const uint COMP_TYPE_CONTROL = 3;

        public const uint COMP_TYPE_CFHTML = 4;

        public const uint COMP_TYPE_MAX = 4;

        public const uint IS_NORMAL = 0x00000001;

        public const uint IS_FULLSCREEN = 0x00000002;

        public const uint IS_SPLIT = 0x00000004;

        public const uint AD_APPLY_SAVE = 0x00000001;

        public const uint AD_APPLY_HTMLGEN = 0x00000002;

        public const uint AD_APPLY_REFRESH = 0x00000004;

        public const uint AD_APPLY_FORCE = 0x00000008;

        public const uint AD_APPLY_BUFFERED_REFRESH = 0x00000010;

        public const uint AD_APPLY_DYNAMICREFRESH = 0x00000020;

        public const uint AD_GETWP_BMP = 0x00000000;

        public const uint AD_GETWP_IMAGE = 0x00000001;

        public const uint AD_GETWP_LAST_APPLIED = 0x00000002;

        public const uint WPSTYLE_CENTER = 0;

        public const uint WPSTYLE_TILE = 1;

        public const uint WPSTYLE_STRETCH = 2;

        public const uint WPSTYLE_KEEPASPECT = 3;

        public const uint WPSTYLE_CROPTOFIT = 4;

        public const uint WPSTYLE_SPAN = 5;

        public const uint WPSTYLE_MAX = 6;

        public const uint COMP_ELEM_TYPE = 0x00000001;

        public const uint COMP_ELEM_CHECKED = 0x00000002;

        public const uint COMP_ELEM_DIRTY = 0x00000004;

        public const uint COMP_ELEM_NOSCROLL = 0x00000008;

        public const uint COMP_ELEM_POS_LEFT = 0x00000010;

        public const uint COMP_ELEM_POS_TOP = 0x00000020;

        public const uint COMP_ELEM_SIZE_WIDTH = 0x00000040;

        public const uint COMP_ELEM_SIZE_HEIGHT = 0x00000080;

        public const uint COMP_ELEM_POS_ZINDEX = 0x00000100;

        public const uint COMP_ELEM_SOURCE = 0x00000200;

        public const uint COMP_ELEM_FRIENDLYNAME = 0x00000400;

        public const uint COMP_ELEM_SUBSCRIBEDURL = 0x00000800;

        public const uint COMP_ELEM_ORIGINAL_CSI = 0x00001000;

        public const uint COMP_ELEM_RESTORED_CSI = 0x00002000;

        public const uint COMP_ELEM_CURITEMSTATE = 0x00004000;

        public const uint ADDURL_SILENT = 0X0001;

        public const uint COMPONENT_DEFAULT_LEFT = 0xFFFF;

        public const uint COMPONENT_DEFAULT_TOP = 0xFFFF;

        public const uint MAX_COLUMN_NAME_LEN = 80;

        public const uint MAX_COLUMN_DESC_LEN = 128;

        public const uint DVASPECT_SHORTNAME = 2;

        public const uint DVASPECT_COPY = 3;

        public const uint DVASPECT_LINK = 4;

        public const int SHCNEE_ORDERCHANGED = 2;

        public const int SHCNEE_MSI_CHANGE = 4;

        public const int SHCNEE_MSI_UNINSTALL = 5;

        public const uint NUM_POINTS = 3;

        public const uint CABINETSTATE_VERSION = 2;

        public const uint PIFNAMESIZE = 30;

        public const uint PIFSTARTLOCSIZE = 63;

        public const uint PIFDEFPATHSIZE = 64;

        public const uint PIFPARAMSSIZE = 64;

        public const uint PIFSHPROGSIZE = 64;

        public const uint PIFSHDATASIZE = 64;

        public const uint PIFDEFFILESIZE = 80;

        public const uint PIFMAXFILEPATH = 260;

        public const uint QCMINFO_PLACE_BEFORE = 0;

        public const uint QCMINFO_PLACE_AFTER = 1;

        public const uint SFVSOC_INVALIDATE_ALL = 0x00000001;

        public const uint SHELLSTATEVERSION_IE4 = 9;

        public const uint SHELLSTATEVERSION_WIN2K = 10;

        public const uint SHPPFW_NONE = 0x00000000;

        public const uint SHPPFW_DIRCREATE = 0x00000001;

        public const uint SHPPFW_ASKDIRCREATE = 0x00000002;

        public const uint SHPPFW_IGNOREFILENAME = 0x00000004;

        public const uint SHPPFW_NOWRITECHECK = 0x00000008;

        public const uint SHPPFW_MEDIACHECKONLY = 0x00000010;

        public const uint CMF_NORMAL = 0x00000000;

        public const uint CMF_DEFAULTONLY = 0x00000001;

        public const uint CMF_VERBSONLY = 0x00000002;

        public const uint CMF_EXPLORE = 0x00000004;

        public const uint CMF_NOVERBS = 0x00000008;

        public const uint CMF_CANRENAME = 0x00000010;

        public const uint CMF_NODEFAULT = 0x00000020;

        public const uint CMF_INCLUDESTATIC = 0x00000040;

        public const uint CMF_ITEMMENU = 0x00000080;

        public const uint CMF_EXTENDEDVERBS = 0x00000100;

        public const uint CMF_DISABLEDVERBS = 0x00000200;

        public const uint CMF_ASYNCVERBSTATE = 0x00000400;

        public const uint CMF_OPTIMIZEFORINVOKE = 0x00000800;

        public const uint CMF_SYNCCASCADEMENU = 0x00001000;

        public const uint CMF_DONOTPICKDEFAULT = 0x00002000;

        public const uint CMF_RESERVED = 0xffff0000;

        public const uint GCS_VERBA = 0x00000000;

        public const uint GCS_HELPTEXTA = 0x00000001;

        public const uint GCS_VALIDATEA = 0x00000002;

        public const uint GCS_VERBW = 0x00000004;

        public const uint GCS_HELPTEXTW = 0x00000005;

        public const uint GCS_VALIDATEW = 0x00000006;

        public const uint GCS_VERBICONW = 0x00000014;

        public const uint GCS_UNICODE = 0x00000004;

        public const uint CMIC_MASK_SHIFT_DOWN = 0x10000000;

        public const uint CMIC_MASK_CONTROL_DOWN = 0x40000000;

        public const uint CMIC_MASK_PTINVOKE = 0x20000000;

        public const uint IRTIR_TASK_NOT_RUNNING = 0;

        public const uint IRTIR_TASK_RUNNING = 1;

        public const uint IRTIR_TASK_SUSPENDED = 2;

        public const uint IRTIR_TASK_PENDING = 3;

        public const uint IRTIR_TASK_FINISHED = 4;

        public const uint ITSAT_DEFAULT_PRIORITY = 0x10000000;

        public const uint ITSAT_MAX_PRIORITY = 0x7fffffff;

        public const uint ITSAT_MIN_PRIORITY = 0x00000000;

        public const uint ITSSFLAG_COMPLETE_ON_DESTROY = 0x0000;

        public const uint ITSSFLAG_KILL_ON_DESTROY = 0x0001;

        public const uint ITSSFLAG_FLAGS_MASK = 0x0003;

        public const int SHCIDS_ALLFIELDS = unchecked((int)0x80000000);

        public const int SHCIDS_CANONICALONLY = 0x10000000;

        public const int SHCIDS_BITMASK = unchecked((int)0xFFFF0000);

        public const int SHCIDS_COLUMNMASK = 0x0000FFFF;

        public const int SFGAO_STORAGE = 0x00000008;

        public const int SFGAO_CANRENAME = 0x00000010;

        public const int SFGAO_CANDELETE = 0x00000020;

        public const int SFGAO_HASPROPSHEET = 0x00000040;

        public const int SFGAO_DROPTARGET = 0x00000100;

        public const int SFGAO_CAPABILITYMASK = 0x00000177;

        public const int SFGAO_PLACEHOLDER = 0x00000800;

        public const int SFGAO_SYSTEM = 0x00001000;

        public const int SFGAO_ENCRYPTED = 0x00002000;

        public const int SFGAO_ISSLOW = 0x00004000;

        public const int SFGAO_GHOSTED = 0x00008000;

        public const int SFGAO_LINK = 0x00010000;

        public const int SFGAO_SHARE = 0x00020000;

        public const int SFGAO_READONLY = 0x00040000;

        public const int SFGAO_HIDDEN = 0x00080000;

        public const int SFGAO_DISPLAYATTRMASK = 0x000FC000;

        public const int SFGAO_FILESYSANCESTOR = 0x10000000;

        public const int SFGAO_FOLDER = 0x20000000;

        public const int SFGAO_FILESYSTEM = 0x40000000;

        public const int SFGAO_HASSUBFOLDER = unchecked((int)0x80000000);

        public const int SFGAO_CONTENTSMASK = unchecked((int)0x80000000);

        public const int SFGAO_VALIDATE = 0x01000000;

        public const int SFGAO_REMOVABLE = 0x02000000;

        public const int SFGAO_COMPRESSED = 0x04000000;

        public const int SFGAO_BROWSABLE = 0x08000000;

        public const int SFGAO_NONENUMERATED = 0x00100000;

        public const int SFGAO_NEWCONTENT = 0x00200000;

        public const int SFGAO_CANMONIKER = 0x00400000;

        public const int SFGAO_HASSTORAGE = 0x00400000;

        public const int SFGAO_STREAM = 0x00400000;

        public const int SFGAO_STORAGEANCESTOR = 0x00800000;

        public const int SFGAO_STORAGECAPMASK = 0x70C50008;

        public const int SFGAO_PKEYSFGAOMASK = unchecked((int)0x81044000);

        public const uint BIND_INTERRUPTABLE = 0xFFFFFFFF;

        public const uint CDBOSC_SETFOCUS = 0x00000000;

        public const uint CDBOSC_KILLFOCUS = 0x00000001;

        public const uint CDBOSC_SELCHANGE = 0x00000002;

        public const uint CDBOSC_RENAME = 0x00000003;

        public const uint CDBOSC_STATECHANGE = 0x00000004;

        public const uint CDB2N_CONTEXTMENU_DONE = 0x00000001;

        public const uint CDB2N_CONTEXTMENU_START = 0x00000002;

        public const uint CDB2GVF_SHOWALLFILES = 0x00000001;

        public const uint CDB2GVF_ISFILESAVE = 0x00000002;

        public const uint CDB2GVF_ALLOWPREVIEWPANE = 0x00000004;

        public const uint CDB2GVF_NOSELECTVERB = 0x00000008;

        public const uint CDB2GVF_NOINCLUDEITEM = 0x00000010;

        public const uint CDB2GVF_ISFOLDERPICKER = 0x00000020;

        public const uint CDB2GVF_ADDSHIELD = 0x00000040;

        public const uint SBSP_DEFBROWSER = 0x0000;

        public const uint SBSP_SAMEBROWSER = 0x0001;

        public const uint SBSP_NEWBROWSER = 0x0002;

        public const uint SBSP_DEFMODE = 0x0000;

        public const uint SBSP_OPENMODE = 0x0010;

        public const uint SBSP_EXPLOREMODE = 0x0020;

        public const uint SBSP_HELPMODE = 0x0040;

        public const uint SBSP_NOTRANSFERHIST = 0x0080;

        public const uint SBSP_ABSOLUTE = 0x0000;

        public const uint SBSP_RELATIVE = 0x1000;

        public const uint SBSP_PARENT = 0x2000;

        public const uint SBSP_NAVIGATEBACK = 0x4000;

        public const uint SBSP_NAVIGATEFORWARD = 0x8000;

        public const uint SBSP_ALLOW_AUTONAVIGATE = 0x00010000;

        public const uint SBSP_KEEPSAMETEMPLATE = 0x00020000;

        public const uint SBSP_KEEPWORDWHEELTEXT = 0x00040000;

        public const uint SBSP_ACTIVATE_NOFOCUS = 0x00080000;

        public const uint SBSP_CREATENOHISTORY = 0x00100000;

        public const uint SBSP_PLAYNOSOUND = 0x00200000;

        public const uint SBSP_CALLERUNTRUSTED = 0x00800000;

        public const uint SBSP_TRUSTFIRSTDOWNLOAD = 0x01000000;

        public const uint SBSP_UNTRUSTEDFORDOWNLOAD = 0x02000000;

        public const uint SBSP_NOAUTOSELECT = 0x04000000;

        public const uint SBSP_WRITENOHISTORY = 0x08000000;

        public const uint SBSP_TRUSTEDFORACTIVEX = 0x10000000;

        public const uint SBSP_FEEDNAVIGATION = 0x20000000;

        public const uint SBSP_REDIRECT = 0x40000000;

        public const uint SBSP_INITIATEDBYHLINKFRAME = 0x80000000;

        public const uint FCW_STATUS = 0x0001;

        public const uint FCW_TOOLBAR = 0x0002;

        public const uint FCW_TREE = 0x0003;

        public const uint FCW_INTERNETBAR = 0x0006;

        public const uint FCW_PROGRESS = 0x0008;

        public const uint FCT_MERGE = 0x0001;

        public const uint FCT_CONFIGABLE = 0x0002;

        public const uint FCT_ADDTOEND = 0x0004;

        public const uint ARCONTENT_AUTORUNINF = 0x00000002;

        public const uint ARCONTENT_AUDIOCD = 0x00000004;

        public const uint ARCONTENT_DVDMOVIE = 0x00000008;

        public const uint ARCONTENT_BLANKCD = 0x00000010;

        public const uint ARCONTENT_BLANKDVD = 0x00000020;

        public const uint ARCONTENT_UNKNOWNCONTENT = 0x00000040;

        public const uint ARCONTENT_AUTOPLAYPIX = 0x00000080;

        public const uint ARCONTENT_AUTOPLAYMUSIC = 0x00000100;

        public const uint ARCONTENT_AUTOPLAYVIDEO = 0x00000200;

        public const uint ARCONTENT_VCD = 0x00000400;

        public const uint ARCONTENT_SVCD = 0x00000800;

        public const uint ARCONTENT_DVDAUDIO = 0x00001000;

        public const uint ARCONTENT_BLANKBD = 0x00002000;

        public const uint ARCONTENT_BLURAY = 0x00004000;

        public const uint ARCONTENT_CAMERASTORAGE = 0x00008000;

        public const uint ARCONTENT_CUSTOMEVENT = 0x00010000;

        public const uint ARCONTENT_NONE = 0x00000000;

        public const uint ARCONTENT_MASK = 0x0001FFFE;

        public const uint ARCONTENT_PHASE_UNKNOWN = 0x00000000;

        public const uint ARCONTENT_PHASE_PRESNIFF = 0x10000000;

        public const uint ARCONTENT_PHASE_SNIFFING = 0x20000000;

        public const uint ARCONTENT_PHASE_FINAL = 0x40000000;

        public const uint ARCONTENT_PHASE_MASK = 0x70000000;

        public const uint IEIFLAG_ASYNC = 0x0001;

        public const uint IEIFLAG_CACHE = 0x0002;

        public const uint IEIFLAG_ASPECT = 0x0004;

        public const uint IEIFLAG_OFFLINE = 0x0008;

        public const uint IEIFLAG_GLEAM = 0x0010;

        public const uint IEIFLAG_SCREEN = 0x0020;

        public const uint IEIFLAG_ORIGSIZE = 0x0040;

        public const uint IEIFLAG_NOSTAMP = 0x0080;

        public const uint IEIFLAG_NOBORDER = 0x0100;

        public const uint IEIFLAG_QUALITY = 0x0200;

        public const uint IEIFLAG_REFRESH = 0x0400;

        public const uint DBIM_MINSIZE = 0x0001;

        public const uint DBIM_MAXSIZE = 0x0002;

        public const uint DBIM_INTEGRAL = 0x0004;

        public const uint DBIM_ACTUAL = 0x0008;

        public const uint DBIM_TITLE = 0x0010;

        public const uint DBIM_MODEFLAGS = 0x0020;

        public const uint DBIM_BKCOLOR = 0x0040;

        public const uint DBIMF_NORMAL = 0x0000;

        public const uint DBIMF_FIXED = 0x0001;

        public const uint DBIMF_FIXEDBMP = 0x0004;

        public const uint DBIMF_VARIABLEHEIGHT = 0x0008;

        public const uint DBIMF_UNDELETEABLE = 0x0010;

        public const uint DBIMF_DEBOSSED = 0x0020;

        public const uint DBIMF_BKCOLOR = 0x0040;

        public const uint DBIMF_USECHEVRON = 0x0080;

        public const uint DBIMF_BREAK = 0x0100;

        public const uint DBIMF_ADDTOFRONT = 0x0200;

        public const uint DBIMF_TOPALIGN = 0x0400;

        public const uint DBIMF_NOGRIPPER = 0x0800;

        public const uint DBIMF_ALWAYSGRIPPER = 0x1000;

        public const uint DBIMF_NOMARGINS = 0x2000;

        public const uint DBIF_VIEWMODE_NORMAL = 0x0000;

        public const uint DBIF_VIEWMODE_VERTICAL = 0x0001;

        public const uint DBIF_VIEWMODE_FLOATING = 0x0002;

        public const uint DBIF_VIEWMODE_TRANSPARENT = 0x0004;

        public const uint DBPC_SELECTFIRST = 0xFFFFFFFF;

        public const uint THBN_CLICKED = 0x1800;

        public const uint FOFX_NOSKIPJUNCTIONS = 0x00010000;

        public const uint FOFX_PREFERHARDLINK = 0x00020000;

        public const uint FOFX_SHOWELEVATIONPROMPT = 0x00040000;

        public const uint FOFX_RECYCLEONDELETE = 0x00080000;

        public const uint FOFX_EARLYFAILURE = 0x00100000;

        public const uint FOFX_PRESERVEFILEEXTENSIONS = 0x00200000;

        public const uint FOFX_KEEPNEWERFILE = 0x00400000;

        public const uint FOFX_NOCOPYHOOKS = 0x00800000;

        public const uint FOFX_NOMINIMIZEBOX = 0x01000000;

        public const uint FOFX_MOVEACLSACROSSVOLUMES = 0x02000000;

        public const uint FOFX_DONTDISPLAYSOURCEPATH = 0x04000000;

        public const uint FOFX_DONTDISPLAYDESTPATH = 0x08000000;

        public const uint FOFX_REQUIREELEVATION = 0x10000000;

        public const uint FOFX_ADDUNDORECORD = 0x20000000;

        public const uint FOFX_COPYASDOWNLOAD = 0x40000000;

        public const uint FOFX_DONTDISPLAYLOCATIONS = 0x80000000;

        public const uint BSIM_STATE = 0x00000001;

        public const uint BSIM_STYLE = 0x00000002;

        public const uint BSSF_VISIBLE = 0x00000001;

        public const uint BSSF_NOTITLE = 0x00000002;

        public const uint BSSF_UNDELETEABLE = 0x00001000;

        public const uint BSIS_AUTOGRIPPER = 0x00000000;

        public const uint BSIS_NOGRIPPER = 0x00000001;

        public const uint BSIS_ALWAYSGRIPPER = 0x00000002;

        public const uint BSIS_LEFTALIGN = 0x00000004;

        public const uint BSIS_SINGLECLICK = 0x00000008;

        public const uint BSIS_NOCONTEXTMENU = 0x00000010;

        public const uint BSIS_NODROPTARGET = 0x00000020;

        public const uint BSIS_NOCAPTION = 0x00000040;

        public const uint BSIS_PREFERNOLINEBREAK = 0x00000080;

        public const uint BSIS_LOCKED = 0x00000100;

        public const uint BSIS_PRESERVEORDERDURINGLAYOUT = 0x00000200;

        public const uint BSIS_FIXEDORDER = 0x00000400;

        public const uint OF_CAP_CANSWITCHTO = 0x0001;

        public const uint OF_CAP_CANCLOSE = 0x0002;

        public const uint SMDM_SHELLFOLDER = 0x00000001;

        public const uint SMDM_HMENU = 0x00000002;

        public const uint SMDM_TOOLBAR = 0x00000004;

        public const uint SMC_INITMENU = 0x00000001;

        public const uint SMC_CREATE = 0x00000002;

        public const uint SMC_EXITMENU = 0x00000003;

        public const uint SMC_GETINFO = 0x00000005;

        public const uint SMC_GETSFINFO = 0x00000006;

        public const uint SMC_GETOBJECT = 0x00000007;

        public const uint SMC_GETSFOBJECT = 0x00000008;

        public const uint SMC_SFEXEC = 0x00000009;

        public const uint SMC_SFSELECTITEM = 0x0000000A;

        public const uint SMC_REFRESH = 0x00000010;

        public const uint SMC_DEMOTE = 0x00000011;

        public const uint SMC_PROMOTE = 0x00000012;

        public const uint SMC_DEFAULTICON = 0x00000016;

        public const uint SMC_NEWITEM = 0x00000017;

        public const uint SMC_CHEVRONEXPAND = 0x00000019;

        public const uint SMC_DISPLAYCHEVRONTIP = 0x0000002A;

        public const uint SMC_SETSFOBJECT = 0x0000002D;

        public const uint SMC_SHCHANGENOTIFY = 0x0000002E;

        public const uint SMC_CHEVRONGETTIP = 0x0000002F;

        public const uint SMC_SFDDRESTRICTED = 0x00000030;

        public const uint SMC_SFEXEC_MIDDLE = 0x00000031;

        public const uint SMC_GETAUTOEXPANDSTATE = 0x00000041;

        public const uint SMC_AUTOEXPANDCHANGE = 0x00000042;

        public const uint SMC_GETCONTEXTMENUMODIFIER = 0x00000043;

        public const uint SMC_GETBKCONTEXTMENU = 0x00000044;

        public const uint SMC_OPEN = 0x00000045;

        public const uint SMAE_EXPANDED = 0x00000001;

        public const uint SMAE_CONTRACTED = 0x00000002;

        public const uint SMAE_USER = 0x00000004;

        public const uint SMAE_VALID = 0x00000007;

        public const uint SMINIT_DEFAULT = 0x00000000;

        public const uint SMINIT_RESTRICT_DRAGDROP = 0x00000002;

        public const uint SMINIT_TOPLEVEL = 0x00000004;

        public const uint SMINIT_CACHED = 0x00000010;

        public const uint SMINIT_AUTOEXPAND = 0x00000100;

        public const uint SMINIT_AUTOTOOLTIP = 0x00000200;

        public const uint SMINIT_DROPONCONTAINER = 0x00000400;

        public const uint SMINIT_VERTICAL = 0x10000000;

        public const uint SMINIT_HORIZONTAL = 0x20000000;

        public const uint SMSET_TOP = 0x10000000;

        public const uint SMSET_BOTTOM = 0x20000000;

        public const uint SMSET_DONTOWN = 0x00000001;

        public const uint SMINV_REFRESH = 0x00000001;

        public const uint SMINV_ID = 0x00000008;

        [NativeTypeName("HRESULT")]
        public const int E_PREVIEWHANDLER_DRM_FAIL = unchecked((int)0x86420001);

        [NativeTypeName("HRESULT")]
        public const int E_PREVIEWHANDLER_NOAUTH = unchecked((int)0x86420002);

        [NativeTypeName("HRESULT")]
        public const int E_PREVIEWHANDLER_NOTFOUND = unchecked((int)0x86420003);

        [NativeTypeName("HRESULT")]
        public const int E_PREVIEWHANDLER_CORRUPT = unchecked((int)0x86420004);

        public static readonly Guid SID_URLExecutionContext__scanned__ = new Guid(0xFB5F8EBC, 0xBBB6, 0x4D10, 0xA4, 0x61, 0x77, 0x72, 0x91, 0xA0, 0x90, 0x30);

        public static readonly Guid SID_LaunchSourceViewSizePreference__scanned__ = new Guid(0x80605492, 0x67d9, 0x414f, 0xaf, 0x89, 0xa1, 0xcd, 0xf1, 0x24, 0x2b, 0xc1);

        public static readonly Guid SID_LaunchTargetViewSizePreference__scanned__ = new Guid(0x26db2472, 0xb7b7, 0x406b, 0x97, 0x2, 0x73, 0xa, 0x4e, 0x20, 0xd3, 0xbf);

        public static readonly Guid SID_LaunchSourceAppUserModelId__scanned__ = new Guid(0x2ce78010, 0x74db, 0x48bc, 0x9c, 0x6a, 0x10, 0xf3, 0x72, 0x49, 0x57, 0x23);

        public static readonly Guid SID_ShellExecuteNamedPropertyStore__scanned__ = new Guid(0xeb84ada2, 0x00ff, 0x4992, 0x83, 0x24, 0xed, 0x5c, 0xe0, 0x61, 0xcb, 0x29);

        public const uint ISIOI_ICONFILE = 0x00000001;

        public const uint ISIOI_ICONINDEX = 0x00000002;

        public const uint ABM_NEW = 0x00000000;

        public const uint ABM_REMOVE = 0x00000001;

        public const uint ABM_QUERYPOS = 0x00000002;

        public const uint ABM_SETPOS = 0x00000003;

        public const uint ABM_GETSTATE = 0x00000004;

        public const uint ABM_GETTASKBARPOS = 0x00000005;

        public const uint ABM_ACTIVATE = 0x00000006;

        public const uint ABM_GETAUTOHIDEBAR = 0x00000007;

        public const uint ABM_SETAUTOHIDEBAR = 0x00000008;

        public const uint ABM_WINDOWPOSCHANGED = 0x0000009;

        public const uint ABM_SETSTATE = 0x0000000a;

        public const uint ABM_GETAUTOHIDEBAREX = 0x0000000b;

        public const uint ABM_SETAUTOHIDEBAREX = 0x0000000c;

        public const uint ABN_STATECHANGE = 0x0000000;

        public const uint ABN_POSCHANGED = 0x0000001;

        public const uint ABN_FULLSCREENAPP = 0x0000002;

        public const uint ABN_WINDOWARRANGE = 0x0000003;

        public const uint ABS_AUTOHIDE = 0x0000001;

        public const uint ABS_ALWAYSONTOP = 0x0000002;

        public const uint ABE_LEFT = 0;

        public const uint ABE_TOP = 1;

        public const uint ABE_RIGHT = 2;

        public const uint ABE_BOTTOM = 3;

        public const uint FO_MOVE = 0x0001;

        public const uint FO_COPY = 0x0002;

        public const uint FO_DELETE = 0x0003;

        public const uint FO_RENAME = 0x0004;

        public const uint FOF_MULTIDESTFILES = 0x0001;

        public const uint FOF_CONFIRMMOUSE = 0x0002;

        public const uint FOF_SILENT = 0x0004;

        public const uint FOF_RENAMEONCOLLISION = 0x0008;

        public const uint FOF_NOCONFIRMATION = 0x0010;

        public const uint FOF_WANTMAPPINGHANDLE = 0x0020;

        public const uint FOF_ALLOWUNDO = 0x0040;

        public const uint FOF_FILESONLY = 0x0080;

        public const uint FOF_SIMPLEPROGRESS = 0x0100;

        public const uint FOF_NOCONFIRMMKDIR = 0x0200;

        public const uint FOF_NOERRORUI = 0x0400;

        public const uint FOF_NOCOPYSECURITYATTRIBS = 0x0800;

        public const uint FOF_NORECURSION = 0x1000;

        public const uint FOF_NO_CONNECTED_ELEMENTS = 0x2000;

        public const uint FOF_WANTNUKEWARNING = 0x4000;

        public const uint FOF_NORECURSEREPARSE = 0x8000;

        public const uint PO_DELETE = 0x0013;

        public const uint PO_RENAME = 0x0014;

        public const uint PO_PORTCHANGE = 0x0020;

        public const uint PO_REN_PORT = 0x0034;

        public const uint SE_ERR_FNF = 2;

        public const uint SE_ERR_PNF = 3;

        public const uint SE_ERR_ACCESSDENIED = 5;

        public const uint SE_ERR_OOM = 8;

        public const uint SE_ERR_DLLNOTFOUND = 32;

        public const uint SE_ERR_SHARE = 26;

        public const uint SE_ERR_ASSOCINCOMPLETE = 27;

        public const uint SE_ERR_DDETIMEOUT = 28;

        public const uint SE_ERR_DDEFAIL = 29;

        public const uint SE_ERR_DDEBUSY = 30;

        public const uint SE_ERR_NOASSOC = 31;

        public const uint SEE_MASK_DEFAULT = 0x00000000;

        public const uint SEE_MASK_CLASSNAME = 0x00000001;

        public const uint SEE_MASK_CLASSKEY = 0x00000003;

        public const uint SEE_MASK_IDLIST = 0x00000004;

        public const uint SEE_MASK_INVOKEIDLIST = 0x0000000c;

        public const uint SEE_MASK_ICON = 0x00000010;

        public const uint SEE_MASK_HOTKEY = 0x00000020;

        public const uint SEE_MASK_NOCLOSEPROCESS = 0x00000040;

        public const uint SEE_MASK_CONNECTNETDRV = 0x00000080;

        public const uint SEE_MASK_NOASYNC = 0x00000100;

        public const uint SEE_MASK_DOENVSUBST = 0x00000200;

        public const uint SEE_MASK_FLAG_NO_UI = 0x00000400;

        public const uint SEE_MASK_UNICODE = 0x00004000;

        public const uint SEE_MASK_NO_CONSOLE = 0x00008000;

        public const uint SEE_MASK_ASYNCOK = 0x00100000;

        public const uint SEE_MASK_HMONITOR = 0x00200000;

        public const uint SEE_MASK_NOZONECHECKS = 0x00800000;

        public const uint SEE_MASK_NOQUERYCLASSSTORE = 0x01000000;

        public const uint SEE_MASK_WAITFORINPUTIDLE = 0x02000000;

        public const uint SEE_MASK_FLAG_LOG_USAGE = 0x04000000;

        public const uint SEE_MASK_FLAG_HINST_IS_SITE = 0x08000000;

        public const uint SHERB_NOCONFIRMATION = 0x00000001;

        public const uint SHERB_NOPROGRESSUI = 0x00000002;

        public const uint SHERB_NOSOUND = 0x00000004;

        public const uint NIN_SELECT = WM_USER + 0;

        public const uint NINF_KEY = 0x1;

        public const uint NIN_BALLOONSHOW = WM_USER + 2;

        public const uint NIN_BALLOONHIDE = WM_USER + 3;

        public const uint NIN_BALLOONTIMEOUT = WM_USER + 4;

        public const uint NIN_BALLOONUSERCLICK = WM_USER + 5;

        public const uint NIN_POPUPOPEN = WM_USER + 6;

        public const uint NIN_POPUPCLOSE = WM_USER + 7;

        public const uint NOTIFYICON_VERSION = 3;

        public const uint NOTIFYICON_VERSION_4 = 4;

        public const uint NIS_HIDDEN = 0x00000001;

        public const uint NIS_SHAREDICON = 0x00000002;

        public const uint NIIF_NONE = 0x00000000;

        public const uint NIIF_INFO = 0x00000001;

        public const uint NIIF_WARNING = 0x00000002;

        public const uint NIIF_ERROR = 0x00000003;

        public const uint NIIF_USER = 0x00000004;

        public const uint NIIF_ICON_MASK = 0x0000000F;

        public const uint NIIF_NOSOUND = 0x00000010;

        public const uint NIIF_LARGE_ICON = 0x00000020;

        public const uint NIIF_RESPECT_QUIET_TIME = 0x00000080;

        public const uint SHGSI_ICONLOCATION = 0;

        public const ulong SHGNLI_PIDL = 0x000000001;

        public const ulong SHGNLI_PREFIXNAME = 0x000000002;

        public const ulong SHGNLI_NOUNIQUE = 0x000000004;

        public const ulong SHGNLI_NOLNK = 0x000000008;

        public const ulong SHGNLI_NOLOCNAME = 0x000000010;

        public const ulong SHGNLI_USEURLEXT = 0x000000020;

        public const uint PRINTACTION_OPEN = 0;

        public const uint PRINTACTION_PROPERTIES = 1;

        public const uint PRINTACTION_NETINSTALL = 2;

        public const uint PRINTACTION_NETINSTALLLINK = 3;

        public const uint PRINTACTION_TESTPAGE = 4;

        public const uint PRINTACTION_OPENNETPRN = 5;

        public const uint PRINTACTION_DOCUMENTDEFAULTS = 6;

        public const uint PRINTACTION_SERVERPROPERTIES = 7;

        public const uint PRINT_PROP_FORCE_NAME = 0x01;

        public const uint OFFLINE_STATUS_LOCAL = 0x0001;

        public const uint OFFLINE_STATUS_REMOTE = 0x0002;

        public const uint OFFLINE_STATUS_INCOMPLETE = 0x0004;

        public const uint SHIL_LARGE = 0;

        public const uint SHIL_SMALL = 1;

        public const uint SHIL_EXTRALARGE = 2;

        public const uint SHIL_SYSSMALL = 3;

        public const uint SHIL_JUMBO = 4;

        public const uint NCM_GETADDRESS = WM_USER+1;

        public const uint NCM_SETALLOWTYPE = WM_USER+2;

        public const uint NCM_GETALLOWTYPE = WM_USER+3;

        public const uint NCM_DISPLAYERRORTIP = WM_USER+4;

        public const uint CREDENTIAL_PROVIDER_NO_DEFAULT = 0xFFFFFFFF;

        public static readonly Guid Identity_LocalUserProvider__scanned__ = new Guid(0xA198529B, 0x730F, 0x4089, 0xB6, 0x46, 0xA1, 0x25, 0x57, 0xF5, 0x66, 0x5E);

        public const uint MAX_SYNCMGR_ID = 64;

        public const uint MAX_SYNCMGR_PROGRESSTEXT = 260;

        public const uint MAX_SYNCMGR_NAME = 128;

        public const int STIF_DEFAULT = 0x00000000;

        public const int STIF_SUPPORT_HEX = 0x00000001;

        public const uint GCT_INVALID = 0x0000;

        public const uint GCT_LFNCHAR = 0x0001;

        public const uint GCT_SHORTCHAR = 0x0002;

        public const uint GCT_WILD = 0x0004;

        public const uint GCT_SEPARATOR = 0x0008;

        public const uint PMSF_NORMAL = 0x00000000;

        public const uint PMSF_MULTIPLE = 0x00000001;

        public const uint PMSF_DONT_STRIP_SPACES = 0x00010000;

        public const uint URL_UNESCAPE = 0x10000000;

        public const uint URL_ESCAPE_UNSAFE = 0x20000000;

        public const uint URL_PLUGGABLE_PROTOCOL = 0x40000000;

        public const uint URL_WININET_COMPATIBILITY = 0x80000000;

        public const uint URL_DONT_ESCAPE_EXTRA_INFO = 0x02000000;

        public const uint URL_ESCAPE_SPACES_ONLY = 0x04000000;

        public const uint URL_DONT_SIMPLIFY = 0x08000000;

        public const uint URL_UNESCAPE_INPLACE = 0x00100000;

        public const uint URL_CONVERT_IF_DOSPATH = 0x00200000;

        public const uint URL_UNESCAPE_HIGH_ANSI_ONLY = 0x00400000;

        public const uint URL_INTERNAL_PATH = 0x00800000;

        public const uint URL_FILE_USE_PATHURL = 0x00010000;

        public const uint URL_DONT_UNESCAPE = 0x00020000;

        public const uint URL_ESCAPE_AS_UTF8 = 0x00040000;

        public const uint URL_ESCAPE_ASCII_URI_COMPONENT = 0x00080000;

        public const uint URL_ESCAPE_PERCENT = 0x00001000;

        public const uint URL_ESCAPE_SEGMENT_ONLY = 0x00002000;

        public const uint URL_PARTFLAG_KEEPSCHEME = 0x00000001;

        public const uint URL_APPLY_DEFAULT = 0x00000001;

        public const uint URL_APPLY_GUESSSCHEME = 0x00000002;

        public const uint URL_APPLY_GUESSFILE = 0x00000004;

        public const uint URL_APPLY_FORCEAPPLY = 0x00000008;

        public const uint SRRF_RT_REG_NONE = 0x00000001;

        public const uint SRRF_RT_REG_SZ = 0x00000002;

        public const uint SRRF_RT_REG_EXPAND_SZ = 0x00000004;

        public const uint SRRF_RT_REG_BINARY = 0x00000008;

        public const uint SRRF_RT_REG_DWORD = 0x00000010;

        public const uint SRRF_RT_REG_MULTI_SZ = 0x00000020;

        public const uint SRRF_RT_REG_QWORD = 0x00000040;

        public const uint SRRF_RT_ANY = 0x0000ffff;

        public const uint SRRF_RM_ANY = 0x00000000;

        public const uint SRRF_RM_NORMAL = 0x00010000;

        public const uint SRRF_RM_SAFE = 0x00020000;

        public const uint SRRF_RM_SAFENETWORK = 0x00040000;

        public const uint SRRF_NOEXPAND = 0x10000000;

        public const uint SRRF_ZEROONFAILURE = 0x20000000;

        public const uint SRRF_NOVIRT = 0x40000000;

        public const uint SHREGSET_HKCU = 0x00000001;

        public const uint SHREGSET_FORCE_HKCU = 0x00000002;

        public const uint SHREGSET_HKLM = 0x00000004;

        public const uint SHREGSET_FORCE_HKLM = 0x00000008;

        public const uint SPMODE_SHELL = 0x00000001;

        public const uint SPMODE_DEBUGOUT = 0x00000002;

        public const uint SPMODE_TEST = 0x00000004;

        public const uint SPMODE_BROWSER = 0x00000008;

        public const uint SPMODE_FLUSH = 0x00000010;

        public const uint SPMODE_EVENT = 0x00000020;

        public const uint SPMODE_MSVM = 0x00000040;

        public const uint SPMODE_FORMATTEXT = 0x00000080;

        public const uint SPMODE_PROFILE = 0x00000100;

        public const uint SPMODE_DEBUGBREAK = 0x00000200;

        public const uint SPMODE_MSGTRACE = 0x00000400;

        public const uint SPMODE_PERFTAGS = 0x00000800;

        public const uint SPMODE_MEMWATCH = 0x00001000;

        public const uint SPMODE_DBMON = 0x00002000;

        public const uint SPMODE_MULTISTOP = 0x00004000;

        public const uint SPMODE_EVENTTRACE = 0x00008000;

        public const uint SHGVSPB_PERUSER = 0x00000001;

        public const uint SHGVSPB_ALLUSERS = 0x00000002;

        public const uint SHGVSPB_PERFOLDER = 0x00000004;

        public const uint SHGVSPB_ALLFOLDERS = 0x00000008;

        public const uint SHGVSPB_INHERIT = 0x00000010;

        public const uint SHGVSPB_ROAM = 0x00000020;

        public const uint SHGVSPB_NOAUTODEFAULTS = 0x80000000;

        public const uint FDTF_SHORTTIME = 0x00000001;

        public const uint FDTF_SHORTDATE = 0x00000002;

        public const uint FDTF_LONGDATE = 0x00000004;

        public const uint FDTF_LONGTIME = 0x00000008;

        public const uint FDTF_RELATIVE = 0x00000010;

        public const uint FDTF_LTRDATE = 0x00000100;

        public const uint FDTF_RTLDATE = 0x00000200;

        public const uint FDTF_NOAUTOREADINGORDER = 0x00000400;

        public const uint OS_WINDOWS = 0;

        public const uint OS_NT = 1;

        public const uint OS_WIN95ORGREATER = 2;

        public const uint OS_NT4ORGREATER = 3;

        public const uint OS_WIN98ORGREATER = 5;

        public const uint OS_WIN98_GOLD = 6;

        public const uint OS_WIN2000ORGREATER = 7;

        public const uint OS_WIN2000PRO = 8;

        public const uint OS_WIN2000SERVER = 9;

        public const uint OS_WIN2000ADVSERVER = 10;

        public const uint OS_WIN2000DATACENTER = 11;

        public const uint OS_WIN2000TERMINAL = 12;

        public const uint OS_EMBEDDED = 13;

        public const uint OS_TERMINALCLIENT = 14;

        public const uint OS_TERMINALREMOTEADMIN = 15;

        public const uint OS_WIN95_GOLD = 16;

        public const uint OS_MEORGREATER = 17;

        public const uint OS_XPORGREATER = 18;

        public const uint OS_HOME = 19;

        public const uint OS_PROFESSIONAL = 20;

        public const uint OS_DATACENTER = 21;

        public const uint OS_ADVSERVER = 22;

        public const uint OS_SERVER = 23;

        public const uint OS_TERMINALSERVER = 24;

        public const uint OS_PERSONALTERMINALSERVER = 25;

        public const uint OS_FASTUSERSWITCHING = 26;

        public const uint OS_WELCOMELOGONUI = 27;

        public const uint OS_DOMAINMEMBER = 28;

        public const uint OS_ANYSERVER = 29;

        public const uint OS_WOW6432 = 30;

        public const uint OS_WEBSERVER = 31;

        public const uint OS_SMALLBUSINESSSERVER = 32;

        public const uint OS_TABLETPC = 33;

        public const uint OS_SERVERADMINUI = 34;

        public const uint OS_MEDIACENTER = 35;

        public const uint OS_APPLIANCE = 36;

        public const uint PLATFORM_UNKNOWN = 0;

        public const uint PLATFORM_IE3 = 1;

        public const uint PLATFORM_BROWSERONLY = 1;

        public const uint PLATFORM_INTEGRATED = 2;

        public const uint ILMM_IE4 = 0;

        public const uint SHACF_DEFAULT = 0x00000000;

        public const uint SHACF_FILESYSTEM = 0x00000001;

        public const uint SHACF_URLHISTORY = 0x00000002;

        public const uint SHACF_URLMRU = 0x00000004;

        public const uint SHACF_USETAB = 0x00000008;

        public const uint SHACF_FILESYS_ONLY = 0x00000010;

        public const uint SHACF_FILESYS_DIRS = 0x00000020;

        public const uint SHACF_VIRTUAL_NAMESPACE = 0x00000040;

        public const uint SHACF_AUTOSUGGEST_FORCE_ON = 0x10000000;

        public const uint SHACF_AUTOSUGGEST_FORCE_OFF = 0x20000000;

        public const uint SHACF_AUTOAPPEND_FORCE_ON = 0x40000000;

        public const uint SHACF_AUTOAPPEND_FORCE_OFF = 0x80000000;

        public const uint DLLVER_PLATFORM_WINDOWS = 0x00000001;

        public const uint DLLVER_PLATFORM_NT = 0x00000002;

        public const ulong DLLVER_MAJOR_MASK = 0xFFFF000000000000;

        public const ulong DLLVER_MINOR_MASK = 0x0000FFFF00000000;

        public const ulong DLLVER_BUILD_MASK = 0x00000000FFFF0000;

        public const ulong DLLVER_QFE_MASK = 0x000000000000FFFF;

        [NativeTypeName("HRESULT")]
        public const int WTS_E_FAILEDEXTRACTION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xB200));

        [NativeTypeName("HRESULT")]
        public const int WTS_E_EXTRACTIONTIMEDOUT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xB201));

        [NativeTypeName("HRESULT")]
        public const int WTS_E_SURROGATEUNAVAILABLE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xB202));

        [NativeTypeName("HRESULT")]
        public const int WTS_E_FASTEXTRACTIONNOTSUPPORTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xB203));

        [NativeTypeName("HRESULT")]
        public const int WTS_E_DATAFILEUNAVAILABLE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xB204));

        [NativeTypeName("HRESULT")]
        public const int WTS_E_EXTRACTIONPENDING = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xB205));

        [NativeTypeName("HRESULT")]
        public const int WTS_E_EXTRACTIONBLOCKED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xB206));

        public const uint SHIMGDEC_DEFAULT = 0x00000000;

        public const uint SHIMGDEC_THUMBNAIL = 0x00000001;

        public const uint SHIMGDEC_LOADFULL = 0x00000002;

        [NativeTypeName("HRESULT")]
        public const int E_NOTVALIDFORANIMATEDIMAGE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x01));

        [NativeTypeName("HRESULT")]
        public const int S_SYNCMGR_MISSINGITEMS = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0201));

        [NativeTypeName("HRESULT")]
        public const int S_SYNCMGR_RETRYSYNC = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0202));

        [NativeTypeName("HRESULT")]
        public const int S_SYNCMGR_CANCELITEM = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0203));

        [NativeTypeName("HRESULT")]
        public const int S_SYNCMGR_CANCELALL = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0204));

        [NativeTypeName("HRESULT")]
        public const int S_SYNCMGR_ITEMDELETED = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0210));

        [NativeTypeName("HRESULT")]
        public const int S_SYNCMGR_ENUMITEMS = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0211));

        public const uint SYNCMGRPROGRESSITEM_STATUSTEXT = 0x0001;

        public const uint SYNCMGRPROGRESSITEM_STATUSTYPE = 0x0002;

        public const uint SYNCMGRPROGRESSITEM_PROGVALUE = 0x0004;

        public const uint SYNCMGRPROGRESSITEM_MAXVALUE = 0x0008;

        public const uint SYNCMGRLOGERROR_ERRORFLAGS = 0x0001;

        public const uint SYNCMGRLOGERROR_ERRORID = 0x0002;

        public const uint SYNCMGRLOGERROR_ITEMID = 0x0004;

        public const uint SYNCMGRITEM_ITEMFLAGMASK = 0x007F;

        public const uint MAX_SYNCMGRITEMNAME = 128;

        public const uint SYNCMGRHANDLERFLAG_MASK = 0x000f;

        public const uint MAX_SYNCMGRHANDLERNAME = 32;

        public const uint SYNCMGRREGISTERFLAGS_MASK = 0x07;

        public const int TLOG_BACK = -1;

        public const uint TLOG_CURRENT = 0;

        public const uint TLOG_FORE = 1;

        public const uint TLMENUF_INCLUDECURRENT = 0x00000001;

        public const uint TLMENUF_BACK = 0x00000010;

        public const uint TLMENUF_FORE = 0x00000020;

        public const uint BSF_REGISTERASDROPTARGET = 0x00000001;

        public const uint BSF_THEATERMODE = 0x00000002;

        public const uint BSF_NOLOCALFILEWARNING = 0x00000010;

        public const uint BSF_UISETBYAUTOMATION = 0x00000100;

        public const uint BSF_RESIZABLE = 0x00000200;

        public const uint BSF_CANMAXIMIZE = 0x00000400;

        public const uint BSF_TOPBROWSER = 0x00000800;

        public const uint BSF_NAVNOHISTORY = 0x00001000;

        public const uint BSF_HTMLNAVCANCELED = 0x00002000;

        public const uint BSF_DONTSHOWNAVCANCELPAGE = 0x00004000;

        public const uint BSF_SETNAVIGATABLECODEPAGE = 0x00008000;

        public const uint BSF_DELEGATEDNAVIGATION = 0x00010000;

        public const uint BSF_TRUSTEDFORACTIVEX = 0x00020000;

        public const uint BSF_MERGEDMENUS = 0x00040000;

        public const uint BSF_FEEDNAVIGATION = 0x00080000;

        public const uint BSF_FEEDSUBSCRIBED = 0x00100000;

        public const uint HLNF_CALLERUNTRUSTED = 0x00200000;

        public const uint HLNF_TRUSTEDFORACTIVEX = 0x00400000;

        public const uint HLNF_DISABLEWINDOWRESTRICTIONS = 0x00800000;

        public const uint HLNF_TRUSTFIRSTDOWNLOAD = 0x01000000;

        public const uint HLNF_UNTRUSTEDFORDOWNLOAD = 0x02000000;

        public const uint SHHLNF_NOAUTOSELECT = 0x04000000;

        public const uint SHHLNF_WRITENOHISTORY = 0x08000000;

        public const uint HLNF_EXTERNALNAVIGATE = 0x10000000;

        public const uint HLNF_ALLOW_AUTONAVIGATE = 0x20000000;

        public const uint HLNF_NEWWINDOWSMANAGED = 0x80000000;

        public const uint INTERNET_MAX_PATH_LENGTH = 2048;

        public const uint INTERNET_MAX_SCHEME_LENGTH = 32;

        public const uint VIEW_PRIORITY_RESTRICTED = 0x00000070;

        public const uint VIEW_PRIORITY_CACHEHIT = 0x00000050;

        public const uint VIEW_PRIORITY_STALECACHEHIT = 0x00000045;

        public const uint VIEW_PRIORITY_USEASDEFAULT = 0x00000043;

        public const uint VIEW_PRIORITY_SHELLEXT = 0x00000040;

        public const uint VIEW_PRIORITY_CACHEMISS = 0x00000030;

        public const uint VIEW_PRIORITY_INHERIT = 0x00000020;

        public const uint VIEW_PRIORITY_SHELLEXT_ASBACKUP = 0x0015;

        public const uint VIEW_PRIORITY_DESPERATE = 0x00000010;

        public const uint VIEW_PRIORITY_NONE = 0x00000000;

        public const uint PATHCCH_MAX_CCH = 0x8000;

        public const uint IDS_DESCRIPTION = 1;

        public const uint ID_APP = 100;

        public const uint DLG_SCRNSAVECONFIGURE = 2003;

        public const uint MAXFILELEN = 13;

        public const uint TITLEBARNAMELEN = 40;

        public const uint APPNAMEBUFFERLEN = 40;

        public const uint BUFFLEN = 255;

        [NativeTypeName("HRESULT")]
        public const int E_FLAGS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x1000));

        [NativeTypeName("HRESULT")]
        public const int IS_E_EXEC_FAILED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x2002));

        [NativeTypeName("HRESULT")]
        public const int URL_E_INVALID_SYNTAX = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x1001));

        [NativeTypeName("HRESULT")]
        public const int URL_E_UNREGISTERED_PROTOCOL = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x1002));

        public const uint PID_FIRST_USABLE = 2;

    }
}

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


namespace Windows.Win32.Web.MsHtml
{
    public static partial class Apis
    {
        public static readonly Guid SID_SEditCommandTarget__scanned__ = new Guid(0x3050f4b5,0x98b5,0x11cf,0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b);

        public static readonly Guid CGID_EditStateCommands__scanned__ = new Guid(0x3050f4b6,0x98b5,0x11cf,0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b);

        public static readonly Guid SID_SHTMLEditHost__scanned__ = new Guid(0x3050f6a0,0x98b5,0x11cf,0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b);

        public static readonly Guid SID_SHTMLEditServices__scanned__ = new Guid(0x3050f7f9,0x98b5,0x11cf,0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b);

        public const uint COOKIEACTION_NONE = 0x00000000;

        public const uint COOKIEACTION_ACCEPT = 0x00000001;

        public const uint COOKIEACTION_REJECT = 0x00000002;

        public const uint COOKIEACTION_DOWNGRADE = 0x00000004;

        public const uint COOKIEACTION_LEASH = 0x00000008;

        public const uint COOKIEACTION_SUPPRESS = 0x00000010;

        public const uint COOKIEACTION_READ = 0x00000020;

        public const uint PRIVACY_URLISTOPLEVEL = 0x00010000;

        public const uint PRIVACY_URLHASCOMPACTPOLICY = 0x00020000;

        public const uint PRIVACY_URLHASPOSTDATA = 0x00080000;

        public const uint PRIVACY_URLHASPOLICYREFLINK = 0x00100000;

        public const uint PRIVACY_URLHASPOLICYREFHEADER = 0x00200000;

        public const uint PRIVACY_URLHASP3PHEADER = 0x00400000;

        public const uint DEBUGCALLBACKNOTIFICATION_TIMEOUT = 0x00000001;

        public const uint DEBUGCALLBACKNOTIFICATION_INTERVAL = 0x00000002;

        public const uint DEBUGCALLBACKNOTIFICATION_IMMEDIATE = 0x00000004;

        public const uint DEBUGCALLBACKNOTIFICATION_ANIMATIONFRAME = 0x00000008;

        public const uint DEBUGCALLBACKNOTIFICATION_DOMEVENT = 0x00000010;

        public const uint DEBUGDOMEVENTPROPAGATIONSTATUS_DEFAULTCANCELED = 0x00000001;

        public const uint DEBUGDOMEVENTPROPAGATIONSTATUS_STOPIMMEDIATEPROPAGATION = 0x00000002;

        public const uint DEBUGDOMEVENTPROPAGATIONSTATUS_STOPPROPAGATION = 0x00000004;

    }
}

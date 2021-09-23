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


using static Windows.Win32.UI.Accessibility.Apis;

namespace Windows.Win32.UI.Accessibility
{
    [Flags]
    public enum STICKYKEYS_FLAGS : uint
    {
        SKF_STICKYKEYSON = 0x00000001,
        SKF_AVAILABLE = 0x00000002,
        SKF_HOTKEYACTIVE = 0x00000004,
        SKF_CONFIRMHOTKEY = 0x00000008,
        SKF_HOTKEYSOUND = 0x00000010,
        SKF_INDICATOR = 0x00000020,
        SKF_AUDIBLEFEEDBACK = 0x00000040,
        SKF_TRISTATE = 0x00000080,
        SKF_TWOKEYSOFF = 0x00000100,
        SKF_LALTLATCHED = 0x10000000,
        SKF_LCTLLATCHED = 0x04000000,
        SKF_LSHIFTLATCHED = 0x01000000,
        SKF_RALTLATCHED = 0x20000000,
        SKF_RCTLLATCHED = 0x08000000,
        SKF_RSHIFTLATCHED = 0x02000000,
        SKF_LWINLATCHED = 0x40000000,
        SKF_RWINLATCHED = 0x80000000,
        SKF_LALTLOCKED = 0x00100000,
        SKF_LCTLLOCKED = 0x00040000,
        SKF_LSHIFTLOCKED = 0x00010000,
        SKF_RALTLOCKED = 0x00200000,
        SKF_RCTLLOCKED = 0x00080000,
        SKF_RSHIFTLOCKED = 0x00020000,
        SKF_LWINLOCKED = 0x00400000,
        SKF_RWINLOCKED = 0x00800000,
    }

    [Flags]
    public enum SOUNDSENTRY_FLAGS : uint
    {
        SSF_SOUNDSENTRYON = 0x00000001,
        SSF_AVAILABLE = 0x00000002,
        SSF_INDICATOR = 0x00000004,
    }

    [Flags]
    public enum ACC_UTILITY_STATE_FLAGS : uint
    {
        ANRUS_ON_SCREEN_KEYBOARD_ACTIVE = 1,
        ANRUS_TOUCH_MODIFICATION_ACTIVE = 2,
        ANRUS_PRIORITY_AUDIO_ACTIVE = 4,
        ANRUS_PRIORITY_AUDIO_ACTIVE_NODUCK = 8,
    }

    public enum SOUND_SENTRY_GRAPHICS_EFFECT : uint
    {
        SSGF_DISPLAY = 3,
        SSGF_NONE = 0,
    }

    [Flags]
    public enum SERIALKEYS_FLAGS : uint
    {
        SERKF_AVAILABLE = 2,
        SERKF_INDICATOR = 4,
        SERKF_SERIALKEYSON = 1,
    }

    [Flags]
    public enum HIGHCONTRASTW_FLAGS : uint
    {
        HCF_HIGHCONTRASTON = 1,
        HCF_AVAILABLE = 2,
        HCF_HOTKEYACTIVE = 4,
        HCF_CONFIRMHOTKEY = 8,
        HCF_HOTKEYSOUND = 16,
        HCF_INDICATOR = 32,
        HCF_HOTKEYAVAILABLE = 64,
        HCF_OPTION_NOTHEMECHANGE = 4096,
    }

    public enum SOUNDSENTRY_TEXT_EFFECT : uint
    {
        SSTF_BORDER = 2,
        SSTF_CHARS = 1,
        SSTF_DISPLAY = 3,
        SSTF_NONE = 0,
    }

    public enum SOUNDSENTRY_WINDOWS_EFFECT : uint
    {
        SSWF_CUSTOM = 4,
        SSWF_DISPLAY = 3,
        SSWF_NONE = 0,
        SSWF_TITLE = 1,
        SSWF_WINDOW = 2,
    }

}

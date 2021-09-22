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


using static Windows.Win32.Devices.Communication.Apis;

namespace Windows.Win32.Devices.Communication
{
    [Flags]
    public enum MODEM_STATUS_FLAGS : uint
    {
        MS_CTS_ON = 16,
        MS_DSR_ON = 32,
        MS_RING_ON = 64,
        MS_RLSD_ON = 128,
    }

    [Flags]
    public enum CLEAR_COMM_ERROR_FLAGS : uint
    {
        CE_BREAK = 16,
        CE_FRAME = 8,
        CE_OVERRUN = 2,
        CE_RXOVER = 1,
        CE_RXPARITY = 4,
    }

    [Flags]
    public enum PURGE_COMM_FLAGS : uint
    {
        PURGE_RXABORT = 2,
        PURGE_RXCLEAR = 8,
        PURGE_TXABORT = 1,
        PURGE_TXCLEAR = 4,
    }

    [Flags]
    public enum COMM_EVENT_MASK : uint
    {
        EV_BREAK = 64,
        EV_CTS = 8,
        EV_DSR = 16,
        EV_ERR = 128,
        EV_EVENT1 = 2048,
        EV_EVENT2 = 4096,
        EV_PERR = 512,
        EV_RING = 256,
        EV_RLSD = 32,
        EV_RX80FULL = 1024,
        EV_RXCHAR = 1,
        EV_RXFLAG = 2,
        EV_TXEMPTY = 4,
    }

    public enum ESCAPE_COMM_FUNCTION : uint
    {
        CLRBREAK = 9,
        CLRDTR = 6,
        CLRRTS = 4,
        SETBREAK = 8,
        SETDTR = 5,
        SETRTS = 3,
        SETXOFF = 1,
        SETXON = 2,
    }

    [Flags]
    public enum MODEMDEVCAPS_DIAL_OPTIONS : uint
    {
        DIALOPTION_BILLING = 64,
        DIALOPTION_DIALTONE = 256,
        DIALOPTION_QUIET = 128,
    }

    public enum MODEMSETTINGS_SPEAKER_MODE : uint
    {
        MDMSPKR_CALLSETUP = 8,
        MDMSPKR_DIAL = 2,
        MDMSPKR_OFF = 1,
        MDMSPKR_ON = 4,
    }

    [Flags]
    public enum COMMPROP_STOP_PARITY : ushort
    {
        STOPBITS_10 = 1,
        STOPBITS_15 = 2,
        STOPBITS_20 = 4,
        PARITY_NONE = 256,
        PARITY_ODD = 512,
        PARITY_EVEN = 1024,
        PARITY_MARK = 2048,
        PARITY_SPACE = 4096,
    }

    public enum MODEM_SPEAKER_VOLUME : uint
    {
        MDMVOL_HIGH = 2,
        MDMVOL_LOW = 0,
        MDMVOL_MEDIUM = 1,
    }

    [Flags]
    public enum MODEMDEVCAPS_SPEAKER_VOLUME : uint
    {
        MDMVOLFLAG_HIGH = 4,
        MDMVOLFLAG_LOW = 1,
        MDMVOLFLAG_MEDIUM = 2,
    }

    [Flags]
    public enum MODEMDEVCAPS_SPEAKER_MODE : uint
    {
        MDMSPKRFLAG_CALLSETUP = 8,
        MDMSPKRFLAG_DIAL = 2,
        MDMSPKRFLAG_OFF = 1,
        MDMSPKRFLAG_ON = 4,
    }

}

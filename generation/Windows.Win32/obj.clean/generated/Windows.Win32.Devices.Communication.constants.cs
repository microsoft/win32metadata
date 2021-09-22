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


namespace Windows.Win32.Devices.Communication
{
    public static partial class Apis
    {
        public const uint MDM_COMPRESSION = 0x00000001;

        public const uint MDM_ERROR_CONTROL = 0x00000002;

        public const uint MDM_FORCED_EC = 0x00000004;

        public const uint MDM_CELLULAR = 0x00000008;

        public const uint MDM_FLOWCONTROL_HARD = 0x00000010;

        public const uint MDM_FLOWCONTROL_SOFT = 0x00000020;

        public const uint MDM_CCITT_OVERRIDE = 0x00000040;

        public const uint MDM_SPEED_ADJUST = 0x00000080;

        public const uint MDM_TONE_DIAL = 0x00000100;

        public const uint MDM_BLIND_DIAL = 0x00000200;

        public const uint MDM_V23_OVERRIDE = 0x00000400;

        public const uint MDM_DIAGNOSTICS = 0x00000800;

        public const uint MDM_MASK_BEARERMODE = 0x0000f000;

        public const uint MDM_SHIFT_BEARERMODE = 12;

        public const uint MDM_MASK_PROTOCOLID = 0x000f0000;

        public const uint MDM_SHIFT_PROTOCOLID = 16;

        public const uint MDM_MASK_PROTOCOLDATA = 0x0ff00000;

        public const uint MDM_SHIFT_PROTOCOLDATA = 20;

        public const uint MDM_BEARERMODE_ANALOG = 0x0;

        public const uint MDM_BEARERMODE_ISDN = 0x1;

        public const uint MDM_BEARERMODE_GSM = 0x2;

        public const uint MDM_PROTOCOLID_DEFAULT = 0x0;

        public const uint MDM_PROTOCOLID_HDLCPPP = 0x1;

        public const uint MDM_PROTOCOLID_V128 = 0x2;

        public const uint MDM_PROTOCOLID_X75 = 0x3;

        public const uint MDM_PROTOCOLID_V110 = 0x4;

        public const uint MDM_PROTOCOLID_V120 = 0x5;

        public const uint MDM_PROTOCOLID_AUTO = 0x6;

        public const uint MDM_PROTOCOLID_ANALOG = 0x7;

        public const uint MDM_PROTOCOLID_GPRS = 0x8;

        public const uint MDM_PROTOCOLID_PIAFS = 0x9;

        public const uint MDM_SHIFT_HDLCPPP_SPEED = 0x0;

        public const uint MDM_MASK_HDLCPPP_SPEED = 0x7;

        public const uint MDM_HDLCPPP_SPEED_DEFAULT = 0x0;

        public const uint MDM_HDLCPPP_SPEED_64K = 0x1;

        public const uint MDM_HDLCPPP_SPEED_56K = 0x2;

        public const uint MDM_SHIFT_HDLCPPP_AUTH = 0x3;

        public const uint MDM_HDLCPPP_AUTH_DEFAULT = 0x0;

        public const uint MDM_HDLCPPP_AUTH_NONE = 0x1;

        public const uint MDM_HDLCPPP_AUTH_PAP = 0x2;

        public const uint MDM_HDLCPPP_AUTH_CHAP = 0x3;

        public const uint MDM_HDLCPPP_AUTH_MSCHAP = 0x4;

        public const uint MDM_SHIFT_HDLCPPP_ML = 0x6;

        public const uint MDM_HDLCPPP_ML_DEFAULT = 0x0;

        public const uint MDM_HDLCPPP_ML_NONE = 0x1;

        public const uint MDM_HDLCPPP_ML_2 = 0x2;

        public const uint MDM_SHIFT_V120_SPEED = 0x0;

        public const uint MDM_MASK_V120_SPEED = 0x7;

        public const uint MDM_V120_SPEED_DEFAULT = 0x0;

        public const uint MDM_V120_SPEED_64K = 0x1;

        public const uint MDM_V120_SPEED_56K = 0x2;

        public const uint MDM_SHIFT_V120_ML = 0x6;

        public const uint MDM_V120_ML_DEFAULT = 0x0;

        public const uint MDM_V120_ML_NONE = 0x1;

        public const uint MDM_V120_ML_2 = 0x2;

        public const uint MDM_SHIFT_X75_DATA = 0x0;

        public const uint MDM_MASK_X75_DATA = 0x7;

        public const uint MDM_X75_DATA_DEFAULT = 0x0;

        public const uint MDM_X75_DATA_64K = 0x1;

        public const uint MDM_X75_DATA_128K = 0x2;

        public const uint MDM_X75_DATA_T_70 = 0x3;

        public const uint MDM_X75_DATA_BTX = 0x4;

        public const uint MDM_SHIFT_V110_SPEED = 0x0;

        public const uint MDM_MASK_V110_SPEED = 0xf;

        public const uint MDM_V110_SPEED_DEFAULT = 0x0;

        public const uint MDM_V110_SPEED_1DOT2K = 0x1;

        public const uint MDM_V110_SPEED_2DOT4K = 0x2;

        public const uint MDM_V110_SPEED_4DOT8K = 0x3;

        public const uint MDM_V110_SPEED_9DOT6K = 0x4;

        public const uint MDM_V110_SPEED_12DOT0K = 0x5;

        public const uint MDM_V110_SPEED_14DOT4K = 0x6;

        public const uint MDM_V110_SPEED_19DOT2K = 0x7;

        public const uint MDM_V110_SPEED_28DOT8K = 0x8;

        public const uint MDM_V110_SPEED_38DOT4K = 0x9;

        public const uint MDM_V110_SPEED_57DOT6K = 0xA;

        public const uint MDM_SHIFT_AUTO_SPEED = 0x0;

        public const uint MDM_MASK_AUTO_SPEED = 0x7;

        public const uint MDM_AUTO_SPEED_DEFAULT = 0x0;

        public const uint MDM_SHIFT_AUTO_ML = 0x6;

        public const uint MDM_AUTO_ML_DEFAULT = 0x0;

        public const uint MDM_AUTO_ML_NONE = 0x1;

        public const uint MDM_AUTO_ML_2 = 0x2;

        public const uint MDM_ANALOG_RLP_ON = 0x0;

        public const uint MDM_ANALOG_RLP_OFF = 0x1;

        public const uint MDM_ANALOG_V34 = 0x2;

        public const uint MDM_PIAFS_INCOMING = 0;

        public const uint MDM_PIAFS_OUTGOING = 1;

    }
}

using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;
using static Windows.Win32.Media.Audio.Apis;
using static Windows.Win32.UI.WindowsAndMessaging.Apis;

namespace Windows.Win32.Media.Multimedia
{
    public static unsafe partial class Apis
    {
        public const uint WM_CAP_START = WM_USER;

        public const uint MODM_USER = DRVM_USER;
        public const uint MIDM_USER = DRVM_USER;
        public const uint MODM_MAPPER = DRVM_MAPPER;
        public const uint MIDM_MAPPER = DRVM_MAPPER;
        public const uint MODM_INIT = DRVM_INIT;
        public const uint MIDM_INIT = DRVM_INIT;
        public const uint MODM_INIT_EX = DRVM_INIT_EX;
        public const uint MIDM_INIT_EX = DRVM_INIT_EX;
        public const uint DRV_MCI_FIRST = DRV_RESERVED;

        public const uint ACMDM_BASE = ACMDM_RESERVED_LOW;
        public const uint ICM_RESERVED = ICM_RESERVED_LOW;
    }
}

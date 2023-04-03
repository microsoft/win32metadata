using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Power
{
    public enum POWER_COOLING_MODE : ushort
    {
        PO_TZ_ACTIVE,
        PO_TZ_PASSIVE,
        PO_TZ_INVALID_MODE
    }

    public partial struct PROCESSOR_POWER_INFORMATION
    {
        public uint Number;
        
        public uint MaxMhz;
        
        public uint CurrentMhz;
        
        public uint MhzLimit;
        
        public uint MaxIdleState;
        
        public uint CurrentIdleState;
    }

    public partial struct SYSTEM_POWER_INFORMATION
    {
        public uint MaxIdlenessAllowed;
        
        public uint Idleness;
        
        public uint TimeRemaining;
        
        public POWER_COOLING_MODE CoolingMode;
    }
}

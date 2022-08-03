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
        public ulong Number;
        
        public ulong MaxMhz;
        
        public ulong CurrentMhz;
        
        public ulong MhzLimit;
        
        public ulong MaxIdleState;
        
        public ulong CurrentIdleState;
    }

    public partial struct SYSTEM_POWER_INFORMATION
    {
        public ulong MaxIdlenessAllowed;
        
        public ulong Idleness;
        
        public ulong TimeRemaining;
        
        public POWER_COOLING_MODE CoolingMode;
    }
}

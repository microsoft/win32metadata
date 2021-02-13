using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.DeviceAndDriverInstallation
{
    public enum CONFIGRET : uint
    {
        Success = (0x00000000),
        Default = (0x00000001),
        OutOfMemory = (0x00000002),
        InvalidPointer = (0x00000003),
        InvalidFlag = (0x00000004),
        InvalidDevnode = (0x00000005),
        InvalidDevinst = InvalidDevnode,
        InvalidResDes = (0x00000006),
        InvalidLogConf = (0x00000007),
        InvalidArbitrator = (0x00000008),
        InvalidNodelist = (0x00000009),
        DevnodeHasReqs = (0x0000000A),
        DevinstHasReqs = DevnodeHasReqs,
        InvalidResourceid = (0x0000000B),
        DlvxdNotFound = (0x0000000C),   // Win 95 Only
        NoSuchDevnode = (0x0000000D),
        NoSuchDevinst = NoSuchDevnode,
        NoMoreLogConf = (0x0000000E),
        NoMoreResDes = (0x0000000F),
        AlreadySuchDevnode = (0x00000010),
        AlreadySuchDevinst = AlreadySuchDevnode,
        InvalidRangeList = (0x00000011),
        InvalidRange = (0x00000012),
        Failure = (0x00000013),
        NoSuchLogicalDev = (0x00000014),
        CreateBlocked = (0x00000015),
        NotSystemVm = (0x00000016),   // Win 95 Only
        RemoveVetoed = (0x00000017),
        ApmVetoed = (0x00000018),
        InvalidLoadType = (0x00000019),
        BufferSmall = (0x0000001A),
        NoArbitrator = (0x0000001B),
        NoRegistryHandle = (0x0000001C),
        RegistryError = (0x0000001D),
        InvalidDeviceId = (0x0000001E),
        InvalidData = (0x0000001F),
        InvalidApi = (0x00000020),
        DevloaderNotReady = (0x00000021),
        NeedRestart = (0x00000022),
        NoMoreHwProfiles = (0x00000023),
        DeviceNotThere = (0x00000024),
        NoSuchValue = (0x00000025),
        WrongType = (0x00000026),
        InvalidPriority = (0x00000027),
        NotDisableable = (0x00000028),
        FreeResources = (0x00000029),
        QueryVetoed = (0x0000002A),
        CantShareIrq = (0x0000002B),
        NoDependent = (0x0000002C),
        SameResources = (0x0000002D),
        NoSuchRegistryKey = (0x0000002E),
        InvalidMachinename = (0x0000002F),   // Nt Only
        RemoteCommFailure = (0x00000030),   // Nt Only
        MachineUnavailable = (0x00000031),   // Nt Only
        NoCmServices = (0x00000032),   // Nt Only
        AccessDenied = (0x00000033),   // Nt Only
        CallNotImplemented = (0x00000034),
        InvalidProperty = (0x00000035),
        DeviceInterfaceActive = (0x00000036),
        NoSuchDeviceInterface = (0x00000037),
        InvalidReferenceString = (0x00000038),
        InvalidConflictList = (0x00000039),
        InvalidIndex = (0x0000003A),
        InvalidStructureSize = (0x0000003B),
        NumCrResults = (0x0000003C)
    }
}

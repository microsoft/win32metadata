using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Ioctl
{
    public static unsafe partial class Apis
    {
        public const uint IOCTL_STORAGE_BASE = FILE_DEVICE_MASS_STORAGE;
        public const uint IOCTL_SCMBUS_BASE = FILE_DEVICE_PERSISTENT_MEMORY;
        public const uint IOCTL_DISK_BASE = (uint)Windows.Win32.Storage.FileSystem.FILE_DEVICE_TYPE.FILE_DEVICE_DISK;
        public const uint IOCTL_CHANGER_BASE = FILE_DEVICE_CHANGER;
        public const uint FILE_SPECIAL_ACCESS = 0;
        public const uint FILE_DEVICE_UNKNOWN = 0x00000022;
    }
}

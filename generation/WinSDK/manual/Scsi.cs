using System;
using System.Runtime.InteropServices;

using Windows.Win32.Interop;

namespace Windows.Win32.Storage.DistributedFileSystem
{
    public static unsafe partial class Apis
    {
        public const uint FSCTL_DFS_BASE = (uint)Windows.Win32.System.Ioctl.Apis.FILE_DEVICE_DFS;
    }
}

using System;
using System.Runtime.InteropServices;

using Windows.Win32.Interop;

namespace Windows.Win32.Storage.IscsiDisc
{
    public static unsafe partial class Apis
    {
        public const uint IOCTL_SCSI_BASE = Windows.Win32.System.Ioctl.Apis.FILE_DEVICE_CONTROLLER;
    }
}

using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Diagnostics.Etw
{
    public static unsafe partial class Apis
    {
        public static readonly Guid ALPCGuid = new Guid("45d8cccd-539f-4b72-a8b7-5c683142609a");

        public static readonly Guid DiskIoGuid = new Guid("3d6fa8d4-fe05-11d0-9dda-00c04fd7ba7c");

        public static readonly Guid EventTraceConfigGuid = new Guid("01853a65-418f-4f36-aefc-dc0f1d2fd235");

        public static readonly Guid FileIoGuid = new Guid("90cbdc39-4a3e-11d1-84f4-0000f80464e3");

        public static readonly Guid ImageLoadGuid = new Guid("2cb15d1d-5fc1-11d2-abe1-00a0c911f518");

        public static readonly Guid PageFaultGuid = new Guid("3d6fa8d3-fe05-11d0-9dda-00c04fd7ba7c");

        public static readonly Guid PerfInfoGuid = new Guid("ce1dbfb4-137e-4da6-87b0-3f59aa102cbc");

        public static readonly Guid ProcessGuid = new Guid("3d6fa8d0-fe05-11d0-9dda-00c04fd7ba7c");

        public static readonly Guid RegistryGuid = new Guid("ae53722e-c863-11d2-8659-00c04fa321a1");

        public static readonly Guid SplitIoGuid = new Guid("d837ca92-12b9-44a5-ad6a-3a65b3578aa8");

        public static readonly Guid TcpIpGuid = new Guid("9a280ac0-c8e0-11d1-84e2-00c04fb998a2");

        public static readonly Guid ThreadGuid = new Guid("3d6fa8d1-fe05-11d0-9dda-00c04fd7ba7c");

        public static readonly Guid UdpIpGuid = new Guid("bf3a50c5-a9c9-4988-a005-2df0b7c80f80");
    }
}

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


namespace Windows.Win32.Graphics.DirectDraw
{
    public static partial class Apis
    {
        public const uint DIRECTDRAW_VERSION = 0x0700;

        public const uint _FACDD = 0x876;

        public static readonly Guid CLSID_DirectDraw__scanned__ = new Guid(0xD7B70EE0,0x4340,0x11CF,0xB0,0x63,0x00,0x20,0xAF,0xC2,0xCD,0x35 );

        public static readonly Guid CLSID_DirectDraw7__scanned__ = new Guid(0x3c305196,0x50db,0x11d3,0x9c,0xfe,0x00,0xc0,0x4f,0xd9,0x30,0xc5 );

        public static readonly Guid CLSID_DirectDrawClipper__scanned__ = new Guid(0x593817A0,0x7DB3,0x11CF,0xA2,0xDE,0x00,0xAA,0x00,0xb9,0x33,0x56 );

        public static readonly Guid IID_IDirectDraw__scanned__ = new Guid(0x6C14DB80,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );

        public static readonly Guid IID_IDirectDraw2__scanned__ = new Guid(0xB3A6F3E0,0x2B43,0x11CF,0xA2,0xDE,0x00,0xAA,0x00,0xB9,0x33,0x56 );

        public static readonly Guid IID_IDirectDraw4__scanned__ = new Guid(0x9c59509a,0x39bd,0x11d1,0x8c,0x4a,0x00,0xc0,0x4f,0xd9,0x30,0xc5 );

        public static readonly Guid IID_IDirectDraw7__scanned__ = new Guid(0x15e65ec0,0x3b9c,0x11d2,0xb9,0x2f,0x00,0x60,0x97,0x97,0xea,0x5b );

        public static readonly Guid IID_IDirectDrawSurface__scanned__ = new Guid(0x6C14DB81,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );

        public static readonly Guid IID_IDirectDrawSurface2__scanned__ = new Guid(0x57805885,0x6eec,0x11cf,0x94,0x41,0xa8,0x23,0x03,0xc1,0x0e,0x27 );

        public static readonly Guid IID_IDirectDrawSurface3__scanned__ = new Guid(0xDA044E00,0x69B2,0x11D0,0xA1,0xD5,0x00,0xAA,0x00,0xB8,0xDF,0xBB );

        public static readonly Guid IID_IDirectDrawSurface4__scanned__ = new Guid(0x0B2B8630,0xAD35,0x11D0,0x8E,0xA6,0x00,0x60,0x97,0x97,0xEA,0x5B );

        public static readonly Guid IID_IDirectDrawSurface7__scanned__ = new Guid(0x06675a80,0x3b9b,0x11d2,0xb9,0x2f,0x00,0x60,0x97,0x97,0xea,0x5b );

        public static readonly Guid IID_IDirectDrawPalette__scanned__ = new Guid(0x6C14DB84,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );

        public static readonly Guid IID_IDirectDrawClipper__scanned__ = new Guid(0x6C14DB85,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );

        public static readonly Guid IID_IDirectDrawColorControl__scanned__ = new Guid(0x4B9F0EE0,0x0D7E,0x11D0,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8 );

        public static readonly Guid IID_IDirectDrawGammaControl__scanned__ = new Guid(0x69C11C3E,0xB46B,0x11D1,0xAD,0x7A,0x00,0xC0,0x4F,0xC2,0x9B,0x4E );

        public const int DDENUM_ATTACHEDSECONDARYDEVICES = 0x00000001;

        public const int DDENUM_DETACHEDSECONDARYDEVICES = 0x00000002;

        public const int DDENUM_NONDISPLAYDEVICES = 0x00000004;

        public const int DDCREATE_HARDWAREONLY = 0x00000001;

        public const int DDCREATE_EMULATIONONLY = 0x00000002;

        public const uint MAX_DDDEVICEID_STRING = 512;

        public const int DDGDI_GETHOSTIDENTIFIER = 0x00000001;

        public const int DDSD_CAPS = 0x00000001;

        public const int DDSD_HEIGHT = 0x00000002;

        public const int DDSD_WIDTH = 0x00000004;

        public const int DDSD_PITCH = 0x00000008;

        public const int DDSD_BACKBUFFERCOUNT = 0x00000020;

        public const int DDSD_ZBUFFERBITDEPTH = 0x00000040;

        public const int DDSD_ALPHABITDEPTH = 0x00000080;

        public const int DDSD_LPSURFACE = 0x00000800;

        public const int DDSD_PIXELFORMAT = 0x00001000;

        public const int DDSD_CKDESTOVERLAY = 0x00002000;

        public const int DDSD_CKDESTBLT = 0x00004000;

        public const int DDSD_CKSRCOVERLAY = 0x00008000;

        public const int DDSD_CKSRCBLT = 0x00010000;

        public const int DDSD_MIPMAPCOUNT = 0x00020000;

        public const int DDSD_REFRESHRATE = 0x00040000;

        public const int DDSD_LINEARSIZE = 0x00080000;

        public const int DDSD_TEXTURESTAGE = 0x00100000;

        public const int DDSD_FVF = 0x00200000;

        public const int DDSD_SRCVBHANDLE = 0x00400000;

        public const int DDSD_DEPTH = 0x00800000;

        public const int DDSD_ALL = 0x00fff9ee;

        public const int DDOSD_GUID = 0x00000001;

        public const int DDOSD_COMPRESSION_RATIO = 0x00000002;

        public const int DDOSD_SCAPS = 0x00000004;

        public const int DDOSD_OSCAPS = 0x00000008;

        public const int DDOSD_ALL = 0x0000000f;

        public const int DDOSDCAPS_OPTCOMPRESSED = 0x00000001;

        public const int DDOSDCAPS_OPTREORDERED = 0x00000002;

        public const int DDOSDCAPS_MONOLITHICMIPMAP = 0x00000004;

        public const int DDOSDCAPS_VALIDSCAPS = 0x30004800;

        public const int DDOSDCAPS_VALIDOSCAPS = 0x00000007;

        public const int DDCOLOR_BRIGHTNESS = 0x00000001;

        public const int DDCOLOR_CONTRAST = 0x00000002;

        public const int DDCOLOR_HUE = 0x00000004;

        public const int DDCOLOR_SATURATION = 0x00000008;

        public const int DDCOLOR_SHARPNESS = 0x00000010;

        public const int DDCOLOR_GAMMA = 0x00000020;

        public const int DDCOLOR_COLORENABLE = 0x00000040;

        public const int DDSCAPS_RESERVED1 = 0x00000001;

        public const int DDSCAPS_ALPHA = 0x00000002;

        public const int DDSCAPS_BACKBUFFER = 0x00000004;

        public const int DDSCAPS_COMPLEX = 0x00000008;

        public const int DDSCAPS_FLIP = 0x00000010;

        public const int DDSCAPS_FRONTBUFFER = 0x00000020;

        public const int DDSCAPS_OFFSCREENPLAIN = 0x00000040;

        public const int DDSCAPS_OVERLAY = 0x00000080;

        public const int DDSCAPS_PALETTE = 0x00000100;

        public const int DDSCAPS_PRIMARYSURFACE = 0x00000200;

        public const int DDSCAPS_RESERVED3 = 0x00000400;

        public const int DDSCAPS_PRIMARYSURFACELEFT = 0x00000000;

        public const int DDSCAPS_SYSTEMMEMORY = 0x00000800;

        public const int DDSCAPS_TEXTURE = 0x00001000;

        public const int DDSCAPS_3DDEVICE = 0x00002000;

        public const int DDSCAPS_VIDEOMEMORY = 0x00004000;

        public const int DDSCAPS_VISIBLE = 0x00008000;

        public const int DDSCAPS_WRITEONLY = 0x00010000;

        public const int DDSCAPS_ZBUFFER = 0x00020000;

        public const int DDSCAPS_OWNDC = 0x00040000;

        public const int DDSCAPS_LIVEVIDEO = 0x00080000;

        public const int DDSCAPS_HWCODEC = 0x00100000;

        public const int DDSCAPS_MODEX = 0x00200000;

        public const int DDSCAPS_MIPMAP = 0x00400000;

        public const int DDSCAPS_RESERVED2 = 0x00800000;

        public const int DDSCAPS_ALLOCONLOAD = 0x04000000;

        public const int DDSCAPS_VIDEOPORT = 0x08000000;

        public const int DDSCAPS_LOCALVIDMEM = 0x10000000;

        public const int DDSCAPS_NONLOCALVIDMEM = 0x20000000;

        public const int DDSCAPS_STANDARDVGAMODE = 0x40000000;

        public const int DDSCAPS_OPTIMIZED = unchecked((int)0x80000000);

        public const int DDSCAPS2_RESERVED4 = 0x00000002;

        public const int DDSCAPS2_HARDWAREDEINTERLACE = 0x00000000;

        public const int DDSCAPS2_HINTDYNAMIC = 0x00000004;

        public const int DDSCAPS2_HINTSTATIC = 0x00000008;

        public const int DDSCAPS2_TEXTUREMANAGE = 0x00000010;

        public const int DDSCAPS2_RESERVED1 = 0x00000020;

        public const int DDSCAPS2_RESERVED2 = 0x00000040;

        public const int DDSCAPS2_OPAQUE = 0x00000080;

        public const int DDSCAPS2_HINTANTIALIASING = 0x00000100;

        public const int DDSCAPS2_CUBEMAP = 0x00000200;

        public const int DDSCAPS2_CUBEMAP_POSITIVEX = 0x00000400;

        public const int DDSCAPS2_CUBEMAP_NEGATIVEX = 0x00000800;

        public const int DDSCAPS2_CUBEMAP_POSITIVEY = 0x00001000;

        public const int DDSCAPS2_CUBEMAP_NEGATIVEY = 0x00002000;

        public const int DDSCAPS2_CUBEMAP_POSITIVEZ = 0x00004000;

        public const int DDSCAPS2_CUBEMAP_NEGATIVEZ = 0x00008000;

        public const int DDSCAPS2_MIPMAPSUBLEVEL = 0x00010000;

        public const int DDSCAPS2_D3DTEXTUREMANAGE = 0x00020000;

        public const int DDSCAPS2_DONOTPERSIST = 0x00040000;

        public const int DDSCAPS2_STEREOSURFACELEFT = 0x00080000;

        public const int DDSCAPS2_VOLUME = 0x00200000;

        public const int DDSCAPS2_NOTUSERLOCKABLE = 0x00400000;

        public const int DDSCAPS2_POINTS = 0x00800000;

        public const int DDSCAPS2_RTPATCHES = 0x01000000;

        public const int DDSCAPS2_NPATCHES = 0x02000000;

        public const int DDSCAPS2_RESERVED3 = 0x04000000;

        public const int DDSCAPS2_DISCARDBACKBUFFER = 0x10000000;

        public const int DDSCAPS2_ENABLEALPHACHANNEL = 0x20000000;

        public const int DDSCAPS2_EXTENDEDFORMATPRIMARY = 0x40000000;

        public const int DDSCAPS2_ADDITIONALPRIMARY = unchecked((int)0x80000000);

        public const int DDSCAPS3_MULTISAMPLE_MASK = 0x0000001F;

        public const int DDSCAPS3_MULTISAMPLE_QUALITY_MASK = 0x000000E0;

        public const uint DDSCAPS3_MULTISAMPLE_QUALITY_SHIFT = 5;

        public const int DDSCAPS3_RESERVED1 = 0x00000100;

        public const int DDSCAPS3_RESERVED2 = 0x00000200;

        public const int DDSCAPS3_LIGHTWEIGHTMIPMAP = 0x00000400;

        public const int DDSCAPS3_AUTOGENMIPMAP = 0x00000800;

        public const int DDSCAPS3_DMAP = 0x00001000;

        public const int DDSCAPS3_CREATESHAREDRESOURCE = 0x00002000;

        public const int DDSCAPS3_READONLYRESOURCE = 0x00004000;

        public const int DDSCAPS3_OPENSHAREDRESOURCE = 0x00008000;

        public const int DDCAPS_3D = 0x00000001;

        public const int DDCAPS_ALIGNBOUNDARYDEST = 0x00000002;

        public const int DDCAPS_ALIGNSIZEDEST = 0x00000004;

        public const int DDCAPS_ALIGNBOUNDARYSRC = 0x00000008;

        public const int DDCAPS_ALIGNSIZESRC = 0x00000010;

        public const int DDCAPS_ALIGNSTRIDE = 0x00000020;

        public const int DDCAPS_BLT = 0x00000040;

        public const int DDCAPS_BLTQUEUE = 0x00000080;

        public const int DDCAPS_BLTFOURCC = 0x00000100;

        public const int DDCAPS_BLTSTRETCH = 0x00000200;

        public const int DDCAPS_GDI = 0x00000400;

        public const int DDCAPS_OVERLAY = 0x00000800;

        public const int DDCAPS_OVERLAYCANTCLIP = 0x00001000;

        public const int DDCAPS_OVERLAYFOURCC = 0x00002000;

        public const int DDCAPS_OVERLAYSTRETCH = 0x00004000;

        public const int DDCAPS_PALETTE = 0x00008000;

        public const int DDCAPS_PALETTEVSYNC = 0x00010000;

        public const int DDCAPS_READSCANLINE = 0x00020000;

        public const int DDCAPS_RESERVED1 = 0x00040000;

        public const int DDCAPS_VBI = 0x00080000;

        public const int DDCAPS_ZBLTS = 0x00100000;

        public const int DDCAPS_ZOVERLAYS = 0x00200000;

        public const int DDCAPS_COLORKEY = 0x00400000;

        public const int DDCAPS_ALPHA = 0x00800000;

        public const int DDCAPS_COLORKEYHWASSIST = 0x01000000;

        public const int DDCAPS_NOHARDWARE = 0x02000000;

        public const int DDCAPS_BLTCOLORFILL = 0x04000000;

        public const int DDCAPS_BANKSWITCHED = 0x08000000;

        public const int DDCAPS_BLTDEPTHFILL = 0x10000000;

        public const int DDCAPS_CANCLIP = 0x20000000;

        public const int DDCAPS_CANCLIPSTRETCHED = 0x40000000;

        public const int DDCAPS_CANBLTSYSMEM = unchecked((int)0x80000000);

        public const int DDCAPS2_CERTIFIED = 0x00000001;

        public const int DDCAPS2_NO2DDURING3DSCENE = 0x00000002;

        public const int DDCAPS2_VIDEOPORT = 0x00000004;

        public const int DDCAPS2_AUTOFLIPOVERLAY = 0x00000008;

        public const int DDCAPS2_CANBOBINTERLEAVED = 0x00000010;

        public const int DDCAPS2_CANBOBNONINTERLEAVED = 0x00000020;

        public const int DDCAPS2_COLORCONTROLOVERLAY = 0x00000040;

        public const int DDCAPS2_COLORCONTROLPRIMARY = 0x00000080;

        public const int DDCAPS2_CANDROPZ16BIT = 0x00000100;

        public const int DDCAPS2_NONLOCALVIDMEM = 0x00000200;

        public const int DDCAPS2_NONLOCALVIDMEMCAPS = 0x00000400;

        public const int DDCAPS2_NOPAGELOCKREQUIRED = 0x00000800;

        public const int DDCAPS2_WIDESURFACES = 0x00001000;

        public const int DDCAPS2_CANFLIPODDEVEN = 0x00002000;

        public const int DDCAPS2_CANBOBHARDWARE = 0x00004000;

        public const int DDCAPS2_COPYFOURCC = 0x00008000;

        public const int DDCAPS2_PRIMARYGAMMA = 0x00020000;

        public const int DDCAPS2_CANRENDERWINDOWED = 0x00080000;

        public const int DDCAPS2_CANCALIBRATEGAMMA = 0x00100000;

        public const int DDCAPS2_FLIPINTERVAL = 0x00200000;

        public const int DDCAPS2_FLIPNOVSYNC = 0x00400000;

        public const int DDCAPS2_CANMANAGETEXTURE = 0x00800000;

        public const int DDCAPS2_TEXMANINNONLOCALVIDMEM = 0x01000000;

        public const int DDCAPS2_STEREO = 0x02000000;

        public const int DDCAPS2_SYSTONONLOCAL_AS_SYSTOLOCAL = 0x04000000;

        public const int DDCAPS2_RESERVED1 = 0x08000000;

        public const int DDCAPS2_CANMANAGERESOURCE = 0x10000000;

        public const int DDCAPS2_DYNAMICTEXTURES = 0x20000000;

        public const int DDCAPS2_CANAUTOGENMIPMAP = 0x40000000;

        public const int DDCAPS2_CANSHARERESOURCE = unchecked((int)0x80000000);

        public const int DDFXALPHACAPS_BLTALPHAEDGEBLEND = 0x00000001;

        public const int DDFXALPHACAPS_BLTALPHAPIXELS = 0x00000002;

        public const int DDFXALPHACAPS_BLTALPHAPIXELSNEG = 0x00000004;

        public const int DDFXALPHACAPS_BLTALPHASURFACES = 0x00000008;

        public const int DDFXALPHACAPS_BLTALPHASURFACESNEG = 0x00000010;

        public const int DDFXALPHACAPS_OVERLAYALPHAEDGEBLEND = 0x00000020;

        public const int DDFXALPHACAPS_OVERLAYALPHAPIXELS = 0x00000040;

        public const int DDFXALPHACAPS_OVERLAYALPHAPIXELSNEG = 0x00000080;

        public const int DDFXALPHACAPS_OVERLAYALPHASURFACES = 0x00000100;

        public const int DDFXALPHACAPS_OVERLAYALPHASURFACESNEG = 0x00000200;

        public const int DDFXCAPS_BLTARITHSTRETCHY = 0x00000020;

        public const int DDFXCAPS_BLTARITHSTRETCHYN = 0x00000010;

        public const int DDFXCAPS_BLTMIRRORLEFTRIGHT = 0x00000040;

        public const int DDFXCAPS_BLTMIRRORUPDOWN = 0x00000080;

        public const int DDFXCAPS_BLTROTATION = 0x00000100;

        public const int DDFXCAPS_BLTROTATION90 = 0x00000200;

        public const int DDFXCAPS_BLTSHRINKX = 0x00000400;

        public const int DDFXCAPS_BLTSHRINKXN = 0x00000800;

        public const int DDFXCAPS_BLTSHRINKY = 0x00001000;

        public const int DDFXCAPS_BLTSHRINKYN = 0x00002000;

        public const int DDFXCAPS_BLTSTRETCHX = 0x00004000;

        public const int DDFXCAPS_BLTSTRETCHXN = 0x00008000;

        public const int DDFXCAPS_BLTSTRETCHY = 0x00010000;

        public const int DDFXCAPS_BLTSTRETCHYN = 0x00020000;

        public const int DDFXCAPS_OVERLAYARITHSTRETCHY = 0x00040000;

        public const int DDFXCAPS_OVERLAYARITHSTRETCHYN = 0x00000008;

        public const int DDFXCAPS_OVERLAYSHRINKX = 0x00080000;

        public const int DDFXCAPS_OVERLAYSHRINKXN = 0x00100000;

        public const int DDFXCAPS_OVERLAYSHRINKY = 0x00200000;

        public const int DDFXCAPS_OVERLAYSHRINKYN = 0x00400000;

        public const int DDFXCAPS_OVERLAYSTRETCHX = 0x00800000;

        public const int DDFXCAPS_OVERLAYSTRETCHXN = 0x01000000;

        public const int DDFXCAPS_OVERLAYSTRETCHY = 0x02000000;

        public const int DDFXCAPS_OVERLAYSTRETCHYN = 0x04000000;

        public const int DDFXCAPS_OVERLAYMIRRORLEFTRIGHT = 0x08000000;

        public const int DDFXCAPS_OVERLAYMIRRORUPDOWN = 0x10000000;

        public const int DDFXCAPS_OVERLAYDEINTERLACE = 0x20000000;

        public const int DDFXCAPS_BLTALPHA = 0x00000001;

        public const int DDFXCAPS_OVERLAYALPHA = 0x00000004;

        public const int DDSVCAPS_RESERVED1 = 0x00000001;

        public const int DDSVCAPS_RESERVED2 = 0x00000002;

        public const int DDSVCAPS_RESERVED3 = 0x00000004;

        public const int DDSVCAPS_RESERVED4 = 0x00000008;

        public const int DDSVCAPS_STEREOSEQUENTIAL = 0x00000010;

        public const int DDPCAPS_4BIT = 0x00000001;

        public const int DDPCAPS_8BITENTRIES = 0x00000002;

        public const int DDPCAPS_8BIT = 0x00000004;

        public const int DDPCAPS_INITIALIZE = 0x00000000;

        public const int DDPCAPS_PRIMARYSURFACE = 0x00000010;

        public const int DDPCAPS_PRIMARYSURFACELEFT = 0x00000020;

        public const int DDPCAPS_ALLOW256 = 0x00000040;

        public const int DDPCAPS_VSYNC = 0x00000080;

        public const int DDPCAPS_1BIT = 0x00000100;

        public const int DDPCAPS_2BIT = 0x00000200;

        public const int DDPCAPS_ALPHA = 0x00000400;

        public const int DDSPD_IUNKNOWNPOINTER = 0x00000001;

        public const int DDSPD_VOLATILE = 0x00000002;

        public const int DDBD_1 = 0x00004000;

        public const int DDBD_2 = 0x00002000;

        public const int DDBD_4 = 0x00001000;

        public const int DDBD_8 = 0x00000800;

        public const int DDBD_16 = 0x00000400;

        public const int DDBD_24 = 0X00000200;

        public const int DDBD_32 = 0x00000100;

        public const int DDCKEY_COLORSPACE = 0x00000001;

        public const int DDCKEY_DESTBLT = 0x00000002;

        public const int DDCKEY_DESTOVERLAY = 0x00000004;

        public const int DDCKEY_SRCBLT = 0x00000008;

        public const int DDCKEY_SRCOVERLAY = 0x00000010;

        public const int DDCKEYCAPS_DESTBLT = 0x00000001;

        public const int DDCKEYCAPS_DESTBLTCLRSPACE = 0x00000002;

        public const int DDCKEYCAPS_DESTBLTCLRSPACEYUV = 0x00000004;

        public const int DDCKEYCAPS_DESTBLTYUV = 0x00000008;

        public const int DDCKEYCAPS_DESTOVERLAY = 0x00000010;

        public const int DDCKEYCAPS_DESTOVERLAYCLRSPACE = 0x00000020;

        public const int DDCKEYCAPS_DESTOVERLAYCLRSPACEYUV = 0x00000040;

        public const int DDCKEYCAPS_DESTOVERLAYONEACTIVE = 0x00000080;

        public const int DDCKEYCAPS_DESTOVERLAYYUV = 0x00000100;

        public const int DDCKEYCAPS_SRCBLT = 0x00000200;

        public const int DDCKEYCAPS_SRCBLTCLRSPACE = 0x00000400;

        public const int DDCKEYCAPS_SRCBLTCLRSPACEYUV = 0x00000800;

        public const int DDCKEYCAPS_SRCBLTYUV = 0x00001000;

        public const int DDCKEYCAPS_SRCOVERLAY = 0x00002000;

        public const int DDCKEYCAPS_SRCOVERLAYCLRSPACE = 0x00004000;

        public const int DDCKEYCAPS_SRCOVERLAYCLRSPACEYUV = 0x00008000;

        public const int DDCKEYCAPS_SRCOVERLAYONEACTIVE = 0x00010000;

        public const int DDCKEYCAPS_SRCOVERLAYYUV = 0x00020000;

        public const int DDCKEYCAPS_NOCOSTOVERLAY = 0x00040000;

        public const int DDPF_ALPHAPIXELS = 0x00000001;

        public const int DDPF_ALPHA = 0x00000002;

        public const int DDPF_PALETTEINDEXED4 = 0x00000008;

        public const int DDPF_PALETTEINDEXEDTO8 = 0x00000010;

        public const int DDPF_PALETTEINDEXED8 = 0x00000020;

        public const int DDPF_RGB = 0x00000040;

        public const int DDPF_COMPRESSED = 0x00000080;

        public const int DDPF_RGBTOYUV = 0x00000100;

        public const int DDPF_YUV = 0x00000200;

        public const int DDPF_ZBUFFER = 0x00000400;

        public const int DDPF_PALETTEINDEXED1 = 0x00000800;

        public const int DDPF_PALETTEINDEXED2 = 0x00001000;

        public const int DDPF_ZPIXELS = 0x00002000;

        public const int DDPF_STENCILBUFFER = 0x00004000;

        public const int DDPF_ALPHAPREMULT = 0x00008000;

        public const int DDPF_LUMINANCE = 0x00020000;

        public const int DDPF_BUMPLUMINANCE = 0x00040000;

        public const int DDPF_BUMPDUDV = 0x00080000;

        public const int DDENUMSURFACES_ALL = 0x00000001;

        public const int DDENUMSURFACES_MATCH = 0x00000002;

        public const int DDENUMSURFACES_NOMATCH = 0x00000004;

        public const int DDENUMSURFACES_CANBECREATED = 0x00000008;

        public const int DDENUMSURFACES_DOESEXIST = 0x00000010;

        public const int DDSDM_STANDARDVGAMODE = 0x00000001;

        public const int DDEDM_REFRESHRATES = 0x00000001;

        public const int DDEDM_STANDARDVGAMODES = 0x00000002;

        public const int DDSCL_FULLSCREEN = 0x00000001;

        public const int DDSCL_ALLOWREBOOT = 0x00000002;

        public const int DDSCL_NOWINDOWCHANGES = 0x00000004;

        public const int DDSCL_NORMAL = 0x00000008;

        public const int DDSCL_EXCLUSIVE = 0x00000010;

        public const int DDSCL_ALLOWMODEX = 0x00000040;

        public const int DDSCL_SETFOCUSWINDOW = 0x00000080;

        public const int DDSCL_SETDEVICEWINDOW = 0x00000100;

        public const int DDSCL_CREATEDEVICEWINDOW = 0x00000200;

        public const int DDSCL_MULTITHREADED = 0x00000400;

        public const int DDSCL_FPUSETUP = 0x00000800;

        public const int DDSCL_FPUPRESERVE = 0x00001000;

        public const int DDBLT_ALPHADEST = 0x00000001;

        public const int DDBLT_ALPHADESTCONSTOVERRIDE = 0x00000002;

        public const int DDBLT_ALPHADESTNEG = 0x00000004;

        public const int DDBLT_ALPHADESTSURFACEOVERRIDE = 0x00000008;

        public const int DDBLT_ALPHAEDGEBLEND = 0x00000010;

        public const int DDBLT_ALPHASRC = 0x00000020;

        public const int DDBLT_ALPHASRCCONSTOVERRIDE = 0x00000040;

        public const int DDBLT_ALPHASRCNEG = 0x00000080;

        public const int DDBLT_ALPHASRCSURFACEOVERRIDE = 0x00000100;

        public const int DDBLT_ASYNC = 0x00000200;

        public const int DDBLT_COLORFILL = 0x00000400;

        public const int DDBLT_DDFX = 0x00000800;

        public const int DDBLT_DDROPS = 0x00001000;

        public const int DDBLT_KEYDEST = 0x00002000;

        public const int DDBLT_KEYDESTOVERRIDE = 0x00004000;

        public const int DDBLT_KEYSRC = 0x00008000;

        public const int DDBLT_KEYSRCOVERRIDE = 0x00010000;

        public const int DDBLT_ROP = 0x00020000;

        public const int DDBLT_ROTATIONANGLE = 0x00040000;

        public const int DDBLT_ZBUFFER = 0x00080000;

        public const int DDBLT_ZBUFFERDESTCONSTOVERRIDE = 0x00100000;

        public const int DDBLT_ZBUFFERDESTOVERRIDE = 0x00200000;

        public const int DDBLT_ZBUFFERSRCCONSTOVERRIDE = 0x00400000;

        public const int DDBLT_ZBUFFERSRCOVERRIDE = 0x00800000;

        public const int DDBLT_WAIT = 0x01000000;

        public const int DDBLT_DEPTHFILL = 0x02000000;

        public const int DDBLT_DONOTWAIT = 0x08000000;

        public const int DDBLT_PRESENTATION = 0x10000000;

        public const int DDBLT_LAST_PRESENTATION = 0x20000000;

        public const int DDBLT_EXTENDED_FLAGS = 0x40000000;

        public const int DDBLT_EXTENDED_LINEAR_CONTENT = 0x00000004;

        public const uint DDBLTFAST_NOCOLORKEY = 0x00000000;

        public const uint DDBLTFAST_SRCCOLORKEY = 0x00000001;

        public const uint DDBLTFAST_DESTCOLORKEY = 0x00000002;

        public const uint DDBLTFAST_WAIT = 0x00000010;

        public const uint DDBLTFAST_DONOTWAIT = 0x00000020;

        public const int DDFLIP_WAIT = 0x00000001;

        public const int DDFLIP_EVEN = 0x00000002;

        public const int DDFLIP_ODD = 0x00000004;

        public const int DDFLIP_NOVSYNC = 0x00000008;

        public const int DDFLIP_INTERVAL2 = 0x02000000;

        public const int DDFLIP_INTERVAL3 = 0x03000000;

        public const int DDFLIP_INTERVAL4 = 0x04000000;

        public const int DDFLIP_STEREO = 0x00000010;

        public const int DDFLIP_DONOTWAIT = 0x00000020;

        public const int DDOVER_ALPHADEST = 0x00000001;

        public const int DDOVER_ALPHADESTCONSTOVERRIDE = 0x00000002;

        public const int DDOVER_ALPHADESTNEG = 0x00000004;

        public const int DDOVER_ALPHADESTSURFACEOVERRIDE = 0x00000008;

        public const int DDOVER_ALPHAEDGEBLEND = 0x00000010;

        public const int DDOVER_ALPHASRC = 0x00000020;

        public const int DDOVER_ALPHASRCCONSTOVERRIDE = 0x00000040;

        public const int DDOVER_ALPHASRCNEG = 0x00000080;

        public const int DDOVER_ALPHASRCSURFACEOVERRIDE = 0x00000100;

        public const int DDOVER_HIDE = 0x00000200;

        public const int DDOVER_KEYDEST = 0x00000400;

        public const int DDOVER_KEYDESTOVERRIDE = 0x00000800;

        public const int DDOVER_KEYSRC = 0x00001000;

        public const int DDOVER_KEYSRCOVERRIDE = 0x00002000;

        public const int DDOVER_SHOW = 0x00004000;

        public const int DDOVER_ADDDIRTYRECT = 0x00008000;

        public const int DDOVER_REFRESHDIRTYRECTS = 0x00010000;

        public const int DDOVER_REFRESHALL = 0x00020000;

        public const int DDOVER_DDFX = 0x00080000;

        public const int DDOVER_AUTOFLIP = 0x00100000;

        public const int DDOVER_BOB = 0x00200000;

        public const int DDOVER_OVERRIDEBOBWEAVE = 0x00400000;

        public const int DDOVER_INTERLEAVED = 0x00800000;

        public const int DDOVER_BOBHARDWARE = 0x01000000;

        public const int DDOVER_ARGBSCALEFACTORS = 0x02000000;

        public const int DDOVER_DEGRADEARGBSCALING = 0x04000000;

        public const int DDSETSURFACEDESC_RECREATEDC = 0x00000000;

        public const int DDSETSURFACEDESC_PRESERVEDC = 0x00000001;

        public const int DDLOCK_SURFACEMEMORYPTR = 0x00000000;

        public const int DDLOCK_WAIT = 0x00000001;

        public const int DDLOCK_EVENT = 0x00000002;

        public const int DDLOCK_READONLY = 0x00000010;

        public const int DDLOCK_WRITEONLY = 0x00000020;

        public const int DDLOCK_NOSYSLOCK = 0x00000800;

        public const int DDLOCK_NOOVERWRITE = 0x00001000;

        public const int DDLOCK_DISCARDCONTENTS = 0x00002000;

        public const int DDLOCK_OKTOSWAP = 0x00002000;

        public const int DDLOCK_DONOTWAIT = 0x00004000;

        public const int DDLOCK_HASVOLUMETEXTUREBOXRECT = 0x00008000;

        public const int DDLOCK_NODIRTYUPDATE = 0x00010000;

        public const int DDBLTFX_ARITHSTRETCHY = 0x00000001;

        public const int DDBLTFX_MIRRORLEFTRIGHT = 0x00000002;

        public const int DDBLTFX_MIRRORUPDOWN = 0x00000004;

        public const int DDBLTFX_NOTEARING = 0x00000008;

        public const int DDBLTFX_ROTATE180 = 0x00000010;

        public const int DDBLTFX_ROTATE270 = 0x00000020;

        public const int DDBLTFX_ROTATE90 = 0x00000040;

        public const int DDBLTFX_ZBUFFERRANGE = 0x00000080;

        public const int DDBLTFX_ZBUFFERBASEDEST = 0x00000100;

        public const int DDOVERFX_ARITHSTRETCHY = 0x00000001;

        public const int DDOVERFX_MIRRORLEFTRIGHT = 0x00000002;

        public const int DDOVERFX_MIRRORUPDOWN = 0x00000004;

        public const int DDOVERFX_DEINTERLACE = 0x00000008;

        public const int DDWAITVB_BLOCKBEGIN = 0x00000001;

        public const int DDWAITVB_BLOCKBEGINEVENT = 0x00000002;

        public const int DDWAITVB_BLOCKEND = 0x00000004;

        public const int DDGFS_CANFLIP = 0x00000001;

        public const int DDGFS_ISFLIPDONE = 0x00000002;

        public const int DDGBS_CANBLT = 0x00000001;

        public const int DDGBS_ISBLTDONE = 0x00000002;

        public const int DDENUMOVERLAYZ_BACKTOFRONT = 0x00000000;

        public const int DDENUMOVERLAYZ_FRONTTOBACK = 0x00000001;

        public const int DDOVERZ_SENDTOFRONT = 0x00000000;

        public const int DDOVERZ_SENDTOBACK = 0x00000001;

        public const int DDOVERZ_MOVEFORWARD = 0x00000002;

        public const int DDOVERZ_MOVEBACKWARD = 0x00000003;

        public const int DDOVERZ_INSERTINFRONTOF = 0x00000004;

        public const int DDOVERZ_INSERTINBACKOF = 0x00000005;

        public const int DDSGR_CALIBRATE = 0x00000001;

        public const int DDSMT_ISTESTREQUIRED = 0x00000001;

        public const int DDEM_MODEPASSED = 0x00000001;

        public const int DDEM_MODEFAILED = 0x00000002;

        public const uint DDENUMRET_CANCEL = 0;

        public const uint DDENUMRET_OK = 1;

        public const int OBJECT_ISROOT = unchecked((int)0x80000000);

        public const uint DDUNSUPPORTEDMODE = 0xFFFFFFFF;

        public static readonly Guid GUID_MiscellaneousCallbacks__scanned__ = new Guid(0xefd60cc0, 0x49e7, 0x11d0, 0x88, 0x9d, 0x00, 0xaa, 0x00, 0xbb, 0xb7, 0x6a);

        public static readonly Guid GUID_VideoPortCallbacks__scanned__ = new Guid(0xefd60cc1, 0x49e7, 0x11d0, 0x88, 0x9d, 0x00, 0xaa, 0x00, 0xbb, 0xb7, 0x6a);

        public static readonly Guid GUID_ColorControlCallbacks__scanned__ = new Guid(0xefd60cc2, 0x49e7, 0x11d0, 0x88, 0x9d, 0x00, 0xaa, 0x00, 0xbb, 0xb7, 0x6a);

        public static readonly Guid GUID_VideoPortCaps__scanned__ = new Guid(0xefd60cc3, 0x49e7, 0x11d0, 0x88, 0x9d, 0x00, 0xaa, 0x00, 0xbb, 0xb7, 0x6a);

        public static readonly Guid GUID_D3DCallbacks2__scanned__ = new Guid(0x0ba584e1, 0x70b6, 0x11d0, 0x88, 0x9d, 0x00, 0xaa, 0x00, 0xbb, 0xb7, 0x6a);

        public static readonly Guid GUID_D3DCallbacks3__scanned__ = new Guid(0xddf41230, 0xec0a, 0x11d0, 0xa9, 0xb6, 0x00, 0xaa, 0x00, 0xc0, 0x99, 0x3e);

        public static readonly Guid GUID_NonLocalVidMemCaps__scanned__ = new Guid(0x86c4fa80, 0x8d84, 0x11d0, 0x94, 0xe8, 0x00, 0xc0, 0x4f, 0xc3, 0x41, 0x37);

        public static readonly Guid GUID_KernelCallbacks__scanned__ = new Guid(0x80863800, 0x6B06, 0x11D0, 0x9B, 0x06, 0x0, 0xA0, 0xC9, 0x03, 0xA3, 0xB8);

        public static readonly Guid GUID_KernelCaps__scanned__ = new Guid(0xFFAA7540, 0x7AA8, 0x11D0, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8);

        public static readonly Guid GUID_D3DExtendedCaps__scanned__ = new Guid(0x7de41f80, 0x9d93, 0x11d0, 0x89, 0xab, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x29);

        public static readonly Guid GUID_ZPixelFormats__scanned__ = new Guid(0x93869880, 0x36cf, 0x11d1, 0x9b, 0x1b, 0x0, 0xaa, 0x0, 0xbb, 0xb8, 0xae);

        public static readonly Guid GUID_DDMoreSurfaceCaps__scanned__ = new Guid(0x3b8a0466, 0xf269, 0x11d1, 0x88, 0x0b, 0x0, 0xc0, 0x4f, 0xd9, 0x30, 0xc5);

        public static readonly Guid GUID_DDStereoMode__scanned__ = new Guid(0xf828169c, 0xa8e8, 0x11d2, 0xa1, 0xf2, 0x0, 0xa0, 0xc9, 0x83, 0xea, 0xf6);

        public static readonly Guid GUID_OptSurfaceKmodeInfo__scanned__ = new Guid(0xe05c8472, 0x51d4, 0x11d1, 0x8c, 0xce, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0xa8);

        public static readonly Guid GUID_OptSurfaceUmodeInfo__scanned__ = new Guid(0x9d792804, 0x5fa8, 0x11d1, 0x8c, 0xd0, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0xa8);

        public static readonly Guid GUID_UserModeDriverInfo__scanned__ = new Guid(0xf0b0e8e2, 0x5f97, 0x11d1, 0x8c, 0xd0, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0xa8);

        public static readonly Guid GUID_UserModeDriverPassword__scanned__ = new Guid(0x97f861b6, 0x60a1, 0x11d1, 0x8c, 0xd0, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0xa8);

        public static readonly Guid GUID_D3DParseUnknownCommandCallback__scanned__ = new Guid(0x2e04ffa0, 0x98e4, 0x11d1, 0x8c, 0xe1, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0xa8);

        public static readonly Guid GUID_MotionCompCallbacks__scanned__ = new Guid(0xb1122b40, 0x5dA5, 0x11d1, 0x8f, 0xcF, 0x00, 0xc0, 0x4f, 0xc2, 0x9b, 0x4e);

        public static readonly Guid GUID_Miscellaneous2Callbacks__scanned__ = new Guid(0x406B2F00, 0x3E5A, 0x11D1, 0xB6, 0x40, 0x00, 0xAA, 0x00, 0xA1, 0xF9, 0x6A);

        public const int DDPF_NOVEL_TEXTURE_FORMAT = 0x00100000;

        public const int DDPF_D3DFORMAT = 0x00200000;

        public const int D3DFORMAT_OP_TEXTURE = 0x00000001;

        public const int D3DFORMAT_OP_VOLUMETEXTURE = 0x00000002;

        public const int D3DFORMAT_OP_CUBETEXTURE = 0x00000004;

        public const int D3DFORMAT_OP_OFFSCREEN_RENDERTARGET = 0x00000008;

        public const int D3DFORMAT_OP_SAME_FORMAT_RENDERTARGET = 0x00000010;

        public const int D3DFORMAT_OP_ZSTENCIL = 0x00000040;

        public const int D3DFORMAT_OP_ZSTENCIL_WITH_ARBITRARY_COLOR_DEPTH = 0x00000080;

        public const int D3DFORMAT_OP_SAME_FORMAT_UP_TO_ALPHA_RENDERTARGET = 0x00000100;

        public const int D3DFORMAT_OP_DISPLAYMODE = 0x00000400;

        public const int D3DFORMAT_OP_3DACCELERATION = 0x00000800;

        public const int D3DFORMAT_OP_PIXELSIZE = 0x00001000;

        public const int D3DFORMAT_OP_CONVERT_TO_ARGB = 0x00002000;

        public const int D3DFORMAT_OP_OFFSCREENPLAIN = 0x00004000;

        public const int D3DFORMAT_OP_SRGBREAD = 0x00008000;

        public const int D3DFORMAT_OP_BUMPMAP = 0x00010000;

        public const int D3DFORMAT_OP_DMAP = 0x00020000;

        public const int D3DFORMAT_OP_NOFILTER = 0x00040000;

        public const int D3DFORMAT_MEMBEROFGROUP_ARGB = 0x00080000;

        public const int D3DFORMAT_OP_SRGBWRITE = 0x00100000;

        public const int D3DFORMAT_OP_NOALPHABLEND = 0x00200000;

        public const int D3DFORMAT_OP_AUTOGENMIPMAP = 0x00400000;

        public const int D3DFORMAT_OP_VERTEXTEXTURE = 0x00800000;

        public const int D3DFORMAT_OP_NOTEXCOORDWRAPNORMIP = 0x01000000;

        public const uint DELETED_OK = 0;

        public const uint DELETED_LASTONE = 1;

        public const uint DELETED_NOTFOUND = 2;

        public const uint DCICOMMAND = 3075;

        public const int DD_VERSION = 0x00000200;

        public const int DD_RUNTIME_VERSION = 0x00000902;

        public const uint DD_HAL_VERSION = 0x0100;

        public const uint DDCREATEDRIVEROBJECT = 10;

        public const uint DDGET32BITDRIVERNAME = 11;

        public const uint DDNEWCALLBACKFNS = 12;

        public const uint DDVERSIONINFO = 13;

        public const uint CCHDEVICENAME = 32;

        public const uint MAX_PALETTE_SIZE = 256;

        public const uint MAX_AUTOFLIP_BUFFERS = 10;

        public const uint D3DFMT_INTERNAL_D32 = 71;

        public const uint D3DFMT_INTERNAL_S1D15 = 72;

        public const uint D3DFMT_INTERNAL_D15S1 = 73;

        public const uint D3DFMT_INTERNAL_S8D24 = 74;

        public const uint D3DFMT_INTERNAL_D24S8 = 75;

        public const uint D3DFMT_INTERNAL_X8D24 = 76;

        public const uint D3DFMT_INTERNAL_D24X8 = 77;

        public const int DDHAL_PLEASEALLOC_BLOCKSIZE = 0x00000002;

        public const int DDHAL_PLEASEALLOC_LINEARSIZE = 0x00000003;

        public const int VIDMEM_ISLINEAR = 0x00000001;

        public const int VIDMEM_ISRECTANGULAR = 0x00000002;

        public const int VIDMEM_ISHEAP = 0x00000004;

        public const int VIDMEM_ISNONLOCAL = 0x00000008;

        public const int VIDMEM_ISWC = 0x00000010;

        public const int VIDMEM_HEAPDISABLED = 0x00000020;

        public const int HEAPALIASINFO_MAPPEDREAL = 0x00000001;

        public const int HEAPALIASINFO_MAPPEDDUMMY = 0x00000002;

        public const int DDHAL_CB32_DESTROYDRIVER = 0x00000001;

        public const int DDHAL_CB32_CREATESURFACE = 0x00000002;

        public const int DDHAL_CB32_SETCOLORKEY = 0x00000004;

        public const int DDHAL_CB32_SETMODE = 0x00000008;

        public const int DDHAL_CB32_WAITFORVERTICALBLANK = 0x00000010;

        public const int DDHAL_CB32_CANCREATESURFACE = 0x00000020;

        public const int DDHAL_CB32_CREATEPALETTE = 0x00000040;

        public const int DDHAL_CB32_GETSCANLINE = 0x00000080;

        public const int DDHAL_CB32_SETEXCLUSIVEMODE = 0x00000100;

        public const int DDHAL_CB32_FLIPTOGDISURFACE = 0x00000200;

        public const int DDHAL_PALCB32_DESTROYPALETTE = 0x00000001;

        public const int DDHAL_PALCB32_SETENTRIES = 0x00000002;

        public const int DDHAL_SURFCB32_DESTROYSURFACE = 0x00000001;

        public const int DDHAL_SURFCB32_FLIP = 0x00000002;

        public const int DDHAL_SURFCB32_SETCLIPLIST = 0x00000004;

        public const int DDHAL_SURFCB32_LOCK = 0x00000008;

        public const int DDHAL_SURFCB32_UNLOCK = 0x00000010;

        public const int DDHAL_SURFCB32_BLT = 0x00000020;

        public const int DDHAL_SURFCB32_SETCOLORKEY = 0x00000040;

        public const int DDHAL_SURFCB32_ADDATTACHEDSURFACE = 0x00000080;

        public const int DDHAL_SURFCB32_GETBLTSTATUS = 0x00000100;

        public const int DDHAL_SURFCB32_GETFLIPSTATUS = 0x00000200;

        public const int DDHAL_SURFCB32_UPDATEOVERLAY = 0x00000400;

        public const int DDHAL_SURFCB32_SETOVERLAYPOSITION = 0x00000800;

        public const int DDHAL_SURFCB32_RESERVED4 = 0x00001000;

        public const int DDHAL_SURFCB32_SETPALETTE = 0x00002000;

        public const int DDHAL_MISCCB32_GETAVAILDRIVERMEMORY = 0x00000001;

        public const int DDHAL_MISCCB32_UPDATENONLOCALHEAP = 0x00000002;

        public const int DDHAL_MISCCB32_GETHEAPALIGNMENT = 0x00000004;

        public const int DDHAL_MISCCB32_GETSYSMEMBLTSTATUS = 0x00000008;

        public const int DDHAL_MISC2CB32_CREATESURFACEEX = 0x00000002;

        public const int DDHAL_MISC2CB32_GETDRIVERSTATE = 0x00000004;

        public const int DDHAL_MISC2CB32_DESTROYDDLOCAL = 0x00000008;

        public const int DDHAL_EXEBUFCB32_CANCREATEEXEBUF = 0x00000001;

        public const int DDHAL_EXEBUFCB32_CREATEEXEBUF = 0x00000002;

        public const int DDHAL_EXEBUFCB32_DESTROYEXEBUF = 0x00000004;

        public const int DDHAL_EXEBUFCB32_LOCKEXEBUF = 0x00000008;

        public const int DDHAL_EXEBUFCB32_UNLOCKEXEBUF = 0x00000010;

        public const int DDHAL_VPORT32_CANCREATEVIDEOPORT = 0x00000001;

        public const int DDHAL_VPORT32_CREATEVIDEOPORT = 0x00000002;

        public const int DDHAL_VPORT32_FLIP = 0x00000004;

        public const int DDHAL_VPORT32_GETBANDWIDTH = 0x00000008;

        public const int DDHAL_VPORT32_GETINPUTFORMATS = 0x00000010;

        public const int DDHAL_VPORT32_GETOUTPUTFORMATS = 0x00000020;

        public const int DDHAL_VPORT32_GETFIELD = 0x00000080;

        public const int DDHAL_VPORT32_GETLINE = 0x00000100;

        public const int DDHAL_VPORT32_GETCONNECT = 0x00000200;

        public const int DDHAL_VPORT32_DESTROY = 0x00000400;

        public const int DDHAL_VPORT32_GETFLIPSTATUS = 0x00000800;

        public const int DDHAL_VPORT32_UPDATE = 0x00001000;

        public const int DDHAL_VPORT32_WAITFORSYNC = 0x00002000;

        public const int DDHAL_VPORT32_GETSIGNALSTATUS = 0x00004000;

        public const int DDHAL_VPORT32_COLORCONTROL = 0x00008000;

        public const int DDHAL_COLOR_COLORCONTROL = 0x00000001;

        public const int DDHAL_KERNEL_SYNCSURFACEDATA = 0x00000001;

        public const int DDHAL_KERNEL_SYNCVIDEOPORTDATA = 0x00000002;

        public const uint DDHAL_MOCOMP32_GETGUIDS = 0x00000001;

        public const uint DDHAL_MOCOMP32_GETFORMATS = 0x00000002;

        public const uint DDHAL_MOCOMP32_CREATE = 0x00000004;

        public const uint DDHAL_MOCOMP32_GETCOMPBUFFINFO = 0x00000008;

        public const uint DDHAL_MOCOMP32_GETINTERNALINFO = 0x00000010;

        public const uint DDHAL_MOCOMP32_BEGINFRAME = 0x00000020;

        public const uint DDHAL_MOCOMP32_ENDFRAME = 0x00000040;

        public const uint DDHAL_MOCOMP32_RENDER = 0x00000080;

        public const uint DDHAL_MOCOMP32_QUERYSTATUS = 0x00000100;

        public const uint DDHAL_MOCOMP32_DESTROY = 0x00000200;

        public const int DDHAL_DRIVER_NOTHANDLED = 0x00000000;

        public const int DDHAL_DRIVER_HANDLED = 0x00000001;

        public const int DDHAL_DRIVER_NOCKEYHW = 0x00000002;

        public const int DDRAWIPAL_256 = 0x00000001;

        public const int DDRAWIPAL_16 = 0x00000002;

        public const int DDRAWIPAL_GDI = 0x00000004;

        public const int DDRAWIPAL_STORED_8 = 0x00000008;

        public const int DDRAWIPAL_STORED_16 = 0x00000010;

        public const int DDRAWIPAL_STORED_24 = 0x00000020;

        public const int DDRAWIPAL_EXCLUSIVE = 0x00000040;

        public const int DDRAWIPAL_INHEL = 0x00000080;

        public const int DDRAWIPAL_DIRTY = 0x00000100;

        public const int DDRAWIPAL_ALLOW256 = 0x00000200;

        public const int DDRAWIPAL_4 = 0x00000400;

        public const int DDRAWIPAL_2 = 0x00000800;

        public const int DDRAWIPAL_STORED_8INDEX = 0x00001000;

        public const int DDRAWIPAL_ALPHA = 0x00002000;

        public const int DDRAWICLIP_WATCHWINDOW = 0x00000001;

        public const int DDRAWICLIP_ISINITIALIZED = 0x00000002;

        public const int DDRAWICLIP_INMASTERSPRITELIST = 0x00000004;

        public const int DDAL_IMPLICIT = 0x00000001;

        public const int ACCESSRECT_VRAMSTYLE = 0x00000001;

        public const int ACCESSRECT_NOTHOLDINGWIN16LOCK = 0x00000002;

        public const int ACCESSRECT_BROKEN = 0x00000004;

        public const uint PFINDEX_UNINITIALIZED = 0;

        public const int DDRAWISURFGBL_MEMFREE = 0x00000001;

        public const int DDRAWISURFGBL_SYSMEMREQUESTED = 0x00000002;

        public const int DDRAWISURFGBL_ISGDISURFACE = 0x00000004;

        public const int DDRAWISURFGBL_SOFTWAREAUTOFLIP = 0x00000008;

        public const int DDRAWISURFGBL_LOCKNOTHOLDINGWIN16LOCK = 0x00000010;

        public const int DDRAWISURFGBL_LOCKVRAMSTYLE = 0x00000020;

        public const int DDRAWISURFGBL_LOCKBROKEN = 0x00000040;

        public const int DDRAWISURFGBL_IMPLICITHANDLE = 0x00000080;

        public const int DDRAWISURFGBL_ISCLIENTMEM = 0x00000100;

        public const int DDRAWISURFGBL_HARDWAREOPSOURCE = 0x00000200;

        public const int DDRAWISURFGBL_HARDWAREOPDEST = 0x00000400;

        public const int DDRAWISURFGBL_VPORTINTERLEAVED = 0x00000800;

        public const int DDRAWISURFGBL_VPORTDATA = 0x00001000;

        public const int DDRAWISURFGBL_LATEALLOCATELINEAR = 0x00002000;

        public const int DDRAWISURFGBL_SYSMEMEXECUTEBUFFER = 0x00004000;

        public const int DDRAWISURFGBL_FASTLOCKHELD = 0x00008000;

        public const int DDRAWISURFGBL_READONLYLOCKHELD = 0x00010000;

        public const int DDRAWISURFGBL_DX8SURFACE = 0x00080000;

        public const int DDRAWISURFGBL_DDHELDONTFREE = 0x00100000;

        public const int DDRAWISURFGBL_NOTIFYWHENUNLOCKED = 0x00200000;

        public const int DDRAWISURFGBL_RESERVED0 = unchecked((int)0x80000000);

        public const int DDRAWISURF_ATTACHED = 0x00000001;

        public const int DDRAWISURF_IMPLICITCREATE = 0x00000002;

        public const int DDRAWISURF_ISFREE = 0x00000004;

        public const int DDRAWISURF_ATTACHED_FROM = 0x00000008;

        public const int DDRAWISURF_IMPLICITROOT = 0x00000010;

        public const int DDRAWISURF_PARTOFPRIMARYCHAIN = 0x00000020;

        public const int DDRAWISURF_DATAISALIASED = 0x00000040;

        public const int DDRAWISURF_HASDC = 0x00000080;

        public const int DDRAWISURF_HASCKEYDESTOVERLAY = 0x00000100;

        public const int DDRAWISURF_HASCKEYDESTBLT = 0x00000200;

        public const int DDRAWISURF_HASCKEYSRCOVERLAY = 0x00000400;

        public const int DDRAWISURF_HASCKEYSRCBLT = 0x00000800;

        public const int DDRAWISURF_LOCKEXCLUDEDCURSOR = 0x00001000;

        public const int DDRAWISURF_HASPIXELFORMAT = 0x00002000;

        public const int DDRAWISURF_HASOVERLAYDATA = 0x00004000;

        public const int DDRAWISURF_SETGAMMA = 0x00008000;

        public const int DDRAWISURF_SW_CKEYDESTOVERLAY = 0x00010000;

        public const int DDRAWISURF_SW_CKEYDESTBLT = 0x00020000;

        public const int DDRAWISURF_SW_CKEYSRCOVERLAY = 0x00040000;

        public const int DDRAWISURF_SW_CKEYSRCBLT = 0x00080000;

        public const int DDRAWISURF_HW_CKEYDESTOVERLAY = 0x00100000;

        public const int DDRAWISURF_HW_CKEYDESTBLT = 0x00200000;

        public const int DDRAWISURF_HW_CKEYSRCOVERLAY = 0x00400000;

        public const int DDRAWISURF_HW_CKEYSRCBLT = 0x00800000;

        public const int DDRAWISURF_INMASTERSPRITELIST = 0x01000000;

        public const int DDRAWISURF_HELCB = 0x02000000;

        public const int DDRAWISURF_FRONTBUFFER = 0x04000000;

        public const int DDRAWISURF_BACKBUFFER = 0x08000000;

        public const int DDRAWISURF_INVALID = 0x10000000;

        public const int DDRAWISURF_DCIBUSY = 0x20000000;

        public const int DDRAWISURF_GETDCNULL = 0x40000000;

        public const int DDRAWISURF_STEREOSURFACELEFT = 0x20000000;

        public const int DDRAWISURF_DRIVERMANAGED = 0x40000000;

        public const int DDRAWISURF_DCILOCK = unchecked((int)0x80000000);

        public const int ROP_HAS_SOURCE = 0x00000001;

        public const int ROP_HAS_PATTERN = 0x00000002;

        public const uint DDMODEINFO_PALETTIZED = 0x0001;

        public const uint DDMODEINFO_MODEX = 0x0002;

        public const uint DDMODEINFO_UNSUPPORTED = 0x0004;

        public const uint DDMODEINFO_STANDARDVGA = 0x0008;

        public const uint DDMODEINFO_MAXREFRESH = 0x0010;

        public const uint DDMODEINFO_STEREO = 0x0020;

        public const int DDRAWILCL_HASEXCLUSIVEMODE = 0x00000001;

        public const int DDRAWILCL_ISFULLSCREEN = 0x00000002;

        public const int DDRAWILCL_SETCOOPCALLED = 0x00000004;

        public const int DDRAWILCL_ACTIVEYES = 0x00000008;

        public const int DDRAWILCL_ACTIVENO = 0x00000010;

        public const int DDRAWILCL_HOOKEDHWND = 0x00000020;

        public const int DDRAWILCL_ALLOWMODEX = 0x00000040;

        public const int DDRAWILCL_V1SCLBEHAVIOUR = 0x00000080;

        public const int DDRAWILCL_MODEHASBEENCHANGED = 0x00000100;

        public const int DDRAWILCL_CREATEDWINDOW = 0x00000200;

        public const int DDRAWILCL_DIRTYDC = 0x00000400;

        public const int DDRAWILCL_DISABLEINACTIVATE = 0x00000800;

        public const int DDRAWILCL_CURSORCLIPPED = 0x00001000;

        public const int DDRAWILCL_EXPLICITMONITOR = 0x00002000;

        public const int DDRAWILCL_MULTITHREADED = 0x00004000;

        public const int DDRAWILCL_FPUSETUP = 0x00008000;

        public const int DDRAWILCL_POWEREDDOWN = 0x00010000;

        public const int DDRAWILCL_DIRECTDRAW7 = 0x00020000;

        public const int DDRAWILCL_ATTEMPTEDD3DCONTEXT = 0x00040000;

        public const int DDRAWILCL_FPUPRESERVE = 0x00080000;

        public const int DDRAWILCL_DX8DRIVER = 0x00100000;

        public const int DDRAWILCL_DIRECTDRAW8 = 0x00200000;

        public const int DDRAWI_xxxxxxxxx1 = 0x00000001;

        public const int DDRAWI_xxxxxxxxx2 = 0x00000002;

        public const int DDRAWI_VIRTUALDESKTOP = 0x00000008;

        public const int DDRAWI_MODEX = 0x00000010;

        public const int DDRAWI_DISPLAYDRV = 0x00000020;

        public const int DDRAWI_FULLSCREEN = 0x00000040;

        public const int DDRAWI_MODECHANGED = 0x00000080;

        public const int DDRAWI_NOHARDWARE = 0x00000100;

        public const int DDRAWI_PALETTEINIT = 0x00000200;

        public const int DDRAWI_NOEMULATION = 0x00000400;

        public const int DDRAWI_HASCKEYDESTOVERLAY = 0x00000800;

        public const int DDRAWI_HASCKEYSRCOVERLAY = 0x00001000;

        public const int DDRAWI_HASGDIPALETTE = 0x00002000;

        public const int DDRAWI_EMULATIONINITIALIZED = 0x00004000;

        public const int DDRAWI_HASGDIPALETTE_EXCLUSIVE = 0x00008000;

        public const int DDRAWI_MODEXILLEGAL = 0x00010000;

        public const int DDRAWI_FLIPPEDTOGDI = 0x00020000;

        public const int DDRAWI_NEEDSWIN16FORVRAMLOCK = 0x00040000;

        public const int DDRAWI_PDEVICEVRAMBITCLEARED = 0x00080000;

        public const int DDRAWI_STANDARDVGA = 0x00100000;

        public const int DDRAWI_EXTENDEDALIGNMENT = 0x00200000;

        public const int DDRAWI_CHANGINGMODE = 0x00400000;

        public const int DDRAWI_GDIDRV = 0x00800000;

        public const int DDRAWI_ATTACHEDTODESKTOP = 0x01000000;

        public const int DDRAWI_UMODELOADED = 0x02000000;

        public const int DDRAWI_DDRAWDATANOTFETCHED = 0x04000000;

        public const int DDRAWI_SECONDARYDRIVERLOADED = 0x08000000;

        public const int DDRAWI_TESTINGMODES = 0x10000000;

        public const int DDRAWI_DRIVERINFO2 = 0x20000000;

        public const int DDRAWI_BADPDEV = 0x40000000;

        public const uint DDRAWIVPORT_ON = 0x00000001;

        public const uint DDRAWIVPORT_SOFTWARE_AUTOFLIP = 0x00000002;

        public const uint DDRAWIVPORT_COLORKEYANDINTERP = 0x00000004;

        public const uint DDRAWIVPORT_NOKERNELHANDLES = 0x00000008;

        public const uint DDRAWIVPORT_SOFTWARE_BOB = 0x00000010;

        public const uint DDRAWIVPORT_VBION = 0x00000020;

        public const uint DDRAWIVPORT_VIDEOON = 0x00000040;

        public const int DDHALINFO_ISPRIMARYDISPLAY = 0x00000001;

        public const int DDHALINFO_MODEXILLEGAL = 0x00000002;

        public const int DDHALINFO_GETDRIVERINFOSET = 0x00000004;

        public const int DDHALINFO_GETDRIVERINFO2 = 0x00000008;

        public const int DDWAITVB_I_TESTVB = unchecked((int)0x80000006);

        public const uint DDRAWI_VPORTSTART = 0x0001;

        public const uint DDRAWI_VPORTSTOP = 0x0002;

        public const uint DDRAWI_VPORTUPDATE = 0x0003;

        public const uint DDRAWI_VPORTGETCOLOR = 0x0001;

        public const uint DDRAWI_VPORTSETCOLOR = 0x0002;

        public const uint DDRAWI_GETCOLOR = 0x0001;

        public const uint DDRAWI_SETCOLOR = 0x0002;

        public const uint DDMCQUERY_READ = 0x00000001;

        public static readonly Guid GUID_D3DCaps__scanned__ = new Guid(0x7bf06991, 0x8794, 0x11d0, 0x91, 0x39, 0x08, 0x00, 0x36, 0xd2, 0xef, 0x02);

        public static readonly Guid GUID_D3DCallbacks__scanned__ = new Guid(0x7bf06990, 0x8794, 0x11d0, 0x91, 0x39, 0x08, 0x00, 0x36, 0xd2, 0xef, 0x02);

        public static readonly Guid GUID_DDMoreCaps__scanned__ = new Guid(0x880baf30, 0xb030, 0x11d0, 0x8e, 0xa7, 0x00, 0x60, 0x97, 0x97, 0xea, 0x5b);

        public static readonly Guid GUID_NTCallbacks__scanned__ = new Guid(0x6fe9ecde, 0xdf89, 0x11d1, 0x9d, 0xb0, 0x00, 0x60, 0x08, 0x27, 0x71, 0xba);

        public static readonly Guid GUID_GetHeapAlignment__scanned__ = new Guid(0x42e02f16, 0x7b41, 0x11d2, 0x8b, 0xff, 0x0, 0xa0, 0xc9, 0x83, 0xea, 0xf6);

        public static readonly Guid GUID_UpdateNonLocalHeap__scanned__ = new Guid(0x42e02f17, 0x7b41, 0x11d2, 0x8b, 0xff, 0x0, 0xa0, 0xc9, 0x83, 0xea, 0xf6);

        public static readonly Guid GUID_NTPrivateDriverCaps__scanned__ = new Guid(0xfad16a23, 0x7b66, 0x11d2, 0x83, 0xd7, 0x0, 0xc0, 0x4f, 0x7c, 0xe5, 0x8c);

        public static readonly Guid GUID_VPE2Callbacks__scanned__ = new Guid(0x52882147, 0x2d47, 0x469a, 0xa0, 0xd1, 0x3, 0x45, 0x58, 0x90, 0xf6, 0xc8);

        public const int DDHAL_PLEASEALLOC_USERMEM = 0x00000004;

        public const int DDHAL_CB32_MAPMEMORY = unchecked((int)0x80000000);

        public const int DDHAL_MISC2CB32_ALPHABLT = 0x00000001;

        public const int DDHAL_CREATESURFACEEX_SWAPHANDLES = 0x00000001;

        public const int DDHAL_NTCB32_FREEDRIVERMEMORY = 0x00000001;

        public const int DDHAL_NTCB32_SETEXCLUSIVEMODE = 0x00000002;

        public const int DDHAL_NTCB32_FLIPTOGDISURFACE = 0x00000004;

        public const int DDHAL_VPORT32_GETAUTOFLIPSURF = 0x00000040;

        public const int DDHAL_PRIVATECAP_ATOMICSURFACECREATION = 0x00000001;

        public const int DDHAL_PRIVATECAP_NOTIFYPRIMARYCREATION = 0x00000002;

        public const int DDHAL_PRIVATECAP_RESERVED1 = 0x00000004;

        public const int DDBLT_AFLAGS = unchecked((int)0x80000000);

        public const int DDABLT_SRCOVERDEST = 0x00000001;

        public static readonly Guid IID_IDDVideoPortContainer__scanned__ = new Guid(0x6C142760,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );

        public static readonly Guid IID_IDirectDrawVideoPort__scanned__ = new Guid(0xB36D93E0,0x2B43,0x11CF,0xA2,0xDE,0x00,0xAA,0x00,0xB9,0x33,0x56 );

        public static readonly Guid IID_IDirectDrawVideoPortNotify__scanned__ = new Guid(0xA655FB94,0x0589,0x4E57,0xB3,0x33,0x56,0x7A,0x89,0x46,0x8C,0x88);

        public static readonly Guid DDVPTYPE_E_HREFH_VREFH__scanned__ = new Guid(0x54F39980L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8);

        public static readonly Guid DDVPTYPE_E_HREFH_VREFL__scanned__ = new Guid(0x92783220L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8);

        public static readonly Guid DDVPTYPE_E_HREFL_VREFH__scanned__ = new Guid(0xA07A02E0L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8);

        public static readonly Guid DDVPTYPE_E_HREFL_VREFL__scanned__ = new Guid(0xE09C77E0L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8);

        public static readonly Guid DDVPTYPE_CCIR656__scanned__ = new Guid(0xFCA326A0L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8);

        public static readonly Guid DDVPTYPE_BROOKTREE__scanned__ = new Guid(0x1352A560L,0xDA61,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8);

        public static readonly Guid DDVPTYPE_PHILIPS__scanned__ = new Guid(0x332CF160L,0xDA61,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8);

        public const int DDVPD_WIDTH = 0x00000001;

        public const int DDVPD_HEIGHT = 0x00000002;

        public const int DDVPD_ID = 0x00000004;

        public const int DDVPD_CAPS = 0x00000008;

        public const int DDVPD_FX = 0x00000010;

        public const int DDVPD_AUTOFLIP = 0x00000020;

        public const int DDVPD_ALIGN = 0x00000040;

        public const int DDVPD_PREFERREDAUTOFLIP = 0x00000080;

        public const int DDVPD_FILTERQUALITY = 0x00000100;

        public const int DDVPCONNECT_DOUBLECLOCK = 0x00000001;

        public const int DDVPCONNECT_VACT = 0x00000002;

        public const int DDVPCONNECT_INVERTPOLARITY = 0x00000004;

        public const int DDVPCONNECT_DISCARDSVREFDATA = 0x00000008;

        public const int DDVPCONNECT_HALFLINE = 0x00000010;

        public const int DDVPCONNECT_INTERLACED = 0x00000020;

        public const int DDVPCONNECT_SHAREEVEN = 0x00000040;

        public const int DDVPCONNECT_SHAREODD = 0x00000080;

        public const int DDVPCAPS_AUTOFLIP = 0x00000001;

        public const int DDVPCAPS_INTERLACED = 0x00000002;

        public const int DDVPCAPS_NONINTERLACED = 0x00000004;

        public const int DDVPCAPS_READBACKFIELD = 0x00000008;

        public const int DDVPCAPS_READBACKLINE = 0x00000010;

        public const int DDVPCAPS_SHAREABLE = 0x00000020;

        public const int DDVPCAPS_SKIPEVENFIELDS = 0x00000040;

        public const int DDVPCAPS_SKIPODDFIELDS = 0x00000080;

        public const int DDVPCAPS_SYNCMASTER = 0x00000100;

        public const int DDVPCAPS_VBISURFACE = 0x00000200;

        public const int DDVPCAPS_COLORCONTROL = 0x00000400;

        public const int DDVPCAPS_OVERSAMPLEDVBI = 0x00000800;

        public const int DDVPCAPS_SYSTEMMEMORY = 0x00001000;

        public const int DDVPCAPS_VBIANDVIDEOINDEPENDENT = 0x00002000;

        public const int DDVPCAPS_HARDWAREDEINTERLACE = 0x00004000;

        public const int DDVPFX_CROPTOPDATA = 0x00000001;

        public const int DDVPFX_CROPX = 0x00000002;

        public const int DDVPFX_CROPY = 0x00000004;

        public const int DDVPFX_INTERLEAVE = 0x00000008;

        public const int DDVPFX_MIRRORLEFTRIGHT = 0x00000010;

        public const int DDVPFX_MIRRORUPDOWN = 0x00000020;

        public const int DDVPFX_PRESHRINKX = 0x00000040;

        public const int DDVPFX_PRESHRINKY = 0x00000080;

        public const int DDVPFX_PRESHRINKXB = 0x00000100;

        public const int DDVPFX_PRESHRINKYB = 0x00000200;

        public const int DDVPFX_PRESHRINKXS = 0x00000400;

        public const int DDVPFX_PRESHRINKYS = 0x00000800;

        public const int DDVPFX_PRESTRETCHX = 0x00001000;

        public const int DDVPFX_PRESTRETCHY = 0x00002000;

        public const int DDVPFX_PRESTRETCHXN = 0x00004000;

        public const int DDVPFX_PRESTRETCHYN = 0x00008000;

        public const int DDVPFX_VBICONVERT = 0x00010000;

        public const int DDVPFX_VBINOSCALE = 0x00020000;

        public const int DDVPFX_IGNOREVBIXCROP = 0x00040000;

        public const int DDVPFX_VBINOINTERLEAVE = 0x00080000;

        public const int DDVP_AUTOFLIP = 0x00000001;

        public const int DDVP_CONVERT = 0x00000002;

        public const int DDVP_CROP = 0x00000004;

        public const int DDVP_INTERLEAVE = 0x00000008;

        public const int DDVP_MIRRORLEFTRIGHT = 0x00000010;

        public const int DDVP_MIRRORUPDOWN = 0x00000020;

        public const int DDVP_PRESCALE = 0x00000040;

        public const int DDVP_SKIPEVENFIELDS = 0x00000080;

        public const int DDVP_SKIPODDFIELDS = 0x00000100;

        public const int DDVP_SYNCMASTER = 0x00000200;

        public const int DDVP_VBICONVERT = 0x00000400;

        public const int DDVP_VBINOSCALE = 0x00000800;

        public const int DDVP_OVERRIDEBOBWEAVE = 0x00001000;

        public const int DDVP_IGNOREVBIXCROP = 0x00002000;

        public const int DDVP_VBINOINTERLEAVE = 0x00004000;

        public const int DDVP_HARDWAREDEINTERLACE = 0x00008000;

        public const int DDVPFORMAT_VIDEO = 0x00000001;

        public const int DDVPFORMAT_VBI = 0x00000002;

        public const int DDVPTARGET_VIDEO = 0x00000001;

        public const int DDVPTARGET_VBI = 0x00000002;

        public const int DDVPWAIT_BEGIN = 0x00000001;

        public const int DDVPWAIT_END = 0x00000002;

        public const int DDVPWAIT_LINE = 0x00000003;

        public const int DDVPFLIP_VIDEO = 0x00000001;

        public const int DDVPFLIP_VBI = 0x00000002;

        public const int DDVPSQ_NOSIGNAL = 0x00000001;

        public const int DDVPSQ_SIGNALOK = 0x00000002;

        public const int DDVPB_VIDEOPORT = 0x00000001;

        public const int DDVPB_OVERLAY = 0x00000002;

        public const int DDVPB_TYPE = 0x00000004;

        public const int DDVPBCAPS_SOURCE = 0x00000001;

        public const int DDVPBCAPS_DESTINATION = 0x00000002;

        public const int DDVPCREATE_VBIONLY = 0x00000001;

        public const int DDVPCREATE_VIDEOONLY = 0x00000002;

        public const int DDVPSTATUS_VBIONLY = 0x00000001;

        public const int DDVPSTATUS_VIDEOONLY = 0x00000002;

    }
}

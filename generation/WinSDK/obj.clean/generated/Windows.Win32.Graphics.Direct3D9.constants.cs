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


namespace Windows.Win32.Graphics.Direct3D9
{
    public static partial class Apis
    {
        public const int D3DCS_LEFT = 0x00000001;

        public const int D3DCS_RIGHT = 0x00000002;

        public const int D3DCS_TOP = 0x00000004;

        public const int D3DCS_BOTTOM = 0x00000008;

        public const int D3DCS_FRONT = 0x00000010;

        public const int D3DCS_BACK = 0x00000020;

        public const int D3DCS_PLANE0 = 0x00000040;

        public const int D3DCS_PLANE1 = 0x00000080;

        public const int D3DCS_PLANE2 = 0x00000100;

        public const int D3DCS_PLANE3 = 0x00000200;

        public const int D3DCS_PLANE4 = 0x00000400;

        public const int D3DCS_PLANE5 = 0x00000800;

        public const uint D3D_MAX_SIMULTANEOUS_RENDERTARGETS = 4;

        public const int D3DWRAP_W = 0x00000004;

        public const uint D3DDMAPSAMPLER = 256;

        public const uint D3DVERTEXTEXTURESAMPLER0 = D3DDMAPSAMPLER+1;

        public const uint D3DVERTEXTEXTURESAMPLER1 = D3DDMAPSAMPLER+2;

        public const uint D3DVERTEXTEXTURESAMPLER2 = D3DDMAPSAMPLER+3;

        public const uint D3DVERTEXTEXTURESAMPLER3 = D3DDMAPSAMPLER+4;

        public const uint D3DTSS_TCI_SPHEREMAP = 0x00040000;

        public const uint D3DTA_TEMP = 0x00000005;

        public const uint D3DTA_CONSTANT = 0x00000006;

        public const uint D3DFVF_XYZW = 0x4002;

        public const uint D3DFVF_PSIZE = 0x020;

        public const uint D3DFVF_LASTBETA_UBYTE4 = 0x1000;

        public const uint D3DFVF_LASTBETA_D3DCOLOR = 0x8000;

        public const uint MAXD3DDECLUSAGEINDEX = 15;

        public const uint MAXD3DDECLLENGTH = 64;

        public const uint D3DSTREAMSOURCE_INDEXEDDATA = 1u<<30;

        public const uint D3DSTREAMSOURCE_INSTANCEDATA = 2u<<30;

        public const uint D3DSI_OPCODE_MASK = 0x0000FFFF;

        public const uint D3DSI_INSTLENGTH_MASK = 0x0F000000;

        public const uint D3DSI_INSTLENGTH_SHIFT = 24;

        public const uint D3DSI_COISSUE = 0x40000000;

        public const uint D3DSP_OPCODESPECIFICCONTROL_MASK = 0x00ff0000;

        public const uint D3DSP_OPCODESPECIFICCONTROL_SHIFT = 16;

        public const uint D3DSP_DCL_USAGE_SHIFT = 0;

        public const uint D3DSP_DCL_USAGE_MASK = 0x0000000f;

        public const uint D3DSP_DCL_USAGEINDEX_SHIFT = 16;

        public const uint D3DSP_DCL_USAGEINDEX_MASK = 0x000f0000;

        public const uint D3DSP_TEXTURETYPE_SHIFT = 27;

        public const uint D3DSP_TEXTURETYPE_MASK = 0x78000000;

        public const uint D3DSP_REGNUM_MASK = 0x000007FF;

        public const uint D3DSP_WRITEMASK_0 = 0x00010000;

        public const uint D3DSP_WRITEMASK_1 = 0x00020000;

        public const uint D3DSP_WRITEMASK_2 = 0x00040000;

        public const uint D3DSP_WRITEMASK_3 = 0x00080000;

        public const uint D3DSP_WRITEMASK_ALL = 0x000F0000;

        public const uint D3DSP_DSTMOD_SHIFT = 20;

        public const uint D3DSP_DSTMOD_MASK = 0x00F00000;

        public const uint D3DSP_DSTSHIFT_SHIFT = 24;

        public const uint D3DSP_DSTSHIFT_MASK = 0x0F000000;

        public const uint D3DSP_REGTYPE_SHIFT = 28;

        public const uint D3DSP_REGTYPE_SHIFT2 = 8;

        public const uint D3DSP_REGTYPE_MASK = 0x70000000;

        public const uint D3DSP_REGTYPE_MASK2 = 0x00001800;

        public const uint D3DVS_ADDRESSMODE_SHIFT = 13;

        public const uint D3DSHADER_ADDRESSMODE_SHIFT = 13;

        public const uint D3DVS_SWIZZLE_SHIFT = 16;

        public const uint D3DVS_SWIZZLE_MASK = 0x00FF0000;

        public const uint D3DSP_SWIZZLE_SHIFT = 16;

        public const uint D3DSP_SWIZZLE_MASK = 0x00FF0000;

        public const uint D3DSP_SRCMOD_SHIFT = 24;

        public const uint D3DSP_SRCMOD_MASK = 0x0F000000;

        public const uint D3DSP_MIN_PRECISION_SHIFT = 14;

        public const uint D3DSP_MIN_PRECISION_MASK = 0x0000C000;

        public const uint D3DSI_COMMENTSIZE_SHIFT = 16;

        public const uint D3DSI_COMMENTSIZE_MASK = 0x7FFF0000;

        public const uint D3DPRESENT_RATE_DEFAULT = 0x00000000;

        public const uint D3DPRESENTFLAG_LOCKABLE_BACKBUFFER = 0x00000001;

        public const uint D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL = 0x00000002;

        public const uint D3DPRESENTFLAG_DEVICECLIP = 0x00000004;

        public const uint D3DPRESENTFLAG_VIDEO = 0x00000010;

        public const uint D3DPRESENTFLAG_NOAUTOROTATE = 0x00000020;

        public const uint D3DPRESENTFLAG_UNPRUNEDMODE = 0x00000040;

        public const uint D3DPRESENTFLAG_OVERLAY_LIMITEDRGB = 0x00000080;

        public const uint D3DPRESENTFLAG_OVERLAY_YCbCr_BT709 = 0x00000100;

        public const uint D3DPRESENTFLAG_OVERLAY_YCbCr_xvYCC = 0x00000200;

        public const uint D3DPRESENTFLAG_RESTRICTED_CONTENT = 0x00000400;

        public const uint D3DPRESENTFLAG_RESTRICT_SHARED_RESOURCE_DRIVER = 0x00000800;

        public const int D3DUSAGE_RENDERTARGET = 0x00000001;

        public const int D3DUSAGE_DEPTHSTENCIL = 0x00000002;

        public const int D3DUSAGE_DYNAMIC = 0x00000200;

        public const int D3DUSAGE_NONSECURE = 0x00800000;

        public const int D3DUSAGE_AUTOGENMIPMAP = 0x00000400;

        public const int D3DUSAGE_DMAP = 0x00004000;

        public const int D3DUSAGE_QUERY_LEGACYBUMPMAP = 0x00008000;

        public const int D3DUSAGE_QUERY_SRGBREAD = 0x00010000;

        public const int D3DUSAGE_QUERY_FILTER = 0x00020000;

        public const int D3DUSAGE_QUERY_SRGBWRITE = 0x00040000;

        public const int D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING = 0x00080000;

        public const int D3DUSAGE_QUERY_VERTEXTEXTURE = 0x00100000;

        public const int D3DUSAGE_QUERY_WRAPANDMIP = 0x00200000;

        public const int D3DUSAGE_WRITEONLY = 0x00000008;

        public const int D3DUSAGE_SOFTWAREPROCESSING = 0x00000010;

        public const int D3DUSAGE_DONOTCLIP = 0x00000020;

        public const int D3DUSAGE_POINTS = 0x00000040;

        public const int D3DUSAGE_RTPATCHES = 0x00000080;

        public const int D3DUSAGE_NPATCHES = 0x00000100;

        public const int D3DUSAGE_TEXTAPI = 0x10000000;

        public const int D3DUSAGE_RESTRICTED_CONTENT = 0x00000800;

        public const int D3DUSAGE_RESTRICT_SHARED_RESOURCE = 0x00002000;

        public const int D3DUSAGE_RESTRICT_SHARED_RESOURCE_DRIVER = 0x00001000;

        public const int D3DLOCK_READONLY = 0x00000010;

        public const int D3DLOCK_DISCARD = 0x00002000;

        public const int D3DLOCK_NOOVERWRITE = 0x00001000;

        public const int D3DLOCK_NOSYSLOCK = 0x00000800;

        public const int D3DLOCK_DONOTWAIT = 0x00004000;

        public const int D3DLOCK_NO_DIRTY_UPDATE = 0x00008000;

        public const uint MAX_DEVICE_IDENTIFIER_STRING = 512;

        public const uint D3DISSUE_END = 1u<< 0;

        public const uint D3DISSUE_BEGIN = 1u<< 1;

        public const uint D3DGETDATA_FLUSH = 1u<< 0;

        public const uint D3DCOMPOSERECTS_MAXNUMRECTS = 0xFFFF;

        public const uint D3DCONVOLUTIONMONO_MAXWIDTH = 7;

        public const uint D3DFMT_A1_SURFACE_MAXWIDTH = 8192;

        public const uint D3DFMT_A1_SURFACE_MAXHEIGHT = 2048;

        public const uint D3D9_RESOURCE_PRIORITY_MINIMUM = 0x28000000;

        public const uint D3D9_RESOURCE_PRIORITY_LOW = 0x50000000;

        public const uint D3D9_RESOURCE_PRIORITY_NORMAL = 0x78000000;

        public const uint D3D9_RESOURCE_PRIORITY_HIGH = 0xa0000000;

        public const uint D3D9_RESOURCE_PRIORITY_MAXIMUM = 0xc8000000;

        public const uint D3D_OMAC_SIZE = 16;

        public static readonly Guid D3DAUTHENTICATEDQUERY_PROTECTION__scanned__ = new Guid(0xa84eb584, 0xc495, 0x48aa, 0xb9, 0x4d, 0x8b, 0xd2, 0xd6, 0xfb, 0xce, 0x5);

        public static readonly Guid D3DAUTHENTICATEDQUERY_CHANNELTYPE__scanned__ = new Guid(0xbc1b18a5, 0xb1fb, 0x42ab, 0xbd, 0x94, 0xb5, 0x82, 0x8b, 0x4b, 0xf7, 0xbe);

        public static readonly Guid D3DAUTHENTICATEDQUERY_DEVICEHANDLE__scanned__ = new Guid(0xec1c539d, 0x8cff, 0x4e2a, 0xbc, 0xc4, 0xf5, 0x69, 0x2f, 0x99, 0xf4, 0x80);

        public static readonly Guid D3DAUTHENTICATEDQUERY_CRYPTOSESSION__scanned__ = new Guid(0x2634499e, 0xd018, 0x4d74, 0xac, 0x17, 0x7f, 0x72, 0x40, 0x59, 0x52, 0x8d);

        public static readonly Guid D3DAUTHENTICATEDQUERY_RESTRICTEDSHAREDRESOURCEPROCESSCOUNT__scanned__ = new Guid(0xdb207b3, 0x9450, 0x46a6, 0x82, 0xde, 0x1b, 0x96, 0xd4, 0x4f, 0x9c, 0xf2);

        public static readonly Guid D3DAUTHENTICATEDQUERY_RESTRICTEDSHAREDRESOURCEPROCESS__scanned__ = new Guid(0x649bbadb, 0xf0f4, 0x4639, 0xa1, 0x5b, 0x24, 0x39, 0x3f, 0xc3, 0xab, 0xac);

        public static readonly Guid D3DAUTHENTICATEDQUERY_UNRESTRICTEDPROTECTEDSHAREDRESOURCECOUNT__scanned__ = new Guid(0x12f0bd6, 0xe662, 0x4474, 0xbe, 0xfd, 0xaa, 0x53, 0xe5, 0x14, 0x3c, 0x6d);

        public static readonly Guid D3DAUTHENTICATEDQUERY_OUTPUTIDCOUNT__scanned__ = new Guid(0x2c042b5e, 0x8c07, 0x46d5, 0xaa, 0xbe, 0x8f, 0x75, 0xcb, 0xad, 0x4c, 0x31);

        public static readonly Guid D3DAUTHENTICATEDQUERY_OUTPUTID__scanned__ = new Guid(0x839ddca3, 0x9b4e, 0x41e4, 0xb0, 0x53, 0x89, 0x2b, 0xd2, 0xa1, 0x1e, 0xe7);

        public static readonly Guid D3DAUTHENTICATEDQUERY_ACCESSIBILITYATTRIBUTES__scanned__ = new Guid(0x6214d9d2, 0x432c, 0x4abb, 0x9f, 0xce, 0x21, 0x6e, 0xea, 0x26, 0x9e, 0x3b);

        public static readonly Guid D3DAUTHENTICATEDQUERY_ENCRYPTIONWHENACCESSIBLEGUIDCOUNT__scanned__ = new Guid(0xb30f7066, 0x203c, 0x4b07, 0x93, 0xfc, 0xce, 0xaa, 0xfd, 0x61, 0x24, 0x1e);

        public static readonly Guid D3DAUTHENTICATEDQUERY_ENCRYPTIONWHENACCESSIBLEGUID__scanned__ = new Guid(0xf83a5958, 0xe986, 0x4bda, 0xbe, 0xb0, 0x41, 0x1f, 0x6a, 0x7a, 0x1, 0xb7);

        public static readonly Guid D3DAUTHENTICATEDQUERY_CURRENTENCRYPTIONWHENACCESSIBLE__scanned__ = new Guid(0xec1791c7, 0xdad3, 0x4f15, 0x9e, 0xc3, 0xfa, 0xa9, 0x3d, 0x60, 0xd4, 0xf0);

        public static readonly Guid D3DAUTHENTICATEDCONFIGURE_INITIALIZE__scanned__ = new Guid(0x6114bdb, 0x3523, 0x470a, 0x8d, 0xca, 0xfb, 0xc2, 0x84, 0x51, 0x54, 0xf0);

        public static readonly Guid D3DAUTHENTICATEDCONFIGURE_PROTECTION__scanned__ = new Guid(0x50455658, 0x3f47, 0x4362, 0xbf, 0x99, 0xbf, 0xdf, 0xcd, 0xe9, 0xed, 0x29);

        public static readonly Guid D3DAUTHENTICATEDCONFIGURE_CRYPTOSESSION__scanned__ = new Guid(0x6346cc54, 0x2cfc, 0x4ad4, 0x82, 0x24, 0xd1, 0x58, 0x37, 0xde, 0x77, 0x0);

        public static readonly Guid D3DAUTHENTICATEDCONFIGURE_SHAREDRESOURCE__scanned__ = new Guid(0x772d047, 0x1b40, 0x48e8, 0x9c, 0xa6, 0xb5, 0xf5, 0x10, 0xde, 0x9f, 0x1);

        public static readonly Guid D3DAUTHENTICATEDCONFIGURE_ENCRYPTIONWHENACCESSIBLE__scanned__ = new Guid(0x41fff286, 0x6ae0, 0x4d43, 0x9d, 0x55, 0xa4, 0x6e, 0x9e, 0xfd, 0x15, 0x8a);

        public const uint D3DVS20CAPS_PREDICATION = 1u<<0;

        public const uint D3DVS20_MAX_DYNAMICFLOWCONTROLDEPTH = 24;

        public const uint D3DVS20_MIN_DYNAMICFLOWCONTROLDEPTH = 0;

        public const uint D3DVS20_MAX_NUMTEMPS = 32;

        public const uint D3DVS20_MIN_NUMTEMPS = 12;

        public const uint D3DVS20_MAX_STATICFLOWCONTROLDEPTH = 4;

        public const uint D3DVS20_MIN_STATICFLOWCONTROLDEPTH = 1;

        public const uint D3DPS20CAPS_ARBITRARYSWIZZLE = 1u<<0;

        public const uint D3DPS20CAPS_GRADIENTINSTRUCTIONS = 1u<<1;

        public const uint D3DPS20CAPS_PREDICATION = 1u<<2;

        public const uint D3DPS20CAPS_NODEPENDENTREADLIMIT = 1u<<3;

        public const uint D3DPS20CAPS_NOTEXINSTRUCTIONLIMIT = 1u<<4;

        public const uint D3DPS20_MAX_DYNAMICFLOWCONTROLDEPTH = 24;

        public const uint D3DPS20_MIN_DYNAMICFLOWCONTROLDEPTH = 0;

        public const uint D3DPS20_MAX_NUMTEMPS = 32;

        public const uint D3DPS20_MIN_NUMTEMPS = 12;

        public const uint D3DPS20_MAX_STATICFLOWCONTROLDEPTH = 4;

        public const uint D3DPS20_MIN_STATICFLOWCONTROLDEPTH = 0;

        public const uint D3DPS20_MAX_NUMINSTRUCTIONSLOTS = 512;

        public const uint D3DPS20_MIN_NUMINSTRUCTIONSLOTS = 96;

        public const uint D3DMIN30SHADERINSTRUCTIONS = 512;

        public const uint D3DMAX30SHADERINSTRUCTIONS = 32768;

        public const uint D3DOVERLAYCAPS_FULLRANGERGB = 0x00000001;

        public const uint D3DOVERLAYCAPS_LIMITEDRANGERGB = 0x00000002;

        public const uint D3DOVERLAYCAPS_YCbCr_BT601 = 0x00000004;

        public const uint D3DOVERLAYCAPS_YCbCr_BT709 = 0x00000008;

        public const uint D3DOVERLAYCAPS_YCbCr_BT601_xvYCC = 0x00000010;

        public const uint D3DOVERLAYCAPS_YCbCr_BT709_xvYCC = 0x00000020;

        public const uint D3DOVERLAYCAPS_STRETCHX = 0x00000040;

        public const uint D3DOVERLAYCAPS_STRETCHY = 0x00000080;

        public const uint D3DCPCAPS_SOFTWARE = 0x00000001;

        public const uint D3DCPCAPS_HARDWARE = 0x00000002;

        public const uint D3DCPCAPS_PROTECTIONALWAYSON = 0x00000004;

        public const uint D3DCPCAPS_PARTIALDECRYPTION = 0x00000008;

        public const uint D3DCPCAPS_CONTENTKEY = 0x00000010;

        public const uint D3DCPCAPS_FRESHENSESSIONKEY = 0x00000020;

        public const uint D3DCPCAPS_ENCRYPTEDREADBACK = 0x00000040;

        public const uint D3DCPCAPS_ENCRYPTEDREADBACKKEY = 0x00000080;

        public const uint D3DCPCAPS_SEQUENTIAL_CTR_IV = 0x00000100;

        public const uint D3DCPCAPS_ENCRYPTSLICEDATAONLY = 0x00000200;

        public static readonly Guid D3DCRYPTOTYPE_AES128_CTR__scanned__ = new Guid(0x9b6bd711, 0x4f74, 0x41c9, 0x9e, 0x7b, 0xb, 0xe2, 0xd7, 0xd9, 0x3b, 0x4f);

        public static readonly Guid D3DCRYPTOTYPE_PROPRIETARY__scanned__ = new Guid(0xab4e9afd, 0x1d1c, 0x46e6, 0xa7, 0x2f, 0x8, 0x69, 0x91, 0x7b, 0xd, 0xe8);

        public static readonly Guid D3DKEYEXCHANGE_RSAES_OAEP__scanned__ = new Guid(0xc1949895, 0xd72a, 0x4a1d, 0x8e, 0x5d, 0xed, 0x85, 0x7d, 0x17, 0x15, 0x20);

        public static readonly Guid D3DKEYEXCHANGE_DXVA__scanned__ = new Guid(0x43d3775c, 0x38e5, 0x4924, 0x8d, 0x86, 0xd3, 0xfc, 0xcf, 0x15, 0x3e, 0x9b);

        public const int D3DCAPS_OVERLAY = 0x00000800;

        public const int D3DCAPS_READ_SCANLINE = 0x00020000;

        public const int D3DCAPS2_FULLSCREENGAMMA = 0x00020000;

        public const int D3DCAPS2_CANCALIBRATEGAMMA = 0x00100000;

        public const int D3DCAPS2_RESERVED = 0x02000000;

        public const int D3DCAPS2_CANMANAGERESOURCE = 0x10000000;

        public const int D3DCAPS2_DYNAMICTEXTURES = 0x20000000;

        public const int D3DCAPS2_CANAUTOGENMIPMAP = 0x40000000;

        public const int D3DCAPS2_CANSHARERESOURCE = unchecked((int)0x80000000);

        public const int D3DCAPS3_RESERVED = unchecked((int)0x8000001f);

        public const int D3DCAPS3_ALPHA_FULLSCREEN_FLIP_OR_DISCARD = 0x00000020;

        public const int D3DCAPS3_LINEAR_TO_SRGB_PRESENTATION = 0x00000080;

        public const int D3DCAPS3_COPY_TO_VIDMEM = 0x00000100;

        public const int D3DCAPS3_COPY_TO_SYSTEMMEM = 0x00000200;

        public const int D3DCAPS3_DXVAHD = 0x00000400;

        public const int D3DCAPS3_DXVAHD_LIMITED = 0x00000800;

        public const int D3DPRESENT_INTERVAL_DEFAULT = 0x00000000;

        public const int D3DPRESENT_INTERVAL_ONE = 0x00000001;

        public const int D3DPRESENT_INTERVAL_TWO = 0x00000002;

        public const int D3DPRESENT_INTERVAL_THREE = 0x00000004;

        public const int D3DPRESENT_INTERVAL_FOUR = 0x00000008;

        public const int D3DPRESENT_INTERVAL_IMMEDIATE = unchecked((int)0x80000000);

        public const int D3DCURSORCAPS_COLOR = 0x00000001;

        public const int D3DCURSORCAPS_LOWRES = 0x00000002;

        public const int D3DDEVCAPS_PUREDEVICE = 0x00100000;

        public const int D3DDEVCAPS_QUINTICRTPATCHES = 0x00200000;

        public const int D3DDEVCAPS_RTPATCHES = 0x00400000;

        public const int D3DDEVCAPS_RTPATCHHANDLEZERO = 0x00800000;

        public const int D3DDEVCAPS_NPATCHES = 0x01000000;

        public const int D3DPMISCCAPS_COLORWRITEENABLE = 0x00000080;

        public const int D3DPMISCCAPS_CLIPPLANESCALEDPOINTS = 0x00000100;

        public const int D3DPMISCCAPS_CLIPTLVERTS = 0x00000200;

        public const int D3DPMISCCAPS_TSSARGTEMP = 0x00000400;

        public const int D3DPMISCCAPS_BLENDOP = 0x00000800;

        public const int D3DPMISCCAPS_NULLREFERENCE = 0x00001000;

        public const int D3DPMISCCAPS_INDEPENDENTWRITEMASKS = 0x00004000;

        public const int D3DPMISCCAPS_PERSTAGECONSTANT = 0x00008000;

        public const int D3DPMISCCAPS_FOGANDSPECULARALPHA = 0x00010000;

        public const int D3DPMISCCAPS_SEPARATEALPHABLEND = 0x00020000;

        public const int D3DPMISCCAPS_MRTINDEPENDENTBITDEPTHS = 0x00040000;

        public const int D3DPMISCCAPS_MRTPOSTPIXELSHADERBLENDING = 0x00080000;

        public const int D3DPMISCCAPS_FOGVERTEXCLAMPED = 0x00100000;

        public const int D3DPMISCCAPS_POSTBLENDSRGBCONVERT = 0x00200000;

        public const int D3DLINECAPS_TEXTURE = 0x00000001;

        public const int D3DLINECAPS_ZTEST = 0x00000002;

        public const int D3DLINECAPS_BLEND = 0x00000004;

        public const int D3DLINECAPS_ALPHACMP = 0x00000008;

        public const int D3DLINECAPS_FOG = 0x00000010;

        public const int D3DLINECAPS_ANTIALIAS = 0x00000020;

        public const int D3DPRASTERCAPS_COLORPERSPECTIVE = 0x00400000;

        public const int D3DPRASTERCAPS_SCISSORTEST = 0x01000000;

        public const int D3DPRASTERCAPS_SLOPESCALEDEPTHBIAS = 0x02000000;

        public const int D3DPRASTERCAPS_DEPTHBIAS = 0x04000000;

        public const int D3DPRASTERCAPS_MULTISAMPLE_TOGGLE = 0x08000000;

        public const int D3DPBLENDCAPS_BLENDFACTOR = 0x00002000;

        public const int D3DPBLENDCAPS_SRCCOLOR2 = 0x00004000;

        public const int D3DPBLENDCAPS_INVSRCCOLOR2 = 0x00008000;

        public const int D3DPTEXTURECAPS_VOLUMEMAP = 0x00002000;

        public const int D3DPTEXTURECAPS_MIPMAP = 0x00004000;

        public const int D3DPTEXTURECAPS_MIPVOLUMEMAP = 0x00008000;

        public const int D3DPTEXTURECAPS_MIPCUBEMAP = 0x00010000;

        public const int D3DPTEXTURECAPS_CUBEMAP_POW2 = 0x00020000;

        public const int D3DPTEXTURECAPS_VOLUMEMAP_POW2 = 0x00040000;

        public const int D3DPTEXTURECAPS_NOPROJECTEDBUMPENV = 0x00200000;

        public const int D3DPTFILTERCAPS_MINFPYRAMIDALQUAD = 0x00000800;

        public const int D3DPTFILTERCAPS_MINFGAUSSIANQUAD = 0x00001000;

        public const int D3DPTFILTERCAPS_CONVOLUTIONMONO = 0x00040000;

        public const int D3DPTFILTERCAPS_MAGFPYRAMIDALQUAD = 0x08000000;

        public const int D3DPTFILTERCAPS_MAGFGAUSSIANQUAD = 0x10000000;

        public const int D3DPTADDRESSCAPS_MIRRORONCE = 0x00000020;

        public const int D3DSTENCILCAPS_TWOSIDED = 0x00000100;

        public const int D3DTEXOPCAPS_MULTIPLYADD = 0x01000000;

        public const int D3DTEXOPCAPS_LERP = 0x02000000;

        public const int D3DFVFCAPS_PSIZE = 0x00100000;

        public const int D3DVTXPCAPS_TWEENING = 0x00000040;

        public const int D3DVTXPCAPS_TEXGEN_SPHEREMAP = 0x00000100;

        public const int D3DVTXPCAPS_NO_TEXGEN_NONLOCALVIEWER = 0x00000200;

        public const int D3DDEVCAPS2_STREAMOFFSET = 0x00000001;

        public const int D3DDEVCAPS2_DMAPNPATCH = 0x00000002;

        public const int D3DDEVCAPS2_ADAPTIVETESSRTPATCH = 0x00000004;

        public const int D3DDEVCAPS2_ADAPTIVETESSNPATCH = 0x00000008;

        public const int D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES = 0x00000010;

        public const int D3DDEVCAPS2_PRESAMPLEDDMAPNPATCH = 0x00000020;

        public const int D3DDEVCAPS2_VERTEXELEMENTSCANSHARESTREAMOFFSET = 0x00000040;

        public const int D3DDTCAPS_UBYTE4 = 0x00000001;

        public const int D3DDTCAPS_UBYTE4N = 0x00000002;

        public const int D3DDTCAPS_SHORT2N = 0x00000004;

        public const int D3DDTCAPS_SHORT4N = 0x00000008;

        public const int D3DDTCAPS_USHORT2N = 0x00000010;

        public const int D3DDTCAPS_USHORT4N = 0x00000020;

        public const int D3DDTCAPS_UDEC3 = 0x00000040;

        public const int D3DDTCAPS_DEC3N = 0x00000080;

        public const int D3DDTCAPS_FLOAT16_2 = 0x00000100;

        public const int D3DDTCAPS_FLOAT16_4 = 0x00000200;

        public const int D3DSPD_IUNKNOWN = 0x00000001;

        public const int D3DCREATE_FPU_PRESERVE = 0x00000002;

        public const int D3DCREATE_MULTITHREADED = 0x00000004;

        public const int D3DCREATE_PUREDEVICE = 0x00000010;

        public const int D3DCREATE_SOFTWARE_VERTEXPROCESSING = 0x00000020;

        public const int D3DCREATE_HARDWARE_VERTEXPROCESSING = 0x00000040;

        public const int D3DCREATE_MIXED_VERTEXPROCESSING = 0x00000080;

        public const int D3DCREATE_DISABLE_DRIVER_MANAGEMENT = 0x00000100;

        public const int D3DCREATE_ADAPTERGROUP_DEVICE = 0x00000200;

        public const uint D3DADAPTER_DEFAULT = 0;

        public const int D3DENUM_NO_DRIVERVERSION = 0x00000004;

        public const int D3DPRESENT_BACK_BUFFERS_MAX = 3;

        public const int D3DSGR_NO_CALIBRATION = 0x00000000;

        public const int D3DSGR_CALIBRATE = 0x00000001;

        public const int D3DCURSOR_IMMEDIATE_UPDATE = 0x00000001;

        public const int D3DPRESENT_DONOTWAIT = 0x00000001;

        public const int D3DPRESENT_LINEAR_CONTENT = 0x00000002;

        public const uint _FACD3D = 0x876;

        public const uint D3D_SDK_VERSION = 32;

        public const uint D3D9b_SDK_VERSION = 31;

        public static readonly Guid IID_HelperName__scanned__ = new Guid(0xe4a36723, 0xfdfe, 0x4b22, 0xb1, 0x46, 0x3c, 0x4, 0xc0, 0x7f, 0x4c, 0xc8);

        public const int D3DCREATE_DISABLE_DRIVER_MANAGEMENT_EX = 0x00000400;

        public const int D3DCREATE_NOWINDOWCHANGES = 0x00000800;

        public const int D3DCREATE_DISABLE_PSGP_THREADING = 0x00002000;

        public const int D3DCREATE_ENABLE_PRESENTSTATS = 0x00004000;

        public const int D3DCREATE_DISABLE_PRINTSCREEN = 0x00008000;

        public const int D3DCREATE_SCREENSAVER = 0x10000000;

        public const int D3DENUM_WHQL_LEVEL = 0x00000002;

        public const int D3DPRESENT_BACK_BUFFERS_MAX_EX = 30;

        public const int D3DPRESENT_DONOTFLIP = 0x00000004;

        public const int D3DPRESENT_FLIPRESTART = 0x00000008;

        public const int D3DPRESENT_VIDEO_RESTRICT_TO_MONITOR = 0x00000010;

        public const int D3DPRESENT_UPDATEOVERLAYONLY = 0x00000020;

        public const int D3DPRESENT_HIDEOVERLAY = 0x00000040;

        public const int D3DPRESENT_UPDATECOLORKEY = 0x00000080;

        public const int D3DPRESENT_FORCEIMMEDIATE = 0x00000100;

    }
}

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


namespace Windows.Win32.Graphics.Direct2D
{
    public static partial class Apis
    {
        public const float D2D1_DEFAULT_FLATTENING_TOLERANCE = 0.25f;

        public static readonly Guid CLSID_D2D12DAffineTransform__scanned__ = new Guid(0x6AA97485, 0x6354, 0x4cfc, 0x90, 0x8C, 0xE4, 0xA7, 0x4F, 0x62, 0xC9, 0x6C);

        public static readonly Guid CLSID_D2D13DPerspectiveTransform__scanned__ = new Guid(0xC2844D0B, 0x3D86, 0x46e7, 0x85, 0xBA, 0x52, 0x6C, 0x92, 0x40, 0xF3, 0xFB);

        public static readonly Guid CLSID_D2D13DTransform__scanned__ = new Guid(0xe8467b04, 0xec61, 0x4b8a, 0xb5, 0xde, 0xd4, 0xd7, 0x3d, 0xeb, 0xea, 0x5a);

        public static readonly Guid CLSID_D2D1ArithmeticComposite__scanned__ = new Guid(0xfc151437, 0x049a, 0x4784, 0xa2, 0x4a, 0xf1, 0xc4, 0xda, 0xf2, 0x09, 0x87);

        public static readonly Guid CLSID_D2D1Atlas__scanned__ = new Guid(0x913e2be4, 0xfdcf, 0x4fe2, 0xa5, 0xf0, 0x24, 0x54, 0xf1, 0x4f, 0xf4, 0x8);

        public static readonly Guid CLSID_D2D1BitmapSource__scanned__ = new Guid(0x5fb6c24d, 0xc6dd, 0x4231, 0x94, 0x4,  0x50, 0xf4, 0xd5, 0xc3, 0x25, 0x2d);

        public static readonly Guid CLSID_D2D1Blend__scanned__ = new Guid(0x81c5b77b, 0x13f8, 0x4cdd, 0xad, 0x20, 0xc8, 0x90, 0x54, 0x7a, 0xc6, 0x5d);

        public static readonly Guid CLSID_D2D1Border__scanned__ = new Guid(0x2A2D49C0, 0x4ACF, 0x43c7, 0x8C, 0x6A, 0x7C, 0x4A, 0x27, 0x87, 0x4D, 0x27);

        public static readonly Guid CLSID_D2D1Brightness__scanned__ = new Guid(0x8cea8d1e, 0x77b0, 0x4986, 0xb3, 0xb9, 0x2f, 0x0c, 0x0e, 0xae, 0x78, 0x87);

        public static readonly Guid CLSID_D2D1ColorManagement__scanned__ = new Guid(0x1A28524C, 0xFDD6, 0x4AA4, 0xAE, 0x8F, 0x83, 0x7E, 0xB8, 0x26, 0x7B, 0x37);

        public static readonly Guid CLSID_D2D1ColorMatrix__scanned__ = new Guid(0x921F03D6, 0x641C, 0x47DF, 0x85, 0x2D, 0xB4, 0xBB, 0x61, 0x53, 0xAE, 0x11);

        public static readonly Guid CLSID_D2D1Composite__scanned__ = new Guid(0x48fc9f51, 0xf6ac, 0x48f1, 0x8b, 0x58, 0x3b, 0x28, 0xac, 0x46, 0xf7, 0x6d);

        public static readonly Guid CLSID_D2D1ConvolveMatrix__scanned__ = new Guid(0x407f8c08, 0x5533, 0x4331, 0xa3, 0x41, 0x23, 0xcc, 0x38, 0x77, 0x84, 0x3e);

        public static readonly Guid CLSID_D2D1Crop__scanned__ = new Guid(0xE23F7110, 0x0E9A, 0x4324, 0xAF, 0x47, 0x6A, 0x2C, 0x0C, 0x46, 0xF3, 0x5B);

        public static readonly Guid CLSID_D2D1DirectionalBlur__scanned__ = new Guid(0x174319a6, 0x58e9, 0x49b2, 0xbb, 0x63, 0xca, 0xf2, 0xc8, 0x11, 0xa3, 0xdb);

        public static readonly Guid CLSID_D2D1DiscreteTransfer__scanned__ = new Guid(0x90866fcd, 0x488e, 0x454b, 0xaf, 0x06, 0xe5, 0x04, 0x1b, 0x66, 0xc3, 0x6c);

        public static readonly Guid CLSID_D2D1DisplacementMap__scanned__ = new Guid(0xedc48364, 0x417,  0x4111, 0x94, 0x50, 0x43, 0x84, 0x5f, 0xa9, 0xf8, 0x90);

        public static readonly Guid CLSID_D2D1DistantDiffuse__scanned__ = new Guid(0x3e7efd62, 0xa32d, 0x46d4, 0xa8, 0x3c, 0x52, 0x78, 0x88, 0x9a, 0xc9, 0x54);

        public static readonly Guid CLSID_D2D1DistantSpecular__scanned__ = new Guid(0x428c1ee5, 0x77b8, 0x4450, 0x8a, 0xb5, 0x72, 0x21, 0x9c, 0x21, 0xab, 0xda);

        public static readonly Guid CLSID_D2D1DpiCompensation__scanned__ = new Guid(0x6c26c5c7, 0x34e0, 0x46fc, 0x9c, 0xfd, 0xe5, 0x82, 0x37, 0x6,  0xe2, 0x28);

        public static readonly Guid CLSID_D2D1Flood__scanned__ = new Guid(0x61c23c20, 0xae69, 0x4d8e, 0x94, 0xcf, 0x50, 0x07, 0x8d, 0xf6, 0x38, 0xf2);

        public static readonly Guid CLSID_D2D1GammaTransfer__scanned__ = new Guid(0x409444c4, 0xc419, 0x41a0, 0xb0, 0xc1, 0x8c, 0xd0, 0xc0, 0xa1, 0x8e, 0x42);

        public static readonly Guid CLSID_D2D1GaussianBlur__scanned__ = new Guid(0x1feb6d69, 0x2fe6, 0x4ac9, 0x8c, 0x58, 0x1d, 0x7f, 0x93, 0xe7, 0xa6, 0xa5);

        public static readonly Guid CLSID_D2D1Scale__scanned__ = new Guid(0x9daf9369, 0x3846, 0x4d0e, 0xa4, 0x4e, 0xc,  0x60, 0x79, 0x34, 0xa5, 0xd7);

        public static readonly Guid CLSID_D2D1Histogram__scanned__ = new Guid(0x881db7d0, 0xf7ee, 0x4d4d, 0xa6, 0xd2, 0x46, 0x97, 0xac, 0xc6, 0x6e, 0xe8);

        public static readonly Guid CLSID_D2D1HueRotation__scanned__ = new Guid(0x0f4458ec, 0x4b32, 0x491b, 0x9e, 0x85, 0xbd, 0x73, 0xf4, 0x4d, 0x3e, 0xb6);

        public static readonly Guid CLSID_D2D1LinearTransfer__scanned__ = new Guid(0xad47c8fd, 0x63ef, 0x4acc, 0x9b, 0x51, 0x67, 0x97, 0x9c, 0x03, 0x6c, 0x06);

        public static readonly Guid CLSID_D2D1LuminanceToAlpha__scanned__ = new Guid(0x41251ab7, 0x0beb, 0x46f8, 0x9d, 0xa7, 0x59, 0xe9, 0x3f, 0xcc, 0xe5, 0xde);

        public static readonly Guid CLSID_D2D1Morphology__scanned__ = new Guid(0xeae6c40d, 0x626a, 0x4c2d, 0xbf, 0xcb, 0x39, 0x10, 0x01, 0xab, 0xe2, 0x02);

        public static readonly Guid CLSID_D2D1OpacityMetadata__scanned__ = new Guid(0x6c53006a, 0x4450, 0x4199, 0xaa, 0x5b, 0xad, 0x16, 0x56, 0xfe, 0xce, 0x5e);

        public static readonly Guid CLSID_D2D1PointDiffuse__scanned__ = new Guid(0xb9e303c3, 0xc08c, 0x4f91, 0x8b, 0x7b, 0x38, 0x65, 0x6b, 0xc4, 0x8c, 0x20);

        public static readonly Guid CLSID_D2D1PointSpecular__scanned__ = new Guid(0x09c3ca26, 0x3ae2, 0x4f09, 0x9e, 0xbc, 0xed, 0x38, 0x65, 0xd5, 0x3f, 0x22);

        public static readonly Guid CLSID_D2D1Premultiply__scanned__ = new Guid(0x06eab419, 0xdeed, 0x4018, 0x80, 0xd2, 0x3e, 0x1d, 0x47, 0x1a, 0xde, 0xb2);

        public static readonly Guid CLSID_D2D1Saturation__scanned__ = new Guid(0x5cb2d9cf, 0x327d, 0x459f, 0xa0, 0xce, 0x40, 0xc0, 0xb2, 0x08, 0x6b, 0xf7);

        public static readonly Guid CLSID_D2D1Shadow__scanned__ = new Guid(0xC67EA361, 0x1863, 0x4e69, 0x89, 0xDB, 0x69, 0x5D, 0x3E, 0x9A, 0x5B, 0x6B);

        public static readonly Guid CLSID_D2D1SpotDiffuse__scanned__ = new Guid(0x818a1105, 0x7932, 0x44f4, 0xaa, 0x86, 0x08, 0xae, 0x7b, 0x2f, 0x2c, 0x93);

        public static readonly Guid CLSID_D2D1SpotSpecular__scanned__ = new Guid(0xedae421e, 0x7654, 0x4a37, 0x9d, 0xb8, 0x71, 0xac, 0xc1, 0xbe, 0xb3, 0xc1);

        public static readonly Guid CLSID_D2D1TableTransfer__scanned__ = new Guid(0x5bf818c3, 0x5e43, 0x48cb, 0xb6, 0x31, 0x86, 0x83, 0x96, 0xd6, 0xa1, 0xd4);

        public static readonly Guid CLSID_D2D1Tile__scanned__ = new Guid(0xB0784138, 0x3B76, 0x4bc5, 0xB1, 0x3B, 0x0F, 0xA2, 0xAD, 0x02, 0x65, 0x9F);

        public static readonly Guid CLSID_D2D1Turbulence__scanned__ = new Guid(0xCF2BB6AE, 0x889A, 0x4ad7, 0xBA, 0x29, 0xA2, 0xFD, 0x73, 0x2C, 0x9F, 0xC9);

        public static readonly Guid CLSID_D2D1UnPremultiply__scanned__ = new Guid(0xfb9ac489, 0xad8d, 0x41ed, 0x99, 0x99, 0xbb, 0x63, 0x47, 0xd1, 0x10, 0xf7);

        public static readonly Guid CLSID_D2D1YCbCr__scanned__ = new Guid(0x99503cc1, 0x66c7, 0x45c9, 0xa8, 0x75, 0x8a, 0xd8, 0xa7, 0x91, 0x44, 0x01);

        public static readonly Guid CLSID_D2D1Contrast__scanned__ = new Guid(0xb648a78a, 0x0ed5, 0x4f80, 0xa9, 0x4a, 0x8e, 0x82, 0x5a, 0xca, 0x6b, 0x77);

        public static readonly Guid CLSID_D2D1RgbToHue__scanned__ = new Guid(0x23f3e5ec, 0x91e8, 0x4d3d, 0xad, 0x0a, 0xaf, 0xad, 0xc1, 0x00, 0x4a, 0xa1);

        public static readonly Guid CLSID_D2D1HueToRgb__scanned__ = new Guid(0x7b78a6bd, 0x0141, 0x4def, 0x8a, 0x52, 0x63, 0x56, 0xee, 0x0c, 0xbd, 0xd5);

        public static readonly Guid CLSID_D2D1ChromaKey__scanned__ = new Guid(0x74C01F5B, 0x2A0D, 0x408C, 0x88, 0xE2, 0xC7, 0xA3, 0xC7, 0x19, 0x77, 0x42);

        public static readonly Guid CLSID_D2D1Emboss__scanned__ = new Guid(0xb1c5eb2b, 0x0348, 0x43f0, 0x81, 0x07, 0x49, 0x57, 0xca, 0xcb, 0xa2, 0xae);

        public static readonly Guid CLSID_D2D1Exposure__scanned__ = new Guid(0xb56c8cfa, 0xf634, 0x41ee, 0xbe, 0xe0, 0xff, 0xa6, 0x17, 0x10, 0x60, 0x04);

        public static readonly Guid CLSID_D2D1Grayscale__scanned__ = new Guid(0x36DDE0EB, 0x3725, 0x42E0, 0x83, 0x6D, 0x52, 0xFB, 0x20, 0xAE, 0xE6, 0x44);

        public static readonly Guid CLSID_D2D1Invert__scanned__ = new Guid(0xe0c3784d, 0xcb39, 0x4e84, 0xb6, 0xfd, 0x6b, 0x72, 0xf0, 0x81, 0x02, 0x63);

        public static readonly Guid CLSID_D2D1Posterize__scanned__ = new Guid(0x2188945e, 0x33a3, 0x4366, 0xb7, 0xbc, 0x08, 0x6b, 0xd0, 0x2d, 0x08, 0x84);

        public static readonly Guid CLSID_D2D1Sepia__scanned__ = new Guid(0x3a1af410, 0x5f1d, 0x4dbe, 0x84, 0xdf, 0x91, 0x5d, 0xa7, 0x9b, 0x71, 0x53);

        public static readonly Guid CLSID_D2D1Sharpen__scanned__ = new Guid(0xC9B887CB, 0xC5FF, 0x4DC5, 0x97, 0x79, 0x27, 0x3D, 0xCF, 0x41, 0x7C, 0x7D);

        public static readonly Guid CLSID_D2D1Straighten__scanned__ = new Guid(0x4da47b12, 0x79a3, 0x4fb0, 0x82, 0x37, 0xbb, 0xc3, 0xb2, 0xa4, 0xde, 0x08);

        public static readonly Guid CLSID_D2D1TemperatureTint__scanned__ = new Guid(0x89176087, 0x8AF9, 0x4A08, 0xAE, 0xB1, 0x89, 0x5F, 0x38, 0xDB, 0x17, 0x66);

        public static readonly Guid CLSID_D2D1Vignette__scanned__ = new Guid(0xc00c40be, 0x5e67, 0x4ca3, 0x95, 0xb4, 0xf4, 0xb0, 0x2c, 0x11, 0x51, 0x35);

        public static readonly Guid CLSID_D2D1EdgeDetection__scanned__ = new Guid(0xEFF583CA, 0xCB07, 0x4AA9, 0xAC, 0x5D, 0x2C, 0xC4, 0x4C, 0x76, 0x46, 0x0F);

        public static readonly Guid CLSID_D2D1HighlightsShadows__scanned__ = new Guid(0xCADC8384, 0x323F, 0x4C7E, 0xA3, 0x61, 0x2E, 0x2B, 0x24, 0xDF, 0x6E, 0xE4);

        public static readonly Guid CLSID_D2D1LookupTable3D__scanned__ = new Guid(0x349E0EDA, 0x0088, 0x4A79, 0x9C, 0xA3, 0xC7, 0xE3, 0x00, 0x20, 0x20, 0x20);

        public static readonly Guid CLSID_D2D1Opacity__scanned__ = new Guid(0x811d79a4, 0xde28, 0x4454, 0x80, 0x94, 0xc6, 0x46, 0x85, 0xf8, 0xbd, 0x4c);

        public static readonly Guid CLSID_D2D1AlphaMask__scanned__ = new Guid(0xc80ecff0, 0x3fd5, 0x4f05, 0x83, 0x28, 0xc5, 0xd1, 0x72, 0x4b, 0x4f, 0x0a);

        public static readonly Guid CLSID_D2D1CrossFade__scanned__ = new Guid(0x12f575e8, 0x4db1, 0x485f, 0x9a, 0x84, 0x03, 0xa0, 0x7d, 0xd3, 0x82, 0x9f);

        public static readonly Guid CLSID_D2D1Tint__scanned__ = new Guid(0x36312b17, 0xf7dd, 0x4014, 0x91, 0x5d, 0xff, 0xca, 0x76, 0x8c, 0xf2, 0x11);

        public const float D2D1_SCENE_REFERRED_SDR_WHITE_LEVEL = 80.0f;

        public static readonly Guid CLSID_D2D1WhiteLevelAdjustment__scanned__ = new Guid(0x44a1cadb, 0x6cdd, 0x4818, 0x8f, 0xf4, 0x26, 0xc1, 0xcf, 0xe9, 0x5b, 0xdb);

        public static readonly Guid CLSID_D2D1HdrToneMap__scanned__ = new Guid(0x7b0b748d, 0x4610, 0x4486, 0xa9, 0x0c, 0x99, 0x9d, 0x9a, 0x2e, 0x2b, 0x11);

        public const uint D2D1_APPEND_ALIGNED_ELEMENT = 0xffffffff;

    }
}
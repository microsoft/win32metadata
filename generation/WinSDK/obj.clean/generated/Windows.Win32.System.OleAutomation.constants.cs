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


namespace Windows.Win32.System.OleAutomation
{
    public static partial class Apis
    {
        public const uint FADF_AUTO = 0x1;

        public const uint FADF_STATIC = 0x2;

        public const uint FADF_EMBEDDED = 0x4;

        public const uint FADF_FIXEDSIZE = 0x10;

        public const uint FADF_RECORD = 0x20;

        public const uint FADF_HAVEIID = 0x40;

        public const uint FADF_HAVEVARTYPE = 0x80;

        public const uint FADF_BSTR = 0x100;

        public const uint FADF_UNKNOWN = 0x200;

        public const uint FADF_DISPATCH = 0x400;

        public const uint FADF_VARIANT = 0x800;

        public const uint FADF_RESERVED = 0xf008;

        public const uint PARAMFLAG_NONE = 0;

        public const uint PARAMFLAG_FIN = 0x1;

        public const uint PARAMFLAG_FOUT = 0x2;

        public const uint PARAMFLAG_FLCID = 0x4;

        public const uint PARAMFLAG_FRETVAL = 0x8;

        public const uint PARAMFLAG_FOPT = 0x10;

        public const uint PARAMFLAG_FHASDEFAULT = 0x20;

        public const uint PARAMFLAG_FHASCUSTDATA = 0x40;

        public const uint IMPLTYPEFLAG_FDEFAULT = 0x1;

        public const uint IMPLTYPEFLAG_FSOURCE = 0x2;

        public const uint IMPLTYPEFLAG_FRESTRICTED = 0x4;

        public const uint IMPLTYPEFLAG_FDEFAULTVTABLE = 0x8;

        public const int DISPID_UNKNOWN = -1;

        public const uint DISPID_VALUE = 0;

        public const int DISPID_PROPERTYPUT = -3;

        public const int DISPID_NEWENUM = -4;

        public const int DISPID_EVALUATE = -5;

        public const int DISPID_CONSTRUCTOR = -6;

        public const int DISPID_DESTRUCTOR = -7;

        public const int DISPID_COLLECT = -8;

        public const uint STDOLE_MAJORVERNUM = 0x1;

        public const uint STDOLE_MINORVERNUM = 0x0;

        public const uint STDOLE_LCID = 0x0000;

        public const uint STDOLE2_MAJORVERNUM = 0x2;

        public const uint STDOLE2_MINORVERNUM = 0x0;

        public const uint STDOLE2_LCID = 0x0000;

        public const uint VARIANT_NOVALUEPROP = 0x01;

        public const uint VARIANT_ALPHABOOL = 0x02;

        public const uint VARIANT_NOUSEROVERRIDE = 0x04;

        public const uint VARIANT_CALENDAR_HIJRI = 0x08;

        public const uint VARIANT_LOCALBOOL = 0x10;

        public const uint VARIANT_CALENDAR_THAI = 0x20;

        public const uint VARIANT_CALENDAR_GREGORIAN = 0x40;

        public const uint VARIANT_USE_NLS = 0x80;

        public const uint LOCALE_USE_NLS = 0x10000000;

        public const uint VTDATEGRE_MAX = 2958465;

        public const int VTDATEGRE_MIN = -657434;

        public const uint NUMPRS_LEADING_WHITE = 0x0001;

        public const uint NUMPRS_TRAILING_WHITE = 0x0002;

        public const uint NUMPRS_LEADING_PLUS = 0x0004;

        public const uint NUMPRS_TRAILING_PLUS = 0x0008;

        public const uint NUMPRS_LEADING_MINUS = 0x0010;

        public const uint NUMPRS_TRAILING_MINUS = 0x0020;

        public const uint NUMPRS_HEX_OCT = 0x0040;

        public const uint NUMPRS_PARENS = 0x0080;

        public const uint NUMPRS_DECIMAL = 0x0100;

        public const uint NUMPRS_THOUSANDS = 0x0200;

        public const uint NUMPRS_CURRENCY = 0x0400;

        public const uint NUMPRS_EXPONENT = 0x0800;

        public const uint NUMPRS_USE_ALL = 0x1000;

        public const uint NUMPRS_STD = 0x1FFF;

        public const uint NUMPRS_NEG = 0x10000;

        public const uint NUMPRS_INEXACT = 0x20000;

        public const uint VARCMP_LT = 0;

        public const uint VARCMP_EQ = 1;

        public const uint VARCMP_GT = 2;

        public const uint VARCMP_NULL = 3;

        public const int ID_DEFAULTINST = -2;

        public const uint DISPATCH_METHOD = 0x1;

        public const uint DISPATCH_PROPERTYGET = 0x2;

        public const uint DISPATCH_PROPERTYPUT = 0x4;

        public const uint DISPATCH_PROPERTYPUTREF = 0x8;

        public const uint LOAD_TLB_AS_32BIT = 0x20;

        public const uint LOAD_TLB_AS_64BIT = 0x40;

        public const uint ACTIVEOBJECT_STRONG = 0x0;

        public const uint ACTIVEOBJECT_WEAK = 0x1;

        public static readonly Guid SID_VariantConversion__scanned__ = new Guid(0x1f101481, 0xbccd, 0x11d0, 0x93, 0x36, 0x0, 0xa0, 0xc9, 0xd, 0xca, 0xa9);

        public static readonly Guid SID_GetCaller__scanned__ = new Guid(0x4717cc40, 0xbcb9, 0x11d0, 0x93, 0x36, 0x0, 0xa0, 0xc9, 0xd, 0xca, 0xa9);

        public static readonly Guid SID_ProvideRuntimeContext__scanned__ = new Guid(0x74a5040c, 0xdd0c, 0x48f0, 0xac, 0x85, 0x19, 0x4c, 0x32, 0x59, 0x18, 0xa);

        public const uint DISPATCH_CONSTRUCT = 0x4000;

        public const int DISPID_THIS = -613;

    }
}

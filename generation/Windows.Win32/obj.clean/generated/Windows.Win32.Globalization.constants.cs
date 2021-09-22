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


namespace Windows.Win32.Globalization
{
    public static partial class Apis
    {
        public const uint ALL_SERVICE_TYPES = 0;

        public const uint HIGHLEVEL_SERVICE_TYPES = 1;

        public const uint LOWLEVEL_SERVICE_TYPES = 2;

        public const uint ALL_SERVICES = 0;

        public const uint ONLINE_SERVICES = 1;

        public const uint OFFLINE_SERVICES = 2;

        public const uint MAX_LEADBYTES = 12;

        public const uint MAX_DEFAULTCHAR = 2;

        public const uint HIGH_SURROGATE_START = 0xd800;

        public const uint HIGH_SURROGATE_END = 0xdbff;

        public const uint LOW_SURROGATE_START = 0xdc00;

        public const uint LOW_SURROGATE_END = 0xdfff;

        public const uint WC_COMPOSITECHECK = 0x00000200;

        public const uint WC_DISCARDNS = 0x00000010;

        public const uint WC_SEPCHARS = 0x00000020;

        public const uint WC_DEFAULTCHAR = 0x00000040;

        public const uint WC_ERR_INVALID_CHARS = 0x00000080;

        public const uint WC_NO_BEST_FIT_CHARS = 0x00000400;

        public const uint CT_CTYPE1 = 0x00000001;

        public const uint CT_CTYPE2 = 0x00000002;

        public const uint CT_CTYPE3 = 0x00000004;

        public const uint C1_UPPER = 0x0001;

        public const uint C1_LOWER = 0x0002;

        public const uint C1_DIGIT = 0x0004;

        public const uint C1_SPACE = 0x0008;

        public const uint C1_PUNCT = 0x0010;

        public const uint C1_CNTRL = 0x0020;

        public const uint C1_BLANK = 0x0040;

        public const uint C1_XDIGIT = 0x0080;

        public const uint C1_ALPHA = 0x0100;

        public const uint C1_DEFINED = 0x0200;

        public const uint C2_LEFTTORIGHT = 0x0001;

        public const uint C2_RIGHTTOLEFT = 0x0002;

        public const uint C2_EUROPENUMBER = 0x0003;

        public const uint C2_EUROPESEPARATOR = 0x0004;

        public const uint C2_EUROPETERMINATOR = 0x0005;

        public const uint C2_ARABICNUMBER = 0x0006;

        public const uint C2_COMMONSEPARATOR = 0x0007;

        public const uint C2_BLOCKSEPARATOR = 0x0008;

        public const uint C2_SEGMENTSEPARATOR = 0x0009;

        public const uint C2_WHITESPACE = 0x000A;

        public const uint C2_OTHERNEUTRAL = 0x000B;

        public const uint C2_NOTAPPLICABLE = 0x0000;

        public const uint C3_NONSPACING = 0x0001;

        public const uint C3_DIACRITIC = 0x0002;

        public const uint C3_VOWELMARK = 0x0004;

        public const uint C3_SYMBOL = 0x0008;

        public const uint C3_KATAKANA = 0x0010;

        public const uint C3_HIRAGANA = 0x0020;

        public const uint C3_HALFWIDTH = 0x0040;

        public const uint C3_FULLWIDTH = 0x0080;

        public const uint C3_IDEOGRAPH = 0x0100;

        public const uint C3_KASHIDA = 0x0200;

        public const uint C3_LEXICAL = 0x0400;

        public const uint C3_HIGHSURROGATE = 0x0800;

        public const uint C3_LOWSURROGATE = 0x1000;

        public const uint C3_ALPHA = 0x8000;

        public const uint C3_NOTAPPLICABLE = 0x0000;

        public const uint LCMAP_LOWERCASE = 0x00000100;

        public const uint LCMAP_UPPERCASE = 0x00000200;

        public const uint LCMAP_TITLECASE = 0x00000300;

        public const uint LCMAP_SORTKEY = 0x00000400;

        public const uint LCMAP_BYTEREV = 0x00000800;

        public const uint LCMAP_HIRAGANA = 0x00100000;

        public const uint LCMAP_KATAKANA = 0x00200000;

        public const uint LCMAP_HALFWIDTH = 0x00400000;

        public const uint LCMAP_FULLWIDTH = 0x00800000;

        public const uint LCMAP_LINGUISTIC_CASING = 0x01000000;

        public const uint LCMAP_SIMPLIFIED_CHINESE = 0x02000000;

        public const uint LCMAP_TRADITIONAL_CHINESE = 0x04000000;

        public const uint LCMAP_SORTHANDLE = 0x20000000;

        public const uint LCMAP_HASH = 0x00040000;

        public const uint FIND_STARTSWITH = 0x00100000;

        public const uint FIND_ENDSWITH = 0x00200000;

        public const uint FIND_FROMSTART = 0x00400000;

        public const uint FIND_FROMEND = 0x00800000;

        public const uint LCID_ALTERNATE_SORTS = 0x00000004;

        public const uint LOCALE_ALL = 0;

        public const uint LOCALE_WINDOWS = 0x00000001;

        public const uint LOCALE_SUPPLEMENTAL = 0x00000002;

        public const uint LOCALE_ALTERNATE_SORTS = 0x00000004;

        public const uint LOCALE_REPLACEMENT = 0x00000008;

        public const uint LOCALE_NEUTRALDATA = 0x00000010;

        public const uint LOCALE_SPECIFICDATA = 0x00000020;

        public const uint CSTR_LESS_THAN = 1;

        public const uint CSTR_EQUAL = 2;

        public const uint CSTR_GREATER_THAN = 3;

        public const uint CP_ACP = 0;

        public const uint CP_OEMCP = 1;

        public const uint CP_MACCP = 2;

        public const uint CP_THREAD_ACP = 3;

        public const uint CP_SYMBOL = 42;

        public const uint CP_UTF7 = 65000;

        public const uint CP_UTF8 = 65001;

        public const uint CTRY_DEFAULT = 0;

        public const uint CTRY_ALBANIA = 355;

        public const uint CTRY_ALGERIA = 213;

        public const uint CTRY_ARGENTINA = 54;

        public const uint CTRY_ARMENIA = 374;

        public const uint CTRY_AUSTRALIA = 61;

        public const uint CTRY_AUSTRIA = 43;

        public const uint CTRY_AZERBAIJAN = 994;

        public const uint CTRY_BAHRAIN = 973;

        public const uint CTRY_BELARUS = 375;

        public const uint CTRY_BELGIUM = 32;

        public const uint CTRY_BELIZE = 501;

        public const uint CTRY_BOLIVIA = 591;

        public const uint CTRY_BRAZIL = 55;

        public const uint CTRY_BRUNEI_DARUSSALAM = 673;

        public const uint CTRY_BULGARIA = 359;

        public const uint CTRY_CANADA = 2;

        public const uint CTRY_CARIBBEAN = 1;

        public const uint CTRY_CHILE = 56;

        public const uint CTRY_COLOMBIA = 57;

        public const uint CTRY_COSTA_RICA = 506;

        public const uint CTRY_CROATIA = 385;

        public const uint CTRY_CZECH = 420;

        public const uint CTRY_DENMARK = 45;

        public const uint CTRY_DOMINICAN_REPUBLIC = 1;

        public const uint CTRY_ECUADOR = 593;

        public const uint CTRY_EGYPT = 20;

        public const uint CTRY_EL_SALVADOR = 503;

        public const uint CTRY_ESTONIA = 372;

        public const uint CTRY_FAEROE_ISLANDS = 298;

        public const uint CTRY_FINLAND = 358;

        public const uint CTRY_FRANCE = 33;

        public const uint CTRY_GEORGIA = 995;

        public const uint CTRY_GERMANY = 49;

        public const uint CTRY_GREECE = 30;

        public const uint CTRY_GUATEMALA = 502;

        public const uint CTRY_HONDURAS = 504;

        public const uint CTRY_HONG_KONG = 852;

        public const uint CTRY_HUNGARY = 36;

        public const uint CTRY_ICELAND = 354;

        public const uint CTRY_INDIA = 91;

        public const uint CTRY_INDONESIA = 62;

        public const uint CTRY_IRAN = 981;

        public const uint CTRY_IRAQ = 964;

        public const uint CTRY_IRELAND = 353;

        public const uint CTRY_ISRAEL = 972;

        public const uint CTRY_ITALY = 39;

        public const uint CTRY_JAMAICA = 1;

        public const uint CTRY_JAPAN = 81;

        public const uint CTRY_JORDAN = 962;

        public const uint CTRY_KAZAKSTAN = 7;

        public const uint CTRY_KENYA = 254;

        public const uint CTRY_KUWAIT = 965;

        public const uint CTRY_KYRGYZSTAN = 996;

        public const uint CTRY_LATVIA = 371;

        public const uint CTRY_LEBANON = 961;

        public const uint CTRY_LIBYA = 218;

        public const uint CTRY_LIECHTENSTEIN = 41;

        public const uint CTRY_LITHUANIA = 370;

        public const uint CTRY_LUXEMBOURG = 352;

        public const uint CTRY_MACAU = 853;

        public const uint CTRY_MACEDONIA = 389;

        public const uint CTRY_MALAYSIA = 60;

        public const uint CTRY_MALDIVES = 960;

        public const uint CTRY_MEXICO = 52;

        public const uint CTRY_MONACO = 33;

        public const uint CTRY_MONGOLIA = 976;

        public const uint CTRY_MOROCCO = 212;

        public const uint CTRY_NETHERLANDS = 31;

        public const uint CTRY_NEW_ZEALAND = 64;

        public const uint CTRY_NICARAGUA = 505;

        public const uint CTRY_NORWAY = 47;

        public const uint CTRY_OMAN = 968;

        public const uint CTRY_PAKISTAN = 92;

        public const uint CTRY_PANAMA = 507;

        public const uint CTRY_PARAGUAY = 595;

        public const uint CTRY_PERU = 51;

        public const uint CTRY_PHILIPPINES = 63;

        public const uint CTRY_POLAND = 48;

        public const uint CTRY_PORTUGAL = 351;

        public const uint CTRY_PRCHINA = 86;

        public const uint CTRY_PUERTO_RICO = 1;

        public const uint CTRY_QATAR = 974;

        public const uint CTRY_ROMANIA = 40;

        public const uint CTRY_RUSSIA = 7;

        public const uint CTRY_SAUDI_ARABIA = 966;

        public const uint CTRY_SERBIA = 381;

        public const uint CTRY_SINGAPORE = 65;

        public const uint CTRY_SLOVAK = 421;

        public const uint CTRY_SLOVENIA = 386;

        public const uint CTRY_SOUTH_AFRICA = 27;

        public const uint CTRY_SOUTH_KOREA = 82;

        public const uint CTRY_SPAIN = 34;

        public const uint CTRY_SWEDEN = 46;

        public const uint CTRY_SWITZERLAND = 41;

        public const uint CTRY_SYRIA = 963;

        public const uint CTRY_TAIWAN = 886;

        public const uint CTRY_TATARSTAN = 7;

        public const uint CTRY_THAILAND = 66;

        public const uint CTRY_TRINIDAD_Y_TOBAGO = 1;

        public const uint CTRY_TUNISIA = 216;

        public const uint CTRY_TURKEY = 90;

        public const uint CTRY_UAE = 971;

        public const uint CTRY_UKRAINE = 380;

        public const uint CTRY_UNITED_KINGDOM = 44;

        public const uint CTRY_UNITED_STATES = 1;

        public const uint CTRY_URUGUAY = 598;

        public const uint CTRY_UZBEKISTAN = 7;

        public const uint CTRY_VENEZUELA = 58;

        public const uint CTRY_VIET_NAM = 84;

        public const uint CTRY_YEMEN = 967;

        public const uint CTRY_ZIMBABWE = 263;

        public const uint LOCALE_NOUSEROVERRIDE = 0x80000000;

        public const uint LOCALE_USE_CP_ACP = 0x40000000;

        public const uint LOCALE_RETURN_NUMBER = 0x20000000;

        public const uint LOCALE_RETURN_GENITIVE_NAMES = 0x10000000;

        public const uint LOCALE_ALLOW_NEUTRAL_NAMES = 0x08000000;

        public const uint LOCALE_SLOCALIZEDDISPLAYNAME = 0x00000002;

        public const uint LOCALE_SENGLISHDISPLAYNAME = 0x00000072;

        public const uint LOCALE_SNATIVEDISPLAYNAME = 0x00000073;

        public const uint LOCALE_SLOCALIZEDLANGUAGENAME = 0x0000006f;

        public const uint LOCALE_SENGLISHLANGUAGENAME = 0x00001001;

        public const uint LOCALE_SNATIVELANGUAGENAME = 0x00000004;

        public const uint LOCALE_SLOCALIZEDCOUNTRYNAME = 0x00000006;

        public const uint LOCALE_SENGLISHCOUNTRYNAME = 0x00001002;

        public const uint LOCALE_SNATIVECOUNTRYNAME = 0x00000008;

        public const uint LOCALE_IDIALINGCODE = 0x00000005;

        public const uint LOCALE_SLIST = 0x0000000C;

        public const uint LOCALE_IMEASURE = 0x0000000D;

        public const uint LOCALE_SDECIMAL = 0x0000000E;

        public const uint LOCALE_STHOUSAND = 0x0000000F;

        public const uint LOCALE_SGROUPING = 0x00000010;

        public const uint LOCALE_IDIGITS = 0x00000011;

        public const uint LOCALE_ILZERO = 0x00000012;

        public const uint LOCALE_INEGNUMBER = 0x00001010;

        public const uint LOCALE_SNATIVEDIGITS = 0x00000013;

        public const uint LOCALE_SCURRENCY = 0x00000014;

        public const uint LOCALE_SINTLSYMBOL = 0x00000015;

        public const uint LOCALE_SMONDECIMALSEP = 0x00000016;

        public const uint LOCALE_SMONTHOUSANDSEP = 0x00000017;

        public const uint LOCALE_SMONGROUPING = 0x00000018;

        public const uint LOCALE_ICURRDIGITS = 0x00000019;

        public const uint LOCALE_ICURRENCY = 0x0000001B;

        public const uint LOCALE_INEGCURR = 0x0000001C;

        public const uint LOCALE_SSHORTDATE = 0x0000001F;

        public const uint LOCALE_SLONGDATE = 0x00000020;

        public const uint LOCALE_STIMEFORMAT = 0x00001003;

        public const uint LOCALE_SAM = 0x00000028;

        public const uint LOCALE_SPM = 0x00000029;

        public const uint LOCALE_ICALENDARTYPE = 0x00001009;

        public const uint LOCALE_IOPTIONALCALENDAR = 0x0000100B;

        public const uint LOCALE_IFIRSTDAYOFWEEK = 0x0000100C;

        public const uint LOCALE_IFIRSTWEEKOFYEAR = 0x0000100D;

        public const uint LOCALE_SDAYNAME1 = 0x0000002A;

        public const uint LOCALE_SDAYNAME2 = 0x0000002B;

        public const uint LOCALE_SDAYNAME3 = 0x0000002C;

        public const uint LOCALE_SDAYNAME4 = 0x0000002D;

        public const uint LOCALE_SDAYNAME5 = 0x0000002E;

        public const uint LOCALE_SDAYNAME6 = 0x0000002F;

        public const uint LOCALE_SDAYNAME7 = 0x00000030;

        public const uint LOCALE_SABBREVDAYNAME1 = 0x00000031;

        public const uint LOCALE_SABBREVDAYNAME2 = 0x00000032;

        public const uint LOCALE_SABBREVDAYNAME3 = 0x00000033;

        public const uint LOCALE_SABBREVDAYNAME4 = 0x00000034;

        public const uint LOCALE_SABBREVDAYNAME5 = 0x00000035;

        public const uint LOCALE_SABBREVDAYNAME6 = 0x00000036;

        public const uint LOCALE_SABBREVDAYNAME7 = 0x00000037;

        public const uint LOCALE_SMONTHNAME1 = 0x00000038;

        public const uint LOCALE_SMONTHNAME2 = 0x00000039;

        public const uint LOCALE_SMONTHNAME3 = 0x0000003A;

        public const uint LOCALE_SMONTHNAME4 = 0x0000003B;

        public const uint LOCALE_SMONTHNAME5 = 0x0000003C;

        public const uint LOCALE_SMONTHNAME6 = 0x0000003D;

        public const uint LOCALE_SMONTHNAME7 = 0x0000003E;

        public const uint LOCALE_SMONTHNAME8 = 0x0000003F;

        public const uint LOCALE_SMONTHNAME9 = 0x00000040;

        public const uint LOCALE_SMONTHNAME10 = 0x00000041;

        public const uint LOCALE_SMONTHNAME11 = 0x00000042;

        public const uint LOCALE_SMONTHNAME12 = 0x00000043;

        public const uint LOCALE_SMONTHNAME13 = 0x0000100E;

        public const uint LOCALE_SABBREVMONTHNAME1 = 0x00000044;

        public const uint LOCALE_SABBREVMONTHNAME2 = 0x00000045;

        public const uint LOCALE_SABBREVMONTHNAME3 = 0x00000046;

        public const uint LOCALE_SABBREVMONTHNAME4 = 0x00000047;

        public const uint LOCALE_SABBREVMONTHNAME5 = 0x00000048;

        public const uint LOCALE_SABBREVMONTHNAME6 = 0x00000049;

        public const uint LOCALE_SABBREVMONTHNAME7 = 0x0000004A;

        public const uint LOCALE_SABBREVMONTHNAME8 = 0x0000004B;

        public const uint LOCALE_SABBREVMONTHNAME9 = 0x0000004C;

        public const uint LOCALE_SABBREVMONTHNAME10 = 0x0000004D;

        public const uint LOCALE_SABBREVMONTHNAME11 = 0x0000004E;

        public const uint LOCALE_SABBREVMONTHNAME12 = 0x0000004F;

        public const uint LOCALE_SABBREVMONTHNAME13 = 0x0000100F;

        public const uint LOCALE_SPOSITIVESIGN = 0x00000050;

        public const uint LOCALE_SNEGATIVESIGN = 0x00000051;

        public const uint LOCALE_IPOSSIGNPOSN = 0x00000052;

        public const uint LOCALE_INEGSIGNPOSN = 0x00000053;

        public const uint LOCALE_IPOSSYMPRECEDES = 0x00000054;

        public const uint LOCALE_IPOSSEPBYSPACE = 0x00000055;

        public const uint LOCALE_INEGSYMPRECEDES = 0x00000056;

        public const uint LOCALE_INEGSEPBYSPACE = 0x00000057;

        public const uint LOCALE_FONTSIGNATURE = 0x00000058;

        public const uint LOCALE_SISO639LANGNAME = 0x00000059;

        public const uint LOCALE_SISO3166CTRYNAME = 0x0000005A;

        public const uint LOCALE_IPAPERSIZE = 0x0000100A;

        public const uint LOCALE_SENGCURRNAME = 0x00001007;

        public const uint LOCALE_SNATIVECURRNAME = 0x00001008;

        public const uint LOCALE_SYEARMONTH = 0x00001006;

        public const uint LOCALE_SSORTNAME = 0x00001013;

        public const uint LOCALE_IDIGITSUBSTITUTION = 0x00001014;

        public const uint LOCALE_SNAME = 0x0000005c;

        public const uint LOCALE_SDURATION = 0x0000005d;

        public const uint LOCALE_SSHORTESTDAYNAME1 = 0x00000060;

        public const uint LOCALE_SSHORTESTDAYNAME2 = 0x00000061;

        public const uint LOCALE_SSHORTESTDAYNAME3 = 0x00000062;

        public const uint LOCALE_SSHORTESTDAYNAME4 = 0x00000063;

        public const uint LOCALE_SSHORTESTDAYNAME5 = 0x00000064;

        public const uint LOCALE_SSHORTESTDAYNAME6 = 0x00000065;

        public const uint LOCALE_SSHORTESTDAYNAME7 = 0x00000066;

        public const uint LOCALE_SISO639LANGNAME2 = 0x00000067;

        public const uint LOCALE_SISO3166CTRYNAME2 = 0x00000068;

        public const uint LOCALE_SNAN = 0x00000069;

        public const uint LOCALE_SPOSINFINITY = 0x0000006a;

        public const uint LOCALE_SNEGINFINITY = 0x0000006b;

        public const uint LOCALE_SSCRIPTS = 0x0000006c;

        public const uint LOCALE_SPARENT = 0x0000006d;

        public const uint LOCALE_SCONSOLEFALLBACKNAME = 0x0000006e;

        public const uint LOCALE_IREADINGLAYOUT = 0x00000070;

        public const uint LOCALE_INEUTRAL = 0x00000071;

        public const uint LOCALE_INEGATIVEPERCENT = 0x00000074;

        public const uint LOCALE_IPOSITIVEPERCENT = 0x00000075;

        public const uint LOCALE_SPERCENT = 0x00000076;

        public const uint LOCALE_SPERMILLE = 0x00000077;

        public const uint LOCALE_SMONTHDAY = 0x00000078;

        public const uint LOCALE_SSHORTTIME = 0x00000079;

        public const uint LOCALE_SOPENTYPELANGUAGETAG = 0x0000007a;

        public const uint LOCALE_SSORTLOCALE = 0x0000007b;

        public const uint LOCALE_SRELATIVELONGDATE = 0x0000007c;

        public const uint LOCALE_SSHORTESTAM = 0x0000007e;

        public const uint LOCALE_SSHORTESTPM = 0x0000007f;

        public const uint LOCALE_IDEFAULTCODEPAGE = 0x0000000B;

        public const uint LOCALE_IDEFAULTANSICODEPAGE = 0x00001004;

        public const uint LOCALE_IDEFAULTMACCODEPAGE = 0x00001011;

        public const uint LOCALE_IDEFAULTEBCDICCODEPAGE = 0x00001012;

        public const uint LOCALE_ILANGUAGE = 0x00000001;

        public const uint LOCALE_SABBREVLANGNAME = 0x00000003;

        public const uint LOCALE_SABBREVCTRYNAME = 0x00000007;

        public const uint LOCALE_IGEOID = 0x0000005B;

        public const uint LOCALE_IDEFAULTLANGUAGE = 0x00000009;

        public const uint LOCALE_IDEFAULTCOUNTRY = 0x0000000A;

        public const uint LOCALE_IINTLCURRDIGITS = 0x0000001A;

        public const uint LOCALE_SDATE = 0x0000001D;

        public const uint LOCALE_STIME = 0x0000001E;

        public const uint LOCALE_IDATE = 0x00000021;

        public const uint LOCALE_ILDATE = 0x00000022;

        public const uint LOCALE_ITIME = 0x00000023;

        public const uint LOCALE_ITIMEMARKPOSN = 0x00001005;

        public const uint LOCALE_ICENTURY = 0x00000024;

        public const uint LOCALE_ITLZERO = 0x00000025;

        public const uint LOCALE_IDAYLZERO = 0x00000026;

        public const uint LOCALE_IMONLZERO = 0x00000027;

        public const uint LOCALE_SKEYBOARDSTOINSTALL = 0x0000005e;

        public const uint CAL_ICALINTVALUE = 0x00000001;

        public const uint CAL_SCALNAME = 0x00000002;

        public const uint CAL_IYEAROFFSETRANGE = 0x00000003;

        public const uint CAL_SERASTRING = 0x00000004;

        public const uint CAL_SSHORTDATE = 0x00000005;

        public const uint CAL_SLONGDATE = 0x00000006;

        public const uint CAL_SDAYNAME1 = 0x00000007;

        public const uint CAL_SDAYNAME2 = 0x00000008;

        public const uint CAL_SDAYNAME3 = 0x00000009;

        public const uint CAL_SDAYNAME4 = 0x0000000a;

        public const uint CAL_SDAYNAME5 = 0x0000000b;

        public const uint CAL_SDAYNAME6 = 0x0000000c;

        public const uint CAL_SDAYNAME7 = 0x0000000d;

        public const uint CAL_SABBREVDAYNAME1 = 0x0000000e;

        public const uint CAL_SABBREVDAYNAME2 = 0x0000000f;

        public const uint CAL_SABBREVDAYNAME3 = 0x00000010;

        public const uint CAL_SABBREVDAYNAME4 = 0x00000011;

        public const uint CAL_SABBREVDAYNAME5 = 0x00000012;

        public const uint CAL_SABBREVDAYNAME6 = 0x00000013;

        public const uint CAL_SABBREVDAYNAME7 = 0x00000014;

        public const uint CAL_SMONTHNAME1 = 0x00000015;

        public const uint CAL_SMONTHNAME2 = 0x00000016;

        public const uint CAL_SMONTHNAME3 = 0x00000017;

        public const uint CAL_SMONTHNAME4 = 0x00000018;

        public const uint CAL_SMONTHNAME5 = 0x00000019;

        public const uint CAL_SMONTHNAME6 = 0x0000001a;

        public const uint CAL_SMONTHNAME7 = 0x0000001b;

        public const uint CAL_SMONTHNAME8 = 0x0000001c;

        public const uint CAL_SMONTHNAME9 = 0x0000001d;

        public const uint CAL_SMONTHNAME10 = 0x0000001e;

        public const uint CAL_SMONTHNAME11 = 0x0000001f;

        public const uint CAL_SMONTHNAME12 = 0x00000020;

        public const uint CAL_SMONTHNAME13 = 0x00000021;

        public const uint CAL_SABBREVMONTHNAME1 = 0x00000022;

        public const uint CAL_SABBREVMONTHNAME2 = 0x00000023;

        public const uint CAL_SABBREVMONTHNAME3 = 0x00000024;

        public const uint CAL_SABBREVMONTHNAME4 = 0x00000025;

        public const uint CAL_SABBREVMONTHNAME5 = 0x00000026;

        public const uint CAL_SABBREVMONTHNAME6 = 0x00000027;

        public const uint CAL_SABBREVMONTHNAME7 = 0x00000028;

        public const uint CAL_SABBREVMONTHNAME8 = 0x00000029;

        public const uint CAL_SABBREVMONTHNAME9 = 0x0000002a;

        public const uint CAL_SABBREVMONTHNAME10 = 0x0000002b;

        public const uint CAL_SABBREVMONTHNAME11 = 0x0000002c;

        public const uint CAL_SABBREVMONTHNAME12 = 0x0000002d;

        public const uint CAL_SABBREVMONTHNAME13 = 0x0000002e;

        public const uint CAL_SYEARMONTH = 0x0000002f;

        public const uint CAL_ITWODIGITYEARMAX = 0x00000030;

        public const uint CAL_SSHORTESTDAYNAME1 = 0x00000031;

        public const uint CAL_SSHORTESTDAYNAME2 = 0x00000032;

        public const uint CAL_SSHORTESTDAYNAME3 = 0x00000033;

        public const uint CAL_SSHORTESTDAYNAME4 = 0x00000034;

        public const uint CAL_SSHORTESTDAYNAME5 = 0x00000035;

        public const uint CAL_SSHORTESTDAYNAME6 = 0x00000036;

        public const uint CAL_SSHORTESTDAYNAME7 = 0x00000037;

        public const uint CAL_SMONTHDAY = 0x00000038;

        public const uint CAL_SABBREVERASTRING = 0x00000039;

        public const uint CAL_SRELATIVELONGDATE = 0x0000003a;

        public const uint CAL_SENGLISHERANAME = 0x0000003b;

        public const uint CAL_SENGLISHABBREVERANAME = 0x0000003c;

        public const uint CAL_SJAPANESEERAFIRSTYEAR = 0x0000003d;

        public const uint ENUM_ALL_CALENDARS = 0xffffffff;

        public const uint CAL_GREGORIAN = 1;

        public const uint CAL_GREGORIAN_US = 2;

        public const uint CAL_JAPAN = 3;

        public const uint CAL_TAIWAN = 4;

        public const uint CAL_KOREA = 5;

        public const uint CAL_HIJRI = 6;

        public const uint CAL_THAI = 7;

        public const uint CAL_HEBREW = 8;

        public const uint CAL_GREGORIAN_ME_FRENCH = 9;

        public const uint CAL_GREGORIAN_ARABIC = 10;

        public const uint CAL_GREGORIAN_XLIT_ENGLISH = 11;

        public const uint CAL_GREGORIAN_XLIT_FRENCH = 12;

        public const uint CAL_PERSIAN = 22;

        public const uint CAL_UMALQURA = 23;

        public const uint LGRPID_WESTERN_EUROPE = 0x0001;

        public const uint LGRPID_CENTRAL_EUROPE = 0x0002;

        public const uint LGRPID_BALTIC = 0x0003;

        public const uint LGRPID_GREEK = 0x0004;

        public const uint LGRPID_CYRILLIC = 0x0005;

        public const uint LGRPID_TURKIC = 0x0006;

        public const uint LGRPID_TURKISH = 0x0006;

        public const uint LGRPID_JAPANESE = 0x0007;

        public const uint LGRPID_KOREAN = 0x0008;

        public const uint LGRPID_TRADITIONAL_CHINESE = 0x0009;

        public const uint LGRPID_SIMPLIFIED_CHINESE = 0x000a;

        public const uint LGRPID_THAI = 0x000b;

        public const uint LGRPID_HEBREW = 0x000c;

        public const uint LGRPID_ARABIC = 0x000d;

        public const uint LGRPID_VIETNAMESE = 0x000e;

        public const uint LGRPID_INDIC = 0x000f;

        public const uint LGRPID_GEORGIAN = 0x0010;

        public const uint LGRPID_ARMENIAN = 0x0011;

        public const uint MUI_LANGUAGE_ID = 0x4;

        public const uint MUI_LANGUAGE_NAME = 0x8;

        public const uint MUI_MERGE_SYSTEM_FALLBACK = 0x10;

        public const uint MUI_MERGE_USER_FALLBACK = 0x20;

        public const uint MUI_THREAD_LANGUAGES = 0x40;

        public const uint MUI_CONSOLE_FILTER = 0x100;

        public const uint MUI_COMPLEX_SCRIPT_FILTER = 0x200;

        public const uint MUI_RESET_FILTERS = 0x001;

        public const uint MUI_USER_PREFERRED_UI_LANGUAGES = 0x10;

        public const uint MUI_USE_INSTALLED_LANGUAGES = 0x20;

        public const uint MUI_USE_SEARCH_ALL_LANGUAGES = 0x40;

        public const uint MUI_LANG_NEUTRAL_PE_FILE = 0x100;

        public const uint MUI_NON_LANG_NEUTRAL_FILE = 0x200;

        public const uint MUI_MACHINE_LANGUAGE_SETTINGS = 0x400;

        public const uint MUI_FILETYPE_NOT_LANGUAGE_NEUTRAL = 0x001;

        public const uint MUI_FILETYPE_LANGUAGE_NEUTRAL_MAIN = 0x002;

        public const uint MUI_FILETYPE_LANGUAGE_NEUTRAL_MUI = 0x004;

        public const uint MUI_QUERY_TYPE = 0x001;

        public const uint MUI_QUERY_CHECKSUM = 0x002;

        public const uint MUI_QUERY_LANGUAGE_NAME = 0x004;

        public const uint MUI_QUERY_RESOURCE_TYPES = 0x008;

        public const uint MUI_FILEINFO_VERSION = 0x001;

        public const uint MUI_FULL_LANGUAGE = 0x01;

        public const uint MUI_PARTIAL_LANGUAGE = 0x02;

        public const uint MUI_LIP_LANGUAGE = 0x04;

        public const uint MUI_LANGUAGE_INSTALLED = 0x20;

        public const uint MUI_LANGUAGE_LICENSED = 0x40;

        public const int GEOID_NOT_AVAILABLE = -1;

        public const uint IDN_ALLOW_UNASSIGNED = 0x01;

        public const uint IDN_USE_STD3_ASCII_RULES = 0x02;

        public const uint IDN_EMAIL_ADDRESS = 0x04;

        public const uint IDN_RAW_PUNYCODE = 0x08;

        public const uint VS_ALLOW_LATIN = 0x0001;

        public const uint GSS_ALLOW_INHERITED_COMMON = 0x0001;

        public const uint MUI_FORMAT_REG_COMPAT = 0x0001;

        public const uint MUI_FORMAT_INF_COMPAT = 0x0002;

        public const uint MUI_VERIFY_FILE_EXISTS = 0x0004;

        public const uint MUI_SKIP_STRING_CACHE = 0x0008;

        public const uint MUI_IMMUTABLE_LOOKUP = 0x0010;

        public static readonly Guid CLSID_VERSION_DEPENDENT_MSIME_JAPANESE__scanned__ = new Guid(0x6a91029e, 0xaa49, 0x471b, 0xae, 0xe7, 0x7d, 0x33, 0x27, 0x85, 0x66, 0x0d);

        public static readonly Guid IID_IFECommon__scanned__ = new Guid(0x19f7151, 0xe6db, 0x11d0, 0x83, 0xc3, 0x0, 0xc0, 0x4f, 0xdd, 0xb8, 0x2e);

        public static readonly Guid IID_IFELanguage__scanned__ = new Guid(0x19f7152, 0xe6db, 0x11d0, 0x83, 0xc3, 0x0, 0xc0, 0x4f, 0xdd, 0xb8, 0x2e);

        public static readonly Guid IID_IFELanguage2__scanned__ = new Guid(0x21164102, 0xc24a, 0x11d1, 0x85, 0x1a, 0x0, 0xc0, 0x4f, 0xcc, 0x6b, 0x14);

        public static readonly Guid IID_IFEDictionary__scanned__ = new Guid(0x19f7153, 0xe6db, 0x11d0, 0x83, 0xc3, 0x0, 0xc0, 0x4f, 0xdd, 0xb8, 0x2e);

        [NativeTypeName("HRESULT")]
        public const int IFEC_S_ALREADY_DEFAULT = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7400));

        public const uint FELANG_REQ_CONV = 0x00010000;

        public const uint FELANG_REQ_RECONV = 0x00020000;

        public const uint FELANG_REQ_REV = 0x00030000;

        public const uint FELANG_CMODE_MONORUBY = 0x00000002;

        public const uint FELANG_CMODE_NOPRUNING = 0x00000004;

        public const uint FELANG_CMODE_KATAKANAOUT = 0x00000008;

        public const uint FELANG_CMODE_HIRAGANAOUT = 0x00000000;

        public const uint FELANG_CMODE_HALFWIDTHOUT = 0x00000010;

        public const uint FELANG_CMODE_FULLWIDTHOUT = 0x00000020;

        public const uint FELANG_CMODE_BOPOMOFO = 0x00000040;

        public const uint FELANG_CMODE_HANGUL = 0x00000080;

        public const uint FELANG_CMODE_PINYIN = 0x00000100;

        public const uint FELANG_CMODE_PRECONV = 0x00000200;

        public const uint FELANG_CMODE_RADICAL = 0x00000400;

        public const uint FELANG_CMODE_UNKNOWNREADING = 0x00000800;

        public const uint FELANG_CMODE_MERGECAND = 0x00001000;

        public const uint FELANG_CMODE_ROMAN = 0x00002000;

        public const uint FELANG_CMODE_BESTFIRST = 0x00004000;

        public const uint FELANG_CMODE_USENOREVWORDS = 0x00008000;

        public const uint FELANG_CMODE_NONE = 0x01000000;

        public const uint FELANG_CMODE_PLAURALCLAUSE = 0x02000000;

        public const uint FELANG_CMODE_SINGLECONVERT = 0x04000000;

        public const uint FELANG_CMODE_AUTOMATIC = 0x08000000;

        public const uint FELANG_CMODE_PHRASEPREDICT = 0x10000000;

        public const uint FELANG_CMODE_CONVERSATION = 0x20000000;

        public const uint FELANG_CMODE_NOINVISIBLECHAR = 0x40000000;

        public const uint E_NOCAND = 0x30;

        public const uint E_NOTENOUGH_BUFFER = 0x31;

        public const uint E_NOTENOUGH_WDD = 0x32;

        public const uint E_LARGEINPUT = 0x33;

        public const uint FELANG_CLMN_WBREAK = 0x01;

        public const uint FELANG_CLMN_NOWBREAK = 0x02;

        public const uint FELANG_CLMN_PBREAK = 0x04;

        public const uint FELANG_CLMN_NOPBREAK = 0x08;

        public const uint FELANG_CLMN_FIXR = 0x10;

        public const uint FELANG_CLMN_FIXD = 0x20;

        public const uint FELANG_INVALD_PO = 0xFFFF;

        public const uint IFED_POS_NONE = 0x00000000;

        public const uint IFED_POS_NOUN = 0x00000001;

        public const uint IFED_POS_VERB = 0x00000002;

        public const uint IFED_POS_ADJECTIVE = 0x00000004;

        public const uint IFED_POS_ADJECTIVE_VERB = 0x00000008;

        public const uint IFED_POS_ADVERB = 0x00000010;

        public const uint IFED_POS_ADNOUN = 0x00000020;

        public const uint IFED_POS_CONJUNCTION = 0x00000040;

        public const uint IFED_POS_INTERJECTION = 0x00000080;

        public const uint IFED_POS_INDEPENDENT = 0x000000ff;

        public const uint IFED_POS_INFLECTIONALSUFFIX = 0x00000100;

        public const uint IFED_POS_PREFIX = 0x00000200;

        public const uint IFED_POS_SUFFIX = 0x00000400;

        public const uint IFED_POS_AFFIX = 0x00000600;

        public const uint IFED_POS_TANKANJI = 0x00000800;

        public const uint IFED_POS_IDIOMS = 0x00001000;

        public const uint IFED_POS_SYMBOLS = 0x00002000;

        public const uint IFED_POS_PARTICLE = 0x00004000;

        public const uint IFED_POS_AUXILIARY_VERB = 0x00008000;

        public const uint IFED_POS_SUB_VERB = 0x00010000;

        public const uint IFED_POS_DEPENDENT = 0x0001c000;

        public const uint IFED_POS_ALL = 0x0001ffff;

        public const uint IFED_SELECT_NONE = 0x00000000;

        public const uint IFED_SELECT_READING = 0x00000001;

        public const uint IFED_SELECT_DISPLAY = 0x00000002;

        public const uint IFED_SELECT_POS = 0x00000004;

        public const uint IFED_SELECT_COMMENT = 0x00000008;

        public const uint IFED_SELECT_ALL = 0x0000000f;

        public const uint IFED_REG_NONE = 0x00000000;

        public const uint IFED_REG_USER = 0x00000001;

        public const uint IFED_REG_AUTO = 0x00000002;

        public const uint IFED_REG_GRAMMAR = 0x00000004;

        public const uint IFED_REG_ALL = 0x00000007;

        public const uint IFED_TYPE_NONE = 0x00000000;

        public const uint IFED_TYPE_GENERAL = 0x00000001;

        public const uint IFED_TYPE_NAMEPLACE = 0x00000002;

        public const uint IFED_TYPE_SPEECH = 0x00000004;

        public const uint IFED_TYPE_REVERSE = 0x00000008;

        public const uint IFED_TYPE_ENGLISH = 0x00000010;

        public const uint IFED_TYPE_ALL = 0x0000001f;

        [NativeTypeName("HRESULT")]
        public const int IFED_S_MORE_ENTRIES = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7200));

        [NativeTypeName("HRESULT")]
        public const int IFED_S_EMPTY_DICTIONARY = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7201));

        [NativeTypeName("HRESULT")]
        public const int IFED_S_WORD_EXISTS = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7202));

        [NativeTypeName("HRESULT")]
        public const int IFED_S_COMMENT_CHANGED = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7203));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_NOT_FOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7300));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_INVALID_FORMAT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7301));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_OPEN_FAILED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7302));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_WRITE_FAILED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7303));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_NO_ENTRY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7304));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_REGISTER_FAILED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7305));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_NOT_USER_DIC = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7306));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_NOT_SUPPORTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7307));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_USER_COMMENT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7308));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_REGISTER_ILLEGAL_POS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x7309));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_REGISTER_IMPROPER_WORD = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x730a));

        [NativeTypeName("HRESULT")]
        public const int IFED_E_REGISTER_DISCONNECTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x730b));

        public const uint POS_UNDEFINED = 0;

        public const uint JPOS_MEISHI_FUTSU = 100;

        public const uint JPOS_MEISHI_SAHEN = 101;

        public const uint JPOS_MEISHI_ZAHEN = 102;

        public const uint JPOS_MEISHI_KEIYOUDOUSHI = 103;

        public const uint JPOS_HUKUSIMEISHI = 104;

        public const uint JPOS_MEISA_KEIDOU = 105;

        public const uint JPOS_JINMEI = 106;

        public const uint JPOS_JINMEI_SEI = 107;

        public const uint JPOS_JINMEI_MEI = 108;

        public const uint JPOS_CHIMEI = 109;

        public const uint JPOS_CHIMEI_KUNI = 110;

        public const uint JPOS_CHIMEI_KEN = 111;

        public const uint JPOS_CHIMEI_GUN = 112;

        public const uint JPOS_CHIMEI_KU = 113;

        public const uint JPOS_CHIMEI_SHI = 114;

        public const uint JPOS_CHIMEI_MACHI = 115;

        public const uint JPOS_CHIMEI_MURA = 116;

        public const uint JPOS_CHIMEI_EKI = 117;

        public const uint JPOS_SONOTA = 118;

        public const uint JPOS_SHAMEI = 119;

        public const uint JPOS_SOSHIKI = 120;

        public const uint JPOS_KENCHIKU = 121;

        public const uint JPOS_BUPPIN = 122;

        public const uint JPOS_DAIMEISHI = 123;

        public const uint JPOS_DAIMEISHI_NINSHOU = 124;

        public const uint JPOS_DAIMEISHI_SHIJI = 125;

        public const uint JPOS_KAZU = 126;

        public const uint JPOS_KAZU_SURYOU = 127;

        public const uint JPOS_KAZU_SUSHI = 128;

        public const uint JPOS_5DAN_AWA = 200;

        public const uint JPOS_5DAN_KA = 201;

        public const uint JPOS_5DAN_GA = 202;

        public const uint JPOS_5DAN_SA = 203;

        public const uint JPOS_5DAN_TA = 204;

        public const uint JPOS_5DAN_NA = 205;

        public const uint JPOS_5DAN_BA = 206;

        public const uint JPOS_5DAN_MA = 207;

        public const uint JPOS_5DAN_RA = 208;

        public const uint JPOS_5DAN_AWAUON = 209;

        public const uint JPOS_5DAN_KASOKUON = 210;

        public const uint JPOS_5DAN_RAHEN = 211;

        public const uint JPOS_4DAN_HA = 212;

        public const uint JPOS_1DAN = 213;

        public const uint JPOS_TOKUSHU_KAHEN = 214;

        public const uint JPOS_TOKUSHU_SAHENSURU = 215;

        public const uint JPOS_TOKUSHU_SAHEN = 216;

        public const uint JPOS_TOKUSHU_ZAHEN = 217;

        public const uint JPOS_TOKUSHU_NAHEN = 218;

        public const uint JPOS_KURU_KI = 219;

        public const uint JPOS_KURU_KITA = 220;

        public const uint JPOS_KURU_KITARA = 221;

        public const uint JPOS_KURU_KITARI = 222;

        public const uint JPOS_KURU_KITAROU = 223;

        public const uint JPOS_KURU_KITE = 224;

        public const uint JPOS_KURU_KUREBA = 225;

        public const uint JPOS_KURU_KO = 226;

        public const uint JPOS_KURU_KOI = 227;

        public const uint JPOS_KURU_KOYOU = 228;

        public const uint JPOS_SURU_SA = 229;

        public const uint JPOS_SURU_SI = 230;

        public const uint JPOS_SURU_SITA = 231;

        public const uint JPOS_SURU_SITARA = 232;

        public const uint JPOS_SURU_SIATRI = 233;

        public const uint JPOS_SURU_SITAROU = 234;

        public const uint JPOS_SURU_SITE = 235;

        public const uint JPOS_SURU_SIYOU = 236;

        public const uint JPOS_SURU_SUREBA = 237;

        public const uint JPOS_SURU_SE = 238;

        public const uint JPOS_SURU_SEYO = 239;

        public const uint JPOS_KEIYOU = 300;

        public const uint JPOS_KEIYOU_GARU = 301;

        public const uint JPOS_KEIYOU_GE = 302;

        public const uint JPOS_KEIYOU_ME = 303;

        public const uint JPOS_KEIYOU_YUU = 304;

        public const uint JPOS_KEIYOU_U = 305;

        public const uint JPOS_KEIDOU = 400;

        public const uint JPOS_KEIDOU_NO = 401;

        public const uint JPOS_KEIDOU_TARU = 402;

        public const uint JPOS_KEIDOU_GARU = 403;

        public const uint JPOS_FUKUSHI = 500;

        public const uint JPOS_FUKUSHI_SAHEN = 501;

        public const uint JPOS_FUKUSHI_NI = 502;

        public const uint JPOS_FUKUSHI_NANO = 503;

        public const uint JPOS_FUKUSHI_DA = 504;

        public const uint JPOS_FUKUSHI_TO = 505;

        public const uint JPOS_FUKUSHI_TOSURU = 506;

        public const uint JPOS_RENTAISHI = 600;

        public const uint JPOS_RENTAISHI_SHIJI = 601;

        public const uint JPOS_SETSUZOKUSHI = 650;

        public const uint JPOS_KANDOUSHI = 670;

        public const uint JPOS_SETTOU = 700;

        public const uint JPOS_SETTOU_KAKU = 701;

        public const uint JPOS_SETTOU_SAI = 702;

        public const uint JPOS_SETTOU_FUKU = 703;

        public const uint JPOS_SETTOU_MI = 704;

        public const uint JPOS_SETTOU_DAISHOU = 705;

        public const uint JPOS_SETTOU_KOUTEI = 706;

        public const uint JPOS_SETTOU_CHOUTAN = 707;

        public const uint JPOS_SETTOU_SHINKYU = 708;

        public const uint JPOS_SETTOU_JINMEI = 709;

        public const uint JPOS_SETTOU_CHIMEI = 710;

        public const uint JPOS_SETTOU_SONOTA = 711;

        public const uint JPOS_SETTOU_JOSUSHI = 712;

        public const uint JPOS_SETTOU_TEINEI_O = 713;

        public const uint JPOS_SETTOU_TEINEI_GO = 714;

        public const uint JPOS_SETTOU_TEINEI_ON = 715;

        public const uint JPOS_SETSUBI = 800;

        public const uint JPOS_SETSUBI_TEKI = 801;

        public const uint JPOS_SETSUBI_SEI = 802;

        public const uint JPOS_SETSUBI_KA = 803;

        public const uint JPOS_SETSUBI_CHU = 804;

        public const uint JPOS_SETSUBI_FU = 805;

        public const uint JPOS_SETSUBI_RYU = 806;

        public const uint JPOS_SETSUBI_YOU = 807;

        public const uint JPOS_SETSUBI_KATA = 808;

        public const uint JPOS_SETSUBI_MEISHIRENDAKU = 809;

        public const uint JPOS_SETSUBI_JINMEI = 810;

        public const uint JPOS_SETSUBI_CHIMEI = 811;

        public const uint JPOS_SETSUBI_KUNI = 812;

        public const uint JPOS_SETSUBI_KEN = 813;

        public const uint JPOS_SETSUBI_GUN = 814;

        public const uint JPOS_SETSUBI_KU = 815;

        public const uint JPOS_SETSUBI_SHI = 816;

        public const uint JPOS_SETSUBI_MACHI = 817;

        public const uint JPOS_SETSUBI_CHOU = 818;

        public const uint JPOS_SETSUBI_MURA = 819;

        public const uint JPOS_SETSUBI_SON = 820;

        public const uint JPOS_SETSUBI_EKI = 821;

        public const uint JPOS_SETSUBI_SONOTA = 822;

        public const uint JPOS_SETSUBI_SHAMEI = 823;

        public const uint JPOS_SETSUBI_SOSHIKI = 824;

        public const uint JPOS_SETSUBI_KENCHIKU = 825;

        public const uint JPOS_RENYOU_SETSUBI = 826;

        public const uint JPOS_SETSUBI_JOSUSHI = 827;

        public const uint JPOS_SETSUBI_JOSUSHIPLUS = 828;

        public const uint JPOS_SETSUBI_JIKAN = 829;

        public const uint JPOS_SETSUBI_JIKANPLUS = 830;

        public const uint JPOS_SETSUBI_TEINEI = 831;

        public const uint JPOS_SETSUBI_SAN = 832;

        public const uint JPOS_SETSUBI_KUN = 833;

        public const uint JPOS_SETSUBI_SAMA = 834;

        public const uint JPOS_SETSUBI_DONO = 835;

        public const uint JPOS_SETSUBI_FUKUSU = 836;

        public const uint JPOS_SETSUBI_TACHI = 837;

        public const uint JPOS_SETSUBI_RA = 838;

        public const uint JPOS_TANKANJI = 900;

        public const uint JPOS_TANKANJI_KAO = 901;

        public const uint JPOS_KANYOUKU = 902;

        public const uint JPOS_DOKURITSUGO = 903;

        public const uint JPOS_FUTEIGO = 904;

        public const uint JPOS_KIGOU = 905;

        public const uint JPOS_EIJI = 906;

        public const uint JPOS_KUTEN = 907;

        public const uint JPOS_TOUTEN = 908;

        public const uint JPOS_KANJI = 909;

        public const uint JPOS_OPENBRACE = 910;

        public const uint JPOS_CLOSEBRACE = 911;

        public const uint JPOS_YOKUSEI = 912;

        public const uint JPOS_TANSHUKU = 913;

        public const uint VERSION_ID_JAPANESE = 0x01000000;

        public const uint VERSION_ID_KOREAN = 0x02000000;

        public const uint VERSION_ID_CHINESE_TRADITIONAL = 0x04000000;

        public const uint VERSION_ID_CHINESE_SIMPLIFIED = 0x08000000;

        public const uint FID_MSIME_VERSION = 0;

        public const uint VERSION_MOUSE_OPERATION = 1;

        public const int IMEMOUSERET_NOTHANDLED = -1;

        public const uint IMEMOUSE_VERSION = 0xff;

        public const uint IMEMOUSE_NONE = 0x00;

        public const uint IMEMOUSE_LDOWN = 0x01;

        public const uint IMEMOUSE_RDOWN = 0x02;

        public const uint IMEMOUSE_MDOWN = 0x04;

        public const uint IMEMOUSE_WUP = 0x10;

        public const uint IMEMOUSE_WDOWN = 0x20;

        public const uint FID_RECONVERT_VERSION = 0x10000000;

        public const uint VERSION_RECONVERSION = 1;

        public const uint VERSION_DOCUMENTFEED = 1;

        public const uint VERSION_QUERYPOSITION = 1;

        public const uint VERSION_MODEBIAS = 1;

        public const uint MODEBIAS_GETVERSION = 0;

        public const uint MODEBIAS_SETVALUE = 1;

        public const uint MODEBIAS_GETVALUE = 2;

        public const uint MODEBIASMODE_DEFAULT = 0x00000000;

        public const uint MODEBIASMODE_FILENAME = 0x00000001;

        public const uint MODEBIASMODE_READING = 0x00000002;

        public const uint MODEBIASMODE_DIGIT = 0x00000004;

        public const uint SHOWIMEPAD_DEFAULT = 0x00000000;

        public const uint SHOWIMEPAD_CATEGORY = 0x00000001;

        public const uint SHOWIMEPAD_GUID = 0x00000002;

        public const uint FID_MSIME_KMS_VERSION = 1;

        public const uint FID_MSIME_KMS_INIT = 2;

        public const uint FID_MSIME_KMS_TERM = 3;

        public const uint FID_MSIME_KMS_DEL_KEYLIST = 4;

        public const uint FID_MSIME_KMS_NOTIFY = 5;

        public const uint FID_MSIME_KMS_GETMAP = 6;

        public const uint FID_MSIME_KMS_INVOKE = 7;

        public const uint FID_MSIME_KMS_SETMAP = 8;

        public const uint FID_MSIME_KMS_FUNCDESC = 9;

        public const uint FID_MSIME_KMS_GETMAPSEAMLESS = 10;

        public const uint FID_MSIME_KMS_GETMAPFAST = 11;

        public const uint IMEKMS_NOCOMPOSITION = 0;

        public const uint IMEKMS_COMPOSITION = 1;

        public const uint IMEKMS_SELECTION = 2;

        public const uint IMEKMS_IMEOFF = 3;

        public const uint IMEKMS_2NDLEVEL = 4;

        public const uint IMEKMS_INPTGL = 5;

        public const uint IMEKMS_CANDIDATE = 6;

        public const uint IMEKMS_TYPECAND = 7;

        public const uint RECONVOPT_NONE = 0x00000000;

        public const uint RECONVOPT_USECANCELNOTIFY = 0x00000001;

        public const uint GCSEX_CANCELRECONVERT = 0x10000000;

        public const uint STYLE_DESCRIPTION_SIZE = 32;

        public const uint IMEMENUITEM_STRING_SIZE = 80;

        public const uint IMC_GETCANDIDATEPOS = 0x0007;

        public const uint IMC_SETCANDIDATEPOS = 0x0008;

        public const uint IMC_GETCOMPOSITIONFONT = 0x0009;

        public const uint IMC_SETCOMPOSITIONFONT = 0x000A;

        public const uint IMC_GETCOMPOSITIONWINDOW = 0x000B;

        public const uint IMC_SETCOMPOSITIONWINDOW = 0x000C;

        public const uint IMC_GETSTATUSWINDOWPOS = 0x000F;

        public const uint IMC_SETSTATUSWINDOWPOS = 0x0010;

        public const uint IMC_CLOSESTATUSWINDOW = 0x0021;

        public const uint IMC_OPENSTATUSWINDOW = 0x0022;

        public const uint NI_FINALIZECONVERSIONRESULT = 0x0014;

        public const uint ISC_SHOWUICANDIDATEWINDOW = 0x00000001;

        public const uint ISC_SHOWUICOMPOSITIONWINDOW = 0x80000000;

        public const uint ISC_SHOWUIGUIDELINE = 0x40000000;

        public const uint ISC_SHOWUIALLCANDIDATEWINDOW = 0x0000000F;

        public const uint ISC_SHOWUIALL = 0xC000000F;

        public const uint MOD_LEFT = 0x8000;

        public const uint MOD_RIGHT = 0x4000;

        public const uint MOD_ON_KEYUP = 0x0800;

        public const uint MOD_IGNORE_ALL_MODIFIER = 0x0400;

        public const uint IME_CHOTKEY_IME_NONIME_TOGGLE = 0x10;

        public const uint IME_CHOTKEY_SHAPE_TOGGLE = 0x11;

        public const uint IME_CHOTKEY_SYMBOL_TOGGLE = 0x12;

        public const uint IME_JHOTKEY_CLOSE_OPEN = 0x30;

        public const uint IME_KHOTKEY_SHAPE_TOGGLE = 0x50;

        public const uint IME_KHOTKEY_HANJACONVERT = 0x51;

        public const uint IME_KHOTKEY_ENGLISH = 0x52;

        public const uint IME_THOTKEY_IME_NONIME_TOGGLE = 0x70;

        public const uint IME_THOTKEY_SHAPE_TOGGLE = 0x71;

        public const uint IME_THOTKEY_SYMBOL_TOGGLE = 0x72;

        public const uint IME_HOTKEY_DSWITCH_FIRST = 0x100;

        public const uint IME_HOTKEY_DSWITCH_LAST = 0x11F;

        public const uint IME_HOTKEY_PRIVATE_FIRST = 0x200;

        public const uint IME_ITHOTKEY_RESEND_RESULTSTR = 0x200;

        public const uint IME_ITHOTKEY_PREVIOUS_COMPOSITION = 0x201;

        public const uint IME_ITHOTKEY_UISTYLE_TOGGLE = 0x202;

        public const uint IME_ITHOTKEY_RECONVERTSTRING = 0x203;

        public const uint IME_HOTKEY_PRIVATE_LAST = 0x21F;

        public const uint GCS_COMPREADSTR = 0x0001;

        public const uint GCS_COMPREADATTR = 0x0002;

        public const uint GCS_COMPREADCLAUSE = 0x0004;

        public const uint GCS_COMPSTR = 0x0008;

        public const uint GCS_COMPATTR = 0x0010;

        public const uint GCS_COMPCLAUSE = 0x0020;

        public const uint GCS_CURSORPOS = 0x0080;

        public const uint GCS_DELTASTART = 0x0100;

        public const uint GCS_RESULTREADSTR = 0x0200;

        public const uint GCS_RESULTREADCLAUSE = 0x0400;

        public const uint GCS_RESULTSTR = 0x0800;

        public const uint GCS_RESULTCLAUSE = 0x1000;

        public const uint CS_INSERTCHAR = 0x2000;

        public const uint CS_NOMOVECARET = 0x4000;

        public const uint IMEVER_0310 = 0x0003000A;

        public const uint IMEVER_0400 = 0x00040000;

        public const uint IME_PROP_AT_CARET = 0x00010000;

        public const uint IME_PROP_SPECIAL_UI = 0x00020000;

        public const uint IME_PROP_CANDLIST_START_FROM_1 = 0x00040000;

        public const uint IME_PROP_UNICODE = 0x00080000;

        public const uint IME_PROP_COMPLETE_ON_UNSELECT = 0x00100000;

        public const uint UI_CAP_2700 = 0x00000001;

        public const uint UI_CAP_ROT90 = 0x00000002;

        public const uint UI_CAP_ROTANY = 0x00000004;

        public const uint SCS_CAP_COMPSTR = 0x00000001;

        public const uint SCS_CAP_MAKEREAD = 0x00000002;

        public const uint SCS_CAP_SETRECONVERTSTRING = 0x00000004;

        public const uint SELECT_CAP_CONVERSION = 0x00000001;

        public const uint SELECT_CAP_SENTENCE = 0x00000002;

        public const uint GL_LEVEL_NOGUIDELINE = 0x00000000;

        public const uint GL_LEVEL_FATAL = 0x00000001;

        public const uint GL_LEVEL_ERROR = 0x00000002;

        public const uint GL_LEVEL_WARNING = 0x00000003;

        public const uint GL_LEVEL_INFORMATION = 0x00000004;

        public const uint GL_ID_UNKNOWN = 0x00000000;

        public const uint GL_ID_NOMODULE = 0x00000001;

        public const uint GL_ID_NODICTIONARY = 0x00000010;

        public const uint GL_ID_CANNOTSAVE = 0x00000011;

        public const uint GL_ID_NOCONVERT = 0x00000020;

        public const uint GL_ID_TYPINGERROR = 0x00000021;

        public const uint GL_ID_TOOMANYSTROKE = 0x00000022;

        public const uint GL_ID_READINGCONFLICT = 0x00000023;

        public const uint GL_ID_INPUTREADING = 0x00000024;

        public const uint GL_ID_INPUTRADICAL = 0x00000025;

        public const uint GL_ID_INPUTCODE = 0x00000026;

        public const uint GL_ID_INPUTSYMBOL = 0x00000027;

        public const uint GL_ID_CHOOSECANDIDATE = 0x00000028;

        public const uint GL_ID_REVERSECONVERSION = 0x00000029;

        public const uint GL_ID_PRIVATE_FIRST = 0x00008000;

        public const uint GL_ID_PRIVATE_LAST = 0x0000FFFF;

        public const uint ATTR_INPUT = 0x00;

        public const uint ATTR_TARGET_CONVERTED = 0x01;

        public const uint ATTR_CONVERTED = 0x02;

        public const uint ATTR_TARGET_NOTCONVERTED = 0x03;

        public const uint ATTR_INPUT_ERROR = 0x04;

        public const uint ATTR_FIXEDCONVERTED = 0x05;

        public const uint CFS_DEFAULT = 0x0000;

        public const uint CFS_RECT = 0x0001;

        public const uint CFS_POINT = 0x0002;

        public const uint CFS_FORCE_POSITION = 0x0020;

        public const uint CFS_CANDIDATEPOS = 0x0040;

        public const uint CFS_EXCLUDE = 0x0080;

        public const uint IME_CMODE_SOFTKBD = 0x0080;

        public const uint IME_CMODE_NOCONVERSION = 0x0100;

        public const uint IME_CMODE_EUDC = 0x0200;

        public const uint IME_CMODE_SYMBOL = 0x0400;

        public const uint IME_CMODE_FIXED = 0x0800;

        public const uint IME_CMODE_RESERVED = 0xF0000000;

        public const uint IME_SMODE_NONE = 0x0000;

        public const uint IME_SMODE_PLAURALCLAUSE = 0x0001;

        public const uint IME_SMODE_SINGLECONVERT = 0x0002;

        public const uint IME_SMODE_AUTOMATIC = 0x0004;

        public const uint IME_SMODE_PHRASEPREDICT = 0x0008;

        public const uint IME_SMODE_CONVERSATION = 0x0010;

        public const uint IME_SMODE_RESERVED = 0x0000F000;

        public const uint IME_CAND_UNKNOWN = 0x0000;

        public const uint IME_CAND_READ = 0x0001;

        public const uint IME_CAND_CODE = 0x0002;

        public const uint IME_CAND_MEANING = 0x0003;

        public const uint IME_CAND_RADICAL = 0x0004;

        public const uint IME_CAND_STROKE = 0x0005;

        public const uint IMN_CLOSESTATUSWINDOW = 0x0001;

        public const uint IMN_OPENSTATUSWINDOW = 0x0002;

        public const uint IMN_CHANGECANDIDATE = 0x0003;

        public const uint IMN_CLOSECANDIDATE = 0x0004;

        public const uint IMN_OPENCANDIDATE = 0x0005;

        public const uint IMN_SETCONVERSIONMODE = 0x0006;

        public const uint IMN_SETSENTENCEMODE = 0x0007;

        public const uint IMN_SETOPENSTATUS = 0x0008;

        public const uint IMN_SETCANDIDATEPOS = 0x0009;

        public const uint IMN_SETCOMPOSITIONFONT = 0x000A;

        public const uint IMN_SETCOMPOSITIONWINDOW = 0x000B;

        public const uint IMN_SETSTATUSWINDOWPOS = 0x000C;

        public const uint IMN_GUIDELINE = 0x000D;

        public const uint IMN_PRIVATE = 0x000E;

        public const uint IMR_COMPOSITIONWINDOW = 0x0001;

        public const uint IMR_CANDIDATEWINDOW = 0x0002;

        public const uint IMR_COMPOSITIONFONT = 0x0003;

        public const uint IMR_RECONVERTSTRING = 0x0004;

        public const uint IMR_CONFIRMRECONVERTSTRING = 0x0005;

        public const uint IMR_QUERYCHARPOSITION = 0x0006;

        public const uint IMR_DOCUMENTFEED = 0x0007;

        public const int IMM_ERROR_NODATA = -1;

        public const int IMM_ERROR_GENERAL = -2;

        public const uint IME_CONFIG_GENERAL = 1;

        public const uint IME_CONFIG_REGISTERWORD = 2;

        public const uint IME_CONFIG_SELECTDICTIONARY = 3;

        public const uint IME_ESC_QUERY_SUPPORT = 0x0003;

        public const uint IME_ESC_RESERVED_FIRST = 0x0004;

        public const uint IME_ESC_RESERVED_LAST = 0x07FF;

        public const uint IME_ESC_PRIVATE_FIRST = 0x0800;

        public const uint IME_ESC_PRIVATE_LAST = 0x0FFF;

        public const uint IME_ESC_SEQUENCE_TO_INTERNAL = 0x1001;

        public const uint IME_ESC_GET_EUDC_DICTIONARY = 0x1003;

        public const uint IME_ESC_SET_EUDC_DICTIONARY = 0x1004;

        public const uint IME_ESC_MAX_KEY = 0x1005;

        public const uint IME_ESC_IME_NAME = 0x1006;

        public const uint IME_ESC_SYNC_HOTKEY = 0x1007;

        public const uint IME_ESC_HANJA_MODE = 0x1008;

        public const uint IME_ESC_AUTOMATA = 0x1009;

        public const uint IME_ESC_PRIVATE_HOTKEY = 0x100a;

        public const uint IME_ESC_GETHELPFILENAME = 0x100b;

        public const uint IME_REGWORD_STYLE_EUDC = 0x00000001;

        public const uint IME_REGWORD_STYLE_USER_FIRST = 0x80000000;

        public const uint IME_REGWORD_STYLE_USER_LAST = 0xFFFFFFFF;

        public const uint IACE_CHILDREN = 0x0001;

        public const uint IACE_DEFAULT = 0x0010;

        public const uint IACE_IGNORENOCONTEXT = 0x0020;

        public const uint IGIMIF_RIGHTMENU = 0x0001;

        public const uint IGIMII_CMODE = 0x0001;

        public const uint IGIMII_SMODE = 0x0002;

        public const uint IGIMII_CONFIGURE = 0x0004;

        public const uint IGIMII_TOOLS = 0x0008;

        public const uint IGIMII_HELP = 0x0010;

        public const uint IGIMII_OTHER = 0x0020;

        public const uint IGIMII_INPUTTOOLS = 0x0040;

        public const uint IMFT_RADIOCHECK = 0x00001;

        public const uint IMFT_SEPARATOR = 0x00002;

        public const uint IMFT_SUBMENU = 0x00004;

        public const uint SOFTKEYBOARD_TYPE_T1 = 0x0001;

        public const uint SOFTKEYBOARD_TYPE_C1 = 0x0002;

        public const uint IMMGWL_IMC = 0;

        public const uint IMMGWLP_IMC = 0;

        public const uint IMC_SETCONVERSIONMODE = 0x0002;

        public const uint IMC_SETSENTENCEMODE = 0x0004;

        public const uint IMC_SETOPENSTATUS = 0x0006;

        public const uint IMC_GETSOFTKBDFONT = 0x0011;

        public const uint IMC_SETSOFTKBDFONT = 0x0012;

        public const uint IMC_GETSOFTKBDPOS = 0x0013;

        public const uint IMC_SETSOFTKBDPOS = 0x0014;

        public const uint IMC_GETSOFTKBDSUBTYPE = 0x0015;

        public const uint IMC_SETSOFTKBDSUBTYPE = 0x0016;

        public const uint IMC_SETSOFTKBDDATA = 0x0018;

        public const uint NI_CONTEXTUPDATED = 0x0003;

        public const uint IME_SYSINFO_WINLOGON = 0x0001;

        public const uint IME_SYSINFO_WOW16 = 0x0002;

        public const uint INIT_STATUSWNDPOS = 0x00000001;

        public const uint INIT_CONVERSION = 0x00000002;

        public const uint INIT_SENTENCE = 0x00000004;

        public const uint INIT_LOGFONT = 0x00000008;

        public const uint INIT_COMPFORM = 0x00000010;

        public const uint INIT_SOFTKBDPOS = 0x00000020;

        public const uint IME_PROP_END_UNLOAD = 0x00000001;

        public const uint IME_PROP_KBD_CHAR_FIRST = 0x00000002;

        public const uint IME_PROP_IGNORE_UPKEYS = 0x00000004;

        public const uint IME_PROP_NEED_ALTKEY = 0x00000008;

        public const uint IME_PROP_NO_KEYS_ON_CLOSE = 0x00000010;

        public const uint IME_PROP_ACCEPT_WIDE_VKEY = 0x00000020;

        public const uint UI_CAP_SOFTKBD = 0x00010000;

        public const uint IMN_SOFTKBDDESTROYED = 0x0011;

        public const uint IME_UI_CLASS_NAME_SIZE = 16;

        public const uint IME_ESC_STRING_BUFFER_SIZE = 80;

        public static readonly Guid CATID_MSIME_IImePadApplet_VER7__scanned__ = new Guid(0x4a0f8e31, 0xc3ee, 0x11d1, 0xaf, 0xef, 0x0, 0x80, 0x5f, 0xc, 0x8b, 0x6d);

        public static readonly Guid CATID_MSIME_IImePadApplet_VER80__scanned__ = new Guid(0x56f7a792, 0xfef1, 0x11d3, 0x84, 0x63, 0x0, 0xc0, 0x4f, 0x7a, 0x6, 0xe5);

        public static readonly Guid CATID_MSIME_IImePadApplet_VER81__scanned__ = new Guid(0x656520b0, 0xbb88, 0x11d4, 0x84, 0xc0, 0x0, 0xc0, 0x4f, 0x7a, 0x6, 0xe5);

        public static readonly Guid CATID_MSIME_IImePadApplet900__scanned__ = new Guid(0xfaae51bf, 0x5e5b, 0x4a1d, 0x8d, 0xe1, 0x17, 0xc1, 0xd9, 0xe1, 0x72, 0x8d);

        public static readonly Guid CATID_MSIME_IImePadApplet1000__scanned__ = new Guid(0xe081e1d6, 0x2389, 0x43cb, 0xb6, 0x6f, 0x60, 0x9f, 0x82, 0x3d, 0x9f, 0x9c);

        public static readonly Guid CATID_MSIME_IImePadApplet1200__scanned__ = new Guid(0xa47fb5fc, 0x7d15, 0x4223, 0xa7, 0x89, 0xb7, 0x81, 0xbf, 0x9a, 0xe6, 0x67);

        public static readonly Guid CATID_MSIME_IImePadApplet__scanned__ = new Guid(0x7566cad1, 0x4ec9, 0x4478, 0x9f, 0xe9, 0x8e, 0xd7, 0x66, 0x61, 0x9e, 0xdf);

        public static readonly Guid IID_IImePad__scanned__ = new Guid(0x5d8e643a, 0xc3a9, 0x11d1, 0xaf, 0xef, 0x0, 0x80, 0x5f, 0xc, 0x8b, 0x6d);

        public static readonly Guid IID_IImePadApplet__scanned__ = new Guid(0x5d8e643b, 0xc3a9, 0x11d1, 0xaf, 0xef, 0x0, 0x80, 0x5f, 0xc, 0x8b, 0x6d);

        public static readonly Guid IID_IImeSpecifyApplets__scanned__ = new Guid(0x5d8e643c, 0xc3a9, 0x11d1, 0xaf, 0xef, 0x0, 0x80, 0x5f, 0xc, 0x8b, 0x6d);

        public const uint FEID_NONE = 0x00;

        public const uint FEID_CHINESE_TRADITIONAL = 0x01;

        public const uint FEID_CHINESE_SIMPLIFIED = 0x02;

        public const uint FEID_CHINESE_HONGKONG = 0x03;

        public const uint FEID_CHINESE_SINGAPORE = 0x04;

        public const uint FEID_JAPANESE = 0x05;

        public const uint FEID_KOREAN = 0x06;

        public const uint FEID_KOREAN_JOHAB = 0x07;

        public const uint INFOMASK_NONE = 0x00000000;

        public const uint INFOMASK_QUERY_CAND = 0x00000001;

        public const uint INFOMASK_APPLY_CAND = 0x00000002;

        public const uint INFOMASK_APPLY_CAND_EX = 0x00000004;

        public const uint INFOMASK_STRING_FIX = 0x00010000;

        public const uint INFOMASK_HIDE_CAND = 0x00020000;

        public const uint INFOMASK_BLOCK_CAND = 0x00040000;

        public const uint IMEFAREASTINFO_TYPE_DEFAULT = 0;

        public const uint IMEFAREASTINFO_TYPE_READING = 1;

        public const uint IMEFAREASTINFO_TYPE_COMMENT = 2;

        public const uint IMEFAREASTINFO_TYPE_COSTTIME = 3;

        public const uint CHARINFO_APPLETID_MASK = 0xFF000000;

        public const uint CHARINFO_FEID_MASK = 0x00F00000;

        public const uint CHARINFO_CHARID_MASK = 0x0000FFFF;

        public const uint MAX_APPLETTITLE = 64;

        public const uint MAX_FONTFACE = 32;

        public const int IPACFG_NONE = 0x00000000;

        public const int IPACFG_PROPERTY = 0x00000001;

        public const int IPACFG_HELP = 0x00000002;

        public const int IPACFG_TITLE = 0x00010000;

        public const int IPACFG_TITLEFONTFACE = 0x00020000;

        public const int IPACFG_CATEGORY = 0x00040000;

        public const int IPACFG_LANG = 0x00000010;

        public const uint IPACID_NONE = 0x0000;

        public const uint IPACID_SOFTKEY = 0x0001;

        public const uint IPACID_HANDWRITING = 0x0002;

        public const uint IPACID_STROKESEARCH = 0x0003;

        public const uint IPACID_RADICALSEARCH = 0x0004;

        public const uint IPACID_SYMBOLSEARCH = 0x0005;

        public const uint IPACID_VOICE = 0x0006;

        public const uint IPACID_EPWING = 0x0007;

        public const uint IPACID_OCR = 0x0008;

        public const uint IPACID_CHARLIST = 0x0009;

        public const uint IPACID_USER = 0x0100;

        public const uint IMEPADREQ_FIRST = 0x1000;

        public const uint IMEPADREQ_INSERTSTRINGCANDIDATE = IMEPADREQ_FIRST + 2;

        public const uint IMEPADREQ_INSERTITEMCANDIDATE = IMEPADREQ_FIRST + 3;

        public const uint IMEPADREQ_SENDKEYCONTROL = IMEPADREQ_FIRST + 5;

        public const uint IMEPADREQ_GETSELECTEDSTRING = IMEPADREQ_FIRST + 7;

        public const uint IMEPADREQ_SETAPPLETDATA = IMEPADREQ_FIRST + 9;

        public const uint IMEPADREQ_GETAPPLETDATA = IMEPADREQ_FIRST + 10;

        public const uint IMEPADREQ_SETTITLEFONT = IMEPADREQ_FIRST + 11;

        public const uint IMEPADREQ_GETCOMPOSITIONSTRINGID = IMEPADREQ_FIRST + 13;

        public const uint IMEPADREQ_INSERTSTRINGCANDIDATEINFO = IMEPADREQ_FIRST + 14;

        public const uint IMEPADREQ_CHANGESTRINGCANDIDATEINFO = IMEPADREQ_FIRST + 15;

        public const uint IMEPADREQ_INSERTSTRINGINFO = IMEPADREQ_FIRST + 18;

        public const uint IMEPADREQ_CHANGESTRINGINFO = IMEPADREQ_FIRST + 19;

        public const uint IMEPADREQ_GETCURRENTUILANGID = IMEPADREQ_FIRST + 24;

        public const uint IMEPADCTRL_CONVERTALL = 1;

        public const uint IMEPADCTRL_DETERMINALL = 2;

        public const uint IMEPADCTRL_DETERMINCHAR = 3;

        public const uint IMEPADCTRL_CLEARALL = 4;

        public const uint IMEPADCTRL_CARETSET = 5;

        public const uint IMEPADCTRL_CARETLEFT = 6;

        public const uint IMEPADCTRL_CARETRIGHT = 7;

        public const uint IMEPADCTRL_CARETTOP = 8;

        public const uint IMEPADCTRL_CARETBOTTOM = 9;

        public const uint IMEPADCTRL_CARETBACKSPACE = 10;

        public const uint IMEPADCTRL_CARETDELETE = 11;

        public const uint IMEPADCTRL_PHRASEDELETE = 12;

        public const uint IMEPADCTRL_INSERTSPACE = 13;

        public const uint IMEPADCTRL_INSERTFULLSPACE = 14;

        public const uint IMEPADCTRL_INSERTHALFSPACE = 15;

        public const uint IMEPADCTRL_ONIME = 16;

        public const uint IMEPADCTRL_OFFIME = 17;

        public const uint IMEPADCTRL_ONPRECONVERSION = 18;

        public const uint IMEPADCTRL_OFFPRECONVERSION = 19;

        public const uint IMEPADCTRL_PHONETICCANDIDATE = 20;

        public const uint IMEKEYCTRLMASK_ALT = 0x0001;

        public const uint IMEKEYCTRLMASK_CTRL = 0x0002;

        public const uint IMEKEYCTRLMASK_SHIFT = 0x0004;

        public const uint IMEKEYCTRL_UP = 1;

        public const uint IMEKEYCTRL_DOWN = 0;

        public const uint IMEPN_FIRST = 0x0100;

        public const uint IMEPN_ACTIVATE = IMEPN_FIRST + 1;

        public const uint IMEPN_INACTIVATE = IMEPN_FIRST + 2;

        public const uint IMEPN_SHOW = IMEPN_FIRST + 4;

        public const uint IMEPN_HIDE = IMEPN_FIRST + 5;

        public const uint IMEPN_SIZECHANGING = IMEPN_FIRST + 6;

        public const uint IMEPN_SIZECHANGED = IMEPN_FIRST + 7;

        public const uint IMEPN_CONFIG = IMEPN_FIRST + 8;

        public const uint IMEPN_HELP = IMEPN_FIRST + 9;

        public const uint IMEPN_QUERYCAND = IMEPN_FIRST +10;

        public const uint IMEPN_APPLYCAND = IMEPN_FIRST +11;

        public const uint IMEPN_APPLYCANDEX = IMEPN_FIRST +12;

        public const uint IMEPN_SETTINGCHANGED = IMEPN_FIRST +13;

        public const uint IMEPN_USER = IMEPN_FIRST + 100;

        public const int IPAWS_ENABLED = 0x00000001;

        public const int IPAWS_SIZINGNOTIFY = 0x00000004;

        public const int IPAWS_VERTICALFIXED = 0x00000100;

        public const int IPAWS_HORIZONTALFIXED = 0x00000200;

        public const int IPAWS_SIZEFIXED = 0x00000300;

        public const int IPAWS_MAXWIDTHFIXED = 0x00001000;

        public const int IPAWS_MAXHEIGHTFIXED = 0x00002000;

        public const int IPAWS_MAXSIZEFIXED = 0x00003000;

        public const int IPAWS_MINWIDTHFIXED = 0x00010000;

        public const int IPAWS_MINHEIGHTFIXED = 0x00020000;

        public const int IPAWS_MINSIZEFIXED = 0x00030000;

        public static readonly Guid CLSID_ImePlugInDictDictionaryList_CHS__scanned__ = new Guid(0x7bf0129b, 0x5bef, 0x4de4, 0x9b, 0x0b, 0x5e, 0xdb, 0x66, 0xac, 0x2f, 0xa6);

        public static readonly Guid CLSID_ImePlugInDictDictionaryList_JPN__scanned__ = new Guid(0x4fe2776b, 0xb0f9, 0x4396, 0xb5, 0xfc, 0xe9, 0xd4, 0xcf, 0x1e, 0xc1, 0x95);

        public const uint SCRIPT_UNDEFINED = 0;

        [NativeTypeName("HRESULT")]
        public const int USP_E_SCRIPT_NOT_IN_FONT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x200));

        public const uint SGCM_RTL = 0x00000001;

        public const uint SSA_PASSWORD = 0x00000001;

        public const uint SSA_TAB = 0x00000002;

        public const uint SSA_CLIP = 0x00000004;

        public const uint SSA_FIT = 0x00000008;

        public const uint SSA_DZWG = 0x00000010;

        public const uint SSA_FALLBACK = 0x00000020;

        public const uint SSA_BREAK = 0x00000040;

        public const uint SSA_GLYPHS = 0x00000080;

        public const uint SSA_RTL = 0x00000100;

        public const uint SSA_GCP = 0x00000200;

        public const uint SSA_HOTKEY = 0x00000400;

        public const uint SSA_METAFILE = 0x00000800;

        public const uint SSA_LINK = 0x00001000;

        public const uint SSA_HIDEHOTKEY = 0x00002000;

        public const uint SSA_HOTKEYONLY = 0x00002400;

        public const uint SSA_FULLMEASURE = 0x04000000;

        public const uint SSA_LPKANSIFALLBACK = 0x08000000;

        public const uint SSA_PIDX = 0x10000000;

        public const uint SSA_LAYOUTRTL = 0x20000000;

        public const uint SSA_DONTGLYPH = 0x40000000;

        public const uint SSA_NOKASHIDA = 0x80000000;

        public const uint SCRIPT_DIGITSUBSTITUTE_CONTEXT = 0;

        public const uint SCRIPT_DIGITSUBSTITUTE_NONE = 1;

        public const uint SCRIPT_DIGITSUBSTITUTE_NATIONAL = 2;

        public const uint SCRIPT_DIGITSUBSTITUTE_TRADITIONAL = 3;

        public const uint UNISCRIBE_OPENTYPE = 0x0100;

        public const uint SCRIPT_TAG_UNKNOWN = 0x00000000;

        public const uint MUI_LANGUAGE_EXACT = 0x10;

        public const uint NLS_CP_CPINFO = 0x10000000;

        public const uint NLS_CP_MBTOWC = 0x40000000;

        public const uint NLS_CP_WCTOMB = 0x80000000;

        public const uint U_DISABLE_RENAMING = 1;

        public const uint U_SHOW_CPLUSPLUS_API = 0;

        public const uint U_DEFAULT_SHOW_DRAFT = 0;

        public const uint U_HIDE_DRAFT_API = 1;

        public const uint U_HIDE_DEPRECATED_API = 1;

        public const uint U_HIDE_OBSOLETE_API = 1;

        public const uint U_HIDE_INTERNAL_API = 1;

        public const uint U_NO_DEFAULT_INCLUDE_UTF_HEADERS = 1;

        public const uint UCLN_NO_AUTO_CLEANUP = 1;

        public const uint U_OVERRIDE_CXX_ALLOCATION = 1;

        public const uint U_ENABLE_TRACING = 0;

        public const uint UCONFIG_ENABLE_PLUGINS = 0;

        public const uint U_ENABLE_DYLOAD = 1;

        public const uint U_CHECK_DYLOAD = 1;

        public const uint U_PF_UNKNOWN = 0;

        public const uint U_PF_WINDOWS = 1000;

        public const uint U_PF_MINGW = 1800;

        public const uint U_PF_CYGWIN = 1900;

        public const uint U_PF_HPUX = 2100;

        public const uint U_PF_SOLARIS = 2600;

        public const uint U_PF_BSD = 3000;

        public const uint U_PF_AIX = 3100;

        public const uint U_PF_IRIX = 3200;

        public const uint U_PF_DARWIN = 3500;

        public const uint U_PF_IPHONE = 3550;

        public const uint U_PF_QNX = 3700;

        public const uint U_PF_LINUX = 4000;

        public const uint U_PF_BROWSER_NATIVE_CLIENT = 4020;

        public const uint U_PF_ANDROID = 4050;

        public const uint U_PF_FUCHSIA = 4100;

        public const uint U_PF_OS390 = 9000;

        public const uint U_PF_OS400 = 9400;

        public const uint U_ASCII_FAMILY = 0;

        public const uint U_EBCDIC_FAMILY = 1;

        public const uint U_SIZEOF_UCHAR = 2;

        public const int U_SENTINEL = -1;

        public const uint U8_MAX_LENGTH = 4;

        public const uint U16_MAX_LENGTH = 2;

        public const uint UTF_SIZE = 16;

        public const uint UTF8_ERROR_VALUE_1 = 0x15;

        public const uint UTF8_ERROR_VALUE_2 = 0x9f;

        public const uint UTF_ERROR_VALUE = 0xffff;

        public const uint UTF8_MAX_CHAR_LENGTH = 4;

        public const uint UTF16_MAX_CHAR_LENGTH = 2;

        public const uint UTF32_MAX_CHAR_LENGTH = 1;

        public const uint U_COPYRIGHT_STRING_LENGTH = 128;

        public const uint U_MAX_VERSION_LENGTH = 4;

        public const uint U_MAX_VERSION_STRING_LENGTH = 20;

        public const uint U_MILLIS_PER_SECOND = 1000;

        public const uint U_MILLIS_PER_MINUTE = 60000;

        public const uint U_MILLIS_PER_HOUR = 3600000;

        public const uint U_MILLIS_PER_DAY = 86400000;

        public const uint U_COMBINED_IMPLEMENTATION = 1;

        public const uint U_SHAPE_LENGTH_GROW_SHRINK = 0;

        public const uint U_SHAPE_LAMALEF_RESIZE = 0;

        public const uint U_SHAPE_LENGTH_FIXED_SPACES_NEAR = 1;

        public const uint U_SHAPE_LAMALEF_NEAR = 1;

        public const uint U_SHAPE_LENGTH_FIXED_SPACES_AT_END = 2;

        public const uint U_SHAPE_LAMALEF_END = 2;

        public const uint U_SHAPE_LENGTH_FIXED_SPACES_AT_BEGINNING = 3;

        public const uint U_SHAPE_LAMALEF_BEGIN = 3;

        public const uint U_SHAPE_LAMALEF_AUTO = 0x10000;

        public const uint U_SHAPE_LENGTH_MASK = 0x10003;

        public const uint U_SHAPE_LAMALEF_MASK = 0x10003;

        public const uint U_SHAPE_TEXT_DIRECTION_LOGICAL = 0;

        public const uint U_SHAPE_TEXT_DIRECTION_VISUAL_RTL = 0;

        public const uint U_SHAPE_TEXT_DIRECTION_VISUAL_LTR = 4;

        public const uint U_SHAPE_TEXT_DIRECTION_MASK = 4;

        public const uint U_SHAPE_LETTERS_NOOP = 0;

        public const uint U_SHAPE_LETTERS_SHAPE = 8;

        public const uint U_SHAPE_LETTERS_UNSHAPE = 0x10;

        public const uint U_SHAPE_LETTERS_SHAPE_TASHKEEL_ISOLATED = 0x18;

        public const uint U_SHAPE_LETTERS_MASK = 0x18;

        public const uint U_SHAPE_DIGITS_NOOP = 0;

        public const uint U_SHAPE_DIGITS_EN2AN = 0x20;

        public const uint U_SHAPE_DIGITS_AN2EN = 0x40;

        public const uint U_SHAPE_DIGITS_ALEN2AN_INIT_LR = 0x60;

        public const uint U_SHAPE_DIGITS_ALEN2AN_INIT_AL = 0x80;

        public const uint U_SHAPE_DIGITS_RESERVED = 0xa0;

        public const uint U_SHAPE_DIGITS_MASK = 0xe0;

        public const uint U_SHAPE_DIGIT_TYPE_AN = 0;

        public const uint U_SHAPE_DIGIT_TYPE_AN_EXTENDED = 0x100;

        public const uint U_SHAPE_DIGIT_TYPE_RESERVED = 0x200;

        public const uint U_SHAPE_DIGIT_TYPE_MASK = 0x300;

        public const uint U_SHAPE_AGGREGATE_TASHKEEL = 0x4000;

        public const uint U_SHAPE_AGGREGATE_TASHKEEL_NOOP = 0;

        public const uint U_SHAPE_AGGREGATE_TASHKEEL_MASK = 0x4000;

        public const uint U_SHAPE_PRESERVE_PRESENTATION = 0x8000;

        public const uint U_SHAPE_PRESERVE_PRESENTATION_NOOP = 0;

        public const uint U_SHAPE_PRESERVE_PRESENTATION_MASK = 0x8000;

        public const uint U_SHAPE_SEEN_TWOCELL_NEAR = 0x200000;

        public const uint U_SHAPE_SEEN_MASK = 0x700000;

        public const uint U_SHAPE_YEHHAMZA_TWOCELL_NEAR = 0x1000000;

        public const uint U_SHAPE_YEHHAMZA_MASK = 0x3800000;

        public const uint U_SHAPE_TASHKEEL_BEGIN = 0x40000;

        public const uint U_SHAPE_TASHKEEL_END = 0x60000;

        public const uint U_SHAPE_TASHKEEL_RESIZE = 0x80000;

        public const uint U_SHAPE_TASHKEEL_REPLACE_BY_TATWEEL = 0xC0000;

        public const uint U_SHAPE_TASHKEEL_MASK = 0xE0000;

        public const uint U_SHAPE_SPACES_RELATIVE_TO_TEXT_BEGIN_END = 0x4000000;

        public const uint U_SHAPE_SPACES_RELATIVE_TO_TEXT_MASK = 0x4000000;

        public const uint U_SHAPE_TAIL_NEW_UNICODE = 0x8000000;

        public const uint U_SHAPE_TAIL_TYPE_MASK = 0x8000000;

        public const uint ULOC_LANG_CAPACITY = 12;

        public const uint ULOC_COUNTRY_CAPACITY = 4;

        public const uint ULOC_FULLNAME_CAPACITY = 157;

        public const uint ULOC_SCRIPT_CAPACITY = 6;

        public const uint ULOC_KEYWORDS_CAPACITY = 96;

        public const uint ULOC_KEYWORD_AND_VALUES_CAPACITY = 100;

        public const uint ULOC_KEYWORD_SEPARATOR_UNICODE = 0x40;

        public const uint ULOC_KEYWORD_ASSIGN_UNICODE = 0x3D;

        public const uint ULOC_KEYWORD_ITEM_SEPARATOR_UNICODE = 0x3B;

        public const uint UCNV_MAX_CONVERTER_NAME_LENGTH = 60;

        public const uint UCNV_SI = 0x0F;

        public const uint UCNV_SO = 0x0E;

        public const uint U_FOLD_CASE_DEFAULT = 0;

        public const uint U_FOLD_CASE_EXCLUDE_SPECIAL_I = 1;

        public const uint U_TITLECASE_WHOLE_STRING = 0x20;

        public const uint U_TITLECASE_SENTENCES = 0x40;

        public const uint U_TITLECASE_NO_LOWERCASE = 0x100;

        public const uint U_TITLECASE_NO_BREAK_ADJUSTMENT = 0x200;

        public const uint U_TITLECASE_ADJUST_TO_CASED = 0x400;

        public const uint U_EDITS_NO_RESET = 0x2000;

        public const uint U_OMIT_UNCHANGED_TEXT = 0x4000;

        public const uint U_COMPARE_CODE_POINT_ORDER = 0x8000;

        public const uint U_COMPARE_IGNORE_CASE = 0x10000;

        public const uint UNORM_INPUT_IS_FCD = 0x20000;

        public const uint UCHAR_MIN_VALUE = 0;

        public const uint UCHAR_MAX_VALUE = 0x10ffff;

        public const uint UBIDI_DEFAULT_LTR = 0xfe;

        public const uint UBIDI_DEFAULT_RTL = 0xff;

        public const uint UBIDI_MAX_EXPLICIT_LEVEL = 125;

        public const uint UBIDI_LEVEL_OVERRIDE = 0x80;

        public const int UBIDI_MAP_NOWHERE = -1;

        public const uint UBIDI_KEEP_BASE_COMBINING = 1;

        public const uint UBIDI_DO_MIRRORING = 2;

        public const uint UBIDI_INSERT_LRM_FOR_NUMERIC = 4;

        public const uint UBIDI_REMOVE_BIDI_CONTROLS = 8;

        public const uint UBIDI_OUTPUT_REVERSE = 16;

        public const uint USPREP_DEFAULT = 0x0000;

        public const uint USPREP_ALLOW_UNASSIGNED = 0x0001;

        public const int USEARCH_DONE = -1;

    }
}

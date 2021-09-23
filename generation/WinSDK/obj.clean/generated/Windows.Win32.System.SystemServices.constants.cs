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


namespace Windows.Win32.System.SystemServices
{
    public static partial class Apis
    {
        public const uint ANYSIZE_ARRAY = 1;

        public const uint MEMORY_ALLOCATION_ALIGNMENT = 16;

        public const uint SYSTEM_CACHE_ALIGNMENT_SIZE = 64;

        public const uint PRAGMA_DEPRECATED_DDK = 1;

        public const uint UCSCHAR_INVALID_CHARACTER = 0xffffffff;

        public const uint MIN_UCSCHAR = 0;

        public const uint MAX_UCSCHAR = 0x0010FFFF;

        public const uint ALL_PROCESSOR_GROUPS = 0xffff;

        public const uint MAXIMUM_PROC_PER_GROUP = 64;

        public const uint APPLICATION_ERROR_MASK = 0x20000000;

        public const uint ERROR_SEVERITY_SUCCESS = 0x00000000;

        public const uint ERROR_SEVERITY_INFORMATIONAL = 0x40000000;

        public const uint ERROR_SEVERITY_WARNING = 0x80000000;

        public const uint ERROR_SEVERITY_ERROR = 0xC0000000;

        public const ulong MAXLONGLONG = 0x7fffffffffffffff;

        public const uint UNICODE_STRING_MAX_CHARS = 32767;

        public const uint MINCHAR = 0x80;

        public const uint MAXCHAR = 0x7f;

        public const uint MINSHORT = 0x8000;

        public const uint MAXSHORT = 0x7fff;

        public const uint MINLONG = 0x80000000;

        public const uint MAXLONG = 0x7fffffff;

        public const uint MAXBYTE = 0xff;

        public const uint MAXWORD = 0xffff;

        public const uint MAXDWORD = 0xffffffff;

        public const uint ENCLAVE_SHORT_ID_LENGTH = 16;

        public const uint ENCLAVE_LONG_ID_LENGTH = 32;

        public const uint VER_SERVER_NT = 0x80000000;

        public const uint VER_WORKSTATION_NT = 0x40000000;

        public const uint VER_SUITE_SMALLBUSINESS = 0x00000001;

        public const uint VER_SUITE_ENTERPRISE = 0x00000002;

        public const uint VER_SUITE_BACKOFFICE = 0x00000004;

        public const uint VER_SUITE_COMMUNICATIONS = 0x00000008;

        public const uint VER_SUITE_TERMINAL = 0x00000010;

        public const uint VER_SUITE_SMALLBUSINESS_RESTRICTED = 0x00000020;

        public const uint VER_SUITE_EMBEDDEDNT = 0x00000040;

        public const uint VER_SUITE_DATACENTER = 0x00000080;

        public const uint VER_SUITE_SINGLEUSERTS = 0x00000100;

        public const uint VER_SUITE_PERSONAL = 0x00000200;

        public const uint VER_SUITE_BLADE = 0x00000400;

        public const uint VER_SUITE_EMBEDDED_RESTRICTED = 0x00000800;

        public const uint VER_SUITE_SECURITY_APPLIANCE = 0x00001000;

        public const uint VER_SUITE_STORAGE_SERVER = 0x00002000;

        public const uint VER_SUITE_COMPUTE_SERVER = 0x00004000;

        public const uint VER_SUITE_WH_SERVER = 0x00008000;

        public const uint VER_SUITE_MULTIUSERTS = 0x00020000;

        public const uint PRODUCT_STANDARD_SERVER_CORE = 0x0000000D;

        public const uint PRODUCT_SOLUTION_EMBEDDEDSERVER_CORE = 0x00000039;

        public const uint PRODUCT_PROFESSIONAL_EMBEDDED = 0x0000003A;

        public const uint PRODUCT_EMBEDDED = 0x00000041;

        public const uint PRODUCT_EMBEDDED_AUTOMOTIVE = 0x00000055;

        public const uint PRODUCT_EMBEDDED_INDUSTRY_A = 0x00000056;

        public const uint PRODUCT_THINPC = 0x00000057;

        public const uint PRODUCT_EMBEDDED_A = 0x00000058;

        public const uint PRODUCT_EMBEDDED_INDUSTRY = 0x00000059;

        public const uint PRODUCT_EMBEDDED_E = 0x0000005A;

        public const uint PRODUCT_EMBEDDED_INDUSTRY_E = 0x0000005B;

        public const uint PRODUCT_EMBEDDED_INDUSTRY_A_E = 0x0000005C;

        public const uint PRODUCT_CORE_ARM = 0x00000061;

        public const uint PRODUCT_EMBEDDED_INDUSTRY_EVAL = 0x00000069;

        public const uint PRODUCT_EMBEDDED_INDUSTRY_E_EVAL = 0x0000006A;

        public const uint PRODUCT_EMBEDDED_EVAL = 0x0000006B;

        public const uint PRODUCT_EMBEDDED_E_EVAL = 0x0000006C;

        public const uint PRODUCT_NANO_SERVER = 0x0000006D;

        public const uint PRODUCT_CLOUD_STORAGE_SERVER = 0x0000006E;

        public const uint PRODUCT_CORE_CONNECTED = 0x0000006F;

        public const uint PRODUCT_PROFESSIONAL_STUDENT = 0x00000070;

        public const uint PRODUCT_CORE_CONNECTED_N = 0x00000071;

        public const uint PRODUCT_PROFESSIONAL_STUDENT_N = 0x00000072;

        public const uint PRODUCT_CORE_CONNECTED_SINGLELANGUAGE = 0x00000073;

        public const uint PRODUCT_CORE_CONNECTED_COUNTRYSPECIFIC = 0x00000074;

        public const uint PRODUCT_CONNECTED_CAR = 0x00000075;

        public const uint PRODUCT_INDUSTRY_HANDHELD = 0x00000076;

        public const uint PRODUCT_PPI_PRO = 0x00000077;

        public const uint PRODUCT_ARM64_SERVER = 0x00000078;

        public const uint PRODUCT_CLOUD_HOST_INFRASTRUCTURE_SERVER = 0x0000007C;

        public const uint PRODUCT_PROFESSIONAL_S = 0x0000007F;

        public const uint PRODUCT_PROFESSIONAL_S_N = 0x00000080;

        public const uint PRODUCT_HOLOGRAPHIC = 0x00000087;

        public const uint PRODUCT_HOLOGRAPHIC_BUSINESS = 0x00000088;

        public const uint PRODUCT_PRO_SINGLE_LANGUAGE = 0x0000008A;

        public const uint PRODUCT_PRO_CHINA = 0x0000008B;

        public const uint PRODUCT_ENTERPRISE_SUBSCRIPTION = 0x0000008C;

        public const uint PRODUCT_ENTERPRISE_SUBSCRIPTION_N = 0x0000008D;

        public const uint PRODUCT_DATACENTER_NANO_SERVER = 0x0000008F;

        public const uint PRODUCT_STANDARD_NANO_SERVER = 0x00000090;

        public const uint PRODUCT_DATACENTER_WS_SERVER_CORE = 0x00000093;

        public const uint PRODUCT_STANDARD_WS_SERVER_CORE = 0x00000094;

        public const uint PRODUCT_UTILITY_VM = 0x00000095;

        public const uint PRODUCT_DATACENTER_EVALUATION_SERVER_CORE = 0x0000009F;

        public const uint PRODUCT_STANDARD_EVALUATION_SERVER_CORE = 0x000000A0;

        public const uint PRODUCT_PRO_FOR_EDUCATION = 0x000000A4;

        public const uint PRODUCT_PRO_FOR_EDUCATION_N = 0x000000A5;

        public const uint PRODUCT_AZURE_SERVER_CORE = 0x000000A8;

        public const uint PRODUCT_AZURE_NANO_SERVER = 0x000000A9;

        public const uint PRODUCT_ENTERPRISEG = 0x000000AB;

        public const uint PRODUCT_ENTERPRISEGN = 0x000000AC;

        public const uint PRODUCT_SERVERRDSH = 0x000000AF;

        public const uint PRODUCT_CLOUD = 0x000000B2;

        public const uint PRODUCT_CLOUDN = 0x000000B3;

        public const uint PRODUCT_HUBOS = 0x000000B4;

        public const uint PRODUCT_ONECOREUPDATEOS = 0x000000B6;

        public const uint PRODUCT_CLOUDE = 0x000000B7;

        public const uint PRODUCT_ANDROMEDA = 0x000000B8;

        public const uint PRODUCT_IOTOS = 0x000000B9;

        public const uint PRODUCT_CLOUDEN = 0x000000BA;

        public const uint PRODUCT_IOTEDGEOS = 0x000000BB;

        public const uint PRODUCT_IOTENTERPRISE = 0x000000BC;

        public const uint PRODUCT_LITE = 0x000000BD;

        public const uint PRODUCT_IOTENTERPRISES = 0x000000BF;

        public const uint PRODUCT_XBOX_SYSTEMOS = 0x000000C0;

        public const uint PRODUCT_XBOX_NATIVEOS = 0x000000C1;

        public const uint PRODUCT_XBOX_GAMEOS = 0x000000C2;

        public const uint PRODUCT_XBOX_ERAOS = 0x000000C3;

        public const uint PRODUCT_XBOX_DURANGOHOSTOS = 0x000000C4;

        public const uint PRODUCT_XBOX_SCARLETTHOSTOS = 0x000000C5;

        public const uint PRODUCT_UNLICENSED = 0xABCDABCD;

        public const uint LANG_NEUTRAL = 0x00;

        public const uint LANG_INVARIANT = 0x7f;

        public const uint LANG_AFRIKAANS = 0x36;

        public const uint LANG_ALBANIAN = 0x1c;

        public const uint LANG_ALSATIAN = 0x84;

        public const uint LANG_AMHARIC = 0x5e;

        public const uint LANG_ARABIC = 0x01;

        public const uint LANG_ARMENIAN = 0x2b;

        public const uint LANG_ASSAMESE = 0x4d;

        public const uint LANG_AZERI = 0x2c;

        public const uint LANG_AZERBAIJANI = 0x2c;

        public const uint LANG_BANGLA = 0x45;

        public const uint LANG_BASHKIR = 0x6d;

        public const uint LANG_BASQUE = 0x2d;

        public const uint LANG_BELARUSIAN = 0x23;

        public const uint LANG_BENGALI = 0x45;

        public const uint LANG_BRETON = 0x7e;

        public const uint LANG_BOSNIAN = 0x1a;

        public const uint LANG_BOSNIAN_NEUTRAL = 0x781a;

        public const uint LANG_BULGARIAN = 0x02;

        public const uint LANG_CATALAN = 0x03;

        public const uint LANG_CENTRAL_KURDISH = 0x92;

        public const uint LANG_CHEROKEE = 0x5c;

        public const uint LANG_CHINESE = 0x04;

        public const uint LANG_CHINESE_SIMPLIFIED = 0x04;

        public const uint LANG_CHINESE_TRADITIONAL = 0x7c04;

        public const uint LANG_CORSICAN = 0x83;

        public const uint LANG_CROATIAN = 0x1a;

        public const uint LANG_CZECH = 0x05;

        public const uint LANG_DANISH = 0x06;

        public const uint LANG_DARI = 0x8c;

        public const uint LANG_DIVEHI = 0x65;

        public const uint LANG_DUTCH = 0x13;

        public const uint LANG_ENGLISH = 0x09;

        public const uint LANG_ESTONIAN = 0x25;

        public const uint LANG_FAEROESE = 0x38;

        public const uint LANG_FARSI = 0x29;

        public const uint LANG_FILIPINO = 0x64;

        public const uint LANG_FINNISH = 0x0b;

        public const uint LANG_FRENCH = 0x0c;

        public const uint LANG_FRISIAN = 0x62;

        public const uint LANG_FULAH = 0x67;

        public const uint LANG_GALICIAN = 0x56;

        public const uint LANG_GEORGIAN = 0x37;

        public const uint LANG_GERMAN = 0x07;

        public const uint LANG_GREEK = 0x08;

        public const uint LANG_GREENLANDIC = 0x6f;

        public const uint LANG_GUJARATI = 0x47;

        public const uint LANG_HAUSA = 0x68;

        public const uint LANG_HAWAIIAN = 0x75;

        public const uint LANG_HEBREW = 0x0d;

        public const uint LANG_HINDI = 0x39;

        public const uint LANG_HUNGARIAN = 0x0e;

        public const uint LANG_ICELANDIC = 0x0f;

        public const uint LANG_IGBO = 0x70;

        public const uint LANG_INDONESIAN = 0x21;

        public const uint LANG_INUKTITUT = 0x5d;

        public const uint LANG_IRISH = 0x3c;

        public const uint LANG_ITALIAN = 0x10;

        public const uint LANG_JAPANESE = 0x11;

        public const uint LANG_KANNADA = 0x4b;

        public const uint LANG_KASHMIRI = 0x60;

        public const uint LANG_KAZAK = 0x3f;

        public const uint LANG_KHMER = 0x53;

        public const uint LANG_KICHE = 0x86;

        public const uint LANG_KINYARWANDA = 0x87;

        public const uint LANG_KONKANI = 0x57;

        public const uint LANG_KOREAN = 0x12;

        public const uint LANG_KYRGYZ = 0x40;

        public const uint LANG_LAO = 0x54;

        public const uint LANG_LATVIAN = 0x26;

        public const uint LANG_LITHUANIAN = 0x27;

        public const uint LANG_LOWER_SORBIAN = 0x2e;

        public const uint LANG_LUXEMBOURGISH = 0x6e;

        public const uint LANG_MACEDONIAN = 0x2f;

        public const uint LANG_MALAY = 0x3e;

        public const uint LANG_MALAYALAM = 0x4c;

        public const uint LANG_MALTESE = 0x3a;

        public const uint LANG_MANIPURI = 0x58;

        public const uint LANG_MAORI = 0x81;

        public const uint LANG_MAPUDUNGUN = 0x7a;

        public const uint LANG_MARATHI = 0x4e;

        public const uint LANG_MOHAWK = 0x7c;

        public const uint LANG_MONGOLIAN = 0x50;

        public const uint LANG_NEPALI = 0x61;

        public const uint LANG_NORWEGIAN = 0x14;

        public const uint LANG_OCCITAN = 0x82;

        public const uint LANG_ODIA = 0x48;

        public const uint LANG_ORIYA = 0x48;

        public const uint LANG_PASHTO = 0x63;

        public const uint LANG_PERSIAN = 0x29;

        public const uint LANG_POLISH = 0x15;

        public const uint LANG_PORTUGUESE = 0x16;

        public const uint LANG_PULAR = 0x67;

        public const uint LANG_PUNJABI = 0x46;

        public const uint LANG_QUECHUA = 0x6b;

        public const uint LANG_ROMANIAN = 0x18;

        public const uint LANG_ROMANSH = 0x17;

        public const uint LANG_RUSSIAN = 0x19;

        public const uint LANG_SAKHA = 0x85;

        public const uint LANG_SAMI = 0x3b;

        public const uint LANG_SANSKRIT = 0x4f;

        public const uint LANG_SCOTTISH_GAELIC = 0x91;

        public const uint LANG_SERBIAN = 0x1a;

        public const uint LANG_SERBIAN_NEUTRAL = 0x7c1a;

        public const uint LANG_SINDHI = 0x59;

        public const uint LANG_SINHALESE = 0x5b;

        public const uint LANG_SLOVAK = 0x1b;

        public const uint LANG_SLOVENIAN = 0x24;

        public const uint LANG_SOTHO = 0x6c;

        public const uint LANG_SPANISH = 0x0a;

        public const uint LANG_SWAHILI = 0x41;

        public const uint LANG_SWEDISH = 0x1d;

        public const uint LANG_SYRIAC = 0x5a;

        public const uint LANG_TAJIK = 0x28;

        public const uint LANG_TAMAZIGHT = 0x5f;

        public const uint LANG_TAMIL = 0x49;

        public const uint LANG_TATAR = 0x44;

        public const uint LANG_TELUGU = 0x4a;

        public const uint LANG_THAI = 0x1e;

        public const uint LANG_TIBETAN = 0x51;

        public const uint LANG_TIGRIGNA = 0x73;

        public const uint LANG_TIGRINYA = 0x73;

        public const uint LANG_TSWANA = 0x32;

        public const uint LANG_TURKISH = 0x1f;

        public const uint LANG_TURKMEN = 0x42;

        public const uint LANG_UIGHUR = 0x80;

        public const uint LANG_UKRAINIAN = 0x22;

        public const uint LANG_UPPER_SORBIAN = 0x2e;

        public const uint LANG_URDU = 0x20;

        public const uint LANG_UZBEK = 0x43;

        public const uint LANG_VALENCIAN = 0x03;

        public const uint LANG_VIETNAMESE = 0x2a;

        public const uint LANG_WELSH = 0x52;

        public const uint LANG_WOLOF = 0x88;

        public const uint LANG_XHOSA = 0x34;

        public const uint LANG_YAKUT = 0x85;

        public const uint LANG_YI = 0x78;

        public const uint LANG_YORUBA = 0x6a;

        public const uint LANG_ZULU = 0x35;

        public const uint SUBLANG_NEUTRAL = 0x00;

        public const uint SUBLANG_DEFAULT = 0x01;

        public const uint SUBLANG_SYS_DEFAULT = 0x02;

        public const uint SUBLANG_CUSTOM_DEFAULT = 0x03;

        public const uint SUBLANG_CUSTOM_UNSPECIFIED = 0x04;

        public const uint SUBLANG_UI_CUSTOM_DEFAULT = 0x05;

        public const uint SUBLANG_AFRIKAANS_SOUTH_AFRICA = 0x01;

        public const uint SUBLANG_ALBANIAN_ALBANIA = 0x01;

        public const uint SUBLANG_ALSATIAN_FRANCE = 0x01;

        public const uint SUBLANG_AMHARIC_ETHIOPIA = 0x01;

        public const uint SUBLANG_ARABIC_SAUDI_ARABIA = 0x01;

        public const uint SUBLANG_ARABIC_IRAQ = 0x02;

        public const uint SUBLANG_ARABIC_EGYPT = 0x03;

        public const uint SUBLANG_ARABIC_LIBYA = 0x04;

        public const uint SUBLANG_ARABIC_ALGERIA = 0x05;

        public const uint SUBLANG_ARABIC_MOROCCO = 0x06;

        public const uint SUBLANG_ARABIC_TUNISIA = 0x07;

        public const uint SUBLANG_ARABIC_OMAN = 0x08;

        public const uint SUBLANG_ARABIC_YEMEN = 0x09;

        public const uint SUBLANG_ARABIC_SYRIA = 0x0a;

        public const uint SUBLANG_ARABIC_JORDAN = 0x0b;

        public const uint SUBLANG_ARABIC_LEBANON = 0x0c;

        public const uint SUBLANG_ARABIC_KUWAIT = 0x0d;

        public const uint SUBLANG_ARABIC_UAE = 0x0e;

        public const uint SUBLANG_ARABIC_BAHRAIN = 0x0f;

        public const uint SUBLANG_ARABIC_QATAR = 0x10;

        public const uint SUBLANG_ARMENIAN_ARMENIA = 0x01;

        public const uint SUBLANG_ASSAMESE_INDIA = 0x01;

        public const uint SUBLANG_AZERI_LATIN = 0x01;

        public const uint SUBLANG_AZERI_CYRILLIC = 0x02;

        public const uint SUBLANG_AZERBAIJANI_AZERBAIJAN_LATIN = 0x01;

        public const uint SUBLANG_AZERBAIJANI_AZERBAIJAN_CYRILLIC = 0x02;

        public const uint SUBLANG_BANGLA_INDIA = 0x01;

        public const uint SUBLANG_BANGLA_BANGLADESH = 0x02;

        public const uint SUBLANG_BASHKIR_RUSSIA = 0x01;

        public const uint SUBLANG_BASQUE_BASQUE = 0x01;

        public const uint SUBLANG_BELARUSIAN_BELARUS = 0x01;

        public const uint SUBLANG_BENGALI_INDIA = 0x01;

        public const uint SUBLANG_BENGALI_BANGLADESH = 0x02;

        public const uint SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_LATIN = 0x05;

        public const uint SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_CYRILLIC = 0x08;

        public const uint SUBLANG_BRETON_FRANCE = 0x01;

        public const uint SUBLANG_BULGARIAN_BULGARIA = 0x01;

        public const uint SUBLANG_CATALAN_CATALAN = 0x01;

        public const uint SUBLANG_CENTRAL_KURDISH_IRAQ = 0x01;

        public const uint SUBLANG_CHEROKEE_CHEROKEE = 0x01;

        public const uint SUBLANG_CHINESE_TRADITIONAL = 0x01;

        public const uint SUBLANG_CHINESE_SIMPLIFIED = 0x02;

        public const uint SUBLANG_CHINESE_HONGKONG = 0x03;

        public const uint SUBLANG_CHINESE_SINGAPORE = 0x04;

        public const uint SUBLANG_CHINESE_MACAU = 0x05;

        public const uint SUBLANG_CORSICAN_FRANCE = 0x01;

        public const uint SUBLANG_CZECH_CZECH_REPUBLIC = 0x01;

        public const uint SUBLANG_CROATIAN_CROATIA = 0x01;

        public const uint SUBLANG_CROATIAN_BOSNIA_HERZEGOVINA_LATIN = 0x04;

        public const uint SUBLANG_DANISH_DENMARK = 0x01;

        public const uint SUBLANG_DARI_AFGHANISTAN = 0x01;

        public const uint SUBLANG_DIVEHI_MALDIVES = 0x01;

        public const uint SUBLANG_DUTCH = 0x01;

        public const uint SUBLANG_DUTCH_BELGIAN = 0x02;

        public const uint SUBLANG_ENGLISH_US = 0x01;

        public const uint SUBLANG_ENGLISH_UK = 0x02;

        public const uint SUBLANG_ENGLISH_AUS = 0x03;

        public const uint SUBLANG_ENGLISH_CAN = 0x04;

        public const uint SUBLANG_ENGLISH_NZ = 0x05;

        public const uint SUBLANG_ENGLISH_EIRE = 0x06;

        public const uint SUBLANG_ENGLISH_SOUTH_AFRICA = 0x07;

        public const uint SUBLANG_ENGLISH_JAMAICA = 0x08;

        public const uint SUBLANG_ENGLISH_CARIBBEAN = 0x09;

        public const uint SUBLANG_ENGLISH_BELIZE = 0x0a;

        public const uint SUBLANG_ENGLISH_TRINIDAD = 0x0b;

        public const uint SUBLANG_ENGLISH_ZIMBABWE = 0x0c;

        public const uint SUBLANG_ENGLISH_PHILIPPINES = 0x0d;

        public const uint SUBLANG_ENGLISH_INDIA = 0x10;

        public const uint SUBLANG_ENGLISH_MALAYSIA = 0x11;

        public const uint SUBLANG_ENGLISH_SINGAPORE = 0x12;

        public const uint SUBLANG_ESTONIAN_ESTONIA = 0x01;

        public const uint SUBLANG_FAEROESE_FAROE_ISLANDS = 0x01;

        public const uint SUBLANG_FILIPINO_PHILIPPINES = 0x01;

        public const uint SUBLANG_FINNISH_FINLAND = 0x01;

        public const uint SUBLANG_FRENCH = 0x01;

        public const uint SUBLANG_FRENCH_BELGIAN = 0x02;

        public const uint SUBLANG_FRENCH_CANADIAN = 0x03;

        public const uint SUBLANG_FRENCH_SWISS = 0x04;

        public const uint SUBLANG_FRENCH_LUXEMBOURG = 0x05;

        public const uint SUBLANG_FRENCH_MONACO = 0x06;

        public const uint SUBLANG_FRISIAN_NETHERLANDS = 0x01;

        public const uint SUBLANG_FULAH_SENEGAL = 0x02;

        public const uint SUBLANG_GALICIAN_GALICIAN = 0x01;

        public const uint SUBLANG_GEORGIAN_GEORGIA = 0x01;

        public const uint SUBLANG_GERMAN = 0x01;

        public const uint SUBLANG_GERMAN_SWISS = 0x02;

        public const uint SUBLANG_GERMAN_AUSTRIAN = 0x03;

        public const uint SUBLANG_GERMAN_LUXEMBOURG = 0x04;

        public const uint SUBLANG_GERMAN_LIECHTENSTEIN = 0x05;

        public const uint SUBLANG_GREEK_GREECE = 0x01;

        public const uint SUBLANG_GREENLANDIC_GREENLAND = 0x01;

        public const uint SUBLANG_GUJARATI_INDIA = 0x01;

        public const uint SUBLANG_HAUSA_NIGERIA_LATIN = 0x01;

        public const uint SUBLANG_HAWAIIAN_US = 0x01;

        public const uint SUBLANG_HEBREW_ISRAEL = 0x01;

        public const uint SUBLANG_HINDI_INDIA = 0x01;

        public const uint SUBLANG_HUNGARIAN_HUNGARY = 0x01;

        public const uint SUBLANG_ICELANDIC_ICELAND = 0x01;

        public const uint SUBLANG_IGBO_NIGERIA = 0x01;

        public const uint SUBLANG_INDONESIAN_INDONESIA = 0x01;

        public const uint SUBLANG_INUKTITUT_CANADA = 0x01;

        public const uint SUBLANG_INUKTITUT_CANADA_LATIN = 0x02;

        public const uint SUBLANG_IRISH_IRELAND = 0x02;

        public const uint SUBLANG_ITALIAN = 0x01;

        public const uint SUBLANG_ITALIAN_SWISS = 0x02;

        public const uint SUBLANG_JAPANESE_JAPAN = 0x01;

        public const uint SUBLANG_KANNADA_INDIA = 0x01;

        public const uint SUBLANG_KASHMIRI_SASIA = 0x02;

        public const uint SUBLANG_KASHMIRI_INDIA = 0x02;

        public const uint SUBLANG_KAZAK_KAZAKHSTAN = 0x01;

        public const uint SUBLANG_KHMER_CAMBODIA = 0x01;

        public const uint SUBLANG_KICHE_GUATEMALA = 0x01;

        public const uint SUBLANG_KINYARWANDA_RWANDA = 0x01;

        public const uint SUBLANG_KONKANI_INDIA = 0x01;

        public const uint SUBLANG_KOREAN = 0x01;

        public const uint SUBLANG_KYRGYZ_KYRGYZSTAN = 0x01;

        public const uint SUBLANG_LAO_LAO = 0x01;

        public const uint SUBLANG_LATVIAN_LATVIA = 0x01;

        public const uint SUBLANG_LITHUANIAN = 0x01;

        public const uint SUBLANG_LOWER_SORBIAN_GERMANY = 0x02;

        public const uint SUBLANG_LUXEMBOURGISH_LUXEMBOURG = 0x01;

        public const uint SUBLANG_MACEDONIAN_MACEDONIA = 0x01;

        public const uint SUBLANG_MALAY_MALAYSIA = 0x01;

        public const uint SUBLANG_MALAY_BRUNEI_DARUSSALAM = 0x02;

        public const uint SUBLANG_MALAYALAM_INDIA = 0x01;

        public const uint SUBLANG_MALTESE_MALTA = 0x01;

        public const uint SUBLANG_MAORI_NEW_ZEALAND = 0x01;

        public const uint SUBLANG_MAPUDUNGUN_CHILE = 0x01;

        public const uint SUBLANG_MARATHI_INDIA = 0x01;

        public const uint SUBLANG_MOHAWK_MOHAWK = 0x01;

        public const uint SUBLANG_MONGOLIAN_CYRILLIC_MONGOLIA = 0x01;

        public const uint SUBLANG_MONGOLIAN_PRC = 0x02;

        public const uint SUBLANG_NEPALI_INDIA = 0x02;

        public const uint SUBLANG_NEPALI_NEPAL = 0x01;

        public const uint SUBLANG_NORWEGIAN_BOKMAL = 0x01;

        public const uint SUBLANG_NORWEGIAN_NYNORSK = 0x02;

        public const uint SUBLANG_OCCITAN_FRANCE = 0x01;

        public const uint SUBLANG_ODIA_INDIA = 0x01;

        public const uint SUBLANG_ORIYA_INDIA = 0x01;

        public const uint SUBLANG_PASHTO_AFGHANISTAN = 0x01;

        public const uint SUBLANG_PERSIAN_IRAN = 0x01;

        public const uint SUBLANG_POLISH_POLAND = 0x01;

        public const uint SUBLANG_PORTUGUESE = 0x02;

        public const uint SUBLANG_PORTUGUESE_BRAZILIAN = 0x01;

        public const uint SUBLANG_PULAR_SENEGAL = 0x02;

        public const uint SUBLANG_PUNJABI_INDIA = 0x01;

        public const uint SUBLANG_PUNJABI_PAKISTAN = 0x02;

        public const uint SUBLANG_QUECHUA_BOLIVIA = 0x01;

        public const uint SUBLANG_QUECHUA_ECUADOR = 0x02;

        public const uint SUBLANG_QUECHUA_PERU = 0x03;

        public const uint SUBLANG_ROMANIAN_ROMANIA = 0x01;

        public const uint SUBLANG_ROMANSH_SWITZERLAND = 0x01;

        public const uint SUBLANG_RUSSIAN_RUSSIA = 0x01;

        public const uint SUBLANG_SAKHA_RUSSIA = 0x01;

        public const uint SUBLANG_SAMI_NORTHERN_NORWAY = 0x01;

        public const uint SUBLANG_SAMI_NORTHERN_SWEDEN = 0x02;

        public const uint SUBLANG_SAMI_NORTHERN_FINLAND = 0x03;

        public const uint SUBLANG_SAMI_LULE_NORWAY = 0x04;

        public const uint SUBLANG_SAMI_LULE_SWEDEN = 0x05;

        public const uint SUBLANG_SAMI_SOUTHERN_NORWAY = 0x06;

        public const uint SUBLANG_SAMI_SOUTHERN_SWEDEN = 0x07;

        public const uint SUBLANG_SAMI_SKOLT_FINLAND = 0x08;

        public const uint SUBLANG_SAMI_INARI_FINLAND = 0x09;

        public const uint SUBLANG_SANSKRIT_INDIA = 0x01;

        public const uint SUBLANG_SCOTTISH_GAELIC = 0x01;

        public const uint SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_LATIN = 0x06;

        public const uint SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_CYRILLIC = 0x07;

        public const uint SUBLANG_SERBIAN_MONTENEGRO_LATIN = 0x0b;

        public const uint SUBLANG_SERBIAN_MONTENEGRO_CYRILLIC = 0x0c;

        public const uint SUBLANG_SERBIAN_SERBIA_LATIN = 0x09;

        public const uint SUBLANG_SERBIAN_SERBIA_CYRILLIC = 0x0a;

        public const uint SUBLANG_SERBIAN_CROATIA = 0x01;

        public const uint SUBLANG_SERBIAN_LATIN = 0x02;

        public const uint SUBLANG_SERBIAN_CYRILLIC = 0x03;

        public const uint SUBLANG_SINDHI_INDIA = 0x01;

        public const uint SUBLANG_SINDHI_PAKISTAN = 0x02;

        public const uint SUBLANG_SINDHI_AFGHANISTAN = 0x02;

        public const uint SUBLANG_SINHALESE_SRI_LANKA = 0x01;

        public const uint SUBLANG_SOTHO_NORTHERN_SOUTH_AFRICA = 0x01;

        public const uint SUBLANG_SLOVAK_SLOVAKIA = 0x01;

        public const uint SUBLANG_SLOVENIAN_SLOVENIA = 0x01;

        public const uint SUBLANG_SPANISH = 0x01;

        public const uint SUBLANG_SPANISH_MEXICAN = 0x02;

        public const uint SUBLANG_SPANISH_MODERN = 0x03;

        public const uint SUBLANG_SPANISH_GUATEMALA = 0x04;

        public const uint SUBLANG_SPANISH_COSTA_RICA = 0x05;

        public const uint SUBLANG_SPANISH_PANAMA = 0x06;

        public const uint SUBLANG_SPANISH_DOMINICAN_REPUBLIC = 0x07;

        public const uint SUBLANG_SPANISH_VENEZUELA = 0x08;

        public const uint SUBLANG_SPANISH_COLOMBIA = 0x09;

        public const uint SUBLANG_SPANISH_PERU = 0x0a;

        public const uint SUBLANG_SPANISH_ARGENTINA = 0x0b;

        public const uint SUBLANG_SPANISH_ECUADOR = 0x0c;

        public const uint SUBLANG_SPANISH_CHILE = 0x0d;

        public const uint SUBLANG_SPANISH_URUGUAY = 0x0e;

        public const uint SUBLANG_SPANISH_PARAGUAY = 0x0f;

        public const uint SUBLANG_SPANISH_BOLIVIA = 0x10;

        public const uint SUBLANG_SPANISH_EL_SALVADOR = 0x11;

        public const uint SUBLANG_SPANISH_HONDURAS = 0x12;

        public const uint SUBLANG_SPANISH_NICARAGUA = 0x13;

        public const uint SUBLANG_SPANISH_PUERTO_RICO = 0x14;

        public const uint SUBLANG_SPANISH_US = 0x15;

        public const uint SUBLANG_SWAHILI_KENYA = 0x01;

        public const uint SUBLANG_SWEDISH = 0x01;

        public const uint SUBLANG_SWEDISH_FINLAND = 0x02;

        public const uint SUBLANG_SYRIAC_SYRIA = 0x01;

        public const uint SUBLANG_TAJIK_TAJIKISTAN = 0x01;

        public const uint SUBLANG_TAMAZIGHT_ALGERIA_LATIN = 0x02;

        public const uint SUBLANG_TAMAZIGHT_MOROCCO_TIFINAGH = 0x04;

        public const uint SUBLANG_TAMIL_INDIA = 0x01;

        public const uint SUBLANG_TAMIL_SRI_LANKA = 0x02;

        public const uint SUBLANG_TATAR_RUSSIA = 0x01;

        public const uint SUBLANG_TELUGU_INDIA = 0x01;

        public const uint SUBLANG_THAI_THAILAND = 0x01;

        public const uint SUBLANG_TIBETAN_PRC = 0x01;

        public const uint SUBLANG_TIGRIGNA_ERITREA = 0x02;

        public const uint SUBLANG_TIGRINYA_ERITREA = 0x02;

        public const uint SUBLANG_TIGRINYA_ETHIOPIA = 0x01;

        public const uint SUBLANG_TSWANA_BOTSWANA = 0x02;

        public const uint SUBLANG_TSWANA_SOUTH_AFRICA = 0x01;

        public const uint SUBLANG_TURKISH_TURKEY = 0x01;

        public const uint SUBLANG_TURKMEN_TURKMENISTAN = 0x01;

        public const uint SUBLANG_UIGHUR_PRC = 0x01;

        public const uint SUBLANG_UKRAINIAN_UKRAINE = 0x01;

        public const uint SUBLANG_UPPER_SORBIAN_GERMANY = 0x01;

        public const uint SUBLANG_URDU_PAKISTAN = 0x01;

        public const uint SUBLANG_URDU_INDIA = 0x02;

        public const uint SUBLANG_UZBEK_LATIN = 0x01;

        public const uint SUBLANG_UZBEK_CYRILLIC = 0x02;

        public const uint SUBLANG_VALENCIAN_VALENCIA = 0x02;

        public const uint SUBLANG_VIETNAMESE_VIETNAM = 0x01;

        public const uint SUBLANG_WELSH_UNITED_KINGDOM = 0x01;

        public const uint SUBLANG_WOLOF_SENEGAL = 0x01;

        public const uint SUBLANG_XHOSA_SOUTH_AFRICA = 0x01;

        public const uint SUBLANG_YAKUT_RUSSIA = 0x01;

        public const uint SUBLANG_YI_PRC = 0x01;

        public const uint SUBLANG_YORUBA_NIGERIA = 0x01;

        public const uint SUBLANG_ZULU_SOUTH_AFRICA = 0x01;

        public const uint SORT_DEFAULT = 0x0;

        public const uint SORT_INVARIANT_MATH = 0x1;

        public const uint SORT_JAPANESE_XJIS = 0x0;

        public const uint SORT_JAPANESE_UNICODE = 0x1;

        public const uint SORT_JAPANESE_RADICALSTROKE = 0x4;

        public const uint SORT_CHINESE_BIG5 = 0x0;

        public const uint SORT_CHINESE_PRCP = 0x0;

        public const uint SORT_CHINESE_UNICODE = 0x1;

        public const uint SORT_CHINESE_PRC = 0x2;

        public const uint SORT_CHINESE_BOPOMOFO = 0x3;

        public const uint SORT_CHINESE_RADICALSTROKE = 0x4;

        public const uint SORT_KOREAN_KSC = 0x0;

        public const uint SORT_KOREAN_UNICODE = 0x1;

        public const uint SORT_GERMAN_PHONE_BOOK = 0x1;

        public const uint SORT_HUNGARIAN_DEFAULT = 0x0;

        public const uint SORT_HUNGARIAN_TECHNICAL = 0x1;

        public const uint SORT_GEORGIAN_TRADITIONAL = 0x0;

        public const uint SORT_GEORGIAN_MODERN = 0x1;

        public const uint NLS_VALID_LOCALE_MASK = 0x000fffff;

        public const uint LOCALE_NAME_MAX_LENGTH = 85;

        public const uint LOCALE_TRANSIENT_KEYBOARD1 = 0x2000;

        public const uint LOCALE_TRANSIENT_KEYBOARD2 = 0x2400;

        public const uint LOCALE_TRANSIENT_KEYBOARD3 = 0x2800;

        public const uint LOCALE_TRANSIENT_KEYBOARD4 = 0x2c00;

        public const uint MAXIMUM_WAIT_OBJECTS = 64;

        public const uint EXCEPTION_READ_FAULT = 0;

        public const uint EXCEPTION_WRITE_FAULT = 1;

        public const uint EXCEPTION_EXECUTE_FAULT = 8;

        public const int CONTEXT_AMD64 = 0x00100000;

        public const int CONTEXT_KERNEL_DEBUGGER = 0x04000000;

        public const int CONTEXT_EXCEPTION_ACTIVE = 0x08000000;

        public const int CONTEXT_SERVICE_ACTIVE = 0x10000000;

        public const int CONTEXT_EXCEPTION_REQUEST = 0x40000000;

        public const int CONTEXT_EXCEPTION_REPORTING = unchecked((int)0x80000000);

        public const uint INITIAL_MXCSR = 0x1f80;

        public const uint INITIAL_FPCSR = 0x027f;

        public const uint RUNTIME_FUNCTION_INDIRECT = 0x1;

        public const uint UNW_FLAG_NO_EPILOGUE = 0x80000000;

        public const uint UNWIND_CHAIN_LIMIT = 32;

        public const uint UNWIND_HISTORY_TABLE_SIZE = 12;

        public const uint PF_TEMPORAL_LEVEL_1 = 0;

        public const uint PF_TEMPORAL_LEVEL_2 = 1;

        public const uint PF_TEMPORAL_LEVEL_3 = 2;

        public const uint PF_NON_TEMPORAL_LEVEL_ALL = 3;

        public const int CONTEXT_ARM = 0x00200000;

        public const uint CONTEXT_UNWOUND_TO_CALL = 0x20000000;

        public const uint INITIAL_CPSR = 0x10;

        public const uint INITIAL_FPSCR = 0;

        public const uint ARM_MAX_BREAKPOINTS = 8;

        public const uint ARM_MAX_WATCHPOINTS = 1;

        public const int CONTEXT_ARM64 = 0x00400000;

        public const uint CONTEXT_RET_TO_GUEST = 0x04000000;

        public const uint ARM64_MAX_BREAKPOINTS = 8;

        public const uint ARM64_MAX_WATCHPOINTS = 2;

        public const uint BREAK_DEBUG_BASE = 0x080000;

        public const uint ASSERT_BREAKPOINT = BREAK_DEBUG_BASE+3;

        public const uint SIZE_OF_80387_REGISTERS = 80;

        public const int CONTEXT_i386 = 0x00010000;

        public const int CONTEXT_i486 = 0x00010000;

        public const uint MAXIMUM_SUPPORTED_EXTENSION = 512;

        public const uint EXCEPTION_NONCONTINUABLE = 0x1;

        public const uint EXCEPTION_UNWINDING = 0x2;

        public const uint EXCEPTION_EXIT_UNWIND = 0x4;

        public const uint EXCEPTION_STACK_INVALID = 0x8;

        public const uint EXCEPTION_NESTED_CALL = 0x10;

        public const uint EXCEPTION_TARGET_UNWIND = 0x20;

        public const uint EXCEPTION_COLLIDED_UNWIND = 0x40;

        public const uint EXCEPTION_MAXIMUM_PARAMETERS = 15;

        public const uint DELETE = 0x00010000;

        public const uint WRITE_DAC = 0x00040000;

        public const uint WRITE_OWNER = 0x00080000;

        public const uint ACCESS_SYSTEM_SECURITY = 0x01000000;

        public const uint MAXIMUM_ALLOWED = 0x02000000;

        public const uint GENERIC_READ = 0x80000000;

        public const uint GENERIC_WRITE = 0x40000000;

        public const uint GENERIC_EXECUTE = 0x20000000;

        public const uint GENERIC_ALL = 0x10000000;

        public const uint SID_REVISION = 1;

        public const uint SID_MAX_SUB_AUTHORITIES = 15;

        public const uint SID_RECOMMENDED_SUB_AUTHORITIES = 1;

        public const uint SID_HASH_SIZE = 32;

        public const int SECURITY_NULL_RID = 0x00000000;

        public const int SECURITY_WORLD_RID = 0x00000000;

        public const int SECURITY_LOCAL_RID = 0x00000000;

        public const int SECURITY_LOCAL_LOGON_RID = 0x00000001;

        public const int SECURITY_CREATOR_OWNER_RID = 0x00000000;

        public const int SECURITY_CREATOR_GROUP_RID = 0x00000001;

        public const int SECURITY_CREATOR_OWNER_SERVER_RID = 0x00000002;

        public const int SECURITY_CREATOR_GROUP_SERVER_RID = 0x00000003;

        public const int SECURITY_CREATOR_OWNER_RIGHTS_RID = 0x00000004;

        public const int SECURITY_DIALUP_RID = 0x00000001;

        public const int SECURITY_NETWORK_RID = 0x00000002;

        public const int SECURITY_BATCH_RID = 0x00000003;

        public const int SECURITY_INTERACTIVE_RID = 0x00000004;

        public const int SECURITY_LOGON_IDS_RID = 0x00000005;

        public const int SECURITY_LOGON_IDS_RID_COUNT = 3;

        public const int SECURITY_SERVICE_RID = 0x00000006;

        public const int SECURITY_ANONYMOUS_LOGON_RID = 0x00000007;

        public const int SECURITY_PROXY_RID = 0x00000008;

        public const int SECURITY_ENTERPRISE_CONTROLLERS_RID = 0x00000009;

        public const int SECURITY_PRINCIPAL_SELF_RID = 0x0000000A;

        public const int SECURITY_AUTHENTICATED_USER_RID = 0x0000000B;

        public const int SECURITY_RESTRICTED_CODE_RID = 0x0000000C;

        public const int SECURITY_TERMINAL_SERVER_RID = 0x0000000D;

        public const int SECURITY_REMOTE_LOGON_RID = 0x0000000E;

        public const int SECURITY_THIS_ORGANIZATION_RID = 0x0000000F;

        public const int SECURITY_IUSER_RID = 0x00000011;

        public const int SECURITY_LOCAL_SYSTEM_RID = 0x00000012;

        public const int SECURITY_LOCAL_SERVICE_RID = 0x00000013;

        public const int SECURITY_NETWORK_SERVICE_RID = 0x00000014;

        public const int SECURITY_NT_NON_UNIQUE = 0x00000015;

        public const int SECURITY_NT_NON_UNIQUE_SUB_AUTH_COUNT = 3;

        public const int SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID = 0x00000016;

        public const int SECURITY_BUILTIN_DOMAIN_RID = 0x00000020;

        public const int SECURITY_WRITE_RESTRICTED_CODE_RID = 0x00000021;

        public const int SECURITY_PACKAGE_BASE_RID = 0x00000040;

        public const int SECURITY_PACKAGE_RID_COUNT = 2;

        public const int SECURITY_PACKAGE_NTLM_RID = 0x0000000A;

        public const int SECURITY_PACKAGE_SCHANNEL_RID = 0x0000000E;

        public const int SECURITY_PACKAGE_DIGEST_RID = 0x00000015;

        public const int SECURITY_CRED_TYPE_BASE_RID = 0x00000041;

        public const int SECURITY_CRED_TYPE_RID_COUNT = 2;

        public const int SECURITY_CRED_TYPE_THIS_ORG_CERT_RID = 0x00000001;

        public const int SECURITY_MIN_BASE_RID = 0x00000050;

        public const int SECURITY_SERVICE_ID_BASE_RID = 0x00000050;

        public const int SECURITY_SERVICE_ID_RID_COUNT = 6;

        public const int SECURITY_RESERVED_ID_BASE_RID = 0x00000051;

        public const int SECURITY_APPPOOL_ID_BASE_RID = 0x00000052;

        public const int SECURITY_APPPOOL_ID_RID_COUNT = 6;

        public const int SECURITY_VIRTUALSERVER_ID_BASE_RID = 0x00000053;

        public const int SECURITY_VIRTUALSERVER_ID_RID_COUNT = 6;

        public const int SECURITY_USERMODEDRIVERHOST_ID_BASE_RID = 0x00000054;

        public const int SECURITY_USERMODEDRIVERHOST_ID_RID_COUNT = 6;

        public const int SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_BASE_RID = 0x00000055;

        public const int SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_RID_COUNT = 6;

        public const int SECURITY_WMIHOST_ID_BASE_RID = 0x00000056;

        public const int SECURITY_WMIHOST_ID_RID_COUNT = 6;

        public const int SECURITY_TASK_ID_BASE_RID = 0x00000057;

        public const int SECURITY_NFS_ID_BASE_RID = 0x00000058;

        public const int SECURITY_COM_ID_BASE_RID = 0x00000059;

        public const int SECURITY_WINDOW_MANAGER_BASE_RID = 0x0000005A;

        public const int SECURITY_RDV_GFX_BASE_RID = 0x0000005B;

        public const int SECURITY_DASHOST_ID_BASE_RID = 0x0000005C;

        public const int SECURITY_DASHOST_ID_RID_COUNT = 6;

        public const int SECURITY_USERMANAGER_ID_BASE_RID = 0x0000005D;

        public const int SECURITY_USERMANAGER_ID_RID_COUNT = 6;

        public const int SECURITY_WINRM_ID_BASE_RID = 0x0000005E;

        public const int SECURITY_WINRM_ID_RID_COUNT = 6;

        public const int SECURITY_CCG_ID_BASE_RID = 0x0000005F;

        public const int SECURITY_UMFD_BASE_RID = 0x00000060;

        public const int SECURITY_VIRTUALACCOUNT_ID_RID_COUNT = 6;

        public const int SECURITY_MAX_BASE_RID = 0x0000006F;

        public const int SECURITY_MAX_ALWAYS_FILTERED = 0x000003E7;

        public const int SECURITY_MIN_NEVER_FILTERED = 0x000003E8;

        public const int SECURITY_OTHER_ORGANIZATION_RID = 0x000003E8;

        public const int SECURITY_WINDOWSMOBILE_ID_BASE_RID = 0x00000070;

        public const uint SECURITY_INSTALLER_GROUP_CAPABILITY_BASE = 0x20;

        public const uint SECURITY_INSTALLER_GROUP_CAPABILITY_RID_COUNT = 9;

        public const uint SECURITY_INSTALLER_CAPABILITY_RID_COUNT = 10;

        public const int SECURITY_LOCAL_ACCOUNT_RID = 0x00000071;

        public const int SECURITY_LOCAL_ACCOUNT_AND_ADMIN_RID = 0x00000072;

        public const int DOMAIN_GROUP_RID_AUTHORIZATION_DATA_IS_COMPOUNDED = 0x000001F0;

        public const int DOMAIN_GROUP_RID_AUTHORIZATION_DATA_CONTAINS_CLAIMS = 0x000001F1;

        public const int DOMAIN_GROUP_RID_ENTERPRISE_READONLY_DOMAIN_CONTROLLERS = 0x000001F2;

        public const int FOREST_USER_RID_MAX = 0x000001F3;

        public const int DOMAIN_USER_RID_ADMIN = 0x000001F4;

        public const int DOMAIN_USER_RID_GUEST = 0x000001F5;

        public const int DOMAIN_USER_RID_KRBTGT = 0x000001F6;

        public const int DOMAIN_USER_RID_DEFAULT_ACCOUNT = 0x000001F7;

        public const int DOMAIN_USER_RID_WDAG_ACCOUNT = 0x000001F8;

        public const int DOMAIN_USER_RID_MAX = 0x000003E7;

        public const int DOMAIN_GROUP_RID_ADMINS = 0x00000200;

        public const int DOMAIN_GROUP_RID_USERS = 0x00000201;

        public const int DOMAIN_GROUP_RID_GUESTS = 0x00000202;

        public const int DOMAIN_GROUP_RID_COMPUTERS = 0x00000203;

        public const int DOMAIN_GROUP_RID_CONTROLLERS = 0x00000204;

        public const int DOMAIN_GROUP_RID_CERT_ADMINS = 0x00000205;

        public const int DOMAIN_GROUP_RID_SCHEMA_ADMINS = 0x00000206;

        public const int DOMAIN_GROUP_RID_ENTERPRISE_ADMINS = 0x00000207;

        public const int DOMAIN_GROUP_RID_POLICY_ADMINS = 0x00000208;

        public const int DOMAIN_GROUP_RID_READONLY_CONTROLLERS = 0x00000209;

        public const int DOMAIN_GROUP_RID_CLONEABLE_CONTROLLERS = 0x0000020A;

        public const int DOMAIN_GROUP_RID_CDC_RESERVED = 0x0000020C;

        public const int DOMAIN_GROUP_RID_PROTECTED_USERS = 0x0000020D;

        public const int DOMAIN_GROUP_RID_KEY_ADMINS = 0x0000020E;

        public const int DOMAIN_GROUP_RID_ENTERPRISE_KEY_ADMINS = 0x0000020F;

        public const int DOMAIN_ALIAS_RID_ADMINS = 0x00000220;

        public const int DOMAIN_ALIAS_RID_USERS = 0x00000221;

        public const int DOMAIN_ALIAS_RID_GUESTS = 0x00000222;

        public const int DOMAIN_ALIAS_RID_POWER_USERS = 0x00000223;

        public const int DOMAIN_ALIAS_RID_ACCOUNT_OPS = 0x00000224;

        public const int DOMAIN_ALIAS_RID_SYSTEM_OPS = 0x00000225;

        public const int DOMAIN_ALIAS_RID_PRINT_OPS = 0x00000226;

        public const int DOMAIN_ALIAS_RID_BACKUP_OPS = 0x00000227;

        public const int DOMAIN_ALIAS_RID_REPLICATOR = 0x00000228;

        public const int DOMAIN_ALIAS_RID_RAS_SERVERS = 0x00000229;

        public const int DOMAIN_ALIAS_RID_PREW2KCOMPACCESS = 0x0000022A;

        public const int DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS = 0x0000022B;

        public const int DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS = 0x0000022C;

        public const int DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS = 0x0000022D;

        public const int DOMAIN_ALIAS_RID_MONITORING_USERS = 0x0000022E;

        public const int DOMAIN_ALIAS_RID_LOGGING_USERS = 0x0000022F;

        public const int DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS = 0x00000230;

        public const int DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS = 0x00000231;

        public const int DOMAIN_ALIAS_RID_DCOM_USERS = 0x00000232;

        public const int DOMAIN_ALIAS_RID_IUSERS = 0x00000238;

        public const int DOMAIN_ALIAS_RID_CRYPTO_OPERATORS = 0x00000239;

        public const int DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_GROUP = 0x0000023B;

        public const int DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_GROUP = 0x0000023C;

        public const int DOMAIN_ALIAS_RID_EVENT_LOG_READERS_GROUP = 0x0000023D;

        public const int DOMAIN_ALIAS_RID_CERTSVC_DCOM_ACCESS_GROUP = 0x0000023E;

        public const int DOMAIN_ALIAS_RID_RDS_REMOTE_ACCESS_SERVERS = 0x0000023F;

        public const int DOMAIN_ALIAS_RID_RDS_ENDPOINT_SERVERS = 0x00000240;

        public const int DOMAIN_ALIAS_RID_RDS_MANAGEMENT_SERVERS = 0x00000241;

        public const int DOMAIN_ALIAS_RID_HYPER_V_ADMINS = 0x00000242;

        public const int DOMAIN_ALIAS_RID_ACCESS_CONTROL_ASSISTANCE_OPS = 0x00000243;

        public const int DOMAIN_ALIAS_RID_REMOTE_MANAGEMENT_USERS = 0x00000244;

        public const int DOMAIN_ALIAS_RID_DEFAULT_ACCOUNT = 0x00000245;

        public const int DOMAIN_ALIAS_RID_STORAGE_REPLICA_ADMINS = 0x00000246;

        public const int DOMAIN_ALIAS_RID_DEVICE_OWNERS = 0x00000247;

        public const int SECURITY_APP_PACKAGE_BASE_RID = 0x00000002;

        public const int SECURITY_BUILTIN_APP_PACKAGE_RID_COUNT = 2;

        public const int SECURITY_APP_PACKAGE_RID_COUNT = 8;

        public const int SECURITY_CAPABILITY_BASE_RID = 0x00000003;

        public const ulong SECURITY_CAPABILITY_APP_RID = 0x000000400;

        public const int SECURITY_BUILTIN_CAPABILITY_RID_COUNT = 2;

        public const int SECURITY_CAPABILITY_RID_COUNT = 5;

        public const int SECURITY_CHILD_PACKAGE_RID_COUNT = 12;

        public const int SECURITY_BUILTIN_PACKAGE_ANY_PACKAGE = 0x00000001;

        public const int SECURITY_BUILTIN_PACKAGE_ANY_RESTRICTED_PACKAGE = 0x00000002;

        public const int SECURITY_CAPABILITY_INTERNET_CLIENT = 0x00000001;

        public const int SECURITY_CAPABILITY_INTERNET_CLIENT_SERVER = 0x00000002;

        public const int SECURITY_CAPABILITY_PRIVATE_NETWORK_CLIENT_SERVER = 0x00000003;

        public const int SECURITY_CAPABILITY_PICTURES_LIBRARY = 0x00000004;

        public const int SECURITY_CAPABILITY_VIDEOS_LIBRARY = 0x00000005;

        public const int SECURITY_CAPABILITY_MUSIC_LIBRARY = 0x00000006;

        public const int SECURITY_CAPABILITY_DOCUMENTS_LIBRARY = 0x00000007;

        public const int SECURITY_CAPABILITY_ENTERPRISE_AUTHENTICATION = 0x00000008;

        public const int SECURITY_CAPABILITY_SHARED_USER_CERTIFICATES = 0x00000009;

        public const int SECURITY_CAPABILITY_REMOVABLE_STORAGE = 0x0000000A;

        public const int SECURITY_CAPABILITY_APPOINTMENTS = 0x0000000B;

        public const int SECURITY_CAPABILITY_CONTACTS = 0x0000000C;

        public const int SECURITY_CAPABILITY_INTERNET_EXPLORER = 0x00001000;

        public const int SECURITY_MANDATORY_UNTRUSTED_RID = 0x00000000;

        public const int SECURITY_MANDATORY_LOW_RID = 0x00001000;

        public const int SECURITY_MANDATORY_MEDIUM_RID = 0x00002000;

        public const uint SECURITY_MANDATORY_MEDIUM_PLUS_RID = SECURITY_MANDATORY_MEDIUM_RID + 0x100;

        public const int SECURITY_MANDATORY_HIGH_RID = 0x00003000;

        public const int SECURITY_MANDATORY_SYSTEM_RID = 0x00004000;

        public const int SECURITY_MANDATORY_PROTECTED_PROCESS_RID = 0x00005000;

        public const int SECURITY_AUTHENTICATION_AUTHORITY_RID_COUNT = 1;

        public const int SECURITY_AUTHENTICATION_AUTHORITY_ASSERTED_RID = 0x00000001;

        public const int SECURITY_AUTHENTICATION_SERVICE_ASSERTED_RID = 0x00000002;

        public const int SECURITY_AUTHENTICATION_FRESH_KEY_AUTH_RID = 0x00000003;

        public const int SECURITY_AUTHENTICATION_KEY_TRUST_RID = 0x00000004;

        public const int SECURITY_AUTHENTICATION_KEY_PROPERTY_MFA_RID = 0x00000005;

        public const int SECURITY_AUTHENTICATION_KEY_PROPERTY_ATTESTATION_RID = 0x00000006;

        public const int SECURITY_PROCESS_TRUST_AUTHORITY_RID_COUNT = 2;

        public const int SECURITY_PROCESS_PROTECTION_TYPE_FULL_RID = 0x00000400;

        public const int SECURITY_PROCESS_PROTECTION_TYPE_LITE_RID = 0x00000200;

        public const int SECURITY_PROCESS_PROTECTION_TYPE_NONE_RID = 0x00000000;

        public const int SECURITY_PROCESS_PROTECTION_LEVEL_WINTCB_RID = 0x00002000;

        public const int SECURITY_PROCESS_PROTECTION_LEVEL_WINDOWS_RID = 0x00001000;

        public const int SECURITY_PROCESS_PROTECTION_LEVEL_APP_RID = 0x00000800;

        public const int SECURITY_PROCESS_PROTECTION_LEVEL_ANTIMALWARE_RID = 0x00000600;

        public const int SECURITY_PROCESS_PROTECTION_LEVEL_AUTHENTICODE_RID = 0x00000400;

        public const int SECURITY_PROCESS_PROTECTION_LEVEL_NONE_RID = 0x00000000;

        public const uint SECURITY_TRUSTED_INSTALLER_RID1 = 956008885;

        public const uint SECURITY_TRUSTED_INSTALLER_RID2 = 3418522649;

        public const uint SECURITY_TRUSTED_INSTALLER_RID3 = 1831038044;

        public const uint SECURITY_TRUSTED_INSTALLER_RID4 = 1853292631;

        public const uint SECURITY_TRUSTED_INSTALLER_RID5 = 2271478464;

        public const int SE_GROUP_MANDATORY = 0x00000001;

        public const int SE_GROUP_ENABLED_BY_DEFAULT = 0x00000002;

        public const int SE_GROUP_ENABLED = 0x00000004;

        public const int SE_GROUP_OWNER = 0x00000008;

        public const int SE_GROUP_USE_FOR_DENY_ONLY = 0x00000010;

        public const int SE_GROUP_INTEGRITY = 0x00000020;

        public const int SE_GROUP_INTEGRITY_ENABLED = 0x00000040;

        public const int SE_GROUP_LOGON_ID = unchecked((int)0xC0000000);

        public const int SE_GROUP_RESOURCE = 0x20000000;

        public const uint ACL_REVISION1 = 1;

        public const uint ACL_REVISION2 = 2;

        public const uint ACL_REVISION3 = 3;

        public const uint ACL_REVISION4 = 4;

        public const uint ACCESS_MIN_MS_ACE_TYPE = 0x0;

        public const uint ACCESS_ALLOWED_ACE_TYPE = 0x0;

        public const uint ACCESS_DENIED_ACE_TYPE = 0x1;

        public const uint SYSTEM_AUDIT_ACE_TYPE = 0x2;

        public const uint SYSTEM_ALARM_ACE_TYPE = 0x3;

        public const uint ACCESS_MAX_MS_V2_ACE_TYPE = 0x3;

        public const uint ACCESS_ALLOWED_COMPOUND_ACE_TYPE = 0x4;

        public const uint ACCESS_MAX_MS_V3_ACE_TYPE = 0x4;

        public const uint ACCESS_MIN_MS_OBJECT_ACE_TYPE = 0x5;

        public const uint ACCESS_ALLOWED_OBJECT_ACE_TYPE = 0x5;

        public const uint ACCESS_DENIED_OBJECT_ACE_TYPE = 0x6;

        public const uint SYSTEM_AUDIT_OBJECT_ACE_TYPE = 0x7;

        public const uint SYSTEM_ALARM_OBJECT_ACE_TYPE = 0x8;

        public const uint ACCESS_MAX_MS_OBJECT_ACE_TYPE = 0x8;

        public const uint ACCESS_MAX_MS_V4_ACE_TYPE = 0x8;

        public const uint ACCESS_MAX_MS_ACE_TYPE = 0x8;

        public const uint ACCESS_ALLOWED_CALLBACK_ACE_TYPE = 0x9;

        public const uint ACCESS_DENIED_CALLBACK_ACE_TYPE = 0xA;

        public const uint ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE = 0xB;

        public const uint ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE = 0xC;

        public const uint SYSTEM_AUDIT_CALLBACK_ACE_TYPE = 0xD;

        public const uint SYSTEM_ALARM_CALLBACK_ACE_TYPE = 0xE;

        public const uint SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE = 0xF;

        public const uint SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE = 0x10;

        public const uint SYSTEM_MANDATORY_LABEL_ACE_TYPE = 0x11;

        public const uint SYSTEM_RESOURCE_ATTRIBUTE_ACE_TYPE = 0x12;

        public const uint SYSTEM_SCOPED_POLICY_ID_ACE_TYPE = 0x13;

        public const uint SYSTEM_PROCESS_TRUST_LABEL_ACE_TYPE = 0x14;

        public const uint SYSTEM_ACCESS_FILTER_ACE_TYPE = 0x15;

        public const uint ACCESS_MAX_MS_V5_ACE_TYPE = 0x15;

        public const uint VALID_INHERIT_FLAGS = 0x1F;

        public const uint CRITICAL_ACE_FLAG = 0x20;

        public const uint TRUST_PROTECTED_FILTER_ACE_FLAG = 0x40;

        public const uint SYSTEM_MANDATORY_LABEL_NO_WRITE_UP = 0x1;

        public const uint SYSTEM_MANDATORY_LABEL_NO_READ_UP = 0x2;

        public const uint SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP = 0x4;

        public const uint SYSTEM_PROCESS_TRUST_LABEL_VALID_MASK = 0x00ffffff;

        public const uint SYSTEM_PROCESS_TRUST_NOCONSTRAINT_MASK = 0xffffffff;

        public const uint SYSTEM_ACCESS_FILTER_VALID_MASK = 0x00ffffff;

        public const uint SYSTEM_ACCESS_FILTER_NOCONSTRAINT_MASK = 0xffffffff;

        public const uint SECURITY_DESCRIPTOR_REVISION = 1;

        public const uint SECURITY_DESCRIPTOR_REVISION1 = 1;

        public const uint SE_OWNER_DEFAULTED = 0x0001;

        public const uint SE_GROUP_DEFAULTED = 0x0002;

        public const uint SE_DACL_PRESENT = 0x0004;

        public const uint SE_DACL_DEFAULTED = 0x0008;

        public const uint SE_SACL_PRESENT = 0x0010;

        public const uint SE_SACL_DEFAULTED = 0x0020;

        public const uint SE_DACL_AUTO_INHERIT_REQ = 0x0100;

        public const uint SE_SACL_AUTO_INHERIT_REQ = 0x0200;

        public const uint SE_DACL_AUTO_INHERITED = 0x0400;

        public const uint SE_SACL_AUTO_INHERITED = 0x0800;

        public const uint SE_DACL_PROTECTED = 0x1000;

        public const uint SE_SACL_PROTECTED = 0x2000;

        public const uint SE_RM_CONTROL_VALID = 0x4000;

        public const uint SE_SELF_RELATIVE = 0x8000;

        public const uint ACCESS_OBJECT_GUID = 0;

        public const uint ACCESS_PROPERTY_SET_GUID = 1;

        public const uint ACCESS_PROPERTY_GUID = 2;

        public const uint ACCESS_MAX_LEVEL = 4;

        public const uint AUDIT_ALLOW_NO_PRIVILEGE = 0x1;

        public const uint PRIVILEGE_SET_ALL_NECESSARY = 1;

        public const uint ACCESS_REASON_TYPE_MASK = 0x00ff0000;

        public const uint ACCESS_REASON_DATA_MASK = 0x0000ffff;

        public const uint ACCESS_REASON_STAGING_MASK = 0x80000000;

        public const uint ACCESS_REASON_EXDATA_MASK = 0x7f000000;

        public const uint SE_SECURITY_DESCRIPTOR_FLAG_NO_OWNER_ACE = 0x00000001;

        public const uint SE_SECURITY_DESCRIPTOR_FLAG_NO_LABEL_ACE = 0x00000002;

        public const uint SE_SECURITY_DESCRIPTOR_FLAG_NO_ACCESS_FILTER_ACE = 0x00000004;

        public const uint SE_SECURITY_DESCRIPTOR_VALID_FLAGS = 0x00000007;

        public const uint SE_ACCESS_CHECK_FLAG_NO_LEARNING_MODE_LOGGING = 0x00000008;

        public const uint SE_ACCESS_CHECK_VALID_FLAGS = 0x00000008;

        public const uint POLICY_AUDIT_SUBCATEGORY_COUNT = 59;

        public const uint TOKEN_SOURCE_LENGTH = 8;

        public const uint CLAIM_SECURITY_ATTRIBUTE_TYPE_INVALID = 0x00;

        public const uint CLAIM_SECURITY_ATTRIBUTE_CUSTOM_FLAGS = 0xFFFF0000;

        public const uint CLAIM_SECURITY_ATTRIBUTES_INFORMATION_VERSION_V1 = 1;

        public const int PROCESS_TRUST_LABEL_SECURITY_INFORMATION = 0x00000080;

        public const int ACCESS_FILTER_SECURITY_INFORMATION = 0x00000100;

        public const uint SE_SIGNING_LEVEL_UNCHECKED = 0x00000000;

        public const uint SE_SIGNING_LEVEL_UNSIGNED = 0x00000001;

        public const uint SE_SIGNING_LEVEL_ENTERPRISE = 0x00000002;

        public const uint SE_SIGNING_LEVEL_CUSTOM_1 = 0x00000003;

        public const uint SE_SIGNING_LEVEL_AUTHENTICODE = 0x00000004;

        public const uint SE_SIGNING_LEVEL_CUSTOM_2 = 0x00000005;

        public const uint SE_SIGNING_LEVEL_STORE = 0x00000006;

        public const uint SE_SIGNING_LEVEL_CUSTOM_3 = 0x00000007;

        public const uint SE_SIGNING_LEVEL_MICROSOFT = 0x00000008;

        public const uint SE_SIGNING_LEVEL_CUSTOM_4 = 0x00000009;

        public const uint SE_SIGNING_LEVEL_CUSTOM_5 = 0x0000000A;

        public const uint SE_SIGNING_LEVEL_DYNAMIC_CODEGEN = 0x0000000B;

        public const uint SE_SIGNING_LEVEL_WINDOWS = 0x0000000C;

        public const uint SE_SIGNING_LEVEL_CUSTOM_7 = 0x0000000D;

        public const uint SE_SIGNING_LEVEL_WINDOWS_TCB = 0x0000000E;

        public const uint SE_SIGNING_LEVEL_CUSTOM_6 = 0x0000000F;

        public const uint SE_LEARNING_MODE_FLAG_PERMISSIVE = 0x00000001;

        public const uint JOB_OBJECT_ASSIGN_PROCESS = 0x0001;

        public const uint JOB_OBJECT_SET_ATTRIBUTES = 0x0002;

        public const uint JOB_OBJECT_QUERY = 0x0004;

        public const uint JOB_OBJECT_TERMINATE = 0x0008;

        public const uint JOB_OBJECT_SET_SECURITY_ATTRIBUTES = 0x0010;

        public const uint JOB_OBJECT_IMPERSONATE = 0x0020;

        public const uint FLS_MAXIMUM_AVAILABLE = 4080;

        public const uint TLS_MINIMUM_AVAILABLE = 64;

        public const uint THREAD_DYNAMIC_CODE_ALLOW = 1;

        public const uint THREAD_BASE_PRIORITY_LOWRT = 15;

        public const uint THREAD_BASE_PRIORITY_MAX = 2;

        public const int THREAD_BASE_PRIORITY_MIN = -2;

        public const int THREAD_BASE_PRIORITY_IDLE = -15;

        public const uint MEMORY_PRIORITY_LOWEST = 0;

        public const uint DYNAMIC_EH_CONTINUATION_TARGET_ADD = 0x00000001;

        public const uint DYNAMIC_EH_CONTINUATION_TARGET_PROCESSED = 0x00000002;

        public const uint QUOTA_LIMITS_HARDWS_MIN_ENABLE = 0x00000001;

        public const uint QUOTA_LIMITS_HARDWS_MIN_DISABLE = 0x00000002;

        public const uint QUOTA_LIMITS_HARDWS_MAX_ENABLE = 0x00000004;

        public const uint QUOTA_LIMITS_HARDWS_MAX_DISABLE = 0x00000008;

        public const uint QUOTA_LIMITS_USE_DEFAULT_LIMITS = 0x00000010;

        public const uint MAX_HW_COUNTERS = 16;

        public const uint THREAD_PROFILING_FLAG_DISPATCH = 0x00000001;

        public const uint JOB_OBJECT_NET_RATE_CONTROL_MAX_DSCP_TAG = 64;

        public const uint JOB_OBJECT_MSG_END_OF_JOB_TIME = 1;

        public const uint JOB_OBJECT_MSG_END_OF_PROCESS_TIME = 2;

        public const uint JOB_OBJECT_MSG_ACTIVE_PROCESS_LIMIT = 3;

        public const uint JOB_OBJECT_MSG_ACTIVE_PROCESS_ZERO = 4;

        public const uint JOB_OBJECT_MSG_NEW_PROCESS = 6;

        public const uint JOB_OBJECT_MSG_EXIT_PROCESS = 7;

        public const uint JOB_OBJECT_MSG_ABNORMAL_EXIT_PROCESS = 8;

        public const uint JOB_OBJECT_MSG_PROCESS_MEMORY_LIMIT = 9;

        public const uint JOB_OBJECT_MSG_JOB_MEMORY_LIMIT = 10;

        public const uint JOB_OBJECT_MSG_NOTIFICATION_LIMIT = 11;

        public const uint JOB_OBJECT_MSG_JOB_CYCLE_TIME_LIMIT = 12;

        public const uint JOB_OBJECT_MSG_SILO_TERMINATED = 13;

        public const uint JOB_OBJECT_MSG_MINIMUM = 1;

        public const uint JOB_OBJECT_MSG_MAXIMUM = 13;

        public const uint JOB_OBJECT_UILIMIT_ALL = 0x000000FF;

        public const uint JOB_OBJECT_UI_VALID_FLAGS = 0x000000FF;

        public const uint JOB_OBJECT_CPU_RATE_CONTROL_MIN_MAX_RATE = 0x10;

        public const uint JOB_OBJECT_CPU_RATE_CONTROL_VALID_FLAGS = 0x1f;

        public const uint EVENT_MODIFY_STATE = 0x0002;

        public const uint MUTANT_QUERY_STATE = 0x0001;

        public const uint SEMAPHORE_MODIFY_STATE = 0x0002;

        public const uint TIMER_QUERY_STATE = 0x0001;

        public const uint TIMER_MODIFY_STATE = 0x0002;

        public const uint TIME_ZONE_ID_UNKNOWN = 0;

        public const uint TIME_ZONE_ID_STANDARD = 1;

        public const uint TIME_ZONE_ID_DAYLIGHT = 2;

        public const uint LTP_PC_SMT = 0x1;

        public const uint CACHE_FULLY_ASSOCIATIVE = 0xFF;

        public const uint SYSTEM_CPU_SET_INFORMATION_PARKED = 0x1;

        public const uint SYSTEM_CPU_SET_INFORMATION_ALLOCATED = 0x2;

        public const uint SYSTEM_CPU_SET_INFORMATION_ALLOCATED_TO_TARGET_PROCESS = 0x4;

        public const uint SYSTEM_CPU_SET_INFORMATION_REALTIME = 0x8;

        public const uint PROCESSOR_INTEL_386 = 386;

        public const uint PROCESSOR_INTEL_486 = 486;

        public const uint PROCESSOR_INTEL_PENTIUM = 586;

        public const uint PROCESSOR_INTEL_IA64 = 2200;

        public const uint PROCESSOR_AMD_X8664 = 8664;

        public const uint PROCESSOR_MIPS_R4000 = 4000;

        public const uint PROCESSOR_ALPHA_21064 = 21064;

        public const uint PROCESSOR_PPC_601 = 601;

        public const uint PROCESSOR_PPC_603 = 603;

        public const uint PROCESSOR_PPC_604 = 604;

        public const uint PROCESSOR_PPC_620 = 620;

        public const uint PROCESSOR_HITACHI_SH3 = 10003;

        public const uint PROCESSOR_HITACHI_SH3E = 10004;

        public const uint PROCESSOR_HITACHI_SH4 = 10005;

        public const uint PROCESSOR_MOTOROLA_821 = 821;

        public const uint PROCESSOR_SHx_SH3 = 103;

        public const uint PROCESSOR_SHx_SH4 = 104;

        public const uint PROCESSOR_STRONGARM = 2577;

        public const uint PROCESSOR_ARM720 = 1824;

        public const uint PROCESSOR_ARM820 = 2080;

        public const uint PROCESSOR_ARM920 = 2336;

        public const uint PROCESSOR_ARM_7TDMI = 70001;

        public const uint PROCESSOR_OPTIL = 0x494f;

        public const uint PROCESSOR_ARCHITECTURE_MIPS = 1;

        public const uint PROCESSOR_ARCHITECTURE_ALPHA = 2;

        public const uint PROCESSOR_ARCHITECTURE_PPC = 3;

        public const uint PROCESSOR_ARCHITECTURE_SHX = 4;

        public const uint PROCESSOR_ARCHITECTURE_ALPHA64 = 7;

        public const uint PROCESSOR_ARCHITECTURE_MSIL = 8;

        public const uint PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 = 10;

        public const uint PROCESSOR_ARCHITECTURE_NEUTRAL = 11;

        public const uint PROCESSOR_ARCHITECTURE_ARM64 = 12;

        public const uint PROCESSOR_ARCHITECTURE_ARM32_ON_WIN64 = 13;

        public const uint PROCESSOR_ARCHITECTURE_IA32_ON_ARM64 = 14;

        public const uint PF_PPC_MOVEMEM_64BIT_OK = 4;

        public const uint PF_ALPHA_BYTE_INSTRUCTIONS = 5;

        public const uint PF_SSE_DAZ_MODE_AVAILABLE = 11;

        public const uint PF_ARM_NEON_INSTRUCTIONS_AVAILABLE = 19;

        public const uint PF_RDRAND_INSTRUCTION_AVAILABLE = 28;

        public const uint PF_RDTSCP_INSTRUCTION_AVAILABLE = 32;

        public const uint PF_RDPID_INSTRUCTION_AVAILABLE = 33;

        public const uint PF_MONITORX_INSTRUCTION_AVAILABLE = 35;

        public const uint PF_SSSE3_INSTRUCTIONS_AVAILABLE = 36;

        public const uint PF_SSE4_1_INSTRUCTIONS_AVAILABLE = 37;

        public const uint PF_SSE4_2_INSTRUCTIONS_AVAILABLE = 38;

        public const uint PF_AVX_INSTRUCTIONS_AVAILABLE = 39;

        public const uint PF_AVX2_INSTRUCTIONS_AVAILABLE = 40;

        public const uint PF_AVX512F_INSTRUCTIONS_AVAILABLE = 41;

        public const uint XSTATE_LEGACY_FLOATING_POINT = 0;

        public const uint XSTATE_LEGACY_SSE = 1;

        public const uint XSTATE_GSSE = 2;

        public const uint XSTATE_MPX_BNDREGS = 3;

        public const uint XSTATE_MPX_BNDCSR = 4;

        public const uint XSTATE_AVX512_KMASK = 5;

        public const uint XSTATE_AVX512_ZMM_H = 6;

        public const uint XSTATE_AVX512_ZMM = 7;

        public const uint XSTATE_IPT = 8;

        public const uint XSTATE_CET_U = 11;

        public const uint XSTATE_LWP = 62;

        public const uint MAXIMUM_XSTATE_FEATURES = 64;

        public const uint XSTATE_COMPACTION_ENABLE = 63;

        public const uint XSTATE_ALIGN_BIT = 1;

        public const uint XSTATE_CONTROLFLAG_XSAVEOPT_MASK = 1;

        public const uint XSTATE_CONTROLFLAG_XSAVEC_MASK = 2;

        public const uint CFG_CALL_TARGET_VALID = 0x00000001;

        public const uint CFG_CALL_TARGET_PROCESSED = 0x00000002;

        public const uint CFG_CALL_TARGET_CONVERT_EXPORT_SUPPRESSED_TO_VALID = 0x00000004;

        public const uint SESSION_QUERY_ACCESS = 0x0001;

        public const uint SESSION_MODIFY_ACCESS = 0x0002;

        public const uint MEM_TOP_DOWN = 0x00100000;

        public const uint MEM_WRITE_WATCH = 0x00200000;

        public const uint MEM_PHYSICAL = 0x00400000;

        public const uint MEM_ROTATE = 0x00800000;

        public const uint MEM_DIFFERENT_IMAGE_BASE_OK = 0x00800000;

        public const uint MEM_4MB_PAGES = 0x80000000;

        public const uint MEM_COALESCE_PLACEHOLDERS = 0x00000001;

        public const uint MEM_EXTENDED_PARAMETER_GRAPHICS = 0x00000001;

        public const uint MEM_EXTENDED_PARAMETER_NONPAGED = 0x00000002;

        public const uint MEM_EXTENDED_PARAMETER_ZERO_PAGES_OPTIONAL = 0x00000004;

        public const uint MEM_EXTENDED_PARAMETER_NONPAGED_LARGE = 0x00000008;

        public const uint MEM_EXTENDED_PARAMETER_NONPAGED_HUGE = 0x00000010;

        public const uint MEM_EXTENDED_PARAMETER_SOFT_FAULT_PAGES = 0x00000020;

        public const uint MEM_EXTENDED_PARAMETER_TYPE_BITS = 8;

        public const uint WRITE_WATCH_FLAG_RESET = 0x01;

        public const uint ENCLAVE_TYPE_SGX = 0x00000001;

        public const uint ENCLAVE_TYPE_SGX2 = 0x00000002;

        public const uint ENCLAVE_TYPE_VBS = 0x00000010;

        public const uint ENCLAVE_VBS_FLAG_DEBUG = 0x00000001;

        public const uint ENCLAVE_TYPE_VBS_BASIC = 0x00000011;

        public const uint VBS_BASIC_PAGE_MEASURED_DATA = 0x00000001;

        public const uint VBS_BASIC_PAGE_UNMEASURED_DATA = 0x00000002;

        public const uint VBS_BASIC_PAGE_ZERO_FILL = 0x00000003;

        public const uint VBS_BASIC_PAGE_THREAD_DESCRIPTOR = 0x00000004;

        public const uint VBS_BASIC_PAGE_SYSTEM_CALL = 0x00000005;

        public const uint TREE_CONNECT_ATTRIBUTE_PRIVACY = 0x00004000;

        public const uint TREE_CONNECT_ATTRIBUTE_INTEGRITY = 0x00008000;

        public const uint TREE_CONNECT_ATTRIBUTE_GLOBAL = 0x00000004;

        public const uint TREE_CONNECT_ATTRIBUTE_PINNED = 0x00000002;

        public const uint FILE_ATTRIBUTE_STRICTLY_SEQUENTIAL = 0x20000000;

        public const uint MAILSLOT_NO_MESSAGE = 0xFFFFFFFF;

        public const uint MAILSLOT_WAIT_FOREVER = 0xFFFFFFFF;

        public const uint FILE_CASE_SENSITIVE_SEARCH = 0x00000001;

        public const uint FILE_CASE_PRESERVED_NAMES = 0x00000002;

        public const uint FILE_UNICODE_ON_DISK = 0x00000004;

        public const uint FILE_PERSISTENT_ACLS = 0x00000008;

        public const uint FILE_FILE_COMPRESSION = 0x00000010;

        public const uint FILE_VOLUME_QUOTAS = 0x00000020;

        public const uint FILE_SUPPORTS_SPARSE_FILES = 0x00000040;

        public const uint FILE_SUPPORTS_REPARSE_POINTS = 0x00000080;

        public const uint FILE_SUPPORTS_REMOTE_STORAGE = 0x00000100;

        public const uint FILE_RETURNS_CLEANUP_RESULT_INFO = 0x00000200;

        public const uint FILE_SUPPORTS_POSIX_UNLINK_RENAME = 0x00000400;

        public const uint FILE_VOLUME_IS_COMPRESSED = 0x00008000;

        public const uint FILE_SUPPORTS_OBJECT_IDS = 0x00010000;

        public const uint FILE_SUPPORTS_ENCRYPTION = 0x00020000;

        public const uint FILE_NAMED_STREAMS = 0x00040000;

        public const uint FILE_READ_ONLY_VOLUME = 0x00080000;

        public const uint FILE_SEQUENTIAL_WRITE_ONCE = 0x00100000;

        public const uint FILE_SUPPORTS_TRANSACTIONS = 0x00200000;

        public const uint FILE_SUPPORTS_HARD_LINKS = 0x00400000;

        public const uint FILE_SUPPORTS_EXTENDED_ATTRIBUTES = 0x00800000;

        public const uint FILE_SUPPORTS_OPEN_BY_FILE_ID = 0x01000000;

        public const uint FILE_SUPPORTS_USN_JOURNAL = 0x02000000;

        public const uint FILE_SUPPORTS_INTEGRITY_STREAMS = 0x04000000;

        public const uint FILE_SUPPORTS_BLOCK_REFCOUNTING = 0x08000000;

        public const uint FILE_SUPPORTS_SPARSE_VDL = 0x10000000;

        public const uint FILE_DAX_VOLUME = 0x20000000;

        public const uint FILE_SUPPORTS_GHOSTING = 0x40000000;

        public const uint FILE_CS_FLAG_CASE_SENSITIVE_DIR = 0x00000001;

        public const uint FLUSH_FLAGS_FILE_DATA_ONLY = 0x00000001;

        public const uint FLUSH_FLAGS_NO_SYNC = 0x00000002;

        public const uint FLUSH_FLAGS_FILE_DATA_SYNC_ONLY = 0x00000004;

        public const uint IO_REPARSE_TAG_RESERVED_ZERO = 0;

        public const uint IO_REPARSE_TAG_RESERVED_ONE = 1;

        public const uint IO_REPARSE_TAG_RESERVED_TWO = 2;

        public const int IO_REPARSE_TAG_MOUNT_POINT = unchecked((int)0xA0000003);

        public const int IO_REPARSE_TAG_HSM = unchecked((int)0xC0000004);

        public const int IO_REPARSE_TAG_HSM2 = unchecked((int)0x80000006);

        public const int IO_REPARSE_TAG_SIS = unchecked((int)0x80000007);

        public const int IO_REPARSE_TAG_WIM = unchecked((int)0x80000008);

        public const int IO_REPARSE_TAG_CSV = unchecked((int)0x80000009);

        public const int IO_REPARSE_TAG_DFS = unchecked((int)0x8000000A);

        public const int IO_REPARSE_TAG_SYMLINK = unchecked((int)0xA000000C);

        public const int IO_REPARSE_TAG_DFSR = unchecked((int)0x80000012);

        public const int IO_REPARSE_TAG_DEDUP = unchecked((int)0x80000013);

        public const int IO_REPARSE_TAG_NFS = unchecked((int)0x80000014);

        public const int IO_REPARSE_TAG_FILE_PLACEHOLDER = unchecked((int)0x80000015);

        public const int IO_REPARSE_TAG_WOF = unchecked((int)0x80000017);

        public const int IO_REPARSE_TAG_WCI = unchecked((int)0x80000018);

        public const int IO_REPARSE_TAG_WCI_1 = unchecked((int)0x90001018);

        public const int IO_REPARSE_TAG_GLOBAL_REPARSE = unchecked((int)0xA0000019);

        public const int IO_REPARSE_TAG_CLOUD = unchecked((int)0x9000001A);

        public const int IO_REPARSE_TAG_CLOUD_1 = unchecked((int)0x9000101A);

        public const int IO_REPARSE_TAG_CLOUD_2 = unchecked((int)0x9000201A);

        public const int IO_REPARSE_TAG_CLOUD_3 = unchecked((int)0x9000301A);

        public const int IO_REPARSE_TAG_CLOUD_4 = unchecked((int)0x9000401A);

        public const int IO_REPARSE_TAG_CLOUD_5 = unchecked((int)0x9000501A);

        public const int IO_REPARSE_TAG_CLOUD_6 = unchecked((int)0x9000601A);

        public const int IO_REPARSE_TAG_CLOUD_7 = unchecked((int)0x9000701A);

        public const int IO_REPARSE_TAG_CLOUD_8 = unchecked((int)0x9000801A);

        public const int IO_REPARSE_TAG_CLOUD_9 = unchecked((int)0x9000901A);

        public const int IO_REPARSE_TAG_CLOUD_A = unchecked((int)0x9000A01A);

        public const int IO_REPARSE_TAG_CLOUD_B = unchecked((int)0x9000B01A);

        public const int IO_REPARSE_TAG_CLOUD_C = unchecked((int)0x9000C01A);

        public const int IO_REPARSE_TAG_CLOUD_D = unchecked((int)0x9000D01A);

        public const int IO_REPARSE_TAG_CLOUD_E = unchecked((int)0x9000E01A);

        public const int IO_REPARSE_TAG_CLOUD_F = unchecked((int)0x9000F01A);

        public const int IO_REPARSE_TAG_CLOUD_MASK = 0x0000F000;

        public const int IO_REPARSE_TAG_APPEXECLINK = unchecked((int)0x8000001B);

        public const int IO_REPARSE_TAG_PROJFS = unchecked((int)0x9000001C);

        public const int IO_REPARSE_TAG_STORAGE_SYNC = unchecked((int)0x8000001E);

        public const int IO_REPARSE_TAG_WCI_TOMBSTONE = unchecked((int)0xA000001F);

        public const int IO_REPARSE_TAG_UNHANDLED = unchecked((int)0x80000020);

        public const int IO_REPARSE_TAG_ONEDRIVE = unchecked((int)0x80000021);

        public const int IO_REPARSE_TAG_PROJFS_TOMBSTONE = unchecked((int)0xA0000022);

        public const int IO_REPARSE_TAG_AF_UNIX = unchecked((int)0x80000023);

        public const int IO_REPARSE_TAG_WCI_LINK = unchecked((int)0xA0000027);

        public const int IO_REPARSE_TAG_WCI_LINK_1 = unchecked((int)0xA0001027);

        public const uint SCRUB_DATA_INPUT_FLAG_RESUME = 0x00000001;

        public const uint SCRUB_DATA_INPUT_FLAG_SKIP_IN_SYNC = 0x00000002;

        public const uint SCRUB_DATA_INPUT_FLAG_SKIP_NON_INTEGRITY_DATA = 0x00000004;

        public const uint SCRUB_DATA_INPUT_FLAG_IGNORE_REDUNDANCY = 0x00000008;

        public const uint SCRUB_DATA_INPUT_FLAG_SKIP_DATA = 0x00000010;

        public const uint SCRUB_DATA_INPUT_FLAG_SCRUB_BY_OBJECT_ID = 0x00000020;

        public const uint SCRUB_DATA_INPUT_FLAG_OPLOCK_NOT_ACQUIRED = 0x00000040;

        public const uint SCRUB_DATA_OUTPUT_FLAG_INCOMPLETE = 0x00000001;

        public const uint SCRUB_DATA_OUTPUT_FLAG_NON_USER_DATA_RANGE = 0x00010000;

        public const uint SCRUB_DATA_OUTPUT_FLAG_PARITY_EXTENT_DATA_RETURNED = 0x00020000;

        public const uint SCRUB_DATA_OUTPUT_FLAG_RESUME_CONTEXT_LENGTH_SPECIFIED = 0x00040000;

        public const uint SHUFFLE_FILE_FLAG_SKIP_INITIALIZING_NEW_CLUSTERS = 0x00000001;

        public const uint IO_COMPLETION_MODIFY_STATE = 0x0002;

        public const uint NETWORK_APP_INSTANCE_CSV_FLAGS_VALID_ONLY_IF_CSV_COORDINATOR = 0x00000001;

        public static readonly Guid GUID_MAX_POWER_SAVINGS__scanned__ = new Guid(0xA1841308, 0x3541, 0x4FAB, 0xBC, 0x81, 0xF7, 0x15, 0x56, 0xF2, 0x0B, 0x4A );

        public static readonly Guid GUID_MIN_POWER_SAVINGS__scanned__ = new Guid(0x8C5E7FDA, 0xE8BF, 0x4A96, 0x9A, 0x85, 0xA6, 0xE2, 0x3A, 0x8C, 0x63, 0x5C );

        public static readonly Guid GUID_TYPICAL_POWER_SAVINGS__scanned__ = new Guid(0x381B4222, 0xF694, 0x41F0, 0x96, 0x85, 0xFF, 0x5B, 0xB2, 0x60, 0xDF, 0x2E );

        public static readonly Guid NO_SUBGROUP_GUID__scanned__ = new Guid(0xFEA3413E, 0x7E05, 0x4911, 0x9A, 0x71, 0x70, 0x03, 0x31, 0xF1, 0xC2, 0x94 );

        public static readonly Guid ALL_POWERSCHEMES_GUID__scanned__ = new Guid(0x68A1E95E, 0x13EA, 0x41E1, 0x80, 0x11, 0x0C, 0x49, 0x6C, 0xA4, 0x90, 0xB0 );

        public static readonly Guid GUID_POWERSCHEME_PERSONALITY__scanned__ = new Guid(0x245D8541, 0x3943, 0x4422, 0xB0, 0x25, 0x13, 0xA7, 0x84, 0xF6, 0x79, 0xB7 );

        public static readonly Guid GUID_ACTIVE_POWERSCHEME__scanned__ = new Guid(0x31F9F286, 0x5084, 0x42FE, 0xB7, 0x20, 0x2B, 0x02, 0x64, 0x99, 0x37, 0x63 );

        public static readonly Guid GUID_IDLE_RESILIENCY_SUBGROUP__scanned__ = new Guid(0x2e601130, 0x5351, 0x4d9d, 0x8e, 0x4, 0x25, 0x29, 0x66, 0xba, 0xd0, 0x54);

        public static readonly Guid GUID_IDLE_RESILIENCY_PERIOD__scanned__ = new Guid(0xc42b79aa, 0xaa3a, 0x484b, 0xa9, 0x8f, 0x2c, 0xf3, 0x2a, 0xa9, 0xa, 0x28);

        public static readonly Guid GUID_DEEP_SLEEP_ENABLED__scanned__ = new Guid(0xd502f7ee, 0x1dc7, 0x4efd, 0xa5, 0x5d, 0xf0, 0x4b, 0x6f, 0x5c, 0x5, 0x45);

        public static readonly Guid GUID_DEEP_SLEEP_PLATFORM_STATE__scanned__ = new Guid(0xd23f2fb8, 0x9536, 0x4038, 0x9c, 0x94, 0x1c, 0xe0, 0x2e, 0x5c, 0x21, 0x52);

        public static readonly Guid GUID_DISK_COALESCING_POWERDOWN_TIMEOUT__scanned__ = new Guid(0xc36f0eb4, 0x2988, 0x4a70, 0x8e, 0xee, 0x8, 0x84, 0xfc, 0x2c, 0x24, 0x33);

        public static readonly Guid GUID_EXECUTION_REQUIRED_REQUEST_TIMEOUT__scanned__ = new Guid(0x3166bc41, 0x7e98, 0x4e03, 0xb3, 0x4e, 0xec, 0xf, 0x5f, 0x2b, 0x21, 0x8e);

        public static readonly Guid GUID_VIDEO_SUBGROUP__scanned__ = new Guid(0x7516B95F, 0xF776, 0x4464, 0x8C, 0x53, 0x06, 0x16, 0x7F, 0x40, 0xCC, 0x99 );

        public static readonly Guid GUID_VIDEO_POWERDOWN_TIMEOUT__scanned__ = new Guid(0x3C0BC021, 0xC8A8, 0x4E07, 0xA9, 0x73, 0x6B, 0x14, 0xCB, 0xCB, 0x2B, 0x7E );

        public static readonly Guid GUID_VIDEO_ANNOYANCE_TIMEOUT__scanned__ = new Guid(0x82DBCF2D, 0xCD67, 0x40C5, 0xBF, 0xDC, 0x9F, 0x1A, 0x5C, 0xCD, 0x46, 0x63 );

        public static readonly Guid GUID_VIDEO_ADAPTIVE_PERCENT_INCREASE__scanned__ = new Guid(0xEED904DF, 0xB142, 0x4183, 0xB1, 0x0B, 0x5A, 0x11, 0x97, 0xA3, 0x78, 0x64 );

        public static readonly Guid GUID_VIDEO_DIM_TIMEOUT__scanned__ = new Guid(0x17aaa29b, 0x8b43, 0x4b94, 0xaa, 0xfe, 0x35, 0xf6, 0x4d, 0xaa, 0xf1, 0xee);

        public static readonly Guid GUID_VIDEO_ADAPTIVE_POWERDOWN__scanned__ = new Guid(0x90959D22, 0xD6A1, 0x49B9, 0xAF, 0x93, 0xBC, 0xE8, 0x85, 0xAD, 0x33, 0x5B );

        public static readonly Guid GUID_MONITOR_POWER_ON__scanned__ = new Guid(0x02731015, 0x4510, 0x4526, 0x99, 0xE6, 0xE5, 0xA1, 0x7E, 0xBD, 0x1A, 0xEA );

        public static readonly Guid GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS__scanned__ = new Guid(0xaded5e82L, 0xb909, 0x4619, 0x99, 0x49, 0xf5, 0xd7, 0x1d, 0xac, 0x0b, 0xcb);

        public static readonly Guid GUID_DEVICE_POWER_POLICY_VIDEO_DIM_BRIGHTNESS__scanned__ = new Guid(0xf1fbfde2, 0xa960, 0x4165, 0x9f, 0x88, 0x50, 0x66, 0x79, 0x11, 0xce, 0x96);

        public static readonly Guid GUID_VIDEO_CURRENT_MONITOR_BRIGHTNESS__scanned__ = new Guid(0x8ffee2c6, 0x2d01, 0x46be, 0xad, 0xb9, 0x39, 0x8a, 0xdd, 0xc5, 0xb4, 0xff);

        public static readonly Guid GUID_VIDEO_ADAPTIVE_DISPLAY_BRIGHTNESS__scanned__ = new Guid(0xFBD9AA66, 0x9553, 0x4097, 0xBA, 0x44, 0xED, 0x6E, 0x9D, 0x65, 0xEA, 0xB8);

        public static readonly Guid GUID_CONSOLE_DISPLAY_STATE__scanned__ = new Guid(0x6fe69556, 0x704a, 0x47a0, 0x8f, 0x24, 0xc2, 0x8d, 0x93, 0x6f, 0xda, 0x47);

        public static readonly Guid GUID_ALLOW_DISPLAY_REQUIRED__scanned__ = new Guid(0xA9CEB8DA, 0xCD46, 0x44FB, 0xA9, 0x8B, 0x02, 0xAF, 0x69, 0xDE, 0x46, 0x23 );

        public static readonly Guid GUID_VIDEO_CONSOLE_LOCK_TIMEOUT__scanned__ = new Guid(0x8ec4b3a5, 0x6868, 0x48c2, 0xbe, 0x75, 0x4f, 0x30, 0x44, 0xbe, 0x88, 0xa7);

        public static readonly Guid GUID_ADVANCED_COLOR_QUALITY_BIAS__scanned__ = new Guid(0x684c3e69, 0xa4f7, 0x4014, 0x87, 0x54, 0xd4, 0x51, 0x79, 0xa5, 0x61, 0x67);

        public static readonly Guid GUID_ADAPTIVE_POWER_BEHAVIOR_SUBGROUP__scanned__ = new Guid(0x8619b916, 0xe004, 0x4dd8, 0x9b, 0x66, 0xda, 0xe8, 0x6f, 0x80, 0x66, 0x98);

        public static readonly Guid GUID_NON_ADAPTIVE_INPUT_TIMEOUT__scanned__ = new Guid(0x5adbbfbc, 0x74e, 0x4da1, 0xba, 0x38, 0xdb, 0x8b, 0x36, 0xb2, 0xc8, 0xf3);

        public static readonly Guid GUID_ADAPTIVE_INPUT_CONTROLLER_STATE__scanned__ = new Guid(0xe98fae9, 0xf45a, 0x4de1, 0xa7, 0x57, 0x60, 0x31, 0xf1, 0x97, 0xf6, 0xea);

        public static readonly Guid GUID_DISK_SUBGROUP__scanned__ = new Guid(0x0012EE47, 0x9041, 0x4B5D, 0x9B, 0x77, 0x53, 0x5F, 0xBA, 0x8B, 0x14, 0x42 );

        public static readonly Guid GUID_DISK_MAX_POWER__scanned__ = new Guid(0x51dea550, 0xbb38, 0x4bc4, 0x99, 0x1b, 0xea, 0xcf, 0x37, 0xbe, 0x5e, 0xc8);

        public static readonly Guid GUID_DISK_POWERDOWN_TIMEOUT__scanned__ = new Guid(0x6738E2C4, 0xE8A5, 0x4A42, 0xB1, 0x6A, 0xE0, 0x40, 0xE7, 0x69, 0x75, 0x6E );

        public static readonly Guid GUID_DISK_IDLE_TIMEOUT__scanned__ = new Guid(0x58E39BA8, 0xB8E6, 0x4EF6, 0x90, 0xD0, 0x89, 0xAE, 0x32, 0xB2, 0x58, 0xD6 );

        public static readonly Guid GUID_DISK_BURST_IGNORE_THRESHOLD__scanned__ = new Guid(0x80e3c60e, 0xbb94, 0x4ad8, 0xbb, 0xe0, 0x0d, 0x31, 0x95, 0xef, 0xc6, 0x63 );

        public static readonly Guid GUID_DISK_ADAPTIVE_POWERDOWN__scanned__ = new Guid(0x396A32E1, 0x499A, 0x40B2, 0x91, 0x24, 0xA9, 0x6A, 0xFE, 0x70, 0x76, 0x67 );

        public static readonly Guid GUID_DISK_NVME_NOPPME__scanned__ = new Guid(0xfc7372b6, 0xab2d, 0x43ee, 0x87, 0x97, 0x15, 0xe9, 0x84, 0x1f, 0x2c, 0xca);

        public static readonly Guid GUID_SLEEP_SUBGROUP__scanned__ = new Guid(0x238C9FA8, 0x0AAD, 0x41ED, 0x83, 0xF4, 0x97, 0xBE, 0x24, 0x2C, 0x8F, 0x20 );

        public static readonly Guid GUID_SLEEP_IDLE_THRESHOLD__scanned__ = new Guid(0x81cd32e0, 0x7833, 0x44f3, 0x87, 0x37, 0x70, 0x81, 0xf3, 0x8d, 0x1f, 0x70 );

        public static readonly Guid GUID_STANDBY_TIMEOUT__scanned__ = new Guid(0x29F6C1DB, 0x86DA, 0x48C5, 0x9F, 0xDB, 0xF2, 0xB6, 0x7B, 0x1F, 0x44, 0xDA );

        public static readonly Guid GUID_UNATTEND_SLEEP_TIMEOUT__scanned__ = new Guid(0x7bc4a2f9, 0xd8fc, 0x4469, 0xb0, 0x7b, 0x33, 0xeb, 0x78, 0x5a, 0xac, 0xa0 );

        public static readonly Guid GUID_HIBERNATE_TIMEOUT__scanned__ = new Guid(0x9D7815A6, 0x7EE4, 0x497E, 0x88, 0x88, 0x51, 0x5A, 0x05, 0xF0, 0x23, 0x64 );

        public static readonly Guid GUID_HIBERNATE_FASTS4_POLICY__scanned__ = new Guid(0x94AC6D29, 0x73CE, 0x41A6, 0x80, 0x9F, 0x63, 0x63, 0xBA, 0x21, 0xB4, 0x7E );

        public static readonly Guid GUID_CRITICAL_POWER_TRANSITION__scanned__ = new Guid(0xB7A27025, 0xE569, 0x46c2, 0xA5, 0x04, 0x2B, 0x96, 0xCA, 0xD2, 0x25, 0xA1);

        public static readonly Guid GUID_SYSTEM_AWAYMODE__scanned__ = new Guid(0x98A7F580, 0x01F7, 0x48AA, 0x9C, 0x0F, 0x44, 0x35, 0x2C, 0x29, 0xE5, 0xC0 );

        public static readonly Guid GUID_ALLOW_AWAYMODE__scanned__ = new Guid(0x25dfa149, 0x5dd1, 0x4736, 0xb5, 0xab, 0xe8, 0xa3, 0x7b, 0x5b, 0x81, 0x87 );

        public static readonly Guid GUID_USER_PRESENCE_PREDICTION__scanned__ = new Guid(0x82011705, 0xfb95, 0x4d46, 0x8d, 0x35, 0x40, 0x42, 0xb1, 0xd2, 0xd, 0xef );

        public static readonly Guid GUID_STANDBY_BUDGET_GRACE_PERIOD__scanned__ = new Guid(0x60c07fe1, 0x0556, 0x45cf, 0x99, 0x03, 0xd5, 0x6e, 0x32, 0x21, 0x2, 0x42 );

        public static readonly Guid GUID_STANDBY_BUDGET_PERCENT__scanned__ = new Guid(0x9fe527be, 0x1b70, 0x48da, 0x93, 0x0d, 0x7b, 0xcf, 0x17, 0xb4, 0x49, 0x90 );

        public static readonly Guid GUID_STANDBY_RESERVE_GRACE_PERIOD__scanned__ = new Guid(0xc763ee92, 0x71e8, 0x4127, 0x84, 0xeb, 0xf6, 0xed, 0x04, 0x3a, 0x3e, 0x3d );

        public static readonly Guid GUID_STANDBY_RESERVE_TIME__scanned__ = new Guid(0x468FE7E5, 0x1158, 0x46EC, 0x88, 0xbc, 0x5b, 0x96, 0xc9, 0xe4, 0x4f, 0xd0 );

        public static readonly Guid GUID_STANDBY_RESET_PERCENT__scanned__ = new Guid(0x49cb11a5, 0x56e2, 0x4afb, 0x9d, 0x38, 0x3d, 0xf4, 0x78, 0x72, 0xe2, 0x1b);

        public static readonly Guid GUID_ALLOW_STANDBY_STATES__scanned__ = new Guid(0xabfc2519, 0x3608, 0x4c2a, 0x94, 0xea, 0x17, 0x1b, 0x0e, 0xd5, 0x46, 0xab );

        public static readonly Guid GUID_ALLOW_RTC_WAKE__scanned__ = new Guid(0xBD3B718A, 0x0680, 0x4D9D, 0x8A, 0xB2, 0xE1, 0xD2, 0xB4, 0xAC, 0x80, 0x6D );

        public static readonly Guid GUID_LEGACY_RTC_MITIGATION__scanned__ = new Guid(0x1A34BDC3, 0x7E6B, 0x442E, 0xA9, 0xD0, 0x64, 0xB6, 0xEF, 0x37, 0x8E, 0x84 );

        public static readonly Guid GUID_ALLOW_SYSTEM_REQUIRED__scanned__ = new Guid(0xA4B195F5, 0x8225, 0x47D8, 0x80, 0x12, 0x9D, 0x41, 0x36, 0x97, 0x86, 0xE2 );

        public static readonly Guid GUID_POWER_SAVING_STATUS__scanned__ = new Guid(0xe00958c0, 0xc213, 0x4ace, 0xac, 0x77, 0xfe, 0xcc, 0xed, 0x2e, 0xee, 0xa5);

        public static readonly Guid GUID_ENERGY_SAVER_SUBGROUP__scanned__ = new Guid(0xDE830923, 0xA562, 0x41AF, 0xA0, 0x86, 0xE3, 0xA2, 0xC6, 0xBA, 0xD2, 0xDA );

        public static readonly Guid GUID_ENERGY_SAVER_BATTERY_THRESHOLD__scanned__ = new Guid(0xE69653CA, 0xCF7F, 0x4F05, 0xAA, 0x73, 0xCB, 0x83, 0x3F, 0xA9, 0x0A, 0xD4 );

        public static readonly Guid GUID_ENERGY_SAVER_BRIGHTNESS__scanned__ = new Guid(0x13D09884, 0xF74E, 0x474A, 0xA8, 0x52, 0xB6, 0xBD, 0xE8, 0xAD, 0x03, 0xA8 );

        public static readonly Guid GUID_ENERGY_SAVER_POLICY__scanned__ = new Guid(0x5c5bb349, 0xad29, 0x4ee2, 0x9d, 0xb, 0x2b, 0x25, 0x27, 0xf, 0x7a, 0x81 );

        public static readonly Guid GUID_SYSTEM_BUTTON_SUBGROUP__scanned__ = new Guid(0x4F971E89, 0xEEBD, 0x4455, 0xA8, 0xDE, 0x9E, 0x59, 0x04, 0x0E, 0x73, 0x47 );

        public const uint POWERBUTTON_ACTION_INDEX_NOTHING = 0;

        public const uint POWERBUTTON_ACTION_INDEX_SLEEP = 1;

        public const uint POWERBUTTON_ACTION_INDEX_HIBERNATE = 2;

        public const uint POWERBUTTON_ACTION_INDEX_SHUTDOWN = 3;

        public const uint POWERBUTTON_ACTION_INDEX_TURN_OFF_THE_DISPLAY = 4;

        public const uint POWERBUTTON_ACTION_VALUE_NOTHING = 0;

        public const uint POWERBUTTON_ACTION_VALUE_SLEEP = 2;

        public const uint POWERBUTTON_ACTION_VALUE_HIBERNATE = 3;

        public const uint POWERBUTTON_ACTION_VALUE_SHUTDOWN = 6;

        public const uint POWERBUTTON_ACTION_VALUE_TURN_OFF_THE_DISPLAY = 8;

        public static readonly Guid GUID_POWERBUTTON_ACTION__scanned__ = new Guid(0x7648EFA3, 0xDD9C, 0x4E3E, 0xB5, 0x66, 0x50, 0xF9, 0x29, 0x38, 0x62, 0x80 );

        public static readonly Guid GUID_SLEEPBUTTON_ACTION__scanned__ = new Guid(0x96996BC0, 0xAD50, 0x47EC, 0x92, 0x3B, 0x6F, 0x41, 0x87, 0x4D, 0xD9, 0xEB );

        public static readonly Guid GUID_USERINTERFACEBUTTON_ACTION__scanned__ = new Guid(0xA7066653, 0x8D6C, 0x40A8, 0x91, 0x0E, 0xA1, 0xF5, 0x4B, 0x84, 0xC7, 0xE5 );

        public static readonly Guid GUID_LIDCLOSE_ACTION__scanned__ = new Guid(0x5CA83367, 0x6E45, 0x459F, 0xA2, 0x7B, 0x47, 0x6B, 0x1D, 0x01, 0xC9, 0x36 );

        public static readonly Guid GUID_LIDOPEN_POWERSTATE__scanned__ = new Guid(0x99FF10E7, 0x23B1, 0x4C07, 0xA9, 0xD1, 0x5C, 0x32, 0x06, 0xD7, 0x41, 0xB4 );

        public static readonly Guid GUID_BATTERY_SUBGROUP__scanned__ = new Guid(0xE73A048D, 0xBF27, 0x4F12, 0x97, 0x31, 0x8B, 0x20, 0x76, 0xE8, 0x89, 0x1F );

        public static readonly Guid GUID_BATTERY_DISCHARGE_ACTION_0__scanned__ = new Guid(0x637EA02F, 0xBBCB, 0x4015, 0x8E, 0x2C, 0xA1, 0xC7, 0xB9, 0xC0, 0xB5, 0x46 );

        public static readonly Guid GUID_BATTERY_DISCHARGE_LEVEL_0__scanned__ = new Guid(0x9A66D8D7, 0x4FF7, 0x4EF9, 0xB5, 0xA2, 0x5A, 0x32, 0x6C, 0xA2, 0xA4, 0x69 );

        public static readonly Guid GUID_BATTERY_DISCHARGE_FLAGS_0__scanned__ = new Guid(0x5dbb7c9f, 0x38e9, 0x40d2, 0x97, 0x49, 0x4f, 0x8a, 0x0e, 0x9f, 0x64, 0x0f );

        public static readonly Guid GUID_BATTERY_DISCHARGE_ACTION_1__scanned__ = new Guid(0xD8742DCB, 0x3E6A, 0x4B3C, 0xB3, 0xFE, 0x37, 0x46, 0x23, 0xCD, 0xCF, 0x06 );

        public static readonly Guid GUID_BATTERY_DISCHARGE_LEVEL_1__scanned__ = new Guid(0x8183BA9A, 0xE910, 0x48DA, 0x87, 0x69, 0x14, 0xAE, 0x6D, 0xC1, 0x17, 0x0A );

        public static readonly Guid GUID_BATTERY_DISCHARGE_FLAGS_1__scanned__ = new Guid(0xbcded951, 0x187b, 0x4d05, 0xbc, 0xcc, 0xf7, 0xe5, 0x19, 0x60, 0xc2, 0x58 );

        public static readonly Guid GUID_BATTERY_DISCHARGE_ACTION_2__scanned__ = new Guid(0x421CBA38, 0x1A8E, 0x4881, 0xAC, 0x89, 0xE3, 0x3A, 0x8B, 0x04, 0xEC, 0xE4 );

        public static readonly Guid GUID_BATTERY_DISCHARGE_LEVEL_2__scanned__ = new Guid(0x07A07CA2, 0xADAF, 0x40D7, 0xB0, 0x77, 0x53, 0x3A, 0xAD, 0xED, 0x1B, 0xFA );

        public static readonly Guid GUID_BATTERY_DISCHARGE_FLAGS_2__scanned__ = new Guid(0x7fd2f0c4, 0xfeb7, 0x4da3, 0x81, 0x17, 0xe3, 0xfb, 0xed, 0xc4, 0x65, 0x82 );

        public static readonly Guid GUID_BATTERY_DISCHARGE_ACTION_3__scanned__ = new Guid(0x80472613, 0x9780, 0x455E, 0xB3, 0x08, 0x72, 0xD3, 0x00, 0x3C, 0xF2, 0xF8 );

        public static readonly Guid GUID_BATTERY_DISCHARGE_LEVEL_3__scanned__ = new Guid(0x58AFD5A6, 0xC2DD, 0x47D2, 0x9F, 0xBF, 0xEF, 0x70, 0xCC, 0x5C, 0x59, 0x65 );

        public static readonly Guid GUID_BATTERY_DISCHARGE_FLAGS_3__scanned__ = new Guid(0x73613ccf, 0xdbfa, 0x4279, 0x83, 0x56, 0x49, 0x35, 0xf6, 0xbf, 0x62, 0xf3 );

        public static readonly Guid GUID_PROCESSOR_SETTINGS_SUBGROUP__scanned__ = new Guid(0x54533251, 0x82BE, 0x4824, 0x96, 0xC1, 0x47, 0xB6, 0x0B, 0x74, 0x0D, 0x00 );

        public static readonly Guid GUID_PROCESSOR_THROTTLE_POLICY__scanned__ = new Guid(0x57027304, 0x4AF6, 0x4104, 0x92, 0x60, 0xE3, 0xD9, 0x52, 0x48, 0xFC, 0x36 );

        public const uint PERFSTATE_POLICY_CHANGE_IDEAL = 0;

        public const uint PERFSTATE_POLICY_CHANGE_SINGLE = 1;

        public const uint PERFSTATE_POLICY_CHANGE_ROCKET = 2;

        public const uint PERFSTATE_POLICY_CHANGE_IDEAL_AGGRESSIVE = 3;

        public static readonly Guid GUID_PROCESSOR_THROTTLE_MAXIMUM__scanned__ = new Guid(0xBC5038F7, 0x23E0, 0x4960, 0x96, 0xDA, 0x33, 0xAB, 0xAF, 0x59, 0x35, 0xEC );

        public static readonly Guid GUID_PROCESSOR_THROTTLE_MAXIMUM_1__scanned__ = new Guid(0xBC5038F7, 0x23E0, 0x4960, 0x96, 0xDA, 0x33, 0xAB, 0xAF, 0x59, 0x35, 0xED );

        public static readonly Guid GUID_PROCESSOR_THROTTLE_MINIMUM__scanned__ = new Guid(0x893DEE8E, 0x2BEF, 0x41E0, 0x89, 0xC6, 0xB5, 0x5D, 0x09, 0x29, 0x96, 0x4C );

        public static readonly Guid GUID_PROCESSOR_THROTTLE_MINIMUM_1__scanned__ = new Guid(0x893DEE8E, 0x2BEF, 0x41E0, 0x89, 0xC6, 0xB5, 0x5D, 0x09, 0x29, 0x96, 0x4D );

        public static readonly Guid GUID_PROCESSOR_FREQUENCY_LIMIT__scanned__ = new Guid(0x75b0ae3f, 0xbce0, 0x45a7, 0x8c, 0x89, 0xc9, 0x61, 0x1c, 0x25, 0xe1, 0x00);

        public static readonly Guid GUID_PROCESSOR_FREQUENCY_LIMIT_1__scanned__ = new Guid(0x75b0ae3f, 0xbce0, 0x45a7, 0x8c, 0x89, 0xc9, 0x61, 0x1c, 0x25, 0xe1, 0x01);

        public static readonly Guid GUID_PROCESSOR_ALLOW_THROTTLING__scanned__ = new Guid(0x3b04d4fd, 0x1cc7, 0x4f23, 0xab, 0x1c, 0xd1, 0x33, 0x78, 0x19, 0xc4, 0xbb );

        public const uint PROCESSOR_THROTTLE_DISABLED = 0;

        public const uint PROCESSOR_THROTTLE_ENABLED = 1;

        public const uint PROCESSOR_THROTTLE_AUTOMATIC = 2;

        public static readonly Guid GUID_PROCESSOR_IDLESTATE_POLICY__scanned__ = new Guid(0x68f262a7, 0xf621, 0x4069, 0xb9, 0xa5, 0x48, 0x74, 0x16, 0x9b, 0xe2, 0x3c);

        public static readonly Guid GUID_PROCESSOR_PERFSTATE_POLICY__scanned__ = new Guid(0xBBDC3814, 0x18E9, 0x4463, 0x8A, 0x55, 0xD1, 0x97, 0x32, 0x7C, 0x45, 0xC0);

        public static readonly Guid GUID_PROCESSOR_PERF_INCREASE_THRESHOLD__scanned__ = new Guid(0x06cadf0e, 0x64ed, 0x448a, 0x89, 0x27, 0xce, 0x7b, 0xf9, 0x0e, 0xb3, 0x5d );

        public static readonly Guid GUID_PROCESSOR_PERF_INCREASE_THRESHOLD_1__scanned__ = new Guid(0x06cadf0e, 0x64ed, 0x448a, 0x89, 0x27, 0xce, 0x7b, 0xf9, 0x0e, 0xb3, 0x5e );

        public static readonly Guid GUID_PROCESSOR_PERF_DECREASE_THRESHOLD__scanned__ = new Guid(0x12a0ab44, 0xfe28, 0x4fa9, 0xb3, 0xbd, 0x4b, 0x64, 0xf4, 0x49, 0x60, 0xa6 );

        public static readonly Guid GUID_PROCESSOR_PERF_DECREASE_THRESHOLD_1__scanned__ = new Guid(0x12a0ab44, 0xfe28, 0x4fa9, 0xb3, 0xbd, 0x4b, 0x64, 0xf4, 0x49, 0x60, 0xa7 );

        public static readonly Guid GUID_PROCESSOR_PERF_INCREASE_POLICY__scanned__ = new Guid(0x465e1f50, 0xb610, 0x473a, 0xab, 0x58, 0x0, 0xd1, 0x7, 0x7d, 0xc4, 0x18);

        public static readonly Guid GUID_PROCESSOR_PERF_INCREASE_POLICY_1__scanned__ = new Guid(0x465e1f50, 0xb610, 0x473a, 0xab, 0x58, 0x0, 0xd1, 0x7, 0x7d, 0xc4, 0x19);

        public static readonly Guid GUID_PROCESSOR_PERF_DECREASE_POLICY__scanned__ = new Guid(0x40fbefc7, 0x2e9d, 0x4d25, 0xa1, 0x85, 0xc, 0xfd, 0x85, 0x74, 0xba, 0xc6);

        public static readonly Guid GUID_PROCESSOR_PERF_DECREASE_POLICY_1__scanned__ = new Guid(0x40fbefc7, 0x2e9d, 0x4d25, 0xa1, 0x85, 0xc, 0xfd, 0x85, 0x74, 0xba, 0xc7);

        public static readonly Guid GUID_PROCESSOR_PERF_INCREASE_TIME__scanned__ = new Guid(0x984cf492, 0x3bed, 0x4488, 0xa8, 0xf9, 0x42, 0x86, 0xc9, 0x7b, 0xf5, 0xaa);

        public static readonly Guid GUID_PROCESSOR_PERF_INCREASE_TIME_1__scanned__ = new Guid(0x984cf492, 0x3bed, 0x4488, 0xa8, 0xf9, 0x42, 0x86, 0xc9, 0x7b, 0xf5, 0xab);

        public static readonly Guid GUID_PROCESSOR_PERF_DECREASE_TIME__scanned__ = new Guid(0xd8edeb9b, 0x95cf, 0x4f95, 0xa7, 0x3c, 0xb0, 0x61, 0x97, 0x36, 0x93, 0xc8);

        public static readonly Guid GUID_PROCESSOR_PERF_DECREASE_TIME_1__scanned__ = new Guid(0xd8edeb9b, 0x95cf, 0x4f95, 0xa7, 0x3c, 0xb0, 0x61, 0x97, 0x36, 0x93, 0xc9);

        public static readonly Guid GUID_PROCESSOR_PERF_TIME_CHECK__scanned__ = new Guid(0x4d2b0152, 0x7d5c, 0x498b, 0x88, 0xe2, 0x34, 0x34, 0x53, 0x92, 0xa2, 0xc5);

        public static readonly Guid GUID_PROCESSOR_PERF_BOOST_POLICY__scanned__ = new Guid(0x45bcc044, 0xd885, 0x43e2, 0x86, 0x5, 0xee, 0xe, 0xc6, 0xe9, 0x6b, 0x59);

        public const uint PROCESSOR_PERF_BOOST_POLICY_DISABLED = 0;

        public const uint PROCESSOR_PERF_BOOST_POLICY_MAX = 100;

        public static readonly Guid GUID_PROCESSOR_PERF_BOOST_MODE__scanned__ = new Guid(0xbe337238, 0xd82, 0x4146, 0xa9, 0x60, 0x4f, 0x37, 0x49, 0xd4, 0x70, 0xc7);

        public const uint PROCESSOR_PERF_BOOST_MODE_DISABLED = 0;

        public const uint PROCESSOR_PERF_BOOST_MODE_ENABLED = 1;

        public const uint PROCESSOR_PERF_BOOST_MODE_AGGRESSIVE = 2;

        public const uint PROCESSOR_PERF_BOOST_MODE_EFFICIENT_ENABLED = 3;

        public const uint PROCESSOR_PERF_BOOST_MODE_EFFICIENT_AGGRESSIVE = 4;

        public const uint PROCESSOR_PERF_BOOST_MODE_AGGRESSIVE_AT_GUARANTEED = 5;

        public const uint PROCESSOR_PERF_BOOST_MODE_EFFICIENT_AGGRESSIVE_AT_GUARANTEED = 6;

        public static readonly Guid GUID_PROCESSOR_PERF_AUTONOMOUS_MODE__scanned__ = new Guid(0x8baa4a8a, 0x14c6, 0x4451, 0x8e, 0x8b, 0x14, 0xbd, 0xbd, 0x19, 0x75, 0x37);

        public const uint PROCESSOR_PERF_AUTONOMOUS_MODE_DISABLED = 0;

        public const uint PROCESSOR_PERF_AUTONOMOUS_MODE_ENABLED = 1;

        public static readonly Guid GUID_PROCESSOR_PERF_ENERGY_PERFORMANCE_PREFERENCE__scanned__ = new Guid(0x36687f9e, 0xe3a5, 0x4dbf, 0xb1, 0xdc, 0x15, 0xeb, 0x38, 0x1c, 0x68, 0x63);

        public static readonly Guid GUID_PROCESSOR_PERF_ENERGY_PERFORMANCE_PREFERENCE_1__scanned__ = new Guid(0x36687f9e, 0xe3a5, 0x4dbf, 0xb1, 0xdc, 0x15, 0xeb, 0x38, 0x1c, 0x68, 0x64);

        public const uint PROCESSOR_PERF_PERFORMANCE_PREFERENCE = 0xff;

        public const uint PROCESSOR_PERF_ENERGY_PREFERENCE = 0;

        public static readonly Guid GUID_PROCESSOR_PERF_AUTONOMOUS_ACTIVITY_WINDOW__scanned__ = new Guid(0xcfeda3d0, 0x7697, 0x4566, 0xa9, 0x22, 0xa9, 0x8, 0x6c, 0xd4, 0x9d, 0xfa);

        public const uint PROCESSOR_PERF_MINIMUM_ACTIVITY_WINDOW = 0;

        public const uint PROCESSOR_PERF_MAXIMUM_ACTIVITY_WINDOW = 1270000000;

        public static readonly Guid GUID_PROCESSOR_DUTY_CYCLING__scanned__ = new Guid(0x4e4450b3, 0x6179, 0x4e91, 0xb8, 0xf1, 0x5b, 0xb9, 0x93, 0x8f, 0x81, 0xa1);

        public const uint PROCESSOR_DUTY_CYCLING_DISABLED = 0;

        public const uint PROCESSOR_DUTY_CYCLING_ENABLED = 1;

        public static readonly Guid GUID_PROCESSOR_IDLE_ALLOW_SCALING__scanned__ = new Guid(0x6c2993b0, 0x8f48, 0x481f, 0xbc, 0xc6, 0x0, 0xdd, 0x27, 0x42, 0xaa, 0x6);

        public static readonly Guid GUID_PROCESSOR_IDLE_DISABLE__scanned__ = new Guid(0x5d76a2ca, 0xe8c0, 0x402f, 0xa1, 0x33, 0x21, 0x58, 0x49, 0x2d, 0x58, 0xad);

        public static readonly Guid GUID_PROCESSOR_IDLE_STATE_MAXIMUM__scanned__ = new Guid(0x9943e905, 0x9a30, 0x4ec1, 0x9b, 0x99, 0x44, 0xdd, 0x3b, 0x76, 0xf7, 0xa2);

        public static readonly Guid GUID_PROCESSOR_IDLE_TIME_CHECK__scanned__ = new Guid(0xc4581c31, 0x89ab, 0x4597, 0x8e, 0x2b, 0x9c, 0x9c, 0xab, 0x44, 0xe, 0x6b);

        public static readonly Guid GUID_PROCESSOR_IDLE_DEMOTE_THRESHOLD__scanned__ = new Guid(0x4b92d758, 0x5a24, 0x4851, 0xa4, 0x70, 0x81, 0x5d, 0x78, 0xae, 0xe1, 0x19);

        public static readonly Guid GUID_PROCESSOR_IDLE_PROMOTE_THRESHOLD__scanned__ = new Guid(0x7b224883, 0xb3cc, 0x4d79, 0x81, 0x9f, 0x83, 0x74, 0x15, 0x2c, 0xbe, 0x7c);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_INCREASE_THRESHOLD__scanned__ = new Guid(0xdf142941, 0x20f3, 0x4edf, 0x9a, 0x4a, 0x9c, 0x83, 0xd3, 0xd7, 0x17, 0xd1 );

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_DECREASE_THRESHOLD__scanned__ = new Guid(0x68dd2f27, 0xa4ce, 0x4e11, 0x84, 0x87, 0x37, 0x94, 0xe4, 0x13, 0x5d, 0xfa);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_INCREASE_POLICY__scanned__ = new Guid(0xc7be0679, 0x2817, 0x4d69, 0x9d, 0x02, 0x51, 0x9a, 0x53, 0x7e, 0xd0, 0xc6);

        public const uint CORE_PARKING_POLICY_CHANGE_IDEAL = 0;

        public const uint CORE_PARKING_POLICY_CHANGE_SINGLE = 1;

        public const uint CORE_PARKING_POLICY_CHANGE_ROCKET = 2;

        public const uint CORE_PARKING_POLICY_CHANGE_MULTISTEP = 3;

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_DECREASE_POLICY__scanned__ = new Guid(0x71021b41, 0xc749, 0x4d21, 0xbe, 0x74, 0xa0, 0x0f, 0x33, 0x5d, 0x58, 0x2b);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_MAX_CORES__scanned__ = new Guid(0xea062031, 0x0e34, 0x4ff1, 0x9b, 0x6d, 0xeb, 0x10, 0x59, 0x33, 0x40, 0x28);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_MAX_CORES_1__scanned__ = new Guid(0xea062031, 0x0e34, 0x4ff1, 0x9b, 0x6d, 0xeb, 0x10, 0x59, 0x33, 0x40, 0x29);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_MIN_CORES__scanned__ = new Guid(0x0cc5b647, 0xc1df, 0x4637, 0x89, 0x1a, 0xde, 0xc3, 0x5c, 0x31, 0x85, 0x83);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_MIN_CORES_1__scanned__ = new Guid(0x0cc5b647, 0xc1df, 0x4637, 0x89, 0x1a, 0xde, 0xc3, 0x5c, 0x31, 0x85, 0x84);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_INCREASE_TIME__scanned__ = new Guid(0x2ddd5a84, 0x5a71, 0x437e, 0x91, 0x2a, 0xdb, 0x0b, 0x8c, 0x78, 0x87, 0x32);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_DECREASE_TIME__scanned__ = new Guid(0xdfd10d17, 0xd5eb, 0x45dd, 0x87, 0x7a, 0x9a, 0x34, 0xdd, 0xd1, 0x5c, 0x82);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_DECREASE_FACTOR__scanned__ = new Guid(0x8f7b45e3, 0xc393, 0x480a, 0x87, 0x8c, 0xf6, 0x7a, 0xc3, 0xd0, 0x70, 0x82);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_THRESHOLD__scanned__ = new Guid(0x5b33697b, 0xe89d, 0x4d38, 0xaa, 0x46, 0x9e, 0x7d, 0xfb, 0x7c, 0xd2, 0xf9);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_AFFINITY_WEIGHTING__scanned__ = new Guid(0xe70867f1, 0xfa2f, 0x4f4e, 0xae, 0xa1, 0x4d, 0x8a, 0x0b, 0xa2, 0x3b, 0x20);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_DECREASE_FACTOR__scanned__ = new Guid(0x1299023c, 0xbc28, 0x4f0a, 0x81, 0xec, 0xd3, 0x29, 0x5a, 0x8d, 0x81, 0x5d);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_THRESHOLD__scanned__ = new Guid(0x9ac18e92, 0xaa3c, 0x4e27, 0xb3, 0x07, 0x01, 0xae, 0x37, 0x30, 0x71, 0x29);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_WEIGHTING__scanned__ = new Guid(0x8809c2d8, 0xb155, 0x42d4, 0xbc, 0xda, 0x0d, 0x34, 0x56, 0x51, 0xb1, 0xdb);

        public static readonly Guid GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_THRESHOLD__scanned__ = new Guid(0x943c8cb6, 0x6f93, 0x4227, 0xad, 0x87, 0xe9, 0xa3, 0xfe, 0xec, 0x08, 0xd1);

        public static readonly Guid GUID_PROCESSOR_PARKING_CORE_OVERRIDE__scanned__ = new Guid(0xa55612aa, 0xf624, 0x42c6, 0xa4, 0x43, 0x73, 0x97, 0xd0, 0x64, 0xc0, 0x4f);

        public static readonly Guid GUID_PROCESSOR_PARKING_PERF_STATE__scanned__ = new Guid(0x447235c7, 0x6a8d, 0x4cc0, 0x8e, 0x24, 0x9e, 0xaf, 0x70, 0xb9, 0x6e, 0x2b);

        public static readonly Guid GUID_PROCESSOR_PARKING_PERF_STATE_1__scanned__ = new Guid(0x447235c7, 0x6a8d, 0x4cc0, 0x8e, 0x24, 0x9e, 0xaf, 0x70, 0xb9, 0x6e, 0x2c);

        public static readonly Guid GUID_PROCESSOR_PARKING_CONCURRENCY_THRESHOLD__scanned__ = new Guid(0x2430ab6f, 0xa520, 0x44a2, 0x96, 0x01, 0xf7, 0xf2, 0x3b, 0x51, 0x34, 0xb1);

        public static readonly Guid GUID_PROCESSOR_PARKING_HEADROOM_THRESHOLD__scanned__ = new Guid(0xf735a673, 0x2066, 0x4f80, 0xa0, 0xc5, 0xdd, 0xee, 0x0c, 0xf1, 0xbf, 0x5d);

        public static readonly Guid GUID_PROCESSOR_PARKING_DISTRIBUTION_THRESHOLD__scanned__ = new Guid(0x4bdaf4e9, 0xd103, 0x46d7, 0xa5, 0xf0, 0x62, 0x80, 0x12, 0x16, 0x16, 0xef);

        public static readonly Guid GUID_PROCESSOR_SOFT_PARKING_LATENCY__scanned__ = new Guid(0x97cfac41, 0x2217, 0x47eb, 0x99, 0x2d, 0x61, 0x8b, 0x19, 0x77, 0xc9, 0x7);

        public static readonly Guid GUID_PROCESSOR_PERF_HISTORY__scanned__ = new Guid(0x7d24baa7, 0x0b84, 0x480f, 0x84, 0x0c, 0x1b, 0x07, 0x43, 0xc0, 0x0f, 0x5f);

        public static readonly Guid GUID_PROCESSOR_PERF_HISTORY_1__scanned__ = new Guid(0x7d24baa7, 0x0b84, 0x480f, 0x84, 0x0c, 0x1b, 0x07, 0x43, 0xc0, 0x0f, 0x60);

        public static readonly Guid GUID_PROCESSOR_PERF_INCREASE_HISTORY__scanned__ = new Guid(0x99b3ef01, 0x752f, 0x46a1, 0x80, 0xfb, 0x77, 0x30, 0x1, 0x1f, 0x23, 0x54);

        public static readonly Guid GUID_PROCESSOR_PERF_DECREASE_HISTORY__scanned__ = new Guid(0x300f6f8, 0xabd6, 0x45a9, 0xb7, 0x4f, 0x49, 0x8, 0x69, 0x1a, 0x40, 0xb5);

        public static readonly Guid GUID_PROCESSOR_PERF_CORE_PARKING_HISTORY__scanned__ = new Guid(0x77d7f282, 0x8f1a, 0x42cd, 0x85, 0x37, 0x45, 0x45, 0xa, 0x83, 0x9b, 0xe8);

        public static readonly Guid GUID_PROCESSOR_PERF_LATENCY_HINT__scanned__ = new Guid(0x0822df31, 0x9c83, 0x441c, 0xa0, 0x79, 0x0d, 0xe4, 0xcf, 0x00, 0x9c, 0x7b);

        public static readonly Guid GUID_PROCESSOR_PERF_LATENCY_HINT_PERF__scanned__ = new Guid(0x619b7505, 0x3b, 0x4e82, 0xb7, 0xa6, 0x4d, 0xd2, 0x9c, 0x30, 0x9, 0x71);

        public static readonly Guid GUID_PROCESSOR_PERF_LATENCY_HINT_PERF_1__scanned__ = new Guid(0x619b7505, 0x3b, 0x4e82, 0xb7, 0xa6, 0x4d, 0xd2, 0x9c, 0x30, 0x9, 0x72);

        public static readonly Guid GUID_PROCESSOR_LATENCY_HINT_MIN_UNPARK__scanned__ = new Guid(0x616cdaa5, 0x695e, 0x4545, 0x97, 0xad, 0x97, 0xdc, 0x2d, 0x1b, 0xdd, 0x88);

        public static readonly Guid GUID_PROCESSOR_LATENCY_HINT_MIN_UNPARK_1__scanned__ = new Guid(0x616cdaa5, 0x695e, 0x4545, 0x97, 0xad, 0x97, 0xdc, 0x2d, 0x1b, 0xdd, 0x89);

        public static readonly Guid GUID_PROCESSOR_DISTRIBUTE_UTILITY__scanned__ = new Guid(0xe0007330, 0xf589, 0x42ed, 0xa4, 0x01, 0x5d, 0xdb, 0x10, 0xe7, 0x85, 0xd3);

        public static readonly Guid GUID_PROCESSOR_HETEROGENEOUS_POLICY__scanned__ = new Guid(0x7f2f5cfa, 0xf10c, 0x4823, 0xb5, 0xe1, 0xe9, 0x3a, 0xe8, 0x5f, 0x46, 0xb5);

        public static readonly Guid GUID_PROCESSOR_HETERO_DECREASE_TIME__scanned__ = new Guid(0x7f2492b6, 0x60b1, 0x45e5, 0xae, 0x55, 0x77, 0x3f, 0x8c, 0xd5, 0xca, 0xec);

        public static readonly Guid GUID_PROCESSOR_HETERO_INCREASE_TIME__scanned__ = new Guid(0x4009efa7, 0xe72d, 0x4cba, 0x9e, 0xdf, 0x91, 0x08, 0x4e, 0xa8, 0xcb, 0xc3);

        public static readonly Guid GUID_PROCESSOR_HETERO_DECREASE_THRESHOLD__scanned__ = new Guid(0xf8861c27, 0x95e7, 0x475c, 0x86, 0x5b, 0x13, 0xc0, 0xcb, 0x3f, 0x9d, 0x6b);

        public static readonly Guid GUID_PROCESSOR_HETERO_INCREASE_THRESHOLD__scanned__ = new Guid(0xb000397d, 0x9b0b, 0x483d, 0x98, 0xc9, 0x69, 0x2a, 0x60, 0x60, 0xcf, 0xbf);

        public static readonly Guid GUID_PROCESSOR_CLASS0_FLOOR_PERF__scanned__ = new Guid(0xfddc842b, 0x8364, 0x4edc, 0x94, 0xcf, 0xc1, 0x7f, 0x60, 0xde, 0x1c, 0x80);

        public static readonly Guid GUID_PROCESSOR_CLASS1_INITIAL_PERF__scanned__ = new Guid(0x1facfc65, 0xa930, 0x4bc5, 0x9f, 0x38, 0x50, 0x4e, 0xc0, 0x97, 0xbb, 0xc0);

        public static readonly Guid GUID_PROCESSOR_THREAD_SCHEDULING_POLICY__scanned__ = new Guid(0x93b8b6dc, 0x698, 0x4d1c, 0x9e, 0xe4, 0x6, 0x44, 0xe9, 0x0, 0xc8, 0x5d);

        public static readonly Guid GUID_PROCESSOR_SHORT_THREAD_SCHEDULING_POLICY__scanned__ = new Guid(0xbae08b81, 0x2d5e, 0x4688, 0xad, 0x6a, 0x13, 0x24, 0x33, 0x56, 0x65, 0x4b);

        public static readonly Guid GUID_SYSTEM_COOLING_POLICY__scanned__ = new Guid(0x94D3A615, 0xA899, 0x4AC5, 0xAE, 0x2B, 0xE4, 0xD8, 0xF6, 0x34, 0x36, 0x7F);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_DISABLE_THRESHOLD__scanned__ = new Guid(0x38b8383d, 0xcce0, 0x4c79, 0x9e, 0x3e, 0x56, 0xa4, 0xf1, 0x7c, 0xc4, 0x80);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_DISABLE_THRESHOLD_1__scanned__ = new Guid(0x38b8383d, 0xcce0, 0x4c79, 0x9e, 0x3e, 0x56, 0xa4, 0xf1, 0x7c, 0xc4, 0x81);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_ENABLE_THRESHOLD__scanned__ = new Guid(0x3d44e256, 0x7222, 0x4415, 0xa9, 0xed, 0x9c, 0x45, 0xfa, 0x3d, 0xd8, 0x30);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_ENABLE_THRESHOLD_1__scanned__ = new Guid(0x3d44e256, 0x7222, 0x4415, 0xa9, 0xed, 0x9c, 0x45, 0xfa, 0x3d, 0xd8, 0x31);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_DISABLE_TIME__scanned__ = new Guid(0xf565999f, 0x3fb0, 0x411a, 0xa2, 0x26, 0x3f, 0x1, 0x98, 0xde, 0xc1, 0x30);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_DISABLE_TIME_1__scanned__ = new Guid(0xf565999f, 0x3fb0, 0x411a, 0xa2, 0x26, 0x3f, 0x1, 0x98, 0xde, 0xc1, 0x31);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_ENABLE_TIME__scanned__ = new Guid(0x3d915188, 0x7830, 0x49ae, 0xa7, 0x9a, 0xf, 0xb0, 0xa1, 0xe5, 0xa2, 0x0);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_ENABLE_TIME_1__scanned__ = new Guid(0x3d915188, 0x7830, 0x49ae, 0xa7, 0x9a, 0xf, 0xb0, 0xa1, 0xe5, 0xa2, 0x1);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_EPP_CEILING__scanned__ = new Guid(0x4427c73b, 0x9756, 0x4a5c, 0xb8, 0x4b, 0xc7, 0xbd, 0xa7, 0x9c, 0x73, 0x20);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_EPP_CEILING_1__scanned__ = new Guid(0x4427c73b, 0x9756, 0x4a5c, 0xb8, 0x4b, 0xc7, 0xbd, 0xa7, 0x9c, 0x73, 0x21);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_PERF_FLOOR__scanned__ = new Guid(0xce8e92ee, 0x6a86, 0x4572, 0xbf, 0xe0, 0x20, 0xc2, 0x1d, 0x3, 0xcd, 0x40);

        public static readonly Guid GUID_PROCESSOR_RESPONSIVENESS_PERF_FLOOR_1__scanned__ = new Guid(0xce8e92ee, 0x6a86, 0x4572, 0xbf, 0xe0, 0x20, 0xc2, 0x1d, 0x3, 0xcd, 0x41);

        public static readonly Guid GUID_LOCK_CONSOLE_ON_WAKE__scanned__ = new Guid(0x0E796BDB, 0x100D, 0x47D6, 0xA2, 0xD5, 0xF7, 0xD2, 0xDA, 0xA5, 0x1F, 0x51 );

        public static readonly Guid GUID_DEVICE_IDLE_POLICY__scanned__ = new Guid(0x4faab71a, 0x92e5, 0x4726, 0xb5, 0x31, 0x22, 0x45, 0x59, 0x67, 0x2d, 0x19 );

        public const uint POWER_DEVICE_IDLE_POLICY_PERFORMANCE = 0;

        public const uint POWER_DEVICE_IDLE_POLICY_CONSERVATIVE = 1;

        public static readonly Guid GUID_CONNECTIVITY_IN_STANDBY__scanned__ = new Guid(0xF15576E8, 0x98B7, 0x4186, 0xB9, 0x44, 0xEA, 0xFA, 0x66, 0x44, 0x02, 0xD9 );

        public const uint POWER_CONNECTIVITY_IN_STANDBY_DISABLED = 0;

        public const uint POWER_CONNECTIVITY_IN_STANDBY_ENABLED = 1;

        public const uint POWER_CONNECTIVITY_IN_STANDBY_SYSTEM_MANAGED = 2;

        public static readonly Guid GUID_DISCONNECTED_STANDBY_MODE__scanned__ = new Guid(0x68AFB2D9, 0xEE95, 0x47A8, 0x8F, 0x50, 0x41, 0x15, 0x08, 0x80, 0x73, 0xB1 );

        public const uint POWER_DISCONNECTED_STANDBY_MODE_NORMAL = 0;

        public const uint POWER_DISCONNECTED_STANDBY_MODE_AGGRESSIVE = 1;

        public static readonly Guid GUID_ACDC_POWER_SOURCE__scanned__ = new Guid(0x5D3E9A59, 0xE9D5, 0x4B00, 0xA6, 0xBD, 0xFF, 0x34, 0xFF, 0x51, 0x65, 0x48 );

        public static readonly Guid GUID_LIDSWITCH_STATE_CHANGE__scanned__ = new Guid(0xBA3E0F4D, 0xB817, 0x4094, 0xA2, 0xD1, 0xD5, 0x63, 0x79, 0xE6, 0xA0, 0xF3 );

        public static readonly Guid GUID_BATTERY_PERCENTAGE_REMAINING__scanned__ = new Guid(0xA7AD8041, 0xB45A, 0x4CAE, 0x87, 0xA3, 0xEE, 0xCB, 0xB4, 0x68, 0xA9, 0xE1 );

        public static readonly Guid GUID_BATTERY_COUNT__scanned__ = new Guid(0x7d263f15, 0xfca4, 0x49e5, 0x85, 0x4b, 0xa9, 0xf2, 0xbf, 0xbd, 0x5c, 0x24 );

        public static readonly Guid GUID_GLOBAL_USER_PRESENCE__scanned__ = new Guid(0x786e8a1d, 0xb427, 0x4344, 0x92, 0x7, 0x9, 0xe7, 0xb, 0xdc, 0xbe, 0xa9 );

        public static readonly Guid GUID_SESSION_DISPLAY_STATUS__scanned__ = new Guid(0x2b84c20e, 0xad23, 0x4ddf, 0x93, 0xdb, 0x5, 0xff, 0xbd, 0x7e, 0xfc, 0xa5 );

        public static readonly Guid GUID_SESSION_USER_PRESENCE__scanned__ = new Guid(0x3c0f4548, 0xc03f, 0x4c4d, 0xb9, 0xf2, 0x23, 0x7e, 0xde, 0x68, 0x63, 0x76 );

        public static readonly Guid GUID_IDLE_BACKGROUND_TASK__scanned__ = new Guid(0x515C31D8, 0xF734, 0x163D, 0xA0, 0xFD, 0x11, 0xA0, 0x8C, 0x91, 0xE8, 0xF1 );

        public static readonly Guid GUID_BACKGROUND_TASK_NOTIFICATION__scanned__ = new Guid(0xCF23F240, 0x2A54, 0x48D8, 0xB1, 0x14, 0xDE, 0x15, 0x18, 0xFF, 0x05, 0x2E );

        public static readonly Guid GUID_APPLAUNCH_BUTTON__scanned__ = new Guid(0x1A689231, 0x7399, 0x4E9A, 0x8F, 0x99, 0xB7, 0x1F, 0x99, 0x9D, 0xB3, 0xFA );

        public static readonly Guid GUID_PCIEXPRESS_SETTINGS_SUBGROUP__scanned__ = new Guid(0x501a4d13, 0x42af,0x4429, 0x9f, 0xd1, 0xa8, 0x21, 0x8c, 0x26, 0x8e, 0x20 );

        public static readonly Guid GUID_PCIEXPRESS_ASPM_POLICY__scanned__ = new Guid(0xee12f906, 0xd277, 0x404b, 0xb6, 0xda, 0xe5, 0xfa, 0x1a, 0x57, 0x6d, 0xf5 );

        public static readonly Guid GUID_ENABLE_SWITCH_FORCED_SHUTDOWN__scanned__ = new Guid(0x833a6b62, 0xdfa4, 0x46d1, 0x82, 0xf8, 0xe0, 0x9e, 0x34, 0xd0, 0x29, 0xd6 );

        public static readonly Guid GUID_INTSTEER_SUBGROUP__scanned__ = new Guid(0x48672f38, 0x7a9a, 0x4bb2, 0x8b, 0xf8, 0x3d, 0x85, 0xbe, 0x19, 0xde, 0x4e);

        public static readonly Guid GUID_INTSTEER_MODE__scanned__ = new Guid(0x2bfc24f9, 0x5ea2, 0x4801, 0x82, 0x13, 0x3d, 0xba, 0xe0, 0x1a, 0xa3, 0x9d);

        public static readonly Guid GUID_INTSTEER_LOAD_PER_PROC_TRIGGER__scanned__ = new Guid(0x73cde64d, 0xd720, 0x4bb2, 0xa8, 0x60, 0xc7, 0x55, 0xaf, 0xe7, 0x7e, 0xf2);

        public static readonly Guid GUID_INTSTEER_TIME_UNPARK_TRIGGER__scanned__ = new Guid(0xd6ba4903, 0x386f, 0x4c2c, 0x8a, 0xdb, 0x5c, 0x21, 0xb3, 0x32, 0x8d, 0x25);

        public static readonly Guid GUID_GRAPHICS_SUBGROUP__scanned__ = new Guid(0x5fb4938d, 0x1ee8, 0x4b0f, 0x9a, 0x3c, 0x50, 0x36, 0xb0, 0xab, 0x99, 0x5c);

        public static readonly Guid GUID_GPU_PREFERENCE_POLICY__scanned__ = new Guid(0xdd848b2a, 0x8a5d, 0x4451, 0x9a, 0xe2, 0x39, 0xcd, 0x41, 0x65, 0x8f, 0x6c);

        public static readonly Guid GUID_MIXED_REALITY_MODE__scanned__ = new Guid(0x1e626b4e, 0xcf04, 0x4f8d, 0x9c, 0xc7, 0xc9, 0x7c, 0x5b, 0xf, 0x23, 0x91);

        public static readonly Guid GUID_SPR_ACTIVE_SESSION_CHANGE__scanned__ = new Guid(0xe24ce38, 0xc393, 0x4742, 0xbd, 0xb1, 0x74, 0x4f, 0x4b, 0x9e, 0xe0, 0x8e);

        public const uint POWER_SYSTEM_MAXIMUM = 7;

        public const uint DIAGNOSTIC_REASON_VERSION = 0;

        public const uint DIAGNOSTIC_REASON_SIMPLE_STRING = 0x00000001;

        public const uint DIAGNOSTIC_REASON_DETAILED_STRING = 0x00000002;

        public const uint DIAGNOSTIC_REASON_NOT_SPECIFIED = 0x80000000;

        public const uint PDCAP_D0_SUPPORTED = 0x00000001;

        public const uint PDCAP_D1_SUPPORTED = 0x00000002;

        public const uint PDCAP_D2_SUPPORTED = 0x00000004;

        public const uint PDCAP_D3_SUPPORTED = 0x00000008;

        public const uint PDCAP_WAKE_FROM_D0_SUPPORTED = 0x00000010;

        public const uint PDCAP_WAKE_FROM_D1_SUPPORTED = 0x00000020;

        public const uint PDCAP_WAKE_FROM_D2_SUPPORTED = 0x00000040;

        public const uint PDCAP_WAKE_FROM_D3_SUPPORTED = 0x00000080;

        public const uint PDCAP_WARM_EJECT_SUPPORTED = 0x00000100;

        public const uint POWER_SETTING_VALUE_VERSION = 0x1;

        public const uint PROC_IDLE_BUCKET_COUNT = 6;

        public const uint PROC_IDLE_BUCKET_COUNT_EX = 16;

        public const uint ACPI_PPM_SOFTWARE_ALL = 0xFC;

        public const uint ACPI_PPM_SOFTWARE_ANY = 0xFD;

        public const uint ACPI_PPM_HARDWARE_ALL = 0xFE;

        public const uint MS_PPM_SOFTWARE_ALL = 0x1;

        public const uint PPM_FIRMWARE_ACPI1C2 = 0x00000001;

        public const uint PPM_FIRMWARE_ACPI1C3 = 0x00000002;

        public const uint PPM_FIRMWARE_ACPI1TSTATES = 0x00000004;

        public const uint PPM_FIRMWARE_CST = 0x00000008;

        public const uint PPM_FIRMWARE_CSD = 0x00000010;

        public const uint PPM_FIRMWARE_PCT = 0x00000020;

        public const uint PPM_FIRMWARE_PSS = 0x00000040;

        public const uint PPM_FIRMWARE_XPSS = 0x00000080;

        public const uint PPM_FIRMWARE_PPC = 0x00000100;

        public const uint PPM_FIRMWARE_PSD = 0x00000200;

        public const uint PPM_FIRMWARE_PTC = 0x00000400;

        public const uint PPM_FIRMWARE_TSS = 0x00000800;

        public const uint PPM_FIRMWARE_TPC = 0x00001000;

        public const uint PPM_FIRMWARE_TSD = 0x00002000;

        public const uint PPM_FIRMWARE_PCCH = 0x00004000;

        public const uint PPM_FIRMWARE_PCCP = 0x00008000;

        public const uint PPM_FIRMWARE_OSC = 0x00010000;

        public const uint PPM_FIRMWARE_PDC = 0x00020000;

        public const uint PPM_FIRMWARE_CPC = 0x00040000;

        public const uint PPM_FIRMWARE_LPI = 0x00080000;

        public const uint PPM_PERFORMANCE_IMPLEMENTATION_NONE = 0x00000000;

        public const uint PPM_PERFORMANCE_IMPLEMENTATION_PSTATES = 0x00000001;

        public const uint PPM_PERFORMANCE_IMPLEMENTATION_PCCV1 = 0x00000002;

        public const uint PPM_PERFORMANCE_IMPLEMENTATION_CPPC = 0x00000003;

        public const uint PPM_PERFORMANCE_IMPLEMENTATION_PEP = 0x00000004;

        public const uint PPM_IDLE_IMPLEMENTATION_NONE = 0x00000000;

        public const uint PPM_IDLE_IMPLEMENTATION_CSTATES = 0x00000001;

        public const uint PPM_IDLE_IMPLEMENTATION_PEP = 0x00000002;

        public const uint PPM_IDLE_IMPLEMENTATION_MICROPEP = 0x00000003;

        public const uint PPM_IDLE_IMPLEMENTATION_LPISTATES = 0x00000004;

        public static readonly Guid PPM_PERFSTATE_CHANGE_GUID__scanned__ = new Guid(0xa5b32ddd, 0x7f39, 0x4abc, 0xb8, 0x92, 0x90, 0xe, 0x43, 0xb5, 0x9e, 0xbb);

        public static readonly Guid PPM_PERFSTATE_DOMAIN_CHANGE_GUID__scanned__ = new Guid(0x995e6b7f, 0xd653, 0x497a, 0xb9, 0x78, 0x36, 0xa3, 0xc, 0x29, 0xbf, 0x1);

        public static readonly Guid PPM_IDLESTATE_CHANGE_GUID__scanned__ = new Guid(0x4838fe4f, 0xf71c, 0x4e51, 0x9e, 0xcc, 0x84, 0x30, 0xa7, 0xac, 0x4c, 0x6c);

        public static readonly Guid PPM_PERFSTATES_DATA_GUID__scanned__ = new Guid(0x5708cc20, 0x7d40, 0x4bf4, 0xb4, 0xaa, 0x2b, 0x01, 0x33, 0x8d, 0x01, 0x26);

        public static readonly Guid PPM_IDLESTATES_DATA_GUID__scanned__ = new Guid(0xba138e10, 0xe250, 0x4ad7, 0x86, 0x16, 0xcf, 0x1a, 0x7a, 0xd4, 0x10, 0xe7);

        public static readonly Guid PPM_IDLE_ACCOUNTING_GUID__scanned__ = new Guid(0xe2a26f78, 0xae07, 0x4ee0, 0xa3, 0x0f, 0xce, 0x54, 0xf5, 0x5a, 0x94, 0xcd);

        public static readonly Guid PPM_IDLE_ACCOUNTING_EX_GUID__scanned__ = new Guid(0xd67abd39, 0x81f8, 0x4a5e, 0x81, 0x52, 0x72, 0xe3, 0x1e, 0xc9, 0x12, 0xee);

        public static readonly Guid PPM_THERMALCONSTRAINT_GUID__scanned__ = new Guid(0xa852c2c8, 0x1a4c, 0x423b, 0x8c, 0x2c, 0xf3, 0x0d, 0x82, 0x93, 0x1a, 0x88);

        public static readonly Guid PPM_PERFMON_PERFSTATE_GUID__scanned__ = new Guid(0x7fd18652, 0xcfe, 0x40d2, 0xb0, 0xa1, 0xb, 0x6, 0x6a, 0x87, 0x75, 0x9e);

        public static readonly Guid PPM_THERMAL_POLICY_CHANGE_GUID__scanned__ = new Guid(0x48f377b8, 0x6880, 0x4c7b, 0x8b, 0xdc, 0x38, 0x1, 0x76, 0xc6, 0x65, 0x4d);

        public const uint POWER_ACTION_QUERY_ALLOWED = 0x00000001;

        public const uint POWER_ACTION_UI_ALLOWED = 0x00000002;

        public const uint POWER_ACTION_OVERRIDE_APPS = 0x00000004;

        public const uint POWER_ACTION_HIBERBOOT = 0x00000008;

        public const uint POWER_ACTION_USER_NOTIFY = 0x00000010;

        public const uint POWER_ACTION_DOZE_TO_HIBERNATE = 0x00000020;

        public const uint POWER_ACTION_ACPI_CRITICAL = 0x01000000;

        public const uint POWER_ACTION_ACPI_USER_NOTIFY = 0x02000000;

        public const uint POWER_ACTION_DIRECTED_DRIPS = 0x04000000;

        public const uint POWER_ACTION_PSEUDO_TRANSITION = 0x08000000;

        public const uint POWER_ACTION_LIGHTEST_FIRST = 0x10000000;

        public const uint POWER_ACTION_LOCK_CONSOLE = 0x20000000;

        public const uint POWER_ACTION_DISABLE_WAKES = 0x40000000;

        public const uint POWER_ACTION_CRITICAL = 0x80000000;

        public const uint POWER_USER_NOTIFY_FORCED_SHUTDOWN = 0x00000020;

        public const uint BATTERY_DISCHARGE_FLAGS_EVENTCODE_MASK = 0x00000007;

        public const uint BATTERY_DISCHARGE_FLAGS_ENABLE = 0x80000000;

        public const uint NUM_DISCHARGE_POLICIES = 4;

        public const uint DISCHARGE_POLICY_CRITICAL = 0;

        public const uint DISCHARGE_POLICY_LOW = 1;

        public const uint PROCESSOR_IDLESTATE_POLICY_COUNT = 0x3;

        public const uint PO_THROTTLE_NONE = 0;

        public const uint PO_THROTTLE_CONSTANT = 1;

        public const uint PO_THROTTLE_DEGRADE = 2;

        public const uint PO_THROTTLE_ADAPTIVE = 3;

        public const uint PO_THROTTLE_MAXIMUM = 4;

        public const uint HIBERFILE_TYPE_NONE = 0x00;

        public const uint HIBERFILE_TYPE_REDUCED = 0x01;

        public const uint HIBERFILE_TYPE_FULL = 0x02;

        public const uint HIBERFILE_TYPE_MAX = 0x03;

        public const uint IMAGE_DOS_SIGNATURE = 0x5A4D;

        public const uint IMAGE_OS2_SIGNATURE = 0x454E;

        public const uint IMAGE_OS2_SIGNATURE_LE = 0x454C;

        public const uint IMAGE_VXD_SIGNATURE = 0x454C;

        public const uint IMAGE_NT_SIGNATURE = 0x00004550;

        public const uint IMAGE_SIZEOF_FILE_HEADER = 20;

        public const uint IMAGE_NUMBEROF_DIRECTORY_ENTRIES = 16;

        public const uint IMAGE_SIZEOF_SHORT_NAME = 8;

        public const uint IMAGE_SIZEOF_SECTION_HEADER = 40;

        public const uint IMAGE_SIZEOF_SYMBOL = 18;

        public const uint IMAGE_SYM_SECTION_MAX = 0xFEFF;

        public const uint IMAGE_SYM_TYPE_NULL = 0x0000;

        public const uint IMAGE_SYM_TYPE_VOID = 0x0001;

        public const uint IMAGE_SYM_TYPE_CHAR = 0x0002;

        public const uint IMAGE_SYM_TYPE_SHORT = 0x0003;

        public const uint IMAGE_SYM_TYPE_INT = 0x0004;

        public const uint IMAGE_SYM_TYPE_LONG = 0x0005;

        public const uint IMAGE_SYM_TYPE_FLOAT = 0x0006;

        public const uint IMAGE_SYM_TYPE_DOUBLE = 0x0007;

        public const uint IMAGE_SYM_TYPE_STRUCT = 0x0008;

        public const uint IMAGE_SYM_TYPE_UNION = 0x0009;

        public const uint IMAGE_SYM_TYPE_ENUM = 0x000A;

        public const uint IMAGE_SYM_TYPE_MOE = 0x000B;

        public const uint IMAGE_SYM_TYPE_BYTE = 0x000C;

        public const uint IMAGE_SYM_TYPE_WORD = 0x000D;

        public const uint IMAGE_SYM_TYPE_UINT = 0x000E;

        public const uint IMAGE_SYM_TYPE_DWORD = 0x000F;

        public const uint IMAGE_SYM_TYPE_PCODE = 0x8000;

        public const uint IMAGE_SYM_DTYPE_NULL = 0;

        public const uint IMAGE_SYM_DTYPE_POINTER = 1;

        public const uint IMAGE_SYM_DTYPE_FUNCTION = 2;

        public const uint IMAGE_SYM_DTYPE_ARRAY = 3;

        public const uint IMAGE_SYM_CLASS_NULL = 0x0000;

        public const uint IMAGE_SYM_CLASS_AUTOMATIC = 0x0001;

        public const uint IMAGE_SYM_CLASS_EXTERNAL = 0x0002;

        public const uint IMAGE_SYM_CLASS_STATIC = 0x0003;

        public const uint IMAGE_SYM_CLASS_REGISTER = 0x0004;

        public const uint IMAGE_SYM_CLASS_EXTERNAL_DEF = 0x0005;

        public const uint IMAGE_SYM_CLASS_LABEL = 0x0006;

        public const uint IMAGE_SYM_CLASS_UNDEFINED_LABEL = 0x0007;

        public const uint IMAGE_SYM_CLASS_MEMBER_OF_STRUCT = 0x0008;

        public const uint IMAGE_SYM_CLASS_ARGUMENT = 0x0009;

        public const uint IMAGE_SYM_CLASS_STRUCT_TAG = 0x000A;

        public const uint IMAGE_SYM_CLASS_MEMBER_OF_UNION = 0x000B;

        public const uint IMAGE_SYM_CLASS_UNION_TAG = 0x000C;

        public const uint IMAGE_SYM_CLASS_TYPE_DEFINITION = 0x000D;

        public const uint IMAGE_SYM_CLASS_UNDEFINED_STATIC = 0x000E;

        public const uint IMAGE_SYM_CLASS_ENUM_TAG = 0x000F;

        public const uint IMAGE_SYM_CLASS_MEMBER_OF_ENUM = 0x0010;

        public const uint IMAGE_SYM_CLASS_REGISTER_PARAM = 0x0011;

        public const uint IMAGE_SYM_CLASS_BIT_FIELD = 0x0012;

        public const uint IMAGE_SYM_CLASS_FAR_EXTERNAL = 0x0044;

        public const uint IMAGE_SYM_CLASS_BLOCK = 0x0064;

        public const uint IMAGE_SYM_CLASS_FUNCTION = 0x0065;

        public const uint IMAGE_SYM_CLASS_END_OF_STRUCT = 0x0066;

        public const uint IMAGE_SYM_CLASS_FILE = 0x0067;

        public const uint IMAGE_SYM_CLASS_SECTION = 0x0068;

        public const uint IMAGE_SYM_CLASS_WEAK_EXTERNAL = 0x0069;

        public const uint IMAGE_SYM_CLASS_CLR_TOKEN = 0x006B;

        public const uint N_BTMASK = 0x000F;

        public const uint N_TMASK = 0x0030;

        public const uint N_TMASK1 = 0x00C0;

        public const uint N_TMASK2 = 0x00F0;

        public const uint N_BTSHFT = 4;

        public const uint N_TSHIFT = 2;

        public const uint IMAGE_COMDAT_SELECT_NODUPLICATES = 1;

        public const uint IMAGE_COMDAT_SELECT_ANY = 2;

        public const uint IMAGE_COMDAT_SELECT_SAME_SIZE = 3;

        public const uint IMAGE_COMDAT_SELECT_EXACT_MATCH = 4;

        public const uint IMAGE_COMDAT_SELECT_ASSOCIATIVE = 5;

        public const uint IMAGE_COMDAT_SELECT_LARGEST = 6;

        public const uint IMAGE_COMDAT_SELECT_NEWEST = 7;

        public const uint IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY = 1;

        public const uint IMAGE_WEAK_EXTERN_SEARCH_LIBRARY = 2;

        public const uint IMAGE_WEAK_EXTERN_SEARCH_ALIAS = 3;

        public const uint IMAGE_WEAK_EXTERN_ANTI_DEPENDENCY = 4;

        public const uint IMAGE_REL_I386_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_I386_DIR16 = 0x0001;

        public const uint IMAGE_REL_I386_REL16 = 0x0002;

        public const uint IMAGE_REL_I386_DIR32 = 0x0006;

        public const uint IMAGE_REL_I386_DIR32NB = 0x0007;

        public const uint IMAGE_REL_I386_SEG12 = 0x0009;

        public const uint IMAGE_REL_I386_SECTION = 0x000A;

        public const uint IMAGE_REL_I386_SECREL = 0x000B;

        public const uint IMAGE_REL_I386_TOKEN = 0x000C;

        public const uint IMAGE_REL_I386_SECREL7 = 0x000D;

        public const uint IMAGE_REL_I386_REL32 = 0x0014;

        public const uint IMAGE_REL_MIPS_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_MIPS_REFHALF = 0x0001;

        public const uint IMAGE_REL_MIPS_REFWORD = 0x0002;

        public const uint IMAGE_REL_MIPS_JMPADDR = 0x0003;

        public const uint IMAGE_REL_MIPS_REFHI = 0x0004;

        public const uint IMAGE_REL_MIPS_REFLO = 0x0005;

        public const uint IMAGE_REL_MIPS_GPREL = 0x0006;

        public const uint IMAGE_REL_MIPS_LITERAL = 0x0007;

        public const uint IMAGE_REL_MIPS_SECTION = 0x000A;

        public const uint IMAGE_REL_MIPS_SECREL = 0x000B;

        public const uint IMAGE_REL_MIPS_SECRELLO = 0x000C;

        public const uint IMAGE_REL_MIPS_SECRELHI = 0x000D;

        public const uint IMAGE_REL_MIPS_TOKEN = 0x000E;

        public const uint IMAGE_REL_MIPS_JMPADDR16 = 0x0010;

        public const uint IMAGE_REL_MIPS_REFWORDNB = 0x0022;

        public const uint IMAGE_REL_MIPS_PAIR = 0x0025;

        public const uint IMAGE_REL_ALPHA_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_ALPHA_REFLONG = 0x0001;

        public const uint IMAGE_REL_ALPHA_REFQUAD = 0x0002;

        public const uint IMAGE_REL_ALPHA_GPREL32 = 0x0003;

        public const uint IMAGE_REL_ALPHA_LITERAL = 0x0004;

        public const uint IMAGE_REL_ALPHA_LITUSE = 0x0005;

        public const uint IMAGE_REL_ALPHA_GPDISP = 0x0006;

        public const uint IMAGE_REL_ALPHA_BRADDR = 0x0007;

        public const uint IMAGE_REL_ALPHA_HINT = 0x0008;

        public const uint IMAGE_REL_ALPHA_INLINE_REFLONG = 0x0009;

        public const uint IMAGE_REL_ALPHA_REFHI = 0x000A;

        public const uint IMAGE_REL_ALPHA_REFLO = 0x000B;

        public const uint IMAGE_REL_ALPHA_PAIR = 0x000C;

        public const uint IMAGE_REL_ALPHA_MATCH = 0x000D;

        public const uint IMAGE_REL_ALPHA_SECTION = 0x000E;

        public const uint IMAGE_REL_ALPHA_SECREL = 0x000F;

        public const uint IMAGE_REL_ALPHA_REFLONGNB = 0x0010;

        public const uint IMAGE_REL_ALPHA_SECRELLO = 0x0011;

        public const uint IMAGE_REL_ALPHA_SECRELHI = 0x0012;

        public const uint IMAGE_REL_ALPHA_REFQ3 = 0x0013;

        public const uint IMAGE_REL_ALPHA_REFQ2 = 0x0014;

        public const uint IMAGE_REL_ALPHA_REFQ1 = 0x0015;

        public const uint IMAGE_REL_ALPHA_GPRELLO = 0x0016;

        public const uint IMAGE_REL_ALPHA_GPRELHI = 0x0017;

        public const uint IMAGE_REL_PPC_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_PPC_ADDR64 = 0x0001;

        public const uint IMAGE_REL_PPC_ADDR32 = 0x0002;

        public const uint IMAGE_REL_PPC_ADDR24 = 0x0003;

        public const uint IMAGE_REL_PPC_ADDR16 = 0x0004;

        public const uint IMAGE_REL_PPC_ADDR14 = 0x0005;

        public const uint IMAGE_REL_PPC_REL24 = 0x0006;

        public const uint IMAGE_REL_PPC_REL14 = 0x0007;

        public const uint IMAGE_REL_PPC_TOCREL16 = 0x0008;

        public const uint IMAGE_REL_PPC_TOCREL14 = 0x0009;

        public const uint IMAGE_REL_PPC_ADDR32NB = 0x000A;

        public const uint IMAGE_REL_PPC_SECREL = 0x000B;

        public const uint IMAGE_REL_PPC_SECTION = 0x000C;

        public const uint IMAGE_REL_PPC_IFGLUE = 0x000D;

        public const uint IMAGE_REL_PPC_IMGLUE = 0x000E;

        public const uint IMAGE_REL_PPC_SECREL16 = 0x000F;

        public const uint IMAGE_REL_PPC_REFHI = 0x0010;

        public const uint IMAGE_REL_PPC_REFLO = 0x0011;

        public const uint IMAGE_REL_PPC_PAIR = 0x0012;

        public const uint IMAGE_REL_PPC_SECRELLO = 0x0013;

        public const uint IMAGE_REL_PPC_SECRELHI = 0x0014;

        public const uint IMAGE_REL_PPC_GPREL = 0x0015;

        public const uint IMAGE_REL_PPC_TOKEN = 0x0016;

        public const uint IMAGE_REL_PPC_TYPEMASK = 0x00FF;

        public const uint IMAGE_REL_PPC_NEG = 0x0100;

        public const uint IMAGE_REL_PPC_BRTAKEN = 0x0200;

        public const uint IMAGE_REL_PPC_BRNTAKEN = 0x0400;

        public const uint IMAGE_REL_PPC_TOCDEFN = 0x0800;

        public const uint IMAGE_REL_SH3_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_SH3_DIRECT16 = 0x0001;

        public const uint IMAGE_REL_SH3_DIRECT32 = 0x0002;

        public const uint IMAGE_REL_SH3_DIRECT8 = 0x0003;

        public const uint IMAGE_REL_SH3_DIRECT8_WORD = 0x0004;

        public const uint IMAGE_REL_SH3_DIRECT8_LONG = 0x0005;

        public const uint IMAGE_REL_SH3_DIRECT4 = 0x0006;

        public const uint IMAGE_REL_SH3_DIRECT4_WORD = 0x0007;

        public const uint IMAGE_REL_SH3_DIRECT4_LONG = 0x0008;

        public const uint IMAGE_REL_SH3_PCREL8_WORD = 0x0009;

        public const uint IMAGE_REL_SH3_PCREL8_LONG = 0x000A;

        public const uint IMAGE_REL_SH3_PCREL12_WORD = 0x000B;

        public const uint IMAGE_REL_SH3_STARTOF_SECTION = 0x000C;

        public const uint IMAGE_REL_SH3_SIZEOF_SECTION = 0x000D;

        public const uint IMAGE_REL_SH3_SECTION = 0x000E;

        public const uint IMAGE_REL_SH3_SECREL = 0x000F;

        public const uint IMAGE_REL_SH3_DIRECT32_NB = 0x0010;

        public const uint IMAGE_REL_SH3_GPREL4_LONG = 0x0011;

        public const uint IMAGE_REL_SH3_TOKEN = 0x0012;

        public const uint IMAGE_REL_SHM_PCRELPT = 0x0013;

        public const uint IMAGE_REL_SHM_REFLO = 0x0014;

        public const uint IMAGE_REL_SHM_REFHALF = 0x0015;

        public const uint IMAGE_REL_SHM_RELLO = 0x0016;

        public const uint IMAGE_REL_SHM_RELHALF = 0x0017;

        public const uint IMAGE_REL_SHM_PAIR = 0x0018;

        public const uint IMAGE_REL_SH_NOMODE = 0x8000;

        public const uint IMAGE_REL_ARM_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_ARM_ADDR32 = 0x0001;

        public const uint IMAGE_REL_ARM_ADDR32NB = 0x0002;

        public const uint IMAGE_REL_ARM_BRANCH24 = 0x0003;

        public const uint IMAGE_REL_ARM_BRANCH11 = 0x0004;

        public const uint IMAGE_REL_ARM_TOKEN = 0x0005;

        public const uint IMAGE_REL_ARM_GPREL12 = 0x0006;

        public const uint IMAGE_REL_ARM_GPREL7 = 0x0007;

        public const uint IMAGE_REL_ARM_BLX24 = 0x0008;

        public const uint IMAGE_REL_ARM_BLX11 = 0x0009;

        public const uint IMAGE_REL_ARM_SECTION = 0x000E;

        public const uint IMAGE_REL_ARM_SECREL = 0x000F;

        public const uint IMAGE_REL_ARM_MOV32A = 0x0010;

        public const uint IMAGE_REL_ARM_MOV32 = 0x0010;

        public const uint IMAGE_REL_ARM_MOV32T = 0x0011;

        public const uint IMAGE_REL_THUMB_MOV32 = 0x0011;

        public const uint IMAGE_REL_ARM_BRANCH20T = 0x0012;

        public const uint IMAGE_REL_THUMB_BRANCH20 = 0x0012;

        public const uint IMAGE_REL_ARM_BRANCH24T = 0x0014;

        public const uint IMAGE_REL_THUMB_BRANCH24 = 0x0014;

        public const uint IMAGE_REL_ARM_BLX23T = 0x0015;

        public const uint IMAGE_REL_THUMB_BLX23 = 0x0015;

        public const uint IMAGE_REL_AM_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_AM_ADDR32 = 0x0001;

        public const uint IMAGE_REL_AM_ADDR32NB = 0x0002;

        public const uint IMAGE_REL_AM_CALL32 = 0x0003;

        public const uint IMAGE_REL_AM_FUNCINFO = 0x0004;

        public const uint IMAGE_REL_AM_REL32_1 = 0x0005;

        public const uint IMAGE_REL_AM_REL32_2 = 0x0006;

        public const uint IMAGE_REL_AM_SECREL = 0x0007;

        public const uint IMAGE_REL_AM_SECTION = 0x0008;

        public const uint IMAGE_REL_AM_TOKEN = 0x0009;

        public const uint IMAGE_REL_ARM64_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_ARM64_ADDR32 = 0x0001;

        public const uint IMAGE_REL_ARM64_ADDR32NB = 0x0002;

        public const uint IMAGE_REL_ARM64_BRANCH26 = 0x0003;

        public const uint IMAGE_REL_ARM64_PAGEBASE_REL21 = 0x0004;

        public const uint IMAGE_REL_ARM64_REL21 = 0x0005;

        public const uint IMAGE_REL_ARM64_PAGEOFFSET_12A = 0x0006;

        public const uint IMAGE_REL_ARM64_PAGEOFFSET_12L = 0x0007;

        public const uint IMAGE_REL_ARM64_SECREL = 0x0008;

        public const uint IMAGE_REL_ARM64_SECREL_LOW12A = 0x0009;

        public const uint IMAGE_REL_ARM64_SECREL_HIGH12A = 0x000A;

        public const uint IMAGE_REL_ARM64_SECREL_LOW12L = 0x000B;

        public const uint IMAGE_REL_ARM64_TOKEN = 0x000C;

        public const uint IMAGE_REL_ARM64_SECTION = 0x000D;

        public const uint IMAGE_REL_ARM64_ADDR64 = 0x000E;

        public const uint IMAGE_REL_ARM64_BRANCH19 = 0x000F;

        public const uint IMAGE_REL_AMD64_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_AMD64_ADDR64 = 0x0001;

        public const uint IMAGE_REL_AMD64_ADDR32 = 0x0002;

        public const uint IMAGE_REL_AMD64_ADDR32NB = 0x0003;

        public const uint IMAGE_REL_AMD64_REL32 = 0x0004;

        public const uint IMAGE_REL_AMD64_REL32_1 = 0x0005;

        public const uint IMAGE_REL_AMD64_REL32_2 = 0x0006;

        public const uint IMAGE_REL_AMD64_REL32_3 = 0x0007;

        public const uint IMAGE_REL_AMD64_REL32_4 = 0x0008;

        public const uint IMAGE_REL_AMD64_REL32_5 = 0x0009;

        public const uint IMAGE_REL_AMD64_SECTION = 0x000A;

        public const uint IMAGE_REL_AMD64_SECREL = 0x000B;

        public const uint IMAGE_REL_AMD64_SECREL7 = 0x000C;

        public const uint IMAGE_REL_AMD64_TOKEN = 0x000D;

        public const uint IMAGE_REL_AMD64_SREL32 = 0x000E;

        public const uint IMAGE_REL_AMD64_PAIR = 0x000F;

        public const uint IMAGE_REL_AMD64_SSPAN32 = 0x0010;

        public const uint IMAGE_REL_AMD64_EHANDLER = 0x0011;

        public const uint IMAGE_REL_AMD64_IMPORT_BR = 0x0012;

        public const uint IMAGE_REL_AMD64_IMPORT_CALL = 0x0013;

        public const uint IMAGE_REL_AMD64_CFG_BR = 0x0014;

        public const uint IMAGE_REL_AMD64_CFG_BR_REX = 0x0015;

        public const uint IMAGE_REL_AMD64_CFG_CALL = 0x0016;

        public const uint IMAGE_REL_AMD64_INDIR_BR = 0x0017;

        public const uint IMAGE_REL_AMD64_INDIR_BR_REX = 0x0018;

        public const uint IMAGE_REL_AMD64_INDIR_CALL = 0x0019;

        public const uint IMAGE_REL_AMD64_INDIR_BR_SWITCHTABLE_FIRST = 0x0020;

        public const uint IMAGE_REL_AMD64_INDIR_BR_SWITCHTABLE_LAST = 0x002F;

        public const uint IMAGE_REL_IA64_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_IA64_IMM14 = 0x0001;

        public const uint IMAGE_REL_IA64_IMM22 = 0x0002;

        public const uint IMAGE_REL_IA64_IMM64 = 0x0003;

        public const uint IMAGE_REL_IA64_DIR32 = 0x0004;

        public const uint IMAGE_REL_IA64_DIR64 = 0x0005;

        public const uint IMAGE_REL_IA64_PCREL21B = 0x0006;

        public const uint IMAGE_REL_IA64_PCREL21M = 0x0007;

        public const uint IMAGE_REL_IA64_PCREL21F = 0x0008;

        public const uint IMAGE_REL_IA64_GPREL22 = 0x0009;

        public const uint IMAGE_REL_IA64_LTOFF22 = 0x000A;

        public const uint IMAGE_REL_IA64_SECTION = 0x000B;

        public const uint IMAGE_REL_IA64_SECREL22 = 0x000C;

        public const uint IMAGE_REL_IA64_SECREL64I = 0x000D;

        public const uint IMAGE_REL_IA64_SECREL32 = 0x000E;

        public const uint IMAGE_REL_IA64_DIR32NB = 0x0010;

        public const uint IMAGE_REL_IA64_SREL14 = 0x0011;

        public const uint IMAGE_REL_IA64_SREL22 = 0x0012;

        public const uint IMAGE_REL_IA64_SREL32 = 0x0013;

        public const uint IMAGE_REL_IA64_UREL32 = 0x0014;

        public const uint IMAGE_REL_IA64_PCREL60X = 0x0015;

        public const uint IMAGE_REL_IA64_PCREL60B = 0x0016;

        public const uint IMAGE_REL_IA64_PCREL60F = 0x0017;

        public const uint IMAGE_REL_IA64_PCREL60I = 0x0018;

        public const uint IMAGE_REL_IA64_PCREL60M = 0x0019;

        public const uint IMAGE_REL_IA64_IMMGPREL64 = 0x001A;

        public const uint IMAGE_REL_IA64_TOKEN = 0x001B;

        public const uint IMAGE_REL_IA64_GPREL32 = 0x001C;

        public const uint IMAGE_REL_IA64_ADDEND = 0x001F;

        public const uint IMAGE_REL_CEF_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_CEF_ADDR32 = 0x0001;

        public const uint IMAGE_REL_CEF_ADDR64 = 0x0002;

        public const uint IMAGE_REL_CEF_ADDR32NB = 0x0003;

        public const uint IMAGE_REL_CEF_SECTION = 0x0004;

        public const uint IMAGE_REL_CEF_SECREL = 0x0005;

        public const uint IMAGE_REL_CEF_TOKEN = 0x0006;

        public const uint IMAGE_REL_CEE_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_CEE_ADDR32 = 0x0001;

        public const uint IMAGE_REL_CEE_ADDR64 = 0x0002;

        public const uint IMAGE_REL_CEE_ADDR32NB = 0x0003;

        public const uint IMAGE_REL_CEE_SECTION = 0x0004;

        public const uint IMAGE_REL_CEE_SECREL = 0x0005;

        public const uint IMAGE_REL_CEE_TOKEN = 0x0006;

        public const uint IMAGE_REL_M32R_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_M32R_ADDR32 = 0x0001;

        public const uint IMAGE_REL_M32R_ADDR32NB = 0x0002;

        public const uint IMAGE_REL_M32R_ADDR24 = 0x0003;

        public const uint IMAGE_REL_M32R_GPREL16 = 0x0004;

        public const uint IMAGE_REL_M32R_PCREL24 = 0x0005;

        public const uint IMAGE_REL_M32R_PCREL16 = 0x0006;

        public const uint IMAGE_REL_M32R_PCREL8 = 0x0007;

        public const uint IMAGE_REL_M32R_REFHALF = 0x0008;

        public const uint IMAGE_REL_M32R_REFHI = 0x0009;

        public const uint IMAGE_REL_M32R_REFLO = 0x000A;

        public const uint IMAGE_REL_M32R_PAIR = 0x000B;

        public const uint IMAGE_REL_M32R_SECTION = 0x000C;

        public const uint IMAGE_REL_M32R_SECREL32 = 0x000D;

        public const uint IMAGE_REL_M32R_TOKEN = 0x000E;

        public const uint IMAGE_REL_EBC_ABSOLUTE = 0x0000;

        public const uint IMAGE_REL_EBC_ADDR32NB = 0x0001;

        public const uint IMAGE_REL_EBC_REL32 = 0x0002;

        public const uint IMAGE_REL_EBC_SECTION = 0x0003;

        public const uint IMAGE_REL_EBC_SECREL = 0x0004;

        public const uint EMARCH_ENC_I17_IMM7B_INST_WORD_X = 3;

        public const uint EMARCH_ENC_I17_IMM7B_SIZE_X = 7;

        public const uint EMARCH_ENC_I17_IMM7B_INST_WORD_POS_X = 4;

        public const uint EMARCH_ENC_I17_IMM7B_VAL_POS_X = 0;

        public const uint EMARCH_ENC_I17_IMM9D_INST_WORD_X = 3;

        public const uint EMARCH_ENC_I17_IMM9D_SIZE_X = 9;

        public const uint EMARCH_ENC_I17_IMM9D_INST_WORD_POS_X = 18;

        public const uint EMARCH_ENC_I17_IMM9D_VAL_POS_X = 7;

        public const uint EMARCH_ENC_I17_IMM5C_INST_WORD_X = 3;

        public const uint EMARCH_ENC_I17_IMM5C_SIZE_X = 5;

        public const uint EMARCH_ENC_I17_IMM5C_INST_WORD_POS_X = 13;

        public const uint EMARCH_ENC_I17_IMM5C_VAL_POS_X = 16;

        public const uint EMARCH_ENC_I17_IC_INST_WORD_X = 3;

        public const uint EMARCH_ENC_I17_IC_SIZE_X = 1;

        public const uint EMARCH_ENC_I17_IC_INST_WORD_POS_X = 12;

        public const uint EMARCH_ENC_I17_IC_VAL_POS_X = 21;

        public const uint EMARCH_ENC_I17_IMM41a_INST_WORD_X = 1;

        public const uint EMARCH_ENC_I17_IMM41a_SIZE_X = 10;

        public const uint EMARCH_ENC_I17_IMM41a_INST_WORD_POS_X = 14;

        public const uint EMARCH_ENC_I17_IMM41a_VAL_POS_X = 22;

        public const uint EMARCH_ENC_I17_IMM41b_INST_WORD_X = 1;

        public const uint EMARCH_ENC_I17_IMM41b_SIZE_X = 8;

        public const uint EMARCH_ENC_I17_IMM41b_INST_WORD_POS_X = 24;

        public const uint EMARCH_ENC_I17_IMM41b_VAL_POS_X = 32;

        public const uint EMARCH_ENC_I17_IMM41c_INST_WORD_X = 2;

        public const uint EMARCH_ENC_I17_IMM41c_SIZE_X = 23;

        public const uint EMARCH_ENC_I17_IMM41c_INST_WORD_POS_X = 0;

        public const uint EMARCH_ENC_I17_IMM41c_VAL_POS_X = 40;

        public const uint EMARCH_ENC_I17_SIGN_INST_WORD_X = 3;

        public const uint EMARCH_ENC_I17_SIGN_SIZE_X = 1;

        public const uint EMARCH_ENC_I17_SIGN_INST_WORD_POS_X = 27;

        public const uint EMARCH_ENC_I17_SIGN_VAL_POS_X = 63;

        public const uint X3_OPCODE_INST_WORD_X = 3;

        public const uint X3_OPCODE_SIZE_X = 4;

        public const uint X3_OPCODE_INST_WORD_POS_X = 28;

        public const uint X3_OPCODE_SIGN_VAL_POS_X = 0;

        public const uint X3_I_INST_WORD_X = 3;

        public const uint X3_I_SIZE_X = 1;

        public const uint X3_I_INST_WORD_POS_X = 27;

        public const uint X3_I_SIGN_VAL_POS_X = 59;

        public const uint X3_D_WH_INST_WORD_X = 3;

        public const uint X3_D_WH_SIZE_X = 3;

        public const uint X3_D_WH_INST_WORD_POS_X = 24;

        public const uint X3_D_WH_SIGN_VAL_POS_X = 0;

        public const uint X3_IMM20_INST_WORD_X = 3;

        public const uint X3_IMM20_SIZE_X = 20;

        public const uint X3_IMM20_INST_WORD_POS_X = 4;

        public const uint X3_IMM20_SIGN_VAL_POS_X = 0;

        public const uint X3_IMM39_1_INST_WORD_X = 2;

        public const uint X3_IMM39_1_SIZE_X = 23;

        public const uint X3_IMM39_1_INST_WORD_POS_X = 0;

        public const uint X3_IMM39_1_SIGN_VAL_POS_X = 36;

        public const uint X3_IMM39_2_INST_WORD_X = 1;

        public const uint X3_IMM39_2_SIZE_X = 16;

        public const uint X3_IMM39_2_INST_WORD_POS_X = 16;

        public const uint X3_IMM39_2_SIGN_VAL_POS_X = 20;

        public const uint X3_P_INST_WORD_X = 3;

        public const uint X3_P_SIZE_X = 4;

        public const uint X3_P_INST_WORD_POS_X = 0;

        public const uint X3_P_SIGN_VAL_POS_X = 0;

        public const uint X3_TMPLT_INST_WORD_X = 0;

        public const uint X3_TMPLT_SIZE_X = 4;

        public const uint X3_TMPLT_INST_WORD_POS_X = 0;

        public const uint X3_TMPLT_SIGN_VAL_POS_X = 0;

        public const uint X3_BTYPE_QP_INST_WORD_X = 2;

        public const uint X3_BTYPE_QP_SIZE_X = 9;

        public const uint X3_BTYPE_QP_INST_WORD_POS_X = 23;

        public const uint X3_BTYPE_QP_INST_VAL_POS_X = 0;

        public const uint X3_EMPTY_INST_WORD_X = 1;

        public const uint X3_EMPTY_SIZE_X = 2;

        public const uint X3_EMPTY_INST_WORD_POS_X = 14;

        public const uint X3_EMPTY_INST_VAL_POS_X = 0;

        public const uint IMAGE_REL_BASED_ABSOLUTE = 0;

        public const uint IMAGE_REL_BASED_HIGH = 1;

        public const uint IMAGE_REL_BASED_LOW = 2;

        public const uint IMAGE_REL_BASED_HIGHLOW = 3;

        public const uint IMAGE_REL_BASED_HIGHADJ = 4;

        public const uint IMAGE_REL_BASED_MACHINE_SPECIFIC_5 = 5;

        public const uint IMAGE_REL_BASED_RESERVED = 6;

        public const uint IMAGE_REL_BASED_MACHINE_SPECIFIC_7 = 7;

        public const uint IMAGE_REL_BASED_MACHINE_SPECIFIC_8 = 8;

        public const uint IMAGE_REL_BASED_MACHINE_SPECIFIC_9 = 9;

        public const uint IMAGE_REL_BASED_DIR64 = 10;

        public const uint IMAGE_REL_BASED_IA64_IMM64 = 9;

        public const uint IMAGE_REL_BASED_MIPS_JMPADDR = 5;

        public const uint IMAGE_REL_BASED_MIPS_JMPADDR16 = 9;

        public const uint IMAGE_REL_BASED_ARM_MOV32 = 5;

        public const uint IMAGE_REL_BASED_THUMB_MOV32 = 7;

        public const uint IMAGE_ARCHIVE_START_SIZE = 8;

        public const uint IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR = 60;

        public const ulong IMAGE_ORDINAL_FLAG64 = 0x8000000000000000;

        public const uint IMAGE_ORDINAL_FLAG32 = 0x80000000;

        public const uint IMAGE_RESOURCE_NAME_IS_STRING = 0x80000000;

        public const uint IMAGE_RESOURCE_DATA_IS_DIRECTORY = 0x80000000;

        public const uint IMAGE_DYNAMIC_RELOCATION_GUARD_RF_PROLOGUE = 0x00000001;

        public const uint IMAGE_DYNAMIC_RELOCATION_GUARD_RF_EPILOGUE = 0x00000002;

        public const uint IMAGE_DYNAMIC_RELOCATION_GUARD_IMPORT_CONTROL_TRANSFER = 0x00000003;

        public const uint IMAGE_DYNAMIC_RELOCATION_GUARD_INDIR_CONTROL_TRANSFER = 0x00000004;

        public const uint IMAGE_DYNAMIC_RELOCATION_GUARD_SWITCHTABLE_BRANCH = 0x00000005;

        public const uint IMAGE_HOT_PATCH_BASE_OBLIGATORY = 0x00000001;

        public const uint IMAGE_HOT_PATCH_BASE_CAN_ROLL_BACK = 0x00000002;

        public const uint IMAGE_HOT_PATCH_CHUNK_INVERSE = 0x80000000;

        public const uint IMAGE_HOT_PATCH_CHUNK_OBLIGATORY = 0x40000000;

        public const uint IMAGE_HOT_PATCH_CHUNK_RESERVED = 0x3FF03000;

        public const uint IMAGE_HOT_PATCH_CHUNK_TYPE = 0x000FC000;

        public const uint IMAGE_HOT_PATCH_CHUNK_SOURCE_RVA = 0x00008000;

        public const uint IMAGE_HOT_PATCH_CHUNK_TARGET_RVA = 0x00004000;

        public const uint IMAGE_HOT_PATCH_CHUNK_SIZE = 0x00000FFF;

        public const uint IMAGE_HOT_PATCH_NONE = 0x00000000;

        public const uint IMAGE_HOT_PATCH_FUNCTION = 0x0001C000;

        public const uint IMAGE_HOT_PATCH_ABSOLUTE = 0x0002C000;

        public const uint IMAGE_HOT_PATCH_REL32 = 0x0003C000;

        public const uint IMAGE_HOT_PATCH_CALL_TARGET = 0x00044000;

        public const uint IMAGE_HOT_PATCH_INDIRECT = 0x0005C000;

        public const uint IMAGE_HOT_PATCH_NO_CALL_TARGET = 0x00064000;

        public const uint IMAGE_HOT_PATCH_DYNAMIC_VALUE = 0x00078000;

        public const uint IMAGE_GUARD_CF_INSTRUMENTED = 0x00000100;

        public const uint IMAGE_GUARD_CFW_INSTRUMENTED = 0x00000200;

        public const uint IMAGE_GUARD_CF_FUNCTION_TABLE_PRESENT = 0x00000400;

        public const uint IMAGE_GUARD_SECURITY_COOKIE_UNUSED = 0x00000800;

        public const uint IMAGE_GUARD_PROTECT_DELAYLOAD_IAT = 0x00001000;

        public const uint IMAGE_GUARD_DELAYLOAD_IAT_IN_ITS_OWN_SECTION = 0x00002000;

        public const uint IMAGE_GUARD_CF_EXPORT_SUPPRESSION_INFO_PRESENT = 0x00004000;

        public const uint IMAGE_GUARD_CF_ENABLE_EXPORT_SUPPRESSION = 0x00008000;

        public const uint IMAGE_GUARD_CF_LONGJUMP_TABLE_PRESENT = 0x00010000;

        public const uint IMAGE_GUARD_RF_INSTRUMENTED = 0x00020000;

        public const uint IMAGE_GUARD_RF_ENABLE = 0x00040000;

        public const uint IMAGE_GUARD_RF_STRICT = 0x00080000;

        public const uint IMAGE_GUARD_RETPOLINE_PRESENT = 0x00100000;

        public const uint IMAGE_GUARD_EH_CONTINUATION_TABLE_PRESENT = 0x00200000;

        public const uint IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK = 0xF0000000;

        public const uint IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_SHIFT = 28;

        public const uint IMAGE_GUARD_FLAG_FID_SUPPRESSED = 0x01;

        public const uint IMAGE_GUARD_FLAG_EXPORT_SUPPRESSED = 0x02;

        public const uint IMAGE_ENCLAVE_POLICY_DEBUGGABLE = 0x00000001;

        public const uint IMAGE_ENCLAVE_FLAG_PRIMARY_IMAGE = 0x00000001;

        public const uint IMAGE_ENCLAVE_IMPORT_MATCH_NONE = 0x00000000;

        public const uint IMAGE_ENCLAVE_IMPORT_MATCH_UNIQUE_ID = 0x00000001;

        public const uint IMAGE_ENCLAVE_IMPORT_MATCH_AUTHOR_ID = 0x00000002;

        public const uint IMAGE_ENCLAVE_IMPORT_MATCH_FAMILY_ID = 0x00000003;

        public const uint IMAGE_ENCLAVE_IMPORT_MATCH_IMAGE_ID = 0x00000004;

        public const uint IMAGE_DEBUG_TYPE_OMAP_TO_SRC = 7;

        public const uint IMAGE_DEBUG_TYPE_OMAP_FROM_SRC = 8;

        public const uint IMAGE_DEBUG_TYPE_RESERVED10 = 10;

        public const uint IMAGE_DEBUG_TYPE_CLSID = 11;

        public const uint IMAGE_DEBUG_TYPE_VC_FEATURE = 12;

        public const uint IMAGE_DEBUG_TYPE_POGO = 13;

        public const uint IMAGE_DEBUG_TYPE_ILTCG = 14;

        public const uint IMAGE_DEBUG_TYPE_MPX = 15;

        public const uint IMAGE_DEBUG_TYPE_REPRO = 16;

        public const uint IMAGE_DEBUG_TYPE_EX_DLLCHARACTERISTICS = 20;

        public const uint FRAME_FPO = 0;

        public const uint FRAME_TRAP = 1;

        public const uint FRAME_TSS = 2;

        public const uint FRAME_NONFPO = 3;

        public const uint SIZEOF_RFPO_DATA = 16;

        public const uint IMAGE_DEBUG_MISC_EXENAME = 1;

        public const uint IMAGE_SEPARATE_DEBUG_SIGNATURE = 0x4944;

        public const uint NON_PAGED_DEBUG_SIGNATURE = 0x494E;

        public const uint IMAGE_SEPARATE_DEBUG_FLAGS_MASK = 0x8000;

        public const uint IMAGE_SEPARATE_DEBUG_MISMATCH = 0x8000;

        public const uint IMPORT_OBJECT_HDR_SIG2 = 0xffff;

        public const uint RTL_RUN_ONCE_CHECK_ONLY = 0x00000001;

        public const uint RTL_RUN_ONCE_ASYNC = 0x00000002;

        public const uint RTL_RUN_ONCE_INIT_FAILED = 0x00000004;

        public const uint RTL_RUN_ONCE_CTX_RESERVED_BITS = 2;

        public const uint FAST_FAIL_LEGACY_GS_VIOLATION = 0;

        public const uint FAST_FAIL_VTGUARD_CHECK_FAILURE = 1;

        public const uint FAST_FAIL_STACK_COOKIE_CHECK_FAILURE = 2;

        public const uint FAST_FAIL_CORRUPT_LIST_ENTRY = 3;

        public const uint FAST_FAIL_INCORRECT_STACK = 4;

        public const uint FAST_FAIL_INVALID_ARG = 5;

        public const uint FAST_FAIL_GS_COOKIE_INIT = 6;

        public const uint FAST_FAIL_FATAL_APP_EXIT = 7;

        public const uint FAST_FAIL_RANGE_CHECK_FAILURE = 8;

        public const uint FAST_FAIL_UNSAFE_REGISTRY_ACCESS = 9;

        public const uint FAST_FAIL_GUARD_ICALL_CHECK_FAILURE = 10;

        public const uint FAST_FAIL_GUARD_WRITE_CHECK_FAILURE = 11;

        public const uint FAST_FAIL_INVALID_FIBER_SWITCH = 12;

        public const uint FAST_FAIL_INVALID_SET_OF_CONTEXT = 13;

        public const uint FAST_FAIL_INVALID_REFERENCE_COUNT = 14;

        public const uint FAST_FAIL_INVALID_JUMP_BUFFER = 18;

        public const uint FAST_FAIL_MRDATA_MODIFIED = 19;

        public const uint FAST_FAIL_CERTIFICATION_FAILURE = 20;

        public const uint FAST_FAIL_INVALID_EXCEPTION_CHAIN = 21;

        public const uint FAST_FAIL_CRYPTO_LIBRARY = 22;

        public const uint FAST_FAIL_INVALID_CALL_IN_DLL_CALLOUT = 23;

        public const uint FAST_FAIL_INVALID_IMAGE_BASE = 24;

        public const uint FAST_FAIL_DLOAD_PROTECTION_FAILURE = 25;

        public const uint FAST_FAIL_UNSAFE_EXTENSION_CALL = 26;

        public const uint FAST_FAIL_DEPRECATED_SERVICE_INVOKED = 27;

        public const uint FAST_FAIL_INVALID_BUFFER_ACCESS = 28;

        public const uint FAST_FAIL_INVALID_BALANCED_TREE = 29;

        public const uint FAST_FAIL_INVALID_NEXT_THREAD = 30;

        public const uint FAST_FAIL_GUARD_ICALL_CHECK_SUPPRESSED = 31;

        public const uint FAST_FAIL_APCS_DISABLED = 32;

        public const uint FAST_FAIL_INVALID_IDLE_STATE = 33;

        public const uint FAST_FAIL_MRDATA_PROTECTION_FAILURE = 34;

        public const uint FAST_FAIL_UNEXPECTED_HEAP_EXCEPTION = 35;

        public const uint FAST_FAIL_INVALID_LOCK_STATE = 36;

        public const uint FAST_FAIL_GUARD_JUMPTABLE = 37;

        public const uint FAST_FAIL_INVALID_LONGJUMP_TARGET = 38;

        public const uint FAST_FAIL_INVALID_DISPATCH_CONTEXT = 39;

        public const uint FAST_FAIL_INVALID_THREAD = 40;

        public const uint FAST_FAIL_INVALID_SYSCALL_NUMBER = 41;

        public const uint FAST_FAIL_INVALID_FILE_OPERATION = 42;

        public const uint FAST_FAIL_LPAC_ACCESS_DENIED = 43;

        public const uint FAST_FAIL_GUARD_SS_FAILURE = 44;

        public const uint FAST_FAIL_LOADER_CONTINUITY_FAILURE = 45;

        public const uint FAST_FAIL_GUARD_EXPORT_SUPPRESSION_FAILURE = 46;

        public const uint FAST_FAIL_INVALID_CONTROL_STACK = 47;

        public const uint FAST_FAIL_SET_CONTEXT_DENIED = 48;

        public const uint FAST_FAIL_INVALID_IAT = 49;

        public const uint FAST_FAIL_HEAP_METADATA_CORRUPTION = 50;

        public const uint FAST_FAIL_PAYLOAD_RESTRICTION_VIOLATION = 51;

        public const uint FAST_FAIL_LOW_LABEL_ACCESS_DENIED = 52;

        public const uint FAST_FAIL_ENCLAVE_CALL_FAILURE = 53;

        public const uint FAST_FAIL_UNHANDLED_LSS_EXCEPTON = 54;

        public const uint FAST_FAIL_ADMINLESS_ACCESS_DENIED = 55;

        public const uint FAST_FAIL_UNEXPECTED_CALL = 56;

        public const uint FAST_FAIL_CONTROL_INVALID_RETURN_ADDRESS = 57;

        public const uint FAST_FAIL_UNEXPECTED_HOST_BEHAVIOR = 58;

        public const uint FAST_FAIL_FLAGS_CORRUPTION = 59;

        public const uint FAST_FAIL_VEH_CORRUPTION = 60;

        public const uint FAST_FAIL_ETW_CORRUPTION = 61;

        public const uint FAST_FAIL_RIO_ABORT = 62;

        public const uint FAST_FAIL_INVALID_PFN = 63;

        public const uint FAST_FAIL_INVALID_FAST_FAIL_CODE = 0xFFFFFFFF;

        public const uint IS_TEXT_UNICODE_DBCS_LEADBYTE = 0x0400;

        public const uint COMPRESSION_FORMAT_NONE = 0x0000;

        public const uint COMPRESSION_FORMAT_DEFAULT = 0x0001;

        public const uint COMPRESSION_FORMAT_LZNT1 = 0x0002;

        public const uint COMPRESSION_FORMAT_XPRESS = 0x0003;

        public const uint COMPRESSION_FORMAT_XPRESS_HUFF = 0x0004;

        public const uint COMPRESSION_ENGINE_STANDARD = 0x0000;

        public const uint COMPRESSION_ENGINE_MAXIMUM = 0x0100;

        public const uint COMPRESSION_ENGINE_HIBER = 0x0200;

        public const uint SEF_AI_USE_EXTRA_PARAMS = 0x800;

        public const uint SEF_FORCE_USER_MODE = 0x2000;

        public const uint MESSAGE_RESOURCE_UNICODE = 0x0001;

        public const uint MESSAGE_RESOURCE_UTF8 = 0x0002;

        public const uint VER_EQUAL = 1;

        public const uint VER_GREATER = 2;

        public const uint VER_GREATER_EQUAL = 3;

        public const uint VER_LESS = 4;

        public const uint VER_LESS_EQUAL = 5;

        public const uint VER_AND = 6;

        public const uint VER_OR = 7;

        public const uint VER_CONDITION_MASK = 7;

        public const uint VER_NUM_BITS_PER_CONDITION_MASK = 3;

        public const uint VER_NT_WORKSTATION = 0x0000001;

        public const uint VER_NT_DOMAIN_CONTROLLER = 0x0000002;

        public const uint VER_NT_SERVER = 0x0000003;

        public const uint RTL_UMS_VERSION = 0x0100;

        public const uint VRL_PREDEFINED_CLASS_BEGIN = 1u<< 0;

        public const uint VRL_CUSTOM_CLASS_BEGIN = 1u<< 8;

        public const uint VRL_ENABLE_KERNEL_BREAKS = 1u<< 31;

        public const uint CTMF_INCLUDE_APPCONTAINER = 0x00000001;

        public const uint CTMF_INCLUDE_LPAC = 0x00000002;

        public const uint FLUSH_NV_MEMORY_IN_FLAG_NO_DRAIN = 0x00000001;

        public const uint WRITE_NV_MEMORY_FLAG_FLUSH = 0x00000001;

        public const uint WRITE_NV_MEMORY_FLAG_NON_TEMPORAL = 0x00000002;

        public const uint WRITE_NV_MEMORY_FLAG_NO_DRAIN = 0x00000100;

        public const uint FILL_NV_MEMORY_FLAG_FLUSH = 0x00000001;

        public const uint FILL_NV_MEMORY_FLAG_NON_TEMPORAL = 0x00000002;

        public const uint FILL_NV_MEMORY_FLAG_NO_DRAIN = 0x00000100;

        public const uint RTL_CORRELATION_VECTOR_STRING_LENGTH = 129;

        public const uint RTL_CORRELATION_VECTOR_V1_PREFIX_LENGTH = 16;

        public const uint RTL_CORRELATION_VECTOR_V1_LENGTH = 64;

        public const uint RTL_CORRELATION_VECTOR_V2_PREFIX_LENGTH = 22;

        public const uint RTL_CORRELATION_VECTOR_V2_LENGTH = 128;

        public const uint IMAGE_POLICY_METADATA_VERSION = 1;

        public const uint RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO = 0x01000000;

        public const uint RTL_CRITICAL_SECTION_FLAG_DYNAMIC_SPIN = 0x02000000;

        public const uint RTL_CRITICAL_SECTION_FLAG_STATIC_INIT = 0x04000000;

        public const uint RTL_CRITICAL_SECTION_FLAG_RESOURCE_TYPE = 0x08000000;

        public const uint RTL_CRITICAL_SECTION_FLAG_FORCE_DEBUG_INFO = 0x10000000;

        public const uint RTL_CRITICAL_SECTION_ALL_FLAG_BITS = 0xFF000000;

        public const uint RTL_CRITICAL_SECTION_DEBUG_FLAG_STATIC_INIT = 0x00000001;

        public const uint RTL_CONDITION_VARIABLE_LOCKMODE_SHARED = 0x1;

        public const uint HEAP_OPTIMIZE_RESOURCES_CURRENT_VERSION = 1;

        public const uint WT_EXECUTEINUITHREAD = 0x00000002;

        public const uint WT_EXECUTEINPERSISTENTIOTHREAD = 0x00000040;

        public const uint WT_EXECUTEINLONGTHREAD = 0x00000010;

        public const uint WT_EXECUTEDELETEWAIT = 0x00000008;

        public const uint ACTIVATION_CONTEXT_PATH_TYPE_NONE = 1;

        public const uint ACTIVATION_CONTEXT_PATH_TYPE_WIN32_FILE = 2;

        public const uint ACTIVATION_CONTEXT_PATH_TYPE_URL = 3;

        public const uint ACTIVATION_CONTEXT_PATH_TYPE_ASSEMBLYREF = 4;

        public const uint CREATE_BOUNDARY_DESCRIPTOR_ADD_APPCONTAINER_SID = 0x1;

        public const uint PERFORMANCE_DATA_VERSION = 1;

        public const uint READ_THREAD_PROFILING_FLAG_DISPATCHING = 0x00000001;

        public const uint READ_THREAD_PROFILING_FLAG_HARDWARE_COUNTERS = 0x00000002;

        public const uint UNIFIEDBUILDREVISION_MIN = 0x00000000;

        public const uint DEVICEFAMILYINFOENUM_UAP = 0x00000000;

        public const uint DEVICEFAMILYINFOENUM_WINDOWS_8X = 0x00000001;

        public const uint DEVICEFAMILYINFOENUM_WINDOWS_PHONE_8X = 0x00000002;

        public const uint DEVICEFAMILYINFOENUM_DESKTOP = 0x00000003;

        public const uint DEVICEFAMILYINFOENUM_MOBILE = 0x00000004;

        public const uint DEVICEFAMILYINFOENUM_XBOX = 0x00000005;

        public const uint DEVICEFAMILYINFOENUM_TEAM = 0x00000006;

        public const uint DEVICEFAMILYINFOENUM_IOT = 0x00000007;

        public const uint DEVICEFAMILYINFOENUM_IOT_HEADLESS = 0x00000008;

        public const uint DEVICEFAMILYINFOENUM_SERVER = 0x00000009;

        public const uint DEVICEFAMILYINFOENUM_HOLOGRAPHIC = 0x0000000A;

        public const uint DEVICEFAMILYINFOENUM_XBOXSRA = 0x0000000B;

        public const uint DEVICEFAMILYINFOENUM_XBOXERA = 0x0000000C;

        public const uint DEVICEFAMILYINFOENUM_SERVER_NANO = 0x0000000D;

        public const uint DEVICEFAMILYINFOENUM_8828080 = 0x0000000E;

        public const uint DEVICEFAMILYINFOENUM_7067329 = 0x0000000F;

        public const uint DEVICEFAMILYINFOENUM_WINDOWS_CORE = 0x00000010;

        public const uint DEVICEFAMILYINFOENUM_WINDOWS_CORE_HEADLESS = 0x00000011;

        public const uint DEVICEFAMILYINFOENUM_MAX = 0x00000011;

        public const uint DEVICEFAMILYDEVICEFORM_UNKNOWN = 0x00000000;

        public const uint DEVICEFAMILYDEVICEFORM_PHONE = 0x00000001;

        public const uint DEVICEFAMILYDEVICEFORM_TABLET = 0x00000002;

        public const uint DEVICEFAMILYDEVICEFORM_DESKTOP = 0x00000003;

        public const uint DEVICEFAMILYDEVICEFORM_NOTEBOOK = 0x00000004;

        public const uint DEVICEFAMILYDEVICEFORM_CONVERTIBLE = 0x00000005;

        public const uint DEVICEFAMILYDEVICEFORM_DETACHABLE = 0x00000006;

        public const uint DEVICEFAMILYDEVICEFORM_ALLINONE = 0x00000007;

        public const uint DEVICEFAMILYDEVICEFORM_STICKPC = 0x00000008;

        public const uint DEVICEFAMILYDEVICEFORM_PUCK = 0x00000009;

        public const uint DEVICEFAMILYDEVICEFORM_LARGESCREEN = 0x0000000A;

        public const uint DEVICEFAMILYDEVICEFORM_HMD = 0x0000000B;

        public const uint DEVICEFAMILYDEVICEFORM_INDUSTRY_HANDHELD = 0x0000000C;

        public const uint DEVICEFAMILYDEVICEFORM_INDUSTRY_TABLET = 0x0000000D;

        public const uint DEVICEFAMILYDEVICEFORM_BANKING = 0x0000000E;

        public const uint DEVICEFAMILYDEVICEFORM_BUILDING_AUTOMATION = 0x0000000F;

        public const uint DEVICEFAMILYDEVICEFORM_DIGITAL_SIGNAGE = 0x00000010;

        public const uint DEVICEFAMILYDEVICEFORM_GAMING = 0x00000011;

        public const uint DEVICEFAMILYDEVICEFORM_HOME_AUTOMATION = 0x00000012;

        public const uint DEVICEFAMILYDEVICEFORM_INDUSTRIAL_AUTOMATION = 0x00000013;

        public const uint DEVICEFAMILYDEVICEFORM_KIOSK = 0x00000014;

        public const uint DEVICEFAMILYDEVICEFORM_MAKER_BOARD = 0x00000015;

        public const uint DEVICEFAMILYDEVICEFORM_MEDICAL = 0x00000016;

        public const uint DEVICEFAMILYDEVICEFORM_NETWORKING = 0x00000017;

        public const uint DEVICEFAMILYDEVICEFORM_POINT_OF_SERVICE = 0x00000018;

        public const uint DEVICEFAMILYDEVICEFORM_PRINTING = 0x00000019;

        public const uint DEVICEFAMILYDEVICEFORM_THIN_CLIENT = 0x0000001A;

        public const uint DEVICEFAMILYDEVICEFORM_TOY = 0x0000001B;

        public const uint DEVICEFAMILYDEVICEFORM_VENDING = 0x0000001C;

        public const uint DEVICEFAMILYDEVICEFORM_INDUSTRY_OTHER = 0x0000001D;

        public const uint DEVICEFAMILYDEVICEFORM_XBOX_ONE = 0x0000001E;

        public const uint DEVICEFAMILYDEVICEFORM_XBOX_ONE_S = 0x0000001F;

        public const uint DEVICEFAMILYDEVICEFORM_XBOX_ONE_X = 0x00000020;

        public const uint DEVICEFAMILYDEVICEFORM_XBOX_ONE_X_DEVKIT = 0x00000021;

        public const uint DEVICEFAMILYDEVICEFORM_MAX = 0x00000021;

        public const uint DLL_PROCESS_ATTACH = 1;

        public const uint DLL_THREAD_ATTACH = 2;

        public const uint DLL_THREAD_DETACH = 3;

        public const uint DLL_PROCESS_DETACH = 0;

        public const uint EVENTLOG_FORWARDS_READ = 0x0004;

        public const uint EVENTLOG_BACKWARDS_READ = 0x0008;

        public const uint EVENTLOG_START_PAIRED_EVENT = 0x0001;

        public const uint EVENTLOG_END_PAIRED_EVENT = 0x0002;

        public const uint EVENTLOG_END_ALL_PAIRED_EVENTS = 0x0004;

        public const uint EVENTLOG_PAIRED_EVENT_ACTIVE = 0x0008;

        public const uint EVENTLOG_PAIRED_EVENT_INACTIVE = 0x0010;

        public const uint MAXLOGICALLOGNAMESIZE = 256;

        public const int REG_REFRESH_HIVE = 0x00000002;

        public const int REG_NO_LAZY_FLUSH = 0x00000004;

        public const int REG_APP_HIVE = 0x00000010;

        public const int REG_PROCESS_PRIVATE = 0x00000020;

        public const int REG_START_JOURNAL = 0x00000040;

        public const int REG_HIVE_EXACT_FILE_GROWTH = 0x00000080;

        public const int REG_HIVE_NO_RM = 0x00000100;

        public const int REG_HIVE_SINGLE_LOG = 0x00000200;

        public const int REG_BOOT_HIVE = 0x00000400;

        public const int REG_LOAD_HIVE_OPEN_HANDLE = 0x00000800;

        public const int REG_FLUSH_HIVE_FILE_GROWTH = 0x00001000;

        public const int REG_OPEN_READ_ONLY = 0x00002000;

        public const int REG_IMMUTABLE = 0x00004000;

        public const int REG_NO_IMPERSONATION_FALLBACK = 0x00008000;

        public const uint REG_FORCE_UNLOAD = 1;

        public const uint SERVICE_USER_SERVICE = 0x00000040;

        public const uint SERVICE_USERSERVICE_INSTANCE = 0x00000080;

        public const uint SERVICE_INTERACTIVE_PROCESS = 0x00000100;

        public const uint SERVICE_PKG_SERVICE = 0x00000200;

        public const uint CM_SERVICE_NETWORK_BOOT_LOAD = 0x00000001;

        public const uint CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD = 0x00000002;

        public const uint CM_SERVICE_USB_DISK_BOOT_LOAD = 0x00000004;

        public const uint CM_SERVICE_SD_DISK_BOOT_LOAD = 0x00000008;

        public const uint CM_SERVICE_USB3_DISK_BOOT_LOAD = 0x00000010;

        public const uint CM_SERVICE_MEASURED_BOOT_LOAD = 0x00000020;

        public const uint CM_SERVICE_VERIFIER_BOOT_LOAD = 0x00000040;

        public const uint CM_SERVICE_WINPE_BOOT_LOAD = 0x00000080;

        public const uint CM_SERVICE_RAM_DISK_BOOT_LOAD = 0x00000100;

        public const int TAPE_PSEUDO_LOGICAL_POSITION = 2;

        public const int TAPE_PSEUDO_LOGICAL_BLOCK = 3;

        public const uint TAPE_DRIVE_FIXED = 0x00000001;

        public const uint TAPE_DRIVE_SELECT = 0x00000002;

        public const uint TAPE_DRIVE_INITIATOR = 0x00000004;

        public const uint TAPE_DRIVE_ERASE_SHORT = 0x00000010;

        public const uint TAPE_DRIVE_ERASE_LONG = 0x00000020;

        public const uint TAPE_DRIVE_ERASE_BOP_ONLY = 0x00000040;

        public const uint TAPE_DRIVE_ERASE_IMMEDIATE = 0x00000080;

        public const uint TAPE_DRIVE_TAPE_CAPACITY = 0x00000100;

        public const uint TAPE_DRIVE_TAPE_REMAINING = 0x00000200;

        public const uint TAPE_DRIVE_FIXED_BLOCK = 0x00000400;

        public const uint TAPE_DRIVE_VARIABLE_BLOCK = 0x00000800;

        public const uint TAPE_DRIVE_WRITE_PROTECT = 0x00001000;

        public const uint TAPE_DRIVE_EOT_WZ_SIZE = 0x00002000;

        public const uint TAPE_DRIVE_ECC = 0x00010000;

        public const uint TAPE_DRIVE_COMPRESSION = 0x00020000;

        public const uint TAPE_DRIVE_PADDING = 0x00040000;

        public const uint TAPE_DRIVE_REPORT_SMKS = 0x00080000;

        public const uint TAPE_DRIVE_GET_ABSOLUTE_BLK = 0x00100000;

        public const uint TAPE_DRIVE_GET_LOGICAL_BLK = 0x00200000;

        public const uint TAPE_DRIVE_SET_EOT_WZ_SIZE = 0x00400000;

        public const uint TAPE_DRIVE_EJECT_MEDIA = 0x01000000;

        public const uint TAPE_DRIVE_CLEAN_REQUESTS = 0x02000000;

        public const uint TAPE_DRIVE_SET_CMP_BOP_ONLY = 0x04000000;

        public const uint TAPE_DRIVE_RESERVED_BIT = 0x80000000;

        public const uint TAPE_DRIVE_FORMAT = 0xA0000000;

        public const uint TAPE_DRIVE_FORMAT_IMMEDIATE = 0xC0000000;

        public const uint TAPE_DRIVE_HIGH_FEATURES = 0x80000000;

        public const int TAPE_QUERY_DRIVE_PARAMETERS = 0;

        public const int TAPE_QUERY_MEDIA_CAPACITY = 1;

        public const int TAPE_CHECK_FOR_DRIVE_PROBLEM = 2;

        public const int TAPE_QUERY_IO_ERROR_DATA = 3;

        public const int TAPE_QUERY_DEVICE_ERROR_DATA = 4;

        public const uint TRANSACTIONMANAGER_QUERY_INFORMATION = 0x0001;

        public const uint TRANSACTIONMANAGER_SET_INFORMATION = 0x0002;

        public const uint TRANSACTIONMANAGER_RECOVER = 0x0004;

        public const uint TRANSACTIONMANAGER_RENAME = 0x0008;

        public const uint TRANSACTIONMANAGER_CREATE_RM = 0x0010;

        public const uint TRANSACTIONMANAGER_BIND_TRANSACTION = 0x0020;

        public const uint TRANSACTION_QUERY_INFORMATION = 0x0001;

        public const uint TRANSACTION_SET_INFORMATION = 0x0002;

        public const uint TRANSACTION_ENLIST = 0x0004;

        public const uint TRANSACTION_COMMIT = 0x0008;

        public const uint TRANSACTION_ROLLBACK = 0x0010;

        public const uint TRANSACTION_PROPAGATE = 0x0020;

        public const uint TRANSACTION_RIGHT_RESERVED1 = 0x0040;

        public const uint RESOURCEMANAGER_QUERY_INFORMATION = 0x0001;

        public const uint RESOURCEMANAGER_SET_INFORMATION = 0x0002;

        public const uint RESOURCEMANAGER_RECOVER = 0x0004;

        public const uint RESOURCEMANAGER_ENLIST = 0x0008;

        public const uint RESOURCEMANAGER_GET_NOTIFICATION = 0x0010;

        public const uint RESOURCEMANAGER_REGISTER_PROTOCOL = 0x0020;

        public const uint RESOURCEMANAGER_COMPLETE_PROPAGATION = 0x0040;

        public const uint ENLISTMENT_QUERY_INFORMATION = 0x0001;

        public const uint ENLISTMENT_SET_INFORMATION = 0x0002;

        public const uint ENLISTMENT_RECOVER = 0x0004;

        public const uint ENLISTMENT_SUBORDINATE_RIGHTS = 0x0008;

        public const uint ENLISTMENT_SUPERIOR_RIGHTS = 0x0010;

        public const uint PcTeb = 0x18;

        public const uint ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION = 1;

        public const uint ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION = 2;

        public const uint ACTIVATION_CONTEXT_SECTION_WINDOW_CLASS_REDIRECTION = 3;

        public const uint ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION = 4;

        public const uint ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION = 5;

        public const uint ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION = 6;

        public const uint ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION = 7;

        public const uint ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_TABLE = 8;

        public const uint ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES = 9;

        public const uint ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS = 10;

        public const uint ACTIVATION_CONTEXT_SECTION_COMPATIBILITY_INFO = 11;

        public const uint ACTIVATION_CONTEXT_SECTION_WINRT_ACTIVATABLE_CLASSES = 12;

        [PropertyKey(0xb725f130, 0x47ef, 0x101a, 0xa5, 0xf1, 0x02, 0x60, 0x8c, 0x9e, 0xeb, 0xac, 10)]
        public static readonly PROPERTYKEY DEVPKEY_NAME;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 2)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DeviceDesc;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 3)]
        public static readonly PROPERTYKEY DEVPKEY_Device_HardwareIds;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 4)]
        public static readonly PROPERTYKEY DEVPKEY_Device_CompatibleIds;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 6)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Service;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 9)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Class;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 10)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ClassGuid;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 11)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Driver;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 12)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ConfigFlags;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 13)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Manufacturer;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 14)]
        public static readonly PROPERTYKEY DEVPKEY_Device_FriendlyName;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 15)]
        public static readonly PROPERTYKEY DEVPKEY_Device_LocationInfo;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 16)]
        public static readonly PROPERTYKEY DEVPKEY_Device_PDOName;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 17)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Capabilities;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 18)]
        public static readonly PROPERTYKEY DEVPKEY_Device_UINumber;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 19)]
        public static readonly PROPERTYKEY DEVPKEY_Device_UpperFilters;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 20)]
        public static readonly PROPERTYKEY DEVPKEY_Device_LowerFilters;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 21)]
        public static readonly PROPERTYKEY DEVPKEY_Device_BusTypeGuid;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 22)]
        public static readonly PROPERTYKEY DEVPKEY_Device_LegacyBusType;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 23)]
        public static readonly PROPERTYKEY DEVPKEY_Device_BusNumber;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 24)]
        public static readonly PROPERTYKEY DEVPKEY_Device_EnumeratorName;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 25)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Security;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 26)]
        public static readonly PROPERTYKEY DEVPKEY_Device_SecuritySDS;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 27)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DevType;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 28)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Exclusive;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 29)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Characteristics;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 30)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Address;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 31)]
        public static readonly PROPERTYKEY DEVPKEY_Device_UINumberDescFormat;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 32)]
        public static readonly PROPERTYKEY DEVPKEY_Device_PowerData;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 33)]
        public static readonly PROPERTYKEY DEVPKEY_Device_RemovalPolicy;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 34)]
        public static readonly PROPERTYKEY DEVPKEY_Device_RemovalPolicyDefault;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 35)]
        public static readonly PROPERTYKEY DEVPKEY_Device_RemovalPolicyOverride;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 36)]
        public static readonly PROPERTYKEY DEVPKEY_Device_InstallState;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 37)]
        public static readonly PROPERTYKEY DEVPKEY_Device_LocationPaths;

        [PropertyKey(0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 38)]
        public static readonly PROPERTYKEY DEVPKEY_Device_BaseContainerId;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 256)]
        public static readonly PROPERTYKEY DEVPKEY_Device_InstanceId;

        [PropertyKey(0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 2)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DevNodeStatus;

        [PropertyKey(0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 3)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ProblemCode;

        [PropertyKey(0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 4)]
        public static readonly PROPERTYKEY DEVPKEY_Device_EjectionRelations;

        [PropertyKey(0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 5)]
        public static readonly PROPERTYKEY DEVPKEY_Device_RemovalRelations;

        [PropertyKey(0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 6)]
        public static readonly PROPERTYKEY DEVPKEY_Device_PowerRelations;

        [PropertyKey(0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 7)]
        public static readonly PROPERTYKEY DEVPKEY_Device_BusRelations;

        [PropertyKey(0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 8)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Parent;

        [PropertyKey(0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 9)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Children;

        [PropertyKey(0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 10)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Siblings;

        [PropertyKey(0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 11)]
        public static readonly PROPERTYKEY DEVPKEY_Device_TransportRelations;

        [PropertyKey(0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 12)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ProblemStatus;

        [PropertyKey(0x80497100, 0x8c73, 0x48b9, 0xaa, 0xd9, 0xce, 0x38, 0x7e, 0x19, 0xc5, 0x6e, 2)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Reported;

        [PropertyKey(0x80497100, 0x8c73, 0x48b9, 0xaa, 0xd9, 0xce, 0x38, 0x7e, 0x19, 0xc5, 0x6e, 3)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Legacy;

        [PropertyKey(0x8c7ed206, 0x3f8a, 0x4827, 0xb3, 0xab, 0xae, 0x9e, 0x1f, 0xae, 0xfc, 0x6c, 2)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ContainerId;

        [PropertyKey(0x8c7ed206, 0x3f8a, 0x4827, 0xb3, 0xab, 0xae, 0x9e, 0x1f, 0xae, 0xfc, 0x6c, 4)]
        public static readonly PROPERTYKEY DEVPKEY_Device_InLocalMachineContainer;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 39)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Model;

        [PropertyKey(0x80d81ea6, 0x7473, 0x4b0c, 0x82, 0x16, 0xef, 0xc1, 0x1a, 0x2c, 0x4c, 0x8b, 2)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ModelId;

        [PropertyKey(0x80d81ea6, 0x7473, 0x4b0c, 0x82, 0x16, 0xef, 0xc1, 0x1a, 0x2c, 0x4c, 0x8b, 3)]
        public static readonly PROPERTYKEY DEVPKEY_Device_FriendlyNameAttributes;

        [PropertyKey(0x80d81ea6, 0x7473, 0x4b0c, 0x82, 0x16, 0xef, 0xc1, 0x1a, 0x2c, 0x4c, 0x8b, 4)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ManufacturerAttributes;

        [PropertyKey(0x80d81ea6, 0x7473, 0x4b0c, 0x82, 0x16, 0xef, 0xc1, 0x1a, 0x2c, 0x4c, 0x8b, 5)]
        public static readonly PROPERTYKEY DEVPKEY_Device_PresenceNotForDevice;

        [PropertyKey(0x80d81ea6, 0x7473, 0x4b0c, 0x82, 0x16, 0xef, 0xc1, 0x1a, 0x2c, 0x4c, 0x8b, 6)]
        public static readonly PROPERTYKEY DEVPKEY_Device_SignalStrength;

        [PropertyKey(0x80d81ea6, 0x7473, 0x4b0c, 0x82, 0x16, 0xef, 0xc1, 0x1a, 0x2c, 0x4c, 0x8b, 7)]
        public static readonly PROPERTYKEY DEVPKEY_Device_IsAssociateableByUserAction;

        [PropertyKey(0x80d81ea6, 0x7473, 0x4b0c, 0x82, 0x16, 0xef, 0xc1, 0x1a, 0x2c, 0x4c, 0x8b, 8)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ShowInUninstallUI;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 1)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Numa_Proximity_Domain;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 2)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DHP_Rebalance_Policy;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 3)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Numa_Node;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 4)]
        public static readonly PROPERTYKEY DEVPKEY_Device_BusReportedDeviceDesc;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 5)]
        public static readonly PROPERTYKEY DEVPKEY_Device_IsPresent;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 6)]
        public static readonly PROPERTYKEY DEVPKEY_Device_HasProblem;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 7)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ConfigurationId;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 8)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ReportedDeviceIdsHash;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 9)]
        public static readonly PROPERTYKEY DEVPKEY_Device_PhysicalDeviceLocation;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 10)]
        public static readonly PROPERTYKEY DEVPKEY_Device_BiosDeviceName;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 11)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverProblemDesc;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 12)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DebuggerSafe;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 13)]
        public static readonly PROPERTYKEY DEVPKEY_Device_PostInstallInProgress;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 14)]
        public static readonly PROPERTYKEY DEVPKEY_Device_Stack;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 15)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ExtendedConfigurationIds;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 16)]
        public static readonly PROPERTYKEY DEVPKEY_Device_IsRebootRequired;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 17)]
        public static readonly PROPERTYKEY DEVPKEY_Device_FirmwareDate;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 18)]
        public static readonly PROPERTYKEY DEVPKEY_Device_FirmwareVersion;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 19)]
        public static readonly PROPERTYKEY DEVPKEY_Device_FirmwareRevision;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 20)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DependencyProviders;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 21)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DependencyDependents;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 22)]
        public static readonly PROPERTYKEY DEVPKEY_Device_SoftRestartSupported;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 23)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ExtendedAddress;

        [PropertyKey(0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 24)]
        public static readonly PROPERTYKEY DEVPKEY_Device_AssignedToGuest;

        [PropertyKey(0x83da6326, 0x97a6, 0x4088, 0x94, 0x53, 0xa1, 0x92, 0x3f, 0x57, 0x3b, 0x29, 6)]
        public static readonly PROPERTYKEY DEVPKEY_Device_SessionId;

        [PropertyKey(0x83da6326, 0x97a6, 0x4088, 0x94, 0x53, 0xa1, 0x92, 0x3f, 0x57, 0x3b, 0x29, 100)]
        public static readonly PROPERTYKEY DEVPKEY_Device_InstallDate;

        [PropertyKey(0x83da6326, 0x97a6, 0x4088, 0x94, 0x53, 0xa1, 0x92, 0x3f, 0x57, 0x3b, 0x29, 101)]
        public static readonly PROPERTYKEY DEVPKEY_Device_FirstInstallDate;

        [PropertyKey(0x83da6326, 0x97a6, 0x4088, 0x94, 0x53, 0xa1, 0x92, 0x3f, 0x57, 0x3b, 0x29, 102)]
        public static readonly PROPERTYKEY DEVPKEY_Device_LastArrivalDate;

        [PropertyKey(0x83da6326, 0x97a6, 0x4088, 0x94, 0x53, 0xa1, 0x92, 0x3f, 0x57, 0x3b, 0x29, 103)]
        public static readonly PROPERTYKEY DEVPKEY_Device_LastRemovalDate;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 2)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverDate;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 3)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverVersion;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 4)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverDesc;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 5)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverInfPath;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 6)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverInfSection;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 7)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverInfSectionExt;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 8)]
        public static readonly PROPERTYKEY DEVPKEY_Device_MatchingDeviceId;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 9)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverProvider;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 10)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverPropPageProvider;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 11)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverCoInstallers;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 12)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ResourcePickerTags;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 13)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ResourcePickerExceptions;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 14)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverRank;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 15)]
        public static readonly PROPERTYKEY DEVPKEY_Device_DriverLogoLevel;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 17)]
        public static readonly PROPERTYKEY DEVPKEY_Device_NoConnectSound;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 18)]
        public static readonly PROPERTYKEY DEVPKEY_Device_GenericDriverInstalled;

        [PropertyKey(0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 19)]
        public static readonly PROPERTYKEY DEVPKEY_Device_AdditionalSoftwareRequested;

        [PropertyKey(0xafd97640, 0x86a3, 0x4210, 0xb6, 0x7c, 0x28, 0x9c, 0x41, 0xaa, 0xbe, 0x55, 2)]
        public static readonly PROPERTYKEY DEVPKEY_Device_SafeRemovalRequired;

        [PropertyKey(0xafd97640, 0x86a3, 0x4210, 0xb6, 0x7c, 0x28, 0x9c, 0x41, 0xaa, 0xbe, 0x55, 3)]
        public static readonly PROPERTYKEY DEVPKEY_Device_SafeRemovalRequiredOverride;

        [PropertyKey(0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 2)]
        public static readonly PROPERTYKEY DEVPKEY_DrvPkg_Model;

        [PropertyKey(0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 3)]
        public static readonly PROPERTYKEY DEVPKEY_DrvPkg_VendorWebSite;

        [PropertyKey(0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 4)]
        public static readonly PROPERTYKEY DEVPKEY_DrvPkg_DetailedDescription;

        [PropertyKey(0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 5)]
        public static readonly PROPERTYKEY DEVPKEY_DrvPkg_DocumentationLink;

        [PropertyKey(0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 6)]
        public static readonly PROPERTYKEY DEVPKEY_DrvPkg_Icon;

        [PropertyKey(0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 7)]
        public static readonly PROPERTYKEY DEVPKEY_DrvPkg_BrandingIcon;

        [PropertyKey(0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 19)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_UpperFilters;

        [PropertyKey(0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 20)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_LowerFilters;

        [PropertyKey(0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 25)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_Security;

        [PropertyKey(0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 26)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_SecuritySDS;

        [PropertyKey(0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 27)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_DevType;

        [PropertyKey(0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 28)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_Exclusive;

        [PropertyKey(0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 29)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_Characteristics;

        [PropertyKey(0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 2)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_Name;

        [PropertyKey(0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 3)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_ClassName;

        [PropertyKey(0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 4)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_Icon;

        [PropertyKey(0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 5)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_ClassInstaller;

        [PropertyKey(0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 6)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_PropPageProvider;

        [PropertyKey(0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 7)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_NoInstallClass;

        [PropertyKey(0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 8)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_NoDisplayClass;

        [PropertyKey(0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 9)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_SilentInstall;

        [PropertyKey(0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 10)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_NoUseClass;

        [PropertyKey(0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 11)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_DefaultService;

        [PropertyKey(0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 12)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_IconPath;

        [PropertyKey(0xd14d3ef3, 0x66cf, 0x4ba2, 0x9d, 0x38, 0x0d, 0xdb, 0x37, 0xab, 0x47, 0x01, 2)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_DHPRebalanceOptOut;

        [PropertyKey(0x713d1703, 0xa2e2, 0x49f5, 0x92, 0x14, 0x56, 0x47, 0x2e, 0xf3, 0xda, 0x5c, 2)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceClass_ClassCoInstallers;

        [PropertyKey(0x026e516e, 0xb814, 0x414b, 0x83, 0xcd, 0x85, 0x6d, 0x6f, 0xef, 0x48, 0x22, 2)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_FriendlyName;

        [PropertyKey(0x026e516e, 0xb814, 0x414b, 0x83, 0xcd, 0x85, 0x6d, 0x6f, 0xef, 0x48, 0x22, 3)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_Enabled;

        [PropertyKey(0x026e516e, 0xb814, 0x414b, 0x83, 0xcd, 0x85, 0x6d, 0x6f, 0xef, 0x48, 0x22, 4)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_ClassGuid;

        [PropertyKey(0x026e516e, 0xb814, 0x414b, 0x83, 0xcd, 0x85, 0x6d, 0x6f, 0xef, 0x48, 0x22, 5)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_ReferenceString;

        [PropertyKey(0x026e516e, 0xb814, 0x414b, 0x83, 0xcd, 0x85, 0x6d, 0x6f, 0xef, 0x48, 0x22, 6)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_Restricted;

        [PropertyKey(0x026e516e, 0xb814, 0x414b, 0x83, 0xcd, 0x85, 0x6d, 0x6f, 0xef, 0x48, 0x22, 8)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_UnrestrictedAppCapabilities;

        [PropertyKey(0x026e516e, 0xb814, 0x414b, 0x83, 0xcd, 0x85, 0x6d, 0x6f, 0xef, 0x48, 0x22, 9)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_SchematicName;

        [PropertyKey(0x14c83a99, 0x0b3f, 0x44b7, 0xbe, 0x4c, 0xa1, 0x78, 0xd3, 0x99, 0x05, 0x64, 2)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterfaceClass_DefaultInterface;

        [PropertyKey(0x14c83a99, 0x0b3f, 0x44b7, 0xbe, 0x4c, 0xa1, 0x78, 0xd3, 0x99, 0x05, 0x64, 3)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterfaceClass_Name;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 51)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_Address;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 52)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_DiscoveryMethod;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 53)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsEncrypted;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 54)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsAuthenticated;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 55)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsConnected;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 56)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsPaired;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 57)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_Icon;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 65)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_Version;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 66)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_Last_Seen;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 67)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_Last_Connected;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 68)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsShowInDisconnectedState;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 70)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsLocalMachine;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 71)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_MetadataPath;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 72)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsMetadataSearchInProgress;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 73)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_MetadataChecksum;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 74)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsNotInterestingForDisplay;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 76)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_LaunchDeviceStageOnDeviceConnect;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 77)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_LaunchDeviceStageFromExplorer;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 78)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_BaselineExperienceId;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 79)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsDeviceUniquelyIdentifiable;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 80)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_AssociationArray;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 81)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_DeviceDescription1;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 82)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_DeviceDescription2;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 83)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_HasProblem;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 84)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsSharedDevice;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 85)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsNetworkDevice;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 86)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsDefaultDevice;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 87)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_MetadataCabinet;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 88)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_RequiresPairingElevation;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 89)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_ExperienceId;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 90)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_Category;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 91)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_Category_Desc_Singular;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 92)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_Category_Desc_Plural;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 93)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_Category_Icon;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 94)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_CategoryGroup_Desc;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 95)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_CategoryGroup_Icon;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 97)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_PrimaryCategory;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 98)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_UnpairUninstall;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 99)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_RequiresUninstallElevation;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 100)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_DeviceFunctionSubRank;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 101)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_AlwaysShowDeviceAsConnected;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 105)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_ConfigFlags;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 106)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_PrivilegedPackageFamilyNames;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 107)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_CustomPrivilegedPackageFamilyNames;

        [PropertyKey(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 108)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_IsRebootRequired;

        [PropertyKey(0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 12288)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_FriendlyName;

        [PropertyKey(0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 8192)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_Manufacturer;

        [PropertyKey(0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 8194)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_ModelName;

        [PropertyKey(0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 8195)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_ModelNumber;

        [PropertyKey(0x83da6326, 0x97a6, 0x4088, 0x94, 0x53, 0xa1, 0x92, 0x3f, 0x57, 0x3b, 0x29, 9)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceContainer_InstallInProgress;

        [PropertyKey(0x13673f42, 0xa3d6, 0x49f6, 0xb4, 0xda, 0xae, 0x46, 0xe0, 0xc5, 0x23, 0x7c, 2)]
        public static readonly PROPERTYKEY DEVPKEY_DevQuery_ObjectType;

        public static readonly Guid GUID_DEVINTERFACE_DISK__scanned__ = new Guid(0x53f56307L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid GUID_DEVINTERFACE_CDROM__scanned__ = new Guid(0x53f56308L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid GUID_DEVINTERFACE_PARTITION__scanned__ = new Guid(0x53f5630aL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid GUID_DEVINTERFACE_TAPE__scanned__ = new Guid(0x53f5630bL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid GUID_DEVINTERFACE_WRITEONCEDISK__scanned__ = new Guid(0x53f5630cL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid GUID_DEVINTERFACE_VOLUME__scanned__ = new Guid(0x53f5630dL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid GUID_DEVINTERFACE_MEDIUMCHANGER__scanned__ = new Guid(0x53f56310L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid GUID_DEVINTERFACE_FLOPPY__scanned__ = new Guid(0x53f56311L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid GUID_DEVINTERFACE_CDCHANGER__scanned__ = new Guid(0x53f56312L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid GUID_DEVINTERFACE_STORAGEPORT__scanned__ = new Guid(0x2accfe60L, 0xc130, 0x11d2, 0xb0, 0x82, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid GUID_DEVINTERFACE_VMLUN__scanned__ = new Guid(0x6f416619L, 0x9f29, 0x42a5, 0xb2, 0x0b, 0x37, 0xe2, 0x19, 0xca, 0x02, 0xb0);

        public static readonly Guid GUID_DEVINTERFACE_SES__scanned__ = new Guid(0x1790c9ecL, 0x47d5, 0x4df3, 0xb5, 0xaf, 0x9a, 0xdf, 0x3c, 0xf2, 0x3e, 0x48);

        public static readonly Guid GUID_DEVINTERFACE_SERVICE_VOLUME__scanned__ = new Guid(0x6ead3d82L, 0x25ec, 0x46bc, 0xb7, 0xfd, 0xc1, 0xf0, 0xdf, 0x8f, 0x50, 0x37);

        public static readonly Guid GUID_DEVINTERFACE_HIDDEN_VOLUME__scanned__ = new Guid(0x7f108a28L, 0x9833, 0x4b3b, 0xb7, 0x80, 0x2c, 0x6b, 0x5f, 0xa5, 0xc0, 0x62);

        public static readonly Guid GUID_DEVINTERFACE_UNIFIED_ACCESS_RPMB__scanned__ = new Guid(0x27447c21L, 0xbcc3, 0x4d07, 0xa0, 0x5b, 0xa3, 0x39, 0x5b, 0xb4, 0xee, 0xe7);

        public static readonly Guid GUID_DEVICEDUMP_STORAGE_DEVICE__scanned__ = new Guid(0xd8e2592f,0x1aab,0x4d56,0xa7, 0x46, 0x1f, 0x75, 0x85, 0xdf, 0x40, 0xf4);

        public static readonly Guid GUID_DEVICEDUMP_DRIVER_STORAGE_PORT__scanned__ = new Guid(0xda82441d,0x7142,0x4bc1,0xb8, 0x44, 0x08, 0x07, 0xc5, 0xa4, 0xb6, 0x7f);

        [PropertyKey(0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 2)]
        public static readonly PROPERTYKEY DEVPKEY_Storage_Portable;

        [PropertyKey(0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 3)]
        public static readonly PROPERTYKEY DEVPKEY_Storage_Removable_Media;

        [PropertyKey(0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 4)]
        public static readonly PROPERTYKEY DEVPKEY_Storage_System_Critical;

        [PropertyKey(0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 5)]
        public static readonly PROPERTYKEY DEVPKEY_Storage_Disk_Number;

        [PropertyKey(0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 6)]
        public static readonly PROPERTYKEY DEVPKEY_Storage_Partition_Number;

        [PropertyKey(0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 7)]
        public static readonly PROPERTYKEY DEVPKEY_Storage_Mbr_Type;

        [PropertyKey(0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 8)]
        public static readonly PROPERTYKEY DEVPKEY_Storage_Gpt_Type;

        [PropertyKey(0x4d1ebee8, 0x803, 0x4774, 0x98, 0x42, 0xb7, 0x7d, 0xb5, 0x2, 0x65, 0xe9, 9)]
        public static readonly PROPERTYKEY DEVPKEY_Storage_Gpt_Name;

        public const uint IOCTL_STORAGE_CHECK_VERIFY = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0200) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_CHECK_VERIFY2 = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0200) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_MEDIA_REMOVAL = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0201) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_EJECT_MEDIA = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0202) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_LOAD_MEDIA = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0203) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_LOAD_MEDIA2 = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0203) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_RESERVE = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0204) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_RELEASE = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0205) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_FIND_NEW_DEVICES = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0206) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_EJECTION_CONTROL = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0250) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_MCN_CONTROL = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0251) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_MEDIA_TYPES = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0300) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_MEDIA_TYPES_EX = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0301) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_MEDIA_SERIAL_NUMBER = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0304) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_HOTPLUG_INFO = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0305) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_SET_HOTPLUG_INFO = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0306) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_RESET_BUS = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0400) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_RESET_DEVICE = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0401) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_BREAK_RESERVATION = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0405) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_PERSISTENT_RESERVE_IN = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0406) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_PERSISTENT_RESERVE_OUT = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0407) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_DEVICE_NUMBER = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0420) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_DEVICE_NUMBER_EX = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0421) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_PREDICT_FAILURE = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0440) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_FAILURE_PREDICTION_CONFIG = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0441) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_COUNTERS = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x442) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_READ_CAPACITY = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0450) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_DEVICE_TELEMETRY = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0470) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_DEVICE_TELEMETRY_NOTIFY = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0471) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_DEVICE_TELEMETRY_QUERY_CAPS = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0472) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_DEVICE_TELEMETRY_RAW = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0473) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0480) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_PROTOCOL_COMMAND = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x04F0) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_QUERY_PROPERTY = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0500) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x0501) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_LB_PROVISIONING_MAP_RESOURCES = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0502) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_SET_PROPERTY = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x0503) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_REINITIALIZE_MEDIA = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x0590) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_BC_PROPERTIES = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0600) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_ALLOCATE_BC_STREAM = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0601) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_FREE_BC_STREAM = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0602) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_CHECK_PRIORITY_HINT_SUPPORT = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0620) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_START_DATA_INTEGRITY_CHECK = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0621) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_STOP_DATA_INTEGRITY_CHECK = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0622) << 2) | (METHOD_BUFFERED);

        public const uint OBSOLETE_IOCTL_STORAGE_RESET_BUS = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0400) << 2) | (METHOD_BUFFERED);

        public const uint OBSOLETE_IOCTL_STORAGE_RESET_DEVICE = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0401) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_FIRMWARE_GET_INFO = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0700) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_FIRMWARE_DOWNLOAD = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0701) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_FIRMWARE_ACTIVATE = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0702) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_ENABLE_IDLE_POWER = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0720) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_IDLE_POWERUP_REASON = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0721) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_POWER_ACTIVE = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0722) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_POWER_IDLE = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0723) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_EVENT_NOTIFICATION = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0724) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_DEVICE_POWER_CAP = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0725) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_RPMB_COMMAND = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0726) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_ATTRIBUTE_MANAGEMENT = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0727) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_DIAGNOSTIC = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0728) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0729) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_REMOVE_ELEMENT_AND_TRUNCATE = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0730) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG = ((IOCTL_STORAGE_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0731) << 2) | (METHOD_BUFFERED);

        public const uint STORAGE_DEVICE_FLAGS_RANDOM_DEVICEGUID_REASON_CONFLICT = 0x1;

        public const uint STORAGE_DEVICE_FLAGS_RANDOM_DEVICEGUID_REASON_NOHWID = 0x2;

        public const uint STORAGE_DEVICE_FLAGS_PAGE_83_DEVICEGUID = 0x4;

        public const uint RECOVERED_WRITES_VALID = 0x00000001;

        public const uint UNRECOVERED_WRITES_VALID = 0x00000002;

        public const uint RECOVERED_READS_VALID = 0x00000004;

        public const uint UNRECOVERED_READS_VALID = 0x00000008;

        public const uint WRITE_COMPRESSION_INFO_VALID = 0x00000010;

        public const uint READ_COMPRESSION_INFO_VALID = 0x00000020;

        public const int TAPE_RETURN_STATISTICS = 0;

        public const int TAPE_RETURN_ENV_INFO = 1;

        public const int TAPE_RESET_STATISTICS = 2;

        public const uint MEDIA_ERASEABLE = 0x00000001;

        public const uint MEDIA_WRITE_ONCE = 0x00000002;

        public const uint MEDIA_READ_ONLY = 0x00000004;

        public const uint MEDIA_READ_WRITE = 0x00000008;

        public const uint MEDIA_WRITE_PROTECTED = 0x00000100;

        public const uint MEDIA_CURRENTLY_MOUNTED = 0x80000000;

        public const uint STORAGE_FAILURE_PREDICTION_CONFIG_V1 = 1;

        public const uint SRB_TYPE_SCSI_REQUEST_BLOCK = 0;

        public const uint SRB_TYPE_STORAGE_REQUEST_BLOCK = 1;

        public const uint STORAGE_ADDRESS_TYPE_BTL8 = 0;

        public const uint STORAGE_RPMB_DESCRIPTOR_VERSION_1 = 1;

        public const uint STORAGE_RPMB_MINIMUM_RELIABLE_WRITE_SIZE = 512;

        public const uint STORAGE_CRYPTO_CAPABILITY_VERSION_1 = 1;

        public const uint STORAGE_CRYPTO_DESCRIPTOR_VERSION_1 = 1;

        public const uint STORAGE_TIER_NAME_LENGTH = 256;

        public const uint STORAGE_TIER_DESCRIPTION_LENGTH = 512;

        public const uint STORAGE_TIER_FLAG_NO_SEEK_PENALTY = 0x00020000;

        public const uint STORAGE_TIER_FLAG_WRITE_BACK_CACHE = 0x00200000;

        public const uint STORAGE_TIER_FLAG_READ_CACHE = 0x00400000;

        public const uint STORAGE_TIER_FLAG_PARITY = 0x00800000;

        public const uint STORAGE_TIER_FLAG_SMR = 0x01000000;

        public const uint STORAGE_TEMPERATURE_VALUE_NOT_REPORTED = 0x8000;

        public const uint STORAGE_TEMPERATURE_THRESHOLD_FLAG_ADAPTER_REQUEST = 0x0001;

        public const uint STORAGE_COMPONENT_ROLE_CACHE = 0x00000001;

        public const uint STORAGE_COMPONENT_ROLE_TIERING = 0x00000002;

        public const uint STORAGE_COMPONENT_ROLE_DATA = 0x00000004;

        public const uint STORAGE_ATTRIBUTE_BYTE_ADDRESSABLE_IO = 0x01;

        public const uint STORAGE_ATTRIBUTE_BLOCK_IO = 0x02;

        public const uint STORAGE_ATTRIBUTE_DYNAMIC_PERSISTENCE = 0x04;

        public const uint STORAGE_ATTRIBUTE_VOLATILE = 0x08;

        public const uint STORAGE_ATTRIBUTE_ASYNC_EVENT_NOTIFICATION = 0x10;

        public const uint STORAGE_ATTRIBUTE_PERF_SIZE_INDEPENDENT = 0x20;

        public const uint STORAGE_DEVICE_MAX_OPERATIONAL_STATUS = 16;

        public const uint STORAGE_ADAPTER_SERIAL_NUMBER_V1_MAX_LENGTH = 128;

        public const uint DeviceDsmActionFlag_NonDestructive = 0x80000000;

        public const uint DEVICE_DSM_FLAG_ENTIRE_DATA_SET_RANGE = 0x00000001;

        public const uint DEVICE_DSM_FLAG_TRIM_NOT_FS_ALLOCATED = 0x80000000;

        public const uint DEVICE_DSM_FLAG_TRIM_BYPASS_RZAT = 0x40000000;

        public const uint DEVICE_DSM_NOTIFY_FLAG_BEGIN = 0x00000001;

        public const uint DEVICE_DSM_NOTIFY_FLAG_END = 0x00000002;

        public const uint STORAGE_OFFLOAD_MAX_TOKEN_LENGTH = 512;

        public const uint STORAGE_OFFLOAD_TOKEN_ID_LENGTH = 0x1F8;

        public const uint STORAGE_OFFLOAD_TOKEN_TYPE_ZERO_DATA = 0xFFFF0001;

        public const uint STORAGE_OFFLOAD_READ_RANGE_TRUNCATED = 0x00000001;

        public const uint STORAGE_OFFLOAD_WRITE_RANGE_TRUNCATED = 0x0001;

        public const uint STORAGE_OFFLOAD_TOKEN_INVALID = 0x0002;

        public const uint DEVICE_DSM_FLAG_ALLOCATION_CONSOLIDATEABLE_ONLY = 0x40000000;

        public const uint DEVICE_DSM_PARAMETERS_V1 = 1;

        public const uint DEVICE_DSM_FLAG_REPAIR_INPUT_TOPOLOGY_ID_PRESENT = 0x40000000;

        public const uint DEVICE_DSM_FLAG_REPAIR_OUTPUT_PARITY_EXTENT = 0x20000000;

        public const uint DEVICE_DSM_FLAG_SCRUB_SKIP_IN_SYNC = 0x10000000;

        public const uint DEVICE_DSM_FLAG_SCRUB_OUTPUT_PARITY_EXTENT = 0x20000000;

        public const uint DEVICE_DSM_FLAG_PHYSICAL_ADDRESSES_OMIT_TOTAL_RANGES = 0x10000000;

        public const uint DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT_V1 = 1;

        public const uint DEVICE_STORAGE_NO_ERRORS = 0x1;

        public const uint DEVICE_DSM_RANGE_ERROR_OUTPUT_V1 = 1;

        public const uint IOCTL_STORAGE_BC_VERSION = 1;

        public const uint STORAGE_PRIORITY_HINT_SUPPORTED = 0x0001;

        public const uint ERROR_HISTORY_DIRECTORY_ENTRY_DEFAULT_COUNT = 8;

        public const uint DEVICEDUMP_STRUCTURE_VERSION_V1 = 1;

        public const uint DEVICEDUMP_MAX_IDSTRING = 32;

        public const uint MAX_FW_BUCKET_ID_LENGTH = 132;

        public const uint DDUMP_FLAG_DATA_READ_FROM_DEVICE = 0x0001;

        public const uint FW_ISSUEID_NO_ISSUE = 0x00000000;

        public const uint FW_ISSUEID_UNKNOWN = 0xFFFFFFFF;

        public const uint TC_PUBLIC_DEVICEDUMP_CONTENT_SMART = 0x01;

        public const uint TC_PUBLIC_DEVICEDUMP_CONTENT_GPLOG = 0x02;

        public const uint TC_PUBLIC_DEVICEDUMP_CONTENT_GPLOG_MAX = 16;

        public const uint TC_DEVICEDUMP_SUBSECTION_DESC_LENGTH = 16;

        public const uint CDB_SIZE = 16;

        public const uint TELEMETRY_COMMAND_SIZE = 16;

        public const uint DEVICEDUMP_CAP_PRIVATE_SECTION = 0x00000001;

        public const uint DEVICEDUMP_CAP_RESTRICTED_SECTION = 0x00000002;

        public const uint STORAGE_IDLE_POWERUP_REASON_VERSION_V1 = 1;

        public const uint STORAGE_DEVICE_POWER_CAP_VERSION_V1 = 1;

        public const uint STORAGE_EVENT_NOTIFICATION_VERSION_V1 = 1;

        public const ulong STORAGE_EVENT_MEDIA_STATUS = 0x0000000000000001;

        public const ulong STORAGE_EVENT_DEVICE_STATUS = 0x0000000000000002;

        public const ulong STORAGE_EVENT_DEVICE_OPERATION = 0x0000000000000004;

        public const uint READ_COPY_NUMBER_KEY = 0x52434e00;

        public const uint READ_COPY_NUMBER_BYPASS_CACHE_FLAG = 0x00000100;

        public const uint STORAGE_HW_FIRMWARE_REQUEST_FLAG_CONTROLLER = 0x00000001;

        public const uint STORAGE_HW_FIRMWARE_REQUEST_FLAG_LAST_SEGMENT = 0x00000002;

        public const uint STORAGE_HW_FIRMWARE_REQUEST_FLAG_FIRST_SEGMENT = 0x00000004;

        public const uint STORAGE_HW_FIRMWARE_REQUEST_FLAG_SWITCH_TO_EXISTING_FIRMWARE = 0x80000000;

        public const uint STORAGE_HW_FIRMWARE_INVALID_SLOT = 0xFF;

        public const uint STORAGE_HW_FIRMWARE_REVISION_LENGTH = 16;

        public const uint STORAGE_PROTOCOL_STRUCTURE_VERSION = 0x1;

        public const uint STORAGE_PROTOCOL_COMMAND_FLAG_ADAPTER_REQUEST = 0x80000000;

        public const uint STORAGE_PROTOCOL_STATUS_PENDING = 0x0;

        public const uint STORAGE_PROTOCOL_STATUS_SUCCESS = 0x1;

        public const uint STORAGE_PROTOCOL_STATUS_ERROR = 0x2;

        public const uint STORAGE_PROTOCOL_STATUS_INVALID_REQUEST = 0x3;

        public const uint STORAGE_PROTOCOL_STATUS_NO_DEVICE = 0x4;

        public const uint STORAGE_PROTOCOL_STATUS_BUSY = 0x5;

        public const uint STORAGE_PROTOCOL_STATUS_DATA_OVERRUN = 0x6;

        public const uint STORAGE_PROTOCOL_STATUS_INSUFFICIENT_RESOURCES = 0x7;

        public const uint STORAGE_PROTOCOL_STATUS_THROTTLED_REQUEST = 0x8;

        public const uint STORAGE_PROTOCOL_STATUS_NOT_SUPPORTED = 0xFF;

        public const uint STORAGE_PROTOCOL_COMMAND_LENGTH_NVME = 0x40;

        public const uint STORAGE_PROTOCOL_SPECIFIC_NVME_ADMIN_COMMAND = 0x01;

        public const uint STORAGE_PROTOCOL_SPECIFIC_NVME_NVM_COMMAND = 0x02;

        public const uint STORATTRIBUTE_NONE = 0;

        public const uint STORATTRIBUTE_MANAGEMENT_STATE = 1;

        public const uint BSF_MSGSRV32ISOK = 0x80000000;

        public const uint BSF_MSGSRV32ISOK_BIT = 31;

        public const uint DBT_APPYBEGIN = 0x0000;

        public const uint DBT_APPYEND = 0x0001;

        public const uint DBT_DEVNODES_CHANGED = 0x0007;

        public const uint DBT_QUERYCHANGECONFIG = 0x0017;

        public const uint DBT_CONFIGCHANGED = 0x0018;

        public const uint DBT_CONFIGCHANGECANCELED = 0x0019;

        public const uint DBT_MONITORCHANGE = 0x001B;

        public const uint DBT_SHELLLOGGEDON = 0x0020;

        public const uint DBT_CONFIGMGAPI32 = 0x0022;

        public const uint DBT_VXDINITCOMPLETE = 0x0023;

        public const uint DBT_VOLLOCKQUERYLOCK = 0x8041;

        public const uint DBT_VOLLOCKLOCKTAKEN = 0x8042;

        public const uint DBT_VOLLOCKLOCKFAILED = 0x8043;

        public const uint DBT_VOLLOCKQUERYUNLOCK = 0x8044;

        public const uint DBT_VOLLOCKLOCKRELEASED = 0x8045;

        public const uint DBT_VOLLOCKUNLOCKFAILED = 0x8046;

        public const uint LOCKP_ALLOW_WRITES = 0x01;

        public const uint LOCKP_FAIL_WRITES = 0x00;

        public const uint LOCKP_FAIL_MEM_MAPPING = 0x02;

        public const uint LOCKP_ALLOW_MEM_MAPPING = 0x00;

        public const uint LOCKP_USER_MASK = 0x03;

        public const uint LOCKP_LOCK_FOR_FORMAT = 0x04;

        public const uint LOCKF_LOGICAL_LOCK = 0x00;

        public const uint LOCKF_PHYSICAL_LOCK = 0x01;

        public const uint DBT_NO_DISK_SPACE = 0x0047;

        public const uint DBT_LOW_DISK_SPACE = 0x0048;

        public const uint DBT_CONFIGMGPRIVATE = 0x7FFF;

        public const uint DBT_DEVICEARRIVAL = 0x8000;

        public const uint DBT_DEVICEQUERYREMOVE = 0x8001;

        public const uint DBT_DEVICEQUERYREMOVEFAILED = 0x8002;

        public const uint DBT_DEVICEREMOVEPENDING = 0x8003;

        public const uint DBT_DEVICEREMOVECOMPLETE = 0x8004;

        public const uint DBT_DEVICETYPESPECIFIC = 0x8005;

        public const uint DBT_CUSTOMEVENT = 0x8006;

        public const uint DBT_DEVTYP_DEVNODE = 0x00000001;

        public const uint DBT_DEVTYP_NET = 0x00000004;

        public const uint DBTF_RESOURCE = 0x00000001;

        public const uint DBTF_XPORT = 0x00000002;

        public const uint DBTF_SLOWNET = 0x00000004;

        public const uint DBT_VPOWERDAPI = 0x8100;

        public const uint DBT_USERDEFINED = 0xFFFF;

        public const uint DEVPROP_TYPEMOD_ARRAY = 0x00001000;

        public const uint DEVPROP_TYPEMOD_LIST = 0x00002000;

        public const uint DEVPROP_TYPE_EMPTY = 0x00000000;

        public const uint DEVPROP_TYPE_NULL = 0x00000001;

        public const uint DEVPROP_TYPE_SBYTE = 0x00000002;

        public const uint DEVPROP_TYPE_BYTE = 0x00000003;

        public const uint DEVPROP_TYPE_INT16 = 0x00000004;

        public const uint DEVPROP_TYPE_UINT16 = 0x00000005;

        public const uint DEVPROP_TYPE_INT32 = 0x00000006;

        public const uint DEVPROP_TYPE_UINT32 = 0x00000007;

        public const uint DEVPROP_TYPE_INT64 = 0x00000008;

        public const uint DEVPROP_TYPE_UINT64 = 0x00000009;

        public const uint DEVPROP_TYPE_FLOAT = 0x0000000A;

        public const uint DEVPROP_TYPE_DOUBLE = 0x0000000B;

        public const uint DEVPROP_TYPE_DECIMAL = 0x0000000C;

        public const uint DEVPROP_TYPE_GUID = 0x0000000D;

        public const uint DEVPROP_TYPE_CURRENCY = 0x0000000E;

        public const uint DEVPROP_TYPE_DATE = 0x0000000F;

        public const uint DEVPROP_TYPE_FILETIME = 0x00000010;

        public const uint DEVPROP_TYPE_BOOLEAN = 0x00000011;

        public const uint DEVPROP_TYPE_STRING = 0x00000012;

        public const uint DEVPROP_TYPE_SECURITY_DESCRIPTOR = 0x00000013;

        public const uint DEVPROP_TYPE_SECURITY_DESCRIPTOR_STRING = 0x00000014;

        public const uint DEVPROP_TYPE_DEVPROPKEY = 0x00000015;

        public const uint DEVPROP_TYPE_DEVPROPTYPE = 0x00000016;

        public const uint DEVPROP_TYPE_ERROR = 0x00000017;

        public const uint DEVPROP_TYPE_NTSTATUS = 0x00000018;

        public const uint DEVPROP_TYPE_STRING_INDIRECT = 0x00000019;

        public const uint MAX_DEVPROP_TYPE = 0x00000019;

        public const uint MAX_DEVPROP_TYPEMOD = 0x00002000;

        public const uint DEVPROP_MASK_TYPE = 0x00000FFF;

        public const uint DEVPROP_MASK_TYPEMOD = 0x0000F000;

        public const uint DEVPROPID_FIRST_USABLE = 2;

        public static readonly Guid GUID_IO_VOLUME_CHANGE__scanned__ = new Guid(0x7373654aL, 0x812a, 0x11d0, 0xbe, 0xc7, 0x08, 0x00, 0x2b, 0xe2, 0x09, 0x2f );

        public static readonly Guid GUID_IO_VOLUME_DISMOUNT__scanned__ = new Guid(0xd16a55e8L, 0x1059, 0x11d2, 0x8f, 0xfd, 0x00, 0xa0, 0xc9, 0xa0, 0x6d, 0x32 );

        public static readonly Guid GUID_IO_VOLUME_DISMOUNT_FAILED__scanned__ = new Guid(0xe3c5b178L, 0x105d, 0x11d2, 0x8f, 0xfd, 0x00, 0xa0, 0xc9, 0xa0, 0x6d, 0x32 );

        public static readonly Guid GUID_IO_VOLUME_MOUNT__scanned__ = new Guid(0xb5804878L, 0x1a96, 0x11d2, 0x8f, 0xfd, 0x00, 0xa0, 0xc9, 0xa0, 0x6d, 0x32 );

        public static readonly Guid GUID_IO_VOLUME_LOCK__scanned__ = new Guid(0x50708874L, 0xc9af, 0x11d1, 0x8f, 0xef, 0x00, 0xa0, 0xc9, 0xa0, 0x6d, 0x32 );

        public static readonly Guid GUID_IO_VOLUME_LOCK_FAILED__scanned__ = new Guid(0xae2eed10L, 0x0ba8, 0x11d2, 0x8f, 0xfb, 0x00, 0xa0, 0xc9, 0xa0, 0x6d, 0x32 );

        public static readonly Guid GUID_IO_VOLUME_UNLOCK__scanned__ = new Guid(0x9a8c3d68L, 0xd0cb, 0x11d1, 0x8f, 0xef, 0x00, 0xa0, 0xc9, 0xa0, 0x6d, 0x32 );

        public static readonly Guid GUID_IO_VOLUME_NAME_CHANGE__scanned__ = new Guid(0x2de97f83, 0x4c06, 0x11d2, 0xa5, 0x32, 0x0, 0x60, 0x97, 0x13, 0x5, 0x5a);

        public static readonly Guid GUID_IO_VOLUME_NEED_CHKDSK__scanned__ = new Guid(0x799a0960, 0x0a0b, 0x4e03, 0xad, 0x88, 0x2f, 0xa7, 0xc6, 0xce, 0x74, 0x8a);

        public static readonly Guid GUID_IO_VOLUME_WORM_NEAR_FULL__scanned__ = new Guid(0xf3bfff82, 0xf3de, 0x48d2, 0xaf, 0x95, 0x45, 0x7f, 0x80, 0xb7, 0x63, 0xf2);

        public static readonly Guid GUID_IO_VOLUME_WEARING_OUT__scanned__ = new Guid(0x873113ca, 0x1486, 0x4508, 0x82, 0xac, 0xc3, 0xb2, 0xe5, 0x29, 0x7a, 0xaa);

        public static readonly Guid GUID_IO_VOLUME_FORCE_CLOSED__scanned__ = new Guid(0x411ad84f, 0x433e, 0x4dc2, 0xa5, 0xae, 0x4a, 0x2d, 0x1a, 0x2d, 0xe6, 0x54);

        public static readonly Guid GUID_IO_VOLUME_INFO_MAKE_COMPAT__scanned__ = new Guid(0x3ab9a0d2, 0xef80, 0x45cf, 0x8c, 0xdc, 0xcb, 0xe0, 0x2a, 0x21, 0x29, 0x06);

        public static readonly Guid GUID_IO_VOLUME_PREPARING_EJECT__scanned__ = new Guid(0xc79eb16e, 0x0dac, 0x4e7a, 0xa8, 0x6c, 0xb2, 0x5c, 0xee, 0xaa, 0x88, 0xf6);

        public static readonly Guid GUID_IO_VOLUME_BACKGROUND_FORMAT__scanned__ = new Guid(0xa2e5fc86, 0xd5cd, 0x4038, 0xb2, 0xe3, 0x44, 0x45, 0x6, 0x5c, 0x23, 0x77);

        public static readonly Guid GUID_IO_VOLUME_PHYSICAL_CONFIGURATION_CHANGE__scanned__ = new Guid(0x2de97f84, 0x4c06, 0x11d2, 0xa5, 0x32, 0x0, 0x60, 0x97, 0x13, 0x5, 0x5a);

        public static readonly Guid GUID_IO_VOLUME_UNIQUE_ID_CHANGE__scanned__ = new Guid(0xaf39da42, 0x6622, 0x41f5, 0x97, 0xb, 0x13, 0x9d, 0x9, 0x2f, 0xa3, 0xd9);

        public static readonly Guid GUID_IO_VOLUME_FVE_STATUS_CHANGE__scanned__ = new Guid(0x062998b2, 0xee1f, 0x4b6a, 0xb8, 0x57, 0xe7, 0x6c, 0xbb, 0xe9, 0xa6, 0xda);

        public static readonly Guid GUID_IO_VOLUME_DEVICE_INTERFACE__scanned__ = new Guid(0x53f5630d, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid GUID_IO_VOLUME_CHANGE_SIZE__scanned__ = new Guid(0x3a1625be, 0xad03, 0x49f1, 0x8e, 0xf8, 0x6b, 0xba, 0xc1, 0x82, 0xd1, 0xfd);

        public static readonly Guid GUID_IO_MEDIA_ARRIVAL__scanned__ = new Guid(0xd07433c0, 0xa98e, 0x11d2, 0x91, 0x7a, 0x00, 0xa0, 0xc9, 0x06, 0x8f, 0xf3);

        public static readonly Guid GUID_IO_MEDIA_REMOVAL__scanned__ = new Guid(0xd07433c1, 0xa98e, 0x11d2, 0x91, 0x7a, 0x00, 0xa0, 0xc9, 0x06, 0x8f, 0xf3);

        public static readonly Guid GUID_IO_CDROM_EXCLUSIVE_LOCK__scanned__ = new Guid(0xbc56c139, 0x7a10, 0x47ee, 0xa2, 0x94, 0x4c, 0x6a, 0x38, 0xf0, 0x14, 0x9a);

        public static readonly Guid GUID_IO_CDROM_EXCLUSIVE_UNLOCK__scanned__ = new Guid(0xa3b6d27d, 0x5e35, 0x4885, 0x81, 0xe5, 0xee, 0x18, 0xc0, 0xe, 0xd7, 0x79);

        public static readonly Guid GUID_IO_DEVICE_BECOMING_READY__scanned__ = new Guid(0xd07433f0, 0xa98e, 0x11d2, 0x91, 0x7a, 0x00, 0xa0, 0xc9, 0x06, 0x8f, 0xf3);

        public static readonly Guid GUID_IO_DEVICE_EXTERNAL_REQUEST__scanned__ = new Guid(0xd07433d0, 0xa98e, 0x11d2, 0x91, 0x7a, 0x00, 0xa0, 0xc9, 0x06, 0x8f, 0xf3);

        public static readonly Guid GUID_IO_MEDIA_EJECT_REQUEST__scanned__ = new Guid(0xd07433d1, 0xa98e, 0x11d2, 0x91, 0x7a, 0x00, 0xa0, 0xc9, 0x06, 0x8f, 0xf3);

        public static readonly Guid GUID_IO_DRIVE_REQUIRES_CLEANING__scanned__ = new Guid(0x7207877c, 0x90ed, 0x44e5, 0xa0, 0x0, 0x81, 0x42, 0x8d, 0x4c, 0x79, 0xbb);

        public static readonly Guid GUID_IO_TAPE_ERASE__scanned__ = new Guid(0x852d11eb, 0x4bb8, 0x4507, 0x9d, 0x9b, 0x41, 0x7c, 0xc2, 0xb1, 0xb4, 0x38);

        public static readonly Guid GUID_DEVICE_EVENT_RBC__scanned__ = new Guid(0xd0744792, 0xa98e, 0x11d2, 0x91, 0x7a, 0x00, 0xa0, 0xc9, 0x06, 0x8f, 0xf3);

        public static readonly Guid GUID_IO_DISK_CLONE_ARRIVAL__scanned__ = new Guid(0x6a61885b, 0x7c39, 0x43dd, 0x9b, 0x56, 0xb8, 0xac, 0x22, 0xa5, 0x49, 0xaa);

        public static readonly Guid GUID_IO_DISK_LAYOUT_CHANGE__scanned__ = new Guid(0x11dff54c, 0x8469, 0x41f9, 0xb3, 0xde, 0xef, 0x83, 0x64, 0x87, 0xc5, 0x4a);

        public static readonly Guid GUID_IO_DISK_HEALTH_NOTIFICATION__scanned__ = new Guid(0xf1bd644, 0x3916, 0x49c5, 0xb0, 0x63, 0x99, 0x19, 0x40, 0x11, 0x8f, 0xb2);

        public const uint D3DNTHAL_NUMCLIPVERTICES = 20;

        public const int D3DNTHAL_SCENE_CAPTURE_START = 0x00000000;

        public const int D3DNTHAL_SCENE_CAPTURE_END = 0x00000001;

        public const long D3DNTHAL_CONTEXT_BAD = 0x000000200;

        public const long D3DNTHAL_OUTOFCONTEXTS = 0x000000201;

        public const int D3DNTHAL2_CB32_SETRENDERTARGET = 0x00000001;

        public const uint D3DHAL_STATESETBEGIN = 0;

        public const uint D3DHAL_STATESETEND = 1;

        public const uint D3DHAL_STATESETDELETE = 2;

        public const uint D3DHAL_STATESETEXECUTE = 3;

        public const uint D3DHAL_STATESETCAPTURE = 4;

        public const int D3DNTHALDP2_USERMEMVERTICES = 0x00000001;

        public const int D3DNTHALDP2_EXECUTEBUFFER = 0x00000002;

        public const int D3DNTHALDP2_SWAPVERTEXBUFFER = 0x00000004;

        public const int D3DNTHALDP2_SWAPCOMMANDBUFFER = 0x00000008;

        public const int D3DNTHALDP2_REQVERTEXBUFSIZE = 0x00000010;

        public const int D3DNTHALDP2_REQCOMMANDBUFSIZE = 0x00000020;

        public const int D3DNTHALDP2_VIDMEMVERTEXBUF = 0x00000040;

        public const int D3DNTHALDP2_VIDMEMCOMMANDBUF = 0x00000080;

        public const int D3DNTHAL3_CB32_CLEAR2 = 0x00000001;

        public const int D3DNTHAL3_CB32_RESERVED = 0x00000002;

        public const int D3DNTHAL3_CB32_VALIDATETEXTURESTAGESTATE = 0x00000004;

        public const int D3DNTHAL3_CB32_DRAWPRIMITIVES2 = 0x00000008;

        public const uint D3DNTHAL_TSS_RENDERSTATEBASE = 256;

        public const uint D3DNTHAL_TSS_MAXSTAGES = 8;

        public const uint D3DNTHAL_TSS_STATESPERSTAGE = 64;

        public const uint D3DTSS_TEXTUREMAP = 0;

        public const uint D3DHAL_SAMPLER_MAXSAMP = 16;

        public const uint D3DHAL_SAMPLER_MAXVERTEXSAMP = 4;

        public const int D3DPMISCCAPS_LINEPATTERNREP = 0x00000004;

        public const uint D3DRS_MAXVERTEXSHADERINST = 196;

        public const uint D3DRS_MAXPIXELSHADERINST = 197;

        public const uint D3DRENDERSTATE_EVICTMANAGEDTEXTURES = 61;

        public const uint D3DRENDERSTATE_SCENECAPTURE = 62;

        public const uint _NT_D3DRS_DELETERTPATCH = 169;

        public const uint D3DINFINITEINSTRUCTIONS = 0xffffffff;

        public const uint D3DNTHAL_STATESETCREATE = 5;

        public const int D3DNTCLEAR_COMPUTERECTS = 0x00000008;

        public const int _NT_RTPATCHFLAG_HASSEGS = 0x00000001;

        public const int _NT_RTPATCHFLAG_HASINFO = 0x00000002;

        public const uint D3DNTHAL_ROW_WEIGHTS = 1;

        public const uint D3DNTHAL_COL_WEIGHTS = 2;

        public const int DP2BLT_POINT = 0x00000001;

        public const int DP2BLT_LINEAR = 0x00000002;

        public const int DDBLT_EXTENDED_PRESENTATION_STRETCHFACTOR = 0x00000010;

        public const uint _NT_D3DGDI2_MAGIC = 0xFFFFFFFF;

        public const uint _NT_D3DGDI2_TYPE_GETD3DCAPS8 = 0x00000001;

        public const uint _NT_D3DGDI2_TYPE_GETFORMATCOUNT = 0x00000002;

        public const uint _NT_D3DGDI2_TYPE_GETFORMAT = 0x00000003;

        public const uint _NT_D3DGDI2_TYPE_DXVERSION = 0x00000004;

        public const uint _NT_D3DGDI2_TYPE_DEFERRED_AGP_AWARE = 0x00000018;

        public const uint _NT_D3DGDI2_TYPE_FREE_DEFERRED_AGP = 0x00000019;

        public const uint _NT_D3DGDI2_TYPE_DEFER_AGP_FREES = 0x00000020;

        public const uint _NT_D3DGDI2_TYPE_GETD3DCAPS9 = 0x00000010;

        public const uint _NT_D3DGDI2_TYPE_GETEXTENDEDMODECOUNT = 0x00000011;

        public const uint _NT_D3DGDI2_TYPE_GETEXTENDEDMODE = 0x00000012;

        public const uint _NT_D3DGDI2_TYPE_GETADAPTERGROUP = 0x00000013;

        public const uint _NT_D3DGDI2_TYPE_GETMULTISAMPLEQUALITYLEVELS = 0x00000016;

        public const uint _NT_D3DGDI2_TYPE_GETD3DQUERYCOUNT = 0x00000021;

        public const uint _NT_D3DGDI2_TYPE_GETD3DQUERY = 0x00000022;

        public const uint _NT_D3DGDI2_TYPE_GETDDIVERSION = 0x00000023;

        public const uint DX9_DDI_VERSION = 4;

        public const int _NT_D3DDEVCAPS_HWVERTEXBUFFER = 0x02000000;

        public const int _NT_D3DDEVCAPS_HWINDEXBUFFER = 0x04000000;

        public const int _NT_D3DDEVCAPS_SUBVOLUMELOCK = 0x08000000;

        public const int _NT_D3DPMISCCAPS_FOGINFVF = 0x00002000;

        public const int _NT_D3DFVF_FOG = 0x00002000;

        public const int D3DPRASTERCAPS_STRETCHBLTMULTISAMPLE = 0x00800000;

        public const uint _NT_D3DVS_MAXINSTRUCTIONCOUNT_V1_1 = 128;

        public const uint _NT_D3DVS_LABEL_MAX_V3_0 = 2048;

        public const uint _NT_D3DVS_TCRDOUTREG_MAX_V1_1 = 8;

        public const uint _NT_D3DVS_TCRDOUTREG_MAX_V2_0 = 8;

        public const uint _NT_D3DVS_TCRDOUTREG_MAX_V2_1 = 8;

        public const uint _NT_D3DVS_OUTPUTREG_MAX_V3_0 = 12;

        public const uint _NT_D3DVS_OUTPUTREG_MAX_SW_DX9 = 16;

        public const uint _NT_D3DVS_ATTROUTREG_MAX_V1_1 = 2;

        public const uint _NT_D3DVS_ATTROUTREG_MAX_V2_0 = 2;

        public const uint _NT_D3DVS_ATTROUTREG_MAX_V2_1 = 2;

        public const uint _NT_D3DVS_INPUTREG_MAX_V1_1 = 16;

        public const uint _NT_D3DVS_INPUTREG_MAX_V2_0 = 16;

        public const uint _NT_D3DVS_INPUTREG_MAX_V2_1 = 16;

        public const uint _NT_D3DVS_INPUTREG_MAX_V3_0 = 16;

        public const uint _NT_D3DVS_TEMPREG_MAX_V1_1 = 12;

        public const uint _NT_D3DVS_TEMPREG_MAX_V2_0 = 12;

        public const uint _NT_D3DVS_TEMPREG_MAX_V2_1 = 32;

        public const uint _NT_D3DVS_TEMPREG_MAX_V3_0 = 32;

        public const uint _NT_D3DVS_CONSTREG_MAX_V1_1 = 96;

        public const uint _NT_D3DVS_CONSTREG_MAX_V2_0 = 8192;

        public const uint _NT_D3DVS_CONSTREG_MAX_V2_1 = 8192;

        public const uint _NT_D3DVS_CONSTREG_MAX_V3_0 = 8192;

        public const uint _NT_D3DVS_CONSTINTREG_MAX_SW_DX9 = 2048;

        public const uint _NT_D3DVS_CONSTINTREG_MAX_V2_0 = 16;

        public const uint _NT_D3DVS_CONSTINTREG_MAX_V2_1 = 16;

        public const uint _NT_D3DVS_CONSTINTREG_MAX_V3_0 = 16;

        public const uint _NT_D3DVS_CONSTBOOLREG_MAX_SW_DX9 = 2048;

        public const uint _NT_D3DVS_CONSTBOOLREG_MAX_V2_0 = 16;

        public const uint _NT_D3DVS_CONSTBOOLREG_MAX_V2_1 = 16;

        public const uint _NT_D3DVS_CONSTBOOLREG_MAX_V3_0 = 16;

        public const uint _NT_D3DVS_ADDRREG_MAX_V1_1 = 1;

        public const uint _NT_D3DVS_ADDRREG_MAX_V2_0 = 1;

        public const uint _NT_D3DVS_ADDRREG_MAX_V2_1 = 1;

        public const uint _NT_D3DVS_ADDRREG_MAX_V3_0 = 1;

        public const uint _NT_D3DVS_MAXLOOPSTEP_V2_0 = 128;

        public const uint _NT_D3DVS_MAXLOOPSTEP_V2_1 = 128;

        public const uint _NT_D3DVS_MAXLOOPSTEP_V3_0 = 128;

        public const uint _NT_D3DVS_MAXLOOPINITVALUE_V2_0 = 255;

        public const uint _NT_D3DVS_MAXLOOPINITVALUE_V2_1 = 255;

        public const uint _NT_D3DVS_MAXLOOPINITVALUE_V3_0 = 255;

        public const uint _NT_D3DVS_MAXLOOPITERATIONCOUNT_V2_0 = 255;

        public const uint _NT_D3DVS_MAXLOOPITERATIONCOUNT_V2_1 = 255;

        public const uint _NT_D3DVS_MAXLOOPITERATIONCOUNT_V3_0 = 255;

        public const uint _NT_D3DVS_PREDICATE_MAX_V2_1 = 1;

        public const uint _NT_D3DVS_PREDICATE_MAX_V3_0 = 1;

        public const uint _NT_D3DPS_INPUTREG_MAX_V1_1 = 2;

        public const uint _NT_D3DPS_INPUTREG_MAX_V1_2 = 2;

        public const uint _NT_D3DPS_INPUTREG_MAX_V1_3 = 2;

        public const uint _NT_D3DPS_INPUTREG_MAX_V1_4 = 2;

        public const uint _NT_D3DPS_INPUTREG_MAX_V2_0 = 2;

        public const uint _NT_D3DPS_INPUTREG_MAX_V2_1 = 2;

        public const uint _NT_D3DPS_INPUTREG_MAX_V3_0 = 12;

        public const uint _NT_D3DPS_TEMPREG_MAX_V1_1 = 2;

        public const uint _NT_D3DPS_TEMPREG_MAX_V1_2 = 2;

        public const uint _NT_D3DPS_TEMPREG_MAX_V1_3 = 2;

        public const uint _NT_D3DPS_TEMPREG_MAX_V1_4 = 6;

        public const uint _NT_D3DPS_TEMPREG_MAX_V2_0 = 12;

        public const uint _NT_D3DPS_TEMPREG_MAX_V2_1 = 32;

        public const uint _NT_D3DPS_TEMPREG_MAX_V3_0 = 32;

        public const uint _NT_D3DPS_TEXTUREREG_MAX_V1_1 = 4;

        public const uint _NT_D3DPS_TEXTUREREG_MAX_V1_2 = 4;

        public const uint _NT_D3DPS_TEXTUREREG_MAX_V1_3 = 4;

        public const uint _NT_D3DPS_TEXTUREREG_MAX_V1_4 = 6;

        public const uint _NT_D3DPS_TEXTUREREG_MAX_V2_0 = 8;

        public const uint _NT_D3DPS_TEXTUREREG_MAX_V2_1 = 8;

        public const uint _NT_D3DPS_TEXTUREREG_MAX_V3_0 = 0;

        public const uint _NT_D3DPS_COLOROUT_MAX_V2_0 = 4;

        public const uint _NT_D3DPS_COLOROUT_MAX_V2_1 = 4;

        public const uint _NT_D3DPS_COLOROUT_MAX_V3_0 = 4;

        public const uint _NT_D3DPS_PREDICATE_MAX_V2_1 = 1;

        public const uint _NT_D3DPS_PREDICATE_MAX_V3_0 = 1;

        public const uint _NT_D3DPS_CONSTREG_MAX_SW_DX9 = 8192;

        public const uint _NT_D3DPS_CONSTREG_MAX_V1_1 = 8;

        public const uint _NT_D3DPS_CONSTREG_MAX_V1_2 = 8;

        public const uint _NT_D3DPS_CONSTREG_MAX_V1_3 = 8;

        public const uint _NT_D3DPS_CONSTREG_MAX_V1_4 = 8;

        public const uint _NT_D3DPS_CONSTREG_MAX_V2_0 = 32;

        public const uint _NT_D3DPS_CONSTREG_MAX_V2_1 = 32;

        public const uint _NT_D3DPS_CONSTREG_MAX_V3_0 = 224;

        public const uint _NT_D3DPS_CONSTBOOLREG_MAX_SW_DX9 = 2048;

        public const uint _NT_D3DPS_CONSTBOOLREG_MAX_V2_1 = 16;

        public const uint _NT_D3DPS_CONSTBOOLREG_MAX_V3_0 = 16;

        public const uint _NT_D3DPS_CONSTINTREG_MAX_SW_DX9 = 2048;

        public const uint _NT_D3DPS_CONSTINTREG_MAX_V2_1 = 16;

        public const uint _NT_D3DPS_CONSTINTREG_MAX_V3_0 = 16;

        public const uint _NT_D3DPS_MAXLOOPSTEP_V2_1 = 128;

        public const uint _NT_D3DPS_MAXLOOPSTEP_V3_0 = 128;

        public const uint _NT_D3DPS_MAXLOOPINITVALUE_V2_1 = 255;

        public const uint _NT_D3DPS_MAXLOOPINITVALUE_V3_0 = 255;

        public const uint _NT_D3DPS_MAXLOOPITERATIONCOUNT_V2_1 = 255;

        public const uint _NT_D3DPS_MAXLOOPITERATIONCOUNT_V3_0 = 255;

        public const uint _NT_D3DPS_INPUTREG_MAX_DX8 = 8;

        public const uint _NT_D3DPS_TEMPREG_MAX_DX8 = 8;

        public const uint _NT_D3DPS_CONSTREG_MAX_DX8 = 8;

        public const uint _NT_D3DPS_TEXTUREREG_MAX_DX8 = 8;

        public const uint D3DVSDT_FLOAT1 = 0x00;

        public const uint D3DVSDT_FLOAT2 = 0x01;

        public const uint D3DVSDT_FLOAT3 = 0x02;

        public const uint D3DVSDT_FLOAT4 = 0x03;

        public const uint D3DVSDT_D3DCOLOR = 0x04;

        public const uint D3DVSDT_UBYTE4 = 0x05;

        public const uint D3DVSDT_SHORT2 = 0x06;

        public const uint D3DVSDT_SHORT4 = 0x07;

        public const uint D3DVSDE_POSITION = 0;

        public const uint D3DVSDE_BLENDWEIGHT = 1;

        public const uint D3DVSDE_BLENDINDICES = 2;

        public const uint D3DVSDE_NORMAL = 3;

        public const uint D3DVSDE_PSIZE = 4;

        public const uint D3DVSDE_DIFFUSE = 5;

        public const uint D3DVSDE_SPECULAR = 6;

        public const uint D3DVSDE_TEXCOORD0 = 7;

        public const uint D3DVSDE_TEXCOORD1 = 8;

        public const uint D3DVSDE_TEXCOORD2 = 9;

        public const uint D3DVSDE_TEXCOORD3 = 10;

        public const uint D3DVSDE_TEXCOORD4 = 11;

        public const uint D3DVSDE_TEXCOORD5 = 12;

        public const uint D3DVSDE_TEXCOORD6 = 13;

        public const uint D3DVSDE_TEXCOORD7 = 14;

        public const uint D3DVSDE_POSITION2 = 15;

        public const uint D3DVSDE_NORMAL2 = 16;

        public const uint D3DVSD_TOKENTYPESHIFT = 29;

        public const uint D3DVSD_STREAMNUMBERSHIFT = 0;

        public const uint D3DVSD_DATALOADTYPESHIFT = 28;

        public const uint D3DVSD_DATATYPESHIFT = 16;

        public const uint D3DVSD_SKIPCOUNTSHIFT = 16;

        public const uint D3DVSD_VERTEXREGSHIFT = 0;

        public const uint D3DVSD_VERTEXREGINSHIFT = 20;

        public const uint D3DVSD_CONSTCOUNTSHIFT = 25;

        public const uint D3DVSD_CONSTADDRESSSHIFT = 0;

        public const uint D3DVSD_CONSTRSSHIFT = 16;

        public const uint D3DVSD_EXTCOUNTSHIFT = 24;

        public const uint D3DVSD_EXTINFOSHIFT = 0;

        public const uint D3DVSD_STREAMTESSSHIFT = 28;

        public const uint DIRECT3D_VERSION = 0x0700;

        public const int D3DTRANSFORMCAPS_CLIP = 0x00000001;

        public const int D3DLIGHTINGMODEL_RGB = 0x00000001;

        public const int D3DLIGHTINGMODEL_MONO = 0x00000002;

        public const int D3DLIGHTCAPS_POINT = 0x00000001;

        public const int D3DLIGHTCAPS_SPOT = 0x00000002;

        public const int D3DLIGHTCAPS_DIRECTIONAL = 0x00000004;

        public const int D3DLIGHTCAPS_PARALLELPOINT = 0x00000008;

        public const int D3DLIGHTCAPS_GLSPOT = 0x00000010;

        public const int D3DPMISCCAPS_MASKPLANES = 0x00000001;

        public const int D3DPMISCCAPS_MASKZ = 0x00000002;

        public const int D3DPMISCCAPS_CONFORMANT = 0x00000008;

        public const int D3DPMISCCAPS_CULLNONE = 0x00000010;

        public const int D3DPMISCCAPS_CULLCW = 0x00000020;

        public const int D3DPMISCCAPS_CULLCCW = 0x00000040;

        public const int D3DPRASTERCAPS_DITHER = 0x00000001;

        public const int D3DPRASTERCAPS_ROP2 = 0x00000002;

        public const int D3DPRASTERCAPS_XOR = 0x00000004;

        public const int D3DPRASTERCAPS_PAT = 0x00000008;

        public const int D3DPRASTERCAPS_ZTEST = 0x00000010;

        public const int D3DPRASTERCAPS_SUBPIXEL = 0x00000020;

        public const int D3DPRASTERCAPS_SUBPIXELX = 0x00000040;

        public const int D3DPRASTERCAPS_FOGVERTEX = 0x00000080;

        public const int D3DPRASTERCAPS_FOGTABLE = 0x00000100;

        public const int D3DPRASTERCAPS_STIPPLE = 0x00000200;

        public const int D3DPRASTERCAPS_ANTIALIASSORTDEPENDENT = 0x00000400;

        public const int D3DPRASTERCAPS_ANTIALIASSORTINDEPENDENT = 0x00000800;

        public const int D3DPRASTERCAPS_ANTIALIASEDGES = 0x00001000;

        public const int D3DPRASTERCAPS_MIPMAPLODBIAS = 0x00002000;

        public const int D3DPRASTERCAPS_ZBIAS = 0x00004000;

        public const int D3DPRASTERCAPS_ZBUFFERLESSHSR = 0x00008000;

        public const int D3DPRASTERCAPS_FOGRANGE = 0x00010000;

        public const int D3DPRASTERCAPS_ANISOTROPY = 0x00020000;

        public const int D3DPRASTERCAPS_WBUFFER = 0x00040000;

        public const int D3DPRASTERCAPS_TRANSLUCENTSORTINDEPENDENT = 0x00080000;

        public const int D3DPRASTERCAPS_WFOG = 0x00100000;

        public const int D3DPRASTERCAPS_ZFOG = 0x00200000;

        public const int D3DPCMPCAPS_NEVER = 0x00000001;

        public const int D3DPCMPCAPS_LESS = 0x00000002;

        public const int D3DPCMPCAPS_EQUAL = 0x00000004;

        public const int D3DPCMPCAPS_LESSEQUAL = 0x00000008;

        public const int D3DPCMPCAPS_GREATER = 0x00000010;

        public const int D3DPCMPCAPS_NOTEQUAL = 0x00000020;

        public const int D3DPCMPCAPS_GREATEREQUAL = 0x00000040;

        public const int D3DPCMPCAPS_ALWAYS = 0x00000080;

        public const int D3DPBLENDCAPS_ZERO = 0x00000001;

        public const int D3DPBLENDCAPS_ONE = 0x00000002;

        public const int D3DPBLENDCAPS_SRCCOLOR = 0x00000004;

        public const int D3DPBLENDCAPS_INVSRCCOLOR = 0x00000008;

        public const int D3DPBLENDCAPS_SRCALPHA = 0x00000010;

        public const int D3DPBLENDCAPS_INVSRCALPHA = 0x00000020;

        public const int D3DPBLENDCAPS_DESTALPHA = 0x00000040;

        public const int D3DPBLENDCAPS_INVDESTALPHA = 0x00000080;

        public const int D3DPBLENDCAPS_DESTCOLOR = 0x00000100;

        public const int D3DPBLENDCAPS_INVDESTCOLOR = 0x00000200;

        public const int D3DPBLENDCAPS_SRCALPHASAT = 0x00000400;

        public const int D3DPBLENDCAPS_BOTHSRCALPHA = 0x00000800;

        public const int D3DPBLENDCAPS_BOTHINVSRCALPHA = 0x00001000;

        public const int D3DPSHADECAPS_COLORFLATMONO = 0x00000001;

        public const int D3DPSHADECAPS_COLORFLATRGB = 0x00000002;

        public const int D3DPSHADECAPS_COLORGOURAUDMONO = 0x00000004;

        public const int D3DPSHADECAPS_COLORGOURAUDRGB = 0x00000008;

        public const int D3DPSHADECAPS_COLORPHONGMONO = 0x00000010;

        public const int D3DPSHADECAPS_COLORPHONGRGB = 0x00000020;

        public const int D3DPSHADECAPS_SPECULARFLATMONO = 0x00000040;

        public const int D3DPSHADECAPS_SPECULARFLATRGB = 0x00000080;

        public const int D3DPSHADECAPS_SPECULARGOURAUDMONO = 0x00000100;

        public const int D3DPSHADECAPS_SPECULARGOURAUDRGB = 0x00000200;

        public const int D3DPSHADECAPS_SPECULARPHONGMONO = 0x00000400;

        public const int D3DPSHADECAPS_SPECULARPHONGRGB = 0x00000800;

        public const int D3DPSHADECAPS_ALPHAFLATBLEND = 0x00001000;

        public const int D3DPSHADECAPS_ALPHAFLATSTIPPLED = 0x00002000;

        public const int D3DPSHADECAPS_ALPHAGOURAUDBLEND = 0x00004000;

        public const int D3DPSHADECAPS_ALPHAGOURAUDSTIPPLED = 0x00008000;

        public const int D3DPSHADECAPS_ALPHAPHONGBLEND = 0x00010000;

        public const int D3DPSHADECAPS_ALPHAPHONGSTIPPLED = 0x00020000;

        public const int D3DPSHADECAPS_FOGFLAT = 0x00040000;

        public const int D3DPSHADECAPS_FOGGOURAUD = 0x00080000;

        public const int D3DPSHADECAPS_FOGPHONG = 0x00100000;

        public const int D3DPTEXTURECAPS_PERSPECTIVE = 0x00000001;

        public const int D3DPTEXTURECAPS_POW2 = 0x00000002;

        public const int D3DPTEXTURECAPS_ALPHA = 0x00000004;

        public const int D3DPTEXTURECAPS_TRANSPARENCY = 0x00000008;

        public const int D3DPTEXTURECAPS_BORDER = 0x00000010;

        public const int D3DPTEXTURECAPS_SQUAREONLY = 0x00000020;

        public const int D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE = 0x00000040;

        public const int D3DPTEXTURECAPS_ALPHAPALETTE = 0x00000080;

        public const int D3DPTEXTURECAPS_NONPOW2CONDITIONAL = 0x00000100;

        public const int D3DPTEXTURECAPS_PROJECTED = 0x00000400;

        public const int D3DPTEXTURECAPS_CUBEMAP = 0x00000800;

        public const int D3DPTEXTURECAPS_COLORKEYBLEND = 0x00001000;

        public const int D3DPTFILTERCAPS_NEAREST = 0x00000001;

        public const int D3DPTFILTERCAPS_LINEAR = 0x00000002;

        public const int D3DPTFILTERCAPS_MIPNEAREST = 0x00000004;

        public const int D3DPTFILTERCAPS_MIPLINEAR = 0x00000008;

        public const int D3DPTFILTERCAPS_LINEARMIPNEAREST = 0x00000010;

        public const int D3DPTFILTERCAPS_LINEARMIPLINEAR = 0x00000020;

        public const int D3DPTFILTERCAPS_MINFPOINT = 0x00000100;

        public const int D3DPTFILTERCAPS_MINFLINEAR = 0x00000200;

        public const int D3DPTFILTERCAPS_MINFANISOTROPIC = 0x00000400;

        public const int D3DPTFILTERCAPS_MIPFPOINT = 0x00010000;

        public const int D3DPTFILTERCAPS_MIPFLINEAR = 0x00020000;

        public const int D3DPTFILTERCAPS_MAGFPOINT = 0x01000000;

        public const int D3DPTFILTERCAPS_MAGFLINEAR = 0x02000000;

        public const int D3DPTFILTERCAPS_MAGFANISOTROPIC = 0x04000000;

        public const int D3DPTFILTERCAPS_MAGFAFLATCUBIC = 0x08000000;

        public const int D3DPTFILTERCAPS_MAGFGAUSSIANCUBIC = 0x10000000;

        public const int D3DPTBLENDCAPS_DECAL = 0x00000001;

        public const int D3DPTBLENDCAPS_MODULATE = 0x00000002;

        public const int D3DPTBLENDCAPS_DECALALPHA = 0x00000004;

        public const int D3DPTBLENDCAPS_MODULATEALPHA = 0x00000008;

        public const int D3DPTBLENDCAPS_DECALMASK = 0x00000010;

        public const int D3DPTBLENDCAPS_MODULATEMASK = 0x00000020;

        public const int D3DPTBLENDCAPS_COPY = 0x00000040;

        public const int D3DPTBLENDCAPS_ADD = 0x00000080;

        public const int D3DPTADDRESSCAPS_WRAP = 0x00000001;

        public const int D3DPTADDRESSCAPS_MIRROR = 0x00000002;

        public const int D3DPTADDRESSCAPS_CLAMP = 0x00000004;

        public const int D3DPTADDRESSCAPS_BORDER = 0x00000008;

        public const int D3DPTADDRESSCAPS_INDEPENDENTUV = 0x00000010;

        public const int D3DSTENCILCAPS_KEEP = 0x00000001;

        public const int D3DSTENCILCAPS_ZERO = 0x00000002;

        public const int D3DSTENCILCAPS_REPLACE = 0x00000004;

        public const int D3DSTENCILCAPS_INCRSAT = 0x00000008;

        public const int D3DSTENCILCAPS_DECRSAT = 0x00000010;

        public const int D3DSTENCILCAPS_INVERT = 0x00000020;

        public const int D3DSTENCILCAPS_INCR = 0x00000040;

        public const int D3DSTENCILCAPS_DECR = 0x00000080;

        public const int D3DTEXOPCAPS_DISABLE = 0x00000001;

        public const int D3DTEXOPCAPS_SELECTARG1 = 0x00000002;

        public const int D3DTEXOPCAPS_SELECTARG2 = 0x00000004;

        public const int D3DTEXOPCAPS_MODULATE = 0x00000008;

        public const int D3DTEXOPCAPS_MODULATE2X = 0x00000010;

        public const int D3DTEXOPCAPS_MODULATE4X = 0x00000020;

        public const int D3DTEXOPCAPS_ADD = 0x00000040;

        public const int D3DTEXOPCAPS_ADDSIGNED = 0x00000080;

        public const int D3DTEXOPCAPS_ADDSIGNED2X = 0x00000100;

        public const int D3DTEXOPCAPS_SUBTRACT = 0x00000200;

        public const int D3DTEXOPCAPS_ADDSMOOTH = 0x00000400;

        public const int D3DTEXOPCAPS_BLENDDIFFUSEALPHA = 0x00000800;

        public const int D3DTEXOPCAPS_BLENDTEXTUREALPHA = 0x00001000;

        public const int D3DTEXOPCAPS_BLENDFACTORALPHA = 0x00002000;

        public const int D3DTEXOPCAPS_BLENDTEXTUREALPHAPM = 0x00004000;

        public const int D3DTEXOPCAPS_BLENDCURRENTALPHA = 0x00008000;

        public const int D3DTEXOPCAPS_PREMODULATE = 0x00010000;

        public const int D3DTEXOPCAPS_MODULATEALPHA_ADDCOLOR = 0x00020000;

        public const int D3DTEXOPCAPS_MODULATECOLOR_ADDALPHA = 0x00040000;

        public const int D3DTEXOPCAPS_MODULATEINVALPHA_ADDCOLOR = 0x00080000;

        public const int D3DTEXOPCAPS_MODULATEINVCOLOR_ADDALPHA = 0x00100000;

        public const int D3DTEXOPCAPS_BUMPENVMAP = 0x00200000;

        public const int D3DTEXOPCAPS_BUMPENVMAPLUMINANCE = 0x00400000;

        public const int D3DTEXOPCAPS_DOTPRODUCT3 = 0x00800000;

        public const int D3DFVFCAPS_TEXCOORDCOUNTMASK = 0x0000ffff;

        public const int D3DFVFCAPS_DONOTSTRIPELEMENTS = 0x00080000;

        public const int D3DDD_COLORMODEL = 0x00000001;

        public const int D3DDD_DEVCAPS = 0x00000002;

        public const int D3DDD_TRANSFORMCAPS = 0x00000004;

        public const int D3DDD_LIGHTINGCAPS = 0x00000008;

        public const int D3DDD_BCLIPPING = 0x00000010;

        public const int D3DDD_LINECAPS = 0x00000020;

        public const int D3DDD_TRICAPS = 0x00000040;

        public const int D3DDD_DEVICERENDERBITDEPTH = 0x00000080;

        public const int D3DDD_DEVICEZBUFFERBITDEPTH = 0x00000100;

        public const int D3DDD_MAXBUFFERSIZE = 0x00000200;

        public const int D3DDD_MAXVERTEXCOUNT = 0x00000400;

        public const int D3DDEVCAPS_FLOATTLVERTEX = 0x00000001;

        public const int D3DDEVCAPS_SORTINCREASINGZ = 0x00000002;

        public const int D3DDEVCAPS_SORTDECREASINGZ = 0X00000004;

        public const int D3DDEVCAPS_SORTEXACT = 0x00000008;

        public const int D3DDEVCAPS_EXECUTESYSTEMMEMORY = 0x00000010;

        public const int D3DDEVCAPS_EXECUTEVIDEOMEMORY = 0x00000020;

        public const int D3DDEVCAPS_TLVERTEXSYSTEMMEMORY = 0x00000040;

        public const int D3DDEVCAPS_TLVERTEXVIDEOMEMORY = 0x00000080;

        public const int D3DDEVCAPS_TEXTURESYSTEMMEMORY = 0x00000100;

        public const int D3DDEVCAPS_TEXTUREVIDEOMEMORY = 0x00000200;

        public const int D3DDEVCAPS_DRAWPRIMTLVERTEX = 0x00000400;

        public const int D3DDEVCAPS_CANRENDERAFTERFLIP = 0x00000800;

        public const int D3DDEVCAPS_TEXTURENONLOCALVIDMEM = 0x00001000;

        public const int D3DDEVCAPS_DRAWPRIMITIVES2 = 0x00002000;

        public const int D3DDEVCAPS_SEPARATETEXTUREMEMORIES = 0x00004000;

        public const int D3DDEVCAPS_DRAWPRIMITIVES2EX = 0x00008000;

        public const int D3DDEVCAPS_HWTRANSFORMANDLIGHT = 0x00010000;

        public const int D3DDEVCAPS_CANBLTSYSTONONLOCAL = 0x00020000;

        public const int D3DDEVCAPS_HWRASTERIZATION = 0x00080000;

        public const int D3DVTXPCAPS_TEXGEN = 0x00000001;

        public const int D3DVTXPCAPS_MATERIALSOURCE7 = 0x00000002;

        public const int D3DVTXPCAPS_VERTEXFOG = 0x00000004;

        public const int D3DVTXPCAPS_DIRECTIONALLIGHTS = 0x00000008;

        public const int D3DVTXPCAPS_POSITIONALLIGHTS = 0x00000010;

        public const int D3DVTXPCAPS_LOCALVIEWER = 0x00000020;

        public const int D3DFDS_COLORMODEL = 0x00000001;

        public const int D3DFDS_GUID = 0x00000002;

        public const int D3DFDS_HARDWARE = 0x00000004;

        public const int D3DFDS_TRIANGLES = 0x00000008;

        public const int D3DFDS_LINES = 0x00000010;

        public const int D3DFDS_MISCCAPS = 0x00000020;

        public const int D3DFDS_RASTERCAPS = 0x00000040;

        public const int D3DFDS_ZCMPCAPS = 0x00000080;

        public const int D3DFDS_ALPHACMPCAPS = 0x00000100;

        public const int D3DFDS_SRCBLENDCAPS = 0x00000200;

        public const int D3DFDS_DSTBLENDCAPS = 0x00000400;

        public const int D3DFDS_SHADECAPS = 0x00000800;

        public const int D3DFDS_TEXTURECAPS = 0x00001000;

        public const int D3DFDS_TEXTUREFILTERCAPS = 0x00002000;

        public const int D3DFDS_TEXTUREBLENDCAPS = 0x00004000;

        public const int D3DFDS_TEXTUREADDRESSCAPS = 0x00008000;

        public const int D3DDEB_BUFSIZE = 0x00000001;

        public const int D3DDEB_CAPS = 0x00000002;

        public const int D3DDEB_LPDATA = 0x00000004;

        public const int D3DDEBCAPS_SYSTEMMEMORY = 0x00000001;

        public const int D3DDEBCAPS_VIDEOMEMORY = 0x00000002;

        public const uint D3DMAXUSERCLIPPLANES = 32;

        public const uint D3DCLIPPLANE0 = 1u<< 0;

        public const uint D3DCLIPPLANE1 = 1u<< 1;

        public const uint D3DCLIPPLANE2 = 1u<< 2;

        public const uint D3DCLIPPLANE3 = 1u<< 3;

        public const uint D3DCLIPPLANE4 = 1u<< 4;

        public const uint D3DCLIPPLANE5 = 1u<< 5;

        public const int D3DCLIP_LEFT = 0x00000001;

        public const int D3DCLIP_RIGHT = 0x00000002;

        public const int D3DCLIP_TOP = 0x00000004;

        public const int D3DCLIP_BOTTOM = 0x00000008;

        public const int D3DCLIP_FRONT = 0x00000010;

        public const int D3DCLIP_BACK = 0x00000020;

        public const int D3DCLIP_GEN0 = 0x00000040;

        public const int D3DCLIP_GEN1 = 0x00000080;

        public const int D3DCLIP_GEN2 = 0x00000100;

        public const int D3DCLIP_GEN3 = 0x00000200;

        public const int D3DCLIP_GEN4 = 0x00000400;

        public const int D3DCLIP_GEN5 = 0x00000800;

        public const int D3DSTATUS_CLIPINTERSECTIONLEFT = 0x00001000;

        public const int D3DSTATUS_CLIPINTERSECTIONRIGHT = 0x00002000;

        public const int D3DSTATUS_CLIPINTERSECTIONTOP = 0x00004000;

        public const int D3DSTATUS_CLIPINTERSECTIONBOTTOM = 0x00008000;

        public const int D3DSTATUS_CLIPINTERSECTIONFRONT = 0x00010000;

        public const int D3DSTATUS_CLIPINTERSECTIONBACK = 0x00020000;

        public const int D3DSTATUS_CLIPINTERSECTIONGEN0 = 0x00040000;

        public const int D3DSTATUS_CLIPINTERSECTIONGEN1 = 0x00080000;

        public const int D3DSTATUS_CLIPINTERSECTIONGEN2 = 0x00100000;

        public const int D3DSTATUS_CLIPINTERSECTIONGEN3 = 0x00200000;

        public const int D3DSTATUS_CLIPINTERSECTIONGEN4 = 0x00400000;

        public const int D3DSTATUS_CLIPINTERSECTIONGEN5 = 0x00800000;

        public const int D3DSTATUS_ZNOTVISIBLE = 0x01000000;

        public const int D3DTRANSFORM_CLIPPED = 0x00000001;

        public const int D3DTRANSFORM_UNCLIPPED = 0x00000002;

        public const uint D3DLIGHT_ACTIVE = 0x00000001;

        public const uint D3DLIGHT_NO_SPECULAR = 0x00000002;

        public const uint D3DCOLOR_MONO = 1;

        public const uint D3DCOLOR_RGB = 2;

        public const int D3DCLEAR_TARGET = 0x00000001;

        public const int D3DCLEAR_ZBUFFER = 0x00000002;

        public const int D3DCLEAR_STENCIL = 0x00000004;

        public const uint D3DSTATE_OVERRIDE_BIAS = 256;

        public const uint D3DRENDERSTATE_WRAPBIAS = 128;

        public const int D3DWRAP_U = 0x00000001;

        public const int D3DWRAP_V = 0x00000002;

        public const int D3DWRAPCOORD_0 = 0x00000001;

        public const int D3DWRAPCOORD_1 = 0x00000002;

        public const int D3DWRAPCOORD_2 = 0x00000004;

        public const int D3DWRAPCOORD_3 = 0x00000008;

        public const int D3DPROCESSVERTICES_TRANSFORMLIGHT = 0x00000000;

        public const int D3DPROCESSVERTICES_TRANSFORM = 0x00000001;

        public const int D3DPROCESSVERTICES_COPY = 0x00000002;

        public const int D3DPROCESSVERTICES_OPMASK = 0x00000007;

        public const int D3DPROCESSVERTICES_UPDATEEXTENTS = 0x00000008;

        public const int D3DPROCESSVERTICES_NOCOLOR = 0x00000010;

        public const uint D3DTSS_TCI_PASSTHRU = 0x00000000;

        public const uint D3DTSS_TCI_CAMERASPACENORMAL = 0x00010000;

        public const uint D3DTSS_TCI_CAMERASPACEPOSITION = 0x00020000;

        public const uint D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR = 0x00030000;

        public const uint D3DTA_SELECTMASK = 0x0000000f;

        public const uint D3DTA_DIFFUSE = 0x00000000;

        public const uint D3DTA_CURRENT = 0x00000001;

        public const uint D3DTA_TEXTURE = 0x00000002;

        public const uint D3DTA_TFACTOR = 0x00000003;

        public const uint D3DTA_SPECULAR = 0x00000004;

        public const uint D3DTA_COMPLEMENT = 0x00000010;

        public const uint D3DTA_ALPHAREPLICATE = 0x00000020;

        public const int D3DTRIFLAG_START = 0x00000000;

        public const int D3DTRIFLAG_ODD = 0x0000001e;

        public const int D3DTRIFLAG_EVEN = 0x0000001f;

        public const int D3DTRIFLAG_EDGEENABLE1 = 0x00000100;

        public const int D3DTRIFLAG_EDGEENABLE2 = 0x00000200;

        public const int D3DTRIFLAG_EDGEENABLE3 = 0x00000400;

        public const int D3DSETSTATUS_STATUS = 0x00000001;

        public const int D3DSETSTATUS_EXTENTS = 0x00000002;

        public const int D3DCLIPSTATUS_STATUS = 0x00000001;

        public const int D3DCLIPSTATUS_EXTENTS2 = 0x00000002;

        public const int D3DCLIPSTATUS_EXTENTS3 = 0x00000004;

        public const int D3DEXECUTE_CLIPPED = 0x00000001;

        public const int D3DEXECUTE_UNCLIPPED = 0x00000002;

        public const uint D3DPAL_FREE = 0x00;

        public const uint D3DPAL_READONLY = 0x40;

        public const uint D3DPAL_RESERVED = 0x80;

        public const int D3DVBCAPS_SYSTEMMEMORY = 0x00000800;

        public const int D3DVBCAPS_WRITEONLY = 0x00010000;

        public const int D3DVBCAPS_OPTIMIZED = unchecked((int)0x80000000);

        public const int D3DVBCAPS_DONOTCLIP = 0x00000001;

        public const uint D3DVOP_LIGHT = 1u<< 10;

        public const uint D3DVOP_TRANSFORM = 1u<< 0;

        public const uint D3DVOP_CLIP = 1u<< 2;

        public const uint D3DVOP_EXTENTS = 1u<< 3;

        public const uint D3DPV_DONOTCOPYDATA = 1u<< 0;

        public const uint D3DFVF_RESERVED0 = 0x001;

        public const uint D3DFVF_POSITION_MASK = 0x00E;

        public const uint D3DFVF_XYZ = 0x002;

        public const uint D3DFVF_XYZRHW = 0x004;

        public const uint D3DFVF_XYZB1 = 0x006;

        public const uint D3DFVF_XYZB2 = 0x008;

        public const uint D3DFVF_XYZB3 = 0x00a;

        public const uint D3DFVF_XYZB4 = 0x00c;

        public const uint D3DFVF_XYZB5 = 0x00e;

        public const uint D3DFVF_NORMAL = 0x010;

        public const uint D3DFVF_RESERVED1 = 0x020;

        public const uint D3DFVF_DIFFUSE = 0x040;

        public const uint D3DFVF_SPECULAR = 0x080;

        public const uint D3DFVF_TEXCOUNT_MASK = 0xf00;

        public const uint D3DFVF_TEXCOUNT_SHIFT = 8;

        public const uint D3DFVF_TEX0 = 0x000;

        public const uint D3DFVF_TEX1 = 0x100;

        public const uint D3DFVF_TEX2 = 0x200;

        public const uint D3DFVF_TEX3 = 0x300;

        public const uint D3DFVF_TEX4 = 0x400;

        public const uint D3DFVF_TEX5 = 0x500;

        public const uint D3DFVF_TEX6 = 0x600;

        public const uint D3DFVF_TEX7 = 0x700;

        public const uint D3DFVF_TEX8 = 0x800;

        public const uint D3DFVF_RESERVED2 = 0xf000;

        public const uint D3DDP_MAXTEXCOORD = 8;

        public const uint D3DVIS_INSIDE_FRUSTUM = 0;

        public const uint D3DVIS_INTERSECT_FRUSTUM = 1;

        public const uint D3DVIS_OUTSIDE_FRUSTUM = 2;

        public const uint D3DVIS_INSIDE_LEFT = 0;

        public const uint D3DVIS_INTERSECT_LEFT = 1u<< 2;

        public const uint D3DVIS_OUTSIDE_LEFT = 2u<< 2;

        public const uint D3DVIS_INSIDE_RIGHT = 0;

        public const uint D3DVIS_INTERSECT_RIGHT = 1u<< 4;

        public const uint D3DVIS_OUTSIDE_RIGHT = 2u<< 4;

        public const uint D3DVIS_INSIDE_TOP = 0;

        public const uint D3DVIS_INTERSECT_TOP = 1u<< 6;

        public const uint D3DVIS_OUTSIDE_TOP = 2u<< 6;

        public const uint D3DVIS_INSIDE_BOTTOM = 0;

        public const uint D3DVIS_INTERSECT_BOTTOM = 1u<< 8;

        public const uint D3DVIS_OUTSIDE_BOTTOM = 2u<< 8;

        public const uint D3DVIS_INSIDE_NEAR = 0;

        public const uint D3DVIS_INTERSECT_NEAR = 1u<< 10;

        public const uint D3DVIS_OUTSIDE_NEAR = 2u<< 10;

        public const uint D3DVIS_INSIDE_FAR = 0;

        public const uint D3DVIS_INTERSECT_FAR = 1u<< 12;

        public const uint D3DVIS_OUTSIDE_FAR = 2u<< 12;

        public const uint D3DVIS_MASK_FRUSTUM = 3u<< 0;

        public const uint D3DVIS_MASK_LEFT = 3u<< 2;

        public const uint D3DVIS_MASK_RIGHT = 3u<< 4;

        public const uint D3DVIS_MASK_TOP = 3u<< 6;

        public const uint D3DVIS_MASK_BOTTOM = 3u<< 8;

        public const uint D3DVIS_MASK_NEAR = 3u<< 10;

        public const uint D3DVIS_MASK_FAR = 3u<< 12;

        public const uint D3DDEVINFOID_TEXTUREMANAGER = 1;

        public const uint D3DDEVINFOID_D3DTEXTUREMANAGER = 2;

        public const uint D3DDEVINFOID_TEXTURING = 3;

        public const uint D3DFVF_TEXTUREFORMAT2 = 0;

        public const uint D3DFVF_TEXTUREFORMAT1 = 3;

        public const uint D3DFVF_TEXTUREFORMAT3 = 1;

        public const uint D3DFVF_TEXTUREFORMAT4 = 2;

        public const uint FD_ERROR = 0xFFFFFFFF;

        public const uint DDI_ERROR = 0xFFFFFFFF;

        public const uint FDM_TYPE_BM_SIDE_CONST = 0x00000001;

        public const uint FDM_TYPE_MAXEXT_EQUAL_BM_SIDE = 0x00000002;

        public const uint FDM_TYPE_CHAR_INC_EQUAL_BM_BASE = 0x00000004;

        public const uint FDM_TYPE_ZERO_BEARINGS = 0x00000008;

        public const uint FDM_TYPE_CONST_BEARINGS = 0x00000010;

        public const uint GS_UNICODE_HANDLES = 0x00000001;

        public const uint GS_8BIT_HANDLES = 0x00000002;

        public const uint GS_16BIT_HANDLES = 0x00000004;

        public const uint FM_VERSION_NUMBER = 0x0;

        public const uint FM_TYPE_LICENSED = 0x2;

        public const uint FM_READONLY_EMBED = 0x4;

        public const uint FM_EDITABLE_EMBED = 0x8;

        public const uint FM_INFO_TECH_TRUETYPE = 0x00000001;

        public const uint FM_INFO_TECH_BITMAP = 0x00000002;

        public const uint FM_INFO_TECH_STROKE = 0x00000004;

        public const uint FM_INFO_TECH_OUTLINE_NOT_TRUETYPE = 0x00000008;

        public const uint FM_INFO_ARB_XFORMS = 0x00000010;

        public const uint FM_INFO_1BPP = 0x00000020;

        public const uint FM_INFO_4BPP = 0x00000040;

        public const uint FM_INFO_8BPP = 0x00000080;

        public const uint FM_INFO_16BPP = 0x00000100;

        public const uint FM_INFO_24BPP = 0x00000200;

        public const uint FM_INFO_32BPP = 0x00000400;

        public const uint FM_INFO_INTEGER_WIDTH = 0x00000800;

        public const uint FM_INFO_CONSTANT_WIDTH = 0x00001000;

        public const uint FM_INFO_NOT_CONTIGUOUS = 0x00002000;

        public const uint FM_INFO_TECH_MM = 0x00004000;

        public const uint FM_INFO_RETURNS_OUTLINES = 0x00008000;

        public const uint FM_INFO_RETURNS_STROKES = 0x00010000;

        public const uint FM_INFO_RETURNS_BITMAPS = 0x00020000;

        public const uint FM_INFO_DSIG = 0x00040000;

        public const uint FM_INFO_RIGHT_HANDED = 0x00080000;

        public const uint FM_INFO_INTEGRAL_SCALING = 0x00100000;

        public const uint FM_INFO_90DEGREE_ROTATIONS = 0x00200000;

        public const uint FM_INFO_OPTICALLY_FIXED_PITCH = 0x00400000;

        public const uint FM_INFO_DO_NOT_ENUMERATE = 0x00800000;

        public const uint FM_INFO_ISOTROPIC_SCALING_ONLY = 0x01000000;

        public const uint FM_INFO_ANISOTROPIC_SCALING_ONLY = 0x02000000;

        public const uint FM_INFO_TECH_CFF = 0x04000000;

        public const uint FM_INFO_FAMILY_EQUIV = 0x08000000;

        public const uint FM_INFO_DBCS_FIXED_PITCH = 0x10000000;

        public const uint FM_INFO_NONNEGATIVE_AC = 0x20000000;

        public const uint FM_INFO_IGNORE_TC_RA_ABLE = 0x40000000;

        public const uint FM_INFO_TECH_TYPE1 = 0x80000000;

        public const uint MAXCHARSETS = 16;

        public const uint FM_PANOSE_CULTURE_LATIN = 0x0;

        public const uint FM_SEL_ITALIC = 0x0001;

        public const uint FM_SEL_UNDERSCORE = 0x0002;

        public const uint FM_SEL_NEGATIVE = 0x0004;

        public const uint FM_SEL_OUTLINED = 0x0008;

        public const uint FM_SEL_STRIKEOUT = 0x0010;

        public const uint FM_SEL_BOLD = 0x0020;

        public const uint FM_SEL_REGULAR = 0x0040;

        public const uint OPENGL_CMD = 4352;

        public const uint OPENGL_GETINFO = 4353;

        public const uint WNDOBJ_SETUP = 4354;

        public const uint DDI_DRIVER_VERSION_NT4 = 0x00020000;

        public const uint DDI_DRIVER_VERSION_SP3 = 0x00020003;

        public const uint DDI_DRIVER_VERSION_NT5 = 0x00030000;

        public const uint DDI_DRIVER_VERSION_NT5_01 = 0x00030100;

        public const uint DDI_DRIVER_VERSION_NT5_01_SP1 = 0x00030101;

        public const uint GDI_DRIVER_VERSION = 0x4000;

        public const int INDEX_DrvEnablePDEV = 0;

        public const int INDEX_DrvCompletePDEV = 1;

        public const int INDEX_DrvDisablePDEV = 2;

        public const int INDEX_DrvEnableSurface = 3;

        public const int INDEX_DrvDisableSurface = 4;

        public const int INDEX_DrvAssertMode = 5;

        public const int INDEX_DrvOffset = 6;

        public const int INDEX_DrvResetPDEV = 7;

        public const int INDEX_DrvDisableDriver = 8;

        public const int INDEX_DrvCreateDeviceBitmap = 10;

        public const int INDEX_DrvDeleteDeviceBitmap = 11;

        public const int INDEX_DrvRealizeBrush = 12;

        public const int INDEX_DrvDitherColor = 13;

        public const int INDEX_DrvStrokePath = 14;

        public const int INDEX_DrvFillPath = 15;

        public const int INDEX_DrvStrokeAndFillPath = 16;

        public const int INDEX_DrvPaint = 17;

        public const int INDEX_DrvBitBlt = 18;

        public const int INDEX_DrvCopyBits = 19;

        public const int INDEX_DrvStretchBlt = 20;

        public const int INDEX_DrvSetPalette = 22;

        public const int INDEX_DrvTextOut = 23;

        public const int INDEX_DrvEscape = 24;

        public const int INDEX_DrvDrawEscape = 25;

        public const int INDEX_DrvQueryFont = 26;

        public const int INDEX_DrvQueryFontTree = 27;

        public const int INDEX_DrvQueryFontData = 28;

        public const int INDEX_DrvSetPointerShape = 29;

        public const int INDEX_DrvMovePointer = 30;

        public const int INDEX_DrvLineTo = 31;

        public const int INDEX_DrvSendPage = 32;

        public const int INDEX_DrvStartPage = 33;

        public const int INDEX_DrvEndDoc = 34;

        public const int INDEX_DrvStartDoc = 35;

        public const int INDEX_DrvGetGlyphMode = 37;

        public const int INDEX_DrvSynchronize = 38;

        public const int INDEX_DrvSaveScreenBits = 40;

        public const int INDEX_DrvGetModes = 41;

        public const int INDEX_DrvFree = 42;

        public const int INDEX_DrvDestroyFont = 43;

        public const int INDEX_DrvQueryFontCaps = 44;

        public const int INDEX_DrvLoadFontFile = 45;

        public const int INDEX_DrvUnloadFontFile = 46;

        public const int INDEX_DrvFontManagement = 47;

        public const int INDEX_DrvQueryTrueTypeTable = 48;

        public const int INDEX_DrvQueryTrueTypeOutline = 49;

        public const int INDEX_DrvGetTrueTypeFile = 50;

        public const int INDEX_DrvQueryFontFile = 51;

        public const int INDEX_DrvMovePanning = 52;

        public const int INDEX_DrvQueryAdvanceWidths = 53;

        public const int INDEX_DrvSetPixelFormat = 54;

        public const int INDEX_DrvDescribePixelFormat = 55;

        public const int INDEX_DrvSwapBuffers = 56;

        public const int INDEX_DrvStartBanding = 57;

        public const int INDEX_DrvNextBand = 58;

        public const int INDEX_DrvGetDirectDrawInfo = 59;

        public const int INDEX_DrvEnableDirectDraw = 60;

        public const int INDEX_DrvDisableDirectDraw = 61;

        public const int INDEX_DrvQuerySpoolType = 62;

        public const int INDEX_DrvIcmCreateColorTransform = 64;

        public const int INDEX_DrvIcmDeleteColorTransform = 65;

        public const int INDEX_DrvIcmCheckBitmapBits = 66;

        public const int INDEX_DrvIcmSetDeviceGammaRamp = 67;

        public const int INDEX_DrvGradientFill = 68;

        public const int INDEX_DrvStretchBltROP = 69;

        public const int INDEX_DrvPlgBlt = 70;

        public const int INDEX_DrvAlphaBlend = 71;

        public const int INDEX_DrvSynthesizeFont = 72;

        public const int INDEX_DrvGetSynthesizedFontFiles = 73;

        public const int INDEX_DrvTransparentBlt = 74;

        public const int INDEX_DrvQueryPerBandInfo = 75;

        public const int INDEX_DrvQueryDeviceSupport = 76;

        public const int INDEX_DrvReserved1 = 77;

        public const int INDEX_DrvReserved2 = 78;

        public const int INDEX_DrvReserved3 = 79;

        public const int INDEX_DrvReserved4 = 80;

        public const int INDEX_DrvReserved5 = 81;

        public const int INDEX_DrvReserved6 = 82;

        public const int INDEX_DrvReserved7 = 83;

        public const int INDEX_DrvReserved8 = 84;

        public const int INDEX_DrvDeriveSurface = 85;

        public const int INDEX_DrvQueryGlyphAttrs = 86;

        public const int INDEX_DrvNotify = 87;

        public const int INDEX_DrvSynchronizeSurface = 88;

        public const int INDEX_DrvResetDevice = 89;

        public const int INDEX_DrvReserved9 = 90;

        public const int INDEX_DrvReserved10 = 91;

        public const int INDEX_DrvReserved11 = 92;

        public const int INDEX_DrvRenderHint = 93;

        public const int INDEX_DrvCreateDeviceBitmapEx = 94;

        public const int INDEX_DrvDeleteDeviceBitmapEx = 95;

        public const int INDEX_DrvAssociateSharedSurface = 96;

        public const int INDEX_DrvSynchronizeRedirectionBitmaps = 97;

        public const int INDEX_DrvAccumulateD3DDirtyRect = 98;

        public const int INDEX_DrvStartDxInterop = 99;

        public const int INDEX_DrvEndDxInterop = 100;

        public const int INDEX_DrvLockDisplayArea = 101;

        public const int INDEX_DrvUnlockDisplayArea = 102;

        public const int INDEX_DrvSurfaceComplete = 103;

        public const int INDEX_LAST = 89;

        public const uint GCAPS_BEZIERS = 0x00000001;

        public const uint GCAPS_GEOMETRICWIDE = 0x00000002;

        public const uint GCAPS_ALTERNATEFILL = 0x00000004;

        public const uint GCAPS_WINDINGFILL = 0x00000008;

        public const uint GCAPS_HALFTONE = 0x00000010;

        public const uint GCAPS_COLOR_DITHER = 0x00000020;

        public const uint GCAPS_HORIZSTRIKE = 0x00000040;

        public const uint GCAPS_VERTSTRIKE = 0x00000080;

        public const uint GCAPS_OPAQUERECT = 0x00000100;

        public const uint GCAPS_VECTORFONT = 0x00000200;

        public const uint GCAPS_MONO_DITHER = 0x00000400;

        public const uint GCAPS_ASYNCCHANGE = 0x00000800;

        public const uint GCAPS_ASYNCMOVE = 0x00001000;

        public const uint GCAPS_DONTJOURNAL = 0x00002000;

        public const uint GCAPS_DIRECTDRAW = 0x00004000;

        public const uint GCAPS_ARBRUSHOPAQUE = 0x00008000;

        public const uint GCAPS_PANNING = 0x00010000;

        public const uint GCAPS_HIGHRESTEXT = 0x00040000;

        public const uint GCAPS_PALMANAGED = 0x00080000;

        public const uint GCAPS_DITHERONREALIZE = 0x00200000;

        public const uint GCAPS_NO64BITMEMACCESS = 0x00400000;

        public const uint GCAPS_FORCEDITHER = 0x00800000;

        public const uint GCAPS_GRAY16 = 0x01000000;

        public const uint GCAPS_ICM = 0x02000000;

        public const uint GCAPS_CMYKCOLOR = 0x04000000;

        public const uint GCAPS_LAYERED = 0x08000000;

        public const uint GCAPS_ARBRUSHTEXT = 0x10000000;

        public const uint GCAPS_SCREENPRECISION = 0x20000000;

        public const uint GCAPS_FONT_RASTERIZER = 0x40000000;

        public const uint GCAPS_NUP = 0x80000000;

        public const uint GCAPS2_JPEGSRC = 0x00000001;

        public const uint GCAPS2_xxxx = 0x00000002;

        public const uint GCAPS2_PNGSRC = 0x00000008;

        public const uint GCAPS2_CHANGEGAMMARAMP = 0x00000010;

        public const uint GCAPS2_ALPHACURSOR = 0x00000020;

        public const uint GCAPS2_SYNCFLUSH = 0x00000040;

        public const uint GCAPS2_SYNCTIMER = 0x00000080;

        public const uint GCAPS2_ICD_MULTIMON = 0x00000100;

        public const uint GCAPS2_MOUSETRAILS = 0x00000200;

        public const uint GCAPS2_RESERVED1 = 0x00000400;

        public const uint GCAPS2_REMOTEDRIVER = 0x00000400;

        public const uint GCAPS2_EXCLUDELAYERED = 0x00000800;

        public const uint GCAPS2_INCLUDEAPIBITMAPS = 0x00001000;

        public const uint GCAPS2_SHOWHIDDENPOINTER = 0x00002000;

        public const uint GCAPS2_CLEARTYPE = 0x00004000;

        public const uint GCAPS2_ACC_DRIVER = 0x00008000;

        public const uint GCAPS2_BITMAPEXREUSE = 0x00010000;

        public const uint LA_GEOMETRIC = 0x00000001;

        public const uint LA_ALTERNATE = 0x00000002;

        public const uint LA_STARTGAP = 0x00000004;

        public const uint LA_STYLED = 0x00000008;

        public const int JOIN_ROUND = 0;

        public const int JOIN_BEVEL = 1;

        public const int JOIN_MITER = 2;

        public const int ENDCAP_ROUND = 0;

        public const int ENDCAP_SQUARE = 1;

        public const int ENDCAP_BUTT = 2;

        public const uint PRIMARY_ORDER_ABC = 0;

        public const uint PRIMARY_ORDER_ACB = 1;

        public const uint PRIMARY_ORDER_BAC = 2;

        public const uint PRIMARY_ORDER_BCA = 3;

        public const uint PRIMARY_ORDER_CBA = 4;

        public const uint PRIMARY_ORDER_CAB = 5;

        public const uint HT_PATSIZE_2x2 = 0;

        public const uint HT_PATSIZE_2x2_M = 1;

        public const uint HT_PATSIZE_4x4 = 2;

        public const uint HT_PATSIZE_4x4_M = 3;

        public const uint HT_PATSIZE_6x6 = 4;

        public const uint HT_PATSIZE_6x6_M = 5;

        public const uint HT_PATSIZE_8x8 = 6;

        public const uint HT_PATSIZE_8x8_M = 7;

        public const uint HT_PATSIZE_10x10 = 8;

        public const uint HT_PATSIZE_10x10_M = 9;

        public const uint HT_PATSIZE_12x12 = 10;

        public const uint HT_PATSIZE_12x12_M = 11;

        public const uint HT_PATSIZE_14x14 = 12;

        public const uint HT_PATSIZE_14x14_M = 13;

        public const uint HT_PATSIZE_16x16 = 14;

        public const uint HT_PATSIZE_16x16_M = 15;

        public const uint HT_PATSIZE_SUPERCELL = 16;

        public const uint HT_PATSIZE_SUPERCELL_M = 17;

        public const uint HT_PATSIZE_USER = 18;

        public const uint HT_USERPAT_CX_MIN = 4;

        public const uint HT_USERPAT_CX_MAX = 256;

        public const uint HT_USERPAT_CY_MIN = 4;

        public const uint HT_USERPAT_CY_MAX = 256;

        public const uint HT_FORMAT_1BPP = 0;

        public const uint HT_FORMAT_4BPP = 2;

        public const uint HT_FORMAT_4BPP_IRGB = 3;

        public const uint HT_FORMAT_8BPP = 4;

        public const uint HT_FORMAT_16BPP = 5;

        public const uint HT_FORMAT_24BPP = 6;

        public const uint HT_FORMAT_32BPP = 7;

        public const uint WINDDI_MAX_BROADCAST_CONTEXT = 64;

        public const uint HT_FLAG_SQUARE_DEVICE_PEL = 0x00000001;

        public const uint HT_FLAG_HAS_BLACK_DYE = 0x00000002;

        public const uint HT_FLAG_ADDITIVE_PRIMS = 0x00000004;

        public const uint HT_FLAG_USE_8BPP_BITMASK = 0x00000008;

        public const uint HT_FLAG_INK_HIGH_ABSORPTION = 0x00000010;

        public const uint HT_FLAG_INK_ABSORPTION_INDICES = 0x00000060;

        public const uint HT_FLAG_DO_DEVCLR_XFORM = 0x00000080;

        public const uint HT_FLAG_OUTPUT_CMY = 0x00000100;

        public const uint HT_FLAG_PRINT_DRAFT_MODE = 0x00000200;

        public const uint HT_FLAG_INVERT_8BPP_BITMASK_IDX = 0x00000400;

        public const uint HT_FLAG_8BPP_CMY332_MASK = 0xFF000000;

        public const uint HT_FLAG_INK_ABSORPTION_IDX0 = 0x00000000;

        public const uint HT_FLAG_INK_ABSORPTION_IDX1 = 0x00000020;

        public const uint HT_FLAG_INK_ABSORPTION_IDX2 = 0x00000040;

        public const uint HT_FLAG_INK_ABSORPTION_IDX3 = 0x00000060;

        public const uint PPC_DEFAULT = 0x0;

        public const uint PPC_UNDEFINED = 0x1;

        public const uint PPC_RGB_ORDER_VERTICAL_STRIPES = 0x2;

        public const uint PPC_BGR_ORDER_VERTICAL_STRIPES = 0x3;

        public const uint PPC_RGB_ORDER_HORIZONTAL_STRIPES = 0x4;

        public const uint PPC_BGR_ORDER_HORIZONTAL_STRIPES = 0x5;

        public const uint PPG_DEFAULT = 0;

        public const uint PPG_SRGB = 1;

        public const uint BR_DEVICE_ICM = 0x01;

        public const uint BR_HOST_ICM = 0x02;

        public const uint BR_CMYKCOLOR = 0x04;

        public const uint BR_ORIGCOLOR = 0x08;

        public const uint FO_SIM_BOLD = 0x00002000;

        public const uint FO_SIM_ITALIC = 0x00004000;

        public const uint FO_EM_HEIGHT = 0x00008000;

        public const uint FO_GRAY16 = 0x00010000;

        public const uint FO_NOGRAY16 = 0x00020000;

        public const uint FO_NOHINTS = 0x00040000;

        public const uint FO_NO_CHOICE = 0x00080000;

        public const uint FO_CFF = 0x00100000;

        public const uint FO_POSTSCRIPT = 0x00200000;

        public const uint FO_MULTIPLEMASTER = 0x00400000;

        public const uint FO_VERT_FACE = 0x00800000;

        public const uint FO_DBCS_FONT = 0X01000000;

        public const uint FO_NOCLEARTYPE = 0x02000000;

        public const uint FO_CLEARTYPE_X = 0x10000000;

        public const uint FO_CLEARTYPE_Y = 0x20000000;

        public const uint FO_CLEARTYPENATURAL_X = 0x40000000;

        public const uint DC_TRIVIAL = 0;

        public const uint DC_RECT = 1;

        public const uint DC_COMPLEX = 3;

        public const uint FC_RECT = 1;

        public const uint FC_RECT4 = 2;

        public const uint FC_COMPLEX = 3;

        public const uint TC_RECTANGLES = 0;

        public const uint TC_PATHOBJ = 2;

        public const uint OC_BANK_CLIP = 1;

        public const int CT_RECTANGLES = 0;

        public const int CD_RIGHTDOWN = 0;

        public const int CD_LEFTDOWN = 1;

        public const int CD_RIGHTUP = 2;

        public const int CD_LEFTUP = 3;

        public const int CD_ANY = 4;

        public const int CD_LEFTWARDS = 1;

        public const int CD_UPWARDS = 2;

        public const int FO_HGLYPHS = 0;

        public const int FO_GLYPHBITS = 1;

        public const int FO_PATHOBJ = 2;

        public const int FD_NEGATIVE_FONT = 1;

        public const int FO_DEVICE_FONT = 1;

        public const int FO_OUTLINE_CAPABLE = 2;

        public const uint SO_FLAG_DEFAULT_PLACEMENT = 0x00000001;

        public const uint SO_HORIZONTAL = 0x00000002;

        public const uint SO_VERTICAL = 0x00000004;

        public const uint SO_REVERSED = 0x00000008;

        public const uint SO_ZERO_BEARINGS = 0x00000010;

        public const uint SO_CHAR_INC_EQUAL_BM_BASE = 0x00000020;

        public const uint SO_MAXEXT_EQUAL_BM_SIDE = 0x00000040;

        public const uint SO_DO_NOT_SUBSTITUTE_DEVICE_FONT = 0x00000080;

        public const uint SO_GLYPHINDEX_TEXTOUT = 0x00000100;

        public const uint SO_ESC_NOT_ORIENT = 0x00000200;

        public const uint SO_DXDY = 0x00000400;

        public const uint SO_CHARACTER_EXTRA = 0x00000800;

        public const uint SO_BREAK_EXTRA = 0x00001000;

        public const uint FO_ATTR_MODE_ROTATE = 1;

        public const uint PAL_INDEXED = 0x00000001;

        public const uint PAL_BITFIELDS = 0x00000002;

        public const uint PAL_RGB = 0x00000004;

        public const uint PAL_BGR = 0x00000008;

        public const uint PAL_CMYK = 0x00000010;

        public const uint PO_BEZIERS = 0x00000001;

        public const uint PO_ELLIPSE = 0x00000002;

        public const uint PO_ALL_INTEGERS = 0x00000004;

        public const uint PO_ENUM_AS_INTEGERS = 0x00000008;

        public const uint PO_WIDENED = 0x00000010;

        public const uint PD_BEGINSUBPATH = 0x00000001;

        public const uint PD_ENDSUBPATH = 0x00000002;

        public const uint PD_RESETSTYLE = 0x00000004;

        public const uint PD_CLOSEFIGURE = 0x00000008;

        public const uint PD_BEZIERS = 0x00000010;

        public const uint SGI_EXTRASPACE = 0;

        public const int STYPE_BITMAP = 0;

        public const int STYPE_DEVBITMAP = 3;

        public const int BMF_1BPP = 1;

        public const int BMF_4BPP = 2;

        public const int BMF_8BPP = 3;

        public const int BMF_16BPP = 4;

        public const int BMF_24BPP = 5;

        public const int BMF_32BPP = 6;

        public const int BMF_4RLE = 7;

        public const int BMF_8RLE = 8;

        public const int BMF_JPEG = 9;

        public const int BMF_PNG = 10;

        public const uint BMF_TOPDOWN = 0x0001;

        public const uint BMF_NOZEROINIT = 0x0002;

        public const uint BMF_DONTCACHE = 0x0004;

        public const uint BMF_USERMEM = 0x0008;

        public const uint BMF_KMSECTION = 0x0010;

        public const uint BMF_NOTSYSMEM = 0x0020;

        public const uint BMF_WINDOW_BLT = 0x0040;

        public const uint BMF_UMPDMEM = 0x0080;

        public const uint BMF_TEMP_ALPHA = 0x0100;

        public const uint BMF_ACC_NOTIFY = 0x8000;

        public const uint BMF_RMT_ENTER = 0x4000;

        public const uint BMF_RESERVED = 0x3E00;

        public const int GX_IDENTITY = 0;

        public const int GX_OFFSET = 1;

        public const int GX_SCALE = 2;

        public const int GX_GENERAL = 3;

        public const int XF_LTOL = 0;

        public const int XF_INV_LTOL = 1;

        public const int XF_LTOFX = 2;

        public const int XF_INV_FXTOL = 3;

        public const uint XO_TRIVIAL = 0x00000001;

        public const uint XO_TABLE = 0x00000002;

        public const uint XO_TO_MONO = 0x00000004;

        public const uint XO_FROM_CMYK = 0x00000008;

        public const uint XO_DEVICE_ICM = 0x00000010;

        public const uint XO_HOST_ICM = 0x00000020;

        public const uint XO_SRCPALETTE = 1;

        public const uint XO_DESTPALETTE = 2;

        public const uint XO_DESTDCPALETTE = 3;

        public const uint XO_SRCBITFIELDS = 4;

        public const uint XO_DESTBITFIELDS = 5;

        public const uint HOOK_BITBLT = 0x00000001;

        public const uint HOOK_STRETCHBLT = 0x00000002;

        public const uint HOOK_PLGBLT = 0x00000004;

        public const uint HOOK_TEXTOUT = 0x00000008;

        public const uint HOOK_PAINT = 0x00000010;

        public const uint HOOK_STROKEPATH = 0x00000020;

        public const uint HOOK_FILLPATH = 0x00000040;

        public const uint HOOK_STROKEANDFILLPATH = 0x00000080;

        public const uint HOOK_LINETO = 0x00000100;

        public const uint HOOK_COPYBITS = 0x00000400;

        public const uint HOOK_MOVEPANNING = 0x00000800;

        public const uint HOOK_SYNCHRONIZE = 0x00001000;

        public const uint HOOK_STRETCHBLTROP = 0x00002000;

        public const uint HOOK_SYNCHRONIZEACCESS = 0x00004000;

        public const uint HOOK_TRANSPARENTBLT = 0x00008000;

        public const uint HOOK_ALPHABLEND = 0x00010000;

        public const uint HOOK_GRADIENTFILL = 0x00020000;

        public const uint HOOK_FLAGS = 0x0003b5ff;

        public const uint MS_NOTSYSTEMMEMORY = 0x0001;

        public const uint MS_SHAREDACCESS = 0x0002;

        public const uint MS_CDDDEVICEBITMAP = 0x0004;

        public const uint MS_REUSEDDEVICEBITMAP = 0x0008;

        public const uint DRVQUERY_USERMODE = 1;

        public const uint HS_DDI_MAX = 6;

        public const uint DRD_SUCCESS = 0;

        public const uint DRD_ERROR = 1;

        public const uint SS_SAVE = 0;

        public const uint SS_RESTORE = 1;

        public const uint SS_FREE = 2;

        public const uint CDBEX_REDIRECTION = 0x00000001;

        public const uint CDBEX_DXINTEROP = 0x00000002;

        public const uint CDBEX_NTSHAREDSURFACEHANDLE = 0x00000004;

        public const uint CDBEX_CROSSADAPTER = 0x00000008;

        public const uint CDBEX_REUSE = 0x00000010;

        public const uint WINDDI_MAXSETPALETTECOLORS = 256;

        public const uint WINDDI_MAXSETPALETTECOLORINDEX = 255;

        public const uint DM_DEFAULT = 0x00000001;

        public const uint DM_MONOCHROME = 0x00000002;

        public const uint DCR_SOLID = 0;

        public const uint DCR_DRIVER = 1;

        public const uint DCR_HALFTONE = 2;

        public const int RB_DITHERCOLOR = unchecked((int)0x80000000);

        public const int QFT_LIGATURES = 1;

        public const int QFT_KERNPAIRS = 2;

        public const int QFT_GLYPHSET = 3;

        public const int QFD_GLYPHANDBITMAP = 1;

        public const int QFD_GLYPHANDOUTLINE = 2;

        public const int QFD_MAXEXTENTS = 3;

        public const int QFD_TT_GLYPHANDBITMAP = 4;

        public const int QFD_TT_GRAY1_BITMAP = 5;

        public const int QFD_TT_GRAY2_BITMAP = 6;

        public const int QFD_TT_GRAY4_BITMAP = 8;

        public const int QFD_TT_GRAY8_BITMAP = 9;

        public const uint QC_OUTLINES = 0x00000001;

        public const uint QC_1BIT = 0x00000002;

        public const uint QC_4BIT = 0x00000004;

        public const uint FF_SIGNATURE_VERIFIED = 0x1;

        public const uint FF_IGNORED_SIGNATURE = 0x2;

        public const uint QAW_GETWIDTHS = 0;

        public const uint QAW_GETEASYWIDTHS = 1;

        public const uint TTO_METRICS_ONLY = 1;

        public const uint TTO_QUBICS = 2;

        public const uint TTO_UNHINTED = 4;

        public const int QFF_DESCRIPTION = 1;

        public const int QFF_NUMFACES = 2;

        public const int FP_ALTERNATEMODE = 1;

        public const int FP_WINDINGMODE = 2;

        public const uint SPS_ERROR = 0;

        public const uint SPS_DECLINE = 1;

        public const uint SPS_ACCEPT_NOEXCLUDE = 2;

        public const uint SPS_ACCEPT_EXCLUDE = 3;

        public const uint SPS_ACCEPT_SYNCHRONOUS = 4;

        public const int SPS_CHANGE = 0x00000001;

        public const int SPS_ASYNCCHANGE = 0x00000002;

        public const int SPS_ANIMATESTART = 0x00000004;

        public const int SPS_ANIMATEUPDATE = 0x00000008;

        public const int SPS_ALPHA = 0x00000010;

        public const int SPS_RESERVED = 0x00000020;

        public const int SPS_RESERVED1 = 0x00000040;

        public const int SPS_FLAGSMASK = 0x000000FF;

        public const int SPS_LENGTHMASK = 0x00000F00;

        public const int SPS_FREQMASK = 0x000FF000;

        public const uint ED_ABORTDOC = 1;

        public const uint IGRF_RGB_256BYTES = 0;

        public const uint IGRF_RGB_256WORDS = 1;

        public const uint QDS_CHECKJPEGFORMAT = 0;

        public const uint QDS_CHECKPNGFORMAT = 1;

        public const uint DSS_TIMER_EVENT = 0x0001;

        public const uint DSS_FLUSH_EVENT = 0x0002;

        public const uint DSS_RESERVED = 0x0004;

        public const uint DSS_RESERVED1 = 0x0008;

        public const uint DSS_RESERVED2 = 0x0010;

        public const uint DN_ACCELERATION_LEVEL = 1;

        public const uint DN_DEVICE_ORIGIN = 2;

        public const uint DN_SLEEP_MODE = 3;

        public const uint DN_DRAWING_BEGIN = 4;

        public const uint DN_ASSOCIATE_WINDOW = 5;

        public const uint DN_COMPOSITION_CHANGED = 6;

        public const uint DN_DRAWING_BEGIN_APIBITMAP = 7;

        public const uint DN_SURFOBJ_DESTRUCTION = 8;

        public const uint WOC_RGN_CLIENT_DELTA = 0x0001;

        public const uint WOC_RGN_CLIENT = 0x0002;

        public const uint WOC_RGN_SURFACE_DELTA = 0x0004;

        public const uint WOC_RGN_SURFACE = 0x0008;

        public const uint WOC_CHANGED = 0x0010;

        public const uint WOC_DELETE = 0x0020;

        public const uint WOC_DRAWN = 0x0040;

        public const uint WOC_SPRITE_OVERLAP = 0x0080;

        public const uint WOC_SPRITE_NO_OVERLAP = 0x0100;

        public const uint WOC_RGN_SPRITE = 0x0200;

        public const uint WO_RGN_CLIENT_DELTA = 0x0001;

        public const uint WO_RGN_CLIENT = 0x0002;

        public const uint WO_RGN_SURFACE_DELTA = 0x0004;

        public const uint WO_RGN_SURFACE = 0x0008;

        public const uint WO_RGN_UPDATE_ALL = 0x0010;

        public const uint WO_RGN_WINDOW = 0x0020;

        public const uint WO_DRAW_NOTIFY = 0x0040;

        public const uint WO_SPRITE_NOTIFY = 0x0080;

        public const uint WO_RGN_DESKTOP_COORD = 0x0100;

        public const uint WO_RGN_SPRITE = 0x0200;

        public const uint EHN_RESTORED = 0;

        public const uint EHN_ERROR = 1;

        public const uint ECS_TEARDOWN = 0x0001;

        public const uint ECS_REDRAW = 0x0002;

        public const uint DEVHTADJF_COLOR_DEVICE = 0x00000001;

        public const uint DEVHTADJF_ADDITIVE_DEVICE = 0x00000002;

        public const uint FL_ZERO_MEMORY = 0x00000001;

        public const uint FL_NONPAGED_MEMORY = 0x00000002;

        public const uint FL_NON_SESSION = 0x00000004;

        public const uint QSA_MMX = 0x00000100;

        public const uint QSA_SSE = 0x00002000;

        public const uint QSA_3DNOW = 0x00004000;

        public const uint QSA_SSE2 = 0x00010000;

        public const uint QSA_SSE3 = 0x00080000;

        public const uint ENG_FNT_CACHE_READ_FAULT = 0x1;

        public const uint ENG_FNT_CACHE_WRITE_FAULT = 0x2;

        public const uint DRH_APIBITMAP = 0x00000001;

        public static readonly Guid GUID_DEVINTERFACE_SCM_PHYSICAL_DEVICE__scanned__ = new Guid(0x4283609d, 0x4dc2, 0x43be, 0xbb, 0xb4, 0x4f, 0x15, 0xdf, 0xce, 0x2c, 0x61);

        public static readonly Guid GUID_SCM_PD_HEALTH_NOTIFICATION__scanned__ = new Guid(0x9da2d386, 0x72f5, 0x4ee3, 0x81, 0x55, 0xec, 0xa0, 0x67, 0x8e, 0x3b, 0x6);

        public static readonly Guid GUID_SCM_PD_PASSTHROUGH_INVDIMM__scanned__ = new Guid(0x4309AC30, 0x0D11, 0x11E4, 0x91, 0x91, 0x08, 0x00, 0x20, 0x0C, 0x9A, 0x66);

        public static readonly Guid GUID_DEVINTERFACE_COMPORT__scanned__ = new Guid(0X86E0D1E0L, 0X8089, 0X11D0, 0X9C, 0XE4, 0X08, 0X00, 0X3E, 0X30, 0X1F, 0X73);

        public static readonly Guid GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR__scanned__ = new Guid(0x4D36E978L, 0xE325, 0x11CE, 0xBF, 0xC1, 0x08, 0x00, 0x2B, 0xE1, 0x03, 0x18);

        public const uint FILE_DEVICE_BEEP = 0x00000001;

        public const uint FILE_DEVICE_CD_ROM_FILE_SYSTEM = 0x00000003;

        public const uint FILE_DEVICE_CONTROLLER = 0x00000004;

        public const uint FILE_DEVICE_DATALINK = 0x00000005;

        public const uint FILE_DEVICE_DFS = 0x00000006;

        public const uint FILE_DEVICE_DISK_FILE_SYSTEM = 0x00000008;

        public const uint FILE_DEVICE_FILE_SYSTEM = 0x00000009;

        public const uint FILE_DEVICE_INPORT_PORT = 0x0000000a;

        public const uint FILE_DEVICE_KEYBOARD = 0x0000000b;

        public const uint FILE_DEVICE_MAILSLOT = 0x0000000c;

        public const uint FILE_DEVICE_MIDI_IN = 0x0000000d;

        public const uint FILE_DEVICE_MIDI_OUT = 0x0000000e;

        public const uint FILE_DEVICE_MOUSE = 0x0000000f;

        public const uint FILE_DEVICE_MULTI_UNC_PROVIDER = 0x00000010;

        public const uint FILE_DEVICE_NAMED_PIPE = 0x00000011;

        public const uint FILE_DEVICE_NETWORK = 0x00000012;

        public const uint FILE_DEVICE_NETWORK_BROWSER = 0x00000013;

        public const uint FILE_DEVICE_NETWORK_FILE_SYSTEM = 0x00000014;

        public const uint FILE_DEVICE_NULL = 0x00000015;

        public const uint FILE_DEVICE_PARALLEL_PORT = 0x00000016;

        public const uint FILE_DEVICE_PHYSICAL_NETCARD = 0x00000017;

        public const uint FILE_DEVICE_PRINTER = 0x00000018;

        public const uint FILE_DEVICE_SCANNER = 0x00000019;

        public const uint FILE_DEVICE_SERIAL_MOUSE_PORT = 0x0000001a;

        public const uint FILE_DEVICE_SERIAL_PORT = 0x0000001b;

        public const uint FILE_DEVICE_SCREEN = 0x0000001c;

        public const uint FILE_DEVICE_SOUND = 0x0000001d;

        public const uint FILE_DEVICE_STREAMS = 0x0000001e;

        public const uint FILE_DEVICE_TAPE_FILE_SYSTEM = 0x00000020;

        public const uint FILE_DEVICE_TRANSPORT = 0x00000021;

        public const uint FILE_DEVICE_UNKNOWN = 0x00000022;

        public const uint FILE_DEVICE_VIDEO = 0x00000023;

        public const uint FILE_DEVICE_VIRTUAL_DISK = 0x00000024;

        public const uint FILE_DEVICE_WAVE_IN = 0x00000025;

        public const uint FILE_DEVICE_WAVE_OUT = 0x00000026;

        public const uint FILE_DEVICE_8042_PORT = 0x00000027;

        public const uint FILE_DEVICE_NETWORK_REDIRECTOR = 0x00000028;

        public const uint FILE_DEVICE_BATTERY = 0x00000029;

        public const uint FILE_DEVICE_BUS_EXTENDER = 0x0000002a;

        public const uint FILE_DEVICE_MODEM = 0x0000002b;

        public const uint FILE_DEVICE_VDM = 0x0000002c;

        public const uint FILE_DEVICE_MASS_STORAGE = 0x0000002d;

        public const uint FILE_DEVICE_SMB = 0x0000002e;

        public const uint FILE_DEVICE_KS = 0x0000002f;

        public const uint FILE_DEVICE_CHANGER = 0x00000030;

        public const uint FILE_DEVICE_SMARTCARD = 0x00000031;

        public const uint FILE_DEVICE_ACPI = 0x00000032;

        public const uint FILE_DEVICE_FULLSCREEN_VIDEO = 0x00000034;

        public const uint FILE_DEVICE_DFS_FILE_SYSTEM = 0x00000035;

        public const uint FILE_DEVICE_DFS_VOLUME = 0x00000036;

        public const uint FILE_DEVICE_SERENUM = 0x00000037;

        public const uint FILE_DEVICE_TERMSRV = 0x00000038;

        public const uint FILE_DEVICE_KSEC = 0x00000039;

        public const uint FILE_DEVICE_FIPS = 0x0000003A;

        public const uint FILE_DEVICE_INFINIBAND = 0x0000003B;

        public const uint FILE_DEVICE_VMBUS = 0x0000003E;

        public const uint FILE_DEVICE_CRYPT_PROVIDER = 0x0000003F;

        public const uint FILE_DEVICE_WPD = 0x00000040;

        public const uint FILE_DEVICE_BLUETOOTH = 0x00000041;

        public const uint FILE_DEVICE_MT_COMPOSITE = 0x00000042;

        public const uint FILE_DEVICE_MT_TRANSPORT = 0x00000043;

        public const uint FILE_DEVICE_BIOMETRIC = 0x00000044;

        public const uint FILE_DEVICE_PMI = 0x00000045;

        public const uint FILE_DEVICE_EHSTOR = 0x00000046;

        public const uint FILE_DEVICE_DEVAPI = 0x00000047;

        public const uint FILE_DEVICE_GPIO = 0x00000048;

        public const uint FILE_DEVICE_USBEX = 0x00000049;

        public const uint FILE_DEVICE_CONSOLE = 0x00000050;

        public const uint FILE_DEVICE_NFP = 0x00000051;

        public const uint FILE_DEVICE_SYSENV = 0x00000052;

        public const uint FILE_DEVICE_VIRTUAL_BLOCK = 0x00000053;

        public const uint FILE_DEVICE_POINT_OF_SERVICE = 0x00000054;

        public const uint FILE_DEVICE_STORAGE_REPLICATION = 0x00000055;

        public const uint FILE_DEVICE_TRUST_ENV = 0x00000056;

        public const uint FILE_DEVICE_UCM = 0x00000057;

        public const uint FILE_DEVICE_UCMTCPCI = 0x00000058;

        public const uint FILE_DEVICE_PERSISTENT_MEMORY = 0x00000059;

        public const uint FILE_DEVICE_NVDIMM = 0x0000005a;

        public const uint FILE_DEVICE_HOLOGRAPHIC = 0x0000005b;

        public const uint FILE_DEVICE_SDFXHCI = 0x0000005c;

        public const uint FILE_DEVICE_UCMUCSI = 0x0000005d;

        public const uint METHOD_BUFFERED = 0;

        public const uint METHOD_IN_DIRECT = 1;

        public const uint METHOD_OUT_DIRECT = 2;

        public const uint METHOD_NEITHER = 3;

        public const uint FILE_ANY_ACCESS = 0;

        public const uint FILE_READ_ACCESS = 0x0001;

        public const uint FILE_WRITE_ACCESS = 0x0002;

        public const uint IOCTL_SCMBUS_DEVICE_FUNCTION_BASE = 0x0;

        public const uint IOCTL_SCM_LOGICAL_DEVICE_FUNCTION_BASE = 0x300;

        public const uint IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE = 0x600;

        public const uint IOCTL_SCM_BUS_GET_LOGICAL_DEVICES = ((IOCTL_SCMBUS_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | (((IOCTL_SCMBUS_DEVICE_FUNCTION_BASE + 0x00)) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCM_BUS_GET_PHYSICAL_DEVICES = ((IOCTL_SCMBUS_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | (((IOCTL_SCMBUS_DEVICE_FUNCTION_BASE + 0x01)) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCM_BUS_GET_REGIONS = ((IOCTL_SCMBUS_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | (((IOCTL_SCMBUS_DEVICE_FUNCTION_BASE + 0x02)) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCM_LD_GET_INTERLEAVE_SET = ((IOCTL_SCMBUS_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | (((IOCTL_SCM_LOGICAL_DEVICE_FUNCTION_BASE + 0x00)) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCM_PD_QUERY_PROPERTY = ((IOCTL_SCMBUS_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | (((IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE + 0x00)) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCM_PD_FIRMWARE_DOWNLOAD = ((IOCTL_SCMBUS_BASE) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | (((IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE + 0x01)) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCM_PD_FIRMWARE_ACTIVATE = ((IOCTL_SCMBUS_BASE) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | (((IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE + 0x02)) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCM_PD_PASSTHROUGH = ((IOCTL_SCMBUS_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | (((IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE + 0x03)) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCM_PD_UPDATE_MANAGEMENT_STATUS = ((IOCTL_SCMBUS_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | (((IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE + 0x04)) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCM_PD_REINITIALIZE_MEDIA = ((IOCTL_SCMBUS_BASE) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | (((IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE + 0x05)) << 2) | (METHOD_BUFFERED);

        public const uint SCM_MAX_SYMLINK_LEN_IN_CHARS = 256;

        public const uint MAX_INTERFACE_CODES = 8;

        public const uint SCM_PD_FIRMWARE_REVISION_LENGTH_BYTES = 32;

        public const uint SCM_PD_PROPERTY_NAME_LENGTH_IN_CHARS = 128;

        public const uint SCM_PD_MAX_OPERATIONAL_STATUS = 16;

        public const uint SCM_PD_FIRMWARE_LAST_DOWNLOAD = 0x1;

        public const uint IOCTL_DISK_GET_DRIVE_GEOMETRY = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0000) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_GET_PARTITION_INFO = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0001) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_SET_PARTITION_INFO = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0002) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_GET_DRIVE_LAYOUT = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0003) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_SET_DRIVE_LAYOUT = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0004) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_VERIFY = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0005) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_FORMAT_TRACKS = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0006) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_REASSIGN_BLOCKS = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0007) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_PERFORMANCE = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0008) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_IS_WRITABLE = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0009) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_LOGGING = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x000a) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_FORMAT_TRACKS_EX = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x000b) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_HISTOGRAM_STRUCTURE = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x000c) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_HISTOGRAM_DATA = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x000d) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_HISTOGRAM_RESET = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x000e) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_REQUEST_STRUCTURE = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x000f) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_REQUEST_DATA = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0010) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_PERFORMANCE_OFF = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0018) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_CONTROLLER_NUMBER = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0011) << 2) | (METHOD_BUFFERED);

        public const uint SMART_GET_VERSION = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0020) << 2) | (METHOD_BUFFERED);

        public const uint SMART_SEND_DRIVE_COMMAND = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0021) << 2) | (METHOD_BUFFERED);

        public const uint SMART_RCV_DRIVE_DATA = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0022) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_GET_PARTITION_INFO_EX = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0012) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_SET_PARTITION_INFO_EX = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0013) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_GET_DRIVE_LAYOUT_EX = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0014) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_SET_DRIVE_LAYOUT_EX = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0015) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_CREATE_DISK = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0016) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_GET_LENGTH_INFO = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0017) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_GET_DRIVE_GEOMETRY_EX = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0028) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_REASSIGN_BLOCKS_EX = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0029) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_UPDATE_DRIVE_SIZE = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0032) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_GROW_PARTITION = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0034) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_GET_CACHE_INFORMATION = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0035) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_SET_CACHE_INFORMATION = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0036) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_GET_WRITE_CACHE_STATE = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0037) << 2) | (METHOD_BUFFERED);

        public const uint OBSOLETE_DISK_GET_WRITE_CACHE_STATE = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0037) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_DELETE_DRIVE_LAYOUT = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0040) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_UPDATE_PROPERTIES = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0050) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_FORMAT_DRIVE = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x00f3) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_SENSE_DEVICE = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x00f8) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_CHECK_VERIFY = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0200) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_MEDIA_REMOVAL = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0201) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_EJECT_MEDIA = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0202) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_LOAD_MEDIA = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0203) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_RESERVE = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0204) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_RELEASE = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0205) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_FIND_NEW_DEVICES = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0206) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_GET_MEDIA_TYPES = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0300) << 2) | (METHOD_BUFFERED);

        public const uint PARTITION_ENTRY_UNUSED = 0x00;

        public const uint PARTITION_FAT_12 = 0x01;

        public const uint PARTITION_XENIX_1 = 0x02;

        public const uint PARTITION_XENIX_2 = 0x03;

        public const uint PARTITION_FAT_16 = 0x04;

        public const uint PARTITION_EXTENDED = 0x05;

        public const uint PARTITION_HUGE = 0x06;

        public const uint PARTITION_IFS = 0x07;

        public const uint PARTITION_OS2BOOTMGR = 0x0A;

        public const uint PARTITION_FAT32 = 0x0B;

        public const uint PARTITION_FAT32_XINT13 = 0x0C;

        public const uint PARTITION_XINT13 = 0x0E;

        public const uint PARTITION_XINT13_EXTENDED = 0x0F;

        public const uint PARTITION_MSFT_RECOVERY = 0x27;

        public const uint PARTITION_MAIN_OS = 0x28;

        public const uint PARTIITON_OS_DATA = 0x29;

        public const uint PARTITION_PRE_INSTALLED = 0x2a;

        public const uint PARTITION_BSP = 0x2b;

        public const uint PARTITION_DPP = 0x2c;

        public const uint PARTITION_WINDOWS_SYSTEM = 0x2d;

        public const uint PARTITION_PREP = 0x41;

        public const uint PARTITION_LDM = 0x42;

        public const uint PARTITION_DM = 0x54;

        public const uint PARTITION_EZDRIVE = 0x55;

        public const uint PARTITION_UNIX = 0x63;

        public const uint PARTITION_SPACES_DATA = 0xD7;

        public const uint PARTITION_SPACES = 0xE7;

        public const uint PARTITION_GPT = 0xEE;

        public const uint PARTITION_SYSTEM = 0xEF;

        public const uint VALID_NTFT = 0xC0;

        public const uint PARTITION_NTFT = 0x80;

        public const ulong GPT_ATTRIBUTE_NO_BLOCK_IO_PROTOCOL = 0x0000000000000002;

        public const ulong GPT_ATTRIBUTE_LEGACY_BIOS_BOOTABLE = 0x0000000000000004;

        public const ulong GPT_BASIC_DATA_ATTRIBUTE_OFFLINE = 0x0800000000000000;

        public const ulong GPT_BASIC_DATA_ATTRIBUTE_DAX = 0x0400000000000000;

        public const ulong GPT_BASIC_DATA_ATTRIBUTE_SERVICE = 0x0200000000000000;

        public const ulong GPT_SPACES_ATTRIBUTE_NO_METADATA = 0x8000000000000000;

        public const uint HIST_NO_OF_BUCKETS = 24;

        public const uint DISK_LOGGING_START = 0;

        public const uint DISK_LOGGING_STOP = 1;

        public const uint DISK_LOGGING_DUMP = 2;

        public const uint DISK_BINNING = 3;

        public const uint CAP_ATA_ID_CMD = 1;

        public const uint CAP_ATAPI_ID_CMD = 2;

        public const uint CAP_SMART_CMD = 4;

        public const uint ATAPI_ID_CMD = 0xA1;

        public const uint ID_CMD = 0xEC;

        public const uint SMART_CMD = 0xB0;

        public const uint SMART_CYL_LOW = 0x4F;

        public const uint SMART_CYL_HI = 0xC2;

        public const uint SMART_NO_ERROR = 0;

        public const uint SMART_IDE_ERROR = 1;

        public const uint SMART_INVALID_FLAG = 2;

        public const uint SMART_INVALID_COMMAND = 3;

        public const uint SMART_INVALID_BUFFER = 4;

        public const uint SMART_INVALID_DRIVE = 5;

        public const uint SMART_INVALID_IOCTL = 6;

        public const uint SMART_ERROR_NO_MEM = 7;

        public const uint SMART_INVALID_REGISTER = 8;

        public const uint SMART_NOT_SUPPORTED = 9;

        public const uint SMART_NO_IDE_DEVICE = 10;

        public const uint SMART_OFFLINE_ROUTINE_OFFLINE = 0;

        public const uint SMART_SHORT_SELFTEST_OFFLINE = 1;

        public const uint SMART_EXTENDED_SELFTEST_OFFLINE = 2;

        public const uint SMART_ABORT_OFFLINE_SELFTEST = 127;

        public const uint SMART_SHORT_SELFTEST_CAPTIVE = 129;

        public const uint SMART_EXTENDED_SELFTEST_CAPTIVE = 130;

        public const uint READ_ATTRIBUTE_BUFFER_SIZE = 512;

        public const uint IDENTIFY_BUFFER_SIZE = 512;

        public const uint READ_THRESHOLD_BUFFER_SIZE = 512;

        public const uint SMART_LOG_SECTOR_SIZE = 512;

        public const uint READ_ATTRIBUTES = 0xD0;

        public const uint READ_THRESHOLDS = 0xD1;

        public const uint ENABLE_DISABLE_AUTOSAVE = 0xD2;

        public const uint SAVE_ATTRIBUTE_VALUES = 0xD3;

        public const uint EXECUTE_OFFLINE_DIAGS = 0xD4;

        public const uint SMART_READ_LOG = 0xD5;

        public const uint SMART_WRITE_LOG = 0xd6;

        public const uint ENABLE_SMART = 0xD8;

        public const uint DISABLE_SMART = 0xD9;

        public const uint RETURN_SMART_STATUS = 0xDA;

        public const uint ENABLE_DISABLE_AUTO_OFFLINE = 0xDB;

        public const uint IOCTL_DISK_GET_DISK_ATTRIBUTES = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x003c) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_DISK_SET_DISK_ATTRIBUTES = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x003d) << 2) | (METHOD_BUFFERED);

        public const ulong DISK_ATTRIBUTE_OFFLINE = 0x0000000000000001;

        public const ulong DISK_ATTRIBUTE_READ_ONLY = 0x0000000000000002;

        public const uint IOCTL_DISK_RESET_SNAPSHOT_INFO = ((IOCTL_DISK_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0084) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_CHANGER_GET_PARAMETERS = ((IOCTL_CHANGER_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0000) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_CHANGER_GET_STATUS = ((IOCTL_CHANGER_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0001) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_CHANGER_GET_PRODUCT_DATA = ((IOCTL_CHANGER_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0002) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_CHANGER_SET_ACCESS = ((IOCTL_CHANGER_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0004) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_CHANGER_GET_ELEMENT_STATUS = ((IOCTL_CHANGER_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0005) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS = ((IOCTL_CHANGER_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0006) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_CHANGER_SET_POSITION = ((IOCTL_CHANGER_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0007) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_CHANGER_EXCHANGE_MEDIUM = ((IOCTL_CHANGER_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0008) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_CHANGER_MOVE_MEDIUM = ((IOCTL_CHANGER_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x0009) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_CHANGER_REINITIALIZE_TRANSPORT = ((IOCTL_CHANGER_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x000A) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_CHANGER_QUERY_VOLUME_TAGS = ((IOCTL_CHANGER_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x000B) << 2) | (METHOD_BUFFERED);

        public const uint MAX_VOLUME_ID_SIZE = 36;

        public const uint MAX_VOLUME_TEMPLATE_SIZE = 40;

        public const uint VENDOR_ID_LENGTH = 8;

        public const uint PRODUCT_ID_LENGTH = 16;

        public const uint REVISION_LENGTH = 4;

        public const uint SERIAL_NUMBER_LENGTH = 32;

        public const uint CHANGER_RESERVED_BIT = 0x80000000;

        public const uint CHANGER_TO_TRANSPORT = 0x01;

        public const uint CHANGER_TO_SLOT = 0x02;

        public const uint CHANGER_TO_IEPORT = 0x04;

        public const uint CHANGER_TO_DRIVE = 0x08;

        public const uint LOCK_UNLOCK_IEPORT = 0x01;

        public const uint LOCK_UNLOCK_DOOR = 0x02;

        public const uint LOCK_UNLOCK_KEYPAD = 0x04;

        public const uint LOCK_ELEMENT = 0;

        public const uint UNLOCK_ELEMENT = 1;

        public const uint EXTEND_IEPORT = 2;

        public const uint RETRACT_IEPORT = 3;

        public const uint ERROR_LABEL_UNREADABLE = 0x00000001;

        public const uint ERROR_LABEL_QUESTIONABLE = 0x00000002;

        public const uint ERROR_SLOT_NOT_PRESENT = 0x00000004;

        public const uint ERROR_DRIVE_NOT_INSTALLED = 0x00000008;

        public const uint ERROR_TRAY_MALFUNCTION = 0x00000010;

        public const uint ERROR_INIT_STATUS_NEEDED = 0x00000011;

        public const uint ERROR_UNHANDLED_ERROR = 0xFFFFFFFF;

        public const uint SEARCH_ALL = 0x0;

        public const uint SEARCH_PRIMARY = 0x1;

        public const uint SEARCH_ALTERNATE = 0x2;

        public const uint SEARCH_ALL_NO_SEQ = 0x4;

        public const uint SEARCH_PRI_NO_SEQ = 0x5;

        public const uint SEARCH_ALT_NO_SEQ = 0x6;

        public const uint ASSERT_PRIMARY = 0x8;

        public const uint ASSERT_ALTERNATE = 0x9;

        public const uint REPLACE_PRIMARY = 0xA;

        public const uint REPLACE_ALTERNATE = 0xB;

        public const uint UNDEFINE_PRIMARY = 0xC;

        public const uint UNDEFINE_ALTERNATE = 0xD;

        public const uint IOCTL_SERIAL_LSRMST_INSERT = ((FILE_DEVICE_SERIAL_PORT) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((31) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SERENUM_EXPOSE_HARDWARE = ((FILE_DEVICE_SERENUM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((128) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SERENUM_REMOVE_HARDWARE = ((FILE_DEVICE_SERENUM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((129) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SERENUM_PORT_DESC = ((FILE_DEVICE_SERENUM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((130) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SERENUM_GET_PORT_NAME = ((FILE_DEVICE_SERENUM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((131) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_REQUEST_OPLOCK_LEVEL_1 = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_REQUEST_OPLOCK_LEVEL_2 = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((1) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_REQUEST_BATCH_OPLOCK = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((2) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_OPLOCK_BREAK_ACKNOWLEDGE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((3) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_OPBATCH_ACK_CLOSE_PENDING = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((4) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_OPLOCK_BREAK_NOTIFY = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((5) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_LOCK_VOLUME = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((6) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_UNLOCK_VOLUME = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((7) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_DISMOUNT_VOLUME = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((8) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_IS_VOLUME_MOUNTED = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((10) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_IS_PATHNAME_VALID = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((11) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_MARK_VOLUME_DIRTY = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((12) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_RETRIEVAL_POINTERS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((14) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_GET_COMPRESSION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((15) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_COMPRESSION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA | FILE_WRITE_DATA)) << 14) | ((16) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_BOOTLOADER_ACCESSED = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((19) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_OPLOCK_BREAK_ACK_NO_2 = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((20) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_INVALIDATE_VOLUMES = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((21) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_FAT_BPB = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((22) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_REQUEST_FILTER_OPLOCK = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((23) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_FILESYSTEM_GET_STATISTICS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((24) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_NTFS_VOLUME_DATA = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((25) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_NTFS_FILE_RECORD = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((26) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_VOLUME_BITMAP = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((27) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_GET_RETRIEVAL_POINTERS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((28) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_MOVE_FILE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((29) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_IS_VOLUME_DIRTY = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((30) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_ALLOW_EXTENDED_DASD_IO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((32) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_FIND_FILES_BY_SID = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((35) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_SET_OBJECT_ID = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((38) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_OBJECT_ID = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((39) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_DELETE_OBJECT_ID = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((40) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_REPARSE_POINT = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((41) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_REPARSE_POINT = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((42) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_DELETE_REPARSE_POINT = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((43) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_ENUM_USN_DATA = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((44) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_SECURITY_ID_CHECK = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((45) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_READ_USN_JOURNAL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((46) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_SET_OBJECT_ID_EXTENDED = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((47) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CREATE_OR_GET_OBJECT_ID = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((48) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_SPARSE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((49) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_ZERO_DATA = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((50) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_ALLOCATED_RANGES = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((51) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_ENABLE_UPGRADE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((52) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_ENCRYPTION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((53) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_ENCRYPTION_FSCTL_IO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((54) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_WRITE_RAW_ENCRYPTED = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((55) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_READ_RAW_ENCRYPTED = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((56) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_CREATE_USN_JOURNAL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((57) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_READ_FILE_USN_DATA = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((58) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_WRITE_USN_CLOSE_RECORD = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((59) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_EXTEND_VOLUME = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((60) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_USN_JOURNAL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((61) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_DELETE_USN_JOURNAL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((62) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_MARK_HANDLE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((63) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SIS_COPYFILE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((64) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SIS_LINK_FILES = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA | FILE_WRITE_DATA)) << 14) | ((65) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_RECALL_FILE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((69) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_READ_FROM_PLEX = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((71) << 2) | (METHOD_OUT_DIRECT);

        public const uint FSCTL_FILE_PREFETCH = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((72) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_MAKE_MEDIA_COMPATIBLE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((76) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_DEFECT_MANAGEMENT = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((77) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_SPARING_INFO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((78) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_ON_DISK_VOLUME_INFO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((79) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_VOLUME_COMPRESSION_STATE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((80) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_MODIFY_RM = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((81) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_QUERY_RM_INFORMATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((82) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_ROLLFORWARD_REDO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((84) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_ROLLFORWARD_UNDO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((85) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_START_RM = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((86) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_SHUTDOWN_RM = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((87) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_READ_BACKUP_INFORMATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((88) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_WRITE_BACKUP_INFORMATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((89) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_CREATE_SECONDARY_RM = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((90) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_GET_METADATA_INFO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((91) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_GET_TRANSACTED_VERSION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((92) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_SAVEPOINT_INFORMATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((94) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_CREATE_MINIVERSION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((95) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_TRANSACTION_ACTIVE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((99) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_ZERO_ON_DEALLOCATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((101) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_REPAIR = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((102) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_REPAIR = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((103) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_WAIT_FOR_REPAIR = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((104) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_INITIATE_REPAIR = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((106) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSC_INTERNAL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((107) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_SHRINK_VOLUME = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((108) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_SHORT_NAME_BEHAVIOR = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((109) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_DFSR_SET_GHOST_HANDLE_STATE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((110) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((120) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_LIST_TRANSACTIONS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((121) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_PAGEFILE_ENCRYPTION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((122) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_RESET_VOLUME_ALLOCATION_HINTS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((123) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_DEPENDENT_VOLUME = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((124) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SD_GLOBAL_CHANGE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((125) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_READ_BACKUP_INFORMATION2 = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((126) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_LOOKUP_STREAM_FROM_CLUSTER = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((127) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_TXFS_WRITE_BACKUP_INFORMATION2 = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((128) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_FILE_TYPE_NOTIFICATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((129) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_FILE_LEVEL_TRIM = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((130) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_BOOT_AREA_INFO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((140) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_RETRIEVAL_POINTER_BASE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((141) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_PERSISTENT_VOLUME_STATE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((142) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_PERSISTENT_VOLUME_STATE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((143) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_REQUEST_OPLOCK = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((144) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSV_TUNNEL_REQUEST = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((145) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_IS_CSV_FILE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((146) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_FILE_SYSTEM_RECOGNITION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((147) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSV_GET_VOLUME_PATH_NAME = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((148) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSV_GET_VOLUME_NAME_FOR_VOLUME_MOUNT_POINT = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((149) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSV_GET_VOLUME_PATH_NAMES_FOR_VOLUME_NAME = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((150) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_IS_FILE_ON_CSV_VOLUME = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((151) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CORRUPTION_HANDLING = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((152) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_OFFLOAD_READ = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((153) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_OFFLOAD_WRITE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((154) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSV_INTERNAL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((155) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_PURGE_FAILURE_MODE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((156) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_FILE_LAYOUT = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((157) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_IS_VOLUME_OWNED_BYCSVFS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((158) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_INTEGRITY_INFORMATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((159) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_INTEGRITY_INFORMATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA | FILE_WRITE_DATA)) << 14) | ((160) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_FILE_REGIONS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((161) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_RKF_INTERNAL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((171) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_SCRUB_DATA = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((172) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_REPAIR_COPIES = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_DATA | FILE_WRITE_DATA)) << 14) | ((173) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_DISABLE_LOCAL_BUFFERING = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((174) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSV_MGMT_LOCK = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((175) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSV_QUERY_DOWN_LEVEL_FILE_SYSTEM_CHARACTERISTICS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((176) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_ADVANCE_FILE_ID = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((177) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSV_SYNC_TUNNEL_REQUEST = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((178) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSV_QUERY_VETO_FILE_DIRECT_IO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((179) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_WRITE_USN_REASON = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((180) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSV_CONTROL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((181) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_REFS_VOLUME_DATA = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((182) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_CSV_H_BREAKING_SYNC_TUNNEL_REQUEST = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((185) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_STORAGE_CLASSES = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((187) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_REGION_INFO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((188) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_USN_TRACK_MODIFIED_RANGES = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((189) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_SHARED_VIRTUAL_DISK_SUPPORT = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((192) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SVHDX_SYNC_TUNNEL_REQUEST = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((193) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SVHDX_SET_INITIATOR_INFORMATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((194) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_EXTERNAL_BACKING = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((195) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_EXTERNAL_BACKING = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((196) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_DELETE_EXTERNAL_BACKING = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((197) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_ENUM_EXTERNAL_BACKING = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((198) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_ENUM_OVERLAY = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((199) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_ADD_OVERLAY = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((204) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_REMOVE_OVERLAY = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((205) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_UPDATE_OVERLAY = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((206) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SHUFFLE_FILE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((208) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_DUPLICATE_EXTENTS_TO_FILE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((209) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SPARSE_OVERALLOCATE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((211) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_STORAGE_QOS_CONTROL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((212) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_INITIATE_FILE_METADATA_OPTIMIZATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((215) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_FILE_METADATA_OPTIMIZATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((216) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SVHDX_ASYNC_TUNNEL_REQUEST = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((217) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_WOF_VERSION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((218) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_HCS_SYNC_TUNNEL_REQUEST = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((219) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_HCS_ASYNC_TUNNEL_REQUEST = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((220) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_EXTENT_READ_CACHE_INFO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((221) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_QUERY_REFS_VOLUME_COUNTER_INFO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((222) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_CLEAN_VOLUME_METADATA = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((223) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_INTEGRITY_INFORMATION_EX = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((224) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SUSPEND_OVERLAY = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((225) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_VIRTUAL_STORAGE_QUERY_PROPERTY = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((226) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_FILESYSTEM_GET_STATISTICS_EX = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((227) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_VOLUME_CONTAINER_STATE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((228) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_LAYER_ROOT = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((229) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_DIRECT_ACCESS_EXTENTS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((230) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_NOTIFY_STORAGE_SPACE_ALLOCATION = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((231) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SSDI_STORAGE_REQUEST = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((232) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_DIRECT_IMAGE_ORIGINAL_BASE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((233) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_READ_UNPRIVILEGED_USN_JOURNAL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((234) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_GHOST_FILE_EXTENTS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((235) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_GHOSTED_FILE_EXTENTS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((236) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_UNMAP_SPACE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((237) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_HCS_SYNC_NO_WRITE_TUNNEL_REQUEST = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((238) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_STREAMS_QUERY_PARAMETERS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((241) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_STREAMS_ASSOCIATE_ID = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((242) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_STREAMS_QUERY_ID = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((243) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_RETRIEVAL_POINTERS_AND_REFCOUNT = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((244) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_QUERY_VOLUME_NUMA_INFO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((245) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_REFS_DEALLOCATE_RANGES = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((246) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_REFS_SMR_VOLUME_INFO = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((247) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_REFS_SMR_VOLUME_GC_PARAMETERS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((248) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_REFS_FILE_STRICTLY_SEQUENTIAL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((249) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_DUPLICATE_EXTENTS_TO_FILE_EX = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((250) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_QUERY_BAD_RANGES = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((251) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_DAX_ALLOC_ALIGNMENT_HINT = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((252) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_DELETE_CORRUPTED_REFS_CONTAINER = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((253) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SCRUB_UNDISCOVERABLE_ID = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((254) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_NOTIFY_DATA_CHANGE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((255) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_START_VIRTUALIZATION_INSTANCE_EX = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((256) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_ENCRYPTION_KEY_CONTROL = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((257) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_VIRTUAL_STORAGE_SET_BEHAVIOR = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((258) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_SET_REPARSE_POINT_EX = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_SPECIAL_ACCESS)) << 14) | ((259) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_REARRANGE_FILE = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((264) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_VIRTUAL_STORAGE_PASSTHROUGH = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((265) << 2) | (METHOD_BUFFERED);

        public const uint FSCTL_GET_RETRIEVAL_POINTER_COUNT = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((266) << 2) | (METHOD_NEITHER);

        public const uint FSCTL_ENABLE_PER_IO_FLAGS = ((FILE_DEVICE_FILE_SYSTEM) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((267) << 2) | (METHOD_BUFFERED);

        public const uint GET_VOLUME_BITMAP_FLAG_MASK_METADATA = 0x00000001;

        public const uint FLAG_USN_TRACK_MODIFIED_RANGES_ENABLE = 0x00000001;

        public const uint USN_PAGE_SIZE = 0x1000;

        public const uint USN_REASON_DATA_OVERWRITE = 0x00000001;

        public const uint USN_REASON_DATA_EXTEND = 0x00000002;

        public const uint USN_REASON_DATA_TRUNCATION = 0x00000004;

        public const uint USN_REASON_NAMED_DATA_OVERWRITE = 0x00000010;

        public const uint USN_REASON_NAMED_DATA_EXTEND = 0x00000020;

        public const uint USN_REASON_NAMED_DATA_TRUNCATION = 0x00000040;

        public const uint USN_REASON_FILE_CREATE = 0x00000100;

        public const uint USN_REASON_FILE_DELETE = 0x00000200;

        public const uint USN_REASON_EA_CHANGE = 0x00000400;

        public const uint USN_REASON_SECURITY_CHANGE = 0x00000800;

        public const uint USN_REASON_RENAME_OLD_NAME = 0x00001000;

        public const uint USN_REASON_RENAME_NEW_NAME = 0x00002000;

        public const uint USN_REASON_INDEXABLE_CHANGE = 0x00004000;

        public const uint USN_REASON_BASIC_INFO_CHANGE = 0x00008000;

        public const uint USN_REASON_HARD_LINK_CHANGE = 0x00010000;

        public const uint USN_REASON_COMPRESSION_CHANGE = 0x00020000;

        public const uint USN_REASON_ENCRYPTION_CHANGE = 0x00040000;

        public const uint USN_REASON_OBJECT_ID_CHANGE = 0x00080000;

        public const uint USN_REASON_REPARSE_POINT_CHANGE = 0x00100000;

        public const uint USN_REASON_STREAM_CHANGE = 0x00200000;

        public const uint USN_REASON_TRANSACTED_CHANGE = 0x00400000;

        public const uint USN_REASON_INTEGRITY_CHANGE = 0x00800000;

        public const uint USN_REASON_DESIRED_STORAGE_CLASS_CHANGE = 0x01000000;

        public const uint USN_REASON_CLOSE = 0x80000000;

        public const uint USN_DELETE_VALID_FLAGS = 0x00000003;

        public const uint MARK_HANDLE_PROTECT_CLUSTERS = 0x00000001;

        public const uint MARK_HANDLE_TXF_SYSTEM_LOG = 0x00000004;

        public const uint MARK_HANDLE_NOT_TXF_SYSTEM_LOG = 0x00000008;

        public const uint MARK_HANDLE_REALTIME = 0x00000020;

        public const uint MARK_HANDLE_NOT_REALTIME = 0x00000040;

        public const uint MARK_HANDLE_FILTER_METADATA = 0x00000200;

        public const uint MARK_HANDLE_CLOUD_SYNC = 0x00000800;

        public const uint MARK_HANDLE_READ_COPY = 0x00000080;

        public const uint MARK_HANDLE_NOT_READ_COPY = 0x00000100;

        public const uint MARK_HANDLE_RETURN_PURGE_FAILURE = 0x00000400;

        public const uint MARK_HANDLE_DISABLE_FILE_METADATA_OPTIMIZATION = 0x00001000;

        public const uint MARK_HANDLE_ENABLE_USN_SOURCE_ON_PAGING_IO = 0x00002000;

        public const uint MARK_HANDLE_SKIP_COHERENCY_SYNC_DISALLOW_WRITES = 0x00004000;

        public const uint MARK_HANDLE_ENABLE_CPU_CACHE = 0x10000000;

        public const uint VOLUME_IS_DIRTY = 0x00000001;

        public const uint VOLUME_UPGRADE_SCHEDULED = 0x00000002;

        public const uint VOLUME_SESSION_OPEN = 0x00000004;

        public const uint FILE_PREFETCH_TYPE_FOR_CREATE = 0x1;

        public const uint FILE_PREFETCH_TYPE_FOR_DIRENUM = 0x2;

        public const uint FILE_PREFETCH_TYPE_FOR_CREATE_EX = 0x3;

        public const uint FILE_PREFETCH_TYPE_FOR_DIRENUM_EX = 0x4;

        public const uint FILE_PREFETCH_TYPE_MAX = 0x4;

        public const uint FILESYSTEM_STATISTICS_TYPE_REFS = 4;

        public const uint FILE_ZERO_DATA_INFORMATION_FLAG_PRESERVE_CACHED_DATA = 0x00000001;

        public const uint FILE_SET_ENCRYPTION = 0x00000001;

        public const uint FILE_CLEAR_ENCRYPTION = 0x00000002;

        public const uint STREAM_SET_ENCRYPTION = 0x00000003;

        public const uint STREAM_CLEAR_ENCRYPTION = 0x00000004;

        public const uint MAXIMUM_ENCRYPTION_VALUE = 0x00000004;

        public const uint ENCRYPTION_FORMAT_DEFAULT = 0x01;

        public const uint ENCRYPTED_DATA_INFO_SPARSE_FILE = 1;

        public const uint COPYFILE_SIS_LINK = 0x0001;

        public const uint COPYFILE_SIS_REPLACE = 0x0002;

        public const uint COPYFILE_SIS_FLAGS = 0x0003;

        public const uint SET_REPAIR_ENABLED = 0x00000001;

        public const uint SET_REPAIR_WARN_ABOUT_DATA_LOSS = 0x00000008;

        public const uint SET_REPAIR_DISABLED_AND_BUGCHECK_ON_CORRUPT = 0x00000010;

        public const uint SET_REPAIR_VALID_MASK = 0x00000019;

        public const ulong FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_IN_USE = 0x0000000000000001;

        public const ulong FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_REUSED = 0x0000000000000002;

        public const ulong FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_EXIST = 0x0000000000000004;

        public const ulong FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_BASE_RECORD = 0x0000000000000008;

        public const ulong FILE_INITIATE_REPAIR_HINT1_SYSTEM_FILE = 0x0000000000000010;

        public const ulong FILE_INITIATE_REPAIR_HINT1_NOT_IMPLEMENTED = 0x0000000000000020;

        public const ulong FILE_INITIATE_REPAIR_HINT1_UNABLE_TO_REPAIR = 0x0000000000000040;

        public const ulong FILE_INITIATE_REPAIR_HINT1_REPAIR_DISABLED = 0x0000000000000080;

        public const ulong FILE_INITIATE_REPAIR_HINT1_RECURSIVELY_CORRUPTED = 0x0000000000000100;

        public const ulong FILE_INITIATE_REPAIR_HINT1_ORPHAN_GENERATED = 0x0000000000000200;

        public const ulong FILE_INITIATE_REPAIR_HINT1_REPAIRED = 0x0000000000000400;

        public const ulong FILE_INITIATE_REPAIR_HINT1_NOTHING_WRONG = 0x0000000000000800;

        public const ulong FILE_INITIATE_REPAIR_HINT1_ATTRIBUTE_NOT_FOUND = 0x0000000000001000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_POTENTIAL_CROSSLINK = 0x0000000000002000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_STALE_INFORMATION = 0x0000000000004000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_CLUSTERS_ALREADY_IN_USE = 0x0000000000008000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_LCN_NOT_EXIST = 0x0000000000010000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_INVALID_RUN_LENGTH = 0x0000000000020000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_ORPHAN = 0x0000000000040000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_IS_BASE_RECORD = 0x0000000000080000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_INVALID_ARRAY_LENGTH_COUNT = 0x0000000000100000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_SID_VALID = 0x0000000000200000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_SID_MISMATCH = 0x0000000000400000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_INVALID_PARENT = 0x0000000000800000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_IN_USE = 0x0000000001000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_REUSED = 0x0000000002000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_EXIST = 0x0000000004000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_BASE_RECORD = 0x0000000008000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_INDEX = 0x0000000010000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_VALID_INDEX_ENTRY = 0x0000000020000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_OUT_OF_GENERIC_NAMES = 0x0000000040000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_OUT_OF_RESOURCE = 0x0000000080000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_INVALID_LCN = 0x0000000100000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_INVALID_VCN = 0x0000000200000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_NAME_CONFLICT = 0x0000000400000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_ORPHAN = 0x0000000800000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_ATTRIBUTE_TOO_SMALL = 0x0000001000000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_ATTRIBUTE_NON_RESIDENT = 0x0000002000000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_DENY_DEFRAG = 0x0000004000000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_PREVIOUS_PARENT_STILL_VALID = 0x0000008000000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_INDEX_ENTRY_MISMATCH = 0x0000010000000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_INVALID_ORPHAN_RECOVERY_NAME = 0x0000020000000000;

        public const ulong FILE_INITIATE_REPAIR_HINT1_MULTIPLE_FILE_NAME_ATTRIBUTES = 0x0000040000000000;

        public const uint TXFS_LOGGING_MODE_SIMPLE = 0x0001;

        public const uint TXFS_LOGGING_MODE_FULL = 0x0002;

        public const uint TXFS_TRANSACTION_STATE_NONE = 0x00;

        public const uint TXFS_TRANSACTION_STATE_ACTIVE = 0x01;

        public const uint TXFS_TRANSACTION_STATE_PREPARED = 0x02;

        public const uint TXFS_TRANSACTION_STATE_NOTACTIVE = 0x03;

        public const uint TXFS_RM_STATE_NOT_STARTED = 0;

        public const uint TXFS_RM_STATE_STARTING = 1;

        public const uint TXFS_RM_STATE_ACTIVE = 2;

        public const uint TXFS_RM_STATE_SHUTTING_DOWN = 3;

        public const uint TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_REDO_LSN = 0x01;

        public const uint TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_VIRTUAL_CLOCK = 0x02;

        public const uint TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MAX = 0x00000001;

        public const uint TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MIN = 0x00000002;

        public const uint TXFS_START_RM_FLAG_LOG_CONTAINER_SIZE = 0x00000004;

        public const uint TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS = 0x00000008;

        public const uint TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT = 0x00000010;

        public const uint TXFS_START_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE = 0x00000020;

        public const uint TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX = 0x00000040;

        public const uint TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN = 0x00000080;

        public const uint TXFS_START_RM_FLAG_RECOVER_BEST_EFFORT = 0x00000200;

        public const uint TXFS_START_RM_FLAG_LOGGING_MODE = 0x00000400;

        public const uint TXFS_START_RM_FLAG_PRESERVE_CHANGES = 0x00000800;

        public const uint TXFS_START_RM_FLAG_PREFER_CONSISTENCY = 0x00001000;

        public const uint TXFS_START_RM_FLAG_PREFER_AVAILABILITY = 0x00002000;

        public const uint TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_CREATED = 0x00000001;

        public const uint TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_DELETED = 0x00000002;

        public const uint TXFS_TRANSACTED_VERSION_NONTRANSACTED = 0xFFFFFFFE;

        public const uint TXFS_TRANSACTED_VERSION_UNCOMMITTED = 0xFFFFFFFF;

        public const uint TXFS_SAVEPOINT_SET = 0x00000001;

        public const uint TXFS_SAVEPOINT_ROLLBACK = 0x00000002;

        public const uint TXFS_SAVEPOINT_CLEAR = 0x00000004;

        public const uint TXFS_SAVEPOINT_CLEAR_ALL = 0x00000010;

        public const uint PERSISTENT_VOLUME_STATE_SHORT_NAME_CREATION_DISABLED = 0x00000001;

        public const uint PERSISTENT_VOLUME_STATE_VOLUME_SCRUB_DISABLED = 0x00000002;

        public const uint PERSISTENT_VOLUME_STATE_GLOBAL_METADATA_NO_SEEK_PENALTY = 0x00000004;

        public const uint PERSISTENT_VOLUME_STATE_LOCAL_METADATA_NO_SEEK_PENALTY = 0x00000008;

        public const uint PERSISTENT_VOLUME_STATE_NO_HEAT_GATHERING = 0x00000010;

        public const uint PERSISTENT_VOLUME_STATE_CONTAINS_BACKING_WIM = 0x00000020;

        public const uint PERSISTENT_VOLUME_STATE_BACKED_BY_WIM = 0x00000040;

        public const uint PERSISTENT_VOLUME_STATE_NO_WRITE_AUTO_TIERING = 0x00000080;

        public const uint PERSISTENT_VOLUME_STATE_TXF_DISABLED = 0x00000100;

        public const uint PERSISTENT_VOLUME_STATE_REALLOCATE_ALL_DATA_WRITES = 0x00000200;

        public const uint OPLOCK_LEVEL_CACHE_READ = 0x00000001;

        public const uint OPLOCK_LEVEL_CACHE_HANDLE = 0x00000002;

        public const uint OPLOCK_LEVEL_CACHE_WRITE = 0x00000004;

        public const uint REQUEST_OPLOCK_INPUT_FLAG_REQUEST = 0x00000001;

        public const uint REQUEST_OPLOCK_INPUT_FLAG_ACK = 0x00000002;

        public const uint REQUEST_OPLOCK_INPUT_FLAG_COMPLETE_ACK_ON_CLOSE = 0x00000004;

        public const uint REQUEST_OPLOCK_CURRENT_VERSION = 1;

        public const uint REQUEST_OPLOCK_OUTPUT_FLAG_ACK_REQUIRED = 0x00000001;

        public const uint REQUEST_OPLOCK_OUTPUT_FLAG_MODES_PROVIDED = 0x00000002;

        public const uint QUERY_DEPENDENT_VOLUME_REQUEST_FLAG_HOST_VOLUMES = 0x1;

        public const uint QUERY_DEPENDENT_VOLUME_REQUEST_FLAG_GUEST_VOLUMES = 0x2;

        public const uint SD_GLOBAL_CHANGE_TYPE_MACHINE_SID = 1;

        public const uint SD_GLOBAL_CHANGE_TYPE_QUERY_STATS = 1u<< 16;

        public const uint SD_GLOBAL_CHANGE_TYPE_ENUM_SDS = 2u<< 16;

        public const uint LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_PAGE_FILE = 0x00000001;

        public const uint LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_DENY_DEFRAG_SET = 0x00000002;

        public const uint LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_FS_SYSTEM_FILE = 0x00000004;

        public const uint LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_TXF_SYSTEM_FILE = 0x00000008;

        public const uint LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_MASK = 0xff000000;

        public const uint LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_DATA = 0x01000000;

        public const uint LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_INDEX = 0x02000000;

        public const uint LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_SYSTEM = 0x03000000;

        public const uint FILE_TYPE_NOTIFICATION_FLAG_USAGE_BEGIN = 0x00000001;

        public const uint FILE_TYPE_NOTIFICATION_FLAG_USAGE_END = 0x00000002;

        public static readonly Guid FILE_TYPE_NOTIFICATION_GUID_PAGE_FILE__scanned__ = new Guid(0x0d0a64a1, 0x38fc, 0x4db8, 0x9f, 0xe7, 0x3f, 0x43, 0x52, 0xcd, 0x7c, 0x5c );

        public static readonly Guid FILE_TYPE_NOTIFICATION_GUID_HIBERNATION_FILE__scanned__ = new Guid(0xb7624d64, 0xb9a3, 0x4cf8, 0x80, 0x11, 0x5b, 0x86, 0xc9, 0x40, 0xe7, 0xb7 );

        public static readonly Guid FILE_TYPE_NOTIFICATION_GUID_CRASHDUMP_FILE__scanned__ = new Guid(0x9d453eb7, 0xd2a6, 0x4dbd, 0xa2, 0xe3, 0xfb, 0xd0, 0xed, 0x91, 0x09, 0xa9 );

        public const uint CSV_MGMTLOCK_CHECK_VOLUME_REDIRECTED = 0x00000001;

        public const uint CSV_INVALID_DEVICE_NUMBER = 0xFFFFFFFF;

        public const uint CSV_QUERY_MDS_PATH_V2_VERSION_1 = 1;

        public const uint CSV_QUERY_MDS_PATH_FLAG_STORAGE_ON_THIS_NODE_IS_CONNECTED = 0x1;

        public const uint CSV_QUERY_MDS_PATH_FLAG_CSV_DIRECT_IO_ENABLED = 0x2;

        public const uint CSV_QUERY_MDS_PATH_FLAG_SMB_BYPASS_CSV_ENABLED = 0x4;

        public const uint QUERY_FILE_LAYOUT_RESTART = 0x00000001;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_NAMES = 0x00000002;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_STREAMS = 0x00000004;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_EXTENTS = 0x00000008;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_EXTRA_INFO = 0x00000010;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_STREAMS_WITH_NO_CLUSTERS_ALLOCATED = 0x00000020;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_FULL_PATH_IN_NAMES = 0x00000040;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION = 0x00000080;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_DSC_ATTRIBUTE = 0x00000100;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_TXF_ATTRIBUTE = 0x00000200;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_EFS_ATTRIBUTE = 0x00000400;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_ONLY_FILES_WITH_SPECIFIC_ATTRIBUTES = 0x00000800;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_FILES_WITH_DSC_ATTRIBUTE = 0x00001000;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_DATA_ATTRIBUTE = 0x00002000;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_REPARSE_ATTRIBUTE = 0x00004000;

        public const uint QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_EA_ATTRIBUTE = 0x00008000;

        public const uint QUERY_FILE_LAYOUT_SINGLE_INSTANCED = 0x00000001;

        public const uint FILE_LAYOUT_NAME_ENTRY_PRIMARY = 0x00000001;

        public const uint FILE_LAYOUT_NAME_ENTRY_DOS = 0x00000002;

        public const uint STREAM_LAYOUT_ENTRY_IMMOVABLE = 0x00000001;

        public const uint STREAM_LAYOUT_ENTRY_PINNED = 0x00000002;

        public const uint STREAM_LAYOUT_ENTRY_RESIDENT = 0x00000004;

        public const uint STREAM_LAYOUT_ENTRY_NO_CLUSTERS_ALLOCATED = 0x00000008;

        public const uint STREAM_LAYOUT_ENTRY_HAS_INFORMATION = 0x00000010;

        public const uint STREAM_EXTENT_ENTRY_AS_RETRIEVAL_POINTERS = 0x00000001;

        public const uint STREAM_EXTENT_ENTRY_ALL_EXTENTS = 0x00000002;

        public const int CHECKSUM_TYPE_UNCHANGED = -1;

        public const uint CHECKSUM_TYPE_NONE = 0;

        public const uint CHECKSUM_TYPE_CRC32 = 1;

        public const uint CHECKSUM_TYPE_CRC64 = 2;

        public const uint CHECKSUM_TYPE_ECC = 3;

        public const uint CHECKSUM_TYPE_FIRST_UNUSED_TYPE = 4;

        public const uint FSCTL_INTEGRITY_FLAG_CHECKSUM_ENFORCEMENT_OFF = 1;

        public const uint OFFLOAD_READ_FLAG_ALL_ZERO_BEYOND_CURRENT_RANGE = 1;

        public const uint SET_PURGE_FAILURE_MODE_ENABLED = 0x00000001;

        public const uint SET_PURGE_FAILURE_MODE_DISABLED = 0x00000002;

        public const uint FILE_REGION_USAGE_VALID_CACHED_DATA = 0x00000001;

        public const uint FILE_REGION_USAGE_VALID_NONCACHED_DATA = 0x00000002;

        public const uint FILE_REGION_USAGE_OTHER_PAGE_ALIGNMENT = 0x00000004;

        public const uint FILE_REGION_USAGE_LARGE_PAGE_ALIGNMENT = 0x00000008;

        public const uint FILE_REGION_USAGE_HUGE_PAGE_ALIGNMENT = 0x00000010;

        public const uint FILE_STORAGE_TIER_NAME_LENGTH = 256;

        public const uint FILE_STORAGE_TIER_DESCRIPTION_LENGTH = 512;

        public const uint FILE_STORAGE_TIER_FLAG_WRITE_BACK_CACHE = 0x00200000;

        public const uint FILE_STORAGE_TIER_FLAG_READ_CACHE = 0x00400000;

        public const uint FILE_STORAGE_TIER_FLAG_PARITY = 0x00800000;

        public const uint FILE_STORAGE_TIER_FLAG_SMR = 0x01000000;

        public const uint QUERY_STORAGE_CLASSES_FLAGS_MEASURE_WRITE = 0x80000000;

        public const uint QUERY_STORAGE_CLASSES_FLAGS_MEASURE_READ = 0x40000000;

        public const uint QUERY_STORAGE_CLASSES_FLAGS_NO_DEFRAG_VOLUME = 0x20000000;

        public const uint QUERY_FILE_LAYOUT_REPARSE_DATA_INVALID = 0x0001;

        public const uint QUERY_FILE_LAYOUT_REPARSE_TAG_INVALID = 0x0002;

        public const uint DUPLICATE_EXTENTS_DATA_EX_SOURCE_ATOMIC = 0x00000001;

        public const uint DUPLICATE_EXTENTS_DATA_EX_ASYNC = 0x00000002;

        public const uint REFS_SMR_VOLUME_INFO_OUTPUT_VERSION_V1 = 1;

        public const uint REFS_SMR_VOLUME_GC_PARAMETERS_VERSION_V1 = 1;

        public const uint STREAMS_INVALID_ID = 0;

        public const uint STREAMS_ASSOCIATE_ID_CLEAR = 0x1;

        public const uint STREAMS_ASSOCIATE_ID_SET = 0x2;

        public const uint DAX_ALLOC_ALIGNMENT_FLAG_MANDATORY = 0x00000001;

        public const uint DAX_ALLOC_ALIGNMENT_FLAG_FALLBACK_SPECIFIED = 0x00000002;

        public const uint WOF_CURRENT_VERSION = 0x00000001;

        public const uint WOF_PROVIDER_WIM = 0x00000001;

        public const uint WOF_PROVIDER_FILE = 0x00000002;

        public const uint WOF_PROVIDER_CLOUD = 0x00000003;

        public const uint WIM_PROVIDER_HASH_SIZE = 20;

        public const uint WIM_PROVIDER_CURRENT_VERSION = 0x00000001;

        public const uint WIM_PROVIDER_EXTERNAL_FLAG_NOT_ACTIVE = 0x00000001;

        public const uint WIM_PROVIDER_EXTERNAL_FLAG_SUSPENDED = 0x00000002;

        public const uint WIM_BOOT_OS_WIM = 0x00000001;

        public const uint WIM_BOOT_NOT_OS_WIM = 0x00000000;

        public const uint FILE_PROVIDER_CURRENT_VERSION = 0x00000001;

        public const uint FILE_PROVIDER_SINGLE_FILE = 0x00000001;

        public const uint FILE_PROVIDER_COMPRESSION_XPRESS4K = 0x00000000;

        public const uint FILE_PROVIDER_COMPRESSION_LZX = 0x00000001;

        public const uint FILE_PROVIDER_COMPRESSION_XPRESS8K = 0x00000002;

        public const uint FILE_PROVIDER_COMPRESSION_XPRESS16K = 0x00000003;

        public const uint FILE_PROVIDER_COMPRESSION_MAXIMUM = 0x00000004;

        public const uint FILE_PROVIDER_FLAG_COMPRESS_ON_WRITE = 0x00000001;

        public const uint CONTAINER_VOLUME_STATE_HOSTING_CONTAINER = 0x00000001;

        public const uint CONTAINER_ROOT_INFO_FLAG_SCRATCH_ROOT = 0x00000001;

        public const uint CONTAINER_ROOT_INFO_FLAG_LAYER_ROOT = 0x00000002;

        public const uint CONTAINER_ROOT_INFO_FLAG_VIRTUALIZATION_ROOT = 0x00000004;

        public const uint CONTAINER_ROOT_INFO_FLAG_VIRTUALIZATION_TARGET_ROOT = 0x00000008;

        public const uint CONTAINER_ROOT_INFO_FLAG_VIRTUALIZATION_EXCEPTION_ROOT = 0x00000010;

        public const uint CONTAINER_ROOT_INFO_FLAG_BIND_ROOT = 0x00000020;

        public const uint CONTAINER_ROOT_INFO_FLAG_BIND_TARGET_ROOT = 0x00000040;

        public const uint CONTAINER_ROOT_INFO_FLAG_BIND_EXCEPTION_ROOT = 0x00000080;

        public const uint CONTAINER_ROOT_INFO_FLAG_BIND_DO_NOT_MAP_NAME = 0x00000100;

        public const uint CONTAINER_ROOT_INFO_VALID_FLAGS = 0x000001ff;

        public const uint PROJFS_PROTOCOL_VERSION = 3;

        public const uint IOCTL_VOLUME_BASE = 0x00000056;

        public const uint IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_ONLINE = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((2) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_OFFLINE = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((3) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_IS_CLUSTERED = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((12) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_GET_GPT_ATTRIBUTES = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((14) << 2) | (METHOD_BUFFERED);

        public const uint EFS_TRACKED_OFFSET_HEADER_FLAG = 0x0001;

        public const uint SPACES_TRACKED_OFFSET_HEADER_FLAG = 0x0002;

        public const uint ROTFLAGS_REGISTRATIONKEEPSALIVE = 0x1;

        public const uint ROTFLAGS_ALLOWANYCLIENT = 0x2;

        public const uint ROT_COMPARE_MAX = 2048;

        public const uint WDT_INPROC_CALL = 0x48746457;

        public const uint WDT_REMOTE_CALL = 0x52746457;

        public const uint WDT_INPROC64_CALL = 0x50746457;

        public const uint TIME_ONESHOT = 0x0000;

        public const uint TIME_PERIODIC = 0x0001;

        public const uint TIME_CALLBACK_FUNCTION = 0x0000;

        public const uint TIME_CALLBACK_EVENT_SET = 0x0010;

        public const uint TIME_CALLBACK_EVENT_PULSE = 0x0020;

        public const uint TIME_KILL_SYNCHRONOUS = 0x0100;

        public const uint PROCESS_HEAP_REGION = 0x0001;

        public const uint PROCESS_HEAP_UNCOMMITTED_RANGE = 0x0002;

        public const uint PROCESS_HEAP_ENTRY_BUSY = 0x0004;

        public const uint PROCESS_HEAP_SEG_ALLOC = 0x0008;

        public const uint PROCESS_HEAP_ENTRY_MOVEABLE = 0x0010;

        public const uint PROCESS_HEAP_ENTRY_DDESHARE = 0x0020;

        public const uint LMEM_NOCOMPACT = 0x0010;

        public const uint LMEM_NODISCARD = 0x0020;

        public const uint LMEM_MODIFY = 0x0080;

        public const uint LMEM_DISCARDABLE = 0x0F00;

        public const uint LMEM_VALID_FLAGS = 0x0F72;

        public const uint LMEM_INVALID_HANDLE = 0x8000;

        public const uint LMEM_DISCARDED = 0x4000;

        public const uint LMEM_LOCKCOUNT = 0x00FF;

        public const uint NUMA_NO_PREFERRED_NODE = 0xFFFFFFFF;

        public const uint REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION = 1;

    }
}

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


namespace Windows.Win32.Devices.Sensors
{
    public static partial class Apis
    {
        public static readonly Guid GUID_DEVINTERFACE_SENSOR__scanned__ = new Guid(0XBA1BB692, 0X9B7A, 0X4833, 0X9A, 0X1E, 0X52, 0X5E, 0XD1, 0X34, 0XE7, 0XE2);

        public static readonly Guid SENSOR_EVENT_STATE_CHANGED__scanned__ = new Guid(0XBFD96016, 0X6BD7, 0X4560, 0XAD, 0X34, 0XF2, 0XF6, 0X60, 0X7E, 0X8F, 0X81);

        public static readonly Guid SENSOR_EVENT_DATA_UPDATED__scanned__ = new Guid(0X2ED0F2A4, 0X0087, 0X41D3, 0X87, 0XDB, 0X67, 0X73, 0X37, 0X0B, 0X3C, 0X88);

        public static readonly Guid SENSOR_EVENT_PROPERTY_CHANGED__scanned__ = new Guid(0X2358F099, 0X84C9, 0X4D3D, 0X90, 0XDF, 0XC2, 0X42, 0X1E, 0X2B, 0X20, 0X45);

        public static readonly Guid SENSOR_EVENT_ACCELEROMETER_SHAKE__scanned__ = new Guid(0X825F5A94, 0X0F48, 0X4396, 0X9C, 0XA0, 0X6E, 0XCB, 0X5C, 0X99, 0XD9, 0X15);

        public static readonly Guid SENSOR_EVENT_PARAMETER_COMMON_GUID__scanned__ = new Guid(0X64346E30, 0X8728, 0X4B34, 0XBD, 0XF6, 0X4F, 0X52, 0X44, 0X2C, 0X5C, 0X28);

        public static readonly Guid SENSOR_ERROR_PARAMETER_COMMON_GUID__scanned__ = new Guid(0X77112BCD, 0XFCE1, 0X4F43, 0XB8, 0XB8, 0XA8, 0X82, 0X56, 0XAD, 0XB4, 0XB3);

        public static readonly Guid SENSOR_PROPERTY_COMMON_GUID__scanned__ = new Guid(0X7F8383EC, 0XD3EC, 0X495C, 0XA8, 0XCF, 0XB8, 0XBB, 0XE8, 0X5C, 0X29, 0X20);

        public static readonly Guid SENSOR_CATEGORY_ALL__scanned__ = new Guid(0XC317C286, 0XC468, 0X4288, 0X99, 0X75, 0XD4, 0XC4, 0X58, 0X7C, 0X44, 0X2C);

        public static readonly Guid SENSOR_CATEGORY_LOCATION__scanned__ = new Guid(0XBFA794E4, 0XF964, 0X4FDB, 0X90, 0XF6, 0X51, 0X05, 0X6B, 0XFE, 0X4B, 0X44);

        public static readonly Guid SENSOR_CATEGORY_ENVIRONMENTAL__scanned__ = new Guid(0X323439AA, 0X7F66, 0X492B, 0XBA, 0X0C, 0X73, 0XE9, 0XAA, 0X0A, 0X65, 0XD5);

        public static readonly Guid SENSOR_CATEGORY_MOTION__scanned__ = new Guid(0XCD09DAF1, 0X3B2E, 0X4C3D, 0XB5, 0X98, 0XB5, 0XE5, 0XFF, 0X93, 0XFD, 0X46);

        public static readonly Guid SENSOR_CATEGORY_ORIENTATION__scanned__ = new Guid(0X9E6C04B6, 0X96FE, 0X4954, 0XB7, 0X26, 0X68, 0X68, 0X2A, 0X47, 0X3F, 0X69);

        public static readonly Guid SENSOR_CATEGORY_MECHANICAL__scanned__ = new Guid(0X8D131D68, 0X8EF7, 0X4656, 0X80, 0XB5, 0XCC, 0XCB, 0XD9, 0X37, 0X91, 0XC5);

        public static readonly Guid SENSOR_CATEGORY_ELECTRICAL__scanned__ = new Guid(0XFB73FCD8, 0XFC4A, 0X483C, 0XAC, 0X58, 0X27, 0XB6, 0X91, 0XC6, 0XBE, 0XFF);

        public static readonly Guid SENSOR_CATEGORY_BIOMETRIC__scanned__ = new Guid(0XCA19690F, 0XA2C7, 0X477D, 0XA9, 0X9E, 0X99, 0XEC, 0X6E, 0X2B, 0X56, 0X48);

        public static readonly Guid SENSOR_CATEGORY_LIGHT__scanned__ = new Guid(0X17A665C0, 0X9063, 0X4216, 0XB2, 0X02, 0X5C, 0X7A, 0X25, 0X5E, 0X18, 0XCE);

        public static readonly Guid SENSOR_CATEGORY_SCANNER__scanned__ = new Guid(0XB000E77E, 0XF5B5, 0X420F, 0X81, 0X5D, 0X02, 0X70, 0XA7, 0X26, 0XF2, 0X70);

        public static readonly Guid SENSOR_CATEGORY_OTHER__scanned__ = new Guid(0x2C90E7A9, 0xF4C9, 0x4FA2, 0xAF, 0x37, 0x56, 0xD4, 0x71, 0xFE, 0x5A, 0x3D);

        public static readonly Guid SENSOR_CATEGORY_UNSUPPORTED__scanned__ = new Guid(0x2BEAE7fA, 0x19B0, 0x48C5, 0xA1, 0xF6, 0xB5, 0x48, 0x0D, 0xC2, 0x06, 0xB0);

        public static readonly Guid SENSOR_TYPE_LOCATION_GPS__scanned__ = new Guid(0XED4CA589, 0X327A, 0X4FF9, 0XA5, 0X60, 0X91, 0XDA, 0X4B, 0X48, 0X27, 0X5E);

        public static readonly Guid SENSOR_TYPE_LOCATION_STATIC__scanned__ = new Guid(0X095F8184, 0X0FA9, 0X4445, 0X8E, 0X6E, 0XB7, 0X0F, 0X32, 0X0B, 0X6B, 0X4C);

        public static readonly Guid SENSOR_TYPE_LOCATION_LOOKUP__scanned__ = new Guid(0X3B2EAE4A, 0X72CE, 0X436D, 0X96, 0XD2, 0X3C, 0X5B, 0X85, 0X70, 0XE9, 0X87);

        public static readonly Guid SENSOR_TYPE_LOCATION_TRIANGULATION__scanned__ = new Guid(0X691C341A, 0X5406, 0X4FE1, 0X94, 0X2F, 0X22, 0X46, 0XCB, 0XEB, 0X39, 0XE0);

        public static readonly Guid SENSOR_TYPE_LOCATION_OTHER__scanned__ = new Guid(0X9B2D0566, 0X0368, 0X4F71, 0XB8, 0X8D, 0X53, 0X3F, 0X13, 0X20, 0X31, 0XDE);

        public static readonly Guid SENSOR_TYPE_LOCATION_BROADCAST__scanned__ = new Guid(0XD26988CF, 0X5162, 0X4039, 0XBB, 0X17, 0X4C, 0X58, 0XB6, 0X98, 0XE4, 0X4A);

        public static readonly Guid SENSOR_TYPE_LOCATION_DEAD_RECKONING__scanned__ = new Guid(0X1A37D538, 0XF28B, 0X42DA, 0X9F, 0XCE, 0XA9, 0XD0, 0XA2, 0XA6, 0XD8, 0X29);

        public static readonly Guid SENSOR_TYPE_ENVIRONMENTAL_TEMPERATURE__scanned__ = new Guid(0X04FD0EC4, 0XD5DA, 0X45FA, 0X95, 0XA9, 0X5D, 0XB3, 0X8E, 0XE1, 0X93, 0X06);

        public static readonly Guid SENSOR_TYPE_ENVIRONMENTAL_ATMOSPHERIC_PRESSURE__scanned__ = new Guid(0X0E903829, 0XFF8A, 0X4A93, 0X97, 0XDF, 0X3D, 0XCB, 0XDE, 0X40, 0X22, 0X88);

        public static readonly Guid SENSOR_TYPE_ENVIRONMENTAL_HUMIDITY__scanned__ = new Guid(0X5C72BF67, 0XBD7E, 0X4257, 0X99, 0X0B, 0X98, 0XA3, 0XBA, 0X3B, 0X40, 0X0A);

        public static readonly Guid SENSOR_TYPE_ENVIRONMENTAL_WIND_SPEED__scanned__ = new Guid(0XDD50607B, 0XA45F, 0X42CD, 0X8E, 0XFD, 0XEC, 0X61, 0X76, 0X1C, 0X42, 0X26);

        public static readonly Guid SENSOR_TYPE_ENVIRONMENTAL_WIND_DIRECTION__scanned__ = new Guid(0X9EF57A35, 0X9306, 0X434D, 0XAF, 0X09, 0X37, 0XFA, 0X5A, 0X9C, 0X00, 0XBD);

        public static readonly Guid SENSOR_TYPE_ACCELEROMETER_1D__scanned__ = new Guid(0XC04D2387, 0X7340, 0X4CC2, 0X99, 0X1E, 0X3B, 0X18, 0XCB, 0X8E, 0XF2, 0XF4);

        public static readonly Guid SENSOR_TYPE_ACCELEROMETER_2D__scanned__ = new Guid(0XB2C517A8, 0XF6B5, 0X4BA6, 0XA4, 0X23, 0X5D, 0XF5, 0X60, 0XB4, 0XCC, 0X07);

        public static readonly Guid SENSOR_TYPE_ACCELEROMETER_3D__scanned__ = new Guid(0XC2FB0F5F, 0XE2D2, 0X4C78, 0XBC, 0XD0, 0X35, 0X2A, 0X95, 0X82, 0X81, 0X9D);

        public static readonly Guid SENSOR_TYPE_MOTION_DETECTOR__scanned__ = new Guid(0X5C7C1A12, 0X30A5, 0X43B9, 0XA4, 0XB2, 0XCF, 0X09, 0XEC, 0X5B, 0X7B, 0XE8);

        public static readonly Guid SENSOR_TYPE_GYROMETER_1D__scanned__ = new Guid(0XFA088734, 0XF552, 0X4584, 0X83, 0X24, 0XED, 0XFA, 0XF6, 0X49, 0X65, 0X2C);

        public static readonly Guid SENSOR_TYPE_GYROMETER_2D__scanned__ = new Guid(0X31EF4F83, 0X919B, 0X48BF, 0X8D, 0XE0, 0X5D, 0X7A, 0X9D, 0X24, 0X05, 0X56);

        public static readonly Guid SENSOR_TYPE_GYROMETER_3D__scanned__ = new Guid(0X09485F5A, 0X759E, 0X42C2, 0XBD, 0X4B, 0XA3, 0X49, 0XB7, 0X5C, 0X86, 0X43);

        public static readonly Guid SENSOR_TYPE_SPEEDOMETER__scanned__ = new Guid(0X6BD73C1F, 0X0BB4, 0X4310, 0X81, 0XB2, 0XDF, 0XC1, 0X8A, 0X52, 0XBF, 0X94);

        public static readonly Guid SENSOR_TYPE_COMPASS_1D__scanned__ = new Guid(0XA415F6C5, 0XCB50, 0X49D0, 0X8E, 0X62, 0XA8, 0X27, 0X0B, 0XD7, 0XA2, 0X6C);

        public static readonly Guid SENSOR_TYPE_COMPASS_2D__scanned__ = new Guid(0X15655CC0, 0X997A, 0X4D30, 0X84, 0XDB, 0X57, 0XCA, 0XBA, 0X36, 0X48, 0XBB);

        public static readonly Guid SENSOR_TYPE_COMPASS_3D__scanned__ = new Guid(0X76B5CE0D, 0X17DD, 0X414D, 0X93, 0XA1, 0XE1, 0X27, 0XF4, 0X0B, 0XDF, 0X6E);

        public static readonly Guid SENSOR_TYPE_INCLINOMETER_1D__scanned__ = new Guid(0XB96F98C5, 0X7A75, 0X4BA7, 0X94, 0XE9, 0XAC, 0X86, 0X8C, 0X96, 0X6D, 0XD8);

        public static readonly Guid SENSOR_TYPE_INCLINOMETER_2D__scanned__ = new Guid(0XAB140F6D, 0X83EB, 0X4264, 0XB7, 0X0B, 0XB1, 0X6A, 0X5B, 0X25, 0X6A, 0X01);

        public static readonly Guid SENSOR_TYPE_INCLINOMETER_3D__scanned__ = new Guid(0XB84919FB, 0XEA85, 0X4976, 0X84, 0X44, 0X6F, 0X6F, 0X5C, 0X6D, 0X31, 0XDB);

        public static readonly Guid SENSOR_TYPE_DISTANCE_1D__scanned__ = new Guid(0X5F14AB2F, 0X1407, 0X4306, 0XA9, 0X3F, 0XB1, 0XDB, 0XAB, 0XE4, 0XF9, 0XC0);

        public static readonly Guid SENSOR_TYPE_DISTANCE_2D__scanned__ = new Guid(0X5CF9A46C, 0XA9A2, 0X4E55, 0XB6, 0XA1, 0XA0, 0X4A, 0XAF, 0XA9, 0X5A, 0X92);

        public static readonly Guid SENSOR_TYPE_DISTANCE_3D__scanned__ = new Guid(0XA20CAE31, 0X0E25, 0X4772, 0X9F, 0XE5, 0X96, 0X60, 0X8A, 0X13, 0X54, 0XB2);

        public static readonly Guid SENSOR_TYPE_AGGREGATED_QUADRANT_ORIENTATION__scanned__ = new Guid(0X9F81F1AF, 0XC4AB, 0X4307, 0X99, 0X04, 0XC8, 0X28, 0XBF, 0XB9, 0X08, 0X29);

        public static readonly Guid SENSOR_TYPE_AGGREGATED_DEVICE_ORIENTATION__scanned__ = new Guid(0XCDB5D8F7, 0X3CFD, 0X41C8, 0X85, 0X42, 0XCC, 0XE6, 0X22, 0XCF, 0X5D, 0X6E);

        public static readonly Guid SENSOR_TYPE_AGGREGATED_SIMPLE_DEVICE_ORIENTATION__scanned__ = new Guid(0X86A19291, 0X0482, 0X402C, 0XBF, 0X4C, 0XAD, 0XDA, 0XC5, 0X2B, 0X1C, 0X39);

        public static readonly Guid SENSOR_TYPE_VOLTAGE__scanned__ = new Guid(0XC5484637, 0X4FB7, 0X4953, 0X98, 0XB8, 0XA5, 0X6D, 0X8A, 0XA1, 0XFB, 0X1E);

        public static readonly Guid SENSOR_TYPE_CURRENT__scanned__ = new Guid(0X5ADC9FCE, 0X15A0, 0X4BBE, 0XA1, 0XAD, 0X2D, 0X38, 0XA9, 0XAE, 0X83, 0X1C);

        public static readonly Guid SENSOR_TYPE_CAPACITANCE__scanned__ = new Guid(0XCA2FFB1C, 0X2317, 0X49C0, 0XA0, 0XB4, 0XB6, 0X3C, 0XE6, 0X34, 0X61, 0XA0);

        public static readonly Guid SENSOR_TYPE_RESISTANCE__scanned__ = new Guid(0X9993D2C8, 0XC157, 0X4A52, 0XA7, 0XB5, 0X19, 0X5C, 0X76, 0X03, 0X72, 0X31);

        public static readonly Guid SENSOR_TYPE_INDUCTANCE__scanned__ = new Guid(0XDC1D933F, 0XC435, 0X4C7D, 0XA2, 0XFE, 0X60, 0X71, 0X92, 0XA5, 0X24, 0XD3);

        public static readonly Guid SENSOR_TYPE_ELECTRICAL_POWER__scanned__ = new Guid(0X212F10F5, 0X14AB, 0X4376, 0X9A, 0X43, 0XA7, 0X79, 0X40, 0X98, 0XC2, 0XFE);

        public static readonly Guid SENSOR_TYPE_POTENTIOMETER__scanned__ = new Guid(0X2B3681A9, 0XCADC, 0X45AA, 0XA6, 0XFF, 0X54, 0X95, 0X7C, 0X8B, 0XB4, 0X40);

        public static readonly Guid SENSOR_TYPE_FREQUENCY__scanned__ = new Guid(0X8CD2CBB6, 0X73E6, 0X4640, 0XA7, 0X09, 0X72, 0XAE, 0X8F, 0XB6, 0X0D, 0X7F);

        public static readonly Guid SENSOR_TYPE_BOOLEAN_SWITCH__scanned__ = new Guid(0X9C7E371F, 0X1041, 0X460B, 0X8D, 0X5C, 0X71, 0XE4, 0X75, 0X2E, 0X35, 0X0C);

        public static readonly Guid SENSOR_TYPE_MULTIVALUE_SWITCH__scanned__ = new Guid(0XB3EE4D76, 0X37A4, 0X4402, 0XB2, 0X5E, 0X99, 0XC6, 0X0A, 0X77, 0X5F, 0XA1);

        public static readonly Guid SENSOR_TYPE_FORCE__scanned__ = new Guid(0XC2AB2B02, 0X1A1C, 0X4778, 0XA8, 0X1B, 0X95, 0X4A, 0X17, 0X88, 0XCC, 0X75);

        public static readonly Guid SENSOR_TYPE_SCALE__scanned__ = new Guid(0XC06DD92C, 0X7FEB, 0X438E, 0X9B, 0XF6, 0X82, 0X20, 0X7F, 0XFF, 0X5B, 0XB8);

        public static readonly Guid SENSOR_TYPE_PRESSURE__scanned__ = new Guid(0X26D31F34, 0X6352, 0X41CF, 0XB7, 0X93, 0XEA, 0X07, 0X13, 0XD5, 0X3D, 0X77);

        public static readonly Guid SENSOR_TYPE_STRAIN__scanned__ = new Guid(0XC6D1EC0E, 0X6803, 0X4361, 0XAD, 0X3D, 0X85, 0XBC, 0XC5, 0X8C, 0X6D, 0X29);

        public static readonly Guid SENSOR_TYPE_BOOLEAN_SWITCH_ARRAY__scanned__ = new Guid(0X545C8BA5, 0XB143, 0X4545, 0X86, 0X8F, 0XCA, 0X7F, 0XD9, 0X86, 0XB4, 0XF6);

        public static readonly Guid SENSOR_TYPE_HUMAN_PRESENCE__scanned__ = new Guid(0XC138C12B, 0XAD52, 0X451C, 0X93, 0X75, 0X87, 0XF5, 0X18, 0XFF, 0X10, 0XC6);

        public static readonly Guid SENSOR_TYPE_HUMAN_PROXIMITY__scanned__ = new Guid(0X5220DAE9, 0X3179, 0X4430, 0X9F, 0X90, 0X06, 0X26, 0X6D, 0X2A, 0X34, 0XDE);

        public static readonly Guid SENSOR_TYPE_TOUCH__scanned__ = new Guid(0X17DB3018, 0X06C4, 0X4F7D, 0X81, 0XAF, 0X92, 0X74, 0XB7, 0X59, 0X9C, 0X27);

        public static readonly Guid SENSOR_TYPE_AMBIENT_LIGHT__scanned__ = new Guid(0X97F115C8, 0X599A, 0X4153, 0X88, 0X94, 0XD2, 0XD1, 0X28, 0X99, 0X91, 0X8A);

        public static readonly Guid SENSOR_TYPE_RFID_SCANNER__scanned__ = new Guid(0X44328EF5, 0X02DD, 0X4E8D, 0XAD, 0X5D, 0X92, 0X49, 0X83, 0X2B, 0X2E, 0XCA);

        public static readonly Guid SENSOR_TYPE_BARCODE_SCANNER__scanned__ = new Guid(0X990B3D8F, 0X85BB, 0X45FF, 0X91, 0X4D, 0X99, 0X8C, 0X04, 0XF3, 0X72, 0XDF);

        public static readonly Guid SENSOR_TYPE_CUSTOM__scanned__ = new Guid(0XE83AF229, 0X8640, 0X4D18, 0XA2, 0X13, 0XE2, 0X26, 0X75, 0XEB, 0XB2, 0XC3);

        public static readonly Guid SENSOR_TYPE_UNKNOWN__scanned__ = new Guid(0X10BA83E3, 0XEF4F, 0X41ED, 0X98, 0X85, 0XA8, 0X7D, 0X64, 0X35, 0XA8, 0XE1);

        public static readonly Guid SENSOR_DATA_TYPE_COMMON_GUID__scanned__ = new Guid(0XDB5E0CF2, 0XCF1F, 0X4C18, 0XB4, 0X6C, 0XD8, 0X60, 0X11, 0XD6, 0X21, 0X50);

        public static readonly Guid SENSOR_DATA_TYPE_LOCATION_GUID__scanned__ = new Guid(0X055C74D8, 0XCA6F, 0X47D6, 0X95, 0XC6, 0X1E, 0XD3, 0X63, 0X7A, 0X0F, 0XF4);

        public static readonly Guid SENSOR_DATA_TYPE_ENVIRONMENTAL_GUID__scanned__ = new Guid(0X8B0AA2F1, 0X2D57, 0X42EE, 0X8C, 0XC0, 0X4D, 0X27, 0X62, 0X2B, 0X46, 0XC4);

        public static readonly Guid SENSOR_DATA_TYPE_MOTION_GUID__scanned__ = new Guid(0X3F8A69A2, 0X7C5, 0X4E48, 0XA9, 0X65, 0XCD, 0X79, 0X7A, 0XAB, 0X56, 0XD5);

        public static readonly Guid SENSOR_DATA_TYPE_ORIENTATION_GUID__scanned__ = new Guid(0X1637D8A2, 0X4248, 0X4275, 0X86, 0X5D, 0X55, 0X8D, 0XE8, 0X4A, 0XED, 0XFD);

        public static readonly Guid SENSOR_DATA_TYPE_GUID_MECHANICAL_GUID__scanned__ = new Guid(0X38564A7C, 0XF2F2, 0X49BB, 0X9B, 0X2B, 0XBA, 0X60, 0XF6, 0X6A, 0X58, 0XDF);

        public static readonly Guid SENSOR_DATA_TYPE_BIOMETRIC_GUID__scanned__ = new Guid(0X2299288A,    0X6D9E, 0X4B0B, 0XB7, 0XEC, 0X35, 0X28, 0XF8, 0X9E, 0X40, 0XAF);

        public static readonly Guid SENSOR_DATA_TYPE_LIGHT_GUID__scanned__ = new Guid(0XE4C77CE2, 0XDCB7, 0X46E9, 0X84, 0X39, 0X4F, 0XEC, 0X54, 0X88, 0X33, 0XA6);

        public static readonly Guid SENSOR_DATA_TYPE_SCANNER_GUID__scanned__ = new Guid(0XD7A59A3C, 0X3421, 0X44AB, 0X8D, 0X3A, 0X9D, 0XE8, 0XAB, 0X6C, 0X4C, 0XAE);

        public static readonly Guid SENSOR_DATA_TYPE_ELECTRICAL_GUID__scanned__ = new Guid(0XBBB246D1, 0XE242, 0X4780, 0XA2, 0XD3, 0XCD, 0XED, 0X84, 0XF3, 0X58, 0X42);

        public static readonly Guid SENSOR_DATA_TYPE_CUSTOM_GUID__scanned__ = new Guid(0XB14C764F, 0X7CF, 0X41E8, 0X9D, 0X82, 0XEB, 0XE3, 0XD0, 0X77, 0X6A, 0X6F);

        public static readonly Guid SENSOR_PROPERTY_TEST_GUID__scanned__ = new Guid(0XE1E962F4, 0X6E65, 0X45F7, 0X9C, 0X36, 0XD4, 0X87, 0XB7, 0XB1, 0XBD, 0X34);

        public const uint GNSS_CLEAR_ALL_ASSISTANCE_DATA = 0x00000001;

    }
}

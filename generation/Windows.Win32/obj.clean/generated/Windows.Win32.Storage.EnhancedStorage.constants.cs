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


namespace Windows.Win32.Storage.EnhancedStorage
{
    public static partial class Apis
    {
        public static readonly Guid GUID_DEVINTERFACE_ENHANCED_STORAGE_SILO__scanned__ = new Guid(0x3897f6a4, 0xfd35, 0x4bc8, 0xa0, 0xb7, 0x5d, 0xbb, 0xa3, 0x6a, 0xda, 0xfa);

        public static readonly Guid WPD_CATEGORY_ENHANCED_STORAGE__scanned__ = new Guid(0x91248166, 0xb832, 0x4ad4, 0xba, 0xa4, 0x7c, 0xa0, 0xb6, 0xb2, 0x79, 0x8c);

        public const uint ENHANCED_STORAGE_AUTHN_STATE_UNKNOWN = 0x00000000;

        public const uint ENHANCED_STORAGE_AUTHN_STATE_NO_AUTHENTICATION_REQUIRED = 0x00000001;

        public const uint ENHANCED_STORAGE_AUTHN_STATE_NOT_AUTHENTICATED = 0x00000002;

        public const uint ENHANCED_STORAGE_AUTHN_STATE_AUTHENTICATED = 0x00000003;

        public const uint ENHANCED_STORAGE_AUTHN_STATE_AUTHENTICATION_DENIED = 0x80000001;

        public const uint ENHANCED_STORAGE_AUTHN_STATE_DEVICE_ERROR = 0x80000002;

        public const uint CERT_TYPE_EMPTY = 0x00;

        public const uint CERT_TYPE_ASCm = 0x01;

        public const uint CERT_TYPE_PCp = 0x02;

        public const uint CERT_TYPE_ASCh = 0x03;

        public const uint CERT_TYPE_HCh = 0x04;

        public const uint CERT_TYPE_SIGNER = 0x06;

        public const uint CERT_VALIDATION_POLICY_RESERVED = 0x00;

        public const uint CERT_VALIDATION_POLICY_NONE = 0x01;

        public const uint CERT_VALIDATION_POLICY_BASIC = 0x02;

        public const uint CERT_VALIDATION_POLICY_EXTENDED = 0x03;

        public const uint CERT_CAPABILITY_HASH_ALG = 0x1;

        public const uint CERT_CAPABILITY_ASYMMETRIC_KEY_CRYPTOGRAPHY = 0x2;

        public const uint CERT_CAPABILITY_SIGNATURE_ALG = 0x3;

        public const uint CERT_CAPABILITY_CERTIFICATE_SUPPORT = 0x4;

        public const uint CERT_CAPABILITY_OPTIONAL_FEATURES = 0x5;

        public const uint CERT_MAX_CAPABILITY = 0xFF;

        public const uint AUDIO_CHANNELCOUNT_MONO = 1;

        public const uint AUDIO_CHANNELCOUNT_STEREO = 2;

        public const uint CREATOROPENWITHUIOPTION_HIDDEN = 0;

        public const uint CREATOROPENWITHUIOPTION_VISIBLE = 1;

        public const uint ISDEFAULTSAVE_NONE = 0;

        public const uint ISDEFAULTSAVE_OWNER = 1;

        public const uint ISDEFAULTSAVE_NONOWNER = 2;

        public const uint ISDEFAULTSAVE_BOTH = 3;

        public const uint FILEOFFLINEAVAILABILITYSTATUS_NOTAVAILABLEOFFLINE = 0;

        public const uint FILEOFFLINEAVAILABILITYSTATUS_PARTIAL = 1;

        public const uint FILEOFFLINEAVAILABILITYSTATUS_COMPLETE = 2;

        public const uint FILEOFFLINEAVAILABILITYSTATUS_COMPLETE_PINNED = 3;

        public const uint FILEOFFLINEAVAILABILITYSTATUS_EXCLUDED = 4;

        public const uint FILEOFFLINEAVAILABILITYSTATUS_FOLDER_EMPTY = 5;

        public const int FLAGSTATUS_NOTFLAGGED = 0;

        public const int FLAGSTATUS_COMPLETED = 1;

        public const int FLAGSTATUS_FOLLOWUP = 2;

        public const int IMPORTANCE_LOW_MIN = 0;

        public const int IMPORTANCE_LOW_SET = 1;

        public const int IMPORTANCE_LOW_MAX = 1;

        public const int IMPORTANCE_NORMAL_MIN = 2;

        public const int IMPORTANCE_NORMAL_SET = 3;

        public const int IMPORTANCE_NORMAL_MAX = 4;

        public const int IMPORTANCE_HIGH_MIN = 5;

        public const int IMPORTANCE_HIGH_SET = 5;

        public const int IMPORTANCE_HIGH_MAX = 5;

        public const uint OFFLINEAVAILABILITY_NOT_AVAILABLE = 0;

        public const uint OFFLINEAVAILABILITY_AVAILABLE = 1;

        public const uint OFFLINEAVAILABILITY_ALWAYS_AVAILABLE = 2;

        public const uint OFFLINESTATUS_ONLINE = 0;

        public const uint OFFLINESTATUS_OFFLINE = 1;

        public const uint OFFLINESTATUS_OFFLINE_FORCED = 2;

        public const uint OFFLINESTATUS_OFFLINE_SLOW = 3;

        public const uint OFFLINESTATUS_OFFLINE_ERROR = 4;

        public const uint OFFLINESTATUS_OFFLINE_ITEM_VERSION_CONFLICT = 5;

        public const uint OFFLINESTATUS_OFFLINE_SUSPENDED = 6;

        public const uint RATING_ONE_STAR_MIN = 1;

        public const uint RATING_ONE_STAR_SET = 1;

        public const uint RATING_ONE_STAR_MAX = 12;

        public const uint RATING_TWO_STARS_MIN = 13;

        public const uint RATING_TWO_STARS_SET = 25;

        public const uint RATING_TWO_STARS_MAX = 37;

        public const uint RATING_THREE_STARS_MIN = 38;

        public const uint RATING_THREE_STARS_SET = 50;

        public const uint RATING_THREE_STARS_MAX = 62;

        public const uint RATING_FOUR_STARS_MIN = 63;

        public const uint RATING_FOUR_STARS_SET = 75;

        public const uint RATING_FOUR_STARS_MAX = 87;

        public const uint RATING_FIVE_STARS_MIN = 88;

        public const uint RATING_FIVE_STARS_SET = 99;

        public const uint RATING_FIVE_STARS_MAX = 99;

        public const uint SHARINGSTATUS_NOTSHARED = 0;

        public const uint SHARINGSTATUS_SHARED = 1;

        public const uint SHARINGSTATUS_PRIVATE = 2;

        public const uint STORAGE_PROVIDER_SHARINGSTATUS_NOTSHARED = 0;

        public const uint STORAGE_PROVIDER_SHARINGSTATUS_SHARED = 1;

        public const uint STORAGE_PROVIDER_SHARINGSTATUS_PRIVATE = 2;

        public const uint STORAGE_PROVIDER_SHARINGSTATUS_PUBLIC = 3;

        public const uint STORAGE_PROVIDER_SHARINGSTATUS_SHARED_OWNED = 4;

        public const uint STORAGE_PROVIDER_SHARINGSTATUS_SHARED_COOWNED = 5;

        public const uint STORAGE_PROVIDER_SHARINGSTATUS_PUBLIC_OWNED = 6;

        public const uint STORAGE_PROVIDER_SHARINGSTATUS_PUBLIC_COOWNED = 7;

        public const uint BLUETOOTH_ADDRESS_TYPE_PUBLIC = 0;

        public const uint BLUETOOTH_ADDRESS_TYPE_RANDOM = 1;

        public const uint BLUETOOTH_CACHE_MODE_CACHED = 0;

        public const uint BLUETOOTH_CACHED_MODE_UNCACHED = 1;

        public const uint PLAYBACKSTATE_UNKNOWN = 0;

        public const uint PLAYBACKSTATE_STOPPED = 1;

        public const uint PLAYBACKSTATE_PLAYING = 2;

        public const uint PLAYBACKSTATE_TRANSITIONING = 3;

        public const uint PLAYBACKSTATE_PAUSED = 4;

        public const uint PLAYBACKSTATE_RECORDINGPAUSED = 5;

        public const uint PLAYBACKSTATE_RECORDING = 6;

        public const uint PLAYBACKSTATE_NOMEDIA = 7;

        public const int LINK_STATUS_RESOLVED = 1;

        public const int LINK_STATUS_BROKEN = 2;

        public const uint PHOTO_CONTRAST_NORMAL = 0;

        public const uint PHOTO_CONTRAST_SOFT = 1;

        public const uint PHOTO_CONTRAST_HARD = 2;

        public const uint PHOTO_EXPOSUREPROGRAM_UNKNOWN = 0;

        public const uint PHOTO_EXPOSUREPROGRAM_MANUAL = 1;

        public const uint PHOTO_EXPOSUREPROGRAM_NORMAL = 2;

        public const uint PHOTO_EXPOSUREPROGRAM_APERTURE = 3;

        public const uint PHOTO_EXPOSUREPROGRAM_SHUTTER = 4;

        public const uint PHOTO_EXPOSUREPROGRAM_CREATIVE = 5;

        public const uint PHOTO_EXPOSUREPROGRAM_ACTION = 6;

        public const uint PHOTO_EXPOSUREPROGRAM_PORTRAIT = 7;

        public const uint PHOTO_EXPOSUREPROGRAM_LANDSCAPE = 8;

        public const uint PHOTO_FLASH_NONE = 0;

        public const uint PHOTO_FLASH_FLASH = 1;

        public const uint PHOTO_FLASH_WITHOUTSTROBE = 5;

        public const uint PHOTO_FLASH_WITHSTROBE = 7;

        public const uint PHOTO_FLASH_FLASH_COMPULSORY = 9;

        public const uint PHOTO_FLASH_FLASH_COMPULSORY_NORETURNLIGHT = 13;

        public const uint PHOTO_FLASH_FLASH_COMPULSORY_RETURNLIGHT = 15;

        public const uint PHOTO_FLASH_NONE_COMPULSORY = 16;

        public const uint PHOTO_FLASH_NONE_AUTO = 24;

        public const uint PHOTO_FLASH_FLASH_AUTO = 25;

        public const uint PHOTO_FLASH_FLASH_AUTO_NORETURNLIGHT = 29;

        public const uint PHOTO_FLASH_FLASH_AUTO_RETURNLIGHT = 31;

        public const uint PHOTO_FLASH_NOFUNCTION = 32;

        public const uint PHOTO_FLASH_FLASH_REDEYE = 65;

        public const uint PHOTO_FLASH_FLASH_REDEYE_NORETURNLIGHT = 69;

        public const uint PHOTO_FLASH_FLASH_REDEYE_RETURNLIGHT = 71;

        public const uint PHOTO_FLASH_FLASH_COMPULSORY_REDEYE = 73;

        public const uint PHOTO_FLASH_FLASH_COMPULSORY_REDEYE_NORETURNLIGHT = 77;

        public const uint PHOTO_FLASH_FLASH_COMPULSORY_REDEYE_RETURNLIGHT = 79;

        public const uint PHOTO_FLASH_FLASH_AUTO_REDEYE = 89;

        public const uint PHOTO_FLASH_FLASH_AUTO_REDEYE_NORETURNLIGHT = 93;

        public const uint PHOTO_FLASH_FLASH_AUTO_REDEYE_RETURNLIGHT = 95;

        public const double PHOTO_GAINCONTROL_NONE = 0.0;

        public const double PHOTO_GAINCONTROL_LOWGAINUP = 1.0;

        public const double PHOTO_GAINCONTROL_HIGHGAINUP = 2.0;

        public const double PHOTO_GAINCONTROL_LOWGAINDOWN = 3.0;

        public const double PHOTO_GAINCONTROL_HIGHGAINDOWN = 4.0;

        public const uint PHOTO_LIGHTSOURCE_UNKNOWN = 0;

        public const uint PHOTO_LIGHTSOURCE_DAYLIGHT = 1;

        public const uint PHOTO_LIGHTSOURCE_FLUORESCENT = 2;

        public const uint PHOTO_LIGHTSOURCE_TUNGSTEN = 3;

        public const uint PHOTO_LIGHTSOURCE_STANDARD_A = 17;

        public const uint PHOTO_LIGHTSOURCE_STANDARD_B = 18;

        public const uint PHOTO_LIGHTSOURCE_STANDARD_C = 19;

        public const uint PHOTO_LIGHTSOURCE_D55 = 20;

        public const uint PHOTO_LIGHTSOURCE_D65 = 21;

        public const uint PHOTO_LIGHTSOURCE_D75 = 22;

        public const uint PHOTO_PROGRAMMODE_NOTDEFINED = 0;

        public const uint PHOTO_PROGRAMMODE_MANUAL = 1;

        public const uint PHOTO_PROGRAMMODE_NORMAL = 2;

        public const uint PHOTO_PROGRAMMODE_APERTURE = 3;

        public const uint PHOTO_PROGRAMMODE_SHUTTER = 4;

        public const uint PHOTO_PROGRAMMODE_CREATIVE = 5;

        public const uint PHOTO_PROGRAMMODE_ACTION = 6;

        public const uint PHOTO_PROGRAMMODE_PORTRAIT = 7;

        public const uint PHOTO_PROGRAMMODE_LANDSCAPE = 8;

        public const uint PHOTO_SATURATION_NORMAL = 0;

        public const uint PHOTO_SATURATION_LOW = 1;

        public const uint PHOTO_SATURATION_HIGH = 2;

        public const uint PHOTO_SHARPNESS_NORMAL = 0;

        public const uint PHOTO_SHARPNESS_SOFT = 1;

        public const uint PHOTO_SHARPNESS_HARD = 2;

        public const uint PHOTO_WHITEBALANCE_AUTO = 0;

        public const uint PHOTO_WHITEBALANCE_MANUAL = 1;

        public const uint APPUSERMODEL_STARTPINOPTION_DEFAULT = 0;

        public const uint APPUSERMODEL_STARTPINOPTION_NOPINONINSTALL = 1;

        public const uint APPUSERMODEL_STARTPINOPTION_USERPINNED = 2;

        public const uint SYNC_HANDLERTYPE_OTHER = 0;

        public const uint SYNC_HANDLERTYPE_PROGRAMS = 1;

        public const uint SYNC_HANDLERTYPE_DEVICES = 2;

        public const uint SYNC_HANDLERTYPE_FOLDERS = 3;

        public const uint SYNC_HANDLERTYPE_WEBSERVICES = 4;

        public const uint SYNC_HANDLERTYPE_COMPUTERS = 5;

        public const uint SYNC_STATE_NOTSETUP = 0;

        public const uint SYNC_STATE_SYNCNOTRUN = 1;

        public const uint SYNC_STATE_IDLE = 2;

        public const uint SYNC_STATE_ERROR = 3;

        public const uint SYNC_STATE_PENDING = 4;

        public const uint SYNC_STATE_SYNCING = 5;

        public const uint ACT_AUTHORIZE_ON_RESUME = 0x00000001;

        public const uint ACT_AUTHORIZE_ON_SESSION_UNLOCK = 0x00000002;

        public const uint ACT_UNAUTHORIZE_ON_SUSPEND = 0x00000001;

        public const uint ACT_UNAUTHORIZE_ON_SESSION_LOCK = 0x00000002;

    }
}

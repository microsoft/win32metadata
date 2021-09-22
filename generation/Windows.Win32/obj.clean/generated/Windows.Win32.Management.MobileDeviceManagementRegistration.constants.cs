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


namespace Windows.Win32.Management.MobileDeviceManagementRegistration
{
    public static partial class Apis
    {
        public const uint MDM_REGISTRATION_FACILITY_CODE = 25;

        public const uint DEVICE_ENROLLER_FACILITY_CODE = 24;

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DEVICE_MESSAGE_FORMAT_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(1));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICE_MESSAGE_FORMAT_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(1));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DEVICE_AUTHENTICATION_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(2));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICE_AUTHENTICATION_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(2));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DEVICE_AUTHORIZATION_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(3));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICE_AUTHORIZATION_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(3));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DEVICE_CERTIFCATEREQUEST_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(4));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICE_CERTIFCATEREQUEST_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(4));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DEVICE_CONFIGMGRSERVER_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(5));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICE_CONFIGMGRSERVER_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(5));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DEVICE_INTERNALSERVICE_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(6));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICE_INTERNALSERVICE_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(6));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DEVICE_INVALIDSECURITY_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(7));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICE_INVALIDSECURITY_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(7));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DEVICE_UNKNOWN_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(8));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICE_UNKNOWN_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(8));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_REGISTRATION_IN_PROGRESS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(9));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_ENROLLMENT_IN_PROGRESS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(9));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DEVICE_ALREADY_REGISTERED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(10));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICE_ALREADY_ENROLLED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(10));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DEVICE_NOT_REGISTERED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(11));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICE_NOT_ENROLLED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(11));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DISCOVERY_REDIRECTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(12));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DEVICE_NOT_AD_REGISTERED_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(13));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DISCOVERY_SEC_CERT_DATE_INVALID = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(13));

        [NativeTypeName("HRESULT")]
        public const int MREGISTER_E_DISCOVERY_FAILED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(MDM_REGISTRATION_FACILITY_CODE)) << 16) | (int)(14));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PASSWORD_NEEDED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(14));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_WAB_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(15));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_CONNECTIVITY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(16));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_S_ENROLLMENT_SUSPENDED = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(17));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_INVALIDSSLCERT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(18));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICECAPREACHED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(19));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICENOTSUPPORTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(20));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_NOTSUPPORTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(21));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_NOTELIGIBLETORENEW = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(22));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_INMAINTENANCE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(23));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_USERLICENSE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(24));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_ENROLLMENTDATAINVALID = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(25));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_INSECUREREDIRECT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(26));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PLATFORM_WRONG_STATE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(27));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PLATFORM_LICENSE_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(28));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PLATFORM_UNKNOWN_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(29));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PROV_CSP_CERTSTORE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(30));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PROV_CSP_W7 = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(31));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PROV_CSP_DMCLIENT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(32));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PROV_CSP_PFW = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(33));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PROV_CSP_MISC = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(34));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PROV_UNKNOWN = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(35));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PROV_SSLCERTNOTFOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(36));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_PROV_CSP_APPMGMT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(37));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_DEVICE_MANAGEMENT_BLOCKED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(38));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_CERTPOLICY_PRIVATEKEYCREATION_FAILED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(39));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_CERTAUTH_FAILED_TO_FIND_CERT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(40));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_EMPTY_MESSAGE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(41));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_USER_CANCELED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(42));

        [NativeTypeName("HRESULT")]
        public const int MENROLL_E_MDM_NOT_CONFIGURED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(DEVICE_ENROLLER_FACILITY_CODE)) << 16) | (int)(43));

        public const uint DEVICEREGISTRATIONTYPE_MDM_ONLY = 0;

        public const uint DEVICEREGISTRATIONTYPE_MAM = 5;

        public const uint DEVICEREGISTRATIONTYPE_MDM_DEVICEWIDE_WITH_AAD = 6;

        public const uint DEVICEREGISTRATIONTYPE_MDM_USERSPECIFIC_WITH_AAD = 13;

    }
}

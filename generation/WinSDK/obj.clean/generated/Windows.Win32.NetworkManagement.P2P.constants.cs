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


namespace Windows.Win32.NetworkManagement.P2P
{
    public static partial class Apis
    {
        public const uint NS_PNRPNAME = 38;

        public const uint NS_PNRPCLOUD = 39;

        public const uint PNRPINFO_HINT = 0x00000001;

        public static readonly Guid NS_PROVIDER_PNRPNAME__scanned__ = new Guid(0x03fe89cd, 0x766d, 0x4976, 0xb9, 0xc1, 0xbb, 0x9b, 0xc4, 0x2c, 0x7b, 0x4d);

        public static readonly Guid NS_PROVIDER_PNRPCLOUD__scanned__ = new Guid(0x03fe89ce, 0x766d, 0x4976, 0xb9, 0xc1, 0xbb, 0x9b, 0xc4, 0x2c, 0x7b, 0x4d);

        public static readonly Guid SVCID_PNRPCLOUD__scanned__ = new Guid(0xc2239ce6, 0x00c0, 0x4fbf, 0xba, 0xd6, 0x18, 0x13, 0x93, 0x85, 0xa4, 0x9a);

        public static readonly Guid SVCID_PNRPNAME_V1__scanned__ = new Guid(0xc2239ce5, 0x00c0, 0x4fbf, 0xba, 0xd6, 0x18, 0x13, 0x93, 0x85, 0xa4, 0x9a);

        public static readonly Guid SVCID_PNRPNAME_V2__scanned__ = new Guid(0xc2239ce7, 0x00c0, 0x4fbf, 0xba, 0xd6, 0x18, 0x13, 0x93, 0x85, 0xa4, 0x9a);

        public const uint PNRP_MAX_ENDPOINT_ADDRESSES = 10;

        public const uint PNRP_MAX_EXTENDED_PAYLOAD_BYTES = 0x1000;

        public const uint WSA_PNRP_ERROR_BASE = 11500;

        public const uint WSA_PNRP_CLOUD_NOT_FOUND = WSA_PNRP_ERROR_BASE +  1;

        public const uint WSA_PNRP_CLOUD_DISABLED = WSA_PNRP_ERROR_BASE +  2;

        public const uint WSA_PNRP_INVALID_IDENTITY = WSA_PNRP_ERROR_BASE +  3;

        public const uint WSA_PNRP_TOO_MUCH_LOAD = WSA_PNRP_ERROR_BASE +  4;

        public const uint WSA_PNRP_CLOUD_IS_SEARCH_ONLY = WSA_PNRP_ERROR_BASE +  5;

        public const uint WSA_PNRP_CLIENT_INVALID_COMPARTMENT_ID = WSA_PNRP_ERROR_BASE +  6;

        public const uint WSA_PNRP_DUPLICATE_PEER_NAME = WSA_PNRP_ERROR_BASE +  8;

        public const uint WSA_PNRP_CLOUD_IS_DEAD = WSA_PNRP_ERROR_BASE + 9;

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CLOUD_NOT_FOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(WSA_PNRP_CLOUD_NOT_FOUND));

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CLOUD_DISABLED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(WSA_PNRP_CLOUD_DISABLED));

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_IDENTITY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(WSA_PNRP_INVALID_IDENTITY));

        [NativeTypeName("HRESULT")]
        public const int PEER_E_TOO_MUCH_LOAD = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(WSA_PNRP_TOO_MUCH_LOAD));

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CLOUD_IS_SEARCH_ONLY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(WSA_PNRP_CLOUD_IS_SEARCH_ONLY));

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CLIENT_INVALID_COMPARTMENT_ID = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(WSA_PNRP_CLIENT_INVALID_COMPARTMENT_ID));

        [NativeTypeName("HRESULT")]
        public const int PEER_E_DUPLICATE_PEER_NAME = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(WSA_PNRP_DUPLICATE_PEER_NAME));

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CLOUD_IS_DEAD = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(WSA_PNRP_CLOUD_IS_DEAD));

        [NativeTypeName("HRESULT")]
        public const int PEER_E_NOT_FOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_NOT_FOUND));

        [NativeTypeName("HRESULT")]
        public const int PEER_E_DISK_FULL = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_DISK_FULL));

        [NativeTypeName("HRESULT")]
        public const int PEER_E_ALREADY_EXISTS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_ALREADY_EXISTS));

        public static readonly Guid PEER_GROUP_ROLE_ADMIN__scanned__ = new Guid(0x04387127, 0xaa56, 0x450a, 0x8c, 0xe5, 0x4f, 0x56, 0x5c, 0x67, 0x90, 0xf4);

        public static readonly Guid PEER_GROUP_ROLE_MEMBER__scanned__ = new Guid(0xf12dc4c7, 0x0857, 0x4ca0, 0x93, 0xfc, 0xb1, 0xbb, 0x19, 0xa3, 0xd8, 0xc2);

        public static readonly Guid PEER_GROUP_ROLE_INVITING_MEMBER__scanned__ = new Guid(0x4370fd89, 0xdc18, 0x4cfb, 0x8d, 0xbf, 0x98, 0x53, 0xa8, 0xa9, 0xf9, 0x05);

        public static readonly Guid PEER_COLLAB_OBJECTID_USER_PICTURE__scanned__ = new Guid(0xdd15f41f, 0xfc4e, 0x4922, 0xb0, 0x35, 0x4c, 0x06, 0xa7, 0x54, 0xd0, 0x1d);

        public const uint FACILITY_DRT = 98;

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TIMEOUT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x1001));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_KEY_SIZE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x1002));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_CERT_CHAIN = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x1004));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_MESSAGE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x1005));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_NO_MORE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x1006));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_MAX_ADDRESSES = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x1007));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_SEARCH_IN_PROGRESS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x1008));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_KEY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x1009));

        [NativeTypeName("HRESULT")]
        public const int DRT_S_RETRY = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x1010));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_MAX_ENDPOINTS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x1011));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_SEARCH_RANGE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x1012));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_PORT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2000));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_TRANSPORT_PROVIDER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2001));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_SECURITY_PROVIDER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2002));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_STILL_IN_USE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2003));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_BOOTSTRAP_PROVIDER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2004));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_ADDRESS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2005));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_SCOPE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2006));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TRANSPORT_SHUTTING_DOWN = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2007));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_NO_ADDRESSES_AVAILABLE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2008));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_DUPLICATE_KEY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2009));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TRANSPORTPROVIDER_IN_USE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x200a));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TRANSPORTPROVIDER_NOT_ATTACHED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x200b));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_SECURITYPROVIDER_IN_USE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x200c));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_SECURITYPROVIDER_NOT_ATTACHED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x200d));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_BOOTSTRAPPROVIDER_IN_USE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x200e));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_BOOTSTRAPPROVIDER_NOT_ATTACHED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x200f));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TRANSPORT_ALREADY_BOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2101));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TRANSPORT_NOT_BOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2102));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TRANSPORT_UNEXPECTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2103));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TRANSPORT_INVALID_ARGUMENT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2104));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TRANSPORT_NO_DEST_ADDRESSES = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2105));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TRANSPORT_EXECUTING_CALLBACK = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2106));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TRANSPORT_ALREADY_EXISTS_FOR_SCOPE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2107));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_SETTINGS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2108));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_SEARCH_INFO = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x2109));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_FAULTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x210a));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_TRANSPORT_STILL_BOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x210b));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INSUFFICIENT_BUFFER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x210c));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_INSTANCE_PREFIX = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x210d));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_INVALID_SECURITY_MODE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x210e));

        [NativeTypeName("HRESULT")]
        public const int DRT_E_CAPABILITY_MISMATCH = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_DRT)) << 16) | (int)(0x210f));

        public const uint DRT_PAYLOAD_REVOKED = 1u<<0;

        public const uint DRT_MIN_ROUTING_ADDRESSES = 1;

        public const uint DRT_MAX_ROUTING_ADDRESSES = 20;

        public const uint DRT_MAX_PAYLOAD_SIZE = 5120;

        public const uint DRT_MAX_INSTANCE_PREFIX_LEN = 128;

        public const uint DRT_LINK_LOCAL_ISATAP_SCOPEID = 0xffffffff;

        public const int PEERDIST_PUBLICATION_OPTIONS_VERSION_1 = 1;

        public const uint PEERDIST_READ_TIMEOUT_LOCAL_CACHE_ONLY = 0;

        public const uint PEERDIST_READ_TIMEOUT_DEFAULT = 0xfffffffe;

    }
}

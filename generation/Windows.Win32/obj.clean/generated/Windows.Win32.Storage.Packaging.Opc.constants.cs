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


namespace Windows.Win32.Storage.Packaging.Opc
{
    public static partial class Apis
    {
        [NativeTypeName("HRESULT")]
        public const int OPC_E_NONCONFORMING_URI = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_RELATIVE_URI_REQUIRED = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x2));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_RELATIONSHIP_URI_REQUIRED = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x3));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_PART_CANNOT_BE_DIRECTORY = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x4));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_UNEXPECTED_CONTENT_TYPE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x5));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_INVALID_CONTENT_TYPE_XML = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x6));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MISSING_CONTENT_TYPES = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x7));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_NONCONFORMING_CONTENT_TYPES_XML = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x8));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_NONCONFORMING_RELS_XML = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x9));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_INVALID_RELS_XML = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0xA));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DUPLICATE_PART = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0xB));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_INVALID_OVERRIDE_PART_NAME = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0xC));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DUPLICATE_OVERRIDE_PART = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0xD));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_INVALID_DEFAULT_EXTENSION = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0xE));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DUPLICATE_DEFAULT_EXTENSION = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0xF));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_INVALID_RELATIONSHIP_ID = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x10));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_INVALID_RELATIONSHIP_TYPE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x11));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_INVALID_RELATIONSHIP_TARGET = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x12));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DUPLICATE_RELATIONSHIP = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x13));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_CONFLICTING_SETTINGS = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x14));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DUPLICATE_PIECE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x15));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_INVALID_PIECE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x16));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MISSING_PIECE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x17));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_NO_SUCH_PART = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x18));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_SIGNATURE_CORRUPT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x19));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_DIGEST_VALUE_ERROR = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1A));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_DUPLICATE_SIGNATURE_ORIGIN_RELATIONSHIP = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1B));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_INVALID_SIGNATURE_ORIGIN_RELATIONSHIP = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1C));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_INVALID_CERTIFICATE_RELATIONSHIP = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1D));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_EXTERNAL_SIGNATURE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1E));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_MISSING_SIGNATURE_ORIGIN_PART = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1F));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_MISSING_SIGNATURE_PART = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x20));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_INVALID_RELATIONSHIP_TRANSFORM_XML = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x21));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_INVALID_CANONICALIZATION_METHOD = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x22));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_INVALID_RELATIONSHIPS_SIGNING_OPTION = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x23));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_INVALID_OPC_SIGNATURE_TIME_FORMAT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x24));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_PACKAGE_REFERENCE_URI_RESERVED = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x25));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_MISSING_SIGNATURE_PROPERTIES_ELEMENT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x26));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_MISSING_SIGNATURE_PROPERTY_ELEMENT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x27));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_DUPLICATE_SIGNATURE_PROPERTY_ELEMENT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x28));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_MISSING_SIGNATURE_TIME_PROPERTY = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x29));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_INVALID_SIGNATURE_XML = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x2A));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_INVALID_SIGNATURE_COUNT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x2B));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_MISSING_SIGNATURE_ALGORITHM = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x2C));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_DUPLICATE_PACKAGE_OBJECT_REFERENCES = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x2D));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_MISSING_PACKAGE_OBJECT_REFERENCE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x2E));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_EXTERNAL_SIGNATURE_REFERENCE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x2F));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_REFERENCE_MISSING_CONTENT_TYPE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x30));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_MULTIPLE_RELATIONSHIP_TRANSFORMS = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x31));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_MISSING_CANONICALIZATION_TRANSFORM = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x32));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_UNEXPECTED_ELEMENT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x33));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_UNEXPECTED_REQUIRES_ATTR = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x34));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_MISSING_REQUIRES_ATTR = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x35));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_UNEXPECTED_ATTR = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x36));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_INVALID_PREFIX_LIST = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x37));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_INVALID_QNAME_LIST = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x38));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_NESTED_ALTERNATE_CONTENT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x39));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_UNEXPECTED_CHOICE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x3A));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_MISSING_CHOICE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x3B));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_INVALID_ENUM_TYPE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x3C));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_UNKNOWN_NAMESPACE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x3E));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_UNKNOWN_PREFIX = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x3F));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_INVALID_ATTRIBUTES_ON_IGNORABLE_ELEMENT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x40));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_INVALID_XMLNS_ATTRIBUTE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x41));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_INVALID_XML_ENCODING = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x42));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_SIGNATURE_REFERENCE_MISSING_URI = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x43));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_INVALID_CONTENT_TYPE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x44));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_SIGNATURE_PROPERTY_MISSING_TARGET = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x45));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_SIGNATURE_METHOD_NOT_SET = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x46));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_DEFAULT_DIGEST_METHOD_NOT_SET = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x47));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_NO_SUCH_RELATIONSHIP = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x48));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_MULTIPLE_FALLBACK_ELEMENTS = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x49));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_INCONSISTENT_PROCESS_CONTENT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x4A));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_INCONSISTENT_PRESERVE_ATTRIBUTES = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x4B));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_MC_INCONSISTENT_PRESERVE_ELEMENTS = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x4C));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_INVALID_RELATIONSHIP_TARGET_MODE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x4D));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_COULD_NOT_RECOVER = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x4E));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_UNSUPPORTED_PACKAGE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x4F));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ENUM_COLLECTION_CHANGED = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x50));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ENUM_CANNOT_MOVE_NEXT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x51));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ENUM_CANNOT_MOVE_PREVIOUS = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x52));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ENUM_INVALID_POSITION = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x53));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_SIGNATURE_ORIGIN_EXISTS = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x54));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_UNSIGNED_PACKAGE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x55));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_DS_MISSING_CERTIFICATE_PART = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x56));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_NO_SUCH_SETTINGS = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x57));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_INCORRECT_DATA_SIZE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1001));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_CORRUPTED_ARCHIVE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1002));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_COMPRESSION_FAILED = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1003));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_DECOMPRESSION_FAILED = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1004));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_INCONSISTENT_FILEITEM = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1005));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_INCONSISTENT_DIRECTORY = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1006));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_MISSING_DATA_DESCRIPTOR = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1007));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_UNSUPPORTEDARCHIVE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1008));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_CENTRAL_DIRECTORY_TOO_LARGE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1009));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_NAME_TOO_LARGE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x100A));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_DUPLICATE_NAME = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x100B));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_COMMENT_TOO_LARGE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x100C));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_EXTRA_FIELDS_TOO_LARGE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x100D));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_FILE_HEADER_TOO_LARGE = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x100E));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_MISSING_END_OF_CENTRAL_DIRECTORY = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x100F));

        [NativeTypeName("HRESULT")]
        public const int OPC_E_ZIP_REQUIRES_64_BIT = unchecked((int)((1) << 31) | (((int)(FACILITY_OPC)) << 16) | (int)(0x1010));

    }
}

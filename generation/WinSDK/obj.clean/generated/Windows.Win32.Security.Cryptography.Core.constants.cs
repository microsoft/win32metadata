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


namespace Windows.Win32.Security.Cryptography.Core
{
    public static partial class Apis
    {
        public const uint BCRYPT_OBJECT_ALIGNMENT = 16;

        public const uint KDF_HASH_ALGORITHM = 0x0;

        public const uint KDF_SECRET_PREPEND = 0x1;

        public const uint KDF_SECRET_APPEND = 0x2;

        public const uint KDF_HMAC_KEY = 0x3;

        public const uint KDF_TLS_PRF_LABEL = 0x4;

        public const uint KDF_TLS_PRF_SEED = 0x5;

        public const uint KDF_SECRET_HANDLE = 0x6;

        public const uint KDF_TLS_PRF_PROTOCOL = 0x7;

        public const uint KDF_ALGORITHMID = 0x8;

        public const uint KDF_PARTYUINFO = 0x9;

        public const uint KDF_PARTYVINFO = 0xA;

        public const uint KDF_SUPPPUBINFO = 0xB;

        public const uint KDF_SUPPPRIVINFO = 0xC;

        public const uint KDF_LABEL = 0xD;

        public const uint KDF_CONTEXT = 0xE;

        public const uint KDF_SALT = 0xF;

        public const uint KDF_ITERATION_COUNT = 0x10;

        public const uint KDF_GENERIC_PARAMETER = 0x11;

        public const uint KDF_KEYBITLENGTH = 0x12;

        public const uint KDF_HKDF_SALT = 0x13;

        public const uint KDF_HKDF_INFO = 0x14;

        public const uint KDF_USE_SECRET_AS_HMAC_KEY_FLAG = 0x1;

        public const uint BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO_VERSION = 1;

        public const uint BCRYPT_AUTH_MODE_CHAIN_CALLS_FLAG = 0x00000001;

        public const uint BCRYPT_AUTH_MODE_IN_PROGRESS_FLAG = 0x00000002;

        public const uint BCRYPT_SUPPORTED_PAD_ROUTER = 0x00000001;

        public const uint BCRYPT_SUPPORTED_PAD_PKCS1_ENC = 0x00000002;

        public const uint BCRYPT_SUPPORTED_PAD_PKCS1_SIG = 0x00000004;

        public const uint BCRYPT_SUPPORTED_PAD_OAEP = 0x00000008;

        public const uint BCRYPT_SUPPORTED_PAD_PSS = 0x00000010;

        public const uint BCRYPT_BLOCK_PADDING = 0x00000001;

        public const uint BCRYPT_PAD_PKCS1_OPTIONAL_HASH_OID = 0x00000010;

        public const uint BCRYPTBUFFER_VERSION = 0;

        public const uint BCRYPT_ECDH_PUBLIC_P256_MAGIC = 0x314B4345;

        public const uint BCRYPT_ECDH_PRIVATE_P256_MAGIC = 0x324B4345;

        public const uint BCRYPT_ECDH_PUBLIC_P384_MAGIC = 0x334B4345;

        public const uint BCRYPT_ECDH_PRIVATE_P384_MAGIC = 0x344B4345;

        public const uint BCRYPT_ECDH_PUBLIC_P521_MAGIC = 0x354B4345;

        public const uint BCRYPT_ECDH_PRIVATE_P521_MAGIC = 0x364B4345;

        public const uint BCRYPT_ECDH_PUBLIC_GENERIC_MAGIC = 0x504B4345;

        public const uint BCRYPT_ECDH_PRIVATE_GENERIC_MAGIC = 0x564B4345;

        public const uint BCRYPT_ECDSA_PUBLIC_P256_MAGIC = 0x31534345;

        public const uint BCRYPT_ECDSA_PRIVATE_P256_MAGIC = 0x32534345;

        public const uint BCRYPT_ECDSA_PUBLIC_P384_MAGIC = 0x33534345;

        public const uint BCRYPT_ECDSA_PRIVATE_P384_MAGIC = 0x34534345;

        public const uint BCRYPT_ECDSA_PUBLIC_P521_MAGIC = 0x35534345;

        public const uint BCRYPT_ECDSA_PRIVATE_P521_MAGIC = 0x36534345;

        public const uint BCRYPT_ECDSA_PUBLIC_GENERIC_MAGIC = 0x50444345;

        public const uint BCRYPT_ECDSA_PRIVATE_GENERIC_MAGIC = 0x56444345;

        public const uint BCRYPT_ECC_FULLKEY_BLOB_V1 = 0x1;

        public const uint BCRYPT_DH_PARAMETERS_MAGIC = 0x4d504844;

        public const uint BCRYPT_DSA_PUBLIC_MAGIC_V2 = 0x32425044;

        public const uint BCRYPT_DSA_PRIVATE_MAGIC_V2 = 0x32565044;

        public const uint BCRYPT_KEY_DATA_BLOB_MAGIC = 0x4d42444b;

        public const uint BCRYPT_KEY_DATA_BLOB_VERSION1 = 0x1;

        public const uint BCRYPT_DSA_PARAMETERS_MAGIC = 0x4d505344;

        public const uint BCRYPT_DSA_PARAMETERS_MAGIC_V2 = 0x324d5044;

        public const uint BCRYPT_ECC_PARAMETERS_MAGIC = 0x50434345;

        public const uint BCRYPT_KEY_DERIVATION_INTERFACE = 0x00000007;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_MD2_ALG_HANDLE = 0x00000001;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_MD4_ALG_HANDLE = 0x00000011;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_MD5_ALG_HANDLE = 0x00000021;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_SHA1_ALG_HANDLE = 0x00000031;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_SHA256_ALG_HANDLE = 0x00000041;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_SHA384_ALG_HANDLE = 0x00000051;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_SHA512_ALG_HANDLE = 0x00000061;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_RC4_ALG_HANDLE = 0x00000071;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_RNG_ALG_HANDLE = 0x00000081;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_HMAC_MD5_ALG_HANDLE = 0x00000091;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_HMAC_SHA1_ALG_HANDLE = 0x000000a1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_HMAC_SHA256_ALG_HANDLE = 0x000000b1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_HMAC_SHA384_ALG_HANDLE = 0x000000c1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_HMAC_SHA512_ALG_HANDLE = 0x000000d1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_RSA_ALG_HANDLE = 0x000000e1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_ECDSA_ALG_HANDLE = 0x000000f1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_AES_CMAC_ALG_HANDLE = 0x00000101;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_AES_GMAC_ALG_HANDLE = 0x00000111;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_HMAC_MD2_ALG_HANDLE = 0x00000121;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_HMAC_MD4_ALG_HANDLE = 0x00000131;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_3DES_CBC_ALG_HANDLE = 0x00000141;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_3DES_ECB_ALG_HANDLE = 0x00000151;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_3DES_CFB_ALG_HANDLE = 0x00000161;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_3DES_112_CBC_ALG_HANDLE = 0x00000171;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_3DES_112_ECB_ALG_HANDLE = 0x00000181;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_3DES_112_CFB_ALG_HANDLE = 0x00000191;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_AES_CBC_ALG_HANDLE = 0x000001a1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_AES_ECB_ALG_HANDLE = 0x000001b1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_AES_CFB_ALG_HANDLE = 0x000001c1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_AES_CCM_ALG_HANDLE = 0x000001d1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_AES_GCM_ALG_HANDLE = 0x000001e1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_DES_CBC_ALG_HANDLE = 0x000001f1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_DES_ECB_ALG_HANDLE = 0x00000201;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_DES_CFB_ALG_HANDLE = 0x00000211;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_DESX_CBC_ALG_HANDLE = 0x00000221;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_DESX_ECB_ALG_HANDLE = 0x00000231;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_DESX_CFB_ALG_HANDLE = 0x00000241;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_RC2_CBC_ALG_HANDLE = 0x00000251;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_RC2_ECB_ALG_HANDLE = 0x00000261;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_RC2_CFB_ALG_HANDLE = 0x00000271;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_DH_ALG_HANDLE = 0x00000281;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_ECDH_ALG_HANDLE = 0x00000291;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_ECDH_P256_ALG_HANDLE = 0x000002a1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_ECDH_P384_ALG_HANDLE = 0x000002b1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_ECDH_P521_ALG_HANDLE = 0x000002c1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_DSA_ALG_HANDLE = 0x000002d1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_ECDSA_P256_ALG_HANDLE = 0x000002e1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_ECDSA_P384_ALG_HANDLE = 0x000002f1;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_ECDSA_P521_ALG_HANDLE = 0x00000301;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_RSA_SIGN_ALG_HANDLE = 0x00000311;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_CAPI_KDF_ALG_HANDLE = 0x00000321;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_PBKDF2_ALG_HANDLE = 0x00000331;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_SP800108_CTR_HMAC_ALG_HANDLE = 0x00000341;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_SP80056A_CONCAT_ALG_HANDLE = 0x00000351;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_TLS1_1_KDF_ALG_HANDLE = 0x00000361;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_TLS1_2_KDF_ALG_HANDLE = 0x00000371;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_XTS_AES_ALG_HANDLE = 0x00000381;

        [NativeTypeName("BCRYPT_ALG_HANDLE")]
        public const uint BCRYPT_HKDF_ALG_HANDLE = 0x00000391;

        public const uint BCRYPT_CAPI_AES_FLAG = 0x00000010;

        public const uint BCRYPT_MULTI_FLAG = 0x00000040;

        public const uint BCRYPT_TLS_CBC_HMAC_VERIFY_FLAG = 0x00000004;

        public const uint BCRYPT_BUFFERS_LOCKED_FLAG = 0x00000040;

        public const uint BCRYPT_EXTENDED_KEYSIZE = 0x00000080;

        public const uint BCRYPT_ENABLE_INCOMPATIBLE_FIPS_CHECKS = 0x00000100;

        public const uint BCRYPT_KEY_DERIVATION_OPERATION = 0x00000040;

        public const uint BCRYPT_PUBLIC_KEY_FLAG = 0x00000001;

        public const uint BCRYPT_PRIVATE_KEY_FLAG = 0x00000002;

        public const uint BCRYPT_NO_KEY_VALIDATION = 0x00000008;

        public const uint BCRYPT_RNG_USE_ENTROPY_IN_BUFFER = 0x00000001;

        public const uint BCRYPT_USE_SYSTEM_PREFERRED_RNG = 0x00000002;

        public const uint BCRYPT_HASH_INTERFACE_MAJORVERSION_2 = 2;

        public const uint CRYPT_OVERWRITE = 0x00000001;

        public const uint CRYPT_PRIORITY_TOP = 0x00000000;

        public const uint CRYPT_PRIORITY_BOTTOM = 0xFFFFFFFF;

        public const uint CRYTPDLG_FLAGS_MASK = 0xff000000;

        public const uint CRYPTDLG_REVOCATION_DEFAULT = 0x00000000;

        public const uint CRYPTDLG_REVOCATION_ONLINE = 0x80000000;

        public const uint CRYPTDLG_REVOCATION_CACHE = 0x40000000;

        public const uint CRYPTDLG_REVOCATION_NONE = 0x20000000;

        public const uint CRYPTDLG_CACHE_ONLY_URL_RETRIEVAL = 0x10000000;

        public const uint CRYPTDLG_DISABLE_AIA = 0x08000000;

        public const uint CRYPTDLG_POLICY_MASK = 0x0000FFFF;

        public const uint POLICY_IGNORE_NON_CRITICAL_BC = 0x00000001;

        public const uint CRYPTDLG_ACTION_MASK = 0xFFFF0000;

        public const uint ACTION_REVOCATION_DEFAULT_ONLINE = 0x00010000;

        public const uint ACTION_REVOCATION_DEFAULT_CACHE = 0x00020000;

        public const uint CERT_DISPWELL_SELECT = 1;

        public const uint CERT_DISPWELL_TRUST_CA_CERT = 2;

        public const uint CERT_DISPWELL_TRUST_LEAF_CERT = 3;

        public const uint CERT_DISPWELL_TRUST_ADD_CA_CERT = 4;

        public const uint CERT_DISPWELL_TRUST_ADD_LEAF_CERT = 5;

        public const uint CERT_DISPWELL_DISTRUST_CA_CERT = 6;

        public const uint CERT_DISPWELL_DISTRUST_LEAF_CERT = 7;

        public const uint CERT_DISPWELL_DISTRUST_ADD_CA_CERT = 8;

        public const uint CERT_DISPWELL_DISTRUST_ADD_LEAF_CERT = 9;

        public const uint CSS_SELECTCERT_MASK = 0x00ffffff;

        public const uint SELCERT_PROPERTIES = 100;

        public const uint SELCERT_FINEPRINT = 101;

        public const uint SELCERT_CERTLIST = 102;

        public const uint SELCERT_ISSUED_TO = 103;

        public const uint SELCERT_VALIDITY = 104;

        public const uint SELCERT_ALGORITHM = 105;

        public const uint SELCERT_SERIAL_NUM = 106;

        public const uint SELCERT_THUMBPRINT = 107;

        public const uint CM_VIEWFLAGS_MASK = 0x00ffffff;

        public const uint CERTVIEW_CRYPTUI_LPARAM = 0x00800000;

        public const uint CERT_FILTER_OP_EXISTS = 1;

        public const uint CERT_FILTER_OP_NOT_EXISTS = 2;

        public const uint CERT_FILTER_OP_EQUALITY = 3;

        public const uint CERT_FILTER_INCLUDE_V1_CERTS = 0x0001;

        public const uint CERT_FILTER_VALID_TIME_RANGE = 0x0002;

        public const uint CERT_FILTER_VALID_SIGNATURE = 0x0004;

        public const uint CERT_FILTER_LEAF_CERTS_ONLY = 0x0008;

        public const uint CERT_FILTER_ISSUER_CERTS_ONLY = 0x0010;

        public const uint CERT_FILTER_KEY_EXISTS = 0x0020;

        public const uint CERT_VALIDITY_BEFORE_START = 0x00000001;

        public const uint CERT_VALIDITY_AFTER_END = 0x00000002;

        public const uint CERT_VALIDITY_SIGNATURE_FAILS = 0x00000004;

        public const uint CERT_VALIDITY_CERTIFICATE_REVOKED = 0x00000008;

        public const uint CERT_VALIDITY_KEY_USAGE_EXT_FAILURE = 0x00000010;

        public const uint CERT_VALIDITY_EXTENDED_USAGE_FAILURE = 0x00000020;

        public const uint CERT_VALIDITY_NAME_CONSTRAINTS_FAILURE = 0x00000040;

        public const uint CERT_VALIDITY_UNKNOWN_CRITICAL_EXTENSION = 0x00000080;

        public const uint CERT_VALIDITY_ISSUER_INVALID = 0x00000100;

        public const uint CERT_VALIDITY_OTHER_EXTENSION_FAILURE = 0x00000200;

        public const uint CERT_VALIDITY_PERIOD_NESTING_FAILURE = 0x00000400;

        public const uint CERT_VALIDITY_OTHER_ERROR = 0x00000800;

        public const uint CERT_VALIDITY_ISSUER_DISTRUST = 0x02000000;

        public const uint CERT_VALIDITY_EXPLICITLY_DISTRUSTED = 0x01000000;

        public const uint CERT_VALIDITY_NO_ISSUER_CERT_FOUND = 0x10000000;

        public const uint CERT_VALIDITY_NO_CRL_FOUND = 0x20000000;

        public const uint CERT_VALIDITY_CRL_OUT_OF_DATE = 0x40000000;

        public const uint CERT_VALIDITY_NO_TRUST_DATA = 0x80000000;

        public const uint CERT_VALIDITY_MASK_TRUST = 0xffff0000;

        public const uint CERT_VALIDITY_MASK_VALIDITY = 0x0000ffff;

        public const uint CERT_TRUST_MASK = 0x00ffffff;

        public const uint CERT_TRUST_DO_FULL_SEARCH = 0x00000001;

        public const uint CERT_TRUST_PERMIT_MISSING_CRLS = 0x00000002;

        public const uint CERT_TRUST_DO_FULL_TRUST = 0x00000005;

        public const int CERT_CREDENTIAL_PROVIDER_ID = -509;

        public const ulong CRYPTUI_SELECT_ISSUEDTO_COLUMN = 0x000000001;

        public const ulong CRYPTUI_SELECT_ISSUEDBY_COLUMN = 0x000000002;

        public const ulong CRYPTUI_SELECT_INTENDEDUSE_COLUMN = 0x000000004;

        public const ulong CRYPTUI_SELECT_FRIENDLYNAME_COLUMN = 0x000000008;

        public const ulong CRYPTUI_SELECT_LOCATION_COLUMN = 0x000000010;

        public const ulong CRYPTUI_SELECT_EXPIRATION_COLUMN = 0x000000020;

        public const uint CRYPTUI_CERT_MGR_TAB_MASK = 0x0000000F;

        public const uint CRYPTUI_CERT_MGR_PUBLISHER_TAB = 0x00000004;

        public const uint CRYPTUI_CERT_MGR_SINGLE_TAB_FLAG = 0x00008000;

        public const uint CRYPTUI_WIZ_DIGITAL_SIGN_EXCLUDE_PAGE_HASHES = 0x0002;

        public const uint CRYPTUI_WIZ_DIGITAL_SIGN_INCLUDE_PAGE_HASHES = 0x0004;

        public const uint CRYPTUI_WIZ_EXPORT_FORMAT_SERIALIZED_CERT_STORE = 5;

        public const uint CRYPT_XML_BLOB_MAX = 0x7FFFFFF8;

        public const uint CRYPT_XML_ID_MAX = 256;

        public const uint CRYPT_XML_SIGNATURES_MAX = 16;

        public const uint CRYPT_XML_TRANSFORM_MAX = 16;

        public const uint CRYPT_XML_SIGNATURE_VALUE_MAX = 2048;

        public const uint CRYPT_XML_DIGEST_VALUE_MAX = 128;

        public const uint CRYPT_XML_OBJECTS_MAX = 256;

        public const uint CRYPT_XML_REFERENCES_MAX = 0x7FF8;

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_BASE = unchecked((int)0x80092100);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_LARGE = unchecked((int)0x80092101);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_TOO_MANY_TRANSFORMS = unchecked((int)0x80092102);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_ENCODING = unchecked((int)0x80092103);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_ALGORITHM = unchecked((int)0x80092104);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_TRANSFORM = unchecked((int)0x80092105);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_HANDLE = unchecked((int)0x80092106);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_OPERATION = unchecked((int)0x80092107);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_UNRESOLVED_REFERENCE = unchecked((int)0x80092108);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_INVALID_DIGEST = unchecked((int)0x80092109);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_INVALID_SIGNATURE = unchecked((int)0x8009210A);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_HASH_FAILED = unchecked((int)0x8009210B);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_SIGN_FAILED = unchecked((int)0x8009210C);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_VERIFY_FAILED = unchecked((int)0x8009210D);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_TOO_MANY_SIGNATURES = unchecked((int)0x8009210E);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_INVALID_KEYVALUE = unchecked((int)0x8009210F);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_UNEXPECTED_XML = unchecked((int)0x80092110);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_SIGNER = unchecked((int)0x80092111);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_NON_UNIQUE_ID = unchecked((int)0x80092112);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_XML_E_LAST = unchecked((int)0x80092112);

        public const uint CRYPT_XML_FLAG_ALWAYS_RETURN_ENCODED_OBJECT = 0x40000000;

        public const uint CRYPT_XML_FLAG_ENFORCE_ID_NCNAME_FORMAT = 0x20000000;

        public const uint CRYPT_XML_FLAG_ENFORCE_ID_NAME_FORMAT = 0x08000000;

        public const uint CRYPT_XML_FLAG_ECDSA_DSIG11 = 0x04000000;

        public const uint CRYPT_XML_STATUS_NO_ERROR = 0x00000000;

        public const uint CRYPT_XML_FLAG_ADD_OBJECT_CREATE_COPY = 0x00000001;

        public const uint CRYPT_XML_FLAG_CREATE_REFERENCE_AS_OBJECT = 0x00000001;

        public const uint CRYPT_XML_DIGEST_REFERENCE_DATA_TRANSFORMED = 0x00000001;

        public const uint CRYPT_XML_GROUP_ID_HASH = 1;

        public const uint CRYPT_XML_GROUP_ID_SIGN = 2;

        public const uint CRYPT_XML_ALGORITHM_INFO_FIND_BY_URI = 1;

        public const uint CRYPT_XML_ALGORITHM_INFO_FIND_BY_NAME = 2;

        public const uint CRYPT_XML_ALGORITHM_INFO_FIND_BY_CNG_ALGID = 3;

        public const uint CRYPT_XML_ALGORITHM_INFO_FIND_BY_CNG_SIGN_ALGID = 4;

        public const uint NCRYPT_MAX_KEY_NAME_LENGTH = 512;

        public const uint NCRYPT_MAX_ALG_ID_LENGTH = 512;

        public const uint NCRYPT_KEY_PROTECTION_INTERFACE = 0x00010004;

        public const uint NCRYPTBUFFER_VERSION = 0;

        public const uint NCRYPTBUFFER_EMPTY = 0;

        public const uint NCRYPTBUFFER_DATA = 1;

        public const uint NCRYPTBUFFER_PROTECTION_DESCRIPTOR_STRING = 3;

        public const uint NCRYPTBUFFER_PROTECTION_FLAGS = 4;

        public const uint NCRYPTBUFFER_SSL_CLIENT_RANDOM = 20;

        public const uint NCRYPTBUFFER_SSL_SERVER_RANDOM = 21;

        public const uint NCRYPTBUFFER_SSL_HIGHEST_VERSION = 22;

        public const uint NCRYPTBUFFER_SSL_CLEAR_KEY = 23;

        public const uint NCRYPTBUFFER_SSL_KEY_ARG_DATA = 24;

        public const uint NCRYPTBUFFER_SSL_SESSION_HASH = 25;

        public const uint NCRYPTBUFFER_PKCS_OID = 40;

        public const uint NCRYPTBUFFER_PKCS_ALG_OID = 41;

        public const uint NCRYPTBUFFER_PKCS_ALG_PARAM = 42;

        public const uint NCRYPTBUFFER_PKCS_ALG_ID = 43;

        public const uint NCRYPTBUFFER_PKCS_ATTRS = 44;

        public const uint NCRYPTBUFFER_PKCS_KEY_NAME = 45;

        public const uint NCRYPTBUFFER_PKCS_SECRET = 46;

        public const uint NCRYPTBUFFER_CERT_BLOB = 47;

        public const uint NCRYPTBUFFER_CLAIM_IDBINDING_NONCE = 48;

        public const uint NCRYPTBUFFER_CLAIM_KEYATTESTATION_NONCE = 49;

        public const uint NCRYPTBUFFER_KEY_PROPERTY_FLAGS = 50;

        public const uint NCRYPTBUFFER_ATTESTATIONSTATEMENT_BLOB = 51;

        public const uint NCRYPTBUFFER_ATTESTATION_CLAIM_TYPE = 52;

        public const uint NCRYPTBUFFER_ATTESTATION_CLAIM_CHALLENGE_REQUIRED = 53;

        public const uint NCRYPTBUFFER_VSM_KEY_ATTESTATION_CLAIM_RESTRICTIONS = 54;

        public const uint NCRYPTBUFFER_ECC_CURVE_NAME = 60;

        public const uint NCRYPTBUFFER_ECC_PARAMETERS = 61;

        public const uint NCRYPTBUFFER_TPM_SEAL_PASSWORD = 70;

        public const uint NCRYPTBUFFER_TPM_SEAL_POLICYINFO = 71;

        public const uint NCRYPTBUFFER_TPM_SEAL_TICKET = 72;

        public const uint NCRYPTBUFFER_TPM_SEAL_NO_DA_PROTECTION = 73;

        public const uint NCRYPTBUFFER_TPM_PLATFORM_CLAIM_PCR_MASK = 80;

        public const uint NCRYPTBUFFER_TPM_PLATFORM_CLAIM_NONCE = 81;

        public const uint NCRYPTBUFFER_TPM_PLATFORM_CLAIM_STATIC_CREATE = 82;

        public const uint NCRYPT_CIPHER_NO_PADDING_FLAG = 0x00000000;

        public const uint NCRYPT_CIPHER_BLOCK_PADDING_FLAG = 0x00000001;

        public const uint NCRYPT_CIPHER_OTHER_PADDING_FLAG = 0x00000002;

        public const uint NCRYPT_PLATFORM_ATTEST_MAGIC = 0x44504150;

        public const uint NCRYPT_KEY_ATTEST_MAGIC = 0x4450414b;

        public const uint NCRYPT_CLAIM_AUTHORITY_ONLY = 0x00000001;

        public const uint NCRYPT_CLAIM_SUBJECT_ONLY = 0x00000002;

        public const uint NCRYPT_CLAIM_WEB_AUTH_SUBJECT_ONLY = 0x00000102;

        public const uint NCRYPT_CLAIM_AUTHORITY_AND_SUBJECT = 0x00000003;

        public const uint NCRYPT_CLAIM_VSM_KEY_ATTESTATION_STATEMENT = 0x00000004;

        public const uint NCRYPT_CLAIM_UNKNOWN = 0x00001000;

        public const uint NCRYPT_CLAIM_PLATFORM = 0x00010000;

        public const uint NCRYPT_ISOLATED_KEY_FLAG_CREATED_IN_ISOLATION = 0x00000001;

        public const uint NCRYPT_ISOLATED_KEY_FLAG_IMPORT_ONLY = 0x00000002;

        public const uint NCRYPT_ISOLATED_KEY_ATTESTED_ATTRIBUTES_V0 = 0;

        public const uint NCRYPT_VSM_KEY_ATTESTATION_STATEMENT_V0 = 0;

        public const uint NCRYPT_VSM_KEY_ATTESTATION_CLAIM_RESTRICTIONS_V0 = 0;

        public const uint NCRYPT_EXPORTED_ISOLATED_KEY_HEADER_V0 = 0;

        public const uint NCRYPT_TPM_PLATFORM_ATTESTATION_STATEMENT_V0 = 0;

        public const uint NCRYPT_PAD_CIPHER_FLAG = 0x00000010;

        public const uint NCRYPT_ATTESTATION_FLAG = 0x00000020;

        public const uint NCRYPT_SEALING_FLAG = 0x00000100;

        public const uint NCRYPT_DO_NOT_FINALIZE_FLAG = 0x00000400;

        public const uint NCRYPT_EXPORT_LEGACY_FLAG = 0x00000800;

        public const uint NCRYPT_IGNORE_DEVICE_STATE_FLAG = 0x00001000;

        public const uint NCRYPT_TREAT_NIST_AS_GENERIC_ECC_FLAG = 0x00002000;

        public const uint NCRYPT_NO_CACHED_PASSWORD = 0x00004000;

        public const uint NCRYPT_PROTECT_TO_LOCAL_SYSTEM = 0x00008000;

        public const uint NCRYPT_PREFER_VIRTUAL_ISOLATION_FLAG = 0x00010000;

        public const uint NCRYPT_USE_VIRTUAL_ISOLATION_FLAG = 0x00020000;

        public const uint NCRYPT_USE_PER_BOOT_KEY_FLAG = 0x00040000;

        public const uint NCRYPT_AUTHORITY_KEY_FLAG = 0x00000100;

        public const uint NCRYPT_TPM_PSS_SALT_SIZE_UNKNOWN = 0x00000000;

        public const uint NCRYPT_TPM_PSS_SALT_SIZE_MAXIMUM = 0x00000001;

        public const uint NCRYPT_TPM_PSS_SALT_SIZE_HASHSIZE = 0x00000002;

        public const uint NCRYPT_TPM_PAD_PSS_IGNORE_SALT = 0x00000020;

        public const uint IFX_RSA_KEYGEN_VUL_NOT_AFFECTED = 0;

        public const uint IFX_RSA_KEYGEN_VUL_AFFECTED_LEVEL_1 = 1;

        public const uint IFX_RSA_KEYGEN_VUL_AFFECTED_LEVEL_2 = 2;

        public const uint NCRYPT_TPM12_PROVIDER = 0x00010000;

        public const uint NCRYPT_PCP_SIGNATURE_KEY = 0x00000001;

        public const uint NCRYPT_PCP_ENCRYPTION_KEY = 0x00000002;

        public const uint NCRYPT_PCP_STORAGE_KEY = 0x00000004;

        public const uint NCRYPT_PCP_IDENTITY_KEY = 0x00000008;

        public const uint NCRYPT_PCP_HMACVERIFICATION_KEY = 0x00000010;

        public const uint NCRYPT_MAX_PROPERTY_NAME = 64;

        public const uint NCRYPT_MAX_PROPERTY_DATA = 0x100000;

        public const uint NCRYPT_ALLOW_EXPORT_FLAG = 0x00000001;

        public const uint NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG = 0x00000002;

        public const uint NCRYPT_ALLOW_ARCHIVING_FLAG = 0x00000004;

        public const uint NCRYPT_ALLOW_PLAINTEXT_ARCHIVING_FLAG = 0x00000008;

        public const uint NCRYPT_IMPL_HARDWARE_FLAG = 0x00000001;

        public const uint NCRYPT_IMPL_SOFTWARE_FLAG = 0x00000002;

        public const uint NCRYPT_IMPL_REMOVABLE_FLAG = 0x00000008;

        public const uint NCRYPT_IMPL_HARDWARE_RNG_FLAG = 0x00000010;

        public const uint NCRYPT_IMPL_VIRTUAL_ISOLATION_FLAG = 0x00000020;

        public const uint NCRYPT_ALLOW_DECRYPT_FLAG = 0x00000001;

        public const uint NCRYPT_ALLOW_SIGNING_FLAG = 0x00000002;

        public const uint NCRYPT_ALLOW_KEY_AGREEMENT_FLAG = 0x00000004;

        public const uint NCRYPT_ALLOW_KEY_IMPORT_FLAG = 0x00000008;

        public const uint NCRYPT_ALLOW_ALL_USAGES = 0x00ffffff;

        public const uint NCRYPT_UI_PROTECT_KEY_FLAG = 0x00000001;

        public const uint NCRYPT_UI_FORCE_HIGH_PROTECTION_FLAG = 0x00000002;

        public const uint NCRYPT_UI_FINGERPRINT_PROTECTION_FLAG = 0x00000004;

        public const uint NCRYPT_UI_APPCONTAINER_ACCESS_MEDIUM_FLAG = 0x00000008;

        public const uint NCRYPT_PIN_CACHE_DISABLE_DPL_FLAG = 0x00000001;

        public const uint NCRYPT_PIN_CACHE_REQUIRE_GESTURE_FLAG = 0x00000001;

        public const uint NCRYPT_PIN_CACHE_PIN_BYTE_LENGTH = 90;

        public const uint NCRYPT_PIN_CACHE_APPLICATION_TICKET_BYTE_LENGTH = 90;

        public const uint NCRYPT_PIN_CACHE_CLEAR_FOR_CALLING_PROCESS_OPTION = 0x00000001;

        public const uint NCRYPT_KEY_ACCESS_POLICY_VERSION = 1;

        public const uint NCRYPT_ALLOW_SILENT_KEY_ACCESS = 0x00000001;

        public const uint NCRYPT_CIPHER_KEY_BLOB_MAGIC = 0x52485043;

        public const uint NCRYPT_KDF_KEY_BLOB_MAGIC = 0x3146444B;

        public const uint NCRYPT_PROTECTED_KEY_BLOB_MAGIC = 0x4B545250;

        public const uint NCRYPT_TPM_LOADABLE_KEY_BLOB_MAGIC = 0x4D54504B;

        public const uint NCRYPT_NAMED_DESCRIPTOR_FLAG = 0x00000001;

        public const uint NCRYPT_PROTECTION_INFO_TYPE_DESCRIPTOR_STRING = 0x00000001;

        public const uint ALG_CLASS_ANY = 0;

        public const uint ALG_CLASS_SIGNATURE = 1u<< 13;

        public const uint ALG_CLASS_MSG_ENCRYPT = 2u<< 13;

        public const uint ALG_CLASS_DATA_ENCRYPT = 3u<< 13;

        public const uint ALG_CLASS_HASH = 4u<< 13;

        public const uint ALG_CLASS_KEY_EXCHANGE = 5u<< 13;

        public const uint ALG_CLASS_ALL = 7u<< 13;

        public const uint ALG_TYPE_ANY = 0;

        public const uint ALG_TYPE_DSS = 1u<< 9;

        public const uint ALG_TYPE_RSA = 2u<< 9;

        public const uint ALG_TYPE_BLOCK = 3u<< 9;

        public const uint ALG_TYPE_STREAM = 4u<< 9;

        public const uint ALG_TYPE_DH = 5u<< 9;

        public const uint ALG_TYPE_SECURECHANNEL = 6u<< 9;

        public const uint ALG_TYPE_ECDH = 7u<< 9;

        public const uint ALG_TYPE_THIRDPARTY = 8u<< 9;

        public const uint ALG_SID_ANY = 0;

        public const uint ALG_SID_THIRDPARTY_ANY = 0;

        public const uint ALG_SID_RSA_ANY = 0;

        public const uint ALG_SID_RSA_PKCS = 1;

        public const uint ALG_SID_RSA_MSATWORK = 2;

        public const uint ALG_SID_RSA_ENTRUST = 3;

        public const uint ALG_SID_RSA_PGP = 4;

        public const uint ALG_SID_DSS_ANY = 0;

        public const uint ALG_SID_DSS_PKCS = 1;

        public const uint ALG_SID_DSS_DMS = 2;

        public const uint ALG_SID_ECDSA = 3;

        public const uint ALG_SID_DES = 1;

        public const uint ALG_SID_3DES = 3;

        public const uint ALG_SID_DESX = 4;

        public const uint ALG_SID_IDEA = 5;

        public const uint ALG_SID_CAST = 6;

        public const uint ALG_SID_SAFERSK64 = 7;

        public const uint ALG_SID_SAFERSK128 = 8;

        public const uint ALG_SID_3DES_112 = 9;

        public const uint ALG_SID_CYLINK_MEK = 12;

        public const uint ALG_SID_RC5 = 13;

        public const uint ALG_SID_AES_128 = 14;

        public const uint ALG_SID_AES_192 = 15;

        public const uint ALG_SID_AES_256 = 16;

        public const uint ALG_SID_AES = 17;

        public const uint ALG_SID_SKIPJACK = 10;

        public const uint ALG_SID_TEK = 11;

        public const uint CRYPT_MODE_CBCI = 6;

        public const uint CRYPT_MODE_CFBP = 7;

        public const uint CRYPT_MODE_OFBP = 8;

        public const uint CRYPT_MODE_CBCOFM = 9;

        public const uint CRYPT_MODE_CBCOFMI = 10;

        public const uint ALG_SID_RC2 = 2;

        public const uint ALG_SID_RC4 = 1;

        public const uint ALG_SID_SEAL = 2;

        public const uint ALG_SID_DH_SANDF = 1;

        public const uint ALG_SID_DH_EPHEM = 2;

        public const uint ALG_SID_AGREED_KEY_ANY = 3;

        public const uint ALG_SID_KEA = 4;

        public const uint ALG_SID_ECDH = 5;

        public const uint ALG_SID_ECDH_EPHEM = 6;

        public const uint ALG_SID_MD2 = 1;

        public const uint ALG_SID_MD4 = 2;

        public const uint ALG_SID_MD5 = 3;

        public const uint ALG_SID_SHA = 4;

        public const uint ALG_SID_SHA1 = 4;

        public const uint ALG_SID_MAC = 5;

        public const uint ALG_SID_RIPEMD = 6;

        public const uint ALG_SID_RIPEMD160 = 7;

        public const uint ALG_SID_SSL3SHAMD5 = 8;

        public const uint ALG_SID_HMAC = 9;

        public const uint ALG_SID_TLS1PRF = 10;

        public const uint ALG_SID_HASH_REPLACE_OWF = 11;

        public const uint ALG_SID_SHA_256 = 12;

        public const uint ALG_SID_SHA_384 = 13;

        public const uint ALG_SID_SHA_512 = 14;

        public const uint ALG_SID_SSL3_MASTER = 1;

        public const uint ALG_SID_SCHANNEL_MASTER_HASH = 2;

        public const uint ALG_SID_SCHANNEL_MAC_KEY = 3;

        public const uint ALG_SID_PCT1_MASTER = 4;

        public const uint ALG_SID_SSL2_MASTER = 5;

        public const uint ALG_SID_TLS1_MASTER = 6;

        public const uint ALG_SID_SCHANNEL_ENC_KEY = 7;

        public const uint ALG_SID_ECMQV = 1;

        public const uint ALG_SID_EXAMPLE = 80;

        public const uint SIGNATURE_RESOURCE_NUMBER = 0x29A;

        public const uint CRYPT_VERIFYCONTEXT = 0xF0000000;

        public const uint CRYPT_NEWKEYSET = 0x00000008;

        public const uint CRYPT_DELETEKEYSET = 0x00000010;

        public const uint CRYPT_SILENT = 0x00000040;

        public const uint CRYPT_DEFAULT_CONTAINER_OPTIONAL = 0x00000080;

        public const uint CRYPT_UPDATE_KEY = 0x00000008;

        public const uint CRYPT_USER_PROTECTED_STRONG = 0x00100000;

        public const uint RSA1024BIT_KEY = 0x04000000;

        public const uint CRYPT_SERVER = 0x00000400;

        public const uint KEY_LENGTH_MASK = 0xFFFF0000;

        public const uint CRYPT_DECRYPT_RSA_NO_PADDING_CHECK = 0x00000020;

        public const uint CRYPT_SECRETDIGEST = 0x00000001;

        public const uint CRYPT_OWF_REPL_LM_HASH = 0x00000001;

        public const uint CRYPT_LITTLE_ENDIAN = 0x00000001;

        public const uint CRYPT_NOHASHOID = 0x00000001;

        public const uint CRYPT_TYPE2_FORMAT = 0x00000002;

        public const uint CRYPT_X931_FORMAT = 0x00000004;

        public const uint CRYPT_MACHINE_DEFAULT = 0x00000001;

        public const uint CRYPT_USER_DEFAULT = 0x00000002;

        public const uint CRYPT_DELETE_DEFAULT = 0x00000004;

        public const uint SIMPLEBLOB = 0x1;

        public const uint PUBLICKEYBLOB = 0x6;

        public const uint PRIVATEKEYBLOB = 0x7;

        public const uint PLAINTEXTKEYBLOB = 0x8;

        public const uint OPAQUEKEYBLOB = 0x9;

        public const uint PUBLICKEYBLOBEX = 0xA;

        public const uint SYMMETRICWRAPKEYBLOB = 0xB;

        public const uint KEYSTATEBLOB = 0xC;

        public const uint CRYPT_USERDATA = 1;

        public const uint KP_IV = 1;

        public const uint KP_PADDING = 3;

        public const uint KP_MODE = 4;

        public const uint KP_MODE_BITS = 5;

        public const uint KP_P = 11;

        public const uint KP_G = 12;

        public const uint KP_Q = 13;

        public const uint KP_X = 14;

        public const uint KP_Y = 15;

        public const uint KP_RA = 16;

        public const uint KP_RB = 17;

        public const uint KP_INFO = 18;

        public const uint KP_EFFECTIVE_KEYLEN = 19;

        public const uint KP_SCHANNEL_ALG = 20;

        public const uint KP_CLIENT_RANDOM = 21;

        public const uint KP_SERVER_RANDOM = 22;

        public const uint KP_RP = 23;

        public const uint KP_PRECOMP_MD5 = 24;

        public const uint KP_PRECOMP_SHA = 25;

        public const uint KP_CLEAR_KEY = 27;

        public const uint KP_PUB_EX_LEN = 28;

        public const uint KP_PUB_EX_VAL = 29;

        public const uint KP_KEYVAL = 30;

        public const uint KP_ADMIN_PIN = 31;

        public const uint KP_KEYEXCHANGE_PIN = 32;

        public const uint KP_SIGNATURE_PIN = 33;

        public const uint KP_PREHASH = 34;

        public const uint KP_ROUNDS = 35;

        public const uint KP_OAEP_PARAMS = 36;

        public const uint KP_CMS_KEY_INFO = 37;

        public const uint KP_CMS_DH_KEY_INFO = 38;

        public const uint KP_PUB_PARAMS = 39;

        public const uint KP_VERIFY_PARAMS = 40;

        public const uint KP_HIGHEST_VERSION = 41;

        public const uint KP_PIN_ID = 43;

        public const uint KP_PIN_INFO = 44;

        public const uint PKCS5_PADDING = 1;

        public const uint RANDOM_PADDING = 2;

        public const uint ZERO_PADDING = 3;

        public const uint CRYPT_MODE_CBC = 1;

        public const uint CRYPT_MODE_ECB = 2;

        public const uint CRYPT_MODE_OFB = 3;

        public const uint CRYPT_MODE_CFB = 4;

        public const uint CRYPT_MODE_CTS = 5;

        public const uint CRYPT_ENCRYPT = 0x0001;

        public const uint CRYPT_DECRYPT = 0x0002;

        public const uint CRYPT_EXPORT = 0x0004;

        public const uint CRYPT_READ = 0x0008;

        public const uint CRYPT_WRITE = 0x0010;

        public const uint CRYPT_MAC = 0x0020;

        public const uint CRYPT_EXPORT_KEY = 0x0040;

        public const uint CRYPT_IMPORT_KEY = 0x0080;

        public const uint CRYPT_ARCHIVE = 0x0100;

        public const uint HP_ALGID = 0x0001;

        public const uint HP_HASHSIZE = 0x0004;

        public const uint HP_TLS1PRF_LABEL = 0x0006;

        public const uint HP_TLS1PRF_SEED = 0x0007;

        public const uint CRYPT_FAILED = 0;

        public const uint CRYPT_SUCCEED = 1;

        public const uint PP_ENUMALGS = 1;

        public const uint PP_ENUMCONTAINERS = 2;

        public const uint PP_IMPTYPE = 3;

        public const uint PP_NAME = 4;

        public const uint PP_VERSION = 5;

        public const uint PP_CONTAINER = 6;

        public const uint PP_CHANGE_PASSWORD = 7;

        public const uint PP_CERTCHAIN = 9;

        public const uint PP_KEY_TYPE_SUBTYPE = 10;

        public const uint PP_PROVTYPE = 16;

        public const uint PP_KEYSTORAGE = 17;

        public const uint PP_APPLI_CERT = 18;

        public const uint PP_SYM_KEYSIZE = 19;

        public const uint PP_SESSION_KEYSIZE = 20;

        public const uint PP_ENUMALGS_EX = 22;

        public const uint PP_ENUMMANDROOTS = 25;

        public const uint PP_ENUMELECTROOTS = 26;

        public const uint PP_KEYSET_TYPE = 27;

        public const uint PP_ADMIN_PIN = 31;

        public const uint PP_SIG_KEYSIZE_INC = 34;

        public const uint PP_KEYX_KEYSIZE_INC = 35;

        public const uint PP_UNIQUE_CONTAINER = 36;

        public const uint PP_SGC_INFO = 37;

        public const uint PP_KEYSPEC = 39;

        public const uint PP_ENUMEX_SIGNING_PROT = 40;

        public const uint PP_CRYPT_COUNT_KEY_USE = 41;

        public const uint PP_SMARTCARD_GUID = 45;

        public const uint PP_SMARTCARD_READER_ICON = 47;

        public const uint CRYPT_FIRST = 1;

        public const uint CRYPT_NEXT = 2;

        public const uint CRYPT_SGC_ENUM = 4;

        public const uint CRYPT_IMPL_HARDWARE = 1;

        public const uint CRYPT_IMPL_SOFTWARE = 2;

        public const uint CRYPT_IMPL_MIXED = 3;

        public const uint CRYPT_IMPL_UNKNOWN = 4;

        public const uint CRYPT_IMPL_REMOVABLE = 8;

        public const uint CRYPT_SEC_DESCR = 0x00000001;

        public const uint CRYPT_PSTORE = 0x00000002;

        public const uint CRYPT_UI_PROMPT = 0x00000004;

        public const uint CRYPT_FLAG_PCT1 = 0x0001;

        public const uint CRYPT_FLAG_SSL2 = 0x0002;

        public const uint CRYPT_FLAG_SSL3 = 0x0004;

        public const uint CRYPT_FLAG_TLS1 = 0x0008;

        public const uint CRYPT_FLAG_IPSEC = 0x0010;

        public const uint CRYPT_FLAG_SIGNING = 0x0020;

        public const uint CRYPT_SGC = 0x0001;

        public const uint CRYPT_FASTSGC = 0x0002;

        public const uint PP_CONTEXT_INFO = 11;

        public const uint PP_DISMISS_PIN_UI_SEC = 49;

        public const uint PROV_RSA_FULL = 1;

        public const uint PROV_RSA_SIG = 2;

        public const uint PROV_DSS = 3;

        public const uint PROV_FORTEZZA = 4;

        public const uint PROV_MS_EXCHANGE = 5;

        public const uint PROV_SSL = 6;

        public const uint PROV_RSA_SCHANNEL = 12;

        public const uint PROV_DSS_DH = 13;

        public const uint PROV_EC_ECDSA_SIG = 14;

        public const uint PROV_EC_ECNRA_SIG = 15;

        public const uint PROV_EC_ECDSA_FULL = 16;

        public const uint PROV_EC_ECNRA_FULL = 17;

        public const uint PROV_DH_SCHANNEL = 18;

        public const uint PROV_SPYRUS_LYNKS = 20;

        public const uint PROV_RNG = 21;

        public const uint PROV_INTEL_SEC = 22;

        public const uint PROV_REPLACE_OWF = 23;

        public const uint PROV_RSA_AES = 24;

        public const uint PROV_STT_MER = 7;

        public const uint PROV_STT_ACQ = 8;

        public const uint PROV_STT_BRND = 9;

        public const uint PROV_STT_ROOT = 10;

        public const uint PROV_STT_ISS = 11;

        public const uint MAXUIDLEN = 64;

        public const uint CUR_BLOB_VERSION = 2;

        public const uint SCHANNEL_MAC_KEY = 0x00000000;

        public const uint SCHANNEL_ENC_KEY = 0x00000001;

        public const uint INTERNATIONAL_USAGE = 0x00000001;

        public const uint CERT_RDN_TYPE_MASK = 0x000000FF;

        public const uint CERT_RDN_FLAGS_MASK = 0xFF000000;

        public const uint CERT_RDN_ENABLE_T61_UNICODE_FLAG = 0x80000000;

        public const uint CERT_RDN_ENABLE_UTF8_UNICODE_FLAG = 0x20000000;

        public const uint CERT_RDN_FORCE_UTF8_UNICODE_FLAG = 0x10000000;

        public const uint CERT_RDN_DISABLE_CHECK_TYPE_FLAG = 0x40000000;

        public const uint CERT_RDN_DISABLE_IE4_UTF8_FLAG = 0x01000000;

        public const uint CERT_RDN_ENABLE_PUNYCODE_FLAG = 0x02000000;

        public const uint CRYPT_ECC_PRIVATE_KEY_INFO_v1 = 1;

        public const uint CERT_V1 = 0;

        public const uint CERT_V2 = 1;

        public const uint CERT_V3 = 2;

        public const uint CERT_INFO_VERSION_FLAG = 1;

        public const uint CERT_INFO_SERIAL_NUMBER_FLAG = 2;

        public const uint CERT_INFO_SIGNATURE_ALGORITHM_FLAG = 3;

        public const uint CERT_INFO_ISSUER_FLAG = 4;

        public const uint CERT_INFO_NOT_BEFORE_FLAG = 5;

        public const uint CERT_INFO_NOT_AFTER_FLAG = 6;

        public const uint CERT_INFO_SUBJECT_FLAG = 7;

        public const uint CERT_INFO_SUBJECT_PUBLIC_KEY_INFO_FLAG = 8;

        public const uint CERT_INFO_ISSUER_UNIQUE_ID_FLAG = 9;

        public const uint CERT_INFO_SUBJECT_UNIQUE_ID_FLAG = 10;

        public const uint CERT_INFO_EXTENSION_FLAG = 11;

        public const uint CRL_V1 = 0;

        public const uint CRL_V2 = 1;

        public const uint CERT_BUNDLE_CERTIFICATE = 0;

        public const uint CERT_BUNDLE_CRL = 1;

        public const uint CERT_REQUEST_V1 = 0;

        public const uint CERT_KEYGEN_REQUEST_V1 = 0;

        public const uint CTL_V1 = 0;

        public const uint CERT_ENCODING_TYPE_MASK = 0x0000FFFF;

        public const uint CMSG_ENCODING_TYPE_MASK = 0xFFFF0000;

        public const uint CRYPT_ASN_ENCODING = 0x00000001;

        public const uint CRYPT_NDR_ENCODING = 0x00000002;

        public const uint X509_NDR_ENCODING = 0x00000002;

        public const uint PKCS_7_NDR_ENCODING = 0x00020000;

        public const uint CRYPT_FORMAT_STR_MULTI_LINE = 0x0001;

        public const uint CRYPT_FORMAT_STR_NO_HEX = 0x0010;

        public const uint CRYPT_FORMAT_SIMPLE = 0x0001;

        public const uint CRYPT_FORMAT_X509 = 0x0002;

        public const uint CRYPT_FORMAT_OID = 0x0004;

        public const uint CRYPT_FORMAT_RDN_SEMICOLON = 0x0100;

        public const uint CRYPT_FORMAT_RDN_CRLF = 0x0200;

        public const uint CRYPT_FORMAT_RDN_UNQUOTE = 0x0400;

        public const uint CRYPT_FORMAT_RDN_REVERSE = 0x0800;

        public const uint CRYPT_FORMAT_COMMA = 0x1000;

        public const uint CRYPT_ENCODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG = 0x8;

        public const uint CRYPT_SORTED_CTL_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG = 0x10000;

        public const uint CRYPT_ENCODE_ENABLE_UTF8PERCENT_FLAG = 0x40000;

        public const uint CRYPT_DECODE_NOCOPY_FLAG = 0x1;

        public const uint CRYPT_DECODE_TO_BE_SIGNED_FLAG = 0x2;

        public const uint CRYPT_DECODE_SHARE_OID_STRING_FLAG = 0x4;

        public const uint CRYPT_DECODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG = 0x8;

        public const uint CRYPT_DECODE_ALLOC_FLAG = 0x8000;

        public const uint CRYPT_DECODE_ENABLE_PUNYCODE_FLAG = 0x02000000;

        public const uint CRYPT_DECODE_ENABLE_UTF8PERCENT_FLAG = 0x04000000;

        public const uint CRYPT_ENCODE_DECODE_NONE = 0;

        public const uint SITE_PIN_RULES_ALL_SUBDOMAINS_FLAG = 0x1;

        public const uint CERT_ROOT_PROGRAM_FLAG_OU = 0x10;

        public const uint CERT_ROOT_PROGRAM_FLAG_ADDRESS = 0x08;

        public const uint CERT_UNICODE_RDN_ERR_INDEX_MASK = 0x3FF;

        public const uint CERT_UNICODE_RDN_ERR_INDEX_SHIFT = 22;

        public const uint CERT_UNICODE_ATTR_ERR_INDEX_MASK = 0x003F;

        public const uint CERT_UNICODE_ATTR_ERR_INDEX_SHIFT = 16;

        public const uint CERT_UNICODE_VALUE_ERR_INDEX_MASK = 0x0000FFFF;

        public const uint CERT_UNICODE_VALUE_ERR_INDEX_SHIFT = 0;

        public const uint CERT_DIGITAL_SIGNATURE_KEY_USAGE = 0x80;

        public const uint CERT_NON_REPUDIATION_KEY_USAGE = 0x40;

        public const uint CERT_KEY_ENCIPHERMENT_KEY_USAGE = 0x20;

        public const uint CERT_DATA_ENCIPHERMENT_KEY_USAGE = 0x10;

        public const uint CERT_KEY_AGREEMENT_KEY_USAGE = 0x08;

        public const uint CERT_KEY_CERT_SIGN_KEY_USAGE = 0x04;

        public const uint CERT_OFFLINE_CRL_SIGN_KEY_USAGE = 0x02;

        public const uint CERT_CRL_SIGN_KEY_USAGE = 0x02;

        public const uint CERT_ENCIPHER_ONLY_KEY_USAGE = 0x01;

        public const uint CERT_DECIPHER_ONLY_KEY_USAGE = 0x80;

        public const uint CERT_ALT_NAME_X400_ADDRESS = 4;

        public const uint CERT_ALT_NAME_EDI_PARTY_NAME = 6;

        public const uint CERT_ALT_NAME_ENTRY_ERR_INDEX_MASK = 0xFF;

        public const uint CERT_ALT_NAME_ENTRY_ERR_INDEX_SHIFT = 16;

        public const uint CERT_ALT_NAME_VALUE_ERR_INDEX_MASK = 0x0000FFFF;

        public const uint CERT_ALT_NAME_VALUE_ERR_INDEX_SHIFT = 0;

        public const uint CERT_CA_SUBJECT_FLAG = 0x80;

        public const uint CERT_END_ENTITY_SUBJECT_FLAG = 0x40;

        public const uint CRL_REASON_PRIVILEGE_WITHDRAWN = 9;

        public const uint CRL_REASON_AA_COMPROMISE = 10;

        public const uint CRL_DIST_POINT_NO_NAME = 0;

        public const uint CRL_DIST_POINT_FULL_NAME = 1;

        public const uint CRL_DIST_POINT_ISSUER_RDN_NAME = 2;

        public const uint CRL_REASON_UNUSED_FLAG = 0x80;

        public const uint CRL_REASON_KEY_COMPROMISE_FLAG = 0x40;

        public const uint CRL_REASON_CA_COMPROMISE_FLAG = 0x20;

        public const uint CRL_REASON_AFFILIATION_CHANGED_FLAG = 0x10;

        public const uint CRL_REASON_SUPERSEDED_FLAG = 0x08;

        public const uint CRL_REASON_CESSATION_OF_OPERATION_FLAG = 0x04;

        public const uint CRL_REASON_CERTIFICATE_HOLD_FLAG = 0x02;

        public const uint CRL_REASON_PRIVILEGE_WITHDRAWN_FLAG = 0x01;

        public const uint CRL_REASON_AA_COMPROMISE_FLAG = 0x80;

        public const uint CRL_DIST_POINT_ERR_INDEX_MASK = 0x7F;

        public const uint CRL_DIST_POINT_ERR_INDEX_SHIFT = 24;

        public const int CRL_DIST_POINT_ERR_CRL_ISSUER_BIT = unchecked((int)0x80000000);

        public const uint CROSS_CERT_DIST_POINT_ERR_INDEX_MASK = 0xFF;

        public const uint CROSS_CERT_DIST_POINT_ERR_INDEX_SHIFT = 24;

        public const int CERT_EXCLUDED_SUBTREE_BIT = unchecked((int)0x80000000);

        public const uint SORTED_CTL_EXT_HASHED_SUBJECT_IDENTIFIER_FLAG = 0x1;

        public const uint CERT_DSS_R_LEN = 20;

        public const uint CERT_DSS_S_LEN = 20;

        public const uint CRYPT_X942_COUNTER_BYTE_LENGTH = 4;

        public const uint CRYPT_X942_KEY_LENGTH_BYTE_LENGTH = 4;

        public const uint CRYPT_ECC_CMS_SHARED_INFO_SUPPPUBINFO_BYTE_LENGTH = 4;

        public const uint CRYPT_RC2_40BIT_VERSION = 160;

        public const uint CRYPT_RC2_56BIT_VERSION = 52;

        public const uint CRYPT_RC2_64BIT_VERSION = 120;

        public const uint CRYPT_RC2_128BIT_VERSION = 58;

        public const uint PKCS_RSA_SSA_PSS_TRAILER_FIELD_BC = 1;

        public const uint NETSCAPE_SSL_CLIENT_AUTH_CERT_TYPE = 0x80;

        public const uint NETSCAPE_SSL_SERVER_AUTH_CERT_TYPE = 0x40;

        public const uint NETSCAPE_SMIME_CERT_TYPE = 0x20;

        public const uint NETSCAPE_SIGN_CERT_TYPE = 0x10;

        public const uint NETSCAPE_SSL_CA_CERT_TYPE = 0x04;

        public const uint NETSCAPE_SMIME_CA_CERT_TYPE = 0x02;

        public const uint NETSCAPE_SIGN_CA_CERT_TYPE = 0x01;

        public const uint CMC_TAGGED_CERT_REQUEST_CHOICE = 1;

        public const uint CMC_OTHER_INFO_NO_CHOICE = 0;

        public const uint CMC_OTHER_INFO_FAIL_CHOICE = 1;

        public const uint CMC_OTHER_INFO_PEND_CHOICE = 2;

        public const uint CMC_STATUS_SUCCESS = 0;

        public const uint CMC_STATUS_FAILED = 2;

        public const uint CMC_STATUS_PENDING = 3;

        public const uint CMC_STATUS_NO_SUPPORT = 4;

        public const uint CMC_STATUS_CONFIRM_REQUIRED = 5;

        public const uint CMC_FAIL_BAD_ALG = 0;

        public const uint CMC_FAIL_BAD_MESSAGE_CHECK = 1;

        public const uint CMC_FAIL_BAD_REQUEST = 2;

        public const uint CMC_FAIL_BAD_TIME = 3;

        public const uint CMC_FAIL_BAD_CERT_ID = 4;

        public const uint CMC_FAIL_UNSUPORTED_EXT = 5;

        public const uint CMC_FAIL_MUST_ARCHIVE_KEYS = 6;

        public const uint CMC_FAIL_BAD_IDENTITY = 7;

        public const uint CMC_FAIL_POP_REQUIRED = 8;

        public const uint CMC_FAIL_POP_FAILED = 9;

        public const uint CMC_FAIL_NO_KEY_REUSE = 10;

        public const uint CMC_FAIL_INTERNAL_CA_ERROR = 11;

        public const uint CMC_FAIL_TRY_LATER = 12;

        public const uint CERT_BIOMETRIC_PICTURE_TYPE = 0;

        public const uint CERT_BIOMETRIC_SIGNATURE_TYPE = 1;

        public const uint OCSP_REQUEST_V1 = 0;

        public const uint OCSP_SUCCESSFUL_RESPONSE = 0;

        public const uint OCSP_MALFORMED_REQUEST_RESPONSE = 1;

        public const uint OCSP_INTERNAL_ERROR_RESPONSE = 2;

        public const uint OCSP_TRY_LATER_RESPONSE = 3;

        public const uint OCSP_SIG_REQUIRED_RESPONSE = 5;

        public const uint OCSP_UNAUTHORIZED_RESPONSE = 6;

        public const uint OCSP_BASIC_GOOD_CERT_STATUS = 0;

        public const uint OCSP_BASIC_REVOKED_CERT_STATUS = 1;

        public const uint OCSP_BASIC_UNKNOWN_CERT_STATUS = 2;

        public const uint OCSP_BASIC_RESPONSE_V1 = 0;

        public const uint OCSP_BASIC_BY_NAME_RESPONDER_ID = 1;

        public const uint OCSP_BASIC_BY_KEY_RESPONDER_ID = 2;

        public const uint CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG = 1;

        public const uint CRYPT_GET_INSTALLED_OID_FUNC_FLAG = 0x1;

        public const uint CRYPT_REGISTER_FIRST_INDEX = 0;

        public const uint CRYPT_REGISTER_LAST_INDEX = 0xFFFFFFFF;

        public const uint CRYPT_MATCH_ANY_ENCODING_TYPE = 0xFFFFFFFF;

        public const uint CALG_OID_INFO_CNG_ONLY = 0xFFFFFFFF;

        public const uint CALG_OID_INFO_PARAMETERS = 0xFFFFFFFE;

        public const uint CRYPT_HASH_ALG_OID_GROUP_ID = 1;

        public const uint CRYPT_ENCRYPT_ALG_OID_GROUP_ID = 2;

        public const uint CRYPT_PUBKEY_ALG_OID_GROUP_ID = 3;

        public const uint CRYPT_SIGN_ALG_OID_GROUP_ID = 4;

        public const uint CRYPT_RDN_ATTR_OID_GROUP_ID = 5;

        public const uint CRYPT_EXT_OR_ATTR_OID_GROUP_ID = 6;

        public const uint CRYPT_ENHKEY_USAGE_OID_GROUP_ID = 7;

        public const uint CRYPT_POLICY_OID_GROUP_ID = 8;

        public const uint CRYPT_TEMPLATE_OID_GROUP_ID = 9;

        public const uint CRYPT_KDF_OID_GROUP_ID = 10;

        public const uint CRYPT_LAST_OID_GROUP_ID = 10;

        public const uint CRYPT_OID_INHIBIT_SIGNATURE_FORMAT_FLAG = 0x00000001;

        public const uint CRYPT_OID_USE_PUBKEY_PARA_FOR_PKCS7_FLAG = 0x00000002;

        public const uint CRYPT_OID_NO_NULL_ALGORITHM_PARA_FLAG = 0x00000004;

        public const uint CRYPT_OID_PUBKEY_SIGN_ONLY_FLAG = 0x80000000;

        public const uint CRYPT_OID_PUBKEY_ENCRYPT_ONLY_FLAG = 0x40000000;

        public const uint CRYPT_OID_USE_CURVE_NAME_FOR_ENCODE_FLAG = 0x20000000;

        public const uint CRYPT_OID_USE_CURVE_PARAMETERS_FOR_ENCODE_FLAG = 0x10000000;

        public const uint CRYPT_OID_INFO_OID_KEY = 1;

        public const uint CRYPT_OID_INFO_NAME_KEY = 2;

        public const uint CRYPT_OID_INFO_ALGID_KEY = 3;

        public const uint CRYPT_OID_INFO_SIGN_KEY = 4;

        public const uint CRYPT_OID_INFO_CNG_ALGID_KEY = 5;

        public const uint CRYPT_OID_INFO_CNG_SIGN_KEY = 6;

        public const uint CRYPT_OID_INFO_OID_KEY_FLAGS_MASK = 0xFFFF0000;

        public const uint CRYPT_OID_DISABLE_SEARCH_DS_FLAG = 0x80000000;

        public const uint CRYPT_OID_PREFER_CNG_ALGID_FLAG = 0x40000000;

        public const uint CRYPT_OID_INFO_OID_GROUP_BIT_LEN_MASK = 0x0FFF0000;

        public const uint CRYPT_OID_INFO_OID_GROUP_BIT_LEN_SHIFT = 16;

        public const uint CRYPT_INSTALL_OID_INFO_BEFORE_FLAG = 1;

        public const uint CRYPT_LOCALIZED_NAME_ENCODING_TYPE = 0;

        public const uint CERT_STRONG_SIGN_SERIALIZED_INFO_CHOICE = 1;

        public const uint CERT_STRONG_SIGN_OID_INFO_CHOICE = 2;

        public const uint CMSG_ENCRYPTED = 6;

        public const uint CMSG_MAIL_LIST_HANDLE_KEY_CHOICE = 1;

        public const uint CMSG_KEY_TRANS_RECIPIENT = 1;

        public const uint CMSG_KEY_AGREE_RECIPIENT = 2;

        public const uint CMSG_MAIL_LIST_RECIPIENT = 3;

        public const uint CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG = 0x80000000;

        public const uint CMSG_RC4_NO_SALT_FLAG = 0x40000000;

        public const uint CMSG_INDEFINITE_LENGTH = 0xFFFFFFFF;

        public const uint CMSG_BARE_CONTENT_FLAG = 0x00000001;

        public const uint CMSG_LENGTH_ONLY_FLAG = 0x00000002;

        public const uint CMSG_DETACHED_FLAG = 0x00000004;

        public const uint CMSG_AUTHENTICATED_ATTRIBUTES_FLAG = 0x00000008;

        public const uint CMSG_CONTENTS_OCTETS_FLAG = 0x00000010;

        public const uint CMSG_MAX_LENGTH_FLAG = 0x00000020;

        public const uint CMSG_CMS_ENCAPSULATED_CONTENT_FLAG = 0x00000040;

        public const uint CMSG_SIGNED_DATA_NO_SIGN_FLAG = 0x00000080;

        public const uint CMSG_CRYPT_RELEASE_CONTEXT_FLAG = 0x00008000;

        public const uint CMSG_TYPE_PARAM = 1;

        public const uint CMSG_CONTENT_PARAM = 2;

        public const uint CMSG_BARE_CONTENT_PARAM = 3;

        public const uint CMSG_INNER_CONTENT_TYPE_PARAM = 4;

        public const uint CMSG_SIGNER_COUNT_PARAM = 5;

        public const uint CMSG_SIGNER_INFO_PARAM = 6;

        public const uint CMSG_SIGNER_CERT_INFO_PARAM = 7;

        public const uint CMSG_SIGNER_HASH_ALGORITHM_PARAM = 8;

        public const uint CMSG_SIGNER_AUTH_ATTR_PARAM = 9;

        public const uint CMSG_SIGNER_UNAUTH_ATTR_PARAM = 10;

        public const uint CMSG_CERT_COUNT_PARAM = 11;

        public const uint CMSG_CERT_PARAM = 12;

        public const uint CMSG_CRL_COUNT_PARAM = 13;

        public const uint CMSG_CRL_PARAM = 14;

        public const uint CMSG_ENVELOPE_ALGORITHM_PARAM = 15;

        public const uint CMSG_RECIPIENT_COUNT_PARAM = 17;

        public const uint CMSG_RECIPIENT_INDEX_PARAM = 18;

        public const uint CMSG_RECIPIENT_INFO_PARAM = 19;

        public const uint CMSG_HASH_ALGORITHM_PARAM = 20;

        public const uint CMSG_HASH_DATA_PARAM = 21;

        public const uint CMSG_COMPUTED_HASH_PARAM = 22;

        public const uint CMSG_ENCRYPT_PARAM = 26;

        public const uint CMSG_ENCRYPTED_DIGEST = 27;

        public const uint CMSG_ENCODED_SIGNER = 28;

        public const uint CMSG_ENCODED_MESSAGE = 29;

        public const uint CMSG_VERSION_PARAM = 30;

        public const uint CMSG_ATTR_CERT_COUNT_PARAM = 31;

        public const uint CMSG_ATTR_CERT_PARAM = 32;

        public const uint CMSG_CMS_RECIPIENT_COUNT_PARAM = 33;

        public const uint CMSG_CMS_RECIPIENT_INDEX_PARAM = 34;

        public const uint CMSG_CMS_RECIPIENT_ENCRYPTED_KEY_INDEX_PARAM = 35;

        public const uint CMSG_CMS_RECIPIENT_INFO_PARAM = 36;

        public const uint CMSG_UNPROTECTED_ATTR_PARAM = 37;

        public const uint CMSG_SIGNER_CERT_ID_PARAM = 38;

        public const uint CMSG_CMS_SIGNER_INFO_PARAM = 39;

        public const uint CMSG_SIGNED_DATA_V1 = 1;

        public const uint CMSG_SIGNED_DATA_V3 = 3;

        public const uint CMSG_SIGNER_INFO_V1 = 1;

        public const uint CMSG_SIGNER_INFO_V3 = 3;

        public const uint CMSG_HASHED_DATA_V0 = 0;

        public const uint CMSG_HASHED_DATA_V2 = 2;

        public const uint CMSG_ENVELOPED_DATA_V0 = 0;

        public const uint CMSG_ENVELOPED_DATA_V2 = 2;

        public const uint CMSG_ENVELOPED_RECIPIENT_V0 = 0;

        public const uint CMSG_ENVELOPED_RECIPIENT_V2 = 2;

        public const uint CMSG_ENVELOPED_RECIPIENT_V3 = 3;

        public const uint CMSG_ENVELOPED_RECIPIENT_V4 = 4;

        public const uint CMSG_CTRL_VERIFY_SIGNATURE = 1;

        public const uint CMSG_CTRL_DECRYPT = 2;

        public const uint CMSG_CTRL_VERIFY_HASH = 5;

        public const uint CMSG_CTRL_ADD_SIGNER = 6;

        public const uint CMSG_CTRL_DEL_SIGNER = 7;

        public const uint CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR = 8;

        public const uint CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR = 9;

        public const uint CMSG_CTRL_ADD_CERT = 10;

        public const uint CMSG_CTRL_DEL_CERT = 11;

        public const uint CMSG_CTRL_ADD_CRL = 12;

        public const uint CMSG_CTRL_DEL_CRL = 13;

        public const uint CMSG_CTRL_ADD_ATTR_CERT = 14;

        public const uint CMSG_CTRL_DEL_ATTR_CERT = 15;

        public const uint CMSG_CTRL_KEY_TRANS_DECRYPT = 16;

        public const uint CMSG_CTRL_KEY_AGREE_DECRYPT = 17;

        public const uint CMSG_CTRL_MAIL_LIST_DECRYPT = 18;

        public const uint CMSG_CTRL_VERIFY_SIGNATURE_EX = 19;

        public const uint CMSG_CTRL_ADD_CMS_SIGNER_INFO = 20;

        public const uint CMSG_CTRL_ENABLE_STRONG_SIGNATURE = 21;

        public const uint CMSG_VERIFY_SIGNER_PUBKEY = 1;

        public const uint CMSG_VERIFY_SIGNER_CERT = 2;

        public const uint CMSG_VERIFY_SIGNER_CHAIN = 3;

        public const uint CMSG_VERIFY_SIGNER_NULL = 4;

        public const uint CMSG_VERIFY_COUNTER_SIGN_ENABLE_STRONG_FLAG = 0x00000001;

        public const uint CMSG_CONTENT_ENCRYPT_PAD_ENCODED_LEN_FLAG = 0x00000001;

        public const uint CMSG_CONTENT_ENCRYPT_FREE_PARA_FLAG = 0x00000001;

        public const uint CMSG_CONTENT_ENCRYPT_FREE_OBJID_FLAG = 0x00000002;

        public const uint CMSG_CONTENT_ENCRYPT_RELEASE_CONTEXT_FLAG = 0x00008000;

        public const uint CMSG_KEY_TRANS_ENCRYPT_FREE_PARA_FLAG = 0x00000001;

        public const uint CMSG_KEY_TRANS_ENCRYPT_FREE_OBJID_FLAG = 0x00000002;

        public const uint CMSG_KEY_AGREE_ENCRYPT_FREE_PARA_FLAG = 0x00000001;

        public const uint CMSG_KEY_AGREE_ENCRYPT_FREE_MATERIAL_FLAG = 0x00000002;

        public const uint CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_ALG_FLAG = 0x00000004;

        public const uint CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_PARA_FLAG = 0x00000008;

        public const uint CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_BITS_FLAG = 0x00000010;

        public const uint CMSG_KEY_AGREE_ENCRYPT_FREE_OBJID_FLAG = 0x00000020;

        public const uint CMSG_MAIL_LIST_ENCRYPT_FREE_PARA_FLAG = 0x00000001;

        public const uint CMSG_MAIL_LIST_ENCRYPT_FREE_OBJID_FLAG = 0x00000002;

        public const uint CERT_KEY_PROV_HANDLE_PROP_ID = 1;

        public const uint CERT_KEY_PROV_INFO_PROP_ID = 2;

        public const uint CERT_SHA1_HASH_PROP_ID = 3;

        public const uint CERT_MD5_HASH_PROP_ID = 4;

        public const uint CERT_KEY_CONTEXT_PROP_ID = 5;

        public const uint CERT_KEY_SPEC_PROP_ID = 6;

        public const uint CERT_IE30_RESERVED_PROP_ID = 7;

        public const uint CERT_PUBKEY_HASH_RESERVED_PROP_ID = 8;

        public const uint CERT_ENHKEY_USAGE_PROP_ID = 9;

        public const uint CERT_NEXT_UPDATE_LOCATION_PROP_ID = 10;

        public const uint CERT_FRIENDLY_NAME_PROP_ID = 11;

        public const uint CERT_PVK_FILE_PROP_ID = 12;

        public const uint CERT_DESCRIPTION_PROP_ID = 13;

        public const uint CERT_ACCESS_STATE_PROP_ID = 14;

        public const uint CERT_SIGNATURE_HASH_PROP_ID = 15;

        public const uint CERT_SMART_CARD_DATA_PROP_ID = 16;

        public const uint CERT_EFS_PROP_ID = 17;

        public const uint CERT_FORTEZZA_DATA_PROP_ID = 18;

        public const uint CERT_ARCHIVED_PROP_ID = 19;

        public const uint CERT_KEY_IDENTIFIER_PROP_ID = 20;

        public const uint CERT_AUTO_ENROLL_PROP_ID = 21;

        public const uint CERT_PUBKEY_ALG_PARA_PROP_ID = 22;

        public const uint CERT_CROSS_CERT_DIST_POINTS_PROP_ID = 23;

        public const uint CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID = 24;

        public const uint CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID = 25;

        public const uint CERT_ENROLLMENT_PROP_ID = 26;

        public const uint CERT_DATE_STAMP_PROP_ID = 27;

        public const uint CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID = 28;

        public const uint CERT_SUBJECT_NAME_MD5_HASH_PROP_ID = 29;

        public const uint CERT_EXTENDED_ERROR_INFO_PROP_ID = 30;

        public const uint CERT_RENEWAL_PROP_ID = 64;

        public const uint CERT_ARCHIVED_KEY_HASH_PROP_ID = 65;

        public const uint CERT_AUTO_ENROLL_RETRY_PROP_ID = 66;

        public const uint CERT_AIA_URL_RETRIEVED_PROP_ID = 67;

        public const uint CERT_AUTHORITY_INFO_ACCESS_PROP_ID = 68;

        public const uint CERT_BACKED_UP_PROP_ID = 69;

        public const uint CERT_OCSP_RESPONSE_PROP_ID = 70;

        public const uint CERT_REQUEST_ORIGINATOR_PROP_ID = 71;

        public const uint CERT_SOURCE_LOCATION_PROP_ID = 72;

        public const uint CERT_SOURCE_URL_PROP_ID = 73;

        public const uint CERT_NEW_KEY_PROP_ID = 74;

        public const uint CERT_OCSP_CACHE_PREFIX_PROP_ID = 75;

        public const uint CERT_SMART_CARD_ROOT_INFO_PROP_ID = 76;

        public const uint CERT_NO_AUTO_EXPIRE_CHECK_PROP_ID = 77;

        public const uint CERT_NCRYPT_KEY_HANDLE_PROP_ID = 78;

        public const uint CERT_HCRYPTPROV_OR_NCRYPT_KEY_HANDLE_PROP_ID = 79;

        public const uint CERT_SUBJECT_INFO_ACCESS_PROP_ID = 80;

        public const uint CERT_CA_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID = 81;

        public const uint CERT_CA_DISABLE_CRL_PROP_ID = 82;

        public const uint CERT_ROOT_PROGRAM_CERT_POLICIES_PROP_ID = 83;

        public const uint CERT_ROOT_PROGRAM_NAME_CONSTRAINTS_PROP_ID = 84;

        public const uint CERT_SUBJECT_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID = 85;

        public const uint CERT_SUBJECT_DISABLE_CRL_PROP_ID = 86;

        public const uint CERT_CEP_PROP_ID = 87;

        public const uint CERT_SIGN_HASH_CNG_ALG_PROP_ID = 89;

        public const uint CERT_SCARD_PIN_ID_PROP_ID = 90;

        public const uint CERT_SCARD_PIN_INFO_PROP_ID = 91;

        public const uint CERT_SUBJECT_PUB_KEY_BIT_LENGTH_PROP_ID = 92;

        public const uint CERT_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID = 93;

        public const uint CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID = 94;

        public const uint CERT_ISSUER_CHAIN_SIGN_HASH_CNG_ALG_PROP_ID = 95;

        public const uint CERT_ISSUER_CHAIN_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID = 96;

        public const uint CERT_NO_EXPIRE_NOTIFICATION_PROP_ID = 97;

        public const uint CERT_AUTH_ROOT_SHA256_HASH_PROP_ID = 98;

        public const uint CERT_NCRYPT_KEY_HANDLE_TRANSFER_PROP_ID = 99;

        public const uint CERT_HCRYPTPROV_TRANSFER_PROP_ID = 100;

        public const uint CERT_SMART_CARD_READER_PROP_ID = 101;

        public const uint CERT_SEND_AS_TRUSTED_ISSUER_PROP_ID = 102;

        public const uint CERT_KEY_REPAIR_ATTEMPTED_PROP_ID = 103;

        public const uint CERT_DISALLOWED_FILETIME_PROP_ID = 104;

        public const uint CERT_ROOT_PROGRAM_CHAIN_POLICIES_PROP_ID = 105;

        public const uint CERT_SMART_CARD_READER_NON_REMOVABLE_PROP_ID = 106;

        public const uint CERT_SHA256_HASH_PROP_ID = 107;

        public const uint CERT_SCEP_SERVER_CERTS_PROP_ID = 108;

        public const uint CERT_SCEP_RA_SIGNATURE_CERT_PROP_ID = 109;

        public const uint CERT_SCEP_RA_ENCRYPTION_CERT_PROP_ID = 110;

        public const uint CERT_SCEP_CA_CERT_PROP_ID = 111;

        public const uint CERT_SCEP_SIGNER_CERT_PROP_ID = 112;

        public const uint CERT_SCEP_NONCE_PROP_ID = 113;

        public const uint CERT_SCEP_ENCRYPT_HASH_CNG_ALG_PROP_ID = 114;

        public const uint CERT_SCEP_FLAGS_PROP_ID = 115;

        public const uint CERT_SCEP_GUID_PROP_ID = 116;

        public const uint CERT_SERIALIZABLE_KEY_CONTEXT_PROP_ID = 117;

        public const uint CERT_ISOLATED_KEY_PROP_ID = 118;

        public const uint CERT_SERIAL_CHAIN_PROP_ID = 119;

        public const uint CERT_KEY_CLASSIFICATION_PROP_ID = 120;

        public const uint CERT_OCSP_MUST_STAPLE_PROP_ID = 121;

        public const uint CERT_DISALLOWED_ENHKEY_USAGE_PROP_ID = 122;

        public const uint CERT_NONCOMPLIANT_ROOT_URL_PROP_ID = 123;

        public const uint CERT_PIN_SHA256_HASH_PROP_ID = 124;

        public const uint CERT_CLR_DELETE_KEY_PROP_ID = 125;

        public const uint CERT_NOT_BEFORE_FILETIME_PROP_ID = 126;

        public const uint CERT_NOT_BEFORE_ENHKEY_USAGE_PROP_ID = 127;

        public const uint CERT_FIRST_RESERVED_PROP_ID = 128;

        public const uint CERT_LAST_RESERVED_PROP_ID = 0x00007FFF;

        public const uint CERT_FIRST_USER_PROP_ID = 0x00008000;

        public const uint CERT_LAST_USER_PROP_ID = 0x0000FFFF;

        public const uint CERT_ACCESS_STATE_WRITE_PERSIST_FLAG = 0x1;

        public const uint CERT_ACCESS_STATE_SYSTEM_STORE_FLAG = 0x2;

        public const uint CERT_ACCESS_STATE_LM_SYSTEM_STORE_FLAG = 0x4;

        public const uint CERT_ACCESS_STATE_GP_SYSTEM_STORE_FLAG = 0x8;

        public const uint CERT_ACCESS_STATE_SHARED_USER_FLAG = 0x10;

        public const uint CERT_STORE_SIGNATURE_FLAG = 0x00000001;

        public const uint CERT_STORE_TIME_VALIDITY_FLAG = 0x00000002;

        public const uint CERT_STORE_REVOCATION_FLAG = 0x00000004;

        public const uint CERT_STORE_NO_CRL_FLAG = 0x00010000;

        public const uint CERT_STORE_NO_ISSUER_FLAG = 0x00020000;

        public const uint CERT_STORE_BASE_CRL_FLAG = 0x00000100;

        public const uint CERT_STORE_DELTA_CRL_FLAG = 0x00000200;

        public const uint CERT_STORE_UNSAFE_PHYSICAL_FLAG = 0x00000020;

        public const uint CERT_STORE_SHARE_STORE_FLAG = 0x00000040;

        public const uint CERT_STORE_MANIFOLD_FLAG = 0x00000100;

        public const uint CERT_SYSTEM_STORE_MASK = 0xFFFF0000;

        public const uint CERT_SYSTEM_STORE_UNPROTECTED_FLAG = 0x40000000;

        public const uint CERT_SYSTEM_STORE_DEFER_READ_FLAG = 0x20000000;

        public const uint CERT_SYSTEM_STORE_LOCATION_SHIFT = 16;

        public const uint CERT_SYSTEM_STORE_CURRENT_USER_ID = 1;

        public const uint CERT_SYSTEM_STORE_LOCAL_MACHINE_ID = 2;

        public const uint CERT_SYSTEM_STORE_CURRENT_SERVICE_ID = 4;

        public const uint CERT_SYSTEM_STORE_SERVICES_ID = 5;

        public const uint CERT_SYSTEM_STORE_USERS_ID = 6;

        public const uint CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID = 7;

        public const uint CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID = 8;

        public const uint CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID = 9;

        public const uint CERT_SYSTEM_STORE_LOCAL_MACHINE_WCOS_ID = 10;

        public const uint CERT_PROT_ROOT_DISABLE_CURRENT_USER_FLAG = 0x1;

        public const uint CERT_PROT_ROOT_INHIBIT_ADD_AT_INIT_FLAG = 0x2;

        public const uint CERT_PROT_ROOT_INHIBIT_PURGE_LM_FLAG = 0x4;

        public const uint CERT_PROT_ROOT_DISABLE_LM_AUTH_FLAG = 0x8;

        public const uint CERT_PROT_ROOT_ONLY_LM_GPT_FLAG = 0x8;

        public const uint CERT_PROT_ROOT_DISABLE_NT_AUTH_REQUIRED_FLAG = 0x10;

        public const uint CERT_PROT_ROOT_DISABLE_NOT_DEFINED_NAME_CONSTRAINT_FLAG = 0x20;

        public const uint CERT_PROT_ROOT_DISABLE_PEER_TRUST = 0x10000;

        public const uint CERT_TRUST_PUB_ALLOW_TRUST_MASK = 0x00000003;

        public const uint CERT_TRUST_PUB_ALLOW_END_USER_TRUST = 0x00000000;

        public const uint CERT_TRUST_PUB_ALLOW_MACHINE_ADMIN_TRUST = 0x00000001;

        public const uint CERT_TRUST_PUB_ALLOW_ENTERPRISE_ADMIN_TRUST = 0x00000002;

        public const uint CERT_TRUST_PUB_CHECK_PUBLISHER_REV_FLAG = 0x00000100;

        public const uint CERT_TRUST_PUB_CHECK_TIMESTAMP_REV_FLAG = 0x00000200;

        public const uint CERT_AUTH_ROOT_AUTO_UPDATE_DISABLE_UNTRUSTED_ROOT_LOGGING_FLAG = 0x1;

        public const uint CERT_AUTH_ROOT_AUTO_UPDATE_DISABLE_PARTIAL_CHAIN_LOGGING_FLAG = 0x2;

        public const uint CERT_AUTO_UPDATE_DISABLE_RANDOM_QUERY_STRING_FLAG = 0x4;

        public const uint CERT_REGISTRY_STORE_REMOTE_FLAG = 0x10000;

        public const uint CERT_REGISTRY_STORE_SERIALIZED_FLAG = 0x20000;

        public const uint CERT_REGISTRY_STORE_CLIENT_GPT_FLAG = 0x80000000;

        public const uint CERT_REGISTRY_STORE_LM_GPT_FLAG = 0x01000000;

        public const uint CERT_REGISTRY_STORE_ROAMING_FLAG = 0x40000;

        public const uint CERT_REGISTRY_STORE_MY_IE_DIRTY_FLAG = 0x80000;

        public const uint CERT_REGISTRY_STORE_EXTERNAL_FLAG = 0x100000;

        public const uint CERT_FILE_STORE_COMMIT_ENABLE_FLAG = 0x10000;

        public const uint CERT_LDAP_STORE_SIGN_FLAG = 0x10000;

        public const uint CERT_LDAP_STORE_AREC_EXCLUSIVE_FLAG = 0x20000;

        public const uint CERT_LDAP_STORE_OPENED_FLAG = 0x40000;

        public const uint CERT_LDAP_STORE_UNBIND_FLAG = 0x80000;

        public const uint CERT_STORE_PROV_GP_SYSTEM_STORE_FLAG = 0x20;

        public const uint CERT_STORE_PROV_SHARED_USER_FLAG = 0x40;

        public const uint CERT_STORE_PROV_CLOSE_FUNC = 0;

        public const uint CERT_STORE_PROV_READ_CERT_FUNC = 1;

        public const uint CERT_STORE_PROV_WRITE_CERT_FUNC = 2;

        public const uint CERT_STORE_PROV_DELETE_CERT_FUNC = 3;

        public const uint CERT_STORE_PROV_SET_CERT_PROPERTY_FUNC = 4;

        public const uint CERT_STORE_PROV_READ_CRL_FUNC = 5;

        public const uint CERT_STORE_PROV_WRITE_CRL_FUNC = 6;

        public const uint CERT_STORE_PROV_DELETE_CRL_FUNC = 7;

        public const uint CERT_STORE_PROV_SET_CRL_PROPERTY_FUNC = 8;

        public const uint CERT_STORE_PROV_READ_CTL_FUNC = 9;

        public const uint CERT_STORE_PROV_WRITE_CTL_FUNC = 10;

        public const uint CERT_STORE_PROV_DELETE_CTL_FUNC = 11;

        public const uint CERT_STORE_PROV_SET_CTL_PROPERTY_FUNC = 12;

        public const uint CERT_STORE_PROV_CONTROL_FUNC = 13;

        public const uint CERT_STORE_PROV_FIND_CERT_FUNC = 14;

        public const uint CERT_STORE_PROV_FREE_FIND_CERT_FUNC = 15;

        public const uint CERT_STORE_PROV_GET_CERT_PROPERTY_FUNC = 16;

        public const uint CERT_STORE_PROV_FIND_CRL_FUNC = 17;

        public const uint CERT_STORE_PROV_FREE_FIND_CRL_FUNC = 18;

        public const uint CERT_STORE_PROV_GET_CRL_PROPERTY_FUNC = 19;

        public const uint CERT_STORE_PROV_FIND_CTL_FUNC = 20;

        public const uint CERT_STORE_PROV_FREE_FIND_CTL_FUNC = 21;

        public const uint CERT_STORE_PROV_GET_CTL_PROPERTY_FUNC = 22;

        public const uint CERT_STORE_PROV_WRITE_ADD_FLAG = 0x1;

        public const uint CERT_STORE_SAVE_AS_PKCS12 = 3;

        public const uint CERT_CLOSE_STORE_FORCE_FLAG = 0x00000001;

        public const uint CERT_CLOSE_STORE_CHECK_FLAG = 0x00000002;

        public const uint CERT_COMPARE_MASK = 0xFFFF;

        public const uint CERT_COMPARE_ANY = 0;

        public const uint CERT_COMPARE_SHA1_HASH = 1;

        public const uint CERT_COMPARE_NAME = 2;

        public const uint CERT_COMPARE_ATTR = 3;

        public const uint CERT_COMPARE_MD5_HASH = 4;

        public const uint CERT_COMPARE_PROPERTY = 5;

        public const uint CERT_COMPARE_PUBLIC_KEY = 6;

        public const uint CERT_COMPARE_NAME_STR_A = 7;

        public const uint CERT_COMPARE_NAME_STR_W = 8;

        public const uint CERT_COMPARE_KEY_SPEC = 9;

        public const uint CERT_COMPARE_ENHKEY_USAGE = 10;

        public const uint CERT_COMPARE_SUBJECT_CERT = 11;

        public const uint CERT_COMPARE_ISSUER_OF = 12;

        public const uint CERT_COMPARE_EXISTING = 13;

        public const uint CERT_COMPARE_SIGNATURE_HASH = 14;

        public const uint CERT_COMPARE_KEY_IDENTIFIER = 15;

        public const uint CERT_COMPARE_CERT_ID = 16;

        public const uint CERT_COMPARE_CROSS_CERT_DIST_POINTS = 17;

        public const uint CERT_COMPARE_PUBKEY_MD5_HASH = 18;

        public const uint CERT_COMPARE_SUBJECT_INFO_ACCESS = 19;

        public const uint CERT_COMPARE_HASH_STR = 20;

        public const uint CERT_COMPARE_HAS_PRIVATE_KEY = 21;

        public const uint CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG = 0x80000000;

        public const uint CERT_SET_PROPERTY_INHIBIT_PERSIST_FLAG = 0x40000000;

        public const uint CTL_ENTRY_FROM_PROP_CHAIN_FLAG = 0x1;

        public const uint CRL_FIND_ANY = 0;

        public const uint CRL_FIND_ISSUED_BY = 1;

        public const uint CRL_FIND_EXISTING = 2;

        public const uint CRL_FIND_ISSUED_FOR = 3;

        public const uint CRL_FIND_ISSUED_BY_AKI_FLAG = 0x1;

        public const uint CRL_FIND_ISSUED_BY_SIGNATURE_FLAG = 0x2;

        public const uint CRL_FIND_ISSUED_BY_DELTA_FLAG = 0x4;

        public const uint CRL_FIND_ISSUED_BY_BASE_FLAG = 0x8;

        public const uint CRL_FIND_ISSUED_FOR_SET_STRONG_PROPERTIES_FLAG = 0x10;

        public const uint CERT_STORE_ADD_NEW = 1;

        public const uint CERT_STORE_ADD_USE_EXISTING = 2;

        public const uint CERT_STORE_ADD_REPLACE_EXISTING = 3;

        public const uint CERT_STORE_ADD_ALWAYS = 4;

        public const uint CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES = 5;

        public const uint CERT_STORE_ADD_NEWER = 6;

        public const uint CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES = 7;

        public const uint CERT_STORE_CERTIFICATE_CONTEXT = 1;

        public const uint CERT_STORE_CRL_CONTEXT = 2;

        public const uint CERT_STORE_CTL_CONTEXT = 3;

        public const uint CTL_ANY_SUBJECT_TYPE = 1;

        public const uint CTL_CERT_SUBJECT_TYPE = 2;

        public const uint CTL_FIND_NO_LIST_ID_CBDATA = 0xFFFFFFFF;

        public const uint CERT_STORE_CTRL_RESYNC = 1;

        public const uint CERT_STORE_CTRL_NOTIFY_CHANGE = 2;

        public const uint CERT_STORE_CTRL_COMMIT = 3;

        public const uint CERT_STORE_CTRL_AUTO_RESYNC = 4;

        public const uint CERT_STORE_CTRL_CANCEL_NOTIFY = 5;

        public const uint CERT_STORE_LOCALIZED_NAME_PROP_ID = 0x1000;

        public const uint CERT_CREATE_CONTEXT_NOCOPY_FLAG = 0x1;

        public const uint CERT_CREATE_CONTEXT_SORTED_FLAG = 0x2;

        public const uint CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG = 0x4;

        public const uint CERT_CREATE_CONTEXT_NO_ENTRY_FLAG = 0x8;

        public const uint CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG = 0x1;

        public const uint CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG = 0x2;

        public const uint CERT_PHYSICAL_STORE_REMOTE_OPEN_DISABLE_FLAG = 0x4;

        public const uint CERT_PHYSICAL_STORE_INSERT_COMPUTER_NAME_ENABLE_FLAG = 0x8;

        public const uint CERT_PHYSICAL_STORE_PREDEFINED_ENUM_FLAG = 0x1;

        public const uint CMSG_TRUSTED_SIGNER_FLAG = 0x1;

        public const uint CMSG_SIGNER_ONLY_FLAG = 0x2;

        public const uint CMSG_USE_SIGNER_INDEX_FLAG = 0x4;

        public const uint CMSG_CMS_ENCAPSULATED_CTL_FLAG = 0x00008000;

        public const uint CMSG_ENCODE_SORTED_CTL_FLAG = 0x1;

        public const uint CMSG_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG = 0x2;

        public const uint CERT_VERIFY_INHIBIT_CTL_UPDATE_FLAG = 0x1;

        public const uint CERT_VERIFY_TRUSTED_SIGNERS_FLAG = 0x2;

        public const uint CERT_VERIFY_NO_TIME_CHECK_FLAG = 0x4;

        public const uint CERT_VERIFY_ALLOW_MORE_USAGE_FLAG = 0x8;

        public const uint CERT_VERIFY_UPDATED_CTL_FLAG = 0x1;

        public const uint CERT_CONTEXT_REVOCATION_TYPE = 1;

        public const uint CERT_VERIFY_REV_CHAIN_FLAG = 0x00000001;

        public const uint CERT_VERIFY_CACHE_ONLY_BASED_REVOCATION = 0x00000002;

        public const uint CERT_VERIFY_REV_ACCUMULATIVE_TIMEOUT_FLAG = 0x00000004;

        public const uint CERT_VERIFY_REV_SERVER_OCSP_FLAG = 0x00000008;

        public const uint CERT_VERIFY_REV_NO_OCSP_FAILOVER_TO_CRL_FLAG = 0x00000010;

        public const uint CERT_VERIFY_REV_SERVER_OCSP_WIRE_ONLY_FLAG = 0x00000020;

        public const uint CERT_UNICODE_IS_RDN_ATTRS_FLAG = 0x1;

        public const uint CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG = 0x2;

        public const uint CRYPT_VERIFY_CERT_SIGN_SUBJECT_BLOB = 1;

        public const uint CRYPT_VERIFY_CERT_SIGN_SUBJECT_CERT = 2;

        public const uint CRYPT_VERIFY_CERT_SIGN_SUBJECT_CRL = 3;

        public const uint CRYPT_VERIFY_CERT_SIGN_SUBJECT_OCSP_BASIC_SIGNED_RESPONSE = 4;

        public const uint CRYPT_VERIFY_CERT_SIGN_ISSUER_PUBKEY = 1;

        public const uint CRYPT_VERIFY_CERT_SIGN_ISSUER_CERT = 2;

        public const uint CRYPT_VERIFY_CERT_SIGN_ISSUER_CHAIN = 3;

        public const uint CRYPT_VERIFY_CERT_SIGN_ISSUER_NULL = 4;

        public const uint CRYPT_VERIFY_CERT_SIGN_CHECK_WEAK_HASH_FLAG = 0x00000008;

        public const uint CRYPT_ACQUIRE_WINDOW_HANDLE_FLAG = 0x00000080;

        public const uint CRYPT_ACQUIRE_NCRYPT_KEY_FLAGS_MASK = 0x00070000;

        public const uint CRYPT_ACQUIRE_ALLOW_NCRYPT_KEY_FLAG = 0x00010000;

        public const uint CRYPT_ACQUIRE_PREFER_NCRYPT_KEY_FLAG = 0x00020000;

        public const uint CRYPT_ACQUIRE_ONLY_NCRYPT_KEY_FLAG = 0x00040000;

        public const uint CERT_XML_NAME_STR = 4;

        public const uint CERT_NAME_STR_SEMICOLON_FLAG = 0x40000000;

        public const uint CERT_NAME_STR_NO_PLUS_FLAG = 0x20000000;

        public const uint CERT_NAME_STR_NO_QUOTING_FLAG = 0x10000000;

        public const uint CERT_NAME_STR_CRLF_FLAG = 0x08000000;

        public const uint CERT_NAME_STR_COMMA_FLAG = 0x04000000;

        public const uint CERT_NAME_STR_REVERSE_FLAG = 0x02000000;

        public const uint CERT_NAME_STR_FORWARD_FLAG = 0x01000000;

        public const uint CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG = 0x00010000;

        public const uint CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG = 0x00020000;

        public const uint CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG = 0x00040000;

        public const uint CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG = 0x00080000;

        public const uint CERT_NAME_STR_DISABLE_UTF8_DIR_STR_FLAG = 0x00100000;

        public const uint CERT_NAME_STR_ENABLE_PUNYCODE_FLAG = 0x00200000;

        public const uint CERT_NAME_EMAIL_TYPE = 1;

        public const uint CERT_NAME_RDN_TYPE = 2;

        public const uint CERT_NAME_ATTR_TYPE = 3;

        public const uint CERT_NAME_SIMPLE_DISPLAY_TYPE = 4;

        public const uint CERT_NAME_FRIENDLY_DISPLAY_TYPE = 5;

        public const uint CERT_NAME_DNS_TYPE = 6;

        public const uint CERT_NAME_URL_TYPE = 7;

        public const uint CERT_NAME_UPN_TYPE = 8;

        public const uint CERT_NAME_ISSUER_FLAG = 0x1;

        public const uint CERT_NAME_DISABLE_IE4_UTF8_FLAG = 0x00010000;

        public const uint CERT_NAME_SEARCH_ALL_NAMES_FLAG = 0x2;

        public const uint CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG = 0x00000001;

        public const uint CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG = 0x00000002;

        public const uint CRYPT_MESSAGE_KEYID_SIGNER_FLAG = 0x00000004;

        public const uint CRYPT_MESSAGE_SILENT_KEYSET_FLAG = 0x00000040;

        public const uint CRYPT_MESSAGE_KEYID_RECIPIENT_FLAG = 0x4;

        public const uint CRYPT_RETRIEVE_MULTIPLE_OBJECTS = 0x00000001;

        public const uint CRYPT_CACHE_ONLY_RETRIEVAL = 0x00000002;

        public const uint CRYPT_WIRE_ONLY_RETRIEVAL = 0x00000004;

        public const uint CRYPT_DONT_CACHE_RESULT = 0x00000008;

        public const uint CRYPT_ASYNC_RETRIEVAL = 0x00000010;

        public const uint CRYPT_STICKY_CACHE_RETRIEVAL = 0x00001000;

        public const uint CRYPT_LDAP_SCOPE_BASE_ONLY_RETRIEVAL = 0x00002000;

        public const uint CRYPT_OFFLINE_CHECK_RETRIEVAL = 0x00004000;

        public const uint CRYPT_LDAP_INSERT_ENTRY_ATTRIBUTE = 0x00008000;

        public const uint CRYPT_LDAP_SIGN_RETRIEVAL = 0x00010000;

        public const uint CRYPT_NO_AUTH_RETRIEVAL = 0x00020000;

        public const uint CRYPT_LDAP_AREC_EXCLUSIVE_RETRIEVAL = 0x00040000;

        public const uint CRYPT_AIA_RETRIEVAL = 0x00080000;

        public const uint CRYPT_HTTP_POST_RETRIEVAL = 0x00100000;

        public const uint CRYPT_PROXY_CACHE_RETRIEVAL = 0x00200000;

        public const uint CRYPT_NOT_MODIFIED_RETRIEVAL = 0x00400000;

        public const uint CRYPT_ENABLE_SSL_REVOCATION_RETRIEVAL = 0x00800000;

        public const uint CRYPT_RANDOM_QUERY_STRING_RETRIEVAL = 0x04000000;

        public const uint CRYPT_ENABLE_FILE_RETRIEVAL = 0x08000000;

        public const uint CRYPT_CREATE_NEW_FLUSH_ENTRY = 0x10000000;

        public const uint CRYPT_VERIFY_CONTEXT_SIGNATURE = 0x00000020;

        public const uint CRYPT_VERIFY_DATA_HASH = 0x00000040;

        public const uint CRYPT_KEEP_TIME_VALID = 0x00000080;

        public const uint CRYPT_DONT_VERIFY_SIGNATURE = 0x00000100;

        public const uint CRYPT_DONT_CHECK_TIME_VALIDITY = 0x00000200;

        public const uint CRYPT_CHECK_FRESHNESS_TIME_VALIDITY = 0x00000400;

        public const uint CRYPT_ACCUMULATIVE_TIMEOUT = 0x00000800;

        public const uint CRYPT_OCSP_ONLY_RETRIEVAL = 0x01000000;

        public const uint CRYPT_NO_OCSP_FAILOVER_TO_CRL_RETRIEVAL = 0x02000000;

        public const uint CRYPTNET_URL_CACHE_PRE_FETCH_NONE = 0;

        public const uint CRYPTNET_URL_CACHE_PRE_FETCH_BLOB = 1;

        public const uint CRYPTNET_URL_CACHE_PRE_FETCH_CRL = 2;

        public const uint CRYPTNET_URL_CACHE_PRE_FETCH_OCSP = 3;

        public const uint CRYPTNET_URL_CACHE_PRE_FETCH_AUTOROOT_CAB = 5;

        public const uint CRYPTNET_URL_CACHE_PRE_FETCH_DISALLOWED_CERT_CAB = 6;

        public const uint CRYPTNET_URL_CACHE_PRE_FETCH_PIN_RULES_CAB = 7;

        public const uint CRYPTNET_URL_CACHE_DEFAULT_FLUSH = 0;

        public const uint CRYPTNET_URL_CACHE_DISABLE_FLUSH = 0xFFFFFFFF;

        public const uint CRYPTNET_URL_CACHE_RESPONSE_NONE = 0;

        public const uint CRYPTNET_URL_CACHE_RESPONSE_HTTP = 1;

        public const uint CRYPTNET_URL_CACHE_RESPONSE_VALIDATED = 0x8000;

        public const uint CRYPT_RETRIEVE_MAX_ERROR_CONTENT_LENGTH = 0x1000;

        public const uint CRYPT_KEYID_MACHINE_FLAG = 0x00000020;

        public const uint CRYPT_KEYID_ALLOC_FLAG = 0x00008000;

        public const uint CRYPT_KEYID_DELETE_FLAG = 0x00000010;

        public const uint CRYPT_KEYID_SET_NEW_FLAG = 0x00002000;

        public const uint CERT_CHAIN_MAX_AIA_URL_COUNT_IN_CERT_DEFAULT = 5;

        public const uint CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_COUNT_PER_CHAIN_DEFAULT = 3;

        public const uint CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_BYTE_COUNT_DEFAULT = 100000;

        public const uint CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_CERT_COUNT_DEFAULT = 10;

        public const uint CERT_CHAIN_MAX_SSL_TIME_UPDATED_EVENT_COUNT_DEFAULT = 5;

        public const uint CERT_CHAIN_MAX_SSL_TIME_UPDATED_EVENT_COUNT_DISABLE = 0xFFFFFFFF;

        public const uint CERT_CHAIN_ENABLE_MD2_MD4_FLAG = 0x00000001;

        public const uint CERT_CHAIN_ENABLE_WEAK_RSA_ROOT_FLAG = 0x00000002;

        public const uint CERT_CHAIN_ENABLE_WEAK_LOGGING_FLAG = 0x00000004;

        public const uint CERT_CHAIN_ENABLE_ONLY_WEAK_LOGGING_FLAG = 0x00000008;

        public const uint CERT_CHAIN_MIN_RSA_PUB_KEY_BIT_LENGTH_DEFAULT = 1023;

        public const uint CERT_CHAIN_MIN_RSA_PUB_KEY_BIT_LENGTH_DISABLE = 0xFFFFFFFF;

        public const uint CERT_CHAIN_MIN_PUB_KEY_BIT_LENGTH_DISABLE = 0xFFFFFFFF;

        public const uint CERT_CHAIN_ENABLE_WEAK_SETTINGS_FLAG = 0x80000000;

        public const uint CERT_CHAIN_DISABLE_ALL_EKU_WEAK_FLAG = 0x00010000;

        public const uint CERT_CHAIN_ENABLE_ALL_EKU_HYGIENE_FLAG = 0x00020000;

        public const uint CERT_CHAIN_DISABLE_OPT_IN_SERVER_AUTH_WEAK_FLAG = 0x00040000;

        public const uint CERT_CHAIN_DISABLE_SERVER_AUTH_WEAK_FLAG = 0x00100000;

        public const uint CERT_CHAIN_ENABLE_SERVER_AUTH_HYGIENE_FLAG = 0x00200000;

        public const uint CERT_CHAIN_DISABLE_CODE_SIGNING_WEAK_FLAG = 0x00400000;

        public const uint CERT_CHAIN_DISABLE_MOTW_CODE_SIGNING_WEAK_FLAG = 0x00800000;

        public const uint CERT_CHAIN_ENABLE_CODE_SIGNING_HYGIENE_FLAG = 0x01000000;

        public const uint CERT_CHAIN_ENABLE_MOTW_CODE_SIGNING_HYGIENE_FLAG = 0x02000000;

        public const uint CERT_CHAIN_DISABLE_TIMESTAMP_WEAK_FLAG = 0x04000000;

        public const uint CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_WEAK_FLAG = 0x08000000;

        public const uint CERT_CHAIN_ENABLE_TIMESTAMP_HYGIENE_FLAG = 0x10000000;

        public const uint CERT_CHAIN_ENABLE_MOTW_TIMESTAMP_HYGIENE_FLAG = 0x20000000;

        public const uint CERT_CHAIN_MOTW_IGNORE_AFTER_TIME_WEAK_FLAG = 0x40000000;

        public const uint CERT_CHAIN_DISABLE_FILE_HASH_WEAK_FLAG = 0x00001000;

        public const uint CERT_CHAIN_DISABLE_MOTW_FILE_HASH_WEAK_FLAG = 0x00002000;

        public const uint CERT_CHAIN_DISABLE_TIMESTAMP_HASH_WEAK_FLAG = 0x00004000;

        public const uint CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_HASH_WEAK_FLAG = 0x00008000;

        public const uint CERT_CHAIN_AUTO_CURRENT_USER = 1;

        public const uint CERT_CHAIN_AUTO_LOCAL_MACHINE = 2;

        public const uint CERT_CHAIN_AUTO_IMPERSONATED = 3;

        public const uint CERT_CHAIN_AUTO_PROCESS_INFO = 4;

        public const uint CERT_CHAIN_AUTO_PINRULE_INFO = 5;

        public const uint CERT_CHAIN_AUTO_NETWORK_INFO = 6;

        public const uint CERT_CHAIN_AUTO_SERIAL_LOCAL_MACHINE = 7;

        public const uint CERT_CHAIN_AUTO_HPKP_RULE_INFO = 8;

        public const uint CERT_CHAIN_AUTO_FLUSH_DISABLE_FLAG = 0x00000001;

        public const uint CERT_CHAIN_AUTO_LOG_CREATE_FLAG = 0x00000002;

        public const uint CERT_CHAIN_AUTO_LOG_FREE_FLAG = 0x00000004;

        public const uint CERT_CHAIN_AUTO_LOG_FLUSH_FLAG = 0x00000008;

        public const uint CERT_SRV_OCSP_RESP_MIN_SYNC_CERT_FILE_SECONDS_DEFAULT = 5;

        public const uint CRYPTNET_MAX_CACHED_OCSP_PER_CRL_COUNT_DEFAULT = 500;

        public const uint CRYPTNET_OCSP_AFTER_CRL_DISABLE = 0xFFFFFFFF;

        public const uint CRYPTNET_PRE_FETCH_AFTER_PUBLISH_PRE_FETCH_DIVISOR_DEFAULT = 10;

        public const uint CRYPTNET_PRE_FETCH_BEFORE_NEXT_UPDATE_PRE_FETCH_DIVISOR_DEFAULT = 20;

        public const uint CRYPTNET_PRE_FETCH_VALIDITY_PERIOD_AFTER_NEXT_UPDATE_PRE_FETCH_DIVISOR_DEFAULT = 10;

        public const uint CRYPTNET_PRE_FETCH_TRIGGER_DISABLE = 0xFFFFFFFF;

        public const uint CRYPTNET_PRE_FETCH_SCAN_AFTER_TRIGGER_DELAY_SECONDS_DEFAULT = 60;

        public const uint CRYPTNET_CACHED_OCSP_SWITCH_TO_CRL_COUNT_DEFAULT = 50;

        public const uint CRYPTNET_CRL_BEFORE_OCSP_ENABLE = 0xFFFFFFFF;

        public const uint CERT_CHAIN_OPTION_DISABLE_AIA_URL_RETRIEVAL = 0x2;

        public const uint CERT_CHAIN_OPTION_ENABLE_SIA_URL_RETRIEVAL = 0x4;

        public const uint CERT_CHAIN_CRL_VALIDITY_EXT_PERIOD_HOURS_DEFAULT = 12;

        public const uint CERT_CHAIN_CACHE_END_CERT = 0x00000001;

        public const uint CERT_CHAIN_THREAD_STORE_SYNC = 0x00000002;

        public const uint CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL = 0x00000004;

        public const uint CERT_CHAIN_USE_LOCAL_MACHINE_STORE = 0x00000008;

        public const uint CERT_CHAIN_ENABLE_CACHE_AUTO_UPDATE = 0x00000010;

        public const uint CERT_CHAIN_ENABLE_SHARE_STORE = 0x00000020;

        public const uint CERT_CHAIN_EXCLUSIVE_ENABLE_CA_FLAG = 0x00000001;

        public const uint CERT_TRUST_NO_ERROR = 0x00000000;

        public const uint CERT_TRUST_IS_NOT_TIME_VALID = 0x00000001;

        public const uint CERT_TRUST_IS_NOT_TIME_NESTED = 0x00000002;

        public const uint CERT_TRUST_IS_REVOKED = 0x00000004;

        public const uint CERT_TRUST_IS_NOT_SIGNATURE_VALID = 0x00000008;

        public const uint CERT_TRUST_IS_NOT_VALID_FOR_USAGE = 0x00000010;

        public const uint CERT_TRUST_IS_UNTRUSTED_ROOT = 0x00000020;

        public const uint CERT_TRUST_REVOCATION_STATUS_UNKNOWN = 0x00000040;

        public const uint CERT_TRUST_IS_CYCLIC = 0x00000080;

        public const uint CERT_TRUST_INVALID_EXTENSION = 0x00000100;

        public const uint CERT_TRUST_INVALID_POLICY_CONSTRAINTS = 0x00000200;

        public const uint CERT_TRUST_INVALID_BASIC_CONSTRAINTS = 0x00000400;

        public const uint CERT_TRUST_INVALID_NAME_CONSTRAINTS = 0x00000800;

        public const uint CERT_TRUST_HAS_NOT_SUPPORTED_NAME_CONSTRAINT = 0x00001000;

        public const uint CERT_TRUST_HAS_NOT_DEFINED_NAME_CONSTRAINT = 0x00002000;

        public const uint CERT_TRUST_HAS_NOT_PERMITTED_NAME_CONSTRAINT = 0x00004000;

        public const uint CERT_TRUST_HAS_EXCLUDED_NAME_CONSTRAINT = 0x00008000;

        public const uint CERT_TRUST_IS_OFFLINE_REVOCATION = 0x01000000;

        public const uint CERT_TRUST_NO_ISSUANCE_CHAIN_POLICY = 0x02000000;

        public const uint CERT_TRUST_IS_EXPLICIT_DISTRUST = 0x04000000;

        public const uint CERT_TRUST_HAS_NOT_SUPPORTED_CRITICAL_EXT = 0x08000000;

        public const uint CERT_TRUST_HAS_WEAK_SIGNATURE = 0x00100000;

        public const uint CERT_TRUST_HAS_WEAK_HYGIENE = 0x00200000;

        public const uint CERT_TRUST_IS_PARTIAL_CHAIN = 0x00010000;

        public const uint CERT_TRUST_CTL_IS_NOT_TIME_VALID = 0x00020000;

        public const uint CERT_TRUST_CTL_IS_NOT_SIGNATURE_VALID = 0x00040000;

        public const uint CERT_TRUST_CTL_IS_NOT_VALID_FOR_USAGE = 0x00080000;

        public const uint CERT_TRUST_HAS_EXACT_MATCH_ISSUER = 0x00000001;

        public const uint CERT_TRUST_HAS_KEY_MATCH_ISSUER = 0x00000002;

        public const uint CERT_TRUST_HAS_NAME_MATCH_ISSUER = 0x00000004;

        public const uint CERT_TRUST_IS_SELF_SIGNED = 0x00000008;

        public const uint CERT_TRUST_AUTO_UPDATE_CA_REVOCATION = 0x00000010;

        public const uint CERT_TRUST_AUTO_UPDATE_END_REVOCATION = 0x00000020;

        public const uint CERT_TRUST_NO_OCSP_FAILOVER_TO_CRL = 0x00000040;

        public const uint CERT_TRUST_IS_KEY_ROLLOVER = 0x00000080;

        public const uint CERT_TRUST_SSL_HANDSHAKE_OCSP = 0x00040000;

        public const uint CERT_TRUST_SSL_TIME_VALID_OCSP = 0x00080000;

        public const uint CERT_TRUST_SSL_RECONNECT_OCSP = 0x00100000;

        public const uint CERT_TRUST_HAS_PREFERRED_ISSUER = 0x00000100;

        public const uint CERT_TRUST_HAS_ISSUANCE_CHAIN_POLICY = 0x00000200;

        public const uint CERT_TRUST_HAS_VALID_NAME_CONSTRAINTS = 0x00000400;

        public const uint CERT_TRUST_IS_PEER_TRUSTED = 0x00000800;

        public const uint CERT_TRUST_HAS_CRL_VALIDITY_EXTENDED = 0x00001000;

        public const uint CERT_TRUST_IS_FROM_EXCLUSIVE_TRUST_STORE = 0x00002000;

        public const uint CERT_TRUST_IS_CA_TRUSTED = 0x00004000;

        public const uint CERT_TRUST_HAS_AUTO_UPDATE_WEAK_SIGNATURE = 0x00008000;

        public const uint CERT_TRUST_HAS_ALLOW_WEAK_SIGNATURE = 0x00020000;

        public const uint CERT_TRUST_IS_COMPLEX_CHAIN = 0x00010000;

        public const uint CERT_TRUST_SSL_TIME_VALID = 0x01000000;

        public const uint CERT_TRUST_NO_TIME_CHECK = 0x02000000;

        public const uint USAGE_MATCH_TYPE_AND = 0x00000000;

        public const uint USAGE_MATCH_TYPE_OR = 0x00000001;

        public const uint CERT_CHAIN_STRONG_SIGN_DISABLE_END_CHECK_FLAG = 0x00000001;

        public const uint CERT_CHAIN_REVOCATION_CHECK_END_CERT = 0x10000000;

        public const uint CERT_CHAIN_REVOCATION_CHECK_CHAIN = 0x20000000;

        public const uint CERT_CHAIN_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT = 0x40000000;

        public const uint CERT_CHAIN_REVOCATION_CHECK_CACHE_ONLY = 0x80000000;

        public const uint CERT_CHAIN_REVOCATION_ACCUMULATIVE_TIMEOUT = 0x08000000;

        public const uint CERT_CHAIN_REVOCATION_CHECK_OCSP_CERT = 0x04000000;

        public const uint CERT_CHAIN_DISABLE_PASS1_QUALITY_FILTERING = 0x00000040;

        public const uint CERT_CHAIN_RETURN_LOWER_QUALITY_CONTEXTS = 0x00000080;

        public const uint CERT_CHAIN_DISABLE_AUTH_ROOT_AUTO_UPDATE = 0x00000100;

        public const uint CERT_CHAIN_TIMESTAMP_TIME = 0x00000200;

        public const uint CERT_CHAIN_ENABLE_PEER_TRUST = 0x00000400;

        public const uint CERT_CHAIN_DISABLE_MY_PEER_TRUST = 0x00000800;

        public const uint CERT_CHAIN_DISABLE_MD2_MD4 = 0x00001000;

        public const uint CERT_CHAIN_DISABLE_AIA = 0x00002000;

        public const uint CERT_CHAIN_HAS_MOTW = 0x00004000;

        public const uint CERT_CHAIN_ONLY_ADDITIONAL_AND_AUTH_ROOT = 0x00008000;

        public const uint CERT_CHAIN_OPT_IN_WEAK_SIGNATURE = 0x00010000;

        public const uint CERT_CHAIN_FIND_BY_ISSUER = 1;

        public const uint CERT_CHAIN_POLICY_IGNORE_WEAK_SIGNATURE_FLAG = 0x08000000;

        public const uint BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_CA_FLAG = 0x80000000;

        public const uint BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_END_ENTITY_FLAG = 0x40000000;

        public const uint MICROSOFT_ROOT_CERT_CHAIN_POLICY_ENABLE_TEST_ROOT_FLAG = 0x00010000;

        public const uint MICROSOFT_ROOT_CERT_CHAIN_POLICY_CHECK_APPLICATION_ROOT_FLAG = 0x00020000;

        public const uint MICROSOFT_ROOT_CERT_CHAIN_POLICY_DISABLE_FLIGHT_ROOT_FLAG = 0x00040000;

        public const uint SSL_F12_ERROR_TEXT_LENGTH = 256;

        public const uint CERT_CHAIN_POLICY_SSL_F12_SUCCESS_LEVEL = 0;

        public const uint CERT_CHAIN_POLICY_SSL_F12_WARNING_LEVEL = 1;

        public const uint CERT_CHAIN_POLICY_SSL_F12_ERROR_LEVEL = 2;

        public const uint CERT_CHAIN_POLICY_SSL_F12_NONE_CATEGORY = 0;

        public const uint CERT_CHAIN_POLICY_SSL_F12_WEAK_CRYPTO_CATEGORY = 1;

        public const uint CERT_CHAIN_POLICY_SSL_F12_ROOT_PROGRAM_CATEGORY = 2;

        public const uint SSL_HPKP_PKP_HEADER_INDEX = 0;

        public const uint SSL_HPKP_PKP_RO_HEADER_INDEX = 1;

        public const uint SSL_HPKP_HEADER_COUNT = 2;

        public const uint SSL_KEY_PIN_ERROR_TEXT_LENGTH = 512;

        public const int CERT_CHAIN_POLICY_SSL_KEY_PIN_MISMATCH_ERROR = -2;

        public const int CERT_CHAIN_POLICY_SSL_KEY_PIN_MITM_ERROR = -1;

        public const uint CERT_CHAIN_POLICY_SSL_KEY_PIN_SUCCESS = 0;

        public const uint CERT_CHAIN_POLICY_SSL_KEY_PIN_MITM_WARNING = 1;

        public const uint CERT_CHAIN_POLICY_SSL_KEY_PIN_MISMATCH_WARNING = 2;

        public const uint CRYPT_STRING_BASE64URI = 0x0000000d;

        public const uint CRYPT_STRING_ENCODEMASK = 0x000000ff;

        public const uint CRYPT_STRING_RESERVED100 = 0x00000100;

        public const uint CRYPT_STRING_RESERVED200 = 0x00000200;

        public const uint CRYPT_STRING_PERCENTESCAPE = 0x08000000;

        public const uint CRYPT_STRING_HASHDATA = 0x10000000;

        public const uint CRYPT_STRING_NOCRLF = 0x40000000;

        public const uint CRYPT_STRING_NOCR = 0x80000000;

        public const uint PKCS12_IMPORT_SILENT = 0x00000040;

        public const uint PKCS12_ONLY_CERTIFICATES = 0x00000400;

        public const uint PKCS12_ONLY_NOT_ENCRYPTED_CERTIFICATES = 0x00000800;

        public const uint PKCS12_VIRTUAL_ISOLATION_KEY = 0x00010000;

        public const uint PKCS12_IMPORT_RESERVED_MASK = 0xffff0000;

        public const uint PKCS12_ONLY_CERTIFICATES_PROVIDER_TYPE = 0;

        public const uint REPORT_NO_PRIVATE_KEY = 0x0001;

        public const uint REPORT_NOT_ABLE_TO_EXPORT_PRIVATE_KEY = 0x0002;

        public const uint EXPORT_PRIVATE_KEYS = 0x0004;

        public const uint PKCS12_PROTECT_TO_DOMAIN_SIDS = 0x0020;

        public const uint PKCS12_EXPORT_SILENT = 0x0040;

        public const uint PKCS12_EXPORT_PBES2_PARAMS = 0x0080;

        public const uint PKCS12_DISABLE_ENCRYPT_CERTIFICATES = 0x0100;

        public const uint PKCS12_ENCRYPT_CERTIFICATES = 0x0200;

        public const uint PKCS12_EXPORT_ECC_CURVE_PARAMETERS = 0x1000;

        public const uint PKCS12_EXPORT_ECC_CURVE_OID = 0x2000;

        public const uint PKCS12_EXPORT_RESERVED_MASK = 0xffff0000;

        public const uint CERT_SERVER_OCSP_RESPONSE_OPEN_PARA_READ_FLAG = 0x00000001;

        public const uint CERT_SERVER_OCSP_RESPONSE_OPEN_PARA_WRITE_FLAG = 0x00000002;

        public const uint CERT_SERVER_OCSP_RESPONSE_ASYNC_FLAG = 0x00000001;

        public const uint CERT_SELECT_MAX_PARA = 500;

        public const uint CERT_SELECT_BY_ISSUER_DISPLAYNAME = 12;

        public const uint CERT_SELECT_BY_FRIENDLYNAME = 13;

        public const uint CERT_SELECT_BY_THUMBPRINT = 14;

        public const uint CERT_SELECT_ALLOW_EXPIRED = 0x00000001;

        public const uint CERT_SELECT_TRUSTED_ROOT = 0x00000002;

        public const uint CERT_SELECT_DISALLOW_SELFSIGNED = 0x00000004;

        public const uint CERT_SELECT_HAS_PRIVATE_KEY = 0x00000008;

        public const uint CERT_SELECT_HAS_KEY_FOR_SIGNATURE = 0x00000010;

        public const uint CERT_SELECT_HAS_KEY_FOR_KEY_EXCHANGE = 0x00000020;

        public const uint CERT_SELECT_HARDWARE_ONLY = 0x00000040;

        public const uint CERT_SELECT_ALLOW_DUPLICATES = 0x00000080;

        public const uint CERT_SELECT_IGNORE_AUTOSELECT = 0x00000100;

        public const uint TIMESTAMP_FAILURE_BAD_ALG = 0;

        public const uint TIMESTAMP_FAILURE_BAD_REQUEST = 2;

        public const uint TIMESTAMP_FAILURE_BAD_FORMAT = 5;

        public const uint TIMESTAMP_FAILURE_TIME_NOT_AVAILABLE = 14;

        public const uint TIMESTAMP_FAILURE_POLICY_NOT_SUPPORTED = 15;

        public const uint TIMESTAMP_FAILURE_EXTENSION_NOT_SUPPORTED = 16;

        public const uint TIMESTAMP_FAILURE_INFO_NOT_AVAILABLE = 17;

        public const uint TIMESTAMP_FAILURE_SYSTEM_FAILURE = 25;

        public const uint TIMESTAMP_DONT_HASH_DATA = 0x00000001;

        public const uint TIMESTAMP_VERIFY_CONTEXT_SIGNATURE = 0x00000020;

        public const uint TIMESTAMP_NO_AUTH_RETRIEVAL = 0x00020000;

        public const uint CRYPT_OBJECT_LOCATOR_SPN_NAME_TYPE = 1;

        public const uint CRYPT_OBJECT_LOCATOR_LAST_RESERVED_NAME_TYPE = 32;

        public const uint CRYPT_OBJECT_LOCATOR_FIRST_RESERVED_USER_NAME_TYPE = 33;

        public const uint CRYPT_OBJECT_LOCATOR_LAST_RESERVED_USER_NAME_TYPE = 0x0000FFFF;

        public const uint CERT_FILE_HASH_USE_TYPE = 1;

        public const uint CERT_TIMESTAMP_HASH_USE_TYPE = 2;

    }
}

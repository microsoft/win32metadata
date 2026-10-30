namespace Win32MetadataTestCases
{
    internal static class HeaderAnnotationCases
    {
        internal static string[] InvalidPayloads => new[]
        {
            "SetLastError()", "Flags()", "Flags(true)", "Flags(unsigned)", "Retained(1)",
            "Reserved()", "ContainsInteriorPointers=value", "RAIIFree()", "RAIIFree(Close, )",
            "RAIIFree(Close, (0)", "RAIIFree(Close, [))", "AssociatedEnum", "Field",
            "ImportLibrary(\"\")", "ImportLibrary(\"x.dll\", \"#0\")",
            "ImportLibrary(\"x.dll\", \"#65536\")", "ImportLibrary(\"x.dll\", \"#not-an-ordinal\")",
            "SupportedOSPlatform(\"windows10.0.99999\")", "Optional", "Optional()", "Optional(1)",
            "Optional(TRUE)", "Optional(\"false\")", "ComOutPtr(false, true)",
            "ComOutPtr(true || false)", "Unsupported",
        };

        internal const string NativeContractDeclarations = @"
typedef void* HANDLE;
typedef int HRESULT;
enum _Win32_SupportedOS_10240_ _Win32_AssociatedConstant_(LOOSE_A)
    _Win32_AssociatedConstant_(LOOSE_B) Options : unsigned { OptionA = 1, OptionB = 2 };
enum class [[clang::flag_enum]] ScopedOptions : unsigned { None = 0, A = 1, B = 2 };
struct _Win32_SupportedOS_10240_ DESCRIPTION {
    _Win32_AssociatedEnum_(Options) unsigned flags;
    int size;
};
_Win32_SupportedOS_Windows7_ _Win32_AlsoUsableFor_(OTHER_TOKEN)
typedef unsigned long TOKEN;
_Win32_SupportedOS_10240_
typedef int (__stdcall* PFN_BASE)(_Win32_Retained_ void* context, unsigned count);
_Win32_SupportedOS_Windows7_
typedef PFN_BASE PFN_ALIAS;
extern ""C"" {
_Win32_SetLastError_ _Win32_ImportLibrary_(""header.dll"") _Win32_SupportedOS_10240_
int __stdcall Imported(_In_ _Win32_Retained_ void* context,
    _Out_writes_bytes_opt_(capacity) _Win32_ContainsInteriorPointers_ unsigned char* buffer,
    unsigned capacity);
_Win32_RAIIFree_(CloseThing, 0, -1) HANDLE __stdcall OpenThing();
int __stdcall CreateThing(_Out_ _Win32_RAIIFree_(CloseThing, 0) HANDLE* output);
_Win32_AssociatedEnum_(Options) unsigned __stdcall AssociatedReturn();
int __stdcall ReadOption(_In_ _Win32_AssociatedEnum_(Options) unsigned option);
_Win32_PreserveResult_ HRESULT __stdcall ExactResult();
int __stdcall Retval(_Out_ _Win32_Retval_ int* result);
int __stdcall MidlRetval(/* [out] [retval] */ _Out_retval_ int* result);
TOKEN __stdcall UseToken(TOKEN value, TOKEN* output);
int __stdcall UseCallback(PFN_ALIAS callback);
}
struct __declspec(uuid(""b2051485-7dfd-41a0-af5c-1b351bfb1297"")) _Win32_SupportedOS_10240_ IHeaderSample {
    _Win32_PreserveResult_ _Win32_SupportedOS_Windows7_
    virtual HRESULT __stdcall Exact(_Out_ _Win32_Retval_ int* result) = 0;
    _Win32_RAIIFree_(CloseThing, 0, -1)
    virtual HANDLE __stdcall Produce() = 0;
    virtual HRESULT __stdcall Buffer(_Out_writes_bytes_(capacity) _Win32_ContainsInteriorPointers_ unsigned char* data, unsigned capacity) = 0;
};
";
        internal const string AssociatedConstantNativeDeclarations = @"
typedef enum _Win32_AssociatedConstant_(CLSCTX_ALL) _Win32_AssociatedConstant_(CLSCTX_SERVER)
__attribute__((flag_enum)) tagCLSCTX {
    CLSCTX_INPROC_SERVER = 1,
    CLSCTX_INPROC_HANDLER = 2,
    CLSCTX_LOCAL_SERVER = 4,
    CLSCTX_REMOTE_SERVER = 16
} CLSCTX;
#if (_WIN32_WINNT >= 0x0400) || defined(_WIN32_DCOM)
#define CLSCTX_ALL (CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER | CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER)
#define CLSCTX_SERVER (CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER)
#else
#define CLSCTX_ALL (CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER | CLSCTX_LOCAL_SERVER)
#define CLSCTX_SERVER (CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER)
#endif
typedef enum _Win32_AssociatedConstant_(D3DTS_WORLD) _Win32_AssociatedConstant_(D3DTS_WORLD1)
_Win32_AssociatedConstant_(D3DTS_WORLD2) _Win32_AssociatedConstant_(D3DTS_WORLD3)
_D3DTRANSFORMSTATETYPE : int { D3DTS_VIEW = 2, D3DTS_PROJECTION = 3 } D3DTRANSFORMSTATETYPE;
#define D3DTS_WORLDMATRIX(index) (D3DTRANSFORMSTATETYPE)(index + 256)
#define D3DTS_WORLD D3DTS_WORLDMATRIX(0)
#define D3DTS_WORLD1 D3DTS_WORLDMATRIX(1)
#define D3DTS_WORLD2 D3DTS_WORLDMATRIX(2)
#define D3DTS_WORLD3 D3DTS_WORLDMATRIX(3)
#define UNRELATED_NUMBER 19U
#define UNRELATED_POINTER ((void*)-1)
void KeepNative(unsigned value);
";
        internal const string NativeContractAdditionalDeclarations = @"
#define BATCH_FIRST 1U
#define BATCH_SECOND (1U << 3)
_Win32_FlagsEnum_(BATCH_OPTIONS, unsigned, BATCH_FIRST, BATCH_SECOND);
enum BATCH_NATIVE_FLAGS : unsigned { BatchRead = 1, BatchWrite = 4 };
/* Win32Metadata: enum ::BATCH_NATIVE_FLAGS => Flags */
struct BATCH_FIELDS { unsigned value; };
_Win32_AnnotateField_(BATCH_FIELDS::value, _Win32_AssociatedEnum_(BATCH_NATIVE_FLAGS));
#pragma pack(push, 1)
struct BATCH_PACKED { unsigned char kind; void* context; };
#pragma pack(pop)
_Win32_ImportLibrary_(""ordinal.dll"", ""#42"") int __stdcall ByOrdinal();
struct __declspec(uuid(""eb0c0ca2-cfc2-4538-a693-314db6fc20f2"")) IOverride {
    virtual int __stdcall Read(_Out_opt_ void** value) = 0;
};
_WIN32META_ANNOTATE_PARAMETER_(IOverride::Read, value, _Win32_Optional_(false) _Win32_ComOutPtr_(true));
typedef int BATCH_BOOL;
typedef void* BATCH_HANDLE;
typedef BATCH_HANDLE* BATCH_PHANDLE;
struct BATCH_OPAQUE;
typedef struct BATCH_OPAQUE* BATCH_HOPAQUE;
BATCH_BOOL RoundTripBatch(BATCH_BOOL value, BATCH_HANDLE handle, BATCH_PHANDLE output, BATCH_HOPAQUE opaque);
#define BATCH_WRAP32 (0xffffffffU + 1U)
#define BATCH_POINTER_SIZE sizeof(void*)
#if defined(_WIN64)
#define BATCH_ONLY_64 64U
#else
#define BATCH_ONLY_32 32U
#endif
";

        internal const string ScopedDeclarations = @"
typedef int HRESULT;
int BeforeScope();
_Win32_SupportedOS_BEGIN_(WindowsVista)
struct SCOPED_RECORD {
    int size;
    unsigned flags;
    struct NESTED_RECORD { int value; };
    enum NESTED_ENUM { NestedValue = 1 };
};
enum SCOPED_ENUM : unsigned { ScopedValue = 1 };
typedef unsigned SCOPED_TOKEN;
typedef int (__stdcall* PFN_SCOPED)(_In_ _Win32_Retained_ void* context, _Out_ int* result);
using USING_TOKEN = unsigned;
using PFN_USING = SCOPED_TOKEN (__stdcall*)(_In_ _Win32_Retained_ void* context, _Out_ _Win32_Retval_ int* result);
using PFN_USING_ALIAS = PFN_USING;
using PFN_USING_NATIVE_ALIAS = PFN_SCOPED;
typedef PFN_USING PFN_TYPEDEF_USING_ALIAS;
SCOPED_TOKEN UseScopedToken(SCOPED_TOKEN value);
USING_TOKEN UseUsingToken(USING_TOKEN value);
void UseScopedCallbacks(PFN_SCOPED first, PFN_USING second, PFN_USING_ALIAS third, PFN_TYPEDEF_USING_ALIAS fourth);
_Win32_SupportedOS_END_()
using DIRECT_TOKEN _Win32_SupportedOS_Windows7_ = unsigned;
_Win32_SupportedOS_Windows7_ typedef struct _PRIMARY_SCOPED { unsigned value; } PRIMARY_SCOPED;
_Win32_SupportedOS_BEGIN_(Windows7)
int Seven();
_Win32_SupportedOS_Windows7_ int ExplicitEqual();
_Win32_SupportedOS_END_()
_Win32_SupportedOS_Windows8_ int ExplicitLater();
_Win32_SupportedOS_Windows2000_ int ExplicitEarlier();
_Win32_SupportedOS_BEGIN_(Windows2000)
int OlderNested();
_Win32_SupportedOS_END_()
struct __declspec(uuid(""4d0ea686-f54d-4b53-aeec-bf6154950080"")) _Win32_SupportedOS_WindowsVista_ IScoped {
    _Win32_SupportedOS_WindowsVista_ virtual HRESULT __stdcall VistaMethod(_Out_ _Win32_Retval_ int* result) = 0;
    _Win32_SupportedOS_Windows7_ virtual HRESULT __stdcall SevenMethod() = 0;
    _Win32_SupportedOS_Windows2000_ virtual HRESULT __stdcall ExplicitMethod() = 0;
    _Win32_SupportedOS_WindowsVista_ virtual HRESULT __stdcall VistaAgainMethod() = 0;
};
int AfterScope();
struct __declspec(uuid(""b3dd7ce4-3a4c-42d8-b506-b32919dc848e"")) _Win32_SupportedOS_Windows7_ IContainerOnly {
    virtual HRESULT __stdcall UnannotatedMember(_Out_ _Win32_Retval_ int* result) = 0;
};
";
    }
}

using Windows.Win32.Foundation;
using Windows.Win32.Interop;

namespace Microsoft.Dia
{
    public static unsafe partial class Apis
    {
        [NativeTypeName("HRESULT")]
        public const int E_PDB_OK = unchecked(((int)(((uint)(1) << 31) | ((uint)(0x6d) << 16) | ((uint)(1)))));;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_USAGE = E_PDB_OK + 1;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_OUT_OF_MEMORY = E_PDB_OK + 2;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_FILE_SYSTEM = E_PDB_OK + 3;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_NOT_FOUND = E_PDB_OK + 4;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_INVALID_SIG = E_PDB_OK + 5;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_INVALID_AGE = E_PDB_OK + 6;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_PRECOMP_REQUIRED = E_PDB_OK + 7;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_OUT_OF_TI = E_PDB_OK + 8;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_NOT_IMPLEMENTED = E_PDB_OK + 9;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_V1_PDB = E_PDB_OK + 10;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_FORMAT = E_PDB_OK + 11;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_LIMIT = E_PDB_OK + 12;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_CORRUPT = E_PDB_OK + 13;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_TI16 = E_PDB_OK + 14;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_ACCESS_DENIED = E_PDB_OK + 15;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_ILLEGAL_TYPE_EDIT = E_PDB_OK + 16;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_INVALID_EXECUTABLE = E_PDB_OK + 17;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_DBG_NOT_FOUND = E_PDB_OK + 18;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_NO_DEBUG_INFO = E_PDB_OK + 19;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_INVALID_EXE_TIMESTAMP = E_PDB_OK + 20;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_RESERVED = E_PDB_OK + 21;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_DEBUG_INFO_NOT_IN_PDB = E_PDB_OK + 22;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_SYMSRV_BAD_CACHE_PATH = E_PDB_OK + 23;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_SYMSRV_CACHE_FULL = E_PDB_OK + 24;

        [NativeTypeName("HRESULT")]
        public const int E_PDB_OBJECT_DISPOSED = E_PDB_OK + 25;

        [NativeTypeName("HRESULT")]
        public const int E_DIA_INPROLOG = unchecked((int)(((uint)(1)<<31) | ((uint)(((uint)0x6d))<<16) | ((uint)(100))));

        [NativeTypeName("HRESULT")]
        public const int E_DIA_SYNTAX = E_DIA_INPROLOG + 1;

        [NativeTypeName("HRESULT")]
        public const int E_DIA_FRAME_ACCESS = E_DIA_INPROLOG + 2;

        [NativeTypeName("HRESULT")]
        public const int E_DIA_VALUE = E_DIA_INPROLOG + 3;
    }

    public enum SymTag
    {
        SymTagNull,
        SymTagExe,
        SymTagCompiland,
        SymTagCompilandDetails,
        SymTagCompilandEnv,
        SymTagFunction,
        SymTagBlock,
        SymTagData,
        SymTagAnnotation,
        SymTagLabel,
        SymTagPublicSymbol,
        SymTagUDT,
        SymTagEnum,
        SymTagFunctionType,
        SymTagPointerType,
        SymTagArrayType,
        SymTagBaseType,
        SymTagTypedef,
        SymTagBaseClass,
        SymTagFriend,
        SymTagFunctionArgType,
        SymTagFuncDebugStart,
        SymTagFuncDebugEnd,
        SymTagUsingNamespace,
        SymTagVTableShape,
        SymTagVTable,
        SymTagCustom,
        SymTagThunk,
        SymTagCustomType,
        SymTagManagedType,
        SymTagDimension,
        SymTagCallSite,
        SymTagInlineSite,
        SymTagBaseInterface,
        SymTagVectorType,
        SymTagMatrixType,
        SymTagHLSLType,
        SymTagCaller,
        SymTagCallee,
        SymTagExport,
        SymTagHeapAllocationSite,
        SymTagCoffGroup,
        SymTagInlinee,
        SymTagMax
    }
}

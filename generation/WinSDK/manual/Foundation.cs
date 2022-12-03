using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Foundation
{
    public static unsafe partial class Apis
    {
        [NativeTypeName("BOOL")]
        public const int TRUE = 1;

        [NativeTypeName("BOOL")]
        public const int FALSE = 0;

        [NativeTypeName("VARIANT_BOOL")]
        public const short VARIANT_TRUE = -1;

        [NativeTypeName("VARIANT_BOOL")]
        public const short VARIANT_FALSE = 0;

        [NativeTypeName("HANDLE")]
        public const int INVALID_HANDLE_VALUE = -1;

        [NativeTypeName("HRESULT")]
        public const int CO_E_NOTINITIALIZED = unchecked((int)0x800401F0);

        [NativeTypeName("NTSTATUS")]
        public const int STILL_ACTIVE = STATUS_PENDING;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_ACCESS_VIOLATION = STATUS_ACCESS_VIOLATION;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_DATATYPE_MISALIGNMENT = STATUS_DATATYPE_MISALIGNMENT;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_BREAKPOINT = STATUS_BREAKPOINT;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_SINGLE_STEP = STATUS_SINGLE_STEP;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_ARRAY_BOUNDS_EXCEEDED = STATUS_ARRAY_BOUNDS_EXCEEDED;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_FLT_DENORMAL_OPERAND = STATUS_FLOAT_DENORMAL_OPERAND;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_FLT_DIVIDE_BY_ZERO = STATUS_FLOAT_DIVIDE_BY_ZERO;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_FLT_INEXACT_RESULT = STATUS_FLOAT_INEXACT_RESULT;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_FLT_INVALID_OPERATION = STATUS_FLOAT_INVALID_OPERATION;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_FLT_OVERFLOW = STATUS_FLOAT_OVERFLOW;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_FLT_STACK_CHECK = STATUS_FLOAT_STACK_CHECK;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_FLT_UNDERFLOW = STATUS_FLOAT_UNDERFLOW;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_INT_DIVIDE_BY_ZERO = STATUS_INTEGER_DIVIDE_BY_ZERO;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_INT_OVERFLOW = STATUS_INTEGER_OVERFLOW;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_PRIV_INSTRUCTION = STATUS_PRIVILEGED_INSTRUCTION;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_IN_PAGE_ERROR = STATUS_IN_PAGE_ERROR;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_ILLEGAL_INSTRUCTION = STATUS_ILLEGAL_INSTRUCTION;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_NONCONTINUABLE_EXCEPTION = STATUS_NONCONTINUABLE_EXCEPTION;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_STACK_OVERFLOW = STATUS_STACK_OVERFLOW;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_INVALID_DISPOSITION = STATUS_INVALID_DISPOSITION;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_GUARD_PAGE = STATUS_GUARD_PAGE_VIOLATION;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_INVALID_HANDLE = STATUS_INVALID_HANDLE;
        [NativeTypeName("NTSTATUS")]
        public const int EXCEPTION_POSSIBLE_DEADLOCK = STATUS_POSSIBLE_DEADLOCK;
        [NativeTypeName("NTSTATUS")]
        public const int CONTROL_C_EXIT = STATUS_CONTROL_C_EXIT;
    }
}

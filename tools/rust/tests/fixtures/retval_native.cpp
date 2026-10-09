#include <sal.h>

#undef _Out_retval_
#undef _COM_Outptr_retval_

#if defined(TEST_EXISTING_NATIVE_RETVAL)
#define _Out_retval_ 17
#define _COM_Outptr_retval_ 19
#elif defined(TEST_NATIVE_RETVAL_EXPANSION)
#undef _Out_
#undef _COM_Outptr_
#define _Out_ 23
#define _COM_Outptr_ 29
#endif

#include "win32metadata_annotations.h"

#if defined(TEST_EXISTING_NATIVE_RETVAL)
static_assert(_Out_retval_ == 17);
static_assert(_COM_Outptr_retval_ == 19);
#elif defined(TEST_NATIVE_RETVAL_EXPANSION)
static_assert(_Out_retval_ == 23);
static_assert(_COM_Outptr_retval_ == 29);
#else
void NativeRetval(_Out_retval_ int* value);
void NativeComRetval(_COM_Outptr_retval_ void** value);
#endif

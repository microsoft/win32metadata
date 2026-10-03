#pragma once

#include "win32metadata_annotations.h"

typedef void* UNRESOLVED_HANDLE;

extern "C" _Win32_RAIIFree_(CloseUnresolved, MISSING_INVALID_HANDLE)
    UNRESOLVED_HANDLE UnresolvedAnnotation(void);

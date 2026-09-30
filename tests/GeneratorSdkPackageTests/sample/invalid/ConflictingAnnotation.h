#pragma once

#include "win32metadata_annotations.h"

extern "C" _Win32_RAIIFree_(CloseFirst) int ConflictingAnnotation(void);
extern "C" _Win32_RAIIFree_(CloseSecond) int ConflictingAnnotation(void);

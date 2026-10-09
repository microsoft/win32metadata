#pragma once

#include "win32metadata_annotations.h"

extern "C" _Win32_ImportLibrary_("samplecleanup.dll")
    int SampleCloseHandle(SAMPLE_HANDLE handle);

typedef struct CLEANUP_DEPENDENCY_NOISE
{
    int value;
} CLEANUP_DEPENDENCY_NOISE;

extern "C" int CleanupDependencyShouldNotEmit(void);

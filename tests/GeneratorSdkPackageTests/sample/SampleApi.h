#pragma once

#include "DependencyConstants.h"
#include "win32metadata_annotations.h"

enum _Win32_AssociatedConstant_(SAMPLE_MODE_EXTERNAL) SAMPLE_MODE : unsigned long
{
    SAMPLE_MODE_NONE = 0,
    SAMPLE_MODE_FAST = 1,
};

typedef struct SAMPLE_POINT
{
    int x;
    int y;
} SAMPLE_POINT;

class SAMPLE_PROPERTY
{
public:
    unsigned long id;
    void* value;
};

extern "C" _Windows_SupportedOS_19041_662_ int SampleAdd(int left, int right);

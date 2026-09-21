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
extern "C" _Windows_SupportedOS_WindowsVistaSP1_ int SampleVistaSp1(void);
extern "C" _Windows_SupportedOS_20348_ int SampleServer2022(void);
extern "C" _Windows_SupportedOS_22631_ int SampleWindows11_23H2(void);
extern "C" _Windows_SupportedOS_26100_ int SampleWindows11_24H2(void);

#pragma once

#include "DependencyConstants.h"

enum __attribute__((annotate("win32metadata:associated_constant=SAMPLE_MODE_EXTERNAL")))
    SAMPLE_MODE : unsigned long
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

extern "C" int SampleAdd(int left, int right);

#pragma once

#define SAMPLE_MODE_EXTERNAL_VALUE (0xe0000001UL)
#define SAMPLE_MODE_EXTERNAL SAMPLE_MODE_EXTERNAL_VALUE

typedef struct DEPENDENCY_NOISE
{
    int value;
} DEPENDENCY_NOISE;

extern "C" int DependencyShouldNotEmit(void);

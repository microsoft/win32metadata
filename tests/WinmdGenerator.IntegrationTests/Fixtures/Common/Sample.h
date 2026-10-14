#include <windows.h>

#define SAMPLE_VALUE 42

typedef struct ORIGINAL_RECORD
{
    int value;
} ORIGINAL_RECORD;

extern "C" int __stdcall PackageFunction(int value);

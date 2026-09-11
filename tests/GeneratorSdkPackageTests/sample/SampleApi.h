#pragma once

typedef enum SAMPLE_MODE
{
    SAMPLE_MODE_NONE = 0,
    SAMPLE_MODE_FAST = 1,
} SAMPLE_MODE;

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

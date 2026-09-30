#pragma once

#if SAMPLE_INCLUDE_ORDER_TOKEN != 41
#error Translation unit include order was not preserved.
#endif

typedef struct SAMPLE_ORDERED_INCLUDE
{
    int value;
} SAMPLE_ORDERED_INCLUDE;

#define SAMPLE_FEATURE_ENABLED 1
#define SAMPLE_MACRO_HEADER "MacroExpanded.h"

#include "ZOrderDefine.h"
#include "AOrderUse.h"
#include "FeatureMacro.h"
#include SAMPLE_MACRO_HEADER
#include "SampleApi.h"

typedef struct SAMPLE_DIRECT_DECLARATION
{
    int value;
} SAMPLE_DIRECT_DECLARATION;

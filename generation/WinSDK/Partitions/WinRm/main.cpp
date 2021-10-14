#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#define WSMAN_API_VERSION_1_1

#include <wsman.h>
#include <wsmandisp.h>
#include <wsmerror.h>


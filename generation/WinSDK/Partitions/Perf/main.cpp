#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <loadperf.h>
#include <perflib.h>
#include <pdh.h>
#include <winperf.h>
#include <profileapi.h>
#include <isysmon.h>
#include <pdhmsg.h>

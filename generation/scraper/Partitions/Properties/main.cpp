#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <wtypes.h>
#include <shobjidl.h>
#include <shlobj_core.h>
#include <propsys.h>
#include <shobjidl_core.h>
#include <propvarutil.h>
#include <propidl.h>
#include <shellapi.h>

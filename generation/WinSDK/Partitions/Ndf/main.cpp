#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

// Usually brought in by windows.h
typedef UINT_PTR SOCKET;

#include <ndattrib.h>
#include <ndhelper.h>
#include <ndfapi.h>

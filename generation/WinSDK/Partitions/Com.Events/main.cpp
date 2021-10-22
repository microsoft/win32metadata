#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#define MICROSOFT_WINDOWS_WINBASE_H_DEFINE_INTERLOCKED_CPLUSPLUS_OVERLOADS 0

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

typedef LPVOID* PPVOID;

#include <comsvcs.h>
#include <combaseapi.h>
#include <eventsys.h>

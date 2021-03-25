#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <mapi.h>
//#include <mapiunicodehelp.h> // Seems to be inline helper functions which can't go into metadata

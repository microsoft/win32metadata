#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <sapi53.h>
//#include <sapiddk.h> -- Can't compile with sapi53.h
#include <sperror.h>

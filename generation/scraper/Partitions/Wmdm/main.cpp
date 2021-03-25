#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <scclient.h>
#include <mswmdm.h>
// #include <scserver.h> Only contains C++ implementation code
#include <wmdmlog.h>
#include <mtpext.h>

// Purposely not traversing scclient.h in settings.rsp. Only contains C++ implementation code

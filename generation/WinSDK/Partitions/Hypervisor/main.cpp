#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <WinHvPlatform.h>
#if defined(_AMD64_)
#include <WinHvEmulation.h>
#endif
#include <hvsocket.h>
#include <vmgenerationcounter.h>
#include <hypervdevicevirtualization.h>
#include <vmsavedstatedump.h>
#include <vmsavedstatedumpdefs.h>

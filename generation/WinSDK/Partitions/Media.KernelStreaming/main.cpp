#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>
#include <commdlg.h>

#define __STREAMS__

#include <ks.h>
#include <ksmedia.h>
#include <strmif.h>
#include <ksproxy.h>

#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

typedef LONG NTSTATUS;

#include <locationapi.h>
#include <sensorsapi.h>

#include <gnssdriver.h>

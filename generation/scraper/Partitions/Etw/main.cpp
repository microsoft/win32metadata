#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <tdh.h>
#include <evntrace.h>
#include <evntprov.h>
#include <evntcons.h>
#include <securitybaseapi.h>
#include <relogger.h>
#include <wmistr.h>

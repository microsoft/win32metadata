#define SECURITY_WIN32 // For sspi.h

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

// Normally brought in by windows.h
typedef LONG NTSTATUS;

#include <cfapi.h>

#define SECURITY_WIN32 // For sspi.h

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <winnt.h>
#include <winddi.h>
#include <devpropdef.h>
#include <ntddvdeo.h>

#define USERMODE_DRIVER
#include <winddi.h>
#undef USERMODE_DRIVER

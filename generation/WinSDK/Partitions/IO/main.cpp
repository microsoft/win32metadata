#define SECURITY_WIN32 // For sspi.h

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <mmsystem.h>

// Headers needed for COM
#include <objbase.h>
#include <ObjIdl.h>
#include <combaseapi.h>

#include <winbase.h>
#include <winnt.h>

#define USERMODE_DRIVER
#include <winddi.h>
#undef USERMODE_DRIVER

#include <winuser.h>

#include <ioapiset.h>

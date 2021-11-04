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

#include <winuser.h>

#include <utilapiset.h>
#include <errhandlingapi.h>
#include <winternl.h>
#include <debugapi.h>
#include <minwinbase.h>
#include <wct.h>
#include <minidumpapiset.h>
#include <winioctl.h>
#include <ioevent.h>
#include <storprop.h>
#include <ioapiset.h>
#include <dbt.h>
#include <atlthunk.h>
#include <lmserver.h>
#include <windowsceip.h>
#include <realtimeapiset.h>

#include <devpkey.h>
#include <apdevpkey.h>
#include <ntiologc.h>
#include <dlnadeviceinterfaceids.h>
#include <dlnametadataproviderproperties.h>

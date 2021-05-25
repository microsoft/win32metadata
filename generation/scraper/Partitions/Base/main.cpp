#define SECURITY_WIN32 // For sspi.h

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <mmsystem.h>
#include <winsmcrd.h>
#include <winspool.h>

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

#include <utilapiset.h>
#include <errhandlingapi.h>
#include <winternl.h>
#include <debugapi.h>
#include <processenv.h>
#include <minwinbase.h>
#include <wct.h>
#include <minidumpapiset.h>
//#include <imagehlp.h> // Can't use with dbghelp.h
#include <winioctl.h>
#include <ioevent.h>
#include <storprop.h>
#include <ioapiset.h>
#include <dbt.h>
#include <ntddstor.h>
#include <process.h>
#include <fileapi.h>
#include <sysinfoapi.h>
#include <atlthunk.h>
#include <lmserver.h>
#include <handleapi.h>
#include <windowsceip.h>
#include <versionhelpers.h>
#include <realtimeapiset.h>
#include <timezoneapi.h>
#include <timeprov.h>

#include <namespaceapi.h>
#include <processtopologyapi.h>
#include <systemtopologyapi.h>
#include <profileapi.h>

#include <devpkey.h>

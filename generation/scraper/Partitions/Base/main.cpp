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

//
// Begin of area needing to be close to COM headers

#include <waasapi.h>
#include <rtworkq.h>
#include <dispatcherqueue.h>

// End of area needing to be close to COM headers
//

#include <winbase.h>
#include <winnt.h>
#include <winerror.h>
#include <ntstatus.h>

#define USERMODE_DRIVER
#include <winddi.h>
#undef USERMODE_DRIVER

#include <winuser.h>

#include <utilapiset.h>
#include <errhandlingapi.h>
#include <winternl.h>
#include <debugapi.h>
#include <processenv.h>
#include <processthreadsapi.h>
#include <memoryapi.h>
#include <minwinbase.h>
#include <wct.h>
#include <minidumpapiset.h>
//#include <imagehlp.h> // Can't use with dbghelp.h
#include <winioctl.h>
#include <mcx.h>
#include <ioevent.h>
#include <storprop.h>
#include <ioapiset.h>
#include <dbt.h>
#include <ntddstor.h>
#include <pwm.h>
#include <winreg.h>
#include <libloaderapi.h>
#include <process.h>
#include <libloaderapi2.h>
#include <fileapi.h>
#include <namedpipeapi.h>
#include <sysinfoapi.h>
#include <heapapi.h>
#include <atlthunk.h>
#include <lmserver.h>
#include <ntddvdeo.h>
#include <jobapi2.h>
#include <jobapi.h>
#include <avrt.h>
#include <threadpoolapiset.h>
#include <winsvc.h>
#include <reason.h>
#include <synchapi.h>
#include <interlockedapi.h>
#include <threadpoollegacyapiset.h>
#include <handleapi.h>
#include <windowsceip.h>
#include <versionhelpers.h>
#include <realtimeapiset.h>
#include <timezoneapi.h>
#include <timeprov.h>
#include <waasapitypes.h>

#include <namespaceapi.h>
#include <processtopologyapi.h>
#include <systemtopologyapi.h>
#include <profileapi.h>
#include <fibersapi.h>

#include <devpkey.h>

#include <libloaderapi.h>

#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <mmsystem.h>

#include <wtypes.h>
#include <winbase.h>
#include <winnt.h>
#include <objbase.h>
#include <winuser.h>
#include <windowsx.h>
#include <winternl.h>
#include <dbghelp.h>
#include <exposeenums2managed.h>
#include <avrfsdk.h>
#include <camerauicontrol.h>
#include <vdmdbg.h>
#include <editionupgradehelper.h>
#include <featurestagingapi.h>
#include <fhcfg.h>
#include <fhsvcctl.h>
#include <apiquery2.h>
#include <dciman.h>
#include <processenv.h>
#include <processthreadsapi.h>
#include <timezoneapi.h>

#include <ddrawi.h>
#include <handleapi.h>
#include <icwcfg.h>

#include <ddrawgdi.h>
#include <advpub.h>
//#include <comppkgsup.h>
#include <ime.h>
#include <winnls32.h>
#include <exdisp.h>
#include <loadperf.h>
//#include <scsi.h>
#include <capi.h>
#include <msxml.h>
#include <lmaccess.h>
#include <wininet.h>
#include <rpcndr.h>
#include <isolatedapplauncher.h>
//#include <ntsecpkg.h>
#include <iwscapi.h>
#include <wscapi.h>
#include <filehc.h>
#include <aux_ulib.h>
//#include <rtlsupportapi.h>
#include <stralign.h>
//#include <tcpioctl.h>
#include <tdiinfo.h>
#include <appcompatapi.h>
#include <dsound.h>
#include <wldp.h>
#include <windowsceip.h>
#include <xmllite.h>
#include <devquery.h>
#include <fltdefs.h>
#include <statehelpers.h>

#include <reason.h>

#include <fherrors.h>
#include <fhstatus.h>

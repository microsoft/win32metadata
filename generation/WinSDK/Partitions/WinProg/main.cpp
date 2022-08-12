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
#include <camerauicontrol.h>
#include <editionupgradehelper.h>
#include <featurestagingapi.h>
#include <apiquery2.h>
#include <dciman.h>

#include <ddrawi.h>
extern "C" {
#include <ddrawgdi.h>
}
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
//#include <ntsecpkg.h>
#include <aux_ulib.h>
//#include <rtlsupportapi.h>
#include <stralign.h>
//#include <tcpioctl.h>
#include <tdiinfo.h>
#include <appcompatapi.h>
#include <dsound.h>
#include <wldp.h>

#include <defaultbrowsersyncsettings.h>
#include <delayloadhandler.h>
#include <deletebrowsinghistory.h>

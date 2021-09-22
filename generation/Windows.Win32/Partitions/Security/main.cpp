#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <winternl.h>

// Usually brought in by windows.h
typedef NTSTATUS* PNTSTATUS;

#define _NTDEF_
#define SECURITY_WIN32
#include <NTSecAPI.h>
#include <sspi.h>
#include <wincred.h>
#include <NTSecPKG.h>
#include <schannel.h>

typedef struct _OLD_LARGE_INTEGER {
    ULONG LowPart;
    LONG HighPart;
} OLD_LARGE_INTEGER, *POLD_LARGE_INTEGER;


#include <winbase.h>
#include <winnt.h>
#include <accctrl.h>
#include <winuser.h>
#include <processthreadsapi.h>
#include <lmaccess.h>
#include <winreg.h>
#include <securitybaseapi.h>
#include <namedpipeapi.h>
#include <mmcobj.h>
#include <winwlx.h>
#include <tpmvscmgr.h>
#include <sspi.h>
#include <sas.h>
#include <winnetwk.h>
#include <winsmcrd.h>
#include <dssec.h>
#include <casetup.h>
#include <certsrv.h>
#include <celib.h>
#include <mscat.h>
#include <dpapi.h>
#include <mssip.h>
#include <wintrust.h>
#include <iads.h>
#include <scesvc.h>
#include <winsafer.h>
#include <slpublic.h>
#include <diagnosticdataquery.h>
#include <diagnosticdataquerytypes.h>
#include <security.h>

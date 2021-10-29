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
#include <winuser.h>

#include <tpmvscmgr.h>
#include <TpmVscAttestation.h>

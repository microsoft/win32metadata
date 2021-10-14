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

#include <certadm.h>
#include <certbcli.h>
#include <certcli.h>
#include <certenc.h>
#include <certenroll.h>
#include <certexit.h>
#include <certif.h>
#include <certmod.h>
#include <certpol.h>
#include <certpoleng.h>
#include <certsrv.h>
#include <certview.h>
#include <xenroll.h>
#include <certreqd.h>

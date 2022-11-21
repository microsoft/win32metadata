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
extern "C" {
#include <schannel.h>
}

typedef struct _OLD_LARGE_INTEGER {
    ULONG LowPart;
    LONG HighPart;
} OLD_LARGE_INTEGER, *POLD_LARGE_INTEGER;


#include <winbase.h>
#include <winnt.h>
#include <securitybaseapi.h>
#include <subauth.h>
#include <tokenbinding.h>
#include <security.h>
#include <slpublic.h>
#include <issper16.h>
#include <ccgplugins.h>
#include <schnlsp.h>
#include <slerror.h>
#include <sliddefs.h>
#include <wdigest.h>
#include <sas.h>
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
#include <bcrypt.h>
#include <ncryptprotect.h>
#include <ncrypt.h>
#include <wincrypt.h>
#include <cryptxml.h>
#include <cryptdlg.h>
#include <cryptuiapi.h>
#include <i_cryptasn1tls.h>
#include <infocard.h>
#include <dpapi.h>
#include <casetup.h>


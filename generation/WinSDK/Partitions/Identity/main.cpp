#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <winnt.h>

#define SECURITY_WIN32
#include <NTSecAPI.h>
#include <sspi.h>
#include <wincred.h>
#include <NTSecPKG.h>
extern "C" {
#include <schannel.h>
}

#include <winbase.h>
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
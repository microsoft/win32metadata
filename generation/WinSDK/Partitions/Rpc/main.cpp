#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <objidl.h>
#include <wincrypt.h>

#include <rpcdce.h>
#include <winerror.h>
//#include <unknwnbase.h>
#include <rpcndr.h>
#include <rpcasync.h>
#include <rpcdcep.h>
#include <rpcnsi.h>
#include <midles.h>
#include <rpc.h>
#include <rpcssl.h>
//#include <rpcproxy.h> Leaving out on purpose. Requires C-only interfaces and we don't think we need proxy metadata
#include <ndr64types.h>
#include <rpcnsip.h>


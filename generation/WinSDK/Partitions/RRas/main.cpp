#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <ipmib.h>

#include <ras.h>
#include <rasdlg.h>
#include <mprapi.h>
#include <rasshost.h>
//#include <ipxrtdef.h>
//#include <routprot.h>
extern "C" {
#include <mgm.h>
}
#include <rtmv2.h>
#include <raserror.h>

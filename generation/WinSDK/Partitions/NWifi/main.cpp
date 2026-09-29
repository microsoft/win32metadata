#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#if defined(WIN32METADATA) && !defined(UM_NDIS689)
#define UM_NDIS689
#endif

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <wlantypes.h>
#include <windot11.h>
#include <wlanapi.h>
#include <dot1x.h>
#include <ntddndis.h>
#include <adhoc.h>
#include <wlclient.h>
#include <wlanihv.h>
#include <wlanihvtypes.h>

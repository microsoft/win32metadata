//#define SECURITY_WIN32 // For sspi.h
//#define QCC_OS_GROUP_WINDOWS

#if defined(WIN32METADATA) && !defined(UM_NDIS689)
#define UM_NDIS689
#endif

#include "intrinfix.h"

#include <winsock2.h>
#include <IPExport.h>

#define PIO_APC_ROUTINE_DEFINED
#include <winternl.h>
#include <icmpapi.h>
#undef PIO_APC_ROUTINE_DEFINED

#include <ip2string.h>
#include <ws2def.h>
#include <ws2ipdef.h>
#include <windns.h>
#include <iphlpapi.h>
#include <fltdefs.h>
#include <ipinfoid.h>
#include <inaddr.h>

//#define SECURITY_WIN32 // For sspi.h
//#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include <winsock2.h>
#include <IPExport.h>

#include <netioapi.h>

#define PIO_APC_ROUTINE_DEFINED
#include <winternl.h>
#include <icmpapi.h>
#undef PIO_APC_ROUTINE_DEFINED

#include <ip2string.h>
#include <iphlpapi.h>
#include <fltdefs.h>
#include <ipinfoid.h>

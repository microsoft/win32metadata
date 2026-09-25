//#define SECURITY_WIN32 // For sspi.h
//#define QCC_OS_GROUP_WINDOWS

#if defined(WIN32METADATA) && !defined(UM_NDIS689)
#define UM_NDIS689
#endif

#include "intrinfix.h"

#include <winsock2.h>
#include <ntddndis.h>

#include <qos2.h>
#include <traffic.h>
#include <qossp.h>
#include <qospol.h>
#include <LpmApi.h>
#include <tcerror.h>
#include <tcguid.h>
//#include <tcpioctl.h> - won't compile and duplicated by iphlpapi as per tcpioctl.h
#include <wbcl.h>

#include <devioctl.h>
#include <tdiinfo.h>
#include <tcpioctl.h>

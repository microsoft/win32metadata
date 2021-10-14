#define SECURITY_WIN32 // For sspi.h

#include "intrinfix.h"

#include <winsock2.h>

#include <winternl.h>

#define _NTDEF_
#define SECURITY_WIN32
#include <ntsecapi.h>

#include <shlobj_core.h>
#include <cmnquery.h>
#include <dsclient.h>
#include <objsel.h>
#include <dsquery.h>
#include <dsadmin.h>
#include <adsprop.h>
#include <ntdsapi.h>
#include <schedule.h>
#include <dsrole.h>
#include <dsparse.h>
#include <DsGetDC.h>

#include <iads.h>
#include <adssts.h>
#include <adshlp.h>

#include <ntdsbmsg.h>

#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <ntmsapi.h>
#include <ntmsmli.h>
#include <winbase.h>
#include <winnt.h>
#include <clfsw32.h>
#include <clfs.h>
#include <clfsmgmtw32.h>
#include <clfsmgmt.h>
#include <processenv.h>
#include <minwinbase.h>
#include <winioctl.h>
#include <fileapi.h>
#include <ntdddisk.h>
#include <dskquota.h>
#include <winefs.h>
#include <lzexpand.h>
#include <wofapi.h>
#include <txfw32.h>
#include <ntddvol.h>
#include <ktmw32.h>
#include <ktmtypes.h>
#include <lmshare.h>
#include <lmstats.h>
#include <filehc.h>
#include <winver.h> // Also includes verrsrc.h
#include <diskguid.h>
#include <fttypes.h>
#include <ioringapi.h>
#include <ntioring_x.h>
#include <winioctl.h>
#include <ntddstor.h>

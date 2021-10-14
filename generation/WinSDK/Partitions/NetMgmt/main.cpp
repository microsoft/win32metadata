#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <lm.h>
#include <lmaccess.h>
#include <lmjoin.h>
#include <atacct.h>
#include <lmalert.h>
#include <lmapibuf.h>
#include <lmaudit.h>
#include <lmconfig.h>
#include <lmerrlog.h>
#include <lmmsg.h>
#include <lmremutl.h>
#include <lmat.h>
#include <lmserver.h>
#include <lmsvc.h>
#include <lmuse.h>
#include <lmwksta.h>
#include <lmerr.h>
#include <lmcons.h>
#include <netevent.h>
#include <nettypes.h>
#include <lmrepl.h>
#include <lmsname.h>
#include <lmuseflg.h>
#include <netcfgn.h>
#include <netcfgx.h>
#include <netprov.h>
//#include <routprot.h> -- won't compile because it includes stm.h which is missing a type
#include <rtinfo.h>
#include <rtutils.h>

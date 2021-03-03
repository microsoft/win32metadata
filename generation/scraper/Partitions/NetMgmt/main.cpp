#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include <windows.h>
#include <sdkddkver.h>

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

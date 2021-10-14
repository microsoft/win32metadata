#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <wmiutils.h>
#include <wbemcli.h>
#include <wbemprov.h>
#include <wbemdisp.h>
#include <wbemads.h>
//#include <wbemglue.h> -- c++ classes
#include <wbemidl.h>
//#include <wbemtime.h> -- c++ classes
#include <wbemtran.h>

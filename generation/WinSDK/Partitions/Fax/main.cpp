#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#define WIN32 1

#include <winfax.h>
#include <faxdev.h>
//#include <faxcom.h> // A uuid on FaxServer conflicts between faxcom.h and faxcomex.h
#include <faxcomex.h>
#include <faxroute.h>
#include <faxext.h>
#include <fxsutility.h>
#include <faxmmc.h>

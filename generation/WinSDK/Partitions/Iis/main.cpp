#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#define MICROSOFT_WINDOWS_WINBASE_H_DEFINE_INTERLOCKED_CPLUSPLUS_OVERLOADS 0

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <iads.h>

#include <ftpext.h>
#include <iadmext.h>
#include <iadmw.h>

//#include <httpserv.h>
#include <httpext.h>
#include <httpfilt.h>
#include <httprequestid.h>
#include <httptrace.h>
#include <hwebcore.h>

//#include <httpcompression.h> -- Can't figure out the lib for this

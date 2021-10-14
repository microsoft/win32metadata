#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <wia.h>
#include <wiamindr_lh.h>

#include <wiavideo.h>
#include <wiadef.h>
#include <wiadevd.h>

#include <wiaintfc.h>
//#include <wiamdef.h> -- won't scan - Error: System.ArgumentOutOfRangeException: Index was out of range. Must be non-negative and less than the size of the collection. (Parameter 'index')
#include <wiamicro.h>
#include <wiamindr.h>
#include <wiatwcmp.h>
//#include <wiautil.h> -- C++ classes
#include <wiawsdsc.h>

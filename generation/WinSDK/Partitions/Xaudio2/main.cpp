#if defined(WIN32METADATA) && !defined(_XM_NO_INTRINSICS_)
#define _XM_NO_INTRINSICS_
#endif
#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <xapo.h>
//#include <xapobase.h> Class implementations we don't want emitted
#include <xapofx.h>
#include <xaudio2.h>
#include <xaudio2fx.h>
#include <hrtfapoapi.h>
#include <xapo.h>

#include <x3daudio.h>

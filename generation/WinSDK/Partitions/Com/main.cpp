#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS
#define NONAMELESSUNION
#define USE_COM_CONTEXT_DEF

#include "intrinfix.h"
#include "windows.fixed.h"

#include <sdkddkver.h>

#include <wtypes.h>
#include <olectl.h>
#include <vbinterf.h>
#include <ocidl.h>
#include <docobj.h>
#include <oleidl.h>
#include <objidl.h>
#include <oledlg.h>
#include <ole2.h>
#include <objbase.h>

#include <comcat.h>
#include <ctxtcall.h>


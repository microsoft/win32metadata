#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#define IN _In_
#define OUT _Out_

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
#include <callobj.h>
#include <messagedispatcherapi.h>
#include <ctxtcall.h>

#include <ichannelcredentials.h>

#include <mtx.h>
#include <mtxadmin.h>
#include <mtxattr.h>

#include <idispids.h>

#include <oaidl.h>
#include <oleauto.h>
#include <olectl.h>

#include <DispEx.h>

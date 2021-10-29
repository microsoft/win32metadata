#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

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

#include <mtx.h>
#include <mtxadmin.h>
#include <mtxattr.h>

/*
#include <urlmon.h>
#include <accctrl.h>
#include <rpcdce.h>
#include <winerror.h>
#include <combaseapi.h>
#include <objidlbase.h>
#include <wtypesbase.h>
#include <eventsys.h>
#include <txlogpub.h>
#include <shobjidl.h>
#include <iaccess.h>
//#include <unknwnbase.h>
//#include <unknwn.h>
#include <imessagedispatcher.h>
#include <dmerror.h>
#include <roapi.h>
#include <guiddef.h>
#include <winddi.h>
*/

#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <propkeydef.h>
#define DEFINE_DEVSVCGUID DEFINE_GUID
#define DEFINE_DEVSVCPROPKEY DEFINE_PROPERTYKEY

#include <icontact.h>
#include <contactaggregation.h>
#include <icontactproperties.h>

#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <propkeydef.h>
#define DEFINE_DEVSVCGUID DEFINE_GUID
#define DEFINE_DEVSVCPROPKEY DEFINE_PROPERTYKEY

#include <devpropdef.h>

#include <portabledevice.h>
#include <portabledevicetypes.h>
#include <portabledeviceapi.h>
#include <portabledeviceconnectapi.h>
#include <wpdmtpextensions.h>
#include <wpdshellextension.h>
#include <bridgedeviceservice.h>
#include <deviceservices.h>
#include <calendardeviceservice.h>
#include <dmprocessxmlfiltered.h>
#include <hintsdeviceservice.h>
#include <messagedeviceservice.h>
#include <metadatadeviceservice.h>
#include <notesdeviceservice.h>
#include <radiomgr.h>
#include <statusdeviceservice.h>
#include <syncdeviceservice.h>
#include <taskdeviceservice.h>
#include <contactdeviceservice.h>
#include <ringtonedeviceservice.h>
#include <anchorsyncdeviceservice.h>
#include <fullenumsyncdeviceservice.h>

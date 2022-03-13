#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

//#define RO_NO_TEMPLATE_NAME

#include <dispatcherqueue.h>
#include <accountssettingspaneinterop.h>
#include <appserviceinterop.h>
#include <CastingInterop.h>
#include <dragdropinterop.h>
#include <inputpaneinterop.h>
#include <PlayToManagerInterop.h>
#include <RemoteSystemsInterop.h>
#include <UIViewSettingsInterop.h>
#include <useractivityinterop.h>
#include <UserConsentVerifierInterop.h>
#include <WebAuthenticationCoreManagerInterop.h>

#include <hstring.h>
#include <winstring.h>
#include <restrictederrorinfo.h>
#include <roapi.h>
#include <robuffer.h>
#include <roerrorapi.h>
#include <rometadata.h>
//#include <rometadataapi.h>
//#include <rometadataresolution.h>
#include <roparameterizediid.h>
#include <roregistrationapi.h>
#include <shcore.h>
#include <memorybuffer.h>
#include <activation.h>
#include <weakreference.h>

#include <msajtransport.h>
#include <systemmediatransportcontrolsinterop.h>
#include <sharewindowcommandsourceinterop.h>
#include <messagedispatcherapi.h>
#include <CoreWindow.h>
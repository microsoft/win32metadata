#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include <windows.h>
#include <sdkddkver.h>

//#define RO_NO_TEMPLATE_NAME

#include <accountssettingspaneinterop.h>
#include <appserviceinterop.h>
#include <CastingInterop.h>
#include <dragdropinterop.h>
#include <inputpaneinterop.h>
#include <PlayToManagerInterop.h>
#include <Print3DManagerInterop.h>
#include <PrintManagerInterop.h>
#include <RemoteSystemsInterop.h>
#include <UIViewSettingsInterop.h>
#include <useractivityinterop.h>
#include <UserConsentVerifierInterop.h>
#include <WebAuthenticationCoreManagerInterop.h>
#include <windows.data.pdf.interop.h>
#include <Windows.Devices.Display.Core.Interop.h>
#include <Windows.Graphics.Capture.Interop.h>
#include <windows.graphics.directx.direct3d11.interop.h>
#include <windows.graphics.imaging.interop.h>
#include <windows.media.core.interop.h>
#include <windows.ui.xaml.media.dxinterop.h>

#include <windows.graphics.effects.interop.h>
#include <windows.graphics.interop.h>
#include <windows.ui.composition.interop.h>
#include <windows.ui.xaml.interop.h>
//#include <Windows.Web.UI.Interop.h> The interfaces make use of templates which ClangSharp can't yet correctly emit

/*
#include <winnt.h>
#include <winstring.h>
//#include <activation.h>
//#include <activationregistration.h>
//#include <asyncinfo.h>
//#include <combaseapi.h>
//#include <corewindow.h>
//#include <eventtoken.h>
//#include <hstring.h>
#include <inputpaneinterop.h>
//#include <inspectable.h>
//#include <ivectorchangedeventargs.h>
#include <memorybuffer.h>
//#include <objidl.h>
#include <playtomanagerinterop.h>
#include <printmanagerinterop.h>
#include <remotesystemadditionalinfo.h>
//#include <restrictederrorinfo.h>
//#include <roapi.h>
//#include <robuffer.h>
//#include <roerrorapi.h>
//#include <rometadata.h>
//#include <rometadataapi.h>
//#include <rometadataresolution.h>
//#include <roparameterizediid.h>
//#include <roregistrationapi.h>
#include <shcore.h>
#include <shobjidl_core.h>
//#include <weakreference.h>
//#include <webauthenticationcoremanagerinterop.h>
//#include <windows.applicationmodel.core.h>
//#include <windows.applicationmodel.h>
//#include <windows.data.pdf.interop.h>
//#include <windows.devices.display.core.interop.h>
//#include <windows.foundation.collections.h>
//#include <windows.foundation.h>
#include <windows.graphics.capture.interop.h>
#include <windows.graphics.directx.direct3d11.interop.h>
#include <windows.graphics.effects.interop.h>
#include <windows.graphics.imaging.interop.h>
#include <windows.media.core.interop.h>
#include <windows.ui.composition.interop.h>
//#include <windows.ui.xaml.hosting.referencetracker.h>
#include <windows.ui.xaml.media.dxinterop.h>
//#include <windowsstoragecom.h>
*/
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
#include <alljoyn_c\AjAPI.h>
#include <windows.devices.alljoyn.interop.h>
#include <windows.ai.machinelearning.native.h>
#include <Windows.Graphics.Holographic.Interop.h>
#include <windows.graphics.printing.workflow.native.h>
#include <windows.security.isolation.isolatedenvironmentinterop.h>
#include <windows.ui.xaml.hosting.desktopwindowxamlsource.h>
#include <windows.ui.xaml.hosting.referencetracker.h>
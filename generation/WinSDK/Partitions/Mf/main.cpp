#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <camerauicontrol.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3d11_4.h>
#include <d3d12video.h>
#include <d3d9.h>
#include <d3d9types.h>
#include <d3d9caps.h>
#include <wmcodecdsp.h>
#include <dxva9typ.h>
#include <dxva.h>
#include <uuids.h>
#include <codecapi.h>
//#include <icodecapi.h>
#include <dxvahd.h>
#include <opmapi.h>
//#include <ksopmapi.h>
#include <mfidl.h>
#include <wmcontainer.h>
#include <mfobjects.h>
#include <mfcaptureengine.h>
#include <mfd3d12.h>
#include <mfapi.h>
#include <mftransform.h>
#include <mfmediaengine.h>
#include <mfmp2dlna.h>
#include <mfreadwrite.h>
#include <evr.h>
#include <dxva2api.h>
#include <mfplay.h>
#include <mfsharingengine.h>
#include <evr9.h>
#include <mfmediacapture.h>
#include <mfspatialaudio.h>
#include <mfcontentdecryptionmodule.h>
#include <mferror.h>
#include <mfvirtualcamera.h>
#include <opmxbox.h>
#include <playto.h>

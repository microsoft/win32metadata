#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <mmsystem.h>

#include <spatialaudiohrtf.h>
#include <audioendpoints.h>
#include <audioengineendpoint.h>
#include <spatialaudioclient.h>
#include <mmdeviceapi.h>
#include <devicetopology.h>
#include <audioclient.h>
#include <endpointvolume.h>
#include <audiopolicy.h>
#include <spatialaudiometadata.h>
#include <audiosessiontypes.h>
#include <functiondiscoverykeys_devpkey.h>
#include <audioenginebaseapo.h>

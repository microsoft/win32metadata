#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <mmsystem.h>

// Keeps devicetopology.h from bringing in the IKs* stuff
#include <ks.h>
#include <ksmedia.h>

#include <spatialaudiohrtf.h>
#include <spatialaudioclient.h>
#include <mmeapi.h>
#include <mmdeviceapi.h>
#include <devicetopology.h>
#include <audioclient.h>
#include <audiopolicy.h>
#include <spatialaudiometadata.h>
#include <audiosessiontypes.h>
#include <functiondiscoverykeys_devpkey.h>
#include <audioclientactivationparams.h>
#include <audiostatemonitorapi.h>
#include <msacm.h>
#include <playsoundapi.h>
#include <msacmdrv.h>

#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>
#include <commdlg.h>

#define MMNOJOYDEV

#include <ks.h>
#include <ksmedia.h>

#include <combaseapi.h>
#include <mmeapi.h>
#include <mmreg.h>
#include <mmsystem.h>
#include <digitalv.h>
#include <vfw.h>
#include <joystickapi.h>
#include <mmddk.h>
#include <mmiscapi.h>
#include <timeapi.h>
#include <mciapi.h>
#include <minwindef.h>
#include <corecrt_io.h>
#include <asferr.h>
#include <mciavi.h>
#include <msacmdlg.h>
#include <nserror.h>
#include <vfwext.h>

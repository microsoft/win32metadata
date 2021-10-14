#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <winbase.h>
#include <winuser.h>
#include <audioengineendpoint.h>
#include <processthreadsapi.h>
#include <wbemcli.h>
#include <rdpencomapi.h>
#include <tsuserex.h>
#include <tsgpolicyengine.h>
#include <tsgauthenticationengine.h>
#include <wtsapi32.h>
#include <tssbx.h>
#include <cchannel.h>
#include <pchannel.h>
#include <audioapotypes.h>
#include <workspaceruntime.h>
#include <sessdirpublictypes.h>
#include <sbtsv.h>
#include <tspubplugincom.h>
#include <tspubplugin2com.h>
#include <workspaceruntimeclientext.h>
#include <workspaceax.h>
#include <wtshintapi.h>
#include <tsvirtualchannels.h>
#include <wrdsgraphicschannels.h>
#include <wtsdefs.h>
#include <wtsprotocol.h>
#include <rdpappcontainerclient.h>
#include <remotesystemadditionalinfo.h>

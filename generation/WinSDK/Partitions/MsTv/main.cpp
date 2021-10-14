#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <ks.h>
#include <ksmedia.h>

#include <tuner.h>
#include <segment.h>
#include <msvidctl.h>
#include <regbag.h>
#include <bdatypes.h>
#include <sbe.h>
#include <encdec.h>
#include <tvratings.h>
#include <mpeg2data.h>
#include <atscpsipparser.h>
#include <dsattrib.h>
#include <bdaiface.h>
#include <bdatif.h>
#include <mpeg2psiparser.h>
#include <dvbsiparser.h>
#include <strmif.h>
#include <mpeg2structs.h>
#include <bdamedia.h>
//#include <bdaiface_enums.h>
#include <mpeg2bits.h>
#include <atsmedia.h>
//#include <tune.h> -- C++ classes
//#include <tvratings_enum.h> -- duplicates stuff from above


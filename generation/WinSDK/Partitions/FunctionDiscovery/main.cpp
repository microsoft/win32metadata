#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

//#include <functiondiscoverycategories.h>
//#include <functiondiscoveryconstraints.h>
//#include <functiondiscoverykeys.h>
//#include <functiondiscoveryapi.h> 
#include <functiondiscoveryprovider.h> // Includes the ones above it
#include <pnpxassoc.h>
#include <wsdxml.h>
//#include <wsdxmldom.h>
#include <wsdbase.h>
#include <wsdtypes.h>
#include <wsdutil.h>
#include <wsdhost.h>
#include <wsdclient.h>
#include <wsddisco.h>
#include <wsdattachment.h>

#include <functiondiscovery.h>
#include <functiondiscoverycategories.h>
#include <functiondiscoveryconstraints.h>
#include <functiondiscoveryerror.h>

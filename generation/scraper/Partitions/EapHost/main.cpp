#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <eaptypes.h>
#include <eaphostpeertypes.h>
#include <eapmethodtypes.h>
#include <eaphosterror.h>
#include <eaphostpeerconfigapis.h>
#include <eappapis.h>
#include <eapmethodpeerapis.h>
#include <eapauthenticatoractiondefine.h>
#include <eapmethodauthenticatorapis.h>
#include <eapauthenticatortypes.h>

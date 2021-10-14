#define SECURITY_WIN32 // For sspi.h

#include "windows.fixed.h"
#include <sdkddkver.h>

// Need to file a bug against ClangSharp as AdoFields won't scan
#include <adoint.h>
//#include <adoctint.h> -- clashes with adoint.h
#include <adodef.h>
//#include <adogpool_backcompat.h> -- can't be included directly
//#include <adogpool.h> -- can't be included directly
#include <adoguids.h>
#include <adoid.h>
//#include <adoint_backcompat.h> -- can't be included directly
#include <adojet.h>
#include <adomd.h>
#include <icrsint.h>

#define SECURITY_WIN32 // For sspi.h

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <objbase.h>

#include <BiDiSpl.h> 
#include <filterpipeline.h>
#include <msxml6.h>

#define USERMODE_DRIVER
#include <winddi.h>
#undef USERMODE_DRIVER

#include <compstui.h>
#include <winspool.h>
#include <mxdc.h>
#include <winddiui.h>
#include <printoem.h>
#include <prcomoem.h>
#include <prdrvcom.h>
#include <PrinterExtension.h>
#include <prnasnot.h>
#include <prnasntp.h>
#include <prntfont.h>
#include <tcpxcv.h>
#include <usbprint.h>
extern "C" {
#include <winppi.h>
}
#include <winsplp.h>
#include <xpsrassvc.h>
#include <imgerror.h>
#include <printerextensiondispid.h>
#include <printpreview.h>

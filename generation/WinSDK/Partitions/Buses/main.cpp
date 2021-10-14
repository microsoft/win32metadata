#define SECURITY_WIN32 // For sspi.h

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <usb.h>
#include <genericusbfnioctl.h>
#include <usbuser.h>
#include <winusb.h>
#include <winusbio.h>

#include <usbfnbase.h>
//#include <usbioctl.h> -- doesn't compile
#include <usbscan.h>

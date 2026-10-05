#define SECURITY_WIN32 // For sspi.h

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <bluetoothapis.h>
#include <bluetoothleapis.h>
#include <bthdef.h>
#include <bthledef.h>
#include <ws2bth.h>
#include <bthsdpdef.h>
//#include <bthioctl.h> -- won't compile due to: #pragma detect_mismatch("ODR_violation_bthioctl_mismatch", "1")


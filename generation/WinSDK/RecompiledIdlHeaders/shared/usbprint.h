/*++

Copyright (c) 1998 - 2000  Microsoft Corporation

Module Name:

    ioctl.h

Abstract:

        

Environment:

    Kernel & user mode

Revision History:


--*/

#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

// USBPRINT {28D78FAD-5A12-11d1-AE5B-0000F803A8C2}
DEFINE_GUID(GUID_DEVINTERFACE_USBPRINT, 0x28d78fad, 0x5a12, 0x11d1, 0xae, 0x5b, 0x0, 0x0, 0xf8, 0x3, 0xa8, 0xc2);

// IPP over USB {f2f40381-f46d-4e51-bce7-62de6cf2d098}
DEFINE_GUID(GUID_DEVINTERFACE_IPPUSB_PRINT, 0xf2f40381, 0xf46d, 0x4e51, 0xbc, 0xe7, 0x62, 0xde, 0x6c, 0xf2, 0xd0, 0x98);

// USB Printer Interface types
#define USB_PRINTER_INTERFACE_CLASSIC 1   // Has only 7-1-2 alternate config
#define USB_PRINTER_INTERFACE_IPP     2   // Has only 7-1-4 alternate config
#define USB_PRINTER_INTERFACE_DUAL    3   // Has both 7-1-2 and 7-1-4 alternate configs

#define USBPRINT_IOCTL_INDEX  0x0000


#define IOCTL_USBPRINT_GET_LPT_STATUS     CTL_CODE(FILE_DEVICE_UNKNOWN,  \
                                                   USBPRINT_IOCTL_INDEX+12,\
                                                   METHOD_BUFFERED,  \
                                                   FILE_ANY_ACCESS)

#define IOCTL_USBPRINT_GET_1284_ID        CTL_CODE(FILE_DEVICE_UNKNOWN,  \
                                                   USBPRINT_IOCTL_INDEX+13,\
                                                   METHOD_BUFFERED,  \
                                                   FILE_ANY_ACCESS)

#define IOCTL_USBPRINT_VENDOR_SET_COMMAND CTL_CODE(FILE_DEVICE_UNKNOWN,  \
                                                   USBPRINT_IOCTL_INDEX+14,\
                                                   METHOD_BUFFERED,  \
                                                   FILE_ANY_ACCESS)

#define IOCTL_USBPRINT_VENDOR_GET_COMMAND CTL_CODE(FILE_DEVICE_UNKNOWN,  \
                                                   USBPRINT_IOCTL_INDEX+15,\
                                                   METHOD_BUFFERED,  \
                                                   FILE_ANY_ACCESS)

#define IOCTL_USBPRINT_SOFT_RESET         CTL_CODE(FILE_DEVICE_UNKNOWN,  \
                                                   USBPRINT_IOCTL_INDEX+16,\
                                                   METHOD_BUFFERED,  \
                                                   FILE_ANY_ACCESS)

//
// Retrieve the current printer protocol code (i.e. USB_PRINTER_PROTOCOL_IPPOVERUSB)
//
#define IOCTL_USBPRINT_GET_PROTOCOL       CTL_CODE(FILE_DEVICE_UNKNOWN,  \
                                                   USBPRINT_IOCTL_INDEX+17,\
                                                   METHOD_BUFFERED,  \
                                                   FILE_ANY_ACCESS)

//
// Set the current printer protocol code (i.e. USB_PRINTER_PROTOCOL_IPPOVERUSB).
//
#define IOCTL_USBPRINT_SET_PROTOCOL       CTL_CODE(FILE_DEVICE_UNKNOWN,  \
                                                   USBPRINT_IOCTL_INDEX+18,\
                                                   METHOD_BUFFERED,  \
                                                   FILE_ANY_ACCESS)

//
// Get the printer protocol capabilities (i.e. USB_PRINTER_INTERFACE_DUAL)
//
#define IOCTL_USBPRINT_GET_INTERFACE_TYPE    CTL_CODE(FILE_DEVICE_UNKNOWN,  \
                                                      USBPRINT_IOCTL_INDEX+19,\
                                                      METHOD_BUFFERED,  \
                                                      FILE_ANY_ACCESS)

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


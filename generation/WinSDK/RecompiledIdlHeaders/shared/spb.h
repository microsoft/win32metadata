/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    spb.h

Abstract:

    This module contains the Simple Peripheral Bus IOCTL interface for
    use by client applications & drivers.

Environment:

    User-mode and kernel-mode.

--*/

#ifndef _SPB_H_
#define _SPB_H_

#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#if (NTDDI_VERSION >= NTDDI_WIN8)

#ifdef _MSC_VER
#pragma once
#endif

#pragma warning(push)
#pragma warning(disable:4480)   // type specifier for enum

//
// When opening an connection to a device attached to the SPB controller,
// this is the root of the file object name.
//

#define SPB_TARGET_NAME_PREFIX L"\\SPB\\"

typedef enum SpbIoctl
{
    IOCTL_SPB_LOCK_CONTROLLER =    CTL_CODE(FILE_DEVICE_CONTROLLER,
                                            0x600,
                                            METHOD_BUFFERED,
                                            FILE_ANY_ACCESS),

    IOCTL_SPB_UNLOCK_CONTROLLER =  CTL_CODE(FILE_DEVICE_CONTROLLER, 
                                            0x601,                  
                                            METHOD_BUFFERED,        
                                            FILE_ANY_ACCESS),

    IOCTL_SPB_EXECUTE_SEQUENCE =   CTL_CODE(FILE_DEVICE_CONTROLLER,   
                                            0x602,                    
                                            METHOD_BUFFERED,          
                                            FILE_ANY_ACCESS),

    IOCTL_SPB_LOCK_CONNECTION =    CTL_CODE(FILE_DEVICE_CONTROLLER,   
                                            0x603,                    
                                            METHOD_BUFFERED,          
                                            FILE_ANY_ACCESS),

    IOCTL_SPB_UNLOCK_CONNECTION =  CTL_CODE(FILE_DEVICE_CONTROLLER,   
                                            0x604,                    
                                            METHOD_BUFFERED,          
                                            FILE_ANY_ACCESS),

    IOCTL_SPB_FULL_DUPLEX =        CTL_CODE(FILE_DEVICE_CONTROLLER,   
                                            0x605,                    
                                            METHOD_BUFFERED,          
                                            FILE_ANY_ACCESS)
}
SpbIoctl, *PSpbIoctl;

typedef enum SPB_TRANSFER_DIRECTION
{
    SpbTransferDirectionNone,
    SpbTransferDirectionFromDevice,
    SpbTransferDirectionToDevice,
    SpbTransferDirectionMax
}
SPB_TRANSFER_DIRECTION, *PSPB_TRANSFER_DIRECTION;

typedef enum SPB_TRANSFER_BUFFER_FORMAT
{
    SpbTransferBufferFormatInvalid,
    SpbTransferBufferFormatSimple,
    SpbTransferBufferFormatList,
    SpbTransferBufferFormatSimpleNonPaged,
    SpbTransferBufferFormatMdl,
    SpbTransferBufferFormatMax
}
SPB_TRANSFER_BUFFER_FORMAT, *PSPB_TRANSFER_BUFFER_FORMAT;

//
// A single entry in a transfer buffer list.
//

typedef struct SPB_TRANSFER_BUFFER_LIST_ENTRY
{
    //
    // The data buffer.
    //

    PVOID Buffer;

    //
    // The length of the buffer in bytes.
    //

    ULONG BufferCb;
}
SPB_TRANSFER_BUFFER_LIST_ENTRY, *PSPB_TRANSFER_BUFFER_LIST_ENTRY;

#ifndef _NTDDK_
#ifndef PMDL
#define PMDL PVOID
#endif
#endif

//
// A buffer - either a simple one-entry buffer or a buffer list
//

typedef struct SPB_TRANSFER_BUFFER 
{
    //
    // the format of the transfer buffer.
    //

    SPB_TRANSFER_BUFFER_FORMAT Format;

#pragma warning(push)
#pragma warning(disable:4201)
    union 
    {
        //
        // Simple buffer or simple non-paged buffer.
        //

        SPB_TRANSFER_BUFFER_LIST_ENTRY Simple;

        // 
        // List of buffers.
        //

        struct
        {
            PSPB_TRANSFER_BUFFER_LIST_ENTRY List;
            ULONG                           ListCe;
        }
        BufferList;

        //
        // MDL format
        //

        PMDL Mdl;
    };
#pragma warning(pop)
}
SPB_TRANSFER_BUFFER, *PSPB_TRANSFER_BUFFER;

//
// A single transfer and its buffer
//

typedef struct SPB_TRANSFER_LIST_ENTRY
{
    //
    // Direction.
    //

    SPB_TRANSFER_DIRECTION Direction;

    //
    // The delay (in us) before starting this transfer.
    //

    ULONG DelayInUs;

    //
    // The buffer to transfer to/from
    //

    SPB_TRANSFER_BUFFER Buffer;
}
SPB_TRANSFER_LIST_ENTRY, *PSPB_TRANSFER_LIST_ENTRY;

FORCEINLINE
SPB_TRANSFER_LIST_ENTRY
SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE(
    _In_ SPB_TRANSFER_DIRECTION Direction,
    _In_ ULONG                  DelayInUs,
    _Pre_writable_byte_size_(BufferCb) PVOID                  Buffer,
    _In_ ULONG                  BufferCb
    )
{
    SPB_TRANSFER_LIST_ENTRY entry;

    entry.Direction = Direction;
    entry.DelayInUs = DelayInUs;
    entry.Buffer.Format = SpbTransferBufferFormatSimple;
    entry.Buffer.Simple.Buffer = Buffer;
    entry.Buffer.Simple.BufferCb = BufferCb;
    return entry;
}

FORCEINLINE
SPB_TRANSFER_LIST_ENTRY
SPB_TRANSFER_LIST_ENTRY_INIT_NON_PAGED(
    _In_ SPB_TRANSFER_DIRECTION Direction,
    _In_ ULONG                  DelayInUs,
    _Pre_writable_byte_size_(BufferCb) PVOID                  Buffer,
    _In_ ULONG                  BufferCb
    )
{
    SPB_TRANSFER_LIST_ENTRY entry;

    entry.Direction = Direction;
    entry.DelayInUs = DelayInUs;
    entry.Buffer.Format = SpbTransferBufferFormatSimpleNonPaged;
    entry.Buffer.Simple.Buffer = Buffer;
    entry.Buffer.Simple.BufferCb = BufferCb;
    return entry;
}

FORCEINLINE
SPB_TRANSFER_LIST_ENTRY
SPB_TRANSFER_LIST_ENTRY_INIT_MDL(
    _In_ SPB_TRANSFER_DIRECTION Direction,
    _In_ ULONG                  DelayInUs,
    _In_ PMDL                   Mdl
    )
{
    SPB_TRANSFER_LIST_ENTRY entry;

    entry.Direction = Direction;
    entry.DelayInUs = DelayInUs;
    entry.Buffer.Format = SpbTransferBufferFormatMdl;
    entry.Buffer.Mdl = Mdl;
    return entry;
}

FORCEINLINE
SPB_TRANSFER_LIST_ENTRY
SPB_TRANSFER_LIST_ENTRY_INIT_BUFFER_LIST(
    _In_ SPB_TRANSFER_DIRECTION          Direction,
    _In_ ULONG                           DelayInUs,
    _In_ SPB_TRANSFER_BUFFER_LIST_ENTRY  BufferList[], 
    _In_ ULONG                           BufferListCe
    )
{
    SPB_TRANSFER_LIST_ENTRY entry;

    entry.Direction = Direction;
    entry.DelayInUs = DelayInUs;
    entry.Buffer.Format = SpbTransferBufferFormatList;
    entry.Buffer.BufferList.List = BufferList;
    entry.Buffer.BufferList.ListCe = BufferListCe;
    return entry;
}
    

//
// a list of transfers to be executed in a sequence.
//

typedef struct SPB_TRANSFER_LIST
{
    //
    // List size - must be set to sizeof(SPB_TRANSFER_LIST)
    //

    _Field_range_(==, sizeof(SPB_TRANSFER_LIST))
    ULONG Size;

    //
    // Reserved flags for internal use - must be zero.
    //

    ULONG Reserved;

    //
    // The number of input or output transfers for this packet.
    // The packet should be followed by this number of transfer descriptors.
    //
    // Transfers must consist of at least one packet.
    //

    ULONG TransferCount;

    //
    // The array of transfer descriptors in the list.
    //

    _Field_size_(TransferCount) SPB_TRANSFER_LIST_ENTRY Transfers[1];
}
SPB_TRANSFER_LIST, *PSPB_TRANSFER_LIST;

//
// A macro to simplify defining a sequence with multiple 
// transfers.
//

#define SPB_TRANSFER_LIST_AND_ENTRIES(n) struct { \
    SPB_TRANSFER_LIST List;                           \
    SPB_TRANSFER_LIST_ENTRY ExtraTransfers[n-1];      \
}

VOID
FORCEINLINE
SPB_TRANSFER_LIST_INIT(
    _Out_ SPB_TRANSFER_LIST *TransferList,
    _In_  ULONG              TransferCount
    )
{
    memset(TransferList, 
           0,
           (sizeof(SPB_TRANSFER_LIST) + 
            (sizeof(SPB_TRANSFER_LIST_ENTRY) * (TransferCount - 1))));
    TransferList->Size = sizeof(SPB_TRANSFER_LIST);
    TransferList->TransferCount = TransferCount;
}

// begin_wpp config
// CUSTOM_TYPE(SPB_TRANSFER_DIRECTION, ItemEnum(_SPB_TRANSFER_DIRECTION));
// CUSTOM_TYPE(SPB_TRANSFER_BUFFER_FORMAT, ItemEnum(_SPB_TRANSFER_BUFFER_FORMAT));
// end_wpp

#endif // NTDDI_VERSION >= NTDDI_WIN8

#endif // WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#endif // _SPB_H_

/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    nvme.h

Abstract:

    NVMe command protocol related definitions

Revision:

    Aug. 2018 - Align to NVMe spec version 1.3.

--*/

#ifndef NVME_INCLUDED
#define NVME_INCLUDED

#include <winapifamily.h>

#pragma region Desktop Family or Storage Package
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PKG_STORAGE)

#if _MSC_VER >= 1200
#pragma once
#pragma warning(push)
#endif

#pragma warning(disable:4214)   // bit field types other than int
#pragma warning(disable:4201)   // nameless struct/union
#pragma warning(disable:4200)   // zero-sized array in struct/union

//
// 3.1.1  Offset 00h: CAP (Controller Capabilities)
//
typedef union {

    struct {
        //LSB

        ULONGLONG MQES      : 16;   // RO - Maximum Queue Entries Supported (MQES)
        ULONGLONG CQR       : 1;    // RO - Contiguous Queues Required (CQR)

                                    // Bit 17, 18 - AMS; RO - Arbitration Mechanism Supported (AMS)
        ULONGLONG AMS_WeightedRoundRobinWithUrgent  : 1;    // Bit 17: Weighted Round Robin with Urgent;
        ULONGLONG AMS_VendorSpecific                : 1;    // Bit 18: Vendor Specific.

        ULONGLONG Reserved0 : 5;    // RO - bit 19 ~ 23
        ULONGLONG TO        : 8;    // RO - Timeout (TO)
        ULONGLONG DSTRD     : 4;    // RO - Doorbell Stride (DSTRD)
        ULONGLONG NSSRS     : 1;    // RO - NVM Subsystem Reset Supported (NSSRS)

                                    // Bit 37 ~ 44 - CSS; RO - Command Sets Supported (CSS)
        ULONGLONG CSS_NVM               : 1;    // Bit 37: NVM command set
        ULONGLONG CSS_Reserved0         : 1;    // Bit 38: Reserved
        ULONGLONG CSS_Reserved1         : 1;    // Bit 39: Reserved
        ULONGLONG CSS_Reserved2         : 1;    // Bit 40: Reserved
        ULONGLONG CSS_Reserved3         : 1;    // Bit 41: Reserved
        ULONGLONG CSS_Reserved4         : 1;    // Bit 42: Reserved
        ULONGLONG CSS_Reserved5         : 1;    // Bit 43: Reserved
        ULONGLONG CSS_Reserved6         : 1;    // Bit 44: Reserved

        ULONGLONG Reserved2 : 3;    // RO - bit 45 ~ 47
        ULONGLONG MPSMIN    : 4;    // RO - Memory Page Size Minimum (MPSMIN)
        ULONGLONG MPSMAX    : 4;    // RO - Memory Page Size Maximum (MPSMAX)
        ULONGLONG Reserved3 : 8;    // RO - bit 56 ~ 63

        //MSB
    } DUMMYSTRUCTNAME;

    ULONGLONG AsUlonglong;

} NVME_CONTROLLER_CAPABILITIES, *PNVME_CONTROLLER_CAPABILITIES;

//
// 3.1.2  Offset 08h: VS (Version)
//
typedef union {

    struct {
        //LSB
        ULONG TER       : 8;      // Tertiary Version Number (TER)
        ULONG MNR       : 8;      // Minor Version Number (MNR)
        ULONG MJR       : 16;     // Major Version Number (MJR)
        //MSB
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_VERSION, *PNVME_VERSION;

//
// 3.1.5  Offset 14h: CC (Controller Configuration)
//
typedef enum {

    NVME_CC_SHN_NO_NOTIFICATION     = 0,
    NVME_CC_SHN_NORMAL_SHUTDOWN     = 1,
    NVME_CC_SHN_ABRUPT_SHUTDOWN     = 2,

} NVME_CC_SHN_SHUTDOWN_NOTIFICATIONS;

typedef union {

    struct {
        //LSB
        ULONG EN        : 1;        // RW - Enable (EN)
        ULONG Reserved0 : 3;        // RO
        ULONG CSS       : 3;        // RW - I/O  Command Set Selected (CSS)
        ULONG MPS       : 4;        // RW - Memory Page Size (MPS)
        ULONG AMS       : 3;        // RW - Arbitration Mechanism Selected (AMS)
        ULONG SHN       : 2;        // RW - Shutdown Notification (SHN)
        ULONG IOSQES    : 4;        // RW - I/O  Submission Queue Entry Size (IOSQES)
        ULONG IOCQES    : 4;        // RW - I/O  Completion Queue Entry Size (IOCQES)
        ULONG Reserved1 : 8;        // RO
        //MSB
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_CONTROLLER_CONFIGURATION, *PNVME_CONTROLLER_CONFIGURATION;

//
// 3.1.6  Offset 1Ch: CSTS (Controller Status)
//
typedef enum {

    NVME_CSTS_SHST_NO_SHUTDOWN          = 0,
    NVME_CSTS_SHST_SHUTDOWN_IN_PROCESS  = 1,
    NVME_CSTS_SHST_SHUTDOWN_COMPLETED   = 2,

} NVME_CSTS_SHST_SHUTDOWN_STATUS;

typedef union {

    struct {
        ULONG RDY       : 1;        // RO - Ready (RDY)
        ULONG CFS       : 1;        // RO - Controller Fatal Status (CFS)
        ULONG SHST      : 2;        // RO - Shutdown Status (SHST)
        ULONG NSSRO     : 1;        // RW1C - NVM Subsystem Reset Occurred (NSSRO)
        ULONG PP        : 1;        // RO - Processing Paused (PP)

        ULONG Reserved0 : 26;       // RO
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_CONTROLLER_STATUS, *PNVME_CONTROLLER_STATUS;

//
// 3.1.7  Offset 20h: NSSR (NVM Subsystem Reset)
//
typedef struct _NVME_NVM_SUBSYSTEM_RESET {

    ULONG   NSSRC;                  // RW - NVM Subsystem Reset Control (NSSRC)

} NVME_NVM_SUBSYSTEM_RESET, *PNVME_NVM_SUBSYSTEM_RESET;

//
// 3.1.8  Offset 24h: AQA (Admin Queue Attributes)
//
typedef union {

    struct {
        //LSB
        ULONG ASQS      : 12;       // RW - Admin  Submission Queue Size (ASQS)
        ULONG Reserved0 : 4;        // RO
        ULONG ACQS      : 12;       // RW - Admin  Completion Queue Size (ACQS)
        ULONG Reserved1 : 4;        // RO
        //MSB
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_ADMIN_QUEUE_ATTRIBUTES, *PNVME_ADMIN_QUEUE_ATTRIBUTES;

//
// 3.1.9  Offset 28h: ASQ (Admin Submission Queue Base Address)
//
typedef union {

    struct {
        //LSB
        ULONGLONG Reserved0 : 12;       // RO
        ULONGLONG ASQB      : 52;       // RW - Admin Submission Queue Base (ASQB)
        //MSB
    } DUMMYSTRUCTNAME;

    ULONGLONG AsUlonglong;

} NVME_ADMIN_SUBMISSION_QUEUE_BASE_ADDRESS, *PNVME_ADMIN_SUBMISSION_QUEUE_BASE_ADDRESS;

//
// 3.1.10  Offset 30h: ACQ (Admin Completion Queue Base Address)
//
typedef union {

    struct {
        //LSB
        ULONGLONG Reserved0 : 12;       // RO
        ULONGLONG ACQB      : 52;       // RW - Admin Completion Queue Base (ACQB)
        //MSB
    } DUMMYSTRUCTNAME;

    ULONGLONG AsUlonglong;

} NVME_ADMIN_COMPLETION_QUEUE_BASE_ADDRESS, *PNVME_ADMIN_COMPLETION_QUEUE_BASE_ADDRESS;

//
// 3.1.11 Offset 38h: CMBLOC (Controller Memory Buffer Location)
//
typedef union {

    struct {
        //LSB
        ULONG   BIR         : 3;    // RO - Base Indicator Register (BIR)
        ULONG   Reserved    : 9;    // RO
        ULONG   OFST        : 20;   // RO - Offset (OFST)
        //MSB
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CONTROLLER_MEMORY_BUFFER_LOCATION, *PNVME_CONTROLLER_MEMORY_BUFFER_LOCATION;

//
// 3.1.12 Offset 3Ch: CMBSZ (Controller Memory Buffer Size)
//
typedef enum {

    NVME_CMBSZ_SIZE_UNITS_4KB       = 0,
    NVME_CMBSZ_SIZE_UNITS_64KB      = 1,
    NVME_CMBSZ_SIZE_UNITS_1MB       = 2,
    NVME_CMBSZ_SIZE_UNITS_16MB      = 3,
    NVME_CMBSZ_SIZE_UNITS_256MB     = 4,
    NVME_CMBSZ_SIZE_UNITS_4GB       = 5,
    NVME_CMBSZ_SIZE_UNITS_64GB      = 6,

} NVME_CMBSZ_SIZE_UNITS;

typedef union {

    struct {
        //LSB
        ULONG   SQS         : 1;    // RO - Submission Queue Support (SQS)
        ULONG   CQS         : 1;    // RO - Completion Queue Support (CQS)
        ULONG   LISTS       : 1;    // RO - PRP SGL List Support (LISTS)
        ULONG   RDS         : 1;    // RO - Read Data Support (RDS)
        ULONG   WDS         : 1;    // RO - Write Data Support (WDS)
        ULONG   Reserved    : 3;    // RO
        ULONG   SZU         : 4;    // RO - Size Units (SZU)
        ULONG   SZ          : 20;   // RO - Size (SZ)
        //MSB
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CONTROLLER_MEMORY_BUFFER_SIZE, *PNVME_CONTROLLER_MEMORY_BUFFER_SIZE;


//
// 3.1.13  Offset (1000h + ((2y) * (4 << CAP.DSTRD))): SQyTDBL (Submission Queue y Tail Doorbell)
//
typedef union {

    struct {
        //LSB
        ULONG SQT       : 16;       // RW - Submission Queue Tail (SQT)
        ULONG Reserved0 : 16;       // RO
        //MSB
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_SUBMISSION_QUEUE_TAIL_DOORBELL, *PNVME_SUBMISSION_QUEUE_TAIL_DOORBELL;

//
// 3.1.14  Offset  (1000h + ((2y + 1) * (4 << CAP.DSTRD))): CQyHDBL (Completion Queue y Head Doorbell)
//
typedef union {

    struct {
        //LSB
        ULONG CQH       : 16;       // RW - Completion Queue Head (CQH)
        ULONG Reserved0 : 16;       // RO
        //MSB
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_COMPLETION_QUEUE_HEAD_DOORBELL, *PNVME_COMPLETION_QUEUE_HEAD_DOORBELL;

typedef struct {

    NVME_CONTROLLER_CAPABILITIES    CAP;                // Controller Capabilities; 8 bytes
    NVME_VERSION                    VS;                 // Version
    ULONG                           INTMS;              // Interrupt Mask Set
    ULONG                           INTMC;              // Interrupt Mask Clear
    NVME_CONTROLLER_CONFIGURATION   CC;                 // Controller Configuration
    ULONG                           Reserved0;
    NVME_CONTROLLER_STATUS          CSTS;               // Controller Status
    NVME_NVM_SUBSYSTEM_RESET        NSSR;               // NVM Subsystem Reset (Optional)

    NVME_ADMIN_QUEUE_ATTRIBUTES                 AQA;    // Admin Queue Attributes
    NVME_ADMIN_SUBMISSION_QUEUE_BASE_ADDRESS    ASQ;    // Admin Submission Queue Base Address; 8 bytes
    NVME_ADMIN_COMPLETION_QUEUE_BASE_ADDRESS    ACQ;    // Admin Completion Queue Base Address; 8 bytes

    NVME_CONTROLLER_MEMORY_BUFFER_LOCATION      CMBLOC; // Controller Memory Buffer Location (Optional)
    NVME_CONTROLLER_MEMORY_BUFFER_SIZE          CMBSZ;  // Controller Memory Buffer Size (Optional)

    ULONG                           Reserved2[944];     // 40h ~ EFFh
    ULONG                           Reserved3[64];      // F00h ~ FFFh, Command Set Specific

    ULONG                           Doorbells[0];       // Start of the first Doorbell register. (Admin SQ Tail Doorbell)

} NVME_CONTROLLER_REGISTERS, *PNVME_CONTROLLER_REGISTERS;


//
// Command completion status
// The "Phase Tag" field and "Status Field" are separated in spec. We define them in the same data structure to ease the memory access from software.
//
typedef union {

    struct {
        USHORT  P           : 1;        // Phase Tag (P)

        USHORT  SC          : 8;        // Status Code (SC)
        USHORT  SCT         : 3;        // Status Code Type (SCT)
        USHORT  Reserved    : 2;
        USHORT  M           : 1;        // More (M)
        USHORT  DNR         : 1;        // Do Not Retry (DNR)
    } DUMMYSTRUCTNAME;

    USHORT AsUshort;

} NVME_COMMAND_STATUS, *PNVME_COMMAND_STATUS;

//
// Command completion entry
//
typedef struct {

    ULONG   DW0;
    ULONG   Reserved;

    union {
        struct {
            USHORT  SQHD;               // SQ Head Pointer (SQHD)
            USHORT  SQID;               // SQ Identifier (SQID)
        } DUMMYSTRUCTNAME;

        ULONG   AsUlong;
    } DW2;

    union {
        struct {
            USHORT              CID;    // Command Identifier (CID)
            NVME_COMMAND_STATUS Status;
        } DUMMYSTRUCTNAME;

        ULONG   AsUlong;
    } DW3;

} NVME_COMPLETION_ENTRY, *PNVME_COMPLETION_ENTRY;

//
// Completion entry DW0 for NVME_ADMIN_COMMAND_ASYNC_EVENT_REQUEST
//

typedef enum {

    NVME_ASYNC_EVENT_TYPE_ERROR_STATUS              = 0,
    NVME_ASYNC_EVENT_TYPE_HEALTH_STATUS             = 1,
    NVME_ASYNC_EVENT_TYPE_NOTICE                    = 2,
    NVME_ASYNC_EVENT_TYPE_IO_COMMAND_SET_STATUS     = 6,
    NVME_ASYNC_EVENT_TYPE_VENDOR_SPECIFIC           = 7,

} NVME_ASYNC_EVENT_TYPES;

//
// Error Status: NVME_ASYNC_EVENT_TYPE_ERROR_STATUS
//
typedef enum {

    NVME_ASYNC_ERROR_INVALID_SUBMISSION_QUEUE           = 0,
    NVME_ASYNC_ERROR_INVALID_DOORBELL_WRITE_VALUE       = 1,
    NVME_ASYNC_ERROR_DIAG_FAILURE                       = 2,
    NVME_ASYNC_ERROR_PERSISTENT_INTERNAL_DEVICE_ERROR   = 3,
    NVME_ASYNC_ERROR_TRANSIENT_INTERNAL_DEVICE_ERROR    = 4,
    NVME_ASYNC_ERROR_FIRMWARE_IMAGE_LOAD_ERROR          = 5,

} NVME_ASYNC_EVENT_ERROR_STATUS_CODES;

//
// SMART/Health Status: NVME_ASYNC_EVENT_TYPE_HEALTH_STATUS
//
typedef enum {

    NVME_ASYNC_HEALTH_NVM_SUBSYSTEM_RELIABILITY         = 0,
    NVME_ASYNC_HEALTH_TEMPERATURE_THRESHOLD             = 1,
    NVME_ASYNC_HEALTH_SPARE_BELOW_THRESHOLD             = 2,

} NVME_ASYNC_EVENT_HEALTH_STATUS_CODES;

//
// Notice Status: NVME_ASYNC_EVENT_TYPE_NOTICE
//
typedef enum {

    NVME_ASYNC_NOTICE_NAMESPACE_ATTRIBUTE_CHANGED       = 0,
    NVME_ASYNC_NOTICE_FIRMWARE_ACTIVATION_STARTING      = 1,
    NVME_ASYNC_NOTICE_TELEMETRY_LOG_CHANGED             = 2,

} NVME_ASYNC_EVENT_NOTICE_CODES;

//
// NVM Command Set Status: NVME_ASYNC_EVENT_TYPE_IO_COMMAND_SET_STATUS
//
typedef enum {

    NVME_ASYNC_IO_CMD_SET_RESERVATION_LOG_PAGE_AVAILABLE    = 0,
    NVME_ASYNC_IO_CMD_SANITIZE_OPERATION_COMPLETED          = 1,

} NVME_ASYNC_EVENT_IO_COMMAND_SET_STATUS_CODES;


typedef struct {

    ULONG   AsyncEventType  : 3;
    ULONG   Reserved0       : 5;
    ULONG   AsyncEventInfo  : 8;
    ULONG   LogPage         : 8;
    ULONG   Reserved1       : 8;

} NVME_COMPLETION_DW0_ASYNC_EVENT_REQUEST, *PNVME_COMPLETION_DW0_ASYNC_EVENT_REQUEST;



//
//  Status Code Type (SCT)
//
typedef enum {

    NVME_STATUS_TYPE_GENERIC_COMMAND    = 0,
    NVME_STATUS_TYPE_COMMAND_SPECIFIC   = 1,
    NVME_STATUS_TYPE_MEDIA_ERROR        = 2,
    NVME_STATUS_TYPE_VENDOR_SPECIFIC    = 7,

} NVME_STATUS_TYPES;

//
//  Status Code (SC) of NVME_STATUS_TYPE_GENERIC_COMMAND
//
typedef enum {

    NVME_STATUS_SUCCESS_COMPLETION                              = 0x00,
    NVME_STATUS_INVALID_COMMAND_OPCODE                          = 0x01,
    NVME_STATUS_INVALID_FIELD_IN_COMMAND                        = 0x02,
    NVME_STATUS_COMMAND_ID_CONFLICT                             = 0x03,
    NVME_STATUS_DATA_TRANSFER_ERROR                             = 0x04,
    NVME_STATUS_COMMAND_ABORTED_DUE_TO_POWER_LOSS_NOTIFICATION  = 0x05,
    NVME_STATUS_INTERNAL_DEVICE_ERROR                           = 0x06,
    NVME_STATUS_COMMAND_ABORT_REQUESTED                         = 0x07,
    NVME_STATUS_COMMAND_ABORTED_DUE_TO_SQ_DELETION              = 0x08,
    NVME_STATUS_COMMAND_ABORTED_DUE_TO_FAILED_FUSED_COMMAND     = 0x09,
    NVME_STATUS_COMMAND_ABORTED_DUE_TO_FAILED_MISSING_COMMAND   = 0x0A,
    NVME_STATUS_INVALID_NAMESPACE_OR_FORMAT                     = 0x0B,
    NVME_STATUS_COMMAND_SEQUENCE_ERROR                          = 0x0C,
    NVME_STATUS_INVALID_SGL_LAST_SEGMENT_DESCR                  = 0x0D,
    NVME_STATUS_INVALID_NUMBER_OF_SGL_DESCR                     = 0x0E,
    NVME_STATUS_DATA_SGL_LENGTH_INVALID                         = 0x0F,
    NVME_STATUS_METADATA_SGL_LENGTH_INVALID                     = 0x10,
    NVME_STATUS_SGL_DESCR_TYPE_INVALID                          = 0x11,
    NVME_STATUS_INVALID_USE_OF_CONTROLLER_MEMORY_BUFFER         = 0x12,
    NVME_STATUS_PRP_OFFSET_INVALID                              = 0x13,
    NVME_STATUS_ATOMIC_WRITE_UNIT_EXCEEDED                      = 0x14,
    NVME_STATUS_OPERATION_DENIED                                = 0x15,
    NVME_STATUS_SGL_OFFSET_INVALID                              = 0x16,
    NVME_STATUS_RESERVED                                        = 0x17,
    NVME_STATUS_HOST_IDENTIFIER_INCONSISTENT_FORMAT             = 0x18,
    NVME_STATUS_KEEP_ALIVE_TIMEOUT_EXPIRED                      = 0x19,
    NVME_STATUS_KEEP_ALIVE_TIMEOUT_INVALID                      = 0x1A,
    NVME_STATUS_COMMAND_ABORTED_DUE_TO_PREEMPT_ABORT            = 0x1B,
    NVME_STATUS_SANITIZE_FAILED                                 = 0x1C,
    NVME_STATUS_SANITIZE_IN_PROGRESS                            = 0x1D,
    NVME_STATUS_SGL_DATA_BLOCK_GRANULARITY_INVALID              = 0x1E,

    NVME_STATUS_DIRECTIVE_TYPE_INVALID                          = 0x70,
    NVME_STATUS_DIRECTIVE_ID_INVALID                            = 0x71,

    NVME_STATUS_NVM_LBA_OUT_OF_RANGE                            = 0x80,
    NVME_STATUS_NVM_CAPACITY_EXCEEDED                           = 0x81,
    NVME_STATUS_NVM_NAMESPACE_NOT_READY                         = 0x82,
    NVME_STATUS_NVM_RESERVATION_CONFLICT                        = 0x83,
    NVME_STATUS_FORMAT_IN_PROGRESS                              = 0x84,

} NVME_STATUS_GENERIC_COMMAND_CODES;

//
//  Status Code (SC) of NVME_STATUS_TYPE_COMMAND_SPECIFIC
//
typedef enum {

    NVME_STATUS_COMPLETION_QUEUE_INVALID                            = 0x00,         // Create I/O Submission Queue
    NVME_STATUS_INVALID_QUEUE_IDENTIFIER                            = 0x01,         // Create I/O Submission Queue, Create I/O Completion Queue, Delete I/O Completion Queue, Delete I/O Submission Queue
    NVME_STATUS_MAX_QUEUE_SIZE_EXCEEDED                             = 0x02,         // Create I/O Submission Queue, Create I/O Completion Queue
    NVME_STATUS_ABORT_COMMAND_LIMIT_EXCEEDED                        = 0x03,         // Abort
    NVME_STATUS_ASYNC_EVENT_REQUEST_LIMIT_EXCEEDED                  = 0x05,         // Asynchronous Event Request
    NVME_STATUS_INVALID_FIRMWARE_SLOT                               = 0x06,         // Firmware Commit
    NVME_STATUS_INVALID_FIRMWARE_IMAGE                              = 0x07,         // Firmware Commit
    NVME_STATUS_INVALID_INTERRUPT_VECTOR                            = 0x08,         // Create I/O Completion Queue
    NVME_STATUS_INVALID_LOG_PAGE                                    = 0x09,         // Get Log Page
    NVME_STATUS_INVALID_FORMAT                                      = 0x0A,         // Format NVM
    NVME_STATUS_FIRMWARE_ACTIVATION_REQUIRES_CONVENTIONAL_RESET     = 0x0B,         // Firmware Commit
    NVME_STATUS_INVALID_QUEUE_DELETION                              = 0x0C,         // Delete I/O Completion Queue
    NVME_STATUS_FEATURE_ID_NOT_SAVEABLE                             = 0x0D,         // Set Features
    NVME_STATUS_FEATURE_NOT_CHANGEABLE                              = 0x0E,         // Set Features
    NVME_STATUS_FEATURE_NOT_NAMESPACE_SPECIFIC                      = 0x0F,         // Set Features
    NVME_STATUS_FIRMWARE_ACTIVATION_REQUIRES_NVM_SUBSYSTEM_RESET    = 0x10,         // Firmware Commit
    NVME_STATUS_FIRMWARE_ACTIVATION_REQUIRES_RESET                  = 0x11,         // Firmware Commit
    NVME_STATUS_FIRMWARE_ACTIVATION_REQUIRES_MAX_TIME_VIOLATION     = 0x12,         // Firmware Commit
    NVME_STATUS_FIRMWARE_ACTIVATION_PROHIBITED                      = 0x13,         // Firmware Commit
    NVME_STATUS_OVERLAPPING_RANGE                                   = 0x14,         // Firmware Commit, Firmware Image Download, Set Features

    NVME_STATUS_NAMESPACE_INSUFFICIENT_CAPACITY                     = 0x15,         // Namespace Management
    NVME_STATUS_NAMESPACE_IDENTIFIER_UNAVAILABLE                    = 0x16,         // Namespace Management
    NVME_STATUS_NAMESPACE_ALREADY_ATTACHED                          = 0x18,         // Namespace Attachment
    NVME_STATUS_NAMESPACE_IS_PRIVATE                                = 0x19,         // Namespace Attachment
    NVME_STATUS_NAMESPACE_NOT_ATTACHED                              = 0x1A,         // Namespace Attachment
    NVME_STATUS_NAMESPACE_THIN_PROVISIONING_NOT_SUPPORTED           = 0x1B,         // Namespace Management
    NVME_STATUS_CONTROLLER_LIST_INVALID                             = 0x1C,         // Namespace Attachment

    NVME_STATUS_DEVICE_SELF_TEST_IN_PROGRESS                        = 0x1D,         // Device Self-test

    NVME_STATUS_BOOT_PARTITION_WRITE_PROHIBITED                     = 0x1E,         // Firmware Commit

    NVME_STATUS_INVALID_CONTROLLER_IDENTIFIER                       = 0x1F,         // Virtualization Management
    NVME_STATUS_INVALID_SECONDARY_CONTROLLER_STATE                  = 0x20,         // Virtualization Management
    NVME_STATUS_INVALID_NUMBER_OF_CONTROLLER_RESOURCES              = 0x21,         // Virtualization Management
    NVME_STATUS_INVALID_RESOURCE_IDENTIFIER                         = 0x22,         // Virtualization Management

    NVME_STATUS_STREAM_RESOURCE_ALLOCATION_FAILED                   = 0x7F,         // Streams Directive

    NVME_STATUS_NVM_CONFLICTING_ATTRIBUTES                          = 0x80,         // Dataset Management, Read, Write
    NVME_STATUS_NVM_INVALID_PROTECTION_INFORMATION                  = 0x81,         // Compare, Read, Write, Write Zeroes
    NVME_STATUS_NVM_ATTEMPTED_WRITE_TO_READ_ONLY_RANGE              = 0x82,         // Dataset Management, Write, Write Uncorrectable, Write Zeroes

} NVME_STATUS_COMMAND_SPECIFIC_CODES;

//
//  Status Code (SC) of NVME_STATUS_TYPE_MEDIA_ERROR
//
typedef enum {

    NVME_STATUS_NVM_WRITE_FAULT                             = 0x80,
    NVME_STATUS_NVM_UNRECOVERED_READ_ERROR                  = 0x81,
    NVME_STATUS_NVM_END_TO_END_GUARD_CHECK_ERROR            = 0x82,
    NVME_STATUS_NVM_END_TO_END_APPLICATION_TAG_CHECK_ERROR  = 0x83,
    NVME_STATUS_NVM_END_TO_END_REFERENCE_TAG_CHECK_ERROR    = 0x84,
    NVME_STATUS_NVM_COMPARE_FAILURE                         = 0x85,
    NVME_STATUS_NVM_ACCESS_DENIED                           = 0x86,
    NVME_STATUS_NVM_DEALLOCATED_OR_UNWRITTEN_LOGICAL_BLOCK  = 0x87,

} NVME_STATUS_MEDIA_ERROR_CODES;

//
// Admin Command Set
//
typedef enum {

    NVME_ADMIN_COMMAND_DELETE_IO_SQ             = 0x00,
    NVME_ADMIN_COMMAND_CREATE_IO_SQ             = 0x01,
    NVME_ADMIN_COMMAND_GET_LOG_PAGE             = 0x02,
    NVME_ADMIN_COMMAND_DELETE_IO_CQ             = 0x04,
    NVME_ADMIN_COMMAND_CREATE_IO_CQ             = 0x05,
    NVME_ADMIN_COMMAND_IDENTIFY                 = 0x06,
    NVME_ADMIN_COMMAND_ABORT                    = 0x08,
    NVME_ADMIN_COMMAND_SET_FEATURES             = 0x09,
    NVME_ADMIN_COMMAND_GET_FEATURES             = 0x0A,
    NVME_ADMIN_COMMAND_ASYNC_EVENT_REQUEST      = 0x0C,
    NVME_ADMIN_COMMAND_NAMESPACE_MANAGEMENT     = 0x0D,

    NVME_ADMIN_COMMAND_FIRMWARE_ACTIVATE        = 0x10,
    NVME_ADMIN_COMMAND_FIRMWARE_COMMIT          = 0x10,         // "Firmware Activate" command has been renamed to "Firmware Commit" command in spec v1.2
    NVME_ADMIN_COMMAND_FIRMWARE_IMAGE_DOWNLOAD  = 0x11,
    NVME_ADMIN_COMMAND_DEVICE_SELF_TEST         = 0x14,
    NVME_ADMIN_COMMAND_NAMESPACE_ATTACHMENT     = 0x15,

    NVME_ADMIN_COMMAND_DIRECTIVE_SEND           = 0x19,
    NVME_ADMIN_COMMAND_DIRECTIVE_RECEIVE        = 0x1A,
    NVME_ADMIN_COMMAND_VIRTUALIZATION_MANAGEMENT= 0x1C,
    NVME_ADMIN_COMMAND_NVME_MI_SEND             = 0x1D,
    NVME_ADMIN_COMMAND_NVME_MI_RECEIVE          = 0x1E,

    NVME_ADMIN_COMMAND_DOORBELL_BUFFER_CONFIG   = 0x7C,

    NVME_ADMIN_COMMAND_FORMAT_NVM               = 0x80,
    NVME_ADMIN_COMMAND_SECURITY_SEND            = 0x81,
    NVME_ADMIN_COMMAND_SECURITY_RECEIVE         = 0x82,
    NVME_ADMIN_COMMAND_SANITIZE                 = 0x84,

} NVME_ADMIN_COMMANDS;

//
// Features for Get/Set Features command
//
typedef enum {

    NVME_FEATURE_ARBITRATION                            = 0x01,
    NVME_FEATURE_POWER_MANAGEMENT                       = 0x02,
    NVME_FEATURE_LBA_RANGE_TYPE                         = 0x03,
    NVME_FEATURE_TEMPERATURE_THRESHOLD                  = 0x04,
    NVME_FEATURE_ERROR_RECOVERY                         = 0x05,
    NVME_FEATURE_VOLATILE_WRITE_CACHE                   = 0x06,
    NVME_FEATURE_NUMBER_OF_QUEUES                       = 0x07,
    NVME_FEATURE_INTERRUPT_COALESCING                   = 0x08,
    NVME_FEATURE_INTERRUPT_VECTOR_CONFIG                = 0x09,
    NVME_FEATURE_WRITE_ATOMICITY                        = 0x0A,
    NVME_FEATURE_ASYNC_EVENT_CONFIG                     = 0x0B,
    NVME_FEATURE_AUTONOMOUS_POWER_STATE_TRANSITION      = 0x0C,
    NVME_FEATURE_HOST_MEMORY_BUFFER                     = 0x0D,
    NVME_FEATURE_TIMESTAMP                              = 0x0E,
    NVME_FEATURE_KEEP_ALIVE                             = 0x0F,
    NVME_FEATURE_HOST_CONTROLLED_THERMAL_MANAGEMENT     = 0x10,
    NVME_FEATURE_NONOPERATIONAL_POWER_STATE             = 0x11,

    NVME_FEATURE_NVM_SOFTWARE_PROGRESS_MARKER           = 0x80,
    NVME_FEATURE_NVM_HOST_IDENTIFIER                    = 0x81,
    NVME_FEATURE_NVM_RESERVATION_NOTIFICATION_MASK      = 0x82,
    NVME_FEATURE_NVM_RESERVATION_PERSISTANCE            = 0x83,

} NVME_FEATURES;


//
// Abort command: parameter
//
typedef union {

    struct {
        ULONG   SQID    : 8;        // Submission Queue Identifier (SQID)
        ULONG   CID     : 16;       // Command Identifier (CID)
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_CDW10_ABORT, *PNVME_CDW10_ABORT;

//
// Identify Command
//
typedef enum {

    NVME_IDENTIFY_CNS_SPECIFIC_NAMESPACE            = 0,
    NVME_IDENTIFY_CNS_CONTROLLER                    = 1,
    NVME_IDENTIFY_CNS_ACTIVE_NAMESPACES             = 2,       // A list of up to 1024 active namespace IDs is returned to the host containing active namespaces with a namespace identifier greater than the value specified in the Namespace Identifier (CDW1.NSID) field.
    NVME_IDENTIFY_CNS_DESCRIPTOR_NAMESPACE          = 3,
    NVME_IDENTIFY_CNS_NVM_SET                       = 4,

} NVME_IDENTIFY_CNS_CODES;

typedef union {

    struct {
        UCHAR   CNS;            // Controller or Namespace Structure (CNS)
        UCHAR   Reserved;
        USHORT  CNTID;          // Controller Identifier (CNTID)
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_CDW10_IDENTIFY, *PNVME_CDW10_IDENTIFY;

typedef union {

    struct {
        USHORT  NVMSETID;       // NVM Set Identifier
        USHORT  Reserved;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_CDW11_IDENTIFY, *PNVME_CDW11_IDENTIFY;


typedef struct {
    USHORT  MP;                 // bit 0:15.    Maximum  Power (MP)

    UCHAR   Reserved0;          // bit 16:23

    UCHAR   MPS         : 1;    // bit 24: Max Power Scale (MPS)
    UCHAR   NOPS        : 1;    // bit 25: Non-Operational State (NOPS)
    UCHAR   Reserved1   : 6;    // bit 26:31

    ULONG   ENLAT;              // bit 32:63.   Entry Latency (ENLAT)
    ULONG   EXLAT;              // bit 64:95.   Exit Latency (EXLAT)

    UCHAR   RRT         : 5;    // bit 96:100.  Relative Read Throughput (RRT)
    UCHAR   Reserved2   : 3;    // bit 101:103

    UCHAR   RRL         : 5;    // bit 104:108  Relative Read Latency (RRL)
    UCHAR   Reserved3   : 3;    // bit 109:111

    UCHAR   RWT         : 5;    // bit 112:116  Relative Write Throughput (RWT)
    UCHAR   Reserved4   : 3;    // bit 117:119

    UCHAR   RWL         : 5;    // bit 120:124  Relative Write Latency (RWL)
    UCHAR   Reserved5   : 3;    // bit 125:127

    USHORT  IDLP;               // bit 128:143  Idle Power (IDLP)

    UCHAR   Reserved6   : 6;    // bit 144:149
    UCHAR   IPS         : 2;    // bit 150:151  Idle Power Scale (IPS)

    UCHAR   Reserved7;          // bit 152:159

    USHORT  ACTP;               // bit 160:175  Active Power (ACTP)

    UCHAR   APW         : 3;    // bit 176:178  Active Power Workload (APW)
    UCHAR   Reserved8   : 3;    // bit 179:181
    UCHAR   APS         : 2;    // bit 182:183  Active Power Scale (APS)


    UCHAR   Reserved9[9];       // bit 184:255.

} NVME_POWER_STATE_DESC, *PNVME_POWER_STATE_DESC;

typedef struct {

    USHORT      Identifier;
    USHORT      ENDGID;

    ULONG       Reserved1;

    ULONG       Random4KBReadTypical;
    ULONG       OptimalWriteSize;
    UCHAR       TotalCapacity[16];
    UCHAR       UnallocatedCapacity[16];

    UCHAR       Reserved2[80];
} NVME_SET_ATTRIBUTES_ENTRY, *PNVME_SET_ATTRIBUTES_ENTRY;


typedef struct {

    UCHAR       IdentifierCount;

    UCHAR       Reserved[127];

    NVME_SET_ATTRIBUTES_ENTRY       Entry[ANYSIZE_ARRAY];

} NVM_SET_LIST, *PNVM_SET_LIST;

typedef struct {
    //
    // byte 0 : 255, Controller Capabilities and Features
    //
    USHORT  VID;                // byte 0:1.    M - PCI Vendor ID (VID)
    USHORT  SSVID;              // byte 2:3.    M - PCI Subsystem Vendor ID (SSVID)
    UCHAR   SN[20];             // byte 4: 23.  M - Serial Number (SN)
    UCHAR   MN[40];             // byte 24:63.  M - Model Number (MN)
    UCHAR   FR[8];              // byte 64:71.  M - Firmware Revision (FR)
    UCHAR   RAB;                // byte 72.     M - Recommended Arbitration Burst (RAB)
    UCHAR   IEEE[3];            // byte 73:75.  M - IEEE OUI Identifier (IEEE). Controller Vendor code.

    struct {
        UCHAR   MultiPCIePorts      : 1;
        UCHAR   MultiControllers    : 1;
        UCHAR   SRIOV               : 1;
        UCHAR   Reserved            : 5;
    } CMIC;                     // byte 76.     O - Controller Multi-Path I/O and Namespace Sharing Capabilities (CMIC)

    UCHAR   MDTS;               // byte 77.     M - Maximum Data Transfer Size (MDTS)
    USHORT  CNTLID;             // byte 78:79.   M - Controller ID (CNTLID)
    ULONG   VER;                // byte 80:83.   M - Version (VER)
    ULONG   RTD3R;              // byte 84:87.   M - RTD3 Resume Latency (RTD3R)
    ULONG   RTD3E;              // byte 88:91.   M - RTD3 Entry Latency (RTD3E)

    struct {
        ULONG   Reserved0                   : 8;
        ULONG   NamespaceAttributeChanged   : 1;
        ULONG   FirmwareActivation          : 1;
        ULONG   Reserved1                   : 22;
    } OAES;                     // byte 92:95.   M - Optional Asynchronous Events Supported (OAES)

   struct {
        ULONG   HostIdentifier128Bit        : 1;
        ULONG   NOPSPMode                   : 1;
        ULONG   NVMSets                     : 1;
        ULONG   ReadRecoveryLevels          : 1;
        ULONG   EnduranceGroups             : 1;
        ULONG   Reserved0                   : 27;
    } CTRATT;                   // byte 96:99.   M - Controller Attributes (CTRATT)

    UCHAR   Reserved0[140];     // byte 100:239.
    UCHAR   ReservedForManagement[16];     // byte 240:255.  Refer to the NVMe Management Interface Specification for definition.

    //
    // byte 256 : 511, Admin Command Set Attributes
    //
    struct {
        USHORT  SecurityCommands    : 1;
        USHORT  FormatNVM           : 1;
        USHORT  FirmwareCommands    : 1;
        USHORT  NamespaceCommands   : 1;
        USHORT  DeviceSelfTest      : 1;
        USHORT  Directives          : 1;
        USHORT  Reserved            : 10;
    } OACS;                     // byte 256:257. M - Optional Admin Command Support (OACS)

    UCHAR   ACL;                // byte 258.    M - Abort Command Limit (ACL)
    UCHAR   AERL;               // byte 259.    M - Asynchronous Event Request Limit (AERL)

    struct {
        UCHAR   Slot1ReadOnly   : 1;
        UCHAR   SlotCount       : 3;
        UCHAR   ActivationWithoutReset  : 1;
        UCHAR   Reserved        : 3;
    } FRMW;                     // byte 260.    M - Firmware Updates (FRMW)

    struct {
        UCHAR   SmartPagePerNamespace   : 1;
        UCHAR   CommandEffectsLog       : 1;
        UCHAR   LogPageExtendedData     : 1;
        UCHAR   TelemetrySupport        : 1;
        UCHAR   Reserved                : 4;
    } LPA;                      // byte 261.    M - Log Page Attributes (LPA)

    UCHAR   ELPE;               // byte 262.    M - Error Log Page Entries (ELPE)
    UCHAR   NPSS;               // byte 263.    M - Number of Power States Support (NPSS)

    struct {
        UCHAR   CommandFormatInSpec : 1;
        UCHAR   Reserved            : 7;
    } AVSCC;                    // byte 264.    M - Admin Vendor Specific Command Configuration (AVSCC)

    struct {
        UCHAR   Supported       : 1;
        UCHAR   Reserved        : 7;
    } APSTA;                    // byte 265.     O - Autonomous Power State Transition Attributes (APSTA)

    USHORT  WCTEMP;             // byte 266:267. M - Warning Composite Temperature Threshold (WCTEMP)
    USHORT  CCTEMP;             // byte 268:269. M - Critical Composite Temperature Threshold (CCTEMP)
    USHORT  MTFA;               // byte 270:271. O - Maximum Time for Firmware Activation (MTFA)
    ULONG   HMPRE;              // byte 272:275. O - Host Memory Buffer Preferred Size (HMPRE)
    ULONG   HMMIN;              // byte 276:279. O - Host Memory Buffer Minimum Size (HMMIN)
    UCHAR   TNVMCAP[16];        // byte 280:295. O - Total NVM Capacity (TNVMCAP)
    UCHAR   UNVMCAP[16];        // byte 296:311. O - Unallocated NVM Capacity (UNVMCAP)

    struct {
        ULONG   RPMBUnitCount           : 3;    // Number of RPMB Units
        ULONG   AuthenticationMethod    : 3;    // Authentication Method
        ULONG   Reserved0               : 10;
        ULONG   TotalSize               : 8;    // Total Size: in 128KB units.
        ULONG   AccessSize              : 8;    // Access Size: in 512B units.
    } RPMBS;                    // byte 312:315. O - Replay Protected Memory Block Support (RPMBS)

    USHORT  EDSTT;              // byte 316:317. O - Extended Device Self-test Time (EDSTT)
    UCHAR   DSTO;               // byte 318.     O - Device Self-test Options (DSTO)
    UCHAR   FWUG;               // byte 319.     M - Firmware Update Granularity (FWUG)
    USHORT  KAS;                // byte 320:321  M - Keep Alive Support (KAS)

    struct {
        USHORT  Supported       : 1;
        USHORT  Reserved        : 15;
    } HCTMA;                    // byte 322:323  O - Host Controlled Thermal Management Attributes (HCTMA)

    USHORT  MNTMT;              // byte 324:325  O - Minimum Thermal Management Temperature (MNTMT)
    USHORT  MXTMT;              // byte 326:327  O - Maximum Thermal Management Temperature (MXTMT)

    struct {
        ULONG   CryptoErase             : 1;     // Controller supports Crypto Erase Sanitize
        ULONG   BlockErase              : 1;     // Controller supports Block Erase Sanitize
        ULONG   Overwrite               : 1;     // Controller supports Overwrite Santize
        ULONG   Reserved                : 29;
    } SANICAP;                  // byte 328:331  O - Sanitize Capabilities (SANICAP)

    USHORT  NSETIDMAX;          // byte 332:333  O - NVM Set Identifier Maximum

    UCHAR   Reserved1[178];     // byte 334:511.

    //
    // byte 512 : 703, NVM Command Set Attributes
    //
    struct {
        UCHAR   RequiredEntrySize   : 4;    // The value is in bytes and is reported as a power of two (2^n).
        UCHAR   MaxEntrySize        : 4;    // This value is larger than or equal to the required SQ entry size.  The value is in bytes and is reported as a power of two (2^n).
    } SQES;                     // byte 512.    M - Submission Queue Entry Size (SQES)

    struct {
        UCHAR   RequiredEntrySize   : 4;    // The value is in bytes and is reported as a power of two (2^n).
        UCHAR   MaxEntrySize        : 4;    // This value is larger than or equal to the required CQ entry size. The value is in bytes and is reported as a power of two (2^n).
    } CQES;                     // byte 513.    M - Completion Queue Entry Size (CQES)

    UCHAR   Reserved2[2];       // byte 514:515.

    ULONG   NN;                 // byte 516:519. M - Number of Namespaces (NN)

    struct {
        USHORT  Compare             : 1;
        USHORT  WriteUncorrectable  : 1;
        USHORT  DatasetManagement   : 1;
        USHORT  WriteZeroes         : 1;
        USHORT  FeatureField        : 1;
        USHORT  Reservations        : 1;
        USHORT  Timestamp           : 1;

        USHORT  Reserved            : 9;
    } ONCS;                     // byte 520:521. M - Optional NVM Command Support (ONCS)

    struct {
        USHORT  CompareAndWrite             : 1;
        USHORT  Reserved                    : 15;
    } FUSES;                    // byte 522:523. M - Fused Operation Support (FUSES)

    struct {
        UCHAR   FormatApplyToAll                : 1;
        UCHAR   SecureEraseApplyToAll           : 1;
        UCHAR   CryptographicEraseSupported     : 1;
        UCHAR   Reserved                        : 5;
    } FNA;                      // byte 524.     M - Format NVM Attributes (FNA)

    struct {
        UCHAR   Present     : 1;
        UCHAR   Reserved    : 7;
    } VWC;                      // byte 525.     M - Volatile Write Cache (VWC)

    USHORT  AWUN;               // byte 526:527. M - Atomic Write Unit Normal (AWUN)
    USHORT  AWUPF;              // byte 528:529. M - Atomic Write Unit Power Fail (AWUPF)

    struct {
        UCHAR   CommandFormatInSpec : 1;
        UCHAR   Reserved            : 7;
    } NVSCC;                    // byte 530.     M - NVM Vendor Specific Command Configuration (NVSCC)

    UCHAR   Reserved3;          // byte 531.

    USHORT  ACWU;               // byte 532:533  O - Atomic Compare & Write Unit (ACWU)

    UCHAR   Reserved4[2];       // byte 534:535.

    struct {
        ULONG   SGLSupported            : 1;
        ULONG   Reserved0               : 15;
        ULONG   BitBucketDescrSupported : 1;
        ULONG   ByteAlignedContiguousPhysicalBuffer : 1;
        ULONG   SGLLengthLargerThanDataLength       : 1;
        ULONG   Reserved1               : 13;
    } SGLS;                     // byte 536:539. O - SGL Support (SGLS)

    UCHAR   Reserved5[164];     // byte 540:703.

    //
    // byte 704 : 2047, I/O Command Set Attributes
    //
    UCHAR   Reserved6[1344];    // byte 704:2047.

    //
    // byte 2048 : 3071, Power State Descriptors
    //
    NVME_POWER_STATE_DESC   PDS[32];    // byte 2048:2079. M - Power State 0 Descriptor (PSD0):  This field indicates the characteristics of power state 0
                                        // byte 2080:2111. O - Power State 1 Descriptor (PSD1):  This field indicates the characteristics of power state 1
                                        // byte 2112:2143. O - Power State 2 Descriptor (PSD1):  This field indicates the characteristics of power state 2
                                        // byte 2144:2175. O - Power State 3 Descriptor (PSD1):  This field indicates the characteristics of power state 3
                                        // byte 2176:2207. O - Power State 4 Descriptor (PSD1):  This field indicates the characteristics of power state 4
                                        // byte 2208:2239. O - Power State 5 Descriptor (PSD1):  This field indicates the characteristics of power state 5
                                        // byte 2240:2271. O - Power State 6 Descriptor (PSD1):  This field indicates the characteristics of power state 6
                                        // byte 2272:2303. O - Power State 7 Descriptor (PSD1):  This field indicates the characteristics of power state 7
                                        // byte 2304:2335. O - Power State 8 Descriptor (PSD1):  This field indicates the characteristics of power state 8
                                        // byte 2336:2367. O - Power State 9 Descriptor (PSD1):  This field indicates the characteristics of power state 9
                                        // byte 2368:2399. O - Power State 10 Descriptor (PSD1):  This field indicates the characteristics of power state 10
                                        // byte 2400:2431. O - Power State 11 Descriptor (PSD1):  This field indicates the characteristics of power state 11
                                        // byte 2432:2463. O - Power State 12 Descriptor (PSD1):  This field indicates the characteristics of power state 12
                                        // byte 2464:2495. O - Power State 13 Descriptor (PSD1):  This field indicates the characteristics of power state 13
                                        // byte 2496:2527. O - Power State 14 Descriptor (PSD1):  This field indicates the characteristics of power state 14
                                        // byte 2528:2559. O - Power State 15 Descriptor (PSD1):  This field indicates the characteristics of power state 15
                                        // byte 2560:2591. O - Power State 16 Descriptor (PSD1):  This field indicates the characteristics of power state 16
                                        // byte 2592:2623. O - Power State 17 Descriptor (PSD1):  This field indicates the characteristics of power state 17
                                        // byte 2624:2655. O - Power State 18 Descriptor (PSD1):  This field indicates the characteristics of power state 18
                                        // byte 2656:2687. O - Power State 19 Descriptor (PSD1):  This field indicates the characteristics of power state 19
                                        // byte 2688:2719. O - Power State 20 Descriptor (PSD1):  This field indicates the characteristics of power state 20
                                        // byte 2720:2751. O - Power State 21 Descriptor (PSD1):  This field indicates the characteristics of power state 21
                                        // byte 2752:2783. O - Power State 22 Descriptor (PSD1):  This field indicates the characteristics of power state 22
                                        // byte 2784:2815. O - Power State 23 Descriptor (PSD1):  This field indicates the characteristics of power state 23
                                        // byte 2816:2847. O - Power State 24 Descriptor (PSD1):  This field indicates the characteristics of power state 24
                                        // byte 2848:2879. O - Power State 25 Descriptor (PSD1):  This field indicates the characteristics of power state 25
                                        // byte 2880:2911. O - Power State 26 Descriptor (PSD1):  This field indicates the characteristics of power state 26
                                        // byte 2912:2943. O - Power State 27 Descriptor (PSD1):  This field indicates the characteristics of power state 27
                                        // byte 2944:2975. O - Power State 28 Descriptor (PSD1):  This field indicates the characteristics of power state 28
                                        // byte 2976:3007. O - Power State 29 Descriptor (PSD1):  This field indicates the characteristics of power state 29
                                        // byte 3008:3039. O - Power State 30 Descriptor (PSD1):  This field indicates the characteristics of power state 30
                                        // byte 3040:3071. O - Power State 31 Descriptor (PSD1):  This field indicates the characteristics of power state 31

    //
    // byte 3072 : 4095, Vendor Specific
    //
    UCHAR   VS[1024];           // byte 3072 : 4095.

} NVME_IDENTIFY_CONTROLLER_DATA, *PNVME_IDENTIFY_CONTROLLER_DATA;

typedef struct {

    USHORT  NumberOfIdentifiers;
    USHORT  ControllerID[2047];

} NVME_CONTROLLER_LIST, *PNVME_CONTROLLER_LIST;

typedef union {

    struct {
        USHORT  MS;                 // bit 0:15     Metadata Size (MS)
        UCHAR   LBADS;              // bit 16:23    LBA  Data  Size (LBADS)

        UCHAR   RP          : 2;    // bit 24:25    Relative Performance (RP)
        UCHAR   Reserved0   : 6;    // bit 26:31
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_LBA_FORMAT, *PNVME_LBA_FORMAT;

typedef struct {

    ULONGLONG   NSZE;                   // byte 0:7.    M - Namespace Size (NSZE)
    ULONGLONG   NCAP;                   // byte 8:15    M - Namespace Capacity (NCAP)
    ULONGLONG   NUSE;                   // byte 16:23   M - Namespace Utilization (NUSE)

    struct {
        UCHAR   ThinProvisioning            : 1;
        UCHAR   NameSpaceAtomicWriteUnit    : 1;
        UCHAR   DeallocatedOrUnwrittenError : 1;
        UCHAR   SkipReuseUI                 : 1;
        UCHAR   Reserved                    : 4;
    } NSFEAT;                           // byte 24      M - Namespace Features (NSFEAT)

    UCHAR   NLBAF;                      // byte 25      M - Number of LBA Formats (NLBAF)

    struct {
        UCHAR   LbaFormatIndex              : 4;
        UCHAR   MetadataInExtendedDataLBA   : 1;
        UCHAR   Reserved                    : 3;
    } FLBAS;                            // byte 26      M - Formatted LBA Size (FLBAS)

    struct {
        UCHAR   MetadataInExtendedDataLBA   : 1;
        UCHAR   MetadataInSeparateBuffer    : 1;
        UCHAR   Reserved                    : 6;
    } MC;                               // byte 27      M - Metadata Capabilities (MC)

    struct {
        UCHAR   ProtectionInfoType1         : 1;
        UCHAR   ProtectionInfoType2         : 1;
        UCHAR   ProtectionInfoType3         : 1;
        UCHAR   InfoAtBeginningOfMetadata   : 1;
        UCHAR   InfoAtEndOfMetadata         : 1;
        UCHAR   Reserved                    : 3;
    } DPC;                              // byte 28      M - End-to-end Data Protection Capabilities (DPC)

    struct {
        UCHAR   ProtectionInfoTypeEnabled   : 3;    // 0 - not enabled; 1 ~ 3: enabled type; 4 ~ 7: reserved
        UCHAR   InfoAtBeginningOfMetadata   : 1;
        UCHAR   Reserved                    : 4;
    } DPS;                              // byte 29      M - End-to-end Data Protection Type Settings (DPS)

    struct {
        UCHAR   SharedNameSpace     : 1;
        UCHAR   Reserved            : 7;
    } NMIC;                             // byte 30      O - Namespace Multi-path I/O and Namespace Sharing Capabilities (NMIC)

    struct {
        UCHAR   PersistThroughPowerLoss                     : 1;
        UCHAR   WriteExclusiveReservation                   : 1;
        UCHAR   ExclusiveAccessReservation                  : 1;
        UCHAR   WriteExclusiveRegistrantsOnlyReservation    : 1;
        UCHAR   ExclusiveAccessRegistrantsOnlyReservation   : 1;
        UCHAR   WriteExclusiveAllRegistrantsReservation     : 1;
        UCHAR   ExclusiveAccessAllRegistrantsReservation    : 1;
        UCHAR   Reserved                                    : 1;
    } RESCAP;                           // byte 31      O - Reservation Capabilities (RESCAP)

    struct {
        UCHAR   PercentageRemained  : 7;    // Bits 6:0: indicate the percentage of the namespace that remains to be formatted
        UCHAR   Supported           : 1;    // Bit 7: if set to 1 indicates that the namespace supports the Format Progress Indicator.
    } FPI;                              // byte 32      O - Format Progress Indicator (FPI)

    UCHAR           Reserved0;          // byte 33

    USHORT          NAWUN;              // byte 34:35 O - Namespace Atomic Write Unit Normal (NAWUN)
    USHORT          NAWUPF;             // byte 36:37 O - Namespace Atomic Write Unit Power Fail (NAWUPF)
    USHORT          NACWU;              // byte 38:39 O - Namespace Atomic Compare & Write Unit (NACWU)
    USHORT          NABSN;              // byte 40:41 O - Namespace Atomic Boundary Size Normal (NABSN)
    USHORT          NABO;               // byte 42:43 O - Namespace Atomic Boundary Offset (NABO)
    USHORT          NABSPF;             // byte 44:45 O - Namespace Atomic Boundary Size Power Fail (NABSPF)
    USHORT          NOIOB;              // byte 46:47 O - Namespace Optimal IO Boundary (NOIOB)

    UCHAR           NVMCAP[16];         // byte 48:63 O - NVM Capacity (NVMCAP)

    UCHAR           Reserved2[36];      // byte 64:99

    USHORT          NVMSETID;           // byte 100:101 O - Associated NVM Set Identifier

    USHORT          ENDGID;             // byte 102:103 O - Associated Endurance Group Identier

    UCHAR           NGUID[16];          // byte 104:119 O - NAmespace Globally Unique Identifier (NGUID)

    UCHAR           EUI64[8];           // byte 120:127 M - IEEE Extended Unique Identifier (EUI64)

    NVME_LBA_FORMAT LBAF[16];           // byte 128:131 M - LBA Format 0 Support (LBAF0)
                                        // byte 132:135 O - LBA Format 1 Support (LBAF1)
                                        // byte 136:139 O - LBA Format 2 Support (LBAF2)
                                        // byte 140:143 O - LBA Format 3 Support (LBAF3)
                                        // byte 144:147 O - LBA Format 4 Support (LBAF4)
                                        // byte 148:151 O - LBA Format 5 Support (LBAF5)
                                        // byte 152:155 O - LBA Format 6 Support (LBAF6)
                                        // byte 156:159 O - LBA Format 7 Support (LBAF7)
                                        // byte 160:163 O - LBA Format 8 Support (LBAF8)
                                        // byte 164:167 O - LBA Format 9 Support (LBAF9)
                                        // byte 168:171 O - LBA Format 10 Support (LBAF10)
                                        // byte 172:175 O - LBA Format 11 Support (LBAF11)
                                        // byte 176:179 O - LBA Format 12 Support (LBAF12)
                                        // byte 180:183 O - LBA Format 13 Support (LBAF13)
                                        // byte 184:187 O - LBA Format 14 Support (LBAF14)
                                        // byte 188:191 O - LBA Format 15 Support (LBAF15)

    UCHAR           Reserved3[192];     // byte 192:383

    UCHAR           VS[3712];           // byte 384:4095 O - Vendor Specific (VS): This range of bytes is allocated for vendor specific usage.

} NVME_IDENTIFY_NAMESPACE_DATA, *PNVME_IDENTIFY_NAMESPACE_DATA;

//
// Data Structure of LBA Range Type entry
//
typedef enum {

    NVME_LBA_RANGE_TYPE_RESERVED            = 0,
    NVME_LBA_RANGE_TYPE_FILESYSTEM          = 1,
    NVME_LBA_RANGE_TYPE_RAID                = 2,
    NVME_LBA_RANGE_TYPE_CACHE               = 3,
    NVME_LBA_RANGE_TYPE_PAGE_SWAP_FILE      = 4,

} NVME_LBA_RANGE_TYPES;

typedef struct {
    UCHAR       Type;                   // Type (Type): Specifies the Type of the LBA range.
    struct {
        UCHAR   MayOverwritten : 1;
        UCHAR   Hidden         : 1;
        UCHAR   Reserved       : 6;
    } Attributes;                       // Attributes: Specifies attributes of the LBA range. Each bit defines an attribute.

    UCHAR       Reserved0[14];
    ULONGLONG   SLBA;                   // Starting LBA (SLBA): This field specifies the 64-bit address of the first logical block that is part of this LBA range.
    ULONGLONG   NLB;                    // Number of Logical Blocks (NLB): This field specifies the number of logical blocks that are part of this LBA range. This is a 0s based value.
    UCHAR       GUID[16];               // Unique Identifier (GUID): This field is a global unique identifier that uniquely specifies the type of this LBA range. Well known Types may be defined and are published on the NVM Express website.
    UCHAR       Reserved1[16];
} NVME_LBA_RANGET_TYPE_ENTRY, *PNVME_LBA_RANGET_TYPE_ENTRY;


//
// Parameters for NVME_ADMIN_COMMAND_CREATE_IO_CQ
//
typedef union {

    struct {
        ULONG   QID         : 16;       // Queue Identifier (QID)
        ULONG   QSIZE       : 16;       // Queue Size (QSIZE)
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW10_CREATE_IO_QUEUE, *PNVME_CDW10_CREATE_IO_QUEUE;

typedef union {

    struct {
        ULONG   PC          : 1;        // Physically Contiguous (PC)
        ULONG   IEN         : 1;        // Interrupts Enabled (IEN)
        ULONG   Reserved0   : 14;
        ULONG   IV          : 16;       // Interrupt Vector (IV)
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_CREATE_IO_CQ, *PNVME_CDW11_CREATE_IO_CQ;


//
// Parameters for NVME_ADMIN_COMMAND_CREATE_IO_SQ
//
typedef enum {

    NVME_NVM_QUEUE_PRIORITY_URGENT          = 0,
    NVME_NVM_QUEUE_PRIORITY_HIGH            = 1,
    NVME_NVM_QUEUE_PRIORITY_MEDIUM          = 2,
    NVME_NVM_QUEUE_PRIORITY_LOW             = 3,

} NVME_NVM_QUEUE_PRIORITIES;


typedef union {

    struct {
        ULONG   PC          : 1;        // Physically Contiguous (PC)
        ULONG   QPRIO       : 2;        // Queue Priority (QPRIO)
        ULONG   Reserved0   : 13;
        ULONG   CQID        : 16;       // Completion Queue Identifier (CQID)
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_CREATE_IO_SQ, *PNVME_CDW11_CREATE_IO_SQ;

//
// Parameters for NVME_ADMIN_COMMAND_GET_FEATURES or NVME_ADMIN_COMMAND_SET_FEATURES
//
typedef enum {

    NVME_FEATURE_VALUE_CURRENT                      = 0,
    NVME_FEATURE_VALUE_DEFAULT                      = 1,
    NVME_FEATURE_VALUE_SAVED                        = 2,
    NVME_FEATURE_VALUE_SUPPORTED_CAPABILITIES       = 3,

} NVME_FEATURE_VALUE_CODES;

typedef union {

    struct {
        ULONG   FID         : 8;        // Feature Identifier (FID)
        ULONG   SEL         : 3;        // Select (SEL): This field specifies which value of the attributes to return in the provided data.
        ULONG   Reserved0   : 21;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW10_GET_FEATURES, *PNVME_CDW10_GET_FEATURES;

typedef union {

    struct {
        ULONG   FID         : 8;        // Feature Identifier (FID)
        ULONG   Reserved0   : 23;
        ULONG   SV          : 1;        // Save (SV)
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW10_SET_FEATURES, *PNVME_CDW10_SET_FEATURES;

typedef union {

    struct {
        ULONG   NSQ     : 16;           // Number of IO Submission Queues.
        ULONG   NCQ     : 16;           // Number of IO Completion Queues.
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_NUMBER_OF_QUEUES, *PNVME_CDW11_FEATURE_NUMBER_OF_QUEUES;

typedef union {

    struct {
        ULONG   THR         : 8;        // Aggregation Threshold (THR)
        ULONG   TIME        : 8;        // Aggregation Time (TIME)
        ULONG   Reserved0   : 16;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_INTERRUPT_COALESCING, *PNVME_CDW11_FEATURE_INTERRUPT_COALESCING;

typedef union {

    struct {
        ULONG   IV          : 16;       // Interrupt Vector (IV)
        ULONG   CD          : 1;        // Coalescing Disabled (CD)
        ULONG   Reserved0   : 15;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_INTERRUPT_VECTOR_CONFIG, *PNVME_CDW11_FEATURE_INTERRUPT_VECTOR_CONFIG;

typedef union {

    struct {
        ULONG   DN          : 1;        // Disable Normal (DN)
        ULONG   Reserved0   : 31;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_WRITE_ATOMICITY_NORMAL, *PNVME_CDW11_FEATURE_WRITE_ATOMICITY_NORMAL;

typedef union {

    struct {
        ULONG   NOPPME      : 1;        // Non-Operational Power State Permissive Mode Enable (NOPPME)
        ULONG   Reserved0   : 31;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_NON_OPERATIONAL_POWER_STATE, *PNVME_CDW11_FEATURE_NON_OPERATIONAL_POWER_STATE;

typedef union {

    struct {
        ULONG   NUM         : 6;        // Number of LBA Ranges (NUM)
        ULONG   Reserved0   : 26;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_LBA_RANGE_TYPE, *PNVME_CDW11_FEATURE_LBA_RANGE_TYPE;

typedef union {

    struct {
        ULONG   AB          : 3;        // Arbitration Burst (AB)
        ULONG   Reserved0   : 5;
        ULONG   LPW         : 8;        // Low Priority Weight (LPW)
        ULONG   MPW         : 8;        // Medium Priority Weight (MPW)
        ULONG   HPW         : 8;        // High Priority Weight (HPW)
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_ARBITRATION, *PNVME_CDW11_FEATURE_ARBITRATION;

typedef union {

    struct {
        ULONG   WCE         : 1;        // Volatile Write Cache Enable (WCE)
        ULONG   Reserved0   : 31;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_VOLATILE_WRITE_CACHE, *PNVME_CDW11_FEATURE_VOLATILE_WRITE_CACHE;

typedef union {

    struct {
        ULONG   SAVE         : 1;        // Save supported
        ULONG   NSS          : 1;        // Namespace specific
        ULONG   MOD          : 1;        // Changeable
        ULONG   Reserved0    : 29;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_SUPPORTED_CAPABILITY, *PNVME_CDW11_FEATURE_SUPPORTED_CAPABILITY;

typedef union {

    struct {
        ULONG   CriticalWarnings    : 8;  // SMART / Health Critical Warnings
        ULONG   NsAttributeNotices  : 1;  // Namespace Attributes Notices
        ULONG   FwActivationNotices : 1;  // Firmware Activation Notices
        ULONG   TelemetryLogNotices : 1;  // Telemetry Log Notices
        ULONG   Reserved0           : 21;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_ASYNC_EVENT_CONFIG, *PNVME_CDW11_FEATURE_ASYNC_EVENT_CONFIG;

//
// Parameter for NVME_FEATURE_POWER_MANAGEMENT
//
typedef union {

    struct {
        ULONG   PS          : 5;        // Power State (PS)
        ULONG   Reserved0   : 27;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_POWER_MANAGEMENT, *PNVME_CDW11_FEATURE_POWER_MANAGEMENT;

//
// Parameter for NVME_FEATURE_AUTONOMOUS_POWER_STATE_TRANSITION
//
typedef union {
    struct {
        ULONG APSTE     : 1;    // Autonomous Power State Transition Enable (APSTE)
        ULONG Reserved0 : 31;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_CDW11_FEATURE_AUTO_POWER_STATE_TRANSITION, *PNVME_CDW11_FEATURE_AUTO_POWER_STATE_TRANSITION;

//
// Parameter for NVME_FEATURE_AUTONOMOUS_POWER_STATE_TRANSITION
// There is an array of 32 of these (one for each power state) in the data buffer.
//
typedef struct {
    ULONG Reserved0                 : 3;    // Bits 0-2 are reserved.
    ULONG IdleTransitionPowerState  : 5;    // Bits 3-7 - (ITPS) The non-operational power state for the controller to autonomously transition to after there is a continuous period of idle time in the current power state that exceeds time specified in the ITPT field.
    ULONG IdleTimePriorToTransition : 24;   // Bits 8-31 - (ITPT) The amount of idle time (in ms) that occurs in this power state prior to transitioning to the Idle Transition Power State.  A value of 0 disables APST for this power state.
    ULONG Reserved1;                        // Bits 32-63 are reserved.
} NVME_AUTO_POWER_STATE_TRANSITION_ENTRY, *PNVME_AUTO_POWER_STATE_TRANSITION_ENTRY;

//
// Parameter for NVME_FEATURE_TEMPERATURE_THRESHOLD
//

//
// Following definitions are used in "THSEL" field.
//
typedef enum {

    NVME_TEMPERATURE_OVER_THRESHOLD         = 0,
    NVME_TEMPERATURE_UNDER_THRESHOLD        = 1,

} NVME_TEMPERATURE_THRESHOLD_TYPES;

typedef union {

    struct {
        ULONG   TMPTH       : 16;       // Temperature Threshold (TMPTH):  Indicates the threshold for the temperature of the overall device (controller and NVM included) in units of Kelvin.
        ULONG   TMPSEL      : 4;        // Threshold Temperature Select (TMPSEL)
        ULONG   THSEL       : 2;        // Threshold Type Select (THSEL)
        ULONG   Reserved0   : 10;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_FEATURE_TEMPERATURE_THRESHOLD, *PNVME_CDW11_FEATURE_TEMPERATURE_THRESHOLD;


//
// Parameters for NVME_FEATURE_HOST_MEMORY_BUFFER
//
typedef union {
    struct {
        ULONG EHM : 1;  // Enable Host Memory (EHM) - Enables the host memory buffer.
        ULONG MR : 1;   // Memory Return (MR) - Indicates if the host is returning previously allocated memory to the controller.
        ULONG Reserved : 30;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} NVME_CDW11_FEATURE_HOST_MEMORY_BUFFER, *PNVME_CDW11_FEATURE_HOST_MEMORY_BUFFER;

typedef union {
    struct {
        ULONG HSIZE; // Host Memory Buffer Size (HSIZE) - The size of the host memory buffer in memory page size (CC.MPS) units.
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} NVME_CDW12_FEATURE_HOST_MEMORY_BUFFER, *PNVME_CDW12_FEATURE_HOST_MEMORY_BUFFER;

typedef union {
    struct {
        ULONG Reserved : 4;
        ULONG HMDLLA : 28; // Host Memory Descriptor List Lower Address (HMDLLA) - 16-byte aligned, lower 32 bits of the physical location of the Host Memory Descriptor List.
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} NVME_CDW13_FEATURE_HOST_MEMORY_BUFFER, *PNVME_CDW13_FEATURE_HOST_MEMORY_BUFFER;

typedef union {
    struct {
        ULONG HMDLUA; // Host Memory Descriptor List Upper Address (HMDLLA) - Upper 32 bits of the physical location of the Host Memory Descriptor List.
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} NVME_CDW14_FEATURE_HOST_MEMORY_BUFFER, *PNVME_CDW14_FEATURE_HOST_MEMORY_BUFFER;

typedef union {
    struct {
        ULONG HMDLEC; // Host Memory Descriptor List Entry Count (HMDLEC) - Number of entries in the Host Memory Descriptor List.
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} NVME_CDW15_FEATURE_HOST_MEMORY_BUFFER, *PNVME_CDW15_FEATURE_HOST_MEMORY_BUFFER;

//
// This structure is a single entry in the host memory descriptor list.
//
typedef struct {
    ULONGLONG BADD; // Buffer Address (BADD) - Physical host memory address aligned to the memory page size (CC.MPS)
    ULONG BSIZE;    // Buffer Size (BSIZE) - The number of contiguous memory page size (CC.MPS) units for this entry.
    ULONG Reserved;
} NVME_HOST_MEMORY_BUFFER_DESCRIPTOR_ENTRY, *PNVME_HOST_MEMORY_BUFFER_DESCRIPTOR_ENTRY;


//
// Parameters for SECURITY SEND / RECEIVE Commands
//
typedef union {

    struct {
        ULONG   Reserved0   : 8;
        ULONG   SPSP        : 16;       // SP Specific (SPSP)
        ULONG   SECP        : 8;        // Security Protocol (SECP)
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW10_SECURITY_SEND_RECEIVE, *PNVME_CDW10_SECURITY_SEND_RECEIVE;

typedef struct {

    ULONG   TL;                         // Transfer Length  (TL):

} NVME_CDW11_SECURITY_SEND, *PNVME_CDW11_SECURITY_SEND;

typedef struct {

    ULONG   AL;                         // Transfer Length  (AL)

} NVME_CDW11_SECURITY_RECEIVE, *PNVME_CDW11_SECURITY_RECEIVE;


typedef union {
    NVME_CDW11_FEATURE_NUMBER_OF_QUEUES     NumberOfQueues;
    NVME_CDW11_FEATURE_INTERRUPT_COALESCING InterruptCoalescing;
    NVME_CDW11_FEATURE_INTERRUPT_VECTOR_CONFIG InterruptVectorConfig;
    NVME_CDW11_FEATURE_LBA_RANGE_TYPE       LbaRangeType;
    NVME_CDW11_FEATURE_ARBITRATION          Arbitration;
    NVME_CDW11_FEATURE_VOLATILE_WRITE_CACHE VolatileWriteCache;
    NVME_CDW11_FEATURE_ASYNC_EVENT_CONFIG   AsyncEventConfig;
    NVME_CDW11_FEATURE_POWER_MANAGEMENT     PowerManagement;
    NVME_CDW11_FEATURE_AUTO_POWER_STATE_TRANSITION  AutoPowerStateTransition;
    NVME_CDW11_FEATURE_TEMPERATURE_THRESHOLD TemperatureThreshold;
    NVME_CDW11_FEATURE_HOST_MEMORY_BUFFER   HostMemoryBuffer;
    NVME_CDW11_FEATURE_WRITE_ATOMICITY_NORMAL WriteAtomicityNormal;
    NVME_CDW11_FEATURE_NON_OPERATIONAL_POWER_STATE NonOperationalPowerState;

    ULONG   AsUlong;
} NVME_CDW11_FEATURES, *PNVME_CDW11_FEATURES;

typedef union {
    NVME_CDW12_FEATURE_HOST_MEMORY_BUFFER   HostMemoryBuffer;

    ULONG   AsUlong;
} NVME_CDW12_FEATURES, *PNVME_CDW12_FEATURES;

typedef union {
    NVME_CDW13_FEATURE_HOST_MEMORY_BUFFER   HostMemoryBuffer;

    ULONG   AsUlong;
} NVME_CDW13_FEATURES, *PNVME_CDW13_FEATURES;

typedef union {
    NVME_CDW14_FEATURE_HOST_MEMORY_BUFFER   HostMemoryBuffer;

    ULONG   AsUlong;
} NVME_CDW14_FEATURES, *PNVME_CDW14_FEATURES;

typedef union {
    NVME_CDW15_FEATURE_HOST_MEMORY_BUFFER   HostMemoryBuffer;

    ULONG   AsUlong;
} NVME_CDW15_FEATURES, *PNVME_CDW15_FEATURES;

//
// NVMe Maximum log size
//
#define NVME_MAX_LOG_SIZE               0x1000

//
// Parameters for NVME_ADMIN_COMMAND_GET_LOG_PAGE Command
//
typedef enum {

    NVME_LOG_PAGE_ERROR_INFO                    = 0x01,
    NVME_LOG_PAGE_HEALTH_INFO                   = 0x02,
    NVME_LOG_PAGE_FIRMWARE_SLOT_INFO            = 0x03,
    NVME_LOG_PAGE_CHANGED_NAMESPACE_LIST        = 0x04,
    NVME_LOG_PAGE_COMMAND_EFFECTS               = 0x05,
    NVME_LOG_PAGE_DEVICE_SELF_TEST              = 0x06,
    NVME_LOG_PAGE_TELEMETRY_HOST_INITIATED      = 0x07,
    NVME_LOG_PAGE_TELEMETRY_CTLR_INITIATED      = 0x08,
    NVME_LOG_PAGE_ENDURANCE_GROUP_INFORMATION   = 0x09,

    NVME_LOG_PAGE_RESERVATION_NOTIFICATION      = 0x80,
    NVME_LOG_PAGE_SANITIZE_STATUS               = 0x81,

} NVME_LOG_PAGES;

//
// Get LOG PAGE format which confines to  < 1.3 NVMe Specification
// 
typedef union {

    struct {
        ULONG   LID         : 8;        // Log Page Identifier (LID)
        ULONG   Reserved0   : 8;
        ULONG   NUMD        : 12;       // Number of Dwords (NUMD)
        ULONG   Reserved1   : 4;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW10_GET_LOG_PAGE, *PNVME_CDW10_GET_LOG_PAGE;

//
// Get LOG PAGE format which confines to  >= 1.3 NVMe Specification
// 
typedef union {

    struct {
        ULONG   LID         : 8;        // Log Page Identifier (LID)
        ULONG   LSP         : 4;        // Log Specific Field (LSP)
        ULONG   Reserved0   : 3;
        ULONG   RAE         : 1;        // Reset Asynchronous Event (RAE)
        ULONG   NUMDL       : 16;       // Number of Lower Dwords (NUMDL)
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW10_GET_LOG_PAGE_V13, *PNVME_CDW10_GET_LOG_PAGE_V13;

typedef union {

    struct {
        ULONG   NUMDU                   : 16;       // Number of Upper Dwords (NUMDU)
        ULONG   LogSpecificIdentifier   : 16;       // Log Specific Identifier
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_GET_LOG_PAGE, *PNVME_CDW11_GET_LOG_PAGE;

typedef struct {

    ULONG   LPOL;                       // Log Page Offset Lower (LPOL)

} NVME_CDW12_GET_LOG_PAGE, *PNVME_CDW12_GET_LOG_PAGE;

typedef struct {

    ULONG   LPOU;                       // Log Page Offset Upper (LPOU)


} NVME_CDW13_GET_LOG_PAGE, *PNVME_CDW13_GET_LOG_PAGE;

//
// Information of log: NVME_LOG_PAGE_ERROR_INFO. Size: 64 bytes
//
typedef struct {

    ULONGLONG           ErrorCount;
    USHORT              SQID;           // Submission Queue ID
    USHORT              CMDID;          // Command ID
    NVME_COMMAND_STATUS Status;         // Status Field: This field indicates the Status Field for the command  that completed.  The Status Field is located in bits 15:01, bit 00 corresponds to the Phase Tag posted for the command.

    struct {
        USHORT  Byte        : 8;        // Byte in command that contained the error.
        USHORT  Bit         : 3;        // Bit in command that contained the error.
        USHORT  Reserved    : 5;
    } ParameterErrorLocation;

    ULONGLONG           Lba;            // LBA: This field indicates the first LBA that experienced the error condition, if applicable.
    ULONG               NameSpace;      // Namespace: This field indicates the namespace that the error is associated with, if applicable.

    UCHAR               VendorInfoAvailable;    // Vendor Specific Information Available

    UCHAR               Reserved0[3];

    ULONGLONG           CommandSpecificInfo;    // This field contains command specific information. If used, the command definition specifies the information returned.

    UCHAR               Reserved1[24];

} NVME_ERROR_INFO_LOG, *PNVME_ERROR_INFO_LOG;

//
// Information of log: NVME_LOG_PAGE_HEALTH_INFO. Size: 512 bytes
//
typedef struct {

    union {

        struct {
            UCHAR   AvailableSpaceLow   : 1;                    // If set to 1, then the available spare space has fallen below the threshold.
            UCHAR   TemperatureThreshold : 1;                   // If set to 1, then a temperature is above an over temperature threshold or below an under temperature threshold.
            UCHAR   ReliabilityDegraded : 1;                    // If set to 1, then the device reliability has been degraded due to significant media related  errors or any internal error that degrades device reliability.
            UCHAR   ReadOnly            : 1;                    // If set to 1, then the media has been placed in read only mode
            UCHAR   VolatileMemoryBackupDeviceFailed    : 1;    // If set to 1, then the volatile memory backup device has failed. This field is only valid if the controller has a volatile memory backup solution.
            UCHAR   Reserved                            : 3;
        } DUMMYSTRUCTNAME;

        UCHAR AsUchar;

    } CriticalWarning;    // This field indicates critical warnings for the state of the  controller. Each bit corresponds to a critical warning type; multiple bits may be set.

    UCHAR   Temperature[2];                 // Temperature: Contains the temperature of the overall device (controller and NVM included) in units of Kelvin. If the temperature exceeds the temperature threshold, refer to section 5.12.1.4, then an asynchronous event completion may occur
    UCHAR   AvailableSpare;                 // Available Spare:  Contains a normalized percentage (0 to 100%) of the remaining spare capacity available
    UCHAR   AvailableSpareThreshold;        // Available Spare Threshold:  When the Available Spare falls below the threshold indicated in this field, an asynchronous event  completion may occur. The value is indicated as a normalized percentage (0 to 100%).
    UCHAR   PercentageUsed;                 // Percentage Used
    UCHAR   Reserved0[26];

    UCHAR   DataUnitRead[16];               // Data Units Read:  Contains the number of 512 byte data units the host has read from the controller; this value does not include metadata. This value is reported in thousands (i.e., a value of 1 corresponds to 1000 units of 512 bytes read)  and is rounded up.  When the LBA size is a value other than 512 bytes, the controller shall convert the amount of data read to 512 byte units. For the NVM command set, logical blocks read as part of Compare and Read operations shall be included in this value
    UCHAR   DataUnitWritten[16];            // Data Units Written: Contains the number of 512 byte data units the host has written to the controller; this value does not include metadata. This value is reported in thousands (i.e., a value of 1 corresponds to 1000 units of 512 bytes written)  and is rounded up.  When the LBA size is a value other than 512 bytes, the controller shall convert the amount of data written to 512 byte units. For the NVM command set, logical blocks written as part of Write operations shall be included in this value. Write Uncorrectable commands shall not impact this value.
    UCHAR   HostReadCommands[16];           // Host Read Commands:  Contains the number of read commands  completed by  the controller. For the NVM command set, this is the number of Compare and Read commands.
    UCHAR   HostWrittenCommands[16];        // Host Write Commands:  Contains the number of write commands  completed by  the controller. For the NVM command set, this is the number of Write commands.
    UCHAR   ControllerBusyTime[16];         // Controller Busy Time:  Contains the amount of time the controller is busy with I/O commands. The controller is busy when there is a command outstanding to an I/O Queue (specifically, a command was issued via an I/O Submission Queue Tail doorbell write and the corresponding  completion queue entry  has not been posted yet to the associated I/O Completion Queue). This value is reported in minutes.
    UCHAR   PowerCycle[16];                 // Power Cycles: Contains the number of power cycles.
    UCHAR   PowerOnHours[16];               // Power On Hours: Contains the number of power-on hours. This does not include time that the controller was powered and in a low power state condition.
    UCHAR   UnsafeShutdowns[16];            // Unsafe Shutdowns: Contains the number of unsafe shutdowns. This count is incremented when a shutdown notification (CC.SHN) is not received prior to loss of power.
    UCHAR   MediaErrors[16];                // Media Errors:  Contains the number of occurrences where the controller detected an unrecovered data integrity error. Errors such as uncorrectable ECC, CRC checksum failure, or LBA tag mismatch are included in this field.
    UCHAR   ErrorInfoLogEntryCount[16];     // Number of Error Information Log Entries:  Contains the number of Error Information log entries over the life of the controller
    ULONG   WarningCompositeTemperatureTime;     // Warning Composite Temperature Time: Contains the amount of time in minutes that the controller is operational and the Composite Temperature is greater than or equal to the Warning Composite Temperature Threshold (WCTEMP) field and less than the Critical Composite Temperature Threshold (CCTEMP) field in the Identify Controller data structure
    ULONG   CriticalCompositeTemperatureTime;    // Critical Composite Temperature Time: Contains the amount of time in minutes that the controller is operational and the Composite Temperature is greater the Critical Composite Temperature Threshold (CCTEMP) field in the Identify Controller data structure
    USHORT  TemperatureSensor1;          // Contains the current temperature reported by temperature sensor 1.
    USHORT  TemperatureSensor2;          // Contains the current temperature reported by temperature sensor 2.
    USHORT  TemperatureSensor3;          // Contains the current temperature reported by temperature sensor 3.
    USHORT  TemperatureSensor4;          // Contains the current temperature reported by temperature sensor 4.
    USHORT  TemperatureSensor5;          // Contains the current temperature reported by temperature sensor 5.
    USHORT  TemperatureSensor6;          // Contains the current temperature reported by temperature sensor 6.
    USHORT  TemperatureSensor7;          // Contains the current temperature reported by temperature sensor 7.
    USHORT  TemperatureSensor8;          // Contains the current temperature reported by temperature sensor 8.
    UCHAR   Reserved1[296];

} NVME_HEALTH_INFO_LOG, *PNVME_HEALTH_INFO_LOG;

//
// "Telemetry Host-Initiated Log" structure definition.
//

#define NVME_TELEMETRY_HOST_INITIATED_LOG_IDENTIFIER    0x7

#define NVME_TELEMETRY_DATA_BLOCK_SIZE                  0x200 // All NVMe Telemetry Data Blocks are 512 bytes in size.

typedef struct _NVME_TELEMETRY_HOST_INITIATED_LOG {

    UCHAR   LogIdentifier;                      // Byte 0
    UCHAR   Reserved0[4];                       // Bytes 1-4
    UCHAR   OrganizationID[3];                  // Bytes 5-7 - IEEE OUI Identifier
    USHORT  Area1LastBlock;                     // Bytes 8-9
    USHORT  Area2LastBlock;                     // Bytes 10-11
    USHORT  Area3LastBlock;                     // Bytes 12-13
    UCHAR   Reserved1[368];                     // Bytes 14-381
    UCHAR   ControllerInitiatedDataAvailable;   // Byte 382
    UCHAR   ControllerInitiatedDataGenerationNumber; // Byte 383
    UCHAR   ReasonIdentifier[128];              // Bytes 384-511

} NVME_TELEMETRY_HOST_INITIATED_LOG, *PNVME_TELEMETRY_HOST_INITIATED_LOG;

//
// Information of log: NVME_LOG_PAGE_FIRMWARE_SLOT_INFO. Size: 512 bytes
//
typedef struct {

    struct {
        UCHAR   ActiveSlot          : 3;        // Bits 2:0 indicates the firmware slot that contains the actively running firmware revision.
        UCHAR   Reserved0           : 1;
        UCHAR   PendingActivateSlot : 3;        // Bits 6:4 indicates the firmware slot that is going to be activated at the next controller reset.
        UCHAR   Reserved1           : 1;
    } AFI;    // Active Firmware Info (AFI)

    UCHAR       Reserved0[7];

    ULONGLONG   FRS[7];            // Firmware Revision for Slot 1 - 7(FRS1 - FRS7):  Contains the revision of the firmware downloaded to firmware slot 1 - 7.

    UCHAR       Reserved1[448];

} NVME_FIRMWARE_SLOT_INFO_LOG, *PNVME_FIRMWARE_SLOT_INFO_LOG;

//
// Information of log: NVME_LOG_PAGE_CHANGED_NAMESPACE_LIST. Size: 4096 bytes
//
typedef struct {

    ULONG   NSID[1024];                        // List of Namespace ID upto 1024 entries

} NVME_CHANGED_NAMESPACE_LIST_LOG, *PNVME_CHANGED_NAMESPACE_LIST_LOG;


//
// Information of log: NVME_LOG_PAGE_COMMAND_EFFECTS. Size: 4096 bytes
//
typedef enum {

    NVME_COMMAND_EFFECT_SBUMISSION_EXECUTION_LIMIT_NONE                     = 0,
    NVME_COMMAND_EFFECT_SBUMISSION_EXECUTION_LIMIT_SINGLE_PER_NAMESPACE     = 1,
    NVME_COMMAND_EFFECT_SBUMISSION_EXECUTION_LIMIT_SINGLE_PER_CONTROLLER    = 2,

} NVME_COMMAND_EFFECT_SBUMISSION_EXECUTION_LIMITS;

typedef union {

    struct {
        //LSB
        ULONG   CSUPP       : 1;        // Command Supported (CSUPP)
        ULONG   LBCC        : 1;        // Logical Block Content Change (LBCC)
        ULONG   NCC         : 1;        // Namespace Capability Change (NCC)
        ULONG   NIC         : 1;        // Namespace Inventory Change (NIC)
        ULONG   CCC         : 1;        // Controller Capability Change (CCC)
        ULONG   Reserved0   : 11;
        ULONG   CSE         : 3;        // Command Submission and Execution (CSE)
        ULONG   Reserved1   : 13;
        //MSB
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_COMMAND_EFFECTS_DATA, *PNVME_COMMAND_EFFECTS_DATA;


typedef struct {

    NVME_COMMAND_EFFECTS_DATA   ACS[256];       // Admin Command Supported
    NVME_COMMAND_EFFECTS_DATA   IOCS[256];      // I/O Command Supported

    UCHAR                       Reserved[2048];

} NVME_COMMAND_EFFECTS_LOG, *PNVME_COMMAND_EFFECTS_LOG;

#pragma pack(push, 1)
typedef struct {

    struct {
        UCHAR   Result              : 4;        // Result of Device Self-Test operation of this particular result data
        UCHAR   CodeValue           : 4;        // Self-Test code value that was specified in command
    } Status;

    UCHAR       SegmentNumber;                  // Indicates the first segment that failure occured

    struct {
        UCHAR   NSIDValid           : 1;        // If set to 1, the contents of Namespace Identifier field is valid
        UCHAR   FLBAValid           : 1;        // If set to 1, the contents of Failing LBA field is valid
        UCHAR   SCTValid            : 1;        // If set to 1, the contents of Status Code Type field is valid
        UCHAR   SCValid             : 1;        // If set to 1, the contents of Status Code field is valid
        UCHAR   Reserved            : 4;
    } ValidDiagnostics;

    UCHAR       Reserved;

    ULONGLONG   POH;                            // Power On Hours, when test operation was completed/aborted
    ULONG       NSID;                           // Namespace Identifier. Only valid if NSIDValid is set
    ULONGLONG   FailingLBA;                     // Failed LBA which caused test to fail. Only valid if FLBAValid is set

    struct {
        UCHAR   AdditionalInfo      : 3;        // Additional information related to errors/conditions. Only valid if SCTValid is set
        UCHAR   Reserved            : 5;
    } StatusCodeType;

    UCHAR       StatusCode;                     // Additional information related to errors/conditons. Only valid if SCValid is set
    USHORT      VendorSpecific;

} NVME_DEVICE_SELF_TEST_RESULT_DATA, *PNVME_DEVICE_SELF_TEST_RESULT_DATA;

//
// Information of log: NVME_LOG_PAGE_DEVICE_SELF_TEST. Size: 564 bytes
//
typedef struct {

     struct {
        UCHAR   Status              : 4;        // Status of current Device Self-Test operation
        UCHAR   Reserved            : 4;
     } CurrentOperation;

     struct {
        UCHAR   CompletePercent     : 7;        // Percentage of completion of Device Self-Test operation. Valid if Status field is non-zero.
        UCHAR   Reserved            : 1;
     } CurrentCompletion;

     UCHAR      Reserved[2];

     NVME_DEVICE_SELF_TEST_RESULT_DATA       ResultData[20];    // Last 20 Self-Test Result Data, latest to oldest available in sorted order

} NVME_DEVICE_SELF_TEST_LOG, *PNVME_DEVICE_SELF_TEST_LOG;

//
// Information of log: NVME_LOG_PAGE_ENDURANCE_GROUP_INFORMATION. Size: 512 bytes
//
typedef struct {

    ULONG       Reserved0;
    UCHAR       AvailableSpareThreshold;    // Available spare indicated as normalized percentage (0-100)
    UCHAR       PercentageUsed;             // Vendor specific estimate of percentage of life used for the NVM set(s) of Endurance Group (Billion Unit)

    UCHAR       Reserved1[26];
    UCHAR       EnduranceEstimate[16];      // Estimate of total number of data bytes written to NVM set(s) of Endurance Group (Billion Unit)
    UCHAR       DataUnitsRead[16];          // Total number of data bytes read from NVM set(s) of Endurance Group (Billion Unit)
    UCHAR       DataUnitsWritten[16];       // Total number of data bytes written to NVM sets(s) of Endurance Group (Billion Unit)
                                            // Includes only host writes

    UCHAR       MediaUnitsWritten[16];      // Total number of data bytes written to NVM sets(s) of Endurance Group (Billion Unit)
                                            // Includes both host and controller writes.

    UCHAR       Reserved2[416];

} NVME_ENDURANCE_GROUP_LOG, *PNVME_ENDURANCE_GROUP_LOG;

#pragma pack(pop)

//
// Information of log: NVME_LOG_PAGE_RESERVATION_NOTIFICATION. Size: 64 bytes
//
typedef enum {

    NVME_RESERVATION_NOTIFICATION_TYPE_EMPTY_LOG_PAGE           = 0,
    NVME_RESERVATION_NOTIFICATION_TYPE_REGISTRATION_PREEMPTED   = 1,
    NVME_RESERVATION_NOTIFICATION_TYPE_REGISTRATION_RELEASED    = 2,
    NVME_RESERVATION_NOTIFICATION_TYPE_RESERVATION_PREEPMPTED   = 3,

} NVME_RESERVATION_NOTIFICATION_TYPES;

typedef struct {

    ULONGLONG   LogPageCount;           // Log Page Count
    UCHAR       LogPageType;            // Reservation Notification Log Page Type.
    UCHAR       AvailableLogPageCount;  // Number of Available Log Pages
    UCHAR       Reserved0[2];
    ULONG       NameSpaceId;            // Namespace ID
    UCHAR       Reserved1[48];

} NVME_RESERVATION_NOTIFICATION_LOG, *PNVME_RESERVATION_NOTIFICATION_LOG;

//
// Parameters for FIRMWARE IMAGE DOWNLOAD Command
//
typedef struct {

    ULONG   NUMD;                               // Number of Dwords (NUMD)

} NVME_CDW10_FIRMWARE_DOWNLOAD, *PNVME_CDW10_FIRMWARE_DOWNLOAD;

typedef struct {

    ULONG   OFST;                               // Offset (OFST)

} NVME_CDW11_FIRMWARE_DOWNLOAD, *PNVME_CDW11_FIRMWARE_DOWNLOAD;

//
// Parameters for FIRMWARE ACTIVATE/COMMIT Commands
//
typedef enum {

    NVME_FIRMWARE_ACTIVATE_ACTION_DOWNLOAD_TO_SLOT                                       = 0,
    NVME_FIRMWARE_ACTIVATE_ACTION_DOWNLOAD_TO_SLOT_AND_ACTIVATE                          = 1,
    NVME_FIRMWARE_ACTIVATE_ACTION_ACTIVATE                                               = 2,
    NVME_FIRMWARE_ACTIVATE_ACTION_DOWNLOAD_TO_SLOT_AND_ACTIVATE_IMMEDIATE                = 3,

} NVME_FIRMWARE_ACTIVATE_ACTIONS;

typedef union {

    struct {
        ULONG   FS          : 3;            // Firmware Slot (FS)
        ULONG   AA          : 2;            // Activate Action (AA)
        ULONG   Reserved    : 27;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW10_FIRMWARE_ACTIVATE, *PNVME_CDW10_FIRMWARE_ACTIVATE;

//
// Parameters for FORMAT NVM Commands
//
typedef enum {

    NVME_PROTECTION_INFORMATION_NOT_ENABLED                 = 0,
    NVME_PROTECTION_INFORMATION_TYPE1                       = 1,
    NVME_PROTECTION_INFORMATION_TYPE2                       = 2,
    NVME_PROTECTION_INFORMATION_TYPE3                       = 3,

} NVME_PROTECTION_INFORMATION_TYPES;

typedef enum {

    NVME_SECURE_ERASE_NONE                                  = 0,
    NVME_SECURE_ERASE_USER_DATA                             = 1,
    NVME_SECURE_ERASE_CRYPTOGRAPHIC                         = 2,

} NVME_SECURE_ERASE_SETTINGS;

typedef union {

    struct {
        ULONG   LBAF        : 4;                // LBA Format (LBAF)
        ULONG   MS          : 1;                // Metadata Settings (MS)
        ULONG   PI          : 3;                // Protection Information (PI)
        ULONG   PIL         : 1;                // Protection Information Location (PIL)
        ULONG   SES         : 3;                // Secure Erase Settings (SES)

        ULONG   Reserved    : 20;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW10_FORMAT_NVM, *PNVME_CDW10_FORMAT_NVM;




//
// Parameters for Directives.
//

typedef enum {

    NVME_DIRECTIVE_TYPE_IDENTIFY                    = 0x00,
    NVME_DIRECTIVE_TYPE_STREAMS                     = 0x01

} NVME_DIRECTIVE_TYPES;

#define NVME_STREAMS_ID_MIN 1
#define NVME_STREAMS_ID_MAX 0xFFFF

//
// General parameters for Directive Receive.
//

typedef struct {

    ULONG   NUMD; // Number of Dwords (NUMD)

} NVME_CDW10_DIRECTIVE_RECEIVE, *PNVME_CDW10_DIRECTIVE_RECEIVE;

typedef union {

    struct {
        ULONG   DOPER : 8;    // Directive Operation
        ULONG   DTYPE : 8;    // Directive Type
        ULONG   DSPEC : 16;   // Directive Specific
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_DIRECTIVE_RECEIVE, *PNVME_CDW11_DIRECTIVE_RECEIVE;


//
// General parameters for Directive Send.
//

typedef struct {

    ULONG   NUMD; // Number of Dwords (NUMD)

} NVME_CDW10_DIRECTIVE_SEND, *PNVME_CDW10_DIRECTIVE_SEND;

typedef union {

    struct {
        ULONG   DOPER : 8;    // Directive Operation
        ULONG   DTYPE : 8;    // Directive Type
        ULONG   DSPEC : 16;   // Directive Specific
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_DIRECTIVE_SEND, *PNVME_CDW11_DIRECTIVE_SEND;


//
// Parameters for the Identify Directive Type.
//

typedef enum {

    NVME_DIRECTIVE_RECEIVE_IDENTIFY_OPERATION_RETURN_PARAMETERS = 1

} NVME_DIRECTIVE_RECEIVE_IDENTIFY_OPERATIONS;

typedef enum {

    NVME_DIRECTIVE_SEND_IDENTIFY_OPERATION_ENABLE_DIRECTIVE = 1

} NVME_DIRECTIVE_SEND_IDENTIFY_OPERATIONS;

typedef struct {

    UCHAR   Identify : 1;
    UCHAR   Streams : 1;
    UCHAR   Reserved0 : 6;

    UCHAR   Reserved1[31];

} NVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS_DESCRIPTOR, *PNVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS_DESCRIPTOR;

typedef struct {

    NVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS_DESCRIPTOR     DirectivesSupported;
    NVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS_DESCRIPTOR     DirectivesEnabled;

    //
    // This data structure is 4KB in size.  The reserved space is commented out
    // so that this data structure can be safely allocated on the stack.
    //
    //UCHAR   Reserved[4032]; // 4096 - 32 - 32 = 4032

} NVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS, *PNVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS;

typedef union {

    struct {
        ULONG   ENDIR       : 1;    // Enable Directive
        ULONG   Reserved0   : 7;
        ULONG   DTYPE       : 8;    // Directive Type
        ULONG   Reserved1   : 16;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_CDW12_DIRECTIVE_SEND_IDENTIFY_ENABLE_DIRECTIVE, *PNVME_CDW12_DIRECTIVE_SEND_IDENTIFY_ENABLE_DIRECTIVE;

//
// Parameters for the Streams Directive Type
//
typedef enum {

    NVME_DIRECTIVE_RECEIVE_STREAMS_OPERATION_RETURN_PARAMETERS = 1,
    NVME_DIRECTIVE_RECEIVE_STREAMS_OPERATION_GET_STATUS = 2,
    NVME_DIRECTIVE_RECEIVE_STREAMS_OPERATION_ALLOCATE_RESOURCES = 3

} NVME_DIRECTIVE_RECEIVE_STREAMS_OPERATIONS;

typedef enum {

    NVME_DIRECTIVE_SEND_STREAMS_OPERATION_RELEASE_IDENTIFIER = 1,
    NVME_DIRECTIVE_SEND_STREAMS_OPERATION_RELEASE_RESOURCES = 2

} NVME_DIRECTIVE_SEND_STREAMS_OPERATIONS;

typedef struct {

    USHORT  MSL;    // Max Streams Limit
    USHORT  NSSA;   // NVM Subsystem Streams Available
    USHORT  NSSO;   // NVM Subsystem Streams Open
    UCHAR   Reserved0[10];

    ULONG   SWS;    // Stream Write Size
    USHORT  SGS;    // Stream Granularity Size
    USHORT  NSA;    // Namespace Streams Allocated
    USHORT  NSO;    // Namespace Streams Open
    UCHAR   Reserved1[6];

} NVME_DIRECTIVE_STREAMS_RETURN_PARAMETERS, *PNVME_DIRECTIVE_STREAMS_RETURN_PARAMETERS;

#define NVME_STREAMS_GET_STATUS_MAX_IDS 65535

typedef struct {

    USHORT  OpenStreamCount;            // Number of currently open streams.
    USHORT  StreamIdentifiers[NVME_STREAMS_GET_STATUS_MAX_IDS];   // Array of stream IDs that are currently open.

} NVME_DIRECTIVE_STREAMS_GET_STATUS_DATA, *PNVME_DIRECTIVE_STREAMS_GET_STATUS_DATA;

typedef union {

    struct {
        ULONG   NSR         : 16;   // Namespace Streams Requested
        ULONG   Reserved    : 16;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_CDW12_DIRECTIVE_RECEIVE_STREAMS_ALLOCATE_RESOURCES, *PNVME_CDW12_DIRECTIVE_RECEIVE_STREAMS_ALLOCATE_RESOURCES;

typedef struct {

    struct {
        ULONG   NSA         : 16;   // Namespace Streams Allocated
        ULONG   Reserved    : 16;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_COMPLETION_DW0_DIRECTIVE_RECEIVE_STREAMS_ALLOCATE_RESOURCES, *PNVME_COMPLETION_DW0_DIRECTIVE_RECEIVE_STREAMS_ALLOCATE_RESOURCES;

typedef union {
    NVME_CDW12_DIRECTIVE_SEND_IDENTIFY_ENABLE_DIRECTIVE EnableDirective;

    ULONG AsUlong;
} NVME_CDW12_DIRECTIVE_SEND;

typedef union {
    NVME_CDW12_DIRECTIVE_RECEIVE_STREAMS_ALLOCATE_RESOURCES AllocateResources;

    ULONG AsUlong;
} NVME_CDW12_DIRECTIVE_RECEIVE;

//
// NVM Command Set
//
typedef enum {

    NVME_NVM_COMMAND_FLUSH                  = 0x00,
    NVME_NVM_COMMAND_WRITE                  = 0x01,
    NVME_NVM_COMMAND_READ                   = 0x02,

    NVME_NVM_COMMAND_WRITE_UNCORRECTABLE    = 0x04,
    NVME_NVM_COMMAND_COMPARE                = 0x05,
    NVME_NVM_COMMAND_WRITE_ZEROES           = 0x08,
    NVME_NVM_COMMAND_DATASET_MANAGEMENT     = 0x09,
    NVME_NVM_COMMAND_RESERVATION_REGISTER   = 0x0D,
    NVME_NVM_COMMAND_RESERVATION_REPORT     = 0x0E,
    NVME_NVM_COMMAND_RESERVATION_ACQUIRE    = 0x11,
    NVME_NVM_COMMAND_RESERVATION_RELEASE    = 0x15,

} NVME_NVM_COMMANDS;

//
// Data structure of CDW12 for Read/Write command
//
typedef union {

    struct {
        ULONG   NLB         : 16;       // Number of Logical Blocks (NLB)
        ULONG   Reserved0   : 4;
        ULONG   DTYPE       : 4;        // Directive Type (DTYPE)
        ULONG   Reserved1   : 2;
        ULONG   PRINFO      : 4;        // Protection Information Field (PRINFO)
        ULONG   FUA         : 1;        // Force Unit Access (FUA)
        ULONG   LR          : 1;        // Limited Retry (LR)
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW12_READ_WRITE, *PNVME_CDW12_READ_WRITE;

//
// Data structure of CDW13 for Read/Write command
//
typedef enum {

    NVME_ACCESS_FREQUENCY_NONE                  = 0,    // No frequency information provided.
    NVME_ACCESS_FREQUENCY_TYPICAL               = 1,    // Typical number of reads and writes expected for this LBA range.
    NVME_ACCESS_FREQUENCY_INFR_WRITE_INFR_READ  = 2,    // Infrequent writes and infrequent reads to the LBA range indicated.
    NVME_ACCESS_FREQUENCY_INFR_WRITE_FR_READ    = 3,    // Infrequent writes and frequent reads to the LBA range indicated.
    NVME_ACCESS_FREQUENCY_FR_WRITE_INFR_READ    = 4,    // Frequent writes and infrequent reads to the LBA range indicated.
    NVME_ACCESS_FREQUENCY_FR_WRITE_FR_READ      = 5,    // Frequent writes and frequent reads to the LBA range indicated.
    NVME_ACCESS_FREQUENCY_ONE_TIME_READ         = 6,    // One time read. E.g. command is due to virus scan, backup, file copy, or archive.
    NVME_ACCESS_FREQUENCY_SPECULATIVE_READ      = 7,    // Speculative read. The command is part of a prefetch operation.
    NVME_ACCESS_FREQUENCY_WILL_BE_OVERWRITTEN   = 8,    // The LBA range is going to be overwritten in the near future.

} NVME_ACCESS_FREQUENCIES;


typedef enum {

    NVME_ACCESS_LATENCY_NONE                = 0,        // None.  No latency information provided.
    NVME_ACCESS_LATENCY_IDLE                = 1,        // Idle. Longer latency acceptable
    NVME_ACCESS_LATENCY_NORMAL              = 2,        // Normal. Typical latency.
    NVME_ACCESS_LATENCY_LOW                 = 3,        // Low. Smallest possible latency

} NVME_ACCESS_LATENCIES;

typedef union {

    struct {
        struct {
            UCHAR   AccessFrequency     : 4;
            UCHAR   AccessLatency       : 2;
            UCHAR   SequentialRequest   : 1;
            UCHAR   Incompressible      : 1;
        } DSM;                      // Dataset Management (DSM)

        UCHAR   Reserved;
        USHORT  DSPEC;                // Directive Specific Value

    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW13_READ_WRITE, *PNVME_CDW13_READ_WRITE;

//
// Data structure of CDW15 for Read/Write command
//
typedef union {

    struct {
        ULONG   ELBAT       : 16;       // Expected Logical Block Application Tag (ELBAT)
        ULONG   ELBATM      : 16;       // Expected Logical Block Application Tag Mask (ELBATM)
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW15_READ_WRITE, *PNVME_CDW15_READ_WRITE;


//
// Dataset Management - Range Definition
//
typedef union {

    struct {
        ULONG   AccessFrequency         : 4;
        ULONG   AccessLatency           : 2;
        ULONG   Reserved0               : 2;
        ULONG   SequentialReadRange     : 1;
        ULONG   SequentialWriteRange    : 1;
        ULONG   WritePrepare            : 1;
        ULONG   Reserved1               : 13;
        ULONG   CommandAccessSize       : 8;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CONTEXT_ATTRIBUTES, *PNVME_CONTEXT_ATTRIBUTES;

typedef struct {

    NVME_CONTEXT_ATTRIBUTES Attributes;             // The use of this information is optional and the controller is not required to perform any specific action.
    ULONG                   LogicalBlockCount;
    ULONGLONG               StartingLBA;

} NVME_LBA_RANGE, *PNVME_LBA_RANGE;

typedef union {

    struct {
        ULONG   NR          : 8;        // Number of Ranges (NR)
        ULONG   Reserved    : 24;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW10_DATASET_MANAGEMENT, *PNVME_CDW10_DATASET_MANAGEMENT;

typedef union {

    struct {
        ULONG   IDR         : 1;        // Integral Dataset for Read (IDR)
        ULONG   IDW         : 1;        // Integral Dataset for Write (IDW)
        ULONG   AD          : 1;        // Deallocate (AD)
        ULONG   Reserved    : 29;
    } DUMMYSTRUCTNAME;

    ULONG   AsUlong;

} NVME_CDW11_DATASET_MANAGEMENT, *PNVME_CDW11_DATASET_MANAGEMENT;



//
// Command Dword 0
//
typedef union {

    struct {
        //LSB
        ULONG OPC       : 8;        // Opcode (OPC)
        ULONG FUSE      : 2;        // Fused Operation (FUSE)
        ULONG Reserved0 : 5;
        ULONG PSDT      : 1;        // PRP or SGL for Data Transfer (PSDT)
        ULONG CID       : 16;       // Command Identifier (CID)
        //MSB
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;

} NVME_COMMAND_DWORD0, *PNVME_COMMAND_DWORD0;

//
// Fused Operation code
//
typedef enum {

    NVME_FUSED_OPERATION_NORMAL         = 0,
    NVME_FUSED_OPERATION_FIRST_CMD      = 1,
    NVME_FUSED_OPERATION_SECOND_CMD     = 2,

} NVME_FUSED_OPERATION_CODES;


typedef union {

    struct {
        //LSB
        ULONGLONG Reserved0 : 2;
        ULONGLONG PBAO      : 62;       // Page Base Address and Offset (PBAO)
        //MSB
    } DUMMYSTRUCTNAME;

    ULONGLONG AsUlonglong;

} NVME_PRP_ENTRY, *PNVME_PRP_ENTRY;

//
// If the namespace is not used for the command, then 'NSID' field shall be cleared to 0h.
// If a command shall be applied to all namespaces on the device, then 'NSID' field shall be set to FFFFFFFFh.
//
#define NVME_NAMESPACE_ALL              0xFFFFFFFF

//
// NVMe command data structure
//
typedef struct {
    //
    // Common fields for all commands
    //
    NVME_COMMAND_DWORD0 CDW0;
    ULONG               NSID;
    ULONG               Reserved0[2];
    ULONGLONG           MPTR;
    ULONGLONG           PRP1;
    ULONGLONG           PRP2;

    //
    // Command independent fields from CDW10 to CDW15
    //
    union {

        //
        // General Command data fields
        //
        struct {
            ULONG   CDW10;
            ULONG   CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } GENERAL;

        //
        // Admin Command: Identify
        //
        struct {
            NVME_CDW10_IDENTIFY CDW10;
            NVME_CDW11_IDENTIFY CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } IDENTIFY;

        //
        // Admin Command: Abort
        //
        struct {
            NVME_CDW10_ABORT CDW10;
            ULONG   CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } ABORT;

        //
        // Admin Command: Get/Set Features
        //
        struct {
            NVME_CDW10_GET_FEATURES CDW10;
            NVME_CDW11_FEATURES     CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } GETFEATURES;

        struct {
            NVME_CDW10_SET_FEATURES CDW10;
            NVME_CDW11_FEATURES     CDW11;
            NVME_CDW12_FEATURES     CDW12;
            NVME_CDW13_FEATURES     CDW13;
            NVME_CDW14_FEATURES     CDW14;
            NVME_CDW15_FEATURES     CDW15;
        } SETFEATURES;

        //
        // Admin Command: Get Log Page
        //
        struct {
            union {
                NVME_CDW10_GET_LOG_PAGE     CDW10;
                NVME_CDW10_GET_LOG_PAGE_V13 CDW10_V13;
            };

            NVME_CDW11_GET_LOG_PAGE CDW11;
            NVME_CDW12_GET_LOG_PAGE CDW12;
            NVME_CDW13_GET_LOG_PAGE CDW13;
            ULONG                   CDW14;
            ULONG                   CDW15;
        } GETLOGPAGE;

        //
        // Admin Command: Create IO Completion Queue
        //
        struct {
            NVME_CDW10_CREATE_IO_QUEUE CDW10;
            NVME_CDW11_CREATE_IO_CQ    CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } CREATEIOCQ;

        //
        // Admin Command: Create IO Submission Queue
        //
        struct {
            NVME_CDW10_CREATE_IO_QUEUE CDW10;
            NVME_CDW11_CREATE_IO_SQ    CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } CREATEIOSQ;

        //
        // NVM Command: Dataset Management
        //
        struct {
            NVME_CDW10_DATASET_MANAGEMENT   CDW10;
            NVME_CDW11_DATASET_MANAGEMENT   CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } DATASETMANAGEMENT;

        //
        // Admin Command: SECURITY SEND
        //
        struct {
            NVME_CDW10_SECURITY_SEND_RECEIVE    CDW10;
            NVME_CDW11_SECURITY_SEND            CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } SECURITYSEND;

        //
        // Admin Command: SECURITY RECEIVE
        //
        struct {
            NVME_CDW10_SECURITY_SEND_RECEIVE    CDW10;
            NVME_CDW11_SECURITY_RECEIVE         CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } SECURITYRECEIVE;

        //
        // Admin Command: FIRMWARE IMAGE DOWNLOAD
        //
        struct {
            NVME_CDW10_FIRMWARE_DOWNLOAD        CDW10;
            NVME_CDW11_FIRMWARE_DOWNLOAD        CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } FIRMWAREDOWNLOAD;

        //
        // Admin Command: FIRMWARE ACTIVATE
        //
        struct {
            NVME_CDW10_FIRMWARE_ACTIVATE        CDW10;
            ULONG   CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } FIRMWAREACTIVATE;

        //
        // Admin Command: FORMAT NVM
        //
        struct {
            NVME_CDW10_FORMAT_NVM               CDW10;
            ULONG   CDW11;
            ULONG   CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } FORMATNVM;

        //
        // Admin Command: DIRECTIVE RECEIVE
        //
        struct {
            NVME_CDW10_DIRECTIVE_RECEIVE        CDW10;
            NVME_CDW11_DIRECTIVE_RECEIVE        CDW11;
            NVME_CDW12_DIRECTIVE_RECEIVE        CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } DIRECTIVERECEIVE;

        //
        // Admin Command: DIRECTIVE SEND
        //
        struct {
            NVME_CDW10_DIRECTIVE_SEND           CDW10;
            NVME_CDW11_DIRECTIVE_SEND           CDW11;
            NVME_CDW12_DIRECTIVE_SEND           CDW12;
            ULONG   CDW13;
            ULONG   CDW14;
            ULONG   CDW15;
        } DIRECTIVESEND;

        //
        // NVM Command: Read/Write
        //
        struct {
            ULONG                   LBALOW;
            ULONG                   LBAHIGH;
            NVME_CDW12_READ_WRITE   CDW12;
            NVME_CDW13_READ_WRITE   CDW13;
            ULONG                   CDW14;
            NVME_CDW15_READ_WRITE   CDW15;
        } READWRITE;

    } u;

} NVME_COMMAND, *PNVME_COMMAND;



//
// The SCSI name string identifier used for the page 83 descriptor in NVMe to SCSI translation
// For NVMe devices compliant with revision 1.0.
//
typedef struct {

    CHAR PCIVendorID[4];
    CHAR ModelNumber[40];
    CHAR NamespaceID[4];
    CHAR SerialNumber[20];

} NVME_SCSI_NAME_STRING, *PNVME_SCSI_NAME_STRING;

#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default:4214)
#pragma warning(default:4201)
#pragma warning(default:4200)
#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PKG_STORAGE) */
#pragma endregion

#endif //NVME_INCLUDED


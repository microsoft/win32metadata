/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    ntddmtm.h

Abstract:

    This is the include file that defines common constants, types and control codes
    related to multi-tier memory, including technologies like High Bandwidth Memory (HBM),
    Compute Express Link (CXL) memory devices, etc.

    MTM_PD
        Multi-Tier Memory Physical Device

    MTM_BUS
        Multi-Tier Memory Bus

--*/

#include <winapifamily.h>
#include <devioctl.h>

#ifdef __cplusplus
extern "C" {
#endif


#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) 

//
// Interface GUIDs
//
// need these GUIDs outside conditional includes so that user can
//   #include <ntddmtm.h> in precompiled header
//   #include <initguid.h> in a single source file
//   #include <ntddmtm.h> in that source file a second time to instantiate the GUIDs
//
#ifdef DEFINE_GUID

//
// Supported device interfaces
//

// begin_wioctlguids

//
// This interface represents a physical multi-tier memory device.
// {3D487AE7-166A-481D-915E-2FA163D7E386}
//
DEFINE_GUID(GUID_DEVINTERFACE_MTM_PHYSICAL_DEVICE, 0x3d487ae7, 0x166a, 0x481d, 0x91, 0x5e, 0x2f, 0xa1, 0x63, 0xd7, 0xe3, 0x86);


// end_wioctlguids

#endif // DEFINE_GUID

// begin_winioctl

#ifndef _NTDDMTM_H_
#define _NTDDMTM_H_

#pragma warning(push)
#pragma warning(disable:4201) // nameless struct/union
#pragma warning(disable:4214) // bit field types other than int


#if (NTDDI_VERSION >= NTDDI_WIN11_GE)

//
// Functions 0 to 0x2FF are reserved for the bus device.
// Functions 0x300 to 0x5FF are reserved for the physical multi tier memory device (including CXL Type3).
// Functions 0x800 and above are reserved for non-Microsoft users.
//

#define IOCTL_MTMBUS_BASE FILE_DEVICE_MULTITIER_MEMORY

#define IOCTL_MTMBUS_DEVICE_FUNCTION_BASE           0x0
#define IOCTL_MTM_PHYSICAL_DEVICE_FUNCTION_BASE     0x300

#define MTMBUS_FUNCTION(x)              (IOCTL_MTMBUS_DEVICE_FUNCTION_BASE + x)
#define MTM_PHYSICAL_DEVICE_FUNCTION(x) (IOCTL_MTM_PHYSICAL_DEVICE_FUNCTION_BASE + x)

//
// Multi-Tier Memory (MTM) bus device IOCTLs.
//

#define IOCTL_MTM_BUS_QUERY_PROPERTY                CTL_CODE(IOCTL_MTMBUS_BASE, MTMBUS_FUNCTION(0x00), METHOD_BUFFERED, FILE_ANY_ACCESS)


//
// IOCTLs exposed by physical multi-tier memory device (MTM_PD) objects.
//

#define IOCTL_MTM_PD_QUERY_PROPERTY                 CTL_CODE(IOCTL_MTMBUS_BASE, MTM_PHYSICAL_DEVICE_FUNCTION(0x00), METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MTM_PD_COMMAND_PASSTHROUGH            CTL_CODE(IOCTL_MTMBUS_BASE, MTM_PHYSICAL_DEVICE_FUNCTION(0x01), METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MTM_PD_FIRMWARE_TRANSFER              CTL_CODE(IOCTL_MTMBUS_BASE, MTM_PHYSICAL_DEVICE_FUNCTION(0x02), METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_MTM_PD_FIRMWARE_ACTIVATE              CTL_CODE(IOCTL_MTMBUS_BASE, MTM_PHYSICAL_DEVICE_FUNCTION(0x03), METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_MTM_PD_SET_PROPERTY                   CTL_CODE(IOCTL_MTMBUS_BASE, MTM_PHYSICAL_DEVICE_FUNCTION(0x04), METHOD_BUFFERED, FILE_WRITE_ACCESS)



//
// The payload for MTM BUS IOCTLs.
//


//
// IOCTL_MTM_BUS_QUERY_PROPERTY
//
// Input Buffer:
//      a MTM_BUS_PROPERTY_QUERY structure which describes what property is being
//      queried for, and any additional parameters which a particular property
//      query requires.
//
//  Output Buffer:
//      Contains a buffer to place the results of the query into. Since all
//      property descriptors can be cast into a MTM_BUS_DESCRIPTOR_HEADER,
//      the IOCTL can be called once with a small buffer then again using
//      a buffer as large as the header reports is necessary.
//

//
// Types of queries
//

typedef enum _MTM_BUS_QUERY_TYPE {
    MtmBusQuery_Descriptor = 0, // Retrieves the descriptor
    MtmBusQuery_IsSupported,    // Used to test whether the descriptor is supported

    MtmBusQuery_Max
} MTM_BUS_QUERY_TYPE, *PMTM_BUS_QUERY_TYPE;


typedef enum _MTM_BUS_PROPERTY_ID {

    //
    // Query the flat memory ranges on the system.
    //
    MtmBusProperty_FlatMemoryRanges = 0,

    MtmBusProperty_Max
} MTM_BUS_PROPERTY_ID, *PMTM_BUS_PROPERTY_ID;

//
// Query structure - additional parameters for specific queries can follow
// the header
//

#define MTM_BUS_PROPERTY_QUERY_VERSION  1

typedef struct _MTM_BUS_PROPERTY_QUERY {

    //
    // Version of this structure. MTM_BUS_PROPERTY_QUERY_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure, including any additional
    // parameters.
    //
    ULONG Size;

    //
    // ID of the property being retrieved
    //
    MTM_BUS_PROPERTY_ID PropertyId;

    //
    // The type of query being performed.
    //
    MTM_BUS_QUERY_TYPE QueryType;

    //
    // Size of the additional parameters buffer.
    //
    ULONG AdditionalParametersLength;

    //
    // Space for additional parameters if necessary.
    //
    _Field_size_(AdditionalParametersLength) UCHAR AdditionalParameters[ANYSIZE_ARRAY];

} MTM_BUS_PROPERTY_QUERY, *PMTM_BUS_PROPERTY_QUERY;


//
// Standard property descriptor header. All property pages should use this
// as their first element or should contain these two elements
//

typedef struct _MTM_BUS_DESCRIPTOR_HEADER {

    //
    // The version of the descriptor.
    //
    ULONG Version;

    //
    // The size of the entire descriptor (not just the header).
    //
    ULONG Size;

} MTM_BUS_DESCRIPTOR_HEADER, *PMTM_BUS_DESCRIPTOR_HEADER;


//
// MtmBusProperty_FlatMemoryRanges property gets flat memory ranges.
//
// Output buffer for MtmBusProperty_FlatMemoryRanges
//

typedef enum _MTM_FLAT_MEMORY_TYPE {
    MultiTierMemory_FlatMemory_ExtendedLinear,

    MultiTierMemory_FlatMemory_Max
} MTM_FLAT_MEMORY_TYPE, *PMTM_FLAT_MEMORY_TYPE;

typedef struct _MTM_FLAT_MEMORY_EXTENDED_LINEAR_INFO {

    //
    // The number of potential aliased addresses impacted by a memory error.
    //
    ULONG NumberOfAliasedAddresses;

    //
    // The length of the cache range in bytes.
    //
    ULONG64 CacheSize;

} MTM_FLAT_MEMORY_EXTENDED_LINEAR_INFO, *PMTM_FLAT_MEMORY_EXTENDED_LINEAR_INFO;

#define MTM_FLAT_MEMORY_RANGE_VERSION   1

typedef struct _MTM_FLAT_MEMORY_RANGE {

    //
    // Version of this structure. MTM_FLAT_MEMORY_RANGE_VERSION.
    //
    ULONG Version;

    //
    // The size of the entire descriptor (not just the header).
    //
    ULONG Size;

    //
    // Start of the flat memory range.
    //
    ULONG64 SPAStart;

    //
    // The length of the flat memory range in bytes.
    //
    ULONG64 SPALength;

    //
    // Size of the additional parameters buffer.
    //
    ULONG AdditionalParametersLength;

    //
    // Additional information of this flat memory based on its type.
    //
    _Field_size_(AdditionalParametersLength) UCHAR AdditionalParameters[ANYSIZE_ARRAY];

} MTM_FLAT_MEMORY_RANGE, *PMTM_FLAT_MEMORY_RANGE;

#define MTM_FLAT_MEMORY_RANGES_VERSION  1

typedef struct _MTM_FLAT_MEMORY_RANGES {

    //
    // Version of this structure. MTM_FLAT_MEMORY_RANGES_VERSION.
    //
    ULONG Version;

    //
    // Total size of descriptor.
    //
    ULONG Size;

    //
    // Type of the flat memory on the system.
    //
    MTM_FLAT_MEMORY_TYPE Type;

    //
    // Bit Flags of the flat memory.
    // 
    ULONG Flags;

    //
    // The number of flat memory ranges.
    //
    ULONG FlatMemoryRangesCount;

    //
    // The detailed information of flat memory ranges on the system.
    //
    _Field_size_(FlatMemoryRangesCount) MTM_FLAT_MEMORY_RANGE FlatMemoryRanges[ANYSIZE_ARRAY];

} MTM_FLAT_MEMORY_RANGES, *PMTM_FLAT_MEMORY_RANGES;



//
// The payload for a physical device XXX.
//


//
// IOCTL_MTM_PD_QUERY_PROPERTY
//
// Input Buffer:
//      An MTM_PD_PROPERTY_QUERY structure that describes the type of query
//      being done, the property being queried, and any additional parameters
//      the query requires.
//
//  Output Buffer:
//      Contains a buffer to place the results of the query into. Since all
//      property descriptors can be cast into an MTM_PD_DESCRIPTOR_HEADER,
//      the IOCTL can be called once with a small buffer then again using
//      a buffer as large as the header reports is necessary.
//


//
// Types of queries
//

typedef enum _MTM_PD_QUERY_TYPE {
    MtmPhysicalDeviceQuery_Descriptor = 0, // Retrieves the descriptor
    MtmPhysicalDeviceQuery_IsSupported, // Used to test whether the descriptor is supported

    MtmPhysicalDeviceQuery_Max
} MTM_PD_QUERY_TYPE, *PMTM_PD_QUERY_TYPE;


//
// IOCTL_MTM_PD_SET_PROPERTY
//
// Input Buffer:
//      An MTM_PD_PROPERTY_SET structure that describes the type of set
//      being done, the property being set, and any additional parameters
//      the set requires.
//
//  Output Buffer:
//      Contains a buffer to place the results of the set into. Since all
//      property descriptors can be cast into an SCM_PD_DESCRIPTOR_HEADER,
//      the IOCTL can be called once with a small buffer then again using
//      a buffer as large as the header reports is necessary.
//


//
// Types of sets
//

typedef enum _MTM_PD_SET_TYPE {
    MtmPhysicalDeviceSet_Descriptor = 0, // Retrieves the descriptor
    MtmPhysicalDeviceSet_IsSupported, // Used to test whether the descriptor is supported

    MtmPhysicalDeviceSet_Max
} MTM_PD_SET_TYPE, *PMTM_PD_SET_TYPE;


typedef enum _MTM_PD_PROPERTY_ID {

    //
    // General information about the device.
    //
    MtmPhysicalDeviceProperty_DeviceInfo = 0,

    //
    // Returns an identifying handle of the physical device.
    //
    MtmPhysicalDeviceProperty_DeviceHandle,

    //
    // Returns firmware information of the physical device.
    //
    MtmPhysicalDeviceProperty_FirmwareInfo,

    //
    // Returns timestamp information of the physical device.
    //
    MtmPhysicalDeviceProperty_TimestampInfo,

    //
    // Returns the supported logs and their related information of the physical device.
    //
    MtmPhysicalDeviceProperty_SupportedLogs,

    //
    // Returns a specific type log data of the physical device.
    //
    MtmPhysicalDeviceProperty_LogData,

    //
    // Returns alert information of the physical device.
    //
    MtmPhysicalDeviceProperty_AlertConfigInfo,

    //
    // Returns saved event from the physical device.
    //
    MtmPhysicalDeviceProperty_SavedEvent,

    //
    // Returns the health info from the physical device.
    //
    MtmPhysicalDeviceProperty_HealthInfo,

    //
    // Returns the poison list from the physical device.
    //
    MtmPhysicalDeviceProperty_PoisonList,

    MtmPhysicalDeviceProperty_Max
} MTM_PD_PROPERTY_ID, *PMTM_PD_PROPERTY_ID;

//
// Query structure - additional parameters for specific queries can follow
// the header
//

#define MTM_PD_PROPERTY_QUERY_VERSION   1

typedef struct _MTM_PD_PROPERTY_QUERY {

    //
    // Version of this structure. MTM_PD_PROPERTY_QUERY_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure, including any additional
    // parameters.
    //
    ULONG Size;

    //
    // ID of the property being retrieved.
    //
    MTM_PD_PROPERTY_ID PropertyId;

    //
    // The type of query being performed.
    //
    MTM_PD_QUERY_TYPE QueryType;

    //
    // Size of the additional parameters buffer.
    //
    ULONG AdditionalParametersLength;

    //
    // Space for additional parameters if necessary.
    //
    _Field_size_(AdditionalParametersLength) UCHAR AdditionalParameters[ANYSIZE_ARRAY];

} MTM_PD_PROPERTY_QUERY, *PMTM_PD_PROPERTY_QUERY;


//
// Set structure - additional parameters for specific sets can follow
// the header
//

#define MTM_PD_PROPERTY_SET_VERSION 1

typedef struct _MTM_PD_PROPERTY_SET {

    //
    // Version of this structure. MTM_PD_PROPERTY_SET_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure, including any additional
    // parameters.
    //
    ULONG Size;

    //
    // ID of the property being retrieved.
    //
    MTM_PD_PROPERTY_ID PropertyId;

    //
    // The type of set being performed.
    //
    MTM_PD_SET_TYPE SetType;

    //
    // Size of the additional parameters buffer.
    //
    ULONG AdditionalParametersLength;

    //
    // Space for additional parameters if necessary.
    //
    _Field_size_(AdditionalParametersLength) UCHAR AdditionalParameters[ANYSIZE_ARRAY];

} MTM_PD_PROPERTY_SET, *PMTM_PD_PROPERTY_SET;


//
// Standard property descriptor header. All property pages should use this
// as their first element or should contain these two elements
//

typedef struct _MTM_PD_DESCRIPTOR_HEADER {

    //
    // The version of the descriptor.
    //
    ULONG Version;

    //
    // The size of the entire descriptor (not just the header).
    //
    ULONG Size;
} MTM_PD_DESCRIPTOR_HEADER, *PMTM_PD_DESCRIPTOR_HEADER;

//
// The MtmPhysicalDeviceProperty_DeviceHandle property gets identifying information about
// a physical device.
//
// Output buffer for MtmPhysicalDeviceProperty_DeviceHandle
//

#define MTM_PD_DEVICE_HANDLE_VERSION    1

typedef struct _MTM_PD_DEVICE_HANDLE {

    //
    // Version of this structure. MTM_PD_DEVICE_HANDLE_VERSION.
    //
    ULONG Version;

    //
    // The total size of the structure.
    //
    ULONG Size;

    //
    // A GUID that uniquely identifies the physical device, based on hardware information.
    //
    GUID DeviceGuid;

    //
    // A handle, that uniquely identifies the physical device on a local (PCI BDF can do this or not?)
    // system.
    //
    ULONG DeviceHandle;

} MTM_PD_DEVICE_HANDLE, *PMTM_PD_DEVICE_HANDLE;

//
// Output buffer for MtmPhysicalDeviceProperty_DeviceInfo
//

#define MTM_PD_DEVICE_INFO_VERSION  1

typedef struct _MTM_PD_DEVICE_INFO {

    //
    // Version of this structure. MTM_PD_DEVICE_INFO_VERSION.
    //
    ULONG Version;

    //
    // The total size of the structure, including the serial number at the end.
    // If the output buffer is too small to contain the requested information,
    // the Size field indicates the length of the output buffer the caller should provide
    // in order to retrieve all the data.
    //
    ULONG Size;

    //
    // A GUID that uniquely identifies the physical device, based on hardware information.
    //
    GUID DeviceGuid;

    //
    // The total size of the volatile only memory the physical device.
    //
    ULONG64 VolatileOnlySizeInBytes;

    //
    // The total size of the persistent only memory of the physical device.
    //
    ULONG64 PersistentOnlySizeInBytes;

    //
    // The total size of memory that can be either volatile or persistent memory on the physical device.
    //
    ULONG64 PartitionAlignmentSizeInBytes;

    //
    // The total capacity of this memory device, including persistent only,
    // volatile only memory, and partitions that can be either volatile and persistent memory.
    //
    ULONG64 TotalSizeInBytes;

    //
    // Vendor and product IDs.
    //
    ULONG VendorId;
    ULONG DeviceId;
    ULONG SubsystemVendorId;
    ULONG SubsystemId;

    //
    // Device Handle.
    //
    ULONG DeviceHandle;

    ULONG Reserved[7];

    //
    // Offset of the serial number string from the beginning of this structure.
    //
    USHORT SerialNumberOffset;

    //
    // The length of the serial number string in chars, including ending null.
    //
    USHORT SerialNumberLengthInChars;

    //
    // Offset of the location string from the beginning of this structure.
    //
    USHORT LocationOffset;

    //
    // The length of the location string in chars, including ending null.
    //
    USHORT LocationLengthInChars;

    //
    // Offset of the current firmware revision string from the beginning of this structure.
    //
    USHORT FirmwareRevisionOffset;

    //
    // The length of the firmware revision string in chars, including ending null.
    //
    USHORT FirmwareRevisionLengthInChars;

} MTM_PD_DEVICE_INFO, *PMTM_PD_DEVICE_INFO;

//
// Output Buffer for MtmPhysicalDeviceProperty_FirmwareInfo
//

#define MTM_PD_FIRMWARE_SLOT_INFO_VERSION   1
#define MTM_PD_FIRMWARE_REVISION_LENGTH_BYTES   32

typedef struct _MTM_PD_FIRMWARE_SLOT_INFO {

    //
    // Version of this structure. MTM_PD_FIRMWARE_SLOT_INFO_VERSION.
    //
    ULONG Version;

    //
    // Size of the data contained in this structure.
    //
    ULONG Size;

    //
    // Slot number is 1 based.
    //
    UCHAR SlotNumber;

    UCHAR Reserved[7];

    UCHAR Revision[MTM_PD_FIRMWARE_REVISION_LENGTH_BYTES];

} MTM_PD_FIRMWARE_SLOT_INFO, *PMTM_PD_FIRMWARE_SLOT_INFO;

#define MTM_PD_FIRMWARE_INFO_VERSION  1

typedef struct _MTM_PD_FIRMWARE_INFO {

    //
    // Version of this structure. MTM_PD_FIRMWARE_INFO_VERSION.
    //
    ULONG Version;

    //
    // The total size of the structure, including the serial number at the end.
    // If the output buffer is too small to contain the requested information,
    // the Size field indicates the length of the output buffer the caller should provide
    // in order to retrieve all the data.
    //
    ULONG Size;

    //
    // The firmware slot that is currently active. Slot number is 1 based.
    //
    UCHAR ActiveSlot;

    //
    // The slot that will become active once the device is reset. Slot number is 1 based.
    // A value of 0 means there is no slot waiting to be activated.
    //
    UCHAR NextActiveSlot;

    struct {
        UCHAR FirmwareUpdateSupported : 1;
        UCHAR OnlineFirmwareActivation : 1;

        UCHAR Reserved : 6;
    } Capabilities;

    UCHAR SlotCount;

    _Field_size_(SlotCount) MTM_PD_FIRMWARE_SLOT_INFO Slots[ANYSIZE_ARRAY];

} MTM_PD_FIRMWARE_INFO, *PMTM_PD_FIRMWARE_INFO;

//
// Output Buffer for MtmPhysicalDeviceProperty_TimestampInfo
//

#define MTM_PD_TIMESTAMP_INFO_VERSION   1

typedef struct _MTM_PD_TIMESTAMP_INFO {

    //
    // Version of this structure. MTM_PD_TIMESTAMP_INFO_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // The number of unsigned nanoseconds that have elapsed
    // since midnight, 01-Jan-1970, UTC.
    //
    ULONGLONG Timestamp;

} MTM_PD_TIMESTAMP_INFO, *PMTM_PD_TIMESTAMP_INFO;


//
// Output Buffer for MtmPhysicalDeviceProperty_SupportedLogs
//

typedef enum _MTM_PD_LOG_TYPE {
    MtmPhysicalDeviceLogType_Unknown,

    MtmPhysicalDeviceLogType_CxlCommandEffectsLog,
    MtmPhysicalDeviceLogType_CxlVendorDebugLog,
    MtmPhysicalDeviceLogType_CxlComponentStateDumpLog,
    MtmPhysicalDeviceLogType_CxlDDR5ErrorCheckScrubLog,
    MtmPhysicalDeviceLogType_CxlMediaTestCapabilityLog,
    MtmPhysicalDeviceLogType_CxlMediaTestResultsShortLog,
    MtmPhysicalDeviceLogType_CxlMediaTestResultsLongLog,

    MtmPhysicalDeviceLogType_Max
} MTM_PD_LOG_TYPE, *PMTM_PD_LOG_TYPE;

typedef struct _MTM_PD_LOG_INFO_ENTRY {

    //
    // UUID of the log.
    //
    GUID LogIdentifier;

    MTM_PD_LOG_TYPE Type;

    struct {
        ULONG ClearLogSupported : 1;
        ULONG PopulateLogSupported : 1;
        ULONG AutoPopulateSupported : 1;
        ULONG PersistentAcrossColdReset : 1;

        ULONG Reserved : 28;
    } Flags;

    //
    // The maximum number of bytes of log data available to retrieve.
    //
    ULONG LogDataSize;

} MTM_PD_LOG_INFO_ENTRY, *PMTM_PD_LOG_INFO_ENTRY;

#define MTM_PD_LOG_INFO_VERSION 1

typedef struct _MTM_PD_LOG_INFO {

    //
    // Version of this structure. MTM_PD_LOG_INFO_VERSION
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // The number of the log info entries.
    //
    ULONG LogInfoCount;

    //
    // The information of different logs the physical device supports.
    //
    _Field_size_(LogInfoCount) MTM_PD_LOG_INFO_ENTRY LogInfo[ANYSIZE_ARRAY];

} MTM_PD_LOG_INFO, *PMTM_PD_LOG_INFO;

//
// Input Buffer for MtmPhysicalDeviceProperty_LogData
//

typedef enum _MTM_PD_LOG_QUERY_BY {
    MtmPhysicalDeviceLogQueryBy_LogType,
    MtmPhysicalDeviceLogQueryBy_LogIdentifier,

    MtmPhysicalDeviceLogQueryBy_Max
} MTM_PD_LOG_QUERY_BY, *PMTM_PD_LOG_QUERY_BY;

#define MTM_PD_LOG_DATA_INPUT_VERSION   1

typedef struct _MTM_PD_LOG_DATA_INPUT {

    //
    // Version of this structure. MTM_PD_LOG_DATA_INPUT_VERSION
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // The byte offset in the log data to return.
    //
    ULONG OffsetInBytes;

    //
    // The length in bytes of log data to return.
    //
    ULONG LengthInBytes;

    ULONG Reserved;

    //
    // QueryBy determines which value type is used in the below QueryType field.
    //
    MTM_PD_LOG_QUERY_BY QueryBy;

    union {

        //
        // Log Type representing the log for which to retrieve data.
        //
        MTM_PD_LOG_TYPE LogType;

        //
        // UUID representing the log for which to retrieve data.
        //
        GUID LogIdentifier;
    } QueryType;

} MTM_PD_LOG_DATA_INPUT, *PMTM_PD_LOG_DATA_INPUT;

//
// Output Buffer for MtmPhysicalDeviceProperty_LogData
//

#define MTM_PD_LOG_DATA_OUTPUT_VERSION  1

typedef struct _MTM_PD_LOG_DATA_OUTPUT {

    //
    // Version of this structure. MTM_PD_LOG_DATA_OUTPUT_VERSION
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // The length in bytes of log data returned.
    //
    ULONG LogDataLengthInBytes;

    //
    // The log returned.
    //
    _Field_size_(LogDataLengthInBytes) UCHAR LogData[ANYSIZE_ARRAY];

} MTM_PD_LOG_DATA_OUTPUT, *PMTM_PD_LOG_DATA_OUTPUT;

//
// IOCTL_MTM_PD_COMMAND_PASSTHROUGH
//
// Input Buffer:
//      MTM_PD_COMMAND_PASSTHROUGH_INPUT
//      This structure describes the command type, command, input buffer length, and input buffer.
//
//  Output Buffer:
//      MTM_PD_COMMAND_PASSTHROUGH_OUTPUT
//      This structure describes the command status, output buffer length, and output buffer.
//

typedef enum _MTM_PD_COMMAND_TYPE {
    MtmPdCommandType_Mailbox,

    MtmPdCommandType_Max
} MTM_PD_COMMAND_TYPE, *PMTM_PD_COMMAND_TYPE;

typedef struct _MTM_PD_COMMAND {
    MTM_PD_COMMAND_TYPE Type;

    //
    // Union used to define different types of commands.
    //
    union {
        USHORT MailboxCommand;

        ULONG AsUlong;
    } u;
} MTM_PD_COMMAND, *PMTM_PD_COMMAND;

#define MTM_PD_COMMAND_PASSTHROUGH_INPUT_VERSION    1

typedef struct _MTM_PD_COMMAND_PASSTHROUGH_INPUT {

    //
    // Version of this structure. MTM_PD_COMMAND_PASSTHROUGH_INPUT_VERSION.
    //
    ULONG Version;

    //
    // size of this structure including the input buffer.
    //
    ULONG Size;

    MTM_PD_COMMAND Command;

    //
    // Input buffer of the passthrough command.
    //
    ULONG InputBufferLength;
    _Field_size_(InputBufferLength) UCHAR InputBuffer[ANYSIZE_ARRAY];
} MTM_PD_COMMAND_PASSTHROUGH_INPUT, *PMTM_PD_COMMAND_PASSTHROUGH_INPUT;

typedef struct _MTM_PD_COMMAND_STATUS {

    MTM_PD_COMMAND_TYPE Type;

    //
    // Union used to define different types of command return status.
    //
    union {
        struct {
            USHORT ReturnCode;
            USHORT VendorSpecificExtendedStatus;

            struct {
                UCHAR BackgroundOperation : 1;
                UCHAR PercentageComplete : 7;

                UCHAR Reserved;

                USHORT CommandOpcode;
                USHORT ReturnCode;
                USHORT VendorSpecificExtendedStatus;
            } BackgroundCommand;
        } Mailbox;
    } u;

} MTM_PD_COMMAND_STATUS, *PMTM_PD_COMMAND_STATUS;

#define MTM_PD_COMMAND_PASSTHROUGH_OUTPUT_VERSION   1

typedef struct _MTM_PD_COMMAND_PASSTHROUGH_OUTPUT {

    //
    // Version of this structure. MTM_PD_COMMAND_PASSTHROUGH_OUTPUT_VERSION.
    //
    ULONG Version;

    //
    // The total size of the structure, including the output buffer at the end.
    // If the output buffer is too small to contain the requested information,
    // the Size field indicates the length of the output buffer the caller should provide
    // in order to retrieve all the data.
    //
    ULONG Size;

    //
    // Status of the passthrough command.
    //
    MTM_PD_COMMAND_STATUS Status;

    //
    // Output buffer of the passthrough command.
    //
    ULONG OutputBufferLength;
    _Field_size_(OutputBufferLength) UCHAR OutputBuffer[ANYSIZE_ARRAY];

} MTM_PD_COMMAND_PASSTHROUGH_OUTPUT, *PMTM_PD_COMMAND_PASSTHROUGH_OUTPUT;

//
// IOCTL_MTM_PD_FIRMWARE_TRANSFER
//
// Input Buffer:
//      MTM_PD_FIRMWARE_TRANSFER
//      This structure describes the firmware transfer parameters.
//

#define MTM_PD_FIRMWARE_TRANSFER_VERSION    1

typedef enum MTM_PD_FIRMWARE_TRANSFER_ACTION {
    MtmPdFirmwareTransfer_FullImage,

    MtmPdFirmwareTransfer_Max
} MTM_PD_FIRMWARE_TRANSFER_ACTION, *PMTM_PD_FIRMWARE_TRANSFER_ACTION;

typedef struct _MTM_PD_FIRMWARE_TRANSFER {

    //
    // Version of this structure. MTM_PD_FIRMWARE_TRANSFER_VERSION.
    //
    ULONG Version;

    //
    // The total size of the structure, including the firmware data buffer.
    //
    ULONG Size;

    UCHAR Slot;

    UCHAR Action;   // MTM_PD_FIRMWARE_TRANSFER_ACTION

    UCHAR Reserved[22];

    //
    // Input buffer of the firmware transfer.
    //
    ULONG FirmwareImageSizeInBytes;
    _Field_size_(FirmwareImageSizeInBytes) UCHAR FirmwareImage[ANYSIZE_ARRAY];

} MTM_PD_FIRMWARE_TRANSFER, *PMTM_PD_FIRMWARE_TRANSFER;

C_ASSERT(sizeof(MTM_PD_FIRMWARE_TRANSFER) == 40);

//
// IOCTL_MTM_PD_FIRMWARE_ACTIVATE
//
// Input Buffer:
//      MTM_PD_FIRMWARE_ACTIVATE
//      This structure describes the firmware activate parameters.
//

#define MTM_PD_FIRMWARE_ACTIVATE_VERSION    1

typedef struct _MTM_PD_FIRMWARE_ACTIVATE {

    //
    // Version of this structure. MTM_PD_FIRMWARE_ACTIVATE_VERSION.
    //
    ULONG Version;

    //
    // The total size of the structure.
    //
    ULONG Size;

    UCHAR Slot;

    UCHAR Reserved[7];

} MTM_PD_FIRMWARE_ACTIVATE, *PMTM_PD_FIRMWARE_ACTIVATE;

//
// IOCTL_MTM_PD_FIRMWARE_ACTIVATE
// IOCTL_MTM_PD_FIRMWARE_TRANSFER
//
// Output Buffer:
//       MTM_PD_FIRMWARE_OUTPUT
//       This structure describes the firmware activate/transfer output result.

typedef enum _MTM_PD_FIRMWARE_RESULT {
    MtmPdFirmwareResult_NoActionSpecified,

    MtmPdFirmwareResult_NoActionNeeded,
    MtmPdFirmwareResult_CxlResetNeeded,
    MtmPdFirmwareResult_ConventionalResetNeeded,
    MtmPdFirmwareResult_ColdResetNeeded,

    MtmPdFirmwareResult_Max
} MTM_PD_FIRMWARE_RESULT, *PMTM_PD_FIRMWARE_RESULT;

#define MTM_PD_FIRMWARE_OUTPUT_VERSION 1

typedef struct _MTM_PD_FIRMWARE_OUTPUT {

    //
    // Version of this structure. MTM_PD_FIRMWARE_OUTPUT_VERSION.
    //
    ULONG Version;

    //
    // The total size of the structure.
    //
    ULONG Size;

    ULONG DurationInMilliSeconds;

    MTM_PD_FIRMWARE_RESULT Result;

} MTM_PD_FIRMWARE_OUTPUT, *PMTM_PD_FIRMWARE_OUTPUT;



#define MTM_PD_GET_ALERT_CONFIG_INFO_VERSION   1

typedef struct _MTM_PD_GET_ALERT_CONFIG_INFO {

    //
    // Version of this structure. MTM_PD_GET_ALERT_CONFIG_INFO_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // Alert Configuration
    //
    union {
        struct {
            UCHAR LifeUsed: 1;
            UCHAR DeviceOverTemp : 1;
            UCHAR DeviceUnderTemp : 1;
            UCHAR CorrectedVolatileMemory : 1;
            UCHAR CorrectedPersistentMemory : 1;
            UCHAR Reserved : 3;
        } bits;
        UCHAR AsUchar;
    } ValidAlerts;
    
    union {
        struct {
            UCHAR LifeUsed: 1;
            UCHAR DeviceOverTemp : 1;
            UCHAR DeviceUnderTemp : 1;
            UCHAR CorrectedVolatileMemory : 1;
            UCHAR CorrectedPersistentMemory : 1;
            UCHAR Reserved : 3;
        } bits;
        UCHAR AsUchar;
    } ProgrammableAlerts;

    UCHAR LifeUsedCriticalThreshold;
    UCHAR LifeUsedProgWarningThreshold;
    USHORT DeviceOverTempCriticalThreshold;
    USHORT DeviceUnderTempCriticalThreshold;
    USHORT DeviceOverTempProgWarningThreshold;
    USHORT DeviceUnderTempProgWarningThreshold;
    USHORT CorrectedVolatileMemoryProgWarningThreshold;
    USHORT CorrectedPersistentMemoryProgWarningThreshold;
} MTM_PD_GET_ALERT_CONFIG_INFO, *PMTM_PD_GET_ALERT_CONFIG_INFO;

#define MTM_PD_SET_ALERT_CONFIG_INFO_VERSION   1

typedef struct _MTM_PD_SET_ALERT_CONFIG_INFO {

    //
    // Version of this structure. MTM_PD_SET_ALERTCONFIG_INFO_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // Alert Configuration
    //
    union {
        struct {
            UCHAR LifeUsed: 1;
            UCHAR DeviceOverTemp : 1;
            UCHAR DeviceUnderTemp : 1;
            UCHAR CorrectedVolatileMemory : 1;
            UCHAR CorrectedPersistentMemory : 1;
            UCHAR Reserved : 3;
        } bits;
        UCHAR AsUchar;
    } ValidAlertActions;

    union {
        struct {
            UCHAR LifeUsed: 1;
            UCHAR DeviceOverTemp : 1;
            UCHAR DeviceUnderTemp : 1;
            UCHAR CorrectedVolatileMemory : 1;
            UCHAR CorrectedPersistentMemory : 1;
            UCHAR Reserved : 3;
        } bits;
        UCHAR AsUchar;
    } EnableAlertActions;

    UCHAR LifeUsedProgWarningThreshold;
    UCHAR Reserved;
    USHORT DeviceOverTempProgWarningThreshold;
    USHORT DeviceUnderTempProgWarningThreshold;
    USHORT CorrectedVolatileMemoryProgWarningThreshold;
    USHORT CorrectedPersistentMemoryProgWarningThreshold;
} MTM_PD_SET_ALERT_CONFIG_INFO, *PMTM_PD_SET_ALERT_CONFIG_INFO;

#define MTM_PD_GET_SAVED_EVENT_VERSION   1
#define MTM_PD_EVENT_SIZE 128

typedef enum _MTM_PD_EVENT_SEVERITY {
    MtmPdEventSeverity_All,
    MtmPdEventSeverity_Informational,
    MtmPdEventSeverity_Warning,
    MtmPdEventSeverity_Failure,
    MtmPdEventSeverity_Fatal,

    MtmPdEventSeverity_Max
} MTM_PD_EVENT_SEVERITY, *PMTM_PD_EVENT_SEVERITY;

typedef enum _MTM_PD_EVENT_TYPE {
    MtmPdEventType_GeneralMediaEvent,
    MtmPdEventType_DramEvent,
    MtmPdEventType_MemoryModuleEvent,
    MtmPdEventType_MemorySparingEvent,
    MtmPdEventType_DynamicCapacityEvent,

    MtmPdEventType_Max
} MTM_PD_EVENT_TYPE, *PMTM_PD_EVENT_TYPE;

//
// Retrieve an Event Record from the drivers stored circular buffer
//
typedef struct _MTM_PD_GET_SAVED_EVENT_INPUT {
    //
    // Version of this structure. MTM_PD_GET_SAVED_EVENT_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // The event severity to retrieve saved events for - MTM_PD_EVENT_SEVERITY
    //
    UCHAR EventSeverity; 

    //
    // The event record to retrieve
    //
    UCHAR EventRecord;
} MTM_PD_GET_SAVED_EVENT_INPUT, *PMTM_PD_GET_SAVED_EVENT_INPUT;

//
// Retrieve an Event Record from the drivers stored circular buffer
//
typedef struct _MTM_PD_GET_SAVED_EVENT_OUTPUT {
    //
    // Version of this structure. MTM_PD_GET_SAVED_EVENT_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // TotalEventsReceived - Number of events currently saved in the driver for the EventSeverity
    // EventBufferSize - The size of the circular event buffer allocated by the driver for the EventSeverity
    // NumberOfSavedEvents - Number of events currently saved in the driver for the EventSeverity
    // OldestEvent - Oldest event in the circular buffer for the EventSeverity
    // EventData - The CXL event payload for the given EventSeverity and EventRecord
    // EventType - The type of event based on the event GUID - MTM_PD_EVENT_TYPE
    //
    ULONG TotalEventsReceived;
    UCHAR EventBufferSize;
    UCHAR NumberOfSavedEvents;
    UCHAR OldestEvent;
    UCHAR EventType; 
    UCHAR EventData[MTM_PD_EVENT_SIZE];
} MTM_PD_GET_SAVED_EVENT_OUTPUT, *PMTM_PD_GET_SAVED_EVENT_OUTPUT;

#define MTM_PD_INJECT_ERROR_VERSION   1
#define MTM_PD_INJECT_ERROR_DOE_REQUEST_HEADER_SIZE 4

typedef enum _MTM_PD_INJECT_ERROR_TYPE {
    MtmPdInjectErrorType_UCMemError,
    MtmPdInjectErrorType_CEMemError,
    MtmPdInjectErrorType_ClearUCMemError,
    MtmPdInjectErrorType_HealthStatus,
    MtmPdInjectErrorType_MediaStatus,
    MtmPdInjectErrorType_LifeUsed,
    MtmPdInjectErrorType_DeviceTemperature,
    MtmPdInjectErrorType_Doe,

    MtmPdInjectErrorType_Max
} MTM_PD_INJECT_ERROR_TYPE, *PMTM_PD_INJECT_ERROR_TYPE;

typedef struct _MTM_PD_INJECT_ERROR {

    //
    // Version of this structure. MTM_PD_INJECT_ERROR_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // The error to inject
    //
    UCHAR InjectErrorType; // MTM_PD_INJECT_ERROR_TYPE

    // 
    // When injecting with the DOE interface these fields must also be valid
    //
    USHORT DoeVendorId;
    UCHAR DoeType;  
    UCHAR DoeRequestHeader[MTM_PD_INJECT_ERROR_DOE_REQUEST_HEADER_SIZE];

    //
    // InjectErrorData is dependent on the InjectErrorType
    //
    ULONG InjectErrorDataLength;
    _Field_size_(InjectErrorDataLength) UCHAR InjectErrorData[ANYSIZE_ARRAY];
} MTM_PD_INJECT_ERROR, *PMTM_PD_INJECT_ERROR;

//
// ErrorInjectionType specific structures
//
typedef struct _MTM_PD_INJECT_MEMORY_ERROR_TYPE {
    ULONGLONG InjectErrorPhysicalAddress;
} MTM_PD_INJECT_MEMORY_ERROR_TYPE, *P_MTM_PD_INJECT_MEMORY_ERROR_TYPE;

#define MTM_PD_CLEAR_ERROR_DATA_SIZE 64

typedef struct _MTM_PD_CLEAR_MEMORY_ERROR_TYPE {
    ULONGLONG ClearErrorPhysicalAddress;
    UCHAR ClearErrorData[MTM_PD_CLEAR_ERROR_DATA_SIZE];
} MTM_PD_CLEAR_MEMORY_ERROR_TYPE, *P_MTM_PD_CLEAR_MEMORY_ERROR_TYPE;

#define MTM_PD_GET_HEALTH_INFO_VERSION   1

typedef struct _MTM_PD_GET_HEALTH_INFO {

    //
    // Version of this structure. MTM_PD_GET_HEALTH_INFO_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // Returned Health Info
    //
    union {
        struct {
            UCHAR MaintenanceNeeded : 1;
            UCHAR PerformanceDegraded : 1;
            UCHAR HardwareReplacementNeeded : 1;
            UCHAR MemoryCapacityDegraded : 1;

            UCHAR Reserved : 4;
        } bits;
        UCHAR AsUchar;
    } HealthStatus; 

    UCHAR MediaStatus;

    union {
        struct {
            UCHAR LifeUsed : 2; // CXL_ADDITIONAL_HEALTH_STATUS
            UCHAR DeviceTemperature : 2; // CXL_ADDITIONAL_HEALTH_STATUS
            UCHAR CorrectedVolatileErrorCount : 1; // CXL_ADDITIONAL_HEALTH_STATUS
            UCHAR CorrectedPersistentErrorCount : 1; // CXL_ADDITIONAL_HEALTH_STATUS

            UCHAR Reserved : 2;
        } bits;
        UCHAR AsUchar;   
    } AdditionalStatus; 

    UCHAR LifeUsed;
    USHORT DeviceTemperature;
    ULONG DirtyShutdownCount;
    ULONG CorrectedVolatileErrorCount;
    ULONG CorrectedPersistentErrorCount;
} MTM_PD_GET_HEALTH_INFO, *PMTM_PD_GET_HEALTH_INFO;

typedef enum _MTM_PD_MEDIA_ERROR_SOURCE {
    MtmPdMediaErrorSource_Unknown,
    MtmPdMediaErrorSource_External,
    MtmPdMediaErrorSource_Internal,
    MtmPdMediaErrorSource_Injected,
    MtmPdMediaErrorSource_VendorSpecific,

    MtmPdMediaErrorSource_Max
} MTM_PD_MEDIA_ERROR_SOURCE, *PMTM_PD_MEDIA_ERROR_SOURCE;

typedef struct _MTM_PD_MEDIA_ERROR_RECORD {
    UCHAR ErrorSource; // MTM_PD_MEDIA_ERROR_SOURCE
    ULONGLONG MediaErrorAddress;
    ULONG MediaErrorLength;
} MTM_PD_MEDIA_ERROR_RECORD, *PMTM_PD_MEDIA_ERROR_RECORD;

#define MTM_PD_GET_POISON_LIST_VERSION   1
#define MTM_PD_GET_POISON_LIST_DPA_SHIFT 6

typedef struct _MTM_PD_GET_POISON_LIST_INPUT {

    //
    // Version of this structure. MTM_PD_GET_POISON_LIST_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // Dpa and Length to retrieve the poison list from
    //
    ULONGLONG Dpa;
    ULONGLONG Length;
} MTM_PD_GET_POISON_LIST_INPUT, *PMTM_PD_GET_POISON_LIST_INPUT;

typedef struct _MTM_PD_GET_POISON_LIST_OUTPUT {

    //
    // Version of this structure. MTM_PD_GET_POISON_LIST_VERSION.
    //
    ULONG Version;

    //
    // The size of this structure.
    //
    ULONG Size;

    //
    // Returned Poison List
    //
    ULONG MediaErrorRecordCount;
    _Field_size_(MediaErrorRecordCount) MTM_PD_MEDIA_ERROR_RECORD MediaErrorRecords[ANYSIZE_ARRAY];
} MTM_PD_GET_POISON_LIST_OUTPUT, *PMTM_PD_GET_POISON_LIST_OUTPUT;

#endif // NTDDI_WIN11_GE

#pragma warning(pop)


#endif // _NTDDMTM_H_

// end_winioctl

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#pragma endregion

#ifdef __cplusplus
}
#endif


/*++

Copyright (c) 2010      Microsoft Corporation

Module Name:

   BthLEDef.h

Abstract:

   Public Bluetooth Low Energy Definitions

Environment:

    User mode
  --*/

#ifndef __BTHLEDEF_H__
#define __BTHLEDEF_H__

#ifdef _MSC_VER
#pragma once
#endif //_MSC_VER
#include <winapifamily.h>

#include <minwindef.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)



#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4200)  //
#pragma warning(disable:4201)  // nameless struct/union
#pragma warning(disable:4214)  // bit field types other than int
#endif //_MSC_VER

#if NTDDI_VERSION >= NTDDI_WIN8


//
// Bluetooth LE device interface GUID
//
// {781aee18-7733-4ce4-add0-91f41c67b592}
DEFINE_GUID(GUID_BLUETOOTHLE_DEVICE_INTERFACE,              0x781aee18, 0x7733, 0x4ce4, 0xad, 0xd0, 0x91, 0xf4, 0x1c, 0x67, 0xb5, 0x92);

//
// Bluetooth LE Service device interface GUID
//
// {6e3bb679-4372-40c8-9eaa-4509df260cd8}
DEFINE_GUID(GUID_BLUETOOTH_GATT_SERVICE_DEVICE_INTERFACE,   0x6e3bb679, 0x4372, 0x40c8, 0x9e, 0xaa, 0x45, 0x09, 0xdf, 0x26, 0x0c, 0xd8);



DEFINE_GUID(BTH_LE_ATT_BLUETOOTH_BASE_GUID,                 0x00000000, 0x0000, 0x1000, 0x80, 0x00, 0x00, 0x80, 0x5F, 0x9B, 0x34, 0xFB);


////////////////////////////////////////////////////////////////////////////////
// GATT Constants
////////////////////////////////////////////////////////////////////////////////

//
// Services UUIDs (Assigned numbers)
//
#define BTH_LE_SERVICE_GAP      (0x1800)
#define BTH_LE_SERVICE_GATT     (0x1801)

//
// GATT attribute types (Assigned numbers)
//
#define BTH_LE_GATT_ATTRIBUTE_TYPE_PRIMARY_SERVICE      (0x2800)
#define BTH_LE_GATT_ATTRIBUTE_TYPE_SECONDARY_SERVICE    (0x2801)
#define BTH_LE_GATT_ATTRIBUTE_TYPE_INCLUDE              (0x2802)
#define BTH_LE_GATT_ATTRIBUTE_TYPE_CHARACTERISTIC       (0x2803)

//
// GATT Characteristic Descriptors (Assigned numbers)
//
#define BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_EXTENDED_PROPERTIES   (0x2900)
#define BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_USER_DESCRIPTION      (0x2901)
#define BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_CLIENT_CONFIGURATION  (0x2902)
#define BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_SERVER_CONFIGURATION  (0x2903)
#define BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_FORMAT                (0x2904)
#define BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_AGGREGATE_FORMAT      (0x2905)

//
// GATT Characteristic Types (Assigned numbers)
//
#define BTH_LE_GATT_CHARACTERISTIC_TYPE_DEVICE_NAME                 (0x2A00)
#define BTH_LE_GATT_CHARACTERISTIC_TYPE_APPEARANCE                  (0x2A01)
#define BTH_LE_GATT_CHARACTERISTIC_TYPE_PERIPHERAL_PRIVACY_FLAG     (0x2A02)
#define BTH_LE_GATT_CHARACTERISTIC_TYPE_RECONNECTION_ADDRESS        (0x2A03)
#define BTH_LE_GATT_CHARACTERISTIC_TYPE_PERIPHERAL_PREFERED_CONNECTION_PARAMETER \
                                                                    (0x2A04)
#define BTH_LE_GATT_CHARACTERISTIC_TYPE_SERVICE_CHANGED             (0x2A05)


#define BTH_LE_GAP_APPEARANCE_CATEGORY_OFFSET           0x6
#define BTH_LE_GAP_APPEARANCE_CATEGORY_MASK             0x3ff


#define BTH_LE_GAP_APPEARANCE_GET_CATEGORY(a) \
            ((a >> BTH_LE_GAP_APPEARANCE_CATEGORY_OFFSET) & BTH_LE_GAP_APPEARANCE_CATEGORY_MASK)

#define BTH_LE_GAP_APPEARANCE_SET_CATEGORY(a, c) \
            a = ((a & ~BTH_LE_GAP_APPEARANCE_CATEGORY_MASK) | (c << BTH_LE_GAP_APPEARANCE_CATEGORY_OFFSET))

#define BTH_LE_GAP_APPEARANCE_SUB_CATEGORY_MASK             0x3f

#define BTH_LE_GAP_APPEARANCE_GET_SUB_CATEGORY(a) \
            ((UCHAR)(a & BTH_LE_GAP_APPEARANCE_SUB_CATEGORY_MASK))

#define BTH_LE_GAP_APPEARANCE_SET_SUB_CATEGORY(a, s) \
            a = ((a & ~BTH_LE_GAP_APPEARANCE_SUB_CATEGORY_MASK) | s)

#define BTH_LE_GAP_APPEARANCE_CATEGORY_UNCATEGORIZED        0x0000
#define BTH_LE_GAP_APPEARANCE_CATEGORY_PHONE                0x0001
#define BTH_LE_GAP_APPEARANCE_CATEGORY_COMPUTER             0x0002
#define BTH_LE_GAP_APPEARANCE_CATEGORY_WATCH                0x0003
#define BTH_LE_GAP_APPEARANCE_CATEGORY_CLOCK                0x0004
#define BTH_LE_GAP_APPEARANCE_CATEGORY_DISPLAY              0x0005
#define BTH_LE_GAP_APPEARANCE_CATEGORY_REMOTE_CONTROL       0x0006
#define BTH_LE_GAP_APPEARANCE_CATEGORY_EYE_GLASSES          0x0007
#define BTH_LE_GAP_APPEARANCE_CATEGORY_TAG                  0x0008
#define BTH_LE_GAP_APPEARANCE_CATEGORY_KEYRING              0x0009
#define BTH_LE_GAP_APPEARANCE_CATEGORY_MEDIA_PLAYER         0x000a
#define BTH_LE_GAP_APPEARANCE_CATEGORY_BARCODE_SCANNER      0x000b
#define BTH_LE_GAP_APPEARANCE_CATEGORY_THERMOMETER          0x000c
#define BTH_LE_GAP_APPEARANCE_CATEGORY_HEART_RATE           0x000d
#define BTH_LE_GAP_APPEARANCE_CATEGORY_BLOOD_PRESSURE       0x000e
#define BTH_LE_GAP_APPEARANCE_CATEGORY_HID                  0x000f
#define BTH_LE_GAP_APPEARANCE_CATEGORY_GLUCOSE_METER        0x0010
#define BTH_LE_GAP_APPEARANCE_CATEGORY_RUNNING_WALKING_SENSOR \
                                                            0x0011
#define BTH_LE_GAP_APPEARANCE_CATEGORY_CYCLING              0x0012

#define BTH_LE_GAP_APPEARANCE_CATEGORY_PLUSE_OXIMETER       0x0031
#define BTH_LE_GAP_APPEARANCE_CATEGORY_WEIGHT_SCALE         0x0032
#define BTH_LE_GAP_APPEARANCE_CATEGORY_OUTDOOR_SPORTS_ACTIVITY \
                                                            0x0051

#define BTH_LE_GAP_APPEARANCE_SUBCATEGORY_GENERIC           0x00

#define BTH_LE_GAP_APPEARANCE_WATCH_SUBCATEGORY_SPORTS_WATCH \
                                                            0x01

#define BTH_LE_GAP_APPEARANCE_THERMOMETER_SUBCATEGORY_EAR   0x01

#define BTH_LE_GAP_APPEARANCE_HEART_RATE_SUBCATEGORY_HEART_RATE_BELT \
                                                            0x01

#define BTH_LE_GAP_APPEARANCE_BLOOD_PRESSURE_SUBCATEGORY_ARM \
                                                            0x01
#define BTH_LE_GAP_APPEARANCE_BLOOD_PRESSURE_SUBCATEGORY_WRIST \
                                                            0x02

#define BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_KEYBOARD      0x01
#define BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_MOUSE         0x02
#define BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_JOYSTICK      0x03
#define BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_GAMEPAD       0x04
#define BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_DIGITIZER_TABLET \
                                                            0x05
#define BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_CARD_READER   0x06
#define BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_DIGITAL_PEN   0x07
#define BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_BARCODE_SCANNER \
                                                            0x08

#define BTH_LE_GAP_APPEARANCE_RUNNING_WALKING_SENSOR_SUBCATEGORY_IN_SHOE \
                                                            0x01
#define BTH_LE_GAP_APPEARANCE_RUNNING_WALKING_SENSOR_SUBCATEGORY_ON_SHOE \
                                                            0x02
#define BTH_LE_GAP_APPEARANCE_RUNNING_WALKING_SENSOR_SUBCATEGORY_ON_HIP \
                                                            0x03

#define BTH_LE_GAP_APPEARANCE_CYCLING_SUBCATEGORY_CYCLING_COMPUTER \
                                                            0x01
#define BTH_LE_GAP_APPEARANCE_CYCLING_SUBCATEGORY_SPEED_SENSOR \
                                                            0x02
#define BTH_LE_GAP_APPEARANCE_CYCLING_SUBCATEGORY_CADENCE_SENSOR \
                                                            0x03
#define BTH_LE_GAP_APPEARANCE_CYCLING_SUBCATEGORY_POWER_SENSOR \
                                                            0x04
#define BTH_LE_GAP_APPEARANCE_CYCLING_SUBCATEGORY_SPEED_AND_CADENCE_SENSOR \
                                                            0x05

#define BTH_LE_GAP_APPEARANCE_PULSE_OXIMETER_SUBCATEGORY_FINGERTIP \
                                                            0x01
#define BTH_LE_GAP_APPEARANCE_PULSE_OXIMETER_SUBCATEGORY_WRIST_WORN \
                                                            0x02

#define BTH_LE_GAP_APPEARANCE_OUTDOOR_SPORTS_ACTIVITY_SUBCATEGORY_LOCATION_DISPLAY_DEVICE \
                                                            0x01
#define BTH_LE_GAP_APPEARANCE_OUTDOOR_SPORTS_ACTIVITY_SUBCATEGORY_LOCATION_NAVIGATION_DISPLAY_DEVICE \
                                                            0x02
#define BTH_LE_GAP_APPEARANCE_OUTDOOR_SPORTS_ACTIVITY_SUBCATEGORY_LOCATION_POD \
                                                            0x03
#define BTH_LE_GAP_APPEARANCE_OUTDOOR_SPORTS_ACTIVITY_SUBCATEGORY_LOCATION_NAVIGATION_POD \
                                                            0x04

//
// GATT Included Services Default Maximum Nested Depth
//
#define BTH_LE_GATT_DEFAULT_MAX_INCLUDED_SERVICES_DEPTH                         (3)

////////////////////////////////////////////////////////////////////////////////
// ATT Constants
////////////////////////////////////////////////////////////////////////////////

//
// Transation timeout
//
#define BTH_LE_ATT_TRANSACTION_TIMEOUT 30 // seconds

//
// Maximum size of any attribute value
//
#define BTH_LE_ATT_MAX_VALUE_SIZE 512

//
// CID
//
#define BTH_LE_ATT_CID          (0x0004)

//
// MTU
//
#define BTHLEENUM_ATT_MTU_MIN                       (23)
#define BTHLEENUM_ATT_MTU_MAX                       (0xFFFF)
#define BTHLEENUM_ATT_MTU_DEFAULT                   (BTHLEENUM_ATT_MTU_MIN)
#define BTHLEENUM_ATT_MTU_INITIAL_NEGOTIATION       (525)

////////////////////////////////////////////////////////////////////////////////
// ATT-specific Error Codes
////////////////////////////////////////////////////////////////////////////////

#define BTH_LE_ERROR_INVALID_HANDLE                                 (0x01)
#define BTH_LE_ERROR_READ_NOT_PERMITTED                             (0x02)
#define BTH_LE_ERROR_WRITE_NOT_PERMITTED                            (0x03)
#define BTH_LE_ERROR_INVALID_PDU                                    (0x04)
#define BTH_LE_ERROR_INSUFFICIENT_AUTHENTICATION                    (0x05)
#define BTH_LE_ERROR_REQUEST_NOT_SUPPORTED                          (0x06)
#define BTH_LE_ERROR_INVALID_OFFSET                                 (0x07)
#define BTH_LE_ERROR_INSUFFICIENT_AUTHORIZATION                     (0x08)
#define BTH_LE_ERROR_PREPARE_QUEUE_FULL                             (0x09)
#define BTH_LE_ERROR_ATTRIBUTE_NOT_FOUND                            (0x0A)
#define BTH_LE_ERROR_ATTRIBUTE_NOT_LONG                             (0x0B)
#define BTH_LE_ERROR_INSUFFICIENT_ENCRYPTION_KEY_SIZE               (0x0C)
#define BTH_LE_ERROR_INVALID_ATTRIBUTE_VALUE_LENGTH                 (0x0D)
#define BTH_LE_ERROR_UNLIKELY                                       (0x0E)
#define BTH_LE_ERROR_INSUFFICIENT_ENCRYPTION                        (0x0F)
#define BTH_LE_ERROR_UNSUPPORTED_GROUP_TYPE                         (0x10)
#define BTH_LE_ERROR_INSUFFICIENT_RESOURCES                         (0x11)
#define BTH_LE_ERROR_UNKNOWN                                      (0x1000)

////////////////////////////////////////////////////////////////////////////////
// GATT Security and Other Flag-related Facilities
////////////////////////////////////////////////////////////////////////////////

#define BLUETOOTH_GATT_FLAG_NONE                        0x00000000
#define BLUETOOTH_GATT_FLAG_CONNECTION_ENCRYPTED        0x00000001
#define BLUETOOTH_GATT_FLAG_CONNECTION_AUTHENTICATED    0x00000002
#define BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_DEVICE      0x00000004
#define BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_CACHE       0x00000008
#define BLUETOOTH_GATT_FLAG_SIGNED_WRITE                0x00000010
#define BLUETOOTH_GATT_FLAG_WRITE_WITHOUT_RESPONSE      0x00000020
#define BLUETOOTH_GATT_FLAG_RETURN_ALL                  0x00000040

#define BLUETOOTH_GATT_FLAG_VALID_MASK \
(           BLUETOOTH_GATT_FLAG_NONE \
|           BLUETOOTH_GATT_FLAG_CONNECTION_ENCRYPTED \
|           BLUETOOTH_GATT_FLAG_CONNECTION_AUTHENTICATED \
|           BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_DEVICE \
|           BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_CACHE \
|           BLUETOOTH_GATT_FLAG_SIGNED_WRITE \
|           BLUETOOTH_GATT_FLAG_WRITE_WITHOUT_RESPONSE \
|           BLUETOOTH_GATT_FLAG_RETURN_ALL \
)

#define IS_BLUETOOTH_GATT_FLAG_VALID(f) (0 == (f & ~BLUETOOTH_GATT_FLAG_VALID_MASK))

////////////////////////////////////////////////////////////////////////////////
// GATT Structures
////////////////////////////////////////////////////////////////////////////////

typedef HANDLE BLUETOOTH_GATT_EVENT_HANDLE;

typedef struct _BTH_LE_UUID {
    BOOLEAN IsShortUuid;

#ifdef MIDL_PASS
    [switch_type(BOOLEAN), switch_is((BOOLEAN)IsShortUuid)]
#endif
    union {

#ifdef MIDL_PASS
        [case(TRUE)]
#endif
        USHORT ShortUuid;

#ifdef MIDL_PASS
        [case(FALSE)]
#endif
        GUID LongUuid;
    } Value;
} BTH_LE_UUID, *PBTH_LE_UUID;

typedef struct _BTH_LE_GATT_SERVICE {
    BTH_LE_UUID ServiceUuid;
    USHORT AttributeHandle;
} BTH_LE_GATT_SERVICE, *PBTH_LE_GATT_SERVICE;

typedef enum _BTH_LE_GATT_DESCRIPTOR_TYPE {
    CharacteristicExtendedProperties,
    CharacteristicUserDescription,
    ClientCharacteristicConfiguration,
    ServerCharacteristicConfiguration,
    CharacteristicFormat,
    CharacteristicAggregateFormat,
    CustomDescriptor
} BTH_LE_GATT_DESCRIPTOR_TYPE, *PBTH_LE_GATT_DESCRIPTOR_TYPE;

typedef struct _BTH_LE_GATT_CHARACTERISTIC {
    USHORT ServiceHandle;
    BTH_LE_UUID CharacteristicUuid;
    USHORT AttributeHandle;
    USHORT CharacteristicValueHandle;
    BOOLEAN IsBroadcastable;
    BOOLEAN IsReadable;
    BOOLEAN IsWritable;
    BOOLEAN IsWritableWithoutResponse;
    BOOLEAN IsSignedWritable;
    BOOLEAN IsNotifiable;
    BOOLEAN IsIndicatable;
    BOOLEAN HasExtendedProperties;
} BTH_LE_GATT_CHARACTERISTIC, *PBTH_LE_GATT_CHARACTERISTIC;

typedef struct _BTH_LE_GATT_CHARACTERISTIC_VALUE {
    ULONG DataSize;

#ifdef MIDL_PASS
    [size_is(DataSize)] UCHAR Data[*];
#else
   _Field_size_bytes_(DataSize) UCHAR Data[1];
#endif
} BTH_LE_GATT_CHARACTERISTIC_VALUE, *PBTH_LE_GATT_CHARACTERISTIC_VALUE;

typedef struct _BTH_LE_GATT_DESCRIPTOR {
    USHORT ServiceHandle;
    USHORT CharacteristicHandle;
    BTH_LE_GATT_DESCRIPTOR_TYPE DescriptorType;
    BTH_LE_UUID DescriptorUuid;
    USHORT AttributeHandle;
} BTH_LE_GATT_DESCRIPTOR, *PBTH_LE_GATT_DESCRIPTOR;

typedef struct _BTH_LE_GATT_DESCRIPTOR_VALUE {
    BTH_LE_GATT_DESCRIPTOR_TYPE DescriptorType;
    BTH_LE_UUID DescriptorUuid;

#ifdef MIDL_PASS
    [switch_type(BTH_LE_GATT_DESCRIPTOR_TYPE),
            switch_is((BTH_LE_GATT_DESCRIPTOR_TYPE)DescriptorType)]
#endif
    union {

#ifdef MIDL_PASS
        [case(CharacteristicExtendedProperties)]
#endif
        struct {
            BOOLEAN IsReliableWriteEnabled;
            BOOLEAN IsAuxiliariesWritable;
        } CharacteristicExtendedProperties;

#ifdef MIDL_PASS
        [case(ClientCharacteristicConfiguration)]
#endif
        struct {
            BOOLEAN IsSubscribeToNotification;
            BOOLEAN IsSubscribeToIndication;
        } ClientCharacteristicConfiguration;

#ifdef MIDL_PASS
        [case(ServerCharacteristicConfiguration)]
#endif
        struct {
            BOOLEAN IsBroadcast;
        } ServerCharacteristicConfiguration;

#ifdef MIDL_PASS
        [case(CharacteristicFormat)]
#endif
        struct {
            UCHAR Format;
            UCHAR Exponent;
            BTH_LE_UUID Unit;
            UCHAR NameSpace;
            BTH_LE_UUID Description;
        } CharacteristicFormat;

#ifdef MIDL_PASS
        [default]
            ;
#endif
    };

    ULONG DataSize;

#ifdef MIDL_PASS
    [size_is(DataSize)] UCHAR Data[*];
#else
   _Field_size_bytes_(DataSize) UCHAR Data[1];
#endif
} BTH_LE_GATT_DESCRIPTOR_VALUE, *PBTH_LE_GATT_DESCRIPTOR_VALUE;

typedef enum _BTH_LE_GATT_EVENT_TYPE {
    CharacteristicValueChangedEvent,

} BTH_LE_GATT_EVENT_TYPE;


//
// Callback function signature for Bluetooth GATT events.
//
typedef VOID (CALLBACK *PFNBLUETOOTH_GATT_EVENT_CALLBACK)(
    _In_ BTH_LE_GATT_EVENT_TYPE EventType,
    _In_ PVOID EventOutParameter,
    _In_opt_ PVOID Context
);

//
// Structure associated with a CharacteristicValueChanged Event
//
typedef struct _BLUETOOTH_GATT_VALUE_CHANGED_EVENT_REGISTRATION {
    USHORT NumCharacteristics;
    BTH_LE_GATT_CHARACTERISTIC Characteristics[1];
} BLUETOOTH_GATT_VALUE_CHANGED_EVENT_REGISTRATION, *PBLUETOOTH_GATT_VALUE_CHANGED_EVENT_REGISTRATION;

typedef struct _BLUETOOTH_GATT_VALUE_CHANGED_EVENT {
    USHORT ChangedAttributeHandle;
    size_t CharacteristicValueDataSize;
    PBTH_LE_GATT_CHARACTERISTIC_VALUE CharacteristicValue;
} BLUETOOTH_GATT_VALUE_CHANGED_EVENT, *PBLUETOOTH_GATT_VALUE_CHANGED_EVENT;


typedef ULONG64 BTH_LE_GATT_RELIABLE_WRITE_CONTEXT, *PBTH_LE_GATT_RELIABLE_WRITE_CONTEXT;

#ifdef __cplusplus
extern "C"{
#endif

FORCEINLINE
BOOLEAN
IsBthLEUuidMatch(
    _In_ BTH_LE_UUID uuid1,
    _In_ BTH_LE_UUID uuid2
    )
/*++

Routine Description:

    Determines if the two UUIDs match each other.  If both of the are
    short UUIDs, or if they are both long UUIDs, they will be compared
    directly.  Otherwise, the short UUID will be converted to a long UUID
    using the Bluetooth BASE UUID, and then compared against the long one.

Arguments:
    uuid1 - left comparand
    uuid2 - right comparand


Return Value:
    TRUE if the values are equal, FALSE otherwise

  --*/
{
    BTH_LE_UUID tempLongUuid = {0};

    tempLongUuid.IsShortUuid = FALSE;
    tempLongUuid.Value.LongUuid = BTH_LE_ATT_BLUETOOTH_BASE_GUID;

    if (uuid1.IsShortUuid && uuid2.IsShortUuid) {
        return (uuid1.Value.ShortUuid == uuid2.Value.ShortUuid);
    } else if (!uuid1.IsShortUuid && !uuid2.IsShortUuid) {
        return (0 == memcmp(&uuid1.Value.LongUuid, &uuid2.Value.LongUuid, sizeof(GUID)));
    } else if (uuid1.IsShortUuid) {
        tempLongUuid.Value.LongUuid.Data1 += uuid1.Value.ShortUuid;
        return (0 == memcmp(&tempLongUuid, &uuid2.Value.LongUuid, sizeof(GUID)));
    } else if (uuid2.IsShortUuid) {
        tempLongUuid.Value.LongUuid.Data1 += uuid2.Value.ShortUuid;
        return (0 == memcmp(&uuid1.Value.LongUuid, &tempLongUuid.Value.LongUuid, sizeof(GUID)));
    }

    return FALSE;
}

#ifdef __cplusplus
    }
#endif


#endif //NTDDI_WIN8

#ifdef _MSC_VER
#pragma warning(pop)
#endif //_MSC_VER




#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#endif // __BTHLEDEF_H__


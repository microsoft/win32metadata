// Copyright (C) Microsoft Corporation. All rights reserved.

#pragma once

#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#ifndef NETCX_ADAPTER_2
#error include netadaptercx.h
#endif

EXTERN_C_START

struct _NET_RING;
typedef struct _NET_RING NET_RING;

typedef enum _NET_RING_TYPE {
    NetRingTypePacket,
    NetRingTypeFragment,
} NET_RING_TYPE;

typedef struct _NET_RING_COLLECTION
{

    NET_RING *
        Rings[NetRingTypeFragment + 1];

} NET_RING_COLLECTION;

inline
NET_RING *
NetRingCollectionGetPacketRing(
    NET_RING_COLLECTION const * Rings
)
{
    return Rings->Rings[NetRingTypePacket];
}

inline
NET_RING *
NetRingCollectionGetFragmentRing(
    NET_RING_COLLECTION const * Rings
)
{
    return Rings->Rings[NetRingTypeFragment];
}

EXTERN_C_END

#endif // WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
#pragma endregion


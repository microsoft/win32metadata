//==============================================================;
//
//  MSCLMD.H
//
//  Abstract:
//      Definitions used by the Smart Card PIV and GIDS class
//      mini-driver for Windows.
//
//  This source code is only intended as a supplement to existing
//  Microsoft documentation.
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT
//  WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING
//  BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY
//  AND/OR FITNESS FOR A PARTICULAR PURPOSE.
//
//  Copyright (C) Microsoft Corporation.  All Rights Reserved.
//
//==============================================================;


#ifndef __MSCLMD__H__
#define __MSCLMD__H__

#if defined (_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#pragma warning(push)
#pragma warning(disable:4201)
// Disable error C4201 in public header
//   nonstandard extension used : nameless struct/union
#include <winscard.h>
#pragma warning(pop)

#include <windows.h>
#include <stdio.h>
#include <cardmod.h>

// Special PIN identifiers for PIN ALWAYS and PUK.
#define ROLE_PIN_ALWAYS             3
#define ROLE_PUK                    4

// PIV-specific properties.
#define CP_PIV_CARD_CAPABILITY_CONTAINER                L"PIV CCC"
#define CP_PIV_CARD_HOLDER_UNIQUE_IDENTIFIER            L"PIV CHUID"
#define CP_PIV_CARD_HOLDER_UNSIGNED_UNIQUE_IDENTIFIER   L"PIV UCHUID"
#define CP_PIV_FINGERPRINT                              L"PIV Fingerprint"
#define CP_PIV_SECURITY_OBJECT                          L"PIV Security Object"
#define CP_PIV_FACIAL_IMAGE                             L"PIV Facial Image"
#define CP_PIV_PRINTED_INFORMATION                      L"PIV Printed Information"
#define CP_PIV_GENERATE_KEY                             L"PIV Generate Key"
#define CP_CARD_PIV                                     L"PIV Card"
#define CP_PIV_CERTIFICATE                              L"PIV Certificate"
#define CP_PIV_PUBLIC_KEY                               L"PIV Public Key"
#define CP_PIV_KEY_HISTORY_OBJECT                       L"PIV Key History Object"

#define CLMD_PIV_CERT_DATA_CURRENT_VERSION                  0
#define CLMD_PIV_GENERATE_ASYMMETRIC_KEY_CURRENT_VERSION    0
#define CLMD_PIV_PUBLIC_KEY_DATA_CURRENT_VERSION            0

// File BER-TLV tags for PIV objects
#define CLMD_FILE_TAG_PIV_AUTH_CERT                     0x5FC105
#define CLMD_FILE_TAG_SIG_CERT                          0x5FC10A
#define CLMD_FILE_TAG_KEY_MGMT_CERT                     0x5FC10B
#define CLMD_FILE_TAG_CARD_AUTH_CERT                    0x5FC101
#define CLMD_FILE_TAG_CHUID                             0x5FC102
#define CLMD_FILE_TAG_CARD_CAPABILITY_CONTAINER         0x5FC107
#define CLMD_FILE_TAG_UNSIGNED_CHUID                    0x5FC104
#define CLMD_FILE_TAG_FINGERPRINT                       0x5FC103
#define CLMD_FILE_TAG_SECURITY_OBJECT                   0x5FC106
#define CLMD_FILE_TAG_FACIAL_IMAGE                      0x5FC108
#define CLMD_FILE_TAG_PRINTED_INFORMATION               0x5FC109
#define CLMD_FILE_TAG_KEY_HISTORY                       0x5FC10C
#define CLMD_FILE_TAG_FIRST_RETIRED_KEY_MGMT_KEY        0x5FC10D
#define CLMD_FILE_TAG_LAST_RETIRED_KEY_MGMT_KEY         0x5FC120

// The following structure will be used to pass and retrieve the 
// certificates from the card through the use of CardSetProperty 
// and CardGetProperty.
typedef struct _CLMD_PIV_CERT_DATA
{
    DWORD       dwVersion;
    DWORD       dwCertTag;
    PBYTE       pbCert;
    DWORD       cbCert;
} CLMD_PIV_CERT_DATA, *PCLMD_PIV_CERT_DATA;

// The following structure will be used to generate asymmetric keys. 
// pbKey/cbKey are optional parameters when calling CardSetProperty.
typedef struct _CLMD_PIV_GENERATE_ASYMMETRIC_KEY
{
    DWORD       dwVersion;
    BYTE        bAlgorithmId;       // The container Id associated with this key.
    BYTE        bKeyId;             // 9A, 9C, etc. 
    PBYTE       pbKey;              // The key generation parameters. Example modulus for RSA (tag 81) + public exponent (tag 82)
    DWORD       cbKey;              // Size of the key generation parameters.
} CLMD_PIV_GENERATE_ASYMMETRIC_KEY, *PCLMD_PIV_GENERATE_ASYMMETRIC_KEY;

// The following structure will be used to retrieve the public key 
// of a previously generated asymmetric key pair. Public keys will be
// stored per session.
typedef struct _CLMD_PIV_PUBLIC_KEY_DATA
{
    DWORD       dwVersion;
    BYTE        bKeyId;             // The key Id of the previously generated key. 9A, 9C, etc.
    PBYTE       pbPublicKey;        // The public key buffer as returned from the card.
    DWORD       cbPublicKey;        // Size of the public key buffer.
} CLMD_PIV_PUBLIC_KEY_DATA, *PCLMD_PIV_PUBLIC_KEY_DATA;

#endif

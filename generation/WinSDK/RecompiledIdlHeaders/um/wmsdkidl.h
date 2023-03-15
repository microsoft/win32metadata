

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __wmsdkidl_h__
#define __wmsdkidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IWMMediaProps_FWD_DEFINED__
#define __IWMMediaProps_FWD_DEFINED__
typedef interface IWMMediaProps IWMMediaProps;

#endif 	/* __IWMMediaProps_FWD_DEFINED__ */


#ifndef __IWMVideoMediaProps_FWD_DEFINED__
#define __IWMVideoMediaProps_FWD_DEFINED__
typedef interface IWMVideoMediaProps IWMVideoMediaProps;

#endif 	/* __IWMVideoMediaProps_FWD_DEFINED__ */


#ifndef __IWMWriter_FWD_DEFINED__
#define __IWMWriter_FWD_DEFINED__
typedef interface IWMWriter IWMWriter;

#endif 	/* __IWMWriter_FWD_DEFINED__ */


#ifndef __IWMDRMWriter_FWD_DEFINED__
#define __IWMDRMWriter_FWD_DEFINED__
typedef interface IWMDRMWriter IWMDRMWriter;

#endif 	/* __IWMDRMWriter_FWD_DEFINED__ */


#ifndef __IWMDRMWriter2_FWD_DEFINED__
#define __IWMDRMWriter2_FWD_DEFINED__
typedef interface IWMDRMWriter2 IWMDRMWriter2;

#endif 	/* __IWMDRMWriter2_FWD_DEFINED__ */


#ifndef __IWMDRMWriter3_FWD_DEFINED__
#define __IWMDRMWriter3_FWD_DEFINED__
typedef interface IWMDRMWriter3 IWMDRMWriter3;

#endif 	/* __IWMDRMWriter3_FWD_DEFINED__ */


#ifndef __IWMInputMediaProps_FWD_DEFINED__
#define __IWMInputMediaProps_FWD_DEFINED__
typedef interface IWMInputMediaProps IWMInputMediaProps;

#endif 	/* __IWMInputMediaProps_FWD_DEFINED__ */


#ifndef __IWMPropertyVault_FWD_DEFINED__
#define __IWMPropertyVault_FWD_DEFINED__
typedef interface IWMPropertyVault IWMPropertyVault;

#endif 	/* __IWMPropertyVault_FWD_DEFINED__ */


#ifndef __IWMIStreamProps_FWD_DEFINED__
#define __IWMIStreamProps_FWD_DEFINED__
typedef interface IWMIStreamProps IWMIStreamProps;

#endif 	/* __IWMIStreamProps_FWD_DEFINED__ */


#ifndef __IWMReader_FWD_DEFINED__
#define __IWMReader_FWD_DEFINED__
typedef interface IWMReader IWMReader;

#endif 	/* __IWMReader_FWD_DEFINED__ */


#ifndef __IWMSyncReader_FWD_DEFINED__
#define __IWMSyncReader_FWD_DEFINED__
typedef interface IWMSyncReader IWMSyncReader;

#endif 	/* __IWMSyncReader_FWD_DEFINED__ */


#ifndef __IWMSyncReader2_FWD_DEFINED__
#define __IWMSyncReader2_FWD_DEFINED__
typedef interface IWMSyncReader2 IWMSyncReader2;

#endif 	/* __IWMSyncReader2_FWD_DEFINED__ */


#ifndef __IWMOutputMediaProps_FWD_DEFINED__
#define __IWMOutputMediaProps_FWD_DEFINED__
typedef interface IWMOutputMediaProps IWMOutputMediaProps;

#endif 	/* __IWMOutputMediaProps_FWD_DEFINED__ */


#ifndef __IWMStatusCallback_FWD_DEFINED__
#define __IWMStatusCallback_FWD_DEFINED__
typedef interface IWMStatusCallback IWMStatusCallback;

#endif 	/* __IWMStatusCallback_FWD_DEFINED__ */


#ifndef __IWMReaderCallback_FWD_DEFINED__
#define __IWMReaderCallback_FWD_DEFINED__
typedef interface IWMReaderCallback IWMReaderCallback;

#endif 	/* __IWMReaderCallback_FWD_DEFINED__ */


#ifndef __IWMCredentialCallback_FWD_DEFINED__
#define __IWMCredentialCallback_FWD_DEFINED__
typedef interface IWMCredentialCallback IWMCredentialCallback;

#endif 	/* __IWMCredentialCallback_FWD_DEFINED__ */


#ifndef __IWMMetadataEditor_FWD_DEFINED__
#define __IWMMetadataEditor_FWD_DEFINED__
typedef interface IWMMetadataEditor IWMMetadataEditor;

#endif 	/* __IWMMetadataEditor_FWD_DEFINED__ */


#ifndef __IWMMetadataEditor2_FWD_DEFINED__
#define __IWMMetadataEditor2_FWD_DEFINED__
typedef interface IWMMetadataEditor2 IWMMetadataEditor2;

#endif 	/* __IWMMetadataEditor2_FWD_DEFINED__ */


#ifndef __IWMDRMEditor_FWD_DEFINED__
#define __IWMDRMEditor_FWD_DEFINED__
typedef interface IWMDRMEditor IWMDRMEditor;

#endif 	/* __IWMDRMEditor_FWD_DEFINED__ */


#ifndef __IWMHeaderInfo_FWD_DEFINED__
#define __IWMHeaderInfo_FWD_DEFINED__
typedef interface IWMHeaderInfo IWMHeaderInfo;

#endif 	/* __IWMHeaderInfo_FWD_DEFINED__ */


#ifndef __IWMHeaderInfo2_FWD_DEFINED__
#define __IWMHeaderInfo2_FWD_DEFINED__
typedef interface IWMHeaderInfo2 IWMHeaderInfo2;

#endif 	/* __IWMHeaderInfo2_FWD_DEFINED__ */


#ifndef __IWMHeaderInfo3_FWD_DEFINED__
#define __IWMHeaderInfo3_FWD_DEFINED__
typedef interface IWMHeaderInfo3 IWMHeaderInfo3;

#endif 	/* __IWMHeaderInfo3_FWD_DEFINED__ */


#ifndef __IWMProfileManager_FWD_DEFINED__
#define __IWMProfileManager_FWD_DEFINED__
typedef interface IWMProfileManager IWMProfileManager;

#endif 	/* __IWMProfileManager_FWD_DEFINED__ */


#ifndef __IWMProfileManager2_FWD_DEFINED__
#define __IWMProfileManager2_FWD_DEFINED__
typedef interface IWMProfileManager2 IWMProfileManager2;

#endif 	/* __IWMProfileManager2_FWD_DEFINED__ */


#ifndef __IWMProfileManagerLanguage_FWD_DEFINED__
#define __IWMProfileManagerLanguage_FWD_DEFINED__
typedef interface IWMProfileManagerLanguage IWMProfileManagerLanguage;

#endif 	/* __IWMProfileManagerLanguage_FWD_DEFINED__ */


#ifndef __IWMProfile_FWD_DEFINED__
#define __IWMProfile_FWD_DEFINED__
typedef interface IWMProfile IWMProfile;

#endif 	/* __IWMProfile_FWD_DEFINED__ */


#ifndef __IWMProfile2_FWD_DEFINED__
#define __IWMProfile2_FWD_DEFINED__
typedef interface IWMProfile2 IWMProfile2;

#endif 	/* __IWMProfile2_FWD_DEFINED__ */


#ifndef __IWMProfile3_FWD_DEFINED__
#define __IWMProfile3_FWD_DEFINED__
typedef interface IWMProfile3 IWMProfile3;

#endif 	/* __IWMProfile3_FWD_DEFINED__ */


#ifndef __IWMStreamConfig_FWD_DEFINED__
#define __IWMStreamConfig_FWD_DEFINED__
typedef interface IWMStreamConfig IWMStreamConfig;

#endif 	/* __IWMStreamConfig_FWD_DEFINED__ */


#ifndef __IWMStreamConfig2_FWD_DEFINED__
#define __IWMStreamConfig2_FWD_DEFINED__
typedef interface IWMStreamConfig2 IWMStreamConfig2;

#endif 	/* __IWMStreamConfig2_FWD_DEFINED__ */


#ifndef __IWMStreamConfig3_FWD_DEFINED__
#define __IWMStreamConfig3_FWD_DEFINED__
typedef interface IWMStreamConfig3 IWMStreamConfig3;

#endif 	/* __IWMStreamConfig3_FWD_DEFINED__ */


#ifndef __IWMPacketSize_FWD_DEFINED__
#define __IWMPacketSize_FWD_DEFINED__
typedef interface IWMPacketSize IWMPacketSize;

#endif 	/* __IWMPacketSize_FWD_DEFINED__ */


#ifndef __IWMPacketSize2_FWD_DEFINED__
#define __IWMPacketSize2_FWD_DEFINED__
typedef interface IWMPacketSize2 IWMPacketSize2;

#endif 	/* __IWMPacketSize2_FWD_DEFINED__ */


#ifndef __IWMStreamList_FWD_DEFINED__
#define __IWMStreamList_FWD_DEFINED__
typedef interface IWMStreamList IWMStreamList;

#endif 	/* __IWMStreamList_FWD_DEFINED__ */


#ifndef __IWMMutualExclusion_FWD_DEFINED__
#define __IWMMutualExclusion_FWD_DEFINED__
typedef interface IWMMutualExclusion IWMMutualExclusion;

#endif 	/* __IWMMutualExclusion_FWD_DEFINED__ */


#ifndef __IWMMutualExclusion2_FWD_DEFINED__
#define __IWMMutualExclusion2_FWD_DEFINED__
typedef interface IWMMutualExclusion2 IWMMutualExclusion2;

#endif 	/* __IWMMutualExclusion2_FWD_DEFINED__ */


#ifndef __IWMBandwidthSharing_FWD_DEFINED__
#define __IWMBandwidthSharing_FWD_DEFINED__
typedef interface IWMBandwidthSharing IWMBandwidthSharing;

#endif 	/* __IWMBandwidthSharing_FWD_DEFINED__ */


#ifndef __IWMStreamPrioritization_FWD_DEFINED__
#define __IWMStreamPrioritization_FWD_DEFINED__
typedef interface IWMStreamPrioritization IWMStreamPrioritization;

#endif 	/* __IWMStreamPrioritization_FWD_DEFINED__ */


#ifndef __IWMWriterAdvanced_FWD_DEFINED__
#define __IWMWriterAdvanced_FWD_DEFINED__
typedef interface IWMWriterAdvanced IWMWriterAdvanced;

#endif 	/* __IWMWriterAdvanced_FWD_DEFINED__ */


#ifndef __IWMWriterAdvanced2_FWD_DEFINED__
#define __IWMWriterAdvanced2_FWD_DEFINED__
typedef interface IWMWriterAdvanced2 IWMWriterAdvanced2;

#endif 	/* __IWMWriterAdvanced2_FWD_DEFINED__ */


#ifndef __IWMWriterAdvanced3_FWD_DEFINED__
#define __IWMWriterAdvanced3_FWD_DEFINED__
typedef interface IWMWriterAdvanced3 IWMWriterAdvanced3;

#endif 	/* __IWMWriterAdvanced3_FWD_DEFINED__ */


#ifndef __IWMWriterPreprocess_FWD_DEFINED__
#define __IWMWriterPreprocess_FWD_DEFINED__
typedef interface IWMWriterPreprocess IWMWriterPreprocess;

#endif 	/* __IWMWriterPreprocess_FWD_DEFINED__ */


#ifndef __IWMWriterPostViewCallback_FWD_DEFINED__
#define __IWMWriterPostViewCallback_FWD_DEFINED__
typedef interface IWMWriterPostViewCallback IWMWriterPostViewCallback;

#endif 	/* __IWMWriterPostViewCallback_FWD_DEFINED__ */


#ifndef __IWMWriterPostView_FWD_DEFINED__
#define __IWMWriterPostView_FWD_DEFINED__
typedef interface IWMWriterPostView IWMWriterPostView;

#endif 	/* __IWMWriterPostView_FWD_DEFINED__ */


#ifndef __IWMWriterSink_FWD_DEFINED__
#define __IWMWriterSink_FWD_DEFINED__
typedef interface IWMWriterSink IWMWriterSink;

#endif 	/* __IWMWriterSink_FWD_DEFINED__ */


#ifndef __IWMRegisterCallback_FWD_DEFINED__
#define __IWMRegisterCallback_FWD_DEFINED__
typedef interface IWMRegisterCallback IWMRegisterCallback;

#endif 	/* __IWMRegisterCallback_FWD_DEFINED__ */


#ifndef __IWMWriterFileSink_FWD_DEFINED__
#define __IWMWriterFileSink_FWD_DEFINED__
typedef interface IWMWriterFileSink IWMWriterFileSink;

#endif 	/* __IWMWriterFileSink_FWD_DEFINED__ */


#ifndef __IWMWriterFileSink2_FWD_DEFINED__
#define __IWMWriterFileSink2_FWD_DEFINED__
typedef interface IWMWriterFileSink2 IWMWriterFileSink2;

#endif 	/* __IWMWriterFileSink2_FWD_DEFINED__ */


#ifndef __IWMWriterFileSink3_FWD_DEFINED__
#define __IWMWriterFileSink3_FWD_DEFINED__
typedef interface IWMWriterFileSink3 IWMWriterFileSink3;

#endif 	/* __IWMWriterFileSink3_FWD_DEFINED__ */


#ifndef __IWMWriterNetworkSink_FWD_DEFINED__
#define __IWMWriterNetworkSink_FWD_DEFINED__
typedef interface IWMWriterNetworkSink IWMWriterNetworkSink;

#endif 	/* __IWMWriterNetworkSink_FWD_DEFINED__ */


#ifndef __IWMClientConnections_FWD_DEFINED__
#define __IWMClientConnections_FWD_DEFINED__
typedef interface IWMClientConnections IWMClientConnections;

#endif 	/* __IWMClientConnections_FWD_DEFINED__ */


#ifndef __IWMClientConnections2_FWD_DEFINED__
#define __IWMClientConnections2_FWD_DEFINED__
typedef interface IWMClientConnections2 IWMClientConnections2;

#endif 	/* __IWMClientConnections2_FWD_DEFINED__ */


#ifndef __IWMReaderAdvanced_FWD_DEFINED__
#define __IWMReaderAdvanced_FWD_DEFINED__
typedef interface IWMReaderAdvanced IWMReaderAdvanced;

#endif 	/* __IWMReaderAdvanced_FWD_DEFINED__ */


#ifndef __IWMReaderAdvanced2_FWD_DEFINED__
#define __IWMReaderAdvanced2_FWD_DEFINED__
typedef interface IWMReaderAdvanced2 IWMReaderAdvanced2;

#endif 	/* __IWMReaderAdvanced2_FWD_DEFINED__ */


#ifndef __IWMReaderAdvanced3_FWD_DEFINED__
#define __IWMReaderAdvanced3_FWD_DEFINED__
typedef interface IWMReaderAdvanced3 IWMReaderAdvanced3;

#endif 	/* __IWMReaderAdvanced3_FWD_DEFINED__ */


#ifndef __IWMReaderAdvanced4_FWD_DEFINED__
#define __IWMReaderAdvanced4_FWD_DEFINED__
typedef interface IWMReaderAdvanced4 IWMReaderAdvanced4;

#endif 	/* __IWMReaderAdvanced4_FWD_DEFINED__ */


#ifndef __IWMReaderAdvanced5_FWD_DEFINED__
#define __IWMReaderAdvanced5_FWD_DEFINED__
typedef interface IWMReaderAdvanced5 IWMReaderAdvanced5;

#endif 	/* __IWMReaderAdvanced5_FWD_DEFINED__ */


#ifndef __IWMReaderAdvanced6_FWD_DEFINED__
#define __IWMReaderAdvanced6_FWD_DEFINED__
typedef interface IWMReaderAdvanced6 IWMReaderAdvanced6;

#endif 	/* __IWMReaderAdvanced6_FWD_DEFINED__ */


#ifndef __IWMPlayerHook_FWD_DEFINED__
#define __IWMPlayerHook_FWD_DEFINED__
typedef interface IWMPlayerHook IWMPlayerHook;

#endif 	/* __IWMPlayerHook_FWD_DEFINED__ */


#ifndef __IWMReaderAllocatorEx_FWD_DEFINED__
#define __IWMReaderAllocatorEx_FWD_DEFINED__
typedef interface IWMReaderAllocatorEx IWMReaderAllocatorEx;

#endif 	/* __IWMReaderAllocatorEx_FWD_DEFINED__ */


#ifndef __IWMReaderTypeNegotiation_FWD_DEFINED__
#define __IWMReaderTypeNegotiation_FWD_DEFINED__
typedef interface IWMReaderTypeNegotiation IWMReaderTypeNegotiation;

#endif 	/* __IWMReaderTypeNegotiation_FWD_DEFINED__ */


#ifndef __IWMReaderCallbackAdvanced_FWD_DEFINED__
#define __IWMReaderCallbackAdvanced_FWD_DEFINED__
typedef interface IWMReaderCallbackAdvanced IWMReaderCallbackAdvanced;

#endif 	/* __IWMReaderCallbackAdvanced_FWD_DEFINED__ */


#ifndef __IWMDRMReader_FWD_DEFINED__
#define __IWMDRMReader_FWD_DEFINED__
typedef interface IWMDRMReader IWMDRMReader;

#endif 	/* __IWMDRMReader_FWD_DEFINED__ */


#ifndef __IWMDRMReader2_FWD_DEFINED__
#define __IWMDRMReader2_FWD_DEFINED__
typedef interface IWMDRMReader2 IWMDRMReader2;

#endif 	/* __IWMDRMReader2_FWD_DEFINED__ */


#ifndef __IWMDRMReader3_FWD_DEFINED__
#define __IWMDRMReader3_FWD_DEFINED__
typedef interface IWMDRMReader3 IWMDRMReader3;

#endif 	/* __IWMDRMReader3_FWD_DEFINED__ */


#ifndef __IWMReaderPlaylistBurn_FWD_DEFINED__
#define __IWMReaderPlaylistBurn_FWD_DEFINED__
typedef interface IWMReaderPlaylistBurn IWMReaderPlaylistBurn;

#endif 	/* __IWMReaderPlaylistBurn_FWD_DEFINED__ */


#ifndef __IWMReaderNetworkConfig_FWD_DEFINED__
#define __IWMReaderNetworkConfig_FWD_DEFINED__
typedef interface IWMReaderNetworkConfig IWMReaderNetworkConfig;

#endif 	/* __IWMReaderNetworkConfig_FWD_DEFINED__ */


#ifndef __IWMReaderNetworkConfig2_FWD_DEFINED__
#define __IWMReaderNetworkConfig2_FWD_DEFINED__
typedef interface IWMReaderNetworkConfig2 IWMReaderNetworkConfig2;

#endif 	/* __IWMReaderNetworkConfig2_FWD_DEFINED__ */


#ifndef __IWMReaderStreamClock_FWD_DEFINED__
#define __IWMReaderStreamClock_FWD_DEFINED__
typedef interface IWMReaderStreamClock IWMReaderStreamClock;

#endif 	/* __IWMReaderStreamClock_FWD_DEFINED__ */


#ifndef __IWMIndexer_FWD_DEFINED__
#define __IWMIndexer_FWD_DEFINED__
typedef interface IWMIndexer IWMIndexer;

#endif 	/* __IWMIndexer_FWD_DEFINED__ */


#ifndef __IWMIndexer2_FWD_DEFINED__
#define __IWMIndexer2_FWD_DEFINED__
typedef interface IWMIndexer2 IWMIndexer2;

#endif 	/* __IWMIndexer2_FWD_DEFINED__ */


#ifndef __IWMLicenseBackup_FWD_DEFINED__
#define __IWMLicenseBackup_FWD_DEFINED__
typedef interface IWMLicenseBackup IWMLicenseBackup;

#endif 	/* __IWMLicenseBackup_FWD_DEFINED__ */


#ifndef __IWMLicenseRestore_FWD_DEFINED__
#define __IWMLicenseRestore_FWD_DEFINED__
typedef interface IWMLicenseRestore IWMLicenseRestore;

#endif 	/* __IWMLicenseRestore_FWD_DEFINED__ */


#ifndef __IWMBackupRestoreProps_FWD_DEFINED__
#define __IWMBackupRestoreProps_FWD_DEFINED__
typedef interface IWMBackupRestoreProps IWMBackupRestoreProps;

#endif 	/* __IWMBackupRestoreProps_FWD_DEFINED__ */


#ifndef __IWMCodecInfo_FWD_DEFINED__
#define __IWMCodecInfo_FWD_DEFINED__
typedef interface IWMCodecInfo IWMCodecInfo;

#endif 	/* __IWMCodecInfo_FWD_DEFINED__ */


#ifndef __IWMCodecInfo2_FWD_DEFINED__
#define __IWMCodecInfo2_FWD_DEFINED__
typedef interface IWMCodecInfo2 IWMCodecInfo2;

#endif 	/* __IWMCodecInfo2_FWD_DEFINED__ */


#ifndef __IWMCodecInfo3_FWD_DEFINED__
#define __IWMCodecInfo3_FWD_DEFINED__
typedef interface IWMCodecInfo3 IWMCodecInfo3;

#endif 	/* __IWMCodecInfo3_FWD_DEFINED__ */


#ifndef __IWMLanguageList_FWD_DEFINED__
#define __IWMLanguageList_FWD_DEFINED__
typedef interface IWMLanguageList IWMLanguageList;

#endif 	/* __IWMLanguageList_FWD_DEFINED__ */


#ifndef __IWMWriterPushSink_FWD_DEFINED__
#define __IWMWriterPushSink_FWD_DEFINED__
typedef interface IWMWriterPushSink IWMWriterPushSink;

#endif 	/* __IWMWriterPushSink_FWD_DEFINED__ */


#ifndef __IWMDeviceRegistration_FWD_DEFINED__
#define __IWMDeviceRegistration_FWD_DEFINED__
typedef interface IWMDeviceRegistration IWMDeviceRegistration;

#endif 	/* __IWMDeviceRegistration_FWD_DEFINED__ */


#ifndef __IWMRegisteredDevice_FWD_DEFINED__
#define __IWMRegisteredDevice_FWD_DEFINED__
typedef interface IWMRegisteredDevice IWMRegisteredDevice;

#endif 	/* __IWMRegisteredDevice_FWD_DEFINED__ */


#ifndef __IWMProximityDetection_FWD_DEFINED__
#define __IWMProximityDetection_FWD_DEFINED__
typedef interface IWMProximityDetection IWMProximityDetection;

#endif 	/* __IWMProximityDetection_FWD_DEFINED__ */


#ifndef __IWMDRMMessageParser_FWD_DEFINED__
#define __IWMDRMMessageParser_FWD_DEFINED__
typedef interface IWMDRMMessageParser IWMDRMMessageParser;

#endif 	/* __IWMDRMMessageParser_FWD_DEFINED__ */


#ifndef __IWMDRMTranscryptor_FWD_DEFINED__
#define __IWMDRMTranscryptor_FWD_DEFINED__
typedef interface IWMDRMTranscryptor IWMDRMTranscryptor;

#endif 	/* __IWMDRMTranscryptor_FWD_DEFINED__ */


#ifndef __IWMDRMTranscryptor2_FWD_DEFINED__
#define __IWMDRMTranscryptor2_FWD_DEFINED__
typedef interface IWMDRMTranscryptor2 IWMDRMTranscryptor2;

#endif 	/* __IWMDRMTranscryptor2_FWD_DEFINED__ */


#ifndef __IWMDRMTranscryptionManager_FWD_DEFINED__
#define __IWMDRMTranscryptionManager_FWD_DEFINED__
typedef interface IWMDRMTranscryptionManager IWMDRMTranscryptionManager;

#endif 	/* __IWMDRMTranscryptionManager_FWD_DEFINED__ */


#ifndef __IWMWatermarkInfo_FWD_DEFINED__
#define __IWMWatermarkInfo_FWD_DEFINED__
typedef interface IWMWatermarkInfo IWMWatermarkInfo;

#endif 	/* __IWMWatermarkInfo_FWD_DEFINED__ */


#ifndef __IWMReaderAccelerator_FWD_DEFINED__
#define __IWMReaderAccelerator_FWD_DEFINED__
typedef interface IWMReaderAccelerator IWMReaderAccelerator;

#endif 	/* __IWMReaderAccelerator_FWD_DEFINED__ */


#ifndef __IWMReaderTimecode_FWD_DEFINED__
#define __IWMReaderTimecode_FWD_DEFINED__
typedef interface IWMReaderTimecode IWMReaderTimecode;

#endif 	/* __IWMReaderTimecode_FWD_DEFINED__ */


#ifndef __IWMAddressAccess_FWD_DEFINED__
#define __IWMAddressAccess_FWD_DEFINED__
typedef interface IWMAddressAccess IWMAddressAccess;

#endif 	/* __IWMAddressAccess_FWD_DEFINED__ */


#ifndef __IWMAddressAccess2_FWD_DEFINED__
#define __IWMAddressAccess2_FWD_DEFINED__
typedef interface IWMAddressAccess2 IWMAddressAccess2;

#endif 	/* __IWMAddressAccess2_FWD_DEFINED__ */


#ifndef __IWMImageInfo_FWD_DEFINED__
#define __IWMImageInfo_FWD_DEFINED__
typedef interface IWMImageInfo IWMImageInfo;

#endif 	/* __IWMImageInfo_FWD_DEFINED__ */


#ifndef __IWMLicenseRevocationAgent_FWD_DEFINED__
#define __IWMLicenseRevocationAgent_FWD_DEFINED__
typedef interface IWMLicenseRevocationAgent IWMLicenseRevocationAgent;

#endif 	/* __IWMLicenseRevocationAgent_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "wmsbuffer.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_wmsdkidl_0000_0000 */
/* [local] */ 

//=========================================================================
//
// Microsoft Windows Media Technologies
// Copyright (C) Microsoft Corporation.  All Rights Reserved.
//
//=========================================================================
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
typedef unsigned __int64 QWORD;

































































////////////////////////////////////////////////////////////////
//
// These are the special case attributes that give information 
// about the Windows Media file.
//
static const DWORD g_dwWMSpecialAttributes = 20;
static const WCHAR g_wszWMDuration[] =L"Duration";
static const WCHAR g_wszWMBitrate[] =L"Bitrate";
static const WCHAR g_wszWMSeekable[] =L"Seekable";
static const WCHAR g_wszWMStridable[] =L"Stridable";
static const WCHAR g_wszWMBroadcast[] =L"Broadcast";
static const WCHAR g_wszWMProtected[] =L"Is_Protected";
static const WCHAR g_wszWMTrusted[] =L"Is_Trusted";
static const WCHAR g_wszWMSignature_Name[] =L"Signature_Name";
static const WCHAR g_wszWMHasAudio[] =L"HasAudio";
static const WCHAR g_wszWMHasImage[] =L"HasImage";
static const WCHAR g_wszWMHasScript[] =L"HasScript";
static const WCHAR g_wszWMHasVideo[] =L"HasVideo";
static const WCHAR g_wszWMCurrentBitrate[] =L"CurrentBitrate";
static const WCHAR g_wszWMOptimalBitrate[] =L"OptimalBitrate";
static const WCHAR g_wszWMHasAttachedImages[] =L"HasAttachedImages";
static const WCHAR g_wszWMSkipBackward[] =L"Can_Skip_Backward";
static const WCHAR g_wszWMSkipForward[] =L"Can_Skip_Forward";
static const WCHAR g_wszWMNumberOfFrames[] =L"NumberOfFrames";
static const WCHAR g_wszWMFileSize[] =L"FileSize";
static const WCHAR g_wszWMHasArbitraryDataStream[] =L"HasArbitraryDataStream";
static const WCHAR g_wszWMHasFileTransferStream[] =L"HasFileTransferStream";
static const WCHAR g_wszWMContainerFormat[] =L"WM/ContainerFormat";

////////////////////////////////////////////////////////////////
//
// The content description object supports 5 basic attributes.
//
static const DWORD g_dwWMContentAttributes = 5;
static const WCHAR g_wszWMTitle[] =L"Title";
static const WCHAR g_wszWMTitleSort[] =L"TitleSort";
static const WCHAR g_wszWMAuthor[] =L"Author";
static const WCHAR g_wszWMAuthorSort[] =L"AuthorSort";
static const WCHAR g_wszWMDescription[] =L"Description";
static const WCHAR g_wszWMRating[] =L"Rating";
static const WCHAR g_wszWMCopyright[] =L"Copyright";

////////////////////////////////////////////////////////////////
//
// These attributes are used to configure and query DRM settings in the reader and writer.
//
static const WCHAR g_wszWMUse_DRM[] = L"Use_DRM";
static const WCHAR g_wszWMDRM_Flags[] = L"DRM_Flags";
static const WCHAR g_wszWMDRM_Level[] = L"DRM_Level";
static const WCHAR g_wszWMUse_Advanced_DRM[] = L"Use_Advanced_DRM";
static const WCHAR g_wszWMDRM_KeySeed[] = L"DRM_KeySeed";
static const WCHAR g_wszWMDRM_KeyID[] = L"DRM_KeyID";
static const WCHAR g_wszWMDRM_ContentID[] = L"DRM_ContentID";
static const WCHAR g_wszWMDRM_SourceID[] = L"DRM_SourceID";
static const WCHAR g_wszWMDRM_IndividualizedVersion[] = L"DRM_IndividualizedVersion";
static const WCHAR g_wszWMDRM_LicenseAcqURL[] = L"DRM_LicenseAcqURL";
static const WCHAR g_wszWMDRM_V1LicenseAcqURL[] = L"DRM_V1LicenseAcqURL";
static const WCHAR g_wszWMDRM_HeaderSignPrivKey[] = L"DRM_HeaderSignPrivKey";
static const WCHAR g_wszWMDRM_LASignaturePrivKey[] = L"DRM_LASignaturePrivKey";
static const WCHAR g_wszWMDRM_LASignatureCert[] = L"DRM_LASignatureCert";
static const WCHAR g_wszWMDRM_LASignatureLicSrvCert[] = L"DRM_LASignatureLicSrvCert";
static const WCHAR g_wszWMDRM_LASignatureRootCert[] = L"DRM_LASignatureRootCert";

////////////////////////////////////////////////////////////////
//
// These are the additional attributes defined in the WM attribute
// namespace that give information about the content.
//
static const WCHAR g_wszWMAlbumTitle[] =L"WM/AlbumTitle";
static const WCHAR g_wszWMAlbumTitleSort[] =L"WM/AlbumTitleSort";
static const WCHAR g_wszWMTrack[] =L"WM/Track";
static const WCHAR g_wszWMPromotionURL[] =L"WM/PromotionURL";
static const WCHAR g_wszWMAlbumCoverURL[] =L"WM/AlbumCoverURL";
static const WCHAR g_wszWMGenre[] =L"WM/Genre";
static const WCHAR g_wszWMYear[] =L"WM/Year";
static const WCHAR g_wszWMGenreID[] =L"WM/GenreID";
static const WCHAR g_wszWMMCDI[] =L"WM/MCDI";
static const WCHAR g_wszWMComposer[] =L"WM/Composer";
static const WCHAR g_wszWMComposerSort[] =L"WM/ComposerSort";
static const WCHAR g_wszWMLyrics[] =L"WM/Lyrics";
static const WCHAR g_wszWMTrackNumber[] =L"WM/TrackNumber";
static const WCHAR g_wszWMToolName[] =L"WM/ToolName";
static const WCHAR g_wszWMToolVersion[] =L"WM/ToolVersion";
static const WCHAR g_wszWMIsVBR[] =L"IsVBR";
static const WCHAR g_wszWMAlbumArtist[] =L"WM/AlbumArtist";
static const WCHAR g_wszWMAlbumArtistSort[] =L"WM/AlbumArtistSort";

////////////////////////////////////////////////////////////////
//
// These optional attributes may be used to give information 
// about the branding of the content.
//
static const WCHAR g_wszWMBannerImageType[] =L"BannerImageType";
static const WCHAR g_wszWMBannerImageData[] =L"BannerImageData";
static const WCHAR g_wszWMBannerImageURL[] =L"BannerImageURL";
static const WCHAR g_wszWMCopyrightURL[] =L"CopyrightURL";
////////////////////////////////////////////////////////////////
//
// Optional attributes, used to give information 
// about video stream properties.
//
static const WCHAR g_wszWMAspectRatioX[] =L"AspectRatioX";
static const WCHAR g_wszWMAspectRatioY[] =L"AspectRatioY";
////////////////////////////////////////////////////////////////
//
// Optional attributes, used to give information 
// about the overall streaming properties of VBR files.
// This attribute takes the format:
//  WORD wReserved (must be 0)
//  WM_LEAKY_BUCKET_PAIR pair1
//  WM_LEAKY_BUCKET_PAIR pair2
//  ...
//
static const WCHAR g_wszASFLeakyBucketPairs[] =L"ASFLeakyBucketPairs";
////////////////////////////////////////////////////////////////
//
// The NSC file supports the following attributes.
//
static const DWORD g_dwWMNSCAttributes = 5;
static const WCHAR g_wszWMNSCName[] =L"NSC_Name";
static const WCHAR g_wszWMNSCAddress[] =L"NSC_Address";
static const WCHAR g_wszWMNSCPhone[] =L"NSC_Phone";
static const WCHAR g_wszWMNSCEmail[] =L"NSC_Email";
static const WCHAR g_wszWMNSCDescription[] =L"NSC_Description";

////////////////////////////////////////////////////////////////
//
// Attributes introduced in V9
//
static const WCHAR g_wszWMWriter[] =L"WM/Writer";
static const WCHAR g_wszWMConductor[] =L"WM/Conductor";
static const WCHAR g_wszWMProducer[] =L"WM/Producer";
static const WCHAR g_wszWMDirector[] =L"WM/Director";
static const WCHAR g_wszWMContentGroupDescription[] =L"WM/ContentGroupDescription";
static const WCHAR g_wszWMSubTitle[] =L"WM/SubTitle";
static const WCHAR g_wszWMPartOfSet[] =L"WM/PartOfSet";
static const WCHAR g_wszWMProtectionType[] =L"WM/ProtectionType";
static const WCHAR g_wszWMVideoHeight[] =L"WM/VideoHeight";
static const WCHAR g_wszWMVideoWidth[] =L"WM/VideoWidth";
static const WCHAR g_wszWMVideoFrameRate[] =L"WM/VideoFrameRate";
static const WCHAR g_wszWMMediaClassPrimaryID[] =L"WM/MediaClassPrimaryID";
static const WCHAR g_wszWMMediaClassSecondaryID[] =L"WM/MediaClassSecondaryID";
static const WCHAR g_wszWMPeriod[] = L"WM/Period";
static const WCHAR g_wszWMCategory[] = L"WM/Category";
static const WCHAR g_wszWMPicture[] =L"WM/Picture";
static const WCHAR g_wszWMLyrics_Synchronised[] =L"WM/Lyrics_Synchronised";
static const WCHAR g_wszWMOriginalLyricist[] =L"WM/OriginalLyricist";
static const WCHAR g_wszWMOriginalArtist[] =L"WM/OriginalArtist";
static const WCHAR g_wszWMOriginalAlbumTitle[] =L"WM/OriginalAlbumTitle";
static const WCHAR g_wszWMOriginalReleaseYear[] =L"WM/OriginalReleaseYear";
static const WCHAR g_wszWMOriginalFilename[] =L"WM/OriginalFilename";
static const WCHAR g_wszWMPublisher[] =L"WM/Publisher";
static const WCHAR g_wszWMEncodedBy[] =L"WM/EncodedBy";
static const WCHAR g_wszWMEncodingSettings[] =L"WM/EncodingSettings";
static const WCHAR g_wszWMEncodingTime[] =L"WM/EncodingTime";
static const WCHAR g_wszWMAuthorURL[] =L"WM/AuthorURL";
static const WCHAR g_wszWMUserWebURL[] =L"WM/UserWebURL";
static const WCHAR g_wszWMAudioFileURL[] =L"WM/AudioFileURL";
static const WCHAR g_wszWMAudioSourceURL[] =L"WM/AudioSourceURL";
static const WCHAR g_wszWMLanguage[] =L"WM/Language";
static const WCHAR g_wszWMParentalRating[] =L"WM/ParentalRating";
static const WCHAR g_wszWMBeatsPerMinute[] =L"WM/BeatsPerMinute";
static const WCHAR g_wszWMInitialKey[] =L"WM/InitialKey";
static const WCHAR g_wszWMMood[] =L"WM/Mood";
static const WCHAR g_wszWMText[] =L"WM/Text";
static const WCHAR g_wszWMDVDID[] =L"WM/DVDID";
static const WCHAR g_wszWMWMContentID[] =L"WM/WMContentID";
static const WCHAR g_wszWMWMCollectionID[] =L"WM/WMCollectionID";
static const WCHAR g_wszWMWMCollectionGroupID[] =L"WM/WMCollectionGroupID";
static const WCHAR g_wszWMUniqueFileIdentifier[] =L"WM/UniqueFileIdentifier";
static const WCHAR g_wszWMModifiedBy[] =L"WM/ModifiedBy";
static const WCHAR g_wszWMRadioStationName[] =L"WM/RadioStationName";
static const WCHAR g_wszWMRadioStationOwner[] =L"WM/RadioStationOwner";
static const WCHAR g_wszWMPlaylistDelay[] =L"WM/PlaylistDelay";
static const WCHAR g_wszWMCodec[] =L"WM/Codec";
static const WCHAR g_wszWMDRM[] =L"WM/DRM";
static const WCHAR g_wszWMISRC[] =L"WM/ISRC";
static const WCHAR g_wszWMProvider[] =L"WM/Provider";
static const WCHAR g_wszWMProviderRating[] =L"WM/ProviderRating";
static const WCHAR g_wszWMProviderStyle[] =L"WM/ProviderStyle";
static const WCHAR g_wszWMContentDistributor[] =L"WM/ContentDistributor";
static const WCHAR g_wszWMSubscriptionContentID[] =L"WM/SubscriptionContentID";
static const WCHAR g_wszWMWMADRCPeakReference[] =L"WM/WMADRCPeakReference";
static const WCHAR g_wszWMWMADRCPeakTarget[] =L"WM/WMADRCPeakTarget";
static const WCHAR g_wszWMWMADRCAverageReference[] =L"WM/WMADRCAverageReference";
static const WCHAR g_wszWMWMADRCAverageTarget[] =L"WM/WMADRCAverageTarget";
////////////////////////////////////////////////////////////////
//
// Attributes introduced in V10
//
static const WCHAR g_wszWMStreamTypeInfo[] = L"WM/StreamTypeInfo";
static const WCHAR g_wszWMPeakBitrate[] = L"WM/PeakBitrate";
static const WCHAR g_wszWMASFPacketCount[] = L"WM/ASFPacketCount";
static const WCHAR g_wszWMASFSecurityObjectsSize[] = L"WM/ASFSecurityObjectsSize";
static const WCHAR g_wszWMSharedUserRating[] = L"WM/SharedUserRating";
static const WCHAR g_wszWMSubTitleDescription[] = L"WM/SubTitleDescription";
static const WCHAR g_wszWMMediaCredits[] = L"WM/MediaCredits";
static const WCHAR g_wszWMParentalRatingReason[] = L"WM/ParentalRatingReason";
static const WCHAR g_wszWMOriginalReleaseTime[] = L"WM/OriginalReleaseTime";
static const WCHAR g_wszWMMediaStationCallSign[] = L"WM/MediaStationCallSign";
static const WCHAR g_wszWMMediaStationName[] = L"WM/MediaStationName";
static const WCHAR g_wszWMMediaNetworkAffiliation[] = L"WM/MediaNetworkAffiliation";
static const WCHAR g_wszWMMediaOriginalChannel[] = L"WM/MediaOriginalChannel";
static const WCHAR g_wszWMMediaOriginalBroadcastDateTime[] = L"WM/MediaOriginalBroadcastDateTime";
static const WCHAR g_wszWMMediaIsStereo[] = L"WM/MediaIsStereo";
static const WCHAR g_wszWMVideoClosedCaptioning[] = L"WM/VideoClosedCaptioning";
static const WCHAR g_wszWMMediaIsRepeat[] = L"WM/MediaIsRepeat";
static const WCHAR g_wszWMMediaIsLive[] = L"WM/MediaIsLive";
static const WCHAR g_wszWMMediaIsTape[] = L"WM/MediaIsTape";
static const WCHAR g_wszWMMediaIsDelay[] = L"WM/MediaIsDelay";
static const WCHAR g_wszWMMediaIsSubtitled[] = L"WM/MediaIsSubtitled";
static const WCHAR g_wszWMMediaIsPremiere[] = L"WM/MediaIsPremiere";
static const WCHAR g_wszWMMediaIsFinale[] = L"WM/MediaIsFinale";
static const WCHAR g_wszWMMediaIsSAP[] = L"WM/MediaIsSAP";
static const WCHAR g_wszWMProviderCopyright[] = L"WM/ProviderCopyright";
////////////////////////////////////////////////////////////////
//
// Attributes introduced in V11
//
static const WCHAR g_wszWMISAN[] = L"WM/ISAN";
static const WCHAR g_wszWMADID[] = L"WM/ADID";
static const WCHAR g_wszWMWMShadowFileSourceFileType[] = L"WM/WMShadowFileSourceFileType";
static const WCHAR g_wszWMWMShadowFileSourceDRMType[] = L"WM/WMShadowFileSourceDRMType";
static const WCHAR g_wszWMWMCPDistributor[] =L"WM/WMCPDistributor";
static const WCHAR g_wszWMWMCPDistributorID[] =L"WM/WMCPDistributorID";
static const WCHAR g_wszWMSeasonNumber[] =L"WM/SeasonNumber";
static const WCHAR g_wszWMEpisodeNumber[] =L"WM/EpisodeNumber";
////////////////////////////////////////////////////////////////
//
// These are setting names for use in Get/SetOutputSetting
//
static const WCHAR g_wszEarlyDataDelivery[] =L"EarlyDataDelivery";
static const WCHAR g_wszJustInTimeDecode[] =L"JustInTimeDecode";
static const WCHAR g_wszSingleOutputBuffer[] =L"SingleOutputBuffer";
static const WCHAR g_wszSoftwareScaling[] =L"SoftwareScaling";
static const WCHAR g_wszDeliverOnReceive[] =L"DeliverOnReceive";
static const WCHAR g_wszScrambledAudio[] =L"ScrambledAudio";
static const WCHAR g_wszDedicatedDeliveryThread[] =L"DedicatedDeliveryThread";
static const WCHAR g_wszEnableDiscreteOutput[] = L"EnableDiscreteOutput";
static const WCHAR g_wszSpeakerConfig[] = L"SpeakerConfig";
static const WCHAR g_wszDynamicRangeControl[] = L"DynamicRangeControl";
static const WCHAR g_wszAllowInterlacedOutput[] = L"AllowInterlacedOutput";
static const WCHAR g_wszVideoSampleDurations[] =L"VideoSampleDurations";
static const WCHAR g_wszStreamLanguage[] =L"StreamLanguage";
static const WCHAR g_wszEnableWMAProSPDIFOutput[] = L"EnableWMAProSPDIFOutput";

////////////////////////////////////////////////////////////////
//
// These are setting names for use in Get/SetInputSetting
//
static const WCHAR g_wszDeinterlaceMode[] =L"DeinterlaceMode";
static const WCHAR g_wszInitialPatternForInverseTelecine[] =L"InitialPatternForInverseTelecine";
static const WCHAR g_wszJPEGCompressionQuality[] =L"JPEGCompressionQuality";
static const WCHAR g_wszWatermarkCLSID[] =L"WatermarkCLSID";
static const WCHAR g_wszWatermarkConfig[] =L"WatermarkConfig";
static const WCHAR g_wszInterlacedCoding[] =L"InterlacedCoding";
static const WCHAR g_wszFixedFrameRate[] =L"FixedFrameRate";

////////////////////////////////////////////////////////////////
//
// All known IWMPropertyVault property names
//
// g_wszOriginalSourceFormatTag is obsolete and has been superceded by g_wszOriginalWaveFormat
static const WCHAR g_wszOriginalSourceFormatTag[] =L"_SOURCEFORMATTAG";
static const WCHAR g_wszOriginalWaveFormat[] =L"_ORIGINALWAVEFORMAT";
static const WCHAR g_wszEDL[] =L"_EDL";
static const WCHAR g_wszComplexity[] =L"_COMPLEXITYEX";
static const WCHAR g_wszDecoderComplexityRequested[] =L"_DECODERCOMPLEXITYPROFILE";

////////////////////////////////////////////////////////////////
//
// All known IWMIStreamProps property names
//
static const WCHAR g_wszReloadIndexOnSeek[] =L"ReloadIndexOnSeek";
static const WCHAR g_wszStreamNumIndexObjects[] =L"StreamNumIndexObjects";
static const WCHAR g_wszFailSeekOnError[] =L"FailSeekOnError";
static const WCHAR g_wszPermitSeeksBeyondEndOfStream[] =L"PermitSeeksBeyondEndOfStream";
static const WCHAR g_wszUsePacketAtSeekPoint[] =L"UsePacketAtSeekPoint";
static const WCHAR g_wszSourceBufferTime[] =L"SourceBufferTime";
static const WCHAR g_wszSourceMaxBytesAtOnce[] =L"SourceMaxBytesAtOnce";

////////////////////////////////////////////////////////////////
//
// VBR encoding settings
//
static const WCHAR g_wszVBREnabled[] =L"_VBRENABLED";
static const WCHAR g_wszVBRQuality[] =L"_VBRQUALITY";
static const WCHAR g_wszVBRBitrateMax[] =L"_RMAX";
static const WCHAR g_wszVBRBufferWindowMax[] =L"_BMAX";

////////////////////////////////////////////////////////////////
//
// VBR Video settings
//
static const WCHAR g_wszVBRPeak[] = L"VBR Peak";
static const WCHAR g_wszBufferAverage[] = L"Buffer Average";

////////////////////////////////////////////////////////////////
//
// Codec encoding complexity settings
//
// g_wszComplexity should be used to set desired encoding complexity on the
// stream's IWMPropertyVault (see above for definition) 
// The below settings can be queried from IWMCodecInfo3::GetCodecProp()
//
static const WCHAR g_wszComplexityMax[] =L"_COMPLEXITYEXMAX";
static const WCHAR g_wszComplexityOffline[] =L"_COMPLEXITYEXOFFLINE";
static const WCHAR g_wszComplexityLive[] =L"_COMPLEXITYEXLIVE";
static const WCHAR g_wszIsVBRSupported[] =L"_ISVBRSUPPORTED";
////////////////////////////////////////////////////////////////
//
// Codec enumeration settings
//
// g_wszVBREnabled can be used as a codec enumeration setting (see above for definition)
static const WCHAR g_wszNumPasses[] = L"_PASSESUSED";

////////////////////////////////////////////////////////////////
//
// These are WMA Voice V9 attribute names and values
//
static const WCHAR g_wszMusicSpeechClassMode[] = L"MusicSpeechClassMode";
static const WCHAR g_wszMusicClassMode[] = L"MusicClassMode";
static const WCHAR g_wszSpeechClassMode[] = L"SpeechClassMode";
static const WCHAR g_wszMixedClassMode[] = L"MixedClassMode";

////////////////////////////////////////////////////////////////
//
// The WMA Voice V9 supports the following format property.
//
static const WCHAR g_wszSpeechCaps[] = L"SpeechFormatCap";

////////////////////////////////////////////////////////////////
//
// Multi-channel WMA properties
//
static const WCHAR g_wszPeakValue[] = L"PeakValue";
static const WCHAR g_wszAverageLevel[] = L"AverageLevel";
static const WCHAR g_wszFold6To2Channels3[] = L"Fold6To2Channels3";
static const WCHAR g_wszFoldToChannelsTemplate[] = L"Fold%luTo%luChannels%lu";

////////////////////////////////////////////////////////////////
//
// Complexity profile description strings
//
static const WCHAR g_wszDeviceConformanceTemplate[] = L"DeviceConformanceTemplate";

////////////////////////////////////////////////////////////////
//
// Frame interpolation on video decode
//
static const WCHAR g_wszEnableFrameInterpolation[] =L"EnableFrameInterpolation";

////////////////////////////////////////////////////////////////
//
// Needs previous sample for Delta frame on video decode
//
static const WCHAR g_wszNeedsPreviousSample[] =L"NeedsPreviousSample";

////////////////////////////////////////////////////////////////
//
// Corresponds to iTunes Compilation flag
//
static const WCHAR g_wszWMIsCompilation[] = L"WM/IsCompilation";

////////////////////////////////////////////////////////////////
//
// Flags that can be passed into the Start method of IWMReader
//
#define WM_START_CURRENTPOSITION     ( ( QWORD )-1 )

#define WM_BACKUP_OVERWRITE    ((DWORD) 0x00000001)
#define WM_RESTORE_INDIVIDUALIZE    ((DWORD) 0x00000002)
#define WAVE_FORMAT_DRM            0x0009
typedef LPCWSTR LPCWSTR_WMSDK_TYPE_SAFE;

#ifdef WMSDK_TYPE_SAFE
#define LPCWSTR_WMSDK_TYPE_SAFE LPCWSTR
#else
#define LPCWSTR_WMSDK_TYPE_SAFE LPWSTR
#endif

enum __MIDL___MIDL_itf_wmsdkidl_0000_0000_0001
    {
        WEBSTREAM_SAMPLE_TYPE_FILE	= 0x1,
        WEBSTREAM_SAMPLE_TYPE_RENDER	= 0x2
    } ;

enum __MIDL___MIDL_itf_wmsdkidl_0000_0000_0002
    {
        WM_SF_CLEANPOINT	= 0x1,
        WM_SF_DISCONTINUITY	= 0x2,
        WM_SF_DATALOSS	= 0x4
    } ;

enum __MIDL___MIDL_itf_wmsdkidl_0000_0000_0003
    {
        WM_SFEX_NOTASYNCPOINT	= 0x2,
        WM_SFEX_DATALOSS	= 0x4
    } ;
typedef 
enum WMT_STATUS
    {
        WMT_ERROR	= 0,
        WMT_OPENED	= 1,
        WMT_BUFFERING_START	= 2,
        WMT_BUFFERING_STOP	= 3,
        WMT_EOF	= 4,
        WMT_END_OF_FILE	= 4,
        WMT_END_OF_SEGMENT	= 5,
        WMT_END_OF_STREAMING	= 6,
        WMT_LOCATING	= 7,
        WMT_CONNECTING	= 8,
        WMT_NO_RIGHTS	= 9,
        WMT_MISSING_CODEC	= 10,
        WMT_STARTED	= 11,
        WMT_STOPPED	= 12,
        WMT_CLOSED	= 13,
        WMT_STRIDING	= 14,
        WMT_TIMER	= 15,
        WMT_INDEX_PROGRESS	= 16,
        WMT_SAVEAS_START	= 17,
        WMT_SAVEAS_STOP	= 18,
        WMT_NEW_SOURCEFLAGS	= 19,
        WMT_NEW_METADATA	= 20,
        WMT_BACKUPRESTORE_BEGIN	= 21,
        WMT_SOURCE_SWITCH	= 22,
        WMT_ACQUIRE_LICENSE	= 23,
        WMT_INDIVIDUALIZE	= 24,
        WMT_NEEDS_INDIVIDUALIZATION	= 25,
        WMT_NO_RIGHTS_EX	= 26,
        WMT_BACKUPRESTORE_END	= 27,
        WMT_BACKUPRESTORE_CONNECTING	= 28,
        WMT_BACKUPRESTORE_DISCONNECTING	= 29,
        WMT_ERROR_WITHURL	= 30,
        WMT_RESTRICTED_LICENSE	= 31,
        WMT_CLIENT_CONNECT	= 32,
        WMT_CLIENT_DISCONNECT	= 33,
        WMT_NATIVE_OUTPUT_PROPS_CHANGED	= 34,
        WMT_RECONNECT_START	= 35,
        WMT_RECONNECT_END	= 36,
        WMT_CLIENT_CONNECT_EX	= 37,
        WMT_CLIENT_DISCONNECT_EX	= 38,
        WMT_SET_FEC_SPAN	= 39,
        WMT_PREROLL_READY	= 40,
        WMT_PREROLL_COMPLETE	= 41,
        WMT_CLIENT_PROPERTIES	= 42,
        WMT_LICENSEURL_SIGNATURE_STATE	= 43,
        WMT_INIT_PLAYLIST_BURN	= 44,
        WMT_TRANSCRYPTOR_INIT	= 45,
        WMT_TRANSCRYPTOR_SEEKED	= 46,
        WMT_TRANSCRYPTOR_READ	= 47,
        WMT_TRANSCRYPTOR_CLOSED	= 48,
        WMT_PROXIMITY_RESULT	= 49,
        WMT_PROXIMITY_COMPLETED	= 50,
        WMT_CONTENT_ENABLER	= 51
    } 	WMT_STATUS;

typedef 
enum WMT_STREAM_SELECTION
    {
        WMT_OFF	= 0,
        WMT_CLEANPOINT_ONLY	= 1,
        WMT_ON	= 2
    } 	WMT_STREAM_SELECTION;

typedef 
enum WMT_IMAGE_TYPE
    {
        WMT_IT_NONE	= 0,
        WMT_IT_BITMAP	= 1,
        WMT_IT_JPEG	= 2,
        WMT_IT_GIF	= 3
    } 	WMT_IMAGE_TYPE;

typedef 
enum WMT_ATTR_DATATYPE
    {
        WMT_TYPE_DWORD	= 0,
        WMT_TYPE_STRING	= 1,
        WMT_TYPE_BINARY	= 2,
        WMT_TYPE_BOOL	= 3,
        WMT_TYPE_QWORD	= 4,
        WMT_TYPE_WORD	= 5,
        WMT_TYPE_GUID	= 6
    } 	WMT_ATTR_DATATYPE;

typedef 
enum WMT_ATTR_IMAGETYPE
    {
        WMT_IMAGETYPE_BITMAP	= 1,
        WMT_IMAGETYPE_JPEG	= 2,
        WMT_IMAGETYPE_GIF	= 3
    } 	WMT_ATTR_IMAGETYPE;

typedef 
enum WMT_VERSION
    {
        WMT_VER_4_0	= 0x40000,
        WMT_VER_7_0	= 0x70000,
        WMT_VER_8_0	= 0x80000,
        WMT_VER_9_0	= 0x90000
    } 	WMT_VERSION;

typedef 
enum tagWMT_STORAGE_FORMAT
    {
        WMT_Storage_Format_MP3	= 0,
        WMT_Storage_Format_V1	= ( WMT_Storage_Format_MP3 + 1 ) 
    } 	WMT_STORAGE_FORMAT;

typedef 
enum tagWMT_DRMLA_TRUST
    {
        WMT_DRMLA_UNTRUSTED	= 0,
        WMT_DRMLA_TRUSTED	= ( WMT_DRMLA_UNTRUSTED + 1 ) ,
        WMT_DRMLA_TAMPERED	= ( WMT_DRMLA_TRUSTED + 1 ) 
    } 	WMT_DRMLA_TRUST;

typedef 
enum tagWMT_TRANSPORT_TYPE
    {
        WMT_Transport_Type_Unreliable	= 0,
        WMT_Transport_Type_Reliable	= ( WMT_Transport_Type_Unreliable + 1 ) 
    } 	WMT_TRANSPORT_TYPE;

typedef 
enum WMT_NET_PROTOCOL
    {
        WMT_PROTOCOL_HTTP	= 0
    } 	WMT_NET_PROTOCOL;

typedef 
enum WMT_PLAY_MODE
    {
        WMT_PLAY_MODE_AUTOSELECT	= 0,
        WMT_PLAY_MODE_LOCAL	= 1,
        WMT_PLAY_MODE_DOWNLOAD	= 2,
        WMT_PLAY_MODE_STREAMING	= 3
    } 	WMT_PLAY_MODE;

typedef 
enum WMT_PROXY_SETTINGS
    {
        WMT_PROXY_SETTING_NONE	= 0,
        WMT_PROXY_SETTING_MANUAL	= 1,
        WMT_PROXY_SETTING_AUTO	= 2,
        WMT_PROXY_SETTING_BROWSER	= 3,
        WMT_PROXY_SETTING_MAX	= ( WMT_PROXY_SETTING_BROWSER + 1 ) 
    } 	WMT_PROXY_SETTINGS;

typedef 
enum WMT_CODEC_INFO_TYPE
    {
        WMT_CODECINFO_AUDIO	= 0,
        WMT_CODECINFO_VIDEO	= 1,
        WMT_CODECINFO_UNKNOWN	= 0xffffffff
    } 	WMT_CODEC_INFO_TYPE;


enum __MIDL___MIDL_itf_wmsdkidl_0000_0000_0004
    {
        WM_DM_NOTINTERLACED	= 0,
        WM_DM_DEINTERLACE_NORMAL	= 1,
        WM_DM_DEINTERLACE_HALFSIZE	= 2,
        WM_DM_DEINTERLACE_HALFSIZEDOUBLERATE	= 3,
        WM_DM_DEINTERLACE_INVERSETELECINE	= 4,
        WM_DM_DEINTERLACE_VERTICALHALFSIZEDOUBLERATE	= 5
    } ;

enum __MIDL___MIDL_itf_wmsdkidl_0000_0000_0005
    {
        WM_DM_IT_DISABLE_COHERENT_MODE	= 0,
        WM_DM_IT_FIRST_FRAME_IN_CLIP_IS_AA_TOP	= 1,
        WM_DM_IT_FIRST_FRAME_IN_CLIP_IS_BB_TOP	= 2,
        WM_DM_IT_FIRST_FRAME_IN_CLIP_IS_BC_TOP	= 3,
        WM_DM_IT_FIRST_FRAME_IN_CLIP_IS_CD_TOP	= 4,
        WM_DM_IT_FIRST_FRAME_IN_CLIP_IS_DD_TOP	= 5,
        WM_DM_IT_FIRST_FRAME_IN_CLIP_IS_AA_BOTTOM	= 6,
        WM_DM_IT_FIRST_FRAME_IN_CLIP_IS_BB_BOTTOM	= 7,
        WM_DM_IT_FIRST_FRAME_IN_CLIP_IS_BC_BOTTOM	= 8,
        WM_DM_IT_FIRST_FRAME_IN_CLIP_IS_CD_BOTTOM	= 9,
        WM_DM_IT_FIRST_FRAME_IN_CLIP_IS_DD_BOTTOM	= 10
    } ;
typedef 
enum tagWMT_OFFSET_FORMAT
    {
        WMT_OFFSET_FORMAT_100NS	= 0,
        WMT_OFFSET_FORMAT_FRAME_NUMBERS	= ( WMT_OFFSET_FORMAT_100NS + 1 ) ,
        WMT_OFFSET_FORMAT_PLAYLIST_OFFSET	= ( WMT_OFFSET_FORMAT_FRAME_NUMBERS + 1 ) ,
        WMT_OFFSET_FORMAT_TIMECODE	= ( WMT_OFFSET_FORMAT_PLAYLIST_OFFSET + 1 ) ,
        WMT_OFFSET_FORMAT_100NS_APPROXIMATE	= ( WMT_OFFSET_FORMAT_TIMECODE + 1 ) 
    } 	WMT_OFFSET_FORMAT;

typedef 
enum tagWMT_INDEXER_TYPE
    {
        WMT_IT_PRESENTATION_TIME	= 0,
        WMT_IT_FRAME_NUMBERS	= ( WMT_IT_PRESENTATION_TIME + 1 ) ,
        WMT_IT_TIMECODE	= ( WMT_IT_FRAME_NUMBERS + 1 ) 
    } 	WMT_INDEXER_TYPE;

typedef 
enum tagWMT_INDEX_TYPE
    {
        WMT_IT_NEAREST_DATA_UNIT	= 1,
        WMT_IT_NEAREST_OBJECT	= ( WMT_IT_NEAREST_DATA_UNIT + 1 ) ,
        WMT_IT_NEAREST_CLEAN_POINT	= ( WMT_IT_NEAREST_OBJECT + 1 ) 
    } 	WMT_INDEX_TYPE;

typedef 
enum tagWMT_FILESINK_MODE
    {
        WMT_FM_SINGLE_BUFFERS	= 0x1,
        WMT_FM_FILESINK_DATA_UNITS	= 0x2,
        WMT_FM_FILESINK_UNBUFFERED	= 0x4
    } 	WMT_FILESINK_MODE;

typedef 
enum tagWMT_MUSICSPEECH_CLASS_MODE
    {
        WMT_MS_CLASS_MUSIC	= 0,
        WMT_MS_CLASS_SPEECH	= 1,
        WMT_MS_CLASS_MIXED	= 2
    } 	WMT_MUSICSPEECH_CLASS_MODE;

typedef 
enum tagWMT_WATERMARK_ENTRY_TYPE
    {
        WMT_WMETYPE_AUDIO	= 1,
        WMT_WMETYPE_VIDEO	= 2
    } 	WMT_WATERMARK_ENTRY_TYPE;


enum __MIDL___MIDL_itf_wmsdkidl_0000_0000_0006
    {
        WM_PLAYBACK_DRC_HIGH	= 0,
        WM_PLAYBACK_DRC_MEDIUM	= ( WM_PLAYBACK_DRC_HIGH + 1 ) ,
        WM_PLAYBACK_DRC_LOW	= ( WM_PLAYBACK_DRC_MEDIUM + 1 ) 
    } ;

enum __MIDL___MIDL_itf_wmsdkidl_0000_0000_0007
    {
        WMT_TIMECODE_FRAMERATE_30	= 0,
        WMT_TIMECODE_FRAMERATE_30DROP	= ( WMT_TIMECODE_FRAMERATE_30 + 1 ) ,
        WMT_TIMECODE_FRAMERATE_25	= ( WMT_TIMECODE_FRAMERATE_30DROP + 1 ) ,
        WMT_TIMECODE_FRAMERATE_24	= ( WMT_TIMECODE_FRAMERATE_25 + 1 ) 
    } ;
typedef 
enum WMT_CREDENTIAL_FLAGS
    {
        WMT_CREDENTIAL_SAVE	= 0x1,
        WMT_CREDENTIAL_DONT_CACHE	= 0x2,
        WMT_CREDENTIAL_CLEAR_TEXT	= 0x4,
        WMT_CREDENTIAL_PROXY	= 0x8,
        WMT_CREDENTIAL_ENCRYPT	= 0x10
    } 	WMT_CREDENTIAL_FLAGS;

typedef 
enum WM_AETYPE
    {
        WM_AETYPE_INCLUDE	= 0x69,
        WM_AETYPE_EXCLUDE	= 0x65
    } 	WM_AETYPE;

typedef 
enum WMT_RIGHTS
    {
        WMT_RIGHT_PLAYBACK	= 0x1,
        WMT_RIGHT_COPY_TO_NON_SDMI_DEVICE	= 0x2,
        WMT_RIGHT_COPY_TO_CD	= 0x8,
        WMT_RIGHT_COPY_TO_SDMI_DEVICE	= 0x10,
        WMT_RIGHT_ONE_TIME	= 0x20,
        WMT_RIGHT_SAVE_STREAM_PROTECTED	= 0x40,
        WMT_RIGHT_COPY	= 0x80,
        WMT_RIGHT_COLLABORATIVE_PLAY	= 0x100,
        WMT_RIGHT_SDMI_TRIGGER	= 0x10000,
        WMT_RIGHT_SDMI_NOMORECOPIES	= 0x20000
    } 	WMT_RIGHTS;


#pragma pack(push)

#pragma pack(2)
typedef struct _WMStreamPrioritizationRecord
    {
    WORD wStreamNumber;
    BOOL fMandatory;
    } 	WM_STREAM_PRIORITY_RECORD;


#pragma pack(pop)
typedef struct _WMWriterStatistics
    {
    QWORD qwSampleCount;
    QWORD qwByteCount;
    QWORD qwDroppedSampleCount;
    QWORD qwDroppedByteCount;
    DWORD dwCurrentBitrate;
    DWORD dwAverageBitrate;
    DWORD dwExpectedBitrate;
    DWORD dwCurrentSampleRate;
    DWORD dwAverageSampleRate;
    DWORD dwExpectedSampleRate;
    } 	WM_WRITER_STATISTICS;

typedef struct _WMWriterStatisticsEx
    {
    DWORD dwBitratePlusOverhead;
    DWORD dwCurrentSampleDropRateInQueue;
    DWORD dwCurrentSampleDropRateInCodec;
    DWORD dwCurrentSampleDropRateInMultiplexer;
    DWORD dwTotalSampleDropsInQueue;
    DWORD dwTotalSampleDropsInCodec;
    DWORD dwTotalSampleDropsInMultiplexer;
    } 	WM_WRITER_STATISTICS_EX;

typedef struct _WMReaderStatistics
    {
    DWORD cbSize;
    DWORD dwBandwidth;
    DWORD cPacketsReceived;
    DWORD cPacketsRecovered;
    DWORD cPacketsLost;
    WORD wQuality;
    } 	WM_READER_STATISTICS;

typedef struct _WMReaderClientInfo
    {
    DWORD cbSize;
    WCHAR *wszLang;
    WCHAR *wszBrowserUserAgent;
    WCHAR *wszBrowserWebPage;
    QWORD qwReserved;
    LPARAM *pReserved;
    WCHAR *wszHostExe;
    QWORD qwHostVersion;
    WCHAR *wszPlayerUserAgent;
    } 	WM_READER_CLIENTINFO;

typedef struct _WMClientProperties
    {
    DWORD dwIPAddress;
    DWORD dwPort;
    } 	WM_CLIENT_PROPERTIES;

typedef struct _WMClientPropertiesEx
    {
    DWORD cbSize;
    LPCWSTR pwszIPAddress;
    LPCWSTR pwszPort;
    LPCWSTR pwszDNSName;
    } 	WM_CLIENT_PROPERTIES_EX;

typedef struct _WMPortNumberRange
    {
    WORD wPortBegin;
    WORD wPortEnd;
    } 	WM_PORT_NUMBER_RANGE;

typedef struct _WMT_BUFFER_SEGMENT
    {
    INSSBuffer *pBuffer;
    DWORD cbOffset;
    DWORD cbLength;
    } 	WMT_BUFFER_SEGMENT;

typedef struct _WMT_PAYLOAD_FRAGMENT
    {
    DWORD dwPayloadIndex;
    WMT_BUFFER_SEGMENT segmentData;
    } 	WMT_PAYLOAD_FRAGMENT;

typedef struct _WMT_FILESINK_DATA_UNIT
    {
    WMT_BUFFER_SEGMENT packetHeaderBuffer;
    DWORD cPayloads;
    WMT_BUFFER_SEGMENT *pPayloadHeaderBuffers;
    DWORD cPayloadDataFragments;
    WMT_PAYLOAD_FRAGMENT *pPayloadDataFragments;
    } 	WMT_FILESINK_DATA_UNIT;

typedef struct _WMT_WEBSTREAM_FORMAT
    {
    WORD cbSize;
    WORD cbSampleHeaderFixedData;
    WORD wVersion;
    WORD wReserved;
    } 	WMT_WEBSTREAM_FORMAT;

typedef struct _WMT_WEBSTREAM_SAMPLE_HEADER
    {
    WORD cbLength;
    WORD wPart;
    WORD cTotalParts;
    WORD wSampleType;
    WCHAR wszURL[ 1 ];
    } 	WMT_WEBSTREAM_SAMPLE_HEADER;

typedef struct _WMAddressAccessEntry
    {
    DWORD dwIPAddress;
    DWORD dwMask;
    } 	WM_ADDRESS_ACCESSENTRY;


#pragma pack(push)

#pragma pack(1)
typedef struct _WMPicture
    {
    LPWSTR pwszMIMEType;
    BYTE bPictureType;
    LPWSTR pwszDescription;
    DWORD dwDataLen;
    BYTE *pbData;
    } 	WM_PICTURE;

typedef struct _WMSynchronisedLyrics
    {
    BYTE bTimeStampFormat;
    BYTE bContentType;
    LPWSTR pwszContentDescriptor;
    DWORD dwLyricsLen;
    BYTE *pbLyrics;
    } 	WM_SYNCHRONISED_LYRICS;

typedef struct _WMUserWebURL
    {
    LPWSTR pwszDescription;
    LPWSTR pwszURL;
    } 	WM_USER_WEB_URL;

typedef struct _WMUserText
    {
    LPWSTR pwszDescription;
    LPWSTR pwszText;
    } 	WM_USER_TEXT;

typedef struct _WMLeakyBucketPair
    {
    DWORD dwBitrate;
    DWORD msBufferWindow;
    } 	WM_LEAKY_BUCKET_PAIR;

typedef struct _WMStreamTypeInfo
    {
    GUID guidMajorType;
    DWORD cbFormat;
    } 	WM_STREAM_TYPE_INFO;


#pragma pack(pop)
typedef struct __WMT_WATERMARK_ENTRY
    {
    WMT_WATERMARK_ENTRY_TYPE wmetType;
    CLSID clsid;
    UINT cbDisplayName;
    LPWSTR pwszDisplayName;
    } 	WMT_WATERMARK_ENTRY;

#define WMT_VIDEOIMAGE_SAMPLE_INPUT_FRAME      1 // sample has input frame 
#define WMT_VIDEOIMAGE_SAMPLE_OUTPUT_FRAME     2 // sample produces output frame 
#define WMT_VIDEOIMAGE_SAMPLE_USES_CURRENT_INPUT_FRAME  4 
#define WMT_VIDEOIMAGE_SAMPLE_USES_PREVIOUS_INPUT_FRAME 8 
#define WMT_VIDEOIMAGE_SAMPLE_MOTION       1 // acef used (includes resizing) 
#define WMT_VIDEOIMAGE_SAMPLE_ROTATION     2 // bd also used (not valid without acef) 
#define WMT_VIDEOIMAGE_SAMPLE_BLENDING     4 // BlendCoef1 used 
#define WMT_VIDEOIMAGE_SAMPLE_ADV_BLENDING 8 // BlendCoef2 also used (not valid without BlendCoef1) 
#define WMT_VIDEOIMAGE_INTEGER_DENOMINATOR 65536L 
#define WMT_VIDEOIMAGE_MAGIC_NUMBER 0x1d4a45f2 
#define WMT_VIDEOIMAGE_MAGIC_NUMBER_2 0x1d4a45f3 
typedef struct __WMT_VIDEOIMAGE_SAMPLE
    {
    DWORD dwMagic;
    ULONG cbStruct;
    DWORD dwControlFlags;
    DWORD dwInputFlagsCur;
    LONG lCurMotionXtoX;
    LONG lCurMotionYtoX;
    LONG lCurMotionXoffset;
    LONG lCurMotionXtoY;
    LONG lCurMotionYtoY;
    LONG lCurMotionYoffset;
    LONG lCurBlendCoef1;
    LONG lCurBlendCoef2;
    DWORD dwInputFlagsPrev;
    LONG lPrevMotionXtoX;
    LONG lPrevMotionYtoX;
    LONG lPrevMotionXoffset;
    LONG lPrevMotionXtoY;
    LONG lPrevMotionYtoY;
    LONG lPrevMotionYoffset;
    LONG lPrevBlendCoef1;
    LONG lPrevBlendCoef2;
    } 	WMT_VIDEOIMAGE_SAMPLE;

#define WMT_VIDEOIMAGE_TRANSITION_BOW_TIE           11
#define WMT_VIDEOIMAGE_TRANSITION_CIRCLE            12
#define WMT_VIDEOIMAGE_TRANSITION_CROSS_FADE        13
#define WMT_VIDEOIMAGE_TRANSITION_DIAGONAL          14
#define WMT_VIDEOIMAGE_TRANSITION_DIAMOND           15
#define WMT_VIDEOIMAGE_TRANSITION_FADE_TO_COLOR     16
#define WMT_VIDEOIMAGE_TRANSITION_FILLED_V          17
#define WMT_VIDEOIMAGE_TRANSITION_FLIP              18
#define WMT_VIDEOIMAGE_TRANSITION_INSET             19
#define WMT_VIDEOIMAGE_TRANSITION_IRIS              20
#define WMT_VIDEOIMAGE_TRANSITION_PAGE_ROLL         21
#define WMT_VIDEOIMAGE_TRANSITION_RECTANGLE         23
#define WMT_VIDEOIMAGE_TRANSITION_REVEAL            24
#define WMT_VIDEOIMAGE_TRANSITION_SLIDE             27
#define WMT_VIDEOIMAGE_TRANSITION_SPLIT             29
#define WMT_VIDEOIMAGE_TRANSITION_STAR              30
#define WMT_VIDEOIMAGE_TRANSITION_WHEEL             31
typedef struct __WMT_VIDEOIMAGE_SAMPLE2
    {
    DWORD dwMagic;
    DWORD dwStructSize;
    DWORD dwControlFlags;
    DWORD dwViewportWidth;
    DWORD dwViewportHeight;
    DWORD dwCurrImageWidth;
    DWORD dwCurrImageHeight;
    FLOAT fCurrRegionX0;
    FLOAT fCurrRegionY0;
    FLOAT fCurrRegionWidth;
    FLOAT fCurrRegionHeight;
    FLOAT fCurrBlendCoef;
    DWORD dwPrevImageWidth;
    DWORD dwPrevImageHeight;
    FLOAT fPrevRegionX0;
    FLOAT fPrevRegionY0;
    FLOAT fPrevRegionWidth;
    FLOAT fPrevRegionHeight;
    FLOAT fPrevBlendCoef;
    DWORD dwEffectType;
    DWORD dwNumEffectParas;
    FLOAT fEffectPara0;
    FLOAT fEffectPara1;
    FLOAT fEffectPara2;
    FLOAT fEffectPara3;
    FLOAT fEffectPara4;
    BOOL bKeepPrevImage;
    } 	WMT_VIDEOIMAGE_SAMPLE2;

typedef struct _WMMediaType
    {
    GUID majortype;
    GUID subtype;
    BOOL bFixedSizeSamples;
    BOOL bTemporalCompression;
    ULONG lSampleSize;
    GUID formattype;
    IUnknown *pUnk;
    ULONG cbFormat;
    /* [size_is] */ BYTE *pbFormat;
    } 	WM_MEDIA_TYPE;

typedef struct tagWMVIDEOINFOHEADER
{
    //
    // The bit we really want to use.
    //
    RECT rcSource;

    //
    // Where the video should go.
    //
    RECT rcTarget;

    //
    // Approximate bit data rate.
    //
    DWORD dwBitRate;

    //
    // Bit error rate for this stream.
    //
    DWORD dwBitErrorRate;

    //
    // Average time per frame (100ns units).
    //
    LONGLONG AvgTimePerFrame;

    BITMAPINFOHEADER bmiHeader;
} WMVIDEOINFOHEADER;
typedef struct tagWMVIDEOINFOHEADER2
{
    //
    // The bit we really want to use.
    //
    RECT rcSource;

    //
    // Where the video should go.
    //
    RECT rcTarget;

    //
    // Approximate bit data rate.
    //
    DWORD dwBitRate;

    //
    // Bit error rate for this stream.
    //
    DWORD dwBitErrorRate;

    //
    // Average time per frame (100ns units).
    //
    LONGLONG AvgTimePerFrame;

    //
    // Use AMINTERLACE_* defines. Reject connection if undefined bits are not 0.
    //
    DWORD dwInterlaceFlags;

    //
    // use AMCOPYPROTECT_* defines. Reject connection if undefined bits are not 0.
    //
    DWORD dwCopyProtectFlags;

    //
    // X dimension of picture aspect ratio, e.g. 16 for 16x9 display.
    //
    DWORD dwPictAspectRatioX;

    //
    // Y dimension of picture aspect ratio, e.g.  9 for 16x9 display.
    //
    DWORD dwPictAspectRatioY;

    //
    // Must be 0; reject connection otherwise.
    //
    DWORD dwReserved1;

    //
    // Must be 0; reject connection otherwise.
    //
    DWORD dwReserved2;

    BITMAPINFOHEADER bmiHeader;
} WMVIDEOINFOHEADER2;
typedef struct tagWMMPEG2VIDEOINFO
{
    //
    // Video info header2.
    //
    WMVIDEOINFOHEADER2 hdr;

    //
    // Not used for DVD.
    //
    DWORD dwStartTimeCode;

    //
    // Is 0 for DVD (no sequence header).
    //
    DWORD cbSequenceHeader;

    //
    // Use enum MPEG2Profile.
    //
    DWORD dwProfile;

    //
    // Use enum MPEG2Level.
    //
    DWORD dwLevel;

    //
    // Use AMMPEG2_* defines.  Reject connection if undefined bits are not 0.
    //
    DWORD dwFlags;

    //
    // Sequence header.
    //
    DWORD dwSequenceHeader[1];

} WMMPEG2VIDEOINFO;
typedef struct tagWMSCRIPTFORMAT
{
    GUID    scriptType; 
} WMSCRIPTFORMAT;
// 00000000-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_Base 
EXTERN_GUID(WMMEDIASUBTYPE_Base, 
0x00000000, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 73646976-0000-0010-8000-00AA00389B71  'vids' == WMMEDIATYPE_Video 
EXTERN_GUID(WMMEDIATYPE_Video, 
0x73646976, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71); 
// e436eb78-524f-11ce-9f53-0020af0ba770            MEDIASUBTYPE_RGB1 
EXTERN_GUID(WMMEDIASUBTYPE_RGB1, 
0xe436eb78, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70); 
// e436eb79-524f-11ce-9f53-0020af0ba770            MEDIASUBTYPE_RGB4 
EXTERN_GUID(WMMEDIASUBTYPE_RGB4, 
0xe436eb79, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70); 
// e436eb7a-524f-11ce-9f53-0020af0ba770            MEDIASUBTYPE_RGB8 
EXTERN_GUID(WMMEDIASUBTYPE_RGB8, 
0xe436eb7a, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70); 
// e436eb7b-524f-11ce-9f53-0020af0ba770            MEDIASUBTYPE_RGB565 
EXTERN_GUID(WMMEDIASUBTYPE_RGB565, 
0xe436eb7b, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70); 
// e436eb7c-524f-11ce-9f53-0020af0ba770            MEDIASUBTYPE_RGB555 
EXTERN_GUID(WMMEDIASUBTYPE_RGB555, 
0xe436eb7c, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70); 
// e436eb7d-524f-11ce-9f53-0020af0ba770            MEDIASUBTYPE_RGB24 
EXTERN_GUID(WMMEDIASUBTYPE_RGB24, 
0xe436eb7d, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70); 
// e436eb7e-524f-11ce-9f53-0020af0ba770            MEDIASUBTYPE_RGB32 
EXTERN_GUID(WMMEDIASUBTYPE_RGB32, 
0xe436eb7e, 0x524f, 0x11ce, 0x9f, 0x53, 0x00, 0x20, 0xaf, 0x0b, 0xa7, 0x70); 
// 30323449-0000-0010-8000-00AA00389B71  'I420' ==  MEDIASUBTYPE_I420 
EXTERN_GUID(WMMEDIASUBTYPE_I420, 
0x30323449, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71); 
// 56555949-0000-0010-8000-00AA00389B71  'IYUV' ==  MEDIASUBTYPE_IYUV 
EXTERN_GUID(WMMEDIASUBTYPE_IYUV, 
0x56555949, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71); 
// 32315659-0000-0010-8000-00AA00389B71  'YV12' ==  MEDIASUBTYPE_YV12 
EXTERN_GUID(WMMEDIASUBTYPE_YV12, 
0x32315659, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71); 
// 32595559-0000-0010-8000-00AA00389B71  'YUY2' == MEDIASUBTYPE_YUY2 
EXTERN_GUID(WMMEDIASUBTYPE_YUY2, 
0x32595559, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71); 
// 32323450-0000-0010-8000-00AA00389B71  'P422' == MEDIASUBTYPE_P422 
EXTERN_GUID(WMMEDIASUBTYPE_P422, 
0x32323450, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71); 
// 59565955-0000-0010-8000-00AA00389B71  'UYVY' ==  MEDIASUBTYPE_UYVY 
EXTERN_GUID(WMMEDIASUBTYPE_UYVY, 
0x59565955, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71); 
// 55595659-0000-0010-8000-00AA00389B71  'YVYU' == MEDIASUBTYPE_YVYU 
EXTERN_GUID(WMMEDIASUBTYPE_YVYU, 
0x55595659, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71); 
// 39555659-0000-0010-8000-00AA00389B71  'YVU9' == MEDIASUBTYPE_YVU9 
EXTERN_GUID(WMMEDIASUBTYPE_YVU9, 
0x39555659, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71); 
// 1d4a45f2-e5f6-4b44-8388-f0ae5c0e0c37            MEDIASUBTYPE_VIDEOIMAGE 
EXTERN_GUID(WMMEDIASUBTYPE_VIDEOIMAGE,  
0x1d4a45f2, 0xe5f6, 0x4b44, 0x83, 0x88, 0xf0, 0xae, 0x5c, 0x0e, 0x0c, 0x37); 
// 3334504D-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_MP43 
EXTERN_GUID(WMMEDIASUBTYPE_MP43, 
0x3334504D, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 5334504D-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_MP4S 
EXTERN_GUID(WMMEDIASUBTYPE_MP4S, 
0x5334504D, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 3253344D-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_M4S2 
EXTERN_GUID(WMMEDIASUBTYPE_M4S2, 
0x3253344D, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 31564D57-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMV1 
EXTERN_GUID(WMMEDIASUBTYPE_WMV1, 
0x31564D57, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 32564D57-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMV2 
EXTERN_GUID(WMMEDIASUBTYPE_WMV2, 
0x32564D57, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 3153534D-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_MSS1 
EXTERN_GUID(WMMEDIASUBTYPE_MSS1, 
0x3153534D, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// E06D8026-DB46-11CF-B4D1-00805F6CBBEA            WMMEDIASUBTYPE_MPEG2_VIDEO 
EXTERN_GUID(WMMEDIASUBTYPE_MPEG2_VIDEO, 
0xe06d8026, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x5f, 0x6c, 0xbb, 0xea); 
// 73647561-0000-0010-8000-00AA00389B71  'auds' == WMMEDIATYPE_Audio 
EXTERN_GUID(WMMEDIATYPE_Audio, 
0x73647561, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71); 
// 00000001-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_PCM 
EXTERN_GUID(WMMEDIASUBTYPE_PCM, 
0x00000001, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 00000009-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_DRM 
EXTERN_GUID(WMMEDIASUBTYPE_DRM, 
0x00000009, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 00000162-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMAudioV9 
EXTERN_GUID(WMMEDIASUBTYPE_WMAudioV9, 
0x00000162, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 00000163-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMAudio_Lossless 
EXTERN_GUID(WMMEDIASUBTYPE_WMAudio_Lossless, 
0x00000163, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 3253534D-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_MSS2 
EXTERN_GUID(WMMEDIASUBTYPE_MSS2, 
0x3253534D, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 0000000A-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMSP1 
EXTERN_GUID( WMMEDIASUBTYPE_WMSP1, 
0x0000000A,0x0000,0x0010,0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71); 
// 0000000B-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMSP2 
EXTERN_GUID( WMMEDIASUBTYPE_WMSP2, 
0x0000000B,0x0000,0x0010,0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71); 
// 33564D57-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMV3 
EXTERN_GUID(WMMEDIASUBTYPE_WMV3, 
0x33564D57, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 50564D57-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMVP 
EXTERN_GUID(WMMEDIASUBTYPE_WMVP, 
0x50564D57, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 32505657-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WVP2 
EXTERN_GUID(WMMEDIASUBTYPE_WVP2, 
0x32505657, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 41564D57-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMVA 
EXTERN_GUID(WMMEDIASUBTYPE_WMVA, 
0x41564D57, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 31435657-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WVC1 
EXTERN_GUID(WMMEDIASUBTYPE_WVC1, 
0x31435657, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 00000161-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMAudioV8 
EXTERN_GUID(WMMEDIASUBTYPE_WMAudioV8, 
0x00000161, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 00000161-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMAudioV7 
EXTERN_GUID(WMMEDIASUBTYPE_WMAudioV7, 
0x00000161, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 00000161-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_WMAudioV2 
EXTERN_GUID(WMMEDIASUBTYPE_WMAudioV2, 
0x00000161, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 00000130-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_ACELPnet 
EXTERN_GUID(WMMEDIASUBTYPE_ACELPnet, 
0x00000130, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 00000055-0000-0010-8000-00AA00389B71            WMMEDIASUBTYPE_MP3 
EXTERN_GUID(WMMEDIASUBTYPE_MP3, 
0x00000055, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71); 
// 776257D4-C627-41CB-8F81-7AC7FF1C40CC            WMMEDIASUBTYPE_WebStream 
EXTERN_GUID(WMMEDIASUBTYPE_WebStream, 
0x776257d4, 0xc627, 0x41cb, 0x8f, 0x81, 0x7a, 0xc7, 0xff, 0x1c, 0x40, 0xcc); 
// 73636d64-0000-0010-8000-00AA00389B71  'scmd' == WMMEDIATYPE_Script 
EXTERN_GUID(WMMEDIATYPE_Script, 
0x73636d64, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71); 
// 34A50FD8-8AA5-4386-81FE-A0EFE0488E31  'imag' == WMMEDIATYPE_Image 
EXTERN_GUID(WMMEDIATYPE_Image, 
0x34a50fd8, 0x8aa5, 0x4386, 0x81, 0xfe, 0xa0, 0xef, 0xe0, 0x48, 0x8e, 0x31); 
// D9E47579-930E-4427-ADFC-AD80F290E470  'fxfr' == WMMEDIATYPE_FileTransfer 
EXTERN_GUID(WMMEDIATYPE_FileTransfer, 
0xd9e47579, 0x930e, 0x4427, 0xad, 0xfc, 0xad, 0x80, 0xf2, 0x90, 0xe4, 0x70); 
// 9BBA1EA7-5AB2-4829-BA57-0940209BCF3E      'text' == WMMEDIATYPE_Text 
EXTERN_GUID(WMMEDIATYPE_Text, 
0x9bba1ea7, 0x5ab2, 0x4829, 0xba, 0x57, 0x9, 0x40, 0x20, 0x9b, 0xcf, 0x3e); 
// 05589F80-C356-11CE-BF01-00AA0055595A        WMFORMAT_VideoInfo 
EXTERN_GUID(WMFORMAT_VideoInfo, 
0x05589f80, 0xc356, 0x11ce, 0xbf, 0x01, 0x00, 0xaa, 0x00, 0x55, 0x59, 0x5a); 
// E06D80E3-DB46-11CF-B4D1-00805F6CBBEA        WMFORMAT_MPEG2Video 
EXTERN_GUID(WMFORMAT_MPEG2Video, 
0xe06d80e3, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x05f, 0x6c, 0xbb, 0xea); 
// 05589F81-C356-11CE-BF01-00AA0055595A        WMFORMAT_WaveFormatEx 
EXTERN_GUID(WMFORMAT_WaveFormatEx, 
0x05589f81, 0xc356, 0x11ce, 0xbf, 0x01, 0x00, 0xaa, 0x00, 0x55, 0x59, 0x5a); 
// 5C8510F2-DEBE-4CA7-BBA5-F07A104F8DFF        WMFORMAT_Script 
EXTERN_GUID(WMFORMAT_Script, 
0x5c8510f2, 0xdebe, 0x4ca7, 0xbb, 0xa5, 0xf0, 0x7a, 0x10, 0x4f, 0x8d, 0xff); 
// DA1E6B13-8359-4050-B398-388E965BF00C        WMFORMAT_WebStream 
EXTERN_GUID(WMFORMAT_WebStream, 
0xda1e6b13, 0x8359, 0x4050, 0xb3, 0x98, 0x38, 0x8e, 0x96, 0x5b, 0xf0, 0x0c); 
// 82F38A70-C29F-11D1-97AD-00A0C95EA850        WMSCRIPTTYPE_TwoStrings 
EXTERN_GUID( WMSCRIPTTYPE_TwoStrings, 
0x82f38a70,0xc29f,0x11d1,0x97,0xad,0x00,0xa0,0xc9,0x5e,0xa8,0x50); 
EXTERN_GUID( WM_SampleExtensionGUID_OutputCleanPoint, 0xf72a3c6f, 0x6eb4, 0x4ebc, 0xb1, 0x92, 0x9, 0xad, 0x97, 0x59, 0xe8, 0x28 );
EXTERN_GUID( WM_SampleExtensionGUID_Timecode, 0x399595ec, 0x8667, 0x4e2d, 0x8f, 0xdb, 0x98, 0x81, 0x4c, 0xe7, 0x6c, 0x1e);
EXTERN_GUID( WM_SampleExtensionGUID_ChromaLocation, 0x4c5acca0, 0x9276, 0x4b2c, 0x9e, 0x4c, 0xa0, 0xed, 0xef, 0xdd, 0x21, 0x7e);
EXTERN_GUID( WM_SampleExtensionGUID_ColorSpaceInfo, 0xf79ada56, 0x30eb, 0x4f2b, 0x9f, 0x7a, 0xf2, 0x4b, 0x13, 0x9a, 0x11, 0x57 );
EXTERN_GUID( WM_SampleExtensionGUID_UserDataInfo, 0x732bb4fa, 0x78be, 0x4549, 0x99, 0xbd, 0x2, 0xdb, 0x1a, 0x55, 0xb7, 0xa8 );
EXTERN_GUID( WM_SampleExtensionGUID_FileName, 0xe165ec0e, 0x19ed, 0x45d7, 0xb4, 0xa7, 0x25, 0xcb, 0xd1, 0xe2, 0x8e, 0x9b);
EXTERN_GUID( WM_SampleExtensionGUID_ContentType, 0xd590dc20, 0x07bc, 0x436c, 0x9c, 0xf7, 0xf3, 0xbb, 0xfb, 0xf1, 0xa4, 0xdc );
EXTERN_GUID( WM_SampleExtensionGUID_PixelAspectRatio, 0x1b1ee554, 0xf9ea, 0x4bc8, 0x82, 0x1a, 0x37, 0x6b, 0x74, 0xe4, 0xc4, 0xb8 );
EXTERN_GUID( WM_SampleExtensionGUID_SampleDuration, 0xc6bd9450, 0x867f, 0x4907, 0x83, 0xa3, 0xc7, 0x79, 0x21, 0xb7, 0x33, 0xad );
EXTERN_GUID( WM_SampleExtensionGUID_SampleProtectionSalt, 0x5403deee, 0xb9ee, 0x438f, 0xaa, 0x83, 0x38, 0x4, 0x99, 0x7e, 0x56, 0x9d );
#define WM_SampleExtension_ContentType_Size         1
#define WM_SampleExtension_PixelAspectRatio_Size    2
#define WM_SampleExtension_Timecode_Size           14
#define WM_SampleExtension_SampleDuration_Size      2
#define WM_SampleExtension_ChromaLocation_Size      1
#define WM_SampleExtension_ColorSpaceInfo_Size      3
#define WM_CT_REPEAT_FIRST_FIELD 0x10
#define WM_CT_BOTTOM_FIELD_FIRST 0x20
#define WM_CT_TOP_FIELD_FIRST    0x40
#define WM_CT_INTERLACED         0x80
#define WM_CL_INTERLACED420   0
#define WM_CL_PROGRESSIVE420  1

#pragma pack(push)

#pragma pack(1)
typedef struct _WMT_COLORSPACEINFO_EXTENSION_DATA
    {
    BYTE ucColorPrimaries;
    BYTE ucColorTransferChar;
    BYTE ucColorMatrixCoef;
    } 	WMT_COLORSPACEINFO_EXTENSION_DATA;


#pragma pack(pop)

#pragma pack(push)

#pragma pack(2)
typedef struct _WMT_TIMECODE_EXTENSION_DATA
    {
    WORD wRange;
    DWORD dwTimecode;
    DWORD dwUserbits;
    DWORD dwAmFlags;
    } 	WMT_TIMECODE_EXTENSION_DATA;


#pragma pack(pop)
typedef struct _DRM_VAL16
    {
    BYTE val[ 16 ];
    } 	DRM_VAL16;

EXTERN_GUID( IID_IWMMediaProps,         0x96406bce,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMVideoMediaProps,    0x96406bcf,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMWriter,             0x96406bd4,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMInputMediaProps,    0x96406bd5,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMReader,             0x96406bd6,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMSyncReader,         0x9397f121,0x7705,0x4dc9,0xb0,0x49,0x98,0xb6,0x98,0x18,0x84,0x14 );
EXTERN_GUID( IID_IWMSyncReader2,        0xfaed3d21,0x1b6b,0x4af7,0x8c,0xb6,0x3e,0x18,0x9b,0xbc,0x18,0x7b );
EXTERN_GUID( IID_IWMOutputMediaProps,   0x96406bd7,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMStatusCallback,     0x6d7cdc70,0x9888,0x11d3,0x8e,0xdc,0x00,0xc0,0x4f,0x61,0x09,0xcf );
EXTERN_GUID( IID_IWMReaderCallback,     0x96406bd8,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMCredentialCallback, 0x342e0eb7,0xe651,0x450c,0x97,0x5b,0x2a,0xce,0x2c,0x90,0xc4,0x8e );
EXTERN_GUID( IID_IWMMetadataEditor,     0x96406bd9,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMMetadataEditor2,    0x203cffe3,0x2e18,0x4fdf,0xb5,0x9d,0x6e,0x71,0x53,0x05,0x34,0xcf );
EXTERN_GUID( IID_IWMDRMEditor,          0xFF130EBC,0xA6C3,0x42A6,0xB4,0x01,0xC3,0x38,0x2C,0x3E,0x08,0xB3 );
EXTERN_GUID( IID_IWMHeaderInfo,         0x96406bda,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMHeaderInfo2,        0x15cf9781,0x454e,0x482e,0xb3,0x93,0x85,0xfa,0xe4,0x87,0xa8,0x10 );
EXTERN_GUID( IID_IWMHeaderInfo3,        0x15CC68E3,0x27CC,0x4ecd,0xB2,0x22,0x3F,0x5D,0x02,0xD8,0x0B,0xD5 );
EXTERN_GUID( IID_IWMProfileManager,     0xd16679f2,0x6ca0,0x472d,0x8d,0x31,0x2f,0x5d,0x55,0xae,0xe1,0x55 );
EXTERN_GUID( IID_IWMProfileManager2,    0x7a924e51,0x73c1,0x494d,0x80,0x19,0x23,0xd3,0x7e,0xd9,0xb8,0x9a );
EXTERN_GUID( IID_IWMProfileManagerLanguage, 0xba4dcc78,0x7ee0,0x4ab8,0xb2,0x7a,0xdb,0xce,0x8b,0xc5,0x14,0x54 );
EXTERN_GUID( IID_IWMProfile,            0x96406bdb,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMProfile2,           0x07e72d33,0xd94e,0x4be7,0x88,0x43,0x60,0xae,0x5f,0xf7,0xe5,0xf5 );
EXTERN_GUID( IID_IWMProfile3,           0x00ef96cc,0xa461,0x4546,0x8b,0xcd,0xc9,0xa2,0x8f,0x0e,0x06,0xf5 );
EXTERN_GUID( IID_IWMStreamConfig,       0x96406bdc,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMStreamConfig2,      0x7688d8cb,0xfc0d,0x43bd,0x94,0x59,0x5a,0x8d,0xec,0x20,0x0c,0xfa );
EXTERN_GUID( IID_IWMStreamConfig3,      0xcb164104,0x3aa9,0x45a7,0x9a,0xc9,0x4d,0xae,0xe1,0x31,0xd6,0xe1 );
EXTERN_GUID( IID_IWMStreamList,         0x96406bdd,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMMutualExclusion,    0x96406bde,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMMutualExclusion2,   0x302b57d,0x89d1,0x4ba2,0x85,0xc9,0x16,0x6f,0x2c,0x53,0xeb,0x91 );
EXTERN_GUID( IID_IWMBandwidthSharing,   0xad694af1,0xf8d9,0x42f8,0xbc,0x47,0x70,0x31,0x1b,0x0c,0x4f,0x9e );
EXTERN_GUID( IID_IWMStreamPrioritization, 0x8c1c6090,0xf9a8,0x4748,0x8e,0xc3,0xdd,0x11,0x08,0xba,0x1e,0x77 );
EXTERN_GUID( IID_IWMWriterAdvanced,     0x96406be3,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMWriterAdvanced2,    0x962dc1ec,0xc046,0x4db8,0x9c,0xc7,0x26,0xce,0xae,0x50,0x08,0x17 );
EXTERN_GUID( IID_IWMWriterAdvanced3,    0x2cd6492d,0x7c37,0x4e76,0x9d,0x3b,0x59,0x26,0x11,0x83,0xa2,0x2e );
EXTERN_GUID( IID_IWMWriterPreprocess,   0xfc54a285,0x38c4,0x45b5,0xaa,0x23,0x85,0xb9,0xf7,0xcb,0x42,0x4b );
EXTERN_GUID( IID_IWMWriterSink,         0x96406be4,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMWriterFileSink,     0x96406be5,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMWriterFileSink2,    0x14282ba7,0x4aef,0x4205,0x8c,0xe5,0xc2,0x29,0x03,0x5a,0x05,0xbc );
EXTERN_GUID( IID_IWMWriterFileSink3,    0x3fea4feb,0x2945,0x47a7,0xa1,0xdd,0xc5,0x3a,0x8f,0xc4,0xc4,0x5c );
EXTERN_GUID( IID_IWMWriterNetworkSink,  0x96406be7,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMClientConnections,  0x73c66010,0xa299,0x41df,0xb1,0xf0,0xcc,0xf0,0x3b,0x09,0xc1,0xc6 );
EXTERN_GUID( IID_IWMClientConnections2, 0x4091571e,0x4701,0x4593,0xbb,0x3d,0xd5,0xf5,0xf0,0xc7,0x42,0x46 ); 
EXTERN_GUID( IID_IWMReaderAdvanced,     0x96406bea,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMReaderAdvanced2,    0xae14a945,0xb90c,0x4d0d,0x91,0x27,0x80,0xd6,0x65,0xf7,0xd7,0x3e );
EXTERN_GUID( IID_IWMReaderAdvanced3,    0x5dc0674b,0xf04b,0x4a4e,0x9f,0x2a,0xb1,0xaf,0xde,0x2c,0x81,0x00 );
EXTERN_GUID( IID_IWMReaderAdvanced4,    0x945a76a2,0x12ae,0x4d48,0xbd,0x3c,0xcd,0x1d,0x90,0x39,0x9b,0x85 );
EXTERN_GUID( IID_IWMReaderAdvanced5,    0x24c44db0,0x55d1,0x49ae,0xa5,0xcc,0xf1,0x38,0x15,0xe3,0x63,0x63 );
EXTERN_GUID( IID_IWMReaderAdvanced6,    0x18a2e7f8,0x428f,0x4acd,0x8a,0x00,0xe6,0x46,0x39,0xbc,0x93,0xde );
EXTERN_GUID( IID_IWMPlayerHook,         0xe5b7ca9a,0x0f1c,0x4f66,0x90,0x02,0x74,0xec,0x50,0xd8,0xb3,0x04 );
EXTERN_GUID( IID_IWMDRMReader,          0xd2827540,0x3ee7,0x432c,0xb1,0x4c,0xdc,0x17,0xf0,0x85,0xd3,0xb3 );
EXTERN_GUID( IID_IWMDRMReader2,         0xbefe7a75,0x9f1d,0x4075,0xb9,0xd9,0xa3,0xc3,0x7b,0xda,0x49,0xa0 );
EXTERN_GUID( IID_IWMDRMReader3,         0xe08672de,0xf1e7,0x4ff4,0xa0,0xa3,0xfc,0x4b,0x08,0xe4,0xca,0xf8 );
EXTERN_GUID( IID_IWMReaderPlaylistBurn, 0xf28c0300,0x9baa,0x4477,0xa8,0x46,0x17,0x44,0xd9,0xcb,0xf5,0x33 );
EXTERN_GUID( IID_IWMReaderCallbackAdvanced, 0x96406beb,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMReaderNetworkConfig,0x96406bec,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMReaderStreamClock,  0x96406bed,0x2b2b,0x11d3,0xb3,0x6b,0x00,0xc0,0x4f,0x61,0x08,0xff );
EXTERN_GUID( IID_IWMIndexer,            0x6d7cdc71,0x9888,0x11d3,0x8e,0xdc,0x00,0xc0,0x4f,0x61,0x09,0xcf );
EXTERN_GUID( IID_IWMIndexer2,           0xb70f1e42,0x6255,0x4df0,0xa6,0xb9,0x02,0xb2,0x12,0xd9,0xe2,0xbb );
EXTERN_GUID( IID_IWMReaderAllocatorEx,  0x9f762fa7,0xa22e,0x428d,0x93,0xc9,0xac,0x82,0xf3,0xaa,0xfe,0x5a );
EXTERN_GUID( IID_IWMReaderTypeNegotiation, 0xfdbe5592,0x81a1,0x41ea,0x93,0xbd,0x73,0x5c,0xad,0x1a,0xdc,0x5 );
EXTERN_GUID( IID_IWMLicenseBackup,      0x05E5AC9F,0x3FB6,0x4508,0xBB,0x43,0xA4,0x06,0x7B,0xA1,0xEB,0xE8);
EXTERN_GUID( IID_IWMLicenseRestore,     0xC70B6334,0xa22e,0x4efb,0xA2,0x45,0x15,0xE6,0x5A,0x00,0x4A,0x13);
EXTERN_GUID( IID_IWMBackupRestoreProps, 0x3C8E0DA6,0x996F,0x4ff3,0xA1,0xAF,0x48,0x38,0xF9,0x37,0x7e,0x2e);
EXTERN_GUID( IID_IWMPacketSize,         0xcdfb97ab,0x188f,0x40b3,0xb6,0x43,0x5b,0x79,0x03,0x97,0x5c,0x59);
EXTERN_GUID( IID_IWMPacketSize2,        0x8bfc2b9e,0xb646,0x4233,0xa8,0x77,0x1c,0x6a,0x7,0x96,0x69,0xdc);
EXTERN_GUID( IID_IWMRegisterCallback,   0xcf4b1f99,0x4de2,0x4e49,0xa3,0x63,0x25,0x27,0x40,0xd9,0x9b,0xc1);
EXTERN_GUID( IID_IWMWriterPostView,     0x81e20ce4,0x75ef,0x491a,0x80,0x04,0xfc,0x53,0xc4,0x5b,0xdc,0x3e);
EXTERN_GUID( IID_IWMWriterPostViewCallback, 0xd9d6549d,0xa193,0x4f24,0xb3,0x08,0x03,0x12,0x3d,0x9b,0x7f,0x8d);
EXTERN_GUID( IID_IWMCodecInfo,          0xa970f41e,0x34de,0x4a98,0xb3,0xba,0xe4,0xb3,0xca,0x75,0x28,0xf0);
EXTERN_GUID( IID_IWMCodecInfo2,         0xaa65e273,0xb686,0x4056,0x91,0xec,0xdd,0x76,0x8d,0x4d,0xf7,0x10);
EXTERN_GUID( IID_IWMCodecInfo3,         0x7e51f487,0x4d93,0x4f98,0x8a,0xb4,0x27,0xd0,0x56,0x5a,0xdc,0x51);
EXTERN_GUID( IID_IWMPropertyVault,      0x72995A79,0x5090,0x42a4,0x9C,0x8C,0xD9,0xD0,0xB6,0xD3,0x4B,0xE5 );
EXTERN_GUID( IID_IWMIStreamProps,       0x6816dad3,0x2b4b,0x4c8e,0x81,0x49,0x87,0x4c,0x34,0x83,0xa7,0x53 );
EXTERN_GUID( IID_IWMLanguageList,       0xdf683f00,0x2d49,0x4d8e,0x92,0xb7,0xfb,0x19,0xf6,0xa0,0xdc,0x57 );
EXTERN_GUID( IID_IWMDRMWriter,          0xd6ea5dd0,0x12a0,0x43f4,0x90,0xab,0xa3,0xfd,0x45,0x1e,0x6a,0x07 );
EXTERN_GUID( IID_IWMDRMWriter2,         0x38ee7a94,0x40e2,0x4e10,0xaa,0x3f,0x33,0xfd,0x32,0x10,0xed,0x5b );
EXTERN_GUID( IID_IWMDRMWriter3,         0xa7184082,0xa4aa,0x4dde,0xac,0x9c,0xe7,0x5d,0xbd,0x11,0x17,0xce );
EXTERN_GUID( IID_IWMWriterPushSink,      0xdc10e6a5,0x072c,0x467d,0xbf,0x57,0x63,0x30,0xa9,0xdd,0xe1,0x2a );
EXTERN_GUID( IID_IWMReaderNetworkConfig2,0xd979a853,0x042b,0x4050,0x83,0x87,0xc9,0x39,0xdb,0x22,0x01,0x3f );
EXTERN_GUID( IID_IWMWatermarkInfo,       0x6f497062,0xf2e2,0x4624,0x8e,0xa7,0x9d,0xd4,0x0d,0x81,0xfc,0x8d );
EXTERN_GUID( IID_IWMReaderAccelerator,   0xbddc4d08,0x944d,0x4d52,0xa6,0x12,0x46,0xc3,0xfd,0xa0,0x7d,0xd4 );
EXTERN_GUID( IID_IWMReaderTimecode,        0xf369e2f0,0xe081,0x4fe6,0x84,0x50,0xb8,0x10,0xb2,0xf4,0x10,0xd1 );
EXTERN_GUID( IID_IWMImageInfo,            0x9f0aa3b6,0x7267,0x4d89,0x88,0xf2,0xba,0x91,0x5a,0xa5,0xc4,0xc6);
EXTERN_GUID( IID_IWMAddressAccess,        0xBB3C6389,0x1633,0x4e92,0xAF,0x14,0x9F,0x31,0x73,0xBA,0x39,0xD0 );
EXTERN_GUID( IID_IWMAddressAccess2,       0x65a83fc2,0x3e98,0x4d4d,0x81,0xb5,0x2a,0x74,0x28,0x86,0xb3,0x3d );
EXTERN_GUID( IID_IWMDeviceRegistration,   0xf6211f03,0x8d21,0x4e94,0x93,0xe6,0x85,0x10,0x80,0x5f,0x2d,0x99 );
EXTERN_GUID( IID_IWMRegisteredDevice,     0xa4503bec,0x5508,0x4148,0x97,0xac,0xbf,0xa7,0x57,0x60,0xa7,0x0d );
EXTERN_GUID( IID_IWMProximityDetection,   0x6A9FD8EE,0xB651,0x4bf0,0xB8,0x49,0x7D,0x4E,0xCE,0x79,0xA2,0xB1 );
EXTERN_GUID( IID_IWMDRMMessageParser,     0xa73a0072,0x25a0,0x4c99,0xb4,0xa5,0xed,0xe8,0x10,0x1a,0x6c,0x39 );
EXTERN_GUID( IID_IWMDRMTranscryptor,      0x69059850,0x6e6f,0x4bb2,0x80,0x6f,0x71,0x86,0x3d,0xdf,0xc4,0x71 );
EXTERN_GUID( IID_IWMDRMTranscryptor2,     0xe0da439f,0xd331,0x496a,0xbe,0xce,0x18,0xe5,0xba,0xc5,0xdd,0x23 );
EXTERN_GUID( IID_IWMDRMTranscryptionManager, 0xb1a887b2,0xa4f0,0x407a,0xb0,0x2e,0xef,0xbd,0x23,0xbb,0xec,0xdf );
EXTERN_GUID( IID_IWMLicenseRevocationAgent, 0x6967f2c9,0x4e26,0x4b57,0x88,0x94,0x79,0x98,0x80,0xf7,0xac,0x7b );
EXTERN_GUID( CLSID_WMMUTEX_Language, 0xD6E22A00,0x35DA,0x11D1,0x90,0x34,0x00,0xA0,0xC9,0x03,0x49,0xBE );
EXTERN_GUID( CLSID_WMMUTEX_Bitrate, 0xD6E22A01,0x35DA,0x11D1,0x90,0x34,0x00,0xA0,0xC9,0x03,0x49,0xBE );
EXTERN_GUID( CLSID_WMMUTEX_Presentation, 0xD6E22A02,0x35DA,0x11D1,0x90,0x34,0x00,0xA0,0xC9,0x03,0x49,0xBE );
EXTERN_GUID( CLSID_WMMUTEX_Unknown, 0xD6E22A03,0x35DA,0x11D1,0x90,0x34,0x00,0xA0,0xC9,0x03,0x49,0xBE );
EXTERN_GUID( CLSID_WMBandwidthSharing_Exclusive, 0xaf6060aa,0x5197,0x11d2,0xb6,0xaf,0x00,0xc0,0x4f,0xd9,0x08,0xe9 );
EXTERN_GUID( CLSID_WMBandwidthSharing_Partial, 0xaf6060ab,0x5197,0x11d2,0xb6,0xaf,0x00,0xc0,0x4f,0xd9,0x08,0xe9 );
// {B42CDE2B-6178-4a2c-A375-89DD3FD7F497}
EXTERN_GUID( WMT_DMOCATEGORY_AUDIO_WATERMARK, 0x65221c5a, 0xfa75, 0x4b39, 0xb5, 0x0c, 0x06, 0xc3, 0x36, 0xb6, 0xa3, 0xef );
// {E77797C6-18AF-4458-BBDD-492D3F78FC8F}
EXTERN_GUID( WMT_DMOCATEGORY_VIDEO_WATERMARK, 0x187cc922, 0x8efc, 0x4404, 0x9d, 0xaf, 0x63, 0xf4, 0x83, 0x0d, 0xf1, 0xbc );
#define WM_MAX_VIDEO_STREAMS            0x3f
#define WM_MAX_STREAMS                  0x3f
HRESULT STDMETHODCALLTYPE WMIsContentProtected( const WCHAR *pwszFileName, BOOL *pfIsProtected );
HRESULT STDMETHODCALLTYPE WMCreateWriter( IUnknown* pUnkCert, IWMWriter **ppWriter );
HRESULT STDMETHODCALLTYPE WMCreateReader( IUnknown* pUnkCert, DWORD dwRights, IWMReader **ppReader );
HRESULT STDMETHODCALLTYPE WMCreateSyncReader( IUnknown* pUnkCert, DWORD dwRights, IWMSyncReader **ppSyncReader );
HRESULT STDMETHODCALLTYPE WMCreateEditor( IWMMetadataEditor **ppEditor );
HRESULT STDMETHODCALLTYPE WMCreateIndexer( IWMIndexer **ppIndexer );
HRESULT STDMETHODCALLTYPE WMCreateBackupRestorer( IUnknown *pCallback, IWMLicenseBackup **ppBackup );
HRESULT STDMETHODCALLTYPE WMCreateProfileManager( IWMProfileManager **ppProfileManager );
HRESULT STDMETHODCALLTYPE WMCreateWriterFileSink( IWMWriterFileSink **ppSink );
HRESULT STDMETHODCALLTYPE WMCreateWriterNetworkSink( IWMWriterNetworkSink **ppSink );
HRESULT STDMETHODCALLTYPE WMCreateWriterPushSink( IWMWriterPushSink **ppSink );
HRESULT STDMETHODCALLTYPE WMCreateDeviceRegistration( IWMDeviceRegistration **ppDevReg );
HRESULT STDMETHODCALLTYPE WMCreateDRMTranscryptor( IWMDRMTranscryptor **ppTranscryptor );
HRESULT STDMETHODCALLTYPE WMCreateDRMTranscryptionManager( IWMDRMTranscryptionManager **ppTranscryptionManager );
HRESULT STDMETHODCALLTYPE WMCreateLicenseRevocationAgent( IUnknown *pCallback, IWMLicenseRevocationAgent ** ppLicenseRevocationAgent );


extern RPC_IF_HANDLE __MIDL_itf_wmsdkidl_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wmsdkidl_0000_0000_v0_0_s_ifspec;

#ifndef __IWMMediaProps_INTERFACE_DEFINED__
#define __IWMMediaProps_INTERFACE_DEFINED__

/* interface IWMMediaProps */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMMediaProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BCE-2B2B-11d3-B36B-00C04F6108FF")
    IWMMediaProps : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [annotation][out] */ 
            _Out_  GUID *pguidType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaType( 
            /* [annotation][out] */ 
            _Out_  WM_MEDIA_TYPE *pType,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaType( 
            /* [annotation][in] */ 
            _In_  WM_MEDIA_TYPE *pType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMMediaPropsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMMediaProps * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMMediaProps * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMMediaProps * This);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, GetType)
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IWMMediaProps * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidType);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, GetMediaType)
        HRESULT ( STDMETHODCALLTYPE *GetMediaType )( 
            IWMMediaProps * This,
            /* [annotation][out] */ 
            _Out_  WM_MEDIA_TYPE *pType,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbType);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, SetMediaType)
        HRESULT ( STDMETHODCALLTYPE *SetMediaType )( 
            IWMMediaProps * This,
            /* [annotation][in] */ 
            _In_  WM_MEDIA_TYPE *pType);
        
        END_INTERFACE
    } IWMMediaPropsVtbl;

    interface IWMMediaProps
    {
        CONST_VTBL struct IWMMediaPropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMMediaProps_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMMediaProps_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMMediaProps_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMMediaProps_GetType(This,pguidType)	\
    ( (This)->lpVtbl -> GetType(This,pguidType) ) 

#define IWMMediaProps_GetMediaType(This,pType,pcbType)	\
    ( (This)->lpVtbl -> GetMediaType(This,pType,pcbType) ) 

#define IWMMediaProps_SetMediaType(This,pType)	\
    ( (This)->lpVtbl -> SetMediaType(This,pType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMMediaProps_INTERFACE_DEFINED__ */


#ifndef __IWMVideoMediaProps_INTERFACE_DEFINED__
#define __IWMVideoMediaProps_INTERFACE_DEFINED__

/* interface IWMVideoMediaProps */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMVideoMediaProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BCF-2B2B-11d3-B36B-00C04F6108FF")
    IWMVideoMediaProps : public IWMMediaProps
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMaxKeyFrameSpacing( 
            /* [annotation][out] */ 
            _Out_  LONGLONG *pllTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxKeyFrameSpacing( 
            /* [annotation][in] */ 
            _In_  LONGLONG llTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetQuality( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwQuality) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetQuality( 
            /* [annotation][in] */ 
            _In_  DWORD dwQuality) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMVideoMediaPropsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMVideoMediaProps * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMVideoMediaProps * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMVideoMediaProps * This);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, GetType)
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IWMVideoMediaProps * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidType);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, GetMediaType)
        HRESULT ( STDMETHODCALLTYPE *GetMediaType )( 
            IWMVideoMediaProps * This,
            /* [annotation][out] */ 
            _Out_  WM_MEDIA_TYPE *pType,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbType);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, SetMediaType)
        HRESULT ( STDMETHODCALLTYPE *SetMediaType )( 
            IWMVideoMediaProps * This,
            /* [annotation][in] */ 
            _In_  WM_MEDIA_TYPE *pType);
        
        DECLSPEC_XFGVIRT(IWMVideoMediaProps, GetMaxKeyFrameSpacing)
        HRESULT ( STDMETHODCALLTYPE *GetMaxKeyFrameSpacing )( 
            IWMVideoMediaProps * This,
            /* [annotation][out] */ 
            _Out_  LONGLONG *pllTime);
        
        DECLSPEC_XFGVIRT(IWMVideoMediaProps, SetMaxKeyFrameSpacing)
        HRESULT ( STDMETHODCALLTYPE *SetMaxKeyFrameSpacing )( 
            IWMVideoMediaProps * This,
            /* [annotation][in] */ 
            _In_  LONGLONG llTime);
        
        DECLSPEC_XFGVIRT(IWMVideoMediaProps, GetQuality)
        HRESULT ( STDMETHODCALLTYPE *GetQuality )( 
            IWMVideoMediaProps * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwQuality);
        
        DECLSPEC_XFGVIRT(IWMVideoMediaProps, SetQuality)
        HRESULT ( STDMETHODCALLTYPE *SetQuality )( 
            IWMVideoMediaProps * This,
            /* [annotation][in] */ 
            _In_  DWORD dwQuality);
        
        END_INTERFACE
    } IWMVideoMediaPropsVtbl;

    interface IWMVideoMediaProps
    {
        CONST_VTBL struct IWMVideoMediaPropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMVideoMediaProps_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMVideoMediaProps_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMVideoMediaProps_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMVideoMediaProps_GetType(This,pguidType)	\
    ( (This)->lpVtbl -> GetType(This,pguidType) ) 

#define IWMVideoMediaProps_GetMediaType(This,pType,pcbType)	\
    ( (This)->lpVtbl -> GetMediaType(This,pType,pcbType) ) 

#define IWMVideoMediaProps_SetMediaType(This,pType)	\
    ( (This)->lpVtbl -> SetMediaType(This,pType) ) 


#define IWMVideoMediaProps_GetMaxKeyFrameSpacing(This,pllTime)	\
    ( (This)->lpVtbl -> GetMaxKeyFrameSpacing(This,pllTime) ) 

#define IWMVideoMediaProps_SetMaxKeyFrameSpacing(This,llTime)	\
    ( (This)->lpVtbl -> SetMaxKeyFrameSpacing(This,llTime) ) 

#define IWMVideoMediaProps_GetQuality(This,pdwQuality)	\
    ( (This)->lpVtbl -> GetQuality(This,pdwQuality) ) 

#define IWMVideoMediaProps_SetQuality(This,dwQuality)	\
    ( (This)->lpVtbl -> SetQuality(This,dwQuality) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMVideoMediaProps_INTERFACE_DEFINED__ */


#ifndef __IWMWriter_INTERFACE_DEFINED__
#define __IWMWriter_INTERFACE_DEFINED__

/* interface IWMWriter */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BD4-2B2B-11d3-B36B-00C04F6108FF")
    IWMWriter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetProfileByID( 
            /* [annotation][in] */ 
            _In_  REFGUID guidProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProfile( 
            /* [annotation][in] */ 
            _In_  IWMProfile *pProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutputFilename( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcInputs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputProps( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][out] */ 
            _Out_  IWMInputMediaProps **ppInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInputProps( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  IWMInputMediaProps *pInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputFormatCount( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNumber,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputFormat( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNumber,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatNumber,
            /* [annotation][out] */ 
            _Out_  IWMInputMediaProps **pProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginWriting( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndWriting( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocateSample( 
            /* [annotation][in] */ 
            _In_  DWORD dwSampleSize,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppSample) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteSample( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Flush( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriter * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriter * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriter * This);
        
        DECLSPEC_XFGVIRT(IWMWriter, SetProfileByID)
        HRESULT ( STDMETHODCALLTYPE *SetProfileByID )( 
            IWMWriter * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidProfile);
        
        DECLSPEC_XFGVIRT(IWMWriter, SetProfile)
        HRESULT ( STDMETHODCALLTYPE *SetProfile )( 
            IWMWriter * This,
            /* [annotation][in] */ 
            _In_  IWMProfile *pProfile);
        
        DECLSPEC_XFGVIRT(IWMWriter, SetOutputFilename)
        HRESULT ( STDMETHODCALLTYPE *SetOutputFilename )( 
            IWMWriter * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMWriter, GetInputCount)
        HRESULT ( STDMETHODCALLTYPE *GetInputCount )( 
            IWMWriter * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcInputs);
        
        DECLSPEC_XFGVIRT(IWMWriter, GetInputProps)
        HRESULT ( STDMETHODCALLTYPE *GetInputProps )( 
            IWMWriter * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][out] */ 
            _Out_  IWMInputMediaProps **ppInput);
        
        DECLSPEC_XFGVIRT(IWMWriter, SetInputProps)
        HRESULT ( STDMETHODCALLTYPE *SetInputProps )( 
            IWMWriter * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  IWMInputMediaProps *pInput);
        
        DECLSPEC_XFGVIRT(IWMWriter, GetInputFormatCount)
        HRESULT ( STDMETHODCALLTYPE *GetInputFormatCount )( 
            IWMWriter * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNumber,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormats);
        
        DECLSPEC_XFGVIRT(IWMWriter, GetInputFormat)
        HRESULT ( STDMETHODCALLTYPE *GetInputFormat )( 
            IWMWriter * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNumber,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatNumber,
            /* [annotation][out] */ 
            _Out_  IWMInputMediaProps **pProps);
        
        DECLSPEC_XFGVIRT(IWMWriter, BeginWriting)
        HRESULT ( STDMETHODCALLTYPE *BeginWriting )( 
            IWMWriter * This);
        
        DECLSPEC_XFGVIRT(IWMWriter, EndWriting)
        HRESULT ( STDMETHODCALLTYPE *EndWriting )( 
            IWMWriter * This);
        
        DECLSPEC_XFGVIRT(IWMWriter, AllocateSample)
        HRESULT ( STDMETHODCALLTYPE *AllocateSample )( 
            IWMWriter * This,
            /* [annotation][in] */ 
            _In_  DWORD dwSampleSize,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppSample);
        
        DECLSPEC_XFGVIRT(IWMWriter, WriteSample)
        HRESULT ( STDMETHODCALLTYPE *WriteSample )( 
            IWMWriter * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample);
        
        DECLSPEC_XFGVIRT(IWMWriter, Flush)
        HRESULT ( STDMETHODCALLTYPE *Flush )( 
            IWMWriter * This);
        
        END_INTERFACE
    } IWMWriterVtbl;

    interface IWMWriter
    {
        CONST_VTBL struct IWMWriterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriter_SetProfileByID(This,guidProfile)	\
    ( (This)->lpVtbl -> SetProfileByID(This,guidProfile) ) 

#define IWMWriter_SetProfile(This,pProfile)	\
    ( (This)->lpVtbl -> SetProfile(This,pProfile) ) 

#define IWMWriter_SetOutputFilename(This,pwszFilename)	\
    ( (This)->lpVtbl -> SetOutputFilename(This,pwszFilename) ) 

#define IWMWriter_GetInputCount(This,pcInputs)	\
    ( (This)->lpVtbl -> GetInputCount(This,pcInputs) ) 

#define IWMWriter_GetInputProps(This,dwInputNum,ppInput)	\
    ( (This)->lpVtbl -> GetInputProps(This,dwInputNum,ppInput) ) 

#define IWMWriter_SetInputProps(This,dwInputNum,pInput)	\
    ( (This)->lpVtbl -> SetInputProps(This,dwInputNum,pInput) ) 

#define IWMWriter_GetInputFormatCount(This,dwInputNumber,pcFormats)	\
    ( (This)->lpVtbl -> GetInputFormatCount(This,dwInputNumber,pcFormats) ) 

#define IWMWriter_GetInputFormat(This,dwInputNumber,dwFormatNumber,pProps)	\
    ( (This)->lpVtbl -> GetInputFormat(This,dwInputNumber,dwFormatNumber,pProps) ) 

#define IWMWriter_BeginWriting(This)	\
    ( (This)->lpVtbl -> BeginWriting(This) ) 

#define IWMWriter_EndWriting(This)	\
    ( (This)->lpVtbl -> EndWriting(This) ) 

#define IWMWriter_AllocateSample(This,dwSampleSize,ppSample)	\
    ( (This)->lpVtbl -> AllocateSample(This,dwSampleSize,ppSample) ) 

#define IWMWriter_WriteSample(This,dwInputNum,cnsSampleTime,dwFlags,pSample)	\
    ( (This)->lpVtbl -> WriteSample(This,dwInputNum,cnsSampleTime,dwFlags,pSample) ) 

#define IWMWriter_Flush(This)	\
    ( (This)->lpVtbl -> Flush(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriter_INTERFACE_DEFINED__ */


#ifndef __IWMDRMWriter_INTERFACE_DEFINED__
#define __IWMDRMWriter_INTERFACE_DEFINED__

/* interface IWMDRMWriter */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDRMWriter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d6ea5dd0-12a0-43f4-90ab-a3fd451e6a07")
    IWMDRMWriter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GenerateKeySeed( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchLength)  WCHAR *pwszKeySeed,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GenerateKeyID( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchLength)  WCHAR *pwszKeyID,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GenerateSigningKeyPair( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchPrivKeyLength)  WCHAR *pwszPrivKey,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchPrivKeyLength,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchPubKeyLength)  WCHAR *pwszPubKey,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchPubKeyLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDRMAttribute( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDRMWriterVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDRMWriter * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDRMWriter * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDRMWriter * This);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, GenerateKeySeed)
        HRESULT ( STDMETHODCALLTYPE *GenerateKeySeed )( 
            IWMDRMWriter * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchLength)  WCHAR *pwszKeySeed,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchLength);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, GenerateKeyID)
        HRESULT ( STDMETHODCALLTYPE *GenerateKeyID )( 
            IWMDRMWriter * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchLength)  WCHAR *pwszKeyID,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchLength);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, GenerateSigningKeyPair)
        HRESULT ( STDMETHODCALLTYPE *GenerateSigningKeyPair )( 
            IWMDRMWriter * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchPrivKeyLength)  WCHAR *pwszPrivKey,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchPrivKeyLength,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchPubKeyLength)  WCHAR *pwszPubKey,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchPubKeyLength);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, SetDRMAttribute)
        HRESULT ( STDMETHODCALLTYPE *SetDRMAttribute )( 
            IWMDRMWriter * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        END_INTERFACE
    } IWMDRMWriterVtbl;

    interface IWMDRMWriter
    {
        CONST_VTBL struct IWMDRMWriterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDRMWriter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDRMWriter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDRMWriter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDRMWriter_GenerateKeySeed(This,pwszKeySeed,pcwchLength)	\
    ( (This)->lpVtbl -> GenerateKeySeed(This,pwszKeySeed,pcwchLength) ) 

#define IWMDRMWriter_GenerateKeyID(This,pwszKeyID,pcwchLength)	\
    ( (This)->lpVtbl -> GenerateKeyID(This,pwszKeyID,pcwchLength) ) 

#define IWMDRMWriter_GenerateSigningKeyPair(This,pwszPrivKey,pcwchPrivKeyLength,pwszPubKey,pcwchPubKeyLength)	\
    ( (This)->lpVtbl -> GenerateSigningKeyPair(This,pwszPrivKey,pcwchPrivKeyLength,pwszPubKey,pcwchPubKeyLength) ) 

#define IWMDRMWriter_SetDRMAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetDRMAttribute(This,wStreamNum,pszName,Type,pValue,cbLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDRMWriter_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_wmsdkidl_0000_0004 */
/* [local] */ 

#ifndef WMDRM_IMPORT_INIT_STRUCT_DEFINED
#define WMDRM_IMPORT_INIT_STRUCT_DEFINED 1
typedef struct WMDRM_IMPORT_INIT_STRUCT
    {
    DWORD dwVersion;
    DWORD cbEncryptedSessionKeyMessage;
    BYTE *pbEncryptedSessionKeyMessage;
    DWORD cbEncryptedKeyMessage;
    BYTE *pbEncryptedKeyMessage;
    } 	WMDRM_IMPORT_INIT_STRUCT;

#endif // WMDRM_IMPORT_INIT_STRUCT_DEFINED


extern RPC_IF_HANDLE __MIDL_itf_wmsdkidl_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wmsdkidl_0000_0004_v0_0_s_ifspec;

#ifndef __IWMDRMWriter2_INTERFACE_DEFINED__
#define __IWMDRMWriter2_INTERFACE_DEFINED__

/* interface IWMDRMWriter2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDRMWriter2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38ee7a94-40e2-4e10-aa3f-33fd3210ed5b")
    IWMDRMWriter2 : public IWMDRMWriter
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetWMDRMNetEncryption( 
            /* [annotation][in] */ 
            _In_  BOOL fSamplesEncrypted,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyID,
            /* [annotation][in] */ 
            _In_  DWORD cbKeyID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDRMWriter2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDRMWriter2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDRMWriter2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDRMWriter2 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, GenerateKeySeed)
        HRESULT ( STDMETHODCALLTYPE *GenerateKeySeed )( 
            IWMDRMWriter2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchLength)  WCHAR *pwszKeySeed,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchLength);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, GenerateKeyID)
        HRESULT ( STDMETHODCALLTYPE *GenerateKeyID )( 
            IWMDRMWriter2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchLength)  WCHAR *pwszKeyID,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchLength);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, GenerateSigningKeyPair)
        HRESULT ( STDMETHODCALLTYPE *GenerateSigningKeyPair )( 
            IWMDRMWriter2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchPrivKeyLength)  WCHAR *pwszPrivKey,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchPrivKeyLength,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchPubKeyLength)  WCHAR *pwszPubKey,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchPubKeyLength);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, SetDRMAttribute)
        HRESULT ( STDMETHODCALLTYPE *SetDRMAttribute )( 
            IWMDRMWriter2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter2, SetWMDRMNetEncryption)
        HRESULT ( STDMETHODCALLTYPE *SetWMDRMNetEncryption )( 
            IWMDRMWriter2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fSamplesEncrypted,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyID,
            /* [annotation][in] */ 
            _In_  DWORD cbKeyID);
        
        END_INTERFACE
    } IWMDRMWriter2Vtbl;

    interface IWMDRMWriter2
    {
        CONST_VTBL struct IWMDRMWriter2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDRMWriter2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDRMWriter2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDRMWriter2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDRMWriter2_GenerateKeySeed(This,pwszKeySeed,pcwchLength)	\
    ( (This)->lpVtbl -> GenerateKeySeed(This,pwszKeySeed,pcwchLength) ) 

#define IWMDRMWriter2_GenerateKeyID(This,pwszKeyID,pcwchLength)	\
    ( (This)->lpVtbl -> GenerateKeyID(This,pwszKeyID,pcwchLength) ) 

#define IWMDRMWriter2_GenerateSigningKeyPair(This,pwszPrivKey,pcwchPrivKeyLength,pwszPubKey,pcwchPubKeyLength)	\
    ( (This)->lpVtbl -> GenerateSigningKeyPair(This,pwszPrivKey,pcwchPrivKeyLength,pwszPubKey,pcwchPubKeyLength) ) 

#define IWMDRMWriter2_SetDRMAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetDRMAttribute(This,wStreamNum,pszName,Type,pValue,cbLength) ) 


#define IWMDRMWriter2_SetWMDRMNetEncryption(This,fSamplesEncrypted,pbKeyID,cbKeyID)	\
    ( (This)->lpVtbl -> SetWMDRMNetEncryption(This,fSamplesEncrypted,pbKeyID,cbKeyID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDRMWriter2_INTERFACE_DEFINED__ */


#ifndef __IWMDRMWriter3_INTERFACE_DEFINED__
#define __IWMDRMWriter3_INTERFACE_DEFINED__

/* interface IWMDRMWriter3 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDRMWriter3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a7184082-a4aa-4dde-ac9c-e75dbd1117ce")
    IWMDRMWriter3 : public IWMDRMWriter2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetProtectStreamSamples( 
            /* [annotation][in] */ 
            _In_  WMDRM_IMPORT_INIT_STRUCT *pImportInitStruct) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDRMWriter3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDRMWriter3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDRMWriter3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDRMWriter3 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, GenerateKeySeed)
        HRESULT ( STDMETHODCALLTYPE *GenerateKeySeed )( 
            IWMDRMWriter3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchLength)  WCHAR *pwszKeySeed,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchLength);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, GenerateKeyID)
        HRESULT ( STDMETHODCALLTYPE *GenerateKeyID )( 
            IWMDRMWriter3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchLength)  WCHAR *pwszKeyID,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchLength);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, GenerateSigningKeyPair)
        HRESULT ( STDMETHODCALLTYPE *GenerateSigningKeyPair )( 
            IWMDRMWriter3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchPrivKeyLength)  WCHAR *pwszPrivKey,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchPrivKeyLength,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcwchPubKeyLength)  WCHAR *pwszPubKey,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcwchPubKeyLength);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter, SetDRMAttribute)
        HRESULT ( STDMETHODCALLTYPE *SetDRMAttribute )( 
            IWMDRMWriter3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter2, SetWMDRMNetEncryption)
        HRESULT ( STDMETHODCALLTYPE *SetWMDRMNetEncryption )( 
            IWMDRMWriter3 * This,
            /* [annotation][in] */ 
            _In_  BOOL fSamplesEncrypted,
            /* [annotation][in] */ 
            _In_  BYTE *pbKeyID,
            /* [annotation][in] */ 
            _In_  DWORD cbKeyID);
        
        DECLSPEC_XFGVIRT(IWMDRMWriter3, SetProtectStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *SetProtectStreamSamples )( 
            IWMDRMWriter3 * This,
            /* [annotation][in] */ 
            _In_  WMDRM_IMPORT_INIT_STRUCT *pImportInitStruct);
        
        END_INTERFACE
    } IWMDRMWriter3Vtbl;

    interface IWMDRMWriter3
    {
        CONST_VTBL struct IWMDRMWriter3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDRMWriter3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDRMWriter3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDRMWriter3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDRMWriter3_GenerateKeySeed(This,pwszKeySeed,pcwchLength)	\
    ( (This)->lpVtbl -> GenerateKeySeed(This,pwszKeySeed,pcwchLength) ) 

#define IWMDRMWriter3_GenerateKeyID(This,pwszKeyID,pcwchLength)	\
    ( (This)->lpVtbl -> GenerateKeyID(This,pwszKeyID,pcwchLength) ) 

#define IWMDRMWriter3_GenerateSigningKeyPair(This,pwszPrivKey,pcwchPrivKeyLength,pwszPubKey,pcwchPubKeyLength)	\
    ( (This)->lpVtbl -> GenerateSigningKeyPair(This,pwszPrivKey,pcwchPrivKeyLength,pwszPubKey,pcwchPubKeyLength) ) 

#define IWMDRMWriter3_SetDRMAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetDRMAttribute(This,wStreamNum,pszName,Type,pValue,cbLength) ) 


#define IWMDRMWriter3_SetWMDRMNetEncryption(This,fSamplesEncrypted,pbKeyID,cbKeyID)	\
    ( (This)->lpVtbl -> SetWMDRMNetEncryption(This,fSamplesEncrypted,pbKeyID,cbKeyID) ) 


#define IWMDRMWriter3_SetProtectStreamSamples(This,pImportInitStruct)	\
    ( (This)->lpVtbl -> SetProtectStreamSamples(This,pImportInitStruct) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDRMWriter3_INTERFACE_DEFINED__ */


#ifndef __IWMInputMediaProps_INTERFACE_DEFINED__
#define __IWMInputMediaProps_INTERFACE_DEFINED__

/* interface IWMInputMediaProps */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMInputMediaProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BD5-2B2B-11d3-B36B-00C04F6108FF")
    IWMInputMediaProps : public IWMMediaProps
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConnectionName( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGroupName( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMInputMediaPropsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMInputMediaProps * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMInputMediaProps * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMInputMediaProps * This);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, GetType)
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IWMInputMediaProps * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidType);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, GetMediaType)
        HRESULT ( STDMETHODCALLTYPE *GetMediaType )( 
            IWMInputMediaProps * This,
            /* [annotation][out] */ 
            _Out_  WM_MEDIA_TYPE *pType,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbType);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, SetMediaType)
        HRESULT ( STDMETHODCALLTYPE *SetMediaType )( 
            IWMInputMediaProps * This,
            /* [annotation][in] */ 
            _In_  WM_MEDIA_TYPE *pType);
        
        DECLSPEC_XFGVIRT(IWMInputMediaProps, GetConnectionName)
        HRESULT ( STDMETHODCALLTYPE *GetConnectionName )( 
            IWMInputMediaProps * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName);
        
        DECLSPEC_XFGVIRT(IWMInputMediaProps, GetGroupName)
        HRESULT ( STDMETHODCALLTYPE *GetGroupName )( 
            IWMInputMediaProps * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName);
        
        END_INTERFACE
    } IWMInputMediaPropsVtbl;

    interface IWMInputMediaProps
    {
        CONST_VTBL struct IWMInputMediaPropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMInputMediaProps_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMInputMediaProps_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMInputMediaProps_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMInputMediaProps_GetType(This,pguidType)	\
    ( (This)->lpVtbl -> GetType(This,pguidType) ) 

#define IWMInputMediaProps_GetMediaType(This,pType,pcbType)	\
    ( (This)->lpVtbl -> GetMediaType(This,pType,pcbType) ) 

#define IWMInputMediaProps_SetMediaType(This,pType)	\
    ( (This)->lpVtbl -> SetMediaType(This,pType) ) 


#define IWMInputMediaProps_GetConnectionName(This,pwszName,pcchName)	\
    ( (This)->lpVtbl -> GetConnectionName(This,pwszName,pcchName) ) 

#define IWMInputMediaProps_GetGroupName(This,pwszName,pcchName)	\
    ( (This)->lpVtbl -> GetGroupName(This,pwszName,pcchName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMInputMediaProps_INTERFACE_DEFINED__ */


#ifndef __IWMPropertyVault_INTERFACE_DEFINED__
#define __IWMPropertyVault_INTERFACE_DEFINED__

/* interface IWMPropertyVault */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMPropertyVault;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("72995A79-5090-42a4-9C8C-D9D0B6D34BE5")
    IWMPropertyVault : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPropertyCount( 
            /* [annotation][in] */ 
            _In_  DWORD *pdwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyByName( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE pType,
            /* [annotation][in] */ 
            _In_  BYTE *pValue,
            /* [annotation][in] */ 
            _In_  DWORD dwSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyByIndex( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwNameLen)  LPWSTR pszName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwNameLen,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyPropertiesFrom( 
            /* [annotation][in] */ 
            _In_  IWMPropertyVault *pIWMPropertyVault) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMPropertyVaultVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMPropertyVault * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMPropertyVault * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMPropertyVault * This);
        
        DECLSPEC_XFGVIRT(IWMPropertyVault, GetPropertyCount)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyCount )( 
            IWMPropertyVault * This,
            /* [annotation][in] */ 
            _In_  DWORD *pdwCount);
        
        DECLSPEC_XFGVIRT(IWMPropertyVault, GetPropertyByName)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyByName )( 
            IWMPropertyVault * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize);
        
        DECLSPEC_XFGVIRT(IWMPropertyVault, SetProperty)
        HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            IWMPropertyVault * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE pType,
            /* [annotation][in] */ 
            _In_  BYTE *pValue,
            /* [annotation][in] */ 
            _In_  DWORD dwSize);
        
        DECLSPEC_XFGVIRT(IWMPropertyVault, GetPropertyByIndex)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyByIndex )( 
            IWMPropertyVault * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwNameLen)  LPWSTR pszName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwNameLen,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize);
        
        DECLSPEC_XFGVIRT(IWMPropertyVault, CopyPropertiesFrom)
        HRESULT ( STDMETHODCALLTYPE *CopyPropertiesFrom )( 
            IWMPropertyVault * This,
            /* [annotation][in] */ 
            _In_  IWMPropertyVault *pIWMPropertyVault);
        
        DECLSPEC_XFGVIRT(IWMPropertyVault, Clear)
        HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IWMPropertyVault * This);
        
        END_INTERFACE
    } IWMPropertyVaultVtbl;

    interface IWMPropertyVault
    {
        CONST_VTBL struct IWMPropertyVaultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMPropertyVault_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMPropertyVault_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMPropertyVault_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMPropertyVault_GetPropertyCount(This,pdwCount)	\
    ( (This)->lpVtbl -> GetPropertyCount(This,pdwCount) ) 

#define IWMPropertyVault_GetPropertyByName(This,pszName,pType,pValue,pdwSize)	\
    ( (This)->lpVtbl -> GetPropertyByName(This,pszName,pType,pValue,pdwSize) ) 

#define IWMPropertyVault_SetProperty(This,pszName,pType,pValue,dwSize)	\
    ( (This)->lpVtbl -> SetProperty(This,pszName,pType,pValue,dwSize) ) 

#define IWMPropertyVault_GetPropertyByIndex(This,dwIndex,pszName,pdwNameLen,pType,pValue,pdwSize)	\
    ( (This)->lpVtbl -> GetPropertyByIndex(This,dwIndex,pszName,pdwNameLen,pType,pValue,pdwSize) ) 

#define IWMPropertyVault_CopyPropertiesFrom(This,pIWMPropertyVault)	\
    ( (This)->lpVtbl -> CopyPropertiesFrom(This,pIWMPropertyVault) ) 

#define IWMPropertyVault_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMPropertyVault_INTERFACE_DEFINED__ */


#ifndef __IWMIStreamProps_INTERFACE_DEFINED__
#define __IWMIStreamProps_INTERFACE_DEFINED__

/* interface IWMIStreamProps */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMIStreamProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6816dad3-2b4b-4c8e-8149-874c3483a753")
    IWMIStreamProps : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMIStreamPropsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMIStreamProps * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMIStreamProps * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMIStreamProps * This);
        
        DECLSPEC_XFGVIRT(IWMIStreamProps, GetProperty)
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IWMIStreamProps * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize);
        
        END_INTERFACE
    } IWMIStreamPropsVtbl;

    interface IWMIStreamProps
    {
        CONST_VTBL struct IWMIStreamPropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMIStreamProps_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMIStreamProps_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMIStreamProps_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMIStreamProps_GetProperty(This,pszName,pType,pValue,pdwSize)	\
    ( (This)->lpVtbl -> GetProperty(This,pszName,pType,pValue,pdwSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMIStreamProps_INTERFACE_DEFINED__ */


#ifndef __IWMReader_INTERFACE_DEFINED__
#define __IWMReader_INTERFACE_DEFINED__

/* interface IWMReader */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BD6-2B2B-11d3-B36B-00C04F6108FF")
    IWMReader : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszURL,
            /* [annotation][in] */ 
            _In_  IWMReaderCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcOutputs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputProps( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  IWMOutputMediaProps **ppOutput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutputProps( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMOutputMediaProps *pOutput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputFormatCount( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNumber,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputFormat( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNumber,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatNumber,
            /* [annotation][out] */ 
            _Out_  IWMOutputMediaProps **ppProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( 
            /* [annotation][in] */ 
            _In_  QWORD cnsStart,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReader * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReader * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReader * This);
        
        DECLSPEC_XFGVIRT(IWMReader, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWMReader * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszURL,
            /* [annotation][in] */ 
            _In_  IWMReaderCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReader, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWMReader * This);
        
        DECLSPEC_XFGVIRT(IWMReader, GetOutputCount)
        HRESULT ( STDMETHODCALLTYPE *GetOutputCount )( 
            IWMReader * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcOutputs);
        
        DECLSPEC_XFGVIRT(IWMReader, GetOutputProps)
        HRESULT ( STDMETHODCALLTYPE *GetOutputProps )( 
            IWMReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  IWMOutputMediaProps **ppOutput);
        
        DECLSPEC_XFGVIRT(IWMReader, SetOutputProps)
        HRESULT ( STDMETHODCALLTYPE *SetOutputProps )( 
            IWMReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMOutputMediaProps *pOutput);
        
        DECLSPEC_XFGVIRT(IWMReader, GetOutputFormatCount)
        HRESULT ( STDMETHODCALLTYPE *GetOutputFormatCount )( 
            IWMReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNumber,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormats);
        
        DECLSPEC_XFGVIRT(IWMReader, GetOutputFormat)
        HRESULT ( STDMETHODCALLTYPE *GetOutputFormat )( 
            IWMReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNumber,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatNumber,
            /* [annotation][out] */ 
            _Out_  IWMOutputMediaProps **ppProps);
        
        DECLSPEC_XFGVIRT(IWMReader, Start)
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IWMReader * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStart,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReader, Stop)
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IWMReader * This);
        
        DECLSPEC_XFGVIRT(IWMReader, Pause)
        HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IWMReader * This);
        
        DECLSPEC_XFGVIRT(IWMReader, Resume)
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            IWMReader * This);
        
        END_INTERFACE
    } IWMReaderVtbl;

    interface IWMReader
    {
        CONST_VTBL struct IWMReaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReader_Open(This,pwszURL,pCallback,pvContext)	\
    ( (This)->lpVtbl -> Open(This,pwszURL,pCallback,pvContext) ) 

#define IWMReader_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IWMReader_GetOutputCount(This,pcOutputs)	\
    ( (This)->lpVtbl -> GetOutputCount(This,pcOutputs) ) 

#define IWMReader_GetOutputProps(This,dwOutputNum,ppOutput)	\
    ( (This)->lpVtbl -> GetOutputProps(This,dwOutputNum,ppOutput) ) 

#define IWMReader_SetOutputProps(This,dwOutputNum,pOutput)	\
    ( (This)->lpVtbl -> SetOutputProps(This,dwOutputNum,pOutput) ) 

#define IWMReader_GetOutputFormatCount(This,dwOutputNumber,pcFormats)	\
    ( (This)->lpVtbl -> GetOutputFormatCount(This,dwOutputNumber,pcFormats) ) 

#define IWMReader_GetOutputFormat(This,dwOutputNumber,dwFormatNumber,ppProps)	\
    ( (This)->lpVtbl -> GetOutputFormat(This,dwOutputNumber,dwFormatNumber,ppProps) ) 

#define IWMReader_Start(This,cnsStart,cnsDuration,fRate,pvContext)	\
    ( (This)->lpVtbl -> Start(This,cnsStart,cnsDuration,fRate,pvContext) ) 

#define IWMReader_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IWMReader_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IWMReader_Resume(This)	\
    ( (This)->lpVtbl -> Resume(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReader_INTERFACE_DEFINED__ */


#ifndef __IWMSyncReader_INTERFACE_DEFINED__
#define __IWMSyncReader_INTERFACE_DEFINED__

/* interface IWMSyncReader */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMSyncReader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9397F121-7705-4dc9-B049-98B698188414")
    IWMSyncReader : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRange( 
            /* [annotation][in] */ 
            _In_  QWORD cnsStartTime,
            /* [annotation][in] */ 
            _In_  LONGLONG cnsDuration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRangeByFrame( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  QWORD qwFrameNumber,
            /* [annotation][in] */ 
            _In_  LONGLONG cFramesToRead) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextSample( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppSample,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsSampleTime,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDuration,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwOutputNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStreamsSelected( 
            /* [annotation][in] */ 
            _In_  WORD cStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pwStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamSelected( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WMT_STREAM_SELECTION *pSelection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetReadStreamSamples( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fCompressed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetReadStreamSamples( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfCompressed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputSetting( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutputSetting( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcOutputs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputProps( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  IWMOutputMediaProps **ppOutput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutputProps( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMOutputMediaProps *pOutput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputFormatCount( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputFormat( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatNum,
            /* [annotation][out] */ 
            _Out_  IWMOutputMediaProps **ppProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputNumberForStream( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwOutputNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamNumberForOutput( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxOutputSampleSize( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxStreamSampleSize( 
            /* [annotation][in] */ 
            _In_  WORD wStream,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenStream( 
            /* [annotation][in] */ 
            _In_  IStream *pStream) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMSyncReaderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMSyncReader * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMSyncReader * This);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWMSyncReader * This);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetRange)
        HRESULT ( STDMETHODCALLTYPE *SetRange )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStartTime,
            /* [annotation][in] */ 
            _In_  LONGLONG cnsDuration);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetRangeByFrame)
        HRESULT ( STDMETHODCALLTYPE *SetRangeByFrame )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  QWORD qwFrameNumber,
            /* [annotation][in] */ 
            _In_  LONGLONG cFramesToRead);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetNextSample)
        HRESULT ( STDMETHODCALLTYPE *GetNextSample )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppSample,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsSampleTime,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDuration,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwOutputNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetStreamsSelected)
        HRESULT ( STDMETHODCALLTYPE *SetStreamsSelected )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  WORD cStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pwStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetStreamSelected)
        HRESULT ( STDMETHODCALLTYPE *GetStreamSelected )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WMT_STREAM_SELECTION *pSelection);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetReadStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *SetReadStreamSamples )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fCompressed);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetReadStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *GetReadStreamSamples )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfCompressed);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *GetOutputSetting )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *SetOutputSetting )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputCount)
        HRESULT ( STDMETHODCALLTYPE *GetOutputCount )( 
            IWMSyncReader * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcOutputs);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputProps)
        HRESULT ( STDMETHODCALLTYPE *GetOutputProps )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  IWMOutputMediaProps **ppOutput);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetOutputProps)
        HRESULT ( STDMETHODCALLTYPE *SetOutputProps )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMOutputMediaProps *pOutput);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputFormatCount)
        HRESULT ( STDMETHODCALLTYPE *GetOutputFormatCount )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormats);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputFormat)
        HRESULT ( STDMETHODCALLTYPE *GetOutputFormat )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatNum,
            /* [annotation][out] */ 
            _Out_  IWMOutputMediaProps **ppProps);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputNumberForStream)
        HRESULT ( STDMETHODCALLTYPE *GetOutputNumberForStream )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwOutputNum);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetStreamNumberForOutput)
        HRESULT ( STDMETHODCALLTYPE *GetStreamNumberForOutput )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetMaxOutputSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxOutputSampleSize )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetMaxStreamSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxStreamSampleSize )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  WORD wStream,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, OpenStream)
        HRESULT ( STDMETHODCALLTYPE *OpenStream )( 
            IWMSyncReader * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream);
        
        END_INTERFACE
    } IWMSyncReaderVtbl;

    interface IWMSyncReader
    {
        CONST_VTBL struct IWMSyncReaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMSyncReader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMSyncReader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMSyncReader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMSyncReader_Open(This,pwszFilename)	\
    ( (This)->lpVtbl -> Open(This,pwszFilename) ) 

#define IWMSyncReader_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IWMSyncReader_SetRange(This,cnsStartTime,cnsDuration)	\
    ( (This)->lpVtbl -> SetRange(This,cnsStartTime,cnsDuration) ) 

#define IWMSyncReader_SetRangeByFrame(This,wStreamNum,qwFrameNumber,cFramesToRead)	\
    ( (This)->lpVtbl -> SetRangeByFrame(This,wStreamNum,qwFrameNumber,cFramesToRead) ) 

#define IWMSyncReader_GetNextSample(This,wStreamNum,ppSample,pcnsSampleTime,pcnsDuration,pdwFlags,pdwOutputNum,pwStreamNum)	\
    ( (This)->lpVtbl -> GetNextSample(This,wStreamNum,ppSample,pcnsSampleTime,pcnsDuration,pdwFlags,pdwOutputNum,pwStreamNum) ) 

#define IWMSyncReader_SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections)	\
    ( (This)->lpVtbl -> SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections) ) 

#define IWMSyncReader_GetStreamSelected(This,wStreamNum,pSelection)	\
    ( (This)->lpVtbl -> GetStreamSelected(This,wStreamNum,pSelection) ) 

#define IWMSyncReader_SetReadStreamSamples(This,wStreamNum,fCompressed)	\
    ( (This)->lpVtbl -> SetReadStreamSamples(This,wStreamNum,fCompressed) ) 

#define IWMSyncReader_GetReadStreamSamples(This,wStreamNum,pfCompressed)	\
    ( (This)->lpVtbl -> GetReadStreamSamples(This,wStreamNum,pfCompressed) ) 

#define IWMSyncReader_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength) ) 

#define IWMSyncReader_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength) ) 

#define IWMSyncReader_GetOutputCount(This,pcOutputs)	\
    ( (This)->lpVtbl -> GetOutputCount(This,pcOutputs) ) 

#define IWMSyncReader_GetOutputProps(This,dwOutputNum,ppOutput)	\
    ( (This)->lpVtbl -> GetOutputProps(This,dwOutputNum,ppOutput) ) 

#define IWMSyncReader_SetOutputProps(This,dwOutputNum,pOutput)	\
    ( (This)->lpVtbl -> SetOutputProps(This,dwOutputNum,pOutput) ) 

#define IWMSyncReader_GetOutputFormatCount(This,dwOutputNum,pcFormats)	\
    ( (This)->lpVtbl -> GetOutputFormatCount(This,dwOutputNum,pcFormats) ) 

#define IWMSyncReader_GetOutputFormat(This,dwOutputNum,dwFormatNum,ppProps)	\
    ( (This)->lpVtbl -> GetOutputFormat(This,dwOutputNum,dwFormatNum,ppProps) ) 

#define IWMSyncReader_GetOutputNumberForStream(This,wStreamNum,pdwOutputNum)	\
    ( (This)->lpVtbl -> GetOutputNumberForStream(This,wStreamNum,pdwOutputNum) ) 

#define IWMSyncReader_GetStreamNumberForOutput(This,dwOutputNum,pwStreamNum)	\
    ( (This)->lpVtbl -> GetStreamNumberForOutput(This,dwOutputNum,pwStreamNum) ) 

#define IWMSyncReader_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax) ) 

#define IWMSyncReader_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax) ) 

#define IWMSyncReader_OpenStream(This,pStream)	\
    ( (This)->lpVtbl -> OpenStream(This,pStream) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMSyncReader_INTERFACE_DEFINED__ */


#ifndef __IWMSyncReader2_INTERFACE_DEFINED__
#define __IWMSyncReader2_INTERFACE_DEFINED__

/* interface IWMSyncReader2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMSyncReader2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("faed3d21-1b6b-4af7-8cb6-3e189bbc187b")
    IWMSyncReader2 : public IWMSyncReader
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetRangeByTimecode( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WMT_TIMECODE_EXTENSION_DATA *pStart,
            /* [annotation][in] */ 
            _In_  WMT_TIMECODE_EXTENSION_DATA *pEnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRangeByFrameEx( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  QWORD qwFrameNumber,
            /* [annotation][in] */ 
            _In_  LONGLONG cFramesToRead,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsStartTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAllocateForOutput( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMReaderAllocatorEx *pAllocator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllocateForOutput( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  IWMReaderAllocatorEx **ppAllocator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAllocateForStream( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  IWMReaderAllocatorEx *pAllocator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllocateForStream( 
            /* [annotation][in] */ 
            _In_  WORD dwSreamNum,
            /* [annotation][out] */ 
            _Out_  IWMReaderAllocatorEx **ppAllocator) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMSyncReader2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMSyncReader2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMSyncReader2 * This);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWMSyncReader2 * This);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetRange)
        HRESULT ( STDMETHODCALLTYPE *SetRange )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStartTime,
            /* [annotation][in] */ 
            _In_  LONGLONG cnsDuration);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetRangeByFrame)
        HRESULT ( STDMETHODCALLTYPE *SetRangeByFrame )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  QWORD qwFrameNumber,
            /* [annotation][in] */ 
            _In_  LONGLONG cFramesToRead);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetNextSample)
        HRESULT ( STDMETHODCALLTYPE *GetNextSample )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppSample,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsSampleTime,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDuration,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwOutputNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetStreamsSelected)
        HRESULT ( STDMETHODCALLTYPE *SetStreamsSelected )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD cStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pwStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetStreamSelected)
        HRESULT ( STDMETHODCALLTYPE *GetStreamSelected )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WMT_STREAM_SELECTION *pSelection);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetReadStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *SetReadStreamSamples )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fCompressed);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetReadStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *GetReadStreamSamples )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfCompressed);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *GetOutputSetting )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *SetOutputSetting )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputCount)
        HRESULT ( STDMETHODCALLTYPE *GetOutputCount )( 
            IWMSyncReader2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcOutputs);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputProps)
        HRESULT ( STDMETHODCALLTYPE *GetOutputProps )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  IWMOutputMediaProps **ppOutput);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, SetOutputProps)
        HRESULT ( STDMETHODCALLTYPE *SetOutputProps )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMOutputMediaProps *pOutput);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputFormatCount)
        HRESULT ( STDMETHODCALLTYPE *GetOutputFormatCount )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormats);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputFormat)
        HRESULT ( STDMETHODCALLTYPE *GetOutputFormat )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatNum,
            /* [annotation][out] */ 
            _Out_  IWMOutputMediaProps **ppProps);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetOutputNumberForStream)
        HRESULT ( STDMETHODCALLTYPE *GetOutputNumberForStream )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwOutputNum);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetStreamNumberForOutput)
        HRESULT ( STDMETHODCALLTYPE *GetStreamNumberForOutput )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetMaxOutputSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxOutputSampleSize )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, GetMaxStreamSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxStreamSampleSize )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStream,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMSyncReader, OpenStream)
        HRESULT ( STDMETHODCALLTYPE *OpenStream )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream);
        
        DECLSPEC_XFGVIRT(IWMSyncReader2, SetRangeByTimecode)
        HRESULT ( STDMETHODCALLTYPE *SetRangeByTimecode )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WMT_TIMECODE_EXTENSION_DATA *pStart,
            /* [annotation][in] */ 
            _In_  WMT_TIMECODE_EXTENSION_DATA *pEnd);
        
        DECLSPEC_XFGVIRT(IWMSyncReader2, SetRangeByFrameEx)
        HRESULT ( STDMETHODCALLTYPE *SetRangeByFrameEx )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  QWORD qwFrameNumber,
            /* [annotation][in] */ 
            _In_  LONGLONG cFramesToRead,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsStartTime);
        
        DECLSPEC_XFGVIRT(IWMSyncReader2, SetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForOutput )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMReaderAllocatorEx *pAllocator);
        
        DECLSPEC_XFGVIRT(IWMSyncReader2, GetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForOutput )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  IWMReaderAllocatorEx **ppAllocator);
        
        DECLSPEC_XFGVIRT(IWMSyncReader2, SetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForStream )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  IWMReaderAllocatorEx *pAllocator);
        
        DECLSPEC_XFGVIRT(IWMSyncReader2, GetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForStream )( 
            IWMSyncReader2 * This,
            /* [annotation][in] */ 
            _In_  WORD dwSreamNum,
            /* [annotation][out] */ 
            _Out_  IWMReaderAllocatorEx **ppAllocator);
        
        END_INTERFACE
    } IWMSyncReader2Vtbl;

    interface IWMSyncReader2
    {
        CONST_VTBL struct IWMSyncReader2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMSyncReader2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMSyncReader2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMSyncReader2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMSyncReader2_Open(This,pwszFilename)	\
    ( (This)->lpVtbl -> Open(This,pwszFilename) ) 

#define IWMSyncReader2_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IWMSyncReader2_SetRange(This,cnsStartTime,cnsDuration)	\
    ( (This)->lpVtbl -> SetRange(This,cnsStartTime,cnsDuration) ) 

#define IWMSyncReader2_SetRangeByFrame(This,wStreamNum,qwFrameNumber,cFramesToRead)	\
    ( (This)->lpVtbl -> SetRangeByFrame(This,wStreamNum,qwFrameNumber,cFramesToRead) ) 

#define IWMSyncReader2_GetNextSample(This,wStreamNum,ppSample,pcnsSampleTime,pcnsDuration,pdwFlags,pdwOutputNum,pwStreamNum)	\
    ( (This)->lpVtbl -> GetNextSample(This,wStreamNum,ppSample,pcnsSampleTime,pcnsDuration,pdwFlags,pdwOutputNum,pwStreamNum) ) 

#define IWMSyncReader2_SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections)	\
    ( (This)->lpVtbl -> SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections) ) 

#define IWMSyncReader2_GetStreamSelected(This,wStreamNum,pSelection)	\
    ( (This)->lpVtbl -> GetStreamSelected(This,wStreamNum,pSelection) ) 

#define IWMSyncReader2_SetReadStreamSamples(This,wStreamNum,fCompressed)	\
    ( (This)->lpVtbl -> SetReadStreamSamples(This,wStreamNum,fCompressed) ) 

#define IWMSyncReader2_GetReadStreamSamples(This,wStreamNum,pfCompressed)	\
    ( (This)->lpVtbl -> GetReadStreamSamples(This,wStreamNum,pfCompressed) ) 

#define IWMSyncReader2_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength) ) 

#define IWMSyncReader2_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength) ) 

#define IWMSyncReader2_GetOutputCount(This,pcOutputs)	\
    ( (This)->lpVtbl -> GetOutputCount(This,pcOutputs) ) 

#define IWMSyncReader2_GetOutputProps(This,dwOutputNum,ppOutput)	\
    ( (This)->lpVtbl -> GetOutputProps(This,dwOutputNum,ppOutput) ) 

#define IWMSyncReader2_SetOutputProps(This,dwOutputNum,pOutput)	\
    ( (This)->lpVtbl -> SetOutputProps(This,dwOutputNum,pOutput) ) 

#define IWMSyncReader2_GetOutputFormatCount(This,dwOutputNum,pcFormats)	\
    ( (This)->lpVtbl -> GetOutputFormatCount(This,dwOutputNum,pcFormats) ) 

#define IWMSyncReader2_GetOutputFormat(This,dwOutputNum,dwFormatNum,ppProps)	\
    ( (This)->lpVtbl -> GetOutputFormat(This,dwOutputNum,dwFormatNum,ppProps) ) 

#define IWMSyncReader2_GetOutputNumberForStream(This,wStreamNum,pdwOutputNum)	\
    ( (This)->lpVtbl -> GetOutputNumberForStream(This,wStreamNum,pdwOutputNum) ) 

#define IWMSyncReader2_GetStreamNumberForOutput(This,dwOutputNum,pwStreamNum)	\
    ( (This)->lpVtbl -> GetStreamNumberForOutput(This,dwOutputNum,pwStreamNum) ) 

#define IWMSyncReader2_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax) ) 

#define IWMSyncReader2_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax) ) 

#define IWMSyncReader2_OpenStream(This,pStream)	\
    ( (This)->lpVtbl -> OpenStream(This,pStream) ) 


#define IWMSyncReader2_SetRangeByTimecode(This,wStreamNum,pStart,pEnd)	\
    ( (This)->lpVtbl -> SetRangeByTimecode(This,wStreamNum,pStart,pEnd) ) 

#define IWMSyncReader2_SetRangeByFrameEx(This,wStreamNum,qwFrameNumber,cFramesToRead,pcnsStartTime)	\
    ( (This)->lpVtbl -> SetRangeByFrameEx(This,wStreamNum,qwFrameNumber,cFramesToRead,pcnsStartTime) ) 

#define IWMSyncReader2_SetAllocateForOutput(This,dwOutputNum,pAllocator)	\
    ( (This)->lpVtbl -> SetAllocateForOutput(This,dwOutputNum,pAllocator) ) 

#define IWMSyncReader2_GetAllocateForOutput(This,dwOutputNum,ppAllocator)	\
    ( (This)->lpVtbl -> GetAllocateForOutput(This,dwOutputNum,ppAllocator) ) 

#define IWMSyncReader2_SetAllocateForStream(This,wStreamNum,pAllocator)	\
    ( (This)->lpVtbl -> SetAllocateForStream(This,wStreamNum,pAllocator) ) 

#define IWMSyncReader2_GetAllocateForStream(This,dwSreamNum,ppAllocator)	\
    ( (This)->lpVtbl -> GetAllocateForStream(This,dwSreamNum,ppAllocator) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMSyncReader2_INTERFACE_DEFINED__ */


#ifndef __IWMOutputMediaProps_INTERFACE_DEFINED__
#define __IWMOutputMediaProps_INTERFACE_DEFINED__

/* interface IWMOutputMediaProps */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMOutputMediaProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BD7-2B2B-11d3-B36B-00C04F6108FF")
    IWMOutputMediaProps : public IWMMediaProps
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStreamGroupName( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConnectionName( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMOutputMediaPropsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMOutputMediaProps * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMOutputMediaProps * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMOutputMediaProps * This);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, GetType)
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IWMOutputMediaProps * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidType);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, GetMediaType)
        HRESULT ( STDMETHODCALLTYPE *GetMediaType )( 
            IWMOutputMediaProps * This,
            /* [annotation][out] */ 
            _Out_  WM_MEDIA_TYPE *pType,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbType);
        
        DECLSPEC_XFGVIRT(IWMMediaProps, SetMediaType)
        HRESULT ( STDMETHODCALLTYPE *SetMediaType )( 
            IWMOutputMediaProps * This,
            /* [annotation][in] */ 
            _In_  WM_MEDIA_TYPE *pType);
        
        DECLSPEC_XFGVIRT(IWMOutputMediaProps, GetStreamGroupName)
        HRESULT ( STDMETHODCALLTYPE *GetStreamGroupName )( 
            IWMOutputMediaProps * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName);
        
        DECLSPEC_XFGVIRT(IWMOutputMediaProps, GetConnectionName)
        HRESULT ( STDMETHODCALLTYPE *GetConnectionName )( 
            IWMOutputMediaProps * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName);
        
        END_INTERFACE
    } IWMOutputMediaPropsVtbl;

    interface IWMOutputMediaProps
    {
        CONST_VTBL struct IWMOutputMediaPropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMOutputMediaProps_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMOutputMediaProps_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMOutputMediaProps_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMOutputMediaProps_GetType(This,pguidType)	\
    ( (This)->lpVtbl -> GetType(This,pguidType) ) 

#define IWMOutputMediaProps_GetMediaType(This,pType,pcbType)	\
    ( (This)->lpVtbl -> GetMediaType(This,pType,pcbType) ) 

#define IWMOutputMediaProps_SetMediaType(This,pType)	\
    ( (This)->lpVtbl -> SetMediaType(This,pType) ) 


#define IWMOutputMediaProps_GetStreamGroupName(This,pwszName,pcchName)	\
    ( (This)->lpVtbl -> GetStreamGroupName(This,pwszName,pcchName) ) 

#define IWMOutputMediaProps_GetConnectionName(This,pwszName,pcchName)	\
    ( (This)->lpVtbl -> GetConnectionName(This,pwszName,pcchName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMOutputMediaProps_INTERFACE_DEFINED__ */


#ifndef __IWMStatusCallback_INTERFACE_DEFINED__
#define __IWMStatusCallback_INTERFACE_DEFINED__

/* interface IWMStatusCallback */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMStatusCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6d7cdc70-9888-11d3-8edc-00c04f6109cf")
    IWMStatusCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnStatus( 
            /* [annotation][in] */ 
            _In_  WMT_STATUS Status,
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE dwType,
            /* [annotation][in] */ 
            _In_  BYTE *pValue,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMStatusCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMStatusCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMStatusCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMStatusCallback * This);
        
        DECLSPEC_XFGVIRT(IWMStatusCallback, OnStatus)
        HRESULT ( STDMETHODCALLTYPE *OnStatus )( 
            IWMStatusCallback * This,
            /* [annotation][in] */ 
            _In_  WMT_STATUS Status,
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE dwType,
            /* [annotation][in] */ 
            _In_  BYTE *pValue,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        END_INTERFACE
    } IWMStatusCallbackVtbl;

    interface IWMStatusCallback
    {
        CONST_VTBL struct IWMStatusCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMStatusCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMStatusCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMStatusCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMStatusCallback_OnStatus(This,Status,hr,dwType,pValue,pvContext)	\
    ( (This)->lpVtbl -> OnStatus(This,Status,hr,dwType,pValue,pvContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMStatusCallback_INTERFACE_DEFINED__ */


#ifndef __IWMReaderCallback_INTERFACE_DEFINED__
#define __IWMReaderCallback_INTERFACE_DEFINED__

/* interface IWMReaderCallback */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BD8-2B2B-11d3-B36B-00C04F6108FF")
    IWMReaderCallback : public IWMStatusCallback
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSample( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderCallback * This);
        
        DECLSPEC_XFGVIRT(IWMStatusCallback, OnStatus)
        HRESULT ( STDMETHODCALLTYPE *OnStatus )( 
            IWMReaderCallback * This,
            /* [annotation][in] */ 
            _In_  WMT_STATUS Status,
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE dwType,
            /* [annotation][in] */ 
            _In_  BYTE *pValue,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderCallback, OnSample)
        HRESULT ( STDMETHODCALLTYPE *OnSample )( 
            IWMReaderCallback * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        END_INTERFACE
    } IWMReaderCallbackVtbl;

    interface IWMReaderCallback
    {
        CONST_VTBL struct IWMReaderCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderCallback_OnStatus(This,Status,hr,dwType,pValue,pvContext)	\
    ( (This)->lpVtbl -> OnStatus(This,Status,hr,dwType,pValue,pvContext) ) 


#define IWMReaderCallback_OnSample(This,dwOutputNum,cnsSampleTime,cnsSampleDuration,dwFlags,pSample,pvContext)	\
    ( (This)->lpVtbl -> OnSample(This,dwOutputNum,cnsSampleTime,cnsSampleDuration,dwFlags,pSample,pvContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderCallback_INTERFACE_DEFINED__ */


#ifndef __IWMCredentialCallback_INTERFACE_DEFINED__
#define __IWMCredentialCallback_INTERFACE_DEFINED__

/* interface IWMCredentialCallback */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMCredentialCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("342e0eb7-e651-450c-975b-2ace2c90c48e")
    IWMCredentialCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AcquireCredentials( 
            /* [annotation][in] */ 
            _In_  WCHAR *pwszRealm,
            /* [annotation][in] */ 
            _In_  WCHAR *pwszSite,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cchUser)  WCHAR *pwszUser,
            /* [annotation][in] */ 
            _In_  DWORD cchUser,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cchPassword)  WCHAR *pwszPassword,
            /* [annotation][in] */ 
            _In_  DWORD cchPassword,
            /* [annotation][in] */ 
            _In_  HRESULT hrStatus,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMCredentialCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMCredentialCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMCredentialCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMCredentialCallback * This);
        
        DECLSPEC_XFGVIRT(IWMCredentialCallback, AcquireCredentials)
        HRESULT ( STDMETHODCALLTYPE *AcquireCredentials )( 
            IWMCredentialCallback * This,
            /* [annotation][in] */ 
            _In_  WCHAR *pwszRealm,
            /* [annotation][in] */ 
            _In_  WCHAR *pwszSite,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cchUser)  WCHAR *pwszUser,
            /* [annotation][in] */ 
            _In_  DWORD cchUser,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cchPassword)  WCHAR *pwszPassword,
            /* [annotation][in] */ 
            _In_  DWORD cchPassword,
            /* [annotation][in] */ 
            _In_  HRESULT hrStatus,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags);
        
        END_INTERFACE
    } IWMCredentialCallbackVtbl;

    interface IWMCredentialCallback
    {
        CONST_VTBL struct IWMCredentialCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMCredentialCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMCredentialCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMCredentialCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMCredentialCallback_AcquireCredentials(This,pwszRealm,pwszSite,pwszUser,cchUser,pwszPassword,cchPassword,hrStatus,pdwFlags)	\
    ( (This)->lpVtbl -> AcquireCredentials(This,pwszRealm,pwszSite,pwszUser,cchUser,pwszPassword,cchPassword,hrStatus,pdwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMCredentialCallback_INTERFACE_DEFINED__ */


#ifndef __IWMMetadataEditor_INTERFACE_DEFINED__
#define __IWMMetadataEditor_INTERFACE_DEFINED__

/* interface IWMMetadataEditor */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMMetadataEditor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BD9-2B2B-11d3-B36B-00C04F6108FF")
    IWMMetadataEditor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Flush( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMMetadataEditorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMMetadataEditor * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMMetadataEditor * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMMetadataEditor * This);
        
        DECLSPEC_XFGVIRT(IWMMetadataEditor, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWMMetadataEditor * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMMetadataEditor, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWMMetadataEditor * This);
        
        DECLSPEC_XFGVIRT(IWMMetadataEditor, Flush)
        HRESULT ( STDMETHODCALLTYPE *Flush )( 
            IWMMetadataEditor * This);
        
        END_INTERFACE
    } IWMMetadataEditorVtbl;

    interface IWMMetadataEditor
    {
        CONST_VTBL struct IWMMetadataEditorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMMetadataEditor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMMetadataEditor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMMetadataEditor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMMetadataEditor_Open(This,pwszFilename)	\
    ( (This)->lpVtbl -> Open(This,pwszFilename) ) 

#define IWMMetadataEditor_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IWMMetadataEditor_Flush(This)	\
    ( (This)->lpVtbl -> Flush(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMMetadataEditor_INTERFACE_DEFINED__ */


#ifndef __IWMMetadataEditor2_INTERFACE_DEFINED__
#define __IWMMetadataEditor2_INTERFACE_DEFINED__

/* interface IWMMetadataEditor2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMMetadataEditor2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("203CFFE3-2E18-4fdf-B59D-6E71530534CF")
    IWMMetadataEditor2 : public IWMMetadataEditor
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OpenEx( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename,
            /* [annotation][in] */ 
            _In_  DWORD dwDesiredAccess,
            /* [annotation][in] */ 
            _In_  DWORD dwShareMode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMMetadataEditor2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMMetadataEditor2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMMetadataEditor2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMMetadataEditor2 * This);
        
        DECLSPEC_XFGVIRT(IWMMetadataEditor, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWMMetadataEditor2 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMMetadataEditor, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWMMetadataEditor2 * This);
        
        DECLSPEC_XFGVIRT(IWMMetadataEditor, Flush)
        HRESULT ( STDMETHODCALLTYPE *Flush )( 
            IWMMetadataEditor2 * This);
        
        DECLSPEC_XFGVIRT(IWMMetadataEditor2, OpenEx)
        HRESULT ( STDMETHODCALLTYPE *OpenEx )( 
            IWMMetadataEditor2 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename,
            /* [annotation][in] */ 
            _In_  DWORD dwDesiredAccess,
            /* [annotation][in] */ 
            _In_  DWORD dwShareMode);
        
        END_INTERFACE
    } IWMMetadataEditor2Vtbl;

    interface IWMMetadataEditor2
    {
        CONST_VTBL struct IWMMetadataEditor2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMMetadataEditor2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMMetadataEditor2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMMetadataEditor2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMMetadataEditor2_Open(This,pwszFilename)	\
    ( (This)->lpVtbl -> Open(This,pwszFilename) ) 

#define IWMMetadataEditor2_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IWMMetadataEditor2_Flush(This)	\
    ( (This)->lpVtbl -> Flush(This) ) 


#define IWMMetadataEditor2_OpenEx(This,pwszFilename,dwDesiredAccess,dwShareMode)	\
    ( (This)->lpVtbl -> OpenEx(This,pwszFilename,dwDesiredAccess,dwShareMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMMetadataEditor2_INTERFACE_DEFINED__ */


#ifndef __IWMDRMEditor_INTERFACE_DEFINED__
#define __IWMDRMEditor_INTERFACE_DEFINED__

/* interface IWMDRMEditor */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDRMEditor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FF130EBC-A6C3-42A6-B401-C3382C3E08B3")
    IWMDRMEditor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDRMProperty( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwstrName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pdwType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDRMEditorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDRMEditor * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDRMEditor * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDRMEditor * This);
        
        DECLSPEC_XFGVIRT(IWMDRMEditor, GetDRMProperty)
        HRESULT ( STDMETHODCALLTYPE *GetDRMProperty )( 
            IWMDRMEditor * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwstrName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pdwType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        END_INTERFACE
    } IWMDRMEditorVtbl;

    interface IWMDRMEditor
    {
        CONST_VTBL struct IWMDRMEditorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDRMEditor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDRMEditor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDRMEditor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDRMEditor_GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDRMEditor_INTERFACE_DEFINED__ */


#ifndef __IWMHeaderInfo_INTERFACE_DEFINED__
#define __IWMHeaderInfo_INTERFACE_DEFINED__

/* interface IWMHeaderInfo */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMHeaderInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BDA-2B2B-11d3-B36B-00C04F6108FF")
    IWMHeaderInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAttributeCount( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WORD *pcAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributeByIndex( 
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwStreamNum,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchNameLen)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchNameLen,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributeByName( 
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttribute( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMarkerCount( 
            /* [annotation][out] */ 
            _Out_  WORD *pcMarkers) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMarker( 
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchMarkerNameLen)  WCHAR *pwszMarkerName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchMarkerNameLen,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsMarkerTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddMarker( 
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszMarkerName,
            /* [annotation][in] */ 
            _In_  QWORD cnsMarkerTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveMarker( 
            /* [annotation][in] */ 
            _In_  WORD wIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetScriptCount( 
            /* [annotation][out] */ 
            _Out_  WORD *pcScripts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetScript( 
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchTypeLen)  WCHAR *pwszType,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchTypeLen,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchCommandLen)  WCHAR *pwszCommand,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchCommandLen,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsScriptTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddScript( 
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszType,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszCommand,
            /* [annotation][in] */ 
            _In_  QWORD cnsScriptTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveScript( 
            /* [annotation][in] */ 
            _In_  WORD wIndex) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMHeaderInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMHeaderInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMHeaderInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMHeaderInfo * This);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetAttributeCount)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeCount )( 
            IWMHeaderInfo * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WORD *pcAttributes);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetAttributeByIndex)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeByIndex )( 
            IWMHeaderInfo * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwStreamNum,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchNameLen)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchNameLen,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetAttributeByName)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeByName )( 
            IWMHeaderInfo * This,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, SetAttribute)
        HRESULT ( STDMETHODCALLTYPE *SetAttribute )( 
            IWMHeaderInfo * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetMarkerCount)
        HRESULT ( STDMETHODCALLTYPE *GetMarkerCount )( 
            IWMHeaderInfo * This,
            /* [annotation][out] */ 
            _Out_  WORD *pcMarkers);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetMarker)
        HRESULT ( STDMETHODCALLTYPE *GetMarker )( 
            IWMHeaderInfo * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchMarkerNameLen)  WCHAR *pwszMarkerName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchMarkerNameLen,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsMarkerTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, AddMarker)
        HRESULT ( STDMETHODCALLTYPE *AddMarker )( 
            IWMHeaderInfo * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszMarkerName,
            /* [annotation][in] */ 
            _In_  QWORD cnsMarkerTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, RemoveMarker)
        HRESULT ( STDMETHODCALLTYPE *RemoveMarker )( 
            IWMHeaderInfo * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetScriptCount)
        HRESULT ( STDMETHODCALLTYPE *GetScriptCount )( 
            IWMHeaderInfo * This,
            /* [annotation][out] */ 
            _Out_  WORD *pcScripts);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetScript)
        HRESULT ( STDMETHODCALLTYPE *GetScript )( 
            IWMHeaderInfo * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchTypeLen)  WCHAR *pwszType,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchTypeLen,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchCommandLen)  WCHAR *pwszCommand,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchCommandLen,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsScriptTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, AddScript)
        HRESULT ( STDMETHODCALLTYPE *AddScript )( 
            IWMHeaderInfo * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszType,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszCommand,
            /* [annotation][in] */ 
            _In_  QWORD cnsScriptTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, RemoveScript)
        HRESULT ( STDMETHODCALLTYPE *RemoveScript )( 
            IWMHeaderInfo * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex);
        
        END_INTERFACE
    } IWMHeaderInfoVtbl;

    interface IWMHeaderInfo
    {
        CONST_VTBL struct IWMHeaderInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMHeaderInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMHeaderInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMHeaderInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMHeaderInfo_GetAttributeCount(This,wStreamNum,pcAttributes)	\
    ( (This)->lpVtbl -> GetAttributeCount(This,wStreamNum,pcAttributes) ) 

#define IWMHeaderInfo_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength) ) 

#define IWMHeaderInfo_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength) ) 

#define IWMHeaderInfo_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength) ) 

#define IWMHeaderInfo_GetMarkerCount(This,pcMarkers)	\
    ( (This)->lpVtbl -> GetMarkerCount(This,pcMarkers) ) 

#define IWMHeaderInfo_GetMarker(This,wIndex,pwszMarkerName,pcchMarkerNameLen,pcnsMarkerTime)	\
    ( (This)->lpVtbl -> GetMarker(This,wIndex,pwszMarkerName,pcchMarkerNameLen,pcnsMarkerTime) ) 

#define IWMHeaderInfo_AddMarker(This,pwszMarkerName,cnsMarkerTime)	\
    ( (This)->lpVtbl -> AddMarker(This,pwszMarkerName,cnsMarkerTime) ) 

#define IWMHeaderInfo_RemoveMarker(This,wIndex)	\
    ( (This)->lpVtbl -> RemoveMarker(This,wIndex) ) 

#define IWMHeaderInfo_GetScriptCount(This,pcScripts)	\
    ( (This)->lpVtbl -> GetScriptCount(This,pcScripts) ) 

#define IWMHeaderInfo_GetScript(This,wIndex,pwszType,pcchTypeLen,pwszCommand,pcchCommandLen,pcnsScriptTime)	\
    ( (This)->lpVtbl -> GetScript(This,wIndex,pwszType,pcchTypeLen,pwszCommand,pcchCommandLen,pcnsScriptTime) ) 

#define IWMHeaderInfo_AddScript(This,pwszType,pwszCommand,cnsScriptTime)	\
    ( (This)->lpVtbl -> AddScript(This,pwszType,pwszCommand,cnsScriptTime) ) 

#define IWMHeaderInfo_RemoveScript(This,wIndex)	\
    ( (This)->lpVtbl -> RemoveScript(This,wIndex) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMHeaderInfo_INTERFACE_DEFINED__ */


#ifndef __IWMHeaderInfo2_INTERFACE_DEFINED__
#define __IWMHeaderInfo2_INTERFACE_DEFINED__

/* interface IWMHeaderInfo2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMHeaderInfo2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("15CF9781-454E-482e-B393-85FAE487A810")
    IWMHeaderInfo2 : public IWMHeaderInfo
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCodecInfoCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcCodecInfos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodecInfo( 
            /* [annotation][in] */ 
            _In_  DWORD wIndex,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchDescription,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDescription)  WCHAR *pwszDescription,
            /* [annotation][out] */ 
            _Out_  WMT_CODEC_INFO_TYPE *pCodecType,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbCodecInfo,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbCodecInfo)  BYTE *pbCodecInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMHeaderInfo2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMHeaderInfo2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMHeaderInfo2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMHeaderInfo2 * This);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetAttributeCount)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeCount )( 
            IWMHeaderInfo2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WORD *pcAttributes);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetAttributeByIndex)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeByIndex )( 
            IWMHeaderInfo2 * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwStreamNum,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchNameLen)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchNameLen,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetAttributeByName)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeByName )( 
            IWMHeaderInfo2 * This,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, SetAttribute)
        HRESULT ( STDMETHODCALLTYPE *SetAttribute )( 
            IWMHeaderInfo2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetMarkerCount)
        HRESULT ( STDMETHODCALLTYPE *GetMarkerCount )( 
            IWMHeaderInfo2 * This,
            /* [annotation][out] */ 
            _Out_  WORD *pcMarkers);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetMarker)
        HRESULT ( STDMETHODCALLTYPE *GetMarker )( 
            IWMHeaderInfo2 * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchMarkerNameLen)  WCHAR *pwszMarkerName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchMarkerNameLen,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsMarkerTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, AddMarker)
        HRESULT ( STDMETHODCALLTYPE *AddMarker )( 
            IWMHeaderInfo2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszMarkerName,
            /* [annotation][in] */ 
            _In_  QWORD cnsMarkerTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, RemoveMarker)
        HRESULT ( STDMETHODCALLTYPE *RemoveMarker )( 
            IWMHeaderInfo2 * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetScriptCount)
        HRESULT ( STDMETHODCALLTYPE *GetScriptCount )( 
            IWMHeaderInfo2 * This,
            /* [annotation][out] */ 
            _Out_  WORD *pcScripts);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetScript)
        HRESULT ( STDMETHODCALLTYPE *GetScript )( 
            IWMHeaderInfo2 * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchTypeLen)  WCHAR *pwszType,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchTypeLen,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchCommandLen)  WCHAR *pwszCommand,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchCommandLen,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsScriptTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, AddScript)
        HRESULT ( STDMETHODCALLTYPE *AddScript )( 
            IWMHeaderInfo2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszType,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszCommand,
            /* [annotation][in] */ 
            _In_  QWORD cnsScriptTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, RemoveScript)
        HRESULT ( STDMETHODCALLTYPE *RemoveScript )( 
            IWMHeaderInfo2 * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo2, GetCodecInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetCodecInfoCount )( 
            IWMHeaderInfo2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcCodecInfos);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo2, GetCodecInfo)
        HRESULT ( STDMETHODCALLTYPE *GetCodecInfo )( 
            IWMHeaderInfo2 * This,
            /* [annotation][in] */ 
            _In_  DWORD wIndex,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchDescription,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDescription)  WCHAR *pwszDescription,
            /* [annotation][out] */ 
            _Out_  WMT_CODEC_INFO_TYPE *pCodecType,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbCodecInfo,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbCodecInfo)  BYTE *pbCodecInfo);
        
        END_INTERFACE
    } IWMHeaderInfo2Vtbl;

    interface IWMHeaderInfo2
    {
        CONST_VTBL struct IWMHeaderInfo2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMHeaderInfo2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMHeaderInfo2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMHeaderInfo2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMHeaderInfo2_GetAttributeCount(This,wStreamNum,pcAttributes)	\
    ( (This)->lpVtbl -> GetAttributeCount(This,wStreamNum,pcAttributes) ) 

#define IWMHeaderInfo2_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength) ) 

#define IWMHeaderInfo2_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength) ) 

#define IWMHeaderInfo2_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength) ) 

#define IWMHeaderInfo2_GetMarkerCount(This,pcMarkers)	\
    ( (This)->lpVtbl -> GetMarkerCount(This,pcMarkers) ) 

#define IWMHeaderInfo2_GetMarker(This,wIndex,pwszMarkerName,pcchMarkerNameLen,pcnsMarkerTime)	\
    ( (This)->lpVtbl -> GetMarker(This,wIndex,pwszMarkerName,pcchMarkerNameLen,pcnsMarkerTime) ) 

#define IWMHeaderInfo2_AddMarker(This,pwszMarkerName,cnsMarkerTime)	\
    ( (This)->lpVtbl -> AddMarker(This,pwszMarkerName,cnsMarkerTime) ) 

#define IWMHeaderInfo2_RemoveMarker(This,wIndex)	\
    ( (This)->lpVtbl -> RemoveMarker(This,wIndex) ) 

#define IWMHeaderInfo2_GetScriptCount(This,pcScripts)	\
    ( (This)->lpVtbl -> GetScriptCount(This,pcScripts) ) 

#define IWMHeaderInfo2_GetScript(This,wIndex,pwszType,pcchTypeLen,pwszCommand,pcchCommandLen,pcnsScriptTime)	\
    ( (This)->lpVtbl -> GetScript(This,wIndex,pwszType,pcchTypeLen,pwszCommand,pcchCommandLen,pcnsScriptTime) ) 

#define IWMHeaderInfo2_AddScript(This,pwszType,pwszCommand,cnsScriptTime)	\
    ( (This)->lpVtbl -> AddScript(This,pwszType,pwszCommand,cnsScriptTime) ) 

#define IWMHeaderInfo2_RemoveScript(This,wIndex)	\
    ( (This)->lpVtbl -> RemoveScript(This,wIndex) ) 


#define IWMHeaderInfo2_GetCodecInfoCount(This,pcCodecInfos)	\
    ( (This)->lpVtbl -> GetCodecInfoCount(This,pcCodecInfos) ) 

#define IWMHeaderInfo2_GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)	\
    ( (This)->lpVtbl -> GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMHeaderInfo2_INTERFACE_DEFINED__ */


#ifndef __IWMHeaderInfo3_INTERFACE_DEFINED__
#define __IWMHeaderInfo3_INTERFACE_DEFINED__

/* interface IWMHeaderInfo3 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMHeaderInfo3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("15CC68E3-27CC-4ecd-B222-3F5D02D80BD5")
    IWMHeaderInfo3 : public IWMHeaderInfo2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAttributeCountEx( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WORD *pcAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributeIndices( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszName,
            /* [annotation][in] */ 
            _In_  WORD *pwLangIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pwCount)  WORD *pwIndices,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributeByIndexEx( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pwNameLen)  LPWSTR pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwNameLen,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][out] */ 
            _Out_  WORD *pwLangIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwDataLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwDataLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ModifyAttribute( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][in] */ 
            _In_  WORD wLangIndex,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  DWORD dwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddAttribute( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WORD *pwIndex,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][in] */ 
            _In_  WORD wLangIndex,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  DWORD dwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteAttribute( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WORD wIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddCodecInfo( 
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszName,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszDescription,
            /* [annotation][in] */ 
            _In_  WMT_CODEC_INFO_TYPE codecType,
            /* [annotation][in] */ 
            _In_  WORD cbCodecInfo,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbCodecInfo)  BYTE *pbCodecInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMHeaderInfo3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMHeaderInfo3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMHeaderInfo3 * This);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetAttributeCount)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeCount )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WORD *pcAttributes);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetAttributeByIndex)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeByIndex )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwStreamNum,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchNameLen)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchNameLen,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetAttributeByName)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeByName )( 
            IWMHeaderInfo3 * This,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, SetAttribute)
        HRESULT ( STDMETHODCALLTYPE *SetAttribute )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetMarkerCount)
        HRESULT ( STDMETHODCALLTYPE *GetMarkerCount )( 
            IWMHeaderInfo3 * This,
            /* [annotation][out] */ 
            _Out_  WORD *pcMarkers);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetMarker)
        HRESULT ( STDMETHODCALLTYPE *GetMarker )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchMarkerNameLen)  WCHAR *pwszMarkerName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchMarkerNameLen,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsMarkerTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, AddMarker)
        HRESULT ( STDMETHODCALLTYPE *AddMarker )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszMarkerName,
            /* [annotation][in] */ 
            _In_  QWORD cnsMarkerTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, RemoveMarker)
        HRESULT ( STDMETHODCALLTYPE *RemoveMarker )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetScriptCount)
        HRESULT ( STDMETHODCALLTYPE *GetScriptCount )( 
            IWMHeaderInfo3 * This,
            /* [annotation][out] */ 
            _Out_  WORD *pcScripts);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, GetScript)
        HRESULT ( STDMETHODCALLTYPE *GetScript )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchTypeLen)  WCHAR *pwszType,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchTypeLen,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchCommandLen)  WCHAR *pwszCommand,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchCommandLen,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsScriptTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, AddScript)
        HRESULT ( STDMETHODCALLTYPE *AddScript )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszType,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszCommand,
            /* [annotation][in] */ 
            _In_  QWORD cnsScriptTime);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo, RemoveScript)
        HRESULT ( STDMETHODCALLTYPE *RemoveScript )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo2, GetCodecInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetCodecInfoCount )( 
            IWMHeaderInfo3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcCodecInfos);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo2, GetCodecInfo)
        HRESULT ( STDMETHODCALLTYPE *GetCodecInfo )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  DWORD wIndex,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchDescription,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDescription)  WCHAR *pwszDescription,
            /* [annotation][out] */ 
            _Out_  WMT_CODEC_INFO_TYPE *pCodecType,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbCodecInfo,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbCodecInfo)  BYTE *pbCodecInfo);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo3, GetAttributeCountEx)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeCountEx )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WORD *pcAttributes);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo3, GetAttributeIndices)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeIndices )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszName,
            /* [annotation][in] */ 
            _In_  WORD *pwLangIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pwCount)  WORD *pwIndices,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwCount);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo3, GetAttributeByIndexEx)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeByIndexEx )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pwNameLen)  LPWSTR pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pwNameLen,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][out] */ 
            _Out_  WORD *pwLangIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwDataLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwDataLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo3, ModifyAttribute)
        HRESULT ( STDMETHODCALLTYPE *ModifyAttribute )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][in] */ 
            _In_  WORD wLangIndex,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  DWORD dwLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo3, AddAttribute)
        HRESULT ( STDMETHODCALLTYPE *AddAttribute )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WORD *pwIndex,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][in] */ 
            _In_  WORD wLangIndex,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  DWORD dwLength);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo3, DeleteAttribute)
        HRESULT ( STDMETHODCALLTYPE *DeleteAttribute )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WORD wIndex);
        
        DECLSPEC_XFGVIRT(IWMHeaderInfo3, AddCodecInfo)
        HRESULT ( STDMETHODCALLTYPE *AddCodecInfo )( 
            IWMHeaderInfo3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszName,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszDescription,
            /* [annotation][in] */ 
            _In_  WMT_CODEC_INFO_TYPE codecType,
            /* [annotation][in] */ 
            _In_  WORD cbCodecInfo,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbCodecInfo)  BYTE *pbCodecInfo);
        
        END_INTERFACE
    } IWMHeaderInfo3Vtbl;

    interface IWMHeaderInfo3
    {
        CONST_VTBL struct IWMHeaderInfo3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMHeaderInfo3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMHeaderInfo3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMHeaderInfo3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMHeaderInfo3_GetAttributeCount(This,wStreamNum,pcAttributes)	\
    ( (This)->lpVtbl -> GetAttributeCount(This,wStreamNum,pcAttributes) ) 

#define IWMHeaderInfo3_GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetAttributeByIndex(This,wIndex,pwStreamNum,pwszName,pcchNameLen,pType,pValue,pcbLength) ) 

#define IWMHeaderInfo3_GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetAttributeByName(This,pwStreamNum,pszName,pType,pValue,pcbLength) ) 

#define IWMHeaderInfo3_SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetAttribute(This,wStreamNum,pszName,Type,pValue,cbLength) ) 

#define IWMHeaderInfo3_GetMarkerCount(This,pcMarkers)	\
    ( (This)->lpVtbl -> GetMarkerCount(This,pcMarkers) ) 

#define IWMHeaderInfo3_GetMarker(This,wIndex,pwszMarkerName,pcchMarkerNameLen,pcnsMarkerTime)	\
    ( (This)->lpVtbl -> GetMarker(This,wIndex,pwszMarkerName,pcchMarkerNameLen,pcnsMarkerTime) ) 

#define IWMHeaderInfo3_AddMarker(This,pwszMarkerName,cnsMarkerTime)	\
    ( (This)->lpVtbl -> AddMarker(This,pwszMarkerName,cnsMarkerTime) ) 

#define IWMHeaderInfo3_RemoveMarker(This,wIndex)	\
    ( (This)->lpVtbl -> RemoveMarker(This,wIndex) ) 

#define IWMHeaderInfo3_GetScriptCount(This,pcScripts)	\
    ( (This)->lpVtbl -> GetScriptCount(This,pcScripts) ) 

#define IWMHeaderInfo3_GetScript(This,wIndex,pwszType,pcchTypeLen,pwszCommand,pcchCommandLen,pcnsScriptTime)	\
    ( (This)->lpVtbl -> GetScript(This,wIndex,pwszType,pcchTypeLen,pwszCommand,pcchCommandLen,pcnsScriptTime) ) 

#define IWMHeaderInfo3_AddScript(This,pwszType,pwszCommand,cnsScriptTime)	\
    ( (This)->lpVtbl -> AddScript(This,pwszType,pwszCommand,cnsScriptTime) ) 

#define IWMHeaderInfo3_RemoveScript(This,wIndex)	\
    ( (This)->lpVtbl -> RemoveScript(This,wIndex) ) 


#define IWMHeaderInfo3_GetCodecInfoCount(This,pcCodecInfos)	\
    ( (This)->lpVtbl -> GetCodecInfoCount(This,pcCodecInfos) ) 

#define IWMHeaderInfo3_GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo)	\
    ( (This)->lpVtbl -> GetCodecInfo(This,wIndex,pcchName,pwszName,pcchDescription,pwszDescription,pCodecType,pcbCodecInfo,pbCodecInfo) ) 


#define IWMHeaderInfo3_GetAttributeCountEx(This,wStreamNum,pcAttributes)	\
    ( (This)->lpVtbl -> GetAttributeCountEx(This,wStreamNum,pcAttributes) ) 

#define IWMHeaderInfo3_GetAttributeIndices(This,wStreamNum,pwszName,pwLangIndex,pwIndices,pwCount)	\
    ( (This)->lpVtbl -> GetAttributeIndices(This,wStreamNum,pwszName,pwLangIndex,pwIndices,pwCount) ) 

#define IWMHeaderInfo3_GetAttributeByIndexEx(This,wStreamNum,wIndex,pwszName,pwNameLen,pType,pwLangIndex,pValue,pdwDataLength)	\
    ( (This)->lpVtbl -> GetAttributeByIndexEx(This,wStreamNum,wIndex,pwszName,pwNameLen,pType,pwLangIndex,pValue,pdwDataLength) ) 

#define IWMHeaderInfo3_ModifyAttribute(This,wStreamNum,wIndex,Type,wLangIndex,pValue,dwLength)	\
    ( (This)->lpVtbl -> ModifyAttribute(This,wStreamNum,wIndex,Type,wLangIndex,pValue,dwLength) ) 

#define IWMHeaderInfo3_AddAttribute(This,wStreamNum,pszName,pwIndex,Type,wLangIndex,pValue,dwLength)	\
    ( (This)->lpVtbl -> AddAttribute(This,wStreamNum,pszName,pwIndex,Type,wLangIndex,pValue,dwLength) ) 

#define IWMHeaderInfo3_DeleteAttribute(This,wStreamNum,wIndex)	\
    ( (This)->lpVtbl -> DeleteAttribute(This,wStreamNum,wIndex) ) 

#define IWMHeaderInfo3_AddCodecInfo(This,pwszName,pwszDescription,codecType,cbCodecInfo,pbCodecInfo)	\
    ( (This)->lpVtbl -> AddCodecInfo(This,pwszName,pwszDescription,codecType,cbCodecInfo,pbCodecInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMHeaderInfo3_INTERFACE_DEFINED__ */


#ifndef __IWMProfileManager_INTERFACE_DEFINED__
#define __IWMProfileManager_INTERFACE_DEFINED__

/* interface IWMProfileManager */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMProfileManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d16679f2-6ca0-472d-8d31-2f5d55aee155")
    IWMProfileManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateEmptyProfile( 
            /* [annotation][in] */ 
            _In_  WMT_VERSION dwVersion,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadProfileByID( 
            /* [annotation][in] */ 
            _In_  REFGUID guidProfile,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadProfileByData( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszProfile,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveProfile( 
            /* [annotation][in] */ 
            _In_  IWMProfile *pIWMProfile,
            /* [annotation][in] */ 
            _In_  WCHAR *pwszProfile,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSystemProfileCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcProfiles) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadSystemProfile( 
            /* [annotation][in] */ 
            _In_  DWORD dwProfileIndex,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMProfileManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMProfileManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMProfileManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMProfileManager * This);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, CreateEmptyProfile)
        HRESULT ( STDMETHODCALLTYPE *CreateEmptyProfile )( 
            IWMProfileManager * This,
            /* [annotation][in] */ 
            _In_  WMT_VERSION dwVersion,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, LoadProfileByID)
        HRESULT ( STDMETHODCALLTYPE *LoadProfileByID )( 
            IWMProfileManager * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidProfile,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, LoadProfileByData)
        HRESULT ( STDMETHODCALLTYPE *LoadProfileByData )( 
            IWMProfileManager * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszProfile,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, SaveProfile)
        HRESULT ( STDMETHODCALLTYPE *SaveProfile )( 
            IWMProfileManager * This,
            /* [annotation][in] */ 
            _In_  IWMProfile *pIWMProfile,
            /* [annotation][in] */ 
            _In_  WCHAR *pwszProfile,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, GetSystemProfileCount)
        HRESULT ( STDMETHODCALLTYPE *GetSystemProfileCount )( 
            IWMProfileManager * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcProfiles);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, LoadSystemProfile)
        HRESULT ( STDMETHODCALLTYPE *LoadSystemProfile )( 
            IWMProfileManager * This,
            /* [annotation][in] */ 
            _In_  DWORD dwProfileIndex,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile);
        
        END_INTERFACE
    } IWMProfileManagerVtbl;

    interface IWMProfileManager
    {
        CONST_VTBL struct IWMProfileManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMProfileManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMProfileManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMProfileManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMProfileManager_CreateEmptyProfile(This,dwVersion,ppProfile)	\
    ( (This)->lpVtbl -> CreateEmptyProfile(This,dwVersion,ppProfile) ) 

#define IWMProfileManager_LoadProfileByID(This,guidProfile,ppProfile)	\
    ( (This)->lpVtbl -> LoadProfileByID(This,guidProfile,ppProfile) ) 

#define IWMProfileManager_LoadProfileByData(This,pwszProfile,ppProfile)	\
    ( (This)->lpVtbl -> LoadProfileByData(This,pwszProfile,ppProfile) ) 

#define IWMProfileManager_SaveProfile(This,pIWMProfile,pwszProfile,pdwLength)	\
    ( (This)->lpVtbl -> SaveProfile(This,pIWMProfile,pwszProfile,pdwLength) ) 

#define IWMProfileManager_GetSystemProfileCount(This,pcProfiles)	\
    ( (This)->lpVtbl -> GetSystemProfileCount(This,pcProfiles) ) 

#define IWMProfileManager_LoadSystemProfile(This,dwProfileIndex,ppProfile)	\
    ( (This)->lpVtbl -> LoadSystemProfile(This,dwProfileIndex,ppProfile) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMProfileManager_INTERFACE_DEFINED__ */


#ifndef __IWMProfileManager2_INTERFACE_DEFINED__
#define __IWMProfileManager2_INTERFACE_DEFINED__

/* interface IWMProfileManager2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMProfileManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7A924E51-73C1-494d-8019-23D37ED9B89A")
    IWMProfileManager2 : public IWMProfileManager
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSystemProfileVersion( 
            WMT_VERSION *pdwVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSystemProfileVersion( 
            WMT_VERSION dwVersion) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMProfileManager2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMProfileManager2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMProfileManager2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMProfileManager2 * This);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, CreateEmptyProfile)
        HRESULT ( STDMETHODCALLTYPE *CreateEmptyProfile )( 
            IWMProfileManager2 * This,
            /* [annotation][in] */ 
            _In_  WMT_VERSION dwVersion,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, LoadProfileByID)
        HRESULT ( STDMETHODCALLTYPE *LoadProfileByID )( 
            IWMProfileManager2 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidProfile,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, LoadProfileByData)
        HRESULT ( STDMETHODCALLTYPE *LoadProfileByData )( 
            IWMProfileManager2 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszProfile,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, SaveProfile)
        HRESULT ( STDMETHODCALLTYPE *SaveProfile )( 
            IWMProfileManager2 * This,
            /* [annotation][in] */ 
            _In_  IWMProfile *pIWMProfile,
            /* [annotation][in] */ 
            _In_  WCHAR *pwszProfile,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwLength);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, GetSystemProfileCount)
        HRESULT ( STDMETHODCALLTYPE *GetSystemProfileCount )( 
            IWMProfileManager2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcProfiles);
        
        DECLSPEC_XFGVIRT(IWMProfileManager, LoadSystemProfile)
        HRESULT ( STDMETHODCALLTYPE *LoadSystemProfile )( 
            IWMProfileManager2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwProfileIndex,
            /* [annotation][out] */ 
            _Out_  IWMProfile **ppProfile);
        
        DECLSPEC_XFGVIRT(IWMProfileManager2, GetSystemProfileVersion)
        HRESULT ( STDMETHODCALLTYPE *GetSystemProfileVersion )( 
            IWMProfileManager2 * This,
            WMT_VERSION *pdwVersion);
        
        DECLSPEC_XFGVIRT(IWMProfileManager2, SetSystemProfileVersion)
        HRESULT ( STDMETHODCALLTYPE *SetSystemProfileVersion )( 
            IWMProfileManager2 * This,
            WMT_VERSION dwVersion);
        
        END_INTERFACE
    } IWMProfileManager2Vtbl;

    interface IWMProfileManager2
    {
        CONST_VTBL struct IWMProfileManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMProfileManager2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMProfileManager2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMProfileManager2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMProfileManager2_CreateEmptyProfile(This,dwVersion,ppProfile)	\
    ( (This)->lpVtbl -> CreateEmptyProfile(This,dwVersion,ppProfile) ) 

#define IWMProfileManager2_LoadProfileByID(This,guidProfile,ppProfile)	\
    ( (This)->lpVtbl -> LoadProfileByID(This,guidProfile,ppProfile) ) 

#define IWMProfileManager2_LoadProfileByData(This,pwszProfile,ppProfile)	\
    ( (This)->lpVtbl -> LoadProfileByData(This,pwszProfile,ppProfile) ) 

#define IWMProfileManager2_SaveProfile(This,pIWMProfile,pwszProfile,pdwLength)	\
    ( (This)->lpVtbl -> SaveProfile(This,pIWMProfile,pwszProfile,pdwLength) ) 

#define IWMProfileManager2_GetSystemProfileCount(This,pcProfiles)	\
    ( (This)->lpVtbl -> GetSystemProfileCount(This,pcProfiles) ) 

#define IWMProfileManager2_LoadSystemProfile(This,dwProfileIndex,ppProfile)	\
    ( (This)->lpVtbl -> LoadSystemProfile(This,dwProfileIndex,ppProfile) ) 


#define IWMProfileManager2_GetSystemProfileVersion(This,pdwVersion)	\
    ( (This)->lpVtbl -> GetSystemProfileVersion(This,pdwVersion) ) 

#define IWMProfileManager2_SetSystemProfileVersion(This,dwVersion)	\
    ( (This)->lpVtbl -> SetSystemProfileVersion(This,dwVersion) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMProfileManager2_INTERFACE_DEFINED__ */


#ifndef __IWMProfileManagerLanguage_INTERFACE_DEFINED__
#define __IWMProfileManagerLanguage_INTERFACE_DEFINED__

/* interface IWMProfileManagerLanguage */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMProfileManagerLanguage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA4DCC78-7EE0-4ab8-B27A-DBCE8BC51454")
    IWMProfileManagerLanguage : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetUserLanguageID( 
            WORD *wLangID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUserLanguageID( 
            WORD wLangID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMProfileManagerLanguageVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMProfileManagerLanguage * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMProfileManagerLanguage * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMProfileManagerLanguage * This);
        
        DECLSPEC_XFGVIRT(IWMProfileManagerLanguage, GetUserLanguageID)
        HRESULT ( STDMETHODCALLTYPE *GetUserLanguageID )( 
            IWMProfileManagerLanguage * This,
            WORD *wLangID);
        
        DECLSPEC_XFGVIRT(IWMProfileManagerLanguage, SetUserLanguageID)
        HRESULT ( STDMETHODCALLTYPE *SetUserLanguageID )( 
            IWMProfileManagerLanguage * This,
            WORD wLangID);
        
        END_INTERFACE
    } IWMProfileManagerLanguageVtbl;

    interface IWMProfileManagerLanguage
    {
        CONST_VTBL struct IWMProfileManagerLanguageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMProfileManagerLanguage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMProfileManagerLanguage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMProfileManagerLanguage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMProfileManagerLanguage_GetUserLanguageID(This,wLangID)	\
    ( (This)->lpVtbl -> GetUserLanguageID(This,wLangID) ) 

#define IWMProfileManagerLanguage_SetUserLanguageID(This,wLangID)	\
    ( (This)->lpVtbl -> SetUserLanguageID(This,wLangID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMProfileManagerLanguage_INTERFACE_DEFINED__ */


#ifndef __IWMProfile_INTERFACE_DEFINED__
#define __IWMProfile_INTERFACE_DEFINED__

/* interface IWMProfile */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMProfile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BDB-2B2B-11d3-B36B-00C04F6108FF")
    IWMProfile : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [annotation][out] */ 
            _Out_  WMT_VERSION *pdwVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDescription)  WCHAR *pwszDescription,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcStreams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStream( 
            /* [annotation][in] */ 
            _In_  DWORD dwStreamIndex,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamByNumber( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveStream( 
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveStreamByNumber( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddStream( 
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReconfigStream( 
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewStream( 
            /* [annotation][in] */ 
            _In_  REFGUID guidStreamType,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMutualExclusionCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcME) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMutualExclusion( 
            /* [annotation][in] */ 
            _In_  DWORD dwMEIndex,
            /* [annotation][out] */ 
            _Out_  IWMMutualExclusion **ppME) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveMutualExclusion( 
            /* [annotation][in] */ 
            _In_  IWMMutualExclusion *pME) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddMutualExclusion( 
            /* [annotation][in] */ 
            _In_  IWMMutualExclusion *pME) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewMutualExclusion( 
            /* [annotation][out] */ 
            _Out_  IWMMutualExclusion **ppME) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMProfileVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMProfile * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMProfile * This);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetVersion)
        HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            IWMProfile * This,
            /* [annotation][out] */ 
            _Out_  WMT_VERSION *pdwVersion);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetName)
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IWMProfile * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchName);
        
        DECLSPEC_XFGVIRT(IWMProfile, SetName)
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszName);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetDescription)
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IWMProfile * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDescription)  WCHAR *pwszDescription,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDescription);
        
        DECLSPEC_XFGVIRT(IWMProfile, SetDescription)
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszDescription);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetStreamCount)
        HRESULT ( STDMETHODCALLTYPE *GetStreamCount )( 
            IWMProfile * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcStreams);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetStream)
        HRESULT ( STDMETHODCALLTYPE *GetStream )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  DWORD dwStreamIndex,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetStreamByNumber)
        HRESULT ( STDMETHODCALLTYPE *GetStreamByNumber )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, RemoveStream)
        HRESULT ( STDMETHODCALLTYPE *RemoveStream )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, RemoveStreamByNumber)
        HRESULT ( STDMETHODCALLTYPE *RemoveStreamByNumber )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMProfile, AddStream)
        HRESULT ( STDMETHODCALLTYPE *AddStream )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, ReconfigStream)
        HRESULT ( STDMETHODCALLTYPE *ReconfigStream )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, CreateNewStream)
        HRESULT ( STDMETHODCALLTYPE *CreateNewStream )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidStreamType,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetMutualExclusionCount)
        HRESULT ( STDMETHODCALLTYPE *GetMutualExclusionCount )( 
            IWMProfile * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcME);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *GetMutualExclusion )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMEIndex,
            /* [annotation][out] */ 
            _Out_  IWMMutualExclusion **ppME);
        
        DECLSPEC_XFGVIRT(IWMProfile, RemoveMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *RemoveMutualExclusion )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  IWMMutualExclusion *pME);
        
        DECLSPEC_XFGVIRT(IWMProfile, AddMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *AddMutualExclusion )( 
            IWMProfile * This,
            /* [annotation][in] */ 
            _In_  IWMMutualExclusion *pME);
        
        DECLSPEC_XFGVIRT(IWMProfile, CreateNewMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *CreateNewMutualExclusion )( 
            IWMProfile * This,
            /* [annotation][out] */ 
            _Out_  IWMMutualExclusion **ppME);
        
        END_INTERFACE
    } IWMProfileVtbl;

    interface IWMProfile
    {
        CONST_VTBL struct IWMProfileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMProfile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMProfile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMProfile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMProfile_GetVersion(This,pdwVersion)	\
    ( (This)->lpVtbl -> GetVersion(This,pdwVersion) ) 

#define IWMProfile_GetName(This,pwszName,pcchName)	\
    ( (This)->lpVtbl -> GetName(This,pwszName,pcchName) ) 

#define IWMProfile_SetName(This,pwszName)	\
    ( (This)->lpVtbl -> SetName(This,pwszName) ) 

#define IWMProfile_GetDescription(This,pwszDescription,pcchDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,pwszDescription,pcchDescription) ) 

#define IWMProfile_SetDescription(This,pwszDescription)	\
    ( (This)->lpVtbl -> SetDescription(This,pwszDescription) ) 

#define IWMProfile_GetStreamCount(This,pcStreams)	\
    ( (This)->lpVtbl -> GetStreamCount(This,pcStreams) ) 

#define IWMProfile_GetStream(This,dwStreamIndex,ppConfig)	\
    ( (This)->lpVtbl -> GetStream(This,dwStreamIndex,ppConfig) ) 

#define IWMProfile_GetStreamByNumber(This,wStreamNum,ppConfig)	\
    ( (This)->lpVtbl -> GetStreamByNumber(This,wStreamNum,ppConfig) ) 

#define IWMProfile_RemoveStream(This,pConfig)	\
    ( (This)->lpVtbl -> RemoveStream(This,pConfig) ) 

#define IWMProfile_RemoveStreamByNumber(This,wStreamNum)	\
    ( (This)->lpVtbl -> RemoveStreamByNumber(This,wStreamNum) ) 

#define IWMProfile_AddStream(This,pConfig)	\
    ( (This)->lpVtbl -> AddStream(This,pConfig) ) 

#define IWMProfile_ReconfigStream(This,pConfig)	\
    ( (This)->lpVtbl -> ReconfigStream(This,pConfig) ) 

#define IWMProfile_CreateNewStream(This,guidStreamType,ppConfig)	\
    ( (This)->lpVtbl -> CreateNewStream(This,guidStreamType,ppConfig) ) 

#define IWMProfile_GetMutualExclusionCount(This,pcME)	\
    ( (This)->lpVtbl -> GetMutualExclusionCount(This,pcME) ) 

#define IWMProfile_GetMutualExclusion(This,dwMEIndex,ppME)	\
    ( (This)->lpVtbl -> GetMutualExclusion(This,dwMEIndex,ppME) ) 

#define IWMProfile_RemoveMutualExclusion(This,pME)	\
    ( (This)->lpVtbl -> RemoveMutualExclusion(This,pME) ) 

#define IWMProfile_AddMutualExclusion(This,pME)	\
    ( (This)->lpVtbl -> AddMutualExclusion(This,pME) ) 

#define IWMProfile_CreateNewMutualExclusion(This,ppME)	\
    ( (This)->lpVtbl -> CreateNewMutualExclusion(This,ppME) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMProfile_INTERFACE_DEFINED__ */


#ifndef __IWMProfile2_INTERFACE_DEFINED__
#define __IWMProfile2_INTERFACE_DEFINED__

/* interface IWMProfile2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMProfile2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("07E72D33-D94E-4be7-8843-60AE5FF7E5F5")
    IWMProfile2 : public IWMProfile
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetProfileID( 
            /* [annotation][out] */ 
            _Out_  GUID *pguidID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMProfile2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMProfile2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMProfile2 * This);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetVersion)
        HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            IWMProfile2 * This,
            /* [annotation][out] */ 
            _Out_  WMT_VERSION *pdwVersion);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetName)
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IWMProfile2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchName);
        
        DECLSPEC_XFGVIRT(IWMProfile, SetName)
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszName);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetDescription)
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IWMProfile2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDescription)  WCHAR *pwszDescription,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDescription);
        
        DECLSPEC_XFGVIRT(IWMProfile, SetDescription)
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszDescription);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetStreamCount)
        HRESULT ( STDMETHODCALLTYPE *GetStreamCount )( 
            IWMProfile2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcStreams);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetStream)
        HRESULT ( STDMETHODCALLTYPE *GetStream )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwStreamIndex,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetStreamByNumber)
        HRESULT ( STDMETHODCALLTYPE *GetStreamByNumber )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, RemoveStream)
        HRESULT ( STDMETHODCALLTYPE *RemoveStream )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, RemoveStreamByNumber)
        HRESULT ( STDMETHODCALLTYPE *RemoveStreamByNumber )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMProfile, AddStream)
        HRESULT ( STDMETHODCALLTYPE *AddStream )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, ReconfigStream)
        HRESULT ( STDMETHODCALLTYPE *ReconfigStream )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, CreateNewStream)
        HRESULT ( STDMETHODCALLTYPE *CreateNewStream )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidStreamType,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetMutualExclusionCount)
        HRESULT ( STDMETHODCALLTYPE *GetMutualExclusionCount )( 
            IWMProfile2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcME);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *GetMutualExclusion )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMEIndex,
            /* [annotation][out] */ 
            _Out_  IWMMutualExclusion **ppME);
        
        DECLSPEC_XFGVIRT(IWMProfile, RemoveMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *RemoveMutualExclusion )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  IWMMutualExclusion *pME);
        
        DECLSPEC_XFGVIRT(IWMProfile, AddMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *AddMutualExclusion )( 
            IWMProfile2 * This,
            /* [annotation][in] */ 
            _In_  IWMMutualExclusion *pME);
        
        DECLSPEC_XFGVIRT(IWMProfile, CreateNewMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *CreateNewMutualExclusion )( 
            IWMProfile2 * This,
            /* [annotation][out] */ 
            _Out_  IWMMutualExclusion **ppME);
        
        DECLSPEC_XFGVIRT(IWMProfile2, GetProfileID)
        HRESULT ( STDMETHODCALLTYPE *GetProfileID )( 
            IWMProfile2 * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidID);
        
        END_INTERFACE
    } IWMProfile2Vtbl;

    interface IWMProfile2
    {
        CONST_VTBL struct IWMProfile2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMProfile2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMProfile2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMProfile2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMProfile2_GetVersion(This,pdwVersion)	\
    ( (This)->lpVtbl -> GetVersion(This,pdwVersion) ) 

#define IWMProfile2_GetName(This,pwszName,pcchName)	\
    ( (This)->lpVtbl -> GetName(This,pwszName,pcchName) ) 

#define IWMProfile2_SetName(This,pwszName)	\
    ( (This)->lpVtbl -> SetName(This,pwszName) ) 

#define IWMProfile2_GetDescription(This,pwszDescription,pcchDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,pwszDescription,pcchDescription) ) 

#define IWMProfile2_SetDescription(This,pwszDescription)	\
    ( (This)->lpVtbl -> SetDescription(This,pwszDescription) ) 

#define IWMProfile2_GetStreamCount(This,pcStreams)	\
    ( (This)->lpVtbl -> GetStreamCount(This,pcStreams) ) 

#define IWMProfile2_GetStream(This,dwStreamIndex,ppConfig)	\
    ( (This)->lpVtbl -> GetStream(This,dwStreamIndex,ppConfig) ) 

#define IWMProfile2_GetStreamByNumber(This,wStreamNum,ppConfig)	\
    ( (This)->lpVtbl -> GetStreamByNumber(This,wStreamNum,ppConfig) ) 

#define IWMProfile2_RemoveStream(This,pConfig)	\
    ( (This)->lpVtbl -> RemoveStream(This,pConfig) ) 

#define IWMProfile2_RemoveStreamByNumber(This,wStreamNum)	\
    ( (This)->lpVtbl -> RemoveStreamByNumber(This,wStreamNum) ) 

#define IWMProfile2_AddStream(This,pConfig)	\
    ( (This)->lpVtbl -> AddStream(This,pConfig) ) 

#define IWMProfile2_ReconfigStream(This,pConfig)	\
    ( (This)->lpVtbl -> ReconfigStream(This,pConfig) ) 

#define IWMProfile2_CreateNewStream(This,guidStreamType,ppConfig)	\
    ( (This)->lpVtbl -> CreateNewStream(This,guidStreamType,ppConfig) ) 

#define IWMProfile2_GetMutualExclusionCount(This,pcME)	\
    ( (This)->lpVtbl -> GetMutualExclusionCount(This,pcME) ) 

#define IWMProfile2_GetMutualExclusion(This,dwMEIndex,ppME)	\
    ( (This)->lpVtbl -> GetMutualExclusion(This,dwMEIndex,ppME) ) 

#define IWMProfile2_RemoveMutualExclusion(This,pME)	\
    ( (This)->lpVtbl -> RemoveMutualExclusion(This,pME) ) 

#define IWMProfile2_AddMutualExclusion(This,pME)	\
    ( (This)->lpVtbl -> AddMutualExclusion(This,pME) ) 

#define IWMProfile2_CreateNewMutualExclusion(This,ppME)	\
    ( (This)->lpVtbl -> CreateNewMutualExclusion(This,ppME) ) 


#define IWMProfile2_GetProfileID(This,pguidID)	\
    ( (This)->lpVtbl -> GetProfileID(This,pguidID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMProfile2_INTERFACE_DEFINED__ */


#ifndef __IWMProfile3_INTERFACE_DEFINED__
#define __IWMProfile3_INTERFACE_DEFINED__

/* interface IWMProfile3 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMProfile3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00EF96CC-A461-4546-8BCD-C9A28F0E06F5")
    IWMProfile3 : public IWMProfile2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStorageFormat( 
            /* [annotation][out] */ 
            _Out_  WMT_STORAGE_FORMAT *pnStorageFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStorageFormat( 
            /* [annotation][in] */ 
            _In_  WMT_STORAGE_FORMAT nStorageFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBandwidthSharingCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcBS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBandwidthSharing( 
            /* [annotation][in] */ 
            _In_  DWORD dwBSIndex,
            /* [annotation][out] */ 
            _Out_  IWMBandwidthSharing **ppBS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveBandwidthSharing( 
            /* [annotation][in] */ 
            _In_  IWMBandwidthSharing *pBS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddBandwidthSharing( 
            /* [annotation][in] */ 
            _In_  IWMBandwidthSharing *pBS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewBandwidthSharing( 
            /* [annotation][out] */ 
            _Out_  IWMBandwidthSharing **ppBS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamPrioritization( 
            /* [annotation][out] */ 
            _Out_  IWMStreamPrioritization **ppSP) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStreamPrioritization( 
            /* [annotation][in] */ 
            _In_  IWMStreamPrioritization *pSP) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveStreamPrioritization( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewStreamPrioritization( 
            /* [annotation][out] */ 
            _Out_  IWMStreamPrioritization **ppSP) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExpectedPacketCount( 
            /* [annotation][in] */ 
            _In_  QWORD msDuration,
            /* [annotation][out] */ 
            _Out_  QWORD *pcPackets) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMProfile3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMProfile3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMProfile3 * This);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetVersion)
        HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            IWMProfile3 * This,
            /* [annotation][out] */ 
            _Out_  WMT_VERSION *pdwVersion);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetName)
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IWMProfile3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchName);
        
        DECLSPEC_XFGVIRT(IWMProfile, SetName)
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszName);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetDescription)
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IWMProfile3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDescription)  WCHAR *pwszDescription,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDescription);
        
        DECLSPEC_XFGVIRT(IWMProfile, SetDescription)
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszDescription);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetStreamCount)
        HRESULT ( STDMETHODCALLTYPE *GetStreamCount )( 
            IWMProfile3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcStreams);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetStream)
        HRESULT ( STDMETHODCALLTYPE *GetStream )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwStreamIndex,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetStreamByNumber)
        HRESULT ( STDMETHODCALLTYPE *GetStreamByNumber )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, RemoveStream)
        HRESULT ( STDMETHODCALLTYPE *RemoveStream )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, RemoveStreamByNumber)
        HRESULT ( STDMETHODCALLTYPE *RemoveStreamByNumber )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMProfile, AddStream)
        HRESULT ( STDMETHODCALLTYPE *AddStream )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, ReconfigStream)
        HRESULT ( STDMETHODCALLTYPE *ReconfigStream )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  IWMStreamConfig *pConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, CreateNewStream)
        HRESULT ( STDMETHODCALLTYPE *CreateNewStream )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidStreamType,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppConfig);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetMutualExclusionCount)
        HRESULT ( STDMETHODCALLTYPE *GetMutualExclusionCount )( 
            IWMProfile3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcME);
        
        DECLSPEC_XFGVIRT(IWMProfile, GetMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *GetMutualExclusion )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMEIndex,
            /* [annotation][out] */ 
            _Out_  IWMMutualExclusion **ppME);
        
        DECLSPEC_XFGVIRT(IWMProfile, RemoveMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *RemoveMutualExclusion )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  IWMMutualExclusion *pME);
        
        DECLSPEC_XFGVIRT(IWMProfile, AddMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *AddMutualExclusion )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  IWMMutualExclusion *pME);
        
        DECLSPEC_XFGVIRT(IWMProfile, CreateNewMutualExclusion)
        HRESULT ( STDMETHODCALLTYPE *CreateNewMutualExclusion )( 
            IWMProfile3 * This,
            /* [annotation][out] */ 
            _Out_  IWMMutualExclusion **ppME);
        
        DECLSPEC_XFGVIRT(IWMProfile2, GetProfileID)
        HRESULT ( STDMETHODCALLTYPE *GetProfileID )( 
            IWMProfile3 * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidID);
        
        DECLSPEC_XFGVIRT(IWMProfile3, GetStorageFormat)
        HRESULT ( STDMETHODCALLTYPE *GetStorageFormat )( 
            IWMProfile3 * This,
            /* [annotation][out] */ 
            _Out_  WMT_STORAGE_FORMAT *pnStorageFormat);
        
        DECLSPEC_XFGVIRT(IWMProfile3, SetStorageFormat)
        HRESULT ( STDMETHODCALLTYPE *SetStorageFormat )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  WMT_STORAGE_FORMAT nStorageFormat);
        
        DECLSPEC_XFGVIRT(IWMProfile3, GetBandwidthSharingCount)
        HRESULT ( STDMETHODCALLTYPE *GetBandwidthSharingCount )( 
            IWMProfile3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcBS);
        
        DECLSPEC_XFGVIRT(IWMProfile3, GetBandwidthSharing)
        HRESULT ( STDMETHODCALLTYPE *GetBandwidthSharing )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwBSIndex,
            /* [annotation][out] */ 
            _Out_  IWMBandwidthSharing **ppBS);
        
        DECLSPEC_XFGVIRT(IWMProfile3, RemoveBandwidthSharing)
        HRESULT ( STDMETHODCALLTYPE *RemoveBandwidthSharing )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  IWMBandwidthSharing *pBS);
        
        DECLSPEC_XFGVIRT(IWMProfile3, AddBandwidthSharing)
        HRESULT ( STDMETHODCALLTYPE *AddBandwidthSharing )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  IWMBandwidthSharing *pBS);
        
        DECLSPEC_XFGVIRT(IWMProfile3, CreateNewBandwidthSharing)
        HRESULT ( STDMETHODCALLTYPE *CreateNewBandwidthSharing )( 
            IWMProfile3 * This,
            /* [annotation][out] */ 
            _Out_  IWMBandwidthSharing **ppBS);
        
        DECLSPEC_XFGVIRT(IWMProfile3, GetStreamPrioritization)
        HRESULT ( STDMETHODCALLTYPE *GetStreamPrioritization )( 
            IWMProfile3 * This,
            /* [annotation][out] */ 
            _Out_  IWMStreamPrioritization **ppSP);
        
        DECLSPEC_XFGVIRT(IWMProfile3, SetStreamPrioritization)
        HRESULT ( STDMETHODCALLTYPE *SetStreamPrioritization )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  IWMStreamPrioritization *pSP);
        
        DECLSPEC_XFGVIRT(IWMProfile3, RemoveStreamPrioritization)
        HRESULT ( STDMETHODCALLTYPE *RemoveStreamPrioritization )( 
            IWMProfile3 * This);
        
        DECLSPEC_XFGVIRT(IWMProfile3, CreateNewStreamPrioritization)
        HRESULT ( STDMETHODCALLTYPE *CreateNewStreamPrioritization )( 
            IWMProfile3 * This,
            /* [annotation][out] */ 
            _Out_  IWMStreamPrioritization **ppSP);
        
        DECLSPEC_XFGVIRT(IWMProfile3, GetExpectedPacketCount)
        HRESULT ( STDMETHODCALLTYPE *GetExpectedPacketCount )( 
            IWMProfile3 * This,
            /* [annotation][in] */ 
            _In_  QWORD msDuration,
            /* [annotation][out] */ 
            _Out_  QWORD *pcPackets);
        
        END_INTERFACE
    } IWMProfile3Vtbl;

    interface IWMProfile3
    {
        CONST_VTBL struct IWMProfile3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMProfile3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMProfile3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMProfile3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMProfile3_GetVersion(This,pdwVersion)	\
    ( (This)->lpVtbl -> GetVersion(This,pdwVersion) ) 

#define IWMProfile3_GetName(This,pwszName,pcchName)	\
    ( (This)->lpVtbl -> GetName(This,pwszName,pcchName) ) 

#define IWMProfile3_SetName(This,pwszName)	\
    ( (This)->lpVtbl -> SetName(This,pwszName) ) 

#define IWMProfile3_GetDescription(This,pwszDescription,pcchDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,pwszDescription,pcchDescription) ) 

#define IWMProfile3_SetDescription(This,pwszDescription)	\
    ( (This)->lpVtbl -> SetDescription(This,pwszDescription) ) 

#define IWMProfile3_GetStreamCount(This,pcStreams)	\
    ( (This)->lpVtbl -> GetStreamCount(This,pcStreams) ) 

#define IWMProfile3_GetStream(This,dwStreamIndex,ppConfig)	\
    ( (This)->lpVtbl -> GetStream(This,dwStreamIndex,ppConfig) ) 

#define IWMProfile3_GetStreamByNumber(This,wStreamNum,ppConfig)	\
    ( (This)->lpVtbl -> GetStreamByNumber(This,wStreamNum,ppConfig) ) 

#define IWMProfile3_RemoveStream(This,pConfig)	\
    ( (This)->lpVtbl -> RemoveStream(This,pConfig) ) 

#define IWMProfile3_RemoveStreamByNumber(This,wStreamNum)	\
    ( (This)->lpVtbl -> RemoveStreamByNumber(This,wStreamNum) ) 

#define IWMProfile3_AddStream(This,pConfig)	\
    ( (This)->lpVtbl -> AddStream(This,pConfig) ) 

#define IWMProfile3_ReconfigStream(This,pConfig)	\
    ( (This)->lpVtbl -> ReconfigStream(This,pConfig) ) 

#define IWMProfile3_CreateNewStream(This,guidStreamType,ppConfig)	\
    ( (This)->lpVtbl -> CreateNewStream(This,guidStreamType,ppConfig) ) 

#define IWMProfile3_GetMutualExclusionCount(This,pcME)	\
    ( (This)->lpVtbl -> GetMutualExclusionCount(This,pcME) ) 

#define IWMProfile3_GetMutualExclusion(This,dwMEIndex,ppME)	\
    ( (This)->lpVtbl -> GetMutualExclusion(This,dwMEIndex,ppME) ) 

#define IWMProfile3_RemoveMutualExclusion(This,pME)	\
    ( (This)->lpVtbl -> RemoveMutualExclusion(This,pME) ) 

#define IWMProfile3_AddMutualExclusion(This,pME)	\
    ( (This)->lpVtbl -> AddMutualExclusion(This,pME) ) 

#define IWMProfile3_CreateNewMutualExclusion(This,ppME)	\
    ( (This)->lpVtbl -> CreateNewMutualExclusion(This,ppME) ) 


#define IWMProfile3_GetProfileID(This,pguidID)	\
    ( (This)->lpVtbl -> GetProfileID(This,pguidID) ) 


#define IWMProfile3_GetStorageFormat(This,pnStorageFormat)	\
    ( (This)->lpVtbl -> GetStorageFormat(This,pnStorageFormat) ) 

#define IWMProfile3_SetStorageFormat(This,nStorageFormat)	\
    ( (This)->lpVtbl -> SetStorageFormat(This,nStorageFormat) ) 

#define IWMProfile3_GetBandwidthSharingCount(This,pcBS)	\
    ( (This)->lpVtbl -> GetBandwidthSharingCount(This,pcBS) ) 

#define IWMProfile3_GetBandwidthSharing(This,dwBSIndex,ppBS)	\
    ( (This)->lpVtbl -> GetBandwidthSharing(This,dwBSIndex,ppBS) ) 

#define IWMProfile3_RemoveBandwidthSharing(This,pBS)	\
    ( (This)->lpVtbl -> RemoveBandwidthSharing(This,pBS) ) 

#define IWMProfile3_AddBandwidthSharing(This,pBS)	\
    ( (This)->lpVtbl -> AddBandwidthSharing(This,pBS) ) 

#define IWMProfile3_CreateNewBandwidthSharing(This,ppBS)	\
    ( (This)->lpVtbl -> CreateNewBandwidthSharing(This,ppBS) ) 

#define IWMProfile3_GetStreamPrioritization(This,ppSP)	\
    ( (This)->lpVtbl -> GetStreamPrioritization(This,ppSP) ) 

#define IWMProfile3_SetStreamPrioritization(This,pSP)	\
    ( (This)->lpVtbl -> SetStreamPrioritization(This,pSP) ) 

#define IWMProfile3_RemoveStreamPrioritization(This)	\
    ( (This)->lpVtbl -> RemoveStreamPrioritization(This) ) 

#define IWMProfile3_CreateNewStreamPrioritization(This,ppSP)	\
    ( (This)->lpVtbl -> CreateNewStreamPrioritization(This,ppSP) ) 

#define IWMProfile3_GetExpectedPacketCount(This,msDuration,pcPackets)	\
    ( (This)->lpVtbl -> GetExpectedPacketCount(This,msDuration,pcPackets) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMProfile3_INTERFACE_DEFINED__ */


#ifndef __IWMStreamConfig_INTERFACE_DEFINED__
#define __IWMStreamConfig_INTERFACE_DEFINED__

/* interface IWMStreamConfig */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMStreamConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BDC-2B2B-11d3-B36B-00C04F6108FF")
    IWMStreamConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStreamType( 
            /* [annotation][out] */ 
            _Out_  GUID *pguidStreamType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamNumber( 
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStreamNumber( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamName( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchStreamName)  WCHAR *pwszStreamName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchStreamName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStreamName( 
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszStreamName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConnectionName( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchInputName)  WCHAR *pwszInputName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchInputName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConnectionName( 
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszInputName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBitrate( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBitrate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBitrate( 
            /* [annotation][in] */ 
            _In_  DWORD pdwBitrate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBufferWindow( 
            /* [annotation][out] */ 
            _Out_  DWORD *pmsBufferWindow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferWindow( 
            /* [annotation][in] */ 
            _In_  DWORD msBufferWindow) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMStreamConfigVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMStreamConfig * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMStreamConfig * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMStreamConfig * This);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetStreamType)
        HRESULT ( STDMETHODCALLTYPE *GetStreamType )( 
            IWMStreamConfig * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidStreamType);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetStreamNumber)
        HRESULT ( STDMETHODCALLTYPE *GetStreamNumber )( 
            IWMStreamConfig * This,
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetStreamNumber)
        HRESULT ( STDMETHODCALLTYPE *SetStreamNumber )( 
            IWMStreamConfig * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetStreamName)
        HRESULT ( STDMETHODCALLTYPE *GetStreamName )( 
            IWMStreamConfig * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchStreamName)  WCHAR *pwszStreamName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchStreamName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetStreamName)
        HRESULT ( STDMETHODCALLTYPE *SetStreamName )( 
            IWMStreamConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszStreamName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetConnectionName)
        HRESULT ( STDMETHODCALLTYPE *GetConnectionName )( 
            IWMStreamConfig * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchInputName)  WCHAR *pwszInputName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchInputName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetConnectionName)
        HRESULT ( STDMETHODCALLTYPE *SetConnectionName )( 
            IWMStreamConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszInputName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetBitrate)
        HRESULT ( STDMETHODCALLTYPE *GetBitrate )( 
            IWMStreamConfig * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBitrate);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetBitrate)
        HRESULT ( STDMETHODCALLTYPE *SetBitrate )( 
            IWMStreamConfig * This,
            /* [annotation][in] */ 
            _In_  DWORD pdwBitrate);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetBufferWindow)
        HRESULT ( STDMETHODCALLTYPE *GetBufferWindow )( 
            IWMStreamConfig * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pmsBufferWindow);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetBufferWindow)
        HRESULT ( STDMETHODCALLTYPE *SetBufferWindow )( 
            IWMStreamConfig * This,
            /* [annotation][in] */ 
            _In_  DWORD msBufferWindow);
        
        END_INTERFACE
    } IWMStreamConfigVtbl;

    interface IWMStreamConfig
    {
        CONST_VTBL struct IWMStreamConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMStreamConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMStreamConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMStreamConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMStreamConfig_GetStreamType(This,pguidStreamType)	\
    ( (This)->lpVtbl -> GetStreamType(This,pguidStreamType) ) 

#define IWMStreamConfig_GetStreamNumber(This,pwStreamNum)	\
    ( (This)->lpVtbl -> GetStreamNumber(This,pwStreamNum) ) 

#define IWMStreamConfig_SetStreamNumber(This,wStreamNum)	\
    ( (This)->lpVtbl -> SetStreamNumber(This,wStreamNum) ) 

#define IWMStreamConfig_GetStreamName(This,pwszStreamName,pcchStreamName)	\
    ( (This)->lpVtbl -> GetStreamName(This,pwszStreamName,pcchStreamName) ) 

#define IWMStreamConfig_SetStreamName(This,pwszStreamName)	\
    ( (This)->lpVtbl -> SetStreamName(This,pwszStreamName) ) 

#define IWMStreamConfig_GetConnectionName(This,pwszInputName,pcchInputName)	\
    ( (This)->lpVtbl -> GetConnectionName(This,pwszInputName,pcchInputName) ) 

#define IWMStreamConfig_SetConnectionName(This,pwszInputName)	\
    ( (This)->lpVtbl -> SetConnectionName(This,pwszInputName) ) 

#define IWMStreamConfig_GetBitrate(This,pdwBitrate)	\
    ( (This)->lpVtbl -> GetBitrate(This,pdwBitrate) ) 

#define IWMStreamConfig_SetBitrate(This,pdwBitrate)	\
    ( (This)->lpVtbl -> SetBitrate(This,pdwBitrate) ) 

#define IWMStreamConfig_GetBufferWindow(This,pmsBufferWindow)	\
    ( (This)->lpVtbl -> GetBufferWindow(This,pmsBufferWindow) ) 

#define IWMStreamConfig_SetBufferWindow(This,msBufferWindow)	\
    ( (This)->lpVtbl -> SetBufferWindow(This,msBufferWindow) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMStreamConfig_INTERFACE_DEFINED__ */


#ifndef __IWMStreamConfig2_INTERFACE_DEFINED__
#define __IWMStreamConfig2_INTERFACE_DEFINED__

/* interface IWMStreamConfig2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMStreamConfig2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7688D8CB-FC0D-43BD-9459-5A8DEC200CFA")
    IWMStreamConfig2 : public IWMStreamConfig
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTransportType( 
            /* [annotation][out] */ 
            _Out_  WMT_TRANSPORT_TYPE *pnTransportType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTransportType( 
            /* [annotation][in] */ 
            _In_  WMT_TRANSPORT_TYPE nTransportType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddDataUnitExtension( 
            /* [annotation][in] */ 
            _In_  GUID guidExtensionSystemID,
            /* [annotation][in] */ 
            _In_  WORD cbExtensionDataSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbExtensionSystemInfo)  BYTE *pbExtensionSystemInfo,
            /* [annotation][in] */ 
            _In_  DWORD cbExtensionSystemInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDataUnitExtensionCount( 
            /* [annotation][out] */ 
            _Out_  WORD *pcDataUnitExtensions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDataUnitExtension( 
            /* [annotation][in] */ 
            _In_  WORD wDataUnitExtensionNumber,
            /* [annotation][out] */ 
            _Out_  GUID *pguidExtensionSystemID,
            /* [annotation][out] */ 
            _Out_  WORD *pcbExtensionDataSize,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbExtensionSystemInfo)  BYTE *pbExtensionSystemInfo,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbExtensionSystemInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAllDataUnitExtensions( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMStreamConfig2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMStreamConfig2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMStreamConfig2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMStreamConfig2 * This);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetStreamType)
        HRESULT ( STDMETHODCALLTYPE *GetStreamType )( 
            IWMStreamConfig2 * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidStreamType);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetStreamNumber)
        HRESULT ( STDMETHODCALLTYPE *GetStreamNumber )( 
            IWMStreamConfig2 * This,
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetStreamNumber)
        HRESULT ( STDMETHODCALLTYPE *SetStreamNumber )( 
            IWMStreamConfig2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetStreamName)
        HRESULT ( STDMETHODCALLTYPE *GetStreamName )( 
            IWMStreamConfig2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchStreamName)  WCHAR *pwszStreamName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchStreamName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetStreamName)
        HRESULT ( STDMETHODCALLTYPE *SetStreamName )( 
            IWMStreamConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszStreamName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetConnectionName)
        HRESULT ( STDMETHODCALLTYPE *GetConnectionName )( 
            IWMStreamConfig2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchInputName)  WCHAR *pwszInputName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchInputName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetConnectionName)
        HRESULT ( STDMETHODCALLTYPE *SetConnectionName )( 
            IWMStreamConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszInputName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetBitrate)
        HRESULT ( STDMETHODCALLTYPE *GetBitrate )( 
            IWMStreamConfig2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBitrate);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetBitrate)
        HRESULT ( STDMETHODCALLTYPE *SetBitrate )( 
            IWMStreamConfig2 * This,
            /* [annotation][in] */ 
            _In_  DWORD pdwBitrate);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetBufferWindow)
        HRESULT ( STDMETHODCALLTYPE *GetBufferWindow )( 
            IWMStreamConfig2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pmsBufferWindow);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetBufferWindow)
        HRESULT ( STDMETHODCALLTYPE *SetBufferWindow )( 
            IWMStreamConfig2 * This,
            /* [annotation][in] */ 
            _In_  DWORD msBufferWindow);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, GetTransportType)
        HRESULT ( STDMETHODCALLTYPE *GetTransportType )( 
            IWMStreamConfig2 * This,
            /* [annotation][out] */ 
            _Out_  WMT_TRANSPORT_TYPE *pnTransportType);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, SetTransportType)
        HRESULT ( STDMETHODCALLTYPE *SetTransportType )( 
            IWMStreamConfig2 * This,
            /* [annotation][in] */ 
            _In_  WMT_TRANSPORT_TYPE nTransportType);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, AddDataUnitExtension)
        HRESULT ( STDMETHODCALLTYPE *AddDataUnitExtension )( 
            IWMStreamConfig2 * This,
            /* [annotation][in] */ 
            _In_  GUID guidExtensionSystemID,
            /* [annotation][in] */ 
            _In_  WORD cbExtensionDataSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbExtensionSystemInfo)  BYTE *pbExtensionSystemInfo,
            /* [annotation][in] */ 
            _In_  DWORD cbExtensionSystemInfo);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, GetDataUnitExtensionCount)
        HRESULT ( STDMETHODCALLTYPE *GetDataUnitExtensionCount )( 
            IWMStreamConfig2 * This,
            /* [annotation][out] */ 
            _Out_  WORD *pcDataUnitExtensions);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, GetDataUnitExtension)
        HRESULT ( STDMETHODCALLTYPE *GetDataUnitExtension )( 
            IWMStreamConfig2 * This,
            /* [annotation][in] */ 
            _In_  WORD wDataUnitExtensionNumber,
            /* [annotation][out] */ 
            _Out_  GUID *pguidExtensionSystemID,
            /* [annotation][out] */ 
            _Out_  WORD *pcbExtensionDataSize,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbExtensionSystemInfo)  BYTE *pbExtensionSystemInfo,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbExtensionSystemInfo);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, RemoveAllDataUnitExtensions)
        HRESULT ( STDMETHODCALLTYPE *RemoveAllDataUnitExtensions )( 
            IWMStreamConfig2 * This);
        
        END_INTERFACE
    } IWMStreamConfig2Vtbl;

    interface IWMStreamConfig2
    {
        CONST_VTBL struct IWMStreamConfig2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMStreamConfig2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMStreamConfig2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMStreamConfig2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMStreamConfig2_GetStreamType(This,pguidStreamType)	\
    ( (This)->lpVtbl -> GetStreamType(This,pguidStreamType) ) 

#define IWMStreamConfig2_GetStreamNumber(This,pwStreamNum)	\
    ( (This)->lpVtbl -> GetStreamNumber(This,pwStreamNum) ) 

#define IWMStreamConfig2_SetStreamNumber(This,wStreamNum)	\
    ( (This)->lpVtbl -> SetStreamNumber(This,wStreamNum) ) 

#define IWMStreamConfig2_GetStreamName(This,pwszStreamName,pcchStreamName)	\
    ( (This)->lpVtbl -> GetStreamName(This,pwszStreamName,pcchStreamName) ) 

#define IWMStreamConfig2_SetStreamName(This,pwszStreamName)	\
    ( (This)->lpVtbl -> SetStreamName(This,pwszStreamName) ) 

#define IWMStreamConfig2_GetConnectionName(This,pwszInputName,pcchInputName)	\
    ( (This)->lpVtbl -> GetConnectionName(This,pwszInputName,pcchInputName) ) 

#define IWMStreamConfig2_SetConnectionName(This,pwszInputName)	\
    ( (This)->lpVtbl -> SetConnectionName(This,pwszInputName) ) 

#define IWMStreamConfig2_GetBitrate(This,pdwBitrate)	\
    ( (This)->lpVtbl -> GetBitrate(This,pdwBitrate) ) 

#define IWMStreamConfig2_SetBitrate(This,pdwBitrate)	\
    ( (This)->lpVtbl -> SetBitrate(This,pdwBitrate) ) 

#define IWMStreamConfig2_GetBufferWindow(This,pmsBufferWindow)	\
    ( (This)->lpVtbl -> GetBufferWindow(This,pmsBufferWindow) ) 

#define IWMStreamConfig2_SetBufferWindow(This,msBufferWindow)	\
    ( (This)->lpVtbl -> SetBufferWindow(This,msBufferWindow) ) 


#define IWMStreamConfig2_GetTransportType(This,pnTransportType)	\
    ( (This)->lpVtbl -> GetTransportType(This,pnTransportType) ) 

#define IWMStreamConfig2_SetTransportType(This,nTransportType)	\
    ( (This)->lpVtbl -> SetTransportType(This,nTransportType) ) 

#define IWMStreamConfig2_AddDataUnitExtension(This,guidExtensionSystemID,cbExtensionDataSize,pbExtensionSystemInfo,cbExtensionSystemInfo)	\
    ( (This)->lpVtbl -> AddDataUnitExtension(This,guidExtensionSystemID,cbExtensionDataSize,pbExtensionSystemInfo,cbExtensionSystemInfo) ) 

#define IWMStreamConfig2_GetDataUnitExtensionCount(This,pcDataUnitExtensions)	\
    ( (This)->lpVtbl -> GetDataUnitExtensionCount(This,pcDataUnitExtensions) ) 

#define IWMStreamConfig2_GetDataUnitExtension(This,wDataUnitExtensionNumber,pguidExtensionSystemID,pcbExtensionDataSize,pbExtensionSystemInfo,pcbExtensionSystemInfo)	\
    ( (This)->lpVtbl -> GetDataUnitExtension(This,wDataUnitExtensionNumber,pguidExtensionSystemID,pcbExtensionDataSize,pbExtensionSystemInfo,pcbExtensionSystemInfo) ) 

#define IWMStreamConfig2_RemoveAllDataUnitExtensions(This)	\
    ( (This)->lpVtbl -> RemoveAllDataUnitExtensions(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMStreamConfig2_INTERFACE_DEFINED__ */


#ifndef __IWMStreamConfig3_INTERFACE_DEFINED__
#define __IWMStreamConfig3_INTERFACE_DEFINED__

/* interface IWMStreamConfig3 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMStreamConfig3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CB164104-3AA9-45a7-9AC9-4DAEE131D6E1")
    IWMStreamConfig3 : public IWMStreamConfig2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLanguage( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchLanguageStringLength)  WCHAR *pwszLanguageString,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchLanguageStringLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLanguage( 
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszLanguageString) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMStreamConfig3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMStreamConfig3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMStreamConfig3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMStreamConfig3 * This);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetStreamType)
        HRESULT ( STDMETHODCALLTYPE *GetStreamType )( 
            IWMStreamConfig3 * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidStreamType);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetStreamNumber)
        HRESULT ( STDMETHODCALLTYPE *GetStreamNumber )( 
            IWMStreamConfig3 * This,
            /* [annotation][out] */ 
            _Out_  WORD *pwStreamNum);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetStreamNumber)
        HRESULT ( STDMETHODCALLTYPE *SetStreamNumber )( 
            IWMStreamConfig3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetStreamName)
        HRESULT ( STDMETHODCALLTYPE *GetStreamName )( 
            IWMStreamConfig3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchStreamName)  WCHAR *pwszStreamName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchStreamName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetStreamName)
        HRESULT ( STDMETHODCALLTYPE *SetStreamName )( 
            IWMStreamConfig3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszStreamName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetConnectionName)
        HRESULT ( STDMETHODCALLTYPE *GetConnectionName )( 
            IWMStreamConfig3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchInputName)  WCHAR *pwszInputName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchInputName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetConnectionName)
        HRESULT ( STDMETHODCALLTYPE *SetConnectionName )( 
            IWMStreamConfig3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszInputName);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetBitrate)
        HRESULT ( STDMETHODCALLTYPE *GetBitrate )( 
            IWMStreamConfig3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBitrate);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetBitrate)
        HRESULT ( STDMETHODCALLTYPE *SetBitrate )( 
            IWMStreamConfig3 * This,
            /* [annotation][in] */ 
            _In_  DWORD pdwBitrate);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, GetBufferWindow)
        HRESULT ( STDMETHODCALLTYPE *GetBufferWindow )( 
            IWMStreamConfig3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pmsBufferWindow);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig, SetBufferWindow)
        HRESULT ( STDMETHODCALLTYPE *SetBufferWindow )( 
            IWMStreamConfig3 * This,
            /* [annotation][in] */ 
            _In_  DWORD msBufferWindow);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, GetTransportType)
        HRESULT ( STDMETHODCALLTYPE *GetTransportType )( 
            IWMStreamConfig3 * This,
            /* [annotation][out] */ 
            _Out_  WMT_TRANSPORT_TYPE *pnTransportType);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, SetTransportType)
        HRESULT ( STDMETHODCALLTYPE *SetTransportType )( 
            IWMStreamConfig3 * This,
            /* [annotation][in] */ 
            _In_  WMT_TRANSPORT_TYPE nTransportType);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, AddDataUnitExtension)
        HRESULT ( STDMETHODCALLTYPE *AddDataUnitExtension )( 
            IWMStreamConfig3 * This,
            /* [annotation][in] */ 
            _In_  GUID guidExtensionSystemID,
            /* [annotation][in] */ 
            _In_  WORD cbExtensionDataSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbExtensionSystemInfo)  BYTE *pbExtensionSystemInfo,
            /* [annotation][in] */ 
            _In_  DWORD cbExtensionSystemInfo);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, GetDataUnitExtensionCount)
        HRESULT ( STDMETHODCALLTYPE *GetDataUnitExtensionCount )( 
            IWMStreamConfig3 * This,
            /* [annotation][out] */ 
            _Out_  WORD *pcDataUnitExtensions);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, GetDataUnitExtension)
        HRESULT ( STDMETHODCALLTYPE *GetDataUnitExtension )( 
            IWMStreamConfig3 * This,
            /* [annotation][in] */ 
            _In_  WORD wDataUnitExtensionNumber,
            /* [annotation][out] */ 
            _Out_  GUID *pguidExtensionSystemID,
            /* [annotation][out] */ 
            _Out_  WORD *pcbExtensionDataSize,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbExtensionSystemInfo)  BYTE *pbExtensionSystemInfo,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbExtensionSystemInfo);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig2, RemoveAllDataUnitExtensions)
        HRESULT ( STDMETHODCALLTYPE *RemoveAllDataUnitExtensions )( 
            IWMStreamConfig3 * This);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig3, GetLanguage)
        HRESULT ( STDMETHODCALLTYPE *GetLanguage )( 
            IWMStreamConfig3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchLanguageStringLength)  WCHAR *pwszLanguageString,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchLanguageStringLength);
        
        DECLSPEC_XFGVIRT(IWMStreamConfig3, SetLanguage)
        HRESULT ( STDMETHODCALLTYPE *SetLanguage )( 
            IWMStreamConfig3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszLanguageString);
        
        END_INTERFACE
    } IWMStreamConfig3Vtbl;

    interface IWMStreamConfig3
    {
        CONST_VTBL struct IWMStreamConfig3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMStreamConfig3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMStreamConfig3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMStreamConfig3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMStreamConfig3_GetStreamType(This,pguidStreamType)	\
    ( (This)->lpVtbl -> GetStreamType(This,pguidStreamType) ) 

#define IWMStreamConfig3_GetStreamNumber(This,pwStreamNum)	\
    ( (This)->lpVtbl -> GetStreamNumber(This,pwStreamNum) ) 

#define IWMStreamConfig3_SetStreamNumber(This,wStreamNum)	\
    ( (This)->lpVtbl -> SetStreamNumber(This,wStreamNum) ) 

#define IWMStreamConfig3_GetStreamName(This,pwszStreamName,pcchStreamName)	\
    ( (This)->lpVtbl -> GetStreamName(This,pwszStreamName,pcchStreamName) ) 

#define IWMStreamConfig3_SetStreamName(This,pwszStreamName)	\
    ( (This)->lpVtbl -> SetStreamName(This,pwszStreamName) ) 

#define IWMStreamConfig3_GetConnectionName(This,pwszInputName,pcchInputName)	\
    ( (This)->lpVtbl -> GetConnectionName(This,pwszInputName,pcchInputName) ) 

#define IWMStreamConfig3_SetConnectionName(This,pwszInputName)	\
    ( (This)->lpVtbl -> SetConnectionName(This,pwszInputName) ) 

#define IWMStreamConfig3_GetBitrate(This,pdwBitrate)	\
    ( (This)->lpVtbl -> GetBitrate(This,pdwBitrate) ) 

#define IWMStreamConfig3_SetBitrate(This,pdwBitrate)	\
    ( (This)->lpVtbl -> SetBitrate(This,pdwBitrate) ) 

#define IWMStreamConfig3_GetBufferWindow(This,pmsBufferWindow)	\
    ( (This)->lpVtbl -> GetBufferWindow(This,pmsBufferWindow) ) 

#define IWMStreamConfig3_SetBufferWindow(This,msBufferWindow)	\
    ( (This)->lpVtbl -> SetBufferWindow(This,msBufferWindow) ) 


#define IWMStreamConfig3_GetTransportType(This,pnTransportType)	\
    ( (This)->lpVtbl -> GetTransportType(This,pnTransportType) ) 

#define IWMStreamConfig3_SetTransportType(This,nTransportType)	\
    ( (This)->lpVtbl -> SetTransportType(This,nTransportType) ) 

#define IWMStreamConfig3_AddDataUnitExtension(This,guidExtensionSystemID,cbExtensionDataSize,pbExtensionSystemInfo,cbExtensionSystemInfo)	\
    ( (This)->lpVtbl -> AddDataUnitExtension(This,guidExtensionSystemID,cbExtensionDataSize,pbExtensionSystemInfo,cbExtensionSystemInfo) ) 

#define IWMStreamConfig3_GetDataUnitExtensionCount(This,pcDataUnitExtensions)	\
    ( (This)->lpVtbl -> GetDataUnitExtensionCount(This,pcDataUnitExtensions) ) 

#define IWMStreamConfig3_GetDataUnitExtension(This,wDataUnitExtensionNumber,pguidExtensionSystemID,pcbExtensionDataSize,pbExtensionSystemInfo,pcbExtensionSystemInfo)	\
    ( (This)->lpVtbl -> GetDataUnitExtension(This,wDataUnitExtensionNumber,pguidExtensionSystemID,pcbExtensionDataSize,pbExtensionSystemInfo,pcbExtensionSystemInfo) ) 

#define IWMStreamConfig3_RemoveAllDataUnitExtensions(This)	\
    ( (This)->lpVtbl -> RemoveAllDataUnitExtensions(This) ) 


#define IWMStreamConfig3_GetLanguage(This,pwszLanguageString,pcchLanguageStringLength)	\
    ( (This)->lpVtbl -> GetLanguage(This,pwszLanguageString,pcchLanguageStringLength) ) 

#define IWMStreamConfig3_SetLanguage(This,pwszLanguageString)	\
    ( (This)->lpVtbl -> SetLanguage(This,pwszLanguageString) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMStreamConfig3_INTERFACE_DEFINED__ */


#ifndef __IWMPacketSize_INTERFACE_DEFINED__
#define __IWMPacketSize_INTERFACE_DEFINED__

/* interface IWMPacketSize */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMPacketSize;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CDFB97AB-188F-40b3-B643-5B7903975C59")
    IWMPacketSize : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMaxPacketSize( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMaxPacketSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxPacketSize( 
            /* [annotation][in] */ 
            _In_  DWORD dwMaxPacketSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMPacketSizeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMPacketSize * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMPacketSize * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMPacketSize * This);
        
        DECLSPEC_XFGVIRT(IWMPacketSize, GetMaxPacketSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxPacketSize )( 
            IWMPacketSize * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMaxPacketSize);
        
        DECLSPEC_XFGVIRT(IWMPacketSize, SetMaxPacketSize)
        HRESULT ( STDMETHODCALLTYPE *SetMaxPacketSize )( 
            IWMPacketSize * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMaxPacketSize);
        
        END_INTERFACE
    } IWMPacketSizeVtbl;

    interface IWMPacketSize
    {
        CONST_VTBL struct IWMPacketSizeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMPacketSize_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMPacketSize_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMPacketSize_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMPacketSize_GetMaxPacketSize(This,pdwMaxPacketSize)	\
    ( (This)->lpVtbl -> GetMaxPacketSize(This,pdwMaxPacketSize) ) 

#define IWMPacketSize_SetMaxPacketSize(This,dwMaxPacketSize)	\
    ( (This)->lpVtbl -> SetMaxPacketSize(This,dwMaxPacketSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMPacketSize_INTERFACE_DEFINED__ */


#ifndef __IWMPacketSize2_INTERFACE_DEFINED__
#define __IWMPacketSize2_INTERFACE_DEFINED__

/* interface IWMPacketSize2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMPacketSize2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8BFC2B9E-B646-4233-A877-1C6A079669DC")
    IWMPacketSize2 : public IWMPacketSize
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMinPacketSize( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMinPacketSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMinPacketSize( 
            /* [annotation][in] */ 
            _In_  DWORD dwMinPacketSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMPacketSize2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMPacketSize2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMPacketSize2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMPacketSize2 * This);
        
        DECLSPEC_XFGVIRT(IWMPacketSize, GetMaxPacketSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxPacketSize )( 
            IWMPacketSize2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMaxPacketSize);
        
        DECLSPEC_XFGVIRT(IWMPacketSize, SetMaxPacketSize)
        HRESULT ( STDMETHODCALLTYPE *SetMaxPacketSize )( 
            IWMPacketSize2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMaxPacketSize);
        
        DECLSPEC_XFGVIRT(IWMPacketSize2, GetMinPacketSize)
        HRESULT ( STDMETHODCALLTYPE *GetMinPacketSize )( 
            IWMPacketSize2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMinPacketSize);
        
        DECLSPEC_XFGVIRT(IWMPacketSize2, SetMinPacketSize)
        HRESULT ( STDMETHODCALLTYPE *SetMinPacketSize )( 
            IWMPacketSize2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMinPacketSize);
        
        END_INTERFACE
    } IWMPacketSize2Vtbl;

    interface IWMPacketSize2
    {
        CONST_VTBL struct IWMPacketSize2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMPacketSize2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMPacketSize2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMPacketSize2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMPacketSize2_GetMaxPacketSize(This,pdwMaxPacketSize)	\
    ( (This)->lpVtbl -> GetMaxPacketSize(This,pdwMaxPacketSize) ) 

#define IWMPacketSize2_SetMaxPacketSize(This,dwMaxPacketSize)	\
    ( (This)->lpVtbl -> SetMaxPacketSize(This,dwMaxPacketSize) ) 


#define IWMPacketSize2_GetMinPacketSize(This,pdwMinPacketSize)	\
    ( (This)->lpVtbl -> GetMinPacketSize(This,pdwMinPacketSize) ) 

#define IWMPacketSize2_SetMinPacketSize(This,dwMinPacketSize)	\
    ( (This)->lpVtbl -> SetMinPacketSize(This,dwMinPacketSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMPacketSize2_INTERFACE_DEFINED__ */


#ifndef __IWMStreamList_INTERFACE_DEFINED__
#define __IWMStreamList_INTERFACE_DEFINED__

/* interface IWMStreamList */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMStreamList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BDD-2B2B-11d3-B36B-00C04F6108FF")
    IWMStreamList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStreams( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcStreams)  WORD *pwStreamNumArray,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcStreams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddStream( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveStream( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMStreamListVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMStreamList * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMStreamList * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMStreamList * This);
        
        DECLSPEC_XFGVIRT(IWMStreamList, GetStreams)
        HRESULT ( STDMETHODCALLTYPE *GetStreams )( 
            IWMStreamList * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcStreams)  WORD *pwStreamNumArray,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcStreams);
        
        DECLSPEC_XFGVIRT(IWMStreamList, AddStream)
        HRESULT ( STDMETHODCALLTYPE *AddStream )( 
            IWMStreamList * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMStreamList, RemoveStream)
        HRESULT ( STDMETHODCALLTYPE *RemoveStream )( 
            IWMStreamList * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        END_INTERFACE
    } IWMStreamListVtbl;

    interface IWMStreamList
    {
        CONST_VTBL struct IWMStreamListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMStreamList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMStreamList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMStreamList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMStreamList_GetStreams(This,pwStreamNumArray,pcStreams)	\
    ( (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams) ) 

#define IWMStreamList_AddStream(This,wStreamNum)	\
    ( (This)->lpVtbl -> AddStream(This,wStreamNum) ) 

#define IWMStreamList_RemoveStream(This,wStreamNum)	\
    ( (This)->lpVtbl -> RemoveStream(This,wStreamNum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMStreamList_INTERFACE_DEFINED__ */


#ifndef __IWMMutualExclusion_INTERFACE_DEFINED__
#define __IWMMutualExclusion_INTERFACE_DEFINED__

/* interface IWMMutualExclusion */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMMutualExclusion;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BDE-2B2B-11d3-B36B-00C04F6108FF")
    IWMMutualExclusion : public IWMStreamList
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [annotation][out] */ 
            _Out_  GUID *pguidType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetType( 
            /* [annotation][in] */ 
            _In_  REFGUID guidType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMMutualExclusionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMMutualExclusion * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMMutualExclusion * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMMutualExclusion * This);
        
        DECLSPEC_XFGVIRT(IWMStreamList, GetStreams)
        HRESULT ( STDMETHODCALLTYPE *GetStreams )( 
            IWMMutualExclusion * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcStreams)  WORD *pwStreamNumArray,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcStreams);
        
        DECLSPEC_XFGVIRT(IWMStreamList, AddStream)
        HRESULT ( STDMETHODCALLTYPE *AddStream )( 
            IWMMutualExclusion * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMStreamList, RemoveStream)
        HRESULT ( STDMETHODCALLTYPE *RemoveStream )( 
            IWMMutualExclusion * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion, GetType)
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IWMMutualExclusion * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidType);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion, SetType)
        HRESULT ( STDMETHODCALLTYPE *SetType )( 
            IWMMutualExclusion * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType);
        
        END_INTERFACE
    } IWMMutualExclusionVtbl;

    interface IWMMutualExclusion
    {
        CONST_VTBL struct IWMMutualExclusionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMMutualExclusion_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMMutualExclusion_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMMutualExclusion_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMMutualExclusion_GetStreams(This,pwStreamNumArray,pcStreams)	\
    ( (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams) ) 

#define IWMMutualExclusion_AddStream(This,wStreamNum)	\
    ( (This)->lpVtbl -> AddStream(This,wStreamNum) ) 

#define IWMMutualExclusion_RemoveStream(This,wStreamNum)	\
    ( (This)->lpVtbl -> RemoveStream(This,wStreamNum) ) 


#define IWMMutualExclusion_GetType(This,pguidType)	\
    ( (This)->lpVtbl -> GetType(This,pguidType) ) 

#define IWMMutualExclusion_SetType(This,guidType)	\
    ( (This)->lpVtbl -> SetType(This,guidType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMMutualExclusion_INTERFACE_DEFINED__ */


#ifndef __IWMMutualExclusion2_INTERFACE_DEFINED__
#define __IWMMutualExclusion2_INTERFACE_DEFINED__

/* interface IWMMutualExclusion2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMMutualExclusion2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0302B57D-89D1-4ba2-85C9-166F2C53EB91")
    IWMMutualExclusion2 : public IWMMutualExclusion
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordCount( 
            /* [annotation][out] */ 
            _Out_  WORD *pwRecordCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRecord( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveRecord( 
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordName( 
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchRecordName)  WCHAR *pwszRecordName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchRecordName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecordName( 
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszRecordName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamsForRecord( 
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcStreams)  WORD *pwStreamNumArray,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcStreams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddStreamForRecord( 
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveStreamForRecord( 
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMMutualExclusion2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMMutualExclusion2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMMutualExclusion2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMMutualExclusion2 * This);
        
        DECLSPEC_XFGVIRT(IWMStreamList, GetStreams)
        HRESULT ( STDMETHODCALLTYPE *GetStreams )( 
            IWMMutualExclusion2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcStreams)  WORD *pwStreamNumArray,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcStreams);
        
        DECLSPEC_XFGVIRT(IWMStreamList, AddStream)
        HRESULT ( STDMETHODCALLTYPE *AddStream )( 
            IWMMutualExclusion2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMStreamList, RemoveStream)
        HRESULT ( STDMETHODCALLTYPE *RemoveStream )( 
            IWMMutualExclusion2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion, GetType)
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IWMMutualExclusion2 * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidType);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion, SetType)
        HRESULT ( STDMETHODCALLTYPE *SetType )( 
            IWMMutualExclusion2 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion2, GetName)
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IWMMutualExclusion2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchName);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion2, SetName)
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IWMMutualExclusion2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszName);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion2, GetRecordCount)
        HRESULT ( STDMETHODCALLTYPE *GetRecordCount )( 
            IWMMutualExclusion2 * This,
            /* [annotation][out] */ 
            _Out_  WORD *pwRecordCount);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion2, AddRecord)
        HRESULT ( STDMETHODCALLTYPE *AddRecord )( 
            IWMMutualExclusion2 * This);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion2, RemoveRecord)
        HRESULT ( STDMETHODCALLTYPE *RemoveRecord )( 
            IWMMutualExclusion2 * This,
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion2, GetRecordName)
        HRESULT ( STDMETHODCALLTYPE *GetRecordName )( 
            IWMMutualExclusion2 * This,
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchRecordName)  WCHAR *pwszRecordName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchRecordName);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion2, SetRecordName)
        HRESULT ( STDMETHODCALLTYPE *SetRecordName )( 
            IWMMutualExclusion2 * This,
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszRecordName);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion2, GetStreamsForRecord)
        HRESULT ( STDMETHODCALLTYPE *GetStreamsForRecord )( 
            IWMMutualExclusion2 * This,
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcStreams)  WORD *pwStreamNumArray,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcStreams);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion2, AddStreamForRecord)
        HRESULT ( STDMETHODCALLTYPE *AddStreamForRecord )( 
            IWMMutualExclusion2 * This,
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber);
        
        DECLSPEC_XFGVIRT(IWMMutualExclusion2, RemoveStreamForRecord)
        HRESULT ( STDMETHODCALLTYPE *RemoveStreamForRecord )( 
            IWMMutualExclusion2 * This,
            /* [annotation][in] */ 
            _In_  WORD wRecordNumber,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber);
        
        END_INTERFACE
    } IWMMutualExclusion2Vtbl;

    interface IWMMutualExclusion2
    {
        CONST_VTBL struct IWMMutualExclusion2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMMutualExclusion2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMMutualExclusion2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMMutualExclusion2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMMutualExclusion2_GetStreams(This,pwStreamNumArray,pcStreams)	\
    ( (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams) ) 

#define IWMMutualExclusion2_AddStream(This,wStreamNum)	\
    ( (This)->lpVtbl -> AddStream(This,wStreamNum) ) 

#define IWMMutualExclusion2_RemoveStream(This,wStreamNum)	\
    ( (This)->lpVtbl -> RemoveStream(This,wStreamNum) ) 


#define IWMMutualExclusion2_GetType(This,pguidType)	\
    ( (This)->lpVtbl -> GetType(This,pguidType) ) 

#define IWMMutualExclusion2_SetType(This,guidType)	\
    ( (This)->lpVtbl -> SetType(This,guidType) ) 


#define IWMMutualExclusion2_GetName(This,pwszName,pcchName)	\
    ( (This)->lpVtbl -> GetName(This,pwszName,pcchName) ) 

#define IWMMutualExclusion2_SetName(This,pwszName)	\
    ( (This)->lpVtbl -> SetName(This,pwszName) ) 

#define IWMMutualExclusion2_GetRecordCount(This,pwRecordCount)	\
    ( (This)->lpVtbl -> GetRecordCount(This,pwRecordCount) ) 

#define IWMMutualExclusion2_AddRecord(This)	\
    ( (This)->lpVtbl -> AddRecord(This) ) 

#define IWMMutualExclusion2_RemoveRecord(This,wRecordNumber)	\
    ( (This)->lpVtbl -> RemoveRecord(This,wRecordNumber) ) 

#define IWMMutualExclusion2_GetRecordName(This,wRecordNumber,pwszRecordName,pcchRecordName)	\
    ( (This)->lpVtbl -> GetRecordName(This,wRecordNumber,pwszRecordName,pcchRecordName) ) 

#define IWMMutualExclusion2_SetRecordName(This,wRecordNumber,pwszRecordName)	\
    ( (This)->lpVtbl -> SetRecordName(This,wRecordNumber,pwszRecordName) ) 

#define IWMMutualExclusion2_GetStreamsForRecord(This,wRecordNumber,pwStreamNumArray,pcStreams)	\
    ( (This)->lpVtbl -> GetStreamsForRecord(This,wRecordNumber,pwStreamNumArray,pcStreams) ) 

#define IWMMutualExclusion2_AddStreamForRecord(This,wRecordNumber,wStreamNumber)	\
    ( (This)->lpVtbl -> AddStreamForRecord(This,wRecordNumber,wStreamNumber) ) 

#define IWMMutualExclusion2_RemoveStreamForRecord(This,wRecordNumber,wStreamNumber)	\
    ( (This)->lpVtbl -> RemoveStreamForRecord(This,wRecordNumber,wStreamNumber) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMMutualExclusion2_INTERFACE_DEFINED__ */


#ifndef __IWMBandwidthSharing_INTERFACE_DEFINED__
#define __IWMBandwidthSharing_INTERFACE_DEFINED__

/* interface IWMBandwidthSharing */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMBandwidthSharing;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD694AF1-F8D9-42F8-BC47-70311B0C4F9E")
    IWMBandwidthSharing : public IWMStreamList
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [annotation][out] */ 
            _Out_  GUID *pguidType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetType( 
            /* [annotation][in] */ 
            _In_  REFGUID guidType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBandwidth( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBitrate,
            /* [annotation][out] */ 
            _Out_  DWORD *pmsBufferWindow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBandwidth( 
            /* [annotation][in] */ 
            _In_  DWORD dwBitrate,
            /* [annotation][in] */ 
            _In_  DWORD msBufferWindow) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMBandwidthSharingVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMBandwidthSharing * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMBandwidthSharing * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMBandwidthSharing * This);
        
        DECLSPEC_XFGVIRT(IWMStreamList, GetStreams)
        HRESULT ( STDMETHODCALLTYPE *GetStreams )( 
            IWMBandwidthSharing * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcStreams)  WORD *pwStreamNumArray,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcStreams);
        
        DECLSPEC_XFGVIRT(IWMStreamList, AddStream)
        HRESULT ( STDMETHODCALLTYPE *AddStream )( 
            IWMBandwidthSharing * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMStreamList, RemoveStream)
        HRESULT ( STDMETHODCALLTYPE *RemoveStream )( 
            IWMBandwidthSharing * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum);
        
        DECLSPEC_XFGVIRT(IWMBandwidthSharing, GetType)
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IWMBandwidthSharing * This,
            /* [annotation][out] */ 
            _Out_  GUID *pguidType);
        
        DECLSPEC_XFGVIRT(IWMBandwidthSharing, SetType)
        HRESULT ( STDMETHODCALLTYPE *SetType )( 
            IWMBandwidthSharing * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType);
        
        DECLSPEC_XFGVIRT(IWMBandwidthSharing, GetBandwidth)
        HRESULT ( STDMETHODCALLTYPE *GetBandwidth )( 
            IWMBandwidthSharing * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwBitrate,
            /* [annotation][out] */ 
            _Out_  DWORD *pmsBufferWindow);
        
        DECLSPEC_XFGVIRT(IWMBandwidthSharing, SetBandwidth)
        HRESULT ( STDMETHODCALLTYPE *SetBandwidth )( 
            IWMBandwidthSharing * This,
            /* [annotation][in] */ 
            _In_  DWORD dwBitrate,
            /* [annotation][in] */ 
            _In_  DWORD msBufferWindow);
        
        END_INTERFACE
    } IWMBandwidthSharingVtbl;

    interface IWMBandwidthSharing
    {
        CONST_VTBL struct IWMBandwidthSharingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMBandwidthSharing_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMBandwidthSharing_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMBandwidthSharing_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMBandwidthSharing_GetStreams(This,pwStreamNumArray,pcStreams)	\
    ( (This)->lpVtbl -> GetStreams(This,pwStreamNumArray,pcStreams) ) 

#define IWMBandwidthSharing_AddStream(This,wStreamNum)	\
    ( (This)->lpVtbl -> AddStream(This,wStreamNum) ) 

#define IWMBandwidthSharing_RemoveStream(This,wStreamNum)	\
    ( (This)->lpVtbl -> RemoveStream(This,wStreamNum) ) 


#define IWMBandwidthSharing_GetType(This,pguidType)	\
    ( (This)->lpVtbl -> GetType(This,pguidType) ) 

#define IWMBandwidthSharing_SetType(This,guidType)	\
    ( (This)->lpVtbl -> SetType(This,guidType) ) 

#define IWMBandwidthSharing_GetBandwidth(This,pdwBitrate,pmsBufferWindow)	\
    ( (This)->lpVtbl -> GetBandwidth(This,pdwBitrate,pmsBufferWindow) ) 

#define IWMBandwidthSharing_SetBandwidth(This,dwBitrate,msBufferWindow)	\
    ( (This)->lpVtbl -> SetBandwidth(This,dwBitrate,msBufferWindow) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMBandwidthSharing_INTERFACE_DEFINED__ */


#ifndef __IWMStreamPrioritization_INTERFACE_DEFINED__
#define __IWMStreamPrioritization_INTERFACE_DEFINED__

/* interface IWMStreamPrioritization */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMStreamPrioritization;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8C1C6090-F9A8-4748-8EC3-DD1108BA1E77")
    IWMStreamPrioritization : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPriorityRecords( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcRecords)  WM_STREAM_PRIORITY_RECORD *pRecordArray,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcRecords) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPriorityRecords( 
            /* [annotation][in] */ 
            _In_  WM_STREAM_PRIORITY_RECORD *pRecordArray,
            /* [annotation][in] */ 
            _In_  WORD cRecords) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMStreamPrioritizationVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMStreamPrioritization * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMStreamPrioritization * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMStreamPrioritization * This);
        
        DECLSPEC_XFGVIRT(IWMStreamPrioritization, GetPriorityRecords)
        HRESULT ( STDMETHODCALLTYPE *GetPriorityRecords )( 
            IWMStreamPrioritization * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcRecords)  WM_STREAM_PRIORITY_RECORD *pRecordArray,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcRecords);
        
        DECLSPEC_XFGVIRT(IWMStreamPrioritization, SetPriorityRecords)
        HRESULT ( STDMETHODCALLTYPE *SetPriorityRecords )( 
            IWMStreamPrioritization * This,
            /* [annotation][in] */ 
            _In_  WM_STREAM_PRIORITY_RECORD *pRecordArray,
            /* [annotation][in] */ 
            _In_  WORD cRecords);
        
        END_INTERFACE
    } IWMStreamPrioritizationVtbl;

    interface IWMStreamPrioritization
    {
        CONST_VTBL struct IWMStreamPrioritizationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMStreamPrioritization_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMStreamPrioritization_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMStreamPrioritization_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMStreamPrioritization_GetPriorityRecords(This,pRecordArray,pcRecords)	\
    ( (This)->lpVtbl -> GetPriorityRecords(This,pRecordArray,pcRecords) ) 

#define IWMStreamPrioritization_SetPriorityRecords(This,pRecordArray,cRecords)	\
    ( (This)->lpVtbl -> SetPriorityRecords(This,pRecordArray,cRecords) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMStreamPrioritization_INTERFACE_DEFINED__ */


#ifndef __IWMWriterAdvanced_INTERFACE_DEFINED__
#define __IWMWriterAdvanced_INTERFACE_DEFINED__

/* interface IWMWriterAdvanced */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterAdvanced;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BE3-2B2B-11d3-B36B-00C04F6108FF")
    IWMWriterAdvanced : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSinkCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcSinks) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSink( 
            /* [annotation][in] */ 
            _In_  DWORD dwSinkNum,
            /* [annotation][out] */ 
            _Out_  IWMWriterSink **ppSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddSink( 
            /* [annotation][in] */ 
            _In_  IWMWriterSink *pSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveSink( 
            /* [annotation][in] */ 
            _In_  IWMWriterSink *pSink) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteStreamSample( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  DWORD msSampleSendTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLiveSource( 
            BOOL fIsLiveSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsRealTime( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfRealTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWriterTime( 
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsCurrentTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatistics( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WM_WRITER_STATISTICS *pStats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSyncTolerance( 
            /* [annotation][in] */ 
            _In_  DWORD msWindow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSyncTolerance( 
            /* [annotation][out] */ 
            _Out_  DWORD *pmsWindow) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterAdvancedVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterAdvanced * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterAdvanced * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterAdvanced * This);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetSinkCount)
        HRESULT ( STDMETHODCALLTYPE *GetSinkCount )( 
            IWMWriterAdvanced * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcSinks);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetSink)
        HRESULT ( STDMETHODCALLTYPE *GetSink )( 
            IWMWriterAdvanced * This,
            /* [annotation][in] */ 
            _In_  DWORD dwSinkNum,
            /* [annotation][out] */ 
            _Out_  IWMWriterSink **ppSink);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, AddSink)
        HRESULT ( STDMETHODCALLTYPE *AddSink )( 
            IWMWriterAdvanced * This,
            /* [annotation][in] */ 
            _In_  IWMWriterSink *pSink);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, RemoveSink)
        HRESULT ( STDMETHODCALLTYPE *RemoveSink )( 
            IWMWriterAdvanced * This,
            /* [annotation][in] */ 
            _In_  IWMWriterSink *pSink);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, WriteStreamSample)
        HRESULT ( STDMETHODCALLTYPE *WriteStreamSample )( 
            IWMWriterAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  DWORD msSampleSendTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, SetLiveSource)
        HRESULT ( STDMETHODCALLTYPE *SetLiveSource )( 
            IWMWriterAdvanced * This,
            BOOL fIsLiveSource);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, IsRealTime)
        HRESULT ( STDMETHODCALLTYPE *IsRealTime )( 
            IWMWriterAdvanced * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfRealTime);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetWriterTime)
        HRESULT ( STDMETHODCALLTYPE *GetWriterTime )( 
            IWMWriterAdvanced * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsCurrentTime);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetStatistics)
        HRESULT ( STDMETHODCALLTYPE *GetStatistics )( 
            IWMWriterAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WM_WRITER_STATISTICS *pStats);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, SetSyncTolerance)
        HRESULT ( STDMETHODCALLTYPE *SetSyncTolerance )( 
            IWMWriterAdvanced * This,
            /* [annotation][in] */ 
            _In_  DWORD msWindow);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetSyncTolerance)
        HRESULT ( STDMETHODCALLTYPE *GetSyncTolerance )( 
            IWMWriterAdvanced * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pmsWindow);
        
        END_INTERFACE
    } IWMWriterAdvancedVtbl;

    interface IWMWriterAdvanced
    {
        CONST_VTBL struct IWMWriterAdvancedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterAdvanced_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterAdvanced_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterAdvanced_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterAdvanced_GetSinkCount(This,pcSinks)	\
    ( (This)->lpVtbl -> GetSinkCount(This,pcSinks) ) 

#define IWMWriterAdvanced_GetSink(This,dwSinkNum,ppSink)	\
    ( (This)->lpVtbl -> GetSink(This,dwSinkNum,ppSink) ) 

#define IWMWriterAdvanced_AddSink(This,pSink)	\
    ( (This)->lpVtbl -> AddSink(This,pSink) ) 

#define IWMWriterAdvanced_RemoveSink(This,pSink)	\
    ( (This)->lpVtbl -> RemoveSink(This,pSink) ) 

#define IWMWriterAdvanced_WriteStreamSample(This,wStreamNum,cnsSampleTime,msSampleSendTime,cnsSampleDuration,dwFlags,pSample)	\
    ( (This)->lpVtbl -> WriteStreamSample(This,wStreamNum,cnsSampleTime,msSampleSendTime,cnsSampleDuration,dwFlags,pSample) ) 

#define IWMWriterAdvanced_SetLiveSource(This,fIsLiveSource)	\
    ( (This)->lpVtbl -> SetLiveSource(This,fIsLiveSource) ) 

#define IWMWriterAdvanced_IsRealTime(This,pfRealTime)	\
    ( (This)->lpVtbl -> IsRealTime(This,pfRealTime) ) 

#define IWMWriterAdvanced_GetWriterTime(This,pcnsCurrentTime)	\
    ( (This)->lpVtbl -> GetWriterTime(This,pcnsCurrentTime) ) 

#define IWMWriterAdvanced_GetStatistics(This,wStreamNum,pStats)	\
    ( (This)->lpVtbl -> GetStatistics(This,wStreamNum,pStats) ) 

#define IWMWriterAdvanced_SetSyncTolerance(This,msWindow)	\
    ( (This)->lpVtbl -> SetSyncTolerance(This,msWindow) ) 

#define IWMWriterAdvanced_GetSyncTolerance(This,pmsWindow)	\
    ( (This)->lpVtbl -> GetSyncTolerance(This,pmsWindow) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterAdvanced_INTERFACE_DEFINED__ */


#ifndef __IWMWriterAdvanced2_INTERFACE_DEFINED__
#define __IWMWriterAdvanced2_INTERFACE_DEFINED__

/* interface IWMWriterAdvanced2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterAdvanced2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("962dc1ec-c046-4db8-9cc7-26ceae500817")
    IWMWriterAdvanced2 : public IWMWriterAdvanced
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInputSetting( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInputSetting( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterAdvanced2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterAdvanced2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterAdvanced2 * This);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetSinkCount)
        HRESULT ( STDMETHODCALLTYPE *GetSinkCount )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcSinks);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetSink)
        HRESULT ( STDMETHODCALLTYPE *GetSink )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwSinkNum,
            /* [annotation][out] */ 
            _Out_  IWMWriterSink **ppSink);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, AddSink)
        HRESULT ( STDMETHODCALLTYPE *AddSink )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  IWMWriterSink *pSink);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, RemoveSink)
        HRESULT ( STDMETHODCALLTYPE *RemoveSink )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  IWMWriterSink *pSink);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, WriteStreamSample)
        HRESULT ( STDMETHODCALLTYPE *WriteStreamSample )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  DWORD msSampleSendTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, SetLiveSource)
        HRESULT ( STDMETHODCALLTYPE *SetLiveSource )( 
            IWMWriterAdvanced2 * This,
            BOOL fIsLiveSource);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, IsRealTime)
        HRESULT ( STDMETHODCALLTYPE *IsRealTime )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfRealTime);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetWriterTime)
        HRESULT ( STDMETHODCALLTYPE *GetWriterTime )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsCurrentTime);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetStatistics)
        HRESULT ( STDMETHODCALLTYPE *GetStatistics )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WM_WRITER_STATISTICS *pStats);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, SetSyncTolerance)
        HRESULT ( STDMETHODCALLTYPE *SetSyncTolerance )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  DWORD msWindow);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetSyncTolerance)
        HRESULT ( STDMETHODCALLTYPE *GetSyncTolerance )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pmsWindow);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced2, GetInputSetting)
        HRESULT ( STDMETHODCALLTYPE *GetInputSetting )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced2, SetInputSetting)
        HRESULT ( STDMETHODCALLTYPE *SetInputSetting )( 
            IWMWriterAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        END_INTERFACE
    } IWMWriterAdvanced2Vtbl;

    interface IWMWriterAdvanced2
    {
        CONST_VTBL struct IWMWriterAdvanced2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterAdvanced2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterAdvanced2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterAdvanced2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterAdvanced2_GetSinkCount(This,pcSinks)	\
    ( (This)->lpVtbl -> GetSinkCount(This,pcSinks) ) 

#define IWMWriterAdvanced2_GetSink(This,dwSinkNum,ppSink)	\
    ( (This)->lpVtbl -> GetSink(This,dwSinkNum,ppSink) ) 

#define IWMWriterAdvanced2_AddSink(This,pSink)	\
    ( (This)->lpVtbl -> AddSink(This,pSink) ) 

#define IWMWriterAdvanced2_RemoveSink(This,pSink)	\
    ( (This)->lpVtbl -> RemoveSink(This,pSink) ) 

#define IWMWriterAdvanced2_WriteStreamSample(This,wStreamNum,cnsSampleTime,msSampleSendTime,cnsSampleDuration,dwFlags,pSample)	\
    ( (This)->lpVtbl -> WriteStreamSample(This,wStreamNum,cnsSampleTime,msSampleSendTime,cnsSampleDuration,dwFlags,pSample) ) 

#define IWMWriterAdvanced2_SetLiveSource(This,fIsLiveSource)	\
    ( (This)->lpVtbl -> SetLiveSource(This,fIsLiveSource) ) 

#define IWMWriterAdvanced2_IsRealTime(This,pfRealTime)	\
    ( (This)->lpVtbl -> IsRealTime(This,pfRealTime) ) 

#define IWMWriterAdvanced2_GetWriterTime(This,pcnsCurrentTime)	\
    ( (This)->lpVtbl -> GetWriterTime(This,pcnsCurrentTime) ) 

#define IWMWriterAdvanced2_GetStatistics(This,wStreamNum,pStats)	\
    ( (This)->lpVtbl -> GetStatistics(This,wStreamNum,pStats) ) 

#define IWMWriterAdvanced2_SetSyncTolerance(This,msWindow)	\
    ( (This)->lpVtbl -> SetSyncTolerance(This,msWindow) ) 

#define IWMWriterAdvanced2_GetSyncTolerance(This,pmsWindow)	\
    ( (This)->lpVtbl -> GetSyncTolerance(This,pmsWindow) ) 


#define IWMWriterAdvanced2_GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength) ) 

#define IWMWriterAdvanced2_SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterAdvanced2_INTERFACE_DEFINED__ */


#ifndef __IWMWriterAdvanced3_INTERFACE_DEFINED__
#define __IWMWriterAdvanced3_INTERFACE_DEFINED__

/* interface IWMWriterAdvanced3 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterAdvanced3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2cd6492d-7c37-4e76-9d3b-59261183a22e")
    IWMWriterAdvanced3 : public IWMWriterAdvanced2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStatisticsEx( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WM_WRITER_STATISTICS_EX *pStats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNonBlocking( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterAdvanced3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterAdvanced3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterAdvanced3 * This);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetSinkCount)
        HRESULT ( STDMETHODCALLTYPE *GetSinkCount )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcSinks);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetSink)
        HRESULT ( STDMETHODCALLTYPE *GetSink )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwSinkNum,
            /* [annotation][out] */ 
            _Out_  IWMWriterSink **ppSink);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, AddSink)
        HRESULT ( STDMETHODCALLTYPE *AddSink )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  IWMWriterSink *pSink);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, RemoveSink)
        HRESULT ( STDMETHODCALLTYPE *RemoveSink )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  IWMWriterSink *pSink);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, WriteStreamSample)
        HRESULT ( STDMETHODCALLTYPE *WriteStreamSample )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  DWORD msSampleSendTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, SetLiveSource)
        HRESULT ( STDMETHODCALLTYPE *SetLiveSource )( 
            IWMWriterAdvanced3 * This,
            BOOL fIsLiveSource);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, IsRealTime)
        HRESULT ( STDMETHODCALLTYPE *IsRealTime )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfRealTime);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetWriterTime)
        HRESULT ( STDMETHODCALLTYPE *GetWriterTime )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsCurrentTime);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetStatistics)
        HRESULT ( STDMETHODCALLTYPE *GetStatistics )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WM_WRITER_STATISTICS *pStats);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, SetSyncTolerance)
        HRESULT ( STDMETHODCALLTYPE *SetSyncTolerance )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  DWORD msWindow);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced, GetSyncTolerance)
        HRESULT ( STDMETHODCALLTYPE *GetSyncTolerance )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pmsWindow);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced2, GetInputSetting)
        HRESULT ( STDMETHODCALLTYPE *GetInputSetting )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced2, SetInputSetting)
        HRESULT ( STDMETHODCALLTYPE *SetInputSetting )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced3, GetStatisticsEx)
        HRESULT ( STDMETHODCALLTYPE *GetStatisticsEx )( 
            IWMWriterAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WM_WRITER_STATISTICS_EX *pStats);
        
        DECLSPEC_XFGVIRT(IWMWriterAdvanced3, SetNonBlocking)
        HRESULT ( STDMETHODCALLTYPE *SetNonBlocking )( 
            IWMWriterAdvanced3 * This);
        
        END_INTERFACE
    } IWMWriterAdvanced3Vtbl;

    interface IWMWriterAdvanced3
    {
        CONST_VTBL struct IWMWriterAdvanced3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterAdvanced3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterAdvanced3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterAdvanced3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterAdvanced3_GetSinkCount(This,pcSinks)	\
    ( (This)->lpVtbl -> GetSinkCount(This,pcSinks) ) 

#define IWMWriterAdvanced3_GetSink(This,dwSinkNum,ppSink)	\
    ( (This)->lpVtbl -> GetSink(This,dwSinkNum,ppSink) ) 

#define IWMWriterAdvanced3_AddSink(This,pSink)	\
    ( (This)->lpVtbl -> AddSink(This,pSink) ) 

#define IWMWriterAdvanced3_RemoveSink(This,pSink)	\
    ( (This)->lpVtbl -> RemoveSink(This,pSink) ) 

#define IWMWriterAdvanced3_WriteStreamSample(This,wStreamNum,cnsSampleTime,msSampleSendTime,cnsSampleDuration,dwFlags,pSample)	\
    ( (This)->lpVtbl -> WriteStreamSample(This,wStreamNum,cnsSampleTime,msSampleSendTime,cnsSampleDuration,dwFlags,pSample) ) 

#define IWMWriterAdvanced3_SetLiveSource(This,fIsLiveSource)	\
    ( (This)->lpVtbl -> SetLiveSource(This,fIsLiveSource) ) 

#define IWMWriterAdvanced3_IsRealTime(This,pfRealTime)	\
    ( (This)->lpVtbl -> IsRealTime(This,pfRealTime) ) 

#define IWMWriterAdvanced3_GetWriterTime(This,pcnsCurrentTime)	\
    ( (This)->lpVtbl -> GetWriterTime(This,pcnsCurrentTime) ) 

#define IWMWriterAdvanced3_GetStatistics(This,wStreamNum,pStats)	\
    ( (This)->lpVtbl -> GetStatistics(This,wStreamNum,pStats) ) 

#define IWMWriterAdvanced3_SetSyncTolerance(This,msWindow)	\
    ( (This)->lpVtbl -> SetSyncTolerance(This,msWindow) ) 

#define IWMWriterAdvanced3_GetSyncTolerance(This,pmsWindow)	\
    ( (This)->lpVtbl -> GetSyncTolerance(This,pmsWindow) ) 


#define IWMWriterAdvanced3_GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetInputSetting(This,dwInputNum,pszName,pType,pValue,pcbLength) ) 

#define IWMWriterAdvanced3_SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetInputSetting(This,dwInputNum,pszName,Type,pValue,cbLength) ) 


#define IWMWriterAdvanced3_GetStatisticsEx(This,wStreamNum,pStats)	\
    ( (This)->lpVtbl -> GetStatisticsEx(This,wStreamNum,pStats) ) 

#define IWMWriterAdvanced3_SetNonBlocking(This)	\
    ( (This)->lpVtbl -> SetNonBlocking(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterAdvanced3_INTERFACE_DEFINED__ */


#ifndef __IWMWriterPreprocess_INTERFACE_DEFINED__
#define __IWMWriterPreprocess_INTERFACE_DEFINED__

/* interface IWMWriterPreprocess */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterPreprocess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fc54a285-38c4-45b5-aa23-85b9f7cb424b")
    IWMWriterPreprocess : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMaxPreprocessingPasses( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMaxNumPasses) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNumPreprocessingPasses( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwNumPasses) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginPreprocessingPass( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PreprocessSample( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndPreprocessingPass( 
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterPreprocessVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterPreprocess * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterPreprocess * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterPreprocess * This);
        
        DECLSPEC_XFGVIRT(IWMWriterPreprocess, GetMaxPreprocessingPasses)
        HRESULT ( STDMETHODCALLTYPE *GetMaxPreprocessingPasses )( 
            IWMWriterPreprocess * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMaxNumPasses);
        
        DECLSPEC_XFGVIRT(IWMWriterPreprocess, SetNumPreprocessingPasses)
        HRESULT ( STDMETHODCALLTYPE *SetNumPreprocessingPasses )( 
            IWMWriterPreprocess * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  DWORD dwNumPasses);
        
        DECLSPEC_XFGVIRT(IWMWriterPreprocess, BeginPreprocessingPass)
        HRESULT ( STDMETHODCALLTYPE *BeginPreprocessingPass )( 
            IWMWriterPreprocess * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IWMWriterPreprocess, PreprocessSample)
        HRESULT ( STDMETHODCALLTYPE *PreprocessSample )( 
            IWMWriterPreprocess * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample);
        
        DECLSPEC_XFGVIRT(IWMWriterPreprocess, EndPreprocessingPass)
        HRESULT ( STDMETHODCALLTYPE *EndPreprocessingPass )( 
            IWMWriterPreprocess * This,
            /* [annotation][in] */ 
            _In_  DWORD dwInputNum,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        END_INTERFACE
    } IWMWriterPreprocessVtbl;

    interface IWMWriterPreprocess
    {
        CONST_VTBL struct IWMWriterPreprocessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterPreprocess_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterPreprocess_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterPreprocess_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterPreprocess_GetMaxPreprocessingPasses(This,dwInputNum,dwFlags,pdwMaxNumPasses)	\
    ( (This)->lpVtbl -> GetMaxPreprocessingPasses(This,dwInputNum,dwFlags,pdwMaxNumPasses) ) 

#define IWMWriterPreprocess_SetNumPreprocessingPasses(This,dwInputNum,dwFlags,dwNumPasses)	\
    ( (This)->lpVtbl -> SetNumPreprocessingPasses(This,dwInputNum,dwFlags,dwNumPasses) ) 

#define IWMWriterPreprocess_BeginPreprocessingPass(This,dwInputNum,dwFlags)	\
    ( (This)->lpVtbl -> BeginPreprocessingPass(This,dwInputNum,dwFlags) ) 

#define IWMWriterPreprocess_PreprocessSample(This,dwInputNum,cnsSampleTime,dwFlags,pSample)	\
    ( (This)->lpVtbl -> PreprocessSample(This,dwInputNum,cnsSampleTime,dwFlags,pSample) ) 

#define IWMWriterPreprocess_EndPreprocessingPass(This,dwInputNum,dwFlags)	\
    ( (This)->lpVtbl -> EndPreprocessingPass(This,dwInputNum,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterPreprocess_INTERFACE_DEFINED__ */


#ifndef __IWMWriterPostViewCallback_INTERFACE_DEFINED__
#define __IWMWriterPostViewCallback_INTERFACE_DEFINED__

/* interface IWMWriterPostViewCallback */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterPostViewCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D9D6549D-A193-4f24-B308-03123D9B7F8D")
    IWMWriterPostViewCallback : public IWMStatusCallback
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnPostViewSample( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocateForPostView( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  DWORD cbBuffer,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterPostViewCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterPostViewCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterPostViewCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterPostViewCallback * This);
        
        DECLSPEC_XFGVIRT(IWMStatusCallback, OnStatus)
        HRESULT ( STDMETHODCALLTYPE *OnStatus )( 
            IWMWriterPostViewCallback * This,
            /* [annotation][in] */ 
            _In_  WMT_STATUS Status,
            /* [annotation][in] */ 
            _In_  HRESULT hr,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE dwType,
            /* [annotation][in] */ 
            _In_  BYTE *pValue,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMWriterPostViewCallback, OnPostViewSample)
        HRESULT ( STDMETHODCALLTYPE *OnPostViewSample )( 
            IWMWriterPostViewCallback * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMWriterPostViewCallback, AllocateForPostView)
        HRESULT ( STDMETHODCALLTYPE *AllocateForPostView )( 
            IWMWriterPostViewCallback * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  DWORD cbBuffer,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        END_INTERFACE
    } IWMWriterPostViewCallbackVtbl;

    interface IWMWriterPostViewCallback
    {
        CONST_VTBL struct IWMWriterPostViewCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterPostViewCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterPostViewCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterPostViewCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterPostViewCallback_OnStatus(This,Status,hr,dwType,pValue,pvContext)	\
    ( (This)->lpVtbl -> OnStatus(This,Status,hr,dwType,pValue,pvContext) ) 


#define IWMWriterPostViewCallback_OnPostViewSample(This,wStreamNumber,cnsSampleTime,cnsSampleDuration,dwFlags,pSample,pvContext)	\
    ( (This)->lpVtbl -> OnPostViewSample(This,wStreamNumber,cnsSampleTime,cnsSampleDuration,dwFlags,pSample,pvContext) ) 

#define IWMWriterPostViewCallback_AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    ( (This)->lpVtbl -> AllocateForPostView(This,wStreamNum,cbBuffer,ppBuffer,pvContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterPostViewCallback_INTERFACE_DEFINED__ */


#ifndef __IWMWriterPostView_INTERFACE_DEFINED__
#define __IWMWriterPostView_INTERFACE_DEFINED__

/* interface IWMWriterPostView */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterPostView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81E20CE4-75EF-491a-8004-FC53C45BDC3E")
    IWMWriterPostView : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPostViewCallback( 
            IWMWriterPostViewCallback *pCallback,
            void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetReceivePostViewSamples( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fReceivePostViewSamples) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetReceivePostViewSamples( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfReceivePostViewSamples) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPostViewProps( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][out] */ 
            _Out_  IWMMediaProps **ppOutput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPostViewProps( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][in] */ 
            _In_  IWMMediaProps *pOutput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPostViewFormatCount( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPostViewFormat( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatNumber,
            /* [annotation][out] */ 
            _Out_  IWMMediaProps **ppProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAllocateForPostView( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllocateForPostView( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterPostViewVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterPostView * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterPostView * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterPostView * This);
        
        DECLSPEC_XFGVIRT(IWMWriterPostView, SetPostViewCallback)
        HRESULT ( STDMETHODCALLTYPE *SetPostViewCallback )( 
            IWMWriterPostView * This,
            IWMWriterPostViewCallback *pCallback,
            void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMWriterPostView, SetReceivePostViewSamples)
        HRESULT ( STDMETHODCALLTYPE *SetReceivePostViewSamples )( 
            IWMWriterPostView * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fReceivePostViewSamples);
        
        DECLSPEC_XFGVIRT(IWMWriterPostView, GetReceivePostViewSamples)
        HRESULT ( STDMETHODCALLTYPE *GetReceivePostViewSamples )( 
            IWMWriterPostView * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfReceivePostViewSamples);
        
        DECLSPEC_XFGVIRT(IWMWriterPostView, GetPostViewProps)
        HRESULT ( STDMETHODCALLTYPE *GetPostViewProps )( 
            IWMWriterPostView * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][out] */ 
            _Out_  IWMMediaProps **ppOutput);
        
        DECLSPEC_XFGVIRT(IWMWriterPostView, SetPostViewProps)
        HRESULT ( STDMETHODCALLTYPE *SetPostViewProps )( 
            IWMWriterPostView * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][in] */ 
            _In_  IWMMediaProps *pOutput);
        
        DECLSPEC_XFGVIRT(IWMWriterPostView, GetPostViewFormatCount)
        HRESULT ( STDMETHODCALLTYPE *GetPostViewFormatCount )( 
            IWMWriterPostView * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormats);
        
        DECLSPEC_XFGVIRT(IWMWriterPostView, GetPostViewFormat)
        HRESULT ( STDMETHODCALLTYPE *GetPostViewFormat )( 
            IWMWriterPostView * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatNumber,
            /* [annotation][out] */ 
            _Out_  IWMMediaProps **ppProps);
        
        DECLSPEC_XFGVIRT(IWMWriterPostView, SetAllocateForPostView)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForPostView )( 
            IWMWriterPostView * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMWriterPostView, GetAllocateForPostView)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForPostView )( 
            IWMWriterPostView * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        END_INTERFACE
    } IWMWriterPostViewVtbl;

    interface IWMWriterPostView
    {
        CONST_VTBL struct IWMWriterPostViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterPostView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterPostView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterPostView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterPostView_SetPostViewCallback(This,pCallback,pvContext)	\
    ( (This)->lpVtbl -> SetPostViewCallback(This,pCallback,pvContext) ) 

#define IWMWriterPostView_SetReceivePostViewSamples(This,wStreamNum,fReceivePostViewSamples)	\
    ( (This)->lpVtbl -> SetReceivePostViewSamples(This,wStreamNum,fReceivePostViewSamples) ) 

#define IWMWriterPostView_GetReceivePostViewSamples(This,wStreamNum,pfReceivePostViewSamples)	\
    ( (This)->lpVtbl -> GetReceivePostViewSamples(This,wStreamNum,pfReceivePostViewSamples) ) 

#define IWMWriterPostView_GetPostViewProps(This,wStreamNumber,ppOutput)	\
    ( (This)->lpVtbl -> GetPostViewProps(This,wStreamNumber,ppOutput) ) 

#define IWMWriterPostView_SetPostViewProps(This,wStreamNumber,pOutput)	\
    ( (This)->lpVtbl -> SetPostViewProps(This,wStreamNumber,pOutput) ) 

#define IWMWriterPostView_GetPostViewFormatCount(This,wStreamNumber,pcFormats)	\
    ( (This)->lpVtbl -> GetPostViewFormatCount(This,wStreamNumber,pcFormats) ) 

#define IWMWriterPostView_GetPostViewFormat(This,wStreamNumber,dwFormatNumber,ppProps)	\
    ( (This)->lpVtbl -> GetPostViewFormat(This,wStreamNumber,dwFormatNumber,ppProps) ) 

#define IWMWriterPostView_SetAllocateForPostView(This,wStreamNumber,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForPostView(This,wStreamNumber,fAllocate) ) 

#define IWMWriterPostView_GetAllocateForPostView(This,wStreamNumber,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForPostView(This,wStreamNumber,pfAllocate) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterPostView_INTERFACE_DEFINED__ */


#ifndef __IWMWriterSink_INTERFACE_DEFINED__
#define __IWMWriterSink_INTERFACE_DEFINED__

/* interface IWMWriterSink */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BE4-2B2B-11d3-B36B-00C04F6108FF")
    IWMWriterSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnHeader( 
            /* [annotation][in] */ 
            _In_  INSSBuffer *pHeader) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsRealTime( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfRealTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocateDataUnit( 
            /* [annotation][in] */ 
            _In_  DWORD cbDataUnit,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppDataUnit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDataUnit( 
            /* [annotation][in] */ 
            _In_  INSSBuffer *pDataUnit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEndWriting( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterSinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterSink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterSink * This);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnHeader)
        HRESULT ( STDMETHODCALLTYPE *OnHeader )( 
            IWMWriterSink * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pHeader);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, IsRealTime)
        HRESULT ( STDMETHODCALLTYPE *IsRealTime )( 
            IWMWriterSink * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfRealTime);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, AllocateDataUnit)
        HRESULT ( STDMETHODCALLTYPE *AllocateDataUnit )( 
            IWMWriterSink * This,
            /* [annotation][in] */ 
            _In_  DWORD cbDataUnit,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnDataUnit)
        HRESULT ( STDMETHODCALLTYPE *OnDataUnit )( 
            IWMWriterSink * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnEndWriting)
        HRESULT ( STDMETHODCALLTYPE *OnEndWriting )( 
            IWMWriterSink * This);
        
        END_INTERFACE
    } IWMWriterSinkVtbl;

    interface IWMWriterSink
    {
        CONST_VTBL struct IWMWriterSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterSink_OnHeader(This,pHeader)	\
    ( (This)->lpVtbl -> OnHeader(This,pHeader) ) 

#define IWMWriterSink_IsRealTime(This,pfRealTime)	\
    ( (This)->lpVtbl -> IsRealTime(This,pfRealTime) ) 

#define IWMWriterSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    ( (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit) ) 

#define IWMWriterSink_OnDataUnit(This,pDataUnit)	\
    ( (This)->lpVtbl -> OnDataUnit(This,pDataUnit) ) 

#define IWMWriterSink_OnEndWriting(This)	\
    ( (This)->lpVtbl -> OnEndWriting(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterSink_INTERFACE_DEFINED__ */


#ifndef __IWMRegisterCallback_INTERFACE_DEFINED__
#define __IWMRegisterCallback_INTERFACE_DEFINED__

/* interface IWMRegisterCallback */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMRegisterCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF4B1F99-4DE2-4e49-A363-252740D99BC1")
    IWMRegisterCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unadvise( 
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMRegisterCallbackVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMRegisterCallback * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMRegisterCallback * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMRegisterCallback * This);
        
        DECLSPEC_XFGVIRT(IWMRegisterCallback, Advise)
        HRESULT ( STDMETHODCALLTYPE *Advise )( 
            IWMRegisterCallback * This,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMRegisterCallback, Unadvise)
        HRESULT ( STDMETHODCALLTYPE *Unadvise )( 
            IWMRegisterCallback * This,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        END_INTERFACE
    } IWMRegisterCallbackVtbl;

    interface IWMRegisterCallback
    {
        CONST_VTBL struct IWMRegisterCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMRegisterCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMRegisterCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMRegisterCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMRegisterCallback_Advise(This,pCallback,pvContext)	\
    ( (This)->lpVtbl -> Advise(This,pCallback,pvContext) ) 

#define IWMRegisterCallback_Unadvise(This,pCallback,pvContext)	\
    ( (This)->lpVtbl -> Unadvise(This,pCallback,pvContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMRegisterCallback_INTERFACE_DEFINED__ */


#ifndef __IWMWriterFileSink_INTERFACE_DEFINED__
#define __IWMWriterFileSink_INTERFACE_DEFINED__

/* interface IWMWriterFileSink */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterFileSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BE5-2B2B-11d3-B36B-00C04F6108FF")
    IWMWriterFileSink : public IWMWriterSink
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterFileSinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterFileSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterFileSink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterFileSink * This);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnHeader)
        HRESULT ( STDMETHODCALLTYPE *OnHeader )( 
            IWMWriterFileSink * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pHeader);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, IsRealTime)
        HRESULT ( STDMETHODCALLTYPE *IsRealTime )( 
            IWMWriterFileSink * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfRealTime);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, AllocateDataUnit)
        HRESULT ( STDMETHODCALLTYPE *AllocateDataUnit )( 
            IWMWriterFileSink * This,
            /* [annotation][in] */ 
            _In_  DWORD cbDataUnit,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnDataUnit)
        HRESULT ( STDMETHODCALLTYPE *OnDataUnit )( 
            IWMWriterFileSink * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnEndWriting)
        HRESULT ( STDMETHODCALLTYPE *OnEndWriting )( 
            IWMWriterFileSink * This);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWMWriterFileSink * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        END_INTERFACE
    } IWMWriterFileSinkVtbl;

    interface IWMWriterFileSink
    {
        CONST_VTBL struct IWMWriterFileSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterFileSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterFileSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterFileSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterFileSink_OnHeader(This,pHeader)	\
    ( (This)->lpVtbl -> OnHeader(This,pHeader) ) 

#define IWMWriterFileSink_IsRealTime(This,pfRealTime)	\
    ( (This)->lpVtbl -> IsRealTime(This,pfRealTime) ) 

#define IWMWriterFileSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    ( (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit) ) 

#define IWMWriterFileSink_OnDataUnit(This,pDataUnit)	\
    ( (This)->lpVtbl -> OnDataUnit(This,pDataUnit) ) 

#define IWMWriterFileSink_OnEndWriting(This)	\
    ( (This)->lpVtbl -> OnEndWriting(This) ) 


#define IWMWriterFileSink_Open(This,pwszFilename)	\
    ( (This)->lpVtbl -> Open(This,pwszFilename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterFileSink_INTERFACE_DEFINED__ */


#ifndef __IWMWriterFileSink2_INTERFACE_DEFINED__
#define __IWMWriterFileSink2_INTERFACE_DEFINED__

/* interface IWMWriterFileSink2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterFileSink2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("14282BA7-4AEF-4205-8CE5-C229035A05BC")
    IWMWriterFileSink2 : public IWMWriterFileSink
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Start( 
            /* [annotation][in] */ 
            _In_  QWORD cnsStartTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( 
            /* [annotation][in] */ 
            _In_  QWORD cnsStopTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsStopped( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfStopped) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileDuration( 
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDuration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileSize( 
            /* [annotation][out] */ 
            _Out_  QWORD *pcbFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsClosed( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfClosed) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterFileSink2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterFileSink2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterFileSink2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterFileSink2 * This);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnHeader)
        HRESULT ( STDMETHODCALLTYPE *OnHeader )( 
            IWMWriterFileSink2 * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pHeader);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, IsRealTime)
        HRESULT ( STDMETHODCALLTYPE *IsRealTime )( 
            IWMWriterFileSink2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfRealTime);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, AllocateDataUnit)
        HRESULT ( STDMETHODCALLTYPE *AllocateDataUnit )( 
            IWMWriterFileSink2 * This,
            /* [annotation][in] */ 
            _In_  DWORD cbDataUnit,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnDataUnit)
        HRESULT ( STDMETHODCALLTYPE *OnDataUnit )( 
            IWMWriterFileSink2 * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnEndWriting)
        HRESULT ( STDMETHODCALLTYPE *OnEndWriting )( 
            IWMWriterFileSink2 * This);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWMWriterFileSink2 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, Start)
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IWMWriterFileSink2 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStartTime);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, Stop)
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IWMWriterFileSink2 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStopTime);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, IsStopped)
        HRESULT ( STDMETHODCALLTYPE *IsStopped )( 
            IWMWriterFileSink2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfStopped);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, GetFileDuration)
        HRESULT ( STDMETHODCALLTYPE *GetFileDuration )( 
            IWMWriterFileSink2 * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDuration);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, GetFileSize)
        HRESULT ( STDMETHODCALLTYPE *GetFileSize )( 
            IWMWriterFileSink2 * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcbFile);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWMWriterFileSink2 * This);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, IsClosed)
        HRESULT ( STDMETHODCALLTYPE *IsClosed )( 
            IWMWriterFileSink2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfClosed);
        
        END_INTERFACE
    } IWMWriterFileSink2Vtbl;

    interface IWMWriterFileSink2
    {
        CONST_VTBL struct IWMWriterFileSink2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterFileSink2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterFileSink2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterFileSink2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterFileSink2_OnHeader(This,pHeader)	\
    ( (This)->lpVtbl -> OnHeader(This,pHeader) ) 

#define IWMWriterFileSink2_IsRealTime(This,pfRealTime)	\
    ( (This)->lpVtbl -> IsRealTime(This,pfRealTime) ) 

#define IWMWriterFileSink2_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    ( (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit) ) 

#define IWMWriterFileSink2_OnDataUnit(This,pDataUnit)	\
    ( (This)->lpVtbl -> OnDataUnit(This,pDataUnit) ) 

#define IWMWriterFileSink2_OnEndWriting(This)	\
    ( (This)->lpVtbl -> OnEndWriting(This) ) 


#define IWMWriterFileSink2_Open(This,pwszFilename)	\
    ( (This)->lpVtbl -> Open(This,pwszFilename) ) 


#define IWMWriterFileSink2_Start(This,cnsStartTime)	\
    ( (This)->lpVtbl -> Start(This,cnsStartTime) ) 

#define IWMWriterFileSink2_Stop(This,cnsStopTime)	\
    ( (This)->lpVtbl -> Stop(This,cnsStopTime) ) 

#define IWMWriterFileSink2_IsStopped(This,pfStopped)	\
    ( (This)->lpVtbl -> IsStopped(This,pfStopped) ) 

#define IWMWriterFileSink2_GetFileDuration(This,pcnsDuration)	\
    ( (This)->lpVtbl -> GetFileDuration(This,pcnsDuration) ) 

#define IWMWriterFileSink2_GetFileSize(This,pcbFile)	\
    ( (This)->lpVtbl -> GetFileSize(This,pcbFile) ) 

#define IWMWriterFileSink2_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IWMWriterFileSink2_IsClosed(This,pfClosed)	\
    ( (This)->lpVtbl -> IsClosed(This,pfClosed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterFileSink2_INTERFACE_DEFINED__ */


#ifndef __IWMWriterFileSink3_INTERFACE_DEFINED__
#define __IWMWriterFileSink3_INTERFACE_DEFINED__

/* interface IWMWriterFileSink3 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterFileSink3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3FEA4FEB-2945-47A7-A1DD-C53A8FC4C45C")
    IWMWriterFileSink3 : public IWMWriterFileSink2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetAutoIndexing( 
            /* [annotation][in] */ 
            _In_  BOOL fDoAutoIndexing) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAutoIndexing( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfAutoIndexing) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetControlStream( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][in] */ 
            _In_  BOOL fShouldControlStartAndStop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMode( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFileSinkMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDataUnitEx( 
            /* [annotation][in] */ 
            _In_  WMT_FILESINK_DATA_UNIT *pFileSinkDataUnit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUnbufferedIO( 
            /* [annotation][in] */ 
            _In_  BOOL fUnbufferedIO,
            /* [annotation][in] */ 
            _In_  BOOL fRestrictMemUsage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnbufferedIO( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfUnbufferedIO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompleteOperations( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterFileSink3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterFileSink3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterFileSink3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterFileSink3 * This);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnHeader)
        HRESULT ( STDMETHODCALLTYPE *OnHeader )( 
            IWMWriterFileSink3 * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pHeader);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, IsRealTime)
        HRESULT ( STDMETHODCALLTYPE *IsRealTime )( 
            IWMWriterFileSink3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfRealTime);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, AllocateDataUnit)
        HRESULT ( STDMETHODCALLTYPE *AllocateDataUnit )( 
            IWMWriterFileSink3 * This,
            /* [annotation][in] */ 
            _In_  DWORD cbDataUnit,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnDataUnit)
        HRESULT ( STDMETHODCALLTYPE *OnDataUnit )( 
            IWMWriterFileSink3 * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnEndWriting)
        HRESULT ( STDMETHODCALLTYPE *OnEndWriting )( 
            IWMWriterFileSink3 * This);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWMWriterFileSink3 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, Start)
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IWMWriterFileSink3 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStartTime);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, Stop)
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IWMWriterFileSink3 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStopTime);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, IsStopped)
        HRESULT ( STDMETHODCALLTYPE *IsStopped )( 
            IWMWriterFileSink3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfStopped);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, GetFileDuration)
        HRESULT ( STDMETHODCALLTYPE *GetFileDuration )( 
            IWMWriterFileSink3 * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDuration);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, GetFileSize)
        HRESULT ( STDMETHODCALLTYPE *GetFileSize )( 
            IWMWriterFileSink3 * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcbFile);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWMWriterFileSink3 * This);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink2, IsClosed)
        HRESULT ( STDMETHODCALLTYPE *IsClosed )( 
            IWMWriterFileSink3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfClosed);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink3, SetAutoIndexing)
        HRESULT ( STDMETHODCALLTYPE *SetAutoIndexing )( 
            IWMWriterFileSink3 * This,
            /* [annotation][in] */ 
            _In_  BOOL fDoAutoIndexing);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink3, GetAutoIndexing)
        HRESULT ( STDMETHODCALLTYPE *GetAutoIndexing )( 
            IWMWriterFileSink3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAutoIndexing);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink3, SetControlStream)
        HRESULT ( STDMETHODCALLTYPE *SetControlStream )( 
            IWMWriterFileSink3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNumber,
            /* [annotation][in] */ 
            _In_  BOOL fShouldControlStartAndStop);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink3, GetMode)
        HRESULT ( STDMETHODCALLTYPE *GetMode )( 
            IWMWriterFileSink3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFileSinkMode);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink3, OnDataUnitEx)
        HRESULT ( STDMETHODCALLTYPE *OnDataUnitEx )( 
            IWMWriterFileSink3 * This,
            /* [annotation][in] */ 
            _In_  WMT_FILESINK_DATA_UNIT *pFileSinkDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink3, SetUnbufferedIO)
        HRESULT ( STDMETHODCALLTYPE *SetUnbufferedIO )( 
            IWMWriterFileSink3 * This,
            /* [annotation][in] */ 
            _In_  BOOL fUnbufferedIO,
            /* [annotation][in] */ 
            _In_  BOOL fRestrictMemUsage);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink3, GetUnbufferedIO)
        HRESULT ( STDMETHODCALLTYPE *GetUnbufferedIO )( 
            IWMWriterFileSink3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfUnbufferedIO);
        
        DECLSPEC_XFGVIRT(IWMWriterFileSink3, CompleteOperations)
        HRESULT ( STDMETHODCALLTYPE *CompleteOperations )( 
            IWMWriterFileSink3 * This);
        
        END_INTERFACE
    } IWMWriterFileSink3Vtbl;

    interface IWMWriterFileSink3
    {
        CONST_VTBL struct IWMWriterFileSink3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterFileSink3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterFileSink3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterFileSink3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterFileSink3_OnHeader(This,pHeader)	\
    ( (This)->lpVtbl -> OnHeader(This,pHeader) ) 

#define IWMWriterFileSink3_IsRealTime(This,pfRealTime)	\
    ( (This)->lpVtbl -> IsRealTime(This,pfRealTime) ) 

#define IWMWriterFileSink3_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    ( (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit) ) 

#define IWMWriterFileSink3_OnDataUnit(This,pDataUnit)	\
    ( (This)->lpVtbl -> OnDataUnit(This,pDataUnit) ) 

#define IWMWriterFileSink3_OnEndWriting(This)	\
    ( (This)->lpVtbl -> OnEndWriting(This) ) 


#define IWMWriterFileSink3_Open(This,pwszFilename)	\
    ( (This)->lpVtbl -> Open(This,pwszFilename) ) 


#define IWMWriterFileSink3_Start(This,cnsStartTime)	\
    ( (This)->lpVtbl -> Start(This,cnsStartTime) ) 

#define IWMWriterFileSink3_Stop(This,cnsStopTime)	\
    ( (This)->lpVtbl -> Stop(This,cnsStopTime) ) 

#define IWMWriterFileSink3_IsStopped(This,pfStopped)	\
    ( (This)->lpVtbl -> IsStopped(This,pfStopped) ) 

#define IWMWriterFileSink3_GetFileDuration(This,pcnsDuration)	\
    ( (This)->lpVtbl -> GetFileDuration(This,pcnsDuration) ) 

#define IWMWriterFileSink3_GetFileSize(This,pcbFile)	\
    ( (This)->lpVtbl -> GetFileSize(This,pcbFile) ) 

#define IWMWriterFileSink3_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IWMWriterFileSink3_IsClosed(This,pfClosed)	\
    ( (This)->lpVtbl -> IsClosed(This,pfClosed) ) 


#define IWMWriterFileSink3_SetAutoIndexing(This,fDoAutoIndexing)	\
    ( (This)->lpVtbl -> SetAutoIndexing(This,fDoAutoIndexing) ) 

#define IWMWriterFileSink3_GetAutoIndexing(This,pfAutoIndexing)	\
    ( (This)->lpVtbl -> GetAutoIndexing(This,pfAutoIndexing) ) 

#define IWMWriterFileSink3_SetControlStream(This,wStreamNumber,fShouldControlStartAndStop)	\
    ( (This)->lpVtbl -> SetControlStream(This,wStreamNumber,fShouldControlStartAndStop) ) 

#define IWMWriterFileSink3_GetMode(This,pdwFileSinkMode)	\
    ( (This)->lpVtbl -> GetMode(This,pdwFileSinkMode) ) 

#define IWMWriterFileSink3_OnDataUnitEx(This,pFileSinkDataUnit)	\
    ( (This)->lpVtbl -> OnDataUnitEx(This,pFileSinkDataUnit) ) 

#define IWMWriterFileSink3_SetUnbufferedIO(This,fUnbufferedIO,fRestrictMemUsage)	\
    ( (This)->lpVtbl -> SetUnbufferedIO(This,fUnbufferedIO,fRestrictMemUsage) ) 

#define IWMWriterFileSink3_GetUnbufferedIO(This,pfUnbufferedIO)	\
    ( (This)->lpVtbl -> GetUnbufferedIO(This,pfUnbufferedIO) ) 

#define IWMWriterFileSink3_CompleteOperations(This)	\
    ( (This)->lpVtbl -> CompleteOperations(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterFileSink3_INTERFACE_DEFINED__ */


#ifndef __IWMWriterNetworkSink_INTERFACE_DEFINED__
#define __IWMWriterNetworkSink_INTERFACE_DEFINED__

/* interface IWMWriterNetworkSink */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterNetworkSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BE7-2B2B-11d3-B36B-00C04F6108FF")
    IWMWriterNetworkSink : public IWMWriterSink
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetMaximumClients( 
            /* [annotation][in] */ 
            _In_  DWORD dwMaxClients) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaximumClients( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMaxClients) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNetworkProtocol( 
            /* [annotation][in] */ 
            _In_  WMT_NET_PROTOCOL protocol) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworkProtocol( 
            /* [annotation][out] */ 
            _Out_  WMT_NET_PROTOCOL *pProtocol) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHostURL( 
            /* [annotation][out] */ 
            _Out_  WCHAR *pwszURL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchURL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwPortNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterNetworkSinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterNetworkSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterNetworkSink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterNetworkSink * This);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnHeader)
        HRESULT ( STDMETHODCALLTYPE *OnHeader )( 
            IWMWriterNetworkSink * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pHeader);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, IsRealTime)
        HRESULT ( STDMETHODCALLTYPE *IsRealTime )( 
            IWMWriterNetworkSink * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfRealTime);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, AllocateDataUnit)
        HRESULT ( STDMETHODCALLTYPE *AllocateDataUnit )( 
            IWMWriterNetworkSink * This,
            /* [annotation][in] */ 
            _In_  DWORD cbDataUnit,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnDataUnit)
        HRESULT ( STDMETHODCALLTYPE *OnDataUnit )( 
            IWMWriterNetworkSink * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnEndWriting)
        HRESULT ( STDMETHODCALLTYPE *OnEndWriting )( 
            IWMWriterNetworkSink * This);
        
        DECLSPEC_XFGVIRT(IWMWriterNetworkSink, SetMaximumClients)
        HRESULT ( STDMETHODCALLTYPE *SetMaximumClients )( 
            IWMWriterNetworkSink * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMaxClients);
        
        DECLSPEC_XFGVIRT(IWMWriterNetworkSink, GetMaximumClients)
        HRESULT ( STDMETHODCALLTYPE *GetMaximumClients )( 
            IWMWriterNetworkSink * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMaxClients);
        
        DECLSPEC_XFGVIRT(IWMWriterNetworkSink, SetNetworkProtocol)
        HRESULT ( STDMETHODCALLTYPE *SetNetworkProtocol )( 
            IWMWriterNetworkSink * This,
            /* [annotation][in] */ 
            _In_  WMT_NET_PROTOCOL protocol);
        
        DECLSPEC_XFGVIRT(IWMWriterNetworkSink, GetNetworkProtocol)
        HRESULT ( STDMETHODCALLTYPE *GetNetworkProtocol )( 
            IWMWriterNetworkSink * This,
            /* [annotation][out] */ 
            _Out_  WMT_NET_PROTOCOL *pProtocol);
        
        DECLSPEC_XFGVIRT(IWMWriterNetworkSink, GetHostURL)
        HRESULT ( STDMETHODCALLTYPE *GetHostURL )( 
            IWMWriterNetworkSink * This,
            /* [annotation][out] */ 
            _Out_  WCHAR *pwszURL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchURL);
        
        DECLSPEC_XFGVIRT(IWMWriterNetworkSink, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWMWriterNetworkSink * This,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwPortNum);
        
        DECLSPEC_XFGVIRT(IWMWriterNetworkSink, Disconnect)
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IWMWriterNetworkSink * This);
        
        DECLSPEC_XFGVIRT(IWMWriterNetworkSink, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWMWriterNetworkSink * This);
        
        END_INTERFACE
    } IWMWriterNetworkSinkVtbl;

    interface IWMWriterNetworkSink
    {
        CONST_VTBL struct IWMWriterNetworkSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterNetworkSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterNetworkSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterNetworkSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterNetworkSink_OnHeader(This,pHeader)	\
    ( (This)->lpVtbl -> OnHeader(This,pHeader) ) 

#define IWMWriterNetworkSink_IsRealTime(This,pfRealTime)	\
    ( (This)->lpVtbl -> IsRealTime(This,pfRealTime) ) 

#define IWMWriterNetworkSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    ( (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit) ) 

#define IWMWriterNetworkSink_OnDataUnit(This,pDataUnit)	\
    ( (This)->lpVtbl -> OnDataUnit(This,pDataUnit) ) 

#define IWMWriterNetworkSink_OnEndWriting(This)	\
    ( (This)->lpVtbl -> OnEndWriting(This) ) 


#define IWMWriterNetworkSink_SetMaximumClients(This,dwMaxClients)	\
    ( (This)->lpVtbl -> SetMaximumClients(This,dwMaxClients) ) 

#define IWMWriterNetworkSink_GetMaximumClients(This,pdwMaxClients)	\
    ( (This)->lpVtbl -> GetMaximumClients(This,pdwMaxClients) ) 

#define IWMWriterNetworkSink_SetNetworkProtocol(This,protocol)	\
    ( (This)->lpVtbl -> SetNetworkProtocol(This,protocol) ) 

#define IWMWriterNetworkSink_GetNetworkProtocol(This,pProtocol)	\
    ( (This)->lpVtbl -> GetNetworkProtocol(This,pProtocol) ) 

#define IWMWriterNetworkSink_GetHostURL(This,pwszURL,pcchURL)	\
    ( (This)->lpVtbl -> GetHostURL(This,pwszURL,pcchURL) ) 

#define IWMWriterNetworkSink_Open(This,pdwPortNum)	\
    ( (This)->lpVtbl -> Open(This,pdwPortNum) ) 

#define IWMWriterNetworkSink_Disconnect(This)	\
    ( (This)->lpVtbl -> Disconnect(This) ) 

#define IWMWriterNetworkSink_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterNetworkSink_INTERFACE_DEFINED__ */


#ifndef __IWMClientConnections_INTERFACE_DEFINED__
#define __IWMClientConnections_INTERFACE_DEFINED__

/* interface IWMClientConnections */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMClientConnections;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("73C66010-A299-41df-B1F0-CCF03B09C1C6")
    IWMClientConnections : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetClientCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcClients) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClientProperties( 
            /* [annotation][in] */ 
            _In_  DWORD dwClientNum,
            /* [annotation][out] */ 
            _Out_  WM_CLIENT_PROPERTIES *pClientProperties) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMClientConnectionsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMClientConnections * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMClientConnections * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMClientConnections * This);
        
        DECLSPEC_XFGVIRT(IWMClientConnections, GetClientCount)
        HRESULT ( STDMETHODCALLTYPE *GetClientCount )( 
            IWMClientConnections * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcClients);
        
        DECLSPEC_XFGVIRT(IWMClientConnections, GetClientProperties)
        HRESULT ( STDMETHODCALLTYPE *GetClientProperties )( 
            IWMClientConnections * This,
            /* [annotation][in] */ 
            _In_  DWORD dwClientNum,
            /* [annotation][out] */ 
            _Out_  WM_CLIENT_PROPERTIES *pClientProperties);
        
        END_INTERFACE
    } IWMClientConnectionsVtbl;

    interface IWMClientConnections
    {
        CONST_VTBL struct IWMClientConnectionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMClientConnections_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMClientConnections_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMClientConnections_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMClientConnections_GetClientCount(This,pcClients)	\
    ( (This)->lpVtbl -> GetClientCount(This,pcClients) ) 

#define IWMClientConnections_GetClientProperties(This,dwClientNum,pClientProperties)	\
    ( (This)->lpVtbl -> GetClientProperties(This,dwClientNum,pClientProperties) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMClientConnections_INTERFACE_DEFINED__ */


#ifndef __IWMClientConnections2_INTERFACE_DEFINED__
#define __IWMClientConnections2_INTERFACE_DEFINED__

/* interface IWMClientConnections2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMClientConnections2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4091571e-4701-4593-bb3d-d5f5f0c74246")
    IWMClientConnections2 : public IWMClientConnections
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetClientInfo( 
            /* [annotation][in] */ 
            _In_  DWORD dwClientNum,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchNetworkAddress)  WCHAR *pwszNetworkAddress,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchNetworkAddress,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchPort)  WCHAR *pwszPort,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchPort,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDNSName)  WCHAR *pwszDNSName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDNSName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMClientConnections2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMClientConnections2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMClientConnections2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMClientConnections2 * This);
        
        DECLSPEC_XFGVIRT(IWMClientConnections, GetClientCount)
        HRESULT ( STDMETHODCALLTYPE *GetClientCount )( 
            IWMClientConnections2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcClients);
        
        DECLSPEC_XFGVIRT(IWMClientConnections, GetClientProperties)
        HRESULT ( STDMETHODCALLTYPE *GetClientProperties )( 
            IWMClientConnections2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwClientNum,
            /* [annotation][out] */ 
            _Out_  WM_CLIENT_PROPERTIES *pClientProperties);
        
        DECLSPEC_XFGVIRT(IWMClientConnections2, GetClientInfo)
        HRESULT ( STDMETHODCALLTYPE *GetClientInfo )( 
            IWMClientConnections2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwClientNum,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchNetworkAddress)  WCHAR *pwszNetworkAddress,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchNetworkAddress,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchPort)  WCHAR *pwszPort,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchPort,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDNSName)  WCHAR *pwszDNSName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDNSName);
        
        END_INTERFACE
    } IWMClientConnections2Vtbl;

    interface IWMClientConnections2
    {
        CONST_VTBL struct IWMClientConnections2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMClientConnections2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMClientConnections2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMClientConnections2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMClientConnections2_GetClientCount(This,pcClients)	\
    ( (This)->lpVtbl -> GetClientCount(This,pcClients) ) 

#define IWMClientConnections2_GetClientProperties(This,dwClientNum,pClientProperties)	\
    ( (This)->lpVtbl -> GetClientProperties(This,dwClientNum,pClientProperties) ) 


#define IWMClientConnections2_GetClientInfo(This,dwClientNum,pwszNetworkAddress,pcchNetworkAddress,pwszPort,pcchPort,pwszDNSName,pcchDNSName)	\
    ( (This)->lpVtbl -> GetClientInfo(This,dwClientNum,pwszNetworkAddress,pcchNetworkAddress,pwszPort,pcchPort,pwszDNSName,pcchDNSName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMClientConnections2_INTERFACE_DEFINED__ */


#ifndef __IWMReaderAdvanced_INTERFACE_DEFINED__
#define __IWMReaderAdvanced_INTERFACE_DEFINED__

/* interface IWMReaderAdvanced */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderAdvanced;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BEA-2B2B-11d3-B36B-00C04F6108FF")
    IWMReaderAdvanced : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetUserProvidedClock( 
            /* [annotation][in] */ 
            _In_  BOOL fUserClock) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserProvidedClock( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfUserClock) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeliverTime( 
            /* [annotation][in] */ 
            _In_  QWORD cnsTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetManualStreamSelection( 
            /* [annotation][in] */ 
            _In_  BOOL fSelection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetManualStreamSelection( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfSelection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStreamsSelected( 
            /* [annotation][in] */ 
            _In_  WORD cStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pwStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamSelected( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WMT_STREAM_SELECTION *pSelection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetReceiveSelectionCallbacks( 
            /* [annotation][in] */ 
            _In_  BOOL fGetCallbacks) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetReceiveSelectionCallbacks( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfGetCallbacks) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetReceiveStreamSamples( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fReceiveStreamSamples) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetReceiveStreamSamples( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfReceiveStreamSamples) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAllocateForOutput( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllocateForOutput( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAllocateForStream( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllocateForStream( 
            /* [annotation][in] */ 
            _In_  WORD dwSreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatistics( 
            /* [annotation][out][in] */ 
            _Inout_  WM_READER_STATISTICS *pStatistics) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetClientInfo( 
            /* [annotation][in] */ 
            _In_  WM_READER_CLIENTINFO *pClientInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxOutputSampleSize( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxStreamSampleSize( 
            /* [annotation][in] */ 
            _In_  WORD wStream,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NotifyLateDelivery( 
            QWORD cnsLateness) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderAdvancedVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderAdvanced * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderAdvanced * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *SetUserProvidedClock )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  BOOL fUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *GetUserProvidedClock )( 
            IWMReaderAdvanced * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, DeliverTime)
        HRESULT ( STDMETHODCALLTYPE *DeliverTime )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsTime);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *SetManualStreamSelection )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  BOOL fSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *GetManualStreamSelection )( 
            IWMReaderAdvanced * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetStreamsSelected)
        HRESULT ( STDMETHODCALLTYPE *SetStreamsSelected )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD cStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pwStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStreamSelected)
        HRESULT ( STDMETHODCALLTYPE *GetStreamSelected )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WMT_STREAM_SELECTION *pSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  BOOL fGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveStreamSamples )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveStreamSamples )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForOutput )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForOutput )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForStream )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForStream )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD dwSreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStatistics)
        HRESULT ( STDMETHODCALLTYPE *GetStatistics )( 
            IWMReaderAdvanced * This,
            /* [annotation][out][in] */ 
            _Inout_  WM_READER_STATISTICS *pStatistics);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetClientInfo)
        HRESULT ( STDMETHODCALLTYPE *SetClientInfo )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  WM_READER_CLIENTINFO *pClientInfo);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxOutputSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxOutputSampleSize )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxStreamSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxStreamSampleSize )( 
            IWMReaderAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD wStream,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, NotifyLateDelivery)
        HRESULT ( STDMETHODCALLTYPE *NotifyLateDelivery )( 
            IWMReaderAdvanced * This,
            QWORD cnsLateness);
        
        END_INTERFACE
    } IWMReaderAdvancedVtbl;

    interface IWMReaderAdvanced
    {
        CONST_VTBL struct IWMReaderAdvancedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderAdvanced_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderAdvanced_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderAdvanced_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderAdvanced_SetUserProvidedClock(This,fUserClock)	\
    ( (This)->lpVtbl -> SetUserProvidedClock(This,fUserClock) ) 

#define IWMReaderAdvanced_GetUserProvidedClock(This,pfUserClock)	\
    ( (This)->lpVtbl -> GetUserProvidedClock(This,pfUserClock) ) 

#define IWMReaderAdvanced_DeliverTime(This,cnsTime)	\
    ( (This)->lpVtbl -> DeliverTime(This,cnsTime) ) 

#define IWMReaderAdvanced_SetManualStreamSelection(This,fSelection)	\
    ( (This)->lpVtbl -> SetManualStreamSelection(This,fSelection) ) 

#define IWMReaderAdvanced_GetManualStreamSelection(This,pfSelection)	\
    ( (This)->lpVtbl -> GetManualStreamSelection(This,pfSelection) ) 

#define IWMReaderAdvanced_SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections)	\
    ( (This)->lpVtbl -> SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections) ) 

#define IWMReaderAdvanced_GetStreamSelected(This,wStreamNum,pSelection)	\
    ( (This)->lpVtbl -> GetStreamSelected(This,wStreamNum,pSelection) ) 

#define IWMReaderAdvanced_SetReceiveSelectionCallbacks(This,fGetCallbacks)	\
    ( (This)->lpVtbl -> SetReceiveSelectionCallbacks(This,fGetCallbacks) ) 

#define IWMReaderAdvanced_GetReceiveSelectionCallbacks(This,pfGetCallbacks)	\
    ( (This)->lpVtbl -> GetReceiveSelectionCallbacks(This,pfGetCallbacks) ) 

#define IWMReaderAdvanced_SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples)	\
    ( (This)->lpVtbl -> SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples) ) 

#define IWMReaderAdvanced_GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples)	\
    ( (This)->lpVtbl -> GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples) ) 

#define IWMReaderAdvanced_SetAllocateForOutput(This,dwOutputNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForOutput(This,dwOutputNum,fAllocate) ) 

#define IWMReaderAdvanced_GetAllocateForOutput(This,dwOutputNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForOutput(This,dwOutputNum,pfAllocate) ) 

#define IWMReaderAdvanced_SetAllocateForStream(This,wStreamNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForStream(This,wStreamNum,fAllocate) ) 

#define IWMReaderAdvanced_GetAllocateForStream(This,dwSreamNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForStream(This,dwSreamNum,pfAllocate) ) 

#define IWMReaderAdvanced_GetStatistics(This,pStatistics)	\
    ( (This)->lpVtbl -> GetStatistics(This,pStatistics) ) 

#define IWMReaderAdvanced_SetClientInfo(This,pClientInfo)	\
    ( (This)->lpVtbl -> SetClientInfo(This,pClientInfo) ) 

#define IWMReaderAdvanced_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax) ) 

#define IWMReaderAdvanced_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax) ) 

#define IWMReaderAdvanced_NotifyLateDelivery(This,cnsLateness)	\
    ( (This)->lpVtbl -> NotifyLateDelivery(This,cnsLateness) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderAdvanced_INTERFACE_DEFINED__ */


#ifndef __IWMReaderAdvanced2_INTERFACE_DEFINED__
#define __IWMReaderAdvanced2_INTERFACE_DEFINED__

/* interface IWMReaderAdvanced2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderAdvanced2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ae14a945-b90c-4d0d-9127-80d665f7d73e")
    IWMReaderAdvanced2 : public IWMReaderAdvanced
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPlayMode( 
            /* [annotation][in] */ 
            _In_  WMT_PLAY_MODE Mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPlayMode( 
            /* [annotation][out] */ 
            _Out_  WMT_PLAY_MODE *pMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBufferProgress( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsBuffering) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDownloadProgress( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pqwBytesDownloaded,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDownload) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSaveAsProgress( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveFileAs( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProtocolName( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchProtocol)  WCHAR *pwszProtocol,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchProtocol) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartAtMarker( 
            /* [annotation][in] */ 
            _In_  WORD wMarkerIndex,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputSetting( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutputSetting( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Preroll( 
            /* [annotation][in] */ 
            _In_  QWORD cnsStart,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLogClientID( 
            /* [annotation][in] */ 
            _In_  BOOL fLogClientID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLogClientID( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfLogClientID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopBuffering( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenStream( 
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  IWMReaderCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderAdvanced2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderAdvanced2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderAdvanced2 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *SetUserProvidedClock )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *GetUserProvidedClock )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, DeliverTime)
        HRESULT ( STDMETHODCALLTYPE *DeliverTime )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsTime);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *SetManualStreamSelection )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *GetManualStreamSelection )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetStreamsSelected)
        HRESULT ( STDMETHODCALLTYPE *SetStreamsSelected )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WORD cStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pwStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStreamSelected)
        HRESULT ( STDMETHODCALLTYPE *GetStreamSelected )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WMT_STREAM_SELECTION *pSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveStreamSamples )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveStreamSamples )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForOutput )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForOutput )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForStream )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForStream )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WORD dwSreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStatistics)
        HRESULT ( STDMETHODCALLTYPE *GetStatistics )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][out][in] */ 
            _Inout_  WM_READER_STATISTICS *pStatistics);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetClientInfo)
        HRESULT ( STDMETHODCALLTYPE *SetClientInfo )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WM_READER_CLIENTINFO *pClientInfo);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxOutputSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxOutputSampleSize )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxStreamSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxStreamSampleSize )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStream,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, NotifyLateDelivery)
        HRESULT ( STDMETHODCALLTYPE *NotifyLateDelivery )( 
            IWMReaderAdvanced2 * This,
            QWORD cnsLateness);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetPlayMode)
        HRESULT ( STDMETHODCALLTYPE *SetPlayMode )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WMT_PLAY_MODE Mode);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetPlayMode)
        HRESULT ( STDMETHODCALLTYPE *GetPlayMode )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  WMT_PLAY_MODE *pMode);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetBufferProgress)
        HRESULT ( STDMETHODCALLTYPE *GetBufferProgress )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsBuffering);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetDownloadProgress)
        HRESULT ( STDMETHODCALLTYPE *GetDownloadProgress )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pqwBytesDownloaded,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDownload);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetSaveAsProgress)
        HRESULT ( STDMETHODCALLTYPE *GetSaveAsProgress )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SaveFileAs)
        HRESULT ( STDMETHODCALLTYPE *SaveFileAs )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetProtocolName)
        HRESULT ( STDMETHODCALLTYPE *GetProtocolName )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchProtocol)  WCHAR *pwszProtocol,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchProtocol);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, StartAtMarker)
        HRESULT ( STDMETHODCALLTYPE *StartAtMarker )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  WORD wMarkerIndex,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *GetOutputSetting )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *SetOutputSetting )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, Preroll)
        HRESULT ( STDMETHODCALLTYPE *Preroll )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStart,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetLogClientID)
        HRESULT ( STDMETHODCALLTYPE *SetLogClientID )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fLogClientID);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetLogClientID)
        HRESULT ( STDMETHODCALLTYPE *GetLogClientID )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfLogClientID);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, StopBuffering)
        HRESULT ( STDMETHODCALLTYPE *StopBuffering )( 
            IWMReaderAdvanced2 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, OpenStream)
        HRESULT ( STDMETHODCALLTYPE *OpenStream )( 
            IWMReaderAdvanced2 * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  IWMReaderCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        END_INTERFACE
    } IWMReaderAdvanced2Vtbl;

    interface IWMReaderAdvanced2
    {
        CONST_VTBL struct IWMReaderAdvanced2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderAdvanced2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderAdvanced2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderAdvanced2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderAdvanced2_SetUserProvidedClock(This,fUserClock)	\
    ( (This)->lpVtbl -> SetUserProvidedClock(This,fUserClock) ) 

#define IWMReaderAdvanced2_GetUserProvidedClock(This,pfUserClock)	\
    ( (This)->lpVtbl -> GetUserProvidedClock(This,pfUserClock) ) 

#define IWMReaderAdvanced2_DeliverTime(This,cnsTime)	\
    ( (This)->lpVtbl -> DeliverTime(This,cnsTime) ) 

#define IWMReaderAdvanced2_SetManualStreamSelection(This,fSelection)	\
    ( (This)->lpVtbl -> SetManualStreamSelection(This,fSelection) ) 

#define IWMReaderAdvanced2_GetManualStreamSelection(This,pfSelection)	\
    ( (This)->lpVtbl -> GetManualStreamSelection(This,pfSelection) ) 

#define IWMReaderAdvanced2_SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections)	\
    ( (This)->lpVtbl -> SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections) ) 

#define IWMReaderAdvanced2_GetStreamSelected(This,wStreamNum,pSelection)	\
    ( (This)->lpVtbl -> GetStreamSelected(This,wStreamNum,pSelection) ) 

#define IWMReaderAdvanced2_SetReceiveSelectionCallbacks(This,fGetCallbacks)	\
    ( (This)->lpVtbl -> SetReceiveSelectionCallbacks(This,fGetCallbacks) ) 

#define IWMReaderAdvanced2_GetReceiveSelectionCallbacks(This,pfGetCallbacks)	\
    ( (This)->lpVtbl -> GetReceiveSelectionCallbacks(This,pfGetCallbacks) ) 

#define IWMReaderAdvanced2_SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples)	\
    ( (This)->lpVtbl -> SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples) ) 

#define IWMReaderAdvanced2_GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples)	\
    ( (This)->lpVtbl -> GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples) ) 

#define IWMReaderAdvanced2_SetAllocateForOutput(This,dwOutputNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForOutput(This,dwOutputNum,fAllocate) ) 

#define IWMReaderAdvanced2_GetAllocateForOutput(This,dwOutputNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForOutput(This,dwOutputNum,pfAllocate) ) 

#define IWMReaderAdvanced2_SetAllocateForStream(This,wStreamNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForStream(This,wStreamNum,fAllocate) ) 

#define IWMReaderAdvanced2_GetAllocateForStream(This,dwSreamNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForStream(This,dwSreamNum,pfAllocate) ) 

#define IWMReaderAdvanced2_GetStatistics(This,pStatistics)	\
    ( (This)->lpVtbl -> GetStatistics(This,pStatistics) ) 

#define IWMReaderAdvanced2_SetClientInfo(This,pClientInfo)	\
    ( (This)->lpVtbl -> SetClientInfo(This,pClientInfo) ) 

#define IWMReaderAdvanced2_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax) ) 

#define IWMReaderAdvanced2_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax) ) 

#define IWMReaderAdvanced2_NotifyLateDelivery(This,cnsLateness)	\
    ( (This)->lpVtbl -> NotifyLateDelivery(This,cnsLateness) ) 


#define IWMReaderAdvanced2_SetPlayMode(This,Mode)	\
    ( (This)->lpVtbl -> SetPlayMode(This,Mode) ) 

#define IWMReaderAdvanced2_GetPlayMode(This,pMode)	\
    ( (This)->lpVtbl -> GetPlayMode(This,pMode) ) 

#define IWMReaderAdvanced2_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    ( (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering) ) 

#define IWMReaderAdvanced2_GetDownloadProgress(This,pdwPercent,pqwBytesDownloaded,pcnsDownload)	\
    ( (This)->lpVtbl -> GetDownloadProgress(This,pdwPercent,pqwBytesDownloaded,pcnsDownload) ) 

#define IWMReaderAdvanced2_GetSaveAsProgress(This,pdwPercent)	\
    ( (This)->lpVtbl -> GetSaveAsProgress(This,pdwPercent) ) 

#define IWMReaderAdvanced2_SaveFileAs(This,pwszFilename)	\
    ( (This)->lpVtbl -> SaveFileAs(This,pwszFilename) ) 

#define IWMReaderAdvanced2_GetProtocolName(This,pwszProtocol,pcchProtocol)	\
    ( (This)->lpVtbl -> GetProtocolName(This,pwszProtocol,pcchProtocol) ) 

#define IWMReaderAdvanced2_StartAtMarker(This,wMarkerIndex,cnsDuration,fRate,pvContext)	\
    ( (This)->lpVtbl -> StartAtMarker(This,wMarkerIndex,cnsDuration,fRate,pvContext) ) 

#define IWMReaderAdvanced2_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength) ) 

#define IWMReaderAdvanced2_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength) ) 

#define IWMReaderAdvanced2_Preroll(This,cnsStart,cnsDuration,fRate)	\
    ( (This)->lpVtbl -> Preroll(This,cnsStart,cnsDuration,fRate) ) 

#define IWMReaderAdvanced2_SetLogClientID(This,fLogClientID)	\
    ( (This)->lpVtbl -> SetLogClientID(This,fLogClientID) ) 

#define IWMReaderAdvanced2_GetLogClientID(This,pfLogClientID)	\
    ( (This)->lpVtbl -> GetLogClientID(This,pfLogClientID) ) 

#define IWMReaderAdvanced2_StopBuffering(This)	\
    ( (This)->lpVtbl -> StopBuffering(This) ) 

#define IWMReaderAdvanced2_OpenStream(This,pStream,pCallback,pvContext)	\
    ( (This)->lpVtbl -> OpenStream(This,pStream,pCallback,pvContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderAdvanced2_INTERFACE_DEFINED__ */


#ifndef __IWMReaderAdvanced3_INTERFACE_DEFINED__
#define __IWMReaderAdvanced3_INTERFACE_DEFINED__

/* interface IWMReaderAdvanced3 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderAdvanced3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5DC0674B-F04B-4a4e-9F2A-B1AFDE2C8100")
    IWMReaderAdvanced3 : public IWMReaderAdvanced2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StopNetStreaming( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartAtPosition( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  void *pvOffsetStart,
            /* [annotation][in] */ 
            _In_  void *pvDuration,
            /* [annotation][in] */ 
            _In_  WMT_OFFSET_FORMAT dwOffsetFormat,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderAdvanced3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderAdvanced3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderAdvanced3 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *SetUserProvidedClock )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  BOOL fUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *GetUserProvidedClock )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, DeliverTime)
        HRESULT ( STDMETHODCALLTYPE *DeliverTime )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsTime);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *SetManualStreamSelection )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  BOOL fSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *GetManualStreamSelection )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetStreamsSelected)
        HRESULT ( STDMETHODCALLTYPE *SetStreamsSelected )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD cStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pwStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStreamSelected)
        HRESULT ( STDMETHODCALLTYPE *GetStreamSelected )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WMT_STREAM_SELECTION *pSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  BOOL fGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveStreamSamples )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveStreamSamples )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForOutput )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForOutput )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForStream )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForStream )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD dwSreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStatistics)
        HRESULT ( STDMETHODCALLTYPE *GetStatistics )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][out][in] */ 
            _Inout_  WM_READER_STATISTICS *pStatistics);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetClientInfo)
        HRESULT ( STDMETHODCALLTYPE *SetClientInfo )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WM_READER_CLIENTINFO *pClientInfo);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxOutputSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxOutputSampleSize )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxStreamSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxStreamSampleSize )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStream,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, NotifyLateDelivery)
        HRESULT ( STDMETHODCALLTYPE *NotifyLateDelivery )( 
            IWMReaderAdvanced3 * This,
            QWORD cnsLateness);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetPlayMode)
        HRESULT ( STDMETHODCALLTYPE *SetPlayMode )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WMT_PLAY_MODE Mode);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetPlayMode)
        HRESULT ( STDMETHODCALLTYPE *GetPlayMode )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  WMT_PLAY_MODE *pMode);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetBufferProgress)
        HRESULT ( STDMETHODCALLTYPE *GetBufferProgress )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsBuffering);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetDownloadProgress)
        HRESULT ( STDMETHODCALLTYPE *GetDownloadProgress )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pqwBytesDownloaded,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDownload);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetSaveAsProgress)
        HRESULT ( STDMETHODCALLTYPE *GetSaveAsProgress )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SaveFileAs)
        HRESULT ( STDMETHODCALLTYPE *SaveFileAs )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetProtocolName)
        HRESULT ( STDMETHODCALLTYPE *GetProtocolName )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchProtocol)  WCHAR *pwszProtocol,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchProtocol);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, StartAtMarker)
        HRESULT ( STDMETHODCALLTYPE *StartAtMarker )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD wMarkerIndex,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *GetOutputSetting )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *SetOutputSetting )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, Preroll)
        HRESULT ( STDMETHODCALLTYPE *Preroll )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStart,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetLogClientID)
        HRESULT ( STDMETHODCALLTYPE *SetLogClientID )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  BOOL fLogClientID);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetLogClientID)
        HRESULT ( STDMETHODCALLTYPE *GetLogClientID )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfLogClientID);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, StopBuffering)
        HRESULT ( STDMETHODCALLTYPE *StopBuffering )( 
            IWMReaderAdvanced3 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, OpenStream)
        HRESULT ( STDMETHODCALLTYPE *OpenStream )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  IWMReaderCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced3, StopNetStreaming)
        HRESULT ( STDMETHODCALLTYPE *StopNetStreaming )( 
            IWMReaderAdvanced3 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced3, StartAtPosition)
        HRESULT ( STDMETHODCALLTYPE *StartAtPosition )( 
            IWMReaderAdvanced3 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  void *pvOffsetStart,
            /* [annotation][in] */ 
            _In_  void *pvDuration,
            /* [annotation][in] */ 
            _In_  WMT_OFFSET_FORMAT dwOffsetFormat,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        END_INTERFACE
    } IWMReaderAdvanced3Vtbl;

    interface IWMReaderAdvanced3
    {
        CONST_VTBL struct IWMReaderAdvanced3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderAdvanced3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderAdvanced3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderAdvanced3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderAdvanced3_SetUserProvidedClock(This,fUserClock)	\
    ( (This)->lpVtbl -> SetUserProvidedClock(This,fUserClock) ) 

#define IWMReaderAdvanced3_GetUserProvidedClock(This,pfUserClock)	\
    ( (This)->lpVtbl -> GetUserProvidedClock(This,pfUserClock) ) 

#define IWMReaderAdvanced3_DeliverTime(This,cnsTime)	\
    ( (This)->lpVtbl -> DeliverTime(This,cnsTime) ) 

#define IWMReaderAdvanced3_SetManualStreamSelection(This,fSelection)	\
    ( (This)->lpVtbl -> SetManualStreamSelection(This,fSelection) ) 

#define IWMReaderAdvanced3_GetManualStreamSelection(This,pfSelection)	\
    ( (This)->lpVtbl -> GetManualStreamSelection(This,pfSelection) ) 

#define IWMReaderAdvanced3_SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections)	\
    ( (This)->lpVtbl -> SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections) ) 

#define IWMReaderAdvanced3_GetStreamSelected(This,wStreamNum,pSelection)	\
    ( (This)->lpVtbl -> GetStreamSelected(This,wStreamNum,pSelection) ) 

#define IWMReaderAdvanced3_SetReceiveSelectionCallbacks(This,fGetCallbacks)	\
    ( (This)->lpVtbl -> SetReceiveSelectionCallbacks(This,fGetCallbacks) ) 

#define IWMReaderAdvanced3_GetReceiveSelectionCallbacks(This,pfGetCallbacks)	\
    ( (This)->lpVtbl -> GetReceiveSelectionCallbacks(This,pfGetCallbacks) ) 

#define IWMReaderAdvanced3_SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples)	\
    ( (This)->lpVtbl -> SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples) ) 

#define IWMReaderAdvanced3_GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples)	\
    ( (This)->lpVtbl -> GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples) ) 

#define IWMReaderAdvanced3_SetAllocateForOutput(This,dwOutputNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForOutput(This,dwOutputNum,fAllocate) ) 

#define IWMReaderAdvanced3_GetAllocateForOutput(This,dwOutputNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForOutput(This,dwOutputNum,pfAllocate) ) 

#define IWMReaderAdvanced3_SetAllocateForStream(This,wStreamNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForStream(This,wStreamNum,fAllocate) ) 

#define IWMReaderAdvanced3_GetAllocateForStream(This,dwSreamNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForStream(This,dwSreamNum,pfAllocate) ) 

#define IWMReaderAdvanced3_GetStatistics(This,pStatistics)	\
    ( (This)->lpVtbl -> GetStatistics(This,pStatistics) ) 

#define IWMReaderAdvanced3_SetClientInfo(This,pClientInfo)	\
    ( (This)->lpVtbl -> SetClientInfo(This,pClientInfo) ) 

#define IWMReaderAdvanced3_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax) ) 

#define IWMReaderAdvanced3_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax) ) 

#define IWMReaderAdvanced3_NotifyLateDelivery(This,cnsLateness)	\
    ( (This)->lpVtbl -> NotifyLateDelivery(This,cnsLateness) ) 


#define IWMReaderAdvanced3_SetPlayMode(This,Mode)	\
    ( (This)->lpVtbl -> SetPlayMode(This,Mode) ) 

#define IWMReaderAdvanced3_GetPlayMode(This,pMode)	\
    ( (This)->lpVtbl -> GetPlayMode(This,pMode) ) 

#define IWMReaderAdvanced3_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    ( (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering) ) 

#define IWMReaderAdvanced3_GetDownloadProgress(This,pdwPercent,pqwBytesDownloaded,pcnsDownload)	\
    ( (This)->lpVtbl -> GetDownloadProgress(This,pdwPercent,pqwBytesDownloaded,pcnsDownload) ) 

#define IWMReaderAdvanced3_GetSaveAsProgress(This,pdwPercent)	\
    ( (This)->lpVtbl -> GetSaveAsProgress(This,pdwPercent) ) 

#define IWMReaderAdvanced3_SaveFileAs(This,pwszFilename)	\
    ( (This)->lpVtbl -> SaveFileAs(This,pwszFilename) ) 

#define IWMReaderAdvanced3_GetProtocolName(This,pwszProtocol,pcchProtocol)	\
    ( (This)->lpVtbl -> GetProtocolName(This,pwszProtocol,pcchProtocol) ) 

#define IWMReaderAdvanced3_StartAtMarker(This,wMarkerIndex,cnsDuration,fRate,pvContext)	\
    ( (This)->lpVtbl -> StartAtMarker(This,wMarkerIndex,cnsDuration,fRate,pvContext) ) 

#define IWMReaderAdvanced3_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength) ) 

#define IWMReaderAdvanced3_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength) ) 

#define IWMReaderAdvanced3_Preroll(This,cnsStart,cnsDuration,fRate)	\
    ( (This)->lpVtbl -> Preroll(This,cnsStart,cnsDuration,fRate) ) 

#define IWMReaderAdvanced3_SetLogClientID(This,fLogClientID)	\
    ( (This)->lpVtbl -> SetLogClientID(This,fLogClientID) ) 

#define IWMReaderAdvanced3_GetLogClientID(This,pfLogClientID)	\
    ( (This)->lpVtbl -> GetLogClientID(This,pfLogClientID) ) 

#define IWMReaderAdvanced3_StopBuffering(This)	\
    ( (This)->lpVtbl -> StopBuffering(This) ) 

#define IWMReaderAdvanced3_OpenStream(This,pStream,pCallback,pvContext)	\
    ( (This)->lpVtbl -> OpenStream(This,pStream,pCallback,pvContext) ) 


#define IWMReaderAdvanced3_StopNetStreaming(This)	\
    ( (This)->lpVtbl -> StopNetStreaming(This) ) 

#define IWMReaderAdvanced3_StartAtPosition(This,wStreamNum,pvOffsetStart,pvDuration,dwOffsetFormat,fRate,pvContext)	\
    ( (This)->lpVtbl -> StartAtPosition(This,wStreamNum,pvOffsetStart,pvDuration,dwOffsetFormat,fRate,pvContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderAdvanced3_INTERFACE_DEFINED__ */


#ifndef __IWMReaderAdvanced4_INTERFACE_DEFINED__
#define __IWMReaderAdvanced4_INTERFACE_DEFINED__

/* interface IWMReaderAdvanced4 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderAdvanced4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("945A76A2-12AE-4d48-BD3C-CD1D90399B85")
    IWMReaderAdvanced4 : public IWMReaderAdvanced3
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLanguageCount( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwLanguageCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLanguage( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  WORD wLanguage,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchLanguageStringLength)  WCHAR *pwszLanguageString,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchLanguageStringLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxSpeedFactor( 
            /* [annotation][out] */ 
            _Out_  double *pdblFactor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsUsingFastCache( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfUsingFastCache) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddLogParam( 
            /* [annotation][in] */ 
            _In_  LPCWSTR wszNameSpace,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszName,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendLogParams( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanSaveFileAs( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfCanSave) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelSaveFileAs( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetURL( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchURL)  WCHAR *pwszURL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchURL) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderAdvanced4Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderAdvanced4 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderAdvanced4 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *SetUserProvidedClock )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  BOOL fUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *GetUserProvidedClock )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, DeliverTime)
        HRESULT ( STDMETHODCALLTYPE *DeliverTime )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsTime);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *SetManualStreamSelection )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  BOOL fSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *GetManualStreamSelection )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetStreamsSelected)
        HRESULT ( STDMETHODCALLTYPE *SetStreamsSelected )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  WORD cStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pwStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStreamSelected)
        HRESULT ( STDMETHODCALLTYPE *GetStreamSelected )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WMT_STREAM_SELECTION *pSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  BOOL fGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveStreamSamples )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveStreamSamples )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForOutput )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForOutput )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForStream )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForStream )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  WORD dwSreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStatistics)
        HRESULT ( STDMETHODCALLTYPE *GetStatistics )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out][in] */ 
            _Inout_  WM_READER_STATISTICS *pStatistics);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetClientInfo)
        HRESULT ( STDMETHODCALLTYPE *SetClientInfo )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  WM_READER_CLIENTINFO *pClientInfo);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxOutputSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxOutputSampleSize )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxStreamSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxStreamSampleSize )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  WORD wStream,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, NotifyLateDelivery)
        HRESULT ( STDMETHODCALLTYPE *NotifyLateDelivery )( 
            IWMReaderAdvanced4 * This,
            QWORD cnsLateness);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetPlayMode)
        HRESULT ( STDMETHODCALLTYPE *SetPlayMode )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  WMT_PLAY_MODE Mode);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetPlayMode)
        HRESULT ( STDMETHODCALLTYPE *GetPlayMode )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out] */ 
            _Out_  WMT_PLAY_MODE *pMode);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetBufferProgress)
        HRESULT ( STDMETHODCALLTYPE *GetBufferProgress )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsBuffering);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetDownloadProgress)
        HRESULT ( STDMETHODCALLTYPE *GetDownloadProgress )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pqwBytesDownloaded,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDownload);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetSaveAsProgress)
        HRESULT ( STDMETHODCALLTYPE *GetSaveAsProgress )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SaveFileAs)
        HRESULT ( STDMETHODCALLTYPE *SaveFileAs )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetProtocolName)
        HRESULT ( STDMETHODCALLTYPE *GetProtocolName )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchProtocol)  WCHAR *pwszProtocol,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchProtocol);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, StartAtMarker)
        HRESULT ( STDMETHODCALLTYPE *StartAtMarker )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  WORD wMarkerIndex,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *GetOutputSetting )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *SetOutputSetting )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, Preroll)
        HRESULT ( STDMETHODCALLTYPE *Preroll )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStart,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetLogClientID)
        HRESULT ( STDMETHODCALLTYPE *SetLogClientID )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  BOOL fLogClientID);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetLogClientID)
        HRESULT ( STDMETHODCALLTYPE *GetLogClientID )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfLogClientID);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, StopBuffering)
        HRESULT ( STDMETHODCALLTYPE *StopBuffering )( 
            IWMReaderAdvanced4 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, OpenStream)
        HRESULT ( STDMETHODCALLTYPE *OpenStream )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  IWMReaderCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced3, StopNetStreaming)
        HRESULT ( STDMETHODCALLTYPE *StopNetStreaming )( 
            IWMReaderAdvanced4 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced3, StartAtPosition)
        HRESULT ( STDMETHODCALLTYPE *StartAtPosition )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  void *pvOffsetStart,
            /* [annotation][in] */ 
            _In_  void *pvDuration,
            /* [annotation][in] */ 
            _In_  WMT_OFFSET_FORMAT dwOffsetFormat,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetLanguageCount)
        HRESULT ( STDMETHODCALLTYPE *GetLanguageCount )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwLanguageCount);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetLanguage)
        HRESULT ( STDMETHODCALLTYPE *GetLanguage )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  WORD wLanguage,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchLanguageStringLength)  WCHAR *pwszLanguageString,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchLanguageStringLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetMaxSpeedFactor)
        HRESULT ( STDMETHODCALLTYPE *GetMaxSpeedFactor )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out] */ 
            _Out_  double *pdblFactor);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, IsUsingFastCache)
        HRESULT ( STDMETHODCALLTYPE *IsUsingFastCache )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfUsingFastCache);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, AddLogParam)
        HRESULT ( STDMETHODCALLTYPE *AddLogParam )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszNameSpace,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszName,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszValue);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, SendLogParams)
        HRESULT ( STDMETHODCALLTYPE *SendLogParams )( 
            IWMReaderAdvanced4 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, CanSaveFileAs)
        HRESULT ( STDMETHODCALLTYPE *CanSaveFileAs )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfCanSave);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, CancelSaveFileAs)
        HRESULT ( STDMETHODCALLTYPE *CancelSaveFileAs )( 
            IWMReaderAdvanced4 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetURL)
        HRESULT ( STDMETHODCALLTYPE *GetURL )( 
            IWMReaderAdvanced4 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchURL)  WCHAR *pwszURL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchURL);
        
        END_INTERFACE
    } IWMReaderAdvanced4Vtbl;

    interface IWMReaderAdvanced4
    {
        CONST_VTBL struct IWMReaderAdvanced4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderAdvanced4_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderAdvanced4_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderAdvanced4_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderAdvanced4_SetUserProvidedClock(This,fUserClock)	\
    ( (This)->lpVtbl -> SetUserProvidedClock(This,fUserClock) ) 

#define IWMReaderAdvanced4_GetUserProvidedClock(This,pfUserClock)	\
    ( (This)->lpVtbl -> GetUserProvidedClock(This,pfUserClock) ) 

#define IWMReaderAdvanced4_DeliverTime(This,cnsTime)	\
    ( (This)->lpVtbl -> DeliverTime(This,cnsTime) ) 

#define IWMReaderAdvanced4_SetManualStreamSelection(This,fSelection)	\
    ( (This)->lpVtbl -> SetManualStreamSelection(This,fSelection) ) 

#define IWMReaderAdvanced4_GetManualStreamSelection(This,pfSelection)	\
    ( (This)->lpVtbl -> GetManualStreamSelection(This,pfSelection) ) 

#define IWMReaderAdvanced4_SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections)	\
    ( (This)->lpVtbl -> SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections) ) 

#define IWMReaderAdvanced4_GetStreamSelected(This,wStreamNum,pSelection)	\
    ( (This)->lpVtbl -> GetStreamSelected(This,wStreamNum,pSelection) ) 

#define IWMReaderAdvanced4_SetReceiveSelectionCallbacks(This,fGetCallbacks)	\
    ( (This)->lpVtbl -> SetReceiveSelectionCallbacks(This,fGetCallbacks) ) 

#define IWMReaderAdvanced4_GetReceiveSelectionCallbacks(This,pfGetCallbacks)	\
    ( (This)->lpVtbl -> GetReceiveSelectionCallbacks(This,pfGetCallbacks) ) 

#define IWMReaderAdvanced4_SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples)	\
    ( (This)->lpVtbl -> SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples) ) 

#define IWMReaderAdvanced4_GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples)	\
    ( (This)->lpVtbl -> GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples) ) 

#define IWMReaderAdvanced4_SetAllocateForOutput(This,dwOutputNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForOutput(This,dwOutputNum,fAllocate) ) 

#define IWMReaderAdvanced4_GetAllocateForOutput(This,dwOutputNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForOutput(This,dwOutputNum,pfAllocate) ) 

#define IWMReaderAdvanced4_SetAllocateForStream(This,wStreamNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForStream(This,wStreamNum,fAllocate) ) 

#define IWMReaderAdvanced4_GetAllocateForStream(This,dwSreamNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForStream(This,dwSreamNum,pfAllocate) ) 

#define IWMReaderAdvanced4_GetStatistics(This,pStatistics)	\
    ( (This)->lpVtbl -> GetStatistics(This,pStatistics) ) 

#define IWMReaderAdvanced4_SetClientInfo(This,pClientInfo)	\
    ( (This)->lpVtbl -> SetClientInfo(This,pClientInfo) ) 

#define IWMReaderAdvanced4_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax) ) 

#define IWMReaderAdvanced4_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax) ) 

#define IWMReaderAdvanced4_NotifyLateDelivery(This,cnsLateness)	\
    ( (This)->lpVtbl -> NotifyLateDelivery(This,cnsLateness) ) 


#define IWMReaderAdvanced4_SetPlayMode(This,Mode)	\
    ( (This)->lpVtbl -> SetPlayMode(This,Mode) ) 

#define IWMReaderAdvanced4_GetPlayMode(This,pMode)	\
    ( (This)->lpVtbl -> GetPlayMode(This,pMode) ) 

#define IWMReaderAdvanced4_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    ( (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering) ) 

#define IWMReaderAdvanced4_GetDownloadProgress(This,pdwPercent,pqwBytesDownloaded,pcnsDownload)	\
    ( (This)->lpVtbl -> GetDownloadProgress(This,pdwPercent,pqwBytesDownloaded,pcnsDownload) ) 

#define IWMReaderAdvanced4_GetSaveAsProgress(This,pdwPercent)	\
    ( (This)->lpVtbl -> GetSaveAsProgress(This,pdwPercent) ) 

#define IWMReaderAdvanced4_SaveFileAs(This,pwszFilename)	\
    ( (This)->lpVtbl -> SaveFileAs(This,pwszFilename) ) 

#define IWMReaderAdvanced4_GetProtocolName(This,pwszProtocol,pcchProtocol)	\
    ( (This)->lpVtbl -> GetProtocolName(This,pwszProtocol,pcchProtocol) ) 

#define IWMReaderAdvanced4_StartAtMarker(This,wMarkerIndex,cnsDuration,fRate,pvContext)	\
    ( (This)->lpVtbl -> StartAtMarker(This,wMarkerIndex,cnsDuration,fRate,pvContext) ) 

#define IWMReaderAdvanced4_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength) ) 

#define IWMReaderAdvanced4_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength) ) 

#define IWMReaderAdvanced4_Preroll(This,cnsStart,cnsDuration,fRate)	\
    ( (This)->lpVtbl -> Preroll(This,cnsStart,cnsDuration,fRate) ) 

#define IWMReaderAdvanced4_SetLogClientID(This,fLogClientID)	\
    ( (This)->lpVtbl -> SetLogClientID(This,fLogClientID) ) 

#define IWMReaderAdvanced4_GetLogClientID(This,pfLogClientID)	\
    ( (This)->lpVtbl -> GetLogClientID(This,pfLogClientID) ) 

#define IWMReaderAdvanced4_StopBuffering(This)	\
    ( (This)->lpVtbl -> StopBuffering(This) ) 

#define IWMReaderAdvanced4_OpenStream(This,pStream,pCallback,pvContext)	\
    ( (This)->lpVtbl -> OpenStream(This,pStream,pCallback,pvContext) ) 


#define IWMReaderAdvanced4_StopNetStreaming(This)	\
    ( (This)->lpVtbl -> StopNetStreaming(This) ) 

#define IWMReaderAdvanced4_StartAtPosition(This,wStreamNum,pvOffsetStart,pvDuration,dwOffsetFormat,fRate,pvContext)	\
    ( (This)->lpVtbl -> StartAtPosition(This,wStreamNum,pvOffsetStart,pvDuration,dwOffsetFormat,fRate,pvContext) ) 


#define IWMReaderAdvanced4_GetLanguageCount(This,dwOutputNum,pwLanguageCount)	\
    ( (This)->lpVtbl -> GetLanguageCount(This,dwOutputNum,pwLanguageCount) ) 

#define IWMReaderAdvanced4_GetLanguage(This,dwOutputNum,wLanguage,pwszLanguageString,pcchLanguageStringLength)	\
    ( (This)->lpVtbl -> GetLanguage(This,dwOutputNum,wLanguage,pwszLanguageString,pcchLanguageStringLength) ) 

#define IWMReaderAdvanced4_GetMaxSpeedFactor(This,pdblFactor)	\
    ( (This)->lpVtbl -> GetMaxSpeedFactor(This,pdblFactor) ) 

#define IWMReaderAdvanced4_IsUsingFastCache(This,pfUsingFastCache)	\
    ( (This)->lpVtbl -> IsUsingFastCache(This,pfUsingFastCache) ) 

#define IWMReaderAdvanced4_AddLogParam(This,wszNameSpace,wszName,wszValue)	\
    ( (This)->lpVtbl -> AddLogParam(This,wszNameSpace,wszName,wszValue) ) 

#define IWMReaderAdvanced4_SendLogParams(This)	\
    ( (This)->lpVtbl -> SendLogParams(This) ) 

#define IWMReaderAdvanced4_CanSaveFileAs(This,pfCanSave)	\
    ( (This)->lpVtbl -> CanSaveFileAs(This,pfCanSave) ) 

#define IWMReaderAdvanced4_CancelSaveFileAs(This)	\
    ( (This)->lpVtbl -> CancelSaveFileAs(This) ) 

#define IWMReaderAdvanced4_GetURL(This,pwszURL,pcchURL)	\
    ( (This)->lpVtbl -> GetURL(This,pwszURL,pcchURL) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderAdvanced4_INTERFACE_DEFINED__ */


#ifndef __IWMReaderAdvanced5_INTERFACE_DEFINED__
#define __IWMReaderAdvanced5_INTERFACE_DEFINED__

/* interface IWMReaderAdvanced5 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderAdvanced5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("24C44DB0-55D1-49ae-A5CC-F13815E36363")
    IWMReaderAdvanced5 : public IWMReaderAdvanced4
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPlayerHook( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMPlayerHook *pHook) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderAdvanced5Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderAdvanced5 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderAdvanced5 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *SetUserProvidedClock )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  BOOL fUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *GetUserProvidedClock )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, DeliverTime)
        HRESULT ( STDMETHODCALLTYPE *DeliverTime )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsTime);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *SetManualStreamSelection )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  BOOL fSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *GetManualStreamSelection )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetStreamsSelected)
        HRESULT ( STDMETHODCALLTYPE *SetStreamsSelected )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  WORD cStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pwStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStreamSelected)
        HRESULT ( STDMETHODCALLTYPE *GetStreamSelected )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WMT_STREAM_SELECTION *pSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  BOOL fGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveStreamSamples )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveStreamSamples )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForOutput )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForOutput )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForStream )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForStream )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  WORD dwSreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStatistics)
        HRESULT ( STDMETHODCALLTYPE *GetStatistics )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out][in] */ 
            _Inout_  WM_READER_STATISTICS *pStatistics);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetClientInfo)
        HRESULT ( STDMETHODCALLTYPE *SetClientInfo )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  WM_READER_CLIENTINFO *pClientInfo);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxOutputSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxOutputSampleSize )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxStreamSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxStreamSampleSize )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  WORD wStream,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, NotifyLateDelivery)
        HRESULT ( STDMETHODCALLTYPE *NotifyLateDelivery )( 
            IWMReaderAdvanced5 * This,
            QWORD cnsLateness);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetPlayMode)
        HRESULT ( STDMETHODCALLTYPE *SetPlayMode )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  WMT_PLAY_MODE Mode);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetPlayMode)
        HRESULT ( STDMETHODCALLTYPE *GetPlayMode )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out] */ 
            _Out_  WMT_PLAY_MODE *pMode);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetBufferProgress)
        HRESULT ( STDMETHODCALLTYPE *GetBufferProgress )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsBuffering);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetDownloadProgress)
        HRESULT ( STDMETHODCALLTYPE *GetDownloadProgress )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pqwBytesDownloaded,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDownload);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetSaveAsProgress)
        HRESULT ( STDMETHODCALLTYPE *GetSaveAsProgress )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SaveFileAs)
        HRESULT ( STDMETHODCALLTYPE *SaveFileAs )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetProtocolName)
        HRESULT ( STDMETHODCALLTYPE *GetProtocolName )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchProtocol)  WCHAR *pwszProtocol,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchProtocol);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, StartAtMarker)
        HRESULT ( STDMETHODCALLTYPE *StartAtMarker )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  WORD wMarkerIndex,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *GetOutputSetting )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *SetOutputSetting )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, Preroll)
        HRESULT ( STDMETHODCALLTYPE *Preroll )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStart,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetLogClientID)
        HRESULT ( STDMETHODCALLTYPE *SetLogClientID )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  BOOL fLogClientID);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetLogClientID)
        HRESULT ( STDMETHODCALLTYPE *GetLogClientID )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfLogClientID);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, StopBuffering)
        HRESULT ( STDMETHODCALLTYPE *StopBuffering )( 
            IWMReaderAdvanced5 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, OpenStream)
        HRESULT ( STDMETHODCALLTYPE *OpenStream )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  IWMReaderCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced3, StopNetStreaming)
        HRESULT ( STDMETHODCALLTYPE *StopNetStreaming )( 
            IWMReaderAdvanced5 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced3, StartAtPosition)
        HRESULT ( STDMETHODCALLTYPE *StartAtPosition )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  void *pvOffsetStart,
            /* [annotation][in] */ 
            _In_  void *pvDuration,
            /* [annotation][in] */ 
            _In_  WMT_OFFSET_FORMAT dwOffsetFormat,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetLanguageCount)
        HRESULT ( STDMETHODCALLTYPE *GetLanguageCount )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwLanguageCount);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetLanguage)
        HRESULT ( STDMETHODCALLTYPE *GetLanguage )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  WORD wLanguage,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchLanguageStringLength)  WCHAR *pwszLanguageString,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchLanguageStringLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetMaxSpeedFactor)
        HRESULT ( STDMETHODCALLTYPE *GetMaxSpeedFactor )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out] */ 
            _Out_  double *pdblFactor);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, IsUsingFastCache)
        HRESULT ( STDMETHODCALLTYPE *IsUsingFastCache )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfUsingFastCache);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, AddLogParam)
        HRESULT ( STDMETHODCALLTYPE *AddLogParam )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszNameSpace,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszName,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszValue);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, SendLogParams)
        HRESULT ( STDMETHODCALLTYPE *SendLogParams )( 
            IWMReaderAdvanced5 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, CanSaveFileAs)
        HRESULT ( STDMETHODCALLTYPE *CanSaveFileAs )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfCanSave);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, CancelSaveFileAs)
        HRESULT ( STDMETHODCALLTYPE *CancelSaveFileAs )( 
            IWMReaderAdvanced5 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetURL)
        HRESULT ( STDMETHODCALLTYPE *GetURL )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchURL)  WCHAR *pwszURL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchURL);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced5, SetPlayerHook)
        HRESULT ( STDMETHODCALLTYPE *SetPlayerHook )( 
            IWMReaderAdvanced5 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMPlayerHook *pHook);
        
        END_INTERFACE
    } IWMReaderAdvanced5Vtbl;

    interface IWMReaderAdvanced5
    {
        CONST_VTBL struct IWMReaderAdvanced5Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderAdvanced5_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderAdvanced5_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderAdvanced5_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderAdvanced5_SetUserProvidedClock(This,fUserClock)	\
    ( (This)->lpVtbl -> SetUserProvidedClock(This,fUserClock) ) 

#define IWMReaderAdvanced5_GetUserProvidedClock(This,pfUserClock)	\
    ( (This)->lpVtbl -> GetUserProvidedClock(This,pfUserClock) ) 

#define IWMReaderAdvanced5_DeliverTime(This,cnsTime)	\
    ( (This)->lpVtbl -> DeliverTime(This,cnsTime) ) 

#define IWMReaderAdvanced5_SetManualStreamSelection(This,fSelection)	\
    ( (This)->lpVtbl -> SetManualStreamSelection(This,fSelection) ) 

#define IWMReaderAdvanced5_GetManualStreamSelection(This,pfSelection)	\
    ( (This)->lpVtbl -> GetManualStreamSelection(This,pfSelection) ) 

#define IWMReaderAdvanced5_SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections)	\
    ( (This)->lpVtbl -> SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections) ) 

#define IWMReaderAdvanced5_GetStreamSelected(This,wStreamNum,pSelection)	\
    ( (This)->lpVtbl -> GetStreamSelected(This,wStreamNum,pSelection) ) 

#define IWMReaderAdvanced5_SetReceiveSelectionCallbacks(This,fGetCallbacks)	\
    ( (This)->lpVtbl -> SetReceiveSelectionCallbacks(This,fGetCallbacks) ) 

#define IWMReaderAdvanced5_GetReceiveSelectionCallbacks(This,pfGetCallbacks)	\
    ( (This)->lpVtbl -> GetReceiveSelectionCallbacks(This,pfGetCallbacks) ) 

#define IWMReaderAdvanced5_SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples)	\
    ( (This)->lpVtbl -> SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples) ) 

#define IWMReaderAdvanced5_GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples)	\
    ( (This)->lpVtbl -> GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples) ) 

#define IWMReaderAdvanced5_SetAllocateForOutput(This,dwOutputNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForOutput(This,dwOutputNum,fAllocate) ) 

#define IWMReaderAdvanced5_GetAllocateForOutput(This,dwOutputNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForOutput(This,dwOutputNum,pfAllocate) ) 

#define IWMReaderAdvanced5_SetAllocateForStream(This,wStreamNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForStream(This,wStreamNum,fAllocate) ) 

#define IWMReaderAdvanced5_GetAllocateForStream(This,dwSreamNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForStream(This,dwSreamNum,pfAllocate) ) 

#define IWMReaderAdvanced5_GetStatistics(This,pStatistics)	\
    ( (This)->lpVtbl -> GetStatistics(This,pStatistics) ) 

#define IWMReaderAdvanced5_SetClientInfo(This,pClientInfo)	\
    ( (This)->lpVtbl -> SetClientInfo(This,pClientInfo) ) 

#define IWMReaderAdvanced5_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax) ) 

#define IWMReaderAdvanced5_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax) ) 

#define IWMReaderAdvanced5_NotifyLateDelivery(This,cnsLateness)	\
    ( (This)->lpVtbl -> NotifyLateDelivery(This,cnsLateness) ) 


#define IWMReaderAdvanced5_SetPlayMode(This,Mode)	\
    ( (This)->lpVtbl -> SetPlayMode(This,Mode) ) 

#define IWMReaderAdvanced5_GetPlayMode(This,pMode)	\
    ( (This)->lpVtbl -> GetPlayMode(This,pMode) ) 

#define IWMReaderAdvanced5_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    ( (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering) ) 

#define IWMReaderAdvanced5_GetDownloadProgress(This,pdwPercent,pqwBytesDownloaded,pcnsDownload)	\
    ( (This)->lpVtbl -> GetDownloadProgress(This,pdwPercent,pqwBytesDownloaded,pcnsDownload) ) 

#define IWMReaderAdvanced5_GetSaveAsProgress(This,pdwPercent)	\
    ( (This)->lpVtbl -> GetSaveAsProgress(This,pdwPercent) ) 

#define IWMReaderAdvanced5_SaveFileAs(This,pwszFilename)	\
    ( (This)->lpVtbl -> SaveFileAs(This,pwszFilename) ) 

#define IWMReaderAdvanced5_GetProtocolName(This,pwszProtocol,pcchProtocol)	\
    ( (This)->lpVtbl -> GetProtocolName(This,pwszProtocol,pcchProtocol) ) 

#define IWMReaderAdvanced5_StartAtMarker(This,wMarkerIndex,cnsDuration,fRate,pvContext)	\
    ( (This)->lpVtbl -> StartAtMarker(This,wMarkerIndex,cnsDuration,fRate,pvContext) ) 

#define IWMReaderAdvanced5_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength) ) 

#define IWMReaderAdvanced5_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength) ) 

#define IWMReaderAdvanced5_Preroll(This,cnsStart,cnsDuration,fRate)	\
    ( (This)->lpVtbl -> Preroll(This,cnsStart,cnsDuration,fRate) ) 

#define IWMReaderAdvanced5_SetLogClientID(This,fLogClientID)	\
    ( (This)->lpVtbl -> SetLogClientID(This,fLogClientID) ) 

#define IWMReaderAdvanced5_GetLogClientID(This,pfLogClientID)	\
    ( (This)->lpVtbl -> GetLogClientID(This,pfLogClientID) ) 

#define IWMReaderAdvanced5_StopBuffering(This)	\
    ( (This)->lpVtbl -> StopBuffering(This) ) 

#define IWMReaderAdvanced5_OpenStream(This,pStream,pCallback,pvContext)	\
    ( (This)->lpVtbl -> OpenStream(This,pStream,pCallback,pvContext) ) 


#define IWMReaderAdvanced5_StopNetStreaming(This)	\
    ( (This)->lpVtbl -> StopNetStreaming(This) ) 

#define IWMReaderAdvanced5_StartAtPosition(This,wStreamNum,pvOffsetStart,pvDuration,dwOffsetFormat,fRate,pvContext)	\
    ( (This)->lpVtbl -> StartAtPosition(This,wStreamNum,pvOffsetStart,pvDuration,dwOffsetFormat,fRate,pvContext) ) 


#define IWMReaderAdvanced5_GetLanguageCount(This,dwOutputNum,pwLanguageCount)	\
    ( (This)->lpVtbl -> GetLanguageCount(This,dwOutputNum,pwLanguageCount) ) 

#define IWMReaderAdvanced5_GetLanguage(This,dwOutputNum,wLanguage,pwszLanguageString,pcchLanguageStringLength)	\
    ( (This)->lpVtbl -> GetLanguage(This,dwOutputNum,wLanguage,pwszLanguageString,pcchLanguageStringLength) ) 

#define IWMReaderAdvanced5_GetMaxSpeedFactor(This,pdblFactor)	\
    ( (This)->lpVtbl -> GetMaxSpeedFactor(This,pdblFactor) ) 

#define IWMReaderAdvanced5_IsUsingFastCache(This,pfUsingFastCache)	\
    ( (This)->lpVtbl -> IsUsingFastCache(This,pfUsingFastCache) ) 

#define IWMReaderAdvanced5_AddLogParam(This,wszNameSpace,wszName,wszValue)	\
    ( (This)->lpVtbl -> AddLogParam(This,wszNameSpace,wszName,wszValue) ) 

#define IWMReaderAdvanced5_SendLogParams(This)	\
    ( (This)->lpVtbl -> SendLogParams(This) ) 

#define IWMReaderAdvanced5_CanSaveFileAs(This,pfCanSave)	\
    ( (This)->lpVtbl -> CanSaveFileAs(This,pfCanSave) ) 

#define IWMReaderAdvanced5_CancelSaveFileAs(This)	\
    ( (This)->lpVtbl -> CancelSaveFileAs(This) ) 

#define IWMReaderAdvanced5_GetURL(This,pwszURL,pcchURL)	\
    ( (This)->lpVtbl -> GetURL(This,pwszURL,pcchURL) ) 


#define IWMReaderAdvanced5_SetPlayerHook(This,dwOutputNum,pHook)	\
    ( (This)->lpVtbl -> SetPlayerHook(This,dwOutputNum,pHook) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderAdvanced5_INTERFACE_DEFINED__ */


#ifndef __IWMReaderAdvanced6_INTERFACE_DEFINED__
#define __IWMReaderAdvanced6_INTERFACE_DEFINED__

/* interface IWMReaderAdvanced6 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderAdvanced6;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("18A2E7F8-428F-4acd-8A00-E64639BC93DE")
    IWMReaderAdvanced6 : public IWMReaderAdvanced5
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetProtectStreamSamples( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cbCertificate)  BYTE *pbCertificate,
            /* [annotation][in] */ 
            _In_  DWORD cbCertificate,
            /* [annotation][in] */ 
            _In_  DWORD dwCertificateType,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbInitializationVector)  BYTE *pbInitializationVector,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbInitializationVector) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderAdvanced6Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderAdvanced6 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderAdvanced6 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *SetUserProvidedClock )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  BOOL fUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetUserProvidedClock)
        HRESULT ( STDMETHODCALLTYPE *GetUserProvidedClock )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfUserClock);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, DeliverTime)
        HRESULT ( STDMETHODCALLTYPE *DeliverTime )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsTime);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *SetManualStreamSelection )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  BOOL fSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetManualStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *GetManualStreamSelection )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetStreamsSelected)
        HRESULT ( STDMETHODCALLTYPE *SetStreamsSelected )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  WORD cStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pwStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStreamSelected)
        HRESULT ( STDMETHODCALLTYPE *GetStreamSelected )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WMT_STREAM_SELECTION *pSelection);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  BOOL fGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveSelectionCallbacks)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveSelectionCallbacks )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfGetCallbacks);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *SetReceiveStreamSamples )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetReceiveStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *GetReceiveStreamSamples )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfReceiveStreamSamples);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForOutput )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForOutput )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *SetAllocateForStream )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  BOOL fAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetAllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *GetAllocateForStream )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  WORD dwSreamNum,
            /* [annotation][out] */ 
            _Out_  BOOL *pfAllocate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetStatistics)
        HRESULT ( STDMETHODCALLTYPE *GetStatistics )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out][in] */ 
            _Inout_  WM_READER_STATISTICS *pStatistics);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, SetClientInfo)
        HRESULT ( STDMETHODCALLTYPE *SetClientInfo )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  WM_READER_CLIENTINFO *pClientInfo);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxOutputSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxOutputSampleSize )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, GetMaxStreamSampleSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxStreamSampleSize )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  WORD wStream,
            /* [annotation][out] */ 
            _Out_  DWORD *pcbMax);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced, NotifyLateDelivery)
        HRESULT ( STDMETHODCALLTYPE *NotifyLateDelivery )( 
            IWMReaderAdvanced6 * This,
            QWORD cnsLateness);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetPlayMode)
        HRESULT ( STDMETHODCALLTYPE *SetPlayMode )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  WMT_PLAY_MODE Mode);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetPlayMode)
        HRESULT ( STDMETHODCALLTYPE *GetPlayMode )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out] */ 
            _Out_  WMT_PLAY_MODE *pMode);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetBufferProgress)
        HRESULT ( STDMETHODCALLTYPE *GetBufferProgress )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsBuffering);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetDownloadProgress)
        HRESULT ( STDMETHODCALLTYPE *GetDownloadProgress )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent,
            /* [annotation][out] */ 
            _Out_  QWORD *pqwBytesDownloaded,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDownload);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetSaveAsProgress)
        HRESULT ( STDMETHODCALLTYPE *GetSaveAsProgress )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPercent);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SaveFileAs)
        HRESULT ( STDMETHODCALLTYPE *SaveFileAs )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszFilename);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetProtocolName)
        HRESULT ( STDMETHODCALLTYPE *GetProtocolName )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchProtocol)  WCHAR *pwszProtocol,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchProtocol);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, StartAtMarker)
        HRESULT ( STDMETHODCALLTYPE *StartAtMarker )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  WORD wMarkerIndex,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *GetOutputSetting )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetOutputSetting)
        HRESULT ( STDMETHODCALLTYPE *SetOutputSetting )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, Preroll)
        HRESULT ( STDMETHODCALLTYPE *Preroll )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStart,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float fRate);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, SetLogClientID)
        HRESULT ( STDMETHODCALLTYPE *SetLogClientID )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  BOOL fLogClientID);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, GetLogClientID)
        HRESULT ( STDMETHODCALLTYPE *GetLogClientID )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfLogClientID);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, StopBuffering)
        HRESULT ( STDMETHODCALLTYPE *StopBuffering )( 
            IWMReaderAdvanced6 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced2, OpenStream)
        HRESULT ( STDMETHODCALLTYPE *OpenStream )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  IWMReaderCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced3, StopNetStreaming)
        HRESULT ( STDMETHODCALLTYPE *StopNetStreaming )( 
            IWMReaderAdvanced6 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced3, StartAtPosition)
        HRESULT ( STDMETHODCALLTYPE *StartAtPosition )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  void *pvOffsetStart,
            /* [annotation][in] */ 
            _In_  void *pvDuration,
            /* [annotation][in] */ 
            _In_  WMT_OFFSET_FORMAT dwOffsetFormat,
            /* [annotation][in] */ 
            _In_  float fRate,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetLanguageCount)
        HRESULT ( STDMETHODCALLTYPE *GetLanguageCount )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwLanguageCount);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetLanguage)
        HRESULT ( STDMETHODCALLTYPE *GetLanguage )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  WORD wLanguage,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchLanguageStringLength)  WCHAR *pwszLanguageString,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchLanguageStringLength);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetMaxSpeedFactor)
        HRESULT ( STDMETHODCALLTYPE *GetMaxSpeedFactor )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out] */ 
            _Out_  double *pdblFactor);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, IsUsingFastCache)
        HRESULT ( STDMETHODCALLTYPE *IsUsingFastCache )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfUsingFastCache);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, AddLogParam)
        HRESULT ( STDMETHODCALLTYPE *AddLogParam )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszNameSpace,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszName,
            /* [annotation][in] */ 
            _In_  LPCWSTR wszValue);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, SendLogParams)
        HRESULT ( STDMETHODCALLTYPE *SendLogParams )( 
            IWMReaderAdvanced6 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, CanSaveFileAs)
        HRESULT ( STDMETHODCALLTYPE *CanSaveFileAs )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfCanSave);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, CancelSaveFileAs)
        HRESULT ( STDMETHODCALLTYPE *CancelSaveFileAs )( 
            IWMReaderAdvanced6 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced4, GetURL)
        HRESULT ( STDMETHODCALLTYPE *GetURL )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchURL)  WCHAR *pwszURL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchURL);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced5, SetPlayerHook)
        HRESULT ( STDMETHODCALLTYPE *SetPlayerHook )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMPlayerHook *pHook);
        
        DECLSPEC_XFGVIRT(IWMReaderAdvanced6, SetProtectStreamSamples)
        HRESULT ( STDMETHODCALLTYPE *SetProtectStreamSamples )( 
            IWMReaderAdvanced6 * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbCertificate)  BYTE *pbCertificate,
            /* [annotation][in] */ 
            _In_  DWORD cbCertificate,
            /* [annotation][in] */ 
            _In_  DWORD dwCertificateType,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbInitializationVector)  BYTE *pbInitializationVector,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbInitializationVector);
        
        END_INTERFACE
    } IWMReaderAdvanced6Vtbl;

    interface IWMReaderAdvanced6
    {
        CONST_VTBL struct IWMReaderAdvanced6Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderAdvanced6_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderAdvanced6_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderAdvanced6_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderAdvanced6_SetUserProvidedClock(This,fUserClock)	\
    ( (This)->lpVtbl -> SetUserProvidedClock(This,fUserClock) ) 

#define IWMReaderAdvanced6_GetUserProvidedClock(This,pfUserClock)	\
    ( (This)->lpVtbl -> GetUserProvidedClock(This,pfUserClock) ) 

#define IWMReaderAdvanced6_DeliverTime(This,cnsTime)	\
    ( (This)->lpVtbl -> DeliverTime(This,cnsTime) ) 

#define IWMReaderAdvanced6_SetManualStreamSelection(This,fSelection)	\
    ( (This)->lpVtbl -> SetManualStreamSelection(This,fSelection) ) 

#define IWMReaderAdvanced6_GetManualStreamSelection(This,pfSelection)	\
    ( (This)->lpVtbl -> GetManualStreamSelection(This,pfSelection) ) 

#define IWMReaderAdvanced6_SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections)	\
    ( (This)->lpVtbl -> SetStreamsSelected(This,cStreamCount,pwStreamNumbers,pSelections) ) 

#define IWMReaderAdvanced6_GetStreamSelected(This,wStreamNum,pSelection)	\
    ( (This)->lpVtbl -> GetStreamSelected(This,wStreamNum,pSelection) ) 

#define IWMReaderAdvanced6_SetReceiveSelectionCallbacks(This,fGetCallbacks)	\
    ( (This)->lpVtbl -> SetReceiveSelectionCallbacks(This,fGetCallbacks) ) 

#define IWMReaderAdvanced6_GetReceiveSelectionCallbacks(This,pfGetCallbacks)	\
    ( (This)->lpVtbl -> GetReceiveSelectionCallbacks(This,pfGetCallbacks) ) 

#define IWMReaderAdvanced6_SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples)	\
    ( (This)->lpVtbl -> SetReceiveStreamSamples(This,wStreamNum,fReceiveStreamSamples) ) 

#define IWMReaderAdvanced6_GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples)	\
    ( (This)->lpVtbl -> GetReceiveStreamSamples(This,wStreamNum,pfReceiveStreamSamples) ) 

#define IWMReaderAdvanced6_SetAllocateForOutput(This,dwOutputNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForOutput(This,dwOutputNum,fAllocate) ) 

#define IWMReaderAdvanced6_GetAllocateForOutput(This,dwOutputNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForOutput(This,dwOutputNum,pfAllocate) ) 

#define IWMReaderAdvanced6_SetAllocateForStream(This,wStreamNum,fAllocate)	\
    ( (This)->lpVtbl -> SetAllocateForStream(This,wStreamNum,fAllocate) ) 

#define IWMReaderAdvanced6_GetAllocateForStream(This,dwSreamNum,pfAllocate)	\
    ( (This)->lpVtbl -> GetAllocateForStream(This,dwSreamNum,pfAllocate) ) 

#define IWMReaderAdvanced6_GetStatistics(This,pStatistics)	\
    ( (This)->lpVtbl -> GetStatistics(This,pStatistics) ) 

#define IWMReaderAdvanced6_SetClientInfo(This,pClientInfo)	\
    ( (This)->lpVtbl -> SetClientInfo(This,pClientInfo) ) 

#define IWMReaderAdvanced6_GetMaxOutputSampleSize(This,dwOutput,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxOutputSampleSize(This,dwOutput,pcbMax) ) 

#define IWMReaderAdvanced6_GetMaxStreamSampleSize(This,wStream,pcbMax)	\
    ( (This)->lpVtbl -> GetMaxStreamSampleSize(This,wStream,pcbMax) ) 

#define IWMReaderAdvanced6_NotifyLateDelivery(This,cnsLateness)	\
    ( (This)->lpVtbl -> NotifyLateDelivery(This,cnsLateness) ) 


#define IWMReaderAdvanced6_SetPlayMode(This,Mode)	\
    ( (This)->lpVtbl -> SetPlayMode(This,Mode) ) 

#define IWMReaderAdvanced6_GetPlayMode(This,pMode)	\
    ( (This)->lpVtbl -> GetPlayMode(This,pMode) ) 

#define IWMReaderAdvanced6_GetBufferProgress(This,pdwPercent,pcnsBuffering)	\
    ( (This)->lpVtbl -> GetBufferProgress(This,pdwPercent,pcnsBuffering) ) 

#define IWMReaderAdvanced6_GetDownloadProgress(This,pdwPercent,pqwBytesDownloaded,pcnsDownload)	\
    ( (This)->lpVtbl -> GetDownloadProgress(This,pdwPercent,pqwBytesDownloaded,pcnsDownload) ) 

#define IWMReaderAdvanced6_GetSaveAsProgress(This,pdwPercent)	\
    ( (This)->lpVtbl -> GetSaveAsProgress(This,pdwPercent) ) 

#define IWMReaderAdvanced6_SaveFileAs(This,pwszFilename)	\
    ( (This)->lpVtbl -> SaveFileAs(This,pwszFilename) ) 

#define IWMReaderAdvanced6_GetProtocolName(This,pwszProtocol,pcchProtocol)	\
    ( (This)->lpVtbl -> GetProtocolName(This,pwszProtocol,pcchProtocol) ) 

#define IWMReaderAdvanced6_StartAtMarker(This,wMarkerIndex,cnsDuration,fRate,pvContext)	\
    ( (This)->lpVtbl -> StartAtMarker(This,wMarkerIndex,cnsDuration,fRate,pvContext) ) 

#define IWMReaderAdvanced6_GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetOutputSetting(This,dwOutputNum,pszName,pType,pValue,pcbLength) ) 

#define IWMReaderAdvanced6_SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetOutputSetting(This,dwOutputNum,pszName,Type,pValue,cbLength) ) 

#define IWMReaderAdvanced6_Preroll(This,cnsStart,cnsDuration,fRate)	\
    ( (This)->lpVtbl -> Preroll(This,cnsStart,cnsDuration,fRate) ) 

#define IWMReaderAdvanced6_SetLogClientID(This,fLogClientID)	\
    ( (This)->lpVtbl -> SetLogClientID(This,fLogClientID) ) 

#define IWMReaderAdvanced6_GetLogClientID(This,pfLogClientID)	\
    ( (This)->lpVtbl -> GetLogClientID(This,pfLogClientID) ) 

#define IWMReaderAdvanced6_StopBuffering(This)	\
    ( (This)->lpVtbl -> StopBuffering(This) ) 

#define IWMReaderAdvanced6_OpenStream(This,pStream,pCallback,pvContext)	\
    ( (This)->lpVtbl -> OpenStream(This,pStream,pCallback,pvContext) ) 


#define IWMReaderAdvanced6_StopNetStreaming(This)	\
    ( (This)->lpVtbl -> StopNetStreaming(This) ) 

#define IWMReaderAdvanced6_StartAtPosition(This,wStreamNum,pvOffsetStart,pvDuration,dwOffsetFormat,fRate,pvContext)	\
    ( (This)->lpVtbl -> StartAtPosition(This,wStreamNum,pvOffsetStart,pvDuration,dwOffsetFormat,fRate,pvContext) ) 


#define IWMReaderAdvanced6_GetLanguageCount(This,dwOutputNum,pwLanguageCount)	\
    ( (This)->lpVtbl -> GetLanguageCount(This,dwOutputNum,pwLanguageCount) ) 

#define IWMReaderAdvanced6_GetLanguage(This,dwOutputNum,wLanguage,pwszLanguageString,pcchLanguageStringLength)	\
    ( (This)->lpVtbl -> GetLanguage(This,dwOutputNum,wLanguage,pwszLanguageString,pcchLanguageStringLength) ) 

#define IWMReaderAdvanced6_GetMaxSpeedFactor(This,pdblFactor)	\
    ( (This)->lpVtbl -> GetMaxSpeedFactor(This,pdblFactor) ) 

#define IWMReaderAdvanced6_IsUsingFastCache(This,pfUsingFastCache)	\
    ( (This)->lpVtbl -> IsUsingFastCache(This,pfUsingFastCache) ) 

#define IWMReaderAdvanced6_AddLogParam(This,wszNameSpace,wszName,wszValue)	\
    ( (This)->lpVtbl -> AddLogParam(This,wszNameSpace,wszName,wszValue) ) 

#define IWMReaderAdvanced6_SendLogParams(This)	\
    ( (This)->lpVtbl -> SendLogParams(This) ) 

#define IWMReaderAdvanced6_CanSaveFileAs(This,pfCanSave)	\
    ( (This)->lpVtbl -> CanSaveFileAs(This,pfCanSave) ) 

#define IWMReaderAdvanced6_CancelSaveFileAs(This)	\
    ( (This)->lpVtbl -> CancelSaveFileAs(This) ) 

#define IWMReaderAdvanced6_GetURL(This,pwszURL,pcchURL)	\
    ( (This)->lpVtbl -> GetURL(This,pwszURL,pcchURL) ) 


#define IWMReaderAdvanced6_SetPlayerHook(This,dwOutputNum,pHook)	\
    ( (This)->lpVtbl -> SetPlayerHook(This,dwOutputNum,pHook) ) 


#define IWMReaderAdvanced6_SetProtectStreamSamples(This,pbCertificate,cbCertificate,dwCertificateType,dwFlags,pbInitializationVector,pcbInitializationVector)	\
    ( (This)->lpVtbl -> SetProtectStreamSamples(This,pbCertificate,cbCertificate,dwCertificateType,dwFlags,pbInitializationVector,pcbInitializationVector) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderAdvanced6_INTERFACE_DEFINED__ */


#ifndef __IWMPlayerHook_INTERFACE_DEFINED__
#define __IWMPlayerHook_INTERFACE_DEFINED__

/* interface IWMPlayerHook */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMPlayerHook;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e5b7ca9a-0f1c-4f66-9002-74ec50d8b304")
    IWMPlayerHook : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PreDecode( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMPlayerHookVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMPlayerHook * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMPlayerHook * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMPlayerHook * This);
        
        DECLSPEC_XFGVIRT(IWMPlayerHook, PreDecode)
        HRESULT ( STDMETHODCALLTYPE *PreDecode )( 
            IWMPlayerHook * This);
        
        END_INTERFACE
    } IWMPlayerHookVtbl;

    interface IWMPlayerHook
    {
        CONST_VTBL struct IWMPlayerHookVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMPlayerHook_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMPlayerHook_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMPlayerHook_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMPlayerHook_PreDecode(This)	\
    ( (This)->lpVtbl -> PreDecode(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMPlayerHook_INTERFACE_DEFINED__ */


#ifndef __IWMReaderAllocatorEx_INTERFACE_DEFINED__
#define __IWMReaderAllocatorEx_INTERFACE_DEFINED__

/* interface IWMReaderAllocatorEx */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderAllocatorEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9F762FA7-A22E-428d-93C9-AC82F3AAFE5A")
    IWMReaderAllocatorEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AllocateForStreamEx( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  DWORD cbBuffer,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocateForOutputEx( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  DWORD cbBuffer,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderAllocatorExVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderAllocatorEx * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderAllocatorEx * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderAllocatorEx * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAllocatorEx, AllocateForStreamEx)
        HRESULT ( STDMETHODCALLTYPE *AllocateForStreamEx )( 
            IWMReaderAllocatorEx * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  DWORD cbBuffer,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderAllocatorEx, AllocateForOutputEx)
        HRESULT ( STDMETHODCALLTYPE *AllocateForOutputEx )( 
            IWMReaderAllocatorEx * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  DWORD cbBuffer,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        END_INTERFACE
    } IWMReaderAllocatorExVtbl;

    interface IWMReaderAllocatorEx
    {
        CONST_VTBL struct IWMReaderAllocatorExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderAllocatorEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderAllocatorEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderAllocatorEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderAllocatorEx_AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    ( (This)->lpVtbl -> AllocateForStreamEx(This,wStreamNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext) ) 

#define IWMReaderAllocatorEx_AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext)	\
    ( (This)->lpVtbl -> AllocateForOutputEx(This,dwOutputNum,cbBuffer,ppBuffer,dwFlags,cnsSampleTime,cnsSampleDuration,pvContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderAllocatorEx_INTERFACE_DEFINED__ */


#ifndef __IWMReaderTypeNegotiation_INTERFACE_DEFINED__
#define __IWMReaderTypeNegotiation_INTERFACE_DEFINED__

/* interface IWMReaderTypeNegotiation */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderTypeNegotiation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FDBE5592-81A1-41ea-93BD-735CAD1ADC05")
    IWMReaderTypeNegotiation : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE TryOutputProps( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMOutputMediaProps *pOutput) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderTypeNegotiationVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderTypeNegotiation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderTypeNegotiation * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderTypeNegotiation * This);
        
        DECLSPEC_XFGVIRT(IWMReaderTypeNegotiation, TryOutputProps)
        HRESULT ( STDMETHODCALLTYPE *TryOutputProps )( 
            IWMReaderTypeNegotiation * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  IWMOutputMediaProps *pOutput);
        
        END_INTERFACE
    } IWMReaderTypeNegotiationVtbl;

    interface IWMReaderTypeNegotiation
    {
        CONST_VTBL struct IWMReaderTypeNegotiationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderTypeNegotiation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderTypeNegotiation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderTypeNegotiation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderTypeNegotiation_TryOutputProps(This,dwOutputNum,pOutput)	\
    ( (This)->lpVtbl -> TryOutputProps(This,dwOutputNum,pOutput) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderTypeNegotiation_INTERFACE_DEFINED__ */


#ifndef __IWMReaderCallbackAdvanced_INTERFACE_DEFINED__
#define __IWMReaderCallbackAdvanced_INTERFACE_DEFINED__

/* interface IWMReaderCallbackAdvanced */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderCallbackAdvanced;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BEB-2B2B-11d3-B36B-00C04F6108FF")
    IWMReaderCallbackAdvanced : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnStreamSample( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTime( 
            /* [annotation][in] */ 
            _In_  QWORD cnsCurrentTime,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnStreamSelection( 
            /* [annotation][in] */ 
            _In_  WORD wStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnOutputPropsChanged( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  WM_MEDIA_TYPE *pMediaType,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocateForStream( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  DWORD cbBuffer,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocateForOutput( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  DWORD cbBuffer,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderCallbackAdvancedVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderCallbackAdvanced * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderCallbackAdvanced * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderCallbackAdvanced * This);
        
        DECLSPEC_XFGVIRT(IWMReaderCallbackAdvanced, OnStreamSample)
        HRESULT ( STDMETHODCALLTYPE *OnStreamSample )( 
            IWMReaderCallbackAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsSampleDuration,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pSample,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderCallbackAdvanced, OnTime)
        HRESULT ( STDMETHODCALLTYPE *OnTime )( 
            IWMReaderCallbackAdvanced * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsCurrentTime,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderCallbackAdvanced, OnStreamSelection)
        HRESULT ( STDMETHODCALLTYPE *OnStreamSelection )( 
            IWMReaderCallbackAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamCount,
            /* [annotation][in] */ 
            _In_  WORD *pStreamNumbers,
            /* [annotation][in] */ 
            _In_  WMT_STREAM_SELECTION *pSelections,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderCallbackAdvanced, OnOutputPropsChanged)
        HRESULT ( STDMETHODCALLTYPE *OnOutputPropsChanged )( 
            IWMReaderCallbackAdvanced * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  WM_MEDIA_TYPE *pMediaType,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderCallbackAdvanced, AllocateForStream)
        HRESULT ( STDMETHODCALLTYPE *AllocateForStream )( 
            IWMReaderCallbackAdvanced * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  DWORD cbBuffer,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderCallbackAdvanced, AllocateForOutput)
        HRESULT ( STDMETHODCALLTYPE *AllocateForOutput )( 
            IWMReaderCallbackAdvanced * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  DWORD cbBuffer,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppBuffer,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        END_INTERFACE
    } IWMReaderCallbackAdvancedVtbl;

    interface IWMReaderCallbackAdvanced
    {
        CONST_VTBL struct IWMReaderCallbackAdvancedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderCallbackAdvanced_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderCallbackAdvanced_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderCallbackAdvanced_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderCallbackAdvanced_OnStreamSample(This,wStreamNum,cnsSampleTime,cnsSampleDuration,dwFlags,pSample,pvContext)	\
    ( (This)->lpVtbl -> OnStreamSample(This,wStreamNum,cnsSampleTime,cnsSampleDuration,dwFlags,pSample,pvContext) ) 

#define IWMReaderCallbackAdvanced_OnTime(This,cnsCurrentTime,pvContext)	\
    ( (This)->lpVtbl -> OnTime(This,cnsCurrentTime,pvContext) ) 

#define IWMReaderCallbackAdvanced_OnStreamSelection(This,wStreamCount,pStreamNumbers,pSelections,pvContext)	\
    ( (This)->lpVtbl -> OnStreamSelection(This,wStreamCount,pStreamNumbers,pSelections,pvContext) ) 

#define IWMReaderCallbackAdvanced_OnOutputPropsChanged(This,dwOutputNum,pMediaType,pvContext)	\
    ( (This)->lpVtbl -> OnOutputPropsChanged(This,dwOutputNum,pMediaType,pvContext) ) 

#define IWMReaderCallbackAdvanced_AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext)	\
    ( (This)->lpVtbl -> AllocateForStream(This,wStreamNum,cbBuffer,ppBuffer,pvContext) ) 

#define IWMReaderCallbackAdvanced_AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext)	\
    ( (This)->lpVtbl -> AllocateForOutput(This,dwOutputNum,cbBuffer,ppBuffer,pvContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderCallbackAdvanced_INTERFACE_DEFINED__ */


#ifndef __IWMDRMReader_INTERFACE_DEFINED__
#define __IWMDRMReader_INTERFACE_DEFINED__

/* interface IWMDRMReader */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDRMReader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D2827540-3EE7-432c-B14C-DC17F085D3B3")
    IWMDRMReader : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AcquireLicense( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelLicenseAcquisition( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Individualize( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelIndividualization( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MonitorLicenseAcquisition( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelMonitorLicenseAcquisition( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDRMProperty( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwstrName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE dwType,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDRMProperty( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwstrName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pdwType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDRMReaderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDRMReader * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDRMReader * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDRMReader * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, AcquireLicense)
        HRESULT ( STDMETHODCALLTYPE *AcquireLicense )( 
            IWMDRMReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, CancelLicenseAcquisition)
        HRESULT ( STDMETHODCALLTYPE *CancelLicenseAcquisition )( 
            IWMDRMReader * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, Individualize)
        HRESULT ( STDMETHODCALLTYPE *Individualize )( 
            IWMDRMReader * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, CancelIndividualization)
        HRESULT ( STDMETHODCALLTYPE *CancelIndividualization )( 
            IWMDRMReader * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, MonitorLicenseAcquisition)
        HRESULT ( STDMETHODCALLTYPE *MonitorLicenseAcquisition )( 
            IWMDRMReader * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, CancelMonitorLicenseAcquisition)
        HRESULT ( STDMETHODCALLTYPE *CancelMonitorLicenseAcquisition )( 
            IWMDRMReader * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, SetDRMProperty)
        HRESULT ( STDMETHODCALLTYPE *SetDRMProperty )( 
            IWMDRMReader * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwstrName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE dwType,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, GetDRMProperty)
        HRESULT ( STDMETHODCALLTYPE *GetDRMProperty )( 
            IWMDRMReader * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwstrName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pdwType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        END_INTERFACE
    } IWMDRMReaderVtbl;

    interface IWMDRMReader
    {
        CONST_VTBL struct IWMDRMReaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDRMReader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDRMReader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDRMReader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDRMReader_AcquireLicense(This,dwFlags)	\
    ( (This)->lpVtbl -> AcquireLicense(This,dwFlags) ) 

#define IWMDRMReader_CancelLicenseAcquisition(This)	\
    ( (This)->lpVtbl -> CancelLicenseAcquisition(This) ) 

#define IWMDRMReader_Individualize(This,dwFlags)	\
    ( (This)->lpVtbl -> Individualize(This,dwFlags) ) 

#define IWMDRMReader_CancelIndividualization(This)	\
    ( (This)->lpVtbl -> CancelIndividualization(This) ) 

#define IWMDRMReader_MonitorLicenseAcquisition(This)	\
    ( (This)->lpVtbl -> MonitorLicenseAcquisition(This) ) 

#define IWMDRMReader_CancelMonitorLicenseAcquisition(This)	\
    ( (This)->lpVtbl -> CancelMonitorLicenseAcquisition(This) ) 

#define IWMDRMReader_SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetDRMProperty(This,pwstrName,dwType,pValue,cbLength) ) 

#define IWMDRMReader_GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDRMReader_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_wmsdkidl_0000_0063 */
/* [local] */ 

#ifndef DRM_OPL_TYPES
#define DRM_OPL_TYPES 1
typedef struct __tagDRM_MINIMUM_OUTPUT_PROTECTION_LEVELS
    {
    WORD wCompressedDigitalVideo;
    WORD wUncompressedDigitalVideo;
    WORD wAnalogVideo;
    WORD wCompressedDigitalAudio;
    WORD wUncompressedDigitalAudio;
    } 	DRM_MINIMUM_OUTPUT_PROTECTION_LEVELS;

typedef struct __tagDRM_OPL_OUTPUT_IDS
    {
    WORD cIds;
    GUID *rgIds;
    } 	DRM_OPL_OUTPUT_IDS;

typedef struct __tagDRM_OUTPUT_PROTECTION
    {
    GUID guidId;
    BYTE bConfigData;
    } 	DRM_OUTPUT_PROTECTION;

typedef DRM_OUTPUT_PROTECTION DRM_VIDEO_OUTPUT_PROTECTION;

typedef struct __tagDRM_VIDEO_OUTPUT_PROTECTION_IDS
    {
    WORD cEntries;
    DRM_VIDEO_OUTPUT_PROTECTION *rgVop;
    } 	DRM_VIDEO_OUTPUT_PROTECTION_IDS;

typedef struct __tagDRM_PLAY_OPL
    {
    DRM_MINIMUM_OUTPUT_PROTECTION_LEVELS minOPL;
    DRM_OPL_OUTPUT_IDS oplIdReserved;
    DRM_VIDEO_OUTPUT_PROTECTION_IDS vopi;
    } 	DRM_PLAY_OPL;

typedef struct __tagDRM_COPY_OPL
    {
    WORD wMinimumCopyLevel;
    DRM_OPL_OUTPUT_IDS oplIdIncludes;
    DRM_OPL_OUTPUT_IDS oplIdExcludes;
    } 	DRM_COPY_OPL;

#endif // DRM_OPL_TYPES


extern RPC_IF_HANDLE __MIDL_itf_wmsdkidl_0000_0063_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wmsdkidl_0000_0063_v0_0_s_ifspec;

#ifndef __IWMDRMReader2_INTERFACE_DEFINED__
#define __IWMDRMReader2_INTERFACE_DEFINED__

/* interface IWMDRMReader2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDRMReader2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("befe7a75-9f1d-4075-b9d9-a3c37bda49a0")
    IWMDRMReader2 : public IWMDRMReader
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetEvaluateOutputLevelLicenses( 
            /* [annotation][in] */ 
            _In_  BOOL fEvaluate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPlayOutputLevels( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  DRM_PLAY_OPL *pPlayOPL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbLength,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMinAppComplianceLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCopyOutputLevels( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  DRM_COPY_OPL *pCopyOPL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbLength,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMinAppComplianceLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TryNextLicense( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDRMReader2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDRMReader2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDRMReader2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDRMReader2 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, AcquireLicense)
        HRESULT ( STDMETHODCALLTYPE *AcquireLicense )( 
            IWMDRMReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, CancelLicenseAcquisition)
        HRESULT ( STDMETHODCALLTYPE *CancelLicenseAcquisition )( 
            IWMDRMReader2 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, Individualize)
        HRESULT ( STDMETHODCALLTYPE *Individualize )( 
            IWMDRMReader2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, CancelIndividualization)
        HRESULT ( STDMETHODCALLTYPE *CancelIndividualization )( 
            IWMDRMReader2 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, MonitorLicenseAcquisition)
        HRESULT ( STDMETHODCALLTYPE *MonitorLicenseAcquisition )( 
            IWMDRMReader2 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, CancelMonitorLicenseAcquisition)
        HRESULT ( STDMETHODCALLTYPE *CancelMonitorLicenseAcquisition )( 
            IWMDRMReader2 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, SetDRMProperty)
        HRESULT ( STDMETHODCALLTYPE *SetDRMProperty )( 
            IWMDRMReader2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwstrName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE dwType,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, GetDRMProperty)
        HRESULT ( STDMETHODCALLTYPE *GetDRMProperty )( 
            IWMDRMReader2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwstrName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pdwType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMDRMReader2, SetEvaluateOutputLevelLicenses)
        HRESULT ( STDMETHODCALLTYPE *SetEvaluateOutputLevelLicenses )( 
            IWMDRMReader2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fEvaluate);
        
        DECLSPEC_XFGVIRT(IWMDRMReader2, GetPlayOutputLevels)
        HRESULT ( STDMETHODCALLTYPE *GetPlayOutputLevels )( 
            IWMDRMReader2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  DRM_PLAY_OPL *pPlayOPL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbLength,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMinAppComplianceLevel);
        
        DECLSPEC_XFGVIRT(IWMDRMReader2, GetCopyOutputLevels)
        HRESULT ( STDMETHODCALLTYPE *GetCopyOutputLevels )( 
            IWMDRMReader2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  DRM_COPY_OPL *pCopyOPL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbLength,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMinAppComplianceLevel);
        
        DECLSPEC_XFGVIRT(IWMDRMReader2, TryNextLicense)
        HRESULT ( STDMETHODCALLTYPE *TryNextLicense )( 
            IWMDRMReader2 * This);
        
        END_INTERFACE
    } IWMDRMReader2Vtbl;

    interface IWMDRMReader2
    {
        CONST_VTBL struct IWMDRMReader2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDRMReader2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDRMReader2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDRMReader2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDRMReader2_AcquireLicense(This,dwFlags)	\
    ( (This)->lpVtbl -> AcquireLicense(This,dwFlags) ) 

#define IWMDRMReader2_CancelLicenseAcquisition(This)	\
    ( (This)->lpVtbl -> CancelLicenseAcquisition(This) ) 

#define IWMDRMReader2_Individualize(This,dwFlags)	\
    ( (This)->lpVtbl -> Individualize(This,dwFlags) ) 

#define IWMDRMReader2_CancelIndividualization(This)	\
    ( (This)->lpVtbl -> CancelIndividualization(This) ) 

#define IWMDRMReader2_MonitorLicenseAcquisition(This)	\
    ( (This)->lpVtbl -> MonitorLicenseAcquisition(This) ) 

#define IWMDRMReader2_CancelMonitorLicenseAcquisition(This)	\
    ( (This)->lpVtbl -> CancelMonitorLicenseAcquisition(This) ) 

#define IWMDRMReader2_SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetDRMProperty(This,pwstrName,dwType,pValue,cbLength) ) 

#define IWMDRMReader2_GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength) ) 


#define IWMDRMReader2_SetEvaluateOutputLevelLicenses(This,fEvaluate)	\
    ( (This)->lpVtbl -> SetEvaluateOutputLevelLicenses(This,fEvaluate) ) 

#define IWMDRMReader2_GetPlayOutputLevels(This,pPlayOPL,pcbLength,pdwMinAppComplianceLevel)	\
    ( (This)->lpVtbl -> GetPlayOutputLevels(This,pPlayOPL,pcbLength,pdwMinAppComplianceLevel) ) 

#define IWMDRMReader2_GetCopyOutputLevels(This,pCopyOPL,pcbLength,pdwMinAppComplianceLevel)	\
    ( (This)->lpVtbl -> GetCopyOutputLevels(This,pCopyOPL,pcbLength,pdwMinAppComplianceLevel) ) 

#define IWMDRMReader2_TryNextLicense(This)	\
    ( (This)->lpVtbl -> TryNextLicense(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDRMReader2_INTERFACE_DEFINED__ */


#ifndef __IWMDRMReader3_INTERFACE_DEFINED__
#define __IWMDRMReader3_INTERFACE_DEFINED__

/* interface IWMDRMReader3 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDRMReader3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e08672de-f1e7-4ff4-a0a3-fc4b08e4caf8")
    IWMDRMReader3 : public IWMDRMReader2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInclusionList( 
            /* [annotation][out] */ 
            _Out_  GUID **ppGuids,
            /* [annotation][out] */ 
            _Out_  DWORD *pcGuids) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDRMReader3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDRMReader3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDRMReader3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDRMReader3 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, AcquireLicense)
        HRESULT ( STDMETHODCALLTYPE *AcquireLicense )( 
            IWMDRMReader3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, CancelLicenseAcquisition)
        HRESULT ( STDMETHODCALLTYPE *CancelLicenseAcquisition )( 
            IWMDRMReader3 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, Individualize)
        HRESULT ( STDMETHODCALLTYPE *Individualize )( 
            IWMDRMReader3 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, CancelIndividualization)
        HRESULT ( STDMETHODCALLTYPE *CancelIndividualization )( 
            IWMDRMReader3 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, MonitorLicenseAcquisition)
        HRESULT ( STDMETHODCALLTYPE *MonitorLicenseAcquisition )( 
            IWMDRMReader3 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, CancelMonitorLicenseAcquisition)
        HRESULT ( STDMETHODCALLTYPE *CancelMonitorLicenseAcquisition )( 
            IWMDRMReader3 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, SetDRMProperty)
        HRESULT ( STDMETHODCALLTYPE *SetDRMProperty )( 
            IWMDRMReader3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwstrName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE dwType,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMDRMReader, GetDRMProperty)
        HRESULT ( STDMETHODCALLTYPE *GetDRMProperty )( 
            IWMDRMReader3 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwstrName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pdwType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMDRMReader2, SetEvaluateOutputLevelLicenses)
        HRESULT ( STDMETHODCALLTYPE *SetEvaluateOutputLevelLicenses )( 
            IWMDRMReader3 * This,
            /* [annotation][in] */ 
            _In_  BOOL fEvaluate);
        
        DECLSPEC_XFGVIRT(IWMDRMReader2, GetPlayOutputLevels)
        HRESULT ( STDMETHODCALLTYPE *GetPlayOutputLevels )( 
            IWMDRMReader3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  DRM_PLAY_OPL *pPlayOPL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbLength,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMinAppComplianceLevel);
        
        DECLSPEC_XFGVIRT(IWMDRMReader2, GetCopyOutputLevels)
        HRESULT ( STDMETHODCALLTYPE *GetCopyOutputLevels )( 
            IWMDRMReader3 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  DRM_COPY_OPL *pCopyOPL,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbLength,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMinAppComplianceLevel);
        
        DECLSPEC_XFGVIRT(IWMDRMReader2, TryNextLicense)
        HRESULT ( STDMETHODCALLTYPE *TryNextLicense )( 
            IWMDRMReader3 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMReader3, GetInclusionList)
        HRESULT ( STDMETHODCALLTYPE *GetInclusionList )( 
            IWMDRMReader3 * This,
            /* [annotation][out] */ 
            _Out_  GUID **ppGuids,
            /* [annotation][out] */ 
            _Out_  DWORD *pcGuids);
        
        END_INTERFACE
    } IWMDRMReader3Vtbl;

    interface IWMDRMReader3
    {
        CONST_VTBL struct IWMDRMReader3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDRMReader3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDRMReader3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDRMReader3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDRMReader3_AcquireLicense(This,dwFlags)	\
    ( (This)->lpVtbl -> AcquireLicense(This,dwFlags) ) 

#define IWMDRMReader3_CancelLicenseAcquisition(This)	\
    ( (This)->lpVtbl -> CancelLicenseAcquisition(This) ) 

#define IWMDRMReader3_Individualize(This,dwFlags)	\
    ( (This)->lpVtbl -> Individualize(This,dwFlags) ) 

#define IWMDRMReader3_CancelIndividualization(This)	\
    ( (This)->lpVtbl -> CancelIndividualization(This) ) 

#define IWMDRMReader3_MonitorLicenseAcquisition(This)	\
    ( (This)->lpVtbl -> MonitorLicenseAcquisition(This) ) 

#define IWMDRMReader3_CancelMonitorLicenseAcquisition(This)	\
    ( (This)->lpVtbl -> CancelMonitorLicenseAcquisition(This) ) 

#define IWMDRMReader3_SetDRMProperty(This,pwstrName,dwType,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetDRMProperty(This,pwstrName,dwType,pValue,cbLength) ) 

#define IWMDRMReader3_GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetDRMProperty(This,pwstrName,pdwType,pValue,pcbLength) ) 


#define IWMDRMReader3_SetEvaluateOutputLevelLicenses(This,fEvaluate)	\
    ( (This)->lpVtbl -> SetEvaluateOutputLevelLicenses(This,fEvaluate) ) 

#define IWMDRMReader3_GetPlayOutputLevels(This,pPlayOPL,pcbLength,pdwMinAppComplianceLevel)	\
    ( (This)->lpVtbl -> GetPlayOutputLevels(This,pPlayOPL,pcbLength,pdwMinAppComplianceLevel) ) 

#define IWMDRMReader3_GetCopyOutputLevels(This,pCopyOPL,pcbLength,pdwMinAppComplianceLevel)	\
    ( (This)->lpVtbl -> GetCopyOutputLevels(This,pCopyOPL,pcbLength,pdwMinAppComplianceLevel) ) 

#define IWMDRMReader3_TryNextLicense(This)	\
    ( (This)->lpVtbl -> TryNextLicense(This) ) 


#define IWMDRMReader3_GetInclusionList(This,ppGuids,pcGuids)	\
    ( (This)->lpVtbl -> GetInclusionList(This,ppGuids,pcGuids) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDRMReader3_INTERFACE_DEFINED__ */


#ifndef __IWMReaderPlaylistBurn_INTERFACE_DEFINED__
#define __IWMReaderPlaylistBurn_INTERFACE_DEFINED__

/* interface IWMReaderPlaylistBurn */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderPlaylistBurn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f28c0300-9baa-4477-a846-1744d9cbf533")
    IWMReaderPlaylistBurn : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitPlaylistBurn( 
            /* [annotation][in] */ 
            _In_  DWORD cFiles,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE *ppwszFilenames,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInitResults( 
            /* [annotation][in] */ 
            _In_  DWORD cFiles,
            /* [annotation][out] */ 
            _Out_  HRESULT *phrStati) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndPlaylistBurn( 
            /* [annotation][in] */ 
            _In_  HRESULT hrBurnResult) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderPlaylistBurnVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderPlaylistBurn * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderPlaylistBurn * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderPlaylistBurn * This);
        
        DECLSPEC_XFGVIRT(IWMReaderPlaylistBurn, InitPlaylistBurn)
        HRESULT ( STDMETHODCALLTYPE *InitPlaylistBurn )( 
            IWMReaderPlaylistBurn * This,
            /* [annotation][in] */ 
            _In_  DWORD cFiles,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE *ppwszFilenames,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMReaderPlaylistBurn, GetInitResults)
        HRESULT ( STDMETHODCALLTYPE *GetInitResults )( 
            IWMReaderPlaylistBurn * This,
            /* [annotation][in] */ 
            _In_  DWORD cFiles,
            /* [annotation][out] */ 
            _Out_  HRESULT *phrStati);
        
        DECLSPEC_XFGVIRT(IWMReaderPlaylistBurn, Cancel)
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IWMReaderPlaylistBurn * This);
        
        DECLSPEC_XFGVIRT(IWMReaderPlaylistBurn, EndPlaylistBurn)
        HRESULT ( STDMETHODCALLTYPE *EndPlaylistBurn )( 
            IWMReaderPlaylistBurn * This,
            /* [annotation][in] */ 
            _In_  HRESULT hrBurnResult);
        
        END_INTERFACE
    } IWMReaderPlaylistBurnVtbl;

    interface IWMReaderPlaylistBurn
    {
        CONST_VTBL struct IWMReaderPlaylistBurnVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderPlaylistBurn_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderPlaylistBurn_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderPlaylistBurn_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderPlaylistBurn_InitPlaylistBurn(This,cFiles,ppwszFilenames,pCallback,pvContext)	\
    ( (This)->lpVtbl -> InitPlaylistBurn(This,cFiles,ppwszFilenames,pCallback,pvContext) ) 

#define IWMReaderPlaylistBurn_GetInitResults(This,cFiles,phrStati)	\
    ( (This)->lpVtbl -> GetInitResults(This,cFiles,phrStati) ) 

#define IWMReaderPlaylistBurn_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IWMReaderPlaylistBurn_EndPlaylistBurn(This,hrBurnResult)	\
    ( (This)->lpVtbl -> EndPlaylistBurn(This,hrBurnResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderPlaylistBurn_INTERFACE_DEFINED__ */


#ifndef __IWMReaderNetworkConfig_INTERFACE_DEFINED__
#define __IWMReaderNetworkConfig_INTERFACE_DEFINED__

/* interface IWMReaderNetworkConfig */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderNetworkConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BEC-2B2B-11d3-B36B-00C04F6108FF")
    IWMReaderNetworkConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBufferingTime( 
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsBufferingTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferingTime( 
            /* [annotation][in] */ 
            _In_  QWORD cnsBufferingTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUDPPortRanges( 
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcRanges)  WM_PORT_NUMBER_RANGE *pRangeArray,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcRanges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUDPPortRanges( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cRanges)  WM_PORT_NUMBER_RANGE *pRangeArray,
            /* [annotation][in] */ 
            _In_  DWORD cRanges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProxySettings( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][out] */ 
            _Out_  WMT_PROXY_SETTINGS *pProxySetting) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProxySettings( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  WMT_PROXY_SETTINGS ProxySetting) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProxyHostName( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchHostName)  WCHAR *pwszHostName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchHostName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProxyHostName( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszHostName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProxyPort( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPort) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProxyPort( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  DWORD dwPort) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProxyExceptionList( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchExceptionList)  WCHAR *pwszExceptionList,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchExceptionList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProxyExceptionList( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszExceptionList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProxyBypassForLocal( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][out] */ 
            _Out_  BOOL *pfBypassForLocal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProxyBypassForLocal( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  BOOL fBypassForLocal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetForceRerunAutoProxyDetection( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfForceRerunDetection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetForceRerunAutoProxyDetection( 
            /* [annotation][in] */ 
            _In_  BOOL fForceRerunDetection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnableMulticast( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableMulticast) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnableMulticast( 
            /* [annotation][in] */ 
            _In_  BOOL fEnableMulticast) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnableHTTP( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableHTTP) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnableHTTP( 
            /* [annotation][in] */ 
            _In_  BOOL fEnableHTTP) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnableUDP( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableUDP) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnableUDP( 
            /* [annotation][in] */ 
            _In_  BOOL fEnableUDP) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnableTCP( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableTCP) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnableTCP( 
            /* [annotation][in] */ 
            _In_  BOOL fEnableTCP) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetProtocolRollover( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConnectionBandwidth( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConnectionBandwidth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConnectionBandwidth( 
            /* [annotation][in] */ 
            _In_  DWORD dwConnectionBandwidth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumProtocolsSupported( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcProtocols) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedProtocolName( 
            /* [annotation][in] */ 
            _In_  DWORD dwProtocolNum,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchProtocolName)  WCHAR *pwszProtocolName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchProtocolName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddLoggingUrl( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLoggingUrl( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchUrl)  LPWSTR pwszUrl,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLoggingUrlCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwUrlCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetLoggingUrlList( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderNetworkConfigVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderNetworkConfig * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderNetworkConfig * This);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetBufferingTime)
        HRESULT ( STDMETHODCALLTYPE *GetBufferingTime )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsBufferingTime);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetBufferingTime)
        HRESULT ( STDMETHODCALLTYPE *SetBufferingTime )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsBufferingTime);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetUDPPortRanges)
        HRESULT ( STDMETHODCALLTYPE *GetUDPPortRanges )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcRanges)  WM_PORT_NUMBER_RANGE *pRangeArray,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcRanges);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetUDPPortRanges)
        HRESULT ( STDMETHODCALLTYPE *SetUDPPortRanges )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cRanges)  WM_PORT_NUMBER_RANGE *pRangeArray,
            /* [annotation][in] */ 
            _In_  DWORD cRanges);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetProxySettings)
        HRESULT ( STDMETHODCALLTYPE *GetProxySettings )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][out] */ 
            _Out_  WMT_PROXY_SETTINGS *pProxySetting);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetProxySettings)
        HRESULT ( STDMETHODCALLTYPE *SetProxySettings )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  WMT_PROXY_SETTINGS ProxySetting);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetProxyHostName)
        HRESULT ( STDMETHODCALLTYPE *GetProxyHostName )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchHostName)  WCHAR *pwszHostName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchHostName);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetProxyHostName)
        HRESULT ( STDMETHODCALLTYPE *SetProxyHostName )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszHostName);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetProxyPort)
        HRESULT ( STDMETHODCALLTYPE *GetProxyPort )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPort);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetProxyPort)
        HRESULT ( STDMETHODCALLTYPE *SetProxyPort )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  DWORD dwPort);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetProxyExceptionList)
        HRESULT ( STDMETHODCALLTYPE *GetProxyExceptionList )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchExceptionList)  WCHAR *pwszExceptionList,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchExceptionList);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetProxyExceptionList)
        HRESULT ( STDMETHODCALLTYPE *SetProxyExceptionList )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszExceptionList);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetProxyBypassForLocal)
        HRESULT ( STDMETHODCALLTYPE *GetProxyBypassForLocal )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][out] */ 
            _Out_  BOOL *pfBypassForLocal);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetProxyBypassForLocal)
        HRESULT ( STDMETHODCALLTYPE *SetProxyBypassForLocal )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  BOOL fBypassForLocal);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetForceRerunAutoProxyDetection)
        HRESULT ( STDMETHODCALLTYPE *GetForceRerunAutoProxyDetection )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfForceRerunDetection);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetForceRerunAutoProxyDetection)
        HRESULT ( STDMETHODCALLTYPE *SetForceRerunAutoProxyDetection )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  BOOL fForceRerunDetection);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetEnableMulticast)
        HRESULT ( STDMETHODCALLTYPE *GetEnableMulticast )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableMulticast);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetEnableMulticast)
        HRESULT ( STDMETHODCALLTYPE *SetEnableMulticast )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableMulticast);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetEnableHTTP)
        HRESULT ( STDMETHODCALLTYPE *GetEnableHTTP )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableHTTP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetEnableHTTP)
        HRESULT ( STDMETHODCALLTYPE *SetEnableHTTP )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableHTTP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetEnableUDP)
        HRESULT ( STDMETHODCALLTYPE *GetEnableUDP )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableUDP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetEnableUDP)
        HRESULT ( STDMETHODCALLTYPE *SetEnableUDP )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableUDP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetEnableTCP)
        HRESULT ( STDMETHODCALLTYPE *GetEnableTCP )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableTCP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetEnableTCP)
        HRESULT ( STDMETHODCALLTYPE *SetEnableTCP )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableTCP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, ResetProtocolRollover)
        HRESULT ( STDMETHODCALLTYPE *ResetProtocolRollover )( 
            IWMReaderNetworkConfig * This);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetConnectionBandwidth)
        HRESULT ( STDMETHODCALLTYPE *GetConnectionBandwidth )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConnectionBandwidth);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetConnectionBandwidth)
        HRESULT ( STDMETHODCALLTYPE *SetConnectionBandwidth )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  DWORD dwConnectionBandwidth);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetNumProtocolsSupported)
        HRESULT ( STDMETHODCALLTYPE *GetNumProtocolsSupported )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcProtocols);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetSupportedProtocolName)
        HRESULT ( STDMETHODCALLTYPE *GetSupportedProtocolName )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  DWORD dwProtocolNum,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchProtocolName)  WCHAR *pwszProtocolName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchProtocolName);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, AddLoggingUrl)
        HRESULT ( STDMETHODCALLTYPE *AddLoggingUrl )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszUrl);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetLoggingUrl)
        HRESULT ( STDMETHODCALLTYPE *GetLoggingUrl )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchUrl)  LPWSTR pwszUrl,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchUrl);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetLoggingUrlCount)
        HRESULT ( STDMETHODCALLTYPE *GetLoggingUrlCount )( 
            IWMReaderNetworkConfig * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwUrlCount);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, ResetLoggingUrlList)
        HRESULT ( STDMETHODCALLTYPE *ResetLoggingUrlList )( 
            IWMReaderNetworkConfig * This);
        
        END_INTERFACE
    } IWMReaderNetworkConfigVtbl;

    interface IWMReaderNetworkConfig
    {
        CONST_VTBL struct IWMReaderNetworkConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderNetworkConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderNetworkConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderNetworkConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderNetworkConfig_GetBufferingTime(This,pcnsBufferingTime)	\
    ( (This)->lpVtbl -> GetBufferingTime(This,pcnsBufferingTime) ) 

#define IWMReaderNetworkConfig_SetBufferingTime(This,cnsBufferingTime)	\
    ( (This)->lpVtbl -> SetBufferingTime(This,cnsBufferingTime) ) 

#define IWMReaderNetworkConfig_GetUDPPortRanges(This,pRangeArray,pcRanges)	\
    ( (This)->lpVtbl -> GetUDPPortRanges(This,pRangeArray,pcRanges) ) 

#define IWMReaderNetworkConfig_SetUDPPortRanges(This,pRangeArray,cRanges)	\
    ( (This)->lpVtbl -> SetUDPPortRanges(This,pRangeArray,cRanges) ) 

#define IWMReaderNetworkConfig_GetProxySettings(This,pwszProtocol,pProxySetting)	\
    ( (This)->lpVtbl -> GetProxySettings(This,pwszProtocol,pProxySetting) ) 

#define IWMReaderNetworkConfig_SetProxySettings(This,pwszProtocol,ProxySetting)	\
    ( (This)->lpVtbl -> SetProxySettings(This,pwszProtocol,ProxySetting) ) 

#define IWMReaderNetworkConfig_GetProxyHostName(This,pwszProtocol,pwszHostName,pcchHostName)	\
    ( (This)->lpVtbl -> GetProxyHostName(This,pwszProtocol,pwszHostName,pcchHostName) ) 

#define IWMReaderNetworkConfig_SetProxyHostName(This,pwszProtocol,pwszHostName)	\
    ( (This)->lpVtbl -> SetProxyHostName(This,pwszProtocol,pwszHostName) ) 

#define IWMReaderNetworkConfig_GetProxyPort(This,pwszProtocol,pdwPort)	\
    ( (This)->lpVtbl -> GetProxyPort(This,pwszProtocol,pdwPort) ) 

#define IWMReaderNetworkConfig_SetProxyPort(This,pwszProtocol,dwPort)	\
    ( (This)->lpVtbl -> SetProxyPort(This,pwszProtocol,dwPort) ) 

#define IWMReaderNetworkConfig_GetProxyExceptionList(This,pwszProtocol,pwszExceptionList,pcchExceptionList)	\
    ( (This)->lpVtbl -> GetProxyExceptionList(This,pwszProtocol,pwszExceptionList,pcchExceptionList) ) 

#define IWMReaderNetworkConfig_SetProxyExceptionList(This,pwszProtocol,pwszExceptionList)	\
    ( (This)->lpVtbl -> SetProxyExceptionList(This,pwszProtocol,pwszExceptionList) ) 

#define IWMReaderNetworkConfig_GetProxyBypassForLocal(This,pwszProtocol,pfBypassForLocal)	\
    ( (This)->lpVtbl -> GetProxyBypassForLocal(This,pwszProtocol,pfBypassForLocal) ) 

#define IWMReaderNetworkConfig_SetProxyBypassForLocal(This,pwszProtocol,fBypassForLocal)	\
    ( (This)->lpVtbl -> SetProxyBypassForLocal(This,pwszProtocol,fBypassForLocal) ) 

#define IWMReaderNetworkConfig_GetForceRerunAutoProxyDetection(This,pfForceRerunDetection)	\
    ( (This)->lpVtbl -> GetForceRerunAutoProxyDetection(This,pfForceRerunDetection) ) 

#define IWMReaderNetworkConfig_SetForceRerunAutoProxyDetection(This,fForceRerunDetection)	\
    ( (This)->lpVtbl -> SetForceRerunAutoProxyDetection(This,fForceRerunDetection) ) 

#define IWMReaderNetworkConfig_GetEnableMulticast(This,pfEnableMulticast)	\
    ( (This)->lpVtbl -> GetEnableMulticast(This,pfEnableMulticast) ) 

#define IWMReaderNetworkConfig_SetEnableMulticast(This,fEnableMulticast)	\
    ( (This)->lpVtbl -> SetEnableMulticast(This,fEnableMulticast) ) 

#define IWMReaderNetworkConfig_GetEnableHTTP(This,pfEnableHTTP)	\
    ( (This)->lpVtbl -> GetEnableHTTP(This,pfEnableHTTP) ) 

#define IWMReaderNetworkConfig_SetEnableHTTP(This,fEnableHTTP)	\
    ( (This)->lpVtbl -> SetEnableHTTP(This,fEnableHTTP) ) 

#define IWMReaderNetworkConfig_GetEnableUDP(This,pfEnableUDP)	\
    ( (This)->lpVtbl -> GetEnableUDP(This,pfEnableUDP) ) 

#define IWMReaderNetworkConfig_SetEnableUDP(This,fEnableUDP)	\
    ( (This)->lpVtbl -> SetEnableUDP(This,fEnableUDP) ) 

#define IWMReaderNetworkConfig_GetEnableTCP(This,pfEnableTCP)	\
    ( (This)->lpVtbl -> GetEnableTCP(This,pfEnableTCP) ) 

#define IWMReaderNetworkConfig_SetEnableTCP(This,fEnableTCP)	\
    ( (This)->lpVtbl -> SetEnableTCP(This,fEnableTCP) ) 

#define IWMReaderNetworkConfig_ResetProtocolRollover(This)	\
    ( (This)->lpVtbl -> ResetProtocolRollover(This) ) 

#define IWMReaderNetworkConfig_GetConnectionBandwidth(This,pdwConnectionBandwidth)	\
    ( (This)->lpVtbl -> GetConnectionBandwidth(This,pdwConnectionBandwidth) ) 

#define IWMReaderNetworkConfig_SetConnectionBandwidth(This,dwConnectionBandwidth)	\
    ( (This)->lpVtbl -> SetConnectionBandwidth(This,dwConnectionBandwidth) ) 

#define IWMReaderNetworkConfig_GetNumProtocolsSupported(This,pcProtocols)	\
    ( (This)->lpVtbl -> GetNumProtocolsSupported(This,pcProtocols) ) 

#define IWMReaderNetworkConfig_GetSupportedProtocolName(This,dwProtocolNum,pwszProtocolName,pcchProtocolName)	\
    ( (This)->lpVtbl -> GetSupportedProtocolName(This,dwProtocolNum,pwszProtocolName,pcchProtocolName) ) 

#define IWMReaderNetworkConfig_AddLoggingUrl(This,pwszUrl)	\
    ( (This)->lpVtbl -> AddLoggingUrl(This,pwszUrl) ) 

#define IWMReaderNetworkConfig_GetLoggingUrl(This,dwIndex,pwszUrl,pcchUrl)	\
    ( (This)->lpVtbl -> GetLoggingUrl(This,dwIndex,pwszUrl,pcchUrl) ) 

#define IWMReaderNetworkConfig_GetLoggingUrlCount(This,pdwUrlCount)	\
    ( (This)->lpVtbl -> GetLoggingUrlCount(This,pdwUrlCount) ) 

#define IWMReaderNetworkConfig_ResetLoggingUrlList(This)	\
    ( (This)->lpVtbl -> ResetLoggingUrlList(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderNetworkConfig_INTERFACE_DEFINED__ */


#ifndef __IWMReaderNetworkConfig2_INTERFACE_DEFINED__
#define __IWMReaderNetworkConfig2_INTERFACE_DEFINED__

/* interface IWMReaderNetworkConfig2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderNetworkConfig2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d979a853-042b-4050-8387-c939db22013f")
    IWMReaderNetworkConfig2 : public IWMReaderNetworkConfig
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEnableContentCaching( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableContentCaching) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnableContentCaching( 
            /* [annotation][in] */ 
            _In_  BOOL fEnableContentCaching) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnableFastCache( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableFastCache) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnableFastCache( 
            /* [annotation][in] */ 
            _In_  BOOL fEnableFastCache) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAcceleratedStreamingDuration( 
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsAccelDuration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAcceleratedStreamingDuration( 
            /* [annotation][in] */ 
            _In_  QWORD cnsAccelDuration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAutoReconnectLimit( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwAutoReconnectLimit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAutoReconnectLimit( 
            /* [annotation][in] */ 
            _In_  DWORD dwAutoReconnectLimit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnableResends( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableResends) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnableResends( 
            /* [annotation][in] */ 
            _In_  BOOL fEnableResends) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnableThinning( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableThinning) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnableThinning( 
            /* [annotation][in] */ 
            _In_  BOOL fEnableThinning) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxNetPacketSize( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMaxNetPacketSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderNetworkConfig2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderNetworkConfig2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderNetworkConfig2 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetBufferingTime)
        HRESULT ( STDMETHODCALLTYPE *GetBufferingTime )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsBufferingTime);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetBufferingTime)
        HRESULT ( STDMETHODCALLTYPE *SetBufferingTime )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsBufferingTime);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetUDPPortRanges)
        HRESULT ( STDMETHODCALLTYPE *GetUDPPortRanges )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcRanges)  WM_PORT_NUMBER_RANGE *pRangeArray,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcRanges);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetUDPPortRanges)
        HRESULT ( STDMETHODCALLTYPE *SetUDPPortRanges )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cRanges)  WM_PORT_NUMBER_RANGE *pRangeArray,
            /* [annotation][in] */ 
            _In_  DWORD cRanges);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetProxySettings)
        HRESULT ( STDMETHODCALLTYPE *GetProxySettings )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][out] */ 
            _Out_  WMT_PROXY_SETTINGS *pProxySetting);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetProxySettings)
        HRESULT ( STDMETHODCALLTYPE *SetProxySettings )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  WMT_PROXY_SETTINGS ProxySetting);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetProxyHostName)
        HRESULT ( STDMETHODCALLTYPE *GetProxyHostName )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchHostName)  WCHAR *pwszHostName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchHostName);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetProxyHostName)
        HRESULT ( STDMETHODCALLTYPE *SetProxyHostName )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszHostName);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetProxyPort)
        HRESULT ( STDMETHODCALLTYPE *GetProxyPort )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwPort);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetProxyPort)
        HRESULT ( STDMETHODCALLTYPE *SetProxyPort )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  DWORD dwPort);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetProxyExceptionList)
        HRESULT ( STDMETHODCALLTYPE *GetProxyExceptionList )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchExceptionList)  WCHAR *pwszExceptionList,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchExceptionList);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetProxyExceptionList)
        HRESULT ( STDMETHODCALLTYPE *SetProxyExceptionList )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszExceptionList);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetProxyBypassForLocal)
        HRESULT ( STDMETHODCALLTYPE *GetProxyBypassForLocal )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][out] */ 
            _Out_  BOOL *pfBypassForLocal);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetProxyBypassForLocal)
        HRESULT ( STDMETHODCALLTYPE *SetProxyBypassForLocal )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszProtocol,
            /* [annotation][in] */ 
            _In_  BOOL fBypassForLocal);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetForceRerunAutoProxyDetection)
        HRESULT ( STDMETHODCALLTYPE *GetForceRerunAutoProxyDetection )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfForceRerunDetection);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetForceRerunAutoProxyDetection)
        HRESULT ( STDMETHODCALLTYPE *SetForceRerunAutoProxyDetection )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fForceRerunDetection);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetEnableMulticast)
        HRESULT ( STDMETHODCALLTYPE *GetEnableMulticast )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableMulticast);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetEnableMulticast)
        HRESULT ( STDMETHODCALLTYPE *SetEnableMulticast )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableMulticast);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetEnableHTTP)
        HRESULT ( STDMETHODCALLTYPE *GetEnableHTTP )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableHTTP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetEnableHTTP)
        HRESULT ( STDMETHODCALLTYPE *SetEnableHTTP )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableHTTP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetEnableUDP)
        HRESULT ( STDMETHODCALLTYPE *GetEnableUDP )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableUDP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetEnableUDP)
        HRESULT ( STDMETHODCALLTYPE *SetEnableUDP )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableUDP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetEnableTCP)
        HRESULT ( STDMETHODCALLTYPE *GetEnableTCP )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableTCP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetEnableTCP)
        HRESULT ( STDMETHODCALLTYPE *SetEnableTCP )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableTCP);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, ResetProtocolRollover)
        HRESULT ( STDMETHODCALLTYPE *ResetProtocolRollover )( 
            IWMReaderNetworkConfig2 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetConnectionBandwidth)
        HRESULT ( STDMETHODCALLTYPE *GetConnectionBandwidth )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwConnectionBandwidth);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, SetConnectionBandwidth)
        HRESULT ( STDMETHODCALLTYPE *SetConnectionBandwidth )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwConnectionBandwidth);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetNumProtocolsSupported)
        HRESULT ( STDMETHODCALLTYPE *GetNumProtocolsSupported )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcProtocols);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetSupportedProtocolName)
        HRESULT ( STDMETHODCALLTYPE *GetSupportedProtocolName )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwProtocolNum,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchProtocolName)  WCHAR *pwszProtocolName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchProtocolName);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, AddLoggingUrl)
        HRESULT ( STDMETHODCALLTYPE *AddLoggingUrl )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszUrl);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetLoggingUrl)
        HRESULT ( STDMETHODCALLTYPE *GetLoggingUrl )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchUrl)  LPWSTR pwszUrl,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchUrl);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, GetLoggingUrlCount)
        HRESULT ( STDMETHODCALLTYPE *GetLoggingUrlCount )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwUrlCount);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig, ResetLoggingUrlList)
        HRESULT ( STDMETHODCALLTYPE *ResetLoggingUrlList )( 
            IWMReaderNetworkConfig2 * This);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, GetEnableContentCaching)
        HRESULT ( STDMETHODCALLTYPE *GetEnableContentCaching )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableContentCaching);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, SetEnableContentCaching)
        HRESULT ( STDMETHODCALLTYPE *SetEnableContentCaching )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableContentCaching);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, GetEnableFastCache)
        HRESULT ( STDMETHODCALLTYPE *GetEnableFastCache )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableFastCache);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, SetEnableFastCache)
        HRESULT ( STDMETHODCALLTYPE *SetEnableFastCache )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableFastCache);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, GetAcceleratedStreamingDuration)
        HRESULT ( STDMETHODCALLTYPE *GetAcceleratedStreamingDuration )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsAccelDuration);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, SetAcceleratedStreamingDuration)
        HRESULT ( STDMETHODCALLTYPE *SetAcceleratedStreamingDuration )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsAccelDuration);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, GetAutoReconnectLimit)
        HRESULT ( STDMETHODCALLTYPE *GetAutoReconnectLimit )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwAutoReconnectLimit);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, SetAutoReconnectLimit)
        HRESULT ( STDMETHODCALLTYPE *SetAutoReconnectLimit )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwAutoReconnectLimit);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, GetEnableResends)
        HRESULT ( STDMETHODCALLTYPE *GetEnableResends )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableResends);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, SetEnableResends)
        HRESULT ( STDMETHODCALLTYPE *SetEnableResends )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableResends);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, GetEnableThinning)
        HRESULT ( STDMETHODCALLTYPE *GetEnableThinning )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfEnableThinning);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, SetEnableThinning)
        HRESULT ( STDMETHODCALLTYPE *SetEnableThinning )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnableThinning);
        
        DECLSPEC_XFGVIRT(IWMReaderNetworkConfig2, GetMaxNetPacketSize)
        HRESULT ( STDMETHODCALLTYPE *GetMaxNetPacketSize )( 
            IWMReaderNetworkConfig2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwMaxNetPacketSize);
        
        END_INTERFACE
    } IWMReaderNetworkConfig2Vtbl;

    interface IWMReaderNetworkConfig2
    {
        CONST_VTBL struct IWMReaderNetworkConfig2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderNetworkConfig2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderNetworkConfig2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderNetworkConfig2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderNetworkConfig2_GetBufferingTime(This,pcnsBufferingTime)	\
    ( (This)->lpVtbl -> GetBufferingTime(This,pcnsBufferingTime) ) 

#define IWMReaderNetworkConfig2_SetBufferingTime(This,cnsBufferingTime)	\
    ( (This)->lpVtbl -> SetBufferingTime(This,cnsBufferingTime) ) 

#define IWMReaderNetworkConfig2_GetUDPPortRanges(This,pRangeArray,pcRanges)	\
    ( (This)->lpVtbl -> GetUDPPortRanges(This,pRangeArray,pcRanges) ) 

#define IWMReaderNetworkConfig2_SetUDPPortRanges(This,pRangeArray,cRanges)	\
    ( (This)->lpVtbl -> SetUDPPortRanges(This,pRangeArray,cRanges) ) 

#define IWMReaderNetworkConfig2_GetProxySettings(This,pwszProtocol,pProxySetting)	\
    ( (This)->lpVtbl -> GetProxySettings(This,pwszProtocol,pProxySetting) ) 

#define IWMReaderNetworkConfig2_SetProxySettings(This,pwszProtocol,ProxySetting)	\
    ( (This)->lpVtbl -> SetProxySettings(This,pwszProtocol,ProxySetting) ) 

#define IWMReaderNetworkConfig2_GetProxyHostName(This,pwszProtocol,pwszHostName,pcchHostName)	\
    ( (This)->lpVtbl -> GetProxyHostName(This,pwszProtocol,pwszHostName,pcchHostName) ) 

#define IWMReaderNetworkConfig2_SetProxyHostName(This,pwszProtocol,pwszHostName)	\
    ( (This)->lpVtbl -> SetProxyHostName(This,pwszProtocol,pwszHostName) ) 

#define IWMReaderNetworkConfig2_GetProxyPort(This,pwszProtocol,pdwPort)	\
    ( (This)->lpVtbl -> GetProxyPort(This,pwszProtocol,pdwPort) ) 

#define IWMReaderNetworkConfig2_SetProxyPort(This,pwszProtocol,dwPort)	\
    ( (This)->lpVtbl -> SetProxyPort(This,pwszProtocol,dwPort) ) 

#define IWMReaderNetworkConfig2_GetProxyExceptionList(This,pwszProtocol,pwszExceptionList,pcchExceptionList)	\
    ( (This)->lpVtbl -> GetProxyExceptionList(This,pwszProtocol,pwszExceptionList,pcchExceptionList) ) 

#define IWMReaderNetworkConfig2_SetProxyExceptionList(This,pwszProtocol,pwszExceptionList)	\
    ( (This)->lpVtbl -> SetProxyExceptionList(This,pwszProtocol,pwszExceptionList) ) 

#define IWMReaderNetworkConfig2_GetProxyBypassForLocal(This,pwszProtocol,pfBypassForLocal)	\
    ( (This)->lpVtbl -> GetProxyBypassForLocal(This,pwszProtocol,pfBypassForLocal) ) 

#define IWMReaderNetworkConfig2_SetProxyBypassForLocal(This,pwszProtocol,fBypassForLocal)	\
    ( (This)->lpVtbl -> SetProxyBypassForLocal(This,pwszProtocol,fBypassForLocal) ) 

#define IWMReaderNetworkConfig2_GetForceRerunAutoProxyDetection(This,pfForceRerunDetection)	\
    ( (This)->lpVtbl -> GetForceRerunAutoProxyDetection(This,pfForceRerunDetection) ) 

#define IWMReaderNetworkConfig2_SetForceRerunAutoProxyDetection(This,fForceRerunDetection)	\
    ( (This)->lpVtbl -> SetForceRerunAutoProxyDetection(This,fForceRerunDetection) ) 

#define IWMReaderNetworkConfig2_GetEnableMulticast(This,pfEnableMulticast)	\
    ( (This)->lpVtbl -> GetEnableMulticast(This,pfEnableMulticast) ) 

#define IWMReaderNetworkConfig2_SetEnableMulticast(This,fEnableMulticast)	\
    ( (This)->lpVtbl -> SetEnableMulticast(This,fEnableMulticast) ) 

#define IWMReaderNetworkConfig2_GetEnableHTTP(This,pfEnableHTTP)	\
    ( (This)->lpVtbl -> GetEnableHTTP(This,pfEnableHTTP) ) 

#define IWMReaderNetworkConfig2_SetEnableHTTP(This,fEnableHTTP)	\
    ( (This)->lpVtbl -> SetEnableHTTP(This,fEnableHTTP) ) 

#define IWMReaderNetworkConfig2_GetEnableUDP(This,pfEnableUDP)	\
    ( (This)->lpVtbl -> GetEnableUDP(This,pfEnableUDP) ) 

#define IWMReaderNetworkConfig2_SetEnableUDP(This,fEnableUDP)	\
    ( (This)->lpVtbl -> SetEnableUDP(This,fEnableUDP) ) 

#define IWMReaderNetworkConfig2_GetEnableTCP(This,pfEnableTCP)	\
    ( (This)->lpVtbl -> GetEnableTCP(This,pfEnableTCP) ) 

#define IWMReaderNetworkConfig2_SetEnableTCP(This,fEnableTCP)	\
    ( (This)->lpVtbl -> SetEnableTCP(This,fEnableTCP) ) 

#define IWMReaderNetworkConfig2_ResetProtocolRollover(This)	\
    ( (This)->lpVtbl -> ResetProtocolRollover(This) ) 

#define IWMReaderNetworkConfig2_GetConnectionBandwidth(This,pdwConnectionBandwidth)	\
    ( (This)->lpVtbl -> GetConnectionBandwidth(This,pdwConnectionBandwidth) ) 

#define IWMReaderNetworkConfig2_SetConnectionBandwidth(This,dwConnectionBandwidth)	\
    ( (This)->lpVtbl -> SetConnectionBandwidth(This,dwConnectionBandwidth) ) 

#define IWMReaderNetworkConfig2_GetNumProtocolsSupported(This,pcProtocols)	\
    ( (This)->lpVtbl -> GetNumProtocolsSupported(This,pcProtocols) ) 

#define IWMReaderNetworkConfig2_GetSupportedProtocolName(This,dwProtocolNum,pwszProtocolName,pcchProtocolName)	\
    ( (This)->lpVtbl -> GetSupportedProtocolName(This,dwProtocolNum,pwszProtocolName,pcchProtocolName) ) 

#define IWMReaderNetworkConfig2_AddLoggingUrl(This,pwszUrl)	\
    ( (This)->lpVtbl -> AddLoggingUrl(This,pwszUrl) ) 

#define IWMReaderNetworkConfig2_GetLoggingUrl(This,dwIndex,pwszUrl,pcchUrl)	\
    ( (This)->lpVtbl -> GetLoggingUrl(This,dwIndex,pwszUrl,pcchUrl) ) 

#define IWMReaderNetworkConfig2_GetLoggingUrlCount(This,pdwUrlCount)	\
    ( (This)->lpVtbl -> GetLoggingUrlCount(This,pdwUrlCount) ) 

#define IWMReaderNetworkConfig2_ResetLoggingUrlList(This)	\
    ( (This)->lpVtbl -> ResetLoggingUrlList(This) ) 


#define IWMReaderNetworkConfig2_GetEnableContentCaching(This,pfEnableContentCaching)	\
    ( (This)->lpVtbl -> GetEnableContentCaching(This,pfEnableContentCaching) ) 

#define IWMReaderNetworkConfig2_SetEnableContentCaching(This,fEnableContentCaching)	\
    ( (This)->lpVtbl -> SetEnableContentCaching(This,fEnableContentCaching) ) 

#define IWMReaderNetworkConfig2_GetEnableFastCache(This,pfEnableFastCache)	\
    ( (This)->lpVtbl -> GetEnableFastCache(This,pfEnableFastCache) ) 

#define IWMReaderNetworkConfig2_SetEnableFastCache(This,fEnableFastCache)	\
    ( (This)->lpVtbl -> SetEnableFastCache(This,fEnableFastCache) ) 

#define IWMReaderNetworkConfig2_GetAcceleratedStreamingDuration(This,pcnsAccelDuration)	\
    ( (This)->lpVtbl -> GetAcceleratedStreamingDuration(This,pcnsAccelDuration) ) 

#define IWMReaderNetworkConfig2_SetAcceleratedStreamingDuration(This,cnsAccelDuration)	\
    ( (This)->lpVtbl -> SetAcceleratedStreamingDuration(This,cnsAccelDuration) ) 

#define IWMReaderNetworkConfig2_GetAutoReconnectLimit(This,pdwAutoReconnectLimit)	\
    ( (This)->lpVtbl -> GetAutoReconnectLimit(This,pdwAutoReconnectLimit) ) 

#define IWMReaderNetworkConfig2_SetAutoReconnectLimit(This,dwAutoReconnectLimit)	\
    ( (This)->lpVtbl -> SetAutoReconnectLimit(This,dwAutoReconnectLimit) ) 

#define IWMReaderNetworkConfig2_GetEnableResends(This,pfEnableResends)	\
    ( (This)->lpVtbl -> GetEnableResends(This,pfEnableResends) ) 

#define IWMReaderNetworkConfig2_SetEnableResends(This,fEnableResends)	\
    ( (This)->lpVtbl -> SetEnableResends(This,fEnableResends) ) 

#define IWMReaderNetworkConfig2_GetEnableThinning(This,pfEnableThinning)	\
    ( (This)->lpVtbl -> GetEnableThinning(This,pfEnableThinning) ) 

#define IWMReaderNetworkConfig2_SetEnableThinning(This,fEnableThinning)	\
    ( (This)->lpVtbl -> SetEnableThinning(This,fEnableThinning) ) 

#define IWMReaderNetworkConfig2_GetMaxNetPacketSize(This,pdwMaxNetPacketSize)	\
    ( (This)->lpVtbl -> GetMaxNetPacketSize(This,pdwMaxNetPacketSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderNetworkConfig2_INTERFACE_DEFINED__ */


#ifndef __IWMReaderStreamClock_INTERFACE_DEFINED__
#define __IWMReaderStreamClock_INTERFACE_DEFINED__

/* interface IWMReaderStreamClock */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderStreamClock;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96406BED-2B2B-11d3-B36B-00C04F6108FF")
    IWMReaderStreamClock : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTime( 
            /* [annotation][in] */ 
            _In_  QWORD *pcnsNow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTimer( 
            /* [annotation][in] */ 
            _In_  QWORD cnsWhen,
            /* [annotation][in] */ 
            _In_  void *pvParam,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwTimerId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KillTimer( 
            /* [annotation][in] */ 
            _In_  DWORD dwTimerId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderStreamClockVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderStreamClock * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderStreamClock * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderStreamClock * This);
        
        DECLSPEC_XFGVIRT(IWMReaderStreamClock, GetTime)
        HRESULT ( STDMETHODCALLTYPE *GetTime )( 
            IWMReaderStreamClock * This,
            /* [annotation][in] */ 
            _In_  QWORD *pcnsNow);
        
        DECLSPEC_XFGVIRT(IWMReaderStreamClock, SetTimer)
        HRESULT ( STDMETHODCALLTYPE *SetTimer )( 
            IWMReaderStreamClock * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsWhen,
            /* [annotation][in] */ 
            _In_  void *pvParam,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwTimerId);
        
        DECLSPEC_XFGVIRT(IWMReaderStreamClock, KillTimer)
        HRESULT ( STDMETHODCALLTYPE *KillTimer )( 
            IWMReaderStreamClock * This,
            /* [annotation][in] */ 
            _In_  DWORD dwTimerId);
        
        END_INTERFACE
    } IWMReaderStreamClockVtbl;

    interface IWMReaderStreamClock
    {
        CONST_VTBL struct IWMReaderStreamClockVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderStreamClock_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderStreamClock_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderStreamClock_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderStreamClock_GetTime(This,pcnsNow)	\
    ( (This)->lpVtbl -> GetTime(This,pcnsNow) ) 

#define IWMReaderStreamClock_SetTimer(This,cnsWhen,pvParam,pdwTimerId)	\
    ( (This)->lpVtbl -> SetTimer(This,cnsWhen,pvParam,pdwTimerId) ) 

#define IWMReaderStreamClock_KillTimer(This,dwTimerId)	\
    ( (This)->lpVtbl -> KillTimer(This,dwTimerId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderStreamClock_INTERFACE_DEFINED__ */


#ifndef __IWMIndexer_INTERFACE_DEFINED__
#define __IWMIndexer_INTERFACE_DEFINED__

/* interface IWMIndexer */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMIndexer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6d7cdc71-9888-11d3-8edc-00c04f6109cf")
    IWMIndexer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartIndexing( 
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszURL,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMIndexerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMIndexer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMIndexer * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMIndexer * This);
        
        DECLSPEC_XFGVIRT(IWMIndexer, StartIndexing)
        HRESULT ( STDMETHODCALLTYPE *StartIndexing )( 
            IWMIndexer * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszURL,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMIndexer, Cancel)
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IWMIndexer * This);
        
        END_INTERFACE
    } IWMIndexerVtbl;

    interface IWMIndexer
    {
        CONST_VTBL struct IWMIndexerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMIndexer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMIndexer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMIndexer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMIndexer_StartIndexing(This,pwszURL,pCallback,pvContext)	\
    ( (This)->lpVtbl -> StartIndexing(This,pwszURL,pCallback,pvContext) ) 

#define IWMIndexer_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMIndexer_INTERFACE_DEFINED__ */


#ifndef __IWMIndexer2_INTERFACE_DEFINED__
#define __IWMIndexer2_INTERFACE_DEFINED__

/* interface IWMIndexer2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMIndexer2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B70F1E42-6255-4df0-A6B9-02B212D9E2BB")
    IWMIndexer2 : public IWMIndexer
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Configure( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WMT_INDEXER_TYPE nIndexerType,
            /* [annotation][in] */ 
            _In_  void *pvInterval,
            /* [annotation][in] */ 
            _In_  void *pvIndexType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMIndexer2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMIndexer2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMIndexer2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMIndexer2 * This);
        
        DECLSPEC_XFGVIRT(IWMIndexer, StartIndexing)
        HRESULT ( STDMETHODCALLTYPE *StartIndexing )( 
            IWMIndexer2 * This,
            /* [annotation][in] */ 
            _In_  const WCHAR *pwszURL,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMIndexer, Cancel)
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IWMIndexer2 * This);
        
        DECLSPEC_XFGVIRT(IWMIndexer2, Configure)
        HRESULT ( STDMETHODCALLTYPE *Configure )( 
            IWMIndexer2 * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WMT_INDEXER_TYPE nIndexerType,
            /* [annotation][in] */ 
            _In_  void *pvInterval,
            /* [annotation][in] */ 
            _In_  void *pvIndexType);
        
        END_INTERFACE
    } IWMIndexer2Vtbl;

    interface IWMIndexer2
    {
        CONST_VTBL struct IWMIndexer2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMIndexer2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMIndexer2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMIndexer2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMIndexer2_StartIndexing(This,pwszURL,pCallback,pvContext)	\
    ( (This)->lpVtbl -> StartIndexing(This,pwszURL,pCallback,pvContext) ) 

#define IWMIndexer2_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 


#define IWMIndexer2_Configure(This,wStreamNum,nIndexerType,pvInterval,pvIndexType)	\
    ( (This)->lpVtbl -> Configure(This,wStreamNum,nIndexerType,pvInterval,pvIndexType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMIndexer2_INTERFACE_DEFINED__ */


#ifndef __IWMLicenseBackup_INTERFACE_DEFINED__
#define __IWMLicenseBackup_INTERFACE_DEFINED__

/* interface IWMLicenseBackup */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMLicenseBackup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("05E5AC9F-3FB6-4508-BB43-A4067BA1EBE8")
    IWMLicenseBackup : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BackupLicenses( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelLicenseBackup( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMLicenseBackupVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMLicenseBackup * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMLicenseBackup * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMLicenseBackup * This);
        
        DECLSPEC_XFGVIRT(IWMLicenseBackup, BackupLicenses)
        HRESULT ( STDMETHODCALLTYPE *BackupLicenses )( 
            IWMLicenseBackup * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback);
        
        DECLSPEC_XFGVIRT(IWMLicenseBackup, CancelLicenseBackup)
        HRESULT ( STDMETHODCALLTYPE *CancelLicenseBackup )( 
            IWMLicenseBackup * This);
        
        END_INTERFACE
    } IWMLicenseBackupVtbl;

    interface IWMLicenseBackup
    {
        CONST_VTBL struct IWMLicenseBackupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMLicenseBackup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMLicenseBackup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMLicenseBackup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMLicenseBackup_BackupLicenses(This,dwFlags,pCallback)	\
    ( (This)->lpVtbl -> BackupLicenses(This,dwFlags,pCallback) ) 

#define IWMLicenseBackup_CancelLicenseBackup(This)	\
    ( (This)->lpVtbl -> CancelLicenseBackup(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMLicenseBackup_INTERFACE_DEFINED__ */


#ifndef __IWMLicenseRestore_INTERFACE_DEFINED__
#define __IWMLicenseRestore_INTERFACE_DEFINED__

/* interface IWMLicenseRestore */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMLicenseRestore;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C70B6334-A22E-4efb-A245-15E65A004A13")
    IWMLicenseRestore : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RestoreLicenses( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelLicenseRestore( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMLicenseRestoreVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMLicenseRestore * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMLicenseRestore * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMLicenseRestore * This);
        
        DECLSPEC_XFGVIRT(IWMLicenseRestore, RestoreLicenses)
        HRESULT ( STDMETHODCALLTYPE *RestoreLicenses )( 
            IWMLicenseRestore * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback);
        
        DECLSPEC_XFGVIRT(IWMLicenseRestore, CancelLicenseRestore)
        HRESULT ( STDMETHODCALLTYPE *CancelLicenseRestore )( 
            IWMLicenseRestore * This);
        
        END_INTERFACE
    } IWMLicenseRestoreVtbl;

    interface IWMLicenseRestore
    {
        CONST_VTBL struct IWMLicenseRestoreVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMLicenseRestore_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMLicenseRestore_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMLicenseRestore_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMLicenseRestore_RestoreLicenses(This,dwFlags,pCallback)	\
    ( (This)->lpVtbl -> RestoreLicenses(This,dwFlags,pCallback) ) 

#define IWMLicenseRestore_CancelLicenseRestore(This)	\
    ( (This)->lpVtbl -> CancelLicenseRestore(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMLicenseRestore_INTERFACE_DEFINED__ */


#ifndef __IWMBackupRestoreProps_INTERFACE_DEFINED__
#define __IWMBackupRestoreProps_INTERFACE_DEFINED__

/* interface IWMBackupRestoreProps */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMBackupRestoreProps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C8E0DA6-996F-4ff3-A1AF-4838F9377E2E")
    IWMBackupRestoreProps : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPropCount( 
            /* [annotation][out] */ 
            _Out_  WORD *pcProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropByIndex( 
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchNameLen)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchNameLen,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropByName( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProp( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveProp( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAllProps( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMBackupRestorePropsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMBackupRestoreProps * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMBackupRestoreProps * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMBackupRestoreProps * This);
        
        DECLSPEC_XFGVIRT(IWMBackupRestoreProps, GetPropCount)
        HRESULT ( STDMETHODCALLTYPE *GetPropCount )( 
            IWMBackupRestoreProps * This,
            /* [annotation][out] */ 
            _Out_  WORD *pcProps);
        
        DECLSPEC_XFGVIRT(IWMBackupRestoreProps, GetPropByIndex)
        HRESULT ( STDMETHODCALLTYPE *GetPropByIndex )( 
            IWMBackupRestoreProps * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchNameLen)  WCHAR *pwszName,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchNameLen,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMBackupRestoreProps, GetPropByName)
        HRESULT ( STDMETHODCALLTYPE *GetPropByName )( 
            IWMBackupRestoreProps * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbLength)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcbLength);
        
        DECLSPEC_XFGVIRT(IWMBackupRestoreProps, SetProp)
        HRESULT ( STDMETHODCALLTYPE *SetProp )( 
            IWMBackupRestoreProps * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLength)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  WORD cbLength);
        
        DECLSPEC_XFGVIRT(IWMBackupRestoreProps, RemoveProp)
        HRESULT ( STDMETHODCALLTYPE *RemoveProp )( 
            IWMBackupRestoreProps * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pcwszName);
        
        DECLSPEC_XFGVIRT(IWMBackupRestoreProps, RemoveAllProps)
        HRESULT ( STDMETHODCALLTYPE *RemoveAllProps )( 
            IWMBackupRestoreProps * This);
        
        END_INTERFACE
    } IWMBackupRestorePropsVtbl;

    interface IWMBackupRestoreProps
    {
        CONST_VTBL struct IWMBackupRestorePropsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMBackupRestoreProps_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMBackupRestoreProps_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMBackupRestoreProps_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMBackupRestoreProps_GetPropCount(This,pcProps)	\
    ( (This)->lpVtbl -> GetPropCount(This,pcProps) ) 

#define IWMBackupRestoreProps_GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetPropByIndex(This,wIndex,pwszName,pcchNameLen,pType,pValue,pcbLength) ) 

#define IWMBackupRestoreProps_GetPropByName(This,pszName,pType,pValue,pcbLength)	\
    ( (This)->lpVtbl -> GetPropByName(This,pszName,pType,pValue,pcbLength) ) 

#define IWMBackupRestoreProps_SetProp(This,pszName,Type,pValue,cbLength)	\
    ( (This)->lpVtbl -> SetProp(This,pszName,Type,pValue,cbLength) ) 

#define IWMBackupRestoreProps_RemoveProp(This,pcwszName)	\
    ( (This)->lpVtbl -> RemoveProp(This,pcwszName) ) 

#define IWMBackupRestoreProps_RemoveAllProps(This)	\
    ( (This)->lpVtbl -> RemoveAllProps(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMBackupRestoreProps_INTERFACE_DEFINED__ */


#ifndef __IWMCodecInfo_INTERFACE_DEFINED__
#define __IWMCodecInfo_INTERFACE_DEFINED__

/* interface IWMCodecInfo */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMCodecInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A970F41E-34DE-4a98-B3BA-E4B3CA7528F0")
    IWMCodecInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCodecInfoCount( 
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][out] */ 
            _Out_  DWORD *pcCodecs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodecFormatCount( 
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodecFormat( 
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatIndex,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppIStreamConfig) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMCodecInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMCodecInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMCodecInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMCodecInfo * This);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo, GetCodecInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetCodecInfoCount )( 
            IWMCodecInfo * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][out] */ 
            _Out_  DWORD *pcCodecs);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo, GetCodecFormatCount)
        HRESULT ( STDMETHODCALLTYPE *GetCodecFormatCount )( 
            IWMCodecInfo * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormat);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo, GetCodecFormat)
        HRESULT ( STDMETHODCALLTYPE *GetCodecFormat )( 
            IWMCodecInfo * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatIndex,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppIStreamConfig);
        
        END_INTERFACE
    } IWMCodecInfoVtbl;

    interface IWMCodecInfo
    {
        CONST_VTBL struct IWMCodecInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMCodecInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMCodecInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMCodecInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMCodecInfo_GetCodecInfoCount(This,guidType,pcCodecs)	\
    ( (This)->lpVtbl -> GetCodecInfoCount(This,guidType,pcCodecs) ) 

#define IWMCodecInfo_GetCodecFormatCount(This,guidType,dwCodecIndex,pcFormat)	\
    ( (This)->lpVtbl -> GetCodecFormatCount(This,guidType,dwCodecIndex,pcFormat) ) 

#define IWMCodecInfo_GetCodecFormat(This,guidType,dwCodecIndex,dwFormatIndex,ppIStreamConfig)	\
    ( (This)->lpVtbl -> GetCodecFormat(This,guidType,dwCodecIndex,dwFormatIndex,ppIStreamConfig) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMCodecInfo_INTERFACE_DEFINED__ */


#ifndef __IWMCodecInfo2_INTERFACE_DEFINED__
#define __IWMCodecInfo2_INTERFACE_DEFINED__

/* interface IWMCodecInfo2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMCodecInfo2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AA65E273-B686-4056-91EC-DD768D4DF710")
    IWMCodecInfo2 : public IWMCodecInfo
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCodecName( 
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *wszName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodecFormatDesc( 
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatIndex,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppIStreamConfig,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDesc)  WCHAR *wszDesc,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDesc) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMCodecInfo2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMCodecInfo2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMCodecInfo2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMCodecInfo2 * This);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo, GetCodecInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetCodecInfoCount )( 
            IWMCodecInfo2 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][out] */ 
            _Out_  DWORD *pcCodecs);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo, GetCodecFormatCount)
        HRESULT ( STDMETHODCALLTYPE *GetCodecFormatCount )( 
            IWMCodecInfo2 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormat);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo, GetCodecFormat)
        HRESULT ( STDMETHODCALLTYPE *GetCodecFormat )( 
            IWMCodecInfo2 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatIndex,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppIStreamConfig);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo2, GetCodecName)
        HRESULT ( STDMETHODCALLTYPE *GetCodecName )( 
            IWMCodecInfo2 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *wszName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchName);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo2, GetCodecFormatDesc)
        HRESULT ( STDMETHODCALLTYPE *GetCodecFormatDesc )( 
            IWMCodecInfo2 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatIndex,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppIStreamConfig,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDesc)  WCHAR *wszDesc,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDesc);
        
        END_INTERFACE
    } IWMCodecInfo2Vtbl;

    interface IWMCodecInfo2
    {
        CONST_VTBL struct IWMCodecInfo2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMCodecInfo2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMCodecInfo2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMCodecInfo2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMCodecInfo2_GetCodecInfoCount(This,guidType,pcCodecs)	\
    ( (This)->lpVtbl -> GetCodecInfoCount(This,guidType,pcCodecs) ) 

#define IWMCodecInfo2_GetCodecFormatCount(This,guidType,dwCodecIndex,pcFormat)	\
    ( (This)->lpVtbl -> GetCodecFormatCount(This,guidType,dwCodecIndex,pcFormat) ) 

#define IWMCodecInfo2_GetCodecFormat(This,guidType,dwCodecIndex,dwFormatIndex,ppIStreamConfig)	\
    ( (This)->lpVtbl -> GetCodecFormat(This,guidType,dwCodecIndex,dwFormatIndex,ppIStreamConfig) ) 


#define IWMCodecInfo2_GetCodecName(This,guidType,dwCodecIndex,wszName,pcchName)	\
    ( (This)->lpVtbl -> GetCodecName(This,guidType,dwCodecIndex,wszName,pcchName) ) 

#define IWMCodecInfo2_GetCodecFormatDesc(This,guidType,dwCodecIndex,dwFormatIndex,ppIStreamConfig,wszDesc,pcchDesc)	\
    ( (This)->lpVtbl -> GetCodecFormatDesc(This,guidType,dwCodecIndex,dwFormatIndex,ppIStreamConfig,wszDesc,pcchDesc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMCodecInfo2_INTERFACE_DEFINED__ */


#ifndef __IWMCodecInfo3_INTERFACE_DEFINED__
#define __IWMCodecInfo3_INTERFACE_DEFINED__

/* interface IWMCodecInfo3 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMCodecInfo3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7e51f487-4d93-4f98-8ab4-27d0565adc51")
    IWMCodecInfo3 : public IWMCodecInfo2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCodecFormatProp( 
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatIndex,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodecProp( 
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCodecEnumerationSetting( 
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwSize)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  DWORD dwSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodecEnumerationSetting( 
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMCodecInfo3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMCodecInfo3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMCodecInfo3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMCodecInfo3 * This);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo, GetCodecInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetCodecInfoCount )( 
            IWMCodecInfo3 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][out] */ 
            _Out_  DWORD *pcCodecs);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo, GetCodecFormatCount)
        HRESULT ( STDMETHODCALLTYPE *GetCodecFormatCount )( 
            IWMCodecInfo3 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pcFormat);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo, GetCodecFormat)
        HRESULT ( STDMETHODCALLTYPE *GetCodecFormat )( 
            IWMCodecInfo3 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatIndex,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppIStreamConfig);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo2, GetCodecName)
        HRESULT ( STDMETHODCALLTYPE *GetCodecName )( 
            IWMCodecInfo3 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchName)  WCHAR *wszName,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchName);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo2, GetCodecFormatDesc)
        HRESULT ( STDMETHODCALLTYPE *GetCodecFormatDesc )( 
            IWMCodecInfo3 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatIndex,
            /* [annotation][out] */ 
            _Out_  IWMStreamConfig **ppIStreamConfig,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDesc)  WCHAR *wszDesc,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcchDesc);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo3, GetCodecFormatProp)
        HRESULT ( STDMETHODCALLTYPE *GetCodecFormatProp )( 
            IWMCodecInfo3 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwFormatIndex,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo3, GetCodecProp)
        HRESULT ( STDMETHODCALLTYPE *GetCodecProp )( 
            IWMCodecInfo3 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo3, SetCodecEnumerationSetting)
        HRESULT ( STDMETHODCALLTYPE *SetCodecEnumerationSetting )( 
            IWMCodecInfo3 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  WMT_ATTR_DATATYPE Type,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwSize)  const BYTE *pValue,
            /* [annotation][in] */ 
            _In_  DWORD dwSize);
        
        DECLSPEC_XFGVIRT(IWMCodecInfo3, GetCodecEnumerationSetting)
        HRESULT ( STDMETHODCALLTYPE *GetCodecEnumerationSetting )( 
            IWMCodecInfo3 * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidType,
            /* [annotation][in] */ 
            _In_  DWORD dwCodecIndex,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszName,
            /* [annotation][out] */ 
            _Out_  WMT_ATTR_DATATYPE *pType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pdwSize)  BYTE *pValue,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwSize);
        
        END_INTERFACE
    } IWMCodecInfo3Vtbl;

    interface IWMCodecInfo3
    {
        CONST_VTBL struct IWMCodecInfo3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMCodecInfo3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMCodecInfo3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMCodecInfo3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMCodecInfo3_GetCodecInfoCount(This,guidType,pcCodecs)	\
    ( (This)->lpVtbl -> GetCodecInfoCount(This,guidType,pcCodecs) ) 

#define IWMCodecInfo3_GetCodecFormatCount(This,guidType,dwCodecIndex,pcFormat)	\
    ( (This)->lpVtbl -> GetCodecFormatCount(This,guidType,dwCodecIndex,pcFormat) ) 

#define IWMCodecInfo3_GetCodecFormat(This,guidType,dwCodecIndex,dwFormatIndex,ppIStreamConfig)	\
    ( (This)->lpVtbl -> GetCodecFormat(This,guidType,dwCodecIndex,dwFormatIndex,ppIStreamConfig) ) 


#define IWMCodecInfo3_GetCodecName(This,guidType,dwCodecIndex,wszName,pcchName)	\
    ( (This)->lpVtbl -> GetCodecName(This,guidType,dwCodecIndex,wszName,pcchName) ) 

#define IWMCodecInfo3_GetCodecFormatDesc(This,guidType,dwCodecIndex,dwFormatIndex,ppIStreamConfig,wszDesc,pcchDesc)	\
    ( (This)->lpVtbl -> GetCodecFormatDesc(This,guidType,dwCodecIndex,dwFormatIndex,ppIStreamConfig,wszDesc,pcchDesc) ) 


#define IWMCodecInfo3_GetCodecFormatProp(This,guidType,dwCodecIndex,dwFormatIndex,pszName,pType,pValue,pdwSize)	\
    ( (This)->lpVtbl -> GetCodecFormatProp(This,guidType,dwCodecIndex,dwFormatIndex,pszName,pType,pValue,pdwSize) ) 

#define IWMCodecInfo3_GetCodecProp(This,guidType,dwCodecIndex,pszName,pType,pValue,pdwSize)	\
    ( (This)->lpVtbl -> GetCodecProp(This,guidType,dwCodecIndex,pszName,pType,pValue,pdwSize) ) 

#define IWMCodecInfo3_SetCodecEnumerationSetting(This,guidType,dwCodecIndex,pszName,Type,pValue,dwSize)	\
    ( (This)->lpVtbl -> SetCodecEnumerationSetting(This,guidType,dwCodecIndex,pszName,Type,pValue,dwSize) ) 

#define IWMCodecInfo3_GetCodecEnumerationSetting(This,guidType,dwCodecIndex,pszName,pType,pValue,pdwSize)	\
    ( (This)->lpVtbl -> GetCodecEnumerationSetting(This,guidType,dwCodecIndex,pszName,pType,pValue,pdwSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMCodecInfo3_INTERFACE_DEFINED__ */


#ifndef __IWMLanguageList_INTERFACE_DEFINED__
#define __IWMLanguageList_INTERFACE_DEFINED__

/* interface IWMLanguageList */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMLanguageList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DF683F00-2D49-4d8e-92B7-FB19F6A0DC57")
    IWMLanguageList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLanguageCount( 
            /* [annotation][out] */ 
            _Out_  WORD *pwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLanguageDetails( 
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchLanguageStringLength)  WCHAR *pwszLanguageString,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchLanguageStringLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddLanguageByRFC1766String( 
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszLanguageString,
            /* [annotation][out] */ 
            _Out_  WORD *pwIndex) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMLanguageListVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMLanguageList * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMLanguageList * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMLanguageList * This);
        
        DECLSPEC_XFGVIRT(IWMLanguageList, GetLanguageCount)
        HRESULT ( STDMETHODCALLTYPE *GetLanguageCount )( 
            IWMLanguageList * This,
            /* [annotation][out] */ 
            _Out_  WORD *pwCount);
        
        DECLSPEC_XFGVIRT(IWMLanguageList, GetLanguageDetails)
        HRESULT ( STDMETHODCALLTYPE *GetLanguageDetails )( 
            IWMLanguageList * This,
            /* [annotation][in] */ 
            _In_  WORD wIndex,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchLanguageStringLength)  WCHAR *pwszLanguageString,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchLanguageStringLength);
        
        DECLSPEC_XFGVIRT(IWMLanguageList, AddLanguageByRFC1766String)
        HRESULT ( STDMETHODCALLTYPE *AddLanguageByRFC1766String )( 
            IWMLanguageList * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR_WMSDK_TYPE_SAFE pwszLanguageString,
            /* [annotation][out] */ 
            _Out_  WORD *pwIndex);
        
        END_INTERFACE
    } IWMLanguageListVtbl;

    interface IWMLanguageList
    {
        CONST_VTBL struct IWMLanguageListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMLanguageList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMLanguageList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMLanguageList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMLanguageList_GetLanguageCount(This,pwCount)	\
    ( (This)->lpVtbl -> GetLanguageCount(This,pwCount) ) 

#define IWMLanguageList_GetLanguageDetails(This,wIndex,pwszLanguageString,pcchLanguageStringLength)	\
    ( (This)->lpVtbl -> GetLanguageDetails(This,wIndex,pwszLanguageString,pcchLanguageStringLength) ) 

#define IWMLanguageList_AddLanguageByRFC1766String(This,pwszLanguageString,pwIndex)	\
    ( (This)->lpVtbl -> AddLanguageByRFC1766String(This,pwszLanguageString,pwIndex) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMLanguageList_INTERFACE_DEFINED__ */


#ifndef __IWMWriterPushSink_INTERFACE_DEFINED__
#define __IWMWriterPushSink_INTERFACE_DEFINED__

/* interface IWMWriterPushSink */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWriterPushSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("dc10e6a5-072c-467d-bf57-6330a9dde12a")
    IWMWriterPushSink : public IWMWriterSink
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Connect( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszURL,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszTemplateURL,
            /* [annotation][in] */ 
            _In_  BOOL fAutoDestroy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndSession( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWriterPushSinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWriterPushSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWriterPushSink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWriterPushSink * This);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnHeader)
        HRESULT ( STDMETHODCALLTYPE *OnHeader )( 
            IWMWriterPushSink * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pHeader);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, IsRealTime)
        HRESULT ( STDMETHODCALLTYPE *IsRealTime )( 
            IWMWriterPushSink * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfRealTime);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, AllocateDataUnit)
        HRESULT ( STDMETHODCALLTYPE *AllocateDataUnit )( 
            IWMWriterPushSink * This,
            /* [annotation][in] */ 
            _In_  DWORD cbDataUnit,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnDataUnit)
        HRESULT ( STDMETHODCALLTYPE *OnDataUnit )( 
            IWMWriterPushSink * This,
            /* [annotation][in] */ 
            _In_  INSSBuffer *pDataUnit);
        
        DECLSPEC_XFGVIRT(IWMWriterSink, OnEndWriting)
        HRESULT ( STDMETHODCALLTYPE *OnEndWriting )( 
            IWMWriterPushSink * This);
        
        DECLSPEC_XFGVIRT(IWMWriterPushSink, Connect)
        HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IWMWriterPushSink * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszURL,
            /* [annotation][in] */ 
            _In_  LPCWSTR pwszTemplateURL,
            /* [annotation][in] */ 
            _In_  BOOL fAutoDestroy);
        
        DECLSPEC_XFGVIRT(IWMWriterPushSink, Disconnect)
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IWMWriterPushSink * This);
        
        DECLSPEC_XFGVIRT(IWMWriterPushSink, EndSession)
        HRESULT ( STDMETHODCALLTYPE *EndSession )( 
            IWMWriterPushSink * This);
        
        END_INTERFACE
    } IWMWriterPushSinkVtbl;

    interface IWMWriterPushSink
    {
        CONST_VTBL struct IWMWriterPushSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWriterPushSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWriterPushSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWriterPushSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWriterPushSink_OnHeader(This,pHeader)	\
    ( (This)->lpVtbl -> OnHeader(This,pHeader) ) 

#define IWMWriterPushSink_IsRealTime(This,pfRealTime)	\
    ( (This)->lpVtbl -> IsRealTime(This,pfRealTime) ) 

#define IWMWriterPushSink_AllocateDataUnit(This,cbDataUnit,ppDataUnit)	\
    ( (This)->lpVtbl -> AllocateDataUnit(This,cbDataUnit,ppDataUnit) ) 

#define IWMWriterPushSink_OnDataUnit(This,pDataUnit)	\
    ( (This)->lpVtbl -> OnDataUnit(This,pDataUnit) ) 

#define IWMWriterPushSink_OnEndWriting(This)	\
    ( (This)->lpVtbl -> OnEndWriting(This) ) 


#define IWMWriterPushSink_Connect(This,pwszURL,pwszTemplateURL,fAutoDestroy)	\
    ( (This)->lpVtbl -> Connect(This,pwszURL,pwszTemplateURL,fAutoDestroy) ) 

#define IWMWriterPushSink_Disconnect(This)	\
    ( (This)->lpVtbl -> Disconnect(This) ) 

#define IWMWriterPushSink_EndSession(This)	\
    ( (This)->lpVtbl -> EndSession(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWriterPushSink_INTERFACE_DEFINED__ */


#ifndef __IWMDeviceRegistration_INTERFACE_DEFINED__
#define __IWMDeviceRegistration_INTERFACE_DEFINED__

/* interface IWMDeviceRegistration */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDeviceRegistration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f6211f03-8d21-4e94-93e6-8510805f2d99")
    IWMDeviceRegistration : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RegisterDevice( 
            /* [annotation][in] */ 
            _In_  DWORD dwRegisterType,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbCertificate)  BYTE *pbCertificate,
            /* [annotation][in] */ 
            _In_  DWORD cbCertificate,
            /* [annotation][in] */ 
            _In_  DRM_VAL16 SerialNumber,
            /* [annotation][out] */ 
            _Out_  IWMRegisteredDevice **ppDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterDevice( 
            /* [annotation][in] */ 
            _In_  DWORD dwRegisterType,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbCertificate)  BYTE *pbCertificate,
            /* [annotation][in] */ 
            _In_  DWORD cbCertificate,
            /* [annotation][in] */ 
            _In_  DRM_VAL16 SerialNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegistrationStats( 
            /* [annotation][in] */ 
            _In_  DWORD dwRegisterType,
            /* [annotation][out] */ 
            _Out_  DWORD *pcRegisteredDevices) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFirstRegisteredDevice( 
            /* [annotation][in] */ 
            _In_  DWORD dwRegisterType,
            /* [annotation][out] */ 
            _Out_  IWMRegisteredDevice **ppDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextRegisteredDevice( 
            /* [annotation][out] */ 
            _Out_  IWMRegisteredDevice **ppDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegisteredDeviceByID( 
            /* [annotation][in] */ 
            _In_  DWORD dwRegisterType,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbCertificate)  BYTE *pbCertificate,
            /* [annotation][in] */ 
            _In_  DWORD cbCertificate,
            /* [annotation][in] */ 
            _In_  DRM_VAL16 SerialNumber,
            /* [annotation][out] */ 
            _Out_  IWMRegisteredDevice **ppDevice) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDeviceRegistrationVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDeviceRegistration * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDeviceRegistration * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDeviceRegistration * This);
        
        DECLSPEC_XFGVIRT(IWMDeviceRegistration, RegisterDevice)
        HRESULT ( STDMETHODCALLTYPE *RegisterDevice )( 
            IWMDeviceRegistration * This,
            /* [annotation][in] */ 
            _In_  DWORD dwRegisterType,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbCertificate)  BYTE *pbCertificate,
            /* [annotation][in] */ 
            _In_  DWORD cbCertificate,
            /* [annotation][in] */ 
            _In_  DRM_VAL16 SerialNumber,
            /* [annotation][out] */ 
            _Out_  IWMRegisteredDevice **ppDevice);
        
        DECLSPEC_XFGVIRT(IWMDeviceRegistration, UnregisterDevice)
        HRESULT ( STDMETHODCALLTYPE *UnregisterDevice )( 
            IWMDeviceRegistration * This,
            /* [annotation][in] */ 
            _In_  DWORD dwRegisterType,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbCertificate)  BYTE *pbCertificate,
            /* [annotation][in] */ 
            _In_  DWORD cbCertificate,
            /* [annotation][in] */ 
            _In_  DRM_VAL16 SerialNumber);
        
        DECLSPEC_XFGVIRT(IWMDeviceRegistration, GetRegistrationStats)
        HRESULT ( STDMETHODCALLTYPE *GetRegistrationStats )( 
            IWMDeviceRegistration * This,
            /* [annotation][in] */ 
            _In_  DWORD dwRegisterType,
            /* [annotation][out] */ 
            _Out_  DWORD *pcRegisteredDevices);
        
        DECLSPEC_XFGVIRT(IWMDeviceRegistration, GetFirstRegisteredDevice)
        HRESULT ( STDMETHODCALLTYPE *GetFirstRegisteredDevice )( 
            IWMDeviceRegistration * This,
            /* [annotation][in] */ 
            _In_  DWORD dwRegisterType,
            /* [annotation][out] */ 
            _Out_  IWMRegisteredDevice **ppDevice);
        
        DECLSPEC_XFGVIRT(IWMDeviceRegistration, GetNextRegisteredDevice)
        HRESULT ( STDMETHODCALLTYPE *GetNextRegisteredDevice )( 
            IWMDeviceRegistration * This,
            /* [annotation][out] */ 
            _Out_  IWMRegisteredDevice **ppDevice);
        
        DECLSPEC_XFGVIRT(IWMDeviceRegistration, GetRegisteredDeviceByID)
        HRESULT ( STDMETHODCALLTYPE *GetRegisteredDeviceByID )( 
            IWMDeviceRegistration * This,
            /* [annotation][in] */ 
            _In_  DWORD dwRegisterType,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbCertificate)  BYTE *pbCertificate,
            /* [annotation][in] */ 
            _In_  DWORD cbCertificate,
            /* [annotation][in] */ 
            _In_  DRM_VAL16 SerialNumber,
            /* [annotation][out] */ 
            _Out_  IWMRegisteredDevice **ppDevice);
        
        END_INTERFACE
    } IWMDeviceRegistrationVtbl;

    interface IWMDeviceRegistration
    {
        CONST_VTBL struct IWMDeviceRegistrationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDeviceRegistration_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDeviceRegistration_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDeviceRegistration_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDeviceRegistration_RegisterDevice(This,dwRegisterType,pbCertificate,cbCertificate,SerialNumber,ppDevice)	\
    ( (This)->lpVtbl -> RegisterDevice(This,dwRegisterType,pbCertificate,cbCertificate,SerialNumber,ppDevice) ) 

#define IWMDeviceRegistration_UnregisterDevice(This,dwRegisterType,pbCertificate,cbCertificate,SerialNumber)	\
    ( (This)->lpVtbl -> UnregisterDevice(This,dwRegisterType,pbCertificate,cbCertificate,SerialNumber) ) 

#define IWMDeviceRegistration_GetRegistrationStats(This,dwRegisterType,pcRegisteredDevices)	\
    ( (This)->lpVtbl -> GetRegistrationStats(This,dwRegisterType,pcRegisteredDevices) ) 

#define IWMDeviceRegistration_GetFirstRegisteredDevice(This,dwRegisterType,ppDevice)	\
    ( (This)->lpVtbl -> GetFirstRegisteredDevice(This,dwRegisterType,ppDevice) ) 

#define IWMDeviceRegistration_GetNextRegisteredDevice(This,ppDevice)	\
    ( (This)->lpVtbl -> GetNextRegisteredDevice(This,ppDevice) ) 

#define IWMDeviceRegistration_GetRegisteredDeviceByID(This,dwRegisterType,pbCertificate,cbCertificate,SerialNumber,ppDevice)	\
    ( (This)->lpVtbl -> GetRegisteredDeviceByID(This,dwRegisterType,pbCertificate,cbCertificate,SerialNumber,ppDevice) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDeviceRegistration_INTERFACE_DEFINED__ */


#ifndef __IWMRegisteredDevice_INTERFACE_DEFINED__
#define __IWMRegisteredDevice_INTERFACE_DEFINED__

/* interface IWMRegisteredDevice */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMRegisteredDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a4503bec-5508-4148-97ac-bfa75760a70d")
    IWMRegisteredDevice : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDeviceSerialNumber( 
            /* [annotation][out] */ 
            _Out_  DRM_VAL16 *pSerialNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceCertificate( 
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppCertificate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceType( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributeCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributeByIndex( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrName,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributeByName( 
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttributeByName( 
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Approve( 
            /* [annotation][in] */ 
            _In_  BOOL fApprove) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsValid( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfValid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsApproved( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfApproved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsWmdrmCompliant( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfCompliant) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsOpened( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfOpened) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Open( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMRegisteredDeviceVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMRegisteredDevice * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMRegisteredDevice * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMRegisteredDevice * This);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, GetDeviceSerialNumber)
        HRESULT ( STDMETHODCALLTYPE *GetDeviceSerialNumber )( 
            IWMRegisteredDevice * This,
            /* [annotation][out] */ 
            _Out_  DRM_VAL16 *pSerialNumber);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, GetDeviceCertificate)
        HRESULT ( STDMETHODCALLTYPE *GetDeviceCertificate )( 
            IWMRegisteredDevice * This,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppCertificate);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, GetDeviceType)
        HRESULT ( STDMETHODCALLTYPE *GetDeviceType )( 
            IWMRegisteredDevice * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwType);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, GetAttributeCount)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeCount )( 
            IWMRegisteredDevice * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcAttributes);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, GetAttributeByIndex)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeByIndex )( 
            IWMRegisteredDevice * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrName,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrValue);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, GetAttributeByName)
        HRESULT ( STDMETHODCALLTYPE *GetAttributeByName )( 
            IWMRegisteredDevice * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrValue);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, SetAttributeByName)
        HRESULT ( STDMETHODCALLTYPE *SetAttributeByName )( 
            IWMRegisteredDevice * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrValue);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, Approve)
        HRESULT ( STDMETHODCALLTYPE *Approve )( 
            IWMRegisteredDevice * This,
            /* [annotation][in] */ 
            _In_  BOOL fApprove);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, IsValid)
        HRESULT ( STDMETHODCALLTYPE *IsValid )( 
            IWMRegisteredDevice * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfValid);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, IsApproved)
        HRESULT ( STDMETHODCALLTYPE *IsApproved )( 
            IWMRegisteredDevice * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfApproved);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, IsWmdrmCompliant)
        HRESULT ( STDMETHODCALLTYPE *IsWmdrmCompliant )( 
            IWMRegisteredDevice * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfCompliant);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, IsOpened)
        HRESULT ( STDMETHODCALLTYPE *IsOpened )( 
            IWMRegisteredDevice * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfOpened);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, Open)
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWMRegisteredDevice * This);
        
        DECLSPEC_XFGVIRT(IWMRegisteredDevice, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWMRegisteredDevice * This);
        
        END_INTERFACE
    } IWMRegisteredDeviceVtbl;

    interface IWMRegisteredDevice
    {
        CONST_VTBL struct IWMRegisteredDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMRegisteredDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMRegisteredDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMRegisteredDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMRegisteredDevice_GetDeviceSerialNumber(This,pSerialNumber)	\
    ( (This)->lpVtbl -> GetDeviceSerialNumber(This,pSerialNumber) ) 

#define IWMRegisteredDevice_GetDeviceCertificate(This,ppCertificate)	\
    ( (This)->lpVtbl -> GetDeviceCertificate(This,ppCertificate) ) 

#define IWMRegisteredDevice_GetDeviceType(This,pdwType)	\
    ( (This)->lpVtbl -> GetDeviceType(This,pdwType) ) 

#define IWMRegisteredDevice_GetAttributeCount(This,pcAttributes)	\
    ( (This)->lpVtbl -> GetAttributeCount(This,pcAttributes) ) 

#define IWMRegisteredDevice_GetAttributeByIndex(This,dwIndex,pbstrName,pbstrValue)	\
    ( (This)->lpVtbl -> GetAttributeByIndex(This,dwIndex,pbstrName,pbstrValue) ) 

#define IWMRegisteredDevice_GetAttributeByName(This,bstrName,pbstrValue)	\
    ( (This)->lpVtbl -> GetAttributeByName(This,bstrName,pbstrValue) ) 

#define IWMRegisteredDevice_SetAttributeByName(This,bstrName,bstrValue)	\
    ( (This)->lpVtbl -> SetAttributeByName(This,bstrName,bstrValue) ) 

#define IWMRegisteredDevice_Approve(This,fApprove)	\
    ( (This)->lpVtbl -> Approve(This,fApprove) ) 

#define IWMRegisteredDevice_IsValid(This,pfValid)	\
    ( (This)->lpVtbl -> IsValid(This,pfValid) ) 

#define IWMRegisteredDevice_IsApproved(This,pfApproved)	\
    ( (This)->lpVtbl -> IsApproved(This,pfApproved) ) 

#define IWMRegisteredDevice_IsWmdrmCompliant(This,pfCompliant)	\
    ( (This)->lpVtbl -> IsWmdrmCompliant(This,pfCompliant) ) 

#define IWMRegisteredDevice_IsOpened(This,pfOpened)	\
    ( (This)->lpVtbl -> IsOpened(This,pfOpened) ) 

#define IWMRegisteredDevice_Open(This)	\
    ( (This)->lpVtbl -> Open(This) ) 

#define IWMRegisteredDevice_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMRegisteredDevice_INTERFACE_DEFINED__ */


#ifndef __IWMProximityDetection_INTERFACE_DEFINED__
#define __IWMProximityDetection_INTERFACE_DEFINED__

/* interface IWMProximityDetection */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMProximityDetection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A9FD8EE-B651-4bf0-B849-7D4ECE79A2B1")
    IWMProximityDetection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartDetection( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cbRegistrationMsg)  BYTE *pbRegistrationMsg,
            /* [annotation][in] */ 
            _In_  DWORD cbRegistrationMsg,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLocalAddress)  BYTE *pbLocalAddress,
            /* [annotation][in] */ 
            _In_  DWORD cbLocalAddress,
            /* [annotation][in] */ 
            _In_  DWORD dwExtraPortsAllowed,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppRegistrationResponseMsg,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMProximityDetectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMProximityDetection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMProximityDetection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMProximityDetection * This);
        
        DECLSPEC_XFGVIRT(IWMProximityDetection, StartDetection)
        HRESULT ( STDMETHODCALLTYPE *StartDetection )( 
            IWMProximityDetection * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbRegistrationMsg)  BYTE *pbRegistrationMsg,
            /* [annotation][in] */ 
            _In_  DWORD cbRegistrationMsg,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbLocalAddress)  BYTE *pbLocalAddress,
            /* [annotation][in] */ 
            _In_  DWORD cbLocalAddress,
            /* [annotation][in] */ 
            _In_  DWORD dwExtraPortsAllowed,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppRegistrationResponseMsg,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        END_INTERFACE
    } IWMProximityDetectionVtbl;

    interface IWMProximityDetection
    {
        CONST_VTBL struct IWMProximityDetectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMProximityDetection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMProximityDetection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMProximityDetection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMProximityDetection_StartDetection(This,pbRegistrationMsg,cbRegistrationMsg,pbLocalAddress,cbLocalAddress,dwExtraPortsAllowed,ppRegistrationResponseMsg,pCallback,pvContext)	\
    ( (This)->lpVtbl -> StartDetection(This,pbRegistrationMsg,cbRegistrationMsg,pbLocalAddress,cbLocalAddress,dwExtraPortsAllowed,ppRegistrationResponseMsg,pCallback,pvContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMProximityDetection_INTERFACE_DEFINED__ */


#ifndef __IWMDRMMessageParser_INTERFACE_DEFINED__
#define __IWMDRMMessageParser_INTERFACE_DEFINED__

/* interface IWMDRMMessageParser */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDRMMessageParser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A73A0072-25A0-4c99-B4A5-EDE8101A6C39")
    IWMDRMMessageParser : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ParseRegistrationReqMsg( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cbRegistrationReqMsg)  BYTE *pbRegistrationReqMsg,
            /* [annotation][in] */ 
            _In_  DWORD cbRegistrationReqMsg,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppDeviceCert,
            /* [annotation][out] */ 
            _Out_  DRM_VAL16 *pDeviceSerialNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ParseLicenseRequestMsg( 
            /* [annotation][size_is][in] */ 
            _In_reads_(pbLicenseRequestMsg)  BYTE *pbLicenseRequestMsg,
            /* [annotation][in] */ 
            _In_  DWORD cbLicenseRequestMsg,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppDeviceCert,
            /* [annotation][out] */ 
            _Out_  DRM_VAL16 *pDeviceSerialNumber,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrAction) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDRMMessageParserVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDRMMessageParser * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDRMMessageParser * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDRMMessageParser * This);
        
        DECLSPEC_XFGVIRT(IWMDRMMessageParser, ParseRegistrationReqMsg)
        HRESULT ( STDMETHODCALLTYPE *ParseRegistrationReqMsg )( 
            IWMDRMMessageParser * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbRegistrationReqMsg)  BYTE *pbRegistrationReqMsg,
            /* [annotation][in] */ 
            _In_  DWORD cbRegistrationReqMsg,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppDeviceCert,
            /* [annotation][out] */ 
            _Out_  DRM_VAL16 *pDeviceSerialNumber);
        
        DECLSPEC_XFGVIRT(IWMDRMMessageParser, ParseLicenseRequestMsg)
        HRESULT ( STDMETHODCALLTYPE *ParseLicenseRequestMsg )( 
            IWMDRMMessageParser * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(pbLicenseRequestMsg)  BYTE *pbLicenseRequestMsg,
            /* [annotation][in] */ 
            _In_  DWORD cbLicenseRequestMsg,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppDeviceCert,
            /* [annotation][out] */ 
            _Out_  DRM_VAL16 *pDeviceSerialNumber,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrAction);
        
        END_INTERFACE
    } IWMDRMMessageParserVtbl;

    interface IWMDRMMessageParser
    {
        CONST_VTBL struct IWMDRMMessageParserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDRMMessageParser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDRMMessageParser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDRMMessageParser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDRMMessageParser_ParseRegistrationReqMsg(This,pbRegistrationReqMsg,cbRegistrationReqMsg,ppDeviceCert,pDeviceSerialNumber)	\
    ( (This)->lpVtbl -> ParseRegistrationReqMsg(This,pbRegistrationReqMsg,cbRegistrationReqMsg,ppDeviceCert,pDeviceSerialNumber) ) 

#define IWMDRMMessageParser_ParseLicenseRequestMsg(This,pbLicenseRequestMsg,cbLicenseRequestMsg,ppDeviceCert,pDeviceSerialNumber,pbstrAction)	\
    ( (This)->lpVtbl -> ParseLicenseRequestMsg(This,pbLicenseRequestMsg,cbLicenseRequestMsg,ppDeviceCert,pDeviceSerialNumber,pbstrAction) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDRMMessageParser_INTERFACE_DEFINED__ */


#ifndef __IWMDRMTranscryptor_INTERFACE_DEFINED__
#define __IWMDRMTranscryptor_INTERFACE_DEFINED__

/* interface IWMDRMTranscryptor */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDRMTranscryptor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69059850-6E6F-4bb2-806F-71863DDFC471")
    IWMDRMTranscryptor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  BSTR bstrFileName,
            /* [size_is][in] */ BYTE *pbLicenseRequestMsg,
            /* [annotation][in] */ 
            _In_  DWORD cbLicenseRequestMsg,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppLicenseResponseMsg,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Seek( 
            /* [annotation][in] */ 
            _In_  QWORD hnsTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Read( 
            /* [annotation][in] */ 
            _In_  BYTE *pbData,
            /* [annotation][in] */ 
            _In_  DWORD *pcbData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDRMTranscryptorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDRMTranscryptor * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDRMTranscryptor * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDRMTranscryptor * This);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor, Initialize)
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IWMDRMTranscryptor * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrFileName,
            /* [size_is][in] */ BYTE *pbLicenseRequestMsg,
            /* [annotation][in] */ 
            _In_  DWORD cbLicenseRequestMsg,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppLicenseResponseMsg,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor, Seek)
        HRESULT ( STDMETHODCALLTYPE *Seek )( 
            IWMDRMTranscryptor * This,
            /* [annotation][in] */ 
            _In_  QWORD hnsTime);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor, Read)
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IWMDRMTranscryptor * This,
            /* [annotation][in] */ 
            _In_  BYTE *pbData,
            /* [annotation][in] */ 
            _In_  DWORD *pcbData);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWMDRMTranscryptor * This);
        
        END_INTERFACE
    } IWMDRMTranscryptorVtbl;

    interface IWMDRMTranscryptor
    {
        CONST_VTBL struct IWMDRMTranscryptorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDRMTranscryptor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDRMTranscryptor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDRMTranscryptor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDRMTranscryptor_Initialize(This,bstrFileName,pbLicenseRequestMsg,cbLicenseRequestMsg,ppLicenseResponseMsg,pCallback,pvContext)	\
    ( (This)->lpVtbl -> Initialize(This,bstrFileName,pbLicenseRequestMsg,cbLicenseRequestMsg,ppLicenseResponseMsg,pCallback,pvContext) ) 

#define IWMDRMTranscryptor_Seek(This,hnsTime)	\
    ( (This)->lpVtbl -> Seek(This,hnsTime) ) 

#define IWMDRMTranscryptor_Read(This,pbData,pcbData)	\
    ( (This)->lpVtbl -> Read(This,pbData,pcbData) ) 

#define IWMDRMTranscryptor_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDRMTranscryptor_INTERFACE_DEFINED__ */


#ifndef __IWMDRMTranscryptor2_INTERFACE_DEFINED__
#define __IWMDRMTranscryptor2_INTERFACE_DEFINED__

/* interface IWMDRMTranscryptor2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDRMTranscryptor2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e0da439f-d331-496a-bece-18e5bac5dd23")
    IWMDRMTranscryptor2 : public IWMDRMTranscryptor
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SeekEx( 
            /* [annotation][in] */ 
            _In_  QWORD cnsStartTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float flRate,
            /* [annotation][in] */ 
            _In_  BOOL fIncludeFileHeader) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ZeroAdjustTimestamps( 
            /* [annotation][in] */ 
            _In_  BOOL fEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSeekStartTime( 
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDuration( 
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDuration) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDRMTranscryptor2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDRMTranscryptor2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDRMTranscryptor2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDRMTranscryptor2 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor, Initialize)
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IWMDRMTranscryptor2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrFileName,
            /* [size_is][in] */ BYTE *pbLicenseRequestMsg,
            /* [annotation][in] */ 
            _In_  DWORD cbLicenseRequestMsg,
            /* [annotation][out] */ 
            _Out_  INSSBuffer **ppLicenseResponseMsg,
            /* [annotation][in] */ 
            _In_  IWMStatusCallback *pCallback,
            /* [annotation][in] */ 
            _In_  void *pvContext);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor, Seek)
        HRESULT ( STDMETHODCALLTYPE *Seek )( 
            IWMDRMTranscryptor2 * This,
            /* [annotation][in] */ 
            _In_  QWORD hnsTime);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor, Read)
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            IWMDRMTranscryptor2 * This,
            /* [annotation][in] */ 
            _In_  BYTE *pbData,
            /* [annotation][in] */ 
            _In_  DWORD *pcbData);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWMDRMTranscryptor2 * This);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor2, SeekEx)
        HRESULT ( STDMETHODCALLTYPE *SeekEx )( 
            IWMDRMTranscryptor2 * This,
            /* [annotation][in] */ 
            _In_  QWORD cnsStartTime,
            /* [annotation][in] */ 
            _In_  QWORD cnsDuration,
            /* [annotation][in] */ 
            _In_  float flRate,
            /* [annotation][in] */ 
            _In_  BOOL fIncludeFileHeader);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor2, ZeroAdjustTimestamps)
        HRESULT ( STDMETHODCALLTYPE *ZeroAdjustTimestamps )( 
            IWMDRMTranscryptor2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fEnable);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor2, GetSeekStartTime)
        HRESULT ( STDMETHODCALLTYPE *GetSeekStartTime )( 
            IWMDRMTranscryptor2 * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsTime);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptor2, GetDuration)
        HRESULT ( STDMETHODCALLTYPE *GetDuration )( 
            IWMDRMTranscryptor2 * This,
            /* [annotation][out] */ 
            _Out_  QWORD *pcnsDuration);
        
        END_INTERFACE
    } IWMDRMTranscryptor2Vtbl;

    interface IWMDRMTranscryptor2
    {
        CONST_VTBL struct IWMDRMTranscryptor2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDRMTranscryptor2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDRMTranscryptor2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDRMTranscryptor2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDRMTranscryptor2_Initialize(This,bstrFileName,pbLicenseRequestMsg,cbLicenseRequestMsg,ppLicenseResponseMsg,pCallback,pvContext)	\
    ( (This)->lpVtbl -> Initialize(This,bstrFileName,pbLicenseRequestMsg,cbLicenseRequestMsg,ppLicenseResponseMsg,pCallback,pvContext) ) 

#define IWMDRMTranscryptor2_Seek(This,hnsTime)	\
    ( (This)->lpVtbl -> Seek(This,hnsTime) ) 

#define IWMDRMTranscryptor2_Read(This,pbData,pcbData)	\
    ( (This)->lpVtbl -> Read(This,pbData,pcbData) ) 

#define IWMDRMTranscryptor2_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 


#define IWMDRMTranscryptor2_SeekEx(This,cnsStartTime,cnsDuration,flRate,fIncludeFileHeader)	\
    ( (This)->lpVtbl -> SeekEx(This,cnsStartTime,cnsDuration,flRate,fIncludeFileHeader) ) 

#define IWMDRMTranscryptor2_ZeroAdjustTimestamps(This,fEnable)	\
    ( (This)->lpVtbl -> ZeroAdjustTimestamps(This,fEnable) ) 

#define IWMDRMTranscryptor2_GetSeekStartTime(This,pcnsTime)	\
    ( (This)->lpVtbl -> GetSeekStartTime(This,pcnsTime) ) 

#define IWMDRMTranscryptor2_GetDuration(This,pcnsDuration)	\
    ( (This)->lpVtbl -> GetDuration(This,pcnsDuration) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDRMTranscryptor2_INTERFACE_DEFINED__ */


#ifndef __IWMDRMTranscryptionManager_INTERFACE_DEFINED__
#define __IWMDRMTranscryptionManager_INTERFACE_DEFINED__

/* interface IWMDRMTranscryptionManager */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMDRMTranscryptionManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b1a887b2-a4f0-407a-b02e-efbd23bbecdf")
    IWMDRMTranscryptionManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateTranscryptor( 
            /* [annotation][out] */ 
            _Out_  IWMDRMTranscryptor **ppTranscryptor) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMDRMTranscryptionManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMDRMTranscryptionManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMDRMTranscryptionManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMDRMTranscryptionManager * This);
        
        DECLSPEC_XFGVIRT(IWMDRMTranscryptionManager, CreateTranscryptor)
        HRESULT ( STDMETHODCALLTYPE *CreateTranscryptor )( 
            IWMDRMTranscryptionManager * This,
            /* [annotation][out] */ 
            _Out_  IWMDRMTranscryptor **ppTranscryptor);
        
        END_INTERFACE
    } IWMDRMTranscryptionManagerVtbl;

    interface IWMDRMTranscryptionManager
    {
        CONST_VTBL struct IWMDRMTranscryptionManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMDRMTranscryptionManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMDRMTranscryptionManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMDRMTranscryptionManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMDRMTranscryptionManager_CreateTranscryptor(This,ppTranscryptor)	\
    ( (This)->lpVtbl -> CreateTranscryptor(This,ppTranscryptor) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMDRMTranscryptionManager_INTERFACE_DEFINED__ */


#ifndef __IWMWatermarkInfo_INTERFACE_DEFINED__
#define __IWMWatermarkInfo_INTERFACE_DEFINED__

/* interface IWMWatermarkInfo */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMWatermarkInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6f497062-f2e2-4624-8ea7-9dd40d81fc8d")
    IWMWatermarkInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetWatermarkEntryCount( 
            /* [annotation][in] */ 
            _In_  WMT_WATERMARK_ENTRY_TYPE wmetType,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWatermarkEntry( 
            /* [annotation][in] */ 
            _In_  WMT_WATERMARK_ENTRY_TYPE wmetType,
            /* [annotation][in] */ 
            _In_  DWORD dwEntryNum,
            /* [annotation][out] */ 
            _Out_  WMT_WATERMARK_ENTRY *pEntry) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMWatermarkInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMWatermarkInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMWatermarkInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMWatermarkInfo * This);
        
        DECLSPEC_XFGVIRT(IWMWatermarkInfo, GetWatermarkEntryCount)
        HRESULT ( STDMETHODCALLTYPE *GetWatermarkEntryCount )( 
            IWMWatermarkInfo * This,
            /* [annotation][in] */ 
            _In_  WMT_WATERMARK_ENTRY_TYPE wmetType,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCount);
        
        DECLSPEC_XFGVIRT(IWMWatermarkInfo, GetWatermarkEntry)
        HRESULT ( STDMETHODCALLTYPE *GetWatermarkEntry )( 
            IWMWatermarkInfo * This,
            /* [annotation][in] */ 
            _In_  WMT_WATERMARK_ENTRY_TYPE wmetType,
            /* [annotation][in] */ 
            _In_  DWORD dwEntryNum,
            /* [annotation][out] */ 
            _Out_  WMT_WATERMARK_ENTRY *pEntry);
        
        END_INTERFACE
    } IWMWatermarkInfoVtbl;

    interface IWMWatermarkInfo
    {
        CONST_VTBL struct IWMWatermarkInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMWatermarkInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMWatermarkInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMWatermarkInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMWatermarkInfo_GetWatermarkEntryCount(This,wmetType,pdwCount)	\
    ( (This)->lpVtbl -> GetWatermarkEntryCount(This,wmetType,pdwCount) ) 

#define IWMWatermarkInfo_GetWatermarkEntry(This,wmetType,dwEntryNum,pEntry)	\
    ( (This)->lpVtbl -> GetWatermarkEntry(This,wmetType,dwEntryNum,pEntry) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMWatermarkInfo_INTERFACE_DEFINED__ */


#ifndef __IWMReaderAccelerator_INTERFACE_DEFINED__
#define __IWMReaderAccelerator_INTERFACE_DEFINED__

/* interface IWMReaderAccelerator */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderAccelerator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BDDC4D08-944D-4d52-A612-46C3FDA07DD4")
    IWMReaderAccelerator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCodecInterface( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Out_  void **ppvCodecInterface) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Notify( 
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  WM_MEDIA_TYPE *pSubtype) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderAcceleratorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderAccelerator * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderAccelerator * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderAccelerator * This);
        
        DECLSPEC_XFGVIRT(IWMReaderAccelerator, GetCodecInterface)
        HRESULT ( STDMETHODCALLTYPE *GetCodecInterface )( 
            IWMReaderAccelerator * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Out_  void **ppvCodecInterface);
        
        DECLSPEC_XFGVIRT(IWMReaderAccelerator, Notify)
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            IWMReaderAccelerator * This,
            /* [annotation][in] */ 
            _In_  DWORD dwOutputNum,
            /* [annotation][in] */ 
            _In_  WM_MEDIA_TYPE *pSubtype);
        
        END_INTERFACE
    } IWMReaderAcceleratorVtbl;

    interface IWMReaderAccelerator
    {
        CONST_VTBL struct IWMReaderAcceleratorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderAccelerator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderAccelerator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderAccelerator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderAccelerator_GetCodecInterface(This,dwOutputNum,riid,ppvCodecInterface)	\
    ( (This)->lpVtbl -> GetCodecInterface(This,dwOutputNum,riid,ppvCodecInterface) ) 

#define IWMReaderAccelerator_Notify(This,dwOutputNum,pSubtype)	\
    ( (This)->lpVtbl -> Notify(This,dwOutputNum,pSubtype) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderAccelerator_INTERFACE_DEFINED__ */


#ifndef __IWMReaderTimecode_INTERFACE_DEFINED__
#define __IWMReaderTimecode_INTERFACE_DEFINED__

/* interface IWMReaderTimecode */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMReaderTimecode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f369e2f0-e081-4fe6-8450-b810b2f410d1")
    IWMReaderTimecode : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTimecodeRangeCount( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwRangeCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimecodeRangeBounds( 
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WORD wRangeNum,
            /* [annotation][out] */ 
            _Out_  DWORD *pStartTimecode,
            /* [annotation][out] */ 
            _Out_  DWORD *pEndTimecode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMReaderTimecodeVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMReaderTimecode * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMReaderTimecode * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMReaderTimecode * This);
        
        DECLSPEC_XFGVIRT(IWMReaderTimecode, GetTimecodeRangeCount)
        HRESULT ( STDMETHODCALLTYPE *GetTimecodeRangeCount )( 
            IWMReaderTimecode * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][out] */ 
            _Out_  WORD *pwRangeCount);
        
        DECLSPEC_XFGVIRT(IWMReaderTimecode, GetTimecodeRangeBounds)
        HRESULT ( STDMETHODCALLTYPE *GetTimecodeRangeBounds )( 
            IWMReaderTimecode * This,
            /* [annotation][in] */ 
            _In_  WORD wStreamNum,
            /* [annotation][in] */ 
            _In_  WORD wRangeNum,
            /* [annotation][out] */ 
            _Out_  DWORD *pStartTimecode,
            /* [annotation][out] */ 
            _Out_  DWORD *pEndTimecode);
        
        END_INTERFACE
    } IWMReaderTimecodeVtbl;

    interface IWMReaderTimecode
    {
        CONST_VTBL struct IWMReaderTimecodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMReaderTimecode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMReaderTimecode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMReaderTimecode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMReaderTimecode_GetTimecodeRangeCount(This,wStreamNum,pwRangeCount)	\
    ( (This)->lpVtbl -> GetTimecodeRangeCount(This,wStreamNum,pwRangeCount) ) 

#define IWMReaderTimecode_GetTimecodeRangeBounds(This,wStreamNum,wRangeNum,pStartTimecode,pEndTimecode)	\
    ( (This)->lpVtbl -> GetTimecodeRangeBounds(This,wStreamNum,wRangeNum,pStartTimecode,pEndTimecode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMReaderTimecode_INTERFACE_DEFINED__ */


#ifndef __IWMAddressAccess_INTERFACE_DEFINED__
#define __IWMAddressAccess_INTERFACE_DEFINED__

/* interface IWMAddressAccess */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMAddressAccess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BB3C6389-1633-4e92-AF14-9F3173BA39D0")
    IWMAddressAccess : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAccessEntryCount( 
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][out] */ 
            _Out_  DWORD *pcEntries) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAccessEntry( 
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  DWORD dwEntryNum,
            /* [annotation][out] */ 
            _Out_  WM_ADDRESS_ACCESSENTRY *pAddrAccessEntry) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddAccessEntry( 
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  WM_ADDRESS_ACCESSENTRY *pAddrAccessEntry) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAccessEntry( 
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  DWORD dwEntryNum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMAddressAccessVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMAddressAccess * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMAddressAccess * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMAddressAccess * This);
        
        DECLSPEC_XFGVIRT(IWMAddressAccess, GetAccessEntryCount)
        HRESULT ( STDMETHODCALLTYPE *GetAccessEntryCount )( 
            IWMAddressAccess * This,
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][out] */ 
            _Out_  DWORD *pcEntries);
        
        DECLSPEC_XFGVIRT(IWMAddressAccess, GetAccessEntry)
        HRESULT ( STDMETHODCALLTYPE *GetAccessEntry )( 
            IWMAddressAccess * This,
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  DWORD dwEntryNum,
            /* [annotation][out] */ 
            _Out_  WM_ADDRESS_ACCESSENTRY *pAddrAccessEntry);
        
        DECLSPEC_XFGVIRT(IWMAddressAccess, AddAccessEntry)
        HRESULT ( STDMETHODCALLTYPE *AddAccessEntry )( 
            IWMAddressAccess * This,
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  WM_ADDRESS_ACCESSENTRY *pAddrAccessEntry);
        
        DECLSPEC_XFGVIRT(IWMAddressAccess, RemoveAccessEntry)
        HRESULT ( STDMETHODCALLTYPE *RemoveAccessEntry )( 
            IWMAddressAccess * This,
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  DWORD dwEntryNum);
        
        END_INTERFACE
    } IWMAddressAccessVtbl;

    interface IWMAddressAccess
    {
        CONST_VTBL struct IWMAddressAccessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMAddressAccess_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMAddressAccess_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMAddressAccess_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMAddressAccess_GetAccessEntryCount(This,aeType,pcEntries)	\
    ( (This)->lpVtbl -> GetAccessEntryCount(This,aeType,pcEntries) ) 

#define IWMAddressAccess_GetAccessEntry(This,aeType,dwEntryNum,pAddrAccessEntry)	\
    ( (This)->lpVtbl -> GetAccessEntry(This,aeType,dwEntryNum,pAddrAccessEntry) ) 

#define IWMAddressAccess_AddAccessEntry(This,aeType,pAddrAccessEntry)	\
    ( (This)->lpVtbl -> AddAccessEntry(This,aeType,pAddrAccessEntry) ) 

#define IWMAddressAccess_RemoveAccessEntry(This,aeType,dwEntryNum)	\
    ( (This)->lpVtbl -> RemoveAccessEntry(This,aeType,dwEntryNum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMAddressAccess_INTERFACE_DEFINED__ */


#ifndef __IWMAddressAccess2_INTERFACE_DEFINED__
#define __IWMAddressAccess2_INTERFACE_DEFINED__

/* interface IWMAddressAccess2 */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMAddressAccess2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("65a83fc2-3e98-4d4d-81b5-2a742886b33d")
    IWMAddressAccess2 : public IWMAddressAccess
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAccessEntryEx( 
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  DWORD dwEntryNum,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrAddress,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddAccessEntryEx( 
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  BSTR bstrAddress,
            /* [annotation][in] */ 
            _In_  BSTR bstrMask) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMAddressAccess2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMAddressAccess2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMAddressAccess2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMAddressAccess2 * This);
        
        DECLSPEC_XFGVIRT(IWMAddressAccess, GetAccessEntryCount)
        HRESULT ( STDMETHODCALLTYPE *GetAccessEntryCount )( 
            IWMAddressAccess2 * This,
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][out] */ 
            _Out_  DWORD *pcEntries);
        
        DECLSPEC_XFGVIRT(IWMAddressAccess, GetAccessEntry)
        HRESULT ( STDMETHODCALLTYPE *GetAccessEntry )( 
            IWMAddressAccess2 * This,
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  DWORD dwEntryNum,
            /* [annotation][out] */ 
            _Out_  WM_ADDRESS_ACCESSENTRY *pAddrAccessEntry);
        
        DECLSPEC_XFGVIRT(IWMAddressAccess, AddAccessEntry)
        HRESULT ( STDMETHODCALLTYPE *AddAccessEntry )( 
            IWMAddressAccess2 * This,
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  WM_ADDRESS_ACCESSENTRY *pAddrAccessEntry);
        
        DECLSPEC_XFGVIRT(IWMAddressAccess, RemoveAccessEntry)
        HRESULT ( STDMETHODCALLTYPE *RemoveAccessEntry )( 
            IWMAddressAccess2 * This,
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  DWORD dwEntryNum);
        
        DECLSPEC_XFGVIRT(IWMAddressAccess2, GetAccessEntryEx)
        HRESULT ( STDMETHODCALLTYPE *GetAccessEntryEx )( 
            IWMAddressAccess2 * This,
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  DWORD dwEntryNum,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrAddress,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrMask);
        
        DECLSPEC_XFGVIRT(IWMAddressAccess2, AddAccessEntryEx)
        HRESULT ( STDMETHODCALLTYPE *AddAccessEntryEx )( 
            IWMAddressAccess2 * This,
            /* [annotation][in] */ 
            _In_  WM_AETYPE aeType,
            /* [annotation][in] */ 
            _In_  BSTR bstrAddress,
            /* [annotation][in] */ 
            _In_  BSTR bstrMask);
        
        END_INTERFACE
    } IWMAddressAccess2Vtbl;

    interface IWMAddressAccess2
    {
        CONST_VTBL struct IWMAddressAccess2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMAddressAccess2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMAddressAccess2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMAddressAccess2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMAddressAccess2_GetAccessEntryCount(This,aeType,pcEntries)	\
    ( (This)->lpVtbl -> GetAccessEntryCount(This,aeType,pcEntries) ) 

#define IWMAddressAccess2_GetAccessEntry(This,aeType,dwEntryNum,pAddrAccessEntry)	\
    ( (This)->lpVtbl -> GetAccessEntry(This,aeType,dwEntryNum,pAddrAccessEntry) ) 

#define IWMAddressAccess2_AddAccessEntry(This,aeType,pAddrAccessEntry)	\
    ( (This)->lpVtbl -> AddAccessEntry(This,aeType,pAddrAccessEntry) ) 

#define IWMAddressAccess2_RemoveAccessEntry(This,aeType,dwEntryNum)	\
    ( (This)->lpVtbl -> RemoveAccessEntry(This,aeType,dwEntryNum) ) 


#define IWMAddressAccess2_GetAccessEntryEx(This,aeType,dwEntryNum,pbstrAddress,pbstrMask)	\
    ( (This)->lpVtbl -> GetAccessEntryEx(This,aeType,dwEntryNum,pbstrAddress,pbstrMask) ) 

#define IWMAddressAccess2_AddAccessEntryEx(This,aeType,bstrAddress,bstrMask)	\
    ( (This)->lpVtbl -> AddAccessEntryEx(This,aeType,bstrAddress,bstrMask) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMAddressAccess2_INTERFACE_DEFINED__ */


#ifndef __IWMImageInfo_INTERFACE_DEFINED__
#define __IWMImageInfo_INTERFACE_DEFINED__

/* interface IWMImageInfo */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMImageInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9F0AA3B6-7267-4d89-88F2-BA915AA5C4C6")
    IWMImageInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetImageCount( 
            /* [annotation][out] */ 
            _Out_  DWORD *pcImages) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetImage( 
            /* [annotation][in] */ 
            _In_  DWORD wIndex,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchMIMEType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchMIMEType)  WCHAR *pwszMIMEType,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchDescription,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDescription)  WCHAR *pwszDescription,
            /* [annotation][out] */ 
            _Out_  WORD *pImageType,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbImageData,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbImageData)  BYTE *pbImageData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMImageInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMImageInfo * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMImageInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMImageInfo * This);
        
        DECLSPEC_XFGVIRT(IWMImageInfo, GetImageCount)
        HRESULT ( STDMETHODCALLTYPE *GetImageCount )( 
            IWMImageInfo * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pcImages);
        
        DECLSPEC_XFGVIRT(IWMImageInfo, GetImage)
        HRESULT ( STDMETHODCALLTYPE *GetImage )( 
            IWMImageInfo * This,
            /* [annotation][in] */ 
            _In_  DWORD wIndex,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchMIMEType,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchMIMEType)  WCHAR *pwszMIMEType,
            /* [annotation][out][in] */ 
            _Inout_  WORD *pcchDescription,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcchDescription)  WCHAR *pwszDescription,
            /* [annotation][out] */ 
            _Out_  WORD *pImageType,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pcbImageData,
            /* [annotation][size_is][out] */ 
            _Out_writes_(*pcbImageData)  BYTE *pbImageData);
        
        END_INTERFACE
    } IWMImageInfoVtbl;

    interface IWMImageInfo
    {
        CONST_VTBL struct IWMImageInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMImageInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMImageInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMImageInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMImageInfo_GetImageCount(This,pcImages)	\
    ( (This)->lpVtbl -> GetImageCount(This,pcImages) ) 

#define IWMImageInfo_GetImage(This,wIndex,pcchMIMEType,pwszMIMEType,pcchDescription,pwszDescription,pImageType,pcbImageData,pbImageData)	\
    ( (This)->lpVtbl -> GetImage(This,wIndex,pcchMIMEType,pwszMIMEType,pcchDescription,pwszDescription,pImageType,pcbImageData,pbImageData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMImageInfo_INTERFACE_DEFINED__ */


#ifndef __IWMLicenseRevocationAgent_INTERFACE_DEFINED__
#define __IWMLicenseRevocationAgent_INTERFACE_DEFINED__

/* interface IWMLicenseRevocationAgent */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWMLicenseRevocationAgent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6967F2C9-4E26-4b57-8894-799880F7AC7B")
    IWMLicenseRevocationAgent : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLRBChallenge( 
            /* [annotation][in] */ 
            _In_  BYTE *pMachineID,
            /* [annotation][in] */ 
            _In_  DWORD dwMachineIDLength,
            /* [annotation][in] */ 
            _In_  BYTE *pChallenge,
            /* [annotation][in] */ 
            _In_  DWORD dwChallengeLength,
            /* [annotation][out] */ 
            _Out_  BYTE *pChallengeOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwChallengeOutputLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessLRB( 
            /* [annotation][in] */ 
            _In_  BYTE *pSignedLRB,
            /* [annotation][in] */ 
            _In_  DWORD dwSignedLRBLength,
            /* [annotation][out] */ 
            _Out_  BYTE *pSignedACK,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwSignedACKLength) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWMLicenseRevocationAgentVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMLicenseRevocationAgent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMLicenseRevocationAgent * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMLicenseRevocationAgent * This);
        
        DECLSPEC_XFGVIRT(IWMLicenseRevocationAgent, GetLRBChallenge)
        HRESULT ( STDMETHODCALLTYPE *GetLRBChallenge )( 
            IWMLicenseRevocationAgent * This,
            /* [annotation][in] */ 
            _In_  BYTE *pMachineID,
            /* [annotation][in] */ 
            _In_  DWORD dwMachineIDLength,
            /* [annotation][in] */ 
            _In_  BYTE *pChallenge,
            /* [annotation][in] */ 
            _In_  DWORD dwChallengeLength,
            /* [annotation][out] */ 
            _Out_  BYTE *pChallengeOutput,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwChallengeOutputLength);
        
        DECLSPEC_XFGVIRT(IWMLicenseRevocationAgent, ProcessLRB)
        HRESULT ( STDMETHODCALLTYPE *ProcessLRB )( 
            IWMLicenseRevocationAgent * This,
            /* [annotation][in] */ 
            _In_  BYTE *pSignedLRB,
            /* [annotation][in] */ 
            _In_  DWORD dwSignedLRBLength,
            /* [annotation][out] */ 
            _Out_  BYTE *pSignedACK,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwSignedACKLength);
        
        END_INTERFACE
    } IWMLicenseRevocationAgentVtbl;

    interface IWMLicenseRevocationAgent
    {
        CONST_VTBL struct IWMLicenseRevocationAgentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMLicenseRevocationAgent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWMLicenseRevocationAgent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWMLicenseRevocationAgent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWMLicenseRevocationAgent_GetLRBChallenge(This,pMachineID,dwMachineIDLength,pChallenge,dwChallengeLength,pChallengeOutput,pdwChallengeOutputLength)	\
    ( (This)->lpVtbl -> GetLRBChallenge(This,pMachineID,dwMachineIDLength,pChallenge,dwChallengeLength,pChallengeOutput,pdwChallengeOutputLength) ) 

#define IWMLicenseRevocationAgent_ProcessLRB(This,pSignedLRB,dwSignedLRBLength,pSignedACK,pdwSignedACKLength)	\
    ( (This)->lpVtbl -> ProcessLRB(This,pSignedLRB,dwSignedLRBLength,pSignedACK,pdwSignedACKLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWMLicenseRevocationAgent_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_wmsdkidl_0000_0093 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_wmsdkidl_0000_0093_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wmsdkidl_0000_0093_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



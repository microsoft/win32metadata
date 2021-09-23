

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
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

#ifndef __audioclient_h__
#define __audioclient_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAudioClient_FWD_DEFINED__
#define __IAudioClient_FWD_DEFINED__
typedef interface IAudioClient IAudioClient;

#endif 	/* __IAudioClient_FWD_DEFINED__ */


#ifndef __IAudioClient2_FWD_DEFINED__
#define __IAudioClient2_FWD_DEFINED__
typedef interface IAudioClient2 IAudioClient2;

#endif 	/* __IAudioClient2_FWD_DEFINED__ */


#ifndef __IAudioClient3_FWD_DEFINED__
#define __IAudioClient3_FWD_DEFINED__
typedef interface IAudioClient3 IAudioClient3;

#endif 	/* __IAudioClient3_FWD_DEFINED__ */


#ifndef __IAudioRenderClient_FWD_DEFINED__
#define __IAudioRenderClient_FWD_DEFINED__
typedef interface IAudioRenderClient IAudioRenderClient;

#endif 	/* __IAudioRenderClient_FWD_DEFINED__ */


#ifndef __IAudioCaptureClient_FWD_DEFINED__
#define __IAudioCaptureClient_FWD_DEFINED__
typedef interface IAudioCaptureClient IAudioCaptureClient;

#endif 	/* __IAudioCaptureClient_FWD_DEFINED__ */


#ifndef __IAudioClock_FWD_DEFINED__
#define __IAudioClock_FWD_DEFINED__
typedef interface IAudioClock IAudioClock;

#endif 	/* __IAudioClock_FWD_DEFINED__ */


#ifndef __IAudioClock2_FWD_DEFINED__
#define __IAudioClock2_FWD_DEFINED__
typedef interface IAudioClock2 IAudioClock2;

#endif 	/* __IAudioClock2_FWD_DEFINED__ */


#ifndef __IAudioClockAdjustment_FWD_DEFINED__
#define __IAudioClockAdjustment_FWD_DEFINED__
typedef interface IAudioClockAdjustment IAudioClockAdjustment;

#endif 	/* __IAudioClockAdjustment_FWD_DEFINED__ */


#ifndef __ISimpleAudioVolume_FWD_DEFINED__
#define __ISimpleAudioVolume_FWD_DEFINED__
typedef interface ISimpleAudioVolume ISimpleAudioVolume;

#endif 	/* __ISimpleAudioVolume_FWD_DEFINED__ */


#ifndef __IAudioStreamVolume_FWD_DEFINED__
#define __IAudioStreamVolume_FWD_DEFINED__
typedef interface IAudioStreamVolume IAudioStreamVolume;

#endif 	/* __IAudioStreamVolume_FWD_DEFINED__ */


#ifndef __IAudioAmbisonicsControl_FWD_DEFINED__
#define __IAudioAmbisonicsControl_FWD_DEFINED__
typedef interface IAudioAmbisonicsControl IAudioAmbisonicsControl;

#endif 	/* __IAudioAmbisonicsControl_FWD_DEFINED__ */


#ifndef __IChannelAudioVolume_FWD_DEFINED__
#define __IChannelAudioVolume_FWD_DEFINED__
typedef interface IChannelAudioVolume IChannelAudioVolume;

#endif 	/* __IChannelAudioVolume_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "unknwn.h"
#include "mmreg.h"
#include "AudioSessionTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_audioclient_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#if 0
typedef /* [hidden][restricted] */ LONGLONG REFERENCE_TIME;

#else
#ifndef _SkipIksIncludes_
#define _IKsControl_
#include <ks.h>
#include <ksmedia.h>
#endif
#endif
#pragma region Application and Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES)

enum _AUDCLNT_BUFFERFLAGS
    {
        AUDCLNT_BUFFERFLAGS_DATA_DISCONTINUITY	= 0x1,
        AUDCLNT_BUFFERFLAGS_SILENT	= 0x2,
        AUDCLNT_BUFFERFLAGS_TIMESTAMP_ERROR	= 0x4
    } ;
typedef /* [v1_enum] */ 
enum AUDCLNT_STREAMOPTIONS
    {
        AUDCLNT_STREAMOPTIONS_NONE	= 0,
        AUDCLNT_STREAMOPTIONS_RAW	= 0x1,
        AUDCLNT_STREAMOPTIONS_MATCH_FORMAT	= 0x2,
        AUDCLNT_STREAMOPTIONS_AMBISONICS	= 0x4
    } 	AUDCLNT_STREAMOPTIONS;

DEFINE_ENUM_FLAG_OPERATORS(AUDCLNT_STREAMOPTIONS);
#if (NTDDI_VERSION < NTDDI_WINBLUE) 
typedef struct AudioClientProperties
{
    UINT32                  cbSize;
    BOOL                    bIsOffload;
    AUDIO_STREAM_CATEGORY   eCategory;
} AudioClientProperties;
#else
typedef struct AudioClientProperties
    {
    UINT32 cbSize;
    BOOL bIsOffload;
    AUDIO_STREAM_CATEGORY eCategory;
    AUDCLNT_STREAMOPTIONS Options;
    } 	AudioClientProperties;

#endif


extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0000_v0_0_s_ifspec;

#ifndef __IAudioClient_INTERFACE_DEFINED__
#define __IAudioClient_INTERFACE_DEFINED__

/* interface IAudioClient */
/* [local][unique][uuid][object] */ 


EXTERN_C const IID IID_IAudioClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1CB9AD4C-DBFA-4c32-B178-C2F568A703B2")
    IAudioClient : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  AUDCLNT_SHAREMODE ShareMode,
            /* [annotation][in] */ 
            _In_  DWORD StreamFlags,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME hnsBufferDuration,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME hnsPeriodicity,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [annotation][in] */ 
            _In_opt_  LPCGUID AudioSessionGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBufferSize( 
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumBufferFrames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStreamLatency( 
            /* [annotation][out] */ 
            _Out_  REFERENCE_TIME *phnsLatency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentPadding( 
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumPaddingFrames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsFormatSupported( 
            /* [annotation][in] */ 
            _In_  AUDCLNT_SHAREMODE ShareMode,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [unique][annotation][out] */ 
            _Out_opt_  WAVEFORMATEX **ppClosestMatch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMixFormat( 
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppDeviceFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDevicePeriod( 
            /* [annotation][out] */ 
            _Out_opt_  REFERENCE_TIME *phnsDefaultDevicePeriod,
            /* [annotation][out] */ 
            _Out_opt_  REFERENCE_TIME *phnsMinimumDevicePeriod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEventHandle( 
            /* [annotation][in] */ 
            _In_  HANDLE eventHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetService( 
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _Out_  void **ppv) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioClient * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IAudioClient * This,
            /* [annotation][in] */ 
            _In_  AUDCLNT_SHAREMODE ShareMode,
            /* [annotation][in] */ 
            _In_  DWORD StreamFlags,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME hnsBufferDuration,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME hnsPeriodicity,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [annotation][in] */ 
            _In_opt_  LPCGUID AudioSessionGuid);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferSize )( 
            IAudioClient * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumBufferFrames);
        
        HRESULT ( STDMETHODCALLTYPE *GetStreamLatency )( 
            IAudioClient * This,
            /* [annotation][out] */ 
            _Out_  REFERENCE_TIME *phnsLatency);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentPadding )( 
            IAudioClient * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumPaddingFrames);
        
        HRESULT ( STDMETHODCALLTYPE *IsFormatSupported )( 
            IAudioClient * This,
            /* [annotation][in] */ 
            _In_  AUDCLNT_SHAREMODE ShareMode,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [unique][annotation][out] */ 
            _Out_opt_  WAVEFORMATEX **ppClosestMatch);
        
        HRESULT ( STDMETHODCALLTYPE *GetMixFormat )( 
            IAudioClient * This,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppDeviceFormat);
        
        HRESULT ( STDMETHODCALLTYPE *GetDevicePeriod )( 
            IAudioClient * This,
            /* [annotation][out] */ 
            _Out_opt_  REFERENCE_TIME *phnsDefaultDevicePeriod,
            /* [annotation][out] */ 
            _Out_opt_  REFERENCE_TIME *phnsMinimumDevicePeriod);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IAudioClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IAudioClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IAudioClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetEventHandle )( 
            IAudioClient * This,
            /* [annotation][in] */ 
            _In_  HANDLE eventHandle);
        
        HRESULT ( STDMETHODCALLTYPE *GetService )( 
            IAudioClient * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _Out_  void **ppv);
        
        END_INTERFACE
    } IAudioClientVtbl;

    interface IAudioClient
    {
        CONST_VTBL struct IAudioClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioClient_Initialize(This,ShareMode,StreamFlags,hnsBufferDuration,hnsPeriodicity,pFormat,AudioSessionGuid)	\
    ( (This)->lpVtbl -> Initialize(This,ShareMode,StreamFlags,hnsBufferDuration,hnsPeriodicity,pFormat,AudioSessionGuid) ) 

#define IAudioClient_GetBufferSize(This,pNumBufferFrames)	\
    ( (This)->lpVtbl -> GetBufferSize(This,pNumBufferFrames) ) 

#define IAudioClient_GetStreamLatency(This,phnsLatency)	\
    ( (This)->lpVtbl -> GetStreamLatency(This,phnsLatency) ) 

#define IAudioClient_GetCurrentPadding(This,pNumPaddingFrames)	\
    ( (This)->lpVtbl -> GetCurrentPadding(This,pNumPaddingFrames) ) 

#define IAudioClient_IsFormatSupported(This,ShareMode,pFormat,ppClosestMatch)	\
    ( (This)->lpVtbl -> IsFormatSupported(This,ShareMode,pFormat,ppClosestMatch) ) 

#define IAudioClient_GetMixFormat(This,ppDeviceFormat)	\
    ( (This)->lpVtbl -> GetMixFormat(This,ppDeviceFormat) ) 

#define IAudioClient_GetDevicePeriod(This,phnsDefaultDevicePeriod,phnsMinimumDevicePeriod)	\
    ( (This)->lpVtbl -> GetDevicePeriod(This,phnsDefaultDevicePeriod,phnsMinimumDevicePeriod) ) 

#define IAudioClient_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IAudioClient_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IAudioClient_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IAudioClient_SetEventHandle(This,eventHandle)	\
    ( (This)->lpVtbl -> SetEventHandle(This,eventHandle) ) 

#define IAudioClient_GetService(This,riid,ppv)	\
    ( (This)->lpVtbl -> GetService(This,riid,ppv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioClient_INTERFACE_DEFINED__ */


#ifndef __IAudioClient2_INTERFACE_DEFINED__
#define __IAudioClient2_INTERFACE_DEFINED__

/* interface IAudioClient2 */
/* [local][unique][uuid][object] */ 


EXTERN_C const IID IID_IAudioClient2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("726778CD-F60A-4eda-82DE-E47610CD78AA")
    IAudioClient2 : public IAudioClient
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsOffloadCapable( 
            /* [annotation][in] */ 
            _In_  AUDIO_STREAM_CATEGORY Category,
            /* [annotation][out] */ 
            _Out_  BOOL *pbOffloadCapable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetClientProperties( 
            /* [annotation][in] */ 
            _In_  const AudioClientProperties *pProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBufferSizeLimits( 
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [annotation][in] */ 
            _In_  BOOL bEventDriven,
            /* [annotation][out] */ 
            _Out_  REFERENCE_TIME *phnsMinBufferDuration,
            /* [annotation][out] */ 
            _Out_  REFERENCE_TIME *phnsMaxBufferDuration) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioClient2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioClient2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioClient2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioClient2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IAudioClient2 * This,
            /* [annotation][in] */ 
            _In_  AUDCLNT_SHAREMODE ShareMode,
            /* [annotation][in] */ 
            _In_  DWORD StreamFlags,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME hnsBufferDuration,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME hnsPeriodicity,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [annotation][in] */ 
            _In_opt_  LPCGUID AudioSessionGuid);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferSize )( 
            IAudioClient2 * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumBufferFrames);
        
        HRESULT ( STDMETHODCALLTYPE *GetStreamLatency )( 
            IAudioClient2 * This,
            /* [annotation][out] */ 
            _Out_  REFERENCE_TIME *phnsLatency);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentPadding )( 
            IAudioClient2 * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumPaddingFrames);
        
        HRESULT ( STDMETHODCALLTYPE *IsFormatSupported )( 
            IAudioClient2 * This,
            /* [annotation][in] */ 
            _In_  AUDCLNT_SHAREMODE ShareMode,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [unique][annotation][out] */ 
            _Out_opt_  WAVEFORMATEX **ppClosestMatch);
        
        HRESULT ( STDMETHODCALLTYPE *GetMixFormat )( 
            IAudioClient2 * This,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppDeviceFormat);
        
        HRESULT ( STDMETHODCALLTYPE *GetDevicePeriod )( 
            IAudioClient2 * This,
            /* [annotation][out] */ 
            _Out_opt_  REFERENCE_TIME *phnsDefaultDevicePeriod,
            /* [annotation][out] */ 
            _Out_opt_  REFERENCE_TIME *phnsMinimumDevicePeriod);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IAudioClient2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IAudioClient2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IAudioClient2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetEventHandle )( 
            IAudioClient2 * This,
            /* [annotation][in] */ 
            _In_  HANDLE eventHandle);
        
        HRESULT ( STDMETHODCALLTYPE *GetService )( 
            IAudioClient2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _Out_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *IsOffloadCapable )( 
            IAudioClient2 * This,
            /* [annotation][in] */ 
            _In_  AUDIO_STREAM_CATEGORY Category,
            /* [annotation][out] */ 
            _Out_  BOOL *pbOffloadCapable);
        
        HRESULT ( STDMETHODCALLTYPE *SetClientProperties )( 
            IAudioClient2 * This,
            /* [annotation][in] */ 
            _In_  const AudioClientProperties *pProperties);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferSizeLimits )( 
            IAudioClient2 * This,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [annotation][in] */ 
            _In_  BOOL bEventDriven,
            /* [annotation][out] */ 
            _Out_  REFERENCE_TIME *phnsMinBufferDuration,
            /* [annotation][out] */ 
            _Out_  REFERENCE_TIME *phnsMaxBufferDuration);
        
        END_INTERFACE
    } IAudioClient2Vtbl;

    interface IAudioClient2
    {
        CONST_VTBL struct IAudioClient2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioClient2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioClient2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioClient2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioClient2_Initialize(This,ShareMode,StreamFlags,hnsBufferDuration,hnsPeriodicity,pFormat,AudioSessionGuid)	\
    ( (This)->lpVtbl -> Initialize(This,ShareMode,StreamFlags,hnsBufferDuration,hnsPeriodicity,pFormat,AudioSessionGuid) ) 

#define IAudioClient2_GetBufferSize(This,pNumBufferFrames)	\
    ( (This)->lpVtbl -> GetBufferSize(This,pNumBufferFrames) ) 

#define IAudioClient2_GetStreamLatency(This,phnsLatency)	\
    ( (This)->lpVtbl -> GetStreamLatency(This,phnsLatency) ) 

#define IAudioClient2_GetCurrentPadding(This,pNumPaddingFrames)	\
    ( (This)->lpVtbl -> GetCurrentPadding(This,pNumPaddingFrames) ) 

#define IAudioClient2_IsFormatSupported(This,ShareMode,pFormat,ppClosestMatch)	\
    ( (This)->lpVtbl -> IsFormatSupported(This,ShareMode,pFormat,ppClosestMatch) ) 

#define IAudioClient2_GetMixFormat(This,ppDeviceFormat)	\
    ( (This)->lpVtbl -> GetMixFormat(This,ppDeviceFormat) ) 

#define IAudioClient2_GetDevicePeriod(This,phnsDefaultDevicePeriod,phnsMinimumDevicePeriod)	\
    ( (This)->lpVtbl -> GetDevicePeriod(This,phnsDefaultDevicePeriod,phnsMinimumDevicePeriod) ) 

#define IAudioClient2_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IAudioClient2_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IAudioClient2_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IAudioClient2_SetEventHandle(This,eventHandle)	\
    ( (This)->lpVtbl -> SetEventHandle(This,eventHandle) ) 

#define IAudioClient2_GetService(This,riid,ppv)	\
    ( (This)->lpVtbl -> GetService(This,riid,ppv) ) 


#define IAudioClient2_IsOffloadCapable(This,Category,pbOffloadCapable)	\
    ( (This)->lpVtbl -> IsOffloadCapable(This,Category,pbOffloadCapable) ) 

#define IAudioClient2_SetClientProperties(This,pProperties)	\
    ( (This)->lpVtbl -> SetClientProperties(This,pProperties) ) 

#define IAudioClient2_GetBufferSizeLimits(This,pFormat,bEventDriven,phnsMinBufferDuration,phnsMaxBufferDuration)	\
    ( (This)->lpVtbl -> GetBufferSizeLimits(This,pFormat,bEventDriven,phnsMinBufferDuration,phnsMaxBufferDuration) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioClient2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioclient_0000_0002 */
/* [local] */ 

// AudioClient3ActivationParams is an optional activation parameter for IAudioClient3
//
// IAudioClient3 implementations log various things via ETW tracing
// including a "context" identifier
//
// In situations where there are multiple active audio clients,
// the "tracing context" identifier can ease correlation of which audio client instance belongs to which application context
//
// Sample app code:
// PROPVARIANT var;
// PropVariantInit(&var);
// auto p = reinterpret_cast<AudioClient3ActivationParams *>CoTaskMemAlloc(sizeof(AudioClient3ActivationParams));
// if (nullptr == p) { ... }
// p->tracingContextId = /* app-specific context identifier */;
// var.vt = VT_BLOB;
// var.blob.cbSize = sizeof(*p);
// var.blob.pBlobData = reinterpret_cast<BYTE *>(p);
// hr = ActivateAudioInterfaceAsync(device, __uuidof(IAudioClient3), &var, ...);
// ...
// PropVariantClear(&var);
typedef struct AudioClient3ActivationParams
    {
    GUID tracingContextId;
    } 	AudioClient3ActivationParams;



extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0002_v0_0_s_ifspec;

#ifndef __IAudioClient3_INTERFACE_DEFINED__
#define __IAudioClient3_INTERFACE_DEFINED__

/* interface IAudioClient3 */
/* [local][unique][uuid][object] */ 


EXTERN_C const IID IID_IAudioClient3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7ED4EE07-8E67-4CD4-8C1A-2B7A5987AD42")
    IAudioClient3 : public IAudioClient2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSharedModeEnginePeriod( 
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [annotation][out] */ 
            _Out_  UINT32 *pDefaultPeriodInFrames,
            /* [annotation][out] */ 
            _Out_  UINT32 *pFundamentalPeriodInFrames,
            /* [annotation][out] */ 
            _Out_  UINT32 *pMinPeriodInFrames,
            /* [annotation][out] */ 
            _Out_  UINT32 *pMaxPeriodInFrames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentSharedModeEnginePeriod( 
            /* [unique][annotation][out] */ 
            _Out_  WAVEFORMATEX **ppFormat,
            /* [annotation][out] */ 
            _Out_  UINT32 *pCurrentPeriodInFrames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitializeSharedAudioStream( 
            /* [annotation][in] */ 
            _In_  DWORD StreamFlags,
            /* [annotation][in] */ 
            _In_  UINT32 PeriodInFrames,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [annotation][in] */ 
            _In_opt_  LPCGUID AudioSessionGuid) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioClient3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioClient3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioClient3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioClient3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IAudioClient3 * This,
            /* [annotation][in] */ 
            _In_  AUDCLNT_SHAREMODE ShareMode,
            /* [annotation][in] */ 
            _In_  DWORD StreamFlags,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME hnsBufferDuration,
            /* [annotation][in] */ 
            _In_  REFERENCE_TIME hnsPeriodicity,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [annotation][in] */ 
            _In_opt_  LPCGUID AudioSessionGuid);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferSize )( 
            IAudioClient3 * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumBufferFrames);
        
        HRESULT ( STDMETHODCALLTYPE *GetStreamLatency )( 
            IAudioClient3 * This,
            /* [annotation][out] */ 
            _Out_  REFERENCE_TIME *phnsLatency);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentPadding )( 
            IAudioClient3 * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumPaddingFrames);
        
        HRESULT ( STDMETHODCALLTYPE *IsFormatSupported )( 
            IAudioClient3 * This,
            /* [annotation][in] */ 
            _In_  AUDCLNT_SHAREMODE ShareMode,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [unique][annotation][out] */ 
            _Out_opt_  WAVEFORMATEX **ppClosestMatch);
        
        HRESULT ( STDMETHODCALLTYPE *GetMixFormat )( 
            IAudioClient3 * This,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppDeviceFormat);
        
        HRESULT ( STDMETHODCALLTYPE *GetDevicePeriod )( 
            IAudioClient3 * This,
            /* [annotation][out] */ 
            _Out_opt_  REFERENCE_TIME *phnsDefaultDevicePeriod,
            /* [annotation][out] */ 
            _Out_opt_  REFERENCE_TIME *phnsMinimumDevicePeriod);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IAudioClient3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IAudioClient3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IAudioClient3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetEventHandle )( 
            IAudioClient3 * This,
            /* [annotation][in] */ 
            _In_  HANDLE eventHandle);
        
        HRESULT ( STDMETHODCALLTYPE *GetService )( 
            IAudioClient3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _Out_  void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *IsOffloadCapable )( 
            IAudioClient3 * This,
            /* [annotation][in] */ 
            _In_  AUDIO_STREAM_CATEGORY Category,
            /* [annotation][out] */ 
            _Out_  BOOL *pbOffloadCapable);
        
        HRESULT ( STDMETHODCALLTYPE *SetClientProperties )( 
            IAudioClient3 * This,
            /* [annotation][in] */ 
            _In_  const AudioClientProperties *pProperties);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferSizeLimits )( 
            IAudioClient3 * This,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [annotation][in] */ 
            _In_  BOOL bEventDriven,
            /* [annotation][out] */ 
            _Out_  REFERENCE_TIME *phnsMinBufferDuration,
            /* [annotation][out] */ 
            _Out_  REFERENCE_TIME *phnsMaxBufferDuration);
        
        HRESULT ( STDMETHODCALLTYPE *GetSharedModeEnginePeriod )( 
            IAudioClient3 * This,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [annotation][out] */ 
            _Out_  UINT32 *pDefaultPeriodInFrames,
            /* [annotation][out] */ 
            _Out_  UINT32 *pFundamentalPeriodInFrames,
            /* [annotation][out] */ 
            _Out_  UINT32 *pMinPeriodInFrames,
            /* [annotation][out] */ 
            _Out_  UINT32 *pMaxPeriodInFrames);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentSharedModeEnginePeriod )( 
            IAudioClient3 * This,
            /* [unique][annotation][out] */ 
            _Out_  WAVEFORMATEX **ppFormat,
            /* [annotation][out] */ 
            _Out_  UINT32 *pCurrentPeriodInFrames);
        
        HRESULT ( STDMETHODCALLTYPE *InitializeSharedAudioStream )( 
            IAudioClient3 * This,
            /* [annotation][in] */ 
            _In_  DWORD StreamFlags,
            /* [annotation][in] */ 
            _In_  UINT32 PeriodInFrames,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pFormat,
            /* [annotation][in] */ 
            _In_opt_  LPCGUID AudioSessionGuid);
        
        END_INTERFACE
    } IAudioClient3Vtbl;

    interface IAudioClient3
    {
        CONST_VTBL struct IAudioClient3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioClient3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioClient3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioClient3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioClient3_Initialize(This,ShareMode,StreamFlags,hnsBufferDuration,hnsPeriodicity,pFormat,AudioSessionGuid)	\
    ( (This)->lpVtbl -> Initialize(This,ShareMode,StreamFlags,hnsBufferDuration,hnsPeriodicity,pFormat,AudioSessionGuid) ) 

#define IAudioClient3_GetBufferSize(This,pNumBufferFrames)	\
    ( (This)->lpVtbl -> GetBufferSize(This,pNumBufferFrames) ) 

#define IAudioClient3_GetStreamLatency(This,phnsLatency)	\
    ( (This)->lpVtbl -> GetStreamLatency(This,phnsLatency) ) 

#define IAudioClient3_GetCurrentPadding(This,pNumPaddingFrames)	\
    ( (This)->lpVtbl -> GetCurrentPadding(This,pNumPaddingFrames) ) 

#define IAudioClient3_IsFormatSupported(This,ShareMode,pFormat,ppClosestMatch)	\
    ( (This)->lpVtbl -> IsFormatSupported(This,ShareMode,pFormat,ppClosestMatch) ) 

#define IAudioClient3_GetMixFormat(This,ppDeviceFormat)	\
    ( (This)->lpVtbl -> GetMixFormat(This,ppDeviceFormat) ) 

#define IAudioClient3_GetDevicePeriod(This,phnsDefaultDevicePeriod,phnsMinimumDevicePeriod)	\
    ( (This)->lpVtbl -> GetDevicePeriod(This,phnsDefaultDevicePeriod,phnsMinimumDevicePeriod) ) 

#define IAudioClient3_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IAudioClient3_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IAudioClient3_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IAudioClient3_SetEventHandle(This,eventHandle)	\
    ( (This)->lpVtbl -> SetEventHandle(This,eventHandle) ) 

#define IAudioClient3_GetService(This,riid,ppv)	\
    ( (This)->lpVtbl -> GetService(This,riid,ppv) ) 


#define IAudioClient3_IsOffloadCapable(This,Category,pbOffloadCapable)	\
    ( (This)->lpVtbl -> IsOffloadCapable(This,Category,pbOffloadCapable) ) 

#define IAudioClient3_SetClientProperties(This,pProperties)	\
    ( (This)->lpVtbl -> SetClientProperties(This,pProperties) ) 

#define IAudioClient3_GetBufferSizeLimits(This,pFormat,bEventDriven,phnsMinBufferDuration,phnsMaxBufferDuration)	\
    ( (This)->lpVtbl -> GetBufferSizeLimits(This,pFormat,bEventDriven,phnsMinBufferDuration,phnsMaxBufferDuration) ) 


#define IAudioClient3_GetSharedModeEnginePeriod(This,pFormat,pDefaultPeriodInFrames,pFundamentalPeriodInFrames,pMinPeriodInFrames,pMaxPeriodInFrames)	\
    ( (This)->lpVtbl -> GetSharedModeEnginePeriod(This,pFormat,pDefaultPeriodInFrames,pFundamentalPeriodInFrames,pMinPeriodInFrames,pMaxPeriodInFrames) ) 

#define IAudioClient3_GetCurrentSharedModeEnginePeriod(This,ppFormat,pCurrentPeriodInFrames)	\
    ( (This)->lpVtbl -> GetCurrentSharedModeEnginePeriod(This,ppFormat,pCurrentPeriodInFrames) ) 

#define IAudioClient3_InitializeSharedAudioStream(This,StreamFlags,PeriodInFrames,pFormat,AudioSessionGuid)	\
    ( (This)->lpVtbl -> InitializeSharedAudioStream(This,StreamFlags,PeriodInFrames,pFormat,AudioSessionGuid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioClient3_INTERFACE_DEFINED__ */


#ifndef __IAudioRenderClient_INTERFACE_DEFINED__
#define __IAudioRenderClient_INTERFACE_DEFINED__

/* interface IAudioRenderClient */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAudioRenderClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F294ACFC-3146-4483-A7BF-ADDCA7C260E2")
    IAudioRenderClient : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBuffer( 
            /* [annotation][in] */ 
            _In_  UINT32 NumFramesRequested,
            /* [annotation][out] */ 
            _Outptr_result_buffer_(_Inexpressible_("NumFramesRequested * pFormat->nBlockAlign"))  BYTE **ppData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseBuffer( 
            /* [annotation][in] */ 
            _In_  UINT32 NumFramesWritten,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioRenderClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioRenderClient * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioRenderClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioRenderClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            IAudioRenderClient * This,
            /* [annotation][in] */ 
            _In_  UINT32 NumFramesRequested,
            /* [annotation][out] */ 
            _Outptr_result_buffer_(_Inexpressible_("NumFramesRequested * pFormat->nBlockAlign"))  BYTE **ppData);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseBuffer )( 
            IAudioRenderClient * This,
            /* [annotation][in] */ 
            _In_  UINT32 NumFramesWritten,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        END_INTERFACE
    } IAudioRenderClientVtbl;

    interface IAudioRenderClient
    {
        CONST_VTBL struct IAudioRenderClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioRenderClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioRenderClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioRenderClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioRenderClient_GetBuffer(This,NumFramesRequested,ppData)	\
    ( (This)->lpVtbl -> GetBuffer(This,NumFramesRequested,ppData) ) 

#define IAudioRenderClient_ReleaseBuffer(This,NumFramesWritten,dwFlags)	\
    ( (This)->lpVtbl -> ReleaseBuffer(This,NumFramesWritten,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioRenderClient_INTERFACE_DEFINED__ */


#ifndef __IAudioCaptureClient_INTERFACE_DEFINED__
#define __IAudioCaptureClient_INTERFACE_DEFINED__

/* interface IAudioCaptureClient */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAudioCaptureClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C8ADBD64-E71E-48a0-A4DE-185C395CD317")
    IAudioCaptureClient : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBuffer( 
            /* [annotation][out] */ 
            _Outptr_result_buffer_(_Inexpressible_("*pNumFramesToRead * pFormat->nBlockAlign"))  BYTE **ppData,
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumFramesToRead,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags,
            /* [annotation][unique][out] */ 
            _Out_opt_  UINT64 *pu64DevicePosition,
            /* [annotation][unique][out] */ 
            _Out_opt_  UINT64 *pu64QPCPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseBuffer( 
            /* [annotation][in] */ 
            _In_  UINT32 NumFramesRead) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextPacketSize( 
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumFramesInNextPacket) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioCaptureClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioCaptureClient * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioCaptureClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioCaptureClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            IAudioCaptureClient * This,
            /* [annotation][out] */ 
            _Outptr_result_buffer_(_Inexpressible_("*pNumFramesToRead * pFormat->nBlockAlign"))  BYTE **ppData,
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumFramesToRead,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwFlags,
            /* [annotation][unique][out] */ 
            _Out_opt_  UINT64 *pu64DevicePosition,
            /* [annotation][unique][out] */ 
            _Out_opt_  UINT64 *pu64QPCPosition);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseBuffer )( 
            IAudioCaptureClient * This,
            /* [annotation][in] */ 
            _In_  UINT32 NumFramesRead);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextPacketSize )( 
            IAudioCaptureClient * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pNumFramesInNextPacket);
        
        END_INTERFACE
    } IAudioCaptureClientVtbl;

    interface IAudioCaptureClient
    {
        CONST_VTBL struct IAudioCaptureClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioCaptureClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioCaptureClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioCaptureClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioCaptureClient_GetBuffer(This,ppData,pNumFramesToRead,pdwFlags,pu64DevicePosition,pu64QPCPosition)	\
    ( (This)->lpVtbl -> GetBuffer(This,ppData,pNumFramesToRead,pdwFlags,pu64DevicePosition,pu64QPCPosition) ) 

#define IAudioCaptureClient_ReleaseBuffer(This,NumFramesRead)	\
    ( (This)->lpVtbl -> ReleaseBuffer(This,NumFramesRead) ) 

#define IAudioCaptureClient_GetNextPacketSize(This,pNumFramesInNextPacket)	\
    ( (This)->lpVtbl -> GetNextPacketSize(This,pNumFramesInNextPacket) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioCaptureClient_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioclient_0000_0005 */
/* [local] */ 

#define AUDIOCLOCK_CHARACTERISTIC_FIXED_FREQ  0x00000001


extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0005_v0_0_s_ifspec;

#ifndef __IAudioClock_INTERFACE_DEFINED__
#define __IAudioClock_INTERFACE_DEFINED__

/* interface IAudioClock */
/* [local][unique][uuid][object] */ 


EXTERN_C const IID IID_IAudioClock;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CD63314F-3FBA-4a1b-812C-EF96358728E7")
    IAudioClock : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFrequency( 
            /* [annotation][out] */ 
            _Out_  UINT64 *pu64Frequency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPosition( 
            /* [annotation][out] */ 
            _Out_  UINT64 *pu64Position,
            /* [annotation][unique][out] */ 
            _Out_opt_  UINT64 *pu64QPCPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCharacteristics( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCharacteristics) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioClockVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioClock * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioClock * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioClock * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFrequency )( 
            IAudioClock * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pu64Frequency);
        
        HRESULT ( STDMETHODCALLTYPE *GetPosition )( 
            IAudioClock * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *pu64Position,
            /* [annotation][unique][out] */ 
            _Out_opt_  UINT64 *pu64QPCPosition);
        
        HRESULT ( STDMETHODCALLTYPE *GetCharacteristics )( 
            IAudioClock * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwCharacteristics);
        
        END_INTERFACE
    } IAudioClockVtbl;

    interface IAudioClock
    {
        CONST_VTBL struct IAudioClockVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioClock_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioClock_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioClock_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioClock_GetFrequency(This,pu64Frequency)	\
    ( (This)->lpVtbl -> GetFrequency(This,pu64Frequency) ) 

#define IAudioClock_GetPosition(This,pu64Position,pu64QPCPosition)	\
    ( (This)->lpVtbl -> GetPosition(This,pu64Position,pu64QPCPosition) ) 

#define IAudioClock_GetCharacteristics(This,pdwCharacteristics)	\
    ( (This)->lpVtbl -> GetCharacteristics(This,pdwCharacteristics) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioClock_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioclient_0000_0006 */
/* [local] */ 

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)


extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0006_v0_0_s_ifspec;

#ifndef __IAudioClock2_INTERFACE_DEFINED__
#define __IAudioClock2_INTERFACE_DEFINED__

/* interface IAudioClock2 */
/* [local][unique][uuid][object] */ 


EXTERN_C const IID IID_IAudioClock2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6f49ff73-6727-49ac-a008-d98cf5e70048")
    IAudioClock2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDevicePosition( 
            /* [annotation][out] */ 
            _Out_  UINT64 *DevicePosition,
            /* [annotation][unique][out] */ 
            _Out_opt_  UINT64 *QPCPosition) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioClock2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioClock2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioClock2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioClock2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDevicePosition )( 
            IAudioClock2 * This,
            /* [annotation][out] */ 
            _Out_  UINT64 *DevicePosition,
            /* [annotation][unique][out] */ 
            _Out_opt_  UINT64 *QPCPosition);
        
        END_INTERFACE
    } IAudioClock2Vtbl;

    interface IAudioClock2
    {
        CONST_VTBL struct IAudioClock2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioClock2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioClock2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioClock2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioClock2_GetDevicePosition(This,DevicePosition,QPCPosition)	\
    ( (This)->lpVtbl -> GetDevicePosition(This,DevicePosition,QPCPosition) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioClock2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioclient_0000_0007 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */


extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0007_v0_0_s_ifspec;

#ifndef __IAudioClockAdjustment_INTERFACE_DEFINED__
#define __IAudioClockAdjustment_INTERFACE_DEFINED__

/* interface IAudioClockAdjustment */
/* [object][local][unique][uuid] */ 


EXTERN_C const IID IID_IAudioClockAdjustment;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f6e4c0a0-46d9-4fb8-be21-57a3ef2b626c")
    IAudioClockAdjustment : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetSampleRate( 
            /* [annotation][in] */ 
            _In_  float flSampleRate) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioClockAdjustmentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioClockAdjustment * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioClockAdjustment * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioClockAdjustment * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSampleRate )( 
            IAudioClockAdjustment * This,
            /* [annotation][in] */ 
            _In_  float flSampleRate);
        
        END_INTERFACE
    } IAudioClockAdjustmentVtbl;

    interface IAudioClockAdjustment
    {
        CONST_VTBL struct IAudioClockAdjustmentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioClockAdjustment_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioClockAdjustment_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioClockAdjustment_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioClockAdjustment_SetSampleRate(This,flSampleRate)	\
    ( (This)->lpVtbl -> SetSampleRate(This,flSampleRate) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioClockAdjustment_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioclient_0000_0008 */
/* [local] */ 

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)


extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0008_v0_0_s_ifspec;

#ifndef __ISimpleAudioVolume_INTERFACE_DEFINED__
#define __ISimpleAudioVolume_INTERFACE_DEFINED__

/* interface ISimpleAudioVolume */
/* [local][unique][uuid][object] */ 


EXTERN_C const IID IID_ISimpleAudioVolume;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87CE5498-68D6-44E5-9215-6DA47EF883D8")
    ISimpleAudioVolume : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetMasterVolume( 
            /* [annotation][in] */ 
            _In_  float fLevel,
            /* [unique][in] */ LPCGUID EventContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMasterVolume( 
            /* [annotation][out] */ 
            _Out_  float *pfLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMute( 
            /* [annotation][in] */ 
            _In_  const BOOL bMute,
            /* [unique][in] */ LPCGUID EventContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMute( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbMute) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISimpleAudioVolumeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimpleAudioVolume * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimpleAudioVolume * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimpleAudioVolume * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetMasterVolume )( 
            ISimpleAudioVolume * This,
            /* [annotation][in] */ 
            _In_  float fLevel,
            /* [unique][in] */ LPCGUID EventContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetMasterVolume )( 
            ISimpleAudioVolume * This,
            /* [annotation][out] */ 
            _Out_  float *pfLevel);
        
        HRESULT ( STDMETHODCALLTYPE *SetMute )( 
            ISimpleAudioVolume * This,
            /* [annotation][in] */ 
            _In_  const BOOL bMute,
            /* [unique][in] */ LPCGUID EventContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetMute )( 
            ISimpleAudioVolume * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbMute);
        
        END_INTERFACE
    } ISimpleAudioVolumeVtbl;

    interface ISimpleAudioVolume
    {
        CONST_VTBL struct ISimpleAudioVolumeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimpleAudioVolume_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimpleAudioVolume_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimpleAudioVolume_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimpleAudioVolume_SetMasterVolume(This,fLevel,EventContext)	\
    ( (This)->lpVtbl -> SetMasterVolume(This,fLevel,EventContext) ) 

#define ISimpleAudioVolume_GetMasterVolume(This,pfLevel)	\
    ( (This)->lpVtbl -> GetMasterVolume(This,pfLevel) ) 

#define ISimpleAudioVolume_SetMute(This,bMute,EventContext)	\
    ( (This)->lpVtbl -> SetMute(This,bMute,EventContext) ) 

#define ISimpleAudioVolume_GetMute(This,pbMute)	\
    ( (This)->lpVtbl -> GetMute(This,pbMute) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimpleAudioVolume_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioclient_0000_0009 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */


extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0009_v0_0_s_ifspec;

#ifndef __IAudioStreamVolume_INTERFACE_DEFINED__
#define __IAudioStreamVolume_INTERFACE_DEFINED__

/* interface IAudioStreamVolume */
/* [local][unique][uuid][object] */ 


EXTERN_C const IID IID_IAudioStreamVolume;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("93014887-242D-4068-8A15-CF5E93B90FE3")
    IAudioStreamVolume : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetChannelCount( 
            /* [annotation][out] */ 
            _Out_  UINT32 *pdwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetChannelVolume( 
            /* [annotation][in] */ 
            _In_  UINT32 dwIndex,
            /* [annotation][in] */ 
            _In_  const float fLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChannelVolume( 
            /* [annotation][in] */ 
            _In_  UINT32 dwIndex,
            /* [annotation][out] */ 
            _Out_  float *pfLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAllVolumes( 
            /* [annotation][in] */ 
            _In_  UINT32 dwCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwCount)  const float *pfVolumes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllVolumes( 
            /* [annotation][in] */ 
            _In_  UINT32 dwCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwCount)  float *pfVolumes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioStreamVolumeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioStreamVolume * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioStreamVolume * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioStreamVolume * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetChannelCount )( 
            IAudioStreamVolume * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pdwCount);
        
        HRESULT ( STDMETHODCALLTYPE *SetChannelVolume )( 
            IAudioStreamVolume * This,
            /* [annotation][in] */ 
            _In_  UINT32 dwIndex,
            /* [annotation][in] */ 
            _In_  const float fLevel);
        
        HRESULT ( STDMETHODCALLTYPE *GetChannelVolume )( 
            IAudioStreamVolume * This,
            /* [annotation][in] */ 
            _In_  UINT32 dwIndex,
            /* [annotation][out] */ 
            _Out_  float *pfLevel);
        
        HRESULT ( STDMETHODCALLTYPE *SetAllVolumes )( 
            IAudioStreamVolume * This,
            /* [annotation][in] */ 
            _In_  UINT32 dwCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwCount)  const float *pfVolumes);
        
        HRESULT ( STDMETHODCALLTYPE *GetAllVolumes )( 
            IAudioStreamVolume * This,
            /* [annotation][in] */ 
            _In_  UINT32 dwCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwCount)  float *pfVolumes);
        
        END_INTERFACE
    } IAudioStreamVolumeVtbl;

    interface IAudioStreamVolume
    {
        CONST_VTBL struct IAudioStreamVolumeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioStreamVolume_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioStreamVolume_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioStreamVolume_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioStreamVolume_GetChannelCount(This,pdwCount)	\
    ( (This)->lpVtbl -> GetChannelCount(This,pdwCount) ) 

#define IAudioStreamVolume_SetChannelVolume(This,dwIndex,fLevel)	\
    ( (This)->lpVtbl -> SetChannelVolume(This,dwIndex,fLevel) ) 

#define IAudioStreamVolume_GetChannelVolume(This,dwIndex,pfLevel)	\
    ( (This)->lpVtbl -> GetChannelVolume(This,dwIndex,pfLevel) ) 

#define IAudioStreamVolume_SetAllVolumes(This,dwCount,pfVolumes)	\
    ( (This)->lpVtbl -> SetAllVolumes(This,dwCount,pfVolumes) ) 

#define IAudioStreamVolume_GetAllVolumes(This,dwCount,pfVolumes)	\
    ( (This)->lpVtbl -> GetAllVolumes(This,dwCount,pfVolumes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioStreamVolume_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioclient_0000_0010 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES) */
#pragma endregion
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
typedef 
enum AMBISONICS_TYPE
    {
        AMBISONICS_TYPE_FULL3D	= 0
    } 	AMBISONICS_TYPE;

typedef 
enum AMBISONICS_CHANNEL_ORDERING
    {
        AMBISONICS_CHANNEL_ORDERING_ACN	= 0
    } 	AMBISONICS_CHANNEL_ORDERING;

typedef 
enum AMBISONICS_NORMALIZATION
    {
        AMBISONICS_NORMALIZATION_SN3D	= 0,
        AMBISONICS_NORMALIZATION_N3D	= ( AMBISONICS_NORMALIZATION_SN3D + 1 ) 
    } 	AMBISONICS_NORMALIZATION;

#define AMBISONICS_PARAM_VERSION_1 1
// The AMBISONICS_PARAMS initialization structure should be completely filled out 
// and then passed into the SetData API of IAmbisonicsControl Service on IAudioClient
// unsigned int(32) size of AMBISONICS_PARAMS
// unsigned int(32)  version of AMBISONICS_PARAMS struct
// unsigned int(32) ambisonics_type is the enumeration of ambisonics types
// unsigned int(32) ambisonics_channel_ordering is the enumeration of ambisonics channel ordering
// unsigned int(32) ambisonics_normalization is the enumeration of ambisonics normaliztion
// unsigned int(32) ambisonics_order
// unsigned int(32) ambisonics_num_channels
// unsigned int(32) ambisonics_channel_map is a sequence of 32-bit unsigned integers that maps audio channels in a given audio track to ambisonic components,
// given the defined ambisonics_channel_ordering. The sequence of channel_map values should match the channel sequence within the given audio track.
typedef struct AMBISONICS_PARAMS
    {
    UINT32 u32Size;
    UINT32 u32Version;
    AMBISONICS_TYPE u32Type;
    AMBISONICS_CHANNEL_ORDERING u32ChannelOrdering;
    AMBISONICS_NORMALIZATION u32Normalization;
    UINT32 u32Order;
    UINT32 u32NumChannels;
    /* [size_is][annotation] */ 
    __field_ecount(u32NumChannels)  UINT32 *pu32ChannelMap;
    } 	AMBISONICS_PARAMS;



extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0010_v0_0_s_ifspec;

#ifndef __IAudioAmbisonicsControl_INTERFACE_DEFINED__
#define __IAudioAmbisonicsControl_INTERFACE_DEFINED__

/* interface IAudioAmbisonicsControl */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IAudioAmbisonicsControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28724C91-DF35-4856-9F76-D6A26413F3DF")
    IAudioAmbisonicsControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetData( 
            /* [annotation][size_is][in] */ 
            _In_reads_(cbAmbisonicsParams)  const AMBISONICS_PARAMS *pAmbisonicsParams,
            /* [annotation][in] */ 
            _In_  UINT32 cbAmbisonicsParams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHeadTracking( 
            /* [annotation][in] */ 
            _In_  BOOL bEnableHeadTracking) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHeadTracking( 
            /* [annotation][out] */ 
            _Out_  BOOL *pbEnableHeadTracking) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRotation( 
            /* [annotation][in] */ 
            _In_  float X,
            /* [annotation][in] */ 
            _In_  float Y,
            /* [annotation][in] */ 
            _In_  float Z,
            /* [annotation][in] */ 
            _In_  float W) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioAmbisonicsControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAudioAmbisonicsControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAudioAmbisonicsControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAudioAmbisonicsControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            __RPC__in IAudioAmbisonicsControl * This,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbAmbisonicsParams)  const AMBISONICS_PARAMS *pAmbisonicsParams,
            /* [annotation][in] */ 
            _In_  UINT32 cbAmbisonicsParams);
        
        HRESULT ( STDMETHODCALLTYPE *SetHeadTracking )( 
            __RPC__in IAudioAmbisonicsControl * This,
            /* [annotation][in] */ 
            _In_  BOOL bEnableHeadTracking);
        
        HRESULT ( STDMETHODCALLTYPE *GetHeadTracking )( 
            __RPC__in IAudioAmbisonicsControl * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pbEnableHeadTracking);
        
        HRESULT ( STDMETHODCALLTYPE *SetRotation )( 
            __RPC__in IAudioAmbisonicsControl * This,
            /* [annotation][in] */ 
            _In_  float X,
            /* [annotation][in] */ 
            _In_  float Y,
            /* [annotation][in] */ 
            _In_  float Z,
            /* [annotation][in] */ 
            _In_  float W);
        
        END_INTERFACE
    } IAudioAmbisonicsControlVtbl;

    interface IAudioAmbisonicsControl
    {
        CONST_VTBL struct IAudioAmbisonicsControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioAmbisonicsControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioAmbisonicsControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioAmbisonicsControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioAmbisonicsControl_SetData(This,pAmbisonicsParams,cbAmbisonicsParams)	\
    ( (This)->lpVtbl -> SetData(This,pAmbisonicsParams,cbAmbisonicsParams) ) 

#define IAudioAmbisonicsControl_SetHeadTracking(This,bEnableHeadTracking)	\
    ( (This)->lpVtbl -> SetHeadTracking(This,bEnableHeadTracking) ) 

#define IAudioAmbisonicsControl_GetHeadTracking(This,pbEnableHeadTracking)	\
    ( (This)->lpVtbl -> GetHeadTracking(This,pbEnableHeadTracking) ) 

#define IAudioAmbisonicsControl_SetRotation(This,X,Y,Z,W)	\
    ( (This)->lpVtbl -> SetRotation(This,X,Y,Z,W) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioAmbisonicsControl_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioclient_0000_0011 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0011_v0_0_s_ifspec;

#ifndef __IChannelAudioVolume_INTERFACE_DEFINED__
#define __IChannelAudioVolume_INTERFACE_DEFINED__

/* interface IChannelAudioVolume */
/* [local][unique][uuid][object] */ 


EXTERN_C const IID IID_IChannelAudioVolume;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C158861-B533-4B30-B1CF-E853E51C59B8")
    IChannelAudioVolume : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetChannelCount( 
            /* [annotation][out] */ 
            _Out_  UINT32 *pdwCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetChannelVolume( 
            /* [annotation][in] */ 
            _In_  UINT32 dwIndex,
            /* [annotation][in] */ 
            _In_  const float fLevel,
            /* [unique][in] */ LPCGUID EventContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChannelVolume( 
            /* [annotation][in] */ 
            _In_  UINT32 dwIndex,
            /* [annotation][out] */ 
            _Out_  float *pfLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAllVolumes( 
            /* [annotation][in] */ 
            _In_  UINT32 dwCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwCount)  const float *pfVolumes,
            /* [unique][in] */ LPCGUID EventContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllVolumes( 
            /* [annotation][in] */ 
            _In_  UINT32 dwCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwCount)  float *pfVolumes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IChannelAudioVolumeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChannelAudioVolume * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChannelAudioVolume * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChannelAudioVolume * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetChannelCount )( 
            IChannelAudioVolume * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pdwCount);
        
        HRESULT ( STDMETHODCALLTYPE *SetChannelVolume )( 
            IChannelAudioVolume * This,
            /* [annotation][in] */ 
            _In_  UINT32 dwIndex,
            /* [annotation][in] */ 
            _In_  const float fLevel,
            /* [unique][in] */ LPCGUID EventContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetChannelVolume )( 
            IChannelAudioVolume * This,
            /* [annotation][in] */ 
            _In_  UINT32 dwIndex,
            /* [annotation][out] */ 
            _Out_  float *pfLevel);
        
        HRESULT ( STDMETHODCALLTYPE *SetAllVolumes )( 
            IChannelAudioVolume * This,
            /* [annotation][in] */ 
            _In_  UINT32 dwCount,
            /* [annotation][size_is][in] */ 
            _In_reads_(dwCount)  const float *pfVolumes,
            /* [unique][in] */ LPCGUID EventContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetAllVolumes )( 
            IChannelAudioVolume * This,
            /* [annotation][in] */ 
            _In_  UINT32 dwCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(dwCount)  float *pfVolumes);
        
        END_INTERFACE
    } IChannelAudioVolumeVtbl;

    interface IChannelAudioVolume
    {
        CONST_VTBL struct IChannelAudioVolumeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChannelAudioVolume_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IChannelAudioVolume_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IChannelAudioVolume_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IChannelAudioVolume_GetChannelCount(This,pdwCount)	\
    ( (This)->lpVtbl -> GetChannelCount(This,pdwCount) ) 

#define IChannelAudioVolume_SetChannelVolume(This,dwIndex,fLevel,EventContext)	\
    ( (This)->lpVtbl -> SetChannelVolume(This,dwIndex,fLevel,EventContext) ) 

#define IChannelAudioVolume_GetChannelVolume(This,dwIndex,pfLevel)	\
    ( (This)->lpVtbl -> GetChannelVolume(This,dwIndex,pfLevel) ) 

#define IChannelAudioVolume_SetAllVolumes(This,dwCount,pfVolumes,EventContext)	\
    ( (This)->lpVtbl -> SetAllVolumes(This,dwCount,pfVolumes,EventContext) ) 

#define IChannelAudioVolume_GetAllVolumes(This,dwCount,pfVolumes)	\
    ( (This)->lpVtbl -> GetAllVolumes(This,dwCount,pfVolumes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IChannelAudioVolume_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioclient_0000_0012 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#pragma region Application and Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES)
#define AUDCLNT_ERR(n) MAKE_HRESULT(SEVERITY_ERROR, FACILITY_AUDCLNT, n)
#define AUDCLNT_SUCCESS(n) MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_AUDCLNT, n)
#define AUDCLNT_E_NOT_INITIALIZED              AUDCLNT_ERR(0x001)
#define AUDCLNT_E_ALREADY_INITIALIZED          AUDCLNT_ERR(0x002)
#define AUDCLNT_E_WRONG_ENDPOINT_TYPE          AUDCLNT_ERR(0x003)
#define AUDCLNT_E_DEVICE_INVALIDATED           AUDCLNT_ERR(0x004)
#define AUDCLNT_E_NOT_STOPPED                  AUDCLNT_ERR(0x005)
#define AUDCLNT_E_BUFFER_TOO_LARGE             AUDCLNT_ERR(0x006)
#define AUDCLNT_E_OUT_OF_ORDER                 AUDCLNT_ERR(0x007)
#define AUDCLNT_E_UNSUPPORTED_FORMAT           AUDCLNT_ERR(0x008)
#define AUDCLNT_E_INVALID_SIZE                 AUDCLNT_ERR(0x009)
#define AUDCLNT_E_DEVICE_IN_USE                AUDCLNT_ERR(0x00a)
#define AUDCLNT_E_BUFFER_OPERATION_PENDING     AUDCLNT_ERR(0x00b)
#define AUDCLNT_E_THREAD_NOT_REGISTERED        AUDCLNT_ERR(0x00c)
#define AUDCLNT_E_EXCLUSIVE_MODE_NOT_ALLOWED   AUDCLNT_ERR(0x00e)
#define AUDCLNT_E_ENDPOINT_CREATE_FAILED       AUDCLNT_ERR(0x00f)
#define AUDCLNT_E_SERVICE_NOT_RUNNING          AUDCLNT_ERR(0x010)
#define AUDCLNT_E_EVENTHANDLE_NOT_EXPECTED     AUDCLNT_ERR(0x011)
#define AUDCLNT_E_EXCLUSIVE_MODE_ONLY          AUDCLNT_ERR(0x012)
#define AUDCLNT_E_BUFDURATION_PERIOD_NOT_EQUAL AUDCLNT_ERR(0x013)
#define AUDCLNT_E_EVENTHANDLE_NOT_SET          AUDCLNT_ERR(0x014)
#define AUDCLNT_E_INCORRECT_BUFFER_SIZE        AUDCLNT_ERR(0x015)
#define AUDCLNT_E_BUFFER_SIZE_ERROR            AUDCLNT_ERR(0x016)
#define AUDCLNT_E_CPUUSAGE_EXCEEDED            AUDCLNT_ERR(0x017)
#define AUDCLNT_E_BUFFER_ERROR                 AUDCLNT_ERR(0x018)
#define AUDCLNT_E_BUFFER_SIZE_NOT_ALIGNED      AUDCLNT_ERR(0x019)
#define AUDCLNT_E_INVALID_DEVICE_PERIOD        AUDCLNT_ERR(0x020)
#define AUDCLNT_E_INVALID_STREAM_FLAG          AUDCLNT_ERR(0x021)
#define AUDCLNT_E_ENDPOINT_OFFLOAD_NOT_CAPABLE AUDCLNT_ERR(0x022)
#define AUDCLNT_E_OUT_OF_OFFLOAD_RESOURCES     AUDCLNT_ERR(0x023)
#define AUDCLNT_E_OFFLOAD_MODE_ONLY            AUDCLNT_ERR(0x024)
#define AUDCLNT_E_NONOFFLOAD_MODE_ONLY         AUDCLNT_ERR(0x025)
#define AUDCLNT_E_RESOURCES_INVALIDATED        AUDCLNT_ERR(0x026)
#define AUDCLNT_E_RAW_MODE_UNSUPPORTED         AUDCLNT_ERR(0x027)
#define AUDCLNT_E_ENGINE_PERIODICITY_LOCKED    AUDCLNT_ERR(0x028)
#define AUDCLNT_E_ENGINE_FORMAT_LOCKED         AUDCLNT_ERR(0x029)
#define AUDCLNT_E_HEADTRACKING_ENABLED         AUDCLNT_ERR(0x030)
#define AUDCLNT_E_HEADTRACKING_UNSUPPORTED     AUDCLNT_ERR(0x040)
#define AUDCLNT_S_BUFFER_EMPTY                 AUDCLNT_SUCCESS(0x001)
#define AUDCLNT_S_THREAD_ALREADY_REGISTERED    AUDCLNT_SUCCESS(0x002)
#define AUDCLNT_S_POSITION_STALLED             AUDCLNT_SUCCESS(0x003)
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0012_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioclient_0000_0012_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



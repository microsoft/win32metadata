

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

#ifndef __audioenginebaseapo_h__
#define __audioenginebaseapo_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAudioProcessingObjectRT_FWD_DEFINED__
#define __IAudioProcessingObjectRT_FWD_DEFINED__
typedef interface IAudioProcessingObjectRT IAudioProcessingObjectRT;

#endif 	/* __IAudioProcessingObjectRT_FWD_DEFINED__ */


#ifndef __IAudioProcessingObjectVBR_FWD_DEFINED__
#define __IAudioProcessingObjectVBR_FWD_DEFINED__
typedef interface IAudioProcessingObjectVBR IAudioProcessingObjectVBR;

#endif 	/* __IAudioProcessingObjectVBR_FWD_DEFINED__ */


#ifndef __IAudioProcessingObjectConfiguration_FWD_DEFINED__
#define __IAudioProcessingObjectConfiguration_FWD_DEFINED__
typedef interface IAudioProcessingObjectConfiguration IAudioProcessingObjectConfiguration;

#endif 	/* __IAudioProcessingObjectConfiguration_FWD_DEFINED__ */


#ifndef __IAudioProcessingObject_FWD_DEFINED__
#define __IAudioProcessingObject_FWD_DEFINED__
typedef interface IAudioProcessingObject IAudioProcessingObject;

#endif 	/* __IAudioProcessingObject_FWD_DEFINED__ */


#ifndef __IAudioDeviceModulesClient_FWD_DEFINED__
#define __IAudioDeviceModulesClient_FWD_DEFINED__
typedef interface IAudioDeviceModulesClient IAudioDeviceModulesClient;

#endif 	/* __IAudioDeviceModulesClient_FWD_DEFINED__ */


#ifndef __IAudioSystemEffects_FWD_DEFINED__
#define __IAudioSystemEffects_FWD_DEFINED__
typedef interface IAudioSystemEffects IAudioSystemEffects;

#endif 	/* __IAudioSystemEffects_FWD_DEFINED__ */


#ifndef __IAudioSystemEffects2_FWD_DEFINED__
#define __IAudioSystemEffects2_FWD_DEFINED__
typedef interface IAudioSystemEffects2 IAudioSystemEffects2;

#endif 	/* __IAudioSystemEffects2_FWD_DEFINED__ */


#ifndef __IAudioSystemEffectsCustomFormats_FWD_DEFINED__
#define __IAudioSystemEffectsCustomFormats_FWD_DEFINED__
typedef interface IAudioSystemEffectsCustomFormats IAudioSystemEffectsCustomFormats;

#endif 	/* __IAudioSystemEffectsCustomFormats_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "mmdeviceapi.h"
#include "audiomediatype.h"
#include "AudioAPOTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_audioenginebaseapo_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
//
// Error Codes for APO
// The facility code for APOs is 0x87D.
//
// The object has already been initialized.
#define APOERR_ALREADY_INITIALIZED               _HRESULT_TYPEDEF_(0x887D0001)
// Object/structure is not initialized.
#define APOERR_NOT_INITIALIZED                   _HRESULT_TYPEDEF_(0x887D0002)
// a pin supporting the format cannot be found.
#define APOERR_FORMAT_NOT_SUPPORTED              _HRESULT_TYPEDEF_(0x887D0003)
// Invalid CLSID in an APO Initialization structure
#define APOERR_INVALID_APO_CLSID                 _HRESULT_TYPEDEF_(0x887D0004)
// Buffers overlap on an APO that does not accept in-place buffers.
#define APOERR_BUFFERS_OVERLAP                   _HRESULT_TYPEDEF_(0x887D0005)
// APO is already in an unlocked state
#define APOERR_ALREADY_UNLOCKED                  _HRESULT_TYPEDEF_(0x887D0006)
// number of input or output connections not valid on this APO
#define APOERR_NUM_CONNECTIONS_INVALID           _HRESULT_TYPEDEF_(0x887D0007)
// Output maxFrameCount not large enough.
#define APOERR_INVALID_OUTPUT_MAXFRAMECOUNT      _HRESULT_TYPEDEF_(0x887D0008)
// Invalid connection format for this operation
#define APOERR_INVALID_CONNECTION_FORMAT         _HRESULT_TYPEDEF_(0x887D0009)
// APO is locked ready to process and can not be changed
#define APOERR_APO_LOCKED                        _HRESULT_TYPEDEF_(0x887D000A)
// Invalid coefficient count
#define APOERR_INVALID_COEFFCOUNT                _HRESULT_TYPEDEF_(0x887D000B)
// Invalid coefficient
#define APOERR_INVALID_COEFFICIENT               _HRESULT_TYPEDEF_(0x887D000C)
// an invalid curve parameter was specified
#define APOERR_INVALID_CURVE_PARAM               _HRESULT_TYPEDEF_(0x887D000D)
//
// Signatures for data structures.
//
#define APO_CONNECTION_DESCRIPTOR_SIGNATURE     'ACDS'
#define APO_CONNECTION_PROPERTY_SIGNATURE       'ACPS'

// Min and max framerates for the engine
#define AUDIO_MIN_FRAMERATE                    10.0     // Minimum frame rate for APOs
#define AUDIO_MAX_FRAMERATE                     384000.0 // Maximum frame rate for APOs

// Min and max # of channels (samples per frame) for the APOs
#define AUDIO_MIN_CHANNELS                      1    // Current minimum number of channels for APOs
#define AUDIO_MAX_CHANNELS                      4096 // Current maximum number of channels for APOs

//-----------------------------------------------------------------------------

typedef 
enum APO_CONNECTION_BUFFER_TYPE
    {
        APO_CONNECTION_BUFFER_TYPE_ALLOCATED	= 0,
        APO_CONNECTION_BUFFER_TYPE_EXTERNAL	= 1,
        APO_CONNECTION_BUFFER_TYPE_DEPENDANT	= 2
    } 	APO_CONNECTION_BUFFER_TYPE;

typedef struct APO_CONNECTION_DESCRIPTOR
    {
    APO_CONNECTION_BUFFER_TYPE Type;
    UINT_PTR pBuffer;
    UINT32 u32MaxFrameCount;
    IAudioMediaType *pFormat;
    UINT32 u32Signature;
    } 	APO_CONNECTION_DESCRIPTOR;

typedef 
enum APO_FLAG
    {
        APO_FLAG_NONE	= 0,
        APO_FLAG_INPLACE	= 0x1,
        APO_FLAG_SAMPLESPERFRAME_MUST_MATCH	= 0x2,
        APO_FLAG_FRAMESPERSECOND_MUST_MATCH	= 0x4,
        APO_FLAG_BITSPERSAMPLE_MUST_MATCH	= 0x8,
        APO_FLAG_MIXER	= 0x10,
        APO_FLAG_DEFAULT	= ( ( APO_FLAG_SAMPLESPERFRAME_MUST_MATCH | APO_FLAG_FRAMESPERSECOND_MUST_MATCH )  | APO_FLAG_BITSPERSAMPLE_MUST_MATCH ) 
    } 	APO_FLAG;

typedef struct APO_REG_PROPERTIES
    {
    CLSID clsid;
    APO_FLAG Flags;
    WCHAR szFriendlyName[ 256 ];
    WCHAR szCopyrightInfo[ 256 ];
    UINT32 u32MajorVersion;
    UINT32 u32MinorVersion;
    UINT32 u32MinInputConnections;
    UINT32 u32MaxInputConnections;
    UINT32 u32MinOutputConnections;
    UINT32 u32MaxOutputConnections;
    UINT32 u32MaxInstances;
    UINT32 u32NumAPOInterfaces;
    /* [size_is] */ IID iidAPOInterfaceList[ 1 ];
    } 	APO_REG_PROPERTIES;

typedef struct APO_REG_PROPERTIES *PAPO_REG_PROPERTIES;

typedef struct APOInitBaseStruct
    {
    UINT32 cbSize;
    CLSID clsid;
    } 	APOInitBaseStruct;

typedef 
enum AUDIO_FLOW_TYPE
    {
        AUDIO_FLOW_PULL	= 0,
        AUDIO_FLOW_PUSH	= ( AUDIO_FLOW_PULL + 1 ) 
    } 	AUDIO_FLOW_TYPE;

typedef 
enum EAudioConstriction
    {
        eAudioConstrictionOff	= 0,
        eAudioConstriction48_16	= ( eAudioConstrictionOff + 1 ) ,
        eAudioConstriction44_16	= ( eAudioConstriction48_16 + 1 ) ,
        eAudioConstriction14_14	= ( eAudioConstriction44_16 + 1 ) ,
        eAudioConstrictionMute	= ( eAudioConstriction14_14 + 1 ) 
    } 	EAudioConstriction;



extern RPC_IF_HANDLE __MIDL_itf_audioenginebaseapo_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioenginebaseapo_0000_0000_v0_0_s_ifspec;

#ifndef __IAudioProcessingObjectRT_INTERFACE_DEFINED__
#define __IAudioProcessingObjectRT_INTERFACE_DEFINED__

/* interface IAudioProcessingObjectRT */
/* [local][unique][uuid][object] */ 


EXTERN_C const IID IID_IAudioProcessingObjectRT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9E1D6A6D-DDBC-4E95-A4C7-AD64BA37846C")
    IAudioProcessingObjectRT : public IUnknown
    {
    public:
        virtual void STDMETHODCALLTYPE APOProcess( 
            /* [annotation][in] */ 
            _In_  UINT32 u32NumInputConnections,
            /* [annotation][in] */ 
            _In_  APO_CONNECTION_PROPERTY **ppInputConnections,
            /* [annotation][in] */ 
            _In_  UINT32 u32NumOutputConnections,
            /* [annotation][out][in] */ 
            _Inout_  APO_CONNECTION_PROPERTY **ppOutputConnections) = 0;
        
        virtual UINT32 STDMETHODCALLTYPE CalcInputFrames( 
            /* [annotation][in] */ 
            _In_  UINT32 u32OutputFrameCount) = 0;
        
        virtual UINT32 STDMETHODCALLTYPE CalcOutputFrames( 
            /* [annotation][in] */ 
            _In_  UINT32 u32InputFrameCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioProcessingObjectRTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioProcessingObjectRT * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioProcessingObjectRT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioProcessingObjectRT * This);
        
        void ( STDMETHODCALLTYPE *APOProcess )( 
            IAudioProcessingObjectRT * This,
            /* [annotation][in] */ 
            _In_  UINT32 u32NumInputConnections,
            /* [annotation][in] */ 
            _In_  APO_CONNECTION_PROPERTY **ppInputConnections,
            /* [annotation][in] */ 
            _In_  UINT32 u32NumOutputConnections,
            /* [annotation][out][in] */ 
            _Inout_  APO_CONNECTION_PROPERTY **ppOutputConnections);
        
        UINT32 ( STDMETHODCALLTYPE *CalcInputFrames )( 
            IAudioProcessingObjectRT * This,
            /* [annotation][in] */ 
            _In_  UINT32 u32OutputFrameCount);
        
        UINT32 ( STDMETHODCALLTYPE *CalcOutputFrames )( 
            IAudioProcessingObjectRT * This,
            /* [annotation][in] */ 
            _In_  UINT32 u32InputFrameCount);
        
        END_INTERFACE
    } IAudioProcessingObjectRTVtbl;

    interface IAudioProcessingObjectRT
    {
        CONST_VTBL struct IAudioProcessingObjectRTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioProcessingObjectRT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioProcessingObjectRT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioProcessingObjectRT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioProcessingObjectRT_APOProcess(This,u32NumInputConnections,ppInputConnections,u32NumOutputConnections,ppOutputConnections)	\
    ( (This)->lpVtbl -> APOProcess(This,u32NumInputConnections,ppInputConnections,u32NumOutputConnections,ppOutputConnections) ) 

#define IAudioProcessingObjectRT_CalcInputFrames(This,u32OutputFrameCount)	\
    ( (This)->lpVtbl -> CalcInputFrames(This,u32OutputFrameCount) ) 

#define IAudioProcessingObjectRT_CalcOutputFrames(This,u32InputFrameCount)	\
    ( (This)->lpVtbl -> CalcOutputFrames(This,u32InputFrameCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioProcessingObjectRT_INTERFACE_DEFINED__ */


#ifndef __IAudioProcessingObjectVBR_INTERFACE_DEFINED__
#define __IAudioProcessingObjectVBR_INTERFACE_DEFINED__

/* interface IAudioProcessingObjectVBR */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IAudioProcessingObjectVBR;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7ba1db8f-78ad-49cd-9591-f79d80a17c81")
    IAudioProcessingObjectVBR : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CalcMaxInputFrames( 
            /* [annotation][in] */ 
            _In_  UINT32 u32MaxOutputFrameCount,
            /* [annotation][out] */ 
            _Out_  UINT32 *pu32InputFrameCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CalcMaxOutputFrames( 
            /* [annotation][in] */ 
            _In_  UINT32 u32MaxInputFrameCount,
            /* [annotation][out] */ 
            _Out_  UINT32 *pu32OutputFrameCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioProcessingObjectVBRVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAudioProcessingObjectVBR * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAudioProcessingObjectVBR * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAudioProcessingObjectVBR * This);
        
        HRESULT ( STDMETHODCALLTYPE *CalcMaxInputFrames )( 
            __RPC__in IAudioProcessingObjectVBR * This,
            /* [annotation][in] */ 
            _In_  UINT32 u32MaxOutputFrameCount,
            /* [annotation][out] */ 
            _Out_  UINT32 *pu32InputFrameCount);
        
        HRESULT ( STDMETHODCALLTYPE *CalcMaxOutputFrames )( 
            __RPC__in IAudioProcessingObjectVBR * This,
            /* [annotation][in] */ 
            _In_  UINT32 u32MaxInputFrameCount,
            /* [annotation][out] */ 
            _Out_  UINT32 *pu32OutputFrameCount);
        
        END_INTERFACE
    } IAudioProcessingObjectVBRVtbl;

    interface IAudioProcessingObjectVBR
    {
        CONST_VTBL struct IAudioProcessingObjectVBRVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioProcessingObjectVBR_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioProcessingObjectVBR_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioProcessingObjectVBR_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioProcessingObjectVBR_CalcMaxInputFrames(This,u32MaxOutputFrameCount,pu32InputFrameCount)	\
    ( (This)->lpVtbl -> CalcMaxInputFrames(This,u32MaxOutputFrameCount,pu32InputFrameCount) ) 

#define IAudioProcessingObjectVBR_CalcMaxOutputFrames(This,u32MaxInputFrameCount,pu32OutputFrameCount)	\
    ( (This)->lpVtbl -> CalcMaxOutputFrames(This,u32MaxInputFrameCount,pu32OutputFrameCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioProcessingObjectVBR_INTERFACE_DEFINED__ */


#ifndef __IAudioProcessingObjectConfiguration_INTERFACE_DEFINED__
#define __IAudioProcessingObjectConfiguration_INTERFACE_DEFINED__

/* interface IAudioProcessingObjectConfiguration */
/* [local][unique][uuid][object] */ 


EXTERN_C const IID IID_IAudioProcessingObjectConfiguration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0E5ED805-ABA6-49c3-8F9A-2B8C889C4FA8")
    IAudioProcessingObjectConfiguration : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LockForProcess( 
            /* [annotation][in] */ 
            _In_  UINT32 u32NumInputConnections,
            /* [annotation][in] */ 
            _In_  APO_CONNECTION_DESCRIPTOR **ppInputConnections,
            /* [annotation][in] */ 
            _In_  UINT32 u32NumOutputConnections,
            /* [annotation][in] */ 
            _In_  APO_CONNECTION_DESCRIPTOR **ppOutputConnections) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnlockForProcess( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioProcessingObjectConfigurationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioProcessingObjectConfiguration * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioProcessingObjectConfiguration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioProcessingObjectConfiguration * This);
        
        HRESULT ( STDMETHODCALLTYPE *LockForProcess )( 
            IAudioProcessingObjectConfiguration * This,
            /* [annotation][in] */ 
            _In_  UINT32 u32NumInputConnections,
            /* [annotation][in] */ 
            _In_  APO_CONNECTION_DESCRIPTOR **ppInputConnections,
            /* [annotation][in] */ 
            _In_  UINT32 u32NumOutputConnections,
            /* [annotation][in] */ 
            _In_  APO_CONNECTION_DESCRIPTOR **ppOutputConnections);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockForProcess )( 
            IAudioProcessingObjectConfiguration * This);
        
        END_INTERFACE
    } IAudioProcessingObjectConfigurationVtbl;

    interface IAudioProcessingObjectConfiguration
    {
        CONST_VTBL struct IAudioProcessingObjectConfigurationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioProcessingObjectConfiguration_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioProcessingObjectConfiguration_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioProcessingObjectConfiguration_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioProcessingObjectConfiguration_LockForProcess(This,u32NumInputConnections,ppInputConnections,u32NumOutputConnections,ppOutputConnections)	\
    ( (This)->lpVtbl -> LockForProcess(This,u32NumInputConnections,ppInputConnections,u32NumOutputConnections,ppOutputConnections) ) 

#define IAudioProcessingObjectConfiguration_UnlockForProcess(This)	\
    ( (This)->lpVtbl -> UnlockForProcess(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioProcessingObjectConfiguration_INTERFACE_DEFINED__ */


#ifndef __IAudioProcessingObject_INTERFACE_DEFINED__
#define __IAudioProcessingObject_INTERFACE_DEFINED__

/* interface IAudioProcessingObject */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IAudioProcessingObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FD7F2B29-24D0-4b5c-B177-592C39F9CA10")
    IAudioProcessingObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLatency( 
            /* [annotation][out] */ 
            _Out_  HNSTIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegistrationProperties( 
            /* [annotation][out] */ 
            _Out_  APO_REG_PROPERTIES **ppRegProps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  UINT32 cbDataSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbDataSize)  BYTE *pbyData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsInputFormatSupported( 
            /* [annotation][unique][in] */ 
            _In_  IAudioMediaType *pOppositeFormat,
            /* [annotation][in] */ 
            _In_  IAudioMediaType *pRequestedInputFormat,
            /* [annotation][out] */ 
            _Out_  IAudioMediaType **ppSupportedInputFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsOutputFormatSupported( 
            /* [annotation][unique][in] */ 
            _In_  IAudioMediaType *pOppositeFormat,
            /* [annotation][in] */ 
            _In_  IAudioMediaType *pRequestedOutputFormat,
            /* [annotation][out] */ 
            _Out_  IAudioMediaType **ppSupportedOutputFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputChannelCount( 
            /* [annotation][out] */ 
            _Out_  UINT32 *pu32ChannelCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioProcessingObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAudioProcessingObject * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAudioProcessingObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAudioProcessingObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IAudioProcessingObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetLatency )( 
            __RPC__in IAudioProcessingObject * This,
            /* [annotation][out] */ 
            _Out_  HNSTIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegistrationProperties )( 
            __RPC__in IAudioProcessingObject * This,
            /* [annotation][out] */ 
            _Out_  APO_REG_PROPERTIES **ppRegProps);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            __RPC__in IAudioProcessingObject * This,
            /* [annotation][in] */ 
            _In_  UINT32 cbDataSize,
            /* [annotation][size_is][in] */ 
            _In_reads_(cbDataSize)  BYTE *pbyData);
        
        HRESULT ( STDMETHODCALLTYPE *IsInputFormatSupported )( 
            __RPC__in IAudioProcessingObject * This,
            /* [annotation][unique][in] */ 
            _In_  IAudioMediaType *pOppositeFormat,
            /* [annotation][in] */ 
            _In_  IAudioMediaType *pRequestedInputFormat,
            /* [annotation][out] */ 
            _Out_  IAudioMediaType **ppSupportedInputFormat);
        
        HRESULT ( STDMETHODCALLTYPE *IsOutputFormatSupported )( 
            __RPC__in IAudioProcessingObject * This,
            /* [annotation][unique][in] */ 
            _In_  IAudioMediaType *pOppositeFormat,
            /* [annotation][in] */ 
            _In_  IAudioMediaType *pRequestedOutputFormat,
            /* [annotation][out] */ 
            _Out_  IAudioMediaType **ppSupportedOutputFormat);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputChannelCount )( 
            __RPC__in IAudioProcessingObject * This,
            /* [annotation][out] */ 
            _Out_  UINT32 *pu32ChannelCount);
        
        END_INTERFACE
    } IAudioProcessingObjectVtbl;

    interface IAudioProcessingObject
    {
        CONST_VTBL struct IAudioProcessingObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioProcessingObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioProcessingObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioProcessingObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioProcessingObject_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IAudioProcessingObject_GetLatency(This,pTime)	\
    ( (This)->lpVtbl -> GetLatency(This,pTime) ) 

#define IAudioProcessingObject_GetRegistrationProperties(This,ppRegProps)	\
    ( (This)->lpVtbl -> GetRegistrationProperties(This,ppRegProps) ) 

#define IAudioProcessingObject_Initialize(This,cbDataSize,pbyData)	\
    ( (This)->lpVtbl -> Initialize(This,cbDataSize,pbyData) ) 

#define IAudioProcessingObject_IsInputFormatSupported(This,pOppositeFormat,pRequestedInputFormat,ppSupportedInputFormat)	\
    ( (This)->lpVtbl -> IsInputFormatSupported(This,pOppositeFormat,pRequestedInputFormat,ppSupportedInputFormat) ) 

#define IAudioProcessingObject_IsOutputFormatSupported(This,pOppositeFormat,pRequestedOutputFormat,ppSupportedOutputFormat)	\
    ( (This)->lpVtbl -> IsOutputFormatSupported(This,pOppositeFormat,pRequestedOutputFormat,ppSupportedOutputFormat) ) 

#define IAudioProcessingObject_GetInputChannelCount(This,pu32ChannelCount)	\
    ( (This)->lpVtbl -> GetInputChannelCount(This,pu32ChannelCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioProcessingObject_INTERFACE_DEFINED__ */


#ifndef __IAudioDeviceModulesClient_INTERFACE_DEFINED__
#define __IAudioDeviceModulesClient_INTERFACE_DEFINED__

/* interface IAudioDeviceModulesClient */
/* [unique][helpstring][nonextensible][uuid][local][object] */ 


EXTERN_C const IID IID_IAudioDeviceModulesClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("98F37DAC-D0B6-49F5-896A-AA4D169A4C48")
    IAudioDeviceModulesClient : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetAudioDeviceModulesManager( 
            /* [annotation][in] */ 
            _In_  IUnknown *pAudioDeviceModulesManager) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioDeviceModulesClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioDeviceModulesClient * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioDeviceModulesClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioDeviceModulesClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetAudioDeviceModulesManager )( 
            IAudioDeviceModulesClient * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pAudioDeviceModulesManager);
        
        END_INTERFACE
    } IAudioDeviceModulesClientVtbl;

    interface IAudioDeviceModulesClient
    {
        CONST_VTBL struct IAudioDeviceModulesClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioDeviceModulesClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioDeviceModulesClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioDeviceModulesClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioDeviceModulesClient_SetAudioDeviceModulesManager(This,pAudioDeviceModulesManager)	\
    ( (This)->lpVtbl -> SetAudioDeviceModulesManager(This,pAudioDeviceModulesManager) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioDeviceModulesClient_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioenginebaseapo_0000_0005 */
/* [local] */ 

//
// APO registration functions
//
typedef HRESULT (WINAPI FNAPONOTIFICATIONCALLBACK)(APO_REG_PROPERTIES* pProperties, VOID* pvRefData);
extern HRESULT WINAPI RegisterAPO(APO_REG_PROPERTIES const* pProperties);
extern HRESULT WINAPI UnregisterAPO(REFCLSID clsid);
extern HRESULT WINAPI RegisterAPONotification(HANDLE hEvent);
extern HRESULT WINAPI UnregisterAPONotification(HANDLE hEvent);
extern HRESULT WINAPI EnumerateAPOs(FNAPONOTIFICATIONCALLBACK pfnCallback, PVOID pvRefData);
extern HRESULT WINAPI GetAPOProperties(REFCLSID clsid, APO_REG_PROPERTIES* pProperties);


extern RPC_IF_HANDLE __MIDL_itf_audioenginebaseapo_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioenginebaseapo_0000_0005_v0_0_s_ifspec;

#ifndef __IAudioSystemEffects_INTERFACE_DEFINED__
#define __IAudioSystemEffects_INTERFACE_DEFINED__

/* interface IAudioSystemEffects */
/* [object][uuid] */ 


EXTERN_C const IID IID_IAudioSystemEffects;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5FA00F27-ADD6-499a-8A9D-6B98521FA75B")
    IAudioSystemEffects : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioSystemEffectsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAudioSystemEffects * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAudioSystemEffects * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAudioSystemEffects * This);
        
        END_INTERFACE
    } IAudioSystemEffectsVtbl;

    interface IAudioSystemEffects
    {
        CONST_VTBL struct IAudioSystemEffectsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioSystemEffects_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioSystemEffects_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioSystemEffects_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioSystemEffects_INTERFACE_DEFINED__ */


#ifndef __IAudioSystemEffects2_INTERFACE_DEFINED__
#define __IAudioSystemEffects2_INTERFACE_DEFINED__

/* interface IAudioSystemEffects2 */
/* [object][uuid][local] */ 


EXTERN_C const IID IID_IAudioSystemEffects2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAFE99D2-7436-44CE-9E0E-4D89AFBFFF56")
    IAudioSystemEffects2 : public IAudioSystemEffects
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEffectsList( 
            /* [annotation][out] */ 
            _Outptr_result_buffer_maybenull_(*pcEffects)  LPGUID *ppEffectsIds,
            /* [annotation][out] */ 
            _Out_  UINT *pcEffects,
            /* [annotation][in] */ 
            _In_  HANDLE Event) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioSystemEffects2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioSystemEffects2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioSystemEffects2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioSystemEffects2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetEffectsList )( 
            IAudioSystemEffects2 * This,
            /* [annotation][out] */ 
            _Outptr_result_buffer_maybenull_(*pcEffects)  LPGUID *ppEffectsIds,
            /* [annotation][out] */ 
            _Out_  UINT *pcEffects,
            /* [annotation][in] */ 
            _In_  HANDLE Event);
        
        END_INTERFACE
    } IAudioSystemEffects2Vtbl;

    interface IAudioSystemEffects2
    {
        CONST_VTBL struct IAudioSystemEffects2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioSystemEffects2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioSystemEffects2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioSystemEffects2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 



#define IAudioSystemEffects2_GetEffectsList(This,ppEffectsIds,pcEffects,Event)	\
    ( (This)->lpVtbl -> GetEffectsList(This,ppEffectsIds,pcEffects,Event) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioSystemEffects2_INTERFACE_DEFINED__ */


#ifndef __IAudioSystemEffectsCustomFormats_INTERFACE_DEFINED__
#define __IAudioSystemEffectsCustomFormats_INTERFACE_DEFINED__

/* interface IAudioSystemEffectsCustomFormats */
/* [object][uuid] */ 


EXTERN_C const IID IID_IAudioSystemEffectsCustomFormats;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B1176E34-BB7F-4f05-BEBD-1B18A534E097")
    IAudioSystemEffectsCustomFormats : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFormatCount( 
            /* [annotation][out] */ 
            _Out_  UINT *pcFormats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFormat( 
            /* [annotation][in] */ 
            _In_  UINT nFormat,
            /* [annotation][out] */ 
            _Out_  IAudioMediaType **ppFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFormatRepresentation( 
            /* [annotation][in] */ 
            _In_  UINT nFormat,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppwstrFormatRep) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioSystemEffectsCustomFormatsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IAudioSystemEffectsCustomFormats * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IAudioSystemEffectsCustomFormats * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IAudioSystemEffectsCustomFormats * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormatCount )( 
            __RPC__in IAudioSystemEffectsCustomFormats * This,
            /* [annotation][out] */ 
            _Out_  UINT *pcFormats);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            __RPC__in IAudioSystemEffectsCustomFormats * This,
            /* [annotation][in] */ 
            _In_  UINT nFormat,
            /* [annotation][out] */ 
            _Out_  IAudioMediaType **ppFormat);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormatRepresentation )( 
            __RPC__in IAudioSystemEffectsCustomFormats * This,
            /* [annotation][in] */ 
            _In_  UINT nFormat,
            /* [annotation][out] */ 
            _Out_  LPWSTR *ppwstrFormatRep);
        
        END_INTERFACE
    } IAudioSystemEffectsCustomFormatsVtbl;

    interface IAudioSystemEffectsCustomFormats
    {
        CONST_VTBL struct IAudioSystemEffectsCustomFormatsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioSystemEffectsCustomFormats_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioSystemEffectsCustomFormats_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioSystemEffectsCustomFormats_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioSystemEffectsCustomFormats_GetFormatCount(This,pcFormats)	\
    ( (This)->lpVtbl -> GetFormatCount(This,pcFormats) ) 

#define IAudioSystemEffectsCustomFormats_GetFormat(This,nFormat,ppFormat)	\
    ( (This)->lpVtbl -> GetFormat(This,nFormat,ppFormat) ) 

#define IAudioSystemEffectsCustomFormats_GetFormatRepresentation(This,nFormat,ppwstrFormatRep)	\
    ( (This)->lpVtbl -> GetFormatRepresentation(This,nFormat,ppwstrFormatRep) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioSystemEffectsCustomFormats_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioenginebaseapo_0000_0008 */
/* [local] */ 

typedef struct APOInitSystemEffects
    {
    APOInitBaseStruct APOInit;
    IPropertyStore *pAPOEndpointProperties;
    IPropertyStore *pAPOSystemEffectsProperties;
    void *pReserved;
    IMMDeviceCollection *pDeviceCollection;
    } 	APOInitSystemEffects;

typedef struct APOInitSystemEffects2
    {
    APOInitBaseStruct APOInit;
    IPropertyStore *pAPOEndpointProperties;
    IPropertyStore *pAPOSystemEffectsProperties;
    void *pReserved;
    IMMDeviceCollection *pDeviceCollection;
    UINT nSoftwareIoDeviceInCollection;
    UINT nSoftwareIoConnectorIndex;
    GUID AudioProcessingMode;
    BOOL InitializeForDiscoveryOnly;
    } 	APOInitSystemEffects2;

typedef /* [public] */ struct __MIDL___MIDL_itf_audioenginebaseapo_0000_0008_0001
    {
    LPARAM AddPageParam;
    LPWSTR pwstrEndpointID;
    IPropertyStore *pFxProperties;
    } 	AudioFXExtensionParams;

DEFINE_PROPERTYKEY(PKEY_FX_Association, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 0);
DEFINE_PROPERTYKEY(PKEY_FX_PreMixEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 1);
DEFINE_PROPERTYKEY(PKEY_FX_PostMixEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 2);
DEFINE_PROPERTYKEY(PKEY_FX_UserInterfaceClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 3);
DEFINE_PROPERTYKEY(PKEY_FX_FriendlyName, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 4);
DEFINE_PROPERTYKEY(PKEY_FX_StreamEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 5);
DEFINE_PROPERTYKEY(PKEY_FX_ModeEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 6);
DEFINE_PROPERTYKEY(PKEY_FX_EndpointEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 7);
DEFINE_PROPERTYKEY(PKEY_FX_KeywordDetector_StreamEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 8);
DEFINE_PROPERTYKEY(PKEY_FX_KeywordDetector_ModeEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 9);
DEFINE_PROPERTYKEY(PKEY_FX_KeywordDetector_EndpointEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 10);
DEFINE_PROPERTYKEY(PKEY_FX_Offload_StreamEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 11);
DEFINE_PROPERTYKEY(PKEY_FX_Offload_ModeEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 12);
DEFINE_PROPERTYKEY(PKEY_CompositeFX_StreamEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 13);
DEFINE_PROPERTYKEY(PKEY_CompositeFX_ModeEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 14);
DEFINE_PROPERTYKEY(PKEY_CompositeFX_EndpointEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 15);
DEFINE_PROPERTYKEY(PKEY_CompositeFX_KeywordDetector_StreamEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 16);
DEFINE_PROPERTYKEY(PKEY_CompositeFX_KeywordDetector_ModeEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 17);
DEFINE_PROPERTYKEY(PKEY_CompositeFX_KeywordDetector_EndpointEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 18);
DEFINE_PROPERTYKEY(PKEY_CompositeFX_Offload_StreamEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 19);
DEFINE_PROPERTYKEY(PKEY_CompositeFX_Offload_ModeEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 20);
DEFINE_PROPERTYKEY(PKEY_SFX_ProcessingModes_Supported_For_Streaming, 0xd3993a3f, 0x99c2, 0x4402, 0xb5, 0xec, 0xa9, 0x2a, 0x3, 0x67, 0x66, 0x4b, 5);
DEFINE_PROPERTYKEY(PKEY_MFX_ProcessingModes_Supported_For_Streaming, 0xd3993a3f, 0x99c2, 0x4402, 0xb5, 0xec, 0xa9, 0x2a, 0x3, 0x67, 0x66, 0x4b, 6);
DEFINE_PROPERTYKEY(PKEY_EFX_ProcessingModes_Supported_For_Streaming, 0xd3993a3f, 0x99c2, 0x4402, 0xb5, 0xec, 0xa9, 0x2a, 0x3, 0x67, 0x66, 0x4b, 7);
DEFINE_PROPERTYKEY(PKEY_SFX_KeywordDetector_ProcessingModes_Supported_For_Streaming, 0xd3993a3f, 0x99c2, 0x4402, 0xb5, 0xec, 0xa9, 0x2a, 0x3, 0x67, 0x66, 0x4b, 8);
DEFINE_PROPERTYKEY(PKEY_MFX_KeywordDetector_ProcessingModes_Supported_For_Streaming, 0xd3993a3f, 0x99c2, 0x4402, 0xb5, 0xec, 0xa9, 0x2a, 0x3, 0x67, 0x66, 0x4b, 9);
DEFINE_PROPERTYKEY(PKEY_EFX_KeywordDetector_ProcessingModes_Supported_For_Streaming, 0xd3993a3f, 0x99c2, 0x4402, 0xb5, 0xec, 0xa9, 0x2a, 0x3, 0x67, 0x66, 0x4b, 10);
DEFINE_PROPERTYKEY(PKEY_SFX_Offload_ProcessingModes_Supported_For_Streaming, 0xd3993a3f, 0x99c2, 0x4402, 0xb5, 0xec, 0xa9, 0x2a, 0x3, 0x67, 0x66, 0x4b, 11);
DEFINE_PROPERTYKEY(PKEY_MFX_Offload_ProcessingModes_Supported_For_Streaming, 0xd3993a3f, 0x99c2, 0x4402, 0xb5, 0xec, 0xa9, 0x2a, 0x3, 0x67, 0x66, 0x4b, 12);
DEFINE_PROPERTYKEY(PKEY_APO_SWFallback_ProcessingModes, 0xd3993a3f, 0x99c2, 0x4402, 0xb5, 0xec, 0xa9, 0x2a, 0x3, 0x67, 0x66, 0x4b, 13);
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_audioenginebaseapo_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioenginebaseapo_0000_0008_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



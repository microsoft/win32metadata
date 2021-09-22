

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

#ifndef __mpeg2psiparser_h__
#define __mpeg2psiparser_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IGenericDescriptor_FWD_DEFINED__
#define __IGenericDescriptor_FWD_DEFINED__
typedef interface IGenericDescriptor IGenericDescriptor;

#endif 	/* __IGenericDescriptor_FWD_DEFINED__ */


#ifndef __IGenericDescriptor2_FWD_DEFINED__
#define __IGenericDescriptor2_FWD_DEFINED__
typedef interface IGenericDescriptor2 IGenericDescriptor2;

#endif 	/* __IGenericDescriptor2_FWD_DEFINED__ */


#ifndef __IPAT_FWD_DEFINED__
#define __IPAT_FWD_DEFINED__
typedef interface IPAT IPAT;

#endif 	/* __IPAT_FWD_DEFINED__ */


#ifndef __ICAT_FWD_DEFINED__
#define __ICAT_FWD_DEFINED__
typedef interface ICAT ICAT;

#endif 	/* __ICAT_FWD_DEFINED__ */


#ifndef __IPMT_FWD_DEFINED__
#define __IPMT_FWD_DEFINED__
typedef interface IPMT IPMT;

#endif 	/* __IPMT_FWD_DEFINED__ */


#ifndef __ITSDT_FWD_DEFINED__
#define __ITSDT_FWD_DEFINED__
typedef interface ITSDT ITSDT;

#endif 	/* __ITSDT_FWD_DEFINED__ */


#ifndef __IPSITables_FWD_DEFINED__
#define __IPSITables_FWD_DEFINED__
typedef interface IPSITables IPSITables;

#endif 	/* __IPSITables_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "mpeg2structs.h"
#include "mpeg2data.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_mpeg2psiparser_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)




extern RPC_IF_HANDLE __MIDL_itf_mpeg2psiparser_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mpeg2psiparser_0000_0000_v0_0_s_ifspec;

#ifndef __IGenericDescriptor_INTERFACE_DEFINED__
#define __IGenericDescriptor_INTERFACE_DEFINED__

/* interface IGenericDescriptor */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IGenericDescriptor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A5918F8-A77A-4f61-AED0-5702BDCDA3E6")
    IGenericDescriptor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  BYTE *pbDesc,
            /* [annotation][in] */ 
            _In_  INT bCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTag( 
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLength( 
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBody( 
            /* [annotation][out] */ 
            _Out_  BYTE **ppbVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGenericDescriptorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGenericDescriptor * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGenericDescriptor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGenericDescriptor * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IGenericDescriptor * This,
            /* [annotation][in] */ 
            _In_  BYTE *pbDesc,
            /* [annotation][in] */ 
            _In_  INT bCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetTag )( 
            IGenericDescriptor * This,
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IGenericDescriptor * This,
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetBody )( 
            IGenericDescriptor * This,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbVal);
        
        END_INTERFACE
    } IGenericDescriptorVtbl;

    interface IGenericDescriptor
    {
        CONST_VTBL struct IGenericDescriptorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGenericDescriptor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGenericDescriptor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGenericDescriptor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGenericDescriptor_Initialize(This,pbDesc,bCount)	\
    ( (This)->lpVtbl -> Initialize(This,pbDesc,bCount) ) 

#define IGenericDescriptor_GetTag(This,pbVal)	\
    ( (This)->lpVtbl -> GetTag(This,pbVal) ) 

#define IGenericDescriptor_GetLength(This,pbVal)	\
    ( (This)->lpVtbl -> GetLength(This,pbVal) ) 

#define IGenericDescriptor_GetBody(This,ppbVal)	\
    ( (This)->lpVtbl -> GetBody(This,ppbVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGenericDescriptor_INTERFACE_DEFINED__ */


#ifndef __IGenericDescriptor2_INTERFACE_DEFINED__
#define __IGenericDescriptor2_INTERFACE_DEFINED__

/* interface IGenericDescriptor2 */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IGenericDescriptor2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BF02FB7E-9792-4e10-A68D-033A2CC246A5")
    IGenericDescriptor2 : public IGenericDescriptor
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  BYTE *pbDesc,
            /* [annotation][in] */ 
            _In_  WORD wCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLength( 
            /* [annotation][out] */ 
            _Out_  WORD *pwVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGenericDescriptor2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGenericDescriptor2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGenericDescriptor2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGenericDescriptor2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IGenericDescriptor2 * This,
            /* [annotation][in] */ 
            _In_  BYTE *pbDesc,
            /* [annotation][in] */ 
            _In_  INT bCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetTag )( 
            IGenericDescriptor2 * This,
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IGenericDescriptor2 * This,
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetBody )( 
            IGenericDescriptor2 * This,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbVal);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IGenericDescriptor2 * This,
            /* [annotation][in] */ 
            _In_  BYTE *pbDesc,
            /* [annotation][in] */ 
            _In_  WORD wCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IGenericDescriptor2 * This,
            /* [annotation][out] */ 
            _Out_  WORD *pwVal);
        
        END_INTERFACE
    } IGenericDescriptor2Vtbl;

    interface IGenericDescriptor2
    {
        CONST_VTBL struct IGenericDescriptor2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGenericDescriptor2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGenericDescriptor2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGenericDescriptor2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGenericDescriptor2_Initialize(This,pbDesc,bCount)	\
    ( (This)->lpVtbl -> Initialize(This,pbDesc,bCount) ) 

#define IGenericDescriptor2_GetTag(This,pbVal)	\
    ( (This)->lpVtbl -> GetTag(This,pbVal) ) 

#define IGenericDescriptor2_GetLength(This,pbVal)	\
    ( (This)->lpVtbl -> GetLength(This,pbVal) ) 

#define IGenericDescriptor2_GetBody(This,ppbVal)	\
    ( (This)->lpVtbl -> GetBody(This,ppbVal) ) 


#define IGenericDescriptor2_Initialize(This,pbDesc,wCount)	\
    ( (This)->lpVtbl -> Initialize(This,pbDesc,wCount) ) 

#define IGenericDescriptor2_GetLength(This,pwVal)	\
    ( (This)->lpVtbl -> GetLength(This,pwVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGenericDescriptor2_INTERFACE_DEFINED__ */


#ifndef __IPAT_INTERFACE_DEFINED__
#define __IPAT_INTERFACE_DEFINED__

/* interface IPAT */
/* [unique][uuid][local][object] */ 

typedef /* [public] */ struct __MIDL_IPAT_0001
    {
    WORD wProgramNumber;
    WORD wProgramMapPID;
    } 	ProgramElement;


EXTERN_C const IID IID_IPAT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6623B511-4B5F-43c3-9A01-E8FF84188060")
    IPAT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  ISectionList *pSectionList,
            /* [annotation][in] */ 
            _In_  IMpeg2Data *pMPEGData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransportStreamId( 
            /* [annotation][out] */ 
            _Out_  WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionNumber( 
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfRecords( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordProgramNumber( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordProgramMapPid( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindRecordProgramMapPid( 
            /* [annotation][in] */ 
            _In_  WORD wProgramNumber,
            /* [annotation][out] */ 
            _Out_  WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForNextTable( 
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableAvailable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextTable( 
            /* [annotation][out] */ 
            _Out_  IPAT **ppPAT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForWhenCurrent( 
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableIsCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertNextToCurrent( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPATVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPAT * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPAT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPAT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IPAT * This,
            /* [annotation][in] */ 
            _In_  ISectionList *pSectionList,
            /* [annotation][in] */ 
            _In_  IMpeg2Data *pMPEGData);
        
        HRESULT ( STDMETHODCALLTYPE *GetTransportStreamId )( 
            IPAT * This,
            /* [annotation][out] */ 
            _Out_  WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionNumber )( 
            IPAT * This,
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfRecords )( 
            IPAT * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordProgramNumber )( 
            IPAT * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordProgramMapPid )( 
            IPAT * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *FindRecordProgramMapPid )( 
            IPAT * This,
            /* [annotation][in] */ 
            _In_  WORD wProgramNumber,
            /* [annotation][out] */ 
            _Out_  WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForNextTable )( 
            IPAT * This,
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableAvailable);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextTable )( 
            IPAT * This,
            /* [annotation][out] */ 
            _Out_  IPAT **ppPAT);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForWhenCurrent )( 
            IPAT * This,
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableIsCurrent);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertNextToCurrent )( 
            IPAT * This);
        
        END_INTERFACE
    } IPATVtbl;

    interface IPAT
    {
        CONST_VTBL struct IPATVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPAT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPAT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPAT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPAT_Initialize(This,pSectionList,pMPEGData)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList,pMPEGData) ) 

#define IPAT_GetTransportStreamId(This,pwVal)	\
    ( (This)->lpVtbl -> GetTransportStreamId(This,pwVal) ) 

#define IPAT_GetVersionNumber(This,pbVal)	\
    ( (This)->lpVtbl -> GetVersionNumber(This,pbVal) ) 

#define IPAT_GetCountOfRecords(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfRecords(This,pdwVal) ) 

#define IPAT_GetRecordProgramNumber(This,dwIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordProgramNumber(This,dwIndex,pwVal) ) 

#define IPAT_GetRecordProgramMapPid(This,dwIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordProgramMapPid(This,dwIndex,pwVal) ) 

#define IPAT_FindRecordProgramMapPid(This,wProgramNumber,pwVal)	\
    ( (This)->lpVtbl -> FindRecordProgramMapPid(This,wProgramNumber,pwVal) ) 

#define IPAT_RegisterForNextTable(This,hNextTableAvailable)	\
    ( (This)->lpVtbl -> RegisterForNextTable(This,hNextTableAvailable) ) 

#define IPAT_GetNextTable(This,ppPAT)	\
    ( (This)->lpVtbl -> GetNextTable(This,ppPAT) ) 

#define IPAT_RegisterForWhenCurrent(This,hNextTableIsCurrent)	\
    ( (This)->lpVtbl -> RegisterForWhenCurrent(This,hNextTableIsCurrent) ) 

#define IPAT_ConvertNextToCurrent(This)	\
    ( (This)->lpVtbl -> ConvertNextToCurrent(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPAT_INTERFACE_DEFINED__ */


#ifndef __ICAT_INTERFACE_DEFINED__
#define __ICAT_INTERFACE_DEFINED__

/* interface ICAT */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_ICAT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7C6995FB-2A31-4bd7-953E-B1AD7FB7D31C")
    ICAT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  ISectionList *pSectionList,
            /* [annotation][in] */ 
            _In_  IMpeg2Data *pMPEGData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionNumber( 
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfTableDescriptors( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByIndex( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByTag( 
            /* [annotation][in] */ 
            _In_  BYTE bTag,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForNextTable( 
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableAvailable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextTable( 
            /* [annotation][in] */ 
            _In_  DWORD dwTimeout,
            /* [annotation][out] */ 
            _Out_  ICAT **ppCAT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForWhenCurrent( 
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableIsCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertNextToCurrent( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICATVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICAT * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICAT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICAT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ICAT * This,
            /* [annotation][in] */ 
            _In_  ISectionList *pSectionList,
            /* [annotation][in] */ 
            _In_  IMpeg2Data *pMPEGData);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionNumber )( 
            ICAT * This,
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfTableDescriptors )( 
            ICAT * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByIndex )( 
            ICAT * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByTag )( 
            ICAT * This,
            /* [annotation][in] */ 
            _In_  BYTE bTag,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForNextTable )( 
            ICAT * This,
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableAvailable);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextTable )( 
            ICAT * This,
            /* [annotation][in] */ 
            _In_  DWORD dwTimeout,
            /* [annotation][out] */ 
            _Out_  ICAT **ppCAT);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForWhenCurrent )( 
            ICAT * This,
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableIsCurrent);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertNextToCurrent )( 
            ICAT * This);
        
        END_INTERFACE
    } ICATVtbl;

    interface ICAT
    {
        CONST_VTBL struct ICATVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICAT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICAT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICAT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICAT_Initialize(This,pSectionList,pMPEGData)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList,pMPEGData) ) 

#define ICAT_GetVersionNumber(This,pbVal)	\
    ( (This)->lpVtbl -> GetVersionNumber(This,pbVal) ) 

#define ICAT_GetCountOfTableDescriptors(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfTableDescriptors(This,pdwVal) ) 

#define ICAT_GetTableDescriptorByIndex(This,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByIndex(This,dwIndex,ppDescriptor) ) 

#define ICAT_GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor) ) 

#define ICAT_RegisterForNextTable(This,hNextTableAvailable)	\
    ( (This)->lpVtbl -> RegisterForNextTable(This,hNextTableAvailable) ) 

#define ICAT_GetNextTable(This,dwTimeout,ppCAT)	\
    ( (This)->lpVtbl -> GetNextTable(This,dwTimeout,ppCAT) ) 

#define ICAT_RegisterForWhenCurrent(This,hNextTableIsCurrent)	\
    ( (This)->lpVtbl -> RegisterForWhenCurrent(This,hNextTableIsCurrent) ) 

#define ICAT_ConvertNextToCurrent(This)	\
    ( (This)->lpVtbl -> ConvertNextToCurrent(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICAT_INTERFACE_DEFINED__ */


#ifndef __IPMT_INTERFACE_DEFINED__
#define __IPMT_INTERFACE_DEFINED__

/* interface IPMT */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IPMT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("01F3B398-9527-4736-94DB-5195878E97A8")
    IPMT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  ISectionList *pSectionList,
            /* [annotation][in] */ 
            _In_  IMpeg2Data *pMPEGData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProgramNumber( 
            /* [annotation][out] */ 
            _Out_  WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionNumber( 
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPcrPid( 
            /* [annotation][out] */ 
            _Out_  PID *pPidVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfTableDescriptors( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByIndex( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByTag( 
            /* [annotation][in] */ 
            _In_  BYTE bTag,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfRecords( 
            /* [annotation][out] */ 
            _Out_  WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordStreamType( 
            /* [annotation][in] */ 
            _In_  DWORD dwRecordIndex,
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordElementaryPid( 
            /* [annotation][in] */ 
            _In_  DWORD dwRecordIndex,
            /* [annotation][out] */ 
            _Out_  PID *pPidVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordCountOfDescriptors( 
            /* [annotation][in] */ 
            _In_  DWORD dwRecordIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByIndex( 
            /* [annotation][in] */ 
            _In_  DWORD dwRecordIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwDescIndex,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByTag( 
            /* [annotation][in] */ 
            _In_  DWORD dwRecordIndex,
            /* [annotation][in] */ 
            _In_  BYTE bTag,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryServiceGatewayInfo( 
            /* [annotation][out] */ 
            _Out_  DSMCC_ELEMENT **ppDSMCCList,
            /* [annotation][out] */ 
            _Out_  UINT *puiCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryMPEInfo( 
            /* [annotation][out] */ 
            _Out_  MPE_ELEMENT **ppMPEList,
            /* [annotation][out] */ 
            _Out_  UINT *puiCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForNextTable( 
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableAvailable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextTable( 
            /* [annotation][out] */ 
            _Out_  IPMT **ppPMT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForWhenCurrent( 
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableIsCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertNextToCurrent( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPMTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPMT * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPMT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPMT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IPMT * This,
            /* [annotation][in] */ 
            _In_  ISectionList *pSectionList,
            /* [annotation][in] */ 
            _In_  IMpeg2Data *pMPEGData);
        
        HRESULT ( STDMETHODCALLTYPE *GetProgramNumber )( 
            IPMT * This,
            /* [annotation][out] */ 
            _Out_  WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionNumber )( 
            IPMT * This,
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetPcrPid )( 
            IPMT * This,
            /* [annotation][out] */ 
            _Out_  PID *pPidVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfTableDescriptors )( 
            IPMT * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByIndex )( 
            IPMT * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByTag )( 
            IPMT * This,
            /* [annotation][in] */ 
            _In_  BYTE bTag,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfRecords )( 
            IPMT * This,
            /* [annotation][out] */ 
            _Out_  WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordStreamType )( 
            IPMT * This,
            /* [annotation][in] */ 
            _In_  DWORD dwRecordIndex,
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordElementaryPid )( 
            IPMT * This,
            /* [annotation][in] */ 
            _In_  DWORD dwRecordIndex,
            /* [annotation][out] */ 
            _Out_  PID *pPidVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordCountOfDescriptors )( 
            IPMT * This,
            /* [annotation][in] */ 
            _In_  DWORD dwRecordIndex,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByIndex )( 
            IPMT * This,
            /* [annotation][in] */ 
            _In_  DWORD dwRecordIndex,
            /* [annotation][in] */ 
            _In_  DWORD dwDescIndex,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByTag )( 
            IPMT * This,
            /* [annotation][in] */ 
            _In_  DWORD dwRecordIndex,
            /* [annotation][in] */ 
            _In_  BYTE bTag,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *QueryServiceGatewayInfo )( 
            IPMT * This,
            /* [annotation][out] */ 
            _Out_  DSMCC_ELEMENT **ppDSMCCList,
            /* [annotation][out] */ 
            _Out_  UINT *puiCount);
        
        HRESULT ( STDMETHODCALLTYPE *QueryMPEInfo )( 
            IPMT * This,
            /* [annotation][out] */ 
            _Out_  MPE_ELEMENT **ppMPEList,
            /* [annotation][out] */ 
            _Out_  UINT *puiCount);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForNextTable )( 
            IPMT * This,
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableAvailable);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextTable )( 
            IPMT * This,
            /* [annotation][out] */ 
            _Out_  IPMT **ppPMT);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForWhenCurrent )( 
            IPMT * This,
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableIsCurrent);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertNextToCurrent )( 
            IPMT * This);
        
        END_INTERFACE
    } IPMTVtbl;

    interface IPMT
    {
        CONST_VTBL struct IPMTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPMT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPMT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPMT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPMT_Initialize(This,pSectionList,pMPEGData)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList,pMPEGData) ) 

#define IPMT_GetProgramNumber(This,pwVal)	\
    ( (This)->lpVtbl -> GetProgramNumber(This,pwVal) ) 

#define IPMT_GetVersionNumber(This,pbVal)	\
    ( (This)->lpVtbl -> GetVersionNumber(This,pbVal) ) 

#define IPMT_GetPcrPid(This,pPidVal)	\
    ( (This)->lpVtbl -> GetPcrPid(This,pPidVal) ) 

#define IPMT_GetCountOfTableDescriptors(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfTableDescriptors(This,pdwVal) ) 

#define IPMT_GetTableDescriptorByIndex(This,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByIndex(This,dwIndex,ppDescriptor) ) 

#define IPMT_GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor) ) 

#define IPMT_GetCountOfRecords(This,pwVal)	\
    ( (This)->lpVtbl -> GetCountOfRecords(This,pwVal) ) 

#define IPMT_GetRecordStreamType(This,dwRecordIndex,pbVal)	\
    ( (This)->lpVtbl -> GetRecordStreamType(This,dwRecordIndex,pbVal) ) 

#define IPMT_GetRecordElementaryPid(This,dwRecordIndex,pPidVal)	\
    ( (This)->lpVtbl -> GetRecordElementaryPid(This,dwRecordIndex,pPidVal) ) 

#define IPMT_GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal)	\
    ( (This)->lpVtbl -> GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal) ) 

#define IPMT_GetRecordDescriptorByIndex(This,dwRecordIndex,dwDescIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByIndex(This,dwRecordIndex,dwDescIndex,ppDescriptor) ) 

#define IPMT_GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor) ) 

#define IPMT_QueryServiceGatewayInfo(This,ppDSMCCList,puiCount)	\
    ( (This)->lpVtbl -> QueryServiceGatewayInfo(This,ppDSMCCList,puiCount) ) 

#define IPMT_QueryMPEInfo(This,ppMPEList,puiCount)	\
    ( (This)->lpVtbl -> QueryMPEInfo(This,ppMPEList,puiCount) ) 

#define IPMT_RegisterForNextTable(This,hNextTableAvailable)	\
    ( (This)->lpVtbl -> RegisterForNextTable(This,hNextTableAvailable) ) 

#define IPMT_GetNextTable(This,ppPMT)	\
    ( (This)->lpVtbl -> GetNextTable(This,ppPMT) ) 

#define IPMT_RegisterForWhenCurrent(This,hNextTableIsCurrent)	\
    ( (This)->lpVtbl -> RegisterForWhenCurrent(This,hNextTableIsCurrent) ) 

#define IPMT_ConvertNextToCurrent(This)	\
    ( (This)->lpVtbl -> ConvertNextToCurrent(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPMT_INTERFACE_DEFINED__ */


#ifndef __ITSDT_INTERFACE_DEFINED__
#define __ITSDT_INTERFACE_DEFINED__

/* interface ITSDT */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_ITSDT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D19BDB43-405B-4a7c-A791-C89110C33165")
    ITSDT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [annotation][in] */ 
            _In_  ISectionList *pSectionList,
            /* [annotation][in] */ 
            _In_  IMpeg2Data *pMPEGData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionNumber( 
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfTableDescriptors( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByIndex( 
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByTag( 
            /* [annotation][in] */ 
            _In_  BYTE bTag,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForNextTable( 
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableAvailable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextTable( 
            /* [annotation][out] */ 
            _Out_  ITSDT **ppTSDT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForWhenCurrent( 
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableIsCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertNextToCurrent( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITSDTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITSDT * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITSDT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITSDT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ITSDT * This,
            /* [annotation][in] */ 
            _In_  ISectionList *pSectionList,
            /* [annotation][in] */ 
            _In_  IMpeg2Data *pMPEGData);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionNumber )( 
            ITSDT * This,
            /* [annotation][out] */ 
            _Out_  BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfTableDescriptors )( 
            ITSDT * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByIndex )( 
            ITSDT * This,
            /* [annotation][in] */ 
            _In_  DWORD dwIndex,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByTag )( 
            ITSDT * This,
            /* [annotation][in] */ 
            _In_  BYTE bTag,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out] */ 
            _Out_  IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForNextTable )( 
            ITSDT * This,
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableAvailable);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextTable )( 
            ITSDT * This,
            /* [annotation][out] */ 
            _Out_  ITSDT **ppTSDT);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForWhenCurrent )( 
            ITSDT * This,
            /* [annotation][in] */ 
            _In_  HANDLE hNextTableIsCurrent);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertNextToCurrent )( 
            ITSDT * This);
        
        END_INTERFACE
    } ITSDTVtbl;

    interface ITSDT
    {
        CONST_VTBL struct ITSDTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITSDT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITSDT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITSDT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITSDT_Initialize(This,pSectionList,pMPEGData)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList,pMPEGData) ) 

#define ITSDT_GetVersionNumber(This,pbVal)	\
    ( (This)->lpVtbl -> GetVersionNumber(This,pbVal) ) 

#define ITSDT_GetCountOfTableDescriptors(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfTableDescriptors(This,pdwVal) ) 

#define ITSDT_GetTableDescriptorByIndex(This,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByIndex(This,dwIndex,ppDescriptor) ) 

#define ITSDT_GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor) ) 

#define ITSDT_RegisterForNextTable(This,hNextTableAvailable)	\
    ( (This)->lpVtbl -> RegisterForNextTable(This,hNextTableAvailable) ) 

#define ITSDT_GetNextTable(This,ppTSDT)	\
    ( (This)->lpVtbl -> GetNextTable(This,ppTSDT) ) 

#define ITSDT_RegisterForWhenCurrent(This,hNextTableIsCurrent)	\
    ( (This)->lpVtbl -> RegisterForWhenCurrent(This,hNextTableIsCurrent) ) 

#define ITSDT_ConvertNextToCurrent(This)	\
    ( (This)->lpVtbl -> ConvertNextToCurrent(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITSDT_INTERFACE_DEFINED__ */


#ifndef __IPSITables_INTERFACE_DEFINED__
#define __IPSITables_INTERFACE_DEFINED__

/* interface IPSITables */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPSITables;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("919F24C5-7B14-42ac-A4B0-2AE08DAF00AC")
    IPSITables : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTable( 
            /* [annotation][in] */ 
            _In_  DWORD dwTSID,
            /* [annotation][in] */ 
            _In_  DWORD dwTID_PID,
            /* [annotation][in] */ 
            _In_  DWORD dwHashedVer,
            /* [annotation][in] */ 
            _In_  DWORD dwPara4,
            /* [annotation][out] */ 
            _Out_  IUnknown **ppIUnknown) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPSITablesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IPSITables * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IPSITables * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IPSITables * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTable )( 
            __RPC__in IPSITables * This,
            /* [annotation][in] */ 
            _In_  DWORD dwTSID,
            /* [annotation][in] */ 
            _In_  DWORD dwTID_PID,
            /* [annotation][in] */ 
            _In_  DWORD dwHashedVer,
            /* [annotation][in] */ 
            _In_  DWORD dwPara4,
            /* [annotation][out] */ 
            _Out_  IUnknown **ppIUnknown);
        
        END_INTERFACE
    } IPSITablesVtbl;

    interface IPSITables
    {
        CONST_VTBL struct IPSITablesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSITables_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPSITables_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPSITables_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPSITables_GetTable(This,dwTSID,dwTID_PID,dwHashedVer,dwPara4,ppIUnknown)	\
    ( (This)->lpVtbl -> GetTable(This,dwTSID,dwTID_PID,dwHashedVer,dwPara4,ppIUnknown) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPSITables_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_mpeg2psiparser_0000_0007 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_mpeg2psiparser_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mpeg2psiparser_0000_0007_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



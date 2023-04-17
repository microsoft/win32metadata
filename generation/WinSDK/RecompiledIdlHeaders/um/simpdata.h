

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


#ifndef __simpdata_h__
#define __simpdata_h__

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

#ifndef __OLEDBSimpleProviderListener_FWD_DEFINED__
#define __OLEDBSimpleProviderListener_FWD_DEFINED__
typedef interface OLEDBSimpleProviderListener OLEDBSimpleProviderListener;

#endif 	/* __OLEDBSimpleProviderListener_FWD_DEFINED__ */


#ifndef __OLEDBSimpleProvider_FWD_DEFINED__
#define __OLEDBSimpleProvider_FWD_DEFINED__
typedef interface OLEDBSimpleProvider OLEDBSimpleProvider;

#endif 	/* __OLEDBSimpleProvider_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_simpdata_0000_0000 */
/* [local] */ 

//=--------------------------------------------------------------------------=
// simpdata.h
//=--------------------------------------------------------------------------=
// (C) Copyright 1995-1996 Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#pragma comment(lib,"uuid.lib")

//--------------------------------------------------------------------------
// OLE DB Simple Provider Toolkit

#ifndef SIMPDATA_H
#define SIMPDATA_H
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#ifdef _WIN64

typedef LONGLONG DBROWCOUNT;

typedef LONGLONG DB_LORDINAL;


#else

typedef LONG DBROWCOUNT;

typedef LONG DB_LORDINAL;

#endif	// _WIN64
#define OSP_IndexLabel      (0)
#define OSP_IndexAll        (~0)
#define OSP_IndexUnknown    (~0)



extern RPC_IF_HANDLE __MIDL_itf_simpdata_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_simpdata_0000_0000_v0_0_s_ifspec;


#ifndef __MSDAOSP_LIBRARY_DEFINED__
#define __MSDAOSP_LIBRARY_DEFINED__

/* library MSDAOSP */
/* [version][lcid][helpstring][uuid] */ 

typedef 
enum OSPFORMAT
    {
        OSPFORMAT_RAW	= 0,
        OSPFORMAT_DEFAULT	= 0,
        OSPFORMAT_FORMATTED	= 1,
        OSPFORMAT_HTML	= 2
    } 	OSPFORMAT;

typedef 
enum OSPRW
    {
        OSPRW_DEFAULT	= 1,
        OSPRW_READONLY	= 0,
        OSPRW_READWRITE	= 1,
        OSPRW_MIXED	= 2
    } 	OSPRW;

typedef 
enum OSPFIND
    {
        OSPFIND_DEFAULT	= 0,
        OSPFIND_UP	= 1,
        OSPFIND_CASESENSITIVE	= 2,
        OSPFIND_UPCASESENSITIVE	= 3
    } 	OSPFIND;

typedef 
enum OSPCOMP
    {
        OSPCOMP_EQ	= 1,
        OSPCOMP_DEFAULT	= 1,
        OSPCOMP_LT	= 2,
        OSPCOMP_LE	= 3,
        OSPCOMP_GE	= 4,
        OSPCOMP_GT	= 5,
        OSPCOMP_NE	= 6
    } 	OSPCOMP;

typedef 
enum OSPXFER
    {
        OSPXFER_COMPLETE	= 0,
        OSPXFER_ABORT	= 1,
        OSPXFER_ERROR	= 2
    } 	OSPXFER;

typedef OLEDBSimpleProvider *LPOLEDBSimpleProvider;

EXTERN_C const IID LIBID_MSDAOSP;

#ifndef __OLEDBSimpleProviderListener_INTERFACE_DEFINED__
#define __OLEDBSimpleProviderListener_INTERFACE_DEFINED__

/* interface OLEDBSimpleProviderListener */
/* [version][oleautomation][unique][uuid][object] */ 


EXTERN_C const IID IID_OLEDBSimpleProviderListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E0E270C1-C0BE-11d0-8FE4-00A0C90A6341")
    OLEDBSimpleProviderListener : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE aboutToChangeCell( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE cellChanged( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE aboutToDeleteRows( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE deletedRows( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE aboutToInsertRows( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE insertedRows( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE rowsAvailable( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE transferComplete( 
            /* [annotation][in] */ 
            _In_  OSPXFER xfer) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct OLEDBSimpleProviderListenerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in OLEDBSimpleProviderListener * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in OLEDBSimpleProviderListener * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in OLEDBSimpleProviderListener * This);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProviderListener, aboutToChangeCell)
        HRESULT ( STDMETHODCALLTYPE *aboutToChangeCell )( 
            __RPC__in OLEDBSimpleProviderListener * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProviderListener, cellChanged)
        HRESULT ( STDMETHODCALLTYPE *cellChanged )( 
            __RPC__in OLEDBSimpleProviderListener * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProviderListener, aboutToDeleteRows)
        HRESULT ( STDMETHODCALLTYPE *aboutToDeleteRows )( 
            __RPC__in OLEDBSimpleProviderListener * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProviderListener, deletedRows)
        HRESULT ( STDMETHODCALLTYPE *deletedRows )( 
            __RPC__in OLEDBSimpleProviderListener * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProviderListener, aboutToInsertRows)
        HRESULT ( STDMETHODCALLTYPE *aboutToInsertRows )( 
            __RPC__in OLEDBSimpleProviderListener * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProviderListener, insertedRows)
        HRESULT ( STDMETHODCALLTYPE *insertedRows )( 
            __RPC__in OLEDBSimpleProviderListener * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProviderListener, rowsAvailable)
        HRESULT ( STDMETHODCALLTYPE *rowsAvailable )( 
            __RPC__in OLEDBSimpleProviderListener * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProviderListener, transferComplete)
        HRESULT ( STDMETHODCALLTYPE *transferComplete )( 
            __RPC__in OLEDBSimpleProviderListener * This,
            /* [annotation][in] */ 
            _In_  OSPXFER xfer);
        
        END_INTERFACE
    } OLEDBSimpleProviderListenerVtbl;

    interface OLEDBSimpleProviderListener
    {
        CONST_VTBL struct OLEDBSimpleProviderListenerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define OLEDBSimpleProviderListener_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define OLEDBSimpleProviderListener_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define OLEDBSimpleProviderListener_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define OLEDBSimpleProviderListener_aboutToChangeCell(This,iRow,iColumn)	\
    ( (This)->lpVtbl -> aboutToChangeCell(This,iRow,iColumn) ) 

#define OLEDBSimpleProviderListener_cellChanged(This,iRow,iColumn)	\
    ( (This)->lpVtbl -> cellChanged(This,iRow,iColumn) ) 

#define OLEDBSimpleProviderListener_aboutToDeleteRows(This,iRow,cRows)	\
    ( (This)->lpVtbl -> aboutToDeleteRows(This,iRow,cRows) ) 

#define OLEDBSimpleProviderListener_deletedRows(This,iRow,cRows)	\
    ( (This)->lpVtbl -> deletedRows(This,iRow,cRows) ) 

#define OLEDBSimpleProviderListener_aboutToInsertRows(This,iRow,cRows)	\
    ( (This)->lpVtbl -> aboutToInsertRows(This,iRow,cRows) ) 

#define OLEDBSimpleProviderListener_insertedRows(This,iRow,cRows)	\
    ( (This)->lpVtbl -> insertedRows(This,iRow,cRows) ) 

#define OLEDBSimpleProviderListener_rowsAvailable(This,iRow,cRows)	\
    ( (This)->lpVtbl -> rowsAvailable(This,iRow,cRows) ) 

#define OLEDBSimpleProviderListener_transferComplete(This,xfer)	\
    ( (This)->lpVtbl -> transferComplete(This,xfer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __OLEDBSimpleProviderListener_INTERFACE_DEFINED__ */


#ifndef __OLEDBSimpleProvider_INTERFACE_DEFINED__
#define __OLEDBSimpleProvider_INTERFACE_DEFINED__

/* interface OLEDBSimpleProvider */
/* [version][oleautomation][unique][uuid][object] */ 


EXTERN_C const IID IID_OLEDBSimpleProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E0E270C0-C0BE-11d0-8FE4-00A0C90A6341")
    OLEDBSimpleProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getRowCount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DBROWCOUNT *pcRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getColumnCount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DB_LORDINAL *pcColumns) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRWStatus( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn,
            /* [annotation][retval][out] */ 
            _Out_retval_  OSPRW *prwStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getVariant( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn,
            /* [annotation][in] */ 
            _In_  OSPFORMAT format,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setVariant( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn,
            /* [annotation][in] */ 
            _In_  OSPFORMAT format,
            /* [annotation][in] */ 
            _In_  VARIANT Var) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getLocale( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrLocale) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE deleteRows( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows,
            /* [annotation][retval][out] */ 
            _Out_retval_  DBROWCOUNT *pcRowsDeleted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE insertRows( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows,
            /* [annotation][retval][out] */ 
            _Out_retval_  DBROWCOUNT *pcRowsInserted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE find( 
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRowStart,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn,
            /* [annotation][in] */ 
            _In_  VARIANT val,
            /* [annotation][in] */ 
            _In_  OSPFIND findFlags,
            /* [annotation][in] */ 
            _In_  OSPCOMP compType,
            /* [annotation][retval][out] */ 
            _Out_retval_  DBROWCOUNT *piRowFound) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE addOLEDBSimpleProviderListener( 
            /* [annotation][in] */ 
            _In_  OLEDBSimpleProviderListener *pospIListener) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE removeOLEDBSimpleProviderListener( 
            /* [annotation][in] */ 
            _In_  OLEDBSimpleProviderListener *pospIListener) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE isAsync( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pbAsynch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getEstimatedRows( 
            /* [annotation][retval][out] */ 
            _Out_retval_  DBROWCOUNT *piRows) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE stopTransfer( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct OLEDBSimpleProviderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in OLEDBSimpleProvider * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in OLEDBSimpleProvider * This);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, getRowCount)
        HRESULT ( STDMETHODCALLTYPE *getRowCount )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DBROWCOUNT *pcRows);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, getColumnCount)
        HRESULT ( STDMETHODCALLTYPE *getColumnCount )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DB_LORDINAL *pcColumns);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, getRWStatus)
        HRESULT ( STDMETHODCALLTYPE *getRWStatus )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn,
            /* [annotation][retval][out] */ 
            _Out_retval_  OSPRW *prwStatus);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, getVariant)
        HRESULT ( STDMETHODCALLTYPE *getVariant )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn,
            /* [annotation][in] */ 
            _In_  OSPFORMAT format,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVar);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, setVariant)
        HRESULT ( STDMETHODCALLTYPE *setVariant )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn,
            /* [annotation][in] */ 
            _In_  OSPFORMAT format,
            /* [annotation][in] */ 
            _In_  VARIANT Var);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, getLocale)
        HRESULT ( STDMETHODCALLTYPE *getLocale )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrLocale);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, deleteRows)
        HRESULT ( STDMETHODCALLTYPE *deleteRows )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows,
            /* [annotation][retval][out] */ 
            _Out_retval_  DBROWCOUNT *pcRowsDeleted);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, insertRows)
        HRESULT ( STDMETHODCALLTYPE *insertRows )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRow,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT cRows,
            /* [annotation][retval][out] */ 
            _Out_retval_  DBROWCOUNT *pcRowsInserted);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, find)
        HRESULT ( STDMETHODCALLTYPE *find )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][in] */ 
            _In_  DBROWCOUNT iRowStart,
            /* [annotation][in] */ 
            _In_  DB_LORDINAL iColumn,
            /* [annotation][in] */ 
            _In_  VARIANT val,
            /* [annotation][in] */ 
            _In_  OSPFIND findFlags,
            /* [annotation][in] */ 
            _In_  OSPCOMP compType,
            /* [annotation][retval][out] */ 
            _Out_retval_  DBROWCOUNT *piRowFound);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, addOLEDBSimpleProviderListener)
        HRESULT ( STDMETHODCALLTYPE *addOLEDBSimpleProviderListener )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][in] */ 
            _In_  OLEDBSimpleProviderListener *pospIListener);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, removeOLEDBSimpleProviderListener)
        HRESULT ( STDMETHODCALLTYPE *removeOLEDBSimpleProviderListener )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][in] */ 
            _In_  OLEDBSimpleProviderListener *pospIListener);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, isAsync)
        HRESULT ( STDMETHODCALLTYPE *isAsync )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *pbAsynch);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, getEstimatedRows)
        HRESULT ( STDMETHODCALLTYPE *getEstimatedRows )( 
            __RPC__in OLEDBSimpleProvider * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  DBROWCOUNT *piRows);
        
        DECLSPEC_XFGVIRT(OLEDBSimpleProvider, stopTransfer)
        HRESULT ( STDMETHODCALLTYPE *stopTransfer )( 
            __RPC__in OLEDBSimpleProvider * This);
        
        END_INTERFACE
    } OLEDBSimpleProviderVtbl;

    interface OLEDBSimpleProvider
    {
        CONST_VTBL struct OLEDBSimpleProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define OLEDBSimpleProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define OLEDBSimpleProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define OLEDBSimpleProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define OLEDBSimpleProvider_getRowCount(This,pcRows)	\
    ( (This)->lpVtbl -> getRowCount(This,pcRows) ) 

#define OLEDBSimpleProvider_getColumnCount(This,pcColumns)	\
    ( (This)->lpVtbl -> getColumnCount(This,pcColumns) ) 

#define OLEDBSimpleProvider_getRWStatus(This,iRow,iColumn,prwStatus)	\
    ( (This)->lpVtbl -> getRWStatus(This,iRow,iColumn,prwStatus) ) 

#define OLEDBSimpleProvider_getVariant(This,iRow,iColumn,format,pVar)	\
    ( (This)->lpVtbl -> getVariant(This,iRow,iColumn,format,pVar) ) 

#define OLEDBSimpleProvider_setVariant(This,iRow,iColumn,format,Var)	\
    ( (This)->lpVtbl -> setVariant(This,iRow,iColumn,format,Var) ) 

#define OLEDBSimpleProvider_getLocale(This,pbstrLocale)	\
    ( (This)->lpVtbl -> getLocale(This,pbstrLocale) ) 

#define OLEDBSimpleProvider_deleteRows(This,iRow,cRows,pcRowsDeleted)	\
    ( (This)->lpVtbl -> deleteRows(This,iRow,cRows,pcRowsDeleted) ) 

#define OLEDBSimpleProvider_insertRows(This,iRow,cRows,pcRowsInserted)	\
    ( (This)->lpVtbl -> insertRows(This,iRow,cRows,pcRowsInserted) ) 

#define OLEDBSimpleProvider_find(This,iRowStart,iColumn,val,findFlags,compType,piRowFound)	\
    ( (This)->lpVtbl -> find(This,iRowStart,iColumn,val,findFlags,compType,piRowFound) ) 

#define OLEDBSimpleProvider_addOLEDBSimpleProviderListener(This,pospIListener)	\
    ( (This)->lpVtbl -> addOLEDBSimpleProviderListener(This,pospIListener) ) 

#define OLEDBSimpleProvider_removeOLEDBSimpleProviderListener(This,pospIListener)	\
    ( (This)->lpVtbl -> removeOLEDBSimpleProviderListener(This,pospIListener) ) 

#define OLEDBSimpleProvider_isAsync(This,pbAsynch)	\
    ( (This)->lpVtbl -> isAsync(This,pbAsynch) ) 

#define OLEDBSimpleProvider_getEstimatedRows(This,piRows)	\
    ( (This)->lpVtbl -> getEstimatedRows(This,piRows) ) 

#define OLEDBSimpleProvider_stopTransfer(This)	\
    ( (This)->lpVtbl -> stopTransfer(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __OLEDBSimpleProvider_INTERFACE_DEFINED__ */

#endif /* __MSDAOSP_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_simpdata_0000_0001 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion
#endif


extern RPC_IF_HANDLE __MIDL_itf_simpdata_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_simpdata_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



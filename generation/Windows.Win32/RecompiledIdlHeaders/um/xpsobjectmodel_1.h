

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

#ifndef __xpsobjectmodel_1_h__
#define __xpsobjectmodel_1_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IXpsOMObjectFactory1_FWD_DEFINED__
#define __IXpsOMObjectFactory1_FWD_DEFINED__
typedef interface IXpsOMObjectFactory1 IXpsOMObjectFactory1;

#endif 	/* __IXpsOMObjectFactory1_FWD_DEFINED__ */


#ifndef __IXpsOMPackage1_FWD_DEFINED__
#define __IXpsOMPackage1_FWD_DEFINED__
typedef interface IXpsOMPackage1 IXpsOMPackage1;

#endif 	/* __IXpsOMPackage1_FWD_DEFINED__ */


#ifndef __IXpsOMPage1_FWD_DEFINED__
#define __IXpsOMPage1_FWD_DEFINED__
typedef interface IXpsOMPage1 IXpsOMPage1;

#endif 	/* __IXpsOMPage1_FWD_DEFINED__ */


#ifndef __IXpsDocumentPackageTarget_FWD_DEFINED__
#define __IXpsDocumentPackageTarget_FWD_DEFINED__
typedef interface IXpsDocumentPackageTarget IXpsDocumentPackageTarget;

#endif 	/* __IXpsDocumentPackageTarget_FWD_DEFINED__ */


#ifndef __IXpsOMRemoteDictionaryResource1_FWD_DEFINED__
#define __IXpsOMRemoteDictionaryResource1_FWD_DEFINED__
typedef interface IXpsOMRemoteDictionaryResource1 IXpsOMRemoteDictionaryResource1;

#endif 	/* __IXpsOMRemoteDictionaryResource1_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "XpsObjectModel.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_xpsobjectmodel_1_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------
#if (NTDDI_VERSION >= NTDDI_WIN8)
#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)



typedef /* [public][public][public][public][public][public][public][public][public][public][public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_xpsobjectmodel_1_0000_0000_0001
    {
        XPS_DOCUMENT_TYPE_UNSPECIFIED	= 1,
        XPS_DOCUMENT_TYPE_XPS	= ( XPS_DOCUMENT_TYPE_UNSPECIFIED + 1 ) ,
        XPS_DOCUMENT_TYPE_OPENXPS	= ( XPS_DOCUMENT_TYPE_XPS + 1 ) 
    } 	XPS_DOCUMENT_TYPE;



extern RPC_IF_HANDLE __MIDL_itf_xpsobjectmodel_1_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_xpsobjectmodel_1_0000_0000_v0_0_s_ifspec;

#ifndef __IXpsOMObjectFactory1_INTERFACE_DEFINED__
#define __IXpsOMObjectFactory1_INTERFACE_DEFINED__

/* interface IXpsOMObjectFactory1 */
/* [local][ref][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IXpsOMObjectFactory1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0a91b617-d612-4181-bf7c-be5824e9cc8f")
    IXpsOMObjectFactory1 : public IXpsOMObjectFactory
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDocumentTypeFromFile( 
            /* [annotation][in] */ 
            _In_  LPCWSTR filename,
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDocumentTypeFromStream( 
            /* [annotation][in] */ 
            _In_  IStream *xpsDocumentStream,
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertHDPhotoToJpegXR( 
            /* [annotation][out][in] */ 
            _Inout_  IXpsOMImageResource *imageResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertJpegXRToHDPhoto( 
            /* [annotation][out][in] */ 
            _Inout_  IXpsOMImageResource *imageResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePackageWriterOnFile1( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR fileName,
            /* [annotation][unique][in] */ 
            _In_  LPSECURITY_ATTRIBUTES securityAttributes,
            /* [annotation][in] */ 
            _In_  DWORD flagsAndAttributes,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_INTERLEAVING interleaving,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *documentSequencePartName,
            /* [annotation][in] */ 
            _In_  IXpsOMCoreProperties *coreProperties,
            /* [annotation][in] */ 
            _In_  IXpsOMImageResource *packageThumbnail,
            /* [annotation][in] */ 
            _In_  IXpsOMPrintTicketResource *documentSequencePrintTicket,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *discardControlPartName,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackageWriter **packageWriter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePackageWriterOnStream1( 
            /* [annotation][in] */ 
            _In_  ISequentialStream *outputStream,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_INTERLEAVING interleaving,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *documentSequencePartName,
            /* [annotation][in] */ 
            _In_  IXpsOMCoreProperties *coreProperties,
            /* [annotation][in] */ 
            _In_  IXpsOMImageResource *packageThumbnail,
            /* [annotation][in] */ 
            _In_  IXpsOMPrintTicketResource *documentSequencePrintTicket,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *discardControlPartName,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackageWriter **packageWriter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePackage1( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackage1 **package) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePackageFromStream1( 
            /* [annotation][in] */ 
            _In_  IStream *stream,
            /* [annotation][in] */ 
            _In_  BOOL reuseObjects,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackage1 **package) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePackageFromFile1( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR filename,
            /* [annotation][in] */ 
            _In_  BOOL reuseObjects,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackage1 **package) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePage1( 
            /* [annotation][in] */ 
            _In_  const XPS_SIZE *pageDimensions,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR language,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPage1 **page) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePageFromStream1( 
            /* [annotation][in] */ 
            _In_  IStream *pageMarkupStream,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][in] */ 
            _In_  IXpsOMPartResources *resources,
            /* [annotation][in] */ 
            _In_  BOOL reuseObjects,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPage1 **page) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateRemoteDictionaryResourceFromStream1( 
            /* [annotation][in] */ 
            _In_  IStream *dictionaryMarkupStream,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][in] */ 
            _In_  IXpsOMPartResources *resources,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMRemoteDictionaryResource **dictionaryResource) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXpsOMObjectFactory1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXpsOMObjectFactory1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXpsOMObjectFactory1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePackage )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackage **package);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePackageFromFile )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR filename,
            /* [annotation][in] */ 
            _In_  BOOL reuseObjects,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackage **package);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePackageFromStream )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *stream,
            /* [annotation][in] */ 
            _In_  BOOL reuseObjects,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackage **package);
        
        HRESULT ( STDMETHODCALLTYPE *CreateStoryFragmentsResource )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *acquiredStream,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMStoryFragmentsResource **storyFragmentsResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDocumentStructureResource )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *acquiredStream,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMDocumentStructureResource **documentStructureResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSignatureBlockResource )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *acquiredStream,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMSignatureBlockResource **signatureBlockResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreateRemoteDictionaryResource )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IXpsOMDictionary *dictionary,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMRemoteDictionaryResource **remoteDictionaryResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreateRemoteDictionaryResourceFromStream )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *dictionaryMarkupStream,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *dictionaryPartUri,
            /* [annotation][in] */ 
            _In_  IXpsOMPartResources *resources,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMRemoteDictionaryResource **dictionaryResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePartResources )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPartResources **partResources);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDocumentSequence )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMDocumentSequence **documentSequence);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDocument )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMDocument **document);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePageReference )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  const XPS_SIZE *advisoryPageDimensions,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPageReference **pageReference);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePage )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  const XPS_SIZE *pageDimensions,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR language,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPage **page);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePageFromStream )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *pageMarkupStream,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][in] */ 
            _In_  IXpsOMPartResources *resources,
            /* [annotation][in] */ 
            _In_  BOOL reuseObjects,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPage **page);
        
        HRESULT ( STDMETHODCALLTYPE *CreateCanvas )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMCanvas **canvas);
        
        HRESULT ( STDMETHODCALLTYPE *CreateGlyphs )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IXpsOMFontResource *fontResource,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMGlyphs **glyphs);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePath )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPath **path);
        
        HRESULT ( STDMETHODCALLTYPE *CreateGeometry )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMGeometry **geometry);
        
        HRESULT ( STDMETHODCALLTYPE *CreateGeometryFigure )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  const XPS_POINT *startPoint,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMGeometryFigure **figure);
        
        HRESULT ( STDMETHODCALLTYPE *CreateMatrixTransform )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  const XPS_MATRIX *matrix,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMMatrixTransform **transform);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSolidColorBrush )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  const XPS_COLOR *color,
            /* [annotation][in] */ 
            _In_  IXpsOMColorProfileResource *colorProfile,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMSolidColorBrush **solidColorBrush);
        
        HRESULT ( STDMETHODCALLTYPE *CreateColorProfileResource )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *acquiredStream,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMColorProfileResource **colorProfileResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreateImageBrush )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IXpsOMImageResource *image,
            /* [annotation][in] */ 
            _In_  const XPS_RECT *viewBox,
            /* [annotation][in] */ 
            _In_  const XPS_RECT *viewPort,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMImageBrush **imageBrush);
        
        HRESULT ( STDMETHODCALLTYPE *CreateVisualBrush )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  const XPS_RECT *viewBox,
            /* [annotation][in] */ 
            _In_  const XPS_RECT *viewPort,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMVisualBrush **visualBrush);
        
        HRESULT ( STDMETHODCALLTYPE *CreateImageResource )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *acquiredStream,
            /* [annotation][in] */ 
            _In_  XPS_IMAGE_TYPE contentType,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMImageResource **imageResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePrintTicketResource )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *acquiredStream,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPrintTicketResource **printTicketResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreateFontResource )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *acquiredStream,
            /* [annotation][in] */ 
            _In_  XPS_FONT_EMBEDDING fontEmbedding,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][in] */ 
            _In_  BOOL isObfSourceStream,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMFontResource **fontResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreateGradientStop )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  const XPS_COLOR *color,
            /* [annotation][in] */ 
            _In_  IXpsOMColorProfileResource *colorProfile,
            /* [annotation][in] */ 
            _In_  FLOAT offset,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMGradientStop **gradientStop);
        
        HRESULT ( STDMETHODCALLTYPE *CreateLinearGradientBrush )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IXpsOMGradientStop *gradStop1,
            /* [annotation][in] */ 
            _In_  IXpsOMGradientStop *gradStop2,
            /* [annotation][in] */ 
            _In_  const XPS_POINT *startPoint,
            /* [annotation][in] */ 
            _In_  const XPS_POINT *endPoint,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMLinearGradientBrush **linearGradientBrush);
        
        HRESULT ( STDMETHODCALLTYPE *CreateRadialGradientBrush )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IXpsOMGradientStop *gradStop1,
            /* [annotation][in] */ 
            _In_  IXpsOMGradientStop *gradStop2,
            /* [annotation][in] */ 
            _In_  const XPS_POINT *centerPoint,
            /* [annotation][in] */ 
            _In_  const XPS_POINT *gradientOrigin,
            /* [annotation][in] */ 
            _In_  const XPS_SIZE *radiiSizes,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMRadialGradientBrush **radialGradientBrush);
        
        HRESULT ( STDMETHODCALLTYPE *CreateCoreProperties )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMCoreProperties **coreProperties);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDictionary )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMDictionary **dictionary);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePartUriCollection )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPartUriCollection **partUriCollection);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePackageWriterOnFile )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR fileName,
            /* [annotation][unique][in] */ 
            _In_  LPSECURITY_ATTRIBUTES securityAttributes,
            /* [annotation][in] */ 
            _In_  DWORD flagsAndAttributes,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_INTERLEAVING interleaving,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *documentSequencePartName,
            /* [annotation][in] */ 
            _In_  IXpsOMCoreProperties *coreProperties,
            /* [annotation][in] */ 
            _In_  IXpsOMImageResource *packageThumbnail,
            /* [annotation][in] */ 
            _In_  IXpsOMPrintTicketResource *documentSequencePrintTicket,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *discardControlPartName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackageWriter **packageWriter);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePackageWriterOnStream )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  ISequentialStream *outputStream,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_INTERLEAVING interleaving,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *documentSequencePartName,
            /* [annotation][in] */ 
            _In_  IXpsOMCoreProperties *coreProperties,
            /* [annotation][in] */ 
            _In_  IXpsOMImageResource *packageThumbnail,
            /* [annotation][in] */ 
            _In_  IXpsOMPrintTicketResource *documentSequencePrintTicket,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *discardControlPartName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackageWriter **packageWriter);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePartUri )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR uri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IOpcPartUri **partUri);
        
        HRESULT ( STDMETHODCALLTYPE *CreateReadOnlyStreamOnFile )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR filename,
            /* [annotation][retval][out] */ 
            _Out_retval_  IStream **stream);
        
        HRESULT ( STDMETHODCALLTYPE *GetDocumentTypeFromFile )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR filename,
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType);
        
        HRESULT ( STDMETHODCALLTYPE *GetDocumentTypeFromStream )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *xpsDocumentStream,
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertHDPhotoToJpegXR )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][out][in] */ 
            _Inout_  IXpsOMImageResource *imageResource);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertJpegXRToHDPhoto )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][out][in] */ 
            _Inout_  IXpsOMImageResource *imageResource);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePackageWriterOnFile1 )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR fileName,
            /* [annotation][unique][in] */ 
            _In_  LPSECURITY_ATTRIBUTES securityAttributes,
            /* [annotation][in] */ 
            _In_  DWORD flagsAndAttributes,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_INTERLEAVING interleaving,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *documentSequencePartName,
            /* [annotation][in] */ 
            _In_  IXpsOMCoreProperties *coreProperties,
            /* [annotation][in] */ 
            _In_  IXpsOMImageResource *packageThumbnail,
            /* [annotation][in] */ 
            _In_  IXpsOMPrintTicketResource *documentSequencePrintTicket,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *discardControlPartName,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackageWriter **packageWriter);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePackageWriterOnStream1 )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  ISequentialStream *outputStream,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_INTERLEAVING interleaving,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *documentSequencePartName,
            /* [annotation][in] */ 
            _In_  IXpsOMCoreProperties *coreProperties,
            /* [annotation][in] */ 
            _In_  IXpsOMImageResource *packageThumbnail,
            /* [annotation][in] */ 
            _In_  IXpsOMPrintTicketResource *documentSequencePrintTicket,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *discardControlPartName,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackageWriter **packageWriter);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePackage1 )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackage1 **package);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePackageFromStream1 )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *stream,
            /* [annotation][in] */ 
            _In_  BOOL reuseObjects,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackage1 **package);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePackageFromFile1 )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR filename,
            /* [annotation][in] */ 
            _In_  BOOL reuseObjects,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackage1 **package);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePage1 )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  const XPS_SIZE *pageDimensions,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR language,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPage1 **page);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePageFromStream1 )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *pageMarkupStream,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][in] */ 
            _In_  IXpsOMPartResources *resources,
            /* [annotation][in] */ 
            _In_  BOOL reuseObjects,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPage1 **page);
        
        HRESULT ( STDMETHODCALLTYPE *CreateRemoteDictionaryResourceFromStream1 )( 
            IXpsOMObjectFactory1 * This,
            /* [annotation][in] */ 
            _In_  IStream *dictionaryMarkupStream,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri,
            /* [annotation][in] */ 
            _In_  IXpsOMPartResources *resources,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMRemoteDictionaryResource **dictionaryResource);
        
        END_INTERFACE
    } IXpsOMObjectFactory1Vtbl;

    interface IXpsOMObjectFactory1
    {
        CONST_VTBL struct IXpsOMObjectFactory1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXpsOMObjectFactory1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXpsOMObjectFactory1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXpsOMObjectFactory1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXpsOMObjectFactory1_CreatePackage(This,package)	\
    ( (This)->lpVtbl -> CreatePackage(This,package) ) 

#define IXpsOMObjectFactory1_CreatePackageFromFile(This,filename,reuseObjects,package)	\
    ( (This)->lpVtbl -> CreatePackageFromFile(This,filename,reuseObjects,package) ) 

#define IXpsOMObjectFactory1_CreatePackageFromStream(This,stream,reuseObjects,package)	\
    ( (This)->lpVtbl -> CreatePackageFromStream(This,stream,reuseObjects,package) ) 

#define IXpsOMObjectFactory1_CreateStoryFragmentsResource(This,acquiredStream,partUri,storyFragmentsResource)	\
    ( (This)->lpVtbl -> CreateStoryFragmentsResource(This,acquiredStream,partUri,storyFragmentsResource) ) 

#define IXpsOMObjectFactory1_CreateDocumentStructureResource(This,acquiredStream,partUri,documentStructureResource)	\
    ( (This)->lpVtbl -> CreateDocumentStructureResource(This,acquiredStream,partUri,documentStructureResource) ) 

#define IXpsOMObjectFactory1_CreateSignatureBlockResource(This,acquiredStream,partUri,signatureBlockResource)	\
    ( (This)->lpVtbl -> CreateSignatureBlockResource(This,acquiredStream,partUri,signatureBlockResource) ) 

#define IXpsOMObjectFactory1_CreateRemoteDictionaryResource(This,dictionary,partUri,remoteDictionaryResource)	\
    ( (This)->lpVtbl -> CreateRemoteDictionaryResource(This,dictionary,partUri,remoteDictionaryResource) ) 

#define IXpsOMObjectFactory1_CreateRemoteDictionaryResourceFromStream(This,dictionaryMarkupStream,dictionaryPartUri,resources,dictionaryResource)	\
    ( (This)->lpVtbl -> CreateRemoteDictionaryResourceFromStream(This,dictionaryMarkupStream,dictionaryPartUri,resources,dictionaryResource) ) 

#define IXpsOMObjectFactory1_CreatePartResources(This,partResources)	\
    ( (This)->lpVtbl -> CreatePartResources(This,partResources) ) 

#define IXpsOMObjectFactory1_CreateDocumentSequence(This,partUri,documentSequence)	\
    ( (This)->lpVtbl -> CreateDocumentSequence(This,partUri,documentSequence) ) 

#define IXpsOMObjectFactory1_CreateDocument(This,partUri,document)	\
    ( (This)->lpVtbl -> CreateDocument(This,partUri,document) ) 

#define IXpsOMObjectFactory1_CreatePageReference(This,advisoryPageDimensions,pageReference)	\
    ( (This)->lpVtbl -> CreatePageReference(This,advisoryPageDimensions,pageReference) ) 

#define IXpsOMObjectFactory1_CreatePage(This,pageDimensions,language,partUri,page)	\
    ( (This)->lpVtbl -> CreatePage(This,pageDimensions,language,partUri,page) ) 

#define IXpsOMObjectFactory1_CreatePageFromStream(This,pageMarkupStream,partUri,resources,reuseObjects,page)	\
    ( (This)->lpVtbl -> CreatePageFromStream(This,pageMarkupStream,partUri,resources,reuseObjects,page) ) 

#define IXpsOMObjectFactory1_CreateCanvas(This,canvas)	\
    ( (This)->lpVtbl -> CreateCanvas(This,canvas) ) 

#define IXpsOMObjectFactory1_CreateGlyphs(This,fontResource,glyphs)	\
    ( (This)->lpVtbl -> CreateGlyphs(This,fontResource,glyphs) ) 

#define IXpsOMObjectFactory1_CreatePath(This,path)	\
    ( (This)->lpVtbl -> CreatePath(This,path) ) 

#define IXpsOMObjectFactory1_CreateGeometry(This,geometry)	\
    ( (This)->lpVtbl -> CreateGeometry(This,geometry) ) 

#define IXpsOMObjectFactory1_CreateGeometryFigure(This,startPoint,figure)	\
    ( (This)->lpVtbl -> CreateGeometryFigure(This,startPoint,figure) ) 

#define IXpsOMObjectFactory1_CreateMatrixTransform(This,matrix,transform)	\
    ( (This)->lpVtbl -> CreateMatrixTransform(This,matrix,transform) ) 

#define IXpsOMObjectFactory1_CreateSolidColorBrush(This,color,colorProfile,solidColorBrush)	\
    ( (This)->lpVtbl -> CreateSolidColorBrush(This,color,colorProfile,solidColorBrush) ) 

#define IXpsOMObjectFactory1_CreateColorProfileResource(This,acquiredStream,partUri,colorProfileResource)	\
    ( (This)->lpVtbl -> CreateColorProfileResource(This,acquiredStream,partUri,colorProfileResource) ) 

#define IXpsOMObjectFactory1_CreateImageBrush(This,image,viewBox,viewPort,imageBrush)	\
    ( (This)->lpVtbl -> CreateImageBrush(This,image,viewBox,viewPort,imageBrush) ) 

#define IXpsOMObjectFactory1_CreateVisualBrush(This,viewBox,viewPort,visualBrush)	\
    ( (This)->lpVtbl -> CreateVisualBrush(This,viewBox,viewPort,visualBrush) ) 

#define IXpsOMObjectFactory1_CreateImageResource(This,acquiredStream,contentType,partUri,imageResource)	\
    ( (This)->lpVtbl -> CreateImageResource(This,acquiredStream,contentType,partUri,imageResource) ) 

#define IXpsOMObjectFactory1_CreatePrintTicketResource(This,acquiredStream,partUri,printTicketResource)	\
    ( (This)->lpVtbl -> CreatePrintTicketResource(This,acquiredStream,partUri,printTicketResource) ) 

#define IXpsOMObjectFactory1_CreateFontResource(This,acquiredStream,fontEmbedding,partUri,isObfSourceStream,fontResource)	\
    ( (This)->lpVtbl -> CreateFontResource(This,acquiredStream,fontEmbedding,partUri,isObfSourceStream,fontResource) ) 

#define IXpsOMObjectFactory1_CreateGradientStop(This,color,colorProfile,offset,gradientStop)	\
    ( (This)->lpVtbl -> CreateGradientStop(This,color,colorProfile,offset,gradientStop) ) 

#define IXpsOMObjectFactory1_CreateLinearGradientBrush(This,gradStop1,gradStop2,startPoint,endPoint,linearGradientBrush)	\
    ( (This)->lpVtbl -> CreateLinearGradientBrush(This,gradStop1,gradStop2,startPoint,endPoint,linearGradientBrush) ) 

#define IXpsOMObjectFactory1_CreateRadialGradientBrush(This,gradStop1,gradStop2,centerPoint,gradientOrigin,radiiSizes,radialGradientBrush)	\
    ( (This)->lpVtbl -> CreateRadialGradientBrush(This,gradStop1,gradStop2,centerPoint,gradientOrigin,radiiSizes,radialGradientBrush) ) 

#define IXpsOMObjectFactory1_CreateCoreProperties(This,partUri,coreProperties)	\
    ( (This)->lpVtbl -> CreateCoreProperties(This,partUri,coreProperties) ) 

#define IXpsOMObjectFactory1_CreateDictionary(This,dictionary)	\
    ( (This)->lpVtbl -> CreateDictionary(This,dictionary) ) 

#define IXpsOMObjectFactory1_CreatePartUriCollection(This,partUriCollection)	\
    ( (This)->lpVtbl -> CreatePartUriCollection(This,partUriCollection) ) 

#define IXpsOMObjectFactory1_CreatePackageWriterOnFile(This,fileName,securityAttributes,flagsAndAttributes,optimizeMarkupSize,interleaving,documentSequencePartName,coreProperties,packageThumbnail,documentSequencePrintTicket,discardControlPartName,packageWriter)	\
    ( (This)->lpVtbl -> CreatePackageWriterOnFile(This,fileName,securityAttributes,flagsAndAttributes,optimizeMarkupSize,interleaving,documentSequencePartName,coreProperties,packageThumbnail,documentSequencePrintTicket,discardControlPartName,packageWriter) ) 

#define IXpsOMObjectFactory1_CreatePackageWriterOnStream(This,outputStream,optimizeMarkupSize,interleaving,documentSequencePartName,coreProperties,packageThumbnail,documentSequencePrintTicket,discardControlPartName,packageWriter)	\
    ( (This)->lpVtbl -> CreatePackageWriterOnStream(This,outputStream,optimizeMarkupSize,interleaving,documentSequencePartName,coreProperties,packageThumbnail,documentSequencePrintTicket,discardControlPartName,packageWriter) ) 

#define IXpsOMObjectFactory1_CreatePartUri(This,uri,partUri)	\
    ( (This)->lpVtbl -> CreatePartUri(This,uri,partUri) ) 

#define IXpsOMObjectFactory1_CreateReadOnlyStreamOnFile(This,filename,stream)	\
    ( (This)->lpVtbl -> CreateReadOnlyStreamOnFile(This,filename,stream) ) 


#define IXpsOMObjectFactory1_GetDocumentTypeFromFile(This,filename,documentType)	\
    ( (This)->lpVtbl -> GetDocumentTypeFromFile(This,filename,documentType) ) 

#define IXpsOMObjectFactory1_GetDocumentTypeFromStream(This,xpsDocumentStream,documentType)	\
    ( (This)->lpVtbl -> GetDocumentTypeFromStream(This,xpsDocumentStream,documentType) ) 

#define IXpsOMObjectFactory1_ConvertHDPhotoToJpegXR(This,imageResource)	\
    ( (This)->lpVtbl -> ConvertHDPhotoToJpegXR(This,imageResource) ) 

#define IXpsOMObjectFactory1_ConvertJpegXRToHDPhoto(This,imageResource)	\
    ( (This)->lpVtbl -> ConvertJpegXRToHDPhoto(This,imageResource) ) 

#define IXpsOMObjectFactory1_CreatePackageWriterOnFile1(This,fileName,securityAttributes,flagsAndAttributes,optimizeMarkupSize,interleaving,documentSequencePartName,coreProperties,packageThumbnail,documentSequencePrintTicket,discardControlPartName,documentType,packageWriter)	\
    ( (This)->lpVtbl -> CreatePackageWriterOnFile1(This,fileName,securityAttributes,flagsAndAttributes,optimizeMarkupSize,interleaving,documentSequencePartName,coreProperties,packageThumbnail,documentSequencePrintTicket,discardControlPartName,documentType,packageWriter) ) 

#define IXpsOMObjectFactory1_CreatePackageWriterOnStream1(This,outputStream,optimizeMarkupSize,interleaving,documentSequencePartName,coreProperties,packageThumbnail,documentSequencePrintTicket,discardControlPartName,documentType,packageWriter)	\
    ( (This)->lpVtbl -> CreatePackageWriterOnStream1(This,outputStream,optimizeMarkupSize,interleaving,documentSequencePartName,coreProperties,packageThumbnail,documentSequencePrintTicket,discardControlPartName,documentType,packageWriter) ) 

#define IXpsOMObjectFactory1_CreatePackage1(This,package)	\
    ( (This)->lpVtbl -> CreatePackage1(This,package) ) 

#define IXpsOMObjectFactory1_CreatePackageFromStream1(This,stream,reuseObjects,package)	\
    ( (This)->lpVtbl -> CreatePackageFromStream1(This,stream,reuseObjects,package) ) 

#define IXpsOMObjectFactory1_CreatePackageFromFile1(This,filename,reuseObjects,package)	\
    ( (This)->lpVtbl -> CreatePackageFromFile1(This,filename,reuseObjects,package) ) 

#define IXpsOMObjectFactory1_CreatePage1(This,pageDimensions,language,partUri,page)	\
    ( (This)->lpVtbl -> CreatePage1(This,pageDimensions,language,partUri,page) ) 

#define IXpsOMObjectFactory1_CreatePageFromStream1(This,pageMarkupStream,partUri,resources,reuseObjects,page)	\
    ( (This)->lpVtbl -> CreatePageFromStream1(This,pageMarkupStream,partUri,resources,reuseObjects,page) ) 

#define IXpsOMObjectFactory1_CreateRemoteDictionaryResourceFromStream1(This,dictionaryMarkupStream,partUri,resources,dictionaryResource)	\
    ( (This)->lpVtbl -> CreateRemoteDictionaryResourceFromStream1(This,dictionaryMarkupStream,partUri,resources,dictionaryResource) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXpsOMObjectFactory1_INTERFACE_DEFINED__ */


#ifndef __IXpsOMPackage1_INTERFACE_DEFINED__
#define __IXpsOMPackage1_INTERFACE_DEFINED__

/* interface IXpsOMPackage1 */
/* [local][ref][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IXpsOMPackage1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95a9435e-12bb-461b-8e7f-c6adb04cd96a")
    IXpsOMPackage1 : public IXpsOMPackage
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDocumentType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteToFile1( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR fileName,
            /* [annotation][unique][in] */ 
            _In_  LPSECURITY_ATTRIBUTES securityAttributes,
            /* [annotation][in] */ 
            _In_  DWORD flagsAndAttributes,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteToStream1( 
            /* [annotation][in] */ 
            _In_  ISequentialStream *outputStream,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXpsOMPackage1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXpsOMPackage1 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXpsOMPackage1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXpsOMPackage1 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDocumentSequence )( 
            IXpsOMPackage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMDocumentSequence **documentSequence);
        
        HRESULT ( STDMETHODCALLTYPE *SetDocumentSequence )( 
            IXpsOMPackage1 * This,
            /* [annotation][in] */ 
            _In_  IXpsOMDocumentSequence *documentSequence);
        
        HRESULT ( STDMETHODCALLTYPE *GetCoreProperties )( 
            IXpsOMPackage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMCoreProperties **coreProperties);
        
        HRESULT ( STDMETHODCALLTYPE *SetCoreProperties )( 
            IXpsOMPackage1 * This,
            /* [annotation][in] */ 
            _In_  IXpsOMCoreProperties *coreProperties);
        
        HRESULT ( STDMETHODCALLTYPE *GetDiscardControlPartName )( 
            IXpsOMPackage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IOpcPartUri **discardControlPartUri);
        
        HRESULT ( STDMETHODCALLTYPE *SetDiscardControlPartName )( 
            IXpsOMPackage1 * This,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *discardControlPartUri);
        
        HRESULT ( STDMETHODCALLTYPE *GetThumbnailResource )( 
            IXpsOMPackage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMImageResource **imageResource);
        
        HRESULT ( STDMETHODCALLTYPE *SetThumbnailResource )( 
            IXpsOMPackage1 * This,
            /* [annotation][in] */ 
            _In_  IXpsOMImageResource *imageResource);
        
        HRESULT ( STDMETHODCALLTYPE *WriteToFile )( 
            IXpsOMPackage1 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR fileName,
            /* [annotation][unique][in] */ 
            _In_  LPSECURITY_ATTRIBUTES securityAttributes,
            /* [annotation][in] */ 
            _In_  DWORD flagsAndAttributes,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize);
        
        HRESULT ( STDMETHODCALLTYPE *WriteToStream )( 
            IXpsOMPackage1 * This,
            /* [annotation][in] */ 
            _In_  ISequentialStream *stream,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDocumentType )( 
            IXpsOMPackage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType);
        
        HRESULT ( STDMETHODCALLTYPE *WriteToFile1 )( 
            IXpsOMPackage1 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR fileName,
            /* [annotation][unique][in] */ 
            _In_  LPSECURITY_ATTRIBUTES securityAttributes,
            /* [annotation][in] */ 
            _In_  DWORD flagsAndAttributes,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType);
        
        HRESULT ( STDMETHODCALLTYPE *WriteToStream1 )( 
            IXpsOMPackage1 * This,
            /* [annotation][in] */ 
            _In_  ISequentialStream *outputStream,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType);
        
        END_INTERFACE
    } IXpsOMPackage1Vtbl;

    interface IXpsOMPackage1
    {
        CONST_VTBL struct IXpsOMPackage1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXpsOMPackage1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXpsOMPackage1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXpsOMPackage1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXpsOMPackage1_GetDocumentSequence(This,documentSequence)	\
    ( (This)->lpVtbl -> GetDocumentSequence(This,documentSequence) ) 

#define IXpsOMPackage1_SetDocumentSequence(This,documentSequence)	\
    ( (This)->lpVtbl -> SetDocumentSequence(This,documentSequence) ) 

#define IXpsOMPackage1_GetCoreProperties(This,coreProperties)	\
    ( (This)->lpVtbl -> GetCoreProperties(This,coreProperties) ) 

#define IXpsOMPackage1_SetCoreProperties(This,coreProperties)	\
    ( (This)->lpVtbl -> SetCoreProperties(This,coreProperties) ) 

#define IXpsOMPackage1_GetDiscardControlPartName(This,discardControlPartUri)	\
    ( (This)->lpVtbl -> GetDiscardControlPartName(This,discardControlPartUri) ) 

#define IXpsOMPackage1_SetDiscardControlPartName(This,discardControlPartUri)	\
    ( (This)->lpVtbl -> SetDiscardControlPartName(This,discardControlPartUri) ) 

#define IXpsOMPackage1_GetThumbnailResource(This,imageResource)	\
    ( (This)->lpVtbl -> GetThumbnailResource(This,imageResource) ) 

#define IXpsOMPackage1_SetThumbnailResource(This,imageResource)	\
    ( (This)->lpVtbl -> SetThumbnailResource(This,imageResource) ) 

#define IXpsOMPackage1_WriteToFile(This,fileName,securityAttributes,flagsAndAttributes,optimizeMarkupSize)	\
    ( (This)->lpVtbl -> WriteToFile(This,fileName,securityAttributes,flagsAndAttributes,optimizeMarkupSize) ) 

#define IXpsOMPackage1_WriteToStream(This,stream,optimizeMarkupSize)	\
    ( (This)->lpVtbl -> WriteToStream(This,stream,optimizeMarkupSize) ) 


#define IXpsOMPackage1_GetDocumentType(This,documentType)	\
    ( (This)->lpVtbl -> GetDocumentType(This,documentType) ) 

#define IXpsOMPackage1_WriteToFile1(This,fileName,securityAttributes,flagsAndAttributes,optimizeMarkupSize,documentType)	\
    ( (This)->lpVtbl -> WriteToFile1(This,fileName,securityAttributes,flagsAndAttributes,optimizeMarkupSize,documentType) ) 

#define IXpsOMPackage1_WriteToStream1(This,outputStream,optimizeMarkupSize,documentType)	\
    ( (This)->lpVtbl -> WriteToStream1(This,outputStream,optimizeMarkupSize,documentType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXpsOMPackage1_INTERFACE_DEFINED__ */


#ifndef __IXpsOMPage1_INTERFACE_DEFINED__
#define __IXpsOMPage1_INTERFACE_DEFINED__

/* interface IXpsOMPage1 */
/* [local][ref][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IXpsOMPage1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("305b60ef-6892-4dda-9cbb-3aa65974508a")
    IXpsOMPage1 : public IXpsOMPage
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDocumentType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write1( 
            /* [annotation][in] */ 
            _In_  ISequentialStream *stream,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXpsOMPage1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXpsOMPage1 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXpsOMPage1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXpsOMPage1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPartName )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IOpcPartUri **partUri);
        
        HRESULT ( STDMETHODCALLTYPE *SetPartName )( 
            IXpsOMPage1 * This,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri);
        
        HRESULT ( STDMETHODCALLTYPE *GetOwner )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPageReference **pageReference);
        
        HRESULT ( STDMETHODCALLTYPE *GetVisuals )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMVisualCollection **visuals);
        
        HRESULT ( STDMETHODCALLTYPE *GetPageDimensions )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_SIZE *pageDimensions);
        
        HRESULT ( STDMETHODCALLTYPE *SetPageDimensions )( 
            IXpsOMPage1 * This,
            /* [annotation][in] */ 
            _In_  const XPS_SIZE *pageDimensions);
        
        HRESULT ( STDMETHODCALLTYPE *GetContentBox )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_RECT *contentBox);
        
        HRESULT ( STDMETHODCALLTYPE *SetContentBox )( 
            IXpsOMPage1 * This,
            /* [annotation][in] */ 
            _In_  const XPS_RECT *contentBox);
        
        HRESULT ( STDMETHODCALLTYPE *GetBleedBox )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_RECT *bleedBox);
        
        HRESULT ( STDMETHODCALLTYPE *SetBleedBox )( 
            IXpsOMPage1 * This,
            /* [annotation][in] */ 
            _In_  const XPS_RECT *bleedBox);
        
        HRESULT ( STDMETHODCALLTYPE *GetLanguage )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *language);
        
        HRESULT ( STDMETHODCALLTYPE *SetLanguage )( 
            IXpsOMPage1 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR language);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *name);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IXpsOMPage1 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *GetIsHyperlinkTarget )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BOOL *isHyperlinkTarget);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsHyperlinkTarget )( 
            IXpsOMPage1 * This,
            /* [annotation][in] */ 
            _In_  BOOL isHyperlinkTarget);
        
        HRESULT ( STDMETHODCALLTYPE *GetDictionary )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMDictionary **resourceDictionary);
        
        HRESULT ( STDMETHODCALLTYPE *GetDictionaryLocal )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMDictionary **resourceDictionary);
        
        HRESULT ( STDMETHODCALLTYPE *SetDictionaryLocal )( 
            IXpsOMPage1 * This,
            /* [annotation][in] */ 
            _In_  IXpsOMDictionary *resourceDictionary);
        
        HRESULT ( STDMETHODCALLTYPE *GetDictionaryResource )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMRemoteDictionaryResource **remoteDictionaryResource);
        
        HRESULT ( STDMETHODCALLTYPE *SetDictionaryResource )( 
            IXpsOMPage1 * This,
            /* [annotation][in] */ 
            _In_  IXpsOMRemoteDictionaryResource *remoteDictionaryResource);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IXpsOMPage1 * This,
            /* [annotation][in] */ 
            _In_  ISequentialStream *stream,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize);
        
        HRESULT ( STDMETHODCALLTYPE *GenerateUnusedLookupKey )( 
            IXpsOMPage1 * This,
            /* [annotation][in] */ 
            _In_  XPS_OBJECT_TYPE type,
            /* [annotation][retval][string][out] */ 
            _Out_retval_  LPWSTR *key);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPage **page);
        
        HRESULT ( STDMETHODCALLTYPE *GetDocumentType )( 
            IXpsOMPage1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType);
        
        HRESULT ( STDMETHODCALLTYPE *Write1 )( 
            IXpsOMPage1 * This,
            /* [annotation][in] */ 
            _In_  ISequentialStream *stream,
            /* [annotation][in] */ 
            _In_  BOOL optimizeMarkupSize,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType);
        
        END_INTERFACE
    } IXpsOMPage1Vtbl;

    interface IXpsOMPage1
    {
        CONST_VTBL struct IXpsOMPage1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXpsOMPage1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXpsOMPage1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXpsOMPage1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXpsOMPage1_GetPartName(This,partUri)	\
    ( (This)->lpVtbl -> GetPartName(This,partUri) ) 

#define IXpsOMPage1_SetPartName(This,partUri)	\
    ( (This)->lpVtbl -> SetPartName(This,partUri) ) 


#define IXpsOMPage1_GetOwner(This,pageReference)	\
    ( (This)->lpVtbl -> GetOwner(This,pageReference) ) 

#define IXpsOMPage1_GetVisuals(This,visuals)	\
    ( (This)->lpVtbl -> GetVisuals(This,visuals) ) 

#define IXpsOMPage1_GetPageDimensions(This,pageDimensions)	\
    ( (This)->lpVtbl -> GetPageDimensions(This,pageDimensions) ) 

#define IXpsOMPage1_SetPageDimensions(This,pageDimensions)	\
    ( (This)->lpVtbl -> SetPageDimensions(This,pageDimensions) ) 

#define IXpsOMPage1_GetContentBox(This,contentBox)	\
    ( (This)->lpVtbl -> GetContentBox(This,contentBox) ) 

#define IXpsOMPage1_SetContentBox(This,contentBox)	\
    ( (This)->lpVtbl -> SetContentBox(This,contentBox) ) 

#define IXpsOMPage1_GetBleedBox(This,bleedBox)	\
    ( (This)->lpVtbl -> GetBleedBox(This,bleedBox) ) 

#define IXpsOMPage1_SetBleedBox(This,bleedBox)	\
    ( (This)->lpVtbl -> SetBleedBox(This,bleedBox) ) 

#define IXpsOMPage1_GetLanguage(This,language)	\
    ( (This)->lpVtbl -> GetLanguage(This,language) ) 

#define IXpsOMPage1_SetLanguage(This,language)	\
    ( (This)->lpVtbl -> SetLanguage(This,language) ) 

#define IXpsOMPage1_GetName(This,name)	\
    ( (This)->lpVtbl -> GetName(This,name) ) 

#define IXpsOMPage1_SetName(This,name)	\
    ( (This)->lpVtbl -> SetName(This,name) ) 

#define IXpsOMPage1_GetIsHyperlinkTarget(This,isHyperlinkTarget)	\
    ( (This)->lpVtbl -> GetIsHyperlinkTarget(This,isHyperlinkTarget) ) 

#define IXpsOMPage1_SetIsHyperlinkTarget(This,isHyperlinkTarget)	\
    ( (This)->lpVtbl -> SetIsHyperlinkTarget(This,isHyperlinkTarget) ) 

#define IXpsOMPage1_GetDictionary(This,resourceDictionary)	\
    ( (This)->lpVtbl -> GetDictionary(This,resourceDictionary) ) 

#define IXpsOMPage1_GetDictionaryLocal(This,resourceDictionary)	\
    ( (This)->lpVtbl -> GetDictionaryLocal(This,resourceDictionary) ) 

#define IXpsOMPage1_SetDictionaryLocal(This,resourceDictionary)	\
    ( (This)->lpVtbl -> SetDictionaryLocal(This,resourceDictionary) ) 

#define IXpsOMPage1_GetDictionaryResource(This,remoteDictionaryResource)	\
    ( (This)->lpVtbl -> GetDictionaryResource(This,remoteDictionaryResource) ) 

#define IXpsOMPage1_SetDictionaryResource(This,remoteDictionaryResource)	\
    ( (This)->lpVtbl -> SetDictionaryResource(This,remoteDictionaryResource) ) 

#define IXpsOMPage1_Write(This,stream,optimizeMarkupSize)	\
    ( (This)->lpVtbl -> Write(This,stream,optimizeMarkupSize) ) 

#define IXpsOMPage1_GenerateUnusedLookupKey(This,type,key)	\
    ( (This)->lpVtbl -> GenerateUnusedLookupKey(This,type,key) ) 

#define IXpsOMPage1_Clone(This,page)	\
    ( (This)->lpVtbl -> Clone(This,page) ) 


#define IXpsOMPage1_GetDocumentType(This,documentType)	\
    ( (This)->lpVtbl -> GetDocumentType(This,documentType) ) 

#define IXpsOMPage1_Write1(This,stream,optimizeMarkupSize,documentType)	\
    ( (This)->lpVtbl -> Write1(This,stream,optimizeMarkupSize,documentType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXpsOMPage1_INTERFACE_DEFINED__ */


#ifndef __IXpsDocumentPackageTarget_INTERFACE_DEFINED__
#define __IXpsDocumentPackageTarget_INTERFACE_DEFINED__

/* interface IXpsDocumentPackageTarget */
/* [local][ref][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IXpsDocumentPackageTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3b0b6d38-53ad-41da-b212-d37637a6714e")
    IXpsDocumentPackageTarget : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetXpsOMPackageWriter( 
            /* [annotation][in] */ 
            _In_  IOpcPartUri *documentSequencePartName,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *discardControlPartName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackageWriter **packageWriter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetXpsOMFactory( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMObjectFactory **xpsFactory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetXpsType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXpsDocumentPackageTargetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXpsDocumentPackageTarget * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXpsDocumentPackageTarget * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXpsDocumentPackageTarget * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetXpsOMPackageWriter )( 
            IXpsDocumentPackageTarget * This,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *documentSequencePartName,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *discardControlPartName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMPackageWriter **packageWriter);
        
        HRESULT ( STDMETHODCALLTYPE *GetXpsOMFactory )( 
            IXpsDocumentPackageTarget * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMObjectFactory **xpsFactory);
        
        HRESULT ( STDMETHODCALLTYPE *GetXpsType )( 
            IXpsDocumentPackageTarget * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType);
        
        END_INTERFACE
    } IXpsDocumentPackageTargetVtbl;

    interface IXpsDocumentPackageTarget
    {
        CONST_VTBL struct IXpsDocumentPackageTargetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXpsDocumentPackageTarget_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXpsDocumentPackageTarget_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXpsDocumentPackageTarget_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXpsDocumentPackageTarget_GetXpsOMPackageWriter(This,documentSequencePartName,discardControlPartName,packageWriter)	\
    ( (This)->lpVtbl -> GetXpsOMPackageWriter(This,documentSequencePartName,discardControlPartName,packageWriter) ) 

#define IXpsDocumentPackageTarget_GetXpsOMFactory(This,xpsFactory)	\
    ( (This)->lpVtbl -> GetXpsOMFactory(This,xpsFactory) ) 

#define IXpsDocumentPackageTarget_GetXpsType(This,documentType)	\
    ( (This)->lpVtbl -> GetXpsType(This,documentType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXpsDocumentPackageTarget_INTERFACE_DEFINED__ */


#ifndef __IXpsOMRemoteDictionaryResource1_INTERFACE_DEFINED__
#define __IXpsOMRemoteDictionaryResource1_INTERFACE_DEFINED__

/* interface IXpsOMRemoteDictionaryResource1 */
/* [local][ref][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IXpsOMRemoteDictionaryResource1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BF8FC1D4-9D46-4141-BA5F-94BB9250D041")
    IXpsOMRemoteDictionaryResource1 : public IXpsOMRemoteDictionaryResource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDocumentType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write1( 
            /* [annotation][in] */ 
            _In_  ISequentialStream *stream,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXpsOMRemoteDictionaryResource1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXpsOMRemoteDictionaryResource1 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXpsOMRemoteDictionaryResource1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXpsOMRemoteDictionaryResource1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPartName )( 
            IXpsOMRemoteDictionaryResource1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IOpcPartUri **partUri);
        
        HRESULT ( STDMETHODCALLTYPE *SetPartName )( 
            IXpsOMRemoteDictionaryResource1 * This,
            /* [annotation][in] */ 
            _In_  IOpcPartUri *partUri);
        
        HRESULT ( STDMETHODCALLTYPE *GetDictionary )( 
            IXpsOMRemoteDictionaryResource1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IXpsOMDictionary **dictionary);
        
        HRESULT ( STDMETHODCALLTYPE *SetDictionary )( 
            IXpsOMRemoteDictionaryResource1 * This,
            /* [annotation][in] */ 
            _In_  IXpsOMDictionary *dictionary);
        
        HRESULT ( STDMETHODCALLTYPE *GetDocumentType )( 
            IXpsOMRemoteDictionaryResource1 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  XPS_DOCUMENT_TYPE *documentType);
        
        HRESULT ( STDMETHODCALLTYPE *Write1 )( 
            IXpsOMRemoteDictionaryResource1 * This,
            /* [annotation][in] */ 
            _In_  ISequentialStream *stream,
            /* [annotation][in] */ 
            _In_  XPS_DOCUMENT_TYPE documentType);
        
        END_INTERFACE
    } IXpsOMRemoteDictionaryResource1Vtbl;

    interface IXpsOMRemoteDictionaryResource1
    {
        CONST_VTBL struct IXpsOMRemoteDictionaryResource1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXpsOMRemoteDictionaryResource1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXpsOMRemoteDictionaryResource1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXpsOMRemoteDictionaryResource1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXpsOMRemoteDictionaryResource1_GetPartName(This,partUri)	\
    ( (This)->lpVtbl -> GetPartName(This,partUri) ) 

#define IXpsOMRemoteDictionaryResource1_SetPartName(This,partUri)	\
    ( (This)->lpVtbl -> SetPartName(This,partUri) ) 



#define IXpsOMRemoteDictionaryResource1_GetDictionary(This,dictionary)	\
    ( (This)->lpVtbl -> GetDictionary(This,dictionary) ) 

#define IXpsOMRemoteDictionaryResource1_SetDictionary(This,dictionary)	\
    ( (This)->lpVtbl -> SetDictionary(This,dictionary) ) 


#define IXpsOMRemoteDictionaryResource1_GetDocumentType(This,documentType)	\
    ( (This)->lpVtbl -> GetDocumentType(This,documentType) ) 

#define IXpsOMRemoteDictionaryResource1_Write1(This,stream,documentType)	\
    ( (This)->lpVtbl -> Write1(This,stream,documentType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXpsOMRemoteDictionaryResource1_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_xpsobjectmodel_1_0000_0005 */
/* [local] */ 

#define XPS_E_INVALID_NUMBER_OF_POINTS_IN_CURVE_SEGMENTS     MAKE_HRESULT(1, FACILITY_XPS, 0x600) 
#define XPS_E_ABSOLUTE_REFERENCE                             MAKE_HRESULT(1, FACILITY_XPS, 0x601) 
#define XPS_E_INVALID_NUMBER_OF_COLOR_CHANNELS               MAKE_HRESULT(1, FACILITY_XPS, 0x602) 
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */
#pragma endregion
#endif // (NTDDI >= NTDDI_WIN8)


extern RPC_IF_HANDLE __MIDL_itf_xpsobjectmodel_1_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_xpsobjectmodel_1_0000_0005_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



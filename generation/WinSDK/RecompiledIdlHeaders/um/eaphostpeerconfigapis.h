///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) Microsoft Corporation
//
// SYNOPSIS
//
//   Declares methods that are used to configure EAP methods.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef EAPHOSTPEERCONFIGAPIS_H
#define EAPHOSTPEERCONFIGAPIS_H
#pragma once
#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


#include "objbase.h"    //Required by msxml2.h
#include "msxml6.h"

#include "EapTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


// This API is used to enumerate all the EAP Methods installed and available for use; this
// includes legacy EAP Methods too. Returns non zero return code up on error.
DWORD WINAPI EapHostPeerGetMethods(
                // API fills the structure to have installed EAP Methods. Caller should free the inner pointers
                // using EapHostPeerFreeMemory starting at the inner most pointer.
                OUT EAP_METHOD_INFO_ARRAY* pEapMethodInfoArray,
                // In case of error, API fills ppEapError if possible. Caller should free ppEapError using EapHostPeerFreeErrorMemory
                OUT EAP_ERROR** ppEapError
                );


// This API is used to retrieve the method properties for a specific configuration
// It returns non zero return code upon error.
DWORD WINAPI EapHostPeerGetMethodProperties(
                // The version number of the API.
                IN DWORD dwVersion,
                // A combination of EAP flags that describe the EAP authentication session behavior.
                IN DWORD dwFlags,
                // An EAP_METHOD_TYPE structure that identifies the EAP method the supplicant is to use.
                IN EAP_METHOD_TYPE eapMethodType,
                // A handle to the user impersonation token to use in this session.
                IN HANDLE hUserImpersonationToken,
                // The size, in bytes, of the connection data buffer provided in pbEapConnData.
                IN DWORD dwEapConnDataSize,
                // Connection data used for the EAP method.
                IN _In_reads_(dwEapConnDataSize) const BYTE* pbEapConnData,
                // The size in bytes of the user data buffer provided in pbUserData.
                IN DWORD dwUserDataSize,
                // A pointer to a byte buffer that contains the opaque user data BLOB.
                IN _In_reads_(dwUserDataSize) const BYTE* pbUserData,
                // A pointer to the method properties array. Caller should free the inner pointers using EapHostPeerFreeMemory starting
                // at the inner most pointer. The caller should free empvString value only when the type is empvtString.
                OUT EAP_METHOD_PROPERTY_ARRAY* pMethodPropertyArray,
                // A pointer to a pointer to an EAP_ERROR structure that contains any errors raised by EAPHost
                // during the execution of this function call.
                OUT EAP_ERROR** ppEapError
                );


// This API is used to invoke configure UI of the specified EAP Method.
// API Returns non zero return code up on error.
DWORD WINAPI EapHostPeerInvokeConfigUI(
                // window handle of the parent window under which configuration dialog will show up
                IN HWND hwndParent,
                // Flags to control the behavior of the EAP Method.
                IN DWORD dwFlags,
                // Identifies the EAP Method to configure
                IN EAP_METHOD_TYPE eapMethodType,
                // Size of input configuration; this could be 0 when there is no configuration
                IN DWORD dwSizeOfConfigIn,
                // input configuration, this couldb NULL when there is no configuration
                IN _In_reads_opt_(dwSizeOfConfigIn) const BYTE* pConfigIn,
                // pointer to DWORD that receives configuration after user updated using UI
                OUT DWORD* pdwSizeOfConfigOut,
                // buffer that receives updated configuration after user updated using UI.
                // Caller should free the memory using EapHostPeerFreeMemory.
                OUT BYTE** ppConfigOut,
                // In case of error, API fills ppEapError if possible. Caller should free ppEapError using EapHostPeerFreeErrorMemory
                OUT EAP_ERROR** ppEapError
                );

// This API is used to obtain the fields to be shown in Single Sign On scenario for
// showing UI in long screen. The structures returned have details on how to show the fields.
// API Returns non zero return code up on error.
DWORD WINAPI EapHostPeerQueryCredentialInputFields(
                // handle to the impersonation token that is used while signle sign on.
                IN HANDLE hUserImpersonationToken,
                // identifies the EAP Method supplicant wants to use
                IN EAP_METHOD_TYPE eapMethodType,
                // control the behavior of the EAP Methods
                IN DWORD dwFlags,
                // size of input configuration data
                IN DWORD dwEapConnDataSize,
                // configuration data that is used for the EAP method
                IN _In_reads_(dwEapConnDataSize) const BYTE* pbEapConnData,
                // structure that gets filled with fields and how they should be shown to the user.
                // Caller should free the inner pointers using EapHostPeerFreeMemory starting
                // at the inner most pointer.
                OUT EAP_CONFIG_INPUT_FIELD_ARRAY *pEapConfigInputFieldArray,
                // In case of error, API fills ppEapError if possible. Caller should free ppEapError using EapHostPeerFreeErrorMemory
                OUT EAP_ERROR** ppEapError
                );


// Supplicant up on receiving user inputs from Single Sign On UI, calls this API to obtain
// credential blob that could used start authentication
// API Returns non zero return code up on error.
DWORD WINAPI EapHostPeerQueryUserBlobFromCredentialInputFields(
                // handle to the impersonation token that is used while signle sign on.
                IN HANDLE hUserImpersonationToken,
                // identifies the EAP Method supplicant wants to use
                IN EAP_METHOD_TYPE eapMethodType,
                // control the behavior of the EAP Methods
                IN DWORD dwFlags,
                // size of input configuration data
                IN DWORD dwEapConnDataSize,
                // configuration data that is used for the EAP method
                IN _In_reads_(dwEapConnDataSize) const BYTE* pbEapConnData,
                // structure containing the data entered by the user in Single Sign On UI
                IN const EAP_CONFIG_INPUT_FIELD_ARRAY *pEapConfigInputFieldArray,
                // pointer to DWORD that receives the size of credential blob, if supplicant passes in
                // non-zero size and non-NULL data below, EAPHost will just attempt to Update
                // the blob with passed in values (if method supports) instead of creating a new one.
                _Inout_ DWORD *pdwUserBlobSize,
                // Pointer that receives the credential blob that can be used in authentication.
                // For incoming data caller should always allocate this memory using LocalAlloc()
                // Caller should free the memory using EapHostPeerFreeMemory.
                _Inout_
                _At_(*ppbUserBlob, 
                    _When_(*ppbUserBlob != NULL, _Pre_writable_size_(*pdwUserBlobSize))
                    _Post_readable_size_(*pdwUserBlobSize))
                BYTE **ppbUserBlob,
                // In case of error, API fills ppEapError if possible. Caller should free ppEapError using EapHostPeerFreeErrorMemory
                OUT EAP_ERROR** ppEapError
                );


// Tunnel Methods call this function to invoke Identity UI of the inner Methods.
// This function returns the identity as well as the credentials to use to start the authentication.
DWORD WINAPI EapHostPeerInvokeIdentityUI (
                // API's version number for ease of interoperability. It must be 0.
                IN DWORD dwVersion,
                // identifies the EAP Method supplicant wants to use
                IN EAP_METHOD_TYPE eapMethodType,
                // EAP_FLAG_xxx defined in eaptypes.w
                IN DWORD dwFlags,
                // window handle of the parent window under which configuration dialog will show up
                IN HWND hwndParent,
                // size of the buffer (pConnectionData) in bytes
                IN DWORD dwSizeofConnectionData,
                // configuration data that is used for the EAP method
                IN _In_reads_(dwSizeofConnectionData) const BYTE* pConnectionData,
                // size of the ubuffer pUserData
                IN DWORD dwSizeofUserData,
                // user credential information pertinent to this auth
                IN _In_reads_opt_(dwSizeofUserData) const BYTE* pUserData,
                // size of the buffer pUserDataOut.
                IN OUT DWORD* pdwSizeOfUserDataOut,
                // user data information returned by method.
                // Caller should release this using EapHostPeerFreeMemory
                OUT _Outptr_result_buffer_(*pdwSizeOfUserDataOut)BYTE** ppUserDataOut,
                // identity returned by method. Caller should release this using EapHostPeerFreeMemory
                OUT _Outptr_ LPWSTR* ppwszIdentity,
                // In case of error, API fills ppEapError if possible. Caller should free ppEapError
                // using EapHostPeerFreeErrorMemory
                OUT EAP_ERROR** ppEapError,
                // Reserved for future usage. It must be NULL.
                IN OUT LPVOID *ppvReserved
                );


// While doing authentication with EapHost, when supplicant receives action code of EapHostPeerResponseInvokeUi
// supplicant should call EapHostPeerGetUIContext to get UI context data. After that. it then should call this
// API from a process where UI can be brought up.
// API Returns non zero return code up on error.
DWORD WINAPI EapHostPeerInvokeInteractiveUI(
                // window handle of the parent window under which dialog will show up
                IN HWND hwndParent,
                // size of UIcontext data received from EapHostPeerGetUIContext call
                IN DWORD dwSizeofUIContextData,
                // UIcontext data received from EapHostPeerGetUIContext call
                IN _In_reads_opt_(dwSizeofUIContextData) const BYTE* pUIContextData,
                // pointer to DWORD that receives data from interactive UI that is used for authentication
                // to continue
                OUT DWORD* pdwSizeOfDataFromInteractiveUI,
                // pointer that receives buffer filled with interactive UI that is used for authentication
                // to continue. Caller should free the memory using EapHostPeerFreeMemory.
                OUT _Outptr_result_buffer_(*pdwSizeOfDataFromInteractiveUI) BYTE** ppDataFromInteractiveUI,
                // In case of error, API fills ppEapError if possible. Caller should free ppEapError using EapHostPeerFreeErrorMemory
                OUT EAP_ERROR** ppEapError
                );

// This API will enable supplicants to collect necessary information from EAPHost to raise interactive UI and collect user information
// supplicant should call EapHostPeerQueryInteractiveUIInputFields() API first after it receives
// EapHostPeerResponseInvokeUi actionCode from EAPHost. If the return value from this API
// is EAP_E_EAPHOST_METHOD_OPERATION_NOT_SUPPORTED, then supplicant should fall back to
// traditional model of invoking method interactive UI, i.e. by calling EapHostPeerInvokeInteractiveUI()
// API Returns non zero return code up on error.
DWORD WINAPI EapHostPeerQueryInteractiveUIInputFields (
                // API's version number for ease of interoperability. It must be 0.
                IN DWORD dwVersion,
                // control the behavior of the EAP Methods
                IN DWORD dwFlags,
                // size of UIcontext data EAPHost runtime
                IN DWORD dwSizeofUIContextData,
                // UIContext data received from EAPHost runtime
                IN _In_reads_(dwSizeofUIContextData) const BYTE* pUIContextData,
                // structure that gets filled with fields and how they should be shown to the user.
                // Caller should free the inner pointers using EapHostPeerFreeMemory starting at the inner most pointer.
                OUT EAP_INTERACTIVE_UI_DATA *pEapInteractiveUIData,
                // In case of error, API fills ppEapError if possible.  Caller should free ppEapError using EapHostPeerFreeErrorMemory
                OUT EAP_ERROR** ppEapError,
                // Reserved for future usage. It must be NULL.
                IN OUT LPVOID *ppvReserved
                );

// This API will enable supplicants to convert user information into a user-blob which can be consumed by EAPHost runtime APIs
// API Returns non zero return code up on error.
DWORD WINAPI EapHostPeerQueryUIBlobFromInteractiveUIInputFields(
                // API's version number for ease of interoperability. It must be 0.
                IN DWORD dwVersion,
                // control the behavior of the EAP Methods
                IN DWORD dwFlags,
                // size of UIcontext data EAPHost runtime
                IN DWORD dwSizeofUIContextData,
                // UIContext data received from EAPHost runtime
                IN _In_reads_(dwSizeofUIContextData) const BYTE* pUIContextData,
                // structure that carries data provided by user
                IN const EAP_INTERACTIVE_UI_DATA *pEapInteractiveUIData,
                // pointer to DWORD that receives size of credential blob, if supplicant passes in
                // non-zero size and non-NULL data below, EAPHost will just attempt to Update
                // the blob with passed in values (if method supports) instead of creating a new one.
                IN OUT DWORD * pdwSizeOfDataFromInteractiveUI,
                // Pointer that receives the credential blob that can be used in authentication.
                // Caller should free the memory using EapHostPeerFreeMemory.
                IN OUT _Outptr_result_buffer_(*pdwSizeOfDataFromInteractiveUI) BYTE ** ppDataFromInteractiveUI,
                // In case of error, API fills ppEapError if possible.  Caller should free ppEapError using EapHostPeerFreeErrorMemory
                OUT EAP_ERROR** ppEapError,
                // Reserved for future usage. It must be NULL.
                IN OUT LPVOID *ppvReserved
                );


// Supplicant can utilize XML based EAP configuration storing, managing, editing. When it wants to call EapHostPeerConfigureUI
// or when it has to start authentication, it calls this API to convert XML configuration into blob.
// API Returns non zero return code up on error.
DWORD WINAPI EapHostPeerConfigXml2Blob(
                // controls the behavior of the EAP Method
                IN DWORD dwFlags,
                // a node containing EAP XML configuration inside it
                IN IXMLDOMNode* pConfigDoc,
                // pointer to DWORD that receives the configuration blob size
                OUT DWORD* pdwSizeOfConfigOut,
                // pointer that receives configuration blob. Caller should free the memory using EapHostPeerFreeMemory.
                OUT _Outptr_result_buffer_(*pdwSizeOfConfigOut) BYTE** ppConfigOut,
                // pointer that receives the EAP Method specified in the XML configuration
                OUT EAP_METHOD_TYPE* pEapMethodType,
                // In case of error, API fills ppEapError if possible. Caller should free ppEapError using EapHostPeerFreeErrorMemory
                OUT EAP_ERROR** ppEapError
                );


// Supplicant can utilize XML based EAP credentials storing, managing, editing. When it wants to start
// authentication, it calls this API to convert XML based credentials into blob.
// API Returns non zero return code up on error.
DWORD WINAPI EapHostPeerCredentialsXml2Blob(
                // controls the behavior of the EAP Method
                IN DWORD dwFlags,
                // XML node that contains credentials
                IN IXMLDOMNode* pCredentialsDoc,
                // size of configuration blob that the credentials are configured for
                IN DWORD dwSizeOfConfigIn,
                // configuration blob that the credentials are configured for
                IN _In_reads_(dwSizeOfConfigIn) BYTE* pConfigIn,
                // pointer to DWORD that receives size of the credentials blob.
                OUT  DWORD* pdwSizeOfCredentialsOut,
                // pointer that receives credential blob buffer.  Caller should free the memory using
                // EapHostPeerFreeMemory.
                OUT _Outptr_result_buffer_(*pdwSizeOfCredentialsOut) BYTE** ppCredentialsOut,
                // pointer that receives the EAP Method specified in the XML configuration
                OUT EAP_METHOD_TYPE* pEapMethodType,
                // In case of error, API fills ppEapError if possible. Caller should free ppEapError using EapHostPeerFreeErrorMemory
                OUT EAP_ERROR** ppEapError
                );


// Supplicant can utilize XML based EAP credentials storing, managing, editing. When it wants to start
// convert configuration blob to XML, it can call this API.
// API Returns non zero return code up on error.
DWORD WINAPI EapHostPeerConfigBlob2Xml(
                // controls the behavior of the EAP Method
                IN DWORD dwFlags,
                // identifies the EAP Method
                IN EAP_METHOD_TYPE eapMethodType,
                // Size of configuration blob that supplicant wants to convert
                IN DWORD dwSizeOfConfigIn,
                // Configuration blob that supplicant wants to convert
                IN _In_reads_(dwSizeOfConfigIn) BYTE* pConfigIn,
                // XML document that contains XML form of the blob. If the EAP Method does not support
                // EapPeerConfigBlob2Xml function, the XML contains ConfigBlob node with blob in string form
                OUT IXMLDOMDocument2** ppConfigDoc,
                // In case of error, API fills ppEapError if possible. Caller should free ppEapError using EapHostPeerFreeErrorMemory
                OUT EAP_ERROR** ppEapError
                );

// Supplicant calls this API to free memory returned by Config APIs. Supplicant should not use this API
// for freeing EAP_ERROR structure.
VOID WINAPI EapHostPeerFreeMemory(BYTE* pData);

// Supplicant calls this API to free EAP_ERROR memory, which will get filled when an API fails.
VOID WINAPI EapHostPeerFreeErrorMemory(EAP_ERROR* pEapError);


#ifdef __cplusplus
}
#endif


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#endif // EAPHOSTPEERCONFIGAPIS_H


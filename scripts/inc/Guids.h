// Required by one of the .idl files we compile

#ifndef _GUIDS_H_
#define _GUIDS_H_

#define WCMTYPELIB_MAJOR_VERSION        1
#define WCMTYPELIB_MINOR_VERSION        0

#define WCM_PROGID_ENGINE               L"Wcm.SettingsEngine"
#define WCM_DESC_ENGINE                 L"SMI Settings Engine"

//
// These consecutive UUID's are generated with command "uuidgen -x -n50".
// The suffix part of these UUID's are fixed on the same machine. 
//

#define MSGUID(iid) {0x##iid##L,0x20b3,0x11DA,{0x81,0xA5,0,0x30,0xF1,0x64,0x2E,0x3C}}   // struct format
#define SZUUID(iid) iid##-20B3-11DA-81A5-0030F1642E3C                                   // typelib uuid format
#define SZGUID(iid) L"{" L#iid L"-20B3-11DA-81A5-0030F1642E3C}"                         // string format
#define GAGUID(iid) L#iid L"-20B3-11DA-81A5-0030F1642E3C"                               // GuidAttribute format


#define GUID_LibraryWcm                             MSGUID(9F7D7BAF)
#define UUID_LibraryWcm                             SZUUID(9F7D7BAF)
#define SZID_LibraryWcm                             SZGUID(9F7D7BAF)
#define GAID_LibraryWcm                             GAGUID(9F7D7BAF)

//_____________________________________________________________________________
//
// Interfaces for handler
//_____________________________________________________________________________

#define GUID_IWcmHandler                            MSGUID(9F7D7BB0)
#define UUID_IWcmHandler                            SZUUID(9F7D7BB0)
#define SZID_IWcmHandler                            SZGUID(9F7D7BB0)
#define GAID_IWcmHandler                            GAGUID(9F7D7BB0)
                                      
#define GUID_IWcmHelper                             MSGUID(9F7D7BB1)
#define UUID_IWcmHelper                             SZUUID(9F7D7BB1)
#define SZID_IWcmHelper                             SZGUID(9F7D7BB1)
#define GAID_IWcmHelper                             GAGUID(9F7D7BB1)
                                      
#define GUID_IWcmData                               MSGUID(9F7D7BB2)
#define UUID_IWcmData                               SZUUID(9F7D7BB2)
#define SZID_IWcmData                               SZGUID(9F7D7BB2)
#define GAID_IWcmData                               GAGUID(9F7D7BB2)

//
// IWcmEnumerator - Enumerator returning IWcmData as each item.
//
#define GUID_IWcmEnumerator                         MSGUID(9F7D7BB3)
#define UUID_IWcmEnumerator                         SZUUID(9F7D7BB3)
#define SZID_IWcmEnumerator                         SZGUID(9F7D7BB3)
#define GAID_IWcmEnumerator                         GAGUID(9F7D7BB3)

//
// IWcmMetadata - Interface for providing access to SMI metadata for the handlers
//
#define GUID_IWcmMetadata                           MSGUID(9F7D7BB4)
#define UUID_IWcmMetadata                           SZUUID(9F7D7BB4)
#define SZID_IWcmMetadata                           SZGUID(9F7D7BB4)
#define GAID_IWcmMetadata                           GAGUID(9F7D7BB4)

//
// COM interfaces
//

#define GUID_ClassSettingsEngine                    MSGUID(9F7D7BB5)
#define UUID_ClassSettingsEngine                    SZUUID(9F7D7BB5)
#define SZID_ClassSettingsEngine                    SZGUID(9F7D7BB5)
#define GAID_ClassSettingsEngine                    GAGUID(9F7D7BB5)
                                                                  
#define GUID_ISettingsIdentity                      MSGUID(9F7D7BB6)
#define UUID_ISettingsIdentity                      SZUUID(9F7D7BB6)
#define SZID_ISettingsIdentity                      SZGUID(9F7D7BB6)
#define GAID_ISettingsIdentity                      GAGUID(9F7D7BB6)

#define GUID_IItemEnumerator                        MSGUID(9F7D7BB7)
#define UUID_IItemEnumerator                        SZUUID(9F7D7BB7)
#define SZID_IItemEnumerator                        SZGUID(9F7D7BB7)
#define GAID_IItemEnumerator                        GAGUID(9F7D7BB7)

#define GUID_ITargetInfo                            MSGUID(9F7D7BB8)
#define UUID_ITargetInfo                            SZUUID(9F7D7BB8)
#define SZID_ITargetInfo                            SZGUID(9F7D7BB8)
#define GAID_ITargetInfo                            GAGUID(9F7D7BB8)

#define GUID_ISettingsEngine                        MSGUID(9F7D7BB9)
#define UUID_ISettingsEngine                        SZUUID(9F7D7BB9)
#define SZID_ISettingsEngine                        SZGUID(9F7D7BB9)
#define GAID_ISettingsEngine                        GAGUID(9F7D7BB9)

#define GUID_ISettingsNamespace                     MSGUID(9F7D7BBA)
#define UUID_ISettingsNamespace                     SZUUID(9F7D7BBA)
#define SZID_ISettingsNamespace                     SZGUID(9F7D7BBA)
#define GAID_ISettingsNamespace                     GAGUID(9F7D7BBA)

#define GUID_ISettingsItem                          MSGUID(9F7D7BBB)
#define UUID_ISettingsItem                          SZUUID(9F7D7BBB)
#define SZID_ISettingsItem                          SZGUID(9F7D7BBB)
#define GAID_ISettingsItem                          GAGUID(9F7D7BBB)

#define GUID_ISettingsResult                        MSGUID(9F7D7BBC)
#define UUID_ISettingsResult                        SZUUID(9F7D7BBC)
#define SZID_ISettingsResult                        SZGUID(9F7D7BBC)
#define GAID_ISettingsResult                        GAGUID(9F7D7BBC)

#define GUID_ISettingsContext                       MSGUID(9F7D7BBD)
#define UUID_ISettingsContext                       SZUUID(9F7D7BBD)
#define SZID_ISettingsContext                       SZGUID(9F7D7BBD)
#define GAID_ISettingsContext                       GAGUID(9F7D7BBD)

//_____________________________________________________________________________
//
// Private COM interfaces
//_____________________________________________________________________________

#define MSGUIDPRIV(iid) {0x##iid##L,0x2C77,0x11D9,{0xBD,0xF0,0,0x08,0x74,0xCD,0x1B,0xAE}}   // struct format
#define SZUUIDPRIV(iid) iid##-2C77-11D9-BDF0-000874CD1BAE                                   // typelib uuid format
#define SZGUIDPRIV(iid) L"{" L#iid L"-2C77-11D9-BDF0-000874CD1BAE}"                         // string format
#define GAGUIDPRIV(iid) L#iid L"-2C77-11D9-BDF0-000874CD1BAE"                               // GuidAttribute format


#define GUID_LibraryWcmPriv                         MSGUIDPRIV(90A45ABD)
#define UUID_LibraryWcmPriv                         SZUUIDPRIV(90A45ABD)
#define SZID_LibraryWcmPriv                         SZGUIDPRIV(90A45ABD)
#define GAID_LibraryWcmPriv                         GAGUIDPRIV(90A45ABD)
                                                                  
#define GUID_ClassSettingsEnginePriv                MSGUIDPRIV(90A45ABE)
#define UUID_ClassSettingsEnginePriv                SZUUIDPRIV(90A45ABE)
#define SZID_ClassSettingsEnginePriv                SZGUIDPRIV(90A45ABE)
#define GAID_ClassSettingsEnginePriv                GAGUIDPRIV(90A45ABE)
                                                                  
#define GUID_IItemCollectionPriv                    MSGUIDPRIV(90A45ABF)
#define UUID_IItemCollectionPriv                    SZUUIDPRIV(90A45ABF)
#define SZID_IItemCollectionPriv                    SZGUIDPRIV(90A45ABF)
#define GAID_IItemCollectionPriv                    GAGUIDPRIV(90A45ABF)
                                                                  
#define GUID_ISettingsEnginePriv                    MSGUIDPRIV(90A45AC0)
#define UUID_ISettingsEnginePriv                    SZUUIDPRIV(90A45AC0)
#define SZID_ISettingsEnginePriv                    SZGUIDPRIV(90A45AC0)
#define GAID_ISettingsEnginePriv                    GAGUIDPRIV(90A45AC0)
                                                                   
#define GUID_ISettingsItemPriv                      MSGUIDPRIV(90A45AC1)
#define UUID_ISettingsItemPriv                      SZUUIDPRIV(90A45AC1)
#define SZID_ISettingsItemPriv                      SZGUIDPRIV(90A45AC1)
#define GAID_ISettingsItemPriv                      GAGUIDPRIV(90A45AC1)
                                                                  
#define GUID_IMetadataItemPriv                      MSGUIDPRIV(90A45AC2)
#define UUID_IMetadataItemPriv                      SZUUIDPRIV(90A45AC2)
#define SZID_IMetadataItemPriv                      SZGUIDPRIV(90A45AC2)
#define GAID_IMetadataItemPriv                      GAGUIDPRIV(90A45AC2)
                                                                   
#define GUID_ISettingsNamespacePriv                 MSGUIDPRIV(90A45AC3)
#define UUID_ISettingsNamespacePriv                 SZUUIDPRIV(90A45AC3)
#define SZID_ISettingsNamespacePriv                 SZGUIDPRIV(90A45AC3)
#define GAID_ISettingsNamespacePriv                 GAGUIDPRIV(90A45AC3)
                                                                   
#define GUID_IMetadataPriv                          MSGUIDPRIV(90A45AC4)
#define UUID_IMetadataPriv                          SZUUIDPRIV(90A45AC4)
#define SZID_IMetadataPriv                          SZGUIDPRIV(90A45AC4)
#define GAID_IMetadataPriv                          GAGUIDPRIV(90A45AC4)
                                                                   
#define GUID_IComplexTypePriv                       MSGUIDPRIV(90A45AC5)
#define UUID_IComplexTypePriv                       SZUUIDPRIV(90A45AC5)
#define SZID_IComplexTypePriv                       SZGUIDPRIV(90A45AC5)
#define GAID_IComplexTypePriv                       GAGUIDPRIV(90A45AC5)
                                                                       
#define GUID_ISimpleTypePriv                        MSGUIDPRIV(90A45AC6)
#define UUID_ISimpleTypePriv                        SZUUIDPRIV(90A45AC6)
#define SZID_ISimpleTypePriv                        SZGUIDPRIV(90A45AC6)
#define GAID_ISimpleTypePriv                        GAGUIDPRIV(90A45AC6)
                                                                                                                                                         
#define GUID_IElementPriv                           MSGUIDPRIV(90A45AC8)
#define UUID_IElementPriv                           SZUUIDPRIV(90A45AC8)
#define SZID_IElementPriv                           SZGUIDPRIV(90A45AC8)
#define GAID_IElementPriv                           GAGUIDPRIV(90A45AC8)
                                                                   
#define GUID_IMemberElementPriv                     MSGUIDPRIV(90A45AC9)
#define UUID_IMemberElementPriv                     SZUUIDPRIV(90A45AC9)
#define SZID_IMemberElementPriv                     SZGUIDPRIV(90A45AC9)
#define GAID_IMemberElementPriv                     GAGUIDPRIV(90A45AC9)
                                                                     
#define GUID_ISettingsAttributePriv                 MSGUIDPRIV(90A45ACA)
#define UUID_ISettingsAttributePriv                 SZUUIDPRIV(90A45ACA)
#define SZID_ISettingsAttributePriv                 SZGUIDPRIV(90A45ACA)
#define GAID_ISettingsAttributePriv                 GAGUIDPRIV(90A45ACA)
                                                               
#define GUID_ISecurityDefinitionPriv                MSGUIDPRIV(90A45ACB)
#define UUID_ISecurityDefinitionPriv                SZUUIDPRIV(90A45ACB)
#define SZID_ISecurityDefinitionPriv                SZGUIDPRIV(90A45ACB)
#define GAID_ISecurityDefinitionPriv                GAGUIDPRIV(90A45ACB)

#define GUID_INamespaceIdentityPriv                 MSGUIDPRIV(90A45ACC)
#define UUID_INamespaceIdentityPriv                 SZUUIDPRIV(90A45ACC)
#define SZID_INamespaceIdentityPriv                 SZGUIDPRIV(90A45ACC)
#define GAID_INamespaceIdentityPriv                 GAGUIDPRIV(90A45ACC)

#define GUID_ITargetInfoPriv                        MSGUIDPRIV(90A45ACD)
#define UUID_ITargetInfoPriv                        SZUUIDPRIV(90A45ACD)
#define SZID_ITargetInfoPriv                        SZGUIDPRIV(90A45ACD)
#define GAID_ITargetInfoPriv                        GAGUIDPRIV(90A45ACD)

#endif  //_GUIDS_H_


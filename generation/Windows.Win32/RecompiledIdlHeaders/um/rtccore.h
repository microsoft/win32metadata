

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

#ifndef __rtccore_h__
#define __rtccore_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IRTCClient_FWD_DEFINED__
#define __IRTCClient_FWD_DEFINED__
typedef interface IRTCClient IRTCClient;

#endif 	/* __IRTCClient_FWD_DEFINED__ */


#ifndef __IRTCClient2_FWD_DEFINED__
#define __IRTCClient2_FWD_DEFINED__
typedef interface IRTCClient2 IRTCClient2;

#endif 	/* __IRTCClient2_FWD_DEFINED__ */


#ifndef __IRTCClientPresence_FWD_DEFINED__
#define __IRTCClientPresence_FWD_DEFINED__
typedef interface IRTCClientPresence IRTCClientPresence;

#endif 	/* __IRTCClientPresence_FWD_DEFINED__ */


#ifndef __IRTCClientPresence2_FWD_DEFINED__
#define __IRTCClientPresence2_FWD_DEFINED__
typedef interface IRTCClientPresence2 IRTCClientPresence2;

#endif 	/* __IRTCClientPresence2_FWD_DEFINED__ */


#ifndef __IRTCClientProvisioning_FWD_DEFINED__
#define __IRTCClientProvisioning_FWD_DEFINED__
typedef interface IRTCClientProvisioning IRTCClientProvisioning;

#endif 	/* __IRTCClientProvisioning_FWD_DEFINED__ */


#ifndef __IRTCClientProvisioning2_FWD_DEFINED__
#define __IRTCClientProvisioning2_FWD_DEFINED__
typedef interface IRTCClientProvisioning2 IRTCClientProvisioning2;

#endif 	/* __IRTCClientProvisioning2_FWD_DEFINED__ */


#ifndef __IRTCProfile_FWD_DEFINED__
#define __IRTCProfile_FWD_DEFINED__
typedef interface IRTCProfile IRTCProfile;

#endif 	/* __IRTCProfile_FWD_DEFINED__ */


#ifndef __IRTCProfile2_FWD_DEFINED__
#define __IRTCProfile2_FWD_DEFINED__
typedef interface IRTCProfile2 IRTCProfile2;

#endif 	/* __IRTCProfile2_FWD_DEFINED__ */


#ifndef __IRTCSession_FWD_DEFINED__
#define __IRTCSession_FWD_DEFINED__
typedef interface IRTCSession IRTCSession;

#endif 	/* __IRTCSession_FWD_DEFINED__ */


#ifndef __IRTCSession2_FWD_DEFINED__
#define __IRTCSession2_FWD_DEFINED__
typedef interface IRTCSession2 IRTCSession2;

#endif 	/* __IRTCSession2_FWD_DEFINED__ */


#ifndef __IRTCSessionCallControl_FWD_DEFINED__
#define __IRTCSessionCallControl_FWD_DEFINED__
typedef interface IRTCSessionCallControl IRTCSessionCallControl;

#endif 	/* __IRTCSessionCallControl_FWD_DEFINED__ */


#ifndef __IRTCParticipant_FWD_DEFINED__
#define __IRTCParticipant_FWD_DEFINED__
typedef interface IRTCParticipant IRTCParticipant;

#endif 	/* __IRTCParticipant_FWD_DEFINED__ */


#ifndef __IRTCRoamingEvent_FWD_DEFINED__
#define __IRTCRoamingEvent_FWD_DEFINED__
typedef interface IRTCRoamingEvent IRTCRoamingEvent;

#endif 	/* __IRTCRoamingEvent_FWD_DEFINED__ */


#ifndef __IRTCProfileEvent_FWD_DEFINED__
#define __IRTCProfileEvent_FWD_DEFINED__
typedef interface IRTCProfileEvent IRTCProfileEvent;

#endif 	/* __IRTCProfileEvent_FWD_DEFINED__ */


#ifndef __IRTCProfileEvent2_FWD_DEFINED__
#define __IRTCProfileEvent2_FWD_DEFINED__
typedef interface IRTCProfileEvent2 IRTCProfileEvent2;

#endif 	/* __IRTCProfileEvent2_FWD_DEFINED__ */


#ifndef __IRTCClientEvent_FWD_DEFINED__
#define __IRTCClientEvent_FWD_DEFINED__
typedef interface IRTCClientEvent IRTCClientEvent;

#endif 	/* __IRTCClientEvent_FWD_DEFINED__ */


#ifndef __IRTCRegistrationStateChangeEvent_FWD_DEFINED__
#define __IRTCRegistrationStateChangeEvent_FWD_DEFINED__
typedef interface IRTCRegistrationStateChangeEvent IRTCRegistrationStateChangeEvent;

#endif 	/* __IRTCRegistrationStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent_FWD_DEFINED__
#define __IRTCSessionStateChangeEvent_FWD_DEFINED__
typedef interface IRTCSessionStateChangeEvent IRTCSessionStateChangeEvent;

#endif 	/* __IRTCSessionStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent2_FWD_DEFINED__
#define __IRTCSessionStateChangeEvent2_FWD_DEFINED__
typedef interface IRTCSessionStateChangeEvent2 IRTCSessionStateChangeEvent2;

#endif 	/* __IRTCSessionStateChangeEvent2_FWD_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent_FWD_DEFINED__
#define __IRTCSessionOperationCompleteEvent_FWD_DEFINED__
typedef interface IRTCSessionOperationCompleteEvent IRTCSessionOperationCompleteEvent;

#endif 	/* __IRTCSessionOperationCompleteEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__
#define __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__
typedef interface IRTCSessionOperationCompleteEvent2 IRTCSessionOperationCompleteEvent2;

#endif 	/* __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__ */


#ifndef __IRTCParticipantStateChangeEvent_FWD_DEFINED__
#define __IRTCParticipantStateChangeEvent_FWD_DEFINED__
typedef interface IRTCParticipantStateChangeEvent IRTCParticipantStateChangeEvent;

#endif 	/* __IRTCParticipantStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCMediaEvent_FWD_DEFINED__
#define __IRTCMediaEvent_FWD_DEFINED__
typedef interface IRTCMediaEvent IRTCMediaEvent;

#endif 	/* __IRTCMediaEvent_FWD_DEFINED__ */


#ifndef __IRTCIntensityEvent_FWD_DEFINED__
#define __IRTCIntensityEvent_FWD_DEFINED__
typedef interface IRTCIntensityEvent IRTCIntensityEvent;

#endif 	/* __IRTCIntensityEvent_FWD_DEFINED__ */


#ifndef __IRTCMessagingEvent_FWD_DEFINED__
#define __IRTCMessagingEvent_FWD_DEFINED__
typedef interface IRTCMessagingEvent IRTCMessagingEvent;

#endif 	/* __IRTCMessagingEvent_FWD_DEFINED__ */


#ifndef __IRTCBuddyEvent_FWD_DEFINED__
#define __IRTCBuddyEvent_FWD_DEFINED__
typedef interface IRTCBuddyEvent IRTCBuddyEvent;

#endif 	/* __IRTCBuddyEvent_FWD_DEFINED__ */


#ifndef __IRTCBuddyEvent2_FWD_DEFINED__
#define __IRTCBuddyEvent2_FWD_DEFINED__
typedef interface IRTCBuddyEvent2 IRTCBuddyEvent2;

#endif 	/* __IRTCBuddyEvent2_FWD_DEFINED__ */


#ifndef __IRTCWatcherEvent_FWD_DEFINED__
#define __IRTCWatcherEvent_FWD_DEFINED__
typedef interface IRTCWatcherEvent IRTCWatcherEvent;

#endif 	/* __IRTCWatcherEvent_FWD_DEFINED__ */


#ifndef __IRTCWatcherEvent2_FWD_DEFINED__
#define __IRTCWatcherEvent2_FWD_DEFINED__
typedef interface IRTCWatcherEvent2 IRTCWatcherEvent2;

#endif 	/* __IRTCWatcherEvent2_FWD_DEFINED__ */


#ifndef __IRTCBuddyGroupEvent_FWD_DEFINED__
#define __IRTCBuddyGroupEvent_FWD_DEFINED__
typedef interface IRTCBuddyGroupEvent IRTCBuddyGroupEvent;

#endif 	/* __IRTCBuddyGroupEvent_FWD_DEFINED__ */


#ifndef __IRTCInfoEvent_FWD_DEFINED__
#define __IRTCInfoEvent_FWD_DEFINED__
typedef interface IRTCInfoEvent IRTCInfoEvent;

#endif 	/* __IRTCInfoEvent_FWD_DEFINED__ */


#ifndef __IRTCMediaRequestEvent_FWD_DEFINED__
#define __IRTCMediaRequestEvent_FWD_DEFINED__
typedef interface IRTCMediaRequestEvent IRTCMediaRequestEvent;

#endif 	/* __IRTCMediaRequestEvent_FWD_DEFINED__ */


#ifndef __IRTCReInviteEvent_FWD_DEFINED__
#define __IRTCReInviteEvent_FWD_DEFINED__
typedef interface IRTCReInviteEvent IRTCReInviteEvent;

#endif 	/* __IRTCReInviteEvent_FWD_DEFINED__ */


#ifndef __IRTCPresencePropertyEvent_FWD_DEFINED__
#define __IRTCPresencePropertyEvent_FWD_DEFINED__
typedef interface IRTCPresencePropertyEvent IRTCPresencePropertyEvent;

#endif 	/* __IRTCPresencePropertyEvent_FWD_DEFINED__ */


#ifndef __IRTCPresenceDataEvent_FWD_DEFINED__
#define __IRTCPresenceDataEvent_FWD_DEFINED__
typedef interface IRTCPresenceDataEvent IRTCPresenceDataEvent;

#endif 	/* __IRTCPresenceDataEvent_FWD_DEFINED__ */


#ifndef __IRTCPresenceStatusEvent_FWD_DEFINED__
#define __IRTCPresenceStatusEvent_FWD_DEFINED__
typedef interface IRTCPresenceStatusEvent IRTCPresenceStatusEvent;

#endif 	/* __IRTCPresenceStatusEvent_FWD_DEFINED__ */


#ifndef __IRTCCollection_FWD_DEFINED__
#define __IRTCCollection_FWD_DEFINED__
typedef interface IRTCCollection IRTCCollection;

#endif 	/* __IRTCCollection_FWD_DEFINED__ */


#ifndef __IRTCEnumParticipants_FWD_DEFINED__
#define __IRTCEnumParticipants_FWD_DEFINED__
typedef interface IRTCEnumParticipants IRTCEnumParticipants;

#endif 	/* __IRTCEnumParticipants_FWD_DEFINED__ */


#ifndef __IRTCEnumProfiles_FWD_DEFINED__
#define __IRTCEnumProfiles_FWD_DEFINED__
typedef interface IRTCEnumProfiles IRTCEnumProfiles;

#endif 	/* __IRTCEnumProfiles_FWD_DEFINED__ */


#ifndef __IRTCEnumBuddies_FWD_DEFINED__
#define __IRTCEnumBuddies_FWD_DEFINED__
typedef interface IRTCEnumBuddies IRTCEnumBuddies;

#endif 	/* __IRTCEnumBuddies_FWD_DEFINED__ */


#ifndef __IRTCEnumWatchers_FWD_DEFINED__
#define __IRTCEnumWatchers_FWD_DEFINED__
typedef interface IRTCEnumWatchers IRTCEnumWatchers;

#endif 	/* __IRTCEnumWatchers_FWD_DEFINED__ */


#ifndef __IRTCEnumGroups_FWD_DEFINED__
#define __IRTCEnumGroups_FWD_DEFINED__
typedef interface IRTCEnumGroups IRTCEnumGroups;

#endif 	/* __IRTCEnumGroups_FWD_DEFINED__ */


#ifndef __IRTCPresenceContact_FWD_DEFINED__
#define __IRTCPresenceContact_FWD_DEFINED__
typedef interface IRTCPresenceContact IRTCPresenceContact;

#endif 	/* __IRTCPresenceContact_FWD_DEFINED__ */


#ifndef __IRTCBuddy_FWD_DEFINED__
#define __IRTCBuddy_FWD_DEFINED__
typedef interface IRTCBuddy IRTCBuddy;

#endif 	/* __IRTCBuddy_FWD_DEFINED__ */


#ifndef __IRTCBuddy2_FWD_DEFINED__
#define __IRTCBuddy2_FWD_DEFINED__
typedef interface IRTCBuddy2 IRTCBuddy2;

#endif 	/* __IRTCBuddy2_FWD_DEFINED__ */


#ifndef __IRTCWatcher_FWD_DEFINED__
#define __IRTCWatcher_FWD_DEFINED__
typedef interface IRTCWatcher IRTCWatcher;

#endif 	/* __IRTCWatcher_FWD_DEFINED__ */


#ifndef __IRTCWatcher2_FWD_DEFINED__
#define __IRTCWatcher2_FWD_DEFINED__
typedef interface IRTCWatcher2 IRTCWatcher2;

#endif 	/* __IRTCWatcher2_FWD_DEFINED__ */


#ifndef __IRTCBuddyGroup_FWD_DEFINED__
#define __IRTCBuddyGroup_FWD_DEFINED__
typedef interface IRTCBuddyGroup IRTCBuddyGroup;

#endif 	/* __IRTCBuddyGroup_FWD_DEFINED__ */


#ifndef __IRTCEventNotification_FWD_DEFINED__
#define __IRTCEventNotification_FWD_DEFINED__
typedef interface IRTCEventNotification IRTCEventNotification;

#endif 	/* __IRTCEventNotification_FWD_DEFINED__ */


#ifndef __IRTCDispatchEventNotification_FWD_DEFINED__
#define __IRTCDispatchEventNotification_FWD_DEFINED__
typedef interface IRTCDispatchEventNotification IRTCDispatchEventNotification;

#endif 	/* __IRTCDispatchEventNotification_FWD_DEFINED__ */


#ifndef __IRTCPortManager_FWD_DEFINED__
#define __IRTCPortManager_FWD_DEFINED__
typedef interface IRTCPortManager IRTCPortManager;

#endif 	/* __IRTCPortManager_FWD_DEFINED__ */


#ifndef __IRTCSessionPortManagement_FWD_DEFINED__
#define __IRTCSessionPortManagement_FWD_DEFINED__
typedef interface IRTCSessionPortManagement IRTCSessionPortManagement;

#endif 	/* __IRTCSessionPortManagement_FWD_DEFINED__ */


#ifndef __IRTCClientPortManagement_FWD_DEFINED__
#define __IRTCClientPortManagement_FWD_DEFINED__
typedef interface IRTCClientPortManagement IRTCClientPortManagement;

#endif 	/* __IRTCClientPortManagement_FWD_DEFINED__ */


#ifndef __IRTCUserSearch_FWD_DEFINED__
#define __IRTCUserSearch_FWD_DEFINED__
typedef interface IRTCUserSearch IRTCUserSearch;

#endif 	/* __IRTCUserSearch_FWD_DEFINED__ */


#ifndef __IRTCUserSearchQuery_FWD_DEFINED__
#define __IRTCUserSearchQuery_FWD_DEFINED__
typedef interface IRTCUserSearchQuery IRTCUserSearchQuery;

#endif 	/* __IRTCUserSearchQuery_FWD_DEFINED__ */


#ifndef __IRTCUserSearchResult_FWD_DEFINED__
#define __IRTCUserSearchResult_FWD_DEFINED__
typedef interface IRTCUserSearchResult IRTCUserSearchResult;

#endif 	/* __IRTCUserSearchResult_FWD_DEFINED__ */


#ifndef __IRTCEnumUserSearchResults_FWD_DEFINED__
#define __IRTCEnumUserSearchResults_FWD_DEFINED__
typedef interface IRTCEnumUserSearchResults IRTCEnumUserSearchResults;

#endif 	/* __IRTCEnumUserSearchResults_FWD_DEFINED__ */


#ifndef __IRTCUserSearchResultsEvent_FWD_DEFINED__
#define __IRTCUserSearchResultsEvent_FWD_DEFINED__
typedef interface IRTCUserSearchResultsEvent IRTCUserSearchResultsEvent;

#endif 	/* __IRTCUserSearchResultsEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionReferStatusEvent_FWD_DEFINED__
#define __IRTCSessionReferStatusEvent_FWD_DEFINED__
typedef interface IRTCSessionReferStatusEvent IRTCSessionReferStatusEvent;

#endif 	/* __IRTCSessionReferStatusEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionReferredEvent_FWD_DEFINED__
#define __IRTCSessionReferredEvent_FWD_DEFINED__
typedef interface IRTCSessionReferredEvent IRTCSessionReferredEvent;

#endif 	/* __IRTCSessionReferredEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionDescriptionManager_FWD_DEFINED__
#define __IRTCSessionDescriptionManager_FWD_DEFINED__
typedef interface IRTCSessionDescriptionManager IRTCSessionDescriptionManager;

#endif 	/* __IRTCSessionDescriptionManager_FWD_DEFINED__ */


#ifndef __IRTCEnumPresenceDevices_FWD_DEFINED__
#define __IRTCEnumPresenceDevices_FWD_DEFINED__
typedef interface IRTCEnumPresenceDevices IRTCEnumPresenceDevices;

#endif 	/* __IRTCEnumPresenceDevices_FWD_DEFINED__ */


#ifndef __IRTCPresenceDevice_FWD_DEFINED__
#define __IRTCPresenceDevice_FWD_DEFINED__
typedef interface IRTCPresenceDevice IRTCPresenceDevice;

#endif 	/* __IRTCPresenceDevice_FWD_DEFINED__ */


#ifndef __IRTCProfile_FWD_DEFINED__
#define __IRTCProfile_FWD_DEFINED__
typedef interface IRTCProfile IRTCProfile;

#endif 	/* __IRTCProfile_FWD_DEFINED__ */


#ifndef __IRTCProfile2_FWD_DEFINED__
#define __IRTCProfile2_FWD_DEFINED__
typedef interface IRTCProfile2 IRTCProfile2;

#endif 	/* __IRTCProfile2_FWD_DEFINED__ */


#ifndef __IRTCEnumProfiles_FWD_DEFINED__
#define __IRTCEnumProfiles_FWD_DEFINED__
typedef interface IRTCEnumProfiles IRTCEnumProfiles;

#endif 	/* __IRTCEnumProfiles_FWD_DEFINED__ */


#ifndef __IRTCSession_FWD_DEFINED__
#define __IRTCSession_FWD_DEFINED__
typedef interface IRTCSession IRTCSession;

#endif 	/* __IRTCSession_FWD_DEFINED__ */


#ifndef __IRTCSession2_FWD_DEFINED__
#define __IRTCSession2_FWD_DEFINED__
typedef interface IRTCSession2 IRTCSession2;

#endif 	/* __IRTCSession2_FWD_DEFINED__ */


#ifndef __IRTCSessionCallControl_FWD_DEFINED__
#define __IRTCSessionCallControl_FWD_DEFINED__
typedef interface IRTCSessionCallControl IRTCSessionCallControl;

#endif 	/* __IRTCSessionCallControl_FWD_DEFINED__ */


#ifndef __IRTCParticipant_FWD_DEFINED__
#define __IRTCParticipant_FWD_DEFINED__
typedef interface IRTCParticipant IRTCParticipant;

#endif 	/* __IRTCParticipant_FWD_DEFINED__ */


#ifndef __IRTCEnumParticipants_FWD_DEFINED__
#define __IRTCEnumParticipants_FWD_DEFINED__
typedef interface IRTCEnumParticipants IRTCEnumParticipants;

#endif 	/* __IRTCEnumParticipants_FWD_DEFINED__ */


#ifndef __IRTCCollection_FWD_DEFINED__
#define __IRTCCollection_FWD_DEFINED__
typedef interface IRTCCollection IRTCCollection;

#endif 	/* __IRTCCollection_FWD_DEFINED__ */


#ifndef __IRTCPresenceContact_FWD_DEFINED__
#define __IRTCPresenceContact_FWD_DEFINED__
typedef interface IRTCPresenceContact IRTCPresenceContact;

#endif 	/* __IRTCPresenceContact_FWD_DEFINED__ */


#ifndef __IRTCBuddy_FWD_DEFINED__
#define __IRTCBuddy_FWD_DEFINED__
typedef interface IRTCBuddy IRTCBuddy;

#endif 	/* __IRTCBuddy_FWD_DEFINED__ */


#ifndef __IRTCBuddy2_FWD_DEFINED__
#define __IRTCBuddy2_FWD_DEFINED__
typedef interface IRTCBuddy2 IRTCBuddy2;

#endif 	/* __IRTCBuddy2_FWD_DEFINED__ */


#ifndef __IRTCEnumBuddies_FWD_DEFINED__
#define __IRTCEnumBuddies_FWD_DEFINED__
typedef interface IRTCEnumBuddies IRTCEnumBuddies;

#endif 	/* __IRTCEnumBuddies_FWD_DEFINED__ */


#ifndef __IRTCWatcher_FWD_DEFINED__
#define __IRTCWatcher_FWD_DEFINED__
typedef interface IRTCWatcher IRTCWatcher;

#endif 	/* __IRTCWatcher_FWD_DEFINED__ */


#ifndef __IRTCWatcher2_FWD_DEFINED__
#define __IRTCWatcher2_FWD_DEFINED__
typedef interface IRTCWatcher2 IRTCWatcher2;

#endif 	/* __IRTCWatcher2_FWD_DEFINED__ */


#ifndef __IRTCEnumWatchers_FWD_DEFINED__
#define __IRTCEnumWatchers_FWD_DEFINED__
typedef interface IRTCEnumWatchers IRTCEnumWatchers;

#endif 	/* __IRTCEnumWatchers_FWD_DEFINED__ */


#ifndef __IRTCBuddyGroup_FWD_DEFINED__
#define __IRTCBuddyGroup_FWD_DEFINED__
typedef interface IRTCBuddyGroup IRTCBuddyGroup;

#endif 	/* __IRTCBuddyGroup_FWD_DEFINED__ */


#ifndef __IRTCEnumGroups_FWD_DEFINED__
#define __IRTCEnumGroups_FWD_DEFINED__
typedef interface IRTCEnumGroups IRTCEnumGroups;

#endif 	/* __IRTCEnumGroups_FWD_DEFINED__ */


#ifndef __IRTCUserSearchQuery_FWD_DEFINED__
#define __IRTCUserSearchQuery_FWD_DEFINED__
typedef interface IRTCUserSearchQuery IRTCUserSearchQuery;

#endif 	/* __IRTCUserSearchQuery_FWD_DEFINED__ */


#ifndef __IRTCUserSearchResult_FWD_DEFINED__
#define __IRTCUserSearchResult_FWD_DEFINED__
typedef interface IRTCUserSearchResult IRTCUserSearchResult;

#endif 	/* __IRTCUserSearchResult_FWD_DEFINED__ */


#ifndef __IRTCEnumUserSearchResults_FWD_DEFINED__
#define __IRTCEnumUserSearchResults_FWD_DEFINED__
typedef interface IRTCEnumUserSearchResults IRTCEnumUserSearchResults;

#endif 	/* __IRTCEnumUserSearchResults_FWD_DEFINED__ */


#ifndef __IRTCEventNotification_FWD_DEFINED__
#define __IRTCEventNotification_FWD_DEFINED__
typedef interface IRTCEventNotification IRTCEventNotification;

#endif 	/* __IRTCEventNotification_FWD_DEFINED__ */


#ifndef __IRTCClientEvent_FWD_DEFINED__
#define __IRTCClientEvent_FWD_DEFINED__
typedef interface IRTCClientEvent IRTCClientEvent;

#endif 	/* __IRTCClientEvent_FWD_DEFINED__ */


#ifndef __IRTCRegistrationStateChangeEvent_FWD_DEFINED__
#define __IRTCRegistrationStateChangeEvent_FWD_DEFINED__
typedef interface IRTCRegistrationStateChangeEvent IRTCRegistrationStateChangeEvent;

#endif 	/* __IRTCRegistrationStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent_FWD_DEFINED__
#define __IRTCSessionStateChangeEvent_FWD_DEFINED__
typedef interface IRTCSessionStateChangeEvent IRTCSessionStateChangeEvent;

#endif 	/* __IRTCSessionStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent2_FWD_DEFINED__
#define __IRTCSessionStateChangeEvent2_FWD_DEFINED__
typedef interface IRTCSessionStateChangeEvent2 IRTCSessionStateChangeEvent2;

#endif 	/* __IRTCSessionStateChangeEvent2_FWD_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent_FWD_DEFINED__
#define __IRTCSessionOperationCompleteEvent_FWD_DEFINED__
typedef interface IRTCSessionOperationCompleteEvent IRTCSessionOperationCompleteEvent;

#endif 	/* __IRTCSessionOperationCompleteEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__
#define __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__
typedef interface IRTCSessionOperationCompleteEvent2 IRTCSessionOperationCompleteEvent2;

#endif 	/* __IRTCSessionOperationCompleteEvent2_FWD_DEFINED__ */


#ifndef __IRTCParticipantStateChangeEvent_FWD_DEFINED__
#define __IRTCParticipantStateChangeEvent_FWD_DEFINED__
typedef interface IRTCParticipantStateChangeEvent IRTCParticipantStateChangeEvent;

#endif 	/* __IRTCParticipantStateChangeEvent_FWD_DEFINED__ */


#ifndef __IRTCMediaEvent_FWD_DEFINED__
#define __IRTCMediaEvent_FWD_DEFINED__
typedef interface IRTCMediaEvent IRTCMediaEvent;

#endif 	/* __IRTCMediaEvent_FWD_DEFINED__ */


#ifndef __IRTCIntensityEvent_FWD_DEFINED__
#define __IRTCIntensityEvent_FWD_DEFINED__
typedef interface IRTCIntensityEvent IRTCIntensityEvent;

#endif 	/* __IRTCIntensityEvent_FWD_DEFINED__ */


#ifndef __IRTCMessagingEvent_FWD_DEFINED__
#define __IRTCMessagingEvent_FWD_DEFINED__
typedef interface IRTCMessagingEvent IRTCMessagingEvent;

#endif 	/* __IRTCMessagingEvent_FWD_DEFINED__ */


#ifndef __IRTCBuddyEvent_FWD_DEFINED__
#define __IRTCBuddyEvent_FWD_DEFINED__
typedef interface IRTCBuddyEvent IRTCBuddyEvent;

#endif 	/* __IRTCBuddyEvent_FWD_DEFINED__ */


#ifndef __IRTCBuddyEvent2_FWD_DEFINED__
#define __IRTCBuddyEvent2_FWD_DEFINED__
typedef interface IRTCBuddyEvent2 IRTCBuddyEvent2;

#endif 	/* __IRTCBuddyEvent2_FWD_DEFINED__ */


#ifndef __IRTCWatcherEvent_FWD_DEFINED__
#define __IRTCWatcherEvent_FWD_DEFINED__
typedef interface IRTCWatcherEvent IRTCWatcherEvent;

#endif 	/* __IRTCWatcherEvent_FWD_DEFINED__ */


#ifndef __IRTCPortManager_FWD_DEFINED__
#define __IRTCPortManager_FWD_DEFINED__
typedef interface IRTCPortManager IRTCPortManager;

#endif 	/* __IRTCPortManager_FWD_DEFINED__ */


#ifndef __IRTCSessionPortManagement_FWD_DEFINED__
#define __IRTCSessionPortManagement_FWD_DEFINED__
typedef interface IRTCSessionPortManagement IRTCSessionPortManagement;

#endif 	/* __IRTCSessionPortManagement_FWD_DEFINED__ */


#ifndef __IRTCClientPortManagement_FWD_DEFINED__
#define __IRTCClientPortManagement_FWD_DEFINED__
typedef interface IRTCClientPortManagement IRTCClientPortManagement;

#endif 	/* __IRTCClientPortManagement_FWD_DEFINED__ */


#ifndef __IRTCWatcherEvent2_FWD_DEFINED__
#define __IRTCWatcherEvent2_FWD_DEFINED__
typedef interface IRTCWatcherEvent2 IRTCWatcherEvent2;

#endif 	/* __IRTCWatcherEvent2_FWD_DEFINED__ */


#ifndef __IRTCBuddyGroupEvent_FWD_DEFINED__
#define __IRTCBuddyGroupEvent_FWD_DEFINED__
typedef interface IRTCBuddyGroupEvent IRTCBuddyGroupEvent;

#endif 	/* __IRTCBuddyGroupEvent_FWD_DEFINED__ */


#ifndef __IRTCProfileEvent_FWD_DEFINED__
#define __IRTCProfileEvent_FWD_DEFINED__
typedef interface IRTCProfileEvent IRTCProfileEvent;

#endif 	/* __IRTCProfileEvent_FWD_DEFINED__ */


#ifndef __IRTCProfileEvent2_FWD_DEFINED__
#define __IRTCProfileEvent2_FWD_DEFINED__
typedef interface IRTCProfileEvent2 IRTCProfileEvent2;

#endif 	/* __IRTCProfileEvent2_FWD_DEFINED__ */


#ifndef __IRTCUserSearchResultsEvent_FWD_DEFINED__
#define __IRTCUserSearchResultsEvent_FWD_DEFINED__
typedef interface IRTCUserSearchResultsEvent IRTCUserSearchResultsEvent;

#endif 	/* __IRTCUserSearchResultsEvent_FWD_DEFINED__ */


#ifndef __IRTCInfoEvent_FWD_DEFINED__
#define __IRTCInfoEvent_FWD_DEFINED__
typedef interface IRTCInfoEvent IRTCInfoEvent;

#endif 	/* __IRTCInfoEvent_FWD_DEFINED__ */


#ifndef __IRTCRoamingEvent_FWD_DEFINED__
#define __IRTCRoamingEvent_FWD_DEFINED__
typedef interface IRTCRoamingEvent IRTCRoamingEvent;

#endif 	/* __IRTCRoamingEvent_FWD_DEFINED__ */


#ifndef __IRTCMediaRequestEvent_FWD_DEFINED__
#define __IRTCMediaRequestEvent_FWD_DEFINED__
typedef interface IRTCMediaRequestEvent IRTCMediaRequestEvent;

#endif 	/* __IRTCMediaRequestEvent_FWD_DEFINED__ */


#ifndef __IRTCReInviteEvent_FWD_DEFINED__
#define __IRTCReInviteEvent_FWD_DEFINED__
typedef interface IRTCReInviteEvent IRTCReInviteEvent;

#endif 	/* __IRTCReInviteEvent_FWD_DEFINED__ */


#ifndef __IRTCPresencePropertyEvent_FWD_DEFINED__
#define __IRTCPresencePropertyEvent_FWD_DEFINED__
typedef interface IRTCPresencePropertyEvent IRTCPresencePropertyEvent;

#endif 	/* __IRTCPresencePropertyEvent_FWD_DEFINED__ */


#ifndef __IRTCPresenceDataEvent_FWD_DEFINED__
#define __IRTCPresenceDataEvent_FWD_DEFINED__
typedef interface IRTCPresenceDataEvent IRTCPresenceDataEvent;

#endif 	/* __IRTCPresenceDataEvent_FWD_DEFINED__ */


#ifndef __IRTCPresenceStatusEvent_FWD_DEFINED__
#define __IRTCPresenceStatusEvent_FWD_DEFINED__
typedef interface IRTCPresenceStatusEvent IRTCPresenceStatusEvent;

#endif 	/* __IRTCPresenceStatusEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionReferStatusEvent_FWD_DEFINED__
#define __IRTCSessionReferStatusEvent_FWD_DEFINED__
typedef interface IRTCSessionReferStatusEvent IRTCSessionReferStatusEvent;

#endif 	/* __IRTCSessionReferStatusEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionReferredEvent_FWD_DEFINED__
#define __IRTCSessionReferredEvent_FWD_DEFINED__
typedef interface IRTCSessionReferredEvent IRTCSessionReferredEvent;

#endif 	/* __IRTCSessionReferredEvent_FWD_DEFINED__ */


#ifndef __IRTCSessionDescriptionManager_FWD_DEFINED__
#define __IRTCSessionDescriptionManager_FWD_DEFINED__
typedef interface IRTCSessionDescriptionManager IRTCSessionDescriptionManager;

#endif 	/* __IRTCSessionDescriptionManager_FWD_DEFINED__ */


#ifndef __IRTCEnumPresenceDevices_FWD_DEFINED__
#define __IRTCEnumPresenceDevices_FWD_DEFINED__
typedef interface IRTCEnumPresenceDevices IRTCEnumPresenceDevices;

#endif 	/* __IRTCEnumPresenceDevices_FWD_DEFINED__ */


#ifndef __IRTCPresenceDevice_FWD_DEFINED__
#define __IRTCPresenceDevice_FWD_DEFINED__
typedef interface IRTCPresenceDevice IRTCPresenceDevice;

#endif 	/* __IRTCPresenceDevice_FWD_DEFINED__ */


#ifndef __IRTCDispatchEventNotification_FWD_DEFINED__
#define __IRTCDispatchEventNotification_FWD_DEFINED__
typedef interface IRTCDispatchEventNotification IRTCDispatchEventNotification;

#endif 	/* __IRTCDispatchEventNotification_FWD_DEFINED__ */


#ifndef __RTCClient_FWD_DEFINED__
#define __RTCClient_FWD_DEFINED__

#ifdef __cplusplus
typedef class RTCClient RTCClient;
#else
typedef struct RTCClient RTCClient;
#endif /* __cplusplus */

#endif 	/* __RTCClient_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "control.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_rtccore_0000_0000 */
/* [local] */ 

//  Copyright (c) Microsoft Corporation.  All rights reserved.
#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
typedef 
enum RTC_AUDIO_DEVICE
    {
        RTCAD_SPEAKER	= 0,
        RTCAD_MICROPHONE	= ( RTCAD_SPEAKER + 1 ) 
    } 	RTC_AUDIO_DEVICE;

typedef 
enum RTC_VIDEO_DEVICE
    {
        RTCVD_RECEIVE	= 0,
        RTCVD_PREVIEW	= ( RTCVD_RECEIVE + 1 ) 
    } 	RTC_VIDEO_DEVICE;

typedef 
enum RTC_EVENT
    {
        RTCE_CLIENT	= 0,
        RTCE_REGISTRATION_STATE_CHANGE	= ( RTCE_CLIENT + 1 ) ,
        RTCE_SESSION_STATE_CHANGE	= ( RTCE_REGISTRATION_STATE_CHANGE + 1 ) ,
        RTCE_SESSION_OPERATION_COMPLETE	= ( RTCE_SESSION_STATE_CHANGE + 1 ) ,
        RTCE_PARTICIPANT_STATE_CHANGE	= ( RTCE_SESSION_OPERATION_COMPLETE + 1 ) ,
        RTCE_MEDIA	= ( RTCE_PARTICIPANT_STATE_CHANGE + 1 ) ,
        RTCE_INTENSITY	= ( RTCE_MEDIA + 1 ) ,
        RTCE_MESSAGING	= ( RTCE_INTENSITY + 1 ) ,
        RTCE_BUDDY	= ( RTCE_MESSAGING + 1 ) ,
        RTCE_WATCHER	= ( RTCE_BUDDY + 1 ) ,
        RTCE_PROFILE	= ( RTCE_WATCHER + 1 ) ,
        RTCE_USERSEARCH	= ( RTCE_PROFILE + 1 ) ,
        RTCE_INFO	= ( RTCE_USERSEARCH + 1 ) ,
        RTCE_GROUP	= ( RTCE_INFO + 1 ) ,
        RTCE_MEDIA_REQUEST	= ( RTCE_GROUP + 1 ) ,
        RTCE_ROAMING	= ( RTCE_MEDIA_REQUEST + 1 ) ,
        RTCE_PRESENCE_PROPERTY	= ( RTCE_ROAMING + 1 ) ,
        RTCE_PRESENCE_DATA	= ( RTCE_PRESENCE_PROPERTY + 1 ) ,
        RTCE_PRESENCE_STATUS	= ( RTCE_PRESENCE_DATA + 1 ) ,
        RTCE_SESSION_REFER_STATUS	= ( RTCE_PRESENCE_STATUS + 1 ) ,
        RTCE_SESSION_REFERRED	= ( RTCE_SESSION_REFER_STATUS + 1 ) ,
        RTCE_REINVITE	= ( RTCE_SESSION_REFERRED + 1 ) 
    } 	RTC_EVENT;

typedef 
enum RTC_LISTEN_MODE
    {
        RTCLM_NONE	= 0,
        RTCLM_DYNAMIC	= ( RTCLM_NONE + 1 ) ,
        RTCLM_BOTH	= ( RTCLM_DYNAMIC + 1 ) 
    } 	RTC_LISTEN_MODE;

typedef 
enum RTC_CLIENT_EVENT_TYPE
    {
        RTCCET_VOLUME_CHANGE	= 0,
        RTCCET_DEVICE_CHANGE	= ( RTCCET_VOLUME_CHANGE + 1 ) ,
        RTCCET_NETWORK_QUALITY_CHANGE	= ( RTCCET_DEVICE_CHANGE + 1 ) ,
        RTCCET_ASYNC_CLEANUP_DONE	= ( RTCCET_NETWORK_QUALITY_CHANGE + 1 ) 
    } 	RTC_CLIENT_EVENT_TYPE;

typedef 
enum RTC_BUDDY_EVENT_TYPE
    {
        RTCBET_BUDDY_ADD	= 0,
        RTCBET_BUDDY_REMOVE	= ( RTCBET_BUDDY_ADD + 1 ) ,
        RTCBET_BUDDY_UPDATE	= ( RTCBET_BUDDY_REMOVE + 1 ) ,
        RTCBET_BUDDY_STATE_CHANGE	= ( RTCBET_BUDDY_UPDATE + 1 ) ,
        RTCBET_BUDDY_ROAMED	= ( RTCBET_BUDDY_STATE_CHANGE + 1 ) ,
        RTCBET_BUDDY_SUBSCRIBED	= ( RTCBET_BUDDY_ROAMED + 1 ) 
    } 	RTC_BUDDY_EVENT_TYPE;

typedef 
enum RTC_WATCHER_EVENT_TYPE
    {
        RTCWET_WATCHER_ADD	= 0,
        RTCWET_WATCHER_REMOVE	= ( RTCWET_WATCHER_ADD + 1 ) ,
        RTCWET_WATCHER_UPDATE	= ( RTCWET_WATCHER_REMOVE + 1 ) ,
        RTCWET_WATCHER_OFFERING	= ( RTCWET_WATCHER_UPDATE + 1 ) ,
        RTCWET_WATCHER_ROAMED	= ( RTCWET_WATCHER_OFFERING + 1 ) 
    } 	RTC_WATCHER_EVENT_TYPE;

typedef 
enum RTC_GROUP_EVENT_TYPE
    {
        RTCGET_GROUP_ADD	= 0,
        RTCGET_GROUP_REMOVE	= ( RTCGET_GROUP_ADD + 1 ) ,
        RTCGET_GROUP_UPDATE	= ( RTCGET_GROUP_REMOVE + 1 ) ,
        RTCGET_GROUP_BUDDY_ADD	= ( RTCGET_GROUP_UPDATE + 1 ) ,
        RTCGET_GROUP_BUDDY_REMOVE	= ( RTCGET_GROUP_BUDDY_ADD + 1 ) ,
        RTCGET_GROUP_ROAMED	= ( RTCGET_GROUP_BUDDY_REMOVE + 1 ) 
    } 	RTC_GROUP_EVENT_TYPE;

typedef 
enum RTC_TERMINATE_REASON
    {
        RTCTR_NORMAL	= 0,
        RTCTR_DND	= ( RTCTR_NORMAL + 1 ) ,
        RTCTR_BUSY	= ( RTCTR_DND + 1 ) ,
        RTCTR_REJECT	= ( RTCTR_BUSY + 1 ) ,
        RTCTR_TIMEOUT	= ( RTCTR_REJECT + 1 ) ,
        RTCTR_SHUTDOWN	= ( RTCTR_TIMEOUT + 1 ) ,
        RTCTR_INSUFFICIENT_SECURITY_LEVEL	= ( RTCTR_SHUTDOWN + 1 ) ,
        RTCTR_NOT_SUPPORTED	= ( RTCTR_INSUFFICIENT_SECURITY_LEVEL + 1 ) 
    } 	RTC_TERMINATE_REASON;

typedef 
enum RTC_REGISTRATION_STATE
    {
        RTCRS_NOT_REGISTERED	= 0,
        RTCRS_REGISTERING	= ( RTCRS_NOT_REGISTERED + 1 ) ,
        RTCRS_REGISTERED	= ( RTCRS_REGISTERING + 1 ) ,
        RTCRS_REJECTED	= ( RTCRS_REGISTERED + 1 ) ,
        RTCRS_UNREGISTERING	= ( RTCRS_REJECTED + 1 ) ,
        RTCRS_ERROR	= ( RTCRS_UNREGISTERING + 1 ) ,
        RTCRS_LOGGED_OFF	= ( RTCRS_ERROR + 1 ) ,
        RTCRS_LOCAL_PA_LOGGED_OFF	= ( RTCRS_LOGGED_OFF + 1 ) ,
        RTCRS_REMOTE_PA_LOGGED_OFF	= ( RTCRS_LOCAL_PA_LOGGED_OFF + 1 ) 
    } 	RTC_REGISTRATION_STATE;

typedef 
enum RTC_SESSION_STATE
    {
        RTCSS_IDLE	= 0,
        RTCSS_INCOMING	= ( RTCSS_IDLE + 1 ) ,
        RTCSS_ANSWERING	= ( RTCSS_INCOMING + 1 ) ,
        RTCSS_INPROGRESS	= ( RTCSS_ANSWERING + 1 ) ,
        RTCSS_CONNECTED	= ( RTCSS_INPROGRESS + 1 ) ,
        RTCSS_DISCONNECTED	= ( RTCSS_CONNECTED + 1 ) ,
        RTCSS_HOLD	= ( RTCSS_DISCONNECTED + 1 ) ,
        RTCSS_REFER	= ( RTCSS_HOLD + 1 ) 
    } 	RTC_SESSION_STATE;

typedef 
enum RTC_PARTICIPANT_STATE
    {
        RTCPS_IDLE	= 0,
        RTCPS_PENDING	= ( RTCPS_IDLE + 1 ) ,
        RTCPS_INCOMING	= ( RTCPS_PENDING + 1 ) ,
        RTCPS_ANSWERING	= ( RTCPS_INCOMING + 1 ) ,
        RTCPS_INPROGRESS	= ( RTCPS_ANSWERING + 1 ) ,
        RTCPS_ALERTING	= ( RTCPS_INPROGRESS + 1 ) ,
        RTCPS_CONNECTED	= ( RTCPS_ALERTING + 1 ) ,
        RTCPS_DISCONNECTING	= ( RTCPS_CONNECTED + 1 ) ,
        RTCPS_DISCONNECTED	= ( RTCPS_DISCONNECTING + 1 ) 
    } 	RTC_PARTICIPANT_STATE;

typedef 
enum RTC_WATCHER_STATE
    {
        RTCWS_UNKNOWN	= 0,
        RTCWS_OFFERING	= ( RTCWS_UNKNOWN + 1 ) ,
        RTCWS_ALLOWED	= ( RTCWS_OFFERING + 1 ) ,
        RTCWS_BLOCKED	= ( RTCWS_ALLOWED + 1 ) ,
        RTCWS_DENIED	= ( RTCWS_BLOCKED + 1 ) ,
        RTCWS_PROMPT	= ( RTCWS_DENIED + 1 ) 
    } 	RTC_WATCHER_STATE;

typedef 
enum RTC_ACE_SCOPE
    {
        RTCAS_SCOPE_USER	= 0,
        RTCAS_SCOPE_DOMAIN	= ( RTCAS_SCOPE_USER + 1 ) ,
        RTCAS_SCOPE_ALL	= ( RTCAS_SCOPE_DOMAIN + 1 ) 
    } 	RTC_ACE_SCOPE;

typedef 
enum RTC_OFFER_WATCHER_MODE
    {
        RTCOWM_OFFER_WATCHER_EVENT	= 0,
        RTCOWM_AUTOMATICALLY_ADD_WATCHER	= ( RTCOWM_OFFER_WATCHER_EVENT + 1 ) 
    } 	RTC_OFFER_WATCHER_MODE;

typedef 
enum RTC_WATCHER_MATCH_MODE
    {
        RTCWMM_EXACT_MATCH	= 0,
        RTCWMM_BEST_ACE_MATCH	= ( RTCWMM_EXACT_MATCH + 1 ) 
    } 	RTC_WATCHER_MATCH_MODE;

typedef 
enum RTC_PRIVACY_MODE
    {
        RTCPM_BLOCK_LIST_EXCLUDED	= 0,
        RTCPM_ALLOW_LIST_ONLY	= ( RTCPM_BLOCK_LIST_EXCLUDED + 1 ) 
    } 	RTC_PRIVACY_MODE;

typedef 
enum RTC_SESSION_TYPE
    {
        RTCST_PC_TO_PC	= 0,
        RTCST_PC_TO_PHONE	= ( RTCST_PC_TO_PC + 1 ) ,
        RTCST_PHONE_TO_PHONE	= ( RTCST_PC_TO_PHONE + 1 ) ,
        RTCST_IM	= ( RTCST_PHONE_TO_PHONE + 1 ) ,
        RTCST_MULTIPARTY_IM	= ( RTCST_IM + 1 ) ,
        RTCST_APPLICATION	= ( RTCST_MULTIPARTY_IM + 1 ) 
    } 	RTC_SESSION_TYPE;

typedef 
enum RTC_PRESENCE_STATUS
    {
        RTCXS_PRESENCE_OFFLINE	= 0,
        RTCXS_PRESENCE_ONLINE	= ( RTCXS_PRESENCE_OFFLINE + 1 ) ,
        RTCXS_PRESENCE_AWAY	= ( RTCXS_PRESENCE_ONLINE + 1 ) ,
        RTCXS_PRESENCE_IDLE	= ( RTCXS_PRESENCE_AWAY + 1 ) ,
        RTCXS_PRESENCE_BUSY	= ( RTCXS_PRESENCE_IDLE + 1 ) ,
        RTCXS_PRESENCE_BE_RIGHT_BACK	= ( RTCXS_PRESENCE_BUSY + 1 ) ,
        RTCXS_PRESENCE_ON_THE_PHONE	= ( RTCXS_PRESENCE_BE_RIGHT_BACK + 1 ) ,
        RTCXS_PRESENCE_OUT_TO_LUNCH	= ( RTCXS_PRESENCE_ON_THE_PHONE + 1 ) 
    } 	RTC_PRESENCE_STATUS;

typedef 
enum RTC_BUDDY_SUBSCRIPTION_TYPE
    {
        RTCBT_SUBSCRIBED	= 0,
        RTCBT_ALWAYS_OFFLINE	= ( RTCBT_SUBSCRIBED + 1 ) ,
        RTCBT_ALWAYS_ONLINE	= ( RTCBT_ALWAYS_OFFLINE + 1 ) ,
        RTCBT_POLL	= ( RTCBT_ALWAYS_ONLINE + 1 ) 
    } 	RTC_BUDDY_SUBSCRIPTION_TYPE;

typedef 
enum RTC_MEDIA_EVENT_TYPE
    {
        RTCMET_STOPPED	= 0,
        RTCMET_STARTED	= ( RTCMET_STOPPED + 1 ) ,
        RTCMET_FAILED	= ( RTCMET_STARTED + 1 ) 
    } 	RTC_MEDIA_EVENT_TYPE;

typedef 
enum RTC_MEDIA_EVENT_REASON
    {
        RTCMER_NORMAL	= 0,
        RTCMER_HOLD	= ( RTCMER_NORMAL + 1 ) ,
        RTCMER_TIMEOUT	= ( RTCMER_HOLD + 1 ) ,
        RTCMER_BAD_DEVICE	= ( RTCMER_TIMEOUT + 1 ) ,
        RTCMER_NO_PORT	= ( RTCMER_BAD_DEVICE + 1 ) ,
        RTCMER_PORT_MAPPING_FAILED	= ( RTCMER_NO_PORT + 1 ) ,
        RTCMER_REMOTE_REQUEST	= ( RTCMER_PORT_MAPPING_FAILED + 1 ) 
    } 	RTC_MEDIA_EVENT_REASON;

typedef 
enum RTC_MESSAGING_EVENT_TYPE
    {
        RTCMSET_MESSAGE	= 0,
        RTCMSET_STATUS	= ( RTCMSET_MESSAGE + 1 ) 
    } 	RTC_MESSAGING_EVENT_TYPE;

typedef 
enum RTC_MESSAGING_USER_STATUS
    {
        RTCMUS_IDLE	= 0,
        RTCMUS_TYPING	= ( RTCMUS_IDLE + 1 ) 
    } 	RTC_MESSAGING_USER_STATUS;

typedef 
enum RTC_DTMF
    {
        RTC_DTMF_0	= 0,
        RTC_DTMF_1	= ( RTC_DTMF_0 + 1 ) ,
        RTC_DTMF_2	= ( RTC_DTMF_1 + 1 ) ,
        RTC_DTMF_3	= ( RTC_DTMF_2 + 1 ) ,
        RTC_DTMF_4	= ( RTC_DTMF_3 + 1 ) ,
        RTC_DTMF_5	= ( RTC_DTMF_4 + 1 ) ,
        RTC_DTMF_6	= ( RTC_DTMF_5 + 1 ) ,
        RTC_DTMF_7	= ( RTC_DTMF_6 + 1 ) ,
        RTC_DTMF_8	= ( RTC_DTMF_7 + 1 ) ,
        RTC_DTMF_9	= ( RTC_DTMF_8 + 1 ) ,
        RTC_DTMF_STAR	= ( RTC_DTMF_9 + 1 ) ,
        RTC_DTMF_POUND	= ( RTC_DTMF_STAR + 1 ) ,
        RTC_DTMF_A	= ( RTC_DTMF_POUND + 1 ) ,
        RTC_DTMF_B	= ( RTC_DTMF_A + 1 ) ,
        RTC_DTMF_C	= ( RTC_DTMF_B + 1 ) ,
        RTC_DTMF_D	= ( RTC_DTMF_C + 1 ) ,
        RTC_DTMF_FLASH	= ( RTC_DTMF_D + 1 ) 
    } 	RTC_DTMF;

typedef 
enum RTC_PROVIDER_URI
    {
        RTCPU_URIHOMEPAGE	= 0,
        RTCPU_URIHELPDESK	= ( RTCPU_URIHOMEPAGE + 1 ) ,
        RTCPU_URIPERSONALACCOUNT	= ( RTCPU_URIHELPDESK + 1 ) ,
        RTCPU_URIDISPLAYDURINGCALL	= ( RTCPU_URIPERSONALACCOUNT + 1 ) ,
        RTCPU_URIDISPLAYDURINGIDLE	= ( RTCPU_URIDISPLAYDURINGCALL + 1 ) 
    } 	RTC_PROVIDER_URI;

typedef 
enum RTC_RING_TYPE
    {
        RTCRT_PHONE	= 0,
        RTCRT_MESSAGE	= ( RTCRT_PHONE + 1 ) ,
        RTCRT_RINGBACK	= ( RTCRT_MESSAGE + 1 ) 
    } 	RTC_RING_TYPE;

typedef 
enum RTC_T120_APPLET
    {
        RTCTA_WHITEBOARD	= 0,
        RTCTA_APPSHARING	= ( RTCTA_WHITEBOARD + 1 ) 
    } 	RTC_T120_APPLET;

typedef 
enum RTC_PORT_TYPE
    {
        RTCPT_AUDIO_RTP	= 0,
        RTCPT_AUDIO_RTCP	= ( RTCPT_AUDIO_RTP + 1 ) ,
        RTCPT_VIDEO_RTP	= ( RTCPT_AUDIO_RTCP + 1 ) ,
        RTCPT_VIDEO_RTCP	= ( RTCPT_VIDEO_RTP + 1 ) ,
        RTCPT_SIP	= ( RTCPT_VIDEO_RTCP + 1 ) 
    } 	RTC_PORT_TYPE;

typedef 
enum RTC_USER_SEARCH_COLUMN
    {
        RTCUSC_URI	= 0,
        RTCUSC_DISPLAYNAME	= ( RTCUSC_URI + 1 ) ,
        RTCUSC_TITLE	= ( RTCUSC_DISPLAYNAME + 1 ) ,
        RTCUSC_OFFICE	= ( RTCUSC_TITLE + 1 ) ,
        RTCUSC_PHONE	= ( RTCUSC_OFFICE + 1 ) ,
        RTCUSC_COMPANY	= ( RTCUSC_PHONE + 1 ) ,
        RTCUSC_CITY	= ( RTCUSC_COMPANY + 1 ) ,
        RTCUSC_STATE	= ( RTCUSC_CITY + 1 ) ,
        RTCUSC_COUNTRY	= ( RTCUSC_STATE + 1 ) ,
        RTCUSC_EMAIL	= ( RTCUSC_COUNTRY + 1 ) 
    } 	RTC_USER_SEARCH_COLUMN;

typedef 
enum RTC_USER_SEARCH_PREFERENCE
    {
        RTCUSP_MAX_MATCHES	= 0,
        RTCUSP_TIME_LIMIT	= ( RTCUSP_MAX_MATCHES + 1 ) 
    } 	RTC_USER_SEARCH_PREFERENCE;

typedef 
enum RTC_ROAMING_EVENT_TYPE
    {
        RTCRET_BUDDY_ROAMING	= 0,
        RTCRET_WATCHER_ROAMING	= ( RTCRET_BUDDY_ROAMING + 1 ) ,
        RTCRET_PRESENCE_ROAMING	= ( RTCRET_WATCHER_ROAMING + 1 ) ,
        RTCRET_PROFILE_ROAMING	= ( RTCRET_PRESENCE_ROAMING + 1 ) ,
        RTCRET_WPENDING_ROAMING	= ( RTCRET_PROFILE_ROAMING + 1 ) 
    } 	RTC_ROAMING_EVENT_TYPE;

typedef 
enum RTC_PROFILE_EVENT_TYPE
    {
        RTCPFET_PROFILE_GET	= 0,
        RTCPFET_PROFILE_UPDATE	= ( RTCPFET_PROFILE_GET + 1 ) 
    } 	RTC_PROFILE_EVENT_TYPE;

typedef 
enum RTC_ANSWER_MODE
    {
        RTCAM_OFFER_SESSION_EVENT	= 0,
        RTCAM_AUTOMATICALLY_ACCEPT	= ( RTCAM_OFFER_SESSION_EVENT + 1 ) ,
        RTCAM_AUTOMATICALLY_REJECT	= ( RTCAM_AUTOMATICALLY_ACCEPT + 1 ) ,
        RTCAM_NOT_SUPPORTED	= ( RTCAM_AUTOMATICALLY_REJECT + 1 ) 
    } 	RTC_ANSWER_MODE;

typedef 
enum RTC_SESSION_REFER_STATUS
    {
        RTCSRS_REFERRING	= 0,
        RTCSRS_ACCEPTED	= ( RTCSRS_REFERRING + 1 ) ,
        RTCSRS_ERROR	= ( RTCSRS_ACCEPTED + 1 ) ,
        RTCSRS_REJECTED	= ( RTCSRS_ERROR + 1 ) ,
        RTCSRS_DROPPED	= ( RTCSRS_REJECTED + 1 ) ,
        RTCSRS_DONE	= ( RTCSRS_DROPPED + 1 ) 
    } 	RTC_SESSION_REFER_STATUS;

typedef 
enum RTC_PRESENCE_PROPERTY
    {
        RTCPP_PHONENUMBER	= 0,
        RTCPP_DISPLAYNAME	= ( RTCPP_PHONENUMBER + 1 ) ,
        RTCPP_EMAIL	= ( RTCPP_DISPLAYNAME + 1 ) ,
        RTCPP_DEVICE_NAME	= ( RTCPP_EMAIL + 1 ) ,
        RTCPP_MULTIPLE	= ( RTCPP_DEVICE_NAME + 1 ) 
    } 	RTC_PRESENCE_PROPERTY;

typedef 
enum RTC_SECURITY_TYPE
    {
        RTCSECT_AUDIO_VIDEO_MEDIA_ENCRYPTION	= 0,
        RTCSECT_T120_MEDIA_ENCRYPTION	= ( RTCSECT_AUDIO_VIDEO_MEDIA_ENCRYPTION + 1 ) 
    } 	RTC_SECURITY_TYPE;

typedef 
enum RTC_SECURITY_LEVEL
    {
        RTCSECL_UNSUPPORTED	= 1,
        RTCSECL_SUPPORTED	= ( RTCSECL_UNSUPPORTED + 1 ) ,
        RTCSECL_REQUIRED	= ( RTCSECL_SUPPORTED + 1 ) 
    } 	RTC_SECURITY_LEVEL;

typedef 
enum RTC_REINVITE_STATE
    {
        RTCRIN_INCOMING	= 0,
        RTCRIN_SUCCEEDED	= ( RTCRIN_INCOMING + 1 ) ,
        RTCRIN_FAIL	= ( RTCRIN_SUCCEEDED + 1 ) 
    } 	RTC_REINVITE_STATE;

#define RTCCS_FORCE_PROFILE          0x00000001
#define RTCCS_FAIL_ON_REDIRECT       0x00000002
#define RTCMT_AUDIO_SEND     0x00000001
#define RTCMT_AUDIO_RECEIVE  0x00000002
#define RTCMT_VIDEO_SEND     0x00000004
#define RTCMT_VIDEO_RECEIVE  0x00000008
#define RTCMT_T120_SENDRECV  0x00000010
#define RTCMT_ALL_RTP   (       \
         RTCMT_AUDIO_SEND    |  \
         RTCMT_AUDIO_RECEIVE  | \
         RTCMT_VIDEO_SEND  |    \
         RTCMT_VIDEO_RECEIVE )    
#define RTCMT_ALL       (       \
         RTCMT_ALL_RTP    |     \
         RTCMT_T120_SENDRECV  )   
#define RTCSI_PC_TO_PC       0x00000001
#define RTCSI_PC_TO_PHONE    0x00000002
#define RTCSI_PHONE_TO_PHONE 0x00000004
#define RTCSI_IM             0x00000008
#define RTCSI_MULTIPARTY_IM  0x00000010
#define RTCSI_APPLICATION	0x00000020
#define RTCTR_UDP            0x00000001
#define RTCTR_TCP            0x00000002
#define RTCTR_TLS            0x00000004
#define RTCAU_BASIC                  0x00000001
#define RTCAU_DIGEST                 0x00000002
#define RTCAU_NTLM                   0x00000004
#define RTCAU_KERBEROS               0x00000008
#define RTCAU_USE_LOGON_CRED         0x00010000
#define RTCRF_REGISTER_INVITE_SESSIONS   0x00000001
#define RTCRF_REGISTER_MESSAGE_SESSIONS  0x00000002
#define RTCRF_REGISTER_PRESENCE          0x00000004
#define RTCRF_REGISTER_NOTIFY            0x00000008
#define RTCRF_REGISTER_ALL               0x0000000F
#define RTCRMF_BUDDY_ROAMING              0x00000001
#define RTCRMF_WATCHER_ROAMING            0x00000002
#define RTCRMF_PRESENCE_ROAMING           0x00000004
#define RTCRMF_PROFILE_ROAMING            0x00000008
#define RTCRMF_ALL_ROAMING                0x0000000F
#define RTCEF_CLIENT                     0x00000001
#define RTCEF_REGISTRATION_STATE_CHANGE  0x00000002
#define RTCEF_SESSION_STATE_CHANGE       0x00000004
#define RTCEF_SESSION_OPERATION_COMPLETE 0x00000008
#define RTCEF_PARTICIPANT_STATE_CHANGE   0x00000010
#define RTCEF_MEDIA                      0x00000020
#define RTCEF_INTENSITY                  0x00000040
#define RTCEF_MESSAGING                  0x00000080
#define RTCEF_BUDDY                      0x00000100
#define RTCEF_WATCHER                    0x00000200
#define RTCEF_PROFILE                    0x00000400
#define RTCEF_USERSEARCH                 0x00000800
#define RTCEF_INFO                       0x00001000
#define RTCEF_GROUP                      0x00002000
#define RTCEF_MEDIA_REQUEST              0x00004000
#define RTCEF_ROAMING                    0x00010000
#define RTCEF_PRESENCE_PROPERTY          0x00020000
#define RTCEF_BUDDY2                     0x00040000
#define RTCEF_WATCHER2                   0x00080000
#define RTCEF_SESSION_REFER_STATUS       0x00100000
#define RTCEF_SESSION_REFERRED           0x00200000
#define RTCEF_REINVITE                   0x00400000
#define RTCEF_PRESENCE_DATA              0x00800000
#define RTCEF_PRESENCE_STATUS            0x01000000
#define RTCEF_ALL                        0x01FFFFFF
#define RTCIF_DISABLE_MEDIA                          0x00000001
#define RTCIF_DISABLE_UPNP                           0x00000002
#define RTCIF_ENABLE_SERVER_CLASS                    0x00000004
#define RTCIF_DISABLE_STRICT_DNS                     0x00000008




































extern RPC_IF_HANDLE __MIDL_itf_rtccore_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_rtccore_0000_0000_v0_0_s_ifspec;

#ifndef __IRTCClient_INTERFACE_DEFINED__
#define __IRTCClient_INTERFACE_DEFINED__

/* interface IRTCClient */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("07829e45-9a34-408e-a011-bddf13487cd1")
    IRTCClient : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Shutdown( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PrepareForShutdown( void) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_EventFilter( 
            /* [annotation][in] */ 
            _In_  long lFilter) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EventFilter( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plFilter) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPreferredMediaTypes( 
            /* [annotation][in] */ 
            _In_  long lMediaTypes,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredMediaTypes( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaTypes) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MediaCapabilities( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaTypes) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateSession( 
            /* [annotation][in] */ 
            _In_  RTC_SESSION_TYPE enType,
            /* [annotation][in] */ 
            _In_  BSTR bstrLocalPhoneURI,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ListenForIncomingSessions( 
            /* [annotation][in] */ 
            _In_  RTC_LISTEN_MODE enListen) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ListenForIncomingSessions( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_LISTEN_MODE *penListen) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NetworkAddresses( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fTCP,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fExternal,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pvAddresses) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  long lVolume) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plVolume) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AudioMuted( 
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fMuted) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioMuted( 
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfMuted) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IVideoWindow( 
            /* [annotation][in] */ 
            _In_  RTC_VIDEO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  IVideoWindow **ppIVideoWindow) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredAudioDevice( 
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  BSTR bstrDeviceName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredAudioDevice( 
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDeviceName) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredVolume( 
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  long lVolume) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredVolume( 
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plVolume) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredAEC( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bEnable) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredAEC( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbEnabled) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredVideoDevice( 
            /* [annotation][in] */ 
            _In_  BSTR bstrDeviceName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredVideoDevice( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDeviceName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveMedia( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaType) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_MaxBitrate( 
            /* [annotation][in] */ 
            _In_  long lMaxBitrate) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MaxBitrate( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMaxBitrate) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_TemporalSpatialTradeOff( 
            /* [annotation][in] */ 
            _In_  long lValue) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_TemporalSpatialTradeOff( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plValue) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NetworkQuality( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plNetworkQuality) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StartT120Applet( 
            /* [annotation][in] */ 
            _In_  RTC_T120_APPLET enApplet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StopT120Applets( void) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsT120AppletRunning( 
            /* [annotation][in] */ 
            _In_  RTC_T120_APPLET enApplet,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfRunning) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LocalUserURI( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserURI) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_LocalUserURI( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LocalUserName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserName) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_LocalUserName( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PlayRing( 
            /* [annotation][in] */ 
            _In_  RTC_RING_TYPE enType,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bPlay) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendDTMF( 
            /* [annotation][in] */ 
            _In_  RTC_DTMF enDTMF) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InvokeTuningWizard( 
            /* [annotation][in] */ 
            _In_  OAHWND hwndParent) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsTuned( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfTuned) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCClient * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            __RPC__in IRTCClient * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Shutdown )( 
            __RPC__in IRTCClient * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PrepareForShutdown )( 
            __RPC__in IRTCClient * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EventFilter )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  long lFilter);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventFilter )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plFilter);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPreferredMediaTypes )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  long lMediaTypes,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredMediaTypes )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaTypes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MediaCapabilities )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaTypes);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateSession )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_SESSION_TYPE enType,
            /* [annotation][in] */ 
            _In_  BSTR bstrLocalPhoneURI,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ListenForIncomingSessions )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_LISTEN_MODE enListen);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ListenForIncomingSessions )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_LISTEN_MODE *penListen);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetworkAddresses )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fTCP,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fExternal,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pvAddresses);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  long lVolume);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plVolume);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AudioMuted )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fMuted);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioMuted )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfMuted);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IVideoWindow )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_VIDEO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  IVideoWindow **ppIVideoWindow);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredAudioDevice )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  BSTR bstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredAudioDevice )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDeviceName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredVolume )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  long lVolume);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredVolume )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plVolume);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredAEC )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bEnable);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredAEC )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbEnabled);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredVideoDevice )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredVideoDevice )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveMedia )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaType);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxBitrate )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  long lMaxBitrate);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxBitrate )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMaxBitrate);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TemporalSpatialTradeOff )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  long lValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TemporalSpatialTradeOff )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetworkQuality )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plNetworkQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartT120Applet )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_T120_APPLET enApplet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StopT120Applets )( 
            __RPC__in IRTCClient * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsT120AppletRunning )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_T120_APPLET enApplet,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfRunning);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalUserURI )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalUserURI )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalUserName )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalUserName )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PlayRing )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_RING_TYPE enType,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bPlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendDTMF )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  RTC_DTMF enDTMF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InvokeTuningWizard )( 
            __RPC__in IRTCClient * This,
            /* [annotation][in] */ 
            _In_  OAHWND hwndParent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsTuned )( 
            __RPC__in IRTCClient * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfTuned);
        
        END_INTERFACE
    } IRTCClientVtbl;

    interface IRTCClient
    {
        CONST_VTBL struct IRTCClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCClient_Initialize(This)	\
    ( (This)->lpVtbl -> Initialize(This) ) 

#define IRTCClient_Shutdown(This)	\
    ( (This)->lpVtbl -> Shutdown(This) ) 

#define IRTCClient_PrepareForShutdown(This)	\
    ( (This)->lpVtbl -> PrepareForShutdown(This) ) 

#define IRTCClient_put_EventFilter(This,lFilter)	\
    ( (This)->lpVtbl -> put_EventFilter(This,lFilter) ) 

#define IRTCClient_get_EventFilter(This,plFilter)	\
    ( (This)->lpVtbl -> get_EventFilter(This,plFilter) ) 

#define IRTCClient_SetPreferredMediaTypes(This,lMediaTypes,fPersistent)	\
    ( (This)->lpVtbl -> SetPreferredMediaTypes(This,lMediaTypes,fPersistent) ) 

#define IRTCClient_get_PreferredMediaTypes(This,plMediaTypes)	\
    ( (This)->lpVtbl -> get_PreferredMediaTypes(This,plMediaTypes) ) 

#define IRTCClient_get_MediaCapabilities(This,plMediaTypes)	\
    ( (This)->lpVtbl -> get_MediaCapabilities(This,plMediaTypes) ) 

#define IRTCClient_CreateSession(This,enType,bstrLocalPhoneURI,pProfile,lFlags,ppSession)	\
    ( (This)->lpVtbl -> CreateSession(This,enType,bstrLocalPhoneURI,pProfile,lFlags,ppSession) ) 

#define IRTCClient_put_ListenForIncomingSessions(This,enListen)	\
    ( (This)->lpVtbl -> put_ListenForIncomingSessions(This,enListen) ) 

#define IRTCClient_get_ListenForIncomingSessions(This,penListen)	\
    ( (This)->lpVtbl -> get_ListenForIncomingSessions(This,penListen) ) 

#define IRTCClient_get_NetworkAddresses(This,fTCP,fExternal,pvAddresses)	\
    ( (This)->lpVtbl -> get_NetworkAddresses(This,fTCP,fExternal,pvAddresses) ) 

#define IRTCClient_put_Volume(This,enDevice,lVolume)	\
    ( (This)->lpVtbl -> put_Volume(This,enDevice,lVolume) ) 

#define IRTCClient_get_Volume(This,enDevice,plVolume)	\
    ( (This)->lpVtbl -> get_Volume(This,enDevice,plVolume) ) 

#define IRTCClient_put_AudioMuted(This,enDevice,fMuted)	\
    ( (This)->lpVtbl -> put_AudioMuted(This,enDevice,fMuted) ) 

#define IRTCClient_get_AudioMuted(This,enDevice,pfMuted)	\
    ( (This)->lpVtbl -> get_AudioMuted(This,enDevice,pfMuted) ) 

#define IRTCClient_get_IVideoWindow(This,enDevice,ppIVideoWindow)	\
    ( (This)->lpVtbl -> get_IVideoWindow(This,enDevice,ppIVideoWindow) ) 

#define IRTCClient_put_PreferredAudioDevice(This,enDevice,bstrDeviceName)	\
    ( (This)->lpVtbl -> put_PreferredAudioDevice(This,enDevice,bstrDeviceName) ) 

#define IRTCClient_get_PreferredAudioDevice(This,enDevice,pbstrDeviceName)	\
    ( (This)->lpVtbl -> get_PreferredAudioDevice(This,enDevice,pbstrDeviceName) ) 

#define IRTCClient_put_PreferredVolume(This,enDevice,lVolume)	\
    ( (This)->lpVtbl -> put_PreferredVolume(This,enDevice,lVolume) ) 

#define IRTCClient_get_PreferredVolume(This,enDevice,plVolume)	\
    ( (This)->lpVtbl -> get_PreferredVolume(This,enDevice,plVolume) ) 

#define IRTCClient_put_PreferredAEC(This,bEnable)	\
    ( (This)->lpVtbl -> put_PreferredAEC(This,bEnable) ) 

#define IRTCClient_get_PreferredAEC(This,pbEnabled)	\
    ( (This)->lpVtbl -> get_PreferredAEC(This,pbEnabled) ) 

#define IRTCClient_put_PreferredVideoDevice(This,bstrDeviceName)	\
    ( (This)->lpVtbl -> put_PreferredVideoDevice(This,bstrDeviceName) ) 

#define IRTCClient_get_PreferredVideoDevice(This,pbstrDeviceName)	\
    ( (This)->lpVtbl -> get_PreferredVideoDevice(This,pbstrDeviceName) ) 

#define IRTCClient_get_ActiveMedia(This,plMediaType)	\
    ( (This)->lpVtbl -> get_ActiveMedia(This,plMediaType) ) 

#define IRTCClient_put_MaxBitrate(This,lMaxBitrate)	\
    ( (This)->lpVtbl -> put_MaxBitrate(This,lMaxBitrate) ) 

#define IRTCClient_get_MaxBitrate(This,plMaxBitrate)	\
    ( (This)->lpVtbl -> get_MaxBitrate(This,plMaxBitrate) ) 

#define IRTCClient_put_TemporalSpatialTradeOff(This,lValue)	\
    ( (This)->lpVtbl -> put_TemporalSpatialTradeOff(This,lValue) ) 

#define IRTCClient_get_TemporalSpatialTradeOff(This,plValue)	\
    ( (This)->lpVtbl -> get_TemporalSpatialTradeOff(This,plValue) ) 

#define IRTCClient_get_NetworkQuality(This,plNetworkQuality)	\
    ( (This)->lpVtbl -> get_NetworkQuality(This,plNetworkQuality) ) 

#define IRTCClient_StartT120Applet(This,enApplet)	\
    ( (This)->lpVtbl -> StartT120Applet(This,enApplet) ) 

#define IRTCClient_StopT120Applets(This)	\
    ( (This)->lpVtbl -> StopT120Applets(This) ) 

#define IRTCClient_get_IsT120AppletRunning(This,enApplet,pfRunning)	\
    ( (This)->lpVtbl -> get_IsT120AppletRunning(This,enApplet,pfRunning) ) 

#define IRTCClient_get_LocalUserURI(This,pbstrUserURI)	\
    ( (This)->lpVtbl -> get_LocalUserURI(This,pbstrUserURI) ) 

#define IRTCClient_put_LocalUserURI(This,bstrUserURI)	\
    ( (This)->lpVtbl -> put_LocalUserURI(This,bstrUserURI) ) 

#define IRTCClient_get_LocalUserName(This,pbstrUserName)	\
    ( (This)->lpVtbl -> get_LocalUserName(This,pbstrUserName) ) 

#define IRTCClient_put_LocalUserName(This,bstrUserName)	\
    ( (This)->lpVtbl -> put_LocalUserName(This,bstrUserName) ) 

#define IRTCClient_PlayRing(This,enType,bPlay)	\
    ( (This)->lpVtbl -> PlayRing(This,enType,bPlay) ) 

#define IRTCClient_SendDTMF(This,enDTMF)	\
    ( (This)->lpVtbl -> SendDTMF(This,enDTMF) ) 

#define IRTCClient_InvokeTuningWizard(This,hwndParent)	\
    ( (This)->lpVtbl -> InvokeTuningWizard(This,hwndParent) ) 

#define IRTCClient_get_IsTuned(This,pfTuned)	\
    ( (This)->lpVtbl -> get_IsTuned(This,pfTuned) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCClient_INTERFACE_DEFINED__ */


#ifndef __IRTCClient2_INTERFACE_DEFINED__
#define __IRTCClient2_INTERFACE_DEFINED__

/* interface IRTCClient2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClient2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0C91D71D-1064-42da-BFA5-572BEB8EEA84")
    IRTCClient2 : public IRTCClient
    {
    public:
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AnswerMode( 
            /* [annotation][in] */ 
            _In_  RTC_SESSION_TYPE enType,
            /* [annotation][in] */ 
            _In_  RTC_ANSWER_MODE enMode) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AnswerMode( 
            /* [annotation][in] */ 
            _In_  RTC_SESSION_TYPE enType,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_ANSWER_MODE *penMode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InvokeTuningWizardEx( 
            /* [annotation][in] */ 
            _In_  OAHWND hwndParent,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fAllowAudio,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fAllowVideo) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plVersion) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ClientName( 
            /* [annotation][in] */ 
            _In_  BSTR bstrClientName) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ClientCurVer( 
            /* [annotation][in] */ 
            _In_  BSTR bstrClientCurVer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InitializeEx( 
            /* [annotation][in] */ 
            _In_  long lFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateSessionWithDescription( 
            /* [annotation][in] */ 
            _In_  BSTR bstrContentType,
            /* [annotation][in] */ 
            _In_  BSTR bstrSessionDescription,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession2) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSessionDescriptionManager( 
            /* [annotation][in] */ 
            _In_  IRTCSessionDescriptionManager *pSessionDescriptionManager) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredSecurityLevel( 
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_LEVEL enSecurityLevel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredSecurityLevel( 
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SECURITY_LEVEL *penSecurityLevel) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AllowedPorts( 
            /* [annotation][in] */ 
            _In_  long lTransport,
            /* [annotation][in] */ 
            _In_  RTC_LISTEN_MODE enListenMode) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AllowedPorts( 
            /* [annotation][in] */ 
            _In_  long lTransport,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_LISTEN_MODE *penListenMode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCClient2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCClient2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCClient2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            __RPC__in IRTCClient2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Shutdown )( 
            __RPC__in IRTCClient2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PrepareForShutdown )( 
            __RPC__in IRTCClient2 * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EventFilter )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  long lFilter);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventFilter )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plFilter);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPreferredMediaTypes )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  long lMediaTypes,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredMediaTypes )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaTypes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MediaCapabilities )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaTypes);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateSession )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_SESSION_TYPE enType,
            /* [annotation][in] */ 
            _In_  BSTR bstrLocalPhoneURI,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ListenForIncomingSessions )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_LISTEN_MODE enListen);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ListenForIncomingSessions )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_LISTEN_MODE *penListen);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetworkAddresses )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fTCP,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fExternal,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pvAddresses);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  long lVolume);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plVolume);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AudioMuted )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fMuted);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioMuted )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfMuted);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IVideoWindow )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_VIDEO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  IVideoWindow **ppIVideoWindow);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredAudioDevice )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  BSTR bstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredAudioDevice )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDeviceName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredVolume )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][in] */ 
            _In_  long lVolume);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredVolume )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_AUDIO_DEVICE enDevice,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plVolume);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredAEC )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bEnable);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredAEC )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pbEnabled);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredVideoDevice )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredVideoDevice )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDeviceName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveMedia )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaType);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxBitrate )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  long lMaxBitrate);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxBitrate )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMaxBitrate);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TemporalSpatialTradeOff )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  long lValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TemporalSpatialTradeOff )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetworkQuality )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plNetworkQuality);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartT120Applet )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_T120_APPLET enApplet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StopT120Applets )( 
            __RPC__in IRTCClient2 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsT120AppletRunning )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_T120_APPLET enApplet,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfRunning);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalUserURI )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalUserURI )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalUserName )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalUserName )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PlayRing )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_RING_TYPE enType,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL bPlay);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendDTMF )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_DTMF enDTMF);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InvokeTuningWizard )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  OAHWND hwndParent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsTuned )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfTuned);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AnswerMode )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_SESSION_TYPE enType,
            /* [annotation][in] */ 
            _In_  RTC_ANSWER_MODE enMode);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AnswerMode )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_SESSION_TYPE enType,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_ANSWER_MODE *penMode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InvokeTuningWizardEx )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  OAHWND hwndParent,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fAllowAudio,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fAllowVideo);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plVersion);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClientName )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrClientName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClientCurVer )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrClientCurVer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InitializeEx )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  long lFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateSessionWithDescription )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrContentType,
            /* [annotation][in] */ 
            _In_  BSTR bstrSessionDescription,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession2);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSessionDescriptionManager )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  IRTCSessionDescriptionManager *pSessionDescriptionManager);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredSecurityLevel )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_LEVEL enSecurityLevel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredSecurityLevel )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SECURITY_LEVEL *penSecurityLevel);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowedPorts )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  long lTransport,
            /* [annotation][in] */ 
            _In_  RTC_LISTEN_MODE enListenMode);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowedPorts )( 
            __RPC__in IRTCClient2 * This,
            /* [annotation][in] */ 
            _In_  long lTransport,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_LISTEN_MODE *penListenMode);
        
        END_INTERFACE
    } IRTCClient2Vtbl;

    interface IRTCClient2
    {
        CONST_VTBL struct IRTCClient2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClient2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCClient2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCClient2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCClient2_Initialize(This)	\
    ( (This)->lpVtbl -> Initialize(This) ) 

#define IRTCClient2_Shutdown(This)	\
    ( (This)->lpVtbl -> Shutdown(This) ) 

#define IRTCClient2_PrepareForShutdown(This)	\
    ( (This)->lpVtbl -> PrepareForShutdown(This) ) 

#define IRTCClient2_put_EventFilter(This,lFilter)	\
    ( (This)->lpVtbl -> put_EventFilter(This,lFilter) ) 

#define IRTCClient2_get_EventFilter(This,plFilter)	\
    ( (This)->lpVtbl -> get_EventFilter(This,plFilter) ) 

#define IRTCClient2_SetPreferredMediaTypes(This,lMediaTypes,fPersistent)	\
    ( (This)->lpVtbl -> SetPreferredMediaTypes(This,lMediaTypes,fPersistent) ) 

#define IRTCClient2_get_PreferredMediaTypes(This,plMediaTypes)	\
    ( (This)->lpVtbl -> get_PreferredMediaTypes(This,plMediaTypes) ) 

#define IRTCClient2_get_MediaCapabilities(This,plMediaTypes)	\
    ( (This)->lpVtbl -> get_MediaCapabilities(This,plMediaTypes) ) 

#define IRTCClient2_CreateSession(This,enType,bstrLocalPhoneURI,pProfile,lFlags,ppSession)	\
    ( (This)->lpVtbl -> CreateSession(This,enType,bstrLocalPhoneURI,pProfile,lFlags,ppSession) ) 

#define IRTCClient2_put_ListenForIncomingSessions(This,enListen)	\
    ( (This)->lpVtbl -> put_ListenForIncomingSessions(This,enListen) ) 

#define IRTCClient2_get_ListenForIncomingSessions(This,penListen)	\
    ( (This)->lpVtbl -> get_ListenForIncomingSessions(This,penListen) ) 

#define IRTCClient2_get_NetworkAddresses(This,fTCP,fExternal,pvAddresses)	\
    ( (This)->lpVtbl -> get_NetworkAddresses(This,fTCP,fExternal,pvAddresses) ) 

#define IRTCClient2_put_Volume(This,enDevice,lVolume)	\
    ( (This)->lpVtbl -> put_Volume(This,enDevice,lVolume) ) 

#define IRTCClient2_get_Volume(This,enDevice,plVolume)	\
    ( (This)->lpVtbl -> get_Volume(This,enDevice,plVolume) ) 

#define IRTCClient2_put_AudioMuted(This,enDevice,fMuted)	\
    ( (This)->lpVtbl -> put_AudioMuted(This,enDevice,fMuted) ) 

#define IRTCClient2_get_AudioMuted(This,enDevice,pfMuted)	\
    ( (This)->lpVtbl -> get_AudioMuted(This,enDevice,pfMuted) ) 

#define IRTCClient2_get_IVideoWindow(This,enDevice,ppIVideoWindow)	\
    ( (This)->lpVtbl -> get_IVideoWindow(This,enDevice,ppIVideoWindow) ) 

#define IRTCClient2_put_PreferredAudioDevice(This,enDevice,bstrDeviceName)	\
    ( (This)->lpVtbl -> put_PreferredAudioDevice(This,enDevice,bstrDeviceName) ) 

#define IRTCClient2_get_PreferredAudioDevice(This,enDevice,pbstrDeviceName)	\
    ( (This)->lpVtbl -> get_PreferredAudioDevice(This,enDevice,pbstrDeviceName) ) 

#define IRTCClient2_put_PreferredVolume(This,enDevice,lVolume)	\
    ( (This)->lpVtbl -> put_PreferredVolume(This,enDevice,lVolume) ) 

#define IRTCClient2_get_PreferredVolume(This,enDevice,plVolume)	\
    ( (This)->lpVtbl -> get_PreferredVolume(This,enDevice,plVolume) ) 

#define IRTCClient2_put_PreferredAEC(This,bEnable)	\
    ( (This)->lpVtbl -> put_PreferredAEC(This,bEnable) ) 

#define IRTCClient2_get_PreferredAEC(This,pbEnabled)	\
    ( (This)->lpVtbl -> get_PreferredAEC(This,pbEnabled) ) 

#define IRTCClient2_put_PreferredVideoDevice(This,bstrDeviceName)	\
    ( (This)->lpVtbl -> put_PreferredVideoDevice(This,bstrDeviceName) ) 

#define IRTCClient2_get_PreferredVideoDevice(This,pbstrDeviceName)	\
    ( (This)->lpVtbl -> get_PreferredVideoDevice(This,pbstrDeviceName) ) 

#define IRTCClient2_get_ActiveMedia(This,plMediaType)	\
    ( (This)->lpVtbl -> get_ActiveMedia(This,plMediaType) ) 

#define IRTCClient2_put_MaxBitrate(This,lMaxBitrate)	\
    ( (This)->lpVtbl -> put_MaxBitrate(This,lMaxBitrate) ) 

#define IRTCClient2_get_MaxBitrate(This,plMaxBitrate)	\
    ( (This)->lpVtbl -> get_MaxBitrate(This,plMaxBitrate) ) 

#define IRTCClient2_put_TemporalSpatialTradeOff(This,lValue)	\
    ( (This)->lpVtbl -> put_TemporalSpatialTradeOff(This,lValue) ) 

#define IRTCClient2_get_TemporalSpatialTradeOff(This,plValue)	\
    ( (This)->lpVtbl -> get_TemporalSpatialTradeOff(This,plValue) ) 

#define IRTCClient2_get_NetworkQuality(This,plNetworkQuality)	\
    ( (This)->lpVtbl -> get_NetworkQuality(This,plNetworkQuality) ) 

#define IRTCClient2_StartT120Applet(This,enApplet)	\
    ( (This)->lpVtbl -> StartT120Applet(This,enApplet) ) 

#define IRTCClient2_StopT120Applets(This)	\
    ( (This)->lpVtbl -> StopT120Applets(This) ) 

#define IRTCClient2_get_IsT120AppletRunning(This,enApplet,pfRunning)	\
    ( (This)->lpVtbl -> get_IsT120AppletRunning(This,enApplet,pfRunning) ) 

#define IRTCClient2_get_LocalUserURI(This,pbstrUserURI)	\
    ( (This)->lpVtbl -> get_LocalUserURI(This,pbstrUserURI) ) 

#define IRTCClient2_put_LocalUserURI(This,bstrUserURI)	\
    ( (This)->lpVtbl -> put_LocalUserURI(This,bstrUserURI) ) 

#define IRTCClient2_get_LocalUserName(This,pbstrUserName)	\
    ( (This)->lpVtbl -> get_LocalUserName(This,pbstrUserName) ) 

#define IRTCClient2_put_LocalUserName(This,bstrUserName)	\
    ( (This)->lpVtbl -> put_LocalUserName(This,bstrUserName) ) 

#define IRTCClient2_PlayRing(This,enType,bPlay)	\
    ( (This)->lpVtbl -> PlayRing(This,enType,bPlay) ) 

#define IRTCClient2_SendDTMF(This,enDTMF)	\
    ( (This)->lpVtbl -> SendDTMF(This,enDTMF) ) 

#define IRTCClient2_InvokeTuningWizard(This,hwndParent)	\
    ( (This)->lpVtbl -> InvokeTuningWizard(This,hwndParent) ) 

#define IRTCClient2_get_IsTuned(This,pfTuned)	\
    ( (This)->lpVtbl -> get_IsTuned(This,pfTuned) ) 


#define IRTCClient2_put_AnswerMode(This,enType,enMode)	\
    ( (This)->lpVtbl -> put_AnswerMode(This,enType,enMode) ) 

#define IRTCClient2_get_AnswerMode(This,enType,penMode)	\
    ( (This)->lpVtbl -> get_AnswerMode(This,enType,penMode) ) 

#define IRTCClient2_InvokeTuningWizardEx(This,hwndParent,fAllowAudio,fAllowVideo)	\
    ( (This)->lpVtbl -> InvokeTuningWizardEx(This,hwndParent,fAllowAudio,fAllowVideo) ) 

#define IRTCClient2_get_Version(This,plVersion)	\
    ( (This)->lpVtbl -> get_Version(This,plVersion) ) 

#define IRTCClient2_put_ClientName(This,bstrClientName)	\
    ( (This)->lpVtbl -> put_ClientName(This,bstrClientName) ) 

#define IRTCClient2_put_ClientCurVer(This,bstrClientCurVer)	\
    ( (This)->lpVtbl -> put_ClientCurVer(This,bstrClientCurVer) ) 

#define IRTCClient2_InitializeEx(This,lFlags)	\
    ( (This)->lpVtbl -> InitializeEx(This,lFlags) ) 

#define IRTCClient2_CreateSessionWithDescription(This,bstrContentType,bstrSessionDescription,pProfile,lFlags,ppSession2)	\
    ( (This)->lpVtbl -> CreateSessionWithDescription(This,bstrContentType,bstrSessionDescription,pProfile,lFlags,ppSession2) ) 

#define IRTCClient2_SetSessionDescriptionManager(This,pSessionDescriptionManager)	\
    ( (This)->lpVtbl -> SetSessionDescriptionManager(This,pSessionDescriptionManager) ) 

#define IRTCClient2_put_PreferredSecurityLevel(This,enSecurityType,enSecurityLevel)	\
    ( (This)->lpVtbl -> put_PreferredSecurityLevel(This,enSecurityType,enSecurityLevel) ) 

#define IRTCClient2_get_PreferredSecurityLevel(This,enSecurityType,penSecurityLevel)	\
    ( (This)->lpVtbl -> get_PreferredSecurityLevel(This,enSecurityType,penSecurityLevel) ) 

#define IRTCClient2_put_AllowedPorts(This,lTransport,enListenMode)	\
    ( (This)->lpVtbl -> put_AllowedPorts(This,lTransport,enListenMode) ) 

#define IRTCClient2_get_AllowedPorts(This,lTransport,penListenMode)	\
    ( (This)->lpVtbl -> get_AllowedPorts(This,lTransport,penListenMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCClient2_INTERFACE_DEFINED__ */


#ifndef __IRTCClientPresence_INTERFACE_DEFINED__
#define __IRTCClientPresence_INTERFACE_DEFINED__

/* interface IRTCClientPresence */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientPresence;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11c3cbcc-0744-42d1-968a-51aa1bb274c6")
    IRTCClientPresence : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnablePresence( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fUseStorage,
            /* [annotation][in] */ 
            _In_  VARIANT varStorage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Export( 
            /* [annotation][in] */ 
            _In_  VARIANT varStorage) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Import( 
            /* [annotation][in] */ 
            _In_  VARIANT varStorage,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fReplaceAll) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateBuddies( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumBuddies **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Buddies( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Buddy( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy **ppBuddy) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddBuddy( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy **ppBuddy) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveBuddy( 
            /* [annotation][in] */ 
            _In_  IRTCBuddy *pBuddy) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateWatchers( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumWatchers **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Watchers( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Watcher( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher **ppWatcher) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddWatcher( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fBlocked,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher **ppWatcher) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveWatcher( 
            /* [annotation][in] */ 
            _In_  IRTCWatcher *pWatcher) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetLocalPresenceInfo( 
            /* [annotation][in] */ 
            _In_  RTC_PRESENCE_STATUS enStatus,
            /* [annotation][in] */ 
            _In_  BSTR bstrNotes) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_OfferWatcherMode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_OFFER_WATCHER_MODE *penMode) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_OfferWatcherMode( 
            /* [annotation][in] */ 
            _In_  RTC_OFFER_WATCHER_MODE enMode) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PrivacyMode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PRIVACY_MODE *penMode) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PrivacyMode( 
            /* [annotation][in] */ 
            _In_  RTC_PRIVACY_MODE enMode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCClientPresenceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCClientPresence * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCClientPresence * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnablePresence )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fUseStorage,
            /* [annotation][in] */ 
            _In_  VARIANT varStorage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Export )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  VARIANT varStorage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  VARIANT varStorage,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fReplaceAll);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateBuddies )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumBuddies **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddies )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddy )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy **ppBuddy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddBuddy )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy **ppBuddy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveBuddy )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  IRTCBuddy *pBuddy);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateWatchers )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumWatchers **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watchers )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watcher )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher **ppWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddWatcher )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fBlocked,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher **ppWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveWatcher )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  IRTCWatcher *pWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetLocalPresenceInfo )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  RTC_PRESENCE_STATUS enStatus,
            /* [annotation][in] */ 
            _In_  BSTR bstrNotes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OfferWatcherMode )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_OFFER_WATCHER_MODE *penMode);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OfferWatcherMode )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  RTC_OFFER_WATCHER_MODE enMode);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PrivacyMode )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PRIVACY_MODE *penMode);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PrivacyMode )( 
            __RPC__in IRTCClientPresence * This,
            /* [annotation][in] */ 
            _In_  RTC_PRIVACY_MODE enMode);
        
        END_INTERFACE
    } IRTCClientPresenceVtbl;

    interface IRTCClientPresence
    {
        CONST_VTBL struct IRTCClientPresenceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientPresence_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCClientPresence_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCClientPresence_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCClientPresence_EnablePresence(This,fUseStorage,varStorage)	\
    ( (This)->lpVtbl -> EnablePresence(This,fUseStorage,varStorage) ) 

#define IRTCClientPresence_Export(This,varStorage)	\
    ( (This)->lpVtbl -> Export(This,varStorage) ) 

#define IRTCClientPresence_Import(This,varStorage,fReplaceAll)	\
    ( (This)->lpVtbl -> Import(This,varStorage,fReplaceAll) ) 

#define IRTCClientPresence_EnumerateBuddies(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateBuddies(This,ppEnum) ) 

#define IRTCClientPresence_get_Buddies(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Buddies(This,ppCollection) ) 

#define IRTCClientPresence_get_Buddy(This,bstrPresentityURI,ppBuddy)	\
    ( (This)->lpVtbl -> get_Buddy(This,bstrPresentityURI,ppBuddy) ) 

#define IRTCClientPresence_AddBuddy(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,pProfile,lFlags,ppBuddy)	\
    ( (This)->lpVtbl -> AddBuddy(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,pProfile,lFlags,ppBuddy) ) 

#define IRTCClientPresence_RemoveBuddy(This,pBuddy)	\
    ( (This)->lpVtbl -> RemoveBuddy(This,pBuddy) ) 

#define IRTCClientPresence_EnumerateWatchers(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateWatchers(This,ppEnum) ) 

#define IRTCClientPresence_get_Watchers(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Watchers(This,ppCollection) ) 

#define IRTCClientPresence_get_Watcher(This,bstrPresentityURI,ppWatcher)	\
    ( (This)->lpVtbl -> get_Watcher(This,bstrPresentityURI,ppWatcher) ) 

#define IRTCClientPresence_AddWatcher(This,bstrPresentityURI,bstrUserName,bstrData,fBlocked,fPersistent,ppWatcher)	\
    ( (This)->lpVtbl -> AddWatcher(This,bstrPresentityURI,bstrUserName,bstrData,fBlocked,fPersistent,ppWatcher) ) 

#define IRTCClientPresence_RemoveWatcher(This,pWatcher)	\
    ( (This)->lpVtbl -> RemoveWatcher(This,pWatcher) ) 

#define IRTCClientPresence_SetLocalPresenceInfo(This,enStatus,bstrNotes)	\
    ( (This)->lpVtbl -> SetLocalPresenceInfo(This,enStatus,bstrNotes) ) 

#define IRTCClientPresence_get_OfferWatcherMode(This,penMode)	\
    ( (This)->lpVtbl -> get_OfferWatcherMode(This,penMode) ) 

#define IRTCClientPresence_put_OfferWatcherMode(This,enMode)	\
    ( (This)->lpVtbl -> put_OfferWatcherMode(This,enMode) ) 

#define IRTCClientPresence_get_PrivacyMode(This,penMode)	\
    ( (This)->lpVtbl -> get_PrivacyMode(This,penMode) ) 

#define IRTCClientPresence_put_PrivacyMode(This,enMode)	\
    ( (This)->lpVtbl -> put_PrivacyMode(This,enMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCClientPresence_INTERFACE_DEFINED__ */


#ifndef __IRTCClientPresence2_INTERFACE_DEFINED__
#define __IRTCClientPresence2_INTERFACE_DEFINED__

/* interface IRTCClientPresence2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientPresence2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD1809E8-62F7-4783-909A-29C9D2CB1D34")
    IRTCClientPresence2 : public IRTCClientPresence
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnablePresenceEx( 
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  VARIANT varStorage,
            /* [annotation][in] */ 
            _In_  long lFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DisablePresence( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddGroup( 
            /* [annotation][in] */ 
            _In_  BSTR bstrGroupName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddyGroup **ppGroup) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveGroup( 
            /* [annotation][in] */ 
            _In_  IRTCBuddyGroup *pGroup) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateGroups( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumGroups **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Groups( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Group( 
            /* [annotation][in] */ 
            _In_  BSTR bstrGroupName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddyGroup **ppGroup) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddWatcherEx( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  RTC_WATCHER_STATE enState,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent,
            /* [annotation][in] */ 
            _In_  RTC_ACE_SCOPE enScope,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher2 **ppWatcher) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_WatcherEx( 
            /* [annotation][in] */ 
            _In_  RTC_WATCHER_MATCH_MODE enMode,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher2 **ppWatcher) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PresenceProperty( 
            /* [annotation][in] */ 
            _In_  RTC_PRESENCE_PROPERTY enProperty,
            /* [annotation][in] */ 
            _In_  BSTR bstrProperty) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PresenceProperty( 
            /* [annotation][in] */ 
            _In_  RTC_PRESENCE_PROPERTY enProperty,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPresenceData( 
            /* [annotation][in] */ 
            _In_  BSTR bstrNamespace,
            /* [annotation][in] */ 
            _In_  BSTR bstrData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPresenceData( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrNamespace,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLocalPresenceInfo( 
            /* [annotation][out] */ 
            _Out_  RTC_PRESENCE_STATUS *penStatus,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrNotes) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddBuddyEx( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent,
            /* [annotation][in] */ 
            _In_  RTC_BUDDY_SUBSCRIPTION_TYPE enSubscriptionType,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy2 **ppBuddy) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCClientPresence2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCClientPresence2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCClientPresence2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnablePresence )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fUseStorage,
            /* [annotation][in] */ 
            _In_  VARIANT varStorage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Export )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT varStorage);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT varStorage,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fReplaceAll);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateBuddies )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumBuddies **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddies )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddy )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy **ppBuddy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddBuddy )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy **ppBuddy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveBuddy )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  IRTCBuddy *pBuddy);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateWatchers )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumWatchers **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watchers )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watcher )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher **ppWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddWatcher )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fBlocked,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher **ppWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveWatcher )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  IRTCWatcher *pWatcher);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetLocalPresenceInfo )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  RTC_PRESENCE_STATUS enStatus,
            /* [annotation][in] */ 
            _In_  BSTR bstrNotes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OfferWatcherMode )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_OFFER_WATCHER_MODE *penMode);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OfferWatcherMode )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  RTC_OFFER_WATCHER_MODE enMode);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PrivacyMode )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PRIVACY_MODE *penMode);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PrivacyMode )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  RTC_PRIVACY_MODE enMode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnablePresenceEx )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  VARIANT varStorage,
            /* [annotation][in] */ 
            _In_  long lFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DisablePresence )( 
            __RPC__in IRTCClientPresence2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddGroup )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrGroupName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddyGroup **ppGroup);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveGroup )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  IRTCBuddyGroup *pGroup);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateGroups )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumGroups **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Groups )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Group )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrGroupName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddyGroup **ppGroup);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddWatcherEx )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  RTC_WATCHER_STATE enState,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent,
            /* [annotation][in] */ 
            _In_  RTC_ACE_SCOPE enScope,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher2 **ppWatcher);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WatcherEx )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  RTC_WATCHER_MATCH_MODE enMode,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher2 **ppWatcher);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresenceProperty )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  RTC_PRESENCE_PROPERTY enProperty,
            /* [annotation][in] */ 
            _In_  BSTR bstrProperty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresenceProperty )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  RTC_PRESENCE_PROPERTY enProperty,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPresenceData )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrNamespace,
            /* [annotation][in] */ 
            _In_  BSTR bstrData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPresenceData )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrNamespace,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLocalPresenceInfo )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][out] */ 
            _Out_  RTC_PRESENCE_STATUS *penStatus,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrNotes);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddBuddyEx )( 
            __RPC__in IRTCClientPresence2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserName,
            /* [annotation][in] */ 
            _In_  BSTR bstrData,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent,
            /* [annotation][in] */ 
            _In_  RTC_BUDDY_SUBSCRIPTION_TYPE enSubscriptionType,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy2 **ppBuddy);
        
        END_INTERFACE
    } IRTCClientPresence2Vtbl;

    interface IRTCClientPresence2
    {
        CONST_VTBL struct IRTCClientPresence2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientPresence2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCClientPresence2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCClientPresence2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCClientPresence2_EnablePresence(This,fUseStorage,varStorage)	\
    ( (This)->lpVtbl -> EnablePresence(This,fUseStorage,varStorage) ) 

#define IRTCClientPresence2_Export(This,varStorage)	\
    ( (This)->lpVtbl -> Export(This,varStorage) ) 

#define IRTCClientPresence2_Import(This,varStorage,fReplaceAll)	\
    ( (This)->lpVtbl -> Import(This,varStorage,fReplaceAll) ) 

#define IRTCClientPresence2_EnumerateBuddies(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateBuddies(This,ppEnum) ) 

#define IRTCClientPresence2_get_Buddies(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Buddies(This,ppCollection) ) 

#define IRTCClientPresence2_get_Buddy(This,bstrPresentityURI,ppBuddy)	\
    ( (This)->lpVtbl -> get_Buddy(This,bstrPresentityURI,ppBuddy) ) 

#define IRTCClientPresence2_AddBuddy(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,pProfile,lFlags,ppBuddy)	\
    ( (This)->lpVtbl -> AddBuddy(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,pProfile,lFlags,ppBuddy) ) 

#define IRTCClientPresence2_RemoveBuddy(This,pBuddy)	\
    ( (This)->lpVtbl -> RemoveBuddy(This,pBuddy) ) 

#define IRTCClientPresence2_EnumerateWatchers(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateWatchers(This,ppEnum) ) 

#define IRTCClientPresence2_get_Watchers(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Watchers(This,ppCollection) ) 

#define IRTCClientPresence2_get_Watcher(This,bstrPresentityURI,ppWatcher)	\
    ( (This)->lpVtbl -> get_Watcher(This,bstrPresentityURI,ppWatcher) ) 

#define IRTCClientPresence2_AddWatcher(This,bstrPresentityURI,bstrUserName,bstrData,fBlocked,fPersistent,ppWatcher)	\
    ( (This)->lpVtbl -> AddWatcher(This,bstrPresentityURI,bstrUserName,bstrData,fBlocked,fPersistent,ppWatcher) ) 

#define IRTCClientPresence2_RemoveWatcher(This,pWatcher)	\
    ( (This)->lpVtbl -> RemoveWatcher(This,pWatcher) ) 

#define IRTCClientPresence2_SetLocalPresenceInfo(This,enStatus,bstrNotes)	\
    ( (This)->lpVtbl -> SetLocalPresenceInfo(This,enStatus,bstrNotes) ) 

#define IRTCClientPresence2_get_OfferWatcherMode(This,penMode)	\
    ( (This)->lpVtbl -> get_OfferWatcherMode(This,penMode) ) 

#define IRTCClientPresence2_put_OfferWatcherMode(This,enMode)	\
    ( (This)->lpVtbl -> put_OfferWatcherMode(This,enMode) ) 

#define IRTCClientPresence2_get_PrivacyMode(This,penMode)	\
    ( (This)->lpVtbl -> get_PrivacyMode(This,penMode) ) 

#define IRTCClientPresence2_put_PrivacyMode(This,enMode)	\
    ( (This)->lpVtbl -> put_PrivacyMode(This,enMode) ) 


#define IRTCClientPresence2_EnablePresenceEx(This,pProfile,varStorage,lFlags)	\
    ( (This)->lpVtbl -> EnablePresenceEx(This,pProfile,varStorage,lFlags) ) 

#define IRTCClientPresence2_DisablePresence(This)	\
    ( (This)->lpVtbl -> DisablePresence(This) ) 

#define IRTCClientPresence2_AddGroup(This,bstrGroupName,bstrData,pProfile,lFlags,ppGroup)	\
    ( (This)->lpVtbl -> AddGroup(This,bstrGroupName,bstrData,pProfile,lFlags,ppGroup) ) 

#define IRTCClientPresence2_RemoveGroup(This,pGroup)	\
    ( (This)->lpVtbl -> RemoveGroup(This,pGroup) ) 

#define IRTCClientPresence2_EnumerateGroups(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateGroups(This,ppEnum) ) 

#define IRTCClientPresence2_get_Groups(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Groups(This,ppCollection) ) 

#define IRTCClientPresence2_get_Group(This,bstrGroupName,ppGroup)	\
    ( (This)->lpVtbl -> get_Group(This,bstrGroupName,ppGroup) ) 

#define IRTCClientPresence2_AddWatcherEx(This,bstrPresentityURI,bstrUserName,bstrData,enState,fPersistent,enScope,pProfile,lFlags,ppWatcher)	\
    ( (This)->lpVtbl -> AddWatcherEx(This,bstrPresentityURI,bstrUserName,bstrData,enState,fPersistent,enScope,pProfile,lFlags,ppWatcher) ) 

#define IRTCClientPresence2_get_WatcherEx(This,enMode,bstrPresentityURI,ppWatcher)	\
    ( (This)->lpVtbl -> get_WatcherEx(This,enMode,bstrPresentityURI,ppWatcher) ) 

#define IRTCClientPresence2_put_PresenceProperty(This,enProperty,bstrProperty)	\
    ( (This)->lpVtbl -> put_PresenceProperty(This,enProperty,bstrProperty) ) 

#define IRTCClientPresence2_get_PresenceProperty(This,enProperty,pbstrProperty)	\
    ( (This)->lpVtbl -> get_PresenceProperty(This,enProperty,pbstrProperty) ) 

#define IRTCClientPresence2_SetPresenceData(This,bstrNamespace,bstrData)	\
    ( (This)->lpVtbl -> SetPresenceData(This,bstrNamespace,bstrData) ) 

#define IRTCClientPresence2_GetPresenceData(This,pbstrNamespace,pbstrData)	\
    ( (This)->lpVtbl -> GetPresenceData(This,pbstrNamespace,pbstrData) ) 

#define IRTCClientPresence2_GetLocalPresenceInfo(This,penStatus,pbstrNotes)	\
    ( (This)->lpVtbl -> GetLocalPresenceInfo(This,penStatus,pbstrNotes) ) 

#define IRTCClientPresence2_AddBuddyEx(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,enSubscriptionType,pProfile,lFlags,ppBuddy)	\
    ( (This)->lpVtbl -> AddBuddyEx(This,bstrPresentityURI,bstrUserName,bstrData,fPersistent,enSubscriptionType,pProfile,lFlags,ppBuddy) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCClientPresence2_INTERFACE_DEFINED__ */


#ifndef __IRTCClientProvisioning_INTERFACE_DEFINED__
#define __IRTCClientProvisioning_INTERFACE_DEFINED__

/* interface IRTCClientProvisioning */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientProvisioning;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B9F5CF06-65B9-4a80-A0E6-73CAE3EF3822")
    IRTCClientProvisioning : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateProfile( 
            /* [annotation][in] */ 
            _In_  BSTR bstrProfileXML,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile **ppProfile) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnableProfile( 
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lRegisterFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DisableProfile( 
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateProfiles( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumProfiles **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Profiles( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProfile( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserAccount,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrServer,
            /* [annotation][in] */ 
            _In_  long lTransport,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SessionCapabilities( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plSupportedSessions) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCClientProvisioningVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCClientProvisioning * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCClientProvisioning * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCClientProvisioning * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateProfile )( 
            __RPC__in IRTCClientProvisioning * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrProfileXML,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile **ppProfile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnableProfile )( 
            __RPC__in IRTCClientProvisioning * This,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lRegisterFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DisableProfile )( 
            __RPC__in IRTCClientProvisioning * This,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateProfiles )( 
            __RPC__in IRTCClientProvisioning * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumProfiles **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profiles )( 
            __RPC__in IRTCClientProvisioning * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProfile )( 
            __RPC__in IRTCClientProvisioning * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserAccount,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrServer,
            /* [annotation][in] */ 
            _In_  long lTransport,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SessionCapabilities )( 
            __RPC__in IRTCClientProvisioning * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plSupportedSessions);
        
        END_INTERFACE
    } IRTCClientProvisioningVtbl;

    interface IRTCClientProvisioning
    {
        CONST_VTBL struct IRTCClientProvisioningVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientProvisioning_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCClientProvisioning_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCClientProvisioning_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCClientProvisioning_CreateProfile(This,bstrProfileXML,ppProfile)	\
    ( (This)->lpVtbl -> CreateProfile(This,bstrProfileXML,ppProfile) ) 

#define IRTCClientProvisioning_EnableProfile(This,pProfile,lRegisterFlags)	\
    ( (This)->lpVtbl -> EnableProfile(This,pProfile,lRegisterFlags) ) 

#define IRTCClientProvisioning_DisableProfile(This,pProfile)	\
    ( (This)->lpVtbl -> DisableProfile(This,pProfile) ) 

#define IRTCClientProvisioning_EnumerateProfiles(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateProfiles(This,ppEnum) ) 

#define IRTCClientProvisioning_get_Profiles(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Profiles(This,ppCollection) ) 

#define IRTCClientProvisioning_GetProfile(This,bstrUserAccount,bstrUserPassword,bstrUserURI,bstrServer,lTransport,lCookie)	\
    ( (This)->lpVtbl -> GetProfile(This,bstrUserAccount,bstrUserPassword,bstrUserURI,bstrServer,lTransport,lCookie) ) 

#define IRTCClientProvisioning_get_SessionCapabilities(This,plSupportedSessions)	\
    ( (This)->lpVtbl -> get_SessionCapabilities(This,plSupportedSessions) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCClientProvisioning_INTERFACE_DEFINED__ */


#ifndef __IRTCClientProvisioning2_INTERFACE_DEFINED__
#define __IRTCClientProvisioning2_INTERFACE_DEFINED__

/* interface IRTCClientProvisioning2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientProvisioning2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A70909B5-F40E-4587-BB75-E6BC0845023E")
    IRTCClientProvisioning2 : public IRTCClientProvisioning
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnableProfileEx( 
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lRegisterFlags,
            /* [annotation][in] */ 
            _In_  long lRoamingFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCClientProvisioning2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCClientProvisioning2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCClientProvisioning2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCClientProvisioning2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateProfile )( 
            __RPC__in IRTCClientProvisioning2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrProfileXML,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile **ppProfile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnableProfile )( 
            __RPC__in IRTCClientProvisioning2 * This,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lRegisterFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DisableProfile )( 
            __RPC__in IRTCClientProvisioning2 * This,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateProfiles )( 
            __RPC__in IRTCClientProvisioning2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumProfiles **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profiles )( 
            __RPC__in IRTCClientProvisioning2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProfile )( 
            __RPC__in IRTCClientProvisioning2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserAccount,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserPassword,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrServer,
            /* [annotation][in] */ 
            _In_  long lTransport,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SessionCapabilities )( 
            __RPC__in IRTCClientProvisioning2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plSupportedSessions);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnableProfileEx )( 
            __RPC__in IRTCClientProvisioning2 * This,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lRegisterFlags,
            /* [annotation][in] */ 
            _In_  long lRoamingFlags);
        
        END_INTERFACE
    } IRTCClientProvisioning2Vtbl;

    interface IRTCClientProvisioning2
    {
        CONST_VTBL struct IRTCClientProvisioning2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientProvisioning2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCClientProvisioning2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCClientProvisioning2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCClientProvisioning2_CreateProfile(This,bstrProfileXML,ppProfile)	\
    ( (This)->lpVtbl -> CreateProfile(This,bstrProfileXML,ppProfile) ) 

#define IRTCClientProvisioning2_EnableProfile(This,pProfile,lRegisterFlags)	\
    ( (This)->lpVtbl -> EnableProfile(This,pProfile,lRegisterFlags) ) 

#define IRTCClientProvisioning2_DisableProfile(This,pProfile)	\
    ( (This)->lpVtbl -> DisableProfile(This,pProfile) ) 

#define IRTCClientProvisioning2_EnumerateProfiles(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateProfiles(This,ppEnum) ) 

#define IRTCClientProvisioning2_get_Profiles(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Profiles(This,ppCollection) ) 

#define IRTCClientProvisioning2_GetProfile(This,bstrUserAccount,bstrUserPassword,bstrUserURI,bstrServer,lTransport,lCookie)	\
    ( (This)->lpVtbl -> GetProfile(This,bstrUserAccount,bstrUserPassword,bstrUserURI,bstrServer,lTransport,lCookie) ) 

#define IRTCClientProvisioning2_get_SessionCapabilities(This,plSupportedSessions)	\
    ( (This)->lpVtbl -> get_SessionCapabilities(This,plSupportedSessions) ) 


#define IRTCClientProvisioning2_EnableProfileEx(This,pProfile,lRegisterFlags,lRoamingFlags)	\
    ( (This)->lpVtbl -> EnableProfileEx(This,pProfile,lRegisterFlags,lRoamingFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCClientProvisioning2_INTERFACE_DEFINED__ */


#ifndef __IRTCProfile_INTERFACE_DEFINED__
#define __IRTCProfile_INTERFACE_DEFINED__

/* interface IRTCProfile */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCProfile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d07eca9e-4062-4dd4-9e7d-722a49ba7303")
    IRTCProfile : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrKey) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_XML( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrXML) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProviderName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProviderURI( 
            /* [annotation][in] */ 
            _In_  RTC_PROVIDER_URI enURI,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProviderData( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientBanner( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfBanner) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientMinVer( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrMinVer) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientCurVer( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrCurVer) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientUpdateURI( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUpdateURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClientData( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UserURI( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UserName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UserAccount( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserAccount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCredentials( 
            /* [annotation][in] */ 
            _In_  BSTR bstrUserURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserAccount,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SessionCapabilities( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plSupportedSessions) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_REGISTRATION_STATE *penState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCProfileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCProfile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCProfile * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrKey);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XML )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrXML);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderName )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderURI )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][in] */ 
            _In_  RTC_PROVIDER_URI enURI,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderData )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientName )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientBanner )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfBanner);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientMinVer )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrMinVer);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientCurVer )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrCurVer);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientUpdateURI )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUpdateURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientData )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserURI )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserName )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserAccount )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserAccount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCredentials )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserAccount,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SessionCapabilities )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plSupportedSessions);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCProfile * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_REGISTRATION_STATE *penState);
        
        END_INTERFACE
    } IRTCProfileVtbl;

    interface IRTCProfile
    {
        CONST_VTBL struct IRTCProfileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCProfile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCProfile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCProfile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCProfile_get_Key(This,pbstrKey)	\
    ( (This)->lpVtbl -> get_Key(This,pbstrKey) ) 

#define IRTCProfile_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IRTCProfile_get_XML(This,pbstrXML)	\
    ( (This)->lpVtbl -> get_XML(This,pbstrXML) ) 

#define IRTCProfile_get_ProviderName(This,pbstrName)	\
    ( (This)->lpVtbl -> get_ProviderName(This,pbstrName) ) 

#define IRTCProfile_get_ProviderURI(This,enURI,pbstrURI)	\
    ( (This)->lpVtbl -> get_ProviderURI(This,enURI,pbstrURI) ) 

#define IRTCProfile_get_ProviderData(This,pbstrData)	\
    ( (This)->lpVtbl -> get_ProviderData(This,pbstrData) ) 

#define IRTCProfile_get_ClientName(This,pbstrName)	\
    ( (This)->lpVtbl -> get_ClientName(This,pbstrName) ) 

#define IRTCProfile_get_ClientBanner(This,pfBanner)	\
    ( (This)->lpVtbl -> get_ClientBanner(This,pfBanner) ) 

#define IRTCProfile_get_ClientMinVer(This,pbstrMinVer)	\
    ( (This)->lpVtbl -> get_ClientMinVer(This,pbstrMinVer) ) 

#define IRTCProfile_get_ClientCurVer(This,pbstrCurVer)	\
    ( (This)->lpVtbl -> get_ClientCurVer(This,pbstrCurVer) ) 

#define IRTCProfile_get_ClientUpdateURI(This,pbstrUpdateURI)	\
    ( (This)->lpVtbl -> get_ClientUpdateURI(This,pbstrUpdateURI) ) 

#define IRTCProfile_get_ClientData(This,pbstrData)	\
    ( (This)->lpVtbl -> get_ClientData(This,pbstrData) ) 

#define IRTCProfile_get_UserURI(This,pbstrUserURI)	\
    ( (This)->lpVtbl -> get_UserURI(This,pbstrUserURI) ) 

#define IRTCProfile_get_UserName(This,pbstrUserName)	\
    ( (This)->lpVtbl -> get_UserName(This,pbstrUserName) ) 

#define IRTCProfile_get_UserAccount(This,pbstrUserAccount)	\
    ( (This)->lpVtbl -> get_UserAccount(This,pbstrUserAccount) ) 

#define IRTCProfile_SetCredentials(This,bstrUserURI,bstrUserAccount,bstrPassword)	\
    ( (This)->lpVtbl -> SetCredentials(This,bstrUserURI,bstrUserAccount,bstrPassword) ) 

#define IRTCProfile_get_SessionCapabilities(This,plSupportedSessions)	\
    ( (This)->lpVtbl -> get_SessionCapabilities(This,plSupportedSessions) ) 

#define IRTCProfile_get_State(This,penState)	\
    ( (This)->lpVtbl -> get_State(This,penState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCProfile_INTERFACE_DEFINED__ */


#ifndef __IRTCProfile2_INTERFACE_DEFINED__
#define __IRTCProfile2_INTERFACE_DEFINED__

/* interface IRTCProfile2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCProfile2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4B81F84E-BDC7-4184-9154-3CB2DD7917FB")
    IRTCProfile2 : public IRTCProfile
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Realm( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrRealm) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Realm( 
            /* [annotation][in] */ 
            _In_  BSTR bstrRealm) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AllowedAuth( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plAllowedAuth) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AllowedAuth( 
            /* [annotation][in] */ 
            _In_  long lAllowedAuth) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCProfile2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCProfile2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCProfile2 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrKey);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XML )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrXML);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderName )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderURI )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][in] */ 
            _In_  RTC_PROVIDER_URI enURI,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderData )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientName )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientBanner )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfBanner);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientMinVer )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrMinVer);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientCurVer )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrCurVer);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientUpdateURI )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUpdateURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClientData )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserURI )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserName )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserAccount )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserAccount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCredentials )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrUserAccount,
            /* [annotation][in] */ 
            _In_  BSTR bstrPassword);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SessionCapabilities )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plSupportedSessions);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_REGISTRATION_STATE *penState);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Realm )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrRealm);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Realm )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrRealm);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowedAuth )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plAllowedAuth);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowedAuth )( 
            __RPC__in IRTCProfile2 * This,
            /* [annotation][in] */ 
            _In_  long lAllowedAuth);
        
        END_INTERFACE
    } IRTCProfile2Vtbl;

    interface IRTCProfile2
    {
        CONST_VTBL struct IRTCProfile2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCProfile2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCProfile2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCProfile2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCProfile2_get_Key(This,pbstrKey)	\
    ( (This)->lpVtbl -> get_Key(This,pbstrKey) ) 

#define IRTCProfile2_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IRTCProfile2_get_XML(This,pbstrXML)	\
    ( (This)->lpVtbl -> get_XML(This,pbstrXML) ) 

#define IRTCProfile2_get_ProviderName(This,pbstrName)	\
    ( (This)->lpVtbl -> get_ProviderName(This,pbstrName) ) 

#define IRTCProfile2_get_ProviderURI(This,enURI,pbstrURI)	\
    ( (This)->lpVtbl -> get_ProviderURI(This,enURI,pbstrURI) ) 

#define IRTCProfile2_get_ProviderData(This,pbstrData)	\
    ( (This)->lpVtbl -> get_ProviderData(This,pbstrData) ) 

#define IRTCProfile2_get_ClientName(This,pbstrName)	\
    ( (This)->lpVtbl -> get_ClientName(This,pbstrName) ) 

#define IRTCProfile2_get_ClientBanner(This,pfBanner)	\
    ( (This)->lpVtbl -> get_ClientBanner(This,pfBanner) ) 

#define IRTCProfile2_get_ClientMinVer(This,pbstrMinVer)	\
    ( (This)->lpVtbl -> get_ClientMinVer(This,pbstrMinVer) ) 

#define IRTCProfile2_get_ClientCurVer(This,pbstrCurVer)	\
    ( (This)->lpVtbl -> get_ClientCurVer(This,pbstrCurVer) ) 

#define IRTCProfile2_get_ClientUpdateURI(This,pbstrUpdateURI)	\
    ( (This)->lpVtbl -> get_ClientUpdateURI(This,pbstrUpdateURI) ) 

#define IRTCProfile2_get_ClientData(This,pbstrData)	\
    ( (This)->lpVtbl -> get_ClientData(This,pbstrData) ) 

#define IRTCProfile2_get_UserURI(This,pbstrUserURI)	\
    ( (This)->lpVtbl -> get_UserURI(This,pbstrUserURI) ) 

#define IRTCProfile2_get_UserName(This,pbstrUserName)	\
    ( (This)->lpVtbl -> get_UserName(This,pbstrUserName) ) 

#define IRTCProfile2_get_UserAccount(This,pbstrUserAccount)	\
    ( (This)->lpVtbl -> get_UserAccount(This,pbstrUserAccount) ) 

#define IRTCProfile2_SetCredentials(This,bstrUserURI,bstrUserAccount,bstrPassword)	\
    ( (This)->lpVtbl -> SetCredentials(This,bstrUserURI,bstrUserAccount,bstrPassword) ) 

#define IRTCProfile2_get_SessionCapabilities(This,plSupportedSessions)	\
    ( (This)->lpVtbl -> get_SessionCapabilities(This,plSupportedSessions) ) 

#define IRTCProfile2_get_State(This,penState)	\
    ( (This)->lpVtbl -> get_State(This,penState) ) 


#define IRTCProfile2_get_Realm(This,pbstrRealm)	\
    ( (This)->lpVtbl -> get_Realm(This,pbstrRealm) ) 

#define IRTCProfile2_put_Realm(This,bstrRealm)	\
    ( (This)->lpVtbl -> put_Realm(This,bstrRealm) ) 

#define IRTCProfile2_get_AllowedAuth(This,plAllowedAuth)	\
    ( (This)->lpVtbl -> get_AllowedAuth(This,plAllowedAuth) ) 

#define IRTCProfile2_put_AllowedAuth(This,lAllowedAuth)	\
    ( (This)->lpVtbl -> put_AllowedAuth(This,lAllowedAuth) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCProfile2_INTERFACE_DEFINED__ */


#ifndef __IRTCSession_INTERFACE_DEFINED__
#define __IRTCSession_INTERFACE_DEFINED__

/* interface IRTCSession */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("387c8086-99be-42fb-9973-7c0fc0ca9fa8")
    IRTCSession : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Client( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCClient **ppClient) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SESSION_STATE *penState) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SESSION_TYPE *penType) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile **ppProfile) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Participants( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Answer( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Terminate( 
            /* [annotation][in] */ 
            _In_  RTC_TERMINATE_REASON enReason) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Redirect( 
            /* [annotation][in] */ 
            _In_  RTC_SESSION_TYPE enType,
            /* [annotation][in] */ 
            _In_  BSTR bstrLocalPhoneURI,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddParticipant( 
            /* [annotation][in] */ 
            _In_  BSTR bstrAddress,
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCParticipant **ppParticipant) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveParticipant( 
            /* [annotation][in] */ 
            _In_  IRTCParticipant *pParticipant) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateParticipants( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumParticipants **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CanAddParticipants( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfCanAdd) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RedirectedUserURI( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RedirectedUserName( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE NextRedirectedUser( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendMessage( 
            /* [annotation][in] */ 
            _In_  BSTR bstrMessageHeader,
            /* [annotation][in] */ 
            _In_  BSTR bstrMessage,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendMessageStatus( 
            /* [annotation][in] */ 
            _In_  RTC_MESSAGING_USER_STATUS enUserStatus,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddStream( 
            /* [annotation][in] */ 
            _In_  long lMediaType,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveStream( 
            /* [annotation][in] */ 
            _In_  long lMediaType,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_EncryptionKey( 
            /* [annotation][in] */ 
            _In_  long lMediaType,
            /* [annotation][in] */ 
            _In_  BSTR EncryptionKey) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCSession * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCSession * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCSession * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Client )( 
            __RPC__in IRTCSession * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCClient **ppClient);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCSession * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SESSION_STATE *penState);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in IRTCSession * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SESSION_TYPE *penType);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            __RPC__in IRTCSession * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile **ppProfile);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participants )( 
            __RPC__in IRTCSession * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Answer )( 
            __RPC__in IRTCSession * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            __RPC__in IRTCSession * This,
            /* [annotation][in] */ 
            _In_  RTC_TERMINATE_REASON enReason);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Redirect )( 
            __RPC__in IRTCSession * This,
            /* [annotation][in] */ 
            _In_  RTC_SESSION_TYPE enType,
            /* [annotation][in] */ 
            _In_  BSTR bstrLocalPhoneURI,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddParticipant )( 
            __RPC__in IRTCSession * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrAddress,
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCParticipant **ppParticipant);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveParticipant )( 
            __RPC__in IRTCSession * This,
            /* [annotation][in] */ 
            _In_  IRTCParticipant *pParticipant);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateParticipants )( 
            __RPC__in IRTCSession * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumParticipants **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanAddParticipants )( 
            __RPC__in IRTCSession * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfCanAdd);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RedirectedUserURI )( 
            __RPC__in IRTCSession * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RedirectedUserName )( 
            __RPC__in IRTCSession * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *NextRedirectedUser )( 
            __RPC__in IRTCSession * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendMessage )( 
            __RPC__in IRTCSession * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrMessageHeader,
            /* [annotation][in] */ 
            _In_  BSTR bstrMessage,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendMessageStatus )( 
            __RPC__in IRTCSession * This,
            /* [annotation][in] */ 
            _In_  RTC_MESSAGING_USER_STATUS enUserStatus,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddStream )( 
            __RPC__in IRTCSession * This,
            /* [annotation][in] */ 
            _In_  long lMediaType,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveStream )( 
            __RPC__in IRTCSession * This,
            /* [annotation][in] */ 
            _In_  long lMediaType,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncryptionKey )( 
            __RPC__in IRTCSession * This,
            /* [annotation][in] */ 
            _In_  long lMediaType,
            /* [annotation][in] */ 
            _In_  BSTR EncryptionKey);
        
        END_INTERFACE
    } IRTCSessionVtbl;

    interface IRTCSession
    {
        CONST_VTBL struct IRTCSessionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSession_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCSession_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCSession_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCSession_get_Client(This,ppClient)	\
    ( (This)->lpVtbl -> get_Client(This,ppClient) ) 

#define IRTCSession_get_State(This,penState)	\
    ( (This)->lpVtbl -> get_State(This,penState) ) 

#define IRTCSession_get_Type(This,penType)	\
    ( (This)->lpVtbl -> get_Type(This,penType) ) 

#define IRTCSession_get_Profile(This,ppProfile)	\
    ( (This)->lpVtbl -> get_Profile(This,ppProfile) ) 

#define IRTCSession_get_Participants(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Participants(This,ppCollection) ) 

#define IRTCSession_Answer(This)	\
    ( (This)->lpVtbl -> Answer(This) ) 

#define IRTCSession_Terminate(This,enReason)	\
    ( (This)->lpVtbl -> Terminate(This,enReason) ) 

#define IRTCSession_Redirect(This,enType,bstrLocalPhoneURI,pProfile,lFlags)	\
    ( (This)->lpVtbl -> Redirect(This,enType,bstrLocalPhoneURI,pProfile,lFlags) ) 

#define IRTCSession_AddParticipant(This,bstrAddress,bstrName,ppParticipant)	\
    ( (This)->lpVtbl -> AddParticipant(This,bstrAddress,bstrName,ppParticipant) ) 

#define IRTCSession_RemoveParticipant(This,pParticipant)	\
    ( (This)->lpVtbl -> RemoveParticipant(This,pParticipant) ) 

#define IRTCSession_EnumerateParticipants(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateParticipants(This,ppEnum) ) 

#define IRTCSession_get_CanAddParticipants(This,pfCanAdd)	\
    ( (This)->lpVtbl -> get_CanAddParticipants(This,pfCanAdd) ) 

#define IRTCSession_get_RedirectedUserURI(This,pbstrUserURI)	\
    ( (This)->lpVtbl -> get_RedirectedUserURI(This,pbstrUserURI) ) 

#define IRTCSession_get_RedirectedUserName(This,pbstrUserName)	\
    ( (This)->lpVtbl -> get_RedirectedUserName(This,pbstrUserName) ) 

#define IRTCSession_NextRedirectedUser(This)	\
    ( (This)->lpVtbl -> NextRedirectedUser(This) ) 

#define IRTCSession_SendMessage(This,bstrMessageHeader,bstrMessage,lCookie)	\
    ( (This)->lpVtbl -> SendMessage(This,bstrMessageHeader,bstrMessage,lCookie) ) 

#define IRTCSession_SendMessageStatus(This,enUserStatus,lCookie)	\
    ( (This)->lpVtbl -> SendMessageStatus(This,enUserStatus,lCookie) ) 

#define IRTCSession_AddStream(This,lMediaType,lCookie)	\
    ( (This)->lpVtbl -> AddStream(This,lMediaType,lCookie) ) 

#define IRTCSession_RemoveStream(This,lMediaType,lCookie)	\
    ( (This)->lpVtbl -> RemoveStream(This,lMediaType,lCookie) ) 

#define IRTCSession_put_EncryptionKey(This,lMediaType,EncryptionKey)	\
    ( (This)->lpVtbl -> put_EncryptionKey(This,lMediaType,EncryptionKey) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCSession_INTERFACE_DEFINED__ */


#ifndef __IRTCSession2_INTERFACE_DEFINED__
#define __IRTCSession2_INTERFACE_DEFINED__

/* interface IRTCSession2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCSession2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17D7CDFC-B007-484c-99D2-86A8A820991D")
    IRTCSession2 : public IRTCSession
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendInfo( 
            /* [annotation][in] */ 
            _In_  BSTR bstrInfoHeader,
            /* [annotation][in] */ 
            _In_  BSTR bstrInfo,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreferredSecurityLevel( 
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_LEVEL enSecurityLevel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredSecurityLevel( 
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SECURITY_LEVEL *penSecurityLevel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsSecurityEnabled( 
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfSecurityEnabled) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AnswerWithSessionDescription( 
            /* [annotation][in] */ 
            _In_  BSTR bstrContentType,
            /* [annotation][in] */ 
            _In_  BSTR bstrSessionDescription) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReInviteWithSessionDescription( 
            /* [annotation][in] */ 
            _In_  BSTR bstrContentType,
            /* [annotation][in] */ 
            _In_  BSTR bstrSessionDescription,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCSession2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCSession2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCSession2 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Client )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCClient **ppClient);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SESSION_STATE *penState);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SESSION_TYPE *penType);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile **ppProfile);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participants )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Answer )( 
            __RPC__in IRTCSession2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  RTC_TERMINATE_REASON enReason);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Redirect )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  RTC_SESSION_TYPE enType,
            /* [annotation][in] */ 
            _In_  BSTR bstrLocalPhoneURI,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  long lFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddParticipant )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrAddress,
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCParticipant **ppParticipant);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveParticipant )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  IRTCParticipant *pParticipant);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateParticipants )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumParticipants **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanAddParticipants )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfCanAdd);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RedirectedUserURI )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RedirectedUserName )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *NextRedirectedUser )( 
            __RPC__in IRTCSession2 * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendMessage )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrMessageHeader,
            /* [annotation][in] */ 
            _In_  BSTR bstrMessage,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendMessageStatus )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  RTC_MESSAGING_USER_STATUS enUserStatus,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddStream )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  long lMediaType,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveStream )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  long lMediaType,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncryptionKey )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  long lMediaType,
            /* [annotation][in] */ 
            _In_  BSTR EncryptionKey);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendInfo )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrInfoHeader,
            /* [annotation][in] */ 
            _In_  BSTR bstrInfo,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreferredSecurityLevel )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_LEVEL enSecurityLevel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredSecurityLevel )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SECURITY_LEVEL *penSecurityLevel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsSecurityEnabled )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfSecurityEnabled);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AnswerWithSessionDescription )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrContentType,
            /* [annotation][in] */ 
            _In_  BSTR bstrSessionDescription);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReInviteWithSessionDescription )( 
            __RPC__in IRTCSession2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrContentType,
            /* [annotation][in] */ 
            _In_  BSTR bstrSessionDescription,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        END_INTERFACE
    } IRTCSession2Vtbl;

    interface IRTCSession2
    {
        CONST_VTBL struct IRTCSession2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSession2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCSession2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCSession2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCSession2_get_Client(This,ppClient)	\
    ( (This)->lpVtbl -> get_Client(This,ppClient) ) 

#define IRTCSession2_get_State(This,penState)	\
    ( (This)->lpVtbl -> get_State(This,penState) ) 

#define IRTCSession2_get_Type(This,penType)	\
    ( (This)->lpVtbl -> get_Type(This,penType) ) 

#define IRTCSession2_get_Profile(This,ppProfile)	\
    ( (This)->lpVtbl -> get_Profile(This,ppProfile) ) 

#define IRTCSession2_get_Participants(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Participants(This,ppCollection) ) 

#define IRTCSession2_Answer(This)	\
    ( (This)->lpVtbl -> Answer(This) ) 

#define IRTCSession2_Terminate(This,enReason)	\
    ( (This)->lpVtbl -> Terminate(This,enReason) ) 

#define IRTCSession2_Redirect(This,enType,bstrLocalPhoneURI,pProfile,lFlags)	\
    ( (This)->lpVtbl -> Redirect(This,enType,bstrLocalPhoneURI,pProfile,lFlags) ) 

#define IRTCSession2_AddParticipant(This,bstrAddress,bstrName,ppParticipant)	\
    ( (This)->lpVtbl -> AddParticipant(This,bstrAddress,bstrName,ppParticipant) ) 

#define IRTCSession2_RemoveParticipant(This,pParticipant)	\
    ( (This)->lpVtbl -> RemoveParticipant(This,pParticipant) ) 

#define IRTCSession2_EnumerateParticipants(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateParticipants(This,ppEnum) ) 

#define IRTCSession2_get_CanAddParticipants(This,pfCanAdd)	\
    ( (This)->lpVtbl -> get_CanAddParticipants(This,pfCanAdd) ) 

#define IRTCSession2_get_RedirectedUserURI(This,pbstrUserURI)	\
    ( (This)->lpVtbl -> get_RedirectedUserURI(This,pbstrUserURI) ) 

#define IRTCSession2_get_RedirectedUserName(This,pbstrUserName)	\
    ( (This)->lpVtbl -> get_RedirectedUserName(This,pbstrUserName) ) 

#define IRTCSession2_NextRedirectedUser(This)	\
    ( (This)->lpVtbl -> NextRedirectedUser(This) ) 

#define IRTCSession2_SendMessage(This,bstrMessageHeader,bstrMessage,lCookie)	\
    ( (This)->lpVtbl -> SendMessage(This,bstrMessageHeader,bstrMessage,lCookie) ) 

#define IRTCSession2_SendMessageStatus(This,enUserStatus,lCookie)	\
    ( (This)->lpVtbl -> SendMessageStatus(This,enUserStatus,lCookie) ) 

#define IRTCSession2_AddStream(This,lMediaType,lCookie)	\
    ( (This)->lpVtbl -> AddStream(This,lMediaType,lCookie) ) 

#define IRTCSession2_RemoveStream(This,lMediaType,lCookie)	\
    ( (This)->lpVtbl -> RemoveStream(This,lMediaType,lCookie) ) 

#define IRTCSession2_put_EncryptionKey(This,lMediaType,EncryptionKey)	\
    ( (This)->lpVtbl -> put_EncryptionKey(This,lMediaType,EncryptionKey) ) 


#define IRTCSession2_SendInfo(This,bstrInfoHeader,bstrInfo,lCookie)	\
    ( (This)->lpVtbl -> SendInfo(This,bstrInfoHeader,bstrInfo,lCookie) ) 

#define IRTCSession2_put_PreferredSecurityLevel(This,enSecurityType,enSecurityLevel)	\
    ( (This)->lpVtbl -> put_PreferredSecurityLevel(This,enSecurityType,enSecurityLevel) ) 

#define IRTCSession2_get_PreferredSecurityLevel(This,enSecurityType,penSecurityLevel)	\
    ( (This)->lpVtbl -> get_PreferredSecurityLevel(This,enSecurityType,penSecurityLevel) ) 

#define IRTCSession2_IsSecurityEnabled(This,enSecurityType,pfSecurityEnabled)	\
    ( (This)->lpVtbl -> IsSecurityEnabled(This,enSecurityType,pfSecurityEnabled) ) 

#define IRTCSession2_AnswerWithSessionDescription(This,bstrContentType,bstrSessionDescription)	\
    ( (This)->lpVtbl -> AnswerWithSessionDescription(This,bstrContentType,bstrSessionDescription) ) 

#define IRTCSession2_ReInviteWithSessionDescription(This,bstrContentType,bstrSessionDescription,lCookie)	\
    ( (This)->lpVtbl -> ReInviteWithSessionDescription(This,bstrContentType,bstrSessionDescription,lCookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCSession2_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionCallControl_INTERFACE_DEFINED__
#define __IRTCSessionCallControl_INTERFACE_DEFINED__

/* interface IRTCSessionCallControl */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionCallControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E9A50D94-190B-4F82-9530-3B8EBF60758A")
    IRTCSessionCallControl : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Hold( 
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UnHold( 
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Forward( 
            /* [annotation][in] */ 
            _In_  BSTR bstrForwardToURI) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Refer( 
            /* [annotation][in] */ 
            _In_  BSTR bstrReferToURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrReferCookie) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ReferredByURI( 
            /* [annotation][in] */ 
            _In_  BSTR bstrReferredByURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ReferredByURI( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrReferredByURI) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ReferCookie( 
            /* [annotation][in] */ 
            _In_  BSTR bstrReferCookie) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ReferCookie( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrReferCookie) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsReferred( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfIsReferred) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCSessionCallControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCSessionCallControl * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCSessionCallControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCSessionCallControl * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Hold )( 
            __RPC__in IRTCSessionCallControl * This,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnHold )( 
            __RPC__in IRTCSessionCallControl * This,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Forward )( 
            __RPC__in IRTCSessionCallControl * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrForwardToURI);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Refer )( 
            __RPC__in IRTCSessionCallControl * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrReferToURI,
            /* [annotation][in] */ 
            _In_  BSTR bstrReferCookie);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReferredByURI )( 
            __RPC__in IRTCSessionCallControl * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrReferredByURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferredByURI )( 
            __RPC__in IRTCSessionCallControl * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrReferredByURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReferCookie )( 
            __RPC__in IRTCSessionCallControl * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrReferCookie);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferCookie )( 
            __RPC__in IRTCSessionCallControl * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrReferCookie);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReferred )( 
            __RPC__in IRTCSessionCallControl * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfIsReferred);
        
        END_INTERFACE
    } IRTCSessionCallControlVtbl;

    interface IRTCSessionCallControl
    {
        CONST_VTBL struct IRTCSessionCallControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionCallControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCSessionCallControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCSessionCallControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCSessionCallControl_Hold(This,lCookie)	\
    ( (This)->lpVtbl -> Hold(This,lCookie) ) 

#define IRTCSessionCallControl_UnHold(This,lCookie)	\
    ( (This)->lpVtbl -> UnHold(This,lCookie) ) 

#define IRTCSessionCallControl_Forward(This,bstrForwardToURI)	\
    ( (This)->lpVtbl -> Forward(This,bstrForwardToURI) ) 

#define IRTCSessionCallControl_Refer(This,bstrReferToURI,bstrReferCookie)	\
    ( (This)->lpVtbl -> Refer(This,bstrReferToURI,bstrReferCookie) ) 

#define IRTCSessionCallControl_put_ReferredByURI(This,bstrReferredByURI)	\
    ( (This)->lpVtbl -> put_ReferredByURI(This,bstrReferredByURI) ) 

#define IRTCSessionCallControl_get_ReferredByURI(This,pbstrReferredByURI)	\
    ( (This)->lpVtbl -> get_ReferredByURI(This,pbstrReferredByURI) ) 

#define IRTCSessionCallControl_put_ReferCookie(This,bstrReferCookie)	\
    ( (This)->lpVtbl -> put_ReferCookie(This,bstrReferCookie) ) 

#define IRTCSessionCallControl_get_ReferCookie(This,pbstrReferCookie)	\
    ( (This)->lpVtbl -> get_ReferCookie(This,pbstrReferCookie) ) 

#define IRTCSessionCallControl_get_IsReferred(This,pfIsReferred)	\
    ( (This)->lpVtbl -> get_IsReferred(This,pfIsReferred) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCSessionCallControl_INTERFACE_DEFINED__ */


#ifndef __IRTCParticipant_INTERFACE_DEFINED__
#define __IRTCParticipant_INTERFACE_DEFINED__

/* interface IRTCParticipant */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCParticipant;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ae86add5-26b1-4414-af1d-b94cd938d739")
    IRTCParticipant : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UserURI( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Removable( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfRemovable) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PARTICIPANT_STATE *penState) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCParticipantVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCParticipant * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCParticipant * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCParticipant * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserURI )( 
            __RPC__in IRTCParticipant * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrUserURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IRTCParticipant * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Removable )( 
            __RPC__in IRTCParticipant * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfRemovable);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCParticipant * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PARTICIPANT_STATE *penState);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __RPC__in IRTCParticipant * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession);
        
        END_INTERFACE
    } IRTCParticipantVtbl;

    interface IRTCParticipant
    {
        CONST_VTBL struct IRTCParticipantVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCParticipant_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCParticipant_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCParticipant_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCParticipant_get_UserURI(This,pbstrUserURI)	\
    ( (This)->lpVtbl -> get_UserURI(This,pbstrUserURI) ) 

#define IRTCParticipant_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IRTCParticipant_get_Removable(This,pfRemovable)	\
    ( (This)->lpVtbl -> get_Removable(This,pfRemovable) ) 

#define IRTCParticipant_get_State(This,penState)	\
    ( (This)->lpVtbl -> get_State(This,penState) ) 

#define IRTCParticipant_get_Session(This,ppSession)	\
    ( (This)->lpVtbl -> get_Session(This,ppSession) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCParticipant_INTERFACE_DEFINED__ */


#ifndef __IRTCRoamingEvent_INTERFACE_DEFINED__
#define __IRTCRoamingEvent_INTERFACE_DEFINED__

/* interface IRTCRoamingEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCRoamingEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("79960a6b-0cb1-4dc8-a805-7318e99902e8")
    IRTCRoamingEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_ROAMING_EVENT_TYPE *pEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile2 **ppProfile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCRoamingEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCRoamingEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCRoamingEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCRoamingEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCRoamingEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCRoamingEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCRoamingEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCRoamingEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            __RPC__in IRTCRoamingEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_ROAMING_EVENT_TYPE *pEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            __RPC__in IRTCRoamingEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile2 **ppProfile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCRoamingEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IRTCRoamingEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCRoamingEventVtbl;

    interface IRTCRoamingEvent
    {
        CONST_VTBL struct IRTCRoamingEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCRoamingEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCRoamingEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCRoamingEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCRoamingEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCRoamingEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCRoamingEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCRoamingEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCRoamingEvent_get_EventType(This,pEventType)	\
    ( (This)->lpVtbl -> get_EventType(This,pEventType) ) 

#define IRTCRoamingEvent_get_Profile(This,ppProfile)	\
    ( (This)->lpVtbl -> get_Profile(This,ppProfile) ) 

#define IRTCRoamingEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCRoamingEvent_get_StatusText(This,pbstrStatusText)	\
    ( (This)->lpVtbl -> get_StatusText(This,pbstrStatusText) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCRoamingEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCProfileEvent_INTERFACE_DEFINED__
#define __IRTCProfileEvent_INTERFACE_DEFINED__

/* interface IRTCProfileEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCProfileEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D6D5AB3B-770E-43e8-800A-79B062395FCA")
    IRTCProfileEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile **ppProfile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cookie( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG_PTR *plCookie) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCProfileEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCProfileEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCProfileEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCProfileEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCProfileEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCProfileEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCProfileEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCProfileEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            __RPC__in IRTCProfileEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile **ppProfile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cookie )( 
            __RPC__in IRTCProfileEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG_PTR *plCookie);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCProfileEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        END_INTERFACE
    } IRTCProfileEventVtbl;

    interface IRTCProfileEvent
    {
        CONST_VTBL struct IRTCProfileEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCProfileEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCProfileEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCProfileEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCProfileEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCProfileEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCProfileEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCProfileEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCProfileEvent_get_Profile(This,ppProfile)	\
    ( (This)->lpVtbl -> get_Profile(This,ppProfile) ) 

#define IRTCProfileEvent_get_Cookie(This,plCookie)	\
    ( (This)->lpVtbl -> get_Cookie(This,plCookie) ) 

#define IRTCProfileEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCProfileEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCProfileEvent2_INTERFACE_DEFINED__
#define __IRTCProfileEvent2_INTERFACE_DEFINED__

/* interface IRTCProfileEvent2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCProfileEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("62E56EDC-03FA-4121-94FB-23493FD0AE64")
    IRTCProfileEvent2 : public IRTCProfileEvent
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PROFILE_EVENT_TYPE *pEventType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCProfileEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCProfileEvent2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCProfileEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCProfileEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCProfileEvent2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCProfileEvent2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCProfileEvent2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCProfileEvent2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            __RPC__in IRTCProfileEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile **ppProfile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cookie )( 
            __RPC__in IRTCProfileEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG_PTR *plCookie);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCProfileEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            __RPC__in IRTCProfileEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PROFILE_EVENT_TYPE *pEventType);
        
        END_INTERFACE
    } IRTCProfileEvent2Vtbl;

    interface IRTCProfileEvent2
    {
        CONST_VTBL struct IRTCProfileEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCProfileEvent2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCProfileEvent2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCProfileEvent2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCProfileEvent2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCProfileEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCProfileEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCProfileEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCProfileEvent2_get_Profile(This,ppProfile)	\
    ( (This)->lpVtbl -> get_Profile(This,ppProfile) ) 

#define IRTCProfileEvent2_get_Cookie(This,plCookie)	\
    ( (This)->lpVtbl -> get_Cookie(This,plCookie) ) 

#define IRTCProfileEvent2_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 


#define IRTCProfileEvent2_get_EventType(This,pEventType)	\
    ( (This)->lpVtbl -> get_EventType(This,pEventType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCProfileEvent2_INTERFACE_DEFINED__ */


#ifndef __IRTCClientEvent_INTERFACE_DEFINED__
#define __IRTCClientEvent_INTERFACE_DEFINED__

/* interface IRTCClientEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2b493b7a-3cba-4170-9c8b-76a9dacdd644")
    IRTCClientEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_CLIENT_EVENT_TYPE *penEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Client( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCClient **ppClient) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCClientEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCClientEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCClientEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCClientEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCClientEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCClientEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCClientEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCClientEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            __RPC__in IRTCClientEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_CLIENT_EVENT_TYPE *penEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Client )( 
            __RPC__in IRTCClientEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCClient **ppClient);
        
        END_INTERFACE
    } IRTCClientEventVtbl;

    interface IRTCClientEvent
    {
        CONST_VTBL struct IRTCClientEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCClientEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCClientEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCClientEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCClientEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCClientEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCClientEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCClientEvent_get_EventType(This,penEventType)	\
    ( (This)->lpVtbl -> get_EventType(This,penEventType) ) 

#define IRTCClientEvent_get_Client(This,ppClient)	\
    ( (This)->lpVtbl -> get_Client(This,ppClient) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCClientEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCRegistrationStateChangeEvent_INTERFACE_DEFINED__
#define __IRTCRegistrationStateChangeEvent_INTERFACE_DEFINED__

/* interface IRTCRegistrationStateChangeEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCRegistrationStateChangeEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("62d0991b-50ab-4f02-b948-ca94f26f8f95")
    IRTCRegistrationStateChangeEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile **ppProfile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_REGISTRATION_STATE *penState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCRegistrationStateChangeEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCRegistrationStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCRegistrationStateChangeEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCRegistrationStateChangeEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCRegistrationStateChangeEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCRegistrationStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCRegistrationStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCRegistrationStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            __RPC__in IRTCRegistrationStateChangeEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile **ppProfile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCRegistrationStateChangeEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_REGISTRATION_STATE *penState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCRegistrationStateChangeEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IRTCRegistrationStateChangeEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCRegistrationStateChangeEventVtbl;

    interface IRTCRegistrationStateChangeEvent
    {
        CONST_VTBL struct IRTCRegistrationStateChangeEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCRegistrationStateChangeEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCRegistrationStateChangeEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCRegistrationStateChangeEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCRegistrationStateChangeEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCRegistrationStateChangeEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCRegistrationStateChangeEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCRegistrationStateChangeEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCRegistrationStateChangeEvent_get_Profile(This,ppProfile)	\
    ( (This)->lpVtbl -> get_Profile(This,ppProfile) ) 

#define IRTCRegistrationStateChangeEvent_get_State(This,penState)	\
    ( (This)->lpVtbl -> get_State(This,penState) ) 

#define IRTCRegistrationStateChangeEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCRegistrationStateChangeEvent_get_StatusText(This,pbstrStatusText)	\
    ( (This)->lpVtbl -> get_StatusText(This,pbstrStatusText) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCRegistrationStateChangeEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent_INTERFACE_DEFINED__
#define __IRTCSessionStateChangeEvent_INTERFACE_DEFINED__

/* interface IRTCSessionStateChangeEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionStateChangeEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b5bad703-5952-48b3-9321-7f4500521506")
    IRTCSessionStateChangeEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SESSION_STATE *penState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCSessionStateChangeEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCSessionStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCSessionStateChangeEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCSessionStateChangeEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCSessionStateChangeEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCSessionStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCSessionStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __RPC__in IRTCSessionStateChangeEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCSessionStateChangeEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SESSION_STATE *penState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCSessionStateChangeEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IRTCSessionStateChangeEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCSessionStateChangeEventVtbl;

    interface IRTCSessionStateChangeEvent
    {
        CONST_VTBL struct IRTCSessionStateChangeEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionStateChangeEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCSessionStateChangeEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCSessionStateChangeEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCSessionStateChangeEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCSessionStateChangeEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCSessionStateChangeEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCSessionStateChangeEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCSessionStateChangeEvent_get_Session(This,ppSession)	\
    ( (This)->lpVtbl -> get_Session(This,ppSession) ) 

#define IRTCSessionStateChangeEvent_get_State(This,penState)	\
    ( (This)->lpVtbl -> get_State(This,penState) ) 

#define IRTCSessionStateChangeEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCSessionStateChangeEvent_get_StatusText(This,pbstrStatusText)	\
    ( (This)->lpVtbl -> get_StatusText(This,pbstrStatusText) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCSessionStateChangeEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionStateChangeEvent2_INTERFACE_DEFINED__
#define __IRTCSessionStateChangeEvent2_INTERFACE_DEFINED__

/* interface IRTCSessionStateChangeEvent2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionStateChangeEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F933171-6F95-4880-80D9-2EC8D495D261")
    IRTCSessionStateChangeEvent2 : public IRTCSessionStateChangeEvent
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MediaTypes( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pMediaTypes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemotePreferredSecurityLevel( 
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SECURITY_LEVEL *penSecurityLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsForked( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfIsForked) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRemoteSessionDescription( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrContentType,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrSessionDescription) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCSessionStateChangeEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionStateChangeEvent2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SESSION_STATE *penState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MediaTypes )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pMediaTypes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemotePreferredSecurityLevel )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SECURITY_LEVEL *penSecurityLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsForked )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfIsForked);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRemoteSessionDescription )( 
            __RPC__in IRTCSessionStateChangeEvent2 * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrContentType,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrSessionDescription);
        
        END_INTERFACE
    } IRTCSessionStateChangeEvent2Vtbl;

    interface IRTCSessionStateChangeEvent2
    {
        CONST_VTBL struct IRTCSessionStateChangeEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionStateChangeEvent2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCSessionStateChangeEvent2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCSessionStateChangeEvent2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCSessionStateChangeEvent2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCSessionStateChangeEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCSessionStateChangeEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCSessionStateChangeEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCSessionStateChangeEvent2_get_Session(This,ppSession)	\
    ( (This)->lpVtbl -> get_Session(This,ppSession) ) 

#define IRTCSessionStateChangeEvent2_get_State(This,penState)	\
    ( (This)->lpVtbl -> get_State(This,penState) ) 

#define IRTCSessionStateChangeEvent2_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCSessionStateChangeEvent2_get_StatusText(This,pbstrStatusText)	\
    ( (This)->lpVtbl -> get_StatusText(This,pbstrStatusText) ) 


#define IRTCSessionStateChangeEvent2_get_MediaTypes(This,pMediaTypes)	\
    ( (This)->lpVtbl -> get_MediaTypes(This,pMediaTypes) ) 

#define IRTCSessionStateChangeEvent2_get_RemotePreferredSecurityLevel(This,enSecurityType,penSecurityLevel)	\
    ( (This)->lpVtbl -> get_RemotePreferredSecurityLevel(This,enSecurityType,penSecurityLevel) ) 

#define IRTCSessionStateChangeEvent2_get_IsForked(This,pfIsForked)	\
    ( (This)->lpVtbl -> get_IsForked(This,pfIsForked) ) 

#define IRTCSessionStateChangeEvent2_GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription)	\
    ( (This)->lpVtbl -> GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCSessionStateChangeEvent2_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent_INTERFACE_DEFINED__
#define __IRTCSessionOperationCompleteEvent_INTERFACE_DEFINED__

/* interface IRTCSessionOperationCompleteEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionOperationCompleteEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a6bff4c0-f7c8-4d3c-9a41-3550f78a95b0")
    IRTCSessionOperationCompleteEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cookie( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG_PTR *plCookie) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCSessionOperationCompleteEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCSessionOperationCompleteEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCSessionOperationCompleteEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCSessionOperationCompleteEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCSessionOperationCompleteEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCSessionOperationCompleteEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCSessionOperationCompleteEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionOperationCompleteEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __RPC__in IRTCSessionOperationCompleteEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cookie )( 
            __RPC__in IRTCSessionOperationCompleteEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG_PTR *plCookie);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCSessionOperationCompleteEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IRTCSessionOperationCompleteEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCSessionOperationCompleteEventVtbl;

    interface IRTCSessionOperationCompleteEvent
    {
        CONST_VTBL struct IRTCSessionOperationCompleteEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionOperationCompleteEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCSessionOperationCompleteEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCSessionOperationCompleteEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCSessionOperationCompleteEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCSessionOperationCompleteEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCSessionOperationCompleteEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCSessionOperationCompleteEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCSessionOperationCompleteEvent_get_Session(This,ppSession)	\
    ( (This)->lpVtbl -> get_Session(This,ppSession) ) 

#define IRTCSessionOperationCompleteEvent_get_Cookie(This,plCookie)	\
    ( (This)->lpVtbl -> get_Cookie(This,plCookie) ) 

#define IRTCSessionOperationCompleteEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCSessionOperationCompleteEvent_get_StatusText(This,pbstrStatusText)	\
    ( (This)->lpVtbl -> get_StatusText(This,pbstrStatusText) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCSessionOperationCompleteEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionOperationCompleteEvent2_INTERFACE_DEFINED__
#define __IRTCSessionOperationCompleteEvent2_INTERFACE_DEFINED__

/* interface IRTCSessionOperationCompleteEvent2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionOperationCompleteEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f6fc2a9b-d5bc-4241-b436-1b8460c13832")
    IRTCSessionOperationCompleteEvent2 : public IRTCSessionOperationCompleteEvent
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Participant( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCParticipant **ppParticipant) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRemoteSessionDescription( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrContentType,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrSessionDescription) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCSessionOperationCompleteEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionOperationCompleteEvent2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cookie )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG_PTR *plCookie);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participant )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCParticipant **ppParticipant);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRemoteSessionDescription )( 
            __RPC__in IRTCSessionOperationCompleteEvent2 * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrContentType,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrSessionDescription);
        
        END_INTERFACE
    } IRTCSessionOperationCompleteEvent2Vtbl;

    interface IRTCSessionOperationCompleteEvent2
    {
        CONST_VTBL struct IRTCSessionOperationCompleteEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionOperationCompleteEvent2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCSessionOperationCompleteEvent2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCSessionOperationCompleteEvent2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCSessionOperationCompleteEvent2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCSessionOperationCompleteEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCSessionOperationCompleteEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCSessionOperationCompleteEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCSessionOperationCompleteEvent2_get_Session(This,ppSession)	\
    ( (This)->lpVtbl -> get_Session(This,ppSession) ) 

#define IRTCSessionOperationCompleteEvent2_get_Cookie(This,plCookie)	\
    ( (This)->lpVtbl -> get_Cookie(This,plCookie) ) 

#define IRTCSessionOperationCompleteEvent2_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCSessionOperationCompleteEvent2_get_StatusText(This,pbstrStatusText)	\
    ( (This)->lpVtbl -> get_StatusText(This,pbstrStatusText) ) 


#define IRTCSessionOperationCompleteEvent2_get_Participant(This,ppParticipant)	\
    ( (This)->lpVtbl -> get_Participant(This,ppParticipant) ) 

#define IRTCSessionOperationCompleteEvent2_GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription)	\
    ( (This)->lpVtbl -> GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCSessionOperationCompleteEvent2_INTERFACE_DEFINED__ */


#ifndef __IRTCParticipantStateChangeEvent_INTERFACE_DEFINED__
#define __IRTCParticipantStateChangeEvent_INTERFACE_DEFINED__

/* interface IRTCParticipantStateChangeEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCParticipantStateChangeEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("09bcb597-f0fa-48f9-b420-468cea7fde04")
    IRTCParticipantStateChangeEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Participant( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCParticipant **ppParticipant) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PARTICIPANT_STATE *penState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCParticipantStateChangeEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCParticipantStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCParticipantStateChangeEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCParticipantStateChangeEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCParticipantStateChangeEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCParticipantStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCParticipantStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCParticipantStateChangeEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participant )( 
            __RPC__in IRTCParticipantStateChangeEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCParticipant **ppParticipant);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCParticipantStateChangeEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PARTICIPANT_STATE *penState);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCParticipantStateChangeEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        END_INTERFACE
    } IRTCParticipantStateChangeEventVtbl;

    interface IRTCParticipantStateChangeEvent
    {
        CONST_VTBL struct IRTCParticipantStateChangeEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCParticipantStateChangeEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCParticipantStateChangeEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCParticipantStateChangeEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCParticipantStateChangeEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCParticipantStateChangeEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCParticipantStateChangeEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCParticipantStateChangeEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCParticipantStateChangeEvent_get_Participant(This,ppParticipant)	\
    ( (This)->lpVtbl -> get_Participant(This,ppParticipant) ) 

#define IRTCParticipantStateChangeEvent_get_State(This,penState)	\
    ( (This)->lpVtbl -> get_State(This,penState) ) 

#define IRTCParticipantStateChangeEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCParticipantStateChangeEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCMediaEvent_INTERFACE_DEFINED__
#define __IRTCMediaEvent_INTERFACE_DEFINED__

/* interface IRTCMediaEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCMediaEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("099944fb-bcda-453e-8c41-e13da2adf7f3")
    IRTCMediaEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MediaType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pMediaType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_MEDIA_EVENT_TYPE *penEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventReason( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_MEDIA_EVENT_REASON *penEventReason) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCMediaEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCMediaEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCMediaEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCMediaEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCMediaEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCMediaEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCMediaEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCMediaEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MediaType )( 
            __RPC__in IRTCMediaEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *pMediaType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            __RPC__in IRTCMediaEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_MEDIA_EVENT_TYPE *penEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventReason )( 
            __RPC__in IRTCMediaEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_MEDIA_EVENT_REASON *penEventReason);
        
        END_INTERFACE
    } IRTCMediaEventVtbl;

    interface IRTCMediaEvent
    {
        CONST_VTBL struct IRTCMediaEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCMediaEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCMediaEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCMediaEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCMediaEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCMediaEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCMediaEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCMediaEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCMediaEvent_get_MediaType(This,pMediaType)	\
    ( (This)->lpVtbl -> get_MediaType(This,pMediaType) ) 

#define IRTCMediaEvent_get_EventType(This,penEventType)	\
    ( (This)->lpVtbl -> get_EventType(This,penEventType) ) 

#define IRTCMediaEvent_get_EventReason(This,penEventReason)	\
    ( (This)->lpVtbl -> get_EventReason(This,penEventReason) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCMediaEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCIntensityEvent_INTERFACE_DEFINED__
#define __IRTCIntensityEvent_INTERFACE_DEFINED__

/* interface IRTCIntensityEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCIntensityEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4c23bf51-390c-4992-a41d-41eec05b2a4b")
    IRTCIntensityEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Level( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Min( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMin) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Max( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMax) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Direction( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_AUDIO_DEVICE *penDirection) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCIntensityEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCIntensityEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCIntensityEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCIntensityEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCIntensityEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCIntensityEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCIntensityEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCIntensityEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Level )( 
            __RPC__in IRTCIntensityEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Min )( 
            __RPC__in IRTCIntensityEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMin);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Max )( 
            __RPC__in IRTCIntensityEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMax);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Direction )( 
            __RPC__in IRTCIntensityEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_AUDIO_DEVICE *penDirection);
        
        END_INTERFACE
    } IRTCIntensityEventVtbl;

    interface IRTCIntensityEvent
    {
        CONST_VTBL struct IRTCIntensityEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCIntensityEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCIntensityEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCIntensityEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCIntensityEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCIntensityEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCIntensityEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCIntensityEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCIntensityEvent_get_Level(This,plLevel)	\
    ( (This)->lpVtbl -> get_Level(This,plLevel) ) 

#define IRTCIntensityEvent_get_Min(This,plMin)	\
    ( (This)->lpVtbl -> get_Min(This,plMin) ) 

#define IRTCIntensityEvent_get_Max(This,plMax)	\
    ( (This)->lpVtbl -> get_Max(This,plMax) ) 

#define IRTCIntensityEvent_get_Direction(This,penDirection)	\
    ( (This)->lpVtbl -> get_Direction(This,penDirection) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCIntensityEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCMessagingEvent_INTERFACE_DEFINED__
#define __IRTCMessagingEvent_INTERFACE_DEFINED__

/* interface IRTCMessagingEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCMessagingEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d3609541-1b29-4de5-a4ad-5aebaf319512")
    IRTCMessagingEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Participant( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCParticipant **ppParticipant) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_MESSAGING_EVENT_TYPE *penEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Message( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrMessage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MessageHeader( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrMessageHeader) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserStatus( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_MESSAGING_USER_STATUS *penUserStatus) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCMessagingEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCMessagingEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCMessagingEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCMessagingEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCMessagingEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCMessagingEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCMessagingEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCMessagingEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __RPC__in IRTCMessagingEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participant )( 
            __RPC__in IRTCMessagingEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCParticipant **ppParticipant);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            __RPC__in IRTCMessagingEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_MESSAGING_EVENT_TYPE *penEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Message )( 
            __RPC__in IRTCMessagingEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrMessage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MessageHeader )( 
            __RPC__in IRTCMessagingEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrMessageHeader);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserStatus )( 
            __RPC__in IRTCMessagingEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_MESSAGING_USER_STATUS *penUserStatus);
        
        END_INTERFACE
    } IRTCMessagingEventVtbl;

    interface IRTCMessagingEvent
    {
        CONST_VTBL struct IRTCMessagingEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCMessagingEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCMessagingEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCMessagingEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCMessagingEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCMessagingEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCMessagingEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCMessagingEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCMessagingEvent_get_Session(This,ppSession)	\
    ( (This)->lpVtbl -> get_Session(This,ppSession) ) 

#define IRTCMessagingEvent_get_Participant(This,ppParticipant)	\
    ( (This)->lpVtbl -> get_Participant(This,ppParticipant) ) 

#define IRTCMessagingEvent_get_EventType(This,penEventType)	\
    ( (This)->lpVtbl -> get_EventType(This,penEventType) ) 

#define IRTCMessagingEvent_get_Message(This,pbstrMessage)	\
    ( (This)->lpVtbl -> get_Message(This,pbstrMessage) ) 

#define IRTCMessagingEvent_get_MessageHeader(This,pbstrMessageHeader)	\
    ( (This)->lpVtbl -> get_MessageHeader(This,pbstrMessageHeader) ) 

#define IRTCMessagingEvent_get_UserStatus(This,penUserStatus)	\
    ( (This)->lpVtbl -> get_UserStatus(This,penUserStatus) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCMessagingEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddyEvent_INTERFACE_DEFINED__
#define __IRTCBuddyEvent_INTERFACE_DEFINED__

/* interface IRTCBuddyEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddyEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f36d755d-17e6-404e-954f-0fc07574c78d")
    IRTCBuddyEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Buddy( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy **ppBuddy) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCBuddyEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCBuddyEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCBuddyEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCBuddyEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCBuddyEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCBuddyEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCBuddyEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCBuddyEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddy )( 
            __RPC__in IRTCBuddyEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy **ppBuddy);
        
        END_INTERFACE
    } IRTCBuddyEventVtbl;

    interface IRTCBuddyEvent
    {
        CONST_VTBL struct IRTCBuddyEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddyEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCBuddyEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCBuddyEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCBuddyEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCBuddyEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCBuddyEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCBuddyEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCBuddyEvent_get_Buddy(This,ppBuddy)	\
    ( (This)->lpVtbl -> get_Buddy(This,ppBuddy) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCBuddyEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddyEvent2_INTERFACE_DEFINED__
#define __IRTCBuddyEvent2_INTERFACE_DEFINED__

/* interface IRTCBuddyEvent2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddyEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("484A7F1E-73F0-4990-BFC2-60BC3978A720")
    IRTCBuddyEvent2 : public IRTCBuddyEvent
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_BUDDY_EVENT_TYPE *pEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCBuddyEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCBuddyEvent2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCBuddyEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCBuddyEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCBuddyEvent2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCBuddyEvent2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCBuddyEvent2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCBuddyEvent2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddy )( 
            __RPC__in IRTCBuddyEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy **ppBuddy);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            __RPC__in IRTCBuddyEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_BUDDY_EVENT_TYPE *pEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCBuddyEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IRTCBuddyEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCBuddyEvent2Vtbl;

    interface IRTCBuddyEvent2
    {
        CONST_VTBL struct IRTCBuddyEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddyEvent2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCBuddyEvent2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCBuddyEvent2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCBuddyEvent2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCBuddyEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCBuddyEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCBuddyEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCBuddyEvent2_get_Buddy(This,ppBuddy)	\
    ( (This)->lpVtbl -> get_Buddy(This,ppBuddy) ) 


#define IRTCBuddyEvent2_get_EventType(This,pEventType)	\
    ( (This)->lpVtbl -> get_EventType(This,pEventType) ) 

#define IRTCBuddyEvent2_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCBuddyEvent2_get_StatusText(This,pbstrStatusText)	\
    ( (This)->lpVtbl -> get_StatusText(This,pbstrStatusText) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCBuddyEvent2_INTERFACE_DEFINED__ */


#ifndef __IRTCWatcherEvent_INTERFACE_DEFINED__
#define __IRTCWatcherEvent_INTERFACE_DEFINED__

/* interface IRTCWatcherEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCWatcherEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f30d7261-587a-424f-822c-312788f43548")
    IRTCWatcherEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Watcher( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher **ppWatcher) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCWatcherEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCWatcherEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCWatcherEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCWatcherEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCWatcherEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCWatcherEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCWatcherEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCWatcherEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watcher )( 
            __RPC__in IRTCWatcherEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher **ppWatcher);
        
        END_INTERFACE
    } IRTCWatcherEventVtbl;

    interface IRTCWatcherEvent
    {
        CONST_VTBL struct IRTCWatcherEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCWatcherEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCWatcherEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCWatcherEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCWatcherEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCWatcherEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCWatcherEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCWatcherEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCWatcherEvent_get_Watcher(This,ppWatcher)	\
    ( (This)->lpVtbl -> get_Watcher(This,ppWatcher) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCWatcherEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCWatcherEvent2_INTERFACE_DEFINED__
#define __IRTCWatcherEvent2_INTERFACE_DEFINED__

/* interface IRTCWatcherEvent2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCWatcherEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E52891E8-188C-49AF-B005-98ED13F83F9C")
    IRTCWatcherEvent2 : public IRTCWatcherEvent
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_WATCHER_EVENT_TYPE *pEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCWatcherEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCWatcherEvent2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCWatcherEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCWatcherEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCWatcherEvent2 * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCWatcherEvent2 * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCWatcherEvent2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCWatcherEvent2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Watcher )( 
            __RPC__in IRTCWatcherEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCWatcher **ppWatcher);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            __RPC__in IRTCWatcherEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_WATCHER_EVENT_TYPE *pEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCWatcherEvent2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        END_INTERFACE
    } IRTCWatcherEvent2Vtbl;

    interface IRTCWatcherEvent2
    {
        CONST_VTBL struct IRTCWatcherEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCWatcherEvent2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCWatcherEvent2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCWatcherEvent2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCWatcherEvent2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCWatcherEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCWatcherEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCWatcherEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCWatcherEvent2_get_Watcher(This,ppWatcher)	\
    ( (This)->lpVtbl -> get_Watcher(This,ppWatcher) ) 


#define IRTCWatcherEvent2_get_EventType(This,pEventType)	\
    ( (This)->lpVtbl -> get_EventType(This,pEventType) ) 

#define IRTCWatcherEvent2_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCWatcherEvent2_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddyGroupEvent_INTERFACE_DEFINED__
#define __IRTCBuddyGroupEvent_INTERFACE_DEFINED__

/* interface IRTCBuddyGroupEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddyGroupEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3A79E1D1-B736-4414-96F8-BBC7F08863E4")
    IRTCBuddyGroupEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_GROUP_EVENT_TYPE *pEventType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Group( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddyGroup **ppGroup) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Buddy( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy2 **ppBuddy) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCBuddyGroupEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCBuddyGroupEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCBuddyGroupEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCBuddyGroupEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCBuddyGroupEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCBuddyGroupEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCBuddyGroupEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCBuddyGroupEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventType )( 
            __RPC__in IRTCBuddyGroupEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_GROUP_EVENT_TYPE *pEventType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Group )( 
            __RPC__in IRTCBuddyGroupEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddyGroup **ppGroup);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddy )( 
            __RPC__in IRTCBuddyGroupEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCBuddy2 **ppBuddy);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCBuddyGroupEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        END_INTERFACE
    } IRTCBuddyGroupEventVtbl;

    interface IRTCBuddyGroupEvent
    {
        CONST_VTBL struct IRTCBuddyGroupEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddyGroupEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCBuddyGroupEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCBuddyGroupEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCBuddyGroupEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCBuddyGroupEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCBuddyGroupEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCBuddyGroupEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCBuddyGroupEvent_get_EventType(This,pEventType)	\
    ( (This)->lpVtbl -> get_EventType(This,pEventType) ) 

#define IRTCBuddyGroupEvent_get_Group(This,ppGroup)	\
    ( (This)->lpVtbl -> get_Group(This,ppGroup) ) 

#define IRTCBuddyGroupEvent_get_Buddy(This,ppBuddy)	\
    ( (This)->lpVtbl -> get_Buddy(This,ppBuddy) ) 

#define IRTCBuddyGroupEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCBuddyGroupEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCInfoEvent_INTERFACE_DEFINED__
#define __IRTCInfoEvent_INTERFACE_DEFINED__

/* interface IRTCInfoEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCInfoEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4E1D68AE-1912-4f49-B2C3-594FADFD425F")
    IRTCInfoEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Participant( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCParticipant **ppParticipant) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Info( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrInfo) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InfoHeader( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrInfoHeader) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCInfoEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCInfoEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCInfoEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCInfoEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCInfoEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCInfoEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCInfoEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCInfoEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __RPC__in IRTCInfoEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Participant )( 
            __RPC__in IRTCInfoEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCParticipant **ppParticipant);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Info )( 
            __RPC__in IRTCInfoEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrInfo);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InfoHeader )( 
            __RPC__in IRTCInfoEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrInfoHeader);
        
        END_INTERFACE
    } IRTCInfoEventVtbl;

    interface IRTCInfoEvent
    {
        CONST_VTBL struct IRTCInfoEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCInfoEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCInfoEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCInfoEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCInfoEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCInfoEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCInfoEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCInfoEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCInfoEvent_get_Session(This,ppSession)	\
    ( (This)->lpVtbl -> get_Session(This,ppSession) ) 

#define IRTCInfoEvent_get_Participant(This,ppParticipant)	\
    ( (This)->lpVtbl -> get_Participant(This,ppParticipant) ) 

#define IRTCInfoEvent_get_Info(This,pbstrInfo)	\
    ( (This)->lpVtbl -> get_Info(This,pbstrInfo) ) 

#define IRTCInfoEvent_get_InfoHeader(This,pbstrInfoHeader)	\
    ( (This)->lpVtbl -> get_InfoHeader(This,pbstrInfoHeader) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCInfoEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCMediaRequestEvent_INTERFACE_DEFINED__
#define __IRTCMediaRequestEvent_INTERFACE_DEFINED__

/* interface IRTCMediaRequestEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCMediaRequestEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52572D15-148C-4d97-A36C-2DA55C289D63")
    IRTCMediaRequestEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProposedMedia( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaTypes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentMedia( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaTypes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Accept( 
            /* [annotation][in] */ 
            _In_  long lMediaTypes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemotePreferredSecurityLevel( 
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SECURITY_LEVEL *penSecurityLevel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reject( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_REINVITE_STATE *pState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCMediaRequestEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCMediaRequestEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCMediaRequestEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCMediaRequestEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCMediaRequestEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCMediaRequestEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCMediaRequestEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCMediaRequestEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __RPC__in IRTCMediaRequestEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProposedMedia )( 
            __RPC__in IRTCMediaRequestEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaTypes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentMedia )( 
            __RPC__in IRTCMediaRequestEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plMediaTypes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Accept )( 
            __RPC__in IRTCMediaRequestEvent * This,
            /* [annotation][in] */ 
            _In_  long lMediaTypes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemotePreferredSecurityLevel )( 
            __RPC__in IRTCMediaRequestEvent * This,
            /* [annotation][in] */ 
            _In_  RTC_SECURITY_TYPE enSecurityType,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SECURITY_LEVEL *penSecurityLevel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reject )( 
            __RPC__in IRTCMediaRequestEvent * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCMediaRequestEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_REINVITE_STATE *pState);
        
        END_INTERFACE
    } IRTCMediaRequestEventVtbl;

    interface IRTCMediaRequestEvent
    {
        CONST_VTBL struct IRTCMediaRequestEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCMediaRequestEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCMediaRequestEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCMediaRequestEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCMediaRequestEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCMediaRequestEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCMediaRequestEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCMediaRequestEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCMediaRequestEvent_get_Session(This,ppSession)	\
    ( (This)->lpVtbl -> get_Session(This,ppSession) ) 

#define IRTCMediaRequestEvent_get_ProposedMedia(This,plMediaTypes)	\
    ( (This)->lpVtbl -> get_ProposedMedia(This,plMediaTypes) ) 

#define IRTCMediaRequestEvent_get_CurrentMedia(This,plMediaTypes)	\
    ( (This)->lpVtbl -> get_CurrentMedia(This,plMediaTypes) ) 

#define IRTCMediaRequestEvent_Accept(This,lMediaTypes)	\
    ( (This)->lpVtbl -> Accept(This,lMediaTypes) ) 

#define IRTCMediaRequestEvent_get_RemotePreferredSecurityLevel(This,enSecurityType,penSecurityLevel)	\
    ( (This)->lpVtbl -> get_RemotePreferredSecurityLevel(This,enSecurityType,penSecurityLevel) ) 

#define IRTCMediaRequestEvent_Reject(This)	\
    ( (This)->lpVtbl -> Reject(This) ) 

#define IRTCMediaRequestEvent_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCMediaRequestEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCReInviteEvent_INTERFACE_DEFINED__
#define __IRTCReInviteEvent_INTERFACE_DEFINED__

/* interface IRTCReInviteEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCReInviteEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11558D84-204C-43e7-99B0-2034E9417F7D")
    IRTCReInviteEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Accept( 
            /* [annotation][in] */ 
            _In_  BSTR bstrContentType,
            /* [annotation][in] */ 
            _In_  BSTR bstrSessionDescription) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reject( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_REINVITE_STATE *pState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRemoteSessionDescription( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrContentType,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrSessionDescription) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCReInviteEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCReInviteEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCReInviteEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCReInviteEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCReInviteEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCReInviteEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCReInviteEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCReInviteEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __RPC__in IRTCReInviteEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Accept )( 
            __RPC__in IRTCReInviteEvent * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrContentType,
            /* [annotation][in] */ 
            _In_  BSTR bstrSessionDescription);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reject )( 
            __RPC__in IRTCReInviteEvent * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCReInviteEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_REINVITE_STATE *pState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRemoteSessionDescription )( 
            __RPC__in IRTCReInviteEvent * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrContentType,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrSessionDescription);
        
        END_INTERFACE
    } IRTCReInviteEventVtbl;

    interface IRTCReInviteEvent
    {
        CONST_VTBL struct IRTCReInviteEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCReInviteEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCReInviteEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCReInviteEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCReInviteEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCReInviteEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCReInviteEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCReInviteEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCReInviteEvent_get_Session(This,ppSession2)	\
    ( (This)->lpVtbl -> get_Session(This,ppSession2) ) 

#define IRTCReInviteEvent_Accept(This,bstrContentType,bstrSessionDescription)	\
    ( (This)->lpVtbl -> Accept(This,bstrContentType,bstrSessionDescription) ) 

#define IRTCReInviteEvent_Reject(This)	\
    ( (This)->lpVtbl -> Reject(This) ) 

#define IRTCReInviteEvent_get_State(This,pState)	\
    ( (This)->lpVtbl -> get_State(This,pState) ) 

#define IRTCReInviteEvent_GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription)	\
    ( (This)->lpVtbl -> GetRemoteSessionDescription(This,pbstrContentType,pbstrSessionDescription) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCReInviteEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCPresencePropertyEvent_INTERFACE_DEFINED__
#define __IRTCPresencePropertyEvent_INTERFACE_DEFINED__

/* interface IRTCPresencePropertyEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCPresencePropertyEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F777F570-A820-49d5-86BD-E099493F1518")
    IRTCPresencePropertyEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PresenceProperty( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PRESENCE_PROPERTY *penPresProp) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCPresencePropertyEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCPresencePropertyEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCPresencePropertyEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCPresencePropertyEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCPresencePropertyEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCPresencePropertyEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCPresencePropertyEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCPresencePropertyEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCPresencePropertyEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IRTCPresencePropertyEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresenceProperty )( 
            __RPC__in IRTCPresencePropertyEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PRESENCE_PROPERTY *penPresProp);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            __RPC__in IRTCPresencePropertyEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrValue);
        
        END_INTERFACE
    } IRTCPresencePropertyEventVtbl;

    interface IRTCPresencePropertyEvent
    {
        CONST_VTBL struct IRTCPresencePropertyEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPresencePropertyEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCPresencePropertyEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCPresencePropertyEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCPresencePropertyEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCPresencePropertyEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCPresencePropertyEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCPresencePropertyEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCPresencePropertyEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCPresencePropertyEvent_get_StatusText(This,pbstrStatusText)	\
    ( (This)->lpVtbl -> get_StatusText(This,pbstrStatusText) ) 

#define IRTCPresencePropertyEvent_get_PresenceProperty(This,penPresProp)	\
    ( (This)->lpVtbl -> get_PresenceProperty(This,penPresProp) ) 

#define IRTCPresencePropertyEvent_get_Value(This,pbstrValue)	\
    ( (This)->lpVtbl -> get_Value(This,pbstrValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCPresencePropertyEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCPresenceDataEvent_INTERFACE_DEFINED__
#define __IRTCPresenceDataEvent_INTERFACE_DEFINED__

/* interface IRTCPresenceDataEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCPresenceDataEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38F0E78C-8B87-4c04-A82D-AEDD83C909BB")
    IRTCPresenceDataEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPresenceData( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrNamespace,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCPresenceDataEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCPresenceDataEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCPresenceDataEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCPresenceDataEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCPresenceDataEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCPresenceDataEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCPresenceDataEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCPresenceDataEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCPresenceDataEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IRTCPresenceDataEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPresenceData )( 
            __RPC__in IRTCPresenceDataEvent * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrNamespace,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrData);
        
        END_INTERFACE
    } IRTCPresenceDataEventVtbl;

    interface IRTCPresenceDataEvent
    {
        CONST_VTBL struct IRTCPresenceDataEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPresenceDataEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCPresenceDataEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCPresenceDataEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCPresenceDataEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCPresenceDataEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCPresenceDataEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCPresenceDataEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCPresenceDataEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCPresenceDataEvent_get_StatusText(This,pbstrStatusText)	\
    ( (This)->lpVtbl -> get_StatusText(This,pbstrStatusText) ) 

#define IRTCPresenceDataEvent_GetPresenceData(This,pbstrNamespace,pbstrData)	\
    ( (This)->lpVtbl -> GetPresenceData(This,pbstrNamespace,pbstrData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCPresenceDataEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCPresenceStatusEvent_INTERFACE_DEFINED__
#define __IRTCPresenceStatusEvent_INTERFACE_DEFINED__

/* interface IRTCPresenceStatusEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCPresenceStatusEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("78673F32-4A0F-462c-89AA-EE7706707678")
    IRTCPresenceStatusEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLocalPresenceInfo( 
            /* [annotation][out] */ 
            _Out_  RTC_PRESENCE_STATUS *penStatus,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrNotes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCPresenceStatusEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCPresenceStatusEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCPresenceStatusEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCPresenceStatusEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCPresenceStatusEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCPresenceStatusEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCPresenceStatusEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCPresenceStatusEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCPresenceStatusEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IRTCPresenceStatusEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLocalPresenceInfo )( 
            __RPC__in IRTCPresenceStatusEvent * This,
            /* [annotation][out] */ 
            _Out_  RTC_PRESENCE_STATUS *penStatus,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrNotes);
        
        END_INTERFACE
    } IRTCPresenceStatusEventVtbl;

    interface IRTCPresenceStatusEvent
    {
        CONST_VTBL struct IRTCPresenceStatusEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPresenceStatusEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCPresenceStatusEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCPresenceStatusEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCPresenceStatusEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCPresenceStatusEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCPresenceStatusEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCPresenceStatusEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCPresenceStatusEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCPresenceStatusEvent_get_StatusText(This,pbstrStatusText)	\
    ( (This)->lpVtbl -> get_StatusText(This,pbstrStatusText) ) 

#define IRTCPresenceStatusEvent_GetLocalPresenceInfo(This,penStatus,pbstrNotes)	\
    ( (This)->lpVtbl -> GetLocalPresenceInfo(This,penStatus,pbstrNotes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCPresenceStatusEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCCollection_INTERFACE_DEFINED__
#define __IRTCCollection_INTERFACE_DEFINED__

/* interface IRTCCollection */
/* [dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC7C8096-B918-4044-94F1-E4FBA0361D5C")
    IRTCCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *lCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [annotation][in] */ 
            _In_  long Index,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVariant) = 0;
        
        virtual /* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **ppNewEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCCollection * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCCollection * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCCollection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCCollection * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in IRTCCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *lCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            __RPC__in IRTCCollection * This,
            /* [annotation][in] */ 
            _In_  long Index,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT *pVariant);
        
        /* [helpstring][id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in IRTCCollection * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IUnknown **ppNewEnum);
        
        END_INTERFACE
    } IRTCCollectionVtbl;

    interface IRTCCollection
    {
        CONST_VTBL struct IRTCCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCCollection_get_Count(This,lCount)	\
    ( (This)->lpVtbl -> get_Count(This,lCount) ) 

#define IRTCCollection_get_Item(This,Index,pVariant)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVariant) ) 

#define IRTCCollection_get__NewEnum(This,ppNewEnum)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppNewEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCCollection_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumParticipants_INTERFACE_DEFINED__
#define __IRTCEnumParticipants_INTERFACE_DEFINED__

/* interface IRTCEnumParticipants */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumParticipants;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fcd56f29-4a4f-41b2-ba5c-f5bccc060bf6")
    IRTCEnumParticipants : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCParticipant **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumParticipants **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCEnumParticipantsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCEnumParticipants * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCEnumParticipants * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCEnumParticipants * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IRTCEnumParticipants * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCParticipant **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IRTCEnumParticipants * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IRTCEnumParticipants * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IRTCEnumParticipants * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumParticipants **ppEnum);
        
        END_INTERFACE
    } IRTCEnumParticipantsVtbl;

    interface IRTCEnumParticipants
    {
        CONST_VTBL struct IRTCEnumParticipantsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumParticipants_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCEnumParticipants_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCEnumParticipants_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCEnumParticipants_Next(This,celt,ppElements,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched) ) 

#define IRTCEnumParticipants_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IRTCEnumParticipants_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IRTCEnumParticipants_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCEnumParticipants_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumProfiles_INTERFACE_DEFINED__
#define __IRTCEnumProfiles_INTERFACE_DEFINED__

/* interface IRTCEnumProfiles */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumProfiles;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29b7c41c-ed82-4bca-84ad-39d5101b58e3")
    IRTCEnumProfiles : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCProfile **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumProfiles **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCEnumProfilesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCEnumProfiles * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCEnumProfiles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCEnumProfiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IRTCEnumProfiles * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCProfile **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IRTCEnumProfiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IRTCEnumProfiles * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IRTCEnumProfiles * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumProfiles **ppEnum);
        
        END_INTERFACE
    } IRTCEnumProfilesVtbl;

    interface IRTCEnumProfiles
    {
        CONST_VTBL struct IRTCEnumProfilesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumProfiles_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCEnumProfiles_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCEnumProfiles_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCEnumProfiles_Next(This,celt,ppElements,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched) ) 

#define IRTCEnumProfiles_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IRTCEnumProfiles_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IRTCEnumProfiles_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCEnumProfiles_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumBuddies_INTERFACE_DEFINED__
#define __IRTCEnumBuddies_INTERFACE_DEFINED__

/* interface IRTCEnumBuddies */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumBuddies;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f7296917-5569-4b3b-b3af-98d1144b2b87")
    IRTCEnumBuddies : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCBuddy **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumBuddies **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCEnumBuddiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCEnumBuddies * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCEnumBuddies * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCEnumBuddies * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IRTCEnumBuddies * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCBuddy **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IRTCEnumBuddies * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IRTCEnumBuddies * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IRTCEnumBuddies * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumBuddies **ppEnum);
        
        END_INTERFACE
    } IRTCEnumBuddiesVtbl;

    interface IRTCEnumBuddies
    {
        CONST_VTBL struct IRTCEnumBuddiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumBuddies_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCEnumBuddies_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCEnumBuddies_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCEnumBuddies_Next(This,celt,ppElements,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched) ) 

#define IRTCEnumBuddies_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IRTCEnumBuddies_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IRTCEnumBuddies_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCEnumBuddies_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumWatchers_INTERFACE_DEFINED__
#define __IRTCEnumWatchers_INTERFACE_DEFINED__

/* interface IRTCEnumWatchers */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumWatchers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a87d55d7-db74-4ed1-9ca4-77a0e41b413e")
    IRTCEnumWatchers : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCWatcher **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumWatchers **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCEnumWatchersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCEnumWatchers * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCEnumWatchers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCEnumWatchers * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IRTCEnumWatchers * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCWatcher **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IRTCEnumWatchers * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IRTCEnumWatchers * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IRTCEnumWatchers * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumWatchers **ppEnum);
        
        END_INTERFACE
    } IRTCEnumWatchersVtbl;

    interface IRTCEnumWatchers
    {
        CONST_VTBL struct IRTCEnumWatchersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumWatchers_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCEnumWatchers_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCEnumWatchers_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCEnumWatchers_Next(This,celt,ppElements,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched) ) 

#define IRTCEnumWatchers_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IRTCEnumWatchers_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IRTCEnumWatchers_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCEnumWatchers_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumGroups_INTERFACE_DEFINED__
#define __IRTCEnumGroups_INTERFACE_DEFINED__

/* interface IRTCEnumGroups */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumGroups;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("742378D6-A141-4415-8F27-35D99076CF5D")
    IRTCEnumGroups : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCBuddyGroup **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumGroups **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCEnumGroupsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCEnumGroups * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCEnumGroups * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCEnumGroups * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IRTCEnumGroups * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCBuddyGroup **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IRTCEnumGroups * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IRTCEnumGroups * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IRTCEnumGroups * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumGroups **ppEnum);
        
        END_INTERFACE
    } IRTCEnumGroupsVtbl;

    interface IRTCEnumGroups
    {
        CONST_VTBL struct IRTCEnumGroupsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumGroups_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCEnumGroups_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCEnumGroups_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCEnumGroups_Next(This,celt,ppElements,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched) ) 

#define IRTCEnumGroups_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IRTCEnumGroups_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IRTCEnumGroups_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCEnumGroups_INTERFACE_DEFINED__ */


#ifndef __IRTCPresenceContact_INTERFACE_DEFINED__
#define __IRTCPresenceContact_INTERFACE_DEFINED__

/* interface IRTCPresenceContact */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCPresenceContact;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8b22f92c-cd90-42db-a733-212205c3e3df")
    IRTCPresenceContact : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PresentityURI( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPresentityURI) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PresentityURI( 
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [annotation][in] */ 
            _In_  BSTR bstrName) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Data( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Data( 
            /* [annotation][in] */ 
            _In_  BSTR bstrData) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Persistent( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfPersistent) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Persistent( 
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCPresenceContactVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCPresenceContact * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCPresenceContact * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCPresenceContact * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresentityURI )( 
            __RPC__in IRTCPresenceContact * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPresentityURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresentityURI )( 
            __RPC__in IRTCPresenceContact * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IRTCPresenceContact * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IRTCPresenceContact * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            __RPC__in IRTCPresenceContact * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            __RPC__in IRTCPresenceContact * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Persistent )( 
            __RPC__in IRTCPresenceContact * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfPersistent);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Persistent )( 
            __RPC__in IRTCPresenceContact * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent);
        
        END_INTERFACE
    } IRTCPresenceContactVtbl;

    interface IRTCPresenceContact
    {
        CONST_VTBL struct IRTCPresenceContactVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPresenceContact_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCPresenceContact_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCPresenceContact_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCPresenceContact_get_PresentityURI(This,pbstrPresentityURI)	\
    ( (This)->lpVtbl -> get_PresentityURI(This,pbstrPresentityURI) ) 

#define IRTCPresenceContact_put_PresentityURI(This,bstrPresentityURI)	\
    ( (This)->lpVtbl -> put_PresentityURI(This,bstrPresentityURI) ) 

#define IRTCPresenceContact_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IRTCPresenceContact_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IRTCPresenceContact_get_Data(This,pbstrData)	\
    ( (This)->lpVtbl -> get_Data(This,pbstrData) ) 

#define IRTCPresenceContact_put_Data(This,bstrData)	\
    ( (This)->lpVtbl -> put_Data(This,bstrData) ) 

#define IRTCPresenceContact_get_Persistent(This,pfPersistent)	\
    ( (This)->lpVtbl -> get_Persistent(This,pfPersistent) ) 

#define IRTCPresenceContact_put_Persistent(This,fPersistent)	\
    ( (This)->lpVtbl -> put_Persistent(This,fPersistent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCPresenceContact_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddy_INTERFACE_DEFINED__
#define __IRTCBuddy_INTERFACE_DEFINED__

/* interface IRTCBuddy */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fcb136c8-7b90-4e0c-befe-56edf0ba6f1c")
    IRTCBuddy : public IRTCPresenceContact
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PRESENCE_STATUS *penStatus) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Notes( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrNotes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCBuddyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCBuddy * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCBuddy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCBuddy * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresentityURI )( 
            __RPC__in IRTCBuddy * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPresentityURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresentityURI )( 
            __RPC__in IRTCBuddy * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IRTCBuddy * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IRTCBuddy * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            __RPC__in IRTCBuddy * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            __RPC__in IRTCBuddy * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Persistent )( 
            __RPC__in IRTCBuddy * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfPersistent);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Persistent )( 
            __RPC__in IRTCBuddy * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            __RPC__in IRTCBuddy * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PRESENCE_STATUS *penStatus);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Notes )( 
            __RPC__in IRTCBuddy * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrNotes);
        
        END_INTERFACE
    } IRTCBuddyVtbl;

    interface IRTCBuddy
    {
        CONST_VTBL struct IRTCBuddyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddy_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCBuddy_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCBuddy_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCBuddy_get_PresentityURI(This,pbstrPresentityURI)	\
    ( (This)->lpVtbl -> get_PresentityURI(This,pbstrPresentityURI) ) 

#define IRTCBuddy_put_PresentityURI(This,bstrPresentityURI)	\
    ( (This)->lpVtbl -> put_PresentityURI(This,bstrPresentityURI) ) 

#define IRTCBuddy_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IRTCBuddy_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IRTCBuddy_get_Data(This,pbstrData)	\
    ( (This)->lpVtbl -> get_Data(This,pbstrData) ) 

#define IRTCBuddy_put_Data(This,bstrData)	\
    ( (This)->lpVtbl -> put_Data(This,bstrData) ) 

#define IRTCBuddy_get_Persistent(This,pfPersistent)	\
    ( (This)->lpVtbl -> get_Persistent(This,pfPersistent) ) 

#define IRTCBuddy_put_Persistent(This,fPersistent)	\
    ( (This)->lpVtbl -> put_Persistent(This,fPersistent) ) 


#define IRTCBuddy_get_Status(This,penStatus)	\
    ( (This)->lpVtbl -> get_Status(This,penStatus) ) 

#define IRTCBuddy_get_Notes(This,pbstrNotes)	\
    ( (This)->lpVtbl -> get_Notes(This,pbstrNotes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCBuddy_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddy2_INTERFACE_DEFINED__
#define __IRTCBuddy2_INTERFACE_DEFINED__

/* interface IRTCBuddy2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddy2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("102F9588-23E7-40e3-954D-CD7A1D5C0361")
    IRTCBuddy2 : public IRTCBuddy
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile2 **ppProfile) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateGroups( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumGroups **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Groups( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PresenceProperty( 
            /* [annotation][in] */ 
            _In_  RTC_PRESENCE_PROPERTY enProperty,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnumeratePresenceDevices( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumPresenceDevices **ppEnumDevices) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PresenceDevices( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppDevicesCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriptionType( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_BUDDY_SUBSCRIPTION_TYPE *penSubscriptionType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCBuddy2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCBuddy2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCBuddy2 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresentityURI )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPresentityURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresentityURI )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Persistent )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfPersistent);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Persistent )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PRESENCE_STATUS *penStatus);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Notes )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrNotes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile2 **ppProfile);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            __RPC__in IRTCBuddy2 * This);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateGroups )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumGroups **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Groups )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresenceProperty )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][in] */ 
            _In_  RTC_PRESENCE_PROPERTY enProperty,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumeratePresenceDevices )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumPresenceDevices **ppEnumDevices);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresenceDevices )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppDevicesCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubscriptionType )( 
            __RPC__in IRTCBuddy2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_BUDDY_SUBSCRIPTION_TYPE *penSubscriptionType);
        
        END_INTERFACE
    } IRTCBuddy2Vtbl;

    interface IRTCBuddy2
    {
        CONST_VTBL struct IRTCBuddy2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddy2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCBuddy2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCBuddy2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCBuddy2_get_PresentityURI(This,pbstrPresentityURI)	\
    ( (This)->lpVtbl -> get_PresentityURI(This,pbstrPresentityURI) ) 

#define IRTCBuddy2_put_PresentityURI(This,bstrPresentityURI)	\
    ( (This)->lpVtbl -> put_PresentityURI(This,bstrPresentityURI) ) 

#define IRTCBuddy2_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IRTCBuddy2_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IRTCBuddy2_get_Data(This,pbstrData)	\
    ( (This)->lpVtbl -> get_Data(This,pbstrData) ) 

#define IRTCBuddy2_put_Data(This,bstrData)	\
    ( (This)->lpVtbl -> put_Data(This,bstrData) ) 

#define IRTCBuddy2_get_Persistent(This,pfPersistent)	\
    ( (This)->lpVtbl -> get_Persistent(This,pfPersistent) ) 

#define IRTCBuddy2_put_Persistent(This,fPersistent)	\
    ( (This)->lpVtbl -> put_Persistent(This,fPersistent) ) 


#define IRTCBuddy2_get_Status(This,penStatus)	\
    ( (This)->lpVtbl -> get_Status(This,penStatus) ) 

#define IRTCBuddy2_get_Notes(This,pbstrNotes)	\
    ( (This)->lpVtbl -> get_Notes(This,pbstrNotes) ) 


#define IRTCBuddy2_get_Profile(This,ppProfile)	\
    ( (This)->lpVtbl -> get_Profile(This,ppProfile) ) 

#define IRTCBuddy2_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IRTCBuddy2_EnumerateGroups(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateGroups(This,ppEnum) ) 

#define IRTCBuddy2_get_Groups(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Groups(This,ppCollection) ) 

#define IRTCBuddy2_get_PresenceProperty(This,enProperty,pbstrProperty)	\
    ( (This)->lpVtbl -> get_PresenceProperty(This,enProperty,pbstrProperty) ) 

#define IRTCBuddy2_EnumeratePresenceDevices(This,ppEnumDevices)	\
    ( (This)->lpVtbl -> EnumeratePresenceDevices(This,ppEnumDevices) ) 

#define IRTCBuddy2_get_PresenceDevices(This,ppDevicesCollection)	\
    ( (This)->lpVtbl -> get_PresenceDevices(This,ppDevicesCollection) ) 

#define IRTCBuddy2_get_SubscriptionType(This,penSubscriptionType)	\
    ( (This)->lpVtbl -> get_SubscriptionType(This,penSubscriptionType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCBuddy2_INTERFACE_DEFINED__ */


#ifndef __IRTCWatcher_INTERFACE_DEFINED__
#define __IRTCWatcher_INTERFACE_DEFINED__

/* interface IRTCWatcher */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCWatcher;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c7cedad8-346b-4d1b-ac02-a2088df9be4f")
    IRTCWatcher : public IRTCPresenceContact
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_WATCHER_STATE *penState) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_State( 
            /* [annotation][in] */ 
            _In_  RTC_WATCHER_STATE enState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCWatcherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCWatcher * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCWatcher * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCWatcher * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresentityURI )( 
            __RPC__in IRTCWatcher * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPresentityURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresentityURI )( 
            __RPC__in IRTCWatcher * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IRTCWatcher * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IRTCWatcher * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            __RPC__in IRTCWatcher * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            __RPC__in IRTCWatcher * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Persistent )( 
            __RPC__in IRTCWatcher * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfPersistent);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Persistent )( 
            __RPC__in IRTCWatcher * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCWatcher * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_WATCHER_STATE *penState);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_State )( 
            __RPC__in IRTCWatcher * This,
            /* [annotation][in] */ 
            _In_  RTC_WATCHER_STATE enState);
        
        END_INTERFACE
    } IRTCWatcherVtbl;

    interface IRTCWatcher
    {
        CONST_VTBL struct IRTCWatcherVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCWatcher_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCWatcher_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCWatcher_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCWatcher_get_PresentityURI(This,pbstrPresentityURI)	\
    ( (This)->lpVtbl -> get_PresentityURI(This,pbstrPresentityURI) ) 

#define IRTCWatcher_put_PresentityURI(This,bstrPresentityURI)	\
    ( (This)->lpVtbl -> put_PresentityURI(This,bstrPresentityURI) ) 

#define IRTCWatcher_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IRTCWatcher_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IRTCWatcher_get_Data(This,pbstrData)	\
    ( (This)->lpVtbl -> get_Data(This,pbstrData) ) 

#define IRTCWatcher_put_Data(This,bstrData)	\
    ( (This)->lpVtbl -> put_Data(This,bstrData) ) 

#define IRTCWatcher_get_Persistent(This,pfPersistent)	\
    ( (This)->lpVtbl -> get_Persistent(This,pfPersistent) ) 

#define IRTCWatcher_put_Persistent(This,fPersistent)	\
    ( (This)->lpVtbl -> put_Persistent(This,fPersistent) ) 


#define IRTCWatcher_get_State(This,penState)	\
    ( (This)->lpVtbl -> get_State(This,penState) ) 

#define IRTCWatcher_put_State(This,enState)	\
    ( (This)->lpVtbl -> put_State(This,enState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCWatcher_INTERFACE_DEFINED__ */


#ifndef __IRTCWatcher2_INTERFACE_DEFINED__
#define __IRTCWatcher2_INTERFACE_DEFINED__

/* interface IRTCWatcher2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCWatcher2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D4D9967F-D011-4b1d-91E3-ABA78F96393D")
    IRTCWatcher2 : public IRTCWatcher
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile2 **ppProfile) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Scope( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_ACE_SCOPE *penScope) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCWatcher2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCWatcher2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCWatcher2 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresentityURI )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrPresentityURI);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PresentityURI )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrPresentityURI);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Persistent )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfPersistent);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Persistent )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fPersistent);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_WATCHER_STATE *penState);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_State )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][in] */ 
            _In_  RTC_WATCHER_STATE enState);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile2 **ppProfile);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Scope )( 
            __RPC__in IRTCWatcher2 * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_ACE_SCOPE *penScope);
        
        END_INTERFACE
    } IRTCWatcher2Vtbl;

    interface IRTCWatcher2
    {
        CONST_VTBL struct IRTCWatcher2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCWatcher2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCWatcher2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCWatcher2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCWatcher2_get_PresentityURI(This,pbstrPresentityURI)	\
    ( (This)->lpVtbl -> get_PresentityURI(This,pbstrPresentityURI) ) 

#define IRTCWatcher2_put_PresentityURI(This,bstrPresentityURI)	\
    ( (This)->lpVtbl -> put_PresentityURI(This,bstrPresentityURI) ) 

#define IRTCWatcher2_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IRTCWatcher2_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IRTCWatcher2_get_Data(This,pbstrData)	\
    ( (This)->lpVtbl -> get_Data(This,pbstrData) ) 

#define IRTCWatcher2_put_Data(This,bstrData)	\
    ( (This)->lpVtbl -> put_Data(This,bstrData) ) 

#define IRTCWatcher2_get_Persistent(This,pfPersistent)	\
    ( (This)->lpVtbl -> get_Persistent(This,pfPersistent) ) 

#define IRTCWatcher2_put_Persistent(This,fPersistent)	\
    ( (This)->lpVtbl -> put_Persistent(This,fPersistent) ) 


#define IRTCWatcher2_get_State(This,penState)	\
    ( (This)->lpVtbl -> get_State(This,penState) ) 

#define IRTCWatcher2_put_State(This,enState)	\
    ( (This)->lpVtbl -> put_State(This,enState) ) 


#define IRTCWatcher2_get_Profile(This,ppProfile)	\
    ( (This)->lpVtbl -> get_Profile(This,ppProfile) ) 

#define IRTCWatcher2_get_Scope(This,penScope)	\
    ( (This)->lpVtbl -> get_Scope(This,penScope) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCWatcher2_INTERFACE_DEFINED__ */


#ifndef __IRTCBuddyGroup_INTERFACE_DEFINED__
#define __IRTCBuddyGroup_INTERFACE_DEFINED__

/* interface IRTCBuddyGroup */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCBuddyGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60361E68-9164-4389-A4C6-D0B3925BDA5E")
    IRTCBuddyGroup : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrGroupName) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [annotation][in] */ 
            _In_  BSTR bstrGroupName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddBuddy( 
            /* [annotation][in] */ 
            _In_  IRTCBuddy *pBuddy) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveBuddy( 
            /* [annotation][in] */ 
            _In_  IRTCBuddy *pBuddy) = 0;
        
        virtual /* [helpstring][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateBuddies( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumBuddies **ppEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Buddies( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Data( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Data( 
            /* [annotation][in] */ 
            _In_  BSTR bstrData) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile2 **ppProfile) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCBuddyGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCBuddyGroup * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCBuddyGroup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCBuddyGroup * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in IRTCBuddyGroup * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrGroupName);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            __RPC__in IRTCBuddyGroup * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrGroupName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddBuddy )( 
            __RPC__in IRTCBuddyGroup * This,
            /* [annotation][in] */ 
            _In_  IRTCBuddy *pBuddy);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveBuddy )( 
            __RPC__in IRTCBuddyGroup * This,
            /* [annotation][in] */ 
            _In_  IRTCBuddy *pBuddy);
        
        /* [helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateBuddies )( 
            __RPC__in IRTCBuddyGroup * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumBuddies **ppEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buddies )( 
            __RPC__in IRTCBuddyGroup * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            __RPC__in IRTCBuddyGroup * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrData);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            __RPC__in IRTCBuddyGroup * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrData);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            __RPC__in IRTCBuddyGroup * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile2 **ppProfile);
        
        END_INTERFACE
    } IRTCBuddyGroupVtbl;

    interface IRTCBuddyGroup
    {
        CONST_VTBL struct IRTCBuddyGroupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCBuddyGroup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCBuddyGroup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCBuddyGroup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCBuddyGroup_get_Name(This,pbstrGroupName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrGroupName) ) 

#define IRTCBuddyGroup_put_Name(This,bstrGroupName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrGroupName) ) 

#define IRTCBuddyGroup_AddBuddy(This,pBuddy)	\
    ( (This)->lpVtbl -> AddBuddy(This,pBuddy) ) 

#define IRTCBuddyGroup_RemoveBuddy(This,pBuddy)	\
    ( (This)->lpVtbl -> RemoveBuddy(This,pBuddy) ) 

#define IRTCBuddyGroup_EnumerateBuddies(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateBuddies(This,ppEnum) ) 

#define IRTCBuddyGroup_get_Buddies(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Buddies(This,ppCollection) ) 

#define IRTCBuddyGroup_get_Data(This,pbstrData)	\
    ( (This)->lpVtbl -> get_Data(This,pbstrData) ) 

#define IRTCBuddyGroup_put_Data(This,bstrData)	\
    ( (This)->lpVtbl -> put_Data(This,bstrData) ) 

#define IRTCBuddyGroup_get_Profile(This,ppProfile)	\
    ( (This)->lpVtbl -> get_Profile(This,ppProfile) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCBuddyGroup_INTERFACE_DEFINED__ */


#ifndef __IRTCEventNotification_INTERFACE_DEFINED__
#define __IRTCEventNotification_INTERFACE_DEFINED__

/* interface IRTCEventNotification */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCEventNotification;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("13fa24c7-5748-4b21-91f5-7397609ce747")
    IRTCEventNotification : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Event( 
            /* [annotation][in] */ 
            _In_  RTC_EVENT RTCEvent,
            /* [annotation][in] */ 
            _In_  IDispatch *pEvent) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCEventNotificationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCEventNotification * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCEventNotification * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCEventNotification * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Event )( 
            __RPC__in IRTCEventNotification * This,
            /* [annotation][in] */ 
            _In_  RTC_EVENT RTCEvent,
            /* [annotation][in] */ 
            _In_  IDispatch *pEvent);
        
        END_INTERFACE
    } IRTCEventNotificationVtbl;

    interface IRTCEventNotification
    {
        CONST_VTBL struct IRTCEventNotificationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEventNotification_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCEventNotification_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCEventNotification_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCEventNotification_Event(This,RTCEvent,pEvent)	\
    ( (This)->lpVtbl -> Event(This,RTCEvent,pEvent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCEventNotification_INTERFACE_DEFINED__ */


#ifndef __IRTCPortManager_INTERFACE_DEFINED__
#define __IRTCPortManager_INTERFACE_DEFINED__

/* interface IRTCPortManager */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCPortManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA77C14B-6208-43ca-8DDF-5B60A0A69FAC")
    IRTCPortManager : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMapping( 
            /* [annotation][in] */ 
            _In_  BSTR bstrRemoteAddress,
            /* [annotation][in] */ 
            _In_  RTC_PORT_TYPE enPortType,
            /* [annotation][out][in] */ 
            _Inout_  BSTR *pbstrInternalLocalAddress,
            /* [annotation][out][in] */ 
            _Inout_  long *plInternalLocalPort,
            /* [annotation][out][in] */ 
            _Inout_  BSTR *pbstrExternalLocalAddress,
            /* [annotation][out][in] */ 
            _Inout_  long *plExternalLocalPort) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateRemoteAddress( 
            /* [annotation][in] */ 
            _In_  BSTR bstrRemoteAddress,
            /* [annotation][in] */ 
            _In_  BSTR bstrInternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lInternalLocalPort,
            /* [annotation][in] */ 
            _In_  BSTR bstrExternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lExternalLocalPort) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReleaseMapping( 
            /* [annotation][in] */ 
            _In_  BSTR bstrInternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lInternalLocalPort,
            /* [annotation][in] */ 
            _In_  BSTR bstrExternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lExternalLocalAddress) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCPortManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCPortManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCPortManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCPortManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMapping )( 
            __RPC__in IRTCPortManager * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrRemoteAddress,
            /* [annotation][in] */ 
            _In_  RTC_PORT_TYPE enPortType,
            /* [annotation][out][in] */ 
            _Inout_  BSTR *pbstrInternalLocalAddress,
            /* [annotation][out][in] */ 
            _Inout_  long *plInternalLocalPort,
            /* [annotation][out][in] */ 
            _Inout_  BSTR *pbstrExternalLocalAddress,
            /* [annotation][out][in] */ 
            _Inout_  long *plExternalLocalPort);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateRemoteAddress )( 
            __RPC__in IRTCPortManager * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrRemoteAddress,
            /* [annotation][in] */ 
            _In_  BSTR bstrInternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lInternalLocalPort,
            /* [annotation][in] */ 
            _In_  BSTR bstrExternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lExternalLocalPort);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseMapping )( 
            __RPC__in IRTCPortManager * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrInternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lInternalLocalPort,
            /* [annotation][in] */ 
            _In_  BSTR bstrExternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lExternalLocalAddress);
        
        END_INTERFACE
    } IRTCPortManagerVtbl;

    interface IRTCPortManager
    {
        CONST_VTBL struct IRTCPortManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPortManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCPortManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCPortManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCPortManager_GetMapping(This,bstrRemoteAddress,enPortType,pbstrInternalLocalAddress,plInternalLocalPort,pbstrExternalLocalAddress,plExternalLocalPort)	\
    ( (This)->lpVtbl -> GetMapping(This,bstrRemoteAddress,enPortType,pbstrInternalLocalAddress,plInternalLocalPort,pbstrExternalLocalAddress,plExternalLocalPort) ) 

#define IRTCPortManager_UpdateRemoteAddress(This,bstrRemoteAddress,bstrInternalLocalAddress,lInternalLocalPort,bstrExternalLocalAddress,lExternalLocalPort)	\
    ( (This)->lpVtbl -> UpdateRemoteAddress(This,bstrRemoteAddress,bstrInternalLocalAddress,lInternalLocalPort,bstrExternalLocalAddress,lExternalLocalPort) ) 

#define IRTCPortManager_ReleaseMapping(This,bstrInternalLocalAddress,lInternalLocalPort,bstrExternalLocalAddress,lExternalLocalAddress)	\
    ( (This)->lpVtbl -> ReleaseMapping(This,bstrInternalLocalAddress,lInternalLocalPort,bstrExternalLocalAddress,lExternalLocalAddress) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCPortManager_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionPortManagement_INTERFACE_DEFINED__
#define __IRTCSessionPortManagement_INTERFACE_DEFINED__

/* interface IRTCSessionPortManagement */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionPortManagement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a072f1d6-0286-4e1f-85f2-17a2948456ec")
    IRTCSessionPortManagement : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPortManager( 
            /* [annotation][in] */ 
            _In_  IRTCPortManager *pPortManager) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCSessionPortManagementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCSessionPortManagement * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCSessionPortManagement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCSessionPortManagement * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPortManager )( 
            __RPC__in IRTCSessionPortManagement * This,
            /* [annotation][in] */ 
            _In_  IRTCPortManager *pPortManager);
        
        END_INTERFACE
    } IRTCSessionPortManagementVtbl;

    interface IRTCSessionPortManagement
    {
        CONST_VTBL struct IRTCSessionPortManagementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionPortManagement_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCSessionPortManagement_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCSessionPortManagement_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCSessionPortManagement_SetPortManager(This,pPortManager)	\
    ( (This)->lpVtbl -> SetPortManager(This,pPortManager) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCSessionPortManagement_INTERFACE_DEFINED__ */


#ifndef __IRTCClientPortManagement_INTERFACE_DEFINED__
#define __IRTCClientPortManagement_INTERFACE_DEFINED__

/* interface IRTCClientPortManagement */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCClientPortManagement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d5df3f03-4bde-4417-aefe-71177bdaea66")
    IRTCClientPortManagement : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartListenAddressAndPort( 
            /* [annotation][in] */ 
            _In_  BSTR bstrInternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lInternalLocalPort) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopListenAddressAndPort( 
            /* [annotation][in] */ 
            _In_  BSTR bstrInternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lInternalLocalPort) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPortRange( 
            /* [annotation][in] */ 
            _In_  RTC_PORT_TYPE enPortType,
            /* [annotation][out] */ 
            _Out_  long *plMinValue,
            /* [annotation][out] */ 
            _Out_  long *plMaxValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCClientPortManagementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCClientPortManagement * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCClientPortManagement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCClientPortManagement * This);
        
        HRESULT ( STDMETHODCALLTYPE *StartListenAddressAndPort )( 
            __RPC__in IRTCClientPortManagement * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrInternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lInternalLocalPort);
        
        HRESULT ( STDMETHODCALLTYPE *StopListenAddressAndPort )( 
            __RPC__in IRTCClientPortManagement * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrInternalLocalAddress,
            /* [annotation][in] */ 
            _In_  long lInternalLocalPort);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPortRange )( 
            __RPC__in IRTCClientPortManagement * This,
            /* [annotation][in] */ 
            _In_  RTC_PORT_TYPE enPortType,
            /* [annotation][out] */ 
            _Out_  long *plMinValue,
            /* [annotation][out] */ 
            _Out_  long *plMaxValue);
        
        END_INTERFACE
    } IRTCClientPortManagementVtbl;

    interface IRTCClientPortManagement
    {
        CONST_VTBL struct IRTCClientPortManagementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCClientPortManagement_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCClientPortManagement_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCClientPortManagement_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCClientPortManagement_StartListenAddressAndPort(This,bstrInternalLocalAddress,lInternalLocalPort)	\
    ( (This)->lpVtbl -> StartListenAddressAndPort(This,bstrInternalLocalAddress,lInternalLocalPort) ) 

#define IRTCClientPortManagement_StopListenAddressAndPort(This,bstrInternalLocalAddress,lInternalLocalPort)	\
    ( (This)->lpVtbl -> StopListenAddressAndPort(This,bstrInternalLocalAddress,lInternalLocalPort) ) 

#define IRTCClientPortManagement_GetPortRange(This,enPortType,plMinValue,plMaxValue)	\
    ( (This)->lpVtbl -> GetPortRange(This,enPortType,plMinValue,plMaxValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCClientPortManagement_INTERFACE_DEFINED__ */


#ifndef __IRTCUserSearch_INTERFACE_DEFINED__
#define __IRTCUserSearch_INTERFACE_DEFINED__

/* interface IRTCUserSearch */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCUserSearch;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B619882B-860C-4db4-BE1B-693B6505BBE5")
    IRTCUserSearch : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateQuery( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCUserSearchQuery **ppQuery) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ExecuteSearch( 
            /* [annotation][in] */ 
            _In_  IRTCUserSearchQuery *pQuery,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCUserSearchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCUserSearch * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCUserSearch * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCUserSearch * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateQuery )( 
            __RPC__in IRTCUserSearch * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCUserSearchQuery **ppQuery);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ExecuteSearch )( 
            __RPC__in IRTCUserSearch * This,
            /* [annotation][in] */ 
            _In_  IRTCUserSearchQuery *pQuery,
            /* [annotation][in] */ 
            _In_  IRTCProfile *pProfile,
            /* [annotation][in] */ 
            _In_  LONG_PTR lCookie);
        
        END_INTERFACE
    } IRTCUserSearchVtbl;

    interface IRTCUserSearch
    {
        CONST_VTBL struct IRTCUserSearchVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCUserSearch_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCUserSearch_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCUserSearch_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCUserSearch_CreateQuery(This,ppQuery)	\
    ( (This)->lpVtbl -> CreateQuery(This,ppQuery) ) 

#define IRTCUserSearch_ExecuteSearch(This,pQuery,pProfile,lCookie)	\
    ( (This)->lpVtbl -> ExecuteSearch(This,pQuery,pProfile,lCookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCUserSearch_INTERFACE_DEFINED__ */


#ifndef __IRTCUserSearchQuery_INTERFACE_DEFINED__
#define __IRTCUserSearchQuery_INTERFACE_DEFINED__

/* interface IRTCUserSearchQuery */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCUserSearchQuery;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("288300F5-D23A-4365-9A73-9985C98C2881")
    IRTCUserSearchQuery : public IUnknown
    {
    public:
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SearchTerm( 
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrValue) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SearchTerm( 
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrValue) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SearchTerms( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrNames) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SearchPreference( 
            /* [annotation][in] */ 
            _In_  RTC_USER_SEARCH_PREFERENCE enPreference,
            /* [annotation][in] */ 
            _In_  long lValue) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SearchPreference( 
            /* [annotation][in] */ 
            _In_  RTC_USER_SEARCH_PREFERENCE enPreference,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plValue) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SearchDomain( 
            /* [annotation][in] */ 
            _In_  BSTR bstrDomain) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SearchDomain( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDomain) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCUserSearchQueryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCUserSearchQuery * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCUserSearchQuery * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCUserSearchQuery * This);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SearchTerm )( 
            __RPC__in IRTCUserSearchQuery * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][in] */ 
            _In_  BSTR bstrValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchTerm )( 
            __RPC__in IRTCUserSearchQuery * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrName,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchTerms )( 
            __RPC__in IRTCUserSearchQuery * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrNames);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SearchPreference )( 
            __RPC__in IRTCUserSearchQuery * This,
            /* [annotation][in] */ 
            _In_  RTC_USER_SEARCH_PREFERENCE enPreference,
            /* [annotation][in] */ 
            _In_  long lValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchPreference )( 
            __RPC__in IRTCUserSearchQuery * This,
            /* [annotation][in] */ 
            _In_  RTC_USER_SEARCH_PREFERENCE enPreference,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plValue);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SearchDomain )( 
            __RPC__in IRTCUserSearchQuery * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrDomain);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchDomain )( 
            __RPC__in IRTCUserSearchQuery * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrDomain);
        
        END_INTERFACE
    } IRTCUserSearchQueryVtbl;

    interface IRTCUserSearchQuery
    {
        CONST_VTBL struct IRTCUserSearchQueryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCUserSearchQuery_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCUserSearchQuery_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCUserSearchQuery_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCUserSearchQuery_put_SearchTerm(This,bstrName,bstrValue)	\
    ( (This)->lpVtbl -> put_SearchTerm(This,bstrName,bstrValue) ) 

#define IRTCUserSearchQuery_get_SearchTerm(This,bstrName,pbstrValue)	\
    ( (This)->lpVtbl -> get_SearchTerm(This,bstrName,pbstrValue) ) 

#define IRTCUserSearchQuery_get_SearchTerms(This,pbstrNames)	\
    ( (This)->lpVtbl -> get_SearchTerms(This,pbstrNames) ) 

#define IRTCUserSearchQuery_put_SearchPreference(This,enPreference,lValue)	\
    ( (This)->lpVtbl -> put_SearchPreference(This,enPreference,lValue) ) 

#define IRTCUserSearchQuery_get_SearchPreference(This,enPreference,plValue)	\
    ( (This)->lpVtbl -> get_SearchPreference(This,enPreference,plValue) ) 

#define IRTCUserSearchQuery_put_SearchDomain(This,bstrDomain)	\
    ( (This)->lpVtbl -> put_SearchDomain(This,bstrDomain) ) 

#define IRTCUserSearchQuery_get_SearchDomain(This,pbstrDomain)	\
    ( (This)->lpVtbl -> get_SearchDomain(This,pbstrDomain) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCUserSearchQuery_INTERFACE_DEFINED__ */


#ifndef __IRTCUserSearchResult_INTERFACE_DEFINED__
#define __IRTCUserSearchResult_INTERFACE_DEFINED__

/* interface IRTCUserSearchResult */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCUserSearchResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("851278B2-9592-480f-8DB5-2DE86B26B54D")
    IRTCUserSearchResult : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [annotation][in] */ 
            _In_  RTC_USER_SEARCH_COLUMN enColumn,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCUserSearchResultVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCUserSearchResult * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCUserSearchResult * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCUserSearchResult * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            __RPC__in IRTCUserSearchResult * This,
            /* [annotation][in] */ 
            _In_  RTC_USER_SEARCH_COLUMN enColumn,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrValue);
        
        END_INTERFACE
    } IRTCUserSearchResultVtbl;

    interface IRTCUserSearchResult
    {
        CONST_VTBL struct IRTCUserSearchResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCUserSearchResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCUserSearchResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCUserSearchResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCUserSearchResult_get_Value(This,enColumn,pbstrValue)	\
    ( (This)->lpVtbl -> get_Value(This,enColumn,pbstrValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCUserSearchResult_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumUserSearchResults_INTERFACE_DEFINED__
#define __IRTCEnumUserSearchResults_INTERFACE_DEFINED__

/* interface IRTCEnumUserSearchResults */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumUserSearchResults;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("83D4D877-AA5D-4a5b-8D0E-002A8067E0E8")
    IRTCEnumUserSearchResults : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCUserSearchResult **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumUserSearchResults **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCEnumUserSearchResultsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCEnumUserSearchResults * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCEnumUserSearchResults * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCEnumUserSearchResults * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IRTCEnumUserSearchResults * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCUserSearchResult **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IRTCEnumUserSearchResults * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IRTCEnumUserSearchResults * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IRTCEnumUserSearchResults * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumUserSearchResults **ppEnum);
        
        END_INTERFACE
    } IRTCEnumUserSearchResultsVtbl;

    interface IRTCEnumUserSearchResults
    {
        CONST_VTBL struct IRTCEnumUserSearchResultsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumUserSearchResults_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCEnumUserSearchResults_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCEnumUserSearchResults_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCEnumUserSearchResults_Next(This,celt,ppElements,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched) ) 

#define IRTCEnumUserSearchResults_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IRTCEnumUserSearchResults_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IRTCEnumUserSearchResults_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCEnumUserSearchResults_INTERFACE_DEFINED__ */


#ifndef __IRTCUserSearchResultsEvent_INTERFACE_DEFINED__
#define __IRTCUserSearchResultsEvent_INTERFACE_DEFINED__

/* interface IRTCUserSearchResultsEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCUserSearchResultsEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D8C8C3CD-7FAC-4088-81C5-C24CBC0938E3")
    IRTCUserSearchResultsEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][hidden] */ HRESULT STDMETHODCALLTYPE EnumerateResults( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumUserSearchResults **ppEnum) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Results( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile2 **ppProfile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Query( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCUserSearchQuery **ppQuery) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cookie( 
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG_PTR *plCookie) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MoreAvailable( 
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfMoreAvailable) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCUserSearchResultsEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCUserSearchResultsEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCUserSearchResultsEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCUserSearchResultsEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCUserSearchResultsEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCUserSearchResultsEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCUserSearchResultsEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCUserSearchResultsEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][hidden] */ HRESULT ( STDMETHODCALLTYPE *EnumerateResults )( 
            __RPC__in IRTCUserSearchResultsEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumUserSearchResults **ppEnum);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Results )( 
            __RPC__in IRTCUserSearchResultsEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCCollection **ppCollection);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            __RPC__in IRTCUserSearchResultsEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCProfile2 **ppProfile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Query )( 
            __RPC__in IRTCUserSearchResultsEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCUserSearchQuery **ppQuery);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cookie )( 
            __RPC__in IRTCUserSearchResultsEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  LONG_PTR *plCookie);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCUserSearchResultsEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MoreAvailable )( 
            __RPC__in IRTCUserSearchResultsEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  VARIANT_BOOL *pfMoreAvailable);
        
        END_INTERFACE
    } IRTCUserSearchResultsEventVtbl;

    interface IRTCUserSearchResultsEvent
    {
        CONST_VTBL struct IRTCUserSearchResultsEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCUserSearchResultsEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCUserSearchResultsEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCUserSearchResultsEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCUserSearchResultsEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCUserSearchResultsEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCUserSearchResultsEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCUserSearchResultsEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCUserSearchResultsEvent_EnumerateResults(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumerateResults(This,ppEnum) ) 

#define IRTCUserSearchResultsEvent_get_Results(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Results(This,ppCollection) ) 

#define IRTCUserSearchResultsEvent_get_Profile(This,ppProfile)	\
    ( (This)->lpVtbl -> get_Profile(This,ppProfile) ) 

#define IRTCUserSearchResultsEvent_get_Query(This,ppQuery)	\
    ( (This)->lpVtbl -> get_Query(This,ppQuery) ) 

#define IRTCUserSearchResultsEvent_get_Cookie(This,plCookie)	\
    ( (This)->lpVtbl -> get_Cookie(This,plCookie) ) 

#define IRTCUserSearchResultsEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCUserSearchResultsEvent_get_MoreAvailable(This,pfMoreAvailable)	\
    ( (This)->lpVtbl -> get_MoreAvailable(This,pfMoreAvailable) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCUserSearchResultsEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionReferStatusEvent_INTERFACE_DEFINED__
#define __IRTCSessionReferStatusEvent_INTERFACE_DEFINED__

/* interface IRTCSessionReferStatusEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionReferStatusEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3D8FC2CD-5D76-44AB-BB68-2A80353B34A2")
    IRTCSessionReferStatusEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReferStatus( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SESSION_REFER_STATUS *penReferStatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusText( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCSessionReferStatusEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCSessionReferStatusEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCSessionReferStatusEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCSessionReferStatusEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCSessionReferStatusEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCSessionReferStatusEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCSessionReferStatusEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionReferStatusEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __RPC__in IRTCSessionReferStatusEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferStatus )( 
            __RPC__in IRTCSessionReferStatusEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_SESSION_REFER_STATUS *penReferStatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            __RPC__in IRTCSessionReferStatusEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  long *plStatusCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusText )( 
            __RPC__in IRTCSessionReferStatusEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrStatusText);
        
        END_INTERFACE
    } IRTCSessionReferStatusEventVtbl;

    interface IRTCSessionReferStatusEvent
    {
        CONST_VTBL struct IRTCSessionReferStatusEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionReferStatusEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCSessionReferStatusEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCSessionReferStatusEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCSessionReferStatusEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCSessionReferStatusEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCSessionReferStatusEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCSessionReferStatusEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCSessionReferStatusEvent_get_Session(This,ppSession)	\
    ( (This)->lpVtbl -> get_Session(This,ppSession) ) 

#define IRTCSessionReferStatusEvent_get_ReferStatus(This,penReferStatus)	\
    ( (This)->lpVtbl -> get_ReferStatus(This,penReferStatus) ) 

#define IRTCSessionReferStatusEvent_get_StatusCode(This,plStatusCode)	\
    ( (This)->lpVtbl -> get_StatusCode(This,plStatusCode) ) 

#define IRTCSessionReferStatusEvent_get_StatusText(This,pbstrStatusText)	\
    ( (This)->lpVtbl -> get_StatusText(This,pbstrStatusText) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCSessionReferStatusEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionReferredEvent_INTERFACE_DEFINED__
#define __IRTCSessionReferredEvent_INTERFACE_DEFINED__

/* interface IRTCSessionReferredEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionReferredEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("176A6828-4FCC-4F28-A862-04597A6CF1C4")
    IRTCSessionReferredEvent : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Session( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReferredByURI( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrReferredByURI) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReferToURI( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrReferoURI) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReferCookie( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrReferCookie) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Accept( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reject( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetReferredSessionState( 
            /* [annotation][in] */ 
            _In_  RTC_SESSION_STATE enState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCSessionReferredEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCSessionReferredEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCSessionReferredEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCSessionReferredEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCSessionReferredEvent * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCSessionReferredEvent * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCSessionReferredEvent * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCSessionReferredEvent * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            __RPC__in IRTCSessionReferredEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCSession2 **ppSession);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferredByURI )( 
            __RPC__in IRTCSessionReferredEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrReferredByURI);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferToURI )( 
            __RPC__in IRTCSessionReferredEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrReferoURI);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferCookie )( 
            __RPC__in IRTCSessionReferredEvent * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrReferCookie);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Accept )( 
            __RPC__in IRTCSessionReferredEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reject )( 
            __RPC__in IRTCSessionReferredEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetReferredSessionState )( 
            __RPC__in IRTCSessionReferredEvent * This,
            /* [annotation][in] */ 
            _In_  RTC_SESSION_STATE enState);
        
        END_INTERFACE
    } IRTCSessionReferredEventVtbl;

    interface IRTCSessionReferredEvent
    {
        CONST_VTBL struct IRTCSessionReferredEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionReferredEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCSessionReferredEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCSessionReferredEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCSessionReferredEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCSessionReferredEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCSessionReferredEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCSessionReferredEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRTCSessionReferredEvent_get_Session(This,ppSession)	\
    ( (This)->lpVtbl -> get_Session(This,ppSession) ) 

#define IRTCSessionReferredEvent_get_ReferredByURI(This,pbstrReferredByURI)	\
    ( (This)->lpVtbl -> get_ReferredByURI(This,pbstrReferredByURI) ) 

#define IRTCSessionReferredEvent_get_ReferToURI(This,pbstrReferoURI)	\
    ( (This)->lpVtbl -> get_ReferToURI(This,pbstrReferoURI) ) 

#define IRTCSessionReferredEvent_get_ReferCookie(This,pbstrReferCookie)	\
    ( (This)->lpVtbl -> get_ReferCookie(This,pbstrReferCookie) ) 

#define IRTCSessionReferredEvent_Accept(This)	\
    ( (This)->lpVtbl -> Accept(This) ) 

#define IRTCSessionReferredEvent_Reject(This)	\
    ( (This)->lpVtbl -> Reject(This) ) 

#define IRTCSessionReferredEvent_SetReferredSessionState(This,enState)	\
    ( (This)->lpVtbl -> SetReferredSessionState(This,enState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCSessionReferredEvent_INTERFACE_DEFINED__ */


#ifndef __IRTCSessionDescriptionManager_INTERFACE_DEFINED__
#define __IRTCSessionDescriptionManager_INTERFACE_DEFINED__

/* interface IRTCSessionDescriptionManager */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCSessionDescriptionManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA7F518E-D336-4070-93A6-865395C843F9")
    IRTCSessionDescriptionManager : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EvaluateSessionDescription( 
            /* [annotation][in] */ 
            _In_  BSTR bstrContentType,
            /* [annotation][in] */ 
            _In_  BSTR bstrSessionDescription,
            /* [annotation][out][in] */ 
            _Inout_  VARIANT_BOOL *pfApplicationSession) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCSessionDescriptionManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCSessionDescriptionManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCSessionDescriptionManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCSessionDescriptionManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EvaluateSessionDescription )( 
            __RPC__in IRTCSessionDescriptionManager * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrContentType,
            /* [annotation][in] */ 
            _In_  BSTR bstrSessionDescription,
            /* [annotation][out][in] */ 
            _Inout_  VARIANT_BOOL *pfApplicationSession);
        
        END_INTERFACE
    } IRTCSessionDescriptionManagerVtbl;

    interface IRTCSessionDescriptionManager
    {
        CONST_VTBL struct IRTCSessionDescriptionManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCSessionDescriptionManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCSessionDescriptionManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCSessionDescriptionManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCSessionDescriptionManager_EvaluateSessionDescription(This,bstrContentType,bstrSessionDescription,pfApplicationSession)	\
    ( (This)->lpVtbl -> EvaluateSessionDescription(This,bstrContentType,bstrSessionDescription,pfApplicationSession) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCSessionDescriptionManager_INTERFACE_DEFINED__ */


#ifndef __IRTCEnumPresenceDevices_INTERFACE_DEFINED__
#define __IRTCEnumPresenceDevices_INTERFACE_DEFINED__

/* interface IRTCEnumPresenceDevices */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IRTCEnumPresenceDevices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("708C2AB7-8BF8-42f8-8C7D-635197AD5539")
    IRTCEnumPresenceDevices : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCPresenceDevice **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumPresenceDevices **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCEnumPresenceDevicesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCEnumPresenceDevices * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCEnumPresenceDevices * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCEnumPresenceDevices * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            __RPC__in IRTCEnumPresenceDevices * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][size_is][out] */ 
            _Out_writes_(celt)  IRTCPresenceDevice **ppElements,
            /* [full][out][in] */ __RPC__inout_opt ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in IRTCEnumPresenceDevices * This);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in IRTCEnumPresenceDevices * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in IRTCEnumPresenceDevices * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  IRTCEnumPresenceDevices **ppEnum);
        
        END_INTERFACE
    } IRTCEnumPresenceDevicesVtbl;

    interface IRTCEnumPresenceDevices
    {
        CONST_VTBL struct IRTCEnumPresenceDevicesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCEnumPresenceDevices_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCEnumPresenceDevices_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCEnumPresenceDevices_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCEnumPresenceDevices_Next(This,celt,ppElements,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,ppElements,pceltFetched) ) 

#define IRTCEnumPresenceDevices_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IRTCEnumPresenceDevices_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IRTCEnumPresenceDevices_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCEnumPresenceDevices_INTERFACE_DEFINED__ */


#ifndef __IRTCPresenceDevice_INTERFACE_DEFINED__
#define __IRTCPresenceDevice_INTERFACE_DEFINED__

/* interface IRTCPresenceDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRTCPresenceDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BC6A90DD-AD9A-48da-9B0C-2515E38521AD")
    IRTCPresenceDevice : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PRESENCE_STATUS *penStatus) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Notes( 
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrNotes) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PresenceProperty( 
            /* [annotation][in] */ 
            _In_  RTC_PRESENCE_PROPERTY enProperty,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPresenceData( 
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrNamespace,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRTCPresenceDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCPresenceDevice * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCPresenceDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCPresenceDevice * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            __RPC__in IRTCPresenceDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  RTC_PRESENCE_STATUS *penStatus);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Notes )( 
            __RPC__in IRTCPresenceDevice * This,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrNotes);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PresenceProperty )( 
            __RPC__in IRTCPresenceDevice * This,
            /* [annotation][in] */ 
            _In_  RTC_PRESENCE_PROPERTY enProperty,
            /* [annotation][retval][out] */ 
            _Out_retval_  BSTR *pbstrProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPresenceData )( 
            __RPC__in IRTCPresenceDevice * This,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrNamespace,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrData);
        
        END_INTERFACE
    } IRTCPresenceDeviceVtbl;

    interface IRTCPresenceDevice
    {
        CONST_VTBL struct IRTCPresenceDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCPresenceDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCPresenceDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCPresenceDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCPresenceDevice_get_Status(This,penStatus)	\
    ( (This)->lpVtbl -> get_Status(This,penStatus) ) 

#define IRTCPresenceDevice_get_Notes(This,pbstrNotes)	\
    ( (This)->lpVtbl -> get_Notes(This,pbstrNotes) ) 

#define IRTCPresenceDevice_get_PresenceProperty(This,enProperty,pbstrProperty)	\
    ( (This)->lpVtbl -> get_PresenceProperty(This,enProperty,pbstrProperty) ) 

#define IRTCPresenceDevice_GetPresenceData(This,pbstrNamespace,pbstrData)	\
    ( (This)->lpVtbl -> GetPresenceData(This,pbstrNamespace,pbstrData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRTCPresenceDevice_INTERFACE_DEFINED__ */



#ifndef __RTCCORELib_LIBRARY_DEFINED__
#define __RTCCORELib_LIBRARY_DEFINED__

/* library RTCCORELib */
/* [helpstring][version][uuid] */ 

























































EXTERN_C const IID LIBID_RTCCORELib;

#ifndef __IRTCDispatchEventNotification_DISPINTERFACE_DEFINED__
#define __IRTCDispatchEventNotification_DISPINTERFACE_DEFINED__

/* dispinterface IRTCDispatchEventNotification */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_IRTCDispatchEventNotification;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("176ddfbe-fec0-4d55-bc87-84cff1ef7f91")
    IRTCDispatchEventNotification : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IRTCDispatchEventNotificationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IRTCDispatchEventNotification * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IRTCDispatchEventNotification * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IRTCDispatchEventNotification * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in IRTCDispatchEventNotification * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in IRTCDispatchEventNotification * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in IRTCDispatchEventNotification * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRTCDispatchEventNotification * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IRTCDispatchEventNotificationVtbl;

    interface IRTCDispatchEventNotification
    {
        CONST_VTBL struct IRTCDispatchEventNotificationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTCDispatchEventNotification_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRTCDispatchEventNotification_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRTCDispatchEventNotification_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRTCDispatchEventNotification_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRTCDispatchEventNotification_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRTCDispatchEventNotification_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRTCDispatchEventNotification_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IRTCDispatchEventNotification_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_RTCClient;

#ifdef __cplusplus

class DECLSPEC_UUID("7a42ea29-a2b7-40c4-b091-f6f024aa89be")
RTCClient;
#endif
#endif /* __RTCCORELib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_rtccore_0000_0064 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_rtccore_0000_0064_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_rtccore_0000_0064_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     __RPC__in unsigned long *, unsigned long            , __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     __RPC__in unsigned long *, __RPC__in VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



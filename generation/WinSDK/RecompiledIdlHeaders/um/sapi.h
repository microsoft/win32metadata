

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

#ifndef __sapi_h__
#define __sapi_h__

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

#ifndef __ISpNotifySource_FWD_DEFINED__
#define __ISpNotifySource_FWD_DEFINED__
typedef interface ISpNotifySource ISpNotifySource;

#endif 	/* __ISpNotifySource_FWD_DEFINED__ */


#ifndef __ISpNotifySink_FWD_DEFINED__
#define __ISpNotifySink_FWD_DEFINED__
typedef interface ISpNotifySink ISpNotifySink;

#endif 	/* __ISpNotifySink_FWD_DEFINED__ */


#ifndef __ISpNotifyTranslator_FWD_DEFINED__
#define __ISpNotifyTranslator_FWD_DEFINED__
typedef interface ISpNotifyTranslator ISpNotifyTranslator;

#endif 	/* __ISpNotifyTranslator_FWD_DEFINED__ */


#ifndef __ISpDataKey_FWD_DEFINED__
#define __ISpDataKey_FWD_DEFINED__
typedef interface ISpDataKey ISpDataKey;

#endif 	/* __ISpDataKey_FWD_DEFINED__ */


#ifndef __ISpRegDataKey_FWD_DEFINED__
#define __ISpRegDataKey_FWD_DEFINED__
typedef interface ISpRegDataKey ISpRegDataKey;

#endif 	/* __ISpRegDataKey_FWD_DEFINED__ */


#ifndef __ISpObjectTokenCategory_FWD_DEFINED__
#define __ISpObjectTokenCategory_FWD_DEFINED__
typedef interface ISpObjectTokenCategory ISpObjectTokenCategory;

#endif 	/* __ISpObjectTokenCategory_FWD_DEFINED__ */


#ifndef __ISpObjectToken_FWD_DEFINED__
#define __ISpObjectToken_FWD_DEFINED__
typedef interface ISpObjectToken ISpObjectToken;

#endif 	/* __ISpObjectToken_FWD_DEFINED__ */


#ifndef __ISpObjectTokenInit_FWD_DEFINED__
#define __ISpObjectTokenInit_FWD_DEFINED__
typedef interface ISpObjectTokenInit ISpObjectTokenInit;

#endif 	/* __ISpObjectTokenInit_FWD_DEFINED__ */


#ifndef __IEnumSpObjectTokens_FWD_DEFINED__
#define __IEnumSpObjectTokens_FWD_DEFINED__
typedef interface IEnumSpObjectTokens IEnumSpObjectTokens;

#endif 	/* __IEnumSpObjectTokens_FWD_DEFINED__ */


#ifndef __ISpObjectWithToken_FWD_DEFINED__
#define __ISpObjectWithToken_FWD_DEFINED__
typedef interface ISpObjectWithToken ISpObjectWithToken;

#endif 	/* __ISpObjectWithToken_FWD_DEFINED__ */


#ifndef __ISpResourceManager_FWD_DEFINED__
#define __ISpResourceManager_FWD_DEFINED__
typedef interface ISpResourceManager ISpResourceManager;

#endif 	/* __ISpResourceManager_FWD_DEFINED__ */


#ifndef __ISpEventSource_FWD_DEFINED__
#define __ISpEventSource_FWD_DEFINED__
typedef interface ISpEventSource ISpEventSource;

#endif 	/* __ISpEventSource_FWD_DEFINED__ */


#ifndef __ISpEventSource2_FWD_DEFINED__
#define __ISpEventSource2_FWD_DEFINED__
typedef interface ISpEventSource2 ISpEventSource2;

#endif 	/* __ISpEventSource2_FWD_DEFINED__ */


#ifndef __ISpEventSink_FWD_DEFINED__
#define __ISpEventSink_FWD_DEFINED__
typedef interface ISpEventSink ISpEventSink;

#endif 	/* __ISpEventSink_FWD_DEFINED__ */


#ifndef __ISpStreamFormat_FWD_DEFINED__
#define __ISpStreamFormat_FWD_DEFINED__
typedef interface ISpStreamFormat ISpStreamFormat;

#endif 	/* __ISpStreamFormat_FWD_DEFINED__ */


#ifndef __ISpStream_FWD_DEFINED__
#define __ISpStream_FWD_DEFINED__
typedef interface ISpStream ISpStream;

#endif 	/* __ISpStream_FWD_DEFINED__ */


#ifndef __ISpStreamFormatConverter_FWD_DEFINED__
#define __ISpStreamFormatConverter_FWD_DEFINED__
typedef interface ISpStreamFormatConverter ISpStreamFormatConverter;

#endif 	/* __ISpStreamFormatConverter_FWD_DEFINED__ */


#ifndef __ISpAudio_FWD_DEFINED__
#define __ISpAudio_FWD_DEFINED__
typedef interface ISpAudio ISpAudio;

#endif 	/* __ISpAudio_FWD_DEFINED__ */


#ifndef __ISpMMSysAudio_FWD_DEFINED__
#define __ISpMMSysAudio_FWD_DEFINED__
typedef interface ISpMMSysAudio ISpMMSysAudio;

#endif 	/* __ISpMMSysAudio_FWD_DEFINED__ */


#ifndef __ISpTranscript_FWD_DEFINED__
#define __ISpTranscript_FWD_DEFINED__
typedef interface ISpTranscript ISpTranscript;

#endif 	/* __ISpTranscript_FWD_DEFINED__ */


#ifndef __ISpLexicon_FWD_DEFINED__
#define __ISpLexicon_FWD_DEFINED__
typedef interface ISpLexicon ISpLexicon;

#endif 	/* __ISpLexicon_FWD_DEFINED__ */


#ifndef __ISpContainerLexicon_FWD_DEFINED__
#define __ISpContainerLexicon_FWD_DEFINED__
typedef interface ISpContainerLexicon ISpContainerLexicon;

#endif 	/* __ISpContainerLexicon_FWD_DEFINED__ */


#ifndef __ISpShortcut_FWD_DEFINED__
#define __ISpShortcut_FWD_DEFINED__
typedef interface ISpShortcut ISpShortcut;

#endif 	/* __ISpShortcut_FWD_DEFINED__ */


#ifndef __ISpPhoneConverter_FWD_DEFINED__
#define __ISpPhoneConverter_FWD_DEFINED__
typedef interface ISpPhoneConverter ISpPhoneConverter;

#endif 	/* __ISpPhoneConverter_FWD_DEFINED__ */


#ifndef __ISpPhoneticAlphabetConverter_FWD_DEFINED__
#define __ISpPhoneticAlphabetConverter_FWD_DEFINED__
typedef interface ISpPhoneticAlphabetConverter ISpPhoneticAlphabetConverter;

#endif 	/* __ISpPhoneticAlphabetConverter_FWD_DEFINED__ */


#ifndef __ISpPhoneticAlphabetSelection_FWD_DEFINED__
#define __ISpPhoneticAlphabetSelection_FWD_DEFINED__
typedef interface ISpPhoneticAlphabetSelection ISpPhoneticAlphabetSelection;

#endif 	/* __ISpPhoneticAlphabetSelection_FWD_DEFINED__ */


#ifndef __ISpVoice_FWD_DEFINED__
#define __ISpVoice_FWD_DEFINED__
typedef interface ISpVoice ISpVoice;

#endif 	/* __ISpVoice_FWD_DEFINED__ */


#ifndef __ISpPhrase_FWD_DEFINED__
#define __ISpPhrase_FWD_DEFINED__
typedef interface ISpPhrase ISpPhrase;

#endif 	/* __ISpPhrase_FWD_DEFINED__ */


#ifndef __ISpPhraseAlt_FWD_DEFINED__
#define __ISpPhraseAlt_FWD_DEFINED__
typedef interface ISpPhraseAlt ISpPhraseAlt;

#endif 	/* __ISpPhraseAlt_FWD_DEFINED__ */


#ifndef __ISpPhrase2_FWD_DEFINED__
#define __ISpPhrase2_FWD_DEFINED__
typedef interface ISpPhrase2 ISpPhrase2;

#endif 	/* __ISpPhrase2_FWD_DEFINED__ */


#ifndef __ISpRecoResult_FWD_DEFINED__
#define __ISpRecoResult_FWD_DEFINED__
typedef interface ISpRecoResult ISpRecoResult;

#endif 	/* __ISpRecoResult_FWD_DEFINED__ */


#ifndef __ISpRecoResult2_FWD_DEFINED__
#define __ISpRecoResult2_FWD_DEFINED__
typedef interface ISpRecoResult2 ISpRecoResult2;

#endif 	/* __ISpRecoResult2_FWD_DEFINED__ */


#ifndef __ISpXMLRecoResult_FWD_DEFINED__
#define __ISpXMLRecoResult_FWD_DEFINED__
typedef interface ISpXMLRecoResult ISpXMLRecoResult;

#endif 	/* __ISpXMLRecoResult_FWD_DEFINED__ */


#ifndef __ISpGrammarBuilder_FWD_DEFINED__
#define __ISpGrammarBuilder_FWD_DEFINED__
typedef interface ISpGrammarBuilder ISpGrammarBuilder;

#endif 	/* __ISpGrammarBuilder_FWD_DEFINED__ */


#ifndef __ISpRecoGrammar_FWD_DEFINED__
#define __ISpRecoGrammar_FWD_DEFINED__
typedef interface ISpRecoGrammar ISpRecoGrammar;

#endif 	/* __ISpRecoGrammar_FWD_DEFINED__ */


#ifndef __ISpGrammarBuilder2_FWD_DEFINED__
#define __ISpGrammarBuilder2_FWD_DEFINED__
typedef interface ISpGrammarBuilder2 ISpGrammarBuilder2;

#endif 	/* __ISpGrammarBuilder2_FWD_DEFINED__ */


#ifndef __ISpRecoGrammar2_FWD_DEFINED__
#define __ISpRecoGrammar2_FWD_DEFINED__
typedef interface ISpRecoGrammar2 ISpRecoGrammar2;

#endif 	/* __ISpRecoGrammar2_FWD_DEFINED__ */


#ifndef __ISpeechResourceLoader_FWD_DEFINED__
#define __ISpeechResourceLoader_FWD_DEFINED__
typedef interface ISpeechResourceLoader ISpeechResourceLoader;

#endif 	/* __ISpeechResourceLoader_FWD_DEFINED__ */


#ifndef __ISpRecoContext_FWD_DEFINED__
#define __ISpRecoContext_FWD_DEFINED__
typedef interface ISpRecoContext ISpRecoContext;

#endif 	/* __ISpRecoContext_FWD_DEFINED__ */


#ifndef __ISpRecoContext2_FWD_DEFINED__
#define __ISpRecoContext2_FWD_DEFINED__
typedef interface ISpRecoContext2 ISpRecoContext2;

#endif 	/* __ISpRecoContext2_FWD_DEFINED__ */


#ifndef __ISpProperties_FWD_DEFINED__
#define __ISpProperties_FWD_DEFINED__
typedef interface ISpProperties ISpProperties;

#endif 	/* __ISpProperties_FWD_DEFINED__ */


#ifndef __ISpRecognizer_FWD_DEFINED__
#define __ISpRecognizer_FWD_DEFINED__
typedef interface ISpRecognizer ISpRecognizer;

#endif 	/* __ISpRecognizer_FWD_DEFINED__ */


#ifndef __ISpSerializeState_FWD_DEFINED__
#define __ISpSerializeState_FWD_DEFINED__
typedef interface ISpSerializeState ISpSerializeState;

#endif 	/* __ISpSerializeState_FWD_DEFINED__ */


#ifndef __ISpRecognizer2_FWD_DEFINED__
#define __ISpRecognizer2_FWD_DEFINED__
typedef interface ISpRecognizer2 ISpRecognizer2;

#endif 	/* __ISpRecognizer2_FWD_DEFINED__ */


#ifndef __ISpRecoCategory_FWD_DEFINED__
#define __ISpRecoCategory_FWD_DEFINED__
typedef interface ISpRecoCategory ISpRecoCategory;

#endif 	/* __ISpRecoCategory_FWD_DEFINED__ */


#ifndef __ISpRecognizer3_FWD_DEFINED__
#define __ISpRecognizer3_FWD_DEFINED__
typedef interface ISpRecognizer3 ISpRecognizer3;

#endif 	/* __ISpRecognizer3_FWD_DEFINED__ */


#ifndef __ISpEnginePronunciation_FWD_DEFINED__
#define __ISpEnginePronunciation_FWD_DEFINED__
typedef interface ISpEnginePronunciation ISpEnginePronunciation;

#endif 	/* __ISpEnginePronunciation_FWD_DEFINED__ */


#ifndef __ISpDisplayAlternates_FWD_DEFINED__
#define __ISpDisplayAlternates_FWD_DEFINED__
typedef interface ISpDisplayAlternates ISpDisplayAlternates;

#endif 	/* __ISpDisplayAlternates_FWD_DEFINED__ */


#ifndef __SpNotifyTranslator_FWD_DEFINED__
#define __SpNotifyTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpNotifyTranslator SpNotifyTranslator;
#else
typedef struct SpNotifyTranslator SpNotifyTranslator;
#endif /* __cplusplus */

#endif 	/* __SpNotifyTranslator_FWD_DEFINED__ */


#ifndef __SpObjectTokenCategory_FWD_DEFINED__
#define __SpObjectTokenCategory_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpObjectTokenCategory SpObjectTokenCategory;
#else
typedef struct SpObjectTokenCategory SpObjectTokenCategory;
#endif /* __cplusplus */

#endif 	/* __SpObjectTokenCategory_FWD_DEFINED__ */


#ifndef __SpObjectToken_FWD_DEFINED__
#define __SpObjectToken_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpObjectToken SpObjectToken;
#else
typedef struct SpObjectToken SpObjectToken;
#endif /* __cplusplus */

#endif 	/* __SpObjectToken_FWD_DEFINED__ */


#ifndef __SpResourceManager_FWD_DEFINED__
#define __SpResourceManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpResourceManager SpResourceManager;
#else
typedef struct SpResourceManager SpResourceManager;
#endif /* __cplusplus */

#endif 	/* __SpResourceManager_FWD_DEFINED__ */


#ifndef __SpStreamFormatConverter_FWD_DEFINED__
#define __SpStreamFormatConverter_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpStreamFormatConverter SpStreamFormatConverter;
#else
typedef struct SpStreamFormatConverter SpStreamFormatConverter;
#endif /* __cplusplus */

#endif 	/* __SpStreamFormatConverter_FWD_DEFINED__ */


#ifndef __SpMMAudioEnum_FWD_DEFINED__
#define __SpMMAudioEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpMMAudioEnum SpMMAudioEnum;
#else
typedef struct SpMMAudioEnum SpMMAudioEnum;
#endif /* __cplusplus */

#endif 	/* __SpMMAudioEnum_FWD_DEFINED__ */


#ifndef __SpMMAudioIn_FWD_DEFINED__
#define __SpMMAudioIn_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpMMAudioIn SpMMAudioIn;
#else
typedef struct SpMMAudioIn SpMMAudioIn;
#endif /* __cplusplus */

#endif 	/* __SpMMAudioIn_FWD_DEFINED__ */


#ifndef __SpMMAudioOut_FWD_DEFINED__
#define __SpMMAudioOut_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpMMAudioOut SpMMAudioOut;
#else
typedef struct SpMMAudioOut SpMMAudioOut;
#endif /* __cplusplus */

#endif 	/* __SpMMAudioOut_FWD_DEFINED__ */


#ifndef __SpStream_FWD_DEFINED__
#define __SpStream_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpStream SpStream;
#else
typedef struct SpStream SpStream;
#endif /* __cplusplus */

#endif 	/* __SpStream_FWD_DEFINED__ */


#ifndef __SpVoice_FWD_DEFINED__
#define __SpVoice_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpVoice SpVoice;
#else
typedef struct SpVoice SpVoice;
#endif /* __cplusplus */

#endif 	/* __SpVoice_FWD_DEFINED__ */


#ifndef __SpSharedRecoContext_FWD_DEFINED__
#define __SpSharedRecoContext_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpSharedRecoContext SpSharedRecoContext;
#else
typedef struct SpSharedRecoContext SpSharedRecoContext;
#endif /* __cplusplus */

#endif 	/* __SpSharedRecoContext_FWD_DEFINED__ */


#ifndef __SpInprocRecognizer_FWD_DEFINED__
#define __SpInprocRecognizer_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpInprocRecognizer SpInprocRecognizer;
#else
typedef struct SpInprocRecognizer SpInprocRecognizer;
#endif /* __cplusplus */

#endif 	/* __SpInprocRecognizer_FWD_DEFINED__ */


#ifndef __SpSharedRecognizer_FWD_DEFINED__
#define __SpSharedRecognizer_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpSharedRecognizer SpSharedRecognizer;
#else
typedef struct SpSharedRecognizer SpSharedRecognizer;
#endif /* __cplusplus */

#endif 	/* __SpSharedRecognizer_FWD_DEFINED__ */


#ifndef __SpLexicon_FWD_DEFINED__
#define __SpLexicon_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpLexicon SpLexicon;
#else
typedef struct SpLexicon SpLexicon;
#endif /* __cplusplus */

#endif 	/* __SpLexicon_FWD_DEFINED__ */


#ifndef __SpUnCompressedLexicon_FWD_DEFINED__
#define __SpUnCompressedLexicon_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpUnCompressedLexicon SpUnCompressedLexicon;
#else
typedef struct SpUnCompressedLexicon SpUnCompressedLexicon;
#endif /* __cplusplus */

#endif 	/* __SpUnCompressedLexicon_FWD_DEFINED__ */


#ifndef __SpCompressedLexicon_FWD_DEFINED__
#define __SpCompressedLexicon_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpCompressedLexicon SpCompressedLexicon;
#else
typedef struct SpCompressedLexicon SpCompressedLexicon;
#endif /* __cplusplus */

#endif 	/* __SpCompressedLexicon_FWD_DEFINED__ */


#ifndef __SpShortcut_FWD_DEFINED__
#define __SpShortcut_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpShortcut SpShortcut;
#else
typedef struct SpShortcut SpShortcut;
#endif /* __cplusplus */

#endif 	/* __SpShortcut_FWD_DEFINED__ */


#ifndef __SpPhoneConverter_FWD_DEFINED__
#define __SpPhoneConverter_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpPhoneConverter SpPhoneConverter;
#else
typedef struct SpPhoneConverter SpPhoneConverter;
#endif /* __cplusplus */

#endif 	/* __SpPhoneConverter_FWD_DEFINED__ */


#ifndef __SpPhoneticAlphabetConverter_FWD_DEFINED__
#define __SpPhoneticAlphabetConverter_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpPhoneticAlphabetConverter SpPhoneticAlphabetConverter;
#else
typedef struct SpPhoneticAlphabetConverter SpPhoneticAlphabetConverter;
#endif /* __cplusplus */

#endif 	/* __SpPhoneticAlphabetConverter_FWD_DEFINED__ */


#ifndef __SpNullPhoneConverter_FWD_DEFINED__
#define __SpNullPhoneConverter_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpNullPhoneConverter SpNullPhoneConverter;
#else
typedef struct SpNullPhoneConverter SpNullPhoneConverter;
#endif /* __cplusplus */

#endif 	/* __SpNullPhoneConverter_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_sapi_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#ifndef _SAPI_VER
// Use SAPI 5.4 by default if target Windows 7 or above
#if _WIN32_WINNT >= 0x0601
#define _SAPI_VER 0x054
#elif _WIN32_WINNT >= 0x0600
#define _SAPI_VER 0x053
#else // _WIN32_WINNT < 0x0600
#define _SAPI_VER 0x051
#endif // _WIN32_WINNT >= 0x0601
#endif // _SAPI_VER
// The following definitions are for SAPI 5.4 and newer
#if  _SAPI_VER >= 0x054
#pragma warning(disable:4201) // Allow nameless structs/unions
#pragma comment(lib, "sapi.lib")
#if 0
typedef /* [hidden][restricted] */ struct WAVEFORMATEX
    {
    WORD wFormatTag;
    WORD nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD nBlockAlign;
    WORD wBitsPerSample;
    WORD cbSize;
    } 	WAVEFORMATEX;

#else
#include <mmsystem.h>
#endif

































typedef /* [hidden] */ 
enum SPDATAKEYLOCATION
    {
        SPDKL_DefaultLocation	= 0,
        SPDKL_CurrentUser	= 1,
        SPDKL_LocalMachine	= 2,
        SPDKL_CurrentConfig	= 5
    } 	SPDATAKEYLOCATION;

#define SPDUI_EngineProperties   L"EngineProperties"
#define SPDUI_AddRemoveWord      L"AddRemoveWord"
#define SPDUI_UserTraining       L"UserTraining"
#define SPDUI_MicTraining        L"MicTraining"
#define SPDUI_RecoProfileProperties L"RecoProfileProperties"
#define SPDUI_AudioProperties    L"AudioProperties"
#define SPDUI_AudioVolume        L"AudioVolume"
#define SPDUI_UserEnrollment     L"UserEnrollment"
#define SPDUI_ShareData          L"ShareData"
#define SPDUI_Tutorial           L"Tutorial"
typedef /* [hidden] */ 
enum SPSTREAMFORMAT
    {
        SPSF_Default	= -1,
        SPSF_NoAssignedFormat	= 0,
        SPSF_Text	= ( SPSF_NoAssignedFormat + 1 ) ,
        SPSF_NonStandardFormat	= ( SPSF_Text + 1 ) ,
        SPSF_ExtendedAudioFormat	= ( SPSF_NonStandardFormat + 1 ) ,
        SPSF_8kHz8BitMono	= ( SPSF_ExtendedAudioFormat + 1 ) ,
        SPSF_8kHz8BitStereo	= ( SPSF_8kHz8BitMono + 1 ) ,
        SPSF_8kHz16BitMono	= ( SPSF_8kHz8BitStereo + 1 ) ,
        SPSF_8kHz16BitStereo	= ( SPSF_8kHz16BitMono + 1 ) ,
        SPSF_11kHz8BitMono	= ( SPSF_8kHz16BitStereo + 1 ) ,
        SPSF_11kHz8BitStereo	= ( SPSF_11kHz8BitMono + 1 ) ,
        SPSF_11kHz16BitMono	= ( SPSF_11kHz8BitStereo + 1 ) ,
        SPSF_11kHz16BitStereo	= ( SPSF_11kHz16BitMono + 1 ) ,
        SPSF_12kHz8BitMono	= ( SPSF_11kHz16BitStereo + 1 ) ,
        SPSF_12kHz8BitStereo	= ( SPSF_12kHz8BitMono + 1 ) ,
        SPSF_12kHz16BitMono	= ( SPSF_12kHz8BitStereo + 1 ) ,
        SPSF_12kHz16BitStereo	= ( SPSF_12kHz16BitMono + 1 ) ,
        SPSF_16kHz8BitMono	= ( SPSF_12kHz16BitStereo + 1 ) ,
        SPSF_16kHz8BitStereo	= ( SPSF_16kHz8BitMono + 1 ) ,
        SPSF_16kHz16BitMono	= ( SPSF_16kHz8BitStereo + 1 ) ,
        SPSF_16kHz16BitStereo	= ( SPSF_16kHz16BitMono + 1 ) ,
        SPSF_22kHz8BitMono	= ( SPSF_16kHz16BitStereo + 1 ) ,
        SPSF_22kHz8BitStereo	= ( SPSF_22kHz8BitMono + 1 ) ,
        SPSF_22kHz16BitMono	= ( SPSF_22kHz8BitStereo + 1 ) ,
        SPSF_22kHz16BitStereo	= ( SPSF_22kHz16BitMono + 1 ) ,
        SPSF_24kHz8BitMono	= ( SPSF_22kHz16BitStereo + 1 ) ,
        SPSF_24kHz8BitStereo	= ( SPSF_24kHz8BitMono + 1 ) ,
        SPSF_24kHz16BitMono	= ( SPSF_24kHz8BitStereo + 1 ) ,
        SPSF_24kHz16BitStereo	= ( SPSF_24kHz16BitMono + 1 ) ,
        SPSF_32kHz8BitMono	= ( SPSF_24kHz16BitStereo + 1 ) ,
        SPSF_32kHz8BitStereo	= ( SPSF_32kHz8BitMono + 1 ) ,
        SPSF_32kHz16BitMono	= ( SPSF_32kHz8BitStereo + 1 ) ,
        SPSF_32kHz16BitStereo	= ( SPSF_32kHz16BitMono + 1 ) ,
        SPSF_44kHz8BitMono	= ( SPSF_32kHz16BitStereo + 1 ) ,
        SPSF_44kHz8BitStereo	= ( SPSF_44kHz8BitMono + 1 ) ,
        SPSF_44kHz16BitMono	= ( SPSF_44kHz8BitStereo + 1 ) ,
        SPSF_44kHz16BitStereo	= ( SPSF_44kHz16BitMono + 1 ) ,
        SPSF_48kHz8BitMono	= ( SPSF_44kHz16BitStereo + 1 ) ,
        SPSF_48kHz8BitStereo	= ( SPSF_48kHz8BitMono + 1 ) ,
        SPSF_48kHz16BitMono	= ( SPSF_48kHz8BitStereo + 1 ) ,
        SPSF_48kHz16BitStereo	= ( SPSF_48kHz16BitMono + 1 ) ,
        SPSF_TrueSpeech_8kHz1BitMono	= ( SPSF_48kHz16BitStereo + 1 ) ,
        SPSF_CCITT_ALaw_8kHzMono	= ( SPSF_TrueSpeech_8kHz1BitMono + 1 ) ,
        SPSF_CCITT_ALaw_8kHzStereo	= ( SPSF_CCITT_ALaw_8kHzMono + 1 ) ,
        SPSF_CCITT_ALaw_11kHzMono	= ( SPSF_CCITT_ALaw_8kHzStereo + 1 ) ,
        SPSF_CCITT_ALaw_11kHzStereo	= ( SPSF_CCITT_ALaw_11kHzMono + 1 ) ,
        SPSF_CCITT_ALaw_22kHzMono	= ( SPSF_CCITT_ALaw_11kHzStereo + 1 ) ,
        SPSF_CCITT_ALaw_22kHzStereo	= ( SPSF_CCITT_ALaw_22kHzMono + 1 ) ,
        SPSF_CCITT_ALaw_44kHzMono	= ( SPSF_CCITT_ALaw_22kHzStereo + 1 ) ,
        SPSF_CCITT_ALaw_44kHzStereo	= ( SPSF_CCITT_ALaw_44kHzMono + 1 ) ,
        SPSF_CCITT_uLaw_8kHzMono	= ( SPSF_CCITT_ALaw_44kHzStereo + 1 ) ,
        SPSF_CCITT_uLaw_8kHzStereo	= ( SPSF_CCITT_uLaw_8kHzMono + 1 ) ,
        SPSF_CCITT_uLaw_11kHzMono	= ( SPSF_CCITT_uLaw_8kHzStereo + 1 ) ,
        SPSF_CCITT_uLaw_11kHzStereo	= ( SPSF_CCITT_uLaw_11kHzMono + 1 ) ,
        SPSF_CCITT_uLaw_22kHzMono	= ( SPSF_CCITT_uLaw_11kHzStereo + 1 ) ,
        SPSF_CCITT_uLaw_22kHzStereo	= ( SPSF_CCITT_uLaw_22kHzMono + 1 ) ,
        SPSF_CCITT_uLaw_44kHzMono	= ( SPSF_CCITT_uLaw_22kHzStereo + 1 ) ,
        SPSF_CCITT_uLaw_44kHzStereo	= ( SPSF_CCITT_uLaw_44kHzMono + 1 ) ,
        SPSF_ADPCM_8kHzMono	= ( SPSF_CCITT_uLaw_44kHzStereo + 1 ) ,
        SPSF_ADPCM_8kHzStereo	= ( SPSF_ADPCM_8kHzMono + 1 ) ,
        SPSF_ADPCM_11kHzMono	= ( SPSF_ADPCM_8kHzStereo + 1 ) ,
        SPSF_ADPCM_11kHzStereo	= ( SPSF_ADPCM_11kHzMono + 1 ) ,
        SPSF_ADPCM_22kHzMono	= ( SPSF_ADPCM_11kHzStereo + 1 ) ,
        SPSF_ADPCM_22kHzStereo	= ( SPSF_ADPCM_22kHzMono + 1 ) ,
        SPSF_ADPCM_44kHzMono	= ( SPSF_ADPCM_22kHzStereo + 1 ) ,
        SPSF_ADPCM_44kHzStereo	= ( SPSF_ADPCM_44kHzMono + 1 ) ,
        SPSF_GSM610_8kHzMono	= ( SPSF_ADPCM_44kHzStereo + 1 ) ,
        SPSF_GSM610_11kHzMono	= ( SPSF_GSM610_8kHzMono + 1 ) ,
        SPSF_GSM610_22kHzMono	= ( SPSF_GSM610_11kHzMono + 1 ) ,
        SPSF_GSM610_44kHzMono	= ( SPSF_GSM610_22kHzMono + 1 ) ,
        SPSF_NUM_FORMATS	= ( SPSF_GSM610_44kHzMono + 1 ) 
    } 	SPSTREAMFORMAT;

EXTERN_C const GUID SPDFID_Text;
EXTERN_C const GUID SPDFID_WaveFormatEx;
#define SPREG_USER_ROOT          L"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Speech"
#define SPREG_LOCAL_MACHINE_ROOT L"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech"
#define SPCAT_AUDIOOUT         L"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\AudioOutput"
#define SPCAT_AUDIOIN          L"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\AudioInput"
#define SPCAT_VOICES           L"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\Voices"
#define SPCAT_RECOGNIZERS      L"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\Recognizers"
#define SPCAT_APPLEXICONS      L"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\AppLexicons"
#define SPCAT_PHONECONVERTERS  L"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\PhoneConverters"
#define SPCAT_TEXTNORMALIZERS  L"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\TextNormalizers"
#define SPCAT_RECOPROFILES     L"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Speech\\RecoProfiles"
#define SPMMSYS_AUDIO_IN_TOKEN_ID        L"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\AudioInput\\TokenEnums\\MMAudioIn\\"
#define SPMMSYS_AUDIO_OUT_TOKEN_ID       L"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\AudioOutput\\TokenEnums\\MMAudioOut\\"
#define SPCURRENT_USER_LEXICON_TOKEN_ID  L"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Speech\\CurrentUserLexicon"
#define SPCURRENT_USER_SHORTCUT_TOKEN_ID  L"HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Speech\\CurrentUserShortcut"
#define SPTOKENVALUE_CLSID L"CLSID"
#define SPTOKENKEY_FILES L"Files"
#define SPTOKENKEY_UI L"UI"
#define SPTOKENKEY_ATTRIBUTES L"Attributes"
#define SPTOKENKEY_RETAINEDAUDIO L"SecondsPerRetainedAudioEvent"
#define SPTOKENKEY_AUDIO_LATENCY_WARNING L"LatencyWarningThreshold"
#define SPTOKENKEY_AUDIO_LATENCY_TRUNCATE L"LatencyTruncateThreshold"
#define SPTOKENKEY_AUDIO_LATENCY_UPDATE_INTERVAL L"LatencyUpdateInterval"
#define SPVOICECATEGORY_TTSRATE L"DefaultTTSRate"
#define SPPROP_RESOURCE_USAGE              L"ResourceUsage"
#define SPPROP_HIGH_CONFIDENCE_THRESHOLD   L"HighConfidenceThreshold"
#define SPPROP_NORMAL_CONFIDENCE_THRESHOLD L"NormalConfidenceThreshold"
#define SPPROP_LOW_CONFIDENCE_THRESHOLD    L"LowConfidenceThreshold"
#define SPPROP_RESPONSE_SPEED              L"ResponseSpeed"
#define SPPROP_COMPLEX_RESPONSE_SPEED      L"ComplexResponseSpeed"
#define SPPROP_ADAPTATION_ON               L"AdaptationOn"
#define SPPROP_PERSISTED_BACKGROUND_ADAPTATION L"PersistedBackgroundAdaptation"
#define SPPROP_PERSISTED_LANGUAGE_MODEL_ADAPTATION L"PersistedLanguageModelAdaptation"
#define SPPROP_UX_IS_LISTENING             L"UXIsListening"
#define SPTOPIC_SPELLING L"Spelling"
#define SPWILDCARD L"..."
#define SPDICTATION    L"*"
#define SPINFDICTATION L"*+"
#define SPREG_SAFE_USER_TOKENS       L"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\UserTokens"
#define	SP_LOW_CONFIDENCE	( -1 )

#define	SP_NORMAL_CONFIDENCE	( 0 )

#define	SP_HIGH_CONFIDENCE	( +1 )

#define	DEFAULT_WEIGHT	( 1 )

#define	SP_MAX_WORD_LENGTH	( 128 )

#define	SP_MAX_PRON_LENGTH	( 384 )

#define	SP_EMULATE_RESULT	( 0x40000000 )

#if defined(__cplusplus)
interface ISpNotifyCallback
{
virtual HRESULT STDMETHODCALLTYPE NotifyCallback(
                                     WPARAM wParam,
                                     LPARAM lParam) = 0;
};
#else
typedef void *ISpNotifyCallback;

#endif
#if 0
typedef void *SPNOTIFYCALLBACK;

#else
typedef void __stdcall SPNOTIFYCALLBACK(WPARAM wParam, LPARAM lParam);
#endif


extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0000_v0_0_s_ifspec;

#ifndef __ISpNotifySource_INTERFACE_DEFINED__
#define __ISpNotifySource_INTERFACE_DEFINED__

/* interface ISpNotifySource */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpNotifySource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5EFF4AEF-8487-11D2-961C-00C04F8EE628")
    ISpNotifySource : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetNotifySink( 
            /* [annotation][in] */ 
            _In_  ISpNotifySink *pNotifySink) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetNotifyWindowMessage( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT Msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetNotifyCallbackFunction( 
            /* [annotation][in] */ 
            _In_  SPNOTIFYCALLBACK *pfnCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetNotifyCallbackInterface( 
            /* [annotation][in] */ 
            _In_  ISpNotifyCallback *pSpCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetNotifyWin32Event( void) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE WaitForNotifyEvent( 
            /* [annotation][in] */ 
            _In_  DWORD dwMilliseconds) = 0;
        
        virtual /* [local] */ HANDLE STDMETHODCALLTYPE GetNotifyEventHandle( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpNotifySourceVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpNotifySource * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpNotifySource * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpNotifySource * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifySink)
        HRESULT ( STDMETHODCALLTYPE *SetNotifySink )( 
            __RPC__in ISpNotifySource * This,
            /* [annotation][in] */ 
            _In_  ISpNotifySink *pNotifySink);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWindowMessage)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWindowMessage )( 
            ISpNotifySource * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT Msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackFunction)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackFunction )( 
            ISpNotifySource * This,
            /* [annotation][in] */ 
            _In_  SPNOTIFYCALLBACK *pfnCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackInterface)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackInterface )( 
            ISpNotifySource * This,
            /* [annotation][in] */ 
            _In_  ISpNotifyCallback *pSpCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWin32Event)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWin32Event )( 
            ISpNotifySource * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, WaitForNotifyEvent)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *WaitForNotifyEvent )( 
            ISpNotifySource * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMilliseconds);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, GetNotifyEventHandle)
        /* [local] */ HANDLE ( STDMETHODCALLTYPE *GetNotifyEventHandle )( 
            ISpNotifySource * This);
        
        END_INTERFACE
    } ISpNotifySourceVtbl;

    interface ISpNotifySource
    {
        CONST_VTBL struct ISpNotifySourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpNotifySource_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpNotifySource_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpNotifySource_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpNotifySource_SetNotifySink(This,pNotifySink)	\
    ( (This)->lpVtbl -> SetNotifySink(This,pNotifySink) ) 

#define ISpNotifySource_SetNotifyWindowMessage(This,hWnd,Msg,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyWindowMessage(This,hWnd,Msg,wParam,lParam) ) 

#define ISpNotifySource_SetNotifyCallbackFunction(This,pfnCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyCallbackFunction(This,pfnCallback,wParam,lParam) ) 

#define ISpNotifySource_SetNotifyCallbackInterface(This,pSpCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyCallbackInterface(This,pSpCallback,wParam,lParam) ) 

#define ISpNotifySource_SetNotifyWin32Event(This)	\
    ( (This)->lpVtbl -> SetNotifyWin32Event(This) ) 

#define ISpNotifySource_WaitForNotifyEvent(This,dwMilliseconds)	\
    ( (This)->lpVtbl -> WaitForNotifyEvent(This,dwMilliseconds) ) 

#define ISpNotifySource_GetNotifyEventHandle(This)	\
    ( (This)->lpVtbl -> GetNotifyEventHandle(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpNotifySource_INTERFACE_DEFINED__ */


#ifndef __ISpNotifySink_INTERFACE_DEFINED__
#define __ISpNotifySink_INTERFACE_DEFINED__

/* interface ISpNotifySink */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpNotifySink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("259684DC-37C3-11D2-9603-00C04F8EE628")
    ISpNotifySink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Notify( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpNotifySinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpNotifySink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpNotifySink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpNotifySink * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySink, Notify)
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            __RPC__in ISpNotifySink * This);
        
        END_INTERFACE
    } ISpNotifySinkVtbl;

    interface ISpNotifySink
    {
        CONST_VTBL struct ISpNotifySinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpNotifySink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpNotifySink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpNotifySink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpNotifySink_Notify(This)	\
    ( (This)->lpVtbl -> Notify(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpNotifySink_INTERFACE_DEFINED__ */


#ifndef __ISpNotifyTranslator_INTERFACE_DEFINED__
#define __ISpNotifyTranslator_INTERFACE_DEFINED__

/* interface ISpNotifyTranslator */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpNotifyTranslator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ACA16614-5D3D-11D2-960E-00C04F8EE628")
    ISpNotifyTranslator : public ISpNotifySink
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitWindowMessage( 
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT Msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitCallback( 
            /* [annotation][in] */ 
            _In_  SPNOTIFYCALLBACK *pfnCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitSpNotifyCallback( 
            /* [annotation][in] */ 
            _In_  ISpNotifyCallback *pSpCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitWin32Event( 
            /* [annotation][in] */ 
            _In_  HANDLE hEvent,
            /* [annotation][in] */ 
            _In_  BOOL fCloseHandleOnRelease) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Wait( 
            /* [annotation][in] */ 
            _In_  DWORD dwMilliseconds) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE GetEventHandle( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpNotifyTranslatorVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpNotifyTranslator * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpNotifyTranslator * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpNotifyTranslator * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySink, Notify)
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            ISpNotifyTranslator * This);
        
        DECLSPEC_XFGVIRT(ISpNotifyTranslator, InitWindowMessage)
        HRESULT ( STDMETHODCALLTYPE *InitWindowMessage )( 
            ISpNotifyTranslator * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT Msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifyTranslator, InitCallback)
        HRESULT ( STDMETHODCALLTYPE *InitCallback )( 
            ISpNotifyTranslator * This,
            /* [annotation][in] */ 
            _In_  SPNOTIFYCALLBACK *pfnCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifyTranslator, InitSpNotifyCallback)
        HRESULT ( STDMETHODCALLTYPE *InitSpNotifyCallback )( 
            ISpNotifyTranslator * This,
            /* [annotation][in] */ 
            _In_  ISpNotifyCallback *pSpCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifyTranslator, InitWin32Event)
        HRESULT ( STDMETHODCALLTYPE *InitWin32Event )( 
            ISpNotifyTranslator * This,
            /* [annotation][in] */ 
            _In_  HANDLE hEvent,
            /* [annotation][in] */ 
            _In_  BOOL fCloseHandleOnRelease);
        
        DECLSPEC_XFGVIRT(ISpNotifyTranslator, Wait)
        HRESULT ( STDMETHODCALLTYPE *Wait )( 
            ISpNotifyTranslator * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMilliseconds);
        
        DECLSPEC_XFGVIRT(ISpNotifyTranslator, GetEventHandle)
        HANDLE ( STDMETHODCALLTYPE *GetEventHandle )( 
            ISpNotifyTranslator * This);
        
        END_INTERFACE
    } ISpNotifyTranslatorVtbl;

    interface ISpNotifyTranslator
    {
        CONST_VTBL struct ISpNotifyTranslatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpNotifyTranslator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpNotifyTranslator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpNotifyTranslator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpNotifyTranslator_Notify(This)	\
    ( (This)->lpVtbl -> Notify(This) ) 


#define ISpNotifyTranslator_InitWindowMessage(This,hWnd,Msg,wParam,lParam)	\
    ( (This)->lpVtbl -> InitWindowMessage(This,hWnd,Msg,wParam,lParam) ) 

#define ISpNotifyTranslator_InitCallback(This,pfnCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> InitCallback(This,pfnCallback,wParam,lParam) ) 

#define ISpNotifyTranslator_InitSpNotifyCallback(This,pSpCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> InitSpNotifyCallback(This,pSpCallback,wParam,lParam) ) 

#define ISpNotifyTranslator_InitWin32Event(This,hEvent,fCloseHandleOnRelease)	\
    ( (This)->lpVtbl -> InitWin32Event(This,hEvent,fCloseHandleOnRelease) ) 

#define ISpNotifyTranslator_Wait(This,dwMilliseconds)	\
    ( (This)->lpVtbl -> Wait(This,dwMilliseconds) ) 

#define ISpNotifyTranslator_GetEventHandle(This)	\
    ( (This)->lpVtbl -> GetEventHandle(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpNotifyTranslator_INTERFACE_DEFINED__ */


#ifndef __ISpDataKey_INTERFACE_DEFINED__
#define __ISpDataKey_INTERFACE_DEFINED__

/* interface ISpDataKey */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpDataKey;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("14056581-E16C-11D2-BB90-00C04F8EE6C0")
    ISpDataKey : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetData( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG cbData,
            /* [annotation][in] */ 
            _In_  const BYTE *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetData( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG *pcbData,
            /* [annotation][out] */ 
            _Out_  BYTE *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStringValue( 
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringValue( 
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDWORD( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  DWORD dwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDWORD( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenKey( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateKey( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteKey( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteValue( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumKeys( 
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumValues( 
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValueName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpDataKeyVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpDataKey * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpDataKey * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpDataKey * This);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetData)
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            ISpDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG cbData,
            /* [annotation][in] */ 
            _In_  const BYTE *pData);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetData)
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            ISpDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG *pcbData,
            /* [annotation][out] */ 
            _Out_  BYTE *pData);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetStringValue)
        HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            ISpDataKey * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetStringValue)
        HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            ISpDataKey * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetDWORD)
        HRESULT ( STDMETHODCALLTYPE *SetDWORD )( 
            ISpDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  DWORD dwValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetDWORD)
        HRESULT ( STDMETHODCALLTYPE *GetDWORD )( 
            ISpDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, OpenKey)
        HRESULT ( STDMETHODCALLTYPE *OpenKey )( 
            ISpDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, CreateKey)
        HRESULT ( STDMETHODCALLTYPE *CreateKey )( 
            ISpDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, DeleteKey)
        HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            ISpDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, DeleteValue)
        HRESULT ( STDMETHODCALLTYPE *DeleteValue )( 
            ISpDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName);
        
        DECLSPEC_XFGVIRT(ISpDataKey, EnumKeys)
        HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            ISpDataKey * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName);
        
        DECLSPEC_XFGVIRT(ISpDataKey, EnumValues)
        HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            ISpDataKey * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValueName);
        
        END_INTERFACE
    } ISpDataKeyVtbl;

    interface ISpDataKey
    {
        CONST_VTBL struct ISpDataKeyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpDataKey_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpDataKey_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpDataKey_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpDataKey_SetData(This,pszValueName,cbData,pData)	\
    ( (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData) ) 

#define ISpDataKey_GetData(This,pszValueName,pcbData,pData)	\
    ( (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData) ) 

#define ISpDataKey_SetStringValue(This,pszValueName,pszValue)	\
    ( (This)->lpVtbl -> SetStringValue(This,pszValueName,pszValue) ) 

#define ISpDataKey_GetStringValue(This,pszValueName,ppszValue)	\
    ( (This)->lpVtbl -> GetStringValue(This,pszValueName,ppszValue) ) 

#define ISpDataKey_SetDWORD(This,pszValueName,dwValue)	\
    ( (This)->lpVtbl -> SetDWORD(This,pszValueName,dwValue) ) 

#define ISpDataKey_GetDWORD(This,pszValueName,pdwValue)	\
    ( (This)->lpVtbl -> GetDWORD(This,pszValueName,pdwValue) ) 

#define ISpDataKey_OpenKey(This,pszSubKeyName,ppSubKey)	\
    ( (This)->lpVtbl -> OpenKey(This,pszSubKeyName,ppSubKey) ) 

#define ISpDataKey_CreateKey(This,pszSubKey,ppSubKey)	\
    ( (This)->lpVtbl -> CreateKey(This,pszSubKey,ppSubKey) ) 

#define ISpDataKey_DeleteKey(This,pszSubKey)	\
    ( (This)->lpVtbl -> DeleteKey(This,pszSubKey) ) 

#define ISpDataKey_DeleteValue(This,pszValueName)	\
    ( (This)->lpVtbl -> DeleteValue(This,pszValueName) ) 

#define ISpDataKey_EnumKeys(This,Index,ppszSubKeyName)	\
    ( (This)->lpVtbl -> EnumKeys(This,Index,ppszSubKeyName) ) 

#define ISpDataKey_EnumValues(This,Index,ppszValueName)	\
    ( (This)->lpVtbl -> EnumValues(This,Index,ppszValueName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpDataKey_INTERFACE_DEFINED__ */


#ifndef __ISpRegDataKey_INTERFACE_DEFINED__
#define __ISpRegDataKey_INTERFACE_DEFINED__

/* interface ISpRegDataKey */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpRegDataKey;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("92A66E2B-C830-4149-83DF-6FC2BA1E7A5B")
    ISpRegDataKey : public ISpDataKey
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetKey( 
            /* [annotation][in] */ 
            _In_  HKEY hkey,
            /* [annotation][in] */ 
            _In_  BOOL fReadOnly) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRegDataKeyVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpRegDataKey * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpRegDataKey * This);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetData)
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            __RPC__in ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG cbData,
            /* [annotation][in] */ 
            _In_  const BYTE *pData);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetData)
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            __RPC__in ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG *pcbData,
            /* [annotation][out] */ 
            _Out_  BYTE *pData);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetStringValue)
        HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            __RPC__in ISpRegDataKey * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetStringValue)
        HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            __RPC__in ISpRegDataKey * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetDWORD)
        HRESULT ( STDMETHODCALLTYPE *SetDWORD )( 
            __RPC__in ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  DWORD dwValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetDWORD)
        HRESULT ( STDMETHODCALLTYPE *GetDWORD )( 
            __RPC__in ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, OpenKey)
        HRESULT ( STDMETHODCALLTYPE *OpenKey )( 
            __RPC__in ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, CreateKey)
        HRESULT ( STDMETHODCALLTYPE *CreateKey )( 
            __RPC__in ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, DeleteKey)
        HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            __RPC__in ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, DeleteValue)
        HRESULT ( STDMETHODCALLTYPE *DeleteValue )( 
            __RPC__in ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName);
        
        DECLSPEC_XFGVIRT(ISpDataKey, EnumKeys)
        HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            __RPC__in ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName);
        
        DECLSPEC_XFGVIRT(ISpDataKey, EnumValues)
        HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            __RPC__in ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValueName);
        
        DECLSPEC_XFGVIRT(ISpRegDataKey, SetKey)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetKey )( 
            ISpRegDataKey * This,
            /* [annotation][in] */ 
            _In_  HKEY hkey,
            /* [annotation][in] */ 
            _In_  BOOL fReadOnly);
        
        END_INTERFACE
    } ISpRegDataKeyVtbl;

    interface ISpRegDataKey
    {
        CONST_VTBL struct ISpRegDataKeyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpRegDataKey_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpRegDataKey_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpRegDataKey_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpRegDataKey_SetData(This,pszValueName,cbData,pData)	\
    ( (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData) ) 

#define ISpRegDataKey_GetData(This,pszValueName,pcbData,pData)	\
    ( (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData) ) 

#define ISpRegDataKey_SetStringValue(This,pszValueName,pszValue)	\
    ( (This)->lpVtbl -> SetStringValue(This,pszValueName,pszValue) ) 

#define ISpRegDataKey_GetStringValue(This,pszValueName,ppszValue)	\
    ( (This)->lpVtbl -> GetStringValue(This,pszValueName,ppszValue) ) 

#define ISpRegDataKey_SetDWORD(This,pszValueName,dwValue)	\
    ( (This)->lpVtbl -> SetDWORD(This,pszValueName,dwValue) ) 

#define ISpRegDataKey_GetDWORD(This,pszValueName,pdwValue)	\
    ( (This)->lpVtbl -> GetDWORD(This,pszValueName,pdwValue) ) 

#define ISpRegDataKey_OpenKey(This,pszSubKeyName,ppSubKey)	\
    ( (This)->lpVtbl -> OpenKey(This,pszSubKeyName,ppSubKey) ) 

#define ISpRegDataKey_CreateKey(This,pszSubKey,ppSubKey)	\
    ( (This)->lpVtbl -> CreateKey(This,pszSubKey,ppSubKey) ) 

#define ISpRegDataKey_DeleteKey(This,pszSubKey)	\
    ( (This)->lpVtbl -> DeleteKey(This,pszSubKey) ) 

#define ISpRegDataKey_DeleteValue(This,pszValueName)	\
    ( (This)->lpVtbl -> DeleteValue(This,pszValueName) ) 

#define ISpRegDataKey_EnumKeys(This,Index,ppszSubKeyName)	\
    ( (This)->lpVtbl -> EnumKeys(This,Index,ppszSubKeyName) ) 

#define ISpRegDataKey_EnumValues(This,Index,ppszValueName)	\
    ( (This)->lpVtbl -> EnumValues(This,Index,ppszValueName) ) 


#define ISpRegDataKey_SetKey(This,hkey,fReadOnly)	\
    ( (This)->lpVtbl -> SetKey(This,hkey,fReadOnly) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpRegDataKey_INTERFACE_DEFINED__ */


#ifndef __ISpObjectTokenCategory_INTERFACE_DEFINED__
#define __ISpObjectTokenCategory_INTERFACE_DEFINED__

/* interface ISpObjectTokenCategory */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpObjectTokenCategory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2D3D3845-39AF-4850-BBF9-40B49780011D")
    ISpObjectTokenCategory : public ISpDataKey
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetId( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszCategoryId,
            /* [annotation][in] */ 
            _In_  BOOL fCreateIfNotExist) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetId( 
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemCategoryId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDataKey( 
            /* [annotation][in] */ 
            _In_  SPDATAKEYLOCATION spdkl,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppDataKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumTokens( 
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pzsReqAttribs,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszOptAttribs,
            /* [annotation][out] */ 
            _Out_  IEnumSpObjectTokens **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultTokenId( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTokenId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultTokenId( 
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemTokenId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpObjectTokenCategoryVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpObjectTokenCategory * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpObjectTokenCategory * This);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetData)
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG cbData,
            /* [annotation][in] */ 
            _In_  const BYTE *pData);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetData)
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG *pcbData,
            /* [annotation][out] */ 
            _Out_  BYTE *pData);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetStringValue)
        HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            ISpObjectTokenCategory * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetStringValue)
        HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            ISpObjectTokenCategory * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetDWORD)
        HRESULT ( STDMETHODCALLTYPE *SetDWORD )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  DWORD dwValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetDWORD)
        HRESULT ( STDMETHODCALLTYPE *GetDWORD )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, OpenKey)
        HRESULT ( STDMETHODCALLTYPE *OpenKey )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, CreateKey)
        HRESULT ( STDMETHODCALLTYPE *CreateKey )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, DeleteKey)
        HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, DeleteValue)
        HRESULT ( STDMETHODCALLTYPE *DeleteValue )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName);
        
        DECLSPEC_XFGVIRT(ISpDataKey, EnumKeys)
        HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName);
        
        DECLSPEC_XFGVIRT(ISpDataKey, EnumValues)
        HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValueName);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenCategory, SetId)
        HRESULT ( STDMETHODCALLTYPE *SetId )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszCategoryId,
            /* [annotation][in] */ 
            _In_  BOOL fCreateIfNotExist);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenCategory, GetId)
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            ISpObjectTokenCategory * This,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemCategoryId);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenCategory, GetDataKey)
        HRESULT ( STDMETHODCALLTYPE *GetDataKey )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  SPDATAKEYLOCATION spdkl,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppDataKey);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenCategory, EnumTokens)
        HRESULT ( STDMETHODCALLTYPE *EnumTokens )( 
            ISpObjectTokenCategory * This,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pzsReqAttribs,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszOptAttribs,
            /* [annotation][out] */ 
            _Out_  IEnumSpObjectTokens **ppEnum);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenCategory, SetDefaultTokenId)
        HRESULT ( STDMETHODCALLTYPE *SetDefaultTokenId )( 
            ISpObjectTokenCategory * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTokenId);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenCategory, GetDefaultTokenId)
        HRESULT ( STDMETHODCALLTYPE *GetDefaultTokenId )( 
            ISpObjectTokenCategory * This,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemTokenId);
        
        END_INTERFACE
    } ISpObjectTokenCategoryVtbl;

    interface ISpObjectTokenCategory
    {
        CONST_VTBL struct ISpObjectTokenCategoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpObjectTokenCategory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpObjectTokenCategory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpObjectTokenCategory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpObjectTokenCategory_SetData(This,pszValueName,cbData,pData)	\
    ( (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData) ) 

#define ISpObjectTokenCategory_GetData(This,pszValueName,pcbData,pData)	\
    ( (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData) ) 

#define ISpObjectTokenCategory_SetStringValue(This,pszValueName,pszValue)	\
    ( (This)->lpVtbl -> SetStringValue(This,pszValueName,pszValue) ) 

#define ISpObjectTokenCategory_GetStringValue(This,pszValueName,ppszValue)	\
    ( (This)->lpVtbl -> GetStringValue(This,pszValueName,ppszValue) ) 

#define ISpObjectTokenCategory_SetDWORD(This,pszValueName,dwValue)	\
    ( (This)->lpVtbl -> SetDWORD(This,pszValueName,dwValue) ) 

#define ISpObjectTokenCategory_GetDWORD(This,pszValueName,pdwValue)	\
    ( (This)->lpVtbl -> GetDWORD(This,pszValueName,pdwValue) ) 

#define ISpObjectTokenCategory_OpenKey(This,pszSubKeyName,ppSubKey)	\
    ( (This)->lpVtbl -> OpenKey(This,pszSubKeyName,ppSubKey) ) 

#define ISpObjectTokenCategory_CreateKey(This,pszSubKey,ppSubKey)	\
    ( (This)->lpVtbl -> CreateKey(This,pszSubKey,ppSubKey) ) 

#define ISpObjectTokenCategory_DeleteKey(This,pszSubKey)	\
    ( (This)->lpVtbl -> DeleteKey(This,pszSubKey) ) 

#define ISpObjectTokenCategory_DeleteValue(This,pszValueName)	\
    ( (This)->lpVtbl -> DeleteValue(This,pszValueName) ) 

#define ISpObjectTokenCategory_EnumKeys(This,Index,ppszSubKeyName)	\
    ( (This)->lpVtbl -> EnumKeys(This,Index,ppszSubKeyName) ) 

#define ISpObjectTokenCategory_EnumValues(This,Index,ppszValueName)	\
    ( (This)->lpVtbl -> EnumValues(This,Index,ppszValueName) ) 


#define ISpObjectTokenCategory_SetId(This,pszCategoryId,fCreateIfNotExist)	\
    ( (This)->lpVtbl -> SetId(This,pszCategoryId,fCreateIfNotExist) ) 

#define ISpObjectTokenCategory_GetId(This,ppszCoMemCategoryId)	\
    ( (This)->lpVtbl -> GetId(This,ppszCoMemCategoryId) ) 

#define ISpObjectTokenCategory_GetDataKey(This,spdkl,ppDataKey)	\
    ( (This)->lpVtbl -> GetDataKey(This,spdkl,ppDataKey) ) 

#define ISpObjectTokenCategory_EnumTokens(This,pzsReqAttribs,pszOptAttribs,ppEnum)	\
    ( (This)->lpVtbl -> EnumTokens(This,pzsReqAttribs,pszOptAttribs,ppEnum) ) 

#define ISpObjectTokenCategory_SetDefaultTokenId(This,pszTokenId)	\
    ( (This)->lpVtbl -> SetDefaultTokenId(This,pszTokenId) ) 

#define ISpObjectTokenCategory_GetDefaultTokenId(This,ppszCoMemTokenId)	\
    ( (This)->lpVtbl -> GetDefaultTokenId(This,ppszCoMemTokenId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpObjectTokenCategory_INTERFACE_DEFINED__ */


#ifndef __ISpObjectToken_INTERFACE_DEFINED__
#define __ISpObjectToken_INTERFACE_DEFINED__

/* interface ISpObjectToken */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpObjectToken;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("14056589-E16C-11D2-BB90-00C04F8EE6C0")
    ISpObjectToken : public ISpDataKey
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetId( 
            /* [annotation] */ 
            _In_opt_  LPCWSTR pszCategoryId,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTokenId,
            /* [annotation][in] */ 
            _In_  BOOL fCreateIfNotExist) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetId( 
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemTokenId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCategory( 
            /* [out][annotation] */ 
            _Outptr_  ISpObjectTokenCategory **ppTokenCategory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateInstance( 
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkOuter,
            /* [annotation][in] */ 
            _In_  DWORD dwClsContext,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStorageFileName( 
            /* [annotation][in] */ 
            _In_  REFCLSID clsidCaller,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszFileNameSpecifier,
            /* [annotation][in] */ 
            _In_  ULONG nFolder,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszFilePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveStorageFileName( 
            /* [annotation][in] */ 
            _In_  REFCLSID clsidCaller,
            /* [in][annotation] */ 
            _In_  LPCWSTR pszKeyName,
            /* [annotation][in] */ 
            _In_  BOOL fDeleteFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( 
            /* [annotation] */ 
            _In_opt_  const CLSID *pclsidCaller) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][in] */ 
            _In_  IUnknown *punkObject,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSupported) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTitle,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][in] */ 
            _In_  IUnknown *punkObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MatchesAttributes( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszAttributes,
            /* [annotation][out] */ 
            _Out_  BOOL *pfMatches) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpObjectTokenVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpObjectToken * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpObjectToken * This);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetData)
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG cbData,
            /* [annotation][in] */ 
            _In_  const BYTE *pData);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetData)
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG *pcbData,
            /* [annotation][out] */ 
            _Out_  BYTE *pData);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetStringValue)
        HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            ISpObjectToken * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetStringValue)
        HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            ISpObjectToken * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetDWORD)
        HRESULT ( STDMETHODCALLTYPE *SetDWORD )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  DWORD dwValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetDWORD)
        HRESULT ( STDMETHODCALLTYPE *GetDWORD )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, OpenKey)
        HRESULT ( STDMETHODCALLTYPE *OpenKey )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, CreateKey)
        HRESULT ( STDMETHODCALLTYPE *CreateKey )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, DeleteKey)
        HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, DeleteValue)
        HRESULT ( STDMETHODCALLTYPE *DeleteValue )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName);
        
        DECLSPEC_XFGVIRT(ISpDataKey, EnumKeys)
        HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName);
        
        DECLSPEC_XFGVIRT(ISpDataKey, EnumValues)
        HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValueName);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, SetId)
        HRESULT ( STDMETHODCALLTYPE *SetId )( 
            ISpObjectToken * This,
            /* [annotation] */ 
            _In_opt_  LPCWSTR pszCategoryId,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTokenId,
            /* [annotation][in] */ 
            _In_  BOOL fCreateIfNotExist);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, GetId)
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            ISpObjectToken * This,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemTokenId);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, GetCategory)
        HRESULT ( STDMETHODCALLTYPE *GetCategory )( 
            ISpObjectToken * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectTokenCategory **ppTokenCategory);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, CreateInstance)
        HRESULT ( STDMETHODCALLTYPE *CreateInstance )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkOuter,
            /* [annotation][in] */ 
            _In_  DWORD dwClsContext,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, GetStorageFileName)
        HRESULT ( STDMETHODCALLTYPE *GetStorageFileName )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  REFCLSID clsidCaller,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszFileNameSpecifier,
            /* [annotation][in] */ 
            _In_  ULONG nFolder,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszFilePath);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, RemoveStorageFileName)
        HRESULT ( STDMETHODCALLTYPE *RemoveStorageFileName )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  REFCLSID clsidCaller,
            /* [in][annotation] */ 
            _In_  LPCWSTR pszKeyName,
            /* [annotation][in] */ 
            _In_  BOOL fDeleteFile);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, Remove)
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            ISpObjectToken * This,
            /* [annotation] */ 
            _In_opt_  const CLSID *pclsidCaller);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, IsUISupported)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][in] */ 
            _In_  IUnknown *punkObject,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSupported);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, DisplayUI)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTitle,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][in] */ 
            _In_  IUnknown *punkObject);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, MatchesAttributes)
        HRESULT ( STDMETHODCALLTYPE *MatchesAttributes )( 
            ISpObjectToken * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszAttributes,
            /* [annotation][out] */ 
            _Out_  BOOL *pfMatches);
        
        END_INTERFACE
    } ISpObjectTokenVtbl;

    interface ISpObjectToken
    {
        CONST_VTBL struct ISpObjectTokenVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpObjectToken_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpObjectToken_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpObjectToken_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpObjectToken_SetData(This,pszValueName,cbData,pData)	\
    ( (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData) ) 

#define ISpObjectToken_GetData(This,pszValueName,pcbData,pData)	\
    ( (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData) ) 

#define ISpObjectToken_SetStringValue(This,pszValueName,pszValue)	\
    ( (This)->lpVtbl -> SetStringValue(This,pszValueName,pszValue) ) 

#define ISpObjectToken_GetStringValue(This,pszValueName,ppszValue)	\
    ( (This)->lpVtbl -> GetStringValue(This,pszValueName,ppszValue) ) 

#define ISpObjectToken_SetDWORD(This,pszValueName,dwValue)	\
    ( (This)->lpVtbl -> SetDWORD(This,pszValueName,dwValue) ) 

#define ISpObjectToken_GetDWORD(This,pszValueName,pdwValue)	\
    ( (This)->lpVtbl -> GetDWORD(This,pszValueName,pdwValue) ) 

#define ISpObjectToken_OpenKey(This,pszSubKeyName,ppSubKey)	\
    ( (This)->lpVtbl -> OpenKey(This,pszSubKeyName,ppSubKey) ) 

#define ISpObjectToken_CreateKey(This,pszSubKey,ppSubKey)	\
    ( (This)->lpVtbl -> CreateKey(This,pszSubKey,ppSubKey) ) 

#define ISpObjectToken_DeleteKey(This,pszSubKey)	\
    ( (This)->lpVtbl -> DeleteKey(This,pszSubKey) ) 

#define ISpObjectToken_DeleteValue(This,pszValueName)	\
    ( (This)->lpVtbl -> DeleteValue(This,pszValueName) ) 

#define ISpObjectToken_EnumKeys(This,Index,ppszSubKeyName)	\
    ( (This)->lpVtbl -> EnumKeys(This,Index,ppszSubKeyName) ) 

#define ISpObjectToken_EnumValues(This,Index,ppszValueName)	\
    ( (This)->lpVtbl -> EnumValues(This,Index,ppszValueName) ) 


#define ISpObjectToken_SetId(This,pszCategoryId,pszTokenId,fCreateIfNotExist)	\
    ( (This)->lpVtbl -> SetId(This,pszCategoryId,pszTokenId,fCreateIfNotExist) ) 

#define ISpObjectToken_GetId(This,ppszCoMemTokenId)	\
    ( (This)->lpVtbl -> GetId(This,ppszCoMemTokenId) ) 

#define ISpObjectToken_GetCategory(This,ppTokenCategory)	\
    ( (This)->lpVtbl -> GetCategory(This,ppTokenCategory) ) 

#define ISpObjectToken_CreateInstance(This,pUnkOuter,dwClsContext,riid,ppvObject)	\
    ( (This)->lpVtbl -> CreateInstance(This,pUnkOuter,dwClsContext,riid,ppvObject) ) 

#define ISpObjectToken_GetStorageFileName(This,clsidCaller,pszValueName,pszFileNameSpecifier,nFolder,ppszFilePath)	\
    ( (This)->lpVtbl -> GetStorageFileName(This,clsidCaller,pszValueName,pszFileNameSpecifier,nFolder,ppszFilePath) ) 

#define ISpObjectToken_RemoveStorageFileName(This,clsidCaller,pszKeyName,fDeleteFile)	\
    ( (This)->lpVtbl -> RemoveStorageFileName(This,clsidCaller,pszKeyName,fDeleteFile) ) 

#define ISpObjectToken_Remove(This,pclsidCaller)	\
    ( (This)->lpVtbl -> Remove(This,pclsidCaller) ) 

#define ISpObjectToken_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)	\
    ( (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported) ) 

#define ISpObjectToken_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject)	\
    ( (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject) ) 

#define ISpObjectToken_MatchesAttributes(This,pszAttributes,pfMatches)	\
    ( (This)->lpVtbl -> MatchesAttributes(This,pszAttributes,pfMatches) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpObjectToken_INTERFACE_DEFINED__ */


#ifndef __ISpObjectTokenInit_INTERFACE_DEFINED__
#define __ISpObjectTokenInit_INTERFACE_DEFINED__

/* interface ISpObjectTokenInit */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpObjectTokenInit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B8AAB0CF-346F-49D8-9499-C8B03F161D51")
    ISpObjectTokenInit : public ISpObjectToken
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitFromDataKey( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszCategoryId,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTokenId,
            /* [annotation][in] */ 
            _In_  ISpDataKey *pDataKey) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpObjectTokenInitVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpObjectTokenInit * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpObjectTokenInit * This);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetData)
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG cbData,
            /* [annotation][in] */ 
            _In_  const BYTE *pData);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetData)
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  ULONG *pcbData,
            /* [annotation][out] */ 
            _Out_  BYTE *pData);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetStringValue)
        HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetStringValue)
        HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, SetDWORD)
        HRESULT ( STDMETHODCALLTYPE *SetDWORD )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][in] */ 
            _In_  DWORD dwValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, GetDWORD)
        HRESULT ( STDMETHODCALLTYPE *GetDWORD )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwValue);
        
        DECLSPEC_XFGVIRT(ISpDataKey, OpenKey)
        HRESULT ( STDMETHODCALLTYPE *OpenKey )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, CreateKey)
        HRESULT ( STDMETHODCALLTYPE *CreateKey )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, DeleteKey)
        HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSubKey);
        
        DECLSPEC_XFGVIRT(ISpDataKey, DeleteValue)
        HRESULT ( STDMETHODCALLTYPE *DeleteValue )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName);
        
        DECLSPEC_XFGVIRT(ISpDataKey, EnumKeys)
        HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName);
        
        DECLSPEC_XFGVIRT(ISpDataKey, EnumValues)
        HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValueName);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, SetId)
        HRESULT ( STDMETHODCALLTYPE *SetId )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation] */ 
            _In_opt_  LPCWSTR pszCategoryId,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTokenId,
            /* [annotation][in] */ 
            _In_  BOOL fCreateIfNotExist);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, GetId)
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemTokenId);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, GetCategory)
        HRESULT ( STDMETHODCALLTYPE *GetCategory )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectTokenCategory **ppTokenCategory);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, CreateInstance)
        HRESULT ( STDMETHODCALLTYPE *CreateInstance )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkOuter,
            /* [annotation][in] */ 
            _In_  DWORD dwClsContext,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, GetStorageFileName)
        HRESULT ( STDMETHODCALLTYPE *GetStorageFileName )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  REFCLSID clsidCaller,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszFileNameSpecifier,
            /* [annotation][in] */ 
            _In_  ULONG nFolder,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszFilePath);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, RemoveStorageFileName)
        HRESULT ( STDMETHODCALLTYPE *RemoveStorageFileName )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  REFCLSID clsidCaller,
            /* [in][annotation] */ 
            _In_  LPCWSTR pszKeyName,
            /* [annotation][in] */ 
            _In_  BOOL fDeleteFile);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, Remove)
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation] */ 
            _In_opt_  const CLSID *pclsidCaller);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, IsUISupported)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][in] */ 
            _In_  IUnknown *punkObject,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSupported);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, DisplayUI)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTitle,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][in] */ 
            _In_  IUnknown *punkObject);
        
        DECLSPEC_XFGVIRT(ISpObjectToken, MatchesAttributes)
        HRESULT ( STDMETHODCALLTYPE *MatchesAttributes )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszAttributes,
            /* [annotation][out] */ 
            _Out_  BOOL *pfMatches);
        
        DECLSPEC_XFGVIRT(ISpObjectTokenInit, InitFromDataKey)
        HRESULT ( STDMETHODCALLTYPE *InitFromDataKey )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszCategoryId,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTokenId,
            /* [annotation][in] */ 
            _In_  ISpDataKey *pDataKey);
        
        END_INTERFACE
    } ISpObjectTokenInitVtbl;

    interface ISpObjectTokenInit
    {
        CONST_VTBL struct ISpObjectTokenInitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpObjectTokenInit_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpObjectTokenInit_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpObjectTokenInit_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpObjectTokenInit_SetData(This,pszValueName,cbData,pData)	\
    ( (This)->lpVtbl -> SetData(This,pszValueName,cbData,pData) ) 

#define ISpObjectTokenInit_GetData(This,pszValueName,pcbData,pData)	\
    ( (This)->lpVtbl -> GetData(This,pszValueName,pcbData,pData) ) 

#define ISpObjectTokenInit_SetStringValue(This,pszValueName,pszValue)	\
    ( (This)->lpVtbl -> SetStringValue(This,pszValueName,pszValue) ) 

#define ISpObjectTokenInit_GetStringValue(This,pszValueName,ppszValue)	\
    ( (This)->lpVtbl -> GetStringValue(This,pszValueName,ppszValue) ) 

#define ISpObjectTokenInit_SetDWORD(This,pszValueName,dwValue)	\
    ( (This)->lpVtbl -> SetDWORD(This,pszValueName,dwValue) ) 

#define ISpObjectTokenInit_GetDWORD(This,pszValueName,pdwValue)	\
    ( (This)->lpVtbl -> GetDWORD(This,pszValueName,pdwValue) ) 

#define ISpObjectTokenInit_OpenKey(This,pszSubKeyName,ppSubKey)	\
    ( (This)->lpVtbl -> OpenKey(This,pszSubKeyName,ppSubKey) ) 

#define ISpObjectTokenInit_CreateKey(This,pszSubKey,ppSubKey)	\
    ( (This)->lpVtbl -> CreateKey(This,pszSubKey,ppSubKey) ) 

#define ISpObjectTokenInit_DeleteKey(This,pszSubKey)	\
    ( (This)->lpVtbl -> DeleteKey(This,pszSubKey) ) 

#define ISpObjectTokenInit_DeleteValue(This,pszValueName)	\
    ( (This)->lpVtbl -> DeleteValue(This,pszValueName) ) 

#define ISpObjectTokenInit_EnumKeys(This,Index,ppszSubKeyName)	\
    ( (This)->lpVtbl -> EnumKeys(This,Index,ppszSubKeyName) ) 

#define ISpObjectTokenInit_EnumValues(This,Index,ppszValueName)	\
    ( (This)->lpVtbl -> EnumValues(This,Index,ppszValueName) ) 


#define ISpObjectTokenInit_SetId(This,pszCategoryId,pszTokenId,fCreateIfNotExist)	\
    ( (This)->lpVtbl -> SetId(This,pszCategoryId,pszTokenId,fCreateIfNotExist) ) 

#define ISpObjectTokenInit_GetId(This,ppszCoMemTokenId)	\
    ( (This)->lpVtbl -> GetId(This,ppszCoMemTokenId) ) 

#define ISpObjectTokenInit_GetCategory(This,ppTokenCategory)	\
    ( (This)->lpVtbl -> GetCategory(This,ppTokenCategory) ) 

#define ISpObjectTokenInit_CreateInstance(This,pUnkOuter,dwClsContext,riid,ppvObject)	\
    ( (This)->lpVtbl -> CreateInstance(This,pUnkOuter,dwClsContext,riid,ppvObject) ) 

#define ISpObjectTokenInit_GetStorageFileName(This,clsidCaller,pszValueName,pszFileNameSpecifier,nFolder,ppszFilePath)	\
    ( (This)->lpVtbl -> GetStorageFileName(This,clsidCaller,pszValueName,pszFileNameSpecifier,nFolder,ppszFilePath) ) 

#define ISpObjectTokenInit_RemoveStorageFileName(This,clsidCaller,pszKeyName,fDeleteFile)	\
    ( (This)->lpVtbl -> RemoveStorageFileName(This,clsidCaller,pszKeyName,fDeleteFile) ) 

#define ISpObjectTokenInit_Remove(This,pclsidCaller)	\
    ( (This)->lpVtbl -> Remove(This,pclsidCaller) ) 

#define ISpObjectTokenInit_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported)	\
    ( (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,punkObject,pfSupported) ) 

#define ISpObjectTokenInit_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject)	\
    ( (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData,punkObject) ) 

#define ISpObjectTokenInit_MatchesAttributes(This,pszAttributes,pfMatches)	\
    ( (This)->lpVtbl -> MatchesAttributes(This,pszAttributes,pfMatches) ) 


#define ISpObjectTokenInit_InitFromDataKey(This,pszCategoryId,pszTokenId,pDataKey)	\
    ( (This)->lpVtbl -> InitFromDataKey(This,pszCategoryId,pszTokenId,pDataKey) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpObjectTokenInit_INTERFACE_DEFINED__ */


#ifndef __IEnumSpObjectTokens_INTERFACE_DEFINED__
#define __IEnumSpObjectTokens_INTERFACE_DEFINED__

/* interface IEnumSpObjectTokens */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumSpObjectTokens;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("06B64F9E-7FDA-11D2-B4F2-00C04F797396")
    IEnumSpObjectTokens : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  ISpObjectToken **pelt,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][in] */ 
            _In_  ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [annotation][out] */ 
            _Out_  IEnumSpObjectTokens **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Item( 
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [annotation][out] */ 
            _Out_  ISpObjectToken **ppToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [annotation][out] */ 
            _Out_  ULONG *pCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumSpObjectTokensVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumSpObjectTokens * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumSpObjectTokens * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumSpObjectTokens * This);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Next)
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumSpObjectTokens * This,
            /* [annotation][in] */ 
            _In_  ULONG celt,
            /* [annotation][length_is][size_is][out] */ 
            _Out_writes_to_(celt,*pceltFetched)  ISpObjectToken **pelt,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pceltFetched);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumSpObjectTokens * This,
            /* [annotation][in] */ 
            _In_  ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Reset)
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumSpObjectTokens * This);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumSpObjectTokens * This,
            /* [annotation][out] */ 
            _Out_  IEnumSpObjectTokens **ppEnum);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Item)
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            IEnumSpObjectTokens * This,
            /* [annotation][in] */ 
            _In_  ULONG Index,
            /* [annotation][out] */ 
            _Out_  ISpObjectToken **ppToken);
        
        DECLSPEC_XFGVIRT(IEnumSpObjectTokens, GetCount)
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumSpObjectTokens * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pCount);
        
        END_INTERFACE
    } IEnumSpObjectTokensVtbl;

    interface IEnumSpObjectTokens
    {
        CONST_VTBL struct IEnumSpObjectTokensVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSpObjectTokens_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumSpObjectTokens_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumSpObjectTokens_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumSpObjectTokens_Next(This,celt,pelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,pelt,pceltFetched) ) 

#define IEnumSpObjectTokens_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumSpObjectTokens_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumSpObjectTokens_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define IEnumSpObjectTokens_Item(This,Index,ppToken)	\
    ( (This)->lpVtbl -> Item(This,Index,ppToken) ) 

#define IEnumSpObjectTokens_GetCount(This,pCount)	\
    ( (This)->lpVtbl -> GetCount(This,pCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumSpObjectTokens_INTERFACE_DEFINED__ */


#ifndef __ISpObjectWithToken_INTERFACE_DEFINED__
#define __ISpObjectWithToken_INTERFACE_DEFINED__

/* interface ISpObjectWithToken */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpObjectWithToken;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5B559F40-E952-11D2-BB91-00C04F8EE6C0")
    ISpObjectWithToken : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetObjectToken( 
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectToken( 
            /* [annotation][out] */ 
            _Out_  ISpObjectToken **ppToken) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpObjectWithTokenVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpObjectWithToken * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpObjectWithToken * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpObjectWithToken * This);
        
        DECLSPEC_XFGVIRT(ISpObjectWithToken, SetObjectToken)
        HRESULT ( STDMETHODCALLTYPE *SetObjectToken )( 
            __RPC__in ISpObjectWithToken * This,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pToken);
        
        DECLSPEC_XFGVIRT(ISpObjectWithToken, GetObjectToken)
        HRESULT ( STDMETHODCALLTYPE *GetObjectToken )( 
            __RPC__in ISpObjectWithToken * This,
            /* [annotation][out] */ 
            _Out_  ISpObjectToken **ppToken);
        
        END_INTERFACE
    } ISpObjectWithTokenVtbl;

    interface ISpObjectWithToken
    {
        CONST_VTBL struct ISpObjectWithTokenVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpObjectWithToken_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpObjectWithToken_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpObjectWithToken_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpObjectWithToken_SetObjectToken(This,pToken)	\
    ( (This)->lpVtbl -> SetObjectToken(This,pToken) ) 

#define ISpObjectWithToken_GetObjectToken(This,ppToken)	\
    ( (This)->lpVtbl -> GetObjectToken(This,ppToken) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpObjectWithToken_INTERFACE_DEFINED__ */


#ifndef __ISpResourceManager_INTERFACE_DEFINED__
#define __ISpResourceManager_INTERFACE_DEFINED__

/* interface ISpResourceManager */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpResourceManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("93384E18-5014-43D5-ADBB-A78E055926BD")
    ISpResourceManager : public IServiceProvider
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetObject( 
            /* [annotation][in] */ 
            _In_  REFGUID guidServiceId,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObject( 
            /* [annotation][in] */ 
            _In_  REFGUID guidServiceId,
            /* [annotation][in] */ 
            _In_  REFCLSID ObjectCLSID,
            /* [annotation][in] */ 
            _In_  REFIID ObjectIID,
            /* [annotation][in] */ 
            _In_  BOOL fReleaseWhenLastExternalRefReleased,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpResourceManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpResourceManager * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpResourceManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpResourceManager * This);
        
        DECLSPEC_XFGVIRT(IServiceProvider, QueryService)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *QueryService )( 
            ISpResourceManager * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidService,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(ISpResourceManager, SetObject)
        HRESULT ( STDMETHODCALLTYPE *SetObject )( 
            __RPC__in ISpResourceManager * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidServiceId,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkObject);
        
        DECLSPEC_XFGVIRT(ISpResourceManager, GetObject)
        HRESULT ( STDMETHODCALLTYPE *GetObject )( 
            __RPC__in ISpResourceManager * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidServiceId,
            /* [annotation][in] */ 
            _In_  REFCLSID ObjectCLSID,
            /* [annotation][in] */ 
            _In_  REFIID ObjectIID,
            /* [annotation][in] */ 
            _In_  BOOL fReleaseWhenLastExternalRefReleased,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppObject);
        
        END_INTERFACE
    } ISpResourceManagerVtbl;

    interface ISpResourceManager
    {
        CONST_VTBL struct ISpResourceManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpResourceManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpResourceManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpResourceManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpResourceManager_QueryService(This,guidService,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryService(This,guidService,riid,ppvObject) ) 


#define ISpResourceManager_SetObject(This,guidServiceId,pUnkObject)	\
    ( (This)->lpVtbl -> SetObject(This,guidServiceId,pUnkObject) ) 

#define ISpResourceManager_GetObject(This,guidServiceId,ObjectCLSID,ObjectIID,fReleaseWhenLastExternalRefReleased,ppObject)	\
    ( (This)->lpVtbl -> GetObject(This,guidServiceId,ObjectCLSID,ObjectIID,fReleaseWhenLastExternalRefReleased,ppObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpResourceManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0011 */
/* [local] */ 

typedef /* [hidden] */ 
enum SPEVENTLPARAMTYPE
    {
        SPET_LPARAM_IS_UNDEFINED	= 0,
        SPET_LPARAM_IS_TOKEN	= ( SPET_LPARAM_IS_UNDEFINED + 1 ) ,
        SPET_LPARAM_IS_OBJECT	= ( SPET_LPARAM_IS_TOKEN + 1 ) ,
        SPET_LPARAM_IS_POINTER	= ( SPET_LPARAM_IS_OBJECT + 1 ) ,
        SPET_LPARAM_IS_STRING	= ( SPET_LPARAM_IS_POINTER + 1 ) 
    } 	SPEVENTLPARAMTYPE;

typedef /* [hidden] */ 
enum SPEVENTENUM
    {
        SPEI_UNDEFINED	= 0,
        SPEI_START_INPUT_STREAM	= 1,
        SPEI_END_INPUT_STREAM	= 2,
        SPEI_VOICE_CHANGE	= 3,
        SPEI_TTS_BOOKMARK	= 4,
        SPEI_WORD_BOUNDARY	= 5,
        SPEI_PHONEME	= 6,
        SPEI_SENTENCE_BOUNDARY	= 7,
        SPEI_VISEME	= 8,
        SPEI_TTS_AUDIO_LEVEL	= 9,
        SPEI_TTS_PRIVATE	= 15,
        SPEI_MIN_TTS	= 1,
        SPEI_MAX_TTS	= 15,
        SPEI_END_SR_STREAM	= 34,
        SPEI_SOUND_START	= 35,
        SPEI_SOUND_END	= 36,
        SPEI_PHRASE_START	= 37,
        SPEI_RECOGNITION	= 38,
        SPEI_HYPOTHESIS	= 39,
        SPEI_SR_BOOKMARK	= 40,
        SPEI_PROPERTY_NUM_CHANGE	= 41,
        SPEI_PROPERTY_STRING_CHANGE	= 42,
        SPEI_FALSE_RECOGNITION	= 43,
        SPEI_INTERFERENCE	= 44,
        SPEI_REQUEST_UI	= 45,
        SPEI_RECO_STATE_CHANGE	= 46,
        SPEI_ADAPTATION	= 47,
        SPEI_START_SR_STREAM	= 48,
        SPEI_RECO_OTHER_CONTEXT	= 49,
        SPEI_SR_AUDIO_LEVEL	= 50,
        SPEI_SR_RETAINEDAUDIO	= 51,
        SPEI_SR_PRIVATE	= 52,
        SPEI_ACTIVE_CATEGORY_CHANGED	= 53,
        SPEI_RESERVED5	= 54,
        SPEI_RESERVED6	= 55,
        SPEI_MIN_SR	= 34,
        SPEI_MAX_SR	= 55,
        SPEI_RESERVED1	= 30,
        SPEI_RESERVED2	= 33,
        SPEI_RESERVED3	= 63
    } 	SPEVENTENUM;

#define SPFEI_FLAGCHECK ( (1ui64 << SPEI_RESERVED1) | (1ui64 << SPEI_RESERVED2) )
#define SPFEI_ALL_TTS_EVENTS (0x000000000000FFFEui64 | SPFEI_FLAGCHECK)
#define SPFEI_ALL_SR_EVENTS  (0x003FFFFC00000000ui64 | SPFEI_FLAGCHECK)
#define SPFEI_ALL_EVENTS      0xEFFFFFFFFFFFFFFFui64
#define SPFEI(SPEI_ord) ((1ui64 << SPEI_ord) | SPFEI_FLAGCHECK)
#if 0
typedef /* [hidden][restricted] */ struct SPEVENT
    {
    WORD eEventId;
    WORD elParamType;
    ULONG ulStreamNum;
    ULONGLONG ullAudioStreamOffset;
    WPARAM wParam;
    LPARAM lParam;
    } 	SPEVENT;

typedef /* [hidden][restricted] */ struct SPSERIALIZEDEVENT
    {
    WORD eEventId;
    WORD elParamType;
    ULONG ulStreamNum;
    ULONGLONG ullAudioStreamOffset;
    ULONG SerializedwParam;
    LONG SerializedlParam;
    } 	SPSERIALIZEDEVENT;

typedef /* [hidden][restricted] */ struct SPSERIALIZEDEVENT64
    {
    WORD eEventId;
    WORD elParamType;
    ULONG ulStreamNum;
    ULONGLONG ullAudioStreamOffset;
    ULONGLONG SerializedwParam;
    LONGLONG SerializedlParam;
    } 	SPSERIALIZEDEVENT64;

#else
typedef struct SPEVENT
{
    SPEVENTENUM        eEventId : 16;
    SPEVENTLPARAMTYPE  elParamType : 16;
    ULONG       ulStreamNum;
    ULONGLONG   ullAudioStreamOffset;
    WPARAM      wParam;
    LPARAM      lParam;
} SPEVENT;
typedef struct SPSERIALIZEDEVENT
{
    SPEVENTENUM        eEventId : 16;
    SPEVENTLPARAMTYPE  elParamType : 16;
    ULONG       ulStreamNum;
    ULONGLONG   ullAudioStreamOffset;
    ULONG       SerializedwParam;
    LONG        SerializedlParam;
} SPSERIALIZEDEVENT;
typedef struct SPSERIALIZEDEVENT64
{
    SPEVENTENUM        eEventId : 16;
    SPEVENTLPARAMTYPE  elParamType : 16;
    ULONG       ulStreamNum;
    ULONGLONG   ullAudioStreamOffset;
    ULONGLONG   SerializedwParam;
    LONGLONG    SerializedlParam;
} SPSERIALIZEDEVENT64;
#endif
#if 0
typedef /* [hidden][restricted] */ struct SPEVENTEX
    {
    WORD eEventId;
    WORD elParamType;
    ULONG ulStreamNum;
    ULONGLONG ullAudioStreamOffset;
    WPARAM wParam;
    LPARAM lParam;
    ULONGLONG ullAudioTimeOffset;
    } 	SPEVENTEX;

#else
typedef struct SPEVENTEX
{
    SPEVENTENUM        eEventId : 16;
    SPEVENTLPARAMTYPE  elParamType : 16;
    ULONG       ulStreamNum;
    ULONGLONG   ullAudioStreamOffset;
    WPARAM      wParam;
    LPARAM      lParam;
    ULONGLONG   ullAudioTimeOffset;
} SPEVENTEX;
#endif
typedef /* [hidden] */ 
enum SPINTERFERENCE
    {
        SPINTERFERENCE_NONE	= 0,
        SPINTERFERENCE_NOISE	= ( SPINTERFERENCE_NONE + 1 ) ,
        SPINTERFERENCE_NOSIGNAL	= ( SPINTERFERENCE_NOISE + 1 ) ,
        SPINTERFERENCE_TOOLOUD	= ( SPINTERFERENCE_NOSIGNAL + 1 ) ,
        SPINTERFERENCE_TOOQUIET	= ( SPINTERFERENCE_TOOLOUD + 1 ) ,
        SPINTERFERENCE_TOOFAST	= ( SPINTERFERENCE_TOOQUIET + 1 ) ,
        SPINTERFERENCE_TOOSLOW	= ( SPINTERFERENCE_TOOFAST + 1 ) ,
        SPINTERFERENCE_LATENCY_WARNING	= ( SPINTERFERENCE_TOOSLOW + 1 ) ,
        SPINTERFERENCE_LATENCY_TRUNCATE_BEGIN	= ( SPINTERFERENCE_LATENCY_WARNING + 1 ) ,
        SPINTERFERENCE_LATENCY_TRUNCATE_END	= ( SPINTERFERENCE_LATENCY_TRUNCATE_BEGIN + 1 ) 
    } 	SPINTERFERENCE;

typedef /* [hidden] */ 
enum SPENDSRSTREAMFLAGS
    {
        SPESF_NONE	= 0,
        SPESF_STREAM_RELEASED	= ( 1 << 0 ) ,
        SPESF_EMULATED	= ( 1 << 1 ) 
    } 	SPENDSRSTREAMFLAGS;

typedef /* [hidden] */ 
enum SPVFEATURE
    {
        SPVFEATURE_STRESSED	= ( 1L << 0 ) ,
        SPVFEATURE_EMPHASIS	= ( 1L << 1 ) 
    } 	SPVFEATURE;

typedef /* [hidden] */ 
enum SPVISEMES
    {
        SP_VISEME_0	= 0,
        SP_VISEME_1	= ( SP_VISEME_0 + 1 ) ,
        SP_VISEME_2	= ( SP_VISEME_1 + 1 ) ,
        SP_VISEME_3	= ( SP_VISEME_2 + 1 ) ,
        SP_VISEME_4	= ( SP_VISEME_3 + 1 ) ,
        SP_VISEME_5	= ( SP_VISEME_4 + 1 ) ,
        SP_VISEME_6	= ( SP_VISEME_5 + 1 ) ,
        SP_VISEME_7	= ( SP_VISEME_6 + 1 ) ,
        SP_VISEME_8	= ( SP_VISEME_7 + 1 ) ,
        SP_VISEME_9	= ( SP_VISEME_8 + 1 ) ,
        SP_VISEME_10	= ( SP_VISEME_9 + 1 ) ,
        SP_VISEME_11	= ( SP_VISEME_10 + 1 ) ,
        SP_VISEME_12	= ( SP_VISEME_11 + 1 ) ,
        SP_VISEME_13	= ( SP_VISEME_12 + 1 ) ,
        SP_VISEME_14	= ( SP_VISEME_13 + 1 ) ,
        SP_VISEME_15	= ( SP_VISEME_14 + 1 ) ,
        SP_VISEME_16	= ( SP_VISEME_15 + 1 ) ,
        SP_VISEME_17	= ( SP_VISEME_16 + 1 ) ,
        SP_VISEME_18	= ( SP_VISEME_17 + 1 ) ,
        SP_VISEME_19	= ( SP_VISEME_18 + 1 ) ,
        SP_VISEME_20	= ( SP_VISEME_19 + 1 ) ,
        SP_VISEME_21	= ( SP_VISEME_20 + 1 ) 
    } 	SPVISEMES;

typedef /* [hidden][restricted] */ struct SPEVENTSOURCEINFO
    {
    ULONGLONG ullEventInterest;
    ULONGLONG ullQueuedInterest;
    ULONG ulCount;
    } 	SPEVENTSOURCEINFO;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0011_v0_0_s_ifspec;

#ifndef __ISpEventSource_INTERFACE_DEFINED__
#define __ISpEventSource_INTERFACE_DEFINED__

/* interface ISpEventSource */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpEventSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BE7A9CCE-5F9E-11D2-960F-00C04F8EE628")
    ISpEventSource : public ISpNotifySource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetInterest( 
            /* [annotation][in] */ 
            _In_  ULONGLONG ullEventInterest,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullQueuedInterest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEvents( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  SPEVENT *pEventArray,
            /* [annotation][out] */ 
            _Out_  ULONG *pulFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInfo( 
            /* [annotation][out] */ 
            _Out_  SPEVENTSOURCEINFO *pInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpEventSourceVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpEventSource * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpEventSource * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpEventSource * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifySink)
        HRESULT ( STDMETHODCALLTYPE *SetNotifySink )( 
            ISpEventSource * This,
            /* [annotation][in] */ 
            _In_  ISpNotifySink *pNotifySink);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWindowMessage)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWindowMessage )( 
            ISpEventSource * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT Msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackFunction)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackFunction )( 
            ISpEventSource * This,
            /* [annotation][in] */ 
            _In_  SPNOTIFYCALLBACK *pfnCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackInterface)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackInterface )( 
            ISpEventSource * This,
            /* [annotation][in] */ 
            _In_  ISpNotifyCallback *pSpCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWin32Event)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWin32Event )( 
            ISpEventSource * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, WaitForNotifyEvent)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *WaitForNotifyEvent )( 
            ISpEventSource * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMilliseconds);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, GetNotifyEventHandle)
        /* [local] */ HANDLE ( STDMETHODCALLTYPE *GetNotifyEventHandle )( 
            ISpEventSource * This);
        
        DECLSPEC_XFGVIRT(ISpEventSource, SetInterest)
        HRESULT ( STDMETHODCALLTYPE *SetInterest )( 
            ISpEventSource * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullEventInterest,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullQueuedInterest);
        
        DECLSPEC_XFGVIRT(ISpEventSource, GetEvents)
        HRESULT ( STDMETHODCALLTYPE *GetEvents )( 
            ISpEventSource * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  SPEVENT *pEventArray,
            /* [annotation][out] */ 
            _Out_  ULONG *pulFetched);
        
        DECLSPEC_XFGVIRT(ISpEventSource, GetInfo)
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            ISpEventSource * This,
            /* [annotation][out] */ 
            _Out_  SPEVENTSOURCEINFO *pInfo);
        
        END_INTERFACE
    } ISpEventSourceVtbl;

    interface ISpEventSource
    {
        CONST_VTBL struct ISpEventSourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpEventSource_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpEventSource_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpEventSource_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpEventSource_SetNotifySink(This,pNotifySink)	\
    ( (This)->lpVtbl -> SetNotifySink(This,pNotifySink) ) 

#define ISpEventSource_SetNotifyWindowMessage(This,hWnd,Msg,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyWindowMessage(This,hWnd,Msg,wParam,lParam) ) 

#define ISpEventSource_SetNotifyCallbackFunction(This,pfnCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyCallbackFunction(This,pfnCallback,wParam,lParam) ) 

#define ISpEventSource_SetNotifyCallbackInterface(This,pSpCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyCallbackInterface(This,pSpCallback,wParam,lParam) ) 

#define ISpEventSource_SetNotifyWin32Event(This)	\
    ( (This)->lpVtbl -> SetNotifyWin32Event(This) ) 

#define ISpEventSource_WaitForNotifyEvent(This,dwMilliseconds)	\
    ( (This)->lpVtbl -> WaitForNotifyEvent(This,dwMilliseconds) ) 

#define ISpEventSource_GetNotifyEventHandle(This)	\
    ( (This)->lpVtbl -> GetNotifyEventHandle(This) ) 


#define ISpEventSource_SetInterest(This,ullEventInterest,ullQueuedInterest)	\
    ( (This)->lpVtbl -> SetInterest(This,ullEventInterest,ullQueuedInterest) ) 

#define ISpEventSource_GetEvents(This,ulCount,pEventArray,pulFetched)	\
    ( (This)->lpVtbl -> GetEvents(This,ulCount,pEventArray,pulFetched) ) 

#define ISpEventSource_GetInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetInfo(This,pInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpEventSource_INTERFACE_DEFINED__ */


#ifndef __ISpEventSource2_INTERFACE_DEFINED__
#define __ISpEventSource2_INTERFACE_DEFINED__

/* interface ISpEventSource2 */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpEventSource2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2373A435-6A4B-429e-A6AC-D4231A61975B")
    ISpEventSource2 : public ISpEventSource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEventsEx( 
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  SPEVENTEX *pEventArray,
            /* [annotation][out] */ 
            _Out_  ULONG *pulFetched) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpEventSource2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpEventSource2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpEventSource2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpEventSource2 * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifySink)
        HRESULT ( STDMETHODCALLTYPE *SetNotifySink )( 
            ISpEventSource2 * This,
            /* [annotation][in] */ 
            _In_  ISpNotifySink *pNotifySink);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWindowMessage)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWindowMessage )( 
            ISpEventSource2 * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT Msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackFunction)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackFunction )( 
            ISpEventSource2 * This,
            /* [annotation][in] */ 
            _In_  SPNOTIFYCALLBACK *pfnCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackInterface)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackInterface )( 
            ISpEventSource2 * This,
            /* [annotation][in] */ 
            _In_  ISpNotifyCallback *pSpCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWin32Event)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWin32Event )( 
            ISpEventSource2 * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, WaitForNotifyEvent)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *WaitForNotifyEvent )( 
            ISpEventSource2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMilliseconds);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, GetNotifyEventHandle)
        /* [local] */ HANDLE ( STDMETHODCALLTYPE *GetNotifyEventHandle )( 
            ISpEventSource2 * This);
        
        DECLSPEC_XFGVIRT(ISpEventSource, SetInterest)
        HRESULT ( STDMETHODCALLTYPE *SetInterest )( 
            ISpEventSource2 * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullEventInterest,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullQueuedInterest);
        
        DECLSPEC_XFGVIRT(ISpEventSource, GetEvents)
        HRESULT ( STDMETHODCALLTYPE *GetEvents )( 
            ISpEventSource2 * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  SPEVENT *pEventArray,
            /* [annotation][out] */ 
            _Out_  ULONG *pulFetched);
        
        DECLSPEC_XFGVIRT(ISpEventSource, GetInfo)
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            ISpEventSource2 * This,
            /* [annotation][out] */ 
            _Out_  SPEVENTSOURCEINFO *pInfo);
        
        DECLSPEC_XFGVIRT(ISpEventSource2, GetEventsEx)
        HRESULT ( STDMETHODCALLTYPE *GetEventsEx )( 
            ISpEventSource2 * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  SPEVENTEX *pEventArray,
            /* [annotation][out] */ 
            _Out_  ULONG *pulFetched);
        
        END_INTERFACE
    } ISpEventSource2Vtbl;

    interface ISpEventSource2
    {
        CONST_VTBL struct ISpEventSource2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpEventSource2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpEventSource2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpEventSource2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpEventSource2_SetNotifySink(This,pNotifySink)	\
    ( (This)->lpVtbl -> SetNotifySink(This,pNotifySink) ) 

#define ISpEventSource2_SetNotifyWindowMessage(This,hWnd,Msg,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyWindowMessage(This,hWnd,Msg,wParam,lParam) ) 

#define ISpEventSource2_SetNotifyCallbackFunction(This,pfnCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyCallbackFunction(This,pfnCallback,wParam,lParam) ) 

#define ISpEventSource2_SetNotifyCallbackInterface(This,pSpCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyCallbackInterface(This,pSpCallback,wParam,lParam) ) 

#define ISpEventSource2_SetNotifyWin32Event(This)	\
    ( (This)->lpVtbl -> SetNotifyWin32Event(This) ) 

#define ISpEventSource2_WaitForNotifyEvent(This,dwMilliseconds)	\
    ( (This)->lpVtbl -> WaitForNotifyEvent(This,dwMilliseconds) ) 

#define ISpEventSource2_GetNotifyEventHandle(This)	\
    ( (This)->lpVtbl -> GetNotifyEventHandle(This) ) 


#define ISpEventSource2_SetInterest(This,ullEventInterest,ullQueuedInterest)	\
    ( (This)->lpVtbl -> SetInterest(This,ullEventInterest,ullQueuedInterest) ) 

#define ISpEventSource2_GetEvents(This,ulCount,pEventArray,pulFetched)	\
    ( (This)->lpVtbl -> GetEvents(This,ulCount,pEventArray,pulFetched) ) 

#define ISpEventSource2_GetInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetInfo(This,pInfo) ) 


#define ISpEventSource2_GetEventsEx(This,ulCount,pEventArray,pulFetched)	\
    ( (This)->lpVtbl -> GetEventsEx(This,ulCount,pEventArray,pulFetched) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpEventSource2_INTERFACE_DEFINED__ */


#ifndef __ISpEventSink_INTERFACE_DEFINED__
#define __ISpEventSink_INTERFACE_DEFINED__

/* interface ISpEventSink */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpEventSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BE7A9CC9-5F9E-11D2-960F-00C04F8EE628")
    ISpEventSink : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddEvents( 
            /* [annotation][in] */ 
            _In_  const SPEVENT *pEventArray,
            /* [annotation][in] */ 
            _In_  ULONG ulCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEventInterest( 
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pullEventInterest) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpEventSinkVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpEventSink * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpEventSink * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpEventSink * This);
        
        DECLSPEC_XFGVIRT(ISpEventSink, AddEvents)
        HRESULT ( STDMETHODCALLTYPE *AddEvents )( 
            ISpEventSink * This,
            /* [annotation][in] */ 
            _In_  const SPEVENT *pEventArray,
            /* [annotation][in] */ 
            _In_  ULONG ulCount);
        
        DECLSPEC_XFGVIRT(ISpEventSink, GetEventInterest)
        HRESULT ( STDMETHODCALLTYPE *GetEventInterest )( 
            ISpEventSink * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pullEventInterest);
        
        END_INTERFACE
    } ISpEventSinkVtbl;

    interface ISpEventSink
    {
        CONST_VTBL struct ISpEventSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpEventSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpEventSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpEventSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpEventSink_AddEvents(This,pEventArray,ulCount)	\
    ( (This)->lpVtbl -> AddEvents(This,pEventArray,ulCount) ) 

#define ISpEventSink_GetEventInterest(This,pullEventInterest)	\
    ( (This)->lpVtbl -> GetEventInterest(This,pullEventInterest) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpEventSink_INTERFACE_DEFINED__ */


#ifndef __ISpStreamFormat_INTERFACE_DEFINED__
#define __ISpStreamFormat_INTERFACE_DEFINED__

/* interface ISpStreamFormat */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpStreamFormat;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BED530BE-2606-4F4D-A1C0-54C5CDA5566F")
    ISpStreamFormat : public IStream
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFormat( 
            /* [annotation][in] */ 
            _In_  GUID *pguidFormatId,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppCoMemWaveFormatEx) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpStreamFormatVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpStreamFormat * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpStreamFormat * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpStreamFormat * This);
        
        DECLSPEC_XFGVIRT(ISequentialStream, Read)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpStreamFormat * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        DECLSPEC_XFGVIRT(ISequentialStream, Write)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpStreamFormat * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        DECLSPEC_XFGVIRT(IStream, Seek)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            ISpStreamFormat * This,
            /* [annotation][in] */ 
            _In_  LARGE_INTEGER dlibMove,
            /* [annotation][in] */ 
            _In_  DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        DECLSPEC_XFGVIRT(IStream, SetSize)
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            __RPC__in ISpStreamFormat * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libNewSize);
        
        DECLSPEC_XFGVIRT(IStream, CopyTo)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            ISpStreamFormat * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        DECLSPEC_XFGVIRT(IStream, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in ISpStreamFormat * This,
            /* [annotation][in] */ 
            _In_  DWORD grfCommitFlags);
        
        DECLSPEC_XFGVIRT(IStream, Revert)
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            __RPC__in ISpStreamFormat * This);
        
        DECLSPEC_XFGVIRT(IStream, LockRegion)
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            __RPC__in ISpStreamFormat * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        DECLSPEC_XFGVIRT(IStream, UnlockRegion)
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            __RPC__in ISpStreamFormat * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        DECLSPEC_XFGVIRT(IStream, Stat)
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            __RPC__in ISpStreamFormat * This,
            /* [annotation][out] */ 
            _Out_  STATSTG *pstatstg,
            /* [annotation][in] */ 
            _In_  DWORD grfStatFlag);
        
        DECLSPEC_XFGVIRT(IStream, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in ISpStreamFormat * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppstm);
        
        DECLSPEC_XFGVIRT(ISpStreamFormat, GetFormat)
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            __RPC__in ISpStreamFormat * This,
            /* [annotation][in] */ 
            _In_  GUID *pguidFormatId,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        END_INTERFACE
    } ISpStreamFormatVtbl;

    interface ISpStreamFormat
    {
        CONST_VTBL struct ISpStreamFormatVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpStreamFormat_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpStreamFormat_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpStreamFormat_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpStreamFormat_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define ISpStreamFormat_Write(This,pv,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pv,cb,pcbWritten) ) 


#define ISpStreamFormat_Seek(This,dlibMove,dwOrigin,plibNewPosition)	\
    ( (This)->lpVtbl -> Seek(This,dlibMove,dwOrigin,plibNewPosition) ) 

#define ISpStreamFormat_SetSize(This,libNewSize)	\
    ( (This)->lpVtbl -> SetSize(This,libNewSize) ) 

#define ISpStreamFormat_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    ( (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten) ) 

#define ISpStreamFormat_Commit(This,grfCommitFlags)	\
    ( (This)->lpVtbl -> Commit(This,grfCommitFlags) ) 

#define ISpStreamFormat_Revert(This)	\
    ( (This)->lpVtbl -> Revert(This) ) 

#define ISpStreamFormat_LockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType) ) 

#define ISpStreamFormat_UnlockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType) ) 

#define ISpStreamFormat_Stat(This,pstatstg,grfStatFlag)	\
    ( (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag) ) 

#define ISpStreamFormat_Clone(This,ppstm)	\
    ( (This)->lpVtbl -> Clone(This,ppstm) ) 


#define ISpStreamFormat_GetFormat(This,pguidFormatId,ppCoMemWaveFormatEx)	\
    ( (This)->lpVtbl -> GetFormat(This,pguidFormatId,ppCoMemWaveFormatEx) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpStreamFormat_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0015 */
/* [local] */ 

typedef /* [hidden] */ 
enum SPFILEMODE
    {
        SPFM_OPEN_READONLY	= 0,
        SPFM_OPEN_READWRITE	= ( SPFM_OPEN_READONLY + 1 ) ,
        SPFM_CREATE	= ( SPFM_OPEN_READWRITE + 1 ) ,
        SPFM_CREATE_ALWAYS	= ( SPFM_CREATE + 1 ) ,
        SPFM_NUM_MODES	= ( SPFM_CREATE_ALWAYS + 1 ) 
    } 	SPFILEMODE;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0015_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0015_v0_0_s_ifspec;

#ifndef __ISpStream_INTERFACE_DEFINED__
#define __ISpStream_INTERFACE_DEFINED__

/* interface ISpStream */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("12E3CCA9-7518-44C5-A5E7-BA5A79CB929E")
    ISpStream : public ISpStreamFormat
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetBaseStream( 
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  REFGUID rguidFormat,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBaseStream( 
            /* [out][annotation] */ 
            _Outptr_  IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindToFile( 
            /* [in][annotation] */ 
            _In_z_  LPCWSTR pszFileName,
            /* [annotation][in] */ 
            _In_  SPFILEMODE eMode,
            /* [in][annotation] */ 
            _In_opt_  const GUID *pFormatId,
            /* [annotation] */ 
            _In_opt_  const WAVEFORMATEX *pWaveFormatEx,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullEventInterest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpStreamVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpStream * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpStream * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpStream * This);
        
        DECLSPEC_XFGVIRT(ISequentialStream, Read)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpStream * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        DECLSPEC_XFGVIRT(ISequentialStream, Write)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpStream * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        DECLSPEC_XFGVIRT(IStream, Seek)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            ISpStream * This,
            /* [annotation][in] */ 
            _In_  LARGE_INTEGER dlibMove,
            /* [annotation][in] */ 
            _In_  DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        DECLSPEC_XFGVIRT(IStream, SetSize)
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            ISpStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libNewSize);
        
        DECLSPEC_XFGVIRT(IStream, CopyTo)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            ISpStream * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        DECLSPEC_XFGVIRT(IStream, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpStream * This,
            /* [annotation][in] */ 
            _In_  DWORD grfCommitFlags);
        
        DECLSPEC_XFGVIRT(IStream, Revert)
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            ISpStream * This);
        
        DECLSPEC_XFGVIRT(IStream, LockRegion)
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            ISpStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        DECLSPEC_XFGVIRT(IStream, UnlockRegion)
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            ISpStream * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        DECLSPEC_XFGVIRT(IStream, Stat)
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            ISpStream * This,
            /* [annotation][out] */ 
            _Out_  STATSTG *pstatstg,
            /* [annotation][in] */ 
            _In_  DWORD grfStatFlag);
        
        DECLSPEC_XFGVIRT(IStream, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISpStream * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppstm);
        
        DECLSPEC_XFGVIRT(ISpStreamFormat, GetFormat)
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            ISpStream * This,
            /* [annotation][in] */ 
            _In_  GUID *pguidFormatId,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpStream, SetBaseStream)
        HRESULT ( STDMETHODCALLTYPE *SetBaseStream )( 
            ISpStream * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  REFGUID rguidFormat,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpStream, GetBaseStream)
        HRESULT ( STDMETHODCALLTYPE *GetBaseStream )( 
            ISpStream * This,
            /* [out][annotation] */ 
            _Outptr_  IStream **ppStream);
        
        DECLSPEC_XFGVIRT(ISpStream, BindToFile)
        HRESULT ( STDMETHODCALLTYPE *BindToFile )( 
            ISpStream * This,
            /* [in][annotation] */ 
            _In_z_  LPCWSTR pszFileName,
            /* [annotation][in] */ 
            _In_  SPFILEMODE eMode,
            /* [in][annotation] */ 
            _In_opt_  const GUID *pFormatId,
            /* [annotation] */ 
            _In_opt_  const WAVEFORMATEX *pWaveFormatEx,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullEventInterest);
        
        DECLSPEC_XFGVIRT(ISpStream, Close)
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            ISpStream * This);
        
        END_INTERFACE
    } ISpStreamVtbl;

    interface ISpStream
    {
        CONST_VTBL struct ISpStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpStream_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define ISpStream_Write(This,pv,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pv,cb,pcbWritten) ) 


#define ISpStream_Seek(This,dlibMove,dwOrigin,plibNewPosition)	\
    ( (This)->lpVtbl -> Seek(This,dlibMove,dwOrigin,plibNewPosition) ) 

#define ISpStream_SetSize(This,libNewSize)	\
    ( (This)->lpVtbl -> SetSize(This,libNewSize) ) 

#define ISpStream_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    ( (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten) ) 

#define ISpStream_Commit(This,grfCommitFlags)	\
    ( (This)->lpVtbl -> Commit(This,grfCommitFlags) ) 

#define ISpStream_Revert(This)	\
    ( (This)->lpVtbl -> Revert(This) ) 

#define ISpStream_LockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType) ) 

#define ISpStream_UnlockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType) ) 

#define ISpStream_Stat(This,pstatstg,grfStatFlag)	\
    ( (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag) ) 

#define ISpStream_Clone(This,ppstm)	\
    ( (This)->lpVtbl -> Clone(This,ppstm) ) 


#define ISpStream_GetFormat(This,pguidFormatId,ppCoMemWaveFormatEx)	\
    ( (This)->lpVtbl -> GetFormat(This,pguidFormatId,ppCoMemWaveFormatEx) ) 


#define ISpStream_SetBaseStream(This,pStream,rguidFormat,pWaveFormatEx)	\
    ( (This)->lpVtbl -> SetBaseStream(This,pStream,rguidFormat,pWaveFormatEx) ) 

#define ISpStream_GetBaseStream(This,ppStream)	\
    ( (This)->lpVtbl -> GetBaseStream(This,ppStream) ) 

#define ISpStream_BindToFile(This,pszFileName,eMode,pFormatId,pWaveFormatEx,ullEventInterest)	\
    ( (This)->lpVtbl -> BindToFile(This,pszFileName,eMode,pFormatId,pWaveFormatEx,ullEventInterest) ) 

#define ISpStream_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpStream_INTERFACE_DEFINED__ */


#ifndef __ISpStreamFormatConverter_INTERFACE_DEFINED__
#define __ISpStreamFormatConverter_INTERFACE_DEFINED__

/* interface ISpStreamFormatConverter */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpStreamFormatConverter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("678A932C-EA71-4446-9B41-78FDA6280A29")
    ISpStreamFormatConverter : public ISpStreamFormat
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetBaseStream( 
            /* [annotation][in] */ 
            _In_  ISpStreamFormat *pStream,
            /* [annotation][in] */ 
            _In_  BOOL fSetFormatToBaseStreamFormat,
            /* [annotation][in] */ 
            _In_  BOOL fWriteToBaseStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBaseStream( 
            /* [annotation][out] */ 
            _Out_  ISpStreamFormat **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFormat( 
            /* [annotation][in] */ 
            _In_  REFGUID rguidFormatIdOfConvertedStream,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatExOfConvertedStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetSeekPosition( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScaleConvertedToBaseOffset( 
            /* [annotation][in] */ 
            _In_  ULONGLONG ullOffsetConvertedStream,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pullOffsetBaseStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScaleBaseToConvertedOffset( 
            /* [annotation][in] */ 
            _In_  ULONGLONG ullOffsetBaseStream,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pullOffsetConvertedStream) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpStreamFormatConverterVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpStreamFormatConverter * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpStreamFormatConverter * This);
        
        DECLSPEC_XFGVIRT(ISequentialStream, Read)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpStreamFormatConverter * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        DECLSPEC_XFGVIRT(ISequentialStream, Write)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpStreamFormatConverter * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        DECLSPEC_XFGVIRT(IStream, Seek)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            ISpStreamFormatConverter * This,
            /* [annotation][in] */ 
            _In_  LARGE_INTEGER dlibMove,
            /* [annotation][in] */ 
            _In_  DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        DECLSPEC_XFGVIRT(IStream, SetSize)
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libNewSize);
        
        DECLSPEC_XFGVIRT(IStream, CopyTo)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            ISpStreamFormatConverter * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        DECLSPEC_XFGVIRT(IStream, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][in] */ 
            _In_  DWORD grfCommitFlags);
        
        DECLSPEC_XFGVIRT(IStream, Revert)
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            __RPC__in ISpStreamFormatConverter * This);
        
        DECLSPEC_XFGVIRT(IStream, LockRegion)
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        DECLSPEC_XFGVIRT(IStream, UnlockRegion)
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        DECLSPEC_XFGVIRT(IStream, Stat)
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][out] */ 
            _Out_  STATSTG *pstatstg,
            /* [annotation][in] */ 
            _In_  DWORD grfStatFlag);
        
        DECLSPEC_XFGVIRT(IStream, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppstm);
        
        DECLSPEC_XFGVIRT(ISpStreamFormat, GetFormat)
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][in] */ 
            _In_  GUID *pguidFormatId,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpStreamFormatConverter, SetBaseStream)
        HRESULT ( STDMETHODCALLTYPE *SetBaseStream )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][in] */ 
            _In_  ISpStreamFormat *pStream,
            /* [annotation][in] */ 
            _In_  BOOL fSetFormatToBaseStreamFormat,
            /* [annotation][in] */ 
            _In_  BOOL fWriteToBaseStream);
        
        DECLSPEC_XFGVIRT(ISpStreamFormatConverter, GetBaseStream)
        HRESULT ( STDMETHODCALLTYPE *GetBaseStream )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][out] */ 
            _Out_  ISpStreamFormat **ppStream);
        
        DECLSPEC_XFGVIRT(ISpStreamFormatConverter, SetFormat)
        HRESULT ( STDMETHODCALLTYPE *SetFormat )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguidFormatIdOfConvertedStream,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatExOfConvertedStream);
        
        DECLSPEC_XFGVIRT(ISpStreamFormatConverter, ResetSeekPosition)
        HRESULT ( STDMETHODCALLTYPE *ResetSeekPosition )( 
            __RPC__in ISpStreamFormatConverter * This);
        
        DECLSPEC_XFGVIRT(ISpStreamFormatConverter, ScaleConvertedToBaseOffset)
        HRESULT ( STDMETHODCALLTYPE *ScaleConvertedToBaseOffset )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullOffsetConvertedStream,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pullOffsetBaseStream);
        
        DECLSPEC_XFGVIRT(ISpStreamFormatConverter, ScaleBaseToConvertedOffset)
        HRESULT ( STDMETHODCALLTYPE *ScaleBaseToConvertedOffset )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullOffsetBaseStream,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pullOffsetConvertedStream);
        
        END_INTERFACE
    } ISpStreamFormatConverterVtbl;

    interface ISpStreamFormatConverter
    {
        CONST_VTBL struct ISpStreamFormatConverterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpStreamFormatConverter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpStreamFormatConverter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpStreamFormatConverter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpStreamFormatConverter_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define ISpStreamFormatConverter_Write(This,pv,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pv,cb,pcbWritten) ) 


#define ISpStreamFormatConverter_Seek(This,dlibMove,dwOrigin,plibNewPosition)	\
    ( (This)->lpVtbl -> Seek(This,dlibMove,dwOrigin,plibNewPosition) ) 

#define ISpStreamFormatConverter_SetSize(This,libNewSize)	\
    ( (This)->lpVtbl -> SetSize(This,libNewSize) ) 

#define ISpStreamFormatConverter_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    ( (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten) ) 

#define ISpStreamFormatConverter_Commit(This,grfCommitFlags)	\
    ( (This)->lpVtbl -> Commit(This,grfCommitFlags) ) 

#define ISpStreamFormatConverter_Revert(This)	\
    ( (This)->lpVtbl -> Revert(This) ) 

#define ISpStreamFormatConverter_LockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType) ) 

#define ISpStreamFormatConverter_UnlockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType) ) 

#define ISpStreamFormatConverter_Stat(This,pstatstg,grfStatFlag)	\
    ( (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag) ) 

#define ISpStreamFormatConverter_Clone(This,ppstm)	\
    ( (This)->lpVtbl -> Clone(This,ppstm) ) 


#define ISpStreamFormatConverter_GetFormat(This,pguidFormatId,ppCoMemWaveFormatEx)	\
    ( (This)->lpVtbl -> GetFormat(This,pguidFormatId,ppCoMemWaveFormatEx) ) 


#define ISpStreamFormatConverter_SetBaseStream(This,pStream,fSetFormatToBaseStreamFormat,fWriteToBaseStream)	\
    ( (This)->lpVtbl -> SetBaseStream(This,pStream,fSetFormatToBaseStreamFormat,fWriteToBaseStream) ) 

#define ISpStreamFormatConverter_GetBaseStream(This,ppStream)	\
    ( (This)->lpVtbl -> GetBaseStream(This,ppStream) ) 

#define ISpStreamFormatConverter_SetFormat(This,rguidFormatIdOfConvertedStream,pWaveFormatExOfConvertedStream)	\
    ( (This)->lpVtbl -> SetFormat(This,rguidFormatIdOfConvertedStream,pWaveFormatExOfConvertedStream) ) 

#define ISpStreamFormatConverter_ResetSeekPosition(This)	\
    ( (This)->lpVtbl -> ResetSeekPosition(This) ) 

#define ISpStreamFormatConverter_ScaleConvertedToBaseOffset(This,ullOffsetConvertedStream,pullOffsetBaseStream)	\
    ( (This)->lpVtbl -> ScaleConvertedToBaseOffset(This,ullOffsetConvertedStream,pullOffsetBaseStream) ) 

#define ISpStreamFormatConverter_ScaleBaseToConvertedOffset(This,ullOffsetBaseStream,pullOffsetConvertedStream)	\
    ( (This)->lpVtbl -> ScaleBaseToConvertedOffset(This,ullOffsetBaseStream,pullOffsetConvertedStream) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpStreamFormatConverter_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0017 */
/* [local] */ 

typedef /* [hidden] */ 
enum _SPAUDIOSTATE
    {
        SPAS_CLOSED	= 0,
        SPAS_STOP	= ( SPAS_CLOSED + 1 ) ,
        SPAS_PAUSE	= ( SPAS_STOP + 1 ) ,
        SPAS_RUN	= ( SPAS_PAUSE + 1 ) 
    } 	SPAUDIOSTATE;

typedef /* [hidden][restricted] */ struct SPAUDIOSTATUS
    {
    long cbFreeBuffSpace;
    ULONG cbNonBlockingIO;
    SPAUDIOSTATE State;
    ULONGLONG CurSeekPos;
    ULONGLONG CurDevicePos;
    DWORD dwAudioLevel;
    DWORD dwReserved2;
    } 	SPAUDIOSTATUS;

typedef /* [hidden][restricted] */ struct SPAUDIOBUFFERINFO
    {
    ULONG ulMsMinNotification;
    ULONG ulMsBufferSize;
    ULONG ulMsEventBias;
    } 	SPAUDIOBUFFERINFO;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0017_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0017_v0_0_s_ifspec;

#ifndef __ISpAudio_INTERFACE_DEFINED__
#define __ISpAudio_INTERFACE_DEFINED__

/* interface ISpAudio */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpAudio;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C05C768F-FAE8-4EC2-8E07-338321C12452")
    ISpAudio : public ISpStreamFormat
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetState( 
            /* [annotation][in] */ 
            _In_  SPAUDIOSTATE NewState,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFormat( 
            /* [annotation][in] */ 
            _In_  REFGUID rguidFmtId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [annotation][out] */ 
            _Out_  SPAUDIOSTATUS *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferInfo( 
            /* [annotation][in] */ 
            _In_  const SPAUDIOBUFFERINFO *pBuffInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBufferInfo( 
            /* [annotation][out] */ 
            _Out_  SPAUDIOBUFFERINFO *pBuffInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultFormat( 
            /* [annotation][out] */ 
            _Out_  GUID *pFormatId,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppCoMemWaveFormatEx) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE EventHandle( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVolumeLevel( 
            /* [annotation][out] */ 
            _Out_  ULONG *pLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVolumeLevel( 
            /* [annotation][in] */ 
            _In_  ULONG Level) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBufferNotifySize( 
            /* [annotation][out] */ 
            _Out_  ULONG *pcbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferNotifySize( 
            /* [annotation][in] */ 
            _In_  ULONG cbSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpAudioVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpAudio * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpAudio * This);
        
        DECLSPEC_XFGVIRT(ISequentialStream, Read)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpAudio * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        DECLSPEC_XFGVIRT(ISequentialStream, Write)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpAudio * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        DECLSPEC_XFGVIRT(IStream, Seek)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  LARGE_INTEGER dlibMove,
            /* [annotation][in] */ 
            _In_  DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        DECLSPEC_XFGVIRT(IStream, SetSize)
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libNewSize);
        
        DECLSPEC_XFGVIRT(IStream, CopyTo)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            ISpAudio * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        DECLSPEC_XFGVIRT(IStream, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  DWORD grfCommitFlags);
        
        DECLSPEC_XFGVIRT(IStream, Revert)
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            ISpAudio * This);
        
        DECLSPEC_XFGVIRT(IStream, LockRegion)
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        DECLSPEC_XFGVIRT(IStream, UnlockRegion)
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        DECLSPEC_XFGVIRT(IStream, Stat)
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            ISpAudio * This,
            /* [annotation][out] */ 
            _Out_  STATSTG *pstatstg,
            /* [annotation][in] */ 
            _In_  DWORD grfStatFlag);
        
        DECLSPEC_XFGVIRT(IStream, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISpAudio * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppstm);
        
        DECLSPEC_XFGVIRT(ISpStreamFormat, GetFormat)
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  GUID *pguidFormatId,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpAudio, SetState)
        HRESULT ( STDMETHODCALLTYPE *SetState )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  SPAUDIOSTATE NewState,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullReserved);
        
        DECLSPEC_XFGVIRT(ISpAudio, SetFormat)
        HRESULT ( STDMETHODCALLTYPE *SetFormat )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguidFmtId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpAudio, GetStatus)
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ISpAudio * This,
            /* [annotation][out] */ 
            _Out_  SPAUDIOSTATUS *pStatus);
        
        DECLSPEC_XFGVIRT(ISpAudio, SetBufferInfo)
        HRESULT ( STDMETHODCALLTYPE *SetBufferInfo )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  const SPAUDIOBUFFERINFO *pBuffInfo);
        
        DECLSPEC_XFGVIRT(ISpAudio, GetBufferInfo)
        HRESULT ( STDMETHODCALLTYPE *GetBufferInfo )( 
            ISpAudio * This,
            /* [annotation][out] */ 
            _Out_  SPAUDIOBUFFERINFO *pBuffInfo);
        
        DECLSPEC_XFGVIRT(ISpAudio, GetDefaultFormat)
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFormat )( 
            ISpAudio * This,
            /* [annotation][out] */ 
            _Out_  GUID *pFormatId,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpAudio, EventHandle)
        HANDLE ( STDMETHODCALLTYPE *EventHandle )( 
            ISpAudio * This);
        
        DECLSPEC_XFGVIRT(ISpAudio, GetVolumeLevel)
        HRESULT ( STDMETHODCALLTYPE *GetVolumeLevel )( 
            ISpAudio * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pLevel);
        
        DECLSPEC_XFGVIRT(ISpAudio, SetVolumeLevel)
        HRESULT ( STDMETHODCALLTYPE *SetVolumeLevel )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  ULONG Level);
        
        DECLSPEC_XFGVIRT(ISpAudio, GetBufferNotifySize)
        HRESULT ( STDMETHODCALLTYPE *GetBufferNotifySize )( 
            ISpAudio * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbSize);
        
        DECLSPEC_XFGVIRT(ISpAudio, SetBufferNotifySize)
        HRESULT ( STDMETHODCALLTYPE *SetBufferNotifySize )( 
            ISpAudio * This,
            /* [annotation][in] */ 
            _In_  ULONG cbSize);
        
        END_INTERFACE
    } ISpAudioVtbl;

    interface ISpAudio
    {
        CONST_VTBL struct ISpAudioVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpAudio_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpAudio_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpAudio_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpAudio_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define ISpAudio_Write(This,pv,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pv,cb,pcbWritten) ) 


#define ISpAudio_Seek(This,dlibMove,dwOrigin,plibNewPosition)	\
    ( (This)->lpVtbl -> Seek(This,dlibMove,dwOrigin,plibNewPosition) ) 

#define ISpAudio_SetSize(This,libNewSize)	\
    ( (This)->lpVtbl -> SetSize(This,libNewSize) ) 

#define ISpAudio_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    ( (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten) ) 

#define ISpAudio_Commit(This,grfCommitFlags)	\
    ( (This)->lpVtbl -> Commit(This,grfCommitFlags) ) 

#define ISpAudio_Revert(This)	\
    ( (This)->lpVtbl -> Revert(This) ) 

#define ISpAudio_LockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType) ) 

#define ISpAudio_UnlockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType) ) 

#define ISpAudio_Stat(This,pstatstg,grfStatFlag)	\
    ( (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag) ) 

#define ISpAudio_Clone(This,ppstm)	\
    ( (This)->lpVtbl -> Clone(This,ppstm) ) 


#define ISpAudio_GetFormat(This,pguidFormatId,ppCoMemWaveFormatEx)	\
    ( (This)->lpVtbl -> GetFormat(This,pguidFormatId,ppCoMemWaveFormatEx) ) 


#define ISpAudio_SetState(This,NewState,ullReserved)	\
    ( (This)->lpVtbl -> SetState(This,NewState,ullReserved) ) 

#define ISpAudio_SetFormat(This,rguidFmtId,pWaveFormatEx)	\
    ( (This)->lpVtbl -> SetFormat(This,rguidFmtId,pWaveFormatEx) ) 

#define ISpAudio_GetStatus(This,pStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pStatus) ) 

#define ISpAudio_SetBufferInfo(This,pBuffInfo)	\
    ( (This)->lpVtbl -> SetBufferInfo(This,pBuffInfo) ) 

#define ISpAudio_GetBufferInfo(This,pBuffInfo)	\
    ( (This)->lpVtbl -> GetBufferInfo(This,pBuffInfo) ) 

#define ISpAudio_GetDefaultFormat(This,pFormatId,ppCoMemWaveFormatEx)	\
    ( (This)->lpVtbl -> GetDefaultFormat(This,pFormatId,ppCoMemWaveFormatEx) ) 

#define ISpAudio_EventHandle(This)	\
    ( (This)->lpVtbl -> EventHandle(This) ) 

#define ISpAudio_GetVolumeLevel(This,pLevel)	\
    ( (This)->lpVtbl -> GetVolumeLevel(This,pLevel) ) 

#define ISpAudio_SetVolumeLevel(This,Level)	\
    ( (This)->lpVtbl -> SetVolumeLevel(This,Level) ) 

#define ISpAudio_GetBufferNotifySize(This,pcbSize)	\
    ( (This)->lpVtbl -> GetBufferNotifySize(This,pcbSize) ) 

#define ISpAudio_SetBufferNotifySize(This,cbSize)	\
    ( (This)->lpVtbl -> SetBufferNotifySize(This,cbSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpAudio_INTERFACE_DEFINED__ */


#ifndef __ISpMMSysAudio_INTERFACE_DEFINED__
#define __ISpMMSysAudio_INTERFACE_DEFINED__

/* interface ISpMMSysAudio */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpMMSysAudio;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("15806F6E-1D70-4B48-98E6-3B1A007509AB")
    ISpMMSysAudio : public ISpAudio
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDeviceId( 
            /* [annotation][out] */ 
            _Out_  UINT *puDeviceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDeviceId( 
            /* [annotation][in] */ 
            _In_  UINT uDeviceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMMHandle( 
            /* [annotation][out] */ 
            _Out_  void **pHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLineId( 
            /* [annotation][out] */ 
            _Out_  UINT *puLineId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLineId( 
            /* [annotation][in] */ 
            _In_  UINT uLineId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpMMSysAudioVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpMMSysAudio * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpMMSysAudio * This);
        
        DECLSPEC_XFGVIRT(ISequentialStream, Read)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpMMSysAudio * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        DECLSPEC_XFGVIRT(ISequentialStream, Write)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpMMSysAudio * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        DECLSPEC_XFGVIRT(IStream, Seek)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  LARGE_INTEGER dlibMove,
            /* [annotation][in] */ 
            _In_  DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        DECLSPEC_XFGVIRT(IStream, SetSize)
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libNewSize);
        
        DECLSPEC_XFGVIRT(IStream, CopyTo)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            ISpMMSysAudio * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        DECLSPEC_XFGVIRT(IStream, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  DWORD grfCommitFlags);
        
        DECLSPEC_XFGVIRT(IStream, Revert)
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            ISpMMSysAudio * This);
        
        DECLSPEC_XFGVIRT(IStream, LockRegion)
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        DECLSPEC_XFGVIRT(IStream, UnlockRegion)
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER libOffset,
            /* [annotation][in] */ 
            _In_  ULARGE_INTEGER cb,
            /* [annotation][in] */ 
            _In_  DWORD dwLockType);
        
        DECLSPEC_XFGVIRT(IStream, Stat)
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            ISpMMSysAudio * This,
            /* [annotation][out] */ 
            _Out_  STATSTG *pstatstg,
            /* [annotation][in] */ 
            _In_  DWORD grfStatFlag);
        
        DECLSPEC_XFGVIRT(IStream, Clone)
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISpMMSysAudio * This,
            /* [annotation][out] */ 
            _Out_  IStream **ppstm);
        
        DECLSPEC_XFGVIRT(ISpStreamFormat, GetFormat)
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  GUID *pguidFormatId,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpAudio, SetState)
        HRESULT ( STDMETHODCALLTYPE *SetState )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  SPAUDIOSTATE NewState,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullReserved);
        
        DECLSPEC_XFGVIRT(ISpAudio, SetFormat)
        HRESULT ( STDMETHODCALLTYPE *SetFormat )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguidFmtId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpAudio, GetStatus)
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ISpMMSysAudio * This,
            /* [annotation][out] */ 
            _Out_  SPAUDIOSTATUS *pStatus);
        
        DECLSPEC_XFGVIRT(ISpAudio, SetBufferInfo)
        HRESULT ( STDMETHODCALLTYPE *SetBufferInfo )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  const SPAUDIOBUFFERINFO *pBuffInfo);
        
        DECLSPEC_XFGVIRT(ISpAudio, GetBufferInfo)
        HRESULT ( STDMETHODCALLTYPE *GetBufferInfo )( 
            ISpMMSysAudio * This,
            /* [annotation][out] */ 
            _Out_  SPAUDIOBUFFERINFO *pBuffInfo);
        
        DECLSPEC_XFGVIRT(ISpAudio, GetDefaultFormat)
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFormat )( 
            ISpMMSysAudio * This,
            /* [annotation][out] */ 
            _Out_  GUID *pFormatId,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpAudio, EventHandle)
        HANDLE ( STDMETHODCALLTYPE *EventHandle )( 
            ISpMMSysAudio * This);
        
        DECLSPEC_XFGVIRT(ISpAudio, GetVolumeLevel)
        HRESULT ( STDMETHODCALLTYPE *GetVolumeLevel )( 
            ISpMMSysAudio * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pLevel);
        
        DECLSPEC_XFGVIRT(ISpAudio, SetVolumeLevel)
        HRESULT ( STDMETHODCALLTYPE *SetVolumeLevel )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  ULONG Level);
        
        DECLSPEC_XFGVIRT(ISpAudio, GetBufferNotifySize)
        HRESULT ( STDMETHODCALLTYPE *GetBufferNotifySize )( 
            ISpMMSysAudio * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pcbSize);
        
        DECLSPEC_XFGVIRT(ISpAudio, SetBufferNotifySize)
        HRESULT ( STDMETHODCALLTYPE *SetBufferNotifySize )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  ULONG cbSize);
        
        DECLSPEC_XFGVIRT(ISpMMSysAudio, GetDeviceId)
        HRESULT ( STDMETHODCALLTYPE *GetDeviceId )( 
            ISpMMSysAudio * This,
            /* [annotation][out] */ 
            _Out_  UINT *puDeviceId);
        
        DECLSPEC_XFGVIRT(ISpMMSysAudio, SetDeviceId)
        HRESULT ( STDMETHODCALLTYPE *SetDeviceId )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  UINT uDeviceId);
        
        DECLSPEC_XFGVIRT(ISpMMSysAudio, GetMMHandle)
        HRESULT ( STDMETHODCALLTYPE *GetMMHandle )( 
            ISpMMSysAudio * This,
            /* [annotation][out] */ 
            _Out_  void **pHandle);
        
        DECLSPEC_XFGVIRT(ISpMMSysAudio, GetLineId)
        HRESULT ( STDMETHODCALLTYPE *GetLineId )( 
            ISpMMSysAudio * This,
            /* [annotation][out] */ 
            _Out_  UINT *puLineId);
        
        DECLSPEC_XFGVIRT(ISpMMSysAudio, SetLineId)
        HRESULT ( STDMETHODCALLTYPE *SetLineId )( 
            ISpMMSysAudio * This,
            /* [annotation][in] */ 
            _In_  UINT uLineId);
        
        END_INTERFACE
    } ISpMMSysAudioVtbl;

    interface ISpMMSysAudio
    {
        CONST_VTBL struct ISpMMSysAudioVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpMMSysAudio_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpMMSysAudio_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpMMSysAudio_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpMMSysAudio_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define ISpMMSysAudio_Write(This,pv,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pv,cb,pcbWritten) ) 


#define ISpMMSysAudio_Seek(This,dlibMove,dwOrigin,plibNewPosition)	\
    ( (This)->lpVtbl -> Seek(This,dlibMove,dwOrigin,plibNewPosition) ) 

#define ISpMMSysAudio_SetSize(This,libNewSize)	\
    ( (This)->lpVtbl -> SetSize(This,libNewSize) ) 

#define ISpMMSysAudio_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    ( (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten) ) 

#define ISpMMSysAudio_Commit(This,grfCommitFlags)	\
    ( (This)->lpVtbl -> Commit(This,grfCommitFlags) ) 

#define ISpMMSysAudio_Revert(This)	\
    ( (This)->lpVtbl -> Revert(This) ) 

#define ISpMMSysAudio_LockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType) ) 

#define ISpMMSysAudio_UnlockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType) ) 

#define ISpMMSysAudio_Stat(This,pstatstg,grfStatFlag)	\
    ( (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag) ) 

#define ISpMMSysAudio_Clone(This,ppstm)	\
    ( (This)->lpVtbl -> Clone(This,ppstm) ) 


#define ISpMMSysAudio_GetFormat(This,pguidFormatId,ppCoMemWaveFormatEx)	\
    ( (This)->lpVtbl -> GetFormat(This,pguidFormatId,ppCoMemWaveFormatEx) ) 


#define ISpMMSysAudio_SetState(This,NewState,ullReserved)	\
    ( (This)->lpVtbl -> SetState(This,NewState,ullReserved) ) 

#define ISpMMSysAudio_SetFormat(This,rguidFmtId,pWaveFormatEx)	\
    ( (This)->lpVtbl -> SetFormat(This,rguidFmtId,pWaveFormatEx) ) 

#define ISpMMSysAudio_GetStatus(This,pStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pStatus) ) 

#define ISpMMSysAudio_SetBufferInfo(This,pBuffInfo)	\
    ( (This)->lpVtbl -> SetBufferInfo(This,pBuffInfo) ) 

#define ISpMMSysAudio_GetBufferInfo(This,pBuffInfo)	\
    ( (This)->lpVtbl -> GetBufferInfo(This,pBuffInfo) ) 

#define ISpMMSysAudio_GetDefaultFormat(This,pFormatId,ppCoMemWaveFormatEx)	\
    ( (This)->lpVtbl -> GetDefaultFormat(This,pFormatId,ppCoMemWaveFormatEx) ) 

#define ISpMMSysAudio_EventHandle(This)	\
    ( (This)->lpVtbl -> EventHandle(This) ) 

#define ISpMMSysAudio_GetVolumeLevel(This,pLevel)	\
    ( (This)->lpVtbl -> GetVolumeLevel(This,pLevel) ) 

#define ISpMMSysAudio_SetVolumeLevel(This,Level)	\
    ( (This)->lpVtbl -> SetVolumeLevel(This,Level) ) 

#define ISpMMSysAudio_GetBufferNotifySize(This,pcbSize)	\
    ( (This)->lpVtbl -> GetBufferNotifySize(This,pcbSize) ) 

#define ISpMMSysAudio_SetBufferNotifySize(This,cbSize)	\
    ( (This)->lpVtbl -> SetBufferNotifySize(This,cbSize) ) 


#define ISpMMSysAudio_GetDeviceId(This,puDeviceId)	\
    ( (This)->lpVtbl -> GetDeviceId(This,puDeviceId) ) 

#define ISpMMSysAudio_SetDeviceId(This,uDeviceId)	\
    ( (This)->lpVtbl -> SetDeviceId(This,uDeviceId) ) 

#define ISpMMSysAudio_GetMMHandle(This,pHandle)	\
    ( (This)->lpVtbl -> GetMMHandle(This,pHandle) ) 

#define ISpMMSysAudio_GetLineId(This,puLineId)	\
    ( (This)->lpVtbl -> GetLineId(This,puLineId) ) 

#define ISpMMSysAudio_SetLineId(This,uLineId)	\
    ( (This)->lpVtbl -> SetLineId(This,uLineId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpMMSysAudio_INTERFACE_DEFINED__ */


#ifndef __ISpTranscript_INTERFACE_DEFINED__
#define __ISpTranscript_INTERFACE_DEFINED__

/* interface ISpTranscript */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpTranscript;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("10F63BCE-201A-11D3-AC70-00C04F8EE6C0")
    ISpTranscript : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTranscript( 
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszTranscript) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AppendTranscript( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszTranscript) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpTranscriptVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpTranscript * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpTranscript * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpTranscript * This);
        
        DECLSPEC_XFGVIRT(ISpTranscript, GetTranscript)
        HRESULT ( STDMETHODCALLTYPE *GetTranscript )( 
            __RPC__in ISpTranscript * This,
            /* [annotation][string][out] */ 
            _Out_  LPWSTR *ppszTranscript);
        
        DECLSPEC_XFGVIRT(ISpTranscript, AppendTranscript)
        HRESULT ( STDMETHODCALLTYPE *AppendTranscript )( 
            __RPC__in ISpTranscript * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszTranscript);
        
        END_INTERFACE
    } ISpTranscriptVtbl;

    interface ISpTranscript
    {
        CONST_VTBL struct ISpTranscriptVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpTranscript_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpTranscript_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpTranscript_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpTranscript_GetTranscript(This,ppszTranscript)	\
    ( (This)->lpVtbl -> GetTranscript(This,ppszTranscript) ) 

#define ISpTranscript_AppendTranscript(This,pszTranscript)	\
    ( (This)->lpVtbl -> AppendTranscript(This,pszTranscript) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpTranscript_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0020 */
/* [local] */ 

typedef /* [hidden] */ 
enum SPDISPLYATTRIBUTES
    {
        SPAF_ONE_TRAILING_SPACE	= 0x2,
        SPAF_TWO_TRAILING_SPACES	= 0x4,
        SPAF_CONSUME_LEADING_SPACES	= 0x8,
        SPAF_BUFFER_POSITION	= 0x10,
        SPAF_ALL	= 0x1f,
        SPAF_USER_SPECIFIED	= 0x80
    } 	SPDISPLAYATTRIBUTES;

typedef WCHAR SPPHONEID;

typedef LPWSTR PSPPHONEID;

typedef LPCWSTR PCSPPHONEID;

typedef /* [hidden][restricted] */ struct SPPHRASEELEMENT
    {
    ULONG ulAudioTimeOffset;
    ULONG ulAudioSizeTime;
    ULONG ulAudioStreamOffset;
    ULONG ulAudioSizeBytes;
    ULONG ulRetainedStreamOffset;
    ULONG ulRetainedSizeBytes;
    LPCWSTR pszDisplayText;
    LPCWSTR pszLexicalForm;
    const SPPHONEID *pszPronunciation;
    BYTE bDisplayAttributes;
    signed char RequiredConfidence;
    signed char ActualConfidence;
    BYTE Reserved;
    float SREngineConfidence;
    } 	SPPHRASEELEMENT;

typedef /* [hidden][restricted] */ struct SPPHRASERULE SPPHRASERULE;

struct SPPHRASERULE
    {
    LPCWSTR pszName;
    ULONG ulId;
    ULONG ulFirstElement;
    ULONG ulCountOfElements;
    const SPPHRASERULE *pNextSibling;
    const SPPHRASERULE *pFirstChild;
    float SREngineConfidence;
    signed char Confidence;
    } ;
typedef /* [hidden][restricted] */ struct SPPHRASEPROPERTY SPPHRASEPROPERTY;

typedef /* [hidden] */ 
enum SPPHRASEPROPERTYUNIONTYPE
    {
        SPPPUT_UNUSED	= 0,
        SPPPUT_ARRAY_INDEX	= ( SPPPUT_UNUSED + 1 ) 
    } 	SPPHRASEPROPERTYUNIONTYPE;

struct SPPHRASEPROPERTY
    {
    LPCWSTR pszName;
    union 
        {
        ULONG ulId;
        struct 
            {
            byte bType;
            byte bReserved;
            unsigned short usArrayIndex;
            } 	;
        } 	;
    LPCWSTR pszValue;
    VARIANT vValue;
    ULONG ulFirstElement;
    ULONG ulCountOfElements;
    const SPPHRASEPROPERTY *pNextSibling;
    const SPPHRASEPROPERTY *pFirstChild;
    float SREngineConfidence;
    signed char Confidence;
    } ;
typedef /* [hidden][restricted] */ struct SPPHRASEREPLACEMENT
    {
    BYTE bDisplayAttributes;
    LPCWSTR pszReplacementText;
    ULONG ulFirstElement;
    ULONG ulCountOfElements;
    } 	SPPHRASEREPLACEMENT;

typedef /* [hidden][restricted] */ struct SPSEMANTICERRORINFO
    {
    ULONG ulLineNumber;
    LPWSTR pszScriptLine;
    LPWSTR pszSource;
    LPWSTR pszDescription;
    HRESULT hrResultCode;
    } 	SPSEMANTICERRORINFO;

typedef 
enum SPSEMANTICFORMAT
    {
        SPSMF_SAPI_PROPERTIES	= 0,
        SPSMF_SRGS_SEMANTICINTERPRETATION_MS	= 1,
        SPSMF_SRGS_SAPIPROPERTIES	= 2,
        SPSMF_UPS	= 4,
        SPSMF_SRGS_SEMANTICINTERPRETATION_W3C	= 8
    } 	SPSEMANTICFORMAT;

typedef /* [hidden][restricted] */ struct SPPHRASE_50
    {
    ULONG cbSize;
    WORD LangID;
    WORD wHomophoneGroupId;
    ULONGLONG ullGrammarID;
    ULONGLONG ftStartTime;
    ULONGLONG ullAudioStreamPosition;
    ULONG ulAudioSizeBytes;
    ULONG ulRetainedSizeBytes;
    ULONG ulAudioSizeTime;
    SPPHRASERULE Rule;
    const SPPHRASEPROPERTY *pProperties;
    const SPPHRASEELEMENT *pElements;
    ULONG cReplacements;
    const SPPHRASEREPLACEMENT *pReplacements;
    GUID SREngineID;
    ULONG ulSREnginePrivateDataSize;
    const BYTE *pSREnginePrivateData;
    } 	SPPHRASE_50;

#define SP_SPPHRASESIZE_500 sizeof(SPPHRASE_50)
#ifdef __cplusplus
typedef struct SPPHRASE_53 : public SPPHRASE_50
{
LPWSTR pSML;
SPSEMANTICERRORINFO* pSemanticErrorInfo;
} SPPHRASE_53;
#else
typedef /* [hidden][restricted] */ struct SPPHRASE_53
    {
    ULONG cbSize;
    WORD LangID;
    WORD wHomophoneGroupId;
    ULONGLONG ullGrammarID;
    ULONGLONG ftStartTime;
    ULONGLONG ullAudioStreamPosition;
    ULONG ulAudioSizeBytes;
    ULONG ulRetainedSizeBytes;
    ULONG ulAudioSizeTime;
    SPPHRASERULE Rule;
    const SPPHRASEPROPERTY *pProperties;
    const SPPHRASEELEMENT *pElements;
    ULONG cReplacements;
    const SPPHRASEREPLACEMENT *pReplacements;
    GUID SREngineID;
    ULONG ulSREnginePrivateDataSize;
    const BYTE *pSREnginePrivateData;
    LPWSTR pSML;
    SPSEMANTICERRORINFO *pSemanticErrorInfo;
    } 	SPPHRASE_53;

#endif // __cplusplus
#define SP_SPPHRASESIZE_530 sizeof(SPPHRASE_53)
#ifdef __cplusplus
typedef struct SPPHRASE : public SPPHRASE_53
{
SPSEMANTICFORMAT SemanticTagFormat;
} SPPHRASE;
#else
typedef /* [hidden][restricted] */ struct SPPHRASE
    {
    ULONG cbSize;
    WORD LangID;
    WORD wHomophoneGroupId;
    ULONGLONG ullGrammarID;
    ULONGLONG ftStartTime;
    ULONGLONG ullAudioStreamPosition;
    ULONG ulAudioSizeBytes;
    ULONG ulRetainedSizeBytes;
    ULONG ulAudioSizeTime;
    SPPHRASERULE Rule;
    const SPPHRASEPROPERTY *pProperties;
    const SPPHRASEELEMENT *pElements;
    ULONG cReplacements;
    const SPPHRASEREPLACEMENT *pReplacements;
    GUID SREngineID;
    ULONG ulSREnginePrivateDataSize;
    const BYTE *pSREnginePrivateData;
    LPWSTR pSML;
    SPSEMANTICERRORINFO *pSemanticErrorInfo;
    SPSEMANTICFORMAT SemanticTagFormat;
    } 	SPPHRASE;

#endif // __cplusplus
typedef /* [hidden][restricted] */ struct SPSERIALIZEDPHRASE
    {
    ULONG ulSerializedSize;
    } 	SPSERIALIZEDPHRASE;

typedef /* [hidden][restricted] */ struct SPRULE
    {
    LPCWSTR pszRuleName;
    ULONG ulRuleId;
    DWORD dwAttributes;
    } 	SPRULE;

typedef /* [hidden] */ 
enum SPVALUETYPE
    {
        SPDF_PROPERTY	= 0x1,
        SPDF_REPLACEMENT	= 0x2,
        SPDF_RULE	= 0x4,
        SPDF_DISPLAYTEXT	= 0x8,
        SPDF_LEXICALFORM	= 0x10,
        SPDF_PRONUNCIATION	= 0x20,
        SPDF_AUDIO	= 0x40,
        SPDF_ALTERNATES	= 0x80,
        SPDF_ALL	= 0xff
    } 	SPVALUETYPE;

typedef /* [hidden] */ struct SPBINARYGRAMMAR
    {
    ULONG ulTotalSerializedSize;
    } 	SPBINARYGRAMMAR;

typedef /* [hidden] */ 
enum SPPHRASERNG
    {
        SPPR_ALL_ELEMENTS	= -1
    } 	SPPHRASERNG;

#define SP_GETWHOLEPHRASE SPPR_ALL_ELEMENTS
#define SPRR_ALL_ELEMENTS SPPR_ALL_ELEMENTS
#if 0
typedef void *SPSTATEHANDLE;

#else
DECLARE_HANDLE(SPSTATEHANDLE);
#endif
typedef /* [hidden] */ 
enum SPRECOEVENTFLAGS
    {
        SPREF_AutoPause	= ( 1 << 0 ) ,
        SPREF_Emulated	= ( 1 << 1 ) ,
        SPREF_SMLTimeout	= ( 1 << 2 ) ,
        SPREF_ExtendableParse	= ( 1 << 3 ) ,
        SPREF_ReSent	= ( 1 << 4 ) ,
        SPREF_Hypothesis	= ( 1 << 5 ) ,
        SPREF_FalseRecognition	= ( 1 << 6 ) 
    } 	SPRECOEVENTFLAGS;

typedef /* [hidden] */ 
enum SPPARTOFSPEECH
    {
        SPPS_NotOverriden	= -1,
        SPPS_Unknown	= 0,
        SPPS_Noun	= 0x1000,
        SPPS_Verb	= 0x2000,
        SPPS_Modifier	= 0x3000,
        SPPS_Function	= 0x4000,
        SPPS_Interjection	= 0x5000,
        SPPS_Noncontent	= 0x6000,
        SPPS_LMA	= 0x7000,
        SPPS_SuppressWord	= 0xf000
    } 	SPPARTOFSPEECH;

typedef /* [hidden] */ 
enum SPLEXICONTYPE
    {
        eLEXTYPE_USER	= ( 1L << 0 ) ,
        eLEXTYPE_APP	= ( 1L << 1 ) ,
        eLEXTYPE_VENDORLEXICON	= ( 1L << 2 ) ,
        eLEXTYPE_LETTERTOSOUND	= ( 1L << 3 ) ,
        eLEXTYPE_MORPHOLOGY	= ( 1L << 4 ) ,
        eLEXTYPE_RESERVED4	= ( 1L << 5 ) ,
        eLEXTYPE_USER_SHORTCUT	= ( 1L << 6 ) ,
        eLEXTYPE_RESERVED6	= ( 1L << 7 ) ,
        eLEXTYPE_RESERVED7	= ( 1L << 8 ) ,
        eLEXTYPE_RESERVED8	= ( 1L << 9 ) ,
        eLEXTYPE_RESERVED9	= ( 1L << 10 ) ,
        eLEXTYPE_RESERVED10	= ( 1L << 11 ) ,
        eLEXTYPE_PRIVATE1	= ( 1L << 12 ) ,
        eLEXTYPE_PRIVATE2	= ( 1L << 13 ) ,
        eLEXTYPE_PRIVATE3	= ( 1L << 14 ) ,
        eLEXTYPE_PRIVATE4	= ( 1L << 15 ) ,
        eLEXTYPE_PRIVATE5	= ( 1L << 16 ) ,
        eLEXTYPE_PRIVATE6	= ( 1L << 17 ) ,
        eLEXTYPE_PRIVATE7	= ( 1L << 18 ) ,
        eLEXTYPE_PRIVATE8	= ( 1L << 19 ) ,
        eLEXTYPE_PRIVATE9	= ( 1L << 20 ) ,
        eLEXTYPE_PRIVATE10	= ( 1L << 21 ) ,
        eLEXTYPE_PRIVATE11	= ( 1L << 22 ) ,
        eLEXTYPE_PRIVATE12	= ( 1L << 23 ) ,
        eLEXTYPE_PRIVATE13	= ( 1L << 24 ) ,
        eLEXTYPE_PRIVATE14	= ( 1L << 25 ) ,
        eLEXTYPE_PRIVATE15	= ( 1L << 26 ) ,
        eLEXTYPE_PRIVATE16	= ( 1L << 27 ) ,
        eLEXTYPE_PRIVATE17	= ( 1L << 28 ) ,
        eLEXTYPE_PRIVATE18	= ( 1L << 29 ) ,
        eLEXTYPE_PRIVATE19	= ( 1L << 30 ) ,
        eLEXTYPE_PRIVATE20	= ( 1L << 31 ) 
    } 	SPLEXICONTYPE;

typedef /* [hidden] */ 
enum SPWORDTYPE
    {
        eWORDTYPE_ADDED	= ( 1L << 0 ) ,
        eWORDTYPE_DELETED	= ( 1L << 1 ) 
    } 	SPWORDTYPE;

typedef /* [hidden] */ 
enum SPPRONUNCIATIONFLAGS
    {
        ePRONFLAG_USED	= ( 1 << 0 ) 
    } 	SPPRONUNCIATIONFLAGS;

typedef /* [hidden][restricted] */ struct SPWORDPRONUNCIATION
    {
    struct SPWORDPRONUNCIATION *pNextWordPronunciation;
    SPLEXICONTYPE eLexiconType;
    WORD LangID;
    WORD wPronunciationFlags;
    SPPARTOFSPEECH ePartOfSpeech;
    SPPHONEID szPronunciation[ 1 ];
    } 	SPWORDPRONUNCIATION;

typedef /* [hidden][restricted] */ struct SPWORDPRONUNCIATIONLIST
    {
    ULONG ulSize;
    BYTE *pvBuffer;
    SPWORDPRONUNCIATION *pFirstWordPronunciation;
    } 	SPWORDPRONUNCIATIONLIST;

typedef /* [hidden][restricted] */ struct SPWORD
    {
    struct SPWORD *pNextWord;
    WORD LangID;
    WORD wReserved;
    SPWORDTYPE eWordType;
    LPWSTR pszWord;
    SPWORDPRONUNCIATION *pFirstWordPronunciation;
    } 	SPWORD;

typedef /* [hidden][restricted] */ struct SPWORDLIST
    {
    ULONG ulSize;
    BYTE *pvBuffer;
    SPWORD *pFirstWord;
    } 	SPWORDLIST;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0020_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0020_v0_0_s_ifspec;

#ifndef __ISpLexicon_INTERFACE_DEFINED__
#define __ISpLexicon_INTERFACE_DEFINED__

/* interface ISpLexicon */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpLexicon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA41A7C2-5383-4DB2-916B-6C1719E3DB58")
    ISpLexicon : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPronunciations( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDPRONUNCIATIONLIST *pWordPronunciationList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPronunciation( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemovePronunciation( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGeneration( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwGeneration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGenerationChange( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDLIST *pWordList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWords( 
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [out][in][annotation] */ 
            _Inout_opt_  DWORD *pdwCookie,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDLIST *pWordList) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpLexiconVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpLexicon * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpLexicon * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpLexicon * This);
        
        DECLSPEC_XFGVIRT(ISpLexicon, GetPronunciations)
        HRESULT ( STDMETHODCALLTYPE *GetPronunciations )( 
            ISpLexicon * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDPRONUNCIATIONLIST *pWordPronunciationList);
        
        DECLSPEC_XFGVIRT(ISpLexicon, AddPronunciation)
        HRESULT ( STDMETHODCALLTYPE *AddPronunciation )( 
            ISpLexicon * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation);
        
        DECLSPEC_XFGVIRT(ISpLexicon, RemovePronunciation)
        HRESULT ( STDMETHODCALLTYPE *RemovePronunciation )( 
            ISpLexicon * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation);
        
        DECLSPEC_XFGVIRT(ISpLexicon, GetGeneration)
        HRESULT ( STDMETHODCALLTYPE *GetGeneration )( 
            ISpLexicon * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwGeneration);
        
        DECLSPEC_XFGVIRT(ISpLexicon, GetGenerationChange)
        HRESULT ( STDMETHODCALLTYPE *GetGenerationChange )( 
            ISpLexicon * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDLIST *pWordList);
        
        DECLSPEC_XFGVIRT(ISpLexicon, GetWords)
        HRESULT ( STDMETHODCALLTYPE *GetWords )( 
            ISpLexicon * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [out][in][annotation] */ 
            _Inout_opt_  DWORD *pdwCookie,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDLIST *pWordList);
        
        END_INTERFACE
    } ISpLexiconVtbl;

    interface ISpLexicon
    {
        CONST_VTBL struct ISpLexiconVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpLexicon_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpLexicon_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpLexicon_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpLexicon_GetPronunciations(This,pszWord,LangID,dwFlags,pWordPronunciationList)	\
    ( (This)->lpVtbl -> GetPronunciations(This,pszWord,LangID,dwFlags,pWordPronunciationList) ) 

#define ISpLexicon_AddPronunciation(This,pszWord,LangID,ePartOfSpeech,pszPronunciation)	\
    ( (This)->lpVtbl -> AddPronunciation(This,pszWord,LangID,ePartOfSpeech,pszPronunciation) ) 

#define ISpLexicon_RemovePronunciation(This,pszWord,LangID,ePartOfSpeech,pszPronunciation)	\
    ( (This)->lpVtbl -> RemovePronunciation(This,pszWord,LangID,ePartOfSpeech,pszPronunciation) ) 

#define ISpLexicon_GetGeneration(This,pdwGeneration)	\
    ( (This)->lpVtbl -> GetGeneration(This,pdwGeneration) ) 

#define ISpLexicon_GetGenerationChange(This,dwFlags,pdwGeneration,pWordList)	\
    ( (This)->lpVtbl -> GetGenerationChange(This,dwFlags,pdwGeneration,pWordList) ) 

#define ISpLexicon_GetWords(This,dwFlags,pdwGeneration,pdwCookie,pWordList)	\
    ( (This)->lpVtbl -> GetWords(This,dwFlags,pdwGeneration,pdwCookie,pWordList) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpLexicon_INTERFACE_DEFINED__ */


#ifndef __ISpContainerLexicon_INTERFACE_DEFINED__
#define __ISpContainerLexicon_INTERFACE_DEFINED__

/* interface ISpContainerLexicon */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpContainerLexicon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8565572F-C094-41CC-B56E-10BD9C3FF044")
    ISpContainerLexicon : public ISpLexicon
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddLexicon( 
            /* [annotation][in] */ 
            _In_  ISpLexicon *pAddLexicon,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpContainerLexiconVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpContainerLexicon * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpContainerLexicon * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpContainerLexicon * This);
        
        DECLSPEC_XFGVIRT(ISpLexicon, GetPronunciations)
        HRESULT ( STDMETHODCALLTYPE *GetPronunciations )( 
            __RPC__in ISpContainerLexicon * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDPRONUNCIATIONLIST *pWordPronunciationList);
        
        DECLSPEC_XFGVIRT(ISpLexicon, AddPronunciation)
        HRESULT ( STDMETHODCALLTYPE *AddPronunciation )( 
            __RPC__in ISpContainerLexicon * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation);
        
        DECLSPEC_XFGVIRT(ISpLexicon, RemovePronunciation)
        HRESULT ( STDMETHODCALLTYPE *RemovePronunciation )( 
            __RPC__in ISpContainerLexicon * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation);
        
        DECLSPEC_XFGVIRT(ISpLexicon, GetGeneration)
        HRESULT ( STDMETHODCALLTYPE *GetGeneration )( 
            __RPC__in ISpContainerLexicon * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwGeneration);
        
        DECLSPEC_XFGVIRT(ISpLexicon, GetGenerationChange)
        HRESULT ( STDMETHODCALLTYPE *GetGenerationChange )( 
            __RPC__in ISpContainerLexicon * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDLIST *pWordList);
        
        DECLSPEC_XFGVIRT(ISpLexicon, GetWords)
        HRESULT ( STDMETHODCALLTYPE *GetWords )( 
            __RPC__in ISpContainerLexicon * This,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [out][in][annotation] */ 
            _Inout_opt_  DWORD *pdwCookie,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDLIST *pWordList);
        
        DECLSPEC_XFGVIRT(ISpContainerLexicon, AddLexicon)
        HRESULT ( STDMETHODCALLTYPE *AddLexicon )( 
            __RPC__in ISpContainerLexicon * This,
            /* [annotation][in] */ 
            _In_  ISpLexicon *pAddLexicon,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags);
        
        END_INTERFACE
    } ISpContainerLexiconVtbl;

    interface ISpContainerLexicon
    {
        CONST_VTBL struct ISpContainerLexiconVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpContainerLexicon_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpContainerLexicon_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpContainerLexicon_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpContainerLexicon_GetPronunciations(This,pszWord,LangID,dwFlags,pWordPronunciationList)	\
    ( (This)->lpVtbl -> GetPronunciations(This,pszWord,LangID,dwFlags,pWordPronunciationList) ) 

#define ISpContainerLexicon_AddPronunciation(This,pszWord,LangID,ePartOfSpeech,pszPronunciation)	\
    ( (This)->lpVtbl -> AddPronunciation(This,pszWord,LangID,ePartOfSpeech,pszPronunciation) ) 

#define ISpContainerLexicon_RemovePronunciation(This,pszWord,LangID,ePartOfSpeech,pszPronunciation)	\
    ( (This)->lpVtbl -> RemovePronunciation(This,pszWord,LangID,ePartOfSpeech,pszPronunciation) ) 

#define ISpContainerLexicon_GetGeneration(This,pdwGeneration)	\
    ( (This)->lpVtbl -> GetGeneration(This,pdwGeneration) ) 

#define ISpContainerLexicon_GetGenerationChange(This,dwFlags,pdwGeneration,pWordList)	\
    ( (This)->lpVtbl -> GetGenerationChange(This,dwFlags,pdwGeneration,pWordList) ) 

#define ISpContainerLexicon_GetWords(This,dwFlags,pdwGeneration,pdwCookie,pWordList)	\
    ( (This)->lpVtbl -> GetWords(This,dwFlags,pdwGeneration,pdwCookie,pWordList) ) 


#define ISpContainerLexicon_AddLexicon(This,pAddLexicon,dwFlags)	\
    ( (This)->lpVtbl -> AddLexicon(This,pAddLexicon,dwFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpContainerLexicon_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0022 */
/* [local] */ 

typedef /* [hidden] */ 
enum SPSHORTCUTTYPE
    {
        SPSHT_NotOverriden	= -1,
        SPSHT_Unknown	= 0,
        SPSHT_EMAIL	= 0x1000,
        SPSHT_OTHER	= 0x2000,
        SPPS_RESERVED1	= 0x3000,
        SPPS_RESERVED2	= 0x4000,
        SPPS_RESERVED3	= 0x5000,
        SPPS_RESERVED4	= 0xf000
    } 	SPSHORTCUTTYPE;

typedef /* [hidden][restricted] */ struct SPSHORTCUTPAIR
    {
    struct SPSHORTCUTPAIR *pNextSHORTCUTPAIR;
    WORD LangID;
    SPSHORTCUTTYPE shType;
    LPWSTR pszDisplay;
    LPWSTR pszSpoken;
    } 	SPSHORTCUTPAIR;

typedef /* [hidden][restricted] */ struct SPSHORTCUTPAIRLIST
    {
    ULONG ulSize;
    BYTE *pvBuffer;
    SPSHORTCUTPAIR *pFirstShortcutPair;
    } 	SPSHORTCUTPAIRLIST;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0022_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0022_v0_0_s_ifspec;

#ifndef __ISpShortcut_INTERFACE_DEFINED__
#define __ISpShortcut_INTERFACE_DEFINED__

/* interface ISpShortcut */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpShortcut;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3DF681E2-EA56-11D9-8BDE-F66BAD1E3F3A")
    ISpShortcut : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddShortcut( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDisplay,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSpoken,
            /* [annotation][in] */ 
            _In_  SPSHORTCUTTYPE shType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveShortcut( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDisplay,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSpoken,
            /* [annotation][in] */ 
            _In_  SPSHORTCUTTYPE shType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetShortcuts( 
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][out][in] */ 
            _Inout_  SPSHORTCUTPAIRLIST *pShortcutpairList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGeneration( 
            /* [annotation][out] */ 
            _Out_  DWORD *pdwGeneration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWordsFromGenerationChange( 
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDLIST *pWordList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWords( 
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDLIST *pWordList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetShortcutsForGeneration( 
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out][in] */ 
            _Inout_  SPSHORTCUTPAIRLIST *pShortcutpairList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGenerationChange( 
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [annotation][out][in] */ 
            _Inout_  SPSHORTCUTPAIRLIST *pShortcutpairList) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpShortcutVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpShortcut * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpShortcut * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpShortcut * This);
        
        DECLSPEC_XFGVIRT(ISpShortcut, AddShortcut)
        HRESULT ( STDMETHODCALLTYPE *AddShortcut )( 
            __RPC__in ISpShortcut * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDisplay,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSpoken,
            /* [annotation][in] */ 
            _In_  SPSHORTCUTTYPE shType);
        
        DECLSPEC_XFGVIRT(ISpShortcut, RemoveShortcut)
        HRESULT ( STDMETHODCALLTYPE *RemoveShortcut )( 
            __RPC__in ISpShortcut * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszDisplay,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszSpoken,
            /* [annotation][in] */ 
            _In_  SPSHORTCUTTYPE shType);
        
        DECLSPEC_XFGVIRT(ISpShortcut, GetShortcuts)
        HRESULT ( STDMETHODCALLTYPE *GetShortcuts )( 
            __RPC__in ISpShortcut * This,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][out][in] */ 
            _Inout_  SPSHORTCUTPAIRLIST *pShortcutpairList);
        
        DECLSPEC_XFGVIRT(ISpShortcut, GetGeneration)
        HRESULT ( STDMETHODCALLTYPE *GetGeneration )( 
            __RPC__in ISpShortcut * This,
            /* [annotation][out] */ 
            _Out_  DWORD *pdwGeneration);
        
        DECLSPEC_XFGVIRT(ISpShortcut, GetWordsFromGenerationChange)
        HRESULT ( STDMETHODCALLTYPE *GetWordsFromGenerationChange )( 
            __RPC__in ISpShortcut * This,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDLIST *pWordList);
        
        DECLSPEC_XFGVIRT(ISpShortcut, GetWords)
        HRESULT ( STDMETHODCALLTYPE *GetWords )( 
            __RPC__in ISpShortcut * This,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDLIST *pWordList);
        
        DECLSPEC_XFGVIRT(ISpShortcut, GetShortcutsForGeneration)
        HRESULT ( STDMETHODCALLTYPE *GetShortcutsForGeneration )( 
            __RPC__in ISpShortcut * This,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwCookie,
            /* [annotation][out][in] */ 
            _Inout_  SPSHORTCUTPAIRLIST *pShortcutpairList);
        
        DECLSPEC_XFGVIRT(ISpShortcut, GetGenerationChange)
        HRESULT ( STDMETHODCALLTYPE *GetGenerationChange )( 
            __RPC__in ISpShortcut * This,
            /* [annotation][out][in] */ 
            _Inout_  DWORD *pdwGeneration,
            /* [annotation][out][in] */ 
            _Inout_  SPSHORTCUTPAIRLIST *pShortcutpairList);
        
        END_INTERFACE
    } ISpShortcutVtbl;

    interface ISpShortcut
    {
        CONST_VTBL struct ISpShortcutVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpShortcut_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpShortcut_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpShortcut_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpShortcut_AddShortcut(This,pszDisplay,LangID,pszSpoken,shType)	\
    ( (This)->lpVtbl -> AddShortcut(This,pszDisplay,LangID,pszSpoken,shType) ) 

#define ISpShortcut_RemoveShortcut(This,pszDisplay,LangID,pszSpoken,shType)	\
    ( (This)->lpVtbl -> RemoveShortcut(This,pszDisplay,LangID,pszSpoken,shType) ) 

#define ISpShortcut_GetShortcuts(This,LangID,pShortcutpairList)	\
    ( (This)->lpVtbl -> GetShortcuts(This,LangID,pShortcutpairList) ) 

#define ISpShortcut_GetGeneration(This,pdwGeneration)	\
    ( (This)->lpVtbl -> GetGeneration(This,pdwGeneration) ) 

#define ISpShortcut_GetWordsFromGenerationChange(This,pdwGeneration,pWordList)	\
    ( (This)->lpVtbl -> GetWordsFromGenerationChange(This,pdwGeneration,pWordList) ) 

#define ISpShortcut_GetWords(This,pdwGeneration,pdwCookie,pWordList)	\
    ( (This)->lpVtbl -> GetWords(This,pdwGeneration,pdwCookie,pWordList) ) 

#define ISpShortcut_GetShortcutsForGeneration(This,pdwGeneration,pdwCookie,pShortcutpairList)	\
    ( (This)->lpVtbl -> GetShortcutsForGeneration(This,pdwGeneration,pdwCookie,pShortcutpairList) ) 

#define ISpShortcut_GetGenerationChange(This,pdwGeneration,pShortcutpairList)	\
    ( (This)->lpVtbl -> GetGenerationChange(This,pdwGeneration,pShortcutpairList) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpShortcut_INTERFACE_DEFINED__ */


#ifndef __ISpPhoneConverter_INTERFACE_DEFINED__
#define __ISpPhoneConverter_INTERFACE_DEFINED__

/* interface ISpPhoneConverter */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpPhoneConverter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8445C581-0CAC-4A38-ABFE-9B2CE2826455")
    ISpPhoneConverter : public ISpObjectWithToken
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PhoneToId( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPhone,
            /* [annotation][out] */ 
            _Out_  SPPHONEID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IdToPhone( 
            /* [annotation][in] */ 
            _In_  PCSPPHONEID pId,
            /* [annotation][out] */ 
            _Out_  WCHAR *pszPhone) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPhoneConverterVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpPhoneConverter * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpPhoneConverter * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpPhoneConverter * This);
        
        DECLSPEC_XFGVIRT(ISpObjectWithToken, SetObjectToken)
        HRESULT ( STDMETHODCALLTYPE *SetObjectToken )( 
            __RPC__in ISpPhoneConverter * This,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pToken);
        
        DECLSPEC_XFGVIRT(ISpObjectWithToken, GetObjectToken)
        HRESULT ( STDMETHODCALLTYPE *GetObjectToken )( 
            __RPC__in ISpPhoneConverter * This,
            /* [annotation][out] */ 
            _Out_  ISpObjectToken **ppToken);
        
        DECLSPEC_XFGVIRT(ISpPhoneConverter, PhoneToId)
        HRESULT ( STDMETHODCALLTYPE *PhoneToId )( 
            __RPC__in ISpPhoneConverter * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszPhone,
            /* [annotation][out] */ 
            _Out_  SPPHONEID *pId);
        
        DECLSPEC_XFGVIRT(ISpPhoneConverter, IdToPhone)
        HRESULT ( STDMETHODCALLTYPE *IdToPhone )( 
            __RPC__in ISpPhoneConverter * This,
            /* [annotation][in] */ 
            _In_  PCSPPHONEID pId,
            /* [annotation][out] */ 
            _Out_  WCHAR *pszPhone);
        
        END_INTERFACE
    } ISpPhoneConverterVtbl;

    interface ISpPhoneConverter
    {
        CONST_VTBL struct ISpPhoneConverterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPhoneConverter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPhoneConverter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPhoneConverter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPhoneConverter_SetObjectToken(This,pToken)	\
    ( (This)->lpVtbl -> SetObjectToken(This,pToken) ) 

#define ISpPhoneConverter_GetObjectToken(This,ppToken)	\
    ( (This)->lpVtbl -> GetObjectToken(This,ppToken) ) 


#define ISpPhoneConverter_PhoneToId(This,pszPhone,pId)	\
    ( (This)->lpVtbl -> PhoneToId(This,pszPhone,pId) ) 

#define ISpPhoneConverter_IdToPhone(This,pId,pszPhone)	\
    ( (This)->lpVtbl -> IdToPhone(This,pId,pszPhone) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPhoneConverter_INTERFACE_DEFINED__ */


#ifndef __ISpPhoneticAlphabetConverter_INTERFACE_DEFINED__
#define __ISpPhoneticAlphabetConverter_INTERFACE_DEFINED__

/* interface ISpPhoneticAlphabetConverter */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpPhoneticAlphabetConverter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("133ADCD4-19B4-4020-9FDC-842E78253B17")
    ISpPhoneticAlphabetConverter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLangId( 
            /* [out][annotation] */ 
            _Out_writes_(1)  WORD *pLangID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLangId( 
            /* [annotation][in] */ 
            _In_  WORD LangID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SAPI2UPS( 
            /* [in][annotation] */ 
            _In_z_  const SPPHONEID *pszSAPIId,
            /* [out][annotation] */ 
            _Out_writes_z_(cMaxLength)  SPPHONEID *pszUPSId,
            /* [annotation][in] */ 
            _In_  DWORD cMaxLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UPS2SAPI( 
            /* [in][annotation] */ 
            _In_z_  const SPPHONEID *pszUPSId,
            /* [out][annotation] */ 
            _Out_writes_z_(cMaxLength)  SPPHONEID *pszSAPIId,
            /* [annotation][in] */ 
            _In_  DWORD cMaxLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxConvertLength( 
            /* [annotation][in] */ 
            _In_  DWORD cSrcLength,
            /* [annotation][in] */ 
            _In_  BOOL bSAPI2UPS,
            /* [out][annotation] */ 
            _Out_writes_(1)  DWORD *pcMaxDestLength) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPhoneticAlphabetConverterVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPhoneticAlphabetConverter * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPhoneticAlphabetConverter * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPhoneticAlphabetConverter * This);
        
        DECLSPEC_XFGVIRT(ISpPhoneticAlphabetConverter, GetLangId)
        HRESULT ( STDMETHODCALLTYPE *GetLangId )( 
            ISpPhoneticAlphabetConverter * This,
            /* [out][annotation] */ 
            _Out_writes_(1)  WORD *pLangID);
        
        DECLSPEC_XFGVIRT(ISpPhoneticAlphabetConverter, SetLangId)
        HRESULT ( STDMETHODCALLTYPE *SetLangId )( 
            ISpPhoneticAlphabetConverter * This,
            /* [annotation][in] */ 
            _In_  WORD LangID);
        
        DECLSPEC_XFGVIRT(ISpPhoneticAlphabetConverter, SAPI2UPS)
        HRESULT ( STDMETHODCALLTYPE *SAPI2UPS )( 
            ISpPhoneticAlphabetConverter * This,
            /* [in][annotation] */ 
            _In_z_  const SPPHONEID *pszSAPIId,
            /* [out][annotation] */ 
            _Out_writes_z_(cMaxLength)  SPPHONEID *pszUPSId,
            /* [annotation][in] */ 
            _In_  DWORD cMaxLength);
        
        DECLSPEC_XFGVIRT(ISpPhoneticAlphabetConverter, UPS2SAPI)
        HRESULT ( STDMETHODCALLTYPE *UPS2SAPI )( 
            ISpPhoneticAlphabetConverter * This,
            /* [in][annotation] */ 
            _In_z_  const SPPHONEID *pszUPSId,
            /* [out][annotation] */ 
            _Out_writes_z_(cMaxLength)  SPPHONEID *pszSAPIId,
            /* [annotation][in] */ 
            _In_  DWORD cMaxLength);
        
        DECLSPEC_XFGVIRT(ISpPhoneticAlphabetConverter, GetMaxConvertLength)
        HRESULT ( STDMETHODCALLTYPE *GetMaxConvertLength )( 
            ISpPhoneticAlphabetConverter * This,
            /* [annotation][in] */ 
            _In_  DWORD cSrcLength,
            /* [annotation][in] */ 
            _In_  BOOL bSAPI2UPS,
            /* [out][annotation] */ 
            _Out_writes_(1)  DWORD *pcMaxDestLength);
        
        END_INTERFACE
    } ISpPhoneticAlphabetConverterVtbl;

    interface ISpPhoneticAlphabetConverter
    {
        CONST_VTBL struct ISpPhoneticAlphabetConverterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPhoneticAlphabetConverter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPhoneticAlphabetConverter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPhoneticAlphabetConverter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPhoneticAlphabetConverter_GetLangId(This,pLangID)	\
    ( (This)->lpVtbl -> GetLangId(This,pLangID) ) 

#define ISpPhoneticAlphabetConverter_SetLangId(This,LangID)	\
    ( (This)->lpVtbl -> SetLangId(This,LangID) ) 

#define ISpPhoneticAlphabetConverter_SAPI2UPS(This,pszSAPIId,pszUPSId,cMaxLength)	\
    ( (This)->lpVtbl -> SAPI2UPS(This,pszSAPIId,pszUPSId,cMaxLength) ) 

#define ISpPhoneticAlphabetConverter_UPS2SAPI(This,pszUPSId,pszSAPIId,cMaxLength)	\
    ( (This)->lpVtbl -> UPS2SAPI(This,pszUPSId,pszSAPIId,cMaxLength) ) 

#define ISpPhoneticAlphabetConverter_GetMaxConvertLength(This,cSrcLength,bSAPI2UPS,pcMaxDestLength)	\
    ( (This)->lpVtbl -> GetMaxConvertLength(This,cSrcLength,bSAPI2UPS,pcMaxDestLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPhoneticAlphabetConverter_INTERFACE_DEFINED__ */


#ifndef __ISpPhoneticAlphabetSelection_INTERFACE_DEFINED__
#define __ISpPhoneticAlphabetSelection_INTERFACE_DEFINED__

/* interface ISpPhoneticAlphabetSelection */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpPhoneticAlphabetSelection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B2745EFD-42CE-48ca-81F1-A96E02538A90")
    ISpPhoneticAlphabetSelection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsAlphabetUPS( 
            /* [annotation][out] */ 
            _Out_  BOOL *pfIsUPS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAlphabetToUPS( 
            /* [annotation][in] */ 
            _In_  BOOL fForceUPS) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPhoneticAlphabetSelectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpPhoneticAlphabetSelection * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpPhoneticAlphabetSelection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpPhoneticAlphabetSelection * This);
        
        DECLSPEC_XFGVIRT(ISpPhoneticAlphabetSelection, IsAlphabetUPS)
        HRESULT ( STDMETHODCALLTYPE *IsAlphabetUPS )( 
            __RPC__in ISpPhoneticAlphabetSelection * This,
            /* [annotation][out] */ 
            _Out_  BOOL *pfIsUPS);
        
        DECLSPEC_XFGVIRT(ISpPhoneticAlphabetSelection, SetAlphabetToUPS)
        HRESULT ( STDMETHODCALLTYPE *SetAlphabetToUPS )( 
            __RPC__in ISpPhoneticAlphabetSelection * This,
            /* [annotation][in] */ 
            _In_  BOOL fForceUPS);
        
        END_INTERFACE
    } ISpPhoneticAlphabetSelectionVtbl;

    interface ISpPhoneticAlphabetSelection
    {
        CONST_VTBL struct ISpPhoneticAlphabetSelectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPhoneticAlphabetSelection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPhoneticAlphabetSelection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPhoneticAlphabetSelection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPhoneticAlphabetSelection_IsAlphabetUPS(This,pfIsUPS)	\
    ( (This)->lpVtbl -> IsAlphabetUPS(This,pfIsUPS) ) 

#define ISpPhoneticAlphabetSelection_SetAlphabetToUPS(This,fForceUPS)	\
    ( (This)->lpVtbl -> SetAlphabetToUPS(This,fForceUPS) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPhoneticAlphabetSelection_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0026 */
/* [local] */ 

typedef /* [hidden][restricted] */ struct SPVPITCH
    {
    long MiddleAdj;
    long RangeAdj;
    } 	SPVPITCH;

typedef /* [hidden] */ 
enum SPVACTIONS
    {
        SPVA_Speak	= 0,
        SPVA_Silence	= ( SPVA_Speak + 1 ) ,
        SPVA_Pronounce	= ( SPVA_Silence + 1 ) ,
        SPVA_Bookmark	= ( SPVA_Pronounce + 1 ) ,
        SPVA_SpellOut	= ( SPVA_Bookmark + 1 ) ,
        SPVA_Section	= ( SPVA_SpellOut + 1 ) ,
        SPVA_ParseUnknownTag	= ( SPVA_Section + 1 ) 
    } 	SPVACTIONS;

typedef /* [hidden][restricted] */ struct SPVCONTEXT
    {
    LPCWSTR pCategory;
    LPCWSTR pBefore;
    LPCWSTR pAfter;
    } 	SPVCONTEXT;

typedef /* [hidden][restricted] */ struct SPVSTATE
    {
    SPVACTIONS eAction;
    WORD LangID;
    WORD wReserved;
    long EmphAdj;
    long RateAdj;
    ULONG Volume;
    SPVPITCH PitchAdj;
    ULONG SilenceMSecs;
    SPPHONEID *pPhoneIds;
    SPPARTOFSPEECH ePartOfSpeech;
    SPVCONTEXT Context;
    } 	SPVSTATE;

typedef /* [hidden] */ 
enum SPRUNSTATE
    {
        SPRS_DONE	= ( 1L << 0 ) ,
        SPRS_IS_SPEAKING	= ( 1L << 1 ) 
    } 	SPRUNSTATE;

typedef /* [hidden] */ 
enum SPVLIMITS
    {
        SPMIN_VOLUME	= 0,
        SPMAX_VOLUME	= 100,
        SPMIN_RATE	= -10,
        SPMAX_RATE	= 10
    } 	SPVLIMITS;

typedef /* [hidden] */ 
enum SPVPRIORITY
    {
        SPVPRI_NORMAL	= 0,
        SPVPRI_ALERT	= ( 1L << 0 ) ,
        SPVPRI_OVER	= ( 1L << 1 ) 
    } 	SPVPRIORITY;

typedef /* [hidden][restricted] */ struct SPVOICESTATUS
    {
    ULONG ulCurrentStream;
    ULONG ulLastStreamQueued;
    HRESULT hrLastResult;
    DWORD dwRunningState;
    ULONG ulInputWordPos;
    ULONG ulInputWordLen;
    ULONG ulInputSentPos;
    ULONG ulInputSentLen;
    LONG lBookmarkId;
    SPPHONEID PhonemeId;
    SPVISEMES VisemeId;
    DWORD dwReserved1;
    DWORD dwReserved2;
    } 	SPVOICESTATUS;

typedef /* [hidden] */ 
enum SPEAKFLAGS
    {
        SPF_DEFAULT	= 0,
        SPF_ASYNC	= ( 1L << 0 ) ,
        SPF_PURGEBEFORESPEAK	= ( 1L << 1 ) ,
        SPF_IS_FILENAME	= ( 1L << 2 ) ,
        SPF_IS_XML	= ( 1L << 3 ) ,
        SPF_IS_NOT_XML	= ( 1L << 4 ) ,
        SPF_PERSIST_XML	= ( 1L << 5 ) ,
        SPF_NLP_SPEAK_PUNC	= ( 1L << 6 ) ,
        SPF_PARSE_SAPI	= ( 1L << 7 ) ,
        SPF_PARSE_SSML	= ( 1L << 8 ) ,
        SPF_PARSE_AUTODETECT	= 0,
        SPF_NLP_MASK	= SPF_NLP_SPEAK_PUNC,
        SPF_PARSE_MASK	= ( SPF_PARSE_SAPI | SPF_PARSE_SSML ) ,
        SPF_VOICE_MASK	= ( ( ( ( ( ( ( SPF_ASYNC | SPF_PURGEBEFORESPEAK )  | SPF_IS_FILENAME )  | SPF_IS_XML )  | SPF_IS_NOT_XML )  | SPF_NLP_MASK )  | SPF_PERSIST_XML )  | SPF_PARSE_MASK ) ,
        SPF_UNUSED_FLAGS	= ~SPF_VOICE_MASK
    } 	SPEAKFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0026_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0026_v0_0_s_ifspec;

#ifndef __ISpVoice_INTERFACE_DEFINED__
#define __ISpVoice_INTERFACE_DEFINED__

/* interface ISpVoice */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpVoice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6C44DF74-72B9-4992-A1EC-EF996E0422D4")
    ISpVoice : public ISpEventSource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetOutput( 
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkOutput,
            /* [annotation][in] */ 
            _In_  BOOL fAllowFormatChanges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputObjectToken( 
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppObjectToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputStream( 
            /* [annotation][out] */ 
            _Out_  ISpStreamFormat **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoice( 
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoice( 
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Speak( 
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pwcs,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pulStreamNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SpeakStream( 
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pulStreamNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [annotation][out] */ 
            _Out_  SPVOICESTATUS *pStatus,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszLastBookmark) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pItemType,
            /* [annotation][in] */ 
            _In_  long lNumItems,
            /* [annotation][out] */ 
            _Out_  ULONG *pulNumSkipped) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPriority( 
            /* [annotation][in] */ 
            _In_  SPVPRIORITY ePriority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPriority( 
            /* [annotation][out] */ 
            _Out_  SPVPRIORITY *pePriority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAlertBoundary( 
            /* [annotation][in] */ 
            _In_  SPEVENTENUM eBoundary) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAlertBoundary( 
            /* [annotation][out] */ 
            _Out_  SPEVENTENUM *peBoundary) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRate( 
            /* [annotation][in] */ 
            _In_  long RateAdjust) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRate( 
            /* [annotation][out] */ 
            _Out_  long *pRateAdjust) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVolume( 
            /* [annotation][in] */ 
            _In_  USHORT usVolume) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVolume( 
            /* [annotation][out] */ 
            _Out_  USHORT *pusVolume) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitUntilDone( 
            /* [annotation][in] */ 
            _In_  ULONG msTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSyncSpeakTimeout( 
            /* [annotation][in] */ 
            _In_  ULONG msTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSyncSpeakTimeout( 
            /* [annotation][out] */ 
            _Out_  ULONG *pmsTimeout) = 0;
        
        virtual /* [local] */ HANDLE STDMETHODCALLTYPE SpeakCompleteEvent( void) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSupported) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTitle,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpVoiceVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpVoice * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpVoice * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifySink)
        HRESULT ( STDMETHODCALLTYPE *SetNotifySink )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  ISpNotifySink *pNotifySink);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWindowMessage)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWindowMessage )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT Msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackFunction)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackFunction )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  SPNOTIFYCALLBACK *pfnCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackInterface)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackInterface )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  ISpNotifyCallback *pSpCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWin32Event)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWin32Event )( 
            ISpVoice * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, WaitForNotifyEvent)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *WaitForNotifyEvent )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMilliseconds);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, GetNotifyEventHandle)
        /* [local] */ HANDLE ( STDMETHODCALLTYPE *GetNotifyEventHandle )( 
            ISpVoice * This);
        
        DECLSPEC_XFGVIRT(ISpEventSource, SetInterest)
        HRESULT ( STDMETHODCALLTYPE *SetInterest )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullEventInterest,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullQueuedInterest);
        
        DECLSPEC_XFGVIRT(ISpEventSource, GetEvents)
        HRESULT ( STDMETHODCALLTYPE *GetEvents )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  SPEVENT *pEventArray,
            /* [annotation][out] */ 
            _Out_  ULONG *pulFetched);
        
        DECLSPEC_XFGVIRT(ISpEventSource, GetInfo)
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            ISpVoice * This,
            /* [annotation][out] */ 
            _Out_  SPEVENTSOURCEINFO *pInfo);
        
        DECLSPEC_XFGVIRT(ISpVoice, SetOutput)
        HRESULT ( STDMETHODCALLTYPE *SetOutput )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  IUnknown *pUnkOutput,
            /* [annotation][in] */ 
            _In_  BOOL fAllowFormatChanges);
        
        DECLSPEC_XFGVIRT(ISpVoice, GetOutputObjectToken)
        HRESULT ( STDMETHODCALLTYPE *GetOutputObjectToken )( 
            ISpVoice * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppObjectToken);
        
        DECLSPEC_XFGVIRT(ISpVoice, GetOutputStream)
        HRESULT ( STDMETHODCALLTYPE *GetOutputStream )( 
            ISpVoice * This,
            /* [annotation][out] */ 
            _Out_  ISpStreamFormat **ppStream);
        
        DECLSPEC_XFGVIRT(ISpVoice, Pause)
        HRESULT ( STDMETHODCALLTYPE *Pause )( 
            ISpVoice * This);
        
        DECLSPEC_XFGVIRT(ISpVoice, Resume)
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            ISpVoice * This);
        
        DECLSPEC_XFGVIRT(ISpVoice, SetVoice)
        HRESULT ( STDMETHODCALLTYPE *SetVoice )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pToken);
        
        DECLSPEC_XFGVIRT(ISpVoice, GetVoice)
        HRESULT ( STDMETHODCALLTYPE *GetVoice )( 
            ISpVoice * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppToken);
        
        DECLSPEC_XFGVIRT(ISpVoice, Speak)
        HRESULT ( STDMETHODCALLTYPE *Speak )( 
            ISpVoice * This,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pwcs,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pulStreamNumber);
        
        DECLSPEC_XFGVIRT(ISpVoice, SpeakStream)
        HRESULT ( STDMETHODCALLTYPE *SpeakStream )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pulStreamNumber);
        
        DECLSPEC_XFGVIRT(ISpVoice, GetStatus)
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ISpVoice * This,
            /* [annotation][out] */ 
            _Out_  SPVOICESTATUS *pStatus,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszLastBookmark);
        
        DECLSPEC_XFGVIRT(ISpVoice, Skip)
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            ISpVoice * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pItemType,
            /* [annotation][in] */ 
            _In_  long lNumItems,
            /* [annotation][out] */ 
            _Out_  ULONG *pulNumSkipped);
        
        DECLSPEC_XFGVIRT(ISpVoice, SetPriority)
        HRESULT ( STDMETHODCALLTYPE *SetPriority )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  SPVPRIORITY ePriority);
        
        DECLSPEC_XFGVIRT(ISpVoice, GetPriority)
        HRESULT ( STDMETHODCALLTYPE *GetPriority )( 
            ISpVoice * This,
            /* [annotation][out] */ 
            _Out_  SPVPRIORITY *pePriority);
        
        DECLSPEC_XFGVIRT(ISpVoice, SetAlertBoundary)
        HRESULT ( STDMETHODCALLTYPE *SetAlertBoundary )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  SPEVENTENUM eBoundary);
        
        DECLSPEC_XFGVIRT(ISpVoice, GetAlertBoundary)
        HRESULT ( STDMETHODCALLTYPE *GetAlertBoundary )( 
            ISpVoice * This,
            /* [annotation][out] */ 
            _Out_  SPEVENTENUM *peBoundary);
        
        DECLSPEC_XFGVIRT(ISpVoice, SetRate)
        HRESULT ( STDMETHODCALLTYPE *SetRate )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  long RateAdjust);
        
        DECLSPEC_XFGVIRT(ISpVoice, GetRate)
        HRESULT ( STDMETHODCALLTYPE *GetRate )( 
            ISpVoice * This,
            /* [annotation][out] */ 
            _Out_  long *pRateAdjust);
        
        DECLSPEC_XFGVIRT(ISpVoice, SetVolume)
        HRESULT ( STDMETHODCALLTYPE *SetVolume )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  USHORT usVolume);
        
        DECLSPEC_XFGVIRT(ISpVoice, GetVolume)
        HRESULT ( STDMETHODCALLTYPE *GetVolume )( 
            ISpVoice * This,
            /* [annotation][out] */ 
            _Out_  USHORT *pusVolume);
        
        DECLSPEC_XFGVIRT(ISpVoice, WaitUntilDone)
        HRESULT ( STDMETHODCALLTYPE *WaitUntilDone )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  ULONG msTimeout);
        
        DECLSPEC_XFGVIRT(ISpVoice, SetSyncSpeakTimeout)
        HRESULT ( STDMETHODCALLTYPE *SetSyncSpeakTimeout )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  ULONG msTimeout);
        
        DECLSPEC_XFGVIRT(ISpVoice, GetSyncSpeakTimeout)
        HRESULT ( STDMETHODCALLTYPE *GetSyncSpeakTimeout )( 
            ISpVoice * This,
            /* [annotation][out] */ 
            _Out_  ULONG *pmsTimeout);
        
        DECLSPEC_XFGVIRT(ISpVoice, SpeakCompleteEvent)
        /* [local] */ HANDLE ( STDMETHODCALLTYPE *SpeakCompleteEvent )( 
            ISpVoice * This);
        
        DECLSPEC_XFGVIRT(ISpVoice, IsUISupported)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSupported);
        
        DECLSPEC_XFGVIRT(ISpVoice, DisplayUI)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            ISpVoice * This,
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTitle,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData);
        
        END_INTERFACE
    } ISpVoiceVtbl;

    interface ISpVoice
    {
        CONST_VTBL struct ISpVoiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpVoice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpVoice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpVoice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpVoice_SetNotifySink(This,pNotifySink)	\
    ( (This)->lpVtbl -> SetNotifySink(This,pNotifySink) ) 

#define ISpVoice_SetNotifyWindowMessage(This,hWnd,Msg,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyWindowMessage(This,hWnd,Msg,wParam,lParam) ) 

#define ISpVoice_SetNotifyCallbackFunction(This,pfnCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyCallbackFunction(This,pfnCallback,wParam,lParam) ) 

#define ISpVoice_SetNotifyCallbackInterface(This,pSpCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyCallbackInterface(This,pSpCallback,wParam,lParam) ) 

#define ISpVoice_SetNotifyWin32Event(This)	\
    ( (This)->lpVtbl -> SetNotifyWin32Event(This) ) 

#define ISpVoice_WaitForNotifyEvent(This,dwMilliseconds)	\
    ( (This)->lpVtbl -> WaitForNotifyEvent(This,dwMilliseconds) ) 

#define ISpVoice_GetNotifyEventHandle(This)	\
    ( (This)->lpVtbl -> GetNotifyEventHandle(This) ) 


#define ISpVoice_SetInterest(This,ullEventInterest,ullQueuedInterest)	\
    ( (This)->lpVtbl -> SetInterest(This,ullEventInterest,ullQueuedInterest) ) 

#define ISpVoice_GetEvents(This,ulCount,pEventArray,pulFetched)	\
    ( (This)->lpVtbl -> GetEvents(This,ulCount,pEventArray,pulFetched) ) 

#define ISpVoice_GetInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetInfo(This,pInfo) ) 


#define ISpVoice_SetOutput(This,pUnkOutput,fAllowFormatChanges)	\
    ( (This)->lpVtbl -> SetOutput(This,pUnkOutput,fAllowFormatChanges) ) 

#define ISpVoice_GetOutputObjectToken(This,ppObjectToken)	\
    ( (This)->lpVtbl -> GetOutputObjectToken(This,ppObjectToken) ) 

#define ISpVoice_GetOutputStream(This,ppStream)	\
    ( (This)->lpVtbl -> GetOutputStream(This,ppStream) ) 

#define ISpVoice_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define ISpVoice_Resume(This)	\
    ( (This)->lpVtbl -> Resume(This) ) 

#define ISpVoice_SetVoice(This,pToken)	\
    ( (This)->lpVtbl -> SetVoice(This,pToken) ) 

#define ISpVoice_GetVoice(This,ppToken)	\
    ( (This)->lpVtbl -> GetVoice(This,ppToken) ) 

#define ISpVoice_Speak(This,pwcs,dwFlags,pulStreamNumber)	\
    ( (This)->lpVtbl -> Speak(This,pwcs,dwFlags,pulStreamNumber) ) 

#define ISpVoice_SpeakStream(This,pStream,dwFlags,pulStreamNumber)	\
    ( (This)->lpVtbl -> SpeakStream(This,pStream,dwFlags,pulStreamNumber) ) 

#define ISpVoice_GetStatus(This,pStatus,ppszLastBookmark)	\
    ( (This)->lpVtbl -> GetStatus(This,pStatus,ppszLastBookmark) ) 

#define ISpVoice_Skip(This,pItemType,lNumItems,pulNumSkipped)	\
    ( (This)->lpVtbl -> Skip(This,pItemType,lNumItems,pulNumSkipped) ) 

#define ISpVoice_SetPriority(This,ePriority)	\
    ( (This)->lpVtbl -> SetPriority(This,ePriority) ) 

#define ISpVoice_GetPriority(This,pePriority)	\
    ( (This)->lpVtbl -> GetPriority(This,pePriority) ) 

#define ISpVoice_SetAlertBoundary(This,eBoundary)	\
    ( (This)->lpVtbl -> SetAlertBoundary(This,eBoundary) ) 

#define ISpVoice_GetAlertBoundary(This,peBoundary)	\
    ( (This)->lpVtbl -> GetAlertBoundary(This,peBoundary) ) 

#define ISpVoice_SetRate(This,RateAdjust)	\
    ( (This)->lpVtbl -> SetRate(This,RateAdjust) ) 

#define ISpVoice_GetRate(This,pRateAdjust)	\
    ( (This)->lpVtbl -> GetRate(This,pRateAdjust) ) 

#define ISpVoice_SetVolume(This,usVolume)	\
    ( (This)->lpVtbl -> SetVolume(This,usVolume) ) 

#define ISpVoice_GetVolume(This,pusVolume)	\
    ( (This)->lpVtbl -> GetVolume(This,pusVolume) ) 

#define ISpVoice_WaitUntilDone(This,msTimeout)	\
    ( (This)->lpVtbl -> WaitUntilDone(This,msTimeout) ) 

#define ISpVoice_SetSyncSpeakTimeout(This,msTimeout)	\
    ( (This)->lpVtbl -> SetSyncSpeakTimeout(This,msTimeout) ) 

#define ISpVoice_GetSyncSpeakTimeout(This,pmsTimeout)	\
    ( (This)->lpVtbl -> GetSyncSpeakTimeout(This,pmsTimeout) ) 

#define ISpVoice_SpeakCompleteEvent(This)	\
    ( (This)->lpVtbl -> SpeakCompleteEvent(This) ) 

#define ISpVoice_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported)	\
    ( (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported) ) 

#define ISpVoice_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData)	\
    ( (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpVoice_INTERFACE_DEFINED__ */


#ifndef __ISpPhrase_INTERFACE_DEFINED__
#define __ISpPhrase_INTERFACE_DEFINED__

/* interface ISpPhrase */
/* [restricted][unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISpPhrase;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1A5C0354-B621-4b5a-8791-D306ED379E53")
    ISpPhrase : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPhrase( 
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSerializedPhrase( 
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetText( 
            /* [annotation][in] */ 
            _In_  ULONG ulStart,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][in] */ 
            _In_  BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Discard( 
            /* [annotation][in] */ 
            _In_  DWORD dwValueTypes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPhraseVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPhrase * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPhrase * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPhrase * This);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpPhrase * This,
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpPhrase * This,
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetText)
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpPhrase * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStart,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][in] */ 
            _In_  BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes);
        
        DECLSPEC_XFGVIRT(ISpPhrase, Discard)
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpPhrase * This,
            /* [annotation][in] */ 
            _In_  DWORD dwValueTypes);
        
        END_INTERFACE
    } ISpPhraseVtbl;

    interface ISpPhrase
    {
        CONST_VTBL struct ISpPhraseVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPhrase_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPhrase_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPhrase_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPhrase_GetPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetPhrase(This,ppCoMemPhrase) ) 

#define ISpPhrase_GetSerializedPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetSerializedPhrase(This,ppCoMemPhrase) ) 

#define ISpPhrase_GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes)	\
    ( (This)->lpVtbl -> GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes) ) 

#define ISpPhrase_Discard(This,dwValueTypes)	\
    ( (This)->lpVtbl -> Discard(This,dwValueTypes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPhrase_INTERFACE_DEFINED__ */


#ifndef __ISpPhraseAlt_INTERFACE_DEFINED__
#define __ISpPhraseAlt_INTERFACE_DEFINED__

/* interface ISpPhraseAlt */
/* [restricted][unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISpPhraseAlt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8FCEBC98-4E49-4067-9C6C-D86A0E092E3D")
    ISpPhraseAlt : public ISpPhrase
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAltInfo( 
            /* [annotation][out] */ 
            _Out_  ISpPhrase **ppParent,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStartElementInParent,
            /* [annotation][out] */ 
            _Out_  ULONG *pcElementsInParent,
            /* [annotation][out] */ 
            _Out_  ULONG *pcElementsInAlt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Commit( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPhraseAltVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPhraseAlt * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPhraseAlt * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPhraseAlt * This);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpPhraseAlt * This,
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpPhraseAlt * This,
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetText)
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpPhraseAlt * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStart,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][in] */ 
            _In_  BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes);
        
        DECLSPEC_XFGVIRT(ISpPhrase, Discard)
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpPhraseAlt * This,
            /* [annotation][in] */ 
            _In_  DWORD dwValueTypes);
        
        DECLSPEC_XFGVIRT(ISpPhraseAlt, GetAltInfo)
        HRESULT ( STDMETHODCALLTYPE *GetAltInfo )( 
            ISpPhraseAlt * This,
            /* [annotation][out] */ 
            _Out_  ISpPhrase **ppParent,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStartElementInParent,
            /* [annotation][out] */ 
            _Out_  ULONG *pcElementsInParent,
            /* [annotation][out] */ 
            _Out_  ULONG *pcElementsInAlt);
        
        DECLSPEC_XFGVIRT(ISpPhraseAlt, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpPhraseAlt * This);
        
        END_INTERFACE
    } ISpPhraseAltVtbl;

    interface ISpPhraseAlt
    {
        CONST_VTBL struct ISpPhraseAltVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPhraseAlt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPhraseAlt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPhraseAlt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPhraseAlt_GetPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetPhrase(This,ppCoMemPhrase) ) 

#define ISpPhraseAlt_GetSerializedPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetSerializedPhrase(This,ppCoMemPhrase) ) 

#define ISpPhraseAlt_GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes)	\
    ( (This)->lpVtbl -> GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes) ) 

#define ISpPhraseAlt_Discard(This,dwValueTypes)	\
    ( (This)->lpVtbl -> Discard(This,dwValueTypes) ) 


#define ISpPhraseAlt_GetAltInfo(This,ppParent,pulStartElementInParent,pcElementsInParent,pcElementsInAlt)	\
    ( (This)->lpVtbl -> GetAltInfo(This,ppParent,pulStartElementInParent,pcElementsInParent,pcElementsInAlt) ) 

#define ISpPhraseAlt_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPhraseAlt_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0029 */
/* [local] */ 

typedef 
enum SPXMLRESULTOPTIONS
    {
        SPXRO_SML	= 0,
        SPXRO_Alternates_SML	= 1
    } 	SPXMLRESULTOPTIONS;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0029_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0029_v0_0_s_ifspec;

#ifndef __ISpPhrase2_INTERFACE_DEFINED__
#define __ISpPhrase2_INTERFACE_DEFINED__

/* interface ISpPhrase2 */
/* [restricted][unique][helpstring][local][uuid][object] */ 


EXTERN_C const IID IID_ISpPhrase2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F264DA52-E457-4696-B856-A737B717AF79")
    ISpPhrase2 : public ISpPhrase
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetXMLResult( 
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemXMLResult,
            /* [annotation][in] */ 
            _In_  SPXMLRESULTOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetXMLErrorInfo( 
            /* [annotation][out] */ 
            _Out_  SPSEMANTICERRORINFO *pSemanticErrorInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudio( 
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [out][annotation] */ 
            _Outptr_  ISpStreamFormat **ppStream) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPhrase2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPhrase2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPhrase2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPhrase2 * This);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpPhrase2 * This,
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpPhrase2 * This,
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetText)
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpPhrase2 * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStart,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][in] */ 
            _In_  BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes);
        
        DECLSPEC_XFGVIRT(ISpPhrase, Discard)
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpPhrase2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwValueTypes);
        
        DECLSPEC_XFGVIRT(ISpPhrase2, GetXMLResult)
        HRESULT ( STDMETHODCALLTYPE *GetXMLResult )( 
            ISpPhrase2 * This,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemXMLResult,
            /* [annotation][in] */ 
            _In_  SPXMLRESULTOPTIONS Options);
        
        DECLSPEC_XFGVIRT(ISpPhrase2, GetXMLErrorInfo)
        HRESULT ( STDMETHODCALLTYPE *GetXMLErrorInfo )( 
            ISpPhrase2 * This,
            /* [annotation][out] */ 
            _Out_  SPSEMANTICERRORINFO *pSemanticErrorInfo);
        
        DECLSPEC_XFGVIRT(ISpPhrase2, GetAudio)
        HRESULT ( STDMETHODCALLTYPE *GetAudio )( 
            ISpPhrase2 * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [out][annotation] */ 
            _Outptr_  ISpStreamFormat **ppStream);
        
        END_INTERFACE
    } ISpPhrase2Vtbl;

    interface ISpPhrase2
    {
        CONST_VTBL struct ISpPhrase2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpPhrase2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpPhrase2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpPhrase2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpPhrase2_GetPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetPhrase(This,ppCoMemPhrase) ) 

#define ISpPhrase2_GetSerializedPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetSerializedPhrase(This,ppCoMemPhrase) ) 

#define ISpPhrase2_GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes)	\
    ( (This)->lpVtbl -> GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes) ) 

#define ISpPhrase2_Discard(This,dwValueTypes)	\
    ( (This)->lpVtbl -> Discard(This,dwValueTypes) ) 


#define ISpPhrase2_GetXMLResult(This,ppszCoMemXMLResult,Options)	\
    ( (This)->lpVtbl -> GetXMLResult(This,ppszCoMemXMLResult,Options) ) 

#define ISpPhrase2_GetXMLErrorInfo(This,pSemanticErrorInfo)	\
    ( (This)->lpVtbl -> GetXMLErrorInfo(This,pSemanticErrorInfo) ) 

#define ISpPhrase2_GetAudio(This,ulStartElement,cElements,ppStream)	\
    ( (This)->lpVtbl -> GetAudio(This,ulStartElement,cElements,ppStream) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpPhrase2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0030 */
/* [local] */ 

typedef /* [hidden][restricted] */ struct SPRECORESULTTIMES
    {
    FILETIME ftStreamTime;
    ULONGLONG ullLength;
    DWORD dwTickCount;
    ULONGLONG ullStart;
    } 	SPRECORESULTTIMES;

typedef /* [hidden] */ struct SPSERIALIZEDRESULT
    {
    ULONG ulSerializedSize;
    } 	SPSERIALIZEDRESULT;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0030_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0030_v0_0_s_ifspec;

#ifndef __ISpRecoResult_INTERFACE_DEFINED__
#define __ISpRecoResult_INTERFACE_DEFINED__

/* interface ISpRecoResult */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpRecoResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("20B053BE-E235-43cd-9A2A-8D17A48B7842")
    ISpRecoResult : public ISpPhrase
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetResultTimes( 
            /* [annotation][out] */ 
            _Out_  SPRECORESULTTIMES *pTimes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAlternates( 
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][in] */ 
            _In_  ULONG ulRequestCount,
            /* [out][annotation] */ 
            _Out_writes_to_(ulRequestCount,*pcPhrasesReturned)  ISpPhraseAlt **ppPhrases,
            /* [annotation][out] */ 
            _Out_  ULONG *pcPhrasesReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudio( 
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][out] */ 
            _Out_  ISpStreamFormat **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SpeakAudio( 
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStreamNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Serialize( 
            /* [annotation][out] */ 
            _Out_  SPSERIALIZEDRESULT **ppCoMemSerializedResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScaleAudio( 
            /* [annotation][in] */ 
            _In_  const GUID *pAudioFormatId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecoContext( 
            /* [annotation][out] */ 
            _Out_  ISpRecoContext **ppRecoContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecoResultVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecoResult * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecoResult * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecoResult * This);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpRecoResult * This,
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpRecoResult * This,
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetText)
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpRecoResult * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStart,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][in] */ 
            _In_  BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes);
        
        DECLSPEC_XFGVIRT(ISpPhrase, Discard)
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpRecoResult * This,
            /* [annotation][in] */ 
            _In_  DWORD dwValueTypes);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetResultTimes)
        HRESULT ( STDMETHODCALLTYPE *GetResultTimes )( 
            ISpRecoResult * This,
            /* [annotation][out] */ 
            _Out_  SPRECORESULTTIMES *pTimes);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetAlternates)
        HRESULT ( STDMETHODCALLTYPE *GetAlternates )( 
            ISpRecoResult * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][in] */ 
            _In_  ULONG ulRequestCount,
            /* [out][annotation] */ 
            _Out_writes_to_(ulRequestCount,*pcPhrasesReturned)  ISpPhraseAlt **ppPhrases,
            /* [annotation][out] */ 
            _Out_  ULONG *pcPhrasesReturned);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetAudio)
        HRESULT ( STDMETHODCALLTYPE *GetAudio )( 
            ISpRecoResult * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][out] */ 
            _Out_  ISpStreamFormat **ppStream);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, SpeakAudio)
        HRESULT ( STDMETHODCALLTYPE *SpeakAudio )( 
            ISpRecoResult * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStreamNumber);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, Serialize)
        HRESULT ( STDMETHODCALLTYPE *Serialize )( 
            ISpRecoResult * This,
            /* [annotation][out] */ 
            _Out_  SPSERIALIZEDRESULT **ppCoMemSerializedResult);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, ScaleAudio)
        HRESULT ( STDMETHODCALLTYPE *ScaleAudio )( 
            ISpRecoResult * This,
            /* [annotation][in] */ 
            _In_  const GUID *pAudioFormatId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetRecoContext)
        HRESULT ( STDMETHODCALLTYPE *GetRecoContext )( 
            ISpRecoResult * This,
            /* [annotation][out] */ 
            _Out_  ISpRecoContext **ppRecoContext);
        
        END_INTERFACE
    } ISpRecoResultVtbl;

    interface ISpRecoResult
    {
        CONST_VTBL struct ISpRecoResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpRecoResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpRecoResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpRecoResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpRecoResult_GetPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetPhrase(This,ppCoMemPhrase) ) 

#define ISpRecoResult_GetSerializedPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetSerializedPhrase(This,ppCoMemPhrase) ) 

#define ISpRecoResult_GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes)	\
    ( (This)->lpVtbl -> GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes) ) 

#define ISpRecoResult_Discard(This,dwValueTypes)	\
    ( (This)->lpVtbl -> Discard(This,dwValueTypes) ) 


#define ISpRecoResult_GetResultTimes(This,pTimes)	\
    ( (This)->lpVtbl -> GetResultTimes(This,pTimes) ) 

#define ISpRecoResult_GetAlternates(This,ulStartElement,cElements,ulRequestCount,ppPhrases,pcPhrasesReturned)	\
    ( (This)->lpVtbl -> GetAlternates(This,ulStartElement,cElements,ulRequestCount,ppPhrases,pcPhrasesReturned) ) 

#define ISpRecoResult_GetAudio(This,ulStartElement,cElements,ppStream)	\
    ( (This)->lpVtbl -> GetAudio(This,ulStartElement,cElements,ppStream) ) 

#define ISpRecoResult_SpeakAudio(This,ulStartElement,cElements,dwFlags,pulStreamNumber)	\
    ( (This)->lpVtbl -> SpeakAudio(This,ulStartElement,cElements,dwFlags,pulStreamNumber) ) 

#define ISpRecoResult_Serialize(This,ppCoMemSerializedResult)	\
    ( (This)->lpVtbl -> Serialize(This,ppCoMemSerializedResult) ) 

#define ISpRecoResult_ScaleAudio(This,pAudioFormatId,pWaveFormatEx)	\
    ( (This)->lpVtbl -> ScaleAudio(This,pAudioFormatId,pWaveFormatEx) ) 

#define ISpRecoResult_GetRecoContext(This,ppRecoContext)	\
    ( (This)->lpVtbl -> GetRecoContext(This,ppRecoContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpRecoResult_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0031 */
/* [local] */ 

typedef /* [hidden] */ 
enum SPCOMMITFLAGS
    {
        SPCF_NONE	= 0,
        SPCF_ADD_TO_USER_LEXICON	= ( 1 << 0 ) ,
        SPCF_DEFINITE_CORRECTION	= ( 1 << 1 ) 
    } 	SPCOMMITFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0031_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0031_v0_0_s_ifspec;

#ifndef __ISpRecoResult2_INTERFACE_DEFINED__
#define __ISpRecoResult2_INTERFACE_DEFINED__

/* interface ISpRecoResult2 */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpRecoResult2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("27CAC6C4-88F2-41f2-8817-0C95E59F1E6E")
    ISpRecoResult2 : public ISpRecoResult
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CommitAlternate( 
            /* [annotation][in] */ 
            _In_  ISpPhraseAlt *pPhraseAlt,
            /* [annotation][out] */ 
            _Out_  ISpRecoResult **ppNewResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CommitText( 
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszCorrectedData,
            /* [annotation][in] */ 
            _In_  DWORD eCommitFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTextFeedback( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszFeedback,
            /* [annotation][in] */ 
            _In_  BOOL fSuccessful) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecoResult2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecoResult2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecoResult2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecoResult2 * This);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpRecoResult2 * This,
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpRecoResult2 * This,
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetText)
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpRecoResult2 * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStart,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][in] */ 
            _In_  BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes);
        
        DECLSPEC_XFGVIRT(ISpPhrase, Discard)
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpRecoResult2 * This,
            /* [annotation][in] */ 
            _In_  DWORD dwValueTypes);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetResultTimes)
        HRESULT ( STDMETHODCALLTYPE *GetResultTimes )( 
            ISpRecoResult2 * This,
            /* [annotation][out] */ 
            _Out_  SPRECORESULTTIMES *pTimes);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetAlternates)
        HRESULT ( STDMETHODCALLTYPE *GetAlternates )( 
            ISpRecoResult2 * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][in] */ 
            _In_  ULONG ulRequestCount,
            /* [out][annotation] */ 
            _Out_writes_to_(ulRequestCount,*pcPhrasesReturned)  ISpPhraseAlt **ppPhrases,
            /* [annotation][out] */ 
            _Out_  ULONG *pcPhrasesReturned);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetAudio)
        HRESULT ( STDMETHODCALLTYPE *GetAudio )( 
            ISpRecoResult2 * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][out] */ 
            _Out_  ISpStreamFormat **ppStream);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, SpeakAudio)
        HRESULT ( STDMETHODCALLTYPE *SpeakAudio )( 
            ISpRecoResult2 * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStreamNumber);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, Serialize)
        HRESULT ( STDMETHODCALLTYPE *Serialize )( 
            ISpRecoResult2 * This,
            /* [annotation][out] */ 
            _Out_  SPSERIALIZEDRESULT **ppCoMemSerializedResult);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, ScaleAudio)
        HRESULT ( STDMETHODCALLTYPE *ScaleAudio )( 
            ISpRecoResult2 * This,
            /* [annotation][in] */ 
            _In_  const GUID *pAudioFormatId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetRecoContext)
        HRESULT ( STDMETHODCALLTYPE *GetRecoContext )( 
            ISpRecoResult2 * This,
            /* [annotation][out] */ 
            _Out_  ISpRecoContext **ppRecoContext);
        
        DECLSPEC_XFGVIRT(ISpRecoResult2, CommitAlternate)
        HRESULT ( STDMETHODCALLTYPE *CommitAlternate )( 
            ISpRecoResult2 * This,
            /* [annotation][in] */ 
            _In_  ISpPhraseAlt *pPhraseAlt,
            /* [annotation][out] */ 
            _Out_  ISpRecoResult **ppNewResult);
        
        DECLSPEC_XFGVIRT(ISpRecoResult2, CommitText)
        HRESULT ( STDMETHODCALLTYPE *CommitText )( 
            ISpRecoResult2 * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszCorrectedData,
            /* [annotation][in] */ 
            _In_  DWORD eCommitFlags);
        
        DECLSPEC_XFGVIRT(ISpRecoResult2, SetTextFeedback)
        HRESULT ( STDMETHODCALLTYPE *SetTextFeedback )( 
            ISpRecoResult2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszFeedback,
            /* [annotation][in] */ 
            _In_  BOOL fSuccessful);
        
        END_INTERFACE
    } ISpRecoResult2Vtbl;

    interface ISpRecoResult2
    {
        CONST_VTBL struct ISpRecoResult2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpRecoResult2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpRecoResult2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpRecoResult2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpRecoResult2_GetPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetPhrase(This,ppCoMemPhrase) ) 

#define ISpRecoResult2_GetSerializedPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetSerializedPhrase(This,ppCoMemPhrase) ) 

#define ISpRecoResult2_GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes)	\
    ( (This)->lpVtbl -> GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes) ) 

#define ISpRecoResult2_Discard(This,dwValueTypes)	\
    ( (This)->lpVtbl -> Discard(This,dwValueTypes) ) 


#define ISpRecoResult2_GetResultTimes(This,pTimes)	\
    ( (This)->lpVtbl -> GetResultTimes(This,pTimes) ) 

#define ISpRecoResult2_GetAlternates(This,ulStartElement,cElements,ulRequestCount,ppPhrases,pcPhrasesReturned)	\
    ( (This)->lpVtbl -> GetAlternates(This,ulStartElement,cElements,ulRequestCount,ppPhrases,pcPhrasesReturned) ) 

#define ISpRecoResult2_GetAudio(This,ulStartElement,cElements,ppStream)	\
    ( (This)->lpVtbl -> GetAudio(This,ulStartElement,cElements,ppStream) ) 

#define ISpRecoResult2_SpeakAudio(This,ulStartElement,cElements,dwFlags,pulStreamNumber)	\
    ( (This)->lpVtbl -> SpeakAudio(This,ulStartElement,cElements,dwFlags,pulStreamNumber) ) 

#define ISpRecoResult2_Serialize(This,ppCoMemSerializedResult)	\
    ( (This)->lpVtbl -> Serialize(This,ppCoMemSerializedResult) ) 

#define ISpRecoResult2_ScaleAudio(This,pAudioFormatId,pWaveFormatEx)	\
    ( (This)->lpVtbl -> ScaleAudio(This,pAudioFormatId,pWaveFormatEx) ) 

#define ISpRecoResult2_GetRecoContext(This,ppRecoContext)	\
    ( (This)->lpVtbl -> GetRecoContext(This,ppRecoContext) ) 


#define ISpRecoResult2_CommitAlternate(This,pPhraseAlt,ppNewResult)	\
    ( (This)->lpVtbl -> CommitAlternate(This,pPhraseAlt,ppNewResult) ) 

#define ISpRecoResult2_CommitText(This,ulStartElement,cElements,pszCorrectedData,eCommitFlags)	\
    ( (This)->lpVtbl -> CommitText(This,ulStartElement,cElements,pszCorrectedData,eCommitFlags) ) 

#define ISpRecoResult2_SetTextFeedback(This,pszFeedback,fSuccessful)	\
    ( (This)->lpVtbl -> SetTextFeedback(This,pszFeedback,fSuccessful) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpRecoResult2_INTERFACE_DEFINED__ */


#ifndef __ISpXMLRecoResult_INTERFACE_DEFINED__
#define __ISpXMLRecoResult_INTERFACE_DEFINED__

/* interface ISpXMLRecoResult */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpXMLRecoResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AE39362B-45A8-4074-9B9E-CCF49AA2D0B6")
    ISpXMLRecoResult : public ISpRecoResult
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetXMLResult( 
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemXMLResult,
            /* [annotation][in] */ 
            _In_  SPXMLRESULTOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetXMLErrorInfo( 
            /* [annotation][out] */ 
            _Out_  SPSEMANTICERRORINFO *pSemanticErrorInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpXMLRecoResultVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpXMLRecoResult * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpXMLRecoResult * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpXMLRecoResult * This);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpXMLRecoResult * This,
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpXMLRecoResult * This,
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        DECLSPEC_XFGVIRT(ISpPhrase, GetText)
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpXMLRecoResult * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStart,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][in] */ 
            _In_  BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes);
        
        DECLSPEC_XFGVIRT(ISpPhrase, Discard)
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpXMLRecoResult * This,
            /* [annotation][in] */ 
            _In_  DWORD dwValueTypes);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetResultTimes)
        HRESULT ( STDMETHODCALLTYPE *GetResultTimes )( 
            ISpXMLRecoResult * This,
            /* [annotation][out] */ 
            _Out_  SPRECORESULTTIMES *pTimes);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetAlternates)
        HRESULT ( STDMETHODCALLTYPE *GetAlternates )( 
            ISpXMLRecoResult * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][in] */ 
            _In_  ULONG ulRequestCount,
            /* [out][annotation] */ 
            _Out_writes_to_(ulRequestCount,*pcPhrasesReturned)  ISpPhraseAlt **ppPhrases,
            /* [annotation][out] */ 
            _Out_  ULONG *pcPhrasesReturned);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetAudio)
        HRESULT ( STDMETHODCALLTYPE *GetAudio )( 
            ISpXMLRecoResult * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][out] */ 
            _Out_  ISpStreamFormat **ppStream);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, SpeakAudio)
        HRESULT ( STDMETHODCALLTYPE *SpeakAudio )( 
            ISpXMLRecoResult * This,
            /* [annotation][in] */ 
            _In_  ULONG ulStartElement,
            /* [annotation][in] */ 
            _In_  ULONG cElements,
            /* [annotation][in] */ 
            _In_  DWORD dwFlags,
            /* [annotation][out] */ 
            _Out_  ULONG *pulStreamNumber);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, Serialize)
        HRESULT ( STDMETHODCALLTYPE *Serialize )( 
            ISpXMLRecoResult * This,
            /* [annotation][out] */ 
            _Out_  SPSERIALIZEDRESULT **ppCoMemSerializedResult);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, ScaleAudio)
        HRESULT ( STDMETHODCALLTYPE *ScaleAudio )( 
            ISpXMLRecoResult * This,
            /* [annotation][in] */ 
            _In_  const GUID *pAudioFormatId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpRecoResult, GetRecoContext)
        HRESULT ( STDMETHODCALLTYPE *GetRecoContext )( 
            ISpXMLRecoResult * This,
            /* [annotation][out] */ 
            _Out_  ISpRecoContext **ppRecoContext);
        
        DECLSPEC_XFGVIRT(ISpXMLRecoResult, GetXMLResult)
        HRESULT ( STDMETHODCALLTYPE *GetXMLResult )( 
            ISpXMLRecoResult * This,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemXMLResult,
            /* [annotation][in] */ 
            _In_  SPXMLRESULTOPTIONS Options);
        
        DECLSPEC_XFGVIRT(ISpXMLRecoResult, GetXMLErrorInfo)
        HRESULT ( STDMETHODCALLTYPE *GetXMLErrorInfo )( 
            ISpXMLRecoResult * This,
            /* [annotation][out] */ 
            _Out_  SPSEMANTICERRORINFO *pSemanticErrorInfo);
        
        END_INTERFACE
    } ISpXMLRecoResultVtbl;

    interface ISpXMLRecoResult
    {
        CONST_VTBL struct ISpXMLRecoResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpXMLRecoResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpXMLRecoResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpXMLRecoResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpXMLRecoResult_GetPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetPhrase(This,ppCoMemPhrase) ) 

#define ISpXMLRecoResult_GetSerializedPhrase(This,ppCoMemPhrase)	\
    ( (This)->lpVtbl -> GetSerializedPhrase(This,ppCoMemPhrase) ) 

#define ISpXMLRecoResult_GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes)	\
    ( (This)->lpVtbl -> GetText(This,ulStart,ulCount,fUseTextReplacements,ppszCoMemText,pbDisplayAttributes) ) 

#define ISpXMLRecoResult_Discard(This,dwValueTypes)	\
    ( (This)->lpVtbl -> Discard(This,dwValueTypes) ) 


#define ISpXMLRecoResult_GetResultTimes(This,pTimes)	\
    ( (This)->lpVtbl -> GetResultTimes(This,pTimes) ) 

#define ISpXMLRecoResult_GetAlternates(This,ulStartElement,cElements,ulRequestCount,ppPhrases,pcPhrasesReturned)	\
    ( (This)->lpVtbl -> GetAlternates(This,ulStartElement,cElements,ulRequestCount,ppPhrases,pcPhrasesReturned) ) 

#define ISpXMLRecoResult_GetAudio(This,ulStartElement,cElements,ppStream)	\
    ( (This)->lpVtbl -> GetAudio(This,ulStartElement,cElements,ppStream) ) 

#define ISpXMLRecoResult_SpeakAudio(This,ulStartElement,cElements,dwFlags,pulStreamNumber)	\
    ( (This)->lpVtbl -> SpeakAudio(This,ulStartElement,cElements,dwFlags,pulStreamNumber) ) 

#define ISpXMLRecoResult_Serialize(This,ppCoMemSerializedResult)	\
    ( (This)->lpVtbl -> Serialize(This,ppCoMemSerializedResult) ) 

#define ISpXMLRecoResult_ScaleAudio(This,pAudioFormatId,pWaveFormatEx)	\
    ( (This)->lpVtbl -> ScaleAudio(This,pAudioFormatId,pWaveFormatEx) ) 

#define ISpXMLRecoResult_GetRecoContext(This,ppRecoContext)	\
    ( (This)->lpVtbl -> GetRecoContext(This,ppRecoContext) ) 


#define ISpXMLRecoResult_GetXMLResult(This,ppszCoMemXMLResult,Options)	\
    ( (This)->lpVtbl -> GetXMLResult(This,ppszCoMemXMLResult,Options) ) 

#define ISpXMLRecoResult_GetXMLErrorInfo(This,pSemanticErrorInfo)	\
    ( (This)->lpVtbl -> GetXMLErrorInfo(This,pSemanticErrorInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpXMLRecoResult_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0033 */
/* [local] */ 

typedef /* [hidden] */ struct tagSPTEXTSELECTIONINFO
    {
    ULONG ulStartActiveOffset;
    ULONG cchActiveChars;
    ULONG ulStartSelection;
    ULONG cchSelection;
    } 	SPTEXTSELECTIONINFO;

typedef /* [hidden] */ 
enum SPWORDPRONOUNCEABLE
    {
        SPWP_UNKNOWN_WORD_UNPRONOUNCEABLE	= 0,
        SPWP_UNKNOWN_WORD_PRONOUNCEABLE	= 1,
        SPWP_KNOWN_WORD_PRONOUNCEABLE	= 2
    } 	SPWORDPRONOUNCEABLE;

typedef /* [hidden] */ 
enum SPGRAMMARSTATE
    {
        SPGS_DISABLED	= 0,
        SPGS_ENABLED	= 1,
        SPGS_EXCLUSIVE	= 3
    } 	SPGRAMMARSTATE;

typedef /* [hidden] */ 
enum SPCONTEXTSTATE
    {
        SPCS_DISABLED	= 0,
        SPCS_ENABLED	= 1
    } 	SPCONTEXTSTATE;

typedef /* [hidden] */ 
enum SPRULESTATE
    {
        SPRS_INACTIVE	= 0,
        SPRS_ACTIVE	= 1,
        SPRS_ACTIVE_WITH_AUTO_PAUSE	= 3,
        SPRS_ACTIVE_USER_DELIMITED	= 4
    } 	SPRULESTATE;

#define	SP_STREAMPOS_ASAP	( 0 )

#define	SP_STREAMPOS_REALTIME	( -1 )

#define SPRULETRANS_TEXTBUFFER (SPSTATEHANDLE)(-1)
#define SPRULETRANS_WILDCARD   (SPSTATEHANDLE)(-2)
#define SPRULETRANS_DICTATION  (SPSTATEHANDLE)(-3)
typedef /* [hidden] */ 
enum SPGRAMMARWORDTYPE
    {
        SPWT_DISPLAY	= 0,
        SPWT_LEXICAL	= ( SPWT_DISPLAY + 1 ) ,
        SPWT_PRONUNCIATION	= ( SPWT_LEXICAL + 1 ) ,
        SPWT_LEXICAL_NO_SPECIAL_CHARS	= ( SPWT_PRONUNCIATION + 1 ) 
    } 	SPGRAMMARWORDTYPE;

typedef /* [hidden] */ struct tagSPPROPERTYINFO
    {
    LPCWSTR pszName;
    ULONG ulId;
    LPCWSTR pszValue;
    VARIANT vValue;
    } 	SPPROPERTYINFO;

typedef /* [hidden] */ 
enum SPCFGRULEATTRIBUTES
    {
        SPRAF_TopLevel	= ( 1 << 0 ) ,
        SPRAF_Active	= ( 1 << 1 ) ,
        SPRAF_Export	= ( 1 << 2 ) ,
        SPRAF_Import	= ( 1 << 3 ) ,
        SPRAF_Interpreter	= ( 1 << 4 ) ,
        SPRAF_Dynamic	= ( 1 << 5 ) ,
        SPRAF_Root	= ( 1 << 6 ) ,
        SPRAF_AutoPause	= ( 1 << 16 ) ,
        SPRAF_UserDelimited	= ( 1 << 17 ) 
    } 	SPCFGRULEATTRIBUTES;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0033_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0033_v0_0_s_ifspec;

#ifndef __ISpGrammarBuilder_INTERFACE_DEFINED__
#define __ISpGrammarBuilder_INTERFACE_DEFINED__

/* interface ISpGrammarBuilder */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpGrammarBuilder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8137828F-591A-4A42-BE58-49EA7EBAAC68")
    ISpGrammarBuilder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ResetGrammar( 
            /* [annotation][in] */ 
            _In_  WORD NewLanguage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRule( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszRuleName,
            /* [annotation][in] */ 
            _In_  DWORD dwRuleId,
            /* [annotation][in] */ 
            _In_  DWORD dwAttributes,
            /* [annotation][in] */ 
            _In_  BOOL fCreateIfNotExist,
            /* [annotation][out] */ 
            _Out_  SPSTATEHANDLE *phInitialState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearRule( 
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewState( 
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hState,
            /* [annotation][out] */ 
            _Out_  SPSTATEHANDLE *phState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddWordTransition( 
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hFromState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hToState,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR psz,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszSeparators,
            /* [annotation][in] */ 
            _In_  SPGRAMMARWORDTYPE eWordType,
            /* [annotation][in] */ 
            _In_  float Weight,
            /* [annotation][in] */ 
            _In_  const SPPROPERTYINFO *pPropInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRuleTransition( 
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hFromState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hToState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  float Weight,
            /* [annotation][in] */ 
            _In_  const SPPROPERTYINFO *pPropInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddResource( 
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hRuleState,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszResourceName,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszResourceValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Commit( 
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpGrammarBuilderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpGrammarBuilder * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpGrammarBuilder * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpGrammarBuilder * This);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, ResetGrammar)
        HRESULT ( STDMETHODCALLTYPE *ResetGrammar )( 
            ISpGrammarBuilder * This,
            /* [annotation][in] */ 
            _In_  WORD NewLanguage);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, GetRule)
        HRESULT ( STDMETHODCALLTYPE *GetRule )( 
            ISpGrammarBuilder * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszRuleName,
            /* [annotation][in] */ 
            _In_  DWORD dwRuleId,
            /* [annotation][in] */ 
            _In_  DWORD dwAttributes,
            /* [annotation][in] */ 
            _In_  BOOL fCreateIfNotExist,
            /* [annotation][out] */ 
            _Out_  SPSTATEHANDLE *phInitialState);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, ClearRule)
        HRESULT ( STDMETHODCALLTYPE *ClearRule )( 
            ISpGrammarBuilder * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hState);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, CreateNewState)
        HRESULT ( STDMETHODCALLTYPE *CreateNewState )( 
            ISpGrammarBuilder * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hState,
            /* [annotation][out] */ 
            _Out_  SPSTATEHANDLE *phState);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddWordTransition)
        HRESULT ( STDMETHODCALLTYPE *AddWordTransition )( 
            ISpGrammarBuilder * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hFromState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hToState,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR psz,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszSeparators,
            /* [annotation][in] */ 
            _In_  SPGRAMMARWORDTYPE eWordType,
            /* [annotation][in] */ 
            _In_  float Weight,
            /* [annotation][in] */ 
            _In_  const SPPROPERTYINFO *pPropInfo);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddRuleTransition)
        HRESULT ( STDMETHODCALLTYPE *AddRuleTransition )( 
            ISpGrammarBuilder * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hFromState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hToState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  float Weight,
            /* [annotation][in] */ 
            _In_  const SPPROPERTYINFO *pPropInfo);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddResource)
        HRESULT ( STDMETHODCALLTYPE *AddResource )( 
            ISpGrammarBuilder * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hRuleState,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszResourceName,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszResourceValue);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpGrammarBuilder * This,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        END_INTERFACE
    } ISpGrammarBuilderVtbl;

    interface ISpGrammarBuilder
    {
        CONST_VTBL struct ISpGrammarBuilderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpGrammarBuilder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpGrammarBuilder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpGrammarBuilder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpGrammarBuilder_ResetGrammar(This,NewLanguage)	\
    ( (This)->lpVtbl -> ResetGrammar(This,NewLanguage) ) 

#define ISpGrammarBuilder_GetRule(This,pszRuleName,dwRuleId,dwAttributes,fCreateIfNotExist,phInitialState)	\
    ( (This)->lpVtbl -> GetRule(This,pszRuleName,dwRuleId,dwAttributes,fCreateIfNotExist,phInitialState) ) 

#define ISpGrammarBuilder_ClearRule(This,hState)	\
    ( (This)->lpVtbl -> ClearRule(This,hState) ) 

#define ISpGrammarBuilder_CreateNewState(This,hState,phState)	\
    ( (This)->lpVtbl -> CreateNewState(This,hState,phState) ) 

#define ISpGrammarBuilder_AddWordTransition(This,hFromState,hToState,psz,pszSeparators,eWordType,Weight,pPropInfo)	\
    ( (This)->lpVtbl -> AddWordTransition(This,hFromState,hToState,psz,pszSeparators,eWordType,Weight,pPropInfo) ) 

#define ISpGrammarBuilder_AddRuleTransition(This,hFromState,hToState,hRule,Weight,pPropInfo)	\
    ( (This)->lpVtbl -> AddRuleTransition(This,hFromState,hToState,hRule,Weight,pPropInfo) ) 

#define ISpGrammarBuilder_AddResource(This,hRuleState,pszResourceName,pszResourceValue)	\
    ( (This)->lpVtbl -> AddResource(This,hRuleState,pszResourceName,pszResourceValue) ) 

#define ISpGrammarBuilder_Commit(This,dwReserved)	\
    ( (This)->lpVtbl -> Commit(This,dwReserved) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpGrammarBuilder_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0034 */
/* [local] */ 

typedef /* [hidden] */ 
enum SPLOADOPTIONS
    {
        SPLO_STATIC	= 0,
        SPLO_DYNAMIC	= 1
    } 	SPLOADOPTIONS;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0034_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0034_v0_0_s_ifspec;

#ifndef __ISpRecoGrammar_INTERFACE_DEFINED__
#define __ISpRecoGrammar_INTERFACE_DEFINED__

/* interface ISpRecoGrammar */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpRecoGrammar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2177DB29-7F45-47D0-8554-067E91C80502")
    ISpRecoGrammar : public ISpGrammarBuilder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetGrammarId( 
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pullGrammarId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecoContext( 
            /* [out][annotation] */ 
            _Outptr_  ISpRecoContext **ppRecoCtxt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromFile( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszFileName,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromObject( 
            /* [annotation][in] */ 
            _In_  REFCLSID rcid,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszGrammarName,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromResource( 
            /* [annotation][in] */ 
            _In_  HMODULE hModule,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszResourceName,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszResourceType,
            /* [annotation][in] */ 
            _In_  WORD wLanguage,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromMemory( 
            /* [annotation][in] */ 
            _In_  const SPBINARYGRAMMAR *pGrammar,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromProprietaryGrammar( 
            /* [annotation][in] */ 
            _In_  REFGUID rguidParam,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszStringParam,
            /* [annotation][in] */ 
            _In_  const void *pvDataPrarm,
            /* [annotation][in] */ 
            _In_  ULONG cbDataSize,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRuleState( 
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  void *pReserved,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRuleIdState( 
            /* [annotation][in] */ 
            _In_  ULONG ulRuleId,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadDictation( 
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszTopicName,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnloadDictation( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDictationState( 
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWordSequenceData( 
            /* [in][annotation] */ 
            _In_reads_opt_(cchText)  const WCHAR *pText,
            /* [annotation][in] */ 
            _In_  ULONG cchText,
            /* [annotation][in] */ 
            _In_  const SPTEXTSELECTIONINFO *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTextSelection( 
            /* [annotation][in] */ 
            _In_  const SPTEXTSELECTIONINFO *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPronounceable( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][out] */ 
            _Out_  SPWORDPRONOUNCEABLE *pWordPronounceable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGrammarState( 
            /* [annotation][in] */ 
            _In_  SPGRAMMARSTATE eGrammarState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveCmd( 
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [optional][out][annotation] */ 
            _Outptr_opt_  LPWSTR *ppszCoMemErrorText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGrammarState( 
            /* [annotation][out] */ 
            _Out_  SPGRAMMARSTATE *peGrammarState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecoGrammarVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecoGrammar * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecoGrammar * This);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, ResetGrammar)
        HRESULT ( STDMETHODCALLTYPE *ResetGrammar )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  WORD NewLanguage);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, GetRule)
        HRESULT ( STDMETHODCALLTYPE *GetRule )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszRuleName,
            /* [annotation][in] */ 
            _In_  DWORD dwRuleId,
            /* [annotation][in] */ 
            _In_  DWORD dwAttributes,
            /* [annotation][in] */ 
            _In_  BOOL fCreateIfNotExist,
            /* [annotation][out] */ 
            _Out_  SPSTATEHANDLE *phInitialState);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, ClearRule)
        HRESULT ( STDMETHODCALLTYPE *ClearRule )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hState);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, CreateNewState)
        HRESULT ( STDMETHODCALLTYPE *CreateNewState )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hState,
            /* [annotation][out] */ 
            _Out_  SPSTATEHANDLE *phState);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddWordTransition)
        HRESULT ( STDMETHODCALLTYPE *AddWordTransition )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hFromState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hToState,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR psz,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszSeparators,
            /* [annotation][in] */ 
            _In_  SPGRAMMARWORDTYPE eWordType,
            /* [annotation][in] */ 
            _In_  float Weight,
            /* [annotation][in] */ 
            _In_  const SPPROPERTYINFO *pPropInfo);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddRuleTransition)
        HRESULT ( STDMETHODCALLTYPE *AddRuleTransition )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hFromState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hToState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hRule,
            /* [annotation][in] */ 
            _In_  float Weight,
            /* [annotation][in] */ 
            _In_  const SPPROPERTYINFO *pPropInfo);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddResource)
        HRESULT ( STDMETHODCALLTYPE *AddResource )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hRuleState,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszResourceName,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszResourceValue);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder, Commit)
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, GetGrammarId)
        HRESULT ( STDMETHODCALLTYPE *GetGrammarId )( 
            ISpRecoGrammar * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pullGrammarId);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, GetRecoContext)
        HRESULT ( STDMETHODCALLTYPE *GetRecoContext )( 
            ISpRecoGrammar * This,
            /* [out][annotation] */ 
            _Outptr_  ISpRecoContext **ppRecoCtxt);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadCmdFromFile)
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromFile )( 
            ISpRecoGrammar * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszFileName,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadCmdFromObject)
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromObject )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  REFCLSID rcid,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszGrammarName,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadCmdFromResource)
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromResource )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  HMODULE hModule,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszResourceName,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszResourceType,
            /* [annotation][in] */ 
            _In_  WORD wLanguage,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadCmdFromMemory)
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromMemory )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  const SPBINARYGRAMMAR *pGrammar,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadCmdFromProprietaryGrammar)
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromProprietaryGrammar )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  REFGUID rguidParam,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszStringParam,
            /* [annotation][in] */ 
            _In_  const void *pvDataPrarm,
            /* [annotation][in] */ 
            _In_  ULONG cbDataSize,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, SetRuleState)
        HRESULT ( STDMETHODCALLTYPE *SetRuleState )( 
            ISpRecoGrammar * This,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszName,
            /* [annotation][in] */ 
            _In_  void *pReserved,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, SetRuleIdState)
        HRESULT ( STDMETHODCALLTYPE *SetRuleIdState )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  ULONG ulRuleId,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, LoadDictation)
        HRESULT ( STDMETHODCALLTYPE *LoadDictation )( 
            ISpRecoGrammar * This,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszTopicName,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, UnloadDictation)
        HRESULT ( STDMETHODCALLTYPE *UnloadDictation )( 
            ISpRecoGrammar * This);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, SetDictationState)
        HRESULT ( STDMETHODCALLTYPE *SetDictationState )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  SPRULESTATE NewState);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, SetWordSequenceData)
        HRESULT ( STDMETHODCALLTYPE *SetWordSequenceData )( 
            ISpRecoGrammar * This,
            /* [in][annotation] */ 
            _In_reads_opt_(cchText)  const WCHAR *pText,
            /* [annotation][in] */ 
            _In_  ULONG cchText,
            /* [annotation][in] */ 
            _In_  const SPTEXTSELECTIONINFO *pInfo);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, SetTextSelection)
        HRESULT ( STDMETHODCALLTYPE *SetTextSelection )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  const SPTEXTSELECTIONINFO *pInfo);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, IsPronounceable)
        HRESULT ( STDMETHODCALLTYPE *IsPronounceable )( 
            ISpRecoGrammar * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][out] */ 
            _Out_  SPWORDPRONOUNCEABLE *pWordPronounceable);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, SetGrammarState)
        HRESULT ( STDMETHODCALLTYPE *SetGrammarState )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  SPGRAMMARSTATE eGrammarState);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, SaveCmd)
        HRESULT ( STDMETHODCALLTYPE *SaveCmd )( 
            ISpRecoGrammar * This,
            /* [annotation][in] */ 
            _In_  IStream *pStream,
            /* [optional][out][annotation] */ 
            _Outptr_opt_  LPWSTR *ppszCoMemErrorText);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar, GetGrammarState)
        HRESULT ( STDMETHODCALLTYPE *GetGrammarState )( 
            ISpRecoGrammar * This,
            /* [annotation][out] */ 
            _Out_  SPGRAMMARSTATE *peGrammarState);
        
        END_INTERFACE
    } ISpRecoGrammarVtbl;

    interface ISpRecoGrammar
    {
        CONST_VTBL struct ISpRecoGrammarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpRecoGrammar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpRecoGrammar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpRecoGrammar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpRecoGrammar_ResetGrammar(This,NewLanguage)	\
    ( (This)->lpVtbl -> ResetGrammar(This,NewLanguage) ) 

#define ISpRecoGrammar_GetRule(This,pszRuleName,dwRuleId,dwAttributes,fCreateIfNotExist,phInitialState)	\
    ( (This)->lpVtbl -> GetRule(This,pszRuleName,dwRuleId,dwAttributes,fCreateIfNotExist,phInitialState) ) 

#define ISpRecoGrammar_ClearRule(This,hState)	\
    ( (This)->lpVtbl -> ClearRule(This,hState) ) 

#define ISpRecoGrammar_CreateNewState(This,hState,phState)	\
    ( (This)->lpVtbl -> CreateNewState(This,hState,phState) ) 

#define ISpRecoGrammar_AddWordTransition(This,hFromState,hToState,psz,pszSeparators,eWordType,Weight,pPropInfo)	\
    ( (This)->lpVtbl -> AddWordTransition(This,hFromState,hToState,psz,pszSeparators,eWordType,Weight,pPropInfo) ) 

#define ISpRecoGrammar_AddRuleTransition(This,hFromState,hToState,hRule,Weight,pPropInfo)	\
    ( (This)->lpVtbl -> AddRuleTransition(This,hFromState,hToState,hRule,Weight,pPropInfo) ) 

#define ISpRecoGrammar_AddResource(This,hRuleState,pszResourceName,pszResourceValue)	\
    ( (This)->lpVtbl -> AddResource(This,hRuleState,pszResourceName,pszResourceValue) ) 

#define ISpRecoGrammar_Commit(This,dwReserved)	\
    ( (This)->lpVtbl -> Commit(This,dwReserved) ) 


#define ISpRecoGrammar_GetGrammarId(This,pullGrammarId)	\
    ( (This)->lpVtbl -> GetGrammarId(This,pullGrammarId) ) 

#define ISpRecoGrammar_GetRecoContext(This,ppRecoCtxt)	\
    ( (This)->lpVtbl -> GetRecoContext(This,ppRecoCtxt) ) 

#define ISpRecoGrammar_LoadCmdFromFile(This,pszFileName,Options)	\
    ( (This)->lpVtbl -> LoadCmdFromFile(This,pszFileName,Options) ) 

#define ISpRecoGrammar_LoadCmdFromObject(This,rcid,pszGrammarName,Options)	\
    ( (This)->lpVtbl -> LoadCmdFromObject(This,rcid,pszGrammarName,Options) ) 

#define ISpRecoGrammar_LoadCmdFromResource(This,hModule,pszResourceName,pszResourceType,wLanguage,Options)	\
    ( (This)->lpVtbl -> LoadCmdFromResource(This,hModule,pszResourceName,pszResourceType,wLanguage,Options) ) 

#define ISpRecoGrammar_LoadCmdFromMemory(This,pGrammar,Options)	\
    ( (This)->lpVtbl -> LoadCmdFromMemory(This,pGrammar,Options) ) 

#define ISpRecoGrammar_LoadCmdFromProprietaryGrammar(This,rguidParam,pszStringParam,pvDataPrarm,cbDataSize,Options)	\
    ( (This)->lpVtbl -> LoadCmdFromProprietaryGrammar(This,rguidParam,pszStringParam,pvDataPrarm,cbDataSize,Options) ) 

#define ISpRecoGrammar_SetRuleState(This,pszName,pReserved,NewState)	\
    ( (This)->lpVtbl -> SetRuleState(This,pszName,pReserved,NewState) ) 

#define ISpRecoGrammar_SetRuleIdState(This,ulRuleId,NewState)	\
    ( (This)->lpVtbl -> SetRuleIdState(This,ulRuleId,NewState) ) 

#define ISpRecoGrammar_LoadDictation(This,pszTopicName,Options)	\
    ( (This)->lpVtbl -> LoadDictation(This,pszTopicName,Options) ) 

#define ISpRecoGrammar_UnloadDictation(This)	\
    ( (This)->lpVtbl -> UnloadDictation(This) ) 

#define ISpRecoGrammar_SetDictationState(This,NewState)	\
    ( (This)->lpVtbl -> SetDictationState(This,NewState) ) 

#define ISpRecoGrammar_SetWordSequenceData(This,pText,cchText,pInfo)	\
    ( (This)->lpVtbl -> SetWordSequenceData(This,pText,cchText,pInfo) ) 

#define ISpRecoGrammar_SetTextSelection(This,pInfo)	\
    ( (This)->lpVtbl -> SetTextSelection(This,pInfo) ) 

#define ISpRecoGrammar_IsPronounceable(This,pszWord,pWordPronounceable)	\
    ( (This)->lpVtbl -> IsPronounceable(This,pszWord,pWordPronounceable) ) 

#define ISpRecoGrammar_SetGrammarState(This,eGrammarState)	\
    ( (This)->lpVtbl -> SetGrammarState(This,eGrammarState) ) 

#define ISpRecoGrammar_SaveCmd(This,pStream,ppszCoMemErrorText)	\
    ( (This)->lpVtbl -> SaveCmd(This,pStream,ppszCoMemErrorText) ) 

#define ISpRecoGrammar_GetGrammarState(This,peGrammarState)	\
    ( (This)->lpVtbl -> GetGrammarState(This,peGrammarState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpRecoGrammar_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0035 */
/* [local] */ 

typedef 
enum SPMATCHINGMODE
    {
        AllWords	= 0,
        Subsequence	= 1,
        OrderedSubset	= 3,
        SubsequenceContentRequired	= 5,
        OrderedSubsetContentRequired	= 7
    } 	SPMATCHINGMODE;

typedef 
enum PHONETICALPHABET
    {
        PA_Ipa	= 0,
        PA_Ups	= 1,
        PA_Sapi	= 2
    } 	PHONETICALPHABET;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0035_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0035_v0_0_s_ifspec;

#ifndef __ISpGrammarBuilder2_INTERFACE_DEFINED__
#define __ISpGrammarBuilder2_INTERFACE_DEFINED__

/* interface ISpGrammarBuilder2 */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpGrammarBuilder2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8AB10026-20CC-4b20-8C22-A49C9BA78F60")
    ISpGrammarBuilder2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddTextSubset( 
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hFromState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hToState,
            /* [annotation][in] */ 
            _In_  LPCWSTR psz,
            /* [annotation][in] */ 
            _In_  SPMATCHINGMODE eMatchMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPhoneticAlphabet( 
            /* [annotation][in] */ 
            _In_  PHONETICALPHABET phoneticALphabet) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpGrammarBuilder2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpGrammarBuilder2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpGrammarBuilder2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpGrammarBuilder2 * This);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder2, AddTextSubset)
        HRESULT ( STDMETHODCALLTYPE *AddTextSubset )( 
            ISpGrammarBuilder2 * This,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hFromState,
            /* [annotation][in] */ 
            _In_  SPSTATEHANDLE hToState,
            /* [annotation][in] */ 
            _In_  LPCWSTR psz,
            /* [annotation][in] */ 
            _In_  SPMATCHINGMODE eMatchMode);
        
        DECLSPEC_XFGVIRT(ISpGrammarBuilder2, SetPhoneticAlphabet)
        HRESULT ( STDMETHODCALLTYPE *SetPhoneticAlphabet )( 
            ISpGrammarBuilder2 * This,
            /* [annotation][in] */ 
            _In_  PHONETICALPHABET phoneticALphabet);
        
        END_INTERFACE
    } ISpGrammarBuilder2Vtbl;

    interface ISpGrammarBuilder2
    {
        CONST_VTBL struct ISpGrammarBuilder2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpGrammarBuilder2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpGrammarBuilder2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpGrammarBuilder2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpGrammarBuilder2_AddTextSubset(This,hFromState,hToState,psz,eMatchMode)	\
    ( (This)->lpVtbl -> AddTextSubset(This,hFromState,hToState,psz,eMatchMode) ) 

#define ISpGrammarBuilder2_SetPhoneticAlphabet(This,phoneticALphabet)	\
    ( (This)->lpVtbl -> SetPhoneticAlphabet(This,phoneticALphabet) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpGrammarBuilder2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0036 */
/* [local] */ 

#define SPRP_NORMAL 0


extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0036_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0036_v0_0_s_ifspec;

#ifndef __ISpRecoGrammar2_INTERFACE_DEFINED__
#define __ISpRecoGrammar2_INTERFACE_DEFINED__

/* interface ISpRecoGrammar2 */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpRecoGrammar2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4B37BC9E-9ED6-44a3-93D3-18F022B79EC3")
    ISpRecoGrammar2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRules( 
            /* [annotation][out] */ 
            _Out_  SPRULE **ppCoMemRules,
            /* [annotation][out] */ 
            _Out_  UINT *puNumRules) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromFile2( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszFileName,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszSharingUri,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszBaseUri) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromMemory2( 
            /* [annotation][in] */ 
            _In_  const SPBINARYGRAMMAR *pGrammar,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszSharingUri,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszBaseUri) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRulePriority( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRuleName,
            /* [annotation][in] */ 
            _In_  ULONG ulRuleId,
            /* [annotation][in] */ 
            _In_  int nRulePriority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRuleWeight( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRuleName,
            /* [annotation][in] */ 
            _In_  ULONG ulRuleId,
            /* [annotation][in] */ 
            _In_  float flWeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDictationWeight( 
            /* [annotation][in] */ 
            _In_  float flWeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGrammarLoader( 
            /* [annotation][in] */ 
            _In_  ISpeechResourceLoader *pLoader) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSMLSecurityManager( 
            /* [annotation][in] */ 
            _In_  IInternetSecurityManager *pSMLSecurityManager) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecoGrammar2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecoGrammar2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecoGrammar2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecoGrammar2 * This);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar2, GetRules)
        HRESULT ( STDMETHODCALLTYPE *GetRules )( 
            ISpRecoGrammar2 * This,
            /* [annotation][out] */ 
            _Out_  SPRULE **ppCoMemRules,
            /* [annotation][out] */ 
            _Out_  UINT *puNumRules);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar2, LoadCmdFromFile2)
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromFile2 )( 
            ISpRecoGrammar2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszFileName,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszSharingUri,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszBaseUri);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar2, LoadCmdFromMemory2)
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromMemory2 )( 
            ISpRecoGrammar2 * This,
            /* [annotation][in] */ 
            _In_  const SPBINARYGRAMMAR *pGrammar,
            /* [annotation][in] */ 
            _In_  SPLOADOPTIONS Options,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszSharingUri,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszBaseUri);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar2, SetRulePriority)
        HRESULT ( STDMETHODCALLTYPE *SetRulePriority )( 
            ISpRecoGrammar2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRuleName,
            /* [annotation][in] */ 
            _In_  ULONG ulRuleId,
            /* [annotation][in] */ 
            _In_  int nRulePriority);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar2, SetRuleWeight)
        HRESULT ( STDMETHODCALLTYPE *SetRuleWeight )( 
            ISpRecoGrammar2 * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRuleName,
            /* [annotation][in] */ 
            _In_  ULONG ulRuleId,
            /* [annotation][in] */ 
            _In_  float flWeight);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar2, SetDictationWeight)
        HRESULT ( STDMETHODCALLTYPE *SetDictationWeight )( 
            ISpRecoGrammar2 * This,
            /* [annotation][in] */ 
            _In_  float flWeight);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar2, SetGrammarLoader)
        HRESULT ( STDMETHODCALLTYPE *SetGrammarLoader )( 
            ISpRecoGrammar2 * This,
            /* [annotation][in] */ 
            _In_  ISpeechResourceLoader *pLoader);
        
        DECLSPEC_XFGVIRT(ISpRecoGrammar2, SetSMLSecurityManager)
        HRESULT ( STDMETHODCALLTYPE *SetSMLSecurityManager )( 
            ISpRecoGrammar2 * This,
            /* [annotation][in] */ 
            _In_  IInternetSecurityManager *pSMLSecurityManager);
        
        END_INTERFACE
    } ISpRecoGrammar2Vtbl;

    interface ISpRecoGrammar2
    {
        CONST_VTBL struct ISpRecoGrammar2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpRecoGrammar2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpRecoGrammar2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpRecoGrammar2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpRecoGrammar2_GetRules(This,ppCoMemRules,puNumRules)	\
    ( (This)->lpVtbl -> GetRules(This,ppCoMemRules,puNumRules) ) 

#define ISpRecoGrammar2_LoadCmdFromFile2(This,pszFileName,Options,pszSharingUri,pszBaseUri)	\
    ( (This)->lpVtbl -> LoadCmdFromFile2(This,pszFileName,Options,pszSharingUri,pszBaseUri) ) 

#define ISpRecoGrammar2_LoadCmdFromMemory2(This,pGrammar,Options,pszSharingUri,pszBaseUri)	\
    ( (This)->lpVtbl -> LoadCmdFromMemory2(This,pGrammar,Options,pszSharingUri,pszBaseUri) ) 

#define ISpRecoGrammar2_SetRulePriority(This,pszRuleName,ulRuleId,nRulePriority)	\
    ( (This)->lpVtbl -> SetRulePriority(This,pszRuleName,ulRuleId,nRulePriority) ) 

#define ISpRecoGrammar2_SetRuleWeight(This,pszRuleName,ulRuleId,flWeight)	\
    ( (This)->lpVtbl -> SetRuleWeight(This,pszRuleName,ulRuleId,flWeight) ) 

#define ISpRecoGrammar2_SetDictationWeight(This,flWeight)	\
    ( (This)->lpVtbl -> SetDictationWeight(This,flWeight) ) 

#define ISpRecoGrammar2_SetGrammarLoader(This,pLoader)	\
    ( (This)->lpVtbl -> SetGrammarLoader(This,pLoader) ) 

#define ISpRecoGrammar2_SetSMLSecurityManager(This,pSMLSecurityManager)	\
    ( (This)->lpVtbl -> SetSMLSecurityManager(This,pSMLSecurityManager) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpRecoGrammar2_INTERFACE_DEFINED__ */


#ifndef __ISpeechResourceLoader_INTERFACE_DEFINED__
#define __ISpeechResourceLoader_INTERFACE_DEFINED__

/* interface ISpeechResourceLoader */
/* [dual][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpeechResourceLoader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B9AC5783-FCD0-4b21-B119-B4F8DA8FD2C3")
    ISpeechResourceLoader : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE LoadResource( 
            /* [annotation][in] */ 
            _In_  BSTR bstrResourceUri,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fAlwaysReload,
            /* [annotation][out] */ 
            _Out_  IUnknown **pStream,
            /* [out][annotation] */ 
            _Out_opt_  BSTR *pbstrMIMEType,
            /* [annotation][out] */ 
            _Out_  VARIANT_BOOL *pfModified,
            /* [out][annotation] */ 
            _Out_opt_  BSTR *pbstrRedirectUrl) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLocalCopy( 
            /* [annotation][in] */ 
            _In_  BSTR bstrResourceUri,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrLocalPath,
            /* [out][annotation] */ 
            _Out_opt_  BSTR *pbstrMIMEType,
            /* [out][annotation] */ 
            _Out_opt_  BSTR *pbstrRedirectUrl) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReleaseLocalCopy( 
            /* [annotation][in] */ 
            _In_  BSTR pbstrLocalPath) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechResourceLoaderVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpeechResourceLoader * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpeechResourceLoader * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpeechResourceLoader * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISpeechResourceLoader * This,
            /* [annotation][out] */ 
            _Out_  UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISpeechResourceLoader * This,
            /* [annotation][in] */ 
            _In_  UINT iTInfo,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][out] */ 
            _Out_  ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISpeechResourceLoader * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][size_is][in] */ 
            _In_reads_(cNames)  LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][size_is][out] */ 
            _Out_writes_(cNames)  DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechResourceLoader * This,
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
        
        DECLSPEC_XFGVIRT(ISpeechResourceLoader, LoadResource)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *LoadResource )( 
            ISpeechResourceLoader * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrResourceUri,
            /* [annotation][in] */ 
            _In_  VARIANT_BOOL fAlwaysReload,
            /* [annotation][out] */ 
            _Out_  IUnknown **pStream,
            /* [out][annotation] */ 
            _Out_opt_  BSTR *pbstrMIMEType,
            /* [annotation][out] */ 
            _Out_  VARIANT_BOOL *pfModified,
            /* [out][annotation] */ 
            _Out_opt_  BSTR *pbstrRedirectUrl);
        
        DECLSPEC_XFGVIRT(ISpeechResourceLoader, GetLocalCopy)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLocalCopy )( 
            ISpeechResourceLoader * This,
            /* [annotation][in] */ 
            _In_  BSTR bstrResourceUri,
            /* [annotation][out] */ 
            _Out_  BSTR *pbstrLocalPath,
            /* [out][annotation] */ 
            _Out_opt_  BSTR *pbstrMIMEType,
            /* [out][annotation] */ 
            _Out_opt_  BSTR *pbstrRedirectUrl);
        
        DECLSPEC_XFGVIRT(ISpeechResourceLoader, ReleaseLocalCopy)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseLocalCopy )( 
            ISpeechResourceLoader * This,
            /* [annotation][in] */ 
            _In_  BSTR pbstrLocalPath);
        
        END_INTERFACE
    } ISpeechResourceLoaderVtbl;

    interface ISpeechResourceLoader
    {
        CONST_VTBL struct ISpeechResourceLoaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechResourceLoader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechResourceLoader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechResourceLoader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechResourceLoader_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechResourceLoader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechResourceLoader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechResourceLoader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechResourceLoader_LoadResource(This,bstrResourceUri,fAlwaysReload,pStream,pbstrMIMEType,pfModified,pbstrRedirectUrl)	\
    ( (This)->lpVtbl -> LoadResource(This,bstrResourceUri,fAlwaysReload,pStream,pbstrMIMEType,pfModified,pbstrRedirectUrl) ) 

#define ISpeechResourceLoader_GetLocalCopy(This,bstrResourceUri,pbstrLocalPath,pbstrMIMEType,pbstrRedirectUrl)	\
    ( (This)->lpVtbl -> GetLocalCopy(This,bstrResourceUri,pbstrLocalPath,pbstrMIMEType,pbstrRedirectUrl) ) 

#define ISpeechResourceLoader_ReleaseLocalCopy(This,pbstrLocalPath)	\
    ( (This)->lpVtbl -> ReleaseLocalCopy(This,pbstrLocalPath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechResourceLoader_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0038 */
/* [local] */ 

typedef /* [hidden][restricted] */ struct SPRECOCONTEXTSTATUS
    {
    SPINTERFERENCE eInterference;
    WCHAR szRequestTypeOfUI[ 255 ];
    DWORD dwReserved1;
    DWORD dwReserved2;
    } 	SPRECOCONTEXTSTATUS;

typedef /* [hidden] */ 
enum SPBOOKMARKOPTIONS
    {
        SPBO_NONE	= 0,
        SPBO_PAUSE	= ( 1 << 0 ) ,
        SPBO_AHEAD	= ( 1 << 1 ) ,
        SPBO_TIME_UNITS	= ( 1 << 2 ) 
    } 	SPBOOKMARKOPTIONS;

typedef /* [hidden] */ 
enum SPAUDIOOPTIONS
    {
        SPAO_NONE	= 0,
        SPAO_RETAIN_AUDIO	= ( 1 << 0 ) 
    } 	SPAUDIOOPTIONS;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0038_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0038_v0_0_s_ifspec;

#ifndef __ISpRecoContext_INTERFACE_DEFINED__
#define __ISpRecoContext_INTERFACE_DEFINED__

/* interface ISpRecoContext */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpRecoContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F740A62F-7C15-489E-8234-940A33D9272D")
    ISpRecoContext : public ISpEventSource
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRecognizer( 
            /* [annotation][out] */ 
            _Out_  ISpRecognizer **ppRecognizer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateGrammar( 
            /* [annotation][in] */ 
            _In_  ULONGLONG ullGrammarId,
            /* [annotation][out] */ 
            _Out_  ISpRecoGrammar **ppGrammar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [annotation][out] */ 
            _Out_  SPRECOCONTEXTSTATUS *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxAlternates( 
            /* [annotation][in] */ 
            _In_  ULONG *pcAlternates) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxAlternates( 
            /* [annotation][in] */ 
            _In_  ULONG cAlternates) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAudioOptions( 
            /* [annotation][in] */ 
            _In_  SPAUDIOOPTIONS Options,
            /* [annotation][in] */ 
            _In_  const GUID *pAudioFormatId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudioOptions( 
            /* [annotation][in] */ 
            _In_  SPAUDIOOPTIONS *pOptions,
            /* [annotation][out] */ 
            _Out_  GUID *pAudioFormatId,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppCoMemWFEX) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeserializeResult( 
            /* [annotation][in] */ 
            _In_  const SPSERIALIZEDRESULT *pSerializedResult,
            /* [annotation][out] */ 
            _Out_  ISpRecoResult **ppResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Bookmark( 
            /* [annotation][in] */ 
            _In_  SPBOOKMARKOPTIONS Options,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullStreamPosition,
            /* [annotation][in] */ 
            _In_  LPARAM lparamEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdaptationData( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pAdaptationData,
            /* [annotation][in] */ 
            _In_  const ULONG cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pause( 
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( 
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoice( 
            /* [annotation][in] */ 
            _In_  ISpVoice *pVoice,
            /* [annotation][in] */ 
            _In_  BOOL fAllowFormatChanges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoice( 
            /* [annotation][out] */ 
            _Out_  ISpVoice **ppVoice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoicePurgeEvent( 
            /* [annotation][in] */ 
            _In_  ULONGLONG ullEventInterest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoicePurgeEvent( 
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pullEventInterest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetContextState( 
            /* [annotation][in] */ 
            _In_  SPCONTEXTSTATE eContextState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextState( 
            /* [annotation][out] */ 
            _Out_  SPCONTEXTSTATE *peContextState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecoContextVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecoContext * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecoContext * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifySink)
        HRESULT ( STDMETHODCALLTYPE *SetNotifySink )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  ISpNotifySink *pNotifySink);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWindowMessage)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWindowMessage )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  HWND hWnd,
            /* [annotation][in] */ 
            _In_  UINT Msg,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackFunction)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackFunction )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  SPNOTIFYCALLBACK *pfnCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyCallbackInterface)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackInterface )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  ISpNotifyCallback *pSpCallback,
            /* [annotation][in] */ 
            _In_  WPARAM wParam,
            /* [annotation][in] */ 
            _In_  LPARAM lParam);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, SetNotifyWin32Event)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWin32Event )( 
            ISpRecoContext * This);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, WaitForNotifyEvent)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *WaitForNotifyEvent )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  DWORD dwMilliseconds);
        
        DECLSPEC_XFGVIRT(ISpNotifySource, GetNotifyEventHandle)
        /* [local] */ HANDLE ( STDMETHODCALLTYPE *GetNotifyEventHandle )( 
            ISpRecoContext * This);
        
        DECLSPEC_XFGVIRT(ISpEventSource, SetInterest)
        HRESULT ( STDMETHODCALLTYPE *SetInterest )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullEventInterest,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullQueuedInterest);
        
        DECLSPEC_XFGVIRT(ISpEventSource, GetEvents)
        HRESULT ( STDMETHODCALLTYPE *GetEvents )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  ULONG ulCount,
            /* [annotation][size_is][out] */ 
            _Out_writes_(ulCount)  SPEVENT *pEventArray,
            /* [annotation][out] */ 
            _Out_  ULONG *pulFetched);
        
        DECLSPEC_XFGVIRT(ISpEventSource, GetInfo)
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            ISpRecoContext * This,
            /* [annotation][out] */ 
            _Out_  SPEVENTSOURCEINFO *pInfo);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, GetRecognizer)
        HRESULT ( STDMETHODCALLTYPE *GetRecognizer )( 
            ISpRecoContext * This,
            /* [annotation][out] */ 
            _Out_  ISpRecognizer **ppRecognizer);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, CreateGrammar)
        HRESULT ( STDMETHODCALLTYPE *CreateGrammar )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullGrammarId,
            /* [annotation][out] */ 
            _Out_  ISpRecoGrammar **ppGrammar);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, GetStatus)
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ISpRecoContext * This,
            /* [annotation][out] */ 
            _Out_  SPRECOCONTEXTSTATUS *pStatus);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, GetMaxAlternates)
        HRESULT ( STDMETHODCALLTYPE *GetMaxAlternates )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  ULONG *pcAlternates);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, SetMaxAlternates)
        HRESULT ( STDMETHODCALLTYPE *SetMaxAlternates )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  ULONG cAlternates);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, SetAudioOptions)
        HRESULT ( STDMETHODCALLTYPE *SetAudioOptions )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  SPAUDIOOPTIONS Options,
            /* [annotation][in] */ 
            _In_  const GUID *pAudioFormatId,
            /* [annotation][in] */ 
            _In_  const WAVEFORMATEX *pWaveFormatEx);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, GetAudioOptions)
        HRESULT ( STDMETHODCALLTYPE *GetAudioOptions )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  SPAUDIOOPTIONS *pOptions,
            /* [annotation][out] */ 
            _Out_  GUID *pAudioFormatId,
            /* [annotation][out] */ 
            _Out_  WAVEFORMATEX **ppCoMemWFEX);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, DeserializeResult)
        HRESULT ( STDMETHODCALLTYPE *DeserializeResult )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  const SPSERIALIZEDRESULT *pSerializedResult,
            /* [annotation][out] */ 
            _Out_  ISpRecoResult **ppResult);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, Bookmark)
        HRESULT ( STDMETHODCALLTYPE *Bookmark )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  SPBOOKMARKOPTIONS Options,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullStreamPosition,
            /* [annotation][in] */ 
            _In_  LPARAM lparamEvent);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, SetAdaptationData)
        HRESULT ( STDMETHODCALLTYPE *SetAdaptationData )( 
            ISpRecoContext * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pAdaptationData,
            /* [annotation][in] */ 
            _In_  const ULONG cch);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, Pause)
        HRESULT ( STDMETHODCALLTYPE *Pause )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, Resume)
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, SetVoice)
        HRESULT ( STDMETHODCALLTYPE *SetVoice )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  ISpVoice *pVoice,
            /* [annotation][in] */ 
            _In_  BOOL fAllowFormatChanges);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, GetVoice)
        HRESULT ( STDMETHODCALLTYPE *GetVoice )( 
            ISpRecoContext * This,
            /* [annotation][out] */ 
            _Out_  ISpVoice **ppVoice);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, SetVoicePurgeEvent)
        HRESULT ( STDMETHODCALLTYPE *SetVoicePurgeEvent )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  ULONGLONG ullEventInterest);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, GetVoicePurgeEvent)
        HRESULT ( STDMETHODCALLTYPE *GetVoicePurgeEvent )( 
            ISpRecoContext * This,
            /* [annotation][out] */ 
            _Out_  ULONGLONG *pullEventInterest);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, SetContextState)
        HRESULT ( STDMETHODCALLTYPE *SetContextState )( 
            ISpRecoContext * This,
            /* [annotation][in] */ 
            _In_  SPCONTEXTSTATE eContextState);
        
        DECLSPEC_XFGVIRT(ISpRecoContext, GetContextState)
        HRESULT ( STDMETHODCALLTYPE *GetContextState )( 
            ISpRecoContext * This,
            /* [annotation][out] */ 
            _Out_  SPCONTEXTSTATE *peContextState);
        
        END_INTERFACE
    } ISpRecoContextVtbl;

    interface ISpRecoContext
    {
        CONST_VTBL struct ISpRecoContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpRecoContext_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpRecoContext_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpRecoContext_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpRecoContext_SetNotifySink(This,pNotifySink)	\
    ( (This)->lpVtbl -> SetNotifySink(This,pNotifySink) ) 

#define ISpRecoContext_SetNotifyWindowMessage(This,hWnd,Msg,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyWindowMessage(This,hWnd,Msg,wParam,lParam) ) 

#define ISpRecoContext_SetNotifyCallbackFunction(This,pfnCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyCallbackFunction(This,pfnCallback,wParam,lParam) ) 

#define ISpRecoContext_SetNotifyCallbackInterface(This,pSpCallback,wParam,lParam)	\
    ( (This)->lpVtbl -> SetNotifyCallbackInterface(This,pSpCallback,wParam,lParam) ) 

#define ISpRecoContext_SetNotifyWin32Event(This)	\
    ( (This)->lpVtbl -> SetNotifyWin32Event(This) ) 

#define ISpRecoContext_WaitForNotifyEvent(This,dwMilliseconds)	\
    ( (This)->lpVtbl -> WaitForNotifyEvent(This,dwMilliseconds) ) 

#define ISpRecoContext_GetNotifyEventHandle(This)	\
    ( (This)->lpVtbl -> GetNotifyEventHandle(This) ) 


#define ISpRecoContext_SetInterest(This,ullEventInterest,ullQueuedInterest)	\
    ( (This)->lpVtbl -> SetInterest(This,ullEventInterest,ullQueuedInterest) ) 

#define ISpRecoContext_GetEvents(This,ulCount,pEventArray,pulFetched)	\
    ( (This)->lpVtbl -> GetEvents(This,ulCount,pEventArray,pulFetched) ) 

#define ISpRecoContext_GetInfo(This,pInfo)	\
    ( (This)->lpVtbl -> GetInfo(This,pInfo) ) 


#define ISpRecoContext_GetRecognizer(This,ppRecognizer)	\
    ( (This)->lpVtbl -> GetRecognizer(This,ppRecognizer) ) 

#define ISpRecoContext_CreateGrammar(This,ullGrammarId,ppGrammar)	\
    ( (This)->lpVtbl -> CreateGrammar(This,ullGrammarId,ppGrammar) ) 

#define ISpRecoContext_GetStatus(This,pStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pStatus) ) 

#define ISpRecoContext_GetMaxAlternates(This,pcAlternates)	\
    ( (This)->lpVtbl -> GetMaxAlternates(This,pcAlternates) ) 

#define ISpRecoContext_SetMaxAlternates(This,cAlternates)	\
    ( (This)->lpVtbl -> SetMaxAlternates(This,cAlternates) ) 

#define ISpRecoContext_SetAudioOptions(This,Options,pAudioFormatId,pWaveFormatEx)	\
    ( (This)->lpVtbl -> SetAudioOptions(This,Options,pAudioFormatId,pWaveFormatEx) ) 

#define ISpRecoContext_GetAudioOptions(This,pOptions,pAudioFormatId,ppCoMemWFEX)	\
    ( (This)->lpVtbl -> GetAudioOptions(This,pOptions,pAudioFormatId,ppCoMemWFEX) ) 

#define ISpRecoContext_DeserializeResult(This,pSerializedResult,ppResult)	\
    ( (This)->lpVtbl -> DeserializeResult(This,pSerializedResult,ppResult) ) 

#define ISpRecoContext_Bookmark(This,Options,ullStreamPosition,lparamEvent)	\
    ( (This)->lpVtbl -> Bookmark(This,Options,ullStreamPosition,lparamEvent) ) 

#define ISpRecoContext_SetAdaptationData(This,pAdaptationData,cch)	\
    ( (This)->lpVtbl -> SetAdaptationData(This,pAdaptationData,cch) ) 

#define ISpRecoContext_Pause(This,dwReserved)	\
    ( (This)->lpVtbl -> Pause(This,dwReserved) ) 

#define ISpRecoContext_Resume(This,dwReserved)	\
    ( (This)->lpVtbl -> Resume(This,dwReserved) ) 

#define ISpRecoContext_SetVoice(This,pVoice,fAllowFormatChanges)	\
    ( (This)->lpVtbl -> SetVoice(This,pVoice,fAllowFormatChanges) ) 

#define ISpRecoContext_GetVoice(This,ppVoice)	\
    ( (This)->lpVtbl -> GetVoice(This,ppVoice) ) 

#define ISpRecoContext_SetVoicePurgeEvent(This,ullEventInterest)	\
    ( (This)->lpVtbl -> SetVoicePurgeEvent(This,ullEventInterest) ) 

#define ISpRecoContext_GetVoicePurgeEvent(This,pullEventInterest)	\
    ( (This)->lpVtbl -> GetVoicePurgeEvent(This,pullEventInterest) ) 

#define ISpRecoContext_SetContextState(This,eContextState)	\
    ( (This)->lpVtbl -> SetContextState(This,eContextState) ) 

#define ISpRecoContext_GetContextState(This,peContextState)	\
    ( (This)->lpVtbl -> GetContextState(This,peContextState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpRecoContext_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0039 */
/* [local] */ 

typedef /* [hidden] */ 
enum SPGRAMMAROPTIONS
    {
        SPGO_SAPI	= 0x1,
        SPGO_SRGS	= 0x2,
        SPGO_UPS	= 0x4,
        SPGO_SRGS_MS_SCRIPT	= 0x8,
        SPGO_SRGS_W3C_SCRIPT	= 0x100,
        SPGO_SRGS_STG_SCRIPT	= 0x200,
        SPGO_SRGS_SCRIPT	= ( ( ( SPGO_SRGS | SPGO_SRGS_MS_SCRIPT )  | SPGO_SRGS_W3C_SCRIPT )  | SPGO_SRGS_STG_SCRIPT ) ,
        SPGO_FILE	= 0x10,
        SPGO_HTTP	= 0x20,
        SPGO_RES	= 0x40,
        SPGO_OBJECT	= 0x80,
        SPGO_DEFAULT	= 0x3fb,
        SPGO_ALL	= 0x3ff
    } 	SPGRAMMAROPTIONS;

typedef /* [hidden] */ 
enum SPADAPTATIONSETTINGS
    {
        SPADS_Default	= 0,
        SPADS_CurrentRecognizer	= 0x1,
        SPADS_RecoProfile	= 0x2,
        SPADS_Immediate	= 0x4,
        SPADS_Reset	= 0x8,
        SPADS_HighVolumeDataSource	= 0x10
    } 	SPADAPTATIONSETTINGS;

typedef /* [hidden] */ 
enum SPADAPTATIONRELEVANCE
    {
        SPAR_Unknown	= 0,
        SPAR_Low	= 1,
        SPAR_Medium	= 2,
        SPAR_High	= 3
    } 	SPADAPTATIONRELEVANCE;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0039_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0039_v0_0_s_ifspec;

#ifndef __ISpRecoContext2_INTERFACE_DEFINED__
#define __ISpRecoContext2_INTERFACE_DEFINED__

/* interface ISpRecoContext2 */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpRecoContext2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BEAD311C-52FF-437f-9464-6B21054CA73D")
    ISpRecoContext2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetGrammarOptions( 
            /* [annotation][in] */ 
            _In_  DWORD eGrammarOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGrammarOptions( 
            /* [annotation][out] */ 
            _Out_  DWORD *peGrammarOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdaptationData2( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pAdaptationData,
            /* [annotation][in] */ 
            _In_  const ULONG cch,
            /* [annotation][in] */ 
            _In_  LPCWSTR pTopicName,
            /* [annotation][in] */ 
            _In_  DWORD eAdaptationSettings,
            /* [annotation][in] */ 
            _In_  SPADAPTATIONRELEVANCE eRelevance) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecoContext2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecoContext2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecoContext2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecoContext2 * This);
        
        DECLSPEC_XFGVIRT(ISpRecoContext2, SetGrammarOptions)
        HRESULT ( STDMETHODCALLTYPE *SetGrammarOptions )( 
            ISpRecoContext2 * This,
            /* [annotation][in] */ 
            _In_  DWORD eGrammarOptions);
        
        DECLSPEC_XFGVIRT(ISpRecoContext2, GetGrammarOptions)
        HRESULT ( STDMETHODCALLTYPE *GetGrammarOptions )( 
            ISpRecoContext2 * This,
            /* [annotation][out] */ 
            _Out_  DWORD *peGrammarOptions);
        
        DECLSPEC_XFGVIRT(ISpRecoContext2, SetAdaptationData2)
        HRESULT ( STDMETHODCALLTYPE *SetAdaptationData2 )( 
            ISpRecoContext2 * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pAdaptationData,
            /* [annotation][in] */ 
            _In_  const ULONG cch,
            /* [annotation][in] */ 
            _In_  LPCWSTR pTopicName,
            /* [annotation][in] */ 
            _In_  DWORD eAdaptationSettings,
            /* [annotation][in] */ 
            _In_  SPADAPTATIONRELEVANCE eRelevance);
        
        END_INTERFACE
    } ISpRecoContext2Vtbl;

    interface ISpRecoContext2
    {
        CONST_VTBL struct ISpRecoContext2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpRecoContext2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpRecoContext2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpRecoContext2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpRecoContext2_SetGrammarOptions(This,eGrammarOptions)	\
    ( (This)->lpVtbl -> SetGrammarOptions(This,eGrammarOptions) ) 

#define ISpRecoContext2_GetGrammarOptions(This,peGrammarOptions)	\
    ( (This)->lpVtbl -> GetGrammarOptions(This,peGrammarOptions) ) 

#define ISpRecoContext2_SetAdaptationData2(This,pAdaptationData,cch,pTopicName,eAdaptationSettings,eRelevance)	\
    ( (This)->lpVtbl -> SetAdaptationData2(This,pAdaptationData,cch,pTopicName,eAdaptationSettings,eRelevance) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpRecoContext2_INTERFACE_DEFINED__ */


#ifndef __ISpProperties_INTERFACE_DEFINED__
#define __ISpProperties_INTERFACE_DEFINED__

/* interface ISpProperties */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5B4FB971-B115-4DE1-AD97-E482E3BF6EE4")
    ISpProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetPropertyNum( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][in] */ 
            _In_  LONG lValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyNum( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][out] */ 
            _Out_  LONG *plValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyString( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyString( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [string][out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpProperties * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpProperties * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpProperties * This);
        
        DECLSPEC_XFGVIRT(ISpProperties, SetPropertyNum)
        HRESULT ( STDMETHODCALLTYPE *SetPropertyNum )( 
            ISpProperties * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][in] */ 
            _In_  LONG lValue);
        
        DECLSPEC_XFGVIRT(ISpProperties, GetPropertyNum)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyNum )( 
            ISpProperties * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][out] */ 
            _Out_  LONG *plValue);
        
        DECLSPEC_XFGVIRT(ISpProperties, SetPropertyString)
        HRESULT ( STDMETHODCALLTYPE *SetPropertyString )( 
            ISpProperties * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pValue);
        
        DECLSPEC_XFGVIRT(ISpProperties, GetPropertyString)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyString )( 
            ISpProperties * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [string][out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemValue);
        
        END_INTERFACE
    } ISpPropertiesVtbl;

    interface ISpProperties
    {
        CONST_VTBL struct ISpPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpProperties_SetPropertyNum(This,pName,lValue)	\
    ( (This)->lpVtbl -> SetPropertyNum(This,pName,lValue) ) 

#define ISpProperties_GetPropertyNum(This,pName,plValue)	\
    ( (This)->lpVtbl -> GetPropertyNum(This,pName,plValue) ) 

#define ISpProperties_SetPropertyString(This,pName,pValue)	\
    ( (This)->lpVtbl -> SetPropertyString(This,pName,pValue) ) 

#define ISpProperties_GetPropertyString(This,pName,ppCoMemValue)	\
    ( (This)->lpVtbl -> GetPropertyString(This,pName,ppCoMemValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpProperties_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0041 */
/* [local] */ 

#define	SP_MAX_LANGIDS	( 20 )

typedef /* [hidden][restricted] */ struct SPRECOGNIZERSTATUS
    {
    SPAUDIOSTATUS AudioStatus;
    ULONGLONG ullRecognitionStreamPos;
    ULONG ulStreamNumber;
    ULONG ulNumActive;
    CLSID clsidEngine;
    ULONG cLangIDs;
    WORD aLangID[ 20 ];
    ULONGLONG ullRecognitionStreamTime;
    } 	SPRECOGNIZERSTATUS;

typedef /* [hidden] */ 
enum SPWAVEFORMATTYPE
    {
        SPWF_INPUT	= 0,
        SPWF_SRENGINE	= ( SPWF_INPUT + 1 ) 
    } 	SPSTREAMFORMATTYPE;

typedef /* [hidden] */ 
enum SPRECOSTATE
    {
        SPRST_INACTIVE	= 0,
        SPRST_ACTIVE	= ( SPRST_INACTIVE + 1 ) ,
        SPRST_ACTIVE_ALWAYS	= ( SPRST_ACTIVE + 1 ) ,
        SPRST_INACTIVE_WITH_PURGE	= ( SPRST_ACTIVE_ALWAYS + 1 ) ,
        SPRST_NUM_STATES	= ( SPRST_INACTIVE_WITH_PURGE + 1 ) 
    } 	SPRECOSTATE;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0041_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0041_v0_0_s_ifspec;

#ifndef __ISpRecognizer_INTERFACE_DEFINED__
#define __ISpRecognizer_INTERFACE_DEFINED__

/* interface ISpRecognizer */
/* [restricted][local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpRecognizer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C2B5F241-DAA0-4507-9E16-5A1EAA2B7A5C")
    ISpRecognizer : public ISpProperties
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetRecognizer( 
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pRecognizer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecognizer( 
            /* [annotation][out] */ 
            _Out_  ISpObjectToken **ppRecognizer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInput( 
            /* [in][annotation] */ 
            _In_opt_  IUnknown *pUnkInput,
            /* [annotation][in] */ 
            _In_  BOOL fAllowFormatChanges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputObjectToken( 
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInputStream( 
            /* [out][annotation] */ 
            _Outptr_  ISpStreamFormat **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateRecoContext( 
            /* [out][annotation] */ 
            _Outptr_  ISpRecoContext **ppNewCtxt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecoProfile( 
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecoProfile( 
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsSharedInstance( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecoState( 
            /* [annotation][out] */ 
            _Out_  SPRECOSTATE *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecoState( 
            /* [annotation][in] */ 
            _In_  SPRECOSTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [annotation][out] */ 
            _Out_  SPRECOGNIZERSTATUS *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFormat( 
            /* [annotation][in] */ 
            _In_  SPSTREAMFORMATTYPE WaveFormatType,
            /* [annotation][out] */ 
            _Out_  GUID *pFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemWFEX) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSupported) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszTitle,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EmulateRecognition( 
            /* [annotation][in] */ 
            _In_  ISpPhrase *pPhrase) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecognizerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecognizer * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecognizer * This);
        
        DECLSPEC_XFGVIRT(ISpProperties, SetPropertyNum)
        HRESULT ( STDMETHODCALLTYPE *SetPropertyNum )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][in] */ 
            _In_  LONG lValue);
        
        DECLSPEC_XFGVIRT(ISpProperties, GetPropertyNum)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyNum )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][out] */ 
            _Out_  LONG *plValue);
        
        DECLSPEC_XFGVIRT(ISpProperties, SetPropertyString)
        HRESULT ( STDMETHODCALLTYPE *SetPropertyString )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [annotation][in] */ 
            _In_  LPCWSTR pValue);
        
        DECLSPEC_XFGVIRT(ISpProperties, GetPropertyString)
        HRESULT ( STDMETHODCALLTYPE *GetPropertyString )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pName,
            /* [string][out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemValue);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, SetRecognizer)
        HRESULT ( STDMETHODCALLTYPE *SetRecognizer )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pRecognizer);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, GetRecognizer)
        HRESULT ( STDMETHODCALLTYPE *GetRecognizer )( 
            ISpRecognizer * This,
            /* [annotation][out] */ 
            _Out_  ISpObjectToken **ppRecognizer);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, SetInput)
        HRESULT ( STDMETHODCALLTYPE *SetInput )( 
            ISpRecognizer * This,
            /* [in][annotation] */ 
            _In_opt_  IUnknown *pUnkInput,
            /* [annotation][in] */ 
            _In_  BOOL fAllowFormatChanges);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, GetInputObjectToken)
        HRESULT ( STDMETHODCALLTYPE *GetInputObjectToken )( 
            ISpRecognizer * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppToken);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, GetInputStream)
        HRESULT ( STDMETHODCALLTYPE *GetInputStream )( 
            ISpRecognizer * This,
            /* [out][annotation] */ 
            _Outptr_  ISpStreamFormat **ppStream);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, CreateRecoContext)
        HRESULT ( STDMETHODCALLTYPE *CreateRecoContext )( 
            ISpRecognizer * This,
            /* [out][annotation] */ 
            _Outptr_  ISpRecoContext **ppNewCtxt);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, GetRecoProfile)
        HRESULT ( STDMETHODCALLTYPE *GetRecoProfile )( 
            ISpRecognizer * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppToken);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, SetRecoProfile)
        HRESULT ( STDMETHODCALLTYPE *SetRecoProfile )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  ISpObjectToken *pToken);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, IsSharedInstance)
        HRESULT ( STDMETHODCALLTYPE *IsSharedInstance )( 
            ISpRecognizer * This);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, GetRecoState)
        HRESULT ( STDMETHODCALLTYPE *GetRecoState )( 
            ISpRecognizer * This,
            /* [annotation][out] */ 
            _Out_  SPRECOSTATE *pState);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, SetRecoState)
        HRESULT ( STDMETHODCALLTYPE *SetRecoState )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  SPRECOSTATE NewState);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, GetStatus)
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ISpRecognizer * This,
            /* [annotation][out] */ 
            _Out_  SPRECOGNIZERSTATUS *pStatus);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, GetFormat)
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  SPSTREAMFORMATTYPE WaveFormatType,
            /* [annotation][out] */ 
            _Out_  GUID *pFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemWFEX);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, IsUISupported)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData,
            /* [annotation][out] */ 
            _Out_  BOOL *pfSupported);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, DisplayUI)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  HWND hwndParent,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszTitle,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszTypeOfUI,
            /* [annotation][in] */ 
            _In_  void *pvExtraData,
            /* [annotation][in] */ 
            _In_  ULONG cbExtraData);
        
        DECLSPEC_XFGVIRT(ISpRecognizer, EmulateRecognition)
        HRESULT ( STDMETHODCALLTYPE *EmulateRecognition )( 
            ISpRecognizer * This,
            /* [annotation][in] */ 
            _In_  ISpPhrase *pPhrase);
        
        END_INTERFACE
    } ISpRecognizerVtbl;

    interface ISpRecognizer
    {
        CONST_VTBL struct ISpRecognizerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpRecognizer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpRecognizer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpRecognizer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpRecognizer_SetPropertyNum(This,pName,lValue)	\
    ( (This)->lpVtbl -> SetPropertyNum(This,pName,lValue) ) 

#define ISpRecognizer_GetPropertyNum(This,pName,plValue)	\
    ( (This)->lpVtbl -> GetPropertyNum(This,pName,plValue) ) 

#define ISpRecognizer_SetPropertyString(This,pName,pValue)	\
    ( (This)->lpVtbl -> SetPropertyString(This,pName,pValue) ) 

#define ISpRecognizer_GetPropertyString(This,pName,ppCoMemValue)	\
    ( (This)->lpVtbl -> GetPropertyString(This,pName,ppCoMemValue) ) 


#define ISpRecognizer_SetRecognizer(This,pRecognizer)	\
    ( (This)->lpVtbl -> SetRecognizer(This,pRecognizer) ) 

#define ISpRecognizer_GetRecognizer(This,ppRecognizer)	\
    ( (This)->lpVtbl -> GetRecognizer(This,ppRecognizer) ) 

#define ISpRecognizer_SetInput(This,pUnkInput,fAllowFormatChanges)	\
    ( (This)->lpVtbl -> SetInput(This,pUnkInput,fAllowFormatChanges) ) 

#define ISpRecognizer_GetInputObjectToken(This,ppToken)	\
    ( (This)->lpVtbl -> GetInputObjectToken(This,ppToken) ) 

#define ISpRecognizer_GetInputStream(This,ppStream)	\
    ( (This)->lpVtbl -> GetInputStream(This,ppStream) ) 

#define ISpRecognizer_CreateRecoContext(This,ppNewCtxt)	\
    ( (This)->lpVtbl -> CreateRecoContext(This,ppNewCtxt) ) 

#define ISpRecognizer_GetRecoProfile(This,ppToken)	\
    ( (This)->lpVtbl -> GetRecoProfile(This,ppToken) ) 

#define ISpRecognizer_SetRecoProfile(This,pToken)	\
    ( (This)->lpVtbl -> SetRecoProfile(This,pToken) ) 

#define ISpRecognizer_IsSharedInstance(This)	\
    ( (This)->lpVtbl -> IsSharedInstance(This) ) 

#define ISpRecognizer_GetRecoState(This,pState)	\
    ( (This)->lpVtbl -> GetRecoState(This,pState) ) 

#define ISpRecognizer_SetRecoState(This,NewState)	\
    ( (This)->lpVtbl -> SetRecoState(This,NewState) ) 

#define ISpRecognizer_GetStatus(This,pStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pStatus) ) 

#define ISpRecognizer_GetFormat(This,WaveFormatType,pFormatId,ppCoMemWFEX)	\
    ( (This)->lpVtbl -> GetFormat(This,WaveFormatType,pFormatId,ppCoMemWFEX) ) 

#define ISpRecognizer_IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported)	\
    ( (This)->lpVtbl -> IsUISupported(This,pszTypeOfUI,pvExtraData,cbExtraData,pfSupported) ) 

#define ISpRecognizer_DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData)	\
    ( (This)->lpVtbl -> DisplayUI(This,hwndParent,pszTitle,pszTypeOfUI,pvExtraData,cbExtraData) ) 

#define ISpRecognizer_EmulateRecognition(This,pPhrase)	\
    ( (This)->lpVtbl -> EmulateRecognition(This,pPhrase) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpRecognizer_INTERFACE_DEFINED__ */


#ifndef __ISpSerializeState_INTERFACE_DEFINED__
#define __ISpSerializeState_INTERFACE_DEFINED__

/* interface ISpSerializeState */
/* [restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpSerializeState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("21B501A0-0EC7-46c9-92C3-A2BC784C54B9")
    ISpSerializeState : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSerializedState( 
            /* [annotation][out] */ 
            _Out_  BYTE **ppbData,
            /* [annotation][out] */ 
            _Out_  ULONG *pulSize,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSerializedState( 
            /* [annotation][in] */ 
            _In_  BYTE *pbData,
            /* [annotation][in] */ 
            _In_  ULONG ulSize,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpSerializeStateVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpSerializeState * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpSerializeState * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpSerializeState * This);
        
        DECLSPEC_XFGVIRT(ISpSerializeState, GetSerializedState)
        HRESULT ( STDMETHODCALLTYPE *GetSerializedState )( 
            __RPC__in ISpSerializeState * This,
            /* [annotation][out] */ 
            _Out_  BYTE **ppbData,
            /* [annotation][out] */ 
            _Out_  ULONG *pulSize,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        DECLSPEC_XFGVIRT(ISpSerializeState, SetSerializedState)
        HRESULT ( STDMETHODCALLTYPE *SetSerializedState )( 
            __RPC__in ISpSerializeState * This,
            /* [annotation][in] */ 
            _In_  BYTE *pbData,
            /* [annotation][in] */ 
            _In_  ULONG ulSize,
            /* [annotation][in] */ 
            _In_  DWORD dwReserved);
        
        END_INTERFACE
    } ISpSerializeStateVtbl;

    interface ISpSerializeState
    {
        CONST_VTBL struct ISpSerializeStateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpSerializeState_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpSerializeState_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpSerializeState_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpSerializeState_GetSerializedState(This,ppbData,pulSize,dwReserved)	\
    ( (This)->lpVtbl -> GetSerializedState(This,ppbData,pulSize,dwReserved) ) 

#define ISpSerializeState_SetSerializedState(This,pbData,ulSize,dwReserved)	\
    ( (This)->lpVtbl -> SetSerializedState(This,pbData,ulSize,dwReserved) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpSerializeState_INTERFACE_DEFINED__ */


#ifndef __ISpRecognizer2_INTERFACE_DEFINED__
#define __ISpRecognizer2_INTERFACE_DEFINED__

/* interface ISpRecognizer2 */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpRecognizer2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8FC6D974-C81E-4098-93C5-0147F61ED4D3")
    ISpRecognizer2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EmulateRecognitionEx( 
            /* [annotation][in] */ 
            _In_  ISpPhrase *pPhrase,
            /* [annotation][in] */ 
            _In_  DWORD dwCompareFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTrainingState( 
            /* [annotation][in] */ 
            _In_  BOOL fDoingTraining,
            /* [annotation][in] */ 
            _In_  BOOL fAdaptFromTrainingData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetAcousticModelAdaptation( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecognizer2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecognizer2 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecognizer2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecognizer2 * This);
        
        DECLSPEC_XFGVIRT(ISpRecognizer2, EmulateRecognitionEx)
        HRESULT ( STDMETHODCALLTYPE *EmulateRecognitionEx )( 
            ISpRecognizer2 * This,
            /* [annotation][in] */ 
            _In_  ISpPhrase *pPhrase,
            /* [annotation][in] */ 
            _In_  DWORD dwCompareFlags);
        
        DECLSPEC_XFGVIRT(ISpRecognizer2, SetTrainingState)
        HRESULT ( STDMETHODCALLTYPE *SetTrainingState )( 
            ISpRecognizer2 * This,
            /* [annotation][in] */ 
            _In_  BOOL fDoingTraining,
            /* [annotation][in] */ 
            _In_  BOOL fAdaptFromTrainingData);
        
        DECLSPEC_XFGVIRT(ISpRecognizer2, ResetAcousticModelAdaptation)
        HRESULT ( STDMETHODCALLTYPE *ResetAcousticModelAdaptation )( 
            ISpRecognizer2 * This);
        
        END_INTERFACE
    } ISpRecognizer2Vtbl;

    interface ISpRecognizer2
    {
        CONST_VTBL struct ISpRecognizer2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpRecognizer2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpRecognizer2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpRecognizer2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpRecognizer2_EmulateRecognitionEx(This,pPhrase,dwCompareFlags)	\
    ( (This)->lpVtbl -> EmulateRecognitionEx(This,pPhrase,dwCompareFlags) ) 

#define ISpRecognizer2_SetTrainingState(This,fDoingTraining,fAdaptFromTrainingData)	\
    ( (This)->lpVtbl -> SetTrainingState(This,fDoingTraining,fAdaptFromTrainingData) ) 

#define ISpRecognizer2_ResetAcousticModelAdaptation(This)	\
    ( (This)->lpVtbl -> ResetAcousticModelAdaptation(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpRecognizer2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0044 */
/* [local] */ 

typedef 
enum SPCATEGORYTYPE
    {
        SPCT_COMMAND	= 0,
        SPCT_DICTATION	= ( SPCT_COMMAND + 1 ) ,
        SPCT_SLEEP	= ( SPCT_DICTATION + 1 ) ,
        SPCT_SUB_COMMAND	= ( SPCT_SLEEP + 1 ) ,
        SPCT_SUB_DICTATION	= ( SPCT_SUB_COMMAND + 1 ) 
    } 	SPCATEGORYTYPE;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0044_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0044_v0_0_s_ifspec;

#ifndef __ISpRecoCategory_INTERFACE_DEFINED__
#define __ISpRecoCategory_INTERFACE_DEFINED__

/* interface ISpRecoCategory */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpRecoCategory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA0CD0F9-14A2-4f09-8C2A-85CC48979345")
    ISpRecoCategory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [annotation][out] */ 
            _Out_  SPCATEGORYTYPE *peCategoryType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecoCategoryVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecoCategory * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecoCategory * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecoCategory * This);
        
        DECLSPEC_XFGVIRT(ISpRecoCategory, GetType)
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            ISpRecoCategory * This,
            /* [annotation][out] */ 
            _Out_  SPCATEGORYTYPE *peCategoryType);
        
        END_INTERFACE
    } ISpRecoCategoryVtbl;

    interface ISpRecoCategory
    {
        CONST_VTBL struct ISpRecoCategoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpRecoCategory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpRecoCategory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpRecoCategory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpRecoCategory_GetType(This,peCategoryType)	\
    ( (This)->lpVtbl -> GetType(This,peCategoryType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpRecoCategory_INTERFACE_DEFINED__ */


#ifndef __ISpRecognizer3_INTERFACE_DEFINED__
#define __ISpRecognizer3_INTERFACE_DEFINED__

/* interface ISpRecognizer3 */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpRecognizer3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DF1B943C-5838-4AA2-8706-D7CD5B333499")
    ISpRecognizer3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCategory( 
            /* [annotation][in] */ 
            _In_  SPCATEGORYTYPE categoryType,
            /* [out][annotation] */ 
            _Outptr_  ISpRecoCategory **ppCategory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActiveCategory( 
            /* [annotation][in] */ 
            _In_  ISpRecoCategory *pCategory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActiveCategory( 
            /* [out][annotation] */ 
            _Outptr_  ISpRecoCategory **ppCategory) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecognizer3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecognizer3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecognizer3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecognizer3 * This);
        
        DECLSPEC_XFGVIRT(ISpRecognizer3, GetCategory)
        HRESULT ( STDMETHODCALLTYPE *GetCategory )( 
            ISpRecognizer3 * This,
            /* [annotation][in] */ 
            _In_  SPCATEGORYTYPE categoryType,
            /* [out][annotation] */ 
            _Outptr_  ISpRecoCategory **ppCategory);
        
        DECLSPEC_XFGVIRT(ISpRecognizer3, SetActiveCategory)
        HRESULT ( STDMETHODCALLTYPE *SetActiveCategory )( 
            ISpRecognizer3 * This,
            /* [annotation][in] */ 
            _In_  ISpRecoCategory *pCategory);
        
        DECLSPEC_XFGVIRT(ISpRecognizer3, GetActiveCategory)
        HRESULT ( STDMETHODCALLTYPE *GetActiveCategory )( 
            ISpRecognizer3 * This,
            /* [out][annotation] */ 
            _Outptr_  ISpRecoCategory **ppCategory);
        
        END_INTERFACE
    } ISpRecognizer3Vtbl;

    interface ISpRecognizer3
    {
        CONST_VTBL struct ISpRecognizer3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpRecognizer3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpRecognizer3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpRecognizer3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpRecognizer3_GetCategory(This,categoryType,ppCategory)	\
    ( (This)->lpVtbl -> GetCategory(This,categoryType,ppCategory) ) 

#define ISpRecognizer3_SetActiveCategory(This,pCategory)	\
    ( (This)->lpVtbl -> SetActiveCategory(This,pCategory) ) 

#define ISpRecognizer3_GetActiveCategory(This,ppCategory)	\
    ( (This)->lpVtbl -> GetActiveCategory(This,ppCategory) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpRecognizer3_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0046 */
/* [local] */ 

typedef /* [hidden][restricted] */ struct SPNORMALIZATIONLIST
    {
    ULONG ulSize;
    WCHAR **ppszzNormalizedList;
    } 	SPNORMALIZATIONLIST;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0046_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0046_v0_0_s_ifspec;

#ifndef __ISpEnginePronunciation_INTERFACE_DEFINED__
#define __ISpEnginePronunciation_INTERFACE_DEFINED__

/* interface ISpEnginePronunciation */
/* [local][restricted][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpEnginePronunciation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C360CE4B-76D1-4214-AD68-52657D5083DA")
    ISpEnginePronunciation : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Normalize( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszLeftContext,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRightContext,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][out] */ 
            _Out_  SPNORMALIZATIONLIST *pNormalizationList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPronunciations( 
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszLeftContext,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRightContext,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDPRONUNCIATIONLIST *pEnginePronunciationList) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpEnginePronunciationVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpEnginePronunciation * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpEnginePronunciation * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpEnginePronunciation * This);
        
        DECLSPEC_XFGVIRT(ISpEnginePronunciation, Normalize)
        HRESULT ( STDMETHODCALLTYPE *Normalize )( 
            ISpEnginePronunciation * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszLeftContext,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRightContext,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][out] */ 
            _Out_  SPNORMALIZATIONLIST *pNormalizationList);
        
        DECLSPEC_XFGVIRT(ISpEnginePronunciation, GetPronunciations)
        HRESULT ( STDMETHODCALLTYPE *GetPronunciations )( 
            ISpEnginePronunciation * This,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszWord,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszLeftContext,
            /* [annotation][string][in] */ 
            _In_  LPCWSTR pszRightContext,
            /* [annotation][in] */ 
            _In_  WORD LangID,
            /* [annotation][out][in] */ 
            _Inout_  SPWORDPRONUNCIATIONLIST *pEnginePronunciationList);
        
        END_INTERFACE
    } ISpEnginePronunciationVtbl;

    interface ISpEnginePronunciation
    {
        CONST_VTBL struct ISpEnginePronunciationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpEnginePronunciation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpEnginePronunciation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpEnginePronunciation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpEnginePronunciation_Normalize(This,pszWord,pszLeftContext,pszRightContext,LangID,pNormalizationList)	\
    ( (This)->lpVtbl -> Normalize(This,pszWord,pszLeftContext,pszRightContext,LangID,pNormalizationList) ) 

#define ISpEnginePronunciation_GetPronunciations(This,pszWord,pszLeftContext,pszRightContext,LangID,pEnginePronunciationList)	\
    ( (This)->lpVtbl -> GetPronunciations(This,pszWord,pszLeftContext,pszRightContext,LangID,pEnginePronunciationList) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpEnginePronunciation_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_sapi_0000_0047 */
/* [local] */ 

typedef /* [hidden][restricted] */ struct SPDISPLAYTOKEN
    {
    const WCHAR *pszLexical;
    const WCHAR *pszDisplay;
    BYTE bDisplayAttributes;
    } 	SPDISPLAYTOKEN;

typedef /* [hidden][restricted] */ struct SPDISPLAYPHRASE
    {
    ULONG ulNumTokens;
    SPDISPLAYTOKEN *pTokens;
    } 	SPDISPLAYPHRASE;



extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0047_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0047_v0_0_s_ifspec;

#ifndef __ISpDisplayAlternates_INTERFACE_DEFINED__
#define __ISpDisplayAlternates_INTERFACE_DEFINED__

/* interface ISpDisplayAlternates */
/* [local][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISpDisplayAlternates;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C8D7C7E2-0DDE-44b7-AFE3-B0C991FBEB5E")
    ISpDisplayAlternates : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDisplayAlternates( 
            /* [annotation][in] */ 
            _In_  const SPDISPLAYPHRASE *pPhrase,
            /* [annotation][in] */ 
            _In_  ULONG cRequestCount,
            /* [annotation][out] */ 
            _Out_  SPDISPLAYPHRASE **ppCoMemPhrases,
            /* [annotation][out] */ 
            _Out_  ULONG *pcPhrasesReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFullStopTrailSpace( 
            /* [annotation][in] */ 
            _In_  ULONG ulTrailSpace) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpDisplayAlternatesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpDisplayAlternates * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpDisplayAlternates * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpDisplayAlternates * This);
        
        DECLSPEC_XFGVIRT(ISpDisplayAlternates, GetDisplayAlternates)
        HRESULT ( STDMETHODCALLTYPE *GetDisplayAlternates )( 
            ISpDisplayAlternates * This,
            /* [annotation][in] */ 
            _In_  const SPDISPLAYPHRASE *pPhrase,
            /* [annotation][in] */ 
            _In_  ULONG cRequestCount,
            /* [annotation][out] */ 
            _Out_  SPDISPLAYPHRASE **ppCoMemPhrases,
            /* [annotation][out] */ 
            _Out_  ULONG *pcPhrasesReturned);
        
        DECLSPEC_XFGVIRT(ISpDisplayAlternates, SetFullStopTrailSpace)
        HRESULT ( STDMETHODCALLTYPE *SetFullStopTrailSpace )( 
            ISpDisplayAlternates * This,
            /* [annotation][in] */ 
            _In_  ULONG ulTrailSpace);
        
        END_INTERFACE
    } ISpDisplayAlternatesVtbl;

    interface ISpDisplayAlternates
    {
        CONST_VTBL struct ISpDisplayAlternatesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpDisplayAlternates_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpDisplayAlternates_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpDisplayAlternates_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpDisplayAlternates_GetDisplayAlternates(This,pPhrase,cRequestCount,ppCoMemPhrases,pcPhrasesReturned)	\
    ( (This)->lpVtbl -> GetDisplayAlternates(This,pPhrase,cRequestCount,ppCoMemPhrases,pcPhrasesReturned) ) 

#define ISpDisplayAlternates_SetFullStopTrailSpace(This,ulTrailSpace)	\
    ( (This)->lpVtbl -> SetFullStopTrailSpace(This,ulTrailSpace) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpDisplayAlternates_INTERFACE_DEFINED__ */



#ifndef __SpeechLib_LIBRARY_DEFINED__
#define __SpeechLib_LIBRARY_DEFINED__

/* library SpeechLib */
/* [version][uuid][helpstring] */ 


EXTERN_C const IID LIBID_SpeechLib;

EXTERN_C const CLSID CLSID_SpNotifyTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("E2AE5372-5D40-11D2-960E-00C04F8EE628")
SpNotifyTranslator;
#endif

EXTERN_C const CLSID CLSID_SpObjectTokenCategory;

#ifdef __cplusplus

class DECLSPEC_UUID("A910187F-0C7A-45AC-92CC-59EDAFB77B53")
SpObjectTokenCategory;
#endif

EXTERN_C const CLSID CLSID_SpObjectToken;

#ifdef __cplusplus

class DECLSPEC_UUID("EF411752-3736-4CB4-9C8C-8EF4CCB58EFE")
SpObjectToken;
#endif

EXTERN_C const CLSID CLSID_SpResourceManager;

#ifdef __cplusplus

class DECLSPEC_UUID("96749373-3391-11D2-9EE3-00C04F797396")
SpResourceManager;
#endif

EXTERN_C const CLSID CLSID_SpStreamFormatConverter;

#ifdef __cplusplus

class DECLSPEC_UUID("7013943A-E2EC-11D2-A086-00C04F8EF9B5")
SpStreamFormatConverter;
#endif

EXTERN_C const CLSID CLSID_SpMMAudioEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("AB1890A0-E91F-11D2-BB91-00C04F8EE6C0")
SpMMAudioEnum;
#endif

EXTERN_C const CLSID CLSID_SpMMAudioIn;

#ifdef __cplusplus

class DECLSPEC_UUID("CF3D2E50-53F2-11D2-960C-00C04F8EE628")
SpMMAudioIn;
#endif

EXTERN_C const CLSID CLSID_SpMMAudioOut;

#ifdef __cplusplus

class DECLSPEC_UUID("A8C680EB-3D32-11D2-9EE7-00C04F797396")
SpMMAudioOut;
#endif

EXTERN_C const CLSID CLSID_SpStream;

#ifdef __cplusplus

class DECLSPEC_UUID("715D9C59-4442-11D2-9605-00C04F8EE628")
SpStream;
#endif

EXTERN_C const CLSID CLSID_SpVoice;

#ifdef __cplusplus

class DECLSPEC_UUID("96749377-3391-11D2-9EE3-00C04F797396")
SpVoice;
#endif

EXTERN_C const CLSID CLSID_SpSharedRecoContext;

#ifdef __cplusplus

class DECLSPEC_UUID("47206204-5ECA-11D2-960F-00C04F8EE628")
SpSharedRecoContext;
#endif

EXTERN_C const CLSID CLSID_SpInprocRecognizer;

#ifdef __cplusplus

class DECLSPEC_UUID("41B89B6B-9399-11D2-9623-00C04F8EE628")
SpInprocRecognizer;
#endif

EXTERN_C const CLSID CLSID_SpSharedRecognizer;

#ifdef __cplusplus

class DECLSPEC_UUID("3BEE4890-4FE9-4A37-8C1E-5E7E12791C1F")
SpSharedRecognizer;
#endif

EXTERN_C const CLSID CLSID_SpLexicon;

#ifdef __cplusplus

class DECLSPEC_UUID("0655E396-25D0-11D3-9C26-00C04F8EF87C")
SpLexicon;
#endif

EXTERN_C const CLSID CLSID_SpUnCompressedLexicon;

#ifdef __cplusplus

class DECLSPEC_UUID("C9E37C15-DF92-4727-85D6-72E5EEB6995A")
SpUnCompressedLexicon;
#endif

EXTERN_C const CLSID CLSID_SpCompressedLexicon;

#ifdef __cplusplus

class DECLSPEC_UUID("90903716-2F42-11D3-9C26-00C04F8EF87C")
SpCompressedLexicon;
#endif

EXTERN_C const CLSID CLSID_SpShortcut;

#ifdef __cplusplus

class DECLSPEC_UUID("0D722F1A-9FCF-4E62-96D8-6DF8F01A26AA")
SpShortcut;
#endif

EXTERN_C const CLSID CLSID_SpPhoneConverter;

#ifdef __cplusplus

class DECLSPEC_UUID("9185F743-1143-4C28-86B5-BFF14F20E5C8")
SpPhoneConverter;
#endif

EXTERN_C const CLSID CLSID_SpPhoneticAlphabetConverter;

#ifdef __cplusplus

class DECLSPEC_UUID("4F414126-DFE3-4629-99EE-797978317EAD")
SpPhoneticAlphabetConverter;
#endif

EXTERN_C const CLSID CLSID_SpNullPhoneConverter;

#ifdef __cplusplus

class DECLSPEC_UUID("455F24E9-7396-4A16-9715-7C0FDBE3EFE3")
SpNullPhoneConverter;
#endif
#endif /* __SpeechLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_sapi_0000_0049 */
/* [local] */ 

#elif _SAPI_VER >= 0x053
#include "sapi53.h"
#else // _SAPI_VER < 0x053
#include "sapi51.h"
#endif  // _SAPI_VER >= 0x054
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0049_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi_0000_0049_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



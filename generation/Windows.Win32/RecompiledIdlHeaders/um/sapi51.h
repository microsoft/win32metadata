

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

#ifndef __sapi51_h__
#define __sapi51_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
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


#ifndef __ISpPhoneConverter_FWD_DEFINED__
#define __ISpPhoneConverter_FWD_DEFINED__
typedef interface ISpPhoneConverter ISpPhoneConverter;

#endif 	/* __ISpPhoneConverter_FWD_DEFINED__ */


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


#ifndef __ISpRecoResult_FWD_DEFINED__
#define __ISpRecoResult_FWD_DEFINED__
typedef interface ISpRecoResult ISpRecoResult;

#endif 	/* __ISpRecoResult_FWD_DEFINED__ */


#ifndef __ISpGrammarBuilder_FWD_DEFINED__
#define __ISpGrammarBuilder_FWD_DEFINED__
typedef interface ISpGrammarBuilder ISpGrammarBuilder;

#endif 	/* __ISpGrammarBuilder_FWD_DEFINED__ */


#ifndef __ISpRecoGrammar_FWD_DEFINED__
#define __ISpRecoGrammar_FWD_DEFINED__
typedef interface ISpRecoGrammar ISpRecoGrammar;

#endif 	/* __ISpRecoGrammar_FWD_DEFINED__ */


#ifndef __ISpRecoContext_FWD_DEFINED__
#define __ISpRecoContext_FWD_DEFINED__
typedef interface ISpRecoContext ISpRecoContext;

#endif 	/* __ISpRecoContext_FWD_DEFINED__ */


#ifndef __ISpProperties_FWD_DEFINED__
#define __ISpProperties_FWD_DEFINED__
typedef interface ISpProperties ISpProperties;

#endif 	/* __ISpProperties_FWD_DEFINED__ */


#ifndef __ISpRecognizer_FWD_DEFINED__
#define __ISpRecognizer_FWD_DEFINED__
typedef interface ISpRecognizer ISpRecognizer;

#endif 	/* __ISpRecognizer_FWD_DEFINED__ */


#ifndef __ISpeechDataKey_FWD_DEFINED__
#define __ISpeechDataKey_FWD_DEFINED__
typedef interface ISpeechDataKey ISpeechDataKey;

#endif 	/* __ISpeechDataKey_FWD_DEFINED__ */


#ifndef __ISpeechObjectToken_FWD_DEFINED__
#define __ISpeechObjectToken_FWD_DEFINED__
typedef interface ISpeechObjectToken ISpeechObjectToken;

#endif 	/* __ISpeechObjectToken_FWD_DEFINED__ */


#ifndef __ISpeechObjectTokens_FWD_DEFINED__
#define __ISpeechObjectTokens_FWD_DEFINED__
typedef interface ISpeechObjectTokens ISpeechObjectTokens;

#endif 	/* __ISpeechObjectTokens_FWD_DEFINED__ */


#ifndef __ISpeechObjectTokenCategory_FWD_DEFINED__
#define __ISpeechObjectTokenCategory_FWD_DEFINED__
typedef interface ISpeechObjectTokenCategory ISpeechObjectTokenCategory;

#endif 	/* __ISpeechObjectTokenCategory_FWD_DEFINED__ */


#ifndef __ISpeechAudioBufferInfo_FWD_DEFINED__
#define __ISpeechAudioBufferInfo_FWD_DEFINED__
typedef interface ISpeechAudioBufferInfo ISpeechAudioBufferInfo;

#endif 	/* __ISpeechAudioBufferInfo_FWD_DEFINED__ */


#ifndef __ISpeechAudioStatus_FWD_DEFINED__
#define __ISpeechAudioStatus_FWD_DEFINED__
typedef interface ISpeechAudioStatus ISpeechAudioStatus;

#endif 	/* __ISpeechAudioStatus_FWD_DEFINED__ */


#ifndef __ISpeechAudioFormat_FWD_DEFINED__
#define __ISpeechAudioFormat_FWD_DEFINED__
typedef interface ISpeechAudioFormat ISpeechAudioFormat;

#endif 	/* __ISpeechAudioFormat_FWD_DEFINED__ */


#ifndef __ISpeechWaveFormatEx_FWD_DEFINED__
#define __ISpeechWaveFormatEx_FWD_DEFINED__
typedef interface ISpeechWaveFormatEx ISpeechWaveFormatEx;

#endif 	/* __ISpeechWaveFormatEx_FWD_DEFINED__ */


#ifndef __ISpeechBaseStream_FWD_DEFINED__
#define __ISpeechBaseStream_FWD_DEFINED__
typedef interface ISpeechBaseStream ISpeechBaseStream;

#endif 	/* __ISpeechBaseStream_FWD_DEFINED__ */


#ifndef __ISpeechFileStream_FWD_DEFINED__
#define __ISpeechFileStream_FWD_DEFINED__
typedef interface ISpeechFileStream ISpeechFileStream;

#endif 	/* __ISpeechFileStream_FWD_DEFINED__ */


#ifndef __ISpeechMemoryStream_FWD_DEFINED__
#define __ISpeechMemoryStream_FWD_DEFINED__
typedef interface ISpeechMemoryStream ISpeechMemoryStream;

#endif 	/* __ISpeechMemoryStream_FWD_DEFINED__ */


#ifndef __ISpeechCustomStream_FWD_DEFINED__
#define __ISpeechCustomStream_FWD_DEFINED__
typedef interface ISpeechCustomStream ISpeechCustomStream;

#endif 	/* __ISpeechCustomStream_FWD_DEFINED__ */


#ifndef __ISpeechAudio_FWD_DEFINED__
#define __ISpeechAudio_FWD_DEFINED__
typedef interface ISpeechAudio ISpeechAudio;

#endif 	/* __ISpeechAudio_FWD_DEFINED__ */


#ifndef __ISpeechMMSysAudio_FWD_DEFINED__
#define __ISpeechMMSysAudio_FWD_DEFINED__
typedef interface ISpeechMMSysAudio ISpeechMMSysAudio;

#endif 	/* __ISpeechMMSysAudio_FWD_DEFINED__ */


#ifndef __ISpeechVoice_FWD_DEFINED__
#define __ISpeechVoice_FWD_DEFINED__
typedef interface ISpeechVoice ISpeechVoice;

#endif 	/* __ISpeechVoice_FWD_DEFINED__ */


#ifndef __ISpeechVoiceStatus_FWD_DEFINED__
#define __ISpeechVoiceStatus_FWD_DEFINED__
typedef interface ISpeechVoiceStatus ISpeechVoiceStatus;

#endif 	/* __ISpeechVoiceStatus_FWD_DEFINED__ */


#ifndef ___ISpeechVoiceEvents_FWD_DEFINED__
#define ___ISpeechVoiceEvents_FWD_DEFINED__
typedef interface _ISpeechVoiceEvents _ISpeechVoiceEvents;

#endif 	/* ___ISpeechVoiceEvents_FWD_DEFINED__ */


#ifndef __ISpeechRecognizer_FWD_DEFINED__
#define __ISpeechRecognizer_FWD_DEFINED__
typedef interface ISpeechRecognizer ISpeechRecognizer;

#endif 	/* __ISpeechRecognizer_FWD_DEFINED__ */


#ifndef __ISpeechRecognizerStatus_FWD_DEFINED__
#define __ISpeechRecognizerStatus_FWD_DEFINED__
typedef interface ISpeechRecognizerStatus ISpeechRecognizerStatus;

#endif 	/* __ISpeechRecognizerStatus_FWD_DEFINED__ */


#ifndef __ISpeechRecoContext_FWD_DEFINED__
#define __ISpeechRecoContext_FWD_DEFINED__
typedef interface ISpeechRecoContext ISpeechRecoContext;

#endif 	/* __ISpeechRecoContext_FWD_DEFINED__ */


#ifndef __ISpeechRecoGrammar_FWD_DEFINED__
#define __ISpeechRecoGrammar_FWD_DEFINED__
typedef interface ISpeechRecoGrammar ISpeechRecoGrammar;

#endif 	/* __ISpeechRecoGrammar_FWD_DEFINED__ */


#ifndef ___ISpeechRecoContextEvents_FWD_DEFINED__
#define ___ISpeechRecoContextEvents_FWD_DEFINED__
typedef interface _ISpeechRecoContextEvents _ISpeechRecoContextEvents;

#endif 	/* ___ISpeechRecoContextEvents_FWD_DEFINED__ */


#ifndef __ISpeechGrammarRule_FWD_DEFINED__
#define __ISpeechGrammarRule_FWD_DEFINED__
typedef interface ISpeechGrammarRule ISpeechGrammarRule;

#endif 	/* __ISpeechGrammarRule_FWD_DEFINED__ */


#ifndef __ISpeechGrammarRules_FWD_DEFINED__
#define __ISpeechGrammarRules_FWD_DEFINED__
typedef interface ISpeechGrammarRules ISpeechGrammarRules;

#endif 	/* __ISpeechGrammarRules_FWD_DEFINED__ */


#ifndef __ISpeechGrammarRuleState_FWD_DEFINED__
#define __ISpeechGrammarRuleState_FWD_DEFINED__
typedef interface ISpeechGrammarRuleState ISpeechGrammarRuleState;

#endif 	/* __ISpeechGrammarRuleState_FWD_DEFINED__ */


#ifndef __ISpeechGrammarRuleStateTransition_FWD_DEFINED__
#define __ISpeechGrammarRuleStateTransition_FWD_DEFINED__
typedef interface ISpeechGrammarRuleStateTransition ISpeechGrammarRuleStateTransition;

#endif 	/* __ISpeechGrammarRuleStateTransition_FWD_DEFINED__ */


#ifndef __ISpeechGrammarRuleStateTransitions_FWD_DEFINED__
#define __ISpeechGrammarRuleStateTransitions_FWD_DEFINED__
typedef interface ISpeechGrammarRuleStateTransitions ISpeechGrammarRuleStateTransitions;

#endif 	/* __ISpeechGrammarRuleStateTransitions_FWD_DEFINED__ */


#ifndef __ISpeechTextSelectionInformation_FWD_DEFINED__
#define __ISpeechTextSelectionInformation_FWD_DEFINED__
typedef interface ISpeechTextSelectionInformation ISpeechTextSelectionInformation;

#endif 	/* __ISpeechTextSelectionInformation_FWD_DEFINED__ */


#ifndef __ISpeechRecoResult_FWD_DEFINED__
#define __ISpeechRecoResult_FWD_DEFINED__
typedef interface ISpeechRecoResult ISpeechRecoResult;

#endif 	/* __ISpeechRecoResult_FWD_DEFINED__ */


#ifndef __ISpeechRecoResultTimes_FWD_DEFINED__
#define __ISpeechRecoResultTimes_FWD_DEFINED__
typedef interface ISpeechRecoResultTimes ISpeechRecoResultTimes;

#endif 	/* __ISpeechRecoResultTimes_FWD_DEFINED__ */


#ifndef __ISpeechPhraseAlternate_FWD_DEFINED__
#define __ISpeechPhraseAlternate_FWD_DEFINED__
typedef interface ISpeechPhraseAlternate ISpeechPhraseAlternate;

#endif 	/* __ISpeechPhraseAlternate_FWD_DEFINED__ */


#ifndef __ISpeechPhraseAlternates_FWD_DEFINED__
#define __ISpeechPhraseAlternates_FWD_DEFINED__
typedef interface ISpeechPhraseAlternates ISpeechPhraseAlternates;

#endif 	/* __ISpeechPhraseAlternates_FWD_DEFINED__ */


#ifndef __ISpeechPhraseInfo_FWD_DEFINED__
#define __ISpeechPhraseInfo_FWD_DEFINED__
typedef interface ISpeechPhraseInfo ISpeechPhraseInfo;

#endif 	/* __ISpeechPhraseInfo_FWD_DEFINED__ */


#ifndef __ISpeechPhraseElement_FWD_DEFINED__
#define __ISpeechPhraseElement_FWD_DEFINED__
typedef interface ISpeechPhraseElement ISpeechPhraseElement;

#endif 	/* __ISpeechPhraseElement_FWD_DEFINED__ */


#ifndef __ISpeechPhraseElements_FWD_DEFINED__
#define __ISpeechPhraseElements_FWD_DEFINED__
typedef interface ISpeechPhraseElements ISpeechPhraseElements;

#endif 	/* __ISpeechPhraseElements_FWD_DEFINED__ */


#ifndef __ISpeechPhraseReplacement_FWD_DEFINED__
#define __ISpeechPhraseReplacement_FWD_DEFINED__
typedef interface ISpeechPhraseReplacement ISpeechPhraseReplacement;

#endif 	/* __ISpeechPhraseReplacement_FWD_DEFINED__ */


#ifndef __ISpeechPhraseReplacements_FWD_DEFINED__
#define __ISpeechPhraseReplacements_FWD_DEFINED__
typedef interface ISpeechPhraseReplacements ISpeechPhraseReplacements;

#endif 	/* __ISpeechPhraseReplacements_FWD_DEFINED__ */


#ifndef __ISpeechPhraseProperty_FWD_DEFINED__
#define __ISpeechPhraseProperty_FWD_DEFINED__
typedef interface ISpeechPhraseProperty ISpeechPhraseProperty;

#endif 	/* __ISpeechPhraseProperty_FWD_DEFINED__ */


#ifndef __ISpeechPhraseProperties_FWD_DEFINED__
#define __ISpeechPhraseProperties_FWD_DEFINED__
typedef interface ISpeechPhraseProperties ISpeechPhraseProperties;

#endif 	/* __ISpeechPhraseProperties_FWD_DEFINED__ */


#ifndef __ISpeechPhraseRule_FWD_DEFINED__
#define __ISpeechPhraseRule_FWD_DEFINED__
typedef interface ISpeechPhraseRule ISpeechPhraseRule;

#endif 	/* __ISpeechPhraseRule_FWD_DEFINED__ */


#ifndef __ISpeechPhraseRules_FWD_DEFINED__
#define __ISpeechPhraseRules_FWD_DEFINED__
typedef interface ISpeechPhraseRules ISpeechPhraseRules;

#endif 	/* __ISpeechPhraseRules_FWD_DEFINED__ */


#ifndef __ISpeechLexicon_FWD_DEFINED__
#define __ISpeechLexicon_FWD_DEFINED__
typedef interface ISpeechLexicon ISpeechLexicon;

#endif 	/* __ISpeechLexicon_FWD_DEFINED__ */


#ifndef __ISpeechLexiconWords_FWD_DEFINED__
#define __ISpeechLexiconWords_FWD_DEFINED__
typedef interface ISpeechLexiconWords ISpeechLexiconWords;

#endif 	/* __ISpeechLexiconWords_FWD_DEFINED__ */


#ifndef __ISpeechLexiconWord_FWD_DEFINED__
#define __ISpeechLexiconWord_FWD_DEFINED__
typedef interface ISpeechLexiconWord ISpeechLexiconWord;

#endif 	/* __ISpeechLexiconWord_FWD_DEFINED__ */


#ifndef __ISpeechLexiconPronunciations_FWD_DEFINED__
#define __ISpeechLexiconPronunciations_FWD_DEFINED__
typedef interface ISpeechLexiconPronunciations ISpeechLexiconPronunciations;

#endif 	/* __ISpeechLexiconPronunciations_FWD_DEFINED__ */


#ifndef __ISpeechLexiconPronunciation_FWD_DEFINED__
#define __ISpeechLexiconPronunciation_FWD_DEFINED__
typedef interface ISpeechLexiconPronunciation ISpeechLexiconPronunciation;

#endif 	/* __ISpeechLexiconPronunciation_FWD_DEFINED__ */


#ifndef __ISpeechPhraseInfoBuilder_FWD_DEFINED__
#define __ISpeechPhraseInfoBuilder_FWD_DEFINED__
typedef interface ISpeechPhraseInfoBuilder ISpeechPhraseInfoBuilder;

#endif 	/* __ISpeechPhraseInfoBuilder_FWD_DEFINED__ */


#ifndef __ISpeechPhoneConverter_FWD_DEFINED__
#define __ISpeechPhoneConverter_FWD_DEFINED__
typedef interface ISpeechPhoneConverter ISpeechPhoneConverter;

#endif 	/* __ISpeechPhoneConverter_FWD_DEFINED__ */


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


#ifndef __SpPhoneConverter_FWD_DEFINED__
#define __SpPhoneConverter_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpPhoneConverter SpPhoneConverter;
#else
typedef struct SpPhoneConverter SpPhoneConverter;
#endif /* __cplusplus */

#endif 	/* __SpPhoneConverter_FWD_DEFINED__ */


#ifndef __SpNullPhoneConverter_FWD_DEFINED__
#define __SpNullPhoneConverter_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpNullPhoneConverter SpNullPhoneConverter;
#else
typedef struct SpNullPhoneConverter SpNullPhoneConverter;
#endif /* __cplusplus */

#endif 	/* __SpNullPhoneConverter_FWD_DEFINED__ */


#ifndef __SpTextSelectionInformation_FWD_DEFINED__
#define __SpTextSelectionInformation_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpTextSelectionInformation SpTextSelectionInformation;
#else
typedef struct SpTextSelectionInformation SpTextSelectionInformation;
#endif /* __cplusplus */

#endif 	/* __SpTextSelectionInformation_FWD_DEFINED__ */


#ifndef __SpPhraseInfoBuilder_FWD_DEFINED__
#define __SpPhraseInfoBuilder_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpPhraseInfoBuilder SpPhraseInfoBuilder;
#else
typedef struct SpPhraseInfoBuilder SpPhraseInfoBuilder;
#endif /* __cplusplus */

#endif 	/* __SpPhraseInfoBuilder_FWD_DEFINED__ */


#ifndef __SpAudioFormat_FWD_DEFINED__
#define __SpAudioFormat_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpAudioFormat SpAudioFormat;
#else
typedef struct SpAudioFormat SpAudioFormat;
#endif /* __cplusplus */

#endif 	/* __SpAudioFormat_FWD_DEFINED__ */


#ifndef __SpWaveFormatEx_FWD_DEFINED__
#define __SpWaveFormatEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpWaveFormatEx SpWaveFormatEx;
#else
typedef struct SpWaveFormatEx SpWaveFormatEx;
#endif /* __cplusplus */

#endif 	/* __SpWaveFormatEx_FWD_DEFINED__ */


#ifndef __SpInProcRecoContext_FWD_DEFINED__
#define __SpInProcRecoContext_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpInProcRecoContext SpInProcRecoContext;
#else
typedef struct SpInProcRecoContext SpInProcRecoContext;
#endif /* __cplusplus */

#endif 	/* __SpInProcRecoContext_FWD_DEFINED__ */


#ifndef __SpCustomStream_FWD_DEFINED__
#define __SpCustomStream_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpCustomStream SpCustomStream;
#else
typedef struct SpCustomStream SpCustomStream;
#endif /* __cplusplus */

#endif 	/* __SpCustomStream_FWD_DEFINED__ */


#ifndef __SpFileStream_FWD_DEFINED__
#define __SpFileStream_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpFileStream SpFileStream;
#else
typedef struct SpFileStream SpFileStream;
#endif /* __cplusplus */

#endif 	/* __SpFileStream_FWD_DEFINED__ */


#ifndef __SpMemoryStream_FWD_DEFINED__
#define __SpMemoryStream_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpMemoryStream SpMemoryStream;
#else
typedef struct SpMemoryStream SpMemoryStream;
#endif /* __cplusplus */

#endif 	/* __SpMemoryStream_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_sapi51_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
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
#define SPTOKENVALUE_CLSID L"CLSID"
#define SPTOKENKEY_FILES L"Files"
#define SPTOKENKEY_UI L"UI"
#define SPTOKENKEY_ATTRIBUTES L"Attributes"
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
#define	SP_LOW_CONFIDENCE	( -1 )

#define	SP_NORMAL_CONFIDENCE	( 0 )

#define	SP_HIGH_CONFIDENCE	( +1 )

#define	DEFAULT_WEIGHT	( 1 )

#define	SP_MAX_WORD_LENGTH	( 128 )

#define	SP_MAX_PRON_LENGTH	( 384 )

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


extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0000_v0_0_s_ifspec;

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
            /* [in] */ __RPC__in_opt ISpNotifySink *pNotifySink) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetNotifyWindowMessage( 
            /* [in] */ HWND hWnd,
            /* [in] */ UINT Msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetNotifyCallbackFunction( 
            /* [in] */ SPNOTIFYCALLBACK *pfnCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetNotifyCallbackInterface( 
            /* [in] */ ISpNotifyCallback *pSpCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetNotifyWin32Event( void) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE WaitForNotifyEvent( 
            /* [in] */ DWORD dwMilliseconds) = 0;
        
        virtual /* [local] */ HANDLE STDMETHODCALLTYPE GetNotifyEventHandle( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpNotifySourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpNotifySource * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpNotifySource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpNotifySource * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetNotifySink )( 
            __RPC__in ISpNotifySource * This,
            /* [in] */ __RPC__in_opt ISpNotifySink *pNotifySink);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWindowMessage )( 
            ISpNotifySource * This,
            /* [in] */ HWND hWnd,
            /* [in] */ UINT Msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackFunction )( 
            ISpNotifySource * This,
            /* [in] */ SPNOTIFYCALLBACK *pfnCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackInterface )( 
            ISpNotifySource * This,
            /* [in] */ ISpNotifyCallback *pSpCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWin32Event )( 
            ISpNotifySource * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *WaitForNotifyEvent )( 
            ISpNotifySource * This,
            /* [in] */ DWORD dwMilliseconds);
        
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
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpNotifySink * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpNotifySink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpNotifySink * This);
        
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
            /* [in] */ HWND hWnd,
            /* [in] */ UINT Msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitCallback( 
            /* [in] */ SPNOTIFYCALLBACK *pfnCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitSpNotifyCallback( 
            /* [in] */ ISpNotifyCallback *pSpCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitWin32Event( 
            /* [in] */ HANDLE hEvent,
            /* [in] */ BOOL fCloseHandleOnRelease) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Wait( 
            /* [in] */ DWORD dwMilliseconds) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE GetEventHandle( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpNotifyTranslatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpNotifyTranslator * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpNotifyTranslator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpNotifyTranslator * This);
        
        HRESULT ( STDMETHODCALLTYPE *Notify )( 
            ISpNotifyTranslator * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitWindowMessage )( 
            ISpNotifyTranslator * This,
            /* [in] */ HWND hWnd,
            /* [in] */ UINT Msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE *InitCallback )( 
            ISpNotifyTranslator * This,
            /* [in] */ SPNOTIFYCALLBACK *pfnCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE *InitSpNotifyCallback )( 
            ISpNotifyTranslator * This,
            /* [in] */ ISpNotifyCallback *pSpCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE *InitWin32Event )( 
            ISpNotifyTranslator * This,
            /* [in] */ HANDLE hEvent,
            /* [in] */ BOOL fCloseHandleOnRelease);
        
        HRESULT ( STDMETHODCALLTYPE *Wait )( 
            ISpNotifyTranslator * This,
            /* [in] */ DWORD dwMilliseconds);
        
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
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ ULONG cbData,
            /* [in] */ const BYTE *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetData( 
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ ULONG *pcbData,
            /* [out] */ BYTE *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStringValue( 
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [in] */ LPCWSTR pszValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringValue( 
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDWORD( 
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ DWORD dwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDWORD( 
            /* [in] */ LPCWSTR pszValueName,
            /* [out] */ DWORD *pdwValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenKey( 
            /* [in] */ LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateKey( 
            /* [in] */ LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteKey( 
            /* [in] */ LPCWSTR pszSubKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteValue( 
            /* [in] */ LPCWSTR pszValueName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumKeys( 
            /* [in] */ ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumValues( 
            /* [in] */ ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValueName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpDataKeyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpDataKey * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpDataKey * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpDataKey * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            ISpDataKey * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ ULONG cbData,
            /* [in] */ const BYTE *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            ISpDataKey * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ ULONG *pcbData,
            /* [out] */ BYTE *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            ISpDataKey * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [in] */ LPCWSTR pszValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            ISpDataKey * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetDWORD )( 
            ISpDataKey * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetDWORD )( 
            ISpDataKey * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [out] */ DWORD *pdwValue);
        
        HRESULT ( STDMETHODCALLTYPE *OpenKey )( 
            ISpDataKey * This,
            /* [in] */ LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *CreateKey )( 
            ISpDataKey * This,
            /* [in] */ LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            ISpDataKey * This,
            /* [in] */ LPCWSTR pszSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteValue )( 
            ISpDataKey * This,
            /* [in] */ LPCWSTR pszValueName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            ISpDataKey * This,
            /* [in] */ ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            ISpDataKey * This,
            /* [in] */ ULONG Index,
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
            /* [in] */ HKEY hkey,
            /* [in] */ BOOL fReadOnly) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRegDataKeyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpRegDataKey * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpRegDataKey * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpRegDataKey * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            __RPC__in ISpRegDataKey * This,
            /* [in] */ __RPC__in LPCWSTR pszValueName,
            /* [in] */ ULONG cbData,
            /* [in] */ __RPC__in const BYTE *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            __RPC__in ISpRegDataKey * This,
            /* [in] */ __RPC__in LPCWSTR pszValueName,
            /* [in] */ __RPC__in ULONG *pcbData,
            /* [out] */ __RPC__out BYTE *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            __RPC__in ISpRegDataKey * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [in] */ __RPC__in LPCWSTR pszValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            __RPC__in ISpRegDataKey * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetDWORD )( 
            __RPC__in ISpRegDataKey * This,
            /* [in] */ __RPC__in LPCWSTR pszValueName,
            /* [in] */ DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetDWORD )( 
            __RPC__in ISpRegDataKey * This,
            /* [in] */ __RPC__in LPCWSTR pszValueName,
            /* [out] */ __RPC__out DWORD *pdwValue);
        
        HRESULT ( STDMETHODCALLTYPE *OpenKey )( 
            __RPC__in ISpRegDataKey * This,
            /* [in] */ __RPC__in LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *CreateKey )( 
            __RPC__in ISpRegDataKey * This,
            /* [in] */ __RPC__in LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            __RPC__in ISpRegDataKey * This,
            /* [in] */ __RPC__in LPCWSTR pszSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteValue )( 
            __RPC__in ISpRegDataKey * This,
            /* [in] */ __RPC__in LPCWSTR pszValueName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            __RPC__in ISpRegDataKey * This,
            /* [in] */ ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            __RPC__in ISpRegDataKey * This,
            /* [in] */ ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValueName);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetKey )( 
            ISpRegDataKey * This,
            /* [in] */ HKEY hkey,
            /* [in] */ BOOL fReadOnly);
        
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
            /* [in] */ LPCWSTR pszCategoryId,
            /* [in] */ BOOL fCreateIfNotExist) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetId( 
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemCategoryId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDataKey( 
            /* [in] */ SPDATAKEYLOCATION spdkl,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppDataKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumTokens( 
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pzsReqAttribs,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszOptAttribs,
            /* [out] */ IEnumSpObjectTokens **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultTokenId( 
            /* [in] */ LPCWSTR pszTokenId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultTokenId( 
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemTokenId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpObjectTokenCategoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpObjectTokenCategory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpObjectTokenCategory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpObjectTokenCategory * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            ISpObjectTokenCategory * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ ULONG cbData,
            /* [in] */ const BYTE *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            ISpObjectTokenCategory * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ ULONG *pcbData,
            /* [out] */ BYTE *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            ISpObjectTokenCategory * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [in] */ LPCWSTR pszValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            ISpObjectTokenCategory * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetDWORD )( 
            ISpObjectTokenCategory * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetDWORD )( 
            ISpObjectTokenCategory * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [out] */ DWORD *pdwValue);
        
        HRESULT ( STDMETHODCALLTYPE *OpenKey )( 
            ISpObjectTokenCategory * This,
            /* [in] */ LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *CreateKey )( 
            ISpObjectTokenCategory * This,
            /* [in] */ LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            ISpObjectTokenCategory * This,
            /* [in] */ LPCWSTR pszSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteValue )( 
            ISpObjectTokenCategory * This,
            /* [in] */ LPCWSTR pszValueName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            ISpObjectTokenCategory * This,
            /* [in] */ ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            ISpObjectTokenCategory * This,
            /* [in] */ ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValueName);
        
        HRESULT ( STDMETHODCALLTYPE *SetId )( 
            ISpObjectTokenCategory * This,
            /* [in] */ LPCWSTR pszCategoryId,
            /* [in] */ BOOL fCreateIfNotExist);
        
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            ISpObjectTokenCategory * This,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemCategoryId);
        
        HRESULT ( STDMETHODCALLTYPE *GetDataKey )( 
            ISpObjectTokenCategory * This,
            /* [in] */ SPDATAKEYLOCATION spdkl,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppDataKey);
        
        HRESULT ( STDMETHODCALLTYPE *EnumTokens )( 
            ISpObjectTokenCategory * This,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pzsReqAttribs,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszOptAttribs,
            /* [out] */ IEnumSpObjectTokens **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *SetDefaultTokenId )( 
            ISpObjectTokenCategory * This,
            /* [in] */ LPCWSTR pszTokenId);
        
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
            /* [in] */ LPCWSTR pszTokenId,
            /* [in] */ BOOL fCreateIfNotExist) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetId( 
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemTokenId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCategory( 
            /* [out][annotation] */ 
            _Outptr_  ISpObjectTokenCategory **ppTokenCategory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateInstance( 
            /* [in] */ IUnknown *pUnkOuter,
            /* [in] */ DWORD dwClsContext,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStorageFileName( 
            /* [in] */ REFCLSID clsidCaller,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszFileNameSpecifier,
            /* [in] */ ULONG nFolder,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszFilePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveStorageFileName( 
            /* [in] */ REFCLSID clsidCaller,
            /* [in][annotation] */ 
            _In_  LPCWSTR pszKeyName,
            /* [in] */ BOOL fDeleteFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( 
            /* [annotation] */ 
            _In_opt_  const CLSID *pclsidCaller) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ IUnknown *punkObject,
            /* [out] */ BOOL *pfSupported) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [in] */ HWND hwndParent,
            /* [in] */ LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ IUnknown *punkObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MatchesAttributes( 
            /* [in] */ LPCWSTR pszAttributes,
            /* [out] */ BOOL *pfMatches) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpObjectTokenVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpObjectToken * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpObjectToken * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpObjectToken * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            ISpObjectToken * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ ULONG cbData,
            /* [in] */ const BYTE *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            ISpObjectToken * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ ULONG *pcbData,
            /* [out] */ BYTE *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            ISpObjectToken * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [in] */ LPCWSTR pszValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            ISpObjectToken * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetDWORD )( 
            ISpObjectToken * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [in] */ DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetDWORD )( 
            ISpObjectToken * This,
            /* [in] */ LPCWSTR pszValueName,
            /* [out] */ DWORD *pdwValue);
        
        HRESULT ( STDMETHODCALLTYPE *OpenKey )( 
            ISpObjectToken * This,
            /* [in] */ LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *CreateKey )( 
            ISpObjectToken * This,
            /* [in] */ LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            ISpObjectToken * This,
            /* [in] */ LPCWSTR pszSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteValue )( 
            ISpObjectToken * This,
            /* [in] */ LPCWSTR pszValueName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            ISpObjectToken * This,
            /* [in] */ ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            ISpObjectToken * This,
            /* [in] */ ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValueName);
        
        HRESULT ( STDMETHODCALLTYPE *SetId )( 
            ISpObjectToken * This,
            /* [annotation] */ 
            _In_opt_  LPCWSTR pszCategoryId,
            /* [in] */ LPCWSTR pszTokenId,
            /* [in] */ BOOL fCreateIfNotExist);
        
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            ISpObjectToken * This,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemTokenId);
        
        HRESULT ( STDMETHODCALLTYPE *GetCategory )( 
            ISpObjectToken * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectTokenCategory **ppTokenCategory);
        
        HRESULT ( STDMETHODCALLTYPE *CreateInstance )( 
            ISpObjectToken * This,
            /* [in] */ IUnknown *pUnkOuter,
            /* [in] */ DWORD dwClsContext,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetStorageFileName )( 
            ISpObjectToken * This,
            /* [in] */ REFCLSID clsidCaller,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszFileNameSpecifier,
            /* [in] */ ULONG nFolder,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszFilePath);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveStorageFileName )( 
            ISpObjectToken * This,
            /* [in] */ REFCLSID clsidCaller,
            /* [in][annotation] */ 
            _In_  LPCWSTR pszKeyName,
            /* [in] */ BOOL fDeleteFile);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            ISpObjectToken * This,
            /* [annotation] */ 
            _In_opt_  const CLSID *pclsidCaller);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            ISpObjectToken * This,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ IUnknown *punkObject,
            /* [out] */ BOOL *pfSupported);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            ISpObjectToken * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ IUnknown *punkObject);
        
        HRESULT ( STDMETHODCALLTYPE *MatchesAttributes )( 
            ISpObjectToken * This,
            /* [in] */ LPCWSTR pszAttributes,
            /* [out] */ BOOL *pfMatches);
        
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
            /* [in] */ __RPC__in LPCWSTR pszCategoryId,
            /* [in] */ __RPC__in LPCWSTR pszTokenId,
            /* [in] */ __RPC__in_opt ISpDataKey *pDataKey) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpObjectTokenInitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpObjectTokenInit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpObjectTokenInit * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetData )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in LPCWSTR pszValueName,
            /* [in] */ ULONG cbData,
            /* [in] */ __RPC__in const BYTE *pData);
        
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in LPCWSTR pszValueName,
            /* [in] */ __RPC__in ULONG *pcbData,
            /* [out] */ __RPC__out BYTE *pData);
        
        HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [in] */ __RPC__in LPCWSTR pszValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszValueName,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetDWORD )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in LPCWSTR pszValueName,
            /* [in] */ DWORD dwValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetDWORD )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in LPCWSTR pszValueName,
            /* [out] */ __RPC__out DWORD *pdwValue);
        
        HRESULT ( STDMETHODCALLTYPE *OpenKey )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in LPCWSTR pszSubKeyName,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *CreateKey )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in LPCWSTR pszSubKey,
            /* [out][annotation] */ 
            _Outptr_  ISpDataKey **ppSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in LPCWSTR pszSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteValue )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in LPCWSTR pszValueName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszSubKeyName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ ULONG Index,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszValueName);
        
        HRESULT ( STDMETHODCALLTYPE *SetId )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation] */ 
            _In_opt_  LPCWSTR pszCategoryId,
            /* [in] */ __RPC__in LPCWSTR pszTokenId,
            /* [in] */ BOOL fCreateIfNotExist);
        
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemTokenId);
        
        HRESULT ( STDMETHODCALLTYPE *GetCategory )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectTokenCategory **ppTokenCategory);
        
        HRESULT ( STDMETHODCALLTYPE *CreateInstance )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in_opt IUnknown *pUnkOuter,
            /* [in] */ DWORD dwClsContext,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppvObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetStorageFileName )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in REFCLSID clsidCaller,
            /* [annotation][in] */ 
            _In_  LPCWSTR pszValueName,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszFileNameSpecifier,
            /* [in] */ ULONG nFolder,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszFilePath);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveStorageFileName )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in REFCLSID clsidCaller,
            /* [in][annotation] */ 
            _In_  LPCWSTR pszKeyName,
            /* [in] */ BOOL fDeleteFile);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [annotation] */ 
            _In_opt_  const CLSID *pclsidCaller);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            ISpObjectTokenInit * This,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ IUnknown *punkObject,
            /* [out] */ BOOL *pfSupported);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            ISpObjectTokenInit * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [in] */ IUnknown *punkObject);
        
        HRESULT ( STDMETHODCALLTYPE *MatchesAttributes )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in LPCWSTR pszAttributes,
            /* [out] */ __RPC__out BOOL *pfMatches);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromDataKey )( 
            __RPC__in ISpObjectTokenInit * This,
            /* [in] */ __RPC__in LPCWSTR pszCategoryId,
            /* [in] */ __RPC__in LPCWSTR pszTokenId,
            /* [in] */ __RPC__in_opt ISpDataKey *pDataKey);
        
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
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ ISpObjectToken **pelt,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumSpObjectTokens **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ ULONG Index,
            /* [out] */ ISpObjectToken **ppToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumSpObjectTokensVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumSpObjectTokens * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumSpObjectTokens * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumSpObjectTokens * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumSpObjectTokens * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ ISpObjectToken **pelt,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumSpObjectTokens * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumSpObjectTokens * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumSpObjectTokens * This,
            /* [out] */ IEnumSpObjectTokens **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            IEnumSpObjectTokens * This,
            /* [in] */ ULONG Index,
            /* [out] */ ISpObjectToken **ppToken);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumSpObjectTokens * This,
            /* [out] */ ULONG *pCount);
        
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
            /* [in] */ __RPC__in_opt ISpObjectToken *pToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectToken( 
            /* [out] */ __RPC__deref_out_opt ISpObjectToken **ppToken) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpObjectWithTokenVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpObjectWithToken * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpObjectWithToken * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpObjectWithToken * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetObjectToken )( 
            __RPC__in ISpObjectWithToken * This,
            /* [in] */ __RPC__in_opt ISpObjectToken *pToken);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectToken )( 
            __RPC__in ISpObjectWithToken * This,
            /* [out] */ __RPC__deref_out_opt ISpObjectToken **ppToken);
        
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
            /* [in] */ __RPC__in REFGUID guidServiceId,
            /* [in] */ __RPC__in_opt IUnknown *pUnkObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObject( 
            /* [in] */ __RPC__in REFGUID guidServiceId,
            /* [in] */ __RPC__in REFCLSID ObjectCLSID,
            /* [in] */ __RPC__in REFIID ObjectIID,
            /* [in] */ BOOL fReleaseWhenLastExternalRefReleased,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpResourceManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpResourceManager * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpResourceManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpResourceManager * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *QueryService )( 
            ISpResourceManager * This,
            /* [annotation][in] */ 
            _In_  REFGUID guidService,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][out] */ 
            _Outptr_  void **ppvObject);
        
        HRESULT ( STDMETHODCALLTYPE *SetObject )( 
            __RPC__in ISpResourceManager * This,
            /* [in] */ __RPC__in REFGUID guidServiceId,
            /* [in] */ __RPC__in_opt IUnknown *pUnkObject);
        
        HRESULT ( STDMETHODCALLTYPE *GetObject )( 
            __RPC__in ISpResourceManager * This,
            /* [in] */ __RPC__in REFGUID guidServiceId,
            /* [in] */ __RPC__in REFCLSID ObjectCLSID,
            /* [in] */ __RPC__in REFIID ObjectIID,
            /* [in] */ BOOL fReleaseWhenLastExternalRefReleased,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppObject);
        
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


/* interface __MIDL_itf_sapi51_0000_0011 */
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
        SPEI_SR_PRIVATE	= 52,
        SPEI_MIN_SR	= 34,
        SPEI_MAX_SR	= 52,
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
        SPESF_STREAM_RELEASED	= ( 1 << 0 ) 
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



extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0011_v0_0_s_ifspec;

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
            /* [in] */ ULONGLONG ullEventInterest,
            /* [in] */ ULONGLONG ullQueuedInterest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEvents( 
            /* [in] */ ULONG ulCount,
            /* [size_is][out] */ SPEVENT *pEventArray,
            /* [out] */ ULONG *pulFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInfo( 
            /* [out] */ SPEVENTSOURCEINFO *pInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpEventSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpEventSource * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpEventSource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpEventSource * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetNotifySink )( 
            ISpEventSource * This,
            /* [in] */ ISpNotifySink *pNotifySink);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWindowMessage )( 
            ISpEventSource * This,
            /* [in] */ HWND hWnd,
            /* [in] */ UINT Msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackFunction )( 
            ISpEventSource * This,
            /* [in] */ SPNOTIFYCALLBACK *pfnCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackInterface )( 
            ISpEventSource * This,
            /* [in] */ ISpNotifyCallback *pSpCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWin32Event )( 
            ISpEventSource * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *WaitForNotifyEvent )( 
            ISpEventSource * This,
            /* [in] */ DWORD dwMilliseconds);
        
        /* [local] */ HANDLE ( STDMETHODCALLTYPE *GetNotifyEventHandle )( 
            ISpEventSource * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetInterest )( 
            ISpEventSource * This,
            /* [in] */ ULONGLONG ullEventInterest,
            /* [in] */ ULONGLONG ullQueuedInterest);
        
        HRESULT ( STDMETHODCALLTYPE *GetEvents )( 
            ISpEventSource * This,
            /* [in] */ ULONG ulCount,
            /* [size_is][out] */ SPEVENT *pEventArray,
            /* [out] */ ULONG *pulFetched);
        
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            ISpEventSource * This,
            /* [out] */ SPEVENTSOURCEINFO *pInfo);
        
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
            /* [in] */ const SPEVENT *pEventArray,
            /* [in] */ ULONG ulCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEventInterest( 
            /* [out] */ ULONGLONG *pullEventInterest) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpEventSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpEventSink * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpEventSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpEventSink * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddEvents )( 
            ISpEventSink * This,
            /* [in] */ const SPEVENT *pEventArray,
            /* [in] */ ULONG ulCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventInterest )( 
            ISpEventSink * This,
            /* [out] */ ULONGLONG *pullEventInterest);
        
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
            /* [in] */ __RPC__in GUID *pguidFormatId,
            /* [out] */ __RPC__deref_out_opt WAVEFORMATEX **ppCoMemWaveFormatEx) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpStreamFormatVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpStreamFormat * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpStreamFormat * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpStreamFormat * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpStreamFormat * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpStreamFormat * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            ISpStreamFormat * This,
            /* [in] */ LARGE_INTEGER dlibMove,
            /* [in] */ DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            __RPC__in ISpStreamFormat * This,
            /* [in] */ ULARGE_INTEGER libNewSize);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            ISpStreamFormat * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [in] */ ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in ISpStreamFormat * This,
            /* [in] */ DWORD grfCommitFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            __RPC__in ISpStreamFormat * This);
        
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            __RPC__in ISpStreamFormat * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            __RPC__in ISpStreamFormat * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            __RPC__in ISpStreamFormat * This,
            /* [out] */ __RPC__out STATSTG *pstatstg,
            /* [in] */ DWORD grfStatFlag);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in ISpStreamFormat * This,
            /* [out] */ __RPC__deref_out_opt IStream **ppstm);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            __RPC__in ISpStreamFormat * This,
            /* [in] */ __RPC__in GUID *pguidFormatId,
            /* [out] */ __RPC__deref_out_opt WAVEFORMATEX **ppCoMemWaveFormatEx);
        
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


/* interface __MIDL_itf_sapi51_0000_0014 */
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



extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0014_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0014_v0_0_s_ifspec;

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
            /* [in] */ IStream *pStream,
            /* [in] */ REFGUID rguidFormat,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBaseStream( 
            /* [out][annotation] */ 
            _Outptr_  IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindToFile( 
            /* [in][annotation] */ 
            _In_z_  LPCWSTR pszFileName,
            /* [in] */ SPFILEMODE eMode,
            /* [in][annotation] */ 
            _In_opt_  const GUID *pFormatId,
            /* [annotation] */ 
            _In_opt_  const WAVEFORMATEX *pWaveFormatEx,
            /* [in] */ ULONGLONG ullEventInterest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpStream * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpStream * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpStream * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpStream * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            ISpStream * This,
            /* [in] */ LARGE_INTEGER dlibMove,
            /* [in] */ DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            ISpStream * This,
            /* [in] */ ULARGE_INTEGER libNewSize);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            ISpStream * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [in] */ ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpStream * This,
            /* [in] */ DWORD grfCommitFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            ISpStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            ISpStream * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            ISpStream * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            ISpStream * This,
            /* [out] */ STATSTG *pstatstg,
            /* [in] */ DWORD grfStatFlag);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISpStream * This,
            /* [out] */ IStream **ppstm);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            ISpStream * This,
            /* [in] */ GUID *pguidFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *SetBaseStream )( 
            ISpStream * This,
            /* [in] */ IStream *pStream,
            /* [in] */ REFGUID rguidFormat,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *GetBaseStream )( 
            ISpStream * This,
            /* [out][annotation] */ 
            _Outptr_  IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *BindToFile )( 
            ISpStream * This,
            /* [in][annotation] */ 
            _In_z_  LPCWSTR pszFileName,
            /* [in] */ SPFILEMODE eMode,
            /* [in][annotation] */ 
            _In_opt_  const GUID *pFormatId,
            /* [annotation] */ 
            _In_opt_  const WAVEFORMATEX *pWaveFormatEx,
            /* [in] */ ULONGLONG ullEventInterest);
        
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
            /* [in] */ __RPC__in_opt ISpStreamFormat *pStream,
            /* [in] */ BOOL fSetFormatToBaseStreamFormat,
            /* [in] */ BOOL fWriteToBaseStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBaseStream( 
            /* [out] */ __RPC__deref_out_opt ISpStreamFormat **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFormat( 
            /* [in] */ __RPC__in REFGUID rguidFormatIdOfConvertedStream,
            /* [in] */ __RPC__in const WAVEFORMATEX *pWaveFormatExOfConvertedStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetSeekPosition( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScaleConvertedToBaseOffset( 
            /* [in] */ ULONGLONG ullOffsetConvertedStream,
            /* [out] */ __RPC__out ULONGLONG *pullOffsetBaseStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScaleBaseToConvertedOffset( 
            /* [in] */ ULONGLONG ullOffsetBaseStream,
            /* [out] */ __RPC__out ULONGLONG *pullOffsetConvertedStream) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpStreamFormatConverterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpStreamFormatConverter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpStreamFormatConverter * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpStreamFormatConverter * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpStreamFormatConverter * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            ISpStreamFormatConverter * This,
            /* [in] */ LARGE_INTEGER dlibMove,
            /* [in] */ DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [in] */ ULARGE_INTEGER libNewSize);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            ISpStreamFormatConverter * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [in] */ ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [in] */ DWORD grfCommitFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            __RPC__in ISpStreamFormatConverter * This);
        
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [out] */ __RPC__out STATSTG *pstatstg,
            /* [in] */ DWORD grfStatFlag);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [out] */ __RPC__deref_out_opt IStream **ppstm);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [in] */ __RPC__in GUID *pguidFormatId,
            /* [out] */ __RPC__deref_out_opt WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *SetBaseStream )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [in] */ __RPC__in_opt ISpStreamFormat *pStream,
            /* [in] */ BOOL fSetFormatToBaseStreamFormat,
            /* [in] */ BOOL fWriteToBaseStream);
        
        HRESULT ( STDMETHODCALLTYPE *GetBaseStream )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [out] */ __RPC__deref_out_opt ISpStreamFormat **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *SetFormat )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [in] */ __RPC__in REFGUID rguidFormatIdOfConvertedStream,
            /* [in] */ __RPC__in const WAVEFORMATEX *pWaveFormatExOfConvertedStream);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSeekPosition )( 
            __RPC__in ISpStreamFormatConverter * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScaleConvertedToBaseOffset )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [in] */ ULONGLONG ullOffsetConvertedStream,
            /* [out] */ __RPC__out ULONGLONG *pullOffsetBaseStream);
        
        HRESULT ( STDMETHODCALLTYPE *ScaleBaseToConvertedOffset )( 
            __RPC__in ISpStreamFormatConverter * This,
            /* [in] */ ULONGLONG ullOffsetBaseStream,
            /* [out] */ __RPC__out ULONGLONG *pullOffsetConvertedStream);
        
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


/* interface __MIDL_itf_sapi51_0000_0016 */
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



extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0016_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0016_v0_0_s_ifspec;

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
            /* [in] */ SPAUDIOSTATE NewState,
            /* [in] */ ULONGLONG ullReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFormat( 
            /* [in] */ REFGUID rguidFmtId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ SPAUDIOSTATUS *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferInfo( 
            /* [in] */ const SPAUDIOBUFFERINFO *pBuffInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBufferInfo( 
            /* [out] */ SPAUDIOBUFFERINFO *pBuffInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultFormat( 
            /* [out] */ GUID *pFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemWaveFormatEx) = 0;
        
        virtual HANDLE STDMETHODCALLTYPE EventHandle( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVolumeLevel( 
            /* [out] */ ULONG *pLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVolumeLevel( 
            /* [in] */ ULONG Level) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBufferNotifySize( 
            /* [out] */ ULONG *pcbSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferNotifySize( 
            /* [in] */ ULONG cbSize) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpAudioVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpAudio * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpAudio * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpAudio * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpAudio * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpAudio * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            ISpAudio * This,
            /* [in] */ LARGE_INTEGER dlibMove,
            /* [in] */ DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            ISpAudio * This,
            /* [in] */ ULARGE_INTEGER libNewSize);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            ISpAudio * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [in] */ ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpAudio * This,
            /* [in] */ DWORD grfCommitFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            ISpAudio * This);
        
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            ISpAudio * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            ISpAudio * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            ISpAudio * This,
            /* [out] */ STATSTG *pstatstg,
            /* [in] */ DWORD grfStatFlag);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISpAudio * This,
            /* [out] */ IStream **ppstm);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            ISpAudio * This,
            /* [in] */ GUID *pguidFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *SetState )( 
            ISpAudio * This,
            /* [in] */ SPAUDIOSTATE NewState,
            /* [in] */ ULONGLONG ullReserved);
        
        HRESULT ( STDMETHODCALLTYPE *SetFormat )( 
            ISpAudio * This,
            /* [in] */ REFGUID rguidFmtId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ISpAudio * This,
            /* [out] */ SPAUDIOSTATUS *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferInfo )( 
            ISpAudio * This,
            /* [in] */ const SPAUDIOBUFFERINFO *pBuffInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferInfo )( 
            ISpAudio * This,
            /* [out] */ SPAUDIOBUFFERINFO *pBuffInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFormat )( 
            ISpAudio * This,
            /* [out] */ GUID *pFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        HANDLE ( STDMETHODCALLTYPE *EventHandle )( 
            ISpAudio * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetVolumeLevel )( 
            ISpAudio * This,
            /* [out] */ ULONG *pLevel);
        
        HRESULT ( STDMETHODCALLTYPE *SetVolumeLevel )( 
            ISpAudio * This,
            /* [in] */ ULONG Level);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferNotifySize )( 
            ISpAudio * This,
            /* [out] */ ULONG *pcbSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferNotifySize )( 
            ISpAudio * This,
            /* [in] */ ULONG cbSize);
        
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
            /* [out] */ UINT *puDeviceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDeviceId( 
            /* [in] */ UINT uDeviceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMMHandle( 
            /* [out] */ void **pHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLineId( 
            /* [out] */ UINT *puLineId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLineId( 
            /* [in] */ UINT uLineId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpMMSysAudioVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpMMSysAudio * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpMMSysAudio * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpMMSysAudio * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            ISpMMSysAudio * This,
            /* [annotation] */ 
            _Out_writes_bytes_to_(cb, *pcbRead)  void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbRead);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISpMMSysAudio * This,
            /* [annotation] */ 
            _In_reads_bytes_(cb)  const void *pv,
            /* [annotation][in] */ 
            _In_  ULONG cb,
            /* [annotation] */ 
            _Out_opt_  ULONG *pcbWritten);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            ISpMMSysAudio * This,
            /* [in] */ LARGE_INTEGER dlibMove,
            /* [in] */ DWORD dwOrigin,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *plibNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            ISpMMSysAudio * This,
            /* [in] */ ULARGE_INTEGER libNewSize);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            ISpMMSysAudio * This,
            /* [annotation][unique][in] */ 
            _In_  IStream *pstm,
            /* [in] */ ULARGE_INTEGER cb,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbRead,
            /* [annotation] */ 
            _Out_opt_  ULARGE_INTEGER *pcbWritten);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpMMSysAudio * This,
            /* [in] */ DWORD grfCommitFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            ISpMMSysAudio * This);
        
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            ISpMMSysAudio * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            ISpMMSysAudio * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            ISpMMSysAudio * This,
            /* [out] */ STATSTG *pstatstg,
            /* [in] */ DWORD grfStatFlag);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISpMMSysAudio * This,
            /* [out] */ IStream **ppstm);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            ISpMMSysAudio * This,
            /* [in] */ GUID *pguidFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *SetState )( 
            ISpMMSysAudio * This,
            /* [in] */ SPAUDIOSTATE NewState,
            /* [in] */ ULONGLONG ullReserved);
        
        HRESULT ( STDMETHODCALLTYPE *SetFormat )( 
            ISpMMSysAudio * This,
            /* [in] */ REFGUID rguidFmtId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ISpMMSysAudio * This,
            /* [out] */ SPAUDIOSTATUS *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferInfo )( 
            ISpMMSysAudio * This,
            /* [in] */ const SPAUDIOBUFFERINFO *pBuffInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferInfo )( 
            ISpMMSysAudio * This,
            /* [out] */ SPAUDIOBUFFERINFO *pBuffInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFormat )( 
            ISpMMSysAudio * This,
            /* [out] */ GUID *pFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemWaveFormatEx);
        
        HANDLE ( STDMETHODCALLTYPE *EventHandle )( 
            ISpMMSysAudio * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetVolumeLevel )( 
            ISpMMSysAudio * This,
            /* [out] */ ULONG *pLevel);
        
        HRESULT ( STDMETHODCALLTYPE *SetVolumeLevel )( 
            ISpMMSysAudio * This,
            /* [in] */ ULONG Level);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferNotifySize )( 
            ISpMMSysAudio * This,
            /* [out] */ ULONG *pcbSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferNotifySize )( 
            ISpMMSysAudio * This,
            /* [in] */ ULONG cbSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceId )( 
            ISpMMSysAudio * This,
            /* [out] */ UINT *puDeviceId);
        
        HRESULT ( STDMETHODCALLTYPE *SetDeviceId )( 
            ISpMMSysAudio * This,
            /* [in] */ UINT uDeviceId);
        
        HRESULT ( STDMETHODCALLTYPE *GetMMHandle )( 
            ISpMMSysAudio * This,
            /* [out] */ void **pHandle);
        
        HRESULT ( STDMETHODCALLTYPE *GetLineId )( 
            ISpMMSysAudio * This,
            /* [out] */ UINT *puLineId);
        
        HRESULT ( STDMETHODCALLTYPE *SetLineId )( 
            ISpMMSysAudio * This,
            /* [in] */ UINT uLineId);
        
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
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszTranscript) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AppendTranscript( 
            /* [string][in] */ __RPC__in_string LPCWSTR pszTranscript) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpTranscriptVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpTranscript * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpTranscript * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpTranscript * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTranscript )( 
            __RPC__in ISpTranscript * This,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszTranscript);
        
        HRESULT ( STDMETHODCALLTYPE *AppendTranscript )( 
            __RPC__in ISpTranscript * This,
            /* [string][in] */ __RPC__in_string LPCWSTR pszTranscript);
        
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


/* interface __MIDL_itf_sapi51_0000_0019 */
/* [local] */ 

typedef /* [hidden] */ 
enum SPDISPLYATTRIBUTES
    {
        SPAF_ONE_TRAILING_SPACE	= 0x2,
        SPAF_TWO_TRAILING_SPACES	= 0x4,
        SPAF_CONSUME_LEADING_SPACES	= 0x8,
        SPAF_ALL	= 0xf
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
    } 	SPPHRASE;

typedef /* [hidden][restricted] */ struct SPSERIALIZEDPHRASE
    {
    ULONG ulSerializedSize;
    } 	SPSERIALIZEDPHRASE;

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
        SPREF_Emulated	= ( 1 << 1 ) 
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
        SPPS_Interjection	= 0x5000
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



extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0019_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0019_v0_0_s_ifspec;

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
            /* [in] */ LPCWSTR pszWord,
            /* [in] */ WORD LangID,
            /* [in] */ DWORD dwFlags,
            /* [out][in] */ SPWORDPRONUNCIATIONLIST *pWordPronunciationList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPronunciation( 
            /* [in] */ LPCWSTR pszWord,
            /* [in] */ WORD LangID,
            /* [in] */ SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemovePronunciation( 
            /* [in] */ LPCWSTR pszWord,
            /* [in] */ WORD LangID,
            /* [in] */ SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGeneration( 
            /* [out] */ DWORD *pdwGeneration) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGenerationChange( 
            /* [in] */ DWORD dwFlags,
            /* [out][in] */ DWORD *pdwGeneration,
            /* [out][in] */ SPWORDLIST *pWordList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWords( 
            /* [in] */ DWORD dwFlags,
            /* [out][in] */ DWORD *pdwGeneration,
            /* [out][in][annotation] */ 
            _Inout_opt_  DWORD *pdwCookie,
            /* [out][in] */ SPWORDLIST *pWordList) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpLexiconVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpLexicon * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpLexicon * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpLexicon * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPronunciations )( 
            ISpLexicon * This,
            /* [in] */ LPCWSTR pszWord,
            /* [in] */ WORD LangID,
            /* [in] */ DWORD dwFlags,
            /* [out][in] */ SPWORDPRONUNCIATIONLIST *pWordPronunciationList);
        
        HRESULT ( STDMETHODCALLTYPE *AddPronunciation )( 
            ISpLexicon * This,
            /* [in] */ LPCWSTR pszWord,
            /* [in] */ WORD LangID,
            /* [in] */ SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation);
        
        HRESULT ( STDMETHODCALLTYPE *RemovePronunciation )( 
            ISpLexicon * This,
            /* [in] */ LPCWSTR pszWord,
            /* [in] */ WORD LangID,
            /* [in] */ SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation);
        
        HRESULT ( STDMETHODCALLTYPE *GetGeneration )( 
            ISpLexicon * This,
            /* [out] */ DWORD *pdwGeneration);
        
        HRESULT ( STDMETHODCALLTYPE *GetGenerationChange )( 
            ISpLexicon * This,
            /* [in] */ DWORD dwFlags,
            /* [out][in] */ DWORD *pdwGeneration,
            /* [out][in] */ SPWORDLIST *pWordList);
        
        HRESULT ( STDMETHODCALLTYPE *GetWords )( 
            ISpLexicon * This,
            /* [in] */ DWORD dwFlags,
            /* [out][in] */ DWORD *pdwGeneration,
            /* [out][in][annotation] */ 
            _Inout_opt_  DWORD *pdwCookie,
            /* [out][in] */ SPWORDLIST *pWordList);
        
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
            /* [in] */ __RPC__in_opt ISpLexicon *pAddLexicon,
            /* [in] */ DWORD dwFlags) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpContainerLexiconVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpContainerLexicon * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpContainerLexicon * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpContainerLexicon * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPronunciations )( 
            __RPC__in ISpContainerLexicon * This,
            /* [in] */ __RPC__in LPCWSTR pszWord,
            /* [in] */ WORD LangID,
            /* [in] */ DWORD dwFlags,
            /* [out][in] */ __RPC__inout SPWORDPRONUNCIATIONLIST *pWordPronunciationList);
        
        HRESULT ( STDMETHODCALLTYPE *AddPronunciation )( 
            __RPC__in ISpContainerLexicon * This,
            /* [in] */ __RPC__in LPCWSTR pszWord,
            /* [in] */ WORD LangID,
            /* [in] */ SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation);
        
        HRESULT ( STDMETHODCALLTYPE *RemovePronunciation )( 
            __RPC__in ISpContainerLexicon * This,
            /* [in] */ __RPC__in LPCWSTR pszWord,
            /* [in] */ WORD LangID,
            /* [in] */ SPPARTOFSPEECH ePartOfSpeech,
            /* [in][annotation] */ 
            _In_opt_  PCSPPHONEID pszPronunciation);
        
        HRESULT ( STDMETHODCALLTYPE *GetGeneration )( 
            __RPC__in ISpContainerLexicon * This,
            /* [out] */ __RPC__out DWORD *pdwGeneration);
        
        HRESULT ( STDMETHODCALLTYPE *GetGenerationChange )( 
            __RPC__in ISpContainerLexicon * This,
            /* [in] */ DWORD dwFlags,
            /* [out][in] */ __RPC__inout DWORD *pdwGeneration,
            /* [out][in] */ __RPC__inout SPWORDLIST *pWordList);
        
        HRESULT ( STDMETHODCALLTYPE *GetWords )( 
            __RPC__in ISpContainerLexicon * This,
            /* [in] */ DWORD dwFlags,
            /* [out][in] */ __RPC__inout DWORD *pdwGeneration,
            /* [out][in][annotation] */ 
            _Inout_opt_  DWORD *pdwCookie,
            /* [out][in] */ __RPC__inout SPWORDLIST *pWordList);
        
        HRESULT ( STDMETHODCALLTYPE *AddLexicon )( 
            __RPC__in ISpContainerLexicon * This,
            /* [in] */ __RPC__in_opt ISpLexicon *pAddLexicon,
            /* [in] */ DWORD dwFlags);
        
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
            /* [in] */ __RPC__in LPCWSTR pszPhone,
            /* [out] */ __RPC__out SPPHONEID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IdToPhone( 
            /* [in] */ __RPC__in PCSPPHONEID pId,
            /* [out] */ __RPC__out WCHAR *pszPhone) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPhoneConverterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpPhoneConverter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpPhoneConverter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpPhoneConverter * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetObjectToken )( 
            __RPC__in ISpPhoneConverter * This,
            /* [in] */ __RPC__in_opt ISpObjectToken *pToken);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectToken )( 
            __RPC__in ISpPhoneConverter * This,
            /* [out] */ __RPC__deref_out_opt ISpObjectToken **ppToken);
        
        HRESULT ( STDMETHODCALLTYPE *PhoneToId )( 
            __RPC__in ISpPhoneConverter * This,
            /* [in] */ __RPC__in LPCWSTR pszPhone,
            /* [out] */ __RPC__out SPPHONEID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *IdToPhone )( 
            __RPC__in ISpPhoneConverter * This,
            /* [in] */ __RPC__in PCSPPHONEID pId,
            /* [out] */ __RPC__out WCHAR *pszPhone);
        
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


/* interface __MIDL_itf_sapi51_0000_0022 */
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
        SPF_NLP_MASK	= SPF_NLP_SPEAK_PUNC,
        SPF_VOICE_MASK	= ( ( ( ( ( ( SPF_ASYNC | SPF_PURGEBEFORESPEAK )  | SPF_IS_FILENAME )  | SPF_IS_XML )  | SPF_IS_NOT_XML )  | SPF_NLP_MASK )  | SPF_PERSIST_XML ) ,
        SPF_UNUSED_FLAGS	= ~SPF_VOICE_MASK
    } 	SPEAKFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0022_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0022_v0_0_s_ifspec;

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
            /* [in] */ IUnknown *pUnkOutput,
            /* [in] */ BOOL fAllowFormatChanges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputObjectToken( 
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppObjectToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputStream( 
            /* [out] */ ISpStreamFormat **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoice( 
            /* [in] */ ISpObjectToken *pToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoice( 
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Speak( 
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pwcs,
            /* [in] */ DWORD dwFlags,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pulStreamNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SpeakStream( 
            /* [in] */ IStream *pStream,
            /* [in] */ DWORD dwFlags,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pulStreamNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ SPVOICESTATUS *pStatus,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszLastBookmark) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [string][in] */ LPCWSTR pItemType,
            /* [in] */ long lNumItems,
            /* [out] */ ULONG *pulNumSkipped) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPriority( 
            /* [in] */ SPVPRIORITY ePriority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPriority( 
            /* [out] */ SPVPRIORITY *pePriority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAlertBoundary( 
            /* [in] */ SPEVENTENUM eBoundary) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAlertBoundary( 
            /* [out] */ SPEVENTENUM *peBoundary) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRate( 
            /* [in] */ long RateAdjust) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRate( 
            /* [out] */ long *pRateAdjust) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVolume( 
            /* [in] */ USHORT usVolume) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVolume( 
            /* [out] */ USHORT *pusVolume) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitUntilDone( 
            /* [in] */ ULONG msTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSyncSpeakTimeout( 
            /* [in] */ ULONG msTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSyncSpeakTimeout( 
            /* [out] */ ULONG *pmsTimeout) = 0;
        
        virtual /* [local] */ HANDLE STDMETHODCALLTYPE SpeakCompleteEvent( void) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [out] */ BOOL *pfSupported) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [in] */ HWND hwndParent,
            /* [in] */ LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpVoiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpVoice * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpVoice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpVoice * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetNotifySink )( 
            ISpVoice * This,
            /* [in] */ ISpNotifySink *pNotifySink);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWindowMessage )( 
            ISpVoice * This,
            /* [in] */ HWND hWnd,
            /* [in] */ UINT Msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackFunction )( 
            ISpVoice * This,
            /* [in] */ SPNOTIFYCALLBACK *pfnCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackInterface )( 
            ISpVoice * This,
            /* [in] */ ISpNotifyCallback *pSpCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWin32Event )( 
            ISpVoice * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *WaitForNotifyEvent )( 
            ISpVoice * This,
            /* [in] */ DWORD dwMilliseconds);
        
        /* [local] */ HANDLE ( STDMETHODCALLTYPE *GetNotifyEventHandle )( 
            ISpVoice * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetInterest )( 
            ISpVoice * This,
            /* [in] */ ULONGLONG ullEventInterest,
            /* [in] */ ULONGLONG ullQueuedInterest);
        
        HRESULT ( STDMETHODCALLTYPE *GetEvents )( 
            ISpVoice * This,
            /* [in] */ ULONG ulCount,
            /* [size_is][out] */ SPEVENT *pEventArray,
            /* [out] */ ULONG *pulFetched);
        
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            ISpVoice * This,
            /* [out] */ SPEVENTSOURCEINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SetOutput )( 
            ISpVoice * This,
            /* [in] */ IUnknown *pUnkOutput,
            /* [in] */ BOOL fAllowFormatChanges);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputObjectToken )( 
            ISpVoice * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppObjectToken);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputStream )( 
            ISpVoice * This,
            /* [out] */ ISpStreamFormat **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *Pause )( 
            ISpVoice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            ISpVoice * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetVoice )( 
            ISpVoice * This,
            /* [in] */ ISpObjectToken *pToken);
        
        HRESULT ( STDMETHODCALLTYPE *GetVoice )( 
            ISpVoice * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppToken);
        
        HRESULT ( STDMETHODCALLTYPE *Speak )( 
            ISpVoice * This,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pwcs,
            /* [in] */ DWORD dwFlags,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pulStreamNumber);
        
        HRESULT ( STDMETHODCALLTYPE *SpeakStream )( 
            ISpVoice * This,
            /* [in] */ IStream *pStream,
            /* [in] */ DWORD dwFlags,
            /* [out][annotation] */ 
            _Out_opt_  ULONG *pulStreamNumber);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ISpVoice * This,
            /* [out] */ SPVOICESTATUS *pStatus,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszLastBookmark);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            ISpVoice * This,
            /* [string][in] */ LPCWSTR pItemType,
            /* [in] */ long lNumItems,
            /* [out] */ ULONG *pulNumSkipped);
        
        HRESULT ( STDMETHODCALLTYPE *SetPriority )( 
            ISpVoice * This,
            /* [in] */ SPVPRIORITY ePriority);
        
        HRESULT ( STDMETHODCALLTYPE *GetPriority )( 
            ISpVoice * This,
            /* [out] */ SPVPRIORITY *pePriority);
        
        HRESULT ( STDMETHODCALLTYPE *SetAlertBoundary )( 
            ISpVoice * This,
            /* [in] */ SPEVENTENUM eBoundary);
        
        HRESULT ( STDMETHODCALLTYPE *GetAlertBoundary )( 
            ISpVoice * This,
            /* [out] */ SPEVENTENUM *peBoundary);
        
        HRESULT ( STDMETHODCALLTYPE *SetRate )( 
            ISpVoice * This,
            /* [in] */ long RateAdjust);
        
        HRESULT ( STDMETHODCALLTYPE *GetRate )( 
            ISpVoice * This,
            /* [out] */ long *pRateAdjust);
        
        HRESULT ( STDMETHODCALLTYPE *SetVolume )( 
            ISpVoice * This,
            /* [in] */ USHORT usVolume);
        
        HRESULT ( STDMETHODCALLTYPE *GetVolume )( 
            ISpVoice * This,
            /* [out] */ USHORT *pusVolume);
        
        HRESULT ( STDMETHODCALLTYPE *WaitUntilDone )( 
            ISpVoice * This,
            /* [in] */ ULONG msTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *SetSyncSpeakTimeout )( 
            ISpVoice * This,
            /* [in] */ ULONG msTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *GetSyncSpeakTimeout )( 
            ISpVoice * This,
            /* [out] */ ULONG *pmsTimeout);
        
        /* [local] */ HANDLE ( STDMETHODCALLTYPE *SpeakCompleteEvent )( 
            ISpVoice * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            ISpVoice * This,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [out] */ BOOL *pfSupported);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            ISpVoice * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData);
        
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
            /* [in] */ ULONG ulStart,
            /* [in] */ ULONG ulCount,
            /* [in] */ BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Discard( 
            /* [in] */ DWORD dwValueTypes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPhraseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPhrase * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPhrase * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPhrase * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpPhrase * This,
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpPhrase * This,
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpPhrase * This,
            /* [in] */ ULONG ulStart,
            /* [in] */ ULONG ulCount,
            /* [in] */ BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpPhrase * This,
            /* [in] */ DWORD dwValueTypes);
        
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
            /* [out] */ ISpPhrase **ppParent,
            /* [out] */ ULONG *pulStartElementInParent,
            /* [out] */ ULONG *pcElementsInParent,
            /* [out] */ ULONG *pcElementsInAlt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Commit( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPhraseAltVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpPhraseAlt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpPhraseAlt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpPhraseAlt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpPhraseAlt * This,
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpPhraseAlt * This,
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpPhraseAlt * This,
            /* [in] */ ULONG ulStart,
            /* [in] */ ULONG ulCount,
            /* [in] */ BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpPhraseAlt * This,
            /* [in] */ DWORD dwValueTypes);
        
        HRESULT ( STDMETHODCALLTYPE *GetAltInfo )( 
            ISpPhraseAlt * This,
            /* [out] */ ISpPhrase **ppParent,
            /* [out] */ ULONG *pulStartElementInParent,
            /* [out] */ ULONG *pcElementsInParent,
            /* [out] */ ULONG *pcElementsInAlt);
        
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


/* interface __MIDL_itf_sapi51_0000_0025 */
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



extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0025_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0025_v0_0_s_ifspec;

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
            /* [out] */ SPRECORESULTTIMES *pTimes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAlternates( 
            /* [in] */ ULONG ulStartElement,
            /* [in] */ ULONG cElements,
            /* [in] */ ULONG ulRequestCount,
            /* [out][annotation] */ 
            _Out_writes_to_(ulRequestCount,*pcPhrasesReturned)  ISpPhraseAlt **ppPhrases,
            /* [out] */ ULONG *pcPhrasesReturned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudio( 
            /* [in] */ ULONG ulStartElement,
            /* [in] */ ULONG cElements,
            /* [out] */ ISpStreamFormat **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SpeakAudio( 
            /* [in] */ ULONG ulStartElement,
            /* [in] */ ULONG cElements,
            /* [in] */ DWORD dwFlags,
            /* [out] */ ULONG *pulStreamNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Serialize( 
            /* [out] */ SPSERIALIZEDRESULT **ppCoMemSerializedResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScaleAudio( 
            /* [in] */ const GUID *pAudioFormatId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecoContext( 
            /* [out] */ ISpRecoContext **ppRecoContext) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecoResultVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecoResult * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecoResult * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecoResult * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhrase )( 
            ISpRecoResult * This,
            /* [out][annotation] */ 
            _Outptr_  SPPHRASE **ppCoMemPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *GetSerializedPhrase )( 
            ISpRecoResult * This,
            /* [out][annotation] */ 
            _Outptr_  SPSERIALIZEDPHRASE **ppCoMemPhrase);
        
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ISpRecoResult * This,
            /* [in] */ ULONG ulStart,
            /* [in] */ ULONG ulCount,
            /* [in] */ BOOL fUseTextReplacements,
            /* [out][annotation] */ 
            _Outptr_  LPWSTR *ppszCoMemText,
            /* [optional][out][annotation] */ 
            _Out_writes_opt_(1)  BYTE *pbDisplayAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *Discard )( 
            ISpRecoResult * This,
            /* [in] */ DWORD dwValueTypes);
        
        HRESULT ( STDMETHODCALLTYPE *GetResultTimes )( 
            ISpRecoResult * This,
            /* [out] */ SPRECORESULTTIMES *pTimes);
        
        HRESULT ( STDMETHODCALLTYPE *GetAlternates )( 
            ISpRecoResult * This,
            /* [in] */ ULONG ulStartElement,
            /* [in] */ ULONG cElements,
            /* [in] */ ULONG ulRequestCount,
            /* [out][annotation] */ 
            _Out_writes_to_(ulRequestCount,*pcPhrasesReturned)  ISpPhraseAlt **ppPhrases,
            /* [out] */ ULONG *pcPhrasesReturned);
        
        HRESULT ( STDMETHODCALLTYPE *GetAudio )( 
            ISpRecoResult * This,
            /* [in] */ ULONG ulStartElement,
            /* [in] */ ULONG cElements,
            /* [out] */ ISpStreamFormat **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *SpeakAudio )( 
            ISpRecoResult * This,
            /* [in] */ ULONG ulStartElement,
            /* [in] */ ULONG cElements,
            /* [in] */ DWORD dwFlags,
            /* [out] */ ULONG *pulStreamNumber);
        
        HRESULT ( STDMETHODCALLTYPE *Serialize )( 
            ISpRecoResult * This,
            /* [out] */ SPSERIALIZEDRESULT **ppCoMemSerializedResult);
        
        HRESULT ( STDMETHODCALLTYPE *ScaleAudio )( 
            ISpRecoResult * This,
            /* [in] */ const GUID *pAudioFormatId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecoContext )( 
            ISpRecoResult * This,
            /* [out] */ ISpRecoContext **ppRecoContext);
        
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


/* interface __MIDL_itf_sapi51_0000_0026 */
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
        SPRS_ACTIVE_WITH_AUTO_PAUSE	= 3
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
        SPWT_PRONUNCIATION	= ( SPWT_LEXICAL + 1 ) 
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
        SPRAF_AutoPause	= ( 1 << 16 ) 
    } 	SPCFGRULEATTRIBUTES;



extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0026_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0026_v0_0_s_ifspec;

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
            /* [in] */ WORD NewLanguage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRule( 
            /* [in] */ LPCWSTR pszRuleName,
            /* [in] */ DWORD dwRuleId,
            /* [in] */ DWORD dwAttributes,
            /* [in] */ BOOL fCreateIfNotExist,
            /* [out] */ SPSTATEHANDLE *phInitialState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearRule( 
            /* [in] */ SPSTATEHANDLE hState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewState( 
            /* [in] */ SPSTATEHANDLE hState,
            /* [out] */ SPSTATEHANDLE *phState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddWordTransition( 
            /* [in] */ SPSTATEHANDLE hFromState,
            /* [in] */ SPSTATEHANDLE hToState,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR psz,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszSeparators,
            /* [in] */ SPGRAMMARWORDTYPE eWordType,
            /* [in] */ float Weight,
            /* [in] */ const SPPROPERTYINFO *pPropInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRuleTransition( 
            /* [in] */ SPSTATEHANDLE hFromState,
            /* [in] */ SPSTATEHANDLE hToState,
            /* [in] */ SPSTATEHANDLE hRule,
            /* [in] */ float Weight,
            /* [in] */ const SPPROPERTYINFO *pPropInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddResource( 
            /* [in] */ SPSTATEHANDLE hRuleState,
            /* [in] */ LPCWSTR pszResourceName,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszResourceValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Commit( 
            /* [in] */ DWORD dwReserved) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpGrammarBuilderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpGrammarBuilder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpGrammarBuilder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpGrammarBuilder * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetGrammar )( 
            ISpGrammarBuilder * This,
            /* [in] */ WORD NewLanguage);
        
        HRESULT ( STDMETHODCALLTYPE *GetRule )( 
            ISpGrammarBuilder * This,
            /* [in] */ LPCWSTR pszRuleName,
            /* [in] */ DWORD dwRuleId,
            /* [in] */ DWORD dwAttributes,
            /* [in] */ BOOL fCreateIfNotExist,
            /* [out] */ SPSTATEHANDLE *phInitialState);
        
        HRESULT ( STDMETHODCALLTYPE *ClearRule )( 
            ISpGrammarBuilder * This,
            /* [in] */ SPSTATEHANDLE hState);
        
        HRESULT ( STDMETHODCALLTYPE *CreateNewState )( 
            ISpGrammarBuilder * This,
            /* [in] */ SPSTATEHANDLE hState,
            /* [out] */ SPSTATEHANDLE *phState);
        
        HRESULT ( STDMETHODCALLTYPE *AddWordTransition )( 
            ISpGrammarBuilder * This,
            /* [in] */ SPSTATEHANDLE hFromState,
            /* [in] */ SPSTATEHANDLE hToState,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR psz,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszSeparators,
            /* [in] */ SPGRAMMARWORDTYPE eWordType,
            /* [in] */ float Weight,
            /* [in] */ const SPPROPERTYINFO *pPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddRuleTransition )( 
            ISpGrammarBuilder * This,
            /* [in] */ SPSTATEHANDLE hFromState,
            /* [in] */ SPSTATEHANDLE hToState,
            /* [in] */ SPSTATEHANDLE hRule,
            /* [in] */ float Weight,
            /* [in] */ const SPPROPERTYINFO *pPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddResource )( 
            ISpGrammarBuilder * This,
            /* [in] */ SPSTATEHANDLE hRuleState,
            /* [in] */ LPCWSTR pszResourceName,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszResourceValue);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpGrammarBuilder * This,
            /* [in] */ DWORD dwReserved);
        
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


/* interface __MIDL_itf_sapi51_0000_0027 */
/* [local] */ 

typedef /* [hidden] */ 
enum SPLOADOPTIONS
    {
        SPLO_STATIC	= 0,
        SPLO_DYNAMIC	= 1
    } 	SPLOADOPTIONS;



extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0027_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0027_v0_0_s_ifspec;

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
            /* [out] */ ULONGLONG *pullGrammarId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecoContext( 
            /* [out][annotation] */ 
            _Outptr_  ISpRecoContext **ppRecoCtxt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromFile( 
            /* [string][in] */ LPCWSTR pszFileName,
            /* [in] */ SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromObject( 
            /* [in] */ REFCLSID rcid,
            /* [string][in] */ LPCWSTR pszGrammarName,
            /* [in] */ SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromResource( 
            /* [in] */ HMODULE hModule,
            /* [string][in] */ LPCWSTR pszResourceName,
            /* [string][in] */ LPCWSTR pszResourceType,
            /* [in] */ WORD wLanguage,
            /* [in] */ SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromMemory( 
            /* [in] */ const SPBINARYGRAMMAR *pGrammar,
            /* [in] */ SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadCmdFromProprietaryGrammar( 
            /* [in] */ REFGUID rguidParam,
            /* [string][in] */ LPCWSTR pszStringParam,
            /* [in] */ const void *pvDataPrarm,
            /* [in] */ ULONG cbDataSize,
            /* [in] */ SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRuleState( 
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszName,
            /* [in] */ void *pReserved,
            /* [in] */ SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRuleIdState( 
            /* [in] */ ULONG ulRuleId,
            /* [in] */ SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadDictation( 
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszTopicName,
            /* [in] */ SPLOADOPTIONS Options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnloadDictation( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDictationState( 
            /* [in] */ SPRULESTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWordSequenceData( 
            /* [in][annotation] */ 
            _In_reads_opt_(cchText)  const WCHAR *pText,
            /* [in] */ ULONG cchText,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTextSelection( 
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPronounceable( 
            /* [string][in] */ LPCWSTR pszWord,
            /* [out] */ SPWORDPRONOUNCEABLE *pWordPronounceable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGrammarState( 
            /* [in] */ SPGRAMMARSTATE eGrammarState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveCmd( 
            /* [in] */ IStream *pStream,
            /* [optional][out][annotation] */ 
            _Outptr_opt_  LPWSTR *ppszCoMemErrorText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGrammarState( 
            /* [out] */ SPGRAMMARSTATE *peGrammarState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecoGrammarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecoGrammar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecoGrammar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecoGrammar * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetGrammar )( 
            ISpRecoGrammar * This,
            /* [in] */ WORD NewLanguage);
        
        HRESULT ( STDMETHODCALLTYPE *GetRule )( 
            ISpRecoGrammar * This,
            /* [in] */ LPCWSTR pszRuleName,
            /* [in] */ DWORD dwRuleId,
            /* [in] */ DWORD dwAttributes,
            /* [in] */ BOOL fCreateIfNotExist,
            /* [out] */ SPSTATEHANDLE *phInitialState);
        
        HRESULT ( STDMETHODCALLTYPE *ClearRule )( 
            ISpRecoGrammar * This,
            /* [in] */ SPSTATEHANDLE hState);
        
        HRESULT ( STDMETHODCALLTYPE *CreateNewState )( 
            ISpRecoGrammar * This,
            /* [in] */ SPSTATEHANDLE hState,
            /* [out] */ SPSTATEHANDLE *phState);
        
        HRESULT ( STDMETHODCALLTYPE *AddWordTransition )( 
            ISpRecoGrammar * This,
            /* [in] */ SPSTATEHANDLE hFromState,
            /* [in] */ SPSTATEHANDLE hToState,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR psz,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszSeparators,
            /* [in] */ SPGRAMMARWORDTYPE eWordType,
            /* [in] */ float Weight,
            /* [in] */ const SPPROPERTYINFO *pPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddRuleTransition )( 
            ISpRecoGrammar * This,
            /* [in] */ SPSTATEHANDLE hFromState,
            /* [in] */ SPSTATEHANDLE hToState,
            /* [in] */ SPSTATEHANDLE hRule,
            /* [in] */ float Weight,
            /* [in] */ const SPPROPERTYINFO *pPropInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddResource )( 
            ISpRecoGrammar * This,
            /* [in] */ SPSTATEHANDLE hRuleState,
            /* [in] */ LPCWSTR pszResourceName,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszResourceValue);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            ISpRecoGrammar * This,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE *GetGrammarId )( 
            ISpRecoGrammar * This,
            /* [out] */ ULONGLONG *pullGrammarId);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecoContext )( 
            ISpRecoGrammar * This,
            /* [out][annotation] */ 
            _Outptr_  ISpRecoContext **ppRecoCtxt);
        
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromFile )( 
            ISpRecoGrammar * This,
            /* [string][in] */ LPCWSTR pszFileName,
            /* [in] */ SPLOADOPTIONS Options);
        
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromObject )( 
            ISpRecoGrammar * This,
            /* [in] */ REFCLSID rcid,
            /* [string][in] */ LPCWSTR pszGrammarName,
            /* [in] */ SPLOADOPTIONS Options);
        
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromResource )( 
            ISpRecoGrammar * This,
            /* [in] */ HMODULE hModule,
            /* [string][in] */ LPCWSTR pszResourceName,
            /* [string][in] */ LPCWSTR pszResourceType,
            /* [in] */ WORD wLanguage,
            /* [in] */ SPLOADOPTIONS Options);
        
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromMemory )( 
            ISpRecoGrammar * This,
            /* [in] */ const SPBINARYGRAMMAR *pGrammar,
            /* [in] */ SPLOADOPTIONS Options);
        
        HRESULT ( STDMETHODCALLTYPE *LoadCmdFromProprietaryGrammar )( 
            ISpRecoGrammar * This,
            /* [in] */ REFGUID rguidParam,
            /* [string][in] */ LPCWSTR pszStringParam,
            /* [in] */ const void *pvDataPrarm,
            /* [in] */ ULONG cbDataSize,
            /* [in] */ SPLOADOPTIONS Options);
        
        HRESULT ( STDMETHODCALLTYPE *SetRuleState )( 
            ISpRecoGrammar * This,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszName,
            /* [in] */ void *pReserved,
            /* [in] */ SPRULESTATE NewState);
        
        HRESULT ( STDMETHODCALLTYPE *SetRuleIdState )( 
            ISpRecoGrammar * This,
            /* [in] */ ULONG ulRuleId,
            /* [in] */ SPRULESTATE NewState);
        
        HRESULT ( STDMETHODCALLTYPE *LoadDictation )( 
            ISpRecoGrammar * This,
            /* [string][in][annotation] */ 
            _In_opt_  LPCWSTR pszTopicName,
            /* [in] */ SPLOADOPTIONS Options);
        
        HRESULT ( STDMETHODCALLTYPE *UnloadDictation )( 
            ISpRecoGrammar * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDictationState )( 
            ISpRecoGrammar * This,
            /* [in] */ SPRULESTATE NewState);
        
        HRESULT ( STDMETHODCALLTYPE *SetWordSequenceData )( 
            ISpRecoGrammar * This,
            /* [in][annotation] */ 
            _In_reads_opt_(cchText)  const WCHAR *pText,
            /* [in] */ ULONG cchText,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SetTextSelection )( 
            ISpRecoGrammar * This,
            /* [in] */ const SPTEXTSELECTIONINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *IsPronounceable )( 
            ISpRecoGrammar * This,
            /* [string][in] */ LPCWSTR pszWord,
            /* [out] */ SPWORDPRONOUNCEABLE *pWordPronounceable);
        
        HRESULT ( STDMETHODCALLTYPE *SetGrammarState )( 
            ISpRecoGrammar * This,
            /* [in] */ SPGRAMMARSTATE eGrammarState);
        
        HRESULT ( STDMETHODCALLTYPE *SaveCmd )( 
            ISpRecoGrammar * This,
            /* [in] */ IStream *pStream,
            /* [optional][out][annotation] */ 
            _Outptr_opt_  LPWSTR *ppszCoMemErrorText);
        
        HRESULT ( STDMETHODCALLTYPE *GetGrammarState )( 
            ISpRecoGrammar * This,
            /* [out] */ SPGRAMMARSTATE *peGrammarState);
        
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


/* interface __MIDL_itf_sapi51_0000_0028 */
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
        SPBO_PAUSE	= ( 1 << 0 ) 
    } 	SPBOOKMARKOPTIONS;

typedef /* [hidden] */ 
enum SPAUDIOOPTIONS
    {
        SPAO_NONE	= 0,
        SPAO_RETAIN_AUDIO	= ( 1 << 0 ) 
    } 	SPAUDIOOPTIONS;



extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0028_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0028_v0_0_s_ifspec;

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
            /* [out] */ ISpRecognizer **ppRecognizer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateGrammar( 
            /* [in] */ ULONGLONG ullGrammarId,
            /* [out] */ ISpRecoGrammar **ppGrammar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ SPRECOCONTEXTSTATUS *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxAlternates( 
            /* [in] */ ULONG *pcAlternates) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxAlternates( 
            /* [in] */ ULONG cAlternates) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAudioOptions( 
            /* [in] */ SPAUDIOOPTIONS Options,
            /* [in] */ const GUID *pAudioFormatId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAudioOptions( 
            /* [in] */ SPAUDIOOPTIONS *pOptions,
            /* [out] */ GUID *pAudioFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemWFEX) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeserializeResult( 
            /* [in] */ const SPSERIALIZEDRESULT *pSerializedResult,
            /* [out] */ ISpRecoResult **ppResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Bookmark( 
            /* [in] */ SPBOOKMARKOPTIONS Options,
            /* [in] */ ULONGLONG ullStreamPosition,
            /* [in] */ LPARAM lparamEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdaptationData( 
            /* [string][in] */ LPCWSTR pAdaptationData,
            /* [in] */ const ULONG cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pause( 
            /* [in] */ DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( 
            /* [in] */ DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoice( 
            /* [in] */ ISpVoice *pVoice,
            /* [in] */ BOOL fAllowFormatChanges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoice( 
            /* [out] */ ISpVoice **ppVoice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVoicePurgeEvent( 
            /* [in] */ ULONGLONG ullEventInterest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVoicePurgeEvent( 
            /* [out] */ ULONGLONG *pullEventInterest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetContextState( 
            /* [in] */ SPCONTEXTSTATE eContextState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextState( 
            /* [out] */ SPCONTEXTSTATE *peContextState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecoContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecoContext * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecoContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecoContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetNotifySink )( 
            ISpRecoContext * This,
            /* [in] */ ISpNotifySink *pNotifySink);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWindowMessage )( 
            ISpRecoContext * This,
            /* [in] */ HWND hWnd,
            /* [in] */ UINT Msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackFunction )( 
            ISpRecoContext * This,
            /* [in] */ SPNOTIFYCALLBACK *pfnCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyCallbackInterface )( 
            ISpRecoContext * This,
            /* [in] */ ISpNotifyCallback *pSpCallback,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetNotifyWin32Event )( 
            ISpRecoContext * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *WaitForNotifyEvent )( 
            ISpRecoContext * This,
            /* [in] */ DWORD dwMilliseconds);
        
        /* [local] */ HANDLE ( STDMETHODCALLTYPE *GetNotifyEventHandle )( 
            ISpRecoContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetInterest )( 
            ISpRecoContext * This,
            /* [in] */ ULONGLONG ullEventInterest,
            /* [in] */ ULONGLONG ullQueuedInterest);
        
        HRESULT ( STDMETHODCALLTYPE *GetEvents )( 
            ISpRecoContext * This,
            /* [in] */ ULONG ulCount,
            /* [size_is][out] */ SPEVENT *pEventArray,
            /* [out] */ ULONG *pulFetched);
        
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            ISpRecoContext * This,
            /* [out] */ SPEVENTSOURCEINFO *pInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecognizer )( 
            ISpRecoContext * This,
            /* [out] */ ISpRecognizer **ppRecognizer);
        
        HRESULT ( STDMETHODCALLTYPE *CreateGrammar )( 
            ISpRecoContext * This,
            /* [in] */ ULONGLONG ullGrammarId,
            /* [out] */ ISpRecoGrammar **ppGrammar);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ISpRecoContext * This,
            /* [out] */ SPRECOCONTEXTSTATUS *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxAlternates )( 
            ISpRecoContext * This,
            /* [in] */ ULONG *pcAlternates);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxAlternates )( 
            ISpRecoContext * This,
            /* [in] */ ULONG cAlternates);
        
        HRESULT ( STDMETHODCALLTYPE *SetAudioOptions )( 
            ISpRecoContext * This,
            /* [in] */ SPAUDIOOPTIONS Options,
            /* [in] */ const GUID *pAudioFormatId,
            /* [in] */ const WAVEFORMATEX *pWaveFormatEx);
        
        HRESULT ( STDMETHODCALLTYPE *GetAudioOptions )( 
            ISpRecoContext * This,
            /* [in] */ SPAUDIOOPTIONS *pOptions,
            /* [out] */ GUID *pAudioFormatId,
            /* [out] */ WAVEFORMATEX **ppCoMemWFEX);
        
        HRESULT ( STDMETHODCALLTYPE *DeserializeResult )( 
            ISpRecoContext * This,
            /* [in] */ const SPSERIALIZEDRESULT *pSerializedResult,
            /* [out] */ ISpRecoResult **ppResult);
        
        HRESULT ( STDMETHODCALLTYPE *Bookmark )( 
            ISpRecoContext * This,
            /* [in] */ SPBOOKMARKOPTIONS Options,
            /* [in] */ ULONGLONG ullStreamPosition,
            /* [in] */ LPARAM lparamEvent);
        
        HRESULT ( STDMETHODCALLTYPE *SetAdaptationData )( 
            ISpRecoContext * This,
            /* [string][in] */ LPCWSTR pAdaptationData,
            /* [in] */ const ULONG cch);
        
        HRESULT ( STDMETHODCALLTYPE *Pause )( 
            ISpRecoContext * This,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            ISpRecoContext * This,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE *SetVoice )( 
            ISpRecoContext * This,
            /* [in] */ ISpVoice *pVoice,
            /* [in] */ BOOL fAllowFormatChanges);
        
        HRESULT ( STDMETHODCALLTYPE *GetVoice )( 
            ISpRecoContext * This,
            /* [out] */ ISpVoice **ppVoice);
        
        HRESULT ( STDMETHODCALLTYPE *SetVoicePurgeEvent )( 
            ISpRecoContext * This,
            /* [in] */ ULONGLONG ullEventInterest);
        
        HRESULT ( STDMETHODCALLTYPE *GetVoicePurgeEvent )( 
            ISpRecoContext * This,
            /* [out] */ ULONGLONG *pullEventInterest);
        
        HRESULT ( STDMETHODCALLTYPE *SetContextState )( 
            ISpRecoContext * This,
            /* [in] */ SPCONTEXTSTATE eContextState);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextState )( 
            ISpRecoContext * This,
            /* [out] */ SPCONTEXTSTATE *peContextState);
        
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
            /* [in] */ LPCWSTR pName,
            /* [in] */ LONG lValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyNum( 
            /* [in] */ LPCWSTR pName,
            /* [out] */ LONG *plValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyString( 
            /* [in] */ LPCWSTR pName,
            /* [in] */ LPCWSTR pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyString( 
            /* [in] */ LPCWSTR pName,
            /* [string][out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemValue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpProperties * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyNum )( 
            ISpProperties * This,
            /* [in] */ LPCWSTR pName,
            /* [in] */ LONG lValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyNum )( 
            ISpProperties * This,
            /* [in] */ LPCWSTR pName,
            /* [out] */ LONG *plValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyString )( 
            ISpProperties * This,
            /* [in] */ LPCWSTR pName,
            /* [in] */ LPCWSTR pValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyString )( 
            ISpProperties * This,
            /* [in] */ LPCWSTR pName,
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


/* interface __MIDL_itf_sapi51_0000_0030 */
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



extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0030_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0030_v0_0_s_ifspec;

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
            /* [in] */ ISpObjectToken *pRecognizer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecognizer( 
            /* [out] */ ISpObjectToken **ppRecognizer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInput( 
            /* [in][annotation] */ 
            _In_opt_  IUnknown *pUnkInput,
            /* [in] */ BOOL fAllowFormatChanges) = 0;
        
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
            /* [in] */ ISpObjectToken *pToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsSharedInstance( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecoState( 
            /* [out] */ SPRECOSTATE *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecoState( 
            /* [in] */ SPRECOSTATE NewState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ SPRECOGNIZERSTATUS *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFormat( 
            /* [in] */ SPSTREAMFORMATTYPE WaveFormatType,
            /* [out] */ GUID *pFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemWFEX) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [out] */ BOOL *pfSupported) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [in] */ HWND hwndParent,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EmulateRecognition( 
            /* [in] */ ISpPhrase *pPhrase) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpRecognizerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpRecognizer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpRecognizer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpRecognizer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyNum )( 
            ISpRecognizer * This,
            /* [in] */ LPCWSTR pName,
            /* [in] */ LONG lValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyNum )( 
            ISpRecognizer * This,
            /* [in] */ LPCWSTR pName,
            /* [out] */ LONG *plValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyString )( 
            ISpRecognizer * This,
            /* [in] */ LPCWSTR pName,
            /* [in] */ LPCWSTR pValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyString )( 
            ISpRecognizer * This,
            /* [in] */ LPCWSTR pName,
            /* [string][out][annotation] */ 
            _Outptr_  LPWSTR *ppCoMemValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetRecognizer )( 
            ISpRecognizer * This,
            /* [in] */ ISpObjectToken *pRecognizer);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecognizer )( 
            ISpRecognizer * This,
            /* [out] */ ISpObjectToken **ppRecognizer);
        
        HRESULT ( STDMETHODCALLTYPE *SetInput )( 
            ISpRecognizer * This,
            /* [in][annotation] */ 
            _In_opt_  IUnknown *pUnkInput,
            /* [in] */ BOOL fAllowFormatChanges);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputObjectToken )( 
            ISpRecognizer * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppToken);
        
        HRESULT ( STDMETHODCALLTYPE *GetInputStream )( 
            ISpRecognizer * This,
            /* [out][annotation] */ 
            _Outptr_  ISpStreamFormat **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *CreateRecoContext )( 
            ISpRecognizer * This,
            /* [out][annotation] */ 
            _Outptr_  ISpRecoContext **ppNewCtxt);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecoProfile )( 
            ISpRecognizer * This,
            /* [out][annotation] */ 
            _Outptr_  ISpObjectToken **ppToken);
        
        HRESULT ( STDMETHODCALLTYPE *SetRecoProfile )( 
            ISpRecognizer * This,
            /* [in] */ ISpObjectToken *pToken);
        
        HRESULT ( STDMETHODCALLTYPE *IsSharedInstance )( 
            ISpRecognizer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecoState )( 
            ISpRecognizer * This,
            /* [out] */ SPRECOSTATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *SetRecoState )( 
            ISpRecognizer * This,
            /* [in] */ SPRECOSTATE NewState);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ISpRecognizer * This,
            /* [out] */ SPRECOGNIZERSTATUS *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            ISpRecognizer * This,
            /* [in] */ SPSTREAMFORMATTYPE WaveFormatType,
            /* [out] */ GUID *pFormatId,
            /* [out][annotation] */ 
            _Outptr_  WAVEFORMATEX **ppCoMemWFEX);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            ISpRecognizer * This,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData,
            /* [out] */ BOOL *pfSupported);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            ISpRecognizer * This,
            /* [in] */ HWND hwndParent,
            /* [in][annotation] */ 
            _In_opt_  LPCWSTR pszTitle,
            /* [in] */ LPCWSTR pszTypeOfUI,
            /* [in] */ void *pvExtraData,
            /* [in] */ ULONG cbExtraData);
        
        HRESULT ( STDMETHODCALLTYPE *EmulateRecognition )( 
            ISpRecognizer * This,
            /* [in] */ ISpPhrase *pPhrase);
        
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



#ifndef __SpeechLib_LIBRARY_DEFINED__
#define __SpeechLib_LIBRARY_DEFINED__

/* library SpeechLib */
/* [version][uuid][helpstring] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)














































typedef long SpeechLanguageId;

#define __SpeechStringConstants_MODULE_DEFINED__
typedef /* [hidden] */ 
enum DISPID_SpeechDataKey
    {
        DISPID_SDKSetBinaryValue	= 1,
        DISPID_SDKGetBinaryValue	= ( DISPID_SDKSetBinaryValue + 1 ) ,
        DISPID_SDKSetStringValue	= ( DISPID_SDKGetBinaryValue + 1 ) ,
        DISPID_SDKGetStringValue	= ( DISPID_SDKSetStringValue + 1 ) ,
        DISPID_SDKSetLongValue	= ( DISPID_SDKGetStringValue + 1 ) ,
        DISPID_SDKGetlongValue	= ( DISPID_SDKSetLongValue + 1 ) ,
        DISPID_SDKOpenKey	= ( DISPID_SDKGetlongValue + 1 ) ,
        DISPID_SDKCreateKey	= ( DISPID_SDKOpenKey + 1 ) ,
        DISPID_SDKDeleteKey	= ( DISPID_SDKCreateKey + 1 ) ,
        DISPID_SDKDeleteValue	= ( DISPID_SDKDeleteKey + 1 ) ,
        DISPID_SDKEnumKeys	= ( DISPID_SDKDeleteValue + 1 ) ,
        DISPID_SDKEnumValues	= ( DISPID_SDKEnumKeys + 1 ) 
    } 	DISPID_SpeechDataKey;

typedef /* [hidden] */ 
enum DISPID_SpeechObjectToken
    {
        DISPID_SOTId	= 1,
        DISPID_SOTDataKey	= ( DISPID_SOTId + 1 ) ,
        DISPID_SOTCategory	= ( DISPID_SOTDataKey + 1 ) ,
        DISPID_SOTGetDescription	= ( DISPID_SOTCategory + 1 ) ,
        DISPID_SOTSetId	= ( DISPID_SOTGetDescription + 1 ) ,
        DISPID_SOTGetAttribute	= ( DISPID_SOTSetId + 1 ) ,
        DISPID_SOTCreateInstance	= ( DISPID_SOTGetAttribute + 1 ) ,
        DISPID_SOTRemove	= ( DISPID_SOTCreateInstance + 1 ) ,
        DISPID_SOTGetStorageFileName	= ( DISPID_SOTRemove + 1 ) ,
        DISPID_SOTRemoveStorageFileName	= ( DISPID_SOTGetStorageFileName + 1 ) ,
        DISPID_SOTIsUISupported	= ( DISPID_SOTRemoveStorageFileName + 1 ) ,
        DISPID_SOTDisplayUI	= ( DISPID_SOTIsUISupported + 1 ) ,
        DISPID_SOTMatchesAttributes	= ( DISPID_SOTDisplayUI + 1 ) 
    } 	DISPID_SpeechObjectToken;

typedef 
enum SpeechDataKeyLocation
    {
        SDKLDefaultLocation	= SPDKL_DefaultLocation,
        SDKLCurrentUser	= SPDKL_CurrentUser,
        SDKLLocalMachine	= SPDKL_LocalMachine,
        SDKLCurrentConfig	= SPDKL_CurrentConfig
    } 	SpeechDataKeyLocation;

typedef 
enum SpeechTokenContext
    {
        STCInprocServer	= CLSCTX_INPROC_SERVER,
        STCInprocHandler	= CLSCTX_INPROC_HANDLER,
        STCLocalServer	= CLSCTX_LOCAL_SERVER,
        STCRemoteServer	= CLSCTX_REMOTE_SERVER,
        STCAll	= ( ( ( CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER )  | CLSCTX_LOCAL_SERVER )  | CLSCTX_REMOTE_SERVER ) 
    } 	SpeechTokenContext;

typedef 
enum SpeechTokenShellFolder
    {
        STSF_AppData	= 0x1a,
        STSF_LocalAppData	= 0x1c,
        STSF_CommonAppData	= 0x23,
        STSF_FlagCreate	= 0x8000
    } 	SpeechTokenShellFolder;

typedef /* [hidden] */ 
enum DISPID_SpeechObjectTokens
    {
        DISPID_SOTsCount	= 1,
        DISPID_SOTsItem	= DISPID_VALUE,
        DISPID_SOTs_NewEnum	= DISPID_NEWENUM
    } 	DISPID_SpeechObjectTokens;

typedef /* [hidden] */ 
enum DISPID_SpeechObjectTokenCategory
    {
        DISPID_SOTCId	= 1,
        DISPID_SOTCDefault	= ( DISPID_SOTCId + 1 ) ,
        DISPID_SOTCSetId	= ( DISPID_SOTCDefault + 1 ) ,
        DISPID_SOTCGetDataKey	= ( DISPID_SOTCSetId + 1 ) ,
        DISPID_SOTCEnumerateTokens	= ( DISPID_SOTCGetDataKey + 1 ) 
    } 	DISPID_SpeechObjectTokenCategory;

typedef 
enum SpeechAudioFormatType
    {
        SAFTDefault	= -1,
        SAFTNoAssignedFormat	= 0,
        SAFTText	= ( SAFTNoAssignedFormat + 1 ) ,
        SAFTNonStandardFormat	= ( SAFTText + 1 ) ,
        SAFTExtendedAudioFormat	= ( SAFTNonStandardFormat + 1 ) ,
        SAFT8kHz8BitMono	= ( SAFTExtendedAudioFormat + 1 ) ,
        SAFT8kHz8BitStereo	= ( SAFT8kHz8BitMono + 1 ) ,
        SAFT8kHz16BitMono	= ( SAFT8kHz8BitStereo + 1 ) ,
        SAFT8kHz16BitStereo	= ( SAFT8kHz16BitMono + 1 ) ,
        SAFT11kHz8BitMono	= ( SAFT8kHz16BitStereo + 1 ) ,
        SAFT11kHz8BitStereo	= ( SAFT11kHz8BitMono + 1 ) ,
        SAFT11kHz16BitMono	= ( SAFT11kHz8BitStereo + 1 ) ,
        SAFT11kHz16BitStereo	= ( SAFT11kHz16BitMono + 1 ) ,
        SAFT12kHz8BitMono	= ( SAFT11kHz16BitStereo + 1 ) ,
        SAFT12kHz8BitStereo	= ( SAFT12kHz8BitMono + 1 ) ,
        SAFT12kHz16BitMono	= ( SAFT12kHz8BitStereo + 1 ) ,
        SAFT12kHz16BitStereo	= ( SAFT12kHz16BitMono + 1 ) ,
        SAFT16kHz8BitMono	= ( SAFT12kHz16BitStereo + 1 ) ,
        SAFT16kHz8BitStereo	= ( SAFT16kHz8BitMono + 1 ) ,
        SAFT16kHz16BitMono	= ( SAFT16kHz8BitStereo + 1 ) ,
        SAFT16kHz16BitStereo	= ( SAFT16kHz16BitMono + 1 ) ,
        SAFT22kHz8BitMono	= ( SAFT16kHz16BitStereo + 1 ) ,
        SAFT22kHz8BitStereo	= ( SAFT22kHz8BitMono + 1 ) ,
        SAFT22kHz16BitMono	= ( SAFT22kHz8BitStereo + 1 ) ,
        SAFT22kHz16BitStereo	= ( SAFT22kHz16BitMono + 1 ) ,
        SAFT24kHz8BitMono	= ( SAFT22kHz16BitStereo + 1 ) ,
        SAFT24kHz8BitStereo	= ( SAFT24kHz8BitMono + 1 ) ,
        SAFT24kHz16BitMono	= ( SAFT24kHz8BitStereo + 1 ) ,
        SAFT24kHz16BitStereo	= ( SAFT24kHz16BitMono + 1 ) ,
        SAFT32kHz8BitMono	= ( SAFT24kHz16BitStereo + 1 ) ,
        SAFT32kHz8BitStereo	= ( SAFT32kHz8BitMono + 1 ) ,
        SAFT32kHz16BitMono	= ( SAFT32kHz8BitStereo + 1 ) ,
        SAFT32kHz16BitStereo	= ( SAFT32kHz16BitMono + 1 ) ,
        SAFT44kHz8BitMono	= ( SAFT32kHz16BitStereo + 1 ) ,
        SAFT44kHz8BitStereo	= ( SAFT44kHz8BitMono + 1 ) ,
        SAFT44kHz16BitMono	= ( SAFT44kHz8BitStereo + 1 ) ,
        SAFT44kHz16BitStereo	= ( SAFT44kHz16BitMono + 1 ) ,
        SAFT48kHz8BitMono	= ( SAFT44kHz16BitStereo + 1 ) ,
        SAFT48kHz8BitStereo	= ( SAFT48kHz8BitMono + 1 ) ,
        SAFT48kHz16BitMono	= ( SAFT48kHz8BitStereo + 1 ) ,
        SAFT48kHz16BitStereo	= ( SAFT48kHz16BitMono + 1 ) ,
        SAFTTrueSpeech_8kHz1BitMono	= ( SAFT48kHz16BitStereo + 1 ) ,
        SAFTCCITT_ALaw_8kHzMono	= ( SAFTTrueSpeech_8kHz1BitMono + 1 ) ,
        SAFTCCITT_ALaw_8kHzStereo	= ( SAFTCCITT_ALaw_8kHzMono + 1 ) ,
        SAFTCCITT_ALaw_11kHzMono	= ( SAFTCCITT_ALaw_8kHzStereo + 1 ) ,
        SAFTCCITT_ALaw_11kHzStereo	= ( SAFTCCITT_ALaw_11kHzMono + 1 ) ,
        SAFTCCITT_ALaw_22kHzMono	= ( SAFTCCITT_ALaw_11kHzStereo + 1 ) ,
        SAFTCCITT_ALaw_22kHzStereo	= ( SAFTCCITT_ALaw_22kHzMono + 1 ) ,
        SAFTCCITT_ALaw_44kHzMono	= ( SAFTCCITT_ALaw_22kHzStereo + 1 ) ,
        SAFTCCITT_ALaw_44kHzStereo	= ( SAFTCCITT_ALaw_44kHzMono + 1 ) ,
        SAFTCCITT_uLaw_8kHzMono	= ( SAFTCCITT_ALaw_44kHzStereo + 1 ) ,
        SAFTCCITT_uLaw_8kHzStereo	= ( SAFTCCITT_uLaw_8kHzMono + 1 ) ,
        SAFTCCITT_uLaw_11kHzMono	= ( SAFTCCITT_uLaw_8kHzStereo + 1 ) ,
        SAFTCCITT_uLaw_11kHzStereo	= ( SAFTCCITT_uLaw_11kHzMono + 1 ) ,
        SAFTCCITT_uLaw_22kHzMono	= ( SAFTCCITT_uLaw_11kHzStereo + 1 ) ,
        SAFTCCITT_uLaw_22kHzStereo	= ( SAFTCCITT_uLaw_22kHzMono + 1 ) ,
        SAFTCCITT_uLaw_44kHzMono	= ( SAFTCCITT_uLaw_22kHzStereo + 1 ) ,
        SAFTCCITT_uLaw_44kHzStereo	= ( SAFTCCITT_uLaw_44kHzMono + 1 ) ,
        SAFTADPCM_8kHzMono	= ( SAFTCCITT_uLaw_44kHzStereo + 1 ) ,
        SAFTADPCM_8kHzStereo	= ( SAFTADPCM_8kHzMono + 1 ) ,
        SAFTADPCM_11kHzMono	= ( SAFTADPCM_8kHzStereo + 1 ) ,
        SAFTADPCM_11kHzStereo	= ( SAFTADPCM_11kHzMono + 1 ) ,
        SAFTADPCM_22kHzMono	= ( SAFTADPCM_11kHzStereo + 1 ) ,
        SAFTADPCM_22kHzStereo	= ( SAFTADPCM_22kHzMono + 1 ) ,
        SAFTADPCM_44kHzMono	= ( SAFTADPCM_22kHzStereo + 1 ) ,
        SAFTADPCM_44kHzStereo	= ( SAFTADPCM_44kHzMono + 1 ) ,
        SAFTGSM610_8kHzMono	= ( SAFTADPCM_44kHzStereo + 1 ) ,
        SAFTGSM610_11kHzMono	= ( SAFTGSM610_8kHzMono + 1 ) ,
        SAFTGSM610_22kHzMono	= ( SAFTGSM610_11kHzMono + 1 ) ,
        SAFTGSM610_44kHzMono	= ( SAFTGSM610_22kHzMono + 1 ) 
    } 	SpeechAudioFormatType;

typedef /* [hidden] */ 
enum DISPID_SpeechAudioFormat
    {
        DISPID_SAFType	= 1,
        DISPID_SAFGuid	= ( DISPID_SAFType + 1 ) ,
        DISPID_SAFGetWaveFormatEx	= ( DISPID_SAFGuid + 1 ) ,
        DISPID_SAFSetWaveFormatEx	= ( DISPID_SAFGetWaveFormatEx + 1 ) 
    } 	DISPID_SpeechAudioFormat;

typedef /* [hidden] */ 
enum DISPID_SpeechBaseStream
    {
        DISPID_SBSFormat	= 1,
        DISPID_SBSRead	= ( DISPID_SBSFormat + 1 ) ,
        DISPID_SBSWrite	= ( DISPID_SBSRead + 1 ) ,
        DISPID_SBSSeek	= ( DISPID_SBSWrite + 1 ) 
    } 	DISPID_SpeechBaseStream;

typedef 
enum SpeechStreamSeekPositionType
    {
        SSSPTRelativeToStart	= STREAM_SEEK_SET,
        SSSPTRelativeToCurrentPosition	= STREAM_SEEK_CUR,
        SSSPTRelativeToEnd	= STREAM_SEEK_END
    } 	SpeechStreamSeekPositionType;

typedef /* [hidden] */ 
enum DISPID_SpeechAudio
    {
        DISPID_SAStatus	= 200,
        DISPID_SABufferInfo	= ( DISPID_SAStatus + 1 ) ,
        DISPID_SADefaultFormat	= ( DISPID_SABufferInfo + 1 ) ,
        DISPID_SAVolume	= ( DISPID_SADefaultFormat + 1 ) ,
        DISPID_SABufferNotifySize	= ( DISPID_SAVolume + 1 ) ,
        DISPID_SAEventHandle	= ( DISPID_SABufferNotifySize + 1 ) ,
        DISPID_SASetState	= ( DISPID_SAEventHandle + 1 ) 
    } 	DISPID_SpeechAudio;

typedef 
enum SpeechAudioState
    {
        SASClosed	= SPAS_CLOSED,
        SASStop	= SPAS_STOP,
        SASPause	= SPAS_PAUSE,
        SASRun	= SPAS_RUN
    } 	SpeechAudioState;

typedef /* [hidden] */ 
enum DISPID_SpeechMMSysAudio
    {
        DISPID_SMSADeviceId	= 300,
        DISPID_SMSALineId	= ( DISPID_SMSADeviceId + 1 ) ,
        DISPID_SMSAMMHandle	= ( DISPID_SMSALineId + 1 ) 
    } 	DISPID_SpeechMMSysAudio;

typedef /* [hidden] */ 
enum DISPID_SpeechFileStream
    {
        DISPID_SFSOpen	= 100,
        DISPID_SFSClose	= ( DISPID_SFSOpen + 1 ) 
    } 	DISPID_SpeechFileStream;

typedef 
enum SpeechStreamFileMode
    {
        SSFMOpenForRead	= SPFM_OPEN_READONLY,
        SSFMOpenReadWrite	= SPFM_OPEN_READWRITE,
        SSFMCreate	= SPFM_CREATE,
        SSFMCreateForWrite	= SPFM_CREATE_ALWAYS
    } 	SpeechStreamFileMode;

typedef /* [hidden] */ 
enum DISPID_SpeechCustomStream
    {
        DISPID_SCSBaseStream	= 100
    } 	DISPID_SpeechCustomStream;

typedef /* [hidden] */ 
enum DISPID_SpeechMemoryStream
    {
        DISPID_SMSSetData	= 100,
        DISPID_SMSGetData	= ( DISPID_SMSSetData + 1 ) 
    } 	DISPID_SpeechMemoryStream;

typedef /* [hidden] */ 
enum DISPID_SpeechAudioStatus
    {
        DISPID_SASFreeBufferSpace	= 1,
        DISPID_SASNonBlockingIO	= ( DISPID_SASFreeBufferSpace + 1 ) ,
        DISPID_SASState	= ( DISPID_SASNonBlockingIO + 1 ) ,
        DISPID_SASCurrentSeekPosition	= ( DISPID_SASState + 1 ) ,
        DISPID_SASCurrentDevicePosition	= ( DISPID_SASCurrentSeekPosition + 1 ) 
    } 	DISPID_SpeechAudioStatus;

typedef /* [hidden] */ 
enum DISPID_SpeechAudioBufferInfo
    {
        DISPID_SABIMinNotification	= 1,
        DISPID_SABIBufferSize	= ( DISPID_SABIMinNotification + 1 ) ,
        DISPID_SABIEventBias	= ( DISPID_SABIBufferSize + 1 ) 
    } 	DISPID_SpeechAudioBufferInfo;

typedef /* [hidden] */ 
enum DISPID_SpeechWaveFormatEx
    {
        DISPID_SWFEFormatTag	= 1,
        DISPID_SWFEChannels	= ( DISPID_SWFEFormatTag + 1 ) ,
        DISPID_SWFESamplesPerSec	= ( DISPID_SWFEChannels + 1 ) ,
        DISPID_SWFEAvgBytesPerSec	= ( DISPID_SWFESamplesPerSec + 1 ) ,
        DISPID_SWFEBlockAlign	= ( DISPID_SWFEAvgBytesPerSec + 1 ) ,
        DISPID_SWFEBitsPerSample	= ( DISPID_SWFEBlockAlign + 1 ) ,
        DISPID_SWFEExtraData	= ( DISPID_SWFEBitsPerSample + 1 ) 
    } 	DISPID_SpeechWaveFormatEx;

typedef /* [hidden] */ 
enum DISPID_SpeechVoice
    {
        DISPID_SVStatus	= 1,
        DISPID_SVVoice	= ( DISPID_SVStatus + 1 ) ,
        DISPID_SVAudioOutput	= ( DISPID_SVVoice + 1 ) ,
        DISPID_SVAudioOutputStream	= ( DISPID_SVAudioOutput + 1 ) ,
        DISPID_SVRate	= ( DISPID_SVAudioOutputStream + 1 ) ,
        DISPID_SVVolume	= ( DISPID_SVRate + 1 ) ,
        DISPID_SVAllowAudioOuputFormatChangesOnNextSet	= ( DISPID_SVVolume + 1 ) ,
        DISPID_SVEventInterests	= ( DISPID_SVAllowAudioOuputFormatChangesOnNextSet + 1 ) ,
        DISPID_SVPriority	= ( DISPID_SVEventInterests + 1 ) ,
        DISPID_SVAlertBoundary	= ( DISPID_SVPriority + 1 ) ,
        DISPID_SVSyncronousSpeakTimeout	= ( DISPID_SVAlertBoundary + 1 ) ,
        DISPID_SVSpeak	= ( DISPID_SVSyncronousSpeakTimeout + 1 ) ,
        DISPID_SVSpeakStream	= ( DISPID_SVSpeak + 1 ) ,
        DISPID_SVPause	= ( DISPID_SVSpeakStream + 1 ) ,
        DISPID_SVResume	= ( DISPID_SVPause + 1 ) ,
        DISPID_SVSkip	= ( DISPID_SVResume + 1 ) ,
        DISPID_SVGetVoices	= ( DISPID_SVSkip + 1 ) ,
        DISPID_SVGetAudioOutputs	= ( DISPID_SVGetVoices + 1 ) ,
        DISPID_SVWaitUntilDone	= ( DISPID_SVGetAudioOutputs + 1 ) ,
        DISPID_SVSpeakCompleteEvent	= ( DISPID_SVWaitUntilDone + 1 ) ,
        DISPID_SVIsUISupported	= ( DISPID_SVSpeakCompleteEvent + 1 ) ,
        DISPID_SVDisplayUI	= ( DISPID_SVIsUISupported + 1 ) 
    } 	DISPID_SpeechVoice;

typedef 
enum SpeechVoicePriority
    {
        SVPNormal	= SPVPRI_NORMAL,
        SVPAlert	= SPVPRI_ALERT,
        SVPOver	= SPVPRI_OVER
    } 	SpeechVoicePriority;

typedef 
enum SpeechVoiceSpeakFlags
    {
        SVSFDefault	= SPF_DEFAULT,
        SVSFlagsAsync	= SPF_ASYNC,
        SVSFPurgeBeforeSpeak	= SPF_PURGEBEFORESPEAK,
        SVSFIsFilename	= SPF_IS_FILENAME,
        SVSFIsXML	= SPF_IS_XML,
        SVSFIsNotXML	= SPF_IS_NOT_XML,
        SVSFPersistXML	= SPF_PERSIST_XML,
        SVSFNLPSpeakPunc	= SPF_NLP_SPEAK_PUNC,
        SVSFNLPMask	= SPF_NLP_MASK,
        SVSFVoiceMask	= SPF_VOICE_MASK,
        SVSFUnusedFlags	= SPF_UNUSED_FLAGS
    } 	SpeechVoiceSpeakFlags;

typedef 
enum SpeechVoiceEvents
    {
        SVEStartInputStream	= ( 1L << 1 ) ,
        SVEEndInputStream	= ( 1L << 2 ) ,
        SVEVoiceChange	= ( 1L << 3 ) ,
        SVEBookmark	= ( 1L << 4 ) ,
        SVEWordBoundary	= ( 1L << 5 ) ,
        SVEPhoneme	= ( 1L << 6 ) ,
        SVESentenceBoundary	= ( 1L << 7 ) ,
        SVEViseme	= ( 1L << 8 ) ,
        SVEAudioLevel	= ( 1L << 9 ) ,
        SVEPrivate	= ( 1L << 15 ) ,
        SVEAllEvents	= 0x83fe
    } 	SpeechVoiceEvents;

typedef /* [hidden] */ 
enum DISPID_SpeechVoiceStatus
    {
        DISPID_SVSCurrentStreamNumber	= 1,
        DISPID_SVSLastStreamNumberQueued	= ( DISPID_SVSCurrentStreamNumber + 1 ) ,
        DISPID_SVSLastResult	= ( DISPID_SVSLastStreamNumberQueued + 1 ) ,
        DISPID_SVSRunningState	= ( DISPID_SVSLastResult + 1 ) ,
        DISPID_SVSInputWordPosition	= ( DISPID_SVSRunningState + 1 ) ,
        DISPID_SVSInputWordLength	= ( DISPID_SVSInputWordPosition + 1 ) ,
        DISPID_SVSInputSentencePosition	= ( DISPID_SVSInputWordLength + 1 ) ,
        DISPID_SVSInputSentenceLength	= ( DISPID_SVSInputSentencePosition + 1 ) ,
        DISPID_SVSLastBookmark	= ( DISPID_SVSInputSentenceLength + 1 ) ,
        DISPID_SVSLastBookmarkId	= ( DISPID_SVSLastBookmark + 1 ) ,
        DISPID_SVSPhonemeId	= ( DISPID_SVSLastBookmarkId + 1 ) ,
        DISPID_SVSVisemeId	= ( DISPID_SVSPhonemeId + 1 ) 
    } 	DISPID_SpeechVoiceStatus;

typedef 
enum SpeechRunState
    {
        SRSEDone	= SPRS_DONE,
        SRSEIsSpeaking	= SPRS_IS_SPEAKING
    } 	SpeechRunState;

typedef 
enum SpeechVisemeType
    {
        SVP_0	= 0,
        SVP_1	= ( SVP_0 + 1 ) ,
        SVP_2	= ( SVP_1 + 1 ) ,
        SVP_3	= ( SVP_2 + 1 ) ,
        SVP_4	= ( SVP_3 + 1 ) ,
        SVP_5	= ( SVP_4 + 1 ) ,
        SVP_6	= ( SVP_5 + 1 ) ,
        SVP_7	= ( SVP_6 + 1 ) ,
        SVP_8	= ( SVP_7 + 1 ) ,
        SVP_9	= ( SVP_8 + 1 ) ,
        SVP_10	= ( SVP_9 + 1 ) ,
        SVP_11	= ( SVP_10 + 1 ) ,
        SVP_12	= ( SVP_11 + 1 ) ,
        SVP_13	= ( SVP_12 + 1 ) ,
        SVP_14	= ( SVP_13 + 1 ) ,
        SVP_15	= ( SVP_14 + 1 ) ,
        SVP_16	= ( SVP_15 + 1 ) ,
        SVP_17	= ( SVP_16 + 1 ) ,
        SVP_18	= ( SVP_17 + 1 ) ,
        SVP_19	= ( SVP_18 + 1 ) ,
        SVP_20	= ( SVP_19 + 1 ) ,
        SVP_21	= ( SVP_20 + 1 ) 
    } 	SpeechVisemeType;

typedef 
enum SpeechVisemeFeature
    {
        SVF_None	= 0,
        SVF_Stressed	= SPVFEATURE_STRESSED,
        SVF_Emphasis	= SPVFEATURE_EMPHASIS
    } 	SpeechVisemeFeature;

typedef /* [hidden] */ 
enum DISPID_SpeechVoiceEvent
    {
        DISPID_SVEStreamStart	= 1,
        DISPID_SVEStreamEnd	= ( DISPID_SVEStreamStart + 1 ) ,
        DISPID_SVEVoiceChange	= ( DISPID_SVEStreamEnd + 1 ) ,
        DISPID_SVEBookmark	= ( DISPID_SVEVoiceChange + 1 ) ,
        DISPID_SVEWord	= ( DISPID_SVEBookmark + 1 ) ,
        DISPID_SVEPhoneme	= ( DISPID_SVEWord + 1 ) ,
        DISPID_SVESentenceBoundary	= ( DISPID_SVEPhoneme + 1 ) ,
        DISPID_SVEViseme	= ( DISPID_SVESentenceBoundary + 1 ) ,
        DISPID_SVEAudioLevel	= ( DISPID_SVEViseme + 1 ) ,
        DISPID_SVEEnginePrivate	= ( DISPID_SVEAudioLevel + 1 ) 
    } 	DISPID_SpeechVoiceEvent;

typedef /* [hidden] */ 
enum DISPID_SpeechRecognizer
    {
        DISPID_SRRecognizer	= 1,
        DISPID_SRAllowAudioInputFormatChangesOnNextSet	= ( DISPID_SRRecognizer + 1 ) ,
        DISPID_SRAudioInput	= ( DISPID_SRAllowAudioInputFormatChangesOnNextSet + 1 ) ,
        DISPID_SRAudioInputStream	= ( DISPID_SRAudioInput + 1 ) ,
        DISPID_SRIsShared	= ( DISPID_SRAudioInputStream + 1 ) ,
        DISPID_SRState	= ( DISPID_SRIsShared + 1 ) ,
        DISPID_SRStatus	= ( DISPID_SRState + 1 ) ,
        DISPID_SRProfile	= ( DISPID_SRStatus + 1 ) ,
        DISPID_SREmulateRecognition	= ( DISPID_SRProfile + 1 ) ,
        DISPID_SRCreateRecoContext	= ( DISPID_SREmulateRecognition + 1 ) ,
        DISPID_SRGetFormat	= ( DISPID_SRCreateRecoContext + 1 ) ,
        DISPID_SRSetPropertyNumber	= ( DISPID_SRGetFormat + 1 ) ,
        DISPID_SRGetPropertyNumber	= ( DISPID_SRSetPropertyNumber + 1 ) ,
        DISPID_SRSetPropertyString	= ( DISPID_SRGetPropertyNumber + 1 ) ,
        DISPID_SRGetPropertyString	= ( DISPID_SRSetPropertyString + 1 ) ,
        DISPID_SRIsUISupported	= ( DISPID_SRGetPropertyString + 1 ) ,
        DISPID_SRDisplayUI	= ( DISPID_SRIsUISupported + 1 ) ,
        DISPID_SRGetRecognizers	= ( DISPID_SRDisplayUI + 1 ) ,
        DISPID_SVGetAudioInputs	= ( DISPID_SRGetRecognizers + 1 ) ,
        DISPID_SVGetProfiles	= ( DISPID_SVGetAudioInputs + 1 ) 
    } 	DISPID_SpeechRecognizer;

typedef 
enum SpeechRecognizerState
    {
        SRSInactive	= SPRST_INACTIVE,
        SRSActive	= SPRST_ACTIVE,
        SRSActiveAlways	= SPRST_ACTIVE_ALWAYS,
        SRSInactiveWithPurge	= SPRST_INACTIVE_WITH_PURGE
    } 	SpeechRecognizerState;

typedef 
enum SpeechDisplayAttributes
    {
        SDA_No_Trailing_Space	= 0,
        SDA_One_Trailing_Space	= SPAF_ONE_TRAILING_SPACE,
        SDA_Two_Trailing_Spaces	= SPAF_TWO_TRAILING_SPACES,
        SDA_Consume_Leading_Spaces	= SPAF_CONSUME_LEADING_SPACES
    } 	SpeechDisplayAttributes;

typedef 
enum SpeechFormatType
    {
        SFTInput	= SPWF_INPUT,
        SFTSREngine	= SPWF_SRENGINE
    } 	SpeechFormatType;

typedef /* [hidden] */ 
enum DISPID_SpeechRecognizerStatus
    {
        DISPID_SRSAudioStatus	= 1,
        DISPID_SRSCurrentStreamPosition	= ( DISPID_SRSAudioStatus + 1 ) ,
        DISPID_SRSCurrentStreamNumber	= ( DISPID_SRSCurrentStreamPosition + 1 ) ,
        DISPID_SRSNumberOfActiveRules	= ( DISPID_SRSCurrentStreamNumber + 1 ) ,
        DISPID_SRSClsidEngine	= ( DISPID_SRSNumberOfActiveRules + 1 ) ,
        DISPID_SRSSupportedLanguages	= ( DISPID_SRSClsidEngine + 1 ) 
    } 	DISPID_SpeechRecognizerStatus;

typedef /* [hidden] */ 
enum DISPID_SpeechRecoContext
    {
        DISPID_SRCRecognizer	= 1,
        DISPID_SRCAudioInInterferenceStatus	= ( DISPID_SRCRecognizer + 1 ) ,
        DISPID_SRCRequestedUIType	= ( DISPID_SRCAudioInInterferenceStatus + 1 ) ,
        DISPID_SRCVoice	= ( DISPID_SRCRequestedUIType + 1 ) ,
        DISPID_SRAllowVoiceFormatMatchingOnNextSet	= ( DISPID_SRCVoice + 1 ) ,
        DISPID_SRCVoicePurgeEvent	= ( DISPID_SRAllowVoiceFormatMatchingOnNextSet + 1 ) ,
        DISPID_SRCEventInterests	= ( DISPID_SRCVoicePurgeEvent + 1 ) ,
        DISPID_SRCCmdMaxAlternates	= ( DISPID_SRCEventInterests + 1 ) ,
        DISPID_SRCState	= ( DISPID_SRCCmdMaxAlternates + 1 ) ,
        DISPID_SRCRetainedAudio	= ( DISPID_SRCState + 1 ) ,
        DISPID_SRCRetainedAudioFormat	= ( DISPID_SRCRetainedAudio + 1 ) ,
        DISPID_SRCPause	= ( DISPID_SRCRetainedAudioFormat + 1 ) ,
        DISPID_SRCResume	= ( DISPID_SRCPause + 1 ) ,
        DISPID_SRCCreateGrammar	= ( DISPID_SRCResume + 1 ) ,
        DISPID_SRCCreateResultFromMemory	= ( DISPID_SRCCreateGrammar + 1 ) ,
        DISPID_SRCBookmark	= ( DISPID_SRCCreateResultFromMemory + 1 ) ,
        DISPID_SRCSetAdaptationData	= ( DISPID_SRCBookmark + 1 ) 
    } 	DISPID_SpeechRecoContext;

typedef 
enum SpeechRetainedAudioOptions
    {
        SRAONone	= SPAO_NONE,
        SRAORetainAudio	= SPAO_RETAIN_AUDIO
    } 	SpeechRetainedAudioOptions;

typedef 
enum SpeechBookmarkOptions
    {
        SBONone	= SPBO_NONE,
        SBOPause	= SPBO_PAUSE
    } 	SpeechBookmarkOptions;

typedef 
enum SpeechInterference
    {
        SINone	= SPINTERFERENCE_NONE,
        SINoise	= SPINTERFERENCE_NOISE,
        SINoSignal	= SPINTERFERENCE_NOSIGNAL,
        SITooLoud	= SPINTERFERENCE_TOOLOUD,
        SITooQuiet	= SPINTERFERENCE_TOOQUIET,
        SITooFast	= SPINTERFERENCE_TOOFAST,
        SITooSlow	= SPINTERFERENCE_TOOSLOW
    } 	SpeechInterference;

typedef 
enum SpeechRecoEvents
    {
        SREStreamEnd	= ( 1L << 0 ) ,
        SRESoundStart	= ( 1L << 1 ) ,
        SRESoundEnd	= ( 1L << 2 ) ,
        SREPhraseStart	= ( 1L << 3 ) ,
        SRERecognition	= ( 1L << 4 ) ,
        SREHypothesis	= ( 1L << 5 ) ,
        SREBookmark	= ( 1L << 6 ) ,
        SREPropertyNumChange	= ( 1L << 7 ) ,
        SREPropertyStringChange	= ( 1L << 8 ) ,
        SREFalseRecognition	= ( 1L << 9 ) ,
        SREInterference	= ( 1L << 10 ) ,
        SRERequestUI	= ( 1L << 11 ) ,
        SREStateChange	= ( 1L << 12 ) ,
        SREAdaptation	= ( 1L << 13 ) ,
        SREStreamStart	= ( 1L << 14 ) ,
        SRERecoOtherContext	= ( 1L << 15 ) ,
        SREAudioLevel	= ( 1L << 16 ) ,
        SREPrivate	= ( 1L << 18 ) ,
        SREAllEvents	= 0x5ffff
    } 	SpeechRecoEvents;

typedef 
enum SpeechRecoContextState
    {
        SRCS_Disabled	= SPCS_DISABLED,
        SRCS_Enabled	= SPCS_ENABLED
    } 	SpeechRecoContextState;

typedef /* [hidden] */ 
enum DISPIDSPRG
    {
        DISPID_SRGId	= 1,
        DISPID_SRGRecoContext	= ( DISPID_SRGId + 1 ) ,
        DISPID_SRGState	= ( DISPID_SRGRecoContext + 1 ) ,
        DISPID_SRGRules	= ( DISPID_SRGState + 1 ) ,
        DISPID_SRGReset	= ( DISPID_SRGRules + 1 ) ,
        DISPID_SRGCommit	= ( DISPID_SRGReset + 1 ) ,
        DISPID_SRGCmdLoadFromFile	= ( DISPID_SRGCommit + 1 ) ,
        DISPID_SRGCmdLoadFromObject	= ( DISPID_SRGCmdLoadFromFile + 1 ) ,
        DISPID_SRGCmdLoadFromResource	= ( DISPID_SRGCmdLoadFromObject + 1 ) ,
        DISPID_SRGCmdLoadFromMemory	= ( DISPID_SRGCmdLoadFromResource + 1 ) ,
        DISPID_SRGCmdLoadFromProprietaryGrammar	= ( DISPID_SRGCmdLoadFromMemory + 1 ) ,
        DISPID_SRGCmdSetRuleState	= ( DISPID_SRGCmdLoadFromProprietaryGrammar + 1 ) ,
        DISPID_SRGCmdSetRuleIdState	= ( DISPID_SRGCmdSetRuleState + 1 ) ,
        DISPID_SRGDictationLoad	= ( DISPID_SRGCmdSetRuleIdState + 1 ) ,
        DISPID_SRGDictationUnload	= ( DISPID_SRGDictationLoad + 1 ) ,
        DISPID_SRGDictationSetState	= ( DISPID_SRGDictationUnload + 1 ) ,
        DISPID_SRGSetWordSequenceData	= ( DISPID_SRGDictationSetState + 1 ) ,
        DISPID_SRGSetTextSelection	= ( DISPID_SRGSetWordSequenceData + 1 ) ,
        DISPID_SRGIsPronounceable	= ( DISPID_SRGSetTextSelection + 1 ) 
    } 	DISPIDSPRG;

typedef 
enum SpeechLoadOption
    {
        SLOStatic	= SPLO_STATIC,
        SLODynamic	= SPLO_DYNAMIC
    } 	SpeechLoadOption;

typedef 
enum SpeechWordPronounceable
    {
        SWPUnknownWordUnpronounceable	= SPWP_UNKNOWN_WORD_UNPRONOUNCEABLE,
        SWPUnknownWordPronounceable	= SPWP_UNKNOWN_WORD_PRONOUNCEABLE,
        SWPKnownWordPronounceable	= SPWP_KNOWN_WORD_PRONOUNCEABLE
    } 	SpeechWordPronounceable;

typedef 
enum SpeechGrammarState
    {
        SGSEnabled	= SPGS_ENABLED,
        SGSDisabled	= SPGS_DISABLED,
        SGSExclusive	= SPGS_EXCLUSIVE
    } 	SpeechGrammarState;

typedef 
enum SpeechRuleState
    {
        SGDSInactive	= SPRS_INACTIVE,
        SGDSActive	= SPRS_ACTIVE,
        SGDSActiveWithAutoPause	= SPRS_ACTIVE_WITH_AUTO_PAUSE
    } 	SpeechRuleState;

typedef 
enum SpeechRuleAttributes
    {
        SRATopLevel	= SPRAF_TopLevel,
        SRADefaultToActive	= SPRAF_Active,
        SRAExport	= SPRAF_Export,
        SRAImport	= SPRAF_Import,
        SRAInterpreter	= SPRAF_Interpreter,
        SRADynamic	= SPRAF_Dynamic
    } 	SpeechRuleAttributes;

typedef 
enum SpeechGrammarWordType
    {
        SGDisplay	= SPWT_DISPLAY,
        SGLexical	= SPWT_LEXICAL,
        SGPronounciation	= SPWT_PRONUNCIATION
    } 	SpeechGrammarWordType;

typedef /* [hidden] */ 
enum DISPID_SpeechRecoContextEvents
    {
        DISPID_SRCEStartStream	= 1,
        DISPID_SRCEEndStream	= ( DISPID_SRCEStartStream + 1 ) ,
        DISPID_SRCEBookmark	= ( DISPID_SRCEEndStream + 1 ) ,
        DISPID_SRCESoundStart	= ( DISPID_SRCEBookmark + 1 ) ,
        DISPID_SRCESoundEnd	= ( DISPID_SRCESoundStart + 1 ) ,
        DISPID_SRCEPhraseStart	= ( DISPID_SRCESoundEnd + 1 ) ,
        DISPID_SRCERecognition	= ( DISPID_SRCEPhraseStart + 1 ) ,
        DISPID_SRCEHypothesis	= ( DISPID_SRCERecognition + 1 ) ,
        DISPID_SRCEPropertyNumberChange	= ( DISPID_SRCEHypothesis + 1 ) ,
        DISPID_SRCEPropertyStringChange	= ( DISPID_SRCEPropertyNumberChange + 1 ) ,
        DISPID_SRCEFalseRecognition	= ( DISPID_SRCEPropertyStringChange + 1 ) ,
        DISPID_SRCEInterference	= ( DISPID_SRCEFalseRecognition + 1 ) ,
        DISPID_SRCERequestUI	= ( DISPID_SRCEInterference + 1 ) ,
        DISPID_SRCERecognizerStateChange	= ( DISPID_SRCERequestUI + 1 ) ,
        DISPID_SRCEAdaptation	= ( DISPID_SRCERecognizerStateChange + 1 ) ,
        DISPID_SRCERecognitionForOtherContext	= ( DISPID_SRCEAdaptation + 1 ) ,
        DISPID_SRCEAudioLevel	= ( DISPID_SRCERecognitionForOtherContext + 1 ) ,
        DISPID_SRCEEnginePrivate	= ( DISPID_SRCEAudioLevel + 1 ) 
    } 	DISPID_SpeechRecoContextEvents;

typedef 
enum SpeechRecognitionType
    {
        SRTStandard	= 0,
        SRTAutopause	= SPREF_AutoPause,
        SRTEmulated	= SPREF_Emulated
    } 	SpeechRecognitionType;

typedef /* [hidden] */ 
enum DISPID_SpeechGrammarRule
    {
        DISPID_SGRAttributes	= 1,
        DISPID_SGRInitialState	= ( DISPID_SGRAttributes + 1 ) ,
        DISPID_SGRName	= ( DISPID_SGRInitialState + 1 ) ,
        DISPID_SGRId	= ( DISPID_SGRName + 1 ) ,
        DISPID_SGRClear	= ( DISPID_SGRId + 1 ) ,
        DISPID_SGRAddResource	= ( DISPID_SGRClear + 1 ) ,
        DISPID_SGRAddState	= ( DISPID_SGRAddResource + 1 ) 
    } 	DISPID_SpeechGrammarRule;

typedef /* [hidden] */ 
enum DISPID_SpeechGrammarRules
    {
        DISPID_SGRsCount	= 1,
        DISPID_SGRsDynamic	= ( DISPID_SGRsCount + 1 ) ,
        DISPID_SGRsAdd	= ( DISPID_SGRsDynamic + 1 ) ,
        DISPID_SGRsCommit	= ( DISPID_SGRsAdd + 1 ) ,
        DISPID_SGRsCommitAndSave	= ( DISPID_SGRsCommit + 1 ) ,
        DISPID_SGRsFindRule	= ( DISPID_SGRsCommitAndSave + 1 ) ,
        DISPID_SGRsItem	= DISPID_VALUE,
        DISPID_SGRs_NewEnum	= DISPID_NEWENUM
    } 	DISPID_SpeechGrammarRules;

typedef /* [hidden] */ 
enum DISPID_SpeechGrammarRuleState
    {
        DISPID_SGRSRule	= 1,
        DISPID_SGRSTransitions	= ( DISPID_SGRSRule + 1 ) ,
        DISPID_SGRSAddWordTransition	= ( DISPID_SGRSTransitions + 1 ) ,
        DISPID_SGRSAddRuleTransition	= ( DISPID_SGRSAddWordTransition + 1 ) ,
        DISPID_SGRSAddSpecialTransition	= ( DISPID_SGRSAddRuleTransition + 1 ) 
    } 	DISPID_SpeechGrammarRuleState;

typedef 
enum SpeechSpecialTransitionType
    {
        SSTTWildcard	= 1,
        SSTTDictation	= ( SSTTWildcard + 1 ) ,
        SSTTTextBuffer	= ( SSTTDictation + 1 ) 
    } 	SpeechSpecialTransitionType;

typedef /* [hidden] */ 
enum DISPID_SpeechGrammarRuleStateTransitions
    {
        DISPID_SGRSTsCount	= 1,
        DISPID_SGRSTsItem	= DISPID_VALUE,
        DISPID_SGRSTs_NewEnum	= DISPID_NEWENUM
    } 	DISPID_SpeechGrammarRuleStateTransitions;

typedef /* [hidden] */ 
enum DISPID_SpeechGrammarRuleStateTransition
    {
        DISPID_SGRSTType	= 1,
        DISPID_SGRSTText	= ( DISPID_SGRSTType + 1 ) ,
        DISPID_SGRSTRule	= ( DISPID_SGRSTText + 1 ) ,
        DISPID_SGRSTWeight	= ( DISPID_SGRSTRule + 1 ) ,
        DISPID_SGRSTPropertyName	= ( DISPID_SGRSTWeight + 1 ) ,
        DISPID_SGRSTPropertyId	= ( DISPID_SGRSTPropertyName + 1 ) ,
        DISPID_SGRSTPropertyValue	= ( DISPID_SGRSTPropertyId + 1 ) ,
        DISPID_SGRSTNextState	= ( DISPID_SGRSTPropertyValue + 1 ) 
    } 	DISPID_SpeechGrammarRuleStateTransition;

typedef 
enum SpeechGrammarRuleStateTransitionType
    {
        SGRSTTEpsilon	= 0,
        SGRSTTWord	= ( SGRSTTEpsilon + 1 ) ,
        SGRSTTRule	= ( SGRSTTWord + 1 ) ,
        SGRSTTDictation	= ( SGRSTTRule + 1 ) ,
        SGRSTTWildcard	= ( SGRSTTDictation + 1 ) ,
        SGRSTTTextBuffer	= ( SGRSTTWildcard + 1 ) 
    } 	SpeechGrammarRuleStateTransitionType;

typedef /* [hidden] */ 
enum DISPIDSPTSI
    {
        DISPIDSPTSI_ActiveOffset	= 1,
        DISPIDSPTSI_ActiveLength	= ( DISPIDSPTSI_ActiveOffset + 1 ) ,
        DISPIDSPTSI_SelectionOffset	= ( DISPIDSPTSI_ActiveLength + 1 ) ,
        DISPIDSPTSI_SelectionLength	= ( DISPIDSPTSI_SelectionOffset + 1 ) 
    } 	DISPIDSPTSI;

typedef /* [hidden] */ 
enum DISPID_SpeechRecoResult
    {
        DISPID_SRRRecoContext	= 1,
        DISPID_SRRTimes	= ( DISPID_SRRRecoContext + 1 ) ,
        DISPID_SRRAudioFormat	= ( DISPID_SRRTimes + 1 ) ,
        DISPID_SRRPhraseInfo	= ( DISPID_SRRAudioFormat + 1 ) ,
        DISPID_SRRAlternates	= ( DISPID_SRRPhraseInfo + 1 ) ,
        DISPID_SRRAudio	= ( DISPID_SRRAlternates + 1 ) ,
        DISPID_SRRSpeakAudio	= ( DISPID_SRRAudio + 1 ) ,
        DISPID_SRRSaveToMemory	= ( DISPID_SRRSpeakAudio + 1 ) ,
        DISPID_SRRDiscardResultInfo	= ( DISPID_SRRSaveToMemory + 1 ) 
    } 	DISPID_SpeechRecoResult;

typedef 
enum SpeechDiscardType
    {
        SDTProperty	= SPDF_PROPERTY,
        SDTReplacement	= SPDF_REPLACEMENT,
        SDTRule	= SPDF_RULE,
        SDTDisplayText	= SPDF_DISPLAYTEXT,
        SDTLexicalForm	= SPDF_LEXICALFORM,
        SDTPronunciation	= SPDF_PRONUNCIATION,
        SDTAudio	= SPDF_AUDIO,
        SDTAlternates	= SPDF_ALTERNATES,
        SDTAll	= SPDF_ALL
    } 	SpeechDiscardType;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseBuilder
    {
        DISPID_SPPBRestorePhraseFromMemory	= 1
    } 	DISPID_SpeechPhraseBuilder;

typedef /* [hidden] */ 
enum DISPID_SpeechRecoResultTimes
    {
        DISPID_SRRTStreamTime	= 1,
        DISPID_SRRTLength	= ( DISPID_SRRTStreamTime + 1 ) ,
        DISPID_SRRTTickCount	= ( DISPID_SRRTLength + 1 ) ,
        DISPID_SRRTOffsetFromStart	= ( DISPID_SRRTTickCount + 1 ) 
    } 	DISPID_SpeechRecoResultTimes;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseAlternate
    {
        DISPID_SPARecoResult	= 1,
        DISPID_SPAStartElementInResult	= ( DISPID_SPARecoResult + 1 ) ,
        DISPID_SPANumberOfElementsInResult	= ( DISPID_SPAStartElementInResult + 1 ) ,
        DISPID_SPAPhraseInfo	= ( DISPID_SPANumberOfElementsInResult + 1 ) ,
        DISPID_SPACommit	= ( DISPID_SPAPhraseInfo + 1 ) 
    } 	DISPID_SpeechPhraseAlternate;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseAlternates
    {
        DISPID_SPAsCount	= 1,
        DISPID_SPAsItem	= DISPID_VALUE,
        DISPID_SPAs_NewEnum	= DISPID_NEWENUM
    } 	DISPID_SpeechPhraseAlternates;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseInfo
    {
        DISPID_SPILanguageId	= 1,
        DISPID_SPIGrammarId	= ( DISPID_SPILanguageId + 1 ) ,
        DISPID_SPIStartTime	= ( DISPID_SPIGrammarId + 1 ) ,
        DISPID_SPIAudioStreamPosition	= ( DISPID_SPIStartTime + 1 ) ,
        DISPID_SPIAudioSizeBytes	= ( DISPID_SPIAudioStreamPosition + 1 ) ,
        DISPID_SPIRetainedSizeBytes	= ( DISPID_SPIAudioSizeBytes + 1 ) ,
        DISPID_SPIAudioSizeTime	= ( DISPID_SPIRetainedSizeBytes + 1 ) ,
        DISPID_SPIRule	= ( DISPID_SPIAudioSizeTime + 1 ) ,
        DISPID_SPIProperties	= ( DISPID_SPIRule + 1 ) ,
        DISPID_SPIElements	= ( DISPID_SPIProperties + 1 ) ,
        DISPID_SPIReplacements	= ( DISPID_SPIElements + 1 ) ,
        DISPID_SPIEngineId	= ( DISPID_SPIReplacements + 1 ) ,
        DISPID_SPIEnginePrivateData	= ( DISPID_SPIEngineId + 1 ) ,
        DISPID_SPISaveToMemory	= ( DISPID_SPIEnginePrivateData + 1 ) ,
        DISPID_SPIGetText	= ( DISPID_SPISaveToMemory + 1 ) ,
        DISPID_SPIGetDisplayAttributes	= ( DISPID_SPIGetText + 1 ) 
    } 	DISPID_SpeechPhraseInfo;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseElement
    {
        DISPID_SPEAudioTimeOffset	= 1,
        DISPID_SPEAudioSizeTime	= ( DISPID_SPEAudioTimeOffset + 1 ) ,
        DISPID_SPEAudioStreamOffset	= ( DISPID_SPEAudioSizeTime + 1 ) ,
        DISPID_SPEAudioSizeBytes	= ( DISPID_SPEAudioStreamOffset + 1 ) ,
        DISPID_SPERetainedStreamOffset	= ( DISPID_SPEAudioSizeBytes + 1 ) ,
        DISPID_SPERetainedSizeBytes	= ( DISPID_SPERetainedStreamOffset + 1 ) ,
        DISPID_SPEDisplayText	= ( DISPID_SPERetainedSizeBytes + 1 ) ,
        DISPID_SPELexicalForm	= ( DISPID_SPEDisplayText + 1 ) ,
        DISPID_SPEPronunciation	= ( DISPID_SPELexicalForm + 1 ) ,
        DISPID_SPEDisplayAttributes	= ( DISPID_SPEPronunciation + 1 ) ,
        DISPID_SPERequiredConfidence	= ( DISPID_SPEDisplayAttributes + 1 ) ,
        DISPID_SPEActualConfidence	= ( DISPID_SPERequiredConfidence + 1 ) ,
        DISPID_SPEEngineConfidence	= ( DISPID_SPEActualConfidence + 1 ) 
    } 	DISPID_SpeechPhraseElement;

typedef 
enum SpeechEngineConfidence
    {
        SECLowConfidence	= -1,
        SECNormalConfidence	= 0,
        SECHighConfidence	= 1
    } 	SpeechEngineConfidence;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseElements
    {
        DISPID_SPEsCount	= 1,
        DISPID_SPEsItem	= DISPID_VALUE,
        DISPID_SPEs_NewEnum	= DISPID_NEWENUM
    } 	DISPID_SpeechPhraseElements;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseReplacement
    {
        DISPID_SPRDisplayAttributes	= 1,
        DISPID_SPRText	= ( DISPID_SPRDisplayAttributes + 1 ) ,
        DISPID_SPRFirstElement	= ( DISPID_SPRText + 1 ) ,
        DISPID_SPRNumberOfElements	= ( DISPID_SPRFirstElement + 1 ) 
    } 	DISPID_SpeechPhraseReplacement;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseReplacements
    {
        DISPID_SPRsCount	= 1,
        DISPID_SPRsItem	= DISPID_VALUE,
        DISPID_SPRs_NewEnum	= DISPID_NEWENUM
    } 	DISPID_SpeechPhraseReplacements;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseProperty
    {
        DISPID_SPPName	= 1,
        DISPID_SPPId	= ( DISPID_SPPName + 1 ) ,
        DISPID_SPPValue	= ( DISPID_SPPId + 1 ) ,
        DISPID_SPPFirstElement	= ( DISPID_SPPValue + 1 ) ,
        DISPID_SPPNumberOfElements	= ( DISPID_SPPFirstElement + 1 ) ,
        DISPID_SPPEngineConfidence	= ( DISPID_SPPNumberOfElements + 1 ) ,
        DISPID_SPPConfidence	= ( DISPID_SPPEngineConfidence + 1 ) ,
        DISPID_SPPParent	= ( DISPID_SPPConfidence + 1 ) ,
        DISPID_SPPChildren	= ( DISPID_SPPParent + 1 ) 
    } 	DISPID_SpeechPhraseProperty;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseProperties
    {
        DISPID_SPPsCount	= 1,
        DISPID_SPPsItem	= DISPID_VALUE,
        DISPID_SPPs_NewEnum	= DISPID_NEWENUM
    } 	DISPID_SpeechPhraseProperties;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseRule
    {
        DISPID_SPRuleName	= 1,
        DISPID_SPRuleId	= ( DISPID_SPRuleName + 1 ) ,
        DISPID_SPRuleFirstElement	= ( DISPID_SPRuleId + 1 ) ,
        DISPID_SPRuleNumberOfElements	= ( DISPID_SPRuleFirstElement + 1 ) ,
        DISPID_SPRuleParent	= ( DISPID_SPRuleNumberOfElements + 1 ) ,
        DISPID_SPRuleChildren	= ( DISPID_SPRuleParent + 1 ) ,
        DISPID_SPRuleConfidence	= ( DISPID_SPRuleChildren + 1 ) ,
        DISPID_SPRuleEngineConfidence	= ( DISPID_SPRuleConfidence + 1 ) 
    } 	DISPID_SpeechPhraseRule;

typedef /* [hidden] */ 
enum DISPID_SpeechPhraseRules
    {
        DISPID_SPRulesCount	= 1,
        DISPID_SPRulesItem	= DISPID_VALUE,
        DISPID_SPRules_NewEnum	= DISPID_NEWENUM
    } 	DISPID_SpeechPhraseRules;

typedef /* [hidden] */ 
enum DISPID_SpeechLexicon
    {
        DISPID_SLGenerationId	= 1,
        DISPID_SLGetWords	= ( DISPID_SLGenerationId + 1 ) ,
        DISPID_SLAddPronunciation	= ( DISPID_SLGetWords + 1 ) ,
        DISPID_SLAddPronunciationByPhoneIds	= ( DISPID_SLAddPronunciation + 1 ) ,
        DISPID_SLRemovePronunciation	= ( DISPID_SLAddPronunciationByPhoneIds + 1 ) ,
        DISPID_SLRemovePronunciationByPhoneIds	= ( DISPID_SLRemovePronunciation + 1 ) ,
        DISPID_SLGetPronunciations	= ( DISPID_SLRemovePronunciationByPhoneIds + 1 ) ,
        DISPID_SLGetGenerationChange	= ( DISPID_SLGetPronunciations + 1 ) 
    } 	DISPID_SpeechLexicon;

typedef 
enum SpeechLexiconType
    {
        SLTUser	= eLEXTYPE_USER,
        SLTApp	= eLEXTYPE_APP
    } 	SpeechLexiconType;

typedef 
enum SpeechPartOfSpeech
    {
        SPSNotOverriden	= SPPS_NotOverriden,
        SPSUnknown	= SPPS_Unknown,
        SPSNoun	= SPPS_Noun,
        SPSVerb	= SPPS_Verb,
        SPSModifier	= SPPS_Modifier,
        SPSFunction	= SPPS_Function,
        SPSInterjection	= SPPS_Interjection
    } 	SpeechPartOfSpeech;

typedef /* [hidden] */ 
enum DISPID_SpeechLexiconWords
    {
        DISPID_SLWsCount	= 1,
        DISPID_SLWsItem	= DISPID_VALUE,
        DISPID_SLWs_NewEnum	= DISPID_NEWENUM
    } 	DISPID_SpeechLexiconWords;

typedef 
enum SpeechWordType
    {
        SWTAdded	= eWORDTYPE_ADDED,
        SWTDeleted	= eWORDTYPE_DELETED
    } 	SpeechWordType;

typedef /* [hidden] */ 
enum DISPID_SpeechLexiconWord
    {
        DISPID_SLWLangId	= 1,
        DISPID_SLWType	= ( DISPID_SLWLangId + 1 ) ,
        DISPID_SLWWord	= ( DISPID_SLWType + 1 ) ,
        DISPID_SLWPronunciations	= ( DISPID_SLWWord + 1 ) 
    } 	DISPID_SpeechLexiconWord;

typedef /* [hidden] */ 
enum DISPID_SpeechLexiconProns
    {
        DISPID_SLPsCount	= 1,
        DISPID_SLPsItem	= DISPID_VALUE,
        DISPID_SLPs_NewEnum	= DISPID_NEWENUM
    } 	DISPID_SpeechLexiconProns;

typedef /* [hidden] */ 
enum DISPID_SpeechLexiconPronunciation
    {
        DISPID_SLPType	= 1,
        DISPID_SLPLangId	= ( DISPID_SLPType + 1 ) ,
        DISPID_SLPPartOfSpeech	= ( DISPID_SLPLangId + 1 ) ,
        DISPID_SLPPhoneIds	= ( DISPID_SLPPartOfSpeech + 1 ) ,
        DISPID_SLPSymbolic	= ( DISPID_SLPPhoneIds + 1 ) 
    } 	DISPID_SpeechLexiconPronunciation;

typedef /* [hidden] */ 
enum DISPID_SpeechPhoneConverter
    {
        DISPID_SPCLangId	= 1,
        DISPID_SPCPhoneToId	= ( DISPID_SPCLangId + 1 ) ,
        DISPID_SPCIdToPhone	= ( DISPID_SPCPhoneToId + 1 ) 
    } 	DISPID_SpeechPhoneConverter;

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

EXTERN_C const IID LIBID_SpeechLib;

#ifndef __ISpeechDataKey_INTERFACE_DEFINED__
#define __ISpeechDataKey_INTERFACE_DEFINED__

/* interface ISpeechDataKey */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechDataKey;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CE17C09B-4EFA-44d5-A4C9-59D9585AB0CD")
    ISpeechDataKey : public IDispatch
    {
    public:
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SetBinaryValue( 
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [in] */ VARIANT Value) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetBinaryValue( 
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [retval][out] */ __RPC__out VARIANT *Value) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SetStringValue( 
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [in] */ __RPC__in const BSTR Value) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetStringValue( 
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Value) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SetLongValue( 
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [in] */ long Value) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetLongValue( 
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [retval][out] */ __RPC__out long *Value) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE OpenKey( 
            /* [in] */ __RPC__in const BSTR SubKeyName,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechDataKey **SubKey) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CreateKey( 
            /* [in] */ __RPC__in const BSTR SubKeyName,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechDataKey **SubKey) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE DeleteKey( 
            /* [in] */ __RPC__in const BSTR SubKeyName) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE DeleteValue( 
            /* [in] */ __RPC__in const BSTR ValueName) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE EnumKeys( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *SubKeyName) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE EnumValues( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *ValueName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechDataKeyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechDataKey * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechDataKey * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechDataKey * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechDataKey * This,
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
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetBinaryValue )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [in] */ VARIANT Value);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetBinaryValue )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [retval][out] */ __RPC__out VARIANT *Value);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetStringValue )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [in] */ __RPC__in const BSTR Value);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetStringValue )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Value);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetLongValue )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [in] */ long Value);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLongValue )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in const BSTR ValueName,
            /* [retval][out] */ __RPC__out long *Value);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenKey )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in const BSTR SubKeyName,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechDataKey **SubKey);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateKey )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in const BSTR SubKeyName,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechDataKey **SubKey);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteKey )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in const BSTR SubKeyName);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteValue )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ __RPC__in const BSTR ValueName);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *SubKeyName);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            __RPC__in ISpeechDataKey * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *ValueName);
        
        END_INTERFACE
    } ISpeechDataKeyVtbl;

    interface ISpeechDataKey
    {
        CONST_VTBL struct ISpeechDataKeyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechDataKey_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechDataKey_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechDataKey_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechDataKey_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechDataKey_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechDataKey_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechDataKey_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechDataKey_SetBinaryValue(This,ValueName,Value)	\
    ( (This)->lpVtbl -> SetBinaryValue(This,ValueName,Value) ) 

#define ISpeechDataKey_GetBinaryValue(This,ValueName,Value)	\
    ( (This)->lpVtbl -> GetBinaryValue(This,ValueName,Value) ) 

#define ISpeechDataKey_SetStringValue(This,ValueName,Value)	\
    ( (This)->lpVtbl -> SetStringValue(This,ValueName,Value) ) 

#define ISpeechDataKey_GetStringValue(This,ValueName,Value)	\
    ( (This)->lpVtbl -> GetStringValue(This,ValueName,Value) ) 

#define ISpeechDataKey_SetLongValue(This,ValueName,Value)	\
    ( (This)->lpVtbl -> SetLongValue(This,ValueName,Value) ) 

#define ISpeechDataKey_GetLongValue(This,ValueName,Value)	\
    ( (This)->lpVtbl -> GetLongValue(This,ValueName,Value) ) 

#define ISpeechDataKey_OpenKey(This,SubKeyName,SubKey)	\
    ( (This)->lpVtbl -> OpenKey(This,SubKeyName,SubKey) ) 

#define ISpeechDataKey_CreateKey(This,SubKeyName,SubKey)	\
    ( (This)->lpVtbl -> CreateKey(This,SubKeyName,SubKey) ) 

#define ISpeechDataKey_DeleteKey(This,SubKeyName)	\
    ( (This)->lpVtbl -> DeleteKey(This,SubKeyName) ) 

#define ISpeechDataKey_DeleteValue(This,ValueName)	\
    ( (This)->lpVtbl -> DeleteValue(This,ValueName) ) 

#define ISpeechDataKey_EnumKeys(This,Index,SubKeyName)	\
    ( (This)->lpVtbl -> EnumKeys(This,Index,SubKeyName) ) 

#define ISpeechDataKey_EnumValues(This,Index,ValueName)	\
    ( (This)->lpVtbl -> EnumValues(This,Index,ValueName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechDataKey_INTERFACE_DEFINED__ */


#ifndef __ISpeechObjectToken_INTERFACE_DEFINED__
#define __ISpeechObjectToken_INTERFACE_DEFINED__

/* interface ISpeechObjectToken */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechObjectToken;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C74A3ADC-B727-4500-A84A-B526721C8B8C")
    ISpeechObjectToken : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *ObjectId) = 0;
        
        virtual /* [hidden][id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DataKey( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechDataKey **DataKey) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Category( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokenCategory **Category) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [defaultvalue][in] */ long Locale,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Description) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE SetId( 
            /* [in] */ __RPC__in BSTR Id,
            /* [defaultvalue][in] */ __RPC__in BSTR CategoryID = (BSTR)L"",
            /* [defaultvalue][in] */ VARIANT_BOOL CreateIfNotExist = 0) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetAttribute( 
            /* [in] */ __RPC__in BSTR AttributeName,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *AttributeValue) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CreateInstance( 
            /* [defaultvalue][in] */ __RPC__in_opt IUnknown *pUnkOuter,
            /* [defaultvalue][in] */ SpeechTokenContext ClsContext,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **Object) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ __RPC__in BSTR ObjectStorageCLSID) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetStorageFileName( 
            /* [in] */ __RPC__in BSTR ObjectStorageCLSID,
            /* [in] */ __RPC__in BSTR KeyName,
            /* [in] */ __RPC__in BSTR FileName,
            /* [in] */ SpeechTokenShellFolder Folder,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *FilePath) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE RemoveStorageFileName( 
            /* [in] */ __RPC__in BSTR ObjectStorageCLSID,
            /* [in] */ __RPC__in BSTR KeyName,
            /* [in] */ VARIANT_BOOL DeleteFile) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData,
            /* [defaultvalue][in] */ __RPC__in_opt IUnknown *Object,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [in] */ long hWnd,
            /* [in] */ __RPC__in BSTR Title,
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData = 0,
            /* [defaultvalue][in] */ __RPC__in_opt IUnknown *Object = 0) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE MatchesAttributes( 
            /* [in] */ __RPC__in BSTR Attributes,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Matches) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechObjectTokenVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechObjectToken * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechObjectToken * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechObjectToken * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechObjectToken * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechObjectToken * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechObjectToken * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechObjectToken * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in ISpeechObjectToken * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *ObjectId);
        
        /* [hidden][id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataKey )( 
            __RPC__in ISpeechObjectToken * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechDataKey **DataKey);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            __RPC__in ISpeechObjectToken * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokenCategory **Category);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            __RPC__in ISpeechObjectToken * This,
            /* [defaultvalue][in] */ long Locale,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Description);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetId )( 
            __RPC__in ISpeechObjectToken * This,
            /* [in] */ __RPC__in BSTR Id,
            /* [defaultvalue][in] */ __RPC__in BSTR CategoryID,
            /* [defaultvalue][in] */ VARIANT_BOOL CreateIfNotExist);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAttribute )( 
            __RPC__in ISpeechObjectToken * This,
            /* [in] */ __RPC__in BSTR AttributeName,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *AttributeValue);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateInstance )( 
            __RPC__in ISpeechObjectToken * This,
            /* [defaultvalue][in] */ __RPC__in_opt IUnknown *pUnkOuter,
            /* [defaultvalue][in] */ SpeechTokenContext ClsContext,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **Object);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in ISpeechObjectToken * This,
            /* [in] */ __RPC__in BSTR ObjectStorageCLSID);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetStorageFileName )( 
            __RPC__in ISpeechObjectToken * This,
            /* [in] */ __RPC__in BSTR ObjectStorageCLSID,
            /* [in] */ __RPC__in BSTR KeyName,
            /* [in] */ __RPC__in BSTR FileName,
            /* [in] */ SpeechTokenShellFolder Folder,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *FilePath);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveStorageFileName )( 
            __RPC__in ISpeechObjectToken * This,
            /* [in] */ __RPC__in BSTR ObjectStorageCLSID,
            /* [in] */ __RPC__in BSTR KeyName,
            /* [in] */ VARIANT_BOOL DeleteFile);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            __RPC__in ISpeechObjectToken * This,
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData,
            /* [defaultvalue][in] */ __RPC__in_opt IUnknown *Object,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            __RPC__in ISpeechObjectToken * This,
            /* [in] */ long hWnd,
            /* [in] */ __RPC__in BSTR Title,
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData,
            /* [defaultvalue][in] */ __RPC__in_opt IUnknown *Object);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *MatchesAttributes )( 
            __RPC__in ISpeechObjectToken * This,
            /* [in] */ __RPC__in BSTR Attributes,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Matches);
        
        END_INTERFACE
    } ISpeechObjectTokenVtbl;

    interface ISpeechObjectToken
    {
        CONST_VTBL struct ISpeechObjectTokenVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechObjectToken_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechObjectToken_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechObjectToken_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechObjectToken_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechObjectToken_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechObjectToken_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechObjectToken_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechObjectToken_get_Id(This,ObjectId)	\
    ( (This)->lpVtbl -> get_Id(This,ObjectId) ) 

#define ISpeechObjectToken_get_DataKey(This,DataKey)	\
    ( (This)->lpVtbl -> get_DataKey(This,DataKey) ) 

#define ISpeechObjectToken_get_Category(This,Category)	\
    ( (This)->lpVtbl -> get_Category(This,Category) ) 

#define ISpeechObjectToken_GetDescription(This,Locale,Description)	\
    ( (This)->lpVtbl -> GetDescription(This,Locale,Description) ) 

#define ISpeechObjectToken_SetId(This,Id,CategoryID,CreateIfNotExist)	\
    ( (This)->lpVtbl -> SetId(This,Id,CategoryID,CreateIfNotExist) ) 

#define ISpeechObjectToken_GetAttribute(This,AttributeName,AttributeValue)	\
    ( (This)->lpVtbl -> GetAttribute(This,AttributeName,AttributeValue) ) 

#define ISpeechObjectToken_CreateInstance(This,pUnkOuter,ClsContext,Object)	\
    ( (This)->lpVtbl -> CreateInstance(This,pUnkOuter,ClsContext,Object) ) 

#define ISpeechObjectToken_Remove(This,ObjectStorageCLSID)	\
    ( (This)->lpVtbl -> Remove(This,ObjectStorageCLSID) ) 

#define ISpeechObjectToken_GetStorageFileName(This,ObjectStorageCLSID,KeyName,FileName,Folder,FilePath)	\
    ( (This)->lpVtbl -> GetStorageFileName(This,ObjectStorageCLSID,KeyName,FileName,Folder,FilePath) ) 

#define ISpeechObjectToken_RemoveStorageFileName(This,ObjectStorageCLSID,KeyName,DeleteFile)	\
    ( (This)->lpVtbl -> RemoveStorageFileName(This,ObjectStorageCLSID,KeyName,DeleteFile) ) 

#define ISpeechObjectToken_IsUISupported(This,TypeOfUI,ExtraData,Object,Supported)	\
    ( (This)->lpVtbl -> IsUISupported(This,TypeOfUI,ExtraData,Object,Supported) ) 

#define ISpeechObjectToken_DisplayUI(This,hWnd,Title,TypeOfUI,ExtraData,Object)	\
    ( (This)->lpVtbl -> DisplayUI(This,hWnd,Title,TypeOfUI,ExtraData,Object) ) 

#define ISpeechObjectToken_MatchesAttributes(This,Attributes,Matches)	\
    ( (This)->lpVtbl -> MatchesAttributes(This,Attributes,Matches) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechObjectToken_INTERFACE_DEFINED__ */


#ifndef __ISpeechObjectTokens_INTERFACE_DEFINED__
#define __ISpeechObjectTokens_INTERFACE_DEFINED__

/* interface ISpeechObjectTokens */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechObjectTokens;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9285B776-2E7B-4bc0-B53E-580EB6FA967F")
    ISpeechObjectTokens : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *Count) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **Token) = 0;
        
        virtual /* [id][restricted][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppEnumVARIANT) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechObjectTokensVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechObjectTokens * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechObjectTokens * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechObjectTokens * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechObjectTokens * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechObjectTokens * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechObjectTokens * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechObjectTokens * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in ISpeechObjectTokens * This,
            /* [retval][out] */ __RPC__out long *Count);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in ISpeechObjectTokens * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **Token);
        
        /* [id][restricted][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in ISpeechObjectTokens * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppEnumVARIANT);
        
        END_INTERFACE
    } ISpeechObjectTokensVtbl;

    interface ISpeechObjectTokens
    {
        CONST_VTBL struct ISpeechObjectTokensVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechObjectTokens_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechObjectTokens_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechObjectTokens_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechObjectTokens_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechObjectTokens_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechObjectTokens_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechObjectTokens_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechObjectTokens_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define ISpeechObjectTokens_Item(This,Index,Token)	\
    ( (This)->lpVtbl -> Item(This,Index,Token) ) 

#define ISpeechObjectTokens_get__NewEnum(This,ppEnumVARIANT)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppEnumVARIANT) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechObjectTokens_INTERFACE_DEFINED__ */


#ifndef __ISpeechObjectTokenCategory_INTERFACE_DEFINED__
#define __ISpeechObjectTokenCategory_INTERFACE_DEFINED__

/* interface ISpeechObjectTokenCategory */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechObjectTokenCategory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CA7EAC50-2D01-4145-86D4-5AE7D70F4469")
    ISpeechObjectTokenCategory : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Id) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Default( 
            /* [in] */ __RPC__in const BSTR TokenId) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Default( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *TokenId) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SetId( 
            /* [in] */ __RPC__in const BSTR Id,
            /* [defaultvalue][in] */ VARIANT_BOOL CreateIfNotExist = 0) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetDataKey( 
            /* [defaultvalue][in] */ SpeechDataKeyLocation Location,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechDataKey **DataKey) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE EnumerateTokens( 
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **Tokens) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechObjectTokenCategoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechObjectTokenCategory * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechObjectTokenCategory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechObjectTokenCategory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechObjectTokenCategory * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechObjectTokenCategory * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechObjectTokenCategory * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechObjectTokenCategory * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in ISpeechObjectTokenCategory * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Id);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Default )( 
            __RPC__in ISpeechObjectTokenCategory * This,
            /* [in] */ __RPC__in const BSTR TokenId);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Default )( 
            __RPC__in ISpeechObjectTokenCategory * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *TokenId);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetId )( 
            __RPC__in ISpeechObjectTokenCategory * This,
            /* [in] */ __RPC__in const BSTR Id,
            /* [defaultvalue][in] */ VARIANT_BOOL CreateIfNotExist);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDataKey )( 
            __RPC__in ISpeechObjectTokenCategory * This,
            /* [defaultvalue][in] */ SpeechDataKeyLocation Location,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechDataKey **DataKey);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumerateTokens )( 
            __RPC__in ISpeechObjectTokenCategory * This,
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **Tokens);
        
        END_INTERFACE
    } ISpeechObjectTokenCategoryVtbl;

    interface ISpeechObjectTokenCategory
    {
        CONST_VTBL struct ISpeechObjectTokenCategoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechObjectTokenCategory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechObjectTokenCategory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechObjectTokenCategory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechObjectTokenCategory_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechObjectTokenCategory_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechObjectTokenCategory_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechObjectTokenCategory_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechObjectTokenCategory_get_Id(This,Id)	\
    ( (This)->lpVtbl -> get_Id(This,Id) ) 

#define ISpeechObjectTokenCategory_put_Default(This,TokenId)	\
    ( (This)->lpVtbl -> put_Default(This,TokenId) ) 

#define ISpeechObjectTokenCategory_get_Default(This,TokenId)	\
    ( (This)->lpVtbl -> get_Default(This,TokenId) ) 

#define ISpeechObjectTokenCategory_SetId(This,Id,CreateIfNotExist)	\
    ( (This)->lpVtbl -> SetId(This,Id,CreateIfNotExist) ) 

#define ISpeechObjectTokenCategory_GetDataKey(This,Location,DataKey)	\
    ( (This)->lpVtbl -> GetDataKey(This,Location,DataKey) ) 

#define ISpeechObjectTokenCategory_EnumerateTokens(This,RequiredAttributes,OptionalAttributes,Tokens)	\
    ( (This)->lpVtbl -> EnumerateTokens(This,RequiredAttributes,OptionalAttributes,Tokens) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechObjectTokenCategory_INTERFACE_DEFINED__ */


#ifndef __ISpeechAudioBufferInfo_INTERFACE_DEFINED__
#define __ISpeechAudioBufferInfo_INTERFACE_DEFINED__

/* interface ISpeechAudioBufferInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechAudioBufferInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11B103D8-1142-4edf-A093-82FB3915F8CC")
    ISpeechAudioBufferInfo : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MinNotification( 
            /* [retval][out] */ __RPC__out long *MinNotification) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_MinNotification( 
            /* [in] */ long MinNotification) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_BufferSize( 
            /* [retval][out] */ __RPC__out long *BufferSize) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_BufferSize( 
            /* [in] */ long BufferSize) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EventBias( 
            /* [retval][out] */ __RPC__out long *EventBias) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_EventBias( 
            /* [in] */ long EventBias) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechAudioBufferInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechAudioBufferInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechAudioBufferInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechAudioBufferInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechAudioBufferInfo * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechAudioBufferInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechAudioBufferInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechAudioBufferInfo * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinNotification )( 
            __RPC__in ISpeechAudioBufferInfo * This,
            /* [retval][out] */ __RPC__out long *MinNotification);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinNotification )( 
            __RPC__in ISpeechAudioBufferInfo * This,
            /* [in] */ long MinNotification);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BufferSize )( 
            __RPC__in ISpeechAudioBufferInfo * This,
            /* [retval][out] */ __RPC__out long *BufferSize);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BufferSize )( 
            __RPC__in ISpeechAudioBufferInfo * This,
            /* [in] */ long BufferSize);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventBias )( 
            __RPC__in ISpeechAudioBufferInfo * This,
            /* [retval][out] */ __RPC__out long *EventBias);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EventBias )( 
            __RPC__in ISpeechAudioBufferInfo * This,
            /* [in] */ long EventBias);
        
        END_INTERFACE
    } ISpeechAudioBufferInfoVtbl;

    interface ISpeechAudioBufferInfo
    {
        CONST_VTBL struct ISpeechAudioBufferInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechAudioBufferInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechAudioBufferInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechAudioBufferInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechAudioBufferInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechAudioBufferInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechAudioBufferInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechAudioBufferInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechAudioBufferInfo_get_MinNotification(This,MinNotification)	\
    ( (This)->lpVtbl -> get_MinNotification(This,MinNotification) ) 

#define ISpeechAudioBufferInfo_put_MinNotification(This,MinNotification)	\
    ( (This)->lpVtbl -> put_MinNotification(This,MinNotification) ) 

#define ISpeechAudioBufferInfo_get_BufferSize(This,BufferSize)	\
    ( (This)->lpVtbl -> get_BufferSize(This,BufferSize) ) 

#define ISpeechAudioBufferInfo_put_BufferSize(This,BufferSize)	\
    ( (This)->lpVtbl -> put_BufferSize(This,BufferSize) ) 

#define ISpeechAudioBufferInfo_get_EventBias(This,EventBias)	\
    ( (This)->lpVtbl -> get_EventBias(This,EventBias) ) 

#define ISpeechAudioBufferInfo_put_EventBias(This,EventBias)	\
    ( (This)->lpVtbl -> put_EventBias(This,EventBias) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechAudioBufferInfo_INTERFACE_DEFINED__ */


#ifndef __ISpeechAudioStatus_INTERFACE_DEFINED__
#define __ISpeechAudioStatus_INTERFACE_DEFINED__

/* interface ISpeechAudioStatus */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechAudioStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C62D9C91-7458-47f6-862D-1EF86FB0B278")
    ISpeechAudioStatus : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_FreeBufferSpace( 
            /* [retval][out] */ __RPC__out long *FreeBufferSpace) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NonBlockingIO( 
            /* [retval][out] */ __RPC__out long *NonBlockingIO) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ __RPC__out SpeechAudioState *State) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentSeekPosition( 
            /* [retval][out] */ __RPC__out VARIANT *CurrentSeekPosition) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentDevicePosition( 
            /* [retval][out] */ __RPC__out VARIANT *CurrentDevicePosition) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechAudioStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechAudioStatus * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechAudioStatus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechAudioStatus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechAudioStatus * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechAudioStatus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechAudioStatus * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechAudioStatus * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreeBufferSpace )( 
            __RPC__in ISpeechAudioStatus * This,
            /* [retval][out] */ __RPC__out long *FreeBufferSpace);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NonBlockingIO )( 
            __RPC__in ISpeechAudioStatus * This,
            /* [retval][out] */ __RPC__out long *NonBlockingIO);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in ISpeechAudioStatus * This,
            /* [retval][out] */ __RPC__out SpeechAudioState *State);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentSeekPosition )( 
            __RPC__in ISpeechAudioStatus * This,
            /* [retval][out] */ __RPC__out VARIANT *CurrentSeekPosition);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentDevicePosition )( 
            __RPC__in ISpeechAudioStatus * This,
            /* [retval][out] */ __RPC__out VARIANT *CurrentDevicePosition);
        
        END_INTERFACE
    } ISpeechAudioStatusVtbl;

    interface ISpeechAudioStatus
    {
        CONST_VTBL struct ISpeechAudioStatusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechAudioStatus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechAudioStatus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechAudioStatus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechAudioStatus_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechAudioStatus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechAudioStatus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechAudioStatus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechAudioStatus_get_FreeBufferSpace(This,FreeBufferSpace)	\
    ( (This)->lpVtbl -> get_FreeBufferSpace(This,FreeBufferSpace) ) 

#define ISpeechAudioStatus_get_NonBlockingIO(This,NonBlockingIO)	\
    ( (This)->lpVtbl -> get_NonBlockingIO(This,NonBlockingIO) ) 

#define ISpeechAudioStatus_get_State(This,State)	\
    ( (This)->lpVtbl -> get_State(This,State) ) 

#define ISpeechAudioStatus_get_CurrentSeekPosition(This,CurrentSeekPosition)	\
    ( (This)->lpVtbl -> get_CurrentSeekPosition(This,CurrentSeekPosition) ) 

#define ISpeechAudioStatus_get_CurrentDevicePosition(This,CurrentDevicePosition)	\
    ( (This)->lpVtbl -> get_CurrentDevicePosition(This,CurrentDevicePosition) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechAudioStatus_INTERFACE_DEFINED__ */


#ifndef __ISpeechAudioFormat_INTERFACE_DEFINED__
#define __ISpeechAudioFormat_INTERFACE_DEFINED__

/* interface ISpeechAudioFormat */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechAudioFormat;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E6E9C590-3E18-40e3-8299-061F98BDE7C7")
    ISpeechAudioFormat : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ __RPC__out SpeechAudioFormatType *AudioFormat) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Type( 
            /* [in] */ SpeechAudioFormatType AudioFormat) = 0;
        
        virtual /* [id][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_Guid( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid) = 0;
        
        virtual /* [id][helpstring][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_Guid( 
            /* [in] */ __RPC__in BSTR Guid) = 0;
        
        virtual /* [id][helpstring][hidden] */ HRESULT STDMETHODCALLTYPE GetWaveFormatEx( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechWaveFormatEx **SpeechWaveFormatEx) = 0;
        
        virtual /* [id][helpstring][hidden] */ HRESULT STDMETHODCALLTYPE SetWaveFormatEx( 
            /* [in] */ __RPC__in_opt ISpeechWaveFormatEx *SpeechWaveFormatEx) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechAudioFormatVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechAudioFormat * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechAudioFormat * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechAudioFormat * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechAudioFormat * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechAudioFormat * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechAudioFormat * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechAudioFormat * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in ISpeechAudioFormat * This,
            /* [retval][out] */ __RPC__out SpeechAudioFormatType *AudioFormat);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            __RPC__in ISpeechAudioFormat * This,
            /* [in] */ SpeechAudioFormatType AudioFormat);
        
        /* [id][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Guid )( 
            __RPC__in ISpeechAudioFormat * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][helpstring][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Guid )( 
            __RPC__in ISpeechAudioFormat * This,
            /* [in] */ __RPC__in BSTR Guid);
        
        /* [id][helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *GetWaveFormatEx )( 
            __RPC__in ISpeechAudioFormat * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechWaveFormatEx **SpeechWaveFormatEx);
        
        /* [id][helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *SetWaveFormatEx )( 
            __RPC__in ISpeechAudioFormat * This,
            /* [in] */ __RPC__in_opt ISpeechWaveFormatEx *SpeechWaveFormatEx);
        
        END_INTERFACE
    } ISpeechAudioFormatVtbl;

    interface ISpeechAudioFormat
    {
        CONST_VTBL struct ISpeechAudioFormatVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechAudioFormat_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechAudioFormat_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechAudioFormat_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechAudioFormat_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechAudioFormat_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechAudioFormat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechAudioFormat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechAudioFormat_get_Type(This,AudioFormat)	\
    ( (This)->lpVtbl -> get_Type(This,AudioFormat) ) 

#define ISpeechAudioFormat_put_Type(This,AudioFormat)	\
    ( (This)->lpVtbl -> put_Type(This,AudioFormat) ) 

#define ISpeechAudioFormat_get_Guid(This,Guid)	\
    ( (This)->lpVtbl -> get_Guid(This,Guid) ) 

#define ISpeechAudioFormat_put_Guid(This,Guid)	\
    ( (This)->lpVtbl -> put_Guid(This,Guid) ) 

#define ISpeechAudioFormat_GetWaveFormatEx(This,SpeechWaveFormatEx)	\
    ( (This)->lpVtbl -> GetWaveFormatEx(This,SpeechWaveFormatEx) ) 

#define ISpeechAudioFormat_SetWaveFormatEx(This,SpeechWaveFormatEx)	\
    ( (This)->lpVtbl -> SetWaveFormatEx(This,SpeechWaveFormatEx) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechAudioFormat_INTERFACE_DEFINED__ */


#ifndef __ISpeechWaveFormatEx_INTERFACE_DEFINED__
#define __ISpeechWaveFormatEx_INTERFACE_DEFINED__

/* interface ISpeechWaveFormatEx */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechWaveFormatEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7A1EF0D5-1581-4741-88E4-209A49F11A10")
    ISpeechWaveFormatEx : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_FormatTag( 
            /* [retval][out] */ __RPC__out short *FormatTag) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_FormatTag( 
            /* [in] */ short FormatTag) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Channels( 
            /* [retval][out] */ __RPC__out short *Channels) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Channels( 
            /* [in] */ short Channels) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SamplesPerSec( 
            /* [retval][out] */ __RPC__out long *SamplesPerSec) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SamplesPerSec( 
            /* [in] */ long SamplesPerSec) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AvgBytesPerSec( 
            /* [retval][out] */ __RPC__out long *AvgBytesPerSec) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AvgBytesPerSec( 
            /* [in] */ long AvgBytesPerSec) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_BlockAlign( 
            /* [retval][out] */ __RPC__out short *BlockAlign) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_BlockAlign( 
            /* [in] */ short BlockAlign) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_BitsPerSample( 
            /* [retval][out] */ __RPC__out short *BitsPerSample) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_BitsPerSample( 
            /* [in] */ short BitsPerSample) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ExtraData( 
            /* [retval][out] */ __RPC__out VARIANT *ExtraData) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ExtraData( 
            /* [in] */ VARIANT ExtraData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechWaveFormatExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechWaveFormatEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechWaveFormatEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechWaveFormatEx * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FormatTag )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [retval][out] */ __RPC__out short *FormatTag);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FormatTag )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [in] */ short FormatTag);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Channels )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [retval][out] */ __RPC__out short *Channels);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Channels )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [in] */ short Channels);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SamplesPerSec )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [retval][out] */ __RPC__out long *SamplesPerSec);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SamplesPerSec )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [in] */ long SamplesPerSec);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AvgBytesPerSec )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [retval][out] */ __RPC__out long *AvgBytesPerSec);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AvgBytesPerSec )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [in] */ long AvgBytesPerSec);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockAlign )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [retval][out] */ __RPC__out short *BlockAlign);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockAlign )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [in] */ short BlockAlign);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BitsPerSample )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [retval][out] */ __RPC__out short *BitsPerSample);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BitsPerSample )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [in] */ short BitsPerSample);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExtraData )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [retval][out] */ __RPC__out VARIANT *ExtraData);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ExtraData )( 
            __RPC__in ISpeechWaveFormatEx * This,
            /* [in] */ VARIANT ExtraData);
        
        END_INTERFACE
    } ISpeechWaveFormatExVtbl;

    interface ISpeechWaveFormatEx
    {
        CONST_VTBL struct ISpeechWaveFormatExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechWaveFormatEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechWaveFormatEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechWaveFormatEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechWaveFormatEx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechWaveFormatEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechWaveFormatEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechWaveFormatEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechWaveFormatEx_get_FormatTag(This,FormatTag)	\
    ( (This)->lpVtbl -> get_FormatTag(This,FormatTag) ) 

#define ISpeechWaveFormatEx_put_FormatTag(This,FormatTag)	\
    ( (This)->lpVtbl -> put_FormatTag(This,FormatTag) ) 

#define ISpeechWaveFormatEx_get_Channels(This,Channels)	\
    ( (This)->lpVtbl -> get_Channels(This,Channels) ) 

#define ISpeechWaveFormatEx_put_Channels(This,Channels)	\
    ( (This)->lpVtbl -> put_Channels(This,Channels) ) 

#define ISpeechWaveFormatEx_get_SamplesPerSec(This,SamplesPerSec)	\
    ( (This)->lpVtbl -> get_SamplesPerSec(This,SamplesPerSec) ) 

#define ISpeechWaveFormatEx_put_SamplesPerSec(This,SamplesPerSec)	\
    ( (This)->lpVtbl -> put_SamplesPerSec(This,SamplesPerSec) ) 

#define ISpeechWaveFormatEx_get_AvgBytesPerSec(This,AvgBytesPerSec)	\
    ( (This)->lpVtbl -> get_AvgBytesPerSec(This,AvgBytesPerSec) ) 

#define ISpeechWaveFormatEx_put_AvgBytesPerSec(This,AvgBytesPerSec)	\
    ( (This)->lpVtbl -> put_AvgBytesPerSec(This,AvgBytesPerSec) ) 

#define ISpeechWaveFormatEx_get_BlockAlign(This,BlockAlign)	\
    ( (This)->lpVtbl -> get_BlockAlign(This,BlockAlign) ) 

#define ISpeechWaveFormatEx_put_BlockAlign(This,BlockAlign)	\
    ( (This)->lpVtbl -> put_BlockAlign(This,BlockAlign) ) 

#define ISpeechWaveFormatEx_get_BitsPerSample(This,BitsPerSample)	\
    ( (This)->lpVtbl -> get_BitsPerSample(This,BitsPerSample) ) 

#define ISpeechWaveFormatEx_put_BitsPerSample(This,BitsPerSample)	\
    ( (This)->lpVtbl -> put_BitsPerSample(This,BitsPerSample) ) 

#define ISpeechWaveFormatEx_get_ExtraData(This,ExtraData)	\
    ( (This)->lpVtbl -> get_ExtraData(This,ExtraData) ) 

#define ISpeechWaveFormatEx_put_ExtraData(This,ExtraData)	\
    ( (This)->lpVtbl -> put_ExtraData(This,ExtraData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechWaveFormatEx_INTERFACE_DEFINED__ */


#ifndef __ISpeechBaseStream_INTERFACE_DEFINED__
#define __ISpeechBaseStream_INTERFACE_DEFINED__

/* interface ISpeechBaseStream */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechBaseStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6450336F-7D49-4ced-8097-49D6DEE37294")
    ISpeechBaseStream : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Format( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **AudioFormat) = 0;
        
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_Format( 
            /* [in] */ __RPC__in_opt ISpeechAudioFormat *AudioFormat) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Read( 
            /* [out] */ __RPC__out VARIANT *Buffer,
            /* [in] */ long NumberOfBytes,
            /* [retval][out] */ __RPC__out long *BytesRead) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ VARIANT Buffer,
            /* [retval][out] */ __RPC__out long *BytesWritten) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Seek( 
            /* [in] */ VARIANT Position,
            /* [defaultvalue][in] */ SpeechStreamSeekPositionType Origin,
            /* [retval][out] */ __RPC__out VARIANT *NewPosition) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechBaseStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechBaseStream * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechBaseStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechBaseStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechBaseStream * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechBaseStream * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechBaseStream * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechBaseStream * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Format )( 
            __RPC__in ISpeechBaseStream * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **AudioFormat);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Format )( 
            __RPC__in ISpeechBaseStream * This,
            /* [in] */ __RPC__in_opt ISpeechAudioFormat *AudioFormat);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            __RPC__in ISpeechBaseStream * This,
            /* [out] */ __RPC__out VARIANT *Buffer,
            /* [in] */ long NumberOfBytes,
            /* [retval][out] */ __RPC__out long *BytesRead);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            __RPC__in ISpeechBaseStream * This,
            /* [in] */ VARIANT Buffer,
            /* [retval][out] */ __RPC__out long *BytesWritten);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            __RPC__in ISpeechBaseStream * This,
            /* [in] */ VARIANT Position,
            /* [defaultvalue][in] */ SpeechStreamSeekPositionType Origin,
            /* [retval][out] */ __RPC__out VARIANT *NewPosition);
        
        END_INTERFACE
    } ISpeechBaseStreamVtbl;

    interface ISpeechBaseStream
    {
        CONST_VTBL struct ISpeechBaseStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechBaseStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechBaseStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechBaseStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechBaseStream_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechBaseStream_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechBaseStream_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechBaseStream_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechBaseStream_get_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> get_Format(This,AudioFormat) ) 

#define ISpeechBaseStream_putref_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> putref_Format(This,AudioFormat) ) 

#define ISpeechBaseStream_Read(This,Buffer,NumberOfBytes,BytesRead)	\
    ( (This)->lpVtbl -> Read(This,Buffer,NumberOfBytes,BytesRead) ) 

#define ISpeechBaseStream_Write(This,Buffer,BytesWritten)	\
    ( (This)->lpVtbl -> Write(This,Buffer,BytesWritten) ) 

#define ISpeechBaseStream_Seek(This,Position,Origin,NewPosition)	\
    ( (This)->lpVtbl -> Seek(This,Position,Origin,NewPosition) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechBaseStream_INTERFACE_DEFINED__ */


#ifndef __ISpeechFileStream_INTERFACE_DEFINED__
#define __ISpeechFileStream_INTERFACE_DEFINED__

/* interface ISpeechFileStream */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechFileStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AF67F125-AB39-4e93-B4A2-CC2E66E182A7")
    ISpeechFileStream : public ISpeechBaseStream
    {
    public:
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ __RPC__in BSTR FileName,
            /* [defaultvalue][in] */ SpeechStreamFileMode FileMode = SSFMOpenForRead,
            /* [defaultvalue][in] */ VARIANT_BOOL DoEvents = 0) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechFileStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechFileStream * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechFileStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechFileStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechFileStream * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechFileStream * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechFileStream * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechFileStream * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Format )( 
            __RPC__in ISpeechFileStream * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **AudioFormat);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Format )( 
            __RPC__in ISpeechFileStream * This,
            /* [in] */ __RPC__in_opt ISpeechAudioFormat *AudioFormat);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            __RPC__in ISpeechFileStream * This,
            /* [out] */ __RPC__out VARIANT *Buffer,
            /* [in] */ long NumberOfBytes,
            /* [retval][out] */ __RPC__out long *BytesRead);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            __RPC__in ISpeechFileStream * This,
            /* [in] */ VARIANT Buffer,
            /* [retval][out] */ __RPC__out long *BytesWritten);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            __RPC__in ISpeechFileStream * This,
            /* [in] */ VARIANT Position,
            /* [defaultvalue][in] */ SpeechStreamSeekPositionType Origin,
            /* [retval][out] */ __RPC__out VARIANT *NewPosition);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            __RPC__in ISpeechFileStream * This,
            /* [in] */ __RPC__in BSTR FileName,
            /* [defaultvalue][in] */ SpeechStreamFileMode FileMode,
            /* [defaultvalue][in] */ VARIANT_BOOL DoEvents);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            __RPC__in ISpeechFileStream * This);
        
        END_INTERFACE
    } ISpeechFileStreamVtbl;

    interface ISpeechFileStream
    {
        CONST_VTBL struct ISpeechFileStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechFileStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechFileStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechFileStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechFileStream_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechFileStream_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechFileStream_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechFileStream_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechFileStream_get_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> get_Format(This,AudioFormat) ) 

#define ISpeechFileStream_putref_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> putref_Format(This,AudioFormat) ) 

#define ISpeechFileStream_Read(This,Buffer,NumberOfBytes,BytesRead)	\
    ( (This)->lpVtbl -> Read(This,Buffer,NumberOfBytes,BytesRead) ) 

#define ISpeechFileStream_Write(This,Buffer,BytesWritten)	\
    ( (This)->lpVtbl -> Write(This,Buffer,BytesWritten) ) 

#define ISpeechFileStream_Seek(This,Position,Origin,NewPosition)	\
    ( (This)->lpVtbl -> Seek(This,Position,Origin,NewPosition) ) 


#define ISpeechFileStream_Open(This,FileName,FileMode,DoEvents)	\
    ( (This)->lpVtbl -> Open(This,FileName,FileMode,DoEvents) ) 

#define ISpeechFileStream_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechFileStream_INTERFACE_DEFINED__ */


#ifndef __ISpeechMemoryStream_INTERFACE_DEFINED__
#define __ISpeechMemoryStream_INTERFACE_DEFINED__

/* interface ISpeechMemoryStream */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechMemoryStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EEB14B68-808B-4abe-A5EA-B51DA7588008")
    ISpeechMemoryStream : public ISpeechBaseStream
    {
    public:
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SetData( 
            /* [in] */ VARIANT Data) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetData( 
            /* [retval][out] */ __RPC__out VARIANT *pData) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechMemoryStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechMemoryStream * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechMemoryStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechMemoryStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechMemoryStream * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechMemoryStream * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechMemoryStream * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechMemoryStream * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Format )( 
            __RPC__in ISpeechMemoryStream * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **AudioFormat);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Format )( 
            __RPC__in ISpeechMemoryStream * This,
            /* [in] */ __RPC__in_opt ISpeechAudioFormat *AudioFormat);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            __RPC__in ISpeechMemoryStream * This,
            /* [out] */ __RPC__out VARIANT *Buffer,
            /* [in] */ long NumberOfBytes,
            /* [retval][out] */ __RPC__out long *BytesRead);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            __RPC__in ISpeechMemoryStream * This,
            /* [in] */ VARIANT Buffer,
            /* [retval][out] */ __RPC__out long *BytesWritten);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            __RPC__in ISpeechMemoryStream * This,
            /* [in] */ VARIANT Position,
            /* [defaultvalue][in] */ SpeechStreamSeekPositionType Origin,
            /* [retval][out] */ __RPC__out VARIANT *NewPosition);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetData )( 
            __RPC__in ISpeechMemoryStream * This,
            /* [in] */ VARIANT Data);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetData )( 
            __RPC__in ISpeechMemoryStream * This,
            /* [retval][out] */ __RPC__out VARIANT *pData);
        
        END_INTERFACE
    } ISpeechMemoryStreamVtbl;

    interface ISpeechMemoryStream
    {
        CONST_VTBL struct ISpeechMemoryStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechMemoryStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechMemoryStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechMemoryStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechMemoryStream_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechMemoryStream_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechMemoryStream_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechMemoryStream_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechMemoryStream_get_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> get_Format(This,AudioFormat) ) 

#define ISpeechMemoryStream_putref_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> putref_Format(This,AudioFormat) ) 

#define ISpeechMemoryStream_Read(This,Buffer,NumberOfBytes,BytesRead)	\
    ( (This)->lpVtbl -> Read(This,Buffer,NumberOfBytes,BytesRead) ) 

#define ISpeechMemoryStream_Write(This,Buffer,BytesWritten)	\
    ( (This)->lpVtbl -> Write(This,Buffer,BytesWritten) ) 

#define ISpeechMemoryStream_Seek(This,Position,Origin,NewPosition)	\
    ( (This)->lpVtbl -> Seek(This,Position,Origin,NewPosition) ) 


#define ISpeechMemoryStream_SetData(This,Data)	\
    ( (This)->lpVtbl -> SetData(This,Data) ) 

#define ISpeechMemoryStream_GetData(This,pData)	\
    ( (This)->lpVtbl -> GetData(This,pData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechMemoryStream_INTERFACE_DEFINED__ */


#ifndef __ISpeechCustomStream_INTERFACE_DEFINED__
#define __ISpeechCustomStream_INTERFACE_DEFINED__

/* interface ISpeechCustomStream */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechCustomStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1A9E9F4F-104F-4db8-A115-EFD7FD0C97AE")
    ISpeechCustomStream : public ISpeechBaseStream
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_BaseStream( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnkStream) = 0;
        
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_BaseStream( 
            /* [in] */ __RPC__in_opt IUnknown *pUnkStream) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechCustomStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechCustomStream * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechCustomStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechCustomStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechCustomStream * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechCustomStream * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechCustomStream * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechCustomStream * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Format )( 
            __RPC__in ISpeechCustomStream * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **AudioFormat);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Format )( 
            __RPC__in ISpeechCustomStream * This,
            /* [in] */ __RPC__in_opt ISpeechAudioFormat *AudioFormat);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            __RPC__in ISpeechCustomStream * This,
            /* [out] */ __RPC__out VARIANT *Buffer,
            /* [in] */ long NumberOfBytes,
            /* [retval][out] */ __RPC__out long *BytesRead);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            __RPC__in ISpeechCustomStream * This,
            /* [in] */ VARIANT Buffer,
            /* [retval][out] */ __RPC__out long *BytesWritten);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            __RPC__in ISpeechCustomStream * This,
            /* [in] */ VARIANT Position,
            /* [defaultvalue][in] */ SpeechStreamSeekPositionType Origin,
            /* [retval][out] */ __RPC__out VARIANT *NewPosition);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BaseStream )( 
            __RPC__in ISpeechCustomStream * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnkStream);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_BaseStream )( 
            __RPC__in ISpeechCustomStream * This,
            /* [in] */ __RPC__in_opt IUnknown *pUnkStream);
        
        END_INTERFACE
    } ISpeechCustomStreamVtbl;

    interface ISpeechCustomStream
    {
        CONST_VTBL struct ISpeechCustomStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechCustomStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechCustomStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechCustomStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechCustomStream_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechCustomStream_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechCustomStream_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechCustomStream_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechCustomStream_get_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> get_Format(This,AudioFormat) ) 

#define ISpeechCustomStream_putref_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> putref_Format(This,AudioFormat) ) 

#define ISpeechCustomStream_Read(This,Buffer,NumberOfBytes,BytesRead)	\
    ( (This)->lpVtbl -> Read(This,Buffer,NumberOfBytes,BytesRead) ) 

#define ISpeechCustomStream_Write(This,Buffer,BytesWritten)	\
    ( (This)->lpVtbl -> Write(This,Buffer,BytesWritten) ) 

#define ISpeechCustomStream_Seek(This,Position,Origin,NewPosition)	\
    ( (This)->lpVtbl -> Seek(This,Position,Origin,NewPosition) ) 


#define ISpeechCustomStream_get_BaseStream(This,ppUnkStream)	\
    ( (This)->lpVtbl -> get_BaseStream(This,ppUnkStream) ) 

#define ISpeechCustomStream_putref_BaseStream(This,pUnkStream)	\
    ( (This)->lpVtbl -> putref_BaseStream(This,pUnkStream) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechCustomStream_INTERFACE_DEFINED__ */


#ifndef __ISpeechAudio_INTERFACE_DEFINED__
#define __ISpeechAudio_INTERFACE_DEFINED__

/* interface ISpeechAudio */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechAudio;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CFF8E175-019E-11d3-A08E-00C04F8EF9B5")
    ISpeechAudio : public ISpeechBaseStream
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioStatus **Status) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_BufferInfo( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioBufferInfo **BufferInfo) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultFormat( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **StreamFormat) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [retval][out] */ __RPC__out long *Volume) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [in] */ long Volume) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_BufferNotifySize( 
            /* [retval][out] */ __RPC__out long *BufferNotifySize) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_BufferNotifySize( 
            /* [in] */ long BufferNotifySize) = 0;
        
        virtual /* [id][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_EventHandle( 
            /* [retval][out] */ __RPC__out long *EventHandle) = 0;
        
        virtual /* [hidden][id][helpstring] */ HRESULT STDMETHODCALLTYPE SetState( 
            /* [in] */ SpeechAudioState State) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechAudioVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechAudio * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechAudio * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechAudio * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechAudio * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechAudio * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechAudio * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechAudio * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Format )( 
            __RPC__in ISpeechAudio * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **AudioFormat);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Format )( 
            __RPC__in ISpeechAudio * This,
            /* [in] */ __RPC__in_opt ISpeechAudioFormat *AudioFormat);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            __RPC__in ISpeechAudio * This,
            /* [out] */ __RPC__out VARIANT *Buffer,
            /* [in] */ long NumberOfBytes,
            /* [retval][out] */ __RPC__out long *BytesRead);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            __RPC__in ISpeechAudio * This,
            /* [in] */ VARIANT Buffer,
            /* [retval][out] */ __RPC__out long *BytesWritten);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            __RPC__in ISpeechAudio * This,
            /* [in] */ VARIANT Position,
            /* [defaultvalue][in] */ SpeechStreamSeekPositionType Origin,
            /* [retval][out] */ __RPC__out VARIANT *NewPosition);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            __RPC__in ISpeechAudio * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioStatus **Status);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BufferInfo )( 
            __RPC__in ISpeechAudio * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioBufferInfo **BufferInfo);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultFormat )( 
            __RPC__in ISpeechAudio * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **StreamFormat);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            __RPC__in ISpeechAudio * This,
            /* [retval][out] */ __RPC__out long *Volume);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            __RPC__in ISpeechAudio * This,
            /* [in] */ long Volume);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BufferNotifySize )( 
            __RPC__in ISpeechAudio * This,
            /* [retval][out] */ __RPC__out long *BufferNotifySize);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BufferNotifySize )( 
            __RPC__in ISpeechAudio * This,
            /* [in] */ long BufferNotifySize);
        
        /* [id][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventHandle )( 
            __RPC__in ISpeechAudio * This,
            /* [retval][out] */ __RPC__out long *EventHandle);
        
        /* [hidden][id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetState )( 
            __RPC__in ISpeechAudio * This,
            /* [in] */ SpeechAudioState State);
        
        END_INTERFACE
    } ISpeechAudioVtbl;

    interface ISpeechAudio
    {
        CONST_VTBL struct ISpeechAudioVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechAudio_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechAudio_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechAudio_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechAudio_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechAudio_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechAudio_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechAudio_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechAudio_get_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> get_Format(This,AudioFormat) ) 

#define ISpeechAudio_putref_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> putref_Format(This,AudioFormat) ) 

#define ISpeechAudio_Read(This,Buffer,NumberOfBytes,BytesRead)	\
    ( (This)->lpVtbl -> Read(This,Buffer,NumberOfBytes,BytesRead) ) 

#define ISpeechAudio_Write(This,Buffer,BytesWritten)	\
    ( (This)->lpVtbl -> Write(This,Buffer,BytesWritten) ) 

#define ISpeechAudio_Seek(This,Position,Origin,NewPosition)	\
    ( (This)->lpVtbl -> Seek(This,Position,Origin,NewPosition) ) 


#define ISpeechAudio_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define ISpeechAudio_get_BufferInfo(This,BufferInfo)	\
    ( (This)->lpVtbl -> get_BufferInfo(This,BufferInfo) ) 

#define ISpeechAudio_get_DefaultFormat(This,StreamFormat)	\
    ( (This)->lpVtbl -> get_DefaultFormat(This,StreamFormat) ) 

#define ISpeechAudio_get_Volume(This,Volume)	\
    ( (This)->lpVtbl -> get_Volume(This,Volume) ) 

#define ISpeechAudio_put_Volume(This,Volume)	\
    ( (This)->lpVtbl -> put_Volume(This,Volume) ) 

#define ISpeechAudio_get_BufferNotifySize(This,BufferNotifySize)	\
    ( (This)->lpVtbl -> get_BufferNotifySize(This,BufferNotifySize) ) 

#define ISpeechAudio_put_BufferNotifySize(This,BufferNotifySize)	\
    ( (This)->lpVtbl -> put_BufferNotifySize(This,BufferNotifySize) ) 

#define ISpeechAudio_get_EventHandle(This,EventHandle)	\
    ( (This)->lpVtbl -> get_EventHandle(This,EventHandle) ) 

#define ISpeechAudio_SetState(This,State)	\
    ( (This)->lpVtbl -> SetState(This,State) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechAudio_INTERFACE_DEFINED__ */


#ifndef __ISpeechMMSysAudio_INTERFACE_DEFINED__
#define __ISpeechMMSysAudio_INTERFACE_DEFINED__

/* interface ISpeechMMSysAudio */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechMMSysAudio;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C76AF6D-1FD7-4831-81D1-3B71D5A13C44")
    ISpeechMMSysAudio : public ISpeechAudio
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DeviceId( 
            /* [retval][out] */ __RPC__out long *DeviceId) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_DeviceId( 
            /* [in] */ long DeviceId) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LineId( 
            /* [retval][out] */ __RPC__out long *LineId) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_LineId( 
            /* [in] */ long LineId) = 0;
        
        virtual /* [id][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_MMHandle( 
            /* [retval][out] */ __RPC__out long *Handle) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechMMSysAudioVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechMMSysAudio * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechMMSysAudio * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechMMSysAudio * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Format )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **AudioFormat);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Format )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [in] */ __RPC__in_opt ISpeechAudioFormat *AudioFormat);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [out] */ __RPC__out VARIANT *Buffer,
            /* [in] */ long NumberOfBytes,
            /* [retval][out] */ __RPC__out long *BytesRead);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [in] */ VARIANT Buffer,
            /* [retval][out] */ __RPC__out long *BytesWritten);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [in] */ VARIANT Position,
            /* [defaultvalue][in] */ SpeechStreamSeekPositionType Origin,
            /* [retval][out] */ __RPC__out VARIANT *NewPosition);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioStatus **Status);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BufferInfo )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioBufferInfo **BufferInfo);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultFormat )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **StreamFormat);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [retval][out] */ __RPC__out long *Volume);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [in] */ long Volume);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BufferNotifySize )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [retval][out] */ __RPC__out long *BufferNotifySize);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BufferNotifySize )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [in] */ long BufferNotifySize);
        
        /* [id][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventHandle )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [retval][out] */ __RPC__out long *EventHandle);
        
        /* [hidden][id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetState )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [in] */ SpeechAudioState State);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceId )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [retval][out] */ __RPC__out long *DeviceId);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DeviceId )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [in] */ long DeviceId);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineId )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [retval][out] */ __RPC__out long *LineId);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LineId )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [in] */ long LineId);
        
        /* [id][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MMHandle )( 
            __RPC__in ISpeechMMSysAudio * This,
            /* [retval][out] */ __RPC__out long *Handle);
        
        END_INTERFACE
    } ISpeechMMSysAudioVtbl;

    interface ISpeechMMSysAudio
    {
        CONST_VTBL struct ISpeechMMSysAudioVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechMMSysAudio_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechMMSysAudio_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechMMSysAudio_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechMMSysAudio_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechMMSysAudio_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechMMSysAudio_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechMMSysAudio_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechMMSysAudio_get_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> get_Format(This,AudioFormat) ) 

#define ISpeechMMSysAudio_putref_Format(This,AudioFormat)	\
    ( (This)->lpVtbl -> putref_Format(This,AudioFormat) ) 

#define ISpeechMMSysAudio_Read(This,Buffer,NumberOfBytes,BytesRead)	\
    ( (This)->lpVtbl -> Read(This,Buffer,NumberOfBytes,BytesRead) ) 

#define ISpeechMMSysAudio_Write(This,Buffer,BytesWritten)	\
    ( (This)->lpVtbl -> Write(This,Buffer,BytesWritten) ) 

#define ISpeechMMSysAudio_Seek(This,Position,Origin,NewPosition)	\
    ( (This)->lpVtbl -> Seek(This,Position,Origin,NewPosition) ) 


#define ISpeechMMSysAudio_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define ISpeechMMSysAudio_get_BufferInfo(This,BufferInfo)	\
    ( (This)->lpVtbl -> get_BufferInfo(This,BufferInfo) ) 

#define ISpeechMMSysAudio_get_DefaultFormat(This,StreamFormat)	\
    ( (This)->lpVtbl -> get_DefaultFormat(This,StreamFormat) ) 

#define ISpeechMMSysAudio_get_Volume(This,Volume)	\
    ( (This)->lpVtbl -> get_Volume(This,Volume) ) 

#define ISpeechMMSysAudio_put_Volume(This,Volume)	\
    ( (This)->lpVtbl -> put_Volume(This,Volume) ) 

#define ISpeechMMSysAudio_get_BufferNotifySize(This,BufferNotifySize)	\
    ( (This)->lpVtbl -> get_BufferNotifySize(This,BufferNotifySize) ) 

#define ISpeechMMSysAudio_put_BufferNotifySize(This,BufferNotifySize)	\
    ( (This)->lpVtbl -> put_BufferNotifySize(This,BufferNotifySize) ) 

#define ISpeechMMSysAudio_get_EventHandle(This,EventHandle)	\
    ( (This)->lpVtbl -> get_EventHandle(This,EventHandle) ) 

#define ISpeechMMSysAudio_SetState(This,State)	\
    ( (This)->lpVtbl -> SetState(This,State) ) 


#define ISpeechMMSysAudio_get_DeviceId(This,DeviceId)	\
    ( (This)->lpVtbl -> get_DeviceId(This,DeviceId) ) 

#define ISpeechMMSysAudio_put_DeviceId(This,DeviceId)	\
    ( (This)->lpVtbl -> put_DeviceId(This,DeviceId) ) 

#define ISpeechMMSysAudio_get_LineId(This,LineId)	\
    ( (This)->lpVtbl -> get_LineId(This,LineId) ) 

#define ISpeechMMSysAudio_put_LineId(This,LineId)	\
    ( (This)->lpVtbl -> put_LineId(This,LineId) ) 

#define ISpeechMMSysAudio_get_MMHandle(This,Handle)	\
    ( (This)->lpVtbl -> get_MMHandle(This,Handle) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechMMSysAudio_INTERFACE_DEFINED__ */


#ifndef __ISpeechVoice_INTERFACE_DEFINED__
#define __ISpeechVoice_INTERFACE_DEFINED__

/* interface ISpeechVoice */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechVoice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("269316D8-57BD-11D2-9EEE-00C04F797396")
    ISpeechVoice : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechVoiceStatus **Status) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Voice( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **Voice) = 0;
        
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_Voice( 
            /* [in] */ __RPC__in_opt ISpeechObjectToken *Voice) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioOutput( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **AudioOutput) = 0;
        
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_AudioOutput( 
            /* [in] */ __RPC__in_opt ISpeechObjectToken *AudioOutput) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioOutputStream( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechBaseStream **AudioOutputStream) = 0;
        
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_AudioOutputStream( 
            /* [in] */ __RPC__in_opt ISpeechBaseStream *AudioOutputStream) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Rate( 
            /* [retval][out] */ __RPC__out long *Rate) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Rate( 
            /* [in] */ long Rate) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [retval][out] */ __RPC__out long *Volume) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [in] */ long Volume) = 0;
        
        virtual /* [id][helpstring][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_AllowAudioOutputFormatChangesOnNextSet( 
            /* [in] */ VARIANT_BOOL Allow) = 0;
        
        virtual /* [id][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_AllowAudioOutputFormatChangesOnNextSet( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Allow) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EventInterests( 
            /* [retval][out] */ __RPC__out SpeechVoiceEvents *EventInterestFlags) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_EventInterests( 
            /* [in] */ SpeechVoiceEvents EventInterestFlags) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Priority( 
            /* [in] */ SpeechVoicePriority Priority) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Priority( 
            /* [retval][out] */ __RPC__out SpeechVoicePriority *Priority) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AlertBoundary( 
            /* [in] */ SpeechVoiceEvents Boundary) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AlertBoundary( 
            /* [retval][out] */ __RPC__out SpeechVoiceEvents *Boundary) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SynchronousSpeakTimeout( 
            /* [in] */ long msTimeout) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SynchronousSpeakTimeout( 
            /* [retval][out] */ __RPC__out long *msTimeout) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Speak( 
            /* [in] */ __RPC__in BSTR Text,
            /* [defaultvalue][in] */ SpeechVoiceSpeakFlags Flags,
            /* [retval][out] */ __RPC__out long *StreamNumber) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SpeakStream( 
            /* [in] */ __RPC__in_opt ISpeechBaseStream *Stream,
            /* [defaultvalue][in] */ SpeechVoiceSpeakFlags Flags,
            /* [retval][out] */ __RPC__out long *StreamNumber) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ __RPC__in const BSTR Type,
            /* [in] */ long NumItems,
            /* [retval][out] */ __RPC__out long *NumSkipped) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetVoices( 
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **ObjectTokens) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetAudioOutputs( 
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **ObjectTokens) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE WaitUntilDone( 
            /* [in] */ long msTimeout,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Done) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE SpeakCompleteEvent( 
            /* [retval][out] */ __RPC__out long *Handle) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [in] */ long hWndParent,
            /* [in] */ __RPC__in BSTR Title,
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData = 0) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechVoiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechVoice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechVoice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechVoice * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechVoice * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechVoiceStatus **Status);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Voice )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **Voice);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Voice )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ __RPC__in_opt ISpeechObjectToken *Voice);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioOutput )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **AudioOutput);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_AudioOutput )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ __RPC__in_opt ISpeechObjectToken *AudioOutput);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioOutputStream )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechBaseStream **AudioOutputStream);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_AudioOutputStream )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ __RPC__in_opt ISpeechBaseStream *AudioOutputStream);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rate )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__out long *Rate);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rate )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ long Rate);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__out long *Volume);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ long Volume);
        
        /* [id][helpstring][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowAudioOutputFormatChangesOnNextSet )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ VARIANT_BOOL Allow);
        
        /* [id][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowAudioOutputFormatChangesOnNextSet )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Allow);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventInterests )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__out SpeechVoiceEvents *EventInterestFlags);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EventInterests )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ SpeechVoiceEvents EventInterestFlags);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Priority )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ SpeechVoicePriority Priority);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Priority )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__out SpeechVoicePriority *Priority);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AlertBoundary )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ SpeechVoiceEvents Boundary);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AlertBoundary )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__out SpeechVoiceEvents *Boundary);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SynchronousSpeakTimeout )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ long msTimeout);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SynchronousSpeakTimeout )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__out long *msTimeout);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Speak )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ __RPC__in BSTR Text,
            /* [defaultvalue][in] */ SpeechVoiceSpeakFlags Flags,
            /* [retval][out] */ __RPC__out long *StreamNumber);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SpeakStream )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ __RPC__in_opt ISpeechBaseStream *Stream,
            /* [defaultvalue][in] */ SpeechVoiceSpeakFlags Flags,
            /* [retval][out] */ __RPC__out long *StreamNumber);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            __RPC__in ISpeechVoice * This);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Resume )( 
            __RPC__in ISpeechVoice * This);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Skip )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ __RPC__in const BSTR Type,
            /* [in] */ long NumItems,
            /* [retval][out] */ __RPC__out long *NumSkipped);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetVoices )( 
            __RPC__in ISpeechVoice * This,
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **ObjectTokens);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAudioOutputs )( 
            __RPC__in ISpeechVoice * This,
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **ObjectTokens);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *WaitUntilDone )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ long msTimeout,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Done);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SpeakCompleteEvent )( 
            __RPC__in ISpeechVoice * This,
            /* [retval][out] */ __RPC__out long *Handle);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            __RPC__in ISpeechVoice * This,
            /* [in] */ long hWndParent,
            /* [in] */ __RPC__in BSTR Title,
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData);
        
        END_INTERFACE
    } ISpeechVoiceVtbl;

    interface ISpeechVoice
    {
        CONST_VTBL struct ISpeechVoiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechVoice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechVoice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechVoice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechVoice_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechVoice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechVoice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechVoice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechVoice_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define ISpeechVoice_get_Voice(This,Voice)	\
    ( (This)->lpVtbl -> get_Voice(This,Voice) ) 

#define ISpeechVoice_putref_Voice(This,Voice)	\
    ( (This)->lpVtbl -> putref_Voice(This,Voice) ) 

#define ISpeechVoice_get_AudioOutput(This,AudioOutput)	\
    ( (This)->lpVtbl -> get_AudioOutput(This,AudioOutput) ) 

#define ISpeechVoice_putref_AudioOutput(This,AudioOutput)	\
    ( (This)->lpVtbl -> putref_AudioOutput(This,AudioOutput) ) 

#define ISpeechVoice_get_AudioOutputStream(This,AudioOutputStream)	\
    ( (This)->lpVtbl -> get_AudioOutputStream(This,AudioOutputStream) ) 

#define ISpeechVoice_putref_AudioOutputStream(This,AudioOutputStream)	\
    ( (This)->lpVtbl -> putref_AudioOutputStream(This,AudioOutputStream) ) 

#define ISpeechVoice_get_Rate(This,Rate)	\
    ( (This)->lpVtbl -> get_Rate(This,Rate) ) 

#define ISpeechVoice_put_Rate(This,Rate)	\
    ( (This)->lpVtbl -> put_Rate(This,Rate) ) 

#define ISpeechVoice_get_Volume(This,Volume)	\
    ( (This)->lpVtbl -> get_Volume(This,Volume) ) 

#define ISpeechVoice_put_Volume(This,Volume)	\
    ( (This)->lpVtbl -> put_Volume(This,Volume) ) 

#define ISpeechVoice_put_AllowAudioOutputFormatChangesOnNextSet(This,Allow)	\
    ( (This)->lpVtbl -> put_AllowAudioOutputFormatChangesOnNextSet(This,Allow) ) 

#define ISpeechVoice_get_AllowAudioOutputFormatChangesOnNextSet(This,Allow)	\
    ( (This)->lpVtbl -> get_AllowAudioOutputFormatChangesOnNextSet(This,Allow) ) 

#define ISpeechVoice_get_EventInterests(This,EventInterestFlags)	\
    ( (This)->lpVtbl -> get_EventInterests(This,EventInterestFlags) ) 

#define ISpeechVoice_put_EventInterests(This,EventInterestFlags)	\
    ( (This)->lpVtbl -> put_EventInterests(This,EventInterestFlags) ) 

#define ISpeechVoice_put_Priority(This,Priority)	\
    ( (This)->lpVtbl -> put_Priority(This,Priority) ) 

#define ISpeechVoice_get_Priority(This,Priority)	\
    ( (This)->lpVtbl -> get_Priority(This,Priority) ) 

#define ISpeechVoice_put_AlertBoundary(This,Boundary)	\
    ( (This)->lpVtbl -> put_AlertBoundary(This,Boundary) ) 

#define ISpeechVoice_get_AlertBoundary(This,Boundary)	\
    ( (This)->lpVtbl -> get_AlertBoundary(This,Boundary) ) 

#define ISpeechVoice_put_SynchronousSpeakTimeout(This,msTimeout)	\
    ( (This)->lpVtbl -> put_SynchronousSpeakTimeout(This,msTimeout) ) 

#define ISpeechVoice_get_SynchronousSpeakTimeout(This,msTimeout)	\
    ( (This)->lpVtbl -> get_SynchronousSpeakTimeout(This,msTimeout) ) 

#define ISpeechVoice_Speak(This,Text,Flags,StreamNumber)	\
    ( (This)->lpVtbl -> Speak(This,Text,Flags,StreamNumber) ) 

#define ISpeechVoice_SpeakStream(This,Stream,Flags,StreamNumber)	\
    ( (This)->lpVtbl -> SpeakStream(This,Stream,Flags,StreamNumber) ) 

#define ISpeechVoice_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define ISpeechVoice_Resume(This)	\
    ( (This)->lpVtbl -> Resume(This) ) 

#define ISpeechVoice_Skip(This,Type,NumItems,NumSkipped)	\
    ( (This)->lpVtbl -> Skip(This,Type,NumItems,NumSkipped) ) 

#define ISpeechVoice_GetVoices(This,RequiredAttributes,OptionalAttributes,ObjectTokens)	\
    ( (This)->lpVtbl -> GetVoices(This,RequiredAttributes,OptionalAttributes,ObjectTokens) ) 

#define ISpeechVoice_GetAudioOutputs(This,RequiredAttributes,OptionalAttributes,ObjectTokens)	\
    ( (This)->lpVtbl -> GetAudioOutputs(This,RequiredAttributes,OptionalAttributes,ObjectTokens) ) 

#define ISpeechVoice_WaitUntilDone(This,msTimeout,Done)	\
    ( (This)->lpVtbl -> WaitUntilDone(This,msTimeout,Done) ) 

#define ISpeechVoice_SpeakCompleteEvent(This,Handle)	\
    ( (This)->lpVtbl -> SpeakCompleteEvent(This,Handle) ) 

#define ISpeechVoice_IsUISupported(This,TypeOfUI,ExtraData,Supported)	\
    ( (This)->lpVtbl -> IsUISupported(This,TypeOfUI,ExtraData,Supported) ) 

#define ISpeechVoice_DisplayUI(This,hWndParent,Title,TypeOfUI,ExtraData)	\
    ( (This)->lpVtbl -> DisplayUI(This,hWndParent,Title,TypeOfUI,ExtraData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechVoice_INTERFACE_DEFINED__ */


#ifndef __ISpeechVoiceStatus_INTERFACE_DEFINED__
#define __ISpeechVoiceStatus_INTERFACE_DEFINED__

/* interface ISpeechVoiceStatus */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechVoiceStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8BE47B07-57F6-11d2-9EEE-00C04F797396")
    ISpeechVoiceStatus : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentStreamNumber( 
            /* [retval][out] */ __RPC__out long *StreamNumber) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LastStreamNumberQueued( 
            /* [retval][out] */ __RPC__out long *StreamNumber) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LastHResult( 
            /* [retval][out] */ __RPC__out long *HResult) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RunningState( 
            /* [retval][out] */ __RPC__out SpeechRunState *State) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_InputWordPosition( 
            /* [retval][out] */ __RPC__out long *Position) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_InputWordLength( 
            /* [retval][out] */ __RPC__out long *Length) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_InputSentencePosition( 
            /* [retval][out] */ __RPC__out long *Position) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_InputSentenceLength( 
            /* [retval][out] */ __RPC__out long *Length) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LastBookmark( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Bookmark) = 0;
        
        virtual /* [hidden][id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LastBookmarkId( 
            /* [retval][out] */ __RPC__out long *BookmarkId) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PhonemeId( 
            /* [retval][out] */ __RPC__out short *PhoneId) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_VisemeId( 
            /* [retval][out] */ __RPC__out short *VisemeId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechVoiceStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechVoiceStatus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechVoiceStatus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechVoiceStatus * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentStreamNumber )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__out long *StreamNumber);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastStreamNumberQueued )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__out long *StreamNumber);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastHResult )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__out long *HResult);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RunningState )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__out SpeechRunState *State);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputWordPosition )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__out long *Position);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputWordLength )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__out long *Length);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputSentencePosition )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__out long *Position);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InputSentenceLength )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__out long *Length);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastBookmark )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Bookmark);
        
        /* [hidden][id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastBookmarkId )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__out long *BookmarkId);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhonemeId )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__out short *PhoneId);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VisemeId )( 
            __RPC__in ISpeechVoiceStatus * This,
            /* [retval][out] */ __RPC__out short *VisemeId);
        
        END_INTERFACE
    } ISpeechVoiceStatusVtbl;

    interface ISpeechVoiceStatus
    {
        CONST_VTBL struct ISpeechVoiceStatusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechVoiceStatus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechVoiceStatus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechVoiceStatus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechVoiceStatus_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechVoiceStatus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechVoiceStatus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechVoiceStatus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechVoiceStatus_get_CurrentStreamNumber(This,StreamNumber)	\
    ( (This)->lpVtbl -> get_CurrentStreamNumber(This,StreamNumber) ) 

#define ISpeechVoiceStatus_get_LastStreamNumberQueued(This,StreamNumber)	\
    ( (This)->lpVtbl -> get_LastStreamNumberQueued(This,StreamNumber) ) 

#define ISpeechVoiceStatus_get_LastHResult(This,HResult)	\
    ( (This)->lpVtbl -> get_LastHResult(This,HResult) ) 

#define ISpeechVoiceStatus_get_RunningState(This,State)	\
    ( (This)->lpVtbl -> get_RunningState(This,State) ) 

#define ISpeechVoiceStatus_get_InputWordPosition(This,Position)	\
    ( (This)->lpVtbl -> get_InputWordPosition(This,Position) ) 

#define ISpeechVoiceStatus_get_InputWordLength(This,Length)	\
    ( (This)->lpVtbl -> get_InputWordLength(This,Length) ) 

#define ISpeechVoiceStatus_get_InputSentencePosition(This,Position)	\
    ( (This)->lpVtbl -> get_InputSentencePosition(This,Position) ) 

#define ISpeechVoiceStatus_get_InputSentenceLength(This,Length)	\
    ( (This)->lpVtbl -> get_InputSentenceLength(This,Length) ) 

#define ISpeechVoiceStatus_get_LastBookmark(This,Bookmark)	\
    ( (This)->lpVtbl -> get_LastBookmark(This,Bookmark) ) 

#define ISpeechVoiceStatus_get_LastBookmarkId(This,BookmarkId)	\
    ( (This)->lpVtbl -> get_LastBookmarkId(This,BookmarkId) ) 

#define ISpeechVoiceStatus_get_PhonemeId(This,PhoneId)	\
    ( (This)->lpVtbl -> get_PhonemeId(This,PhoneId) ) 

#define ISpeechVoiceStatus_get_VisemeId(This,VisemeId)	\
    ( (This)->lpVtbl -> get_VisemeId(This,VisemeId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechVoiceStatus_INTERFACE_DEFINED__ */


#ifndef ___ISpeechVoiceEvents_DISPINTERFACE_DEFINED__
#define ___ISpeechVoiceEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ISpeechVoiceEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__ISpeechVoiceEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A372ACD1-3BEF-4bbd-8FFB-CB3E2B416AF8")
    _ISpeechVoiceEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ISpeechVoiceEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in _ISpeechVoiceEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in _ISpeechVoiceEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in _ISpeechVoiceEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in _ISpeechVoiceEvents * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in _ISpeechVoiceEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in _ISpeechVoiceEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ISpeechVoiceEvents * This,
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
    } _ISpeechVoiceEventsVtbl;

    interface _ISpeechVoiceEvents
    {
        CONST_VTBL struct _ISpeechVoiceEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISpeechVoiceEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ISpeechVoiceEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ISpeechVoiceEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ISpeechVoiceEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ISpeechVoiceEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ISpeechVoiceEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ISpeechVoiceEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ISpeechVoiceEvents_DISPINTERFACE_DEFINED__ */


#ifndef __ISpeechRecognizer_INTERFACE_DEFINED__
#define __ISpeechRecognizer_INTERFACE_DEFINED__

/* interface ISpeechRecognizer */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechRecognizer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2D5F1C0C-BD75-4b08-9478-3B11FEA2586C")
    ISpeechRecognizer : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_Recognizer( 
            /* [in] */ __RPC__in_opt ISpeechObjectToken *Recognizer) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Recognizer( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **Recognizer) = 0;
        
        virtual /* [id][helpstring][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_AllowAudioInputFormatChangesOnNextSet( 
            /* [in] */ VARIANT_BOOL Allow) = 0;
        
        virtual /* [id][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_AllowAudioInputFormatChangesOnNextSet( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Allow) = 0;
        
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_AudioInput( 
            /* [defaultvalue][in] */ __RPC__in_opt ISpeechObjectToken *AudioInput = 0) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioInput( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **AudioInput) = 0;
        
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_AudioInputStream( 
            /* [defaultvalue][in] */ __RPC__in_opt ISpeechBaseStream *AudioInputStream = 0) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioInputStream( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechBaseStream **AudioInputStream) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsShared( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Shared) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_State( 
            /* [in] */ SpeechRecognizerState State) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ __RPC__out SpeechRecognizerState *State) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecognizerStatus **Status) = 0;
        
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_Profile( 
            /* [defaultvalue][in] */ __RPC__in_opt ISpeechObjectToken *Profile = 0) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Profile( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **Profile) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE EmulateRecognition( 
            /* [in] */ VARIANT TextElements,
            /* [defaultvalue][in] */ __RPC__in VARIANT *ElementDisplayAttributes = 0,
            /* [defaultvalue][in] */ long LanguageId = 0) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CreateRecoContext( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoContext **NewContext) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetFormat( 
            /* [in] */ SpeechFormatType Type,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **Format) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE SetPropertyNumber( 
            /* [in] */ __RPC__in const BSTR Name,
            /* [in] */ long Value,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetPropertyNumber( 
            /* [in] */ __RPC__in const BSTR Name,
            /* [out][in] */ __RPC__inout long *Value,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE SetPropertyString( 
            /* [in] */ __RPC__in const BSTR Name,
            /* [in] */ __RPC__in const BSTR Value,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported) = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetPropertyString( 
            /* [in] */ __RPC__in const BSTR Name,
            /* [out][in] */ __RPC__deref_inout_opt BSTR *Value,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE DisplayUI( 
            /* [in] */ long hWndParent,
            /* [in] */ __RPC__in BSTR Title,
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData = 0) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetRecognizers( 
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **ObjectTokens) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetAudioInputs( 
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **ObjectTokens) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetProfiles( 
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **ObjectTokens) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechRecognizerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechRecognizer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechRecognizer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechRecognizer * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechRecognizer * This,
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
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Recognizer )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ __RPC__in_opt ISpeechObjectToken *Recognizer);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Recognizer )( 
            __RPC__in ISpeechRecognizer * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **Recognizer);
        
        /* [id][helpstring][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowAudioInputFormatChangesOnNextSet )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ VARIANT_BOOL Allow);
        
        /* [id][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowAudioInputFormatChangesOnNextSet )( 
            __RPC__in ISpeechRecognizer * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Allow);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_AudioInput )( 
            __RPC__in ISpeechRecognizer * This,
            /* [defaultvalue][in] */ __RPC__in_opt ISpeechObjectToken *AudioInput);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioInput )( 
            __RPC__in ISpeechRecognizer * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **AudioInput);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_AudioInputStream )( 
            __RPC__in ISpeechRecognizer * This,
            /* [defaultvalue][in] */ __RPC__in_opt ISpeechBaseStream *AudioInputStream);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioInputStream )( 
            __RPC__in ISpeechRecognizer * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechBaseStream **AudioInputStream);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsShared )( 
            __RPC__in ISpeechRecognizer * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Shared);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_State )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ SpeechRecognizerState State);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in ISpeechRecognizer * This,
            /* [retval][out] */ __RPC__out SpeechRecognizerState *State);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            __RPC__in ISpeechRecognizer * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecognizerStatus **Status);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Profile )( 
            __RPC__in ISpeechRecognizer * This,
            /* [defaultvalue][in] */ __RPC__in_opt ISpeechObjectToken *Profile);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Profile )( 
            __RPC__in ISpeechRecognizer * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectToken **Profile);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *EmulateRecognition )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ VARIANT TextElements,
            /* [defaultvalue][in] */ __RPC__in VARIANT *ElementDisplayAttributes,
            /* [defaultvalue][in] */ long LanguageId);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateRecoContext )( 
            __RPC__in ISpeechRecognizer * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoContext **NewContext);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ SpeechFormatType Type,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **Format);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPropertyNumber )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ __RPC__in const BSTR Name,
            /* [in] */ long Value,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyNumber )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ __RPC__in const BSTR Name,
            /* [out][in] */ __RPC__inout long *Value,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPropertyString )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ __RPC__in const BSTR Name,
            /* [in] */ __RPC__in const BSTR Value,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPropertyString )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ __RPC__in const BSTR Name,
            /* [out][in] */ __RPC__deref_inout_opt BSTR *Value,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Supported);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *DisplayUI )( 
            __RPC__in ISpeechRecognizer * This,
            /* [in] */ long hWndParent,
            /* [in] */ __RPC__in BSTR Title,
            /* [in] */ __RPC__in const BSTR TypeOfUI,
            /* [defaultvalue][in] */ __RPC__in const VARIANT *ExtraData);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRecognizers )( 
            __RPC__in ISpeechRecognizer * This,
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **ObjectTokens);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetAudioInputs )( 
            __RPC__in ISpeechRecognizer * This,
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **ObjectTokens);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProfiles )( 
            __RPC__in ISpeechRecognizer * This,
            /* [defaultvalue][in] */ __RPC__in BSTR RequiredAttributes,
            /* [defaultvalue][in] */ __RPC__in BSTR OptionalAttributes,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechObjectTokens **ObjectTokens);
        
        END_INTERFACE
    } ISpeechRecognizerVtbl;

    interface ISpeechRecognizer
    {
        CONST_VTBL struct ISpeechRecognizerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechRecognizer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechRecognizer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechRecognizer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechRecognizer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechRecognizer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechRecognizer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechRecognizer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechRecognizer_putref_Recognizer(This,Recognizer)	\
    ( (This)->lpVtbl -> putref_Recognizer(This,Recognizer) ) 

#define ISpeechRecognizer_get_Recognizer(This,Recognizer)	\
    ( (This)->lpVtbl -> get_Recognizer(This,Recognizer) ) 

#define ISpeechRecognizer_put_AllowAudioInputFormatChangesOnNextSet(This,Allow)	\
    ( (This)->lpVtbl -> put_AllowAudioInputFormatChangesOnNextSet(This,Allow) ) 

#define ISpeechRecognizer_get_AllowAudioInputFormatChangesOnNextSet(This,Allow)	\
    ( (This)->lpVtbl -> get_AllowAudioInputFormatChangesOnNextSet(This,Allow) ) 

#define ISpeechRecognizer_putref_AudioInput(This,AudioInput)	\
    ( (This)->lpVtbl -> putref_AudioInput(This,AudioInput) ) 

#define ISpeechRecognizer_get_AudioInput(This,AudioInput)	\
    ( (This)->lpVtbl -> get_AudioInput(This,AudioInput) ) 

#define ISpeechRecognizer_putref_AudioInputStream(This,AudioInputStream)	\
    ( (This)->lpVtbl -> putref_AudioInputStream(This,AudioInputStream) ) 

#define ISpeechRecognizer_get_AudioInputStream(This,AudioInputStream)	\
    ( (This)->lpVtbl -> get_AudioInputStream(This,AudioInputStream) ) 

#define ISpeechRecognizer_get_IsShared(This,Shared)	\
    ( (This)->lpVtbl -> get_IsShared(This,Shared) ) 

#define ISpeechRecognizer_put_State(This,State)	\
    ( (This)->lpVtbl -> put_State(This,State) ) 

#define ISpeechRecognizer_get_State(This,State)	\
    ( (This)->lpVtbl -> get_State(This,State) ) 

#define ISpeechRecognizer_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define ISpeechRecognizer_putref_Profile(This,Profile)	\
    ( (This)->lpVtbl -> putref_Profile(This,Profile) ) 

#define ISpeechRecognizer_get_Profile(This,Profile)	\
    ( (This)->lpVtbl -> get_Profile(This,Profile) ) 

#define ISpeechRecognizer_EmulateRecognition(This,TextElements,ElementDisplayAttributes,LanguageId)	\
    ( (This)->lpVtbl -> EmulateRecognition(This,TextElements,ElementDisplayAttributes,LanguageId) ) 

#define ISpeechRecognizer_CreateRecoContext(This,NewContext)	\
    ( (This)->lpVtbl -> CreateRecoContext(This,NewContext) ) 

#define ISpeechRecognizer_GetFormat(This,Type,Format)	\
    ( (This)->lpVtbl -> GetFormat(This,Type,Format) ) 

#define ISpeechRecognizer_SetPropertyNumber(This,Name,Value,Supported)	\
    ( (This)->lpVtbl -> SetPropertyNumber(This,Name,Value,Supported) ) 

#define ISpeechRecognizer_GetPropertyNumber(This,Name,Value,Supported)	\
    ( (This)->lpVtbl -> GetPropertyNumber(This,Name,Value,Supported) ) 

#define ISpeechRecognizer_SetPropertyString(This,Name,Value,Supported)	\
    ( (This)->lpVtbl -> SetPropertyString(This,Name,Value,Supported) ) 

#define ISpeechRecognizer_GetPropertyString(This,Name,Value,Supported)	\
    ( (This)->lpVtbl -> GetPropertyString(This,Name,Value,Supported) ) 

#define ISpeechRecognizer_IsUISupported(This,TypeOfUI,ExtraData,Supported)	\
    ( (This)->lpVtbl -> IsUISupported(This,TypeOfUI,ExtraData,Supported) ) 

#define ISpeechRecognizer_DisplayUI(This,hWndParent,Title,TypeOfUI,ExtraData)	\
    ( (This)->lpVtbl -> DisplayUI(This,hWndParent,Title,TypeOfUI,ExtraData) ) 

#define ISpeechRecognizer_GetRecognizers(This,RequiredAttributes,OptionalAttributes,ObjectTokens)	\
    ( (This)->lpVtbl -> GetRecognizers(This,RequiredAttributes,OptionalAttributes,ObjectTokens) ) 

#define ISpeechRecognizer_GetAudioInputs(This,RequiredAttributes,OptionalAttributes,ObjectTokens)	\
    ( (This)->lpVtbl -> GetAudioInputs(This,RequiredAttributes,OptionalAttributes,ObjectTokens) ) 

#define ISpeechRecognizer_GetProfiles(This,RequiredAttributes,OptionalAttributes,ObjectTokens)	\
    ( (This)->lpVtbl -> GetProfiles(This,RequiredAttributes,OptionalAttributes,ObjectTokens) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechRecognizer_INTERFACE_DEFINED__ */


#ifndef __ISpeechRecognizerStatus_INTERFACE_DEFINED__
#define __ISpeechRecognizerStatus_INTERFACE_DEFINED__

/* interface ISpeechRecognizerStatus */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechRecognizerStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BFF9E781-53EC-484e-BB8A-0E1B5551E35C")
    ISpeechRecognizerStatus : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioStatus( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioStatus **AudioStatus) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentStreamPosition( 
            /* [retval][out] */ __RPC__out VARIANT *pCurrentStreamPos) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentStreamNumber( 
            /* [retval][out] */ __RPC__out long *StreamNumber) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NumberOfActiveRules( 
            /* [retval][out] */ __RPC__out long *NumberOfActiveRules) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClsidEngine( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *ClsidEngine) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SupportedLanguages( 
            /* [retval][out] */ __RPC__out VARIANT *SupportedLanguages) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechRecognizerStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechRecognizerStatus * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechRecognizerStatus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechRecognizerStatus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechRecognizerStatus * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechRecognizerStatus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechRecognizerStatus * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechRecognizerStatus * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioStatus )( 
            __RPC__in ISpeechRecognizerStatus * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioStatus **AudioStatus);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentStreamPosition )( 
            __RPC__in ISpeechRecognizerStatus * This,
            /* [retval][out] */ __RPC__out VARIANT *pCurrentStreamPos);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentStreamNumber )( 
            __RPC__in ISpeechRecognizerStatus * This,
            /* [retval][out] */ __RPC__out long *StreamNumber);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumberOfActiveRules )( 
            __RPC__in ISpeechRecognizerStatus * This,
            /* [retval][out] */ __RPC__out long *NumberOfActiveRules);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClsidEngine )( 
            __RPC__in ISpeechRecognizerStatus * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *ClsidEngine);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SupportedLanguages )( 
            __RPC__in ISpeechRecognizerStatus * This,
            /* [retval][out] */ __RPC__out VARIANT *SupportedLanguages);
        
        END_INTERFACE
    } ISpeechRecognizerStatusVtbl;

    interface ISpeechRecognizerStatus
    {
        CONST_VTBL struct ISpeechRecognizerStatusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechRecognizerStatus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechRecognizerStatus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechRecognizerStatus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechRecognizerStatus_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechRecognizerStatus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechRecognizerStatus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechRecognizerStatus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechRecognizerStatus_get_AudioStatus(This,AudioStatus)	\
    ( (This)->lpVtbl -> get_AudioStatus(This,AudioStatus) ) 

#define ISpeechRecognizerStatus_get_CurrentStreamPosition(This,pCurrentStreamPos)	\
    ( (This)->lpVtbl -> get_CurrentStreamPosition(This,pCurrentStreamPos) ) 

#define ISpeechRecognizerStatus_get_CurrentStreamNumber(This,StreamNumber)	\
    ( (This)->lpVtbl -> get_CurrentStreamNumber(This,StreamNumber) ) 

#define ISpeechRecognizerStatus_get_NumberOfActiveRules(This,NumberOfActiveRules)	\
    ( (This)->lpVtbl -> get_NumberOfActiveRules(This,NumberOfActiveRules) ) 

#define ISpeechRecognizerStatus_get_ClsidEngine(This,ClsidEngine)	\
    ( (This)->lpVtbl -> get_ClsidEngine(This,ClsidEngine) ) 

#define ISpeechRecognizerStatus_get_SupportedLanguages(This,SupportedLanguages)	\
    ( (This)->lpVtbl -> get_SupportedLanguages(This,SupportedLanguages) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechRecognizerStatus_INTERFACE_DEFINED__ */


#ifndef __ISpeechRecoContext_INTERFACE_DEFINED__
#define __ISpeechRecoContext_INTERFACE_DEFINED__

/* interface ISpeechRecoContext */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechRecoContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("580AA49D-7E1E-4809-B8E2-57DA806104B8")
    ISpeechRecoContext : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Recognizer( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecognizer **Recognizer) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioInputInterferenceStatus( 
            /* [retval][out] */ __RPC__out SpeechInterference *Interference) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RequestedUIType( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *UIType) = 0;
        
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_Voice( 
            /* [in] */ __RPC__in_opt ISpeechVoice *Voice) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Voice( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechVoice **Voice) = 0;
        
        virtual /* [id][helpstring][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_AllowVoiceFormatMatchingOnNextSet( 
            /* [in] */ VARIANT_BOOL Allow) = 0;
        
        virtual /* [id][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_AllowVoiceFormatMatchingOnNextSet( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pAllow) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_VoicePurgeEvent( 
            /* [in] */ SpeechRecoEvents EventInterest) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_VoicePurgeEvent( 
            /* [retval][out] */ __RPC__out SpeechRecoEvents *EventInterest) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_EventInterests( 
            /* [in] */ SpeechRecoEvents EventInterest) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EventInterests( 
            /* [retval][out] */ __RPC__out SpeechRecoEvents *EventInterest) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_CmdMaxAlternates( 
            /* [in] */ long MaxAlternates) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CmdMaxAlternates( 
            /* [retval][out] */ __RPC__out long *MaxAlternates) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_State( 
            /* [in] */ SpeechRecoContextState State) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ __RPC__out SpeechRecoContextState *State) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_RetainedAudio( 
            /* [in] */ SpeechRetainedAudioOptions Option) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RetainedAudio( 
            /* [retval][out] */ __RPC__out SpeechRetainedAudioOptions *Option) = 0;
        
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_RetainedAudioFormat( 
            /* [in] */ __RPC__in_opt ISpeechAudioFormat *Format) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RetainedAudioFormat( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **Format) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CreateGrammar( 
            /* [defaultvalue][in] */ VARIANT GrammarId,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoGrammar **Grammar) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CreateResultFromMemory( 
            /* [in] */ __RPC__in VARIANT *ResultBlock,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoResult **Result) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Bookmark( 
            /* [in] */ SpeechBookmarkOptions Options,
            /* [in] */ VARIANT StreamPos,
            /* [in] */ VARIANT BookmarkId) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SetAdaptationData( 
            /* [in] */ __RPC__in BSTR AdaptationString) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechRecoContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechRecoContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechRecoContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechRecoContext * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechRecoContext * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Recognizer )( 
            __RPC__in ISpeechRecoContext * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecognizer **Recognizer);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioInputInterferenceStatus )( 
            __RPC__in ISpeechRecoContext * This,
            /* [retval][out] */ __RPC__out SpeechInterference *Interference);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequestedUIType )( 
            __RPC__in ISpeechRecoContext * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *UIType);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Voice )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ __RPC__in_opt ISpeechVoice *Voice);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Voice )( 
            __RPC__in ISpeechRecoContext * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechVoice **Voice);
        
        /* [id][helpstring][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowVoiceFormatMatchingOnNextSet )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ VARIANT_BOOL Allow);
        
        /* [id][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowVoiceFormatMatchingOnNextSet )( 
            __RPC__in ISpeechRecoContext * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pAllow);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VoicePurgeEvent )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ SpeechRecoEvents EventInterest);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VoicePurgeEvent )( 
            __RPC__in ISpeechRecoContext * This,
            /* [retval][out] */ __RPC__out SpeechRecoEvents *EventInterest);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EventInterests )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ SpeechRecoEvents EventInterest);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventInterests )( 
            __RPC__in ISpeechRecoContext * This,
            /* [retval][out] */ __RPC__out SpeechRecoEvents *EventInterest);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CmdMaxAlternates )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ long MaxAlternates);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CmdMaxAlternates )( 
            __RPC__in ISpeechRecoContext * This,
            /* [retval][out] */ __RPC__out long *MaxAlternates);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_State )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ SpeechRecoContextState State);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in ISpeechRecoContext * This,
            /* [retval][out] */ __RPC__out SpeechRecoContextState *State);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RetainedAudio )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ SpeechRetainedAudioOptions Option);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RetainedAudio )( 
            __RPC__in ISpeechRecoContext * This,
            /* [retval][out] */ __RPC__out SpeechRetainedAudioOptions *Option);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_RetainedAudioFormat )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ __RPC__in_opt ISpeechAudioFormat *Format);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RetainedAudioFormat )( 
            __RPC__in ISpeechRecoContext * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **Format);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            __RPC__in ISpeechRecoContext * This);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Resume )( 
            __RPC__in ISpeechRecoContext * This);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateGrammar )( 
            __RPC__in ISpeechRecoContext * This,
            /* [defaultvalue][in] */ VARIANT GrammarId,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoGrammar **Grammar);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateResultFromMemory )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ __RPC__in VARIANT *ResultBlock,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoResult **Result);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Bookmark )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ SpeechBookmarkOptions Options,
            /* [in] */ VARIANT StreamPos,
            /* [in] */ VARIANT BookmarkId);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetAdaptationData )( 
            __RPC__in ISpeechRecoContext * This,
            /* [in] */ __RPC__in BSTR AdaptationString);
        
        END_INTERFACE
    } ISpeechRecoContextVtbl;

    interface ISpeechRecoContext
    {
        CONST_VTBL struct ISpeechRecoContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechRecoContext_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechRecoContext_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechRecoContext_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechRecoContext_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechRecoContext_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechRecoContext_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechRecoContext_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechRecoContext_get_Recognizer(This,Recognizer)	\
    ( (This)->lpVtbl -> get_Recognizer(This,Recognizer) ) 

#define ISpeechRecoContext_get_AudioInputInterferenceStatus(This,Interference)	\
    ( (This)->lpVtbl -> get_AudioInputInterferenceStatus(This,Interference) ) 

#define ISpeechRecoContext_get_RequestedUIType(This,UIType)	\
    ( (This)->lpVtbl -> get_RequestedUIType(This,UIType) ) 

#define ISpeechRecoContext_putref_Voice(This,Voice)	\
    ( (This)->lpVtbl -> putref_Voice(This,Voice) ) 

#define ISpeechRecoContext_get_Voice(This,Voice)	\
    ( (This)->lpVtbl -> get_Voice(This,Voice) ) 

#define ISpeechRecoContext_put_AllowVoiceFormatMatchingOnNextSet(This,Allow)	\
    ( (This)->lpVtbl -> put_AllowVoiceFormatMatchingOnNextSet(This,Allow) ) 

#define ISpeechRecoContext_get_AllowVoiceFormatMatchingOnNextSet(This,pAllow)	\
    ( (This)->lpVtbl -> get_AllowVoiceFormatMatchingOnNextSet(This,pAllow) ) 

#define ISpeechRecoContext_put_VoicePurgeEvent(This,EventInterest)	\
    ( (This)->lpVtbl -> put_VoicePurgeEvent(This,EventInterest) ) 

#define ISpeechRecoContext_get_VoicePurgeEvent(This,EventInterest)	\
    ( (This)->lpVtbl -> get_VoicePurgeEvent(This,EventInterest) ) 

#define ISpeechRecoContext_put_EventInterests(This,EventInterest)	\
    ( (This)->lpVtbl -> put_EventInterests(This,EventInterest) ) 

#define ISpeechRecoContext_get_EventInterests(This,EventInterest)	\
    ( (This)->lpVtbl -> get_EventInterests(This,EventInterest) ) 

#define ISpeechRecoContext_put_CmdMaxAlternates(This,MaxAlternates)	\
    ( (This)->lpVtbl -> put_CmdMaxAlternates(This,MaxAlternates) ) 

#define ISpeechRecoContext_get_CmdMaxAlternates(This,MaxAlternates)	\
    ( (This)->lpVtbl -> get_CmdMaxAlternates(This,MaxAlternates) ) 

#define ISpeechRecoContext_put_State(This,State)	\
    ( (This)->lpVtbl -> put_State(This,State) ) 

#define ISpeechRecoContext_get_State(This,State)	\
    ( (This)->lpVtbl -> get_State(This,State) ) 

#define ISpeechRecoContext_put_RetainedAudio(This,Option)	\
    ( (This)->lpVtbl -> put_RetainedAudio(This,Option) ) 

#define ISpeechRecoContext_get_RetainedAudio(This,Option)	\
    ( (This)->lpVtbl -> get_RetainedAudio(This,Option) ) 

#define ISpeechRecoContext_putref_RetainedAudioFormat(This,Format)	\
    ( (This)->lpVtbl -> putref_RetainedAudioFormat(This,Format) ) 

#define ISpeechRecoContext_get_RetainedAudioFormat(This,Format)	\
    ( (This)->lpVtbl -> get_RetainedAudioFormat(This,Format) ) 

#define ISpeechRecoContext_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define ISpeechRecoContext_Resume(This)	\
    ( (This)->lpVtbl -> Resume(This) ) 

#define ISpeechRecoContext_CreateGrammar(This,GrammarId,Grammar)	\
    ( (This)->lpVtbl -> CreateGrammar(This,GrammarId,Grammar) ) 

#define ISpeechRecoContext_CreateResultFromMemory(This,ResultBlock,Result)	\
    ( (This)->lpVtbl -> CreateResultFromMemory(This,ResultBlock,Result) ) 

#define ISpeechRecoContext_Bookmark(This,Options,StreamPos,BookmarkId)	\
    ( (This)->lpVtbl -> Bookmark(This,Options,StreamPos,BookmarkId) ) 

#define ISpeechRecoContext_SetAdaptationData(This,AdaptationString)	\
    ( (This)->lpVtbl -> SetAdaptationData(This,AdaptationString) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechRecoContext_INTERFACE_DEFINED__ */


#ifndef __ISpeechRecoGrammar_INTERFACE_DEFINED__
#define __ISpeechRecoGrammar_INTERFACE_DEFINED__

/* interface ISpeechRecoGrammar */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechRecoGrammar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B6D6F79F-2158-4e50-B5BC-9A9CCD852A09")
    ISpeechRecoGrammar : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ __RPC__out VARIANT *Id) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RecoContext( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoContext **RecoContext) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_State( 
            /* [in] */ SpeechGrammarState State) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ __RPC__out SpeechGrammarState *State) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Rules( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRules **Rules) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Reset( 
            /* [defaultvalue][in] */ SpeechLanguageId NewLanguage = 0) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CmdLoadFromFile( 
            /* [in] */ __RPC__in const BSTR FileName,
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption = SLOStatic) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CmdLoadFromObject( 
            /* [in] */ __RPC__in const BSTR ClassId,
            /* [in] */ __RPC__in const BSTR GrammarName,
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption = SLOStatic) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CmdLoadFromResource( 
            /* [in] */ long hModule,
            /* [in] */ VARIANT ResourceName,
            /* [in] */ VARIANT ResourceType,
            /* [in] */ SpeechLanguageId LanguageId,
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption = SLOStatic) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CmdLoadFromMemory( 
            /* [in] */ VARIANT GrammarData,
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption = SLOStatic) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CmdLoadFromProprietaryGrammar( 
            /* [in] */ __RPC__in const BSTR ProprietaryGuid,
            /* [in] */ __RPC__in const BSTR ProprietaryString,
            /* [in] */ VARIANT ProprietaryData,
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption = SLOStatic) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CmdSetRuleState( 
            /* [in] */ __RPC__in const BSTR Name,
            /* [in] */ SpeechRuleState State) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CmdSetRuleIdState( 
            /* [in] */ long RuleId,
            /* [in] */ SpeechRuleState State) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE DictationLoad( 
            /* [defaultvalue][in] */ __RPC__in const BSTR TopicName = (BSTR)L"",
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption = SLOStatic) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE DictationUnload( void) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE DictationSetState( 
            /* [in] */ SpeechRuleState State) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SetWordSequenceData( 
            /* [in] */ __RPC__in const BSTR Text,
            /* [in] */ long TextLength,
            /* [in] */ __RPC__in_opt ISpeechTextSelectionInformation *Info) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SetTextSelection( 
            /* [in] */ __RPC__in_opt ISpeechTextSelectionInformation *Info) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE IsPronounceable( 
            /* [in] */ __RPC__in const BSTR Word,
            /* [retval][out] */ __RPC__out SpeechWordPronounceable *WordPronounceable) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechRecoGrammarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechRecoGrammar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechRecoGrammar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechRecoGrammar * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [retval][out] */ __RPC__out VARIANT *Id);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecoContext )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoContext **RecoContext);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_State )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ SpeechGrammarState State);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [retval][out] */ __RPC__out SpeechGrammarState *State);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rules )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRules **Rules);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [defaultvalue][in] */ SpeechLanguageId NewLanguage);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CmdLoadFromFile )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ __RPC__in const BSTR FileName,
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CmdLoadFromObject )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ __RPC__in const BSTR ClassId,
            /* [in] */ __RPC__in const BSTR GrammarName,
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CmdLoadFromResource )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ long hModule,
            /* [in] */ VARIANT ResourceName,
            /* [in] */ VARIANT ResourceType,
            /* [in] */ SpeechLanguageId LanguageId,
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CmdLoadFromMemory )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ VARIANT GrammarData,
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CmdLoadFromProprietaryGrammar )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ __RPC__in const BSTR ProprietaryGuid,
            /* [in] */ __RPC__in const BSTR ProprietaryString,
            /* [in] */ VARIANT ProprietaryData,
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CmdSetRuleState )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ __RPC__in const BSTR Name,
            /* [in] */ SpeechRuleState State);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CmdSetRuleIdState )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ long RuleId,
            /* [in] */ SpeechRuleState State);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *DictationLoad )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [defaultvalue][in] */ __RPC__in const BSTR TopicName,
            /* [defaultvalue][in] */ SpeechLoadOption LoadOption);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *DictationUnload )( 
            __RPC__in ISpeechRecoGrammar * This);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *DictationSetState )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ SpeechRuleState State);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetWordSequenceData )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ __RPC__in const BSTR Text,
            /* [in] */ long TextLength,
            /* [in] */ __RPC__in_opt ISpeechTextSelectionInformation *Info);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetTextSelection )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ __RPC__in_opt ISpeechTextSelectionInformation *Info);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsPronounceable )( 
            __RPC__in ISpeechRecoGrammar * This,
            /* [in] */ __RPC__in const BSTR Word,
            /* [retval][out] */ __RPC__out SpeechWordPronounceable *WordPronounceable);
        
        END_INTERFACE
    } ISpeechRecoGrammarVtbl;

    interface ISpeechRecoGrammar
    {
        CONST_VTBL struct ISpeechRecoGrammarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechRecoGrammar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechRecoGrammar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechRecoGrammar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechRecoGrammar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechRecoGrammar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechRecoGrammar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechRecoGrammar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechRecoGrammar_get_Id(This,Id)	\
    ( (This)->lpVtbl -> get_Id(This,Id) ) 

#define ISpeechRecoGrammar_get_RecoContext(This,RecoContext)	\
    ( (This)->lpVtbl -> get_RecoContext(This,RecoContext) ) 

#define ISpeechRecoGrammar_put_State(This,State)	\
    ( (This)->lpVtbl -> put_State(This,State) ) 

#define ISpeechRecoGrammar_get_State(This,State)	\
    ( (This)->lpVtbl -> get_State(This,State) ) 

#define ISpeechRecoGrammar_get_Rules(This,Rules)	\
    ( (This)->lpVtbl -> get_Rules(This,Rules) ) 

#define ISpeechRecoGrammar_Reset(This,NewLanguage)	\
    ( (This)->lpVtbl -> Reset(This,NewLanguage) ) 

#define ISpeechRecoGrammar_CmdLoadFromFile(This,FileName,LoadOption)	\
    ( (This)->lpVtbl -> CmdLoadFromFile(This,FileName,LoadOption) ) 

#define ISpeechRecoGrammar_CmdLoadFromObject(This,ClassId,GrammarName,LoadOption)	\
    ( (This)->lpVtbl -> CmdLoadFromObject(This,ClassId,GrammarName,LoadOption) ) 

#define ISpeechRecoGrammar_CmdLoadFromResource(This,hModule,ResourceName,ResourceType,LanguageId,LoadOption)	\
    ( (This)->lpVtbl -> CmdLoadFromResource(This,hModule,ResourceName,ResourceType,LanguageId,LoadOption) ) 

#define ISpeechRecoGrammar_CmdLoadFromMemory(This,GrammarData,LoadOption)	\
    ( (This)->lpVtbl -> CmdLoadFromMemory(This,GrammarData,LoadOption) ) 

#define ISpeechRecoGrammar_CmdLoadFromProprietaryGrammar(This,ProprietaryGuid,ProprietaryString,ProprietaryData,LoadOption)	\
    ( (This)->lpVtbl -> CmdLoadFromProprietaryGrammar(This,ProprietaryGuid,ProprietaryString,ProprietaryData,LoadOption) ) 

#define ISpeechRecoGrammar_CmdSetRuleState(This,Name,State)	\
    ( (This)->lpVtbl -> CmdSetRuleState(This,Name,State) ) 

#define ISpeechRecoGrammar_CmdSetRuleIdState(This,RuleId,State)	\
    ( (This)->lpVtbl -> CmdSetRuleIdState(This,RuleId,State) ) 

#define ISpeechRecoGrammar_DictationLoad(This,TopicName,LoadOption)	\
    ( (This)->lpVtbl -> DictationLoad(This,TopicName,LoadOption) ) 

#define ISpeechRecoGrammar_DictationUnload(This)	\
    ( (This)->lpVtbl -> DictationUnload(This) ) 

#define ISpeechRecoGrammar_DictationSetState(This,State)	\
    ( (This)->lpVtbl -> DictationSetState(This,State) ) 

#define ISpeechRecoGrammar_SetWordSequenceData(This,Text,TextLength,Info)	\
    ( (This)->lpVtbl -> SetWordSequenceData(This,Text,TextLength,Info) ) 

#define ISpeechRecoGrammar_SetTextSelection(This,Info)	\
    ( (This)->lpVtbl -> SetTextSelection(This,Info) ) 

#define ISpeechRecoGrammar_IsPronounceable(This,Word,WordPronounceable)	\
    ( (This)->lpVtbl -> IsPronounceable(This,Word,WordPronounceable) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechRecoGrammar_INTERFACE_DEFINED__ */


#ifndef ___ISpeechRecoContextEvents_DISPINTERFACE_DEFINED__
#define ___ISpeechRecoContextEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ISpeechRecoContextEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__ISpeechRecoContextEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7B8FCB42-0E9D-4f00-A048-7B04D6179D3D")
    _ISpeechRecoContextEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ISpeechRecoContextEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in _ISpeechRecoContextEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in _ISpeechRecoContextEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in _ISpeechRecoContextEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in _ISpeechRecoContextEvents * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in _ISpeechRecoContextEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in _ISpeechRecoContextEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ISpeechRecoContextEvents * This,
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
    } _ISpeechRecoContextEventsVtbl;

    interface _ISpeechRecoContextEvents
    {
        CONST_VTBL struct _ISpeechRecoContextEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISpeechRecoContextEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ISpeechRecoContextEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ISpeechRecoContextEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ISpeechRecoContextEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ISpeechRecoContextEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ISpeechRecoContextEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ISpeechRecoContextEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ISpeechRecoContextEvents_DISPINTERFACE_DEFINED__ */


#ifndef __ISpeechGrammarRule_INTERFACE_DEFINED__
#define __ISpeechGrammarRule_INTERFACE_DEFINED__

/* interface ISpeechGrammarRule */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechGrammarRule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AFE719CF-5DD1-44f2-999C-7A399F1CFCCC")
    ISpeechGrammarRule : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Attributes( 
            /* [retval][out] */ __RPC__out SpeechRuleAttributes *Attributes) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_InitialState( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRuleState **State) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ __RPC__out long *Id) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE AddResource( 
            /* [in] */ __RPC__in const BSTR ResourceName,
            /* [in] */ __RPC__in const BSTR ResourceValue) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE AddState( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRuleState **State) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechGrammarRuleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechGrammarRule * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechGrammarRule * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechGrammarRule * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechGrammarRule * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechGrammarRule * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechGrammarRule * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechGrammarRule * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attributes )( 
            __RPC__in ISpeechGrammarRule * This,
            /* [retval][out] */ __RPC__out SpeechRuleAttributes *Attributes);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InitialState )( 
            __RPC__in ISpeechGrammarRule * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRuleState **State);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in ISpeechGrammarRule * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in ISpeechGrammarRule * This,
            /* [retval][out] */ __RPC__out long *Id);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            __RPC__in ISpeechGrammarRule * This);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddResource )( 
            __RPC__in ISpeechGrammarRule * This,
            /* [in] */ __RPC__in const BSTR ResourceName,
            /* [in] */ __RPC__in const BSTR ResourceValue);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddState )( 
            __RPC__in ISpeechGrammarRule * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRuleState **State);
        
        END_INTERFACE
    } ISpeechGrammarRuleVtbl;

    interface ISpeechGrammarRule
    {
        CONST_VTBL struct ISpeechGrammarRuleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechGrammarRule_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechGrammarRule_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechGrammarRule_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechGrammarRule_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechGrammarRule_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechGrammarRule_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechGrammarRule_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechGrammarRule_get_Attributes(This,Attributes)	\
    ( (This)->lpVtbl -> get_Attributes(This,Attributes) ) 

#define ISpeechGrammarRule_get_InitialState(This,State)	\
    ( (This)->lpVtbl -> get_InitialState(This,State) ) 

#define ISpeechGrammarRule_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define ISpeechGrammarRule_get_Id(This,Id)	\
    ( (This)->lpVtbl -> get_Id(This,Id) ) 

#define ISpeechGrammarRule_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define ISpeechGrammarRule_AddResource(This,ResourceName,ResourceValue)	\
    ( (This)->lpVtbl -> AddResource(This,ResourceName,ResourceValue) ) 

#define ISpeechGrammarRule_AddState(This,State)	\
    ( (This)->lpVtbl -> AddState(This,State) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechGrammarRule_INTERFACE_DEFINED__ */


#ifndef __ISpeechGrammarRules_INTERFACE_DEFINED__
#define __ISpeechGrammarRules_INTERFACE_DEFINED__

/* interface ISpeechGrammarRules */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechGrammarRules;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6FFA3B44-FC2D-40d1-8AFC-32911C7F1AD1")
    ISpeechGrammarRules : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *Count) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE FindRule( 
            /* [in] */ VARIANT RuleNameOrId,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRule **Rule) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRule **Rule) = 0;
        
        virtual /* [restricted][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Dynamic( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Dynamic) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ __RPC__in BSTR RuleName,
            /* [in] */ SpeechRuleAttributes Attributes,
            /* [defaultvalue][in] */ long RuleId,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRule **Rule) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Commit( void) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE CommitAndSave( 
            /* [out] */ __RPC__deref_out_opt BSTR *ErrorText,
            /* [retval][out] */ __RPC__out VARIANT *SaveStream) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechGrammarRulesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechGrammarRules * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechGrammarRules * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechGrammarRules * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechGrammarRules * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechGrammarRules * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechGrammarRules * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechGrammarRules * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in ISpeechGrammarRules * This,
            /* [retval][out] */ __RPC__out long *Count);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindRule )( 
            __RPC__in ISpeechGrammarRules * This,
            /* [in] */ VARIANT RuleNameOrId,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRule **Rule);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in ISpeechGrammarRules * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRule **Rule);
        
        /* [restricted][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in ISpeechGrammarRules * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dynamic )( 
            __RPC__in ISpeechGrammarRules * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Dynamic);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            __RPC__in ISpeechGrammarRules * This,
            /* [in] */ __RPC__in BSTR RuleName,
            /* [in] */ SpeechRuleAttributes Attributes,
            /* [defaultvalue][in] */ long RuleId,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRule **Rule);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in ISpeechGrammarRules * This);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CommitAndSave )( 
            __RPC__in ISpeechGrammarRules * This,
            /* [out] */ __RPC__deref_out_opt BSTR *ErrorText,
            /* [retval][out] */ __RPC__out VARIANT *SaveStream);
        
        END_INTERFACE
    } ISpeechGrammarRulesVtbl;

    interface ISpeechGrammarRules
    {
        CONST_VTBL struct ISpeechGrammarRulesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechGrammarRules_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechGrammarRules_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechGrammarRules_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechGrammarRules_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechGrammarRules_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechGrammarRules_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechGrammarRules_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechGrammarRules_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define ISpeechGrammarRules_FindRule(This,RuleNameOrId,Rule)	\
    ( (This)->lpVtbl -> FindRule(This,RuleNameOrId,Rule) ) 

#define ISpeechGrammarRules_Item(This,Index,Rule)	\
    ( (This)->lpVtbl -> Item(This,Index,Rule) ) 

#define ISpeechGrammarRules_get__NewEnum(This,EnumVARIANT)	\
    ( (This)->lpVtbl -> get__NewEnum(This,EnumVARIANT) ) 

#define ISpeechGrammarRules_get_Dynamic(This,Dynamic)	\
    ( (This)->lpVtbl -> get_Dynamic(This,Dynamic) ) 

#define ISpeechGrammarRules_Add(This,RuleName,Attributes,RuleId,Rule)	\
    ( (This)->lpVtbl -> Add(This,RuleName,Attributes,RuleId,Rule) ) 

#define ISpeechGrammarRules_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 

#define ISpeechGrammarRules_CommitAndSave(This,ErrorText,SaveStream)	\
    ( (This)->lpVtbl -> CommitAndSave(This,ErrorText,SaveStream) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechGrammarRules_INTERFACE_DEFINED__ */


#ifndef __ISpeechGrammarRuleState_INTERFACE_DEFINED__
#define __ISpeechGrammarRuleState_INTERFACE_DEFINED__

/* interface ISpeechGrammarRuleState */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechGrammarRuleState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D4286F2C-EE67-45ae-B928-28D695362EDA")
    ISpeechGrammarRuleState : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Rule( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRule **Rule) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Transitions( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRuleStateTransitions **Transitions) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE AddWordTransition( 
            /* [in] */ __RPC__in_opt ISpeechGrammarRuleState *DestState,
            /* [in] */ __RPC__in const BSTR Words,
            /* [defaultvalue][in] */ __RPC__in const BSTR Separators = (BSTR)L" ",
            /* [defaultvalue][in] */ SpeechGrammarWordType Type = SGLexical,
            /* [defaultvalue][in] */ __RPC__in const BSTR PropertyName = (BSTR)L"",
            /* [defaultvalue][in] */ long PropertyId = 0,
            /* [defaultvalue][in] */ __RPC__in VARIANT *PropertyValue = 0,
            /* [defaultvalue][in] */ float Weight = 1) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE AddRuleTransition( 
            /* [in] */ __RPC__in_opt ISpeechGrammarRuleState *DestinationState,
            /* [in] */ __RPC__in_opt ISpeechGrammarRule *Rule,
            /* [defaultvalue][in] */ __RPC__in const BSTR PropertyName = (BSTR)L"",
            /* [defaultvalue][in] */ long PropertyId = 0,
            /* [defaultvalue][in] */ __RPC__in VARIANT *PropertyValue = 0,
            /* [defaultvalue][in] */ float Weight = 1) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE AddSpecialTransition( 
            /* [in] */ __RPC__in_opt ISpeechGrammarRuleState *DestinationState,
            /* [in] */ SpeechSpecialTransitionType Type,
            /* [defaultvalue][in] */ __RPC__in const BSTR PropertyName = (BSTR)L"",
            /* [defaultvalue][in] */ long PropertyId = 0,
            /* [defaultvalue][in] */ __RPC__in VARIANT *PropertyValue = 0,
            /* [defaultvalue][in] */ float Weight = 1) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechGrammarRuleStateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechGrammarRuleState * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechGrammarRuleState * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechGrammarRuleState * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechGrammarRuleState * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechGrammarRuleState * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechGrammarRuleState * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechGrammarRuleState * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rule )( 
            __RPC__in ISpeechGrammarRuleState * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRule **Rule);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Transitions )( 
            __RPC__in ISpeechGrammarRuleState * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRuleStateTransitions **Transitions);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddWordTransition )( 
            __RPC__in ISpeechGrammarRuleState * This,
            /* [in] */ __RPC__in_opt ISpeechGrammarRuleState *DestState,
            /* [in] */ __RPC__in const BSTR Words,
            /* [defaultvalue][in] */ __RPC__in const BSTR Separators,
            /* [defaultvalue][in] */ SpeechGrammarWordType Type,
            /* [defaultvalue][in] */ __RPC__in const BSTR PropertyName,
            /* [defaultvalue][in] */ long PropertyId,
            /* [defaultvalue][in] */ __RPC__in VARIANT *PropertyValue,
            /* [defaultvalue][in] */ float Weight);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddRuleTransition )( 
            __RPC__in ISpeechGrammarRuleState * This,
            /* [in] */ __RPC__in_opt ISpeechGrammarRuleState *DestinationState,
            /* [in] */ __RPC__in_opt ISpeechGrammarRule *Rule,
            /* [defaultvalue][in] */ __RPC__in const BSTR PropertyName,
            /* [defaultvalue][in] */ long PropertyId,
            /* [defaultvalue][in] */ __RPC__in VARIANT *PropertyValue,
            /* [defaultvalue][in] */ float Weight);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddSpecialTransition )( 
            __RPC__in ISpeechGrammarRuleState * This,
            /* [in] */ __RPC__in_opt ISpeechGrammarRuleState *DestinationState,
            /* [in] */ SpeechSpecialTransitionType Type,
            /* [defaultvalue][in] */ __RPC__in const BSTR PropertyName,
            /* [defaultvalue][in] */ long PropertyId,
            /* [defaultvalue][in] */ __RPC__in VARIANT *PropertyValue,
            /* [defaultvalue][in] */ float Weight);
        
        END_INTERFACE
    } ISpeechGrammarRuleStateVtbl;

    interface ISpeechGrammarRuleState
    {
        CONST_VTBL struct ISpeechGrammarRuleStateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechGrammarRuleState_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechGrammarRuleState_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechGrammarRuleState_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechGrammarRuleState_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechGrammarRuleState_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechGrammarRuleState_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechGrammarRuleState_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechGrammarRuleState_get_Rule(This,Rule)	\
    ( (This)->lpVtbl -> get_Rule(This,Rule) ) 

#define ISpeechGrammarRuleState_get_Transitions(This,Transitions)	\
    ( (This)->lpVtbl -> get_Transitions(This,Transitions) ) 

#define ISpeechGrammarRuleState_AddWordTransition(This,DestState,Words,Separators,Type,PropertyName,PropertyId,PropertyValue,Weight)	\
    ( (This)->lpVtbl -> AddWordTransition(This,DestState,Words,Separators,Type,PropertyName,PropertyId,PropertyValue,Weight) ) 

#define ISpeechGrammarRuleState_AddRuleTransition(This,DestinationState,Rule,PropertyName,PropertyId,PropertyValue,Weight)	\
    ( (This)->lpVtbl -> AddRuleTransition(This,DestinationState,Rule,PropertyName,PropertyId,PropertyValue,Weight) ) 

#define ISpeechGrammarRuleState_AddSpecialTransition(This,DestinationState,Type,PropertyName,PropertyId,PropertyValue,Weight)	\
    ( (This)->lpVtbl -> AddSpecialTransition(This,DestinationState,Type,PropertyName,PropertyId,PropertyValue,Weight) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechGrammarRuleState_INTERFACE_DEFINED__ */


#ifndef __ISpeechGrammarRuleStateTransition_INTERFACE_DEFINED__
#define __ISpeechGrammarRuleStateTransition_INTERFACE_DEFINED__

/* interface ISpeechGrammarRuleStateTransition */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechGrammarRuleStateTransition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CAFD1DB1-41D1-4a06-9863-E2E81DA17A9A")
    ISpeechGrammarRuleStateTransition : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ __RPC__out SpeechGrammarRuleStateTransitionType *Type) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Text) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Rule( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRule **Rule) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Weight( 
            /* [retval][out] */ __RPC__out VARIANT *Weight) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PropertyName( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *PropertyName) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PropertyId( 
            /* [retval][out] */ __RPC__out long *PropertyId) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PropertyValue( 
            /* [retval][out] */ __RPC__out VARIANT *PropertyValue) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NextState( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRuleState **NextState) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechGrammarRuleStateTransitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechGrammarRuleStateTransition * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [retval][out] */ __RPC__out SpeechGrammarRuleStateTransitionType *Type);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Text);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rule )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRule **Rule);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Weight )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [retval][out] */ __RPC__out VARIANT *Weight);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropertyName )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *PropertyName);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropertyId )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [retval][out] */ __RPC__out long *PropertyId);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropertyValue )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [retval][out] */ __RPC__out VARIANT *PropertyValue);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NextState )( 
            __RPC__in ISpeechGrammarRuleStateTransition * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRuleState **NextState);
        
        END_INTERFACE
    } ISpeechGrammarRuleStateTransitionVtbl;

    interface ISpeechGrammarRuleStateTransition
    {
        CONST_VTBL struct ISpeechGrammarRuleStateTransitionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechGrammarRuleStateTransition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechGrammarRuleStateTransition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechGrammarRuleStateTransition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechGrammarRuleStateTransition_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechGrammarRuleStateTransition_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechGrammarRuleStateTransition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechGrammarRuleStateTransition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechGrammarRuleStateTransition_get_Type(This,Type)	\
    ( (This)->lpVtbl -> get_Type(This,Type) ) 

#define ISpeechGrammarRuleStateTransition_get_Text(This,Text)	\
    ( (This)->lpVtbl -> get_Text(This,Text) ) 

#define ISpeechGrammarRuleStateTransition_get_Rule(This,Rule)	\
    ( (This)->lpVtbl -> get_Rule(This,Rule) ) 

#define ISpeechGrammarRuleStateTransition_get_Weight(This,Weight)	\
    ( (This)->lpVtbl -> get_Weight(This,Weight) ) 

#define ISpeechGrammarRuleStateTransition_get_PropertyName(This,PropertyName)	\
    ( (This)->lpVtbl -> get_PropertyName(This,PropertyName) ) 

#define ISpeechGrammarRuleStateTransition_get_PropertyId(This,PropertyId)	\
    ( (This)->lpVtbl -> get_PropertyId(This,PropertyId) ) 

#define ISpeechGrammarRuleStateTransition_get_PropertyValue(This,PropertyValue)	\
    ( (This)->lpVtbl -> get_PropertyValue(This,PropertyValue) ) 

#define ISpeechGrammarRuleStateTransition_get_NextState(This,NextState)	\
    ( (This)->lpVtbl -> get_NextState(This,NextState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechGrammarRuleStateTransition_INTERFACE_DEFINED__ */


#ifndef __ISpeechGrammarRuleStateTransitions_INTERFACE_DEFINED__
#define __ISpeechGrammarRuleStateTransitions_INTERFACE_DEFINED__

/* interface ISpeechGrammarRuleStateTransitions */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechGrammarRuleStateTransitions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EABCE657-75BC-44a2-AA7F-C56476742963")
    ISpeechGrammarRuleStateTransitions : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *Count) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRuleStateTransition **Transition) = 0;
        
        virtual /* [id][restricted][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechGrammarRuleStateTransitionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechGrammarRuleStateTransitions * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechGrammarRuleStateTransitions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechGrammarRuleStateTransitions * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechGrammarRuleStateTransitions * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechGrammarRuleStateTransitions * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechGrammarRuleStateTransitions * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechGrammarRuleStateTransitions * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in ISpeechGrammarRuleStateTransitions * This,
            /* [retval][out] */ __RPC__out long *Count);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in ISpeechGrammarRuleStateTransitions * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechGrammarRuleStateTransition **Transition);
        
        /* [id][restricted][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in ISpeechGrammarRuleStateTransitions * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT);
        
        END_INTERFACE
    } ISpeechGrammarRuleStateTransitionsVtbl;

    interface ISpeechGrammarRuleStateTransitions
    {
        CONST_VTBL struct ISpeechGrammarRuleStateTransitionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechGrammarRuleStateTransitions_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechGrammarRuleStateTransitions_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechGrammarRuleStateTransitions_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechGrammarRuleStateTransitions_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechGrammarRuleStateTransitions_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechGrammarRuleStateTransitions_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechGrammarRuleStateTransitions_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechGrammarRuleStateTransitions_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define ISpeechGrammarRuleStateTransitions_Item(This,Index,Transition)	\
    ( (This)->lpVtbl -> Item(This,Index,Transition) ) 

#define ISpeechGrammarRuleStateTransitions_get__NewEnum(This,EnumVARIANT)	\
    ( (This)->lpVtbl -> get__NewEnum(This,EnumVARIANT) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechGrammarRuleStateTransitions_INTERFACE_DEFINED__ */


#ifndef __ISpeechTextSelectionInformation_INTERFACE_DEFINED__
#define __ISpeechTextSelectionInformation_INTERFACE_DEFINED__

/* interface ISpeechTextSelectionInformation */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechTextSelectionInformation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3B9C7E7A-6EEE-4DED-9092-11657279ADBE")
    ISpeechTextSelectionInformation : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActiveOffset( 
            /* [in] */ long ActiveOffset) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveOffset( 
            /* [retval][out] */ __RPC__out long *ActiveOffset) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActiveLength( 
            /* [in] */ long ActiveLength) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveLength( 
            /* [retval][out] */ __RPC__out long *ActiveLength) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SelectionOffset( 
            /* [in] */ long SelectionOffset) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SelectionOffset( 
            /* [retval][out] */ __RPC__out long *SelectionOffset) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SelectionLength( 
            /* [in] */ long SelectionLength) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SelectionLength( 
            /* [retval][out] */ __RPC__out long *SelectionLength) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechTextSelectionInformationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechTextSelectionInformation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechTextSelectionInformation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechTextSelectionInformation * This,
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
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveOffset )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [in] */ long ActiveOffset);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveOffset )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [retval][out] */ __RPC__out long *ActiveOffset);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveLength )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [in] */ long ActiveLength);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveLength )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [retval][out] */ __RPC__out long *ActiveLength);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SelectionOffset )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [in] */ long SelectionOffset);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SelectionOffset )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [retval][out] */ __RPC__out long *SelectionOffset);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SelectionLength )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [in] */ long SelectionLength);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SelectionLength )( 
            __RPC__in ISpeechTextSelectionInformation * This,
            /* [retval][out] */ __RPC__out long *SelectionLength);
        
        END_INTERFACE
    } ISpeechTextSelectionInformationVtbl;

    interface ISpeechTextSelectionInformation
    {
        CONST_VTBL struct ISpeechTextSelectionInformationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechTextSelectionInformation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechTextSelectionInformation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechTextSelectionInformation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechTextSelectionInformation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechTextSelectionInformation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechTextSelectionInformation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechTextSelectionInformation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechTextSelectionInformation_put_ActiveOffset(This,ActiveOffset)	\
    ( (This)->lpVtbl -> put_ActiveOffset(This,ActiveOffset) ) 

#define ISpeechTextSelectionInformation_get_ActiveOffset(This,ActiveOffset)	\
    ( (This)->lpVtbl -> get_ActiveOffset(This,ActiveOffset) ) 

#define ISpeechTextSelectionInformation_put_ActiveLength(This,ActiveLength)	\
    ( (This)->lpVtbl -> put_ActiveLength(This,ActiveLength) ) 

#define ISpeechTextSelectionInformation_get_ActiveLength(This,ActiveLength)	\
    ( (This)->lpVtbl -> get_ActiveLength(This,ActiveLength) ) 

#define ISpeechTextSelectionInformation_put_SelectionOffset(This,SelectionOffset)	\
    ( (This)->lpVtbl -> put_SelectionOffset(This,SelectionOffset) ) 

#define ISpeechTextSelectionInformation_get_SelectionOffset(This,SelectionOffset)	\
    ( (This)->lpVtbl -> get_SelectionOffset(This,SelectionOffset) ) 

#define ISpeechTextSelectionInformation_put_SelectionLength(This,SelectionLength)	\
    ( (This)->lpVtbl -> put_SelectionLength(This,SelectionLength) ) 

#define ISpeechTextSelectionInformation_get_SelectionLength(This,SelectionLength)	\
    ( (This)->lpVtbl -> get_SelectionLength(This,SelectionLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechTextSelectionInformation_INTERFACE_DEFINED__ */


#ifndef __ISpeechRecoResult_INTERFACE_DEFINED__
#define __ISpeechRecoResult_INTERFACE_DEFINED__

/* interface ISpeechRecoResult */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechRecoResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ED2879CF-CED9-4ee6-A534-DE0191D5468D")
    ISpeechRecoResult : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RecoContext( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoContext **RecoContext) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Times( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoResultTimes **Times) = 0;
        
        virtual /* [id][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_AudioFormat( 
            /* [in] */ __RPC__in_opt ISpeechAudioFormat *Format) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioFormat( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **Format) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PhraseInfo( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseInfo **PhraseInfo) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Alternates( 
            /* [in] */ long RequestCount,
            /* [defaultvalue][in] */ long StartElement,
            /* [defaultvalue][in] */ long Elements,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseAlternates **Alternates) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Audio( 
            /* [defaultvalue][in] */ long StartElement,
            /* [defaultvalue][in] */ long Elements,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechMemoryStream **Stream) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SpeakAudio( 
            /* [defaultvalue][in] */ long StartElement,
            /* [defaultvalue][in] */ long Elements,
            /* [defaultvalue][in] */ SpeechVoiceSpeakFlags Flags,
            /* [retval][out] */ __RPC__out long *StreamNumber) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SaveToMemory( 
            /* [retval][out] */ __RPC__out VARIANT *ResultBlock) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE DiscardResultInfo( 
            /* [in] */ SpeechDiscardType ValueTypes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechRecoResultVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechRecoResult * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechRecoResult * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechRecoResult * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechRecoResult * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechRecoResult * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechRecoResult * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechRecoResult * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecoContext )( 
            __RPC__in ISpeechRecoResult * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoContext **RecoContext);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Times )( 
            __RPC__in ISpeechRecoResult * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoResultTimes **Times);
        
        /* [id][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_AudioFormat )( 
            __RPC__in ISpeechRecoResult * This,
            /* [in] */ __RPC__in_opt ISpeechAudioFormat *Format);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioFormat )( 
            __RPC__in ISpeechRecoResult * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechAudioFormat **Format);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhraseInfo )( 
            __RPC__in ISpeechRecoResult * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseInfo **PhraseInfo);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Alternates )( 
            __RPC__in ISpeechRecoResult * This,
            /* [in] */ long RequestCount,
            /* [defaultvalue][in] */ long StartElement,
            /* [defaultvalue][in] */ long Elements,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseAlternates **Alternates);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Audio )( 
            __RPC__in ISpeechRecoResult * This,
            /* [defaultvalue][in] */ long StartElement,
            /* [defaultvalue][in] */ long Elements,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechMemoryStream **Stream);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SpeakAudio )( 
            __RPC__in ISpeechRecoResult * This,
            /* [defaultvalue][in] */ long StartElement,
            /* [defaultvalue][in] */ long Elements,
            /* [defaultvalue][in] */ SpeechVoiceSpeakFlags Flags,
            /* [retval][out] */ __RPC__out long *StreamNumber);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SaveToMemory )( 
            __RPC__in ISpeechRecoResult * This,
            /* [retval][out] */ __RPC__out VARIANT *ResultBlock);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *DiscardResultInfo )( 
            __RPC__in ISpeechRecoResult * This,
            /* [in] */ SpeechDiscardType ValueTypes);
        
        END_INTERFACE
    } ISpeechRecoResultVtbl;

    interface ISpeechRecoResult
    {
        CONST_VTBL struct ISpeechRecoResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechRecoResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechRecoResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechRecoResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechRecoResult_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechRecoResult_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechRecoResult_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechRecoResult_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechRecoResult_get_RecoContext(This,RecoContext)	\
    ( (This)->lpVtbl -> get_RecoContext(This,RecoContext) ) 

#define ISpeechRecoResult_get_Times(This,Times)	\
    ( (This)->lpVtbl -> get_Times(This,Times) ) 

#define ISpeechRecoResult_putref_AudioFormat(This,Format)	\
    ( (This)->lpVtbl -> putref_AudioFormat(This,Format) ) 

#define ISpeechRecoResult_get_AudioFormat(This,Format)	\
    ( (This)->lpVtbl -> get_AudioFormat(This,Format) ) 

#define ISpeechRecoResult_get_PhraseInfo(This,PhraseInfo)	\
    ( (This)->lpVtbl -> get_PhraseInfo(This,PhraseInfo) ) 

#define ISpeechRecoResult_Alternates(This,RequestCount,StartElement,Elements,Alternates)	\
    ( (This)->lpVtbl -> Alternates(This,RequestCount,StartElement,Elements,Alternates) ) 

#define ISpeechRecoResult_Audio(This,StartElement,Elements,Stream)	\
    ( (This)->lpVtbl -> Audio(This,StartElement,Elements,Stream) ) 

#define ISpeechRecoResult_SpeakAudio(This,StartElement,Elements,Flags,StreamNumber)	\
    ( (This)->lpVtbl -> SpeakAudio(This,StartElement,Elements,Flags,StreamNumber) ) 

#define ISpeechRecoResult_SaveToMemory(This,ResultBlock)	\
    ( (This)->lpVtbl -> SaveToMemory(This,ResultBlock) ) 

#define ISpeechRecoResult_DiscardResultInfo(This,ValueTypes)	\
    ( (This)->lpVtbl -> DiscardResultInfo(This,ValueTypes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechRecoResult_INTERFACE_DEFINED__ */


#ifndef __ISpeechRecoResultTimes_INTERFACE_DEFINED__
#define __ISpeechRecoResultTimes_INTERFACE_DEFINED__

/* interface ISpeechRecoResultTimes */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechRecoResultTimes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("62B3B8FB-F6E7-41be-BDCB-056B1C29EFC0")
    ISpeechRecoResultTimes : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_StreamTime( 
            /* [retval][out] */ __RPC__out VARIANT *Time) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ __RPC__out VARIANT *Length) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_TickCount( 
            /* [retval][out] */ __RPC__out long *TickCount) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_OffsetFromStart( 
            /* [retval][out] */ __RPC__out VARIANT *OffsetFromStart) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechRecoResultTimesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechRecoResultTimes * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechRecoResultTimes * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechRecoResultTimes * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechRecoResultTimes * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechRecoResultTimes * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechRecoResultTimes * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechRecoResultTimes * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamTime )( 
            __RPC__in ISpeechRecoResultTimes * This,
            /* [retval][out] */ __RPC__out VARIANT *Time);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            __RPC__in ISpeechRecoResultTimes * This,
            /* [retval][out] */ __RPC__out VARIANT *Length);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TickCount )( 
            __RPC__in ISpeechRecoResultTimes * This,
            /* [retval][out] */ __RPC__out long *TickCount);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OffsetFromStart )( 
            __RPC__in ISpeechRecoResultTimes * This,
            /* [retval][out] */ __RPC__out VARIANT *OffsetFromStart);
        
        END_INTERFACE
    } ISpeechRecoResultTimesVtbl;

    interface ISpeechRecoResultTimes
    {
        CONST_VTBL struct ISpeechRecoResultTimesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechRecoResultTimes_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechRecoResultTimes_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechRecoResultTimes_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechRecoResultTimes_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechRecoResultTimes_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechRecoResultTimes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechRecoResultTimes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechRecoResultTimes_get_StreamTime(This,Time)	\
    ( (This)->lpVtbl -> get_StreamTime(This,Time) ) 

#define ISpeechRecoResultTimes_get_Length(This,Length)	\
    ( (This)->lpVtbl -> get_Length(This,Length) ) 

#define ISpeechRecoResultTimes_get_TickCount(This,TickCount)	\
    ( (This)->lpVtbl -> get_TickCount(This,TickCount) ) 

#define ISpeechRecoResultTimes_get_OffsetFromStart(This,OffsetFromStart)	\
    ( (This)->lpVtbl -> get_OffsetFromStart(This,OffsetFromStart) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechRecoResultTimes_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhraseAlternate_INTERFACE_DEFINED__
#define __ISpeechPhraseAlternate_INTERFACE_DEFINED__

/* interface ISpeechPhraseAlternate */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseAlternate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("27864A2A-2B9F-4cb8-92D3-0D2722FD1E73")
    ISpeechPhraseAlternate : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RecoResult( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoResult **RecoResult) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_StartElementInResult( 
            /* [retval][out] */ __RPC__out long *StartElement) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NumberOfElementsInResult( 
            /* [retval][out] */ __RPC__out long *NumberOfElements) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PhraseInfo( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseInfo **PhraseInfo) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Commit( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhraseAlternateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseAlternate * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseAlternate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseAlternate * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseAlternate * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseAlternate * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseAlternate * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseAlternate * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecoResult )( 
            __RPC__in ISpeechPhraseAlternate * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechRecoResult **RecoResult);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartElementInResult )( 
            __RPC__in ISpeechPhraseAlternate * This,
            /* [retval][out] */ __RPC__out long *StartElement);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumberOfElementsInResult )( 
            __RPC__in ISpeechPhraseAlternate * This,
            /* [retval][out] */ __RPC__out long *NumberOfElements);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PhraseInfo )( 
            __RPC__in ISpeechPhraseAlternate * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseInfo **PhraseInfo);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            __RPC__in ISpeechPhraseAlternate * This);
        
        END_INTERFACE
    } ISpeechPhraseAlternateVtbl;

    interface ISpeechPhraseAlternate
    {
        CONST_VTBL struct ISpeechPhraseAlternateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseAlternate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseAlternate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseAlternate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseAlternate_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseAlternate_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseAlternate_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseAlternate_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseAlternate_get_RecoResult(This,RecoResult)	\
    ( (This)->lpVtbl -> get_RecoResult(This,RecoResult) ) 

#define ISpeechPhraseAlternate_get_StartElementInResult(This,StartElement)	\
    ( (This)->lpVtbl -> get_StartElementInResult(This,StartElement) ) 

#define ISpeechPhraseAlternate_get_NumberOfElementsInResult(This,NumberOfElements)	\
    ( (This)->lpVtbl -> get_NumberOfElementsInResult(This,NumberOfElements) ) 

#define ISpeechPhraseAlternate_get_PhraseInfo(This,PhraseInfo)	\
    ( (This)->lpVtbl -> get_PhraseInfo(This,PhraseInfo) ) 

#define ISpeechPhraseAlternate_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseAlternate_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhraseAlternates_INTERFACE_DEFINED__
#define __ISpeechPhraseAlternates_INTERFACE_DEFINED__

/* interface ISpeechPhraseAlternates */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseAlternates;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B238B6D5-F276-4c3d-A6C1-2974801C3CC2")
    ISpeechPhraseAlternates : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *Count) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseAlternate **PhraseAlternate) = 0;
        
        virtual /* [id][restricted][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhraseAlternatesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseAlternates * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseAlternates * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseAlternates * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseAlternates * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseAlternates * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseAlternates * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseAlternates * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in ISpeechPhraseAlternates * This,
            /* [retval][out] */ __RPC__out long *Count);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in ISpeechPhraseAlternates * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseAlternate **PhraseAlternate);
        
        /* [id][restricted][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in ISpeechPhraseAlternates * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT);
        
        END_INTERFACE
    } ISpeechPhraseAlternatesVtbl;

    interface ISpeechPhraseAlternates
    {
        CONST_VTBL struct ISpeechPhraseAlternatesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseAlternates_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseAlternates_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseAlternates_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseAlternates_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseAlternates_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseAlternates_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseAlternates_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseAlternates_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define ISpeechPhraseAlternates_Item(This,Index,PhraseAlternate)	\
    ( (This)->lpVtbl -> Item(This,Index,PhraseAlternate) ) 

#define ISpeechPhraseAlternates_get__NewEnum(This,EnumVARIANT)	\
    ( (This)->lpVtbl -> get__NewEnum(This,EnumVARIANT) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseAlternates_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhraseInfo_INTERFACE_DEFINED__
#define __ISpeechPhraseInfo_INTERFACE_DEFINED__

/* interface ISpeechPhraseInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("961559CF-4E67-4662-8BF0-D93F1FCD61B3")
    ISpeechPhraseInfo : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LanguageId( 
            /* [retval][out] */ __RPC__out long *LanguageId) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_GrammarId( 
            /* [retval][out] */ __RPC__out VARIANT *GrammarId) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_StartTime( 
            /* [retval][out] */ __RPC__out VARIANT *StartTime) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioStreamPosition( 
            /* [retval][out] */ __RPC__out VARIANT *AudioStreamPosition) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioSizeBytes( 
            /* [retval][out] */ __RPC__out long *pAudioSizeBytes) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RetainedSizeBytes( 
            /* [retval][out] */ __RPC__out long *RetainedSizeBytes) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioSizeTime( 
            /* [retval][out] */ __RPC__out long *AudioSizeTime) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Rule( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseRule **Rule) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Properties( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseProperties **Properties) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Elements( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseElements **Elements) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Replacements( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseReplacements **Replacements) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EngineId( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *EngineIdGuid) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EnginePrivateData( 
            /* [retval][out] */ __RPC__out VARIANT *PrivateData) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE SaveToMemory( 
            /* [retval][out] */ __RPC__out VARIANT *PhraseBlock) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetText( 
            /* [defaultvalue][in] */ long StartElement,
            /* [defaultvalue][in] */ long Elements,
            /* [defaultvalue][in] */ VARIANT_BOOL UseReplacements,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Text) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetDisplayAttributes( 
            /* [defaultvalue][in] */ long StartElement,
            /* [defaultvalue][in] */ long Elements,
            /* [defaultvalue][in] */ VARIANT_BOOL UseReplacements,
            /* [retval][out] */ __RPC__out SpeechDisplayAttributes *DisplayAttributes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhraseInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseInfo * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LanguageId )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__out long *LanguageId);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GrammarId )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__out VARIANT *GrammarId);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartTime )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__out VARIANT *StartTime);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioStreamPosition )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__out VARIANT *AudioStreamPosition);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioSizeBytes )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__out long *pAudioSizeBytes);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RetainedSizeBytes )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__out long *RetainedSizeBytes);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioSizeTime )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__out long *AudioSizeTime);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rule )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseRule **Rule);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Properties )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseProperties **Properties);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Elements )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseElements **Elements);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Replacements )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseReplacements **Replacements);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EngineId )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *EngineIdGuid);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnginePrivateData )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__out VARIANT *PrivateData);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SaveToMemory )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [retval][out] */ __RPC__out VARIANT *PhraseBlock);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetText )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [defaultvalue][in] */ long StartElement,
            /* [defaultvalue][in] */ long Elements,
            /* [defaultvalue][in] */ VARIANT_BOOL UseReplacements,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Text);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDisplayAttributes )( 
            __RPC__in ISpeechPhraseInfo * This,
            /* [defaultvalue][in] */ long StartElement,
            /* [defaultvalue][in] */ long Elements,
            /* [defaultvalue][in] */ VARIANT_BOOL UseReplacements,
            /* [retval][out] */ __RPC__out SpeechDisplayAttributes *DisplayAttributes);
        
        END_INTERFACE
    } ISpeechPhraseInfoVtbl;

    interface ISpeechPhraseInfo
    {
        CONST_VTBL struct ISpeechPhraseInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseInfo_get_LanguageId(This,LanguageId)	\
    ( (This)->lpVtbl -> get_LanguageId(This,LanguageId) ) 

#define ISpeechPhraseInfo_get_GrammarId(This,GrammarId)	\
    ( (This)->lpVtbl -> get_GrammarId(This,GrammarId) ) 

#define ISpeechPhraseInfo_get_StartTime(This,StartTime)	\
    ( (This)->lpVtbl -> get_StartTime(This,StartTime) ) 

#define ISpeechPhraseInfo_get_AudioStreamPosition(This,AudioStreamPosition)	\
    ( (This)->lpVtbl -> get_AudioStreamPosition(This,AudioStreamPosition) ) 

#define ISpeechPhraseInfo_get_AudioSizeBytes(This,pAudioSizeBytes)	\
    ( (This)->lpVtbl -> get_AudioSizeBytes(This,pAudioSizeBytes) ) 

#define ISpeechPhraseInfo_get_RetainedSizeBytes(This,RetainedSizeBytes)	\
    ( (This)->lpVtbl -> get_RetainedSizeBytes(This,RetainedSizeBytes) ) 

#define ISpeechPhraseInfo_get_AudioSizeTime(This,AudioSizeTime)	\
    ( (This)->lpVtbl -> get_AudioSizeTime(This,AudioSizeTime) ) 

#define ISpeechPhraseInfo_get_Rule(This,Rule)	\
    ( (This)->lpVtbl -> get_Rule(This,Rule) ) 

#define ISpeechPhraseInfo_get_Properties(This,Properties)	\
    ( (This)->lpVtbl -> get_Properties(This,Properties) ) 

#define ISpeechPhraseInfo_get_Elements(This,Elements)	\
    ( (This)->lpVtbl -> get_Elements(This,Elements) ) 

#define ISpeechPhraseInfo_get_Replacements(This,Replacements)	\
    ( (This)->lpVtbl -> get_Replacements(This,Replacements) ) 

#define ISpeechPhraseInfo_get_EngineId(This,EngineIdGuid)	\
    ( (This)->lpVtbl -> get_EngineId(This,EngineIdGuid) ) 

#define ISpeechPhraseInfo_get_EnginePrivateData(This,PrivateData)	\
    ( (This)->lpVtbl -> get_EnginePrivateData(This,PrivateData) ) 

#define ISpeechPhraseInfo_SaveToMemory(This,PhraseBlock)	\
    ( (This)->lpVtbl -> SaveToMemory(This,PhraseBlock) ) 

#define ISpeechPhraseInfo_GetText(This,StartElement,Elements,UseReplacements,Text)	\
    ( (This)->lpVtbl -> GetText(This,StartElement,Elements,UseReplacements,Text) ) 

#define ISpeechPhraseInfo_GetDisplayAttributes(This,StartElement,Elements,UseReplacements,DisplayAttributes)	\
    ( (This)->lpVtbl -> GetDisplayAttributes(This,StartElement,Elements,UseReplacements,DisplayAttributes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseInfo_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhraseElement_INTERFACE_DEFINED__
#define __ISpeechPhraseElement_INTERFACE_DEFINED__

/* interface ISpeechPhraseElement */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseElement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E6176F96-E373-4801-B223-3B62C068C0B4")
    ISpeechPhraseElement : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioTimeOffset( 
            /* [retval][out] */ __RPC__out long *AudioTimeOffset) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioSizeTime( 
            /* [retval][out] */ __RPC__out long *AudioSizeTime) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioStreamOffset( 
            /* [retval][out] */ __RPC__out long *AudioStreamOffset) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioSizeBytes( 
            /* [retval][out] */ __RPC__out long *AudioSizeBytes) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RetainedStreamOffset( 
            /* [retval][out] */ __RPC__out long *RetainedStreamOffset) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RetainedSizeBytes( 
            /* [retval][out] */ __RPC__out long *RetainedSizeBytes) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayText( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *DisplayText) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LexicalForm( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *LexicalForm) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Pronunciation( 
            /* [retval][out] */ __RPC__out VARIANT *Pronunciation) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayAttributes( 
            /* [retval][out] */ __RPC__out SpeechDisplayAttributes *DisplayAttributes) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RequiredConfidence( 
            /* [retval][out] */ __RPC__out SpeechEngineConfidence *RequiredConfidence) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActualConfidence( 
            /* [retval][out] */ __RPC__out SpeechEngineConfidence *ActualConfidence) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EngineConfidence( 
            /* [retval][out] */ __RPC__out float *EngineConfidence) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhraseElementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseElement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseElement * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseElement * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioTimeOffset )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__out long *AudioTimeOffset);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioSizeTime )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__out long *AudioSizeTime);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioStreamOffset )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__out long *AudioStreamOffset);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioSizeBytes )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__out long *AudioSizeBytes);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RetainedStreamOffset )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__out long *RetainedStreamOffset);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RetainedSizeBytes )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__out long *RetainedSizeBytes);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayText )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *DisplayText);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LexicalForm )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *LexicalForm);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pronunciation )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__out VARIANT *Pronunciation);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayAttributes )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__out SpeechDisplayAttributes *DisplayAttributes);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequiredConfidence )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__out SpeechEngineConfidence *RequiredConfidence);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActualConfidence )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__out SpeechEngineConfidence *ActualConfidence);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EngineConfidence )( 
            __RPC__in ISpeechPhraseElement * This,
            /* [retval][out] */ __RPC__out float *EngineConfidence);
        
        END_INTERFACE
    } ISpeechPhraseElementVtbl;

    interface ISpeechPhraseElement
    {
        CONST_VTBL struct ISpeechPhraseElementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseElement_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseElement_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseElement_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseElement_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseElement_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseElement_get_AudioTimeOffset(This,AudioTimeOffset)	\
    ( (This)->lpVtbl -> get_AudioTimeOffset(This,AudioTimeOffset) ) 

#define ISpeechPhraseElement_get_AudioSizeTime(This,AudioSizeTime)	\
    ( (This)->lpVtbl -> get_AudioSizeTime(This,AudioSizeTime) ) 

#define ISpeechPhraseElement_get_AudioStreamOffset(This,AudioStreamOffset)	\
    ( (This)->lpVtbl -> get_AudioStreamOffset(This,AudioStreamOffset) ) 

#define ISpeechPhraseElement_get_AudioSizeBytes(This,AudioSizeBytes)	\
    ( (This)->lpVtbl -> get_AudioSizeBytes(This,AudioSizeBytes) ) 

#define ISpeechPhraseElement_get_RetainedStreamOffset(This,RetainedStreamOffset)	\
    ( (This)->lpVtbl -> get_RetainedStreamOffset(This,RetainedStreamOffset) ) 

#define ISpeechPhraseElement_get_RetainedSizeBytes(This,RetainedSizeBytes)	\
    ( (This)->lpVtbl -> get_RetainedSizeBytes(This,RetainedSizeBytes) ) 

#define ISpeechPhraseElement_get_DisplayText(This,DisplayText)	\
    ( (This)->lpVtbl -> get_DisplayText(This,DisplayText) ) 

#define ISpeechPhraseElement_get_LexicalForm(This,LexicalForm)	\
    ( (This)->lpVtbl -> get_LexicalForm(This,LexicalForm) ) 

#define ISpeechPhraseElement_get_Pronunciation(This,Pronunciation)	\
    ( (This)->lpVtbl -> get_Pronunciation(This,Pronunciation) ) 

#define ISpeechPhraseElement_get_DisplayAttributes(This,DisplayAttributes)	\
    ( (This)->lpVtbl -> get_DisplayAttributes(This,DisplayAttributes) ) 

#define ISpeechPhraseElement_get_RequiredConfidence(This,RequiredConfidence)	\
    ( (This)->lpVtbl -> get_RequiredConfidence(This,RequiredConfidence) ) 

#define ISpeechPhraseElement_get_ActualConfidence(This,ActualConfidence)	\
    ( (This)->lpVtbl -> get_ActualConfidence(This,ActualConfidence) ) 

#define ISpeechPhraseElement_get_EngineConfidence(This,EngineConfidence)	\
    ( (This)->lpVtbl -> get_EngineConfidence(This,EngineConfidence) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseElement_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhraseElements_INTERFACE_DEFINED__
#define __ISpeechPhraseElements_INTERFACE_DEFINED__

/* interface ISpeechPhraseElements */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseElements;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0626B328-3478-467d-A0B3-D0853B93DDA3")
    ISpeechPhraseElements : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *Count) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseElement **Element) = 0;
        
        virtual /* [id][restricted][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhraseElementsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseElements * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseElements * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseElements * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseElements * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseElements * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseElements * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseElements * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in ISpeechPhraseElements * This,
            /* [retval][out] */ __RPC__out long *Count);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in ISpeechPhraseElements * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseElement **Element);
        
        /* [id][restricted][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in ISpeechPhraseElements * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT);
        
        END_INTERFACE
    } ISpeechPhraseElementsVtbl;

    interface ISpeechPhraseElements
    {
        CONST_VTBL struct ISpeechPhraseElementsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseElements_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseElements_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseElements_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseElements_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseElements_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseElements_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseElements_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseElements_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define ISpeechPhraseElements_Item(This,Index,Element)	\
    ( (This)->lpVtbl -> Item(This,Index,Element) ) 

#define ISpeechPhraseElements_get__NewEnum(This,EnumVARIANT)	\
    ( (This)->lpVtbl -> get__NewEnum(This,EnumVARIANT) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseElements_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhraseReplacement_INTERFACE_DEFINED__
#define __ISpeechPhraseReplacement_INTERFACE_DEFINED__

/* interface ISpeechPhraseReplacement */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseReplacement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2890A410-53A7-4fb5-94EC-06D4998E3D02")
    ISpeechPhraseReplacement : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayAttributes( 
            /* [retval][out] */ __RPC__out SpeechDisplayAttributes *DisplayAttributes) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Text) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_FirstElement( 
            /* [retval][out] */ __RPC__out long *FirstElement) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NumberOfElements( 
            /* [retval][out] */ __RPC__out long *NumberOfElements) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhraseReplacementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseReplacement * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseReplacement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseReplacement * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseReplacement * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseReplacement * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseReplacement * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseReplacement * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayAttributes )( 
            __RPC__in ISpeechPhraseReplacement * This,
            /* [retval][out] */ __RPC__out SpeechDisplayAttributes *DisplayAttributes);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            __RPC__in ISpeechPhraseReplacement * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Text);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstElement )( 
            __RPC__in ISpeechPhraseReplacement * This,
            /* [retval][out] */ __RPC__out long *FirstElement);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumberOfElements )( 
            __RPC__in ISpeechPhraseReplacement * This,
            /* [retval][out] */ __RPC__out long *NumberOfElements);
        
        END_INTERFACE
    } ISpeechPhraseReplacementVtbl;

    interface ISpeechPhraseReplacement
    {
        CONST_VTBL struct ISpeechPhraseReplacementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseReplacement_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseReplacement_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseReplacement_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseReplacement_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseReplacement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseReplacement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseReplacement_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseReplacement_get_DisplayAttributes(This,DisplayAttributes)	\
    ( (This)->lpVtbl -> get_DisplayAttributes(This,DisplayAttributes) ) 

#define ISpeechPhraseReplacement_get_Text(This,Text)	\
    ( (This)->lpVtbl -> get_Text(This,Text) ) 

#define ISpeechPhraseReplacement_get_FirstElement(This,FirstElement)	\
    ( (This)->lpVtbl -> get_FirstElement(This,FirstElement) ) 

#define ISpeechPhraseReplacement_get_NumberOfElements(This,NumberOfElements)	\
    ( (This)->lpVtbl -> get_NumberOfElements(This,NumberOfElements) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseReplacement_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhraseReplacements_INTERFACE_DEFINED__
#define __ISpeechPhraseReplacements_INTERFACE_DEFINED__

/* interface ISpeechPhraseReplacements */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseReplacements;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38BC662F-2257-4525-959E-2069D2596C05")
    ISpeechPhraseReplacements : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *Count) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseReplacement **Reps) = 0;
        
        virtual /* [id][restricted][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhraseReplacementsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseReplacements * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseReplacements * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseReplacements * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseReplacements * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseReplacements * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseReplacements * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseReplacements * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in ISpeechPhraseReplacements * This,
            /* [retval][out] */ __RPC__out long *Count);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in ISpeechPhraseReplacements * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseReplacement **Reps);
        
        /* [id][restricted][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in ISpeechPhraseReplacements * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT);
        
        END_INTERFACE
    } ISpeechPhraseReplacementsVtbl;

    interface ISpeechPhraseReplacements
    {
        CONST_VTBL struct ISpeechPhraseReplacementsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseReplacements_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseReplacements_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseReplacements_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseReplacements_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseReplacements_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseReplacements_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseReplacements_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseReplacements_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define ISpeechPhraseReplacements_Item(This,Index,Reps)	\
    ( (This)->lpVtbl -> Item(This,Index,Reps) ) 

#define ISpeechPhraseReplacements_get__NewEnum(This,EnumVARIANT)	\
    ( (This)->lpVtbl -> get__NewEnum(This,EnumVARIANT) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseReplacements_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhraseProperty_INTERFACE_DEFINED__
#define __ISpeechPhraseProperty_INTERFACE_DEFINED__

/* interface ISpeechPhraseProperty */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CE563D48-961E-4732-A2E1-378A42B430BE")
    ISpeechPhraseProperty : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ __RPC__out long *Id) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ __RPC__out VARIANT *Value) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_FirstElement( 
            /* [retval][out] */ __RPC__out long *FirstElement) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NumberOfElements( 
            /* [retval][out] */ __RPC__out long *NumberOfElements) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EngineConfidence( 
            /* [retval][out] */ __RPC__out float *Confidence) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Confidence( 
            /* [retval][out] */ __RPC__out SpeechEngineConfidence *Confidence) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseProperty **ParentProperty) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Children( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseProperties **Children) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhrasePropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseProperty * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseProperty * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [retval][out] */ __RPC__out long *Id);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [retval][out] */ __RPC__out VARIANT *Value);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstElement )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [retval][out] */ __RPC__out long *FirstElement);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumberOfElements )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [retval][out] */ __RPC__out long *NumberOfElements);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EngineConfidence )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [retval][out] */ __RPC__out float *Confidence);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Confidence )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [retval][out] */ __RPC__out SpeechEngineConfidence *Confidence);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseProperty **ParentProperty);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Children )( 
            __RPC__in ISpeechPhraseProperty * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseProperties **Children);
        
        END_INTERFACE
    } ISpeechPhrasePropertyVtbl;

    interface ISpeechPhraseProperty
    {
        CONST_VTBL struct ISpeechPhrasePropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseProperty_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseProperty_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseProperty_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseProperty_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseProperty_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseProperty_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseProperty_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseProperty_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define ISpeechPhraseProperty_get_Id(This,Id)	\
    ( (This)->lpVtbl -> get_Id(This,Id) ) 

#define ISpeechPhraseProperty_get_Value(This,Value)	\
    ( (This)->lpVtbl -> get_Value(This,Value) ) 

#define ISpeechPhraseProperty_get_FirstElement(This,FirstElement)	\
    ( (This)->lpVtbl -> get_FirstElement(This,FirstElement) ) 

#define ISpeechPhraseProperty_get_NumberOfElements(This,NumberOfElements)	\
    ( (This)->lpVtbl -> get_NumberOfElements(This,NumberOfElements) ) 

#define ISpeechPhraseProperty_get_EngineConfidence(This,Confidence)	\
    ( (This)->lpVtbl -> get_EngineConfidence(This,Confidence) ) 

#define ISpeechPhraseProperty_get_Confidence(This,Confidence)	\
    ( (This)->lpVtbl -> get_Confidence(This,Confidence) ) 

#define ISpeechPhraseProperty_get_Parent(This,ParentProperty)	\
    ( (This)->lpVtbl -> get_Parent(This,ParentProperty) ) 

#define ISpeechPhraseProperty_get_Children(This,Children)	\
    ( (This)->lpVtbl -> get_Children(This,Children) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseProperty_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhraseProperties_INTERFACE_DEFINED__
#define __ISpeechPhraseProperties_INTERFACE_DEFINED__

/* interface ISpeechPhraseProperties */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08166B47-102E-4b23-A599-BDB98DBFD1F4")
    ISpeechPhraseProperties : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *Count) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseProperty **Property) = 0;
        
        virtual /* [id][restricted][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhrasePropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseProperties * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseProperties * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseProperties * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseProperties * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseProperties * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in ISpeechPhraseProperties * This,
            /* [retval][out] */ __RPC__out long *Count);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in ISpeechPhraseProperties * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseProperty **Property);
        
        /* [id][restricted][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in ISpeechPhraseProperties * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT);
        
        END_INTERFACE
    } ISpeechPhrasePropertiesVtbl;

    interface ISpeechPhraseProperties
    {
        CONST_VTBL struct ISpeechPhrasePropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseProperties_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseProperties_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define ISpeechPhraseProperties_Item(This,Index,Property)	\
    ( (This)->lpVtbl -> Item(This,Index,Property) ) 

#define ISpeechPhraseProperties_get__NewEnum(This,EnumVARIANT)	\
    ( (This)->lpVtbl -> get__NewEnum(This,EnumVARIANT) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseProperties_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhraseRule_INTERFACE_DEFINED__
#define __ISpeechPhraseRule_INTERFACE_DEFINED__

/* interface ISpeechPhraseRule */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseRule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A7BFE112-A4A0-48d9-B602-C313843F6964")
    ISpeechPhraseRule : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ __RPC__out long *Id) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_FirstElement( 
            /* [retval][out] */ __RPC__out long *FirstElement) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_NumberOfElements( 
            /* [retval][out] */ __RPC__out long *NumberOfElements) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseRule **Parent) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Children( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseRules **Children) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Confidence( 
            /* [retval][out] */ __RPC__out SpeechEngineConfidence *ActualConfidence) = 0;
        
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EngineConfidence( 
            /* [retval][out] */ __RPC__out float *EngineConfidence) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhraseRuleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseRule * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseRule * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseRule * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [retval][out] */ __RPC__out long *Id);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstElement )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [retval][out] */ __RPC__out long *FirstElement);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumberOfElements )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [retval][out] */ __RPC__out long *NumberOfElements);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseRule **Parent);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Children )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseRules **Children);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Confidence )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [retval][out] */ __RPC__out SpeechEngineConfidence *ActualConfidence);
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EngineConfidence )( 
            __RPC__in ISpeechPhraseRule * This,
            /* [retval][out] */ __RPC__out float *EngineConfidence);
        
        END_INTERFACE
    } ISpeechPhraseRuleVtbl;

    interface ISpeechPhraseRule
    {
        CONST_VTBL struct ISpeechPhraseRuleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseRule_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseRule_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseRule_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseRule_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseRule_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseRule_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseRule_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseRule_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define ISpeechPhraseRule_get_Id(This,Id)	\
    ( (This)->lpVtbl -> get_Id(This,Id) ) 

#define ISpeechPhraseRule_get_FirstElement(This,FirstElement)	\
    ( (This)->lpVtbl -> get_FirstElement(This,FirstElement) ) 

#define ISpeechPhraseRule_get_NumberOfElements(This,NumberOfElements)	\
    ( (This)->lpVtbl -> get_NumberOfElements(This,NumberOfElements) ) 

#define ISpeechPhraseRule_get_Parent(This,Parent)	\
    ( (This)->lpVtbl -> get_Parent(This,Parent) ) 

#define ISpeechPhraseRule_get_Children(This,Children)	\
    ( (This)->lpVtbl -> get_Children(This,Children) ) 

#define ISpeechPhraseRule_get_Confidence(This,ActualConfidence)	\
    ( (This)->lpVtbl -> get_Confidence(This,ActualConfidence) ) 

#define ISpeechPhraseRule_get_EngineConfidence(This,EngineConfidence)	\
    ( (This)->lpVtbl -> get_EngineConfidence(This,EngineConfidence) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseRule_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhraseRules_INTERFACE_DEFINED__
#define __ISpeechPhraseRules_INTERFACE_DEFINED__

/* interface ISpeechPhraseRules */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseRules;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9047D593-01DD-4b72-81A3-E4A0CA69F407")
    ISpeechPhraseRules : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *Count) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseRule **Rule) = 0;
        
        virtual /* [id][restricted][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhraseRulesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseRules * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseRules * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseRules * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseRules * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseRules * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseRules * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseRules * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in ISpeechPhraseRules * This,
            /* [retval][out] */ __RPC__out long *Count);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in ISpeechPhraseRules * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseRule **Rule);
        
        /* [id][restricted][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in ISpeechPhraseRules * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT);
        
        END_INTERFACE
    } ISpeechPhraseRulesVtbl;

    interface ISpeechPhraseRules
    {
        CONST_VTBL struct ISpeechPhraseRulesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseRules_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseRules_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseRules_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseRules_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseRules_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseRules_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseRules_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseRules_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define ISpeechPhraseRules_Item(This,Index,Rule)	\
    ( (This)->lpVtbl -> Item(This,Index,Rule) ) 

#define ISpeechPhraseRules_get__NewEnum(This,EnumVARIANT)	\
    ( (This)->lpVtbl -> get__NewEnum(This,EnumVARIANT) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseRules_INTERFACE_DEFINED__ */


#ifndef __ISpeechLexicon_INTERFACE_DEFINED__
#define __ISpeechLexicon_INTERFACE_DEFINED__

/* interface ISpeechLexicon */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechLexicon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3DA7627A-C7AE-4b23-8708-638C50362C25")
    ISpeechLexicon : public IDispatch
    {
    public:
        virtual /* [hidden][id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_GenerationId( 
            /* [retval][out] */ __RPC__out long *GenerationId) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetWords( 
            /* [defaultvalue][in] */ SpeechLexiconType Flags,
            /* [defaultvalue][out] */ __RPC__out long *GenerationID,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconWords **Words) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE AddPronunciation( 
            /* [in] */ __RPC__in BSTR bstrWord,
            /* [in] */ SpeechLanguageId LangId,
            /* [defaultvalue][in] */ SpeechPartOfSpeech PartOfSpeech = SPSUnknown,
            /* [defaultvalue][in] */ __RPC__in BSTR bstrPronunciation = (BSTR)L"") = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE AddPronunciationByPhoneIds( 
            /* [in] */ __RPC__in BSTR bstrWord,
            /* [in] */ SpeechLanguageId LangId,
            /* [defaultvalue][in] */ SpeechPartOfSpeech PartOfSpeech = SPSUnknown,
            /* [defaultvalue][in] */ __RPC__in VARIANT *PhoneIds = 0) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE RemovePronunciation( 
            /* [in] */ __RPC__in BSTR bstrWord,
            /* [in] */ SpeechLanguageId LangId,
            /* [defaultvalue][in] */ SpeechPartOfSpeech PartOfSpeech = SPSUnknown,
            /* [defaultvalue][in] */ __RPC__in BSTR bstrPronunciation = (BSTR)L"") = 0;
        
        virtual /* [id][hidden][helpstring] */ HRESULT STDMETHODCALLTYPE RemovePronunciationByPhoneIds( 
            /* [in] */ __RPC__in BSTR bstrWord,
            /* [in] */ SpeechLanguageId LangId,
            /* [defaultvalue][in] */ SpeechPartOfSpeech PartOfSpeech = SPSUnknown,
            /* [defaultvalue][in] */ __RPC__in VARIANT *PhoneIds = 0) = 0;
        
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE GetPronunciations( 
            /* [in] */ __RPC__in BSTR bstrWord,
            /* [defaultvalue][in] */ SpeechLanguageId LangId,
            /* [defaultvalue][in] */ SpeechLexiconType TypeFlags,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconPronunciations **ppPronunciations) = 0;
        
        virtual /* [hidden][id][helpstring] */ HRESULT STDMETHODCALLTYPE GetGenerationChange( 
            /* [out][in] */ __RPC__inout long *GenerationID,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconWords **ppWords) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechLexiconVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechLexicon * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechLexicon * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechLexicon * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechLexicon * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechLexicon * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechLexicon * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechLexicon * This,
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
        
        /* [hidden][id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GenerationId )( 
            __RPC__in ISpeechLexicon * This,
            /* [retval][out] */ __RPC__out long *GenerationId);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetWords )( 
            __RPC__in ISpeechLexicon * This,
            /* [defaultvalue][in] */ SpeechLexiconType Flags,
            /* [defaultvalue][out] */ __RPC__out long *GenerationID,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconWords **Words);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddPronunciation )( 
            __RPC__in ISpeechLexicon * This,
            /* [in] */ __RPC__in BSTR bstrWord,
            /* [in] */ SpeechLanguageId LangId,
            /* [defaultvalue][in] */ SpeechPartOfSpeech PartOfSpeech,
            /* [defaultvalue][in] */ __RPC__in BSTR bstrPronunciation);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddPronunciationByPhoneIds )( 
            __RPC__in ISpeechLexicon * This,
            /* [in] */ __RPC__in BSTR bstrWord,
            /* [in] */ SpeechLanguageId LangId,
            /* [defaultvalue][in] */ SpeechPartOfSpeech PartOfSpeech,
            /* [defaultvalue][in] */ __RPC__in VARIANT *PhoneIds);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemovePronunciation )( 
            __RPC__in ISpeechLexicon * This,
            /* [in] */ __RPC__in BSTR bstrWord,
            /* [in] */ SpeechLanguageId LangId,
            /* [defaultvalue][in] */ SpeechPartOfSpeech PartOfSpeech,
            /* [defaultvalue][in] */ __RPC__in BSTR bstrPronunciation);
        
        /* [id][hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemovePronunciationByPhoneIds )( 
            __RPC__in ISpeechLexicon * This,
            /* [in] */ __RPC__in BSTR bstrWord,
            /* [in] */ SpeechLanguageId LangId,
            /* [defaultvalue][in] */ SpeechPartOfSpeech PartOfSpeech,
            /* [defaultvalue][in] */ __RPC__in VARIANT *PhoneIds);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPronunciations )( 
            __RPC__in ISpeechLexicon * This,
            /* [in] */ __RPC__in BSTR bstrWord,
            /* [defaultvalue][in] */ SpeechLanguageId LangId,
            /* [defaultvalue][in] */ SpeechLexiconType TypeFlags,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconPronunciations **ppPronunciations);
        
        /* [hidden][id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetGenerationChange )( 
            __RPC__in ISpeechLexicon * This,
            /* [out][in] */ __RPC__inout long *GenerationID,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconWords **ppWords);
        
        END_INTERFACE
    } ISpeechLexiconVtbl;

    interface ISpeechLexicon
    {
        CONST_VTBL struct ISpeechLexiconVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechLexicon_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechLexicon_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechLexicon_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechLexicon_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechLexicon_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechLexicon_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechLexicon_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechLexicon_get_GenerationId(This,GenerationId)	\
    ( (This)->lpVtbl -> get_GenerationId(This,GenerationId) ) 

#define ISpeechLexicon_GetWords(This,Flags,GenerationID,Words)	\
    ( (This)->lpVtbl -> GetWords(This,Flags,GenerationID,Words) ) 

#define ISpeechLexicon_AddPronunciation(This,bstrWord,LangId,PartOfSpeech,bstrPronunciation)	\
    ( (This)->lpVtbl -> AddPronunciation(This,bstrWord,LangId,PartOfSpeech,bstrPronunciation) ) 

#define ISpeechLexicon_AddPronunciationByPhoneIds(This,bstrWord,LangId,PartOfSpeech,PhoneIds)	\
    ( (This)->lpVtbl -> AddPronunciationByPhoneIds(This,bstrWord,LangId,PartOfSpeech,PhoneIds) ) 

#define ISpeechLexicon_RemovePronunciation(This,bstrWord,LangId,PartOfSpeech,bstrPronunciation)	\
    ( (This)->lpVtbl -> RemovePronunciation(This,bstrWord,LangId,PartOfSpeech,bstrPronunciation) ) 

#define ISpeechLexicon_RemovePronunciationByPhoneIds(This,bstrWord,LangId,PartOfSpeech,PhoneIds)	\
    ( (This)->lpVtbl -> RemovePronunciationByPhoneIds(This,bstrWord,LangId,PartOfSpeech,PhoneIds) ) 

#define ISpeechLexicon_GetPronunciations(This,bstrWord,LangId,TypeFlags,ppPronunciations)	\
    ( (This)->lpVtbl -> GetPronunciations(This,bstrWord,LangId,TypeFlags,ppPronunciations) ) 

#define ISpeechLexicon_GetGenerationChange(This,GenerationID,ppWords)	\
    ( (This)->lpVtbl -> GetGenerationChange(This,GenerationID,ppWords) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechLexicon_INTERFACE_DEFINED__ */


#ifndef __ISpeechLexiconWords_INTERFACE_DEFINED__
#define __ISpeechLexiconWords_INTERFACE_DEFINED__

/* interface ISpeechLexiconWords */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechLexiconWords;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8D199862-415E-47d5-AC4F-FAA608B424E6")
    ISpeechLexiconWords : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *Count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconWord **Word) = 0;
        
        virtual /* [restricted][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechLexiconWordsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechLexiconWords * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechLexiconWords * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechLexiconWords * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechLexiconWords * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechLexiconWords * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechLexiconWords * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechLexiconWords * This,
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
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in ISpeechLexiconWords * This,
            /* [retval][out] */ __RPC__out long *Count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in ISpeechLexiconWords * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconWord **Word);
        
        /* [restricted][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in ISpeechLexiconWords * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT);
        
        END_INTERFACE
    } ISpeechLexiconWordsVtbl;

    interface ISpeechLexiconWords
    {
        CONST_VTBL struct ISpeechLexiconWordsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechLexiconWords_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechLexiconWords_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechLexiconWords_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechLexiconWords_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechLexiconWords_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechLexiconWords_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechLexiconWords_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechLexiconWords_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define ISpeechLexiconWords_Item(This,Index,Word)	\
    ( (This)->lpVtbl -> Item(This,Index,Word) ) 

#define ISpeechLexiconWords_get__NewEnum(This,EnumVARIANT)	\
    ( (This)->lpVtbl -> get__NewEnum(This,EnumVARIANT) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechLexiconWords_INTERFACE_DEFINED__ */


#ifndef __ISpeechLexiconWord_INTERFACE_DEFINED__
#define __ISpeechLexiconWord_INTERFACE_DEFINED__

/* interface ISpeechLexiconWord */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechLexiconWord;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4E5B933C-C9BE-48ed-8842-1EE51BB1D4FF")
    ISpeechLexiconWord : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LangId( 
            /* [retval][out] */ __RPC__out SpeechLanguageId *LangId) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ __RPC__out SpeechWordType *WordType) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Word( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Word) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Pronunciations( 
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconPronunciations **Pronunciations) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechLexiconWordVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechLexiconWord * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechLexiconWord * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechLexiconWord * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechLexiconWord * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechLexiconWord * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechLexiconWord * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechLexiconWord * This,
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
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LangId )( 
            __RPC__in ISpeechLexiconWord * This,
            /* [retval][out] */ __RPC__out SpeechLanguageId *LangId);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in ISpeechLexiconWord * This,
            /* [retval][out] */ __RPC__out SpeechWordType *WordType);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Word )( 
            __RPC__in ISpeechLexiconWord * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Word);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Pronunciations )( 
            __RPC__in ISpeechLexiconWord * This,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconPronunciations **Pronunciations);
        
        END_INTERFACE
    } ISpeechLexiconWordVtbl;

    interface ISpeechLexiconWord
    {
        CONST_VTBL struct ISpeechLexiconWordVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechLexiconWord_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechLexiconWord_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechLexiconWord_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechLexiconWord_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechLexiconWord_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechLexiconWord_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechLexiconWord_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechLexiconWord_get_LangId(This,LangId)	\
    ( (This)->lpVtbl -> get_LangId(This,LangId) ) 

#define ISpeechLexiconWord_get_Type(This,WordType)	\
    ( (This)->lpVtbl -> get_Type(This,WordType) ) 

#define ISpeechLexiconWord_get_Word(This,Word)	\
    ( (This)->lpVtbl -> get_Word(This,Word) ) 

#define ISpeechLexiconWord_get_Pronunciations(This,Pronunciations)	\
    ( (This)->lpVtbl -> get_Pronunciations(This,Pronunciations) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechLexiconWord_INTERFACE_DEFINED__ */


#ifndef __ISpeechLexiconPronunciations_INTERFACE_DEFINED__
#define __ISpeechLexiconPronunciations_INTERFACE_DEFINED__

/* interface ISpeechLexiconPronunciations */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechLexiconPronunciations;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("72829128-5682-4704-A0D4-3E2BB6F2EAD3")
    ISpeechLexiconPronunciations : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *Count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconPronunciation **Pronunciation) = 0;
        
        virtual /* [restricted][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechLexiconPronunciationsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechLexiconPronunciations * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechLexiconPronunciations * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechLexiconPronunciations * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechLexiconPronunciations * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechLexiconPronunciations * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechLexiconPronunciations * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechLexiconPronunciations * This,
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
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            __RPC__in ISpeechLexiconPronunciations * This,
            /* [retval][out] */ __RPC__out long *Count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            __RPC__in ISpeechLexiconPronunciations * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechLexiconPronunciation **Pronunciation);
        
        /* [restricted][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            __RPC__in ISpeechLexiconPronunciations * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **EnumVARIANT);
        
        END_INTERFACE
    } ISpeechLexiconPronunciationsVtbl;

    interface ISpeechLexiconPronunciations
    {
        CONST_VTBL struct ISpeechLexiconPronunciationsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechLexiconPronunciations_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechLexiconPronunciations_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechLexiconPronunciations_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechLexiconPronunciations_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechLexiconPronunciations_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechLexiconPronunciations_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechLexiconPronunciations_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechLexiconPronunciations_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define ISpeechLexiconPronunciations_Item(This,Index,Pronunciation)	\
    ( (This)->lpVtbl -> Item(This,Index,Pronunciation) ) 

#define ISpeechLexiconPronunciations_get__NewEnum(This,EnumVARIANT)	\
    ( (This)->lpVtbl -> get__NewEnum(This,EnumVARIANT) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechLexiconPronunciations_INTERFACE_DEFINED__ */


#ifndef __ISpeechLexiconPronunciation_INTERFACE_DEFINED__
#define __ISpeechLexiconPronunciation_INTERFACE_DEFINED__

/* interface ISpeechLexiconPronunciation */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechLexiconPronunciation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95252C5D-9E43-4f4a-9899-48EE73352F9F")
    ISpeechLexiconPronunciation : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ __RPC__out SpeechLexiconType *LexiconType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LangId( 
            /* [retval][out] */ __RPC__out SpeechLanguageId *LangId) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PartOfSpeech( 
            /* [retval][out] */ __RPC__out SpeechPartOfSpeech *PartOfSpeech) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PhoneIds( 
            /* [retval][out] */ __RPC__out VARIANT *PhoneIds) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Symbolic( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Symbolic) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechLexiconPronunciationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechLexiconPronunciation * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechLexiconPronunciation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechLexiconPronunciation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechLexiconPronunciation * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechLexiconPronunciation * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechLexiconPronunciation * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechLexiconPronunciation * This,
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
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in ISpeechLexiconPronunciation * This,
            /* [retval][out] */ __RPC__out SpeechLexiconType *LexiconType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LangId )( 
            __RPC__in ISpeechLexiconPronunciation * This,
            /* [retval][out] */ __RPC__out SpeechLanguageId *LangId);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PartOfSpeech )( 
            __RPC__in ISpeechLexiconPronunciation * This,
            /* [retval][out] */ __RPC__out SpeechPartOfSpeech *PartOfSpeech);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PhoneIds )( 
            __RPC__in ISpeechLexiconPronunciation * This,
            /* [retval][out] */ __RPC__out VARIANT *PhoneIds);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Symbolic )( 
            __RPC__in ISpeechLexiconPronunciation * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Symbolic);
        
        END_INTERFACE
    } ISpeechLexiconPronunciationVtbl;

    interface ISpeechLexiconPronunciation
    {
        CONST_VTBL struct ISpeechLexiconPronunciationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechLexiconPronunciation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechLexiconPronunciation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechLexiconPronunciation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechLexiconPronunciation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechLexiconPronunciation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechLexiconPronunciation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechLexiconPronunciation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechLexiconPronunciation_get_Type(This,LexiconType)	\
    ( (This)->lpVtbl -> get_Type(This,LexiconType) ) 

#define ISpeechLexiconPronunciation_get_LangId(This,LangId)	\
    ( (This)->lpVtbl -> get_LangId(This,LangId) ) 

#define ISpeechLexiconPronunciation_get_PartOfSpeech(This,PartOfSpeech)	\
    ( (This)->lpVtbl -> get_PartOfSpeech(This,PartOfSpeech) ) 

#define ISpeechLexiconPronunciation_get_PhoneIds(This,PhoneIds)	\
    ( (This)->lpVtbl -> get_PhoneIds(This,PhoneIds) ) 

#define ISpeechLexiconPronunciation_get_Symbolic(This,Symbolic)	\
    ( (This)->lpVtbl -> get_Symbolic(This,Symbolic) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechLexiconPronunciation_INTERFACE_DEFINED__ */



#ifndef __SpeechStringConstants_MODULE_DEFINED__
#define __SpeechStringConstants_MODULE_DEFINED__


/* module SpeechStringConstants */
/* [uuid] */ 

const BSTR SpeechRegistryUserRoot	=	L"HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech";

const BSTR SpeechRegistryLocalMachineRoot	=	L"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech";

const BSTR SpeechCategoryAudioOut	=	L"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioOutput";

const BSTR SpeechCategoryAudioIn	=	L"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioInput";

const BSTR SpeechCategoryVoices	=	L"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices";

const BSTR SpeechCategoryRecognizers	=	L"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Recognizers";

const BSTR SpeechCategoryAppLexicons	=	L"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AppLexicons";

const BSTR SpeechCategoryPhoneConverters	=	L"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\PhoneConverters";

const BSTR SpeechCategoryRecoProfiles	=	L"HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\RecoProfiles";

const BSTR SpeechTokenIdUserLexicon	=	L"HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\CurrentUserLexicon";

const BSTR SpeechTokenValueCLSID	=	L"CLSID";

const BSTR SpeechTokenKeyFiles	=	L"Files";

const BSTR SpeechTokenKeyUI	=	L"UI";

const BSTR SpeechTokenKeyAttributes	=	L"Attributes";

const BSTR SpeechVoiceCategoryTTSRate	=	L"DefaultTTSRate";

const BSTR SpeechPropertyResourceUsage	=	L"ResourceUsage";

const BSTR SpeechPropertyHighConfidenceThreshold	=	L"HighConfidenceThreshold";

const BSTR SpeechPropertyNormalConfidenceThreshold	=	L"NormalConfidenceThreshold";

const BSTR SpeechPropertyLowConfidenceThreshold	=	L"LowConfidenceThreshold";

const BSTR SpeechPropertyResponseSpeed	=	L"ResponseSpeed";

const BSTR SpeechPropertyComplexResponseSpeed	=	L"ComplexResponseSpeed";

const BSTR SpeechPropertyAdaptationOn	=	L"AdaptationOn";

const BSTR SpeechDictationTopicSpelling	=	L"Spelling";

const BSTR SpeechGrammarTagWildcard	=	L"...";

const BSTR SpeechGrammarTagDictation	=	L"*";

const BSTR SpeechGrammarTagUnlimitedDictation	=	L"*+";

const BSTR SpeechEngineProperties	=	L"EngineProperties";

const BSTR SpeechAddRemoveWord	=	L"AddRemoveWord";

const BSTR SpeechUserTraining	=	L"UserTraining";

const BSTR SpeechMicTraining	=	L"MicTraining";

const BSTR SpeechRecoProfileProperties	=	L"RecoProfileProperties";

const BSTR SpeechAudioProperties	=	L"AudioProperties";

const BSTR SpeechAudioVolume	=	L"AudioVolume";

const BSTR SpeechVoiceSkipTypeSentence	=	L"Sentence";

const BSTR SpeechAudioFormatGUIDWave	=	L"{C31ADBAE-527F-4ff5-A230-F62BB61FF70C}";

const BSTR SpeechAudioFormatGUIDText	=	L"{7CEEF9F9-3D13-11d2-9EE7-00C04F797396}";

#endif /* __SpeechStringConstants_MODULE_DEFINED__ */


#ifndef __SpeechConstants_MODULE_DEFINED__
#define __SpeechConstants_MODULE_DEFINED__


/* module SpeechConstants */
/* [uuid] */ 

const float Speech_Default_Weight	=	DEFAULT_WEIGHT;

const LONG Speech_Max_Word_Length	=	SP_MAX_WORD_LENGTH;

const LONG Speech_Max_Pron_Length	=	SP_MAX_PRON_LENGTH;

const LONG Speech_StreamPos_Asap	=	SP_STREAMPOS_ASAP;

const LONG Speech_StreamPos_RealTime	=	SP_STREAMPOS_REALTIME;

const LONG SpeechAllElements	=	SPPR_ALL_ELEMENTS;

#endif /* __SpeechConstants_MODULE_DEFINED__ */

#ifndef __ISpeechPhraseInfoBuilder_INTERFACE_DEFINED__
#define __ISpeechPhraseInfoBuilder_INTERFACE_DEFINED__

/* interface ISpeechPhraseInfoBuilder */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhraseInfoBuilder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3B151836-DF3A-4E0A-846C-D2ADC9334333")
    ISpeechPhraseInfoBuilder : public IDispatch
    {
    public:
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE RestorePhraseFromMemory( 
            /* [in] */ __RPC__in VARIANT *PhraseInMemory,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseInfo **PhraseInfo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhraseInfoBuilderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhraseInfoBuilder * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhraseInfoBuilder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhraseInfoBuilder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhraseInfoBuilder * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhraseInfoBuilder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhraseInfoBuilder * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhraseInfoBuilder * This,
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
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *RestorePhraseFromMemory )( 
            __RPC__in ISpeechPhraseInfoBuilder * This,
            /* [in] */ __RPC__in VARIANT *PhraseInMemory,
            /* [retval][out] */ __RPC__deref_out_opt ISpeechPhraseInfo **PhraseInfo);
        
        END_INTERFACE
    } ISpeechPhraseInfoBuilderVtbl;

    interface ISpeechPhraseInfoBuilder
    {
        CONST_VTBL struct ISpeechPhraseInfoBuilderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhraseInfoBuilder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhraseInfoBuilder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhraseInfoBuilder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhraseInfoBuilder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhraseInfoBuilder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhraseInfoBuilder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhraseInfoBuilder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhraseInfoBuilder_RestorePhraseFromMemory(This,PhraseInMemory,PhraseInfo)	\
    ( (This)->lpVtbl -> RestorePhraseFromMemory(This,PhraseInMemory,PhraseInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhraseInfoBuilder_INTERFACE_DEFINED__ */


#ifndef __ISpeechPhoneConverter_INTERFACE_DEFINED__
#define __ISpeechPhoneConverter_INTERFACE_DEFINED__

/* interface ISpeechPhoneConverter */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISpeechPhoneConverter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C3E4F353-433F-43d6-89A1-6A62A7054C3D")
    ISpeechPhoneConverter : public IDispatch
    {
    public:
        virtual /* [id][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LanguageId( 
            /* [retval][out] */ __RPC__out SpeechLanguageId *LanguageId) = 0;
        
        virtual /* [id][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_LanguageId( 
            /* [in] */ SpeechLanguageId LanguageId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PhoneToId( 
            /* [in] */ __RPC__in const BSTR Phonemes,
            /* [retval][out] */ __RPC__out VARIANT *IdArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IdToPhone( 
            /* [in] */ const VARIANT IdArray,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Phonemes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpeechPhoneConverterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in ISpeechPhoneConverter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in ISpeechPhoneConverter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in ISpeechPhoneConverter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in ISpeechPhoneConverter * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in ISpeechPhoneConverter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in ISpeechPhoneConverter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISpeechPhoneConverter * This,
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
        
        /* [id][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LanguageId )( 
            __RPC__in ISpeechPhoneConverter * This,
            /* [retval][out] */ __RPC__out SpeechLanguageId *LanguageId);
        
        /* [id][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LanguageId )( 
            __RPC__in ISpeechPhoneConverter * This,
            /* [in] */ SpeechLanguageId LanguageId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PhoneToId )( 
            __RPC__in ISpeechPhoneConverter * This,
            /* [in] */ __RPC__in const BSTR Phonemes,
            /* [retval][out] */ __RPC__out VARIANT *IdArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IdToPhone )( 
            __RPC__in ISpeechPhoneConverter * This,
            /* [in] */ const VARIANT IdArray,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Phonemes);
        
        END_INTERFACE
    } ISpeechPhoneConverterVtbl;

    interface ISpeechPhoneConverter
    {
        CONST_VTBL struct ISpeechPhoneConverterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpeechPhoneConverter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpeechPhoneConverter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpeechPhoneConverter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpeechPhoneConverter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISpeechPhoneConverter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISpeechPhoneConverter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISpeechPhoneConverter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISpeechPhoneConverter_get_LanguageId(This,LanguageId)	\
    ( (This)->lpVtbl -> get_LanguageId(This,LanguageId) ) 

#define ISpeechPhoneConverter_put_LanguageId(This,LanguageId)	\
    ( (This)->lpVtbl -> put_LanguageId(This,LanguageId) ) 

#define ISpeechPhoneConverter_PhoneToId(This,Phonemes,IdArray)	\
    ( (This)->lpVtbl -> PhoneToId(This,Phonemes,IdArray) ) 

#define ISpeechPhoneConverter_IdToPhone(This,IdArray,Phonemes)	\
    ( (This)->lpVtbl -> IdToPhone(This,IdArray,Phonemes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpeechPhoneConverter_INTERFACE_DEFINED__ */


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

EXTERN_C const CLSID CLSID_SpPhoneConverter;

#ifdef __cplusplus

class DECLSPEC_UUID("9185F743-1143-4C28-86B5-BFF14F20E5C8")
SpPhoneConverter;
#endif

EXTERN_C const CLSID CLSID_SpNullPhoneConverter;

#ifdef __cplusplus

class DECLSPEC_UUID("455F24E9-7396-4A16-9715-7C0FDBE3EFE3")
SpNullPhoneConverter;
#endif

EXTERN_C const CLSID CLSID_SpTextSelectionInformation;

#ifdef __cplusplus

class DECLSPEC_UUID("0F92030A-CBFD-4AB8-A164-FF5985547FF6")
SpTextSelectionInformation;
#endif

EXTERN_C const CLSID CLSID_SpPhraseInfoBuilder;

#ifdef __cplusplus

class DECLSPEC_UUID("C23FC28D-C55F-4720-8B32-91F73C2BD5D1")
SpPhraseInfoBuilder;
#endif

EXTERN_C const CLSID CLSID_SpAudioFormat;

#ifdef __cplusplus

class DECLSPEC_UUID("9EF96870-E160-4792-820D-48CF0649E4EC")
SpAudioFormat;
#endif

EXTERN_C const CLSID CLSID_SpWaveFormatEx;

#ifdef __cplusplus

class DECLSPEC_UUID("C79A574C-63BE-44b9-801F-283F87F898BE")
SpWaveFormatEx;
#endif

EXTERN_C const CLSID CLSID_SpInProcRecoContext;

#ifdef __cplusplus

class DECLSPEC_UUID("73AD6842-ACE0-45E8-A4DD-8795881A2C2A")
SpInProcRecoContext;
#endif

EXTERN_C const CLSID CLSID_SpCustomStream;

#ifdef __cplusplus

class DECLSPEC_UUID("8DBEF13F-1948-4aa8-8CF0-048EEBED95D8")
SpCustomStream;
#endif

EXTERN_C const CLSID CLSID_SpFileStream;

#ifdef __cplusplus

class DECLSPEC_UUID("947812B3-2AE1-4644-BA86-9E90DED7EC91")
SpFileStream;
#endif

EXTERN_C const CLSID CLSID_SpMemoryStream;

#ifdef __cplusplus

class DECLSPEC_UUID("5FB7EF7D-DFF4-468a-B6B7-2FCBD188F994")
SpMemoryStream;
#endif
#endif /* __SpeechLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_sapi51_0000_0032 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0032_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sapi51_0000_0032_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



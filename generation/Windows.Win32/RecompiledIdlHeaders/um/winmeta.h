#pragma once
#define WINEVENT_CHANNEL_CLASSIC_TRACE 0x0
#define WINEVENT_CHANNEL_GLOBAL_SYSTEM 0x8
#define WINEVENT_CHANNEL_GLOBAL_APPLICATION 0x9
#define WINEVENT_CHANNEL_GLOBAL_SECURITY 0xa
#define WINEVENT_CHANNEL_TRACELOGGING 0xb
#define WINEVENT_CHANNEL_PROVIDERMETADATA 0xc
#define WINEVENT_LEVEL_LOG_ALWAYS 0x0
#define WINEVENT_LEVEL_CRITICAL 0x1
#define WINEVENT_LEVEL_ERROR 0x2
#define WINEVENT_LEVEL_WARNING 0x3
#define WINEVENT_LEVEL_INFO 0x4
#define WINEVENT_LEVEL_VERBOSE 0x5
#define WINEVENT_LEVEL_RESERVED_6 0x6
#define WINEVENT_LEVEL_RESERVED_7 0x7
#define WINEVENT_LEVEL_RESERVED_8 0x8
#define WINEVENT_LEVEL_RESERVED_9 0x9
#define WINEVENT_LEVEL_RESERVED_10 0xa
#define WINEVENT_LEVEL_RESERVED_11 0xb
#define WINEVENT_LEVEL_RESERVED_12 0xc
#define WINEVENT_LEVEL_RESERVED_13 0xd
#define WINEVENT_LEVEL_RESERVED_14 0xe
#define WINEVENT_LEVEL_RESERVED_15 0xf
#define WINEVENT_OPCODE_INFO 0x0
#define WINEVENT_OPCODE_START 0x1
#define WINEVENT_OPCODE_STOP 0x2
#define WINEVENT_OPCODE_DC_START 0x3
#define WINEVENT_OPCODE_DC_STOP 0x4
#define WINEVENT_OPCODE_EXTENSION 0x5
#define WINEVENT_OPCODE_REPLY 0x6
#define WINEVENT_OPCODE_RESUME 0x7
#define WINEVENT_OPCODE_SUSPEND 0x8
#define WINEVENT_OPCODE_SEND 0x9
#define WINEVENT_OPCODE_RECEIVE 0xf0
#define WINEVENT_OPCODE_RESERVED_241 0xf1
#define WINEVENT_OPCODE_RESERVED_242 0xf2
#define WINEVENT_OPCODE_RESERVED_243 0xf3
#define WINEVENT_OPCODE_RESERVED_244 0xf4
#define WINEVENT_OPCODE_RESERVED_245 0xf5
#define WINEVENT_OPCODE_RESERVED_246 0xf6
#define WINEVENT_OPCODE_RESERVED_247 0xf7
#define WINEVENT_OPCODE_RESERVED_248 0xf8
#define WINEVENT_OPCODE_RESERVED_249 0xf9
#define WINEVENT_OPCODE_RESERVED_250 0xfa
#define WINEVENT_OPCODE_RESERVED_251 0xfb
#define WINEVENT_OPCODE_RESERVED_252 0xfc
#define WINEVENT_OPCODE_RESERVED_253 0xfd
#define WINEVENT_OPCODE_RESERVED_254 0xfe
#define WINEVENT_OPCODE_RESERVED_255 0xff
#define WINEVENT_TASK_NONE 0x0
#define WINEVT_KEYWORD_ANY 0x0
#define WINEVENT_KEYWORD_RESPONSE_TIME 0x1000000000000
#define WINEVENT_KEYWORD_RESERVED_49 0x2000000000000
#define WINEVENT_KEYWORD_WDI_DIAG 0x4000000000000
#define WINEVENT_KEYWORD_SQM 0x8000000000000
#define WINEVENT_KEYWORD_AUDIT_FAILURE 0x10000000000000
#define WINEVENT_KEYWORD_AUDIT_SUCCESS 0x20000000000000
#define WINEVENT_KEYWORD_CORRELATION_HINT 0x40000000000000
#define WINEVENT_KEYWORD_EVENTLOG_CLASSIC 0x80000000000000
#define WINEVENT_KEYWORD_RESERVED_56 0x100000000000000
#define WINEVENT_KEYWORD_RESERVED_57 0x200000000000000
#define WINEVENT_KEYWORD_RESERVED_58 0x400000000000000
#define WINEVENT_KEYWORD_RESERVED_59 0x800000000000000
#define WINEVENT_KEYWORD_RESERVED_60 0x1000000000000000
#define WINEVENT_KEYWORD_RESERVED_61 0x2000000000000000
#define WINEVENT_KEYWORD_RESERVED_62 0x4000000000000000
#define WINEVENT_KEYWORD_RESERVED_63 0x8000000000000000
#define MSG_category_Devices             0x00000001L

#define MSG_category_Disk                0x00000002L

#define MSG_category_Network             0x00000007L

#define MSG_category_Printers            0x00000003L

#define MSG_category_Services            0x00000004L

#define MSG_category_Shell               0x00000005L

#define MSG_category_SystemEvent         0x00000006L

#define MSG_channel_Application          0x00000100L

#define MSG_channel_ProviderMetadata     0x90000003L

#define MSG_channel_Security             0x00000101L

#define MSG_channel_System               0x00000102L

#define MSG_channel_TraceClassic         0x90000001L

#define MSG_channel_TraceLogging         0x90000002L

#define MSG_keyword_AnyKeyword           0x10000000L

#define MSG_keyword_AuditFailure         0x10000035L

#define MSG_keyword_AuditSuccess         0x10000036L

#define MSG_keyword_Classic              0x10000038L

#define MSG_keyword_CorrelationHint      0x10000037L

#define MSG_keyword_ResponseTime         0x10000031L

#define MSG_keyword_SQM                  0x10000034L

#define MSG_keyword_WDIDiag              0x10000033L

#define MSG_level_Critical               0x50000001L

#define MSG_level_Error                  0x50000002L

#define MSG_level_Informational          0x50000004L

#define MSG_level_LogAlways              0x50000000L

#define MSG_level_Verbose                0x50000005L

#define MSG_level_Warning                0x50000003L

#define MSG_opcode_DCStart               0x30030000L

#define MSG_opcode_DCStop                0x30040000L

#define MSG_opcode_Extension             0x30050000L

#define MSG_opcode_Info                  0x30000000L

#define MSG_opcode_Receive               0x30F00000L

#define MSG_opcode_Reply                 0x30060000L

#define MSG_opcode_Resume                0x30070000L

#define MSG_opcode_Send                  0x30090000L

#define MSG_opcode_Start                 0x30010000L

#define MSG_opcode_Stop                  0x30020000L

#define MSG_opcode_Suspend               0x30080000L

#define MSG_task_None                    0x70000000L


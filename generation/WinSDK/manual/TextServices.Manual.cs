using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.UI.TextServices
{
    public static unsafe partial class Apis
    {
        public static readonly Guid GUID_PROP_TEXTOWNER = new Guid("f1e2d520-0969-11d3-8df0-00105a2799b5");
        public static readonly Guid GUID_PROP_ATTRIBUTE = new Guid("34b45670-7526-11d2-a147-00105a2799b5");
        public static readonly Guid GUID_PROP_LANGID = new Guid("3280ce20-8032-11d2-b603-00105a2799b5");
        public static readonly Guid GUID_PROP_READING = new Guid("5463f7c0-8e31-11d2-bf46-00105a2799b5");
        public static readonly Guid GUID_PROP_COMPOSING = new Guid("e12ac060-af15-11d2-afc5-00105a2799b5");
        public static readonly Guid GUID_PROP_TKB_ALTERNATES = new Guid("70b2a803-968d-462e-b93b-2164c91517f7");
        public static readonly Guid GUID_SYSTEM_FUNCTIONPROVIDER = new Guid("9a698bb0-0f21-11d3-8df1-00105a2799b5");
        public static readonly Guid GUID_APP_FUNCTIONPROVIDER = new Guid("4caef01e-12af-4b0e-9db1-a6ec5b881208");
        public static readonly Guid GUID_TFCAT_CATEGORY_OF_TIP = new Guid("534c48c1-0607-4098-a521-4fc899c73e90");
        public static readonly Guid GUID_TFCAT_TIP_KEYBOARD = new Guid("34745c63-b2f0-4784-8b67-5e12c8701a31");
        public static readonly Guid GUID_TFCAT_TIP_SPEECH = new Guid("b5a73cd1-8355-426b-a161-259808f26b14");
        public static readonly Guid GUID_TFCAT_TIP_HANDWRITING = new Guid("246ecb87-c2f2-4abe-905b-c8b38add2c43");
        public static readonly Guid GUID_TFCAT_PROP_AUDIODATA = new Guid("9b7be3a9-e8ab-4d47-a8fe-254fa423436d");
        public static readonly Guid GUID_TFCAT_PROP_INKDATA = new Guid("7c6a82ae-b0d7-4f14-a745-14f28b009d61");
        public static readonly Guid GUID_COMPARTMENT_SAPI_AUDIO = new Guid("51af2086-cc6b-457d-b5aa-8b19dc290ab4");
        public static readonly Guid GUID_COMPARTMENT_KEYBOARD_DISABLED = new Guid("71a5b253-1951-466b-9fbc-9c8808fa84f2");
        public static readonly Guid GUID_COMPARTMENT_KEYBOARD_OPENCLOSE = new Guid("58273aad-01bb-4164-95c6-755ba0b5162d");
        public static readonly Guid GUID_COMPARTMENT_HANDWRITING_OPENCLOSE = new Guid("f9ae2c6b-1866-4361-af72-7aa30948890e");
        public static readonly Guid GUID_COMPARTMENT_SPEECH_DISABLED = new Guid("56c5c607-0703-4e59-8e52-cbc84e8bbe35");
        public static readonly Guid GUID_COMPARTMENT_SPEECH_OPENCLOSE = new Guid("544d6a63-e2e8-4752-bbd1-000960bca083");
        public static readonly Guid GUID_COMPARTMENT_SPEECH_GLOBALSTATE = new Guid("2a54fe8e-0d08-460c-a75d-87035ff436c5");
        public static readonly Guid GUID_COMPARTMENT_CONVERSIONMODEBIAS = new Guid("5497f516-ee91-436e-b946-aa2c05f1ac5b");
        public static readonly Guid GUID_PROP_MODEBIAS = new Guid("372E0716-974F-40AC-A088-08CDC92EBFBC");
        public static readonly Guid GUID_COMPARTMENT_KEYBOARD_INPUTMODE = new Guid("b6592511-bcee-4122-a7c4-09f4b3fa4396");
        public static readonly Guid GUID_MODEBIAS_NONE = new Guid("00000000-0000-0000-0000-000000000000");
        public static readonly Guid GUID_MODEBIAS_URLHISTORY = new Guid("8b0e54d9-63f2-4c68-84d4-79aee7a59f09");
        public static readonly Guid GUID_MODEBIAS_FILENAME = new Guid("d7f707fe-44c6-4fca-8e76-86ab50c7931b");
        public static readonly Guid GUID_MODEBIAS_READING = new Guid("e31643a3-6466-4cbf-8d8b-0bd4d8545461");
        public static readonly Guid GUID_MODEBIAS_DATETIME = new Guid("f2bdb372-7f61-4039-92ef-1c35599f0222");
        public static readonly Guid GUID_MODEBIAS_NAME = new Guid("fddc10f0-d239-49bf-b8fc-5410caaa427e");
        public static readonly Guid GUID_MODEBIAS_CONVERSATION = new Guid("0f4ec104-1790-443b-95f1-e10f939d6546");
        public static readonly Guid GUID_MODEBIAS_NUMERIC = new Guid("4021766c-e872-48fd-9cee-4ec5c75e16c3");
        public static readonly Guid GUID_MODEBIAS_HIRAGANA = new Guid("d73d316e-9b91-46f1-a280-31597f52c694");
        public static readonly Guid GUID_MODEBIAS_KATAKANA = new Guid("2e0eeddd-3a1a-499e-8543-3c7ee7949811");
        public static readonly Guid GUID_MODEBIAS_HANGUL = new Guid("76ef0541-23b3-4d77-a074-691801ccea17");
        public static readonly Guid GUID_MODEBIAS_CHINESE = new Guid("7add26de-4328-489b-83ae-6493750cad5c");
        public static readonly Guid GUID_MODEBIAS_HALFWIDTHKATAKANA = new Guid("005f6b63-78d4-41cc-8859-485ca821a795");
        public static readonly Guid GUID_MODEBIAS_FULLWIDTHALPHANUMERIC = new Guid("81489fb8-b36a-473d-8146-e4a2258b24ae");
        public static readonly Guid GUID_MODEBIAS_HALFWIDTHALPHANUMERIC = new Guid("6f24fc0-4479-46ed-938a-6052b1653d3b");
        public static readonly Guid GUID_MODEBIAS_FULLWIDTHHANGUL = new Guid("c01ae6c9-45b5-4fd0-9cb1-9f4cebc39fea");
        public static readonly Guid GUID_TFCAT_PROPSTYLE_CUSTOM = new Guid("4af3031-852d-40a2-bc09-8992898ce722");
        public static readonly Guid GUID_TFCAT_PROPSTYLE_STATIC = new Guid("565fb8d8-6bd4-4ca1-b223-0f2ccb8f4f96");
        public static readonly Guid GUID_TFCAT_PROPSTYLE_STATICCOMPACT = new Guid("5f9794b-4d19-40d8-8864-4e747371a66d");
        public static readonly Guid GUID_TFCAT_DISPLAYATTRIBUTEPROVIDER = new Guid("046b8c80-1647-40f7-9b21-b93b81aabc1b");
        public static readonly Guid GUID_TFCAT_DISPLAYATTRIBUTEPROPERTY = new Guid("b95f181b-ea4c-4af1-8056-7c321abbb091");
        public static readonly Guid GUID_COMPARTMENT_SPEECH_DICTATIONSTAT = new Guid("edb55cc-58f0-4592-aae1-fe51f43b95c5");
        public static readonly Guid GUID_COMPARTMENT_PERSISTMENUENABLED = new Guid("5F3783-70C8-47C8-AE5D-91A01A1F7592");
        public static readonly Guid GUID_COMPARTMENT_SPEECH_UI_STATUS = new Guid("D92016F0-9367-4FE7-9ABF-BC59DACBE0E3");
        public static readonly Guid GUID_COMPARTMENT_EMPTYCONTEXT = new Guid("d7487dbf-804e-41c5-894d-ad96fd4eea13");
        public static readonly Guid GUID_COMPARTMENT_TIPUISTATUS = new Guid("148ca3ec-0366-401c-8d75-ed978d85fbc9");
        public static readonly Guid GUID_COMPARTMENT_SPEECH_CFGMENU = new Guid("fb6c5c2d-4e83-4bb6-91a2-e019bff6762d");
        public static readonly Guid GUID_LBI_SAPILAYR_CFGMENUBUTTON = new Guid("D02F24A1-942D-422E-8D99-B4F2ADDEE999");
        public static readonly Guid GUID_TFCAT_TIPCAP_SECUREMODE = new Guid("49d2f9ce-1f5e-11d7-a6d3-00065b84435c");
        public static readonly Guid GUID_TFCAT_TIPCAP_UIELEMENTENABLED = new Guid("49d2f9cf-1f5e-11d7-a6d3-00065b84435c");
        public static readonly Guid GUID_TFCAT_TIPCAP_INPUTMODECOMPARTMENT = new Guid("ccf05dd7-4a87-11d7-a6e2-00065b84435c");
        public static readonly Guid GUID_TFCAT_TIPCAP_COMLESS = new Guid("364215d9-75bc-11d7-a6ef-00065b84435c");
        public static readonly Guid GUID_TFCAT_TIPCAP_WOW16 = new Guid("364215da-75bc-11d7-a6ef-00065b84435c");
        public static readonly Guid GUID_TFCAT_TIPCAP_IMMERSIVESUPPORT = new Guid("13a016df-560b-46cd-947a-4c3af1e0e35d");
        public static readonly Guid GUID_TFCAT_TIPCAP_IMMERSIVEONLY = new Guid("3a4259ac-640d-4ad4-89f7-1eb67e7c4ee8");
        public static readonly Guid GUID_TFCAT_TIPCAP_LOCALSERVER = new Guid("74769ee9-4a66-4f9d-90d6-bf8b7c3eb461");
        public static readonly Guid GUID_TFCAT_TIPCAP_TSF3 = new Guid("07dcb4af-98de-4548-bef7-25bd45979a1f");
        public static readonly Guid GUID_TFCAT_TIPCAP_DUALMODE = new Guid("3af314a2-d79f-4b1b-9992-15086d339b05");
        public static readonly Guid GUID_TFCAT_TIPCAP_SYSTRAYSUPPORT = new Guid("25504fb4-7bab-4bc1-9c69-cf81890f0ef5");
        public static readonly Guid GUID_COMPARTMENT_KEYBOARD_INPUTMODE_CONVERSION = new Guid("ccf05dd8-4a87-11d7-a6e2-00065b84435c");
        public static readonly Guid GUID_COMPARTMENT_KEYBOARD_INPUTMODE_SENTENCE = new Guid("ccf05dd9-4a87-11d7-a6e2-00065b84435c");
        public static readonly Guid GUID_COMPARTMENT_TRANSITORYEXTENSION = new Guid("8be347f5-c7a0-11d7-b408-00065b84435c");
        public static readonly Guid GUID_COMPARTMENT_TRANSITORYEXTENSION_DOCUMENTMANAGER = new Guid("8be347f7-c7a0-11d7-b408-00065b84435c");
        public static readonly Guid GUID_COMPARTMENT_TRANSITORYEXTENSION_PARENT = new Guid("8be347f8-c7a0-11d7-b408-00065b84435c");
        public static readonly Guid GUID_COMPARTMENT_ENABLED_PROFILES_UPDATED = new Guid("92c1fd48-a9ae-4a7c-be08-4329e4723817");
        public static readonly Guid GUID_TFCAT_TRANSITORYEXTENSIONUI = new Guid("6302de22-a5cf-4b02-bfe8-4d72b2bed3c6");
        public static readonly Guid GUID_LBI_INPUTMODE = new Guid("2C77A81E-41CC-4178-A3A7-5F8A987568E6");

        public static readonly Guid CLSID_TF_ThreadMgr = new Guid("529A9E6B-6587-4F23-AB9E-9C7D683E3C50");
        public static readonly Guid CLSID_TF_LangBarMgr = new Guid("EBB08C45-6C4A-4FDC-AE53-4EB8C4C7DB8E");
        public static readonly Guid CLSID_TF_DisplayAttributeMgr = new Guid("3CE74DE4-53D3-4D74-8B83-431B3828BA53");
        public static readonly Guid CLSID_TF_CategoryMgr = new Guid("A4B544A1-438D-4B41-9325-869523E2D6C7");
        public static readonly Guid CLSID_TF_InputProcessorProfiles = new Guid("33C53A50-F456-4884-B049-85FD643ECFED");
        public static readonly Guid CLSID_TF_LangBarItemMgr = new Guid("B9931692-A2B3-4FAB-BF33-9EC6F9FB96AC");
        public static readonly Guid CLSID_TF_ClassicLangBar = new Guid("3318360c-1afc-4d09-a86b-9f9cb6dceb9c");
        public static readonly Guid CLSID_TF_TransitoryExtensionUIEntry = new Guid("ae6be008-07fb-400d-8beb-337a64f7051f");
        public static readonly Guid CLSID_TsfServices = new Guid("39aedc00-6b60-46db-8d31-3642be0e4373");

        public const ulong TF_DEFAULT_SELECTION = unchecked((ulong)-1);
        public const ulong TS_DEFAULT_SELECTION = unchecked((ulong)-1);
    }
}

using System;
using Windows.Win32.Foundation;
using Windows.Win32.Interop;
using Windows.Win32.System.PropertiesSystem; // For PROPERTYKEY
using Windows.Win32.System.SystemServices;
using static Windows.Win32.Foundation.Apis; // Various constants
using static Windows.Win32.System.Diagnostics.Debug.WIN32_ERROR;
using static Windows.Win32.System.SystemServices.Apis; // Various constants
using static Windows.Win32.Media.Multimedia.Apis; // Various constants
using static Windows.Win32.Media.Audio.CoreAudio.Apis; // Various constants
using static Windows.Win32.Graphics.DirectShow.Apis; // Various constants
using static Windows.Win32.UI.WindowsAndMessaging.Apis; // For WM_USER
using static Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS; // For FILE_* constants
using static Windows.Win32.System.Diagnostics.Debug.FACILITY_CODE; // For MAKE_HRESULT constants


namespace Windows.Win32.Media.Audio.DirectMusic
{
    public static partial class Apis
    {
        public const uint DMUS_MAX_DESCRIPTION = 128;

        public const uint DMUS_MAX_DRIVER = 128;

        public const uint DMUS_EFFECT_NONE = 0x00000000;

        public const uint DMUS_EFFECT_REVERB = 0x00000001;

        public const uint DMUS_EFFECT_CHORUS = 0x00000002;

        public const uint DMUS_EFFECT_DELAY = 0x00000004;

        public const uint DMUS_PC_INPUTCLASS = 0;

        public const uint DMUS_PC_OUTPUTCLASS = 1;

        public const uint DMUS_PC_DLS = 0x00000001;

        public const uint DMUS_PC_EXTERNAL = 0x00000002;

        public const uint DMUS_PC_SOFTWARESYNTH = 0x00000004;

        public const uint DMUS_PC_MEMORYSIZEFIXED = 0x00000008;

        public const uint DMUS_PC_GMINHARDWARE = 0x00000010;

        public const uint DMUS_PC_GSINHARDWARE = 0x00000020;

        public const uint DMUS_PC_XGINHARDWARE = 0x00000040;

        public const uint DMUS_PC_DIRECTSOUND = 0x00000080;

        public const uint DMUS_PC_SHAREABLE = 0x00000100;

        public const uint DMUS_PC_DLS2 = 0x00000200;

        public const uint DMUS_PC_AUDIOPATH = 0x00000400;

        public const uint DMUS_PC_WAVE = 0x00000800;

        public const uint DMUS_PC_SYSTEMMEMORY = 0x7FFFFFFF;

        public const uint DMUS_PORT_WINMM_DRIVER = 0;

        public const uint DMUS_PORT_USER_MODE_SYNTH = 1;

        public const uint DMUS_PORT_KERNEL_MODE = 2;

        public const uint DMUS_PORTPARAMS_VOICES = 0x00000001;

        public const uint DMUS_PORTPARAMS_CHANNELGROUPS = 0x00000002;

        public const uint DMUS_PORTPARAMS_AUDIOCHANNELS = 0x00000004;

        public const uint DMUS_PORTPARAMS_SAMPLERATE = 0x00000008;

        public const uint DMUS_PORTPARAMS_EFFECTS = 0x00000020;

        public const uint DMUS_PORTPARAMS_SHARE = 0x00000040;

        public const uint DMUS_PORTPARAMS_FEATURES = 0x00000080;

        public const uint DMUS_PORT_FEATURE_AUDIOPATH = 0x00000001;

        public const uint DMUS_PORT_FEATURE_STREAMING = 0x00000002;

        public const uint DMUS_SYNTHSTATS_VOICES = 1u<< 0;

        public const uint DMUS_SYNTHSTATS_TOTAL_CPU = 1u<< 1;

        public const uint DMUS_SYNTHSTATS_CPU_PER_VOICE = 1u<< 2;

        public const uint DMUS_SYNTHSTATS_LOST_NOTES = 1u<< 3;

        public const uint DMUS_SYNTHSTATS_PEAK_VOLUME = 1u<< 4;

        public const uint DMUS_SYNTHSTATS_FREE_MEMORY = 1u<< 5;

        public const uint DMUS_CLOCKF_GLOBAL = 0x00000001;

        public const uint DSBUSID_FIRST_SPKR_LOC = 0;

        public const uint DSBUSID_FRONT_LEFT = 0;

        public const uint DSBUSID_LEFT = 0;

        public const uint DSBUSID_FRONT_RIGHT = 1;

        public const uint DSBUSID_RIGHT = 1;

        public const uint DSBUSID_FRONT_CENTER = 2;

        public const uint DSBUSID_LOW_FREQUENCY = 3;

        public const uint DSBUSID_BACK_LEFT = 4;

        public const uint DSBUSID_BACK_RIGHT = 5;

        public const uint DSBUSID_FRONT_LEFT_OF_CENTER = 6;

        public const uint DSBUSID_FRONT_RIGHT_OF_CENTER = 7;

        public const uint DSBUSID_BACK_CENTER = 8;

        public const uint DSBUSID_SIDE_LEFT = 9;

        public const uint DSBUSID_SIDE_RIGHT = 10;

        public const uint DSBUSID_TOP_CENTER = 11;

        public const uint DSBUSID_TOP_FRONT_LEFT = 12;

        public const uint DSBUSID_TOP_FRONT_CENTER = 13;

        public const uint DSBUSID_TOP_FRONT_RIGHT = 14;

        public const uint DSBUSID_TOP_BACK_LEFT = 15;

        public const uint DSBUSID_TOP_BACK_CENTER = 16;

        public const uint DSBUSID_TOP_BACK_RIGHT = 17;

        public const uint DSBUSID_LAST_SPKR_LOC = 17;

        public const uint DSBUSID_REVERB_SEND = 64;

        public const uint DSBUSID_CHORUS_SEND = 65;

        public const uint DSBUSID_DYNAMIC_0 = 512;

        public const uint DSBUSID_NULL = 0xFFFFFFFF;

        public const uint DAUD_CRITICAL_VOICE_PRIORITY = 0xF0000000;

        public const uint DAUD_HIGH_VOICE_PRIORITY = 0xC0000000;

        public const uint DAUD_STANDARD_VOICE_PRIORITY = 0x80000000;

        public const uint DAUD_LOW_VOICE_PRIORITY = 0x40000000;

        public const uint DAUD_PERSIST_VOICE_PRIORITY = 0x10000000;

        public const uint DAUD_CHAN1_VOICE_PRIORITY_OFFSET = 0x0000000E;

        public const uint DAUD_CHAN2_VOICE_PRIORITY_OFFSET = 0x0000000D;

        public const uint DAUD_CHAN3_VOICE_PRIORITY_OFFSET = 0x0000000C;

        public const uint DAUD_CHAN4_VOICE_PRIORITY_OFFSET = 0x0000000B;

        public const uint DAUD_CHAN5_VOICE_PRIORITY_OFFSET = 0x0000000A;

        public const uint DAUD_CHAN6_VOICE_PRIORITY_OFFSET = 0x00000009;

        public const uint DAUD_CHAN7_VOICE_PRIORITY_OFFSET = 0x00000008;

        public const uint DAUD_CHAN8_VOICE_PRIORITY_OFFSET = 0x00000007;

        public const uint DAUD_CHAN9_VOICE_PRIORITY_OFFSET = 0x00000006;

        public const uint DAUD_CHAN10_VOICE_PRIORITY_OFFSET = 0x0000000F;

        public const uint DAUD_CHAN11_VOICE_PRIORITY_OFFSET = 0x00000005;

        public const uint DAUD_CHAN12_VOICE_PRIORITY_OFFSET = 0x00000004;

        public const uint DAUD_CHAN13_VOICE_PRIORITY_OFFSET = 0x00000003;

        public const uint DAUD_CHAN14_VOICE_PRIORITY_OFFSET = 0x00000002;

        public const uint DAUD_CHAN15_VOICE_PRIORITY_OFFSET = 0x00000001;

        public const uint DAUD_CHAN16_VOICE_PRIORITY_OFFSET = 0x00000000;

        public static readonly Guid CLSID_DirectMusic__scanned__ = new Guid(0x636b9f10,0x0c7d,0x11d1,0x95,0xb2,0x00,0x20,0xaf,0xdc,0x74,0x21);

        public static readonly Guid CLSID_DirectMusicCollection__scanned__ = new Guid(0x480ff4b0, 0x28b2, 0x11d1, 0xbe, 0xf7, 0x0, 0xc0, 0x4f, 0xbf, 0x8f, 0xef);

        public static readonly Guid CLSID_DirectMusicSynth__scanned__ = new Guid(0x58C2B4D0,0x46E7,0x11D1,0x89,0xAC,0x00,0xA0,0xC9,0x05,0x41,0x29);

        public static readonly Guid IID_IDirectMusic__scanned__ = new Guid(0x6536115a,0x7b2d,0x11d2,0xba,0x18,0x00,0x00,0xf8,0x75,0xac,0x12);

        public static readonly Guid IID_IDirectMusicBuffer__scanned__ = new Guid(0xd2ac2878, 0xb39b, 0x11d1, 0x87, 0x4, 0x0, 0x60, 0x8, 0x93, 0xb1, 0xbd);

        public static readonly Guid IID_IDirectMusicPort__scanned__ = new Guid(0x08f2d8c9,0x37c2,0x11d2,0xb9,0xf9,0x00,0x00,0xf8,0x75,0xac,0x12);

        public static readonly Guid IID_IDirectMusicThru__scanned__ = new Guid(0xced153e7, 0x3606, 0x11d2, 0xb9, 0xf9, 0x00, 0x00, 0xf8, 0x75, 0xac, 0x12);

        public static readonly Guid IID_IDirectMusicPortDownload__scanned__ = new Guid(0xd2ac287a, 0xb39b, 0x11d1, 0x87, 0x4, 0x0, 0x60, 0x8, 0x93, 0xb1, 0xbd);

        public static readonly Guid IID_IDirectMusicDownload__scanned__ = new Guid(0xd2ac287b, 0xb39b, 0x11d1, 0x87, 0x4, 0x0, 0x60, 0x8, 0x93, 0xb1, 0xbd);

        public static readonly Guid IID_IDirectMusicCollection__scanned__ = new Guid(0xd2ac287c, 0xb39b, 0x11d1, 0x87, 0x4, 0x0, 0x60, 0x8, 0x93, 0xb1, 0xbd);

        public static readonly Guid IID_IDirectMusicInstrument__scanned__ = new Guid(0xd2ac287d, 0xb39b, 0x11d1, 0x87, 0x4, 0x0, 0x60, 0x8, 0x93, 0xb1, 0xbd);

        public static readonly Guid IID_IDirectMusicDownloadedInstrument__scanned__ = new Guid(0xd2ac287e, 0xb39b, 0x11d1, 0x87, 0x4, 0x0, 0x60, 0x8, 0x93, 0xb1, 0xbd);

        public static readonly Guid IID_IDirectMusic2__scanned__ = new Guid(0x6fc2cae1, 0xbc78, 0x11d2, 0xaf, 0xa6, 0x0, 0xaa, 0x0, 0x24, 0xd8, 0xb6);

        public static readonly Guid IID_IDirectMusic8__scanned__ = new Guid(0x2d3629f7,0x813d,0x4939,0x85,0x08,0xf0,0x5c,0x6b,0x75,0xfd,0x97);

        public static readonly Guid GUID_DMUS_PROP_GM_Hardware__scanned__ = new Guid(0x178f2f24, 0xc364, 0x11d1, 0xa7, 0x60, 0x00, 0x00, 0xf8, 0x75, 0xac, 0x12);

        public static readonly Guid GUID_DMUS_PROP_GS_Hardware__scanned__ = new Guid(0x178f2f25, 0xc364, 0x11d1, 0xa7, 0x60, 0x00, 0x00, 0xf8, 0x75, 0xac, 0x12);

        public static readonly Guid GUID_DMUS_PROP_XG_Hardware__scanned__ = new Guid(0x178f2f26, 0xc364, 0x11d1, 0xa7, 0x60, 0x00, 0x00, 0xf8, 0x75, 0xac, 0x12);

        public static readonly Guid GUID_DMUS_PROP_XG_Capable__scanned__ = new Guid(0x6496aba1, 0x61b0, 0x11d2, 0xaf, 0xa6, 0x0, 0xaa, 0x0, 0x24, 0xd8, 0xb6);

        public static readonly Guid GUID_DMUS_PROP_GS_Capable__scanned__ = new Guid(0x6496aba2, 0x61b0, 0x11d2, 0xaf, 0xa6, 0x0, 0xaa, 0x0, 0x24, 0xd8, 0xb6);

        public static readonly Guid GUID_DMUS_PROP_DLS1__scanned__ = new Guid(0x178f2f27, 0xc364, 0x11d1, 0xa7, 0x60, 0x00, 0x00, 0xf8, 0x75, 0xac, 0x12);

        public static readonly Guid GUID_DMUS_PROP_DLS2__scanned__ = new Guid(0xf14599e5, 0x4689, 0x11d2, 0xaf, 0xa6, 0x0, 0xaa, 0x0, 0x24, 0xd8, 0xb6);

        public static readonly Guid GUID_DMUS_PROP_INSTRUMENT2__scanned__ = new Guid(0x865fd372, 0x9f67, 0x11d2, 0x87, 0x2a, 0x0, 0x60, 0x8, 0x93, 0xb1, 0xbd);

        public static readonly Guid GUID_DMUS_PROP_SynthSink_DSOUND__scanned__ = new Guid(0xaa97844, 0xc877, 0x11d1, 0x87, 0xc, 0x0, 0x60, 0x8, 0x93, 0xb1, 0xbd);

        public static readonly Guid GUID_DMUS_PROP_SynthSink_WAVE__scanned__ = new Guid(0xaa97845, 0xc877, 0x11d1, 0x87, 0xc, 0x0, 0x60, 0x8, 0x93, 0xb1, 0xbd);

        public static readonly Guid GUID_DMUS_PROP_SampleMemorySize__scanned__ = new Guid(0x178f2f28, 0xc364, 0x11d1, 0xa7, 0x60, 0x00, 0x00, 0xf8, 0x75, 0xac, 0x12);

        public static readonly Guid GUID_DMUS_PROP_SamplePlaybackRate__scanned__ = new Guid(0x2a91f713, 0xa4bf, 0x11d2, 0xbb, 0xdf, 0x0, 0x60, 0x8, 0x33, 0xdb, 0xd8);

        public static readonly Guid GUID_DMUS_PROP_WriteLatency__scanned__ = new Guid(0x268a0fa0, 0x60f2, 0x11d2, 0xaf, 0xa6, 0x0, 0xaa, 0x0, 0x24, 0xd8, 0xb6);

        public static readonly Guid GUID_DMUS_PROP_WritePeriod__scanned__ = new Guid(0x268a0fa1, 0x60f2, 0x11d2, 0xaf, 0xa6, 0x0, 0xaa, 0x0, 0x24, 0xd8, 0xb6);

        public static readonly Guid GUID_DMUS_PROP_MemorySize__scanned__ = new Guid(0x178f2f28, 0xc364, 0x11d1, 0xa7, 0x60, 0x00, 0x00, 0xf8, 0x75, 0xac, 0x12);

        public static readonly Guid GUID_DMUS_PROP_WavesReverb__scanned__ = new Guid(0x4cb5622, 0x32e5, 0x11d2, 0xaf, 0xa6, 0x0, 0xaa, 0x0, 0x24, 0xd8, 0xb6);

        public static readonly Guid GUID_DMUS_PROP_Effects__scanned__ = new Guid(0xcda8d611, 0x684a, 0x11d2, 0x87, 0x1e, 0x0, 0x60, 0x8, 0x93, 0xb1, 0xbd);

        public static readonly Guid GUID_DMUS_PROP_LegacyCaps__scanned__ = new Guid(0xcfa7cdc2, 0x00a1, 0x11d2, 0xaa, 0xd5, 0x00, 0x00, 0xf8, 0x75, 0xac, 0x12);

        public static readonly Guid GUID_DMUS_PROP_Volume__scanned__ = new Guid(0xfedfae25L, 0xe46e, 0x11d1, 0xaa, 0xce, 0x00, 0x00, 0xf8, 0x75, 0xac, 0x12);

        public const uint DMUS_VOLUME_MAX = 2000;

        public const int DMUS_VOLUME_MIN = -20000;

        public const uint DMUS_EVENT_STRUCTURED = 0x00000001;

        public const uint DIRECTSOUND_VERSION = 0x0700;

        public const uint _FACDS = 0x878;

        public static readonly Guid CLSID_DirectSound__scanned__ = new Guid(0x47d4d946, 0x62e8, 0x11cf, 0x93, 0xbc, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0);

        public static readonly Guid CLSID_DirectSound8__scanned__ = new Guid(0x3901cc3f, 0x84b5, 0x4fa4, 0xba, 0x35, 0xaa, 0x81, 0x72, 0xb8, 0xa0, 0x9b);

        public static readonly Guid CLSID_DirectSoundCapture__scanned__ = new Guid(0xb0210780, 0x89cd, 0x11d0, 0xaf, 0x8, 0x0, 0xa0, 0xc9, 0x25, 0xcd, 0x16);

        public static readonly Guid CLSID_DirectSoundCapture8__scanned__ = new Guid(0xe4bcac13, 0x7f99, 0x4908, 0x9a, 0x8e, 0x74, 0xe3, 0xbf, 0x24, 0xb6, 0xe1);

        public static readonly Guid CLSID_DirectSoundFullDuplex__scanned__ = new Guid(0xfea4300c, 0x7959, 0x4147, 0xb2, 0x6a, 0x23, 0x77, 0xb9, 0xe7, 0xa9, 0x1d);

        public static readonly Guid DSDEVID_DefaultPlayback__scanned__ = new Guid(0xdef00000, 0x9c6d, 0x47ed, 0xaa, 0xf1, 0x4d, 0xda, 0x8f, 0x2b, 0x5c, 0x03);

        public static readonly Guid DSDEVID_DefaultCapture__scanned__ = new Guid(0xdef00001, 0x9c6d, 0x47ed, 0xaa, 0xf1, 0x4d, 0xda, 0x8f, 0x2b, 0x5c, 0x03);

        public static readonly Guid DSDEVID_DefaultVoicePlayback__scanned__ = new Guid(0xdef00002, 0x9c6d, 0x47ed, 0xaa, 0xf1, 0x4d, 0xda, 0x8f, 0x2b, 0x5c, 0x03);

        public static readonly Guid DSDEVID_DefaultVoiceCapture__scanned__ = new Guid(0xdef00003, 0x9c6d, 0x47ed, 0xaa, 0xf1, 0x4d, 0xda, 0x8f, 0x2b, 0x5c, 0x03);

        public static readonly Guid IID_IDirectSound__scanned__ = new Guid(0x279AFA83, 0x4981, 0x11CE, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60);

        public static readonly Guid IID_IDirectSound8__scanned__ = new Guid(0xC50A7E93, 0xF395, 0x4834, 0x9E, 0xF6, 0x7F, 0xA9, 0x9D, 0xE5, 0x09, 0x66);

        public static readonly Guid IID_IDirectSoundBuffer__scanned__ = new Guid(0x279AFA85, 0x4981, 0x11CE, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60);

        public static readonly Guid IID_IDirectSoundBuffer8__scanned__ = new Guid(0x6825a449, 0x7524, 0x4d82, 0x92, 0x0f, 0x50, 0xe3, 0x6a, 0xb3, 0xab, 0x1e);

        public static readonly Guid GUID_All_Objects__scanned__ = new Guid(0xaa114de5, 0xc262, 0x4169, 0xa1, 0xc8, 0x23, 0xd6, 0x98, 0xcc, 0x73, 0xb5);

        public static readonly Guid IID_IDirectSound3DListener__scanned__ = new Guid(0x279AFA84, 0x4981, 0x11CE, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60);

        public static readonly Guid IID_IDirectSound3DBuffer__scanned__ = new Guid(0x279AFA86, 0x4981, 0x11CE, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60);

        public static readonly Guid IID_IDirectSoundCapture__scanned__ = new Guid(0xb0210781, 0x89cd, 0x11d0, 0xaf, 0x8, 0x0, 0xa0, 0xc9, 0x25, 0xcd, 0x16);

        public static readonly Guid IID_IDirectSoundCaptureBuffer__scanned__ = new Guid(0xb0210782, 0x89cd, 0x11d0, 0xaf, 0x8, 0x0, 0xa0, 0xc9, 0x25, 0xcd, 0x16);

        public static readonly Guid IID_IDirectSoundCaptureBuffer8__scanned__ = new Guid(0x990df4, 0xdbb, 0x4872, 0x83, 0x3e, 0x6d, 0x30, 0x3e, 0x80, 0xae, 0xb6);

        public static readonly Guid IID_IDirectSoundNotify__scanned__ = new Guid(0xb0210783, 0x89cd, 0x11d0, 0xaf, 0x8, 0x0, 0xa0, 0xc9, 0x25, 0xcd, 0x16);

        public const uint KSPROPERTY_SUPPORT_GET = 0x00000001;

        public const uint KSPROPERTY_SUPPORT_SET = 0x00000002;

        public static readonly Guid IID_IDirectSoundFXGargle__scanned__ = new Guid(0xd616f352, 0xd622, 0x11ce, 0xaa, 0xc5, 0x00, 0x20, 0xaf, 0x0b, 0x99, 0xa3);

        public const uint DSFXGARGLE_WAVE_TRIANGLE = 0;

        public const uint DSFXGARGLE_WAVE_SQUARE = 1;

        public const uint DSFXGARGLE_RATEHZ_MIN = 1;

        public const uint DSFXGARGLE_RATEHZ_MAX = 1000;

        public static readonly Guid IID_IDirectSoundFXChorus__scanned__ = new Guid(0x880842e3, 0x145f, 0x43e6, 0xa9, 0x34, 0xa7, 0x18, 0x06, 0xe5, 0x05, 0x47);

        public const uint DSFXCHORUS_WAVE_TRIANGLE = 0;

        public const uint DSFXCHORUS_WAVE_SIN = 1;

        public const float DSFXCHORUS_WETDRYMIX_MIN = 0.0f;

        public const float DSFXCHORUS_WETDRYMIX_MAX = 100.0f;

        public const float DSFXCHORUS_DEPTH_MIN = 0.0f;

        public const float DSFXCHORUS_DEPTH_MAX = 100.0f;

        public const float DSFXCHORUS_FEEDBACK_MIN = -99.0f;

        public const float DSFXCHORUS_FEEDBACK_MAX = 99.0f;

        public const float DSFXCHORUS_FREQUENCY_MIN = 0.0f;

        public const float DSFXCHORUS_FREQUENCY_MAX = 10.0f;

        public const float DSFXCHORUS_DELAY_MIN = 0.0f;

        public const float DSFXCHORUS_DELAY_MAX = 20.0f;

        public const uint DSFXCHORUS_PHASE_MIN = 0;

        public const uint DSFXCHORUS_PHASE_MAX = 4;

        public const uint DSFXCHORUS_PHASE_NEG_180 = 0;

        public const uint DSFXCHORUS_PHASE_NEG_90 = 1;

        public const uint DSFXCHORUS_PHASE_ZERO = 2;

        public const uint DSFXCHORUS_PHASE_90 = 3;

        public const uint DSFXCHORUS_PHASE_180 = 4;

        public static readonly Guid IID_IDirectSoundFXFlanger__scanned__ = new Guid(0x903e9878, 0x2c92, 0x4072, 0x9b, 0x2c, 0xea, 0x68, 0xf5, 0x39, 0x67, 0x83);

        public const uint DSFXFLANGER_WAVE_TRIANGLE = 0;

        public const uint DSFXFLANGER_WAVE_SIN = 1;

        public const float DSFXFLANGER_WETDRYMIX_MIN = 0.0f;

        public const float DSFXFLANGER_WETDRYMIX_MAX = 100.0f;

        public const float DSFXFLANGER_FREQUENCY_MIN = 0.0f;

        public const float DSFXFLANGER_FREQUENCY_MAX = 10.0f;

        public const float DSFXFLANGER_DEPTH_MIN = 0.0f;

        public const float DSFXFLANGER_DEPTH_MAX = 100.0f;

        public const uint DSFXFLANGER_PHASE_MIN = 0;

        public const uint DSFXFLANGER_PHASE_MAX = 4;

        public const float DSFXFLANGER_FEEDBACK_MIN = -99.0f;

        public const float DSFXFLANGER_FEEDBACK_MAX = 99.0f;

        public const float DSFXFLANGER_DELAY_MIN = 0.0f;

        public const float DSFXFLANGER_DELAY_MAX = 4.0f;

        public const uint DSFXFLANGER_PHASE_NEG_180 = 0;

        public const uint DSFXFLANGER_PHASE_NEG_90 = 1;

        public const uint DSFXFLANGER_PHASE_ZERO = 2;

        public const uint DSFXFLANGER_PHASE_90 = 3;

        public const uint DSFXFLANGER_PHASE_180 = 4;

        public static readonly Guid IID_IDirectSoundFXEcho__scanned__ = new Guid(0x8bd28edf, 0x50db, 0x4e92, 0xa2, 0xbd, 0x44, 0x54, 0x88, 0xd1, 0xed, 0x42);

        public const float DSFXECHO_WETDRYMIX_MIN = 0.0f;

        public const float DSFXECHO_WETDRYMIX_MAX = 100.0f;

        public const float DSFXECHO_FEEDBACK_MIN = 0.0f;

        public const float DSFXECHO_FEEDBACK_MAX = 100.0f;

        public const float DSFXECHO_LEFTDELAY_MIN = 1.0f;

        public const float DSFXECHO_LEFTDELAY_MAX = 2000.0f;

        public const float DSFXECHO_RIGHTDELAY_MIN = 1.0f;

        public const float DSFXECHO_RIGHTDELAY_MAX = 2000.0f;

        public const uint DSFXECHO_PANDELAY_MIN = 0;

        public const uint DSFXECHO_PANDELAY_MAX = 1;

        public static readonly Guid IID_IDirectSoundFXDistortion__scanned__ = new Guid(0x8ecf4326, 0x455f, 0x4d8b, 0xbd, 0xa9, 0x8d, 0x5d, 0x3e, 0x9e, 0x3e, 0x0b);

        public const float DSFXDISTORTION_GAIN_MIN = -60.0f;

        public const float DSFXDISTORTION_GAIN_MAX = 0.0f;

        public const float DSFXDISTORTION_EDGE_MIN = 0.0f;

        public const float DSFXDISTORTION_EDGE_MAX = 100.0f;

        public const float DSFXDISTORTION_POSTEQCENTERFREQUENCY_MIN = 100.0f;

        public const float DSFXDISTORTION_POSTEQCENTERFREQUENCY_MAX = 8000.0f;

        public const float DSFXDISTORTION_POSTEQBANDWIDTH_MIN = 100.0f;

        public const float DSFXDISTORTION_POSTEQBANDWIDTH_MAX = 8000.0f;

        public const float DSFXDISTORTION_PRELOWPASSCUTOFF_MIN = 100.0f;

        public const float DSFXDISTORTION_PRELOWPASSCUTOFF_MAX = 8000.0f;

        public static readonly Guid IID_IDirectSoundFXCompressor__scanned__ = new Guid(0x4bbd1154, 0x62f6, 0x4e2c, 0xa1, 0x5c, 0xd3, 0xb6, 0xc4, 0x17, 0xf7, 0xa0);

        public const float DSFXCOMPRESSOR_GAIN_MIN = -60.0f;

        public const float DSFXCOMPRESSOR_GAIN_MAX = 60.0f;

        public const float DSFXCOMPRESSOR_ATTACK_MIN = 0.01f;

        public const float DSFXCOMPRESSOR_ATTACK_MAX = 500.0f;

        public const float DSFXCOMPRESSOR_RELEASE_MIN = 50.0f;

        public const float DSFXCOMPRESSOR_RELEASE_MAX = 3000.0f;

        public const float DSFXCOMPRESSOR_THRESHOLD_MIN = -60.0f;

        public const float DSFXCOMPRESSOR_THRESHOLD_MAX = 0.0f;

        public const float DSFXCOMPRESSOR_RATIO_MIN = 1.0f;

        public const float DSFXCOMPRESSOR_RATIO_MAX = 100.0f;

        public const float DSFXCOMPRESSOR_PREDELAY_MIN = 0.0f;

        public const float DSFXCOMPRESSOR_PREDELAY_MAX = 4.0f;

        public static readonly Guid IID_IDirectSoundFXParamEq__scanned__ = new Guid(0xc03ca9fe, 0xfe90, 0x4204, 0x80, 0x78, 0x82, 0x33, 0x4c, 0xd1, 0x77, 0xda);

        public const float DSFXPARAMEQ_CENTER_MIN = 80.0f;

        public const float DSFXPARAMEQ_CENTER_MAX = 16000.0f;

        public const float DSFXPARAMEQ_BANDWIDTH_MIN = 1.0f;

        public const float DSFXPARAMEQ_BANDWIDTH_MAX = 36.0f;

        public const float DSFXPARAMEQ_GAIN_MIN = -15.0f;

        public const float DSFXPARAMEQ_GAIN_MAX = 15.0f;

        public static readonly Guid IID_IDirectSoundFXI3DL2Reverb__scanned__ = new Guid(0x4b166a6a, 0x0d66, 0x43f3, 0x80, 0xe3, 0xee, 0x62, 0x80, 0xde, 0xe1, 0xa4);

        public const int DSFX_I3DL2REVERB_ROOM_MIN = -10000;

        public const uint DSFX_I3DL2REVERB_ROOM_MAX = 0;

        public const int DSFX_I3DL2REVERB_ROOM_DEFAULT = -1000;

        public const int DSFX_I3DL2REVERB_ROOMHF_MIN = -10000;

        public const uint DSFX_I3DL2REVERB_ROOMHF_MAX = 0;

        public const int DSFX_I3DL2REVERB_ROOMHF_DEFAULT = -100;

        public const float DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_MIN = 0.0f;

        public const float DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_MAX = 10.0f;

        public const float DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_DEFAULT = 0.0f;

        public const float DSFX_I3DL2REVERB_DECAYTIME_MIN = 0.1f;

        public const float DSFX_I3DL2REVERB_DECAYTIME_MAX = 20.0f;

        public const float DSFX_I3DL2REVERB_DECAYTIME_DEFAULT = 1.49f;

        public const float DSFX_I3DL2REVERB_DECAYHFRATIO_MIN = 0.1f;

        public const float DSFX_I3DL2REVERB_DECAYHFRATIO_MAX = 2.0f;

        public const float DSFX_I3DL2REVERB_DECAYHFRATIO_DEFAULT = 0.83f;

        public const int DSFX_I3DL2REVERB_REFLECTIONS_MIN = -10000;

        public const uint DSFX_I3DL2REVERB_REFLECTIONS_MAX = 1000;

        public const int DSFX_I3DL2REVERB_REFLECTIONS_DEFAULT = -2602;

        public const float DSFX_I3DL2REVERB_REFLECTIONSDELAY_MIN = 0.0f;

        public const float DSFX_I3DL2REVERB_REFLECTIONSDELAY_MAX = 0.3f;

        public const float DSFX_I3DL2REVERB_REFLECTIONSDELAY_DEFAULT = 0.007f;

        public const int DSFX_I3DL2REVERB_REVERB_MIN = -10000;

        public const uint DSFX_I3DL2REVERB_REVERB_MAX = 2000;

        public const uint DSFX_I3DL2REVERB_REVERB_DEFAULT = 200;

        public const float DSFX_I3DL2REVERB_REVERBDELAY_MIN = 0.0f;

        public const float DSFX_I3DL2REVERB_REVERBDELAY_MAX = 0.1f;

        public const float DSFX_I3DL2REVERB_REVERBDELAY_DEFAULT = 0.011f;

        public const float DSFX_I3DL2REVERB_DIFFUSION_MIN = 0.0f;

        public const float DSFX_I3DL2REVERB_DIFFUSION_MAX = 100.0f;

        public const float DSFX_I3DL2REVERB_DIFFUSION_DEFAULT = 100.0f;

        public const float DSFX_I3DL2REVERB_DENSITY_MIN = 0.0f;

        public const float DSFX_I3DL2REVERB_DENSITY_MAX = 100.0f;

        public const float DSFX_I3DL2REVERB_DENSITY_DEFAULT = 100.0f;

        public const float DSFX_I3DL2REVERB_HFREFERENCE_MIN = 20.0f;

        public const float DSFX_I3DL2REVERB_HFREFERENCE_MAX = 20000.0f;

        public const float DSFX_I3DL2REVERB_HFREFERENCE_DEFAULT = 5000.0f;

        public const uint DSFX_I3DL2REVERB_QUALITY_MIN = 0;

        public const uint DSFX_I3DL2REVERB_QUALITY_MAX = 3;

        public const uint DSFX_I3DL2REVERB_QUALITY_DEFAULT = 2;

        public static readonly Guid IID_IDirectSoundFXWavesReverb__scanned__ = new Guid(0x46858c3a,0x0dc6,0x45e3,0xb7,0x60,0xd4,0xee,0xf1,0x6c,0xb3,0x25);

        public const float DSFX_WAVESREVERB_INGAIN_MIN = -96.0f;

        public const float DSFX_WAVESREVERB_INGAIN_MAX = 0.0f;

        public const float DSFX_WAVESREVERB_INGAIN_DEFAULT = 0.0f;

        public const float DSFX_WAVESREVERB_REVERBMIX_MIN = -96.0f;

        public const float DSFX_WAVESREVERB_REVERBMIX_MAX = 0.0f;

        public const float DSFX_WAVESREVERB_REVERBMIX_DEFAULT = 0.0f;

        public const float DSFX_WAVESREVERB_REVERBTIME_MIN = 0.001f;

        public const float DSFX_WAVESREVERB_REVERBTIME_MAX = 3000.0f;

        public const float DSFX_WAVESREVERB_REVERBTIME_DEFAULT = 1000.0f;

        public const float DSFX_WAVESREVERB_HIGHFREQRTRATIO_MIN = 0.001f;

        public const float DSFX_WAVESREVERB_HIGHFREQRTRATIO_MAX = 0.999f;

        public const float DSFX_WAVESREVERB_HIGHFREQRTRATIO_DEFAULT = 0.001f;

        public static readonly Guid IID_IDirectSoundCaptureFXAec__scanned__ = new Guid(0xad74143d, 0x903d, 0x4ab7, 0x80, 0x66, 0x28, 0xd3, 0x63, 0x03, 0x6d, 0x65);

        public const uint DSCFX_AEC_MODE_PASS_THROUGH = 0x0;

        public const uint DSCFX_AEC_MODE_HALF_DUPLEX = 0x1;

        public const uint DSCFX_AEC_MODE_FULL_DUPLEX = 0x2;

        public const uint DSCFX_AEC_STATUS_HISTORY_UNINITIALIZED = 0x0;

        public const uint DSCFX_AEC_STATUS_HISTORY_CONTINUOUSLY_CONVERGED = 0x1;

        public const uint DSCFX_AEC_STATUS_HISTORY_PREVIOUSLY_DIVERGED = 0x2;

        public const uint DSCFX_AEC_STATUS_CURRENTLY_CONVERGED = 0x8;

        public static readonly Guid IID_IDirectSoundCaptureFXNoiseSuppress__scanned__ = new Guid(0xed311e41, 0xfbae, 0x4175, 0x96, 0x25, 0xcd, 0x8, 0x54, 0xf6, 0x93, 0xca);

        public static readonly Guid IID_IDirectSoundFullDuplex__scanned__ = new Guid(0xedcb4c7a, 0xdaab, 0x4216, 0xa4, 0x2e, 0x6c, 0x50, 0x59, 0x6d, 0xdc, 0x1d);

        [NativeTypeName("HRESULT")]
        public const int DS_NO_VIRTUALIZATION = unchecked((int)((0) << 31) | (((int)(_FACDS)) << 16) | (int)(10));

        public const uint DSCAPS_PRIMARYMONO = 0x00000001;

        public const uint DSCAPS_PRIMARYSTEREO = 0x00000002;

        public const uint DSCAPS_PRIMARY8BIT = 0x00000004;

        public const uint DSCAPS_PRIMARY16BIT = 0x00000008;

        public const uint DSCAPS_CONTINUOUSRATE = 0x00000010;

        public const uint DSCAPS_EMULDRIVER = 0x00000020;

        public const uint DSCAPS_CERTIFIED = 0x00000040;

        public const uint DSCAPS_SECONDARYMONO = 0x00000100;

        public const uint DSCAPS_SECONDARYSTEREO = 0x00000200;

        public const uint DSCAPS_SECONDARY8BIT = 0x00000400;

        public const uint DSCAPS_SECONDARY16BIT = 0x00000800;

        public const uint DSSCL_NORMAL = 0x00000001;

        public const uint DSSCL_PRIORITY = 0x00000002;

        public const uint DSSCL_EXCLUSIVE = 0x00000003;

        public const uint DSSCL_WRITEPRIMARY = 0x00000004;

        public const uint DSSPEAKER_DIRECTOUT = 0x00000000;

        public const uint DSSPEAKER_HEADPHONE = 0x00000001;

        public const uint DSSPEAKER_MONO = 0x00000002;

        public const uint DSSPEAKER_QUAD = 0x00000003;

        public const uint DSSPEAKER_STEREO = 0x00000004;

        public const uint DSSPEAKER_SURROUND = 0x00000005;

        public const uint DSSPEAKER_5POINT1 = 0x00000006;

        public const uint DSSPEAKER_7POINT1 = 0x00000007;

        public const uint DSSPEAKER_7POINT1_SURROUND = 0x00000008;

        public const uint DSSPEAKER_5POINT1_SURROUND = 0x00000009;

        public const uint DSSPEAKER_GEOMETRY_MIN = 0x00000005;

        public const uint DSSPEAKER_GEOMETRY_NARROW = 0x0000000A;

        public const uint DSSPEAKER_GEOMETRY_WIDE = 0x00000014;

        public const uint DSSPEAKER_GEOMETRY_MAX = 0x000000B4;

        public const uint DSBCAPS_PRIMARYBUFFER = 0x00000001;

        public const uint DSBCAPS_STATIC = 0x00000002;

        public const uint DSBCAPS_LOCHARDWARE = 0x00000004;

        public const uint DSBCAPS_LOCSOFTWARE = 0x00000008;

        public const uint DSBCAPS_CTRL3D = 0x00000010;

        public const uint DSBCAPS_CTRLFREQUENCY = 0x00000020;

        public const uint DSBCAPS_CTRLPAN = 0x00000040;

        public const uint DSBCAPS_CTRLVOLUME = 0x00000080;

        public const uint DSBCAPS_CTRLPOSITIONNOTIFY = 0x00000100;

        public const uint DSBCAPS_CTRLFX = 0x00000200;

        public const uint DSBCAPS_STICKYFOCUS = 0x00004000;

        public const uint DSBCAPS_GLOBALFOCUS = 0x00008000;

        public const uint DSBCAPS_GETCURRENTPOSITION2 = 0x00010000;

        public const uint DSBCAPS_MUTE3DATMAXDISTANCE = 0x00020000;

        public const uint DSBCAPS_LOCDEFER = 0x00040000;

        public const uint DSBCAPS_TRUEPLAYPOSITION = 0x00080000;

        public const uint DSBPLAY_LOOPING = 0x00000001;

        public const uint DSBPLAY_LOCHARDWARE = 0x00000002;

        public const uint DSBPLAY_LOCSOFTWARE = 0x00000004;

        public const uint DSBPLAY_TERMINATEBY_TIME = 0x00000008;

        public const ulong DSBPLAY_TERMINATEBY_DISTANCE = 0x000000010;

        public const ulong DSBPLAY_TERMINATEBY_PRIORITY = 0x000000020;

        public const uint DSBSTATUS_PLAYING = 0x00000001;

        public const uint DSBSTATUS_BUFFERLOST = 0x00000002;

        public const uint DSBSTATUS_LOOPING = 0x00000004;

        public const uint DSBSTATUS_LOCHARDWARE = 0x00000008;

        public const uint DSBSTATUS_LOCSOFTWARE = 0x00000010;

        public const uint DSBSTATUS_TERMINATED = 0x00000020;

        public const uint DSBLOCK_FROMWRITECURSOR = 0x00000001;

        public const uint DSBLOCK_ENTIREBUFFER = 0x00000002;

        public const uint DSBFREQUENCY_ORIGINAL = 0;

        public const uint DSBFREQUENCY_MIN = 100;

        public const uint DSBFREQUENCY_MAX = 200000;

        public const int DSBPAN_LEFT = -10000;

        public const uint DSBPAN_CENTER = 0;

        public const uint DSBPAN_RIGHT = 10000;

        public const int DSBVOLUME_MIN = -10000;

        public const uint DSBVOLUME_MAX = 0;

        public const uint DSBSIZE_MIN = 4;

        public const uint DSBSIZE_MAX = 0x0FFFFFFF;

        public const uint DSBSIZE_FX_MIN = 150;

        public const uint DSBNOTIFICATIONS_MAX = 100000;

        public const uint DS3DMODE_NORMAL = 0x00000000;

        public const uint DS3DMODE_HEADRELATIVE = 0x00000001;

        public const uint DS3DMODE_DISABLE = 0x00000002;

        public const uint DS3D_IMMEDIATE = 0x00000000;

        public const uint DS3D_DEFERRED = 0x00000001;

        public const float DS3D_DEFAULTDISTANCEFACTOR = 1.0f;

        public const float DS3D_MINROLLOFFFACTOR = 0.0f;

        public const float DS3D_MAXROLLOFFFACTOR = 10.0f;

        public const float DS3D_DEFAULTROLLOFFFACTOR = 1.0f;

        public const float DS3D_MINDOPPLERFACTOR = 0.0f;

        public const float DS3D_MAXDOPPLERFACTOR = 10.0f;

        public const float DS3D_DEFAULTDOPPLERFACTOR = 1.0f;

        public const float DS3D_DEFAULTMINDISTANCE = 1.0f;

        public const float DS3D_DEFAULTMAXDISTANCE = 1000000000.0f;

        public const uint DS3D_MINCONEANGLE = 0;

        public const uint DS3D_MAXCONEANGLE = 360;

        public const uint DS3D_DEFAULTCONEANGLE = 360;

        public const uint DSCCAPS_MULTIPLECAPTURE = 0x00000001;

        public const uint DSCBCAPS_WAVEMAPPED = 0x80000000;

        public const uint DSCBCAPS_CTRLFX = 0x00000200;

        public const uint DSCBLOCK_ENTIREBUFFER = 0x00000001;

        public const uint DSCBSTATUS_CAPTURING = 0x00000001;

        public const uint DSCBSTATUS_LOOPING = 0x00000002;

        public const uint DSCBSTART_LOOPING = 0x00000001;

        public const uint DSBPN_OFFSETSTOP = 0xFFFFFFFF;

        public const uint DS_CERTIFIED = 0x00000000;

        public const uint DS_UNCERTIFIED = 0x00000001;

        public static readonly Guid DS3DALG_NO_VIRTUALIZATION__scanned__ = new Guid(0xc241333f, 0x1c1b, 0x11d2, 0x94, 0xf5, 0x0, 0xc0, 0x4f, 0xc2, 0x8a, 0xca);

        public static readonly Guid DS3DALG_HRTF_FULL__scanned__ = new Guid(0xc2413340, 0x1c1b, 0x11d2, 0x94, 0xf5, 0x0, 0xc0, 0x4f, 0xc2, 0x8a, 0xca);

        public static readonly Guid DS3DALG_HRTF_LIGHT__scanned__ = new Guid(0xc2413342, 0x1c1b, 0x11d2, 0x94, 0xf5, 0x0, 0xc0, 0x4f, 0xc2, 0x8a, 0xca);

        public static readonly Guid GUID_DSFX_STANDARD_GARGLE__scanned__ = new Guid(0xdafd8210, 0x5711, 0x4b91, 0x9f, 0xe3, 0xf7, 0x5b, 0x7a, 0xe2, 0x79, 0xbf);

        public static readonly Guid GUID_DSFX_STANDARD_CHORUS__scanned__ = new Guid(0xefe6629c, 0x81f7, 0x4281, 0xbd, 0x91, 0xc9, 0xd6, 0x04, 0xa9, 0x5a, 0xf6);

        public static readonly Guid GUID_DSFX_STANDARD_FLANGER__scanned__ = new Guid(0xefca3d92, 0xdfd8, 0x4672, 0xa6, 0x03, 0x74, 0x20, 0x89, 0x4b, 0xad, 0x98);

        public static readonly Guid GUID_DSFX_STANDARD_ECHO__scanned__ = new Guid(0xef3e932c, 0xd40b, 0x4f51, 0x8c, 0xcf, 0x3f, 0x98, 0xf1, 0xb2, 0x9d, 0x5d);

        public static readonly Guid GUID_DSFX_STANDARD_DISTORTION__scanned__ = new Guid(0xef114c90, 0xcd1d, 0x484e, 0x96, 0xe5, 0x09, 0xcf, 0xaf, 0x91, 0x2a, 0x21);

        public static readonly Guid GUID_DSFX_STANDARD_COMPRESSOR__scanned__ = new Guid(0xef011f79, 0x4000, 0x406d, 0x87, 0xaf, 0xbf, 0xfb, 0x3f, 0xc3, 0x9d, 0x57);

        public static readonly Guid GUID_DSFX_STANDARD_PARAMEQ__scanned__ = new Guid(0x120ced89, 0x3bf4, 0x4173, 0xa1, 0x32, 0x3c, 0xb4, 0x06, 0xcf, 0x32, 0x31);

        public static readonly Guid GUID_DSFX_STANDARD_I3DL2REVERB__scanned__ = new Guid(0xef985e71, 0xd5c7, 0x42d4, 0xba, 0x4d, 0x2d, 0x07, 0x3e, 0x2e, 0x96, 0xf4);

        public static readonly Guid GUID_DSFX_WAVES_REVERB__scanned__ = new Guid(0x87fc0268, 0x9a55, 0x4360, 0x95, 0xaa, 0x00, 0x4a, 0x1d, 0x9d, 0xe2, 0x6c);

        public static readonly Guid GUID_DSCFX_CLASS_AEC__scanned__ = new Guid(0xBF963D80L, 0xC559, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1);

        public static readonly Guid GUID_DSCFX_MS_AEC__scanned__ = new Guid(0xcdebb919, 0x379a, 0x488a, 0x87, 0x65, 0xf5, 0x3c, 0xfd, 0x36, 0xde, 0x40);

        public static readonly Guid GUID_DSCFX_SYSTEM_AEC__scanned__ = new Guid(0x1c22c56d, 0x9879, 0x4f5b, 0xa3, 0x89, 0x27, 0x99, 0x6d, 0xdc, 0x28, 0x10);

        public static readonly Guid GUID_DSCFX_CLASS_NS__scanned__ = new Guid(0xe07f903f, 0x62fd, 0x4e60, 0x8c, 0xdd, 0xde, 0xa7, 0x23, 0x66, 0x65, 0xb5);

        public static readonly Guid GUID_DSCFX_MS_NS__scanned__ = new Guid(0x11c5c73b, 0x66e9, 0x4ba1, 0xa0, 0xba, 0xe8, 0x14, 0xc6, 0xee, 0xd9, 0x2d);

        public static readonly Guid GUID_DSCFX_SYSTEM_NS__scanned__ = new Guid(0x5ab0882e, 0x7274, 0x4516, 0x87, 0x7d, 0x4e, 0xee, 0x99, 0xba, 0x4f, 0xd0);

        public const uint DMUS_DOWNLOADINFO_INSTRUMENT = 1;

        public const uint DMUS_DOWNLOADINFO_WAVE = 2;

        public const uint DMUS_DOWNLOADINFO_INSTRUMENT2 = 3;

        public const uint DMUS_DOWNLOADINFO_WAVEARTICULATION = 4;

        public const uint DMUS_DOWNLOADINFO_STREAMINGWAVE = 5;

        public const uint DMUS_DOWNLOADINFO_ONESHOTWAVE = 6;

        public const uint DMUS_DEFAULT_SIZE_OFFSETTABLE = 1;

        public const uint DMUS_INSTRUMENT_GM_INSTRUMENT = 1u<< 0;

        public const uint DMUS_MIN_DATA_SIZE = 4;

        public const uint CONN_SRC_NONE = 0x0000;

        public const uint CONN_SRC_LFO = 0x0001;

        public const uint CONN_SRC_KEYONVELOCITY = 0x0002;

        public const uint CONN_SRC_KEYNUMBER = 0x0003;

        public const uint CONN_SRC_EG1 = 0x0004;

        public const uint CONN_SRC_EG2 = 0x0005;

        public const uint CONN_SRC_PITCHWHEEL = 0x0006;

        public const uint CONN_SRC_CC1 = 0x0081;

        public const uint CONN_SRC_CC7 = 0x0087;

        public const uint CONN_SRC_CC10 = 0x008a;

        public const uint CONN_SRC_CC11 = 0x008b;

        public const uint CONN_DST_NONE = 0x0000;

        public const uint CONN_DST_ATTENUATION = 0x0001;

        public const uint CONN_DST_PITCH = 0x0003;

        public const uint CONN_DST_PAN = 0x0004;

        public const uint CONN_DST_LFO_FREQUENCY = 0x0104;

        public const uint CONN_DST_LFO_STARTDELAY = 0x0105;

        public const uint CONN_DST_EG1_ATTACKTIME = 0x0206;

        public const uint CONN_DST_EG1_DECAYTIME = 0x0207;

        public const uint CONN_DST_EG1_RELEASETIME = 0x0209;

        public const uint CONN_DST_EG1_SUSTAINLEVEL = 0x020a;

        public const uint CONN_DST_EG2_ATTACKTIME = 0x030a;

        public const uint CONN_DST_EG2_DECAYTIME = 0x030b;

        public const uint CONN_DST_EG2_RELEASETIME = 0x030d;

        public const uint CONN_DST_EG2_SUSTAINLEVEL = 0x030e;

        public const uint CONN_TRN_NONE = 0x0000;

        public const uint CONN_TRN_CONCAVE = 0x0001;

        public const uint F_INSTRUMENT_DRUMS = 0x80000000;

        public const uint F_RGN_OPTION_SELFNONEXCLUSIVE = 0x0001;

        public const int WAVELINK_CHANNEL_LEFT = 0x0001;

        public const int WAVELINK_CHANNEL_RIGHT = 0x0002;

        public const uint F_WAVELINK_PHASE_MASTER = 0x0001;

        public const int POOL_CUE_NULL = unchecked((int)0xffffffff);

        public const int F_WSMP_NO_TRUNCATION = 0x0001;

        public const int F_WSMP_NO_COMPRESSION = 0x0002;

        public const uint WLOOP_TYPE_FORWARD = 0;

        [NativeTypeName("HRESULT")]
        public const int APOERR_ALREADY_INITIALIZED = unchecked((int)0x887D0001);

        [NativeTypeName("HRESULT")]
        public const int APOERR_NOT_INITIALIZED = unchecked((int)0x887D0002);

        [NativeTypeName("HRESULT")]
        public const int APOERR_FORMAT_NOT_SUPPORTED = unchecked((int)0x887D0003);

        [NativeTypeName("HRESULT")]
        public const int APOERR_INVALID_APO_CLSID = unchecked((int)0x887D0004);

        [NativeTypeName("HRESULT")]
        public const int APOERR_BUFFERS_OVERLAP = unchecked((int)0x887D0005);

        [NativeTypeName("HRESULT")]
        public const int APOERR_ALREADY_UNLOCKED = unchecked((int)0x887D0006);

        [NativeTypeName("HRESULT")]
        public const int APOERR_NUM_CONNECTIONS_INVALID = unchecked((int)0x887D0007);

        [NativeTypeName("HRESULT")]
        public const int APOERR_INVALID_OUTPUT_MAXFRAMECOUNT = unchecked((int)0x887D0008);

        [NativeTypeName("HRESULT")]
        public const int APOERR_INVALID_CONNECTION_FORMAT = unchecked((int)0x887D0009);

        [NativeTypeName("HRESULT")]
        public const int APOERR_APO_LOCKED = unchecked((int)0x887D000A);

        [NativeTypeName("HRESULT")]
        public const int APOERR_INVALID_COEFFCOUNT = unchecked((int)0x887D000B);

        [NativeTypeName("HRESULT")]
        public const int APOERR_INVALID_COEFFICIENT = unchecked((int)0x887D000C);

        [NativeTypeName("HRESULT")]
        public const int APOERR_INVALID_CURVE_PARAM = unchecked((int)0x887D000D);

        public const double AUDIO_MIN_FRAMERATE = 10.0;

        public const double AUDIO_MAX_FRAMERATE = 384000.0;

        public const uint AUDIO_MIN_CHANNELS = 1;

        public const uint AUDIO_MAX_CHANNELS = 4096;

        public const uint REFRESH_F_LASTBUFFER = 0x00000001;

        public static readonly Guid IID_IDirectMusicSynth__scanned__ = new Guid(0x9823661,  0x5c85, 0x11d2, 0xaf, 0xa6, 0x0, 0xaa, 0x0, 0x24, 0xd8, 0xb6);

        public static readonly Guid IID_IDirectMusicSynthSink__scanned__ = new Guid(0x9823663, 0x5c85, 0x11d2, 0xaf, 0xa6, 0x0, 0xaa, 0x0, 0x24, 0xd8, 0xb6);

        public static readonly Guid IID_IDirectMusicSynth8__scanned__ = new Guid(0x53cab625, 0x2711, 0x4c9f, 0x9d, 0xe7, 0x1b, 0x7f, 0x92, 0x5f, 0x6f, 0xc8);

        public static readonly Guid CLSID_DirectMusicSynthSink__scanned__ = new Guid(0xaec17ce3, 0xa514, 0x11d1, 0xaf, 0xa6, 0x0, 0xaa, 0x0, 0x24, 0xd8, 0xb6);

        public static readonly Guid GUID_DMUS_PROP_SetSynthSink__scanned__ = new Guid(0x0a3a5ba5, 0x37b6, 0x11d2, 0xb9, 0xf9, 0x00, 0x00, 0xf8, 0x75, 0xac, 0x12);

        public static readonly Guid GUID_DMUS_PROP_SinkUsesDSound__scanned__ = new Guid(0xbe208857, 0x8952, 0x11d2, 0xba, 0x1c, 0x00, 0x00, 0xf8, 0x75, 0xac, 0x12);

        public const uint AUDIOMEDIATYPE_EQUAL_FORMAT_TYPES = 0x00000002;

        public const uint AUDIOMEDIATYPE_EQUAL_FORMAT_DATA = 0x00000004;

        public const uint AUDIOMEDIATYPE_EQUAL_FORMAT_USER_DATA = 0x00000008;

    }
}

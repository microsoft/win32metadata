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


namespace Windows.Win32.Media.Audio.XAudio2
{
    public static partial class Apis
    {
        public const uint XAUDIO2_MAX_BUFFER_BYTES = 0x80000000;

        public const uint XAUDIO2_MAX_QUEUED_BUFFERS = 64;

        public const uint XAUDIO2_MAX_BUFFERS_SYSTEM = 2;

        public const uint XAUDIO2_MAX_AUDIO_CHANNELS = 64;

        public const uint XAUDIO2_MIN_SAMPLE_RATE = 1000;

        public const uint XAUDIO2_MAX_SAMPLE_RATE = 200000;

        public const float XAUDIO2_MAX_VOLUME_LEVEL = 16777216.0f;

        public const float XAUDIO2_MAX_FREQ_RATIO = 1024.0f;

        public const float XAUDIO2_DEFAULT_FREQ_RATIO = 2.0f;

        public const float XAUDIO2_MAX_FILTER_ONEOVERQ = 1.5f;

        public const float XAUDIO2_MAX_FILTER_FREQUENCY = 1.0f;

        public const uint XAUDIO2_MAX_LOOP_COUNT = 254;

        public const uint XAUDIO2_MAX_INSTANCES = 8;

        public const uint XAUDIO2_MAX_RATIO_TIMES_RATE_XMA_MONO = 600000;

        public const uint XAUDIO2_MAX_RATIO_TIMES_RATE_XMA_MULTICHANNEL = 300000;

        public const uint XAUDIO2_COMMIT_NOW = 0;

        public const uint XAUDIO2_COMMIT_ALL = 0;

        public const uint XAUDIO2_NO_LOOP_REGION = 0;

        public const uint XAUDIO2_LOOP_INFINITE = 255;

        public const uint XAUDIO2_DEFAULT_CHANNELS = 0;

        public const uint XAUDIO2_DEFAULT_SAMPLERATE = 0;

        public const uint XAUDIO2_DEBUG_ENGINE = 0x0001;

        public const uint XAUDIO2_VOICE_NOPITCH = 0x0002;

        public const uint XAUDIO2_VOICE_NOSRC = 0x0004;

        public const uint XAUDIO2_VOICE_USEFILTER = 0x0008;

        public const uint XAUDIO2_PLAY_TAILS = 0x0020;

        public const uint XAUDIO2_END_OF_STREAM = 0x0040;

        public const uint XAUDIO2_SEND_USEFILTER = 0x0080;

        public const uint XAUDIO2_VOICE_NOSAMPLESPLAYED = 0x0100;

        public const uint XAUDIO2_STOP_ENGINE_WHEN_IDLE = 0x2000;

        public const uint XAUDIO2_1024_QUANTUM = 0x8000;

        public const uint XAUDIO2_NO_VIRTUAL_AUDIO_CLIENT = 0x10000;

        public const float XAUDIO2_DEFAULT_FILTER_ONEOVERQ = 1.0f;

        public const uint XAUDIO2_QUANTUM_NUMERATOR = 1;

        public const uint XAUDIO2_QUANTUM_DENOMINATOR = 100;

        public const uint FACILITY_XAUDIO2 = 0x896;

        [NativeTypeName("HRESULT")]
        public const int XAUDIO2_E_INVALID_CALL = unchecked((int)0x88960001);

        [NativeTypeName("HRESULT")]
        public const int XAUDIO2_E_XMA_DECODER_ERROR = unchecked((int)0x88960002);

        [NativeTypeName("HRESULT")]
        public const int XAUDIO2_E_XAPO_CREATION_FAILED = unchecked((int)0x88960003);

        [NativeTypeName("HRESULT")]
        public const int XAUDIO2_E_DEVICE_INVALIDATED = unchecked((int)0x88960004);

        public const uint Processor1 = 0x00000001;

        public const uint Processor2 = 0x00000002;

        public const uint Processor3 = 0x00000004;

        public const uint Processor4 = 0x00000008;

        public const uint Processor5 = 0x00000010;

        public const uint Processor6 = 0x00000020;

        public const uint Processor7 = 0x00000040;

        public const uint Processor8 = 0x00000080;

        public const uint Processor9 = 0x00000100;

        public const uint Processor10 = 0x00000200;

        public const uint Processor11 = 0x00000400;

        public const uint Processor12 = 0x00000800;

        public const uint Processor13 = 0x00001000;

        public const uint Processor14 = 0x00002000;

        public const uint Processor15 = 0x00004000;

        public const uint Processor16 = 0x00008000;

        public const uint Processor17 = 0x00010000;

        public const uint Processor18 = 0x00020000;

        public const uint Processor19 = 0x00040000;

        public const uint Processor20 = 0x00080000;

        public const uint Processor21 = 0x00100000;

        public const uint Processor22 = 0x00200000;

        public const uint Processor23 = 0x00400000;

        public const uint Processor24 = 0x00800000;

        public const uint Processor25 = 0x01000000;

        public const uint Processor26 = 0x02000000;

        public const uint Processor27 = 0x04000000;

        public const uint Processor28 = 0x08000000;

        public const uint Processor29 = 0x10000000;

        public const uint Processor30 = 0x20000000;

        public const uint Processor31 = 0x40000000;

        public const uint Processor32 = 0x80000000;

        public const uint XAUDIO2_ANY_PROCESSOR = 0xffffffff;

        public const uint XAUDIO2_USE_DEFAULT_PROCESSOR = 0x00000000;

        public const uint XAUDIO2_LOG_ERRORS = 0x0001;

        public const uint XAUDIO2_LOG_WARNINGS = 0x0002;

        public const uint XAUDIO2_LOG_INFO = 0x0004;

        public const uint XAUDIO2_LOG_DETAIL = 0x0008;

        public const uint XAUDIO2_LOG_API_CALLS = 0x0010;

        public const uint XAUDIO2_LOG_FUNC_CALLS = 0x0020;

        public const uint XAUDIO2_LOG_TIMING = 0x0040;

        public const uint XAUDIO2_LOG_LOCKS = 0x0080;

        public const uint XAUDIO2_LOG_MEMORY = 0x0100;

        public const uint XAUDIO2_LOG_STREAMING = 0x1000;

        public const uint XAUDIO2FX_REVERB_MIN_FRAMERATE = 20000;

        public const uint XAUDIO2FX_REVERB_MAX_FRAMERATE = 48000;

        public const float XAUDIO2FX_REVERB_MIN_WET_DRY_MIX = 0.0f;

        public const uint XAUDIO2FX_REVERB_MIN_REFLECTIONS_DELAY = 0;

        public const uint XAUDIO2FX_REVERB_MIN_REVERB_DELAY = 0;

        public const uint XAUDIO2FX_REVERB_MIN_REAR_DELAY = 0;

        public const uint XAUDIO2FX_REVERB_MIN_7POINT1_SIDE_DELAY = 0;

        public const uint XAUDIO2FX_REVERB_MIN_7POINT1_REAR_DELAY = 0;

        public const uint XAUDIO2FX_REVERB_MIN_POSITION = 0;

        public const uint XAUDIO2FX_REVERB_MIN_DIFFUSION = 0;

        public const uint XAUDIO2FX_REVERB_MIN_LOW_EQ_GAIN = 0;

        public const uint XAUDIO2FX_REVERB_MIN_LOW_EQ_CUTOFF = 0;

        public const uint XAUDIO2FX_REVERB_MIN_HIGH_EQ_GAIN = 0;

        public const uint XAUDIO2FX_REVERB_MIN_HIGH_EQ_CUTOFF = 0;

        public const float XAUDIO2FX_REVERB_MIN_ROOM_FILTER_FREQ = 20.0f;

        public const float XAUDIO2FX_REVERB_MIN_ROOM_FILTER_MAIN = -100.0f;

        public const float XAUDIO2FX_REVERB_MIN_ROOM_FILTER_HF = -100.0f;

        public const float XAUDIO2FX_REVERB_MIN_REFLECTIONS_GAIN = -100.0f;

        public const float XAUDIO2FX_REVERB_MIN_REVERB_GAIN = -100.0f;

        public const float XAUDIO2FX_REVERB_MIN_DECAY_TIME = 0.1f;

        public const float XAUDIO2FX_REVERB_MIN_DENSITY = 0.0f;

        public const float XAUDIO2FX_REVERB_MIN_ROOM_SIZE = 0.0f;

        public const float XAUDIO2FX_REVERB_MAX_WET_DRY_MIX = 100.0f;

        public const uint XAUDIO2FX_REVERB_MAX_REFLECTIONS_DELAY = 300;

        public const uint XAUDIO2FX_REVERB_MAX_REVERB_DELAY = 85;

        public const uint XAUDIO2FX_REVERB_MAX_REAR_DELAY = 5;

        public const uint XAUDIO2FX_REVERB_MAX_7POINT1_SIDE_DELAY = 5;

        public const uint XAUDIO2FX_REVERB_MAX_7POINT1_REAR_DELAY = 20;

        public const uint XAUDIO2FX_REVERB_MAX_POSITION = 30;

        public const uint XAUDIO2FX_REVERB_MAX_DIFFUSION = 15;

        public const uint XAUDIO2FX_REVERB_MAX_LOW_EQ_GAIN = 12;

        public const uint XAUDIO2FX_REVERB_MAX_LOW_EQ_CUTOFF = 9;

        public const uint XAUDIO2FX_REVERB_MAX_HIGH_EQ_GAIN = 8;

        public const uint XAUDIO2FX_REVERB_MAX_HIGH_EQ_CUTOFF = 14;

        public const float XAUDIO2FX_REVERB_MAX_ROOM_FILTER_FREQ = 20000.0f;

        public const float XAUDIO2FX_REVERB_MAX_ROOM_FILTER_MAIN = 0.0f;

        public const float XAUDIO2FX_REVERB_MAX_ROOM_FILTER_HF = 0.0f;

        public const float XAUDIO2FX_REVERB_MAX_REFLECTIONS_GAIN = 20.0f;

        public const float XAUDIO2FX_REVERB_MAX_REVERB_GAIN = 20.0f;

        public const float XAUDIO2FX_REVERB_MAX_DENSITY = 100.0f;

        public const float XAUDIO2FX_REVERB_MAX_ROOM_SIZE = 100.0f;

        public const float XAUDIO2FX_REVERB_DEFAULT_WET_DRY_MIX = 100.0f;

        public const uint XAUDIO2FX_REVERB_DEFAULT_REFLECTIONS_DELAY = 5;

        public const uint XAUDIO2FX_REVERB_DEFAULT_REVERB_DELAY = 5;

        public const uint XAUDIO2FX_REVERB_DEFAULT_REAR_DELAY = 5;

        public const uint XAUDIO2FX_REVERB_DEFAULT_7POINT1_SIDE_DELAY = 5;

        public const uint XAUDIO2FX_REVERB_DEFAULT_7POINT1_REAR_DELAY = 20;

        public const uint XAUDIO2FX_REVERB_DEFAULT_POSITION = 6;

        public const uint XAUDIO2FX_REVERB_DEFAULT_POSITION_MATRIX = 27;

        public const uint XAUDIO2FX_REVERB_DEFAULT_EARLY_DIFFUSION = 8;

        public const uint XAUDIO2FX_REVERB_DEFAULT_LATE_DIFFUSION = 8;

        public const uint XAUDIO2FX_REVERB_DEFAULT_LOW_EQ_GAIN = 8;

        public const uint XAUDIO2FX_REVERB_DEFAULT_LOW_EQ_CUTOFF = 4;

        public const uint XAUDIO2FX_REVERB_DEFAULT_HIGH_EQ_GAIN = 8;

        public const uint XAUDIO2FX_REVERB_DEFAULT_HIGH_EQ_CUTOFF = 4;

        public const float XAUDIO2FX_REVERB_DEFAULT_ROOM_FILTER_FREQ = 5000.0f;

        public const float XAUDIO2FX_REVERB_DEFAULT_ROOM_FILTER_MAIN = 0.0f;

        public const float XAUDIO2FX_REVERB_DEFAULT_ROOM_FILTER_HF = 0.0f;

        public const float XAUDIO2FX_REVERB_DEFAULT_REFLECTIONS_GAIN = 0.0f;

        public const float XAUDIO2FX_REVERB_DEFAULT_REVERB_GAIN = 0.0f;

        public const float XAUDIO2FX_REVERB_DEFAULT_DECAY_TIME = 1.0f;

        public const float XAUDIO2FX_REVERB_DEFAULT_DENSITY = 100.0f;

        public const float XAUDIO2FX_REVERB_DEFAULT_ROOM_SIZE = 100.0f;

        public const uint XAUDIO2FX_REVERB_DEFAULT_DISABLE_LATE_FIELD = 0;

        public const float HRTF_MAX_GAIN_LIMIT = 12.0f;

        public const float HRTF_MIN_GAIN_LIMIT = -96.0f;

        public const float HRTF_MIN_UNITY_GAIN_DISTANCE = 0.05f;

        public const float HRTF_DEFAULT_UNITY_GAIN_DISTANCE = 1.0f;

        public const uint X3DAUDIO_HANDLE_BYTESIZE = 20;

        public const float X3DAUDIO_PI = 3.141592654f;

        public const float X3DAUDIO_2PI = 6.283185307f;

        public const float X3DAUDIO_SPEED_OF_SOUND = 343.5f;

        public const uint X3DAUDIO_CALCULATE_MATRIX = 0x00000001;

        public const uint X3DAUDIO_CALCULATE_DELAY = 0x00000002;

        public const uint X3DAUDIO_CALCULATE_LPF_DIRECT = 0x00000004;

        public const uint X3DAUDIO_CALCULATE_LPF_REVERB = 0x00000008;

        public const uint X3DAUDIO_CALCULATE_REVERB = 0x00000010;

        public const uint X3DAUDIO_CALCULATE_DOPPLER = 0x00000020;

        public const uint X3DAUDIO_CALCULATE_EMITTER_ANGLE = 0x00000040;

        public const uint X3DAUDIO_CALCULATE_ZEROCENTER = 0x00010000;

        public const uint X3DAUDIO_CALCULATE_REDIRECT_TO_LFE = 0x00020000;

    }
}

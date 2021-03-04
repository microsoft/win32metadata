﻿using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.SystemServices
{
    public static unsafe partial class Apis
    {
        public const int TRUE = 1;

        public const int FALSE = 0;

        public const ushort RT_CURSOR = 1;

        public const ushort RT_BITMAP = 2;

        public const ushort RT_ICON = 3;

        public const ushort RT_MENU = 4;

        public const ushort RT_DIALOG = 5;

        public const ushort RT_STRING = 6;

        public const ushort RT_FONTDIR = 7;

        public const ushort RT_FONT = 8;

        public const ushort RT_ACCELERATOR = 9;

        public const ushort RT_RCDATA = 10;

        public const ushort RT_MESSAGETABLE = 11;

        public const int DIFFERENCE = 11;

        public const ushort RT_GROUP_CURSOR = RT_CURSOR + DIFFERENCE;

        public const ushort RT_GROUP_ICON = RT_ICON + DIFFERENCE;

        public const ushort RT_VERSION = 16;

        public const ushort RT_DLGINCLUDE = 17;

        public const ushort RT_PLUGPLAY = 19;

        public const ushort RT_VXD = 20;

        public const ushort RT_ANICURSOR = 21;

        public const ushort RT_ANIICON = 22;

        public const ushort RT_HTML = 23;

        public const ushort RT_MANIFEST = 24;

        public const ushort CREATEPROCESS_MANIFEST_RESOURCE_ID = 1;

        public const ushort ISOLATIONAWARE_MANIFEST_RESOURCE_ID = 2;

        public const ushort ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID = 3;

        public const ushort ISOLATIONPOLICY_MANIFEST_RESOURCE_ID = 4;

        public const ushort ISOLATIONPOLICY_BROWSER_MANIFEST_RESOURCE_ID = 5;

        public const ushort MINIMUM_RESERVED_MANIFEST_RESOURCE_ID = 1;

        public const ushort MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID = 16;

        public const int SETWALLPAPER_DEFAULT = -1;

        public const int SB_HORZ = 0;

        public const int SB_VERT = 1;

        public const int SB_CTL = 2;

        public const int SB_BOTH = 3;

        public const int SB_LINEUP = 0;

        public const int SB_LINELEFT = 0;

        public const int SB_LINEDOWN = 1;

        public const int SB_LINERIGHT = 1;

        public const int SB_PAGEUP = 2;

        public const int SB_PAGELEFT = 2;

        public const int SB_PAGEDOWN = 3;

        public const int SB_PAGERIGHT = 3;

        public const int SB_THUMBPOSITION = 4;

        public const int SB_THUMBTRACK = 5;

        public const int SB_TOP = 6;

        public const int SB_LEFT = 6;

        public const int SB_BOTTOM = 7;

        public const int SB_RIGHT = 7;

        public const int SB_ENDSCROLL = 8;

        public const int SW_HIDE = 0;

        public const int SW_SHOWNORMAL = 1;

        public const int SW_NORMAL = 1;

        public const int SW_SHOWMINIMIZED = 2;

        public const int SW_SHOWMAXIMIZED = 3;

        public const int SW_MAXIMIZE = 3;

        public const int SW_SHOWNOACTIVATE = 4;

        public const int SW_SHOW = 5;

        public const int SW_MINIMIZE = 6;

        public const int SW_SHOWMINNOACTIVE = 7;

        public const int SW_SHOWNA = 8;

        public const int SW_RESTORE = 9;

        public const int SW_SHOWDEFAULT = 10;

        public const int SW_FORCEMINIMIZE = 11;

        public const int SW_MAX = 11;

        public const int HIDE_WINDOW = 0;

        public const int SHOW_OPENWINDOW = 1;

        public const int SHOW_ICONWINDOW = 2;

        public const int SHOW_FULLSCREEN = 3;

        public const int SHOW_OPENNOACTIVATE = 4;

        public const int SW_PARENTCLOSING = 1;

        public const int SW_OTHERZOOM = 2;

        public const int SW_PARENTOPENING = 3;

        public const int SW_OTHERUNZOOM = 4;

        public const int AW_HOR_POSITIVE = 0x00000001;

        public const int AW_HOR_NEGATIVE = 0x00000002;

        public const int AW_VER_POSITIVE = 0x00000004;

        public const int AW_VER_NEGATIVE = 0x00000008;

        public const int AW_CENTER = 0x00000010;

        public const int AW_HIDE = 0x00010000;

        public const int AW_ACTIVATE = 0x00020000;

        public const int AW_SLIDE = 0x00040000;

        public const int AW_BLEND = 0x00080000;

        public const int KF_EXTENDED = 0x0100;

        public const int KF_DLGMODE = 0x0800;

        public const int KF_MENUMODE = 0x1000;

        public const int KF_ALTDOWN = 0x2000;

        public const int KF_REPEAT = 0x4000;

        public const int KF_UP = 0x8000;

        public const int VK_LBUTTON = 0x01;

        public const int VK_RBUTTON = 0x02;

        public const int VK_CANCEL = 0x03;

        public const int VK_MBUTTON = 0x04;

        public const int VK_XBUTTON1 = 0x05;

        public const int VK_XBUTTON2 = 0x06;

        public const int VK_BACK = 0x08;

        public const int VK_TAB = 0x09;

        public const int VK_CLEAR = 0x0C;

        public const int VK_RETURN = 0x0D;

        public const int VK_SHIFT = 0x10;

        public const int VK_CONTROL = 0x11;

        public const int VK_MENU = 0x12;

        public const int VK_PAUSE = 0x13;

        public const int VK_CAPITAL = 0x14;

        public const int VK_KANA = 0x15;

        public const int VK_HANGEUL = 0x15;

        public const int VK_HANGUL = 0x15;

        public const int VK_JUNJA = 0x17;

        public const int VK_FINAL = 0x18;

        public const int VK_HANJA = 0x19;

        public const int VK_KANJI = 0x19;

        public const int VK_ESCAPE = 0x1B;

        public const int VK_CONVERT = 0x1C;

        public const int VK_NONCONVERT = 0x1D;

        public const int VK_ACCEPT = 0x1E;

        public const int VK_MODECHANGE = 0x1F;

        public const int VK_SPACE = 0x20;

        public const int VK_PRIOR = 0x21;

        public const int VK_NEXT = 0x22;

        public const int VK_END = 0x23;

        public const int VK_HOME = 0x24;

        public const int VK_LEFT = 0x25;

        public const int VK_UP = 0x26;

        public const int VK_RIGHT = 0x27;

        public const int VK_DOWN = 0x28;

        public const int VK_SELECT = 0x29;

        public const int VK_PRINT = 0x2A;

        public const int VK_EXECUTE = 0x2B;

        public const int VK_SNAPSHOT = 0x2C;

        public const int VK_INSERT = 0x2D;

        public const int VK_DELETE = 0x2E;

        public const int VK_HELP = 0x2F;

        public const int VK_LWIN = 0x5B;

        public const int VK_RWIN = 0x5C;

        public const int VK_APPS = 0x5D;

        public const int VK_SLEEP = 0x5F;

        public const int VK_NUMPAD0 = 0x60;

        public const int VK_NUMPAD1 = 0x61;

        public const int VK_NUMPAD2 = 0x62;

        public const int VK_NUMPAD3 = 0x63;

        public const int VK_NUMPAD4 = 0x64;

        public const int VK_NUMPAD5 = 0x65;

        public const int VK_NUMPAD6 = 0x66;

        public const int VK_NUMPAD7 = 0x67;

        public const int VK_NUMPAD8 = 0x68;

        public const int VK_NUMPAD9 = 0x69;

        public const int VK_MULTIPLY = 0x6A;

        public const int VK_ADD = 0x6B;

        public const int VK_SEPARATOR = 0x6C;

        public const int VK_SUBTRACT = 0x6D;

        public const int VK_DECIMAL = 0x6E;

        public const int VK_DIVIDE = 0x6F;

        public const int VK_F1 = 0x70;

        public const int VK_F2 = 0x71;

        public const int VK_F3 = 0x72;

        public const int VK_F4 = 0x73;

        public const int VK_F5 = 0x74;

        public const int VK_F6 = 0x75;

        public const int VK_F7 = 0x76;

        public const int VK_F8 = 0x77;

        public const int VK_F9 = 0x78;

        public const int VK_F10 = 0x79;

        public const int VK_F11 = 0x7A;

        public const int VK_F12 = 0x7B;

        public const int VK_F13 = 0x7C;

        public const int VK_F14 = 0x7D;

        public const int VK_F15 = 0x7E;

        public const int VK_F16 = 0x7F;

        public const int VK_F17 = 0x80;

        public const int VK_F18 = 0x81;

        public const int VK_F19 = 0x82;

        public const int VK_F20 = 0x83;

        public const int VK_F21 = 0x84;

        public const int VK_F22 = 0x85;

        public const int VK_F23 = 0x86;

        public const int VK_F24 = 0x87;

        public const int VK_NAVIGATION_VIEW = 0x88;

        public const int VK_NAVIGATION_MENU = 0x89;

        public const int VK_NAVIGATION_UP = 0x8A;

        public const int VK_NAVIGATION_DOWN = 0x8B;

        public const int VK_NAVIGATION_LEFT = 0x8C;

        public const int VK_NAVIGATION_RIGHT = 0x8D;

        public const int VK_NAVIGATION_ACCEPT = 0x8E;

        public const int VK_NAVIGATION_CANCEL = 0x8F;

        public const int VK_NUMLOCK = 0x90;

        public const int VK_SCROLL = 0x91;

        public const int VK_OEM_NEC_EQUAL = 0x92;

        public const int VK_OEM_FJ_JISHO = 0x92;

        public const int VK_OEM_FJ_MASSHOU = 0x93;

        public const int VK_OEM_FJ_TOUROKU = 0x94;

        public const int VK_OEM_FJ_LOYA = 0x95;

        public const int VK_OEM_FJ_ROYA = 0x96;

        public const int VK_LSHIFT = 0xA0;

        public const int VK_RSHIFT = 0xA1;

        public const int VK_LCONTROL = 0xA2;

        public const int VK_RCONTROL = 0xA3;

        public const int VK_LMENU = 0xA4;

        public const int VK_RMENU = 0xA5;

        public const int VK_BROWSER_BACK = 0xA6;

        public const int VK_BROWSER_FORWARD = 0xA7;

        public const int VK_BROWSER_REFRESH = 0xA8;

        public const int VK_BROWSER_STOP = 0xA9;

        public const int VK_BROWSER_SEARCH = 0xAA;

        public const int VK_BROWSER_FAVORITES = 0xAB;

        public const int VK_BROWSER_HOME = 0xAC;

        public const int VK_VOLUME_MUTE = 0xAD;

        public const int VK_VOLUME_DOWN = 0xAE;

        public const int VK_VOLUME_UP = 0xAF;

        public const int VK_MEDIA_NEXT_TRACK = 0xB0;

        public const int VK_MEDIA_PREV_TRACK = 0xB1;

        public const int VK_MEDIA_STOP = 0xB2;

        public const int VK_MEDIA_PLAY_PAUSE = 0xB3;

        public const int VK_LAUNCH_MAIL = 0xB4;

        public const int VK_LAUNCH_MEDIA_SELECT = 0xB5;

        public const int VK_LAUNCH_APP1 = 0xB6;

        public const int VK_LAUNCH_APP2 = 0xB7;

        public const int VK_OEM_1 = 0xBA;

        public const int VK_OEM_PLUS = 0xBB;

        public const int VK_OEM_COMMA = 0xBC;

        public const int VK_OEM_MINUS = 0xBD;

        public const int VK_OEM_PERIOD = 0xBE;

        public const int VK_OEM_2 = 0xBF;

        public const int VK_OEM_3 = 0xC0;

        public const int VK_GAMEPAD_A = 0xC3;

        public const int VK_GAMEPAD_B = 0xC4;

        public const int VK_GAMEPAD_X = 0xC5;

        public const int VK_GAMEPAD_Y = 0xC6;

        public const int VK_GAMEPAD_RIGHT_SHOULDER = 0xC7;

        public const int VK_GAMEPAD_LEFT_SHOULDER = 0xC8;

        public const int VK_GAMEPAD_LEFT_TRIGGER = 0xC9;

        public const int VK_GAMEPAD_RIGHT_TRIGGER = 0xCA;

        public const int VK_GAMEPAD_DPAD_UP = 0xCB;

        public const int VK_GAMEPAD_DPAD_DOWN = 0xCC;

        public const int VK_GAMEPAD_DPAD_LEFT = 0xCD;

        public const int VK_GAMEPAD_DPAD_RIGHT = 0xCE;

        public const int VK_GAMEPAD_MENU = 0xCF;

        public const int VK_GAMEPAD_VIEW = 0xD0;

        public const int VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON = 0xD1;

        public const int VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON = 0xD2;

        public const int VK_GAMEPAD_LEFT_THUMBSTICK_UP = 0xD3;

        public const int VK_GAMEPAD_LEFT_THUMBSTICK_DOWN = 0xD4;

        public const int VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT = 0xD5;

        public const int VK_GAMEPAD_LEFT_THUMBSTICK_LEFT = 0xD6;

        public const int VK_GAMEPAD_RIGHT_THUMBSTICK_UP = 0xD7;

        public const int VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN = 0xD8;

        public const int VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT = 0xD9;

        public const int VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT = 0xDA;

        public const int VK_OEM_4 = 0xDB;

        public const int VK_OEM_5 = 0xDC;

        public const int VK_OEM_6 = 0xDD;

        public const int VK_OEM_7 = 0xDE;

        public const int VK_OEM_8 = 0xDF;

        public const int VK_OEM_AX = 0xE1;

        public const int VK_OEM_102 = 0xE2;

        public const int VK_ICO_HELP = 0xE3;

        public const int VK_ICO_00 = 0xE4;

        public const int VK_PROCESSKEY = 0xE5;

        public const int VK_ICO_CLEAR = 0xE6;

        public const int VK_PACKET = 0xE7;

        public const int VK_OEM_RESET = 0xE9;

        public const int VK_OEM_JUMP = 0xEA;

        public const int VK_OEM_PA1 = 0xEB;

        public const int VK_OEM_PA2 = 0xEC;

        public const int VK_OEM_PA3 = 0xED;

        public const int VK_OEM_WSCTRL = 0xEE;

        public const int VK_OEM_CUSEL = 0xEF;

        public const int VK_OEM_ATTN = 0xF0;

        public const int VK_OEM_FINISH = 0xF1;

        public const int VK_OEM_COPY = 0xF2;

        public const int VK_OEM_AUTO = 0xF3;

        public const int VK_OEM_ENLW = 0xF4;

        public const int VK_OEM_BACKTAB = 0xF5;

        public const int VK_ATTN = 0xF6;

        public const int VK_CRSEL = 0xF7;

        public const int VK_EXSEL = 0xF8;

        public const int VK_EREOF = 0xF9;

        public const int VK_PLAY = 0xFA;

        public const int VK_ZOOM = 0xFB;

        public const int VK_NONAME = 0xFC;

        public const int VK_PA1 = 0xFD;

        public const int VK_OEM_CLEAR = 0xFE;

        public const int WH_MIN = -1;

        public const int WH_MSGFILTER = -1;

        public const int WH_JOURNALRECORD = 0;

        public const int WH_JOURNALPLAYBACK = 1;

        public const int WH_KEYBOARD = 2;

        public const int WH_GETMESSAGE = 3;

        public const int WH_CALLWNDPROC = 4;

        public const int WH_CBT = 5;

        public const int WH_SYSMSGFILTER = 6;

        public const int WH_MOUSE = 7;

        public const int WH_HARDWARE = 8;

        public const int WH_DEBUG = 9;

        public const int WH_SHELL = 10;

        public const int WH_FOREGROUNDIDLE = 11;

        public const int WH_CALLWNDPROCRET = 12;

        public const int WH_KEYBOARD_LL = 13;

        public const int WH_MOUSE_LL = 14;

        public const int WH_MAX = 14;

        public const int WH_MINHOOK = WH_MIN;

        public const int WH_MAXHOOK = WH_MAX;

        public const int HC_ACTION = 0;

        public const int HC_GETNEXT = 1;

        public const int HC_SKIP = 2;

        public const int HC_NOREMOVE = 3;

        public const int HC_NOREM = HC_NOREMOVE;

        public const int HC_SYSMODALON = 4;

        public const int HC_SYSMODALOFF = 5;

        public const int HCBT_MOVESIZE = 0;

        public const int HCBT_MINMAX = 1;

        public const int HCBT_QS = 2;

        public const int HCBT_CREATEWND = 3;

        public const int HCBT_DESTROYWND = 4;

        public const int HCBT_ACTIVATE = 5;

        public const int HCBT_CLICKSKIPPED = 6;

        public const int HCBT_KEYSKIPPED = 7;

        public const int HCBT_SYSCOMMAND = 8;

        public const int HCBT_SETFOCUS = 9;

        public const int WTS_CONSOLE_CONNECT = 0x1;

        public const int WTS_CONSOLE_DISCONNECT = 0x2;

        public const int WTS_REMOTE_CONNECT = 0x3;

        public const int WTS_REMOTE_DISCONNECT = 0x4;

        public const int WTS_SESSION_LOGON = 0x5;

        public const int WTS_SESSION_LOGOFF = 0x6;

        public const int WTS_SESSION_LOCK = 0x7;

        public const int WTS_SESSION_UNLOCK = 0x8;

        public const int WTS_SESSION_REMOTE_CONTROL = 0x9;

        public const int WTS_SESSION_CREATE = 0xA;

        public const int WTS_SESSION_TERMINATE = 0xB;

        public const int MSGF_DIALOGBOX = 0;

        public const int MSGF_MESSAGEBOX = 1;

        public const int MSGF_MENU = 2;

        public const int MSGF_SCROLLBAR = 5;

        public const int MSGF_NEXTWINDOW = 6;

        public const int MSGF_MAX = 8;

        public const int MSGF_USER = 4096;

        public const int HSHELL_WINDOWCREATED = 1;

        public const int HSHELL_WINDOWDESTROYED = 2;

        public const int HSHELL_ACTIVATESHELLWINDOW = 3;

        public const int HSHELL_WINDOWACTIVATED = 4;

        public const int HSHELL_GETMINRECT = 5;

        public const int HSHELL_REDRAW = 6;

        public const int HSHELL_TASKMAN = 7;

        public const int HSHELL_LANGUAGE = 8;

        public const int HSHELL_SYSMENU = 9;

        public const int HSHELL_ENDTASK = 10;

        public const int HSHELL_ACCESSIBILITYSTATE = 11;

        public const int HSHELL_APPCOMMAND = 12;

        public const int HSHELL_WINDOWREPLACED = 13;

        public const int HSHELL_WINDOWREPLACING = 14;

        public const int HSHELL_MONITORCHANGED = 16;

        public const int HSHELL_HIGHBIT = 0x8000;

        public const int HSHELL_FLASH = HSHELL_REDRAW | HSHELL_HIGHBIT;

        public const int HSHELL_RUDEAPPACTIVATED = HSHELL_WINDOWACTIVATED | HSHELL_HIGHBIT;

        public const int APPCOMMAND_BROWSER_BACKWARD = 1;

        public const int APPCOMMAND_BROWSER_FORWARD = 2;

        public const int APPCOMMAND_BROWSER_REFRESH = 3;

        public const int APPCOMMAND_BROWSER_STOP = 4;

        public const int APPCOMMAND_BROWSER_SEARCH = 5;

        public const int APPCOMMAND_BROWSER_FAVORITES = 6;

        public const int APPCOMMAND_BROWSER_HOME = 7;

        public const int APPCOMMAND_VOLUME_MUTE = 8;

        public const int APPCOMMAND_VOLUME_DOWN = 9;

        public const int APPCOMMAND_VOLUME_UP = 10;

        public const int APPCOMMAND_MEDIA_NEXTTRACK = 11;

        public const int APPCOMMAND_MEDIA_PREVIOUSTRACK = 12;

        public const int APPCOMMAND_MEDIA_STOP = 13;

        public const int APPCOMMAND_MEDIA_PLAY_PAUSE = 14;

        public const int APPCOMMAND_LAUNCH_MAIL = 15;

        public const int APPCOMMAND_LAUNCH_MEDIA_SELECT = 16;

        public const int APPCOMMAND_LAUNCH_APP1 = 17;

        public const int APPCOMMAND_LAUNCH_APP2 = 18;

        public const int APPCOMMAND_BASS_DOWN = 19;

        public const int APPCOMMAND_BASS_BOOST = 20;

        public const int APPCOMMAND_BASS_UP = 21;

        public const int APPCOMMAND_TREBLE_DOWN = 22;

        public const int APPCOMMAND_TREBLE_UP = 23;

        public const int APPCOMMAND_MICROPHONE_VOLUME_MUTE = 24;

        public const int APPCOMMAND_MICROPHONE_VOLUME_DOWN = 25;

        public const int APPCOMMAND_MICROPHONE_VOLUME_UP = 26;

        public const int APPCOMMAND_HELP = 27;

        public const int APPCOMMAND_FIND = 28;

        public const int APPCOMMAND_NEW = 29;

        public const int APPCOMMAND_OPEN = 30;

        public const int APPCOMMAND_CLOSE = 31;

        public const int APPCOMMAND_SAVE = 32;

        public const int APPCOMMAND_PRINT = 33;

        public const int APPCOMMAND_UNDO = 34;

        public const int APPCOMMAND_REDO = 35;

        public const int APPCOMMAND_COPY = 36;

        public const int APPCOMMAND_CUT = 37;

        public const int APPCOMMAND_PASTE = 38;

        public const int APPCOMMAND_REPLY_TO_MAIL = 39;

        public const int APPCOMMAND_FORWARD_MAIL = 40;

        public const int APPCOMMAND_SEND_MAIL = 41;

        public const int APPCOMMAND_SPELL_CHECK = 42;

        public const int APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE = 43;

        public const int APPCOMMAND_MIC_ON_OFF_TOGGLE = 44;

        public const int APPCOMMAND_CORRECTION_LIST = 45;

        public const int APPCOMMAND_MEDIA_PLAY = 46;

        public const int APPCOMMAND_MEDIA_PAUSE = 47;

        public const int APPCOMMAND_MEDIA_RECORD = 48;

        public const int APPCOMMAND_MEDIA_FAST_FORWARD = 49;

        public const int APPCOMMAND_MEDIA_REWIND = 50;

        public const int APPCOMMAND_MEDIA_CHANNEL_UP = 51;

        public const int APPCOMMAND_MEDIA_CHANNEL_DOWN = 52;

        public const int APPCOMMAND_DELETE = 53;

        public const int APPCOMMAND_DWM_FLIP3D = 54;

        public const int FAPPCOMMAND_MOUSE = 0x8000;

        public const int FAPPCOMMAND_KEY = 0;

        public const int FAPPCOMMAND_OEM = 0x1000;

        public const int FAPPCOMMAND_MASK = 0xF000;

        public const int LLKHF_EXTENDED = KF_EXTENDED >> 8;

        public const int LLKHF_INJECTED = 0x00000010;

        public const int LLKHF_ALTDOWN = KF_ALTDOWN >> 8;

        public const int LLKHF_UP = KF_UP >> 8;

        public const int LLKHF_LOWER_IL_INJECTED = 0x00000002;

        public const int LLMHF_INJECTED = 0x00000001;

        public const int LLMHF_LOWER_IL_INJECTED = 0x00000002;

        public const int HKL_PREV = 0;

        public const int HKL_NEXT = 1;

        public const int KLF_ACTIVATE = 0x00000001;

        public const int KLF_SUBSTITUTE_OK = 0x00000002;

        public const int KLF_REORDER = 0x00000008;

        public const int KLF_REPLACELANG = 0x00000010;

        public const int KLF_NOTELLSHELL = 0x00000080;

        public const int KLF_SETFORPROCESS = 0x00000100;

        public const int KLF_SHIFTLOCK = 0x00010000;

        public const int KLF_RESET = 0x40000000;

        public const int INPUTLANGCHANGE_SYSCHARSET = 0x0001;

        public const int INPUTLANGCHANGE_FORWARD = 0x0002;

        public const int INPUTLANGCHANGE_BACKWARD = 0x0004;

        public const int KL_NAMELENGTH = 9;

        public const int GMMP_USE_DISPLAY_POINTS = 1;

        public const int GMMP_USE_HIGH_RESOLUTION_POINTS = 2;

        public const int DESKTOP_READOBJECTS = 0x0001;

        public const int DESKTOP_CREATEWINDOW = 0x0002;

        public const int DESKTOP_CREATEMENU = 0x0004;

        public const int DESKTOP_HOOKCONTROL = 0x0008;

        public const int DESKTOP_JOURNALRECORD = 0x0010;

        public const int DESKTOP_JOURNALPLAYBACK = 0x0020;

        public const int DESKTOP_ENUMERATE = 0x0040;

        public const int DESKTOP_WRITEOBJECTS = 0x0080;

        public const int DESKTOP_SWITCHDESKTOP = 0x0100;

        public const int DF_ALLOWOTHERACCOUNTHOOK = 0x0001;

        public const int WINSTA_ENUMDESKTOPS = 0x0001;

        public const int WINSTA_READATTRIBUTES = 0x0002;

        public const int WINSTA_ACCESSCLIPBOARD = 0x0004;

        public const int WINSTA_CREATEDESKTOP = 0x0008;

        public const int WINSTA_WRITEATTRIBUTES = 0x0010;

        public const int WINSTA_ACCESSGLOBALATOMS = 0x0020;

        public const int WINSTA_EXITWINDOWS = 0x0040;

        public const int WINSTA_ENUMERATE = 0x0100;

        public const int WINSTA_READSCREEN = 0x0200;

        public const int WINSTA_ALL_ACCESS = WINSTA_ENUMDESKTOPS | WINSTA_READATTRIBUTES | WINSTA_ACCESSCLIPBOARD | WINSTA_CREATEDESKTOP | WINSTA_WRITEATTRIBUTES | WINSTA_ACCESSGLOBALATOMS | WINSTA_EXITWINDOWS | WINSTA_ENUMERATE | WINSTA_READSCREEN;

        public const int CWF_CREATE_ONLY = 0x00000001;

        public const int WSF_VISIBLE = 0x0001;

        public const int UOI_FLAGS = 1;

        public const int UOI_NAME = 2;

        public const int UOI_TYPE = 3;

        public const int UOI_USER_SID = 4;

        public const int UOI_HEAPSIZE = 5;

        public const int UOI_IO = 6;

        public const int UOI_TIMERPROC_EXCEPTION_SUPPRESSION = 7;

        public const int GWL_WNDPROC = -4;

        public const int GWL_HINSTANCE = -6;

        public const int GWL_HWNDPARENT = -8;

        public const int GWL_STYLE = -16;

        public const int GWL_EXSTYLE = -20;

        public const int GWL_USERDATA = -21;

        public const int GWL_ID = -12;

        public const int GWLP_WNDPROC = -4;

        public const int GWLP_HINSTANCE = -6;

        public const int GWLP_HWNDPARENT = -8;

        public const int GWLP_USERDATA = -21;

        public const int GWLP_ID = -12;

        public const int GCL_MENUNAME = -8;

        public const int GCL_HBRBACKGROUND = -10;

        public const int GCL_HCURSOR = -12;

        public const int GCL_HICON = -14;

        public const int GCL_HMODULE = -16;

        public const int GCL_CBWNDEXTRA = -18;

        public const int GCL_CBCLSEXTRA = -20;

        public const int GCL_WNDPROC = -24;

        public const int GCL_STYLE = -26;

        public const int GCW_ATOM = -32;

        public const int GCL_HICONSM = -34;

        public const int GCLP_MENUNAME = -8;

        public const int GCLP_HBRBACKGROUND = -10;

        public const int GCLP_HCURSOR = -12;

        public const int GCLP_HICON = -14;

        public const int GCLP_HMODULE = -16;

        public const int GCLP_WNDPROC = -24;

        public const int GCLP_HICONSM = -34;

        public const int WM_NULL = 0x0000;

        public const int WM_CREATE = 0x0001;

        public const int WM_DESTROY = 0x0002;

        public const int WM_MOVE = 0x0003;

        public const int WM_SIZE = 0x0005;

        public const int WM_ACTIVATE = 0x0006;

        public const int WA_INACTIVE = 0;

        public const int WA_ACTIVE = 1;

        public const int WA_CLICKACTIVE = 2;

        public const int WM_SETFOCUS = 0x0007;

        public const int WM_KILLFOCUS = 0x0008;

        public const int WM_ENABLE = 0x000A;

        public const int WM_SETREDRAW = 0x000B;

        public const int WM_SETTEXT = 0x000C;

        public const int WM_GETTEXT = 0x000D;

        public const int WM_GETTEXTLENGTH = 0x000E;

        public const int WM_PAINT = 0x000F;

        public const int WM_CLOSE = 0x0010;

        public const int WM_QUERYENDSESSION = 0x0011;

        public const int WM_QUERYOPEN = 0x0013;

        public const int WM_ENDSESSION = 0x0016;

        public const int WM_QUIT = 0x0012;

        public const int WM_ERASEBKGND = 0x0014;

        public const int WM_SYSCOLORCHANGE = 0x0015;

        public const int WM_SHOWWINDOW = 0x0018;

        public const int WM_WININICHANGE = 0x001A;

        public const int WM_SETTINGCHANGE = WM_WININICHANGE;

        public const int WM_DEVMODECHANGE = 0x001B;

        public const int WM_ACTIVATEAPP = 0x001C;

        public const int WM_FONTCHANGE = 0x001D;

        public const int WM_TIMECHANGE = 0x001E;

        public const int WM_CANCELMODE = 0x001F;

        public const int WM_SETCURSOR = 0x0020;

        public const int WM_MOUSEACTIVATE = 0x0021;

        public const int WM_CHILDACTIVATE = 0x0022;

        public const int WM_QUEUESYNC = 0x0023;

        public const int WM_GETMINMAXINFO = 0x0024;

        public const int WM_PAINTICON = 0x0026;

        public const int WM_ICONERASEBKGND = 0x0027;

        public const int WM_NEXTDLGCTL = 0x0028;

        public const int WM_SPOOLERSTATUS = 0x002A;

        public const int WM_DRAWITEM = 0x002B;

        public const int WM_MEASUREITEM = 0x002C;

        public const int WM_DELETEITEM = 0x002D;

        public const int WM_VKEYTOITEM = 0x002E;

        public const int WM_CHARTOITEM = 0x002F;

        public const int WM_SETFONT = 0x0030;

        public const int WM_GETFONT = 0x0031;

        public const int WM_SETHOTKEY = 0x0032;

        public const int WM_GETHOTKEY = 0x0033;

        public const int WM_QUERYDRAGICON = 0x0037;

        public const int WM_COMPAREITEM = 0x0039;

        public const int WM_GETOBJECT = 0x003D;

        public const int WM_COMPACTING = 0x0041;

        public const int WM_COMMNOTIFY = 0x0044;

        public const int WM_WINDOWPOSCHANGING = 0x0046;

        public const int WM_WINDOWPOSCHANGED = 0x0047;

        public const int WM_POWER = 0x0048;

        public const int PWR_OK = 1;

        public const int PWR_FAIL = -1;

        public const int PWR_SUSPENDREQUEST = 1;

        public const int PWR_SUSPENDRESUME = 2;

        public const int PWR_CRITICALRESUME = 3;

        public const int WM_COPYDATA = 0x004A;

        public const int WM_CANCELJOURNAL = 0x004B;

        public const int WM_NOTIFY = 0x004E;

        public const int WM_INPUTLANGCHANGEREQUEST = 0x0050;

        public const int WM_INPUTLANGCHANGE = 0x0051;

        public const int WM_TCARD = 0x0052;

        public const int WM_HELP = 0x0053;

        public const int WM_USERCHANGED = 0x0054;

        public const int WM_NOTIFYFORMAT = 0x0055;

        public const int NFR_ANSI = 1;

        public const int NFR_UNICODE = 2;

        public const int NF_QUERY = 3;

        public const int NF_REQUERY = 4;

        public const int WM_CONTEXTMENU = 0x007B;

        public const int WM_STYLECHANGING = 0x007C;

        public const int WM_STYLECHANGED = 0x007D;

        public const int WM_DISPLAYCHANGE = 0x007E;

        public const int WM_GETICON = 0x007F;

        public const int WM_SETICON = 0x0080;

        public const int WM_NCCREATE = 0x0081;

        public const int WM_NCDESTROY = 0x0082;

        public const int WM_NCCALCSIZE = 0x0083;

        public const int WM_NCHITTEST = 0x0084;

        public const int WM_NCPAINT = 0x0085;

        public const int WM_NCACTIVATE = 0x0086;

        public const int WM_GETDLGCODE = 0x0087;

        public const int WM_SYNCPAINT = 0x0088;

        public const int WM_NCMOUSEMOVE = 0x00A0;

        public const int WM_NCLBUTTONDOWN = 0x00A1;

        public const int WM_NCLBUTTONUP = 0x00A2;

        public const int WM_NCLBUTTONDBLCLK = 0x00A3;

        public const int WM_NCRBUTTONDOWN = 0x00A4;

        public const int WM_NCRBUTTONUP = 0x00A5;

        public const int WM_NCRBUTTONDBLCLK = 0x00A6;

        public const int WM_NCMBUTTONDOWN = 0x00A7;

        public const int WM_NCMBUTTONUP = 0x00A8;

        public const int WM_NCMBUTTONDBLCLK = 0x00A9;

        public const int WM_NCXBUTTONDOWN = 0x00AB;

        public const int WM_NCXBUTTONUP = 0x00AC;

        public const int WM_NCXBUTTONDBLCLK = 0x00AD;

        public const int WM_INPUT_DEVICE_CHANGE = 0x00FE;

        public const int WM_INPUT = 0x00FF;

        public const int WM_KEYFIRST = 0x0100;

        public const int WM_KEYDOWN = 0x0100;

        public const int WM_KEYUP = 0x0101;

        public const int WM_CHAR = 0x0102;

        public const int WM_DEADCHAR = 0x0103;

        public const int WM_SYSKEYDOWN = 0x0104;

        public const int WM_SYSKEYUP = 0x0105;

        public const int WM_SYSCHAR = 0x0106;

        public const int WM_SYSDEADCHAR = 0x0107;

        public const int WM_UNICHAR = 0x0109;

        public const int WM_KEYLAST = 0x0109;

        public const int UNICODE_NOCHAR = 0xFFFF;

        public const int WM_IME_STARTCOMPOSITION = 0x010D;

        public const int WM_IME_ENDCOMPOSITION = 0x010E;

        public const int WM_IME_COMPOSITION = 0x010F;

        public const int WM_IME_KEYLAST = 0x010F;

        public const int WM_INITDIALOG = 0x0110;

        public const int WM_COMMAND = 0x0111;

        public const int WM_SYSCOMMAND = 0x0112;

        public const int WM_TIMER = 0x0113;

        public const int WM_HSCROLL = 0x0114;

        public const int WM_VSCROLL = 0x0115;

        public const int WM_INITMENU = 0x0116;

        public const int WM_INITMENUPOPUP = 0x0117;

        public const int WM_GESTURE = 0x0119;

        public const int WM_GESTURENOTIFY = 0x011A;

        public const int WM_MENUSELECT = 0x011F;

        public const int WM_MENUCHAR = 0x0120;

        public const int WM_ENTERIDLE = 0x0121;

        public const int WM_MENURBUTTONUP = 0x0122;

        public const int WM_MENUDRAG = 0x0123;

        public const int WM_MENUGETOBJECT = 0x0124;

        public const int WM_UNINITMENUPOPUP = 0x0125;

        public const int WM_MENUCOMMAND = 0x0126;

        public const int WM_CHANGEUISTATE = 0x0127;

        public const int WM_UPDATEUISTATE = 0x0128;

        public const int WM_QUERYUISTATE = 0x0129;

        public const int UIS_SET = 1;

        public const int UIS_CLEAR = 2;

        public const int UIS_INITIALIZE = 3;

        public const int UISF_HIDEFOCUS = 0x1;

        public const int UISF_HIDEACCEL = 0x2;

        public const int UISF_ACTIVE = 0x4;

        public const int WM_CTLCOLORMSGBOX = 0x0132;

        public const int WM_CTLCOLOREDIT = 0x0133;

        public const int WM_CTLCOLORLISTBOX = 0x0134;

        public const int WM_CTLCOLORBTN = 0x0135;

        public const int WM_CTLCOLORDLG = 0x0136;

        public const int WM_CTLCOLORSCROLLBAR = 0x0137;

        public const int WM_CTLCOLORSTATIC = 0x0138;

        public const int MN_GETHMENU = 0x01E1;

        public const int WM_MOUSEFIRST = 0x0200;

        public const int WM_MOUSEMOVE = 0x0200;

        public const int WM_LBUTTONDOWN = 0x0201;

        public const int WM_LBUTTONUP = 0x0202;

        public const int WM_LBUTTONDBLCLK = 0x0203;

        public const int WM_RBUTTONDOWN = 0x0204;

        public const int WM_RBUTTONUP = 0x0205;

        public const int WM_RBUTTONDBLCLK = 0x0206;

        public const int WM_MBUTTONDOWN = 0x0207;

        public const int WM_MBUTTONUP = 0x0208;

        public const int WM_MBUTTONDBLCLK = 0x0209;

        public const int WM_MOUSEWHEEL = 0x020A;

        public const int WM_XBUTTONDOWN = 0x020B;

        public const int WM_XBUTTONUP = 0x020C;

        public const int WM_XBUTTONDBLCLK = 0x020D;

        public const int WM_MOUSEHWHEEL = 0x020E;

        public const int WM_MOUSELAST = 0x020E;

        public const int WHEEL_DELTA = 120;

        public const uint WHEEL_PAGESCROLL = uint.MaxValue;

        public const int XBUTTON1 = 0x0001;

        public const int XBUTTON2 = 0x0002;

        public const int WM_PARENTNOTIFY = 0x0210;

        public const int WM_ENTERMENULOOP = 0x0211;

        public const int WM_EXITMENULOOP = 0x0212;

        public const int WM_NEXTMENU = 0x0213;

        public const int WM_SIZING = 0x0214;

        public const int WM_CAPTURECHANGED = 0x0215;

        public const int WM_MOVING = 0x0216;

        public const int WM_POWERBROADCAST = 0x0218;

        public const int PBT_APMQUERYSUSPEND = 0x0000;

        public const int PBT_APMQUERYSTANDBY = 0x0001;

        public const int PBT_APMQUERYSUSPENDFAILED = 0x0002;

        public const int PBT_APMQUERYSTANDBYFAILED = 0x0003;

        public const int PBT_APMSUSPEND = 0x0004;

        public const int PBT_APMSTANDBY = 0x0005;

        public const int PBT_APMRESUMECRITICAL = 0x0006;

        public const int PBT_APMRESUMESUSPEND = 0x0007;

        public const int PBT_APMRESUMESTANDBY = 0x0008;

        public const int PBTF_APMRESUMEFROMFAILURE = 0x00000001;

        public const int PBT_APMBATTERYLOW = 0x0009;

        public const int PBT_APMPOWERSTATUSCHANGE = 0x000A;

        public const int PBT_APMOEMEVENT = 0x000B;

        public const int PBT_APMRESUMEAUTOMATIC = 0x0012;

        public const int PBT_POWERSETTINGCHANGE = 0x8013;

        public const int WM_DEVICECHANGE = 0x0219;

        public const int WM_MDICREATE = 0x0220;

        public const int WM_MDIDESTROY = 0x0221;

        public const int WM_MDIACTIVATE = 0x0222;

        public const int WM_MDIRESTORE = 0x0223;

        public const int WM_MDINEXT = 0x0224;

        public const int WM_MDIMAXIMIZE = 0x0225;

        public const int WM_MDITILE = 0x0226;

        public const int WM_MDICASCADE = 0x0227;

        public const int WM_MDIICONARRANGE = 0x0228;

        public const int WM_MDIGETACTIVE = 0x0229;

        public const int WM_MDISETMENU = 0x0230;

        public const int WM_ENTERSIZEMOVE = 0x0231;

        public const int WM_EXITSIZEMOVE = 0x0232;

        public const int WM_DROPFILES = 0x0233;

        public const int WM_MDIREFRESHMENU = 0x0234;

        public const int WM_POINTERDEVICECHANGE = 0x238;

        public const int WM_POINTERDEVICEINRANGE = 0x239;

        public const int WM_POINTERDEVICEOUTOFRANGE = 0x23A;

        public const int WM_TOUCH = 0x0240;

        public const int WM_NCPOINTERUPDATE = 0x0241;

        public const int WM_NCPOINTERDOWN = 0x0242;

        public const int WM_NCPOINTERUP = 0x0243;

        public const int WM_POINTERUPDATE = 0x0245;

        public const int WM_POINTERDOWN = 0x0246;

        public const int WM_POINTERUP = 0x0247;

        public const int WM_POINTERENTER = 0x0249;

        public const int WM_POINTERLEAVE = 0x024A;

        public const int WM_POINTERACTIVATE = 0x024B;

        public const int WM_POINTERCAPTURECHANGED = 0x024C;

        public const int WM_TOUCHHITTESTING = 0x024D;

        public const int WM_POINTERWHEEL = 0x024E;

        public const int WM_POINTERHWHEEL = 0x024F;

        public const int DM_POINTERHITTEST = 0x0250;

        public const int WM_POINTERROUTEDTO = 0x0251;

        public const int WM_POINTERROUTEDAWAY = 0x0252;

        public const int WM_POINTERROUTEDRELEASED = 0x0253;

        public const int WM_IME_SETCONTEXT = 0x0281;

        public const int WM_IME_NOTIFY = 0x0282;

        public const int WM_IME_CONTROL = 0x0283;

        public const int WM_IME_COMPOSITIONFULL = 0x0284;

        public const int WM_IME_SELECT = 0x0285;

        public const int WM_IME_CHAR = 0x0286;

        public const int WM_IME_REQUEST = 0x0288;

        public const int WM_IME_KEYDOWN = 0x0290;

        public const int WM_IME_KEYUP = 0x0291;

        public const int WM_MOUSEHOVER = 0x02A1;

        public const int WM_MOUSELEAVE = 0x02A3;

        public const int WM_NCMOUSEHOVER = 0x02A0;

        public const int WM_NCMOUSELEAVE = 0x02A2;

        public const int WM_WTSSESSION_CHANGE = 0x02B1;

        public const int WM_TABLET_FIRST = 0x02c0;

        public const int WM_TABLET_LAST = 0x02df;

        public const int WM_DPICHANGED = 0x02E0;

        public const int WM_DPICHANGED_BEFOREPARENT = 0x02E2;

        public const int WM_DPICHANGED_AFTERPARENT = 0x02E3;

        public const int WM_GETDPISCALEDSIZE = 0x02E4;

        public const int WM_CUT = 0x0300;

        public const int WM_COPY = 0x0301;

        public const int WM_PASTE = 0x0302;

        public const int WM_CLEAR = 0x0303;

        public const int WM_UNDO = 0x0304;

        public const int WM_RENDERFORMAT = 0x0305;

        public const int WM_RENDERALLFORMATS = 0x0306;

        public const int WM_DESTROYCLIPBOARD = 0x0307;

        public const int WM_DRAWCLIPBOARD = 0x0308;

        public const int WM_PAINTCLIPBOARD = 0x0309;

        public const int WM_VSCROLLCLIPBOARD = 0x030A;

        public const int WM_SIZECLIPBOARD = 0x030B;

        public const int WM_ASKCBFORMATNAME = 0x030C;

        public const int WM_CHANGECBCHAIN = 0x030D;

        public const int WM_HSCROLLCLIPBOARD = 0x030E;

        public const int WM_QUERYNEWPALETTE = 0x030F;

        public const int WM_PALETTEISCHANGING = 0x0310;

        public const int WM_PALETTECHANGED = 0x0311;

        public const int WM_HOTKEY = 0x0312;

        public const int WM_PRINT = 0x0317;

        public const int WM_PRINTCLIENT = 0x0318;

        public const int WM_APPCOMMAND = 0x0319;

        public const int WM_THEMECHANGED = 0x031A;

        public const int WM_CLIPBOARDUPDATE = 0x031D;

        public const int WM_DWMCOMPOSITIONCHANGED = 0x031E;

        public const int WM_DWMNCRENDERINGCHANGED = 0x031F;

        public const int WM_DWMCOLORIZATIONCOLORCHANGED = 0x0320;

        public const int WM_DWMWINDOWMAXIMIZEDCHANGE = 0x0321;

        public const int WM_DWMSENDICONICTHUMBNAIL = 0x0323;

        public const int WM_DWMSENDICONICLIVEPREVIEWBITMAP = 0x0326;

        public const int WM_GETTITLEBARINFOEX = 0x033F;

        public const int WM_HANDHELDFIRST = 0x0358;

        public const int WM_HANDHELDLAST = 0x035F;

        public const int WM_AFXFIRST = 0x0360;

        public const int WM_AFXLAST = 0x037F;

        public const int WM_PENWINFIRST = 0x0380;

        public const int WM_PENWINLAST = 0x038F;

        public const int WM_APP = 0x8000;

        public const int WM_USER = 0x0400;

        public const int WMSZ_LEFT = 1;

        public const int WMSZ_RIGHT = 2;

        public const int WMSZ_TOP = 3;

        public const int WMSZ_TOPLEFT = 4;

        public const int WMSZ_TOPRIGHT = 5;

        public const int WMSZ_BOTTOM = 6;

        public const int WMSZ_BOTTOMLEFT = 7;

        public const int WMSZ_BOTTOMRIGHT = 8;

        public const int HTERROR = -2;

        public const int HTTRANSPARENT = -1;

        public const int HTNOWHERE = 0;

        public const int HTCLIENT = 1;

        public const int HTCAPTION = 2;

        public const int HTSYSMENU = 3;

        public const int HTGROWBOX = 4;

        public const int HTSIZE = HTGROWBOX;

        public const int HTMENU = 5;

        public const int HTHSCROLL = 6;

        public const int HTVSCROLL = 7;

        public const int HTMINBUTTON = 8;

        public const int HTMAXBUTTON = 9;

        public const int HTLEFT = 10;

        public const int HTRIGHT = 11;

        public const int HTTOP = 12;

        public const int HTTOPLEFT = 13;

        public const int HTTOPRIGHT = 14;

        public const int HTBOTTOM = 15;

        public const int HTBOTTOMLEFT = 16;

        public const int HTBOTTOMRIGHT = 17;

        public const int HTBORDER = 18;

        public const int HTREDUCE = HTMINBUTTON;

        public const int HTZOOM = HTMAXBUTTON;

        public const int HTSIZEFIRST = HTLEFT;

        public const int HTSIZELAST = HTBOTTOMRIGHT;

        public const int HTOBJECT = 19;

        public const int HTCLOSE = 20;

        public const int HTHELP = 21;

        public const int SMTO_NORMAL = 0x0000;

        public const int SMTO_BLOCK = 0x0001;

        public const int SMTO_ABORTIFHUNG = 0x0002;

        public const int SMTO_NOTIMEOUTIFNOTHUNG = 0x0008;

        public const int SMTO_ERRORONEXIT = 0x0020;

        public const int MA_ACTIVATE = 1;

        public const int MA_ACTIVATEANDEAT = 2;

        public const int MA_NOACTIVATE = 3;

        public const int MA_NOACTIVATEANDEAT = 4;

        public const int ICON_SMALL = 0;

        public const int ICON_BIG = 1;

        public const int ICON_SMALL2 = 2;

        public const int SIZE_RESTORED = 0;

        public const int SIZE_MINIMIZED = 1;

        public const int SIZE_MAXIMIZED = 2;

        public const int SIZE_MAXSHOW = 3;

        public const int SIZE_MAXHIDE = 4;

        public const int SIZENORMAL = SIZE_RESTORED;

        public const int SIZEICONIC = SIZE_MINIMIZED;

        public const int SIZEFULLSCREEN = SIZE_MAXIMIZED;

        public const int SIZEZOOMSHOW = SIZE_MAXSHOW;

        public const int SIZEZOOMHIDE = SIZE_MAXHIDE;

        public const int WVR_ALIGNTOP = 0x0010;

        public const int WVR_ALIGNLEFT = 0x0020;

        public const int WVR_ALIGNBOTTOM = 0x0040;

        public const int WVR_ALIGNRIGHT = 0x0080;

        public const int WVR_HREDRAW = 0x0100;

        public const int WVR_VREDRAW = 0x0200;

        public const int WVR_REDRAW = WVR_HREDRAW | WVR_VREDRAW;

        public const int WVR_VALIDRECTS = 0x0400;

        public const int MK_LBUTTON = 0x0001;

        public const int MK_RBUTTON = 0x0002;

        public const int MK_SHIFT = 0x0004;

        public const int MK_CONTROL = 0x0008;

        public const int MK_MBUTTON = 0x0010;

        public const int MK_XBUTTON1 = 0x0020;

        public const int MK_XBUTTON2 = 0x0040;

        public const uint TME_HOVER = 0x00000001;

        public const uint TME_LEAVE = 0x00000002;

        public const uint TME_NONCLIENT = 0x00000010;

        public const uint TME_QUERY = 0x40000000;

        public const uint TME_CANCEL = 0x80000000;

        public const uint HOVER_DEFAULT = 0xFFFFFFFF;

        public const uint WS_OVERLAPPED = 0x00000000;

        public const uint WS_POPUP = 0x80000000;

        public const uint WS_CHILD = 0x40000000;

        public const uint WS_MINIMIZE = 0x20000000;

        public const uint WS_VISIBLE = 0x10000000;

        public const uint WS_DISABLED = 0x08000000;

        public const uint WS_CLIPSIBLINGS = 0x04000000;

        public const uint WS_CLIPCHILDREN = 0x02000000;

        public const uint WS_MAXIMIZE = 0x01000000;

        public const uint WS_CAPTION = 0x00C00000;

        public const uint WS_BORDER = 0x00800000;

        public const uint WS_DLGFRAME = 0x00400000;

        public const uint WS_VSCROLL = 0x00200000;

        public const uint WS_HSCROLL = 0x00100000;

        public const uint WS_SYSMENU = 0x00080000;

        public const uint WS_THICKFRAME = 0x00040000;

        public const uint WS_GROUP = 0x00020000;

        public const uint WS_TABSTOP = 0x00010000;

        public const uint WS_MINIMIZEBOX = 0x00020000;

        public const uint WS_MAXIMIZEBOX = 0x00010000;

        public const uint WS_TILED = WS_OVERLAPPED;

        public const uint WS_ICONIC = WS_MINIMIZE;

        public const uint WS_SIZEBOX = WS_THICKFRAME;

        public const uint WS_TILEDWINDOW = WS_OVERLAPPEDWINDOW;

        public const uint WS_OVERLAPPEDWINDOW = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

        public const uint WS_POPUPWINDOW = WS_POPUP | WS_BORDER | WS_SYSMENU;

        public const uint WS_CHILDWINDOW = WS_CHILD;

        public const int WS_EX_DLGMODALFRAME = 0x00000001;

        public const int WS_EX_NOPARENTNOTIFY = 0x00000004;

        public const int WS_EX_TOPMOST = 0x00000008;

        public const int WS_EX_ACCEPTFILES = 0x00000010;

        public const int WS_EX_TRANSPARENT = 0x00000020;

        public const int WS_EX_MDICHILD = 0x00000040;

        public const int WS_EX_TOOLWINDOW = 0x00000080;

        public const int WS_EX_WINDOWEDGE = 0x00000100;

        public const int WS_EX_CLIENTEDGE = 0x00000200;

        public const int WS_EX_CONTEXTHELP = 0x00000400;

        public const int WS_EX_RIGHT = 0x00001000;

        public const int WS_EX_LEFT = 0x00000000;

        public const int WS_EX_RTLREADING = 0x00002000;

        public const int WS_EX_LTRREADING = 0x00000000;

        public const int WS_EX_LEFTSCROLLBAR = 0x00004000;

        public const int WS_EX_RIGHTSCROLLBAR = 0x00000000;

        public const int WS_EX_CONTROLPARENT = 0x00010000;

        public const int WS_EX_STATICEDGE = 0x00020000;

        public const int WS_EX_APPWINDOW = 0x00040000;

        public const int WS_EX_OVERLAPPEDWINDOW = WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE;

        public const int WS_EX_PALETTEWINDOW = WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST;

        public const int WS_EX_NOINHERITLAYOUT = 0x00100000;

        public const int WS_EX_NOREDIRECTIONBITMAP = 0x00200000;

        public const int WS_EX_LAYOUTRTL = 0x00400000;

        public const int WS_EX_COMPOSITED = 0x02000000;

        public const int WS_EX_NOACTIVATE = 0x08000000;

        public const int CS_VREDRAW = 0x0001;

        public const int CS_HREDRAW = 0x0002;

        public const int CS_DBLCLKS = 0x0008;

        public const int CS_OWNDC = 0x0020;

        public const int CS_CLASSDC = 0x0040;

        public const int CS_PARENTDC = 0x0080;

        public const int CS_NOCLOSE = 0x0200;

        public const int CS_SAVEBITS = 0x0800;

        public const int CS_BYTEALIGNCLIENT = 0x1000;

        public const int CS_BYTEALIGNWINDOW = 0x2000;

        public const int CS_GLOBALCLASS = 0x4000;

        public const int CS_IME = 0x00010000;

        public const int CS_DROPSHADOW = 0x00020000;

        public const int PRF_CHECKVISIBLE = 0x00000001;

        public const int PRF_NONCLIENT = 0x00000002;

        public const int PRF_CLIENT = 0x00000004;

        public const int PRF_ERASEBKGND = 0x00000008;

        public const int PRF_CHILDREN = 0x00000010;

        public const int PRF_OWNED = 0x00000020;

        public const int BDR_RAISEDOUTER = 0x0001;

        public const int BDR_SUNKENOUTER = 0x0002;

        public const int BDR_RAISEDINNER = 0x0004;

        public const int BDR_SUNKENINNER = 0x0008;

        public const int BDR_OUTER = BDR_RAISEDOUTER | BDR_SUNKENOUTER;

        public const int BDR_INNER = BDR_RAISEDINNER | BDR_SUNKENINNER;

        public const int BDR_RAISED = BDR_RAISEDOUTER | BDR_RAISEDINNER;

        public const int BDR_SUNKEN = BDR_SUNKENOUTER | BDR_SUNKENINNER;

        public const int EDGE_RAISED = BDR_RAISEDOUTER | BDR_RAISEDINNER;

        public const int EDGE_SUNKEN = BDR_SUNKENOUTER | BDR_SUNKENINNER;

        public const int EDGE_ETCHED = BDR_SUNKENOUTER | BDR_RAISEDINNER;

        public const int EDGE_BUMP = BDR_RAISEDOUTER | BDR_SUNKENINNER;

        public const int BF_LEFT = 0x0001;

        public const int BF_TOP = 0x0002;

        public const int BF_RIGHT = 0x0004;

        public const int BF_BOTTOM = 0x0008;

        public const int BF_TOPLEFT = BF_TOP | BF_LEFT;

        public const int BF_TOPRIGHT = BF_TOP | BF_RIGHT;

        public const int BF_BOTTOMLEFT = BF_BOTTOM | BF_LEFT;

        public const int BF_BOTTOMRIGHT = BF_BOTTOM | BF_RIGHT;

        public const int BF_RECT = BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM;

        public const int BF_DIAGONAL = 0x0010;

        public const int BF_DIAGONAL_ENDTOPRIGHT = BF_DIAGONAL | BF_TOP | BF_RIGHT;

        public const int BF_DIAGONAL_ENDTOPLEFT = BF_DIAGONAL | BF_TOP | BF_LEFT;

        public const int BF_DIAGONAL_ENDBOTTOMLEFT = BF_DIAGONAL | BF_BOTTOM | BF_LEFT;

        public const int BF_DIAGONAL_ENDBOTTOMRIGHT = BF_DIAGONAL | BF_BOTTOM | BF_RIGHT;

        public const int BF_MIDDLE = 0x0800;

        public const int BF_SOFT = 0x1000;

        public const int BF_ADJUST = 0x2000;

        public const int BF_FLAT = 0x4000;

        public const int BF_MONO = 0x8000;

        public const int DFC_CAPTION = 1;

        public const int DFC_MENU = 2;

        public const int DFC_SCROLL = 3;

        public const int DFC_BUTTON = 4;

        public const int DFC_POPUPMENU = 5;

        public const int DFCS_CAPTIONCLOSE = 0x0000;

        public const int DFCS_CAPTIONMIN = 0x0001;

        public const int DFCS_CAPTIONMAX = 0x0002;

        public const int DFCS_CAPTIONRESTORE = 0x0003;

        public const int DFCS_CAPTIONHELP = 0x0004;

        public const int DFCS_MENUARROW = 0x0000;

        public const int DFCS_MENUCHECK = 0x0001;

        public const int DFCS_MENUBULLET = 0x0002;

        public const int DFCS_MENUARROWRIGHT = 0x0004;

        public const int DFCS_SCROLLUP = 0x0000;

        public const int DFCS_SCROLLDOWN = 0x0001;

        public const int DFCS_SCROLLLEFT = 0x0002;

        public const int DFCS_SCROLLRIGHT = 0x0003;

        public const int DFCS_SCROLLCOMBOBOX = 0x0005;

        public const int DFCS_SCROLLSIZEGRIP = 0x0008;

        public const int DFCS_SCROLLSIZEGRIPRIGHT = 0x0010;

        public const int DFCS_BUTTONCHECK = 0x0000;

        public const int DFCS_BUTTONRADIOIMAGE = 0x0001;

        public const int DFCS_BUTTONRADIOMASK = 0x0002;

        public const int DFCS_BUTTONRADIO = 0x0004;

        public const int DFCS_BUTTON3STATE = 0x0008;

        public const int DFCS_BUTTONPUSH = 0x0010;

        public const int DFCS_INACTIVE = 0x0100;

        public const int DFCS_PUSHED = 0x0200;

        public const int DFCS_CHECKED = 0x0400;

        public const int DFCS_TRANSPARENT = 0x0800;

        public const int DFCS_HOT = 0x1000;

        public const int DFCS_ADJUSTRECT = 0x2000;

        public const int DFCS_FLAT = 0x4000;

        public const int DFCS_MONO = 0x8000;

        public const int DC_ACTIVE = 0x0001;

        public const int DC_SMALLCAP = 0x0002;

        public const int DC_ICON = 0x0004;

        public const int DC_TEXT = 0x0008;

        public const int DC_INBUTTON = 0x0010;

        public const int DC_GRADIENT = 0x0020;

        public const int DC_BUTTONS = 0x1000;

        public const int IDANI_OPEN = 1;

        public const int IDANI_CAPTION = 3;

        public const int CF_TEXT = 1;

        public const int CF_BITMAP = 2;

        public const int CF_METAFILEPICT = 3;

        public const int CF_SYLK = 4;

        public const int CF_DIF = 5;

        public const int CF_TIFF = 6;

        public const int CF_OEMTEXT = 7;

        public const int CF_DIB = 8;

        public const int CF_PALETTE = 9;

        public const int CF_PENDATA = 10;

        public const int CF_RIFF = 11;

        public const int CF_WAVE = 12;

        public const int CF_UNICODETEXT = 13;

        public const int CF_ENHMETAFILE = 14;

        public const int CF_HDROP = 15;

        public const int CF_LOCALE = 16;

        public const int CF_DIBV5 = 17;

        public const int CF_MAX = 18;

        public const int CF_OWNERDISPLAY = 0x0080;

        public const int CF_DSPTEXT = 0x0081;

        public const int CF_DSPBITMAP = 0x0082;

        public const int CF_DSPMETAFILEPICT = 0x0083;

        public const int CF_DSPENHMETAFILE = 0x008E;

        public const int CF_PRIVATEFIRST = 0x0200;

        public const int CF_PRIVATELAST = 0x02FF;

        public const int CF_GDIOBJFIRST = 0x0300;

        public const int CF_GDIOBJLAST = 0x03FF;

        public const int FVIRTKEY = 1;

        public const int FNOINVERT = 0x02;

        public const int FSHIFT = 0x04;

        public const int FCONTROL = 0x08;

        public const int FALT = 0x10;

        public const int WPF_SETMINPOSITION = 0x0001;

        public const int WPF_RESTORETOMAXIMIZED = 0x0002;

        public const int WPF_ASYNCWINDOWPLACEMENT = 0x0004;

        public const int ODT_MENU = 1;

        public const int ODT_LISTBOX = 2;

        public const int ODT_COMBOBOX = 3;

        public const int ODT_BUTTON = 4;

        public const int ODT_STATIC = 5;

        public const int ODA_DRAWENTIRE = 0x0001;

        public const int ODA_SELECT = 0x0002;

        public const int ODA_FOCUS = 0x0004;

        public const int ODS_SELECTED = 0x0001;

        public const int ODS_GRAYED = 0x0002;

        public const int ODS_DISABLED = 0x0004;

        public const int ODS_CHECKED = 0x0008;

        public const int ODS_FOCUS = 0x0010;

        public const int ODS_DEFAULT = 0x0020;

        public const int ODS_COMBOBOXEDIT = 0x1000;

        public const int ODS_HOTLIGHT = 0x0040;

        public const int ODS_INACTIVE = 0x0080;

        public const int ODS_NOACCEL = 0x0100;

        public const int ODS_NOFOCUSRECT = 0x0200;

        public const int PM_NOREMOVE = 0x0000;

        public const int PM_REMOVE = 0x0001;

        public const int PM_NOYIELD = 0x0002;

        public const int PM_QS_INPUT = QS_INPUT << 16;

        public const int PM_QS_POSTMESSAGE = (QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16;

        public const int PM_QS_PAINT = QS_PAINT << 16;

        public const int PM_QS_SENDMESSAGE = QS_SENDMESSAGE << 16;

        public const int MOD_ALT = 0x0001;

        public const int MOD_CONTROL = 0x0002;

        public const int MOD_SHIFT = 0x0004;

        public const int MOD_WIN = 0x0008;

        public const int MOD_NOREPEAT = 0x4000;

        public const int IDHOT_SNAPWINDOW = -1;

        public const int IDHOT_SNAPDESKTOP = -2;

        public const uint ENDSESSION_CLOSEAPP = 0x00000001;

        public const uint ENDSESSION_CRITICAL = 0x40000000;

        public const uint ENDSESSION_LOGOFF = 0x80000000;

        public const int EWX_LOGOFF = 0x00000000;

        public const int EWX_SHUTDOWN = 0x00000001;

        public const int EWX_REBOOT = 0x00000002;

        public const int EWX_FORCE = 0x00000004;

        public const int EWX_POWEROFF = 0x00000008;

        public const int EWX_FORCEIFHUNG = 0x00000010;

        public const int EWX_QUICKRESOLVE = 0x00000020;

        public const int EWX_RESTARTAPPS = 0x00000040;

        public const int EWX_HYBRID_SHUTDOWN = 0x00400000;

        public const int EWX_BOOTOPTIONS = 0x01000000;

        public const int EWX_ARSO = 0x04000000;

        public const int BSM_ALLCOMPONENTS = 0x00000000;

        public const int BSM_VXDS = 0x00000001;

        public const int BSM_NETDRIVER = 0x00000002;

        public const int BSM_INSTALLABLEDRIVERS = 0x00000004;

        public const int BSM_APPLICATIONS = 0x00000008;

        public const int BSM_ALLDESKTOPS = 0x00000010;

        public const int BSF_QUERY = 0x00000001;

        public const int BSF_IGNORECURRENTTASK = 0x00000002;

        public const int BSF_FLUSHDISK = 0x00000004;

        public const int BSF_NOHANG = 0x00000008;

        public const int BSF_POSTMESSAGE = 0x00000010;

        public const int BSF_FORCEIFHUNG = 0x00000020;

        public const int BSF_NOTIMEOUTIFNOTHUNG = 0x00000040;

        public const int BSF_ALLOWSFW = 0x00000080;

        public const int BSF_SENDNOTIFYMESSAGE = 0x00000100;

        public const int BSF_RETURNHDESK = 0x00000200;

        public const int BSF_LUID = 0x00000400;

        public const int BROADCAST_QUERY_DENY = 0x424D5144;

        public const int DEVICE_NOTIFY_WINDOW_HANDLE = 0x00000000;

        public const int DEVICE_NOTIFY_SERVICE_HANDLE = 0x00000001;

        public const int DEVICE_NOTIFY_ALL_INTERFACE_CLASSES = 0x00000004;

        [NativeTypeName("HWND")]
        public const int HWND_BROADCAST = 0xFFFF;

        [NativeTypeName("HWND")]
        public const int HWND_MESSAGE = -3;

        public const int ISMEX_NOSEND = 0x00000000;

        public const int ISMEX_SEND = 0x00000001;

        public const int ISMEX_NOTIFY = 0x00000002;

        public const int ISMEX_CALLBACK = 0x00000004;

        public const int ISMEX_REPLIED = 0x00000008;

        public const int CW_USEDEFAULT = unchecked((int)0x80000000);

        [NativeTypeName("HWND")]
        public const int HWND_DESKTOP = 0;

        public const int PW_CLIENTONLY = 0x00000001;

        public const int PW_RENDERFULLCONTENT = 0x00000002;

        public const int LWA_COLORKEY = 0x00000001;

        public const int LWA_ALPHA = 0x00000002;

        public const int ULW_COLORKEY = 0x00000001;

        public const int ULW_ALPHA = 0x00000002;

        public const int ULW_OPAQUE = 0x00000004;

        public const int ULW_EX_NORESIZE = 0x00000008;

        public const int FLASHW_STOP = 0;

        public const int FLASHW_CAPTION = 0x00000001;

        public const int FLASHW_TRAY = 0x00000002;

        public const int FLASHW_ALL = FLASHW_CAPTION | FLASHW_TRAY;

        public const int FLASHW_TIMER = 0x00000004;

        public const int FLASHW_TIMERNOFG = 0x0000000C;

        public const int WDA_NONE = 0x00000000;

        public const int WDA_MONITOR = 0x00000001;

        public const int WDA_EXCLUDEFROMCAPTURE = 0x00000011;

        public const int SWP_NOSIZE = 0x0001;

        public const int SWP_NOMOVE = 0x0002;

        public const int SWP_NOZORDER = 0x0004;

        public const int SWP_NOREDRAW = 0x0008;

        public const int SWP_NOACTIVATE = 0x0010;

        public const int SWP_FRAMECHANGED = 0x0020;

        public const int SWP_SHOWWINDOW = 0x0040;

        public const int SWP_HIDEWINDOW = 0x0080;

        public const int SWP_NOCOPYBITS = 0x0100;

        public const int SWP_NOOWNERZORDER = 0x0200;

        public const int SWP_NOSENDCHANGING = 0x0400;

        public const int SWP_DRAWFRAME = SWP_FRAMECHANGED;

        public const int SWP_NOREPOSITION = SWP_NOOWNERZORDER;

        public const int SWP_DEFERERASE = 0x2000;

        public const int SWP_ASYNCWINDOWPOS = 0x4000;

        [NativeTypeName("HWND")]
        public const int HWND_TOP = 0;

        [NativeTypeName("HWND")]
        public const int HWND_BOTTOM = 1;

        [NativeTypeName("HWND")]
        public const int HWND_TOPMOST = -1;

        [NativeTypeName("HWND")]
        public const int HWND_NOTOPMOST = -2;

        public const int DLGWINDOWEXTRA = 30;

        public const int KEYEVENTF_EXTENDEDKEY = 0x0001;

        public const int KEYEVENTF_KEYUP = 0x0002;

        public const int KEYEVENTF_UNICODE = 0x0004;

        public const int KEYEVENTF_SCANCODE = 0x0008;

        public const int MOUSEEVENTF_MOVE = 0x0001;

        public const int MOUSEEVENTF_LEFTDOWN = 0x0002;

        public const int MOUSEEVENTF_LEFTUP = 0x0004;

        public const int MOUSEEVENTF_RIGHTDOWN = 0x0008;

        public const int MOUSEEVENTF_RIGHTUP = 0x0010;

        public const int MOUSEEVENTF_MIDDLEDOWN = 0x0020;

        public const int MOUSEEVENTF_MIDDLEUP = 0x0040;

        public const int MOUSEEVENTF_XDOWN = 0x0080;

        public const int MOUSEEVENTF_XUP = 0x0100;

        public const int MOUSEEVENTF_WHEEL = 0x0800;

        public const int MOUSEEVENTF_HWHEEL = 0x01000;

        public const int MOUSEEVENTF_MOVE_NOCOALESCE = 0x2000;

        public const int MOUSEEVENTF_VIRTUALDESK = 0x4000;

        public const int MOUSEEVENTF_ABSOLUTE = 0x8000;

        public const int INPUT_MOUSE = 0;

        public const int INPUT_KEYBOARD = 1;

        public const int INPUT_HARDWARE = 2;

        public const int TOUCHEVENTF_MOVE = 0x0001;

        public const int TOUCHEVENTF_DOWN = 0x0002;

        public const int TOUCHEVENTF_UP = 0x0004;

        public const int TOUCHEVENTF_INRANGE = 0x0008;

        public const int TOUCHEVENTF_PRIMARY = 0x0010;

        public const int TOUCHEVENTF_NOCOALESCE = 0x0020;

        public const int TOUCHEVENTF_PEN = 0x0040;

        public const int TOUCHEVENTF_PALM = 0x0080;

        public const int TOUCHINPUTMASKF_TIMEFROMSYSTEM = 0x0001;

        public const int TOUCHINPUTMASKF_EXTRAINFO = 0x0002;

        public const int TOUCHINPUTMASKF_CONTACTAREA = 0x0004;

        public const int TWF_FINETOUCH = 0x00000001;

        public const int TWF_WANTPALM = 0x00000002;

        public const int POINTER_FLAG_NONE = 0x00000000;

        public const int POINTER_FLAG_NEW = 0x00000001;

        public const int POINTER_FLAG_INRANGE = 0x00000002;

        public const int POINTER_FLAG_INCONTACT = 0x00000004;

        public const int POINTER_FLAG_FIRSTBUTTON = 0x00000010;

        public const int POINTER_FLAG_SECONDBUTTON = 0x00000020;

        public const int POINTER_FLAG_THIRDBUTTON = 0x00000040;

        public const int POINTER_FLAG_FOURTHBUTTON = 0x00000080;

        public const int POINTER_FLAG_FIFTHBUTTON = 0x00000100;

        public const int POINTER_FLAG_PRIMARY = 0x00002000;

        public const int POINTER_FLAG_CONFIDENCE = 0x00004000;

        public const int POINTER_FLAG_CANCELED = 0x00008000;

        public const int POINTER_FLAG_DOWN = 0x00010000;

        public const int POINTER_FLAG_UPDATE = 0x00020000;

        public const int POINTER_FLAG_UP = 0x00040000;

        public const int POINTER_FLAG_WHEEL = 0x00080000;

        public const int POINTER_FLAG_HWHEEL = 0x00100000;

        public const int POINTER_FLAG_CAPTURECHANGED = 0x00200000;

        public const int POINTER_FLAG_HASTRANSFORM = 0x00400000;

        public const int POINTER_MOD_SHIFT = 0x0004;

        public const int POINTER_MOD_CTRL = 0x0008;

        public const int TOUCH_FLAG_NONE = 0x00000000;

        public const int TOUCH_MASK_NONE = 0x00000000;

        public const int TOUCH_MASK_CONTACTAREA = 0x00000001;

        public const int TOUCH_MASK_ORIENTATION = 0x00000002;

        public const int TOUCH_MASK_PRESSURE = 0x00000004;

        public const int PEN_FLAG_NONE = 0x00000000;

        public const int PEN_FLAG_BARREL = 0x00000001;

        public const int PEN_FLAG_INVERTED = 0x00000002;

        public const int PEN_FLAG_ERASER = 0x00000004;

        public const int PEN_MASK_NONE = 0x00000000;

        public const int PEN_MASK_PRESSURE = 0x00000001;

        public const int PEN_MASK_ROTATION = 0x00000002;

        public const int PEN_MASK_TILT_X = 0x00000004;

        public const int PEN_MASK_TILT_Y = 0x00000008;

        public const int POINTER_MESSAGE_FLAG_NEW = 0x00000001;

        public const int POINTER_MESSAGE_FLAG_INRANGE = 0x00000002;

        public const int POINTER_MESSAGE_FLAG_INCONTACT = 0x00000004;

        public const int POINTER_MESSAGE_FLAG_FIRSTBUTTON = 0x00000010;

        public const int POINTER_MESSAGE_FLAG_SECONDBUTTON = 0x00000020;

        public const int POINTER_MESSAGE_FLAG_THIRDBUTTON = 0x00000040;

        public const int POINTER_MESSAGE_FLAG_FOURTHBUTTON = 0x00000080;

        public const int POINTER_MESSAGE_FLAG_FIFTHBUTTON = 0x00000100;

        public const int POINTER_MESSAGE_FLAG_PRIMARY = 0x00002000;

        public const int POINTER_MESSAGE_FLAG_CONFIDENCE = 0x00004000;

        public const int POINTER_MESSAGE_FLAG_CANCELED = 0x00008000;

        public const int PA_ACTIVATE = MA_ACTIVATE;

        public const int PA_NOACTIVATE = MA_NOACTIVATE;

        public const int MAX_TOUCH_COUNT = 256;

        public const int TOUCH_FEEDBACK_DEFAULT = 0x1;

        public const int TOUCH_FEEDBACK_INDIRECT = 0x2;

        public const int TOUCH_FEEDBACK_NONE = 0x3;

        public const int TOUCH_HIT_TESTING_DEFAULT = 0x0;

        public const int TOUCH_HIT_TESTING_CLIENT = 0x1;

        public const int TOUCH_HIT_TESTING_NONE = 0x2;

        public const int TOUCH_HIT_TESTING_PROXIMITY_CLOSEST = 0x0;

        public const int TOUCH_HIT_TESTING_PROXIMITY_FARTHEST = 0xFFF;

        public const int GWFS_INCLUDE_ANCESTORS = 0x00000001;

        public const int MAPVK_VK_TO_VSC = 0;

        public const int MAPVK_VSC_TO_VK = 1;

        public const int MAPVK_VK_TO_CHAR = 2;

        public const int MAPVK_VSC_TO_VK_EX = 3;

        public const int MAPVK_VK_TO_VSC_EX = 4;

        public const int MWMO_WAITALL = 0x0001;

        public const int MWMO_ALERTABLE = 0x0002;

        public const int MWMO_INPUTAVAILABLE = 0x0004;

        public const int QS_KEY = 0x0001;

        public const int QS_MOUSEMOVE = 0x0002;

        public const int QS_MOUSEBUTTON = 0x0004;

        public const int QS_POSTMESSAGE = 0x0008;

        public const int QS_TIMER = 0x0010;

        public const int QS_PAINT = 0x0020;

        public const int QS_SENDMESSAGE = 0x0040;

        public const int QS_HOTKEY = 0x0080;

        public const int QS_ALLPOSTMESSAGE = 0x0100;

        public const int QS_RAWINPUT = 0x0400;

        public const int QS_TOUCH = 0x0800;

        public const int QS_POINTER = 0x1000;

        public const int QS_MOUSE = QS_MOUSEMOVE | QS_MOUSEBUTTON;

        public const int QS_INPUT = QS_MOUSE | QS_KEY | QS_RAWINPUT | QS_TOUCH | QS_POINTER;

        public const int QS_ALLEVENTS = QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY;

        public const int QS_ALLINPUT = QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE;

        public const int USER_TIMER_MAXIMUM = 0x7FFFFFFF;

        public const int USER_TIMER_MINIMUM = 0x0000000A;

        public const uint TIMERV_DEFAULT_COALESCING = 0;

        public const uint TIMERV_NO_COALESCING = 0xFFFFFFFF;

        public const uint TIMERV_COALESCING_MIN = 1;

        public const uint TIMERV_COALESCING_MAX = 0x7FFFFFF5;

        public const int SM_CXSCREEN = 0;

        public const int SM_CYSCREEN = 1;

        public const int SM_CXVSCROLL = 2;

        public const int SM_CYHSCROLL = 3;

        public const int SM_CYCAPTION = 4;

        public const int SM_CXBORDER = 5;

        public const int SM_CYBORDER = 6;

        public const int SM_CXDLGFRAME = 7;

        public const int SM_CYDLGFRAME = 8;

        public const int SM_CYVTHUMB = 9;

        public const int SM_CXHTHUMB = 10;

        public const int SM_CXICON = 11;

        public const int SM_CYICON = 12;

        public const int SM_CXCURSOR = 13;

        public const int SM_CYCURSOR = 14;

        public const int SM_CYMENU = 15;

        public const int SM_CXFULLSCREEN = 16;

        public const int SM_CYFULLSCREEN = 17;

        public const int SM_CYKANJIWINDOW = 18;

        public const int SM_MOUSEPRESENT = 19;

        public const int SM_CYVSCROLL = 20;

        public const int SM_CXHSCROLL = 21;

        public const int SM_DEBUG = 22;

        public const int SM_SWAPBUTTON = 23;

        public const int SM_RESERVED1 = 24;

        public const int SM_RESERVED2 = 25;

        public const int SM_RESERVED3 = 26;

        public const int SM_RESERVED4 = 27;

        public const int SM_CXMIN = 28;

        public const int SM_CYMIN = 29;

        public const int SM_CXSIZE = 30;

        public const int SM_CYSIZE = 31;

        public const int SM_CXFRAME = 32;

        public const int SM_CYFRAME = 33;

        public const int SM_CXMINTRACK = 34;

        public const int SM_CYMINTRACK = 35;

        public const int SM_CXDOUBLECLK = 36;

        public const int SM_CYDOUBLECLK = 37;

        public const int SM_CXICONSPACING = 38;

        public const int SM_CYICONSPACING = 39;

        public const int SM_MENUDROPALIGNMENT = 40;

        public const int SM_PENWINDOWS = 41;

        public const int SM_DBCSENABLED = 42;

        public const int SM_CMOUSEBUTTONS = 43;

        public const int SM_CXFIXEDFRAME = SM_CXDLGFRAME;

        public const int SM_CYFIXEDFRAME = SM_CYDLGFRAME;

        public const int SM_CXSIZEFRAME = SM_CXFRAME;

        public const int SM_CYSIZEFRAME = SM_CYFRAME;

        public const int SM_SECURE = 44;

        public const int SM_CXEDGE = 45;

        public const int SM_CYEDGE = 46;

        public const int SM_CXMINSPACING = 47;

        public const int SM_CYMINSPACING = 48;

        public const int SM_CXSMICON = 49;

        public const int SM_CYSMICON = 50;

        public const int SM_CYSMCAPTION = 51;

        public const int SM_CXSMSIZE = 52;

        public const int SM_CYSMSIZE = 53;

        public const int SM_CXMENUSIZE = 54;

        public const int SM_CYMENUSIZE = 55;

        public const int SM_ARRANGE = 56;

        public const int SM_CXMINIMIZED = 57;

        public const int SM_CYMINIMIZED = 58;

        public const int SM_CXMAXTRACK = 59;

        public const int SM_CYMAXTRACK = 60;

        public const int SM_CXMAXIMIZED = 61;

        public const int SM_CYMAXIMIZED = 62;

        public const int SM_NETWORK = 63;

        public const int SM_CLEANBOOT = 67;

        public const int SM_CXDRAG = 68;

        public const int SM_CYDRAG = 69;

        public const int SM_SHOWSOUNDS = 70;

        public const int SM_CXMENUCHECK = 71;

        public const int SM_CYMENUCHECK = 72;

        public const int SM_SLOWMACHINE = 73;

        public const int SM_MIDEASTENABLED = 74;

        public const int SM_MOUSEWHEELPRESENT = 75;

        public const int SM_XVIRTUALSCREEN = 76;

        public const int SM_YVIRTUALSCREEN = 77;

        public const int SM_CXVIRTUALSCREEN = 78;

        public const int SM_CYVIRTUALSCREEN = 79;

        public const int SM_CMONITORS = 80;

        public const int SM_SAMEDISPLAYFORMAT = 81;

        public const int SM_IMMENABLED = 82;

        public const int SM_CXFOCUSBORDER = 83;

        public const int SM_CYFOCUSBORDER = 84;

        public const int SM_TABLETPC = 86;

        public const int SM_MEDIACENTER = 87;

        public const int SM_STARTER = 88;

        public const int SM_SERVERR2 = 89;

        public const int SM_MOUSEHORIZONTALWHEELPRESENT = 91;

        public const int SM_CXPADDEDBORDER = 92;

        public const int SM_DIGITIZER = 94;

        public const int SM_MAXIMUMTOUCHES = 95;

        public const int SM_CMETRICS = 97;

        public const int SM_REMOTESESSION = 0x1000;

        public const int SM_SHUTTINGDOWN = 0x2000;

        public const int SM_REMOTECONTROL = 0x2001;

        public const int SM_CARETBLINKINGENABLED = 0x2002;

        public const int SM_CONVERTIBLESLATEMODE = 0x2003;

        public const int SM_SYSTEMDOCKED = 0x2004;

        public const int PMB_ACTIVE = 0x00000001;

        public const int MNC_IGNORE = 0;

        public const int MNC_CLOSE = 1;

        public const int MNC_EXECUTE = 2;

        public const int MNC_SELECT = 3;

        public const uint MNS_NOCHECK = 0x80000000;

        public const uint MNS_MODELESS = 0x40000000;

        public const uint MNS_DRAGDROP = 0x20000000;

        public const uint MNS_AUTODISMISS = 0x10000000;

        public const uint MNS_NOTIFYBYPOS = 0x08000000;

        public const uint MNS_CHECKORBMP = 0x04000000;

        public const uint MIM_MAXHEIGHT = 0x00000001;

        public const uint MIM_BACKGROUND = 0x00000002;

        public const uint MIM_HELPID = 0x00000004;

        public const uint MIM_MENUDATA = 0x00000008;

        public const uint MIM_STYLE = 0x00000010;

        public const uint MIM_APPLYTOSUBMENUS = 0x80000000;

        public const int MND_CONTINUE = 0;

        public const int MND_ENDMENU = 1;

        public const int MNGOF_TOPGAP = 0x00000001;

        public const int MNGOF_BOTTOMGAP = 0x00000002;

        public const int MNGO_NOINTERFACE = 0x00000000;

        public const int MNGO_NOERROR = 0x00000001;

        public const int MIIM_STATE = 0x00000001;

        public const int MIIM_ID = 0x00000002;

        public const int MIIM_SUBMENU = 0x00000004;

        public const int MIIM_CHECKMARKS = 0x00000008;

        public const int MIIM_TYPE = 0x00000010;

        public const int MIIM_DATA = 0x00000020;

        public const int MIIM_STRING = 0x00000040;

        public const int MIIM_BITMAP = 0x00000080;

        public const int MIIM_FTYPE = 0x00000100;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_CALLBACK = -1;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_SYSTEM = 1;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_MBAR_RESTORE = 2;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_MBAR_MINIMIZE = 3;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_MBAR_CLOSE = 5;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_MBAR_CLOSE_D = 6;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_MBAR_MINIMIZE_D = 7;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_POPUP_CLOSE = 8;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_POPUP_RESTORE = 9;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_POPUP_MAXIMIZE = 10;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_POPUP_MINIMIZE = 11;

        public const int TPM_LEFTBUTTON = 0x0000;

        public const int TPM_RIGHTBUTTON = 0x0002;

        public const int TPM_LEFTALIGN = 0x0000;

        public const int TPM_CENTERALIGN = 0x0004;

        public const int TPM_RIGHTALIGN = 0x0008;

        public const int TPM_TOPALIGN = 0x0000;

        public const int TPM_VCENTERALIGN = 0x0010;

        public const int TPM_BOTTOMALIGN = 0x0020;

        public const int TPM_HORIZONTAL = 0x0000;

        public const int TPM_VERTICAL = 0x0040;

        public const int TPM_NONOTIFY = 0x0080;

        public const int TPM_RETURNCMD = 0x0100;

        public const int TPM_RECURSE = 0x0001;

        public const int TPM_HORPOSANIMATION = 0x0400;

        public const int TPM_HORNEGANIMATION = 0x0800;

        public const int TPM_VERPOSANIMATION = 0x1000;

        public const int TPM_VERNEGANIMATION = 0x2000;

        public const int TPM_NOANIMATION = 0x4000;

        public const int TPM_LAYOUTRTL = 0x8000;

        public const int TPM_WORKAREA = 0x10000;

        public const int DOF_EXECUTABLE = 0x8001;

        public const int DOF_DOCUMENT = 0x8002;

        public const int DOF_DIRECTORY = 0x8003;

        public const int DOF_MULTIPLE = 0x8004;

        public const int DOF_PROGMAN = 0x0001;

        public const int DOF_SHELLDATA = 0x0002;

        public const int DO_DROPFILE = 0x454C4946;

        public const int DO_PRINTFILE = 0x544E5250;

        public const int DT_TOP = 0x00000000;

        public const int DT_LEFT = 0x00000000;

        public const int DT_CENTER = 0x00000001;

        public const int DT_RIGHT = 0x00000002;

        public const int DT_VCENTER = 0x00000004;

        public const int DT_BOTTOM = 0x00000008;

        public const int DT_WORDBREAK = 0x00000010;

        public const int DT_SINGLELINE = 0x00000020;

        public const int DT_EXPANDTABS = 0x00000040;

        public const int DT_TABSTOP = 0x00000080;

        public const int DT_NOCLIP = 0x00000100;

        public const int DT_EXTERNALLEADING = 0x00000200;

        public const int DT_CALCRECT = 0x00000400;

        public const int DT_NOPREFIX = 0x00000800;

        public const int DT_INTERNAL = 0x00001000;

        public const int DT_EDITCONTROL = 0x00002000;

        public const int DT_PATH_ELLIPSIS = 0x00004000;

        public const int DT_END_ELLIPSIS = 0x00008000;

        public const int DT_MODIFYSTRING = 0x00010000;

        public const int DT_RTLREADING = 0x00020000;

        public const int DT_WORD_ELLIPSIS = 0x00040000;

        public const int DT_NOFULLWIDTHCHARBREAK = 0x00080000;

        public const int DT_HIDEPREFIX = 0x00100000;

        public const int DT_PREFIXONLY = 0x00200000;

        public const int DST_COMPLEX = 0x0000;

        public const int DST_TEXT = 0x0001;

        public const int DST_PREFIXTEXT = 0x0002;

        public const int DST_ICON = 0x0003;

        public const int DST_BITMAP = 0x0004;

        public const int DSS_NORMAL = 0x0000;

        public const int DSS_UNION = 0x0010;

        public const int DSS_DISABLED = 0x0020;

        public const int DSS_MONO = 0x0080;

        public const int DSS_HIDEPREFIX = 0x0200;

        public const int DSS_PREFIXONLY = 0x0400;

        public const int DSS_RIGHT = 0x8000;

        public const uint ASFW_ANY = unchecked((uint)-1);

        public const int LSFW_LOCK = 1;

        public const int LSFW_UNLOCK = 2;

        public const int DCX_WINDOW = 0x00000001;

        public const int DCX_CACHE = 0x00000002;

        public const int DCX_NORESETATTRS = 0x00000004;

        public const int DCX_CLIPCHILDREN = 0x00000008;

        public const int DCX_CLIPSIBLINGS = 0x00000010;

        public const int DCX_PARENTCLIP = 0x00000020;

        public const int DCX_EXCLUDERGN = 0x00000040;

        public const int DCX_INTERSECTRGN = 0x00000080;

        public const int DCX_EXCLUDEUPDATE = 0x00000100;

        public const int DCX_INTERSECTUPDATE = 0x00000200;

        public const int DCX_LOCKWINDOWUPDATE = 0x00000400;

        public const int DCX_VALIDATE = 0x00200000;

        public const int RDW_INVALIDATE = 0x0001;

        public const int RDW_INTERNALPAINT = 0x0002;

        public const int RDW_ERASE = 0x0004;

        public const int RDW_VALIDATE = 0x0008;

        public const int RDW_NOINTERNALPAINT = 0x0010;

        public const int RDW_NOERASE = 0x0020;

        public const int RDW_NOCHILDREN = 0x0040;

        public const int RDW_ALLCHILDREN = 0x0080;

        public const int RDW_UPDATENOW = 0x0100;

        public const int RDW_ERASENOW = 0x0200;

        public const int RDW_FRAME = 0x0400;

        public const int RDW_NOFRAME = 0x0800;

        public const int SW_SCROLLCHILDREN = 0x0001;

        public const int SW_INVALIDATE = 0x0002;

        public const int SW_ERASE = 0x0004;

        public const int SW_SMOOTHSCROLL = 0x0010;

        public const int ESB_ENABLE_BOTH = 0x0000;

        public const int ESB_DISABLE_BOTH = 0x0003;

        public const int ESB_DISABLE_LEFT = 0x0001;

        public const int ESB_DISABLE_RIGHT = 0x0002;

        public const int ESB_DISABLE_UP = 0x0001;

        public const int ESB_DISABLE_DOWN = 0x0002;

        public const int ESB_DISABLE_LTUP = ESB_DISABLE_LEFT;

        public const int ESB_DISABLE_RTDN = ESB_DISABLE_RIGHT;

        public const int HELPINFO_WINDOW = 0x0001;

        public const int HELPINFO_MENUITEM = 0x0002;

        public const int MB_OK = 0x00000000;

        public const int MB_OKCANCEL = 0x00000001;

        public const int MB_ABORTRETRYIGNORE = 0x00000002;

        public const int MB_YESNOCANCEL = 0x00000003;

        public const int MB_YESNO = 0x00000004;

        public const int MB_RETRYCANCEL = 0x00000005;

        public const int MB_CANCELTRYCONTINUE = 0x00000006;

        public const int MB_ICONHAND = 0x00000010;

        public const int MB_ICONQUESTION = 0x00000020;

        public const int MB_ICONEXCLAMATION = 0x00000030;

        public const int MB_ICONASTERISK = 0x00000040;

        public const int MB_USERICON = 0x00000080;

        public const int MB_ICONWARNING = MB_ICONEXCLAMATION;

        public const int MB_ICONERROR = MB_ICONHAND;

        public const int MB_ICONINFORMATION = MB_ICONASTERISK;

        public const int MB_ICONSTOP = MB_ICONHAND;

        public const int MB_DEFBUTTON1 = 0x00000000;

        public const int MB_DEFBUTTON2 = 0x00000100;

        public const int MB_DEFBUTTON3 = 0x00000200;

        public const int MB_DEFBUTTON4 = 0x00000300;

        public const int MB_APPLMODAL = 0x00000000;

        public const int MB_SYSTEMMODAL = 0x00001000;

        public const int MB_TASKMODAL = 0x00002000;

        public const int MB_HELP = 0x00004000;

        public const int MB_NOFOCUS = 0x00008000;

        public const int MB_SETFOREGROUND = 0x00010000;

        public const int MB_DEFAULT_DESKTOP_ONLY = 0x00020000;

        public const int MB_TOPMOST = 0x00040000;

        public const int MB_RIGHT = 0x00080000;

        public const int MB_RTLREADING = 0x00100000;

        public const int MB_SERVICE_NOTIFICATION = 0x00200000;

        public const int MB_SERVICE_NOTIFICATION_NT3X = 0x00040000;

        public const int MB_TYPEMASK = 0x0000000F;

        public const int MB_ICONMASK = 0x000000F0;

        public const int MB_DEFMASK = 0x00000F00;

        public const int MB_MODEMASK = 0x00003000;

        public const int MB_MISCMASK = 0x0000C000;

        public const int CWP_ALL = 0x0000;

        public const int CWP_SKIPINVISIBLE = 0x0001;

        public const int CWP_SKIPDISABLED = 0x0002;

        public const int CWP_SKIPTRANSPARENT = 0x0004;

        public const int CTLCOLOR_MSGBOX = 0;

        public const int CTLCOLOR_EDIT = 1;

        public const int CTLCOLOR_LISTBOX = 2;

        public const int CTLCOLOR_BTN = 3;

        public const int CTLCOLOR_DLG = 4;

        public const int CTLCOLOR_SCROLLBAR = 5;

        public const int CTLCOLOR_STATIC = 6;

        public const int CTLCOLOR_MAX = 7;

        public const int COLOR_SCROLLBAR = 0;

        public const int COLOR_BACKGROUND = 1;

        public const int COLOR_ACTIVECAPTION = 2;

        public const int COLOR_INACTIVECAPTION = 3;

        public const int COLOR_MENU = 4;

        public const int COLOR_WINDOW = 5;

        public const int COLOR_WINDOWFRAME = 6;

        public const int COLOR_MENUTEXT = 7;

        public const int COLOR_WINDOWTEXT = 8;

        public const int COLOR_CAPTIONTEXT = 9;

        public const int COLOR_ACTIVEBORDER = 10;

        public const int COLOR_INACTIVEBORDER = 11;

        public const int COLOR_APPWORKSPACE = 12;

        public const int COLOR_HIGHLIGHT = 13;

        public const int COLOR_HIGHLIGHTTEXT = 14;

        public const int COLOR_BTNFACE = 15;

        public const int COLOR_BTNSHADOW = 16;

        public const int COLOR_GRAYTEXT = 17;

        public const int COLOR_BTNTEXT = 18;

        public const int COLOR_INACTIVECAPTIONTEXT = 19;

        public const int COLOR_BTNHIGHLIGHT = 20;

        public const int COLOR_3DDKSHADOW = 21;

        public const int COLOR_3DLIGHT = 22;

        public const int COLOR_INFOTEXT = 23;

        public const int COLOR_INFOBK = 24;

        public const int COLOR_HOTLIGHT = 26;

        public const int COLOR_GRADIENTACTIVECAPTION = 27;

        public const int COLOR_GRADIENTINACTIVECAPTION = 28;

        public const int COLOR_MENUHILIGHT = 29;

        public const int COLOR_MENUBAR = 30;

        public const int COLOR_DESKTOP = COLOR_BACKGROUND;

        public const int COLOR_3DFACE = COLOR_BTNFACE;

        public const int COLOR_3DSHADOW = COLOR_BTNSHADOW;

        public const int COLOR_3DHIGHLIGHT = COLOR_BTNHIGHLIGHT;

        public const int COLOR_3DHILIGHT = COLOR_BTNHIGHLIGHT;

        public const int COLOR_BTNHILIGHT = COLOR_BTNHIGHLIGHT;

        public const int GW_HWNDFIRST = 0;

        public const int GW_HWNDLAST = 1;

        public const int GW_HWNDNEXT = 2;

        public const int GW_HWNDPREV = 3;

        public const int GW_OWNER = 4;

        public const int GW_CHILD = 5;

        public const int GW_ENABLEDPOPUP = 6;

        public const int GW_MAX = 6;

        public const int MF_INSERT = 0x00000000;

        public const int MF_CHANGE = 0x00000080;

        public const int MF_APPEND = 0x00000100;

        public const int MF_DELETE = 0x00000200;

        public const int MF_REMOVE = 0x00001000;

        public const int MF_BYCOMMAND = 0x00000000;

        public const int MF_BYPOSITION = 0x00000400;

        public const int MF_SEPARATOR = 0x00000800;

        public const int MF_ENABLED = 0x00000000;

        public const int MF_GRAYED = 0x00000001;

        public const int MF_DISABLED = 0x00000002;

        public const int MF_UNCHECKED = 0x00000000;

        public const int MF_CHECKED = 0x00000008;

        public const int MF_USECHECKBITMAPS = 0x00000200;

        public const int MF_STRING = 0x00000000;

        public const int MF_BITMAP = 0x00000004;

        public const int MF_OWNERDRAW = 0x00000100;

        public const int MF_POPUP = 0x00000010;

        public const int MF_MENUBARBREAK = 0x00000020;

        public const int MF_MENUBREAK = 0x00000040;

        public const int MF_UNHILITE = 0x00000000;

        public const int MF_HILITE = 0x00000080;

        public const int MF_DEFAULT = 0x00001000;

        public const int MF_SYSMENU = 0x00002000;

        public const int MF_HELP = 0x00004000;

        public const int MF_RIGHTJUSTIFY = 0x00004000;

        public const int MF_MOUSESELECT = 0x00008000;

        public const int MF_END = 0x00000080;

        public const int MFT_STRING = MF_STRING;

        public const int MFT_BITMAP = MF_BITMAP;

        public const int MFT_MENUBARBREAK = MF_MENUBARBREAK;

        public const int MFT_MENUBREAK = MF_MENUBREAK;

        public const int MFT_OWNERDRAW = MF_OWNERDRAW;

        public const int MFT_RADIOCHECK = 0x00000200;

        public const int MFT_SEPARATOR = MF_SEPARATOR;

        public const int MFT_RIGHTORDER = 0x00002000;

        public const int MFT_RIGHTJUSTIFY = MF_RIGHTJUSTIFY;

        public const int MFS_GRAYED = 0x00000003;

        public const int MFS_DISABLED = MFS_GRAYED;

        public const int MFS_CHECKED = MF_CHECKED;

        public const int MFS_HILITE = MF_HILITE;

        public const int MFS_ENABLED = MF_ENABLED;

        public const int MFS_UNCHECKED = MF_UNCHECKED;

        public const int MFS_UNHILITE = MF_UNHILITE;

        public const int MFS_DEFAULT = MF_DEFAULT;

        public const int SC_SIZE = 0xF000;

        public const int SC_MOVE = 0xF010;

        public const int SC_MINIMIZE = 0xF020;

        public const int SC_MAXIMIZE = 0xF030;

        public const int SC_NEXTWINDOW = 0xF040;

        public const int SC_PREVWINDOW = 0xF050;

        public const int SC_CLOSE = 0xF060;

        public const int SC_VSCROLL = 0xF070;

        public const int SC_HSCROLL = 0xF080;

        public const int SC_MOUSEMENU = 0xF090;

        public const int SC_KEYMENU = 0xF100;

        public const int SC_ARRANGE = 0xF110;

        public const int SC_RESTORE = 0xF120;

        public const int SC_TASKLIST = 0xF130;

        public const int SC_SCREENSAVE = 0xF140;

        public const int SC_HOTKEY = 0xF150;

        public const int SC_DEFAULT = 0xF160;

        public const int SC_MONITORPOWER = 0xF170;

        public const int SC_CONTEXTHELP = 0xF180;

        public const int SC_SEPARATOR = 0xF00F;

        public const int SCF_ISSECURE = 0x00000001;

        public const int SC_ICON = SC_MINIMIZE;

        public const int SC_ZOOM = SC_MAXIMIZE;

        public const ushort IDC_ARROW = 32512;

        public const ushort IDC_IBEAM = 32513;

        public const ushort IDC_WAIT = 32514;

        public const ushort IDC_CROSS = 32515;

        public const ushort IDC_UPARROW = 32516;

        [Obsolete("use IDC_SIZEALL")]
        public const ushort IDC_SIZE = 32640;

        [Obsolete("use IDC_ARROW")]
        public const ushort IDC_ICON = 32641;

        public const ushort IDC_SIZENWSE = 32642;

        public const ushort IDC_SIZENESW = 32643;

        public const ushort IDC_SIZEWE = 32644;

        public const ushort IDC_SIZENS = 32645;

        public const ushort IDC_SIZEALL = 32646;

        public const ushort IDC_NO = 32648;

        public const ushort IDC_HAND = 32649;

        public const int IDC_APPSTARTING = 32650;

        public const int IDC_HELP = 32651;

        public const int IDC_PIN = 32671;

        public const int IDC_PERSON = 32672;

        public const int IMAGE_BITMAP = 0;

        public const int IMAGE_ICON = 1;

        public const int IMAGE_CURSOR = 2;

        public const int IMAGE_ENHMETAFILE = 3;

        public const int LR_DEFAULTCOLOR = 0x00000000;

        public const int LR_MONOCHROME = 0x00000001;

        public const int LR_COLOR = 0x00000002;

        public const int LR_COPYRETURNORG = 0x00000004;

        public const int LR_COPYDELETEORG = 0x00000008;

        public const int LR_LOADFROMFILE = 0x00000010;

        public const int LR_LOADTRANSPARENT = 0x00000020;

        public const int LR_DEFAULTSIZE = 0x00000040;

        public const int LR_VGACOLOR = 0x00000080;

        public const int LR_LOADMAP3DCOLORS = 0x00001000;

        public const int LR_CREATEDIBSECTION = 0x00002000;

        public const int LR_COPYFROMRESOURCE = 0x00004000;

        public const int LR_SHARED = 0x00008000;

        public const int RES_ICON = 1;

        public const int RES_CURSOR = 2;

        public const int OBM_CLOSE = 32754;

        public const int OBM_UPARROW = 32753;

        public const int OBM_DNARROW = 32752;

        public const int OBM_RGARROW = 32751;

        public const int OBM_LFARROW = 32750;

        public const int OBM_REDUCE = 32749;

        public const int OBM_ZOOM = 32748;

        public const int OBM_RESTORE = 32747;

        public const int OBM_REDUCED = 32746;

        public const int OBM_ZOOMD = 32745;

        public const int OBM_RESTORED = 32744;

        public const int OBM_UPARROWD = 32743;

        public const int OBM_DNARROWD = 32742;

        public const int OBM_RGARROWD = 32741;

        public const int OBM_LFARROWD = 32740;

        public const int OBM_MNARROW = 32739;

        public const int OBM_COMBO = 32738;

        public const int OBM_UPARROWI = 32737;

        public const int OBM_DNARROWI = 32736;

        public const int OBM_RGARROWI = 32735;

        public const int OBM_LFARROWI = 32734;

        public const int OBM_OLD_CLOSE = 32767;

        public const int OBM_SIZE = 32766;

        public const int OBM_OLD_UPARROW = 32765;

        public const int OBM_OLD_DNARROW = 32764;

        public const int OBM_OLD_RGARROW = 32763;

        public const int OBM_OLD_LFARROW = 32762;

        public const int OBM_BTSIZE = 32761;

        public const int OBM_CHECK = 32760;

        public const int OBM_CHECKBOXES = 32759;

        public const int OBM_BTNCORNERS = 32758;

        public const int OBM_OLD_REDUCE = 32757;

        public const int OBM_OLD_ZOOM = 32756;

        public const int OBM_OLD_RESTORE = 32755;

        public const int OCR_NORMAL = 32512;

        public const int OCR_IBEAM = 32513;

        public const int OCR_WAIT = 32514;

        public const int OCR_CROSS = 32515;

        public const int OCR_UP = 32516;

        [Obsolete("use OCR_SIZEALL")]
        public const int OCR_SIZE = 32640;

        [Obsolete("use OCR_NORMAL")]
        public const int OCR_ICON = 32641;

        public const int OCR_SIZENWSE = 32642;

        public const int OCR_SIZENESW = 32643;

        public const int OCR_SIZEWE = 32644;

        public const int OCR_SIZENS = 32645;

        public const int OCR_SIZEALL = 32646;

        [Obsolete("use OIC_WINLOGO")]
        public const int OCR_ICOCUR = 32647;

        public const int OCR_NO = 32648;

        public const int OCR_HAND = 32649;

        public const int OCR_APPSTARTING = 32650;

        public const int OIC_SAMPLE = 32512;

        public const int OIC_HAND = 32513;

        public const int OIC_QUES = 32514;

        public const int OIC_BANG = 32515;

        public const int OIC_NOTE = 32516;

        public const int OIC_WINLOGO = 32517;

        public const int OIC_WARNING = OIC_BANG;

        public const int OIC_ERROR = OIC_HAND;

        public const int OIC_INFORMATION = OIC_NOTE;

        public const int OIC_SHIELD = 32518;

        public const int ORD_LANGDRIVER = 1;

        public const ushort IDI_APPLICATION = 32512;

        public const ushort IDI_HAND = 32513;

        public const ushort IDI_QUESTION = 32514;

        public const ushort IDI_EXCLAMATION = 32515;

        public const ushort IDI_ASTERISK = 32516;

        public const ushort IDI_WINLOGO = 32517;

        public const ushort IDI_SHIELD = 32518;

        public const ushort IDI_WARNING = IDI_EXCLAMATION;

        public const ushort IDI_ERROR = IDI_HAND;

        public const ushort IDI_INFORMATION = IDI_ASTERISK;

        public const int IDOK = 1;

        public const int IDCANCEL = 2;

        public const int IDABORT = 3;

        public const int IDRETRY = 4;

        public const int IDIGNORE = 5;

        public const int IDYES = 6;

        public const int IDNO = 7;

        public const int IDCLOSE = 8;

        public const int IDHELP = 9;

        public const int IDTRYAGAIN = 10;

        public const int IDCONTINUE = 11;

        public const int IDTIMEOUT = 32000;

        public const int ES_LEFT = 0x0000;

        public const int ES_CENTER = 0x0001;

        public const int ES_RIGHT = 0x0002;

        public const int ES_MULTILINE = 0x0004;

        public const int ES_UPPERCASE = 0x0008;

        public const int ES_LOWERCASE = 0x0010;

        public const int ES_PASSWORD = 0x0020;

        public const int ES_AUTOVSCROLL = 0x0040;

        public const int ES_AUTOHSCROLL = 0x0080;

        public const int ES_NOHIDESEL = 0x0100;

        public const int ES_OEMCONVERT = 0x0400;

        public const int ES_READONLY = 0x0800;

        public const int ES_WANTRETURN = 0x1000;

        public const int ES_NUMBER = 0x2000;

        public const int EN_SETFOCUS = 0x0100;

        public const int EN_KILLFOCUS = 0x0200;

        public const int EN_CHANGE = 0x0300;

        public const int EN_UPDATE = 0x0400;

        public const int EN_ERRSPACE = 0x0500;

        public const int EN_MAXTEXT = 0x0501;

        public const int EN_HSCROLL = 0x0601;

        public const int EN_VSCROLL = 0x0602;

        public const int EN_ALIGN_LTR_EC = 0x0700;

        public const int EN_ALIGN_RTL_EC = 0x0701;

        public const int EN_BEFORE_PASTE = 0x0800;

        public const int EN_AFTER_PASTE = 0x0801;

        public const int EC_LEFTMARGIN = 0x0001;

        public const int EC_RIGHTMARGIN = 0x0002;

        public const int EC_USEFONTINFO = 0xFFFF;

        public const int EMSIS_COMPOSITIONSTRING = 0x0001;

        public const int EIMES_GETCOMPSTRATONCE = 0x0001;

        public const int EIMES_CANCELCOMPSTRINFOCUS = 0x0002;

        public const int EIMES_COMPLETECOMPSTRKILLFOCUS = 0x0004;

        public const int EM_GETSEL = 0x00B0;

        public const int EM_SETSEL = 0x00B1;

        public const int EM_GETRECT = 0x00B2;

        public const int EM_SETRECT = 0x00B3;

        public const int EM_SETRECTNP = 0x00B4;

        public const int EM_SCROLL = 0x00B5;

        public const int EM_LINESCROLL = 0x00B6;

        public const int EM_SCROLLCARET = 0x00B7;

        public const int EM_GETMODIFY = 0x00B8;

        public const int EM_SETMODIFY = 0x00B9;

        public const int EM_GETLINECOUNT = 0x00BA;

        public const int EM_LINEINDEX = 0x00BB;

        public const int EM_SETHANDLE = 0x00BC;

        public const int EM_GETHANDLE = 0x00BD;

        public const int EM_GETTHUMB = 0x00BE;

        public const int EM_LINELENGTH = 0x00C1;

        public const int EM_REPLACESEL = 0x00C2;

        public const int EM_GETLINE = 0x00C4;

        public const int EM_LIMITTEXT = 0x00C5;

        public const int EM_CANUNDO = 0x00C6;

        public const int EM_UNDO = 0x00C7;

        public const int EM_FMTLINES = 0x00C8;

        public const int EM_LINEFROMCHAR = 0x00C9;

        public const int EM_SETTABSTOPS = 0x00CB;

        public const int EM_SETPASSWORDCHAR = 0x00CC;

        public const int EM_EMPTYUNDOBUFFER = 0x00CD;

        public const int EM_GETFIRSTVISIBLELINE = 0x00CE;

        public const int EM_SETREADONLY = 0x00CF;

        public const int EM_SETWORDBREAKPROC = 0x00D0;

        public const int EM_GETWORDBREAKPROC = 0x00D1;

        public const int EM_GETPASSWORDCHAR = 0x00D2;

        public const int EM_SETMARGINS = 0x00D3;

        public const int EM_GETMARGINS = 0x00D4;

        public const int EM_SETLIMITTEXT = EM_LIMITTEXT;

        public const int EM_GETLIMITTEXT = 0x00D5;

        public const int EM_POSFROMCHAR = 0x00D6;

        public const int EM_CHARFROMPOS = 0x00D7;

        public const int EM_SETIMESTATUS = 0x00D8;

        public const int EM_GETIMESTATUS = 0x00D9;

        public const int EM_ENABLEFEATURE = 0x00DA;

        public const int WB_LEFT = 0;

        public const int WB_RIGHT = 1;

        public const int WB_ISDELIMITER = 2;

        public const int BS_PUSHBUTTON = 0x00000000;

        public const int BS_DEFPUSHBUTTON = 0x00000001;

        public const int BS_CHECKBOX = 0x00000002;

        public const int BS_AUTOCHECKBOX = 0x00000003;

        public const int BS_RADIOBUTTON = 0x00000004;

        public const int BS_3STATE = 0x00000005;

        public const int BS_AUTO3STATE = 0x00000006;

        public const int BS_GROUPBOX = 0x00000007;

        public const int BS_USERBUTTON = 0x00000008;

        public const int BS_AUTORADIOBUTTON = 0x00000009;

        public const int BS_PUSHBOX = 0x0000000A;

        public const int BS_OWNERDRAW = 0x0000000B;

        public const int BS_TYPEMASK = 0x0000000F;

        public const int BS_LEFTTEXT = 0x00000020;

        public const int BS_TEXT = 0x00000000;

        public const int BS_ICON = 0x00000040;

        public const int BS_BITMAP = 0x00000080;

        public const int BS_LEFT = 0x00000100;

        public const int BS_RIGHT = 0x00000200;

        public const int BS_CENTER = 0x00000300;

        public const int BS_TOP = 0x00000400;

        public const int BS_BOTTOM = 0x00000800;

        public const int BS_VCENTER = 0x00000C00;

        public const int BS_PUSHLIKE = 0x00001000;

        public const int BS_MULTILINE = 0x00002000;

        public const int BS_NOTIFY = 0x00004000;

        public const int BS_FLAT = 0x00008000;

        public const int BS_RIGHTBUTTON = BS_LEFTTEXT;

        public const int BN_CLICKED = 0;

        public const int BN_PAINT = 1;

        public const int BN_HILITE = 2;

        public const int BN_UNHILITE = 3;

        public const int BN_DISABLE = 4;

        public const int BN_DOUBLECLICKED = 5;

        public const int BN_PUSHED = BN_HILITE;

        public const int BN_UNPUSHED = BN_UNHILITE;

        public const int BN_DBLCLK = BN_DOUBLECLICKED;

        public const int BN_SETFOCUS = 6;

        public const int BN_KILLFOCUS = 7;

        public const int BM_GETCHECK = 0x00F0;

        public const int BM_SETCHECK = 0x00F1;

        public const int BM_GETSTATE = 0x00F2;

        public const int BM_SETSTATE = 0x00F3;

        public const int BM_SETSTYLE = 0x00F4;

        public const int BM_CLICK = 0x00F5;

        public const int BM_GETIMAGE = 0x00F6;

        public const int BM_SETIMAGE = 0x00F7;

        public const int BM_SETDONTCLICK = 0x00F8;

        public const int BST_UNCHECKED = 0x0000;

        public const int BST_CHECKED = 0x0001;

        public const int BST_INDETERMINATE = 0x0002;

        public const int BST_PUSHED = 0x0004;

        public const int BST_FOCUS = 0x0008;

        public const int SS_LEFT = 0x00000000;

        public const int SS_CENTER = 0x00000001;

        public const int SS_RIGHT = 0x00000002;

        public const int SS_ICON = 0x00000003;

        public const int SS_BLACKRECT = 0x00000004;

        public const int SS_GRAYRECT = 0x00000005;

        public const int SS_WHITERECT = 0x00000006;

        public const int SS_BLACKFRAME = 0x00000007;

        public const int SS_GRAYFRAME = 0x00000008;

        public const int SS_WHITEFRAME = 0x00000009;

        public const int SS_USERITEM = 0x0000000A;

        public const int SS_SIMPLE = 0x0000000B;

        public const int SS_LEFTNOWORDWRAP = 0x0000000C;

        public const int SS_OWNERDRAW = 0x0000000D;

        public const int SS_BITMAP = 0x0000000E;

        public const int SS_ENHMETAFILE = 0x0000000F;

        public const int SS_ETCHEDHORZ = 0x00000010;

        public const int SS_ETCHEDVERT = 0x00000011;

        public const int SS_ETCHEDFRAME = 0x00000012;

        public const int SS_TYPEMASK = 0x0000001F;

        public const int SS_REALSIZECONTROL = 0x00000040;

        public const int SS_NOPREFIX = 0x00000080;

        public const int SS_NOTIFY = 0x00000100;

        public const int SS_CENTERIMAGE = 0x00000200;

        public const int SS_RIGHTJUST = 0x00000400;

        public const int SS_REALSIZEIMAGE = 0x00000800;

        public const int SS_SUNKEN = 0x00001000;

        public const int SS_EDITCONTROL = 0x00002000;

        public const int SS_ENDELLIPSIS = 0x00004000;

        public const int SS_PATHELLIPSIS = 0x00008000;

        public const int SS_WORDELLIPSIS = 0x0000C000;

        public const int SS_ELLIPSISMASK = 0x0000C000;

        public const int STM_SETICON = 0x0170;

        public const int STM_GETICON = 0x0171;

        public const int STM_SETIMAGE = 0x0172;

        public const int STM_GETIMAGE = 0x0173;

        public const int STN_CLICKED = 0;

        public const int STN_DBLCLK = 1;

        public const int STN_ENABLE = 2;

        public const int STN_DISABLE = 3;

        public const int STM_MSGMAX = 0x0174;

        // MAKEINTATOM(0x8002)
        public const ushort WC_DIALOG = 0x8002;

        public const int DWL_MSGRESULT = 0;

        public const int DWL_DLGPROC = 4;

        public const int DWL_USER = 8;

        public const int DWLP_MSGRESULT = 0;

        public const int DDL_READWRITE = 0x0000;

        public const int DDL_READONLY = 0x0001;

        public const int DDL_HIDDEN = 0x0002;

        public const int DDL_SYSTEM = 0x0004;

        public const int DDL_DIRECTORY = 0x0010;

        public const int DDL_ARCHIVE = 0x0020;

        public const int DDL_POSTMSGS = 0x2000;

        public const int DDL_DRIVES = 0x4000;

        public const int DDL_EXCLUSIVE = 0x8000;

        public const int DS_ABSALIGN = 0x01;

        public const int DS_SYSMODAL = 0x02;

        public const int DS_LOCALEDIT = 0x20;

        public const int DS_SETFONT = 0x40;

        public const int DS_MODALFRAME = 0x80;

        public const int DS_NOIDLEMSG = 0x100;

        public const int DS_SETFOREGROUND = 0x200;

        public const int DS_3DLOOK = 0x0004;

        public const int DS_FIXEDSYS = 0x0008;

        public const int DS_NOFAILCREATE = 0x0010;

        public const int DS_CONTROL = 0x0400;

        public const int DS_CENTER = 0x0800;

        public const int DS_CENTERMOUSE = 0x1000;

        public const int DS_CONTEXTHELP = 0x2000;

        public const int DS_SHELLFONT = DS_SETFONT | DS_FIXEDSYS;

        public const int DS_USEPIXELS = 0x8000;

        public const int DM_GETDEFID = WM_USER + 0;

        public const int DM_SETDEFID = WM_USER + 1;

        public const int DM_REPOSITION = WM_USER + 2;

        public const int DC_HASDEFID = 0x534B;

        public const int DLGC_WANTARROWS = 0x0001;

        public const int DLGC_WANTTAB = 0x0002;

        public const int DLGC_WANTALLKEYS = 0x0004;

        public const int DLGC_WANTMESSAGE = 0x0004;

        public const int DLGC_HASSETSEL = 0x0008;

        public const int DLGC_DEFPUSHBUTTON = 0x0010;

        public const int DLGC_UNDEFPUSHBUTTON = 0x0020;

        public const int DLGC_RADIOBUTTON = 0x0040;

        public const int DLGC_WANTCHARS = 0x0080;

        public const int DLGC_STATIC = 0x0100;

        public const int DLGC_BUTTON = 0x2000;

        public const int LB_CTLCODE = 0;

        public const int LB_OKAY = 0;

        public const int LB_ERR = -1;

        public const int LB_ERRSPACE = -2;

        public const int LBN_ERRSPACE = -2;

        public const int LBN_SELCHANGE = 1;

        public const int LBN_DBLCLK = 2;

        public const int LBN_SELCANCEL = 3;

        public const int LBN_SETFOCUS = 4;

        public const int LBN_KILLFOCUS = 5;

        public const int LB_ADDSTRING = 0x0180;

        public const int LB_INSERTSTRING = 0x0181;

        public const int LB_DELETESTRING = 0x0182;

        public const int LB_SELITEMRANGEEX = 0x0183;

        public const int LB_RESETCONTENT = 0x0184;

        public const int LB_SETSEL = 0x0185;

        public const int LB_SETCURSEL = 0x0186;

        public const int LB_GETSEL = 0x0187;

        public const int LB_GETCURSEL = 0x0188;

        public const int LB_GETTEXT = 0x0189;

        public const int LB_GETTEXTLEN = 0x018A;

        public const int LB_GETCOUNT = 0x018B;

        public const int LB_SELECTSTRING = 0x018C;

        public const int LB_DIR = 0x018D;

        public const int LB_GETTOPINDEX = 0x018E;

        public const int LB_FINDSTRING = 0x018F;

        public const int LB_GETSELCOUNT = 0x0190;

        public const int LB_GETSELITEMS = 0x0191;

        public const int LB_SETTABSTOPS = 0x0192;

        public const int LB_GETHORIZONTALEXTENT = 0x0193;

        public const int LB_SETHORIZONTALEXTENT = 0x0194;

        public const int LB_SETCOLUMNWIDTH = 0x0195;

        public const int LB_ADDFILE = 0x0196;

        public const int LB_SETTOPINDEX = 0x0197;

        public const int LB_GETITEMRECT = 0x0198;

        public const int LB_GETITEMDATA = 0x0199;

        public const int LB_SETITEMDATA = 0x019A;

        public const int LB_SELITEMRANGE = 0x019B;

        public const int LB_SETANCHORINDEX = 0x019C;

        public const int LB_GETANCHORINDEX = 0x019D;

        public const int LB_SETCARETINDEX = 0x019E;

        public const int LB_GETCARETINDEX = 0x019F;

        public const int LB_SETITEMHEIGHT = 0x01A0;

        public const int LB_GETITEMHEIGHT = 0x01A1;

        public const int LB_FINDSTRINGEXACT = 0x01A2;

        public const int LB_SETLOCALE = 0x01A5;

        public const int LB_GETLOCALE = 0x01A6;

        public const int LB_SETCOUNT = 0x01A7;

        public const int LB_INITSTORAGE = 0x01A8;

        public const int LB_ITEMFROMPOINT = 0x01A9;

        public const int LB_MULTIPLEADDSTRING = 0x01B1;

        public const int LB_GETLISTBOXINFO = 0x01B2;

        public const int LB_MSGMAX = 0x01B3;

        public const uint LBS_NOTIFY = 0x0001;

        public const uint LBS_SORT = 0x0002;

        public const uint LBS_NOREDRAW = 0x0004;

        public const uint LBS_MULTIPLESEL = 0x0008;

        public const uint LBS_OWNERDRAWFIXED = 0x0010;

        public const uint LBS_OWNERDRAWVARIABLE = 0x0020;

        public const uint LBS_HASSTRINGS = 0x0040;

        public const uint LBS_USETABSTOPS = 0x0080;

        public const uint LBS_NOINTEGRALHEIGHT = 0x0100;

        public const uint LBS_MULTICOLUMN = 0x0200;

        public const uint LBS_WANTKEYBOARDINPUT = 0x0400;

        public const uint LBS_EXTENDEDSEL = 0x0800;

        public const uint LBS_DISABLENOSCROLL = 0x1000;

        public const uint LBS_NODATA = 0x2000;

        public const uint LBS_NOSEL = 0x4000;

        public const uint LBS_COMBOBOX = 0x8000;

        public const uint LBS_STANDARD = LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER;

        public const int CB_OKAY = 0;

        public const int CB_ERR = -1;

        public const int CB_ERRSPACE = -2;

        public const int CBN_ERRSPACE = -1;

        public const int CBN_SELCHANGE = 1;

        public const int CBN_DBLCLK = 2;

        public const int CBN_SETFOCUS = 3;

        public const int CBN_KILLFOCUS = 4;

        public const int CBN_EDITCHANGE = 5;

        public const int CBN_EDITUPDATE = 6;

        public const int CBN_DROPDOWN = 7;

        public const int CBN_CLOSEUP = 8;

        public const int CBN_SELENDOK = 9;

        public const int CBN_SELENDCANCEL = 10;

        public const int CBS_SIMPLE = 0x0001;

        public const int CBS_DROPDOWN = 0x0002;

        public const int CBS_DROPDOWNLIST = 0x0003;

        public const int CBS_OWNERDRAWFIXED = 0x0010;

        public const int CBS_OWNERDRAWVARIABLE = 0x0020;

        public const int CBS_AUTOHSCROLL = 0x0040;

        public const int CBS_OEMCONVERT = 0x0080;

        public const int CBS_SORT = 0x0100;

        public const int CBS_HASSTRINGS = 0x0200;

        public const int CBS_NOINTEGRALHEIGHT = 0x0400;

        public const int CBS_DISABLENOSCROLL = 0x0800;

        public const int CBS_UPPERCASE = 0x2000;

        public const int CBS_LOWERCASE = 0x4000;

        public const int CB_GETEDITSEL = 0x0140;

        public const int CB_LIMITTEXT = 0x0141;

        public const int CB_SETEDITSEL = 0x0142;

        public const int CB_ADDSTRING = 0x0143;

        public const int CB_DELETESTRING = 0x0144;

        public const int CB_DIR = 0x0145;

        public const int CB_GETCOUNT = 0x0146;

        public const int CB_GETCURSEL = 0x0147;

        public const int CB_GETLBTEXT = 0x0148;

        public const int CB_GETLBTEXTLEN = 0x0149;

        public const int CB_INSERTSTRING = 0x014A;

        public const int CB_RESETCONTENT = 0x014B;

        public const int CB_FINDSTRING = 0x014C;

        public const int CB_SELECTSTRING = 0x014D;

        public const int CB_SETCURSEL = 0x014E;

        public const int CB_SHOWDROPDOWN = 0x014F;

        public const int CB_GETITEMDATA = 0x0150;

        public const int CB_SETITEMDATA = 0x0151;

        public const int CB_GETDROPPEDCONTROLRECT = 0x0152;

        public const int CB_SETITEMHEIGHT = 0x0153;

        public const int CB_GETITEMHEIGHT = 0x0154;

        public const int CB_SETEXTENDEDUI = 0x0155;

        public const int CB_GETEXTENDEDUI = 0x0156;

        public const int CB_GETDROPPEDSTATE = 0x0157;

        public const int CB_FINDSTRINGEXACT = 0x0158;

        public const int CB_SETLOCALE = 0x0159;

        public const int CB_GETLOCALE = 0x015A;

        public const int CB_GETTOPINDEX = 0x015b;

        public const int CB_SETTOPINDEX = 0x015c;

        public const int CB_GETHORIZONTALEXTENT = 0x015d;

        public const int CB_SETHORIZONTALEXTENT = 0x015e;

        public const int CB_GETDROPPEDWIDTH = 0x015f;

        public const int CB_SETDROPPEDWIDTH = 0x0160;

        public const int CB_INITSTORAGE = 0x0161;

        public const int CB_MULTIPLEADDSTRING = 0x0163;

        public const int CB_GETCOMBOBOXINFO = 0x0164;

        public const int CB_MSGMAX = 0x0165;

        public const int SBS_HORZ = 0x0000;

        public const int SBS_VERT = 0x0001;

        public const int SBS_TOPALIGN = 0x0002;

        public const int SBS_LEFTALIGN = 0x0002;

        public const int SBS_BOTTOMALIGN = 0x0004;

        public const int SBS_RIGHTALIGN = 0x0004;

        public const int SBS_SIZEBOXTOPLEFTALIGN = 0x0002;

        public const int SBS_SIZEBOXBOTTOMRIGHTALIGN = 0x0004;

        public const int SBS_SIZEBOX = 0x0008;

        public const int SBS_SIZEGRIP = 0x0010;

        public const int SBM_SETPOS = 0x00E0;

        public const int SBM_GETPOS = 0x00E1;

        public const int SBM_SETRANGE = 0x00E2;

        public const int SBM_SETRANGEREDRAW = 0x00E6;

        public const int SBM_GETRANGE = 0x00E3;

        public const int SBM_ENABLE_ARROWS = 0x00E4;

        public const int SBM_SETSCROLLINFO = 0x00E9;

        public const int SBM_GETSCROLLINFO = 0x00EA;

        public const int SBM_GETSCROLLBARINFO = 0x00EB;

        public const int SIF_RANGE = 0x0001;

        public const int SIF_PAGE = 0x0002;

        public const int SIF_POS = 0x0004;

        public const int SIF_DISABLENOSCROLL = 0x0008;

        public const int SIF_TRACKPOS = 0x0010;

        public const int SIF_ALL = SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS;

        public const int MDIS_ALLCHILDSTYLES = 0x0001;

        public const int MDITILE_VERTICAL = 0x0000;

        public const int MDITILE_HORIZONTAL = 0x0001;

        public const int MDITILE_SKIPDISABLED = 0x0002;

        public const int MDITILE_ZORDER = 0x0004;

        public const int HELP_CONTEXT = 0x0001;

        public const int HELP_QUIT = 0x0002;

        public const int HELP_INDEX = 0x0003;

        public const int HELP_CONTENTS = 0x0003;

        public const int HELP_HELPONHELP = 0x0004;

        public const int HELP_SETINDEX = 0x0005;

        public const int HELP_SETCONTENTS = 0x0005;

        public const int HELP_CONTEXTPOPUP = 0x0008;

        public const int HELP_FORCEFILE = 0x0009;

        public const int HELP_KEY = 0x0101;

        public const int HELP_COMMAND = 0x0102;

        public const int HELP_PARTIALKEY = 0x0105;

        public const int HELP_MULTIKEY = 0x0201;

        public const int HELP_SETWINPOS = 0x0203;

        public const int HELP_CONTEXTMENU = 0x000a;

        public const int HELP_FINDER = 0x000b;

        public const int HELP_WM_HELP = 0x000c;

        public const int HELP_SETPOPUP_POS = 0x000d;

        public const int HELP_TCARD = 0x8000;

        public const int HELP_TCARD_DATA = 0x0010;

        public const int HELP_TCARD_OTHER_CALLER = 0x0011;

        public const int IDH_NO_HELP = 28440;

        public const int IDH_MISSING_CONTEXT = 28441;

        public const int IDH_GENERIC_HELP_BUTTON = 28442;

        public const int IDH_OK = 28443;

        public const int IDH_CANCEL = 28444;

        public const int IDH_HELP = 28445;

        public const int GR_GDIOBJECTS = 0;

        public const int GR_USEROBJECTS = 1;

        public const int GR_GDIOBJECTS_PEAK = 2;

        public const int GR_USEROBJECTS_PEAK = 4;

        public const int GR_GLOBAL = -2;

        public const int SPI_GETBEEP = 0x0001;

        public const int SPI_SETBEEP = 0x0002;

        public const int SPI_GETMOUSE = 0x0003;

        public const int SPI_SETMOUSE = 0x0004;

        public const int SPI_GETBORDER = 0x0005;

        public const int SPI_SETBORDER = 0x0006;

        public const int SPI_GETKEYBOARDSPEED = 0x000A;

        public const int SPI_SETKEYBOARDSPEED = 0x000B;

        public const int SPI_LANGDRIVER = 0x000C;

        public const int SPI_ICONHORIZONTALSPACING = 0x000D;

        public const int SPI_GETSCREENSAVETIMEOUT = 0x000E;

        public const int SPI_SETSCREENSAVETIMEOUT = 0x000F;

        public const int SPI_GETSCREENSAVEACTIVE = 0x0010;

        public const int SPI_SETSCREENSAVEACTIVE = 0x0011;

        public const int SPI_GETGRIDGRANULARITY = 0x0012;

        public const int SPI_SETGRIDGRANULARITY = 0x0013;

        public const int SPI_SETDESKWALLPAPER = 0x0014;

        public const int SPI_SETDESKPATTERN = 0x0015;

        public const int SPI_GETKEYBOARDDELAY = 0x0016;

        public const int SPI_SETKEYBOARDDELAY = 0x0017;

        public const int SPI_ICONVERTICALSPACING = 0x0018;

        public const int SPI_GETICONTITLEWRAP = 0x0019;

        public const int SPI_SETICONTITLEWRAP = 0x001A;

        public const int SPI_GETMENUDROPALIGNMENT = 0x001B;

        public const int SPI_SETMENUDROPALIGNMENT = 0x001C;

        public const int SPI_SETDOUBLECLKWIDTH = 0x001D;

        public const int SPI_SETDOUBLECLKHEIGHT = 0x001E;

        public const int SPI_GETICONTITLELOGFONT = 0x001F;

        public const int SPI_SETDOUBLECLICKTIME = 0x0020;

        public const int SPI_SETMOUSEBUTTONSWAP = 0x0021;

        public const int SPI_SETICONTITLELOGFONT = 0x0022;

        public const int SPI_GETFASTTASKSWITCH = 0x0023;

        public const int SPI_SETFASTTASKSWITCH = 0x0024;

        public const int SPI_SETDRAGFULLWINDOWS = 0x0025;

        public const int SPI_GETDRAGFULLWINDOWS = 0x0026;

        public const int SPI_GETNONCLIENTMETRICS = 0x0029;

        public const int SPI_SETNONCLIENTMETRICS = 0x002A;

        public const int SPI_GETMINIMIZEDMETRICS = 0x002B;

        public const int SPI_SETMINIMIZEDMETRICS = 0x002C;

        public const int SPI_GETICONMETRICS = 0x002D;

        public const int SPI_SETICONMETRICS = 0x002E;

        public const int SPI_SETWORKAREA = 0x002F;

        public const int SPI_GETWORKAREA = 0x0030;

        public const int SPI_SETPENWINDOWS = 0x0031;

        public const int SPI_GETHIGHCONTRAST = 0x0042;

        public const int SPI_SETHIGHCONTRAST = 0x0043;

        public const int SPI_GETKEYBOARDPREF = 0x0044;

        public const int SPI_SETKEYBOARDPREF = 0x0045;

        public const int SPI_GETSCREENREADER = 0x0046;

        public const int SPI_SETSCREENREADER = 0x0047;

        public const int SPI_GETANIMATION = 0x0048;

        public const int SPI_SETANIMATION = 0x0049;

        public const int SPI_GETFONTSMOOTHING = 0x004A;

        public const int SPI_SETFONTSMOOTHING = 0x004B;

        public const int SPI_SETDRAGWIDTH = 0x004C;

        public const int SPI_SETDRAGHEIGHT = 0x004D;

        public const int SPI_SETHANDHELD = 0x004E;

        public const int SPI_GETLOWPOWERTIMEOUT = 0x004F;

        public const int SPI_GETPOWEROFFTIMEOUT = 0x0050;

        public const int SPI_SETLOWPOWERTIMEOUT = 0x0051;

        public const int SPI_SETPOWEROFFTIMEOUT = 0x0052;

        public const int SPI_GETLOWPOWERACTIVE = 0x0053;

        public const int SPI_GETPOWEROFFACTIVE = 0x0054;

        public const int SPI_SETLOWPOWERACTIVE = 0x0055;

        public const int SPI_SETPOWEROFFACTIVE = 0x0056;

        public const int SPI_SETCURSORS = 0x0057;

        public const int SPI_SETICONS = 0x0058;

        public const int SPI_GETDEFAULTINPUTLANG = 0x0059;

        public const int SPI_SETDEFAULTINPUTLANG = 0x005A;

        public const int SPI_SETLANGTOGGLE = 0x005B;

        public const int SPI_GETWINDOWSEXTENSION = 0x005C;

        public const int SPI_SETMOUSETRAILS = 0x005D;

        public const int SPI_GETMOUSETRAILS = 0x005E;

        public const int SPI_SETSCREENSAVERRUNNING = 0x0061;

        public const int SPI_SCREENSAVERRUNNING = SPI_SETSCREENSAVERRUNNING;

        public const int SPI_GETFILTERKEYS = 0x0032;

        public const int SPI_SETFILTERKEYS = 0x0033;

        public const int SPI_GETTOGGLEKEYS = 0x0034;

        public const int SPI_SETTOGGLEKEYS = 0x0035;

        public const int SPI_GETMOUSEKEYS = 0x0036;

        public const int SPI_SETMOUSEKEYS = 0x0037;

        public const int SPI_GETSHOWSOUNDS = 0x0038;

        public const int SPI_SETSHOWSOUNDS = 0x0039;

        public const int SPI_GETSTICKYKEYS = 0x003A;

        public const int SPI_SETSTICKYKEYS = 0x003B;

        public const int SPI_GETACCESSTIMEOUT = 0x003C;

        public const int SPI_SETACCESSTIMEOUT = 0x003D;

        public const int SPI_GETSERIALKEYS = 0x003E;

        public const int SPI_SETSERIALKEYS = 0x003F;

        public const int SPI_GETSOUNDSENTRY = 0x0040;

        public const int SPI_SETSOUNDSENTRY = 0x0041;

        public const int SPI_GETSNAPTODEFBUTTON = 0x005F;

        public const int SPI_SETSNAPTODEFBUTTON = 0x0060;

        public const int SPI_GETMOUSEHOVERWIDTH = 0x0062;

        public const int SPI_SETMOUSEHOVERWIDTH = 0x0063;

        public const int SPI_GETMOUSEHOVERHEIGHT = 0x0064;

        public const int SPI_SETMOUSEHOVERHEIGHT = 0x0065;

        public const int SPI_GETMOUSEHOVERTIME = 0x0066;

        public const int SPI_SETMOUSEHOVERTIME = 0x0067;

        public const int SPI_GETWHEELSCROLLLINES = 0x0068;

        public const int SPI_SETWHEELSCROLLLINES = 0x0069;

        public const int SPI_GETMENUSHOWDELAY = 0x006A;

        public const int SPI_SETMENUSHOWDELAY = 0x006B;

        public const int SPI_GETWHEELSCROLLCHARS = 0x006C;

        public const int SPI_SETWHEELSCROLLCHARS = 0x006D;

        public const int SPI_GETSHOWIMEUI = 0x006E;

        public const int SPI_SETSHOWIMEUI = 0x006F;

        public const int SPI_GETMOUSESPEED = 0x0070;

        public const int SPI_SETMOUSESPEED = 0x0071;

        public const int SPI_GETSCREENSAVERRUNNING = 0x0072;

        public const int SPI_GETDESKWALLPAPER = 0x0073;

        public const int SPI_GETAUDIODESCRIPTION = 0x0074;

        public const int SPI_SETAUDIODESCRIPTION = 0x0075;

        public const int SPI_GETSCREENSAVESECURE = 0x0076;

        public const int SPI_SETSCREENSAVESECURE = 0x0077;

        public const int SPI_GETHUNGAPPTIMEOUT = 0x0078;

        public const int SPI_SETHUNGAPPTIMEOUT = 0x0079;

        public const int SPI_GETWAITTOKILLTIMEOUT = 0x007A;

        public const int SPI_SETWAITTOKILLTIMEOUT = 0x007B;

        public const int SPI_GETWAITTOKILLSERVICETIMEOUT = 0x007C;

        public const int SPI_SETWAITTOKILLSERVICETIMEOUT = 0x007D;

        public const int SPI_GETMOUSEDOCKTHRESHOLD = 0x007E;

        public const int SPI_SETMOUSEDOCKTHRESHOLD = 0x007F;

        public const int SPI_GETPENDOCKTHRESHOLD = 0x0080;

        public const int SPI_SETPENDOCKTHRESHOLD = 0x0081;

        public const int SPI_GETWINARRANGING = 0x0082;

        public const int SPI_SETWINARRANGING = 0x0083;

        public const int SPI_GETMOUSEDRAGOUTTHRESHOLD = 0x0084;

        public const int SPI_SETMOUSEDRAGOUTTHRESHOLD = 0x0085;

        public const int SPI_GETPENDRAGOUTTHRESHOLD = 0x0086;

        public const int SPI_SETPENDRAGOUTTHRESHOLD = 0x0087;

        public const int SPI_GETMOUSESIDEMOVETHRESHOLD = 0x0088;

        public const int SPI_SETMOUSESIDEMOVETHRESHOLD = 0x0089;

        public const int SPI_GETPENSIDEMOVETHRESHOLD = 0x008A;

        public const int SPI_SETPENSIDEMOVETHRESHOLD = 0x008B;

        public const int SPI_GETDRAGFROMMAXIMIZE = 0x008C;

        public const int SPI_SETDRAGFROMMAXIMIZE = 0x008D;

        public const int SPI_GETSNAPSIZING = 0x008E;

        public const int SPI_SETSNAPSIZING = 0x008F;

        public const int SPI_GETDOCKMOVING = 0x0090;

        public const int SPI_SETDOCKMOVING = 0x0091;

        public const int MAX_TOUCH_PREDICTION_FILTER_TAPS = 3;

        public const int TOUCHPREDICTIONPARAMETERS_DEFAULT_LATENCY = 8;

        public const int TOUCHPREDICTIONPARAMETERS_DEFAULT_SAMPLETIME = 8;

        public const int TOUCHPREDICTIONPARAMETERS_DEFAULT_USE_HW_TIMESTAMP = 1;

        public const float TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_DELTA = 0.001f;

        public const float TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_MIN = 0.9f;

        public const float TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_MAX = 0.999f;

        public const float TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_LEARNING_RATE = 0.001f;

        public const float TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_EXPO_SMOOTH_ALPHA = 0.99f;

        public const int SPI_GETTOUCHPREDICTIONPARAMETERS = 0x009C;

        public const int SPI_SETTOUCHPREDICTIONPARAMETERS = 0x009D;

        public const int MAX_LOGICALDPIOVERRIDE = 2;

        public const int MIN_LOGICALDPIOVERRIDE = -2;

        public const int SPI_GETLOGICALDPIOVERRIDE = 0x009E;

        public const int SPI_SETLOGICALDPIOVERRIDE = 0x009F;

        public const int SPI_GETMENURECT = 0x00A2;

        public const int SPI_SETMENURECT = 0x00A3;

        public const int SPI_GETACTIVEWINDOWTRACKING = 0x1000;

        public const int SPI_SETACTIVEWINDOWTRACKING = 0x1001;

        public const int SPI_GETMENUANIMATION = 0x1002;

        public const int SPI_SETMENUANIMATION = 0x1003;

        public const int SPI_GETCOMBOBOXANIMATION = 0x1004;

        public const int SPI_SETCOMBOBOXANIMATION = 0x1005;

        public const int SPI_GETLISTBOXSMOOTHSCROLLING = 0x1006;

        public const int SPI_SETLISTBOXSMOOTHSCROLLING = 0x1007;

        public const int SPI_GETGRADIENTCAPTIONS = 0x1008;

        public const int SPI_SETGRADIENTCAPTIONS = 0x1009;

        public const int SPI_GETKEYBOARDCUES = 0x100A;

        public const int SPI_SETKEYBOARDCUES = 0x100B;

        public const int SPI_GETMENUUNDERLINES = SPI_GETKEYBOARDCUES;

        public const int SPI_SETMENUUNDERLINES = SPI_SETKEYBOARDCUES;

        public const int SPI_GETACTIVEWNDTRKZORDER = 0x100C;

        public const int SPI_SETACTIVEWNDTRKZORDER = 0x100D;

        public const int SPI_GETHOTTRACKING = 0x100E;

        public const int SPI_SETHOTTRACKING = 0x100F;

        public const int SPI_GETMENUFADE = 0x1012;

        public const int SPI_SETMENUFADE = 0x1013;

        public const int SPI_GETSELECTIONFADE = 0x1014;

        public const int SPI_SETSELECTIONFADE = 0x1015;

        public const int SPI_GETTOOLTIPANIMATION = 0x1016;

        public const int SPI_SETTOOLTIPANIMATION = 0x1017;

        public const int SPI_GETTOOLTIPFADE = 0x1018;

        public const int SPI_SETTOOLTIPFADE = 0x1019;

        public const int SPI_GETCURSORSHADOW = 0x101A;

        public const int SPI_SETCURSORSHADOW = 0x101B;

        public const int SPI_GETMOUSESONAR = 0x101C;

        public const int SPI_SETMOUSESONAR = 0x101D;

        public const int SPI_GETMOUSECLICKLOCK = 0x101E;

        public const int SPI_SETMOUSECLICKLOCK = 0x101F;

        public const int SPI_GETMOUSEVANISH = 0x1020;

        public const int SPI_SETMOUSEVANISH = 0x1021;

        public const int SPI_GETFLATMENU = 0x1022;

        public const int SPI_SETFLATMENU = 0x1023;

        public const int SPI_GETDROPSHADOW = 0x1024;

        public const int SPI_SETDROPSHADOW = 0x1025;

        public const int SPI_GETBLOCKSENDINPUTRESETS = 0x1026;

        public const int SPI_SETBLOCKSENDINPUTRESETS = 0x1027;

        public const int SPI_GETUIEFFECTS = 0x103E;

        public const int SPI_SETUIEFFECTS = 0x103F;

        public const int SPI_GETDISABLEOVERLAPPEDCONTENT = 0x1040;

        public const int SPI_SETDISABLEOVERLAPPEDCONTENT = 0x1041;

        public const int SPI_GETCLIENTAREAANIMATION = 0x1042;

        public const int SPI_SETCLIENTAREAANIMATION = 0x1043;

        public const int SPI_GETCLEARTYPE = 0x1048;

        public const int SPI_SETCLEARTYPE = 0x1049;

        public const int SPI_GETSPEECHRECOGNITION = 0x104A;

        public const int SPI_SETSPEECHRECOGNITION = 0x104B;

        public const int SPI_GETCARETBROWSING = 0x104C;

        public const int SPI_SETCARETBROWSING = 0x104D;

        public const int SPI_GETTHREADLOCALINPUTSETTINGS = 0x104E;

        public const int SPI_SETTHREADLOCALINPUTSETTINGS = 0x104F;

        public const int SPI_GETSYSTEMLANGUAGEBAR = 0x1050;

        public const int SPI_SETSYSTEMLANGUAGEBAR = 0x1051;

        public const int SPI_GETFOREGROUNDLOCKTIMEOUT = 0x2000;

        public const int SPI_SETFOREGROUNDLOCKTIMEOUT = 0x2001;

        public const int SPI_GETACTIVEWNDTRKTIMEOUT = 0x2002;

        public const int SPI_SETACTIVEWNDTRKTIMEOUT = 0x2003;

        public const int SPI_GETFOREGROUNDFLASHCOUNT = 0x2004;

        public const int SPI_SETFOREGROUNDFLASHCOUNT = 0x2005;

        public const int SPI_GETCARETWIDTH = 0x2006;

        public const int SPI_SETCARETWIDTH = 0x2007;

        public const int SPI_GETMOUSECLICKLOCKTIME = 0x2008;

        public const int SPI_SETMOUSECLICKLOCKTIME = 0x2009;

        public const int SPI_GETFONTSMOOTHINGTYPE = 0x200A;

        public const int SPI_SETFONTSMOOTHINGTYPE = 0x200B;

        public const int FE_FONTSMOOTHINGSTANDARD = 0x0001;

        public const int FE_FONTSMOOTHINGCLEARTYPE = 0x0002;

        public const int SPI_GETFONTSMOOTHINGCONTRAST = 0x200C;

        public const int SPI_SETFONTSMOOTHINGCONTRAST = 0x200D;

        public const int SPI_GETFOCUSBORDERWIDTH = 0x200E;

        public const int SPI_SETFOCUSBORDERWIDTH = 0x200F;

        public const int SPI_GETFOCUSBORDERHEIGHT = 0x2010;

        public const int SPI_SETFOCUSBORDERHEIGHT = 0x2011;

        public const int SPI_GETFONTSMOOTHINGORIENTATION = 0x2012;

        public const int SPI_SETFONTSMOOTHINGORIENTATION = 0x2013;

        public const int FE_FONTSMOOTHINGORIENTATIONBGR = 0x0000;

        public const int FE_FONTSMOOTHINGORIENTATIONRGB = 0x0001;

        public const int SPI_GETMINIMUMHITRADIUS = 0x2014;

        public const int SPI_SETMINIMUMHITRADIUS = 0x2015;

        public const int SPI_GETMESSAGEDURATION = 0x2016;

        public const int SPI_SETMESSAGEDURATION = 0x2017;

        public const int SPI_GETCONTACTVISUALIZATION = 0x2018;

        public const int SPI_SETCONTACTVISUALIZATION = 0x2019;

        public const int CONTACTVISUALIZATION_OFF = 0x0000;

        public const int CONTACTVISUALIZATION_ON = 0x0001;

        public const int CONTACTVISUALIZATION_PRESENTATIONMODE = 0x0002;

        public const int SPI_GETGESTUREVISUALIZATION = 0x201A;

        public const int SPI_SETGESTUREVISUALIZATION = 0x201B;

        public const int GESTUREVISUALIZATION_OFF = 0x0000;

        public const int GESTUREVISUALIZATION_ON = 0x001F;

        public const int GESTUREVISUALIZATION_TAP = 0x0001;

        public const int GESTUREVISUALIZATION_DOUBLETAP = 0x0002;

        public const int GESTUREVISUALIZATION_PRESSANDTAP = 0x0004;

        public const int GESTUREVISUALIZATION_PRESSANDHOLD = 0x0008;

        public const int GESTUREVISUALIZATION_RIGHTTAP = 0x0010;

        public const int SPI_GETMOUSEWHEELROUTING = 0x201C;

        public const int SPI_SETMOUSEWHEELROUTING = 0x201D;

        public const int MOUSEWHEEL_ROUTING_FOCUS = 0;

        public const int MOUSEWHEEL_ROUTING_HYBRID = 1;

        public const int MOUSEWHEEL_ROUTING_MOUSE_POS = 2;

        public const int SPI_GETPENVISUALIZATION = 0x201E;

        public const int SPI_SETPENVISUALIZATION = 0x201F;

        public const int PENVISUALIZATION_ON = 0x0023;

        public const int PENVISUALIZATION_OFF = 0x0000;

        public const int PENVISUALIZATION_TAP = 0x0001;

        public const int PENVISUALIZATION_DOUBLETAP = 0x0002;

        public const int PENVISUALIZATION_CURSOR = 0x0020;

        public const int SPI_GETPENARBITRATIONTYPE = 0x2020;

        public const int SPI_SETPENARBITRATIONTYPE = 0x2021;

        public const int PENARBITRATIONTYPE_NONE = 0x0000;

        public const int PENARBITRATIONTYPE_WIN8 = 0x0001;

        public const int PENARBITRATIONTYPE_FIS = 0x0002;

        public const int PENARBITRATIONTYPE_SPT = 0x0003;

        public const int PENARBITRATIONTYPE_MAX = 0x0004;

        public const int SPI_GETCARETTIMEOUT = 0x2022;

        public const int SPI_SETCARETTIMEOUT = 0x2023;

        public const int SPI_GETHANDEDNESS = 0x2024;

        public const int SPI_SETHANDEDNESS = 0x2025;

        public const int SPIF_UPDATEINIFILE = 0x0001;

        public const int SPIF_SENDWININICHANGE = 0x0002;

        public const int SPIF_SENDCHANGE = SPIF_SENDWININICHANGE;

        public const int METRICS_USEDEFAULT = -1;

        public const int ARW_BOTTOMLEFT = 0x0000;

        public const int ARW_BOTTOMRIGHT = 0x0001;

        public const int ARW_TOPLEFT = 0x0002;

        public const int ARW_TOPRIGHT = 0x0003;

        public const int ARW_STARTMASK = 0x0003;

        public const int ARW_STARTRIGHT = 0x0001;

        public const int ARW_STARTTOP = 0x0002;

        public const int ARW_LEFT = 0x0000;

        public const int ARW_RIGHT = 0x0000;

        public const int ARW_UP = 0x0004;

        public const int ARW_DOWN = 0x0004;

        public const int ARW_HIDE = 0x0008;

        public const int SERKF_SERIALKEYSON = 0x00000001;

        public const int SERKF_AVAILABLE = 0x00000002;

        public const int SERKF_INDICATOR = 0x00000004;

        public const int HCF_HIGHCONTRASTON = 0x00000001;

        public const int HCF_AVAILABLE = 0x00000002;

        public const int HCF_HOTKEYACTIVE = 0x00000004;

        public const int HCF_CONFIRMHOTKEY = 0x00000008;

        public const int HCF_HOTKEYSOUND = 0x00000010;

        public const int HCF_INDICATOR = 0x00000020;

        public const int HCF_HOTKEYAVAILABLE = 0x00000040;

        public const int HCF_LOGONDESKTOP = 0x00000100;

        public const int HCF_DEFAULTDESKTOP = 0x00000200;

        public const int HCF_OPTION_NOTHEMECHANGE = 0x00001000;

        public const int CDS_UPDATEREGISTRY = 0x00000001;

        public const int CDS_TEST = 0x00000002;

        public const int CDS_FULLSCREEN = 0x00000004;

        public const int CDS_GLOBAL = 0x00000008;

        public const int CDS_SET_PRIMARY = 0x00000010;

        public const int CDS_VIDEOPARAMETERS = 0x00000020;

        public const int CDS_ENABLE_UNSAFE_MODES = 0x00000100;

        public const int CDS_DISABLE_UNSAFE_MODES = 0x00000200;

        public const int CDS_RESET = 0x40000000;

        public const int CDS_RESET_EX = 0x20000000;

        public const int CDS_NORESET = 0x10000000;

        public const int DISP_CHANGE_SUCCESSFUL = 0;

        public const int DISP_CHANGE_RESTART = 1;

        public const int DISP_CHANGE_FAILED = -1;

        public const int DISP_CHANGE_BADMODE = -2;

        public const int DISP_CHANGE_NOTUPDATED = -3;

        public const int DISP_CHANGE_BADFLAGS = -4;

        public const int DISP_CHANGE_BADPARAM = -5;

        public const int DISP_CHANGE_BADDUALVIEW = -6;

        public const uint ENUM_CURRENT_SETTINGS = unchecked((uint)-1);

        public const uint ENUM_REGISTRY_SETTINGS = unchecked((uint)-2);

        public const int EDS_RAWMODE = 0x00000002;

        public const int EDS_ROTATEDMODE = 0x00000004;

        public const int EDD_GET_DEVICE_INTERFACE_NAME = 0x00000001;

        public const int FKF_FILTERKEYSON = 0x00000001;

        public const int FKF_AVAILABLE = 0x00000002;

        public const int FKF_HOTKEYACTIVE = 0x00000004;

        public const int FKF_CONFIRMHOTKEY = 0x00000008;

        public const int FKF_HOTKEYSOUND = 0x00000010;

        public const int FKF_INDICATOR = 0x00000020;

        public const int FKF_CLICKON = 0x00000040;

        public const uint SKF_STICKYKEYSON = 0x00000001;

        public const uint SKF_AVAILABLE = 0x00000002;

        public const uint SKF_HOTKEYACTIVE = 0x00000004;

        public const uint SKF_CONFIRMHOTKEY = 0x00000008;

        public const uint SKF_HOTKEYSOUND = 0x00000010;

        public const uint SKF_INDICATOR = 0x00000020;

        public const uint SKF_AUDIBLEFEEDBACK = 0x00000040;

        public const uint SKF_TRISTATE = 0x00000080;

        public const uint SKF_TWOKEYSOFF = 0x00000100;

        public const uint SKF_LALTLATCHED = 0x10000000;

        public const uint SKF_LCTLLATCHED = 0x04000000;

        public const uint SKF_LSHIFTLATCHED = 0x01000000;

        public const uint SKF_RALTLATCHED = 0x20000000;

        public const uint SKF_RCTLLATCHED = 0x08000000;

        public const uint SKF_RSHIFTLATCHED = 0x02000000;

        public const uint SKF_LWINLATCHED = 0x40000000;

        public const uint SKF_RWINLATCHED = 0x80000000;

        public const uint SKF_LALTLOCKED = 0x00100000;

        public const uint SKF_LCTLLOCKED = 0x00040000;

        public const uint SKF_LSHIFTLOCKED = 0x00010000;

        public const uint SKF_RALTLOCKED = 0x00200000;

        public const uint SKF_RCTLLOCKED = 0x00080000;

        public const uint SKF_RSHIFTLOCKED = 0x00020000;

        public const uint SKF_LWINLOCKED = 0x00400000;

        public const uint SKF_RWINLOCKED = 0x00800000;

        public const uint MKF_MOUSEKEYSON = 0x00000001;

        public const uint MKF_AVAILABLE = 0x00000002;

        public const uint MKF_HOTKEYACTIVE = 0x00000004;

        public const uint MKF_CONFIRMHOTKEY = 0x00000008;

        public const uint MKF_HOTKEYSOUND = 0x00000010;

        public const uint MKF_INDICATOR = 0x00000020;

        public const uint MKF_MODIFIERS = 0x00000040;

        public const uint MKF_REPLACENUMBERS = 0x00000080;

        public const uint MKF_LEFTBUTTONSEL = 0x10000000;

        public const uint MKF_RIGHTBUTTONSEL = 0x20000000;

        public const uint MKF_LEFTBUTTONDOWN = 0x01000000;

        public const uint MKF_RIGHTBUTTONDOWN = 0x02000000;

        public const uint MKF_MOUSEMODE = 0x80000000;

        public const int ATF_TIMEOUTON = 0x00000001;

        public const int ATF_ONOFFFEEDBACK = 0x00000002;

        public const int SSGF_NONE = 0;

        public const int SSGF_DISPLAY = 3;

        public const int SSTF_NONE = 0;

        public const int SSTF_CHARS = 1;

        public const int SSTF_BORDER = 2;

        public const int SSTF_DISPLAY = 3;

        public const int SSWF_NONE = 0;

        public const int SSWF_TITLE = 1;

        public const int SSWF_WINDOW = 2;

        public const int SSWF_DISPLAY = 3;

        public const int SSWF_CUSTOM = 4;

        public const int SSF_SOUNDSENTRYON = 0x00000001;

        public const int SSF_AVAILABLE = 0x00000002;

        public const int SSF_INDICATOR = 0x00000004;

        public const int TKF_TOGGLEKEYSON = 0x00000001;

        public const int TKF_AVAILABLE = 0x00000002;

        public const int TKF_HOTKEYACTIVE = 0x00000004;

        public const int TKF_CONFIRMHOTKEY = 0x00000008;

        public const int TKF_HOTKEYSOUND = 0x00000010;

        public const int TKF_INDICATOR = 0x00000020;

        public const int SLE_ERROR = 0x00000001;

        public const int SLE_MINORERROR = 0x00000002;

        public const int SLE_WARNING = 0x00000003;

        public const int MONITOR_DEFAULTTONULL = 0x00000000;

        public const int MONITOR_DEFAULTTOPRIMARY = 0x00000001;

        public const int MONITOR_DEFAULTTONEAREST = 0x00000002;

        public const int MONITORINFOF_PRIMARY = 0x00000001;

        public const int CCHDEVICENAME = 32;

        public const int WINEVENT_OUTOFCONTEXT = 0x0000;

        public const int WINEVENT_SKIPOWNTHREAD = 0x0001;

        public const int WINEVENT_SKIPOWNPROCESS = 0x0002;

        public const int WINEVENT_INCONTEXT = 0x0004;

        public const int CHILDID_SELF = 0;

        public const int INDEXID_OBJECT = 0;

        public const int INDEXID_CONTAINER = 0;

        public const int OBJID_WINDOW = 0x00000000;

        public const int OBJID_SYSMENU = unchecked((int)0xFFFFFFFF);

        public const int OBJID_TITLEBAR = unchecked((int)0xFFFFFFFE);

        public const int OBJID_MENU = unchecked((int)0xFFFFFFFD);

        public const int OBJID_CLIENT = unchecked((int)0xFFFFFFFC);

        public const int OBJID_VSCROLL = unchecked((int)0xFFFFFFFB);

        public const int OBJID_HSCROLL = unchecked((int)0xFFFFFFFA);

        public const int OBJID_SIZEGRIP = unchecked((int)0xFFFFFFF9);

        public const int OBJID_CARET = unchecked((int)0xFFFFFFF8);

        public const int OBJID_CURSOR = unchecked((int)0xFFFFFFF7);

        public const int OBJID_ALERT = unchecked((int)0xFFFFFFF6);

        public const int OBJID_SOUND = unchecked((int)0xFFFFFFF5);

        public const int OBJID_QUERYCLASSNAMEIDX = unchecked((int)0xFFFFFFF4);

        public const int OBJID_NATIVEOM = unchecked((int)0xFFFFFFF0);

        public const int EVENT_MIN = 0x00000001;

        public const int EVENT_MAX = 0x7FFFFFFF;

        public const int EVENT_SYSTEM_SOUND = 0x0001;

        public const int EVENT_SYSTEM_ALERT = 0x0002;

        public const int EVENT_SYSTEM_FOREGROUND = 0x0003;

        public const int EVENT_SYSTEM_MENUSTART = 0x0004;

        public const int EVENT_SYSTEM_MENUEND = 0x0005;

        public const int EVENT_SYSTEM_MENUPOPUPSTART = 0x0006;

        public const int EVENT_SYSTEM_MENUPOPUPEND = 0x0007;

        public const int EVENT_SYSTEM_CAPTURESTART = 0x0008;

        public const int EVENT_SYSTEM_CAPTUREEND = 0x0009;

        public const int EVENT_SYSTEM_MOVESIZESTART = 0x000A;

        public const int EVENT_SYSTEM_MOVESIZEEND = 0x000B;

        public const int EVENT_SYSTEM_CONTEXTHELPSTART = 0x000C;

        public const int EVENT_SYSTEM_CONTEXTHELPEND = 0x000D;

        public const int EVENT_SYSTEM_DRAGDROPSTART = 0x000E;

        public const int EVENT_SYSTEM_DRAGDROPEND = 0x000F;

        public const int EVENT_SYSTEM_DIALOGSTART = 0x0010;

        public const int EVENT_SYSTEM_DIALOGEND = 0x0011;

        public const int EVENT_SYSTEM_SCROLLINGSTART = 0x0012;

        public const int EVENT_SYSTEM_SCROLLINGEND = 0x0013;

        public const int EVENT_SYSTEM_SWITCHSTART = 0x0014;

        public const int EVENT_SYSTEM_SWITCHEND = 0x0015;

        public const int EVENT_SYSTEM_MINIMIZESTART = 0x0016;

        public const int EVENT_SYSTEM_MINIMIZEEND = 0x0017;

        public const int EVENT_SYSTEM_DESKTOPSWITCH = 0x0020;

        public const int EVENT_SYSTEM_SWITCHER_APPGRABBED = 0x0024;

        public const int EVENT_SYSTEM_SWITCHER_APPOVERTARGET = 0x0025;

        public const int EVENT_SYSTEM_SWITCHER_APPDROPPED = 0x0026;

        public const int EVENT_SYSTEM_SWITCHER_CANCELLED = 0x0027;

        public const int EVENT_SYSTEM_IME_KEY_NOTIFICATION = 0x0029;

        public const int EVENT_SYSTEM_END = 0x00FF;

        public const int EVENT_OEM_DEFINED_START = 0x0101;

        public const int EVENT_OEM_DEFINED_END = 0x01FF;

        public const int EVENT_UIA_EVENTID_START = 0x4E00;

        public const int EVENT_UIA_EVENTID_END = 0x4EFF;

        public const int EVENT_UIA_PROPID_START = 0x7500;

        public const int EVENT_UIA_PROPID_END = 0x75FF;

        public const int EVENT_CONSOLE_CARET = 0x4001;

        public const int EVENT_CONSOLE_UPDATE_REGION = 0x4002;

        public const int EVENT_CONSOLE_UPDATE_SIMPLE = 0x4003;

        public const int EVENT_CONSOLE_UPDATE_SCROLL = 0x4004;

        public const int EVENT_CONSOLE_LAYOUT = 0x4005;

        public const int EVENT_CONSOLE_START_APPLICATION = 0x4006;

        public const int EVENT_CONSOLE_END_APPLICATION = 0x4007;

        public const int CONSOLE_APPLICATION_16BIT = 0x0001;

        public const int CONSOLE_CARET_SELECTION = 0x0001;

        public const int CONSOLE_CARET_VISIBLE = 0x0002;

        public const int EVENT_CONSOLE_END = 0x40FF;

        public const int EVENT_OBJECT_CREATE = 0x8000;

        public const int EVENT_OBJECT_DESTROY = 0x8001;

        public const int EVENT_OBJECT_SHOW = 0x8002;

        public const int EVENT_OBJECT_HIDE = 0x8003;

        public const int EVENT_OBJECT_REORDER = 0x8004;

        public const int EVENT_OBJECT_FOCUS = 0x8005;

        public const int EVENT_OBJECT_SELECTION = 0x8006;

        public const int EVENT_OBJECT_SELECTIONADD = 0x8007;

        public const int EVENT_OBJECT_SELECTIONREMOVE = 0x8008;

        public const int EVENT_OBJECT_SELECTIONWITHIN = 0x8009;

        public const int EVENT_OBJECT_STATECHANGE = 0x800A;

        public const int EVENT_OBJECT_LOCATIONCHANGE = 0x800B;

        public const int EVENT_OBJECT_NAMECHANGE = 0x800C;

        public const int EVENT_OBJECT_DESCRIPTIONCHANGE = 0x800D;

        public const int EVENT_OBJECT_VALUECHANGE = 0x800E;

        public const int EVENT_OBJECT_PARENTCHANGE = 0x800F;

        public const int EVENT_OBJECT_HELPCHANGE = 0x8010;

        public const int EVENT_OBJECT_DEFACTIONCHANGE = 0x8011;

        public const int EVENT_OBJECT_ACCELERATORCHANGE = 0x8012;

        public const int EVENT_OBJECT_INVOKED = 0x8013;

        public const int EVENT_OBJECT_TEXTSELECTIONCHANGED = 0x8014;

        public const int EVENT_OBJECT_CONTENTSCROLLED = 0x8015;

        public const int EVENT_SYSTEM_ARRANGMENTPREVIEW = 0x8016;

        public const int EVENT_OBJECT_CLOAKED = 0x8017;

        public const int EVENT_OBJECT_UNCLOAKED = 0x8018;

        public const int EVENT_OBJECT_LIVEREGIONCHANGED = 0x8019;

        public const int EVENT_OBJECT_HOSTEDOBJECTSINVALIDATED = 0x8020;

        public const int EVENT_OBJECT_DRAGSTART = 0x8021;

        public const int EVENT_OBJECT_DRAGCANCEL = 0x8022;

        public const int EVENT_OBJECT_DRAGCOMPLETE = 0x8023;

        public const int EVENT_OBJECT_DRAGENTER = 0x8024;

        public const int EVENT_OBJECT_DRAGLEAVE = 0x8025;

        public const int EVENT_OBJECT_DRAGDROPPED = 0x8026;

        public const int EVENT_OBJECT_IME_SHOW = 0x8027;

        public const int EVENT_OBJECT_IME_HIDE = 0x8028;

        public const int EVENT_OBJECT_IME_CHANGE = 0x8029;

        public const int EVENT_OBJECT_TEXTEDIT_CONVERSIONTARGETCHANGED = 0x8030;

        public const int EVENT_OBJECT_END = 0x80FF;

        public const int EVENT_AIA_START = 0xA000;

        public const int EVENT_AIA_END = 0xAFFF;

        public const int SOUND_SYSTEM_STARTUP = 1;

        public const int SOUND_SYSTEM_SHUTDOWN = 2;

        public const int SOUND_SYSTEM_BEEP = 3;

        public const int SOUND_SYSTEM_ERROR = 4;

        public const int SOUND_SYSTEM_QUESTION = 5;

        public const int SOUND_SYSTEM_WARNING = 6;

        public const int SOUND_SYSTEM_INFORMATION = 7;

        public const int SOUND_SYSTEM_MAXIMIZE = 8;

        public const int SOUND_SYSTEM_MINIMIZE = 9;

        public const int SOUND_SYSTEM_RESTOREUP = 10;

        public const int SOUND_SYSTEM_RESTOREDOWN = 11;

        public const int SOUND_SYSTEM_APPSTART = 12;

        public const int SOUND_SYSTEM_FAULT = 13;

        public const int SOUND_SYSTEM_APPEND = 14;

        public const int SOUND_SYSTEM_MENUCOMMAND = 15;

        public const int SOUND_SYSTEM_MENUPOPUP = 16;

        public const int CSOUND_SYSTEM = 16;

        public const int ALERT_SYSTEM_INFORMATIONAL = 1;

        public const int ALERT_SYSTEM_WARNING = 2;

        public const int ALERT_SYSTEM_ERROR = 3;

        public const int ALERT_SYSTEM_QUERY = 4;

        public const int ALERT_SYSTEM_CRITICAL = 5;

        public const int CALERT_SYSTEM = 6;

        public const int GUI_CARETBLINKING = 0x00000001;

        public const int GUI_INMOVESIZE = 0x00000002;

        public const int GUI_INMENUMODE = 0x00000004;

        public const int GUI_SYSTEMMENUMODE = 0x00000008;

        public const int GUI_POPUPMENUMODE = 0x00000010;

        public const int GUI_16BITTASK = 0x00000020;

        public const int USER_DEFAULT_SCREEN_DPI = 96;

        public const int STATE_SYSTEM_UNAVAILABLE = 0x00000001;

        public const int STATE_SYSTEM_SELECTED = 0x00000002;

        public const int STATE_SYSTEM_FOCUSED = 0x00000004;

        public const int STATE_SYSTEM_PRESSED = 0x00000008;

        public const int STATE_SYSTEM_CHECKED = 0x00000010;

        public const int STATE_SYSTEM_MIXED = 0x00000020;

        public const int STATE_SYSTEM_INDETERMINATE = STATE_SYSTEM_MIXED;

        public const int STATE_SYSTEM_READONLY = 0x00000040;

        public const int STATE_SYSTEM_HOTTRACKED = 0x00000080;

        public const int STATE_SYSTEM_DEFAULT = 0x00000100;

        public const int STATE_SYSTEM_EXPANDED = 0x00000200;

        public const int STATE_SYSTEM_COLLAPSED = 0x00000400;

        public const int STATE_SYSTEM_BUSY = 0x00000800;

        public const int STATE_SYSTEM_FLOATING = 0x00001000;

        public const int STATE_SYSTEM_MARQUEED = 0x00002000;

        public const int STATE_SYSTEM_ANIMATED = 0x00004000;

        public const int STATE_SYSTEM_INVISIBLE = 0x00008000;

        public const int STATE_SYSTEM_OFFSCREEN = 0x00010000;

        public const int STATE_SYSTEM_SIZEABLE = 0x00020000;

        public const int STATE_SYSTEM_MOVEABLE = 0x00040000;

        public const int STATE_SYSTEM_SELFVOICING = 0x00080000;

        public const int STATE_SYSTEM_FOCUSABLE = 0x00100000;

        public const int STATE_SYSTEM_SELECTABLE = 0x00200000;

        public const int STATE_SYSTEM_LINKED = 0x00400000;

        public const int STATE_SYSTEM_TRAVERSED = 0x00800000;

        public const int STATE_SYSTEM_MULTISELECTABLE = 0x01000000;

        public const int STATE_SYSTEM_EXTSELECTABLE = 0x02000000;

        public const int STATE_SYSTEM_ALERT_LOW = 0x04000000;

        public const int STATE_SYSTEM_ALERT_MEDIUM = 0x08000000;

        public const int STATE_SYSTEM_ALERT_HIGH = 0x10000000;

        public const int STATE_SYSTEM_PROTECTED = 0x20000000;

        public const int STATE_SYSTEM_VALID = 0x3FFFFFFF;

        public const int CCHILDREN_TITLEBAR = 5;

        public const int CCHILDREN_SCROLLBAR = 5;

        public const int CURSOR_SHOWING = 0x00000001;

        public const int CURSOR_SUPPRESSED = 0x00000002;

        public const int WS_ACTIVECAPTION = 0x0001;

        public const int GA_PARENT = 1;

        public const int GA_ROOT = 2;

        public const int GA_ROOTOWNER = 3;

        public const int RIM_INPUT = 0;

        public const int RIM_INPUTSINK = 1;

        public const int RIM_TYPEMOUSE = 0;

        public const int RIM_TYPEKEYBOARD = 1;

        public const int RIM_TYPEHID = 2;

        public const int RIM_TYPEMAX = 2;

        public const int RI_MOUSE_LEFT_BUTTON_DOWN = 0x0001;

        public const int RI_MOUSE_LEFT_BUTTON_UP = 0x0002;

        public const int RI_MOUSE_RIGHT_BUTTON_DOWN = 0x0004;

        public const int RI_MOUSE_RIGHT_BUTTON_UP = 0x0008;

        public const int RI_MOUSE_MIDDLE_BUTTON_DOWN = 0x0010;

        public const int RI_MOUSE_MIDDLE_BUTTON_UP = 0x0020;

        public const int RI_MOUSE_BUTTON_1_DOWN = RI_MOUSE_LEFT_BUTTON_DOWN;

        public const int RI_MOUSE_BUTTON_1_UP = RI_MOUSE_LEFT_BUTTON_UP;

        public const int RI_MOUSE_BUTTON_2_DOWN = RI_MOUSE_RIGHT_BUTTON_DOWN;

        public const int RI_MOUSE_BUTTON_2_UP = RI_MOUSE_RIGHT_BUTTON_UP;

        public const int RI_MOUSE_BUTTON_3_DOWN = RI_MOUSE_MIDDLE_BUTTON_DOWN;

        public const int RI_MOUSE_BUTTON_3_UP = RI_MOUSE_MIDDLE_BUTTON_UP;

        public const int RI_MOUSE_BUTTON_4_DOWN = 0x0040;

        public const int RI_MOUSE_BUTTON_4_UP = 0x0080;

        public const int RI_MOUSE_BUTTON_5_DOWN = 0x0100;

        public const int RI_MOUSE_BUTTON_5_UP = 0x0200;

        public const int RI_MOUSE_WHEEL = 0x0400;

        public const int RI_MOUSE_HWHEEL = 0x0800;

        public const int MOUSE_MOVE_RELATIVE = 0;

        public const int MOUSE_MOVE_ABSOLUTE = 1;

        public const int MOUSE_VIRTUAL_DESKTOP = 0x02;

        public const int MOUSE_ATTRIBUTES_CHANGED = 0x04;

        public const int MOUSE_MOVE_NOCOALESCE = 0x08;

        public const int KEYBOARD_OVERRUN_MAKE_CODE = 0xFF;

        public const int RI_KEY_MAKE = 0;

        public const int RI_KEY_BREAK = 1;

        public const int RI_KEY_E0 = 2;

        public const int RI_KEY_E1 = 4;

        public const int RI_KEY_TERMSRV_SET_LED = 8;

        public const int RI_KEY_TERMSRV_SHADOW = 0x10;

        public const int RID_INPUT = 0x10000003;

        public const int RID_HEADER = 0x10000005;

        public const int RIDI_PREPARSEDDATA = 0x20000005;

        public const int RIDI_DEVICENAME = 0x20000007;

        public const int RIDI_DEVICEINFO = 0x2000000b;

        public const int RIDEV_REMOVE = 0x00000001;

        public const int RIDEV_EXCLUDE = 0x00000010;

        public const int RIDEV_PAGEONLY = 0x00000020;

        public const int RIDEV_NOLEGACY = 0x00000030;

        public const int RIDEV_INPUTSINK = 0x00000100;

        public const int RIDEV_CAPTUREMOUSE = 0x00000200;

        public const int RIDEV_NOHOTKEYS = 0x00000200;

        public const int RIDEV_APPKEYS = 0x00000400;

        public const int RIDEV_EXINPUTSINK = 0x00001000;

        public const int RIDEV_DEVNOTIFY = 0x00002000;

        public const int RIDEV_EXMODEMASK = 0x000000F0;

        public const int GIDC_ARRIVAL = 1;

        public const int GIDC_REMOVAL = 2;

        public const int POINTER_DEVICE_PRODUCT_STRING_MAX = 520;

        public const int PDC_ARRIVAL = 0x001;

        public const int PDC_REMOVAL = 0x002;

        public const int PDC_ORIENTATION_0 = 0x004;

        public const int PDC_ORIENTATION_90 = 0x008;

        public const int PDC_ORIENTATION_180 = 0x010;

        public const int PDC_ORIENTATION_270 = 0x020;

        public const int PDC_MODE_DEFAULT = 0x040;

        public const int PDC_MODE_CENTERED = 0x080;

        public const int PDC_MAPPING_CHANGE = 0x100;

        public const int PDC_RESOLUTION = 0x200;

        public const int PDC_ORIGIN = 0x400;

        public const int PDC_MODE_ASPECTRATIOPRESERVED = 0x800;

        public const int MSGFLT_ADD = 1;

        public const int MSGFLT_REMOVE = 2;

        public const int MSGFLTINFO_NONE = 0;

        public const int MSGFLTINFO_ALREADYALLOWED_FORWND = 1;

        public const int MSGFLTINFO_ALREADYDISALLOWED_FORWND = 2;

        public const int MSGFLTINFO_ALLOWED_HIGHER = 3;

        public const int MSGFLT_RESET = 0;

        public const int MSGFLT_ALLOW = 1;

        public const int MSGFLT_DISALLOW = 2;

        public const int GF_BEGIN = 0x00000001;

        public const int GF_INERTIA = 0x00000002;

        public const int GF_END = 0x00000004;

        public const int GID_BEGIN = 1;

        public const int GID_END = 2;

        public const int GID_ZOOM = 3;

        public const int GID_PAN = 4;

        public const int GID_ROTATE = 5;

        public const int GID_TWOFINGERTAP = 6;

        public const int GID_PRESSANDTAP = 7;

        public const int GID_ROLLOVER = GID_PRESSANDTAP;

        public const int GC_ALLGESTURES = 0x00000001;

        public const int GC_ZOOM = 0x00000001;

        public const int GC_PAN = 0x00000001;

        public const int GC_PAN_WITH_SINGLE_FINGER_VERTICALLY = 0x00000002;

        public const int GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY = 0x00000004;

        public const int GC_PAN_WITH_GUTTER = 0x00000008;

        public const int GC_PAN_WITH_INERTIA = 0x00000010;

        public const int GC_ROTATE = 0x00000001;

        public const int GC_TWOFINGERTAP = 0x00000001;

        public const int GC_PRESSANDTAP = 0x00000001;

        public const int GC_ROLLOVER = GC_PRESSANDTAP;

        public const int GESTURECONFIGMAXCOUNT = 256;

        public const int NID_INTEGRATED_TOUCH = 0x00000001;

        public const int NID_EXTERNAL_TOUCH = 0x00000002;

        public const int NID_INTEGRATED_PEN = 0x00000004;

        public const int NID_EXTERNAL_PEN = 0x00000008;

        public const int NID_MULTI_INPUT = 0x00000040;

        public const int NID_READY = 0x00000080;

        public const int MAX_STR_BLOCKREASON = 256;

        public const uint DXGI_CREATE_FACTORY_DEBUG = 0x1;

        public const uint INFINITE = 0xFFFFFFFF;
    }

    [Flags]
    public enum ConsoleMode
    {
        ENABLE_ECHO_INPUT = 0x0004,
        ENABLE_INSERT_MODE = 0x0020,
        ENABLE_LINE_INPUT = 0x0002,
        ENABLE_MOUSE_INPUT = 0x0010,
        ENABLE_PROCESSED_INPUT = 0x0001,
        ENABLE_QUICK_EDIT_MODE = 0x0040,
        ENABLE_WINDOW_INPUT = 0x0008,
        ENABLE_VIRTUAL_TERMINAL_INPUT = 0x0200,
        ENABLE_PROCESSED_OUTPUT = 0x0001,
        ENABLE_WRAP_AT_EOL_OUTPUT = 0x0002,
        ENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004,
        DISABLE_NEWLINE_AUTO_RETURN = 0x0008,
        ENABLE_LVB_GRID_WORLDWIDE = 0x0010
    }

    [Flags]
    public enum PAGE_TYPE : uint
    {
        PAGE_NOACCESS = 0x1,
        PAGE_READONLY = 0x2,
        PAGE_READWRITE = 0x4,
        PAGE_WRITECOPY = 0x8,
        PAGE_EXECUTE = 0x10,
        PAGE_EXECUTE_READ = 0x20,
        PAGE_EXECUTE_READWRITE = 0x40,
        PAGE_EXECUTE_WRITECOPY = 0x80,
        PAGE_GUARD = 0x100,
        PAGE_NOCACHE = 0x200,
        PAGE_WRITECOMBINE = 0x400,
        PAGE_TARGETS_INVALID = 0x40000000,
        PAGE_TARGETS_NO_UPDATE = 0x40000000
    }

    [Flags]
    public enum PROCESS_ACCESS_RIGHTS : uint
    {
        PROCESS_TERMINATE = (0x0001),
        PROCESS_CREATE_THREAD = (0x0002),
        PROCESS_SET_SESSIONID = (0x0004),
        PROCESS_VM_OPERATION = (0x0008),
        PROCESS_VM_READ = (0x0010),
        PROCESS_VM_WRITE = (0x0020),
        PROCESS_DUP_HANDLE = (0x0040),
        PROCESS_CREATE_PROCESS = (0x0080),
        PROCESS_SET_QUOTA = (0x0100),
        PROCESS_SET_INFORMATION = (0x0200),
        PROCESS_QUERY_INFORMATION = (0x0400),
        PROCESS_SUSPEND_RESUME = (0x0800),
        PROCESS_QUERY_LIMITED_INFORMATION = (0x1000),
        PROCESS_SET_LIMITED_INFORMATION = (0x2000),
        PROCESS_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFFF),
        DELETE = (0x00010000),
        READ_CONTROL = (0x00020000),
        WRITE_DAC = (0x00040000),
        WRITE_OWNER = (0x00080000),
        SYNCHRONIZE = (0x00100000),
        STANDARD_RIGHTS_REQUIRED = (0x000F0000)
    }

    [Flags]
    public enum JOB_OBJECT_LIMIT : uint
    {
        JOB_OBJECT_LIMIT_WORKINGSET = 0x00000001,
        JOB_OBJECT_LIMIT_PROCESS_TIME = 0x00000002,
        JOB_OBJECT_LIMIT_JOB_TIME = 0x00000004,
        JOB_OBJECT_LIMIT_ACTIVE_PROCESS = 0x00000008,
        JOB_OBJECT_LIMIT_AFFINITY = 0x00000010,
        JOB_OBJECT_LIMIT_PRIORITY_CLASS = 0x00000020,
        JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME = 0x00000040,
        JOB_OBJECT_LIMIT_SCHEDULING_CLASS = 0x00000080,
        JOB_OBJECT_LIMIT_PROCESS_MEMORY = 0x00000100,
        JOB_OBJECT_LIMIT_JOB_MEMORY = 0x00000200,
        JOB_OBJECT_LIMIT_JOB_MEMORY_HIGH = JOB_OBJECT_LIMIT_JOB_MEMORY,
        JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION = 0x00000400,
        JOB_OBJECT_LIMIT_BREAKAWAY_OK = 0x00000800,
        JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK = 0x00001000,
        JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE = 0x00002000,
        JOB_OBJECT_LIMIT_SUBSET_AFFINITY = 0x00004000,
        JOB_OBJECT_LIMIT_JOB_MEMORY_LOW = 0x00008000,
        JOB_OBJECT_LIMIT_JOB_READ_BYTES = 0x00010000,
        JOB_OBJECT_LIMIT_JOB_WRITE_BYTES = 0x00020000,
        JOB_OBJECT_LIMIT_RATE_CONTROL = 0x00040000,
        JOB_OBJECT_LIMIT_CPU_RATE_CONTROL = JOB_OBJECT_LIMIT_RATE_CONTROL,
        JOB_OBJECT_LIMIT_IO_RATE_CONTROL = 0x00080000,
        JOB_OBJECT_LIMIT_NET_RATE_CONTROL = 0x00100000,
        JOB_OBJECT_LIMIT_VALID_FLAGS = 0x0007ffff,
        JOB_OBJECT_BASIC_LIMIT_VALID_FLAGS = 0x000000ff,
        JOB_OBJECT_EXTENDED_LIMIT_VALID_FLAGS = 0x00007fff,
        JOB_OBJECT_NOTIFICATION_LIMIT_VALID_FLAGS = (JOB_OBJECT_LIMIT_JOB_READ_BYTES | JOB_OBJECT_LIMIT_JOB_WRITE_BYTES | JOB_OBJECT_LIMIT_JOB_TIME | JOB_OBJECT_LIMIT_JOB_MEMORY_LOW | JOB_OBJECT_LIMIT_JOB_MEMORY_HIGH | JOB_OBJECT_LIMIT_CPU_RATE_CONTROL | JOB_OBJECT_LIMIT_IO_RATE_CONTROL | JOB_OBJECT_LIMIT_NET_RATE_CONTROL),
    }

    [Flags]
    public enum JOB_OBJECT_UILIMIT : uint
    {
        JOB_OBJECT_UILIMIT_NONE = 0x00000000,
        JOB_OBJECT_UILIMIT_HANDLES = 0x00000001,
        JOB_OBJECT_UILIMIT_READCLIPBOARD = 0x00000002,
        JOB_OBJECT_UILIMIT_WRITECLIPBOARD = 0x00000004,
        JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS = 0x00000008,
        JOB_OBJECT_UILIMIT_DISPLAYSETTINGS = 0x00000010,
        JOB_OBJECT_UILIMIT_GLOBALATOMS = 0x00000020,
        JOB_OBJECT_UILIMIT_DESKTOP = 0x00000040,
        JOB_OBJECT_UILIMIT_EXITWINDOWS = 0x00000080
    }

    [Flags]
    public enum JOB_OBJECT_SECURITY : uint
    {
        JOB_OBJECT_SECURITY_NO_ADMIN = 0x00000001,
        JOB_OBJECT_SECURITY_RESTRICTED_TOKEN = 0x00000002,
        JOB_OBJECT_SECURITY_ONLY_TOKEN = 0x00000004,
        JOB_OBJECT_SECURITY_FILTER_TOKENS = 0x00000008,
        JOB_OBJECT_SECURITY_VALID_FLAGS = 0x0000000f
    }

    public enum IMAGE
    {
        IMAGE_BITMAP = 0,
        IMAGE_CURSOR = 2,
        IMAGE_ICON = 1
    }

    public enum OnSetSoftwareRadioStateComplete_statusFlags
    {
        S_OK = 0
    }

    public enum SSGF
    {
        SSGF_DISPLAY = 3,
        SSGF_NONE = 0
    }

    public enum GWL
    {
        GWL_EXSTYLE = -20,
        GWL_HINSTANCE = -6,
        GWL_ID = -12,
        GWL_STYLE = -16,
        GWL_USERDATA = -21,
        GWL_WNDPROC = -4
    }

    [Flags]
    public enum AnonymousEnum5 : uint
    {
        XBUTTON1 = 0x00000001,
        XBUTTON2 = 0x00000002
    }

    [Flags]
    public enum SPIF : uint
    {
        SPIF_UPDATEINIFILE = 0x00000001,
        SPIF_SENDCHANGE = 0x00000002,
        SPIF_SENDWININICHANGE = 0x00000002
    }

    [Flags]
    public enum DT : uint
    {
        DT_BOTTOM = 0x00000008,
        DT_CALCRECT = 0x00000400,
        DT_CENTER = 0x00000001,
        DT_EDITCONTROL = 0x00002000,
        DT_END_ELLIPSIS = 0x00008000,
        DT_EXPANDTABS = 0x00000040,
        DT_EXTERNALLEADING = 0x00000200,
        DT_HIDEPREFIX = 0x00100000,
        DT_INTERNAL = 0x00001000,
        DT_LEFT = 0x00000000,
        DT_MODIFYSTRING = 0x00010000,
        DT_NOCLIP = 0x00000100,
        DT_NOFULLWIDTHCHARBREAK = 0x00080000,
        DT_NOPREFIX = 0x00000800,
        DT_PATH_ELLIPSIS = 0x00004000,
        DT_PREFIXONLY = 0x00200000,
        DT_RIGHT = 0x00000002,
        DT_RTLREADING = 0x00020000,
        DT_SINGLELINE = 0x00000020,
        DT_TABSTOP = 0x00000080,
        DT_TOP = 0x00000000,
        DT_VCENTER = 0x00000004,
        DT_WORDBREAK = 0x00000010,
        DT_WORD_ELLIPSIS = 0x00040000
    }

    public enum DELETEITEMSTRUCT_CtlTypeFlags
    {
        ODT_LISTBOX = 2,
        ODT_COMBOBOX = 3
    }

    public enum RIDI
    {
        RIDI_PREPARSEDDATA = 536870917,
        RIDI_DEVICENAME = 536870919,
        RIDI_DEVICEINFO = 536870923
    }

    public enum COMBOBOXINFO_stateButtonFlags
    {
        STATE_SYSTEM_INVISIBLE = 32768,
        STATE_SYSTEM_PRESSED = 8
    }

    public enum SSTF
    {
        SSTF_BORDER = 2,
        SSTF_CHARS = 1,
        SSTF_DISPLAY = 3,
        SSTF_NONE = 0
    }

    public enum ChangeWindowMessageFilterEx_actionFlags
    {
        MSGFLT_ALLOW = 1,
        MSGFLT_DISALLOW = 2,
        MSGFLT_RESET = 0
    }

    public enum BST
    {
        BST_CHECKED = 1,
        BST_INDETERMINATE = 2,
        BST_UNCHECKED = 0
    }

    [Flags]
    public enum DrawEdgeFlags : uint
    {
        BF_ADJUST = 0x00002000,
        BF_BOTTOM = 0x00000008,
        BF_BOTTOMLEFT = 0x00000009,
        BF_BOTTOMRIGHT = 0x0000000C,
        BF_DIAGONAL = 0x00000010,
        BF_DIAGONAL_ENDBOTTOMLEFT = 0x00000019,
        BF_DIAGONAL_ENDBOTTOMRIGHT = 0x0000001C,
        BF_DIAGONAL_ENDTOPLEFT = 0x00000013,
        BF_DIAGONAL_ENDTOPRIGHT = 0x00000016,
        BF_FLAT = 0x00004000,
        BF_LEFT = 0x00000001,
        BF_MIDDLE = 0x00000800,
        BF_MONO = 0x00008000,
        BF_RECT = 0x0000000F,
        BF_RIGHT = 0x00000004,
        BF_SOFT = 0x00001000,
        BF_TOP = 0x00000002,
        BF_TOPLEFT = 0x00000003,
        BF_TOPRIGHT = 0x00000006
    }

    [Flags]
    public enum AnonymousEnum17 : uint
    {
        BSM_ALLCOMPONENTS = 0x00000000,
        BSM_ALLDESKTOPS = 0x00000010,
        BSM_APPLICATIONS = 0x00000008
    }

    public enum GetWindow_uCmdFlags
    {
        GW_CHILD = 5,
        GW_ENABLEDPOPUP = 6,
        GW_HWNDFIRST = 0,
        GW_HWNDLAST = 1,
        GW_HWNDNEXT = 2,
        GW_HWNDPREV = 3,
        GW_OWNER = 4
    }

    public enum GetScrollBarInfo_idObjectFlags
    {
        OBJID_CLIENT = -4,
        OBJID_HSCROLL = -6,
        OBJID_VSCROLL = -5
    }

    public enum MENUGETOBJECTINFOFlags
    {
        MNGOF_BOTTOMGAP = 2,
        MNGOF_TOPGAP = 1
    }

    [Flags]
    public enum SCROLLINFO_fMaskFlags : uint
    {
        SIF_ALL = 0x00000017,
        SIF_DISABLENOSCROLL = 0x00000008,
        SIF_PAGE = 0x00000002,
        SIF_POS = 0x00000004,
        SIF_RANGE = 0x00000001,
        SIF_TRACKPOS = 0x00000010
    }

    public enum GetAncestorFlags
    {
        GA_PARENT = 1,
        GA_ROOT = 2,
        GA_ROOTOWNER = 3
    }

    public enum AnonymousEnum27
    {
        MF_BYCOMMAND = 0,
        MF_BYPOSITION = 1024
    }

    [Flags]
    public enum LookupIconIdFromDirectoryExFlags : uint
    {
        LR_DEFAULTCOLOR = 0x00000000,
        LR_MONOCHROME = 0x00000001
    }

    [Flags]
    public enum keybd_eventFlags : uint
    {
        KEYEVENTF_EXTENDEDKEY = 0x00000001,
        KEYEVENTF_KEYUP = 0x00000002
    }

    public enum ENUM : uint
    {
        ENUM_CURRENT_SETTINGS = 4294967295U,
        ENUM_REGISTRY_SETTINGS = 4294967294U
    }

    [Flags]
    public enum WINDOWPLACEMENTFlags : uint
    {
        WPF_ASYNCWINDOWPLACEMENT = 0x00000004,
        WPF_RESTORETOMAXIMIZED = 0x00000002,
        WPF_SETMINPOSITION = 0x00000001
    }

    [Flags]
    public enum SetWindowPosFlags : uint
    {
        SWP_ASYNCWINDOWPOS = 0x00004000,
        SWP_DEFERERASE = 0x00002000,
        SWP_DRAWFRAME = 0x00000020,
        SWP_FRAMECHANGED = 0x00000020,
        SWP_HIDEWINDOW = 0x00000080,
        SWP_NOACTIVATE = 0x00000010,
        SWP_NOCOPYBITS = 0x00000100,
        SWP_NOMOVE = 0x00000002,
        SWP_NOOWNERZORDER = 0x00000200,
        SWP_NOREDRAW = 0x00000008,
        SWP_NOREPOSITION = 0x00000200,
        SWP_NOSENDCHANGING = 0x00000400,
        SWP_NOSIZE = 0x00000001,
        SWP_NOZORDER = 0x00000004,
        SWP_SHOWWINDOW = 0x00000040
    }

    public enum SB
    {
        SB_BOTH = 3,
        SB_HORZ = 0,
        SB_VERT = 1
    }

    public enum AnonymousEnum42
    {
        GCW_ATOM = -32,
        GCL_CBCLSEXTRA = -20,
        GCL_CBWNDEXTRA = -18,
        GCLP_HBRBACKGROUND = -10,
        GCLP_HCURSOR = -12,
        GCLP_HICON = -14,
        GCLP_HICONSM = -34,
        GCLP_HMODULE = -16,
        GCLP_MENUNAME = -8,
        GCL_STYLE = -26,
        GCLP_WNDPROC = -24
    }

    public enum AnonymousEnum43
    {
        MONITOR_DEFAULTTONEAREST = 2,
        MONITOR_DEFAULTTONULL = 0,
        MONITOR_DEFAULTTOPRIMARY = 1
    }

    [Flags]
    public enum SMTO : uint
    {
        SMTO_ABORTIFHUNG = 0x00000002,
        SMTO_BLOCK = 0x00000001,
        SMTO_NORMAL = 0x00000000,
        SMTO_NOTIMEOUTIFNOTHUNG = 0x00000008,
        SMTO_ERRORONEXIT = 0x00000020
    }

    [Flags]
    public enum DDL : uint
    {
        DDL_ARCHIVE = 0x00000020,
        DDL_DIRECTORY = 0x00000010,
        DDL_DRIVES = 0x00004000,
        DDL_EXCLUSIVE = 0x00008000,
        DDL_HIDDEN = 0x00000002,
        DDL_READONLY = 0x00000001,
        DDL_READWRITE = 0x00000000,
        DDL_SYSTEM = 0x00000004,
        DDL_POSTMSGS = 0x00002000
    }

    [Flags]
    public enum LR : uint
    {
        LR_CREATEDIBSECTION = 0x00002000,
        LR_DEFAULTCOLOR = 0x00000000,
        LR_DEFAULTSIZE = 0x00000040,
        LR_LOADFROMFILE = 0x00000010,
        LR_LOADMAP3DCOLORS = 0x00001000,
        LR_LOADTRANSPARENT = 0x00000020,
        LR_MONOCHROME = 0x00000001,
        LR_SHARED = 0x00008000
    }

    public enum ShowWindow_nCmdShowFlags
    {
        SW_FORCEMINIMIZE = 11,
        SW_HIDE = 0,
        SW_MAXIMIZE = 3,
        SW_MINIMIZE = 6,
        SW_RESTORE = 9,
        SW_SHOW = 5,
        SW_SHOWDEFAULT = 10,
        SW_SHOWMAXIMIZED = 3,
        SW_SHOWMINIMIZED = 2,
        SW_SHOWMINNOACTIVE = 7,
        SW_SHOWNA = 8,
        SW_SHOWNOACTIVATE = 4,
        SW_SHOWNORMAL = 1
    }

    [Flags]
    public enum LR : uint
    {
        LR_CREATEDIBSECTION = 0x00002000,
        LR_DEFAULTCOLOR = 0x00000000,
        LR_DEFAULTSIZE = 0x00000040,
        LR_LOADFROMFILE = 0x00000010,
        LR_LOADMAP3DCOLORS = 0x00001000,
        LR_LOADTRANSPARENT = 0x00000020,
        LR_MONOCHROME = 0x00000001,
        LR_SHARED = 0x00008000,
        LR_VGACOLOR = 0x00000080
    }

    [Flags]
    public enum QS : uint
    {
        QS_ALLEVENTS = 0x00001CBF,
        QS_ALLINPUT = 0x00001CFF,
        QS_ALLPOSTMESSAGE = 0x00000100,
        QS_HOTKEY = 0x00000080,
        QS_INPUT = 0x00001C07,
        QS_KEY = 0x00000001,
        QS_MOUSE = 0x00000006,
        QS_MOUSEBUTTON = 0x00000004,
        QS_MOUSEMOVE = 0x00000002,
        QS_PAINT = 0x00000020,
        QS_POSTMESSAGE = 0x00000008,
        QS_RAWINPUT = 0x00000400,
        QS_SENDMESSAGE = 0x00000040,
        QS_TIMER = 0x00000010
    }

    public enum UOI
    {
        UOI_FLAGS = 1,
        UOI_HEAPSIZE = 5,
        UOI_IO = 6,
        UOI_NAME = 2,
        UOI_TYPE = 3,
        UOI_USER_SID = 4
    }

    public enum LockSetForegroundWindow_uLockCodeFlags
    {
        LSFW_LOCK = 1,
        LSFW_UNLOCK = 2
    }

    [Flags]
    public enum FlatSB_SetScrollInfo_psiFlags : uint
    {
        SIF_DISABLENOSCROLL = 0x00000008,
        SIF_PAGE = 0x00000002,
        SIF_POS = 0x00000004,
        SIF_RANGE = 0x00000001,
        SIF_ALL = 0x00000017
    }

    [Flags]
    public enum EnableMenuItem_uEnableFlags : uint
    {
        MF_BYCOMMAND = 0x00000000,
        MF_BYPOSITION = 0x00000400,
        MF_DISABLED = 0x00000002,
        MF_ENABLED = 0x00000000,
        MF_GRAYED = 0x00000001
    }

    public enum SB
    {
        SB_HORZ = 0,
        SB_VERT = 1
    }

    [Flags]
    public enum SERKF : uint
    {
        SERKF_AVAILABLE = 0x00000002,
        SERKF_INDICATOR = 0x00000004,
        SERKF_SERIALKEYSON = 0x00000001
    }

    public enum WINDOWPLACEMENT_showCmdFlags
    {
        SW_HIDE = 0,
        SW_MAXIMIZE = 3,
        SW_MINIMIZE = 6,
        SW_RESTORE = 9,
        SW_SHOW = 5,
        SW_SHOWMAXIMIZED = 3,
        SW_SHOWMINIMIZED = 2,
        SW_SHOWMINNOACTIVE = 7,
        SW_SHOWNA = 8,
        SW_SHOWNOACTIVATE = 4,
        SW_SHOWNORMAL = 1
    }

    public enum AnonymousEnum54
    {
        GWL_EXSTYLE = -20,
        GWLP_HINSTANCE = -6,
        GWLP_HWNDPARENT = -8,
        GWLP_ID = -12,
        GWL_STYLE = -16,
        GWLP_USERDATA = -21,
        GWLP_WNDPROC = -4
    }

    public enum SB
    {
        SB_CTL = 2,
        SB_HORZ = 0,
        SB_VERT = 1
    }

    [Flags]
    public enum BSF : uint
    {
        BSF_ALLOWSFW = 0x00000080,
        BSF_FLUSHDISK = 0x00000004,
        BSF_FORCEIFHUNG = 0x00000020,
        BSF_IGNORECURRENTTASK = 0x00000002,
        BSF_NOHANG = 0x00000008,
        BSF_NOTIMEOUTIFNOTHUNG = 0x00000040,
        BSF_POSTMESSAGE = 0x00000010,
        BSF_QUERY = 0x00000001,
        BSF_SENDNOTIFYMESSAGE = 0x00000100
    }

    [Flags]
    public enum MIIM : uint
    {
        MIIM_BITMAP = 0x00000080,
        MIIM_CHECKMARKS = 0x00000008,
        MIIM_DATA = 0x00000020,
        MIIM_FTYPE = 0x00000100,
        MIIM_ID = 0x00000002,
        MIIM_STATE = 0x00000001,
        MIIM_STRING = 0x00000040,
        MIIM_SUBMENU = 0x00000004,
        MIIM_TYPE = 0x00000010
    }

    [Flags]
    public enum TRACKMOUSEEVENTFlags : uint
    {
        TME_CANCEL = 0x80000000,
        TME_HOVER = 0x00000001,
        TME_LEAVE = 0x00000002,
        TME_NONCLIENT = 0x00000010,
        TME_QUERY = 0x40000000
    }

    public enum ESB
    {
        ESB_DISABLE_BOTH = 3,
        ESB_DISABLE_DOWN = 2,
        ESB_DISABLE_LEFT = 1,
        ESB_DISABLE_LTUP = 1,
        ESB_DISABLE_RIGHT = 2,
        ESB_DISABLE_RTDN = 2,
        ESB_DISABLE_UP = 1,
        ESB_ENABLE_BOTH = 0
    }

    public enum CDS
    {
        CDS_FULLSCREEN = 4,
        CDS_GLOBAL = 8,
        CDS_NORESET = 268435456,
        CDS_RESET = 1073741824,
        CDS_SET_PRIMARY = 16,
        CDS_TEST = 2,
        CDS_UPDATEREGISTRY = 1,
        CDS_VIDEOPARAMETERS = 32,
        CDS_ENABLE_UNSAFE_MODES = 256,
        CDS_DISABLE_UNSAFE_MODES = 512
    }

    public enum ULW
    {
        ULW_ALPHA = 2,
        ULW_COLORKEY = 1,
        ULW_OPAQUE = 4,
        ULW_EX_NORESIZE = 8
    }

    public enum MINIMIZEDMETRICS_iArrangeFlags
    {
        ARW_BOTTOMLEFT = 0,
        ARW_BOTTOMRIGHT = 1,
        ARW_TOPLEFT = 2,
        ARW_TOPRIGHT = 3
    }

    public enum GCL
    {
        GCL_CBCLSEXTRA = -20,
        GCL_CBWNDEXTRA = -18,
        GCL_HBRBACKGROUND = -10,
        GCL_HCURSOR = -12,
        GCL_HICON = -14,
        GCL_HICONSM = -34,
        GCL_HMODULE = -16,
        GCL_MENUNAME = -8,
        GCL_STYLE = -26,
        GCL_WNDPROC = -24
    }

    public enum SetWindowDisplayAffinity_dwAffinityFlags
    {
        WDA_NONE = 0,
        WDA_MONITOR = 1,
        WDA_EXCLUDEFROMCAPTURE = 17
    }

    public enum mouse_eventFlags
    {
        MOUSEEVENTF_ABSOLUTE = 32768,
        MOUSEEVENTF_LEFTDOWN = 2,
        MOUSEEVENTF_LEFTUP = 4,
        MOUSEEVENTF_MIDDLEDOWN = 32,
        MOUSEEVENTF_MIDDLEUP = 64,
        MOUSEEVENTF_MOVE = 1,
        MOUSEEVENTF_RIGHTDOWN = 8,
        MOUSEEVENTF_RIGHTUP = 16,
        MOUSEEVENTF_WHEEL = 2048,
        MOUSEEVENTF_XDOWN = 128,
        MOUSEEVENTF_XUP = 256,
        MOUSEEVENTF_HWHEEL = 4096
    }

    public enum HWND
    {
        HWND_BOTTOM = 1,
        HWND_NOTOPMOST = -2,
        HWND_TOP = 0,
        HWND_TOPMOST = -1
    }

    [Flags]
    public enum PM : uint
    {
        PM_NOREMOVE = 0x00000000,
        PM_REMOVE = 0x00000001,
        PM_NOYIELD = 0x00000002
    }

    [Flags]
    public enum AnimateWindowFlags : uint
    {
        AW_ACTIVATE = 0x00020000,
        AW_BLEND = 0x00080000,
        AW_CENTER = 0x00000010,
        AW_HIDE = 0x00010000,
        AW_HOR_POSITIVE = 0x00000001,
        AW_HOR_NEGATIVE = 0x00000002,
        AW_SLIDE = 0x00040000,
        AW_VER_POSITIVE = 0x00000004,
        AW_VER_NEGATIVE = 0x00000008
    }

    public enum RAWINPUTDEVICEFlags
    {
        RIDEV_REMOVE = 1,
        RIDEV_EXCLUDE = 16,
        RIDEV_PAGEONLY = 32,
        RIDEV_NOLEGACY = 48,
        RIDEV_INPUTSINK = 256,
        RIDEV_CAPTUREMOUSE = 512,
        RIDEV_NOHOTKEYS = 512,
        RIDEV_APPKEYS = 1024,
        RIDEV_EXINPUTSINK = 4096,
        RIDEV_DEVNOTIFY = 8192
    }

    public enum WH
    {
        WH_CALLWNDPROC = 4,
        WH_CALLWNDPROCRET = 12,
        WH_CBT = 5,
        WH_DEBUG = 9,
        WH_FOREGROUNDIDLE = 11,
        WH_GETMESSAGE = 3,
        WH_JOURNALPLAYBACK = 1,
        WH_JOURNALRECORD = 0,
        WH_KEYBOARD = 2,
        WH_KEYBOARD_LL = 13,
        WH_MOUSE = 7,
        WH_MOUSE_LL = 14,
        WH_MSGFILTER = -1,
        WH_SHELL = 10,
        WH_SYSMSGFILTER = 6
    }

    [Flags]
    public enum LWA : uint
    {
        LWA_ALPHA = 0x00000002,
        LWA_COLORKEY = 0x00000001
    }

    public enum AnonymousEnum70
    {
        GWL_EXSTYLE = -20,
        GWLP_HINSTANCE = -6,
        GWLP_ID = -12,
        GWL_STYLE = -16,
        GWLP_USERDATA = -21,
        GWLP_WNDPROC = -4
    }

    [Flags]
    public enum GetQueueStatusFlags : uint
    {
        QS_ALLEVENTS = 0x00001CBF,
        QS_ALLINPUT = 0x00001CFF,
        QS_ALLPOSTMESSAGE = 0x00000100,
        QS_HOTKEY = 0x00000080,
        QS_INPUT = 0x00001C07,
        QS_KEY = 0x00000001,
        QS_MOUSE = 0x00000006,
        QS_MOUSEBUTTON = 0x00000004,
        QS_MOUSEMOVE = 0x00000002,
        QS_PAINT = 0x00000020,
        QS_POSTMESSAGE = 0x00000008,
        QS_RAWINPUT = 0x00000400,
        QS_SENDMESSAGE = 0x00000040,
        QS_TIMER = 0x00000010
    }

    public enum AnonymousEnum75
    {
        IDC_APPSTARTING = 32650,
        IDC_ARROW = 32512,
        IDC_CROSS = 32515,
        IDC_HAND = 32649,
        IDC_HELP = 32651,
        IDC_IBEAM = 32513,
        IDC_NO = 32648,
        IDC_SIZEALL = 32646,
        IDC_SIZENESW = 32643,
        IDC_SIZENS = 32645,
        IDC_SIZENWSE = 32642,
        IDC_SIZEWE = 32644,
        IDC_UPARROW = 32516,
        IDC_WAIT = 32514,
        IDI_APPLICATION = 32512,
        IDI_ASTERISK = 32516,
        IDI_EXCLAMATION = 32515,
        IDI_HAND = 32513,
        IDI_QUESTION = 32514,
        IDI_WINLOGO = 32517
    }

    public enum SB
    {
        SB_BOTH = 3,
        SB_CTL = 2,
        SB_HORZ = 0,
        SB_VERT = 1
    }

    [Flags]
    public enum RegisterHotKey_fsModifiersFlags : uint
    {
        MOD_ALT = 0x00000001,
        MOD_CONTROL = 0x00000002,
        MOD_NOREPEAT = 0x00004000,
        MOD_SHIFT = 0x00000004,
        MOD_WIN = 0x00000008
    }

    public enum AnonymousEnum77
    {
        GCW_ATOM = -32,
        GCL_CBCLSEXTRA = -20,
        GCL_CBWNDEXTRA = -18,
        GCL_HBRBACKGROUND = -10,
        GCL_HCURSOR = -12,
        GCL_HICON = -14,
        GCL_HICONSM = -34,
        GCL_HMODULE = -16,
        GCL_MENUNAME = -8,
        GCL_STYLE = -26,
        GCL_WNDPROC = -24
    }

    [Flags]
    public enum CascadeWindows_wHowFlags : uint
    {
        MDITILE_SKIPDISABLED = 0x00000002,
        MDITILE_ZORDER = 0x00000004
    }

    public enum MF
    {
        MF_BITMAP = 4,
        MF_CHECKED = 8,
        MF_DISABLED = 2,
        MF_ENABLED = 0,
        MF_GRAYED = 1,
        MF_MENUBARBREAK = 32,
        MF_MENUBREAK = 64,
        MF_OWNERDRAW = 256,
        MF_POPUP = 16,
        MF_SEPARATOR = 2048,
        MF_STRING = 0,
        MF_UNCHECKED = 0
    }

    [Flags]
    public enum HCF : uint
    {
        HCF_HIGHCONTRASTON = 0x00000001,
        HCF_AVAILABLE = 0x00000002,
        HCF_HOTKEYACTIVE = 0x00000004,
        HCF_CONFIRMHOTKEY = 0x00000008,
        HCF_HOTKEYSOUND = 0x00000010,
        HCF_INDICATOR = 0x00000020,
        HCF_HOTKEYAVAILABLE = 0x00000040,
        HCF_OPTION_NOTHEMECHANGE = 0x00001000
    }

    public enum ChangeWindowMessageFilter_dwFlagFlags
    {
        MSGFLT_ADD = 1,
        MSGFLT_REMOVE = 2
    }

    [Flags]
    public enum WS : uint
    {
        WS_MINIMIZE = 0x20000000,
        WS_MAXIMIZE = 0x01000000,
        WS_HSCROLL = 0x00100000,
        WS_VSCROLL = 0x00200000
    }

    public enum PWAITCHAINCALLBACK_CallbackStatusFlags
    {
        ERROR_ACCESS_DENIED = 5,
        ERROR_CANCELLED = 1223,
        ERROR_MORE_DATA = 234,
        ERROR_OBJECT_NOT_FOUND = 4312,
        ERROR_SUCCESS = 0,
        ERROR_TOO_MANY_THREADS = 565
    }

    public enum GetRawInputData_uiCommandFlags
    {
        RID_HEADER = 268435461,
        RID_INPUT = 268435459
    }

    [Flags]
    public enum BSF : uint
    {
        BSF_ALLOWSFW = 0x00000080,
        BSF_FLUSHDISK = 0x00000004,
        BSF_FORCEIFHUNG = 0x00000020,
        BSF_IGNORECURRENTTASK = 0x00000002,
        BSF_LUID = 0x00000400,
        BSF_NOHANG = 0x00000008,
        BSF_NOTIMEOUTIFNOTHUNG = 0x00000040,
        BSF_POSTMESSAGE = 0x00000010,
        BSF_RETURNHDESK = 0x00000200,
        BSF_QUERY = 0x00000001,
        BSF_SENDNOTIFYMESSAGE = 0x00000100
    }

    [Flags]
    public enum GetDCExFlags : uint
    {
        DCX_WINDOW = 0x00000001,
        DCX_CACHE = 0x00000002,
        DCX_PARENTCLIP = 0x00000020,
        DCX_CLIPSIBLINGS = 0x00000010,
        DCX_CLIPCHILDREN = 0x00000008,
        DCX_NORESETATTRS = 0x00000004,
        DCX_LOCKWINDOWUPDATE = 0x00000400,
        DCX_EXCLUDERGN = 0x00000040,
        DCX_INTERSECTRGN = 0x00000080,
        DCX_INTERSECTUPDATE = 0x00000200,
        DCX_VALIDATE = 0x00200000
    }

    public enum KEYBDINPUTFlags
    {
        KEYEVENTF_EXTENDEDKEY = 1,
        KEYEVENTF_KEYUP = 2,
        KEYEVENTF_SCANCODE = 8,
        KEYEVENTF_UNICODE = 4
    }

    [Flags]
    public enum ScrollWindowExFlags : uint
    {
        SW_ERASE = 0x00000004,
        SW_INVALIDATE = 0x00000002,
        SW_SCROLLCHILDREN = 0x00000001,
        SW_SMOOTHSCROLL = 0x00000010
    }

    public enum ExitWindowsExFlags
    {
        EWX_HYBRID_SHUTDOWN = 4194304,
        EWX_LOGOFF = 0,
        EWX_POWEROFF = 8,
        EWX_REBOOT = 2,
        EWX_RESTARTAPPS = 64,
        EWX_SHUTDOWN = 1
    }

    public enum INPUT_typeFlags
    {
        INPUT_MOUSE = 0,
        INPUT_KEYBOARD = 1,
        INPUT_HARDWARE = 2
    }

    [Flags]
    public enum STATE_SYSTEM : uint
    {
        STATE_SYSTEM_FOCUSABLE = 0x00100000,
        STATE_SYSTEM_INVISIBLE = 0x00008000,
        STATE_SYSTEM_OFFSCREEN = 0x00010000,
        STATE_SYSTEM_UNAVAILABLE = 0x00000001,
        STATE_SYSTEM_PRESSED = 0x00000008
    }

    public enum SSWF
    {
        SSWF_CUSTOM = 4,
        SSWF_DISPLAY = 3,
        SSWF_NONE = 0,
        SSWF_TITLE = 1,
        SSWF_WINDOW = 2
    }

    [Flags]
    public enum ACCEL_fVirtFlags : uint
    {
        FALT = 0x00000010,
        FCONTROL = 0x00000008,
        FNOINVERT = 0x00000002,
        FSHIFT = 0x00000004,
        FVIRTKEY = 0x00000001
    }

    public enum GetMenuBarInfo_idObjectFlags
    {
        OBJID_CLIENT = -4,
        OBJID_MENU = -3,
        OBJID_SYSMENU = -1
    }

    public enum CHANGEFILTERSTRUCT_ExtStatusFlags
    {
        MSGFLTINFO_NONE = 0,
        MSGFLTINFO_ALLOWED_HIGHER = 3,
        MSGFLTINFO_ALREADYALLOWED_FORWND = 1,
        MSGFLTINFO_ALREADYDISALLOWED_FORWND = 2
    }

    public enum DrawFrameControl_arg4Flags
    {
        DFCS_BUTTON3STATE = 8,
        DFCS_BUTTONCHECK = 0,
        DFCS_BUTTONPUSH = 16,
        DFCS_BUTTONRADIO = 4,
        DFCS_BUTTONRADIOIMAGE = 1,
        DFCS_BUTTONRADIOMASK = 2
    }

    [Flags]
    public enum MFT : uint
    {
        MFT_BITMAP = 0x00000004,
        MFT_MENUBARBREAK = 0x00000020,
        MFT_MENUBREAK = 0x00000040,
        MFT_OWNERDRAW = 0x00000100,
        MFT_RADIOCHECK = 0x00000200,
        MFT_RIGHTJUSTIFY = 0x00004000,
        MFT_RIGHTORDER = 0x00002000,
        MFT_SEPARATOR = 0x00000800,
        MFT_STRING = 0x00000000
    }

    [Flags]
    public enum DrawCaptionFlags : uint
    {
        DC_ACTIVE = 0x00000001,
        DC_BUTTONS = 0x00001000,
        DC_GRADIENT = 0x00000020,
        DC_ICON = 0x00000004,
        DC_INBUTTON = 0x00000010,
        DC_SMALLCAP = 0x00000002,
        DC_TEXT = 0x00000008
    }

    [Flags]
    public enum RAWMOUSEFlags : uint
    {
        RI_MOUSE_LEFT_BUTTON_DOWN = 0x00000001,
        RI_MOUSE_LEFT_BUTTON_UP = 0x00000002,
        RI_MOUSE_MIDDLE_BUTTON_DOWN = 0x00000010,
        RI_MOUSE_MIDDLE_BUTTON_UP = 0x00000020,
        RI_MOUSE_RIGHT_BUTTON_DOWN = 0x00000004,
        RI_MOUSE_RIGHT_BUTTON_UP = 0x00000008,
        RI_MOUSE_BUTTON_1_DOWN = 0x00000001,
        RI_MOUSE_BUTTON_1_UP = 0x00000002,
        RI_MOUSE_BUTTON_2_DOWN = 0x00000004,
        RI_MOUSE_BUTTON_2_UP = 0x00000008,
        RI_MOUSE_BUTTON_3_DOWN = 0x00000010,
        RI_MOUSE_BUTTON_3_UP = 0x00000020,
        RI_MOUSE_BUTTON_4_DOWN = 0x00000040,
        RI_MOUSE_BUTTON_4_UP = 0x00000080,
        RI_MOUSE_BUTTON_5_DOWN = 0x00000100,
        RI_MOUSE_BUTTON_5_UP = 0x00000200,
        RI_MOUSE_WHEEL = 0x00000400,
        RI_MOUSE_HWHEEL = 0x00000800
    }

    [Flags]
    public enum GetScrollInfo_lpsiFlags : uint
    {
        SIF_PAGE = 0x00000002,
        SIF_POS = 0x00000004,
        SIF_RANGE = 0x00000001,
        SIF_TRACKPOS = 0x00000010
    }

    [Flags]
    public enum MsgWaitForMultipleObjectsExFlags : uint
    {
        MWMO_ALERTABLE = 0x00000002,
        MWMO_INPUTAVAILABLE = 0x00000004,
        MWMO_WAITALL = 0x00000001
    }

    public enum GetMouseMovePointsEx_resolutionFlags
    {
        GMMP_USE_DISPLAY_POINTS = 1,
        GMMP_USE_HIGH_RESOLUTION_POINTS = 2
    }

    [Flags]
    public enum FlatSB_GetScrollInfo_arg3Flags : uint
    {
        SIF_PAGE = 0x00000002,
        SIF_POS = 0x00000004,
        SIF_RANGE = 0x00000001,
        SIF_ALL = 0x00000017
    }

    [Flags]
    public enum GUITHREADINFOFlags : uint
    {
        GUI_CARETBLINKING = 0x00000001,
        GUI_INMENUMODE = 0x00000004,
        GUI_INMOVESIZE = 0x00000002,
        GUI_POPUPMENUMODE = 0x00000010,
        GUI_SYSTEMMENUMODE = 0x00000008
    }

    [Flags]
    public enum MF : uint
    {
        MF_BITMAP = 0x00000004,
        MF_CHECKED = 0x00000008,
        MF_DISABLED = 0x00000002,
        MF_ENABLED = 0x00000000,
        MF_GRAYED = 0x00000001,
        MF_MENUBARBREAK = 0x00000020,
        MF_MENUBREAK = 0x00000040,
        MF_OWNERDRAW = 0x00000100,
        MF_POPUP = 0x00000010,
        MF_SEPARATOR = 0x00000800,
        MF_STRING = 0x00000000,
        MF_UNCHECKED = 0x00000000
    }

    public enum CURSORINFOFlags
    {
        CURSOR_SHOWING = 1,
        CURSOR_SUPPRESSED = 2
    }

    public enum TxScrollWindowEx_fuScrollFlags
    {
        SW_ERASE = 4,
        SW_INVALIDATE = 2,
        SW_SCROLLCHILDREN = 1,
        SW_SMOOTHSCROLL = 16
    }

    public enum RIP_INFO_dwTypeFlags
    {
        SLE_ERROR = 1,
        SLE_MINORERROR = 2,
        SLE_WARNING = 3
    }

    public enum PrintWindowFlags
    {
        PW_CLIENTONLY = 1
    }

    [Flags]
    public enum MENUINFO_dwStyleFlags : uint
    {
        MNS_AUTODISMISS = 0x10000000,
        MNS_CHECKORBMP = 0x04000000,
        MNS_DRAGDROP = 0x20000000,
        MNS_MODELESS = 0x40000000,
        MNS_NOCHECK = 0x80000000,
        MNS_NOTIFYBYPOS = 0x08000000
    }

    public enum DEVICE_NOTIFY
    {
        DEVICE_NOTIFY_WINDOW_HANDLE = 0,
        DEVICE_NOTIFY_SERVICE_HANDLE = 1
    }

    [Flags]
    public enum MENUINFO_fMaskFlags : uint
    {
        MIM_APPLYTOSUBMENUS = 0x80000000,
        MIM_BACKGROUND = 0x00000002,
        MIM_HELPID = 0x00000004,
        MIM_MAXHEIGHT = 0x00000001,
        MIM_MENUDATA = 0x00000008,
        MIM_STYLE = 0x00000010
    }

    public enum DrawFrameControl_arg3Flags
    {
        DFC_BUTTON = 4,
        DFC_CAPTION = 1,
        DFC_MENU = 2,
        DFC_POPUPMENU = 5,
        DFC_SCROLL = 3
    }

    [Flags]
    public enum SetScrollInfo_lpsiFlags : uint
    {
        SIF_DISABLENOSCROLL = 0x00000008,
        SIF_PAGE = 0x00000002,
        SIF_POS = 0x00000004,
        SIF_RANGE = 0x00000001
    }

    public enum GetGuiResourcesFlags
    {
        GR_GDIOBJECTS = 0,
        GR_GDIOBJECTS_PEAK = 2,
        GR_USEROBJECTS = 1,
        GR_USEROBJECTS_PEAK = 4
    }

    [Flags]
    public enum MOUSEINPUTFlags : uint
    {
        MOUSEEVENTF_ABSOLUTE = 0x00008000,
        MOUSEEVENTF_HWHEEL = 0x00001000,
        MOUSEEVENTF_MOVE = 0x00000001,
        MOUSEEVENTF_MOVE_NOCOALESCE = 0x00002000,
        MOUSEEVENTF_LEFTDOWN = 0x00000002,
        MOUSEEVENTF_LEFTUP = 0x00000004,
        MOUSEEVENTF_RIGHTDOWN = 0x00000008,
        MOUSEEVENTF_RIGHTUP = 0x00000010,
        MOUSEEVENTF_MIDDLEDOWN = 0x00000020,
        MOUSEEVENTF_MIDDLEUP = 0x00000040,
        MOUSEEVENTF_VIRTUALDESK = 0x00004000,
        MOUSEEVENTF_WHEEL = 0x00000800,
        MOUSEEVENTF_XDOWN = 0x00000080,
        MOUSEEVENTF_XUP = 0x00000100
    }

    [Flags]
    public enum FLASHWINFOFlags : uint
    {
        FLASHW_ALL = 0x00000003,
        FLASHW_CAPTION = 0x00000001,
        FLASHW_STOP = 0x00000000,
        FLASHW_TIMER = 0x00000004,
        FLASHW_TIMERNOFG = 0x0000000C,
        FLASHW_TRAY = 0x00000002
    }

    [Flags]
    public enum CreateIconFromResourceExFlags : uint
    {
        LR_DEFAULTCOLOR = 0x00000000,
        LR_DEFAULTSIZE = 0x00000040,
        LR_MONOCHROME = 0x00000001,
        LR_SHARED = 0x00008000
    }

    public enum NETINFOSTRUCT_dwStatusFlags
    {
        NO_ERROR = 0,
        ERROR_NO_NETWORK = 1222,
        ERROR_BUSY = 170
    }

    public enum IDI : ushort
    {
        IDI_APPLICATION = 32512,
        IDI_ASTERISK = 32516,
        IDI_ERROR = 32513,
        IDI_EXCLAMATION = 32515,
        IDI_HAND = 32513,
        IDI_INFORMATION = 32516,
        IDI_QUESTION = 32514,
        IDI_SHIELD = 32518,
        IDI_WARNING = 32515,
        IDI_WINLOGO = 32517
    }

    public enum ActivateKeyboardLayout_hklFlags
    {
        HKL_NEXT = 1,
        HKL_PREV = 0
    }

    public enum GWL
    {
        GWL_EXSTYLE = -20,
        GWL_HINSTANCE = -6,
        GWL_HWNDPARENT = -8,
        GWL_ID = -12,
        GWL_STYLE = -16,
        GWL_USERDATA = -21,
        GWL_WNDPROC = -4
    }

    public enum AnonymousEnum106
    {
        RIM_TYPEHID = 2,
        RIM_TYPEKEYBOARD = 1,
        RIM_TYPEMOUSE = 0
    }

    public enum RegisterTouchWindowFlags
    {
        TWF_FINETOUCH = 1,
        TWF_WANTPALM = 2
    }

    public enum GetNextWindow_wCmdFlags
    {
        GW_HWNDNEXT = 2,
        GW_HWNDPREV = 3
    }

    public enum MB
    {
        MB_ABORTRETRYIGNORE = 2,
        MB_CANCELTRYCONTINUE = 6,
        MB_HELP = 16384,
        MB_OK = 0,
        MB_OKCANCEL = 1,
        MB_RETRYCANCEL = 5,
        MB_YESNO = 4,
        MB_YESNOCANCEL = 3
    }

    [Flags]
    public enum DeferWindowPosFlags : uint
    {
        SWP_DRAWFRAME = 0x00000020,
        SWP_FRAMECHANGED = 0x00000020,
        SWP_HIDEWINDOW = 0x00000080,
        SWP_NOACTIVATE = 0x00000010,
        SWP_NOCOPYBITS = 0x00000100,
        SWP_NOMOVE = 0x00000002,
        SWP_NOOWNERZORDER = 0x00000200,
        SWP_NOREDRAW = 0x00000008,
        SWP_NOREPOSITION = 0x00000200,
        SWP_NOSENDCHANGING = 0x00000400,
        SWP_NOSIZE = 0x00000001,
        SWP_NOZORDER = 0x00000004,
        SWP_SHOWWINDOW = 0x00000040
    }

    [Flags]
    public enum CopyImageFlags : uint
    {
        LR_COPYDELETEORG = 0x00000008,
        LR_COPYFROMRESOURCE = 0x00004000,
        LR_COPYRETURNORG = 0x00000004,
        LR_CREATEDIBSECTION = 0x00002000,
        LR_DEFAULTSIZE = 0x00000040,
        LR_MONOCHROME = 0x00000001
    }

    public enum TileWindows_wHowFlags
    {
        MDITILE_HORIZONTAL = 1,
        MDITILE_VERTICAL = 0
    }
}

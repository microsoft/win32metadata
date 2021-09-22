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


namespace Windows.Win32.System.DesktopSharing
{
    public static partial class Apis
    {
        public const uint DISPID_RDPSRAPI_METHOD_OPEN = 100;

        public const uint DISPID_RDPSRAPI_METHOD_CLOSE = 101;

        public const uint DISPID_RDPSRAPI_METHOD_SETSHAREDRECT = 102;

        public const uint DISPID_RDPSRAPI_METHOD_GETSHAREDRECT = 103;

        public const uint DISPID_RDPSRAPI_METHOD_VIEWERCONNECT = 104;

        public const uint DISPID_RDPSRAPI_METHOD_VIEWERDISCONNECT = 105;

        public const uint DISPID_RDPSRAPI_METHOD_TERMINATE_CONNECTION = 106;

        public const uint DISPID_RDPSRAPI_METHOD_CREATE_INVITATION = 107;

        public const uint DISPID_RDPSRAPI_METHOD_REQUEST_CONTROL = 108;

        public const uint DISPID_RDPSRAPI_METHOD_VIRTUAL_CHANNEL_CREATE = 109;

        public const uint DISPID_RDPSRAPI_METHOD_VIRTUAL_CHANNEL_SEND_DATA = 110;

        public const uint DISPID_RDPSRAPI_METHOD_VIRTUAL_CHANNEL_SET_ACCESS = 111;

        public const uint DISPID_RDPSRAPI_METHOD_PAUSE = 112;

        public const uint DISPID_RDPSRAPI_METHOD_RESUME = 113;

        public const uint DISPID_RDPSRAPI_METHOD_SHOW_WINDOW = 114;

        public const uint DISPID_RDPSRAPI_METHOD_REQUEST_COLOR_DEPTH_CHANGE = 115;

        public const uint DISPID_RDPSRAPI_METHOD_STARTREVCONNECTLISTENER = 116;

        public const uint DISPID_RDPSRAPI_METHOD_CONNECTTOCLIENT = 117;

        public const uint DISPID_RDPSRAPI_METHOD_SET_RENDERING_SURFACE = 118;

        public const uint DISPID_RDPSRAPI_METHOD_SEND_MOUSE_BUTTON_EVENT = 119;

        public const uint DISPID_RDPSRAPI_METHOD_SEND_MOUSE_MOVE_EVENT = 120;

        public const uint DISPID_RDPSRAPI_METHOD_SEND_MOUSE_WHEEL_EVENT = 121;

        public const uint DISPID_RDPSRAPI_METHOD_SEND_KEYBOARD_EVENT = 122;

        public const uint DISPID_RDPSRAPI_METHOD_SEND_SYNC_EVENT = 123;

        public const uint DISPID_RDPSRAPI_METHOD_BEGIN_TOUCH_FRAME = 124;

        public const uint DISPID_RDPSRAPI_METHOD_ADD_TOUCH_INPUT = 125;

        public const uint DISPID_RDPSRAPI_METHOD_END_TOUCH_FRAME = 126;

        public const uint DISPID_RDPSRAPI_METHOD_CONNECTUSINGTRANSPORTSTREAM = 127;

        public const uint DISPID_RDPSRAPI_METHOD_SENDCONTROLLEVELCHANGERESPONSE = 148;

        public const uint DISPID_RDPSRAPI_METHOD_GETFRAMEBUFFERBITS = 149;

        public const uint DISPID_RDPSRAPI_PROP_DISPIDVALUE = 200;

        public const uint DISPID_RDPSRAPI_PROP_ID = 201;

        public const uint DISPID_RDPSRAPI_PROP_SESSION_PROPERTIES = 202;

        public const uint DISPID_RDPSRAPI_PROP_ATTENDEES = 203;

        public const uint DISPID_RDPSRAPI_PROP_INVITATIONS = 204;

        public const uint DISPID_RDPSRAPI_PROP_INVITATION = 205;

        public const uint DISPID_RDPSRAPI_PROP_CHANNELMANAGER = 206;

        public const uint DISPID_RDPSRAPI_PROP_VIRTUAL_CHANNEL_GETNAME = 207;

        public const uint DISPID_RDPSRAPI_PROP_VIRTUAL_CHANNEL_GETFLAGS = 208;

        public const uint DISPID_RDPSRAPI_PROP_VIRTUAL_CHANNEL_GETPRIORITY = 209;

        public const uint DISPID_RDPSRAPI_PROP_WINDOWID = 210;

        public const uint DISPID_RDPSRAPI_PROP_APPLICATION = 211;

        public const uint DISPID_RDPSRAPI_PROP_WINDOWSHARED = 212;

        public const uint DISPID_RDPSRAPI_PROP_WINDOWNAME = 213;

        public const uint DISPID_RDPSRAPI_PROP_APPNAME = 214;

        public const uint DISPID_RDPSRAPI_PROP_APPLICATION_FILTER = 215;

        public const uint DISPID_RDPSRAPI_PROP_WINDOW_LIST = 216;

        public const uint DISPID_RDPSRAPI_PROP_APPLICATION_LIST = 217;

        public const uint DISPID_RDPSRAPI_PROP_APPFILTER_ENABLED = 218;

        public const uint DISPID_RDPSRAPI_PROP_APPFILTERENABLED = 219;

        public const uint DISPID_RDPSRAPI_PROP_SHARED = 220;

        public const uint DISPID_RDPSRAPI_PROP_INVITATIONITEM = 221;

        public const uint DISPID_RDPSRAPI_PROP_DBG_CLX_CMDLINE = 222;

        public const uint DISPID_RDPSRAPI_PROP_APPFLAGS = 223;

        public const uint DISPID_RDPSRAPI_PROP_WNDFLAGS = 224;

        public const uint DISPID_RDPSRAPI_PROP_PROTOCOL_TYPE = 225;

        public const uint DISPID_RDPSRAPI_PROP_LOCAL_PORT = 226;

        public const uint DISPID_RDPSRAPI_PROP_LOCAL_IP = 227;

        public const uint DISPID_RDPSRAPI_PROP_PEER_PORT = 228;

        public const uint DISPID_RDPSRAPI_PROP_PEER_IP = 229;

        public const uint DISPID_RDPSRAPI_PROP_ATTENDEE_FLAGS = 230;

        public const uint DISPID_RDPSRAPI_PROP_CONINFO = 231;

        public const uint DISPID_RDPSRAPI_PROP_CONNECTION_STRING = 232;

        public const uint DISPID_RDPSRAPI_PROP_GROUP_NAME = 233;

        public const uint DISPID_RDPSRAPI_PROP_PASSWORD = 234;

        public const uint DISPID_RDPSRAPI_PROP_ATTENDEELIMIT = 235;

        public const uint DISPID_RDPSRAPI_PROP_REVOKED = 236;

        public const uint DISPID_RDPSRAPI_PROP_DISCONNECTED_STRING = 237;

        public const uint DISPID_RDPSRAPI_PROP_USESMARTSIZING = 238;

        public const uint DISPID_RDPSRAPI_PROP_SESSION_COLORDEPTH = 239;

        public const uint DISPID_RDPSRAPI_PROP_REASON = 240;

        public const uint DISPID_RDPSRAPI_PROP_CODE = 241;

        public const uint DISPID_RDPSRAPI_PROP_CTRL_LEVEL = 242;

        public const uint DISPID_RDPSRAPI_PROP_REMOTENAME = 243;

        public const uint DISPID_RDPSRAPI_PROP_COUNT = 244;

        public const uint DISPID_RDPSRAPI_PROP_FRAMEBUFFER_HEIGHT = 251;

        public const uint DISPID_RDPSRAPI_PROP_FRAMEBUFFER_WIDTH = 252;

        public const uint DISPID_RDPSRAPI_PROP_FRAMEBUFFER_BPP = 253;

        public const uint DISPID_RDPSRAPI_PROP_FRAMEBUFFER = 254;

        public const uint DISPID_RDPSRAPI_EVENT_ON_ATTENDEE_CONNECTED = 301;

        public const uint DISPID_RDPSRAPI_EVENT_ON_ATTENDEE_DISCONNECTED = 302;

        public const uint DISPID_RDPSRAPI_EVENT_ON_ATTENDEE_UPDATE = 303;

        public const uint DISPID_RDPSRAPI_EVENT_ON_ERROR = 304;

        public const uint DISPID_RDPSRAPI_EVENT_ON_VIEWER_CONNECTED = 305;

        public const uint DISPID_RDPSRAPI_EVENT_ON_VIEWER_DISCONNECTED = 306;

        public const uint DISPID_RDPSRAPI_EVENT_ON_VIEWER_AUTHENTICATED = 307;

        public const uint DISPID_RDPSRAPI_EVENT_ON_VIEWER_CONNECTFAILED = 308;

        public const uint DISPID_RDPSRAPI_EVENT_ON_CTRLLEVEL_CHANGE_REQUEST = 309;

        public const uint DISPID_RDPSRAPI_EVENT_ON_GRAPHICS_STREAM_PAUSED = 310;

        public const uint DISPID_RDPSRAPI_EVENT_ON_GRAPHICS_STREAM_RESUMED = 311;

        public const uint DISPID_RDPSRAPI_EVENT_ON_VIRTUAL_CHANNEL_JOIN = 312;

        public const uint DISPID_RDPSRAPI_EVENT_ON_VIRTUAL_CHANNEL_LEAVE = 313;

        public const uint DISPID_RDPSRAPI_EVENT_ON_VIRTUAL_CHANNEL_DATARECEIVED = 314;

        public const uint DISPID_RDPSRAPI_EVENT_ON_VIRTUAL_CHANNEL_SENDCOMPLETED = 315;

        public const uint DISPID_RDPSRAPI_EVENT_ON_APPLICATION_OPEN = 316;

        public const uint DISPID_RDPSRAPI_EVENT_ON_APPLICATION_CLOSE = 317;

        public const uint DISPID_RDPSRAPI_EVENT_ON_APPLICATION_UPDATE = 318;

        public const uint DISPID_RDPSRAPI_EVENT_ON_WINDOW_OPEN = 319;

        public const uint DISPID_RDPSRAPI_EVENT_ON_WINDOW_CLOSE = 320;

        public const uint DISPID_RDPSRAPI_EVENT_ON_WINDOW_UPDATE = 321;

        public const uint DISPID_RDPSRAPI_EVENT_ON_APPFILTER_UPDATE = 322;

        public const uint DISPID_RDPSRAPI_EVENT_ON_SHARED_RECT_CHANGED = 323;

        public const uint DISPID_RDPSRAPI_EVENT_ON_FOCUSRELEASED = 324;

        public const uint DISPID_RDPSRAPI_EVENT_ON_SHARED_DESKTOP_SETTINGS_CHANGED = 325;

        public const uint DISPID_RDPSRAPI_EVENT_ON_CTRLLEVEL_CHANGE_RESPONSE = 338;

        public const uint DISPID_RDPAPI_EVENT_ON_BOUNDING_RECT_CHANGED = 340;

        public const uint DISPID_RDPSRAPI_METHOD_STREAM_ALLOCBUFFER = 421;

        public const uint DISPID_RDPSRAPI_METHOD_STREAM_FREEBUFFER = 422;

        public const uint DISPID_RDPSRAPI_METHOD_STREAMSENDDATA = 423;

        public const uint DISPID_RDPSRAPI_METHOD_STREAMREADDATA = 424;

        public const uint DISPID_RDPSRAPI_METHOD_STREAMOPEN = 425;

        public const uint DISPID_RDPSRAPI_METHOD_STREAMCLOSE = 426;

        public const uint DISPID_RDPSRAPI_PROP_STREAMBUFFER_STORAGE = 555;

        public const uint DISPID_RDPSRAPI_PROP_STREAMBUFFER_PAYLOADSIZE = 558;

        public const uint DISPID_RDPSRAPI_PROP_STREAMBUFFER_PAYLOADOFFSET = 559;

        public const uint DISPID_RDPSRAPI_PROP_STREAMBUFFER_CONTEXT = 560;

        public const uint DISPID_RDPSRAPI_PROP_STREAMBUFFER_FLAGS = 561;

        public const uint DISPID_RDPSRAPI_PROP_STREAMBUFFER_STORESIZE = 562;

        public const uint DISPID_RDPSRAPI_EVENT_ON_STREAM_SENDCOMPLETED = 632;

        public const uint DISPID_RDPSRAPI_EVENT_ON_STREAM_DATARECEIVED = 633;

        public const uint DISPID_RDPSRAPI_EVENT_ON_STREAM_CLOSED = 634;

        public const uint DISPID_RDPSRAPI_EVENT_VIEW_MOUSE_BUTTON_RECEIVED = 700;

        public const uint DISPID_RDPSRAPI_EVENT_VIEW_MOUSE_MOVE_RECEIVED = 701;

        public const uint DISPID_RDPSRAPI_EVENT_VIEW_MOUSE_WHEEL_RECEIVED = 702;

    }
}

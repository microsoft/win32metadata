/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

        HIDUSAGE.H

Abstract:

   Public Definitions of HID USAGES.

Environment:

    Kernel & user mode

--*/

#ifndef   __HIDUSAGE_H__
#define   __HIDUSAGE_H__
#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


//
// Usage Pages
//

typedef USHORT USAGE, *PUSAGE;

#define HID_USAGE_PAGE_UNDEFINED                        ((USAGE) 0x00)
#define HID_USAGE_PAGE_GENERIC                          ((USAGE) 0x01)
#define HID_USAGE_PAGE_SIMULATION                       ((USAGE) 0x02)
#define HID_USAGE_PAGE_VR                               ((USAGE) 0x03)
#define HID_USAGE_PAGE_SPORT                            ((USAGE) 0x04)
#define HID_USAGE_PAGE_GAME                             ((USAGE) 0x05)
#define HID_USAGE_PAGE_GENERIC_DEVICE                   ((USAGE) 0x06)
#define HID_USAGE_PAGE_KEYBOARD                         ((USAGE) 0x07)
#define HID_USAGE_PAGE_LED                              ((USAGE) 0x08)
#define HID_USAGE_PAGE_BUTTON                           ((USAGE) 0x09)
#define HID_USAGE_PAGE_ORDINAL                          ((USAGE) 0x0A)
#define HID_USAGE_PAGE_TELEPHONY                        ((USAGE) 0x0B)
#define HID_USAGE_PAGE_CONSUMER                         ((USAGE) 0x0C)
#define HID_USAGE_PAGE_DIGITIZER                        ((USAGE) 0x0D)
#define HID_USAGE_PAGE_HAPTICS                          ((USAGE) 0x0E)
#define HID_USAGE_PAGE_PID                              ((USAGE) 0x0F)
#define HID_USAGE_PAGE_UNICODE                          ((USAGE) 0x10)
#define HID_USAGE_PAGE_ALPHANUMERIC                     ((USAGE) 0x14)
#define HID_USAGE_PAGE_SENSOR                           ((USAGE) 0x20)
#define HID_USAGE_PAGE_LIGHTING_ILLUMINATION            ((USAGE) 0x59)
#define HID_USAGE_PAGE_BARCODE_SCANNER                  ((USAGE) 0x8C)
#define HID_USAGE_PAGE_WEIGHING_DEVICE                  ((USAGE) 0x8D)
#define HID_USAGE_PAGE_MAGNETIC_STRIPE_READER           ((USAGE) 0x8E)
#define HID_USAGE_PAGE_CAMERA_CONTROL                   ((USAGE) 0x90)
#define HID_USAGE_PAGE_ARCADE                           ((USAGE) 0x91)
#define HID_USAGE_PAGE_MICROSOFT_BLUETOOTH_HANDSFREE    ((USAGE) 0xFFF3)
#define HID_USAGE_PAGE_VENDOR_DEFINED_BEGIN             ((USAGE) 0xFF00)
#define HID_USAGE_PAGE_VENDOR_DEFINED_END               ((USAGE) 0xFFFF)

//
// Generic Desktop Page (0x01)
//
#define HID_USAGE_GENERIC_POINTER                                       ((USAGE) 0x01)
#define HID_USAGE_GENERIC_MOUSE                                         ((USAGE) 0x02)
#define HID_USAGE_GENERIC_JOYSTICK                                      ((USAGE) 0x04)
#define HID_USAGE_GENERIC_GAMEPAD                                       ((USAGE) 0x05)
#define HID_USAGE_GENERIC_KEYBOARD                                      ((USAGE) 0x06)
#define HID_USAGE_GENERIC_KEYPAD                                        ((USAGE) 0x07)
#define HID_USAGE_GENERIC_MULTI_AXIS_CONTROLLER                         ((USAGE) 0x08)
#define HID_USAGE_GENERIC_TABLET_PC_SYSTEM_CTL                          ((USAGE) 0x09)
#define HID_USAGE_GENERIC_PORTABLE_DEVICE_CONTROL                       ((USAGE) 0x0D)
#define HID_USAGE_GENERIC_INTERACTIVE_CONTROL                           ((USAGE) 0x0E)
#define HID_USAGE_GENERIC_COUNTED_BUFFER                                ((USAGE) 0x3A)
#define HID_USAGE_GENERIC_SYSTEM_CTL                                    ((USAGE) 0x80)

#define HID_USAGE_GENERIC_X                                             ((USAGE) 0x30)
#define HID_USAGE_GENERIC_Y                                             ((USAGE) 0x31)
#define HID_USAGE_GENERIC_Z                                             ((USAGE) 0x32)
#define HID_USAGE_GENERIC_RX                                            ((USAGE) 0x33)
#define HID_USAGE_GENERIC_RY                                            ((USAGE) 0x34)
#define HID_USAGE_GENERIC_RZ                                            ((USAGE) 0x35)
#define HID_USAGE_GENERIC_SLIDER                                        ((USAGE) 0x36)
#define HID_USAGE_GENERIC_DIAL                                          ((USAGE) 0x37)
#define HID_USAGE_GENERIC_WHEEL                                         ((USAGE) 0x38)
#define HID_USAGE_GENERIC_HATSWITCH                                     ((USAGE) 0x39)
#define HID_USAGE_GENERIC_COUNTED_BUFFER                                ((USAGE) 0x3A)
#define HID_USAGE_GENERIC_BYTE_COUNT                                    ((USAGE) 0x3B)
#define HID_USAGE_GENERIC_MOTION_WAKEUP                                 ((USAGE) 0x3C)
#define HID_USAGE_GENERIC_START                                         ((USAGE) 0x3D)
#define HID_USAGE_GENERIC_SELECT                                        ((USAGE) 0x3E)
#define HID_USAGE_GENERIC_VX                                            ((USAGE) 0x40)
#define HID_USAGE_GENERIC_VY                                            ((USAGE) 0x41)
#define HID_USAGE_GENERIC_VZ                                            ((USAGE) 0x42)
#define HID_USAGE_GENERIC_VBRX                                          ((USAGE) 0x43)
#define HID_USAGE_GENERIC_VBRY                                          ((USAGE) 0x44)
#define HID_USAGE_GENERIC_VBRZ                                          ((USAGE) 0x45)
#define HID_USAGE_GENERIC_VNO                                           ((USAGE) 0x46)
#define HID_USAGE_GENERIC_FEATURE_NOTIFICATION                          ((USAGE) 0x47)
#define HID_USAGE_GENERIC_RESOLUTION_MULTIPLIER                         ((USAGE) 0x48)
#define HID_USAGE_GENERIC_SYSCTL_POWER                                  ((USAGE) 0x81)
#define HID_USAGE_GENERIC_SYSCTL_SLEEP                                  ((USAGE) 0x82)
#define HID_USAGE_GENERIC_SYSCTL_WAKE                                   ((USAGE) 0x83)
#define HID_USAGE_GENERIC_SYSCTL_CONTEXT_MENU                           ((USAGE) 0x84)
#define HID_USAGE_GENERIC_SYSCTL_MAIN_MENU                              ((USAGE) 0x85)
#define HID_USAGE_GENERIC_SYSCTL_APP_MENU                               ((USAGE) 0x86)
#define HID_USAGE_GENERIC_SYSCTL_HELP_MENU                              ((USAGE) 0x87)
#define HID_USAGE_GENERIC_SYSCTL_MENU_EXIT                              ((USAGE) 0x88)
#define HID_USAGE_GENERIC_SYSCTL_MENU_SELECT                            ((USAGE) 0x89)
#define HID_USAGE_GENERIC_SYSCTL_MENU_RIGHT                             ((USAGE) 0x8A)
#define HID_USAGE_GENERIC_SYSCTL_MENU_LEFT                              ((USAGE) 0x8B)
#define HID_USAGE_GENERIC_SYSCTL_MENU_UP                                ((USAGE) 0x8C)
#define HID_USAGE_GENERIC_SYSCTL_MENU_DOWN                              ((USAGE) 0x8D)
#define HID_USAGE_GENERIC_SYSCTL_COLD_RESTART                           ((USAGE) 0x8E)
#define HID_USAGE_GENERIC_SYSCTL_WARM_RESTART                           ((USAGE) 0x8F)
#define HID_USAGE_GENERIC_DPAD_UP                                       ((USAGE) 0x90)
#define HID_USAGE_GENERIC_DPAD_DOWN                                     ((USAGE) 0x91)
#define HID_USAGE_GENERIC_DPAD_RIGHT                                    ((USAGE) 0x92)
#define HID_USAGE_GENERIC_DPAD_LEFT                                     ((USAGE) 0x93)
#define HID_USAGE_GENERIC_SYSCTL_FN                                     ((USAGE) 0x97)
#define HID_USAGE_GENERIC_SYSCTL_FN_LOCK                                ((USAGE) 0x98)
#define HID_USAGE_GENERIC_SYSCTL_FN_LOCK_INDICATOR                      ((USAGE) 0x99)
#define HID_USAGE_GENERIC_SYSCTL_DISMISS_NOTIFICATION                   ((USAGE) 0x9A)
#define HID_USAGE_GENERIC_SYSCTL_DOCK                                   ((USAGE) 0xA0)
#define HID_USAGE_GENERIC_SYSCTL_UNDOCK                                 ((USAGE) 0xA1)
#define HID_USAGE_GENERIC_SYSCTL_SETUP                                  ((USAGE) 0xA2)
#define HID_USAGE_GENERIC_SYSCTL_SYS_BREAK                              ((USAGE) 0xA3)
#define HID_USAGE_GENERIC_SYSCTL_SYS_DBG_BREAK                          ((USAGE) 0xA4)
#define HID_USAGE_GENERIC_SYSCTL_APP_BREAK                              ((USAGE) 0xA5)
#define HID_USAGE_GENERIC_SYSCTL_APP_DBG_BREAK                          ((USAGE) 0xA6)
#define HID_USAGE_GENERIC_SYSCTL_MUTE                                   ((USAGE) 0xA7)
#define HID_USAGE_GENERIC_SYSCTL_HIBERNATE                              ((USAGE) 0xA8)
#define HID_USAGE_GENERIC_SYSCTL_DISP_INVERT                            ((USAGE) 0xB0)
#define HID_USAGE_GENERIC_SYSCTL_DISP_INTERNAL                          ((USAGE) 0xB1)
#define HID_USAGE_GENERIC_SYSCTL_DISP_EXTERNAL                          ((USAGE) 0xB2)
#define HID_USAGE_GENERIC_SYSCTL_DISP_BOTH                              ((USAGE) 0xB3)
#define HID_USAGE_GENERIC_SYSCTL_DISP_DUAL                              ((USAGE) 0xB4)
#define HID_USAGE_GENERIC_SYSCTL_DISP_TOGGLE                            ((USAGE) 0xB5)
#define HID_USAGE_GENERIC_SYSCTL_DISP_SWAP                              ((USAGE) 0xB6)
#define HID_USAGE_GENERIC_SYSCTL_DISP_AUTOSCALE                         ((USAGE) 0xB7)
#define HID_USAGE_GENERIC_SYSTEM_DISPLAY_ROTATION_LOCK_BUTTON           ((USAGE) 0xC9)
#define HID_USAGE_GENERIC_SYSTEM_DISPLAY_ROTATION_LOCK_SLIDER_SWITCH    ((USAGE) 0xCA)
#define HID_USAGE_GENERIC_CONTROL_ENABLE                                ((USAGE) 0xCB)

//
// Simulation Controls Page (0x02)
//
#define HID_USAGE_SIMULATION_FLIGHT_SIMULATION_DEVICE          ((USAGE) 0x01)
#define HID_USAGE_SIMULATION_AUTOMOBILE_SIMULATION_DEVICE      ((USAGE) 0x02)
#define HID_USAGE_SIMULATION_TANK_SIMULATION_DEVICE            ((USAGE) 0x03)
#define HID_USAGE_SIMULATION_SPACESHIP_SIMULATION_DEVICE       ((USAGE) 0x04)
#define HID_USAGE_SIMULATION_SUBMARINE_SIMULATION_DEVICE       ((USAGE) 0x05)
#define HID_USAGE_SIMULATION_SAILING_SIMULATION_DEVICE         ((USAGE) 0x06)
#define HID_USAGE_SIMULATION_MOTORCYCLE_SIMULATION_DEVICE      ((USAGE) 0x07)
#define HID_USAGE_SIMULATION_SPORTS_SIMULATION_DEVICE          ((USAGE) 0x08)
#define HID_USAGE_SIMULATION_AIRPLANE_SIMULATION_DEVICE        ((USAGE) 0x09)
#define HID_USAGE_SIMULATION_HELICOPTER_SIMULATION_DEVICE      ((USAGE) 0x0A)
#define HID_USAGE_SIMULATION_MAGIC_CARPET_SIMULATION_DEVICE    ((USAGE) 0x0B)
#define HID_USAGE_SIMULATION_BICYCLE_SIMULATION_DEVICE         ((USAGE) 0x0C)
#define HID_USAGE_SIMULATION_FLIGHT_CONTROL_STICK              ((USAGE) 0x20)
#define HID_USAGE_SIMULATION_FLIGHT_STICK                      ((USAGE) 0x21)
#define HID_USAGE_SIMULATION_CYCLIC_CONTROL                    ((USAGE) 0x22)
#define HID_USAGE_SIMULATION_CYCLIC_TRIM                       ((USAGE) 0x23)
#define HID_USAGE_SIMULATION_FLIGHT_YOKE                       ((USAGE) 0x24)
#define HID_USAGE_SIMULATION_TRACK_CONTROL                     ((USAGE) 0x25)

#define HID_USAGE_SIMULATION_AILERON                           ((USAGE) 0xB0)
#define HID_USAGE_SIMULATION_AILERON_TRIM                      ((USAGE) 0xB1)
#define HID_USAGE_SIMULATION_ANTI_TORQUE_CONTROL               ((USAGE) 0xB2)
#define HID_USAGE_SIMULATION_AUTOPIOLOT_ENABLE                 ((USAGE) 0xB3)
#define HID_USAGE_SIMULATION_CHAFF_RELEASE                     ((USAGE) 0xB4)
#define HID_USAGE_SIMULATION_COLLECTIVE_CONTROL                ((USAGE) 0xB5)
#define HID_USAGE_SIMULATION_DIVE_BRAKE                        ((USAGE) 0xB6)
#define HID_USAGE_SIMULATION_ELECTRONIC_COUNTERMEASURES        ((USAGE) 0xB7)
#define HID_USAGE_SIMULATION_ELEVATOR                          ((USAGE) 0xB8)
#define HID_USAGE_SIMULATION_ELEVATOR_TRIM                     ((USAGE) 0xB9)
#define HID_USAGE_SIMULATION_RUDDER                            ((USAGE) 0xBA)
#define HID_USAGE_SIMULATION_THROTTLE                          ((USAGE) 0xBB)
#define HID_USAGE_SIMULATION_FLIGHT_COMMUNICATIONS             ((USAGE) 0xBC)
#define HID_USAGE_SIMULATION_FLARE_RELEASE                     ((USAGE) 0xBD)
#define HID_USAGE_SIMULATION_LANDING_GEAR                      ((USAGE) 0xBE)
#define HID_USAGE_SIMULATION_TOE_BRAKE                         ((USAGE) 0xBF)
#define HID_USAGE_SIMULATION_TRIGGER                           ((USAGE) 0xC0)
#define HID_USAGE_SIMULATION_WEAPONS_ARM                       ((USAGE) 0xC1)
#define HID_USAGE_SIMULATION_WEAPONS_SELECT                    ((USAGE) 0xC2)
#define HID_USAGE_SIMULATION_WING_FLAPS                        ((USAGE) 0xC3)
#define HID_USAGE_SIMULATION_ACCELLERATOR                      ((USAGE) 0xC4)
#define HID_USAGE_SIMULATION_BRAKE                             ((USAGE) 0xC5)
#define HID_USAGE_SIMULATION_CLUTCH                            ((USAGE) 0xC6)
#define HID_USAGE_SIMULATION_SHIFTER                           ((USAGE) 0xC7)
#define HID_USAGE_SIMULATION_STEERING                          ((USAGE) 0xC8)
#define HID_USAGE_SIMULATION_TURRET_DIRECTION                  ((USAGE) 0xC9)
#define HID_USAGE_SIMULATION_BARREL_ELEVATION                  ((USAGE) 0xCA)
#define HID_USAGE_SIMULATION_DIVE_PLANE                        ((USAGE) 0xCB)
#define HID_USAGE_SIMULATION_BALLAST                           ((USAGE) 0xCC)
#define HID_USAGE_SIMULATION_BICYCLE_CRANK                     ((USAGE) 0xCD)
#define HID_USAGE_SIMULATION_HANDLE_BARS                       ((USAGE) 0xCE)
#define HID_USAGE_SIMULATION_FRONT_BRAKE                       ((USAGE) 0xCF)
#define HID_USAGE_SIMULATION_REAR_BRAKE                        ((USAGE) 0xD0)

//
// Virtual Reality Controls Page (0x03)
//
#define HID_USAGE_VR_BELT                    ((USAGE) 0x01)
#define HID_USAGE_VR_BODY_SUIT               ((USAGE) 0x02)
#define HID_USAGE_VR_FLEXOR                  ((USAGE) 0x03)
#define HID_USAGE_VR_GLOVE                   ((USAGE) 0x04)
#define HID_USAGE_VR_HEAD_TRACKER            ((USAGE) 0x05)
#define HID_USAGE_VR_HEAD_MOUNTED_DISPLAY    ((USAGE) 0x06)
#define HID_USAGE_VR_HAND_TRACKER            ((USAGE) 0x07)
#define HID_USAGE_VR_OCULOMETER              ((USAGE) 0x08)
#define HID_USAGE_VR_VEST                    ((USAGE) 0x09)
#define HID_USAGE_VR_ANIMATRONIC_DEVICE      ((USAGE) 0x0A)

#define HID_USAGE_VR_STEREO_ENABLE           ((USAGE) 0x20)
#define HID_USAGE_VR_DISPLAY_ENABLE          ((USAGE) 0x21)

//
// Sport Controls Page (0x04)
//
#define HID_USAGE_SPORT_BASEBALL_BAT        ((USAGE) 0x01)
#define HID_USAGE_SPORT_GOLF_CLUB           ((USAGE) 0x02)
#define HID_USAGE_SPORT_ROWING_MACHINE      ((USAGE) 0x03)
#define HID_USAGE_SPORT_TREADMILL           ((USAGE) 0x04)
#define HID_USAGE_SPORT_STICK_TYPE          ((USAGE) 0x38)

#define HID_USAGE_SPORT_OAR                 ((USAGE) 0x30)
#define HID_USAGE_SPORT_SLOPE               ((USAGE) 0x31)
#define HID_USAGE_SPORT_RATE                ((USAGE) 0x32)
#define HID_USAGE_SPORT_STICK_SPEED         ((USAGE) 0x33)
#define HID_USAGE_SPORT_STICK_FACE_ANGLE    ((USAGE) 0x34)
#define HID_USAGE_SPORT_HEEL_TOE            ((USAGE) 0x35)
#define HID_USAGE_SPORT_FOLLOW_THROUGH      ((USAGE) 0x36)
#define HID_USAGE_SPORT_TEMPO               ((USAGE) 0x37)
#define HID_USAGE_SPORT_HEIGHT              ((USAGE) 0x39)
#define HID_USAGE_SPORT_PUTTER              ((USAGE) 0x50)
#define HID_USAGE_SPORT_1_IRON              ((USAGE) 0x51)
#define HID_USAGE_SPORT_2_IRON              ((USAGE) 0x52)
#define HID_USAGE_SPORT_3_IRON              ((USAGE) 0x53)
#define HID_USAGE_SPORT_4_IRON              ((USAGE) 0x54)
#define HID_USAGE_SPORT_5_IRON              ((USAGE) 0x55)
#define HID_USAGE_SPORT_6_IRON              ((USAGE) 0x56)
#define HID_USAGE_SPORT_7_IRON              ((USAGE) 0x57)
#define HID_USAGE_SPORT_8_IRON              ((USAGE) 0x58)
#define HID_USAGE_SPORT_9_IRON              ((USAGE) 0x59)
#define HID_USAGE_SPORT_10_IRON             ((USAGE) 0x5A)
#define HID_USAGE_SPORT_11_IRON             ((USAGE) 0x5B)
#define HID_USAGE_SPORT_SAND_WEDGE          ((USAGE) 0x5C)
#define HID_USAGE_SPORT_LOFT_WEDGE          ((USAGE) 0x5D)
#define HID_USAGE_SPORT_POWER_WEDGE         ((USAGE) 0x5E)
#define HID_USAGE_SPORT_1_WOOD              ((USAGE) 0x5F)
#define HID_USAGE_SPORT_3_WOOD              ((USAGE) 0x60)
#define HID_USAGE_SPORT_5_WOOD              ((USAGE) 0x61)
#define HID_USAGE_SPORT_7_WOOD              ((USAGE) 0x62)
#define HID_USAGE_SPORT_9_WOOD              ((USAGE) 0x63)

//
// Game Controls Page (0x05)
//
#define HID_USAGE_GAME_3D_GAME_CONTROLLER    ((USAGE) 0x01)
#define HID_USAGE_GAME_PINBALL_DEVICE        ((USAGE) 0x02)
#define HID_USAGE_GAME_GUN_DEVICE            ((USAGE) 0x03)
#define HID_USAGE_GAME_POINT_OF_VIEW         ((USAGE) 0x20)
#define HID_USAGE_GAME_GUN_SELECTOR          ((USAGE) 0x32)
#define HID_USAGE_GAME_GAMEPAD_FIRE_JUMP     ((USAGE) 0x37)
#define HID_USAGE_GAME_GAMEPAD_TRIGGER       ((USAGE) 0x39)

#define HID_USAGE_GAME_TURN_RIGHT_LEFT       ((USAGE) 0x21)
#define HID_USAGE_GAME_PITCH_FORWARD_BACK    ((USAGE) 0x22)
#define HID_USAGE_GAME_ROLL_RIGHT_LEFT       ((USAGE) 0x23)
#define HID_USAGE_GAME_MOVE_RIGHT_LEFT       ((USAGE) 0x24)
#define HID_USAGE_GAME_MOVE_FORWARD_BACK     ((USAGE) 0x25)
#define HID_USAGE_GAME_MOVE_UP_DOWN          ((USAGE) 0x26)
#define HID_USAGE_GAME_LEAN_RIGHT_LEFT       ((USAGE) 0x27)
#define HID_USAGE_GAME_LEAN_FORWARD_BACK     ((USAGE) 0x28)
#define HID_USAGE_GAME_POV_HEIGHT            ((USAGE) 0x29)
#define HID_USAGE_GAME_FLIPPER               ((USAGE) 0x2A)
#define HID_USAGE_GAME_SECONDARY_FLIPPER     ((USAGE) 0x2B)
#define HID_USAGE_GAME_BUMP                  ((USAGE) 0x2C)
#define HID_USAGE_GAME_NEW_GAME              ((USAGE) 0x2D)
#define HID_USAGE_GAME_SHOOT_BALL            ((USAGE) 0x2E)
#define HID_USAGE_GAME_PLAYER                ((USAGE) 0x2F)
#define HID_USAGE_GAME_GUN_BOLT              ((USAGE) 0x30)
#define HID_USAGE_GAME_GUN_CLIP              ((USAGE) 0x31)
#define HID_USAGE_GAME_GUN_SINGLE_SHOT       ((USAGE) 0x33)
#define HID_USAGE_GAME_GUN_BURST             ((USAGE) 0x34)
#define HID_USAGE_GAME_GUN_AUTOMATIC         ((USAGE) 0x35)
#define HID_USAGE_GAME_GUN_SAFETY            ((USAGE) 0x36)

//
// Generic Device Controls Page (0x06)
//
#define HID_USAGE_GENERIC_DEVICE_BATTERY_STRENGTH              ((USAGE) 0x20)
#define HID_USAGE_GENERIC_DEVICE_WIRELESS_CHANNEL              ((USAGE) 0x21)
#define HID_USAGE_GENERIC_DEVICE_WIRELESS_ID                   ((USAGE) 0x22)
#define HID_USAGE_GENERIC_DEVICE_DISCOVER_WIRELESS_CONTROL     ((USAGE) 0x23)
#define HID_USAGE_GENERIC_DEVICE_SECURITY_CODE_CHAR_ENTERED    ((USAGE) 0x24)
#define HID_USAGE_GENERIC_DEVICE_SECURITY_CODE_CHAR_ERASED     ((USAGE) 0x25)
#define HID_USAGE_GENERIC_DEVICE_SECURITY_CODE_CLEARED         ((USAGE) 0x26)

//
// Keyboard/Keypad Page (0x07)
//

// Error "keys"
#define HID_USAGE_KEYBOARD_NOEVENT     ((USAGE) 0x00)
#define HID_USAGE_KEYBOARD_ROLLOVER    ((USAGE) 0x01)
#define HID_USAGE_KEYBOARD_POSTFAIL    ((USAGE) 0x02)
#define HID_USAGE_KEYBOARD_UNDEFINED   ((USAGE) 0x03)

// Letters
#define HID_USAGE_KEYBOARD_aA          ((USAGE) 0x04)
#define HID_USAGE_KEYBOARD_zZ          ((USAGE) 0x1D)

// Numbers
#define HID_USAGE_KEYBOARD_ONE         ((USAGE) 0x1E)
#define HID_USAGE_KEYBOARD_ZERO        ((USAGE) 0x27)

// Modifier Keys
#define HID_USAGE_KEYBOARD_LCTRL       ((USAGE) 0xE0)
#define HID_USAGE_KEYBOARD_LSHFT       ((USAGE) 0xE1)
#define HID_USAGE_KEYBOARD_LALT        ((USAGE) 0xE2)
#define HID_USAGE_KEYBOARD_LGUI        ((USAGE) 0xE3)
#define HID_USAGE_KEYBOARD_RCTRL       ((USAGE) 0xE4)
#define HID_USAGE_KEYBOARD_RSHFT       ((USAGE) 0xE5)
#define HID_USAGE_KEYBOARD_RALT        ((USAGE) 0xE6)
#define HID_USAGE_KEYBOARD_RGUI        ((USAGE) 0xE7)
#define HID_USAGE_KEYBOARD_SCROLL_LOCK ((USAGE) 0x47)
#define HID_USAGE_KEYBOARD_NUM_LOCK    ((USAGE) 0x53)
#define HID_USAGE_KEYBOARD_CAPS_LOCK   ((USAGE) 0x39)

// Function keys
#define HID_USAGE_KEYBOARD_F1          ((USAGE) 0x3A)
#define HID_USAGE_KEYBOARD_F2          ((USAGE) 0x3B)
#define HID_USAGE_KEYBOARD_F3          ((USAGE) 0x3C)
#define HID_USAGE_KEYBOARD_F4          ((USAGE) 0x3D)
#define HID_USAGE_KEYBOARD_F5          ((USAGE) 0x3E)
#define HID_USAGE_KEYBOARD_F6          ((USAGE) 0x3F)
#define HID_USAGE_KEYBOARD_F7          ((USAGE) 0x40)
#define HID_USAGE_KEYBOARD_F8          ((USAGE) 0x41)
#define HID_USAGE_KEYBOARD_F9          ((USAGE) 0x42)
#define HID_USAGE_KEYBOARD_F10         ((USAGE) 0x43)
#define HID_USAGE_KEYBOARD_F11         ((USAGE) 0x44)
#define HID_USAGE_KEYBOARD_F12         ((USAGE) 0x45)
#define HID_USAGE_KEYBOARD_F13         ((USAGE) 0x68)
#define HID_USAGE_KEYBOARD_F14         ((USAGE) 0x69)
#define HID_USAGE_KEYBOARD_F15         ((USAGE) 0x6A)
#define HID_USAGE_KEYBOARD_F16         ((USAGE) 0x6B)
#define HID_USAGE_KEYBOARD_F17         ((USAGE) 0x6C)
#define HID_USAGE_KEYBOARD_F18         ((USAGE) 0x6D)
#define HID_USAGE_KEYBOARD_F19         ((USAGE) 0x6E)
#define HID_USAGE_KEYBOARD_F20         ((USAGE) 0x6F)
#define HID_USAGE_KEYBOARD_F21         ((USAGE) 0x70)
#define HID_USAGE_KEYBOARD_F22         ((USAGE) 0x71)
#define HID_USAGE_KEYBOARD_F23         ((USAGE) 0x72)
#define HID_USAGE_KEYBOARD_F24         ((USAGE) 0x73)

#define HID_USAGE_KEYBOARD_RETURN      ((USAGE) 0x28)
#define HID_USAGE_KEYBOARD_ESCAPE      ((USAGE) 0x29)
#define HID_USAGE_KEYBOARD_DELETE      ((USAGE) 0x2A)

#define HID_USAGE_KEYBOARD_PRINT_SCREEN      ((USAGE) 0x46)
#define HID_USAGE_KEYBOARD_DELETE_FORWARD    ((USAGE) 0x4C)


//
// LED Page (0x08)
//
#define HID_USAGE_LED_NUM_LOCK               ((USAGE) 0x01)
#define HID_USAGE_LED_CAPS_LOCK              ((USAGE) 0x02)
#define HID_USAGE_LED_SCROLL_LOCK            ((USAGE) 0x03)
#define HID_USAGE_LED_COMPOSE                ((USAGE) 0x04)
#define HID_USAGE_LED_KANA                   ((USAGE) 0x05)
#define HID_USAGE_LED_POWER                  ((USAGE) 0x06)
#define HID_USAGE_LED_SHIFT                  ((USAGE) 0x07)
#define HID_USAGE_LED_DO_NOT_DISTURB         ((USAGE) 0x08)
#define HID_USAGE_LED_MUTE                   ((USAGE) 0x09)
#define HID_USAGE_LED_TONE_ENABLE            ((USAGE) 0x0A)
#define HID_USAGE_LED_HIGH_CUT_FILTER        ((USAGE) 0x0B)
#define HID_USAGE_LED_LOW_CUT_FILTER         ((USAGE) 0x0C)
#define HID_USAGE_LED_EQUALIZER_ENABLE       ((USAGE) 0x0D)
#define HID_USAGE_LED_SOUND_FIELD_ON         ((USAGE) 0x0E)
#define HID_USAGE_LED_SURROUND_FIELD_ON      ((USAGE) 0x0F)
#define HID_USAGE_LED_REPEAT                 ((USAGE) 0x10)
#define HID_USAGE_LED_STEREO                 ((USAGE) 0x11)
#define HID_USAGE_LED_SAMPLING_RATE_DETECT   ((USAGE) 0x12)
#define HID_USAGE_LED_SPINNING               ((USAGE) 0x13)
#define HID_USAGE_LED_CAV                    ((USAGE) 0x14)
#define HID_USAGE_LED_CLV                    ((USAGE) 0x15)
#define HID_USAGE_LED_RECORDING_FORMAT_DET   ((USAGE) 0x16)
#define HID_USAGE_LED_OFF_HOOK               ((USAGE) 0x17)
#define HID_USAGE_LED_RING                   ((USAGE) 0x18)
#define HID_USAGE_LED_MESSAGE_WAITING        ((USAGE) 0x19)
#define HID_USAGE_LED_DATA_MODE              ((USAGE) 0x1A)
#define HID_USAGE_LED_BATTERY_OPERATION      ((USAGE) 0x1B)
#define HID_USAGE_LED_BATTERY_OK             ((USAGE) 0x1C)
#define HID_USAGE_LED_BATTERY_LOW            ((USAGE) 0x1D)
#define HID_USAGE_LED_SPEAKER                ((USAGE) 0x1E)
#define HID_USAGE_LED_HEAD_SET               ((USAGE) 0x1F)
#define HID_USAGE_LED_HOLD                   ((USAGE) 0x20)
#define HID_USAGE_LED_MICROPHONE             ((USAGE) 0x21)
#define HID_USAGE_LED_COVERAGE               ((USAGE) 0x22)
#define HID_USAGE_LED_NIGHT_MODE             ((USAGE) 0x23)
#define HID_USAGE_LED_SEND_CALLS             ((USAGE) 0x24)
#define HID_USAGE_LED_CALL_PICKUP            ((USAGE) 0x25)
#define HID_USAGE_LED_CONFERENCE             ((USAGE) 0x26)
#define HID_USAGE_LED_STAND_BY               ((USAGE) 0x27)
#define HID_USAGE_LED_CAMERA_ON              ((USAGE) 0x28)
#define HID_USAGE_LED_CAMERA_OFF             ((USAGE) 0x29)
#define HID_USAGE_LED_ON_LINE                ((USAGE) 0x2A)
#define HID_USAGE_LED_OFF_LINE               ((USAGE) 0x2B)
#define HID_USAGE_LED_BUSY                   ((USAGE) 0x2C)
#define HID_USAGE_LED_READY                  ((USAGE) 0x2D)
#define HID_USAGE_LED_PAPER_OUT              ((USAGE) 0x2E)
#define HID_USAGE_LED_PAPER_JAM              ((USAGE) 0x2F)
#define HID_USAGE_LED_REMOTE                 ((USAGE) 0x30)
#define HID_USAGE_LED_FORWARD                ((USAGE) 0x31)
#define HID_USAGE_LED_REVERSE                ((USAGE) 0x32)
#define HID_USAGE_LED_STOP                   ((USAGE) 0x33)
#define HID_USAGE_LED_REWIND                 ((USAGE) 0x34)
#define HID_USAGE_LED_FAST_FORWARD           ((USAGE) 0x35)
#define HID_USAGE_LED_PLAY                   ((USAGE) 0x36)
#define HID_USAGE_LED_PAUSE                  ((USAGE) 0x37)
#define HID_USAGE_LED_RECORD                 ((USAGE) 0x38)
#define HID_USAGE_LED_ERROR                  ((USAGE) 0x39)
#define HID_USAGE_LED_SELECTED_INDICATOR     ((USAGE) 0x3A)
#define HID_USAGE_LED_IN_USE_INDICATOR       ((USAGE) 0x3B)
#define HID_USAGE_LED_MULTI_MODE_INDICATOR   ((USAGE) 0x3C)
#define HID_USAGE_LED_INDICATOR_ON           ((USAGE) 0x3D)
#define HID_USAGE_LED_INDICATOR_FLASH        ((USAGE) 0x3E)
#define HID_USAGE_LED_INDICATOR_SLOW_BLINK   ((USAGE) 0x3F)
#define HID_USAGE_LED_INDICATOR_FAST_BLINK   ((USAGE) 0x40)
#define HID_USAGE_LED_INDICATOR_OFF          ((USAGE) 0x41)
#define HID_USAGE_LED_FLASH_ON_TIME          ((USAGE) 0x42)
#define HID_USAGE_LED_SLOW_BLINK_ON_TIME     ((USAGE) 0x43)
#define HID_USAGE_LED_SLOW_BLINK_OFF_TIME    ((USAGE) 0x44)
#define HID_USAGE_LED_FAST_BLINK_ON_TIME     ((USAGE) 0x45)
#define HID_USAGE_LED_FAST_BLINK_OFF_TIME    ((USAGE) 0x46)
#define HID_USAGE_LED_INDICATOR_COLOR        ((USAGE) 0x47)
#define HID_USAGE_LED_RED                    ((USAGE) 0x48)
#define HID_USAGE_LED_GREEN                  ((USAGE) 0x49)
#define HID_USAGE_LED_AMBER                  ((USAGE) 0x4A)
#define HID_USAGE_LED_GENERIC_INDICATOR      ((USAGE) 0x4B)
#define HID_USAGE_LED_SYSTEM_SUSPEND         ((USAGE) 0x4C)
#define HID_USAGE_LED_EXTERNAL_POWER         ((USAGE) 0x4D)

//
//  Button Page (0x09)
//
//  There is no need to label these usages.
//


//
//  Ordinal Page (0x0A)
//
//  There is no need to label these usages.
//


//
//  Telephony Device Page (0x0B)
//
#define HID_USAGE_TELEPHONY_PHONE                   ((USAGE) 0x01)
#define HID_USAGE_TELEPHONY_ANSWERING_MACHINE       ((USAGE) 0x02)
#define HID_USAGE_TELEPHONY_MESSAGE_CONTROLS        ((USAGE) 0x03)
#define HID_USAGE_TELEPHONY_HANDSET                 ((USAGE) 0x04)
#define HID_USAGE_TELEPHONY_HEADSET                 ((USAGE) 0x05)
#define HID_USAGE_TELEPHONY_KEYPAD                  ((USAGE) 0x06)
#define HID_USAGE_TELEPHONY_PROGRAMMABLE_BUTTON     ((USAGE) 0x07)
#define HID_USAGE_TELEPHONY_REDIAL                  ((USAGE) 0x24)
#define HID_USAGE_TELEPHONY_TRANSFER                ((USAGE) 0x25)
#define HID_USAGE_TELEPHONY_DROP                    ((USAGE) 0x26)
#define HID_USAGE_TELEPHONY_LINE                    ((USAGE) 0x2A)
#define HID_USAGE_TELEPHONY_RING_ENABLE             ((USAGE) 0x2D)
#define HID_USAGE_TELEPHONY_SEND                    ((USAGE) 0x31)
#define HID_USAGE_TELEPHONY_KEYPAD_0                ((USAGE) 0xB0)
#define HID_USAGE_TELEPHONY_KEYPAD_D                ((USAGE) 0xBF)
#define HID_USAGE_TELEPHONY_HOST_AVAILABLE          ((USAGE) 0xF1)


//
// Consumer Controls Page (0x0C)
//
#define HID_USAGE_CONSUMERCTRL                      ((USAGE) 0x01)

// channel
#define HID_USAGE_CONSUMER_CHANNEL_INCREMENT        ((USAGE) 0x9C)
#define HID_USAGE_CONSUMER_CHANNEL_DECREMENT        ((USAGE) 0x9D)

// transport control
#define HID_USAGE_CONSUMER_PLAY                     ((USAGE) 0xB0)
#define HID_USAGE_CONSUMER_PAUSE                    ((USAGE) 0xB1)
#define HID_USAGE_CONSUMER_RECORD                   ((USAGE) 0xB2)
#define HID_USAGE_CONSUMER_FAST_FORWARD             ((USAGE) 0xB3)
#define HID_USAGE_CONSUMER_REWIND                   ((USAGE) 0xB4)
#define HID_USAGE_CONSUMER_SCAN_NEXT_TRACK          ((USAGE) 0xB5)
#define HID_USAGE_CONSUMER_SCAN_PREV_TRACK          ((USAGE) 0xB6)
#define HID_USAGE_CONSUMER_STOP                     ((USAGE) 0xB7)
#define HID_USAGE_CONSUMER_PLAY_PAUSE               ((USAGE) 0xCD)

// GameDVR
#define HID_USAGE_CONSUMER_GAMEDVR_OPEN_GAMEBAR     ((USAGE) 0xD0)
#define HID_USAGE_CONSUMER_GAMEDVR_TOGGLE_RECORD    ((USAGE) 0xD1)
#define HID_USAGE_CONSUMER_GAMEDVR_RECORD_CLIP      ((USAGE) 0xD2)
#define HID_USAGE_CONSUMER_GAMEDVR_SCREENSHOT       ((USAGE) 0xD3)
#define HID_USAGE_CONSUMER_GAMEDVR_TOGGLE_INDICATOR ((USAGE) 0xD4)
#define HID_USAGE_CONSUMER_GAMEDVR_TOGGLE_MICROPHONE ((USAGE) 0xD5)
#define HID_USAGE_CONSUMER_GAMEDVR_TOGGLE_CAMERA    ((USAGE) 0xD6)
#define HID_USAGE_CONSUMER_GAMEDVR_TOGGLE_BROADCAST ((USAGE) 0xD7)

// audio
#define HID_USAGE_CONSUMER_VOLUME                   ((USAGE) 0xE0)
#define HID_USAGE_CONSUMER_BALANCE                  ((USAGE) 0xE1)
#define HID_USAGE_CONSUMER_MUTE                     ((USAGE) 0xE2)
#define HID_USAGE_CONSUMER_BASS                     ((USAGE) 0xE3)
#define HID_USAGE_CONSUMER_TREBLE                   ((USAGE) 0xE4)
#define HID_USAGE_CONSUMER_BASS_BOOST               ((USAGE) 0xE5)
#define HID_USAGE_CONSUMER_SURROUND_MODE            ((USAGE) 0xE6)
#define HID_USAGE_CONSUMER_LOUDNESS                 ((USAGE) 0xE7)
#define HID_USAGE_CONSUMER_MPX                      ((USAGE) 0xE8)
#define HID_USAGE_CONSUMER_VOLUME_INCREMENT         ((USAGE) 0xE9)
#define HID_USAGE_CONSUMER_VOLUME_DECREMENT         ((USAGE) 0xEA)

// supplementary audio
#define HID_USAGE_CONSUMER_BASS_INCREMENT           ((USAGE) 0x152)
#define HID_USAGE_CONSUMER_BASS_DECREMENT           ((USAGE) 0x153)
#define HID_USAGE_CONSUMER_TREBLE_INCREMENT         ((USAGE) 0x154)
#define HID_USAGE_CONSUMER_TREBLE_DECREMENT         ((USAGE) 0x155)

// Application Launch
#define HID_USAGE_CONSUMER_AL_CONFIGURATION         ((USAGE) 0x183)
#define HID_USAGE_CONSUMER_AL_EMAIL                 ((USAGE) 0x18A)
#define HID_USAGE_CONSUMER_AL_CALCULATOR            ((USAGE) 0x192)
#define HID_USAGE_CONSUMER_AL_BROWSER               ((USAGE) 0x194)
#define HID_USAGE_CONSUMER_AL_SEARCH                ((USAGE) 0x1C6)

// Application Control
#define HID_USAGE_CONSUMER_AC_SEARCH                ((USAGE) 0x221)
#define HID_USAGE_CONSUMER_AC_GOTO                  ((USAGE) 0x222)
#define HID_USAGE_CONSUMER_AC_HOME                  ((USAGE) 0x223)
#define HID_USAGE_CONSUMER_AC_BACK                  ((USAGE) 0x224)
#define HID_USAGE_CONSUMER_AC_FORWARD               ((USAGE) 0x225)
#define HID_USAGE_CONSUMER_AC_STOP                  ((USAGE) 0x226)
#define HID_USAGE_CONSUMER_AC_REFRESH               ((USAGE) 0x227)
#define HID_USAGE_CONSUMER_AC_PREVIOUS              ((USAGE) 0x228)
#define HID_USAGE_CONSUMER_AC_NEXT                  ((USAGE) 0x229)
#define HID_USAGE_CONSUMER_AC_BOOKMARKS             ((USAGE) 0x22A)
#define HID_USAGE_CONSUMER_AC_PAN                   ((USAGE) 0x238)

// Keyboard Extended Attributes (defined on consumer page in HUTRR42)
#define HID_USAGE_CONSUMER_EXTENDED_KEYBOARD_ATTRIBUTES_COLLECTION      ((USAGE) 0x2C0)
#define HID_USAGE_CONSUMER_KEYBOARD_FORM_FACTOR                         ((USAGE) 0x2C1)
#define HID_USAGE_CONSUMER_KEYBOARD_KEY_TYPE                            ((USAGE) 0x2C2)
#define HID_USAGE_CONSUMER_KEYBOARD_PHYSICAL_LAYOUT                     ((USAGE) 0x2C3)
#define HID_USAGE_CONSUMER_VENDOR_SPECIFIC_KEYBOARD_PHYSICAL_LAYOUT     ((USAGE) 0x2C4)
#define HID_USAGE_CONSUMER_KEYBOARD_IETF_LANGUAGE_TAG_INDEX             ((USAGE) 0x2C5)
#define HID_USAGE_CONSUMER_IMPLEMENTED_KEYBOARD_INPUT_ASSIST_CONTROLS   ((USAGE) 0x2C6)

//
// Digitizer Page (0x0D)
//
#define HID_USAGE_DIGITIZER_DIGITIZER                      ((USAGE) 0x01)
#define HID_USAGE_DIGITIZER_PEN                            ((USAGE) 0x02)
#define HID_USAGE_DIGITIZER_LIGHT_PEN                      ((USAGE) 0x03)
#define HID_USAGE_DIGITIZER_TOUCH_SCREEN                   ((USAGE) 0x04)
#define HID_USAGE_DIGITIZER_TOUCH_PAD                      ((USAGE) 0x05)
#define HID_USAGE_DIGITIZER_WHITE_BOARD                    ((USAGE) 0x06)
#define HID_USAGE_DIGITIZER_COORD_MEASURING                ((USAGE) 0x07)
#define HID_USAGE_DIGITIZER_3D_DIGITIZER                   ((USAGE) 0x08)
#define HID_USAGE_DIGITIZER_STEREO_PLOTTER                 ((USAGE) 0x09)
#define HID_USAGE_DIGITIZER_ARTICULATED_ARM                ((USAGE) 0x0A)
#define HID_USAGE_DIGITIZER_ARMATURE                       ((USAGE) 0x0B)
#define HID_USAGE_DIGITIZER_MULTI_POINT                    ((USAGE) 0x0C)
#define HID_USAGE_DIGITIZER_FREE_SPACE_WAND                ((USAGE) 0x0D)
#define HID_USAGE_DIGITIZER_HEAT_MAP                       ((USAGE) 0x0F)
#define HID_USAGE_DIGITIZER_STYLUS                         ((USAGE) 0x20)
#define HID_USAGE_DIGITIZER_PUCK                           ((USAGE) 0x21)
#define HID_USAGE_DIGITIZER_FINGER                         ((USAGE) 0x22)
#define HID_USAGE_DIGITIZER_TABLET_FUNC_KEYS               ((USAGE) 0x39)
#define HID_USAGE_DIGITIZER_PROG_CHANGE_KEYS               ((USAGE) 0x3A)

#define HID_USAGE_DIGITIZER_TIP_PRESSURE                   ((USAGE) 0x30)
#define HID_USAGE_DIGITIZER_BARREL_PRESSURE                ((USAGE) 0x31)
#define HID_USAGE_DIGITIZER_IN_RANGE                       ((USAGE) 0x32)
#define HID_USAGE_DIGITIZER_TOUCH                          ((USAGE) 0x33)
#define HID_USAGE_DIGITIZER_UNTOUCH                        ((USAGE) 0x34)
#define HID_USAGE_DIGITIZER_TAP                            ((USAGE) 0x35)
#define HID_USAGE_DIGITIZER_QUALITY                        ((USAGE) 0x36)
#define HID_USAGE_DIGITIZER_DATA_VALID                     ((USAGE) 0x37)
#define HID_USAGE_DIGITIZER_TRANSDUCER_INDEX               ((USAGE) 0x38)
#define HID_USAGE_DIGITIZER_BATTERY_STRENGTH               ((USAGE) 0x3B)
#define HID_USAGE_DIGITIZER_INVERT                         ((USAGE) 0x3C)
#define HID_USAGE_DIGITIZER_X_TILT                         ((USAGE) 0x3D)
#define HID_USAGE_DIGITIZER_Y_TILT                         ((USAGE) 0x3E)
#define HID_USAGE_DIGITIZER_AZIMUTH                        ((USAGE) 0x3F)
#define HID_USAGE_DIGITIZER_ALTITUDE                       ((USAGE) 0x40)
#define HID_USAGE_DIGITIZER_TWIST                          ((USAGE) 0x41)
#define HID_USAGE_DIGITIZER_TIP_SWITCH                     ((USAGE) 0x42)
#define HID_USAGE_DIGITIZER_SECONDARY_TIP_SWITCH           ((USAGE) 0x43)
#define HID_USAGE_DIGITIZER_BARREL_SWITCH                  ((USAGE) 0x44)
#define HID_USAGE_DIGITIZER_ERASER                         ((USAGE) 0x45)
#define HID_USAGE_DIGITIZER_TABLET_PICK                    ((USAGE) 0x46)
#define HID_USAGE_DIGITIZER_TRANSDUCER_SERIAL              ((USAGE) 0x5B)
#define HID_USAGE_DIGITIZER_HEAT_MAP_PROTOCOL_VENDOR_ID    ((USAGE) 0x6A)
#define HID_USAGE_DIGITIZER_HEAT_MAP_PROTOCOL_VERSION      ((USAGE) 0x6B)
#define HID_USAGE_DIGITIZER_HEAT_MAP_FRAME_DATA            ((USAGE) 0x6C)
#define HID_USAGE_DIGITIZER_TRANSDUCER_VENDOR              ((USAGE) 0x91)
#define HID_USAGE_DIGITIZER_TRANSDUCER_PRODUCT             ((USAGE) 0x92)
#define HID_USAGE_DIGITIZER_TRANSDUCER_CONNECTED           ((USAGE) 0xA2)

//
// Simple Haptic Controller Page (0x0E)
//
#define HID_USAGE_HAPTICS_SIMPLE_CONTROLLER         ((USAGE)0x01)

#define HID_USAGE_HAPTICS_WAVEFORM_LIST             ((USAGE)0x10)
#define HID_USAGE_HAPTICS_DURATION_LIST             ((USAGE)0x11)

#define HID_USAGE_HAPTICS_AUTO_TRIGGER              ((USAGE)0x20)
#define HID_USAGE_HAPTICS_MANUAL_TRIGGER            ((USAGE)0x21)
#define HID_USAGE_HAPTICS_AUTO_ASSOCIATED_CONTROL   ((USAGE)0x22)
#define HID_USAGE_HAPTICS_INTENSITY                 ((USAGE)0x23)
#define HID_USAGE_HAPTICS_REPEAT_COUNT              ((USAGE)0x24)
#define HID_USAGE_HAPTICS_RETRIGGER_PERIOD          ((USAGE)0x25)
#define HID_USAGE_HAPTICS_WAVEFORM_VENDOR_PAGE      ((USAGE)0x26)
#define HID_USAGE_HAPTICS_WAVEFORM_VENDOR_ID        ((USAGE)0x27)
#define HID_USAGE_HAPTICS_WAVEFORM_CUTOFF_TIME      ((USAGE)0x28)

// Waveform types
#define HID_USAGE_HAPTICS_WAVEFORM_BEGIN            ((USAGE)0x1000)
#define HID_USAGE_HAPTICS_WAVEFORM_STOP             ((USAGE)0x1001)
#define HID_USAGE_HAPTICS_WAVEFORM_NULL             ((USAGE)0x1002)
#define HID_USAGE_HAPTICS_WAVEFORM_CLICK            ((USAGE)0x1003)
#define HID_USAGE_HAPTICS_WAVEFORM_BUZZ             ((USAGE)0x1004)
#define HID_USAGE_HAPTICS_WAVEFORM_RUMBLE           ((USAGE)0x1005)
#define HID_USAGE_HAPTICS_WAVEFORM_PRESS            ((USAGE)0x1006)
#define HID_USAGE_HAPTICS_WAVEFORM_RELEASE          ((USAGE)0x1007)
#define HID_USAGE_HAPTICS_WAVEFORM_END              ((USAGE)0x1FFF)

#define HID_USAGE_HAPTICS_WAVEFORM_VENDOR_BEGIN     ((USAGE)0x2000)
#define HID_USAGE_HAPTICS_WAVEFORM_VENDOR_END       ((USAGE)0x2FFF)

//
//  Unicode Page (0x10)
//
//  There is no need to label these usages.
//

//
//  Alphanumeric Display Page (0x14)
//
#define HID_USAGE_ALPHANUMERIC_ALPHANUMERIC_DISPLAY            ((USAGE) 0x01)
#define HID_USAGE_ALPHANUMERIC_BITMAPPED_DISPLAY               ((USAGE) 0x02)
#define HID_USAGE_ALPHANUMERIC_DISPLAY_ATTRIBUTES_REPORT       ((USAGE) 0x20)
#define HID_USAGE_ALPHANUMERIC_DISPLAY_CONTROL_REPORT          ((USAGE) 0x24)
#define HID_USAGE_ALPHANUMERIC_CHARACTER_REPORT                ((USAGE) 0x2B)
#define HID_USAGE_ALPHANUMERIC_DISPLAY_STATUS                  ((USAGE) 0x2D)
#define HID_USAGE_ALPHANUMERIC_CURSOR_POSITION_REPORT          ((USAGE) 0x32)
#define HID_USAGE_ALPHANUMERIC_FONT_REPORT                     ((USAGE) 0x3B)
#define HID_USAGE_ALPHANUMERIC_FONT_DATA                       ((USAGE) 0x3C)
#define HID_USAGE_ALPHANUMERIC_CHARACTER_ATTRIBUTE             ((USAGE) 0x48)
#define HID_USAGE_ALPHANUMERIC_PALETTE_REPORT                  ((USAGE) 0x85)
#define HID_USAGE_ALPHANUMERIC_PALETTE_DATA                    ((USAGE) 0x88)
#define HID_USAGE_ALPHANUMERIC_BLIT_REPORT                     ((USAGE) 0x8A)
#define HID_USAGE_ALPHANUMERIC_BLIT_DATA                       ((USAGE) 0x8F)
#define HID_USAGE_ALPHANUMERIC_SOFT_BUTTON                     ((USAGE) 0x90)

#define HID_USAGE_ALPHANUMERIC_ASCII_CHARACTER_SET             ((USAGE) 0x21)
#define HID_USAGE_ALPHANUMERIC_DATA_READ_BACK                  ((USAGE) 0x22)
#define HID_USAGE_ALPHANUMERIC_FONT_READ_BACK                  ((USAGE) 0x23)
#define HID_USAGE_ALPHANUMERIC_CLEAR_DISPLAY                   ((USAGE) 0x25)
#define HID_USAGE_ALPHANUMERIC_DISPLAY_ENABLE                  ((USAGE) 0x26)
#define HID_USAGE_ALPHANUMERIC_SCREEN_SAVER_DELAY              ((USAGE) 0x27)
#define HID_USAGE_ALPHANUMERIC_SCREEN_SAVER_ENABLE             ((USAGE) 0x28)
#define HID_USAGE_ALPHANUMERIC_VERTICAL_SCROLL                 ((USAGE) 0x29)
#define HID_USAGE_ALPHANUMERIC_HORIZONTAL_SCROLL               ((USAGE) 0x2A)
#define HID_USAGE_ALPHANUMERIC_DISPLAY_DATA                    ((USAGE) 0x2C)
#define HID_USAGE_ALPHANUMERIC_STATUS_NOT_READY                ((USAGE) 0x2E)
#define HID_USAGE_ALPHANUMERIC_STATUS_READY                    ((USAGE) 0x2F)
#define HID_USAGE_ALPHANUMERIC_ERR_NOT_A_LOADABLE_CHARACTER    ((USAGE) 0x30)
#define HID_USAGE_ALPHANUMERIC_ERR_FONT_DATA_CANNOT_BE_READ    ((USAGE) 0x31)
#define HID_USAGE_ALPHANUMERIC_ROW                             ((USAGE) 0x33)
#define HID_USAGE_ALPHANUMERIC_COLUMN                          ((USAGE) 0x34)
#define HID_USAGE_ALPHANUMERIC_ROWS                            ((USAGE) 0x35)
#define HID_USAGE_ALPHANUMERIC_COLUMNS                         ((USAGE) 0x36)
#define HID_USAGE_ALPHANUMERIC_CURSOR_PIXEL_POSITIONING        ((USAGE) 0x37)
#define HID_USAGE_ALPHANUMERIC_CURSOR_MODE                     ((USAGE) 0x38)
#define HID_USAGE_ALPHANUMERIC_CURSOR_ENABLE                   ((USAGE) 0x39)
#define HID_USAGE_ALPHANUMERIC_CURSOR_BLINK                    ((USAGE) 0x3A)
#define HID_USAGE_ALPHANUMERIC_CHAR_WIDTH                      ((USAGE) 0x3D)
#define HID_USAGE_ALPHANUMERIC_CHAR_HEIGHT                     ((USAGE) 0x3E)
#define HID_USAGE_ALPHANUMERIC_CHAR_SPACING_HORIZONTAL         ((USAGE) 0x3F)
#define HID_USAGE_ALPHANUMERIC_CHAR_SPACING_VERTICAL           ((USAGE) 0x40)
#define HID_USAGE_ALPHANUMERIC_UNICODE_CHAR_SET                ((USAGE) 0x41)
#define HID_USAGE_ALPHANUMERIC_FONT_7_SEGMENT                  ((USAGE) 0x42)
#define HID_USAGE_ALPHANUMERIC_7_SEGMENT_DIRECT_MAP            ((USAGE) 0x43)
#define HID_USAGE_ALPHANUMERIC_FONT_14_SEGMENT                 ((USAGE) 0x44)
#define HID_USAGE_ALPHANUMERIC_14_SEGMENT_DIRECT_MAP           ((USAGE) 0x45)
#define HID_USAGE_ALPHANUMERIC_DISPLAY_BRIGHTNESS              ((USAGE) 0x46)
#define HID_USAGE_ALPHANUMERIC_DISPLAY_CONTRAST                ((USAGE) 0x47)
#define HID_USAGE_ALPHANUMERIC_ATTRIBUTE_READBACK              ((USAGE) 0x49)
#define HID_USAGE_ALPHANUMERIC_ATTRIBUTE_DATA                  ((USAGE) 0x4A)
#define HID_USAGE_ALPHANUMERIC_CHAR_ATTR_ENHANCE               ((USAGE) 0x4B)
#define HID_USAGE_ALPHANUMERIC_CHAR_ATTR_UNDERLINE             ((USAGE) 0x4C)
#define HID_USAGE_ALPHANUMERIC_CHAR_ATTR_BLINK                 ((USAGE) 0x4D)
#define HID_USAGE_ALPHANUMERIC_BITMAP_SIZE_X                   ((USAGE) 0x80)
#define HID_USAGE_ALPHANUMERIC_BITMAP_SIZE_Y                   ((USAGE) 0x81)
#define HID_USAGE_ALPHANUMERIC_BIT_DEPTH_FORMAT                ((USAGE) 0x83)
#define HID_USAGE_ALPHANUMERIC_DISPLAY_ORIENTATION             ((USAGE) 0x84)
#define HID_USAGE_ALPHANUMERIC_PALETTE_DATA_SIZE               ((USAGE) 0x86)
#define HID_USAGE_ALPHANUMERIC_PALETTE_DATA_OFFSET             ((USAGE) 0x87)
#define HID_USAGE_ALPHANUMERIC_BLIT_RECTANGLE_X1               ((USAGE) 0x8B)
#define HID_USAGE_ALPHANUMERIC_BLIT_RECTANGLE_Y1               ((USAGE) 0x8C)
#define HID_USAGE_ALPHANUMERIC_BLIT_RECTANGLE_X2               ((USAGE) 0x8D)
#define HID_USAGE_ALPHANUMERIC_BLIT_RECTANGLE_Y2               ((USAGE) 0x8E)
#define HID_USAGE_ALPHANUMERIC_SOFT_BUTTON_ID                  ((USAGE) 0x91)
#define HID_USAGE_ALPHANUMERIC_SOFT_BUTTON_SIDE                ((USAGE) 0x92)
#define HID_USAGE_ALPHANUMERIC_SOFT_BUTTON_OFFSET1             ((USAGE) 0x93)
#define HID_USAGE_ALPHANUMERIC_SOFT_BUTTON_OFFSET2             ((USAGE) 0x94)
#define HID_USAGE_ALPHANUMERIC_SOFT_BUTTON_REPORT              ((USAGE) 0x95)

//
// Sensor Page (0x20)
//

//
// LampArray Page (0x59)
//
#define HID_USAGE_LAMPARRAY                                             ((USAGE) 0x01)
#define HID_USAGE_LAMPARRAY_ATTRBIUTES_REPORT                           ((USAGE) 0x02)
#define HID_USAGE_LAMPARRAY_LAMP_COUNT                                  ((USAGE) 0x03)
#define HID_USAGE_LAMPARRAY_BOUNDING_BOX_WIDTH_IN_MICROMETERS           ((USAGE) 0x04)
#define HID_USAGE_LAMPARRAY_BOUNDING_BOX_HEIGHT_IN_MICROMETERS          ((USAGE) 0x05)
#define HID_USAGE_LAMPARRAY_BOUNDING_BOX_DEPTH_IN_MICROMETERS           ((USAGE) 0x06)
#define HID_USAGE_LAMPARRAY_KIND                                        ((USAGE) 0x07)
#define HID_USAGE_LAMPARRAY_MIN_UPDATE_INTERVAL_IN_MICROSECONDS         ((USAGE) 0x08)

// 0x09 - 0x1F Reserved

#define HID_USAGE_LAMPARRAY_LAMP_ATTRIBUTES_REQUEST_REPORT              ((USAGE) 0x20)
#define HID_USAGE_LAMPARRAY_LAMP_ID                                     ((USAGE) 0x21)
#define HID_USAGE_LAMPARRAY_LAMP_ATTRIBUTES_RESPONSE_REPORT             ((USAGE) 0x22)
#define HID_USAGE_LAMPARRAY_POSITION_X_IN_MICROMETERS                   ((USAGE) 0x23)
#define HID_USAGE_LAMPARRAY_POSITION_Y_IN_MICROMETERS                   ((USAGE) 0x24)
#define HID_USAGE_LAMPARRAY_POSITION_Z_IN_MICROMETERS                   ((USAGE) 0x25)
#define HID_USAGE_LAMPARRAY_LAMP_PURPOSES                               ((USAGE) 0x26)
#define HID_USAGE_LAMPARRAY_UPDATE_LATENCY_IN_MICROSECONDS              ((USAGE) 0x27)
#define HID_USAGE_LAMPARRAY_RED_LEVEL_COUNT                             ((USAGE) 0x28)
#define HID_USAGE_LAMPARRAY_GREEN_LEVEL_COUNT                           ((USAGE) 0x29)
#define HID_USAGE_LAMPARRAY_BLUE_LEVEL_COUNT                            ((USAGE) 0x2A)
#define HID_USAGE_LAMPARRAY_INTENSITY_LEVEL_COUNT                       ((USAGE) 0x2B)
#define HID_USAGE_LAMPARRAY_IS_PROGRAMMABLE                             ((USAGE) 0x2C)
#define HID_USAGE_LAMPARRAY_INPUT_BINDING                               ((USAGE) 0x2D)

// 0x2E - 0x4F Reserved

#define HID_USAGE_LAMPARRAY_LAMP_MULTI_UPDATE_REPORT                    ((USAGE) 0x50)
#define HID_USAGE_LAMPARRAY_LAMP_RED_UPDATE_CHANNEL                     ((USAGE) 0x51)
#define HID_USAGE_LAMPARRAY_LAMP_GREEN_UPDATE_CHANNEL                   ((USAGE) 0x52)
#define HID_USAGE_LAMPARRAY_LAMP_BLUE_UPDATE_CHANNEL                    ((USAGE) 0x53)
#define HID_USAGE_LAMPARRAY_LAMP_INTENSITY_UPDATE_CHANNEL               ((USAGE) 0x54)
#define HID_USAGE_LAMPARRAY_LAMP_UPDATE_FLAGS                           ((USAGE) 0x55)

// 0x55 - 0x5F Reserved

#define HID_USAGE_LAMPARRAY_LAMP_RANGE_UPDATE_REPORT                    ((USAGE) 0x60)
#define HID_USAGE_LAMPARRAY_LAMP_ID_START                               ((USAGE) 0x61)
#define HID_USAGE_LAMPARRAY_LAMP_ID_END                                 ((USAGE) 0x62)

// 0x63 - 0x6F Reserved

#define HID_USAGE_LAMPARRAY_CONTROL_REPORT                              ((USAGE) 0x70)
#define HID_USAGE_LAMPARRAY_AUTONOMOUS_MODE                             ((USAGE) 0x71)

//
// Camera Control Page (0x90)
//
#define HID_USAGE_CAMERA_AUTO_FOCUS                 ((USAGE) 0x20)
#define HID_USAGE_CAMERA_SHUTTER                    ((USAGE) 0x21)

//
// Microsoft Bluetooth Handsfree Page (0xFFF3)
//
#define HID_USAGE_MS_BTH_HF_DIALNUMBER              ((USAGE) 0x21)
#define HID_USAGE_MS_BTH_HF_DIALMEMORY              ((USAGE) 0x22)


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#endif

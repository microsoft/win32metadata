//
// Important namespacing information:
//
// No capabilities should ever have overlapping numerical values even if
// they are for different architectures. AMD64 code can be loaded on ARM64
// under emulation and the emulator may prefer certain implementations (such
// as use of AVX instructions) that it can emulate more efficiently.
//
// Versioning:
//
// Any time new capabilities are introduced in an OS release, a new capability set
// or "CAPSET" is introduced. For example, AMD64 SV2 has the
// OVRDCAP_AMD64_V1_CAPSET capability associated with it (which will be enabled
// on that OS and later OS's). We may also add multiple capability sets in a release
// in certain situations.
//
// The OVRDCAP_AMD64_V1_CAPSET capability indicates "this OS is aware of all
// capabilities" defined with the OVRDCAP_AMD64_V1_CAPSET (i.e. anything noted
// as a SV2 Capability).
//
// This allows an application to determine if a capability is
// "not supported" due to the OS not even knowing about the capability
// (such as the case where an app is being run on an older OS) or because
// the capability was queried for by the OS but is not supported.
// All capabilities must have a version marker associated with them.
// Applications must not make assumptions about which OS's support querying
// capabilities as we may choose to backport capabilities at our discretion
// (so applications should always just use the presence of the capability set
// to know if the OS supports any particular capability).
//
// Note that if a capability set is indicated as supported the OS must support
// all capabilities provided by that capability set.
//

//
// Normal overrides. Each architecture has 65536 overrides available currently
// although this can easily be expanded in the future.
//

// AMD64
// SV2 Capabilities (OVRDCAP_AMD64_V1_CAPSET)
#define OVRDCAP_AMD64_FIRST                               0x00000000
#define OVRDCAP_AMD64_ERMSB                               0x00000000
#define OVRDCAP_AMD64_FAST_SHORT_REPMOV                   0x00000001
#define OVRDCAP_AMD64_FAST_ZERO_LEN_REPMOV                0x00000002
#define OVRDCAP_AMD64_FAST_SHORT_REPSTOSB                 0x00000003
#define OVRDCAP_AMD64_FAST_SHORT_REPCMPSB                 0x00000004
#define OVRDCAP_AMD64_USERMODE                            0x00000005
#define OVRDCAP_AMD64_KERNELMODE                          0x00000006
#define OVRDCAP_AMD64_CPU_MANUFACTURER_RECOGNIZED         0x00000007
#define OVRDCAP_AMD64_CPU_MANUFACTURER_INTEL              0x00000008
#define OVRDCAP_AMD64_CPU_MANUFACTURER_AMD                0x00000009
#define OVRDCAP_AMD64_CPU_MANUFACTURER_VIA                0x0000000A
#define OVRDCAP_AMD64_CPU_MODEL_0                         0x0000000B
#define OVRDCAP_AMD64_CPU_MODEL_1                         0x0000000C
#define OVRDCAP_AMD64_CPU_MODEL_2                         0x0000000D
#define OVRDCAP_AMD64_CPU_MODEL_3                         0x0000000E
#define OVRDCAP_AMD64_CPU_MODEL_4                         0x0000000F
#define OVRDCAP_AMD64_CPU_MODEL_5                         0x00000010
#define OVRDCAP_AMD64_CPU_MODEL_6                         0x00000011
#define OVRDCAP_AMD64_CPU_MODEL_7                         0x00000012
#define OVRDCAP_AMD64_CPU_MODEL_8                         0x00000013
#define OVRDCAP_AMD64_CPU_MODEL_9                         0x00000014
#define OVRDCAP_AMD64_CPU_MODEL_10                        0x00000015
#define OVRDCAP_AMD64_CPU_MODEL_11                        0x00000016
#define OVRDCAP_AMD64_CPU_MODEL_12                        0x00000017
#define OVRDCAP_AMD64_CPU_MODEL_13                        0x00000018
#define OVRDCAP_AMD64_CPU_MODEL_14                        0x00000019
#define OVRDCAP_AMD64_CPU_MODEL_15                        0x0000001A
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_0                0x0000001B
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_1                0x0000001C
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_2                0x0000001D
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_3                0x0000001E
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_4                0x0000001F
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_5                0x00000020
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_6                0x00000021
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_7                0x00000022
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_8                0x00000023
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_9                0x00000024
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_10               0x00000025
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_11               0x00000026
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_12               0x00000027
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_13               0x00000028
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_14               0x00000029
#define OVRDCAP_AMD64_CPU_EXTENDED_MODEL_15               0x0000002A
#define OVRDCAP_AMD64_CPU_FAMILY_0                        0x0000002B
#define OVRDCAP_AMD64_CPU_FAMILY_1                        0x0000002C
#define OVRDCAP_AMD64_CPU_FAMILY_2                        0x0000002D
#define OVRDCAP_AMD64_CPU_FAMILY_3                        0x0000002E
#define OVRDCAP_AMD64_CPU_FAMILY_4                        0x0000002F
#define OVRDCAP_AMD64_CPU_FAMILY_5                        0x00000030
#define OVRDCAP_AMD64_CPU_FAMILY_6                        0x00000031
#define OVRDCAP_AMD64_CPU_FAMILY_7                        0x00000032
#define OVRDCAP_AMD64_CPU_FAMILY_8                        0x00000033
#define OVRDCAP_AMD64_CPU_FAMILY_9                        0x00000034
#define OVRDCAP_AMD64_CPU_FAMILY_10                       0x00000035
#define OVRDCAP_AMD64_CPU_FAMILY_11                       0x00000036
#define OVRDCAP_AMD64_CPU_FAMILY_12                       0x00000037
#define OVRDCAP_AMD64_CPU_FAMILY_13                       0x00000038
#define OVRDCAP_AMD64_CPU_FAMILY_14                       0x00000039
#define OVRDCAP_AMD64_CPU_FAMILY_15                       0x0000003A
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_0               0x0000003B
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_1               0x0000003C
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_2               0x0000003D
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_3               0x0000003E
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_4               0x0000003F
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_5               0x00000040
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_6               0x00000041
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_7               0x00000042
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_8               0x00000043
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_9               0x00000044
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_10              0x00000045
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_11              0x00000046
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_12              0x00000047
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_13              0x00000048
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_14              0x00000049
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_15              0x0000004A
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_16              0x0000004B
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_17              0x0000004C
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_18              0x0000004D
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_19              0x0000004E
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_20              0x0000004F
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_21              0x00000050
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_22              0x00000051
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_23              0x00000052
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_24              0x00000053
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_25              0x00000054
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_26              0x00000055
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_27              0x00000056
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_28              0x00000057
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_29              0x00000058
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_30              0x00000059
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_31              0x0000005A
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_32              0x0000005B
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_33              0x0000005C
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_34              0x0000005D
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_35              0x0000005E
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_36              0x0000005F
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_37              0x00000060
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_38              0x00000061
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_39              0x00000062
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_40              0x00000063
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_41              0x00000064
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_42              0x00000065
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_43              0x00000066
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_44              0x00000067
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_45              0x00000068
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_46              0x00000069
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_47              0x0000006A
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_48              0x0000006B
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_49              0x0000006C
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_50              0x0000006D
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_51              0x0000006E
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_52              0x0000006F
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_53              0x00000070
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_54              0x00000071
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_55              0x00000072
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_56              0x00000073
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_57              0x00000074
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_58              0x00000075
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_59              0x00000076
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_60              0x00000077
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_61              0x00000078
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_62              0x00000079
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_63              0x0000007A
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_64              0x0000007B
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_65              0x0000007C
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_66              0x0000007D
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_67              0x0000007E
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_68              0x0000007F
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_69              0x00000080
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_70              0x00000081
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_71              0x00000082
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_72              0x00000083
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_73              0x00000084
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_74              0x00000085
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_75              0x00000086
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_76              0x00000087
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_77              0x00000088
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_78              0x00000089
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_79              0x0000008A
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_80              0x0000008B
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_81              0x0000008C
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_82              0x0000008D
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_83              0x0000008E
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_84              0x0000008F
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_85              0x00000090
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_86              0x00000091
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_87              0x00000092
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_88              0x00000093
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_89              0x00000094
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_90              0x00000095
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_91              0x00000096
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_92              0x00000097
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_93              0x00000098
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_94              0x00000099
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_95              0x0000009A
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_96              0x0000009B
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_97              0x0000009C
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_98              0x0000009D
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_99              0x0000009E
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_100             0x0000009F
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_101             0x000000A0
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_102             0x000000A1
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_103             0x000000A2
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_104             0x000000A3
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_105             0x000000A4
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_106             0x000000A5
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_107             0x000000A6
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_108             0x000000A7
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_109             0x000000A8
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_110             0x000000A9
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_111             0x000000AA
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_112             0x000000AB
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_113             0x000000AC
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_114             0x000000AD
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_115             0x000000AE
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_116             0x000000AF
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_117             0x000000B0
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_118             0x000000B1
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_119             0x000000B2
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_120             0x000000B3
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_121             0x000000B4
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_122             0x000000B5
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_123             0x000000B6
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_124             0x000000B7
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_125             0x000000B8
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_126             0x000000B9
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_127             0x000000BA
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_128             0x000000BB
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_129             0x000000BC
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_130             0x000000BD
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_131             0x000000BE
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_132             0x000000BF
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_133             0x000000C0
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_134             0x000000C1
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_135             0x000000C2
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_136             0x000000C3
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_137             0x000000C4
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_138             0x000000C5
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_139             0x000000C6
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_140             0x000000C7
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_141             0x000000C8
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_142             0x000000C9
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_143             0x000000CA
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_144             0x000000CB
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_145             0x000000CC
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_146             0x000000CD
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_147             0x000000CE
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_148             0x000000CF
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_149             0x000000D0
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_150             0x000000D1
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_151             0x000000D2
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_152             0x000000D3
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_153             0x000000D4
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_154             0x000000D5
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_155             0x000000D6
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_156             0x000000D7
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_157             0x000000D8
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_158             0x000000D9
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_159             0x000000DA
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_160             0x000000DB
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_161             0x000000DC
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_162             0x000000DD
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_163             0x000000DE
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_164             0x000000DF
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_165             0x000000E0
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_166             0x000000E1
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_167             0x000000E2
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_168             0x000000E3
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_169             0x000000E4
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_170             0x000000E5
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_171             0x000000E6
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_172             0x000000E7
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_173             0x000000E8
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_174             0x000000E9
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_175             0x000000EA
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_176             0x000000EB
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_177             0x000000EC
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_178             0x000000ED
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_179             0x000000EE
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_180             0x000000EF
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_181             0x000000F0
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_182             0x000000F1
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_183             0x000000F2
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_184             0x000000F3
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_185             0x000000F4
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_186             0x000000F5
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_187             0x000000F6
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_188             0x000000F7
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_189             0x000000F8
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_190             0x000000F9
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_191             0x000000FA
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_192             0x000000FB
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_193             0x000000FC
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_194             0x000000FD
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_195             0x000000FE
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_196             0x000000FF
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_197             0x00000100
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_198             0x00000101
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_199             0x00000102
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_200             0x00000103
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_201             0x00000104
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_202             0x00000105
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_203             0x00000106
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_204             0x00000107
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_205             0x00000108
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_206             0x00000109
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_207             0x0000010A
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_208             0x0000010B
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_209             0x0000010C
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_210             0x0000010D
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_211             0x0000010E
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_212             0x0000010F
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_213             0x00000110
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_214             0x00000111
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_215             0x00000112
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_216             0x00000113
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_217             0x00000114
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_218             0x00000115
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_219             0x00000116
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_220             0x00000117
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_221             0x00000118
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_222             0x00000119
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_223             0x0000011A
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_224             0x0000011B
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_225             0x0000011C
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_226             0x0000011D
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_227             0x0000011E
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_228             0x0000011F
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_229             0x00000120
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_230             0x00000121
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_231             0x00000122
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_232             0x00000123
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_233             0x00000124
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_234             0x00000125
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_235             0x00000126
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_236             0x00000127
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_237             0x00000128
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_238             0x00000129
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_239             0x0000012A
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_240             0x0000012B
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_241             0x0000012C
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_242             0x0000012D
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_243             0x0000012E
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_244             0x0000012F
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_245             0x00000130
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_246             0x00000131
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_247             0x00000132
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_248             0x00000133
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_249             0x00000134
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_250             0x00000135
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_251             0x00000136
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_252             0x00000137
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_253             0x00000138
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_254             0x00000139
#define OVRDCAP_AMD64_CPU_EXTENDED_FAMILY_255             0x0000013A
#define OVRDCAP_AMD64_V1_CAPSET                           0x0000013B

// SV2 AVX Capabilities (OVRDCAP_AMD64_V2_CAPSET)
#define OVRDCAP_AMD64_AVX                                 0x0000013C
#define OVRDCAP_AMD64_AVX2                                0x0000013D
#define OVRDCAP_AMD64_AVX512F                             0x0000013E
#define OVRDCAP_AMD64_V2_CAPSET                           0x0000013F

// SV3 Capabilities (OVRDCAP_AMD64_V3_CAPSET)
#define OVRDCAP_AMD64_V3_CAPSET                           0x00000140
#define OVRDCAP_AMD64_CFG_CHECK_OPT                       0x00000141 // MUST NOT CHANGE, hard coded in compiler
#define OVRDCAP_AMD64_CFG_DISPATCH_OPT                    0x00000142 // MUST NOT CHANGE, hard coded in compiler
#define OVRDCAP_AMD64_XFG_DISPATCH_OPT                    0x00000143 // MUST NOT CHANGE, hard coded in compiler
#define OVRDCAP_AMD64_SSE41                               0x00000144
#define OVRDCAP_AMD64_SMEP                                0x00000145
#define OVRDCAP_AMD64_KCFG_DISPATCH_KSCP                  0x00000146
#define OVRDCAP_AMD64_NOT_LIVE_MIGRATEABLE                0x00000147

#define OVRDCAP_AMD64_MAX                                 0x00000148

// ARM64
// SV2 Capabilities (OVRDCAP_ARM64_V1_CAPSET)
#define OVRDCAP_ARM64_FIRST                               0x00010000
#define OVRDCAP_ARM64_USERMODE                            0x00010001
#define OVRDCAP_ARM64_KERNELMODE                          0x00010002
#define OVRDCAP_ARM64_V1_CAPSET                           0x00010003

// SV3 Capabilities (OVRDCAP_ARM64_V2_CAPSET)
#define OVRDCAP_ARM64_SHA256                              0x00010004
#define OVRDCAP_ARM64_SHA512                              0x00010005
#define OVRDCAP_ARM64_SHA3                                0x00010006
#define OVRDCAP_ARM64_LSE                                 0x00010007
#define OVRDCAP_ARM64_LSE2                                0x00010008
#define OVRDCAP_ARM64_RDM                                 0x00010009
#define OVRDCAP_ARM64_SM3                                 0x0001000A
#define OVRDCAP_ARM64_SM4                                 0x0001000B
#define OVRDCAP_ARM64_DP                                  0x0001000C
#define OVRDCAP_ARM64_FHM                                 0x0001000D
#define OVRDCAP_ARM64_FLAGM                               0x0001000E
#define OVRDCAP_ARM64_FLAGM2                              0x0001000F
#define OVRDCAP_ARM64_FCMA                                0x00010010
#define OVRDCAP_ARM64_LRCPC                               0x00010011
#define OVRDCAP_ARM64_LRCPC2                              0x00010012
#define OVRDCAP_ARM64_BF16                                0x00010013
#define OVRDCAP_ARM64_I8MM                                0x00010014
#define OVRDCAP_ARM64_FP16                                0x00010015
#define OVRDCAP_ARM64_SVE                                 0x00010016
#define OVRDCAP_ARM64_SVE2                                0x00010017
#define OVRDCAP_ARM64_F32MM                               0x00010018
#define OVRDCAP_ARM64_F64MM                               0x00010019
#define OVRDCAP_ARM64_V2_CAPSET                           0x0001001A
#define OVRDCAP_ARM64_CFG_CHECK_OPT                       0x0001001B // MUST NOT CHANGE, hard coded in compiler
#define OVRDCAP_ARM64_CFG_DISPATCH_OPT                    0x0001001C // MUST NOT CHANGE, hard coded in compiler
#define OVRDCAP_ARM64_EC_CFG_CHECK_OPT                    0x0001001D // MUST NOT CHANGE, hard coded in compiler
#define OVRDCAP_ARM64_EC_ICALL_CHECK_OPT                  0x0001001E // MUST NOT CHANGE, hard coded in compiler
#define OVRDCAP_ARM64_EC_CALL_CHECK_OPT                   0x0001001F // MUST NOT CHANGE, hard coded in compiler

// Ga Capabilities
#define OVRDCAP_ARM64_V3_CAPSET                           0x00010020
#define OVRDCAP_ARM64_UNALIGNED_CRT_STRESS_TEST           0x00010021
#define OVRDCAP_ARM64_UNALIGNED_CRT                       0x00010022 // MUST NOT CHANGE, hard coded in vcruntime140.dll
#define OVRDCAP_ARM64_DCZVA                               0x00010023
#define OVRDCAP_ARM64_DCZVA_STRIDE_64BYTES                0x00010024
#define OVRDCAP_ARM64_HYPERVISOR_VENDOR_MICROSOFT         0x00010025
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_ARM                 0x00010026
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_BROADCOM            0x00010027
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_CAVIUM              0x00010028
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_DEC                 0x00010029
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_FUJITSU             0x0001002A
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_INFINEON            0x0001002B
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_MOTOROLA_OR_FREESCALE 0x0001002C
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_NVIDIA              0x0001002D
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_APPLIED_MICRO_CIRCUITS 0x0001002E
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_QUALCOMM            0x0001002F
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_MARVELL             0x00010030
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_INTEL               0x00010031
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_AMPERE              0x00010032
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_MICROSOFT           0x00010033
#define OVRDCAP_ARM64_CPU_IMPLEMENTER_APPLE               0x00010034
#define OVRDCAP_ARM64_KCFG_CHECK_KSCP                     0x00010035 // Just for use by NT.
#define OVRDCAP_ARM64_NO_DEVICE_MEMORY_ALLOCATION         0x00010036 // Allocated (PAGE_NOCACHE) memory is not device memory.
#define OVRDCAP_ARM64_NOT_LIVE_MIGRATEABLE                0x00010037
#define OVRDCAP_ARM64_QC_CHIPSET_850                      0x00010038
#define OVRDCAP_ARM64_QC_CHIPSET_850_OR_8180              0x00010039
#define OVRDCAP_ARM64_QC_CHIPSET_8180                     0x0001003A
#define OVRDCAP_ARM64_QC_CHIPSET_8280                     0x0001003B
#define OVRDCAP_ARM64_QC_CHIPSET_8380                     0x0001003C

#define OVRDCAP_ARM64_MAX                                 0x0001003D

#define OVRDCAP_ALWAYS_OFF                                0x7FFFFFFF

//
// SPECIAL OS FUNCTIONS:
// If the top bit is set (32-bit value) this indicates the capability is an
// "OS Special Function". For these functions, the OS will override the 
// function implementation with a function that it supplies (for example, 
// a function implemented by ntdll). This bit cannot be set on arbitrary 
// overrides capabilities (i.e. the capabilities listed above), it must
// be set on specific capabilities.
//
// Note that this behavior is hard coded in to the linker which
// will use the top-bit being set as an indication to ensure the branch the 
// relocation is applied to is able to point at the 32MB of VA trailing
// the binary (as the operating system may map the special function after
// the binary). This is especially important for ARM64 where the "b" and "bl"
// branches only have +-128MB range from the current instruction. If the linker
// cannot guarantee this instruction will be placed such that it can target 32MB
// off the end of the binary the linker will instead need to emit a different
// instruction sequence (using ADRP/ADD) that has enough range. Accordingly,
// it is not possible to place "OS Special Functions" anywhere else in the 
// capability bitspace as the linker will not behave correctly.
//

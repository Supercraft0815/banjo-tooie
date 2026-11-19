/* data_to_c.py: from asm/data/overlays/su/expressjoint.data.s */
JointTransform D_80800A60_suexpressjoint[3] BT_DATA(4, overlays_su_expressjoint, 0x0) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 4.47f, 0.99f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 1.94f, 0.53f}, {0.0f, 0.0f, 0.0f}, {0.7f, 0.88f, 1.0f}}};
JointTransform D_80800ACC_suexpressjoint[3] BT_DATA(4, overlays_su_expressjoint, 0x6C) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, -1.23f, 0.5f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.39f, 0.5f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointTransform D_80800B38_suexpressjoint[3] BT_DATA(4, overlays_su_expressjoint, 0xD8) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.78f}, {0.0f, 0.0f, 0.0f}, {0.78f, 1.0f, 1.0f}}};
JointPart D_80800BA4_suexpressjoint[3] BT_DATA(4, overlays_su_expressjoint,
                                               0x144) = {{0x2A, 1, D_80800A60_suexpressjoint},
                                                         {0x2B, 1, D_80800ACC_suexpressjoint},
                                                         {0x2C, 1, D_80800B38_suexpressjoint}};
u8 D_80800BBC_suexpressjoint[3][4] BT_DATA(4, overlays_su_expressjoint,
                                           0x15C) = {{0x64, 0, 0, 0}, {0, 0x64, 0, 0}, {0, 0, 0x64, 0}};
JointTransform D_80800BC8_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0x168) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {-3.75f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {-5.78f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointTransform D_80800C58_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0x1F8) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {25.09f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {15.54f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {-9.49f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_80800CE8_suexpressjoint[2] BT_DATA(4, overlays_su_expressjoint, 0x288) = {
    {0x12, 1, D_80800BC8_suexpressjoint}, {0x35, 0, D_80800C58_suexpressjoint}};
u8 D_80800CF8_suexpressjoint[5][4] BT_DATA(4, overlays_su_expressjoint, 0x298) = {
    {0x64, 0, 0, 0}, {0, 0x64, 0, 0}, {0, 0, 0x64, 0}, {0, 0, 0, 0x64}, {0, 0x32, 0x32, 0}};
JointTransform D_80800D0C_suexpressjoint[2] BT_DATA(4, overlays_su_expressjoint, 0x2AC) = {
    {{0.0f, 0.0f, 0.0f}, {30.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {-14.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_80800D54_suexpressjoint[1] BT_DATA(4, overlays_su_expressjoint,
                                               0x2F4) = {{0x2B, 0, D_80800D0C_suexpressjoint}};
u8 D_80800D5C_suexpressjoint[3][4] BT_DATA(4, overlays_su_expressjoint,
                                           0x2FC) = {{0x64, 0, 0, 0}, {0, 0x64, 0, 0}, {0, 0x32, 0, 0}};
JointTransform D_80800D68_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0x308) = {
    {{0.0f, 0.0f, 0.0f}, {5.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {-15.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointTransform D_80800DF8_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0x398) = {
    {{0.0f, 0.0f, 0.0f}, {-5.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {30.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointTransform D_80800E88_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0x428) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {-30.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_80800F18_suexpressjoint[3] BT_DATA(4, overlays_su_expressjoint,
                                               0x4B8) = {{0x2A, 1, D_80800D68_suexpressjoint},
                                                         {0x4A, 1, D_80800DF8_suexpressjoint},
                                                         {0x4F, 1, D_80800E88_suexpressjoint}};
u8 D_80800F30_suexpressjoint[24][4] BT_DATA(4, overlays_su_expressjoint, 0x4D0) = {
    {0x64, 0, 0, 0}, {0, 0x32, 0, 0},    {0, 0x64, 0, 0},    {0, 0, 0x64, 0},    {0, 0, 0, 0x32},
    {0, 0, 0, 0x64}, {0, 0, 0, 0},       {0, 0, 0, 0},       {0, 0, 0, 0},       {0x41, 0xA0, 0, 0},
    {0, 0, 0, 0},    {0, 0, 0, 0},       {0x40, 0x40, 0, 0}, {0x40, 0x40, 0, 0}, {0x40, 0x40, 0, 0},
    {0, 0, 0, 0},    {0, 0, 0, 0},       {0, 0, 0, 0},       {0xC1, 0xF0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0},    {0x40, 0x80, 0, 0}, {0x40, 0x80, 0, 0}, {0x40, 0x80, 0, 0}};
JointPart D_80800F90_suexpressjoint[1] BT_DATA(4, overlays_su_expressjoint,
                                               0x530) = {{3, 1, D_80800E88_suexpressjoint}};
u8 D_80800F98_suexpressjoint[2][4] BT_DATA(4, overlays_su_expressjoint, 0x538) = {{0x64, 0, 0, 0},
                                                                                  {0, 0x64, 0, 0}};
JointPart D_80800FA0_suexpressjoint[2] BT_DATA(4, overlays_su_expressjoint, 0x540) = {
    {0x2A, 1, D_80800D68_suexpressjoint}, {0x4A, 1, D_80800DF8_suexpressjoint}};
u8 D_80800FB0_suexpressjoint[3][4] BT_DATA(4, overlays_su_expressjoint,
                                           0x550) = {{0x64, 0, 0, 0}, {0, 0x32, 0, 0}, {0, 0x64, 0, 0}};
JointTransform D_80800FBC_suexpressjoint[2] BT_DATA(4, overlays_su_expressjoint, 0x55C) = {
    {{0.0f, 0.0f, 0.0f}, {-24.41f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {-9.78f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointTransform D_80801004_suexpressjoint[2] BT_DATA(4, overlays_su_expressjoint, 0x5A4) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {-2.09f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointTransform D_8080104C_suexpressjoint[2] BT_DATA(4, overlays_su_expressjoint, 0x5EC) = {
    {{0.0f, 0.0f, 0.0f}, {-23.0f, 0.0f, 0.0f}, {0.6f, 0.6f, 0.6f}},
    {{0.0f, 0.0f, 0.0f}, {-15.92f, 0.0f, 0.0f}, {0.6f, 0.6f, 0.6f}}};
JointPart D_80801094_suexpressjoint[3] BT_DATA(4, overlays_su_expressjoint,
                                               0x634) = {{0x52, 0, D_80800FBC_suexpressjoint},
                                                         {0x51, 1, D_80801004_suexpressjoint},
                                                         {0x53, 0, D_8080104C_suexpressjoint}};
u8 D_808010AC_suexpressjoint[2][4] BT_DATA(4, overlays_su_expressjoint, 0x64C) = {{0x64, 0, 0, 0},
                                                                                  {0, 0x64, 0, 0}};
JointTransform D_808010B4_suexpressjoint[1] BT_DATA(4, overlays_su_expressjoint, 0x654) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointTransform D_808010D8_suexpressjoint[1] BT_DATA(4, overlays_su_expressjoint, 0x678) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_808010FC_suexpressjoint[2] BT_DATA(4, overlays_su_expressjoint, 0x69C) = {
    {0x12, 0, D_808010B4_suexpressjoint}, {0x2A, 0, D_808010D8_suexpressjoint}};
u8 D_8080110C_suexpressjoint[3][4] BT_DATA(4, overlays_su_expressjoint,
                                           0x6AC) = {{0x64, 0, 0, 0}, {0x64, 0, 0, 0}, {0x64, 0, 0, 0}};
JointTransform D_80801118_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0x6B8) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {2.0f, 0.0f, 3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {2.0f, 0.0f, -3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {4.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_808011A8_suexpressjoint[1] BT_DATA(4, overlays_su_expressjoint,
                                               0x748) = {{0x12, 1, D_80801118_suexpressjoint}};
u8 D_808011B0_suexpressjoint[5][4] BT_DATA(4, overlays_su_expressjoint, 0x750) = {
    {0x1E, 0, 0, 0}, {0, 0x64, 0, 0x28}, {0, 0x50, 0x64, 0x32}, {0, 0, 0x32, 0x32}, {0, 0x32, 0, 0x1E}};
JointTransform D_808011C4_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0x764) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {2.0f, 0.0f, 3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {2.0f, 0.0f, -3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {4.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_80801254_suexpressjoint[1] BT_DATA(4, overlays_su_expressjoint,
                                               0x7F4) = {{0x12, 1, D_808011C4_suexpressjoint}};
u8 D_8080125C_suexpressjoint[3][4] BT_DATA(4, overlays_su_expressjoint,
                                           0x7FC) = {{0x32, 0, 0, 0}, {0, 0x64, 0, 0x32}, {0, 0, 0x64, 0x32}};
JointTransform D_80801268_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0x808) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {2.0f, 0.0f, 3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {2.0f, 0.0f, -3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {4.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_808012F8_suexpressjoint[1] BT_DATA(4, overlays_su_expressjoint,
                                               0x898) = {{0x12, 1, D_80801268_suexpressjoint}};
u8 D_80801300_suexpressjoint[3][4] BT_DATA(4, overlays_su_expressjoint,
                                           0x8A0) = {{0x32, 0, 0, 0}, {0, 0x64, 0, 0x32}, {0, 0, 0x64, 0x32}};
JointTransform D_8080130C_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0x8AC) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {2.0f, 0.0f, 3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {2.0f, 0.0f, -3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {4.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointTransform D_8080139C_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0x93C) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_8080142C_suexpressjoint[2] BT_DATA(4, overlays_su_expressjoint, 0x9CC) = {
    {0x29, 1, D_8080130C_suexpressjoint}, {0x2A, 0, D_8080139C_suexpressjoint}};
u8 D_8080143C_suexpressjoint[3][4] BT_DATA(4, overlays_su_expressjoint,
                                           0x9DC) = {{0x64, 0, 0, 0}, {0, 0x64, 0, 0x32}, {0, 0, 0x64, 0x32}};
JointTransform D_80801448_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0x9E8) = {
    {{0.0f, 0.0f, 0.0f}, {10.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {20.0f, 0.0f, 3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {40.0f, 0.0f, -3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {30.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_808014D8_suexpressjoint[1] BT_DATA(4, overlays_su_expressjoint,
                                               0xA78) = {{0x2A, 3, D_80801448_suexpressjoint}};
u8 D_808014E0_suexpressjoint[3][4] BT_DATA(4, overlays_su_expressjoint,
                                           0xA80) = {{0x32, 0, 0, 0}, {0, 0x64, 0, 0x32}, {0, 0, 0x64, 0x32}};
JointTransform D_808014EC_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0xA8C) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {2.0f, 0.0f, 3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {2.0f, 0.0f, -3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {4.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_8080157C_suexpressjoint[1] BT_DATA(4, overlays_su_expressjoint,
                                               0xB1C) = {{0x12, 1, D_808014EC_suexpressjoint}};
u8 D_80801584_suexpressjoint[3][4] BT_DATA(4, overlays_su_expressjoint,
                                           0xB24) = {{0x32, 0, 0, 0}, {0, 0x64, 0, 0x32}, {0, 0, 0x64, 0x32}};
JointTransform D_80801590_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0xB30) = {
    {{0.0f, 0.0f, 0.0f}, {5.0f, 0.0f, -3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {9.0f, 0.0f, 6.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {9.0f, 0.0f, -6.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {10.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_80801620_suexpressjoint[1] BT_DATA(4, overlays_su_expressjoint,
                                               0xBC0) = {{0x12, 1, D_80801590_suexpressjoint}};
u8 D_80801628_suexpressjoint[3][4] BT_DATA(4, overlays_su_expressjoint,
                                           0xBC8) = {{0x64, 0, 0, 0}, {0, 0x64, 0, 0}, {0, 0, 0x64, 0}};
JointTransform D_80801634_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0xBD4) = {
    {{0.0f, 0.0f, 0.0f}, {5.0f, 0.0f, -3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {9.0f, 0.0f, 6.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {9.0f, 0.0f, -6.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {10.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_808016C4_suexpressjoint[1] BT_DATA(4, overlays_su_expressjoint,
                                               0xC64) = {{0x12, 1, D_80801634_suexpressjoint}};
u8 D_808016CC_suexpressjoint[4][4] BT_DATA(4, overlays_su_expressjoint, 0xC6C) = {
    {0x64, 0, 0, 0}, {0, 0x32, 0, 0}, {0, 0, 0x32, 0}, {0, 0x32, 0, 0}};
JointTransform D_808016DC_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0xC7C) = {
    {{0.0f, 0.0f, 0.0f}, {3.0f, 0.0f, -2.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {4.0f, 0.0f, 3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {4.0f, 0.0f, -3.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {5.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointTransform D_8080176C_suexpressjoint[4] BT_DATA(4, overlays_su_expressjoint, 0xD0C) = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}}};
JointPart D_808017FC_suexpressjoint[2] BT_DATA(4, overlays_su_expressjoint, 0xD9C) = {
    {0x12, 1, D_808016DC_suexpressjoint}, {0x2A, 0, D_8080176C_suexpressjoint}};
u8 D_8080180C_suexpressjoint[3][4] BT_DATA(4, overlays_su_expressjoint,
                                           0xDAC) = {{0x64, 0, 0, 0}, {0, 0x64, 0, 0}, {0, 0, 0x64, 0}};
JointInfo D_80801818_suexpressjoint[22] BT_DATA(4, overlays_su_expressjoint, 0xDB8) = {
    {D_80800F18_suexpressjoint, D_80800F30_suexpressjoint, 12, 0, 3, 4, {0, 0, 0}},
    {D_80800F18_suexpressjoint, D_80800F30_suexpressjoint, 13, 0, 3, 4, {0, 0, 0}},
    {D_80800F18_suexpressjoint, D_80800F30_suexpressjoint, 14, 0, 3, 4, {0, 0, 0}},
    {D_80800CE8_suexpressjoint, D_80800CF8_suexpressjoint, 16, 0, 2, 4, {0, 0, 0}},
    {D_80800CE8_suexpressjoint, D_80800CF8_suexpressjoint, 119, 0, 2, 4, {0, 0, 0}},
    {D_80800D54_suexpressjoint, D_80800D5C_suexpressjoint, 58, 1, 1, 2, {0, 0, 0}},
    {D_80800BA4_suexpressjoint, D_80800BBC_suexpressjoint, 66, 1, 3, 3, {0, 0, 0}},
    {D_80800FA0_suexpressjoint, D_80800FB0_suexpressjoint, 91, 0, 2, 3, {0, 0, 0}},
    {D_80800F90_suexpressjoint, D_80800F98_suexpressjoint, 92, 0, 1, 2, {0, 0, 0}},
    {D_80801094_suexpressjoint, D_808010AC_suexpressjoint, 117, 0, 3, 2, {0, 0, 0}},
    {D_80801094_suexpressjoint, D_808010AC_suexpressjoint, 118, 0, 3, 2, {0, 0, 0}},
    {D_808011A8_suexpressjoint, D_808011B0_suexpressjoint, 121, 0, 1, 4, {0, 0, 0}},
    {D_80801254_suexpressjoint, D_8080125C_suexpressjoint, 122, 0, 1, 4, {0, 0, 0}},
    {D_808012F8_suexpressjoint, D_80801300_suexpressjoint, 126, 0, 1, 4, {0, 0, 0}},
    {D_808010FC_suexpressjoint, D_8080110C_suexpressjoint, 127, 0, 2, 1, {0, 0, 0}},
    {D_8080142C_suexpressjoint, D_8080143C_suexpressjoint, 128, 0, 2, 4, {0, 0, 0}},
    {D_808010FC_suexpressjoint, D_8080110C_suexpressjoint, 171, 0, 2, 1, {0, 0, 0}},
    {D_808014D8_suexpressjoint, D_808014E0_suexpressjoint, 34, 0, 1, 4, {0, 0, 0}},
    {D_8080157C_suexpressjoint, D_80801584_suexpressjoint, 174, 0, 1, 4, {0, 0, 0}},
    {D_80801620_suexpressjoint, D_80801628_suexpressjoint, 64, 0, 1, 4, {0, 0, 0}},
    {D_808016C4_suexpressjoint, D_808016CC_suexpressjoint, 111, 0, 1, 4, {0, 0, 0}},
    {D_808017FC_suexpressjoint, D_8080180C_suexpressjoint, 175, 0, 2, 4, {0, 0, 0}}};

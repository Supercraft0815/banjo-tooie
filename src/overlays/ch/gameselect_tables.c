#include "gameselect_tables.h"

void func_8080000C_chgameselect(Actor *);
void func_8080015C_chgameselect(Actor *);
s32 func_80800228_chgameselect(Actor *, s32, s32);
void func_80800440_chgameselect(void *);
void func_80800D74_chgameselect(Actor *);
void func_80800E24_chgameselect(void *);
s32 func_808011B4_chgameselect(void *, s32, s32);
void func_808012E4_chgameselect(Actor *, u8 *);
void func_80801AC4_chgameselect(Actor *);
s32 func_80801BA8_chgameselect(Actor *, s32, BtIntPtr);
void func_808021E4_chgameselect(void *);
void func_80802248_chgameselect(Actor *);
void func_80802480_chgameselect(void *);
void func_808024D4_chgameselect(void *);
void func_80802530_chgameselect(void *);
void func_80802588_chgameselect(void *);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_808025CC_chgameselect(Actor *, BtIntPtr);
#define GAME_SELECT_DRAW(fn) .draw_actor = fn
#else
void func_808025CC_chgameselect(void *);
#define GAME_SELECT_DRAW(fn) (void (*)(s32, s32))fn
#endif
s32 func_808025EC_chgameselect(void *, s32, s32);
void func_808027D4_chgameselect(s32);
void func_808027DC_chgameselect(Actor *);
void func_80802994_chgameselect(Actor *, s32);
void func_808029D8_chgameselect(Actor *);
s32 func_80802A0C_chgameselect(Actor *, s32, s32);
void func_808039D0_chgameselect(void);
void func_80803A18_chgameselect(void);
void func_80803A58_chgameselect(void);
void func_80803A88_chgameselect(void);
void func_80803AB0_chgameselect(void);
s32 func_8080413C_chgameselect(Actor *);
s32 func_808041C8_chgameselect(void *);
void func_80804220_chgameselect(void *);
int func_808042A8_chgameselect(Actor *, s32, s32 *);
void func_80804404_chgameselect(u8 *, s32);
s32 func_8080444C_chgameselect(void *);
void func_808044A4_chgameselect(void *);
s32 func_8080450C_chgameselect(Actor *, s32, s32 *);
void func_808045E4_chgameselect(u8 *, s32);
s32 func_8080462C_chgameselect(u8 *);
void func_80804694_chgameselect(void *);
void func_808046D0_chgameselect(s32, s32);
s32 func_80804750_chgameselect(Actor *, s32, s32);
void func_80804878_chgameselect(Actor *, s32, s32);
void func_808048F8_chgameselect(u8 *, s32 *);
void func_80804A8C_chgameselect(u8 *, s32, s32);
void func_80804AF0_chgameselect(u8 *, s32, s32);
s32 func_80804B4C_chgameselect(void *);
void func_80804B90_chgameselect(void *);
void func_80804BB4_chgameselect(BtIntPtr, s32, s32);
void func_80804BF4_chgameselect(u8 *, s32, s32);
s32 func_80804E34_chgameselect(u8 *);
void func_80804F14_chgameselect(void *);
void func_80804F38_chgameselect(Actor *, s32, s32);
void func_808051B4_chgameselect(Actor *, s32, s32);
void func_80805498_chgameselect(Actor *, BtIntPtr);
void func_8080569C_chgameselect(Actor *, BT_IDO_ONLY(s32) BT_PASS2(s32, BT_PASS2(s32, s32)));
s32 func_8080595C_chgameselect(Actor *, OptionState *, s32);
void func_80805AC0_chgameselect(Actor *, s32, s32);
void func_808064E8_chgameselect(s32, s32, s32, s32);
void func_80806800_chgameselect(void *, s32);
void func_80806B5C_chgameselect(s32, s32, s32);
void func_80806BD4_chgameselect(s32, s32, s32);
void func_80806C54_chgameselect(Actor *);
void func_80806D98_chgameselect(Actor *);
void func_80806FAC_chgameselect(Actor *, BtIntPtr);
void func_80807030_chgameselect(Actor *);
s32 func_808070C0_chgameselect(Actor *, s32, s32);
void func_808078F0_chgameselect(void *);
void func_80807900_chgameselect(Actor *);
void func_808079C8_chgameselect(s32);
s32 func_808079D0_chgameselect(s32, s32, s32);

/* data_to_c.py: from asm/data/overlays/ch/gameselect.data.s */
void func_80102EC0();
void func_8010A730();
void func_80107C2C();
void func_801018A4();
GameSelectModel D_80807DB0_chgameselect[8] BT_DATA(4, overlays_ch_gameselect, 0x0) = {
    {6366, 2}, {6366, 2}, {6366, 2}, {6367, 3}, {6368, 4}, {6369, 5}, {6370, 6}, {6371, 7}};
GameSelectState D_80807DD0_chgameselect[10] BT_DATA(4, overlays_ch_gameselect, 0x20) = {
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {(GameSelectInit)func_8080413C_chgameselect, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
     NULL, NULL, NULL, NULL},
    {(GameSelectInit)func_808041C8_chgameselect, (GameSelectExit)func_80804220_chgameselect,
     (GameSelectChange)func_808042A8_chgameselect, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
     (GameSelectGetOption)func_80804404_chgameselect, NULL, NULL},
    {(GameSelectInit)func_8080444C_chgameselect, (GameSelectExit)func_808044A4_chgameselect,
     (GameSelectChange)func_8080450C_chgameselect, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
     (GameSelectGetOption)func_808045E4_chgameselect, NULL, NULL},
    {(GameSelectInit)func_80804E34_chgameselect, (GameSelectExit)func_80804F14_chgameselect, NULL,
     (GameSelectOpen)func_80805498_chgameselect, (GameSelectSelect)func_8080595C_chgameselect,
     (GameSelectEvent5)func_80805AC0_chgameselect, (GameSelectEvent3)func_80804F38_chgameselect,
     (GameSelectEventCallback)func_808051B4_chgameselect,
     (GameSelectOpen)func_8080569C_chgameselect, (GameSelectOpen)func_808064E8_chgameselect,
     (GameSelectGetOption)func_80806800_chgameselect,
     (GameSelectEventCallback)func_80806B5C_chgameselect,
     (GameSelectEventCallback)func_80806BD4_chgameselect},
    {(GameSelectInit)func_8080462C_chgameselect, (GameSelectExit)func_80804694_chgameselect, NULL,
     (GameSelectOpen)func_808046D0_chgameselect, (GameSelectSelect)func_80804750_chgameselect,
     (GameSelectEvent5)func_80804878_chgameselect, NULL, NULL, NULL, NULL,
     (GameSelectGetOption)func_808048F8_chgameselect,
     (GameSelectEventCallback)func_80804A8C_chgameselect,
     (GameSelectEventCallback)func_80804AF0_chgameselect},
    {(GameSelectInit)func_80804B4C_chgameselect, (GameSelectExit)func_80804B90_chgameselect, NULL,
     NULL, NULL, NULL, (GameSelectEvent3)func_80804BB4_chgameselect,
     (GameSelectEventCallback)func_80804BF4_chgameselect, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}};
ActorData D_80807FD8_chgameselect BT_DATA(4, overlays_ch_gameselect, 0x228) = {
    344,
    1191,
    0,
    9,
    0,
    (void (*)(struct Actor *))func_8080015C_chgameselect,
    (void (*)(struct Actor *))func_80102EC0,
    (void (*)(s32, s32))func_8010A730,
    0,
    0,
    0,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_80800440_chgameselect,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_8080000C_chgameselect,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32768,
    9218,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_80800228_chgameselect,
                  (void (*)(struct Actor *, long, long))func_80800228_chgameselect),
    0};
ActorAnimationEntry D_80808020_chgameselect[3] BT_DATA(4, overlays_ch_gameselect, 0x270) = {
    {0.0f, 0, 0}, {1.0f, 0x3D0, 9}, {2.6f, 0x3D4, 0x4A}};
ActorData D_80808038_chgameselect BT_DATA(4, overlays_ch_gameselect, 0x288) = {
    344,
    1195,
    2146,
    1,
    (void *)D_80808020_chgameselect,
    (void (*)(struct Actor *))func_80800E24_chgameselect,
    (void (*)(struct Actor *))func_80102EC0,
    (void (*)(s32, s32))func_808012E4_chgameselect,
    0,
    0,
    0,
    0,
    0,
    1092,
    0,
    0,
    216,
    0,
    (void (*)(struct Actor *))func_80800D74_chgameselect,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32640,
    18,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_808011B4_chgameselect,
                  (void (*)(struct Actor *, long, long))func_808011B4_chgameselect),
    0};
ActorAnimationEntry D_80808080_chgameselect[5] BT_DATA(4, overlays_ch_gameselect, 0x2D0) = {
    {0.0f, 0, 0}, {0.0f, 0x35B, 0x44}, {0.0f, 0, 0}, {3.75f, 0x35B, 9}, {3.75f, 0x35B, 0xA}};
GameSelectModel D_808080A8_chgameselect[8] BT_DATA(4, overlays_ch_gameselect, 0x2F8) = {
    {2060, 8}, {2061, 9}, {2062, 10}, {2063, 2}, {2067, 3}, {2066, 4}, {2065, 5}, {2064, 6}};
ActorData D_808080C8_chgameselect BT_DATA(4, overlays_ch_gameselect, 0x318) = {
    344,
    1192,
    0,
    1,
    (void *)D_80808080_chgameselect,
    (void (*)(struct Actor *))func_80801AC4_chgameselect,
    (void (*)(struct Actor *))func_80102EC0,
    (void (*)(s32, s32))func_801018A4,
    0,
    0,
    0,
    0,
    0,
    1060,
    0,
    0,
    0,
    0,
    0,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32640,
    8194,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_80801BA8_chgameselect,
                  (void (*)(struct Actor *, long, long))func_80801BA8_chgameselect),
    0};
f32 D_80808110_chgameselect[8][11] BT_DATA(4, overlays_ch_gameselect, 0x360) = {
    {0.51f, 0.6f, 0.67f, 0.72f, 0.77f, 0.79f, 0.83f, 0.87f, -1.0f, -1.0f, -1.0f},
    {0.08f, 0.14f, 0.23f, 0.28f, 0.325f, 0.36f, 0.39f, 0.43f, -1.0f, -1.0f, -1.0f},
    {0.31f, 0.38f, 0.44f, 0.5f, 0.55f, 0.58f, 0.62f, 0.66f, -1.0f, -1.0f, -1.0f},
    {0.14f, 0.22f, 0.315f, 0.38f, 0.46f, 0.52f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f},
    {0.18f, 0.57f, 0.73f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f},
    {0.26f, 0.312f, 0.363f, 0.42f, 0.484f, 0.535f, 0.59f, 0.65f, 0.66f, -1.0f, -1.0f},
    {0.28f, 0.37f, 0.46f, 0.52f, 0.62f, 0.66f, 0.85f, -1.0f, -1.0f, -1.0f, -1.0f},
    {0.19f, 0.21f, 0.23f, 0.255f, 0.28f, 0.3f, 0.41f, 0.45f, 0.61f, 0.65f, -1.0f}};
u16 D_80808270_chgameselect[8] BT_DATA(4, overlays_ch_gameselect, 0x4C0) = {
    0x411, 0x411, 0x411, 0x564, 0x627, 0x564, 0x564, 0x564};
u8 D_80808280_chgameselect[8] BT_DATA(4, overlays_ch_gameselect, 0x4D0) = {9,    9,    9,    0x12,
                                                                           0x14, 0x12, 0x12, 0x12};
f32 D_80808288_chgameselect[4] BT_DATA(4, overlays_ch_gameselect, 0x4D8) = {0.08f, 0.47f, 0.64f,
                                                                            -1.0f};
ActorData D_80808298_chgameselect BT_DATA(4, overlays_ch_gameselect, 0x4E8) = {
    344,
    1193,
    -1,
    1,
    0,
    (void (*)(struct Actor *))func_80802248_chgameselect,
    (void (*)(struct Actor *))func_80102EC0,
    GAME_SELECT_DRAW(func_808025CC_chgameselect),
    0,
    0,
    0,
    0,
    2,
    1028,
    (void (*)(struct Actor *))func_80802480_chgameselect,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_808021E4_chgameselect,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32768,
    8194,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_808025EC_chgameselect,
                  (void (*)(struct Actor *, long, long))func_808025EC_chgameselect),
    0};
ActorData D_808082E0_chgameselect BT_DATA(4, overlays_ch_gameselect, 0x530) = {
    344,
    1194,
    -1,
    1,
    0,
    (void (*)(struct Actor *))func_80802530_chgameselect,
    (void (*)(struct Actor *))func_80102EC0,
    GAME_SELECT_DRAW(func_808025CC_chgameselect),
    0,
    0,
    0,
    0,
    2,
    1028,
    (void (*)(struct Actor *))func_80802588_chgameselect,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_808024D4_chgameselect,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32768,
    8194,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_808025EC_chgameselect,
                  (void (*)(struct Actor *, long, long))func_808025EC_chgameselect),
    0};
ActorData D_80808328_chgameselect BT_DATA(4, overlays_ch_gameselect, 0x578) = {
    344,
    1196,
    -1,
    1,
    0,
    (void (*)(struct Actor *))func_808027DC_chgameselect,
    (void (*)(struct Actor *))func_80102EC0,
    (void (*)(s32, s32))func_80802994_chgameselect,
    0,
    0,
    0,
    0,
    2,
    1028,
    (void (*)(struct Actor *))func_808029D8_chgameselect,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_808027D4_chgameselect,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32768,
    8194,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_80802A0C_chgameselect,
                  (void (*)(struct Actor *, long, long))func_80802A0C_chgameselect),
    0};
GameSelectActions D_80808370_chgameselect BT_DATA(4, overlays_ch_gameselect, 0x5C0) = {
    {{64, (void (*)(void *))func_808039D0_chgameselect},
     {66, (void (*)(void *))func_808039D0_chgameselect},
     {72, (void (*)(void *))func_808039D0_chgameselect},
     {70, (void (*)(void *))func_80803A18_chgameselect},
     {76, (void (*)(void *))func_80803A18_chgameselect},
     {77, (void (*)(void *))func_80803A88_chgameselect}},
    {{64, (void (*)(void *))func_80803AB0_chgameselect},
     {66, (void (*)(void *))func_80803AB0_chgameselect},
     {72, (void (*)(void *))func_80803AB0_chgameselect},
     {70, (void (*)(void *))func_80803A58_chgameselect},
     {76, (void (*)(void *))func_80803A58_chgameselect}},
    {0, 255, 255, 0}};
s16 D_808083D0_chgameselect[4] BT_DATA(4, overlays_ch_gameselect, 0x620) = {255, 255, 255, 0};
s16 D_808083D8_chgameselect[4] BT_DATA(4, overlays_ch_gameselect, 0x628) = {255, 255, 0, 0};
s16 D_808083E0_chgameselect[4] BT_DATA(4, overlays_ch_gameselect, 0x630) = {175, 71, 163, 0};
SelectEntry D_808083E8_chgameselect[3] BT_DATA(4, overlays_ch_gameselect, 0x638) = {
    {6373, 0, 65}, {6374, 1, 66}, {6376, 2, 34}};
u8 D_808083FC_chgameselect[3] BT_DATA(4, overlays_ch_gameselect, 0x64C) = {0x10, 0x6F, 0x22};
u8 D_80808400_chgameselect[3] BT_DATA(4, overlays_ch_gameselect, 0x650) = {0xC, 0xD, 0x10};
u8 D_80808404_chgameselect[4] BT_DATA(4, overlays_ch_gameselect, 0x654) = {0xC, 0x9F, 0x6F, 5};
u8 D_80808408_chgameselect[4] BT_DATA(4, overlays_ch_gameselect, 0x658) = {0x36, 0x6B, 0x46, 0xAC};
u8 D_8080840C_chgameselect[5] BT_DATA(4, overlays_ch_gameselect, 0x65C) = {0xD, 0x7E, 0x40, 0xA2,
                                                                           0xCB};
u8 D_80808414_chgameselect[5] BT_DATA(4, overlays_ch_gameselect, 0x664) = {5, 6, 7, 8, 9};
u8 D_8080841C_chgameselect[8] BT_DATA(4, overlays_ch_gameselect, 0x66C) = {0xC,  0x10, 0x13, 0x6F,
                                                                           0x22, 0,    0,    0};
GameSelectMenu D_80808424_chgameselect[12] BT_DATA(4, overlays_ch_gameselect, 0x674) = {
    {0, 0, 0, 0, 0, 0, 0},
    {3, 0xF, 3, -1, 6369, 0, (unsigned char *)D_80808400_chgameselect},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {4, 0x14, 8, -1, 6389, 0, (unsigned char *)D_80808408_chgameselect},
    {0, 0, 0, 0, 0, 0, 0},
    {5, 0, 0xA, 10, 6385, 6385, (unsigned char *)D_80808414_chgameselect},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {4, 0, 8, -1, 6389, 0, (unsigned char *)D_80808408_chgameselect},
    {4, 0xA, 8, -1, 6389, 0, (unsigned char *)D_80808408_chgameselect}};
ActorData D_808084B4_chgameselect BT_DATA(4, overlays_ch_gameselect, 0x704) = {
    344,
    1206,
    -1,
    1,
    0,
    (void (*)(struct Actor *))func_80806D98_chgameselect,
    (void (*)(struct Actor *))func_80102EC0,
    GAME_SELECT_DRAW(func_80806FAC_chgameselect),
    0,
    0,
    0,
    0,
    2,
    1028,
    (void (*)(struct Actor *))func_80807030_chgameselect,
    0,
    40,
    0,
    (void (*)(struct Actor *))func_80806C54_chgameselect,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32768,
    8194,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_808070C0_chgameselect,
                  (void (*)(struct Actor *, long, long))func_808070C0_chgameselect),
    0};
s16 D_808084FC_chgameselect[4] BT_DATA(4, overlays_ch_gameselect, 0x74C) = {255, 255, 255, 0};
ActorData D_80808504_chgameselect BT_DATA(4, overlays_ch_gameselect, 0x754) = {
    344,
    1209,
    0,
    1,
    0,
    (void (*)(struct Actor *))func_80807900_chgameselect,
    (void (*)(struct Actor *))func_80102EC0,
    (void (*)(s32, s32))func_8010A730,
    0,
    0,
    0,
    0,
    0,
    4,
    (void (*)(struct Actor *))func_808079C8_chgameselect,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_808078F0_chgameselect,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32768,
    8194,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_808079D0_chgameselect,
                  (void (*)(struct Actor *, long, long))func_808079D0_chgameselect),
    0};

#include "quiz_tables.h"

s32 func_801018A4(BtIntPtr, BtIntPtr);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
void func_80801CC4_chquiz(Actor *);
void func_80802628_chquiz(Actor *);
void func_80802664_chquiz(Actor *);
void func_808029A4_chquiz(Actor *);
s32 func_80802A2C_chquiz(Actor *, s32, s32);
void func_80803470_chquiz(Actor *);
s32 func_80803588_chquiz(Actor *, s32, s32);
void func_80803910_chquiz(u8 *);
void func_80803954_chquiz(Actor *);
s32 func_808039D4_chquiz(Actor *, s32, s32);

/* data_to_c.py: from asm/data/overlays/ch/quiz.data.s */
void func_80101870();
s32 func_801018A4(BtIntPtr, BtIntPtr);
ActorAnimationEntry D_80806D00_chquiz[16] BT_DATA(4, overlays_ch_quiz, 0x0) = {
    {0.0f, 0, 0},        {6.0f, 0x3B7, 9},    {1.0f, 0x3B8, 0x4A}, {6.0f, 0x3B7, 9},
    {6.0f, 0x3B7, 9},    {0.9f, 0x3B5, 0x4A}, {6.0f, 0x3B7, 9},    {6.0f, 0x3B7, 9},
    {6.0f, 0x3B7, 9},    {1.3f, 0x3B9, 0x4A}, {6.0f, 0x3B7, 9},    {1.0f, 0x3B8, 0x4A},
    {0.5f, 0x3BA, 0x4A}, {0.1f, 0x3BB, 0x49}, {1.0f, 0x3B8, 0x4A}, {6.0f, 0x3B7, 9}};
ActorAnimationEntry D_80806D80_chquiz[16] BT_DATA(4, overlays_ch_quiz, 0x80) = {
    {0.0f, 0, 0},         {7.29f, 0x4BA, 9},    {1.67f, 0x4BC, 0x4A}, {7.29f, 0x4BA, 9},
    {7.29f, 0x4BA, 9},    {0.95f, 0x4BB, 0x4A}, {7.29f, 0x4BA, 9},    {7.29f, 0x4BA, 9},
    {7.29f, 0x4BA, 9},    {3.52f, 0x4BD, 0x4A}, {7.29f, 0x4BA, 9},    {1.67f, 0x4BC, 0x4A},
    {2.48f, 0x4BE, 0x4A}, {0.5f, 0x4BF, 0x49},  {1.67f, 0x4BC, 0x4A}, {7.29f, 0x4BA, 9}};
ActorAnimationEntry D_80806E00_chquiz[16] BT_DATA(4, overlays_ch_quiz, 0x100) = {
    {0.0f, 0, 0},        {9.0f, 0x3B0, 9},    {1.1f, 0x3B1, 0x4A}, {9.0f, 0x3B0, 9},
    {9.0f, 0x3B0, 9},    {1.0f, 0x3AE, 0x4A}, {9.0f, 0x3B0, 9},    {9.0f, 0x3B0, 9},
    {9.0f, 0x3B0, 9},    {1.4f, 0x3B2, 0x4A}, {9.0f, 0x3B0, 9},    {1.1f, 0x3B1, 0x4A},
    {0.4f, 0x3B3, 0x4A}, {0.1f, 0x3B4, 0x49}, {1.1f, 0x3B1, 0x4A}, {9.0f, 0x3B0, 9}};
ActorAnimationEntry D_80806E80_chquiz[16] BT_DATA(4, overlays_ch_quiz, 0x180) = {
    {0.0f, 0, 0},        {8.0f, 0x3BE, 9},    {1.0f, 0x3BF, 0x4A}, {8.0f, 0x3BE, 9},
    {8.0f, 0x3BE, 9},    {0.9f, 0x3BC, 0x4A}, {8.0f, 0x3BE, 9},    {8.0f, 0x3BE, 9},
    {8.0f, 0x3BE, 9},    {1.3f, 0x3C0, 0x4A}, {8.0f, 0x3BE, 9},    {1.0f, 0x3BF, 0x4A},
    {0.4f, 0x3C1, 0x4A}, {0.1f, 0x3C2, 0x49}, {1.0f, 0x3BF, 0x4A}, {8.0f, 0x3BE, 9}};
ActorAnimationEntry D_80806F00_chquiz[16] BT_DATA(4, overlays_ch_quiz, 0x200) = {
    {0.0f, 0, 0},        {8.0f, 0x3C3, 9},    {1.0f, 0x3C6, 0x4A}, {8.0f, 0x3C3, 9},
    {8.0f, 0x3C3, 9},    {0.9f, 0x3C4, 0x4A}, {8.0f, 0x3C3, 9},    {8.0f, 0x3C3, 9},
    {8.0f, 0x3C3, 9},    {1.3f, 0x3C5, 0x4A}, {8.0f, 0x3C3, 9},    {1.0f, 0x3C6, 0x4A},
    {0.4f, 0x3C7, 0x4A}, {0.1f, 0x3C8, 0x49}, {1.0f, 0x3C6, 0x4A}, {8.0f, 0x3C3, 9}};
ActorAnimationEntry D_80806F80_chquiz[16] BT_DATA(4, overlays_ch_quiz, 0x280) = {
    {0.0f, 0, 0},        {8.0f, 0x20D, 9},    {1.0f, 0x210, 0x4A}, {8.0f, 0x20D, 9},
    {8.0f, 0x20D, 9},    {0.9f, 0x20E, 0x4A}, {8.0f, 0x20D, 9},    {8.0f, 0x20D, 9},
    {8.0f, 0x20D, 9},    {1.3f, 0x20F, 0x4A}, {8.0f, 0x20D, 9},    {1.0f, 0x210, 0x4A},
    {0.4f, 0x211, 0x4A}, {0.1f, 0x215, 0x49}, {1.0f, 0x210, 0x4A}, {8.0f, 0x20D, 9}};
QuizContestant D_80807000_chquiz[7] BT_DATA(4, overlays_ch_quiz, 0x300) = {
    {2235, 0.3f, 2331, 0.31f, (ActorAnimationEntry *)D_80806D80_chquiz, 0.3f},
    {2237, 1.0f, 2333, 1.2f, (ActorAnimationEntry *)D_80806D00_chquiz, 0.3f},
    {1578, 1.0f, 2333, 1.0f, (ActorAnimationEntry *)D_80806E00_chquiz, 0.3f},
    {1637, 0.5f, 2355, 0.5f, (ActorAnimationEntry *)D_80806F00_chquiz, 0.3f},
    {2006, 0.575f, 2334, 1.15f, (ActorAnimationEntry *)D_80806E80_chquiz, 0.3f},
    {1579, 1.0f, 2333, 1.0f, (ActorAnimationEntry *)D_80806E00_chquiz, 0.3f},
    {1653, 0.08f, 2356, 0.08f, (ActorAnimationEntry *)D_80806F80_chquiz, 0.3f}};
s16 D_808070A8_chquiz[4] BT_DATA(4, overlays_ch_quiz, 0x3A8) = {157, 159, 77, -1};
s16 D_808070B0_chquiz[3] BT_DATA(4, overlays_ch_quiz, 0x3B0) = {60, 60, 60};
QuizChoices D_808070B8_chquiz BT_DATA(4, overlays_ch_quiz, 0x3B8) = {{0, 0, 0}};
s8 D_808070C4_chquiz[3][10] BT_DATA(4, overlays_ch_quiz, 0x3C4) = {{7, 8, 6, 5, 6, 7, 8, 3, 0, 4},
                                                                   {7, 8, 5, 5, 6, 7, 8, 3, 1, 4},
                                                                   {7, 8, 5, 5, 6, 7, 8, 32, 2, 4}};
QuizCameraScript D_808070E4_chquiz BT_DATA(4, overlays_ch_quiz, 0x3E4) = {
    {{0, 1, 0, 0, 2.0f}, {1, 2, 0, 0, 2.0f}, {2, 0, 0, 0, 1.0f}, {8, 0, 1, 0, 1.0f},
     {8, 0, 1, 0, 1.0f}, {8, 1, 0, 0, 1.0f}, {8, 0, 1, 0, 1.0f}, {9, 1, 1, 0, 1.5f},
     {7, 1, 1, 0, 1.5f}, {9, 0, 2, 0, 1.0f}, {9, 0, 2, 0, 1.0f}, {9, 1, 2, 0, 3.0f},
     {9, 1, 2, 0, 1.0f}, {8, 0, 1, 0, 1.0f}, {8, 0, 1, 0, 1.0f}, {8, 0, 0, 0, 1.0f},
     {8, 0, 0, 0, 1.0f}, {8, 1, 1, 0, 1.0f}, {8, 0, 1, 0, 2.0f}, {9, 1, 2, 0, 2.0f},
     {8, 1, 1, 0, 2.0f}, {2, 0, 1, 0, 1.0f}, {8, 0, 1, 0, 1.0f}, {2, 0, 1, 0, 1.0f},
     {8, 0, 1, 0, 1.0f}, {8, 1, 2, 0, 1.5f}, {8, 0, 1, 0, 1.0f}, {8, 0, 1, 0, 1.0f},
     {3, 1, 0, 0, 1.5f}, {4, 1, 0, 0, 1.5f}, {5, 1, 0, 0, 1.5f}, {6, 1, 0, 0, 1.5f},
     {8, 1, 1, 0, 1.5f}, {8, 0, 1, 0, 1.5f}, {8, 0, 1, 0, 1.5f}, {8, 0, 1, 0, 1.5f},
     {8, 0, 1, 0, 1.5f}, {8, 0, 1, 0, 1.5f}},
    {-2, -1, 2, 1, -2, -1},
    {0, 0}};
ActorAnimationEntry D_8080721C_chquiz[4] BT_DATA(4, overlays_ch_quiz, 0x51C) = {
    {0.0f, 0, 0}, {2.0f, 0x596, 9}, {0.8f, 0x597, 0x4A}, {0.8f, 0x597, 0x84}};
s32 D_8080723C_chquiz[14] BT_DATA(4, overlays_ch_quiz, 0x53C) = {
    1903069, 2818764, 57016341, 153,         2228608, 33555584, 100663321,
    7,       2949170, 6553632,  -1482184768, 721046,  9830405,  -327680};
s32 D_80807274_chquiz[18] BT_DATA(4, overlays_ch_quiz, 0x574) = {
    1902201,  1834208,  -45875154, 0,       45875260, 23528224, 720996, 13107205, -327658,
    67108903, 19661100, 39322200,  2228352, 8388736,  8388629,  230,    2818560,  50331648};
u16 D_808072BC_chquiz[8] BT_DATA(4, overlays_ch_quiz, 0x5BC) = {0x13, 0x685,  0xA, 0x119,
                                                                0x16, 0x7D00, 0,   0};
ActorData D_808072CC_chquiz BT_DATA(4, overlays_ch_quiz, 0x5CC) = {
    344,
    1324,
    2458,
    1,
    (void *)D_8080721C_chquiz,
    (void (*)(struct Actor *))func_80801CC4_chquiz,
    (void (*)(struct Actor *))func_80105834,
    (void (*)(s32, s32))func_80101870,
    0,
    0,
    0,
    0,
    8320,
    0,
    0,
    (BtIntPtr)func_80108ED0,
    0,
    0,
    0,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32768,
    17538,
    0,
    0};
f32 D_80807314_chquiz[2] BT_DATA(4, overlays_ch_quiz, 0x614) = {120.0f, 200.0f};
u32 D_8080731C_chquiz[3] BT_DATA(4, overlays_ch_quiz, 0x61C) = {0xFF, 0xFF, 0xFF};
f32 D_80807328_chquiz[3] BT_DATA(4, overlays_ch_quiz, 0x628) = {1320.0f, 113.0f, 88.0f};
ActorData D_80807334_chquiz BT_DATA(4, overlays_ch_quiz, 0x634) = {
    344,
    1321,
    0,
    1,
    0,
    (void (*)(struct Actor *))func_80802664_chquiz,
    (void (*)(struct Actor *))func_80105834,
    (void (*)(s32, s32))func_801018A4,
    0,
    0,
    0,
    0,
    0,
    360,
    (void (*)(struct Actor *))func_808029A4_chquiz,
    (BtIntPtr)func_80108ED0,
    4,
    0,
    (void (*)(struct Actor *))func_80802628_chquiz,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32764,
    1026,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_80802A2C_chquiz,
                  (void (*)(struct Actor *, long, long))func_80802A2C_chquiz),
    0};
ActorAnimationEntry D_8080737C_chquiz[5] BT_DATA(4, overlays_ch_quiz,
                                                 0x67C) = {{0.0f, 0, 0},
                                                           {0.95f, 0x3AF, 0x44},
                                                           {0.95f, 0x3AF, 0x4A},
                                                           {0.95f, 0x3AF, 0x44},
                                                           {0.95f, 0x3AF, 0x44}};
ActorAnimationEntry D_808073A4_chquiz[5] BT_DATA(4, overlays_ch_quiz,
                                                 0x6A4) = {{0.0f, 0, 0},
                                                           {0.95f, 0x4C0, 0x44},
                                                           {0.95f, 0x4C0, 0x4A},
                                                           {0.95f, 0x4C0, 0x44},
                                                           {0.95f, 0x4C0, 0x44}};
ActorAnimationEntry D_808073CC_chquiz[10] BT_DATA(4, overlays_ch_quiz, 0x6CC) = {
    {0.0f, 0, 0},         {0.95f, 0x3AF, 0x44}, {0.95f, 0x3AF, 0x4A}, {0.95f, 0x3AF, 0x44},
    {0.95f, 0x3AF, 0x44}, {0.0f, 0, 0},         {0.95f, 0x3AF, 0x44}, {0.95f, 0x3AF, 0x4A},
    {0.95f, 0x3AF, 0x44}, {0.95f, 0x3AF, 0x44}};
ActorAnimationEntry D_8080741C_chquiz[5] BT_DATA(4, overlays_ch_quiz,
                                                 0x71C) = {{0.0f, 0, 0},
                                                           {0.95f, 0x3AF, 0x44},
                                                           {0.95f, 0x3AF, 0x4A},
                                                           {0.95f, 0x3AF, 0x44},
                                                           {0.95f, 0x3AF, 0x44}};
ActorAnimationEntry D_80807444_chquiz[5] BT_DATA(4, overlays_ch_quiz,
                                                 0x744) = {{0.0f, 0, 0},
                                                           {0.95f, 0x216, 0x44},
                                                           {0.95f, 0x216, 0x4A},
                                                           {0.95f, 0x216, 0x44},
                                                           {0.95f, 0x216, 0x44}};
f32 D_8080746C_chquiz[2] BT_DATA(4, overlays_ch_quiz, 0x76C) = {100.0f, 250.0f};
u32 D_80807474_chquiz[3] BT_DATA(4, overlays_ch_quiz, 0x774) = {0xFF, 0xC8, 0};
ActorData D_80807480_chquiz BT_DATA(4, overlays_ch_quiz, 0x780) = {
    344,
    1323,
    0,
    1,
    0,
    (void (*)(struct Actor *))func_80803470_chquiz,
    (void (*)(struct Actor *))func_80105834,
    (void (*)(s32, s32))func_801018A4,
    0,
    0,
    0,
    0,
    8320,
    64,
    (void (*)(struct Actor *))func_80803910_chquiz,
    (BtIntPtr)func_80108ED0,
    0,
    0,
    0,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32764,
    1026,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_80803588_chquiz,
                  (void (*)(struct Actor *, long, long))func_80803588_chquiz),
    0};
f32 D_808074C8_chquiz[2] BT_DATA(4, overlays_ch_quiz, 0x7C8) = {120.0f, 250.0f};
u32 D_808074D0_chquiz[3] BT_DATA(4, overlays_ch_quiz, 0x7D0) = {0xFF, 0xC8, 0x96};
ActorData D_808074DC_chquiz BT_DATA(4, overlays_ch_quiz, 0x7DC) = {
    344,
    1326,
    2466,
    1,
    0,
    (void (*)(struct Actor *))func_80803954_chquiz,
    (void (*)(struct Actor *))func_80105834,
    (void (*)(s32, s32))func_801018A4,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (BtIntPtr)func_80108ED0,
    0,
    0,
    0,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C,
                  (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32768,
    1026,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_808039D4_chquiz,
                  (void (*)(struct Actor *, long, long))func_808039D4_chquiz),
    0};
ActorAnimationEntry D_80807524_chquiz[7] BT_DATA(4, overlays_ch_quiz, 0x824) = {
    {0.0f, 0, 0},        {8.0f, 0x4C2, 9}, {1.6f, 0x4C4, 0x4A}, {1.6f, 0x4C3, 0x4A},
    {9.5f, 0x4C5, 0x4A}, {1.3f, 0x4C6, 9}, {6.5f, 0x4C7, 0xA}};
f32 D_8080755C_chquiz[2] BT_DATA(4, overlays_ch_quiz, 0x85C) = {500.0f, 750.0f};
u32 D_80807564_chquiz[3] BT_DATA(4, overlays_ch_quiz, 0x864) = {0xFF, 0xC8, 0};
QuizTimes4 D_80807570_chquiz BT_DATA(4, overlays_ch_quiz, 0x870) = {{0.43f, 0.49f, 0.58f, -1.0f}};
QuizTimes6 D_80807580_chquiz BT_DATA(4, overlays_ch_quiz,
                                     0x880) = {{0.58f, 0.68f, 0.78f, 0.84f, 0.88f, -1.0f}};
QuizTimes6 D_80807598_chquiz BT_DATA(4, overlays_ch_quiz,
                                     0x898) = {{0.56f, 0.66f, 0.76f, 0.82f, 0.86f, -1.0f}};
u16 D_808075B0_chquiz[8] BT_DATA(4, overlays_ch_quiz, 0x8B0) = {0x13, 0x564,  0xA, 0x100,
                                                                0x16, 0x7FFF, 0,   0};
s32 D_808075C0_chquiz[11] BT_DATA(4, overlays_ch_quiz, 0x8C0) = {
    1903069, 1638400, 917531,   13107500, -1660813278, 3342387, 33555456,
    1376256, 4980779, 25166464, 0};
s32 D_808075EC_chquiz[14] BT_DATA(4, overlays_ch_quiz, 0x8EC) = {
    1903054, 1572864, 3072,     251658251, 655390,  -1245214, 2162688,
    180,     2228480, 16777625, 30146581,  4980928, 2818073,  3342336};
u16 D_80807624_chquiz[14] BT_DATA(4, overlays_ch_quiz, 0x924) = {
    0x13, 0x4DC, 0xC, 0, 0x300, 0xCC, 0x133, 0x16, 0x7FFF, 0x15, 0x100, 0x380, 0x180, 0};

#include "common.h"

OSThread *chlagoonbits_entrypoint_0(void)
{
    extern ActorData D_80800804_chlagoonbits[];

    return (OSThread *) D_80800804_chlagoonbits;
}

OSThread *chlagoonbits_entrypoint_1(void)
{
    extern ActorData D_8080084C_chlagoonbits[];

    return (OSThread *) D_8080084C_chlagoonbits;
}

OSThread *chlagoonbits_entrypoint_2(void)
{
    extern ActorData D_80800894_chlagoonbits[];

    return (OSThread *) D_80800894_chlagoonbits;
}

OSThread *chlagoonbits_entrypoint_3(void)
{
    extern ActorData D_808008DC_chlagoonbits[];

    return (OSThread *) D_808008DC_chlagoonbits;
}

OSThread *chlagoonbits_entrypoint_4(void)
{
    extern ActorData D_80800924_chlagoonbits[];

    return (OSThread *) D_80800924_chlagoonbits;
}

OSThread *chlagoonbits_entrypoint_5(void)
{
    extern ActorData D_8080096C_chlagoonbits[];

    return (OSThread *) D_8080096C_chlagoonbits;
}

BT_NATIVE_ONLY(struct player_state_s; s32 _subaddiesect_entrypoint_1(Actor *);) void func_80800048_chlagoonbits(s32 arg0)
{
}
void func_80800050_chlagoonbits(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor*);
    if (func_800DA298(arg0->unk6C_9 == 0x368 ? 0xCB : 0xCC) != 0) {
        func_800FFAB0(arg0);
    }
}

void func_808000A4_chlagoonbits(s32 arg0) 
{
}                typedef struct { u8 pad0[0x28]; s32 unk28; u8 pad2C[0x39]; u8 unk65; } Objbits_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
/* extern */

void func_808000AC_chlagoonbits(void *arg0) {
    BT_IDO_ONLY(s32 _subaddiesect_entrypoint_1();)
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    (((Objbits_arg0 *)arg0)->unk28) = _subaddiesect_entrypoint_1(BT_NATIVE_ONLY((Actor *)arg0));
    if (func_800DA298(0xCF) != 0) {
        func_80108B04(arg0, 0);
        func_80101FDC(arg0, 3);
        (((Objbits_arg0 *)arg0)->unk65) = (u8) ((((Objbits_arg0 *)arg0)->unk65) & 0xFFFE);
    }
}

void func_80800108_chlagoonbits(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor *);
    s32 _subaddiesect_entrypoint_2(Actor *arg0, s32 arg1, s32 arg2);
    s32 func_800D0B68(u32, u32);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    s32 func_800DA298(s32);
    s32 func_800DA564(s32, s32);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    s32 func_800DA9E4(s32, s32);
    s32 func_800DC128(s32, s32);
    void func_800FFAB0(Actor *);
    void func_80102FDC(void *, f32);
    s32 sp2C;
    s32 sp28;

    arg0->actorData[4] = _subaddiesect_entrypoint_1(arg0);
    func_80102FDC(arg0, 0.6f);
    if (func_800DA9E4(0xD0, 1) == 0) {
        func_800DA7A8(0xD1, func_800DC128(0, 4), 2);
    }
    sp2C = func_800DA564(0xD1, 2);
    sp28 = arg0->unk74_7 - 0x32;
    if ((func_800DA298(0x45) != 0) || (sp2C != sp28)) {
        if ((sp2C == sp28) && (func_800D0B68(0x14, 0) == 0)) {
            func_800D1000(0x14, 0, arg0->position, 3, NULL);
        }
        func_800FFAB0(arg0);
    } else {
        _subaddiesect_entrypoint_2(arg0, arg0->actorData[4], 1);
    }
}

/* extern */

void func_808001F4_chlagoonbits(Actor *arg0) {
    s32 _subaddieDll_entrypoint_6(Actor*, s32);
    void func_8080023C_chlagoonbits(Actor *);
    if (((((u32) (*(u16 *)((s8 *)(arg0) + (0x72)))) >> 0xA) == 2) && (_subaddieDll_entrypoint_6(arg0, 0xB) != 0)) {
        func_8080023C_chlagoonbits(arg0);
    }
}

/* extern */

void func_8080023C_chlagoonbits(Actor *arg0) {
    void func_808002CC_chlagoonbits(Actor *);
    void func_80800360_chlagoonbits(Actor *);
    void func_8080041C_chlagoonbits(Actor *volatile);
    void func_808004B0_chlagoonbits(Actor *);
    void func_80800548_chlagoonbits(Actor *volatile);
    switch (arg0->unk6C_9) {
    case 0x366:
        func_808002CC_chlagoonbits(arg0);
        return;
    case 0x367:
    case 0x368:
        func_80800360_chlagoonbits(arg0);
        return;
    case 0x369:
        func_8080041C_chlagoonbits(arg0);
        return;
    case 0x36C:
        func_808004B0_chlagoonbits(arg0);
        return;
    case 0x36D:
        func_80800548_chlagoonbits(arg0);
        /* fallthrough */
    default:
        return;
    }
}

void func_808002CC_chlagoonbits(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800DA544(s32 index);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_808007D0_chlagoonbits[13];
    extern s32 D_808009B4_chlagoonbits[6];
    f32 sp24[3];

    func_800EE7F8(sp24, arg0->position);
    func_800EF1B8(sp24, arg0->rotation[1], -100.0f);
    _chexploder_entrypoint_3(arg0, sp24, 0xE);
    func_800BBCB8(arg0->position, sp24, 0.8f, 5, D_808007D0_chlagoonbits);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808009B4_chlagoonbits);
    func_800DA544(0xCE);
}

void func_80800360_chlagoonbits(Actor *arg0)
{
  void _chexploder_entrypoint_3(void *, void *, u32);
  void _subaddieaudioquick_entrypoint_2(Actor *, f32 [3], void *);
  BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
  void func_800DA544(s32 index);
  void func_800EE7F8(f32 *, f32 *);
  void func_800EF1B8(f32 *, f32, f32);
  extern s32 D_808007D0_chlagoonbits[13];
  extern s32 D_808009CC_chlagoonbits[6];
  s32 sp3C;
  f32 sp30[3];
  f32 *sp2C[1];
  if (arg0->unk6C_9 == 0x368)
  {
    sp3C = 0xCB;
  }
  else
  {
    sp3C = 0xCC;
  }
  if (sp30)
  {
  }
  sp2C[0] = arg0->position;
  func_800EE7F8(sp30, sp2C[0]);
  func_800EF1B8(sp30, arg0->rotation[1], -100.0f);
  _subaddieaudioquick_entrypoint_2(arg0, sp2C[0], D_808009CC_chlagoonbits);
  func_800BBCB8(sp2C[0], sp30, 0.8f, 5, D_808007D0_chlagoonbits);
  _chexploder_entrypoint_3(arg0, sp30, 0xE);
  func_800DA544(sp3C);
}

void func_8080041C_chlagoonbits(Actor *volatile arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800DA544(s32 index);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_808009E4_chlagoonbits[6];
    extern s32 D_808009FC_chlagoonbits[13];
    f32 sp24[3];
    f32 *sp20;

    sp20 = arg0->position;
    func_800EE7F8(sp24, sp20);
    sp24[1] -= 100.0f;
    _subaddieaudioquick_entrypoint_2(arg0, sp20, D_808009E4_chlagoonbits);
    func_800BBCB8(sp20, sp24, 0.8f, 5, D_808009FC_chlagoonbits);
    _chexploder_entrypoint_3(arg0, sp24, 0xE);
    func_800DA544(0xCD);
}

void func_808004B0_chlagoonbits(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800DA544(s32 index);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    extern s32 D_80800A30_chlagoonbits[13];
    extern s32 D_80800A64_chlagoonbits[6];
    f32 *temp_s0;

    temp_s0 = arg0->position;
    _chexploder_entrypoint_3(arg0, temp_s0, 7);
    _subaddieaudioquick_entrypoint_2(arg0, temp_s0, D_80800A64_chlagoonbits);
    func_800BBCB8(temp_s0, temp_s0, 2.0f, 6, D_80800A30_chlagoonbits);
    func_80108B04(arg0, 0);
    func_80101FDC(arg0, 3);
    arg0->unk64_16 = 0;
    func_800DA544(0xCF);
}

void func_80800548_chlagoonbits(Actor *volatile arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    void func_800DA544(s32 index);
    void func_800FFAB0(Actor *);
    extern s32 D_808007D0_chlagoonbits[13];
    f32 *temp_s0;

    temp_s0 = arg0->position;
    func_800D1000(0x14, 0, temp_s0, 1, 0);
    _chexploder_entrypoint_3(arg0, temp_s0, 7);
    func_800BBCB8(temp_s0, temp_s0, 0.8f, 5, D_808007D0_chlagoonbits);
    func_800DA544(0x45);
    func_800FFAB0(arg0);
}

void func_808005D0_chlagoonbits(Actor *arg0, s32 arg1) {
    void func_800FFAB0(Actor *);
    void func_80102FDC(void *, f32);
    Actor *func_80108474(u32, f32 *, s32);
    extern f32 D_80800A7C_chlagoonbits[3];
    extern f32 D_80800A88_chlagoonbits[6];
    if (arg0->unk70_10 == 3) {
        func_800FFAB0(arg0);
    }
    if (arg1 == 0) {
        func_80102FDC(func_80108474(0x156, D_80800A88_chlagoonbits, 0), 0.9f);
        func_80102FDC(func_80108474(0x157, D_80800A7C_chlagoonbits, 0), 0.9f);
    }
}

s32 func_80800658_chlagoonbits(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80800730_chlagoonbits(Actor *, BtIntPtr);
    void _chexploder_entrypoint_6(Actor *arg0, f32 arg1, f32 arg2);
    void _chexploder_entrypoint_7(Actor *arg0, f32 arg1, f32 arg2);
    void _chexploder_entrypoint_12(Actor *arg0, s32 arg1);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    s32 *value = &arg2;

    switch (arg1) {
    case 0x40:
        func_80800730_chlagoonbits(arg0, arg2);
        break;
    case 0x3D:
        func_808005D0_chlagoonbits(arg0, arg2);
        break;
    case 0x90:
        actor = func_80106790(func_80101080());
        switch (arg2) {
        case 0x761:
            _chexploder_entrypoint_6(actor, 500.0f, 600.0f);
            _chexploder_entrypoint_7(actor, -500.0f, -400.0f);
            break;
        case 0x786:
            _chexploder_entrypoint_12(actor, 0x32);
            break;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800730_chlagoonbits(Actor *arg0, BtIntPtr arg1) {
    s32 _subaddieDll_entrypoint_5(Actor *arg0, Unk80132ED0 *arg1);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    if (arg0->unk6C_9 == 0x369) {
        if (_subaddieDll_entrypoint_5(arg0, arg1) != 0) {
            func_80103110(arg0, 1);
            func_80101FDC(arg0, 2);
            return;
        }
        func_8080023C_chlagoonbits(arg0);
        return;
    }
    func_8080023C_chlagoonbits(arg0);
}
/* data_to_c.py: from asm/data/overlays/ch/lagoon/bits.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_808007D0_chlagoonbits[13] BT_DATA(4, overlays_ch_lagoon_bits, 0x0) = { 1903069, 2818816, 67108898, 25166336, 75499008, 1376256, 10027033, 7, 2949170, 4915232, -2134327104, 917584, 6553600 };
ActorData D_80800804_chlagoonbits [1] BT_DATA(4, overlays_ch_lagoon_bits, 0x34) = { { 408, 870, 1887, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 206, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800048_chlagoonbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_80800658_chlagoonbits, 0 } };
ActorData D_8080084C_chlagoonbits [1] BT_DATA(4, overlays_ch_lagoon_bits, 0x7C) = { { 770, 871, 1889, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800050_chlagoonbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_80800658_chlagoonbits, 0 } };
ActorData D_80800894_chlagoonbits [1] BT_DATA(4, overlays_ch_lagoon_bits, 0xC4) = { { 770, 872, 1889, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800050_chlagoonbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_80800658_chlagoonbits, 0 } };
ActorData D_808008DC_chlagoonbits [1] BT_DATA(4, overlays_ch_lagoon_bits, 0x10C) = { { 771, 873, 1890, 1, 0, (void (*)(struct Actor *))func_808001F4_chlagoonbits, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 205, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808000A4_chlagoonbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_80800658_chlagoonbits, 0 } };
ActorData D_80800924_chlagoonbits [1] BT_DATA(4, overlays_ch_lagoon_bits, 0x154) = { { 769, 876, 1926, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808000AC_chlagoonbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_80800658_chlagoonbits, 0 } };
ActorData D_8080096C_chlagoonbits [1] BT_DATA(4, overlays_ch_lagoon_bits, 0x19C) = { { 761, 877, 1893, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2052, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800108_chlagoonbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_80800658_chlagoonbits, 0 } };
s32 D_808009B4_chlagoonbits[6] BT_DATA(4, overlays_ch_lagoon_bits, 0x1E4) = { 1769491, 83099658, 13369366, 1835008001, 81922500, 0 };
s32 D_808009CC_chlagoonbits[6] BT_DATA(4, overlays_ch_lagoon_bits, 0x1FC) = { 1769491, 80216077, 15925516, 1469792, 66786, 163840000 };
s32 D_808009E4_chlagoonbits[6] BT_DATA(4, overlays_ch_lagoon_bits, 0x214) = { 1769491, 80216077, 15925516, 1469792, 66786, 163840000 };
s32 D_808009FC_chlagoonbits[13] BT_DATA(4, overlays_ch_lagoon_bits, 0x22C) = { 1903069, 2818816, 67108898, 25166336, 75499008, 1376256, 10027033, 7, 2949170, 4915232, -2134851392, 917584, 6553600 };
s32 D_80800A30_chlagoonbits[13] BT_DATA(4, overlays_ch_lagoon_bits, 0x260) = { 1903069, 2818816, 67108898, 25166336, 75499008, 1376256, 10027033, 7, 2949170, 4915232, 2022473920, 917584, 6553600 };
s32 D_80800A64_chlagoonbits[6] BT_DATA(4, overlays_ch_lagoon_bits, 0x294) = { 1769491, 68354058, 15073302, 1835008001, 81922500, 0 };
f32 D_80800A7C_chlagoonbits[3] BT_DATA(4, overlays_ch_lagoon_bits, 0x2AC) = { -8890.0f, 9175.0f, -9990.0f };
f32 D_80800A88_chlagoonbits[6] BT_DATA(4, overlays_ch_lagoon_bits, 0x2B8) = { -9110.0f, 9175.0f, -9990.0f, 0.0f, 0.0f, 0.0f };

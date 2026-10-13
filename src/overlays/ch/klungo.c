#include "common.h"

OSThread *chklungo_entrypoint_0(void)
{
    extern u8 D_80803B6C_chklungo[];

    return (OSThread *) D_80803B6C_chklungo;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080000C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808002D0_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080101C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808010E0_chklungo.s")

void func_808011B4_chklungo(void *arg0, s32 arg1)
{
  s32 func_800DF440(s32);
  s32 func_80101808(void *, s32 *);
  extern s32 func_801017D0;
  u32 temp_t7;
  temp_t7 = (u16) (*((u16 *) (((s8 *) arg0) + 0x72)));
  temp_t7 = temp_t7 >> 0xA;
  if (((temp_t7 == 0xD) || (temp_t7 == 0x15)) || (temp_t7 == 0x16))
  {
    func_800DF440(0);
  }
  else
  {
    func_800DF440(1);
  }
  func_80101808(arg0, &func_801017D0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80801220_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080162C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80801680_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80801744_chklungo.s")

void func_80801848_chklungo(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    _susubgame_entrypoint_3(arg0, (s32)func_80100094(arg0, 0U) + 0x88, arg1, arg2);
}

void func_80801888_chklungo(void *arg0) {
    void func_8010D600(s32 *);
    f32 func_80102D78(void *, s32 *);
    void func_80102BF8(void *, f32, f32, f32);
    s32 sp1C[3];

    func_8010D600(sp1C);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = func_80102D78(arg0, sp1C);
    func_80102BF8(arg0, 0.15f, 4.0f, 200.0f);
}

/* extern */

void func_808018D4_chklungo(void *arg0) {
    s32 func_800EFD24(s32 *);
    f32 func_80102D78(void *, s32 *);
    s32 sp1C[3];
    f32 temp_f0;

    func_800EFD24(sp1C);
    temp_f0 = func_80102D78(arg0, sp1C);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = temp_f0;
    (*(f32 *)((s8 *)(arg0) + (0x48))) = temp_f0;
}

void func_80801910_chklungo(u8 *arg0) {
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    Actor *actor = (Actor *)arg0;
    _sudeflect_entrypoint_0(actor->position, actor->scale * 100.0f, actor->scale * 130.0f, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80801964_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808020F0_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080220C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080231C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808023A4_chklungo.s")

s32 func_8080242C_chklungo(void) {
    s32 func_800EA05C();
    extern s16 D_808038A0_chklungo;
    s8 *var_a0;
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_800EA05C();
    var_a0 = &D_808038A0_chklungo;
    var_v1 = 0;
loop_1:
    if (temp_v0 == *(s16 *) var_a0) {
        return var_v1;
    }
    var_v1 += 1;
    var_a0 += 0x84;
    if (var_v1 == 3) {
        return -1;
    }
    goto loop_1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802480_chklungo.s")

void func_80802558_chklungo(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _susubgame_entrypoint_4(void *, s32);
    _susubgame_entrypoint_4(arg0, (s32)func_80100094(arg0, 0U) + 0x88);
}

void func_80802588_chklungo(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    _susubgame_entrypoint_5(arg0, (u8 *)func_80100094(arg0, 0U) + 0x88, arg1, arg2, 0);
}

void func_808025CC_chklungo(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    extern s16 D_808038A0_chklungo;
    void *data;
    s32 *entry;
    s32 a3;
    s32 a2;

    data = func_80100094(arg0, 0U);
    entry = (s32 *)((u8 *)&D_808038A0_chklungo + (*(s16 *)((u8 *)data + 8) * 0x84) + (arg1 * 8));
    a3 = entry[3];
    a2 = entry[2];
    _susubgame_entrypoint_6(arg0, (u8 *)data + 0x88, a2, a3, 0);
}

void func_80802634_chklungo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    void _subaddieaudioquick_entrypoint_4(Actor*, f32*, u32*, u32*);
    extern u32 D_80803BE0_chklungo;
    extern u32 D_80803BEC_chklungo;
    extern u32 D_80803BFC_chklungo;
    extern u32 D_80803C0C_chklungo;
    extern u32 D_80803C1C_chklungo;
    extern u32 D_80803C2C_chklungo;
    f32 *temp_s1;

    temp_s1 = (f32 *)((s8 *)arg0 + 4);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_80803BE0_chklungo, 0.2f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, &D_80803BEC_chklungo, 0.78f);
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, &D_80803C0C_chklungo, &D_80803C2C_chklungo);
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, &D_80803BFC_chklungo, &D_80803C1C_chklungo);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808026CC_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802798_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802864_chklungo.s")

void func_808028E8_chklungo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_80803C98_chklungo;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80803C98_chklungo, 0.0f);
}

void func_80802914_chklungo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_80803CA8_chklungo;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80803CA8_chklungo, 0.0f);
}

void func_80802940_chklungo(s32 arg0) {
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    s32 func_80018820(s32, s32, s32);
    s32 func_800E15CC(s32, s32, s32);
    s32 func_8080299C_chklungo();
    extern s32 D_80803CB8_chklungo;
    func_8080299C_chklungo();
    func_80018820(0, 0x3F800000, 0x3ECCCCCD);
    func_800E15CC(0, 0x41200000, 0x3F4CCCCD);
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80803CB8_chklungo);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080299C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802B10_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802B84_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802DF4_chklungo.s")

void func_80802F30_chklungo(s32 arg0) {
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    extern s32 D_80803D18_chklungo;
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80803D18_chklungo);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802F58_chklungo.s")

void func_80802FCC_chklungo(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    (*(u8 *)((s8 *)(sp1C) + (0x48))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0x48))));
}

/* extern */

void func_80803000_chklungo(Actor *arg0) {
    u32 func_800F54E4(void);
    void* func_80100094(Actor*, u32);
    s32 func_800F4AF4(u32, s32);
    s32 func_808030A4_chklungo(Actor *);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if ((*(s16 *)((s8 *)(temp_v0) + (0x46))) == 0) {
        func_800F4AF4(func_800F54E4(), 0x14);
        (*(s16 *)((s8 *)(sp1C) + (0x46))) = 1;
    }
    func_808030A4_chklungo(arg0);
}

/* extern */

void func_8080305C_chklungo(Actor *arg0) {
    u32 func_800F54E4(void);
    void* func_80100094(Actor*, u32);
    s32 func_800F4B20(u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if ((*(s16 *)((s8 *)(temp_v0) + (0x46))) != 0) {
        func_800F4B20(func_800F54E4());
        (*(s16 *)((s8 *)(sp1C) + (0x46))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808030A4_chklungo.s")

s32 func_80803158_chklungo(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    return _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0xAB);
}

/* extern */

void func_8080318C_chklungo(Actor *arg0) {
    void func_80101CDC(Actor*, f32);
    f32 func_8010203C(Actor *, u32);
    f32 sp1C;

    sp1C = 300.0f / *(f32 *)((s8 *)arg0 + 0x24);
    func_80101CDC(arg0, func_8010203C(arg0, arg0->unk70_10) * sp1C);
}

f32 func_808031E4_chklungo(void *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = *(f32 *)((s8 *)(arg0) + 0x24) / 300.0f;
    temp_f2 = 400.0f;
    return temp_f2 * temp_f0;
}

void func_80803208_chklungo(s32 *arg0) {
    s32 func_80105230();
    extern s32 D_80803D38_chklungo;
    func_80105230(arg0, &D_80803D38_chklungo);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080322C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80803304_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80803390_chklungo.s")

/* extern */

void func_80803464_chklungo(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 func_800EE7F8(s32, void *);
    s32 func_800EF1B8(s32, f32, f32);
    f32 func_800F1DF4(void *, s32);
    f32 sp1C;

    sp1C = func_800F1DF4(arg1, arg2);
    func_800EE7F8(arg3, arg1);
    func_800EF1B8(arg3, sp1C, (f32) (*(s16 *)((s8 *)(arg1) + (0xC))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808034CC_chklungo.s")

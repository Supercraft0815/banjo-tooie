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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80801848_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80801888_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808018D4_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80801910_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80801964_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808020F0_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080220C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080231C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808023A4_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080242C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802480_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802558_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802588_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808025CC_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802634_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808026CC_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802798_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802864_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808028E8_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80802914_chklungo.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80803000_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080305C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808030A4_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_80803158_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_8080318C_chklungo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/func_808031E4_chklungo.s")

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

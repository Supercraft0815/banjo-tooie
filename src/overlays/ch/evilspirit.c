#include "common.h"

OSThread *chevilspirit_entrypoint_0(void)
{
    extern u8 D_80802270_chevilspirit[];

    return (OSThread *) D_80802270_chevilspirit;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_8080000C_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800104_chevilspirit.s")

void func_808005B4_chevilspirit(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x24)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (*(s32 *)((s8 *)(arg0) + (0x24))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808005EC_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800718_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808007B4_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800A4C_chevilspirit.s")

void func_80800BFC_chevilspirit(Actor *arg0, Gfx **arg1, s32 *arg2, s16 *arg3, u8 *arg4) {
    s32 x;
    s32 y;
    s32 alpha;

    x = (arg2[0] + arg3[0]) & 0xFFFC;
    y = (arg2[1] + arg3[1]) & 0xFFFC;
    gDPPipeSync((*arg1)++);
    alpha = (arg4[3] * arg0->alpha) >> 8;
    gDPSetFogColor((*arg1)++, arg4[0] >> 2, arg4[1] >> 2, arg4[2] >> 2, (alpha >> 1) + (alpha >> 2));
    gSPTextureRectangle((*arg1)++, x - 8, y - 8, x + 8, y + 8, 0, 0, 0, 256, 256);
    gDPPipeSync((*arg1)++);
    gDPSetFogColor((*arg1)++, arg4[0], arg4[1], arg4[2], alpha);
    gSPTextureRectangle((*arg1)++, x - 4, y - 4, x + 4, y + 4, 0, 0, 0, 256, 256);
}

void func_80800E20_chevilspirit(Actor *arg0, Gfx **arg1, s32 *arg2)
{
  s32 y;
  s32 x;
  if (((arg0->unk70_10 != 1) && (arg0->unk70_10 != 2)) && (arg0->unk70_10 != 3))
  {
    x = arg2[0] & (~3);
    y = arg2[1] & (~3);
    gDPPipeSync((*arg1)++);
    gDPSetFogColor((*arg1)++, 255, 255, 255, (arg0->alpha << 7) >> 8);
    gSPTextureRectangle((*arg1)++, x - 4, y, x + 8, y + 4, 0, 0, 0, 256, 256);
    gSPTextureRectangle((*arg1)++, x, y - 4, x + 4, y + 8, 0, 0, 0, 256, 256);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800F8C_chevilspirit.s")

int func_80800FF8_chevilspirit(s32 arg0) {
    s32 func_800EA05C();
    extern u16 D_808022E4_chevilspirit;
    extern u16 D_808022E8_chevilspirit;
    u16 *ptr;
    s32 map;

    map = func_800EA05C();
    ptr = &D_808022E4_chevilspirit; loop_1: if (map == *ptr) {
            return 1;
        }
        ptr++;
        if (ptr == &D_808022E8_chevilspirit) {
            return 0;
        }
    goto loop_1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_8080104C_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808012CC_chevilspirit.s")

/* extern */

void func_80801344_chevilspirit(u8 *arg0) {
    s32 func_8008FE94(s32, s32, u8 *);
    f32 func_80090010();
    s32 func_808013DC_chevilspirit(u8 *);
    func_8008FE94(5, arg0 + 0x18, arg0);
    (*(f32 *)((s8 *)(arg0) + (0x1C))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x1C))) + 100.0f);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = func_80090010();
    func_808013DC_chevilspirit(arg0);
}

/* extern */

void func_80801398_chevilspirit(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_808013DC_chevilspirit(u8 *);
    s32 func_80801458_chevilspirit();
    s32 _subaddielink_entrypoint_4(u8 *);
    if (_subaddielink_entrypoint_4(func_80100094(arg0, 0U)) != 0) {
        func_80801458_chevilspirit(arg0);
        func_808013DC_chevilspirit((u8 *) arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808013DC_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801458_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801534_chevilspirit.s")

/* extern */

void func_808015A4_chevilspirit(s32 arg0) {
    s32 func_80102424(s32, s32);
    s32 func_80801458_chevilspirit();
    s32 func_808015E0_chevilspirit(s32, s32);
    func_80801458_chevilspirit();
    if (func_808015E0_chevilspirit(arg0, 0x42C80000) != 0) {
        func_80102424(arg0, 6);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808015E0_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801684_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801840_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808018DC_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801988_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801A6C_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801B00_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801C04_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801E18_chevilspirit.s")

/* extern */

s32 func_80801EC4_chevilspirit(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F6D24(s32);
    s32 func_800F8004(s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F6D24(temp_v0) != 0) {
        return 0;
    }
    if (func_800F8004(sp1C) != 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801F1C_chevilspirit.s")

/* extern */

void func_80802024_chevilspirit(Actor *arg0, s32 arg1, s32 arg2) {
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    u32 func_800C07F4(void);
    void *func_80100094(Actor *, u32);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0);
    if ((func_800C07F4() == 0) && (arg1 == 0x15C5) && (arg2 == 1)) {
        _susubgame_entrypoint_6(arg0, sp24 + 0x40, 5, 0x20, 0);
    }
}

/* extern */

void func_80802090_chevilspirit(Actor *arg0, s32 *arg1) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    f32 *sp20 = arg0->position;
    if (arg0->unk5F == 0) {
        arg0->unk5F = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
        func_800C330C(arg0->unk5F, 3);
    }
    func_800C3058(arg0->unk5F, 0x55F0);
    func_800C31DC(arg0->unk5F, 1.0f);
    func_800C4350(arg0->unk5F, sp20, arg1);
    func_800C3BDC(arg0->unk5F);
}

/* extern */

void func_80802118_chevilspirit(void *arg0) {
    s32 func_800C2FDC(u8);
    s32 func_800C3D78(s32, u8);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x5F)));
    if ((temp_a1 != 0) && (func_800C3D78(temp_a1 & 0xFF, temp_a1) == 0)) {
        func_800C2FDC((*(u8 *)((s8 *)(arg0) + (0x5F))));
        (*(u8 *)((s8 *)(arg0) + (0x5F))) = 0U;
    }
}

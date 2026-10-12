#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80800000_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80800124_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80800434_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80800A94_chpotogoldgame.s")

/* extern */

void chpotogoldgame_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_800D395C();
    s32 func_80106790(s32);
    s32 func_80800434_chpotogoldgame(s32, s32);
    if (func_800D395C() != 0) {
        func_80800434_chpotogoldgame(func_80106790(arg1), 0xE);
        return;
    }
    func_80800434_chpotogoldgame(func_80106790(arg1), 8);
}

/* extern */

void func_808010A0_chpotogoldgame(void *arg0) {
    s32 func_800D2054(s32, s32, s32);
    s32 func_800D211C(s32);
    s32 func_8080206C_chpotogoldgame();
    s32 sp1C;

    sp1C = func_8080206C_chpotogoldgame();
    if (func_800D211C(0x84) == 0x64) {
        func_800D2054(1, 0x89, (*(s32 *)((s8 *)(arg0) + (0x20))));
        return;
    }
    if (sp1C == 0x64) {
        func_800D2054(1, 0x89, (*(s32 *)((s8 *)(arg0) + (0x20))));
    }
    func_800D2054(0, 0x84, sp1C);
}

/* extern */

void func_8080111C_chpotogoldgame(s32 arg0) {
    s32 _gccubesearch_entrypoint_1(s32, s32);
    s32 _gspropctrl_entrypoint_11(s32, s32 *);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    s32 func_80802124_chpotogoldgame(s32, s32, s32);
    s32 pad[2];
    s32 sp24;

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x1F6, arg0 + 4), &sp24);
    func_800D1000(0x49, 1, &sp24, 1, 0);
    func_80802124_chpotogoldgame(arg0, 3, 0x10);
}

/* extern */

void func_8080117C_chpotogoldgame(s32 arg0) {
    s32 _gccubesearch_entrypoint_1(s32, s32);
    s32 _gspropctrl_entrypoint_11(s32, s32 *);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    s32 func_80802124_chpotogoldgame(s32, s32, s32);
    s32 sp24[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x201, arg0 + 4), sp24);
    func_800D1000(0x17, 4, sp24, 1, 0);
    func_80802124_chpotogoldgame(arg0, 5, 0x10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_808011DC_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80801244_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_808013BC_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80801494_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80801558_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_808016E8_chpotogoldgame.s")

void func_80801870_chpotogoldgame(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_800BEA88(s32);
    extern s32 _chpotogoldgame_entrypoint_1;
    arg1 = ((arg3 & 1) << 4) | arg1;
    _glid_entrypoint_0(func_800BEA88(0), ((arg0 * 5) - arg2) + 5, &_chpotogoldgame_entrypoint_1, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/chpotogoldgame_entrypoint_1.s")

s32 func_80801998_chpotogoldgame(s16 *arg0) {
    void func_800EE88C(f32 dst[3], s16 src[3]);
    s32 func_800F1EA4(f32[3], f32 *);
    f32 sp24;
    f32 sp18[3];

    func_800EE88C(sp18, arg0);
    func_800F1EA4(sp18, &sp24);
    return (s32) (sp24 / 72.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/chpotogoldgame_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80801A7C_chpotogoldgame.s")

void chpotogoldgame_entrypoint_3(s32 arg0, s32 arg1, Vtx *arg2, s32 arg3, s32 arg4) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_80106790(s32);
    s32 pad;
    u8 *actor;
    u8 color;
    Vtx *end;

    actor = (u8 *)func_80106790(arg4);
    switch (arg0) {
    case 21:
        color = (u8)(u32)func_800F10B4(*(f32 *)(actor + 0x2C), 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 22:
        color = (u8)(u32)func_800F10B4(*(f32 *)(actor + 0x30), 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 23:
        color = (u8)(u32)func_800F10B4(*(f32 *)(actor + 0x28), 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 24:
        color = (u8)(u32)func_800F10B4(*(f32 *)(actor + 0x18), 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    case 25:
        color = (u8)(u32)func_800F10B4(*(f32 *)(actor + 0x1C), 0.0f, 2.0f, 100.0f, 255.0f);
        break;
    }
    for (end = arg2 + arg3; arg2 < end; arg2++) {
        arg2->v.cn[0] = color;
        arg2->v.cn[1] = color;
        arg2->v.cn[2] = color;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_8080206C_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80802124_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_8080219C_chpotogoldgame.s")

/* extern */

void func_8080227C_chpotogoldgame(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x34))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x34))) = 0;
    }
}

OSThread *chpotogoldgame_entrypoint_4(void)
{
    extern u8 D_80802578_chpotogoldgame[];

    return (OSThread *) D_80802578_chpotogoldgame;
}

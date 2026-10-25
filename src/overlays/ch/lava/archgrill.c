#include "common.h"

/* extern */

void func_80800000_chlavaarchgrill(void *arg0) {
    s32 func_800DA7A8(s32, s32, s32, void *);
    s32 func_8010A800(void *, s32);
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
    func_800DA7A8(0xA1A, 0, 3, arg0);
    func_8010A800(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/archgrill/func_80800044_chlavaarchgrill.s")

/* extern */

void func_80800288_chlavaarchgrill(u8 *arg0, s32 arg1) {
    s32 func_800D9078(s32);
    s32 func_80101FDC(u8 *, s32);
    if (func_800D9078(arg0 + 0x18) != 0) {
        func_80101FDC(arg0, arg1);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = 2.0f;
    }
}

void func_808002D0_chlavaarchgrill(Actor *arg0) {
    s32 func_800D9078();
    s32 func_80101FDC();
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    extern u32 D_80800688_chlavaarchgrill[];
    extern u32 D_80800698_chlavaarchgrill[];
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;

    switch (arg0->unk70_10) {
    case 2:
        func_80800288_chlavaarchgrill((u8 *)arg0, 3);
        break;
    case 3:
        sp3C = func_800D9078(&arg0->unk58);
        arg0->position[1] = func_800F12D4(arg0->unk58, 0.0f, 2.0f, ((f32 *)arg0->actorData)[5] + ((190.0f * arg0->scale) / 2), ((f32 *)arg0->actorData)[5]);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800688_chlavaarchgrill);
        if (sp3C) {
            func_80101FDC(arg0, 4);
        }
        break;
    case 5:
        func_80800288_chlavaarchgrill((u8 *)arg0, 6);
        break;
    case 6:
        sp38 = func_800D9078(&arg0->unk58);
        arg0->position[1] = func_800F12D4(arg0->unk58, 0.0f, 2.0f, ((f32 *)arg0->actorData)[5] + (190.0f * arg0->scale), ((f32 *)arg0->actorData)[5] + ((190.0f * arg0->scale) / 2));
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800688_chlavaarchgrill);
        if (sp38) {
            func_80101FDC(arg0, 7);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800698_chlavaarchgrill);
        }
        break;
    case 8:
        func_80800288_chlavaarchgrill((u8 *)arg0, 9);
        break;
    case 9:
        sp34 = func_800D9078(&arg0->unk58);
        arg0->position[1] = func_800F12D4(arg0->unk58, 2.0f, 0.0f, ((f32 *)arg0->actorData)[5] + ((190.0f * arg0->scale) / 2), ((f32 *)arg0->actorData)[5]);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800688_chlavaarchgrill);
        if (sp34) {
            func_80101FDC(arg0, 1);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800698_chlavaarchgrill);
        }
        break;
    case 10:
        if (func_800D9078((f32 *)arg0->actorData)) {
            func_80101FDC(arg0, 11);
            arg0->unk58 = 4.0f;
        }
        break;
    case 11:
        sp30 = func_800D9078(&arg0->unk58);
        arg0->position[1] = func_800F12D4(arg0->unk58, 0.0f, 4.0f, ((f32 *)arg0->actorData)[5] + (190.0f * arg0->scale), ((f32 *)arg0->actorData)[5]);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800688_chlavaarchgrill);
        if (sp30) {
            func_80101FDC(arg0, 12);
        }
        break;
    }
}

OSThread *chlavaarchgrill_entrypoint_0(void)
{
    extern u8 D_808006A4_chlavaarchgrill[];

    return (OSThread *) D_808006A4_chlavaarchgrill;
}

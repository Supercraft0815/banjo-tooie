#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroomprops/func_80800000_chtoxicroomprops.s")

s32 func_8080030C_chtoxicroomprops(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800DA524(s32);
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    void _glcutDll_entrypoint_17(void);
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
        case 0xB:
            func_800DA524(0xA04);
            func_800DA524(0x1BD);
            _subaddieaudioloop_entrypoint_2((u8 *)arg0);
            _glcutDll_entrypoint_17();
            return 3;
        case 0x49:
            if (arg2 == 0x41) {
                func_80101FDC(arg0, 2);
                return 1;
            }
            return 0;
        default:
            return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroomprops/func_80800390_chtoxicroomprops.s")

OSThread *chtoxicroomprops_entrypoint_0(void)
{
    extern u8 D_808009E8_chtoxicroomprops[];

    return (OSThread *) D_808009E8_chtoxicroomprops;
}

void func_80800650_chtoxicroomprops(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x4C))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x54))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 10.0f;
}

/* extern */

void func_80800670_chtoxicroomprops(u8 *arg0) {
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    s32 func_800D90A4(s32);
    s32 func_800FFA88(s32);
    s32 func_80800390_chtoxicroomprops(u8 *, s32);
    if (func_800D90A4(arg0 + 0x58) != 0) {
        func_80800390_chtoxicroomprops(arg0, 0xC0000000);
        if ((*(f32 *)((s8 *)(arg0) + (0x24))) < 45.0f) {
            _subaddieaudioloop_entrypoint_2(arg0);
            (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
            func_800FFA88((*(s32 *)((s8 *)(arg0) + (0))));
        }
    } else {
        func_80800390_chtoxicroomprops(arg0, 0x40800000);
    }
}

OSThread *chtoxicroomprops_entrypoint_1(void)
{
    extern u8 D_80800A30_chtoxicroomprops[];

    return (OSThread *) D_80800A30_chtoxicroomprops;
}

/* extern */

void func_80800700_chtoxicroomprops(void *arg0) {
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    (*(f32 *)((s8 *)(arg0) + (0x30))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
    if (func_800DA298(0x1BD) == 0) {
        func_80101FDC(arg0, 3);
        return;
    }
    func_80101FDC(arg0, 1);
}

void func_80800758_chtoxicroomprops(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800D90A4();
    s32 func_800DA298(s32);
    void func_800E148C(s32, f32, f32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    f32 func_80103EF4(Actor *);
    extern u8 D_80800A78_chtoxicroomprops[];
    f32 *position;

    switch (arg0->unk70_10) {
        case 1:
            if (func_800DA298(0xA04) || !func_800DA298(0x1BD)) {
                func_80101FDC(arg0, 2);
                ((f32 *)arg0->actorData)[4] = 8.0f;
            }
            arg0->position[1] = ((f32 *)arg0->actorData)[6];
            break;
        case 2:
            if (func_800D90A4(&((f32 *)arg0->actorData)[4])) {
                func_80101FDC(arg0, 3);
            }
            arg0->position[1] = ((f32 *)arg0->actorData)[6] + func_800F10B4(((f32 *)arg0->actorData)[4], 8.0f, 0.0f, 0.0f, func_80103EF4(arg0) * 0.9f);
            break;
        case 3:
            if (func_800DA298(0x1BD) && !func_800DA298(0xA04)) {
                func_80101FDC(arg0, 4);
                ((f32 *)arg0->actorData)[4] = 0.5f;
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800A78_chtoxicroomprops);
            }
            arg0->position[1] = ((f32 *)arg0->actorData)[6] + func_80103EF4(arg0) * 0.9f;
            break;
        case 4:
            if (func_800D90A4(&((f32 *)arg0->actorData)[4])) {
                position = arg0->position;
                func_800E148C(func_800E1610(2, 200.0f, 0.85f, position), 1000.0f, 4000.0f);
                func_80101FDC(arg0, 1);
                _subaddieaudioquick_entrypoint_2(arg0, position, D_80800A78_chtoxicroomprops);
            }
            arg0->position[1] = ((f32 *)arg0->actorData)[6] + func_800F10B4(((f32 *)arg0->actorData)[4], 0.5f, 0.0f, func_80103EF4(arg0) * 0.9f, 0.0f);
            break;
    }
}

OSThread *chtoxicroomprops_entrypoint_2(void)
{
    extern u8 D_80800A84_chtoxicroomprops[];

    return (OSThread *) D_80800A84_chtoxicroomprops;
}

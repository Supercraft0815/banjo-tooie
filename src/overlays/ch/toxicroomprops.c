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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toxicroomprops/func_80800758_chtoxicroomprops.s")

OSThread *chtoxicroomprops_entrypoint_2(void)
{
    extern u8 D_80800A84_chtoxicroomprops[];

    return (OSThread *) D_80800A84_chtoxicroomprops;
}

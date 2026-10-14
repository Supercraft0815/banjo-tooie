#include "common.h"

OSThread *chmadamegrunty_entrypoint_0(void)
{
    extern u8 D_80800B50_chmadamegrunty[];

    return (OSThread *) D_80800B50_chmadamegrunty;
}

OSThread *chmadamegrunty_entrypoint_1(void)
{
    extern u8 D_80800B98_chmadamegrunty[];

    return (OSThread *) D_80800B98_chmadamegrunty;
}

/* extern */

void func_80800018_chmadamegrunty(void *arg0) {
    s32 func_800DA298(s32);
    s32 func_80101FDC(void *, s32);
    if (func_800DA298(0xA02) != 0) {
        func_80101FDC(arg0, 7);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = 20.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_8080005C_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800198_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800200_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_808002BC_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_808003B0_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800460_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800564_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800670_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_80800784_chmadamegrunty.s")

/* extern */

void func_8080082C_chmadamegrunty(void *arg0, s32 arg1) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_11(s32, s32, s32, s32, s32);
    s32 func_80101FDC();
    func_80101FDC();
    if (arg1 == 7) {
        _subaddieDll_entrypoint_4(arg0, 1);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = 60.0f;
        _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(arg0) + (0))), 0x10CA, 4, 0, 0x43);
    }
}

s32 func_80800898_chmadamegrunty(f32 arg0, f32 arg1, f32 arg2) {
    if ((arg0 <= arg2) && (arg2 < arg1)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_808008D4_chmadamegrunty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/madamegrunty/func_808009AC_chmadamegrunty.s")

/* extern */

void func_80800A30_chmadamegrunty(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    s32 _chdoormake_entrypoint_7(void *, f32);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, arg0->scale * 200.0f, 0x2812, 0xA02) != 0) {
        _chdoormake_entrypoint_5(arg0, 1.0f);
        _chdoormake_entrypoint_7(arg0, 1.0f);
    }
}

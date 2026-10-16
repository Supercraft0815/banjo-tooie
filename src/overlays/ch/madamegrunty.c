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

void func_80800200_chmadamegrunty(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void func_800F497C(s32);
    void func_800F49D4(s32, void *, s32);
    void func_800F4AC0(s32, s32, f32);
    u32 func_800F54E4(void);
    s32 func_800F6438(u32);
    s32 func_800F6478(s32);
    s32 func_800F64A4(s32, s32);
    s32 func_8010C500(void *);
    void func_8080082C_chmadamegrunty(void *, s32);
    extern s32 func_8010D5DC;
    u32 temp_v0;

    temp_v0 = func_800F54E4();
    if (func_800F6438(temp_v0) && func_800F6478(temp_v0) &&
        func_8010C500(arg0) && !func_800F64A4(temp_v0, 0x10000)) {
        func_800F497C(temp_v0);
        func_800F49D4(temp_v0, &func_8010D5DC, arg0->unk0);
        func_800F4AC0(temp_v0, arg0->position, 170.0f);
        func_8080082C_chmadamegrunty(arg0, 2);
        _capod_entrypoint_13(arg0->unk0, NULL, 0xAE, 0x20);
    }
}

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

void func_808009AC_chmadamegrunty(Actor *arg0, s32 arg1, f32 arg2) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C301C(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    f32 func_800DC178(f32, f32);
    extern s32 D_80800C4C_chmadamegrunty;
    u8 sp27;

    sp27 = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
    func_800C4350(sp27 & 0xFF, arg0->position, &D_80800C4C_chmadamegrunty);
    func_800C301C(sp27, arg1);
    func_800C31DC(sp27, func_800DC178(-0.05f, 0.05f) + arg2);
    func_800C3BDC(sp27);
}

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

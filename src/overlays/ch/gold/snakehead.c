#include "common.h"

OSThread *chgoldsnakehead_entrypoint_0(void)
{
    extern u8 D_80800508_chgoldsnakehead[];

    return (OSThread *) D_80800508_chgoldsnakehead;
}

OSThread *chgoldsnakehead_entrypoint_1(void)
{
    extern u8 D_80800550_chgoldsnakehead[];

    return (OSThread *) D_80800550_chgoldsnakehead;
}

OSThread *chgoldsnakehead_entrypoint_2(void)
{
    extern u8 D_80800598_chgoldsnakehead[];

    return (OSThread *) D_80800598_chgoldsnakehead;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/snakehead/func_80800024_chgoldsnakehead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/snakehead/func_8080015C_chgoldsnakehead.s")

void func_808002B4_chgoldsnakehead(Actor *arg0, u8 *arg1) { void func_800DF744(s32, s32); void func_80101870(Actor*, void*); func_800DF744(1, ((u32) (arg0->unk0->unk28 << 0x12) >> 0x1F) ? 0 : 1); func_800DF744(2, (s32) ((u32) (arg0->unk0->unk28 << 0x12) >> 0x1F)); func_80101870(arg0, arg1); }

/* extern */

void func_80800324_chgoldsnakehead(s32 arg0, s32 arg1) {
    s32 func_800DA564(s32, s32);
    s32 func_800DA7A8(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    s32 func_80101FDC(s32, s32);
    s32 func_80102FE8(s32, s32);
    s32 func_80103110(s32, s32);
    s32 func_8010A570();
    s32 sp1C;
    s32 temp_a1;

    func_8010A570();
    func_80101FDC(arg0, 2);
    func_80102FE8(arg0, 0);
    func_80103110(arg0, 1);
    temp_a1 = func_800DA564(6, 3) + 1;
    sp1C = temp_a1;
    func_800DA7A8(6, temp_a1, 3);
    if (sp1C == 6) {
        func_80101180(0x10E, 7, 0);
    }
}

s32 func_808003A8_chgoldsnakehead(s32 arg0, s32 arg1, volatile s32 arg2) {
    if (arg1 == 0x40) {
        func_80800324_chgoldsnakehead(arg0, *(s32 *)&arg2);
        return 1;
    }
    return 0;
}

/* extern */

void func_808003E0_chgoldsnakehead(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor*, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_8(void*, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 200.0f, 0x41, 0x18B) != 0) {
        _chdoormake_entrypoint_8(arg0, 5U);
        _chdoormake_entrypoint_9(arg0, 0, 6, 0x10);
    }
}

void func_80800440_chgoldsnakehead(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_12(Actor *, s32, s32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);

    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 200.0f, 0x60, 0x59C) != 0) {
        _chdoormake_entrypoint_6(arg0, 0x40400000);
        _chdoormake_entrypoint_8(arg0, 5U);
        _chdoormake_entrypoint_12(arg0, 0, 0xD);
        _chdoormake_entrypoint_9(arg0, 0, 0x2B, 0x2900);
    }
    if ((func_800DA298(0x59C) != 0) && (_glcutDll_entrypoint_19(0xD) == 0)) {
        func_800FFAB0(arg0);
    }
}

#include "common.h"

/* extern */

void func_80800000_chwaspstatue(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_80800134_chwaspstatue(s32, s32);

    func_80800134_chwaspstatue(arg0, func_800DA298(0x35A) ? 0x6 : 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspstatue/func_8080003C_chwaspstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspstatue/func_80800134_chwaspstatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspstatue/func_80800350_chwaspstatue.s")

/* extern */

void chwaspstatue_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_80106790(s32);
    s32 func_80800134_chwaspstatue(s32, s32);
    func_80800134_chwaspstatue(func_80106790(arg1), 4);
}

OSThread *chwaspstatue_entrypoint_1(void)
{
    extern u8 D_80800740_chwaspstatue[];

    return (OSThread *) D_80800740_chwaspstatue;
}

/* extern */

void func_80800544_chwaspstatue(Actor *arg0) {
    s32 _chdoormake_entrypoint_10(void *, s32, s32);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(s32, s32);
    s32 var_a1;

    var_a1 = func_800F64A4(func_800F54E4(), 0x20) != 0;
    if (var_a1 != 0) {
        var_a1 = func_800DA298(0x35A) != 0;
    }
    func_800DA3B8(0x9FD, var_a1);
    _chdoormake_entrypoint_3(arg0, arg0->rotation[1], arg0->rotation[0] + 90.0f, arg0->scale * 346.0f, 0x83, 0x9FD);
    _chdoormake_entrypoint_5(arg0, 2.0f);
    _chdoormake_entrypoint_6(arg0, 0x3F000000);
    _chdoormake_entrypoint_8(arg0, 5);
    _chdoormake_entrypoint_9(arg0, 0, 0x1D, 0x810);
    _chdoormake_entrypoint_10(arg0, 0, 0x3DF);
}

OSThread *chwaspstatue_entrypoint_2(void)
{
    extern u8 D_80800788_chwaspstatue[];

    return (OSThread *) D_80800788_chwaspstatue;
}

#include "common.h"

OSThread *chjiggytemple_entrypoint_0(void)
{
    extern u8 D_808008C8_chjiggytemple[];

    return (OSThread *) D_808008C8_chjiggytemple;
}

void func_8080000C_chjiggytemple(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    extern s32 D_80800910_chjiggytemple;
    _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80800910_chjiggytemple);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/temple/func_80800034_chjiggytemple.s")

void func_808000A8_chjiggytemple(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/temple/func_808000B0_chjiggytemple.s")

OSThread *chjiggytemple_entrypoint_1(void)
{
    extern u8 D_8080092C_chjiggytemple[];

    return (OSThread *) D_8080092C_chjiggytemple;
}

/* extern */

void func_80800320_chjiggytemple(s32 arg0) {
    s32 _chdoormake_entrypoint_3(s32, f32, f32, f32, s32, s32);
    s32 _chdoormake_entrypoint_5(s32, f32);
    s32 _chdoormake_entrypoint_6(s32, f32);
    s32 _chdoormake_entrypoint_7(s32, f32);
    s32 _chdoormake_entrypoint_8(s32, s32);
    s32 _chdoormake_entrypoint_9(s32, s32, s32, s32);
    s32 _glcutDll_entrypoint_18();
    s32 _sujiggy_entrypoint_17();
    s32 func_800DA298(s32);
    s32 func_800EA090();
    s32 func_8010108C(s32, s32, s32);
    s32 func_80101FDC(s32, s32);
    f32 func_80103EF4(s32);
    s32 sp2C;
    s32 sp28;

    sp2C = func_800EA090();
    if ((func_800DA298(0x532) != 0) && ((sp2C == 1) || (_sujiggy_entrypoint_17() != 0))) {
        func_80101FDC(arg0, 4);
    }
    _chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, func_80103EF4(arg0), 2, -1);
    _chdoormake_entrypoint_5(arg0, 1.0f);
    _chdoormake_entrypoint_6(arg0, 0.5f);
    _chdoormake_entrypoint_7(arg0, 0.5f);
    _chdoormake_entrypoint_8(arg0, 5);
    _chdoormake_entrypoint_9(arg0, 1, 0x12, 0x10);
    if (func_800DA298(0x532) != 0) {
        sp28 = _glcutDll_entrypoint_18();
        if ((_sujiggy_entrypoint_17() == 0) && (sp28 != 0x67) && (sp28 != 0x7A)) {
            func_8010108C(arg0, 8, 0);
        }
    }
}

void func_80800438_chjiggytemple(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    if (arg1 == 7) {
        _chdoor_entrypoint_1(arg0, arg1, arg2);
        return;
    }
    _chdoor_entrypoint_1(arg0, arg1, arg2);
}

OSThread *chjiggytemple_entrypoint_2(void)
{
    extern u8 D_80800974_chjiggytemple[];

    return (OSThread *) D_80800974_chjiggytemple;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/temple/func_8080047C_chjiggytemple.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/temple/func_808004D8_chjiggytemple.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/temple/func_80800688_chjiggytemple.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/temple/func_80800784_chjiggytemple.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jiggy/temple/func_808007F4_chjiggytemple.s")

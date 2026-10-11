#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80800000_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80800630_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80800A08_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80800C7C_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801038_chfactoryempspell.s")

/* extern */

void chfactoryempspell_entrypoint_0(s32 arg0, s32 arg1) {
    s32 _chmrtannoy_entrypoint_0();
    s32 func_800C0534(s32, s32, s32, s32, s32, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800EA05C();
    if (func_800DA298(0x329) == 0) {
        _chmrtannoy_entrypoint_0();
        func_800C0534(0x133A, 4, 0, 0, 0, 0, 0, 0xA3);
    }
    if (func_800EA05C() != 0x10B) {
        func_800DA524(0x9DE);
    }
    func_800DA524(0xA05);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801130_chfactoryempspell.s")

void func_808012C0_chfactoryempspell(f32 arg0, f32 arg1) {
    void func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800DC0C0(void);
    void func_800E3980(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern s32 D_80802240_chfactoryempspell;
    extern s32 D_8080227C_chfactoryempspell;
    extern f32 D_808022C8_chfactoryempspell[][3];
    extern f32 D_808022E0_chfactoryempspell[][3];
    extern f32 D_808022F8_chfactoryempspell[][3];
    extern f32 D_80802310_chfactoryempspell[][3];
    f32 position[3];
    f32 random;
    s32 side;

    func_800E3980(position);
    if (position[0] < 0.0f) {
        side = 0;
    } else {
        side = 1;
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(D_808022C8_chfactoryempspell[side], NULL, 1.0f, 1, &D_80802240_chfactoryempspell);
    }
    if (random < arg1) {
        func_800EFA4C(position, D_808022C8_chfactoryempspell[side][0] + 100.0f, D_808022C8_chfactoryempspell[side][1] - 30.0f, D_808022C8_chfactoryempspell[side][2] - 50.0f);
        func_800BBCB8(D_808022C8_chfactoryempspell[side], position, 1.0f, 2, &D_8080227C_chfactoryempspell);
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(D_808022E0_chfactoryempspell[side], NULL, 1.0f, 1, &D_80802240_chfactoryempspell);
    }
    if (random < arg1) {
        func_800EFA4C(position, D_808022E0_chfactoryempspell[side][0] + 100.0f, D_808022E0_chfactoryempspell[side][1] - 30.0f, D_808022E0_chfactoryempspell[side][2] - 50.0f);
        func_800BBCB8(D_808022E0_chfactoryempspell[side], position, 1.0f, 2, &D_8080227C_chfactoryempspell);
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(D_808022F8_chfactoryempspell[side], NULL, 1.0f, 1, &D_80802240_chfactoryempspell);
    }
    if (random < arg1) {
        func_800EFA4C(position, D_808022F8_chfactoryempspell[side][0] + 100.0f, D_808022F8_chfactoryempspell[side][1] - 30.0f, D_808022F8_chfactoryempspell[side][2] + 50.0f);
        func_800BBCB8(D_808022F8_chfactoryempspell[side], position, 1.0f, 2, &D_8080227C_chfactoryempspell);
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(D_80802310_chfactoryempspell[side], NULL, 1.0f, 1, &D_80802240_chfactoryempspell);
    }
    if (random < arg1) {
        func_800EFA4C(position, D_80802310_chfactoryempspell[side][0] + 100.0f, D_80802310_chfactoryempspell[side][1] - 30.0f, D_80802310_chfactoryempspell[side][2] + 50.0f);
        func_800BBCB8(D_80802310_chfactoryempspell[side], position, 1.0f, 2, &D_8080227C_chfactoryempspell);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_808016AC_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801844_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801AB4_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801B2C_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801C00_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801E48_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801E9C_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801F30_chfactoryempspell.s")

/* extern */

void func_80801FE0_chfactoryempspell(void *arg0) {
    s32 _subaddieaudioloop_entrypoint_2();
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    s32 func_80801AB4_chfactoryempspell(void *);
    _subaddieaudioloop_entrypoint_2();
    (*(u8 *)((s8 *)(arg0) + (0x28))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x28))));
    func_80801AB4_chfactoryempspell(arg0);
    if ((*(s16 *)((s8 *)(arg0) + (0x82))) != 0) {
        _sumumbofx_entrypoint_1(arg0, 0);
    }
}

OSThread *chfactoryempspell_entrypoint_1(void)
{
    extern u8 D_80802414_chfactoryempspell[];

    return (OSThread *) D_80802414_chfactoryempspell;
}

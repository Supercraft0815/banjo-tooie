#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quicksandbaddy/func_80800000_chquicksandbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quicksandbaddy/func_80800140_chquicksandbaddy.s")

/* extern */

f32 func_80800CC0_chquicksandbaddy(u8 *arg0) {
    f32 func_800C6920(s32, f32, f32, s32);
    f32 result;

    result = func_800C6920((s32) (arg0 + 4), 500.0f, -500.0f, 0);
    result += *(f32 *) (arg0 + 0x54);
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quicksandbaddy/func_80800CFC_chquicksandbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quicksandbaddy/func_80800DBC_chquicksandbaddy.s")

void chquicksandbaddy_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_8001210C(s32);
    s32 func_800B53A4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BAB80(s32, s32 *);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    f32 func_800DC0C0();
    s32 func_808010A0_chquicksandbaddy(s32 *);
    extern s32 D_80801370_chquicksandbaddy;
    extern s32 D_80801390_chquicksandbaddy;
    s32 sp24;
    s32 temp_v0;

    if ((func_800DC0C0() < 0.75f) && (func_808010A0_chquicksandbaddy(&D_80801390_chquicksandbaddy) != 0) && (func_8001210C(3) != 0)) {
        temp_v0 = func_800B53A4(1);
        sp24 = temp_v0;
        func_800BABB8(temp_v0, arg1, 0, 0x40000000, &D_80801370_chquicksandbaddy);
        func_800BAB80(sp24, &D_80801390_chquicksandbaddy);
        func_800BA22C(sp24, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quicksandbaddy/func_80800FC8_chquicksandbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quicksandbaddy/func_808010A0_chquicksandbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quicksandbaddy/func_80801154_chquicksandbaddy.s")

OSThread *chquicksandbaddy_entrypoint_1(void)
{
    extern u8 D_808013D8_chquicksandbaddy[];

    return (OSThread *) D_808013D8_chquicksandbaddy;
}

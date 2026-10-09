#include "common.h"

OSThread *chbanjoctrl_entrypoint_0(void)
{
    extern u8 D_80801270_chbanjoctrl[];

    return (OSThread *) D_80801270_chbanjoctrl;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_8080000C_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800098_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_8080012C_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800160_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_8080025C_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_808002A4_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800360_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_808003F8_chbanjoctrl.s")

/* extern */

s32 chbanjoctrl_entrypoint_1(s32 arg0) {
    s32 _chhotwaterpoolbits_entrypoint_5(s32, s32);
    s32 func_800F54E4();
    s32 func_800F7B9C(s32, s32);
    if (func_800F7B9C(func_800F54E4(), 0x51) == 2) {
        _chhotwaterpoolbits_entrypoint_5(arg0, 0x3F800000);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800544_chbanjoctrl.s")

/* extern */

s32 chbanjoctrl_entrypoint_2(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F798C(s32, s32, s32);
    s32 func_80800544_chbanjoctrl(s32);
    if (func_800F798C(func_800F54E4(), 0xD, 3) != 0) {
        func_80800544_chbanjoctrl(arg0);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800638_chbanjoctrl.s")

void func_80800684_chbanjoctrl(void *arg0, f32 arg1, s32 arg2, s32 arg3) {
    (*(s32 *)((s8 *)(arg0) + (0x24))) = arg3;
    (*(s32 *)((s8 *)(arg0) + (0x50))) = arg2;
    (*(s8 *)((s8 *)(arg0) + (0x30))) = 1;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_808006A8_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800728_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_808007D8_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800824_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_808008D8_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_8080091C_chbanjoctrl.s")

/* extern */

void func_80800ADC_chbanjoctrl(s32 arg0) {
    s32 func_800F54E4();
    s32 func_80800824_chbanjoctrl(s32, s32);
    s32 func_8080091C_chbanjoctrl(s32, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    func_80800824_chbanjoctrl(arg0, temp_v0);
    func_8080091C_chbanjoctrl(arg0, sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800B18_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800D04_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800D50_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80800DF8_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_8080102C_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_80801088_chbanjoctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/banjoctrl/func_808010FC_chbanjoctrl.s")

/* extern */

void func_808011F4_chbanjoctrl(void) {
    s32 func_8080102C_chbanjoctrl();
    func_8080102C_chbanjoctrl();
}

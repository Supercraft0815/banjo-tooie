#include "common.h"

/* extern */

void func_80800000_chrainbow(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_80800270_chrainbow(s32, s32);

    func_80800270_chrainbow(arg0, func_800DA298(0x1E1) ? 0xD : 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_8080003C_chrainbow.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_80800270_chrainbow.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_80800440_chrainbow.s")

void func_808005E0_chrainbow(s32 arg0, s32 arg1) {
    s32 func_800B53A4(s32);
    s32 func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80800FD0_chrainbow;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(1);
    sp24 = temp_v0;
    func_800BA3FC(temp_v0, arg1 + 0x9DF);
    func_800BABB8(sp24, arg0, 0, 0x3F800000, &D_80800FD0_chrainbow);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_8080063C_chrainbow.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_80800838_chrainbow.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/chrainbow_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_80800CD4_chrainbow.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_80800D88_chrainbow.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainbow/func_80800EB4_chrainbow.s")

OSThread *chrainbow_entrypoint_1(void)
{
    extern u8 D_80801010_chrainbow[];

    return (OSThread *) D_80801010_chrainbow;
}

#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wandglow/func_80800000_chwandglow.s")

void func_808000E8_chwandglow(void *arg0) {
    (*(s32 (**)(s32, s32, void *))((s8 *)(arg0) + (0x30)))((*(s32 *)((s8 *)(arg0) + (0))), (*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wandglow/func_8080011C_chwandglow.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wandglow/func_80800218_chwandglow.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wandglow/chwandglow_entrypoint_0.s")

void chwandglow_entrypoint_1()
{
    func_800FFA88();
}

/* extern */

void chwandglow_entrypoint_2(void) {
    s32 func_8080011C_chwandglow(s32, s32);
    s32 func_80106790();
    func_8080011C_chwandglow(func_80106790(), 4);
}

OSThread *chwandglow_entrypoint_3(void)
{
    extern u8 D_80800410_chwandglow[];

    return (OSThread *) D_80800410_chwandglow;
}

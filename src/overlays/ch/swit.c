#include "common.h"

OSThread *chswitch_entrypoint_0(void)
{
    extern u8 D_80800DB0_chswitch[];

    return (OSThread *) D_80800DB0_chswitch;
}

OSThread *chswitch_entrypoint_1(void)
{
    extern u8 D_80800DC4_chswitch[];

    return (OSThread *) D_80800DC4_chswitch;
}

OSThread *chswitch_entrypoint_2(void)
{
    extern u8 D_80800DD8_chswitch[];

    return (OSThread *) D_80800DD8_chswitch;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_80800024_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_808000B8_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_8080012C_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_808002B4_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_7.s")

void chswitch_entrypoint_8(s32 *arg0, s32 arg1) {
    arg0[11] = arg1;
}

void chswitch_entrypoint_9(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0x30))) = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_80800694_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/func_8080093C_chswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swit/chswitch_entrypoint_14.s")

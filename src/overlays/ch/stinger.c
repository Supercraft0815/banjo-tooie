#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_80800000_chstinger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_8080015C_chstinger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_80800218_chstinger.s")

void func_8080025C_chstinger(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_80800264_chstinger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_808003B0_chstinger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_80800420_chstinger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/chstinger_entrypoint_0.s")

s32 func_80800774_chstinger(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80109EEC(s16*, s32);
    switch (arg1) {
        case 0x95:
            func_80109EEC((s16 *) arg0, 0x10);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chstinger_entrypoint_1(void)
{
    extern u8 D_80800870_chstinger[];

    return (OSThread *) D_80800870_chstinger;
}

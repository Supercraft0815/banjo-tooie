#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_80800000_chfaircoinbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_8080001C_chfaircoinbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_80800050_chfaircoinbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_808000A4_chfaircoinbox.s")

void func_8080016C_chfaircoinbox(s32 arg0) 
{
}
/* extern */

void func_80800174_chfaircoinbox(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_8010A63C();
    s32 func_80800050_chfaircoinbox(s32);
    s32 func_808000A4_chfaircoinbox(s32, s32);
    func_8010A63C();
    if (func_800DA298(func_80800050_chfaircoinbox(arg0)) != 0) {
        func_808000A4_chfaircoinbox(arg0, 4);
        return;
    }
    func_808000A4_chfaircoinbox(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_808001C8_chfaircoinbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_80800264_chfaircoinbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_808002CC_chfaircoinbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/chfaircoinbox_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/chfaircoinbox_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_808003C4_chfaircoinbox.s")

OSThread *chfaircoinbox_entrypoint_2(void)
{
    extern u8 D_808004C8_chfaircoinbox[];

    return (OSThread *) D_808004C8_chfaircoinbox;
}

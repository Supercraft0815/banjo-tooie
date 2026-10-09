#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_80800000_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_80800130_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_808002B8_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_808003A8_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_808003DC_chfactorydrums.s")

void chfactorydrums_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808011CC_chfactorydrums;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_808011CC_chfactorydrums);
}

void chfactorydrums_entrypoint_1(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80801208_chfactorydrums;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_80801208_chfactorydrums);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_80800CD0_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_80800D90_chfactorydrums.s")

OSThread *chfactorydrums_entrypoint_2(void)
{
    extern u8 D_8080125C_chfactorydrums[];

    return (OSThread *) D_8080125C_chfactorydrums;
}

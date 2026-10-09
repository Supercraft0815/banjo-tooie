#include "common.h"

OSThread *chjigsawcollect_entrypoint_0(void)
{
    extern u8 D_80800670_chjigsawcollect[];

    return (OSThread *) D_80800670_chjigsawcollect;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/collect/func_8080000C_chjigsawcollect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/collect/func_808000CC_chjigsawcollect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/collect/func_80800524_chjigsawcollect.s")

s32 func_808005A4_chjigsawcollect(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
void func_808005B8_chjigsawcollect(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808006D0_chjigsawcollect;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_808006D0_chjigsawcollect);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/collect/chjigsawcollect_entrypoint_1.s")

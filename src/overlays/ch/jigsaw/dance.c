#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/dance/func_80800000_chjigsawdance.s")

void func_808000AC_chjigsawdance(Actor *arg0) {
    void func_800C8B84(s32);
    if (arg0->unk6C_0 != 0) {
        func_800C8B84(arg0->unk6C_0);
        arg0->unk6C_0 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/dance/func_808000F0_chjigsawdance.s")

void chjigsawdance_entrypoint_0(void *arg0, s32 arg1) {
    (*(f32 *)((s8 *)(arg0) + (0x50))) = (f32) arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/dance/chjigsawdance_entrypoint_1.s")

OSThread *chjigsawdance_entrypoint_2(void)
{
    extern u8 D_80800488_chjigsawdance[];

    return (OSThread *) D_80800488_chjigsawdance;
}

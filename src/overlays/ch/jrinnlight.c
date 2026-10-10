#include "common.h"

void func_80800000_chjrinnlight(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x58)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (*(s32 *)((s8 *)(arg0) + (0x58))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jrinnlight/func_80800038_chjrinnlight.s")

OSThread *chjrinnlight_entrypoint_0(void)
{
    extern u8 D_808000F0_chjrinnlight[];

    return (OSThread *) D_808000F0_chjrinnlight;
}

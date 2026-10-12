#include "common.h"

s32 suchase_entrypoint_0(void) {
    s32 func_8001211C();
    void func_8010D254(s32 *);
    void func_808000A8_suchase(s32 *, s32 *);
    extern s32 D_808001D0_suchase[2];
    s32 temp_v0;
    s32 sp18[3];

    temp_v0 = func_8001211C();
    if (temp_v0 != D_808001D0_suchase[0]) {
        func_8010D254(sp18);
        D_808001D0_suchase[1] = 0;
        D_808001D0_suchase[0] = temp_v0;
        func_808000A8_suchase(D_808001D0_suchase, sp18);
    }
    return D_808001D0_suchase[1];
}

/* extern */

int suchase_entrypoint_1(s32 *arg0) {
    s32 suchase_entrypoint_0();
    s32 value;
    value = suchase_entrypoint_0();
    return value == 0 || value == *arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/chase/func_808000A8_suchase.s")

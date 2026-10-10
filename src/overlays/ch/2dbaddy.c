#include "common.h"

OSThread *ch2dbaddy_entrypoint_0(void)
{
    extern u8 D_80800A9C_ch2dbaddy[];

    return (OSThread *) D_80800A9C_ch2dbaddy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_8080000C_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808000A0_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808002A8_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808003C4_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_8080041C_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_80800468_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808004A8_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808004F4_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_80800564_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_80800700_ch2dbaddy.s")

void func_80800820_ch2dbaddy(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_80800AF4_ch2dbaddy;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800AF4_ch2dbaddy, 0.1f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_80800850_ch2dbaddy.s")

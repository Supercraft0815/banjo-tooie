#include "common.h"

void basudie_entrypoint_0()
{
    func_80091EF0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sudie/basudie_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sudie/basudie_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sudie/basudie_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sudie/basudie_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sudie/basudie_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sudie/basudie_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sudie/basudie_entrypoint_7.s")

/* extern */

void basudie_entrypoint_8(s32 arg0) {
    s32 func_80091E6C();
    s32 func_800A4C68(s32);
    s32 func_800A4E30(s32);
    s32 func_800C53EC(s32, s32);
    func_80091E6C();
    func_800A4E30(arg0);
    func_800C53EC(func_800A4C68(arg0), 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sudie/basudie_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sudie/basudie_entrypoint_10.s")

void basudie_entrypoint_11(s32 arg0)
{
    func_8009E6EC();
    func_80099AA8(arg0);
}
/* extern */

void basudie_entrypoint_12(s32 arg0) {
    s32 baphysics_reset_terminal_velocity(s32);
    s32 baphysics_set_terminal_velocity(s32, s32);
    s32 player_inWater();
    if (player_inWater() != 0) {
        baphysics_set_terminal_velocity(arg0, 0xC37A0000);
        return;
    }
    baphysics_reset_terminal_velocity(arg0);
}

#include "bs/blongleg.h"

s32 func_80800000_bsblongleg(PlayerState* arg0)
{
    return player_inWater(arg0);
}

void func_80800020_bsblongleg(PlayerState *arg0, s32 arg1) {
    void func_8009DE38(PlayerState *, s32, f32);
    if (arg1 != 0) {
        func_8009DE38(arg0, 0x4433, 0.88f);
        return;
    }
    func_8009DE38(arg0, 0x4433, 0.96f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800064_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_808000C8_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_8080013C_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800204_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_808002D8_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800378_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_2.s")

s32 bsblongleg_entrypoint_3(s32 arg0) {
    extern s32 D_80801470_bsblongleg[];
    return ((s32 *)&D_80801470_bsblongleg)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_5.s")

void bsblongleg_entrypoint_6()
{
    func_80800204_bsblongleg();
}

s32 bsblongleg_entrypoint_7(s32 arg0) {
    extern s32 D_80801480_bsblongleg[];
    return ((s32 *)&D_80801480_bsblongleg)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_9.s")

void bsblongleg_entrypoint_10()
{
    func_80800204_bsblongleg();
}

s32 bsblongleg_entrypoint_11(s32 arg0) {
    extern s32 D_80801490_bsblongleg[];
    return ((s32 *)&D_80801490_bsblongleg)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800994_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/func_80800A18_bsblongleg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_14.s")

s32 bsblongleg_entrypoint_15(s32 arg0) {
    extern s32 D_808014A0_bsblongleg[];
    return ((s32 *)&D_808014A0_bsblongleg)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_17.s")

void bsblongleg_entrypoint_18(s32 arg0)
{
    baphysics_reset_gravity();
    func_80800204_bsblongleg(arg0);
}
s32 bsblongleg_entrypoint_19(s32 arg0) {
    extern s32 D_808014B0_bsblongleg[];
    return ((s32 *)&D_808014B0_bsblongleg)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_21.s")

void bsblongleg_entrypoint_22()
{
    func_80800204_bsblongleg();
}

s32 bsblongleg_entrypoint_23(s32 arg0) {
    extern s32 D_808014C0_bsblongleg[];
    return ((s32 *)&D_808014C0_bsblongleg)[arg0];
}

void bsblongleg_entrypoint_24(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800204_bsblongleg(arg0);
}
void bsblongleg_entrypoint_25(s32 arg0)
{
    func_8080013C_bsblongleg();
    _bsrest_entrypoint_16(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/blongleg/bsblongleg_entrypoint_26.s")

s32 bsblongleg_entrypoint_27(s32 arg0) {
    extern s32 D_808014D0_bsblongleg[];
    return ((s32 *)&D_808014D0_bsblongleg)[arg0];
}

void bsblongleg_entrypoint_28(s32 arg0)
{
    func_8080013C_bsblongleg();
    _bsdrone_entrypoint_0(arg0);
}
/* extern */

void bsblongleg_entrypoint_29(s32 arg0) {
    s32 _bsdrone_entrypoint_1(s32);
    s32 bastatetimer_isDone(s32, s32);
    s32 bs_setState(s32, s32);
    s32 func_808000C8_bsblongleg();
    func_808000C8_bsblongleg();
    _bsdrone_entrypoint_1(arg0);
    if (bastatetimer_isDone(arg0, 2) != 0) {
        bs_setState(arg0, 0x29);
    }
}

void bsblongleg_entrypoint_30(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800204_bsblongleg(arg0);
}
s32 bsblongleg_entrypoint_31(s32 arg0) {
    extern s32 D_808014E0_bsblongleg[];
    return ((s32 *)&D_808014E0_bsblongleg)[arg0];
}

#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bitten/func_80800000_bsdronebitten.s")

void bsdronebitten_entrypoint_0(s32 arg0)
{
    func_8008E95C();
    bastick_popZone(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bitten/bsdronebitten_entrypoint_1.s")

void bsdronebitten_entrypoint_2()
{
    func_80099AA8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bitten/bsdronebitten_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bitten/bsdronebitten_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bitten/bsdronebitten_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bitten/bsdronebitten_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bitten/bsdronebitten_entrypoint_7.s")

void bsdronebitten_entrypoint_8()
{
    func_80099AA8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bitten/func_80800478_bsdronebitten.s")

/* extern */

void func_808004C4_bsdronebitten(void *arg0, s32 arg1, s32 arg2) {
    s32 anctrl_reset(s32);
    s32 anctrl_setDuration(s32, s32);
    s32 anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    s32 anctrl_setSmoothTransition(s32, s32);
    s32 anctrl_start(s32);
    s32 baanim_getAnimCtrlPtr();
    s32 temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr();
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, arg1);
    anctrl_setDuration(temp_v0, arg2);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_start(temp_v0);
    (*(s8 *)((s8 *)(arg0) + (0x190))) = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bitten/bsdronebitten_entrypoint_9.s")

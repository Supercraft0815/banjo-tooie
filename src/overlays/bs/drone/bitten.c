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

void bsdronebitten_entrypoint_5(void *arg0, void *arg1, f32 arg2)
{
  s32 pad[2];
  f32 _bamovegoto_entrypoint_3();
  f32 func_80013970(f32);
  f32 sp1C;
  float new_var;
  u8 temp_v0;
  temp_v0 = *((u8 *) (((s8 *) arg0) + 0x191));
  if ((temp_v0 != 1) && (temp_v0 == 2))
  {
    sp1C = _bamovegoto_entrypoint_3();
    new_var = (func_80013970(arg2 * 180.0f) * sp1C) * 0.5f;
    *((f32 *) (((s8 *) arg1) + 4)) = (f32) ((*((f32 *) (((s8 *) arg1) + 4))) + new_var);
  }
}

void bsdronebitten_entrypoint_6(s32 arg0)
{
    void _bafpctrl_entrypoint_19(s32);
    func_800961A0((s32 *)arg0, 0);
    func_8008E95C(arg0);
    _bafpctrl_entrypoint_19(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bitten/bsdronebitten_entrypoint_7.s")

void bsdronebitten_entrypoint_8()
{
    func_80099AA8();
}

/* extern */

struct player_state_s;
s32 func_80800478_bsdronebitten(struct player_state_s *arg0, s32 arg1) {
    s32 _badata_entrypoint_32(struct player_state_s *);
    s32 _badata_entrypoint_34(struct player_state_s *);
    s32 func_8008E124(struct player_state_s *);
    s32 var_v0;

    if (func_8008E124(arg0) != 0) {
        var_v0 = _badata_entrypoint_32(arg0);
    } else {
        var_v0 = _badata_entrypoint_34(arg0);
    }
    return var_v0;
}

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
